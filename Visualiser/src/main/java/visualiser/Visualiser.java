package visualiser;

import info.leadinglight.jdot.Edge;
import info.leadinglight.jdot.Graph;
import info.leadinglight.jdot.impl.Util;

import java.io.FileNotFoundException;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.HashMap;
import java.io.IOException;
import java.io.File;

import static java.lang.Math.round;

public class Visualiser {


	public static HashMap<String, HashMap<String, String>> hm;
	public static HashMap<String, String> states;

	public static String type = "pdf";
	public static String program = "/usr/bin/dot";

	private static void generateGraph() {
		Graph g = new Graph("klee");

		for (String from : hm.keySet()) {
			for (String to : hm.get(from).keySet()) {
			    g.addEdge(new Edge().setLabel(hm.get(from).get(to)).addNode(states.get(from)).addNode(states.get(to)));
			}
		}

		Util.sh(program+" -o "+"klee_graph."+type+" -T"+type, g.toDot());
	}


	private static void generateStates() {
		int s = 0;
		for (String from : hm.keySet()) {
			if(!states.containsKey(from)) {
				states.put(from, "s"+s);
				s++;
			}
			for (String to : hm.get(from).keySet()) {
				if(!states.containsKey(to)) {
					states.put(to, "s"+s);
					s++;
				}
			}
		}
	}


	public static void main(String[] args) throws FileNotFoundException, IOException  {
		if(args.length==0 || args[0]==null) {
			System.out.println("No statedump file provided!"); 
			return;
		}

		if(args.length>1)
			type=args[1];		
			
		if(args.length>2)
			program=args[2];

		String filename = args[0];
		String file;
		if(filename.charAt(0)=='/')
			file = filename;
		else
			file = System.getProperty("user.dir")+"/"+filename;

		File f = new File(file);
		if(!f.exists()) {
			System.out.println("File "+file+" not found");
			return;
		}

		System.out.println("Using file "+f.getCanonicalPath());
	
		hm = HashMapCreator.getMap(f.getCanonicalPath());
		System.out.println(hm);
		states = new HashMap<String, String>();

		System.out.println("Generating state names");
		generateStates();

		System.out.println("Generating graph in klee_graph."+type);
		generateGraph();
	}


}

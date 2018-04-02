package binarylearner;

import com.google.common.collect.ImmutableSet;
import de.learnlib.api.SUL;

import java.io.IOException;
import java.util.Collection;
import java.util.ArrayList;
import java.io.File;

import org.apache.commons.cli.DefaultParser;
import org.apache.commons.cli.CommandLine;
import org.apache.commons.cli.CommandLineParser;
import org.apache.commons.cli.HelpFormatter;
import org.apache.commons.cli.Options;
import org.apache.commons.cli.Option;
import org.apache.commons.cli.ParseException;

/**
 * Created by rick on 17/03/2017.
 */
public class BinaryLearner {

	private static Collection<String> inputAlphabet = null;
	private static String filename = null;
	private static BasicLearner.LearningMethod learningMethod = null;
	private static BasicLearner.TestingMethod testingMethod = null;

	private static void addOptions(Options options) {

		options.addOption("h", "help", false, "show this help");

		options.addOption("lm", true, "Set learning method [default=TTT]");
		options.addOption("tm", true, "Set testing method [default=RandomWalk]");

		options.addOption(Option.builder("a")
                      .desc("Input alphabet up to a [default=5]")
                      .type(Number.class)
                      .hasArg()
                      .argName("a")
                      .build());

		options.addOption("e", true, "Executable to learn");		
		
	}

	private static void parseCmd(Options options, CommandLine cmd) {
		if (cmd.hasOption("h"))
			help(options);
		if(cmd.hasOption("lm")) {
		    // set learning method
			switch(cmd.getOptionValue("lm")) {
				case "LStar": learningMethod = BasicLearner.LearningMethod.LStar; System.out.println("Learning with LStar"); break;
				case "RivestSchapire": learningMethod = BasicLearner.LearningMethod.RivestSchapire; System.out.println("Learning with RivestSchapire"); break;
				case "KearnsVazirani": learningMethod = BasicLearner.LearningMethod.KearnsVazirani; System.out.println("Learning with KearnsVazirani"); break;
				default     : learningMethod = BasicLearner.LearningMethod.TTT; System.out.println("Learning with TTT");
			}
		} else {
			learningMethod = BasicLearner.LearningMethod.TTT; System.out.println("Learning with TTT");
		}
		if(cmd.hasOption("tm")) {
			switch(cmd.getOptionValue("tm")) {
				case "WMethod": testingMethod = BasicLearner.TestingMethod.WMethod; System.out.println("Testing with WMethod"); break;
				case "WpMethod": testingMethod = BasicLearner.TestingMethod.WpMethod; System.out.println("Testing with WpMethod"); break;
				default     : testingMethod = BasicLearner.TestingMethod.RandomWalk; System.out.println("Testing with RandomWalk");
			}
		} else {
			testingMethod = BasicLearner.TestingMethod.RandomWalk;
		}
		if(cmd.hasOption("e")) {
		    filename = cmd.getOptionValue("e");
		}
		if(cmd.hasOption("a")) {
			int n = 5;
	
			try{System.out.println("a arg is "+cmd.getParsedOptionValue("a").toString()); n = ((Number)cmd.getParsedOptionValue("a")).intValue();} catch(Exception e) {System.out.println("Expected int as argument for -a"); n=5; e.printStackTrace();}
			System.out.println("Using alphabet size of "+n);
			ArrayList<String> arr = new ArrayList();
			for(int i = 1; i<=n; i++){ arr.add(String.valueOf(i)); }
			inputAlphabet = arr;
		} else {
		    inputAlphabet = ImmutableSet.of("1","2","3","4","5");
		}
	}


	private static void help(Options options) {
		HelpFormatter formater = new HelpFormatter();
		formater.printHelp("BinaryLearner", options);
		System.exit(0);
	 }

    /**
     * Example of how to learn a Mealy machine model from one of the compliled RERS programs.
     * @param args
     * @throws IOException
     */
    public static void main(String [] args) throws IOException {
        // Load the System Under Learning (SUL)

	// create Options object
	Options options = new Options();
	addOptions(options);
	CommandLineParser parser = new DefaultParser();
	CommandLine cmd = null;

	try { cmd = parser.parse( options, args); } catch(ParseException e){System.out.println("Error parsing arguments"); help(options);}
	parseCmd(options, cmd);
	if(filename==null) {System.out.println("No executable provided!"); help(options);}

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

        SUL<String,String> sul = new ProcessSUL(f.getCanonicalPath());


        // the input alphabet
        //Collection<String> inputAlphabet = ImmutableSet.of("1","2","3","4","5");

        try {
            // runControlledExperiment for detailed statistics, runSimpleExperiment for just the result
            //BasicLearner.runControlledExperiment(sul, BasicLearner.LearningMethod.TTT, BasicLearner.TestingMethod.RandomWalk, inputAlphabet);
            BasicLearner.runControlledExperiment(sul, learningMethod, testingMethod, inputAlphabet);
        } finally {
            if (sul instanceof AutoCloseable) {
                try {
                    ((AutoCloseable) sul).close();
                } catch (Exception exception) {
                    // should not happen
                }
            }
        }
    }
}

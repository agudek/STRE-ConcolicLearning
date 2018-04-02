package visualiser;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Scanner;
import java.util.ArrayList;

public class HashMapCreator {

    private static HashMap<String, HashMap<String, String>> map = new HashMap<>();
    private static HashMap<String, HashMap<String, ArrayList<String>>> sb = new HashMap<>();
    

    public static HashMap<String, HashMap<String, String>> getMap(String file) throws FileNotFoundException {
        Scanner sc = new Scanner(new File(file));
        while (sc.hasNextLine()) {
            String line = sc.nextLine();
            String[] split = line.split(" ");
            if (!map.containsKey(split[0])) {
                HashMap<String, String> value = new HashMap<>();
                value.put(split[2], concatInOutStrings(split[1], split[3]));
                map.put(split[0], value);
                
                ArrayList<String> o = new ArrayList<>();
                o.add(split[3]);
                HashMap<String, ArrayList<String>> io = new HashMap<>();
                io.put(split[1], o);
                sb.put(split[0], io);
            } else {
                HashMap<String, String> value = map.get(split[0]);
                HashMap<String, ArrayList<String>> seenb = sb.get(split[0]);
                
                if(seenb.containsKey(split[1]) && seenb.get(split[1]).contains(split[3]))
                	continue;
                	
                if(!seenb.containsKey(split[1])) {
                	seenb.put(split[1],new ArrayList<String>());
                }
		            seenb.get(split[1]).add(split[3]);
                	
                if (value.containsKey(split[2])) {
                    String source = value.get(split[2]);
                    value.put(split[2], concatStrings(source, split[1], split[3]));
                } else {
                    value.put(split[2], concatInOutStrings(split[1], split[3]));
                    map.put(split[0], value);
                }
            }
        }
        return map;
    }

    private static String concatInOutStrings(String a, String b) {
        String[] states = b.split(";");
        String res = states[states.length - 1];
        return a + "-" + res;
    }

    private static String concatStrings(String source, String a, String b) {
        return source + " / " + concatInOutStrings(a,b);
    }
}

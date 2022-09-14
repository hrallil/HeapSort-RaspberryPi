import java.io.*;
import java.util.Random;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        int sampleSize = 6000; //K
        int n = 0; //n does nothing at this moment

        MaxHeap q = new MaxHeap<Integer>();
        FileCreator fc = new FileCreator();
        Scanner sc = new Scanner(fc.createTestFile(sampleSize));


        while (sc.hasNextLine()){
            q.insert(Integer.valueOf(sc.nextLine()));
        }

        //print out queue (to test if it sorted correctly)
        while(!q.isEmpty()){
            System.out.println(q.extractMin());
        }

    }
}

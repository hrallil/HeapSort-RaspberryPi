import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class FileCreator {
    public FileCreator() {
        int maxVal = 100;
        int numberOfData = 100;

    }
    public File createTestFile(int size){

        File file = new File("tests\\"+size/1000+"K-Sorted.txt");
        try {
            if (file.createNewFile()) {
                try {

                    FileWriter myWriter = new FileWriter(file);
                    for (int i = 0; i < size; i++) {
                        myWriter.write(Integer.toString(i)+ "\n");
                    }
                    myWriter.close();
                    System.out.println("Successfully wrote to the file.");
                } catch (IOException e) {
                    System.out.println("An error occurred.");
                    e.printStackTrace();
                }
                System.out.println("File created: " + file.getName());
            } else {
                System.out.println("File already exists.");
            }
        }catch(IOException e){
            System.out.println("An error occurred.");
            e.printStackTrace();
        }



        return file;
    }
}

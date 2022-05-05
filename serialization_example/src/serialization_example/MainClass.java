package serialization_example;
import java.io.*;

class Person implements Serializable{
    
    private String name;
    private int age;
    private double height;
    private transient boolean married;
      
    Person(String n, int a, double h, boolean m){
          
        name=n;
        age=a;
        height=h;
        married=m;
    }
    
    String getName() {return name;}
    int getAge(){ return age;}
    double getHeight(){return height;}
    boolean getMarried(){return married;}
}
public class MainClass {

	public static void main(String[] args) {
		
		try(ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("person.dat")))
        {
            Person p = new Person("Sam", 35, 155, false);
            oos.writeObject(p);
        }
        catch(Exception ex){
             
            System.out.println(ex.getMessage());
        } 
		
		 try(ObjectInputStream ois = new ObjectInputStream(new FileInputStream("person.dat")))
	        {
	            Person p=(Person)ois.readObject();
	            System.out.printf("Name: %s \t Age: %d \n", p.getName(), p.getAge());
	        }
	        catch(Exception ex){
	             
	            System.out.println(ex.getMessage());
	        }
		
	}

}


package tarea1edd2020;

import java.util.Scanner; 
public class Tarea1EDD2020 {


    public static void main(String[] args) {
       
        System.out.println("Ingrese el valor M");            
        Scanner entradaEscaner = new Scanner (System.in);   
        int m = Integer.parseInt(entradaEscaner.nextLine());
        
        int matriz[][] = new int[m][m];
        
       for (int x=0; x < matriz.length; x++) {
              
          for (int y=0; y < matriz[x].length; y++) {
               
            
            if (x==0){
                matriz[x][y] =1;
            }
            
            if (y ==0){
                matriz[x][y] =1;
            }
      
            if (x==matriz.length-1){
                matriz[x][y] = 1;
            }
            
            if (y==matriz[x].length-1){
                matriz[x][y] = 1;
            }
            
            System.out.print (matriz[x][y]);
            if (y!=matriz[x].length-1) System.out.print("\t");            
  }
  System.out.println("|");
  
}
        
        
    }
    
}

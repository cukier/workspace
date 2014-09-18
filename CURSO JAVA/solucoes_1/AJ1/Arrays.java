/**
 * Classe com o objetivo de praticar arrays de tipos primitivos e reference.
 * 
 * @author Melissa
 */
class Arrays {
  /**
   * M�todo para que esta classe possa ser executada com o utilit�rio java.
   * 
   * @param args
   *          - argumentos para o m�todo main
   */
  public static void main(String args[]) {
	String array[] = new String[5];
	for (int i = 0; i < array.length; i++) {
	  array[i] = "Cliente " + (i + 1) + " email: cliente" + (i + 1)
		  + "@cliente.com.br";
	}
	for (String string : array) {
	  System.out.println(string);
	}
  }
}

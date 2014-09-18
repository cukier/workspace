/**
 * Classe com o objetivo de praticar a utiliza��o de controladores de fluxo.
 * 
 * @author Globalcode
 */
class ControleFluxoForOpcional {
  /**
   * M�todo para que esta classe possa ser executada com o utilit�rio java.
   * 
   * @param args
   *          - argumentos para o m�todo main
   */
  public static void main(String[] args) {
	for (int i = 100; i <= 200; i++) {
	  if (i % 2 == 0 && i % 3 == 0) {
		System.out
		    .println(i
		        + " � divis�vel por 2 e divis�vel por 3 e portanto � divis�vel por 6");
	  } else if (i % 2 == 0) {
		System.out.println(i + " � divis�vel por 2");
	  } else if (i % 3 == 0) {
		System.out.println(i + " � divis�vel por 3");
	  }
	}
  }
}

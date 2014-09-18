/**
 * Classe com o objetivo de praticar a utiliza��o de controladores de fluxo.
 * 
 * @author Globalcode
 */
class ControleFluxoWhileOpcional {
  /**
   * M�todo para que esta classe possa ser executada com o utilit�rio java.
   * 
   * @param args
   *          - argumentos para o m�todo main
   */
  public static void main(String[] args) {
	int limiteInferior = 14;
	int limiteSuperior = 1578;
	int numerosDiv6 = 0;
	int temp = limiteInferior;
	while (temp <= limiteSuperior) {
	  if (temp % 6 == 0) {
		numerosDiv6++;
	  }
	  temp++;
	}
	String texto = "Quantidade de numeros divisiveis por 6 entre ";
	System.out.println(texto + limiteInferior + " e " + limiteSuperior
	    + " e : " + numerosDiv6);
  }
}

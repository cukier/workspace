/**
 * Classe com o objetivo de fixar a declara��o, inicializa��o e utiliza��o de
 * vari�veis de tipos primitivos e String.
 * 
 * @author Globalcode
 */
public class DeclaracaoVariaveis {
  /**
   * M�todo para que esta classe possa ser executada com o utilit�rio java.
   * 
   * @param args
   *          - argumentos para o m�todo main
   */
  public static void main(String[] args) {
	String nome = "Carolina Pereira";
	int idade = 20;
	String rg = "34.654.789-9";
	char sexo = 'F';
	double salario = 1500.0;
	System.out.print("O(a) Senhor(a) " + nome + ", de " + idade);
	System.out.println(" anos, portador(a) do RG de n�mero " + rg + ", ");
	System.out.print("do sexo " + sexo);
	System.out.println(", est� registrado(a) com o sal�rio de R$ " + salario);
  }
}

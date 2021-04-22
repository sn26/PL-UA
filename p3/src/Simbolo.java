/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Alvar
 */
public class Simbolo {
    // los símbolos pueden ser variables enteras o reales, o funciones. 
    // (el tipo VOID se usa puntualmente, cuando la función no ha declarado tipo ni lo ha heredado)
    public static final int ENTERO=1, REAL=2, FUNCION=3, VOID=4;
  

    /**
     * nombre del símbolo en el programa fuente
     */
    public String nombre;

    /**
     * tipo (ENTERO, REAL, FUNCION)     (VOID nunca puede ser)
     */
    public int tipo;        

    /**
     * nombre traducido al lenguaje objeto (se genera en la declaración)
     */
    public String nomtrad;


    /**
     * constructor
     * @param nombre  nombre en el programa fuente
     * @param tipo    tipo con el que se declara
     * @param nomtrad nombre en el lenguaje objeto
     */
    public Simbolo(String nombre,int tipo,String nomtrad)
    {
      this.nombre = nombre;
      this.tipo = tipo;
      this.nomtrad = nomtrad;
    }
}

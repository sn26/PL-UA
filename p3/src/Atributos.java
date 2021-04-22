/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Alvar
 */
public class Atributos {
    public String[] atributos;
    
    public Atributos(String[] atributos){
        this.atributos = atributos;  
    }
    
    /**
     * Para mirar si tenemos una asignacion o solamente el tipo
     * @return 
     */
    public boolean hasAnAsig(){
        if(this.atributos.length > 1 ) return true; 
        return false; 
        
    }
    
    /**
     * Devolvemos el tipo (Lo usamos en los let)
     * @return 
     */
    public String getTipo(){
        return this.atributos[0]; 
    }
    
    
    /**
     * Devolvemos la asignacion (Si fuera necesario)
     * @return 
     */
    public String getAsig(){
        return this.atributos[1]; 
    } 
}

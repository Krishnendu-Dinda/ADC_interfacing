# ADC_interfacing
<br>
 This new post I share my new work which is interfacing an ADC ic with 8051 microcontroller.      
 For this work I use  ADC0804 ic which is a 8-bit resolution differential analogies voltage input 0v-5v input voltage range.        
 The main thing  in ADC  is Resolution which is calculated by " (max input voltage) /2^n "(n is bit number) this formula.      
 ADC 0804 is a single channel analog to digital  converter. It  takes only one analog signal. It has 8-bit resolution. Input voltage span is 0-5v and step size is 
 19.53mV(5v/256) . In this situation we open Vref/2.         
 
 The programming step given below :-     
 S1). Write a function for LCD data & LCD  command.  
 S2). Write a function which divides the hex value which is to get the ADC,  to a single character.  
 S3). start main function. In the main function first send a high signal to the "wrt" pin of ADC ic. 
 S4). Start an infinite loop  first send a  high signal to "rd" pin of ADC ic . then send a low signal to "wrt" pin  of the ADC ic then after so. after some delay send 
      high signal to the "wrt" pin of ADC ic .  
 S5). Check "intr" pin value  is high or not  , if high then send a high signal to the "rd" pin of ADC ic . 
 S6).   The value sent to the  LCD  for displaying. 
 S7). Close the infinite loop & main function.

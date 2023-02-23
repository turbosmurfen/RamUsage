## Better to use Moo.mrc, which can be found here: https://hm2k.org/projects/moo  



# RamUsage  
This is a DLL-file to read memory information. This is only made for mIRC.  

### Examples grab how much RAM you have.  
```//echo -a $dll(RamUsage.dll,mem,memtotal)```  
Example result:  
```16300```  
  
### Example grab how much RAM that you use at the moment.  
```//echo -a $dll(RamUsage.dll,mem,memused,)```  
Example result:  
```7191``` 

### Example grab memory load.  
```//echo -a $dll(RamUsage.dll,mem,memload,)```    
Example result:  
```40``` 


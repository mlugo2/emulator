# Sunflower VM
___
### Instruction Set Architecture

| Opcode      | Mnumonic      | Desc. |
|:------------- |:------------- |:-----:|
| 0x00          | \---------    | n/a   |
| 0x01          | IADD		   	  |    |
| 0x02          | ISUB      	  |     |
| 0x03          | IMUL 			    | |
| 0x04          | ILT      		  |    |
| 0x05          | IEQ      		  |    |
| 0x06          | BR 			      |  |
| 0x07          | BRT      		  |    |
| 0x08          | BRF      		|     |
| 0x09          | ICONST 		|  |
| 0x0A          | LOAD      	|    |
| 0x0B          | GLOAD      	|     |
| 0x0C          | STORE 		|  |
| 0x0D          | GSTORE      	|    |
| 0x0E          | PRINT      	|     |
| 0x0F          | POP 			|  |
| 0x10          | CALL      	|    |
| 0x11          | RET      		|     |
| 0x12          | IAND      	|     |
| 0x13          | IOR      	|     |
| 0x14          | INOT      	|     |
| 0x15          | LSFT      	|     |
| 0x16          | RSFT      	|     |
| 0x17          | ROTR      	|     |
| 0x18          | ROTL      	|     |
| 0x19          | HALT      	|     |

***
### Memory Map

| Memory        | Description     |
|:------------- |:------------- |
| 0xFFFF          | ASCII values are read or written here
| 0xFFFE          | Status for which INT(0x00 - 0xFF)
|                 | 0x00: No interrupt, the CPU runs.
|                 | 0x01: Get input from keyboard.
|                 | 0x02: Text mode, print character to cursor location.
|                 | 0x03: Graphics mode.
| 0xFFFD          | if (Text mode):
|                 | X position for the cursor (00h - 50h)       
|                 | if (Graphics mode):
|                 | High byte for X position (00h - ??)
| 0xFFFC          | if (Text mode):
|                 |  Y position for the cursor (00h - 20h)
|                 | if (Graphics mode):
|                 | Low byte for X position (00h - FFh)
| 0xFFFB          | if (Text mode):
|                 | Color for the character
|                 | if (Graphics mode):
|                 | High byte for Y position (00h - ??)
| 0xFFFA          | if (Text mode):
|                 | Color for the background
|                 | if (Graphics mode):
|                 | Low byte for Y position (00h - FFh)
| 0xFFF9          | Color of pixel for graphics mode    
| 0xFFF8          | 	   	  |
| 0xFFF7          |       	  |
| 0xFFF6          |   |

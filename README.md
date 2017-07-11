# Sunflower VM

| Operands      | Mnumonic      | Desc. |
|:------------- |:------------- |:-----:|
| 0x00          | \---------    | n/a   |
| 0x01          | IADD		   	|   [TOS] = [TOS] + [TOS+1] |
| 0x02          | ISUB      	|    $1 |
| 0x03          | IMUL 			| $1600 |
| 0x04          | ILT      		|   $12 |
| 0x05          | IEQ      		|    $1 |
| 0x06          | BR 			| $1600 |
| 0x07          | BRT      		|   $12 |
| 0x08          | BRF      		|    $1 |
| 0x09          | ICONST 		| $1600 |
| 0x0A          | LOAD      	|   $12 |
| 0x0B          | GLOAD      	|    $1 |
| 0x0C          | STORE 		| $1600 |
| 0x0D          | GSTORE      	|   $12 |
| 0x0E          | PRINT      	|    $1 |
| 0x0F          | POP 			| $1600 |
| 0x10          | CALL      	|   $12 |
| 0x11          | RET      		|    $1 |
| 0x12          | HALT      	|    $1 |
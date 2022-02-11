int F_1 ( const struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 = ( ( V_3 + V_4 - 1 ) & 0x3 ) + F_2 ( 0x2a0 ) ;
if ( ( V_3 | ( V_4 - 1 ) ) > 0x3 ) {
F_3 ( V_6 L_1 ,
V_3 , V_4 - 1 + 'A' ) ;
return - 1 ;
}
return V_5 ;
}
int F_4 ( struct V_7 * V_8 )
{
unsigned long V_9 , V_10 ;
V_9 = F_5 ( V_11 ) ;
V_9 |= 0x40080000 ;
F_6 ( V_8 , V_9 , V_12 ) ;
V_10 = F_5 ( V_13 ) ;
V_10 = ( V_10 & V_14 ) & V_15 ;
F_6 ( V_8 , V_10 , V_16 ) ;
F_6 ( V_8 , 0x0c000000 , V_17 ) ;
F_6 ( V_8 , 0xd0000000 , V_18 ) ;
F_6 ( V_8 , 0x0c000000 , V_19 ) ;
F_6 ( V_8 , 0x00000000 , V_20 ) ;
return 0 ;
}

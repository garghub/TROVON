int F_1 ( const struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
if ( F_2 () )
return V_5 [ V_3 ] ;
else
return V_6 [ V_3 ] ;
}
int F_3 ( struct V_7 * V_8 )
{
unsigned long V_9 , V_10 ;
V_9 = F_4 ( V_11 ) ;
V_9 |= 0x40080000 ;
F_5 ( V_8 , V_9 , V_12 ) ;
F_5 ( V_8 , 0x0000c3ff , V_13 ) ;
F_5 ( V_8 , 0x0000380f , V_14 ) ;
F_5 ( V_8 , 0xfb900047 , V_15 ) ;
F_5 ( V_8 , 0xab000001 , V_16 ) ;
V_10 = F_4 ( V_17 ) ;
V_10 = ( V_10 & V_18 ) & V_19 ;
F_5 ( V_8 , V_10 , V_20 ) ;
F_5 ( V_8 , 0x0c000000 , V_21 ) ;
F_5 ( V_8 , 0xd0000000 , V_22 ) ;
F_5 ( V_8 , 0x0c000000 , V_23 ) ;
F_5 ( V_8 , 0x00000000 , V_24 ) ;
return 0 ;
}

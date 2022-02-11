T_1 void T_2 F_1 ( void )
{
int V_1 ;
for ( V_1 = 0x000 ; V_1 < 0x400 ; V_1 += 8 )
F_2 ( V_1 , V_2 ) ;
F_2 ( V_3 , V_4 ) ;
F_2 ( V_5 , V_6 ) ;
F_2 ( V_7 , V_8 ) ;
F_2 ( V_9 , V_10 ) ;
F_2 ( V_11 , V_12 ) ;
F_2 ( V_13 , V_14 ) ;
F_2 ( V_15 , V_16 ) ;
F_2 ( V_17 , V_18 ) ;
F_2 ( V_19 , V_20 ) ;
F_2 ( V_21 , V_20 ) ;
F_2 ( V_22 , V_23 ) ;
F_2 ( V_24 , V_23 ) ;
F_2 ( V_25 , V_23 ) ;
F_2 ( V_26 , V_23 ) ;
F_2 ( V_27 , V_23 ) ;
F_2 ( V_28 , V_23 ) ;
F_2 ( V_29 , V_23 ) ;
V_30 = V_22 ;
V_31 = V_24 ;
V_32 = V_25 ;
V_33 = V_26 ;
V_34 = V_27 ;
V_35 = V_28 ;
V_36 = V_29 ;
#ifndef F_3
F_4 () ;
F_5 () ;
#endif
#ifdef F_6
for ( V_1 = 0 ; V_1 < V_37 ; V_1 ++ )
F_7 ( V_1 ) = V_38 | V_39 ;
#else
for ( V_1 = 0 ; V_1 < V_40 ; V_1 ++ )
F_7 ( V_1 ) = V_38 | V_39 ;
#endif
V_41 = 0 ;
V_42 = 0 ;
V_43 = 0 ;
V_44 = 0 ;
V_45 = 0 ;
V_46 = 0 ;
V_47 = 0 ;
V_48 = 0 ;
V_49 = 0 ;
V_50 = 0 ;
V_51 = 0 ;
V_52 = 0 ;
V_53 = 0 ;
V_54 = 0 ;
V_55 = 0 ;
V_56 = 0 ;
V_57 = 0 ;
V_58 = 0 ;
F_8 () ;
}
void T_2 F_9 ( unsigned long * V_59 , unsigned long * V_60 )
{
unsigned long V_61 = V_62 ;
unsigned long V_63 = 0 ;
* V_59 = 0x90000000 ;
switch ( V_61 & 0x00000003 ) {
case 0x01 :
V_63 = 256 / 8 ;
break;
case 0x02 :
V_63 = 512 / 8 ;
break;
case 0x03 :
V_63 = 1024 / 8 ;
break;
default:
F_10 ( L_1 ) ;
break;
}
F_11 ( V_64 L_2 , V_63 , * V_59 ) ;
* V_60 = ( V_63 * 2 ) << 20 ;
}

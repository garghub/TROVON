static int T_1 F_1 ( void )
{
struct V_1 * V_2 = F_2 ( 0 ) ;
struct V_3 V_4 ;
int V_5 , V_6 ;
T_2 V_7 [] = {
0x40 , 0x2a ,
0x43 , 0x3c ,
0x44 , 0x3c ,
0x45 , 0x3c ,
0x54 , 0x03 ,
0x51 , 0x00 ,
0x51 , 0x01 ,
0xff , 0x00 ,
0x43 , 0xf0 ,
0x44 , 0xf0 ,
0x45 , 0xf0 ,
} ;
if ( ! F_3 () )
return 0 ;
if ( ! V_2 )
return 0 ;
V_4 . V_8 = 0x40 ;
V_4 . V_9 = 2 ;
V_4 . V_10 = 0 ;
for ( V_5 = 0 ; V_5 < F_4 ( V_7 ) ; V_5 += 2 ) {
V_4 . V_11 = V_7 + V_5 ;
if ( 0xff == V_4 . V_11 [ 0 ] ) {
F_5 ( 500 ) ;
continue;
}
V_6 = F_6 ( V_2 , & V_4 , 1 ) ;
if ( V_6 < 0 ) {
F_7 ( L_1 ) ;
break;
}
}
return 0 ;
}
static void T_1 F_8 ( void )
{
F_9 () ;
F_10 ( V_12 , NULL ) ;
F_10 ( V_13 , NULL ) ;
F_10 ( V_14 , NULL ) ;
F_10 ( V_15 , NULL ) ;
F_10 ( V_16 , NULL ) ;
F_10 ( V_17 , NULL ) ;
F_11 ( V_17 ) ;
F_10 ( V_18 , NULL ) ;
F_10 ( V_19 , NULL ) ;
F_10 ( V_20 , NULL ) ;
F_10 ( V_21 , NULL ) ;
F_10 ( V_22 , NULL ) ;
F_10 ( V_23 , NULL ) ;
F_10 ( V_24 , NULL ) ;
F_10 ( V_25 , NULL ) ;
F_10 ( V_26 , NULL ) ;
F_10 ( V_27 , NULL ) ;
F_10 ( V_28 , NULL ) ;
F_10 ( V_29 , NULL ) ;
F_10 ( V_30 , NULL ) ;
F_10 ( V_31 , NULL ) ;
F_10 ( V_32 , NULL ) ;
F_10 ( V_33 , NULL ) ;
F_10 ( V_34 , NULL ) ;
F_10 ( V_35 , NULL ) ;
F_10 ( V_36 , NULL ) ;
F_10 ( V_37 , NULL ) ;
F_10 ( V_38 , NULL ) ;
F_10 ( V_39 , NULL ) ;
F_10 ( V_40 , NULL ) ;
F_10 ( V_41 , NULL ) ;
F_10 ( V_42 , NULL ) ;
F_10 ( V_43 , NULL ) ;
F_10 ( V_44 , NULL ) ;
F_10 ( V_45 , NULL ) ;
F_12 ( V_44 , 1 ) ;
F_12 ( V_45 , 1 ) ;
F_10 ( V_46 , NULL ) ;
F_11 ( V_46 ) ;
F_10 ( V_47 , NULL ) ;
F_10 ( V_48 , NULL ) ;
F_10 ( V_49 , NULL ) ;
F_10 ( V_50 , NULL ) ;
F_10 ( V_51 , NULL ) ;
F_10 ( V_52 , NULL ) ;
F_10 ( V_53 , NULL ) ;
F_10 ( V_54 , NULL ) ;
F_10 ( V_55 , NULL ) ;
F_10 ( V_56 , NULL ) ;
F_10 ( V_57 , NULL ) ;
F_10 ( V_58 , NULL ) ;
F_10 ( V_59 , NULL ) ;
F_10 ( V_60 , NULL ) ;
F_10 ( V_61 , NULL ) ;
F_10 ( V_62 , NULL ) ;
F_10 ( V_63 , NULL ) ;
F_10 ( V_64 , NULL ) ;
F_10 ( V_65 , NULL ) ;
F_10 ( V_66 , NULL ) ;
F_12 ( V_66 , 1 ) ;
F_10 ( V_67 , NULL ) ;
F_10 ( V_68 , NULL ) ;
#ifdef F_13
F_14 ( F_15 ( 0xf0100000 ) , 0x40460000 , 0x82000fff ) ;
#endif
F_16 ( 1 , V_69 , F_4 ( V_69 ) ) ;
F_16 ( 3 , V_70 , F_4 ( V_70 ) ) ;
F_17 () ;
F_18 ( V_71 , F_4 ( V_71 ) ) ;
}

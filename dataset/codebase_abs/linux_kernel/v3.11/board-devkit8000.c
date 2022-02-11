static int F_1 ( struct V_1 * V_2 ,
unsigned V_3 , unsigned V_4 )
{
V_5 [ 0 ] . V_6 = V_3 + 0 ;
F_2 ( V_5 ) ;
V_7 [ 2 ] . V_3 = V_3 + V_8 + 1 ;
V_9 . V_10 = 1 ;
V_9 . V_11 [ 0 ] = V_3 + V_8 + 0 ;
V_12 . V_13 = V_3 + 7 ;
return 0 ;
}
static int T_1 F_3 ( void )
{
F_4 ( & V_14 ,
V_15 | V_16 ,
V_17 ) ;
F_5 ( L_1 , & V_14 ) ;
F_6 ( 3 , 400 , NULL , 0 ) ;
return 0 ;
}
static void T_1 F_7 ( void )
{
unsigned char * V_18 = V_19 . V_20 ;
struct V_21 V_22 ;
int V_23 ;
V_23 = F_8 ( V_24 , V_25 , L_2 ) ;
if ( V_23 < 0 ) {
F_9 ( V_26 L_3 ,
V_24 ) ;
return;
}
F_10 ( & V_22 ) ;
V_18 [ 0 ] = 0x02 ;
V_18 [ 1 ] = V_22 . V_27 & 0xff ;
V_18 [ 2 ] = ( V_22 . V_28 & 0xff000000 ) >> 24 ;
V_18 [ 3 ] = ( V_22 . V_28 & 0x00ff0000 ) >> 16 ;
V_18 [ 4 ] = ( V_22 . V_28 & 0x0000ff00 ) >> 8 ;
V_18 [ 5 ] = ( V_22 . V_28 & 0x000000ff ) ;
}
static void T_1 F_11 ( void )
{
F_12 ( V_29 , V_30 ) ;
F_13 () ;
F_14 ( V_31 ,
V_31 ) ;
F_7 () ;
F_15 ( V_5 ) ;
F_3 () ;
V_32 [ 2 ] . V_33 = F_16 ( V_24 ) ;
F_17 ( V_34 ,
F_18 ( V_34 ) ) ;
F_19 ( & V_35 ) ;
F_20 ( 2 , V_36 , 0 , NULL ) ;
F_21 ( L_4 , 0 , L_5 ) ;
F_22 ( NULL ) ;
F_23 ( & V_37 ) ;
F_24 ( V_38 ,
F_18 ( V_38 ) , V_39 ,
V_40 , NULL ) ;
F_25 ( L_6 , NULL ) ;
F_26 ( L_7 , V_41 ) ;
F_26 ( L_8 , V_41 ) ;
}

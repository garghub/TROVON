static int F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_3 ) )
F_3 ( V_2 -> V_3 , 1 ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_3 ) )
F_3 ( V_2 -> V_3 , 0 ) ;
}
static int F_5 ( struct V_4 * V_5 ,
unsigned V_6 , unsigned V_7 )
{
int V_8 ;
V_9 [ 0 ] . V_10 = V_6 + 0 ;
F_6 ( V_9 ) ;
V_11 [ 2 ] . V_6 = V_6 + V_12 + 1 ;
V_13 . V_3 = V_6 + V_12 + 0 ;
V_8 = F_7 ( V_13 . V_3 ,
V_14 , L_1 ) ;
if ( V_8 < 0 ) {
V_13 . V_3 = - V_15 ;
F_8 ( V_16 L_2 ) ;
}
V_17 . V_18 = V_6 + 7 ;
return 0 ;
}
static int T_1 F_9 ( void )
{
F_10 ( & V_19 ,
V_20 | V_21 ,
V_22 ) ;
F_11 ( L_3 , & V_19 ) ;
F_12 ( 3 , 400 , NULL , 0 ) ;
return 0 ;
}
static void T_1 F_13 ( void )
{
unsigned char * V_23 = V_24 . V_25 ;
struct V_26 V_27 ;
int V_8 ;
V_8 = F_7 ( V_28 , V_29 , L_4 ) ;
if ( V_8 < 0 ) {
F_8 ( V_16 L_5 ,
V_28 ) ;
return;
}
F_14 ( & V_27 ) ;
V_23 [ 0 ] = 0x02 ;
V_23 [ 1 ] = V_27 . V_30 & 0xff ;
V_23 [ 2 ] = ( V_27 . V_31 & 0xff000000 ) >> 24 ;
V_23 [ 3 ] = ( V_27 . V_31 & 0x00ff0000 ) >> 16 ;
V_23 [ 4 ] = ( V_27 . V_31 & 0x0000ff00 ) >> 8 ;
V_23 [ 5 ] = ( V_27 . V_31 & 0x000000ff ) ;
}
static void T_1 F_15 ( void )
{
F_16 ( V_32 , V_33 ) ;
F_17 () ;
F_18 ( V_34 ,
V_34 ) ;
F_13 () ;
F_19 ( V_9 ) ;
F_9 () ;
V_35 [ 2 ] . V_36 = F_20 ( V_28 ) ;
F_21 ( V_37 ,
F_22 ( V_37 ) ) ;
F_23 ( & V_38 ) ;
F_24 ( 2 , V_39 , 0 , NULL ) ;
F_25 ( NULL ) ;
F_26 ( & V_40 ) ;
F_27 ( V_41 ,
F_22 ( V_41 ) , V_42 ,
V_43 , NULL ) ;
F_28 ( L_6 ) ;
F_29 ( L_7 , V_44 ) ;
F_29 ( L_8 , V_44 ) ;
}

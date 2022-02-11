static int F_1 ( struct V_1 * V_2 ,
unsigned V_3 , unsigned V_4 )
{
if ( V_5 >= 0x20 && V_5 <= 0x34301000 ) {
F_2 ( 23 , V_6 ) ;
V_7 [ 0 ] . V_8 = 23 ;
} else {
F_2 ( 29 , V_6 ) ;
}
V_7 [ 0 ] . V_9 = V_3 + 0 ;
F_3 ( V_7 ) ;
V_10 . V_2 = V_7 [ 0 ] . V_2 ;
V_11 . V_2 = V_7 [ 0 ] . V_2 ;
F_4 ( V_3 + 1 , V_12 , L_1 ) ;
F_4 ( V_3 + V_13 , V_14 ,
L_2 ) ;
V_15 [ 2 ] . V_3 = V_3 + V_13 + 1 ;
return 0 ;
}
static int T_1 F_5 ( void )
{
F_6 ( L_3 , & V_16 ) ;
F_7 ( 3 , 100 , V_17 ,
F_8 ( V_17 ) ) ;
return 0 ;
}
static void T_1 F_9 ( void )
{
F_10 () ;
F_11 ( V_18 ,
V_18 ) ;
}
static void T_1 F_12 ( void )
{
F_13 () ;
#ifdef F_14
F_15 ( 12 ) ;
#endif
}
static void F_16 ( void )
{
int V_19 = V_20 ;
if ( F_4 ( V_19 , V_14 , L_4 ) < 0 )
F_17 ( V_21 L_5 ) ;
}
static int T_1 F_18 ( char * V_22 )
{
if ( ! V_22 )
return 0 ;
return F_19 ( V_22 , 10 , & V_23 ) ;
}
static void T_1 F_20 ( void )
{
F_21 ( V_24 , V_25 ) ;
V_26 = V_27 ;
V_28 = F_8 ( V_27 ) ;
V_29 = F_16 ;
F_5 () ;
F_22 ( V_30 ,
F_8 ( V_30 ) ) ;
F_23 () ;
F_2 ( 170 , V_6 ) ;
F_4 ( 176 , V_31 , L_6 ) ;
F_24 ( 4 , V_32 , 310 , & V_33 ) ;
F_25 ( NULL ) ;
F_26 ( & V_34 ) ;
F_27 ( V_35 , V_36 ,
F_8 ( V_36 ) ) ;
F_28 ( L_7 , V_37 ) ;
F_28 ( L_8 , V_37 ) ;
}

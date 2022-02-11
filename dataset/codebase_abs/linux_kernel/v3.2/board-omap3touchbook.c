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
F_4 ( V_3 + 1 , V_10 , L_1 ) ;
F_4 ( V_3 + V_11 , V_12 ,
L_2 ) ;
V_13 [ 2 ] . V_3 = V_3 + V_11 + 1 ;
return 0 ;
}
static int T_1 F_5 ( void )
{
F_6 ( & V_14 ,
V_15 | V_16 ,
V_17 | V_18 ) ;
V_14 . V_19 -> V_20 =
F_7 ( V_21 ) ;
V_14 . V_19 -> V_22 = V_21 ;
V_14 . V_23 -> V_24 . V_25 = L_3 ;
V_14 . V_23 -> V_20 =
F_7 ( V_26 ) ;
V_14 . V_23 -> V_22 = V_26 ;
F_8 ( L_4 , & V_14 ) ;
F_9 ( 3 , 100 , V_27 ,
F_7 ( V_27 ) ) ;
return 0 ;
}
static void F_10 ( void )
{
int V_28 = V_29 ;
if ( F_4 ( V_28 , V_12 , L_5 ) < 0 )
F_11 ( V_30 L_6 ) ;
}
static int T_1 F_12 ( char * V_31 )
{
if ( ! V_31 )
return 0 ;
return F_13 ( V_31 , 10 , & V_32 ) ;
}
static void T_1 F_14 ( void )
{
F_15 ( V_33 , V_34 ) ;
V_35 = F_10 ;
F_5 () ;
F_16 ( V_36 ,
F_7 ( V_36 ) ) ;
F_17 () ;
F_18 ( V_37 ,
V_37 ) ;
F_2 ( 170 , V_6 ) ;
F_4 ( 176 , V_38 , L_7 ) ;
F_19 ( 4 , V_39 , 310 , & V_40 ) ;
F_20 ( NULL ) ;
F_21 ( & V_41 ) ;
F_22 ( V_42 , V_43 ,
F_7 ( V_43 ) ) ;
F_23 ( L_8 , V_44 ) ;
F_23 ( L_9 , V_44 ) ;
}

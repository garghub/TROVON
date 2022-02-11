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
static void T_1 F_10 ( void )
{
F_11 () ;
F_12 ( V_28 ,
V_28 ) ;
}
static void T_1 F_13 ( void )
{
F_14 () ;
}
static void F_15 ( void )
{
int V_29 = V_30 ;
if ( F_4 ( V_29 , V_12 , L_5 ) < 0 )
F_16 ( V_31 L_6 ) ;
}
static int T_1 F_17 ( char * V_32 )
{
if ( ! V_32 )
return 0 ;
return F_18 ( V_32 , 10 , & V_33 ) ;
}
static void T_1 F_19 ( void )
{
F_20 ( V_34 , V_35 ) ;
V_36 = V_37 ;
V_38 = F_7 ( V_37 ) ;
V_39 = F_15 ;
F_5 () ;
F_21 ( V_40 ,
F_7 ( V_40 ) ) ;
F_22 () ;
F_2 ( 170 , V_6 ) ;
F_4 ( 176 , V_41 , L_7 ) ;
F_23 ( 4 , V_42 , 310 , & V_43 ) ;
F_24 ( NULL ) ;
F_25 ( & V_44 ) ;
F_26 ( V_45 , V_46 ,
F_7 ( V_46 ) ) ;
F_27 ( L_8 , V_47 ) ;
F_27 ( L_9 , V_47 ) ;
}

static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 |= V_4 ;
V_2 -> V_5 . V_6 = 1 ;
V_2 -> V_7 . V_8 = 0x104c ;
V_2 -> V_7 . V_9 = 0x9066 ;
V_2 -> V_7 . V_10 = 512 ;
V_2 -> V_7 . V_11 = 20000000 ;
}
static int F_2 ( struct V_9 * V_12 ,
unsigned V_13 , unsigned V_14 )
{
int V_15 , V_16 ;
V_17 [ 0 ] . V_18 = V_13 + 0 ;
V_17 [ 1 ] . V_18 = V_13 + 1 ;
F_3 ( V_17 ) ;
V_16 = V_13 + 13 ;
V_15 = F_4 ( V_16 , V_19 , L_1 ) ;
if ( V_15 < 0 ) {
F_5 ( L_2 , V_16 , V_15 ) ;
return - V_20 ;
}
return 0 ;
}
static int T_1 F_6 ( void )
{
F_7 ( & V_21 ,
V_22 | V_23 ,
V_24 | V_25 ) ;
V_21 . V_26 -> V_27 . V_28 = true ;
V_21 . V_29 -> V_27 . V_28 = true ;
V_21 . V_29 -> V_30 =
F_8 ( V_31 ) ;
V_21 . V_29 -> V_32 = V_31 ;
F_9 ( L_3 , & V_21 ) ;
F_10 ( 3 , 100 , V_33 ,
F_8 ( V_33 ) ) ;
return 0 ;
}
static void T_1 F_11 ( void )
{
F_12 () ;
F_13 ( V_34 ,
V_34 ) ;
}
static void T_1 F_14 ( void )
{
struct V_35 V_36 ;
int V_15 ;
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
V_15 = F_4 ( V_37 , V_38 , L_4 ) ;
if ( V_15 < 0 )
goto V_39;
V_36 . V_40 = F_15 ( V_37 ) ;
if ( V_36 . V_40 < 0 )
goto V_41;
V_36 . V_42 = true ;
V_15 = F_16 ( & V_36 ) ;
if ( V_15 < 0 )
goto V_41;
return;
V_41:
F_17 ( V_37 ) ;
V_39:
F_18 ( V_43 L_5 ) ;
}
static void T_1 F_19 ( void )
{
F_20 ( V_44 , V_45 ) ;
F_6 () ;
F_14 () ;
F_21 ( V_46 ,
F_8 ( V_46 ) ) ;
F_22 ( & V_47 ) ;
F_23 () ;
F_24 ( V_48 ,
F_8 ( V_48 ) ) ;
F_25 ( 1 , V_49 , 0 , NULL ) ;
F_26 ( & V_50 ) ;
F_27 ( NULL ) ;
F_28 ( & V_51 ) ;
F_29 ( L_6 , V_52 ) ;
F_29 ( L_7 , V_52 ) ;
}

static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> type == V_3 || V_2 -> type == V_4 ) {
V_2 -> V_5 |= V_6 ;
V_2 -> V_7 . V_8 = 1 ;
V_2 -> V_9 . V_10 = 0x104c ;
V_2 -> V_9 . V_11 = 0x9066 ;
V_2 -> V_9 . V_12 = 512 ;
V_2 -> V_9 . V_13 = 20000000 ;
}
}
static int F_2 ( struct V_11 * V_14 ,
unsigned V_15 , unsigned V_16 )
{
int V_17 , V_18 ;
V_19 [ 0 ] . V_20 = V_15 + 0 ;
V_19 [ 1 ] . V_20 = V_15 + 1 ;
F_3 ( V_19 ) ;
V_18 = V_15 + 13 ;
V_17 = F_4 ( V_18 , V_21 , L_1 ) ;
if ( V_17 < 0 ) {
F_5 ( L_2 , V_18 , V_17 ) ;
return - V_22 ;
}
return 0 ;
}
static int T_1 F_6 ( void )
{
F_7 ( & V_23 ,
V_24 | V_25 ,
V_26 | V_27 ) ;
V_23 . V_28 -> V_29 . V_30 = true ;
V_23 . V_31 -> V_29 . V_30 = true ;
V_23 . V_31 -> V_32 =
F_8 ( V_33 ) ;
V_23 . V_31 -> V_34 = V_33 ;
F_9 ( L_3 , & V_23 ) ;
F_10 ( 3 , 100 , V_35 ,
F_8 ( V_35 ) ) ;
return 0 ;
}
static void T_1 F_11 ( void )
{
struct V_36 V_37 ;
int V_17 ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_38 = - 1 ;
V_17 = F_4 ( V_39 , V_40 , L_4 ) ;
if ( V_17 < 0 )
goto V_41;
V_37 . V_42 = F_12 ( V_39 ) ;
if ( V_37 . V_42 < 0 )
goto V_43;
V_37 . V_44 = true ;
V_17 = F_13 ( & V_37 ) ;
if ( V_17 < 0 )
goto V_43;
return;
V_43:
F_14 ( V_39 ) ;
V_41:
F_15 ( V_45 L_5 ) ;
}
static void T_1 F_16 ( void )
{
F_17 ( V_46 , V_47 ) ;
F_18 ( V_19 ) ;
F_6 () ;
F_11 () ;
F_19 ( V_48 ,
F_8 ( V_48 ) ) ;
F_20 ( & V_49 ) ;
F_21 () ;
F_22 ( V_50 ,
V_50 ) ;
F_23 ( V_51 ,
F_8 ( V_51 ) ) ;
F_24 ( 1 , V_52 , 0 , NULL ) ;
F_25 ( V_53 , F_8 ( V_53 ) ) ;
F_26 ( & V_54 ) ;
F_27 ( L_6 , 0 , L_7 ) ;
F_28 ( NULL ) ;
F_29 ( & V_55 , NULL ) ;
F_30 ( L_8 , V_56 ) ;
F_30 ( L_9 , V_56 ) ;
}

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
F_7 ( L_3 , & V_21 ) ;
F_8 ( 3 , 100 , V_22 ,
F_9 ( V_22 ) ) ;
return 0 ;
}
static void T_1 F_10 ( void )
{
F_11 () ;
F_12 ( V_23 ,
V_23 ) ;
}
static void T_1 F_13 ( void )
{
struct V_24 V_25 ;
int V_15 ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
V_15 = F_4 ( V_26 , V_27 , L_4 ) ;
if ( V_15 < 0 )
goto V_28;
V_25 . V_29 = F_14 ( V_26 ) ;
if ( V_25 . V_29 < 0 )
goto V_30;
V_25 . V_31 = true ;
V_15 = F_15 ( & V_25 ) ;
if ( V_15 < 0 )
goto V_30;
return;
V_30:
F_16 ( V_26 ) ;
V_28:
F_17 ( V_32 L_5 ) ;
}
static void T_1 F_18 ( void )
{
F_19 ( V_33 , V_34 ) ;
F_6 () ;
F_13 () ;
F_20 ( V_35 ,
F_9 ( V_35 ) ) ;
F_21 ( & V_36 ) ;
F_22 () ;
F_23 ( V_37 ,
F_9 ( V_37 ) ) ;
F_24 ( 1 , V_38 , 0 , NULL ) ;
F_25 ( & V_39 ) ;
F_26 ( NULL ) ;
F_27 ( & V_40 ) ;
F_28 ( L_6 , V_41 ) ;
F_28 ( L_7 , V_41 ) ;
}

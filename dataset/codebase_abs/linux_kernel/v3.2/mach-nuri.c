static void T_1 F_1 ( void )
{
F_2 ( & V_1 ) ;
F_3 ( & V_2 ) ;
F_4 ( & V_3 ) ;
}
static void F_5 ( struct V_4 * V_5 , unsigned int V_6 )
{
int V_7 = F_6 ( 5 ) ;
F_7 ( V_7 , L_1 ) ;
F_8 ( V_7 , V_6 ) ;
F_9 ( V_7 ) ;
}
static int F_10 ( struct V_8 * V_9 )
{
int V_10 , V_7 = F_11 ( 3 ) ;
V_10 = F_7 ( V_7 , L_2 ) ;
if ( ! V_10 )
F_8 ( V_7 , 0 ) ;
return V_10 ;
}
static int F_12 ( struct V_8 * V_9 , int V_11 )
{
if ( V_11 < 1 )
V_11 = 0 ;
F_13 ( F_11 ( 3 ) , 1 ) ;
return V_11 ;
}
static void F_14 ( struct V_8 * V_9 )
{
F_9 ( F_11 ( 3 ) ) ;
}
static void T_1 F_15 ( void )
{
int V_7 ;
V_7 = F_16 ( 4 ) ;
F_7 ( V_7 , L_3 ) ;
F_17 ( V_7 , F_18 ( 0xf ) ) ;
F_19 ( V_7 , V_12 ) ;
}
static void T_1 F_20 ( void )
{
int V_7 ;
int V_13 = V_14 + 1 ;
int V_15 = 0 ;
V_16 . V_13 = V_13 ;
V_13 += V_17 ;
V_7 = F_16 ( 7 ) ;
F_7 ( V_7 , L_4 ) ;
F_17 ( V_7 , F_18 ( 0xf ) ) ;
F_19 ( V_7 , V_18 ) ;
V_7 = F_21 ( 3 ) ;
F_7 ( V_7 , L_5 ) ;
F_17 ( V_7 , F_18 ( 0xf ) ) ;
F_19 ( V_7 , V_18 ) ;
V_7 = V_19 . V_20 ;
F_7 ( V_7 , L_6 ) ;
F_17 ( V_7 , F_18 ( 0xf ) ) ;
F_19 ( V_7 , V_18 ) ;
V_15 = F_22 ( V_7 ) ? 0 : 1 ;
V_7 = V_19 . V_21 ;
F_7 ( V_7 , L_7 ) ;
F_23 ( V_7 ) ;
V_7 = V_19 . V_22 ;
F_7 ( V_7 , L_8 ) ;
F_8 ( V_7 , V_15 ) ;
}
static void T_1 F_24 ( void )
{
struct V_23 * V_24 = & V_25 ;
F_25 ( V_24 ) ;
}
static void F_26 ( void )
{
F_27 ( & V_26 , sizeof( V_26 ) ,
& V_27 ) ;
F_27 ( & V_28 , sizeof( V_28 ) ,
& V_29 ) ;
if ( F_28 ( V_30 ,
F_29 ( V_30 ) ) ) {
F_30 ( L_9 , V_31 ) ;
return;
}
V_32 . V_33 = F_31 ( V_34 ) ;
if ( ! F_32 ( V_32 . V_33 ) )
F_17 ( V_34 , F_18 ( 0xF ) ) ;
else
F_30 ( L_10 , V_31 ) ;
F_9 ( V_35 ) ;
if ( F_33 ( V_36 ) ) {
F_30 ( L_11 , V_31 ) ;
return;
}
F_34 ( F_35 ( 3 ) , V_37 ) ;
}
static void T_1 F_36 ( void )
{
F_37 ( NULL , 0 , V_38 ) ;
F_38 ( 24000000 ) ;
F_39 ( V_39 , F_29 ( V_39 ) ) ;
}
static void T_1 F_40 ( void )
{
F_41 ( 0x43000000 , 8 << 20 , 0x51000000 , 8 << 20 ) ;
}
static void T_1 F_42 ( void )
{
F_1 () ;
F_15 () ;
F_20 () ;
F_43 ( & V_40 ) ;
F_44 ( 1 , V_41 , F_29 ( V_41 ) ) ;
F_45 ( & V_42 ) ;
F_44 ( 3 , V_43 , F_29 ( V_43 ) ) ;
F_46 ( NULL ) ;
V_44 [ V_45 ] . V_33 = F_47 ( F_16 ( 7 ) ) ;
F_44 ( 5 , V_44 , F_29 ( V_44 ) ) ;
V_46 [ V_47 ] . V_33 = F_47 ( F_21 ( 3 ) ) ;
F_44 ( 9 , V_46 , F_29 ( V_46 ) ) ;
F_48 ( & V_48 ) ;
F_26 () ;
F_24 () ;
V_49 . V_50 = 24000000 ;
F_49 ( V_51 , F_29 ( V_51 ) ) ;
V_52 . V_9 . V_53 = & V_54 [ V_55 ] . V_9 ;
V_56 . V_9 . V_53 = & V_54 [ V_57 ] . V_9 ;
V_58 . V_9 . V_53 = & V_54 [ V_59 ] . V_9 ;
V_60 . V_9 . V_53 = & V_54 [ V_59 ] . V_9 ;
V_61 . V_9 . V_53 = & V_54 [ V_59 ] . V_9 ;
V_62 . V_9 . V_53 = & V_54 [ V_59 ] . V_9 ;
V_27 . V_9 . V_53 = & V_54 [ V_59 ] . V_9 ;
}

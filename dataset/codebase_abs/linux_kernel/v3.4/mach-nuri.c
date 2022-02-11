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
return F_11 ( F_12 ( 3 ) , V_10 ,
L_2 ) ;
}
static int F_13 ( struct V_8 * V_9 , int V_11 )
{
if ( V_11 < 1 )
V_11 = 0 ;
F_14 ( F_12 ( 3 ) , 1 ) ;
return V_11 ;
}
static void F_15 ( struct V_8 * V_9 )
{
F_9 ( F_12 ( 3 ) ) ;
}
static void T_1 F_16 ( void )
{
int V_7 ;
V_7 = F_17 ( 4 ) ;
F_7 ( V_7 , L_3 ) ;
F_18 ( V_7 , F_19 ( 0xf ) ) ;
F_20 ( V_7 , V_12 ) ;
}
static void T_1 F_21 ( void )
{
int V_7 ;
int V_13 = V_14 + 1 ;
int V_15 = 0 ;
V_16 . V_13 = V_13 ;
V_13 += V_17 ;
V_7 = F_17 ( 7 ) ;
F_7 ( V_7 , L_4 ) ;
F_18 ( V_7 , F_19 ( 0xf ) ) ;
F_20 ( V_7 , V_18 ) ;
V_7 = F_22 ( 3 ) ;
F_7 ( V_7 , L_5 ) ;
F_18 ( V_7 , F_19 ( 0xf ) ) ;
F_20 ( V_7 , V_18 ) ;
V_7 = V_19 . V_20 ;
F_7 ( V_7 , L_6 ) ;
F_18 ( V_7 , F_19 ( 0xf ) ) ;
F_20 ( V_7 , V_18 ) ;
V_15 = F_23 ( V_7 ) ? 0 : 1 ;
V_7 = V_19 . V_21 ;
F_7 ( V_7 , L_7 ) ;
F_24 ( V_7 ) ;
V_7 = V_19 . V_22 ;
F_7 ( V_7 , L_8 ) ;
F_8 ( V_7 , V_15 ) ;
}
static void T_1 F_25 ( void )
{
struct V_23 * V_24 = & V_25 ;
F_26 ( V_24 ) ;
}
static void T_1 F_27 ( void )
{
F_28 ( & V_26 , sizeof( V_26 ) ,
& V_27 ) ;
F_28 ( & V_28 , sizeof( V_28 ) ,
& V_29 ) ;
if ( F_29 ( V_30 ,
F_30 ( V_30 ) ) ) {
F_31 ( L_9 , V_31 ) ;
return;
}
V_32 . V_33 = F_32 ( V_34 ) ;
if ( ! F_33 ( V_32 . V_33 ) )
F_18 ( V_34 , F_19 ( 0xF ) ) ;
else
F_31 ( L_10 , V_31 ) ;
F_9 ( V_35 ) ;
F_9 ( V_36 ) ;
F_9 ( V_37 ) ;
if ( F_34 ( V_38 ) ) {
F_31 ( L_11 , V_31 ) ;
return;
}
F_35 ( F_36 ( 3 ) , V_39 ) ;
}
static void T_1 F_37 ( void )
{
V_40 . V_41 = 24000000 ;
F_38 ( NULL , 0 ) ;
F_39 ( 24000000 ) ;
F_40 ( V_42 , F_30 ( V_42 ) ) ;
}
static void T_1 F_41 ( void )
{
F_42 ( 0x43000000 , 8 << 20 , 0x51000000 , 8 << 20 ) ;
}
static void T_1 F_43 ( void )
{
F_1 () ;
F_16 () ;
F_21 () ;
F_44 ( & V_43 ) ;
F_45 ( 1 , V_44 , F_30 ( V_44 ) ) ;
F_46 ( & V_45 ) ;
F_45 ( 3 , V_46 , F_30 ( V_46 ) ) ;
F_47 ( NULL ) ;
V_47 [ V_48 ] . V_33 = F_48 ( F_17 ( 7 ) ) ;
F_45 ( 5 , V_47 , F_30 ( V_47 ) ) ;
V_49 [ V_50 ] . V_33 = F_48 ( F_22 ( 3 ) ) ;
F_45 ( 9 , V_49 , F_30 ( V_49 ) ) ;
F_49 ( & V_51 ) ;
F_50 ( & V_52 ) ;
F_27 () ;
F_25 () ;
F_51 ( V_53 , F_30 ( V_53 ) ) ;
}

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
static void T_1 F_26 ( void )
{
F_27 ( NULL , 0 , V_26 ) ;
F_28 ( 24000000 ) ;
F_29 ( V_27 , F_30 ( V_27 ) ) ;
}
static void T_1 F_31 ( void )
{
F_32 ( 0x43000000 , 8 << 20 , 0x51000000 , 8 << 20 ) ;
}
static void T_1 F_33 ( void )
{
F_1 () ;
F_15 () ;
F_20 () ;
F_34 ( 1 , V_28 , F_30 ( V_28 ) ) ;
F_35 ( & V_29 ) ;
F_34 ( 3 , V_30 , F_30 ( V_30 ) ) ;
F_36 ( NULL ) ;
V_31 [ V_32 ] . V_33 = F_37 ( F_16 ( 7 ) ) ;
F_34 ( 5 , V_31 , F_30 ( V_31 ) ) ;
V_34 [ V_35 ] . V_33 = F_37 ( F_21 ( 3 ) ) ;
F_34 ( 9 , V_34 , F_30 ( V_34 ) ) ;
F_24 () ;
V_36 . V_37 = 24000000 ;
F_38 ( V_38 , F_30 ( V_38 ) ) ;
V_39 . V_9 . V_40 = & V_41 [ V_42 ] . V_9 ;
}

static int F_1 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_4 , L_1 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_3 ( V_4 , 1 ) ;
if ( ! V_3 )
return 0 ;
F_4 ( V_4 ) ;
return V_3 ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_4 ( V_4 ) ;
}
static int F_6 ( struct V_1 * V_2 , unsigned int V_5 )
{
F_7 ( V_4 , ! V_5 ) ;
return 0 ;
}
static void F_8 ( struct V_6 * V_7 , T_1 V_8 )
{
if ( V_8 & V_9 )
F_9 ( & V_10 . V_2 , V_11 , 0 ) ;
else
F_9 ( & V_10 . V_2 , V_11 , 1 ) ;
if ( V_8 & V_12 )
F_9 ( & V_10 . V_2 , V_13 , 0 ) ;
else
F_9 ( & V_10 . V_2 , V_13 , 1 ) ;
}
static T_1 F_10 ( struct V_6 * V_7 )
{
int V_14 = V_15 ;
unsigned int V_16 ;
V_16 = F_11 ( & V_10 . V_2 , V_17 & V_18 ) ;
if ( V_16 == - V_19 )
return V_14 ;
if ( V_16 & V_17 )
V_14 |= V_20 ;
if ( V_16 & V_18 )
V_14 |= V_21 ;
return V_14 ;
}
static int F_12 ( struct V_22 * V_2 )
{
return 0 ;
}
static int F_13 ( struct V_22 * V_2 )
{
return 0 ;
}
static int T_2 F_14 ( void )
{
return F_15 ( & V_23 ) ;
}
static int F_16 ( void )
{
int V_3 = F_2 ( V_24 , L_2 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_3 ( V_24 , 1 ) ;
if ( V_3 )
F_4 ( V_24 ) ;
return V_3 ;
}
static void F_17 ( int V_25 )
{
F_7 ( V_24 , V_25 ) ;
}
static void F_18 ( void )
{
F_4 ( V_24 ) ;
}
static void T_2 F_19 ( void )
{
int V_14 = 0 ;
V_26 = V_27 | V_28 | V_29 | V_30 |
V_31 | V_32 ;
V_33 = V_34 | V_35 | V_36 | V_37 | V_38 |
V_39 | V_40 | V_41 | V_27 |
V_28 | V_29 | V_42 |
V_43 | V_44 |
V_45 | V_32 ;
V_46 = V_47 | V_48 | V_49 | V_50 | V_51 | V_52 |
V_53 | V_54 | V_55 | V_56 | V_57 | V_58 |
V_59 | V_60 | V_61 | V_62 | V_63 | V_64 ;
V_65 = 0 ;
V_66 = V_45 ;
V_67 = V_68 | V_69 | V_70 | V_71 ;
V_72 = V_73 ;
V_74 |= V_43 ;
F_20 () ;
V_75 = & V_76 ;
V_14 = F_21 ( V_77 , F_22 ( V_77 ) ) ;
if ( V_14 ) {
F_23 ( V_78 L_3 ) ;
}
F_24 ( & V_79 ) ;
F_25 ( & V_80 , V_81 ,
F_22 ( V_81 ) ) ;
F_26 ( & V_82 ) ;
F_27 ( & V_83 ) ;
F_28 () ;
}
static void T_2 F_29 ( void )
{
F_30 () ;
F_31 ( V_84 , F_22 ( V_84 ) ) ;
#ifdef F_32
F_33 ( & V_85 ) ;
#endif
F_34 ( 0 , 3 ) ;
F_34 ( 1 , 1 ) ;
}

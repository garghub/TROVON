static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
T_1 V_5 , T_1 V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static int F_5 ( struct V_6 * V_7 )
{
return 0 ;
}
static int F_6 ( struct V_6 * V_7 )
{
return 0 ;
}
static int F_7 ( struct V_6 * V_7 ,
T_2 * V_8 )
{
struct V_1 * V_2 ;
unsigned long V_9 ;
T_1 V_5 ;
V_2 = V_7 -> V_10 ;
F_8 ( & V_2 -> V_11 , V_9 ) ;
V_5 = F_1 ( V_2 , V_12 ) ;
if ( V_8 -> V_9 & V_13 )
V_5 |= V_14 ;
else
V_5 &= ~ V_14 ;
if ( V_2 -> V_15 && ( V_2 -> V_16 & V_17 ) )
V_5 ^= V_14 ;
F_3 ( V_2 , V_5 , V_12 ) ;
V_2 -> V_18 = * V_8 ;
F_9 ( & V_2 -> V_11 , V_9 ) ;
return 0 ;
}
static unsigned int F_10 ( struct V_1 * V_2 )
{
unsigned int V_19 ;
T_1 V_5 ;
V_19 = 0 ;
V_5 = F_1 ( V_2 , V_12 ) ;
if ( ! ( V_5 & V_20 ) && ! ( V_5 & V_21 ) )
V_19 |= V_22 ;
if ( ( V_19 & V_22 ) && ! V_2 -> V_15 ) {
unsigned int V_19 = 0 ;
V_5 |= V_23 ;
V_5 |= V_24 ;
F_3 ( V_2 , V_5 , V_12 ) ;
F_11 ( 10 ) ;
V_5 = F_1 ( V_2 , V_12 ) ;
V_19 |= ( V_5 & V_25 ) ? V_26 : 0 ;
V_19 |= ( V_5 & V_27 ) ? V_28 : 0 ;
V_5 &= ~ V_23 ;
V_5 |= V_24 ;
F_3 ( V_2 , V_5 , V_12 ) ;
F_11 ( 10 ) ;
V_5 = F_1 ( V_2 , V_12 ) ;
V_19 |= ( V_5 & V_20 ) ? V_29 : 0 ;
V_19 |= ( V_5 & V_21 ) ? V_30 : 0 ;
V_5 |= V_23 ;
V_5 &= ~ V_24 ;
F_3 ( V_2 , V_5 , V_12 ) ;
F_11 ( 10 ) ;
V_5 = F_1 ( V_2 , V_12 ) ;
V_19 |= ( V_5 & V_20 ) ? V_31 : 0 ;
V_19 |= ( V_5 & V_21 ) ? V_32 : 0 ;
V_2 -> V_16 = V_33 [ V_19 ] ;
if ( ! V_2 -> V_16 )
F_12 ( & V_2 -> V_34 . V_35 , L_1 ) ;
V_5 &= ~ ( V_23 | V_24 ) ;
V_5 &= ~ ( V_36 | V_37 ) ;
if ( V_2 -> V_16 & V_38 )
V_5 |= V_36 ;
else
V_5 |= V_37 ;
F_3 ( V_2 , V_5 , V_12 ) ;
}
V_2 -> V_15 = ( V_19 & V_22 ) ? 1 : 0 ;
if ( V_2 -> V_16 & V_17 )
V_19 |= V_39 ;
if ( V_2 -> V_16 & V_40 )
V_19 |= V_41 ;
if ( V_2 -> V_16 & V_42 )
V_19 |= V_43 ;
V_19 |= V_44 ;
if ( F_13 ( V_2 -> V_45 -> V_46 ) )
V_19 |= V_47 ;
return V_19 ;
}
static int F_14 ( struct V_6 * V_7 ,
unsigned int * V_48 )
{
struct V_1 * V_2 ;
V_2 = V_7 -> V_10 ;
F_15 ( & V_2 -> V_11 ) ;
* V_48 = F_10 ( V_2 ) ;
F_16 ( & V_2 -> V_11 ) ;
return 0 ;
}
static void F_17 ( unsigned long V_49 )
{
struct V_1 * V_2 ;
unsigned int V_19 , V_50 ;
V_2 = (struct V_1 * ) V_49 ;
F_15 ( & V_2 -> V_11 ) ;
V_19 = F_10 ( V_2 ) ;
V_50 = ( V_19 ^ V_2 -> V_51 ) & V_2 -> V_18 . V_52 ;
V_2 -> V_51 = V_19 ;
F_16 ( & V_2 -> V_11 ) ;
if ( V_50 )
F_18 ( & V_2 -> V_34 , V_50 ) ;
F_19 ( & V_2 -> V_53 ,
V_54 + F_20 ( V_55 ) ) ;
}
static int F_21 ( struct V_6 * V_7 ,
struct V_56 * V_57 )
{
return 0 ;
}
static int F_22 ( struct V_6 * V_7 ,
struct V_58 * V_57 )
{
struct V_1 * V_2 ;
struct V_59 * V_60 ;
V_2 = V_7 -> V_10 ;
if ( V_57 -> V_9 & V_61 )
V_60 = V_2 -> V_62 ;
else
V_60 = V_2 -> V_63 ;
V_57 -> V_64 = V_60 -> V_65 + V_57 -> V_66 ;
return 0 ;
}
static int T_3 F_23 ( struct V_67 * V_68 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
struct V_59 * V_60 , * V_69 ;
unsigned int V_70 = 0 , V_71 = 0 ;
T_1 V_5 ;
int V_72 ;
V_2 = F_24 ( sizeof( * V_2 ) , V_73 ) ;
if ( ! V_2 )
return - V_74 ;
F_25 ( & V_2 -> V_11 ) ;
V_7 = & V_2 -> V_34 ;
V_7 -> V_10 = V_2 ;
V_2 -> V_63 = F_26 ( V_68 , V_75 , 1 ) ;
V_2 -> V_62 = F_26 ( V_68 , V_75 , 2 ) ;
V_69 = F_26 ( V_68 , V_76 , 0 ) ;
V_2 -> V_45 = V_68 -> V_35 . V_77 ;
if ( ! V_2 -> V_63 || ! V_2 -> V_62 || ! V_69 || ! V_2 -> V_45 ) {
V_72 = - V_78 ;
goto V_79;
}
V_60 = F_26 ( V_68 , V_75 , 0 ) ;
V_70 = F_27 ( V_60 ) ;
if ( ! F_28 ( V_60 -> V_65 , V_70 , L_2 ) ) {
V_72 = - V_78 ;
goto V_79;
}
V_2 -> V_80 = V_60 ;
V_2 -> V_4 = F_29 ( V_60 -> V_65 , V_70 ) ;
if ( ! V_2 -> V_4 ) {
V_72 = - V_74 ;
goto V_79;
}
V_60 = F_26 ( V_68 , V_75 , 3 ) ;
V_71 = F_27 ( V_60 ) ;
V_2 -> V_81 = F_29 ( V_60 -> V_65 , V_71 ) ;
if ( ! V_2 -> V_81 ) {
V_72 = - V_74 ;
goto V_79;
}
V_7 -> V_82 = & V_83 ;
V_7 -> V_84 = & V_85 ;
V_7 -> V_86 = V_87 ;
V_7 -> V_35 . V_88 = & V_68 -> V_35 ;
V_7 -> V_89 = V_90 | V_91 ;
V_7 -> V_92 = ( unsigned long ) V_2 -> V_81 ;
V_7 -> V_93 = V_69 -> V_65 ;
#ifdef F_30
V_7 -> V_94 = V_95 ;
if ( V_95 )
V_7 -> V_89 |= V_96 ;
#endif
V_7 -> V_97 = F_27 ( V_2 -> V_63 ) ;
F_31 ( & V_2 -> V_53 , F_17 , ( unsigned long ) V_2 ) ;
V_5 = F_1 ( V_2 , V_12 ) ;
V_5 &= V_98 ;
V_5 |= V_99 ;
F_3 ( V_2 , V_5 , V_12 ) ;
V_5 = V_100 ;
V_5 |= 10 << V_101 ;
V_5 |= 6 << V_102 ;
V_5 |= 3 << V_103 ;
V_5 |= 3 << V_104 ;
F_3 ( V_2 , V_5 , V_105 ) ;
V_72 = F_32 ( V_7 ) ;
if ( V_72 )
goto V_79;
F_19 ( & V_2 -> V_53 ,
V_54 + F_20 ( V_55 ) ) ;
F_33 ( V_68 , V_2 ) ;
return 0 ;
V_79:
if ( V_2 -> V_81 )
F_34 ( V_2 -> V_81 ) ;
if ( V_2 -> V_4 )
F_34 ( V_2 -> V_4 ) ;
if ( V_2 -> V_80 )
F_35 ( V_2 -> V_80 -> V_65 , V_70 ) ;
F_36 ( V_2 ) ;
return V_72 ;
}
static int T_4 F_37 ( struct V_67 * V_68 )
{
struct V_1 * V_2 ;
struct V_59 * V_60 ;
V_2 = F_38 ( V_68 ) ;
F_39 ( & V_2 -> V_53 ) ;
F_34 ( V_2 -> V_4 ) ;
F_34 ( V_2 -> V_81 ) ;
V_60 = V_2 -> V_80 ;
F_35 ( V_60 -> V_65 , F_27 ( V_60 ) ) ;
F_36 ( V_2 ) ;
return 0 ;
}
static int T_3 F_40 ( struct V_106 * V_35 ,
const struct V_107 * V_108 )
{
V_95 = V_35 ;
return F_41 ( & V_109 ) ;
}
static void T_4 F_42 ( struct V_106 * V_35 )
{
F_43 ( & V_109 ) ;
V_95 = NULL ;
}
static int T_5 F_44 ( void )
{
#ifdef F_30
return F_45 ( & V_110 ) ;
#else
return F_41 ( & V_109 ) ;
#endif
}
static void T_6 F_46 ( void )
{
#ifdef F_30
return F_47 ( & V_110 ) ;
#else
F_43 ( & V_109 ) ;
#endif
}

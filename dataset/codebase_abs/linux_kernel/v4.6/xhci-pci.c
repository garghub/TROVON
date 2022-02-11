static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( ! F_2 ( V_4 ) )
F_3 ( V_2 , L_1 ) ;
F_3 ( V_2 , L_2 ) ;
return 0 ;
}
static void F_4 ( struct V_5 * V_6 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_5 ( V_6 ) ;
if ( V_4 -> V_7 == V_8 &&
( V_4 -> V_5 == V_9 ||
V_4 -> V_5 == V_10 ) ) {
if ( V_4 -> V_5 == V_9 &&
V_4 -> V_11 == 0x0 ) {
V_2 -> V_12 |= V_13 ;
F_6 ( V_2 , V_14 ,
L_3
L_4 ) ;
}
if ( V_4 -> V_5 == V_9 &&
V_4 -> V_11 == 0x4 ) {
V_2 -> V_12 |= V_15 ;
F_6 ( V_2 , V_14 ,
L_5
L_6 ,
V_4 -> V_11 ) ;
}
if ( V_4 -> V_5 == V_9 )
V_2 -> V_12 |= V_16 ;
V_2 -> V_12 |= V_17 ;
F_6 ( V_2 , V_14 ,
L_7
L_8 ,
V_4 -> V_11 ) ;
V_2 -> V_12 |= V_18 ;
}
if ( V_4 -> V_7 == V_19 )
V_2 -> V_12 |= V_20 ;
if ( V_4 -> V_7 == V_21 && V_2 -> V_22 == 0x96 )
V_2 -> V_12 |= V_23 ;
if ( V_4 -> V_7 == V_21 && F_7 () )
V_2 -> V_12 |= V_24 ;
if ( V_4 -> V_7 == V_21 )
V_2 -> V_12 |= V_18 ;
if ( V_4 -> V_7 == V_25 ) {
V_2 -> V_12 |= V_26 ;
V_2 -> V_12 |= V_27 ;
V_2 -> V_12 |= V_28 ;
}
if ( V_4 -> V_7 == V_25 &&
V_4 -> V_5 == V_29 ) {
V_2 -> V_12 |= V_30 ;
V_2 -> V_31 = 64 ;
V_2 -> V_12 |= V_32 ;
V_2 -> V_12 |= V_33 ;
}
if ( V_4 -> V_7 == V_25 &&
V_4 -> V_5 == V_34 ) {
V_2 -> V_12 |= V_33 ;
V_2 -> V_12 |= V_35 ;
}
if ( V_4 -> V_7 == V_25 &&
( V_4 -> V_5 == V_36 ||
V_4 -> V_5 == V_37 ||
V_4 -> V_5 == V_38 ||
V_4 -> V_5 == V_39 ||
V_4 -> V_5 == V_40 ) ) {
V_2 -> V_12 |= V_41 ;
}
if ( V_4 -> V_7 == V_25 &&
V_4 -> V_5 == V_38 ) {
V_2 -> V_12 |= V_42 ;
}
if ( V_4 -> V_7 == V_43 &&
V_4 -> V_5 == V_44 ) {
V_2 -> V_12 |= V_45 ;
V_2 -> V_12 |= V_18 ;
V_2 -> V_12 |= V_16 ;
}
if ( V_4 -> V_7 == V_46 &&
V_4 -> V_5 == 0x0015 )
V_2 -> V_12 |= V_45 ;
if ( V_4 -> V_7 == V_47 )
V_2 -> V_12 |= V_45 ;
if ( V_4 -> V_7 == V_47 &&
V_4 -> V_5 == 0x3432 )
V_2 -> V_12 |= V_16 ;
if ( V_4 -> V_7 == V_48 &&
V_4 -> V_5 == 0x1042 )
V_2 -> V_12 |= V_16 ;
if ( V_2 -> V_12 & V_45 )
F_6 ( V_2 , V_14 ,
L_9 ) ;
}
static void F_8 ( struct V_3 * V_6 )
{
static const T_1 V_49 [] = {
0xb7 , 0x0c , 0x34 , 0xac , 0x01 , 0xe9 , 0xbf , 0x45 ,
0xb7 , 0xe6 , 0x2b , 0x34 , 0xec , 0x93 , 0x1e , 0x23 ,
} ;
union V_50 * V_51 ;
V_51 = F_9 ( F_10 ( & V_6 -> V_6 ) , V_49 , 3 , 1 ,
NULL ) ;
F_11 ( V_51 ) ;
}
static void F_8 ( struct V_3 * V_6 ) { }
static int F_12 ( struct V_52 * V_53 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = F_5 ( V_53 -> V_54 . V_55 ) ;
int V_56 ;
V_2 = F_13 ( V_53 ) ;
if ( ! V_2 -> V_57 )
F_14 ( V_4 , V_58 , & V_2 -> V_57 ) ;
V_56 = F_15 ( V_53 , F_4 ) ;
if ( V_56 )
return V_56 ;
if ( ! F_16 ( V_53 ) )
return 0 ;
F_3 ( V_2 , L_10 , ( unsigned int ) V_2 -> V_57 ) ;
V_56 = F_1 ( V_2 , V_4 ) ;
if ( ! V_56 )
return V_56 ;
return V_56 ;
}
static int F_17 ( struct V_3 * V_6 , const struct V_59 * V_60 )
{
int V_56 ;
struct V_1 * V_2 ;
struct V_61 * V_62 ;
struct V_52 * V_53 ;
V_62 = (struct V_61 * ) V_60 -> V_63 ;
F_18 ( & V_6 -> V_6 ) ;
V_56 = F_19 ( V_6 , V_60 ) ;
if ( V_56 )
goto V_64;
V_53 = F_20 ( & V_6 -> V_6 ) ;
V_2 = F_13 ( V_53 ) ;
V_2 -> V_65 = F_21 ( V_62 , & V_6 -> V_6 ,
F_22 ( V_6 ) , V_53 ) ;
if ( ! V_2 -> V_65 ) {
V_56 = - V_66 ;
goto V_67;
}
V_56 = F_23 ( V_2 -> V_65 , V_6 -> V_68 ,
V_69 ) ;
if ( V_56 )
goto V_70;
if ( ! ( V_2 -> V_12 & V_16 ) &&
F_24 ( V_2 -> V_71 ) >= 4 )
V_2 -> V_65 -> V_72 = 1 ;
if ( V_2 -> V_12 & V_41 )
F_8 ( V_6 ) ;
F_25 ( & V_6 -> V_6 ) ;
return 0 ;
V_70:
F_26 ( V_2 -> V_65 ) ;
V_67:
F_27 ( V_6 ) ;
V_64:
F_25 ( & V_6 -> V_6 ) ;
return V_56 ;
}
static void F_28 ( struct V_3 * V_6 )
{
struct V_1 * V_2 ;
V_2 = F_13 ( F_29 ( V_6 ) ) ;
V_2 -> V_73 |= V_74 ;
if ( V_2 -> V_65 ) {
F_30 ( V_2 -> V_65 ) ;
F_26 ( V_2 -> V_65 ) ;
}
F_27 ( V_6 ) ;
if ( V_2 -> V_12 & V_35 )
F_31 ( V_6 , V_75 ) ;
}
static void F_32 ( struct V_52 * V_53 , bool V_76 )
{
struct V_1 * V_2 = F_13 ( V_53 ) ;
T_2 V_77 ;
void T_3 * V_78 ;
int V_79 ;
for ( V_79 = 0 ; V_79 < V_80 ; V_79 ++ ) {
V_78 = ( void T_3 * ) V_2 -> V_81 +
V_82 +
V_79 * V_83 ;
V_77 = F_33 ( V_78 ) & ~ V_84 ;
F_34 ( V_77 , V_78 ) ;
V_77 = F_33 ( V_78 ) ;
if ( V_76 )
V_77 |= V_85 ;
else
V_77 &= ~ V_85 ;
F_34 ( V_77 , V_78 ) ;
V_77 = F_33 ( V_78 ) | V_84 ;
F_34 ( V_77 , V_78 ) ;
F_33 ( V_78 ) ;
}
}
static void F_35 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = F_13 ( V_53 ) ;
void T_3 * V_78 ;
T_2 V_77 ;
V_78 = ( void T_3 * ) V_2 -> V_81 + 0x80a4 ;
V_77 = F_33 ( V_78 ) ;
F_34 ( V_77 | F_36 ( 28 ) , V_78 ) ;
F_33 ( V_78 ) ;
}
static int F_37 ( struct V_52 * V_53 , bool V_86 )
{
struct V_1 * V_2 = F_13 ( V_53 ) ;
struct V_3 * V_4 = F_5 ( V_53 -> V_54 . V_55 ) ;
int V_87 ;
if ( V_2 -> V_12 & V_88 )
V_4 -> V_89 = true ;
if ( V_2 -> V_12 & V_41 )
F_35 ( V_53 ) ;
if ( V_2 -> V_12 & V_42 )
F_32 ( V_53 , true ) ;
V_87 = F_38 ( V_2 , V_86 ) ;
if ( V_87 && ( V_2 -> V_12 & V_42 ) )
F_32 ( V_53 , false ) ;
return V_87 ;
}
static int F_39 ( struct V_52 * V_53 , bool V_90 )
{
struct V_1 * V_2 = F_13 ( V_53 ) ;
struct V_3 * V_4 = F_5 ( V_53 -> V_54 . V_55 ) ;
int V_56 = 0 ;
if ( V_4 -> V_7 == V_25 )
F_40 ( V_4 ) ;
if ( V_2 -> V_12 & V_42 )
F_32 ( V_53 , false ) ;
if ( V_2 -> V_12 & V_41 )
F_35 ( V_53 ) ;
V_56 = F_41 ( V_2 , V_90 ) ;
return V_56 ;
}
static int T_4 F_42 ( void )
{
F_43 ( & V_91 , & V_92 ) ;
#ifdef F_44
V_91 . V_93 = F_37 ;
V_91 . V_94 = F_39 ;
#endif
return F_45 ( & V_95 ) ;
}
static void T_5 F_46 ( void )
{
F_47 ( & V_95 ) ;
}

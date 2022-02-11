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
V_4 -> V_5 == V_39 ) ) {
V_2 -> V_12 |= V_40 ;
}
if ( V_4 -> V_7 == V_25 &&
V_4 -> V_5 == V_38 ) {
V_2 -> V_12 |= V_41 ;
}
if ( V_4 -> V_7 == V_42 &&
V_4 -> V_5 == V_43 ) {
V_2 -> V_12 |= V_44 ;
V_2 -> V_12 |= V_18 ;
V_2 -> V_12 |= V_16 ;
}
if ( V_4 -> V_7 == V_45 &&
V_4 -> V_5 == 0x0015 )
V_2 -> V_12 |= V_44 ;
if ( V_4 -> V_7 == V_46 )
V_2 -> V_12 |= V_44 ;
if ( V_4 -> V_7 == V_46 &&
V_4 -> V_5 == 0x3432 )
V_2 -> V_12 |= V_16 ;
if ( V_4 -> V_7 == V_47 &&
V_4 -> V_5 == 0x1042 )
V_2 -> V_12 |= V_16 ;
if ( V_2 -> V_12 & V_44 )
F_6 ( V_2 , V_14 ,
L_9 ) ;
}
static void F_8 ( struct V_3 * V_6 )
{
static const T_1 V_48 [] = {
0xb7 , 0x0c , 0x34 , 0xac , 0x01 , 0xe9 , 0xbf , 0x45 ,
0xb7 , 0xe6 , 0x2b , 0x34 , 0xec , 0x93 , 0x1e , 0x23 ,
} ;
union V_49 * V_50 ;
V_50 = F_9 ( F_10 ( & V_6 -> V_6 ) , V_48 , 3 , 1 ,
NULL ) ;
F_11 ( V_50 ) ;
}
static void F_8 ( struct V_3 * V_6 ) { }
static int F_12 ( struct V_51 * V_52 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = F_5 ( V_52 -> V_53 . V_54 ) ;
int V_55 ;
V_2 = F_13 ( V_52 ) ;
if ( ! V_2 -> V_56 )
F_14 ( V_4 , V_57 , & V_2 -> V_56 ) ;
V_55 = F_15 ( V_52 , F_4 ) ;
if ( V_55 )
return V_55 ;
if ( ! F_16 ( V_52 ) )
return 0 ;
F_3 ( V_2 , L_10 , ( unsigned int ) V_2 -> V_56 ) ;
V_55 = F_1 ( V_2 , V_4 ) ;
if ( ! V_55 )
return V_55 ;
return V_55 ;
}
static int F_17 ( struct V_3 * V_6 , const struct V_58 * V_59 )
{
int V_55 ;
struct V_1 * V_2 ;
struct V_60 * V_61 ;
struct V_51 * V_52 ;
V_61 = (struct V_60 * ) V_59 -> V_62 ;
F_18 ( & V_6 -> V_6 ) ;
V_55 = F_19 ( V_6 , V_59 ) ;
if ( V_55 )
goto V_63;
V_52 = F_20 ( & V_6 -> V_6 ) ;
V_2 = F_13 ( V_52 ) ;
V_2 -> V_64 = F_21 ( V_61 , & V_6 -> V_6 ,
F_22 ( V_6 ) , V_52 ) ;
if ( ! V_2 -> V_64 ) {
V_55 = - V_65 ;
goto V_66;
}
V_55 = F_23 ( V_2 -> V_64 , V_6 -> V_67 ,
V_68 ) ;
if ( V_55 )
goto V_69;
if ( ! ( V_2 -> V_12 & V_16 ) &&
F_24 ( V_2 -> V_70 ) >= 4 )
V_2 -> V_64 -> V_71 = 1 ;
if ( V_2 -> V_12 & V_40 )
F_8 ( V_6 ) ;
F_25 ( & V_6 -> V_6 ) ;
return 0 ;
V_69:
F_26 ( V_2 -> V_64 ) ;
V_66:
F_27 ( V_6 ) ;
V_63:
F_25 ( & V_6 -> V_6 ) ;
return V_55 ;
}
static void F_28 ( struct V_3 * V_6 )
{
struct V_1 * V_2 ;
V_2 = F_13 ( F_29 ( V_6 ) ) ;
if ( V_2 -> V_64 ) {
F_30 ( V_2 -> V_64 ) ;
F_26 ( V_2 -> V_64 ) ;
}
F_27 ( V_6 ) ;
if ( V_2 -> V_12 & V_35 )
F_31 ( V_6 , V_72 ) ;
}
static void F_32 ( struct V_51 * V_52 , bool V_73 )
{
struct V_1 * V_2 = F_13 ( V_52 ) ;
T_2 V_74 ;
void T_3 * V_75 ;
int V_76 ;
for ( V_76 = 0 ; V_76 < V_77 ; V_76 ++ ) {
V_75 = ( void T_3 * ) V_2 -> V_78 +
V_79 +
V_76 * V_80 ;
V_74 = F_33 ( V_75 ) & ~ V_81 ;
F_34 ( V_74 , V_75 ) ;
V_74 = F_33 ( V_75 ) ;
if ( V_73 )
V_74 |= V_82 ;
else
V_74 &= ~ V_82 ;
F_34 ( V_74 , V_75 ) ;
V_74 = F_33 ( V_75 ) | V_81 ;
F_34 ( V_74 , V_75 ) ;
F_33 ( V_75 ) ;
}
}
static void F_35 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = F_13 ( V_52 ) ;
void T_3 * V_75 ;
T_2 V_74 ;
V_75 = ( void T_3 * ) V_2 -> V_78 + 0x80a4 ;
V_74 = F_33 ( V_75 ) ;
F_34 ( V_74 | F_36 ( 28 ) , V_75 ) ;
F_33 ( V_75 ) ;
}
static int F_37 ( struct V_51 * V_52 , bool V_83 )
{
struct V_1 * V_2 = F_13 ( V_52 ) ;
struct V_3 * V_4 = F_5 ( V_52 -> V_53 . V_54 ) ;
int V_84 ;
if ( V_2 -> V_12 & V_85 )
V_4 -> V_86 = true ;
if ( V_2 -> V_12 & V_40 )
F_35 ( V_52 ) ;
if ( V_2 -> V_12 & V_41 )
F_32 ( V_52 , true ) ;
V_84 = F_38 ( V_2 , V_83 ) ;
if ( V_84 && ( V_2 -> V_12 & V_41 ) )
F_32 ( V_52 , false ) ;
return V_84 ;
}
static int F_39 ( struct V_51 * V_52 , bool V_87 )
{
struct V_1 * V_2 = F_13 ( V_52 ) ;
struct V_3 * V_4 = F_5 ( V_52 -> V_53 . V_54 ) ;
int V_55 = 0 ;
if ( V_4 -> V_7 == V_25 )
F_40 ( V_4 ) ;
if ( V_2 -> V_12 & V_41 )
F_32 ( V_52 , false ) ;
if ( V_2 -> V_12 & V_40 )
F_35 ( V_52 ) ;
V_55 = F_41 ( V_2 , V_87 ) ;
return V_55 ;
}
static int T_4 F_42 ( void )
{
F_43 ( & V_88 , & V_89 ) ;
#ifdef F_44
V_88 . V_90 = F_37 ;
V_88 . V_91 = F_39 ;
#endif
return F_45 ( & V_92 ) ;
}
static void T_5 F_46 ( void )
{
F_47 ( & V_92 ) ;
}

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
V_4 -> V_5 == V_38 ) ) {
V_2 -> V_12 |= V_39 ;
}
if ( V_4 -> V_7 == V_40 &&
V_4 -> V_5 == V_41 ) {
V_2 -> V_12 |= V_42 ;
V_2 -> V_12 |= V_18 ;
V_2 -> V_12 |= V_16 ;
}
if ( V_4 -> V_7 == V_43 &&
V_4 -> V_5 == 0x0015 )
V_2 -> V_12 |= V_42 ;
if ( V_4 -> V_7 == V_44 )
V_2 -> V_12 |= V_42 ;
if ( V_4 -> V_7 == V_44 &&
V_4 -> V_5 == 0x3432 )
V_2 -> V_12 |= V_16 ;
if ( V_4 -> V_7 == V_45 &&
V_4 -> V_5 == 0x1042 )
V_2 -> V_12 |= V_16 ;
if ( V_2 -> V_12 & V_42 )
F_6 ( V_2 , V_14 ,
L_9 ) ;
}
static void F_8 ( struct V_3 * V_6 )
{
static const T_1 V_46 [] = {
0xb7 , 0x0c , 0x34 , 0xac , 0x01 , 0xe9 , 0xbf , 0x45 ,
0xb7 , 0xe6 , 0x2b , 0x34 , 0xec , 0x93 , 0x1e , 0x23 ,
} ;
union V_47 * V_48 ;
V_48 = F_9 ( F_10 ( & V_6 -> V_6 ) , V_46 , 3 , 1 ,
NULL ) ;
F_11 ( V_48 ) ;
}
static void F_8 ( struct V_3 * V_6 ) { }
static int F_12 ( struct V_49 * V_50 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = F_5 ( V_50 -> V_51 . V_52 ) ;
int V_53 ;
V_2 = F_13 ( V_50 ) ;
if ( ! V_2 -> V_54 )
F_14 ( V_4 , V_55 , & V_2 -> V_54 ) ;
V_53 = F_15 ( V_50 , F_4 ) ;
if ( V_53 )
return V_53 ;
if ( ! F_16 ( V_50 ) )
return 0 ;
F_3 ( V_2 , L_10 , ( unsigned int ) V_2 -> V_54 ) ;
V_53 = F_1 ( V_2 , V_4 ) ;
if ( ! V_53 )
return V_53 ;
return V_53 ;
}
static int F_17 ( struct V_3 * V_6 , const struct V_56 * V_57 )
{
int V_53 ;
struct V_1 * V_2 ;
struct V_58 * V_59 ;
struct V_49 * V_50 ;
V_59 = (struct V_58 * ) V_57 -> V_60 ;
F_18 ( & V_6 -> V_6 ) ;
V_53 = F_19 ( V_6 , V_57 ) ;
if ( V_53 )
goto V_61;
V_50 = F_20 ( & V_6 -> V_6 ) ;
V_2 = F_13 ( V_50 ) ;
V_2 -> V_62 = F_21 ( V_59 , & V_6 -> V_6 ,
F_22 ( V_6 ) , V_50 ) ;
if ( ! V_2 -> V_62 ) {
V_53 = - V_63 ;
goto V_64;
}
V_53 = F_23 ( V_2 -> V_62 , V_6 -> V_65 ,
V_66 ) ;
if ( V_53 )
goto V_67;
if ( ! ( V_2 -> V_12 & V_16 ) &&
F_24 ( V_2 -> V_68 ) >= 4 )
V_2 -> V_62 -> V_69 = 1 ;
if ( V_2 -> V_12 & V_39 )
F_8 ( V_6 ) ;
F_25 ( & V_6 -> V_6 ) ;
return 0 ;
V_67:
F_26 ( V_2 -> V_62 ) ;
V_64:
F_27 ( V_6 ) ;
V_61:
F_25 ( & V_6 -> V_6 ) ;
return V_53 ;
}
static void F_28 ( struct V_3 * V_6 )
{
struct V_1 * V_2 ;
V_2 = F_13 ( F_29 ( V_6 ) ) ;
if ( V_2 -> V_62 ) {
F_30 ( V_2 -> V_62 ) ;
F_26 ( V_2 -> V_62 ) ;
}
F_27 ( V_6 ) ;
if ( V_2 -> V_12 & V_35 )
F_31 ( V_6 , V_70 ) ;
}
static void F_32 ( struct V_49 * V_50 , bool V_71 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
struct V_3 * V_4 = F_5 ( V_50 -> V_51 . V_52 ) ;
T_2 V_72 ;
void T_3 * V_73 ;
if ( V_4 -> V_7 == V_25 &&
V_4 -> V_5 == V_38 ) {
V_73 = ( void T_3 * ) V_2 -> V_74 + V_75 ;
V_72 = F_33 ( V_73 ) & ~ V_76 ;
F_34 ( V_72 , V_73 ) ;
V_72 = F_33 ( V_73 ) ;
if ( V_71 )
V_72 |= V_77 ;
else
V_72 &= ~ V_77 ;
F_34 ( V_72 , V_73 ) ;
V_72 = F_33 ( V_73 ) | V_76 ;
F_34 ( V_72 , V_73 ) ;
F_33 ( V_73 ) ;
}
V_73 = ( void T_3 * ) V_2 -> V_74 + 0x80a4 ;
V_72 = F_33 ( V_73 ) ;
F_34 ( V_72 | F_35 ( 28 ) , V_73 ) ;
F_33 ( V_73 ) ;
}
static int F_36 ( struct V_49 * V_50 , bool V_78 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
struct V_3 * V_4 = F_5 ( V_50 -> V_51 . V_52 ) ;
if ( V_2 -> V_12 & V_79 )
V_4 -> V_80 = true ;
if ( V_2 -> V_12 & V_39 )
F_32 ( V_50 , true ) ;
return F_37 ( V_2 , V_78 ) ;
}
static int F_38 ( struct V_49 * V_50 , bool V_81 )
{
struct V_1 * V_2 = F_13 ( V_50 ) ;
struct V_3 * V_4 = F_5 ( V_50 -> V_51 . V_52 ) ;
int V_53 = 0 ;
if ( V_4 -> V_7 == V_25 )
F_39 ( V_4 ) ;
if ( V_2 -> V_12 & V_39 )
F_32 ( V_50 , false ) ;
V_53 = F_40 ( V_2 , V_81 ) ;
return V_53 ;
}
static int T_4 F_41 ( void )
{
F_42 ( & V_82 , & V_83 ) ;
#ifdef F_43
V_82 . V_84 = F_36 ;
V_82 . V_85 = F_38 ;
#endif
return F_44 ( & V_86 ) ;
}
static void T_5 F_45 ( void )
{
F_46 ( & V_86 ) ;
}

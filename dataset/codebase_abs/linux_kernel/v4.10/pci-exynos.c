static void F_1 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 )
{
F_2 ( V_2 , V_1 -> V_4 + V_3 ) ;
}
static T_1 F_3 ( struct V_1 * V_1 , T_1 V_3 )
{
return F_4 ( V_1 -> V_4 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 )
{
F_2 ( V_2 , V_1 -> V_5 + V_3 ) ;
}
static T_1 F_6 ( struct V_1 * V_1 , T_1 V_3 )
{
return F_4 ( V_1 -> V_5 + V_3 ) ;
}
static void F_7 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 )
{
F_2 ( V_2 , V_1 -> V_6 + V_3 ) ;
}
static T_1 F_8 ( struct V_1 * V_1 , T_1 V_3 )
{
return F_4 ( V_1 -> V_6 + V_3 ) ;
}
static void F_9 ( struct V_1 * V_1 ,
bool V_7 )
{
T_1 V_2 ;
if ( V_7 ) {
V_2 = F_3 ( V_1 , V_8 ) ;
V_2 |= V_9 ;
F_1 ( V_1 , V_2 , V_8 ) ;
} else {
V_2 = F_3 ( V_1 , V_8 ) ;
V_2 &= ~ V_9 ;
F_1 ( V_1 , V_2 , V_8 ) ;
}
}
static void F_10 ( struct V_1 * V_1 ,
bool V_7 )
{
T_1 V_2 ;
if ( V_7 ) {
V_2 = F_3 ( V_1 , V_10 ) ;
V_2 |= V_9 ;
F_1 ( V_1 , V_2 , V_10 ) ;
} else {
V_2 = F_3 ( V_1 , V_10 ) ;
V_2 &= ~ V_9 ;
F_1 ( V_1 , V_2 , V_10 ) ;
}
}
static void F_11 ( struct V_1 * V_1 )
{
T_1 V_2 ;
V_2 = F_3 ( V_1 , V_11 ) ;
V_2 &= ~ V_12 ;
F_1 ( V_1 , V_2 , V_11 ) ;
F_1 ( V_1 , 0 , V_13 ) ;
F_1 ( V_1 , 0 , V_14 ) ;
F_1 ( V_1 , 0 , V_15 ) ;
}
static void F_12 ( struct V_1 * V_1 )
{
T_1 V_2 ;
V_2 = F_3 ( V_1 , V_11 ) ;
V_2 |= V_12 ;
F_1 ( V_1 , V_2 , V_11 ) ;
F_1 ( V_1 , 1 , V_14 ) ;
F_1 ( V_1 , 1 , V_15 ) ;
F_1 ( V_1 , 1 , V_16 ) ;
F_1 ( V_1 , 0 , V_16 ) ;
F_7 ( V_1 , 1 , V_17 ) ;
}
static void F_13 ( struct V_1 * V_1 )
{
F_7 ( V_1 , 0 , V_17 ) ;
F_7 ( V_1 , 1 , V_18 ) ;
}
static void F_14 ( struct V_1 * V_1 )
{
F_7 ( V_1 , 0 , V_18 ) ;
F_1 ( V_1 , 1 , V_13 ) ;
F_7 ( V_1 , 0 , V_19 ) ;
F_7 ( V_1 , 0 , V_20 ) ;
F_7 ( V_1 , 0 , V_21 ) ;
F_7 ( V_1 , 0 , V_22 ) ;
}
static void F_15 ( struct V_1 * V_1 )
{
T_1 V_2 ;
V_2 = F_6 ( V_1 , V_23 ) ;
V_2 &= ~ V_24 ;
F_5 ( V_1 , V_2 , V_23 ) ;
V_2 = F_6 ( V_1 , V_25 ) ;
V_2 &= ~ V_26 ;
F_5 ( V_1 , V_2 , V_25 ) ;
V_2 = F_6 ( V_1 , V_27 ) ;
V_2 &= ~ V_28 ;
F_5 ( V_1 , V_2 , V_27 ) ;
V_2 = F_6 ( V_1 , V_29 ) ;
V_2 &= ~ V_30 ;
F_5 ( V_1 , V_2 , V_29 ) ;
V_2 = F_6 ( V_1 , V_31 ) ;
V_2 &= ~ V_32 ;
F_5 ( V_1 , V_2 , V_31 ) ;
}
static void F_16 ( struct V_1 * V_1 )
{
T_1 V_2 ;
V_2 = F_6 ( V_1 , V_23 ) ;
V_2 |= V_24 ;
F_5 ( V_1 , V_2 , V_23 ) ;
V_2 = F_6 ( V_1 , V_25 ) ;
V_2 |= V_26 ;
F_5 ( V_1 , V_2 , V_25 ) ;
V_2 = F_6 ( V_1 , V_27 ) ;
V_2 |= V_28 ;
F_5 ( V_1 , V_2 , V_27 ) ;
V_2 = F_6 ( V_1 , V_29 ) ;
V_2 |= V_30 ;
F_5 ( V_1 , V_2 , V_29 ) ;
V_2 = F_6 ( V_1 , V_31 ) ;
V_2 |= V_32 ;
F_5 ( V_1 , V_2 , V_31 ) ;
}
static void F_17 ( struct V_1 * V_1 )
{
F_5 ( V_1 , 0x29 , V_33 ) ;
F_5 ( V_1 , 0xd5 , V_34 ) ;
F_5 ( V_1 , 0x14 , V_35 ) ;
F_5 ( V_1 , 0x12 , V_36 ) ;
F_5 ( V_1 , 0x7f , V_37 ) ;
F_5 ( V_1 , 0x0 , V_38 ) ;
F_5 ( V_1 , 0xe7 , V_39 ) ;
F_5 ( V_1 , 0x82 , V_40 ) ;
F_5 ( V_1 , 0x82 , V_41 ) ;
F_5 ( V_1 , 0x82 , V_42 ) ;
F_5 ( V_1 , 0x82 , V_43 ) ;
F_5 ( V_1 , 0x39 , V_38 ) ;
F_5 ( V_1 , 0x39 , V_44 ) ;
F_5 ( V_1 , 0x39 , V_45 ) ;
F_5 ( V_1 , 0x39 , V_46 ) ;
F_5 ( V_1 , 0x20 , V_47 ) ;
F_5 ( V_1 , 0xa0 , V_48 ) ;
F_5 ( V_1 , 0xa0 , V_49 ) ;
F_5 ( V_1 , 0xa0 , V_50 ) ;
}
static void F_18 ( struct V_1 * V_1 )
{
struct V_51 * V_52 = & V_1 -> V_52 ;
struct V_53 * V_54 = V_52 -> V_54 ;
if ( V_1 -> V_55 >= 0 )
F_19 ( V_54 , V_1 -> V_55 ,
V_56 , L_1 ) ;
}
static int F_20 ( struct V_1 * V_1 )
{
struct V_51 * V_52 = & V_1 -> V_52 ;
struct V_53 * V_54 = V_52 -> V_54 ;
T_1 V_2 ;
if ( F_21 ( V_52 ) ) {
F_22 ( V_54 , L_2 ) ;
return 0 ;
}
F_11 ( V_1 ) ;
F_13 ( V_1 ) ;
F_14 ( V_1 ) ;
F_15 ( V_1 ) ;
F_17 ( V_1 ) ;
F_7 ( V_1 , 1 , V_19 ) ;
F_23 ( 500 ) ;
F_7 ( V_1 , 0 , V_19 ) ;
F_12 ( V_1 ) ;
F_24 ( V_52 ) ;
F_18 ( V_1 ) ;
F_1 ( V_1 , V_57 ,
V_58 ) ;
if ( ! F_25 ( V_52 ) )
return 0 ;
while ( F_6 ( V_1 , V_59 ) == 0 ) {
V_2 = F_8 ( V_1 , V_59 ) ;
F_26 ( V_54 , L_3 , V_2 ) ;
}
F_16 ( V_1 ) ;
return - V_60 ;
}
static void F_27 ( struct V_1 * V_1 )
{
T_1 V_2 ;
V_2 = F_3 ( V_1 , V_61 ) ;
F_1 ( V_1 , V_2 , V_61 ) ;
}
static void F_28 ( struct V_1 * V_1 )
{
T_1 V_2 ;
V_2 = V_62 | V_63 |
V_64 | V_65 ;
F_1 ( V_1 , V_2 , V_66 ) ;
}
static T_2 F_29 ( int V_67 , void * V_68 )
{
struct V_1 * V_1 = V_68 ;
F_27 ( V_1 ) ;
return V_69 ;
}
static T_2 F_30 ( int V_67 , void * V_68 )
{
struct V_1 * V_1 = V_68 ;
struct V_51 * V_52 = & V_1 -> V_52 ;
return F_31 ( V_52 ) ;
}
static void F_32 ( struct V_1 * V_1 )
{
struct V_51 * V_52 = & V_1 -> V_52 ;
T_1 V_2 ;
F_33 ( V_52 ) ;
V_2 = F_3 ( V_1 , V_70 ) ;
V_2 |= V_71 ;
F_1 ( V_1 , V_2 , V_70 ) ;
}
static void F_34 ( struct V_1 * V_1 )
{
F_28 ( V_1 ) ;
if ( F_35 ( V_72 ) )
F_32 ( V_1 ) ;
}
static T_1 F_36 ( struct V_51 * V_52 , T_1 V_3 )
{
struct V_1 * V_1 = F_37 ( V_52 ) ;
T_1 V_2 ;
F_10 ( V_1 , true ) ;
V_2 = F_4 ( V_52 -> V_73 + V_3 ) ;
F_10 ( V_1 , false ) ;
return V_2 ;
}
static void F_38 ( struct V_51 * V_52 , T_1 V_3 , T_1 V_2 )
{
struct V_1 * V_1 = F_37 ( V_52 ) ;
F_9 ( V_1 , true ) ;
F_2 ( V_2 , V_52 -> V_73 + V_3 ) ;
F_9 ( V_1 , false ) ;
}
static int F_39 ( struct V_51 * V_52 , int V_74 , int V_75 ,
T_1 * V_2 )
{
struct V_1 * V_1 = F_37 ( V_52 ) ;
int V_76 ;
F_10 ( V_1 , true ) ;
V_76 = F_40 ( V_52 -> V_73 + V_74 , V_75 , V_2 ) ;
F_10 ( V_1 , false ) ;
return V_76 ;
}
static int F_41 ( struct V_51 * V_52 , int V_74 , int V_75 ,
T_1 V_2 )
{
struct V_1 * V_1 = F_37 ( V_52 ) ;
int V_76 ;
F_9 ( V_1 , true ) ;
V_76 = F_42 ( V_52 -> V_73 + V_74 , V_75 , V_2 ) ;
F_9 ( V_1 , false ) ;
return V_76 ;
}
static int F_43 ( struct V_51 * V_52 )
{
struct V_1 * V_1 = F_37 ( V_52 ) ;
T_1 V_2 ;
V_2 = F_3 ( V_1 , V_77 ) ;
if ( V_2 == V_57 )
return 1 ;
return 0 ;
}
static void F_44 ( struct V_51 * V_52 )
{
struct V_1 * V_1 = F_37 ( V_52 ) ;
F_20 ( V_1 ) ;
F_34 ( V_1 ) ;
}
static int T_3 F_45 ( struct V_1 * V_1 ,
struct V_78 * V_79 )
{
struct V_51 * V_52 = & V_1 -> V_52 ;
struct V_53 * V_54 = V_52 -> V_54 ;
int V_76 ;
V_52 -> V_67 = F_46 ( V_79 , 1 ) ;
if ( ! V_52 -> V_67 ) {
F_22 ( V_54 , L_4 ) ;
return - V_80 ;
}
V_76 = F_47 ( V_54 , V_52 -> V_67 , F_29 ,
V_81 , L_5 , V_1 ) ;
if ( V_76 ) {
F_22 ( V_54 , L_6 ) ;
return V_76 ;
}
if ( F_35 ( V_72 ) ) {
V_52 -> V_82 = F_46 ( V_79 , 0 ) ;
if ( ! V_52 -> V_82 ) {
F_22 ( V_54 , L_7 ) ;
return - V_80 ;
}
V_76 = F_47 ( V_54 , V_52 -> V_82 ,
F_30 ,
V_81 | V_83 ,
L_5 , V_1 ) ;
if ( V_76 ) {
F_22 ( V_54 , L_8 ) ;
return V_76 ;
}
}
V_52 -> V_84 = - 1 ;
V_52 -> V_85 = & V_86 ;
V_76 = F_48 ( V_52 ) ;
if ( V_76 ) {
F_22 ( V_54 , L_9 ) ;
return V_76 ;
}
return 0 ;
}
static int T_3 F_49 ( struct V_78 * V_79 )
{
struct V_53 * V_54 = & V_79 -> V_54 ;
struct V_1 * V_1 ;
struct V_51 * V_52 ;
struct V_87 * V_88 = V_54 -> V_89 ;
struct V_90 * V_4 ;
struct V_90 * V_5 ;
struct V_90 * V_6 ;
int V_76 ;
V_1 = F_50 ( V_54 , sizeof( * V_1 ) , V_91 ) ;
if ( ! V_1 )
return - V_92 ;
V_52 = & V_1 -> V_52 ;
V_52 -> V_54 = V_54 ;
V_1 -> V_55 = F_51 ( V_88 , L_10 , 0 ) ;
V_1 -> V_93 = F_52 ( V_54 , L_11 ) ;
if ( F_53 ( V_1 -> V_93 ) ) {
F_22 ( V_54 , L_12 ) ;
return F_54 ( V_1 -> V_93 ) ;
}
V_76 = F_55 ( V_1 -> V_93 ) ;
if ( V_76 )
return V_76 ;
V_1 -> V_94 = F_52 ( V_54 , L_13 ) ;
if ( F_53 ( V_1 -> V_94 ) ) {
F_22 ( V_54 , L_14 ) ;
V_76 = F_54 ( V_1 -> V_94 ) ;
goto V_95;
}
V_76 = F_55 ( V_1 -> V_94 ) ;
if ( V_76 )
goto V_95;
V_4 = F_56 ( V_79 , V_96 , 0 ) ;
V_1 -> V_4 = F_57 ( V_54 , V_4 ) ;
if ( F_53 ( V_1 -> V_4 ) ) {
V_76 = F_54 ( V_1 -> V_4 ) ;
goto V_97;
}
V_5 = F_56 ( V_79 , V_96 , 1 ) ;
V_1 -> V_5 = F_57 ( V_54 , V_5 ) ;
if ( F_53 ( V_1 -> V_5 ) ) {
V_76 = F_54 ( V_1 -> V_5 ) ;
goto V_97;
}
V_6 = F_56 ( V_79 , V_96 , 2 ) ;
V_1 -> V_6 = F_57 ( V_54 , V_6 ) ;
if ( F_53 ( V_1 -> V_6 ) ) {
V_76 = F_54 ( V_1 -> V_6 ) ;
goto V_97;
}
V_76 = F_45 ( V_1 , V_79 ) ;
if ( V_76 < 0 )
goto V_97;
F_58 ( V_79 , V_1 ) ;
return 0 ;
V_97:
F_59 ( V_1 -> V_94 ) ;
V_95:
F_59 ( V_1 -> V_93 ) ;
return V_76 ;
}
static int T_4 F_60 ( struct V_78 * V_79 )
{
struct V_1 * V_1 = F_61 ( V_79 ) ;
F_59 ( V_1 -> V_94 ) ;
F_59 ( V_1 -> V_93 ) ;
return 0 ;
}
static int T_3 F_62 ( void )
{
return F_63 ( & V_98 , F_49 ) ;
}

static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_3 , V_2 -> V_6 + V_4 ) ;
}
static inline T_1 F_6 ( struct V_1 * V_2 , T_1 V_4 )
{
return F_4 ( V_2 -> V_6 + V_4 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_3 , V_2 -> V_7 + V_4 ) ;
}
static inline T_1 F_8 ( struct V_1 * V_2 , T_1 V_4 )
{
return F_4 ( V_2 -> V_7 + V_4 ) ;
}
static void F_9 ( struct V_8 * V_9 , bool V_10 )
{
T_1 V_3 ;
struct V_1 * V_1 = F_10 ( V_9 ) ;
if ( V_10 ) {
V_3 = F_3 ( V_1 , V_11 ) ;
V_3 |= V_12 ;
F_1 ( V_1 , V_3 , V_11 ) ;
} else {
V_3 = F_3 ( V_1 , V_11 ) ;
V_3 &= ~ V_12 ;
F_1 ( V_1 , V_3 , V_11 ) ;
}
}
static void F_11 ( struct V_8 * V_9 , bool V_10 )
{
T_1 V_3 ;
struct V_1 * V_1 = F_10 ( V_9 ) ;
if ( V_10 ) {
V_3 = F_3 ( V_1 , V_13 ) ;
V_3 |= V_12 ;
F_1 ( V_1 , V_3 , V_13 ) ;
} else {
V_3 = F_3 ( V_1 , V_13 ) ;
V_3 &= ~ V_12 ;
F_1 ( V_1 , V_3 , V_13 ) ;
}
}
static void F_12 ( struct V_8 * V_9 )
{
T_1 V_3 ;
struct V_1 * V_1 = F_10 ( V_9 ) ;
V_3 = F_3 ( V_1 , V_14 ) ;
V_3 &= ~ V_15 ;
F_1 ( V_1 , V_3 , V_14 ) ;
F_1 ( V_1 , 0 , V_16 ) ;
F_1 ( V_1 , 0 , V_17 ) ;
F_1 ( V_1 , 0 , V_18 ) ;
}
static void F_13 ( struct V_8 * V_9 )
{
T_1 V_3 ;
struct V_1 * V_1 = F_10 ( V_9 ) ;
V_3 = F_3 ( V_1 , V_14 ) ;
V_3 |= V_15 ;
F_1 ( V_1 , V_3 , V_14 ) ;
F_1 ( V_1 , 1 , V_17 ) ;
F_1 ( V_1 , 1 , V_18 ) ;
F_1 ( V_1 , 1 , V_19 ) ;
F_1 ( V_1 , 0 , V_19 ) ;
F_7 ( V_1 , 1 , V_20 ) ;
}
static void F_14 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_10 ( V_9 ) ;
F_7 ( V_1 , 0 , V_20 ) ;
F_7 ( V_1 , 1 , V_21 ) ;
}
static void F_15 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_10 ( V_9 ) ;
F_7 ( V_1 , 0 , V_21 ) ;
F_1 ( V_1 , 1 , V_16 ) ;
F_7 ( V_1 , 0 , V_22 ) ;
F_7 ( V_1 , 0 , V_23 ) ;
F_7 ( V_1 , 0 , V_24 ) ;
F_7 ( V_1 , 0 , V_25 ) ;
}
static void F_16 ( struct V_8 * V_9 )
{
T_1 V_3 ;
struct V_1 * V_1 = F_10 ( V_9 ) ;
V_3 = F_6 ( V_1 , V_26 ) ;
V_3 &= ~ V_27 ;
F_5 ( V_1 , V_3 , V_26 ) ;
V_3 = F_6 ( V_1 , V_28 ) ;
V_3 &= ~ V_29 ;
F_5 ( V_1 , V_3 , V_28 ) ;
V_3 = F_6 ( V_1 , V_30 ) ;
V_3 &= ~ V_31 ;
F_5 ( V_1 , V_3 , V_30 ) ;
V_3 = F_6 ( V_1 , V_32 ) ;
V_3 &= ~ V_33 ;
F_5 ( V_1 , V_3 , V_32 ) ;
V_3 = F_6 ( V_1 , V_34 ) ;
V_3 &= ~ V_35 ;
F_5 ( V_1 , V_3 , V_34 ) ;
}
static void F_17 ( struct V_8 * V_9 )
{
T_1 V_3 ;
struct V_1 * V_1 = F_10 ( V_9 ) ;
V_3 = F_6 ( V_1 , V_26 ) ;
V_3 |= V_27 ;
F_5 ( V_1 , V_3 , V_26 ) ;
V_3 = F_6 ( V_1 , V_28 ) ;
V_3 |= V_29 ;
F_5 ( V_1 , V_3 , V_28 ) ;
V_3 = F_6 ( V_1 , V_30 ) ;
V_3 |= V_31 ;
F_5 ( V_1 , V_3 , V_30 ) ;
V_3 = F_6 ( V_1 , V_32 ) ;
V_3 |= V_33 ;
F_5 ( V_1 , V_3 , V_32 ) ;
V_3 = F_6 ( V_1 , V_34 ) ;
V_3 |= V_35 ;
F_5 ( V_1 , V_3 , V_34 ) ;
}
static void F_18 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_10 ( V_9 ) ;
F_5 ( V_1 , 0x29 , V_36 ) ;
F_5 ( V_1 , 0xd5 , V_37 ) ;
F_5 ( V_1 , 0x14 , V_38 ) ;
F_5 ( V_1 , 0x12 , V_39 ) ;
F_5 ( V_1 , 0x7f , V_40 ) ;
F_5 ( V_1 , 0x0 , V_41 ) ;
F_5 ( V_1 , 0xe7 , V_42 ) ;
F_5 ( V_1 , 0x82 , V_43 ) ;
F_5 ( V_1 , 0x82 , V_44 ) ;
F_5 ( V_1 , 0x82 , V_45 ) ;
F_5 ( V_1 , 0x82 , V_46 ) ;
F_5 ( V_1 , 0x39 , V_41 ) ;
F_5 ( V_1 , 0x39 , V_47 ) ;
F_5 ( V_1 , 0x39 , V_48 ) ;
F_5 ( V_1 , 0x39 , V_49 ) ;
F_5 ( V_1 , 0x20 , V_50 ) ;
F_5 ( V_1 , 0xa0 , V_51 ) ;
F_5 ( V_1 , 0xa0 , V_52 ) ;
F_5 ( V_1 , 0xa0 , V_53 ) ;
}
static void F_19 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_10 ( V_9 ) ;
if ( V_1 -> V_54 >= 0 )
F_20 ( V_9 -> V_55 , V_1 -> V_54 ,
V_56 , L_1 ) ;
}
static int F_21 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_10 ( V_9 ) ;
T_1 V_3 ;
unsigned int V_57 ;
if ( F_22 ( V_9 ) ) {
F_23 ( V_9 -> V_55 , L_2 ) ;
return 0 ;
}
F_12 ( V_9 ) ;
F_14 ( V_9 ) ;
F_15 ( V_9 ) ;
F_16 ( V_9 ) ;
F_18 ( V_9 ) ;
F_7 ( V_1 , 1 , V_22 ) ;
F_24 ( 500 ) ;
F_7 ( V_1 , 0 , V_22 ) ;
F_13 ( V_9 ) ;
F_25 ( V_9 ) ;
F_19 ( V_9 ) ;
F_1 ( V_1 , V_58 ,
V_59 ) ;
for ( V_57 = 0 ; V_57 < 10 ; V_57 ++ ) {
if ( F_22 ( V_9 ) ) {
F_26 ( V_9 -> V_55 , L_3 ) ;
return 0 ;
}
F_27 ( 100 ) ;
}
while ( F_6 ( V_1 , V_60 ) == 0 ) {
V_3 = F_8 ( V_1 , V_60 ) ;
F_26 ( V_9 -> V_55 , L_4 , V_3 ) ;
}
F_17 ( V_9 ) ;
F_23 ( V_9 -> V_55 , L_5 ) ;
return - V_61 ;
}
static void F_28 ( struct V_8 * V_9 )
{
T_1 V_3 ;
struct V_1 * V_1 = F_10 ( V_9 ) ;
V_3 = F_3 ( V_1 , V_62 ) ;
F_1 ( V_1 , V_3 , V_62 ) ;
}
static void F_29 ( struct V_8 * V_9 )
{
T_1 V_3 ;
struct V_1 * V_1 = F_10 ( V_9 ) ;
V_3 = V_63 | V_64 |
V_65 | V_66 ;
F_1 ( V_1 , V_3 , V_67 ) ;
}
static T_2 F_30 ( int V_68 , void * V_69 )
{
struct V_8 * V_9 = V_69 ;
F_28 ( V_9 ) ;
return V_70 ;
}
static T_2 F_31 ( int V_68 , void * V_69 )
{
struct V_8 * V_9 = V_69 ;
return F_32 ( V_9 ) ;
}
static void F_33 ( struct V_8 * V_9 )
{
T_1 V_3 ;
struct V_1 * V_1 = F_10 ( V_9 ) ;
F_34 ( V_9 ) ;
V_3 = F_3 ( V_1 , V_71 ) ;
V_3 |= V_72 ;
F_1 ( V_1 , V_3 , V_71 ) ;
}
static void F_35 ( struct V_8 * V_9 )
{
F_29 ( V_9 ) ;
if ( F_36 ( V_73 ) )
F_33 ( V_9 ) ;
}
static inline void F_37 ( struct V_8 * V_9 ,
void T_3 * V_74 , T_1 * V_3 )
{
F_11 ( V_9 , true ) ;
* V_3 = F_4 ( V_74 ) ;
F_11 ( V_9 , false ) ;
}
static inline void F_38 ( struct V_8 * V_9 ,
T_1 V_3 , void T_3 * V_74 )
{
F_9 ( V_9 , true ) ;
F_2 ( V_3 , V_74 ) ;
F_9 ( V_9 , false ) ;
}
static int F_39 ( struct V_8 * V_9 , int V_75 , int V_76 ,
T_1 * V_3 )
{
int V_77 ;
F_11 ( V_9 , true ) ;
V_77 = F_40 ( V_9 -> V_74 + V_75 , V_76 , V_3 ) ;
F_11 ( V_9 , false ) ;
return V_77 ;
}
static int F_41 ( struct V_8 * V_9 , int V_75 , int V_76 ,
T_1 V_3 )
{
int V_77 ;
F_9 ( V_9 , true ) ;
V_77 = F_42 ( V_9 -> V_74 + V_75 , V_76 , V_3 ) ;
F_9 ( V_9 , false ) ;
return V_77 ;
}
static int F_43 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_10 ( V_9 ) ;
T_1 V_3 = F_3 ( V_1 , V_78 ) ;
if ( V_3 == V_58 )
return 1 ;
return 0 ;
}
static void F_44 ( struct V_8 * V_9 )
{
F_21 ( V_9 ) ;
F_35 ( V_9 ) ;
}
static int T_4 F_45 ( struct V_8 * V_9 ,
struct V_79 * V_80 )
{
int V_77 ;
V_9 -> V_68 = F_46 ( V_80 , 1 ) ;
if ( ! V_9 -> V_68 ) {
F_23 ( & V_80 -> V_55 , L_6 ) ;
return - V_81 ;
}
V_77 = F_47 ( & V_80 -> V_55 , V_9 -> V_68 , F_30 ,
V_82 , L_7 , V_9 ) ;
if ( V_77 ) {
F_23 ( & V_80 -> V_55 , L_8 ) ;
return V_77 ;
}
if ( F_36 ( V_73 ) ) {
V_9 -> V_83 = F_46 ( V_80 , 0 ) ;
if ( ! V_9 -> V_83 ) {
F_23 ( & V_80 -> V_55 , L_9 ) ;
return - V_81 ;
}
V_77 = F_47 ( & V_80 -> V_55 , V_9 -> V_83 ,
F_31 ,
V_82 | V_84 ,
L_7 , V_9 ) ;
if ( V_77 ) {
F_23 ( & V_80 -> V_55 , L_10 ) ;
return V_77 ;
}
}
V_9 -> V_85 = - 1 ;
V_9 -> V_86 = & V_87 ;
V_77 = F_48 ( V_9 ) ;
if ( V_77 ) {
F_23 ( & V_80 -> V_55 , L_11 ) ;
return V_77 ;
}
return 0 ;
}
static int T_4 F_49 ( struct V_79 * V_80 )
{
struct V_1 * V_1 ;
struct V_8 * V_9 ;
struct V_88 * V_89 = V_80 -> V_55 . V_90 ;
struct V_91 * V_5 ;
struct V_91 * V_6 ;
struct V_91 * V_7 ;
int V_77 ;
V_1 = F_50 ( & V_80 -> V_55 , sizeof( * V_1 ) ,
V_92 ) ;
if ( ! V_1 )
return - V_93 ;
V_9 = & V_1 -> V_9 ;
V_9 -> V_55 = & V_80 -> V_55 ;
V_1 -> V_54 = F_51 ( V_89 , L_12 , 0 ) ;
V_1 -> V_94 = F_52 ( & V_80 -> V_55 , L_13 ) ;
if ( F_53 ( V_1 -> V_94 ) ) {
F_23 ( & V_80 -> V_55 , L_14 ) ;
return F_54 ( V_1 -> V_94 ) ;
}
V_77 = F_55 ( V_1 -> V_94 ) ;
if ( V_77 )
return V_77 ;
V_1 -> V_95 = F_52 ( & V_80 -> V_55 , L_15 ) ;
if ( F_53 ( V_1 -> V_95 ) ) {
F_23 ( & V_80 -> V_55 , L_16 ) ;
V_77 = F_54 ( V_1 -> V_95 ) ;
goto V_96;
}
V_77 = F_55 ( V_1 -> V_95 ) ;
if ( V_77 )
goto V_96;
V_5 = F_56 ( V_80 , V_97 , 0 ) ;
V_1 -> V_5 = F_57 ( & V_80 -> V_55 , V_5 ) ;
if ( F_53 ( V_1 -> V_5 ) ) {
V_77 = F_54 ( V_1 -> V_5 ) ;
goto V_98;
}
V_6 = F_56 ( V_80 , V_97 , 1 ) ;
V_1 -> V_6 = F_57 ( & V_80 -> V_55 , V_6 ) ;
if ( F_53 ( V_1 -> V_6 ) ) {
V_77 = F_54 ( V_1 -> V_6 ) ;
goto V_98;
}
V_7 = F_56 ( V_80 , V_97 , 2 ) ;
V_1 -> V_7 = F_57 ( & V_80 -> V_55 , V_7 ) ;
if ( F_53 ( V_1 -> V_7 ) ) {
V_77 = F_54 ( V_1 -> V_7 ) ;
goto V_98;
}
V_77 = F_45 ( V_9 , V_80 ) ;
if ( V_77 < 0 )
goto V_98;
F_58 ( V_80 , V_1 ) ;
return 0 ;
V_98:
F_59 ( V_1 -> V_95 ) ;
V_96:
F_59 ( V_1 -> V_94 ) ;
return V_77 ;
}
static int T_5 F_60 ( struct V_79 * V_80 )
{
struct V_1 * V_1 = F_61 ( V_80 ) ;
F_59 ( V_1 -> V_95 ) ;
F_59 ( V_1 -> V_94 ) ;
return 0 ;
}
static int T_4 F_62 ( void )
{
return F_63 ( & V_99 , F_49 ) ;
}

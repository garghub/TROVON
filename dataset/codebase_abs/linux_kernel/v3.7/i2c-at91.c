static unsigned F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , unsigned V_3 , unsigned V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_6 ,
V_7 | V_8 | V_9 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
F_3 ( V_2 , V_10 , V_11 ) ;
F_3 ( V_2 , V_10 , V_12 ) ;
F_3 ( V_2 , V_10 , V_13 ) ;
F_3 ( V_2 , V_14 , V_2 -> V_15 ) ;
}
static void T_1 F_7 ( struct V_1 * V_2 , int V_16 )
{
int V_17 , V_18 , div ;
struct V_19 * V_20 = V_2 -> V_20 ;
int V_21 = V_20 -> V_22 ;
int V_23 = V_20 -> V_24 ;
div = F_8 ( 0 , ( int ) F_9 ( F_10 ( V_2 -> V_25 ) ,
2 * V_16 ) - V_21 ) ;
V_17 = F_11 ( div >> 8 ) ;
V_18 = div >> V_17 ;
if ( V_17 > V_23 ) {
F_12 ( V_2 -> V_2 , L_1 ,
V_17 , V_23 ) ;
V_17 = V_23 ;
V_18 = 255 ;
}
V_2 -> V_15 = ( V_17 << 16 ) | ( V_18 << 8 ) | V_18 ;
F_13 ( V_2 -> V_2 , L_2 , V_18 , V_17 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
if ( V_2 -> V_26 <= 0 )
return;
F_3 ( V_2 , V_27 , * V_2 -> V_28 ) ;
if ( -- V_2 -> V_26 == 0 )
F_3 ( V_2 , V_10 , V_29 ) ;
F_13 ( V_2 -> V_2 , L_3 , * V_2 -> V_28 , V_2 -> V_26 ) ;
++ V_2 -> V_28 ;
}
static void F_15 ( struct V_1 * V_2 )
{
if ( V_2 -> V_26 <= 0 )
return;
* V_2 -> V_28 = F_1 ( V_2 , V_30 ) & 0xff ;
-- V_2 -> V_26 ;
if ( F_16 ( V_2 -> V_31 -> V_32 & V_33 ) ) {
V_2 -> V_31 -> V_32 &= ~ V_33 ;
V_2 -> V_26 += * V_2 -> V_28 ;
V_2 -> V_31 -> V_34 = V_2 -> V_26 + 1 ;
F_13 ( V_2 -> V_2 , L_4 , V_2 -> V_26 ) ;
}
if ( V_2 -> V_26 == 1 )
F_3 ( V_2 , V_10 , V_29 ) ;
F_13 ( V_2 -> V_2 , L_5 , * V_2 -> V_28 , V_2 -> V_26 ) ;
++ V_2 -> V_28 ;
}
static T_2 F_17 ( int V_35 , void * V_36 )
{
struct V_1 * V_2 = V_36 ;
const unsigned V_37 = F_1 ( V_2 , V_38 ) ;
const unsigned V_39 = V_37 & F_1 ( V_2 , V_40 ) ;
if ( ! V_39 )
return V_41 ;
else if ( V_39 & V_8 )
F_15 ( V_2 ) ;
else if ( V_39 & V_9 )
F_14 ( V_2 ) ;
V_2 -> V_42 |= V_37 ;
if ( V_39 & V_7 ) {
F_5 ( V_2 ) ;
F_18 ( & V_2 -> V_43 ) ;
}
return V_44 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_45 ;
bool V_46 = V_2 -> V_20 -> V_46 ;
F_13 ( V_2 -> V_2 , L_6 ,
( V_2 -> V_31 -> V_32 & V_47 ) ? L_7 : L_8 , V_2 -> V_26 ) ;
F_20 ( V_2 -> V_43 ) ;
V_2 -> V_42 = 0 ;
if ( ! V_2 -> V_26 ) {
F_3 ( V_2 , V_10 , V_48 ) ;
F_3 ( V_2 , V_49 , V_7 ) ;
} else if ( V_2 -> V_31 -> V_32 & V_47 ) {
unsigned V_50 = V_51 ;
if ( F_1 ( V_2 , V_38 ) & V_8 ) {
F_21 ( V_2 -> V_2 , L_9 ) ;
F_1 ( V_2 , V_30 ) ;
}
if ( V_2 -> V_26 <= 1 && ! ( V_2 -> V_31 -> V_32 & V_33 ) )
V_50 |= V_29 ;
F_3 ( V_2 , V_10 , V_50 ) ;
F_3 ( V_2 , V_49 ,
V_7 | V_8 ) ;
} else {
F_14 ( V_2 ) ;
F_3 ( V_2 , V_49 ,
V_7 | V_9 ) ;
}
V_45 = F_22 ( & V_2 -> V_43 ,
V_2 -> V_52 . V_53 ) ;
if ( V_45 == 0 ) {
F_21 ( V_2 -> V_2 , L_10 ) ;
F_6 ( V_2 ) ;
return - V_54 ;
}
if ( V_2 -> V_42 & V_55 ) {
F_13 ( V_2 -> V_2 , L_11 ) ;
return - V_56 ;
}
if ( V_2 -> V_42 & V_57 ) {
F_21 ( V_2 -> V_2 , L_12 ) ;
return - V_58 ;
}
if ( V_46 && V_2 -> V_42 & V_59 ) {
F_21 ( V_2 -> V_2 , L_13 ) ;
return - V_58 ;
}
F_13 ( V_2 -> V_2 , L_14 ) ;
return 0 ;
}
static int F_23 ( struct V_60 * V_61 , struct V_62 * V_31 , int V_63 )
{
struct V_1 * V_2 = F_24 ( V_61 ) ;
int V_45 ;
unsigned V_64 = 0 ;
struct V_62 * V_65 = V_31 ;
F_13 ( & V_61 -> V_2 , L_15 , V_63 ) ;
if ( V_63 > 2 ) {
F_21 ( V_2 -> V_2 ,
L_16 ) ;
return 0 ;
} else if ( V_63 == 2 ) {
int V_66 = 0 ;
int V_67 ;
if ( V_31 -> V_32 & V_47 ) {
F_21 ( V_2 -> V_2 , L_17 ) ;
return - V_68 ;
}
if ( V_31 -> V_34 > 3 ) {
F_21 ( V_2 -> V_2 , L_18 ) ;
return - V_68 ;
}
V_65 = & V_31 [ 1 ] ;
for ( V_67 = 0 ; V_67 < V_31 -> V_34 ; ++ V_67 ) {
const unsigned V_69 = V_31 -> V_28 [ V_31 -> V_34 - 1 - V_67 ] ;
V_66 |= V_69 << ( 8 * V_67 ) ;
V_64 += V_70 ;
}
F_3 ( V_2 , V_71 , V_66 ) ;
}
F_3 ( V_2 , V_72 , ( V_65 -> V_69 << 16 ) | V_64
| ( ( V_65 -> V_32 & V_47 ) ? V_73 : 0 ) ) ;
V_2 -> V_26 = V_65 -> V_34 ;
V_2 -> V_28 = V_65 -> V_28 ;
V_2 -> V_31 = V_65 ;
V_45 = F_19 ( V_2 ) ;
return ( V_45 < 0 ) ? V_45 : V_63 ;
}
static T_3 F_25 ( struct V_60 * V_52 )
{
return V_74 | V_75
| V_76 ;
}
static struct V_19 * T_1 F_26 (
struct V_77 * V_78 )
{
if ( V_78 -> V_2 . V_79 ) {
const struct V_80 * V_81 ;
V_81 = F_27 ( V_82 , V_78 -> V_2 . V_79 ) ;
if ( ! V_81 )
return NULL ;
return V_81 -> V_83 ;
}
return (struct V_19 * ) F_28 ( V_78 ) -> V_84 ;
}
static int T_1 F_29 ( struct V_77 * V_78 )
{
struct V_1 * V_2 ;
struct V_85 * V_86 ;
int V_87 ;
V_2 = F_30 ( & V_78 -> V_2 , sizeof( * V_2 ) , V_88 ) ;
if ( ! V_2 )
return - V_89 ;
F_31 ( & V_2 -> V_43 ) ;
V_2 -> V_2 = & V_78 -> V_2 ;
V_86 = F_32 ( V_78 , V_90 , 0 ) ;
if ( ! V_86 )
return - V_91 ;
V_2 -> V_20 = F_26 ( V_78 ) ;
if ( ! V_2 -> V_20 )
return - V_91 ;
V_2 -> V_4 = F_33 ( & V_78 -> V_2 , V_86 ) ;
if ( ! V_2 -> V_4 )
return - V_92 ;
V_2 -> V_35 = F_34 ( V_78 , 0 ) ;
if ( V_2 -> V_35 < 0 )
return V_2 -> V_35 ;
V_87 = F_35 ( & V_78 -> V_2 , V_2 -> V_35 , F_17 , 0 ,
F_36 ( V_2 -> V_2 ) , V_2 ) ;
if ( V_87 ) {
F_21 ( V_2 -> V_2 , L_19 , V_2 -> V_35 , V_87 ) ;
return V_87 ;
}
F_37 ( V_78 , V_2 ) ;
V_2 -> V_25 = F_38 ( V_2 -> V_2 , NULL ) ;
if ( F_39 ( V_2 -> V_25 ) ) {
F_21 ( V_2 -> V_2 , L_20 ) ;
return - V_91 ;
}
F_40 ( V_2 -> V_25 ) ;
F_7 ( V_2 , V_93 ) ;
F_6 ( V_2 ) ;
snprintf ( V_2 -> V_52 . V_94 , sizeof( V_2 -> V_52 . V_94 ) , L_21 ) ;
F_41 ( & V_2 -> V_52 , V_2 ) ;
V_2 -> V_52 . V_95 = V_96 ;
V_2 -> V_52 . V_97 = V_98 ;
V_2 -> V_52 . V_99 = & V_100 ;
V_2 -> V_52 . V_2 . V_101 = V_2 -> V_2 ;
V_2 -> V_52 . V_102 = V_78 -> V_103 ;
V_2 -> V_52 . V_53 = V_104 ;
V_2 -> V_52 . V_2 . V_79 = V_78 -> V_2 . V_79 ;
V_87 = F_42 ( & V_2 -> V_52 ) ;
if ( V_87 ) {
F_21 ( V_2 -> V_2 , L_22 ,
V_2 -> V_52 . V_94 ) ;
F_43 ( V_2 -> V_25 ) ;
return V_87 ;
}
F_44 ( & V_2 -> V_52 ) ;
F_45 ( V_2 -> V_2 , L_23 ) ;
return 0 ;
}
static int T_4 F_46 ( struct V_77 * V_78 )
{
struct V_1 * V_2 = F_47 ( V_78 ) ;
int V_87 ;
V_87 = F_48 ( & V_2 -> V_52 ) ;
F_43 ( V_2 -> V_25 ) ;
return V_87 ;
}
static int F_49 ( struct V_105 * V_2 )
{
struct V_1 * V_106 = F_50 ( V_2 ) ;
F_51 ( V_106 -> V_25 ) ;
return 0 ;
}
static int F_52 ( struct V_105 * V_2 )
{
struct V_1 * V_106 = F_50 ( V_2 ) ;
return F_53 ( V_106 -> V_25 ) ;
}
static int T_5 F_54 ( void )
{
return F_55 ( & V_107 ) ;
}
static void T_6 F_56 ( void )
{
F_57 ( & V_107 ) ;
}

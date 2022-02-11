static void F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
switch ( F_2 ( V_2 , V_5 ) ) {
case V_6 :
V_4 = ( V_3 == 32 ) ? 0x0001 : 0x0000 ;
break;
case V_7 :
V_4 = ( V_3 == 32 ) ? 0x0000 : 0x0001 ;
break;
case V_8 :
case V_9 :
if ( V_3 == 64 )
V_4 = 0x0000 ;
else if ( V_3 == 32 )
V_4 = 0x0101 ;
else
V_4 = 0x0001 ;
break;
default:
return;
}
F_3 ( V_2 , V_10 , V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_5 ( V_2 ) ;
int V_15 = F_6 ( V_14 -> V_16 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( ! V_12 -> V_17 )
V_12 -> V_17 = F_7 ( V_14 -> V_16 ) ;
V_12 -> V_18 = F_8 ( F_9 ( V_14 -> V_16 , 1 ) / 512 , 1L ) ;
F_1 ( V_2 , 16 ) ;
return 0 ;
}
static unsigned int F_10 ( struct V_1 * V_2 ,
unsigned int V_19 )
{
struct V_13 * V_14 = F_5 ( V_2 ) ;
unsigned int V_20 , V_21 , V_22 = 0 , V_23 = ~ 0 ;
int V_24 , V_15 ;
if ( ! ( V_2 -> V_25 -> V_26 & V_27 ) )
return F_7 ( V_14 -> V_16 ) ;
for ( V_24 = F_11 ( 9 , F_12 ( V_28 / V_19 ) ) ; V_24 >= 0 ; V_24 -- ) {
V_20 = F_9 ( V_14 -> V_16 , V_19 << V_24 ) ;
if ( V_20 > ( V_19 << V_24 ) ) {
V_20 = F_9 ( V_14 -> V_16 ,
( V_19 << V_24 ) / 4 * 3 ) ;
if ( V_20 > ( V_19 << V_24 ) )
continue;
}
V_21 = V_19 - ( V_20 >> V_24 ) ;
if ( V_21 <= V_23 ) {
V_22 = V_20 ;
V_23 = V_21 ;
}
}
V_15 = F_13 ( V_14 -> V_16 , V_22 ) ;
return V_15 == 0 ? V_22 : F_7 ( V_14 -> V_16 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_5 ( V_2 ) ;
F_15 ( V_14 -> V_16 ) ;
}
static int F_16 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_17 ( V_12 ) ;
return ! ( F_18 ( V_2 , V_29 ) & V_30 ) ;
}
static int F_19 ( struct V_11 * V_12 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = F_17 ( V_12 ) ;
struct V_13 * V_14 = F_5 ( V_2 ) ;
struct V_33 * V_34 ;
int V_15 ;
switch ( V_32 -> V_35 ) {
case V_36 :
V_34 = V_14 -> V_37 ;
break;
case V_38 :
V_34 = V_14 -> V_39 ;
break;
default:
return - V_40 ;
}
if ( F_20 ( V_14 -> V_41 ) || F_20 ( V_34 ) )
return V_32 -> V_35 ==
V_36 ? 0 : - V_40 ;
V_15 = F_21 ( V_2 -> V_12 , V_32 ) ;
if ( V_15 )
return V_15 ;
return F_22 ( V_14 -> V_41 , V_34 ) ;
}
static inline T_1 F_23 ( struct V_1 * V_2 ,
struct V_13 * V_14 , int V_42 )
{
return F_24 ( V_14 -> V_43 + ( V_42 << V_2 -> V_44 ) ) ;
}
static inline void F_25 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
int V_42 , T_1 V_4 )
{
F_26 ( V_4 , V_14 -> V_43 + ( V_42 << V_2 -> V_44 ) ) ;
}
static unsigned int F_27 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
if ( ! ( V_2 -> V_12 -> V_45 & V_46 ) )
return 0 ;
V_14 = F_5 ( V_2 ) ;
F_25 ( V_2 , V_14 , V_47 ,
0x8 << V_48 ) ;
F_28 ( V_2 , V_29 , 0x0 ) ;
F_25 ( V_2 , V_14 , V_47 ,
V_49 |
F_23 ( V_2 , V_14 , V_47 ) ) ;
F_3 ( V_2 , V_50 , ~ V_51 &
F_2 ( V_2 , V_50 ) ) ;
F_25 ( V_2 , V_14 , V_52 ,
V_53 |
F_23 ( V_2 , V_14 , V_52 ) ) ;
F_3 ( V_2 , V_50 , V_51 |
F_2 ( V_2 , V_50 ) ) ;
F_25 ( V_2 , V_14 , V_54 ,
~ V_55 &
F_23 ( V_2 , V_14 , V_54 ) ) ;
F_25 ( V_2 , V_14 , V_56 , V_2 -> V_57 ) ;
return ( F_23 ( V_2 , V_14 , V_47 ) >>
V_48 ) &
V_58 ;
}
static void F_29 ( struct V_1 * V_2 ,
unsigned long V_59 )
{
struct V_13 * V_14 = F_5 ( V_2 ) ;
F_25 ( V_2 , V_14 , V_60 , V_59 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_5 ( V_2 ) ;
unsigned long V_61 ;
unsigned long V_62 ;
unsigned long V_63 ;
unsigned long V_64 ;
unsigned long V_65 ;
unsigned long V_24 ;
F_25 ( V_2 , V_14 , V_66 , 0 ) ;
V_61 = 0 ;
V_65 = 0 ;
V_63 = 0 ;
V_64 = 0 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_67 * 2 ; V_24 ++ ) {
if ( F_31 ( V_24 , V_2 -> V_68 ) )
V_65 ++ ;
else {
if ( V_65 > V_61 ) {
V_63 = V_24 - V_65 ;
V_64 = V_24 - 1 ;
V_61 = V_65 ;
}
V_65 = 0 ;
}
}
if ( V_65 > V_61 ) {
V_63 = V_24 - V_65 ;
V_64 = V_24 - 1 ;
V_61 = V_65 ;
}
if ( V_61 >= V_69 )
V_62 = ( V_63 + V_64 ) / 2 % V_2 -> V_67 ;
else
return - V_70 ;
F_25 ( V_2 , V_14 , V_60 , V_62 ) ;
F_25 ( V_2 , V_14 , V_54 ,
V_55 |
F_23 ( V_2 , V_14 , V_54 ) ) ;
return 0 ;
}
static bool F_32 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
if ( ! ( V_2 -> V_12 -> V_45 & V_46 ) )
return 0 ;
V_14 = F_5 ( V_2 ) ;
if ( F_23 ( V_2 , V_14 , V_54 ) &
V_55 &&
F_23 ( V_2 , V_14 , V_66 ) &
V_71 ) {
F_25 ( V_2 , V_14 , V_66 , 0 ) ;
return true ;
}
return false ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
if ( ! ( V_2 -> V_12 -> V_45 & V_46 ) )
return;
V_14 = F_5 ( V_2 ) ;
F_3 ( V_2 , V_50 , ~ V_51 &
F_2 ( V_2 , V_50 ) ) ;
F_25 ( V_2 , V_14 , V_52 ,
~ V_53 &
F_23 ( V_2 , V_14 , V_52 ) ) ;
F_3 ( V_2 , V_50 , V_51 |
F_2 ( V_2 , V_50 ) ) ;
F_25 ( V_2 , V_14 , V_54 ,
~ V_55 &
F_23 ( V_2 , V_14 , V_54 ) ) ;
F_25 ( V_2 , V_14 , V_54 ,
~ V_55 &
F_23 ( V_2 , V_14 , V_54 ) ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
int V_72 = 1000 ;
while ( -- V_72 && ! ( F_18 ( V_2 , V_29 )
& V_73 ) )
F_35 ( 1 ) ;
if ( ! V_72 ) {
F_36 ( & V_2 -> V_74 -> V_75 , L_1 ) ;
return - V_76 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , int V_42 )
{
switch ( V_42 )
{
case V_77 :
case V_78 :
case V_79 :
case V_50 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_10 :
return F_34 ( V_2 ) ;
}
return 0 ;
}
static int F_38 ( struct V_84 * V_85 ,
unsigned int V_86 , int V_87 )
{
if ( ( V_86 == V_88 ) &&
V_87 == 2 )
return 1 ;
return V_87 ;
}
static void F_39 ( struct V_1 * V_2 , bool V_89 )
{
F_3 ( V_2 , V_83 , V_89 ? 2 : 0 ) ;
F_1 ( V_2 , V_89 ? 32 : 16 ) ;
}
static int F_40 ( struct V_90 * V_74 )
{
const struct V_91 * V_92 =
F_41 ( V_93 , & V_74 -> V_75 ) ;
struct V_13 * V_14 ;
struct V_94 * V_95 ;
struct V_94 * V_96 = V_74 -> V_75 . V_97 ;
struct V_1 * V_2 ;
struct V_98 * V_99 ;
int V_100 , V_15 , V_24 ;
struct V_101 * V_102 ;
V_99 = F_42 ( V_74 , V_103 , 0 ) ;
if ( ! V_99 )
return - V_40 ;
V_14 = F_43 ( & V_74 -> V_75 , sizeof( struct V_13 ) , V_104 ) ;
if ( ! V_14 )
return - V_105 ;
V_95 = & V_14 -> V_95 ;
V_102 = & V_14 -> V_102 ;
V_14 -> V_16 = F_44 ( & V_74 -> V_75 , NULL ) ;
if ( F_20 ( V_14 -> V_16 ) ) {
V_15 = F_45 ( V_14 -> V_16 ) ;
F_46 ( & V_74 -> V_75 , L_2 , V_15 ) ;
goto V_106;
}
V_14 -> V_41 = F_47 ( & V_74 -> V_75 ) ;
if ( ! F_20 ( V_14 -> V_41 ) ) {
V_14 -> V_37 = F_48 ( V_14 -> V_41 ,
V_107 ) ;
V_14 -> V_39 = F_48 ( V_14 -> V_41 ,
L_3 ) ;
}
V_2 = F_49 ( V_74 ) ;
if ( ! V_2 ) {
V_15 = - V_105 ;
goto V_106;
}
if ( V_92 && V_92 -> V_108 ) {
const struct V_109 * V_110 = V_92 -> V_108 ;
V_95 -> V_26 |= V_110 -> V_111 ;
V_95 -> V_112 = V_110 -> V_113 ;
V_95 -> V_114 |= V_110 -> V_114 ;
V_95 -> V_115 |= V_110 -> V_115 ;
V_95 -> V_116 = V_110 -> V_116 ;
V_102 -> V_117 = V_110 -> V_117 ;
V_2 -> V_44 = V_110 -> V_44 ;
}
V_2 -> V_118 = V_102 ;
V_2 -> V_119 = F_37 ;
V_2 -> V_120 = F_4 ;
V_2 -> V_121 = F_10 ;
V_2 -> V_122 = F_14 ;
V_2 -> V_123 = F_38 ;
if ( V_95 -> V_26 & V_27 ) {
V_2 -> V_124 = F_16 ;
V_2 -> V_125 =
F_19 ;
V_2 -> V_126 = F_27 ;
V_2 -> V_127 = F_29 ;
V_2 -> V_128 = F_30 ;
V_2 -> V_129 = F_32 ;
V_2 -> V_130 = F_33 ;
}
if ( ! V_2 -> V_44 && F_50 ( V_99 ) > 0x100 )
V_2 -> V_44 = 1 ;
if ( V_96 )
* V_95 = * V_96 ;
V_102 -> V_131 = V_132 ;
V_102 -> V_89 = F_39 ;
V_95 -> V_133 = 1 ;
V_95 -> V_114 |= V_134 ;
V_95 -> V_26 |= V_135 ;
V_95 -> V_26 |= V_136 ;
V_95 -> V_26 |= V_137 ;
V_95 -> V_26 |= V_138 ;
V_15 = F_51 ( V_2 , V_95 ) ;
if ( V_15 < 0 )
goto V_139;
if ( V_2 -> V_12 -> V_45 & V_46 ) {
V_2 -> V_12 -> V_45 |= V_140 ;
if ( V_92 && V_92 -> V_108 ) {
const struct V_109 * V_110 ;
const struct V_141 * V_68 ;
bool V_142 = false ;
V_110 = V_92 -> V_108 ;
V_68 = V_110 -> V_68 ;
for ( V_24 = 0 ; V_24 < V_110 -> V_143 ; V_24 ++ ) {
if ( V_68 [ V_24 ] . V_144 == 0 ||
V_68 [ V_24 ] . V_144 == V_2 -> V_12 -> V_17 ) {
V_2 -> V_57 = V_68 -> V_59 ;
V_142 = true ;
break;
}
}
if ( ! V_142 )
F_36 ( & V_2 -> V_74 -> V_75 , L_4 ) ;
V_14 -> V_43 = V_2 -> V_145 + V_110 -> V_146 ;
}
}
V_24 = 0 ;
while ( 1 ) {
V_100 = F_52 ( V_74 , V_24 ) ;
if ( V_100 < 0 )
break;
V_24 ++ ;
V_15 = F_53 ( & V_74 -> V_75 , V_100 , V_147 , 0 ,
F_54 ( & V_74 -> V_75 ) , V_2 ) ;
if ( V_15 )
goto V_148;
}
if ( ! V_24 ) {
V_15 = V_100 ;
goto V_148;
}
F_55 ( & V_74 -> V_75 , L_5 ,
F_56 ( V_2 -> V_12 ) , ( unsigned long )
( F_42 ( V_74 , V_103 , 0 ) -> V_149 ) ,
V_2 -> V_12 -> V_17 / 1000000 ) ;
return V_15 ;
V_148:
F_57 ( V_2 ) ;
V_139:
F_58 ( V_2 ) ;
V_106:
return V_15 ;
}
static int F_59 ( struct V_90 * V_74 )
{
struct V_11 * V_12 = F_60 ( V_74 ) ;
struct V_1 * V_2 = F_17 ( V_12 ) ;
F_57 ( V_2 ) ;
return 0 ;
}

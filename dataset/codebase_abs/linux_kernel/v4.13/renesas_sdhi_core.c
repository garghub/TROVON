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
V_15 = F_6 ( V_14 -> V_17 ) ;
if ( V_15 < 0 ) {
F_7 ( V_14 -> V_16 ) ;
return V_15 ;
}
if ( ! V_12 -> V_18 )
V_12 -> V_18 = F_8 ( V_14 -> V_16 ) ;
V_12 -> V_19 = F_9 ( F_10 ( V_14 -> V_16 , 1 ) / 512 , 1L ) ;
F_1 ( V_2 , 16 ) ;
return 0 ;
}
static unsigned int F_11 ( struct V_1 * V_2 ,
unsigned int V_20 )
{
struct V_13 * V_14 = F_5 ( V_2 ) ;
unsigned int V_21 , V_22 , V_23 = 0 , V_24 = ~ 0 ;
int V_25 , V_15 ;
if ( ! ( V_2 -> V_26 -> V_27 & V_28 ) )
return F_8 ( V_14 -> V_16 ) ;
for ( V_25 = F_12 ( 9 , F_13 ( V_29 / V_20 ) ) ; V_25 >= 0 ; V_25 -- ) {
V_21 = F_10 ( V_14 -> V_16 , V_20 << V_25 ) ;
if ( V_21 > ( V_20 << V_25 ) ) {
V_21 = F_10 ( V_14 -> V_16 ,
( V_20 << V_25 ) / 4 * 3 ) ;
if ( V_21 > ( V_20 << V_25 ) )
continue;
}
V_22 = V_20 - ( V_21 >> V_25 ) ;
if ( V_22 <= V_24 ) {
V_23 = V_21 ;
V_24 = V_22 ;
}
}
V_15 = F_14 ( V_14 -> V_16 , V_23 ) ;
return V_15 == 0 ? V_23 : F_8 ( V_14 -> V_16 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_5 ( V_2 ) ;
F_7 ( V_14 -> V_16 ) ;
F_7 ( V_14 -> V_17 ) ;
}
static int F_16 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_17 ( V_12 ) ;
return ! ( F_18 ( V_2 , V_30 ) &
V_31 ) ;
}
static int F_19 ( struct V_11 * V_12 ,
struct V_32 * V_33 )
{
struct V_1 * V_2 = F_17 ( V_12 ) ;
struct V_13 * V_14 = F_5 ( V_2 ) ;
struct V_34 * V_35 ;
int V_15 ;
switch ( V_33 -> V_36 ) {
case V_37 :
V_35 = V_14 -> V_38 ;
break;
case V_39 :
V_35 = V_14 -> V_40 ;
break;
default:
return - V_41 ;
}
if ( F_20 ( V_14 -> V_42 ) || F_20 ( V_35 ) )
return V_33 -> V_36 ==
V_37 ? 0 : - V_41 ;
V_15 = F_21 ( V_2 -> V_12 , V_33 ) ;
if ( V_15 )
return V_15 ;
return F_22 ( V_14 -> V_42 , V_35 ) ;
}
static inline T_1 F_23 ( struct V_1 * V_2 ,
struct V_13 * V_14 , int V_43 )
{
return F_24 ( V_14 -> V_44 + ( V_43 << V_2 -> V_45 ) ) ;
}
static inline void F_25 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
int V_43 , T_1 V_4 )
{
F_26 ( V_4 , V_14 -> V_44 + ( V_43 << V_2 -> V_45 ) ) ;
}
static unsigned int F_27 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
V_14 = F_5 ( V_2 ) ;
F_25 ( V_2 , V_14 , V_46 ,
0x8 << V_47 ) ;
F_28 ( V_2 , V_30 , 0x0 ) ;
F_25 ( V_2 , V_14 , V_46 ,
V_48 |
F_23 ( V_2 , V_14 , V_46 ) ) ;
F_3 ( V_2 , V_49 , ~ V_50 &
F_2 ( V_2 , V_49 ) ) ;
F_25 ( V_2 , V_14 , V_51 ,
V_52 |
F_23 ( V_2 , V_14 , V_51 ) ) ;
F_3 ( V_2 , V_49 , V_50 |
F_2 ( V_2 , V_49 ) ) ;
F_25 ( V_2 , V_14 , V_53 ,
~ V_54 &
F_23 ( V_2 , V_14 , V_53 ) ) ;
F_25 ( V_2 , V_14 , V_55 , V_2 -> V_56 ) ;
return ( F_23 ( V_2 , V_14 , V_46 ) >>
V_47 ) &
V_57 ;
}
static void F_29 ( struct V_1 * V_2 ,
unsigned long V_58 )
{
struct V_13 * V_14 = F_5 ( V_2 ) ;
F_25 ( V_2 , V_14 , V_59 , V_58 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_5 ( V_2 ) ;
unsigned long V_60 ;
unsigned long V_61 ;
unsigned long V_62 ;
unsigned long V_63 ;
unsigned long V_64 ;
unsigned long V_25 ;
F_25 ( V_2 , V_14 , V_65 , 0 ) ;
V_60 = 0 ;
V_64 = 0 ;
V_62 = 0 ;
V_63 = 0 ;
for ( V_25 = 0 ; V_25 < V_2 -> V_66 * 2 ; V_25 ++ ) {
if ( F_31 ( V_25 , V_2 -> V_67 ) ) {
V_64 ++ ;
} else {
if ( V_64 > V_60 ) {
V_62 = V_25 - V_64 ;
V_63 = V_25 - 1 ;
V_60 = V_64 ;
}
V_64 = 0 ;
}
}
if ( V_64 > V_60 ) {
V_62 = V_25 - V_64 ;
V_63 = V_25 - 1 ;
V_60 = V_64 ;
}
if ( V_60 >= V_68 )
V_61 = ( V_62 + V_63 ) / 2 % V_2 -> V_66 ;
else
return - V_69 ;
F_25 ( V_2 , V_14 , V_59 , V_61 ) ;
F_25 ( V_2 , V_14 , V_53 ,
V_54 |
F_23 ( V_2 , V_14 , V_53 ) ) ;
return 0 ;
}
static bool F_32 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_5 ( V_2 ) ;
if ( F_23 ( V_2 , V_14 , V_53 ) &
V_54 &&
F_23 ( V_2 , V_14 , V_65 ) &
V_70 ) {
F_25 ( V_2 , V_14 , V_65 , 0 ) ;
return true ;
}
return false ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
V_14 = F_5 ( V_2 ) ;
F_3 ( V_2 , V_49 , ~ V_50 &
F_2 ( V_2 , V_49 ) ) ;
F_25 ( V_2 , V_14 , V_51 ,
~ V_52 &
F_23 ( V_2 , V_14 , V_51 ) ) ;
F_3 ( V_2 , V_49 , V_50 |
F_2 ( V_2 , V_49 ) ) ;
F_25 ( V_2 , V_14 , V_53 ,
~ V_54 &
F_23 ( V_2 , V_14 , V_53 ) ) ;
F_25 ( V_2 , V_14 , V_53 ,
~ V_54 &
F_23 ( V_2 , V_14 , V_53 ) ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
int V_71 = 1000 ;
while ( -- V_71 && ! ( F_18 ( V_2 , V_30 )
& V_72 ) )
F_35 ( 1 ) ;
if ( ! V_71 ) {
F_36 ( & V_2 -> V_73 -> V_74 , L_1 ) ;
return - V_75 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , int V_43 )
{
switch ( V_43 ) {
case V_76 :
case V_77 :
case V_78 :
case V_49 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_10 :
return F_34 ( V_2 ) ;
}
return 0 ;
}
static int F_38 ( struct V_83 * V_84 ,
unsigned int V_85 , int V_86 )
{
if ( ( V_85 == V_87 ) &&
V_86 == 2 )
return 1 ;
return V_86 ;
}
static void F_39 ( struct V_1 * V_2 , bool V_88 )
{
F_3 ( V_2 , V_82 , V_88 ? 2 : 0 ) ;
F_1 ( V_2 , V_88 ? 32 : 16 ) ;
}
int F_40 ( struct V_89 * V_73 ,
const struct V_90 * V_91 )
{
struct V_92 * V_93 = V_73 -> V_74 . V_94 ;
const struct V_95 * V_96 ;
struct V_92 * V_97 ;
struct V_98 * V_99 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
struct V_100 * V_101 ;
int V_102 , V_15 , V_25 ;
V_96 = F_41 ( & V_73 -> V_74 ) ;
V_101 = F_42 ( V_73 , V_103 , 0 ) ;
if ( ! V_101 )
return - V_41 ;
V_14 = F_43 ( & V_73 -> V_74 , sizeof( struct V_13 ) ,
V_104 ) ;
if ( ! V_14 )
return - V_105 ;
V_97 = & V_14 -> V_97 ;
V_99 = & V_14 -> V_99 ;
V_14 -> V_16 = F_44 ( & V_73 -> V_74 , NULL ) ;
if ( F_20 ( V_14 -> V_16 ) ) {
V_15 = F_45 ( V_14 -> V_16 ) ;
F_46 ( & V_73 -> V_74 , L_2 , V_15 ) ;
goto V_106;
}
V_14 -> V_17 = F_44 ( & V_73 -> V_74 , L_3 ) ;
if ( F_20 ( V_14 -> V_17 ) )
V_14 -> V_17 = NULL ;
V_14 -> V_42 = F_47 ( & V_73 -> V_74 ) ;
if ( ! F_20 ( V_14 -> V_42 ) ) {
V_14 -> V_38 = F_48 ( V_14 -> V_42 ,
V_107 ) ;
V_14 -> V_40 = F_48 ( V_14 -> V_42 ,
L_4 ) ;
}
V_2 = F_49 ( V_73 ) ;
if ( ! V_2 ) {
V_15 = - V_105 ;
goto V_106;
}
if ( V_96 ) {
V_97 -> V_27 |= V_96 -> V_108 ;
V_97 -> V_109 = V_96 -> V_110 ;
V_97 -> V_111 |= V_96 -> V_111 ;
V_97 -> V_112 |= V_96 -> V_112 ;
V_97 -> V_113 = V_96 -> V_113 ;
V_99 -> V_114 = V_96 -> V_114 ;
V_2 -> V_45 = V_96 -> V_45 ;
}
V_2 -> V_115 = V_99 ;
V_2 -> V_116 = F_37 ;
V_2 -> V_117 = F_4 ;
V_2 -> V_118 = F_11 ;
V_2 -> V_119 = F_15 ;
V_2 -> V_120 = F_38 ;
if ( V_97 -> V_27 & V_28 ) {
V_2 -> V_121 = F_16 ;
V_2 -> V_122 =
F_19 ;
}
if ( ! V_2 -> V_45 && F_50 ( V_101 ) > 0x100 )
V_2 -> V_45 = 1 ;
if ( V_93 )
* V_97 = * V_93 ;
V_99 -> V_123 = V_124 ;
V_99 -> V_88 = F_39 ;
V_97 -> V_125 = 1 ;
V_97 -> V_111 |= V_126 ;
V_97 -> V_27 |= V_127 ;
V_97 -> V_27 |= V_128 ;
V_97 -> V_27 |= V_129 ;
V_97 -> V_27 |= V_130 ;
V_15 = F_51 ( V_2 , V_97 , V_91 ) ;
if ( V_15 < 0 )
goto V_131;
if ( V_96 && V_96 -> V_132 &&
( V_2 -> V_12 -> V_133 & V_134 ||
V_2 -> V_12 -> V_135 & V_136 ) ) {
const struct V_137 * V_67 = V_96 -> V_67 ;
bool V_138 = false ;
V_2 -> V_12 -> V_133 |= V_139 ;
for ( V_25 = 0 ; V_25 < V_96 -> V_140 ; V_25 ++ ) {
if ( V_67 [ V_25 ] . V_141 == 0 ||
V_67 [ V_25 ] . V_141 == V_2 -> V_12 -> V_18 ) {
V_2 -> V_56 = V_67 -> V_58 ;
V_138 = true ;
break;
}
}
if ( ! V_138 )
F_36 ( & V_2 -> V_73 -> V_74 , L_5 ) ;
V_14 -> V_44 = V_2 -> V_142 + V_96 -> V_132 ;
V_2 -> V_143 = F_27 ;
V_2 -> V_144 = F_29 ;
V_2 -> V_145 = F_30 ;
V_2 -> V_146 = F_32 ;
V_2 -> V_147 = F_33 ;
}
V_25 = 0 ;
while ( 1 ) {
V_102 = F_52 ( V_73 , V_25 ) ;
if ( V_102 < 0 )
break;
V_25 ++ ;
V_15 = F_53 ( & V_73 -> V_74 , V_102 , V_148 , 0 ,
F_54 ( & V_73 -> V_74 ) , V_2 ) ;
if ( V_15 )
goto V_149;
}
if ( ! V_25 ) {
V_15 = V_102 ;
goto V_149;
}
F_55 ( & V_73 -> V_74 , L_6 ,
F_56 ( V_2 -> V_12 ) , ( unsigned long )
( F_42 ( V_73 , V_103 , 0 ) -> V_150 ) ,
V_2 -> V_12 -> V_18 / 1000000 ) ;
return V_15 ;
V_149:
F_57 ( V_2 ) ;
V_131:
F_58 ( V_2 ) ;
V_106:
return V_15 ;
}
int F_59 ( struct V_89 * V_73 )
{
struct V_11 * V_12 = F_60 ( V_73 ) ;
struct V_1 * V_2 = F_17 ( V_12 ) ;
F_57 ( V_2 ) ;
return 0 ;
}

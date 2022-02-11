static struct V_1 * F_1 ( struct V_2 * V_3 ,
unsigned long V_4 )
{
if ( V_4 >= V_3 -> V_5 -> V_6 && V_4 < V_3 -> V_5 -> V_7 )
return V_3 -> V_8 ;
return V_3 -> V_9 ;
}
static unsigned int F_2 ( struct V_2 * V_3 , unsigned long V_4 )
{
return ( ( V_4 >> 4 ) & V_3 -> V_5 -> V_10 )
<< V_3 -> V_5 -> V_11 ;
}
static int F_3 ( struct V_12 * V_13 ,
struct V_14 * V_15 , unsigned V_16 ,
bool V_17 )
{
unsigned int V_18 ;
unsigned int V_19 ;
struct V_2 * V_3 = F_4 ( V_13 ) ;
V_18 = F_2 ( V_3 , V_16 ) + V_3 -> V_5 -> V_20 ;
V_19 = F_5 ( V_16 & 0xf ) ;
if ( V_17 )
V_18 = F_6 ( V_18 , V_3 ) ;
else
V_18 = F_7 ( V_18 , V_3 ) ;
F_8 ( F_1 ( V_3 , V_16 ) , V_18 , V_19 ) ;
return 0 ;
}
static void F_9 ( struct V_21 * V_22 , unsigned V_16 , int V_23 )
{
unsigned int V_18 ;
unsigned int V_19 ;
struct V_2 * V_3 = F_10 ( V_22 -> V_24 ) ;
V_18 = F_2 ( V_3 , V_16 ) + V_3 -> V_5 -> V_25 ;
V_19 = F_5 ( V_16 & 0xf ) ;
if ( V_23 )
V_18 = F_7 ( V_18 , V_3 ) ;
else
V_18 = F_6 ( V_18 , V_3 ) ;
F_8 ( F_1 ( V_3 , V_16 ) , V_18 , V_19 ) ;
}
static int F_11 ( struct V_2 * V_3 , unsigned V_4 ,
int V_23 , enum V_26 V_27 )
{
unsigned int V_18 , V_16 ;
unsigned int V_19 ;
if ( ! V_3 -> V_5 -> V_28 &&
V_3 -> V_5 -> V_29 == V_30 &&
V_27 == V_31 )
return - V_32 ;
if ( ! V_3 -> V_5 -> V_28 &&
V_3 -> V_5 -> V_33 == V_30 &&
V_27 == V_34 )
return - V_32 ;
if ( V_3 -> V_5 -> V_28 ) {
return V_3 -> V_5 -> V_28 ( F_1 ( V_3 , V_4 ) ,
V_4 , V_3 -> V_5 -> V_35 , V_23 , V_27 ) ;
}
V_19 = F_5 ( V_4 & 0xf ) ;
if ( V_27 == V_31 )
V_16 = V_3 -> V_5 -> V_29 ;
else
V_16 = V_3 -> V_5 -> V_33 ;
if ( V_23 )
V_18 = F_7 ( F_2 ( V_3 , V_4 ) + V_16 , V_3 ) ;
else
V_18 = F_6 ( F_2 ( V_3 , V_4 ) + V_16 , V_3 ) ;
F_8 ( F_1 ( V_3 , V_4 ) , V_18 , V_19 ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_1 ,
const struct V_36 * V_37 , unsigned int V_38 ,
unsigned int V_4 , unsigned char V_39 , int V_23 )
{
unsigned int V_40 , V_18 , V_19 ;
for ( V_40 = 0 ; V_40 < V_38 ; V_40 ++ ) {
if ( V_4 >= V_37 [ V_40 ] . V_41 &&
V_4 <= V_37 [ V_40 ] . V_42 ) {
break;
}
}
if ( V_40 == V_38 )
return - V_32 ;
if ( V_23 )
V_18 = V_37 [ V_40 ] . V_16 + V_39 ;
else
V_18 = V_37 [ V_40 ] . V_16 + ( V_39 << 1 ) ;
V_19 = F_5 ( V_37 [ V_40 ] . V_19 ) ;
F_8 ( V_1 , V_18 , V_19 ) ;
return 0 ;
}
static const struct V_43 * F_13 (
struct V_2 * V_3 , unsigned long V_4 ) {
int V_40 ;
for ( V_40 = 0 ; V_40 < V_3 -> V_5 -> V_44 ; V_40 ++ ) {
const struct V_43 * V_45 =
V_3 -> V_5 -> V_46 + V_40 ;
if ( V_4 == V_45 -> V_4 )
return V_45 ;
}
return NULL ;
}
static int F_14 ( struct V_2 * V_3 ,
unsigned int V_4 , unsigned char V_47 )
{
const struct V_43 * V_45 ;
unsigned int V_48 ;
unsigned int V_49 , V_50 , V_51 ;
const struct V_52 * V_53 ;
if ( V_4 >= V_3 -> V_5 -> V_54 )
return - V_32 ;
V_45 = F_13 ( V_3 , V_4 ) ;
if ( ! V_45 || V_45 -> V_55 > V_3 -> V_5 -> V_56 )
return - V_32 ;
V_53 = V_3 -> V_5 -> V_57 + V_45 -> V_55 ;
if ( V_47 >= V_53 -> V_58 && V_47 <= V_53 -> V_59
&& ! ( V_47 % V_53 -> V_60 ) ) {
V_48 = V_47 / V_53 -> V_60 - 1 ;
V_49 = V_53 -> V_61 - V_53 -> V_62 + 1 ;
V_50 = F_5 ( V_49 ) - 1 ;
V_51 = V_45 -> V_19 + V_53 -> V_62 ;
V_50 <<= V_51 ;
V_48 <<= V_51 ;
return F_15 ( F_1 ( V_3 , V_4 ) ,
V_45 -> V_16 , V_50 , V_48 ) ;
}
return - V_32 ;
}
int F_16 ( struct V_1 * V_1 ,
const struct V_63 * V_64 ,
unsigned int V_38 , unsigned int V_4 ,
unsigned char V_39 , bool V_65 , unsigned int V_66 )
{
unsigned int V_40 ;
unsigned int V_67 , V_68 , V_69 ;
unsigned int V_70 , V_71 , V_72 ;
const struct V_63 * V_73 ;
bool V_74 = false ;
for ( V_40 = 0 ; V_40 < V_38 ; V_40 ++ ) {
if ( V_4 == V_64 [ V_40 ] . V_4 ) {
V_74 = true ;
break;
}
}
if ( ! V_74 )
return - V_32 ;
V_73 = V_64 + V_40 ;
V_68 = V_73 -> V_16 + V_39 ;
V_69 = V_73 -> V_16 + ( V_39 << 1 ) ;
if ( V_65 )
V_67 = V_69 ;
else
V_67 = V_68 ;
V_70 = F_5 ( V_73 -> V_75 ) ;
F_8 ( V_1 , V_67 , V_70 ) ;
V_71 = F_5 ( V_73 -> V_76 ) ;
V_72 = F_5 ( V_73 -> V_77 ) ;
switch ( V_66 ) {
case V_78 :
F_8 ( V_1 , V_69 , V_71 ) ;
F_8 ( V_1 , V_69 , V_72 ) ;
break;
case V_79 :
F_8 ( V_1 , V_68 , V_71 ) ;
F_8 ( V_1 , V_69 , V_72 ) ;
break;
case V_80 :
F_8 ( V_1 , V_69 , V_71 ) ;
F_8 ( V_1 , V_68 , V_72 ) ;
break;
case V_81 :
F_8 ( V_1 , V_68 , V_71 ) ;
F_8 ( V_1 , V_68 , V_72 ) ;
break;
default:
return - V_32 ;
}
return 0 ;
}
static int F_17 ( struct V_2 * V_3 ,
unsigned int V_4 , bool V_82 , bool V_65 , unsigned int V_27 )
{
unsigned int V_19 ;
unsigned int V_83 , V_84 ;
int V_85 ;
if ( V_3 -> V_5 -> V_86 ) {
V_85 = V_3 -> V_5 -> V_86 ( F_1 ( V_3 , V_4 ) ,
V_4 , V_3 -> V_5 -> V_35 , V_65 , V_27 ) ;
if ( ! V_85 )
return 0 ;
}
if ( V_27 != 0 && V_27 != 1 ) {
F_18 ( V_3 -> V_24 , L_1 ,
V_27 , V_4 ) ;
return - V_32 ;
}
V_19 = F_5 ( V_4 & 0xf ) ;
if ( V_82 )
V_83 = F_7 ( F_2 ( V_3 , V_4 ) +
V_3 -> V_5 -> V_87 , V_3 ) ;
else
V_83 = F_6 ( F_2 ( V_3 , V_4 ) +
V_3 -> V_5 -> V_87 , V_3 ) ;
if ( V_65 )
V_84 = F_7 ( F_2 ( V_3 , V_4 ) +
V_3 -> V_5 -> V_88 , V_3 ) ;
else
V_84 = F_6 ( F_2 ( V_3 , V_4 ) +
V_3 -> V_5 -> V_88 , V_3 ) ;
F_8 ( F_1 ( V_3 , V_4 ) , V_83 , V_19 ) ;
F_8 ( F_1 ( V_3 , V_4 ) , V_84 , V_19 ) ;
return 0 ;
}
static int F_19 ( struct V_12 * V_13 ,
unsigned int V_4 , enum V_26 V_89 ,
enum V_26 V_27 )
{
int V_85 = 0 ;
struct V_2 * V_3 = F_4 ( V_13 ) ;
switch ( V_89 ) {
case V_90 :
V_85 = F_17 ( V_3 , V_4 , false , false , V_27 ) ;
break;
case V_91 :
V_85 = F_17 ( V_3 , V_4 , true , true , V_27 ) ;
break;
case V_92 :
V_85 = F_17 ( V_3 , V_4 , true , false , V_27 ) ;
break;
case V_31 :
V_85 = F_11 ( V_3 , V_4 , V_27 , V_89 ) ;
break;
case V_93 :
F_9 ( V_3 -> V_22 , V_4 , V_27 ) ;
V_85 = F_3 ( V_13 , NULL , V_4 , false ) ;
break;
case V_34 :
V_85 = F_11 ( V_3 , V_4 , V_27 , V_89 ) ;
break;
case V_94 :
V_85 = F_14 ( V_3 , V_4 , V_27 ) ;
break;
default:
V_85 = - V_32 ;
}
return V_85 ;
}
static int F_20 ( struct V_12 * V_13 ,
unsigned V_95 ,
unsigned long * V_96 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
* V_96 = V_3 -> V_97 [ V_95 ] . V_96 ;
return 0 ;
}
static int F_21 ( struct V_12 * V_13 , unsigned V_95 ,
unsigned long * V_98 , unsigned V_99 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
struct V_100 * V_101 = & V_3 -> V_97 [ V_95 ] ;
int V_40 , V_85 ;
for ( V_40 = 0 ; V_40 < V_99 ; V_40 ++ ) {
V_85 = F_19 ( V_13 , V_101 -> V_4 ,
F_22 ( V_98 [ V_40 ] ) ,
F_23 ( V_98 [ V_40 ] ) ) ;
if ( V_85 < 0 )
return V_85 ;
V_101 -> V_96 = V_98 [ V_40 ] ;
}
return 0 ;
}
static struct V_100 *
F_24 ( struct V_2 * V_3 , T_1 V_4 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_3 -> V_102 ; V_40 ++ ) {
struct V_100 * V_55 = V_3 -> V_97 + V_40 ;
if ( V_55 -> V_4 == V_4 )
return V_55 ;
}
return NULL ;
}
static const struct V_103 * F_25 (
struct V_2 * V_3 , T_1 V_104 , T_1 V_105 )
{
const struct V_106 * V_4 = V_3 -> V_5 -> V_107 + V_104 ;
const struct V_103 * V_108 = V_4 -> V_109 ;
while ( V_108 && V_108 -> V_110 ) {
if ( V_108 -> V_111 == V_105 )
return V_108 ;
V_108 ++ ;
}
return NULL ;
}
static bool F_26 ( struct V_2 * V_3 ,
T_1 V_104 , T_1 V_105 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_3 -> V_5 -> V_54 ; V_40 ++ ) {
const struct V_106 * V_4 = V_3 -> V_5 -> V_107 + V_40 ;
if ( V_4 -> V_4 . V_112 == V_104 ) {
const struct V_103 * V_108 =
V_4 -> V_109 ;
while ( V_108 && V_108 -> V_110 ) {
if ( V_108 -> V_111 == V_105 )
return true ;
V_108 ++ ;
}
break;
}
}
return false ;
}
static int F_27 ( struct V_2 * V_3 ,
T_1 V_4 , T_1 V_105 , struct V_100 * V_55 ,
struct V_113 * * V_114 , unsigned * V_115 ,
unsigned * V_116 )
{
bool V_85 ;
if ( * V_116 == * V_115 )
return - V_117 ;
( * V_114 ) [ * V_116 ] . type = V_118 ;
( * V_114 ) [ * V_116 ] . V_119 . V_120 . V_95 = V_55 -> V_110 ;
V_85 = F_26 ( V_3 , V_4 , V_105 ) ;
if ( ! V_85 ) {
F_18 ( V_3 -> V_24 , L_2 ,
V_105 , V_4 ) ;
return - V_32 ;
}
( * V_114 ) [ * V_116 ] . V_119 . V_120 . V_121 = V_122 [ V_105 ] ;
( * V_116 ) ++ ;
return 0 ;
}
static int F_28 ( struct V_12 * V_13 ,
struct V_123 * V_124 ,
struct V_113 * * V_114 ,
unsigned * V_115 ,
unsigned * V_116 )
{
struct V_125 * V_107 ;
T_1 V_126 , V_4 , V_108 ;
int V_127 , V_128 , V_129 ;
unsigned long * V_98 ;
unsigned int V_99 ;
bool V_130 = 0 ;
int V_40 , V_131 ;
unsigned V_132 = 0 ;
struct V_100 * V_55 ;
struct V_2 * V_3 = F_4 ( V_13 ) ;
V_107 = F_29 ( V_124 , L_3 , NULL ) ;
if ( ! V_107 ) {
F_18 ( V_3 -> V_24 , L_4 ,
V_124 -> V_110 ) ;
return - V_32 ;
}
V_131 = F_30 ( V_124 , V_13 , & V_98 ,
& V_99 ) ;
if ( V_99 )
V_130 = 1 ;
V_127 = V_107 -> V_133 / sizeof( T_1 ) ;
V_128 = V_127 ;
V_129 = 0 ;
if ( V_128 )
V_129 ++ ;
if ( V_130 && V_127 >= 1 )
V_129 ++ ;
if ( ! V_127 || ! V_129 )
return - V_32 ;
V_132 = V_127 * V_129 ;
V_131 = F_31 ( V_13 , V_114 ,
V_115 , V_116 , V_132 ) ;
if ( V_131 < 0 )
goto V_134;
for ( V_40 = 0 ; V_40 < V_127 ; V_40 ++ ) {
V_131 = F_32 ( V_124 , L_3 ,
V_40 , & V_126 ) ;
if ( V_131 )
goto V_134;
V_4 = F_33 ( V_126 ) ;
V_108 = F_34 ( V_126 ) ;
if ( V_4 >= V_3 -> V_5 -> V_54 ||
V_108 >= F_35 ( V_122 ) ) {
F_18 ( V_3 -> V_24 , L_5 ) ;
V_131 = - V_32 ;
goto V_134;
}
V_55 = F_24 ( V_3 , V_4 ) ;
if ( ! V_55 ) {
F_18 ( V_3 -> V_24 , L_6 ,
V_4 ) ;
return - V_32 ;
}
V_131 = F_27 ( V_3 , V_4 , V_108 , V_55 , V_114 ,
V_115 , V_116 ) ;
if ( V_131 < 0 )
goto V_134;
if ( V_130 ) {
V_131 = F_36 ( V_13 , V_114 ,
V_115 , V_116 , V_55 -> V_110 ,
V_98 , V_99 ,
V_135 ) ;
if ( V_131 < 0 )
goto V_134;
}
}
return 0 ;
V_134:
return V_131 ;
}
static int F_37 ( struct V_12 * V_13 ,
struct V_123 * V_136 ,
struct V_113 * * V_114 , unsigned * V_116 )
{
struct V_123 * V_137 ;
unsigned V_115 ;
int V_85 ;
* V_114 = NULL ;
* V_116 = 0 ;
V_115 = 0 ;
F_38 (np_config, np) {
V_85 = F_28 ( V_13 , V_137 , V_114 ,
& V_115 , V_116 ) ;
if ( V_85 < 0 ) {
F_39 ( V_13 , * V_114 , * V_116 ) ;
return V_85 ;
}
}
return 0 ;
}
static int F_40 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
return V_3 -> V_102 ;
}
static const char * F_41 ( struct V_12 * V_13 ,
unsigned V_95 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
return V_3 -> V_97 [ V_95 ] . V_110 ;
}
static int F_42 ( struct V_12 * V_13 ,
unsigned V_95 ,
const unsigned * * V_107 ,
unsigned * V_127 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
* V_107 = ( unsigned * ) & V_3 -> V_97 [ V_95 ] . V_4 ;
* V_127 = 1 ;
return 0 ;
}
static int F_43 ( struct V_12 * V_13 )
{
return F_35 ( V_122 ) ;
}
static const char * F_44 ( struct V_12 * V_13 ,
unsigned V_138 )
{
return V_122 [ V_138 ] ;
}
static int F_45 ( struct V_12 * V_13 ,
unsigned V_121 ,
const char * const * * V_97 ,
unsigned * const V_139 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
* V_97 = V_3 -> V_140 ;
* V_139 = V_3 -> V_102 ;
return 0 ;
}
static int F_46 ( struct V_12 * V_13 ,
unsigned long V_4 , unsigned long V_141 )
{
unsigned int V_18 ;
unsigned char V_19 ;
unsigned int V_48 ;
unsigned int V_50 = ( 1L << V_142 ) - 1 ;
struct V_2 * V_3 = F_4 ( V_13 ) ;
V_18 = ( ( V_4 / V_143 ) << V_3 -> V_5 -> V_11 )
+ V_3 -> V_5 -> V_144 ;
V_19 = V_4 % V_143 ;
V_50 <<= ( V_142 * V_19 ) ;
V_48 = ( V_141 << ( V_142 * V_19 ) ) ;
return F_15 ( F_1 ( V_3 , V_4 ) ,
V_18 , V_50 , V_48 ) ;
}
static const struct V_106 *
F_47 ( struct V_2 * V_3 , unsigned int V_145 )
{
int V_40 ;
const struct V_106 * V_4 ;
for ( V_40 = 0 ; V_40 < V_3 -> V_5 -> V_54 ; V_40 ++ ) {
V_4 = V_3 -> V_5 -> V_107 + V_40 ;
if ( V_4 -> V_146 . V_147 == V_145 )
return V_4 ;
}
return NULL ;
}
static int F_48 ( struct V_12 * V_13 ,
unsigned V_121 ,
unsigned V_95 )
{
bool V_85 ;
const struct V_103 * V_148 ;
struct V_2 * V_3 = F_4 ( V_13 ) ;
struct V_100 * V_101 = V_3 -> V_97 + V_95 ;
V_85 = F_26 ( V_3 , V_101 -> V_4 , V_121 ) ;
if ( ! V_85 ) {
F_18 ( V_3 -> V_24 , L_7 ,
V_121 , V_95 ) ;
return - V_32 ;
}
V_148 = F_25 ( V_3 , V_101 -> V_4 , V_121 ) ;
if ( ! V_148 )
return - V_32 ;
F_46 ( V_13 , V_101 -> V_4 , V_148 -> V_111 ) ;
return 0 ;
}
static int F_49 ( struct V_21 * V_22 , unsigned V_16 )
{
return F_50 ( V_22 -> V_149 + V_16 ) ;
}
static void F_51 ( struct V_21 * V_22 , unsigned V_16 )
{
F_52 ( V_22 -> V_149 + V_16 ) ;
}
static int F_53 ( struct V_21 * V_22 ,
unsigned V_16 )
{
return F_54 ( V_22 -> V_149 + V_16 ) ;
}
static int F_55 ( struct V_21 * V_22 ,
unsigned V_16 , int V_23 )
{
F_9 ( V_22 , V_16 , V_23 ) ;
return F_56 ( V_22 -> V_149 + V_16 ) ;
}
static int F_57 ( struct V_21 * V_22 , unsigned V_16 )
{
unsigned int V_18 ;
unsigned int V_19 ;
unsigned int V_150 = 0 ;
struct V_2 * V_3 = F_10 ( V_22 -> V_24 ) ;
V_18 = F_2 ( V_3 , V_16 ) + V_3 -> V_5 -> V_20 ;
V_19 = F_5 ( V_16 & 0xf ) ;
F_58 ( V_3 -> V_9 , V_18 , & V_150 ) ;
return ! ! ( V_150 & V_19 ) ;
}
static int F_59 ( struct V_21 * V_22 , unsigned V_16 )
{
unsigned int V_18 ;
unsigned int V_19 ;
unsigned int V_150 = 0 ;
struct V_2 * V_3 = F_10 ( V_22 -> V_24 ) ;
if ( F_57 ( V_22 , V_16 ) )
V_18 = F_2 ( V_3 , V_16 ) +
V_3 -> V_5 -> V_25 ;
else
V_18 = F_2 ( V_3 , V_16 ) +
V_3 -> V_5 -> V_151 ;
V_19 = F_5 ( V_16 & 0xf ) ;
F_58 ( V_3 -> V_9 , V_18 , & V_150 ) ;
return ! ! ( V_150 & V_19 ) ;
}
static int F_60 ( struct V_21 * V_22 , unsigned V_16 )
{
const struct V_106 * V_4 ;
struct V_2 * V_3 = F_10 ( V_22 -> V_24 ) ;
int V_152 ;
V_4 = V_3 -> V_5 -> V_107 + V_16 ;
if ( V_4 -> V_146 . V_147 == V_153 )
return - V_32 ;
V_152 = F_61 ( V_3 -> V_154 , V_4 -> V_146 . V_147 ) ;
if ( ! V_152 )
return - V_32 ;
return V_152 ;
}
static int F_62 ( struct V_155 * V_156 )
{
struct V_2 * V_3 = F_63 ( V_156 ) ;
const struct V_106 * V_4 ;
int V_85 ;
V_4 = F_47 ( V_3 , V_156 -> V_157 ) ;
if ( ! V_4 ) {
F_18 ( V_3 -> V_24 , L_8 ) ;
return - V_32 ;
}
V_85 = F_64 ( V_3 -> V_22 , V_4 -> V_4 . V_112 ) ;
if ( V_85 ) {
F_18 ( V_3 -> V_24 , L_9 ,
F_65 ( V_156 ) ) ;
return V_85 ;
}
F_46 ( V_3 -> V_158 , V_4 -> V_4 . V_112 , V_4 -> V_146 . V_159 ) ;
return 0 ;
}
static void F_66 ( struct V_155 * V_156 )
{
struct V_2 * V_3 = F_63 ( V_156 ) ;
const struct V_106 * V_4 ;
V_4 = F_47 ( V_3 , V_156 -> V_157 ) ;
if ( ! V_4 ) {
F_18 ( V_3 -> V_24 , L_8 ) ;
return;
}
F_67 ( V_3 -> V_22 , V_4 -> V_4 . V_112 ) ;
}
static void T_2 * F_68 ( struct V_2 * V_3 ,
unsigned int V_145 , unsigned int V_16 )
{
unsigned int V_160 = 0 ;
void T_2 * V_161 ;
if ( V_145 >= V_3 -> V_5 -> V_162 )
V_160 = V_3 -> V_5 -> V_162 ;
V_161 = V_3 -> V_163 + V_16 + ( ( V_145 - V_160 ) / 32 ) * 4 ;
return V_161 ;
}
static unsigned int F_69 ( struct V_2 * V_3 ,
unsigned int V_145 )
{
unsigned int V_164 ;
unsigned int V_19 = F_5 ( V_145 % 32 ) ;
const struct V_165 * V_166 =
& V_3 -> V_5 -> V_166 ;
void T_2 * V_161 = F_68 ( V_3 , V_145 ,
V_166 -> V_164 ) ;
if ( F_70 ( V_161 ) & V_19 )
V_164 = V_167 ;
else
V_164 = V_168 ;
if ( ( V_145 < V_3 -> V_5 -> V_169 ) && ( V_164 != V_168 ) )
return 1 ;
else
return 0 ;
}
static unsigned int F_71 ( struct V_2 * V_3 ,
unsigned int V_145 )
{
unsigned int V_19 = F_5 ( V_145 % 32 ) ;
const struct V_165 * V_166 =
& V_3 -> V_5 -> V_166 ;
void T_2 * V_161 = F_68 ( V_3 , V_145 ,
V_166 -> V_50 ) ;
return ! ! ( F_70 ( V_161 ) & V_19 ) ;
}
static int F_72 ( struct V_2 * V_3 , int V_157 )
{
int V_170 , V_171 ;
unsigned int V_172 ;
const struct V_165 * V_166 = & ( V_3 -> V_5 -> V_166 ) ;
T_1 V_50 = 1 << ( V_157 & 0x1f ) ;
T_1 V_173 = ( V_157 >> 5 ) & V_166 -> V_10 ;
void T_2 * V_161 = V_3 -> V_163 + ( V_173 << 2 ) ;
const struct V_106 * V_4 ;
V_4 = F_47 ( V_3 , V_157 ) ;
V_171 = F_59 ( V_3 -> V_22 , V_4 -> V_4 . V_112 ) ;
do {
V_170 = V_171 ;
if ( V_170 )
V_172 = V_166 -> V_174 ;
else
V_172 = V_166 -> V_175 ;
F_73 ( V_50 , V_161 + V_172 ) ;
V_171 = F_59 ( V_3 -> V_22 , V_4 -> V_4 . V_112 ) ;
} while ( V_170 != V_171 );
return V_170 ;
}
static void F_74 ( struct V_155 * V_156 )
{
struct V_2 * V_3 = F_63 ( V_156 ) ;
const struct V_165 * V_166 =
& V_3 -> V_5 -> V_166 ;
T_1 V_50 = F_5 ( V_156 -> V_157 & 0x1f ) ;
void T_2 * V_161 = F_68 ( V_3 , V_156 -> V_157 ,
V_166 -> V_176 ) ;
F_73 ( V_50 , V_161 ) ;
}
static void F_75 ( struct V_155 * V_156 )
{
struct V_2 * V_3 = F_63 ( V_156 ) ;
const struct V_165 * V_166 =
& V_3 -> V_5 -> V_166 ;
T_1 V_50 = F_5 ( V_156 -> V_157 & 0x1f ) ;
void T_2 * V_161 = F_68 ( V_3 , V_156 -> V_157 ,
V_166 -> V_177 ) ;
F_73 ( V_50 , V_161 ) ;
if ( V_3 -> V_178 [ V_156 -> V_157 ] )
F_72 ( V_3 , V_156 -> V_157 ) ;
}
static int F_76 ( struct V_21 * V_22 , unsigned V_16 ,
unsigned V_179 )
{
struct V_2 * V_3 = F_10 ( V_22 -> V_24 ) ;
int V_145 , V_180 , V_181 ;
unsigned int V_182 , V_19 , V_183 , V_184 , V_185 , V_40 , V_186 , V_187 ;
static const unsigned int V_188 [] = { 0 , 1 , 16 , 32 , 64 , 128 , 256 } ;
const struct V_106 * V_4 ;
struct V_155 * V_156 ;
V_4 = V_3 -> V_5 -> V_107 + V_16 ;
if ( V_4 -> V_146 . V_147 == V_153 )
return - V_32 ;
V_145 = V_4 -> V_146 . V_147 ;
V_180 = F_61 ( V_3 -> V_154 , V_145 ) ;
V_181 = ( V_145 % 4 ) * 8 ;
V_156 = F_77 ( V_180 ) ;
V_182 = ( V_145 / 4 ) * 4 + V_3 -> V_5 -> V_166 . V_189 ;
V_184 = ( V_145 / 4 ) * 4 + V_3 -> V_5 -> V_166 . V_190 ;
if ( ! F_69 ( V_3 , V_145 ) )
return - V_191 ;
V_187 = F_35 ( V_188 ) ;
for ( V_40 = 0 ; V_40 < F_35 ( V_188 ) ; V_40 ++ ) {
if ( V_179 <= V_188 [ V_40 ] ) {
V_187 = V_40 ;
break;
}
}
if ( ! F_71 ( V_3 , V_145 ) ) {
F_74 ( V_156 ) ;
V_186 = 1 ;
} else {
V_186 = 0 ;
}
V_183 = 0xff << V_181 ;
F_73 ( V_183 , V_3 -> V_163 + V_184 ) ;
V_19 = ( ( V_187 << V_192 ) | V_193 ) <<
V_181 ;
V_185 = V_194 << V_181 ;
F_73 ( V_185 | V_19 , V_3 -> V_163 + V_182 ) ;
F_78 ( 1 ) ;
if ( V_186 == 1 )
F_75 ( V_156 ) ;
return 0 ;
}
static int F_79 ( struct V_155 * V_156 ,
unsigned int type )
{
struct V_2 * V_3 = F_63 ( V_156 ) ;
const struct V_165 * V_166 =
& V_3 -> V_5 -> V_166 ;
T_1 V_50 = F_5 ( V_156 -> V_157 & 0x1f ) ;
void T_2 * V_161 ;
if ( ( ( type & V_195 ) && ( type & V_196 ) ) ||
( ( type & V_196 ) == V_196 ) ) {
F_18 ( V_3 -> V_24 , L_10 ,
V_156 -> V_152 , V_156 -> V_157 , type ) ;
return - V_32 ;
}
if ( ( type & V_195 ) == V_195 )
V_3 -> V_178 [ V_156 -> V_157 ] = 1 ;
else
V_3 -> V_178 [ V_156 -> V_157 ] = 0 ;
if ( type & ( V_197 | V_198 ) ) {
V_161 = F_68 ( V_3 , V_156 -> V_157 ,
V_166 -> V_174 ) ;
F_73 ( V_50 , V_161 ) ;
} else {
V_161 = F_68 ( V_3 , V_156 -> V_157 ,
V_166 -> V_175 ) ;
F_73 ( V_50 , V_161 ) ;
}
if ( type & ( V_199 | V_198 ) ) {
V_161 = F_68 ( V_3 , V_156 -> V_157 ,
V_166 -> V_200 ) ;
F_73 ( V_50 , V_161 ) ;
} else {
V_161 = F_68 ( V_3 , V_156 -> V_157 ,
V_166 -> V_201 ) ;
F_73 ( V_50 , V_161 ) ;
}
if ( V_3 -> V_178 [ V_156 -> V_157 ] )
F_72 ( V_3 , V_156 -> V_157 ) ;
return 0 ;
}
static int F_80 ( struct V_155 * V_156 , unsigned int V_202 )
{
struct V_2 * V_3 = F_63 ( V_156 ) ;
int V_51 = V_156 -> V_157 & 0x1f ;
int V_161 = V_156 -> V_157 >> 5 ;
if ( V_202 )
V_3 -> V_203 [ V_161 ] |= F_5 ( V_51 ) ;
else
V_3 -> V_203 [ V_161 ] &= ~ F_5 ( V_51 ) ;
return 0 ;
}
static void F_81 ( const struct V_165 * V_22 ,
void T_2 * V_163 , T_1 * V_204 )
{
int V_173 ;
void T_2 * V_161 ;
for ( V_173 = 0 ; V_173 < V_22 -> V_205 ; V_173 ++ ) {
V_161 = V_163 + ( V_173 << 2 ) ;
F_82 ( ~ V_204 [ V_173 ] , V_161 + V_22 -> V_176 ) ;
F_82 ( V_204 [ V_173 ] , V_161 + V_22 -> V_177 ) ;
}
}
static void F_83 ( const struct V_165 * V_22 ,
void T_2 * V_163 , T_1 * V_204 )
{
int V_173 ;
void T_2 * V_161 ;
for ( V_173 = 0 ; V_173 < V_22 -> V_205 ; V_173 ++ ) {
V_161 = V_163 + V_22 -> V_50 + ( V_173 << 2 ) ;
V_204 [ V_173 ] = ~ F_84 ( V_161 ) ;
}
}
static int F_85 ( struct V_206 * V_206 )
{
void T_2 * V_161 ;
struct V_2 * V_3 = F_10 ( V_206 ) ;
const struct V_165 * V_166 =
& V_3 -> V_5 -> V_166 ;
V_161 = V_3 -> V_163 ;
F_83 ( V_166 , V_161 , V_3 -> V_207 ) ;
F_81 ( V_166 , V_161 , V_3 -> V_203 ) ;
return 0 ;
}
static int F_86 ( struct V_206 * V_206 )
{
struct V_2 * V_3 = F_10 ( V_206 ) ;
const struct V_165 * V_166 =
& V_3 -> V_5 -> V_166 ;
F_81 ( V_166 ,
V_3 -> V_163 , V_3 -> V_207 ) ;
return 0 ;
}
static void F_87 ( struct V_155 * V_156 )
{
struct V_2 * V_3 = F_63 ( V_156 ) ;
const struct V_165 * V_166 =
& V_3 -> V_5 -> V_166 ;
T_1 V_50 = F_5 ( V_156 -> V_157 & 0x1f ) ;
void T_2 * V_161 = F_68 ( V_3 , V_156 -> V_157 ,
V_166 -> V_208 ) ;
F_73 ( V_50 , V_161 ) ;
}
static unsigned int F_88 ( struct V_2 * V_3 )
{
const struct V_165 * V_166 =
& V_3 -> V_5 -> V_166 ;
void T_2 * V_161 = V_3 -> V_163 + V_166 -> V_209 ;
unsigned int V_40 ;
for ( V_40 = 0 ; V_40 < V_3 -> V_5 -> V_162 ; V_40 += 32 ) {
F_73 ( 0xffffffff , V_161 ) ;
V_161 += 4 ;
}
return 0 ;
}
static inline void
F_89 ( struct V_2 * V_3 , int V_210 )
{
unsigned int V_185 , V_211 ;
unsigned int V_19 , V_187 ;
const struct V_165 * V_166 =
& V_3 -> V_5 -> V_166 ;
V_211 = ( V_210 / 4 ) * 4 + V_166 -> V_212 ;
V_187 = F_70 ( V_3 -> V_163 + V_211 ) ;
V_19 = V_193 << ( ( V_210 % 4 ) * 8 ) ;
if ( ( V_19 & V_187 ) > 0 ) {
V_211 = ( V_210 / 4 ) * 4 + V_166 -> V_189 ;
V_185 = V_194 << ( ( V_210 % 4 ) * 8 ) ;
F_73 ( V_185 , V_3 -> V_163 + V_211 ) ;
}
}
static void F_90 ( struct V_213 * V_148 )
{
struct V_214 * V_22 = F_91 ( V_148 ) ;
struct V_2 * V_3 = F_92 ( V_148 ) ;
unsigned int V_215 , V_145 ;
int V_16 , V_210 , V_180 ;
const struct V_165 * V_166 =
& V_3 -> V_5 -> V_166 ;
void T_2 * V_161 = F_68 ( V_3 , 0 , V_166 -> V_216 ) ;
int V_217 , V_170 , V_171 ;
const struct V_106 * V_4 ;
F_93 ( V_22 , V_148 ) ;
for ( V_145 = 0 ; V_145 < V_3 -> V_5 -> V_162 ; V_145 += 32 ) {
V_215 = F_70 ( V_161 ) ;
V_161 += 4 ;
while ( V_215 ) {
V_16 = F_94 ( V_215 ) ;
V_210 = V_145 + V_16 ;
V_180 = F_61 ( V_3 -> V_154 , V_210 ) ;
V_215 &= ~ F_5 ( V_16 ) ;
V_217 = V_3 -> V_178 [ V_210 ] ;
if ( V_217 ) {
F_73 ( F_5 ( V_16 ) , V_161 - V_166 -> V_216 +
V_166 -> V_218 ) ;
V_4 = F_47 ( V_3 , V_210 ) ;
V_170 = F_59 ( V_3 -> V_22 ,
V_4 -> V_4 . V_112 ) ;
}
F_95 ( V_180 ) ;
if ( V_217 ) {
V_171 = F_72 ( V_3 , V_210 ) ;
if ( V_170 != V_171 )
F_73 ( F_5 ( V_16 ) , V_161 -
V_166 -> V_216 +
V_166 -> V_219 ) ;
}
if ( V_210 < V_3 -> V_5 -> V_169 )
F_89 ( V_3 , V_210 ) ;
}
}
F_96 ( V_22 , V_148 ) ;
}
static int F_97 ( struct V_220 * V_221 )
{
struct V_2 * V_3 = F_98 ( V_221 ) ;
int V_40 ;
V_3 -> V_102 = V_3 -> V_5 -> V_54 ;
V_3 -> V_97 = F_99 ( & V_221 -> V_24 , V_3 -> V_102 ,
sizeof( * V_3 -> V_97 ) , V_222 ) ;
if ( ! V_3 -> V_97 )
return - V_223 ;
V_3 -> V_140 = F_99 ( & V_221 -> V_24 , V_3 -> V_102 ,
sizeof( * V_3 -> V_140 ) , V_222 ) ;
if ( ! V_3 -> V_140 )
return - V_223 ;
for ( V_40 = 0 ; V_40 < V_3 -> V_5 -> V_54 ; V_40 ++ ) {
const struct V_106 * V_4 = V_3 -> V_5 -> V_107 + V_40 ;
struct V_100 * V_95 = V_3 -> V_97 + V_40 ;
V_95 -> V_110 = V_4 -> V_4 . V_110 ;
V_95 -> V_4 = V_4 -> V_4 . V_112 ;
V_3 -> V_140 [ V_40 ] = V_4 -> V_4 . V_110 ;
}
return 0 ;
}
int F_100 ( struct V_220 * V_221 ,
const struct V_224 * V_119 ,
struct V_1 * V_1 )
{
struct V_225 * V_107 ;
struct V_2 * V_3 ;
struct V_123 * V_137 = V_221 -> V_24 . V_226 , * V_124 ;
struct V_125 * V_227 ;
struct V_228 * V_229 ;
int V_40 , V_85 , V_152 , V_230 ;
V_3 = F_101 ( & V_221 -> V_24 , sizeof( * V_3 ) , V_222 ) ;
if ( ! V_3 )
return - V_223 ;
F_102 ( V_221 , V_3 ) ;
V_227 = F_29 ( V_137 , L_11 , NULL ) ;
if ( ! V_227 ) {
F_18 ( & V_221 -> V_24 , L_12 ) ;
return - V_32 ;
}
V_124 = F_103 ( V_137 , L_13 , 0 ) ;
if ( V_124 ) {
V_3 -> V_9 = F_104 ( V_124 ) ;
if ( F_105 ( V_3 -> V_9 ) )
return F_106 ( V_3 -> V_9 ) ;
} else if ( V_1 ) {
V_3 -> V_9 = V_1 ;
} else {
F_18 ( & V_221 -> V_24 , L_14 ) ;
return - V_32 ;
}
V_124 = F_103 ( V_137 , L_13 , 1 ) ;
if ( V_124 ) {
V_3 -> V_8 = F_104 ( V_124 ) ;
if ( F_105 ( V_3 -> V_8 ) )
return F_106 ( V_3 -> V_8 ) ;
}
V_3 -> V_5 = V_119 ;
V_85 = F_97 ( V_221 ) ;
if ( V_85 ) {
F_18 ( & V_221 -> V_24 , L_15 , V_85 ) ;
return - V_32 ;
}
V_107 = F_99 ( & V_221 -> V_24 , V_3 -> V_5 -> V_54 , sizeof( * V_107 ) ,
V_222 ) ;
if ( ! V_107 )
return - V_223 ;
for ( V_40 = 0 ; V_40 < V_3 -> V_5 -> V_54 ; V_40 ++ )
V_107 [ V_40 ] = V_3 -> V_5 -> V_107 [ V_40 ] . V_4 ;
V_3 -> V_231 . V_110 = F_107 ( & V_221 -> V_24 ) ;
V_3 -> V_231 . V_232 = V_233 ;
V_3 -> V_231 . V_107 = V_107 ;
V_3 -> V_231 . V_54 = V_3 -> V_5 -> V_54 ;
V_3 -> V_231 . V_234 = & V_235 ;
V_3 -> V_231 . V_236 = & V_237 ;
V_3 -> V_231 . V_238 = & V_239 ;
V_3 -> V_24 = & V_221 -> V_24 ;
V_3 -> V_158 = F_108 ( & V_3 -> V_231 , & V_221 -> V_24 , V_3 ) ;
if ( F_105 ( V_3 -> V_158 ) ) {
F_18 ( & V_221 -> V_24 , L_16 ) ;
return F_106 ( V_3 -> V_158 ) ;
}
V_3 -> V_22 = F_101 ( & V_221 -> V_24 , sizeof( * V_3 -> V_22 ) , V_222 ) ;
if ( ! V_3 -> V_22 ) {
V_85 = - V_223 ;
goto V_240;
}
* V_3 -> V_22 = V_241 ;
V_3 -> V_22 -> V_242 = V_3 -> V_5 -> V_54 ;
V_3 -> V_22 -> V_243 = F_107 ( & V_221 -> V_24 ) ;
V_3 -> V_22 -> V_24 = & V_221 -> V_24 ;
V_3 -> V_22 -> V_149 = - 1 ;
V_85 = F_109 ( V_3 -> V_22 ) ;
if ( V_85 ) {
V_85 = - V_32 ;
goto V_240;
}
V_85 = F_110 ( V_3 -> V_22 , F_107 ( & V_221 -> V_24 ) ,
0 , 0 , V_3 -> V_5 -> V_54 ) ;
if ( V_85 ) {
V_85 = - V_32 ;
goto V_244;
}
if ( ! F_111 ( V_137 , L_17 ) )
return 0 ;
V_229 = F_112 ( V_221 , V_245 , 0 ) ;
if ( ! V_229 ) {
F_18 ( & V_221 -> V_24 , L_18 ) ;
V_85 = - V_32 ;
goto V_244;
}
V_3 -> V_163 = F_113 ( & V_221 -> V_24 , V_229 ) ;
if ( F_105 ( V_3 -> V_163 ) ) {
V_85 = - V_32 ;
goto V_244;
}
V_230 = V_3 -> V_5 -> V_166 . V_205 ;
V_3 -> V_203 = F_99 ( & V_221 -> V_24 , V_230 ,
sizeof( * V_3 -> V_203 ) , V_222 ) ;
if ( ! V_3 -> V_203 ) {
V_85 = - V_223 ;
goto V_244;
}
V_3 -> V_207 = F_99 ( & V_221 -> V_24 , V_230 ,
sizeof( * V_3 -> V_207 ) , V_222 ) ;
if ( ! V_3 -> V_207 ) {
V_85 = - V_223 ;
goto V_244;
}
V_3 -> V_178 = F_99 ( & V_221 -> V_24 , V_3 -> V_5 -> V_162 ,
sizeof( int ) , V_222 ) ;
if ( ! V_3 -> V_178 ) {
V_85 = - V_223 ;
goto V_244;
}
V_152 = F_114 ( V_137 , 0 ) ;
if ( ! V_152 ) {
F_18 ( & V_221 -> V_24 , L_19 ) ;
V_85 = - V_32 ;
goto V_244;
}
V_3 -> V_154 = F_115 ( V_137 ,
V_3 -> V_5 -> V_162 , & V_246 , NULL ) ;
if ( ! V_3 -> V_154 ) {
F_18 ( & V_221 -> V_24 , L_20 ) ;
V_85 = - V_223 ;
goto V_244;
}
F_88 ( V_3 ) ;
for ( V_40 = 0 ; V_40 < V_3 -> V_5 -> V_162 ; V_40 ++ ) {
int V_180 = F_116 ( V_3 -> V_154 , V_40 ) ;
F_117 ( V_180 , & V_247 ,
V_248 ) ;
F_118 ( V_180 , V_3 ) ;
} ;
F_119 ( V_152 , F_90 , V_3 ) ;
return 0 ;
V_244:
F_120 ( V_3 -> V_22 ) ;
V_240:
F_121 ( V_3 -> V_158 ) ;
return V_85 ;
}

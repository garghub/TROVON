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
struct V_2 * V_3 = F_10 ( V_22 ) ;
V_18 = F_2 ( V_3 , V_16 ) + V_3 -> V_5 -> V_24 ;
V_19 = F_5 ( V_16 & 0xf ) ;
if ( V_23 )
V_18 = F_7 ( V_18 , V_3 ) ;
else
V_18 = F_6 ( V_18 , V_3 ) ;
F_8 ( F_1 ( V_3 , V_16 ) , V_18 , V_19 ) ;
}
static int F_11 ( struct V_2 * V_3 , unsigned V_4 ,
int V_23 , enum V_25 V_26 )
{
unsigned int V_18 , V_16 ;
unsigned int V_19 ;
if ( ! V_3 -> V_5 -> V_27 &&
V_3 -> V_5 -> V_28 == V_29 &&
V_26 == V_30 )
return - V_31 ;
if ( ! V_3 -> V_5 -> V_27 &&
V_3 -> V_5 -> V_32 == V_29 &&
V_26 == V_33 )
return - V_31 ;
if ( V_3 -> V_5 -> V_27 ) {
return V_3 -> V_5 -> V_27 ( F_1 ( V_3 , V_4 ) ,
V_4 , V_3 -> V_5 -> V_34 , V_23 , V_26 ) ;
}
V_19 = F_5 ( V_4 & 0xf ) ;
if ( V_26 == V_30 )
V_16 = V_3 -> V_5 -> V_28 ;
else
V_16 = V_3 -> V_5 -> V_32 ;
if ( V_23 )
V_18 = F_7 ( F_2 ( V_3 , V_4 ) + V_16 , V_3 ) ;
else
V_18 = F_6 ( F_2 ( V_3 , V_4 ) + V_16 , V_3 ) ;
F_8 ( F_1 ( V_3 , V_4 ) , V_18 , V_19 ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_1 ,
const struct V_35 * V_36 , unsigned int V_37 ,
unsigned int V_4 , unsigned char V_38 , int V_23 )
{
unsigned int V_39 , V_18 , V_19 ;
for ( V_39 = 0 ; V_39 < V_37 ; V_39 ++ ) {
if ( V_4 >= V_36 [ V_39 ] . V_40 &&
V_4 <= V_36 [ V_39 ] . V_41 ) {
break;
}
}
if ( V_39 == V_37 )
return - V_31 ;
if ( V_23 )
V_18 = V_36 [ V_39 ] . V_16 + V_38 ;
else
V_18 = V_36 [ V_39 ] . V_16 + ( V_38 << 1 ) ;
V_19 = F_5 ( V_36 [ V_39 ] . V_19 ) ;
F_8 ( V_1 , V_18 , V_19 ) ;
return 0 ;
}
static const struct V_42 * F_13 (
struct V_2 * V_3 , unsigned long V_4 ) {
int V_39 ;
for ( V_39 = 0 ; V_39 < V_3 -> V_5 -> V_43 ; V_39 ++ ) {
const struct V_42 * V_44 =
V_3 -> V_5 -> V_45 + V_39 ;
if ( V_4 == V_44 -> V_4 )
return V_44 ;
}
return NULL ;
}
static int F_14 ( struct V_2 * V_3 ,
unsigned int V_4 , unsigned char V_46 )
{
const struct V_42 * V_44 ;
unsigned int V_47 ;
unsigned int V_48 , V_49 , V_50 ;
const struct V_51 * V_52 ;
if ( V_4 >= V_3 -> V_5 -> V_53 )
return - V_31 ;
V_44 = F_13 ( V_3 , V_4 ) ;
if ( ! V_44 || V_44 -> V_54 > V_3 -> V_5 -> V_55 )
return - V_31 ;
V_52 = V_3 -> V_5 -> V_56 + V_44 -> V_54 ;
if ( V_46 >= V_52 -> V_57 && V_46 <= V_52 -> V_58
&& ! ( V_46 % V_52 -> V_59 ) ) {
V_47 = V_46 / V_52 -> V_59 - 1 ;
V_48 = V_52 -> V_60 - V_52 -> V_61 + 1 ;
V_49 = F_5 ( V_48 ) - 1 ;
V_50 = V_44 -> V_19 + V_52 -> V_61 ;
V_49 <<= V_50 ;
V_47 <<= V_50 ;
return F_15 ( F_1 ( V_3 , V_4 ) ,
V_44 -> V_16 , V_49 , V_47 ) ;
}
return - V_31 ;
}
int F_16 ( struct V_1 * V_1 ,
const struct V_62 * V_63 ,
unsigned int V_37 , unsigned int V_4 ,
unsigned char V_38 , bool V_64 , unsigned int V_65 )
{
unsigned int V_39 ;
unsigned int V_66 , V_67 , V_68 ;
unsigned int V_69 , V_70 , V_71 ;
const struct V_62 * V_72 ;
bool V_73 = false ;
for ( V_39 = 0 ; V_39 < V_37 ; V_39 ++ ) {
if ( V_4 == V_63 [ V_39 ] . V_4 ) {
V_73 = true ;
break;
}
}
if ( ! V_73 )
return - V_31 ;
V_72 = V_63 + V_39 ;
V_67 = V_72 -> V_16 + V_38 ;
V_68 = V_72 -> V_16 + ( V_38 << 1 ) ;
if ( V_64 )
V_66 = V_68 ;
else
V_66 = V_67 ;
V_69 = F_5 ( V_72 -> V_74 ) ;
F_8 ( V_1 , V_66 , V_69 ) ;
V_70 = F_5 ( V_72 -> V_75 ) ;
V_71 = F_5 ( V_72 -> V_76 ) ;
switch ( V_65 ) {
case V_77 :
F_8 ( V_1 , V_68 , V_70 ) ;
F_8 ( V_1 , V_68 , V_71 ) ;
break;
case V_78 :
F_8 ( V_1 , V_67 , V_70 ) ;
F_8 ( V_1 , V_68 , V_71 ) ;
break;
case V_79 :
F_8 ( V_1 , V_68 , V_70 ) ;
F_8 ( V_1 , V_67 , V_71 ) ;
break;
case V_80 :
F_8 ( V_1 , V_67 , V_70 ) ;
F_8 ( V_1 , V_67 , V_71 ) ;
break;
default:
return - V_31 ;
}
return 0 ;
}
static int F_17 ( struct V_2 * V_3 ,
unsigned int V_4 , bool V_81 , bool V_64 , unsigned int V_26 )
{
unsigned int V_19 ;
unsigned int V_82 , V_83 ;
int V_84 ;
if ( V_3 -> V_5 -> V_85 ) {
V_84 = V_3 -> V_5 -> V_85 ( F_1 ( V_3 , V_4 ) ,
V_4 , V_3 -> V_5 -> V_34 , V_64 , V_26 ) ;
if ( ! V_84 )
return 0 ;
}
if ( V_26 != 0 && V_26 != 1 ) {
F_18 ( V_3 -> V_86 , L_1 ,
V_26 , V_4 ) ;
return - V_31 ;
}
V_19 = F_5 ( V_4 & 0xf ) ;
if ( V_81 )
V_82 = F_7 ( F_2 ( V_3 , V_4 ) +
V_3 -> V_5 -> V_87 , V_3 ) ;
else
V_82 = F_6 ( F_2 ( V_3 , V_4 ) +
V_3 -> V_5 -> V_87 , V_3 ) ;
if ( V_64 )
V_83 = F_7 ( F_2 ( V_3 , V_4 ) +
V_3 -> V_5 -> V_88 , V_3 ) ;
else
V_83 = F_6 ( F_2 ( V_3 , V_4 ) +
V_3 -> V_5 -> V_88 , V_3 ) ;
F_8 ( F_1 ( V_3 , V_4 ) , V_82 , V_19 ) ;
F_8 ( F_1 ( V_3 , V_4 ) , V_83 , V_19 ) ;
return 0 ;
}
static int F_19 ( struct V_12 * V_13 ,
unsigned int V_4 , enum V_25 V_89 ,
enum V_25 V_26 )
{
int V_84 = 0 ;
struct V_2 * V_3 = F_4 ( V_13 ) ;
switch ( V_89 ) {
case V_90 :
V_84 = F_17 ( V_3 , V_4 , false , false , V_26 ) ;
break;
case V_91 :
V_84 = F_17 ( V_3 , V_4 , true , true , V_26 ) ;
break;
case V_92 :
V_84 = F_17 ( V_3 , V_4 , true , false , V_26 ) ;
break;
case V_30 :
F_3 ( V_13 , NULL , V_4 , true ) ;
V_84 = F_11 ( V_3 , V_4 , V_26 , V_89 ) ;
break;
case V_93 :
F_9 ( V_3 -> V_22 , V_4 , V_26 ) ;
V_84 = F_3 ( V_13 , NULL , V_4 , false ) ;
break;
case V_33 :
F_3 ( V_13 , NULL , V_4 , true ) ;
V_84 = F_11 ( V_3 , V_4 , V_26 , V_89 ) ;
break;
case V_94 :
V_84 = F_14 ( V_3 , V_4 , V_26 ) ;
break;
default:
V_84 = - V_31 ;
}
return V_84 ;
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
int V_39 , V_84 ;
for ( V_39 = 0 ; V_39 < V_99 ; V_39 ++ ) {
V_84 = F_19 ( V_13 , V_101 -> V_4 ,
F_22 ( V_98 [ V_39 ] ) ,
F_23 ( V_98 [ V_39 ] ) ) ;
if ( V_84 < 0 )
return V_84 ;
V_101 -> V_96 = V_98 [ V_39 ] ;
}
return 0 ;
}
static struct V_100 *
F_24 ( struct V_2 * V_3 , T_1 V_4 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_3 -> V_102 ; V_39 ++ ) {
struct V_100 * V_54 = V_3 -> V_97 + V_39 ;
if ( V_54 -> V_4 == V_4 )
return V_54 ;
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
int V_39 ;
for ( V_39 = 0 ; V_39 < V_3 -> V_5 -> V_53 ; V_39 ++ ) {
const struct V_106 * V_4 = V_3 -> V_5 -> V_107 + V_39 ;
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
T_1 V_4 , T_1 V_105 , struct V_100 * V_54 ,
struct V_113 * * V_114 , unsigned * V_115 ,
unsigned * V_116 )
{
bool V_84 ;
if ( * V_116 == * V_115 )
return - V_117 ;
( * V_114 ) [ * V_116 ] . type = V_118 ;
( * V_114 ) [ * V_116 ] . V_119 . V_120 . V_95 = V_54 -> V_110 ;
V_84 = F_26 ( V_3 , V_4 , V_105 ) ;
if ( ! V_84 ) {
F_18 ( V_3 -> V_86 , L_2 ,
V_105 , V_4 ) ;
return - V_31 ;
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
int V_39 , V_131 ;
unsigned V_132 = 0 ;
struct V_100 * V_54 ;
struct V_2 * V_3 = F_4 ( V_13 ) ;
V_107 = F_29 ( V_124 , L_3 , NULL ) ;
if ( ! V_107 ) {
F_18 ( V_3 -> V_86 , L_4 ,
V_124 -> V_110 ) ;
return - V_31 ;
}
V_131 = F_30 ( V_124 , V_13 , & V_98 ,
& V_99 ) ;
if ( V_131 )
return V_131 ;
if ( V_99 )
V_130 = 1 ;
V_127 = V_107 -> V_133 / sizeof( T_1 ) ;
V_128 = V_127 ;
V_129 = 0 ;
if ( V_128 )
V_129 ++ ;
if ( V_130 && V_127 >= 1 )
V_129 ++ ;
if ( ! V_127 || ! V_129 ) {
V_131 = - V_31 ;
goto exit;
}
V_132 = V_127 * V_129 ;
V_131 = F_31 ( V_13 , V_114 ,
V_115 , V_116 , V_132 ) ;
if ( V_131 < 0 )
goto exit;
for ( V_39 = 0 ; V_39 < V_127 ; V_39 ++ ) {
V_131 = F_32 ( V_124 , L_3 ,
V_39 , & V_126 ) ;
if ( V_131 )
goto exit;
V_4 = F_33 ( V_126 ) ;
V_108 = F_34 ( V_126 ) ;
if ( V_4 >= V_3 -> V_5 -> V_53 ||
V_108 >= F_35 ( V_122 ) ) {
F_18 ( V_3 -> V_86 , L_5 ) ;
V_131 = - V_31 ;
goto exit;
}
V_54 = F_24 ( V_3 , V_4 ) ;
if ( ! V_54 ) {
F_18 ( V_3 -> V_86 , L_6 ,
V_4 ) ;
V_131 = - V_31 ;
goto exit;
}
V_131 = F_27 ( V_3 , V_4 , V_108 , V_54 , V_114 ,
V_115 , V_116 ) ;
if ( V_131 < 0 )
goto exit;
if ( V_130 ) {
V_131 = F_36 ( V_13 , V_114 ,
V_115 , V_116 , V_54 -> V_110 ,
V_98 , V_99 ,
V_134 ) ;
if ( V_131 < 0 )
goto exit;
}
}
V_131 = 0 ;
exit:
F_37 ( V_98 ) ;
return V_131 ;
}
static int F_38 ( struct V_12 * V_13 ,
struct V_123 * V_135 ,
struct V_113 * * V_114 , unsigned * V_116 )
{
struct V_123 * V_136 ;
unsigned V_115 ;
int V_84 ;
* V_114 = NULL ;
* V_116 = 0 ;
V_115 = 0 ;
F_39 (np_config, np) {
V_84 = F_28 ( V_13 , V_136 , V_114 ,
& V_115 , V_116 ) ;
if ( V_84 < 0 ) {
F_40 ( V_13 , * V_114 , * V_116 ) ;
F_41 ( V_136 ) ;
return V_84 ;
}
}
return 0 ;
}
static int F_42 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
return V_3 -> V_102 ;
}
static const char * F_43 ( struct V_12 * V_13 ,
unsigned V_95 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
return V_3 -> V_97 [ V_95 ] . V_110 ;
}
static int F_44 ( struct V_12 * V_13 ,
unsigned V_95 ,
const unsigned * * V_107 ,
unsigned * V_127 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
* V_107 = ( unsigned * ) & V_3 -> V_97 [ V_95 ] . V_4 ;
* V_127 = 1 ;
return 0 ;
}
static int F_45 ( struct V_12 * V_13 )
{
return F_35 ( V_122 ) ;
}
static const char * F_46 ( struct V_12 * V_13 ,
unsigned V_137 )
{
return V_122 [ V_137 ] ;
}
static int F_47 ( struct V_12 * V_13 ,
unsigned V_121 ,
const char * const * * V_97 ,
unsigned * const V_138 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
* V_97 = V_3 -> V_139 ;
* V_138 = V_3 -> V_102 ;
return 0 ;
}
static int F_48 ( struct V_12 * V_13 ,
unsigned long V_4 , unsigned long V_140 )
{
unsigned int V_18 ;
unsigned char V_19 ;
unsigned int V_47 ;
unsigned int V_49 = ( 1L << V_141 ) - 1 ;
struct V_2 * V_3 = F_4 ( V_13 ) ;
V_18 = ( ( V_4 / V_142 ) << V_3 -> V_5 -> V_11 )
+ V_3 -> V_5 -> V_143 ;
V_19 = V_4 % V_142 ;
V_49 <<= ( V_141 * V_19 ) ;
V_47 = ( V_140 << ( V_141 * V_19 ) ) ;
return F_15 ( F_1 ( V_3 , V_4 ) ,
V_18 , V_49 , V_47 ) ;
}
static const struct V_106 *
F_49 ( struct V_2 * V_3 , unsigned int V_144 )
{
int V_39 ;
const struct V_106 * V_4 ;
for ( V_39 = 0 ; V_39 < V_3 -> V_5 -> V_53 ; V_39 ++ ) {
V_4 = V_3 -> V_5 -> V_107 + V_39 ;
if ( V_4 -> V_145 . V_146 == V_144 )
return V_4 ;
}
return NULL ;
}
static int F_50 ( struct V_12 * V_13 ,
unsigned V_121 ,
unsigned V_95 )
{
bool V_84 ;
const struct V_103 * V_147 ;
struct V_2 * V_3 = F_4 ( V_13 ) ;
struct V_100 * V_101 = V_3 -> V_97 + V_95 ;
V_84 = F_26 ( V_3 , V_101 -> V_4 , V_121 ) ;
if ( ! V_84 ) {
F_18 ( V_3 -> V_86 , L_7 ,
V_121 , V_95 ) ;
return - V_31 ;
}
V_147 = F_25 ( V_3 , V_101 -> V_4 , V_121 ) ;
if ( ! V_147 )
return - V_31 ;
F_48 ( V_13 , V_101 -> V_4 , V_147 -> V_111 ) ;
return 0 ;
}
static int F_51 ( struct V_21 * V_22 ,
unsigned V_16 )
{
return F_52 ( V_22 -> V_148 + V_16 ) ;
}
static int F_53 ( struct V_21 * V_22 ,
unsigned V_16 , int V_23 )
{
F_9 ( V_22 , V_16 , V_23 ) ;
return F_54 ( V_22 -> V_148 + V_16 ) ;
}
static int F_55 ( struct V_21 * V_22 , unsigned V_16 )
{
unsigned int V_18 ;
unsigned int V_19 ;
unsigned int V_149 = 0 ;
struct V_2 * V_3 = F_10 ( V_22 ) ;
V_18 = F_2 ( V_3 , V_16 ) + V_3 -> V_5 -> V_20 ;
V_19 = F_5 ( V_16 & 0xf ) ;
F_56 ( V_3 -> V_9 , V_18 , & V_149 ) ;
return ! ( V_149 & V_19 ) ;
}
static int F_57 ( struct V_21 * V_22 , unsigned V_16 )
{
unsigned int V_18 ;
unsigned int V_19 ;
unsigned int V_149 = 0 ;
struct V_2 * V_3 = F_10 ( V_22 ) ;
V_18 = F_2 ( V_3 , V_16 ) +
V_3 -> V_5 -> V_150 ;
V_19 = F_5 ( V_16 & 0xf ) ;
F_56 ( V_3 -> V_9 , V_18 , & V_149 ) ;
return ! ! ( V_149 & V_19 ) ;
}
static int F_58 ( struct V_21 * V_22 , unsigned V_16 )
{
const struct V_106 * V_4 ;
struct V_2 * V_3 = F_10 ( V_22 ) ;
int V_151 ;
V_4 = V_3 -> V_5 -> V_107 + V_16 ;
if ( V_4 -> V_145 . V_146 == V_152 )
return - V_31 ;
V_151 = F_59 ( V_3 -> V_153 , V_4 -> V_145 . V_146 ) ;
if ( ! V_151 )
return - V_31 ;
return V_151 ;
}
static int F_60 ( struct V_154 * V_155 )
{
struct V_2 * V_3 = F_61 ( V_155 ) ;
const struct V_106 * V_4 ;
int V_84 ;
V_4 = F_49 ( V_3 , V_155 -> V_156 ) ;
if ( ! V_4 ) {
F_18 ( V_3 -> V_86 , L_8 ) ;
return - V_31 ;
}
V_84 = F_62 ( V_3 -> V_22 , V_4 -> V_4 . V_112 ) ;
if ( V_84 ) {
F_18 ( V_3 -> V_86 , L_9 ,
F_63 ( V_155 ) ) ;
return V_84 ;
}
F_48 ( V_3 -> V_157 , V_4 -> V_4 . V_112 , V_4 -> V_145 . V_158 ) ;
return 0 ;
}
static void F_64 ( struct V_154 * V_155 )
{
struct V_2 * V_3 = F_61 ( V_155 ) ;
const struct V_106 * V_4 ;
V_4 = F_49 ( V_3 , V_155 -> V_156 ) ;
if ( ! V_4 ) {
F_18 ( V_3 -> V_86 , L_8 ) ;
return;
}
F_65 ( V_3 -> V_22 , V_4 -> V_4 . V_112 ) ;
}
static void T_2 * F_66 ( struct V_2 * V_3 ,
unsigned int V_144 , unsigned int V_16 )
{
unsigned int V_159 = 0 ;
void T_2 * V_160 ;
if ( V_144 >= V_3 -> V_5 -> V_161 )
V_159 = V_3 -> V_5 -> V_161 ;
V_160 = V_3 -> V_162 + V_16 + ( ( V_144 - V_159 ) / 32 ) * 4 ;
return V_160 ;
}
static unsigned int F_67 ( struct V_2 * V_3 ,
unsigned int V_144 )
{
unsigned int V_163 ;
unsigned int V_19 = F_5 ( V_144 % 32 ) ;
const struct V_164 * V_165 =
& V_3 -> V_5 -> V_165 ;
void T_2 * V_160 = F_66 ( V_3 , V_144 ,
V_165 -> V_163 ) ;
if ( F_68 ( V_160 ) & V_19 )
V_163 = V_166 ;
else
V_163 = V_167 ;
if ( ( V_144 < V_3 -> V_5 -> V_168 ) && ( V_163 != V_167 ) )
return 1 ;
else
return 0 ;
}
static unsigned int F_69 ( struct V_2 * V_3 ,
unsigned int V_144 )
{
unsigned int V_19 = F_5 ( V_144 % 32 ) ;
const struct V_164 * V_165 =
& V_3 -> V_5 -> V_165 ;
void T_2 * V_160 = F_66 ( V_3 , V_144 ,
V_165 -> V_49 ) ;
return ! ! ( F_68 ( V_160 ) & V_19 ) ;
}
static int F_70 ( struct V_2 * V_3 , int V_156 )
{
int V_169 , V_170 ;
unsigned int V_171 ;
const struct V_164 * V_165 = & ( V_3 -> V_5 -> V_165 ) ;
T_1 V_49 = F_5 ( V_156 & 0x1f ) ;
T_1 V_172 = ( V_156 >> 5 ) & V_165 -> V_10 ;
void T_2 * V_160 = V_3 -> V_162 + ( V_172 << 2 ) ;
const struct V_106 * V_4 ;
V_4 = F_49 ( V_3 , V_156 ) ;
V_170 = F_57 ( V_3 -> V_22 , V_4 -> V_4 . V_112 ) ;
do {
V_169 = V_170 ;
if ( V_169 )
V_171 = V_165 -> V_173 ;
else
V_171 = V_165 -> V_174 ;
F_71 ( V_49 , V_160 + V_171 ) ;
V_170 = F_57 ( V_3 -> V_22 , V_4 -> V_4 . V_112 ) ;
} while ( V_169 != V_170 );
return V_169 ;
}
static void F_72 ( struct V_154 * V_155 )
{
struct V_2 * V_3 = F_61 ( V_155 ) ;
const struct V_164 * V_165 =
& V_3 -> V_5 -> V_165 ;
T_1 V_49 = F_5 ( V_155 -> V_156 & 0x1f ) ;
void T_2 * V_160 = F_66 ( V_3 , V_155 -> V_156 ,
V_165 -> V_175 ) ;
F_71 ( V_49 , V_160 ) ;
}
static void F_73 ( struct V_154 * V_155 )
{
struct V_2 * V_3 = F_61 ( V_155 ) ;
const struct V_164 * V_165 =
& V_3 -> V_5 -> V_165 ;
T_1 V_49 = F_5 ( V_155 -> V_156 & 0x1f ) ;
void T_2 * V_160 = F_66 ( V_3 , V_155 -> V_156 ,
V_165 -> V_176 ) ;
F_71 ( V_49 , V_160 ) ;
if ( V_3 -> V_177 [ V_155 -> V_156 ] )
F_70 ( V_3 , V_155 -> V_156 ) ;
}
static int F_74 ( struct V_21 * V_22 , unsigned V_16 ,
unsigned V_178 )
{
struct V_2 * V_3 = F_75 ( V_22 -> V_179 ) ;
int V_144 , V_180 , V_181 ;
unsigned int V_182 , V_19 , V_183 , V_184 , V_185 , V_39 , V_186 , V_187 ;
static const unsigned int V_188 [] = { 0 , 1 , 16 , 32 , 64 , 128 , 256 } ;
const struct V_106 * V_4 ;
struct V_154 * V_155 ;
V_4 = V_3 -> V_5 -> V_107 + V_16 ;
if ( V_4 -> V_145 . V_146 == V_152 )
return - V_31 ;
V_144 = V_4 -> V_145 . V_146 ;
V_180 = F_59 ( V_3 -> V_153 , V_144 ) ;
V_181 = ( V_144 % 4 ) * 8 ;
V_155 = F_76 ( V_180 ) ;
V_182 = ( V_144 / 4 ) * 4 + V_3 -> V_5 -> V_165 . V_189 ;
V_184 = ( V_144 / 4 ) * 4 + V_3 -> V_5 -> V_165 . V_190 ;
if ( ! F_67 ( V_3 , V_144 ) )
return - V_191 ;
V_187 = F_35 ( V_188 ) ;
for ( V_39 = 0 ; V_39 < F_35 ( V_188 ) ; V_39 ++ ) {
if ( V_178 <= V_188 [ V_39 ] ) {
V_187 = V_39 ;
break;
}
}
if ( ! F_69 ( V_3 , V_144 ) ) {
F_72 ( V_155 ) ;
V_186 = 1 ;
} else {
V_186 = 0 ;
}
V_183 = 0xff << V_181 ;
F_71 ( V_183 , V_3 -> V_162 + V_184 ) ;
V_19 = ( ( V_187 << V_192 ) | V_193 ) <<
V_181 ;
V_185 = V_194 << V_181 ;
F_71 ( V_185 | V_19 , V_3 -> V_162 + V_182 ) ;
F_77 ( 1 ) ;
if ( V_186 == 1 )
F_73 ( V_155 ) ;
return 0 ;
}
static int F_78 ( struct V_154 * V_155 ,
unsigned int type )
{
struct V_2 * V_3 = F_61 ( V_155 ) ;
const struct V_164 * V_165 =
& V_3 -> V_5 -> V_165 ;
T_1 V_49 = F_5 ( V_155 -> V_156 & 0x1f ) ;
void T_2 * V_160 ;
if ( ( ( type & V_195 ) && ( type & V_196 ) ) ||
( ( type & V_196 ) == V_196 ) ) {
F_18 ( V_3 -> V_86 , L_10 ,
V_155 -> V_151 , V_155 -> V_156 , type ) ;
return - V_31 ;
}
if ( ( type & V_195 ) == V_195 )
V_3 -> V_177 [ V_155 -> V_156 ] = 1 ;
else
V_3 -> V_177 [ V_155 -> V_156 ] = 0 ;
if ( type & ( V_197 | V_198 ) ) {
V_160 = F_66 ( V_3 , V_155 -> V_156 ,
V_165 -> V_173 ) ;
F_71 ( V_49 , V_160 ) ;
} else {
V_160 = F_66 ( V_3 , V_155 -> V_156 ,
V_165 -> V_174 ) ;
F_71 ( V_49 , V_160 ) ;
}
if ( type & ( V_199 | V_198 ) ) {
V_160 = F_66 ( V_3 , V_155 -> V_156 ,
V_165 -> V_200 ) ;
F_71 ( V_49 , V_160 ) ;
} else {
V_160 = F_66 ( V_3 , V_155 -> V_156 ,
V_165 -> V_201 ) ;
F_71 ( V_49 , V_160 ) ;
}
if ( V_3 -> V_177 [ V_155 -> V_156 ] )
F_70 ( V_3 , V_155 -> V_156 ) ;
return 0 ;
}
static int F_79 ( struct V_154 * V_155 , unsigned int V_202 )
{
struct V_2 * V_3 = F_61 ( V_155 ) ;
int V_50 = V_155 -> V_156 & 0x1f ;
int V_160 = V_155 -> V_156 >> 5 ;
if ( V_202 )
V_3 -> V_203 [ V_160 ] |= F_5 ( V_50 ) ;
else
V_3 -> V_203 [ V_160 ] &= ~ F_5 ( V_50 ) ;
return 0 ;
}
static void F_80 ( const struct V_164 * V_22 ,
void T_2 * V_162 , T_1 * V_204 )
{
int V_172 ;
void T_2 * V_160 ;
for ( V_172 = 0 ; V_172 < V_22 -> V_205 ; V_172 ++ ) {
V_160 = V_162 + ( V_172 << 2 ) ;
F_81 ( ~ V_204 [ V_172 ] , V_160 + V_22 -> V_175 ) ;
F_81 ( V_204 [ V_172 ] , V_160 + V_22 -> V_176 ) ;
}
}
static void F_82 ( const struct V_164 * V_22 ,
void T_2 * V_162 , T_1 * V_204 )
{
int V_172 ;
void T_2 * V_160 ;
for ( V_172 = 0 ; V_172 < V_22 -> V_205 ; V_172 ++ ) {
V_160 = V_162 + V_22 -> V_49 + ( V_172 << 2 ) ;
V_204 [ V_172 ] = ~ F_83 ( V_160 ) ;
}
}
static int F_84 ( struct V_206 * V_206 )
{
void T_2 * V_160 ;
struct V_2 * V_3 = F_75 ( V_206 ) ;
const struct V_164 * V_165 =
& V_3 -> V_5 -> V_165 ;
V_160 = V_3 -> V_162 ;
F_82 ( V_165 , V_160 , V_3 -> V_207 ) ;
F_80 ( V_165 , V_160 , V_3 -> V_203 ) ;
return 0 ;
}
static int F_85 ( struct V_206 * V_206 )
{
struct V_2 * V_3 = F_75 ( V_206 ) ;
const struct V_164 * V_165 =
& V_3 -> V_5 -> V_165 ;
F_80 ( V_165 ,
V_3 -> V_162 , V_3 -> V_207 ) ;
return 0 ;
}
static void F_86 ( struct V_154 * V_155 )
{
struct V_2 * V_3 = F_61 ( V_155 ) ;
const struct V_164 * V_165 =
& V_3 -> V_5 -> V_165 ;
T_1 V_49 = F_5 ( V_155 -> V_156 & 0x1f ) ;
void T_2 * V_160 = F_66 ( V_3 , V_155 -> V_156 ,
V_165 -> V_208 ) ;
F_71 ( V_49 , V_160 ) ;
}
static unsigned int F_87 ( struct V_2 * V_3 )
{
const struct V_164 * V_165 =
& V_3 -> V_5 -> V_165 ;
void T_2 * V_160 = V_3 -> V_162 + V_165 -> V_209 ;
unsigned int V_39 ;
for ( V_39 = 0 ; V_39 < V_3 -> V_5 -> V_161 ; V_39 += 32 ) {
F_71 ( 0xffffffff , V_160 ) ;
V_160 += 4 ;
}
return 0 ;
}
static inline void
F_88 ( struct V_2 * V_3 , int V_210 )
{
unsigned int V_185 , V_211 ;
unsigned int V_19 , V_187 ;
const struct V_164 * V_165 =
& V_3 -> V_5 -> V_165 ;
V_211 = ( V_210 / 4 ) * 4 + V_165 -> V_212 ;
V_187 = F_68 ( V_3 -> V_162 + V_211 ) ;
V_19 = V_193 << ( ( V_210 % 4 ) * 8 ) ;
if ( ( V_19 & V_187 ) > 0 ) {
V_211 = ( V_210 / 4 ) * 4 + V_165 -> V_189 ;
V_185 = V_194 << ( ( V_210 % 4 ) * 8 ) ;
F_71 ( V_185 , V_3 -> V_162 + V_211 ) ;
}
}
static void F_89 ( struct V_213 * V_147 )
{
struct V_214 * V_22 = F_90 ( V_147 ) ;
struct V_2 * V_3 = F_91 ( V_147 ) ;
unsigned int V_215 , V_144 ;
int V_16 , V_210 , V_180 ;
const struct V_164 * V_165 =
& V_3 -> V_5 -> V_165 ;
void T_2 * V_160 = F_66 ( V_3 , 0 , V_165 -> V_216 ) ;
int V_217 , V_169 , V_170 ;
const struct V_106 * V_4 ;
F_92 ( V_22 , V_147 ) ;
for ( V_144 = 0 ; V_144 < V_3 -> V_5 -> V_161 ; V_144 += 32 ) {
V_215 = F_68 ( V_160 ) ;
V_160 += 4 ;
while ( V_215 ) {
V_16 = F_93 ( V_215 ) ;
V_210 = V_144 + V_16 ;
V_180 = F_59 ( V_3 -> V_153 , V_210 ) ;
V_215 &= ~ F_5 ( V_16 ) ;
V_217 = V_3 -> V_177 [ V_210 ] ;
if ( V_217 ) {
F_71 ( F_5 ( V_16 ) , V_160 - V_165 -> V_216 +
V_165 -> V_218 ) ;
V_4 = F_49 ( V_3 , V_210 ) ;
V_169 = F_57 ( V_3 -> V_22 ,
V_4 -> V_4 . V_112 ) ;
}
F_94 ( V_180 ) ;
if ( V_217 ) {
V_170 = F_70 ( V_3 , V_210 ) ;
if ( V_169 != V_170 )
F_71 ( F_5 ( V_16 ) , V_160 -
V_165 -> V_216 +
V_165 -> V_219 ) ;
}
if ( V_210 < V_3 -> V_5 -> V_168 )
F_88 ( V_3 , V_210 ) ;
}
}
F_95 ( V_22 , V_147 ) ;
}
static int F_96 ( struct V_220 * V_221 )
{
struct V_2 * V_3 = F_97 ( V_221 ) ;
int V_39 ;
V_3 -> V_102 = V_3 -> V_5 -> V_53 ;
V_3 -> V_97 = F_98 ( & V_221 -> V_86 , V_3 -> V_102 ,
sizeof( * V_3 -> V_97 ) , V_222 ) ;
if ( ! V_3 -> V_97 )
return - V_223 ;
V_3 -> V_139 = F_98 ( & V_221 -> V_86 , V_3 -> V_102 ,
sizeof( * V_3 -> V_139 ) , V_222 ) ;
if ( ! V_3 -> V_139 )
return - V_223 ;
for ( V_39 = 0 ; V_39 < V_3 -> V_5 -> V_53 ; V_39 ++ ) {
const struct V_106 * V_4 = V_3 -> V_5 -> V_107 + V_39 ;
struct V_100 * V_95 = V_3 -> V_97 + V_39 ;
V_95 -> V_110 = V_4 -> V_4 . V_110 ;
V_95 -> V_4 = V_4 -> V_4 . V_112 ;
V_3 -> V_139 [ V_39 ] = V_4 -> V_4 . V_110 ;
}
return 0 ;
}
int F_99 ( struct V_220 * V_221 ,
const struct V_224 * V_119 ,
struct V_1 * V_1 )
{
struct V_225 * V_107 ;
struct V_2 * V_3 ;
struct V_123 * V_136 = V_221 -> V_86 . V_226 , * V_124 ;
struct V_125 * V_227 ;
struct V_228 * V_229 ;
int V_39 , V_84 , V_151 , V_230 ;
V_3 = F_100 ( & V_221 -> V_86 , sizeof( * V_3 ) , V_222 ) ;
if ( ! V_3 )
return - V_223 ;
F_101 ( V_221 , V_3 ) ;
V_227 = F_29 ( V_136 , L_11 , NULL ) ;
if ( ! V_227 ) {
F_18 ( & V_221 -> V_86 , L_12 ) ;
return - V_31 ;
}
V_124 = F_102 ( V_136 , L_13 , 0 ) ;
if ( V_124 ) {
V_3 -> V_9 = F_103 ( V_124 ) ;
if ( F_104 ( V_3 -> V_9 ) )
return F_105 ( V_3 -> V_9 ) ;
} else if ( V_1 ) {
V_3 -> V_9 = V_1 ;
} else {
F_18 ( & V_221 -> V_86 , L_14 ) ;
return - V_31 ;
}
V_124 = F_102 ( V_136 , L_13 , 1 ) ;
if ( V_124 ) {
V_3 -> V_8 = F_103 ( V_124 ) ;
if ( F_104 ( V_3 -> V_8 ) )
return F_105 ( V_3 -> V_8 ) ;
}
V_3 -> V_5 = V_119 ;
V_84 = F_96 ( V_221 ) ;
if ( V_84 ) {
F_18 ( & V_221 -> V_86 , L_15 , V_84 ) ;
return - V_31 ;
}
V_107 = F_98 ( & V_221 -> V_86 , V_3 -> V_5 -> V_53 , sizeof( * V_107 ) ,
V_222 ) ;
if ( ! V_107 )
return - V_223 ;
for ( V_39 = 0 ; V_39 < V_3 -> V_5 -> V_53 ; V_39 ++ )
V_107 [ V_39 ] = V_3 -> V_5 -> V_107 [ V_39 ] . V_4 ;
V_3 -> V_231 . V_110 = F_106 ( & V_221 -> V_86 ) ;
V_3 -> V_231 . V_232 = V_233 ;
V_3 -> V_231 . V_107 = V_107 ;
V_3 -> V_231 . V_53 = V_3 -> V_5 -> V_53 ;
V_3 -> V_231 . V_234 = & V_235 ;
V_3 -> V_231 . V_236 = & V_237 ;
V_3 -> V_231 . V_238 = & V_239 ;
V_3 -> V_86 = & V_221 -> V_86 ;
V_3 -> V_157 = F_107 ( & V_3 -> V_231 , & V_221 -> V_86 , V_3 ) ;
if ( F_104 ( V_3 -> V_157 ) ) {
F_18 ( & V_221 -> V_86 , L_16 ) ;
return F_105 ( V_3 -> V_157 ) ;
}
V_3 -> V_22 = F_100 ( & V_221 -> V_86 , sizeof( * V_3 -> V_22 ) , V_222 ) ;
if ( ! V_3 -> V_22 ) {
V_84 = - V_223 ;
goto V_240;
}
* V_3 -> V_22 = V_241 ;
V_3 -> V_22 -> V_242 = V_3 -> V_5 -> V_53 ;
V_3 -> V_22 -> V_243 = F_106 ( & V_221 -> V_86 ) ;
V_3 -> V_22 -> V_179 = & V_221 -> V_86 ;
V_3 -> V_22 -> V_148 = - 1 ;
V_84 = F_108 ( V_3 -> V_22 , V_3 ) ;
if ( V_84 ) {
V_84 = - V_31 ;
goto V_240;
}
V_84 = F_109 ( V_3 -> V_22 , F_106 ( & V_221 -> V_86 ) ,
0 , 0 , V_3 -> V_5 -> V_53 ) ;
if ( V_84 ) {
V_84 = - V_31 ;
goto V_244;
}
if ( ! F_110 ( V_136 , L_17 ) )
return 0 ;
V_229 = F_111 ( V_221 , V_245 , 0 ) ;
if ( ! V_229 ) {
F_18 ( & V_221 -> V_86 , L_18 ) ;
V_84 = - V_31 ;
goto V_244;
}
V_3 -> V_162 = F_112 ( & V_221 -> V_86 , V_229 ) ;
if ( F_104 ( V_3 -> V_162 ) ) {
V_84 = - V_31 ;
goto V_244;
}
V_230 = V_3 -> V_5 -> V_165 . V_205 ;
V_3 -> V_203 = F_98 ( & V_221 -> V_86 , V_230 ,
sizeof( * V_3 -> V_203 ) , V_222 ) ;
if ( ! V_3 -> V_203 ) {
V_84 = - V_223 ;
goto V_244;
}
V_3 -> V_207 = F_98 ( & V_221 -> V_86 , V_230 ,
sizeof( * V_3 -> V_207 ) , V_222 ) ;
if ( ! V_3 -> V_207 ) {
V_84 = - V_223 ;
goto V_244;
}
V_3 -> V_177 = F_98 ( & V_221 -> V_86 , V_3 -> V_5 -> V_161 ,
sizeof( int ) , V_222 ) ;
if ( ! V_3 -> V_177 ) {
V_84 = - V_223 ;
goto V_244;
}
V_151 = F_113 ( V_136 , 0 ) ;
if ( ! V_151 ) {
F_18 ( & V_221 -> V_86 , L_19 ) ;
V_84 = - V_31 ;
goto V_244;
}
V_3 -> V_153 = F_114 ( V_136 ,
V_3 -> V_5 -> V_161 , & V_246 , NULL ) ;
if ( ! V_3 -> V_153 ) {
F_18 ( & V_221 -> V_86 , L_20 ) ;
V_84 = - V_223 ;
goto V_244;
}
F_87 ( V_3 ) ;
for ( V_39 = 0 ; V_39 < V_3 -> V_5 -> V_161 ; V_39 ++ ) {
int V_180 = F_115 ( V_3 -> V_153 , V_39 ) ;
F_116 ( V_180 , & V_247 ,
V_248 ) ;
F_117 ( V_180 , V_3 ) ;
}
F_118 ( V_151 , F_89 , V_3 ) ;
return 0 ;
V_244:
F_119 ( V_3 -> V_22 ) ;
V_240:
F_120 ( V_3 -> V_157 ) ;
return V_84 ;
}

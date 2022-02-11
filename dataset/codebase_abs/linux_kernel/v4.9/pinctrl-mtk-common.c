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
if ( V_3 -> V_5 -> V_21 )
V_3 -> V_5 -> V_21 ( & V_18 , V_16 ) ;
if ( V_17 )
V_18 = F_6 ( V_18 , V_3 ) ;
else
V_18 = F_7 ( V_18 , V_3 ) ;
F_8 ( F_1 ( V_3 , V_16 ) , V_18 , V_19 ) ;
return 0 ;
}
static void F_9 ( struct V_22 * V_23 , unsigned V_16 , int V_24 )
{
unsigned int V_18 ;
unsigned int V_19 ;
struct V_2 * V_3 = F_10 ( V_23 ) ;
V_18 = F_2 ( V_3 , V_16 ) + V_3 -> V_5 -> V_25 ;
V_19 = F_5 ( V_16 & 0xf ) ;
if ( V_24 )
V_18 = F_7 ( V_18 , V_3 ) ;
else
V_18 = F_6 ( V_18 , V_3 ) ;
F_8 ( F_1 ( V_3 , V_16 ) , V_18 , V_19 ) ;
}
static int F_11 ( struct V_2 * V_3 , unsigned V_4 ,
int V_24 , enum V_26 V_27 )
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
V_4 , V_3 -> V_5 -> V_35 , V_24 , V_27 ) ;
}
V_19 = F_5 ( V_4 & 0xf ) ;
if ( V_27 == V_31 )
V_16 = V_3 -> V_5 -> V_29 ;
else
V_16 = V_3 -> V_5 -> V_33 ;
if ( V_24 )
V_18 = F_7 ( F_2 ( V_3 , V_4 ) + V_16 , V_3 ) ;
else
V_18 = F_6 ( F_2 ( V_3 , V_4 ) + V_16 , V_3 ) ;
F_8 ( F_1 ( V_3 , V_4 ) , V_18 , V_19 ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_1 ,
const struct V_36 * V_37 , unsigned int V_38 ,
unsigned int V_4 , unsigned char V_39 , int V_24 )
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
if ( V_24 )
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
F_18 ( V_3 -> V_87 , L_1 ,
V_27 , V_4 ) ;
return - V_32 ;
}
V_19 = F_5 ( V_4 & 0xf ) ;
if ( V_82 )
V_83 = F_7 ( F_2 ( V_3 , V_4 ) +
V_3 -> V_5 -> V_88 , V_3 ) ;
else
V_83 = F_6 ( F_2 ( V_3 , V_4 ) +
V_3 -> V_5 -> V_88 , V_3 ) ;
if ( V_65 )
V_84 = F_7 ( F_2 ( V_3 , V_4 ) +
V_3 -> V_5 -> V_89 , V_3 ) ;
else
V_84 = F_6 ( F_2 ( V_3 , V_4 ) +
V_3 -> V_5 -> V_89 , V_3 ) ;
F_8 ( F_1 ( V_3 , V_4 ) , V_83 , V_19 ) ;
F_8 ( F_1 ( V_3 , V_4 ) , V_84 , V_19 ) ;
return 0 ;
}
static int F_19 ( struct V_12 * V_13 ,
unsigned int V_4 , enum V_26 V_90 ,
enum V_26 V_27 )
{
int V_85 = 0 ;
struct V_2 * V_3 = F_4 ( V_13 ) ;
switch ( V_90 ) {
case V_91 :
V_85 = F_17 ( V_3 , V_4 , false , false , V_27 ) ;
break;
case V_92 :
V_85 = F_17 ( V_3 , V_4 , true , true , V_27 ) ;
break;
case V_93 :
V_85 = F_17 ( V_3 , V_4 , true , false , V_27 ) ;
break;
case V_31 :
F_3 ( V_13 , NULL , V_4 , true ) ;
V_85 = F_11 ( V_3 , V_4 , V_27 , V_90 ) ;
break;
case V_94 :
F_9 ( V_3 -> V_23 , V_4 , V_27 ) ;
V_85 = F_3 ( V_13 , NULL , V_4 , false ) ;
break;
case V_34 :
F_3 ( V_13 , NULL , V_4 , true ) ;
V_85 = F_11 ( V_3 , V_4 , V_27 , V_90 ) ;
break;
case V_95 :
V_85 = F_14 ( V_3 , V_4 , V_27 ) ;
break;
default:
V_85 = - V_32 ;
}
return V_85 ;
}
static int F_20 ( struct V_12 * V_13 ,
unsigned V_96 ,
unsigned long * V_97 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
* V_97 = V_3 -> V_98 [ V_96 ] . V_97 ;
return 0 ;
}
static int F_21 ( struct V_12 * V_13 , unsigned V_96 ,
unsigned long * V_99 , unsigned V_100 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
struct V_101 * V_102 = & V_3 -> V_98 [ V_96 ] ;
int V_40 , V_85 ;
for ( V_40 = 0 ; V_40 < V_100 ; V_40 ++ ) {
V_85 = F_19 ( V_13 , V_102 -> V_4 ,
F_22 ( V_99 [ V_40 ] ) ,
F_23 ( V_99 [ V_40 ] ) ) ;
if ( V_85 < 0 )
return V_85 ;
V_102 -> V_97 = V_99 [ V_40 ] ;
}
return 0 ;
}
static struct V_101 *
F_24 ( struct V_2 * V_3 , T_1 V_4 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_3 -> V_103 ; V_40 ++ ) {
struct V_101 * V_55 = V_3 -> V_98 + V_40 ;
if ( V_55 -> V_4 == V_4 )
return V_55 ;
}
return NULL ;
}
static const struct V_104 * F_25 (
struct V_2 * V_3 , T_1 V_105 , T_1 V_106 )
{
const struct V_107 * V_4 = V_3 -> V_5 -> V_108 + V_105 ;
const struct V_104 * V_109 = V_4 -> V_110 ;
while ( V_109 && V_109 -> V_111 ) {
if ( V_109 -> V_112 == V_106 )
return V_109 ;
V_109 ++ ;
}
return NULL ;
}
static bool F_26 ( struct V_2 * V_3 ,
T_1 V_105 , T_1 V_106 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_3 -> V_5 -> V_54 ; V_40 ++ ) {
const struct V_107 * V_4 = V_3 -> V_5 -> V_108 + V_40 ;
if ( V_4 -> V_4 . V_113 == V_105 ) {
const struct V_104 * V_109 =
V_4 -> V_110 ;
while ( V_109 && V_109 -> V_111 ) {
if ( V_109 -> V_112 == V_106 )
return true ;
V_109 ++ ;
}
break;
}
}
return false ;
}
static int F_27 ( struct V_2 * V_3 ,
T_1 V_4 , T_1 V_106 , struct V_101 * V_55 ,
struct V_114 * * V_115 , unsigned * V_116 ,
unsigned * V_117 )
{
bool V_85 ;
if ( * V_117 == * V_116 )
return - V_118 ;
( * V_115 ) [ * V_117 ] . type = V_119 ;
( * V_115 ) [ * V_117 ] . V_120 . V_121 . V_96 = V_55 -> V_111 ;
V_85 = F_26 ( V_3 , V_4 , V_106 ) ;
if ( ! V_85 ) {
F_18 ( V_3 -> V_87 , L_2 ,
V_106 , V_4 ) ;
return - V_32 ;
}
( * V_115 ) [ * V_117 ] . V_120 . V_121 . V_122 = V_123 [ V_106 ] ;
( * V_117 ) ++ ;
return 0 ;
}
static int F_28 ( struct V_12 * V_13 ,
struct V_124 * V_125 ,
struct V_114 * * V_115 ,
unsigned * V_116 ,
unsigned * V_117 )
{
struct V_126 * V_108 ;
T_1 V_127 , V_4 , V_109 ;
int V_128 , V_129 , V_130 ;
unsigned long * V_99 ;
unsigned int V_100 ;
bool V_131 = 0 ;
int V_40 , V_132 ;
unsigned V_133 = 0 ;
struct V_101 * V_55 ;
struct V_2 * V_3 = F_4 ( V_13 ) ;
V_108 = F_29 ( V_125 , L_3 , NULL ) ;
if ( ! V_108 ) {
F_18 ( V_3 -> V_87 , L_4 ,
V_125 -> V_111 ) ;
return - V_32 ;
}
V_132 = F_30 ( V_125 , V_13 , & V_99 ,
& V_100 ) ;
if ( V_132 )
return V_132 ;
if ( V_100 )
V_131 = 1 ;
V_128 = V_108 -> V_134 / sizeof( T_1 ) ;
V_129 = V_128 ;
V_130 = 0 ;
if ( V_129 )
V_130 ++ ;
if ( V_131 && V_128 >= 1 )
V_130 ++ ;
if ( ! V_128 || ! V_130 ) {
V_132 = - V_32 ;
goto exit;
}
V_133 = V_128 * V_130 ;
V_132 = F_31 ( V_13 , V_115 ,
V_116 , V_117 , V_133 ) ;
if ( V_132 < 0 )
goto exit;
for ( V_40 = 0 ; V_40 < V_128 ; V_40 ++ ) {
V_132 = F_32 ( V_125 , L_3 ,
V_40 , & V_127 ) ;
if ( V_132 )
goto exit;
V_4 = F_33 ( V_127 ) ;
V_109 = F_34 ( V_127 ) ;
if ( V_4 >= V_3 -> V_5 -> V_54 ||
V_109 >= F_35 ( V_123 ) ) {
F_18 ( V_3 -> V_87 , L_5 ) ;
V_132 = - V_32 ;
goto exit;
}
V_55 = F_24 ( V_3 , V_4 ) ;
if ( ! V_55 ) {
F_18 ( V_3 -> V_87 , L_6 ,
V_4 ) ;
V_132 = - V_32 ;
goto exit;
}
V_132 = F_27 ( V_3 , V_4 , V_109 , V_55 , V_115 ,
V_116 , V_117 ) ;
if ( V_132 < 0 )
goto exit;
if ( V_131 ) {
V_132 = F_36 ( V_13 , V_115 ,
V_116 , V_117 , V_55 -> V_111 ,
V_99 , V_100 ,
V_135 ) ;
if ( V_132 < 0 )
goto exit;
}
}
V_132 = 0 ;
exit:
F_37 ( V_99 ) ;
return V_132 ;
}
static int F_38 ( struct V_12 * V_13 ,
struct V_124 * V_136 ,
struct V_114 * * V_115 , unsigned * V_117 )
{
struct V_124 * V_137 ;
unsigned V_116 ;
int V_85 ;
* V_115 = NULL ;
* V_117 = 0 ;
V_116 = 0 ;
F_39 (np_config, np) {
V_85 = F_28 ( V_13 , V_137 , V_115 ,
& V_116 , V_117 ) ;
if ( V_85 < 0 ) {
F_40 ( V_13 , * V_115 , * V_117 ) ;
F_41 ( V_137 ) ;
return V_85 ;
}
}
return 0 ;
}
static int F_42 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
return V_3 -> V_103 ;
}
static const char * F_43 ( struct V_12 * V_13 ,
unsigned V_96 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
return V_3 -> V_98 [ V_96 ] . V_111 ;
}
static int F_44 ( struct V_12 * V_13 ,
unsigned V_96 ,
const unsigned * * V_108 ,
unsigned * V_128 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
* V_108 = ( unsigned * ) & V_3 -> V_98 [ V_96 ] . V_4 ;
* V_128 = 1 ;
return 0 ;
}
static int F_45 ( struct V_12 * V_13 )
{
return F_35 ( V_123 ) ;
}
static const char * F_46 ( struct V_12 * V_13 ,
unsigned V_138 )
{
return V_123 [ V_138 ] ;
}
static int F_47 ( struct V_12 * V_13 ,
unsigned V_122 ,
const char * const * * V_98 ,
unsigned * const V_139 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
* V_98 = V_3 -> V_140 ;
* V_139 = V_3 -> V_103 ;
return 0 ;
}
static int F_48 ( struct V_12 * V_13 ,
unsigned long V_4 , unsigned long V_141 )
{
unsigned int V_18 ;
unsigned char V_19 ;
unsigned int V_48 ;
unsigned int V_50 = ( 1L << V_142 ) - 1 ;
struct V_2 * V_3 = F_4 ( V_13 ) ;
if ( V_3 -> V_5 -> V_143 )
V_3 -> V_5 -> V_143 ( F_1 ( V_3 , V_4 ) ,
V_4 , V_141 ) ;
V_18 = ( ( V_4 / V_144 ) << V_3 -> V_5 -> V_11 )
+ V_3 -> V_5 -> V_145 ;
V_141 &= V_50 ;
V_19 = V_4 % V_144 ;
V_50 <<= ( V_142 * V_19 ) ;
V_48 = ( V_141 << ( V_142 * V_19 ) ) ;
return F_15 ( F_1 ( V_3 , V_4 ) ,
V_18 , V_50 , V_48 ) ;
}
static const struct V_107 *
F_49 ( struct V_2 * V_3 , unsigned int V_146 )
{
int V_40 ;
const struct V_107 * V_4 ;
for ( V_40 = 0 ; V_40 < V_3 -> V_5 -> V_54 ; V_40 ++ ) {
V_4 = V_3 -> V_5 -> V_108 + V_40 ;
if ( V_4 -> V_147 . V_148 == V_146 )
return V_4 ;
}
return NULL ;
}
static int F_50 ( struct V_12 * V_13 ,
unsigned V_122 ,
unsigned V_96 )
{
bool V_85 ;
const struct V_104 * V_149 ;
struct V_2 * V_3 = F_4 ( V_13 ) ;
struct V_101 * V_102 = V_3 -> V_98 + V_96 ;
V_85 = F_26 ( V_3 , V_102 -> V_4 , V_122 ) ;
if ( ! V_85 ) {
F_18 ( V_3 -> V_87 , L_7 ,
V_122 , V_96 ) ;
return - V_32 ;
}
V_149 = F_25 ( V_3 , V_102 -> V_4 , V_122 ) ;
if ( ! V_149 )
return - V_32 ;
F_48 ( V_13 , V_102 -> V_4 , V_149 -> V_112 ) ;
return 0 ;
}
static int F_51 ( struct V_2 * V_3 ,
unsigned V_16 )
{
const struct V_107 * V_4 = V_3 -> V_5 -> V_108 + V_16 ;
const struct V_104 * V_109 = V_4 -> V_110 ;
while ( V_109 && V_109 -> V_111 ) {
if ( ! strncmp ( V_109 -> V_111 , V_150 ,
sizeof( V_150 ) - 1 ) )
return V_109 -> V_112 ;
V_109 ++ ;
}
return - V_32 ;
}
static int F_52 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
unsigned V_16 )
{
int V_112 ;
struct V_2 * V_3 = F_4 ( V_13 ) ;
V_112 = F_51 ( V_3 , V_16 ) ;
if ( V_112 < 0 ) {
F_18 ( V_3 -> V_87 , L_8 , V_16 ) ;
return - V_32 ;
}
F_48 ( V_13 , V_16 , V_112 ) ;
F_11 ( V_3 , V_16 , 1 , V_31 ) ;
return 0 ;
}
static int F_53 ( struct V_22 * V_23 ,
unsigned V_16 )
{
return F_54 ( V_23 -> V_151 + V_16 ) ;
}
static int F_55 ( struct V_22 * V_23 ,
unsigned V_16 , int V_24 )
{
F_9 ( V_23 , V_16 , V_24 ) ;
return F_56 ( V_23 -> V_151 + V_16 ) ;
}
static int F_57 ( struct V_22 * V_23 , unsigned V_16 )
{
unsigned int V_18 ;
unsigned int V_19 ;
unsigned int V_152 = 0 ;
struct V_2 * V_3 = F_10 ( V_23 ) ;
V_18 = F_2 ( V_3 , V_16 ) + V_3 -> V_5 -> V_20 ;
V_19 = F_5 ( V_16 & 0xf ) ;
if ( V_3 -> V_5 -> V_21 )
V_3 -> V_5 -> V_21 ( & V_18 , V_16 ) ;
F_58 ( V_3 -> V_9 , V_18 , & V_152 ) ;
return ! ( V_152 & V_19 ) ;
}
static int F_59 ( struct V_22 * V_23 , unsigned V_16 )
{
unsigned int V_18 ;
unsigned int V_19 ;
unsigned int V_152 = 0 ;
struct V_2 * V_3 = F_10 ( V_23 ) ;
V_18 = F_2 ( V_3 , V_16 ) +
V_3 -> V_5 -> V_153 ;
V_19 = F_5 ( V_16 & 0xf ) ;
F_58 ( V_3 -> V_9 , V_18 , & V_152 ) ;
return ! ! ( V_152 & V_19 ) ;
}
static int F_60 ( struct V_22 * V_23 , unsigned V_16 )
{
const struct V_107 * V_4 ;
struct V_2 * V_3 = F_10 ( V_23 ) ;
int V_154 ;
V_4 = V_3 -> V_5 -> V_108 + V_16 ;
if ( V_4 -> V_147 . V_148 == V_155 )
return - V_32 ;
V_154 = F_61 ( V_3 -> V_156 , V_4 -> V_147 . V_148 ) ;
if ( ! V_154 )
return - V_32 ;
return V_154 ;
}
static int F_62 ( struct V_157 * V_158 )
{
struct V_2 * V_3 = F_63 ( V_158 ) ;
const struct V_107 * V_4 ;
int V_85 ;
V_4 = F_49 ( V_3 , V_158 -> V_159 ) ;
if ( ! V_4 ) {
F_18 ( V_3 -> V_87 , L_9 ) ;
return - V_32 ;
}
V_85 = F_64 ( V_3 -> V_23 , V_4 -> V_4 . V_113 ) ;
if ( V_85 ) {
F_18 ( V_3 -> V_87 , L_10 ,
F_65 ( V_158 ) ) ;
return V_85 ;
}
F_48 ( V_3 -> V_160 , V_4 -> V_4 . V_113 , V_4 -> V_147 . V_161 ) ;
F_3 ( V_3 -> V_160 , NULL , V_4 -> V_4 . V_113 , true ) ;
F_11 ( V_3 , V_4 -> V_4 . V_113 , 1 , V_31 ) ;
return 0 ;
}
static void F_66 ( struct V_157 * V_158 )
{
struct V_2 * V_3 = F_63 ( V_158 ) ;
const struct V_107 * V_4 ;
V_4 = F_49 ( V_3 , V_158 -> V_159 ) ;
if ( ! V_4 ) {
F_18 ( V_3 -> V_87 , L_9 ) ;
return;
}
F_67 ( V_3 -> V_23 , V_4 -> V_4 . V_113 ) ;
}
static void T_2 * F_68 ( struct V_2 * V_3 ,
unsigned int V_146 , unsigned int V_16 )
{
unsigned int V_162 = 0 ;
void T_2 * V_163 ;
if ( V_146 >= V_3 -> V_5 -> V_164 )
V_162 = V_3 -> V_5 -> V_164 ;
V_163 = V_3 -> V_165 + V_16 + ( ( V_146 - V_162 ) / 32 ) * 4 ;
return V_163 ;
}
static unsigned int F_69 ( struct V_2 * V_3 ,
unsigned int V_146 )
{
unsigned int V_166 ;
unsigned int V_19 = F_5 ( V_146 % 32 ) ;
const struct V_167 * V_168 =
& V_3 -> V_5 -> V_168 ;
void T_2 * V_163 = F_68 ( V_3 , V_146 ,
V_168 -> V_166 ) ;
if ( F_70 ( V_163 ) & V_19 )
V_166 = V_169 ;
else
V_166 = V_170 ;
if ( ( V_146 < V_3 -> V_5 -> V_171 ) && ( V_166 != V_170 ) )
return 1 ;
else
return 0 ;
}
static unsigned int F_71 ( struct V_2 * V_3 ,
unsigned int V_146 )
{
unsigned int V_19 = F_5 ( V_146 % 32 ) ;
const struct V_167 * V_168 =
& V_3 -> V_5 -> V_168 ;
void T_2 * V_163 = F_68 ( V_3 , V_146 ,
V_168 -> V_50 ) ;
return ! ! ( F_70 ( V_163 ) & V_19 ) ;
}
static int F_72 ( struct V_2 * V_3 , int V_159 )
{
int V_172 , V_173 ;
unsigned int V_174 ;
const struct V_167 * V_168 = & ( V_3 -> V_5 -> V_168 ) ;
T_1 V_50 = F_5 ( V_159 & 0x1f ) ;
T_1 V_175 = ( V_159 >> 5 ) & V_168 -> V_10 ;
void T_2 * V_163 = V_3 -> V_165 + ( V_175 << 2 ) ;
const struct V_107 * V_4 ;
V_4 = F_49 ( V_3 , V_159 ) ;
V_173 = F_59 ( V_3 -> V_23 , V_4 -> V_4 . V_113 ) ;
do {
V_172 = V_173 ;
if ( V_172 )
V_174 = V_168 -> V_176 ;
else
V_174 = V_168 -> V_177 ;
F_73 ( V_50 , V_163 + V_174 ) ;
V_173 = F_59 ( V_3 -> V_23 , V_4 -> V_4 . V_113 ) ;
} while ( V_172 != V_173 );
return V_172 ;
}
static void F_74 ( struct V_157 * V_158 )
{
struct V_2 * V_3 = F_63 ( V_158 ) ;
const struct V_167 * V_168 =
& V_3 -> V_5 -> V_168 ;
T_1 V_50 = F_5 ( V_158 -> V_159 & 0x1f ) ;
void T_2 * V_163 = F_68 ( V_3 , V_158 -> V_159 ,
V_168 -> V_178 ) ;
F_73 ( V_50 , V_163 ) ;
}
static void F_75 ( struct V_157 * V_158 )
{
struct V_2 * V_3 = F_63 ( V_158 ) ;
const struct V_167 * V_168 =
& V_3 -> V_5 -> V_168 ;
T_1 V_50 = F_5 ( V_158 -> V_159 & 0x1f ) ;
void T_2 * V_163 = F_68 ( V_3 , V_158 -> V_159 ,
V_168 -> V_179 ) ;
F_73 ( V_50 , V_163 ) ;
if ( V_3 -> V_180 [ V_158 -> V_159 ] )
F_72 ( V_3 , V_158 -> V_159 ) ;
}
static int F_76 ( struct V_22 * V_23 , unsigned V_16 ,
unsigned V_181 )
{
struct V_2 * V_3 = F_77 ( V_23 -> V_182 ) ;
int V_146 , V_183 , V_184 ;
unsigned int V_185 , V_19 , V_186 , V_187 , V_188 , V_40 , V_189 , V_190 ;
static const unsigned int V_191 [] = { 500 , 1000 , 16000 , 32000 , 64000 ,
128000 , 256000 } ;
const struct V_107 * V_4 ;
struct V_157 * V_158 ;
V_4 = V_3 -> V_5 -> V_108 + V_16 ;
if ( V_4 -> V_147 . V_148 == V_155 )
return - V_32 ;
V_146 = V_4 -> V_147 . V_148 ;
V_183 = F_61 ( V_3 -> V_156 , V_146 ) ;
V_184 = ( V_146 % 4 ) * 8 ;
V_158 = F_78 ( V_183 ) ;
V_185 = ( V_146 / 4 ) * 4 + V_3 -> V_5 -> V_168 . V_192 ;
V_187 = ( V_146 / 4 ) * 4 + V_3 -> V_5 -> V_168 . V_193 ;
if ( ! F_69 ( V_3 , V_146 ) )
return - V_194 ;
V_190 = F_35 ( V_191 ) ;
for ( V_40 = 0 ; V_40 < F_35 ( V_191 ) ; V_40 ++ ) {
if ( V_181 <= V_191 [ V_40 ] ) {
V_190 = V_40 ;
break;
}
}
if ( ! F_71 ( V_3 , V_146 ) ) {
F_74 ( V_158 ) ;
V_189 = 1 ;
} else {
V_189 = 0 ;
}
V_186 = 0xff << V_184 ;
F_73 ( V_186 , V_3 -> V_165 + V_187 ) ;
V_19 = ( ( V_190 << V_195 ) | V_196 ) <<
V_184 ;
V_188 = V_197 << V_184 ;
F_73 ( V_188 | V_19 , V_3 -> V_165 + V_185 ) ;
F_79 ( 1 ) ;
if ( V_189 == 1 )
F_75 ( V_158 ) ;
return 0 ;
}
static int F_80 ( struct V_157 * V_158 ,
unsigned int type )
{
struct V_2 * V_3 = F_63 ( V_158 ) ;
const struct V_167 * V_168 =
& V_3 -> V_5 -> V_168 ;
T_1 V_50 = F_5 ( V_158 -> V_159 & 0x1f ) ;
void T_2 * V_163 ;
if ( ( ( type & V_198 ) && ( type & V_199 ) ) ||
( ( type & V_199 ) == V_199 ) ) {
F_18 ( V_3 -> V_87 , L_11 ,
V_158 -> V_154 , V_158 -> V_159 , type ) ;
return - V_32 ;
}
if ( ( type & V_198 ) == V_198 )
V_3 -> V_180 [ V_158 -> V_159 ] = 1 ;
else
V_3 -> V_180 [ V_158 -> V_159 ] = 0 ;
if ( type & ( V_200 | V_201 ) ) {
V_163 = F_68 ( V_3 , V_158 -> V_159 ,
V_168 -> V_176 ) ;
F_73 ( V_50 , V_163 ) ;
} else {
V_163 = F_68 ( V_3 , V_158 -> V_159 ,
V_168 -> V_177 ) ;
F_73 ( V_50 , V_163 ) ;
}
if ( type & ( V_202 | V_201 ) ) {
V_163 = F_68 ( V_3 , V_158 -> V_159 ,
V_168 -> V_203 ) ;
F_73 ( V_50 , V_163 ) ;
} else {
V_163 = F_68 ( V_3 , V_158 -> V_159 ,
V_168 -> V_204 ) ;
F_73 ( V_50 , V_163 ) ;
}
if ( V_3 -> V_180 [ V_158 -> V_159 ] )
F_72 ( V_3 , V_158 -> V_159 ) ;
return 0 ;
}
static int F_81 ( struct V_157 * V_158 , unsigned int V_205 )
{
struct V_2 * V_3 = F_63 ( V_158 ) ;
int V_51 = V_158 -> V_159 & 0x1f ;
int V_163 = V_158 -> V_159 >> 5 ;
if ( V_205 )
V_3 -> V_206 [ V_163 ] |= F_5 ( V_51 ) ;
else
V_3 -> V_206 [ V_163 ] &= ~ F_5 ( V_51 ) ;
return 0 ;
}
static void F_82 ( const struct V_167 * V_23 ,
void T_2 * V_165 , T_1 * V_207 )
{
int V_175 ;
void T_2 * V_163 ;
for ( V_175 = 0 ; V_175 < V_23 -> V_208 ; V_175 ++ ) {
V_163 = V_165 + ( V_175 << 2 ) ;
F_83 ( ~ V_207 [ V_175 ] , V_163 + V_23 -> V_178 ) ;
F_83 ( V_207 [ V_175 ] , V_163 + V_23 -> V_179 ) ;
}
}
static void F_84 ( const struct V_167 * V_23 ,
void T_2 * V_165 , T_1 * V_207 )
{
int V_175 ;
void T_2 * V_163 ;
for ( V_175 = 0 ; V_175 < V_23 -> V_208 ; V_175 ++ ) {
V_163 = V_165 + V_23 -> V_50 + ( V_175 << 2 ) ;
V_207 [ V_175 ] = ~ F_85 ( V_163 ) ;
}
}
static int F_86 ( struct V_209 * V_209 )
{
void T_2 * V_163 ;
struct V_2 * V_3 = F_77 ( V_209 ) ;
const struct V_167 * V_168 =
& V_3 -> V_5 -> V_168 ;
V_163 = V_3 -> V_165 ;
F_84 ( V_168 , V_163 , V_3 -> V_210 ) ;
F_82 ( V_168 , V_163 , V_3 -> V_206 ) ;
return 0 ;
}
static int F_87 ( struct V_209 * V_209 )
{
struct V_2 * V_3 = F_77 ( V_209 ) ;
const struct V_167 * V_168 =
& V_3 -> V_5 -> V_168 ;
F_82 ( V_168 ,
V_3 -> V_165 , V_3 -> V_210 ) ;
return 0 ;
}
static void F_88 ( struct V_157 * V_158 )
{
struct V_2 * V_3 = F_63 ( V_158 ) ;
const struct V_167 * V_168 =
& V_3 -> V_5 -> V_168 ;
T_1 V_50 = F_5 ( V_158 -> V_159 & 0x1f ) ;
void T_2 * V_163 = F_68 ( V_3 , V_158 -> V_159 ,
V_168 -> V_211 ) ;
F_73 ( V_50 , V_163 ) ;
}
static unsigned int F_89 ( struct V_2 * V_3 )
{
const struct V_167 * V_168 =
& V_3 -> V_5 -> V_168 ;
void T_2 * V_163 = V_3 -> V_165 + V_168 -> V_212 ;
unsigned int V_40 ;
for ( V_40 = 0 ; V_40 < V_3 -> V_5 -> V_164 ; V_40 += 32 ) {
F_73 ( 0xffffffff , V_163 ) ;
V_163 += 4 ;
}
return 0 ;
}
static inline void
F_90 ( struct V_2 * V_3 , int V_213 )
{
unsigned int V_188 , V_214 ;
unsigned int V_19 , V_190 ;
const struct V_167 * V_168 =
& V_3 -> V_5 -> V_168 ;
V_214 = ( V_213 / 4 ) * 4 + V_168 -> V_215 ;
V_190 = F_70 ( V_3 -> V_165 + V_214 ) ;
V_19 = V_196 << ( ( V_213 % 4 ) * 8 ) ;
if ( ( V_19 & V_190 ) > 0 ) {
V_214 = ( V_213 / 4 ) * 4 + V_168 -> V_192 ;
V_188 = V_197 << ( ( V_213 % 4 ) * 8 ) ;
F_73 ( V_188 , V_3 -> V_165 + V_214 ) ;
}
}
static void F_91 ( struct V_216 * V_149 )
{
struct V_217 * V_23 = F_92 ( V_149 ) ;
struct V_2 * V_3 = F_93 ( V_149 ) ;
unsigned int V_218 , V_146 ;
int V_16 , V_213 , V_183 ;
const struct V_167 * V_168 =
& V_3 -> V_5 -> V_168 ;
void T_2 * V_163 = F_68 ( V_3 , 0 , V_168 -> V_219 ) ;
int V_220 , V_172 , V_173 ;
const struct V_107 * V_4 ;
F_94 ( V_23 , V_149 ) ;
for ( V_146 = 0 ;
V_146 < V_3 -> V_5 -> V_164 ;
V_146 += 32 , V_163 += 4 ) {
V_218 = F_70 ( V_163 ) ;
while ( V_218 ) {
V_16 = F_95 ( V_218 ) ;
V_213 = V_146 + V_16 ;
V_183 = F_61 ( V_3 -> V_156 , V_213 ) ;
V_218 &= ~ F_5 ( V_16 ) ;
V_220 = V_3 -> V_180 [ V_213 ] ;
if ( V_220 ) {
F_73 ( F_5 ( V_16 ) , V_163 - V_168 -> V_219 +
V_168 -> V_221 ) ;
V_4 = F_49 ( V_3 , V_213 ) ;
V_172 = F_59 ( V_3 -> V_23 ,
V_4 -> V_4 . V_113 ) ;
}
F_96 ( V_183 ) ;
if ( V_220 ) {
V_173 = F_72 ( V_3 , V_213 ) ;
if ( V_172 != V_173 )
F_73 ( F_5 ( V_16 ) , V_163 -
V_168 -> V_219 +
V_168 -> V_222 ) ;
}
if ( V_213 < V_3 -> V_5 -> V_171 )
F_90 ( V_3 , V_213 ) ;
}
}
F_97 ( V_23 , V_149 ) ;
}
static int F_98 ( struct V_223 * V_224 )
{
struct V_2 * V_3 = F_99 ( V_224 ) ;
int V_40 ;
V_3 -> V_103 = V_3 -> V_5 -> V_54 ;
V_3 -> V_98 = F_100 ( & V_224 -> V_87 , V_3 -> V_103 ,
sizeof( * V_3 -> V_98 ) , V_225 ) ;
if ( ! V_3 -> V_98 )
return - V_226 ;
V_3 -> V_140 = F_100 ( & V_224 -> V_87 , V_3 -> V_103 ,
sizeof( * V_3 -> V_140 ) , V_225 ) ;
if ( ! V_3 -> V_140 )
return - V_226 ;
for ( V_40 = 0 ; V_40 < V_3 -> V_5 -> V_54 ; V_40 ++ ) {
const struct V_107 * V_4 = V_3 -> V_5 -> V_108 + V_40 ;
struct V_101 * V_96 = V_3 -> V_98 + V_40 ;
V_96 -> V_111 = V_4 -> V_4 . V_111 ;
V_96 -> V_4 = V_4 -> V_4 . V_113 ;
V_3 -> V_140 [ V_40 ] = V_4 -> V_4 . V_111 ;
}
return 0 ;
}
int F_101 ( struct V_223 * V_224 ,
const struct V_227 * V_120 ,
struct V_1 * V_1 )
{
struct V_228 * V_108 ;
struct V_2 * V_3 ;
struct V_124 * V_137 = V_224 -> V_87 . V_229 , * V_125 ;
struct V_126 * V_230 ;
struct V_231 * V_232 ;
int V_40 , V_85 , V_154 , V_233 ;
V_3 = F_102 ( & V_224 -> V_87 , sizeof( * V_3 ) , V_225 ) ;
if ( ! V_3 )
return - V_226 ;
F_103 ( V_224 , V_3 ) ;
V_230 = F_29 ( V_137 , L_12 , NULL ) ;
if ( ! V_230 ) {
F_18 ( & V_224 -> V_87 , L_13 ) ;
return - V_32 ;
}
V_125 = F_104 ( V_137 , L_14 , 0 ) ;
if ( V_125 ) {
V_3 -> V_9 = F_105 ( V_125 ) ;
if ( F_106 ( V_3 -> V_9 ) )
return F_107 ( V_3 -> V_9 ) ;
} else if ( V_1 ) {
V_3 -> V_9 = V_1 ;
} else {
F_18 ( & V_224 -> V_87 , L_15 ) ;
return - V_32 ;
}
V_125 = F_104 ( V_137 , L_14 , 1 ) ;
if ( V_125 ) {
V_3 -> V_8 = F_105 ( V_125 ) ;
if ( F_106 ( V_3 -> V_8 ) )
return F_107 ( V_3 -> V_8 ) ;
}
V_3 -> V_5 = V_120 ;
V_85 = F_98 ( V_224 ) ;
if ( V_85 ) {
F_18 ( & V_224 -> V_87 , L_16 , V_85 ) ;
return - V_32 ;
}
V_108 = F_100 ( & V_224 -> V_87 , V_3 -> V_5 -> V_54 , sizeof( * V_108 ) ,
V_225 ) ;
if ( ! V_108 )
return - V_226 ;
for ( V_40 = 0 ; V_40 < V_3 -> V_5 -> V_54 ; V_40 ++ )
V_108 [ V_40 ] = V_3 -> V_5 -> V_108 [ V_40 ] . V_4 ;
V_3 -> V_234 . V_111 = F_108 ( & V_224 -> V_87 ) ;
V_3 -> V_234 . V_235 = V_236 ;
V_3 -> V_234 . V_108 = V_108 ;
V_3 -> V_234 . V_54 = V_3 -> V_5 -> V_54 ;
V_3 -> V_234 . V_237 = & V_238 ;
V_3 -> V_234 . V_239 = & V_240 ;
V_3 -> V_234 . V_241 = & V_242 ;
V_3 -> V_87 = & V_224 -> V_87 ;
V_3 -> V_160 = F_109 ( & V_224 -> V_87 , & V_3 -> V_234 ,
V_3 ) ;
if ( F_106 ( V_3 -> V_160 ) ) {
F_18 ( & V_224 -> V_87 , L_17 ) ;
return F_107 ( V_3 -> V_160 ) ;
}
V_3 -> V_23 = F_102 ( & V_224 -> V_87 , sizeof( * V_3 -> V_23 ) , V_225 ) ;
if ( ! V_3 -> V_23 )
return - V_226 ;
* V_3 -> V_23 = V_243 ;
V_3 -> V_23 -> V_244 = V_3 -> V_5 -> V_54 ;
V_3 -> V_23 -> V_245 = F_108 ( & V_224 -> V_87 ) ;
V_3 -> V_23 -> V_182 = & V_224 -> V_87 ;
V_3 -> V_23 -> V_151 = - 1 ;
V_85 = F_110 ( V_3 -> V_23 , V_3 ) ;
if ( V_85 )
return - V_32 ;
V_85 = F_111 ( V_3 -> V_23 , F_108 ( & V_224 -> V_87 ) ,
0 , 0 , V_3 -> V_5 -> V_54 ) ;
if ( V_85 ) {
V_85 = - V_32 ;
goto V_246;
}
if ( ! F_112 ( V_137 , L_18 ) )
return 0 ;
V_232 = F_113 ( V_224 , V_247 , 0 ) ;
if ( ! V_232 ) {
F_18 ( & V_224 -> V_87 , L_19 ) ;
V_85 = - V_32 ;
goto V_246;
}
V_3 -> V_165 = F_114 ( & V_224 -> V_87 , V_232 ) ;
if ( F_106 ( V_3 -> V_165 ) ) {
V_85 = - V_32 ;
goto V_246;
}
V_233 = V_3 -> V_5 -> V_168 . V_208 ;
V_3 -> V_206 = F_100 ( & V_224 -> V_87 , V_233 ,
sizeof( * V_3 -> V_206 ) , V_225 ) ;
if ( ! V_3 -> V_206 ) {
V_85 = - V_226 ;
goto V_246;
}
V_3 -> V_210 = F_100 ( & V_224 -> V_87 , V_233 ,
sizeof( * V_3 -> V_210 ) , V_225 ) ;
if ( ! V_3 -> V_210 ) {
V_85 = - V_226 ;
goto V_246;
}
V_3 -> V_180 = F_100 ( & V_224 -> V_87 , V_3 -> V_5 -> V_164 ,
sizeof( int ) , V_225 ) ;
if ( ! V_3 -> V_180 ) {
V_85 = - V_226 ;
goto V_246;
}
V_154 = F_115 ( V_137 , 0 ) ;
if ( ! V_154 ) {
F_18 ( & V_224 -> V_87 , L_20 ) ;
V_85 = - V_32 ;
goto V_246;
}
V_3 -> V_156 = F_116 ( V_137 ,
V_3 -> V_5 -> V_164 , & V_248 , NULL ) ;
if ( ! V_3 -> V_156 ) {
F_18 ( & V_224 -> V_87 , L_21 ) ;
V_85 = - V_226 ;
goto V_246;
}
F_89 ( V_3 ) ;
for ( V_40 = 0 ; V_40 < V_3 -> V_5 -> V_164 ; V_40 ++ ) {
int V_183 = F_117 ( V_3 -> V_156 , V_40 ) ;
F_118 ( V_183 , & V_249 ,
V_250 ) ;
F_119 ( V_183 , V_3 ) ;
}
F_120 ( V_154 , F_91 , V_3 ) ;
return 0 ;
V_246:
F_121 ( V_3 -> V_23 ) ;
return V_85 ;
}

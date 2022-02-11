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
static void F_11 ( struct V_2 * V_3 , unsigned V_4 ,
int V_23 , enum V_26 V_27 )
{
unsigned int V_18 , V_16 ;
unsigned int V_19 ;
int V_28 ;
if ( V_3 -> V_5 -> V_29 ) {
V_28 = V_3 -> V_5 -> V_29 ( F_1 ( V_3 , V_4 ) ,
V_4 , V_3 -> V_5 -> V_30 , V_23 ) ;
if ( ! V_28 )
return;
}
V_19 = F_5 ( V_4 & 0xf ) ;
if ( V_27 == V_31 )
V_16 = V_3 -> V_5 -> V_32 ;
else
V_16 = V_3 -> V_5 -> V_33 ;
if ( V_23 )
V_18 = F_7 ( F_2 ( V_3 , V_4 ) + V_16 , V_3 ) ;
else
V_18 = F_6 ( F_2 ( V_3 , V_4 ) + V_16 , V_3 ) ;
F_8 ( F_1 ( V_3 , V_4 ) , V_18 , V_19 ) ;
}
static const struct V_34 * F_12 (
struct V_2 * V_3 , unsigned long V_4 ) {
int V_35 ;
for ( V_35 = 0 ; V_35 < V_3 -> V_5 -> V_36 ; V_35 ++ ) {
const struct V_34 * V_37 =
V_3 -> V_5 -> V_38 + V_35 ;
if ( V_4 == V_37 -> V_4 )
return V_37 ;
}
return NULL ;
}
static int F_13 ( struct V_2 * V_3 ,
unsigned int V_4 , unsigned char V_39 )
{
const struct V_34 * V_37 ;
unsigned int V_40 ;
unsigned int V_41 , V_42 , V_43 ;
const struct V_44 * V_45 ;
if ( V_4 >= V_3 -> V_5 -> V_46 )
return - V_47 ;
V_37 = F_12 ( V_3 , V_4 ) ;
if ( ! V_37 || V_37 -> V_48 > V_3 -> V_5 -> V_49 )
return - V_47 ;
V_45 = V_3 -> V_5 -> V_50 + V_37 -> V_48 ;
if ( V_39 >= V_45 -> V_51 && V_39 <= V_45 -> V_52
&& ! ( V_39 % V_45 -> V_53 ) ) {
V_40 = V_39 / V_45 -> V_53 - 1 ;
V_41 = V_45 -> V_54 - V_45 -> V_55 + 1 ;
V_42 = F_5 ( V_41 ) - 1 ;
V_43 = V_37 -> V_19 + V_45 -> V_55 ;
V_42 <<= V_43 ;
V_40 <<= V_43 ;
return F_14 ( F_1 ( V_3 , V_4 ) ,
V_37 -> V_16 , V_42 , V_40 ) ;
}
return - V_47 ;
}
static int F_15 ( struct V_2 * V_3 ,
unsigned int V_4 , bool V_56 , bool V_57 , unsigned int V_58 )
{
unsigned int V_19 ;
unsigned int V_59 , V_60 ;
int V_28 ;
if ( V_3 -> V_5 -> V_61 ) {
V_28 = V_3 -> V_5 -> V_61 ( F_1 ( V_3 , V_4 ) ,
V_4 , V_3 -> V_5 -> V_30 , V_57 , V_58 ) ;
if ( ! V_28 )
return 0 ;
}
if ( V_58 != 0 && V_58 != 1 ) {
F_16 ( V_3 -> V_24 , L_1 ,
V_58 , V_4 ) ;
return - V_47 ;
}
V_19 = F_5 ( V_4 & 0xf ) ;
if ( V_56 )
V_59 = F_7 ( F_2 ( V_3 , V_4 ) +
V_3 -> V_5 -> V_62 , V_3 ) ;
else
V_59 = F_6 ( F_2 ( V_3 , V_4 ) +
V_3 -> V_5 -> V_62 , V_3 ) ;
if ( V_57 )
V_60 = F_7 ( F_2 ( V_3 , V_4 ) +
V_3 -> V_5 -> V_63 , V_3 ) ;
else
V_60 = F_6 ( F_2 ( V_3 , V_4 ) +
V_3 -> V_5 -> V_63 , V_3 ) ;
F_8 ( F_1 ( V_3 , V_4 ) , V_59 , V_19 ) ;
F_8 ( F_1 ( V_3 , V_4 ) , V_60 , V_19 ) ;
return 0 ;
}
static int F_17 ( struct V_12 * V_13 ,
unsigned int V_4 , enum V_26 V_27 ,
enum V_26 V_58 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
switch ( V_27 ) {
case V_64 :
F_15 ( V_3 , V_4 , false , false , V_58 ) ;
break;
case V_65 :
F_15 ( V_3 , V_4 , true , true , V_58 ) ;
break;
case V_66 :
F_15 ( V_3 , V_4 , true , false , V_58 ) ;
break;
case V_31 :
F_11 ( V_3 , V_4 , V_58 , V_27 ) ;
break;
case V_67 :
F_9 ( V_3 -> V_22 , V_4 , V_58 ) ;
F_3 ( V_13 , NULL , V_4 , false ) ;
break;
case V_68 :
F_11 ( V_3 , V_4 , V_58 , V_27 ) ;
break;
case V_69 :
F_13 ( V_3 , V_4 , V_58 ) ;
break;
default:
return - V_47 ;
}
return 0 ;
}
static int F_18 ( struct V_12 * V_13 ,
unsigned V_70 ,
unsigned long * V_71 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
* V_71 = V_3 -> V_72 [ V_70 ] . V_71 ;
return 0 ;
}
static int F_19 ( struct V_12 * V_13 , unsigned V_70 ,
unsigned long * V_73 , unsigned V_74 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
struct V_75 * V_76 = & V_3 -> V_72 [ V_70 ] ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_74 ; V_35 ++ ) {
F_17 ( V_13 , V_76 -> V_4 ,
F_20 ( V_73 [ V_35 ] ) ,
F_21 ( V_73 [ V_35 ] ) ) ;
V_76 -> V_71 = V_73 [ V_35 ] ;
}
return 0 ;
}
static struct V_75 *
F_22 ( struct V_2 * V_3 , T_1 V_4 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_3 -> V_77 ; V_35 ++ ) {
struct V_75 * V_48 = V_3 -> V_72 + V_35 ;
if ( V_48 -> V_4 == V_4 )
return V_48 ;
}
return NULL ;
}
static const struct V_78 * F_23 (
struct V_2 * V_3 , T_1 V_79 , T_1 V_80 )
{
const struct V_81 * V_4 = V_3 -> V_5 -> V_82 + V_79 ;
const struct V_78 * V_83 = V_4 -> V_84 ;
while ( V_83 && V_83 -> V_85 ) {
if ( V_83 -> V_86 == V_80 )
return V_83 ;
V_83 ++ ;
}
return NULL ;
}
static bool F_24 ( struct V_2 * V_3 ,
T_1 V_79 , T_1 V_80 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_3 -> V_5 -> V_46 ; V_35 ++ ) {
const struct V_81 * V_4 = V_3 -> V_5 -> V_82 + V_35 ;
if ( V_4 -> V_4 . V_87 == V_79 ) {
const struct V_78 * V_83 =
V_4 -> V_84 ;
while ( V_83 && V_83 -> V_85 ) {
if ( V_83 -> V_86 == V_80 )
return true ;
V_83 ++ ;
}
break;
}
}
return false ;
}
static int F_25 ( struct V_2 * V_3 ,
T_1 V_4 , T_1 V_80 , struct V_75 * V_48 ,
struct V_88 * * V_89 , unsigned * V_90 ,
unsigned * V_91 )
{
bool V_28 ;
if ( * V_91 == * V_90 )
return - V_92 ;
( * V_89 ) [ * V_91 ] . type = V_93 ;
( * V_89 ) [ * V_91 ] . V_94 . V_95 . V_70 = V_48 -> V_85 ;
V_28 = F_24 ( V_3 , V_4 , V_80 ) ;
if ( ! V_28 ) {
F_16 ( V_3 -> V_24 , L_2 ,
V_80 , V_4 ) ;
return - V_47 ;
}
( * V_89 ) [ * V_91 ] . V_94 . V_95 . V_96 = V_97 [ V_80 ] ;
( * V_91 ) ++ ;
return 0 ;
}
static int F_26 ( struct V_12 * V_13 ,
struct V_98 * V_99 ,
struct V_88 * * V_89 ,
unsigned * V_90 ,
unsigned * V_91 )
{
struct V_100 * V_82 ;
T_1 V_101 , V_4 , V_83 ;
int V_102 , V_103 , V_104 ;
unsigned long * V_73 ;
unsigned int V_74 ;
bool V_105 = 0 ;
int V_35 , V_106 ;
unsigned V_107 = 0 ;
struct V_75 * V_48 ;
struct V_2 * V_3 = F_4 ( V_13 ) ;
V_82 = F_27 ( V_99 , L_3 , NULL ) ;
if ( ! V_82 ) {
F_16 ( V_3 -> V_24 , L_4 ,
V_99 -> V_85 ) ;
return - V_47 ;
}
V_106 = F_28 ( V_99 , V_13 , & V_73 ,
& V_74 ) ;
if ( V_74 )
V_105 = 1 ;
V_102 = V_82 -> V_108 / sizeof( T_1 ) ;
V_103 = V_102 ;
V_104 = 0 ;
if ( V_103 )
V_104 ++ ;
if ( V_105 && V_102 >= 1 )
V_104 ++ ;
if ( ! V_102 || ! V_104 )
return - V_47 ;
V_107 = V_102 * V_104 ;
V_106 = F_29 ( V_13 , V_89 ,
V_90 , V_91 , V_107 ) ;
if ( V_106 < 0 )
goto V_109;
for ( V_35 = 0 ; V_35 < V_102 ; V_35 ++ ) {
V_106 = F_30 ( V_99 , L_3 ,
V_35 , & V_101 ) ;
if ( V_106 )
goto V_109;
V_4 = F_31 ( V_101 ) ;
V_83 = F_32 ( V_101 ) ;
if ( V_4 >= V_3 -> V_5 -> V_46 ||
V_83 >= F_33 ( V_97 ) ) {
F_16 ( V_3 -> V_24 , L_5 ) ;
V_106 = - V_47 ;
goto V_109;
}
V_48 = F_22 ( V_3 , V_4 ) ;
if ( ! V_48 ) {
F_16 ( V_3 -> V_24 , L_6 ,
V_4 ) ;
return - V_47 ;
}
V_106 = F_25 ( V_3 , V_4 , V_83 , V_48 , V_89 ,
V_90 , V_91 ) ;
if ( V_106 < 0 )
goto V_109;
if ( V_105 ) {
V_106 = F_34 ( V_13 , V_89 ,
V_90 , V_91 , V_48 -> V_85 ,
V_73 , V_74 ,
V_110 ) ;
if ( V_106 < 0 )
goto V_109;
}
}
return 0 ;
V_109:
return V_106 ;
}
static int F_35 ( struct V_12 * V_13 ,
struct V_98 * V_111 ,
struct V_88 * * V_89 , unsigned * V_91 )
{
struct V_98 * V_112 ;
unsigned V_90 ;
int V_28 ;
* V_89 = NULL ;
* V_91 = 0 ;
V_90 = 0 ;
F_36 (np_config, np) {
V_28 = F_26 ( V_13 , V_112 , V_89 ,
& V_90 , V_91 ) ;
if ( V_28 < 0 ) {
F_37 ( V_13 , * V_89 , * V_91 ) ;
return V_28 ;
}
}
return 0 ;
}
static int F_38 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
return V_3 -> V_77 ;
}
static const char * F_39 ( struct V_12 * V_13 ,
unsigned V_70 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
return V_3 -> V_72 [ V_70 ] . V_85 ;
}
static int F_40 ( struct V_12 * V_13 ,
unsigned V_70 ,
const unsigned * * V_82 ,
unsigned * V_102 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
* V_82 = ( unsigned * ) & V_3 -> V_72 [ V_70 ] . V_4 ;
* V_102 = 1 ;
return 0 ;
}
static int F_41 ( struct V_12 * V_13 )
{
return F_33 ( V_97 ) ;
}
static const char * F_42 ( struct V_12 * V_13 ,
unsigned V_113 )
{
return V_97 [ V_113 ] ;
}
static int F_43 ( struct V_12 * V_13 ,
unsigned V_96 ,
const char * const * * V_72 ,
unsigned * const V_114 )
{
struct V_2 * V_3 = F_4 ( V_13 ) ;
* V_72 = V_3 -> V_115 ;
* V_114 = V_3 -> V_77 ;
return 0 ;
}
static int F_44 ( struct V_12 * V_13 ,
unsigned long V_4 , unsigned long V_116 )
{
unsigned int V_18 ;
unsigned char V_19 ;
unsigned int V_40 ;
unsigned int V_42 = ( 1L << V_117 ) - 1 ;
struct V_2 * V_3 = F_4 ( V_13 ) ;
V_18 = ( ( V_4 / V_118 ) << V_3 -> V_5 -> V_11 )
+ V_3 -> V_5 -> V_119 ;
V_19 = V_4 % V_118 ;
V_42 <<= ( V_117 * V_19 ) ;
V_40 = ( V_116 << ( V_117 * V_19 ) ) ;
return F_14 ( F_1 ( V_3 , V_4 ) ,
V_18 , V_42 , V_40 ) ;
}
static const struct V_81 *
F_45 ( struct V_2 * V_3 , unsigned int V_120 )
{
int V_35 ;
const struct V_81 * V_4 ;
for ( V_35 = 0 ; V_35 < V_3 -> V_5 -> V_46 ; V_35 ++ ) {
V_4 = V_3 -> V_5 -> V_82 + V_35 ;
if ( V_4 -> V_121 . V_122 == V_120 )
return V_4 ;
}
return NULL ;
}
static int F_46 ( struct V_12 * V_13 ,
unsigned V_96 ,
unsigned V_70 )
{
bool V_28 ;
const struct V_78 * V_123 ;
struct V_2 * V_3 = F_4 ( V_13 ) ;
struct V_75 * V_76 = V_3 -> V_72 + V_70 ;
V_28 = F_24 ( V_3 , V_76 -> V_4 , V_96 ) ;
if ( ! V_28 ) {
F_16 ( V_3 -> V_24 , L_7 ,
V_96 , V_70 ) ;
return - V_47 ;
}
V_123 = F_23 ( V_3 , V_76 -> V_4 , V_96 ) ;
if ( ! V_123 )
return - V_47 ;
F_44 ( V_13 , V_76 -> V_4 , V_123 -> V_86 ) ;
return 0 ;
}
static int F_47 ( struct V_21 * V_22 , unsigned V_16 )
{
return F_48 ( V_22 -> V_124 + V_16 ) ;
}
static void F_49 ( struct V_21 * V_22 , unsigned V_16 )
{
F_50 ( V_22 -> V_124 + V_16 ) ;
}
static int F_51 ( struct V_21 * V_22 ,
unsigned V_16 )
{
return F_52 ( V_22 -> V_124 + V_16 ) ;
}
static int F_53 ( struct V_21 * V_22 ,
unsigned V_16 , int V_23 )
{
F_9 ( V_22 , V_16 , V_23 ) ;
return F_54 ( V_22 -> V_124 + V_16 ) ;
}
static int F_55 ( struct V_21 * V_22 , unsigned V_16 )
{
unsigned int V_18 ;
unsigned int V_19 ;
unsigned int V_125 = 0 ;
struct V_2 * V_3 = F_10 ( V_22 -> V_24 ) ;
V_18 = F_2 ( V_3 , V_16 ) + V_3 -> V_5 -> V_20 ;
V_19 = F_5 ( V_16 & 0xf ) ;
F_56 ( V_3 -> V_9 , V_18 , & V_125 ) ;
return ! ! ( V_125 & V_19 ) ;
}
static int F_57 ( struct V_21 * V_22 , unsigned V_16 )
{
unsigned int V_18 ;
unsigned int V_19 ;
unsigned int V_125 = 0 ;
struct V_2 * V_3 = F_10 ( V_22 -> V_24 ) ;
if ( F_55 ( V_22 , V_16 ) )
V_18 = F_2 ( V_3 , V_16 ) +
V_3 -> V_5 -> V_25 ;
else
V_18 = F_2 ( V_3 , V_16 ) +
V_3 -> V_5 -> V_126 ;
V_19 = F_5 ( V_16 & 0xf ) ;
F_56 ( V_3 -> V_9 , V_18 , & V_125 ) ;
return ! ! ( V_125 & V_19 ) ;
}
static int F_58 ( struct V_21 * V_22 , unsigned V_16 )
{
const struct V_81 * V_4 ;
struct V_2 * V_3 = F_10 ( V_22 -> V_24 ) ;
int V_127 ;
V_4 = V_3 -> V_5 -> V_82 + V_16 ;
if ( V_4 -> V_121 . V_122 == V_128 )
return - V_47 ;
V_127 = F_59 ( V_3 -> V_129 , V_4 -> V_121 . V_122 ) ;
if ( ! V_127 )
return - V_47 ;
return V_127 ;
}
static int F_60 ( struct V_130 * V_131 )
{
struct V_2 * V_3 = F_61 ( V_131 ) ;
const struct V_81 * V_4 ;
int V_28 ;
V_4 = F_45 ( V_3 , V_131 -> V_132 ) ;
if ( ! V_4 ) {
F_16 ( V_3 -> V_24 , L_8 ) ;
return - V_47 ;
}
V_28 = F_62 ( V_3 -> V_22 , V_4 -> V_4 . V_87 ) ;
if ( V_28 ) {
F_16 ( V_3 -> V_24 , L_9 ,
F_63 ( V_131 ) ) ;
return V_28 ;
}
F_44 ( V_3 -> V_133 , V_4 -> V_4 . V_87 , V_4 -> V_121 . V_134 ) ;
return 0 ;
}
static void F_64 ( struct V_130 * V_131 )
{
struct V_2 * V_3 = F_61 ( V_131 ) ;
const struct V_81 * V_4 ;
V_4 = F_45 ( V_3 , V_131 -> V_132 ) ;
if ( ! V_4 ) {
F_16 ( V_3 -> V_24 , L_8 ) ;
return;
}
F_65 ( V_3 -> V_22 , V_4 -> V_4 . V_87 ) ;
}
static void T_2 * F_66 ( struct V_2 * V_3 ,
unsigned int V_120 , unsigned int V_16 )
{
unsigned int V_135 = 0 ;
void T_2 * V_136 ;
if ( V_120 >= V_3 -> V_5 -> V_137 )
V_135 = V_3 -> V_5 -> V_137 ;
V_136 = V_3 -> V_138 + V_16 + ( ( V_120 - V_135 ) / 32 ) * 4 ;
return V_136 ;
}
static unsigned int F_67 ( struct V_2 * V_3 ,
unsigned int V_120 )
{
unsigned int V_139 ;
unsigned int V_19 = F_5 ( V_120 % 32 ) ;
const struct V_140 * V_141 =
& V_3 -> V_5 -> V_141 ;
void T_2 * V_136 = F_66 ( V_3 , V_120 ,
V_141 -> V_139 ) ;
if ( F_68 ( V_136 ) & V_19 )
V_139 = V_142 ;
else
V_139 = V_143 ;
if ( ( V_120 < V_3 -> V_5 -> V_144 ) && ( V_139 != V_143 ) )
return 1 ;
else
return 0 ;
}
static unsigned int F_69 ( struct V_2 * V_3 ,
unsigned int V_120 )
{
unsigned int V_19 = F_5 ( V_120 % 32 ) ;
const struct V_140 * V_141 =
& V_3 -> V_5 -> V_141 ;
void T_2 * V_136 = F_66 ( V_3 , V_120 ,
V_141 -> V_42 ) ;
return ! ! ( F_68 ( V_136 ) & V_19 ) ;
}
static int F_70 ( struct V_2 * V_3 , int V_132 )
{
int V_145 , V_146 ;
unsigned int V_147 ;
const struct V_140 * V_141 = & ( V_3 -> V_5 -> V_141 ) ;
T_1 V_42 = 1 << ( V_132 & 0x1f ) ;
T_1 V_148 = ( V_132 >> 5 ) & V_141 -> V_10 ;
void T_2 * V_136 = V_3 -> V_138 + ( V_148 << 2 ) ;
const struct V_81 * V_4 ;
V_4 = F_45 ( V_3 , V_132 ) ;
V_146 = F_57 ( V_3 -> V_22 , V_4 -> V_4 . V_87 ) ;
do {
V_145 = V_146 ;
if ( V_145 )
V_147 = V_141 -> V_149 ;
else
V_147 = V_141 -> V_150 ;
F_71 ( V_42 , V_136 + V_147 ) ;
V_146 = F_57 ( V_3 -> V_22 , V_4 -> V_4 . V_87 ) ;
} while ( V_145 != V_146 );
return V_145 ;
}
static void F_72 ( struct V_130 * V_131 )
{
struct V_2 * V_3 = F_61 ( V_131 ) ;
const struct V_140 * V_141 =
& V_3 -> V_5 -> V_141 ;
T_1 V_42 = F_5 ( V_131 -> V_132 & 0x1f ) ;
void T_2 * V_136 = F_66 ( V_3 , V_131 -> V_132 ,
V_141 -> V_151 ) ;
F_71 ( V_42 , V_136 ) ;
}
static void F_73 ( struct V_130 * V_131 )
{
struct V_2 * V_3 = F_61 ( V_131 ) ;
const struct V_140 * V_141 =
& V_3 -> V_5 -> V_141 ;
T_1 V_42 = F_5 ( V_131 -> V_132 & 0x1f ) ;
void T_2 * V_136 = F_66 ( V_3 , V_131 -> V_132 ,
V_141 -> V_152 ) ;
F_71 ( V_42 , V_136 ) ;
if ( V_3 -> V_153 [ V_131 -> V_132 ] )
F_70 ( V_3 , V_131 -> V_132 ) ;
}
static int F_74 ( struct V_21 * V_22 , unsigned V_16 ,
unsigned V_154 )
{
struct V_2 * V_3 = F_10 ( V_22 -> V_24 ) ;
int V_120 , V_155 , V_156 ;
unsigned int V_157 , V_19 , V_158 , V_159 , V_160 , V_35 , V_161 , V_162 ;
static const unsigned int V_163 [] = { 0 , 1 , 16 , 32 , 64 , 128 , 256 } ;
const struct V_81 * V_4 ;
struct V_130 * V_131 ;
V_4 = V_3 -> V_5 -> V_82 + V_16 ;
if ( V_4 -> V_121 . V_122 == V_128 )
return - V_47 ;
V_120 = V_4 -> V_121 . V_122 ;
V_155 = F_59 ( V_3 -> V_129 , V_120 ) ;
V_156 = ( V_120 % 4 ) * 8 ;
V_131 = F_75 ( V_155 ) ;
V_157 = ( V_120 / 4 ) * 4 + V_3 -> V_5 -> V_141 . V_164 ;
V_159 = ( V_120 / 4 ) * 4 + V_3 -> V_5 -> V_141 . V_165 ;
if ( ! F_67 ( V_3 , V_120 ) )
return - V_166 ;
V_162 = F_33 ( V_163 ) ;
for ( V_35 = 0 ; V_35 < F_33 ( V_163 ) ; V_35 ++ ) {
if ( V_154 <= V_163 [ V_35 ] ) {
V_162 = V_35 ;
break;
}
}
if ( ! F_69 ( V_3 , V_120 ) ) {
F_72 ( V_131 ) ;
V_161 = 1 ;
} else {
V_161 = 0 ;
}
V_158 = 0xff << V_156 ;
F_71 ( V_158 , V_3 -> V_138 + V_159 ) ;
V_19 = ( ( V_162 << V_167 ) | V_168 ) <<
V_156 ;
V_160 = V_169 << V_156 ;
F_71 ( V_160 | V_19 , V_3 -> V_138 + V_157 ) ;
F_76 ( 1 ) ;
if ( V_161 == 1 )
F_73 ( V_131 ) ;
return 0 ;
}
static int F_77 ( struct V_130 * V_131 ,
unsigned int type )
{
struct V_2 * V_3 = F_61 ( V_131 ) ;
const struct V_140 * V_141 =
& V_3 -> V_5 -> V_141 ;
T_1 V_42 = F_5 ( V_131 -> V_132 & 0x1f ) ;
void T_2 * V_136 ;
if ( ( ( type & V_170 ) && ( type & V_171 ) ) ||
( ( type & V_171 ) == V_171 ) ) {
F_16 ( V_3 -> V_24 , L_10 ,
V_131 -> V_127 , V_131 -> V_132 , type ) ;
return - V_47 ;
}
if ( ( type & V_170 ) == V_170 )
V_3 -> V_153 [ V_131 -> V_132 ] = 1 ;
else
V_3 -> V_153 [ V_131 -> V_132 ] = 0 ;
if ( type & ( V_172 | V_173 ) ) {
V_136 = F_66 ( V_3 , V_131 -> V_132 ,
V_141 -> V_149 ) ;
F_71 ( V_42 , V_136 ) ;
} else {
V_136 = F_66 ( V_3 , V_131 -> V_132 ,
V_141 -> V_150 ) ;
F_71 ( V_42 , V_136 ) ;
}
if ( type & ( V_174 | V_173 ) ) {
V_136 = F_66 ( V_3 , V_131 -> V_132 ,
V_141 -> V_175 ) ;
F_71 ( V_42 , V_136 ) ;
} else {
V_136 = F_66 ( V_3 , V_131 -> V_132 ,
V_141 -> V_176 ) ;
F_71 ( V_42 , V_136 ) ;
}
if ( V_3 -> V_153 [ V_131 -> V_132 ] )
F_70 ( V_3 , V_131 -> V_132 ) ;
return 0 ;
}
static void F_78 ( struct V_130 * V_131 )
{
struct V_2 * V_3 = F_61 ( V_131 ) ;
const struct V_140 * V_141 =
& V_3 -> V_5 -> V_141 ;
T_1 V_42 = F_5 ( V_131 -> V_132 & 0x1f ) ;
void T_2 * V_136 = F_66 ( V_3 , V_131 -> V_132 ,
V_141 -> V_177 ) ;
F_71 ( V_42 , V_136 ) ;
}
static unsigned int F_79 ( struct V_2 * V_3 )
{
const struct V_140 * V_141 =
& V_3 -> V_5 -> V_141 ;
void T_2 * V_136 = V_3 -> V_138 + V_141 -> V_178 ;
unsigned int V_35 ;
for ( V_35 = 0 ; V_35 < V_3 -> V_5 -> V_137 ; V_35 += 32 ) {
F_71 ( 0xffffffff , V_136 ) ;
V_136 += 4 ;
}
return 0 ;
}
static inline void
F_80 ( struct V_2 * V_3 , int V_179 )
{
unsigned int V_160 , V_180 ;
unsigned int V_19 , V_162 ;
const struct V_140 * V_141 =
& V_3 -> V_5 -> V_141 ;
V_180 = ( V_179 / 4 ) * 4 + V_141 -> V_181 ;
V_162 = F_68 ( V_3 -> V_138 + V_180 ) ;
V_19 = V_168 << ( ( V_179 % 4 ) * 8 ) ;
if ( ( V_19 & V_162 ) > 0 ) {
V_180 = ( V_179 / 4 ) * 4 + V_141 -> V_164 ;
V_160 = V_169 << ( ( V_179 % 4 ) * 8 ) ;
F_71 ( V_160 , V_3 -> V_138 + V_180 ) ;
}
}
static void F_81 ( unsigned V_127 , struct V_182 * V_123 )
{
struct V_183 * V_22 = F_82 ( V_127 ) ;
struct V_2 * V_3 = F_83 ( V_127 ) ;
unsigned int V_184 , V_120 ;
int V_16 , V_179 , V_155 ;
const struct V_140 * V_141 =
& V_3 -> V_5 -> V_141 ;
void T_2 * V_136 = F_66 ( V_3 , 0 , V_141 -> V_185 ) ;
int V_186 , V_145 , V_146 ;
const struct V_81 * V_4 ;
F_84 ( V_22 , V_123 ) ;
for ( V_120 = 0 ; V_120 < V_3 -> V_5 -> V_137 ; V_120 += 32 ) {
V_184 = F_68 ( V_136 ) ;
V_136 += 4 ;
while ( V_184 ) {
V_16 = F_85 ( V_184 ) ;
V_179 = V_120 + V_16 ;
V_155 = F_59 ( V_3 -> V_129 , V_179 ) ;
V_184 &= ~ F_5 ( V_16 ) ;
V_186 = V_3 -> V_153 [ V_179 ] ;
if ( V_186 ) {
F_71 ( F_5 ( V_16 ) , V_136 - V_141 -> V_185 +
V_141 -> V_187 ) ;
V_4 = F_45 ( V_3 , V_179 ) ;
V_145 = F_57 ( V_3 -> V_22 ,
V_4 -> V_4 . V_87 ) ;
}
F_86 ( V_155 ) ;
if ( V_186 ) {
V_146 = F_70 ( V_3 , V_179 ) ;
if ( V_145 != V_146 )
F_71 ( F_5 ( V_16 ) , V_136 -
V_141 -> V_185 +
V_141 -> V_188 ) ;
}
if ( V_179 < V_3 -> V_5 -> V_144 )
F_80 ( V_3 , V_179 ) ;
}
}
F_87 ( V_22 , V_123 ) ;
}
static int F_88 ( struct V_189 * V_190 )
{
struct V_2 * V_3 = F_89 ( V_190 ) ;
int V_35 ;
V_3 -> V_77 = V_3 -> V_5 -> V_46 ;
V_3 -> V_72 = F_90 ( & V_190 -> V_24 , V_3 -> V_77 ,
sizeof( * V_3 -> V_72 ) , V_191 ) ;
if ( ! V_3 -> V_72 )
return - V_192 ;
V_3 -> V_115 = F_90 ( & V_190 -> V_24 , V_3 -> V_77 ,
sizeof( * V_3 -> V_115 ) , V_191 ) ;
if ( ! V_3 -> V_115 )
return - V_192 ;
for ( V_35 = 0 ; V_35 < V_3 -> V_5 -> V_46 ; V_35 ++ ) {
const struct V_81 * V_4 = V_3 -> V_5 -> V_82 + V_35 ;
struct V_75 * V_70 = V_3 -> V_72 + V_35 ;
V_70 -> V_85 = V_4 -> V_4 . V_85 ;
V_70 -> V_4 = V_4 -> V_4 . V_87 ;
V_3 -> V_115 [ V_35 ] = V_4 -> V_4 . V_85 ;
}
return 0 ;
}
int F_91 ( struct V_189 * V_190 ,
const struct V_193 * V_94 )
{
struct V_194 * V_82 ;
struct V_2 * V_3 ;
struct V_98 * V_112 = V_190 -> V_24 . V_195 , * V_99 ;
struct V_100 * V_196 ;
struct V_197 * V_198 ;
int V_35 , V_28 , V_127 ;
V_3 = F_92 ( & V_190 -> V_24 , sizeof( * V_3 ) , V_191 ) ;
if ( ! V_3 )
return - V_192 ;
F_93 ( V_190 , V_3 ) ;
V_196 = F_27 ( V_112 , L_11 , NULL ) ;
if ( ! V_196 ) {
F_16 ( & V_190 -> V_24 , L_12 ) ;
return - V_47 ;
}
V_99 = F_94 ( V_112 , L_13 , 0 ) ;
if ( V_99 ) {
V_3 -> V_9 = F_95 ( V_99 ) ;
if ( F_96 ( V_3 -> V_9 ) )
return F_97 ( V_3 -> V_9 ) ;
}
V_99 = F_94 ( V_112 , L_13 , 1 ) ;
if ( V_99 ) {
V_3 -> V_8 = F_95 ( V_99 ) ;
if ( F_96 ( V_3 -> V_8 ) )
return F_97 ( V_3 -> V_8 ) ;
}
V_3 -> V_5 = V_94 ;
V_28 = F_88 ( V_190 ) ;
if ( V_28 ) {
F_16 ( & V_190 -> V_24 , L_14 , V_28 ) ;
return - V_47 ;
}
V_82 = F_90 ( & V_190 -> V_24 , V_3 -> V_5 -> V_46 , sizeof( * V_82 ) ,
V_191 ) ;
if ( ! V_82 )
return - V_192 ;
for ( V_35 = 0 ; V_35 < V_3 -> V_5 -> V_46 ; V_35 ++ )
V_82 [ V_35 ] = V_3 -> V_5 -> V_82 [ V_35 ] . V_4 ;
V_199 . V_85 = F_98 ( & V_190 -> V_24 ) ;
V_199 . V_200 = V_201 ;
V_199 . V_82 = V_82 ;
V_199 . V_46 = V_3 -> V_5 -> V_46 ;
V_3 -> V_24 = & V_190 -> V_24 ;
V_3 -> V_133 = F_99 ( & V_199 , & V_190 -> V_24 , V_3 ) ;
if ( ! V_3 -> V_133 ) {
F_16 ( & V_190 -> V_24 , L_15 ) ;
return - V_47 ;
}
V_3 -> V_22 = F_92 ( & V_190 -> V_24 , sizeof( * V_3 -> V_22 ) , V_191 ) ;
if ( ! V_3 -> V_22 ) {
V_28 = - V_192 ;
goto V_202;
}
V_3 -> V_22 = & V_203 ;
V_3 -> V_22 -> V_204 = V_3 -> V_5 -> V_46 ;
V_3 -> V_22 -> V_205 = F_98 ( & V_190 -> V_24 ) ;
V_3 -> V_22 -> V_24 = & V_190 -> V_24 ;
V_3 -> V_22 -> V_124 = 0 ;
V_28 = F_100 ( V_3 -> V_22 ) ;
if ( V_28 ) {
V_28 = - V_47 ;
goto V_202;
}
V_28 = F_101 ( V_3 -> V_22 , F_98 ( & V_190 -> V_24 ) ,
0 , 0 , V_3 -> V_5 -> V_46 ) ;
if ( V_28 ) {
V_28 = - V_47 ;
goto V_206;
}
V_198 = F_102 ( V_190 , V_207 , 0 ) ;
if ( ! V_198 ) {
F_16 ( & V_190 -> V_24 , L_16 ) ;
V_28 = - V_47 ;
goto V_206;
}
V_3 -> V_138 = F_103 ( & V_190 -> V_24 , V_198 ) ;
if ( F_96 ( V_3 -> V_138 ) ) {
V_28 = - V_47 ;
goto V_206;
}
V_3 -> V_153 = F_90 ( & V_190 -> V_24 , V_3 -> V_5 -> V_137 ,
sizeof( int ) , V_191 ) ;
if ( ! V_3 -> V_153 ) {
V_28 = - V_192 ;
goto V_206;
}
V_127 = F_104 ( V_112 , 0 ) ;
if ( ! V_127 ) {
F_16 ( & V_190 -> V_24 , L_17 ) ;
V_28 = - V_47 ;
goto V_206;
}
V_3 -> V_129 = F_105 ( V_112 ,
V_3 -> V_5 -> V_137 , & V_208 , NULL ) ;
if ( ! V_3 -> V_129 ) {
F_16 ( & V_190 -> V_24 , L_18 ) ;
V_28 = - V_192 ;
goto V_206;
}
F_79 ( V_3 ) ;
for ( V_35 = 0 ; V_35 < V_3 -> V_5 -> V_137 ; V_35 ++ ) {
int V_155 = F_106 ( V_3 -> V_129 , V_35 ) ;
F_107 ( V_155 , & V_209 ,
V_210 ) ;
F_108 ( V_155 , V_3 ) ;
F_109 ( V_155 , V_211 ) ;
} ;
F_110 ( V_127 , F_81 ) ;
F_111 ( V_127 , V_3 ) ;
F_109 ( V_127 , V_211 ) ;
return 0 ;
V_206:
F_112 ( V_3 -> V_22 ) ;
V_202:
F_113 ( V_3 -> V_133 ) ;
return V_28 ;
}

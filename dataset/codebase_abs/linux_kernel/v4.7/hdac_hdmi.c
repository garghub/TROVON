static struct V_1 * F_1 ( struct V_2 * V_3 ,
int V_4 )
{
struct V_1 * V_5 ;
F_2 (pcm, &hdmi->pcm_list, head) {
if ( V_5 -> V_6 == V_4 )
return V_5 ;
}
return NULL ;
}
static inline struct V_7 * F_3 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
return F_5 ( V_11 ) ;
}
static unsigned int F_6 ( const T_1 * V_12 )
{
return ( ( V_12 [ 0 ] >> 0x3 ) & 0x1f ) ;
}
static unsigned int F_7 ( const T_1 * V_12 )
{
return ( V_12 [ 2 ] & 7 ) ;
}
static int F_8 ( struct V_13 * V_14 ,
void * V_15 )
{
T_2 V_16 = V_17 ;
int V_18 ;
const T_1 * V_12 , * V_19 = V_15 ;
V_12 = F_9 ( V_19 ) ;
if ( ! V_12 )
goto V_20;
for ( V_18 = F_10 ( V_19 ) ; V_18 > 0 ; V_18 -- , V_12 += 3 ) {
if ( F_6 ( V_12 ) == 1 ) {
if ( F_7 ( V_12 ) & 0x6 )
V_16 |= V_21 ;
}
}
V_20:
return F_11 ( V_14 , V_22 ,
V_16 ) ;
}
static unsigned int F_12 ( struct V_10 * V_23 ,
T_3 V_24 , int V_25 )
{
unsigned int V_26 ;
V_26 = F_13 ( V_23 , V_24 , 0 , V_27 ,
V_25 ) ;
F_14 ( & V_23 -> V_9 , L_1 ,
V_25 , V_26 ) ;
return V_26 ;
}
static int F_15 ( struct V_10 * V_23 , T_3 V_24 )
{
return F_13 ( V_23 , V_24 , 0 , V_28 ,
V_29 ) ;
}
static int F_16 ( struct V_10 * V_23 , T_3 V_24 ,
unsigned char * V_30 , int * V_31 )
{
int V_18 , V_32 , V_33 = 0 ;
V_32 = F_15 ( V_23 , V_24 ) ;
if ( V_32 < V_34 || V_32 > V_35 ) {
F_17 ( & V_23 -> V_9 , L_2 , V_32 ) ;
return - V_36 ;
}
for ( V_18 = 0 ; V_18 < V_32 ; V_18 ++ ) {
unsigned int V_26 = F_12 ( V_23 , V_24 , V_18 ) ;
if ( ! ( V_26 & V_37 ) ) {
F_17 ( & V_23 -> V_9 ,
L_3 , V_18 ) ;
V_33 = - V_38 ;
goto error;
}
V_26 &= V_39 ;
if ( ! V_26 && ! V_18 ) {
F_17 ( & V_23 -> V_9 , L_4 ) ;
V_33 = - V_38 ;
goto error;
}
V_30 [ V_18 ] = V_26 ;
}
* V_31 = V_32 ;
error:
return V_33 ;
}
static int F_18 ( struct V_7 * V_11 ,
T_3 V_40 , T_3 V_41 ,
T_4 V_42 , int V_43 )
{
unsigned int V_26 ;
F_14 ( & V_11 -> V_11 . V_9 , L_5 ,
V_40 , V_41 , V_42 , V_43 ) ;
V_26 = ( V_42 << 4 ) ;
F_19 ( & V_11 -> V_11 , V_40 , 0 ,
V_44 , V_26 ) ;
F_19 ( & V_11 -> V_11 , V_40 , 0 ,
V_45 , V_43 ) ;
return 0 ;
}
static void
F_20 ( struct V_7 * V_11 , T_3 V_41 ,
int V_46 , int V_25 )
{
int V_26 ;
V_26 = ( V_46 << 5 ) | ( V_25 & 0x1f ) ;
F_19 ( & V_11 -> V_11 , V_41 , 0 ,
V_47 , V_26 ) ;
}
static int F_21 ( struct V_7 * V_11 ,
T_3 V_40 , T_3 V_41 )
{
T_5 V_48 [ V_49 + V_50 ] ;
struct V_51 V_52 ;
struct V_53 V_54 ;
struct V_2 * V_3 = V_11 -> V_55 ;
struct V_56 * V_57 ;
T_1 * V_58 ;
int V_33 ;
int V_18 ;
const T_1 * V_19 ;
T_1 V_59 ;
int V_60 , V_61 ;
F_2 (pin, &hdmi->pin_list, head) {
if ( V_57 -> V_24 == V_41 )
break;
}
V_61 = F_22 ( & V_11 -> V_11 , V_57 -> V_15 . V_62 . V_63 ,
V_57 -> V_60 , V_57 -> V_64 , true , V_57 -> V_65 ) ;
V_60 = F_23 ( V_61 ) ;
V_3 -> V_65 . V_66 . V_67 ( & V_11 -> V_11 , V_40 , V_60 ) ;
F_24 ( & V_3 -> V_65 , V_57 -> V_24 , false , V_61 ,
V_57 -> V_60 , V_57 -> V_65 , V_57 -> V_64 ) ;
V_19 = V_57 -> V_15 . V_68 ;
V_59 = F_25 ( V_19 ) ;
switch ( V_59 ) {
case V_69 :
F_26 ( & V_52 ) ;
V_52 . V_60 = V_60 ;
V_52 . V_70 = V_61 ;
V_33 = F_27 ( & V_52 , V_48 , sizeof( V_48 ) ) ;
if ( V_33 < 0 )
return V_33 ;
break;
case V_71 :
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . type = 0x84 ;
V_54 . V_72 = 0x1b ;
V_54 . V_73 = 0x11 << 2 ;
V_54 . V_74 = V_60 - 1 ;
V_54 . V_75 = V_61 ;
V_58 = ( T_1 * ) & V_54 ;
break;
default:
F_17 ( & V_11 -> V_11 . V_9 , L_6 ,
V_59 ) ;
return - V_76 ;
}
F_20 ( V_11 , V_41 , 0x0 , 0x0 ) ;
F_19 ( & V_11 -> V_11 , V_41 , 0 ,
V_77 , V_78 ) ;
F_20 ( V_11 , V_41 , 0x0 , 0x0 ) ;
if ( V_59 == V_69 ) {
for ( V_18 = 0 ; V_18 < sizeof( V_48 ) ; V_18 ++ )
F_19 ( & V_11 -> V_11 , V_41 , 0 ,
V_79 , V_48 [ V_18 ] ) ;
} else {
for ( V_18 = 0 ; V_18 < sizeof( V_54 ) ; V_18 ++ )
F_19 ( & V_11 -> V_11 , V_41 , 0 ,
V_79 , V_58 [ V_18 ] ) ;
}
F_20 ( V_11 , V_41 , 0x0 , 0x0 ) ;
F_19 ( & V_11 -> V_11 , V_41 , 0 ,
V_77 , V_80 ) ;
return 0 ;
}
static void F_28 ( struct V_7 * V_81 ,
struct V_82 * V_83 , unsigned int V_84 )
{
if ( ! F_29 ( & V_81 -> V_11 , V_83 -> V_57 -> V_24 ,
V_84 ) )
F_19 ( & V_81 -> V_11 , V_83 -> V_57 -> V_24 , 0 ,
V_85 , V_84 ) ;
if ( ! F_29 ( & V_81 -> V_11 , V_83 -> V_86 -> V_24 ,
V_84 ) )
F_19 ( & V_81 -> V_11 , V_83 -> V_86 -> V_24 , 0 ,
V_85 , V_84 ) ;
}
static int F_30 ( struct V_87 * V_88 ,
struct V_89 * V_90 )
{
struct V_7 * V_11 = F_31 ( V_90 ) ;
struct V_2 * V_3 = V_11 -> V_55 ;
struct V_82 * V_83 ;
struct V_56 * V_57 ;
struct V_91 * V_92 ;
int V_33 ;
V_83 = & V_3 -> V_83 [ V_90 -> V_93 ] ;
V_57 = V_83 -> V_57 ;
V_92 = (struct V_91 * ) F_32 ( V_90 , V_88 ) ;
F_14 ( & V_11 -> V_11 . V_9 , L_7 ,
V_92 -> V_42 , V_92 -> V_43 ) ;
F_33 ( & V_57 -> V_94 ) ;
V_57 -> V_60 = V_88 -> V_14 -> V_60 ;
V_33 = F_21 ( V_11 , V_83 -> V_86 -> V_24 ,
V_83 -> V_57 -> V_24 ) ;
F_34 ( & V_57 -> V_94 ) ;
if ( V_33 < 0 )
return V_33 ;
return F_18 ( V_11 , V_83 -> V_86 -> V_24 ,
V_83 -> V_57 -> V_24 , V_92 -> V_42 , V_92 -> V_43 ) ;
}
static int F_35 ( struct V_87 * V_88 ,
struct V_95 * V_96 , struct V_89 * V_90 )
{
struct V_7 * V_11 = F_31 ( V_90 ) ;
struct V_2 * V_3 = V_11 -> V_55 ;
struct V_82 * V_83 ;
struct V_56 * V_57 ;
struct V_91 * V_92 ;
V_83 = & V_3 -> V_83 [ V_90 -> V_93 ] ;
V_57 = V_83 -> V_57 ;
if ( ! V_57 )
return - V_97 ;
if ( ( ! V_57 -> V_15 . V_98 ) || ( ! V_57 -> V_15 . V_99 ) ) {
F_17 ( & V_11 -> V_11 . V_9 , L_8 ,
V_57 -> V_24 ) ;
return - V_97 ;
}
V_92 = F_32 ( V_90 , V_88 ) ;
if ( ! V_92 ) {
V_92 = F_36 ( sizeof( * V_92 ) , V_100 ) ;
if ( ! V_92 )
return - V_101 ;
}
V_92 -> V_43 = F_37 ( F_38 ( V_96 ) ,
F_39 ( V_96 ) , F_40 ( V_96 ) ,
24 , 0 ) ;
F_41 ( V_90 , V_88 , ( void * ) V_92 ) ;
return 0 ;
}
static int F_42 ( struct V_87 * V_88 ,
struct V_89 * V_90 )
{
struct V_7 * V_81 = F_31 ( V_90 ) ;
struct V_91 * V_92 ;
struct V_2 * V_3 = V_81 -> V_55 ;
struct V_82 * V_83 ;
V_83 = & V_3 -> V_83 [ V_90 -> V_93 ] ;
V_92 = (struct V_91 * ) F_32 ( V_90 , V_88 ) ;
if ( V_92 ) {
F_41 ( V_90 , V_88 , NULL ) ;
F_43 ( V_92 ) ;
}
return 0 ;
}
static void F_44 ( struct V_7 * V_81 ,
struct V_82 * V_83 )
{
F_19 ( & V_81 -> V_11 , V_83 -> V_86 -> V_24 , 0 ,
V_102 , 1 ) ;
F_19 ( & V_81 -> V_11 , V_83 -> V_86 -> V_24 , 0 ,
V_103 , 0 ) ;
}
static int F_45 ( struct V_7 * V_11 ,
struct V_82 * V_83 )
{
int V_104 ;
struct V_56 * V_57 = V_83 -> V_57 ;
for ( V_104 = 0 ; V_104 < V_57 -> V_105 ; V_104 ++ ) {
if ( V_57 -> V_106 [ V_104 ] == V_83 -> V_86 -> V_24 ) {
F_19 ( & V_11 -> V_11 , V_57 -> V_24 , 0 ,
V_107 , V_104 ) ;
break;
}
}
if ( V_104 == V_57 -> V_105 )
return - V_76 ;
F_19 ( & V_11 -> V_11 , V_57 -> V_24 , 0 ,
V_108 , V_109 ) ;
F_28 ( V_11 , V_83 , V_110 ) ;
F_19 ( & V_11 -> V_11 , V_57 -> V_24 , 0 ,
V_111 , V_112 ) ;
return 0 ;
}
static int F_46 ( struct V_7 * V_11 ,
struct V_56 * V_57 )
{
if ( ! ( F_47 ( & V_11 -> V_11 , V_57 -> V_24 ) & V_113 ) ) {
F_48 ( & V_11 -> V_11 . V_9 ,
L_9 ,
V_57 -> V_24 , F_47 ( & V_11 -> V_11 , V_57 -> V_24 ) ) ;
return - V_38 ;
}
V_57 -> V_105 = F_49 ( & V_11 -> V_11 , V_57 -> V_24 ,
V_57 -> V_106 , V_114 ) ;
if ( V_57 -> V_105 == 0 )
F_48 ( & V_11 -> V_11 . V_9 , L_10 ,
V_57 -> V_24 ) ;
F_14 ( & V_11 -> V_11 . V_9 , L_11 ,
V_57 -> V_105 , V_57 -> V_24 ) ;
return V_57 -> V_105 ;
}
static struct V_56 * F_50 (
struct V_7 * V_81 ,
struct V_2 * V_3 ,
struct V_115 * V_86 )
{
struct V_1 * V_5 ;
struct V_56 * V_57 = NULL ;
int V_33 , V_18 ;
F_2 (pcm, &hdmi->pcm_list, head) {
if ( V_5 -> V_86 == V_86 ) {
V_57 = V_5 -> V_57 ;
break;
}
}
if ( V_57 ) {
V_33 = F_46 ( V_81 , V_57 ) ;
if ( V_33 < 0 )
return NULL ;
for ( V_18 = 0 ; V_18 < V_57 -> V_105 ; V_18 ++ ) {
if ( V_57 -> V_106 [ V_18 ] == V_86 -> V_24 )
return V_57 ;
}
}
return NULL ;
}
static int F_51 ( struct V_87 * V_88 ,
struct V_89 * V_90 )
{
struct V_7 * V_11 = F_31 ( V_90 ) ;
struct V_2 * V_3 = V_11 -> V_55 ;
struct V_82 * V_83 ;
struct V_115 * V_86 ;
struct V_56 * V_57 ;
int V_33 ;
V_83 = & V_3 -> V_83 [ V_90 -> V_93 ] ;
V_86 = V_83 -> V_86 ;
V_57 = F_50 ( V_11 , V_3 , V_86 ) ;
if ( ! V_57 )
return 0 ;
if ( ( ! V_57 -> V_15 . V_98 ) ||
( ! V_57 -> V_15 . V_99 ) ) {
F_48 ( & V_11 -> V_11 . V_9 ,
L_12 ,
V_57 -> V_15 . V_98 , V_57 -> V_15 . V_99 , V_57 -> V_24 ) ;
return 0 ;
}
V_83 -> V_57 = V_57 ;
F_44 ( V_11 , V_83 ) ;
V_33 = F_45 ( V_11 , V_83 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_8 ( V_88 -> V_14 ,
V_57 -> V_15 . V_68 ) ;
if ( V_33 < 0 )
return V_33 ;
return F_52 ( V_88 -> V_14 ,
V_57 -> V_15 . V_68 ) ;
}
static int F_53 ( struct V_87 * V_88 , int V_116 ,
struct V_89 * V_90 )
{
struct V_82 * V_83 ;
struct V_7 * V_11 = F_31 ( V_90 ) ;
struct V_2 * V_3 = V_11 -> V_55 ;
int V_33 ;
V_83 = & V_3 -> V_83 [ V_90 -> V_93 ] ;
if ( V_116 == V_117 ) {
V_33 = F_45 ( V_11 , V_83 ) ;
if ( V_33 < 0 )
return V_33 ;
return F_30 ( V_88 , V_90 ) ;
}
return 0 ;
}
static void F_54 ( struct V_87 * V_88 ,
struct V_89 * V_90 )
{
struct V_7 * V_11 = F_31 ( V_90 ) ;
struct V_2 * V_3 = V_11 -> V_55 ;
struct V_82 * V_83 ;
V_83 = & V_3 -> V_83 [ V_90 -> V_93 ] ;
if ( V_83 -> V_57 ) {
F_19 ( & V_11 -> V_11 , V_83 -> V_86 -> V_24 , 0 ,
V_44 , 0 ) ;
F_19 ( & V_11 -> V_11 , V_83 -> V_86 -> V_24 , 0 ,
V_45 , 0 ) ;
F_28 ( V_11 , V_83 , V_118 ) ;
F_19 ( & V_11 -> V_11 , V_83 -> V_57 -> V_24 , 0 ,
V_111 , V_119 ) ;
F_33 ( & V_83 -> V_57 -> V_94 ) ;
V_83 -> V_57 -> V_64 = false ;
memset ( V_83 -> V_57 -> V_65 , 0 , sizeof( V_83 -> V_57 -> V_65 ) ) ;
V_83 -> V_57 -> V_60 = 0 ;
F_34 ( & V_83 -> V_57 -> V_94 ) ;
V_83 -> V_57 = NULL ;
}
}
static int
F_55 ( struct V_10 * V_11 , struct V_115 * V_86 )
{
unsigned int V_120 ;
struct V_7 * V_81 = F_5 ( V_11 ) ;
struct V_2 * V_3 = V_81 -> V_55 ;
int V_121 ;
V_120 = F_47 ( V_11 , V_86 -> V_24 ) ;
V_120 = F_56 ( V_120 ) ;
V_86 -> V_122 . V_123 = 2 ;
V_86 -> V_122 . V_124 = V_120 ;
if ( V_120 > V_3 -> V_65 . V_124 )
V_3 -> V_65 . V_124 = V_120 ;
V_121 = F_57 ( V_11 , V_86 -> V_24 ,
& V_86 -> V_122 . V_125 ,
& V_86 -> V_122 . V_16 ,
& V_86 -> V_122 . V_126 ) ;
if ( V_121 < 0 )
F_17 ( & V_11 -> V_9 ,
L_13 ,
V_86 -> V_24 , V_121 ) ;
return V_121 ;
}
static int F_58 ( struct V_8 * V_9 ,
struct V_127 * V_128 ,
enum V_129 V_93 , void * V_130 ,
const char * V_131 , const char * V_132 ,
struct V_133 * V_134 , int V_135 )
{
V_128 -> V_93 = V_93 ;
V_128 -> V_136 = F_59 ( V_9 , V_131 , V_100 ) ;
if ( ! V_128 -> V_136 )
return - V_101 ;
V_128 -> V_137 = V_132 ;
V_128 -> V_138 = V_139 ;
V_128 -> V_140 = 0 ;
V_128 -> V_141 = V_134 ;
V_128 -> V_142 = V_135 ;
V_128 -> V_130 = V_130 ;
return 0 ;
}
static void F_60 ( struct V_143 * V_144 ,
const char * V_145 , const char * V_146 , const char * V_147 ,
int (* F_61)( struct V_127 * V_147 ,
struct V_127 * V_145 ) )
{
V_144 -> V_145 = V_145 ;
V_144 -> V_148 = V_147 ;
V_144 -> V_146 = V_146 ;
V_144 -> V_149 = F_61 ;
}
static struct V_1 * F_62 ( struct V_7 * V_81 ,
struct V_56 * V_57 )
{
struct V_2 * V_3 = V_81 -> V_55 ;
struct V_1 * V_5 = NULL ;
F_2 (pcm, &hdmi->pcm_list, head) {
if ( V_5 -> V_57 == V_57 )
return V_5 ;
}
return NULL ;
}
static int F_63 ( struct V_150 * V_151 ,
struct V_152 * V_153 )
{
int V_33 ;
struct V_154 * V_155 = (struct V_154 * ) V_151 -> V_156 ;
struct V_127 * V_128 = F_64 ( V_151 ) ;
struct V_157 * V_158 = V_128 -> V_158 ;
struct V_56 * V_57 = V_128 -> V_130 ;
struct V_7 * V_81 = F_3 ( V_158 -> V_9 ) ;
struct V_2 * V_3 = V_81 -> V_55 ;
struct V_1 * V_5 = NULL ;
const char * V_159 = V_155 -> V_160 [ V_153 -> V_161 . V_162 . V_163 [ 0 ] ] ;
V_33 = F_65 ( V_151 , V_153 ) ;
if ( V_33 < 0 )
return V_33 ;
F_33 ( & V_3 -> V_164 ) ;
F_2 (pcm, &hdmi->pcm_list, head) {
if ( V_5 -> V_57 == V_57 )
V_5 -> V_57 = NULL ;
if ( ! strcmp ( V_159 , V_5 -> V_86 -> V_136 ) && ! V_5 -> V_57 ) {
V_5 -> V_57 = V_57 ;
if ( V_57 -> V_15 . V_98 && V_57 -> V_15 . V_99 ) {
F_14 ( & V_81 -> V_11 . V_9 ,
L_14 ,
V_5 -> V_6 ) ;
F_66 ( V_5 -> V_165 , V_166 ) ;
}
F_34 ( & V_3 -> V_164 ) ;
return V_33 ;
}
}
F_34 ( & V_3 -> V_164 ) ;
return V_33 ;
}
static int F_67 ( struct V_7 * V_81 ,
struct V_56 * V_57 ,
struct V_127 * V_167 ,
const char * V_168 )
{
struct V_2 * V_3 = V_81 -> V_55 ;
struct V_133 * V_169 ;
struct V_115 * V_86 ;
struct V_154 * V_170 ;
char V_171 [ V_172 ] ;
char V_173 [ V_172 ] ;
char * V_174 [ V_114 ] ;
int V_18 = 0 ;
int V_175 = V_3 -> V_176 + 1 ;
V_169 = F_68 ( & V_81 -> V_11 . V_9 , sizeof( * V_169 ) , V_100 ) ;
if ( ! V_169 )
return - V_101 ;
V_170 = F_68 ( & V_81 -> V_11 . V_9 , sizeof( * V_170 ) , V_100 ) ;
if ( ! V_170 )
return - V_101 ;
sprintf ( V_171 , L_15 , V_57 -> V_24 ) ;
V_169 -> V_136 = F_59 ( & V_81 -> V_11 . V_9 , V_171 , V_100 ) ;
if ( ! V_169 -> V_136 )
return - V_101 ;
V_169 -> V_156 = ( long ) V_170 ;
V_169 -> V_177 = V_178 ;
V_169 -> V_179 = 0 ;
V_169 -> V_62 = V_180 ;
V_169 -> V_181 = F_63 ;
V_169 -> V_182 = V_183 ;
V_170 -> V_138 = V_139 ;
V_170 -> V_174 = V_175 ;
V_170 -> V_184 = F_69 ( V_170 -> V_174 ) - 1 ;
sprintf ( V_173 , L_16 ) ;
V_174 [ V_18 ] = F_59 ( & V_81 -> V_11 . V_9 , V_173 , V_100 ) ;
if ( ! V_174 [ V_18 ] )
return - V_101 ;
F_2 (cvt, &hdmi->cvt_list, head) {
V_18 ++ ;
sprintf ( V_173 , L_17 , V_86 -> V_24 ) ;
V_174 [ V_18 ] = F_59 ( & V_81 -> V_11 . V_9 , V_173 , V_100 ) ;
if ( ! V_174 [ V_18 ] )
return - V_101 ;
}
V_170 -> V_160 = F_70 ( & V_81 -> V_11 . V_9 , V_174 ,
( V_175 * sizeof( char * ) ) , V_100 ) ;
if ( ! V_170 -> V_160 )
return - V_101 ;
return F_58 ( & V_81 -> V_11 . V_9 , V_167 ,
V_185 , V_57 , V_168 , NULL , V_169 , 1 ) ;
}
static void F_71 ( struct V_7 * V_81 ,
struct V_127 * V_186 ,
struct V_143 * V_144 , int V_187 )
{
struct V_2 * V_3 = V_81 -> V_55 ;
const struct V_133 * V_169 ;
struct V_154 * V_170 ;
int V_188 = V_3 -> V_176 + V_3 -> V_189 ;
int V_18 , V_190 ;
for ( V_18 = 0 ; V_18 < V_3 -> V_189 ; V_18 ++ ) {
V_169 = V_186 [ V_188 ] . V_141 ;
V_170 = (struct V_154 * ) V_169 -> V_156 ;
for ( V_190 = 0 ; V_190 < V_3 -> V_176 ; V_190 ++ ) {
F_60 ( & V_144 [ V_187 ] ,
V_186 [ V_188 ] . V_136 ,
V_170 -> V_160 [ V_190 + 1 ] ,
V_186 [ V_190 ] . V_136 , NULL ) ;
V_187 ++ ;
}
V_188 ++ ;
}
}
static int F_72 ( struct V_157 * V_158 )
{
struct V_127 * V_186 ;
struct V_143 * V_144 ;
struct V_7 * V_81 = F_3 ( V_158 -> V_9 ) ;
struct V_2 * V_3 = V_81 -> V_55 ;
struct V_191 * V_192 = V_158 -> V_193 -> V_192 ;
char V_168 [ V_172 ] ;
struct V_115 * V_86 ;
struct V_56 * V_57 ;
int V_33 , V_18 = 0 , V_194 = 0 ;
if ( F_73 ( & V_3 -> V_195 ) || F_73 ( & V_3 -> V_196 ) )
return - V_38 ;
V_186 = F_68 ( V_158 -> V_9 ,
( sizeof( * V_186 ) * ( ( 2 * V_3 -> V_189 ) + V_3 -> V_176 ) ) ,
V_100 ) ;
if ( ! V_186 )
return - V_101 ;
F_2 (cvt, &hdmi->cvt_list, head) {
sprintf ( V_168 , L_18 , V_86 -> V_24 ) ;
V_33 = F_58 ( V_158 -> V_9 , & V_186 [ V_18 ] ,
V_197 , & V_86 -> V_24 ,
V_168 , V_192 [ V_18 ] . V_198 . V_199 , NULL , 0 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 ++ ;
}
F_2 (pin, &hdmi->pin_list, head) {
sprintf ( V_168 , L_19 , V_57 -> V_24 ) ;
V_33 = F_58 ( V_158 -> V_9 , & V_186 [ V_18 ] ,
V_200 , & V_57 -> V_24 ,
V_168 , NULL , NULL , 0 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 ++ ;
}
F_2 (pin, &hdmi->pin_list, head) {
sprintf ( V_168 , L_20 , V_57 -> V_24 ) ;
V_33 = F_67 ( V_81 , V_57 , & V_186 [ V_18 ] ,
V_168 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 ++ ;
V_194 += V_3 -> V_176 ;
V_194 ++ ;
}
V_144 = F_68 ( V_158 -> V_9 , ( sizeof( * V_144 ) * V_194 ) ,
V_100 ) ;
if ( ! V_144 )
return - V_101 ;
V_18 = 0 ;
F_2 (pin, &hdmi->pin_list, head) {
int V_201 = V_18 + V_3 -> V_176 ;
int V_202 = V_201 + V_3 -> V_189 ;
F_60 ( & V_144 [ V_18 ] ,
V_186 [ V_201 ] . V_136 , NULL ,
V_186 [ V_202 ] . V_136 , NULL ) ;
V_18 ++ ;
}
F_71 ( V_81 , V_186 , V_144 , V_18 ) ;
F_74 ( V_158 , V_186 ,
( ( 2 * V_3 -> V_189 ) + V_3 -> V_176 ) ) ;
F_75 ( V_158 , V_144 , V_194 ) ;
F_76 ( V_158 -> V_203 ) ;
return 0 ;
}
static int F_77 ( struct V_7 * V_81 )
{
struct V_2 * V_3 = V_81 -> V_55 ;
struct V_82 * V_83 ;
struct V_115 * V_86 ;
int V_204 = 0 ;
if ( F_73 ( & V_3 -> V_195 ) )
return - V_38 ;
F_2 (cvt, &hdmi->cvt_list, head) {
V_83 = & V_3 -> V_83 [ V_204 ] ;
V_83 -> V_204 = V_204 ;
V_83 -> V_86 = V_86 ;
V_204 ++ ;
if ( V_204 == V_205 ) {
F_48 ( & V_81 -> V_11 . V_9 ,
L_21 , V_204 ) ;
break;
}
}
return 0 ;
}
static int F_78 ( struct V_7 * V_81 , T_3 V_24 )
{
struct V_2 * V_3 = V_81 -> V_55 ;
struct V_115 * V_86 ;
char V_136 [ V_172 ] ;
V_86 = F_36 ( sizeof( * V_86 ) , V_100 ) ;
if ( ! V_86 )
return - V_101 ;
V_86 -> V_24 = V_24 ;
sprintf ( V_136 , L_17 , V_86 -> V_24 ) ;
V_86 -> V_136 = F_79 ( V_136 , V_100 ) ;
F_80 ( & V_86 -> V_206 , & V_3 -> V_195 ) ;
V_3 -> V_176 ++ ;
return F_55 ( & V_81 -> V_11 , V_86 ) ;
}
static void F_81 ( struct V_7 * V_81 ,
struct V_56 * V_57 )
{
V_57 -> V_15 . V_62 . V_63 = V_57 -> V_15 . V_68 [ V_207 ] ;
}
static void F_82 ( struct V_56 * V_57 , int V_208 )
{
struct V_7 * V_81 = V_57 -> V_81 ;
struct V_2 * V_3 = V_81 -> V_55 ;
struct V_1 * V_5 ;
int V_26 ;
V_57 -> V_209 = V_208 ;
F_83 ( & V_81 -> V_11 . V_9 ) ;
V_26 = F_13 ( & V_81 -> V_11 , V_57 -> V_24 , 0 ,
V_210 , 0 ) ;
F_14 ( & V_81 -> V_11 . V_9 , L_22 ,
V_26 , V_57 -> V_24 ) ;
F_33 ( & V_3 -> V_164 ) ;
V_57 -> V_15 . V_98 = ! ! ( V_26 & V_211 ) ;
V_57 -> V_15 . V_99 = ! ! ( V_26 & V_212 ) ;
V_5 = F_62 ( V_81 , V_57 ) ;
if ( ! V_57 -> V_15 . V_98 || ! V_57 -> V_15 . V_99 ) {
F_14 ( & V_81 -> V_11 . V_9 , L_23 ,
V_213 , V_57 -> V_24 ) ;
if ( V_5 ) {
F_14 ( & V_81 -> V_11 . V_9 ,
L_14 , V_5 -> V_6 ) ;
F_66 ( V_5 -> V_165 , 0 ) ;
}
F_34 ( & V_3 -> V_164 ) ;
goto V_214;
}
if ( V_57 -> V_15 . V_98 && V_57 -> V_15 . V_99 ) {
if ( F_16 ( & V_81 -> V_11 , V_57 -> V_24 ,
V_57 -> V_15 . V_68 ,
& V_57 -> V_15 . V_31 ) == 0 ) {
if ( V_5 ) {
F_14 ( & V_81 -> V_11 . V_9 ,
L_14 ,
V_5 -> V_6 ) ;
F_66 ( V_5 -> V_165 , V_166 ) ;
}
F_81 ( V_81 , V_57 ) ;
F_84 ( L_24 , V_215 ,
V_57 -> V_15 . V_68 , V_57 -> V_15 . V_31 ) ;
} else {
V_57 -> V_15 . V_98 = false ;
V_57 -> V_15 . V_99 = false ;
if ( V_5 ) {
F_14 ( & V_81 -> V_11 . V_9 ,
L_14 ,
V_5 -> V_6 ) ;
F_66 ( V_5 -> V_165 , 0 ) ;
}
}
}
F_34 ( & V_3 -> V_164 ) ;
if ( ( ! V_57 -> V_15 . V_98 || ! V_57 -> V_15 . V_99 ) && V_208 )
F_85 ( & V_57 -> V_216 , F_86 ( 300 ) ) ;
V_214:
F_87 ( & V_81 -> V_11 . V_9 ) ;
}
static void F_88 ( struct V_217 * V_216 )
{
struct V_56 * V_57 =
F_89 ( F_90 ( V_216 ) , struct V_56 , V_216 ) ;
if ( V_57 -> V_209 ++ > 6 )
V_57 -> V_209 = 0 ;
F_82 ( V_57 , V_57 -> V_209 ) ;
}
static int F_91 ( struct V_7 * V_81 , T_3 V_24 )
{
struct V_2 * V_3 = V_81 -> V_55 ;
struct V_56 * V_57 ;
V_57 = F_36 ( sizeof( * V_57 ) , V_100 ) ;
if ( ! V_57 )
return - V_101 ;
V_57 -> V_24 = V_24 ;
F_80 ( & V_57 -> V_206 , & V_3 -> V_196 ) ;
V_3 -> V_189 ++ ;
V_57 -> V_81 = V_81 ;
F_92 ( & V_57 -> V_94 ) ;
F_93 ( & V_57 -> V_216 , F_88 ) ;
return 0 ;
}
static void F_94 ( struct V_10 * V_11 )
{
unsigned int V_218 ;
V_218 = F_13 ( V_11 , V_219 , 0 ,
V_220 , 0 ) ;
if ( V_218 == - 1 || V_218 & V_221 )
return;
V_218 |= V_221 ;
V_218 = F_13 ( V_11 , V_219 , 0 ,
V_222 , V_218 ) ;
if ( V_218 == - 1 )
return;
}
static void F_95 ( struct V_10 * V_11 )
{
unsigned int V_218 ;
V_218 = F_13 ( V_11 , V_219 , 0 ,
V_220 , 0 ) ;
if ( V_218 == - 1 || V_218 & V_223 )
return;
V_218 |= V_223 ;
V_218 = F_13 ( V_11 , V_219 , 0 ,
V_222 , V_218 ) ;
if ( V_218 == - 1 )
return;
}
static int F_96 ( struct V_10 * V_11 ,
struct V_191 * * V_224 ,
struct V_2 * V_3 , int V_225 )
{
struct V_191 * V_226 ;
struct V_115 * V_86 ;
char V_136 [ V_172 ] , V_227 [ V_172 ] ;
int V_18 = 0 ;
T_4 V_125 , V_228 ;
unsigned int V_229 = 384000 , V_230 = 8000 ;
T_2 V_16 ;
int V_33 ;
V_226 = F_68 ( & V_11 -> V_9 ,
( sizeof( * V_226 ) * V_225 ) ,
V_100 ) ;
if ( ! V_226 )
return - V_101 ;
F_2 (cvt, &hdmi->cvt_list, head) {
V_33 = F_57 ( V_11 , V_86 -> V_24 ,
& V_125 , & V_16 , & V_228 ) ;
if ( V_33 )
return V_33 ;
sprintf ( V_227 , L_25 , V_18 + 1 ) ;
V_226 [ V_18 ] . V_136 = F_59 ( & V_11 -> V_9 ,
V_227 , V_100 ) ;
if ( ! V_226 [ V_18 ] . V_136 )
return - V_101 ;
snprintf ( V_136 , sizeof( V_136 ) , L_26 , V_18 + 1 ) ;
V_226 [ V_18 ] . V_198 . V_199 =
F_59 ( & V_11 -> V_9 , V_136 , V_100 ) ;
if ( ! V_226 [ V_18 ] . V_198 . V_199 )
return - V_101 ;
V_226 [ V_18 ] . V_198 . V_16 = V_16 ;
V_226 [ V_18 ] . V_198 . V_125 = V_125 ;
V_226 [ V_18 ] . V_198 . V_229 = V_229 ;
V_226 [ V_18 ] . V_198 . V_230 = V_230 ;
V_226 [ V_18 ] . V_198 . V_123 = 2 ;
V_226 [ V_18 ] . V_198 . V_124 = 2 ;
V_226 [ V_18 ] . V_66 = & V_231 ;
V_18 ++ ;
}
* V_224 = V_226 ;
return 0 ;
}
static int F_97 ( struct V_7 * V_81 ,
struct V_191 * * V_224 , int * V_225 )
{
T_3 V_24 ;
int V_18 , V_232 ;
struct V_10 * V_11 = & V_81 -> V_11 ;
struct V_2 * V_3 = V_81 -> V_55 ;
int V_33 ;
F_94 ( V_11 ) ;
F_95 ( V_11 ) ;
V_232 = F_98 ( V_11 , V_11 -> V_233 , & V_24 ) ;
if ( ! V_24 || V_232 <= 0 ) {
F_48 ( & V_11 -> V_9 , L_27 ) ;
return - V_38 ;
}
V_11 -> V_232 = V_232 ;
V_11 -> V_234 = V_24 ;
for ( V_18 = 0 ; V_18 < V_11 -> V_232 ; V_18 ++ , V_24 ++ ) {
unsigned int V_235 ;
unsigned int type ;
V_235 = F_47 ( V_11 , V_24 ) ;
type = F_99 ( V_235 ) ;
if ( ! ( V_235 & V_236 ) )
continue;
switch ( type ) {
case V_237 :
V_33 = F_78 ( V_81 , V_24 ) ;
if ( V_33 < 0 )
return V_33 ;
break;
case V_238 :
V_33 = F_91 ( V_81 , V_24 ) ;
if ( V_33 < 0 )
return V_33 ;
break;
}
}
V_11 -> V_239 = V_24 ;
if ( ! V_3 -> V_189 || ! V_3 -> V_176 )
return - V_76 ;
V_33 = F_96 ( V_11 , V_224 , V_3 , V_3 -> V_176 ) ;
if ( V_33 ) {
F_17 ( & V_11 -> V_9 , L_28 ,
V_33 ) ;
return V_33 ;
}
* V_225 = V_3 -> V_176 ;
return F_77 ( V_81 ) ;
}
static void F_100 ( void * V_240 , int V_241 )
{
struct V_7 * V_81 = V_240 ;
struct V_2 * V_3 = V_81 -> V_55 ;
struct V_56 * V_57 ;
struct V_242 * V_23 = V_81 -> V_243 ;
T_3 V_41 = V_241 + 0x04 ;
F_14 ( & V_81 -> V_11 . V_9 , L_29 , V_213 , V_41 ) ;
if ( F_101 ( V_23 -> V_193 . V_203 -> V_244 ) !=
V_245 )
return;
if ( F_102 ( & V_81 -> V_11 . V_246 ) )
return;
F_2 (pin, &hdmi->pin_list, head) {
if ( V_57 -> V_24 == V_41 )
F_82 ( V_57 , 1 ) ;
}
}
static struct V_247 * F_103 ( struct V_248 * V_203 ,
int V_8 )
{
struct V_249 * V_250 ;
F_2 (rtd, &card->rtd_list, list) {
if ( V_250 -> V_5 && ( V_250 -> V_5 -> V_8 == V_8 ) )
return V_250 -> V_5 ;
}
return NULL ;
}
int F_104 ( struct V_89 * V_90 , int V_8 )
{
char V_251 [ V_172 ] ;
struct V_242 * V_23 = V_90 -> V_23 ;
struct V_7 * V_81 = F_105 ( V_23 ) ;
struct V_157 * V_158 =
F_106 ( & V_23 -> V_193 ) ;
struct V_2 * V_3 = V_81 -> V_55 ;
struct V_1 * V_5 ;
struct V_247 * V_247 ;
int V_121 ;
V_5 = F_36 ( sizeof( * V_5 ) , V_100 ) ;
if ( ! V_5 )
return - V_101 ;
V_5 -> V_6 = V_8 ;
V_5 -> V_86 = V_3 -> V_83 [ V_90 -> V_93 ] . V_86 ;
V_247 = F_103 ( V_90 -> V_193 -> V_203 , V_8 ) ;
if ( V_247 ) {
V_121 = F_107 ( V_247 , V_8 , & V_3 -> V_65 ) ;
if ( V_121 < 0 ) {
F_17 ( & V_81 -> V_11 . V_9 ,
L_30 ,
V_121 , V_8 ) ;
F_43 ( V_5 ) ;
return V_121 ;
}
}
F_80 ( & V_5 -> V_206 , & V_3 -> V_252 ) ;
sprintf ( V_251 , L_31 , V_8 ) ;
return F_108 ( V_158 -> V_203 -> V_244 , V_251 ,
V_166 , & V_5 -> V_165 , true , false ) ;
}
static int F_109 ( struct V_242 * V_23 )
{
struct V_7 * V_81 = F_105 ( V_23 ) ;
struct V_2 * V_3 = V_81 -> V_55 ;
struct V_157 * V_158 =
F_106 ( & V_23 -> V_193 ) ;
struct V_56 * V_57 ;
struct V_253 * V_254 = NULL ;
int V_33 ;
V_81 -> V_243 = V_23 ;
V_254 = F_110 ( V_81 -> V_255 , F_111 ( & V_81 -> V_11 . V_9 ) ) ;
if ( ! V_254 ) {
F_17 ( & V_81 -> V_11 . V_9 , L_32 ) ;
return - V_76 ;
}
F_112 ( V_81 -> V_255 , V_254 ) ;
V_33 = F_72 ( V_158 ) ;
if ( V_33 < 0 )
return V_33 ;
V_256 . V_257 = V_81 ;
V_33 = F_113 ( & V_256 ) ;
if ( V_33 < 0 ) {
F_17 ( & V_81 -> V_11 . V_9 , L_33 ,
V_33 ) ;
return V_33 ;
}
F_2 (pin, &hdmi->pin_list, head)
F_82 ( V_57 , 1 ) ;
V_81 -> V_203 = V_158 -> V_203 -> V_244 ;
F_114 ( & V_81 -> V_11 . V_9 ) ;
F_115 ( & V_81 -> V_11 . V_9 ) ;
F_116 ( & V_81 -> V_11 . V_9 ) ;
return 0 ;
}
static int F_117 ( struct V_242 * V_23 )
{
struct V_7 * V_81 = F_105 ( V_23 ) ;
F_118 ( & V_81 -> V_11 . V_9 ) ;
return 0 ;
}
static int F_119 ( struct V_8 * V_9 )
{
struct V_7 * V_81 = F_3 ( V_9 ) ;
struct V_10 * V_11 = & V_81 -> V_11 ;
F_83 ( & V_81 -> V_11 . V_9 ) ;
F_13 ( V_11 , V_11 -> V_233 , 0 , V_85 ,
V_118 ) ;
return 0 ;
}
static void F_120 ( struct V_8 * V_9 )
{
struct V_7 * V_81 = F_3 ( V_9 ) ;
struct V_2 * V_3 = V_81 -> V_55 ;
struct V_56 * V_57 ;
struct V_10 * V_11 = & V_81 -> V_11 ;
F_13 ( V_11 , V_11 -> V_233 , 0 , V_85 ,
V_110 ) ;
F_94 ( & V_81 -> V_11 ) ;
F_95 ( & V_81 -> V_11 ) ;
F_2 (pin, &hdmi->pin_list, head)
F_82 ( V_57 , 1 ) ;
F_87 ( & V_81 -> V_11 . V_9 ) ;
}
static void F_121 ( struct V_10 * V_11 , int V_4 ,
unsigned char * V_65 )
{
struct V_7 * V_81 = F_5 ( V_11 ) ;
struct V_2 * V_3 = V_81 -> V_55 ;
struct V_1 * V_5 = F_1 ( V_3 , V_4 ) ;
struct V_56 * V_57 = V_5 -> V_57 ;
if ( ! V_57 )
return;
memcpy ( V_65 , V_57 -> V_65 , F_122 ( V_57 -> V_65 ) ) ;
}
static void F_123 ( struct V_10 * V_11 , int V_4 ,
unsigned char * V_65 , int V_258 )
{
struct V_7 * V_81 = F_5 ( V_11 ) ;
struct V_2 * V_3 = V_81 -> V_55 ;
struct V_1 * V_5 = F_1 ( V_3 , V_4 ) ;
struct V_56 * V_57 = V_5 -> V_57 ;
F_33 ( & V_57 -> V_94 ) ;
V_57 -> V_64 = true ;
memcpy ( V_57 -> V_65 , V_65 , F_122 ( V_57 -> V_65 ) ) ;
if ( V_258 )
F_21 ( V_81 , V_5 -> V_86 -> V_24 , V_57 -> V_24 ) ;
F_34 ( & V_57 -> V_94 ) ;
}
static bool F_124 ( struct V_10 * V_11 , int V_4 )
{
struct V_7 * V_81 = F_5 ( V_11 ) ;
struct V_2 * V_3 = V_81 -> V_55 ;
struct V_1 * V_5 = F_1 ( V_3 , V_4 ) ;
struct V_56 * V_57 = V_5 -> V_57 ;
return V_57 ? true : false ;
}
static int F_125 ( struct V_10 * V_11 , int V_4 )
{
struct V_7 * V_81 = F_5 ( V_11 ) ;
struct V_2 * V_3 = V_81 -> V_55 ;
struct V_1 * V_5 = F_1 ( V_3 , V_4 ) ;
struct V_56 * V_57 = V_5 -> V_57 ;
if ( ! V_57 || ! V_57 -> V_15 . V_99 )
return 0 ;
return V_57 -> V_15 . V_62 . V_63 ;
}
static int F_126 ( struct V_7 * V_81 )
{
struct V_10 * V_23 = & V_81 -> V_11 ;
struct V_2 * V_259 ;
struct V_191 * V_226 = NULL ;
struct V_253 * V_254 = NULL ;
int V_225 = 0 ;
int V_33 = 0 ;
V_254 = F_110 ( V_81 -> V_255 , F_111 ( & V_81 -> V_11 . V_9 ) ) ;
if ( ! V_254 ) {
F_17 ( & V_81 -> V_11 . V_9 , L_32 ) ;
return - V_76 ;
}
F_112 ( V_81 -> V_255 , V_254 ) ;
V_259 = F_68 ( & V_23 -> V_9 , sizeof( * V_259 ) , V_100 ) ;
if ( V_259 == NULL )
return - V_101 ;
V_81 -> V_55 = V_259 ;
F_127 ( V_23 , & V_259 -> V_65 ) ;
V_259 -> V_65 . V_66 . V_260 = F_121 ;
V_259 -> V_65 . V_66 . V_261 = F_123 ;
V_259 -> V_65 . V_66 . V_262 = F_124 ;
V_259 -> V_65 . V_66 . V_263 = F_125 ;
F_128 ( & V_23 -> V_9 , V_81 ) ;
F_129 ( & V_259 -> V_196 ) ;
F_129 ( & V_259 -> V_195 ) ;
F_129 ( & V_259 -> V_252 ) ;
F_92 ( & V_259 -> V_164 ) ;
V_33 = F_130 ( V_81 -> V_11 . V_264 , true ) ;
if ( V_33 < 0 ) {
F_17 ( & V_81 -> V_11 . V_9 ,
L_34 ,
V_33 ) ;
return V_33 ;
}
V_33 = F_97 ( V_81 , & V_226 , & V_225 ) ;
if ( V_33 < 0 ) {
F_17 ( & V_23 -> V_9 ,
L_35 , V_33 ) ;
return V_33 ;
}
V_33 = F_131 ( & V_23 -> V_9 , & V_265 ,
V_226 , V_225 ) ;
F_132 ( V_81 -> V_255 , V_254 ) ;
return V_33 ;
}
static int F_133 ( struct V_7 * V_81 )
{
struct V_2 * V_3 = V_81 -> V_55 ;
struct V_56 * V_57 , * V_266 ;
struct V_115 * V_86 , * V_267 ;
struct V_1 * V_5 , * V_268 ;
F_134 ( & V_81 -> V_11 . V_9 ) ;
F_135 (pcm, pcm_next, &hdmi->pcm_list, head) {
V_5 -> V_86 = NULL ;
V_5 -> V_57 = NULL ;
F_136 ( & V_5 -> V_206 ) ;
F_43 ( V_5 ) ;
}
F_135 (cvt, cvt_next, &hdmi->cvt_list, head) {
F_136 ( & V_86 -> V_206 ) ;
F_43 ( V_86 -> V_136 ) ;
F_43 ( V_86 ) ;
}
F_135 (pin, pin_next, &hdmi->pin_list, head) {
F_136 ( & V_57 -> V_206 ) ;
F_43 ( V_57 ) ;
}
return 0 ;
}
static int F_137 ( struct V_8 * V_9 )
{
struct V_7 * V_81 = F_3 ( V_9 ) ;
struct V_10 * V_11 = & V_81 -> V_11 ;
struct V_269 * V_264 = V_11 -> V_264 ;
struct V_270 * V_255 = F_138 ( V_264 ) ;
struct V_253 * V_254 = NULL ;
int V_121 ;
F_14 ( V_9 , L_36 , V_213 ) ;
if ( ! V_264 )
return 0 ;
F_13 ( V_11 , V_11 -> V_233 , 0 , V_85 ,
V_118 ) ;
V_121 = F_130 ( V_264 , false ) ;
if ( V_121 < 0 ) {
F_17 ( V_264 -> V_9 , L_37 ) ;
return V_121 ;
}
V_254 = F_110 ( V_255 , F_111 ( V_9 ) ) ;
if ( ! V_254 ) {
F_17 ( V_9 , L_32 ) ;
return - V_76 ;
}
F_132 ( V_255 , V_254 ) ;
return 0 ;
}
static int F_139 ( struct V_8 * V_9 )
{
struct V_7 * V_81 = F_3 ( V_9 ) ;
struct V_10 * V_11 = & V_81 -> V_11 ;
struct V_269 * V_264 = V_11 -> V_264 ;
struct V_270 * V_255 = F_138 ( V_264 ) ;
struct V_253 * V_254 = NULL ;
int V_121 ;
F_14 ( V_9 , L_36 , V_213 ) ;
if ( ! V_264 )
return 0 ;
V_254 = F_110 ( V_255 , F_111 ( V_9 ) ) ;
if ( ! V_254 ) {
F_17 ( V_9 , L_32 ) ;
return - V_76 ;
}
F_112 ( V_255 , V_254 ) ;
V_121 = F_130 ( V_264 , true ) ;
if ( V_121 < 0 ) {
F_17 ( V_264 -> V_9 , L_37 ) ;
return V_121 ;
}
F_94 ( & V_81 -> V_11 ) ;
F_95 ( & V_81 -> V_11 ) ;
F_13 ( V_11 , V_11 -> V_233 , 0 , V_85 ,
V_110 ) ;
return 0 ;
}
static int T_6 F_140 ( void )
{
return F_141 ( & V_271 ) ;
}
static void T_7 F_142 ( void )
{
F_143 ( & V_271 ) ;
}

static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return F_3 ( V_5 ) ;
}
static unsigned int F_4 ( const T_1 * V_6 )
{
return ( ( V_6 [ 0 ] >> 0x3 ) & 0x1f ) ;
}
static unsigned int F_5 ( const T_1 * V_6 )
{
return ( V_6 [ 2 ] & 7 ) ;
}
static int F_6 ( struct V_7 * V_8 ,
void * V_9 )
{
T_2 V_10 = V_11 ;
int V_12 ;
const T_1 * V_6 , * V_13 = V_9 ;
V_6 = F_7 ( V_13 ) ;
if ( ! V_6 )
goto V_14;
for ( V_12 = F_8 ( V_13 ) ; V_12 > 0 ; V_12 -- , V_6 += 3 ) {
if ( F_4 ( V_6 ) == 1 ) {
if ( F_5 ( V_6 ) & 0x6 )
V_10 |= V_15 ;
}
}
V_14:
return F_9 ( V_8 , V_16 ,
V_10 ) ;
}
static unsigned int F_10 ( struct V_4 * V_17 ,
T_3 V_18 , int V_19 )
{
unsigned int V_20 ;
V_20 = F_11 ( V_17 , V_18 , 0 , V_21 ,
V_19 ) ;
F_12 ( & V_17 -> V_3 , L_1 ,
V_19 , V_20 ) ;
return V_20 ;
}
static int F_13 ( struct V_4 * V_17 , T_3 V_18 )
{
return F_11 ( V_17 , V_18 , 0 , V_22 ,
V_23 ) ;
}
static int F_14 ( struct V_4 * V_17 , T_3 V_18 ,
unsigned char * V_24 , int * V_25 )
{
int V_12 , V_26 , V_27 = 0 ;
V_26 = F_13 ( V_17 , V_18 ) ;
if ( V_26 < V_28 || V_26 > V_29 ) {
F_15 ( & V_17 -> V_3 , L_2 , V_26 ) ;
return - V_30 ;
}
for ( V_12 = 0 ; V_12 < V_26 ; V_12 ++ ) {
unsigned int V_20 = F_10 ( V_17 , V_18 , V_12 ) ;
if ( ! ( V_20 & V_31 ) ) {
F_15 ( & V_17 -> V_3 ,
L_3 , V_12 ) ;
V_27 = - V_32 ;
goto error;
}
V_20 &= V_33 ;
if ( ! V_20 && ! V_12 ) {
F_15 ( & V_17 -> V_3 , L_4 ) ;
V_27 = - V_32 ;
goto error;
}
V_24 [ V_12 ] = V_20 ;
}
* V_25 = V_26 ;
error:
return V_27 ;
}
static int F_16 ( struct V_1 * V_5 ,
T_3 V_34 , T_3 V_35 ,
T_4 V_36 , int V_37 )
{
unsigned int V_20 ;
F_12 ( & V_5 -> V_5 . V_3 , L_5 ,
V_34 , V_35 , V_36 , V_37 ) ;
V_20 = ( V_36 << 4 ) ;
F_17 ( & V_5 -> V_5 , V_34 , 0 ,
V_38 , V_20 ) ;
F_17 ( & V_5 -> V_5 , V_34 , 0 ,
V_39 , V_37 ) ;
return 0 ;
}
static void
F_18 ( struct V_1 * V_5 , T_3 V_35 ,
int V_40 , int V_19 )
{
int V_20 ;
V_20 = ( V_40 << 5 ) | ( V_19 & 0x1f ) ;
F_17 ( & V_5 -> V_5 , V_35 , 0 ,
V_41 , V_20 ) ;
}
static int F_19 ( struct V_1 * V_5 ,
T_3 V_34 , T_3 V_35 )
{
T_5 V_42 [ V_43 + V_44 ] ;
struct V_45 V_46 ;
struct V_47 V_48 ;
struct V_49 * V_50 = V_5 -> V_51 ;
struct V_52 * V_53 ;
T_1 * V_54 ;
int V_27 ;
int V_12 ;
const T_1 * V_13 ;
T_1 V_55 ;
int V_56 = 2 ;
F_20 (pin, &hdmi->pin_list, head) {
if ( V_53 -> V_18 == V_35 )
break;
}
V_13 = V_53 -> V_9 . V_57 ;
V_55 = F_21 ( V_13 ) ;
F_17 ( & V_5 -> V_5 , V_34 , 0 ,
V_58 , V_56 - 1 ) ;
switch ( V_55 ) {
case V_59 :
F_22 ( & V_46 ) ;
V_46 . V_56 = V_56 ;
V_27 = F_23 ( & V_46 , V_42 , sizeof( V_42 ) ) ;
if ( V_27 < 0 )
return V_27 ;
break;
case V_60 :
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
V_48 . type = 0x84 ;
V_48 . V_61 = 0x1b ;
V_48 . V_62 = 0x11 << 2 ;
V_48 . V_63 = V_56 - 1 ;
V_48 . V_64 = 0 ;
V_54 = ( T_1 * ) & V_48 ;
break;
default:
F_15 ( & V_5 -> V_5 . V_3 , L_6 ,
V_55 ) ;
return - V_65 ;
}
F_18 ( V_5 , V_35 , 0x0 , 0x0 ) ;
F_17 ( & V_5 -> V_5 , V_35 , 0 ,
V_66 , V_67 ) ;
F_18 ( V_5 , V_35 , 0x0 , 0x0 ) ;
if ( V_55 == V_59 ) {
for ( V_12 = 0 ; V_12 < sizeof( V_42 ) ; V_12 ++ )
F_17 ( & V_5 -> V_5 , V_35 , 0 ,
V_68 , V_42 [ V_12 ] ) ;
} else {
for ( V_12 = 0 ; V_12 < sizeof( V_48 ) ; V_12 ++ )
F_17 ( & V_5 -> V_5 , V_35 , 0 ,
V_68 , V_54 [ V_12 ] ) ;
}
F_18 ( V_5 , V_35 , 0x0 , 0x0 ) ;
F_17 ( & V_5 -> V_5 , V_35 , 0 ,
V_66 , V_69 ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_70 ,
struct V_71 * V_72 , unsigned int V_73 )
{
if ( ! F_25 ( & V_70 -> V_5 , V_72 -> V_53 -> V_18 ,
V_73 ) )
F_17 ( & V_70 -> V_5 , V_72 -> V_53 -> V_18 , 0 ,
V_74 , V_73 ) ;
if ( ! F_25 ( & V_70 -> V_5 , V_72 -> V_75 -> V_18 ,
V_73 ) )
F_17 ( & V_70 -> V_5 , V_72 -> V_75 -> V_18 , 0 ,
V_74 , V_73 ) ;
}
static int F_26 ( struct V_76 * V_77 ,
struct V_78 * V_79 )
{
struct V_1 * V_5 = F_27 ( V_79 ) ;
struct V_49 * V_50 = V_5 -> V_51 ;
struct V_71 * V_72 ;
struct V_80 * V_81 ;
int V_27 ;
V_72 = & V_50 -> V_72 [ V_79 -> V_82 ] ;
V_81 = (struct V_80 * ) F_28 ( V_79 , V_77 ) ;
F_12 ( & V_5 -> V_5 . V_3 , L_7 ,
V_81 -> V_36 , V_81 -> V_37 ) ;
V_27 = F_19 ( V_5 , V_72 -> V_75 -> V_18 ,
V_72 -> V_53 -> V_18 ) ;
if ( V_27 < 0 )
return V_27 ;
return F_16 ( V_5 , V_72 -> V_75 -> V_18 ,
V_72 -> V_53 -> V_18 , V_81 -> V_36 , V_81 -> V_37 ) ;
}
static int F_29 ( struct V_76 * V_77 ,
struct V_83 * V_84 , struct V_78 * V_79 )
{
struct V_1 * V_5 = F_27 ( V_79 ) ;
struct V_49 * V_50 = V_5 -> V_51 ;
struct V_71 * V_72 ;
struct V_52 * V_53 ;
struct V_80 * V_81 ;
V_72 = & V_50 -> V_72 [ V_79 -> V_82 ] ;
V_53 = V_72 -> V_53 ;
if ( ! V_53 )
return - V_85 ;
if ( ( ! V_53 -> V_9 . V_86 ) || ( ! V_53 -> V_9 . V_87 ) ) {
F_15 ( & V_5 -> V_5 . V_3 , L_8 ,
V_53 -> V_18 ) ;
return - V_85 ;
}
V_81 = F_28 ( V_79 , V_77 ) ;
if ( ! V_81 ) {
V_81 = F_30 ( sizeof( * V_81 ) , V_88 ) ;
if ( ! V_81 )
return - V_89 ;
}
V_81 -> V_37 = F_31 ( F_32 ( V_84 ) ,
F_33 ( V_84 ) , F_34 ( V_84 ) ,
24 , 0 ) ;
F_35 ( V_79 , V_77 , ( void * ) V_81 ) ;
return 0 ;
}
static int F_36 ( struct V_76 * V_77 ,
struct V_78 * V_79 )
{
struct V_1 * V_70 = F_27 ( V_79 ) ;
struct V_80 * V_81 ;
struct V_49 * V_50 = V_70 -> V_51 ;
struct V_71 * V_72 ;
V_72 = & V_50 -> V_72 [ V_79 -> V_82 ] ;
V_81 = (struct V_80 * ) F_28 ( V_79 , V_77 ) ;
if ( V_81 ) {
F_35 ( V_79 , V_77 , NULL ) ;
F_37 ( V_81 ) ;
}
return 0 ;
}
static void F_38 ( struct V_1 * V_70 ,
struct V_71 * V_72 )
{
F_17 ( & V_70 -> V_5 , V_72 -> V_75 -> V_18 , 0 ,
V_90 , 1 ) ;
F_17 ( & V_70 -> V_5 , V_72 -> V_75 -> V_18 , 0 ,
V_91 , 0 ) ;
}
static int F_39 ( struct V_1 * V_5 ,
struct V_71 * V_72 )
{
int V_92 ;
struct V_52 * V_53 = V_72 -> V_53 ;
for ( V_92 = 0 ; V_92 < V_53 -> V_93 ; V_92 ++ ) {
if ( V_53 -> V_94 [ V_92 ] == V_72 -> V_75 -> V_18 ) {
F_17 ( & V_5 -> V_5 , V_53 -> V_18 , 0 ,
V_95 , V_92 ) ;
break;
}
}
if ( V_92 == V_53 -> V_93 )
return - V_65 ;
F_17 ( & V_5 -> V_5 , V_53 -> V_18 , 0 ,
V_96 , V_97 ) ;
F_24 ( V_5 , V_72 , V_98 ) ;
F_17 ( & V_5 -> V_5 , V_53 -> V_18 , 0 ,
V_99 , V_100 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_5 ,
struct V_52 * V_53 )
{
if ( ! ( F_41 ( & V_5 -> V_5 , V_53 -> V_18 ) & V_101 ) ) {
F_42 ( & V_5 -> V_5 . V_3 ,
L_9 ,
V_53 -> V_18 , F_41 ( & V_5 -> V_5 , V_53 -> V_18 ) ) ;
return - V_32 ;
}
V_53 -> V_93 = F_43 ( & V_5 -> V_5 , V_53 -> V_18 ,
V_53 -> V_94 , V_102 ) ;
if ( V_53 -> V_93 == 0 )
F_42 ( & V_5 -> V_5 . V_3 , L_10 ,
V_53 -> V_18 ) ;
F_12 ( & V_5 -> V_5 . V_3 , L_11 ,
V_53 -> V_93 , V_53 -> V_18 ) ;
return V_53 -> V_93 ;
}
static struct V_52 * F_44 (
struct V_1 * V_70 ,
struct V_49 * V_50 ,
struct V_103 * V_75 )
{
struct V_104 * V_105 ;
struct V_52 * V_53 = NULL ;
int V_27 , V_12 ;
F_20 (pcm, &hdmi->pcm_list, head) {
if ( V_105 -> V_75 == V_75 ) {
V_53 = V_105 -> V_53 ;
break;
}
}
if ( V_53 ) {
V_27 = F_40 ( V_70 , V_53 ) ;
if ( V_27 < 0 )
return NULL ;
for ( V_12 = 0 ; V_12 < V_53 -> V_93 ; V_12 ++ ) {
if ( V_53 -> V_94 [ V_12 ] == V_75 -> V_18 )
return V_53 ;
}
}
return NULL ;
}
static int F_45 ( struct V_76 * V_77 ,
struct V_78 * V_79 )
{
struct V_1 * V_5 = F_27 ( V_79 ) ;
struct V_49 * V_50 = V_5 -> V_51 ;
struct V_71 * V_72 ;
struct V_103 * V_75 ;
struct V_52 * V_53 ;
int V_27 ;
V_72 = & V_50 -> V_72 [ V_79 -> V_82 ] ;
V_75 = V_72 -> V_75 ;
V_53 = F_44 ( V_5 , V_50 , V_75 ) ;
if ( ! V_53 )
return 0 ;
if ( ( ! V_53 -> V_9 . V_86 ) ||
( ! V_53 -> V_9 . V_87 ) ) {
F_42 ( & V_5 -> V_5 . V_3 ,
L_12 ,
V_53 -> V_9 . V_86 , V_53 -> V_9 . V_87 , V_53 -> V_18 ) ;
return 0 ;
}
V_72 -> V_53 = V_53 ;
F_38 ( V_5 , V_72 ) ;
V_27 = F_39 ( V_5 , V_72 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = F_6 ( V_77 -> V_8 ,
V_53 -> V_9 . V_57 ) ;
if ( V_27 < 0 )
return V_27 ;
return F_46 ( V_77 -> V_8 ,
V_53 -> V_9 . V_57 ) ;
}
static int F_47 ( struct V_76 * V_77 , int V_106 ,
struct V_78 * V_79 )
{
struct V_71 * V_72 ;
struct V_1 * V_5 = F_27 ( V_79 ) ;
struct V_49 * V_50 = V_5 -> V_51 ;
int V_27 ;
V_72 = & V_50 -> V_72 [ V_79 -> V_82 ] ;
if ( V_106 == V_107 ) {
V_27 = F_39 ( V_5 , V_72 ) ;
if ( V_27 < 0 )
return V_27 ;
return F_26 ( V_77 , V_79 ) ;
}
return 0 ;
}
static void F_48 ( struct V_76 * V_77 ,
struct V_78 * V_79 )
{
struct V_1 * V_5 = F_27 ( V_79 ) ;
struct V_49 * V_50 = V_5 -> V_51 ;
struct V_71 * V_72 ;
V_72 = & V_50 -> V_72 [ V_79 -> V_82 ] ;
if ( V_72 -> V_53 ) {
F_17 ( & V_5 -> V_5 , V_72 -> V_75 -> V_18 , 0 ,
V_38 , 0 ) ;
F_17 ( & V_5 -> V_5 , V_72 -> V_75 -> V_18 , 0 ,
V_39 , 0 ) ;
F_24 ( V_5 , V_72 , V_108 ) ;
F_17 ( & V_5 -> V_5 , V_72 -> V_53 -> V_18 , 0 ,
V_99 , V_109 ) ;
V_72 -> V_53 = NULL ;
}
}
static int
F_49 ( struct V_4 * V_5 , struct V_103 * V_75 )
{
int V_110 ;
V_75 -> V_111 . V_112 = V_75 -> V_111 . V_113 = 2 ;
V_110 = F_50 ( V_5 , V_75 -> V_18 ,
& V_75 -> V_111 . V_114 ,
& V_75 -> V_111 . V_10 ,
& V_75 -> V_111 . V_115 ) ;
if ( V_110 < 0 )
F_15 ( & V_5 -> V_3 ,
L_13 ,
V_75 -> V_18 , V_110 ) ;
return V_110 ;
}
static int F_51 ( struct V_2 * V_3 ,
struct V_116 * V_117 ,
enum V_118 V_82 , void * V_119 ,
const char * V_120 , const char * V_121 ,
struct V_122 * V_123 , int V_124 )
{
V_117 -> V_82 = V_82 ;
V_117 -> V_125 = F_52 ( V_3 , V_120 , V_88 ) ;
if ( ! V_117 -> V_125 )
return - V_89 ;
V_117 -> V_126 = V_121 ;
V_117 -> V_127 = V_128 ;
V_117 -> V_129 = 0 ;
V_117 -> V_130 = V_123 ;
V_117 -> V_131 = V_124 ;
V_117 -> V_119 = V_119 ;
return 0 ;
}
static void F_53 ( struct V_132 * V_133 ,
const char * V_134 , const char * V_135 , const char * V_136 ,
int (* F_54)( struct V_116 * V_136 ,
struct V_116 * V_134 ) )
{
V_133 -> V_134 = V_134 ;
V_133 -> V_137 = V_136 ;
V_133 -> V_135 = V_135 ;
V_133 -> V_138 = F_54 ;
}
static struct V_104 * F_55 ( struct V_1 * V_70 ,
struct V_52 * V_53 )
{
struct V_49 * V_50 = V_70 -> V_51 ;
struct V_104 * V_105 = NULL ;
F_20 (pcm, &hdmi->pcm_list, head) {
if ( V_105 -> V_53 == V_53 )
return V_105 ;
}
return NULL ;
}
static int F_56 ( struct V_139 * V_140 ,
struct V_141 * V_142 )
{
int V_27 ;
struct V_143 * V_144 = (struct V_143 * ) V_140 -> V_145 ;
struct V_116 * V_117 = F_57 ( V_140 ) ;
struct V_146 * V_147 = V_117 -> V_147 ;
struct V_52 * V_53 = V_117 -> V_119 ;
struct V_1 * V_70 = F_1 ( V_147 -> V_3 ) ;
struct V_49 * V_50 = V_70 -> V_51 ;
struct V_104 * V_105 = NULL ;
const char * V_148 = V_144 -> V_149 [ V_142 -> V_150 . V_151 . V_152 [ 0 ] ] ;
V_27 = F_58 ( V_140 , V_142 ) ;
if ( V_27 < 0 )
return V_27 ;
F_59 ( & V_50 -> V_153 ) ;
F_20 (pcm, &hdmi->pcm_list, head) {
if ( V_105 -> V_53 == V_53 )
V_105 -> V_53 = NULL ;
if ( ! strcmp ( V_148 , V_105 -> V_75 -> V_125 ) && ! V_105 -> V_53 ) {
V_105 -> V_53 = V_53 ;
if ( V_53 -> V_9 . V_86 && V_53 -> V_9 . V_87 ) {
F_12 ( & V_70 -> V_5 . V_3 ,
L_14 ,
V_105 -> V_154 ) ;
F_60 ( V_105 -> V_155 , V_156 ) ;
}
F_61 ( & V_50 -> V_153 ) ;
return V_27 ;
}
}
F_61 ( & V_50 -> V_153 ) ;
return V_27 ;
}
static int F_62 ( struct V_1 * V_70 ,
struct V_52 * V_53 ,
struct V_116 * V_157 ,
const char * V_158 )
{
struct V_49 * V_50 = V_70 -> V_51 ;
struct V_122 * V_159 ;
struct V_103 * V_75 ;
struct V_143 * V_160 ;
char V_161 [ V_162 ] ;
char V_163 [ V_162 ] ;
char * V_164 [ V_102 ] ;
int V_12 = 0 ;
int V_165 = V_50 -> V_166 + 1 ;
V_159 = F_63 ( & V_70 -> V_5 . V_3 , sizeof( * V_159 ) , V_88 ) ;
if ( ! V_159 )
return - V_89 ;
V_160 = F_63 ( & V_70 -> V_5 . V_3 , sizeof( * V_160 ) , V_88 ) ;
if ( ! V_160 )
return - V_89 ;
sprintf ( V_161 , L_15 , V_53 -> V_18 ) ;
V_159 -> V_125 = F_52 ( & V_70 -> V_5 . V_3 , V_161 , V_88 ) ;
if ( ! V_159 -> V_125 )
return - V_89 ;
V_159 -> V_145 = ( long ) V_160 ;
V_159 -> V_167 = V_168 ;
V_159 -> V_169 = 0 ;
V_159 -> V_170 = V_171 ;
V_159 -> V_172 = F_56 ;
V_159 -> V_173 = V_174 ;
V_160 -> V_127 = V_128 ;
V_160 -> V_164 = V_165 ;
V_160 -> V_175 = F_64 ( V_160 -> V_164 ) - 1 ;
sprintf ( V_163 , L_16 ) ;
V_164 [ V_12 ] = F_52 ( & V_70 -> V_5 . V_3 , V_163 , V_88 ) ;
if ( ! V_164 [ V_12 ] )
return - V_89 ;
F_20 (cvt, &hdmi->cvt_list, head) {
V_12 ++ ;
sprintf ( V_163 , L_17 , V_75 -> V_18 ) ;
V_164 [ V_12 ] = F_52 ( & V_70 -> V_5 . V_3 , V_163 , V_88 ) ;
if ( ! V_164 [ V_12 ] )
return - V_89 ;
}
V_160 -> V_149 = F_65 ( & V_70 -> V_5 . V_3 , V_164 ,
( V_165 * sizeof( char * ) ) , V_88 ) ;
if ( ! V_160 -> V_149 )
return - V_89 ;
return F_51 ( & V_70 -> V_5 . V_3 , V_157 ,
V_176 , V_53 , V_158 , NULL , V_159 , 1 ) ;
}
static void F_66 ( struct V_1 * V_70 ,
struct V_116 * V_177 ,
struct V_132 * V_133 , int V_178 )
{
struct V_49 * V_50 = V_70 -> V_51 ;
const struct V_122 * V_159 ;
struct V_143 * V_160 ;
int V_179 = V_50 -> V_166 + V_50 -> V_180 ;
int V_12 , V_181 ;
for ( V_12 = 0 ; V_12 < V_50 -> V_180 ; V_12 ++ ) {
V_159 = V_177 [ V_179 ] . V_130 ;
V_160 = (struct V_143 * ) V_159 -> V_145 ;
for ( V_181 = 0 ; V_181 < V_50 -> V_166 ; V_181 ++ ) {
F_53 ( & V_133 [ V_178 ] ,
V_177 [ V_179 ] . V_125 ,
V_160 -> V_149 [ V_181 + 1 ] ,
V_177 [ V_181 ] . V_125 , NULL ) ;
V_178 ++ ;
}
V_179 ++ ;
}
}
static int F_67 ( struct V_146 * V_147 )
{
struct V_116 * V_177 ;
struct V_132 * V_133 ;
struct V_1 * V_70 = F_1 ( V_147 -> V_3 ) ;
struct V_49 * V_50 = V_70 -> V_51 ;
struct V_182 * V_183 = V_147 -> V_184 -> V_183 ;
char V_158 [ V_162 ] ;
struct V_103 * V_75 ;
struct V_52 * V_53 ;
int V_27 , V_12 = 0 , V_185 = 0 ;
if ( F_68 ( & V_50 -> V_186 ) || F_68 ( & V_50 -> V_187 ) )
return - V_32 ;
V_177 = F_63 ( V_147 -> V_3 ,
( sizeof( * V_177 ) * ( ( 2 * V_50 -> V_180 ) + V_50 -> V_166 ) ) ,
V_88 ) ;
if ( ! V_177 )
return - V_89 ;
F_20 (cvt, &hdmi->cvt_list, head) {
sprintf ( V_158 , L_18 , V_75 -> V_18 ) ;
V_27 = F_51 ( V_147 -> V_3 , & V_177 [ V_12 ] ,
V_188 , & V_75 -> V_18 ,
V_158 , V_183 [ V_12 ] . V_189 . V_190 , NULL , 0 ) ;
if ( V_27 < 0 )
return V_27 ;
V_12 ++ ;
}
F_20 (pin, &hdmi->pin_list, head) {
sprintf ( V_158 , L_19 , V_53 -> V_18 ) ;
V_27 = F_51 ( V_147 -> V_3 , & V_177 [ V_12 ] ,
V_191 , & V_53 -> V_18 ,
V_158 , NULL , NULL , 0 ) ;
if ( V_27 < 0 )
return V_27 ;
V_12 ++ ;
}
F_20 (pin, &hdmi->pin_list, head) {
sprintf ( V_158 , L_20 , V_53 -> V_18 ) ;
V_27 = F_62 ( V_70 , V_53 , & V_177 [ V_12 ] ,
V_158 ) ;
if ( V_27 < 0 )
return V_27 ;
V_12 ++ ;
V_185 += V_50 -> V_166 ;
V_185 ++ ;
}
V_133 = F_63 ( V_147 -> V_3 , ( sizeof( * V_133 ) * V_185 ) ,
V_88 ) ;
if ( ! V_133 )
return - V_89 ;
V_12 = 0 ;
F_20 (pin, &hdmi->pin_list, head) {
int V_192 = V_12 + V_50 -> V_166 ;
int V_193 = V_192 + V_50 -> V_180 ;
F_53 ( & V_133 [ V_12 ] ,
V_177 [ V_192 ] . V_125 , NULL ,
V_177 [ V_193 ] . V_125 , NULL ) ;
V_12 ++ ;
}
F_66 ( V_70 , V_177 , V_133 , V_12 ) ;
F_69 ( V_147 , V_177 ,
( ( 2 * V_50 -> V_180 ) + V_50 -> V_166 ) ) ;
F_70 ( V_147 , V_133 , V_185 ) ;
F_71 ( V_147 -> V_194 ) ;
return 0 ;
}
static int F_72 ( struct V_1 * V_70 )
{
struct V_49 * V_50 = V_70 -> V_51 ;
struct V_71 * V_72 ;
struct V_103 * V_75 ;
int V_195 = 0 ;
if ( F_68 ( & V_50 -> V_186 ) )
return - V_32 ;
F_20 (cvt, &hdmi->cvt_list, head) {
V_72 = & V_50 -> V_72 [ V_195 ] ;
V_72 -> V_195 = V_195 ;
V_72 -> V_75 = V_75 ;
V_195 ++ ;
if ( V_195 == V_196 ) {
F_42 ( & V_70 -> V_5 . V_3 ,
L_21 , V_195 ) ;
break;
}
}
return 0 ;
}
static int F_73 ( struct V_1 * V_70 , T_3 V_18 )
{
struct V_49 * V_50 = V_70 -> V_51 ;
struct V_103 * V_75 ;
char V_125 [ V_162 ] ;
V_75 = F_30 ( sizeof( * V_75 ) , V_88 ) ;
if ( ! V_75 )
return - V_89 ;
V_75 -> V_18 = V_18 ;
sprintf ( V_125 , L_17 , V_75 -> V_18 ) ;
V_75 -> V_125 = F_74 ( V_125 , V_88 ) ;
F_75 ( & V_75 -> V_197 , & V_50 -> V_186 ) ;
V_50 -> V_166 ++ ;
return F_49 ( & V_70 -> V_5 , V_75 ) ;
}
static void F_76 ( struct V_52 * V_53 , int V_198 )
{
struct V_1 * V_70 = V_53 -> V_70 ;
struct V_49 * V_50 = V_70 -> V_51 ;
struct V_104 * V_105 ;
int V_20 ;
V_53 -> V_199 = V_198 ;
F_77 ( & V_70 -> V_5 . V_3 ) ;
V_20 = F_11 ( & V_70 -> V_5 , V_53 -> V_18 , 0 ,
V_200 , 0 ) ;
F_12 ( & V_70 -> V_5 . V_3 , L_22 ,
V_20 , V_53 -> V_18 ) ;
F_59 ( & V_50 -> V_153 ) ;
V_53 -> V_9 . V_86 = ! ! ( V_20 & V_201 ) ;
V_53 -> V_9 . V_87 = ! ! ( V_20 & V_202 ) ;
V_105 = F_55 ( V_70 , V_53 ) ;
if ( ! V_53 -> V_9 . V_86 || ! V_53 -> V_9 . V_87 ) {
F_12 ( & V_70 -> V_5 . V_3 , L_23 ,
V_203 , V_53 -> V_18 ) ;
if ( V_105 ) {
F_12 ( & V_70 -> V_5 . V_3 ,
L_14 , V_105 -> V_154 ) ;
F_60 ( V_105 -> V_155 , 0 ) ;
}
F_61 ( & V_50 -> V_153 ) ;
goto V_204;
}
if ( V_53 -> V_9 . V_86 && V_53 -> V_9 . V_87 ) {
if ( F_14 ( & V_70 -> V_5 , V_53 -> V_18 ,
V_53 -> V_9 . V_57 ,
& V_53 -> V_9 . V_25 ) == 0 ) {
if ( V_105 ) {
F_12 ( & V_70 -> V_5 . V_3 ,
L_14 ,
V_105 -> V_154 ) ;
F_60 ( V_105 -> V_155 , V_156 ) ;
}
F_78 ( L_24 , V_205 ,
V_53 -> V_9 . V_57 , V_53 -> V_9 . V_25 ) ;
} else {
V_53 -> V_9 . V_86 = false ;
V_53 -> V_9 . V_87 = false ;
if ( V_105 ) {
F_12 ( & V_70 -> V_5 . V_3 ,
L_14 ,
V_105 -> V_154 ) ;
F_60 ( V_105 -> V_155 , 0 ) ;
}
}
}
F_61 ( & V_50 -> V_153 ) ;
if ( ( ! V_53 -> V_9 . V_86 || ! V_53 -> V_9 . V_87 ) && V_198 )
F_79 ( & V_53 -> V_206 , F_80 ( 300 ) ) ;
V_204:
F_81 ( & V_70 -> V_5 . V_3 ) ;
}
static void F_82 ( struct V_207 * V_206 )
{
struct V_52 * V_53 =
F_83 ( F_84 ( V_206 ) , struct V_52 , V_206 ) ;
if ( V_53 -> V_199 ++ > 6 )
V_53 -> V_199 = 0 ;
F_76 ( V_53 , V_53 -> V_199 ) ;
}
static int F_85 ( struct V_1 * V_70 , T_3 V_18 )
{
struct V_49 * V_50 = V_70 -> V_51 ;
struct V_52 * V_53 ;
V_53 = F_30 ( sizeof( * V_53 ) , V_88 ) ;
if ( ! V_53 )
return - V_89 ;
V_53 -> V_18 = V_18 ;
F_75 ( & V_53 -> V_197 , & V_50 -> V_187 ) ;
V_50 -> V_180 ++ ;
V_53 -> V_70 = V_70 ;
F_86 ( & V_53 -> V_206 , F_82 ) ;
return 0 ;
}
static void F_87 ( struct V_4 * V_5 )
{
unsigned int V_208 ;
V_208 = F_11 ( V_5 , V_209 , 0 ,
V_210 , 0 ) ;
if ( V_208 == - 1 || V_208 & V_211 )
return;
V_208 |= V_211 ;
V_208 = F_11 ( V_5 , V_209 , 0 ,
V_212 , V_208 ) ;
if ( V_208 == - 1 )
return;
}
static void F_88 ( struct V_4 * V_5 )
{
unsigned int V_208 ;
V_208 = F_11 ( V_5 , V_209 , 0 ,
V_210 , 0 ) ;
if ( V_208 == - 1 || V_208 & V_213 )
return;
V_208 |= V_213 ;
V_208 = F_11 ( V_5 , V_209 , 0 ,
V_212 , V_208 ) ;
if ( V_208 == - 1 )
return;
}
static int F_89 ( struct V_4 * V_5 ,
struct V_182 * * V_214 ,
struct V_49 * V_50 , int V_215 )
{
struct V_182 * V_216 ;
struct V_103 * V_75 ;
char V_125 [ V_162 ] , V_217 [ V_162 ] ;
int V_12 = 0 ;
T_4 V_114 , V_218 ;
unsigned int V_219 = 384000 , V_220 = 8000 ;
T_2 V_10 ;
int V_27 ;
V_216 = F_63 ( & V_5 -> V_3 ,
( sizeof( * V_216 ) * V_215 ) ,
V_88 ) ;
if ( ! V_216 )
return - V_89 ;
F_20 (cvt, &hdmi->cvt_list, head) {
V_27 = F_50 ( V_5 , V_75 -> V_18 ,
& V_114 , & V_10 , & V_218 ) ;
if ( V_27 )
return V_27 ;
sprintf ( V_217 , L_25 , V_12 + 1 ) ;
V_216 [ V_12 ] . V_125 = F_52 ( & V_5 -> V_3 ,
V_217 , V_88 ) ;
if ( ! V_216 [ V_12 ] . V_125 )
return - V_89 ;
snprintf ( V_125 , sizeof( V_125 ) , L_26 , V_12 + 1 ) ;
V_216 [ V_12 ] . V_189 . V_190 =
F_52 ( & V_5 -> V_3 , V_125 , V_88 ) ;
if ( ! V_216 [ V_12 ] . V_189 . V_190 )
return - V_89 ;
V_216 [ V_12 ] . V_189 . V_10 = V_10 ;
V_216 [ V_12 ] . V_189 . V_114 = V_114 ;
V_216 [ V_12 ] . V_189 . V_219 = V_219 ;
V_216 [ V_12 ] . V_189 . V_220 = V_220 ;
V_216 [ V_12 ] . V_189 . V_112 = 2 ;
V_216 [ V_12 ] . V_189 . V_113 = 2 ;
V_216 [ V_12 ] . V_221 = & V_222 ;
V_12 ++ ;
}
* V_214 = V_216 ;
return 0 ;
}
static int F_90 ( struct V_1 * V_70 ,
struct V_182 * * V_214 , int * V_215 )
{
T_3 V_18 ;
int V_12 , V_223 ;
struct V_4 * V_5 = & V_70 -> V_5 ;
struct V_49 * V_50 = V_70 -> V_51 ;
int V_27 ;
F_87 ( V_5 ) ;
F_88 ( V_5 ) ;
V_223 = F_91 ( V_5 , V_5 -> V_224 , & V_18 ) ;
if ( ! V_18 || V_223 <= 0 ) {
F_42 ( & V_5 -> V_3 , L_27 ) ;
return - V_32 ;
}
V_5 -> V_223 = V_223 ;
V_5 -> V_225 = V_18 ;
for ( V_12 = 0 ; V_12 < V_5 -> V_223 ; V_12 ++ , V_18 ++ ) {
unsigned int V_226 ;
unsigned int type ;
V_226 = F_41 ( V_5 , V_18 ) ;
type = F_92 ( V_226 ) ;
if ( ! ( V_226 & V_227 ) )
continue;
switch ( type ) {
case V_228 :
V_27 = F_73 ( V_70 , V_18 ) ;
if ( V_27 < 0 )
return V_27 ;
break;
case V_229 :
V_27 = F_85 ( V_70 , V_18 ) ;
if ( V_27 < 0 )
return V_27 ;
break;
}
}
V_5 -> V_230 = V_18 ;
if ( ! V_50 -> V_180 || ! V_50 -> V_166 )
return - V_65 ;
V_27 = F_89 ( V_5 , V_214 , V_50 , V_50 -> V_166 ) ;
if ( V_27 ) {
F_15 ( & V_5 -> V_3 , L_28 ,
V_27 ) ;
return V_27 ;
}
* V_215 = V_50 -> V_166 ;
return F_72 ( V_70 ) ;
}
static void F_93 ( void * V_231 , int V_232 )
{
struct V_1 * V_70 = V_231 ;
struct V_49 * V_50 = V_70 -> V_51 ;
struct V_52 * V_53 ;
struct V_233 * V_17 = V_70 -> V_234 ;
T_3 V_35 = V_232 + 0x04 ;
F_12 ( & V_70 -> V_5 . V_3 , L_29 , V_203 , V_35 ) ;
if ( F_94 ( V_17 -> V_184 . V_194 -> V_235 ) !=
V_236 )
return;
if ( F_95 ( & V_70 -> V_5 . V_237 ) )
return;
F_20 (pin, &hdmi->pin_list, head) {
if ( V_53 -> V_18 == V_35 )
F_76 ( V_53 , 1 ) ;
}
}
int F_96 ( struct V_78 * V_79 , int V_2 )
{
char V_238 [ V_162 ] ;
struct V_233 * V_17 = V_79 -> V_17 ;
struct V_1 * V_70 = F_97 ( V_17 ) ;
struct V_146 * V_147 =
F_98 ( & V_17 -> V_184 ) ;
struct V_49 * V_50 = V_70 -> V_51 ;
struct V_104 * V_105 ;
V_105 = F_30 ( sizeof( * V_105 ) , V_88 ) ;
if ( ! V_105 )
return - V_89 ;
V_105 -> V_154 = V_2 ;
V_105 -> V_75 = V_50 -> V_72 [ V_79 -> V_82 ] . V_75 ;
F_75 ( & V_105 -> V_197 , & V_50 -> V_239 ) ;
sprintf ( V_238 , L_30 , V_2 ) ;
return F_99 ( V_147 -> V_194 -> V_235 , V_238 ,
V_156 , & V_105 -> V_155 , true , false ) ;
}
static int F_100 ( struct V_233 * V_17 )
{
struct V_1 * V_70 = F_97 ( V_17 ) ;
struct V_49 * V_50 = V_70 -> V_51 ;
struct V_146 * V_147 =
F_98 ( & V_17 -> V_184 ) ;
struct V_52 * V_53 ;
int V_27 ;
V_70 -> V_234 = V_17 ;
V_27 = F_67 ( V_147 ) ;
if ( V_27 < 0 )
return V_27 ;
V_240 . V_241 = V_70 ;
V_27 = F_101 ( & V_240 ) ;
if ( V_27 < 0 ) {
F_15 ( & V_70 -> V_5 . V_3 , L_31 ,
V_27 ) ;
return V_27 ;
}
F_20 (pin, &hdmi->pin_list, head)
F_76 ( V_53 , 1 ) ;
V_70 -> V_194 = V_147 -> V_194 -> V_235 ;
F_102 ( & V_70 -> V_5 . V_3 ) ;
F_103 ( & V_70 -> V_5 . V_3 ) ;
F_104 ( & V_70 -> V_5 . V_3 ) ;
return 0 ;
}
static int F_105 ( struct V_233 * V_17 )
{
struct V_1 * V_70 = F_97 ( V_17 ) ;
F_106 ( & V_70 -> V_5 . V_3 ) ;
return 0 ;
}
static int F_107 ( struct V_2 * V_3 )
{
struct V_1 * V_70 = F_1 ( V_3 ) ;
struct V_4 * V_5 = & V_70 -> V_5 ;
F_77 ( & V_70 -> V_5 . V_3 ) ;
F_11 ( V_5 , V_5 -> V_224 , 0 , V_74 ,
V_108 ) ;
return 0 ;
}
static void F_108 ( struct V_2 * V_3 )
{
struct V_1 * V_70 = F_1 ( V_3 ) ;
struct V_49 * V_50 = V_70 -> V_51 ;
struct V_52 * V_53 ;
struct V_4 * V_5 = & V_70 -> V_5 ;
F_11 ( V_5 , V_5 -> V_224 , 0 , V_74 ,
V_98 ) ;
F_87 ( & V_70 -> V_5 ) ;
F_88 ( & V_70 -> V_5 ) ;
F_20 (pin, &hdmi->pin_list, head)
F_76 ( V_53 , 1 ) ;
F_81 ( & V_70 -> V_5 . V_3 ) ;
}
static int F_109 ( struct V_1 * V_70 )
{
struct V_4 * V_17 = & V_70 -> V_5 ;
struct V_49 * V_242 ;
struct V_182 * V_216 = NULL ;
int V_215 = 0 ;
int V_27 = 0 ;
V_242 = F_63 ( & V_17 -> V_3 , sizeof( * V_242 ) , V_88 ) ;
if ( V_242 == NULL )
return - V_89 ;
V_70 -> V_51 = V_242 ;
F_110 ( & V_17 -> V_3 , V_70 ) ;
F_111 ( & V_242 -> V_187 ) ;
F_111 ( & V_242 -> V_186 ) ;
F_111 ( & V_242 -> V_239 ) ;
F_112 ( & V_242 -> V_153 ) ;
V_27 = F_113 ( V_70 -> V_5 . V_243 , true ) ;
if ( V_27 < 0 ) {
F_15 ( & V_70 -> V_5 . V_3 ,
L_32 ,
V_27 ) ;
return V_27 ;
}
V_27 = F_90 ( V_70 , & V_216 , & V_215 ) ;
if ( V_27 < 0 ) {
F_15 ( & V_17 -> V_3 ,
L_33 , V_27 ) ;
return V_27 ;
}
return F_114 ( & V_17 -> V_3 , & V_244 ,
V_216 , V_215 ) ;
}
static int F_115 ( struct V_1 * V_70 )
{
struct V_49 * V_50 = V_70 -> V_51 ;
struct V_52 * V_53 , * V_245 ;
struct V_103 * V_75 , * V_246 ;
struct V_104 * V_105 , * V_247 ;
F_116 ( & V_70 -> V_5 . V_3 ) ;
F_117 (pcm, pcm_next, &hdmi->pcm_list, head) {
V_105 -> V_75 = NULL ;
V_105 -> V_53 = NULL ;
F_118 ( & V_105 -> V_197 ) ;
F_37 ( V_105 ) ;
}
F_117 (cvt, cvt_next, &hdmi->cvt_list, head) {
F_118 ( & V_75 -> V_197 ) ;
F_37 ( V_75 -> V_125 ) ;
F_37 ( V_75 ) ;
}
F_117 (pin, pin_next, &hdmi->pin_list, head) {
F_118 ( & V_53 -> V_197 ) ;
F_37 ( V_53 ) ;
}
return 0 ;
}
static int F_119 ( struct V_2 * V_3 )
{
struct V_1 * V_70 = F_1 ( V_3 ) ;
struct V_4 * V_5 = & V_70 -> V_5 ;
struct V_248 * V_243 = V_5 -> V_243 ;
int V_110 ;
F_12 ( V_3 , L_34 , V_203 ) ;
if ( ! V_243 )
return 0 ;
F_11 ( V_5 , V_5 -> V_224 , 0 , V_74 ,
V_108 ) ;
V_110 = F_113 ( V_243 , false ) ;
if ( V_110 < 0 ) {
F_15 ( V_243 -> V_3 , L_35 ) ;
return V_110 ;
}
return 0 ;
}
static int F_120 ( struct V_2 * V_3 )
{
struct V_1 * V_70 = F_1 ( V_3 ) ;
struct V_4 * V_5 = & V_70 -> V_5 ;
struct V_248 * V_243 = V_5 -> V_243 ;
int V_110 ;
F_12 ( V_3 , L_34 , V_203 ) ;
if ( ! V_243 )
return 0 ;
V_110 = F_113 ( V_243 , true ) ;
if ( V_110 < 0 ) {
F_15 ( V_243 -> V_3 , L_35 ) ;
return V_110 ;
}
F_87 ( & V_70 -> V_5 ) ;
F_88 ( & V_70 -> V_5 ) ;
F_11 ( V_5 , V_5 -> V_224 , 0 , V_74 ,
V_98 ) ;
return 0 ;
}
static int T_6 F_121 ( void )
{
return F_122 ( & V_249 ) ;
}
static void T_7 F_123 ( void )
{
F_124 ( & V_249 ) ;
}

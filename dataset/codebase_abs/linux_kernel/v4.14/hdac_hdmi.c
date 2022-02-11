static struct V_1 *
F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_6 = NULL ;
F_2 (pcm, &hdmi->pcm_list, head) {
if ( V_6 -> V_5 == V_5 )
break;
}
return V_6 ;
}
static void F_3 ( struct V_1 * V_6 ,
struct V_7 * V_8 , bool V_9 )
{
struct V_10 * V_11 = V_8 -> V_12 -> V_11 ;
if ( V_9 )
F_4 ( V_8 -> V_13 , V_8 -> V_14 ) ;
else
F_5 ( V_8 -> V_13 , V_8 -> V_14 ) ;
if ( V_9 ) {
if ( V_6 -> V_15 == 0 ) {
F_6 ( & V_11 -> V_16 . V_17 ,
L_1 ,
V_6 -> V_18 ) ;
F_7 ( V_6 -> V_19 , V_20 ,
V_20 ) ;
}
V_6 -> V_15 ++ ;
} else {
if ( V_6 -> V_15 == 1 )
F_7 ( V_6 -> V_19 , 0 , V_20 ) ;
if ( V_6 -> V_15 > 0 )
V_6 -> V_15 -- ;
}
F_8 ( V_8 -> V_13 ) ;
}
static int F_9 ( struct V_10 * V_16 , T_1 V_21 )
{
unsigned int V_22 ;
unsigned int type , V_23 ;
V_22 = F_10 ( & V_16 -> V_16 , V_21 ) ;
type = F_11 ( V_22 ) ;
if ( ! ( V_22 & V_24 ) || ( type != V_25 ) )
return 0 ;
V_23 = F_12 ( & V_16 -> V_16 , V_21 ,
V_26 ) ;
if ( V_23 == - 1 )
return V_23 ;
return V_23 & V_27 ;
}
static int F_13 ( struct V_10 * V_16 ,
struct V_7 * V_8 )
{
return F_14 ( & V_16 -> V_16 , V_8 -> V_12 -> V_21 ,
0 , V_28 , 0 ) ;
}
static int F_15 ( struct V_10 * V_16 ,
struct V_7 * V_8 )
{
int V_29 ;
if ( ! V_8 -> V_12 -> V_30 )
return 0 ;
V_29 = F_9 ( V_16 , V_8 -> V_12 -> V_21 ) ;
if ( V_29 < 0 )
return - V_31 ;
if ( V_29 + 1 < V_8 -> V_32 )
return 0 ;
F_16 ( & V_16 -> V_16 , V_8 -> V_12 -> V_21 , 0 ,
V_33 , V_8 -> V_32 ) ;
if ( V_8 -> V_32 != F_13 ( V_16 , V_8 ) )
return - V_31 ;
F_6 ( & V_16 -> V_16 . V_17 , L_2 , V_8 -> V_32 ) ;
return 0 ;
}
static struct V_1 * F_17 ( struct V_2 * V_3 ,
int V_34 )
{
struct V_1 * V_6 ;
F_2 (pcm, &hdmi->pcm_list, head) {
if ( V_6 -> V_18 == V_34 )
return V_6 ;
}
return NULL ;
}
static inline struct V_10 * F_18 ( struct V_35 * V_17 )
{
struct V_36 * V_16 = F_19 ( V_17 ) ;
return F_20 ( V_16 ) ;
}
static unsigned int F_21 ( const T_2 * V_37 )
{
return ( ( V_37 [ 0 ] >> 0x3 ) & 0x1f ) ;
}
static unsigned int F_22 ( const T_2 * V_37 )
{
return ( V_37 [ 2 ] & 7 ) ;
}
static int F_23 ( struct V_38 * V_39 ,
void * V_40 )
{
T_3 V_41 = V_42 ;
int V_43 ;
const T_2 * V_37 , * V_44 = V_40 ;
V_37 = F_24 ( V_44 ) ;
if ( ! V_37 )
goto V_45;
for ( V_43 = F_25 ( V_44 ) ; V_43 > 0 ; V_43 -- , V_37 += 3 ) {
if ( F_21 ( V_37 ) == 1 ) {
if ( F_22 ( V_37 ) & 0x6 )
V_41 |= V_46 ;
}
}
V_45:
return F_26 ( V_39 , V_47 ,
V_41 ) ;
}
static void
F_27 ( struct V_10 * V_16 , T_1 V_48 ,
int V_49 , int V_50 )
{
int V_51 ;
V_51 = ( V_49 << 5 ) | ( V_50 & 0x1f ) ;
F_16 ( & V_16 -> V_16 , V_48 , 0 ,
V_52 , V_51 ) ;
}
static int F_28 ( struct V_10 * V_16 ,
struct V_1 * V_6 , struct V_7 * V_8 )
{
T_4 V_53 [ V_54 + V_55 ] ;
struct V_56 V_57 ;
struct V_58 * V_12 = V_8 -> V_12 ;
struct V_59 V_60 ;
struct V_2 * V_3 = V_16 -> V_61 ;
struct V_4 * V_5 = V_6 -> V_5 ;
T_2 * V_62 ;
int V_63 ;
int V_43 ;
const T_2 * V_44 ;
T_2 V_64 ;
int V_65 , V_66 ;
V_66 = F_29 ( & V_16 -> V_16 , V_8 -> V_40 . V_67 . V_68 ,
V_6 -> V_65 , V_6 -> V_69 , true , V_6 -> V_70 ) ;
V_65 = F_30 ( V_66 ) ;
V_3 -> V_70 . V_71 . V_72 ( & V_16 -> V_16 , V_5 -> V_21 , V_65 ) ;
F_31 ( & V_3 -> V_70 , V_12 -> V_21 , false , V_66 ,
V_6 -> V_65 , V_6 -> V_70 , V_6 -> V_69 ) ;
V_44 = V_8 -> V_40 . V_73 ;
V_64 = F_32 ( V_44 ) ;
switch ( V_64 ) {
case V_74 :
F_33 ( & V_57 ) ;
V_57 . V_65 = V_65 ;
V_57 . V_75 = V_66 ;
V_63 = F_34 ( & V_57 , V_53 , sizeof( V_53 ) ) ;
if ( V_63 < 0 )
return V_63 ;
break;
case V_76 :
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_60 . type = 0x84 ;
V_60 . V_77 = 0x1b ;
V_60 . V_78 = 0x11 << 2 ;
V_60 . V_79 = V_65 - 1 ;
V_60 . V_80 = V_66 ;
V_62 = ( T_2 * ) & V_60 ;
break;
default:
F_35 ( & V_16 -> V_16 . V_17 , L_3 ,
V_64 ) ;
return - V_31 ;
}
F_27 ( V_16 , V_12 -> V_21 , 0x0 , 0x0 ) ;
F_16 ( & V_16 -> V_16 , V_12 -> V_21 , 0 ,
V_81 , V_82 ) ;
F_27 ( V_16 , V_12 -> V_21 , 0x0 , 0x0 ) ;
if ( V_64 == V_74 ) {
for ( V_43 = 0 ; V_43 < sizeof( V_53 ) ; V_43 ++ )
F_16 ( & V_16 -> V_16 , V_12 -> V_21 , 0 ,
V_83 , V_53 [ V_43 ] ) ;
} else {
for ( V_43 = 0 ; V_43 < sizeof( V_60 ) ; V_43 ++ )
F_16 ( & V_16 -> V_16 , V_12 -> V_21 , 0 ,
V_83 , V_62 [ V_43 ] ) ;
}
F_27 ( V_16 , V_12 -> V_21 , 0x0 , 0x0 ) ;
F_16 ( & V_16 -> V_16 , V_12 -> V_21 , 0 ,
V_81 , V_84 ) ;
return 0 ;
}
static int F_36 ( struct V_85 * V_86 ,
unsigned int V_87 , unsigned int V_88 ,
int V_89 , int V_90 )
{
struct V_10 * V_11 = F_37 ( V_86 ) ;
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_91 * V_92 ;
struct V_1 * V_6 ;
F_6 ( & V_11 -> V_16 . V_17 , L_4 , V_93 , V_87 ) ;
V_92 = & V_3 -> V_92 [ V_86 -> V_32 ] ;
V_6 = F_1 ( V_3 , V_92 -> V_5 ) ;
if ( V_6 )
V_6 -> V_94 = ( V_87 << 4 ) ;
return 0 ;
}
static int F_38 ( struct V_95 * V_96 ,
struct V_97 * V_98 , struct V_85 * V_86 )
{
struct V_10 * V_16 = F_37 ( V_86 ) ;
struct V_2 * V_3 = V_16 -> V_61 ;
struct V_91 * V_92 ;
struct V_7 * V_8 ;
struct V_1 * V_6 ;
int V_99 ;
V_92 = & V_3 -> V_92 [ V_86 -> V_32 ] ;
V_8 = V_92 -> V_8 ;
if ( ! V_8 )
return - V_100 ;
if ( ( ! V_8 -> V_40 . V_101 ) || ( ! V_8 -> V_40 . V_102 ) ) {
F_35 ( & V_16 -> V_16 . V_17 ,
L_5 ,
V_8 -> V_12 -> V_21 , V_8 -> V_32 ) ;
return - V_100 ;
}
V_99 = F_39 ( F_40 ( V_98 ) ,
F_41 ( V_98 ) , F_42 ( V_98 ) ,
V_86 -> V_103 -> V_104 . V_105 , 0 ) ;
V_6 = F_1 ( V_3 , V_92 -> V_5 ) ;
if ( ! V_6 )
return - V_31 ;
V_6 -> V_99 = V_99 ;
V_6 -> V_65 = F_41 ( V_98 ) ;
return 0 ;
}
static int F_43 ( struct V_10 * V_16 ,
struct V_58 * V_12 ,
struct V_7 * V_8 )
{
if ( ! ( F_10 ( & V_16 -> V_16 , V_12 -> V_21 ) & V_106 ) ) {
F_44 ( & V_16 -> V_16 . V_17 ,
L_6 ,
V_12 -> V_21 , F_10 ( & V_16 -> V_16 , V_12 -> V_21 ) ) ;
return - V_107 ;
}
if ( F_15 ( V_16 , V_8 ) < 0 )
return - V_31 ;
V_8 -> V_108 = F_45 ( & V_16 -> V_16 , V_12 -> V_21 ,
V_8 -> V_109 , V_110 ) ;
if ( V_8 -> V_108 == 0 )
F_44 ( & V_16 -> V_16 . V_17 ,
L_7 ,
V_12 -> V_21 , V_8 -> V_32 ) ;
F_6 ( & V_16 -> V_16 . V_17 , L_8 ,
V_8 -> V_108 , V_12 -> V_21 , V_8 -> V_32 ) ;
return V_8 -> V_108 ;
}
static struct V_7 * F_46 (
struct V_10 * V_11 ,
struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_6 ;
struct V_7 * V_8 = NULL ;
int V_63 , V_43 ;
F_2 (pcm, &hdmi->pcm_list, head) {
if ( V_6 -> V_5 == V_5 ) {
if ( F_47 ( & V_6 -> V_111 ) )
continue;
F_2 (port, &pcm->port_list, head) {
F_48 ( & V_6 -> V_112 ) ;
V_63 = F_43 ( V_11 ,
V_8 -> V_12 , V_8 ) ;
F_49 ( & V_6 -> V_112 ) ;
if ( V_63 < 0 )
continue;
for ( V_43 = 0 ; V_43 < V_8 -> V_108 ; V_43 ++ ) {
if ( V_8 -> V_109 [ V_43 ] == V_5 -> V_21 &&
V_8 -> V_40 . V_101 &&
V_8 -> V_40 . V_102 )
return V_8 ;
}
}
}
}
return NULL ;
}
static int F_50 ( struct V_95 * V_96 ,
struct V_85 * V_86 )
{
struct V_10 * V_16 = F_37 ( V_86 ) ;
struct V_2 * V_3 = V_16 -> V_61 ;
struct V_91 * V_92 ;
struct V_4 * V_5 ;
struct V_7 * V_8 ;
int V_63 ;
V_92 = & V_3 -> V_92 [ V_86 -> V_32 ] ;
V_5 = V_92 -> V_5 ;
V_8 = F_46 ( V_16 , V_3 , V_5 ) ;
if ( ! V_8 )
return 0 ;
if ( ( ! V_8 -> V_40 . V_101 ) ||
( ! V_8 -> V_40 . V_102 ) ) {
F_44 ( & V_16 -> V_16 . V_17 ,
L_9 ,
V_8 -> V_40 . V_101 , V_8 -> V_40 . V_102 ,
V_8 -> V_12 -> V_21 , V_8 -> V_32 ) ;
return 0 ;
}
V_92 -> V_8 = V_8 ;
V_63 = F_23 ( V_96 -> V_39 ,
V_8 -> V_40 . V_73 ) ;
if ( V_63 < 0 )
return V_63 ;
return F_51 ( V_96 -> V_39 ,
V_8 -> V_40 . V_73 ) ;
}
static void F_52 ( struct V_95 * V_96 ,
struct V_85 * V_86 )
{
struct V_10 * V_16 = F_37 ( V_86 ) ;
struct V_2 * V_3 = V_16 -> V_61 ;
struct V_91 * V_92 ;
struct V_1 * V_6 ;
V_92 = & V_3 -> V_92 [ V_86 -> V_32 ] ;
V_6 = F_1 ( V_3 , V_92 -> V_5 ) ;
if ( V_6 ) {
F_48 ( & V_6 -> V_112 ) ;
V_6 -> V_69 = false ;
memset ( V_6 -> V_70 , 0 , sizeof( V_6 -> V_70 ) ) ;
V_6 -> V_65 = 0 ;
F_49 ( & V_6 -> V_112 ) ;
}
if ( V_92 -> V_8 )
V_92 -> V_8 = NULL ;
}
static int
F_53 ( struct V_36 * V_16 , struct V_4 * V_5 )
{
unsigned int V_113 ;
struct V_10 * V_11 = F_20 ( V_16 ) ;
struct V_2 * V_3 = V_11 -> V_61 ;
int V_114 ;
V_113 = F_10 ( V_16 , V_5 -> V_21 ) ;
V_113 = F_54 ( V_113 ) ;
V_5 -> V_115 . V_116 = 2 ;
V_5 -> V_115 . V_117 = V_113 ;
if ( V_113 > V_3 -> V_70 . V_117 )
V_3 -> V_70 . V_117 = V_113 ;
V_114 = F_55 ( V_16 , V_5 -> V_21 ,
& V_5 -> V_115 . V_118 ,
& V_5 -> V_115 . V_41 ,
& V_5 -> V_115 . V_119 ) ;
if ( V_114 < 0 )
F_35 ( & V_16 -> V_17 ,
L_10 ,
V_5 -> V_21 , V_114 ) ;
return V_114 ;
}
static int F_56 ( struct V_35 * V_17 ,
struct V_120 * V_121 , enum V_122 V_32 ,
void * V_123 , const char * V_124 , const char * V_125 ,
struct V_126 * V_127 , int V_128 ,
int (* F_57)( struct V_120 * ,
struct V_129 * , int ) , unsigned short V_130 )
{
V_121 -> V_32 = V_32 ;
V_121 -> V_131 = F_58 ( V_17 , V_124 , V_132 ) ;
if ( ! V_121 -> V_131 )
return - V_133 ;
V_121 -> V_134 = V_125 ;
V_121 -> V_135 = V_136 ;
V_121 -> V_137 = 0 ;
V_121 -> V_138 = V_127 ;
V_121 -> V_139 = V_128 ;
V_121 -> V_123 = V_123 ;
V_121 -> F_57 = F_57 ;
V_121 -> V_130 = V_130 ;
return 0 ;
}
static void F_59 ( struct V_140 * V_141 ,
const char * V_142 , const char * V_143 , const char * V_144 ,
int (* F_60)( struct V_120 * V_144 ,
struct V_120 * V_142 ) )
{
V_141 -> V_142 = V_142 ;
V_141 -> V_145 = V_144 ;
V_141 -> V_143 = V_143 ;
V_141 -> V_146 = F_60 ;
}
static struct V_1 * F_61 ( struct V_10 * V_11 ,
struct V_7 * V_8 )
{
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_1 * V_6 = NULL ;
struct V_7 * V_147 ;
F_2 (pcm, &hdmi->pcm_list, head) {
if ( F_47 ( & V_6 -> V_111 ) )
continue;
F_2 (p, &pcm->port_list, head) {
if ( V_147 -> V_32 == V_8 -> V_32 && V_8 -> V_12 == V_147 -> V_12 )
return V_6 ;
}
}
return NULL ;
}
static void F_62 ( struct V_10 * V_11 ,
T_1 V_21 , unsigned int V_148 )
{
if ( F_10 ( & V_11 -> V_16 , V_21 ) & V_149 ) {
if ( ! F_63 ( & V_11 -> V_16 , V_21 , V_148 ) )
F_16 ( & V_11 -> V_16 , V_21 , 0 ,
V_150 , V_148 ) ;
}
}
static void F_64 ( struct V_10 * V_11 ,
T_1 V_21 , int V_51 )
{
if ( F_10 ( & V_11 -> V_16 , V_21 ) & V_151 )
F_16 ( & V_11 -> V_16 , V_21 , 0 ,
V_152 , V_51 ) ;
}
static int F_65 ( struct V_120 * V_121 ,
struct V_129 * V_153 , int F_57 )
{
struct V_7 * V_8 = V_121 -> V_123 ;
struct V_10 * V_11 = F_18 ( V_121 -> V_13 -> V_17 ) ;
struct V_1 * V_6 ;
F_6 ( & V_11 -> V_16 . V_17 , L_11 ,
V_93 , V_121 -> V_131 , F_57 ) ;
V_6 = F_61 ( V_11 , V_8 ) ;
if ( ! V_6 )
return - V_31 ;
if ( F_15 ( V_11 , V_8 ) < 0 )
return - V_31 ;
switch ( F_57 ) {
case V_154 :
F_62 ( V_11 , V_8 -> V_12 -> V_21 , V_155 ) ;
F_16 ( & V_11 -> V_16 , V_8 -> V_12 -> V_21 , 0 ,
V_156 , V_157 ) ;
F_64 ( V_11 , V_8 -> V_12 -> V_21 , V_158 ) ;
return F_28 ( V_11 , V_6 , V_8 ) ;
case V_159 :
F_64 ( V_11 , V_8 -> V_12 -> V_21 , V_160 ) ;
F_16 ( & V_11 -> V_16 , V_8 -> V_12 -> V_21 , 0 ,
V_156 , 0 ) ;
F_62 ( V_11 , V_8 -> V_12 -> V_21 , V_161 ) ;
break;
}
return 0 ;
}
static int F_66 ( struct V_120 * V_121 ,
struct V_129 * V_153 , int F_57 )
{
struct V_4 * V_5 = V_121 -> V_123 ;
struct V_10 * V_11 = F_18 ( V_121 -> V_13 -> V_17 ) ;
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_1 * V_6 ;
F_6 ( & V_11 -> V_16 . V_17 , L_11 ,
V_93 , V_121 -> V_131 , F_57 ) ;
V_6 = F_1 ( V_3 , V_5 ) ;
if ( ! V_6 )
return - V_31 ;
switch ( F_57 ) {
case V_154 :
F_62 ( V_11 , V_5 -> V_21 , V_155 ) ;
F_16 ( & V_11 -> V_16 , V_5 -> V_21 , 0 ,
V_162 , 1 ) ;
F_16 ( & V_11 -> V_16 , V_5 -> V_21 , 0 ,
V_163 , 0 ) ;
F_16 ( & V_11 -> V_16 , V_5 -> V_21 , 0 ,
V_164 , V_6 -> V_94 ) ;
F_16 ( & V_11 -> V_16 , V_5 -> V_21 , 0 ,
V_165 , V_6 -> V_99 ) ;
break;
case V_159 :
F_16 ( & V_11 -> V_16 , V_5 -> V_21 , 0 ,
V_164 , 0 ) ;
F_16 ( & V_11 -> V_16 , V_5 -> V_21 , 0 ,
V_165 , 0 ) ;
F_62 ( V_11 , V_5 -> V_21 , V_161 ) ;
break;
}
return 0 ;
}
static int F_67 ( struct V_120 * V_121 ,
struct V_129 * V_153 , int F_57 )
{
struct V_7 * V_8 = V_121 -> V_123 ;
struct V_10 * V_11 = F_18 ( V_121 -> V_13 -> V_17 ) ;
int V_166 ;
F_6 ( & V_11 -> V_16 . V_17 , L_11 ,
V_93 , V_121 -> V_131 , F_57 ) ;
if ( ! V_153 )
V_153 = V_121 -> V_167 [ 0 ] ;
V_166 = F_68 ( V_153 ) ;
if ( F_15 ( V_11 , V_8 ) < 0 )
return - V_31 ;
if ( V_166 > 0 ) {
F_16 ( & V_11 -> V_16 , V_8 -> V_12 -> V_21 , 0 ,
V_168 , ( V_166 - 1 ) ) ;
}
return 0 ;
}
static int F_69 ( struct V_129 * V_169 ,
struct V_170 * V_171 )
{
int V_63 ;
struct V_7 * V_147 , * V_172 ;
struct V_173 * V_174 = (struct V_173 * ) V_169 -> V_175 ;
struct V_120 * V_121 = F_70 ( V_169 ) ;
struct V_176 * V_13 = V_121 -> V_13 ;
struct V_7 * V_8 = V_121 -> V_123 ;
struct V_10 * V_11 = F_18 ( V_13 -> V_17 ) ;
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_1 * V_6 = NULL ;
const char * V_177 = V_174 -> V_178 [ V_171 -> V_179 . V_180 . V_181 [ 0 ] ] ;
V_63 = F_71 ( V_169 , V_171 ) ;
if ( V_63 < 0 )
return V_63 ;
if ( V_8 == NULL )
return - V_107 ;
F_48 ( & V_3 -> V_182 ) ;
F_2 (pcm, &hdmi->pcm_list, head) {
if ( F_47 ( & V_6 -> V_111 ) )
continue;
F_72 (p, p_next, &pcm->port_list, head) {
if ( V_147 == V_8 && V_147 -> V_32 == V_8 -> V_32 &&
V_147 -> V_12 == V_8 -> V_12 ) {
F_3 ( V_6 , V_8 , false ) ;
F_73 ( & V_147 -> V_183 ) ;
}
}
}
F_2 (pcm, &hdmi->pcm_list, head) {
if ( ! strcmp ( V_177 , V_6 -> V_5 -> V_131 ) ) {
F_74 ( & V_8 -> V_183 , & V_6 -> V_111 ) ;
if ( V_8 -> V_40 . V_101 && V_8 -> V_40 . V_102 ) {
F_3 ( V_6 , V_8 , true ) ;
F_49 ( & V_3 -> V_182 ) ;
return V_63 ;
}
}
}
F_49 ( & V_3 -> V_182 ) ;
return V_63 ;
}
static int F_75 ( struct V_10 * V_11 ,
struct V_7 * V_8 ,
struct V_120 * V_184 ,
const char * V_185 )
{
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_58 * V_12 = V_8 -> V_12 ;
struct V_126 * V_153 ;
struct V_4 * V_5 ;
struct V_173 * V_186 ;
char V_187 [ V_188 ] ;
char V_189 [ V_188 ] ;
char * V_190 [ V_110 ] ;
int V_43 = 0 ;
int V_191 = V_3 -> V_192 + 1 ;
V_153 = F_76 ( & V_11 -> V_16 . V_17 , sizeof( * V_153 ) , V_132 ) ;
if ( ! V_153 )
return - V_133 ;
V_186 = F_76 ( & V_11 -> V_16 . V_17 , sizeof( * V_186 ) , V_132 ) ;
if ( ! V_186 )
return - V_133 ;
sprintf ( V_187 , L_12 , V_12 -> V_21 , V_8 -> V_32 ) ;
V_153 -> V_131 = F_58 ( & V_11 -> V_16 . V_17 , V_187 , V_132 ) ;
if ( ! V_153 -> V_131 )
return - V_133 ;
V_153 -> V_175 = ( long ) V_186 ;
V_153 -> V_193 = V_194 ;
V_153 -> V_195 = 0 ;
V_153 -> V_67 = V_196 ;
V_153 -> V_197 = F_69 ;
V_153 -> V_198 = V_199 ;
V_186 -> V_135 = V_136 ;
V_186 -> V_190 = V_191 ;
V_186 -> V_200 = F_77 ( V_186 -> V_190 ) - 1 ;
sprintf ( V_189 , L_13 ) ;
V_190 [ V_43 ] = F_58 ( & V_11 -> V_16 . V_17 , V_189 , V_132 ) ;
if ( ! V_190 [ V_43 ] )
return - V_133 ;
F_2 (cvt, &hdmi->cvt_list, head) {
V_43 ++ ;
sprintf ( V_189 , L_14 , V_5 -> V_21 ) ;
V_190 [ V_43 ] = F_58 ( & V_11 -> V_16 . V_17 , V_189 , V_132 ) ;
if ( ! V_190 [ V_43 ] )
return - V_133 ;
}
V_186 -> V_178 = F_78 ( & V_11 -> V_16 . V_17 , V_190 ,
( V_191 * sizeof( char * ) ) , V_132 ) ;
if ( ! V_186 -> V_178 )
return - V_133 ;
return F_56 ( & V_11 -> V_16 . V_17 , V_184 ,
V_201 , V_8 , V_185 , NULL , V_153 , 1 ,
F_67 ,
V_154 | V_202 ) ;
}
static void F_79 ( struct V_10 * V_11 ,
struct V_120 * V_203 ,
struct V_140 * V_141 , int V_204 )
{
struct V_2 * V_3 = V_11 -> V_61 ;
const struct V_126 * V_153 ;
struct V_173 * V_186 ;
int V_205 = V_3 -> V_192 + V_3 -> V_29 ;
int V_43 , V_206 ;
for ( V_43 = 0 ; V_43 < V_3 -> V_29 ; V_43 ++ ) {
V_153 = V_203 [ V_205 ] . V_138 ;
V_186 = (struct V_173 * ) V_153 -> V_175 ;
for ( V_206 = 0 ; V_206 < V_3 -> V_192 ; V_206 ++ ) {
F_59 ( & V_141 [ V_204 ] ,
V_203 [ V_205 ] . V_131 ,
V_186 -> V_178 [ V_206 + 1 ] ,
V_203 [ V_206 ] . V_131 , NULL ) ;
V_204 ++ ;
}
V_205 ++ ;
}
}
static int F_80 ( struct V_176 * V_13 )
{
struct V_120 * V_203 ;
struct V_140 * V_141 ;
struct V_10 * V_11 = F_18 ( V_13 -> V_17 ) ;
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_207 * V_208 = V_13 -> V_209 -> V_208 ;
char V_185 [ V_188 ] ;
struct V_4 * V_5 ;
struct V_58 * V_12 ;
int V_63 , V_43 = 0 , V_210 = 0 , V_206 ;
if ( F_47 ( & V_3 -> V_211 ) || F_47 ( & V_3 -> V_212 ) )
return - V_107 ;
V_203 = F_76 ( V_13 -> V_17 , ( sizeof( * V_203 ) *
( ( 2 * V_3 -> V_29 ) + V_3 -> V_192 ) ) ,
V_132 ) ;
if ( ! V_203 )
return - V_133 ;
F_2 (cvt, &hdmi->cvt_list, head) {
sprintf ( V_185 , L_15 , V_5 -> V_21 ) ;
V_63 = F_56 ( V_13 -> V_17 , & V_203 [ V_43 ] ,
V_213 , V_5 ,
V_185 , V_208 [ V_43 ] . V_104 . V_214 , NULL , 0 ,
F_66 ,
V_154 | V_159 ) ;
if ( V_63 < 0 )
return V_63 ;
V_43 ++ ;
}
F_2 (pin, &hdmi->pin_list, head) {
for ( V_206 = 0 ; V_206 < V_12 -> V_29 ; V_206 ++ ) {
sprintf ( V_185 , L_16 ,
V_12 -> V_21 , V_12 -> V_215 [ V_206 ] . V_32 ) ;
V_63 = F_56 ( V_13 -> V_17 , & V_203 [ V_43 ] ,
V_216 , & V_12 -> V_215 [ V_206 ] ,
V_185 , NULL , NULL , 0 ,
F_65 ,
V_154 |
V_159 ) ;
if ( V_63 < 0 )
return V_63 ;
V_12 -> V_215 [ V_206 ] . V_217 = V_203 [ V_43 ] . V_131 ;
V_43 ++ ;
}
}
F_2 (pin, &hdmi->pin_list, head) {
for ( V_206 = 0 ; V_206 < V_12 -> V_29 ; V_206 ++ ) {
sprintf ( V_185 , L_17 ,
V_12 -> V_21 , V_12 -> V_215 [ V_206 ] . V_32 ) ;
V_63 = F_75 ( V_11 ,
& V_12 -> V_215 [ V_206 ] , & V_203 [ V_43 ] ,
V_185 ) ;
if ( V_63 < 0 )
return V_63 ;
V_43 ++ ;
V_210 += V_3 -> V_192 ;
V_210 ++ ;
}
}
V_141 = F_76 ( V_13 -> V_17 , ( sizeof( * V_141 ) * V_210 ) ,
V_132 ) ;
if ( ! V_141 )
return - V_133 ;
V_43 = 0 ;
F_2 (pin, &hdmi->pin_list, head) {
for ( V_206 = 0 ; V_206 < V_12 -> V_29 ; V_206 ++ ) {
int V_218 = V_43 + V_3 -> V_192 ;
int V_219 = V_218 + V_12 -> V_29 *
V_3 -> V_220 ;
F_59 ( & V_141 [ V_43 ] ,
V_203 [ V_218 ] . V_131 , NULL ,
V_203 [ V_219 ] . V_131 , NULL ) ;
V_43 ++ ;
}
}
F_79 ( V_11 , V_203 , V_141 , V_43 ) ;
F_81 ( V_13 , V_203 ,
( ( 2 * V_3 -> V_29 ) + V_3 -> V_192 ) ) ;
F_82 ( V_13 , V_141 , V_210 ) ;
F_83 ( V_13 -> V_221 ) ;
return 0 ;
}
static int F_84 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_91 * V_92 ;
struct V_4 * V_5 ;
int V_222 = 0 ;
if ( F_47 ( & V_3 -> V_211 ) )
return - V_107 ;
F_2 (cvt, &hdmi->cvt_list, head) {
V_92 = & V_3 -> V_92 [ V_222 ] ;
V_92 -> V_222 = V_222 ;
V_92 -> V_5 = V_5 ;
V_222 ++ ;
if ( V_222 == V_223 ) {
F_44 ( & V_11 -> V_16 . V_17 ,
L_18 , V_222 ) ;
break;
}
}
return 0 ;
}
static int F_85 ( struct V_10 * V_11 , T_1 V_21 )
{
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_4 * V_5 ;
char V_131 [ V_188 ] ;
V_5 = F_86 ( sizeof( * V_5 ) , V_132 ) ;
if ( ! V_5 )
return - V_133 ;
V_5 -> V_21 = V_21 ;
sprintf ( V_131 , L_14 , V_5 -> V_21 ) ;
V_5 -> V_131 = F_87 ( V_131 , V_132 ) ;
F_74 ( & V_5 -> V_183 , & V_3 -> V_211 ) ;
V_3 -> V_192 ++ ;
return F_53 ( & V_11 -> V_16 , V_5 ) ;
}
static int F_88 ( struct V_10 * V_11 ,
struct V_7 * V_8 )
{
unsigned int V_78 , V_224 ;
V_78 = ( V_8 -> V_40 . V_73 [ V_225 ] & V_226 )
>> V_227 ;
if ( V_78 != V_228 && V_78 != V_229 ) {
F_35 ( & V_11 -> V_16 . V_17 , L_19 , V_78 ) ;
return - V_107 ;
}
V_224 = ( V_8 -> V_40 . V_73 [ V_230 ] &
V_231 ) >> V_232 ;
if ( V_224 > V_233 ) {
F_35 ( & V_11 -> V_16 . V_17 , L_20 , V_224 ) ;
return - V_107 ;
}
V_8 -> V_40 . V_67 . V_68 = V_8 -> V_40 . V_73 [ V_234 ] ;
return 0 ;
}
static void F_89 ( struct V_58 * V_12 ,
struct V_7 * V_8 )
{
struct V_10 * V_11 = V_12 -> V_11 ;
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_1 * V_6 ;
int V_235 = 0 ;
int V_236 = - 1 ;
if ( ! V_3 )
return;
F_48 ( & V_3 -> V_182 ) ;
V_8 -> V_40 . V_101 = false ;
if ( V_12 -> V_30 )
V_236 = V_8 -> V_32 ;
V_235 = F_90 ( & V_11 -> V_16 , V_12 -> V_21 , V_236 ,
& V_8 -> V_40 . V_101 ,
V_8 -> V_40 . V_73 ,
V_237 ) ;
if ( V_235 > 0 ) {
V_235 = F_91 ( V_235 , V_237 ) ;
if ( F_88 ( V_11 , V_8 ) < 0 )
V_235 = - V_107 ;
}
if ( V_235 > 0 ) {
V_8 -> V_40 . V_102 = true ;
V_8 -> V_40 . V_238 = V_235 ;
} else {
V_8 -> V_40 . V_102 = false ;
V_8 -> V_40 . V_238 = 0 ;
}
V_6 = F_61 ( V_11 , V_8 ) ;
if ( ! V_8 -> V_40 . V_101 || ! V_8 -> V_40 . V_102 ) {
F_35 ( & V_11 -> V_16 . V_17 , L_21 ,
V_93 , V_12 -> V_21 , V_8 -> V_32 ) ;
if ( V_6 )
F_3 ( V_6 , V_8 , false ) ;
F_49 ( & V_3 -> V_182 ) ;
return;
}
if ( V_8 -> V_40 . V_101 && V_8 -> V_40 . V_102 ) {
if ( V_6 )
F_3 ( V_6 , V_8 , true ) ;
F_92 ( L_22 , V_239 , 16 , 1 ,
V_8 -> V_40 . V_73 , V_8 -> V_40 . V_238 , false ) ;
}
F_49 ( & V_3 -> V_182 ) ;
}
static int F_93 ( struct V_2 * V_3 ,
struct V_58 * V_12 )
{
struct V_7 * V_215 ;
int V_240 = V_241 ;
int V_43 ;
V_215 = F_94 ( V_240 , sizeof( * V_215 ) , V_132 ) ;
if ( ! V_215 )
return - V_133 ;
for ( V_43 = 0 ; V_43 < V_240 ; V_43 ++ ) {
V_215 [ V_43 ] . V_32 = V_43 ;
V_215 [ V_43 ] . V_12 = V_12 ;
}
V_12 -> V_215 = V_215 ;
V_12 -> V_29 = V_240 ;
return 0 ;
}
static int F_95 ( struct V_10 * V_11 , T_1 V_21 )
{
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_58 * V_12 ;
int V_63 ;
V_12 = F_86 ( sizeof( * V_12 ) , V_132 ) ;
if ( ! V_12 )
return - V_133 ;
V_12 -> V_21 = V_21 ;
V_12 -> V_30 = false ;
V_12 -> V_11 = V_11 ;
V_63 = F_93 ( V_3 , V_12 ) ;
if ( V_63 < 0 )
return V_63 ;
F_74 ( & V_12 -> V_183 , & V_3 -> V_212 ) ;
V_3 -> V_220 ++ ;
V_3 -> V_29 += V_12 -> V_29 ;
return 0 ;
}
static void F_96 ( struct V_36 * V_16 )
{
unsigned int V_242 ;
struct V_10 * V_11 = F_20 ( V_16 ) ;
struct V_2 * V_3 = V_11 -> V_61 ;
unsigned int V_243 = V_3 -> V_244 -> V_243 ;
V_242 = F_14 ( V_16 , V_243 , 0 ,
V_245 , 0 ) ;
if ( V_242 == - 1 || V_242 & V_246 )
return;
V_242 |= V_246 ;
V_242 = F_14 ( V_16 , V_243 , 0 ,
V_247 , V_242 ) ;
if ( V_242 == - 1 )
return;
}
static void F_97 ( struct V_36 * V_16 )
{
unsigned int V_242 ;
struct V_10 * V_11 = F_20 ( V_16 ) ;
struct V_2 * V_3 = V_11 -> V_61 ;
unsigned int V_243 = V_3 -> V_244 -> V_243 ;
V_242 = F_14 ( V_16 , V_243 , 0 ,
V_245 , 0 ) ;
if ( V_242 == - 1 || V_242 & V_248 )
return;
V_242 |= V_248 ;
V_242 = F_14 ( V_16 , V_243 , 0 ,
V_247 , V_242 ) ;
if ( V_242 == - 1 )
return;
}
static int F_98 ( struct V_36 * V_16 ,
struct V_207 * * V_249 ,
struct V_2 * V_3 , int V_250 )
{
struct V_207 * V_251 ;
struct V_4 * V_5 ;
char V_131 [ V_188 ] , V_252 [ V_188 ] ;
int V_43 = 0 ;
T_5 V_118 , V_253 ;
unsigned int V_254 = 384000 , V_255 = 8000 ;
T_3 V_41 ;
int V_63 ;
V_251 = F_76 ( & V_16 -> V_17 ,
( sizeof( * V_251 ) * V_250 ) ,
V_132 ) ;
if ( ! V_251 )
return - V_133 ;
F_2 (cvt, &hdmi->cvt_list, head) {
V_63 = F_55 ( V_16 , V_5 -> V_21 ,
& V_118 , & V_41 , & V_253 ) ;
if ( V_63 )
return V_63 ;
sprintf ( V_252 , L_23 , V_43 + 1 ) ;
V_251 [ V_43 ] . V_131 = F_58 ( & V_16 -> V_17 ,
V_252 , V_132 ) ;
if ( ! V_251 [ V_43 ] . V_131 )
return - V_133 ;
snprintf ( V_131 , sizeof( V_131 ) , L_24 , V_43 + 1 ) ;
V_251 [ V_43 ] . V_104 . V_214 =
F_58 ( & V_16 -> V_17 , V_131 , V_132 ) ;
if ( ! V_251 [ V_43 ] . V_104 . V_214 )
return - V_133 ;
V_251 [ V_43 ] . V_104 . V_41 = V_41 ;
V_251 [ V_43 ] . V_104 . V_118 = V_118 ;
V_251 [ V_43 ] . V_104 . V_254 = V_254 ;
V_251 [ V_43 ] . V_104 . V_255 = V_255 ;
V_251 [ V_43 ] . V_104 . V_116 = 2 ;
V_251 [ V_43 ] . V_104 . V_117 = 2 ;
V_251 [ V_43 ] . V_104 . V_105 = V_253 ;
V_251 [ V_43 ] . V_71 = & V_256 ;
V_43 ++ ;
}
* V_249 = V_251 ;
return 0 ;
}
static int F_99 ( struct V_10 * V_11 ,
struct V_207 * * V_249 , int * V_250 )
{
T_1 V_21 ;
int V_43 , V_257 ;
struct V_36 * V_16 = & V_11 -> V_16 ;
struct V_2 * V_3 = V_11 -> V_61 ;
int V_63 ;
F_96 ( V_16 ) ;
F_97 ( V_16 ) ;
V_257 = F_100 ( V_16 , V_16 -> V_258 , & V_21 ) ;
if ( ! V_21 || V_257 <= 0 ) {
F_44 ( & V_16 -> V_17 , L_25 ) ;
return - V_107 ;
}
V_16 -> V_257 = V_257 ;
V_16 -> V_259 = V_21 ;
for ( V_43 = 0 ; V_43 < V_16 -> V_257 ; V_43 ++ , V_21 ++ ) {
unsigned int V_22 ;
unsigned int type ;
V_22 = F_10 ( V_16 , V_21 ) ;
type = F_11 ( V_22 ) ;
if ( ! ( V_22 & V_24 ) )
continue;
switch ( type ) {
case V_260 :
V_63 = F_85 ( V_11 , V_21 ) ;
if ( V_63 < 0 )
return V_63 ;
break;
case V_25 :
V_63 = F_95 ( V_11 , V_21 ) ;
if ( V_63 < 0 )
return V_63 ;
break;
}
}
V_16 -> V_261 = V_21 ;
if ( ! V_3 -> V_220 || ! V_3 -> V_192 )
return - V_31 ;
V_63 = F_98 ( V_16 , V_249 , V_3 , V_3 -> V_192 ) ;
if ( V_63 ) {
F_35 ( & V_16 -> V_17 , L_26 ,
V_63 ) ;
return V_63 ;
}
* V_250 = V_3 -> V_192 ;
return F_84 ( V_11 ) ;
}
static void F_101 ( void * V_262 , int V_8 , int V_263 )
{
struct V_10 * V_11 = V_262 ;
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_58 * V_12 = NULL ;
struct V_7 * V_264 = NULL ;
struct V_265 * V_266 = V_11 -> V_267 ;
int V_43 ;
T_1 V_48 = V_8 + 0x04 ;
F_6 ( & V_11 -> V_16 . V_17 , L_27 , V_93 ,
V_48 , V_263 ) ;
if ( F_102 ( V_266 -> V_209 . V_221 -> V_268 ) !=
V_269 )
return;
if ( F_103 ( & V_11 -> V_16 . V_270 ) )
return;
F_2 (pin, &hdmi->pin_list, head) {
if ( V_12 -> V_21 != V_48 )
continue;
if ( V_263 == - 1 ) {
V_12 -> V_30 = false ;
V_264 = & V_12 -> V_215 [ 0 ] ;
} else {
for ( V_43 = 0 ; V_43 < V_12 -> V_29 ; V_43 ++ ) {
V_12 -> V_30 = true ;
if ( V_12 -> V_215 [ V_43 ] . V_32 == V_263 ) {
V_264 = & V_12 -> V_215 [ V_43 ] ;
break;
}
}
}
if ( V_264 )
F_89 ( V_12 , V_264 ) ;
}
}
static struct V_271 * F_104 ( struct V_272 * V_221 ,
int V_35 )
{
struct V_273 * V_274 ;
F_2 (rtd, &card->rtd_list, list) {
if ( V_274 -> V_6 && ( V_274 -> V_6 -> V_35 == V_35 ) )
return V_274 -> V_6 ;
}
return NULL ;
}
static int F_105 ( struct V_272 * V_221 ,
struct V_10 * V_11 )
{
struct V_58 * V_12 ;
struct V_126 * V_153 ;
char V_187 [ V_188 ] , V_275 [ V_188 ] ;
char * V_131 ;
int V_43 = 0 , V_206 ;
struct V_265 * V_266 = V_11 -> V_267 ;
struct V_2 * V_3 = V_11 -> V_61 ;
V_153 = F_106 ( V_266 -> V_17 , V_3 -> V_29 ,
sizeof( * V_153 ) , V_132 ) ;
if ( ! V_153 )
return - V_133 ;
F_2 (pin, &hdmi->pin_list, head) {
for ( V_206 = 0 ; V_206 < V_12 -> V_29 ; V_206 ++ ) {
snprintf ( V_275 , sizeof( V_275 ) , L_28 ,
V_12 -> V_21 , V_12 -> V_215 [ V_206 ] . V_32 ) ;
V_131 = F_58 ( V_266 -> V_17 , V_275 , V_132 ) ;
if ( ! V_131 )
return - V_133 ;
snprintf ( V_187 , sizeof( V_187 ) , L_29 , V_275 ) ;
V_153 [ V_43 ] . V_131 = F_58 ( V_266 -> V_17 , V_187 ,
V_132 ) ;
if ( ! V_153 [ V_43 ] . V_131 )
return - V_133 ;
V_153 [ V_43 ] . V_175 = ( unsigned long ) V_131 ;
V_153 [ V_43 ] . V_193 = V_194 ;
V_153 [ V_43 ] . V_195 = 0 ;
V_153 [ V_43 ] . V_67 = V_276 ;
V_153 [ V_43 ] . V_197 = V_277 ;
V_153 [ V_43 ] . V_198 = V_278 ;
V_43 ++ ;
}
}
return F_107 ( V_221 , V_153 , V_43 ) ;
}
int F_108 ( struct V_265 * V_266 ,
struct V_176 * V_13 )
{
struct V_10 * V_11 = F_109 ( V_266 ) ;
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_58 * V_12 ;
struct V_120 * V_203 ;
struct V_140 * V_141 ;
char V_279 [ V_188 ] ;
int V_43 = 0 , V_206 , V_63 ;
V_203 = F_106 ( V_13 -> V_17 , V_3 -> V_29 ,
sizeof( * V_203 ) , V_132 ) ;
if ( ! V_203 )
return - V_133 ;
V_141 = F_106 ( V_13 -> V_17 , V_3 -> V_29 ,
sizeof( * V_141 ) , V_132 ) ;
if ( ! V_141 )
return - V_133 ;
F_2 (pin, &hdmi->pin_list, head) {
for ( V_206 = 0 ; V_206 < V_12 -> V_29 ; V_206 ++ ) {
snprintf ( V_279 , sizeof( V_279 ) , L_28 ,
V_12 -> V_21 , V_12 -> V_215 [ V_206 ] . V_32 ) ;
V_63 = F_56 ( V_13 -> V_17 , & V_203 [ V_43 ] ,
V_280 , NULL ,
V_279 , NULL , NULL , 0 , NULL , 0 ) ;
if ( V_63 < 0 )
return V_63 ;
V_12 -> V_215 [ V_206 ] . V_14 = V_203 [ V_43 ] . V_131 ;
V_12 -> V_215 [ V_206 ] . V_13 = V_13 ;
F_59 ( & V_141 [ V_43 ] , V_12 -> V_215 [ V_206 ] . V_14 ,
NULL , V_12 -> V_215 [ V_206 ] . V_217 , NULL ) ;
V_43 ++ ;
}
}
V_63 = F_81 ( V_13 , V_203 , V_3 -> V_29 ) ;
if ( V_63 < 0 )
return V_63 ;
V_63 = F_82 ( V_13 , V_141 , V_3 -> V_29 ) ;
if ( V_63 < 0 )
return V_63 ;
V_63 = F_83 ( V_13 -> V_221 ) ;
if ( V_63 < 0 )
return V_63 ;
V_63 = F_105 ( V_13 -> V_221 , V_11 ) ;
if ( V_63 < 0 )
return V_63 ;
F_2 (pin, &hdmi->pin_list, head) {
for ( V_206 = 0 ; V_206 < V_12 -> V_29 ; V_206 ++ )
F_5 ( V_12 -> V_215 [ V_206 ] . V_13 ,
V_12 -> V_215 [ V_206 ] . V_14 ) ;
}
return 0 ;
}
int F_110 ( struct V_85 * V_86 , int V_35 ,
struct V_281 * V_19 )
{
struct V_265 * V_266 = V_86 -> V_266 ;
struct V_10 * V_11 = F_109 ( V_266 ) ;
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_1 * V_6 ;
struct V_271 * V_271 ;
int V_114 ;
V_6 = F_86 ( sizeof( * V_6 ) , V_132 ) ;
if ( ! V_6 )
return - V_133 ;
V_6 -> V_18 = V_35 ;
V_6 -> V_5 = V_3 -> V_92 [ V_86 -> V_32 ] . V_5 ;
V_6 -> V_15 = 0 ;
V_6 -> V_19 = V_19 ;
F_111 ( & V_6 -> V_112 ) ;
F_112 ( & V_6 -> V_111 ) ;
V_271 = F_104 ( V_86 -> V_209 -> V_221 , V_35 ) ;
if ( V_271 ) {
V_114 = F_113 ( V_271 , V_35 , & V_3 -> V_70 ) ;
if ( V_114 < 0 ) {
F_35 ( & V_11 -> V_16 . V_17 ,
L_30 ,
V_114 , V_35 ) ;
F_114 ( V_6 ) ;
return V_114 ;
}
}
F_74 ( & V_6 -> V_183 , & V_3 -> V_282 ) ;
return 0 ;
}
static void F_115 ( struct V_10 * V_11 ,
struct V_2 * V_3 , bool V_283 )
{
int V_43 ;
struct V_58 * V_12 ;
F_2 (pin, &hdmi->pin_list, head) {
if ( V_283 ) {
if ( F_9 ( V_11 , V_12 -> V_21 ) == 0 )
V_12 -> V_30 = false ;
else
V_12 -> V_30 = true ;
}
for ( V_43 = 0 ; V_43 < V_12 -> V_29 ; V_43 ++ ) {
if ( ! V_12 -> V_30 && V_43 > 0 )
continue;
F_89 ( V_12 , & V_12 -> V_215 [ V_43 ] ) ;
}
}
}
static int F_116 ( struct V_265 * V_266 )
{
struct V_10 * V_11 = F_109 ( V_266 ) ;
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_176 * V_13 =
F_117 ( & V_266 -> V_209 ) ;
struct V_284 * V_285 = NULL ;
int V_63 ;
V_11 -> V_267 = V_266 ;
V_285 = F_118 ( V_11 -> V_286 , F_119 ( & V_11 -> V_16 . V_17 ) ) ;
if ( ! V_285 ) {
F_35 ( & V_11 -> V_16 . V_17 , L_31 ) ;
return - V_31 ;
}
F_120 ( V_11 -> V_286 , V_285 ) ;
V_63 = F_80 ( V_13 ) ;
if ( V_63 < 0 )
return V_63 ;
V_287 . V_288 = V_11 ;
V_63 = F_121 ( & V_287 ) ;
if ( V_63 < 0 ) {
F_35 ( & V_11 -> V_16 . V_17 , L_32 ,
V_63 ) ;
return V_63 ;
}
F_115 ( V_11 , V_3 , true ) ;
V_11 -> V_221 = V_13 -> V_221 -> V_268 ;
F_122 ( & V_11 -> V_16 . V_17 ) ;
F_123 ( & V_11 -> V_16 . V_17 ) ;
F_124 ( & V_11 -> V_16 . V_17 ) ;
return 0 ;
}
static int F_125 ( struct V_265 * V_266 )
{
struct V_10 * V_11 = F_109 ( V_266 ) ;
F_126 ( & V_11 -> V_16 . V_17 ) ;
return 0 ;
}
static int F_127 ( struct V_35 * V_17 )
{
struct V_10 * V_11 = F_18 ( V_17 ) ;
struct V_36 * V_16 = & V_11 -> V_16 ;
F_128 ( & V_11 -> V_16 . V_17 ) ;
F_14 ( V_16 , V_16 -> V_258 , 0 , V_150 ,
V_161 ) ;
return 0 ;
}
static void F_129 ( struct V_35 * V_17 )
{
struct V_10 * V_11 = F_18 ( V_17 ) ;
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_36 * V_16 = & V_11 -> V_16 ;
F_14 ( V_16 , V_16 -> V_258 , 0 , V_150 ,
V_155 ) ;
F_96 ( & V_11 -> V_16 ) ;
F_97 ( & V_11 -> V_16 ) ;
F_115 ( V_11 , V_3 , false ) ;
F_130 ( & V_11 -> V_16 . V_17 ) ;
}
static void F_131 ( struct V_36 * V_16 , int V_34 ,
unsigned char * V_70 )
{
struct V_10 * V_11 = F_20 ( V_16 ) ;
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_1 * V_6 = F_17 ( V_3 , V_34 ) ;
memcpy ( V_70 , V_6 -> V_70 , F_132 ( V_6 -> V_70 ) ) ;
}
static void F_133 ( struct V_36 * V_16 , int V_34 ,
unsigned char * V_70 , int V_289 )
{
struct V_10 * V_11 = F_20 ( V_16 ) ;
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_1 * V_6 = F_17 ( V_3 , V_34 ) ;
struct V_7 * V_8 ;
if ( F_47 ( & V_6 -> V_111 ) )
return;
F_48 ( & V_6 -> V_112 ) ;
V_6 -> V_69 = true ;
memcpy ( V_6 -> V_70 , V_70 , F_132 ( V_6 -> V_70 ) ) ;
F_2 (port, &pcm->port_list, head)
if ( V_289 )
F_28 ( V_11 , V_6 , V_8 ) ;
F_49 ( & V_6 -> V_112 ) ;
}
static bool F_134 ( struct V_36 * V_16 , int V_34 )
{
struct V_10 * V_11 = F_20 ( V_16 ) ;
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_1 * V_6 = F_17 ( V_3 , V_34 ) ;
if ( F_47 ( & V_6 -> V_111 ) )
return false ;
return true ;
}
static int F_135 ( struct V_36 * V_16 , int V_34 )
{
struct V_10 * V_11 = F_20 ( V_16 ) ;
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_1 * V_6 = F_17 ( V_3 , V_34 ) ;
struct V_7 * V_8 ;
if ( F_47 ( & V_6 -> V_111 ) )
return 0 ;
V_8 = F_136 ( & V_6 -> V_111 , struct V_7 , V_183 ) ;
if ( ! V_8 )
return 0 ;
if ( ! V_8 || ! V_8 -> V_40 . V_102 )
return 0 ;
return V_8 -> V_40 . V_67 . V_68 ;
}
static int F_137 ( struct V_10 * V_11 )
{
struct V_36 * V_266 = & V_11 -> V_16 ;
struct V_2 * V_290 ;
struct V_207 * V_251 = NULL ;
struct V_284 * V_285 = NULL ;
int V_250 = 0 ;
int V_63 = 0 ;
struct V_291 * V_292 = F_138 ( V_266 -> V_17 . V_103 ) ;
const struct V_293 * V_294 = F_139 ( V_266 , V_292 ) ;
V_285 = F_118 ( V_11 -> V_286 , F_119 ( & V_11 -> V_16 . V_17 ) ) ;
if ( ! V_285 ) {
F_35 ( & V_11 -> V_16 . V_17 , L_31 ) ;
return - V_31 ;
}
F_120 ( V_11 -> V_286 , V_285 ) ;
V_290 = F_76 ( & V_266 -> V_17 , sizeof( * V_290 ) , V_132 ) ;
if ( V_290 == NULL )
return - V_133 ;
V_11 -> V_61 = V_290 ;
F_140 ( V_266 , & V_290 -> V_70 ) ;
V_290 -> V_70 . V_71 . V_295 = F_131 ;
V_290 -> V_70 . V_71 . V_296 = F_133 ;
V_290 -> V_70 . V_71 . V_297 = F_134 ;
V_290 -> V_70 . V_71 . V_298 = F_135 ;
if ( V_294 -> V_299 )
V_290 -> V_244 =
(struct V_300 * ) V_294 -> V_299 ;
else
V_290 -> V_244 = & V_301 ;
F_141 ( & V_266 -> V_17 , V_11 ) ;
F_112 ( & V_290 -> V_212 ) ;
F_112 ( & V_290 -> V_211 ) ;
F_112 ( & V_290 -> V_282 ) ;
F_111 ( & V_290 -> V_182 ) ;
V_63 = F_142 ( V_11 -> V_16 . V_302 , true ) ;
if ( V_63 < 0 ) {
F_35 ( & V_11 -> V_16 . V_17 ,
L_33 ,
V_63 ) ;
return V_63 ;
}
V_63 = F_99 ( V_11 , & V_251 , & V_250 ) ;
if ( V_63 < 0 ) {
F_35 ( & V_266 -> V_17 ,
L_34 , V_63 ) ;
return V_63 ;
}
V_63 = F_143 ( & V_266 -> V_17 , & V_303 ,
V_251 , V_250 ) ;
F_144 ( V_11 -> V_286 , V_285 ) ;
return V_63 ;
}
static int F_145 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_58 * V_12 , * V_304 ;
struct V_4 * V_5 , * V_305 ;
struct V_1 * V_6 , * V_306 ;
struct V_7 * V_8 , * V_307 ;
int V_43 ;
F_146 ( & V_11 -> V_16 . V_17 ) ;
F_72 (pcm, pcm_next, &hdmi->pcm_list, head) {
V_6 -> V_5 = NULL ;
if ( F_47 ( & V_6 -> V_111 ) )
continue;
F_72 (port, port_next,
&pcm->port_list, head)
F_73 ( & V_8 -> V_183 ) ;
F_73 ( & V_6 -> V_183 ) ;
F_114 ( V_6 ) ;
}
F_72 (cvt, cvt_next, &hdmi->cvt_list, head) {
F_73 ( & V_5 -> V_183 ) ;
F_114 ( V_5 -> V_131 ) ;
F_114 ( V_5 ) ;
}
F_72 (pin, pin_next, &hdmi->pin_list, head) {
for ( V_43 = 0 ; V_43 < V_12 -> V_29 ; V_43 ++ )
V_12 -> V_215 [ V_43 ] . V_12 = NULL ;
F_114 ( V_12 -> V_215 ) ;
F_73 ( & V_12 -> V_183 ) ;
F_114 ( V_12 ) ;
}
return 0 ;
}
static int F_147 ( struct V_35 * V_17 )
{
struct V_10 * V_11 = F_18 ( V_17 ) ;
struct V_36 * V_16 = & V_11 -> V_16 ;
struct V_308 * V_302 = V_16 -> V_302 ;
struct V_309 * V_286 = F_148 ( V_302 ) ;
struct V_284 * V_285 = NULL ;
int V_114 ;
F_6 ( V_17 , L_35 , V_93 ) ;
if ( ! V_302 )
return 0 ;
F_14 ( V_16 , V_16 -> V_258 , 0 , V_150 ,
V_161 ) ;
V_114 = F_142 ( V_302 , false ) ;
if ( V_114 < 0 ) {
F_35 ( V_302 -> V_17 , L_36 ) ;
return V_114 ;
}
V_285 = F_118 ( V_286 , F_119 ( V_17 ) ) ;
if ( ! V_285 ) {
F_35 ( V_17 , L_31 ) ;
return - V_31 ;
}
F_144 ( V_286 , V_285 ) ;
return 0 ;
}
static int F_149 ( struct V_35 * V_17 )
{
struct V_10 * V_11 = F_18 ( V_17 ) ;
struct V_36 * V_16 = & V_11 -> V_16 ;
struct V_308 * V_302 = V_16 -> V_302 ;
struct V_309 * V_286 = F_148 ( V_302 ) ;
struct V_284 * V_285 = NULL ;
int V_114 ;
F_6 ( V_17 , L_35 , V_93 ) ;
if ( ! V_302 )
return 0 ;
V_285 = F_118 ( V_286 , F_119 ( V_17 ) ) ;
if ( ! V_285 ) {
F_35 ( V_17 , L_31 ) ;
return - V_31 ;
}
F_120 ( V_286 , V_285 ) ;
V_114 = F_142 ( V_302 , true ) ;
if ( V_114 < 0 ) {
F_35 ( V_302 -> V_17 , L_36 ) ;
return V_114 ;
}
F_96 ( & V_11 -> V_16 ) ;
F_97 ( & V_11 -> V_16 ) ;
F_14 ( V_16 , V_16 -> V_258 , 0 , V_150 ,
V_155 ) ;
return 0 ;
}
static int T_6 F_150 ( void )
{
return F_151 ( & V_310 ) ;
}
static void T_7 F_152 ( void )
{
F_153 ( & V_310 ) ;
}

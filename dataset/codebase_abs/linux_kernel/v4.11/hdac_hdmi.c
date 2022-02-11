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
24 , 0 ) ;
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
if ( ! ( F_10 ( & V_16 -> V_16 , V_12 -> V_21 ) & V_103 ) ) {
F_44 ( & V_16 -> V_16 . V_17 ,
L_6 ,
V_12 -> V_21 , F_10 ( & V_16 -> V_16 , V_12 -> V_21 ) ) ;
return - V_104 ;
}
if ( F_15 ( V_16 , V_8 ) < 0 )
return - V_31 ;
V_8 -> V_105 = F_45 ( & V_16 -> V_16 , V_12 -> V_21 ,
V_8 -> V_106 , V_107 ) ;
if ( V_8 -> V_105 == 0 )
F_44 ( & V_16 -> V_16 . V_17 ,
L_7 ,
V_12 -> V_21 , V_8 -> V_32 ) ;
F_6 ( & V_16 -> V_16 . V_17 , L_8 ,
V_8 -> V_105 , V_12 -> V_21 , V_8 -> V_32 ) ;
return V_8 -> V_105 ;
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
if ( F_47 ( & V_6 -> V_108 ) )
continue;
F_2 (port, &pcm->port_list, head) {
F_48 ( & V_6 -> V_109 ) ;
V_63 = F_43 ( V_11 ,
V_8 -> V_12 , V_8 ) ;
F_49 ( & V_6 -> V_109 ) ;
if ( V_63 < 0 )
continue;
for ( V_43 = 0 ; V_43 < V_8 -> V_105 ; V_43 ++ ) {
if ( V_8 -> V_106 [ V_43 ] == V_5 -> V_21 &&
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
F_48 ( & V_6 -> V_109 ) ;
V_6 -> V_69 = false ;
memset ( V_6 -> V_70 , 0 , sizeof( V_6 -> V_70 ) ) ;
V_6 -> V_65 = 0 ;
F_49 ( & V_6 -> V_109 ) ;
}
if ( V_92 -> V_8 )
V_92 -> V_8 = NULL ;
}
static int
F_53 ( struct V_36 * V_16 , struct V_4 * V_5 )
{
unsigned int V_110 ;
struct V_10 * V_11 = F_20 ( V_16 ) ;
struct V_2 * V_3 = V_11 -> V_61 ;
int V_111 ;
V_110 = F_10 ( V_16 , V_5 -> V_21 ) ;
V_110 = F_54 ( V_110 ) ;
V_5 -> V_112 . V_113 = 2 ;
V_5 -> V_112 . V_114 = V_110 ;
if ( V_110 > V_3 -> V_70 . V_114 )
V_3 -> V_70 . V_114 = V_110 ;
V_111 = F_55 ( V_16 , V_5 -> V_21 ,
& V_5 -> V_112 . V_115 ,
& V_5 -> V_112 . V_41 ,
& V_5 -> V_112 . V_116 ) ;
if ( V_111 < 0 )
F_35 ( & V_16 -> V_17 ,
L_10 ,
V_5 -> V_21 , V_111 ) ;
return V_111 ;
}
static int F_56 ( struct V_35 * V_17 ,
struct V_117 * V_118 , enum V_119 V_32 ,
void * V_120 , const char * V_121 , const char * V_122 ,
struct V_123 * V_124 , int V_125 ,
int (* F_57)( struct V_117 * ,
struct V_126 * , int ) , unsigned short V_127 )
{
V_118 -> V_32 = V_32 ;
V_118 -> V_128 = F_58 ( V_17 , V_121 , V_129 ) ;
if ( ! V_118 -> V_128 )
return - V_130 ;
V_118 -> V_131 = V_122 ;
V_118 -> V_132 = V_133 ;
V_118 -> V_134 = 0 ;
V_118 -> V_135 = V_124 ;
V_118 -> V_136 = V_125 ;
V_118 -> V_120 = V_120 ;
V_118 -> F_57 = F_57 ;
V_118 -> V_127 = V_127 ;
return 0 ;
}
static void F_59 ( struct V_137 * V_138 ,
const char * V_139 , const char * V_140 , const char * V_141 ,
int (* F_60)( struct V_117 * V_141 ,
struct V_117 * V_139 ) )
{
V_138 -> V_139 = V_139 ;
V_138 -> V_142 = V_141 ;
V_138 -> V_140 = V_140 ;
V_138 -> V_143 = F_60 ;
}
static struct V_1 * F_61 ( struct V_10 * V_11 ,
struct V_7 * V_8 )
{
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_1 * V_6 = NULL ;
struct V_7 * V_144 ;
F_2 (pcm, &hdmi->pcm_list, head) {
if ( F_47 ( & V_6 -> V_108 ) )
continue;
F_2 (p, &pcm->port_list, head) {
if ( V_144 -> V_32 == V_8 -> V_32 && V_8 -> V_12 == V_144 -> V_12 )
return V_6 ;
}
}
return NULL ;
}
static void F_62 ( struct V_10 * V_11 ,
T_1 V_21 , unsigned int V_145 )
{
if ( F_10 ( & V_11 -> V_16 , V_21 ) & V_146 ) {
if ( ! F_63 ( & V_11 -> V_16 , V_21 , V_145 ) )
F_16 ( & V_11 -> V_16 , V_21 , 0 ,
V_147 , V_145 ) ;
}
}
static void F_64 ( struct V_10 * V_11 ,
T_1 V_21 , int V_51 )
{
if ( F_10 ( & V_11 -> V_16 , V_21 ) & V_148 )
F_16 ( & V_11 -> V_16 , V_21 , 0 ,
V_149 , V_51 ) ;
}
static int F_65 ( struct V_117 * V_118 ,
struct V_126 * V_150 , int F_57 )
{
struct V_7 * V_8 = V_118 -> V_120 ;
struct V_10 * V_11 = F_18 ( V_118 -> V_13 -> V_17 ) ;
struct V_1 * V_6 ;
F_6 ( & V_11 -> V_16 . V_17 , L_11 ,
V_93 , V_118 -> V_128 , F_57 ) ;
V_6 = F_61 ( V_11 , V_8 ) ;
if ( ! V_6 )
return - V_31 ;
if ( F_15 ( V_11 , V_8 ) < 0 )
return - V_31 ;
switch ( F_57 ) {
case V_151 :
F_62 ( V_11 , V_8 -> V_12 -> V_21 , V_152 ) ;
F_16 ( & V_11 -> V_16 , V_8 -> V_12 -> V_21 , 0 ,
V_153 , V_154 ) ;
F_64 ( V_11 , V_8 -> V_12 -> V_21 , V_155 ) ;
return F_28 ( V_11 , V_6 , V_8 ) ;
case V_156 :
F_64 ( V_11 , V_8 -> V_12 -> V_21 , V_157 ) ;
F_16 ( & V_11 -> V_16 , V_8 -> V_12 -> V_21 , 0 ,
V_153 , 0 ) ;
F_62 ( V_11 , V_8 -> V_12 -> V_21 , V_158 ) ;
break;
}
return 0 ;
}
static int F_66 ( struct V_117 * V_118 ,
struct V_126 * V_150 , int F_57 )
{
struct V_4 * V_5 = V_118 -> V_120 ;
struct V_10 * V_11 = F_18 ( V_118 -> V_13 -> V_17 ) ;
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_1 * V_6 ;
F_6 ( & V_11 -> V_16 . V_17 , L_11 ,
V_93 , V_118 -> V_128 , F_57 ) ;
V_6 = F_1 ( V_3 , V_5 ) ;
if ( ! V_6 )
return - V_31 ;
switch ( F_57 ) {
case V_151 :
F_62 ( V_11 , V_5 -> V_21 , V_152 ) ;
F_16 ( & V_11 -> V_16 , V_5 -> V_21 , 0 ,
V_159 , 1 ) ;
F_16 ( & V_11 -> V_16 , V_5 -> V_21 , 0 ,
V_160 , 0 ) ;
F_16 ( & V_11 -> V_16 , V_5 -> V_21 , 0 ,
V_161 , V_6 -> V_94 ) ;
F_16 ( & V_11 -> V_16 , V_5 -> V_21 , 0 ,
V_162 , V_6 -> V_99 ) ;
break;
case V_156 :
F_16 ( & V_11 -> V_16 , V_5 -> V_21 , 0 ,
V_161 , 0 ) ;
F_16 ( & V_11 -> V_16 , V_5 -> V_21 , 0 ,
V_162 , 0 ) ;
F_62 ( V_11 , V_5 -> V_21 , V_158 ) ;
break;
}
return 0 ;
}
static int F_67 ( struct V_117 * V_118 ,
struct V_126 * V_150 , int F_57 )
{
struct V_7 * V_8 = V_118 -> V_120 ;
struct V_10 * V_11 = F_18 ( V_118 -> V_13 -> V_17 ) ;
int V_163 ;
F_6 ( & V_11 -> V_16 . V_17 , L_11 ,
V_93 , V_118 -> V_128 , F_57 ) ;
if ( ! V_150 )
V_150 = V_118 -> V_164 [ 0 ] ;
V_163 = F_68 ( V_150 ) ;
if ( F_15 ( V_11 , V_8 ) < 0 )
return - V_31 ;
if ( V_163 > 0 ) {
F_16 ( & V_11 -> V_16 , V_8 -> V_12 -> V_21 , 0 ,
V_165 , ( V_163 - 1 ) ) ;
}
return 0 ;
}
static int F_69 ( struct V_126 * V_166 ,
struct V_167 * V_168 )
{
int V_63 ;
struct V_7 * V_144 , * V_169 ;
struct V_170 * V_171 = (struct V_170 * ) V_166 -> V_172 ;
struct V_117 * V_118 = F_70 ( V_166 ) ;
struct V_173 * V_13 = V_118 -> V_13 ;
struct V_7 * V_8 = V_118 -> V_120 ;
struct V_10 * V_11 = F_18 ( V_13 -> V_17 ) ;
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_1 * V_6 = NULL ;
const char * V_174 = V_171 -> V_175 [ V_168 -> V_176 . V_177 . V_178 [ 0 ] ] ;
V_63 = F_71 ( V_166 , V_168 ) ;
if ( V_63 < 0 )
return V_63 ;
if ( V_8 == NULL )
return - V_104 ;
F_48 ( & V_3 -> V_179 ) ;
F_2 (pcm, &hdmi->pcm_list, head) {
if ( F_47 ( & V_6 -> V_108 ) )
continue;
F_72 (p, p_next, &pcm->port_list, head) {
if ( V_144 == V_8 && V_144 -> V_32 == V_8 -> V_32 &&
V_144 -> V_12 == V_8 -> V_12 ) {
F_3 ( V_6 , V_8 , false ) ;
F_73 ( & V_144 -> V_180 ) ;
}
}
}
F_2 (pcm, &hdmi->pcm_list, head) {
if ( ! strcmp ( V_174 , V_6 -> V_5 -> V_128 ) ) {
F_74 ( & V_8 -> V_180 , & V_6 -> V_108 ) ;
if ( V_8 -> V_40 . V_101 && V_8 -> V_40 . V_102 ) {
F_3 ( V_6 , V_8 , true ) ;
F_49 ( & V_3 -> V_179 ) ;
return V_63 ;
}
}
}
F_49 ( & V_3 -> V_179 ) ;
return V_63 ;
}
static int F_75 ( struct V_10 * V_11 ,
struct V_7 * V_8 ,
struct V_117 * V_181 ,
const char * V_182 )
{
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_58 * V_12 = V_8 -> V_12 ;
struct V_123 * V_150 ;
struct V_4 * V_5 ;
struct V_170 * V_183 ;
char V_184 [ V_185 ] ;
char V_186 [ V_185 ] ;
char * V_187 [ V_107 ] ;
int V_43 = 0 ;
int V_188 = V_3 -> V_189 + 1 ;
V_150 = F_76 ( & V_11 -> V_16 . V_17 , sizeof( * V_150 ) , V_129 ) ;
if ( ! V_150 )
return - V_130 ;
V_183 = F_76 ( & V_11 -> V_16 . V_17 , sizeof( * V_183 ) , V_129 ) ;
if ( ! V_183 )
return - V_130 ;
sprintf ( V_184 , L_12 , V_12 -> V_21 , V_8 -> V_32 ) ;
V_150 -> V_128 = F_58 ( & V_11 -> V_16 . V_17 , V_184 , V_129 ) ;
if ( ! V_150 -> V_128 )
return - V_130 ;
V_150 -> V_172 = ( long ) V_183 ;
V_150 -> V_190 = V_191 ;
V_150 -> V_192 = 0 ;
V_150 -> V_67 = V_193 ;
V_150 -> V_194 = F_69 ;
V_150 -> V_195 = V_196 ;
V_183 -> V_132 = V_133 ;
V_183 -> V_187 = V_188 ;
V_183 -> V_197 = F_77 ( V_183 -> V_187 ) - 1 ;
sprintf ( V_186 , L_13 ) ;
V_187 [ V_43 ] = F_58 ( & V_11 -> V_16 . V_17 , V_186 , V_129 ) ;
if ( ! V_187 [ V_43 ] )
return - V_130 ;
F_2 (cvt, &hdmi->cvt_list, head) {
V_43 ++ ;
sprintf ( V_186 , L_14 , V_5 -> V_21 ) ;
V_187 [ V_43 ] = F_58 ( & V_11 -> V_16 . V_17 , V_186 , V_129 ) ;
if ( ! V_187 [ V_43 ] )
return - V_130 ;
}
V_183 -> V_175 = F_78 ( & V_11 -> V_16 . V_17 , V_187 ,
( V_188 * sizeof( char * ) ) , V_129 ) ;
if ( ! V_183 -> V_175 )
return - V_130 ;
return F_56 ( & V_11 -> V_16 . V_17 , V_181 ,
V_198 , V_8 , V_182 , NULL , V_150 , 1 ,
F_67 ,
V_151 | V_199 ) ;
}
static void F_79 ( struct V_10 * V_11 ,
struct V_117 * V_200 ,
struct V_137 * V_138 , int V_201 )
{
struct V_2 * V_3 = V_11 -> V_61 ;
const struct V_123 * V_150 ;
struct V_170 * V_183 ;
int V_202 = V_3 -> V_189 + V_3 -> V_29 ;
int V_43 , V_203 ;
for ( V_43 = 0 ; V_43 < V_3 -> V_29 ; V_43 ++ ) {
V_150 = V_200 [ V_202 ] . V_135 ;
V_183 = (struct V_170 * ) V_150 -> V_172 ;
for ( V_203 = 0 ; V_203 < V_3 -> V_189 ; V_203 ++ ) {
F_59 ( & V_138 [ V_201 ] ,
V_200 [ V_202 ] . V_128 ,
V_183 -> V_175 [ V_203 + 1 ] ,
V_200 [ V_203 ] . V_128 , NULL ) ;
V_201 ++ ;
}
V_202 ++ ;
}
}
static int F_80 ( struct V_173 * V_13 )
{
struct V_117 * V_200 ;
struct V_137 * V_138 ;
struct V_10 * V_11 = F_18 ( V_13 -> V_17 ) ;
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_204 * V_205 = V_13 -> V_206 -> V_205 ;
char V_182 [ V_185 ] ;
struct V_4 * V_5 ;
struct V_58 * V_12 ;
int V_63 , V_43 = 0 , V_207 = 0 , V_203 ;
if ( F_47 ( & V_3 -> V_208 ) || F_47 ( & V_3 -> V_209 ) )
return - V_104 ;
V_200 = F_76 ( V_13 -> V_17 , ( sizeof( * V_200 ) *
( ( 2 * V_3 -> V_29 ) + V_3 -> V_189 ) ) ,
V_129 ) ;
if ( ! V_200 )
return - V_130 ;
F_2 (cvt, &hdmi->cvt_list, head) {
sprintf ( V_182 , L_15 , V_5 -> V_21 ) ;
V_63 = F_56 ( V_13 -> V_17 , & V_200 [ V_43 ] ,
V_210 , V_5 ,
V_182 , V_205 [ V_43 ] . V_211 . V_212 , NULL , 0 ,
F_66 ,
V_151 | V_156 ) ;
if ( V_63 < 0 )
return V_63 ;
V_43 ++ ;
}
F_2 (pin, &hdmi->pin_list, head) {
for ( V_203 = 0 ; V_203 < V_12 -> V_29 ; V_203 ++ ) {
sprintf ( V_182 , L_16 ,
V_12 -> V_21 , V_12 -> V_213 [ V_203 ] . V_32 ) ;
V_63 = F_56 ( V_13 -> V_17 , & V_200 [ V_43 ] ,
V_214 , & V_12 -> V_213 [ V_203 ] ,
V_182 , NULL , NULL , 0 ,
F_65 ,
V_151 |
V_156 ) ;
if ( V_63 < 0 )
return V_63 ;
V_12 -> V_213 [ V_203 ] . V_215 = V_200 [ V_43 ] . V_128 ;
V_43 ++ ;
}
}
F_2 (pin, &hdmi->pin_list, head) {
for ( V_203 = 0 ; V_203 < V_12 -> V_29 ; V_203 ++ ) {
sprintf ( V_182 , L_17 ,
V_12 -> V_21 , V_12 -> V_213 [ V_203 ] . V_32 ) ;
V_63 = F_75 ( V_11 ,
& V_12 -> V_213 [ V_203 ] , & V_200 [ V_43 ] ,
V_182 ) ;
if ( V_63 < 0 )
return V_63 ;
V_43 ++ ;
V_207 += V_3 -> V_189 ;
V_207 ++ ;
}
}
V_138 = F_76 ( V_13 -> V_17 , ( sizeof( * V_138 ) * V_207 ) ,
V_129 ) ;
if ( ! V_138 )
return - V_130 ;
V_43 = 0 ;
F_2 (pin, &hdmi->pin_list, head) {
for ( V_203 = 0 ; V_203 < V_12 -> V_29 ; V_203 ++ ) {
int V_216 = V_43 + V_3 -> V_189 ;
int V_217 = V_216 + V_12 -> V_29 *
V_3 -> V_218 ;
F_59 ( & V_138 [ V_43 ] ,
V_200 [ V_216 ] . V_128 , NULL ,
V_200 [ V_217 ] . V_128 , NULL ) ;
V_43 ++ ;
}
}
F_79 ( V_11 , V_200 , V_138 , V_43 ) ;
F_81 ( V_13 , V_200 ,
( ( 2 * V_3 -> V_29 ) + V_3 -> V_189 ) ) ;
F_82 ( V_13 , V_138 , V_207 ) ;
F_83 ( V_13 -> V_219 ) ;
return 0 ;
}
static int F_84 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_91 * V_92 ;
struct V_4 * V_5 ;
int V_220 = 0 ;
if ( F_47 ( & V_3 -> V_208 ) )
return - V_104 ;
F_2 (cvt, &hdmi->cvt_list, head) {
V_92 = & V_3 -> V_92 [ V_220 ] ;
V_92 -> V_220 = V_220 ;
V_92 -> V_5 = V_5 ;
V_220 ++ ;
if ( V_220 == V_221 ) {
F_44 ( & V_11 -> V_16 . V_17 ,
L_18 , V_220 ) ;
break;
}
}
return 0 ;
}
static int F_85 ( struct V_10 * V_11 , T_1 V_21 )
{
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_4 * V_5 ;
char V_128 [ V_185 ] ;
V_5 = F_86 ( sizeof( * V_5 ) , V_129 ) ;
if ( ! V_5 )
return - V_130 ;
V_5 -> V_21 = V_21 ;
sprintf ( V_128 , L_14 , V_5 -> V_21 ) ;
V_5 -> V_128 = F_87 ( V_128 , V_129 ) ;
F_74 ( & V_5 -> V_180 , & V_3 -> V_208 ) ;
V_3 -> V_189 ++ ;
return F_53 ( & V_11 -> V_16 , V_5 ) ;
}
static int F_88 ( struct V_10 * V_11 ,
struct V_7 * V_8 )
{
unsigned int V_78 , V_222 ;
V_78 = ( V_8 -> V_40 . V_73 [ V_223 ] & V_224 )
>> V_225 ;
if ( V_78 != V_226 && V_78 != V_227 ) {
F_35 ( & V_11 -> V_16 . V_17 , L_19 , V_78 ) ;
return - V_104 ;
}
V_222 = ( V_8 -> V_40 . V_73 [ V_228 ] &
V_229 ) >> V_230 ;
if ( V_222 > V_231 ) {
F_35 ( & V_11 -> V_16 . V_17 , L_20 , V_222 ) ;
return - V_104 ;
}
V_8 -> V_40 . V_67 . V_68 = V_8 -> V_40 . V_73 [ V_232 ] ;
return 0 ;
}
static void F_89 ( struct V_58 * V_12 ,
struct V_7 * V_8 )
{
struct V_10 * V_11 = V_12 -> V_11 ;
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_1 * V_6 ;
int V_233 = 0 ;
int V_234 = - 1 ;
if ( ! V_3 )
return;
F_48 ( & V_3 -> V_179 ) ;
V_8 -> V_40 . V_101 = false ;
if ( V_12 -> V_30 )
V_234 = V_8 -> V_32 ;
V_233 = F_90 ( & V_11 -> V_16 , V_12 -> V_21 , V_234 ,
& V_8 -> V_40 . V_101 ,
V_8 -> V_40 . V_73 ,
V_235 ) ;
if ( V_233 > 0 ) {
V_233 = F_91 ( V_233 , V_235 ) ;
if ( F_88 ( V_11 , V_8 ) < 0 )
V_233 = - V_104 ;
}
if ( V_233 > 0 ) {
V_8 -> V_40 . V_102 = true ;
V_8 -> V_40 . V_236 = V_233 ;
} else {
V_8 -> V_40 . V_102 = false ;
V_8 -> V_40 . V_236 = 0 ;
}
V_6 = F_61 ( V_11 , V_8 ) ;
if ( ! V_8 -> V_40 . V_101 || ! V_8 -> V_40 . V_102 ) {
F_35 ( & V_11 -> V_16 . V_17 , L_21 ,
V_93 , V_12 -> V_21 , V_8 -> V_32 ) ;
if ( V_6 )
F_3 ( V_6 , V_8 , false ) ;
F_49 ( & V_3 -> V_179 ) ;
return;
}
if ( V_8 -> V_40 . V_101 && V_8 -> V_40 . V_102 ) {
if ( V_6 )
F_3 ( V_6 , V_8 , true ) ;
F_92 ( L_22 , V_237 , 16 , 1 ,
V_8 -> V_40 . V_73 , V_8 -> V_40 . V_236 , false ) ;
}
F_49 ( & V_3 -> V_179 ) ;
}
static int F_93 ( struct V_2 * V_3 ,
struct V_58 * V_12 )
{
struct V_7 * V_213 ;
int V_238 = V_239 ;
int V_43 ;
V_213 = F_94 ( V_238 , sizeof( * V_213 ) , V_129 ) ;
if ( ! V_213 )
return - V_130 ;
for ( V_43 = 0 ; V_43 < V_238 ; V_43 ++ ) {
V_213 [ V_43 ] . V_32 = V_43 ;
V_213 [ V_43 ] . V_12 = V_12 ;
}
V_12 -> V_213 = V_213 ;
V_12 -> V_29 = V_238 ;
return 0 ;
}
static int F_95 ( struct V_10 * V_11 , T_1 V_21 )
{
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_58 * V_12 ;
int V_63 ;
V_12 = F_86 ( sizeof( * V_12 ) , V_129 ) ;
if ( ! V_12 )
return - V_130 ;
V_12 -> V_21 = V_21 ;
V_12 -> V_30 = false ;
V_12 -> V_11 = V_11 ;
V_63 = F_93 ( V_3 , V_12 ) ;
if ( V_63 < 0 )
return V_63 ;
F_74 ( & V_12 -> V_180 , & V_3 -> V_209 ) ;
V_3 -> V_218 ++ ;
V_3 -> V_29 += V_12 -> V_29 ;
return 0 ;
}
static void F_96 ( struct V_36 * V_16 )
{
unsigned int V_240 ;
V_240 = F_14 ( V_16 , V_241 , 0 ,
V_242 , 0 ) ;
if ( V_240 == - 1 || V_240 & V_243 )
return;
V_240 |= V_243 ;
V_240 = F_14 ( V_16 , V_241 , 0 ,
V_244 , V_240 ) ;
if ( V_240 == - 1 )
return;
}
static void F_97 ( struct V_36 * V_16 )
{
unsigned int V_240 ;
V_240 = F_14 ( V_16 , V_241 , 0 ,
V_242 , 0 ) ;
if ( V_240 == - 1 || V_240 & V_245 )
return;
V_240 |= V_245 ;
V_240 = F_14 ( V_16 , V_241 , 0 ,
V_244 , V_240 ) ;
if ( V_240 == - 1 )
return;
}
static int F_98 ( struct V_36 * V_16 ,
struct V_204 * * V_246 ,
struct V_2 * V_3 , int V_247 )
{
struct V_204 * V_248 ;
struct V_4 * V_5 ;
char V_128 [ V_185 ] , V_249 [ V_185 ] ;
int V_43 = 0 ;
T_5 V_115 , V_250 ;
unsigned int V_251 = 384000 , V_252 = 8000 ;
T_3 V_41 ;
int V_63 ;
V_248 = F_76 ( & V_16 -> V_17 ,
( sizeof( * V_248 ) * V_247 ) ,
V_129 ) ;
if ( ! V_248 )
return - V_130 ;
F_2 (cvt, &hdmi->cvt_list, head) {
V_63 = F_55 ( V_16 , V_5 -> V_21 ,
& V_115 , & V_41 , & V_250 ) ;
if ( V_63 )
return V_63 ;
sprintf ( V_249 , L_23 , V_43 + 1 ) ;
V_248 [ V_43 ] . V_128 = F_58 ( & V_16 -> V_17 ,
V_249 , V_129 ) ;
if ( ! V_248 [ V_43 ] . V_128 )
return - V_130 ;
snprintf ( V_128 , sizeof( V_128 ) , L_24 , V_43 + 1 ) ;
V_248 [ V_43 ] . V_211 . V_212 =
F_58 ( & V_16 -> V_17 , V_128 , V_129 ) ;
if ( ! V_248 [ V_43 ] . V_211 . V_212 )
return - V_130 ;
V_248 [ V_43 ] . V_211 . V_41 = V_41 ;
V_248 [ V_43 ] . V_211 . V_115 = V_115 ;
V_248 [ V_43 ] . V_211 . V_251 = V_251 ;
V_248 [ V_43 ] . V_211 . V_252 = V_252 ;
V_248 [ V_43 ] . V_211 . V_113 = 2 ;
V_248 [ V_43 ] . V_211 . V_114 = 2 ;
V_248 [ V_43 ] . V_71 = & V_253 ;
V_43 ++ ;
}
* V_246 = V_248 ;
return 0 ;
}
static int F_99 ( struct V_10 * V_11 ,
struct V_204 * * V_246 , int * V_247 )
{
T_1 V_21 ;
int V_43 , V_254 ;
struct V_36 * V_16 = & V_11 -> V_16 ;
struct V_2 * V_3 = V_11 -> V_61 ;
int V_63 ;
F_96 ( V_16 ) ;
F_97 ( V_16 ) ;
V_254 = F_100 ( V_16 , V_16 -> V_255 , & V_21 ) ;
if ( ! V_21 || V_254 <= 0 ) {
F_44 ( & V_16 -> V_17 , L_25 ) ;
return - V_104 ;
}
V_16 -> V_254 = V_254 ;
V_16 -> V_256 = V_21 ;
for ( V_43 = 0 ; V_43 < V_16 -> V_254 ; V_43 ++ , V_21 ++ ) {
unsigned int V_22 ;
unsigned int type ;
V_22 = F_10 ( V_16 , V_21 ) ;
type = F_11 ( V_22 ) ;
if ( ! ( V_22 & V_24 ) )
continue;
switch ( type ) {
case V_257 :
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
V_16 -> V_258 = V_21 ;
if ( ! V_3 -> V_218 || ! V_3 -> V_189 )
return - V_31 ;
V_63 = F_98 ( V_16 , V_246 , V_3 , V_3 -> V_189 ) ;
if ( V_63 ) {
F_35 ( & V_16 -> V_17 , L_26 ,
V_63 ) ;
return V_63 ;
}
* V_247 = V_3 -> V_189 ;
return F_84 ( V_11 ) ;
}
static void F_101 ( void * V_259 , int V_8 , int V_260 )
{
struct V_10 * V_11 = V_259 ;
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_58 * V_12 = NULL ;
struct V_7 * V_261 = NULL ;
struct V_262 * V_263 = V_11 -> V_264 ;
int V_43 ;
T_1 V_48 = V_8 + 0x04 ;
F_6 ( & V_11 -> V_16 . V_17 , L_27 , V_93 ,
V_48 , V_260 ) ;
if ( F_102 ( V_263 -> V_206 . V_219 -> V_265 ) !=
V_266 )
return;
if ( F_103 ( & V_11 -> V_16 . V_267 ) )
return;
F_2 (pin, &hdmi->pin_list, head) {
if ( V_12 -> V_21 != V_48 )
continue;
if ( V_260 == - 1 ) {
V_12 -> V_30 = false ;
V_261 = & V_12 -> V_213 [ 0 ] ;
} else {
for ( V_43 = 0 ; V_43 < V_12 -> V_29 ; V_43 ++ ) {
V_12 -> V_30 = true ;
if ( V_12 -> V_213 [ V_43 ] . V_32 == V_260 ) {
V_261 = & V_12 -> V_213 [ V_43 ] ;
break;
}
}
}
if ( V_261 )
F_89 ( V_12 , V_261 ) ;
}
}
static struct V_268 * F_104 ( struct V_269 * V_219 ,
int V_35 )
{
struct V_270 * V_271 ;
F_2 (rtd, &card->rtd_list, list) {
if ( V_271 -> V_6 && ( V_271 -> V_6 -> V_35 == V_35 ) )
return V_271 -> V_6 ;
}
return NULL ;
}
static int F_105 ( struct V_269 * V_219 ,
struct V_10 * V_11 )
{
struct V_58 * V_12 ;
struct V_123 * V_150 ;
char V_184 [ V_185 ] , V_272 [ V_185 ] ;
char * V_128 ;
int V_43 = 0 , V_203 ;
struct V_262 * V_263 = V_11 -> V_264 ;
struct V_2 * V_3 = V_11 -> V_61 ;
V_150 = F_106 ( V_263 -> V_17 , V_3 -> V_29 ,
sizeof( * V_150 ) , V_129 ) ;
if ( ! V_150 )
return - V_130 ;
F_2 (pin, &hdmi->pin_list, head) {
for ( V_203 = 0 ; V_203 < V_12 -> V_29 ; V_203 ++ ) {
snprintf ( V_272 , sizeof( V_272 ) , L_28 ,
V_12 -> V_21 , V_12 -> V_213 [ V_203 ] . V_32 ) ;
V_128 = F_58 ( V_263 -> V_17 , V_272 , V_129 ) ;
if ( ! V_128 )
return - V_130 ;
snprintf ( V_184 , sizeof( V_184 ) , L_29 , V_272 ) ;
V_150 [ V_43 ] . V_128 = F_58 ( V_263 -> V_17 , V_184 ,
V_129 ) ;
if ( ! V_150 [ V_43 ] . V_128 )
return - V_130 ;
V_150 [ V_43 ] . V_172 = ( unsigned long ) V_128 ;
V_150 [ V_43 ] . V_190 = V_191 ;
V_150 [ V_43 ] . V_192 = 0 ;
V_150 [ V_43 ] . V_67 = V_273 ;
V_150 [ V_43 ] . V_194 = V_274 ;
V_150 [ V_43 ] . V_195 = V_275 ;
V_43 ++ ;
}
}
return F_107 ( V_219 , V_150 , V_43 ) ;
}
int F_108 ( struct V_262 * V_263 ,
struct V_173 * V_13 )
{
struct V_10 * V_11 = F_109 ( V_263 ) ;
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_58 * V_12 ;
struct V_117 * V_200 ;
struct V_137 * V_138 ;
char V_276 [ V_185 ] ;
int V_43 = 0 , V_203 , V_63 ;
V_200 = F_106 ( V_13 -> V_17 , V_3 -> V_29 ,
sizeof( * V_200 ) , V_129 ) ;
if ( ! V_200 )
return - V_130 ;
V_138 = F_106 ( V_13 -> V_17 , V_3 -> V_29 ,
sizeof( * V_138 ) , V_129 ) ;
if ( ! V_138 )
return - V_130 ;
F_2 (pin, &hdmi->pin_list, head) {
for ( V_203 = 0 ; V_203 < V_12 -> V_29 ; V_203 ++ ) {
snprintf ( V_276 , sizeof( V_276 ) , L_28 ,
V_12 -> V_21 , V_12 -> V_213 [ V_203 ] . V_32 ) ;
V_63 = F_56 ( V_13 -> V_17 , & V_200 [ V_43 ] ,
V_277 , NULL ,
V_276 , NULL , NULL , 0 , NULL , 0 ) ;
if ( V_63 < 0 )
return V_63 ;
V_12 -> V_213 [ V_203 ] . V_14 = V_200 [ V_43 ] . V_128 ;
V_12 -> V_213 [ V_203 ] . V_13 = V_13 ;
F_59 ( & V_138 [ V_43 ] , V_12 -> V_213 [ V_203 ] . V_14 ,
NULL , V_12 -> V_213 [ V_203 ] . V_215 , NULL ) ;
V_43 ++ ;
}
}
V_63 = F_81 ( V_13 , V_200 , V_3 -> V_29 ) ;
if ( V_63 < 0 )
return V_63 ;
V_63 = F_82 ( V_13 , V_138 , V_3 -> V_29 ) ;
if ( V_63 < 0 )
return V_63 ;
V_63 = F_83 ( V_13 -> V_219 ) ;
if ( V_63 < 0 )
return V_63 ;
V_63 = F_105 ( V_13 -> V_219 , V_11 ) ;
if ( V_63 < 0 )
return V_63 ;
F_2 (pin, &hdmi->pin_list, head) {
for ( V_203 = 0 ; V_203 < V_12 -> V_29 ; V_203 ++ )
F_5 ( V_12 -> V_213 [ V_203 ] . V_13 ,
V_12 -> V_213 [ V_203 ] . V_14 ) ;
}
return 0 ;
}
int F_110 ( struct V_85 * V_86 , int V_35 ,
struct V_278 * V_19 )
{
struct V_262 * V_263 = V_86 -> V_263 ;
struct V_10 * V_11 = F_109 ( V_263 ) ;
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_1 * V_6 ;
struct V_268 * V_268 ;
int V_111 ;
V_6 = F_86 ( sizeof( * V_6 ) , V_129 ) ;
if ( ! V_6 )
return - V_130 ;
V_6 -> V_18 = V_35 ;
V_6 -> V_5 = V_3 -> V_92 [ V_86 -> V_32 ] . V_5 ;
V_6 -> V_15 = 0 ;
V_6 -> V_19 = V_19 ;
F_111 ( & V_6 -> V_109 ) ;
F_112 ( & V_6 -> V_108 ) ;
V_268 = F_104 ( V_86 -> V_206 -> V_219 , V_35 ) ;
if ( V_268 ) {
V_111 = F_113 ( V_268 , V_35 , & V_3 -> V_70 ) ;
if ( V_111 < 0 ) {
F_35 ( & V_11 -> V_16 . V_17 ,
L_30 ,
V_111 , V_35 ) ;
F_114 ( V_6 ) ;
return V_111 ;
}
}
F_74 ( & V_6 -> V_180 , & V_3 -> V_279 ) ;
return 0 ;
}
static void F_115 ( struct V_10 * V_11 ,
struct V_2 * V_3 , bool V_280 )
{
int V_43 ;
struct V_58 * V_12 ;
F_2 (pin, &hdmi->pin_list, head) {
if ( V_280 ) {
if ( F_9 ( V_11 , V_12 -> V_21 ) == 0 )
V_12 -> V_30 = false ;
else
V_12 -> V_30 = true ;
}
for ( V_43 = 0 ; V_43 < V_12 -> V_29 ; V_43 ++ ) {
if ( ! V_12 -> V_30 && V_43 > 0 )
continue;
F_89 ( V_12 , & V_12 -> V_213 [ V_43 ] ) ;
}
}
}
static int F_116 ( struct V_262 * V_263 )
{
struct V_10 * V_11 = F_109 ( V_263 ) ;
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_173 * V_13 =
F_117 ( & V_263 -> V_206 ) ;
struct V_281 * V_282 = NULL ;
int V_63 ;
V_11 -> V_264 = V_263 ;
V_282 = F_118 ( V_11 -> V_283 , F_119 ( & V_11 -> V_16 . V_17 ) ) ;
if ( ! V_282 ) {
F_35 ( & V_11 -> V_16 . V_17 , L_31 ) ;
return - V_31 ;
}
F_120 ( V_11 -> V_283 , V_282 ) ;
V_63 = F_80 ( V_13 ) ;
if ( V_63 < 0 )
return V_63 ;
V_284 . V_285 = V_11 ;
V_63 = F_121 ( & V_284 ) ;
if ( V_63 < 0 ) {
F_35 ( & V_11 -> V_16 . V_17 , L_32 ,
V_63 ) ;
return V_63 ;
}
F_115 ( V_11 , V_3 , true ) ;
V_11 -> V_219 = V_13 -> V_219 -> V_265 ;
F_122 ( & V_11 -> V_16 . V_17 ) ;
F_123 ( & V_11 -> V_16 . V_17 ) ;
F_124 ( & V_11 -> V_16 . V_17 ) ;
return 0 ;
}
static int F_125 ( struct V_262 * V_263 )
{
struct V_10 * V_11 = F_109 ( V_263 ) ;
F_126 ( & V_11 -> V_16 . V_17 ) ;
return 0 ;
}
static int F_127 ( struct V_35 * V_17 )
{
struct V_10 * V_11 = F_18 ( V_17 ) ;
struct V_36 * V_16 = & V_11 -> V_16 ;
F_128 ( & V_11 -> V_16 . V_17 ) ;
F_14 ( V_16 , V_16 -> V_255 , 0 , V_147 ,
V_158 ) ;
return 0 ;
}
static void F_129 ( struct V_35 * V_17 )
{
struct V_10 * V_11 = F_18 ( V_17 ) ;
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_36 * V_16 = & V_11 -> V_16 ;
F_14 ( V_16 , V_16 -> V_255 , 0 , V_147 ,
V_152 ) ;
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
unsigned char * V_70 , int V_286 )
{
struct V_10 * V_11 = F_20 ( V_16 ) ;
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_1 * V_6 = F_17 ( V_3 , V_34 ) ;
struct V_7 * V_8 ;
if ( F_47 ( & V_6 -> V_108 ) )
return;
F_48 ( & V_6 -> V_109 ) ;
V_6 -> V_69 = true ;
memcpy ( V_6 -> V_70 , V_70 , F_132 ( V_6 -> V_70 ) ) ;
F_2 (port, &pcm->port_list, head)
if ( V_286 )
F_28 ( V_11 , V_6 , V_8 ) ;
F_49 ( & V_6 -> V_109 ) ;
}
static bool F_134 ( struct V_36 * V_16 , int V_34 )
{
struct V_10 * V_11 = F_20 ( V_16 ) ;
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_1 * V_6 = F_17 ( V_3 , V_34 ) ;
if ( F_47 ( & V_6 -> V_108 ) )
return false ;
return true ;
}
static int F_135 ( struct V_36 * V_16 , int V_34 )
{
struct V_10 * V_11 = F_20 ( V_16 ) ;
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_1 * V_6 = F_17 ( V_3 , V_34 ) ;
struct V_7 * V_8 ;
if ( F_47 ( & V_6 -> V_108 ) )
return 0 ;
V_8 = F_136 ( & V_6 -> V_108 , struct V_7 , V_180 ) ;
if ( ! V_8 )
return 0 ;
if ( ! V_8 || ! V_8 -> V_40 . V_102 )
return 0 ;
return V_8 -> V_40 . V_67 . V_68 ;
}
static int F_137 ( struct V_10 * V_11 )
{
struct V_36 * V_263 = & V_11 -> V_16 ;
struct V_2 * V_287 ;
struct V_204 * V_248 = NULL ;
struct V_281 * V_282 = NULL ;
int V_247 = 0 ;
int V_63 = 0 ;
V_282 = F_118 ( V_11 -> V_283 , F_119 ( & V_11 -> V_16 . V_17 ) ) ;
if ( ! V_282 ) {
F_35 ( & V_11 -> V_16 . V_17 , L_31 ) ;
return - V_31 ;
}
F_120 ( V_11 -> V_283 , V_282 ) ;
V_287 = F_76 ( & V_263 -> V_17 , sizeof( * V_287 ) , V_129 ) ;
if ( V_287 == NULL )
return - V_130 ;
V_11 -> V_61 = V_287 ;
F_138 ( V_263 , & V_287 -> V_70 ) ;
V_287 -> V_70 . V_71 . V_288 = F_131 ;
V_287 -> V_70 . V_71 . V_289 = F_133 ;
V_287 -> V_70 . V_71 . V_290 = F_134 ;
V_287 -> V_70 . V_71 . V_291 = F_135 ;
F_139 ( & V_263 -> V_17 , V_11 ) ;
F_112 ( & V_287 -> V_209 ) ;
F_112 ( & V_287 -> V_208 ) ;
F_112 ( & V_287 -> V_279 ) ;
F_111 ( & V_287 -> V_179 ) ;
V_63 = F_140 ( V_11 -> V_16 . V_292 , true ) ;
if ( V_63 < 0 ) {
F_35 ( & V_11 -> V_16 . V_17 ,
L_33 ,
V_63 ) ;
return V_63 ;
}
V_63 = F_99 ( V_11 , & V_248 , & V_247 ) ;
if ( V_63 < 0 ) {
F_35 ( & V_263 -> V_17 ,
L_34 , V_63 ) ;
return V_63 ;
}
V_63 = F_141 ( & V_263 -> V_17 , & V_293 ,
V_248 , V_247 ) ;
F_142 ( V_11 -> V_283 , V_282 ) ;
return V_63 ;
}
static int F_143 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = V_11 -> V_61 ;
struct V_58 * V_12 , * V_294 ;
struct V_4 * V_5 , * V_295 ;
struct V_1 * V_6 , * V_296 ;
struct V_7 * V_8 , * V_297 ;
int V_43 ;
F_144 ( & V_11 -> V_16 . V_17 ) ;
F_72 (pcm, pcm_next, &hdmi->pcm_list, head) {
V_6 -> V_5 = NULL ;
if ( F_47 ( & V_6 -> V_108 ) )
continue;
F_72 (port, port_next,
&pcm->port_list, head)
F_73 ( & V_8 -> V_180 ) ;
F_73 ( & V_6 -> V_180 ) ;
F_114 ( V_6 ) ;
}
F_72 (cvt, cvt_next, &hdmi->cvt_list, head) {
F_73 ( & V_5 -> V_180 ) ;
F_114 ( V_5 -> V_128 ) ;
F_114 ( V_5 ) ;
}
F_72 (pin, pin_next, &hdmi->pin_list, head) {
for ( V_43 = 0 ; V_43 < V_12 -> V_29 ; V_43 ++ )
V_12 -> V_213 [ V_43 ] . V_12 = NULL ;
F_114 ( V_12 -> V_213 ) ;
F_73 ( & V_12 -> V_180 ) ;
F_114 ( V_12 ) ;
}
return 0 ;
}
static int F_145 ( struct V_35 * V_17 )
{
struct V_10 * V_11 = F_18 ( V_17 ) ;
struct V_36 * V_16 = & V_11 -> V_16 ;
struct V_298 * V_292 = V_16 -> V_292 ;
struct V_299 * V_283 = F_146 ( V_292 ) ;
struct V_281 * V_282 = NULL ;
int V_111 ;
F_6 ( V_17 , L_35 , V_93 ) ;
if ( ! V_292 )
return 0 ;
F_14 ( V_16 , V_16 -> V_255 , 0 , V_147 ,
V_158 ) ;
V_111 = F_140 ( V_292 , false ) ;
if ( V_111 < 0 ) {
F_35 ( V_292 -> V_17 , L_36 ) ;
return V_111 ;
}
V_282 = F_118 ( V_283 , F_119 ( V_17 ) ) ;
if ( ! V_282 ) {
F_35 ( V_17 , L_31 ) ;
return - V_31 ;
}
F_142 ( V_283 , V_282 ) ;
return 0 ;
}
static int F_147 ( struct V_35 * V_17 )
{
struct V_10 * V_11 = F_18 ( V_17 ) ;
struct V_36 * V_16 = & V_11 -> V_16 ;
struct V_298 * V_292 = V_16 -> V_292 ;
struct V_299 * V_283 = F_146 ( V_292 ) ;
struct V_281 * V_282 = NULL ;
int V_111 ;
F_6 ( V_17 , L_35 , V_93 ) ;
if ( ! V_292 )
return 0 ;
V_282 = F_118 ( V_283 , F_119 ( V_17 ) ) ;
if ( ! V_282 ) {
F_35 ( V_17 , L_31 ) ;
return - V_31 ;
}
F_120 ( V_283 , V_282 ) ;
V_111 = F_140 ( V_292 , true ) ;
if ( V_111 < 0 ) {
F_35 ( V_292 -> V_17 , L_36 ) ;
return V_111 ;
}
F_96 ( & V_11 -> V_16 ) ;
F_97 ( & V_11 -> V_16 ) ;
F_14 ( V_16 , V_16 -> V_255 , 0 , V_147 ,
V_152 ) ;
return 0 ;
}
static int T_6 F_148 ( void )
{
return F_149 ( & V_300 ) ;
}
static void T_7 F_150 ( void )
{
F_151 ( & V_300 ) ;
}

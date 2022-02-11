static void *
F_1 ( struct V_1 * V_2 , const char * V_3 ,
T_1 V_4 )
{
const struct V_5 * V_6 ;
void * V_7 ;
int V_8 ;
V_8 = F_2 ( V_2 -> V_9 , V_3 , & V_6 ) ;
if ( V_8 )
return F_3 ( V_8 ) ;
if ( V_6 -> V_10 < V_4 ) {
F_4 ( V_2 , L_1 ,
V_3 , V_4 ) ;
F_5 ( V_6 ) ;
return F_3 ( - V_11 ) ;
}
V_7 = F_6 ( V_6 -> V_12 , V_6 -> V_10 , V_13 ) ;
F_5 ( V_6 ) ;
if ( ! V_7 )
return F_3 ( - V_14 ) ;
return V_7 ;
}
static void *
F_7 ( const struct V_5 * V_15 , const struct V_5 * V_16 ,
const struct V_5 * V_12 , struct V_17 * V_18 )
{
struct V_19 * V_20 = ( void * ) V_15 -> V_12 ;
struct V_21 * V_22 = ( void * ) V_15 -> V_12 + V_20 -> V_23 ;
void * V_24 = ( void * ) V_15 -> V_12 + V_20 -> V_25 ;
T_2 V_26 = 0 ;
void * V_27 ;
V_18 -> V_28 = V_26 ;
V_18 -> V_29 = F_8 ( V_22 -> V_30 , sizeof( T_2 ) ) ;
V_18 -> V_31 = V_22 -> V_32 * 256 ;
V_18 -> V_33 = V_22 -> V_32 * 256 ;
V_26 = F_8 ( V_26 + V_18 -> V_29 , V_34 ) ;
V_18 -> V_35 = V_26 ;
V_18 -> V_36 = F_8 ( V_16 -> V_10 , V_34 ) +
F_8 ( V_12 -> V_10 , V_34 ) ;
V_18 -> V_37 = 0 ;
V_18 -> V_38 = 0 ;
V_18 -> V_39 = 0 ;
V_18 -> V_40 = 0 ;
V_18 -> V_41 = F_8 ( V_16 -> V_10 , V_34 ) ;
V_26 = F_8 ( V_26 + V_18 -> V_41 , V_34 ) ;
V_18 -> V_42 = V_26 - V_18 -> V_35 ;
V_18 -> V_43 = F_8 ( V_12 -> V_10 , V_34 ) ;
V_18 -> V_44 = F_8 ( V_22 -> V_30 , V_34 ) +
V_18 -> V_36 ;
V_27 = F_9 ( V_18 -> V_44 , V_13 ) ;
if ( ! V_27 )
return F_3 ( - V_14 ) ;
memcpy ( V_27 + V_18 -> V_28 , V_24 ,
V_22 -> V_30 ) ;
memcpy ( V_27 + V_18 -> V_35 , V_16 -> V_12 , V_16 -> V_10 ) ;
memcpy ( V_27 + V_18 -> V_35 + V_18 -> V_42 ,
V_12 -> V_12 , V_12 -> V_10 ) ;
return V_27 ;
}
static int
F_10 ( struct V_1 * V_2 ,
struct V_45 * V_46 , const char * V_47 ,
const T_2 V_48 )
{
const struct V_5 * V_15 , * V_16 , * V_12 ;
struct V_49 * V_50 ;
char V_51 [ 64 ] ;
int V_8 ;
V_46 -> V_52 = NULL ;
snprintf ( V_51 , sizeof( V_51 ) , L_2 , V_47 ) ;
V_8 = F_2 ( V_2 -> V_9 , V_51 , & V_15 ) ;
if ( V_8 )
goto error;
snprintf ( V_51 , sizeof( V_51 ) , L_3 , V_47 ) ;
V_8 = F_2 ( V_2 -> V_9 , V_51 , & V_16 ) ;
if ( V_8 )
goto V_53;
snprintf ( V_51 , sizeof( V_51 ) , L_4 , V_47 ) ;
V_8 = F_2 ( V_2 -> V_9 , V_51 , & V_12 ) ;
if ( V_8 )
goto V_54;
V_46 -> V_55 = F_7 ( V_15 , V_16 , V_12 ,
& V_46 -> V_56 ) ;
if ( F_11 ( V_46 -> V_55 ) ) {
V_8 = F_12 ( V_46 -> V_55 ) ;
goto V_57;
}
V_46 -> V_58 = V_46 -> V_56 . V_44 ;
snprintf ( V_51 , sizeof( V_51 ) , L_5 , V_47 ) ;
V_50 = F_1 ( V_2 , V_51 , sizeof( * V_50 ) ) ;
if ( F_11 ( V_50 ) ) {
V_8 = F_12 ( V_50 ) ;
goto V_59;
}
V_50 -> V_48 = V_48 ;
memcpy ( & V_46 -> V_60 . V_61 , V_50 , sizeof( * V_50 ) ) ;
V_46 -> V_48 = V_50 -> V_48 ;
F_13 ( V_50 ) ;
goto V_57;
V_59:
F_13 ( V_46 -> V_55 ) ;
V_57:
F_5 ( V_12 ) ;
V_54:
F_5 ( V_16 ) ;
V_53:
F_5 ( V_15 ) ;
error:
return V_8 ;
}
static int
F_14 ( struct V_1 * V_2 , struct V_45 * V_46 )
{
return F_10 ( V_2 , V_46 , L_6 ,
V_62 ) ;
}
static int
F_15 ( struct V_1 * V_2 , struct V_45 * V_46 )
{
return F_10 ( V_2 , V_46 , L_7 ,
V_63 ) ;
}
static struct V_45 *
F_16 ( struct V_1 * V_2 , T_3 V_64 )
{
struct V_45 * V_46 ;
int V_8 ;
V_46 = F_9 ( sizeof( * V_46 ) , V_13 ) ;
if ( ! V_46 )
return F_3 ( - V_14 ) ;
V_8 = V_64 ( V_2 , V_46 ) ;
if ( V_8 ) {
F_13 ( V_46 ) ;
return F_3 ( V_8 ) ;
}
return V_46 ;
}
static void
F_17 ( struct V_45 * V_46 , T_4 V_65 ,
struct V_66 * V_18 )
{
struct V_17 * V_67 = & V_46 -> V_56 ;
T_4 V_68 ;
V_68 = V_65 + V_46 -> V_60 . V_69 +
V_67 -> V_35 ;
memset ( V_18 , 0 , sizeof( * V_18 ) ) ;
V_18 -> V_70 = V_71 ;
V_18 -> V_72 . V_73 = F_18 (
( V_68 + V_67 -> V_40 ) ) ;
V_18 -> V_72 . V_74 = F_19 (
( V_68 + V_67 -> V_40 ) ) ;
V_18 -> V_75 = V_67 -> V_41 ;
V_18 -> V_76 . V_73 = F_18 (
( V_68 + V_67 -> V_42 ) ) ;
V_18 -> V_76 . V_74 = F_19 (
( V_68 + V_67 -> V_42 ) ) ;
V_18 -> V_77 = V_67 -> V_43 ;
V_18 -> V_78 = V_67 -> V_38 ;
}
static T_2
F_20 ( struct V_79 * V_80 , struct V_45 * V_46 ,
T_2 V_81 )
{
struct V_82 * V_83 = & V_46 -> V_84 ;
struct V_85 * V_86 = & V_46 -> V_60 ;
struct V_17 * V_18 = & V_46 -> V_56 ;
if ( V_46 -> V_52 ) {
F_21 ( & V_80 -> V_87 . V_2 ,
L_8 ) ;
return V_81 ;
}
V_83 -> V_48 = V_46 -> V_48 ;
V_83 -> V_88 = V_80 -> V_87 . V_89 -> V_90 ;
V_83 -> V_91 = V_92 ;
V_81 = F_8 ( V_81 , V_93 ) ;
V_83 -> V_94 = V_81 ;
V_81 += sizeof( struct V_85 ) ;
V_81 = F_8 ( V_81 , V_95 ) ;
V_86 -> V_69 = V_81 ;
V_81 += V_46 -> V_58 ;
V_86 -> V_96 = F_8 ( V_18 -> V_29 ,
V_97 ) ;
V_86 -> V_58 = F_8 ( V_18 -> V_42 ,
V_97 ) + V_86 -> V_96 ;
V_86 -> V_77 = F_8 ( V_18 -> V_36 , V_97 ) +
V_86 -> V_96 - V_86 -> V_58 ;
V_86 -> V_98 = V_18 -> V_31 ;
V_86 -> V_99 = V_18 -> V_35 +
V_18 -> V_40 ;
V_86 -> V_100 = V_18 -> V_41 ;
V_86 -> V_101 = V_18 -> V_35 +
V_18 -> V_42 ;
V_86 -> V_102 = V_18 -> V_43 ;
V_86 -> V_103 = 0 ;
if ( V_46 -> V_48 == V_80 -> V_87 . V_89 -> V_90 )
V_86 -> V_103 = V_104 ;
if ( V_46 -> V_48 == V_63 )
V_86 -> V_103 |= V_105 ;
V_86 -> V_106 = F_8 ( sizeof( struct V_66 ) ,
V_107 ) ;
V_81 = F_8 ( V_81 , V_108 ) ;
V_86 -> V_109 = V_81 ;
V_81 += V_86 -> V_106 ;
return V_81 ;
}
static void
F_22 ( struct V_110 * V_111 )
{
memset ( V_111 , 0 , sizeof( * V_111 ) ) ;
F_23 ( & V_111 -> V_112 ) ;
}
static void
F_24 ( struct V_110 * V_111 )
{
struct V_45 * V_46 , * V_113 ;
F_25 (img, t, &mgr->img_list, node) {
F_13 ( V_46 -> V_55 ) ;
F_13 ( V_46 -> V_52 ) ;
F_13 ( V_46 ) ;
}
}
static void
F_26 ( struct V_110 * V_111 , struct V_45 * V_46 )
{
V_111 -> V_114 ++ ;
F_27 ( & V_46 -> V_115 , & V_111 -> V_112 ) ;
}
static void
F_28 ( struct V_79 * V_80 , struct V_110 * V_111 )
{
struct V_45 * V_46 ;
T_2 V_81 ;
V_81 = sizeof( struct V_82 ) * ( V_111 -> V_114 + 1 ) ;
F_29 (img, &mgr->img_list, node) {
V_81 = F_20 ( V_80 , V_46 , V_81 ) ;
}
V_111 -> V_116 = V_81 ;
}
static int
F_30 ( struct V_79 * V_80 , struct V_110 * V_111 ,
struct V_117 * V_118 )
{
struct V_45 * V_46 ;
T_2 V_26 = 0 ;
F_31 ( V_118 ) ;
F_29 (img, &mgr->img_list, node) {
F_32 ( V_118 , V_26 , & V_46 -> V_84 ,
sizeof( V_46 -> V_84 ) ) ;
F_32 ( V_118 , V_46 -> V_84 . V_94 ,
& V_46 -> V_60 , sizeof( V_46 -> V_60 ) ) ;
if ( ! V_46 -> V_52 ) {
T_5 V_18 [ V_80 -> V_89 -> V_119 ] ;
struct V_66 V_120 ;
F_17 ( V_46 , V_80 -> V_65 ,
& V_120 ) ;
V_80 -> V_89 -> V_121 ( & V_120 , & V_18 ) ;
F_32 ( V_118 ,
V_46 -> V_60 . V_109 ,
& V_18 , V_80 -> V_89 -> V_119 ) ;
}
F_32 ( V_118 , V_46 -> V_60 . V_69 ,
V_46 -> V_55 , V_46 -> V_58 ) ;
V_26 += sizeof( V_46 -> V_84 ) ;
}
F_33 ( V_118 , V_26 , V_122 ) ;
F_34 ( V_118 ) ;
return 0 ;
}
static int
F_35 ( struct V_79 * V_80 )
{
struct V_123 * V_124 = & V_80 -> V_87 ;
struct V_125 * V_9 = V_124 -> V_2 . V_9 ;
struct V_110 V_111 ;
int V_48 ;
int V_8 ;
F_22 ( & V_111 ) ;
F_36 (falcon_id, &gsb->base.func->managed_falcons,
NVKM_SECBOOT_FALCON_END) {
struct V_45 * V_46 ;
V_46 = F_16 ( & V_124 -> V_2 , V_126 [ V_48 ] ) ;
if ( F_11 ( V_46 ) ) {
V_8 = F_12 ( V_46 ) ;
goto V_127;
}
F_26 ( & V_111 , V_46 ) ;
}
F_28 ( V_80 , & V_111 ) ;
V_111 . V_116 = F_8 ( V_111 . V_116 , V_128 ) ;
V_8 = F_37 ( V_9 , V_111 . V_116 , V_128 , false , NULL ,
& V_80 -> V_129 ) ;
if ( V_8 )
goto V_127;
F_38 ( & V_124 -> V_2 , L_9 ,
V_111 . V_114 , V_111 . V_116 ) ;
if ( ! V_80 -> V_116 ) {
V_80 -> V_65 = V_80 -> V_129 -> V_130 ;
V_80 -> V_116 = V_80 -> V_129 -> V_10 ;
}
V_8 = F_30 ( V_80 , & V_111 , V_80 -> V_129 ) ;
if ( V_8 )
F_39 ( & V_80 -> V_129 ) ;
V_127:
F_24 ( & V_111 ) ;
return V_8 ;
}
static void
F_40 ( struct V_79 * V_80 , void * V_131 )
{
struct V_123 * V_124 = & V_80 -> V_87 ;
struct V_19 * V_132 = V_131 ;
struct V_133 * V_134 = V_131 + V_132 -> V_23 ;
void * V_135 = V_131 + V_132 -> V_25 ;
void * V_136 ;
T_2 V_137 ;
if ( ( F_41 ( V_124 -> V_2 . V_9 , V_124 -> V_87 + 0xc08 ) >> 20 ) & 0x1 ) {
V_136 = V_131 + V_134 -> V_138 ;
V_137 = V_134 -> V_139 ;
} else {
V_136 = V_131 + V_134 -> V_140 ;
V_137 = V_134 -> V_141 ;
}
memcpy ( V_135 + V_134 -> V_142 , V_136 + V_134 -> V_143 , V_137 ) ;
}
static void
F_42 ( void * V_131 ,
struct V_66 * V_22 )
{
struct V_19 * V_132 = V_131 ;
struct V_133 * V_134 = V_131 + V_132 -> V_23 ;
struct V_144 * V_145 = V_131 + V_134 -> V_146 ;
V_134 = V_131 + V_132 -> V_23 ;
V_145 = V_131 + V_134 -> V_146 ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
V_22 -> V_70 = V_147 ;
V_22 -> V_148 = V_145 -> V_148 ;
V_22 -> V_75 = V_145 -> V_75 ;
V_22 -> V_149 = V_145 -> V_150 [ 0 ] . V_149 ;
V_22 -> V_151 = V_145 -> V_150 [ 0 ] . V_151 ;
V_22 -> V_78 = 0 ;
V_22 -> V_72 . V_73 = 0 ;
V_22 -> V_76 . V_73 = V_145 -> V_76 ;
V_22 -> V_77 = V_145 -> V_77 ;
}
static int
F_43 ( struct V_79 * V_80 , const char * V_6 ,
struct V_117 * * V_7 ,
struct V_66 * V_22 , bool V_152 )
{
struct V_1 * V_2 = & V_80 -> V_87 . V_2 ;
void * V_131 ;
struct V_19 * V_132 ;
struct V_133 * V_134 ;
void * V_153 ;
struct V_144 * V_145 ;
struct V_154 * V_18 ;
int V_8 ;
V_131 = F_1 ( V_2 , V_6 , 0 ) ;
if ( F_11 ( V_131 ) )
return F_12 ( V_131 ) ;
V_132 = V_131 ;
F_40 ( V_80 , V_131 ) ;
V_153 = V_131 + V_132 -> V_25 ;
if ( V_152 ) {
V_134 = V_131 + V_132 -> V_23 ;
V_145 = V_131 + V_134 -> V_146 ;
V_18 = V_153 + V_145 -> V_76 ;
V_80 -> V_89 -> V_155 ( V_80 , V_18 ) ;
}
F_42 ( V_131 , V_22 ) ;
V_8 = F_37 ( V_2 -> V_9 , F_8 ( V_132 -> V_77 , 256 ) ,
0x1000 , false , NULL , V_7 ) ;
if ( V_8 )
goto V_127;
F_31 ( * V_7 ) ;
F_32 ( * V_7 , 0 , V_153 , V_132 -> V_77 ) ;
F_34 ( * V_7 ) ;
V_127:
F_13 ( V_131 ) ;
return V_8 ;
}
static int
F_44 ( struct V_79 * V_80 )
{
struct V_1 * V_2 = & V_80 -> V_87 . V_2 ;
V_80 -> V_156 = F_1 ( V_2 , L_10 , 0 ) ;
if ( F_11 ( V_80 -> V_156 ) ) {
int V_8 = F_12 ( V_80 -> V_156 ) ;
V_80 -> V_156 = NULL ;
return V_8 ;
}
return 0 ;
}
int
F_45 ( struct V_79 * V_80 )
{
int V_8 ;
if ( ! V_80 -> V_129 ) {
V_8 = F_35 ( V_80 ) ;
if ( V_8 )
return V_8 ;
}
if ( ! V_80 -> V_157 ) {
V_8 = F_43 ( V_80 , L_11 ,
& V_80 -> V_157 ,
& V_80 -> V_158 , true ) ;
if ( V_8 )
return V_8 ;
}
if ( ! V_80 -> V_156 ) {
V_8 = F_44 ( V_80 ) ;
if ( V_8 )
return V_8 ;
}
return 0 ;
}
static int
F_46 ( struct V_79 * V_80 )
{
int V_8 ;
V_8 = F_45 ( V_80 ) ;
if ( V_8 )
return V_8 ;
if ( ! V_80 -> V_159 ) {
V_8 = F_43 ( V_80 , L_12 ,
& V_80 -> V_159 ,
& V_80 -> V_160 , false ) ;
if ( V_8 )
return V_8 ;
}
return 0 ;
}
static int
F_47 ( struct V_79 * V_80 )
{
struct V_1 * V_2 = & V_80 -> V_87 . V_2 ;
int V_8 ;
if ( V_80 -> V_161 )
return 0 ;
V_8 = V_80 -> V_89 -> V_162 ( V_80 ) ;
if ( V_8 ) {
F_4 ( V_2 , L_13 ) ;
return V_8 ;
}
V_80 -> V_161 = true ;
return 0 ;
}
static void
F_48 ( struct V_79 * V_80 , void * V_12 , T_2 V_77 )
{
struct V_125 * V_9 = V_80 -> V_87 . V_2 . V_9 ;
struct V_19 * V_163 = V_80 -> V_156 ;
struct V_21 * V_164 = V_80 -> V_156 + V_163 -> V_23 ;
void * V_165 = V_80 -> V_156 + V_163 -> V_25 ;
void * V_166 = V_165 + V_164 -> V_167 ;
void * V_168 = V_165 + V_164 -> V_169 ;
T_2 V_30 = F_8 ( V_164 -> V_30 , 256 ) ;
const T_2 V_87 = V_80 -> V_87 . V_87 ;
T_2 V_170 ;
T_2 V_171 ;
int V_172 ;
F_49 ( V_9 , V_87 + 0x1c0 , ( 0x00000000 | ( 0x1 << 24 ) ) ) ;
for ( V_172 = 0 ; V_172 < V_164 -> V_77 / 4 ; V_172 ++ )
F_49 ( V_9 , V_87 + 0x1c4 , ( ( T_2 * ) V_168 ) [ V_172 ] ) ;
F_49 ( V_9 , V_87 + 0x1c0 ,
( V_164 -> V_173 | ( 0x1 << 24 ) ) ) ;
for ( V_172 = 0 ; V_172 < V_77 / 4 ; V_172 ++ )
F_49 ( V_9 , V_87 + 0x1c4 , ( ( T_2 * ) V_12 ) [ V_172 ] ) ;
V_170 = ( F_41 ( V_9 , V_87 + 0x108 ) & 0x1ff ) - ( V_30 >> 8 ) ;
V_171 = V_164 -> V_32 ;
F_49 ( V_9 , V_87 + 0x180 , ( ( V_170 & 0xff ) << 8 ) | ( 0x1 << 24 ) ) ;
for ( V_172 = 0 ; V_172 < V_30 / 4 ; V_172 ++ ) {
if ( ( V_172 & 0x3f ) == 0 ) {
F_49 ( V_9 , V_87 + 0x188 , V_171 & 0xffff ) ;
V_171 ++ ;
}
F_49 ( V_9 , V_87 + 0x184 , ( ( T_2 * ) V_166 ) [ V_172 ] ) ;
}
F_49 ( V_9 , V_87 + 0x188 , 0 ) ;
}
static int
F_50 ( struct V_79 * V_80 )
{
struct V_125 * V_9 = V_80 -> V_87 . V_2 . V_9 ;
struct V_19 * V_163 = V_80 -> V_156 ;
struct V_21 * V_164 = V_80 -> V_156 + V_163 -> V_23 ;
T_2 V_174 = V_164 -> V_32 << 8 ;
const T_2 V_87 = V_80 -> V_87 . V_87 ;
const T_2 V_175 = V_87 + 0xe00 ;
T_2 V_176 ;
int V_8 ;
V_8 = F_51 ( & V_80 -> V_87 ) ;
if ( V_8 )
return V_8 ;
F_49 ( V_9 , V_175 + 4 * ( V_71 ) , 0x4 ) ;
F_49 ( V_9 , V_175 + 4 * ( V_147 ) , 0x0 ) ;
F_49 ( V_9 , V_175 + 4 * ( V_177 ) , 0x4 ) ;
F_49 ( V_9 , V_175 + 4 * ( V_178 ) ,
0x4 | 0x1 ) ;
F_49 ( V_9 , V_175 + 4 * ( V_179 ) ,
0x4 | 0x2 ) ;
if ( F_52 ( V_80 -> V_180 -> V_181 ) == V_182 )
V_176 = 0x0 ;
else
V_176 = 0x3 ;
F_53 ( V_9 , V_87 + 0x048 , 0x1 , 0x1 ) ;
F_49 ( V_9 , V_87 + 0x480 ,
( ( V_80 -> V_180 -> V_130 >> 12 ) & 0xfffffff ) |
( V_176 << 28 ) | ( 1 << 30 ) ) ;
F_49 ( V_9 , V_87 + 0x104 , V_174 ) ;
return 0 ;
}
static int
F_54 ( struct V_79 * V_80 , struct V_117 * V_7 ,
struct V_66 * V_18 )
{
struct V_183 V_184 ;
T_4 V_185 ;
const T_2 V_119 = V_80 -> V_89 -> V_119 ;
T_5 V_22 [ V_119 ] ;
int V_8 ;
V_8 = F_55 ( V_7 , V_80 -> V_186 , V_187 , & V_184 ) ;
if ( V_8 )
return V_8 ;
V_185 = F_56 ( V_18 -> V_72 ) + V_184 . V_81 ;
V_18 -> V_72 . V_73 = F_18 ( V_185 ) ;
V_18 -> V_72 . V_74 = F_19 ( V_185 ) ;
V_185 = F_56 ( V_18 -> V_76 ) + V_184 . V_81 ;
V_18 -> V_76 . V_73 = F_18 ( V_185 ) ;
V_18 -> V_76 . V_74 = F_19 ( V_185 ) ;
V_80 -> V_89 -> V_121 ( V_18 , & V_22 ) ;
V_8 = F_50 ( V_80 ) ;
if ( V_8 )
goto V_188;
F_48 ( V_80 , & V_22 , V_119 ) ;
V_8 = F_57 ( & V_80 -> V_87 ) ;
if ( V_8 )
goto V_188;
V_188:
V_185 = F_56 ( V_18 -> V_72 ) - V_184 . V_81 ;
V_18 -> V_72 . V_73 = F_18 ( V_185 ) ;
V_18 -> V_72 . V_74 = F_19 ( V_185 ) ;
V_185 = F_56 ( V_18 -> V_76 ) - V_184 . V_81 ;
V_18 -> V_76 . V_73 = F_18 ( V_185 ) ;
V_18 -> V_76 . V_74 = F_19 ( V_185 ) ;
F_58 ( & V_184 ) ;
return V_8 ;
}
int
F_59 ( struct V_123 * V_124 , enum V_189 V_190 )
{
struct V_79 * V_80 = V_79 ( V_124 ) ;
int V_8 ;
V_8 = F_47 ( V_80 ) ;
if ( V_8 )
return V_8 ;
if ( V_190 != V_62 )
goto V_191;
if ( V_80 -> V_159 &&
V_80 -> V_192 [ V_62 ] != V_193 ) {
V_8 = F_54 ( V_80 , V_80 -> V_159 ,
& V_80 -> V_160 ) ;
if ( V_8 )
return V_8 ;
}
V_8 = F_54 ( V_80 , V_80 -> V_157 ,
& V_80 -> V_158 ) ;
if ( V_8 )
return V_8 ;
V_191:
V_80 -> V_192 [ V_190 ] = V_194 ;
return 0 ;
}
int
F_60 ( struct V_123 * V_124 , enum V_189 V_190 )
{
struct V_79 * V_80 = V_79 ( V_124 ) ;
int V_87 ;
switch ( V_190 ) {
case V_62 :
V_87 = 0x409000 ;
break;
case V_63 :
V_87 = 0x41a000 ;
break;
default:
F_4 ( & V_124 -> V_2 , L_14 ) ;
return - V_11 ;
}
F_49 ( V_124 -> V_2 . V_9 , V_87 + 0x130 , 0x00000002 ) ;
V_80 -> V_192 [ V_190 ] = V_195 ;
return 0 ;
}
int
F_61 ( struct V_123 * V_124 )
{
struct V_79 * V_80 = V_79 ( V_124 ) ;
struct V_125 * V_9 = V_124 -> V_2 . V_9 ;
struct V_196 * V_186 ;
const T_4 V_197 = 600 * 1024 ;
int V_8 ;
V_8 = F_37 ( V_9 , 0x1000 , 0 , true , NULL , & V_80 -> V_180 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_37 ( V_9 , 0x8000 , 0 , true , NULL , & V_80 -> V_198 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_62 ( V_9 , 0 , V_197 , 0 , NULL , & V_186 ) ;
if ( V_8 )
return V_8 ;
F_63 ( & V_186 -> V_199 [ V_200 ] ) ;
V_8 = F_64 ( V_186 , & V_80 -> V_186 , V_80 -> V_198 ) ;
F_64 ( NULL , & V_186 , NULL ) ;
if ( V_8 )
return V_8 ;
F_31 ( V_80 -> V_180 ) ;
F_33 ( V_80 -> V_180 , 0x200 , F_18 ( V_80 -> V_198 -> V_130 ) ) ;
F_33 ( V_80 -> V_180 , 0x204 , F_19 ( V_80 -> V_198 -> V_130 ) ) ;
F_33 ( V_80 -> V_180 , 0x208 , F_18 ( V_197 - 1 ) ) ;
F_33 ( V_80 -> V_180 , 0x20c , F_19 ( V_197 - 1 ) ) ;
F_34 ( V_80 -> V_180 ) ;
return 0 ;
}
static int
F_65 ( struct V_123 * V_124 , bool V_201 )
{
struct V_79 * V_80 = V_79 ( V_124 ) ;
int V_8 = 0 ;
int V_172 ;
if ( V_80 -> V_159 &&
V_80 -> V_192 [ V_62 ] != V_193 )
V_8 = F_54 ( V_80 , V_80 -> V_159 ,
& V_80 -> V_160 ) ;
for ( V_172 = 0 ; V_172 < V_202 ; V_172 ++ )
V_80 -> V_192 [ V_172 ] = V_193 ;
return V_8 ;
}
void *
F_66 ( struct V_123 * V_124 )
{
struct V_79 * V_80 = V_79 ( V_124 ) ;
F_39 ( & V_80 -> V_159 ) ;
F_13 ( V_80 -> V_156 ) ;
F_39 ( & V_80 -> V_157 ) ;
F_39 ( & V_80 -> V_129 ) ;
F_64 ( NULL , & V_80 -> V_186 , V_80 -> V_198 ) ;
F_39 ( & V_80 -> V_198 ) ;
F_39 ( & V_80 -> V_180 ) ;
return V_80 ;
}
static void
F_67 ( const struct V_66 * V_18 , void * V_8 )
{
memcpy ( V_8 , V_18 , sizeof( * V_18 ) ) ;
}
static void
F_68 ( struct V_79 * V_80 ,
struct V_154 * V_18 )
{
V_18 -> V_203 = V_80 -> V_129 -> V_130 ;
V_18 -> V_204 = V_80 -> V_129 -> V_10 ;
V_18 -> V_205 = 0 ;
V_18 -> V_206 = 1 ;
V_18 -> V_207 . V_208 = 1 ;
V_18 -> V_207 . V_209 [ 0 ] . V_210 = 1 ;
V_18 -> V_207 . V_209 [ 0 ] . V_211 = V_80 -> V_65 >> 8 ;
V_18 -> V_207 . V_209 [ 0 ] . V_212 =
( V_80 -> V_65 + V_80 -> V_116 ) >> 8 ;
}
int
F_69 ( struct V_125 * V_9 , int V_213 ,
struct V_123 * * V_214 )
{
int V_8 ;
struct V_79 * V_80 ;
V_80 = F_9 ( sizeof( * V_80 ) , V_13 ) ;
if ( ! V_80 ) {
V_214 = NULL ;
return - V_14 ;
}
* V_214 = & V_80 -> V_87 ;
V_8 = F_70 ( & V_79 , V_9 , V_213 , & V_80 -> V_87 ) ;
if ( V_8 )
return V_8 ;
V_80 -> V_89 = & V_215 ;
return 0 ;
}

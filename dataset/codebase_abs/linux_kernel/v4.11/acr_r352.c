static void
F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 , T_1 V_5 ,
void * V_6 )
{
struct V_7 * V_8 = V_7 ( V_4 ) ;
struct V_9 * V_10 = V_6 ;
const struct V_11 * V_12 = & V_4 -> V_13 ;
T_1 V_14 , V_15 , V_16 ;
V_14 = V_5 + V_8 -> V_17 . V_18 + V_12 -> V_19 ;
V_15 = ( V_14 + V_12 -> V_20 ) >> 8 ;
V_16 = ( V_14 + V_12 -> V_21 ) >> 8 ;
V_10 -> V_22 = V_23 ;
V_10 -> V_24 = F_2 ( V_15 ) ;
V_10 -> V_25 = F_3 ( V_15 ) ;
V_10 -> V_26 = V_12 -> V_20 ;
V_10 -> V_27 = V_12 -> V_28 ;
V_10 -> V_29 = V_12 -> V_30 ;
V_10 -> V_31 = F_2 ( V_16 ) ;
V_10 -> V_32 = F_3 ( V_16 ) ;
V_10 -> V_33 = V_12 -> V_34 ;
}
struct V_3 *
F_4 ( const struct V_35 * V_2 ,
enum V_36 V_37 )
{
const struct V_38 * V_39 = V_2 -> V_14 . V_39 ;
struct V_7 * V_8 ;
int V_40 ;
V_8 = F_5 ( sizeof( * V_8 ) , V_41 ) ;
if ( ! V_8 )
return F_6 ( - V_42 ) ;
V_8 -> V_14 . V_37 = V_37 ;
V_40 = V_2 -> V_43 -> V_44 [ V_37 ] -> F_7 ( V_39 , & V_8 -> V_14 ) ;
if ( V_40 ) {
F_8 ( V_8 -> V_14 . V_45 ) ;
F_8 ( V_8 -> V_14 . V_46 ) ;
F_8 ( V_8 ) ;
return F_6 ( V_40 ) ;
}
if ( V_8 -> V_14 . V_47 != sizeof( V_8 -> V_17 . V_48 ) ) {
F_9 ( V_39 , L_1 ,
V_49 [ V_37 ] ) ;
return F_6 ( - V_50 ) ;
}
memcpy ( & V_8 -> V_17 . V_48 , V_8 -> V_14 . V_46 , V_8 -> V_14 . V_47 ) ;
V_8 -> V_17 . V_48 . V_37 = V_37 ;
return & V_8 -> V_14 ;
}
static T_2
F_10 ( struct V_35 * V_2 ,
struct V_7 * V_8 , T_2 V_51 )
{
struct V_3 * V_4 = & V_8 -> V_14 ;
struct V_52 * V_53 = & V_8 -> V_54 ;
struct V_55 * V_56 = & V_8 -> V_17 ;
struct V_11 * V_10 = & V_4 -> V_13 ;
const struct V_57 * V_43 =
V_2 -> V_43 -> V_44 [ V_4 -> V_37 ] ;
V_53 -> V_37 = V_4 -> V_37 ;
V_53 -> V_58 = V_2 -> V_14 . V_59 ;
V_53 -> V_60 = V_61 ;
if ( V_2 -> V_62 & F_11 ( V_4 -> V_37 ) )
V_53 -> V_62 = 1 ;
V_51 = F_12 ( V_51 , V_63 ) ;
V_53 -> V_64 = V_51 ;
V_51 += sizeof( * V_56 ) ;
V_51 = F_12 ( V_51 , V_65 ) ;
V_56 -> V_18 = V_51 ;
V_51 += V_4 -> V_66 ;
V_56 -> V_67 = F_12 ( V_10 -> V_68 ,
V_69 ) ;
V_56 -> V_66 = F_12 ( V_10 -> V_21 ,
V_69 ) + V_56 -> V_67 ;
V_56 -> V_33 = F_12 ( V_10 -> V_70 , V_69 ) +
V_56 -> V_67 - V_56 -> V_66 ;
V_56 -> V_71 = V_10 -> V_72 ;
V_56 -> V_73 = V_10 -> V_19 +
V_10 -> V_20 ;
V_56 -> V_74 = V_10 -> V_28 ;
V_56 -> V_75 = V_10 -> V_19 +
V_10 -> V_21 ;
V_56 -> V_76 = V_10 -> V_34 ;
V_56 -> V_77 = V_43 -> V_78 ;
if ( V_4 -> V_37 == V_2 -> V_14 . V_59 )
V_56 -> V_77 |= V_79 ;
V_56 -> V_80 = F_12 ( V_43 -> V_81 , V_82 ) ;
V_51 = F_12 ( V_51 , V_83 ) ;
V_56 -> V_84 = V_51 ;
V_51 += V_56 -> V_80 ;
return V_51 ;
}
int
F_13 ( struct V_35 * V_2 , struct V_85 * V_86 )
{
struct V_7 * V_8 ;
struct V_85 * V_87 ;
T_2 V_88 = 0 ;
T_2 V_51 ;
F_14 (l, imgs)
V_88 ++ ;
V_51 = sizeof( V_8 -> V_54 ) * ( V_88 + 1 ) ;
F_15 (img, imgs, base.node) {
V_51 = F_10 ( V_2 , V_8 , V_51 ) ;
}
return V_51 ;
}
int
F_16 ( struct V_35 * V_2 , struct V_85 * V_86 ,
struct V_89 * V_90 , T_2 V_5 )
{
struct V_3 * V_4 ;
T_2 V_91 = 0 ;
F_17 ( V_90 ) ;
F_15 (_img, imgs, node) {
struct V_7 * V_8 = V_7 ( V_4 ) ;
const struct V_57 * V_44 =
V_2 -> V_43 -> V_44 [ V_4 -> V_37 ] ;
T_3 V_92 [ V_44 -> V_81 ] ;
F_18 ( V_90 , V_91 , & V_8 -> V_54 ,
sizeof( V_8 -> V_54 ) ) ;
F_18 ( V_90 , V_8 -> V_54 . V_64 ,
& V_8 -> V_17 , sizeof( V_8 -> V_17 ) ) ;
memset ( V_92 , 0 , V_44 -> V_81 ) ;
V_44 -> V_93 ( & V_2 -> V_14 , V_4 , V_5 , V_92 ) ;
F_18 ( V_90 , V_8 -> V_17 . V_84 ,
V_92 , V_44 -> V_81 ) ;
F_18 ( V_90 , V_8 -> V_17 . V_18 ,
V_4 -> V_45 , V_4 -> V_66 ) ;
V_91 += sizeof( V_8 -> V_54 ) ;
}
F_19 ( V_90 , V_91 , V_94 ) ;
F_20 ( V_90 ) ;
return 0 ;
}
static int
F_21 ( struct V_35 * V_2 , T_1 V_5 , T_2 V_95 )
{
const struct V_38 * V_39 = V_2 -> V_14 . V_39 ;
struct V_85 V_86 ;
struct V_3 * V_8 , * V_96 ;
unsigned long V_97 = V_2 -> V_14 . V_97 ;
int V_98 = 0 ;
T_2 V_99 ;
int V_37 ;
int V_40 ;
F_22 ( & V_86 ) ;
F_23 (falcon_id, &managed_falcons, NVKM_SECBOOT_FALCON_END) {
struct V_3 * V_8 ;
V_8 = V_2 -> V_43 -> V_100 ( V_2 , V_37 ) ;
if ( F_24 ( V_8 ) ) {
V_40 = F_25 ( V_8 ) ;
goto V_101;
}
F_26 ( & V_8 -> V_102 , & V_86 ) ;
V_98 ++ ;
}
V_99 = V_2 -> V_43 -> V_103 ( V_2 , & V_86 ) ;
V_99 = F_12 ( V_99 , V_104 ) ;
V_40 = F_27 ( V_39 -> V_105 , V_99 , V_104 ,
false , NULL , & V_2 -> V_106 ) ;
if ( V_40 )
goto V_101;
F_28 ( V_39 , L_2 ,
V_98 , V_99 ) ;
if ( V_95 == 0 ) {
V_5 = V_2 -> V_106 -> V_107 ;
V_95 = V_99 ;
} else if ( V_99 > V_95 ) {
F_9 ( V_39 , L_3 ) ;
F_9 ( V_39 , L_4 , V_99 ) ;
F_9 ( V_39 , L_5 , V_95 ) ;
V_40 = - V_108 ;
goto V_101;
}
V_40 = V_2 -> V_43 -> V_109 ( V_2 , & V_86 , V_2 -> V_106 , V_5 ) ;
if ( V_40 )
F_29 ( & V_2 -> V_106 ) ;
V_101:
F_30 (img, t, &imgs, node) {
F_8 ( V_8 -> V_45 ) ;
F_8 ( V_8 -> V_46 ) ;
F_8 ( V_8 ) ;
}
return V_40 ;
}
static void
F_31 ( struct V_110 * V_111 , void * V_112 )
{
struct V_113 * V_114 = V_112 ;
struct V_115 * V_116 = V_112 + V_114 -> V_117 ;
void * V_118 = V_112 + V_114 -> V_119 ;
void * V_46 ;
T_2 V_47 ;
if ( V_111 -> V_59 -> V_120 ) {
V_46 = V_112 + V_116 -> V_121 ;
V_47 = V_116 -> V_122 ;
} else {
V_46 = V_112 + V_116 -> V_123 ;
V_47 = V_116 -> V_124 ;
}
memcpy ( V_118 + V_116 -> V_125 , V_46 + V_116 -> V_126 , V_47 ) ;
}
static void
F_32 ( struct V_35 * V_2 , struct V_110 * V_111 ,
struct V_127 * V_10 )
{
struct V_89 * V_106 = V_2 -> V_106 ;
if ( V_111 -> V_95 == 0 ) {
T_2 V_128 = V_106 -> V_107 ;
T_2 V_129 = V_128 + V_106 -> V_130 ;
V_10 -> V_131 = 1 ;
V_10 -> V_132 . V_133 = 2 ;
V_10 -> V_132 . V_134 [ 0 ] . V_135 = V_128 >> 8 ;
V_10 -> V_132 . V_134 [ 0 ] . V_136 = V_129 >> 8 ;
V_10 -> V_132 . V_134 [ 0 ] . V_137 = 1 ;
V_10 -> V_132 . V_134 [ 0 ] . V_138 = 0xf ;
V_10 -> V_132 . V_134 [ 0 ] . V_139 = 0xc ;
V_10 -> V_132 . V_134 [ 0 ] . V_140 = 0x2 ;
} else {
V_10 -> V_141 = V_106 -> V_107 ;
V_10 -> V_142 = V_106 -> V_130 ;
}
}
static void
F_33 ( const struct V_143 * V_144 , void * V_145 ,
T_1 V_51 )
{
struct V_9 * V_146 = V_145 ;
T_1 V_15 , V_16 ;
V_15 = V_51 >> 8 ;
V_16 = ( V_51 + V_144 -> V_31 ) >> 8 ;
V_146 -> V_22 = V_147 ;
V_146 -> V_24 = F_2 ( V_15 ) ;
V_146 -> V_26 = V_144 -> V_26 ;
V_146 -> V_27 = V_144 -> V_27 ;
V_146 -> V_148 = V_144 -> V_149 [ 0 ] . V_148 ;
V_146 -> V_150 = V_144 -> V_149 [ 0 ] . V_150 ;
V_146 -> V_29 = 0 ;
V_146 -> V_31 = F_2 ( V_16 ) ;
V_146 -> V_33 = V_144 -> V_33 ;
}
static int
F_34 ( struct V_35 * V_2 , struct V_110 * V_111 ,
const char * V_151 , struct V_89 * * V_152 ,
struct V_143 * V_153 , bool V_154 )
{
struct V_38 * V_39 = & V_111 -> V_39 ;
void * V_112 ;
struct V_113 * V_114 ;
struct V_115 * V_116 ;
struct V_143 * V_155 ;
void * V_156 ;
int V_40 ;
V_112 = F_35 ( V_39 , V_151 , 0 ) ;
if ( F_24 ( V_112 ) )
return F_25 ( V_112 ) ;
V_114 = V_112 ;
V_116 = V_112 + V_114 -> V_117 ;
V_155 = V_112 + V_116 -> V_157 ;
V_156 = V_112 + V_114 -> V_119 ;
F_31 ( V_111 , V_112 ) ;
if ( V_154 ) {
struct V_127 * V_10 ;
V_10 = V_156 + V_155 -> V_31 ;
F_32 ( V_2 , V_111 , V_10 ) ;
}
if ( V_155 -> V_158 > V_159 ) {
F_9 ( V_39 , L_6 ,
V_155 -> V_158 , V_159 ) ;
V_40 = - V_50 ;
goto V_101;
}
memcpy ( V_153 , V_155 , sizeof( * V_153 ) +
( sizeof( V_155 -> V_149 [ 0 ] ) * V_155 -> V_158 ) ) ;
V_40 = F_27 ( V_39 -> V_105 , F_12 ( V_114 -> V_33 , 256 ) ,
0x1000 , false , NULL , V_152 ) ;
if ( V_40 )
goto V_101;
F_17 ( * V_152 ) ;
F_18 ( * V_152 , 0 , V_156 , V_114 -> V_33 ) ;
F_20 ( * V_152 ) ;
V_101:
F_8 ( V_112 ) ;
return V_40 ;
}
static int
F_36 ( struct V_35 * V_2 )
{
const struct V_38 * V_39 = V_2 -> V_14 . V_39 ;
struct V_113 * V_144 ;
struct V_160 * V_161 ;
V_2 -> V_162 = F_35 ( V_39 , L_7 , 0 ) ;
if ( F_24 ( V_2 -> V_162 ) ) {
int V_40 = F_25 ( V_2 -> V_162 ) ;
V_2 -> V_162 = NULL ;
return V_40 ;
}
V_144 = V_2 -> V_162 ;
V_161 = V_2 -> V_162 + V_144 -> V_117 ;
V_2 -> V_14 . V_163 = V_161 -> V_164 << 8 ;
return 0 ;
}
int
F_37 ( struct V_35 * V_2 , struct V_110 * V_111 )
{
int V_40 ;
if ( V_2 -> V_165 )
return 0 ;
V_40 = F_21 ( V_2 , V_111 -> V_5 , V_111 -> V_95 ) ;
if ( V_40 )
return V_40 ;
if ( ! V_2 -> V_166 ) {
V_40 = F_34 ( V_2 , V_111 , L_8 ,
& V_2 -> V_166 ,
& V_2 -> V_167 , true ) ;
if ( V_40 )
return V_40 ;
}
if ( V_111 -> V_95 == 0 ) {
V_40 = F_34 ( V_2 , V_111 , L_9 ,
& V_2 -> V_168 ,
& V_2 -> V_169 , false ) ;
if ( V_40 )
return V_40 ;
}
if ( ! V_2 -> V_162 ) {
V_40 = F_36 ( V_2 ) ;
if ( V_40 )
return V_40 ;
}
V_2 -> V_165 = true ;
F_28 ( & V_111 -> V_39 , L_10 ) ;
return 0 ;
}
static int
F_38 ( struct V_1 * V_170 , struct V_110 * V_111 ,
struct V_89 * V_152 , T_1 V_51 )
{
struct V_35 * V_2 = V_35 ( V_170 ) ;
struct V_171 * V_172 = V_111 -> V_59 ;
struct V_113 * V_144 = V_2 -> V_162 ;
struct V_160 * V_161 = V_2 -> V_162 + V_144 -> V_117 ;
void * V_173 = V_2 -> V_162 + V_144 -> V_119 ;
void * V_174 = V_173 + V_161 -> V_175 ;
void * V_176 = V_173 + V_161 -> V_177 ;
T_2 V_178 = F_12 ( V_161 -> V_178 , 256 ) ;
const struct V_143 * V_155 ;
const T_2 V_81 = V_2 -> V_43 -> V_179 ;
T_3 V_146 [ V_81 ] ;
if ( V_152 == V_2 -> V_166 ) {
V_155 = & V_2 -> V_167 ;
} else if ( V_152 == V_2 -> V_168 ) {
V_155 = & V_2 -> V_169 ;
} else {
F_9 ( V_170 -> V_39 , L_11 ) ;
return - V_50 ;
}
F_39 ( V_172 , V_176 , 0x0 , V_161 -> V_33 , 0 ) ;
F_40 ( V_172 , V_174 , V_172 -> V_180 . V_181 - V_178 ,
V_178 , V_161 -> V_164 , 0 , false ) ;
memset ( V_146 , 0 , V_81 ) ;
V_2 -> V_43 -> V_182 ( V_155 , V_146 , V_51 ) ;
F_39 ( V_172 , V_146 , V_161 -> V_183 ,
V_81 , 0 ) ;
return 0 ;
}
static int
F_41 ( struct V_35 * V_2 , struct V_110 * V_111 )
{
int V_184 ;
if ( V_2 -> V_168 && V_111 -> V_185 ) {
int V_40 ;
F_28 ( & V_111 -> V_39 , L_12 ) ;
V_40 = V_111 -> V_43 -> V_186 ( V_111 , V_2 -> V_168 ) ;
if ( V_40 )
return V_40 ;
F_28 ( & V_111 -> V_39 , L_13 ) ;
}
for ( V_184 = 0 ; V_184 < V_187 ; V_184 ++ )
V_2 -> V_188 [ V_184 ] = V_189 ;
V_111 -> V_185 = false ;
return 0 ;
}
static int
F_42 ( struct V_35 * V_2 , struct V_110 * V_111 )
{
int V_40 ;
if ( V_111 -> V_185 )
return 0 ;
V_40 = F_37 ( V_2 , V_111 ) ;
if ( V_40 )
return V_40 ;
F_28 ( & V_111 -> V_39 , L_14 ) ;
V_40 = V_111 -> V_43 -> V_186 ( V_111 , V_2 -> V_166 ) ;
F_43 ( V_111 -> V_59 , 0x10 ) ;
if ( V_40 )
return V_40 ;
F_28 ( & V_111 -> V_39 , L_15 ) ;
V_111 -> V_185 = true ;
return 0 ;
}
static int
F_44 ( struct V_1 * V_170 , struct V_110 * V_111 ,
enum V_36 V_172 )
{
struct V_35 * V_2 = V_35 ( V_170 ) ;
int V_40 ;
if ( V_172 != V_190 )
goto V_191;
V_40 = F_41 ( V_2 , V_111 ) ;
if ( V_40 )
return V_40 ;
F_42 ( V_2 , V_111 ) ;
if ( V_40 )
return V_40 ;
V_191:
V_2 -> V_188 [ V_172 ] = V_192 ;
return 0 ;
}
static int
F_45 ( struct V_1 * V_170 , struct V_110 * V_111 ,
enum V_36 V_172 )
{
struct V_35 * V_2 = V_35 ( V_170 ) ;
const struct V_38 * V_39 = & V_111 -> V_39 ;
int V_14 ;
switch ( V_172 ) {
case V_190 :
V_14 = 0x409000 ;
break;
case V_193 :
V_14 = 0x41a000 ;
break;
default:
F_9 ( V_39 , L_16 ) ;
return - V_50 ;
}
F_46 ( V_39 -> V_105 , V_14 + 0x130 , 0x00000002 ) ;
V_2 -> V_188 [ V_172 ] = V_194 ;
return 0 ;
}
static int
F_47 ( struct V_1 * V_170 , struct V_110 * V_111 , bool V_195 )
{
struct V_35 * V_2 = V_35 ( V_170 ) ;
return F_41 ( V_2 , V_111 ) ;
}
static void
F_48 ( struct V_1 * V_170 )
{
struct V_35 * V_2 = V_35 ( V_170 ) ;
F_29 ( & V_2 -> V_168 ) ;
F_8 ( V_2 -> V_162 ) ;
F_29 ( & V_2 -> V_166 ) ;
F_29 ( & V_2 -> V_106 ) ;
F_8 ( V_2 ) ;
}
struct V_1 *
F_49 ( const struct V_196 * V_43 ,
enum V_36 V_59 ,
unsigned long V_97 )
{
struct V_35 * V_2 ;
V_2 = F_5 ( sizeof( * V_2 ) , V_41 ) ;
if ( ! V_2 )
return F_6 ( - V_42 ) ;
V_2 -> V_14 . V_59 = V_59 ;
V_2 -> V_14 . V_97 = V_97 ;
V_2 -> V_14 . V_43 = & V_197 ;
V_2 -> V_43 = V_43 ;
return & V_2 -> V_14 ;
}
struct V_1 *
F_50 ( unsigned long V_97 )
{
return F_49 ( & V_196 , V_198 ,
V_97 ) ;
}

static const union V_1 * F_1 (
const struct V_2 * V_3 ,
T_1 V_4 , T_1 V_5 )
{
unsigned int V_6 = F_2 (
V_3 -> V_7 . V_8 ) ;
unsigned int V_9 =
F_3 ( struct V_2 , V_10 [ 0 ] ) ;
unsigned long V_11 = ( unsigned long ) V_3 ;
while ( V_9 < V_6 ) {
const union V_1 * V_10 =
( const union V_1 * ) ( V_11 + V_9 ) ;
if ( V_4 == V_10 -> V_12 . V_13 . V_4 &&
V_5 == V_10 -> V_12 . V_13 . V_5 )
return V_10 ;
V_9 += F_2 ( V_10 -> V_12 . V_13 . V_14 ) ;
}
return NULL ;
}
static struct V_2 * F_4 (
struct V_15 * V_16 )
{
const void * V_17 ;
T_2 V_18 ;
V_18 = F_5 ( V_19 ) ;
V_17 = F_6 ( V_16 -> V_20 ,
V_18 , NULL , NULL , NULL ) ;
F_7 (
table_address,
L_1 ,
return NULL) ;
return (struct V_2 * ) V_17 ;
}
bool F_8 ( struct V_15 * V_16 ,
T_1 V_4 , T_1 V_5 )
{
struct V_2 * V_21 =
(struct V_2 * )
F_4 ( V_16 ) ;
bool V_22 ;
F_7 (voltage_info,
L_2 ,
return false) ;
V_22 = ( F_1 ( V_21 ,
V_4 , V_5 ) ) ? true : false ;
return V_22 ;
}
int F_9 ( struct V_15 * V_16 ,
T_1 V_4 , T_1 V_5 ,
struct V_23 * V_24 )
{
struct V_2 * V_21 =
(struct V_2 * )
F_4 ( V_16 ) ;
const union V_1 * V_10 ;
unsigned int V_25 ;
int V_26 = 0 ;
F_7 (voltage_info,
L_2 ,
return -1 ) ;
V_10 = F_1 ( V_21 ,
V_4 , V_5 ) ;
if ( ! V_10 )
return - 1 ;
V_24 -> V_27 = 0 ;
if ( V_5 == V_28 ) {
F_7 (
( V_10 -> V_12 . V_29 <=
V_30 ) ,
L_3 ,
V_26 = - 1 ) ;
if ( ! V_26 ) {
for ( V_25 = 0 ; V_25 < V_10 -> V_12 .
V_29 ; V_25 ++ ) {
V_24 -> V_31 [ V_25 ] . V_32 =
F_2 ( V_10 -> V_12 .
V_33 [ V_25 ] . V_34 ) ;
V_24 -> V_31 [ V_25 ] . V_35 =
F_10 ( V_10 -> V_12 .
V_33 [ V_25 ] . V_36 ) ;
}
V_24 -> V_27 =
V_10 -> V_12 . V_29 ;
V_24 -> V_37 =
F_10 (
V_10 -> V_12 . V_38 ) ;
V_24 -> V_39 =
V_10 -> V_12 . V_40 ;
}
} else if ( V_5 == V_41 ) {
V_24 -> V_42 =
V_10 -> V_43 . V_44 & 0x1 ;
V_24 -> V_45 =
V_10 -> V_43 . V_45 & 0x1 ;
V_24 -> V_46 =
V_10 -> V_43 . V_47 ;
V_24 -> V_48 =
V_10 -> V_43 . V_48 ;
V_24 -> V_49 =
V_10 -> V_43 . V_50 ;
} else
F_7 ( false ,
L_4 ,
V_26 = - 1 ) ;
return V_26 ;
}
static struct V_51 * F_11 (
struct V_15 * V_16 )
{
const void * V_17 ;
T_2 V_18 ;
V_18 = F_5 ( V_52 ) ;
V_17 = F_6 ( V_16 -> V_20 ,
V_18 , NULL , NULL , NULL ) ;
F_7 (table_address,
L_1 ,
return NULL) ;
return (struct V_51 * ) V_17 ;
}
static bool F_12 (
struct V_51 * V_53 ,
const T_3 V_54 ,
struct V_55 * V_56 )
{
unsigned int V_6 = F_2 (
V_53 -> V_7 . V_8 ) ;
unsigned int V_9 =
F_3 ( struct V_51 , V_57 [ 0 ] ) ;
unsigned long V_11 = ( unsigned long ) V_53 ;
while ( V_9 < V_6 ) {
const struct V_58 * V_59 =
( const struct V_58 * ) ( V_11 + V_9 ) ;
if ( V_54 == V_59 -> V_60 ) {
V_56 -> V_61 =
V_59 -> V_62 ;
V_56 -> V_63 =
F_2 ( V_59 -> V_64 ) ;
return true ;
}
V_9 += F_3 ( struct V_58 , V_60 ) + 1 ;
}
return false ;
}
bool F_13 ( struct V_15 * V_16 ,
const T_3 V_54 ,
struct V_55 * V_56 )
{
bool V_22 = false ;
struct V_51 * V_53 =
F_11 ( V_16 ) ;
F_7 (gpio_lookup_table,
L_5 ,
return false) ;
V_22 = F_12 ( V_53 ,
V_54 , V_56 ) ;
return V_22 ;
}
int F_14 ( struct V_15 * V_16 )
{
return 0 ;
}
int F_15 ( struct V_15 * V_16 ,
T_3 V_65 , T_3 V_66 ,
struct V_67 * V_68 )
{
struct V_69 V_70 ;
struct V_71 * V_72 ;
int V_26 ;
T_3 V_18 ;
V_70 . V_73 = ( T_3 ) V_66 ;
V_70 . V_74 = V_65 ;
V_18 = F_16 ( V_75 ) ;
V_26 = F_17 ( V_16 -> V_20 , V_18 , & V_70 ) ;
if ( ! V_26 ) {
V_72 = (struct V_71 * )
& V_70 ;
V_68 -> V_76 = F_10 ( V_72 -> V_73 ) ;
V_68 -> V_77 = F_10 ( V_72 -> V_78 ) ;
V_68 -> V_79 = F_10 ( V_72 -> V_80 ) ;
V_68 -> V_81 = F_10 ( V_72 -> V_82 ) ;
V_68 -> V_83 = F_2 ( V_72 -> V_84 ) ;
V_68 -> V_85 = V_72 -> V_86 ;
}
return V_26 ;
}
int F_18 ( struct V_15 * V_16 ,
struct V_87 * V_88 )
{
T_2 V_18 ;
struct V_89 * V_90 ;
V_18 = F_5 ( V_91 ) ;
V_90 = (struct V_89 * )
F_6 ( V_16 -> V_20 ,
V_18 , NULL , NULL , NULL ) ;
if ( ! V_90 )
return - 1 ;
V_88 -> V_92 = F_10 ( V_90 -> V_93 ) ;
V_88 -> V_94 = F_10 ( V_90 -> V_95 ) ;
V_88 -> V_96 =
F_10 ( V_90 -> V_97 ) ;
V_88 -> V_98 =
F_10 ( V_90 -> V_99 ) ;
V_88 -> V_100 =
F_10 ( V_90 -> V_101 ) ;
V_88 -> V_102 =
F_2 ( V_90 -> V_103 ) ;
V_88 -> V_104 =
F_2 ( V_90 -> V_105 ) ;
V_88 -> V_106 =
F_2 ( V_90 -> V_107 ) ;
V_88 -> V_108 =
F_10 ( V_90 -> V_109 ) ;
V_88 -> V_110 =
F_10 ( V_90 -> V_111 ) ;
V_88 -> V_112 =
F_10 ( V_90 -> V_113 ) ;
V_88 -> V_114 =
F_10 ( V_90 -> V_115 ) ;
V_88 -> V_116 =
F_10 ( V_90 -> V_117 ) ;
V_88 -> V_118 =
F_10 ( V_90 -> V_119 ) ;
V_88 -> V_120 =
F_10 ( V_90 -> V_121 ) ;
V_88 -> V_122 =
F_10 ( V_90 -> V_123 ) ;
V_88 -> V_124 =
F_10 ( V_90 -> V_125 ) ;
V_88 -> V_126 =
F_10 ( V_90 -> V_127 ) ;
V_88 -> V_128 =
F_10 ( V_90 -> V_129 ) ;
V_88 -> V_130 =
F_10 ( V_90 -> V_131 ) ;
V_88 -> V_132 =
V_90 -> V_133 ;
V_88 -> V_134 =
V_90 -> V_135 ;
V_88 -> V_136 =
F_2 ( V_90 -> V_137 ) ;
V_88 -> V_138 =
F_10 ( V_90 -> V_139 ) ;
V_88 -> V_140 =
F_10 ( V_90 -> V_141 ) ;
V_88 -> V_142 =
F_10 ( V_90 -> V_143 ) ;
V_88 -> V_144 =
F_10 ( V_90 -> V_145 ) ;
V_88 -> V_146 =
F_10 ( V_90 -> V_147 ) ;
V_88 -> V_148 =
F_10 ( V_90 -> V_149 ) ;
V_88 -> V_150 =
F_10 ( V_90 -> V_151 ) ;
V_88 -> V_152 =
F_10 ( V_90 -> V_153 ) ;
V_88 -> V_154 =
F_10 ( V_90 -> V_155 ) ;
V_88 -> V_156 =
F_10 ( V_90 -> V_157 ) ;
V_88 -> V_158 =
F_10 ( V_90 -> V_159 ) ;
V_88 -> V_160 =
F_10 ( V_90 -> V_161 ) ;
return 0 ;
}
int F_19 ( struct V_15 * V_16 ,
struct V_162 * V_88 )
{
struct V_163 * V_164 ;
T_2 V_18 ;
V_18 = F_5 ( V_165 ) ;
V_164 = (struct V_163 * )
F_6 ( V_16 -> V_20 ,
V_18 , NULL , NULL , NULL ) ;
if ( ! V_164 ) {
F_20 ( L_6 ) ;
return - 1 ;
}
V_88 -> V_166 = V_164 -> V_167 ;
V_88 -> V_168 = V_164 -> V_169 ;
V_88 -> V_170 = V_164 -> V_171 ;
V_88 -> V_172 = V_164 -> V_173 ;
V_88 -> V_174 = V_164 -> V_175 ;
V_88 -> V_176 = V_164 -> V_177 ;
V_88 -> V_178 = V_164 -> V_179 ;
V_88 -> V_180 = V_164 -> V_181 ;
return 0 ;
}
int F_21 ( struct V_15 * V_16 , T_4 V_182 , T_3 * V_183 )
{
struct V_184 V_185 ;
struct V_186 * V_187 ;
T_3 V_188 ;
V_185 . V_189 = V_182 ;
V_185 . V_190 = V_191 ;
V_188 = F_16 ( V_192 ) ;
if ( ! F_17 ( V_16 -> V_20 , V_188 , & V_185 ) ) {
V_187 = (struct V_186 * ) & V_185 ;
* V_183 = V_187 -> V_193 . V_194 / 10000 ;
} else {
F_20 ( L_7 ) ;
return - 1 ;
}
return 0 ;
}
int F_22 ( struct V_15 * V_16 ,
struct V_195 * V_196 )
{
struct V_197 * V_164 = NULL ;
T_2 V_188 ;
T_3 V_183 = 0 ;
V_188 = F_5 ( V_198 ) ;
V_164 = (struct V_197 * )
F_6 ( V_16 -> V_20 ,
V_188 , NULL , NULL , NULL ) ;
if ( ! V_164 ) {
F_20 ( L_8 ) ;
return - V_199 ;
}
V_196 -> V_200 = V_164 -> V_201 ;
V_196 -> V_202 = V_164 -> V_203 ;
V_196 -> V_204 = V_164 -> V_205 ;
V_196 -> V_206 = V_164 -> V_207 ;
V_196 -> V_208 = V_164 -> V_209 ;
V_196 -> V_210 = V_164 -> V_211 ;
V_196 -> V_212 = V_164 -> V_213 ;
V_196 -> V_214 = 0 ;
V_196 -> V_215 = 0 ;
if ( ! F_21 ( V_16 , V_216 , & V_183 ) )
V_196 -> V_214 = V_183 ;
if ( ! F_21 ( V_16 , V_217 , & V_183 ) )
V_196 -> V_215 = V_183 ;
return 0 ;
}

static inline T_1 F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 + V_4 ) ;
}
static inline int F_3 ( T_1 V_5 )
{
return ( V_6 & V_5 ) ? 1 : 0 ;
}
static inline int F_4 ( struct V_7 * V_8 )
{
return V_8 -> V_9 -> V_10 . V_11 & V_12 ;
}
static inline int
F_5 ( struct V_13 * V_14 )
{
return V_14 -> V_10 . V_11 & V_12 ;
}
static inline int F_6 ( struct V_1 * V_2 )
{
return F_7 ( & V_2 -> V_15 , V_2 -> V_16 ) ;
}
static inline void F_8 ( struct V_1 * V_2 , T_1 V_17 )
{
F_9 ( ~ ( 1 << V_17 ) ,
( V_2 -> V_3 + V_18 ) ) ;
}
static inline int F_10 ( T_1 V_19 )
{
return ( ( ( V_19 ) & ( 0xFF ) ) >> 1 ) ^ ( 0x07 ) ;
}
static inline int F_11 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 + V_20 ) &
V_21 ;
}
static inline void F_12 ( struct V_1 * V_2 )
{
T_2 V_22 , V_23 , V_24 ;
F_13 ( V_2 -> V_25 ) ;
if ( V_2 -> V_26 ) {
V_22 = sizeof( struct V_13 ) * V_2 -> V_16 ;
F_14 ( V_2 -> V_27 , V_22 ,
V_2 -> V_26 , V_2 -> V_28 ) ;
}
if ( V_2 -> V_29 ) {
V_23 =
( sizeof( struct V_30 ) * V_2 -> V_31 ) ;
F_14 ( V_2 -> V_27 , V_23 ,
V_2 -> V_29 , V_2 -> V_32 ) ;
}
if ( V_2 -> V_33 ) {
V_24 =
( sizeof( struct V_34 ) * V_2 -> V_31 ) ;
F_14 ( V_2 -> V_27 , V_24 ,
V_2 -> V_33 , V_2 -> V_35 ) ;
}
}
static inline int
F_15 ( struct V_36 * V_37 )
{
return ( ( F_16 ( V_37 -> V_10 . V_38 ) >> 24 ) ==
V_39 ) ? 0 : V_40 << 16 ;
}
static inline int
F_17 ( struct V_36 * V_37 )
{
return F_16 ( V_37 -> V_10 . V_41 ) & V_42 ;
}
static inline void
F_18 ( struct V_1 * V_2 , int V_43 )
{
switch ( V_43 ) {
case V_44 :
F_9 ( ( V_45 |
V_46 ) ,
( V_2 -> V_3 +
V_47 ) ) ;
break;
case V_48 :
F_9 ( ( V_45 |
V_49 |
V_50 |
V_51 ) ,
( V_2 -> V_3 +
V_47 ) ) ;
break;
}
}
static void F_19 ( struct V_1 * V_2 )
{
F_9 ( V_52 ,
( V_2 -> V_3 +
V_53 ) ) ;
F_9 ( V_54 ,
( V_2 -> V_3 +
V_55 ) ) ;
}
static inline void F_20 ( struct V_1 * V_2 )
{
F_9 ( V_56 , ( V_2 -> V_3 + V_57 ) ) ;
}
static inline int F_21 ( struct V_1 * V_2 )
{
return ( F_2 ( V_2 -> V_3 + V_57 ) & 0x1 ) ? 0 : 1 ;
}
static inline
void F_22 ( struct V_1 * V_2 , unsigned int V_58 )
{
F_23 ( V_58 , & V_2 -> V_59 ) ;
F_9 ( ( 1 << V_58 ) ,
( V_2 -> V_3 + V_60 ) ) ;
}
static inline void F_24 ( struct V_7 * V_8 )
{
int V_61 ;
if ( V_8 -> V_62 ) {
V_61 = F_25 ( V_8 -> V_37 -> V_63 ) ;
memcpy ( V_8 -> V_62 ,
V_8 -> V_37 -> V_64 ,
F_26 ( int , V_61 , V_65 ) ) ;
}
}
static inline void F_27 ( struct V_1 * V_2 )
{
V_2 -> V_66 =
F_2 ( V_2 -> V_3 + V_67 ) ;
V_2 -> V_31 = ( V_2 -> V_66 & V_68 ) + 1 ;
V_2 -> V_16 =
( ( V_2 -> V_66 & V_69 ) >> 16 ) + 1 ;
}
static inline void
F_28 ( struct V_1 * V_2 , struct V_70 * V_71 )
{
F_9 ( V_71 -> V_72 ,
( V_2 -> V_3 + V_73 ) ) ;
F_9 ( V_71 -> V_74 ,
( V_2 -> V_3 + V_20 ) ) ;
F_9 ( V_71 -> V_75 ,
( V_2 -> V_3 + V_76 ) ) ;
F_9 ( ( V_71 -> V_77 & V_78 ) ,
( V_2 -> V_3 + V_79 ) ) ;
}
static int F_29 ( struct V_7 * V_8 )
{
struct V_80 * V_81 ;
struct V_82 * V_83 ;
struct V_84 * V_85 ;
int V_86 ;
int V_87 ;
V_85 = V_8 -> V_85 ;
V_86 = F_30 ( V_85 ) ;
if ( V_86 < 0 )
return V_86 ;
if ( V_86 ) {
V_8 -> V_9 -> V_88 =
F_31 ( ( V_89 ) ( V_86 ) ) ;
V_81 = (struct V_80 * ) V_8 -> V_90 ;
F_32 (cmd, sg, sg_segments, i) {
V_81 [ V_87 ] . V_91 =
F_33 ( ( ( T_1 ) F_34 ( V_83 ) ) - 1 ) ;
V_81 [ V_87 ] . V_92 =
F_33 ( F_35 ( V_83 -> V_93 ) ) ;
V_81 [ V_87 ] . V_94 =
F_33 ( F_36 ( V_83 -> V_93 ) ) ;
}
} else {
V_8 -> V_9 -> V_88 = 0 ;
}
return 0 ;
}
static void F_37 ( struct V_1 * V_2 , T_1 V_43 )
{
switch ( V_43 ) {
case V_95 :
F_9 ( V_2 -> V_96 ,
( V_2 -> V_3 + V_97 ) ) ;
break;
case V_98 :
if ( V_2 -> V_99 == V_100 )
F_9 ( V_101 ,
( V_2 -> V_3 + V_97 ) ) ;
else
F_9 ( V_102 ,
( V_2 -> V_3 + V_97 ) ) ;
break;
}
}
static void F_38 ( struct V_7 * V_8 )
{
struct V_30 * V_103 ;
struct V_104 * V_105 ;
T_1 V_106 ;
T_1 V_107 ;
V_105 = V_8 -> V_105 ;
V_103 = V_8 -> V_9 ;
switch ( V_8 -> V_108 ) {
case V_109 :
if ( V_8 -> V_85 -> V_110 == V_111 ) {
V_106 = V_112 ;
V_107 = V_113 ;
} else if ( V_8 -> V_85 -> V_110 == V_114 ) {
V_106 = V_115 ;
V_107 = V_116 ;
} else {
V_106 = V_117 ;
V_107 = V_118 ;
}
V_103 -> V_10 . V_38 =
F_33 ( V_106 | V_119 ) ;
V_103 -> V_10 . V_11 =
F_33 ( V_120 ) ;
V_105 -> V_10 . V_38 =
F_39 ( F_40 ( V_121 ,
V_107 ,
V_8 -> V_122 ,
V_8 -> V_58 ) ) ;
V_105 -> V_10 . V_41 =
F_39 (
F_40 ( V_123 ,
0 ,
0 ,
0 ) ) ;
V_105 -> V_10 . V_11 = 0 ;
V_105 -> V_124 =
F_39 ( V_8 -> V_85 -> V_125 . V_126 ) ;
memcpy ( V_105 -> V_127 ,
V_8 -> V_85 -> V_128 ,
( F_26 (unsigned short,
lrbp->cmd->cmd_len,
MAX_CDB_SIZE) ) ) ;
break;
case V_129 :
break;
case V_130 :
break;
}
}
static int F_41 ( struct V_131 * V_132 , struct V_84 * V_85 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 ;
unsigned long V_133 ;
int V_134 ;
int V_135 = 0 ;
V_2 = F_42 ( V_132 ) ;
V_134 = V_85 -> V_136 -> V_134 ;
if ( V_2 -> V_137 != V_138 ) {
V_135 = V_139 ;
goto V_140;
}
V_8 = & V_2 -> V_25 [ V_134 ] ;
V_8 -> V_85 = V_85 ;
V_8 -> V_141 = V_65 ;
V_8 -> V_62 = V_85 -> V_62 ;
V_8 -> V_58 = V_134 ;
V_8 -> V_122 = V_85 -> V_142 -> V_122 ;
V_8 -> V_108 = V_109 ;
F_38 ( V_8 ) ;
V_135 = F_29 ( V_8 ) ;
if ( V_135 )
goto V_140;
F_43 ( V_2 -> V_132 -> V_143 , V_133 ) ;
F_22 ( V_2 , V_134 ) ;
F_44 ( V_2 -> V_132 -> V_143 , V_133 ) ;
V_140:
return V_135 ;
}
static int F_45 ( struct V_1 * V_2 )
{
T_2 V_22 , V_23 , V_24 ;
V_24 = ( sizeof( struct V_34 ) * V_2 -> V_31 ) ;
V_2 -> V_33 = F_46 ( V_2 -> V_27 ,
V_24 ,
& V_2 -> V_35 ,
V_144 ) ;
if ( ! V_2 -> V_33 ||
F_47 ( V_2 -> V_35 & ( V_145 - 1 ) ) ) {
F_48 ( V_2 -> V_27 ,
L_1 ) ;
goto V_140;
}
V_23 = ( sizeof( struct V_30 ) * V_2 -> V_31 ) ;
V_2 -> V_29 = F_46 ( V_2 -> V_27 ,
V_23 ,
& V_2 -> V_32 ,
V_144 ) ;
if ( ! V_2 -> V_29 ||
F_47 ( V_2 -> V_32 & ( V_145 - 1 ) ) ) {
F_48 ( V_2 -> V_27 ,
L_2 ) ;
goto V_140;
}
V_22 = sizeof( struct V_13 ) * V_2 -> V_16 ;
V_2 -> V_26 = F_46 ( V_2 -> V_27 ,
V_22 ,
& V_2 -> V_28 ,
V_144 ) ;
if ( ! V_2 -> V_26 ||
F_47 ( V_2 -> V_28 & ( V_145 - 1 ) ) ) {
F_48 ( V_2 -> V_27 ,
L_3 ) ;
goto V_140;
}
V_2 -> V_25 = F_49 ( V_2 -> V_31 , sizeof( struct V_7 ) , V_144 ) ;
if ( ! V_2 -> V_25 ) {
F_48 ( V_2 -> V_27 , L_4 ) ;
goto V_140;
}
return 0 ;
V_140:
F_12 ( V_2 ) ;
return - V_146 ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_34 * V_147 ;
struct V_30 * V_148 ;
T_3 V_149 ;
T_3 V_150 ;
V_89 V_151 ;
V_89 V_152 ;
int V_153 ;
int V_87 ;
V_148 = V_2 -> V_29 ;
V_147 = V_2 -> V_33 ;
V_151 =
F_51 ( struct V_34 , V_154 ) ;
V_152 =
F_51 ( struct V_34 , V_81 ) ;
V_153 = sizeof( struct V_34 ) ;
V_149 = V_2 -> V_35 ;
for ( V_87 = 0 ; V_87 < V_2 -> V_31 ; V_87 ++ ) {
V_150 =
( V_149 + ( V_153 * V_87 ) ) ;
V_148 [ V_87 ] . V_155 =
F_33 ( F_35 ( V_150 ) ) ;
V_148 [ V_87 ] . V_156 =
F_33 ( F_36 ( V_150 ) ) ;
V_148 [ V_87 ] . V_157 =
F_31 ( ( V_151 >> 2 ) ) ;
V_148 [ V_87 ] . V_158 =
F_31 ( ( V_152 >> 2 ) ) ;
V_148 [ V_87 ] . V_159 =
F_31 ( V_160 ) ;
V_2 -> V_25 [ V_87 ] . V_9 = ( V_148 + V_87 ) ;
V_2 -> V_25 [ V_87 ] . V_105 =
(struct V_104 * ) ( V_147 + V_87 ) ;
V_2 -> V_25 [ V_87 ] . V_37 =
(struct V_36 * ) V_147 [ V_87 ] . V_154 ;
V_2 -> V_25 [ V_87 ] . V_90 =
(struct V_80 * ) V_147 [ V_87 ] . V_81 ;
}
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_70 * V_161 ;
unsigned long V_133 ;
if ( ( ( F_2 ( V_2 -> V_3 + V_162 ) ) &
V_163 ) == 0x0 ) {
F_48 ( V_2 -> V_27 ,
L_5
L_6 ) ;
return - V_164 ;
}
F_43 ( V_2 -> V_132 -> V_143 , V_133 ) ;
V_161 = & V_2 -> V_165 ;
V_161 -> V_77 = V_166 ;
V_161 -> V_72 = 0 ;
V_161 -> V_74 = 0 ;
V_161 -> V_75 = 0 ;
V_2 -> V_96 |= V_167 ;
F_37 ( V_2 , V_95 ) ;
F_28 ( V_2 , V_161 ) ;
F_44 ( V_2 -> V_132 -> V_143 , V_133 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
int V_135 = 0 ;
T_1 V_19 ;
V_19 = F_2 ( ( V_2 -> V_3 + V_162 ) ) ;
if ( ! F_3 ( V_19 ) ) {
F_48 ( V_2 -> V_27 , L_7 ) ;
V_135 = - V_168 ;
goto V_140;
}
if ( ! ( F_10 ( V_19 ) ) ) {
F_19 ( V_2 ) ;
} else {
F_48 ( V_2 -> V_27 ,
L_8 ) ;
V_135 = - V_164 ;
goto V_140;
}
V_2 -> V_96 |= ( V_169 |
V_170 |
V_171 |
V_172 |
V_173 |
V_174 ) ;
F_37 ( V_2 , V_95 ) ;
F_18 ( V_2 , V_48 ) ;
if ( V_2 -> V_137 == V_175 )
F_54 ( V_2 -> V_132 ) ;
V_2 -> V_137 = V_138 ;
F_55 ( V_2 -> V_132 ) ;
V_140:
return V_135 ;
}
static int F_56 ( struct V_1 * V_2 )
{
int V_176 ;
if ( ! F_21 ( V_2 ) ) {
F_57 ( V_2 ) ;
F_58 ( 5 ) ;
}
F_20 ( V_2 ) ;
F_58 ( 1 ) ;
V_176 = 10 ;
while ( F_21 ( V_2 ) ) {
if ( V_176 ) {
V_176 -- ;
} else {
F_48 ( V_2 -> V_27 ,
L_9 ) ;
return - V_164 ;
}
F_58 ( 5 ) ;
}
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
if ( F_56 ( V_2 ) )
return - V_164 ;
F_9 ( F_35 ( V_2 -> V_32 ) ,
( V_2 -> V_3 + V_177 ) ) ;
F_9 ( F_36 ( V_2 -> V_32 ) ,
( V_2 -> V_3 + V_178 ) ) ;
F_9 ( F_35 ( V_2 -> V_28 ) ,
( V_2 -> V_3 + V_179 ) ) ;
F_9 ( F_36 ( V_2 -> V_28 ) ,
( V_2 -> V_3 + V_180 ) ) ;
return F_52 ( V_2 ) ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
unsigned long V_133 ;
int V_134 ;
F_61 ( V_2 -> V_132 ) ;
F_43 ( V_2 -> V_132 -> V_143 , V_133 ) ;
V_2 -> V_137 = V_175 ;
F_57 ( V_2 ) ;
F_44 ( V_2 -> V_132 -> V_143 , V_133 ) ;
for ( V_134 = 0 ; V_134 < V_2 -> V_31 ; V_134 ++ ) {
if ( F_62 ( V_134 , & V_2 -> V_59 ) ) {
V_8 = & V_2 -> V_25 [ V_134 ] ;
F_63 ( V_8 -> V_85 ) ;
V_8 -> V_85 -> V_181 = V_182 << 16 ;
V_8 -> V_85 -> V_183 ( V_8 -> V_85 ) ;
V_8 -> V_85 = NULL ;
}
}
V_2 -> V_59 = 0 ;
V_2 -> V_15 = 0 ;
if ( F_59 ( V_2 ) ) {
F_48 ( V_2 -> V_27 ,
L_10 ) ;
return V_184 ;
}
return V_185 ;
}
static int F_64 ( struct V_186 * V_187 )
{
struct V_1 * V_2 ;
V_2 = F_42 ( V_187 -> V_132 ) ;
V_187 -> V_188 = 1 ;
V_187 -> V_189 = 1 ;
F_65 ( V_187 , V_190 ) ;
F_66 ( V_187 , V_2 -> V_31 ) ;
return 0 ;
}
static void F_67 ( struct V_186 * V_187 )
{
struct V_1 * V_2 ;
V_2 = F_42 ( V_187 -> V_132 ) ;
F_68 ( V_187 , V_2 -> V_31 ) ;
}
static int F_69 ( struct V_1 * V_2 , T_1 V_191 )
{
struct V_13 * V_14 ;
struct V_192 * V_193 ;
unsigned long V_133 ;
int V_194 ;
int V_195 ;
F_43 ( V_2 -> V_132 -> V_143 , V_133 ) ;
F_70 ( V_191 , & V_2 -> V_15 ) ;
V_14 = V_2 -> V_26 ;
V_194 = F_5 ( & V_14 [ V_191 ] ) ;
if ( V_194 == V_196 ) {
V_193 = (struct V_192 * )
V_14 [ V_191 ] . V_197 ;
V_195 = F_16 ( V_193 -> V_10 . V_41 ) ;
V_195 = ( ( V_195 & V_198 ) >> 8 ) ;
if ( V_195 != V_199 &&
V_195 != V_200 )
V_195 = V_184 ;
else
V_195 = V_185 ;
} else {
V_195 = V_184 ;
F_48 ( V_2 -> V_27 ,
L_11 , V_194 ) ;
}
F_44 ( V_2 -> V_132 -> V_143 , V_133 ) ;
return V_195 ;
}
static void F_71 ( struct V_84 * V_85 )
{
struct V_1 * V_2 ;
int V_87 ;
int V_201 = 0 ;
V_2 = F_42 ( V_85 -> V_142 -> V_132 ) ;
for ( V_87 = 0 ; V_87 < V_2 -> V_31 ; V_87 ++ ) {
if ( F_62 ( V_87 , & V_2 -> V_59 ) ) {
if ( V_85 -> V_142 -> V_122 == V_2 -> V_25 [ V_87 ] . V_122 )
V_201 ++ ;
}
}
F_72 ( V_85 -> V_142 , V_190 , V_201 - 1 ) ;
}
static inline int
F_73 ( struct V_7 * V_8 , int V_202 )
{
int V_181 = 0 ;
switch ( V_202 ) {
case V_203 :
V_181 |= V_204 << 16 |
V_205 << 8 |
V_203 ;
break;
case V_206 :
V_181 |= V_204 << 16 |
V_205 << 8 |
V_206 ;
F_24 ( V_8 ) ;
break;
case V_207 :
V_181 |= V_207 ;
break;
case V_208 :
F_71 ( V_8 -> V_85 ) ;
V_181 |= V_208 ;
break;
case V_209 :
V_181 |= V_209 ;
break;
default:
V_181 |= V_40 << 16 ;
break;
}
return V_181 ;
}
static inline int
F_74 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
int V_181 = 0 ;
int V_202 ;
int V_210 ;
V_210 = F_4 ( V_8 ) ;
switch ( V_210 ) {
case V_196 :
V_181 = F_15 ( V_8 -> V_37 ) ;
if ( V_181 ) {
F_48 ( V_2 -> V_27 ,
L_12 , V_181 ) ;
break;
}
V_181 = F_17 ( V_8 -> V_37 ) ;
V_202 = V_181 & V_211 ;
V_181 = F_73 ( V_8 , V_202 ) ;
break;
case V_212 :
V_181 |= V_213 << 16 ;
break;
case V_214 :
case V_215 :
case V_216 :
case V_217 :
case V_218 :
case V_219 :
default:
V_181 |= V_40 << 16 ;
F_48 ( V_2 -> V_27 ,
L_13 , V_210 ) ;
break;
}
return V_181 ;
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_7 * V_25 ;
unsigned long V_220 ;
T_1 V_221 ;
int V_181 ;
int V_191 ;
V_25 = V_2 -> V_25 ;
V_221 =
F_2 ( V_2 -> V_3 + V_60 ) ;
V_220 = V_221 ^ V_2 -> V_59 ;
for ( V_191 = 0 ; V_191 < V_2 -> V_31 ; V_191 ++ ) {
if ( F_62 ( V_191 , & V_220 ) ) {
V_181 = F_74 ( V_2 , & V_25 [ V_191 ] ) ;
if ( V_25 [ V_191 ] . V_85 ) {
F_63 ( V_25 [ V_191 ] . V_85 ) ;
V_25 [ V_191 ] . V_85 -> V_181 = V_181 ;
V_25 [ V_191 ] . V_85 -> V_183 ( V_25 [ V_191 ] . V_85 ) ;
V_25 [ V_191 ] . V_85 = NULL ;
}
}
}
V_2 -> V_59 ^= V_220 ;
F_18 ( V_2 , V_44 ) ;
}
static void F_76 ( struct V_222 * V_223 )
{
struct V_1 * V_2 ;
V_2 = F_77 ( V_223 , struct V_1 , V_224 ) ;
if ( ( V_2 -> V_165 . V_77 == V_166 ) &&
! ( F_11 ( V_2 ) ) ) {
if ( F_53 ( V_2 ) )
F_48 ( V_2 -> V_27 ,
L_14 ) ;
return;
}
}
static void F_78 ( struct V_222 * V_223 )
{
struct V_1 * V_2 ;
V_2 = F_77 ( V_223 , struct V_1 , V_225 ) ;
if ( V_2 -> V_137 != V_175 )
F_60 ( V_2 ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
T_1 V_19 ;
if ( V_2 -> V_226 & V_227 )
goto V_228;
if ( V_2 -> V_226 & V_170 ) {
V_19 = F_2 ( V_2 -> V_3 +
V_229 ) ;
if ( V_19 & V_230 )
goto V_228;
}
return;
V_228:
V_2 -> V_137 = V_231 ;
F_80 ( & V_2 -> V_225 ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
T_1 V_232 ;
V_232 = F_2 ( V_2 -> V_3 + V_233 ) ;
V_2 -> V_234 = V_232 ^ V_2 -> V_15 ;
F_82 ( & V_2 -> V_235 ) ;
}
static void F_83 ( struct V_1 * V_2 , T_1 V_236 )
{
V_2 -> V_226 = V_237 & V_236 ;
if ( V_2 -> V_226 )
F_79 ( V_2 ) ;
if ( V_236 & V_167 )
F_80 ( & V_2 -> V_224 ) ;
if ( V_236 & V_171 )
F_81 ( V_2 ) ;
if ( V_236 & V_169 )
F_75 ( V_2 ) ;
}
static T_4 F_84 ( int V_238 , void * V_239 )
{
T_1 V_236 ;
T_4 V_240 = V_241 ;
struct V_1 * V_2 = V_239 ;
F_85 ( V_2 -> V_132 -> V_143 ) ;
V_236 = F_2 ( V_2 -> V_3 + V_242 ) ;
if ( V_236 ) {
F_83 ( V_2 , V_236 ) ;
if ( V_2 -> V_99 == V_100 )
F_9 ( V_236 ,
( V_2 -> V_3 + V_242 ) ) ;
V_240 = V_243 ;
}
F_86 ( V_2 -> V_132 -> V_143 ) ;
return V_240 ;
}
static int
F_87 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
T_5 V_244 )
{
struct V_13 * V_14 ;
struct V_245 * V_246 ;
struct V_131 * V_132 ;
unsigned long V_133 ;
int V_247 = 0 ;
int V_135 ;
V_132 = V_2 -> V_132 ;
F_43 ( V_132 -> V_143 , V_133 ) ;
V_247 = F_6 ( V_2 ) ;
if ( V_247 >= V_2 -> V_16 ) {
F_44 ( V_132 -> V_143 , V_133 ) ;
F_48 ( V_2 -> V_27 , L_15 ) ;
V_135 = V_184 ;
goto V_140;
}
V_14 = V_2 -> V_26 ;
V_14 += V_247 ;
V_14 -> V_10 . V_38 = F_33 ( V_248 ) ;
V_14 -> V_10 . V_11 =
F_33 ( V_120 ) ;
V_246 =
(struct V_245 * ) V_14 -> V_249 ;
V_246 -> V_10 . V_38 =
F_39 ( F_40 ( V_250 , 0 ,
V_8 -> V_122 , V_8 -> V_58 ) ) ;
V_246 -> V_10 . V_41 =
F_39 ( F_40 ( 0 , V_244 , 0 , 0 ) ) ;
V_246 -> V_251 = V_8 -> V_122 ;
V_246 -> V_251 =
F_39 ( V_246 -> V_251 ) ;
V_246 -> V_252 = V_8 -> V_58 ;
V_246 -> V_252 =
F_39 ( V_246 -> V_252 ) ;
F_23 ( V_247 , & V_2 -> V_15 ) ;
F_9 ( ( 1 << V_247 ) ,
( V_2 -> V_3 + V_233 ) ) ;
F_44 ( V_132 -> V_143 , V_133 ) ;
V_135 =
F_88 ( V_2 -> V_235 ,
( F_62 ( V_247 ,
& V_2 -> V_234 ) != 0 ) ,
60 * V_253 ) ;
if ( ! V_135 ) {
F_48 ( V_2 -> V_27 ,
L_16 ) ;
V_135 = V_184 ;
goto V_140;
}
F_89 ( V_247 , & V_2 -> V_234 ) ;
V_135 = F_69 ( V_2 , V_247 ) ;
V_140:
return V_135 ;
}
static int F_90 ( struct V_84 * V_85 )
{
struct V_131 * V_132 ;
struct V_1 * V_2 ;
unsigned int V_134 ;
T_1 V_17 ;
int V_135 ;
V_132 = V_85 -> V_142 -> V_132 ;
V_2 = F_42 ( V_132 ) ;
V_134 = V_85 -> V_136 -> V_134 ;
V_135 = F_87 ( V_2 , & V_2 -> V_25 [ V_134 ] , V_254 ) ;
if ( V_135 == V_184 )
goto V_140;
for ( V_17 = 0 ; V_17 < V_2 -> V_31 ; V_17 ++ ) {
if ( F_62 ( V_17 , & V_2 -> V_59 ) &&
( V_2 -> V_25 [ V_134 ] . V_122 == V_2 -> V_25 [ V_17 ] . V_122 ) ) {
F_8 ( V_2 , V_17 ) ;
F_89 ( V_17 , & V_2 -> V_59 ) ;
if ( V_2 -> V_25 [ V_17 ] . V_85 ) {
F_63 ( V_2 -> V_25 [ V_17 ] . V_85 ) ;
V_2 -> V_25 [ V_17 ] . V_85 -> V_181 =
V_213 << 16 ;
V_2 -> V_25 [ V_17 ] . V_85 -> V_183 ( V_85 ) ;
V_2 -> V_25 [ V_17 ] . V_85 = NULL ;
}
}
}
V_140:
return V_135 ;
}
static int F_91 ( struct V_84 * V_85 )
{
struct V_1 * V_2 ;
V_2 = F_42 ( V_85 -> V_142 -> V_132 ) ;
if ( V_2 -> V_137 == V_175 )
return V_185 ;
return F_60 ( V_2 ) ;
}
static int F_92 ( struct V_84 * V_85 )
{
struct V_131 * V_132 ;
struct V_1 * V_2 ;
unsigned long V_133 ;
unsigned int V_134 ;
int V_135 ;
V_132 = V_85 -> V_142 -> V_132 ;
V_2 = F_42 ( V_132 ) ;
V_134 = V_85 -> V_136 -> V_134 ;
F_43 ( V_132 -> V_143 , V_133 ) ;
if ( ! ( F_62 ( V_134 , & V_2 -> V_59 ) ) ) {
V_135 = V_184 ;
F_44 ( V_132 -> V_143 , V_133 ) ;
goto V_140;
}
F_44 ( V_132 -> V_143 , V_133 ) ;
V_135 = F_87 ( V_2 , & V_2 -> V_25 [ V_134 ] , V_255 ) ;
if ( V_135 == V_184 )
goto V_140;
F_63 ( V_85 ) ;
F_43 ( V_132 -> V_143 , V_133 ) ;
F_8 ( V_2 , V_134 ) ;
F_70 ( V_134 , & V_2 -> V_59 ) ;
V_2 -> V_25 [ V_134 ] . V_85 = NULL ;
F_44 ( V_132 -> V_143 , V_133 ) ;
V_140:
return V_135 ;
}
int F_93 ( struct V_1 * V_2 , T_6 V_256 )
{
return - V_257 ;
}
int F_94 ( struct V_1 * V_2 )
{
return - V_257 ;
}
static void F_95 ( struct V_1 * V_2 )
{
F_96 ( V_2 -> V_3 ) ;
F_12 ( V_2 ) ;
}
void F_97 ( struct V_1 * V_2 )
{
F_37 ( V_2 , V_98 ) ;
F_57 ( V_2 ) ;
F_95 ( V_2 ) ;
F_98 ( V_2 -> V_132 ) ;
F_99 ( V_2 -> V_132 ) ;
}
int F_100 ( struct V_142 * V_27 , struct V_1 * * V_258 ,
void T_7 * V_3 , unsigned int V_238 )
{
struct V_131 * V_132 ;
struct V_1 * V_2 ;
int V_135 ;
if ( ! V_27 ) {
F_48 ( V_27 ,
L_17 ) ;
V_135 = - V_259 ;
goto V_260;
}
if ( ! V_3 ) {
F_48 ( V_27 ,
L_18 ) ;
V_135 = - V_259 ;
goto V_260;
}
V_132 = F_101 ( & V_261 ,
sizeof( struct V_1 ) ) ;
if ( ! V_132 ) {
F_48 ( V_27 , L_19 ) ;
V_135 = - V_146 ;
goto V_260;
}
V_2 = F_42 ( V_132 ) ;
V_2 -> V_132 = V_132 ;
V_2 -> V_27 = V_27 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_238 = V_238 ;
F_27 ( V_2 ) ;
V_2 -> V_99 = F_1 ( V_2 ) ;
V_135 = F_45 ( V_2 ) ;
if ( V_135 ) {
F_48 ( V_2 -> V_27 , L_20 ) ;
goto V_262;
}
F_50 ( V_2 ) ;
V_132 -> V_263 = V_2 -> V_31 ;
V_132 -> V_264 = V_2 -> V_31 ;
V_132 -> V_265 = V_266 ;
V_132 -> V_267 = V_268 ;
V_132 -> V_269 = V_270 ;
V_132 -> V_271 = V_132 -> V_272 ;
V_132 -> V_273 = V_274 ;
F_102 ( & V_2 -> V_235 ) ;
F_103 ( & V_2 -> V_224 , F_76 ) ;
F_103 ( & V_2 -> V_225 , F_78 ) ;
V_135 = F_104 ( V_238 , F_84 , V_275 , V_276 , V_2 ) ;
if ( V_135 ) {
F_48 ( V_2 -> V_27 , L_21 ) ;
goto V_277;
}
V_135 = F_105 ( V_132 , V_132 -> V_263 ) ;
if ( V_135 ) {
F_48 ( V_2 -> V_27 , L_22 ) ;
goto V_278;
}
V_135 = F_106 ( V_132 , V_2 -> V_27 ) ;
if ( V_135 ) {
F_48 ( V_2 -> V_27 , L_23 ) ;
goto V_278;
}
V_135 = F_59 ( V_2 ) ;
if ( V_135 ) {
F_48 ( V_2 -> V_27 , L_24 ) ;
goto V_279;
}
* V_258 = V_2 ;
return 0 ;
V_279:
F_98 ( V_2 -> V_132 ) ;
V_278:
F_107 ( V_238 , V_2 ) ;
V_277:
F_12 ( V_2 ) ;
V_262:
F_99 ( V_132 ) ;
V_260:
return V_135 ;
}

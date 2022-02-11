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
F_39 ( V_8 -> V_85 -> V_125 ) ;
memcpy ( V_105 -> V_126 ,
V_8 -> V_85 -> V_127 ,
( F_26 (unsigned short,
lrbp->cmd->cmd_len,
MAX_CDB_SIZE) ) ) ;
break;
case V_128 :
break;
case V_129 :
break;
}
}
static int F_41 ( struct V_130 * V_131 , struct V_84 * V_85 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 ;
unsigned long V_132 ;
int V_133 ;
int V_134 = 0 ;
V_2 = F_42 ( V_131 ) ;
V_133 = V_85 -> V_135 -> V_133 ;
if ( V_2 -> V_136 != V_137 ) {
V_134 = V_138 ;
goto V_139;
}
V_8 = & V_2 -> V_25 [ V_133 ] ;
V_8 -> V_85 = V_85 ;
V_8 -> V_140 = V_65 ;
V_8 -> V_62 = V_85 -> V_62 ;
V_8 -> V_58 = V_133 ;
V_8 -> V_122 = V_85 -> V_141 -> V_122 ;
V_8 -> V_108 = V_109 ;
F_38 ( V_8 ) ;
V_134 = F_29 ( V_8 ) ;
if ( V_134 )
goto V_139;
F_43 ( V_2 -> V_131 -> V_142 , V_132 ) ;
F_22 ( V_2 , V_133 ) ;
F_44 ( V_2 -> V_131 -> V_142 , V_132 ) ;
V_139:
return V_134 ;
}
static int F_45 ( struct V_1 * V_2 )
{
T_2 V_22 , V_23 , V_24 ;
V_24 = ( sizeof( struct V_34 ) * V_2 -> V_31 ) ;
V_2 -> V_33 = F_46 ( V_2 -> V_27 ,
V_24 ,
& V_2 -> V_35 ,
V_143 ) ;
if ( ! V_2 -> V_33 ||
F_47 ( V_2 -> V_35 & ( V_144 - 1 ) ) ) {
F_48 ( V_2 -> V_27 ,
L_1 ) ;
goto V_139;
}
V_23 = ( sizeof( struct V_30 ) * V_2 -> V_31 ) ;
V_2 -> V_29 = F_46 ( V_2 -> V_27 ,
V_23 ,
& V_2 -> V_32 ,
V_143 ) ;
if ( ! V_2 -> V_29 ||
F_47 ( V_2 -> V_32 & ( V_144 - 1 ) ) ) {
F_48 ( V_2 -> V_27 ,
L_2 ) ;
goto V_139;
}
V_22 = sizeof( struct V_13 ) * V_2 -> V_16 ;
V_2 -> V_26 = F_46 ( V_2 -> V_27 ,
V_22 ,
& V_2 -> V_28 ,
V_143 ) ;
if ( ! V_2 -> V_26 ||
F_47 ( V_2 -> V_28 & ( V_144 - 1 ) ) ) {
F_48 ( V_2 -> V_27 ,
L_3 ) ;
goto V_139;
}
V_2 -> V_25 = F_49 ( V_2 -> V_31 , sizeof( struct V_7 ) , V_143 ) ;
if ( ! V_2 -> V_25 ) {
F_48 ( V_2 -> V_27 , L_4 ) ;
goto V_139;
}
return 0 ;
V_139:
F_12 ( V_2 ) ;
return - V_145 ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_34 * V_146 ;
struct V_30 * V_147 ;
T_3 V_148 ;
T_3 V_149 ;
V_89 V_150 ;
V_89 V_151 ;
int V_152 ;
int V_87 ;
V_147 = V_2 -> V_29 ;
V_146 = V_2 -> V_33 ;
V_150 =
F_51 ( struct V_34 , V_153 ) ;
V_151 =
F_51 ( struct V_34 , V_81 ) ;
V_152 = sizeof( struct V_34 ) ;
V_148 = V_2 -> V_35 ;
for ( V_87 = 0 ; V_87 < V_2 -> V_31 ; V_87 ++ ) {
V_149 =
( V_148 + ( V_152 * V_87 ) ) ;
V_147 [ V_87 ] . V_154 =
F_33 ( F_35 ( V_149 ) ) ;
V_147 [ V_87 ] . V_155 =
F_33 ( F_36 ( V_149 ) ) ;
V_147 [ V_87 ] . V_156 =
F_31 ( ( V_150 >> 2 ) ) ;
V_147 [ V_87 ] . V_157 =
F_31 ( ( V_151 >> 2 ) ) ;
V_147 [ V_87 ] . V_158 =
F_31 ( V_159 ) ;
V_2 -> V_25 [ V_87 ] . V_9 = ( V_147 + V_87 ) ;
V_2 -> V_25 [ V_87 ] . V_105 =
(struct V_104 * ) ( V_146 + V_87 ) ;
V_2 -> V_25 [ V_87 ] . V_37 =
(struct V_36 * ) V_146 [ V_87 ] . V_153 ;
V_2 -> V_25 [ V_87 ] . V_90 =
(struct V_80 * ) V_146 [ V_87 ] . V_81 ;
}
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_70 * V_160 ;
unsigned long V_132 ;
if ( ( ( F_2 ( V_2 -> V_3 + V_161 ) ) &
V_162 ) == 0x0 ) {
F_48 ( V_2 -> V_27 ,
L_5
L_6 ) ;
return - V_163 ;
}
F_43 ( V_2 -> V_131 -> V_142 , V_132 ) ;
V_160 = & V_2 -> V_164 ;
V_160 -> V_77 = V_165 ;
V_160 -> V_72 = 0 ;
V_160 -> V_74 = 0 ;
V_160 -> V_75 = 0 ;
V_2 -> V_96 |= V_166 ;
F_37 ( V_2 , V_95 ) ;
F_28 ( V_2 , V_160 ) ;
F_44 ( V_2 -> V_131 -> V_142 , V_132 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
int V_134 = 0 ;
T_1 V_19 ;
V_19 = F_2 ( ( V_2 -> V_3 + V_161 ) ) ;
if ( ! F_3 ( V_19 ) ) {
F_48 ( V_2 -> V_27 , L_7 ) ;
V_134 = - V_167 ;
goto V_139;
}
if ( ! ( F_10 ( V_19 ) ) ) {
F_19 ( V_2 ) ;
} else {
F_48 ( V_2 -> V_27 ,
L_8 ) ;
V_134 = - V_163 ;
goto V_139;
}
V_2 -> V_96 |= ( V_168 |
V_169 |
V_170 |
V_171 |
V_172 |
V_173 ) ;
F_37 ( V_2 , V_95 ) ;
F_18 ( V_2 , V_48 ) ;
if ( V_2 -> V_136 == V_174 )
F_54 ( V_2 -> V_131 ) ;
V_2 -> V_136 = V_137 ;
F_55 ( V_2 -> V_131 ) ;
V_139:
return V_134 ;
}
static int F_56 ( struct V_1 * V_2 )
{
int V_175 ;
if ( ! F_21 ( V_2 ) ) {
F_57 ( V_2 ) ;
F_58 ( 5 ) ;
}
F_20 ( V_2 ) ;
F_58 ( 1 ) ;
V_175 = 10 ;
while ( F_21 ( V_2 ) ) {
if ( V_175 ) {
V_175 -- ;
} else {
F_48 ( V_2 -> V_27 ,
L_9 ) ;
return - V_163 ;
}
F_58 ( 5 ) ;
}
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
if ( F_56 ( V_2 ) )
return - V_163 ;
F_9 ( F_35 ( V_2 -> V_32 ) ,
( V_2 -> V_3 + V_176 ) ) ;
F_9 ( F_36 ( V_2 -> V_32 ) ,
( V_2 -> V_3 + V_177 ) ) ;
F_9 ( F_35 ( V_2 -> V_28 ) ,
( V_2 -> V_3 + V_178 ) ) ;
F_9 ( F_36 ( V_2 -> V_28 ) ,
( V_2 -> V_3 + V_179 ) ) ;
return F_52 ( V_2 ) ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
unsigned long V_132 ;
int V_133 ;
F_61 ( V_2 -> V_131 ) ;
F_43 ( V_2 -> V_131 -> V_142 , V_132 ) ;
V_2 -> V_136 = V_174 ;
F_57 ( V_2 ) ;
F_44 ( V_2 -> V_131 -> V_142 , V_132 ) ;
for ( V_133 = 0 ; V_133 < V_2 -> V_31 ; V_133 ++ ) {
if ( F_62 ( V_133 , & V_2 -> V_59 ) ) {
V_8 = & V_2 -> V_25 [ V_133 ] ;
F_63 ( V_8 -> V_85 ) ;
V_8 -> V_85 -> V_180 = V_181 << 16 ;
V_8 -> V_85 -> V_182 ( V_8 -> V_85 ) ;
V_8 -> V_85 = NULL ;
}
}
V_2 -> V_59 = 0 ;
V_2 -> V_15 = 0 ;
if ( F_59 ( V_2 ) ) {
F_48 ( V_2 -> V_27 ,
L_10 ) ;
return V_183 ;
}
return V_184 ;
}
static int F_64 ( struct V_185 * V_186 )
{
struct V_1 * V_2 ;
V_2 = F_42 ( V_186 -> V_131 ) ;
V_186 -> V_187 = 1 ;
V_186 -> V_188 = 1 ;
F_65 ( V_186 , V_189 ) ;
F_66 ( V_186 , V_2 -> V_31 ) ;
return 0 ;
}
static void F_67 ( struct V_185 * V_186 )
{
struct V_1 * V_2 ;
V_2 = F_42 ( V_186 -> V_131 ) ;
F_68 ( V_186 , V_2 -> V_31 ) ;
}
static int F_69 ( struct V_1 * V_2 , T_1 V_190 )
{
struct V_13 * V_14 ;
struct V_191 * V_192 ;
unsigned long V_132 ;
int V_193 ;
int V_194 ;
F_43 ( V_2 -> V_131 -> V_142 , V_132 ) ;
F_70 ( V_190 , & V_2 -> V_15 ) ;
V_14 = V_2 -> V_26 ;
V_193 = F_5 ( & V_14 [ V_190 ] ) ;
if ( V_193 == V_195 ) {
V_192 = (struct V_191 * )
V_14 [ V_190 ] . V_196 ;
V_194 = F_16 ( V_192 -> V_10 . V_41 ) ;
V_194 = ( ( V_194 & V_197 ) >> 8 ) ;
if ( V_194 != V_198 &&
V_194 != V_199 )
V_194 = V_183 ;
else
V_194 = V_184 ;
} else {
V_194 = V_183 ;
F_48 ( V_2 -> V_27 ,
L_11 , V_193 ) ;
}
F_44 ( V_2 -> V_131 -> V_142 , V_132 ) ;
return V_194 ;
}
static void F_71 ( struct V_84 * V_85 )
{
struct V_1 * V_2 ;
int V_87 ;
int V_200 = 0 ;
V_2 = F_42 ( V_85 -> V_141 -> V_131 ) ;
for ( V_87 = 0 ; V_87 < V_2 -> V_31 ; V_87 ++ ) {
if ( F_62 ( V_87 , & V_2 -> V_59 ) ) {
if ( V_85 -> V_141 -> V_122 == V_2 -> V_25 [ V_87 ] . V_122 )
V_200 ++ ;
}
}
F_72 ( V_85 -> V_141 , V_189 , V_200 - 1 ) ;
}
static inline int
F_73 ( struct V_7 * V_8 , int V_201 )
{
int V_180 = 0 ;
switch ( V_201 ) {
case V_202 :
V_180 |= V_203 << 16 |
V_204 << 8 |
V_202 ;
break;
case V_205 :
V_180 |= V_203 << 16 |
V_204 << 8 |
V_205 ;
F_24 ( V_8 ) ;
break;
case V_206 :
V_180 |= V_206 ;
break;
case V_207 :
F_71 ( V_8 -> V_85 ) ;
V_180 |= V_207 ;
break;
case V_208 :
V_180 |= V_208 ;
break;
default:
V_180 |= V_40 << 16 ;
break;
}
return V_180 ;
}
static inline int
F_74 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
int V_180 = 0 ;
int V_201 ;
int V_209 ;
V_209 = F_4 ( V_8 ) ;
switch ( V_209 ) {
case V_195 :
V_180 = F_15 ( V_8 -> V_37 ) ;
if ( V_180 ) {
F_48 ( V_2 -> V_27 ,
L_12 , V_180 ) ;
break;
}
V_180 = F_17 ( V_8 -> V_37 ) ;
V_201 = V_180 & V_210 ;
V_180 = F_73 ( V_8 , V_201 ) ;
break;
case V_211 :
V_180 |= V_212 << 16 ;
break;
case V_213 :
case V_214 :
case V_215 :
case V_216 :
case V_217 :
case V_218 :
default:
V_180 |= V_40 << 16 ;
F_48 ( V_2 -> V_27 ,
L_13 , V_209 ) ;
break;
}
return V_180 ;
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_7 * V_25 ;
unsigned long V_219 ;
T_1 V_220 ;
int V_180 ;
int V_190 ;
V_25 = V_2 -> V_25 ;
V_220 =
F_2 ( V_2 -> V_3 + V_60 ) ;
V_219 = V_220 ^ V_2 -> V_59 ;
for ( V_190 = 0 ; V_190 < V_2 -> V_31 ; V_190 ++ ) {
if ( F_62 ( V_190 , & V_219 ) ) {
V_180 = F_74 ( V_2 , & V_25 [ V_190 ] ) ;
if ( V_25 [ V_190 ] . V_85 ) {
F_63 ( V_25 [ V_190 ] . V_85 ) ;
V_25 [ V_190 ] . V_85 -> V_180 = V_180 ;
V_25 [ V_190 ] . V_85 -> V_182 ( V_25 [ V_190 ] . V_85 ) ;
V_25 [ V_190 ] . V_85 = NULL ;
}
}
}
V_2 -> V_59 ^= V_219 ;
F_18 ( V_2 , V_44 ) ;
}
static void F_76 ( struct V_221 * V_222 )
{
struct V_1 * V_2 ;
V_2 = F_77 ( V_222 , struct V_1 , V_223 ) ;
if ( ( V_2 -> V_164 . V_77 == V_165 ) &&
! ( F_11 ( V_2 ) ) ) {
if ( F_53 ( V_2 ) )
F_48 ( V_2 -> V_27 ,
L_14 ) ;
return;
}
}
static void F_78 ( struct V_221 * V_222 )
{
struct V_1 * V_2 ;
V_2 = F_77 ( V_222 , struct V_1 , V_224 ) ;
if ( V_2 -> V_136 != V_174 )
F_60 ( V_2 ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
T_1 V_19 ;
if ( V_2 -> V_225 & V_226 )
goto V_227;
if ( V_2 -> V_225 & V_169 ) {
V_19 = F_2 ( V_2 -> V_3 +
V_228 ) ;
if ( V_19 & V_229 )
goto V_227;
}
return;
V_227:
V_2 -> V_136 = V_230 ;
F_80 ( & V_2 -> V_224 ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
T_1 V_231 ;
V_231 = F_2 ( V_2 -> V_3 + V_232 ) ;
V_2 -> V_233 = V_231 ^ V_2 -> V_15 ;
F_82 ( & V_2 -> V_234 ) ;
}
static void F_83 ( struct V_1 * V_2 , T_1 V_235 )
{
V_2 -> V_225 = V_236 & V_235 ;
if ( V_2 -> V_225 )
F_79 ( V_2 ) ;
if ( V_235 & V_166 )
F_80 ( & V_2 -> V_223 ) ;
if ( V_235 & V_170 )
F_81 ( V_2 ) ;
if ( V_235 & V_168 )
F_75 ( V_2 ) ;
}
static T_4 F_84 ( int V_237 , void * V_238 )
{
T_1 V_235 ;
T_4 V_239 = V_240 ;
struct V_1 * V_2 = V_238 ;
F_85 ( V_2 -> V_131 -> V_142 ) ;
V_235 = F_2 ( V_2 -> V_3 + V_241 ) ;
if ( V_235 ) {
F_83 ( V_2 , V_235 ) ;
if ( V_2 -> V_99 == V_100 )
F_9 ( V_235 ,
( V_2 -> V_3 + V_241 ) ) ;
V_239 = V_242 ;
}
F_86 ( V_2 -> V_131 -> V_142 ) ;
return V_239 ;
}
static int
F_87 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
T_5 V_243 )
{
struct V_13 * V_14 ;
struct V_244 * V_245 ;
struct V_130 * V_131 ;
unsigned long V_132 ;
int V_246 = 0 ;
int V_134 ;
V_131 = V_2 -> V_131 ;
F_43 ( V_131 -> V_142 , V_132 ) ;
V_246 = F_6 ( V_2 ) ;
if ( V_246 >= V_2 -> V_16 ) {
F_44 ( V_131 -> V_142 , V_132 ) ;
F_48 ( V_2 -> V_27 , L_15 ) ;
V_134 = V_183 ;
goto V_139;
}
V_14 = V_2 -> V_26 ;
V_14 += V_246 ;
V_14 -> V_10 . V_38 = F_33 ( V_247 ) ;
V_14 -> V_10 . V_11 =
F_33 ( V_120 ) ;
V_245 =
(struct V_244 * ) V_14 -> V_248 ;
V_245 -> V_10 . V_38 =
F_39 ( F_40 ( V_249 , 0 ,
V_8 -> V_122 , V_8 -> V_58 ) ) ;
V_245 -> V_10 . V_41 =
F_39 ( F_40 ( 0 , V_243 , 0 , 0 ) ) ;
V_245 -> V_250 = V_8 -> V_122 ;
V_245 -> V_250 =
F_39 ( V_245 -> V_250 ) ;
V_245 -> V_251 = V_8 -> V_58 ;
V_245 -> V_251 =
F_39 ( V_245 -> V_251 ) ;
F_23 ( V_246 , & V_2 -> V_15 ) ;
F_9 ( ( 1 << V_246 ) ,
( V_2 -> V_3 + V_232 ) ) ;
F_44 ( V_131 -> V_142 , V_132 ) ;
V_134 =
F_88 ( V_2 -> V_234 ,
( F_62 ( V_246 ,
& V_2 -> V_233 ) != 0 ) ,
60 * V_252 ) ;
if ( ! V_134 ) {
F_48 ( V_2 -> V_27 ,
L_16 ) ;
V_134 = V_183 ;
goto V_139;
}
F_89 ( V_246 , & V_2 -> V_233 ) ;
V_134 = F_69 ( V_2 , V_246 ) ;
V_139:
return V_134 ;
}
static int F_90 ( struct V_84 * V_85 )
{
struct V_130 * V_131 ;
struct V_1 * V_2 ;
unsigned int V_133 ;
T_1 V_17 ;
int V_134 ;
V_131 = V_85 -> V_141 -> V_131 ;
V_2 = F_42 ( V_131 ) ;
V_133 = V_85 -> V_135 -> V_133 ;
V_134 = F_87 ( V_2 , & V_2 -> V_25 [ V_133 ] , V_253 ) ;
if ( V_134 == V_183 )
goto V_139;
for ( V_17 = 0 ; V_17 < V_2 -> V_31 ; V_17 ++ ) {
if ( F_62 ( V_17 , & V_2 -> V_59 ) &&
( V_2 -> V_25 [ V_133 ] . V_122 == V_2 -> V_25 [ V_17 ] . V_122 ) ) {
F_8 ( V_2 , V_17 ) ;
F_89 ( V_17 , & V_2 -> V_59 ) ;
if ( V_2 -> V_25 [ V_17 ] . V_85 ) {
F_63 ( V_2 -> V_25 [ V_17 ] . V_85 ) ;
V_2 -> V_25 [ V_17 ] . V_85 -> V_180 =
V_212 << 16 ;
V_2 -> V_25 [ V_17 ] . V_85 -> V_182 ( V_85 ) ;
V_2 -> V_25 [ V_17 ] . V_85 = NULL ;
}
}
}
V_139:
return V_134 ;
}
static int F_91 ( struct V_84 * V_85 )
{
struct V_1 * V_2 ;
V_2 = F_42 ( V_85 -> V_141 -> V_131 ) ;
if ( V_2 -> V_136 == V_174 )
return V_184 ;
return F_60 ( V_2 ) ;
}
static int F_92 ( struct V_84 * V_85 )
{
struct V_130 * V_131 ;
struct V_1 * V_2 ;
unsigned long V_132 ;
unsigned int V_133 ;
int V_134 ;
V_131 = V_85 -> V_141 -> V_131 ;
V_2 = F_42 ( V_131 ) ;
V_133 = V_85 -> V_135 -> V_133 ;
F_43 ( V_131 -> V_142 , V_132 ) ;
if ( ! ( F_62 ( V_133 , & V_2 -> V_59 ) ) ) {
V_134 = V_183 ;
F_44 ( V_131 -> V_142 , V_132 ) ;
goto V_139;
}
F_44 ( V_131 -> V_142 , V_132 ) ;
V_134 = F_87 ( V_2 , & V_2 -> V_25 [ V_133 ] , V_254 ) ;
if ( V_134 == V_183 )
goto V_139;
F_63 ( V_85 ) ;
F_43 ( V_131 -> V_142 , V_132 ) ;
F_8 ( V_2 , V_133 ) ;
F_70 ( V_133 , & V_2 -> V_59 ) ;
V_2 -> V_25 [ V_133 ] . V_85 = NULL ;
F_44 ( V_131 -> V_142 , V_132 ) ;
V_139:
return V_134 ;
}
int F_93 ( struct V_1 * V_2 , T_6 V_255 )
{
return - V_256 ;
}
int F_94 ( struct V_1 * V_2 )
{
return - V_256 ;
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
F_98 ( V_2 -> V_131 ) ;
F_99 ( V_2 -> V_131 ) ;
}
int F_100 ( struct V_141 * V_27 , struct V_1 * * V_257 ,
void T_7 * V_3 , unsigned int V_237 )
{
struct V_130 * V_131 ;
struct V_1 * V_2 ;
int V_134 ;
if ( ! V_27 ) {
F_48 ( V_27 ,
L_17 ) ;
V_134 = - V_258 ;
goto V_259;
}
if ( ! V_3 ) {
F_48 ( V_27 ,
L_18 ) ;
V_134 = - V_258 ;
goto V_259;
}
V_131 = F_101 ( & V_260 ,
sizeof( struct V_1 ) ) ;
if ( ! V_131 ) {
F_48 ( V_27 , L_19 ) ;
V_134 = - V_145 ;
goto V_259;
}
V_2 = F_42 ( V_131 ) ;
V_2 -> V_131 = V_131 ;
V_2 -> V_27 = V_27 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_237 = V_237 ;
F_27 ( V_2 ) ;
V_2 -> V_99 = F_1 ( V_2 ) ;
V_134 = F_45 ( V_2 ) ;
if ( V_134 ) {
F_48 ( V_2 -> V_27 , L_20 ) ;
goto V_261;
}
F_50 ( V_2 ) ;
V_131 -> V_262 = V_2 -> V_31 ;
V_131 -> V_263 = V_2 -> V_31 ;
V_131 -> V_264 = V_265 ;
V_131 -> V_266 = V_267 ;
V_131 -> V_268 = V_269 ;
V_131 -> V_270 = V_131 -> V_271 ;
V_131 -> V_272 = V_273 ;
F_102 ( & V_2 -> V_234 ) ;
F_103 ( & V_2 -> V_223 , F_76 ) ;
F_103 ( & V_2 -> V_224 , F_78 ) ;
V_134 = F_104 ( V_237 , F_84 , V_274 , V_275 , V_2 ) ;
if ( V_134 ) {
F_48 ( V_2 -> V_27 , L_21 ) ;
goto V_276;
}
V_134 = F_105 ( V_131 , V_131 -> V_262 ) ;
if ( V_134 ) {
F_48 ( V_2 -> V_27 , L_22 ) ;
goto V_277;
}
V_134 = F_106 ( V_131 , V_2 -> V_27 ) ;
if ( V_134 ) {
F_48 ( V_2 -> V_27 , L_23 ) ;
goto V_277;
}
V_134 = F_59 ( V_2 ) ;
if ( V_134 ) {
F_48 ( V_2 -> V_27 , L_24 ) ;
goto V_278;
}
* V_257 = V_2 ;
return 0 ;
V_278:
F_98 ( V_2 -> V_131 ) ;
V_277:
F_107 ( V_237 , V_2 ) ;
V_276:
F_12 ( V_2 ) ;
V_261:
F_99 ( V_131 ) ;
V_259:
return V_134 ;
}

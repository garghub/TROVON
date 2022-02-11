static inline T_1 F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 + V_4 ) ;
}
static inline int F_3 ( T_1 V_5 )
{
return ( V_6 & V_5 ) ? 0 : - 1 ;
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
F_14 ( & V_2 -> V_27 -> V_28 , V_22 ,
V_2 -> V_26 , V_2 -> V_29 ) ;
}
if ( V_2 -> V_30 ) {
V_23 =
( sizeof( struct V_31 ) * V_2 -> V_32 ) ;
F_14 ( & V_2 -> V_27 -> V_28 , V_23 ,
V_2 -> V_30 , V_2 -> V_33 ) ;
}
if ( V_2 -> V_34 ) {
V_24 =
( sizeof( struct V_35 ) * V_2 -> V_32 ) ;
F_14 ( & V_2 -> V_27 -> V_28 , V_24 ,
V_2 -> V_34 , V_2 -> V_36 ) ;
}
}
static inline int
F_15 ( struct V_37 * V_38 )
{
return ( ( F_16 ( V_38 -> V_10 . V_39 ) >> 24 ) ==
V_40 ) ? 0 : V_41 << 16 ;
}
static inline int
F_17 ( struct V_37 * V_38 )
{
return F_16 ( V_38 -> V_10 . V_42 ) & V_43 ;
}
static inline void
F_18 ( struct V_1 * V_2 , int V_44 )
{
switch ( V_44 ) {
case V_45 :
F_9 ( ( V_46 |
V_47 ) ,
( V_2 -> V_3 +
V_48 ) ) ;
break;
case V_49 :
F_9 ( ( V_46 |
V_50 |
V_51 |
V_52 ) ,
( V_2 -> V_3 +
V_48 ) ) ;
break;
}
}
static void F_19 ( struct V_1 * V_2 )
{
F_9 ( V_53 ,
( V_2 -> V_3 +
V_54 ) ) ;
F_9 ( V_55 ,
( V_2 -> V_3 +
V_56 ) ) ;
}
static inline void F_20 ( struct V_1 * V_2 )
{
F_9 ( V_57 , ( V_2 -> V_3 + V_58 ) ) ;
}
static inline void F_21 ( struct V_1 * V_2 )
{
F_9 ( V_59 , ( V_2 -> V_3 + V_58 ) ) ;
}
static inline int F_22 ( struct V_1 * V_2 )
{
return ( F_2 ( V_2 -> V_3 + V_58 ) & 0x1 ) ? 0 : 1 ;
}
static inline
void F_23 ( struct V_1 * V_2 , unsigned int V_60 )
{
F_24 ( V_60 , & V_2 -> V_61 ) ;
F_9 ( ( 1 << V_60 ) ,
( V_2 -> V_3 + V_62 ) ) ;
}
static inline void F_25 ( struct V_7 * V_8 )
{
int V_63 ;
if ( V_8 -> V_64 ) {
V_63 = F_26 ( V_8 -> V_38 -> V_65 ) ;
memcpy ( V_8 -> V_64 ,
V_8 -> V_38 -> V_66 ,
F_27 ( int , V_63 , V_67 ) ) ;
}
}
static inline void F_28 ( struct V_1 * V_2 )
{
V_2 -> V_68 =
F_2 ( V_2 -> V_3 + V_69 ) ;
V_2 -> V_32 = ( V_2 -> V_68 & V_70 ) + 1 ;
V_2 -> V_16 =
( ( V_2 -> V_68 & V_71 ) >> 16 ) + 1 ;
}
static inline void
F_29 ( struct V_1 * V_2 , struct V_72 * V_73 )
{
F_9 ( V_73 -> V_74 ,
( V_2 -> V_3 + V_75 ) ) ;
F_9 ( V_73 -> V_76 ,
( V_2 -> V_3 + V_20 ) ) ;
F_9 ( V_73 -> V_77 ,
( V_2 -> V_3 + V_78 ) ) ;
F_9 ( ( V_73 -> V_79 & V_80 ) ,
( V_2 -> V_3 + V_81 ) ) ;
}
static int F_30 ( struct V_7 * V_8 )
{
struct V_82 * V_83 ;
struct V_84 * V_85 ;
struct V_86 * V_87 ;
int V_88 ;
int V_89 ;
V_87 = V_8 -> V_87 ;
V_88 = F_31 ( V_87 ) ;
if ( V_88 < 0 )
return V_88 ;
if ( V_88 ) {
V_8 -> V_9 -> V_90 =
F_32 ( ( V_91 ) ( V_88 ) ) ;
V_83 = (struct V_82 * ) V_8 -> V_92 ;
F_33 (cmd, sg, sg_segments, i) {
V_83 [ V_89 ] . V_93 =
F_34 ( ( ( T_1 ) F_35 ( V_85 ) ) - 1 ) ;
V_83 [ V_89 ] . V_94 =
F_34 ( F_36 ( V_85 -> V_95 ) ) ;
V_83 [ V_89 ] . V_96 =
F_34 ( F_37 ( V_85 -> V_95 ) ) ;
}
} else {
V_8 -> V_9 -> V_90 = 0 ;
}
return 0 ;
}
static void F_38 ( struct V_1 * V_2 , T_1 V_44 )
{
switch ( V_44 ) {
case V_97 :
F_9 ( V_2 -> V_98 ,
( V_2 -> V_3 + V_99 ) ) ;
break;
case V_100 :
if ( V_2 -> V_101 == V_102 )
F_9 ( V_103 ,
( V_2 -> V_3 + V_99 ) ) ;
else
F_9 ( V_104 ,
( V_2 -> V_3 + V_99 ) ) ;
break;
}
}
static void F_39 ( struct V_7 * V_8 )
{
struct V_31 * V_105 ;
struct V_106 * V_107 ;
T_1 V_108 ;
T_1 V_109 ;
V_107 = V_8 -> V_107 ;
V_105 = V_8 -> V_9 ;
switch ( V_8 -> V_110 ) {
case V_111 :
if ( V_8 -> V_87 -> V_112 == V_113 ) {
V_108 = V_114 ;
V_109 = V_115 ;
} else if ( V_8 -> V_87 -> V_112 == V_116 ) {
V_108 = V_117 ;
V_109 = V_118 ;
} else {
V_108 = V_119 ;
V_109 = V_120 ;
}
V_105 -> V_10 . V_39 =
F_34 ( V_108 | V_121 ) ;
V_105 -> V_10 . V_11 =
F_34 ( V_122 ) ;
V_107 -> V_10 . V_39 =
F_40 ( F_41 ( V_123 ,
V_109 ,
V_8 -> V_124 ,
V_8 -> V_60 ) ) ;
V_107 -> V_10 . V_42 =
F_40 (
F_41 ( V_125 ,
0 ,
0 ,
0 ) ) ;
V_107 -> V_10 . V_11 = 0 ;
V_107 -> V_126 =
F_40 ( V_8 -> V_87 -> V_127 ) ;
memcpy ( V_107 -> V_128 ,
V_8 -> V_87 -> V_129 ,
( F_27 (unsigned short,
lrbp->cmd->cmd_len,
MAX_CDB_SIZE) ) ) ;
break;
case V_130 :
break;
case V_131 :
break;
}
}
static int F_42 ( struct V_132 * V_133 , struct V_86 * V_87 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 ;
unsigned long V_134 ;
int V_135 ;
int V_136 = 0 ;
V_2 = F_43 ( V_133 ) ;
V_135 = V_87 -> V_137 -> V_135 ;
if ( V_2 -> V_138 != V_139 ) {
V_136 = V_140 ;
goto V_141;
}
V_8 = & V_2 -> V_25 [ V_135 ] ;
V_8 -> V_87 = V_87 ;
V_8 -> V_142 = V_67 ;
V_8 -> V_64 = V_87 -> V_64 ;
V_8 -> V_60 = V_135 ;
V_8 -> V_124 = V_87 -> V_143 -> V_124 ;
V_8 -> V_110 = V_111 ;
F_39 ( V_8 ) ;
V_136 = F_30 ( V_8 ) ;
if ( V_136 )
goto V_141;
F_44 ( V_2 -> V_133 -> V_144 , V_134 ) ;
F_23 ( V_2 , V_135 ) ;
F_45 ( V_2 -> V_133 -> V_144 , V_134 ) ;
V_141:
return V_136 ;
}
static int F_46 ( struct V_1 * V_2 )
{
T_2 V_22 , V_23 , V_24 ;
V_24 = ( sizeof( struct V_35 ) * V_2 -> V_32 ) ;
V_2 -> V_34 = F_47 ( & V_2 -> V_27 -> V_28 ,
V_24 ,
& V_2 -> V_36 ,
V_145 ) ;
if ( ! V_2 -> V_34 ||
F_48 ( V_2 -> V_36 & ( V_146 - 1 ) ) ) {
F_49 ( & V_2 -> V_27 -> V_28 ,
L_1 ) ;
goto V_141;
}
V_23 = ( sizeof( struct V_31 ) * V_2 -> V_32 ) ;
V_2 -> V_30 = F_47 ( & V_2 -> V_27 -> V_28 ,
V_23 ,
& V_2 -> V_33 ,
V_145 ) ;
if ( ! V_2 -> V_30 ||
F_48 ( V_2 -> V_33 & ( V_146 - 1 ) ) ) {
F_49 ( & V_2 -> V_27 -> V_28 ,
L_2 ) ;
goto V_141;
}
V_22 = sizeof( struct V_13 ) * V_2 -> V_16 ;
V_2 -> V_26 = F_47 ( & V_2 -> V_27 -> V_28 ,
V_22 ,
& V_2 -> V_29 ,
V_145 ) ;
if ( ! V_2 -> V_26 ||
F_48 ( V_2 -> V_29 & ( V_146 - 1 ) ) ) {
F_49 ( & V_2 -> V_27 -> V_28 ,
L_3 ) ;
goto V_141;
}
V_2 -> V_25 = F_50 ( V_2 -> V_32 , sizeof( struct V_7 ) , V_145 ) ;
if ( ! V_2 -> V_25 ) {
F_49 ( & V_2 -> V_27 -> V_28 , L_4 ) ;
goto V_141;
}
return 0 ;
V_141:
F_12 ( V_2 ) ;
return - V_147 ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_35 * V_148 ;
struct V_31 * V_149 ;
T_3 V_150 ;
T_3 V_151 ;
V_91 V_152 ;
V_91 V_153 ;
int V_154 ;
int V_89 ;
V_149 = V_2 -> V_30 ;
V_148 = V_2 -> V_34 ;
V_152 =
F_52 ( struct V_35 , V_155 ) ;
V_153 =
F_52 ( struct V_35 , V_83 ) ;
V_154 = sizeof( struct V_35 ) ;
V_150 = V_2 -> V_36 ;
for ( V_89 = 0 ; V_89 < V_2 -> V_32 ; V_89 ++ ) {
V_151 =
( V_150 + ( V_154 * V_89 ) ) ;
V_149 [ V_89 ] . V_156 =
F_34 ( F_36 ( V_151 ) ) ;
V_149 [ V_89 ] . V_157 =
F_34 ( F_37 ( V_151 ) ) ;
V_149 [ V_89 ] . V_158 =
F_32 ( ( V_152 >> 2 ) ) ;
V_149 [ V_89 ] . V_159 =
F_32 ( ( V_153 >> 2 ) ) ;
V_149 [ V_89 ] . V_160 =
F_32 ( V_161 ) ;
V_2 -> V_25 [ V_89 ] . V_9 = ( V_149 + V_89 ) ;
V_2 -> V_25 [ V_89 ] . V_107 =
(struct V_106 * ) ( V_148 + V_89 ) ;
V_2 -> V_25 [ V_89 ] . V_38 =
(struct V_37 * ) V_148 [ V_89 ] . V_155 ;
V_2 -> V_25 [ V_89 ] . V_92 =
(struct V_82 * ) V_148 [ V_89 ] . V_83 ;
}
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_72 * V_162 ;
unsigned long V_134 ;
if ( ( ( F_2 ( V_2 -> V_3 + V_163 ) ) &
V_164 ) == 0x0 ) {
F_49 ( & V_2 -> V_27 -> V_28 ,
L_5
L_6 ) ;
return - V_165 ;
}
F_44 ( V_2 -> V_133 -> V_144 , V_134 ) ;
V_162 = & V_2 -> V_166 ;
V_162 -> V_79 = V_167 ;
V_162 -> V_74 = 0 ;
V_162 -> V_76 = 0 ;
V_162 -> V_77 = 0 ;
V_2 -> V_98 |= V_168 ;
F_38 ( V_2 , V_97 ) ;
F_29 ( V_2 , V_162 ) ;
F_45 ( V_2 -> V_133 -> V_144 , V_134 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
int V_136 = 0 ;
T_1 V_19 ;
V_19 = F_2 ( ( V_2 -> V_3 + V_163 ) ) ;
if ( F_3 ( V_19 ) ) {
F_49 ( & V_2 -> V_27 -> V_28 , L_7 ) ;
V_136 = - V_169 ;
goto V_141;
}
if ( ! ( F_10 ( V_19 ) ) ) {
F_19 ( V_2 ) ;
} else {
F_49 ( & V_2 -> V_27 -> V_28 ,
L_8 ) ;
V_136 = - V_165 ;
goto V_141;
}
V_2 -> V_98 |= ( V_170 |
V_171 |
V_172 |
V_173 |
V_174 |
V_175 ) ;
F_38 ( V_2 , V_97 ) ;
F_18 ( V_2 , V_49 ) ;
if ( V_2 -> V_138 == V_176 )
F_55 ( V_2 -> V_133 ) ;
V_2 -> V_138 = V_139 ;
F_56 ( V_2 -> V_133 ) ;
V_141:
return V_136 ;
}
static int F_57 ( struct V_1 * V_2 )
{
int V_177 ;
if ( ! F_22 ( V_2 ) ) {
F_20 ( V_2 ) ;
F_58 ( 5 ) ;
}
F_21 ( V_2 ) ;
F_58 ( 1 ) ;
V_177 = 10 ;
while ( F_22 ( V_2 ) ) {
if ( V_177 ) {
V_177 -- ;
} else {
F_49 ( & V_2 -> V_27 -> V_28 ,
L_9 ) ;
return - V_165 ;
}
F_58 ( 5 ) ;
}
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
if ( F_57 ( V_2 ) )
return - V_165 ;
F_9 ( F_36 ( V_2 -> V_33 ) ,
( V_2 -> V_3 + V_178 ) ) ;
F_9 ( F_37 ( V_2 -> V_33 ) ,
( V_2 -> V_3 + V_179 ) ) ;
F_9 ( F_36 ( V_2 -> V_29 ) ,
( V_2 -> V_3 + V_180 ) ) ;
F_9 ( F_37 ( V_2 -> V_29 ) ,
( V_2 -> V_3 + V_181 ) ) ;
return F_53 ( V_2 ) ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
unsigned long V_134 ;
int V_135 ;
F_61 ( V_2 -> V_133 ) ;
F_44 ( V_2 -> V_133 -> V_144 , V_134 ) ;
V_2 -> V_138 = V_176 ;
F_20 ( V_2 ) ;
F_45 ( V_2 -> V_133 -> V_144 , V_134 ) ;
for ( V_135 = 0 ; V_135 < V_2 -> V_32 ; V_135 ++ ) {
if ( F_62 ( V_135 , & V_2 -> V_61 ) ) {
V_8 = & V_2 -> V_25 [ V_135 ] ;
F_63 ( V_8 -> V_87 ) ;
V_8 -> V_87 -> V_182 = V_183 << 16 ;
V_8 -> V_87 -> V_184 ( V_8 -> V_87 ) ;
V_8 -> V_87 = NULL ;
}
}
V_2 -> V_61 = 0 ;
V_2 -> V_15 = 0 ;
if ( F_59 ( V_2 ) ) {
F_49 ( & V_2 -> V_27 -> V_28 ,
L_10 ) ;
return V_185 ;
}
return V_186 ;
}
static int F_64 ( struct V_187 * V_188 )
{
struct V_1 * V_2 ;
V_2 = F_43 ( V_188 -> V_133 ) ;
V_188 -> V_189 = 1 ;
V_188 -> V_190 = 1 ;
F_65 ( V_188 , V_191 ) ;
F_66 ( V_188 , V_2 -> V_32 ) ;
return 0 ;
}
static void F_67 ( struct V_187 * V_188 )
{
struct V_1 * V_2 ;
V_2 = F_43 ( V_188 -> V_133 ) ;
F_68 ( V_188 , V_2 -> V_32 ) ;
}
static int F_69 ( struct V_1 * V_2 , T_1 V_192 )
{
struct V_13 * V_14 ;
struct V_193 * V_194 ;
unsigned long V_134 ;
int V_195 ;
int V_196 ;
F_44 ( V_2 -> V_133 -> V_144 , V_134 ) ;
F_70 ( V_192 , & V_2 -> V_15 ) ;
V_14 = V_2 -> V_26 ;
V_195 = F_5 ( & V_14 [ V_192 ] ) ;
if ( V_195 == V_197 ) {
V_194 = (struct V_193 * )
V_14 [ V_192 ] . V_198 ;
V_196 = F_16 ( V_194 -> V_10 . V_42 ) ;
V_196 = ( ( V_196 & V_199 ) >> 8 ) ;
if ( V_196 != V_200 &&
V_196 != V_201 )
V_196 = V_185 ;
} else {
V_196 = V_185 ;
F_49 ( & V_2 -> V_27 -> V_28 ,
L_11 , V_195 ) ;
}
F_45 ( V_2 -> V_133 -> V_144 , V_134 ) ;
return V_196 ;
}
static void F_71 ( struct V_86 * V_87 )
{
struct V_1 * V_2 ;
int V_89 ;
int V_202 = 0 ;
V_2 = F_43 ( V_87 -> V_143 -> V_133 ) ;
for ( V_89 = 0 ; V_89 < V_2 -> V_32 ; V_89 ++ ) {
if ( F_62 ( V_89 , & V_2 -> V_61 ) ) {
if ( V_87 -> V_143 -> V_124 == V_2 -> V_25 [ V_89 ] . V_124 )
V_202 ++ ;
}
}
F_72 ( V_87 -> V_143 , V_191 , V_202 - 1 ) ;
}
static inline int
F_73 ( struct V_7 * V_8 , int V_203 )
{
int V_182 = 0 ;
switch ( V_203 ) {
case V_204 :
V_182 |= V_205 << 16 |
V_206 << 8 |
V_204 ;
break;
case V_207 :
V_182 |= V_205 << 16 |
V_206 << 8 |
V_207 ;
F_25 ( V_8 ) ;
break;
case V_208 :
V_182 |= V_208 ;
break;
case V_209 :
F_71 ( V_8 -> V_87 ) ;
V_182 |= V_209 ;
break;
case V_210 :
V_182 |= V_210 ;
break;
default:
V_182 |= V_41 << 16 ;
break;
}
return V_182 ;
}
static inline int
F_74 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
int V_182 = 0 ;
int V_203 ;
int V_211 ;
V_211 = F_4 ( V_8 ) ;
switch ( V_211 ) {
case V_197 :
V_182 = F_15 ( V_8 -> V_38 ) ;
if ( V_182 ) {
F_49 ( & V_2 -> V_27 -> V_28 ,
L_12 , V_182 ) ;
break;
}
V_182 = F_17 ( V_8 -> V_38 ) ;
V_203 = V_182 & V_212 ;
V_182 = F_73 ( V_8 , V_203 ) ;
break;
case V_213 :
V_182 |= V_214 << 16 ;
break;
case V_215 :
case V_216 :
case V_217 :
case V_218 :
case V_219 :
case V_220 :
default:
V_182 |= V_41 << 16 ;
F_49 ( & V_2 -> V_27 -> V_28 ,
L_13 , V_211 ) ;
break;
}
return V_182 ;
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_7 * V_25 ;
unsigned long V_221 ;
T_1 V_222 ;
int V_182 ;
int V_192 ;
V_25 = V_2 -> V_25 ;
V_222 =
F_2 ( V_2 -> V_3 + V_62 ) ;
V_221 = V_222 ^ V_2 -> V_61 ;
for ( V_192 = 0 ; V_192 < V_2 -> V_32 ; V_192 ++ ) {
if ( F_62 ( V_192 , & V_221 ) ) {
V_182 = F_74 ( V_2 , & V_25 [ V_192 ] ) ;
if ( V_25 [ V_192 ] . V_87 ) {
F_63 ( V_25 [ V_192 ] . V_87 ) ;
V_25 [ V_192 ] . V_87 -> V_182 = V_182 ;
V_25 [ V_192 ] . V_87 -> V_184 ( V_25 [ V_192 ] . V_87 ) ;
V_25 [ V_192 ] . V_87 = NULL ;
}
}
}
V_2 -> V_61 ^= V_221 ;
F_18 ( V_2 , V_45 ) ;
}
static void F_76 ( struct V_223 * V_224 )
{
struct V_1 * V_2 ;
V_2 = F_77 ( V_224 , struct V_1 , V_225 ) ;
if ( ( V_2 -> V_166 . V_79 == V_167 ) &&
! ( F_11 ( V_2 ) ) ) {
if ( F_54 ( V_2 ) )
F_49 ( & V_2 -> V_27 -> V_28 ,
L_14 ) ;
return;
}
}
static void F_78 ( struct V_223 * V_224 )
{
struct V_1 * V_2 ;
V_2 = F_77 ( V_224 , struct V_1 , V_226 ) ;
if ( V_2 -> V_138 != V_176 )
F_60 ( V_2 ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
T_1 V_19 ;
if ( V_2 -> V_227 & V_228 )
goto V_229;
if ( V_2 -> V_227 & V_171 ) {
V_19 = F_2 ( V_2 -> V_3 +
V_230 ) ;
if ( V_19 & V_231 )
goto V_229;
}
return;
V_229:
V_2 -> V_138 = V_232 ;
F_80 ( & V_2 -> V_226 ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
T_1 V_233 ;
V_233 = F_2 ( V_2 -> V_3 + V_234 ) ;
V_2 -> V_235 = V_233 ^ V_2 -> V_15 ;
F_82 ( & V_2 -> V_236 ) ;
}
static void F_83 ( struct V_1 * V_2 , T_1 V_237 )
{
V_2 -> V_227 = V_238 & V_237 ;
if ( V_2 -> V_227 )
F_79 ( V_2 ) ;
if ( V_237 & V_168 )
F_80 ( & V_2 -> V_225 ) ;
if ( V_237 & V_172 )
F_81 ( V_2 ) ;
if ( V_237 & V_170 )
F_75 ( V_2 ) ;
}
static T_4 F_84 ( int V_239 , void * V_240 )
{
T_1 V_237 ;
T_4 V_241 = V_242 ;
struct V_1 * V_2 = V_240 ;
F_85 ( V_2 -> V_133 -> V_144 ) ;
V_237 = F_2 ( V_2 -> V_3 + V_243 ) ;
if ( V_237 ) {
F_83 ( V_2 , V_237 ) ;
if ( V_2 -> V_101 == V_102 )
F_9 ( V_237 ,
( V_2 -> V_3 + V_243 ) ) ;
V_241 = V_244 ;
}
F_86 ( V_2 -> V_133 -> V_144 ) ;
return V_241 ;
}
static int
F_87 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
T_5 V_245 )
{
struct V_13 * V_14 ;
struct V_246 * V_247 ;
struct V_132 * V_133 ;
unsigned long V_134 ;
int V_248 = 0 ;
int V_136 ;
V_133 = V_2 -> V_133 ;
F_44 ( V_133 -> V_144 , V_134 ) ;
V_248 = F_6 ( V_2 ) ;
if ( V_248 >= V_2 -> V_16 ) {
F_45 ( V_133 -> V_144 , V_134 ) ;
F_49 ( & V_2 -> V_27 -> V_28 , L_15 ) ;
V_136 = V_185 ;
goto V_141;
}
V_14 = V_2 -> V_26 ;
V_14 += V_248 ;
V_14 -> V_10 . V_39 = F_34 ( V_249 ) ;
V_14 -> V_10 . V_11 =
F_34 ( V_122 ) ;
V_247 =
(struct V_246 * ) V_14 -> V_250 ;
V_247 -> V_10 . V_39 =
F_40 ( F_41 ( V_251 , 0 ,
V_8 -> V_124 , V_8 -> V_60 ) ) ;
V_247 -> V_10 . V_42 =
F_40 ( F_41 ( 0 , V_245 , 0 , 0 ) ) ;
V_247 -> V_252 = V_8 -> V_124 ;
V_247 -> V_252 =
F_40 ( V_247 -> V_252 ) ;
V_247 -> V_253 = V_8 -> V_60 ;
V_247 -> V_253 =
F_40 ( V_247 -> V_253 ) ;
F_24 ( V_248 , & V_2 -> V_15 ) ;
F_9 ( ( 1 << V_248 ) ,
( V_2 -> V_3 + V_234 ) ) ;
F_45 ( V_133 -> V_144 , V_134 ) ;
V_136 =
F_88 ( V_2 -> V_236 ,
( F_62 ( V_248 ,
& V_2 -> V_235 ) != 0 ) ,
60 * V_254 ) ;
if ( ! V_136 ) {
F_49 ( & V_2 -> V_27 -> V_28 ,
L_16 ) ;
V_136 = V_185 ;
goto V_141;
}
F_89 ( V_248 , & V_2 -> V_235 ) ;
return F_69 ( V_2 , V_248 ) ;
V_141:
return V_136 ;
}
static int F_90 ( struct V_86 * V_87 )
{
struct V_132 * V_133 ;
struct V_1 * V_2 ;
unsigned int V_135 ;
T_1 V_17 ;
int V_136 ;
V_133 = V_87 -> V_143 -> V_133 ;
V_2 = F_43 ( V_133 ) ;
V_135 = V_87 -> V_137 -> V_135 ;
V_136 = F_87 ( V_2 , & V_2 -> V_25 [ V_135 ] , V_255 ) ;
if ( V_136 )
goto V_141;
for ( V_17 = 0 ; V_17 < V_2 -> V_32 ; V_17 ++ ) {
if ( F_62 ( V_17 , & V_2 -> V_61 ) &&
( V_2 -> V_25 [ V_135 ] . V_124 == V_2 -> V_25 [ V_17 ] . V_124 ) ) {
F_8 ( V_2 , V_17 ) ;
F_89 ( V_17 , & V_2 -> V_61 ) ;
if ( V_2 -> V_25 [ V_17 ] . V_87 ) {
F_63 ( V_2 -> V_25 [ V_17 ] . V_87 ) ;
V_2 -> V_25 [ V_17 ] . V_87 -> V_182 =
V_214 << 16 ;
V_2 -> V_25 [ V_17 ] . V_87 -> V_184 ( V_87 ) ;
V_2 -> V_25 [ V_17 ] . V_87 = NULL ;
}
}
}
V_141:
return V_136 ;
}
static int F_91 ( struct V_86 * V_87 )
{
struct V_1 * V_2 ;
V_2 = F_43 ( V_87 -> V_143 -> V_133 ) ;
if ( V_2 -> V_138 == V_176 )
return V_186 ;
return ( F_60 ( V_2 ) == V_186 ) ? V_186 : V_185 ;
}
static int F_92 ( struct V_86 * V_87 )
{
struct V_132 * V_133 ;
struct V_1 * V_2 ;
unsigned long V_134 ;
unsigned int V_135 ;
int V_136 ;
V_133 = V_87 -> V_143 -> V_133 ;
V_2 = F_43 ( V_133 ) ;
V_135 = V_87 -> V_137 -> V_135 ;
F_44 ( V_133 -> V_144 , V_134 ) ;
if ( ! ( F_62 ( V_135 , & V_2 -> V_61 ) ) ) {
V_136 = V_185 ;
F_45 ( V_133 -> V_144 , V_134 ) ;
goto V_141;
}
F_45 ( V_133 -> V_144 , V_134 ) ;
V_136 = F_87 ( V_2 , & V_2 -> V_25 [ V_135 ] , V_256 ) ;
if ( V_136 )
goto V_141;
F_63 ( V_87 ) ;
F_44 ( V_133 -> V_144 , V_134 ) ;
F_8 ( V_2 , V_135 ) ;
F_70 ( V_135 , & V_2 -> V_61 ) ;
V_2 -> V_25 [ V_135 ] . V_87 = NULL ;
F_45 ( V_133 -> V_144 , V_134 ) ;
V_141:
return V_136 ;
}
static void F_93 ( struct V_257 * V_27 )
{
F_20 ( (struct V_1 * ) F_94 ( V_27 ) ) ;
}
static int F_95 ( struct V_257 * V_27 , T_6 V_258 )
{
return - V_259 ;
}
static int F_96 ( struct V_257 * V_27 )
{
return - V_259 ;
}
static void F_97 ( struct V_1 * V_2 )
{
F_98 ( V_2 -> V_3 ) ;
F_12 ( V_2 ) ;
F_99 ( V_2 -> V_27 ) ;
}
static void F_100 ( struct V_257 * V_27 )
{
struct V_1 * V_2 = F_94 ( V_27 ) ;
F_38 ( V_2 , V_100 ) ;
F_101 ( V_27 -> V_239 , V_2 ) ;
F_20 ( V_2 ) ;
F_97 ( V_2 ) ;
F_102 ( V_2 -> V_133 ) ;
F_103 ( V_2 -> V_133 ) ;
F_104 ( V_27 , NULL ) ;
F_105 ( V_27 ) ;
F_106 ( V_27 ) ;
}
static int F_107 ( struct V_1 * V_2 )
{
int V_136 ;
T_7 V_260 ;
if ( V_2 -> V_68 & V_261 )
V_260 = F_108 ( 64 ) ;
else
V_260 = F_108 ( 32 ) ;
V_136 = F_109 ( V_2 -> V_27 , V_260 ) ;
if ( V_136 )
return V_136 ;
V_136 = F_110 ( V_2 -> V_27 , V_260 ) ;
return V_136 ;
}
static int T_8
F_111 ( struct V_257 * V_27 , const struct V_262 * V_263 )
{
struct V_132 * V_133 ;
struct V_1 * V_2 ;
int V_136 ;
V_136 = F_112 ( V_27 ) ;
if ( V_136 ) {
F_49 ( & V_27 -> V_28 , L_17 ) ;
goto V_264;
}
F_113 ( V_27 ) ;
V_133 = F_114 ( & V_265 ,
sizeof( struct V_1 ) ) ;
if ( ! V_133 ) {
F_49 ( & V_27 -> V_28 , L_18 ) ;
V_136 = - V_147 ;
goto V_266;
}
V_2 = F_43 ( V_133 ) ;
V_136 = F_115 ( V_27 , V_267 ) ;
if ( V_136 < 0 ) {
F_49 ( & V_27 -> V_28 , L_19 ) ;
goto V_268;
}
V_2 -> V_3 = F_116 ( V_27 , 0 ) ;
if ( ! V_2 -> V_3 ) {
F_49 ( & V_27 -> V_28 , L_20 ) ;
V_136 = - V_147 ;
goto V_269;
}
V_2 -> V_133 = V_133 ;
V_2 -> V_27 = V_27 ;
F_28 ( V_2 ) ;
V_2 -> V_101 = F_1 ( V_2 ) ;
V_136 = F_107 ( V_2 ) ;
if ( V_136 ) {
F_49 ( & V_27 -> V_28 , L_21 ) ;
goto V_270;
}
V_136 = F_46 ( V_2 ) ;
if ( V_136 ) {
F_49 ( & V_27 -> V_28 , L_22 ) ;
goto V_270;
}
F_51 ( V_2 ) ;
V_133 -> V_271 = V_2 -> V_32 ;
V_133 -> V_272 = V_2 -> V_32 ;
V_133 -> V_273 = V_274 ;
V_133 -> V_275 = V_276 ;
V_133 -> V_277 = V_278 ;
V_133 -> V_279 = V_133 -> V_280 ;
V_133 -> V_281 = V_282 ;
F_117 ( & V_2 -> V_236 ) ;
F_118 ( & V_2 -> V_225 , F_76 ) ;
F_118 ( & V_2 -> V_226 , F_78 ) ;
V_136 = F_119 ( V_27 -> V_239 , F_84 , V_283 , V_267 , V_2 ) ;
if ( V_136 ) {
F_49 ( & V_27 -> V_28 , L_23 ) ;
goto V_284;
}
V_136 = F_120 ( V_133 , V_133 -> V_271 ) ;
if ( V_136 ) {
F_49 ( & V_27 -> V_28 , L_24 ) ;
goto V_285;
}
F_104 ( V_27 , V_2 ) ;
V_136 = F_121 ( V_133 , & V_27 -> V_28 ) ;
if ( V_136 ) {
F_49 ( & V_27 -> V_28 , L_25 ) ;
goto V_285;
}
V_136 = F_59 ( V_2 ) ;
if ( V_136 ) {
F_49 ( & V_27 -> V_28 , L_26 ) ;
goto V_285;
}
return 0 ;
V_285:
F_101 ( V_27 -> V_239 , V_2 ) ;
V_284:
F_12 ( V_2 ) ;
V_270:
F_98 ( V_2 -> V_3 ) ;
V_269:
F_99 ( V_27 ) ;
V_268:
F_103 ( V_133 ) ;
V_266:
F_105 ( V_27 ) ;
F_106 ( V_27 ) ;
V_264:
return V_136 ;
}
static int T_9 F_122 ( void )
{
return F_123 ( & V_286 ) ;
}
static void T_10 F_124 ( void )
{
F_125 ( & V_286 ) ;
}

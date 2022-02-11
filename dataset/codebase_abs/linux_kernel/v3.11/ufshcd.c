static inline T_1 F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 == V_4 )
return V_5 ;
else
return V_6 ;
}
static inline T_1 F_2 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_7 ) ;
}
static inline int F_4 ( T_1 V_8 )
{
return ( V_9 & V_8 ) ? 1 : 0 ;
}
static inline int F_5 ( struct V_10 * V_11 )
{
return V_11 -> V_12 -> V_13 . V_14 & V_15 ;
}
static inline int
F_6 ( struct V_16 * V_17 )
{
return V_17 -> V_13 . V_14 & V_15 ;
}
static inline int F_7 ( struct V_1 * V_2 )
{
return F_8 ( & V_2 -> V_18 , V_2 -> V_19 ) ;
}
static inline void F_9 ( struct V_1 * V_2 , T_1 V_20 )
{
F_10 ( V_2 , ~ ( 1 << V_20 ) , V_21 ) ;
}
static inline int F_11 ( T_1 V_22 )
{
return ( ( ( V_22 ) & ( 0xFF ) ) >> 1 ) ^ ( 0x07 ) ;
}
static inline int F_12 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_23 ) &
V_24 ;
}
static inline int
F_13 ( struct V_25 * V_26 )
{
return ( ( F_14 ( V_26 -> V_13 . V_27 ) >> 24 ) ==
V_28 ) ? 0 : V_29 << 16 ;
}
static inline int
F_15 ( struct V_25 * V_26 )
{
return F_14 ( V_26 -> V_13 . V_30 ) & V_31 ;
}
static inline void
F_16 ( struct V_1 * V_2 , int V_32 )
{
switch ( V_32 ) {
case V_33 :
F_10 ( V_2 , V_34 |
V_35 ,
V_36 ) ;
break;
case V_37 :
F_10 ( V_2 , V_34 | V_38 |
V_39 |
V_40 ,
V_36 ) ;
break;
}
}
static void F_17 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_41 ,
V_42 ) ;
F_10 ( V_2 , V_43 ,
V_44 ) ;
}
static inline void F_18 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_45 , V_46 ) ;
}
static inline int F_19 ( struct V_1 * V_2 )
{
return ( F_3 ( V_2 , V_46 ) & 0x1 ) ? 0 : 1 ;
}
static inline
void F_20 ( struct V_1 * V_2 , unsigned int V_47 )
{
F_21 ( V_47 , & V_2 -> V_48 ) ;
F_10 ( V_2 , 1 << V_47 , V_49 ) ;
}
static inline void F_22 ( struct V_10 * V_11 )
{
int V_50 ;
if ( V_11 -> V_51 ) {
V_50 = F_23 ( V_11 -> V_26 -> V_52 ) ;
memcpy ( V_11 -> V_51 ,
V_11 -> V_26 -> V_53 ,
F_24 ( int , V_50 , V_54 ) ) ;
}
}
static inline void F_25 ( struct V_1 * V_2 )
{
V_2 -> V_55 = F_3 ( V_2 , V_56 ) ;
V_2 -> V_57 = ( V_2 -> V_55 & V_58 ) + 1 ;
V_2 -> V_19 =
( ( V_2 -> V_55 & V_59 ) >> 16 ) + 1 ;
}
static inline bool F_26 ( struct V_1 * V_2 )
{
if ( F_3 ( V_2 , V_60 ) & V_61 )
return true ;
else
return false ;
}
static inline void
F_27 ( struct V_1 * V_2 , struct V_62 * V_63 )
{
F_28 ( V_2 -> V_64 ) ;
V_2 -> V_64 = V_63 ;
F_10 ( V_2 , V_63 -> V_65 , V_66 ) ;
F_10 ( V_2 , V_63 -> V_67 , V_23 ) ;
F_10 ( V_2 , V_63 -> V_68 , V_69 ) ;
F_10 ( V_2 , V_63 -> V_70 & V_71 ,
V_72 ) ;
}
static int
F_29 ( struct V_1 * V_2 , struct V_62 * V_63 )
{
int V_73 ;
unsigned long V_74 ;
if ( F_30 ( & V_63 -> V_75 ,
F_31 ( V_76 ) ) )
V_73 = V_63 -> V_67 & V_24 ;
else
V_73 = - V_77 ;
F_32 ( V_2 -> V_78 -> V_79 , V_74 ) ;
V_2 -> V_64 = NULL ;
F_33 ( V_2 -> V_78 -> V_79 , V_74 ) ;
return V_73 ;
}
static int
F_34 ( struct V_1 * V_2 , struct V_62 * V_63 )
{
int V_73 ;
unsigned long V_74 ;
if ( ! F_26 ( V_2 ) ) {
F_35 ( V_2 -> V_80 ,
L_1 ) ;
return - V_81 ;
}
F_36 ( & V_63 -> V_75 ) ;
F_32 ( V_2 -> V_78 -> V_79 , V_74 ) ;
F_27 ( V_2 , V_63 ) ;
F_33 ( V_2 -> V_78 -> V_79 , V_74 ) ;
V_73 = F_29 ( V_2 , V_63 ) ;
return V_73 ;
}
static int
F_37 ( struct V_1 * V_2 , struct V_62 * V_63 )
{
int V_73 ;
F_38 ( & V_2 -> V_82 ) ;
V_73 = F_34 ( V_2 , V_63 ) ;
F_39 ( & V_2 -> V_82 ) ;
return V_73 ;
}
static int F_40 ( struct V_10 * V_11 )
{
struct V_83 * V_84 ;
struct V_85 * V_86 ;
struct V_87 * V_88 ;
int V_89 ;
int V_90 ;
V_88 = V_11 -> V_88 ;
V_89 = F_41 ( V_88 ) ;
if ( V_89 < 0 )
return V_89 ;
if ( V_89 ) {
V_11 -> V_12 -> V_91 =
F_42 ( ( V_92 ) ( V_89 ) ) ;
V_84 = (struct V_83 * ) V_11 -> V_93 ;
F_43 (cmd, sg, sg_segments, i) {
V_84 [ V_90 ] . V_94 =
F_44 ( ( ( T_1 ) F_45 ( V_86 ) ) - 1 ) ;
V_84 [ V_90 ] . V_95 =
F_44 ( F_46 ( V_86 -> V_96 ) ) ;
V_84 [ V_90 ] . V_97 =
F_44 ( F_47 ( V_86 -> V_96 ) ) ;
}
} else {
V_11 -> V_12 -> V_91 = 0 ;
}
return 0 ;
}
static void F_48 ( struct V_1 * V_2 , T_1 V_98 )
{
T_1 V_99 = F_3 ( V_2 , V_100 ) ;
if ( V_2 -> V_3 == V_4 ) {
T_1 V_101 ;
V_101 = V_99 & V_102 ;
V_99 = V_101 | ( ( V_99 ^ V_98 ) & V_98 ) ;
} else {
V_99 |= V_98 ;
}
F_10 ( V_2 , V_99 , V_100 ) ;
}
static void F_49 ( struct V_1 * V_2 , T_1 V_98 )
{
T_1 V_99 = F_3 ( V_2 , V_100 ) ;
if ( V_2 -> V_3 == V_4 ) {
T_1 V_101 ;
V_101 = ( V_99 & V_102 ) &
~ ( V_98 & V_102 ) ;
V_99 = V_101 | ( ( V_99 & V_98 ) & ~ V_102 ) ;
} else {
V_99 &= ~ V_98 ;
}
F_10 ( V_2 , V_99 , V_100 ) ;
}
static void F_50 ( struct V_10 * V_11 )
{
struct V_103 * V_104 ;
struct V_105 * V_106 ;
T_1 V_107 ;
T_1 V_108 ;
V_106 = V_11 -> V_106 ;
V_104 = V_11 -> V_12 ;
switch ( V_11 -> V_109 ) {
case V_110 :
if ( V_11 -> V_88 -> V_111 == V_112 ) {
V_107 = V_113 ;
V_108 = V_114 ;
} else if ( V_11 -> V_88 -> V_111 == V_115 ) {
V_107 = V_116 ;
V_108 = V_117 ;
} else {
V_107 = V_118 ;
V_108 = V_119 ;
}
V_104 -> V_13 . V_27 =
F_44 ( V_107 | V_120 ) ;
V_104 -> V_13 . V_14 =
F_44 ( V_121 ) ;
V_106 -> V_13 . V_27 =
F_51 ( F_52 ( V_122 ,
V_108 ,
V_11 -> V_123 ,
V_11 -> V_47 ) ) ;
V_106 -> V_13 . V_30 =
F_51 (
F_52 ( V_124 ,
0 ,
0 ,
0 ) ) ;
V_106 -> V_13 . V_14 = 0 ;
V_106 -> V_125 =
F_51 ( V_11 -> V_88 -> V_126 . V_127 ) ;
memcpy ( V_106 -> V_128 ,
V_11 -> V_88 -> V_129 ,
( F_24 (unsigned short,
lrbp->cmd->cmd_len,
MAX_CDB_SIZE) ) ) ;
break;
case V_130 :
break;
case V_131 :
break;
}
}
static int F_53 ( struct V_132 * V_78 , struct V_87 * V_88 )
{
struct V_10 * V_11 ;
struct V_1 * V_2 ;
unsigned long V_74 ;
int V_133 ;
int V_134 = 0 ;
V_2 = F_54 ( V_78 ) ;
V_133 = V_88 -> V_135 -> V_133 ;
if ( V_2 -> V_136 != V_137 ) {
V_134 = V_138 ;
goto V_139;
}
V_11 = & V_2 -> V_140 [ V_133 ] ;
V_11 -> V_88 = V_88 ;
V_11 -> V_141 = V_54 ;
V_11 -> V_51 = V_88 -> V_51 ;
V_11 -> V_47 = V_133 ;
V_11 -> V_123 = V_88 -> V_142 -> V_123 ;
V_11 -> V_109 = V_110 ;
F_50 ( V_11 ) ;
V_134 = F_40 ( V_11 ) ;
if ( V_134 )
goto V_139;
F_32 ( V_2 -> V_78 -> V_79 , V_74 ) ;
F_20 ( V_2 , V_133 ) ;
F_33 ( V_2 -> V_78 -> V_79 , V_74 ) ;
V_139:
return V_134 ;
}
static int F_55 ( struct V_1 * V_2 )
{
T_2 V_143 , V_144 , V_145 ;
V_145 = ( sizeof( struct V_146 ) * V_2 -> V_57 ) ;
V_2 -> V_147 = F_56 ( V_2 -> V_80 ,
V_145 ,
& V_2 -> V_148 ,
V_149 ) ;
if ( ! V_2 -> V_147 ||
F_28 ( V_2 -> V_148 & ( V_150 - 1 ) ) ) {
F_35 ( V_2 -> V_80 ,
L_2 ) ;
goto V_139;
}
V_144 = ( sizeof( struct V_103 ) * V_2 -> V_57 ) ;
V_2 -> V_151 = F_56 ( V_2 -> V_80 ,
V_144 ,
& V_2 -> V_152 ,
V_149 ) ;
if ( ! V_2 -> V_151 ||
F_28 ( V_2 -> V_152 & ( V_150 - 1 ) ) ) {
F_35 ( V_2 -> V_80 ,
L_3 ) ;
goto V_139;
}
V_143 = sizeof( struct V_16 ) * V_2 -> V_19 ;
V_2 -> V_153 = F_56 ( V_2 -> V_80 ,
V_143 ,
& V_2 -> V_154 ,
V_149 ) ;
if ( ! V_2 -> V_153 ||
F_28 ( V_2 -> V_154 & ( V_150 - 1 ) ) ) {
F_35 ( V_2 -> V_80 ,
L_4 ) ;
goto V_139;
}
V_2 -> V_140 = F_57 ( V_2 -> V_80 ,
V_2 -> V_57 * sizeof( struct V_10 ) ,
V_149 ) ;
if ( ! V_2 -> V_140 ) {
F_35 ( V_2 -> V_80 , L_5 ) ;
goto V_139;
}
return 0 ;
V_139:
return - V_155 ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_146 * V_156 ;
struct V_103 * V_157 ;
T_3 V_158 ;
T_3 V_159 ;
V_92 V_160 ;
V_92 V_161 ;
int V_162 ;
int V_90 ;
V_157 = V_2 -> V_151 ;
V_156 = V_2 -> V_147 ;
V_160 =
F_59 ( struct V_146 , V_163 ) ;
V_161 =
F_59 ( struct V_146 , V_84 ) ;
V_162 = sizeof( struct V_146 ) ;
V_158 = V_2 -> V_148 ;
for ( V_90 = 0 ; V_90 < V_2 -> V_57 ; V_90 ++ ) {
V_159 =
( V_158 + ( V_162 * V_90 ) ) ;
V_157 [ V_90 ] . V_164 =
F_44 ( F_46 ( V_159 ) ) ;
V_157 [ V_90 ] . V_165 =
F_44 ( F_47 ( V_159 ) ) ;
V_157 [ V_90 ] . V_166 =
F_42 ( ( V_160 >> 2 ) ) ;
V_157 [ V_90 ] . V_167 =
F_42 ( ( V_161 >> 2 ) ) ;
V_157 [ V_90 ] . V_168 =
F_42 ( V_169 >> 2 ) ;
V_2 -> V_140 [ V_90 ] . V_12 = ( V_157 + V_90 ) ;
V_2 -> V_140 [ V_90 ] . V_106 =
(struct V_105 * ) ( V_156 + V_90 ) ;
V_2 -> V_140 [ V_90 ] . V_26 =
(struct V_25 * ) V_156 [ V_90 ] . V_163 ;
V_2 -> V_140 [ V_90 ] . V_93 =
(struct V_83 * ) V_156 [ V_90 ] . V_84 ;
}
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_62 V_63 = { 0 } ;
int V_73 ;
V_63 . V_70 = V_170 ;
V_73 = F_37 ( V_2 , & V_63 ) ;
if ( V_73 )
F_35 ( V_2 -> V_80 ,
L_6 , V_73 ) ;
return V_73 ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_134 = 0 ;
T_1 V_22 ;
V_22 = F_3 ( V_2 , V_60 ) ;
if ( ! F_4 ( V_22 ) ) {
F_35 ( V_2 -> V_80 , L_7 ) ;
V_134 = - V_171 ;
goto V_139;
}
F_48 ( V_2 , V_172 ) ;
F_16 ( V_2 , V_37 ) ;
F_10 ( V_2 , F_46 ( V_2 -> V_152 ) ,
V_173 ) ;
F_10 ( V_2 , F_47 ( V_2 -> V_152 ) ,
V_174 ) ;
F_10 ( V_2 , F_46 ( V_2 -> V_154 ) ,
V_175 ) ;
F_10 ( V_2 , F_47 ( V_2 -> V_154 ) ,
V_176 ) ;
if ( ! ( F_11 ( V_22 ) ) ) {
F_17 ( V_2 ) ;
} else {
F_35 ( V_2 -> V_80 ,
L_8 ) ;
V_134 = - V_81 ;
goto V_139;
}
if ( V_2 -> V_136 == V_177 )
F_62 ( V_2 -> V_78 ) ;
V_2 -> V_136 = V_137 ;
V_139:
return V_134 ;
}
static int F_63 ( struct V_1 * V_2 )
{
int V_178 ;
if ( ! F_19 ( V_2 ) ) {
F_64 ( V_2 ) ;
F_65 ( 5 ) ;
}
F_18 ( V_2 ) ;
F_65 ( 1 ) ;
V_178 = 10 ;
while ( F_19 ( V_2 ) ) {
if ( V_178 ) {
V_178 -- ;
} else {
F_35 ( V_2 -> V_80 ,
L_9 ) ;
return - V_81 ;
}
F_65 ( 5 ) ;
}
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
int V_73 ;
F_48 ( V_2 , V_179 ) ;
V_73 = F_60 ( V_2 ) ;
if ( V_73 )
goto V_139;
V_73 = F_61 ( V_2 ) ;
V_139:
if ( V_73 )
F_35 ( V_2 -> V_80 , L_10 , V_73 ) ;
return V_73 ;
}
static int F_67 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
unsigned long V_74 ;
int V_133 ;
F_68 ( V_2 -> V_78 ) ;
F_32 ( V_2 -> V_78 -> V_79 , V_74 ) ;
V_2 -> V_136 = V_177 ;
F_64 ( V_2 ) ;
F_33 ( V_2 -> V_78 -> V_79 , V_74 ) ;
for ( V_133 = 0 ; V_133 < V_2 -> V_57 ; V_133 ++ ) {
if ( F_69 ( V_133 , & V_2 -> V_48 ) ) {
V_11 = & V_2 -> V_140 [ V_133 ] ;
F_70 ( V_11 -> V_88 ) ;
V_11 -> V_88 -> V_180 = V_181 << 16 ;
V_11 -> V_88 -> V_182 ( V_11 -> V_88 ) ;
V_11 -> V_88 = NULL ;
}
}
V_2 -> V_48 = 0 ;
V_2 -> V_18 = 0 ;
if ( F_63 ( V_2 ) ) {
F_35 ( V_2 -> V_80 ,
L_11 ) ;
return V_183 ;
}
if ( F_66 ( V_2 ) ) {
F_35 ( V_2 -> V_80 ,
L_12 ) ;
return V_183 ;
}
return V_184 ;
}
static int F_71 ( struct V_185 * V_186 )
{
struct V_1 * V_2 ;
V_2 = F_54 ( V_186 -> V_78 ) ;
V_186 -> V_187 = 1 ;
V_186 -> V_188 = 1 ;
F_72 ( V_186 , V_189 ) ;
F_73 ( V_186 , V_2 -> V_57 ) ;
return 0 ;
}
static void F_74 ( struct V_185 * V_186 )
{
struct V_1 * V_2 ;
V_2 = F_54 ( V_186 -> V_78 ) ;
F_75 ( V_186 , V_2 -> V_57 ) ;
}
static int F_76 ( struct V_1 * V_2 , T_1 V_190 )
{
struct V_16 * V_17 ;
struct V_191 * V_192 ;
unsigned long V_74 ;
int V_193 ;
int V_194 ;
F_32 ( V_2 -> V_78 -> V_79 , V_74 ) ;
F_77 ( V_190 , & V_2 -> V_18 ) ;
V_17 = V_2 -> V_153 ;
V_193 = F_6 ( & V_17 [ V_190 ] ) ;
if ( V_193 == V_195 ) {
V_192 = (struct V_191 * )
V_17 [ V_190 ] . V_196 ;
V_194 = F_14 ( V_192 -> V_13 . V_30 ) ;
V_194 = ( ( V_194 & V_197 ) >> 8 ) ;
if ( V_194 != V_198 &&
V_194 != V_199 )
V_194 = V_183 ;
else
V_194 = V_184 ;
} else {
V_194 = V_183 ;
F_35 ( V_2 -> V_80 ,
L_13 , V_193 ) ;
}
F_33 ( V_2 -> V_78 -> V_79 , V_74 ) ;
return V_194 ;
}
static void F_78 ( struct V_87 * V_88 )
{
struct V_1 * V_2 ;
int V_90 ;
int V_200 = 0 ;
V_2 = F_54 ( V_88 -> V_142 -> V_78 ) ;
for ( V_90 = 0 ; V_90 < V_2 -> V_57 ; V_90 ++ ) {
if ( F_69 ( V_90 , & V_2 -> V_48 ) ) {
if ( V_88 -> V_142 -> V_123 == V_2 -> V_140 [ V_90 ] . V_123 )
V_200 ++ ;
}
}
F_79 ( V_88 -> V_142 , V_189 , V_200 - 1 ) ;
}
static inline int
F_80 ( struct V_10 * V_11 , int V_201 )
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
F_22 ( V_11 ) ;
break;
case V_206 :
V_180 |= V_206 ;
break;
case V_207 :
F_78 ( V_11 -> V_88 ) ;
V_180 |= V_207 ;
break;
case V_208 :
V_180 |= V_208 ;
break;
default:
V_180 |= V_29 << 16 ;
break;
}
return V_180 ;
}
static inline int
F_81 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
int V_180 = 0 ;
int V_201 ;
int V_209 ;
V_209 = F_5 ( V_11 ) ;
switch ( V_209 ) {
case V_195 :
V_180 = F_13 ( V_11 -> V_26 ) ;
if ( V_180 ) {
F_35 ( V_2 -> V_80 ,
L_14 , V_180 ) ;
break;
}
V_180 = F_15 ( V_11 -> V_26 ) ;
V_201 = V_180 & V_210 ;
V_180 = F_80 ( V_11 , V_201 ) ;
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
V_180 |= V_29 << 16 ;
F_35 ( V_2 -> V_80 ,
L_15 , V_209 ) ;
break;
}
return V_180 ;
}
static void F_82 ( struct V_1 * V_2 )
{
if ( V_2 -> V_64 ) {
V_2 -> V_64 -> V_67 |=
F_12 ( V_2 ) ;
F_83 ( & V_2 -> V_64 -> V_75 ) ;
}
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_10 * V_140 ;
unsigned long V_219 ;
T_1 V_220 ;
int V_180 ;
int V_190 ;
V_140 = V_2 -> V_140 ;
V_220 = F_3 ( V_2 , V_49 ) ;
V_219 = V_220 ^ V_2 -> V_48 ;
for ( V_190 = 0 ; V_190 < V_2 -> V_57 ; V_190 ++ ) {
if ( F_69 ( V_190 , & V_219 ) ) {
V_180 = F_81 ( V_2 , & V_140 [ V_190 ] ) ;
if ( V_140 [ V_190 ] . V_88 ) {
F_70 ( V_140 [ V_190 ] . V_88 ) ;
V_140 [ V_190 ] . V_88 -> V_180 = V_180 ;
V_140 [ V_190 ] . V_88 -> V_182 ( V_140 [ V_190 ] . V_88 ) ;
V_140 [ V_190 ] . V_88 = NULL ;
}
}
}
V_2 -> V_48 ^= V_219 ;
F_16 ( V_2 , V_33 ) ;
}
static void F_85 ( struct V_221 * V_222 )
{
struct V_1 * V_2 ;
V_2 = F_86 ( V_222 , struct V_1 , V_223 ) ;
if ( V_2 -> V_136 != V_177 )
F_67 ( V_2 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
T_1 V_22 ;
if ( V_2 -> V_224 & V_225 )
goto V_226;
if ( V_2 -> V_224 & V_227 ) {
V_22 = F_3 ( V_2 , V_228 ) ;
if ( V_22 & V_229 )
goto V_226;
}
return;
V_226:
V_2 -> V_136 = V_230 ;
F_88 ( & V_2 -> V_223 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
T_1 V_231 ;
V_231 = F_3 ( V_2 , V_232 ) ;
V_2 -> V_233 = V_231 ^ V_2 -> V_18 ;
F_90 ( & V_2 -> V_234 ) ;
}
static void F_91 ( struct V_1 * V_2 , T_1 V_235 )
{
V_2 -> V_224 = V_236 & V_235 ;
if ( V_2 -> V_224 )
F_87 ( V_2 ) ;
if ( V_235 & V_179 )
F_82 ( V_2 ) ;
if ( V_235 & V_237 )
F_89 ( V_2 ) ;
if ( V_235 & V_238 )
F_84 ( V_2 ) ;
}
static T_4 F_92 ( int V_239 , void * V_240 )
{
T_1 V_235 ;
T_4 V_241 = V_242 ;
struct V_1 * V_2 = V_240 ;
F_93 ( V_2 -> V_78 -> V_79 ) ;
V_235 = F_3 ( V_2 , V_243 ) ;
if ( V_235 ) {
F_10 ( V_2 , V_235 , V_243 ) ;
F_91 ( V_2 , V_235 ) ;
V_241 = V_244 ;
}
F_94 ( V_2 -> V_78 -> V_79 ) ;
return V_241 ;
}
static int
F_95 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
T_5 V_245 )
{
struct V_16 * V_17 ;
struct V_246 * V_247 ;
struct V_132 * V_78 ;
unsigned long V_74 ;
int V_248 = 0 ;
int V_134 ;
V_78 = V_2 -> V_78 ;
F_32 ( V_78 -> V_79 , V_74 ) ;
V_248 = F_7 ( V_2 ) ;
if ( V_248 >= V_2 -> V_19 ) {
F_33 ( V_78 -> V_79 , V_74 ) ;
F_35 ( V_2 -> V_80 , L_16 ) ;
V_134 = V_183 ;
goto V_139;
}
V_17 = V_2 -> V_153 ;
V_17 += V_248 ;
V_17 -> V_13 . V_27 = F_44 ( V_249 ) ;
V_17 -> V_13 . V_14 =
F_44 ( V_121 ) ;
V_247 =
(struct V_246 * ) V_17 -> V_250 ;
V_247 -> V_13 . V_27 =
F_51 ( F_52 ( V_251 , 0 ,
V_11 -> V_123 , V_11 -> V_47 ) ) ;
V_247 -> V_13 . V_30 =
F_51 ( F_52 ( 0 , V_245 , 0 , 0 ) ) ;
V_247 -> V_252 = V_11 -> V_123 ;
V_247 -> V_252 =
F_51 ( V_247 -> V_252 ) ;
V_247 -> V_253 = V_11 -> V_47 ;
V_247 -> V_253 =
F_51 ( V_247 -> V_253 ) ;
F_21 ( V_248 , & V_2 -> V_18 ) ;
F_10 ( V_2 , 1 << V_248 , V_232 ) ;
F_33 ( V_78 -> V_79 , V_74 ) ;
V_134 =
F_96 ( V_2 -> V_234 ,
( F_69 ( V_248 ,
& V_2 -> V_233 ) != 0 ) ,
60 * V_254 ) ;
if ( ! V_134 ) {
F_35 ( V_2 -> V_80 ,
L_17 ) ;
V_134 = V_183 ;
goto V_139;
}
F_97 ( V_248 , & V_2 -> V_233 ) ;
V_134 = F_76 ( V_2 , V_248 ) ;
V_139:
return V_134 ;
}
static int F_98 ( struct V_87 * V_88 )
{
struct V_132 * V_78 ;
struct V_1 * V_2 ;
unsigned int V_133 ;
T_1 V_20 ;
int V_134 ;
V_78 = V_88 -> V_142 -> V_78 ;
V_2 = F_54 ( V_78 ) ;
V_133 = V_88 -> V_135 -> V_133 ;
V_134 = F_95 ( V_2 , & V_2 -> V_140 [ V_133 ] , V_255 ) ;
if ( V_134 == V_183 )
goto V_139;
for ( V_20 = 0 ; V_20 < V_2 -> V_57 ; V_20 ++ ) {
if ( F_69 ( V_20 , & V_2 -> V_48 ) &&
( V_2 -> V_140 [ V_133 ] . V_123 == V_2 -> V_140 [ V_20 ] . V_123 ) ) {
F_9 ( V_2 , V_20 ) ;
F_97 ( V_20 , & V_2 -> V_48 ) ;
if ( V_2 -> V_140 [ V_20 ] . V_88 ) {
F_70 ( V_2 -> V_140 [ V_20 ] . V_88 ) ;
V_2 -> V_140 [ V_20 ] . V_88 -> V_180 =
V_212 << 16 ;
V_2 -> V_140 [ V_20 ] . V_88 -> V_182 ( V_88 ) ;
V_2 -> V_140 [ V_20 ] . V_88 = NULL ;
}
}
}
V_139:
return V_134 ;
}
static int F_99 ( struct V_87 * V_88 )
{
struct V_1 * V_2 ;
V_2 = F_54 ( V_88 -> V_142 -> V_78 ) ;
if ( V_2 -> V_136 == V_177 )
return V_184 ;
return F_67 ( V_2 ) ;
}
static int F_100 ( struct V_87 * V_88 )
{
struct V_132 * V_78 ;
struct V_1 * V_2 ;
unsigned long V_74 ;
unsigned int V_133 ;
int V_134 ;
V_78 = V_88 -> V_142 -> V_78 ;
V_2 = F_54 ( V_78 ) ;
V_133 = V_88 -> V_135 -> V_133 ;
F_32 ( V_78 -> V_79 , V_74 ) ;
if ( ! ( F_69 ( V_133 , & V_2 -> V_48 ) ) ) {
V_134 = V_183 ;
F_33 ( V_78 -> V_79 , V_74 ) ;
goto V_139;
}
F_33 ( V_78 -> V_79 , V_74 ) ;
V_134 = F_95 ( V_2 , & V_2 -> V_140 [ V_133 ] , V_256 ) ;
if ( V_134 == V_183 )
goto V_139;
F_70 ( V_88 ) ;
F_32 ( V_78 -> V_79 , V_74 ) ;
F_9 ( V_2 , V_133 ) ;
F_77 ( V_133 , & V_2 -> V_48 ) ;
V_2 -> V_140 [ V_133 ] . V_88 = NULL ;
F_33 ( V_78 -> V_79 , V_74 ) ;
V_139:
return V_134 ;
}
static void F_101 ( void * V_257 , T_6 V_258 )
{
struct V_1 * V_2 = (struct V_1 * ) V_257 ;
int V_73 ;
V_73 = F_66 ( V_2 ) ;
if ( ! V_73 )
F_102 ( V_2 -> V_78 ) ;
}
int F_103 ( struct V_1 * V_2 , T_7 V_259 )
{
return - V_260 ;
}
int F_104 ( struct V_1 * V_2 )
{
return - V_260 ;
}
void F_105 ( struct V_1 * V_2 )
{
F_49 ( V_2 , V_2 -> V_261 ) ;
F_64 ( V_2 ) ;
F_106 ( V_2 -> V_78 ) ;
F_107 ( V_2 -> V_78 ) ;
}
int F_108 ( struct V_142 * V_80 , struct V_1 * * V_262 ,
void T_8 * V_263 , unsigned int V_239 )
{
struct V_132 * V_78 ;
struct V_1 * V_2 ;
int V_134 ;
if ( ! V_80 ) {
F_35 ( V_80 ,
L_18 ) ;
V_134 = - V_264 ;
goto V_265;
}
if ( ! V_263 ) {
F_35 ( V_80 ,
L_19 ) ;
V_134 = - V_264 ;
goto V_265;
}
V_78 = F_109 ( & V_266 ,
sizeof( struct V_1 ) ) ;
if ( ! V_78 ) {
F_35 ( V_80 , L_20 ) ;
V_134 = - V_155 ;
goto V_265;
}
V_2 = F_54 ( V_78 ) ;
V_2 -> V_78 = V_78 ;
V_2 -> V_80 = V_80 ;
V_2 -> V_263 = V_263 ;
V_2 -> V_239 = V_239 ;
F_25 ( V_2 ) ;
V_2 -> V_3 = F_2 ( V_2 ) ;
V_2 -> V_261 = F_1 ( V_2 ) ;
V_134 = F_55 ( V_2 ) ;
if ( V_134 ) {
F_35 ( V_2 -> V_80 , L_21 ) ;
goto V_267;
}
F_58 ( V_2 ) ;
V_78 -> V_268 = V_2 -> V_57 ;
V_78 -> V_269 = V_2 -> V_57 ;
V_78 -> V_270 = V_271 ;
V_78 -> V_272 = V_273 ;
V_78 -> V_274 = V_275 ;
V_78 -> V_276 = V_78 -> V_277 ;
V_78 -> V_278 = V_279 ;
F_110 ( & V_2 -> V_234 ) ;
F_111 ( & V_2 -> V_223 , F_85 ) ;
F_112 ( & V_2 -> V_82 ) ;
V_134 = F_113 ( V_80 , V_239 , F_92 , V_280 , V_281 , V_2 ) ;
if ( V_134 ) {
F_35 ( V_2 -> V_80 , L_22 ) ;
goto V_267;
}
V_134 = F_114 ( V_78 , V_78 -> V_268 ) ;
if ( V_134 ) {
F_35 ( V_2 -> V_80 , L_23 ) ;
goto V_267;
}
V_134 = F_115 ( V_78 , V_2 -> V_80 ) ;
if ( V_134 ) {
F_35 ( V_2 -> V_80 , L_24 ) ;
goto V_267;
}
V_134 = F_63 ( V_2 ) ;
if ( V_134 ) {
F_35 ( V_2 -> V_80 , L_25 ) ;
goto V_282;
}
* V_262 = V_2 ;
F_116 ( F_101 , V_2 ) ;
return 0 ;
V_282:
F_106 ( V_2 -> V_78 ) ;
V_267:
F_107 ( V_78 ) ;
V_265:
return V_134 ;
}

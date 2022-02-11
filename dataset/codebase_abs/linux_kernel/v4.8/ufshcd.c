static inline enum V_1
F_1 ( enum V_2 V_3 )
{
return V_4 [ V_3 ] . V_5 ;
}
static inline enum V_6
F_2 ( enum V_2 V_3 )
{
return V_4 [ V_3 ] . V_7 ;
}
static inline bool F_3 ( struct V_8 * V_9 , int V_10 )
{
return V_10 >= 0 && V_10 < V_9 -> V_11 ;
}
static inline int F_4 ( struct V_8 * V_9 )
{
int V_12 = 0 ;
if ( ! V_9 -> V_13 ) {
V_12 = F_5 ( V_9 -> V_14 , V_15 , V_16 , V_17 ,
V_9 ) ;
if ( V_12 )
F_6 ( V_9 -> V_18 , L_1 ,
V_19 , V_12 ) ;
V_9 -> V_13 = true ;
}
return V_12 ;
}
static inline void F_7 ( struct V_8 * V_9 )
{
if ( V_9 -> V_13 ) {
F_8 ( V_9 -> V_14 , V_9 ) ;
V_9 -> V_13 = false ;
}
}
static inline void F_9 ( char * V_20 )
{
if ( ! V_20 )
return;
if ( * V_20 < 0x20 || * V_20 > 0x7e )
* V_20 = ' ' ;
}
int F_10 ( struct V_8 * V_9 , T_1 V_21 , T_1 V_22 ,
T_1 V_20 , unsigned long V_23 ,
unsigned long V_24 , bool V_25 )
{
int V_26 = 0 ;
unsigned long V_27 = V_28 + F_11 ( V_24 ) ;
V_20 = V_20 & V_22 ;
while ( ( F_12 ( V_9 , V_21 ) & V_22 ) != V_20 ) {
if ( V_25 )
F_13 ( V_23 , V_23 + 50 ) ;
else
F_14 ( V_23 ) ;
if ( F_15 ( V_28 , V_27 ) ) {
if ( ( F_12 ( V_9 , V_21 ) & V_22 ) != V_20 )
V_26 = - V_29 ;
break;
}
}
return V_26 ;
}
static inline T_1 F_16 ( struct V_8 * V_9 )
{
if ( V_9 -> V_30 == V_31 )
return V_32 ;
else
return V_33 ;
}
static inline T_1 F_17 ( struct V_8 * V_9 )
{
if ( V_9 -> V_34 & V_35 )
return F_18 ( V_9 ) ;
return F_12 ( V_9 , V_36 ) ;
}
static inline int F_19 ( struct V_8 * V_9 )
{
return ( F_12 ( V_9 , V_37 ) &
V_38 ) ? 1 : 0 ;
}
static inline int F_20 ( struct V_39 * V_40 )
{
return F_21 ( V_40 -> V_41 -> V_42 . V_43 ) & V_44 ;
}
static inline int
F_22 ( struct V_45 * V_46 )
{
return F_21 ( V_46 -> V_42 . V_43 ) & V_44 ;
}
static bool F_23 ( struct V_8 * V_9 , int * V_47 )
{
int V_10 ;
bool V_12 = false ;
if ( ! V_47 )
goto V_48;
do {
V_10 = F_24 ( & V_9 -> V_49 , V_9 -> V_50 ) ;
if ( V_10 >= V_9 -> V_50 )
goto V_48;
} while ( F_25 ( V_10 , & V_9 -> V_49 ) );
* V_47 = V_10 ;
V_12 = true ;
V_48:
return V_12 ;
}
static inline void F_26 ( struct V_8 * V_9 , int V_51 )
{
F_27 ( V_51 , & V_9 -> V_49 ) ;
}
static inline void F_28 ( struct V_8 * V_9 , T_1 V_52 )
{
F_29 ( V_9 , ~ ( 1 << V_52 ) , V_53 ) ;
}
static inline void F_30 ( struct V_8 * V_9 , int V_10 )
{
F_31 ( V_10 , & V_9 -> V_54 ) ;
}
static inline int F_32 ( T_1 V_21 )
{
return ( ( V_21 & 0xFF ) >> 1 ) ^ 0x07 ;
}
static inline int F_33 ( struct V_8 * V_9 )
{
return F_12 ( V_9 , V_55 ) &
V_56 ;
}
static inline T_1 F_34 ( struct V_8 * V_9 )
{
return F_12 ( V_9 , V_57 ) ;
}
static inline int
F_35 ( struct V_58 * V_59 )
{
return F_36 ( V_59 -> V_42 . V_60 ) >> 24 ;
}
static inline int
F_37 ( struct V_58 * V_59 )
{
return F_36 ( V_59 -> V_42 . V_61 ) & V_62 ;
}
static inline unsigned int
F_38 ( struct V_58 * V_59 )
{
return F_36 ( V_59 -> V_42 . V_43 ) &
V_63 ;
}
static inline bool F_39 ( struct V_58 * V_59 )
{
return F_36 ( V_59 -> V_42 . V_43 ) &
V_64 ? true : false ;
}
static inline void
F_40 ( struct V_8 * V_9 )
{
F_29 ( V_9 , V_65 |
V_66 ,
V_67 ) ;
}
static inline void
F_41 ( struct V_8 * V_9 , T_2 V_68 , T_2 V_69 )
{
F_29 ( V_9 , V_65 | V_70 |
F_42 ( V_68 ) |
F_43 ( V_69 ) ,
V_67 ) ;
}
static inline void F_44 ( struct V_8 * V_9 )
{
F_29 ( V_9 , 0 , V_67 ) ;
}
static void F_45 ( struct V_8 * V_9 )
{
F_29 ( V_9 , V_71 ,
V_72 ) ;
F_29 ( V_9 , V_73 ,
V_74 ) ;
}
static inline void F_46 ( struct V_8 * V_9 )
{
F_29 ( V_9 , V_75 , V_76 ) ;
}
static inline int F_47 ( struct V_8 * V_9 )
{
return ( F_12 ( V_9 , V_76 ) & 0x1 ) ? 0 : 1 ;
}
T_1 F_48 ( struct V_8 * V_9 )
{
if ( ( V_9 -> V_30 == V_31 ) ||
( V_9 -> V_30 == V_77 ) )
return V_78 ;
else
return V_79 ;
}
static bool F_49 ( struct V_8 * V_9 )
{
if ( F_48 ( V_9 ) < V_79 )
return true ;
else
return false ;
}
static void F_50 ( struct V_80 * V_81 )
{
int V_12 ;
unsigned long V_82 ;
struct V_8 * V_9 = F_51 ( V_81 , struct V_8 ,
V_83 . V_84 ) ;
F_52 ( & V_9 -> V_83 . V_85 ) ;
F_53 ( V_9 -> V_86 -> V_87 , V_82 ) ;
if ( V_9 -> V_83 . V_88 == V_89 ) {
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
goto V_90;
}
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
F_55 ( V_9 , true ) ;
if ( F_56 ( V_9 ) ) {
V_9 -> V_83 . V_91 = true ;
if ( F_57 ( V_9 ) ) {
V_12 = F_58 ( V_9 ) ;
if ( V_12 )
F_6 ( V_9 -> V_18 , L_2 ,
V_19 , V_12 ) ;
else
F_59 ( V_9 ) ;
}
V_9 -> V_83 . V_91 = false ;
}
V_90:
if ( F_60 ( V_9 ) )
F_61 ( V_9 -> V_92 ) ;
F_62 ( V_9 -> V_86 ) ;
}
int F_63 ( struct V_8 * V_9 , bool V_93 )
{
int V_94 = 0 ;
unsigned long V_82 ;
if ( ! F_64 ( V_9 ) )
goto V_48;
F_53 ( V_9 -> V_86 -> V_87 , V_82 ) ;
V_9 -> V_83 . V_95 ++ ;
if ( F_65 ( V_9 ) ) {
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
return 0 ;
}
V_96:
switch ( V_9 -> V_83 . V_88 ) {
case V_89 :
break;
case V_97 :
if ( F_66 ( & V_9 -> V_83 . V_85 ) ) {
V_9 -> V_83 . V_88 = V_89 ;
break;
}
case V_98 :
F_67 ( V_9 -> V_86 ) ;
V_9 -> V_83 . V_88 = V_99 ;
F_68 ( & V_9 -> V_83 . V_84 ) ;
case V_99 :
if ( V_93 ) {
V_94 = - V_100 ;
V_9 -> V_83 . V_95 -- ;
break;
}
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
F_69 ( & V_9 -> V_83 . V_84 ) ;
F_53 ( V_9 -> V_86 -> V_87 , V_82 ) ;
goto V_96;
default:
F_6 ( V_9 -> V_18 , L_3 ,
V_19 , V_9 -> V_83 . V_88 ) ;
break;
}
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
V_48:
return V_94 ;
}
static void F_70 ( struct V_80 * V_81 )
{
struct V_8 * V_9 = F_51 ( V_81 , struct V_8 ,
V_83 . V_85 . V_81 ) ;
unsigned long V_82 ;
F_53 ( V_9 -> V_86 -> V_87 , V_82 ) ;
if ( V_9 -> V_83 . V_91 ) {
V_9 -> V_83 . V_88 = V_89 ;
goto V_101;
}
if ( V_9 -> V_83 . V_95
|| V_9 -> V_102 != V_103
|| V_9 -> V_104 || V_9 -> V_105
|| V_9 -> V_106 || V_9 -> V_107 )
goto V_101;
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
if ( F_56 ( V_9 ) ) {
if ( F_71 ( V_9 ) ) {
V_9 -> V_83 . V_88 = V_89 ;
goto V_48;
}
F_72 ( V_9 ) ;
}
if ( F_60 ( V_9 ) ) {
F_73 ( V_9 -> V_92 ) ;
V_9 -> V_108 . V_109 = 0 ;
}
if ( ! F_74 ( V_9 ) )
F_55 ( V_9 , false ) ;
else
F_75 ( V_9 , false , true ) ;
F_53 ( V_9 -> V_86 -> V_87 , V_82 ) ;
if ( V_9 -> V_83 . V_88 == V_97 )
V_9 -> V_83 . V_88 = V_98 ;
V_101:
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
V_48:
return;
}
static void F_76 ( struct V_8 * V_9 )
{
if ( ! F_64 ( V_9 ) )
return;
V_9 -> V_83 . V_95 -- ;
if ( V_9 -> V_83 . V_95 || V_9 -> V_83 . V_91
|| V_9 -> V_102 != V_103
|| V_9 -> V_104 || V_9 -> V_105
|| V_9 -> V_106 || V_9 -> V_107
|| F_65 ( V_9 ) )
return;
V_9 -> V_83 . V_88 = V_97 ;
F_77 ( & V_9 -> V_83 . V_85 ,
F_11 ( V_9 -> V_83 . V_110 ) ) ;
}
void F_78 ( struct V_8 * V_9 )
{
unsigned long V_82 ;
F_53 ( V_9 -> V_86 -> V_87 , V_82 ) ;
F_76 ( V_9 ) ;
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
}
static T_3 F_79 ( struct V_111 * V_18 ,
struct V_112 * V_113 , char * V_114 )
{
struct V_8 * V_9 = F_80 ( V_18 ) ;
return snprintf ( V_114 , V_115 , L_4 , V_9 -> V_83 . V_110 ) ;
}
static T_3 F_81 ( struct V_111 * V_18 ,
struct V_112 * V_113 , const char * V_114 , T_4 V_116 )
{
struct V_8 * V_9 = F_80 ( V_18 ) ;
unsigned long V_82 , V_117 ;
if ( F_82 ( V_114 , 0 , & V_117 ) )
return - V_118 ;
F_53 ( V_9 -> V_86 -> V_87 , V_82 ) ;
V_9 -> V_83 . V_110 = V_117 ;
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
return V_116 ;
}
static void F_83 ( struct V_8 * V_9 )
{
if ( ! F_64 ( V_9 ) )
return;
V_9 -> V_83 . V_110 = 150 ;
F_84 ( & V_9 -> V_83 . V_85 , F_70 ) ;
F_85 ( & V_9 -> V_83 . V_84 , F_50 ) ;
V_9 -> V_83 . V_119 . V_120 = F_79 ;
V_9 -> V_83 . V_119 . V_121 = F_81 ;
F_86 ( & V_9 -> V_83 . V_119 . V_113 ) ;
V_9 -> V_83 . V_119 . V_113 . V_122 = L_5 ;
V_9 -> V_83 . V_119 . V_113 . V_123 = V_124 | V_125 ;
if ( F_87 ( V_9 -> V_18 , & V_9 -> V_83 . V_119 ) )
F_6 ( V_9 -> V_18 , L_6 ) ;
}
static void F_88 ( struct V_8 * V_9 )
{
if ( ! F_64 ( V_9 ) )
return;
F_89 ( V_9 -> V_18 , & V_9 -> V_83 . V_119 ) ;
F_90 ( & V_9 -> V_83 . V_84 ) ;
F_52 ( & V_9 -> V_83 . V_85 ) ;
}
static void F_91 ( struct V_8 * V_9 )
{
if ( ! F_60 ( V_9 ) )
return;
if ( ! V_9 -> V_108 . V_126 ) {
V_9 -> V_108 . V_127 = F_92 () ;
V_9 -> V_108 . V_126 = true ;
}
}
static void F_93 ( struct V_8 * V_9 )
{
struct V_128 * V_129 = & V_9 -> V_108 ;
if ( ! F_60 ( V_9 ) )
return;
if ( ! V_9 -> V_54 && V_129 -> V_126 ) {
V_129 -> V_130 += F_94 ( F_95 ( F_92 () ,
V_129 -> V_127 ) ) ;
V_129 -> V_127 = F_96 ( 0 , 0 ) ;
V_129 -> V_126 = false ;
}
}
static inline
void F_97 ( struct V_8 * V_9 , unsigned int V_131 )
{
F_91 ( V_9 ) ;
F_98 ( V_131 , & V_9 -> V_54 ) ;
F_29 ( V_9 , 1 << V_131 , V_132 ) ;
}
static inline void F_99 ( struct V_39 * V_40 )
{
int V_133 ;
if ( V_40 -> V_134 &&
F_38 ( V_40 -> V_59 ) ) {
V_133 = F_100 ( V_40 -> V_59 -> V_135 . V_136 ) ;
memcpy ( V_40 -> V_134 ,
V_40 -> V_59 -> V_135 . V_137 ,
F_101 ( int , V_133 , V_138 ) ) ;
}
}
static
int F_102 ( struct V_8 * V_9 , struct V_39 * V_40 )
{
struct V_139 * V_140 = & V_9 -> V_141 . V_142 . V_143 ;
memcpy ( & V_140 -> V_144 , & V_40 -> V_59 -> V_145 , V_146 ) ;
if ( V_40 -> V_59 -> V_145 . V_147 == V_148 ) {
T_2 * V_149 = ( T_2 * ) V_40 -> V_59 +
V_150 ;
T_5 V_151 ;
T_5 V_152 ;
V_151 = F_36 ( V_40 -> V_59 -> V_42 . V_43 ) &
V_153 ;
V_152 = F_100 (
V_9 -> V_141 . V_142 . V_154 . V_155 . V_156 ) ;
if ( F_103 ( V_152 >= V_151 ) ) {
memcpy ( V_9 -> V_141 . V_142 . V_157 , V_149 , V_151 ) ;
} else {
F_104 ( V_9 -> V_18 ,
L_7 ,
V_19 ) ;
return - V_118 ;
}
}
return 0 ;
}
static inline void F_105 ( struct V_8 * V_9 )
{
V_9 -> V_158 = F_12 ( V_9 , V_159 ) ;
V_9 -> V_11 = ( V_9 -> V_158 & V_160 ) + 1 ;
V_9 -> V_50 =
( ( V_9 -> V_158 & V_161 ) >> 16 ) + 1 ;
}
static inline bool F_106 ( struct V_8 * V_9 )
{
if ( F_12 ( V_9 , V_37 ) & V_162 )
return true ;
else
return false ;
}
static inline T_2 F_107 ( struct V_8 * V_9 )
{
return ( F_12 ( V_9 , V_37 ) >> 8 ) & 0x7 ;
}
static inline void
F_108 ( struct V_8 * V_9 , struct V_163 * V_164 )
{
F_109 ( V_9 -> V_106 ) ;
V_9 -> V_106 = V_164 ;
F_29 ( V_9 , V_164 -> V_165 , V_166 ) ;
F_29 ( V_9 , V_164 -> V_167 , V_55 ) ;
F_29 ( V_9 , V_164 -> V_168 , V_57 ) ;
F_29 ( V_9 , V_164 -> V_169 & V_170 ,
V_171 ) ;
}
static int
F_110 ( struct V_8 * V_9 , struct V_163 * V_164 )
{
int V_12 ;
unsigned long V_82 ;
if ( F_111 ( & V_164 -> V_172 ,
F_11 ( V_173 ) ) )
V_12 = V_164 -> V_167 & V_56 ;
else
V_12 = - V_29 ;
F_53 ( V_9 -> V_86 -> V_87 , V_82 ) ;
V_9 -> V_106 = NULL ;
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
return V_12 ;
}
static int
F_112 ( struct V_8 * V_9 , struct V_163 * V_164 ,
bool V_174 )
{
if ( ! F_106 ( V_9 ) ) {
F_6 ( V_9 -> V_18 ,
L_8 ) ;
return - V_175 ;
}
if ( V_174 )
F_113 ( & V_164 -> V_172 ) ;
F_108 ( V_9 , V_164 ) ;
return 0 ;
}
static int
F_114 ( struct V_8 * V_9 , struct V_163 * V_164 )
{
int V_12 ;
unsigned long V_82 ;
F_63 ( V_9 , false ) ;
F_115 ( & V_9 -> V_176 ) ;
F_116 ( V_9 ) ;
F_53 ( V_9 -> V_86 -> V_87 , V_82 ) ;
V_12 = F_112 ( V_9 , V_164 , true ) ;
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
if ( ! V_12 )
V_12 = F_110 ( V_9 , V_164 ) ;
F_117 ( & V_9 -> V_176 ) ;
F_78 ( V_9 ) ;
return V_12 ;
}
static int F_118 ( struct V_39 * V_40 )
{
struct V_177 * V_178 ;
struct V_179 * V_180 ;
struct V_181 * V_182 ;
int V_183 ;
int V_184 ;
V_182 = V_40 -> V_182 ;
V_183 = F_119 ( V_182 ) ;
if ( V_183 < 0 )
return V_183 ;
if ( V_183 ) {
V_40 -> V_41 -> V_185 =
F_120 ( ( T_5 ) ( V_183 ) ) ;
V_178 = (struct V_177 * ) V_40 -> V_186 ;
F_121 (cmd, sg, sg_segments, i) {
V_178 [ V_184 ] . V_187 =
F_122 ( ( ( T_1 ) F_123 ( V_180 ) ) - 1 ) ;
V_178 [ V_184 ] . V_188 =
F_122 ( F_124 ( V_180 -> V_189 ) ) ;
V_178 [ V_184 ] . V_190 =
F_122 ( F_125 ( V_180 -> V_189 ) ) ;
V_178 [ V_184 ] . V_191 = 0 ;
}
} else {
V_40 -> V_41 -> V_185 = 0 ;
}
return 0 ;
}
static void F_126 ( struct V_8 * V_9 , T_1 V_192 )
{
T_1 V_193 = F_12 ( V_9 , V_194 ) ;
if ( V_9 -> V_30 == V_31 ) {
T_1 V_195 ;
V_195 = V_193 & V_196 ;
V_193 = V_195 | ( ( V_193 ^ V_192 ) & V_192 ) ;
} else {
V_193 |= V_192 ;
}
F_29 ( V_9 , V_193 , V_194 ) ;
}
static void F_127 ( struct V_8 * V_9 , T_1 V_192 )
{
T_1 V_193 = F_12 ( V_9 , V_194 ) ;
if ( V_9 -> V_30 == V_31 ) {
T_1 V_195 ;
V_195 = ( V_193 & V_196 ) &
~ ( V_192 & V_196 ) ;
V_193 = V_195 | ( ( V_193 & V_192 ) & ~ V_196 ) ;
} else {
V_193 &= ~ V_192 ;
}
F_29 ( V_9 , V_193 , V_194 ) ;
}
static void F_128 ( struct V_39 * V_40 ,
T_1 * V_197 , enum V_198 V_199 )
{
struct V_200 * V_201 = V_40 -> V_41 ;
T_1 V_202 ;
T_1 V_60 ;
if ( V_199 == V_203 ) {
V_202 = V_204 ;
* V_197 = V_205 ;
} else if ( V_199 == V_206 ) {
V_202 = V_207 ;
* V_197 = V_208 ;
} else {
V_202 = V_209 ;
* V_197 = V_210 ;
}
V_60 = V_202 | ( V_40 -> V_211
<< V_212 ) ;
if ( V_40 -> V_213 )
V_60 |= V_214 ;
V_201 -> V_42 . V_60 = F_122 ( V_60 ) ;
V_201 -> V_42 . V_61 = 0 ;
V_201 -> V_42 . V_43 =
F_122 ( V_215 ) ;
V_201 -> V_42 . V_216 = 0 ;
V_201 -> V_185 = 0 ;
}
static
void F_129 ( struct V_39 * V_40 , T_1 V_197 )
{
struct V_217 * V_218 = V_40 -> V_218 ;
unsigned short V_219 ;
V_218 -> V_42 . V_60 = F_130 (
V_220 , V_197 ,
V_40 -> V_221 , V_40 -> V_131 ) ;
V_218 -> V_42 . V_61 = F_130 (
V_222 , 0 , 0 , 0 ) ;
V_218 -> V_42 . V_43 = 0 ;
V_218 -> V_223 . V_224 =
F_131 ( V_40 -> V_182 -> V_225 . V_156 ) ;
V_219 = F_101 (unsigned short, lrbp->cmd->cmd_len, MAX_CDB_SIZE) ;
memset ( V_218 -> V_223 . V_226 , 0 , V_227 ) ;
memcpy ( V_218 -> V_223 . V_226 , V_40 -> V_182 -> V_228 , V_219 ) ;
memset ( V_40 -> V_59 , 0 , sizeof( struct V_58 ) ) ;
}
static void F_132 ( struct V_8 * V_9 ,
struct V_39 * V_40 , T_1 V_197 )
{
struct V_217 * V_218 = V_40 -> V_218 ;
struct V_229 * V_142 = & V_9 -> V_141 . V_142 ;
T_5 V_133 = F_100 ( V_142 -> V_154 . V_155 . V_156 ) ;
T_2 * V_149 = ( T_2 * ) V_40 -> V_218 + V_150 ;
V_218 -> V_42 . V_60 = F_130 (
V_230 , V_197 ,
V_40 -> V_221 , V_40 -> V_131 ) ;
V_218 -> V_42 . V_61 = F_130 (
0 , V_142 -> V_154 . V_231 , 0 , 0 ) ;
V_218 -> V_42 . V_43 = F_130 (
0 , 0 , V_133 >> 8 , ( T_2 ) V_133 ) ;
memcpy ( & V_218 -> V_145 , & V_142 -> V_154 . V_155 ,
V_146 ) ;
if ( V_142 -> V_154 . V_155 . V_147 == V_232 )
memcpy ( V_149 , V_142 -> V_157 , V_133 ) ;
memset ( V_40 -> V_59 , 0 , sizeof( struct V_58 ) ) ;
}
static inline void F_133 ( struct V_39 * V_40 )
{
struct V_217 * V_218 = V_40 -> V_218 ;
memset ( V_218 , 0 , sizeof( struct V_217 ) ) ;
V_218 -> V_42 . V_60 =
F_130 (
V_233 , 0 , 0 , V_40 -> V_131 ) ;
V_218 -> V_42 . V_61 = 0 ;
V_218 -> V_42 . V_43 = 0 ;
memset ( V_40 -> V_59 , 0 , sizeof( struct V_58 ) ) ;
}
static int F_134 ( struct V_8 * V_9 , struct V_39 * V_40 )
{
T_1 V_197 ;
int V_12 = 0 ;
if ( V_9 -> V_30 == V_234 )
V_40 -> V_211 = V_235 ;
else
V_40 -> V_211 = V_236 ;
F_128 ( V_40 , & V_197 , V_237 ) ;
if ( V_9 -> V_141 . type == V_238 )
F_132 ( V_9 , V_40 , V_197 ) ;
else if ( V_9 -> V_141 . type == V_239 )
F_133 ( V_40 ) ;
else
V_12 = - V_118 ;
return V_12 ;
}
static int F_135 ( struct V_8 * V_9 , struct V_39 * V_40 )
{
T_1 V_197 ;
int V_12 = 0 ;
if ( V_9 -> V_30 == V_234 )
V_40 -> V_211 = V_235 ;
else
V_40 -> V_211 = V_240 ;
if ( F_103 ( V_40 -> V_182 ) ) {
F_128 ( V_40 , & V_197 ,
V_40 -> V_182 -> V_241 ) ;
F_129 ( V_40 , V_197 ) ;
} else {
V_12 = - V_118 ;
}
return V_12 ;
}
static inline T_2 F_136 ( unsigned int V_242 )
{
if ( F_137 ( V_242 ) )
return ( V_242 & V_243 )
| V_244 ;
else
return V_242 & V_243 ;
}
static inline T_5 F_138 ( T_2 V_245 )
{
return ( V_245 & ~ V_244 ) | V_246 ;
}
static int F_139 ( struct V_247 * V_86 , struct V_181 * V_182 )
{
struct V_39 * V_40 ;
struct V_8 * V_9 ;
unsigned long V_82 ;
int V_10 ;
int V_26 = 0 ;
V_9 = F_140 ( V_86 ) ;
V_10 = V_182 -> V_154 -> V_10 ;
if ( ! F_3 ( V_9 , V_10 ) ) {
F_6 ( V_9 -> V_18 ,
L_9 ,
V_19 , V_10 , V_182 , V_182 -> V_154 ) ;
F_141 () ;
}
F_53 ( V_9 -> V_86 -> V_87 , V_82 ) ;
switch ( V_9 -> V_102 ) {
case V_103 :
break;
case V_248 :
V_26 = V_249 ;
goto V_250;
case V_251 :
F_142 ( V_182 , V_252 ) ;
V_182 -> V_253 ( V_182 ) ;
goto V_250;
default:
F_143 ( V_9 -> V_18 , 1 , L_10 ,
V_19 , V_9 -> V_102 ) ;
F_142 ( V_182 , V_254 ) ;
V_182 -> V_253 ( V_182 ) ;
goto V_250;
}
if ( F_65 ( V_9 ) ) {
F_142 ( V_182 , V_252 ) ;
V_182 -> V_253 ( V_182 ) ;
goto V_250;
}
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
if ( F_25 ( V_10 , & V_9 -> V_104 ) ) {
V_26 = V_249 ;
goto V_48;
}
V_26 = F_63 ( V_9 , true ) ;
if ( V_26 ) {
V_26 = V_249 ;
F_27 ( V_10 , & V_9 -> V_104 ) ;
goto V_48;
}
F_109 ( V_9 -> V_83 . V_88 != V_89 ) ;
V_40 = & V_9 -> V_255 [ V_10 ] ;
F_109 ( V_40 -> V_182 ) ;
V_40 -> V_182 = V_182 ;
V_40 -> V_256 = V_138 ;
V_40 -> V_134 = V_182 -> V_134 ;
V_40 -> V_131 = V_10 ;
V_40 -> V_221 = F_136 ( V_182 -> V_111 -> V_221 ) ;
V_40 -> V_213 = ! F_144 ( V_9 ) ? true : false ;
F_135 ( V_9 , V_40 ) ;
V_26 = F_118 ( V_40 ) ;
if ( V_26 ) {
V_40 -> V_182 = NULL ;
F_27 ( V_10 , & V_9 -> V_104 ) ;
goto V_48;
}
F_53 ( V_9 -> V_86 -> V_87 , V_82 ) ;
F_97 ( V_9 , V_10 ) ;
V_250:
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
V_48:
return V_26 ;
}
static int F_145 ( struct V_8 * V_9 ,
struct V_39 * V_40 , enum V_257 V_258 , int V_10 )
{
V_40 -> V_182 = NULL ;
V_40 -> V_256 = 0 ;
V_40 -> V_134 = NULL ;
V_40 -> V_131 = V_10 ;
V_40 -> V_221 = 0 ;
V_40 -> V_213 = true ;
V_9 -> V_141 . type = V_258 ;
return F_134 ( V_9 , V_40 ) ;
}
static int
F_146 ( struct V_8 * V_9 , int V_10 )
{
int V_26 = 0 ;
unsigned long V_82 ;
T_1 V_22 = 1 << V_10 ;
F_53 ( V_9 -> V_86 -> V_87 , V_82 ) ;
F_28 ( V_9 , V_10 ) ;
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
V_26 = F_10 ( V_9 ,
V_132 ,
V_22 , ~ V_22 , 1000 , 1000 , true ) ;
return V_26 ;
}
static int
F_147 ( struct V_8 * V_9 , struct V_39 * V_40 )
{
struct V_139 * V_140 = & V_9 -> V_141 . V_142 . V_143 ;
V_140 -> V_143 = F_37 ( V_40 -> V_59 ) >>
V_259 ;
return V_140 -> V_143 ;
}
static int
F_148 ( struct V_8 * V_9 , struct V_39 * V_40 )
{
int V_260 ;
int V_26 = 0 ;
V_260 = F_35 ( V_40 -> V_59 ) ;
switch ( V_260 ) {
case V_261 :
if ( V_9 -> V_141 . type != V_239 ) {
V_26 = - V_118 ;
F_6 ( V_9 -> V_18 , L_11 ,
V_19 , V_260 ) ;
}
break;
case V_262 :
V_26 = F_147 ( V_9 , V_40 ) ;
if ( ! V_26 )
V_26 = F_102 ( V_9 , V_40 ) ;
break;
case V_263 :
V_26 = - V_264 ;
F_6 ( V_9 -> V_18 , L_12 ,
V_19 ) ;
break;
default:
V_26 = - V_118 ;
F_6 ( V_9 -> V_18 , L_13 ,
V_19 , V_260 ) ;
break;
}
return V_26 ;
}
static int F_149 ( struct V_8 * V_9 ,
struct V_39 * V_40 , int V_265 )
{
int V_26 = 0 ;
unsigned long V_266 ;
unsigned long V_82 ;
V_266 = F_111 ( V_9 -> V_141 . V_267 ,
F_11 ( V_265 ) ) ;
F_53 ( V_9 -> V_86 -> V_87 , V_82 ) ;
V_9 -> V_141 . V_267 = NULL ;
if ( F_103 ( V_266 ) ) {
V_26 = F_20 ( V_40 ) ;
if ( ! V_26 )
V_26 = F_148 ( V_9 , V_40 ) ;
}
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
if ( ! V_266 ) {
V_26 = - V_29 ;
F_150 ( V_9 -> V_18 , L_14 ,
V_19 , V_40 -> V_131 ) ;
if ( ! F_146 ( V_9 , V_40 -> V_131 ) )
V_26 = - V_100 ;
F_30 ( V_9 , V_40 -> V_131 ) ;
}
return V_26 ;
}
static bool F_151 ( struct V_8 * V_9 , int * V_268 )
{
int V_10 ;
bool V_12 = false ;
unsigned long V_269 ;
if ( ! V_268 )
goto V_48;
do {
V_269 = ~ V_9 -> V_104 ;
V_10 = F_152 ( & V_269 , V_9 -> V_11 ) ;
if ( V_10 >= V_9 -> V_11 )
goto V_48;
} while ( F_25 ( V_10 , & V_9 -> V_104 ) );
* V_268 = V_10 ;
V_12 = true ;
V_48:
return V_12 ;
}
static inline void F_153 ( struct V_8 * V_9 , int V_10 )
{
F_27 ( V_10 , & V_9 -> V_104 ) ;
}
static int F_154 ( struct V_8 * V_9 ,
enum V_257 V_258 , int V_27 )
{
struct V_39 * V_40 ;
int V_26 ;
int V_10 ;
struct V_174 V_270 ;
unsigned long V_82 ;
F_155 ( V_9 -> V_141 . V_271 , F_151 ( V_9 , & V_10 ) ) ;
F_113 ( & V_270 ) ;
V_40 = & V_9 -> V_255 [ V_10 ] ;
F_109 ( V_40 -> V_182 ) ;
V_26 = F_145 ( V_9 , V_40 , V_258 , V_10 ) ;
if ( F_156 ( V_26 ) )
goto V_272;
V_9 -> V_141 . V_267 = & V_270 ;
F_157 () ;
F_53 ( V_9 -> V_86 -> V_87 , V_82 ) ;
F_97 ( V_9 , V_10 ) ;
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
V_26 = F_149 ( V_9 , V_40 , V_27 ) ;
V_272:
F_153 ( V_9 , V_10 ) ;
F_158 ( & V_9 -> V_141 . V_271 ) ;
return V_26 ;
}
static inline void F_159 ( struct V_8 * V_9 ,
struct V_273 * * V_154 , struct V_139 * * V_143 ,
enum V_274 V_147 , T_2 V_275 , T_2 V_276 , T_2 V_277 )
{
* V_154 = & V_9 -> V_141 . V_142 . V_154 ;
* V_143 = & V_9 -> V_141 . V_142 . V_143 ;
memset ( * V_154 , 0 , sizeof( struct V_273 ) ) ;
memset ( * V_143 , 0 , sizeof( struct V_139 ) ) ;
( * V_154 ) -> V_155 . V_147 = V_147 ;
( * V_154 ) -> V_155 . V_275 = V_275 ;
( * V_154 ) -> V_155 . V_276 = V_276 ;
( * V_154 ) -> V_155 . V_277 = V_277 ;
}
static int F_160 ( struct V_8 * V_9 ,
enum V_274 V_147 , enum V_278 V_275 , bool * V_279 )
{
int V_12 ;
int V_280 ;
for ( V_280 = 0 ; V_280 < V_281 ; V_280 ++ ) {
V_12 = F_161 ( V_9 , V_147 , V_275 , V_279 ) ;
if ( V_12 )
F_150 ( V_9 -> V_18 ,
L_15 ,
V_19 , V_12 , V_280 ) ;
else
break;
}
if ( V_12 )
F_6 ( V_9 -> V_18 ,
L_16 ,
V_19 , V_147 , V_275 , V_12 , V_280 ) ;
return V_12 ;
}
int F_161 ( struct V_8 * V_9 , enum V_274 V_147 ,
enum V_278 V_275 , bool * V_279 )
{
struct V_273 * V_154 = NULL ;
struct V_139 * V_143 = NULL ;
int V_26 , V_276 = 0 , V_277 = 0 ;
int V_27 = V_282 ;
F_162 ( ! V_9 ) ;
F_63 ( V_9 , false ) ;
F_115 ( & V_9 -> V_141 . V_283 ) ;
F_159 ( V_9 , & V_154 , & V_143 , V_147 , V_275 , V_276 ,
V_277 ) ;
switch ( V_147 ) {
case V_284 :
case V_285 :
case V_286 :
V_154 -> V_231 = V_287 ;
break;
case V_288 :
V_154 -> V_231 = V_289 ;
if ( ! V_279 ) {
F_6 ( V_9 -> V_18 , L_17 ,
V_19 ) ;
V_26 = - V_118 ;
goto V_250;
}
break;
default:
F_6 ( V_9 -> V_18 ,
L_18 ,
V_19 , V_147 ) ;
V_26 = - V_118 ;
goto V_250;
}
if ( V_275 == V_290 )
V_27 = V_291 ;
V_26 = F_154 ( V_9 , V_238 , V_27 ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 ,
L_19 ,
V_19 , V_275 , V_26 ) ;
goto V_250;
}
if ( V_279 )
* V_279 = ( F_36 ( V_143 -> V_144 . V_117 ) &
V_292 ) & 0x1 ;
V_250:
F_117 ( & V_9 -> V_141 . V_283 ) ;
F_78 ( V_9 ) ;
return V_26 ;
}
static int F_163 ( struct V_8 * V_9 , enum V_274 V_147 ,
enum V_293 V_275 , T_2 V_276 , T_2 V_277 , T_1 * V_294 )
{
struct V_273 * V_154 = NULL ;
struct V_139 * V_143 = NULL ;
int V_26 ;
F_162 ( ! V_9 ) ;
F_63 ( V_9 , false ) ;
if ( ! V_294 ) {
F_6 ( V_9 -> V_18 , L_20 ,
V_19 , V_147 ) ;
V_26 = - V_118 ;
goto V_48;
}
F_115 ( & V_9 -> V_141 . V_283 ) ;
F_159 ( V_9 , & V_154 , & V_143 , V_147 , V_275 , V_276 ,
V_277 ) ;
switch ( V_147 ) {
case V_295 :
V_154 -> V_231 = V_287 ;
V_154 -> V_155 . V_117 = F_131 ( * V_294 ) ;
break;
case V_296 :
V_154 -> V_231 = V_289 ;
break;
default:
F_6 ( V_9 -> V_18 , L_21 ,
V_19 , V_147 ) ;
V_26 = - V_118 ;
goto V_250;
}
V_26 = F_154 ( V_9 , V_238 , V_282 ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_22 ,
V_19 , V_147 , V_275 , V_26 ) ;
goto V_250;
}
* V_294 = F_36 ( V_143 -> V_144 . V_117 ) ;
V_250:
F_117 ( & V_9 -> V_141 . V_283 ) ;
V_48:
F_78 ( V_9 ) ;
return V_26 ;
}
static int F_164 ( struct V_8 * V_9 ,
enum V_274 V_147 , enum V_293 V_275 , T_2 V_276 , T_2 V_277 ,
T_1 * V_294 )
{
int V_12 = 0 ;
T_1 V_280 ;
for ( V_280 = V_281 ; V_280 > 0 ; V_280 -- ) {
V_12 = F_163 ( V_9 , V_147 , V_275 , V_276 ,
V_277 , V_294 ) ;
if ( V_12 )
F_150 ( V_9 -> V_18 , L_15 ,
V_19 , V_12 , V_280 ) ;
else
break;
}
if ( V_12 )
F_6 ( V_9 -> V_18 ,
L_23 ,
V_19 , V_275 , V_12 , V_281 ) ;
return V_12 ;
}
static int F_165 ( struct V_8 * V_9 ,
enum V_274 V_147 , enum V_297 V_275 , T_2 V_276 ,
T_2 V_277 , T_2 * V_298 , int * V_152 )
{
struct V_273 * V_154 = NULL ;
struct V_139 * V_143 = NULL ;
int V_26 ;
F_162 ( ! V_9 ) ;
F_63 ( V_9 , false ) ;
if ( ! V_298 ) {
F_6 ( V_9 -> V_18 , L_24 ,
V_19 , V_147 ) ;
V_26 = - V_118 ;
goto V_48;
}
if ( * V_152 <= V_299 || * V_152 > V_300 ) {
F_6 ( V_9 -> V_18 , L_25 ,
V_19 , * V_152 ) ;
V_26 = - V_118 ;
goto V_48;
}
F_115 ( & V_9 -> V_141 . V_283 ) ;
F_159 ( V_9 , & V_154 , & V_143 , V_147 , V_275 , V_276 ,
V_277 ) ;
V_9 -> V_141 . V_142 . V_157 = V_298 ;
V_154 -> V_155 . V_156 = F_166 ( * V_152 ) ;
switch ( V_147 ) {
case V_232 :
V_154 -> V_231 = V_287 ;
break;
case V_148 :
V_154 -> V_231 = V_289 ;
break;
default:
F_6 ( V_9 -> V_18 ,
L_26 ,
V_19 , V_147 ) ;
V_26 = - V_118 ;
goto V_250;
}
V_26 = F_154 ( V_9 , V_238 , V_282 ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_22 ,
V_19 , V_147 , V_275 , V_26 ) ;
goto V_250;
}
V_9 -> V_141 . V_142 . V_157 = NULL ;
* V_152 = F_100 ( V_143 -> V_144 . V_156 ) ;
V_250:
F_117 ( & V_9 -> V_141 . V_283 ) ;
V_48:
F_78 ( V_9 ) ;
return V_26 ;
}
int F_167 ( struct V_8 * V_9 ,
enum V_274 V_147 , enum V_297 V_275 , T_2 V_276 ,
T_2 V_277 , T_2 * V_298 , int * V_152 )
{
int V_26 ;
int V_280 ;
for ( V_280 = V_281 ; V_280 > 0 ; V_280 -- ) {
V_26 = F_165 ( V_9 , V_147 , V_275 , V_276 ,
V_277 , V_298 , V_152 ) ;
if ( ! V_26 || V_26 == - V_118 )
break;
}
return V_26 ;
}
static int F_168 ( struct V_8 * V_9 ,
enum V_297 V_301 ,
int V_302 ,
T_1 V_303 ,
T_2 * V_304 ,
T_1 V_305 )
{
int V_12 ;
T_2 * V_298 ;
T_1 V_306 ;
bool V_307 = true ;
if ( V_301 >= V_308 )
return - V_118 ;
V_306 = V_309 [ V_301 ] ;
if ( ( V_303 + V_305 ) > V_306 )
return - V_118 ;
if ( ! V_303 && ( V_305 == V_306 ) ) {
V_298 = V_304 ;
V_307 = false ;
} else {
V_298 = F_169 ( V_306 , V_310 ) ;
if ( ! V_298 )
return - V_311 ;
}
V_12 = F_167 ( V_9 , V_148 ,
V_301 , V_302 , 0 , V_298 ,
& V_306 ) ;
if ( V_12 || ( V_306 < V_309 [ V_301 ] ) ||
( V_298 [ V_312 ] !=
V_309 [ V_301 ] )
|| ( V_298 [ V_313 ] != V_301 ) ) {
F_6 ( V_9 -> V_18 , L_27 ,
V_19 , V_301 , V_303 , V_306 , V_12 ) ;
if ( ! V_12 )
V_12 = - V_118 ;
goto V_48;
}
if ( V_307 )
memcpy ( V_304 , & V_298 [ V_303 ] , V_305 ) ;
V_48:
if ( V_307 )
F_170 ( V_298 ) ;
return V_12 ;
}
static inline int F_171 ( struct V_8 * V_9 ,
enum V_297 V_301 ,
int V_302 ,
T_2 * V_114 ,
T_1 V_187 )
{
return F_168 ( V_9 , V_301 , V_302 , 0 , V_114 , V_187 ) ;
}
static inline int F_172 ( struct V_8 * V_9 ,
T_2 * V_114 ,
T_1 V_187 )
{
return F_171 ( V_9 , V_314 , 0 , V_114 , V_187 ) ;
}
int F_173 ( struct V_8 * V_9 , T_2 * V_114 , T_1 V_187 )
{
return F_171 ( V_9 , V_315 , 0 , V_114 , V_187 ) ;
}
int F_174 ( struct V_8 * V_9 , int V_302 , T_2 * V_114 ,
T_1 V_187 , bool V_316 )
{
int V_26 = 0 ;
V_26 = F_171 ( V_9 ,
V_317 , V_302 , V_114 , V_187 ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_28 ,
V_19 , V_281 , V_26 ) ;
goto V_48;
}
if ( V_316 ) {
int V_318 ;
int V_319 ;
int V_184 ;
char * V_320 ;
V_318 = V_114 [ 0 ] ;
V_319 = ( V_318 - V_321 ) / 2 + 1 ;
if ( V_187 < V_319 + V_321 ) {
F_6 ( V_9 -> V_18 , L_29 ,
V_19 ) ;
V_26 = - V_311 ;
goto V_48;
}
V_320 = F_169 ( V_319 , V_310 ) ;
if ( ! V_320 ) {
V_26 = - V_311 ;
goto V_48;
}
F_175 ( ( V_322 * ) & V_114 [ V_321 ] ,
V_318 - V_321 ,
V_323 , V_320 , V_319 ) ;
for ( V_184 = 0 ; V_184 < V_319 ; V_184 ++ )
F_9 ( & V_320 [ V_184 ] ) ;
memset ( V_114 + V_321 , 0 ,
V_187 - V_321 ) ;
memcpy ( V_114 + V_321 , V_320 , V_319 ) ;
V_114 [ V_312 ] = V_319 + V_321 ;
F_170 ( V_320 ) ;
}
V_48:
return V_26 ;
}
static inline int F_176 ( struct V_8 * V_9 ,
int V_221 ,
enum V_324 V_303 ,
T_2 * V_304 ,
T_1 V_305 )
{
if ( V_221 != V_325 && ( V_221 >= V_326 ) )
return - V_327 ;
return F_168 ( V_9 , V_328 , V_221 ,
V_303 , V_304 , V_305 ) ;
}
static int F_177 ( struct V_8 * V_9 )
{
T_4 V_329 , V_330 , V_331 ;
V_331 = ( sizeof( struct V_332 ) * V_9 -> V_11 ) ;
V_9 -> V_333 = F_178 ( V_9 -> V_18 ,
V_331 ,
& V_9 -> V_334 ,
V_310 ) ;
if ( ! V_9 -> V_333 ||
F_109 ( V_9 -> V_334 & ( V_115 - 1 ) ) ) {
F_6 ( V_9 -> V_18 ,
L_30 ) ;
goto V_48;
}
V_330 = ( sizeof( struct V_200 ) * V_9 -> V_11 ) ;
V_9 -> V_335 = F_178 ( V_9 -> V_18 ,
V_330 ,
& V_9 -> V_336 ,
V_310 ) ;
if ( ! V_9 -> V_335 ||
F_109 ( V_9 -> V_336 & ( V_115 - 1 ) ) ) {
F_6 ( V_9 -> V_18 ,
L_31 ) ;
goto V_48;
}
V_329 = sizeof( struct V_45 ) * V_9 -> V_50 ;
V_9 -> V_337 = F_178 ( V_9 -> V_18 ,
V_329 ,
& V_9 -> V_338 ,
V_310 ) ;
if ( ! V_9 -> V_337 ||
F_109 ( V_9 -> V_338 & ( V_115 - 1 ) ) ) {
F_6 ( V_9 -> V_18 ,
L_32 ) ;
goto V_48;
}
V_9 -> V_255 = F_179 ( V_9 -> V_18 ,
V_9 -> V_11 * sizeof( struct V_39 ) ,
V_310 ) ;
if ( ! V_9 -> V_255 ) {
F_6 ( V_9 -> V_18 , L_33 ) ;
goto V_48;
}
return 0 ;
V_48:
return - V_311 ;
}
static void F_180 ( struct V_8 * V_9 )
{
struct V_332 * V_339 ;
struct V_200 * V_340 ;
T_6 V_341 ;
T_6 V_342 ;
T_5 V_343 ;
T_5 V_344 ;
int V_345 ;
int V_184 ;
V_340 = V_9 -> V_335 ;
V_339 = V_9 -> V_333 ;
V_343 =
F_181 ( struct V_332 , V_346 ) ;
V_344 =
F_181 ( struct V_332 , V_178 ) ;
V_345 = sizeof( struct V_332 ) ;
V_341 = V_9 -> V_334 ;
for ( V_184 = 0 ; V_184 < V_9 -> V_11 ; V_184 ++ ) {
V_342 =
( V_341 + ( V_345 * V_184 ) ) ;
V_340 [ V_184 ] . V_347 =
F_122 ( F_124 ( V_342 ) ) ;
V_340 [ V_184 ] . V_348 =
F_122 ( F_125 ( V_342 ) ) ;
V_340 [ V_184 ] . V_349 =
F_120 ( ( V_343 >> 2 ) ) ;
V_340 [ V_184 ] . V_350 =
F_120 ( ( V_344 >> 2 ) ) ;
V_340 [ V_184 ] . V_351 =
F_120 ( V_352 >> 2 ) ;
V_9 -> V_255 [ V_184 ] . V_41 = ( V_340 + V_184 ) ;
V_9 -> V_255 [ V_184 ] . V_218 =
(struct V_217 * ) ( V_339 + V_184 ) ;
V_9 -> V_255 [ V_184 ] . V_59 =
(struct V_58 * ) V_339 [ V_184 ] . V_346 ;
V_9 -> V_255 [ V_184 ] . V_186 =
(struct V_177 * ) V_339 [ V_184 ] . V_178 ;
}
}
static int F_182 ( struct V_8 * V_9 )
{
struct V_163 V_164 = { 0 } ;
int V_12 ;
V_164 . V_169 = V_353 ;
V_12 = F_114 ( V_9 , & V_164 ) ;
if ( V_12 )
F_6 ( V_9 -> V_18 ,
L_34 , V_12 ) ;
return V_12 ;
}
static inline void F_116 ( struct V_8 * V_9 )
{
#define F_183 1000
unsigned long V_354 ;
if ( ! ( V_9 -> V_34 & V_355 ) )
return;
if ( F_156 ( ! F_94 ( V_9 -> V_356 ) ) ) {
V_354 = F_183 ;
} else {
unsigned long V_357 =
( unsigned long ) F_94 (
F_95 ( F_92 () ,
V_9 -> V_356 ) ) ;
if ( V_357 < F_183 )
V_354 =
F_183 - V_357 ;
else
return;
}
F_13 ( V_354 , V_354 + 50 ) ;
}
int F_184 ( struct V_8 * V_9 , T_1 V_358 ,
T_2 V_359 , T_1 V_360 , T_2 V_361 )
{
struct V_163 V_164 = { 0 } ;
static const char * const V_362 [] = {
L_35 ,
L_36
} ;
const char * V_193 = V_362 [ ! ! V_361 ] ;
int V_12 ;
int V_280 = V_363 ;
V_164 . V_169 = V_361 ?
V_364 : V_365 ;
V_164 . V_165 = V_358 ;
V_164 . V_167 = F_185 ( V_359 ) ;
V_164 . V_168 = V_360 ;
do {
V_12 = F_114 ( V_9 , & V_164 ) ;
if ( V_12 )
F_150 ( V_9 -> V_18 , L_37 ,
V_193 , F_186 ( V_358 ) , V_360 , V_12 ) ;
} while ( V_12 && V_361 && -- V_280 );
if ( ! V_280 )
F_6 ( V_9 -> V_18 , L_38 ,
V_193 , F_186 ( V_358 ) , V_360 ,
V_280 ) ;
return V_12 ;
}
int F_187 ( struct V_8 * V_9 , T_1 V_358 ,
T_1 * V_360 , T_2 V_361 )
{
struct V_163 V_164 = { 0 } ;
static const char * const V_362 [] = {
L_39 ,
L_40
} ;
const char * V_366 = V_362 [ ! ! V_361 ] ;
int V_12 ;
int V_280 = V_363 ;
struct V_367 V_368 ;
struct V_367 V_369 ;
bool V_370 = false ;
if ( V_361 && ( V_9 -> V_34 & V_371 ) ) {
V_368 = V_9 -> V_372 ;
V_369 = V_368 ;
if ( V_368 . V_373 == V_374 ||
V_368 . V_375 == V_374 ) {
V_369 . V_373 = V_376 ;
V_369 . V_375 = V_376 ;
V_370 = true ;
} else if ( V_368 . V_373 == V_377 ||
V_368 . V_375 == V_377 ) {
V_369 . V_373 = V_378 ;
V_369 . V_375 = V_378 ;
V_370 = true ;
}
if ( V_370 ) {
V_12 = F_188 ( V_9 , & V_369 ) ;
if ( V_12 )
goto V_48;
}
}
V_164 . V_169 = V_361 ?
V_379 : V_380 ;
V_164 . V_165 = V_358 ;
do {
V_12 = F_114 ( V_9 , & V_164 ) ;
if ( V_12 )
F_150 ( V_9 -> V_18 , L_41 ,
V_366 , F_186 ( V_358 ) , V_12 ) ;
} while ( V_12 && V_361 && -- V_280 );
if ( ! V_280 )
F_6 ( V_9 -> V_18 , L_42 ,
V_366 , F_186 ( V_358 ) , V_280 ) ;
if ( V_360 && ! V_12 )
* V_360 = V_164 . V_168 ;
if ( V_361 && ( V_9 -> V_34 & V_371 )
&& V_370 )
F_188 ( V_9 , & V_368 ) ;
V_48:
return V_12 ;
}
static int F_189 ( struct V_8 * V_9 , struct V_163 * V_182 )
{
struct V_174 V_107 ;
unsigned long V_82 ;
T_2 V_381 ;
int V_12 ;
bool V_382 = false ;
F_115 ( & V_9 -> V_176 ) ;
F_113 ( & V_107 ) ;
F_116 ( V_9 ) ;
F_53 ( V_9 -> V_86 -> V_87 , V_82 ) ;
V_9 -> V_107 = & V_107 ;
if ( F_12 ( V_9 , V_194 ) & V_383 ) {
F_127 ( V_9 , V_383 ) ;
F_157 () ;
V_382 = true ;
}
V_12 = F_112 ( V_9 , V_182 , false ) ;
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
if ( V_12 ) {
F_6 ( V_9 -> V_18 ,
L_43 ,
V_182 -> V_169 , V_182 -> V_168 , V_12 ) ;
goto V_48;
}
if ( ! F_111 ( V_9 -> V_107 ,
F_11 ( V_173 ) ) ) {
F_6 ( V_9 -> V_18 ,
L_44 ,
V_182 -> V_169 , V_182 -> V_168 ) ;
V_12 = - V_29 ;
goto V_48;
}
V_381 = F_107 ( V_9 ) ;
if ( V_381 != V_384 ) {
F_6 ( V_9 -> V_18 ,
L_45 ,
V_182 -> V_169 , V_381 ) ;
V_12 = ( V_381 != V_385 ) ? V_381 : - 1 ;
}
V_48:
F_53 ( V_9 -> V_86 -> V_87 , V_82 ) ;
V_9 -> V_106 = NULL ;
V_9 -> V_107 = NULL ;
if ( V_382 )
F_126 ( V_9 , V_383 ) ;
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
F_117 ( & V_9 -> V_176 ) ;
return V_12 ;
}
static int F_190 ( struct V_8 * V_9 , T_2 V_123 )
{
struct V_163 V_164 = { 0 } ;
int V_12 ;
if ( V_9 -> V_34 & V_386 ) {
V_12 = F_191 ( V_9 ,
F_192 ( V_387 , 0 ) , 1 ) ;
if ( V_12 ) {
F_6 ( V_9 -> V_18 , L_46 ,
V_19 , V_12 ) ;
goto V_48;
}
}
V_164 . V_169 = V_365 ;
V_164 . V_165 = F_193 ( V_388 ) ;
V_164 . V_168 = V_123 ;
F_63 ( V_9 , false ) ;
V_12 = F_189 ( V_9 , & V_164 ) ;
F_78 ( V_9 ) ;
V_48:
return V_12 ;
}
static int F_194 ( struct V_8 * V_9 )
{
int V_12 ;
unsigned long V_82 ;
F_53 ( V_9 -> V_86 -> V_87 , V_82 ) ;
V_9 -> V_102 = V_248 ;
F_195 ( V_9 ) ;
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
V_12 = F_196 ( V_9 ) ;
F_53 ( V_9 -> V_86 -> V_87 , V_82 ) ;
if ( V_12 )
V_9 -> V_102 = V_251 ;
F_197 ( V_9 ) ;
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
if ( V_12 )
F_6 ( V_9 -> V_18 , L_47 ,
V_19 , V_12 ) ;
return V_12 ;
}
static int F_198 ( struct V_8 * V_9 )
{
int V_12 ;
struct V_163 V_164 = { 0 } ;
V_164 . V_169 = V_389 ;
V_12 = F_189 ( V_9 , & V_164 ) ;
if ( V_12 ) {
F_6 ( V_9 -> V_18 , L_48 ,
V_19 , V_12 ) ;
if ( F_194 ( V_9 ) )
V_12 = - V_390 ;
}
return V_12 ;
}
static int F_71 ( struct V_8 * V_9 )
{
int V_12 = 0 , V_280 ;
for ( V_280 = V_391 ; V_280 > 0 ; V_280 -- ) {
V_12 = F_198 ( V_9 ) ;
if ( ! V_12 || V_12 == - V_390 )
goto V_48;
}
V_48:
return V_12 ;
}
static int F_58 ( struct V_8 * V_9 )
{
struct V_163 V_164 = { 0 } ;
int V_12 ;
V_164 . V_169 = V_392 ;
V_12 = F_189 ( V_9 , & V_164 ) ;
if ( V_12 ) {
F_6 ( V_9 -> V_18 , L_49 ,
V_19 , V_12 ) ;
V_12 = F_194 ( V_9 ) ;
}
return V_12 ;
}
static void F_199 ( struct V_8 * V_9 )
{
V_9 -> V_372 . V_393 = V_394 ;
V_9 -> V_372 . V_395 = V_394 ;
V_9 -> V_372 . V_396 = 1 ;
V_9 -> V_372 . V_397 = 1 ;
V_9 -> V_372 . V_375 = V_378 ;
V_9 -> V_372 . V_373 = V_378 ;
V_9 -> V_372 . V_398 = 0 ;
}
static int F_200 ( struct V_8 * V_9 )
{
struct V_367 * V_372 = & V_9 -> V_399 . V_400 ;
if ( V_9 -> V_399 . V_401 )
return 0 ;
V_372 -> V_373 = V_376 ;
V_372 -> V_375 = V_376 ;
V_372 -> V_398 = V_402 ;
F_201 ( V_9 , F_193 ( V_403 ) ,
& V_372 -> V_396 ) ;
F_201 ( V_9 , F_193 ( V_404 ) ,
& V_372 -> V_397 ) ;
if ( ! V_372 -> V_396 || ! V_372 -> V_397 ) {
F_6 ( V_9 -> V_18 , L_50 ,
V_19 ,
V_372 -> V_396 ,
V_372 -> V_397 ) ;
return - V_118 ;
}
F_201 ( V_9 , F_193 ( V_405 ) , & V_372 -> V_393 ) ;
if ( ! V_372 -> V_393 ) {
F_201 ( V_9 , F_193 ( V_406 ) ,
& V_372 -> V_393 ) ;
if ( ! V_372 -> V_393 ) {
F_6 ( V_9 -> V_18 , L_51 ,
V_19 , V_372 -> V_393 ) ;
return - V_118 ;
}
V_372 -> V_375 = V_378 ;
}
F_202 ( V_9 , F_193 ( V_405 ) ,
& V_372 -> V_395 ) ;
if ( ! V_372 -> V_395 ) {
F_202 ( V_9 , F_193 ( V_406 ) ,
& V_372 -> V_395 ) ;
if ( ! V_372 -> V_395 ) {
F_6 ( V_9 -> V_18 , L_52 ,
V_19 , V_372 -> V_395 ) ;
return - V_118 ;
}
V_372 -> V_373 = V_378 ;
}
V_9 -> V_399 . V_401 = true ;
return 0 ;
}
static int F_188 ( struct V_8 * V_9 ,
struct V_367 * V_407 )
{
int V_12 ;
if ( V_407 -> V_393 == V_9 -> V_372 . V_393 &&
V_407 -> V_395 == V_9 -> V_372 . V_395 &&
V_407 -> V_396 == V_9 -> V_372 . V_396 &&
V_407 -> V_397 == V_9 -> V_372 . V_397 &&
V_407 -> V_375 == V_9 -> V_372 . V_375 &&
V_407 -> V_373 == V_9 -> V_372 . V_373 &&
V_407 -> V_398 == V_9 -> V_372 . V_398 ) {
F_150 ( V_9 -> V_18 , L_53 , V_19 ) ;
return 0 ;
}
F_191 ( V_9 , F_193 ( V_408 ) , V_407 -> V_393 ) ;
F_191 ( V_9 , F_193 ( V_409 ) ,
V_407 -> V_396 ) ;
if ( V_407 -> V_375 == V_376 ||
V_407 -> V_375 == V_374 )
F_191 ( V_9 , F_193 ( V_410 ) , TRUE ) ;
else
F_191 ( V_9 , F_193 ( V_410 ) , FALSE ) ;
F_191 ( V_9 , F_193 ( V_411 ) , V_407 -> V_395 ) ;
F_191 ( V_9 , F_193 ( V_412 ) ,
V_407 -> V_397 ) ;
if ( V_407 -> V_373 == V_376 ||
V_407 -> V_373 == V_374 )
F_191 ( V_9 , F_193 ( V_413 ) , TRUE ) ;
else
F_191 ( V_9 , F_193 ( V_413 ) , FALSE ) ;
if ( V_407 -> V_375 == V_376 ||
V_407 -> V_373 == V_376 ||
V_407 -> V_375 == V_374 ||
V_407 -> V_373 == V_374 )
F_191 ( V_9 , F_193 ( V_414 ) ,
V_407 -> V_398 ) ;
V_12 = F_190 ( V_9 , V_407 -> V_375 << 4
| V_407 -> V_373 ) ;
if ( V_12 ) {
F_6 ( V_9 -> V_18 ,
L_54 , V_19 , V_12 ) ;
} else {
F_203 ( V_9 , V_415 , NULL ,
V_407 ) ;
memcpy ( & V_9 -> V_372 , V_407 ,
sizeof( struct V_367 ) ) ;
}
return V_12 ;
}
static int F_204 ( struct V_8 * V_9 ,
struct V_367 * V_416 )
{
struct V_367 V_417 = { 0 } ;
int V_12 ;
V_12 = F_203 ( V_9 , V_418 ,
V_416 , & V_417 ) ;
if ( V_12 )
memcpy ( & V_417 , V_416 , sizeof( V_417 ) ) ;
V_12 = F_188 ( V_9 , & V_417 ) ;
return V_12 ;
}
static int F_205 ( struct V_8 * V_9 )
{
int V_184 ;
int V_26 ;
bool V_279 = 1 ;
V_26 = F_160 ( V_9 , V_284 ,
V_290 , NULL ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 ,
L_55 ,
V_19 , V_26 ) ;
goto V_48;
}
for ( V_184 = 0 ; V_184 < 1000 && ! V_26 && V_279 ; V_184 ++ )
V_26 = F_160 ( V_9 , V_288 ,
V_290 , & V_279 ) ;
if ( V_26 )
F_6 ( V_9 -> V_18 ,
L_56 ,
V_19 , V_26 ) ;
else if ( V_279 )
F_6 ( V_9 -> V_18 ,
L_57 ,
V_19 ) ;
V_48:
return V_26 ;
}
static int F_206 ( struct V_8 * V_9 )
{
int V_26 = 0 ;
T_1 V_21 ;
F_126 ( V_9 , V_419 ) ;
if ( F_144 ( V_9 ) )
F_41 ( V_9 , V_9 -> V_11 - 1 , V_420 ) ;
else
F_44 ( V_9 ) ;
F_29 ( V_9 , F_124 ( V_9 -> V_336 ) ,
V_421 ) ;
F_29 ( V_9 , F_125 ( V_9 -> V_336 ) ,
V_422 ) ;
F_29 ( V_9 , F_124 ( V_9 -> V_338 ) ,
V_423 ) ;
F_29 ( V_9 , F_125 ( V_9 -> V_338 ) ,
V_424 ) ;
F_157 () ;
V_21 = F_12 ( V_9 , V_37 ) ;
if ( ! ( F_32 ( V_21 ) ) ) {
F_45 ( V_9 ) ;
} else {
F_6 ( V_9 -> V_18 ,
L_58 ) ;
V_26 = - V_175 ;
goto V_48;
}
V_48:
return V_26 ;
}
static inline void F_207 ( struct V_8 * V_9 , bool V_25 )
{
int V_26 ;
F_29 ( V_9 , V_425 , V_76 ) ;
V_26 = F_10 ( V_9 , V_76 ,
V_75 , V_425 ,
10 , 1 , V_25 ) ;
if ( V_26 )
F_6 ( V_9 -> V_18 , L_59 , V_19 ) ;
}
static int F_208 ( struct V_8 * V_9 )
{
int V_426 ;
if ( ! F_47 ( V_9 ) )
F_207 ( V_9 , true ) ;
F_209 ( V_9 ) ;
F_210 ( V_9 , V_418 ) ;
F_46 ( V_9 ) ;
F_211 ( 1 ) ;
V_426 = 10 ;
while ( F_47 ( V_9 ) ) {
if ( V_426 ) {
V_426 -- ;
} else {
F_6 ( V_9 -> V_18 ,
L_60 ) ;
return - V_175 ;
}
F_211 ( 5 ) ;
}
F_126 ( V_9 , V_427 ) ;
F_210 ( V_9 , V_415 ) ;
return 0 ;
}
static int F_212 ( struct V_8 * V_9 , bool V_361 )
{
int V_428 , V_184 , V_26 = 0 ;
if ( ! V_361 )
F_201 ( V_9 , F_193 ( V_404 ) ,
& V_428 ) ;
else
F_202 ( V_9 , F_193 ( V_404 ) ,
& V_428 ) ;
for ( V_184 = 0 ; V_184 < V_428 ; V_184 ++ ) {
if ( ! V_361 )
V_26 = F_191 ( V_9 ,
F_192 ( V_429 ,
F_213 ( V_184 ) ) ,
0 ) ;
else
V_26 = F_214 ( V_9 ,
F_192 ( V_429 ,
F_213 ( V_184 ) ) ,
0 ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_61 ,
V_19 , V_361 , V_184 , V_26 ) ;
break;
}
}
return V_26 ;
}
static inline int F_215 ( struct V_8 * V_9 )
{
return F_212 ( V_9 , true ) ;
}
static int F_216 ( struct V_8 * V_9 )
{
int V_12 ;
int V_280 = V_430 ;
do {
F_217 ( V_9 , V_418 ) ;
V_12 = F_182 ( V_9 ) ;
if ( ! V_12 && ! F_19 ( V_9 ) ) {
F_6 ( V_9 -> V_18 , L_62 , V_19 ) ;
V_12 = - V_431 ;
goto V_48;
}
if ( V_12 && F_208 ( V_9 ) )
goto V_48;
} while ( V_12 && V_280 -- );
if ( V_12 )
goto V_48;
if ( V_9 -> V_34 & V_432 ) {
V_12 = F_215 ( V_9 ) ;
if ( V_12 )
goto V_48;
}
V_12 = F_217 ( V_9 , V_415 ) ;
if ( V_12 )
goto V_48;
V_12 = F_206 ( V_9 ) ;
V_48:
if ( V_12 )
F_6 ( V_9 -> V_18 , L_63 , V_12 ) ;
return V_12 ;
}
static int F_218 ( struct V_8 * V_9 )
{
int V_26 = 0 ;
int V_280 ;
F_63 ( V_9 , false ) ;
F_115 ( & V_9 -> V_141 . V_283 ) ;
for ( V_280 = V_433 ; V_280 > 0 ; V_280 -- ) {
V_26 = F_154 ( V_9 , V_239 ,
V_434 ) ;
if ( ! V_26 || V_26 == - V_29 )
break;
F_150 ( V_9 -> V_18 , L_64 , V_19 , V_26 ) ;
}
F_117 ( & V_9 -> V_141 . V_283 ) ;
F_78 ( V_9 ) ;
if ( V_26 )
F_6 ( V_9 -> V_18 , L_65 , V_19 , V_26 ) ;
return V_26 ;
}
static void F_219 ( struct V_435 * V_436 )
{
int V_12 = 0 ;
T_2 V_437 ;
struct V_8 * V_9 ;
V_9 = F_140 ( V_436 -> V_86 ) ;
V_437 = V_9 -> V_11 ;
V_12 = F_176 ( V_9 ,
F_136 ( V_436 -> V_221 ) ,
V_438 ,
& V_437 ,
sizeof( V_437 ) ) ;
if ( V_12 == - V_327 )
V_437 = 1 ;
else if ( ! V_437 )
V_437 = V_9 -> V_11 ;
else
V_437 = F_101 ( int , V_437 , V_9 -> V_11 ) ;
F_150 ( V_9 -> V_18 , L_66 ,
V_19 , V_437 ) ;
F_220 ( V_436 , V_437 ) ;
}
static int F_221 ( struct V_8 * V_9 ,
T_2 V_221 ,
T_2 * V_439 )
{
int V_12 ;
if ( ! V_439 )
V_12 = - V_118 ;
else if ( V_221 >= V_326 )
V_12 = - V_440 ;
else
V_12 = F_176 ( V_9 ,
V_221 ,
V_441 ,
V_439 ,
sizeof( * V_439 ) ) ;
return V_12 ;
}
static inline void F_222 ( struct V_8 * V_9 ,
struct V_435 * V_436 )
{
if ( V_9 -> V_442 . V_443 &&
! V_9 -> V_442 . V_444 ) {
T_2 V_439 ;
if ( ! F_221 ( V_9 , F_136 ( V_436 -> V_221 ) ,
& V_439 ) &&
( V_439 == V_445 ) )
V_9 -> V_442 . V_444 = true ;
}
}
static int F_223 ( struct V_435 * V_436 )
{
struct V_8 * V_9 ;
V_9 = F_140 ( V_436 -> V_86 ) ;
V_436 -> V_446 = 1 ;
V_436 -> V_447 = 1 ;
V_436 -> V_448 = 1 ;
F_219 ( V_436 ) ;
F_222 ( V_9 , V_436 ) ;
return 0 ;
}
static int F_224 ( struct V_435 * V_436 , int V_449 )
{
struct V_8 * V_9 = F_140 ( V_436 -> V_86 ) ;
if ( V_449 > V_9 -> V_11 )
V_449 = V_9 -> V_11 ;
return F_220 ( V_436 , V_449 ) ;
}
static int F_225 ( struct V_435 * V_436 )
{
struct V_450 * V_451 = V_436 -> V_450 ;
F_226 ( V_451 , V_452 - 1 ) ;
F_227 ( V_451 , V_453 ) ;
return 0 ;
}
static void F_228 ( struct V_435 * V_436 )
{
struct V_8 * V_9 ;
V_9 = F_140 ( V_436 -> V_86 ) ;
if ( F_136 ( V_436 -> V_221 ) == V_454 ) {
unsigned long V_82 ;
F_53 ( V_9 -> V_86 -> V_87 , V_82 ) ;
V_9 -> V_455 = NULL ;
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
}
}
static int F_229 ( struct V_8 * V_9 , T_1 V_276 , T_2 * V_260 )
{
struct V_45 * V_46 ;
struct V_456 * V_457 ;
unsigned long V_82 ;
int V_458 ;
int V_459 ;
F_53 ( V_9 -> V_86 -> V_87 , V_82 ) ;
F_31 ( V_276 , & V_9 -> V_105 ) ;
V_46 = V_9 -> V_337 ;
V_458 = F_22 ( & V_46 [ V_276 ] ) ;
if ( V_458 == V_460 ) {
V_457 = (struct V_456 * )
V_46 [ V_276 ] . V_461 ;
V_459 = F_36 ( V_457 -> V_42 . V_61 ) ;
V_459 = ( ( V_459 & V_462 ) >> 8 ) ;
if ( V_260 )
* V_260 = ( T_2 ) V_459 ;
} else {
F_6 ( V_9 -> V_18 , L_67 ,
V_19 , V_458 ) ;
}
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
return V_458 ;
}
static inline int
F_230 ( struct V_39 * V_40 , int V_463 )
{
int V_464 = 0 ;
switch ( V_463 ) {
case V_465 :
F_99 ( V_40 ) ;
case V_466 :
V_464 |= V_467 << 16 |
V_468 << 8 |
V_463 ;
break;
case V_469 :
case V_470 :
case V_471 :
F_99 ( V_40 ) ;
V_464 |= V_463 ;
break;
default:
V_464 |= V_252 << 16 ;
break;
}
return V_464 ;
}
static inline int
F_231 ( struct V_8 * V_9 , struct V_39 * V_40 )
{
int V_464 = 0 ;
int V_463 ;
int V_472 ;
V_472 = F_20 ( V_40 ) ;
switch ( V_472 ) {
case V_460 :
V_464 = F_35 ( V_40 -> V_59 ) ;
switch ( V_464 ) {
case V_473 :
V_464 = F_37 ( V_40 -> V_59 ) ;
V_463 = V_464 & V_474 ;
V_464 = F_230 ( V_40 , V_463 ) ;
if ( ! V_9 -> V_475 &&
F_39 ( V_40 -> V_59 ) )
F_68 ( & V_9 -> V_476 ) ;
break;
case V_263 :
V_464 = V_252 << 16 ;
F_6 ( V_9 -> V_18 ,
L_68 ) ;
break;
default:
V_464 = V_252 << 16 ;
F_6 ( V_9 -> V_18 ,
L_69 ,
V_464 ) ;
break;
}
break;
case V_477 :
V_464 |= V_478 << 16 ;
break;
case V_215 :
V_464 |= V_479 << 16 ;
break;
case V_480 :
case V_481 :
case V_482 :
case V_483 :
case V_484 :
case V_485 :
default:
V_464 |= V_252 << 16 ;
F_6 ( V_9 -> V_18 ,
L_70 , V_472 ) ;
break;
}
return V_464 ;
}
static void F_232 ( struct V_8 * V_9 , T_1 V_486 )
{
if ( ( V_486 & V_383 ) && V_9 -> V_106 ) {
V_9 -> V_106 -> V_167 |=
F_33 ( V_9 ) ;
V_9 -> V_106 -> V_168 =
F_34 ( V_9 ) ;
V_267 ( & V_9 -> V_106 -> V_172 ) ;
}
if ( ( V_486 & V_487 ) && V_9 -> V_107 )
V_267 ( V_9 -> V_107 ) ;
}
static void F_233 ( struct V_8 * V_9 ,
unsigned long V_488 )
{
struct V_39 * V_40 ;
struct V_181 * V_182 ;
int V_464 ;
int V_276 ;
F_234 (index, &completed_reqs, hba->nutrs) {
V_40 = & V_9 -> V_255 [ V_276 ] ;
V_182 = V_40 -> V_182 ;
if ( V_182 ) {
V_464 = F_231 ( V_9 , V_40 ) ;
F_235 ( V_182 ) ;
V_182 -> V_464 = V_464 ;
V_40 -> V_182 = NULL ;
F_27 ( V_276 , & V_9 -> V_104 ) ;
V_182 -> V_253 ( V_182 ) ;
F_76 ( V_9 ) ;
} else if ( V_40 -> V_211 == V_236 ||
V_40 -> V_211 == V_235 ) {
if ( V_9 -> V_141 . V_267 )
V_267 ( V_9 -> V_141 . V_267 ) ;
}
}
V_9 -> V_54 ^= V_488 ;
F_93 ( V_9 ) ;
F_158 ( & V_9 -> V_141 . V_271 ) ;
}
static void F_236 ( struct V_8 * V_9 )
{
unsigned long V_488 ;
T_1 V_489 ;
if ( F_144 ( V_9 ) )
F_40 ( V_9 ) ;
V_489 = F_12 ( V_9 , V_132 ) ;
V_488 = V_489 ^ V_9 -> V_54 ;
F_233 ( V_9 , V_488 ) ;
}
static int F_237 ( struct V_8 * V_9 , T_5 V_22 )
{
int V_26 = 0 ;
T_1 V_20 ;
if ( ! ( V_9 -> V_490 & V_22 ) )
goto V_48;
V_20 = V_9 -> V_490 & ~ V_22 ;
V_20 &= 0xFFFF ;
V_26 = F_164 ( V_9 , V_295 ,
V_491 , 0 , 0 , & V_20 ) ;
if ( ! V_26 )
V_9 -> V_490 &= ~ V_22 ;
V_48:
return V_26 ;
}
static int F_238 ( struct V_8 * V_9 , T_5 V_22 )
{
int V_26 = 0 ;
T_1 V_20 ;
if ( V_9 -> V_490 & V_22 )
goto V_48;
V_20 = V_9 -> V_490 | V_22 ;
V_20 &= 0xFFFF ;
V_26 = F_164 ( V_9 , V_295 ,
V_491 , 0 , 0 , & V_20 ) ;
if ( ! V_26 )
V_9 -> V_490 |= V_22 ;
V_48:
return V_26 ;
}
static int F_239 ( struct V_8 * V_9 )
{
int V_26 = 0 ;
if ( V_9 -> V_492 )
goto V_48;
V_26 = F_160 ( V_9 , V_284 ,
V_493 , NULL ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_71 ,
V_19 , V_26 ) ;
goto V_48;
}
V_9 -> V_492 = true ;
V_26 = F_237 ( V_9 , V_494 ) ;
if ( V_26 )
F_6 ( V_9 -> V_18 , L_72 ,
V_19 , V_26 ) ;
V_48:
return V_26 ;
}
static int F_240 ( struct V_8 * V_9 )
{
int V_26 = 0 ;
if ( ! V_9 -> V_492 )
goto V_48;
V_26 = F_238 ( V_9 , V_494 ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_73 ,
V_19 , V_26 ) ;
goto V_48;
}
V_26 = F_160 ( V_9 , V_285 ,
V_493 , NULL ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_74 ,
V_19 , V_26 ) ;
F_237 ( V_9 , V_494 ) ;
goto V_48;
}
V_9 -> V_492 = false ;
V_48:
return V_26 ;
}
static void F_241 ( struct V_8 * V_9 )
{
V_9 -> V_492 = false ;
V_9 -> V_490 |= V_494 ;
F_239 ( V_9 ) ;
}
static inline int F_242 ( struct V_8 * V_9 , T_1 * V_381 )
{
return F_164 ( V_9 , V_296 ,
V_495 , 0 , 0 , V_381 ) ;
}
static int F_243 ( struct V_8 * V_9 ,
enum V_496 V_381 )
{
int V_26 ;
T_1 V_497 = 0 ;
V_26 = F_242 ( V_9 , & V_497 ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_75 ,
V_19 , V_26 ) ;
goto V_48;
} else if ( V_497 > V_498 ) {
F_6 ( V_9 -> V_18 , L_76 ,
V_19 , V_497 ) ;
V_26 = - V_118 ;
goto V_48;
}
if ( V_497 >= V_381 )
V_26 = F_239 ( V_9 ) ;
else
V_26 = F_240 ( V_9 ) ;
V_48:
return V_26 ;
}
static int F_244 ( struct V_8 * V_9 )
{
return F_243 ( V_9 , V_9 -> V_499 ) ;
}
static inline int F_245 ( struct V_8 * V_9 , T_1 * V_381 )
{
return F_164 ( V_9 , V_296 ,
V_500 , 0 , 0 , V_381 ) ;
}
static void F_246 ( struct V_8 * V_9 )
{
int V_26 ;
T_1 V_497 = 0 ;
if ( V_9 -> V_501 )
goto V_502;
V_26 = F_242 ( V_9 , & V_497 ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_75 ,
V_19 , V_26 ) ;
goto V_48;
}
if ( V_497 < V_503 ) {
F_6 ( V_9 -> V_18 , L_77 ,
V_19 , V_497 ) ;
V_9 -> V_499 = V_497 ;
V_9 -> V_501 = true ;
}
V_502:
V_26 = F_239 ( V_9 ) ;
V_48:
if ( V_26 < 0 )
F_6 ( V_9 -> V_18 , L_78 ,
V_19 , V_26 ) ;
}
static void F_247 ( struct V_80 * V_81 )
{
struct V_8 * V_9 ;
int V_26 ;
T_1 V_381 = 0 ;
V_9 = F_51 ( V_81 , struct V_8 , V_476 ) ;
F_248 ( V_9 -> V_18 ) ;
V_26 = F_245 ( V_9 , & V_381 ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_79 ,
V_19 , V_26 ) ;
goto V_48;
}
V_381 &= V_9 -> V_490 ;
if ( V_381 & V_494 )
F_246 ( V_9 ) ;
V_48:
F_249 ( V_9 -> V_18 ) ;
return;
}
static void F_250 ( struct V_8 * V_9 )
{
F_236 ( V_9 ) ;
F_251 ( V_9 ) ;
}
static bool F_252 ( struct V_8 * V_9 )
{
unsigned long V_82 ;
bool V_504 = true ;
F_53 ( V_9 -> V_86 -> V_87 , V_82 ) ;
if ( V_9 -> V_505 & ( V_506 | V_507 ) )
goto V_48;
if ( ( V_9 -> V_505 & V_508 ) ||
( ( V_9 -> V_505 & V_509 ) &&
( V_9 -> V_510 & V_511 ) ) )
goto V_48;
if ( ( V_9 -> V_505 & V_509 ) &&
( V_9 -> V_510 & V_512 ) ) {
int V_26 ;
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
F_211 ( 50 ) ;
F_53 ( V_9 -> V_86 -> V_87 , V_82 ) ;
if ( ( V_9 -> V_505 & V_513 ) ||
( ( V_9 -> V_505 & V_509 ) &&
( V_9 -> V_510 & ~ V_512 ) ) )
goto V_48;
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
V_26 = F_218 ( V_9 ) ;
F_53 ( V_9 -> V_86 -> V_87 , V_82 ) ;
if ( V_26 )
goto V_48;
if ( V_9 -> V_510 == V_512 )
V_9 -> V_505 &= ~ V_509 ;
V_9 -> V_510 &= ~ V_512 ;
if ( ! V_9 -> V_510 ) {
V_504 = false ;
goto V_48;
}
}
V_48:
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
return V_504 ;
}
static void F_253 ( struct V_80 * V_81 )
{
struct V_8 * V_9 ;
unsigned long V_82 ;
T_1 V_514 = 0 ;
T_1 V_515 = 0 ;
int V_26 = 0 ;
int V_10 ;
bool V_516 = false ;
V_9 = F_51 ( V_81 , struct V_8 , V_517 ) ;
F_248 ( V_9 -> V_18 ) ;
F_63 ( V_9 , false ) ;
F_53 ( V_9 -> V_86 -> V_87 , V_82 ) ;
if ( V_9 -> V_102 == V_248 )
goto V_48;
V_9 -> V_102 = V_248 ;
F_195 ( V_9 ) ;
F_250 ( V_9 ) ;
if ( V_9 -> V_518 & V_519 ) {
bool V_12 ;
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
V_12 = F_252 ( V_9 ) ;
F_53 ( V_9 -> V_86 -> V_87 , V_82 ) ;
if ( ! V_12 )
goto V_520;
}
if ( ( V_9 -> V_505 & V_513 ) ||
( ( V_9 -> V_505 & V_509 ) &&
( V_9 -> V_510 & ( V_521 |
V_512 |
V_511 ) ) ) )
V_516 = true ;
if ( V_516 )
goto V_522;
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
F_234 (tag, &hba->outstanding_reqs, hba->nutrs) {
if ( F_146 ( V_9 , V_10 ) ) {
V_514 = true ;
goto V_523;
}
}
F_234 (tag, &hba->outstanding_tasks, hba->nutmrs) {
if ( F_254 ( V_9 , V_10 ) ) {
V_515 = true ;
goto V_523;
}
}
V_523:
F_53 ( V_9 -> V_86 -> V_87 , V_82 ) ;
F_250 ( V_9 ) ;
if ( V_514 || V_515 )
V_516 = true ;
V_522:
if ( V_516 ) {
unsigned long V_524 = ( 1UL << V_9 -> V_11 ) - 1 ;
if ( V_9 -> V_54 == V_524 )
F_233 ( V_9 ,
( 1UL << ( V_9 -> V_11 - 1 ) ) ) ;
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
V_26 = F_255 ( V_9 ) ;
F_53 ( V_9 -> V_86 -> V_87 , V_82 ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_80 ,
V_19 ) ;
V_9 -> V_102 = V_251 ;
}
F_256 ( V_9 -> V_86 , 0 ) ;
V_9 -> V_505 = 0 ;
V_9 -> V_510 = 0 ;
}
V_520:
if ( ! V_516 ) {
V_9 -> V_102 = V_103 ;
if ( V_9 -> V_505 || V_9 -> V_510 )
F_257 ( V_9 -> V_18 , L_81 ,
V_19 , V_9 -> V_505 , V_9 -> V_510 ) ;
}
F_197 ( V_9 ) ;
V_48:
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
F_62 ( V_9 -> V_86 ) ;
F_78 ( V_9 ) ;
F_249 ( V_9 -> V_18 ) ;
}
static void F_258 ( struct V_8 * V_9 )
{
T_1 V_21 ;
V_21 = F_12 ( V_9 , V_525 ) ;
if ( V_21 & V_526 )
V_9 -> V_527 |= V_521 ;
else if ( V_9 -> V_518 &
V_519 ) {
if ( V_21 & V_528 )
V_9 -> V_527 |=
V_512 ;
else if ( V_21 & V_529 )
V_9 -> V_527 |= V_511 ;
}
V_21 = F_12 ( V_9 , V_530 ) ;
if ( V_21 )
V_9 -> V_527 |= V_531 ;
V_21 = F_12 ( V_9 , V_532 ) ;
if ( V_21 )
V_9 -> V_527 |= V_533 ;
V_21 = F_12 ( V_9 , V_534 ) ;
if ( V_21 )
V_9 -> V_527 |= V_535 ;
F_150 ( V_9 -> V_18 , L_82 ,
V_19 , V_9 -> V_527 ) ;
}
static void F_259 ( struct V_8 * V_9 )
{
bool V_536 = false ;
if ( V_9 -> V_537 & V_513 )
V_536 = true ;
if ( V_9 -> V_537 & V_509 ) {
V_9 -> V_527 = 0 ;
F_258 ( V_9 ) ;
if ( V_9 -> V_527 )
V_536 = true ;
}
if ( V_536 ) {
V_9 -> V_505 |= V_9 -> V_537 ;
V_9 -> V_510 |= V_9 -> V_527 ;
if ( V_9 -> V_102 == V_103 ) {
F_67 ( V_9 -> V_86 ) ;
V_9 -> V_102 = V_251 ;
F_68 ( & V_9 -> V_517 ) ;
}
}
}
static void F_251 ( struct V_8 * V_9 )
{
T_1 V_538 ;
V_538 = F_12 ( V_9 , V_539 ) ;
V_9 -> V_540 = V_538 ^ V_9 -> V_105 ;
F_158 ( & V_9 -> V_541 ) ;
}
static void F_260 ( struct V_8 * V_9 , T_1 V_486 )
{
V_9 -> V_537 = V_542 & V_486 ;
if ( V_9 -> V_537 )
F_259 ( V_9 ) ;
if ( V_486 & V_427 )
F_232 ( V_9 , V_486 ) ;
if ( V_486 & V_543 )
F_251 ( V_9 ) ;
if ( V_486 & V_544 )
F_236 ( V_9 ) ;
}
static T_7 V_15 ( int V_14 , void * V_545 )
{
T_1 V_486 , V_546 ;
T_7 V_547 = V_548 ;
struct V_8 * V_9 = V_545 ;
F_261 ( V_9 -> V_86 -> V_87 ) ;
V_486 = F_12 ( V_9 , V_549 ) ;
V_546 =
V_486 & F_12 ( V_9 , V_194 ) ;
if ( V_486 )
F_29 ( V_9 , V_486 , V_549 ) ;
if ( V_546 ) {
F_260 ( V_9 , V_546 ) ;
V_547 = V_550 ;
}
F_262 ( V_9 -> V_86 -> V_87 ) ;
return V_547 ;
}
static int F_254 ( struct V_8 * V_9 , int V_10 )
{
int V_26 = 0 ;
T_1 V_22 = 1 << V_10 ;
unsigned long V_82 ;
if ( ! F_263 ( V_10 , & V_9 -> V_105 ) )
goto V_48;
F_53 ( V_9 -> V_86 -> V_87 , V_82 ) ;
F_29 ( V_9 , ~ ( 1 << V_10 ) , V_551 ) ;
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
V_26 = F_10 ( V_9 ,
V_539 ,
V_22 , 0 , 1000 , 1000 , true ) ;
V_48:
return V_26 ;
}
static int F_264 ( struct V_8 * V_9 , int V_552 , int V_553 ,
T_2 V_554 , T_2 * V_555 )
{
struct V_45 * V_46 ;
struct V_556 * V_557 ;
struct V_247 * V_86 ;
unsigned long V_82 ;
int V_47 ;
int V_26 ;
int V_131 ;
V_86 = V_9 -> V_86 ;
F_155 ( V_9 -> V_558 , F_23 ( V_9 , & V_47 ) ) ;
F_63 ( V_9 , false ) ;
F_53 ( V_86 -> V_87 , V_82 ) ;
V_46 = V_9 -> V_337 ;
V_46 += V_47 ;
V_46 -> V_42 . V_60 = F_122 ( V_214 ) ;
V_46 -> V_42 . V_43 =
F_122 ( V_215 ) ;
V_557 =
(struct V_556 * ) V_46 -> V_559 ;
V_131 = V_9 -> V_11 + V_47 ;
V_557 -> V_42 . V_60 =
F_130 ( V_560 , 0 ,
V_552 , V_131 ) ;
V_557 -> V_42 . V_61 =
F_130 ( 0 , V_554 , 0 , 0 ) ;
V_557 -> V_561 = F_131 ( V_552 ) ;
V_557 -> V_562 = F_131 ( V_553 ) ;
F_98 ( V_47 , & V_9 -> V_105 ) ;
F_157 () ;
F_29 ( V_9 , 1 << V_47 , V_539 ) ;
F_54 ( V_86 -> V_87 , V_82 ) ;
V_26 = F_265 ( V_9 -> V_541 ,
F_263 ( V_47 , & V_9 -> V_540 ) ,
F_11 ( V_563 ) ) ;
if ( ! V_26 ) {
F_6 ( V_9 -> V_18 , L_83 ,
V_19 , V_554 ) ;
if ( F_254 ( V_9 , V_47 ) )
F_266 ( V_9 -> V_18 , L_84 ,
V_19 , V_47 ) ;
V_26 = - V_29 ;
} else {
V_26 = F_229 ( V_9 , V_47 , V_555 ) ;
}
F_267 ( V_47 , & V_9 -> V_540 ) ;
F_26 ( V_9 , V_47 ) ;
F_158 ( & V_9 -> V_558 ) ;
F_78 ( V_9 ) ;
return V_26 ;
}
static int F_268 ( struct V_181 * V_182 )
{
struct V_247 * V_86 ;
struct V_8 * V_9 ;
unsigned int V_10 ;
T_1 V_52 ;
int V_26 ;
T_2 V_260 = 0xF ;
struct V_39 * V_40 ;
unsigned long V_82 ;
V_86 = V_182 -> V_111 -> V_86 ;
V_9 = F_140 ( V_86 ) ;
V_10 = V_182 -> V_154 -> V_10 ;
V_40 = & V_9 -> V_255 [ V_10 ] ;
V_26 = F_264 ( V_9 , V_40 -> V_221 , 0 , V_564 , & V_260 ) ;
if ( V_26 || V_260 != V_565 ) {
if ( ! V_26 )
V_26 = V_260 ;
goto V_48;
}
F_234 (pos, &hba->outstanding_reqs, hba->nutrs) {
if ( V_9 -> V_255 [ V_52 ] . V_221 == V_40 -> V_221 ) {
V_26 = F_146 ( V_9 , V_52 ) ;
if ( V_26 )
break;
}
}
F_53 ( V_86 -> V_87 , V_82 ) ;
F_236 ( V_9 ) ;
F_54 ( V_86 -> V_87 , V_82 ) ;
V_48:
if ( ! V_26 ) {
V_26 = V_566 ;
} else {
F_6 ( V_9 -> V_18 , L_85 , V_19 , V_26 ) ;
V_26 = V_567 ;
}
return V_26 ;
}
static int F_269 ( struct V_181 * V_182 )
{
struct V_247 * V_86 ;
struct V_8 * V_9 ;
unsigned long V_82 ;
unsigned int V_10 ;
int V_26 = 0 ;
int V_568 ;
T_2 V_260 = 0xF ;
struct V_39 * V_40 ;
T_1 V_21 ;
V_86 = V_182 -> V_111 -> V_86 ;
V_9 = F_140 ( V_86 ) ;
V_10 = V_182 -> V_154 -> V_10 ;
if ( ! F_3 ( V_9 , V_10 ) ) {
F_6 ( V_9 -> V_18 ,
L_9 ,
V_19 , V_10 , V_182 , V_182 -> V_154 ) ;
F_141 () ;
}
F_63 ( V_9 , false ) ;
V_21 = F_12 ( V_9 , V_132 ) ;
if ( ! ( F_263 ( V_10 , & V_9 -> V_54 ) ) ) {
F_6 ( V_9 -> V_18 ,
L_86 ,
V_19 , V_10 , V_9 -> V_54 , V_21 ) ;
goto V_48;
}
if ( ! ( V_21 & ( 1 << V_10 ) ) ) {
F_6 ( V_9 -> V_18 ,
L_87 ,
V_19 , V_10 ) ;
}
V_40 = & V_9 -> V_255 [ V_10 ] ;
for ( V_568 = 100 ; V_568 ; V_568 -- ) {
V_26 = F_264 ( V_9 , V_40 -> V_221 , V_40 -> V_131 ,
V_569 , & V_260 ) ;
if ( ! V_26 && V_260 == V_570 ) {
break;
} else if ( ! V_26 && V_260 == V_565 ) {
V_21 = F_12 ( V_9 , V_132 ) ;
if ( V_21 & ( 1 << V_10 ) ) {
F_13 ( 100 , 200 ) ;
continue;
}
goto V_48;
} else {
if ( ! V_26 )
V_26 = V_260 ;
goto V_48;
}
}
if ( ! V_568 ) {
V_26 = - V_571 ;
goto V_48;
}
V_26 = F_264 ( V_9 , V_40 -> V_221 , V_40 -> V_131 ,
V_572 , & V_260 ) ;
if ( V_26 || V_260 != V_565 ) {
if ( ! V_26 )
V_26 = V_260 ;
goto V_48;
}
V_26 = F_146 ( V_9 , V_10 ) ;
if ( V_26 )
goto V_48;
F_235 ( V_182 ) ;
F_53 ( V_86 -> V_87 , V_82 ) ;
F_30 ( V_9 , V_10 ) ;
V_9 -> V_255 [ V_10 ] . V_182 = NULL ;
F_54 ( V_86 -> V_87 , V_82 ) ;
F_27 ( V_10 , & V_9 -> V_104 ) ;
F_158 ( & V_9 -> V_141 . V_271 ) ;
V_48:
if ( ! V_26 ) {
V_26 = V_566 ;
} else {
F_6 ( V_9 -> V_18 , L_85 , V_19 , V_26 ) ;
V_26 = V_567 ;
}
F_78 ( V_9 ) ;
return V_26 ;
}
static int F_196 ( struct V_8 * V_9 )
{
int V_26 ;
unsigned long V_82 ;
F_53 ( V_9 -> V_86 -> V_87 , V_82 ) ;
F_207 ( V_9 , false ) ;
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
V_26 = F_208 ( V_9 ) ;
if ( V_26 )
goto V_48;
V_26 = F_270 ( V_9 ) ;
if ( ! V_26 && ( V_9 -> V_102 != V_103 ) )
V_26 = - V_175 ;
V_48:
if ( V_26 )
F_6 ( V_9 -> V_18 , L_88 , V_19 , V_26 ) ;
return V_26 ;
}
static int F_255 ( struct V_8 * V_9 )
{
int V_26 = 0 ;
unsigned long V_82 ;
int V_280 = V_573 ;
do {
V_26 = F_196 ( V_9 ) ;
} while ( V_26 && -- V_280 );
F_53 ( V_9 -> V_86 -> V_87 , V_82 ) ;
F_236 ( V_9 ) ;
F_251 ( V_9 ) ;
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
return V_26 ;
}
static int F_271 ( struct V_181 * V_182 )
{
int V_26 ;
unsigned long V_82 ;
struct V_8 * V_9 ;
V_9 = F_140 ( V_182 -> V_111 -> V_86 ) ;
F_63 ( V_9 , false ) ;
do {
F_53 ( V_9 -> V_86 -> V_87 , V_82 ) ;
if ( ! ( F_272 ( & V_9 -> V_517 ) ||
V_9 -> V_102 == V_248 ) )
break;
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
F_150 ( V_9 -> V_18 , L_89 , V_19 ) ;
F_69 ( & V_9 -> V_517 ) ;
} while ( 1 );
V_9 -> V_102 = V_248 ;
F_195 ( V_9 ) ;
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
V_26 = F_255 ( V_9 ) ;
F_53 ( V_9 -> V_86 -> V_87 , V_82 ) ;
if ( ! V_26 ) {
V_26 = V_566 ;
V_9 -> V_102 = V_103 ;
} else {
V_26 = V_567 ;
V_9 -> V_102 = V_251 ;
}
F_197 ( V_9 ) ;
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
F_78 ( V_9 ) ;
return V_26 ;
}
static T_1 F_273 ( int V_574 , T_1 V_575 , char * V_576 )
{
int V_184 ;
int V_577 ;
T_5 V_578 ;
T_5 V_579 ;
for ( V_184 = V_575 ; V_184 >= 0 ; V_184 -- ) {
V_578 = F_100 ( * ( ( T_5 * ) ( V_576 + 2 * V_184 ) ) ) ;
V_579 = ( V_578 & V_580 ) >>
V_581 ;
V_577 = V_578 & V_582 ;
switch ( V_579 ) {
case V_583 :
V_577 = V_577 / 1000 ;
break;
case V_584 :
V_577 = V_577 * 1000 ;
break;
case V_585 :
V_577 = V_577 * 1000 * 1000 ;
break;
case V_586 :
default:
break;
}
if ( V_574 >= V_577 )
break;
}
if ( V_184 < 0 ) {
V_184 = 0 ;
F_274 ( L_90 , V_19 , V_184 ) ;
}
return ( T_1 ) V_184 ;
}
static T_1 F_275 ( struct V_8 * V_9 ,
T_2 * V_298 , int V_133 )
{
T_1 V_587 = 0 ;
if ( ! V_9 -> V_588 . V_589 || ! V_9 -> V_588 . V_590 ||
! V_9 -> V_588 . V_591 ) {
F_6 ( V_9 -> V_18 ,
L_91 ,
V_19 , V_587 ) ;
goto V_48;
}
if ( V_9 -> V_588 . V_589 )
V_587 = F_273 (
V_9 -> V_588 . V_589 -> V_592 ,
V_593 - 1 ,
& V_298 [ V_594 ] ) ;
if ( V_9 -> V_588 . V_590 )
V_587 = F_273 (
V_9 -> V_588 . V_590 -> V_592 ,
V_587 ,
& V_298 [ V_595 ] ) ;
if ( V_9 -> V_588 . V_591 )
V_587 = F_273 (
V_9 -> V_588 . V_591 -> V_592 ,
V_587 ,
& V_298 [ V_596 ] ) ;
V_48:
return V_587 ;
}
static void F_276 ( struct V_8 * V_9 )
{
int V_12 ;
int V_306 = V_597 ;
T_2 V_298 [ V_597 ] ;
V_12 = F_172 ( V_9 , V_298 , V_306 ) ;
if ( V_12 ) {
F_6 ( V_9 -> V_18 ,
L_92 ,
V_19 , V_306 , V_12 ) ;
return;
}
V_9 -> V_598 . V_587 =
F_275 ( V_9 ,
V_298 , V_306 ) ;
F_150 ( V_9 -> V_18 , L_93 ,
V_19 , V_9 -> V_598 . V_587 ) ;
V_12 = F_164 ( V_9 , V_295 ,
V_599 , 0 , 0 ,
& V_9 -> V_598 . V_587 ) ;
if ( V_12 )
F_6 ( V_9 -> V_18 ,
L_94 ,
V_19 , V_9 -> V_598 . V_587 , V_12 ) ;
}
static int F_277 ( struct V_8 * V_9 )
{
int V_12 = 0 ;
struct V_435 * V_600 ;
struct V_435 * V_601 ;
V_9 -> V_455 = F_278 ( V_9 -> V_86 , 0 , 0 ,
F_138 ( V_454 ) , NULL ) ;
if ( F_279 ( V_9 -> V_455 ) ) {
V_12 = F_280 ( V_9 -> V_455 ) ;
V_9 -> V_455 = NULL ;
goto V_48;
}
F_281 ( V_9 -> V_455 ) ;
V_601 = F_278 ( V_9 -> V_86 , 0 , 0 ,
F_138 ( V_602 ) , NULL ) ;
if ( F_279 ( V_601 ) ) {
V_12 = F_280 ( V_601 ) ;
goto V_603;
}
F_281 ( V_601 ) ;
V_600 = F_278 ( V_9 -> V_86 , 0 , 0 ,
F_138 ( V_325 ) , NULL ) ;
if ( F_279 ( V_600 ) ) {
V_12 = F_280 ( V_600 ) ;
goto V_604;
}
F_281 ( V_600 ) ;
goto V_48;
V_604:
F_282 ( V_601 ) ;
V_603:
F_282 ( V_9 -> V_455 ) ;
V_48:
return V_12 ;
}
static int F_283 ( struct V_8 * V_9 ,
struct V_605 * V_606 )
{
int V_26 ;
T_2 V_607 ;
T_2 V_608 [ V_609 + 1 ] = { 0 } ;
T_2 V_298 [ V_610 ] ;
V_26 = F_173 ( V_9 , V_298 ,
V_610 ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_95 ,
V_19 , V_26 ) ;
goto V_48;
}
V_606 -> V_611 = V_298 [ V_612 ] << 8 |
V_298 [ V_612 + 1 ] ;
V_607 = V_298 [ V_613 ] ;
V_26 = F_174 ( V_9 , V_607 , V_608 ,
V_609 , V_614 ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_96 ,
V_19 , V_26 ) ;
goto V_48;
}
V_608 [ V_609 ] = '\0' ;
F_284 ( V_606 -> V_615 , ( V_608 + V_321 ) ,
F_101 ( T_2 , V_608 [ V_312 ] ,
V_616 ) ) ;
V_606 -> V_615 [ V_616 ] = '\0' ;
V_48:
return V_26 ;
}
void F_285 ( struct V_8 * V_9 )
{
int V_26 ;
struct V_617 * V_618 ;
struct V_605 V_606 ;
V_606 . V_611 = 0 ;
V_26 = F_283 ( V_9 , & V_606 ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_97 ,
V_19 , V_26 ) ;
return;
}
for ( V_618 = V_619 ; V_618 -> V_620 ; V_618 ++ ) {
if ( ( ( V_618 -> V_621 . V_611 == V_606 . V_611 ) ||
( V_618 -> V_621 . V_611 == V_622 ) ) &&
( F_286 ( V_618 -> V_621 . V_615 , V_606 . V_615 ) ||
! strcmp ( V_618 -> V_621 . V_615 , V_623 ) ) )
V_9 -> V_518 |= V_618 -> V_620 ;
}
}
static int F_287 ( struct V_8 * V_9 )
{
int V_12 = 0 ;
T_1 V_624 = 0 , V_625 ;
V_12 = F_202 ( V_9 ,
F_192 (
V_626 ,
F_288 ( 0 ) ) ,
& V_624 ) ;
if ( V_12 )
goto V_48;
V_625 =
( ( V_624 * V_627 )
/ V_628 ) ;
V_12 = F_191 ( V_9 , F_193 ( V_629 ) ,
V_625 ) ;
V_48:
return V_12 ;
}
static int F_289 ( struct V_8 * V_9 )
{
int V_12 = 0 ;
T_1 V_630 = 0 , V_631 = 0 ;
T_1 V_632 , V_633 ;
V_12 = F_201 ( V_9 ,
F_192 ( V_634 ,
F_213 ( 0 ) ) ,
& V_630 ) ;
if ( V_12 )
goto V_48;
V_12 = F_202 ( V_9 ,
F_192 ( V_635 ,
F_288 ( 0 ) ) ,
& V_631 ) ;
if ( V_12 )
goto V_48;
V_632 = F_290 ( V_630 ,
V_631 ) ;
V_633 = ( ( V_632 * V_636 )
/ V_637 ) ;
V_12 = F_191 ( V_9 , F_193 ( V_638 ) ,
V_633 ) ;
V_48:
return V_12 ;
}
static void F_291 ( struct V_8 * V_9 )
{
if ( F_49 ( V_9 ) ) {
F_287 ( V_9 ) ;
F_289 ( V_9 ) ;
}
if ( V_9 -> V_518 & V_639 )
F_191 ( V_9 , F_193 ( V_629 ) , 10 ) ;
}
static int F_270 ( struct V_8 * V_9 )
{
int V_12 ;
V_12 = F_216 ( V_9 ) ;
if ( V_12 )
goto V_48;
F_199 ( V_9 ) ;
V_9 -> V_499 = V_503 ;
V_9 -> V_501 = false ;
F_59 ( V_9 ) ;
V_12 = F_218 ( V_9 ) ;
if ( V_12 )
goto V_48;
V_12 = F_205 ( V_9 ) ;
if ( V_12 )
goto V_48;
F_285 ( V_9 ) ;
F_291 ( V_9 ) ;
V_12 = F_292 ( V_9 ,
( V_9 -> V_518 & V_640 ) ? true : false ) ;
if ( V_12 )
goto V_48;
F_293 ( V_9 ) ;
F_241 ( V_9 ) ;
V_9 -> V_641 = true ;
if ( F_200 ( V_9 ) ) {
F_6 ( V_9 -> V_18 ,
L_98 ,
V_19 ) ;
} else {
V_12 = F_204 ( V_9 , & V_9 -> V_399 . V_400 ) ;
if ( V_12 )
F_6 ( V_9 -> V_18 , L_99 ,
V_19 , V_12 ) ;
}
V_9 -> V_102 = V_103 ;
if ( ! F_65 ( V_9 ) && ! V_9 -> V_475 ) {
bool V_642 ;
memset ( & V_9 -> V_442 , 0 , sizeof( V_9 -> V_442 ) ) ;
if ( ! F_160 ( V_9 , V_288 ,
V_643 , & V_642 ) )
V_9 -> V_442 . V_443 = V_642 ;
if ( ! V_9 -> V_644 )
F_276 ( V_9 ) ;
if ( F_277 ( V_9 ) )
goto V_48;
F_294 ( V_9 -> V_86 ) ;
F_249 ( V_9 -> V_18 ) ;
}
if ( ! V_9 -> V_644 )
V_9 -> V_644 = true ;
if ( F_60 ( V_9 ) )
F_61 ( V_9 -> V_92 ) ;
V_48:
if ( V_12 && ! F_65 ( V_9 ) && ! V_9 -> V_475 ) {
F_249 ( V_9 -> V_18 ) ;
F_295 ( V_9 ) ;
}
return V_12 ;
}
static void F_296 ( void * V_578 , T_8 V_645 )
{
struct V_8 * V_9 = (struct V_8 * ) V_578 ;
F_270 ( V_9 ) ;
}
static enum V_646 F_297 ( struct V_181 * V_647 )
{
unsigned long V_82 ;
struct V_247 * V_86 ;
struct V_8 * V_9 ;
int V_276 ;
bool V_648 = false ;
if ( ! V_647 || ! V_647 -> V_111 || ! V_647 -> V_111 -> V_86 )
return V_649 ;
V_86 = V_647 -> V_111 -> V_86 ;
V_9 = F_140 ( V_86 ) ;
if ( ! V_9 )
return V_649 ;
F_53 ( V_86 -> V_87 , V_82 ) ;
F_234 (index, &hba->outstanding_reqs, hba->nutrs) {
if ( V_9 -> V_255 [ V_276 ] . V_182 == V_647 ) {
V_648 = true ;
break;
}
}
F_54 ( V_86 -> V_87 , V_82 ) ;
return V_648 ? V_649 : V_650 ;
}
static int F_298 ( struct V_111 * V_18 , struct V_651 * V_652 ,
int V_653 )
{
int V_12 ;
if ( ! V_652 )
return 0 ;
V_12 = F_299 ( V_652 -> V_21 , V_653 ) ;
if ( V_12 < 0 ) {
F_6 ( V_18 , L_100 ,
V_19 , V_652 -> V_122 , V_653 , V_12 ) ;
}
return V_12 ;
}
static inline int F_300 ( struct V_8 * V_9 ,
struct V_651 * V_652 )
{
if ( ! V_652 )
return 0 ;
else if ( V_652 -> V_654 )
return 0 ;
else
return F_298 ( V_9 -> V_18 , V_652 ,
V_655 ) ;
}
static inline int F_301 ( struct V_8 * V_9 ,
struct V_651 * V_652 )
{
if ( ! V_652 )
return 0 ;
else if ( V_652 -> V_654 )
return 0 ;
else
return F_298 ( V_9 -> V_18 , V_652 , V_652 -> V_592 ) ;
}
static int F_302 ( struct V_111 * V_18 ,
struct V_651 * V_652 , bool V_656 )
{
int V_12 = 0 ;
struct V_657 * V_21 = V_652 -> V_21 ;
const char * V_122 = V_652 -> V_122 ;
int V_658 , V_659 ;
F_162 ( ! V_652 ) ;
if ( F_303 ( V_21 ) > 0 ) {
V_658 = V_656 ? V_652 -> V_658 : 0 ;
V_12 = F_304 ( V_21 , V_658 , V_652 -> V_660 ) ;
if ( V_12 ) {
F_6 ( V_18 , L_101 ,
V_19 , V_122 , V_12 ) ;
goto V_48;
}
V_659 = V_656 ? V_652 -> V_592 : 0 ;
V_12 = F_298 ( V_18 , V_652 , V_659 ) ;
if ( V_12 )
goto V_48;
}
V_48:
return V_12 ;
}
static int F_305 ( struct V_111 * V_18 , struct V_651 * V_652 )
{
int V_12 = 0 ;
if ( ! V_652 )
goto V_48;
else if ( V_652 -> V_661 || V_652 -> V_654 )
goto V_48;
V_12 = F_302 ( V_18 , V_652 , true ) ;
if ( ! V_12 )
V_12 = F_306 ( V_652 -> V_21 ) ;
if ( ! V_12 )
V_652 -> V_661 = true ;
else
F_6 ( V_18 , L_102 ,
V_19 , V_652 -> V_122 , V_12 ) ;
V_48:
return V_12 ;
}
static int F_307 ( struct V_111 * V_18 , struct V_651 * V_652 )
{
int V_12 = 0 ;
if ( ! V_652 )
goto V_48;
else if ( ! V_652 -> V_661 || V_652 -> V_654 )
goto V_48;
V_12 = F_308 ( V_652 -> V_21 ) ;
if ( ! V_12 ) {
F_302 ( V_18 , V_652 , false ) ;
V_652 -> V_661 = false ;
} else {
F_6 ( V_18 , L_103 ,
V_19 , V_652 -> V_122 , V_12 ) ;
}
V_48:
return V_12 ;
}
static int F_309 ( struct V_8 * V_9 , bool V_656 )
{
int V_12 = 0 ;
struct V_111 * V_18 = V_9 -> V_18 ;
struct V_662 * V_400 = & V_9 -> V_588 ;
if ( ! V_400 )
goto V_48;
V_12 = F_310 ( V_18 , V_400 -> V_589 , V_656 ) ;
if ( V_12 )
goto V_48;
V_12 = F_310 ( V_18 , V_400 -> V_590 , V_656 ) ;
if ( V_12 )
goto V_48;
V_12 = F_310 ( V_18 , V_400 -> V_591 , V_656 ) ;
if ( V_12 )
goto V_48;
V_48:
if ( V_12 ) {
F_310 ( V_18 , V_400 -> V_591 , false ) ;
F_310 ( V_18 , V_400 -> V_590 , false ) ;
F_310 ( V_18 , V_400 -> V_589 , false ) ;
}
return V_12 ;
}
static int F_311 ( struct V_8 * V_9 , bool V_656 )
{
struct V_662 * V_400 = & V_9 -> V_588 ;
if ( V_400 )
return F_310 ( V_9 -> V_18 , V_400 -> V_663 , V_656 ) ;
return 0 ;
}
static int F_312 ( struct V_111 * V_18 , struct V_651 * V_652 )
{
int V_12 = 0 ;
if ( ! V_652 )
goto V_48;
V_652 -> V_21 = F_313 ( V_18 , V_652 -> V_122 ) ;
if ( F_279 ( V_652 -> V_21 ) ) {
V_12 = F_280 ( V_652 -> V_21 ) ;
F_6 ( V_18 , L_104 ,
V_19 , V_652 -> V_122 , V_12 ) ;
}
V_48:
return V_12 ;
}
static int F_314 ( struct V_8 * V_9 )
{
int V_12 = 0 ;
struct V_111 * V_18 = V_9 -> V_18 ;
struct V_662 * V_400 = & V_9 -> V_588 ;
if ( ! V_400 )
goto V_48;
V_12 = F_312 ( V_18 , V_400 -> V_589 ) ;
if ( V_12 )
goto V_48;
V_12 = F_312 ( V_18 , V_400 -> V_590 ) ;
if ( V_12 )
goto V_48;
V_12 = F_312 ( V_18 , V_400 -> V_591 ) ;
V_48:
return V_12 ;
}
static int F_315 ( struct V_8 * V_9 )
{
struct V_662 * V_400 = & V_9 -> V_588 ;
if ( V_400 )
return F_312 ( V_9 -> V_18 , V_400 -> V_663 ) ;
return 0 ;
}
static int F_292 ( struct V_8 * V_9 , bool V_654 )
{
int V_12 = 0 ;
struct V_662 * V_400 = & V_9 -> V_588 ;
if ( ! V_400 )
goto V_48;
else if ( ! V_400 -> V_590 )
goto V_48;
if ( V_654 ) {
V_12 = F_310 ( V_9 -> V_18 , V_400 -> V_590 , false ) ;
if ( ! V_12 )
V_400 -> V_590 -> V_654 = true ;
} else {
V_400 -> V_590 -> V_654 = false ;
}
V_48:
return V_12 ;
}
static int F_75 ( struct V_8 * V_9 , bool V_656 ,
bool V_664 )
{
int V_12 = 0 ;
struct V_665 * V_666 ;
struct V_667 * V_668 = & V_9 -> V_669 ;
unsigned long V_82 ;
if ( ! V_668 || F_316 ( V_668 ) )
goto V_48;
F_317 (clki, head, list) {
if ( ! F_318 ( V_666 -> V_670 ) ) {
if ( V_664 && ! strcmp ( V_666 -> V_122 , L_105 ) )
continue;
if ( V_656 && ! V_666 -> V_661 ) {
V_12 = F_319 ( V_666 -> V_670 ) ;
if ( V_12 ) {
F_6 ( V_9 -> V_18 , L_106 ,
V_19 , V_666 -> V_122 , V_12 ) ;
goto V_48;
}
} else if ( ! V_656 && V_666 -> V_661 ) {
F_320 ( V_666 -> V_670 ) ;
}
V_666 -> V_661 = V_656 ;
F_150 ( V_9 -> V_18 , L_107 , V_19 ,
V_666 -> V_122 , V_656 ? L_108 : L_109 ) ;
}
}
V_12 = F_321 ( V_9 , V_656 ) ;
V_48:
if ( V_12 ) {
F_317 (clki, head, list) {
if ( ! F_318 ( V_666 -> V_670 ) && V_666 -> V_661 )
F_320 ( V_666 -> V_670 ) ;
}
} else if ( V_656 ) {
F_53 ( V_9 -> V_86 -> V_87 , V_82 ) ;
V_9 -> V_83 . V_88 = V_89 ;
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
}
return V_12 ;
}
static int F_55 ( struct V_8 * V_9 , bool V_656 )
{
return F_75 ( V_9 , V_656 , false ) ;
}
static int F_322 ( struct V_8 * V_9 )
{
int V_12 = 0 ;
struct V_665 * V_666 ;
struct V_111 * V_18 = V_9 -> V_18 ;
struct V_667 * V_668 = & V_9 -> V_669 ;
if ( ! V_668 || F_316 ( V_668 ) )
goto V_48;
F_317 (clki, head, list) {
if ( ! V_666 -> V_122 )
continue;
V_666 -> V_670 = F_323 ( V_18 , V_666 -> V_122 ) ;
if ( F_279 ( V_666 -> V_670 ) ) {
V_12 = F_280 ( V_666 -> V_670 ) ;
F_6 ( V_18 , L_110 ,
V_19 , V_666 -> V_122 , V_12 ) ;
goto V_48;
}
if ( V_666 -> V_671 ) {
V_12 = F_324 ( V_666 -> V_670 , V_666 -> V_671 ) ;
if ( V_12 ) {
F_6 ( V_9 -> V_18 , L_111 ,
V_19 , V_666 -> V_122 ,
V_666 -> V_671 , V_12 ) ;
goto V_48;
}
V_666 -> V_672 = V_666 -> V_671 ;
}
F_150 ( V_18 , L_112 , V_19 ,
V_666 -> V_122 , F_325 ( V_666 -> V_670 ) ) ;
}
V_48:
return V_12 ;
}
static int F_326 ( struct V_8 * V_9 )
{
int V_26 = 0 ;
if ( ! V_9 -> V_673 )
goto V_48;
V_26 = F_327 ( V_9 ) ;
if ( V_26 )
goto V_48;
V_26 = F_328 ( V_9 , true ) ;
if ( V_26 )
goto V_674;
goto V_48;
V_674:
F_329 ( V_9 ) ;
V_48:
if ( V_26 )
F_6 ( V_9 -> V_18 , L_113 ,
V_19 , F_330 ( V_9 ) , V_26 ) ;
return V_26 ;
}
static void F_331 ( struct V_8 * V_9 )
{
if ( ! V_9 -> V_673 )
return;
F_321 ( V_9 , false ) ;
F_328 ( V_9 , false ) ;
F_329 ( V_9 ) ;
}
static int F_332 ( struct V_8 * V_9 )
{
int V_26 ;
V_26 = F_315 ( V_9 ) ;
if ( V_26 )
goto V_48;
V_26 = F_311 ( V_9 , true ) ;
if ( V_26 )
goto V_48;
V_26 = F_322 ( V_9 ) ;
if ( V_26 )
goto V_675;
V_26 = F_55 ( V_9 , true ) ;
if ( V_26 )
goto V_675;
V_26 = F_314 ( V_9 ) ;
if ( V_26 )
goto V_676;
V_26 = F_309 ( V_9 , true ) ;
if ( V_26 )
goto V_676;
V_26 = F_326 ( V_9 ) ;
if ( V_26 )
goto V_677;
V_9 -> V_678 = true ;
goto V_48;
V_677:
F_309 ( V_9 , false ) ;
V_676:
F_55 ( V_9 , false ) ;
V_675:
F_311 ( V_9 , false ) ;
V_48:
return V_26 ;
}
static void F_295 ( struct V_8 * V_9 )
{
if ( V_9 -> V_678 ) {
F_331 ( V_9 ) ;
F_309 ( V_9 , false ) ;
F_55 ( V_9 , false ) ;
F_311 ( V_9 , false ) ;
V_9 -> V_678 = false ;
}
}
static int
F_333 ( struct V_8 * V_9 , struct V_435 * V_679 )
{
unsigned char V_182 [ 6 ] = { V_680 ,
0 ,
0 ,
0 ,
V_138 ,
0 } ;
char * V_681 ;
int V_12 ;
V_681 = F_334 ( V_138 , V_310 ) ;
if ( ! V_681 ) {
V_12 = - V_311 ;
goto V_48;
}
V_12 = F_335 ( V_679 , V_182 , V_203 , V_681 ,
V_138 , NULL ,
F_11 ( 1000 ) , 3 , NULL , V_682 ) ;
if ( V_12 )
F_274 ( L_85 , V_19 , V_12 ) ;
F_170 ( V_681 ) ;
V_48:
return V_12 ;
}
static int F_336 ( struct V_8 * V_9 ,
enum V_1 V_407 )
{
unsigned char V_182 [ 6 ] = { V_683 } ;
struct V_684 V_685 ;
struct V_435 * V_679 ;
unsigned long V_82 ;
int V_12 ;
F_53 ( V_9 -> V_86 -> V_87 , V_82 ) ;
V_679 = V_9 -> V_455 ;
if ( V_679 ) {
V_12 = F_337 ( V_679 ) ;
if ( ! V_12 && ! F_338 ( V_679 ) ) {
V_12 = - V_686 ;
F_281 ( V_679 ) ;
}
} else {
V_12 = - V_686 ;
}
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
if ( V_12 )
return V_12 ;
V_9 -> V_86 -> V_687 = 1 ;
if ( V_9 -> V_641 ) {
V_12 = F_333 ( V_9 , V_679 ) ;
if ( V_12 )
goto V_48;
V_9 -> V_641 = false ;
}
V_182 [ 4 ] = V_407 << 4 ;
V_12 = F_335 ( V_679 , V_182 , V_237 , NULL , 0 , & V_685 ,
V_688 , 0 , NULL , V_682 ) ;
if ( V_12 ) {
F_339 ( V_689 , V_679 ,
L_114 ,
V_407 , V_12 ) ;
if ( F_340 ( V_12 ) & V_690 )
F_341 ( V_679 , NULL , & V_685 ) ;
}
if ( ! V_12 )
V_9 -> V_691 = V_407 ;
V_48:
F_281 ( V_679 ) ;
V_9 -> V_86 -> V_687 = 0 ;
return V_12 ;
}
static int F_342 ( struct V_8 * V_9 ,
enum V_6 V_692 ,
int V_693 )
{
int V_12 = 0 ;
if ( V_692 == V_9 -> V_6 )
return 0 ;
if ( V_692 == V_694 ) {
V_12 = F_71 ( V_9 ) ;
if ( ! V_12 )
F_72 ( V_9 ) ;
else
goto V_48;
}
else if ( ( V_692 == V_695 ) &&
( ! V_693 || ( V_693 &&
! V_9 -> V_492 ) ) ) {
V_12 = F_71 ( V_9 ) ;
if ( V_12 )
goto V_48;
F_207 ( V_9 , true ) ;
F_209 ( V_9 ) ;
}
V_48:
return V_12 ;
}
static void F_343 ( struct V_8 * V_9 )
{
if ( ! F_74 ( V_9 ) &&
V_9 -> V_518 & V_696 )
F_13 ( 2000 , 2100 ) ;
if ( F_344 ( V_9 ) && F_345 ( V_9 ) &&
! V_9 -> V_442 . V_444 ) {
F_309 ( V_9 , false ) ;
} else if ( ! F_346 ( V_9 ) ) {
F_310 ( V_9 -> V_18 , V_9 -> V_588 . V_589 , false ) ;
if ( ! F_74 ( V_9 ) ) {
F_300 ( V_9 , V_9 -> V_588 . V_590 ) ;
F_300 ( V_9 , V_9 -> V_588 . V_591 ) ;
}
}
}
static int F_347 ( struct V_8 * V_9 )
{
int V_12 = 0 ;
if ( F_344 ( V_9 ) && F_345 ( V_9 ) &&
! V_9 -> V_442 . V_444 ) {
V_12 = F_309 ( V_9 , true ) ;
} else if ( ! F_346 ( V_9 ) ) {
V_12 = F_310 ( V_9 -> V_18 , V_9 -> V_588 . V_589 , true ) ;
if ( ! V_12 && ! F_74 ( V_9 ) ) {
V_12 = F_301 ( V_9 , V_9 -> V_588 . V_590 ) ;
if ( V_12 )
goto V_697;
V_12 = F_301 ( V_9 , V_9 -> V_588 . V_591 ) ;
if ( V_12 )
goto V_698;
}
}
goto V_48;
V_698:
F_300 ( V_9 , V_9 -> V_588 . V_590 ) ;
V_697:
F_310 ( V_9 -> V_18 , V_9 -> V_588 . V_589 , false ) ;
V_48:
return V_12 ;
}
static void F_348 ( struct V_8 * V_9 )
{
if ( F_345 ( V_9 ) )
F_311 ( V_9 , false ) ;
}
static void F_349 ( struct V_8 * V_9 )
{
if ( F_345 ( V_9 ) )
F_311 ( V_9 , true ) ;
}
static int F_350 ( struct V_8 * V_9 , enum V_699 V_700 )
{
int V_12 = 0 ;
enum V_2 V_701 ;
enum V_1 V_702 ;
enum V_6 V_692 ;
V_9 -> V_475 = 1 ;
if ( ! F_351 ( V_700 ) ) {
V_701 = F_352 ( V_700 ) ?
V_9 -> V_703 : V_9 -> V_704 ;
V_702 = F_1 ( V_701 ) ;
V_692 = F_2 ( V_701 ) ;
} else {
V_702 = V_705 ;
V_692 = V_695 ;
}
F_63 ( V_9 , false ) ;
V_9 -> V_83 . V_91 = true ;
if ( V_702 == V_706 &&
V_692 == V_707 ) {
goto V_708;
}
if ( ( V_702 == V_9 -> V_691 ) &&
( V_692 == V_9 -> V_6 ) )
goto V_48;
if ( ! F_346 ( V_9 ) || ! F_74 ( V_9 ) ) {
V_12 = - V_118 ;
goto V_48;
}
if ( F_352 ( V_700 ) ) {
if ( F_353 ( V_9 ) ) {
V_12 = F_244 ( V_9 ) ;
if ( V_12 )
goto V_709;
} else {
F_240 ( V_9 ) ;
}
}
if ( ( V_702 != V_9 -> V_691 ) &&
( ( F_352 ( V_700 ) && ! V_9 -> V_492 ) ||
! F_352 ( V_700 ) ) ) {
F_240 ( V_9 ) ;
V_12 = F_336 ( V_9 , V_702 ) ;
if ( V_12 )
goto V_709;
}
V_12 = F_342 ( V_9 , V_692 , 1 ) ;
if ( V_12 )
goto V_710;
F_343 ( V_9 ) ;
V_708:
if ( F_60 ( V_9 ) ) {
F_73 ( V_9 -> V_92 ) ;
V_9 -> V_108 . V_109 = 0 ;
}
V_12 = F_354 ( V_9 , V_700 ) ;
if ( V_12 )
goto V_711;
V_12 = F_321 ( V_9 , false ) ;
if ( V_12 )
goto V_712;
if ( ! F_74 ( V_9 ) )
F_55 ( V_9 , false ) ;
else
F_75 ( V_9 , false , true ) ;
V_9 -> V_83 . V_88 = V_98 ;
F_7 ( V_9 ) ;
F_348 ( V_9 ) ;
goto V_48;
V_712:
F_355 ( V_9 , V_700 ) ;
V_711:
F_347 ( V_9 ) ;
if ( F_57 ( V_9 ) && ! F_58 ( V_9 ) )
F_59 ( V_9 ) ;
else if ( F_345 ( V_9 ) )
F_196 ( V_9 ) ;
V_710:
if ( ! F_336 ( V_9 , V_706 ) )
F_240 ( V_9 ) ;
V_709:
V_9 -> V_83 . V_91 = false ;
F_78 ( V_9 ) ;
V_48:
V_9 -> V_475 = 0 ;
return V_12 ;
}
static int F_356 ( struct V_8 * V_9 , enum V_699 V_700 )
{
int V_12 ;
enum V_6 V_713 ;
V_9 -> V_475 = 1 ;
V_713 = V_9 -> V_6 ;
F_349 ( V_9 ) ;
V_12 = F_55 ( V_9 , true ) ;
if ( V_12 )
goto V_48;
V_12 = F_4 ( V_9 ) ;
if ( V_12 )
goto V_714;
V_12 = F_347 ( V_9 ) ;
if ( V_12 )
goto V_714;
V_12 = F_355 ( V_9 , V_700 ) ;
if ( V_12 )
goto V_715;
if ( F_57 ( V_9 ) ) {
V_12 = F_58 ( V_9 ) ;
if ( ! V_12 )
F_59 ( V_9 ) ;
else
goto V_716;
} else if ( F_345 ( V_9 ) ) {
V_12 = F_196 ( V_9 ) ;
if ( V_12 || ! F_74 ( V_9 ) )
goto V_716;
}
if ( ! F_346 ( V_9 ) ) {
V_12 = F_336 ( V_9 , V_706 ) ;
if ( V_12 )
goto V_717;
}
F_244 ( V_9 ) ;
V_9 -> V_83 . V_91 = false ;
if ( F_60 ( V_9 ) )
F_61 ( V_9 -> V_92 ) ;
F_78 ( V_9 ) ;
goto V_48;
V_717:
F_342 ( V_9 , V_713 , 0 ) ;
V_716:
F_354 ( V_9 , V_700 ) ;
V_715:
F_343 ( V_9 ) ;
V_714:
F_7 ( V_9 ) ;
F_55 ( V_9 , false ) ;
V_48:
V_9 -> V_475 = 0 ;
return V_12 ;
}
int F_357 ( struct V_8 * V_9 )
{
int V_12 = 0 ;
if ( ! V_9 || ! V_9 -> V_678 )
return 0 ;
if ( F_358 ( V_9 -> V_18 ) ) {
if ( V_9 -> V_703 == V_9 -> V_704 )
if ( ( F_1 ( V_9 -> V_704 ) ==
V_9 -> V_691 ) && ! V_9 -> V_492 )
goto V_48;
V_12 = F_359 ( V_9 ) ;
if ( V_12 )
goto V_48;
}
V_12 = F_350 ( V_9 , V_718 ) ;
V_48:
if ( ! V_12 )
V_9 -> V_719 = true ;
return V_12 ;
}
int F_360 ( struct V_8 * V_9 )
{
if ( ! V_9 || ! V_9 -> V_678 || F_358 ( V_9 -> V_18 ) )
return 0 ;
return F_356 ( V_9 , V_718 ) ;
}
int F_361 ( struct V_8 * V_9 )
{
if ( ! V_9 || ! V_9 -> V_678 )
return 0 ;
return F_350 ( V_9 , V_720 ) ;
}
int F_359 ( struct V_8 * V_9 )
{
if ( ! V_9 || ! V_9 -> V_678 )
return 0 ;
else
return F_356 ( V_9 , V_720 ) ;
}
int F_362 ( struct V_8 * V_9 )
{
return 0 ;
}
int F_363 ( struct V_8 * V_9 )
{
int V_12 = 0 ;
if ( F_344 ( V_9 ) && F_345 ( V_9 ) )
goto V_48;
if ( F_358 ( V_9 -> V_18 ) ) {
V_12 = F_359 ( V_9 ) ;
if ( V_12 )
goto V_48;
}
V_12 = F_350 ( V_9 , V_721 ) ;
V_48:
if ( V_12 )
F_6 ( V_9 -> V_18 , L_115 , V_19 , V_12 ) ;
return 0 ;
}
void F_364 ( struct V_8 * V_9 )
{
F_365 ( V_9 -> V_86 ) ;
F_127 ( V_9 , V_9 -> V_722 ) ;
F_207 ( V_9 , true ) ;
F_366 ( V_9 -> V_86 ) ;
F_88 ( V_9 ) ;
if ( F_60 ( V_9 ) )
F_367 ( V_9 -> V_92 ) ;
F_295 ( V_9 ) ;
}
void F_368 ( struct V_8 * V_9 )
{
F_366 ( V_9 -> V_86 ) ;
}
static int F_369 ( struct V_8 * V_9 )
{
if ( V_9 -> V_158 & V_723 ) {
if ( ! F_370 ( V_9 -> V_18 , F_371 ( 64 ) ) )
return 0 ;
}
return F_370 ( V_9 -> V_18 , F_371 ( 32 ) ) ;
}
int F_372 ( struct V_111 * V_18 , struct V_8 * * V_724 )
{
struct V_247 * V_86 ;
struct V_8 * V_9 ;
int V_26 = 0 ;
if ( ! V_18 ) {
F_6 ( V_18 ,
L_116 ) ;
V_26 = - V_686 ;
goto V_725;
}
V_86 = F_373 ( & V_726 ,
sizeof( struct V_8 ) ) ;
if ( ! V_86 ) {
F_6 ( V_18 , L_117 ) ;
V_26 = - V_311 ;
goto V_725;
}
V_9 = F_140 ( V_86 ) ;
V_9 -> V_86 = V_86 ;
V_9 -> V_18 = V_18 ;
* V_724 = V_9 ;
V_725:
return V_26 ;
}
static int F_374 ( struct V_8 * V_9 , bool V_727 )
{
int V_12 = 0 ;
struct V_665 * V_666 ;
struct V_667 * V_668 = & V_9 -> V_669 ;
if ( ! V_668 || F_316 ( V_668 ) )
goto V_48;
V_12 = F_375 ( V_9 , V_727 , V_418 ) ;
if ( V_12 )
return V_12 ;
F_317 (clki, head, list) {
if ( ! F_318 ( V_666 -> V_670 ) ) {
if ( V_727 && V_666 -> V_671 ) {
if ( V_666 -> V_672 == V_666 -> V_671 )
continue;
V_12 = F_324 ( V_666 -> V_670 , V_666 -> V_671 ) ;
if ( V_12 ) {
F_6 ( V_9 -> V_18 , L_111 ,
V_19 , V_666 -> V_122 ,
V_666 -> V_671 , V_12 ) ;
break;
}
V_666 -> V_672 = V_666 -> V_671 ;
} else if ( ! V_727 && V_666 -> V_728 ) {
if ( V_666 -> V_672 == V_666 -> V_728 )
continue;
V_12 = F_324 ( V_666 -> V_670 , V_666 -> V_728 ) ;
if ( V_12 ) {
F_6 ( V_9 -> V_18 , L_111 ,
V_19 , V_666 -> V_122 ,
V_666 -> V_728 , V_12 ) ;
break;
}
V_666 -> V_672 = V_666 -> V_728 ;
}
}
F_150 ( V_9 -> V_18 , L_112 , V_19 ,
V_666 -> V_122 , F_325 ( V_666 -> V_670 ) ) ;
}
V_12 = F_375 ( V_9 , V_727 , V_415 ) ;
V_48:
return V_12 ;
}
static int F_376 ( struct V_111 * V_18 ,
unsigned long * V_729 , T_1 V_82 )
{
int V_26 = 0 ;
struct V_8 * V_9 = F_80 ( V_18 ) ;
if ( ! F_60 ( V_9 ) )
return - V_118 ;
if ( * V_729 == V_730 )
V_26 = F_374 ( V_9 , true ) ;
else if ( * V_729 == 0 )
V_26 = F_374 ( V_9 , false ) ;
return V_26 ;
}
static int F_377 ( struct V_111 * V_18 ,
struct V_731 * V_732 )
{
struct V_8 * V_9 = F_80 ( V_18 ) ;
struct V_128 * V_129 = & V_9 -> V_108 ;
unsigned long V_82 ;
if ( ! F_60 ( V_9 ) )
return - V_118 ;
memset ( V_732 , 0 , sizeof( * V_732 ) ) ;
F_53 ( V_9 -> V_86 -> V_87 , V_82 ) ;
if ( ! V_129 -> V_109 )
goto V_733;
if ( V_129 -> V_126 )
V_129 -> V_130 += F_94 ( F_95 ( F_92 () ,
V_129 -> V_127 ) ) ;
V_732 -> V_734 = F_378 ( ( long ) V_28 -
( long ) V_129 -> V_109 ) ;
V_732 -> V_735 = V_129 -> V_130 ;
V_733:
V_129 -> V_109 = V_28 ;
V_129 -> V_130 = 0 ;
if ( V_9 -> V_54 ) {
V_129 -> V_127 = F_92 () ;
V_129 -> V_126 = true ;
} else {
V_129 -> V_127 = F_96 ( 0 , 0 ) ;
V_129 -> V_126 = false ;
}
F_54 ( V_9 -> V_86 -> V_87 , V_82 ) ;
return 0 ;
}
int F_379 ( struct V_8 * V_9 , void T_9 * V_736 , unsigned int V_14 )
{
int V_26 ;
struct V_247 * V_86 = V_9 -> V_86 ;
struct V_111 * V_18 = V_9 -> V_18 ;
if ( ! V_736 ) {
F_6 ( V_9 -> V_18 ,
L_118 ) ;
V_26 = - V_686 ;
goto V_725;
}
V_9 -> V_736 = V_736 ;
V_9 -> V_14 = V_14 ;
V_26 = F_332 ( V_9 ) ;
if ( V_26 )
goto V_725;
F_105 ( V_9 ) ;
V_9 -> V_30 = F_17 ( V_9 ) ;
V_9 -> V_722 = F_16 ( V_9 ) ;
V_26 = F_369 ( V_9 ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_119 ) ;
goto V_737;
}
V_26 = F_177 ( V_9 ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_120 ) ;
goto V_737;
}
F_180 ( V_9 ) ;
V_86 -> V_738 = V_9 -> V_11 ;
V_86 -> V_739 = V_9 -> V_11 ;
V_86 -> V_740 = V_741 ;
V_86 -> V_742 = V_743 ;
V_86 -> V_744 = V_745 ;
V_86 -> V_746 = V_86 -> V_747 ;
V_86 -> V_748 = V_227 ;
V_9 -> V_399 . V_401 = false ;
F_380 ( & V_9 -> V_541 ) ;
F_380 ( & V_9 -> V_558 ) ;
F_85 ( & V_9 -> V_517 , F_253 ) ;
F_85 ( & V_9 -> V_476 , F_247 ) ;
F_381 ( & V_9 -> V_176 ) ;
F_381 ( & V_9 -> V_141 . V_283 ) ;
F_380 ( & V_9 -> V_141 . V_271 ) ;
F_83 ( V_9 ) ;
F_29 ( V_9 , F_12 ( V_9 , V_549 ) ,
V_549 ) ;
F_29 ( V_9 , 0 , V_194 ) ;
F_382 () ;
V_26 = F_383 ( V_18 , V_14 , V_15 , V_16 , V_17 , V_9 ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_121 ) ;
goto V_749;
} else {
V_9 -> V_13 = true ;
}
V_26 = F_384 ( V_86 , V_9 -> V_18 ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_122 ) ;
goto V_749;
}
V_26 = F_208 ( V_9 ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_123 ) ;
goto V_750;
}
if ( F_60 ( V_9 ) ) {
V_9 -> V_92 = F_385 ( V_18 , & V_751 ,
L_124 , NULL ) ;
if ( F_279 ( V_9 -> V_92 ) ) {
F_6 ( V_9 -> V_18 , L_125 ,
F_280 ( V_9 -> V_92 ) ) ;
goto V_750;
}
F_73 ( V_9 -> V_92 ) ;
V_9 -> V_108 . V_109 = 0 ;
}
F_248 ( V_18 ) ;
F_386 ( V_9 ) ;
F_387 ( F_296 , V_9 ) ;
return 0 ;
V_750:
F_365 ( V_9 -> V_86 ) ;
V_749:
F_88 ( V_9 ) ;
V_737:
V_9 -> V_13 = false ;
F_366 ( V_86 ) ;
F_295 ( V_9 ) ;
V_725:
return V_26 ;
}

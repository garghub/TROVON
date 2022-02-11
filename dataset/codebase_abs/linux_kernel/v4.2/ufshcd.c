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
static inline int F_3 ( struct V_8 * V_9 )
{
int V_10 = 0 ;
if ( ! V_9 -> V_11 ) {
V_10 = F_4 ( V_9 -> V_12 , V_13 , V_14 , V_15 ,
V_9 ) ;
if ( V_10 )
F_5 ( V_9 -> V_16 , L_1 ,
V_17 , V_10 ) ;
V_9 -> V_11 = true ;
}
return V_10 ;
}
static inline void F_6 ( struct V_8 * V_9 )
{
if ( V_9 -> V_11 ) {
F_7 ( V_9 -> V_12 , V_9 ) ;
V_9 -> V_11 = false ;
}
}
static int F_8 ( struct V_8 * V_9 , T_1 V_18 , T_1 V_19 ,
T_1 V_20 , unsigned long V_21 , unsigned long V_22 )
{
int V_23 = 0 ;
unsigned long V_24 = V_25 + F_9 ( V_22 ) ;
V_20 = V_20 & V_19 ;
while ( ( F_10 ( V_9 , V_18 ) & V_19 ) != V_20 ) {
F_11 ( V_21 , V_21 + 50 ) ;
if ( F_12 ( V_25 , V_24 ) ) {
if ( ( F_10 ( V_9 , V_18 ) & V_19 ) != V_20 )
V_23 = - V_26 ;
break;
}
}
return V_23 ;
}
static inline T_1 F_13 ( struct V_8 * V_9 )
{
if ( V_9 -> V_27 == V_28 )
return V_29 ;
else
return V_30 ;
}
static inline T_1 F_14 ( struct V_8 * V_9 )
{
if ( V_9 -> V_31 & V_32 ) {
if ( V_9 -> V_33 && V_9 -> V_33 -> V_34 )
return V_9 -> V_33 -> V_34 ( V_9 ) ;
}
return F_10 ( V_9 , V_35 ) ;
}
static inline int F_15 ( struct V_8 * V_9 )
{
return ( F_10 ( V_9 , V_36 ) &
V_37 ) ? 1 : 0 ;
}
static inline int F_16 ( struct V_38 * V_39 )
{
return F_17 ( V_39 -> V_40 -> V_41 . V_42 ) & V_43 ;
}
static inline int
F_18 ( struct V_44 * V_45 )
{
return F_17 ( V_45 -> V_41 . V_42 ) & V_43 ;
}
static bool F_19 ( struct V_8 * V_9 , int * V_46 )
{
int V_47 ;
bool V_10 = false ;
if ( ! V_46 )
goto V_48;
do {
V_47 = F_20 ( & V_9 -> V_49 , V_9 -> V_50 ) ;
if ( V_47 >= V_9 -> V_50 )
goto V_48;
} while ( F_21 ( V_47 , & V_9 -> V_49 ) );
* V_46 = V_47 ;
V_10 = true ;
V_48:
return V_10 ;
}
static inline void F_22 ( struct V_8 * V_9 , int V_51 )
{
F_23 ( V_51 , & V_9 -> V_49 ) ;
}
static inline void F_24 ( struct V_8 * V_9 , T_1 V_52 )
{
F_25 ( V_9 , ~ ( 1 << V_52 ) , V_53 ) ;
}
static inline int F_26 ( T_1 V_18 )
{
return ( ( ( V_18 ) & ( 0xFF ) ) >> 1 ) ^ ( 0x07 ) ;
}
static inline int F_27 ( struct V_8 * V_9 )
{
return F_10 ( V_9 , V_54 ) &
V_55 ;
}
static inline T_1 F_28 ( struct V_8 * V_9 )
{
return F_10 ( V_9 , V_56 ) ;
}
static inline int
F_29 ( struct V_57 * V_58 )
{
return F_30 ( V_58 -> V_41 . V_59 ) >> 24 ;
}
static inline int
F_31 ( struct V_57 * V_58 )
{
return F_30 ( V_58 -> V_41 . V_60 ) & V_61 ;
}
static inline unsigned int
F_32 ( struct V_57 * V_58 )
{
return F_30 ( V_58 -> V_41 . V_42 ) &
V_62 ;
}
static inline bool F_33 ( struct V_57 * V_58 )
{
return F_30 ( V_58 -> V_41 . V_42 ) &
V_63 ? true : false ;
}
static inline void
F_34 ( struct V_8 * V_9 )
{
F_25 ( V_9 , V_64 |
V_65 ,
V_66 ) ;
}
static inline void
F_35 ( struct V_8 * V_9 , T_2 V_67 , T_2 V_68 )
{
F_25 ( V_9 , V_64 | V_69 |
F_36 ( V_67 ) |
F_37 ( V_68 ) ,
V_66 ) ;
}
static inline void F_38 ( struct V_8 * V_9 )
{
F_25 ( V_9 , 0 , V_66 ) ;
}
static void F_39 ( struct V_8 * V_9 )
{
F_25 ( V_9 , V_70 ,
V_71 ) ;
F_25 ( V_9 , V_72 ,
V_73 ) ;
}
static inline void F_40 ( struct V_8 * V_9 )
{
F_25 ( V_9 , V_74 , V_75 ) ;
}
static inline int F_41 ( struct V_8 * V_9 )
{
return ( F_10 ( V_9 , V_75 ) & 0x1 ) ? 0 : 1 ;
}
static void F_42 ( struct V_76 * V_77 )
{
int V_10 ;
unsigned long V_78 ;
struct V_8 * V_9 = F_43 ( V_77 , struct V_8 ,
V_79 . V_80 ) ;
F_44 ( & V_9 -> V_79 . V_81 ) ;
F_45 ( V_9 -> V_82 -> V_83 , V_78 ) ;
if ( V_9 -> V_79 . V_84 == V_85 ) {
F_46 ( V_9 -> V_82 -> V_83 , V_78 ) ;
goto V_86;
}
F_46 ( V_9 -> V_82 -> V_83 , V_78 ) ;
F_47 ( V_9 , true ) ;
if ( F_48 ( V_9 ) ) {
V_9 -> V_79 . V_87 = true ;
if ( F_49 ( V_9 ) ) {
V_10 = F_50 ( V_9 ) ;
if ( V_10 )
F_5 ( V_9 -> V_16 , L_2 ,
V_17 , V_10 ) ;
else
F_51 ( V_9 ) ;
}
V_9 -> V_79 . V_87 = false ;
}
V_86:
if ( F_52 ( V_9 ) )
F_53 ( V_9 -> V_88 ) ;
F_54 ( V_9 -> V_82 ) ;
}
int F_55 ( struct V_8 * V_9 , bool V_89 )
{
int V_90 = 0 ;
unsigned long V_78 ;
if ( ! F_56 ( V_9 ) )
goto V_48;
F_45 ( V_9 -> V_82 -> V_83 , V_78 ) ;
V_9 -> V_79 . V_91 ++ ;
V_92:
switch ( V_9 -> V_79 . V_84 ) {
case V_85 :
break;
case V_93 :
if ( F_57 ( & V_9 -> V_79 . V_81 ) ) {
V_9 -> V_79 . V_84 = V_85 ;
break;
}
case V_94 :
F_58 ( V_9 -> V_82 ) ;
V_9 -> V_79 . V_84 = V_95 ;
F_59 ( & V_9 -> V_79 . V_80 ) ;
case V_95 :
if ( V_89 ) {
V_90 = - V_96 ;
V_9 -> V_79 . V_91 -- ;
break;
}
F_46 ( V_9 -> V_82 -> V_83 , V_78 ) ;
F_60 ( & V_9 -> V_79 . V_80 ) ;
F_45 ( V_9 -> V_82 -> V_83 , V_78 ) ;
goto V_92;
default:
F_5 ( V_9 -> V_16 , L_3 ,
V_17 , V_9 -> V_79 . V_84 ) ;
break;
}
F_46 ( V_9 -> V_82 -> V_83 , V_78 ) ;
V_48:
return V_90 ;
}
static void F_61 ( struct V_76 * V_77 )
{
struct V_8 * V_9 = F_43 ( V_77 , struct V_8 ,
V_79 . V_81 . V_77 ) ;
unsigned long V_78 ;
F_45 ( V_9 -> V_82 -> V_83 , V_78 ) ;
if ( V_9 -> V_79 . V_87 ) {
V_9 -> V_79 . V_84 = V_85 ;
goto V_97;
}
if ( V_9 -> V_79 . V_91
|| V_9 -> V_98 != V_99
|| V_9 -> V_100 || V_9 -> V_101
|| V_9 -> V_102 || V_9 -> V_103 )
goto V_97;
F_46 ( V_9 -> V_82 -> V_83 , V_78 ) ;
if ( F_48 ( V_9 ) ) {
if ( F_62 ( V_9 ) ) {
V_9 -> V_79 . V_84 = V_85 ;
goto V_48;
}
F_63 ( V_9 ) ;
}
if ( F_52 ( V_9 ) ) {
F_64 ( V_9 -> V_88 ) ;
V_9 -> V_104 . V_105 = 0 ;
}
if ( ! F_65 ( V_9 ) )
F_47 ( V_9 , false ) ;
else
F_66 ( V_9 , false , true ) ;
F_45 ( V_9 -> V_82 -> V_83 , V_78 ) ;
if ( V_9 -> V_79 . V_84 == V_93 )
V_9 -> V_79 . V_84 = V_94 ;
V_97:
F_46 ( V_9 -> V_82 -> V_83 , V_78 ) ;
V_48:
return;
}
static void F_67 ( struct V_8 * V_9 )
{
if ( ! F_56 ( V_9 ) )
return;
V_9 -> V_79 . V_91 -- ;
if ( V_9 -> V_79 . V_91 || V_9 -> V_79 . V_87
|| V_9 -> V_98 != V_99
|| V_9 -> V_100 || V_9 -> V_101
|| V_9 -> V_102 || V_9 -> V_103 )
return;
V_9 -> V_79 . V_84 = V_93 ;
F_68 ( & V_9 -> V_79 . V_81 ,
F_9 ( V_9 -> V_79 . V_106 ) ) ;
}
void F_69 ( struct V_8 * V_9 )
{
unsigned long V_78 ;
F_45 ( V_9 -> V_82 -> V_83 , V_78 ) ;
F_67 ( V_9 ) ;
F_46 ( V_9 -> V_82 -> V_83 , V_78 ) ;
}
static T_3 F_70 ( struct V_107 * V_16 ,
struct V_108 * V_109 , char * V_110 )
{
struct V_8 * V_9 = F_71 ( V_16 ) ;
return snprintf ( V_110 , V_111 , L_4 , V_9 -> V_79 . V_106 ) ;
}
static T_3 F_72 ( struct V_107 * V_16 ,
struct V_108 * V_109 , const char * V_110 , T_4 V_112 )
{
struct V_8 * V_9 = F_71 ( V_16 ) ;
unsigned long V_78 , V_113 ;
if ( F_73 ( V_110 , 0 , & V_113 ) )
return - V_114 ;
F_45 ( V_9 -> V_82 -> V_83 , V_78 ) ;
V_9 -> V_79 . V_106 = V_113 ;
F_46 ( V_9 -> V_82 -> V_83 , V_78 ) ;
return V_112 ;
}
static void F_74 ( struct V_8 * V_9 )
{
if ( ! F_56 ( V_9 ) )
return;
V_9 -> V_79 . V_106 = 150 ;
F_75 ( & V_9 -> V_79 . V_81 , F_61 ) ;
F_76 ( & V_9 -> V_79 . V_80 , F_42 ) ;
V_9 -> V_79 . V_115 . V_116 = F_70 ;
V_9 -> V_79 . V_115 . V_117 = F_72 ;
F_77 ( & V_9 -> V_79 . V_115 . V_109 ) ;
V_9 -> V_79 . V_115 . V_109 . V_118 = L_5 ;
V_9 -> V_79 . V_115 . V_109 . V_119 = V_120 | V_121 ;
if ( F_78 ( V_9 -> V_16 , & V_9 -> V_79 . V_115 ) )
F_5 ( V_9 -> V_16 , L_6 ) ;
}
static void F_79 ( struct V_8 * V_9 )
{
if ( ! F_56 ( V_9 ) )
return;
F_80 ( V_9 -> V_16 , & V_9 -> V_79 . V_115 ) ;
F_81 ( & V_9 -> V_79 . V_80 ) ;
F_44 ( & V_9 -> V_79 . V_81 ) ;
}
static void F_82 ( struct V_8 * V_9 )
{
if ( ! F_52 ( V_9 ) )
return;
if ( ! V_9 -> V_104 . V_122 ) {
V_9 -> V_104 . V_123 = F_83 () ;
V_9 -> V_104 . V_122 = true ;
}
}
static void F_84 ( struct V_8 * V_9 )
{
struct V_124 * V_125 = & V_9 -> V_104 ;
if ( ! F_52 ( V_9 ) )
return;
if ( ! V_9 -> V_126 && V_125 -> V_122 ) {
V_125 -> V_127 += F_85 ( F_86 ( F_83 () ,
V_125 -> V_123 ) ) ;
V_125 -> V_123 = F_87 ( 0 , 0 ) ;
V_125 -> V_122 = false ;
}
}
static inline
void F_88 ( struct V_8 * V_9 , unsigned int V_128 )
{
F_82 ( V_9 ) ;
F_89 ( V_128 , & V_9 -> V_126 ) ;
F_25 ( V_9 , 1 << V_128 , V_129 ) ;
}
static inline void F_90 ( struct V_38 * V_39 )
{
int V_130 ;
if ( V_39 -> V_131 &&
F_32 ( V_39 -> V_58 ) ) {
V_130 = F_91 ( V_39 -> V_58 -> V_132 . V_133 ) ;
memcpy ( V_39 -> V_131 ,
V_39 -> V_58 -> V_132 . V_134 ,
F_92 ( int , V_130 , V_135 ) ) ;
}
}
static
int F_93 ( struct V_8 * V_9 , struct V_38 * V_39 )
{
struct V_136 * V_137 = & V_9 -> V_138 . V_139 . V_140 ;
memcpy ( & V_137 -> V_141 , & V_39 -> V_58 -> V_142 , V_143 ) ;
if ( V_39 -> V_58 -> V_142 . V_144 == V_145 ) {
T_2 * V_146 = ( T_2 * ) V_39 -> V_58 +
V_147 ;
T_5 V_148 ;
T_5 V_149 ;
V_148 = F_30 ( V_39 -> V_58 -> V_41 . V_42 ) &
V_150 ;
V_149 = F_91 (
V_9 -> V_138 . V_139 . V_151 . V_152 . V_153 ) ;
if ( F_94 ( V_149 >= V_148 ) ) {
memcpy ( V_9 -> V_138 . V_139 . V_154 , V_146 , V_148 ) ;
} else {
F_95 ( V_9 -> V_16 ,
L_7 ,
V_17 ) ;
return - V_114 ;
}
}
return 0 ;
}
static inline void F_96 ( struct V_8 * V_9 )
{
V_9 -> V_155 = F_10 ( V_9 , V_156 ) ;
V_9 -> V_157 = ( V_9 -> V_155 & V_158 ) + 1 ;
V_9 -> V_50 =
( ( V_9 -> V_155 & V_159 ) >> 16 ) + 1 ;
}
static inline bool F_97 ( struct V_8 * V_9 )
{
if ( F_10 ( V_9 , V_36 ) & V_160 )
return true ;
else
return false ;
}
static inline T_2 F_98 ( struct V_8 * V_9 )
{
return ( F_10 ( V_9 , V_36 ) >> 8 ) & 0x7 ;
}
static inline void
F_99 ( struct V_8 * V_9 , struct V_161 * V_162 )
{
F_100 ( V_9 -> V_102 ) ;
V_9 -> V_102 = V_162 ;
F_25 ( V_9 , V_162 -> V_163 , V_164 ) ;
F_25 ( V_9 , V_162 -> V_165 , V_54 ) ;
F_25 ( V_9 , V_162 -> V_166 , V_56 ) ;
F_25 ( V_9 , V_162 -> V_167 & V_168 ,
V_169 ) ;
}
static int
F_101 ( struct V_8 * V_9 , struct V_161 * V_162 )
{
int V_10 ;
unsigned long V_78 ;
if ( F_102 ( & V_162 -> V_170 ,
F_9 ( V_171 ) ) )
V_10 = V_162 -> V_165 & V_55 ;
else
V_10 = - V_26 ;
F_45 ( V_9 -> V_82 -> V_83 , V_78 ) ;
V_9 -> V_102 = NULL ;
F_46 ( V_9 -> V_82 -> V_83 , V_78 ) ;
return V_10 ;
}
static int
F_103 ( struct V_8 * V_9 , struct V_161 * V_162 )
{
if ( ! F_97 ( V_9 ) ) {
F_5 ( V_9 -> V_16 ,
L_8 ) ;
return - V_172 ;
}
F_104 ( & V_162 -> V_170 ) ;
F_99 ( V_9 , V_162 ) ;
return 0 ;
}
static int
F_105 ( struct V_8 * V_9 , struct V_161 * V_162 )
{
int V_10 ;
unsigned long V_78 ;
F_55 ( V_9 , false ) ;
F_106 ( & V_9 -> V_173 ) ;
F_107 ( V_9 ) ;
F_45 ( V_9 -> V_82 -> V_83 , V_78 ) ;
V_10 = F_103 ( V_9 , V_162 ) ;
F_46 ( V_9 -> V_82 -> V_83 , V_78 ) ;
if ( ! V_10 )
V_10 = F_101 ( V_9 , V_162 ) ;
F_108 ( & V_9 -> V_173 ) ;
F_69 ( V_9 ) ;
return V_10 ;
}
static int F_109 ( struct V_38 * V_39 )
{
struct V_174 * V_175 ;
struct V_176 * V_177 ;
struct V_178 * V_179 ;
int V_180 ;
int V_181 ;
V_179 = V_39 -> V_179 ;
V_180 = F_110 ( V_179 ) ;
if ( V_180 < 0 )
return V_180 ;
if ( V_180 ) {
V_39 -> V_40 -> V_182 =
F_111 ( ( T_5 ) ( V_180 ) ) ;
V_175 = (struct V_174 * ) V_39 -> V_183 ;
F_112 (cmd, sg, sg_segments, i) {
V_175 [ V_181 ] . V_184 =
F_113 ( ( ( T_1 ) F_114 ( V_177 ) ) - 1 ) ;
V_175 [ V_181 ] . V_185 =
F_113 ( F_115 ( V_177 -> V_186 ) ) ;
V_175 [ V_181 ] . V_187 =
F_113 ( F_116 ( V_177 -> V_186 ) ) ;
}
} else {
V_39 -> V_40 -> V_182 = 0 ;
}
return 0 ;
}
static void F_117 ( struct V_8 * V_9 , T_1 V_188 )
{
T_1 V_189 = F_10 ( V_9 , V_190 ) ;
if ( V_9 -> V_27 == V_28 ) {
T_1 V_191 ;
V_191 = V_189 & V_192 ;
V_189 = V_191 | ( ( V_189 ^ V_188 ) & V_188 ) ;
} else {
V_189 |= V_188 ;
}
F_25 ( V_9 , V_189 , V_190 ) ;
}
static void F_118 ( struct V_8 * V_9 , T_1 V_188 )
{
T_1 V_189 = F_10 ( V_9 , V_190 ) ;
if ( V_9 -> V_27 == V_28 ) {
T_1 V_191 ;
V_191 = ( V_189 & V_192 ) &
~ ( V_188 & V_192 ) ;
V_189 = V_191 | ( ( V_189 & V_188 ) & ~ V_192 ) ;
} else {
V_189 &= ~ V_188 ;
}
F_25 ( V_9 , V_189 , V_190 ) ;
}
static void F_119 ( struct V_38 * V_39 ,
T_1 * V_193 , enum V_194 V_195 )
{
struct V_196 * V_197 = V_39 -> V_40 ;
T_1 V_198 ;
T_1 V_59 ;
if ( V_195 == V_199 ) {
V_198 = V_200 ;
* V_193 = V_201 ;
} else if ( V_195 == V_202 ) {
V_198 = V_203 ;
* V_193 = V_204 ;
} else {
V_198 = V_205 ;
* V_193 = V_206 ;
}
V_59 = V_198 | ( V_39 -> V_207
<< V_208 ) ;
if ( V_39 -> V_209 )
V_59 |= V_210 ;
V_197 -> V_41 . V_59 = F_113 ( V_59 ) ;
V_197 -> V_41 . V_42 =
F_113 ( V_211 ) ;
}
static
void F_120 ( struct V_38 * V_39 , T_1 V_193 )
{
struct V_212 * V_213 = V_39 -> V_213 ;
V_213 -> V_41 . V_59 = F_121 (
V_214 , V_193 ,
V_39 -> V_215 , V_39 -> V_128 ) ;
V_213 -> V_41 . V_60 = F_121 (
V_216 , 0 , 0 , 0 ) ;
V_213 -> V_41 . V_42 = 0 ;
V_213 -> V_217 . V_218 =
F_122 ( V_39 -> V_179 -> V_219 . V_153 ) ;
memcpy ( V_213 -> V_217 . V_220 , V_39 -> V_179 -> V_221 ,
( F_92 (unsigned short, lrbp->cmd->cmd_len, MAX_CDB_SIZE) ) ) ;
}
static void F_123 ( struct V_8 * V_9 ,
struct V_38 * V_39 , T_1 V_193 )
{
struct V_212 * V_213 = V_39 -> V_213 ;
struct V_222 * V_139 = & V_9 -> V_138 . V_139 ;
T_5 V_130 = F_91 ( V_139 -> V_151 . V_152 . V_153 ) ;
T_2 * V_146 = ( T_2 * ) V_39 -> V_213 + V_147 ;
V_213 -> V_41 . V_59 = F_121 (
V_223 , V_193 ,
V_39 -> V_215 , V_39 -> V_128 ) ;
V_213 -> V_41 . V_60 = F_121 (
0 , V_139 -> V_151 . V_224 , 0 , 0 ) ;
V_213 -> V_41 . V_42 = F_121 (
0 , 0 , V_130 >> 8 , ( T_2 ) V_130 ) ;
memcpy ( & V_213 -> V_142 , & V_139 -> V_151 . V_152 ,
V_143 ) ;
if ( V_139 -> V_151 . V_152 . V_144 == V_225 )
memcpy ( V_146 , V_139 -> V_154 , V_130 ) ;
}
static inline void F_124 ( struct V_38 * V_39 )
{
struct V_212 * V_213 = V_39 -> V_213 ;
memset ( V_213 , 0 , sizeof( struct V_212 ) ) ;
V_213 -> V_41 . V_59 =
F_121 (
V_226 , 0 , 0 , V_39 -> V_128 ) ;
}
static int F_125 ( struct V_8 * V_9 , struct V_38 * V_39 )
{
T_1 V_193 ;
int V_10 = 0 ;
switch ( V_39 -> V_207 ) {
case V_227 :
if ( F_94 ( V_39 -> V_179 ) ) {
F_119 ( V_39 , & V_193 ,
V_39 -> V_179 -> V_228 ) ;
F_120 ( V_39 , V_193 ) ;
} else {
V_10 = - V_114 ;
}
break;
case V_229 :
F_119 ( V_39 , & V_193 , V_230 ) ;
if ( V_9 -> V_138 . type == V_231 )
F_123 (
V_9 , V_39 , V_193 ) ;
else if ( V_9 -> V_138 . type == V_232 )
F_124 ( V_39 ) ;
else
V_10 = - V_114 ;
break;
case V_233 :
V_10 = - V_234 ;
F_5 ( V_9 -> V_16 , L_9 ,
V_17 ) ;
break;
default:
V_10 = - V_234 ;
F_5 ( V_9 -> V_16 , L_10 ,
V_17 , V_39 -> V_207 ) ;
break;
}
return V_10 ;
}
static inline T_2 F_126 ( unsigned int V_235 )
{
if ( F_127 ( V_235 ) )
return ( V_235 & V_236 )
| V_237 ;
else
return V_235 & V_236 ;
}
static inline T_5 F_128 ( T_2 V_238 )
{
return ( V_238 & ~ V_237 ) | V_239 ;
}
static int F_129 ( struct V_240 * V_82 , struct V_178 * V_179 )
{
struct V_38 * V_39 ;
struct V_8 * V_9 ;
unsigned long V_78 ;
int V_47 ;
int V_23 = 0 ;
V_9 = F_130 ( V_82 ) ;
V_47 = V_179 -> V_151 -> V_47 ;
F_45 ( V_9 -> V_82 -> V_83 , V_78 ) ;
switch ( V_9 -> V_98 ) {
case V_99 :
break;
case V_241 :
V_23 = V_242 ;
goto V_243;
case V_244 :
F_131 ( V_179 , V_245 ) ;
V_179 -> V_246 ( V_179 ) ;
goto V_243;
default:
F_132 ( V_9 -> V_16 , 1 , L_11 ,
V_17 , V_9 -> V_98 ) ;
F_131 ( V_179 , V_247 ) ;
V_179 -> V_246 ( V_179 ) ;
goto V_243;
}
F_46 ( V_9 -> V_82 -> V_83 , V_78 ) ;
if ( F_21 ( V_47 , & V_9 -> V_100 ) ) {
V_23 = V_242 ;
goto V_48;
}
V_23 = F_55 ( V_9 , true ) ;
if ( V_23 ) {
V_23 = V_242 ;
F_23 ( V_47 , & V_9 -> V_100 ) ;
goto V_48;
}
F_100 ( V_9 -> V_79 . V_84 != V_85 ) ;
V_39 = & V_9 -> V_248 [ V_47 ] ;
F_100 ( V_39 -> V_179 ) ;
V_39 -> V_179 = V_179 ;
V_39 -> V_249 = V_135 ;
V_39 -> V_131 = V_179 -> V_131 ;
V_39 -> V_128 = V_47 ;
V_39 -> V_215 = F_126 ( V_179 -> V_107 -> V_215 ) ;
V_39 -> V_209 = ! F_133 ( V_9 ) ? true : false ;
V_39 -> V_207 = V_227 ;
F_125 ( V_9 , V_39 ) ;
V_23 = F_109 ( V_39 ) ;
if ( V_23 ) {
V_39 -> V_179 = NULL ;
F_23 ( V_47 , & V_9 -> V_100 ) ;
goto V_48;
}
F_45 ( V_9 -> V_82 -> V_83 , V_78 ) ;
F_88 ( V_9 , V_47 ) ;
V_243:
F_46 ( V_9 -> V_82 -> V_83 , V_78 ) ;
V_48:
return V_23 ;
}
static int F_134 ( struct V_8 * V_9 ,
struct V_38 * V_39 , enum V_250 V_251 , int V_47 )
{
V_39 -> V_179 = NULL ;
V_39 -> V_249 = 0 ;
V_39 -> V_131 = NULL ;
V_39 -> V_128 = V_47 ;
V_39 -> V_215 = 0 ;
V_39 -> V_207 = V_229 ;
V_39 -> V_209 = true ;
V_9 -> V_138 . type = V_251 ;
return F_125 ( V_9 , V_39 ) ;
}
static int
F_135 ( struct V_8 * V_9 , int V_47 )
{
int V_23 = 0 ;
unsigned long V_78 ;
T_1 V_19 = 1 << V_47 ;
F_45 ( V_9 -> V_82 -> V_83 , V_78 ) ;
F_24 ( V_9 , V_47 ) ;
F_46 ( V_9 -> V_82 -> V_83 , V_78 ) ;
V_23 = F_8 ( V_9 ,
V_129 ,
V_19 , ~ V_19 , 1000 , 1000 ) ;
return V_23 ;
}
static int
F_136 ( struct V_8 * V_9 , struct V_38 * V_39 )
{
struct V_136 * V_137 = & V_9 -> V_138 . V_139 . V_140 ;
V_137 -> V_140 = F_31 ( V_39 -> V_58 ) >>
V_252 ;
return V_137 -> V_140 ;
}
static int
F_137 ( struct V_8 * V_9 , struct V_38 * V_39 )
{
int V_253 ;
int V_23 = 0 ;
V_253 = F_29 ( V_39 -> V_58 ) ;
switch ( V_253 ) {
case V_254 :
if ( V_9 -> V_138 . type != V_232 ) {
V_23 = - V_114 ;
F_5 ( V_9 -> V_16 , L_12 ,
V_17 , V_253 ) ;
}
break;
case V_255 :
V_23 = F_136 ( V_9 , V_39 ) ;
if ( ! V_23 )
V_23 = F_93 ( V_9 , V_39 ) ;
break;
case V_256 :
V_23 = - V_257 ;
F_5 ( V_9 -> V_16 , L_13 ,
V_17 ) ;
break;
default:
V_23 = - V_114 ;
F_5 ( V_9 -> V_16 , L_14 ,
V_17 , V_253 ) ;
break;
}
return V_23 ;
}
static int F_138 ( struct V_8 * V_9 ,
struct V_38 * V_39 , int V_258 )
{
int V_23 = 0 ;
unsigned long V_259 ;
unsigned long V_78 ;
V_259 = F_102 ( V_9 -> V_138 . V_260 ,
F_9 ( V_258 ) ) ;
F_45 ( V_9 -> V_82 -> V_83 , V_78 ) ;
V_9 -> V_138 . V_260 = NULL ;
if ( F_94 ( V_259 ) ) {
V_23 = F_16 ( V_39 ) ;
if ( ! V_23 )
V_23 = F_137 ( V_9 , V_39 ) ;
}
F_46 ( V_9 -> V_82 -> V_83 , V_78 ) ;
if ( ! V_259 ) {
V_23 = - V_26 ;
if ( ! F_135 ( V_9 , V_39 -> V_128 ) )
V_23 = - V_96 ;
}
return V_23 ;
}
static bool F_139 ( struct V_8 * V_9 , int * V_261 )
{
int V_47 ;
bool V_10 = false ;
unsigned long V_262 ;
if ( ! V_261 )
goto V_48;
do {
V_262 = ~ V_9 -> V_100 ;
V_47 = F_140 ( & V_262 , V_9 -> V_157 ) ;
if ( V_47 >= V_9 -> V_157 )
goto V_48;
} while ( F_21 ( V_47 , & V_9 -> V_100 ) );
* V_261 = V_47 ;
V_10 = true ;
V_48:
return V_10 ;
}
static inline void F_141 ( struct V_8 * V_9 , int V_47 )
{
F_23 ( V_47 , & V_9 -> V_100 ) ;
}
static int F_142 ( struct V_8 * V_9 ,
enum V_250 V_251 , int V_24 )
{
struct V_38 * V_39 ;
int V_23 ;
int V_47 ;
struct V_263 V_264 ;
unsigned long V_78 ;
F_143 ( V_9 -> V_138 . V_265 , F_139 ( V_9 , & V_47 ) ) ;
F_104 ( & V_264 ) ;
V_39 = & V_9 -> V_248 [ V_47 ] ;
F_100 ( V_39 -> V_179 ) ;
V_23 = F_134 ( V_9 , V_39 , V_251 , V_47 ) ;
if ( F_144 ( V_23 ) )
goto V_266;
V_9 -> V_138 . V_260 = & V_264 ;
F_45 ( V_9 -> V_82 -> V_83 , V_78 ) ;
F_88 ( V_9 , V_47 ) ;
F_46 ( V_9 -> V_82 -> V_83 , V_78 ) ;
V_23 = F_138 ( V_9 , V_39 , V_24 ) ;
V_266:
F_141 ( V_9 , V_47 ) ;
F_145 ( & V_9 -> V_138 . V_265 ) ;
return V_23 ;
}
static inline void F_146 ( struct V_8 * V_9 ,
struct V_267 * * V_151 , struct V_136 * * V_140 ,
enum V_268 V_144 , T_2 V_269 , T_2 V_270 , T_2 V_271 )
{
* V_151 = & V_9 -> V_138 . V_139 . V_151 ;
* V_140 = & V_9 -> V_138 . V_139 . V_140 ;
memset ( * V_151 , 0 , sizeof( struct V_267 ) ) ;
memset ( * V_140 , 0 , sizeof( struct V_136 ) ) ;
( * V_151 ) -> V_152 . V_144 = V_144 ;
( * V_151 ) -> V_152 . V_269 = V_269 ;
( * V_151 ) -> V_152 . V_270 = V_270 ;
( * V_151 ) -> V_152 . V_271 = V_271 ;
}
static int F_147 ( struct V_8 * V_9 , enum V_268 V_144 ,
enum V_272 V_269 , bool * V_273 )
{
struct V_267 * V_151 = NULL ;
struct V_136 * V_140 = NULL ;
int V_23 , V_270 = 0 , V_271 = 0 ;
F_148 ( ! V_9 ) ;
F_55 ( V_9 , false ) ;
F_106 ( & V_9 -> V_138 . V_274 ) ;
F_146 ( V_9 , & V_151 , & V_140 , V_144 , V_269 , V_270 ,
V_271 ) ;
switch ( V_144 ) {
case V_275 :
case V_276 :
case V_277 :
V_151 -> V_224 = V_278 ;
break;
case V_279 :
V_151 -> V_224 = V_280 ;
if ( ! V_273 ) {
F_5 ( V_9 -> V_16 , L_15 ,
V_17 ) ;
V_23 = - V_114 ;
goto V_243;
}
break;
default:
F_5 ( V_9 -> V_16 ,
L_16 ,
V_17 , V_144 ) ;
V_23 = - V_114 ;
goto V_243;
}
V_23 = F_142 ( V_9 , V_231 , V_281 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 ,
L_17 ,
V_17 , V_269 , V_23 ) ;
goto V_243;
}
if ( V_273 )
* V_273 = ( F_30 ( V_140 -> V_141 . V_113 ) &
V_282 ) & 0x1 ;
V_243:
F_108 ( & V_9 -> V_138 . V_274 ) ;
F_69 ( V_9 ) ;
return V_23 ;
}
static int F_149 ( struct V_8 * V_9 , enum V_268 V_144 ,
enum V_283 V_269 , T_2 V_270 , T_2 V_271 , T_1 * V_284 )
{
struct V_267 * V_151 = NULL ;
struct V_136 * V_140 = NULL ;
int V_23 ;
F_148 ( ! V_9 ) ;
F_55 ( V_9 , false ) ;
if ( ! V_284 ) {
F_5 ( V_9 -> V_16 , L_18 ,
V_17 , V_144 ) ;
V_23 = - V_114 ;
goto V_48;
}
F_106 ( & V_9 -> V_138 . V_274 ) ;
F_146 ( V_9 , & V_151 , & V_140 , V_144 , V_269 , V_270 ,
V_271 ) ;
switch ( V_144 ) {
case V_285 :
V_151 -> V_224 = V_278 ;
V_151 -> V_152 . V_113 = F_122 ( * V_284 ) ;
break;
case V_286 :
V_151 -> V_224 = V_280 ;
break;
default:
F_5 ( V_9 -> V_16 , L_19 ,
V_17 , V_144 ) ;
V_23 = - V_114 ;
goto V_243;
}
V_23 = F_142 ( V_9 , V_231 , V_281 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_20 ,
V_17 , V_144 , V_269 , V_23 ) ;
goto V_243;
}
* V_284 = F_30 ( V_140 -> V_141 . V_113 ) ;
V_243:
F_108 ( & V_9 -> V_138 . V_274 ) ;
V_48:
F_69 ( V_9 ) ;
return V_23 ;
}
static int F_150 ( struct V_8 * V_9 ,
enum V_268 V_144 , enum V_287 V_269 , T_2 V_270 ,
T_2 V_271 , T_2 * V_288 , int * V_149 )
{
struct V_267 * V_151 = NULL ;
struct V_136 * V_140 = NULL ;
int V_23 ;
F_148 ( ! V_9 ) ;
F_55 ( V_9 , false ) ;
if ( ! V_288 ) {
F_5 ( V_9 -> V_16 , L_21 ,
V_17 , V_144 ) ;
V_23 = - V_114 ;
goto V_48;
}
if ( * V_149 <= V_289 || * V_149 > V_290 ) {
F_5 ( V_9 -> V_16 , L_22 ,
V_17 , * V_149 ) ;
V_23 = - V_114 ;
goto V_48;
}
F_106 ( & V_9 -> V_138 . V_274 ) ;
F_146 ( V_9 , & V_151 , & V_140 , V_144 , V_269 , V_270 ,
V_271 ) ;
V_9 -> V_138 . V_139 . V_154 = V_288 ;
V_151 -> V_152 . V_153 = F_151 ( * V_149 ) ;
switch ( V_144 ) {
case V_225 :
V_151 -> V_224 = V_278 ;
break;
case V_145 :
V_151 -> V_224 = V_280 ;
break;
default:
F_5 ( V_9 -> V_16 ,
L_23 ,
V_17 , V_144 ) ;
V_23 = - V_114 ;
goto V_243;
}
V_23 = F_142 ( V_9 , V_231 , V_281 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_20 ,
V_17 , V_144 , V_269 , V_23 ) ;
goto V_243;
}
V_9 -> V_138 . V_139 . V_154 = NULL ;
* V_149 = F_91 ( V_140 -> V_141 . V_153 ) ;
V_243:
F_108 ( & V_9 -> V_138 . V_274 ) ;
V_48:
F_69 ( V_9 ) ;
return V_23 ;
}
static int F_152 ( struct V_8 * V_9 ,
enum V_287 V_291 ,
int V_292 ,
T_1 V_293 ,
T_2 * V_294 ,
T_1 V_295 )
{
int V_10 ;
T_2 * V_288 ;
T_1 V_296 ;
bool V_297 = true ;
if ( V_291 >= V_298 )
return - V_114 ;
V_296 = V_299 [ V_291 ] ;
if ( ( V_293 + V_295 ) > V_296 )
return - V_114 ;
if ( ! V_293 && ( V_295 == V_296 ) ) {
V_288 = V_294 ;
V_297 = false ;
} else {
V_288 = F_153 ( V_296 , V_300 ) ;
if ( ! V_288 )
return - V_301 ;
}
V_10 = F_150 ( V_9 , V_145 ,
V_291 , V_292 , 0 , V_288 ,
& V_296 ) ;
if ( V_10 || ( V_296 < V_299 [ V_291 ] ) ||
( V_288 [ V_302 ] !=
V_299 [ V_291 ] )
|| ( V_288 [ V_303 ] != V_291 ) ) {
F_5 ( V_9 -> V_16 , L_24 ,
V_17 , V_291 , V_293 , V_296 , V_10 ) ;
if ( ! V_10 )
V_10 = - V_114 ;
goto V_48;
}
if ( V_297 )
memcpy ( V_294 , & V_288 [ V_293 ] , V_295 ) ;
V_48:
if ( V_297 )
F_154 ( V_288 ) ;
return V_10 ;
}
static inline int F_155 ( struct V_8 * V_9 ,
enum V_287 V_291 ,
int V_292 ,
T_2 * V_110 ,
T_1 V_184 )
{
return F_152 ( V_9 , V_291 , V_292 , 0 , V_110 , V_184 ) ;
}
static inline int F_156 ( struct V_8 * V_9 ,
T_2 * V_110 ,
T_1 V_184 )
{
return F_155 ( V_9 , V_304 , 0 , V_110 , V_184 ) ;
}
static inline int F_157 ( struct V_8 * V_9 ,
int V_215 ,
enum V_305 V_293 ,
T_2 * V_294 ,
T_1 V_295 )
{
if ( V_215 != V_306 && ( V_215 >= V_307 ) )
return - V_308 ;
return F_152 ( V_9 , V_309 , V_215 ,
V_293 , V_294 , V_295 ) ;
}
static int F_158 ( struct V_8 * V_9 )
{
T_4 V_310 , V_311 , V_312 ;
V_312 = ( sizeof( struct V_313 ) * V_9 -> V_157 ) ;
V_9 -> V_314 = F_159 ( V_9 -> V_16 ,
V_312 ,
& V_9 -> V_315 ,
V_300 ) ;
if ( ! V_9 -> V_314 ||
F_100 ( V_9 -> V_315 & ( V_111 - 1 ) ) ) {
F_5 ( V_9 -> V_16 ,
L_25 ) ;
goto V_48;
}
V_311 = ( sizeof( struct V_196 ) * V_9 -> V_157 ) ;
V_9 -> V_316 = F_159 ( V_9 -> V_16 ,
V_311 ,
& V_9 -> V_317 ,
V_300 ) ;
if ( ! V_9 -> V_316 ||
F_100 ( V_9 -> V_317 & ( V_111 - 1 ) ) ) {
F_5 ( V_9 -> V_16 ,
L_26 ) ;
goto V_48;
}
V_310 = sizeof( struct V_44 ) * V_9 -> V_50 ;
V_9 -> V_318 = F_159 ( V_9 -> V_16 ,
V_310 ,
& V_9 -> V_319 ,
V_300 ) ;
if ( ! V_9 -> V_318 ||
F_100 ( V_9 -> V_319 & ( V_111 - 1 ) ) ) {
F_5 ( V_9 -> V_16 ,
L_27 ) ;
goto V_48;
}
V_9 -> V_248 = F_160 ( V_9 -> V_16 ,
V_9 -> V_157 * sizeof( struct V_38 ) ,
V_300 ) ;
if ( ! V_9 -> V_248 ) {
F_5 ( V_9 -> V_16 , L_28 ) ;
goto V_48;
}
return 0 ;
V_48:
return - V_301 ;
}
static void F_161 ( struct V_8 * V_9 )
{
struct V_313 * V_320 ;
struct V_196 * V_321 ;
T_6 V_322 ;
T_6 V_323 ;
T_5 V_324 ;
T_5 V_325 ;
int V_326 ;
int V_181 ;
V_321 = V_9 -> V_316 ;
V_320 = V_9 -> V_314 ;
V_324 =
F_162 ( struct V_313 , V_327 ) ;
V_325 =
F_162 ( struct V_313 , V_175 ) ;
V_326 = sizeof( struct V_313 ) ;
V_322 = V_9 -> V_315 ;
for ( V_181 = 0 ; V_181 < V_9 -> V_157 ; V_181 ++ ) {
V_323 =
( V_322 + ( V_326 * V_181 ) ) ;
V_321 [ V_181 ] . V_328 =
F_113 ( F_115 ( V_323 ) ) ;
V_321 [ V_181 ] . V_329 =
F_113 ( F_116 ( V_323 ) ) ;
V_321 [ V_181 ] . V_330 =
F_111 ( ( V_324 >> 2 ) ) ;
V_321 [ V_181 ] . V_331 =
F_111 ( ( V_325 >> 2 ) ) ;
V_321 [ V_181 ] . V_332 =
F_111 ( V_333 >> 2 ) ;
V_9 -> V_248 [ V_181 ] . V_40 = ( V_321 + V_181 ) ;
V_9 -> V_248 [ V_181 ] . V_213 =
(struct V_212 * ) ( V_320 + V_181 ) ;
V_9 -> V_248 [ V_181 ] . V_58 =
(struct V_57 * ) V_320 [ V_181 ] . V_327 ;
V_9 -> V_248 [ V_181 ] . V_183 =
(struct V_174 * ) V_320 [ V_181 ] . V_175 ;
}
}
static int F_163 ( struct V_8 * V_9 )
{
struct V_161 V_162 = { 0 } ;
int V_10 ;
V_162 . V_167 = V_334 ;
V_10 = F_105 ( V_9 , & V_162 ) ;
if ( V_10 )
F_5 ( V_9 -> V_16 ,
L_29 , V_10 ) ;
return V_10 ;
}
static inline void F_107 ( struct V_8 * V_9 )
{
#define F_164 1000
unsigned long V_335 ;
if ( ! ( V_9 -> V_31 & V_336 ) )
return;
if ( F_144 ( ! F_85 ( V_9 -> V_337 ) ) ) {
V_335 = F_164 ;
} else {
unsigned long V_338 =
( unsigned long ) F_85 (
F_86 ( F_83 () ,
V_9 -> V_337 ) ) ;
if ( V_338 < F_164 )
V_335 =
F_164 - V_338 ;
else
return;
}
F_11 ( V_335 , V_335 + 50 ) ;
}
int F_165 ( struct V_8 * V_9 , T_1 V_339 ,
T_2 V_340 , T_1 V_341 , T_2 V_342 )
{
struct V_161 V_162 = { 0 } ;
static const char * const V_343 [] = {
L_30 ,
L_31
} ;
const char * V_189 = V_343 [ ! ! V_342 ] ;
int V_10 ;
V_162 . V_167 = V_342 ?
V_344 : V_345 ;
V_162 . V_163 = V_339 ;
V_162 . V_165 = F_166 ( V_340 ) ;
V_162 . V_166 = V_341 ;
V_10 = F_105 ( V_9 , & V_162 ) ;
if ( V_10 )
F_5 ( V_9 -> V_16 , L_32 ,
V_189 , F_167 ( V_339 ) , V_341 , V_10 ) ;
return V_10 ;
}
int F_168 ( struct V_8 * V_9 , T_1 V_339 ,
T_1 * V_341 , T_2 V_342 )
{
struct V_161 V_162 = { 0 } ;
static const char * const V_343 [] = {
L_33 ,
L_34
} ;
const char * V_346 = V_343 [ ! ! V_342 ] ;
int V_10 ;
struct V_347 V_348 ;
struct V_347 V_349 ;
bool V_350 = false ;
if ( V_342 && ( V_9 -> V_31 & V_351 ) ) {
V_348 = V_9 -> V_352 ;
V_349 = V_348 ;
if ( V_348 . V_353 == V_354 ||
V_348 . V_355 == V_354 ) {
V_349 . V_353 = V_356 ;
V_349 . V_355 = V_356 ;
V_350 = true ;
} else if ( V_348 . V_353 == V_357 ||
V_348 . V_355 == V_357 ) {
V_349 . V_353 = V_358 ;
V_349 . V_355 = V_358 ;
V_350 = true ;
}
if ( V_350 ) {
V_10 = F_169 ( V_9 , & V_349 ) ;
if ( V_10 )
goto V_48;
}
}
V_162 . V_167 = V_342 ?
V_359 : V_360 ;
V_162 . V_163 = V_339 ;
V_10 = F_105 ( V_9 , & V_162 ) ;
if ( V_10 ) {
F_5 ( V_9 -> V_16 , L_35 ,
V_346 , F_167 ( V_339 ) , V_10 ) ;
goto V_48;
}
if ( V_341 )
* V_341 = V_162 . V_166 ;
if ( V_342 && ( V_9 -> V_31 & V_351 )
&& V_350 )
F_169 ( V_9 , & V_348 ) ;
V_48:
return V_10 ;
}
static int F_170 ( struct V_8 * V_9 , struct V_161 * V_179 )
{
struct V_263 V_103 ;
unsigned long V_78 ;
T_2 V_361 ;
int V_10 ;
F_106 ( & V_9 -> V_173 ) ;
F_104 ( & V_103 ) ;
F_107 ( V_9 ) ;
F_45 ( V_9 -> V_82 -> V_83 , V_78 ) ;
V_9 -> V_103 = & V_103 ;
V_10 = F_103 ( V_9 , V_179 ) ;
F_46 ( V_9 -> V_82 -> V_83 , V_78 ) ;
if ( V_10 ) {
F_5 ( V_9 -> V_16 ,
L_36 ,
V_179 -> V_167 , V_179 -> V_166 , V_10 ) ;
goto V_48;
}
V_10 = F_101 ( V_9 , V_179 ) ;
if ( V_10 ) {
F_5 ( V_9 -> V_16 ,
L_36 ,
V_179 -> V_167 , V_179 -> V_166 , V_10 ) ;
goto V_48;
}
if ( ! F_102 ( V_9 -> V_103 ,
F_9 ( V_171 ) ) ) {
F_5 ( V_9 -> V_16 ,
L_37 ,
V_179 -> V_167 , V_179 -> V_166 ) ;
V_10 = - V_26 ;
goto V_48;
}
V_361 = F_98 ( V_9 ) ;
if ( V_361 != V_362 ) {
F_5 ( V_9 -> V_16 ,
L_38 ,
V_179 -> V_167 , V_361 ) ;
V_10 = ( V_361 != V_363 ) ? V_361 : - 1 ;
}
V_48:
F_45 ( V_9 -> V_82 -> V_83 , V_78 ) ;
V_9 -> V_103 = NULL ;
F_46 ( V_9 -> V_82 -> V_83 , V_78 ) ;
F_108 ( & V_9 -> V_173 ) ;
return V_10 ;
}
static int F_171 ( struct V_8 * V_9 , T_2 V_119 )
{
struct V_161 V_162 = { 0 } ;
int V_10 ;
if ( V_9 -> V_31 & V_364 ) {
V_10 = F_172 ( V_9 ,
F_173 ( V_365 , 0 ) , 1 ) ;
if ( V_10 ) {
F_5 ( V_9 -> V_16 , L_39 ,
V_17 , V_10 ) ;
goto V_48;
}
}
V_162 . V_167 = V_345 ;
V_162 . V_163 = F_174 ( V_366 ) ;
V_162 . V_166 = V_119 ;
F_55 ( V_9 , false ) ;
V_10 = F_170 ( V_9 , & V_162 ) ;
F_69 ( V_9 ) ;
V_48:
return V_10 ;
}
static int F_62 ( struct V_8 * V_9 )
{
struct V_161 V_162 = { 0 } ;
V_162 . V_167 = V_367 ;
return F_170 ( V_9 , & V_162 ) ;
}
static int F_50 ( struct V_8 * V_9 )
{
struct V_161 V_162 = { 0 } ;
int V_10 ;
V_162 . V_167 = V_368 ;
V_10 = F_170 ( V_9 , & V_162 ) ;
if ( V_10 ) {
F_175 ( V_9 ) ;
V_10 = F_176 ( V_9 ) ;
}
return V_10 ;
}
static void F_177 ( struct V_8 * V_9 )
{
V_9 -> V_352 . V_369 = V_370 ;
V_9 -> V_352 . V_371 = V_370 ;
V_9 -> V_352 . V_372 = 1 ;
V_9 -> V_352 . V_373 = 1 ;
V_9 -> V_352 . V_355 = V_358 ;
V_9 -> V_352 . V_353 = V_358 ;
V_9 -> V_352 . V_374 = 0 ;
}
static int F_178 ( struct V_8 * V_9 )
{
struct V_347 * V_352 = & V_9 -> V_375 . V_376 ;
if ( V_9 -> V_375 . V_377 )
return 0 ;
V_352 -> V_353 = V_356 ;
V_352 -> V_355 = V_356 ;
V_352 -> V_374 = V_378 ;
F_179 ( V_9 , F_174 ( V_379 ) ,
& V_352 -> V_372 ) ;
F_179 ( V_9 , F_174 ( V_380 ) ,
& V_352 -> V_373 ) ;
if ( ! V_352 -> V_372 || ! V_352 -> V_373 ) {
F_5 ( V_9 -> V_16 , L_40 ,
V_17 ,
V_352 -> V_372 ,
V_352 -> V_373 ) ;
return - V_114 ;
}
F_179 ( V_9 , F_174 ( V_381 ) , & V_352 -> V_369 ) ;
if ( ! V_352 -> V_369 ) {
F_179 ( V_9 , F_174 ( V_382 ) ,
& V_352 -> V_369 ) ;
if ( ! V_352 -> V_369 ) {
F_5 ( V_9 -> V_16 , L_41 ,
V_17 , V_352 -> V_369 ) ;
return - V_114 ;
}
V_352 -> V_355 = V_358 ;
}
F_180 ( V_9 , F_174 ( V_381 ) ,
& V_352 -> V_371 ) ;
if ( ! V_352 -> V_371 ) {
F_180 ( V_9 , F_174 ( V_382 ) ,
& V_352 -> V_371 ) ;
if ( ! V_352 -> V_371 ) {
F_5 ( V_9 -> V_16 , L_42 ,
V_17 , V_352 -> V_371 ) ;
return - V_114 ;
}
V_352 -> V_353 = V_358 ;
}
V_9 -> V_375 . V_377 = true ;
return 0 ;
}
static int F_169 ( struct V_8 * V_9 ,
struct V_347 * V_383 )
{
int V_10 ;
if ( V_383 -> V_369 == V_9 -> V_352 . V_369 &&
V_383 -> V_371 == V_9 -> V_352 . V_371 &&
V_383 -> V_372 == V_9 -> V_352 . V_372 &&
V_383 -> V_373 == V_9 -> V_352 . V_373 &&
V_383 -> V_355 == V_9 -> V_352 . V_355 &&
V_383 -> V_353 == V_9 -> V_352 . V_353 &&
V_383 -> V_374 == V_9 -> V_352 . V_374 ) {
F_181 ( V_9 -> V_16 , L_43 , V_17 ) ;
return 0 ;
}
F_172 ( V_9 , F_174 ( V_384 ) , V_383 -> V_369 ) ;
F_172 ( V_9 , F_174 ( V_385 ) ,
V_383 -> V_372 ) ;
if ( V_383 -> V_355 == V_356 ||
V_383 -> V_355 == V_354 )
F_172 ( V_9 , F_174 ( V_386 ) , TRUE ) ;
else
F_172 ( V_9 , F_174 ( V_386 ) , FALSE ) ;
F_172 ( V_9 , F_174 ( V_387 ) , V_383 -> V_371 ) ;
F_172 ( V_9 , F_174 ( V_388 ) ,
V_383 -> V_373 ) ;
if ( V_383 -> V_353 == V_356 ||
V_383 -> V_353 == V_354 )
F_172 ( V_9 , F_174 ( V_389 ) , TRUE ) ;
else
F_172 ( V_9 , F_174 ( V_389 ) , FALSE ) ;
if ( V_383 -> V_355 == V_356 ||
V_383 -> V_353 == V_356 ||
V_383 -> V_355 == V_354 ||
V_383 -> V_353 == V_354 )
F_172 ( V_9 , F_174 ( V_390 ) ,
V_383 -> V_374 ) ;
V_10 = F_171 ( V_9 , V_383 -> V_355 << 4
| V_383 -> V_353 ) ;
if ( V_10 ) {
F_5 ( V_9 -> V_16 ,
L_44 , V_17 , V_10 ) ;
} else {
if ( V_9 -> V_33 && V_9 -> V_33 -> V_391 )
V_9 -> V_33 -> V_391 ( V_9 ,
V_392 , NULL , V_383 ) ;
memcpy ( & V_9 -> V_352 , V_383 ,
sizeof( struct V_347 ) ) ;
}
return V_10 ;
}
static int F_182 ( struct V_8 * V_9 ,
struct V_347 * V_393 )
{
struct V_347 V_394 = { 0 } ;
int V_10 ;
if ( V_9 -> V_33 && V_9 -> V_33 -> V_391 )
V_9 -> V_33 -> V_391 ( V_9 ,
V_395 , V_393 , & V_394 ) ;
else
memcpy ( & V_394 , V_393 , sizeof( V_394 ) ) ;
V_10 = F_169 ( V_9 , & V_394 ) ;
return V_10 ;
}
static int F_183 ( struct V_8 * V_9 )
{
int V_181 , V_396 , V_23 = 0 ;
bool V_273 = 1 ;
for ( V_396 = V_397 ; V_396 > 0 ; V_396 -- ) {
V_23 = F_147 ( V_9 , V_275 ,
V_398 , NULL ) ;
if ( ! V_23 || V_23 == - V_26 )
break;
F_181 ( V_9 -> V_16 , L_45 , V_17 , V_23 ) ;
}
if ( V_23 ) {
F_5 ( V_9 -> V_16 ,
L_46 ,
V_17 , V_23 ) ;
goto V_48;
}
for ( V_181 = 0 ; V_181 < 100 && ! V_23 && V_273 ; V_181 ++ ) {
for ( V_396 = V_397 ; V_396 > 0 ; V_396 -- ) {
V_23 = F_147 ( V_9 ,
V_279 ,
V_398 , & V_273 ) ;
if ( ! V_23 || V_23 == - V_26 )
break;
F_181 ( V_9 -> V_16 , L_45 , V_17 ,
V_23 ) ;
}
}
if ( V_23 )
F_5 ( V_9 -> V_16 ,
L_47 ,
V_17 , V_23 ) ;
else if ( V_273 )
F_5 ( V_9 -> V_16 ,
L_48 ,
V_17 ) ;
V_48:
return V_23 ;
}
static int F_184 ( struct V_8 * V_9 )
{
int V_23 = 0 ;
T_1 V_18 ;
F_117 ( V_9 , V_399 ) ;
if ( F_133 ( V_9 ) )
F_35 ( V_9 , V_9 -> V_157 - 1 , V_400 ) ;
else
F_38 ( V_9 ) ;
F_25 ( V_9 , F_115 ( V_9 -> V_317 ) ,
V_401 ) ;
F_25 ( V_9 , F_116 ( V_9 -> V_317 ) ,
V_402 ) ;
F_25 ( V_9 , F_115 ( V_9 -> V_319 ) ,
V_403 ) ;
F_25 ( V_9 , F_116 ( V_9 -> V_319 ) ,
V_404 ) ;
V_18 = F_10 ( V_9 , V_36 ) ;
if ( ! ( F_26 ( V_18 ) ) ) {
F_39 ( V_9 ) ;
} else {
F_5 ( V_9 -> V_16 ,
L_49 ) ;
V_23 = - V_172 ;
goto V_48;
}
V_48:
return V_23 ;
}
static int F_185 ( struct V_8 * V_9 )
{
int V_405 ;
if ( ! F_41 ( V_9 ) ) {
F_186 ( V_9 ) ;
F_187 ( 5 ) ;
}
F_175 ( V_9 ) ;
if ( V_9 -> V_33 && V_9 -> V_33 -> V_406 )
V_9 -> V_33 -> V_406 ( V_9 , V_395 ) ;
F_40 ( V_9 ) ;
F_187 ( 1 ) ;
V_405 = 10 ;
while ( F_41 ( V_9 ) ) {
if ( V_405 ) {
V_405 -- ;
} else {
F_5 ( V_9 -> V_16 ,
L_50 ) ;
return - V_172 ;
}
F_187 ( 5 ) ;
}
F_117 ( V_9 , V_407 ) ;
if ( V_9 -> V_33 && V_9 -> V_33 -> V_406 )
V_9 -> V_33 -> V_406 ( V_9 , V_392 ) ;
return 0 ;
}
static int F_188 ( struct V_8 * V_9 , bool V_342 )
{
int V_408 , V_181 , V_23 = 0 ;
if ( ! V_342 )
F_179 ( V_9 , F_174 ( V_380 ) ,
& V_408 ) ;
else
F_180 ( V_9 , F_174 ( V_380 ) ,
& V_408 ) ;
for ( V_181 = 0 ; V_181 < V_408 ; V_181 ++ ) {
if ( ! V_342 )
V_23 = F_172 ( V_9 ,
F_173 ( V_409 ,
F_189 ( V_181 ) ) ,
0 ) ;
else
V_23 = F_190 ( V_9 ,
F_173 ( V_409 ,
F_189 ( V_181 ) ) ,
0 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_51 ,
V_17 , V_342 , V_181 , V_23 ) ;
break;
}
}
return V_23 ;
}
static inline int F_191 ( struct V_8 * V_9 )
{
return F_188 ( V_9 , true ) ;
}
static int F_192 ( struct V_8 * V_9 )
{
int V_10 ;
int V_396 = V_410 ;
do {
if ( V_9 -> V_33 && V_9 -> V_33 -> V_411 )
V_9 -> V_33 -> V_411 ( V_9 , V_395 ) ;
V_10 = F_163 ( V_9 ) ;
if ( ! V_10 && ! F_15 ( V_9 ) ) {
F_5 ( V_9 -> V_16 , L_52 , V_17 ) ;
V_10 = - V_412 ;
goto V_48;
}
if ( V_10 && F_185 ( V_9 ) )
goto V_48;
} while ( V_10 && V_396 -- );
if ( V_10 )
goto V_48;
if ( V_9 -> V_31 & V_413 ) {
V_10 = F_191 ( V_9 ) ;
if ( V_10 )
goto V_48;
}
if ( V_9 -> V_33 && V_9 -> V_33 -> V_411 ) {
V_10 = V_9 -> V_33 -> V_411 ( V_9 , V_392 ) ;
if ( V_10 )
goto V_48;
}
V_10 = F_184 ( V_9 ) ;
V_48:
if ( V_10 )
F_5 ( V_9 -> V_16 , L_53 , V_10 ) ;
return V_10 ;
}
static int F_193 ( struct V_8 * V_9 )
{
int V_23 = 0 ;
int V_396 ;
F_55 ( V_9 , false ) ;
F_106 ( & V_9 -> V_138 . V_274 ) ;
for ( V_396 = V_414 ; V_396 > 0 ; V_396 -- ) {
V_23 = F_142 ( V_9 , V_232 ,
V_415 ) ;
if ( ! V_23 || V_23 == - V_26 )
break;
F_181 ( V_9 -> V_16 , L_45 , V_17 , V_23 ) ;
}
F_108 ( & V_9 -> V_138 . V_274 ) ;
F_69 ( V_9 ) ;
if ( V_23 )
F_5 ( V_9 -> V_16 , L_54 , V_17 , V_23 ) ;
return V_23 ;
}
static void F_194 ( struct V_416 * V_417 )
{
int V_10 = 0 ;
T_2 V_418 ;
struct V_8 * V_9 ;
V_9 = F_130 ( V_417 -> V_82 ) ;
V_418 = V_9 -> V_157 ;
V_10 = F_157 ( V_9 ,
F_126 ( V_417 -> V_215 ) ,
V_419 ,
& V_418 ,
sizeof( V_418 ) ) ;
if ( V_10 == - V_308 )
V_418 = 1 ;
else if ( ! V_418 )
V_418 = V_9 -> V_157 ;
else
V_418 = F_92 ( int , V_418 , V_9 -> V_157 ) ;
F_181 ( V_9 -> V_16 , L_55 ,
V_17 , V_418 ) ;
F_195 ( V_417 , V_418 ) ;
}
static int F_196 ( struct V_8 * V_9 ,
T_2 V_215 ,
T_2 * V_420 )
{
int V_10 ;
if ( ! V_420 )
V_10 = - V_114 ;
else if ( V_215 >= V_307 )
V_10 = - V_234 ;
else
V_10 = F_157 ( V_9 ,
V_215 ,
V_421 ,
V_420 ,
sizeof( * V_420 ) ) ;
return V_10 ;
}
static inline void F_197 ( struct V_8 * V_9 ,
struct V_416 * V_417 )
{
if ( V_9 -> V_422 . V_423 &&
! V_9 -> V_422 . V_424 ) {
T_2 V_420 ;
if ( ! F_196 ( V_9 , F_126 ( V_417 -> V_215 ) ,
& V_420 ) &&
( V_420 == V_425 ) )
V_9 -> V_422 . V_424 = true ;
}
}
static int F_198 ( struct V_416 * V_417 )
{
struct V_8 * V_9 ;
V_9 = F_130 ( V_417 -> V_82 ) ;
V_417 -> V_426 = 1 ;
V_417 -> V_427 = 1 ;
V_417 -> V_428 = 1 ;
F_194 ( V_417 ) ;
F_197 ( V_9 , V_417 ) ;
return 0 ;
}
static int F_199 ( struct V_416 * V_417 , int V_429 )
{
struct V_8 * V_9 = F_130 ( V_417 -> V_82 ) ;
if ( V_429 > V_9 -> V_157 )
V_429 = V_9 -> V_157 ;
return F_195 ( V_417 , V_429 ) ;
}
static int F_200 ( struct V_416 * V_417 )
{
struct V_430 * V_431 = V_417 -> V_430 ;
F_201 ( V_431 , V_432 - 1 ) ;
F_202 ( V_431 , V_433 ) ;
return 0 ;
}
static void F_203 ( struct V_416 * V_417 )
{
struct V_8 * V_9 ;
V_9 = F_130 ( V_417 -> V_82 ) ;
if ( F_126 ( V_417 -> V_215 ) == V_434 ) {
unsigned long V_78 ;
F_45 ( V_9 -> V_82 -> V_83 , V_78 ) ;
V_9 -> V_435 = NULL ;
F_46 ( V_9 -> V_82 -> V_83 , V_78 ) ;
}
}
static int F_204 ( struct V_8 * V_9 , T_1 V_270 , T_2 * V_253 )
{
struct V_44 * V_45 ;
struct V_436 * V_437 ;
unsigned long V_78 ;
int V_438 ;
int V_439 ;
F_45 ( V_9 -> V_82 -> V_83 , V_78 ) ;
F_205 ( V_270 , & V_9 -> V_101 ) ;
V_45 = V_9 -> V_318 ;
V_438 = F_18 ( & V_45 [ V_270 ] ) ;
if ( V_438 == V_440 ) {
V_437 = (struct V_436 * )
V_45 [ V_270 ] . V_441 ;
V_439 = F_30 ( V_437 -> V_41 . V_60 ) ;
V_439 = ( ( V_439 & V_442 ) >> 8 ) ;
if ( V_253 )
* V_253 = ( T_2 ) V_439 ;
} else {
F_5 ( V_9 -> V_16 , L_56 ,
V_17 , V_438 ) ;
}
F_46 ( V_9 -> V_82 -> V_83 , V_78 ) ;
return V_438 ;
}
static inline int
F_206 ( struct V_38 * V_39 , int V_443 )
{
int V_444 = 0 ;
switch ( V_443 ) {
case V_445 :
F_90 ( V_39 ) ;
case V_446 :
V_444 |= V_447 << 16 |
V_448 << 8 |
V_443 ;
break;
case V_449 :
case V_450 :
case V_451 :
F_90 ( V_39 ) ;
V_444 |= V_443 ;
break;
default:
V_444 |= V_245 << 16 ;
break;
}
return V_444 ;
}
static inline int
F_207 ( struct V_8 * V_9 , struct V_38 * V_39 )
{
int V_444 = 0 ;
int V_443 ;
int V_452 ;
V_452 = F_16 ( V_39 ) ;
switch ( V_452 ) {
case V_440 :
V_444 = F_29 ( V_39 -> V_58 ) ;
switch ( V_444 ) {
case V_453 :
V_444 = F_31 ( V_39 -> V_58 ) ;
V_443 = V_444 & V_454 ;
V_444 = F_206 ( V_39 , V_443 ) ;
if ( F_33 ( V_39 -> V_58 ) )
F_59 ( & V_9 -> V_455 ) ;
break;
case V_256 :
V_444 = V_245 << 16 ;
F_5 ( V_9 -> V_16 ,
L_57 ) ;
break;
default:
V_444 = V_245 << 16 ;
F_5 ( V_9 -> V_16 ,
L_58 ,
V_444 ) ;
break;
}
break;
case V_456 :
V_444 |= V_457 << 16 ;
break;
case V_211 :
V_444 |= V_458 << 16 ;
break;
case V_459 :
case V_460 :
case V_461 :
case V_462 :
case V_463 :
case V_464 :
default:
V_444 |= V_245 << 16 ;
F_5 ( V_9 -> V_16 ,
L_59 , V_452 ) ;
break;
}
return V_444 ;
}
static void F_208 ( struct V_8 * V_9 , T_1 V_465 )
{
if ( ( V_465 & V_466 ) && V_9 -> V_102 ) {
V_9 -> V_102 -> V_165 |=
F_27 ( V_9 ) ;
V_9 -> V_102 -> V_166 =
F_28 ( V_9 ) ;
V_260 ( & V_9 -> V_102 -> V_170 ) ;
}
if ( ( V_465 & V_467 ) && V_9 -> V_103 )
V_260 ( V_9 -> V_103 ) ;
}
static void F_209 ( struct V_8 * V_9 )
{
struct V_38 * V_39 ;
struct V_178 * V_179 ;
unsigned long V_468 ;
T_1 V_469 ;
int V_444 ;
int V_270 ;
if ( F_133 ( V_9 ) )
F_34 ( V_9 ) ;
V_469 = F_10 ( V_9 , V_129 ) ;
V_468 = V_469 ^ V_9 -> V_126 ;
F_210 (index, &completed_reqs, hba->nutrs) {
V_39 = & V_9 -> V_248 [ V_270 ] ;
V_179 = V_39 -> V_179 ;
if ( V_179 ) {
V_444 = F_207 ( V_9 , V_39 ) ;
F_211 ( V_179 ) ;
V_179 -> V_444 = V_444 ;
V_39 -> V_179 = NULL ;
F_23 ( V_270 , & V_9 -> V_100 ) ;
V_179 -> V_246 ( V_179 ) ;
F_67 ( V_9 ) ;
} else if ( V_39 -> V_207 == V_229 ) {
if ( V_9 -> V_138 . V_260 )
V_260 ( V_9 -> V_138 . V_260 ) ;
}
}
V_9 -> V_126 ^= V_468 ;
F_84 ( V_9 ) ;
F_145 ( & V_9 -> V_138 . V_265 ) ;
}
static int F_212 ( struct V_8 * V_9 , T_5 V_19 )
{
int V_23 = 0 ;
T_1 V_20 ;
if ( ! ( V_9 -> V_470 & V_19 ) )
goto V_48;
V_20 = V_9 -> V_470 & ~ V_19 ;
V_20 &= 0xFFFF ;
V_23 = F_149 ( V_9 , V_285 ,
V_471 , 0 , 0 , & V_20 ) ;
if ( ! V_23 )
V_9 -> V_470 &= ~ V_19 ;
V_48:
return V_23 ;
}
static int F_213 ( struct V_8 * V_9 , T_5 V_19 )
{
int V_23 = 0 ;
T_1 V_20 ;
if ( V_9 -> V_470 & V_19 )
goto V_48;
V_20 = V_9 -> V_470 | V_19 ;
V_20 &= 0xFFFF ;
V_23 = F_149 ( V_9 , V_285 ,
V_471 , 0 , 0 , & V_20 ) ;
if ( ! V_23 )
V_9 -> V_470 |= V_19 ;
V_48:
return V_23 ;
}
static int F_214 ( struct V_8 * V_9 )
{
int V_23 = 0 ;
if ( V_9 -> V_472 )
goto V_48;
V_23 = F_147 ( V_9 , V_275 ,
V_473 , NULL ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_60 ,
V_17 , V_23 ) ;
goto V_48;
}
V_9 -> V_472 = true ;
V_23 = F_212 ( V_9 , V_474 ) ;
if ( V_23 )
F_5 ( V_9 -> V_16 , L_61 ,
V_17 , V_23 ) ;
V_48:
return V_23 ;
}
static int F_215 ( struct V_8 * V_9 )
{
int V_23 = 0 ;
if ( ! V_9 -> V_472 )
goto V_48;
V_23 = F_213 ( V_9 , V_474 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_62 ,
V_17 , V_23 ) ;
goto V_48;
}
V_23 = F_147 ( V_9 , V_276 ,
V_473 , NULL ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_63 ,
V_17 , V_23 ) ;
F_212 ( V_9 , V_474 ) ;
goto V_48;
}
V_9 -> V_472 = false ;
V_48:
return V_23 ;
}
static void F_216 ( struct V_8 * V_9 )
{
V_9 -> V_472 = false ;
V_9 -> V_470 |= V_474 ;
F_214 ( V_9 ) ;
}
static inline int F_217 ( struct V_8 * V_9 , T_1 * V_361 )
{
return F_149 ( V_9 , V_286 ,
V_475 , 0 , 0 , V_361 ) ;
}
static int F_218 ( struct V_8 * V_9 ,
enum V_476 V_361 )
{
int V_23 ;
T_1 V_477 = 0 ;
V_23 = F_217 ( V_9 , & V_477 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_64 ,
V_17 , V_23 ) ;
goto V_48;
} else if ( V_477 > V_478 ) {
F_5 ( V_9 -> V_16 , L_65 ,
V_17 , V_477 ) ;
V_23 = - V_114 ;
goto V_48;
}
if ( V_477 >= V_361 )
V_23 = F_214 ( V_9 ) ;
else
V_23 = F_215 ( V_9 ) ;
V_48:
return V_23 ;
}
static int F_219 ( struct V_8 * V_9 )
{
return F_218 ( V_9 , V_479 ) ;
}
static inline int F_220 ( struct V_8 * V_9 , T_1 * V_361 )
{
return F_149 ( V_9 , V_286 ,
V_480 , 0 , 0 , V_361 ) ;
}
static void F_221 ( struct V_76 * V_77 )
{
struct V_8 * V_9 ;
int V_23 ;
T_1 V_361 = 0 ;
V_9 = F_43 ( V_77 , struct V_8 , V_455 ) ;
F_222 ( V_9 -> V_16 ) ;
V_23 = F_220 ( V_9 , & V_361 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_66 ,
V_17 , V_23 ) ;
goto V_48;
}
V_361 &= V_9 -> V_470 ;
if ( V_361 & V_474 ) {
V_23 = F_219 ( V_9 ) ;
if ( V_23 < 0 )
F_5 ( V_9 -> V_16 , L_67 ,
V_17 , V_23 ) ;
}
V_48:
F_223 ( V_9 -> V_16 ) ;
return;
}
static void F_224 ( struct V_76 * V_77 )
{
struct V_8 * V_9 ;
unsigned long V_78 ;
T_1 V_481 = 0 ;
T_1 V_482 = 0 ;
int V_23 = 0 ;
int V_47 ;
V_9 = F_43 ( V_77 , struct V_8 , V_483 ) ;
F_222 ( V_9 -> V_16 ) ;
F_55 ( V_9 , false ) ;
F_45 ( V_9 -> V_82 -> V_83 , V_78 ) ;
if ( V_9 -> V_98 == V_241 ) {
F_46 ( V_9 -> V_82 -> V_83 , V_78 ) ;
goto V_48;
}
V_9 -> V_98 = V_241 ;
F_225 ( V_9 ) ;
F_209 ( V_9 ) ;
F_226 ( V_9 ) ;
F_46 ( V_9 -> V_82 -> V_83 , V_78 ) ;
F_210 (tag, &hba->outstanding_reqs, hba->nutrs)
if ( F_135 ( V_9 , V_47 ) )
V_481 |= 1 << V_47 ;
F_210 (tag, &hba->outstanding_tasks, hba->nutmrs)
if ( F_227 ( V_9 , V_47 ) )
V_482 |= 1 << V_47 ;
F_45 ( V_9 -> V_82 -> V_83 , V_78 ) ;
F_209 ( V_9 ) ;
F_226 ( V_9 ) ;
F_46 ( V_9 -> V_82 -> V_83 , V_78 ) ;
if ( V_481 || V_482 || ( V_9 -> V_484 & V_485 ) ||
( ( V_9 -> V_484 & V_486 ) &&
( V_9 -> V_487 & V_488 ) ) ) {
V_23 = F_228 ( V_9 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_68 ,
V_17 ) ;
V_9 -> V_98 = V_244 ;
}
F_229 ( V_9 -> V_82 , 0 ) ;
V_9 -> V_484 = 0 ;
V_9 -> V_487 = 0 ;
}
F_230 ( V_9 ) ;
V_48:
F_54 ( V_9 -> V_82 ) ;
F_69 ( V_9 ) ;
F_223 ( V_9 -> V_16 ) ;
}
static void F_231 ( struct V_8 * V_9 )
{
T_1 V_18 ;
V_18 = F_10 ( V_9 , V_489 ) ;
if ( V_18 & V_490 )
V_9 -> V_491 |= V_488 ;
V_18 = F_10 ( V_9 , V_492 ) ;
if ( V_18 )
V_9 -> V_491 |= V_493 ;
V_18 = F_10 ( V_9 , V_494 ) ;
if ( V_18 )
V_9 -> V_491 |= V_495 ;
V_18 = F_10 ( V_9 , V_496 ) ;
if ( V_18 )
V_9 -> V_491 |= V_497 ;
F_181 ( V_9 -> V_16 , L_69 ,
V_17 , V_9 -> V_491 ) ;
}
static void F_232 ( struct V_8 * V_9 )
{
bool V_498 = false ;
if ( V_9 -> V_499 & V_485 )
V_498 = true ;
if ( V_9 -> V_499 & V_486 ) {
V_9 -> V_491 = 0 ;
F_231 ( V_9 ) ;
if ( V_9 -> V_491 )
V_498 = true ;
}
if ( V_498 ) {
if ( V_9 -> V_98 == V_99 ) {
F_58 ( V_9 -> V_82 ) ;
V_9 -> V_484 |= V_9 -> V_499 ;
V_9 -> V_487 |= V_9 -> V_491 ;
V_9 -> V_98 = V_244 ;
F_59 ( & V_9 -> V_483 ) ;
}
}
}
static void F_226 ( struct V_8 * V_9 )
{
T_1 V_500 ;
V_500 = F_10 ( V_9 , V_501 ) ;
V_9 -> V_502 = V_500 ^ V_9 -> V_101 ;
F_145 ( & V_9 -> V_503 ) ;
}
static void F_233 ( struct V_8 * V_9 , T_1 V_465 )
{
V_9 -> V_499 = V_504 & V_465 ;
if ( V_9 -> V_499 )
F_232 ( V_9 ) ;
if ( V_465 & V_407 )
F_208 ( V_9 , V_465 ) ;
if ( V_465 & V_505 )
F_226 ( V_9 ) ;
if ( V_465 & V_506 )
F_209 ( V_9 ) ;
}
static T_7 V_13 ( int V_12 , void * V_507 )
{
T_1 V_465 ;
T_7 V_508 = V_509 ;
struct V_8 * V_9 = V_507 ;
F_234 ( V_9 -> V_82 -> V_83 ) ;
V_465 = F_10 ( V_9 , V_510 ) ;
if ( V_465 ) {
F_25 ( V_9 , V_465 , V_510 ) ;
F_233 ( V_9 , V_465 ) ;
V_508 = V_511 ;
}
F_235 ( V_9 -> V_82 -> V_83 ) ;
return V_508 ;
}
static int F_227 ( struct V_8 * V_9 , int V_47 )
{
int V_23 = 0 ;
T_1 V_19 = 1 << V_47 ;
unsigned long V_78 ;
if ( ! F_236 ( V_47 , & V_9 -> V_101 ) )
goto V_48;
F_45 ( V_9 -> V_82 -> V_83 , V_78 ) ;
F_25 ( V_9 , ~ ( 1 << V_47 ) , V_512 ) ;
F_46 ( V_9 -> V_82 -> V_83 , V_78 ) ;
V_23 = F_8 ( V_9 ,
V_501 ,
V_19 , 0 , 1000 , 1000 ) ;
V_48:
return V_23 ;
}
static int F_237 ( struct V_8 * V_9 , int V_513 , int V_514 ,
T_2 V_515 , T_2 * V_516 )
{
struct V_44 * V_45 ;
struct V_517 * V_518 ;
struct V_240 * V_82 ;
unsigned long V_78 ;
int V_46 ;
int V_23 ;
int V_128 ;
V_82 = V_9 -> V_82 ;
F_143 ( V_9 -> V_519 , F_19 ( V_9 , & V_46 ) ) ;
F_55 ( V_9 , false ) ;
F_45 ( V_82 -> V_83 , V_78 ) ;
V_45 = V_9 -> V_318 ;
V_45 += V_46 ;
V_45 -> V_41 . V_59 = F_113 ( V_210 ) ;
V_45 -> V_41 . V_42 =
F_113 ( V_211 ) ;
V_518 =
(struct V_517 * ) V_45 -> V_520 ;
V_128 = V_9 -> V_157 + V_46 ;
V_518 -> V_41 . V_59 =
F_121 ( V_521 , 0 ,
V_513 , V_128 ) ;
V_518 -> V_41 . V_60 =
F_121 ( 0 , V_515 , 0 , 0 ) ;
V_518 -> V_522 = F_122 ( V_513 ) ;
V_518 -> V_523 = F_122 ( V_514 ) ;
F_89 ( V_46 , & V_9 -> V_101 ) ;
F_25 ( V_9 , 1 << V_46 , V_501 ) ;
F_46 ( V_82 -> V_83 , V_78 ) ;
V_23 = F_238 ( V_9 -> V_503 ,
F_236 ( V_46 , & V_9 -> V_502 ) ,
F_9 ( V_524 ) ) ;
if ( ! V_23 ) {
F_5 ( V_9 -> V_16 , L_70 ,
V_17 , V_515 ) ;
if ( F_227 ( V_9 , V_46 ) )
F_239 ( V_9 -> V_16 , L_71 ,
V_17 , V_46 ) ;
V_23 = - V_26 ;
} else {
V_23 = F_204 ( V_9 , V_46 , V_516 ) ;
}
F_240 ( V_46 , & V_9 -> V_502 ) ;
F_22 ( V_9 , V_46 ) ;
F_145 ( & V_9 -> V_519 ) ;
F_69 ( V_9 ) ;
return V_23 ;
}
static int F_241 ( struct V_178 * V_179 )
{
struct V_240 * V_82 ;
struct V_8 * V_9 ;
unsigned int V_47 ;
T_1 V_52 ;
int V_23 ;
T_2 V_253 = 0xF ;
struct V_38 * V_39 ;
unsigned long V_78 ;
V_82 = V_179 -> V_107 -> V_82 ;
V_9 = F_130 ( V_82 ) ;
V_47 = V_179 -> V_151 -> V_47 ;
V_39 = & V_9 -> V_248 [ V_47 ] ;
V_23 = F_237 ( V_9 , V_39 -> V_215 , 0 , V_525 , & V_253 ) ;
if ( V_23 || V_253 != V_526 ) {
if ( ! V_23 )
V_23 = V_253 ;
goto V_48;
}
F_210 (pos, &hba->outstanding_reqs, hba->nutrs) {
if ( V_9 -> V_248 [ V_52 ] . V_215 == V_39 -> V_215 ) {
V_23 = F_135 ( V_9 , V_52 ) ;
if ( V_23 )
break;
}
}
F_45 ( V_82 -> V_83 , V_78 ) ;
F_209 ( V_9 ) ;
F_46 ( V_82 -> V_83 , V_78 ) ;
V_48:
if ( ! V_23 ) {
V_23 = V_527 ;
} else {
F_5 ( V_9 -> V_16 , L_72 , V_17 , V_23 ) ;
V_23 = V_528 ;
}
return V_23 ;
}
static int F_242 ( struct V_178 * V_179 )
{
struct V_240 * V_82 ;
struct V_8 * V_9 ;
unsigned long V_78 ;
unsigned int V_47 ;
int V_23 = 0 ;
int V_529 ;
T_2 V_253 = 0xF ;
struct V_38 * V_39 ;
T_1 V_18 ;
V_82 = V_179 -> V_107 -> V_82 ;
V_9 = F_130 ( V_82 ) ;
V_47 = V_179 -> V_151 -> V_47 ;
F_55 ( V_9 , false ) ;
if ( ! ( F_236 ( V_47 , & V_9 -> V_126 ) ) )
goto V_48;
V_18 = F_10 ( V_9 , V_129 ) ;
if ( ! ( V_18 & ( 1 << V_47 ) ) ) {
F_5 ( V_9 -> V_16 ,
L_73 ,
V_17 , V_47 ) ;
}
V_39 = & V_9 -> V_248 [ V_47 ] ;
for ( V_529 = 100 ; V_529 ; V_529 -- ) {
V_23 = F_237 ( V_9 , V_39 -> V_215 , V_39 -> V_128 ,
V_530 , & V_253 ) ;
if ( ! V_23 && V_253 == V_531 ) {
break;
} else if ( ! V_23 && V_253 == V_526 ) {
V_18 = F_10 ( V_9 , V_129 ) ;
if ( V_18 & ( 1 << V_47 ) ) {
F_11 ( 100 , 200 ) ;
continue;
}
goto V_48;
} else {
if ( ! V_23 )
V_23 = V_253 ;
goto V_48;
}
}
if ( ! V_529 ) {
V_23 = - V_532 ;
goto V_48;
}
V_23 = F_237 ( V_9 , V_39 -> V_215 , V_39 -> V_128 ,
V_533 , & V_253 ) ;
if ( V_23 || V_253 != V_526 ) {
if ( ! V_23 )
V_23 = V_253 ;
goto V_48;
}
V_23 = F_135 ( V_9 , V_47 ) ;
if ( V_23 )
goto V_48;
F_211 ( V_179 ) ;
F_45 ( V_82 -> V_83 , V_78 ) ;
F_205 ( V_47 , & V_9 -> V_126 ) ;
V_9 -> V_248 [ V_47 ] . V_179 = NULL ;
F_46 ( V_82 -> V_83 , V_78 ) ;
F_23 ( V_47 , & V_9 -> V_100 ) ;
F_145 ( & V_9 -> V_138 . V_265 ) ;
V_48:
if ( ! V_23 ) {
V_23 = V_527 ;
} else {
F_5 ( V_9 -> V_16 , L_72 , V_17 , V_23 ) ;
V_23 = V_528 ;
}
F_69 ( V_9 ) ;
return V_23 ;
}
static int F_176 ( struct V_8 * V_9 )
{
int V_23 ;
unsigned long V_78 ;
F_45 ( V_9 -> V_82 -> V_83 , V_78 ) ;
F_186 ( V_9 ) ;
F_46 ( V_9 -> V_82 -> V_83 , V_78 ) ;
V_23 = F_185 ( V_9 ) ;
if ( V_23 )
goto V_48;
V_23 = F_243 ( V_9 ) ;
if ( ! V_23 && ( V_9 -> V_98 != V_99 ) )
V_23 = - V_172 ;
V_48:
if ( V_23 )
F_5 ( V_9 -> V_16 , L_74 , V_17 , V_23 ) ;
return V_23 ;
}
static int F_228 ( struct V_8 * V_9 )
{
int V_23 = 0 ;
unsigned long V_78 ;
int V_396 = V_534 ;
do {
V_23 = F_176 ( V_9 ) ;
} while ( V_23 && -- V_396 );
F_45 ( V_9 -> V_82 -> V_83 , V_78 ) ;
F_209 ( V_9 ) ;
F_226 ( V_9 ) ;
F_46 ( V_9 -> V_82 -> V_83 , V_78 ) ;
return V_23 ;
}
static int F_244 ( struct V_178 * V_179 )
{
int V_23 ;
unsigned long V_78 ;
struct V_8 * V_9 ;
V_9 = F_130 ( V_179 -> V_107 -> V_82 ) ;
F_55 ( V_9 , false ) ;
do {
F_45 ( V_9 -> V_82 -> V_83 , V_78 ) ;
if ( ! ( F_245 ( & V_9 -> V_483 ) ||
V_9 -> V_98 == V_241 ) )
break;
F_46 ( V_9 -> V_82 -> V_83 , V_78 ) ;
F_181 ( V_9 -> V_16 , L_75 , V_17 ) ;
F_60 ( & V_9 -> V_483 ) ;
} while ( 1 );
V_9 -> V_98 = V_241 ;
F_225 ( V_9 ) ;
F_46 ( V_9 -> V_82 -> V_83 , V_78 ) ;
V_23 = F_228 ( V_9 ) ;
F_45 ( V_9 -> V_82 -> V_83 , V_78 ) ;
if ( ! V_23 ) {
V_23 = V_527 ;
V_9 -> V_98 = V_99 ;
} else {
V_23 = V_528 ;
V_9 -> V_98 = V_244 ;
}
F_230 ( V_9 ) ;
F_46 ( V_9 -> V_82 -> V_83 , V_78 ) ;
F_69 ( V_9 ) ;
return V_23 ;
}
static T_1 F_246 ( int V_535 , T_1 V_536 , char * V_537 )
{
int V_181 ;
int V_538 ;
T_5 V_539 ;
T_5 V_540 ;
for ( V_181 = V_536 ; V_181 >= 0 ; V_181 -- ) {
V_539 = F_91 ( * ( ( T_5 * ) ( V_537 + 2 * V_181 ) ) ) ;
V_540 = ( V_539 & V_541 ) >>
V_542 ;
V_538 = V_539 & V_543 ;
switch ( V_540 ) {
case V_544 :
V_538 = V_538 / 1000 ;
break;
case V_545 :
V_538 = V_538 * 1000 ;
break;
case V_546 :
V_538 = V_538 * 1000 * 1000 ;
break;
case V_547 :
default:
break;
}
if ( V_535 >= V_538 )
break;
}
if ( V_181 < 0 ) {
V_181 = 0 ;
F_247 ( L_76 , V_17 , V_181 ) ;
}
return ( T_1 ) V_181 ;
}
static T_1 F_248 ( struct V_8 * V_9 ,
T_2 * V_288 , int V_130 )
{
T_1 V_548 = 0 ;
if ( ! V_9 -> V_549 . V_550 || ! V_9 -> V_549 . V_551 ||
! V_9 -> V_549 . V_552 ) {
F_5 ( V_9 -> V_16 ,
L_77 ,
V_17 , V_548 ) ;
goto V_48;
}
if ( V_9 -> V_549 . V_550 )
V_548 = F_246 (
V_9 -> V_549 . V_550 -> V_553 ,
V_554 - 1 ,
& V_288 [ V_555 ] ) ;
if ( V_9 -> V_549 . V_551 )
V_548 = F_246 (
V_9 -> V_549 . V_551 -> V_553 ,
V_548 ,
& V_288 [ V_556 ] ) ;
if ( V_9 -> V_549 . V_552 )
V_548 = F_246 (
V_9 -> V_549 . V_552 -> V_553 ,
V_548 ,
& V_288 [ V_557 ] ) ;
V_48:
return V_548 ;
}
static void F_249 ( struct V_8 * V_9 )
{
int V_10 ;
int V_296 = V_558 ;
T_2 V_288 [ V_558 ] ;
V_10 = F_156 ( V_9 , V_288 , V_296 ) ;
if ( V_10 ) {
F_5 ( V_9 -> V_16 ,
L_78 ,
V_17 , V_296 , V_10 ) ;
return;
}
V_9 -> V_559 . V_548 =
F_248 ( V_9 ,
V_288 , V_296 ) ;
F_181 ( V_9 -> V_16 , L_79 ,
V_17 , V_9 -> V_559 . V_548 ) ;
V_10 = F_149 ( V_9 , V_285 ,
V_560 , 0 , 0 ,
& V_9 -> V_559 . V_548 ) ;
if ( V_10 )
F_5 ( V_9 -> V_16 ,
L_80 ,
V_17 , V_9 -> V_559 . V_548 , V_10 ) ;
}
static int F_250 ( struct V_8 * V_9 )
{
int V_10 = 0 ;
struct V_416 * V_561 ;
struct V_416 * V_562 ;
V_9 -> V_435 = F_251 ( V_9 -> V_82 , 0 , 0 ,
F_128 ( V_434 ) , NULL ) ;
if ( F_252 ( V_9 -> V_435 ) ) {
V_10 = F_253 ( V_9 -> V_435 ) ;
V_9 -> V_435 = NULL ;
goto V_48;
}
F_254 ( V_9 -> V_435 ) ;
V_562 = F_251 ( V_9 -> V_82 , 0 , 0 ,
F_128 ( V_563 ) , NULL ) ;
if ( F_252 ( V_562 ) ) {
V_10 = F_253 ( V_562 ) ;
goto V_564;
}
F_254 ( V_562 ) ;
V_561 = F_251 ( V_9 -> V_82 , 0 , 0 ,
F_128 ( V_306 ) , NULL ) ;
if ( F_252 ( V_561 ) ) {
V_10 = F_253 ( V_561 ) ;
goto V_565;
}
F_254 ( V_561 ) ;
goto V_48;
V_565:
F_255 ( V_562 ) ;
V_564:
F_255 ( V_9 -> V_435 ) ;
V_48:
return V_10 ;
}
static int F_243 ( struct V_8 * V_9 )
{
int V_10 ;
V_10 = F_192 ( V_9 ) ;
if ( V_10 )
goto V_48;
F_177 ( V_9 ) ;
F_51 ( V_9 ) ;
V_10 = F_193 ( V_9 ) ;
if ( V_10 )
goto V_48;
V_10 = F_183 ( V_9 ) ;
if ( V_10 )
goto V_48;
F_256 ( V_9 ) ;
F_216 ( V_9 ) ;
V_9 -> V_98 = V_99 ;
V_9 -> V_566 = true ;
if ( F_178 ( V_9 ) ) {
F_5 ( V_9 -> V_16 ,
L_81 ,
V_17 ) ;
} else {
V_10 = F_182 ( V_9 , & V_9 -> V_375 . V_376 ) ;
if ( V_10 )
F_5 ( V_9 -> V_16 , L_82 ,
V_17 , V_10 ) ;
}
if ( ! F_257 ( V_9 ) && ! V_9 -> V_567 ) {
bool V_568 ;
memset ( & V_9 -> V_422 , 0 , sizeof( V_9 -> V_422 ) ) ;
if ( ! F_147 ( V_9 , V_279 ,
V_569 , & V_568 ) )
V_9 -> V_422 . V_423 = V_568 ;
if ( ! V_9 -> V_570 )
F_249 ( V_9 ) ;
if ( F_250 ( V_9 ) )
goto V_48;
F_258 ( V_9 -> V_82 ) ;
F_223 ( V_9 -> V_16 ) ;
}
if ( ! V_9 -> V_570 )
V_9 -> V_570 = true ;
if ( F_52 ( V_9 ) )
F_53 ( V_9 -> V_88 ) ;
V_48:
if ( V_10 && ! F_257 ( V_9 ) && ! V_9 -> V_567 ) {
F_223 ( V_9 -> V_16 ) ;
F_259 ( V_9 ) ;
}
return V_10 ;
}
static void F_260 ( void * V_539 , T_8 V_571 )
{
struct V_8 * V_9 = (struct V_8 * ) V_539 ;
F_243 ( V_9 ) ;
}
static int F_261 ( struct V_107 * V_16 , struct V_572 * V_573 ,
int V_574 )
{
int V_10 ;
if ( ! V_573 )
return 0 ;
V_10 = F_262 ( V_573 -> V_18 , V_574 ) ;
if ( V_10 < 0 ) {
F_5 ( V_16 , L_83 ,
V_17 , V_573 -> V_118 , V_574 , V_10 ) ;
}
return V_10 ;
}
static inline int F_263 ( struct V_8 * V_9 ,
struct V_572 * V_573 )
{
return F_261 ( V_9 -> V_16 , V_573 , V_575 ) ;
}
static inline int F_264 ( struct V_8 * V_9 ,
struct V_572 * V_573 )
{
return F_261 ( V_9 -> V_16 , V_573 , V_573 -> V_553 ) ;
}
static int F_265 ( struct V_107 * V_16 ,
struct V_572 * V_573 , bool V_576 )
{
int V_10 = 0 ;
struct V_577 * V_18 = V_573 -> V_18 ;
const char * V_118 = V_573 -> V_118 ;
int V_578 , V_579 ;
F_148 ( ! V_573 ) ;
if ( F_266 ( V_18 ) > 0 ) {
V_578 = V_576 ? V_573 -> V_578 : 0 ;
V_10 = F_267 ( V_18 , V_578 , V_573 -> V_580 ) ;
if ( V_10 ) {
F_5 ( V_16 , L_84 ,
V_17 , V_118 , V_10 ) ;
goto V_48;
}
V_579 = V_576 ? V_573 -> V_553 : 0 ;
V_10 = F_261 ( V_16 , V_573 , V_579 ) ;
if ( V_10 )
goto V_48;
}
V_48:
return V_10 ;
}
static int F_268 ( struct V_107 * V_16 , struct V_572 * V_573 )
{
int V_10 = 0 ;
if ( ! V_573 || V_573 -> V_581 )
goto V_48;
V_10 = F_265 ( V_16 , V_573 , true ) ;
if ( ! V_10 )
V_10 = F_269 ( V_573 -> V_18 ) ;
if ( ! V_10 )
V_573 -> V_581 = true ;
else
F_5 ( V_16 , L_85 ,
V_17 , V_573 -> V_118 , V_10 ) ;
V_48:
return V_10 ;
}
static int F_270 ( struct V_107 * V_16 , struct V_572 * V_573 )
{
int V_10 = 0 ;
if ( ! V_573 || ! V_573 -> V_581 )
goto V_48;
V_10 = F_271 ( V_573 -> V_18 ) ;
if ( ! V_10 ) {
F_265 ( V_16 , V_573 , false ) ;
V_573 -> V_581 = false ;
} else {
F_5 ( V_16 , L_86 ,
V_17 , V_573 -> V_118 , V_10 ) ;
}
V_48:
return V_10 ;
}
static int F_272 ( struct V_8 * V_9 , bool V_576 )
{
int V_10 = 0 ;
struct V_107 * V_16 = V_9 -> V_16 ;
struct V_582 * V_376 = & V_9 -> V_549 ;
if ( ! V_376 )
goto V_48;
V_10 = F_273 ( V_16 , V_376 -> V_550 , V_576 ) ;
if ( V_10 )
goto V_48;
V_10 = F_273 ( V_16 , V_376 -> V_551 , V_576 ) ;
if ( V_10 )
goto V_48;
V_10 = F_273 ( V_16 , V_376 -> V_552 , V_576 ) ;
if ( V_10 )
goto V_48;
V_48:
if ( V_10 ) {
F_273 ( V_16 , V_376 -> V_552 , false ) ;
F_273 ( V_16 , V_376 -> V_551 , false ) ;
F_273 ( V_16 , V_376 -> V_550 , false ) ;
}
return V_10 ;
}
static int F_274 ( struct V_8 * V_9 , bool V_576 )
{
struct V_582 * V_376 = & V_9 -> V_549 ;
if ( V_376 )
return F_273 ( V_9 -> V_16 , V_376 -> V_583 , V_576 ) ;
return 0 ;
}
static int F_275 ( struct V_107 * V_16 , struct V_572 * V_573 )
{
int V_10 = 0 ;
if ( ! V_573 )
goto V_48;
V_573 -> V_18 = F_276 ( V_16 , V_573 -> V_118 ) ;
if ( F_252 ( V_573 -> V_18 ) ) {
V_10 = F_253 ( V_573 -> V_18 ) ;
F_5 ( V_16 , L_87 ,
V_17 , V_573 -> V_118 , V_10 ) ;
}
V_48:
return V_10 ;
}
static int F_277 ( struct V_8 * V_9 )
{
int V_10 = 0 ;
struct V_107 * V_16 = V_9 -> V_16 ;
struct V_582 * V_376 = & V_9 -> V_549 ;
if ( ! V_376 )
goto V_48;
V_10 = F_275 ( V_16 , V_376 -> V_550 ) ;
if ( V_10 )
goto V_48;
V_10 = F_275 ( V_16 , V_376 -> V_551 ) ;
if ( V_10 )
goto V_48;
V_10 = F_275 ( V_16 , V_376 -> V_552 ) ;
V_48:
return V_10 ;
}
static int F_278 ( struct V_8 * V_9 )
{
struct V_582 * V_376 = & V_9 -> V_549 ;
if ( V_376 )
return F_275 ( V_9 -> V_16 , V_376 -> V_583 ) ;
return 0 ;
}
static int F_66 ( struct V_8 * V_9 , bool V_576 ,
bool V_584 )
{
int V_10 = 0 ;
struct V_585 * V_586 ;
struct V_587 * V_588 = & V_9 -> V_589 ;
unsigned long V_78 ;
if ( ! V_588 || F_279 ( V_588 ) )
goto V_48;
F_280 (clki, head, list) {
if ( ! F_281 ( V_586 -> V_590 ) ) {
if ( V_584 && ! strcmp ( V_586 -> V_118 , L_88 ) )
continue;
if ( V_576 && ! V_586 -> V_581 ) {
V_10 = F_282 ( V_586 -> V_590 ) ;
if ( V_10 ) {
F_5 ( V_9 -> V_16 , L_89 ,
V_17 , V_586 -> V_118 , V_10 ) ;
goto V_48;
}
} else if ( ! V_576 && V_586 -> V_581 ) {
F_283 ( V_586 -> V_590 ) ;
}
V_586 -> V_581 = V_576 ;
F_181 ( V_9 -> V_16 , L_90 , V_17 ,
V_586 -> V_118 , V_576 ? L_91 : L_92 ) ;
}
}
if ( V_9 -> V_33 && V_9 -> V_33 -> V_591 )
V_10 = V_9 -> V_33 -> V_591 ( V_9 , V_576 ) ;
V_48:
if ( V_10 ) {
F_280 (clki, head, list) {
if ( ! F_281 ( V_586 -> V_590 ) && V_586 -> V_581 )
F_283 ( V_586 -> V_590 ) ;
}
} else if ( V_576 ) {
F_45 ( V_9 -> V_82 -> V_83 , V_78 ) ;
V_9 -> V_79 . V_84 = V_85 ;
F_46 ( V_9 -> V_82 -> V_83 , V_78 ) ;
}
return V_10 ;
}
static int F_47 ( struct V_8 * V_9 , bool V_576 )
{
return F_66 ( V_9 , V_576 , false ) ;
}
static int F_284 ( struct V_8 * V_9 )
{
int V_10 = 0 ;
struct V_585 * V_586 ;
struct V_107 * V_16 = V_9 -> V_16 ;
struct V_587 * V_588 = & V_9 -> V_589 ;
if ( ! V_588 || F_279 ( V_588 ) )
goto V_48;
F_280 (clki, head, list) {
if ( ! V_586 -> V_118 )
continue;
V_586 -> V_590 = F_285 ( V_16 , V_586 -> V_118 ) ;
if ( F_252 ( V_586 -> V_590 ) ) {
V_10 = F_253 ( V_586 -> V_590 ) ;
F_5 ( V_16 , L_93 ,
V_17 , V_586 -> V_118 , V_10 ) ;
goto V_48;
}
if ( V_586 -> V_592 ) {
V_10 = F_286 ( V_586 -> V_590 , V_586 -> V_592 ) ;
if ( V_10 ) {
F_5 ( V_9 -> V_16 , L_94 ,
V_17 , V_586 -> V_118 ,
V_586 -> V_592 , V_10 ) ;
goto V_48;
}
V_586 -> V_593 = V_586 -> V_592 ;
}
F_181 ( V_16 , L_95 , V_17 ,
V_586 -> V_118 , F_287 ( V_586 -> V_590 ) ) ;
}
V_48:
return V_10 ;
}
static int F_288 ( struct V_8 * V_9 )
{
int V_23 = 0 ;
if ( ! V_9 -> V_33 )
goto V_48;
if ( V_9 -> V_33 -> V_594 ) {
V_23 = V_9 -> V_33 -> V_594 ( V_9 ) ;
if ( V_23 )
goto V_48;
}
if ( V_9 -> V_33 -> V_595 ) {
V_23 = V_9 -> V_33 -> V_595 ( V_9 , true ) ;
if ( V_23 )
goto V_596;
}
goto V_48;
V_596:
if ( V_9 -> V_33 -> exit )
V_9 -> V_33 -> exit ( V_9 ) ;
V_48:
if ( V_23 )
F_5 ( V_9 -> V_16 , L_96 ,
V_17 , V_9 -> V_33 ? V_9 -> V_33 -> V_118 : L_97 , V_23 ) ;
return V_23 ;
}
static void F_289 ( struct V_8 * V_9 )
{
if ( ! V_9 -> V_33 )
return;
if ( V_9 -> V_33 -> V_591 )
V_9 -> V_33 -> V_591 ( V_9 , false ) ;
if ( V_9 -> V_33 -> V_595 )
V_9 -> V_33 -> V_595 ( V_9 , false ) ;
if ( V_9 -> V_33 -> exit )
V_9 -> V_33 -> exit ( V_9 ) ;
}
static int F_290 ( struct V_8 * V_9 )
{
int V_23 ;
V_23 = F_278 ( V_9 ) ;
if ( V_23 )
goto V_48;
V_23 = F_274 ( V_9 , true ) ;
if ( V_23 )
goto V_48;
V_23 = F_284 ( V_9 ) ;
if ( V_23 )
goto V_597;
V_23 = F_47 ( V_9 , true ) ;
if ( V_23 )
goto V_597;
V_23 = F_277 ( V_9 ) ;
if ( V_23 )
goto V_598;
V_23 = F_272 ( V_9 , true ) ;
if ( V_23 )
goto V_598;
V_23 = F_288 ( V_9 ) ;
if ( V_23 )
goto V_599;
V_9 -> V_600 = true ;
goto V_48;
V_599:
F_272 ( V_9 , false ) ;
V_598:
F_47 ( V_9 , false ) ;
V_597:
F_274 ( V_9 , false ) ;
V_48:
return V_23 ;
}
static void F_259 ( struct V_8 * V_9 )
{
if ( V_9 -> V_600 ) {
F_289 ( V_9 ) ;
F_272 ( V_9 , false ) ;
F_47 ( V_9 , false ) ;
F_274 ( V_9 , false ) ;
V_9 -> V_600 = false ;
}
}
static int
F_291 ( struct V_8 * V_9 , struct V_416 * V_601 )
{
unsigned char V_179 [ 6 ] = { V_602 ,
0 ,
0 ,
0 ,
V_135 ,
0 } ;
char * V_603 ;
int V_10 ;
V_603 = F_292 ( V_135 , V_300 ) ;
if ( ! V_603 ) {
V_10 = - V_301 ;
goto V_48;
}
V_10 = F_293 ( V_601 , V_179 , V_199 , V_603 ,
V_135 , NULL ,
F_9 ( 1000 ) , 3 , NULL , V_604 ) ;
if ( V_10 )
F_247 ( L_72 , V_17 , V_10 ) ;
F_154 ( V_603 ) ;
V_48:
return V_10 ;
}
static int F_294 ( struct V_8 * V_9 ,
enum V_1 V_383 )
{
unsigned char V_179 [ 6 ] = { V_605 } ;
struct V_606 V_607 ;
struct V_416 * V_601 ;
unsigned long V_78 ;
int V_10 ;
F_45 ( V_9 -> V_82 -> V_83 , V_78 ) ;
V_601 = V_9 -> V_435 ;
if ( V_601 ) {
V_10 = F_295 ( V_601 ) ;
if ( ! V_10 && ! F_296 ( V_601 ) ) {
V_10 = - V_608 ;
F_254 ( V_601 ) ;
}
} else {
V_10 = - V_608 ;
}
F_46 ( V_9 -> V_82 -> V_83 , V_78 ) ;
if ( V_10 )
return V_10 ;
V_9 -> V_82 -> V_609 = 1 ;
if ( V_9 -> V_566 ) {
V_10 = F_291 ( V_9 , V_601 ) ;
if ( V_10 )
goto V_48;
V_9 -> V_566 = false ;
}
V_179 [ 4 ] = V_383 << 4 ;
V_10 = F_293 ( V_601 , V_179 , V_230 , NULL , 0 , & V_607 ,
V_610 , 0 , NULL , V_604 ) ;
if ( V_10 ) {
F_297 ( V_611 , V_601 ,
L_98 ,
V_383 , V_10 ) ;
if ( F_298 ( V_10 ) & V_612 )
F_299 ( V_601 , NULL , & V_607 ) ;
}
if ( ! V_10 )
V_9 -> V_613 = V_383 ;
V_48:
F_254 ( V_601 ) ;
V_9 -> V_82 -> V_609 = 0 ;
return V_10 ;
}
static int F_300 ( struct V_8 * V_9 ,
enum V_6 V_614 ,
int V_615 )
{
int V_10 = 0 ;
if ( V_614 == V_9 -> V_6 )
return 0 ;
if ( V_614 == V_616 ) {
V_10 = F_62 ( V_9 ) ;
if ( ! V_10 )
F_63 ( V_9 ) ;
else
goto V_48;
}
else if ( ( V_614 == V_617 ) &&
( ! V_615 || ( V_615 &&
! V_9 -> V_472 ) ) ) {
F_186 ( V_9 ) ;
F_175 ( V_9 ) ;
}
V_48:
return V_10 ;
}
static void F_301 ( struct V_8 * V_9 )
{
if ( F_302 ( V_9 ) && F_303 ( V_9 ) &&
! V_9 -> V_422 . V_424 ) {
F_272 ( V_9 , false ) ;
} else if ( ! F_304 ( V_9 ) ) {
F_273 ( V_9 -> V_16 , V_9 -> V_549 . V_550 , false ) ;
if ( ! F_65 ( V_9 ) ) {
F_263 ( V_9 , V_9 -> V_549 . V_551 ) ;
F_263 ( V_9 , V_9 -> V_549 . V_552 ) ;
}
}
}
static int F_305 ( struct V_8 * V_9 )
{
int V_10 = 0 ;
if ( F_302 ( V_9 ) && F_303 ( V_9 ) &&
! V_9 -> V_422 . V_424 ) {
V_10 = F_272 ( V_9 , true ) ;
} else if ( ! F_304 ( V_9 ) ) {
V_10 = F_273 ( V_9 -> V_16 , V_9 -> V_549 . V_550 , true ) ;
if ( ! V_10 && ! F_65 ( V_9 ) ) {
V_10 = F_264 ( V_9 , V_9 -> V_549 . V_551 ) ;
if ( V_10 )
goto V_618;
V_10 = F_264 ( V_9 , V_9 -> V_549 . V_552 ) ;
if ( V_10 )
goto V_619;
}
}
goto V_48;
V_619:
F_263 ( V_9 , V_9 -> V_549 . V_551 ) ;
V_618:
F_273 ( V_9 -> V_16 , V_9 -> V_549 . V_550 , false ) ;
V_48:
return V_10 ;
}
static void F_306 ( struct V_8 * V_9 )
{
if ( F_303 ( V_9 ) )
F_274 ( V_9 , false ) ;
}
static void F_307 ( struct V_8 * V_9 )
{
if ( F_303 ( V_9 ) )
F_274 ( V_9 , true ) ;
}
static int F_308 ( struct V_8 * V_9 , enum V_620 V_621 )
{
int V_10 = 0 ;
enum V_2 V_622 ;
enum V_1 V_623 ;
enum V_6 V_614 ;
V_9 -> V_567 = 1 ;
if ( ! F_309 ( V_621 ) ) {
V_622 = F_310 ( V_621 ) ?
V_9 -> V_624 : V_9 -> V_625 ;
V_623 = F_1 ( V_622 ) ;
V_614 = F_2 ( V_622 ) ;
} else {
V_623 = V_626 ;
V_614 = V_617 ;
}
F_55 ( V_9 , false ) ;
V_9 -> V_79 . V_87 = true ;
if ( V_623 == V_627 &&
V_614 == V_628 ) {
goto V_629;
}
if ( ( V_623 == V_9 -> V_613 ) &&
( V_614 == V_9 -> V_6 ) )
goto V_48;
if ( ! F_304 ( V_9 ) || ! F_65 ( V_9 ) ) {
V_10 = - V_114 ;
goto V_48;
}
if ( F_310 ( V_621 ) ) {
if ( F_311 ( V_9 ) ) {
V_10 = F_219 ( V_9 ) ;
if ( V_10 )
goto V_630;
} else {
F_215 ( V_9 ) ;
}
}
if ( ( V_623 != V_9 -> V_613 ) &&
( ( F_310 ( V_621 ) && ! V_9 -> V_472 ) ||
! F_310 ( V_621 ) ) ) {
F_215 ( V_9 ) ;
V_10 = F_294 ( V_9 , V_623 ) ;
if ( V_10 )
goto V_630;
}
V_10 = F_300 ( V_9 , V_614 , 1 ) ;
if ( V_10 )
goto V_631;
F_301 ( V_9 ) ;
V_629:
if ( F_52 ( V_9 ) ) {
F_64 ( V_9 -> V_88 ) ;
V_9 -> V_104 . V_105 = 0 ;
}
if ( V_9 -> V_33 && V_9 -> V_33 -> V_632 ) {
V_10 = V_9 -> V_33 -> V_632 ( V_9 , V_621 ) ;
if ( V_10 )
goto V_633;
}
if ( V_9 -> V_33 && V_9 -> V_33 -> V_591 ) {
V_10 = V_9 -> V_33 -> V_591 ( V_9 , false ) ;
if ( V_10 )
goto V_634;
}
if ( ! F_65 ( V_9 ) )
F_47 ( V_9 , false ) ;
else
F_66 ( V_9 , false , true ) ;
V_9 -> V_79 . V_84 = V_94 ;
F_6 ( V_9 ) ;
F_306 ( V_9 ) ;
goto V_48;
V_634:
if ( V_9 -> V_33 && V_9 -> V_33 -> V_635 )
V_9 -> V_33 -> V_635 ( V_9 , V_621 ) ;
V_633:
F_305 ( V_9 ) ;
if ( F_49 ( V_9 ) && ! F_50 ( V_9 ) )
F_51 ( V_9 ) ;
else if ( F_303 ( V_9 ) )
F_176 ( V_9 ) ;
V_631:
if ( ! F_294 ( V_9 , V_627 ) )
F_215 ( V_9 ) ;
V_630:
V_9 -> V_79 . V_87 = false ;
F_69 ( V_9 ) ;
V_48:
V_9 -> V_567 = 0 ;
return V_10 ;
}
static int F_312 ( struct V_8 * V_9 , enum V_620 V_621 )
{
int V_10 ;
enum V_6 V_636 ;
V_9 -> V_567 = 1 ;
V_636 = V_9 -> V_6 ;
F_307 ( V_9 ) ;
V_10 = F_47 ( V_9 , true ) ;
if ( V_10 )
goto V_48;
V_10 = F_3 ( V_9 ) ;
if ( V_10 )
goto V_637;
V_10 = F_305 ( V_9 ) ;
if ( V_10 )
goto V_637;
if ( V_9 -> V_33 && V_9 -> V_33 -> V_635 ) {
V_10 = V_9 -> V_33 -> V_635 ( V_9 , V_621 ) ;
if ( V_10 )
goto V_638;
}
if ( F_49 ( V_9 ) ) {
V_10 = F_50 ( V_9 ) ;
if ( ! V_10 )
F_51 ( V_9 ) ;
else
goto V_639;
} else if ( F_303 ( V_9 ) ) {
V_10 = F_176 ( V_9 ) ;
if ( V_10 || ! F_65 ( V_9 ) )
goto V_639;
}
if ( ! F_304 ( V_9 ) ) {
V_10 = F_294 ( V_9 , V_627 ) ;
if ( V_10 )
goto V_640;
}
F_219 ( V_9 ) ;
V_9 -> V_79 . V_87 = false ;
if ( F_52 ( V_9 ) )
F_53 ( V_9 -> V_88 ) ;
F_69 ( V_9 ) ;
goto V_48;
V_640:
F_300 ( V_9 , V_636 , 0 ) ;
V_639:
if ( V_9 -> V_33 && V_9 -> V_33 -> V_632 )
V_9 -> V_33 -> V_632 ( V_9 , V_621 ) ;
V_638:
F_301 ( V_9 ) ;
V_637:
F_6 ( V_9 ) ;
F_47 ( V_9 , false ) ;
V_48:
V_9 -> V_567 = 0 ;
return V_10 ;
}
int F_313 ( struct V_8 * V_9 )
{
int V_10 = 0 ;
if ( ! V_9 || ! V_9 -> V_600 )
return 0 ;
if ( F_314 ( V_9 -> V_16 ) ) {
if ( V_9 -> V_624 == V_9 -> V_625 )
if ( ( F_1 ( V_9 -> V_625 ) ==
V_9 -> V_613 ) && ! V_9 -> V_472 )
goto V_48;
V_10 = F_315 ( V_9 ) ;
if ( V_10 )
goto V_48;
}
V_10 = F_308 ( V_9 , V_641 ) ;
V_48:
if ( ! V_10 )
V_9 -> V_642 = true ;
return V_10 ;
}
int F_316 ( struct V_8 * V_9 )
{
if ( ! V_9 || ! V_9 -> V_600 || F_314 ( V_9 -> V_16 ) )
return 0 ;
return F_312 ( V_9 , V_641 ) ;
}
int F_317 ( struct V_8 * V_9 )
{
if ( ! V_9 || ! V_9 -> V_600 )
return 0 ;
return F_308 ( V_9 , V_643 ) ;
}
int F_315 ( struct V_8 * V_9 )
{
if ( ! V_9 || ! V_9 -> V_600 )
return 0 ;
else
return F_312 ( V_9 , V_643 ) ;
}
int F_318 ( struct V_8 * V_9 )
{
return 0 ;
}
int F_319 ( struct V_8 * V_9 )
{
int V_10 = 0 ;
if ( F_302 ( V_9 ) && F_303 ( V_9 ) )
goto V_48;
if ( F_314 ( V_9 -> V_16 ) ) {
V_10 = F_315 ( V_9 ) ;
if ( V_10 )
goto V_48;
}
V_10 = F_308 ( V_9 , V_644 ) ;
V_48:
if ( V_10 )
F_5 ( V_9 -> V_16 , L_99 , V_17 , V_10 ) ;
return 0 ;
}
void F_320 ( struct V_8 * V_9 )
{
F_321 ( V_9 -> V_82 ) ;
F_118 ( V_9 , V_9 -> V_645 ) ;
F_186 ( V_9 ) ;
F_322 ( V_9 -> V_82 ) ;
F_79 ( V_9 ) ;
if ( F_52 ( V_9 ) )
F_323 ( V_9 -> V_88 ) ;
F_259 ( V_9 ) ;
}
static int F_324 ( struct V_8 * V_9 )
{
if ( V_9 -> V_155 & V_646 ) {
if ( ! F_325 ( V_9 -> V_16 , F_326 ( 64 ) ) )
return 0 ;
}
return F_325 ( V_9 -> V_16 , F_326 ( 32 ) ) ;
}
int F_327 ( struct V_107 * V_16 , struct V_8 * * V_647 )
{
struct V_240 * V_82 ;
struct V_8 * V_9 ;
int V_23 = 0 ;
if ( ! V_16 ) {
F_5 ( V_16 ,
L_100 ) ;
V_23 = - V_608 ;
goto V_648;
}
V_82 = F_328 ( & V_649 ,
sizeof( struct V_8 ) ) ;
if ( ! V_82 ) {
F_5 ( V_16 , L_101 ) ;
V_23 = - V_301 ;
goto V_648;
}
V_9 = F_130 ( V_82 ) ;
V_9 -> V_82 = V_82 ;
V_9 -> V_16 = V_16 ;
* V_647 = V_9 ;
V_648:
return V_23 ;
}
static int F_329 ( struct V_8 * V_9 , bool V_650 )
{
int V_10 = 0 ;
struct V_585 * V_586 ;
struct V_587 * V_588 = & V_9 -> V_589 ;
if ( ! V_588 || F_279 ( V_588 ) )
goto V_48;
F_280 (clki, head, list) {
if ( ! F_281 ( V_586 -> V_590 ) ) {
if ( V_650 && V_586 -> V_592 ) {
if ( V_586 -> V_593 == V_586 -> V_592 )
continue;
V_10 = F_286 ( V_586 -> V_590 , V_586 -> V_592 ) ;
if ( V_10 ) {
F_5 ( V_9 -> V_16 , L_94 ,
V_17 , V_586 -> V_118 ,
V_586 -> V_592 , V_10 ) ;
break;
}
V_586 -> V_593 = V_586 -> V_592 ;
} else if ( ! V_650 && V_586 -> V_651 ) {
if ( V_586 -> V_593 == V_586 -> V_651 )
continue;
V_10 = F_286 ( V_586 -> V_590 , V_586 -> V_651 ) ;
if ( V_10 ) {
F_5 ( V_9 -> V_16 , L_94 ,
V_17 , V_586 -> V_118 ,
V_586 -> V_651 , V_10 ) ;
break;
}
V_586 -> V_593 = V_586 -> V_651 ;
}
}
F_181 ( V_9 -> V_16 , L_95 , V_17 ,
V_586 -> V_118 , F_287 ( V_586 -> V_590 ) ) ;
}
if ( V_9 -> V_33 -> V_652 )
V_9 -> V_33 -> V_652 ( V_9 ) ;
V_48:
return V_10 ;
}
static int F_330 ( struct V_107 * V_16 ,
unsigned long * V_653 , T_1 V_78 )
{
int V_23 = 0 ;
struct V_8 * V_9 = F_71 ( V_16 ) ;
if ( ! F_52 ( V_9 ) )
return - V_114 ;
if ( * V_653 == V_654 )
V_23 = F_329 ( V_9 , true ) ;
else if ( * V_653 == 0 )
V_23 = F_329 ( V_9 , false ) ;
return V_23 ;
}
static int F_331 ( struct V_107 * V_16 ,
struct V_655 * V_656 )
{
struct V_8 * V_9 = F_71 ( V_16 ) ;
struct V_124 * V_125 = & V_9 -> V_104 ;
unsigned long V_78 ;
if ( ! F_52 ( V_9 ) )
return - V_114 ;
memset ( V_656 , 0 , sizeof( * V_656 ) ) ;
F_45 ( V_9 -> V_82 -> V_83 , V_78 ) ;
if ( ! V_125 -> V_105 )
goto V_657;
if ( V_125 -> V_122 )
V_125 -> V_127 += F_85 ( F_86 ( F_83 () ,
V_125 -> V_123 ) ) ;
V_656 -> V_658 = F_332 ( ( long ) V_25 -
( long ) V_125 -> V_105 ) ;
V_656 -> V_659 = V_125 -> V_127 ;
V_657:
V_125 -> V_105 = V_25 ;
V_125 -> V_127 = 0 ;
if ( V_9 -> V_126 ) {
V_125 -> V_123 = F_83 () ;
V_125 -> V_122 = true ;
} else {
V_125 -> V_123 = F_87 ( 0 , 0 ) ;
V_125 -> V_122 = false ;
}
F_46 ( V_9 -> V_82 -> V_83 , V_78 ) ;
return 0 ;
}
int F_333 ( struct V_8 * V_9 , void T_9 * V_660 , unsigned int V_12 )
{
int V_23 ;
struct V_240 * V_82 = V_9 -> V_82 ;
struct V_107 * V_16 = V_9 -> V_16 ;
if ( ! V_660 ) {
F_5 ( V_9 -> V_16 ,
L_102 ) ;
V_23 = - V_608 ;
goto V_648;
}
V_9 -> V_660 = V_660 ;
V_9 -> V_12 = V_12 ;
V_23 = F_290 ( V_9 ) ;
if ( V_23 )
goto V_648;
F_96 ( V_9 ) ;
V_9 -> V_27 = F_14 ( V_9 ) ;
V_9 -> V_645 = F_13 ( V_9 ) ;
V_23 = F_324 ( V_9 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_103 ) ;
goto V_661;
}
V_23 = F_158 ( V_9 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_104 ) ;
goto V_661;
}
F_161 ( V_9 ) ;
V_82 -> V_662 = V_9 -> V_157 ;
V_82 -> V_663 = V_9 -> V_157 ;
V_82 -> V_664 = V_665 ;
V_82 -> V_666 = V_667 ;
V_82 -> V_668 = V_669 ;
V_82 -> V_670 = V_82 -> V_671 ;
V_82 -> V_672 = V_673 ;
V_9 -> V_375 . V_377 = false ;
F_334 ( & V_9 -> V_503 ) ;
F_334 ( & V_9 -> V_519 ) ;
F_76 ( & V_9 -> V_483 , F_224 ) ;
F_76 ( & V_9 -> V_455 , F_221 ) ;
F_335 ( & V_9 -> V_173 ) ;
F_335 ( & V_9 -> V_138 . V_274 ) ;
F_334 ( & V_9 -> V_138 . V_265 ) ;
F_74 ( V_9 ) ;
V_23 = F_336 ( V_16 , V_12 , V_13 , V_14 , V_15 , V_9 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_105 ) ;
goto V_674;
} else {
V_9 -> V_11 = true ;
}
V_23 = F_337 ( V_82 , V_82 -> V_662 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_106 ) ;
goto V_674;
}
V_23 = F_338 ( V_82 , V_9 -> V_16 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_107 ) ;
goto V_674;
}
V_23 = F_185 ( V_9 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_108 ) ;
goto V_675;
}
if ( F_52 ( V_9 ) ) {
V_9 -> V_88 = F_339 ( V_16 , & V_676 ,
L_109 , NULL ) ;
if ( F_252 ( V_9 -> V_88 ) ) {
F_5 ( V_9 -> V_16 , L_110 ,
F_253 ( V_9 -> V_88 ) ) ;
goto V_675;
}
F_64 ( V_9 -> V_88 ) ;
V_9 -> V_104 . V_105 = 0 ;
}
F_222 ( V_16 ) ;
F_340 ( V_9 ) ;
F_341 ( F_260 , V_9 ) ;
return 0 ;
V_675:
F_321 ( V_9 -> V_82 ) ;
V_674:
F_79 ( V_9 ) ;
V_661:
V_9 -> V_11 = false ;
F_322 ( V_82 ) ;
F_259 ( V_9 ) ;
V_648:
return V_23 ;
}

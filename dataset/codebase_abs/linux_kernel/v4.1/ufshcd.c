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
return F_10 ( V_9 , V_31 ) ;
}
static inline int F_15 ( struct V_8 * V_9 )
{
return ( F_10 ( V_9 , V_32 ) &
V_33 ) ? 1 : 0 ;
}
static inline int F_16 ( struct V_34 * V_35 )
{
return F_17 ( V_35 -> V_36 -> V_37 . V_38 ) & V_39 ;
}
static inline int
F_18 ( struct V_40 * V_41 )
{
return F_17 ( V_41 -> V_37 . V_38 ) & V_39 ;
}
static bool F_19 ( struct V_8 * V_9 , int * V_42 )
{
int V_43 ;
bool V_10 = false ;
if ( ! V_42 )
goto V_44;
do {
V_43 = F_20 ( & V_9 -> V_45 , V_9 -> V_46 ) ;
if ( V_43 >= V_9 -> V_46 )
goto V_44;
} while ( F_21 ( V_43 , & V_9 -> V_45 ) );
* V_42 = V_43 ;
V_10 = true ;
V_44:
return V_10 ;
}
static inline void F_22 ( struct V_8 * V_9 , int V_47 )
{
F_23 ( V_47 , & V_9 -> V_45 ) ;
}
static inline void F_24 ( struct V_8 * V_9 , T_1 V_48 )
{
F_25 ( V_9 , ~ ( 1 << V_48 ) , V_49 ) ;
}
static inline int F_26 ( T_1 V_18 )
{
return ( ( ( V_18 ) & ( 0xFF ) ) >> 1 ) ^ ( 0x07 ) ;
}
static inline int F_27 ( struct V_8 * V_9 )
{
return F_10 ( V_9 , V_50 ) &
V_51 ;
}
static inline T_1 F_28 ( struct V_8 * V_9 )
{
return F_10 ( V_9 , V_52 ) ;
}
static inline int
F_29 ( struct V_53 * V_54 )
{
return F_30 ( V_54 -> V_37 . V_55 ) >> 24 ;
}
static inline int
F_31 ( struct V_53 * V_54 )
{
return F_30 ( V_54 -> V_37 . V_56 ) & V_57 ;
}
static inline unsigned int
F_32 ( struct V_53 * V_54 )
{
return F_30 ( V_54 -> V_37 . V_38 ) &
V_58 ;
}
static inline bool F_33 ( struct V_53 * V_54 )
{
return F_30 ( V_54 -> V_37 . V_38 ) &
V_59 ? true : false ;
}
static inline void
F_34 ( struct V_8 * V_9 )
{
F_25 ( V_9 , V_60 |
V_61 ,
V_62 ) ;
}
static inline void
F_35 ( struct V_8 * V_9 , T_2 V_63 , T_2 V_64 )
{
F_25 ( V_9 , V_60 | V_65 |
F_36 ( V_63 ) |
F_37 ( V_64 ) ,
V_62 ) ;
}
static void F_38 ( struct V_8 * V_9 )
{
F_25 ( V_9 , V_66 ,
V_67 ) ;
F_25 ( V_9 , V_68 ,
V_69 ) ;
}
static inline void F_39 ( struct V_8 * V_9 )
{
F_25 ( V_9 , V_70 , V_71 ) ;
}
static inline int F_40 ( struct V_8 * V_9 )
{
return ( F_10 ( V_9 , V_71 ) & 0x1 ) ? 0 : 1 ;
}
static void F_41 ( struct V_72 * V_73 )
{
int V_10 ;
unsigned long V_74 ;
struct V_8 * V_9 = F_42 ( V_73 , struct V_8 ,
V_75 . V_76 ) ;
F_43 ( & V_9 -> V_75 . V_77 ) ;
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
if ( V_9 -> V_75 . V_80 == V_81 ) {
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
goto V_82;
}
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
F_46 ( V_9 , true ) ;
if ( F_47 ( V_9 ) ) {
V_9 -> V_75 . V_83 = true ;
if ( F_48 ( V_9 ) ) {
V_10 = F_49 ( V_9 ) ;
if ( V_10 )
F_5 ( V_9 -> V_16 , L_2 ,
V_17 , V_10 ) ;
else
F_50 ( V_9 ) ;
}
V_9 -> V_75 . V_83 = false ;
}
V_82:
if ( F_51 ( V_9 ) )
F_52 ( V_9 -> V_84 ) ;
F_53 ( V_9 -> V_78 ) ;
}
int F_54 ( struct V_8 * V_9 , bool V_85 )
{
int V_86 = 0 ;
unsigned long V_74 ;
if ( ! F_55 ( V_9 ) )
goto V_44;
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
V_9 -> V_75 . V_87 ++ ;
V_88:
switch ( V_9 -> V_75 . V_80 ) {
case V_81 :
break;
case V_89 :
if ( F_56 ( & V_9 -> V_75 . V_77 ) ) {
V_9 -> V_75 . V_80 = V_81 ;
break;
}
case V_90 :
F_57 ( V_9 -> V_78 ) ;
V_9 -> V_75 . V_80 = V_91 ;
F_58 ( & V_9 -> V_75 . V_76 ) ;
case V_91 :
if ( V_85 ) {
V_86 = - V_92 ;
V_9 -> V_75 . V_87 -- ;
break;
}
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
F_59 ( & V_9 -> V_75 . V_76 ) ;
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
goto V_88;
default:
F_5 ( V_9 -> V_16 , L_3 ,
V_17 , V_9 -> V_75 . V_80 ) ;
break;
}
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
V_44:
return V_86 ;
}
static void F_60 ( struct V_72 * V_73 )
{
struct V_8 * V_9 = F_42 ( V_73 , struct V_8 ,
V_75 . V_77 . V_73 ) ;
unsigned long V_74 ;
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
if ( V_9 -> V_75 . V_83 ) {
V_9 -> V_75 . V_80 = V_81 ;
goto V_93;
}
if ( V_9 -> V_75 . V_87
|| V_9 -> V_94 != V_95
|| V_9 -> V_96 || V_9 -> V_97
|| V_9 -> V_98 || V_9 -> V_99 )
goto V_93;
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
if ( F_47 ( V_9 ) ) {
if ( F_61 ( V_9 ) ) {
V_9 -> V_75 . V_80 = V_81 ;
goto V_44;
}
F_62 ( V_9 ) ;
}
if ( F_51 ( V_9 ) ) {
F_63 ( V_9 -> V_84 ) ;
V_9 -> V_100 . V_101 = 0 ;
}
if ( ! F_64 ( V_9 ) )
F_46 ( V_9 , false ) ;
else
F_65 ( V_9 , false , true ) ;
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
if ( V_9 -> V_75 . V_80 == V_89 )
V_9 -> V_75 . V_80 = V_90 ;
V_93:
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
V_44:
return;
}
static void F_66 ( struct V_8 * V_9 )
{
if ( ! F_55 ( V_9 ) )
return;
V_9 -> V_75 . V_87 -- ;
if ( V_9 -> V_75 . V_87 || V_9 -> V_75 . V_83
|| V_9 -> V_94 != V_95
|| V_9 -> V_96 || V_9 -> V_97
|| V_9 -> V_98 || V_9 -> V_99 )
return;
V_9 -> V_75 . V_80 = V_89 ;
F_67 ( & V_9 -> V_75 . V_77 ,
F_9 ( V_9 -> V_75 . V_102 ) ) ;
}
void F_68 ( struct V_8 * V_9 )
{
unsigned long V_74 ;
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
F_66 ( V_9 ) ;
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
}
static T_3 F_69 ( struct V_103 * V_16 ,
struct V_104 * V_105 , char * V_106 )
{
struct V_8 * V_9 = F_70 ( V_16 ) ;
return snprintf ( V_106 , V_107 , L_4 , V_9 -> V_75 . V_102 ) ;
}
static T_3 F_71 ( struct V_103 * V_16 ,
struct V_104 * V_105 , const char * V_106 , T_4 V_108 )
{
struct V_8 * V_9 = F_70 ( V_16 ) ;
unsigned long V_74 , V_109 ;
if ( F_72 ( V_106 , 0 , & V_109 ) )
return - V_110 ;
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
V_9 -> V_75 . V_102 = V_109 ;
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
return V_108 ;
}
static void F_73 ( struct V_8 * V_9 )
{
if ( ! F_55 ( V_9 ) )
return;
V_9 -> V_75 . V_102 = 150 ;
F_74 ( & V_9 -> V_75 . V_77 , F_60 ) ;
F_75 ( & V_9 -> V_75 . V_76 , F_41 ) ;
V_9 -> V_75 . V_111 . V_112 = F_69 ;
V_9 -> V_75 . V_111 . V_113 = F_71 ;
F_76 ( & V_9 -> V_75 . V_111 . V_105 ) ;
V_9 -> V_75 . V_111 . V_105 . V_114 = L_5 ;
V_9 -> V_75 . V_111 . V_105 . V_115 = V_116 | V_117 ;
if ( F_77 ( V_9 -> V_16 , & V_9 -> V_75 . V_111 ) )
F_5 ( V_9 -> V_16 , L_6 ) ;
}
static void F_78 ( struct V_8 * V_9 )
{
if ( ! F_55 ( V_9 ) )
return;
F_79 ( V_9 -> V_16 , & V_9 -> V_75 . V_111 ) ;
F_80 ( & V_9 -> V_75 . V_76 ) ;
F_43 ( & V_9 -> V_75 . V_77 ) ;
}
static void F_81 ( struct V_8 * V_9 )
{
if ( ! F_51 ( V_9 ) )
return;
if ( ! V_9 -> V_100 . V_118 ) {
V_9 -> V_100 . V_119 = F_82 () ;
V_9 -> V_100 . V_118 = true ;
}
}
static void F_83 ( struct V_8 * V_9 )
{
struct V_120 * V_121 = & V_9 -> V_100 ;
if ( ! F_51 ( V_9 ) )
return;
if ( ! V_9 -> V_122 && V_121 -> V_118 ) {
V_121 -> V_123 += F_84 ( F_85 ( F_82 () ,
V_121 -> V_119 ) ) ;
V_121 -> V_119 = F_86 ( 0 , 0 ) ;
V_121 -> V_118 = false ;
}
}
static inline
void F_87 ( struct V_8 * V_9 , unsigned int V_124 )
{
F_81 ( V_9 ) ;
F_88 ( V_124 , & V_9 -> V_122 ) ;
F_25 ( V_9 , 1 << V_124 , V_125 ) ;
}
static inline void F_89 ( struct V_34 * V_35 )
{
int V_126 ;
if ( V_35 -> V_127 &&
F_32 ( V_35 -> V_54 ) ) {
V_126 = F_90 ( V_35 -> V_54 -> V_128 . V_129 ) ;
memcpy ( V_35 -> V_127 ,
V_35 -> V_54 -> V_128 . V_130 ,
F_91 ( int , V_126 , V_131 ) ) ;
}
}
static
int F_92 ( struct V_8 * V_9 , struct V_34 * V_35 )
{
struct V_132 * V_133 = & V_9 -> V_134 . V_135 . V_136 ;
memcpy ( & V_133 -> V_137 , & V_35 -> V_54 -> V_138 , V_139 ) ;
if ( V_35 -> V_54 -> V_138 . V_140 == V_141 ) {
T_2 * V_142 = ( T_2 * ) V_35 -> V_54 +
V_143 ;
T_5 V_144 ;
T_5 V_145 ;
V_144 = F_30 ( V_35 -> V_54 -> V_37 . V_38 ) &
V_146 ;
V_145 = F_90 (
V_9 -> V_134 . V_135 . V_147 . V_148 . V_149 ) ;
if ( F_93 ( V_145 >= V_144 ) ) {
memcpy ( V_9 -> V_134 . V_135 . V_150 , V_142 , V_144 ) ;
} else {
F_94 ( V_9 -> V_16 ,
L_7 ,
V_17 ) ;
return - V_110 ;
}
}
return 0 ;
}
static inline void F_95 ( struct V_8 * V_9 )
{
V_9 -> V_151 = F_10 ( V_9 , V_152 ) ;
V_9 -> V_153 = ( V_9 -> V_151 & V_154 ) + 1 ;
V_9 -> V_46 =
( ( V_9 -> V_151 & V_155 ) >> 16 ) + 1 ;
}
static inline bool F_96 ( struct V_8 * V_9 )
{
if ( F_10 ( V_9 , V_32 ) & V_156 )
return true ;
else
return false ;
}
static inline T_2 F_97 ( struct V_8 * V_9 )
{
return ( F_10 ( V_9 , V_32 ) >> 8 ) & 0x7 ;
}
static inline void
F_98 ( struct V_8 * V_9 , struct V_157 * V_158 )
{
F_99 ( V_9 -> V_98 ) ;
V_9 -> V_98 = V_158 ;
F_25 ( V_9 , V_158 -> V_159 , V_160 ) ;
F_25 ( V_9 , V_158 -> V_161 , V_50 ) ;
F_25 ( V_9 , V_158 -> V_162 , V_52 ) ;
F_25 ( V_9 , V_158 -> V_163 & V_164 ,
V_165 ) ;
}
static int
F_100 ( struct V_8 * V_9 , struct V_157 * V_158 )
{
int V_10 ;
unsigned long V_74 ;
if ( F_101 ( & V_158 -> V_166 ,
F_9 ( V_167 ) ) )
V_10 = V_158 -> V_161 & V_51 ;
else
V_10 = - V_26 ;
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
V_9 -> V_98 = NULL ;
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
return V_10 ;
}
static int
F_102 ( struct V_8 * V_9 , struct V_157 * V_158 )
{
if ( ! F_96 ( V_9 ) ) {
F_5 ( V_9 -> V_16 ,
L_8 ) ;
return - V_168 ;
}
F_103 ( & V_158 -> V_166 ) ;
F_98 ( V_9 , V_158 ) ;
return 0 ;
}
static int
F_104 ( struct V_8 * V_9 , struct V_157 * V_158 )
{
int V_10 ;
unsigned long V_74 ;
F_54 ( V_9 , false ) ;
F_105 ( & V_9 -> V_169 ) ;
F_106 ( V_9 ) ;
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
V_10 = F_102 ( V_9 , V_158 ) ;
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
if ( ! V_10 )
V_10 = F_100 ( V_9 , V_158 ) ;
F_107 ( & V_9 -> V_169 ) ;
F_68 ( V_9 ) ;
return V_10 ;
}
static int F_108 ( struct V_34 * V_35 )
{
struct V_170 * V_171 ;
struct V_172 * V_173 ;
struct V_174 * V_175 ;
int V_176 ;
int V_177 ;
V_175 = V_35 -> V_175 ;
V_176 = F_109 ( V_175 ) ;
if ( V_176 < 0 )
return V_176 ;
if ( V_176 ) {
V_35 -> V_36 -> V_178 =
F_110 ( ( T_5 ) ( V_176 ) ) ;
V_171 = (struct V_170 * ) V_35 -> V_179 ;
F_111 (cmd, sg, sg_segments, i) {
V_171 [ V_177 ] . V_180 =
F_112 ( ( ( T_1 ) F_113 ( V_173 ) ) - 1 ) ;
V_171 [ V_177 ] . V_181 =
F_112 ( F_114 ( V_173 -> V_182 ) ) ;
V_171 [ V_177 ] . V_183 =
F_112 ( F_115 ( V_173 -> V_182 ) ) ;
}
} else {
V_35 -> V_36 -> V_178 = 0 ;
}
return 0 ;
}
static void F_116 ( struct V_8 * V_9 , T_1 V_184 )
{
T_1 V_185 = F_10 ( V_9 , V_186 ) ;
if ( V_9 -> V_27 == V_28 ) {
T_1 V_187 ;
V_187 = V_185 & V_188 ;
V_185 = V_187 | ( ( V_185 ^ V_184 ) & V_184 ) ;
} else {
V_185 |= V_184 ;
}
F_25 ( V_9 , V_185 , V_186 ) ;
}
static void F_117 ( struct V_8 * V_9 , T_1 V_184 )
{
T_1 V_185 = F_10 ( V_9 , V_186 ) ;
if ( V_9 -> V_27 == V_28 ) {
T_1 V_187 ;
V_187 = ( V_185 & V_188 ) &
~ ( V_184 & V_188 ) ;
V_185 = V_187 | ( ( V_185 & V_184 ) & ~ V_188 ) ;
} else {
V_185 &= ~ V_184 ;
}
F_25 ( V_9 , V_185 , V_186 ) ;
}
static void F_118 ( struct V_34 * V_35 ,
T_1 * V_189 , enum V_190 V_191 )
{
struct V_192 * V_193 = V_35 -> V_36 ;
T_1 V_194 ;
T_1 V_55 ;
if ( V_191 == V_195 ) {
V_194 = V_196 ;
* V_189 = V_197 ;
} else if ( V_191 == V_198 ) {
V_194 = V_199 ;
* V_189 = V_200 ;
} else {
V_194 = V_201 ;
* V_189 = V_202 ;
}
V_55 = V_194 | ( V_35 -> V_203
<< V_204 ) ;
if ( V_35 -> V_205 )
V_55 |= V_206 ;
V_193 -> V_37 . V_55 = F_112 ( V_55 ) ;
V_193 -> V_37 . V_38 =
F_112 ( V_207 ) ;
}
static
void F_119 ( struct V_34 * V_35 , T_1 V_189 )
{
struct V_208 * V_209 = V_35 -> V_209 ;
V_209 -> V_37 . V_55 = F_120 (
V_210 , V_189 ,
V_35 -> V_211 , V_35 -> V_124 ) ;
V_209 -> V_37 . V_56 = F_120 (
V_212 , 0 , 0 , 0 ) ;
V_209 -> V_37 . V_38 = 0 ;
V_209 -> V_213 . V_214 =
F_121 ( V_35 -> V_175 -> V_215 . V_149 ) ;
memcpy ( V_209 -> V_213 . V_216 , V_35 -> V_175 -> V_217 ,
( F_91 (unsigned short, lrbp->cmd->cmd_len, MAX_CDB_SIZE) ) ) ;
}
static void F_122 ( struct V_8 * V_9 ,
struct V_34 * V_35 , T_1 V_189 )
{
struct V_208 * V_209 = V_35 -> V_209 ;
struct V_218 * V_135 = & V_9 -> V_134 . V_135 ;
T_5 V_126 = F_90 ( V_135 -> V_147 . V_148 . V_149 ) ;
T_2 * V_142 = ( T_2 * ) V_35 -> V_209 + V_143 ;
V_209 -> V_37 . V_55 = F_120 (
V_219 , V_189 ,
V_35 -> V_211 , V_35 -> V_124 ) ;
V_209 -> V_37 . V_56 = F_120 (
0 , V_135 -> V_147 . V_220 , 0 , 0 ) ;
V_209 -> V_37 . V_38 = F_120 (
0 , 0 , V_126 >> 8 , ( T_2 ) V_126 ) ;
memcpy ( & V_209 -> V_138 , & V_135 -> V_147 . V_148 ,
V_139 ) ;
if ( V_135 -> V_147 . V_148 . V_140 == V_221 )
memcpy ( V_142 , V_135 -> V_150 , V_126 ) ;
}
static inline void F_123 ( struct V_34 * V_35 )
{
struct V_208 * V_209 = V_35 -> V_209 ;
memset ( V_209 , 0 , sizeof( struct V_208 ) ) ;
V_209 -> V_37 . V_55 =
F_120 (
V_222 , 0 , 0 , V_35 -> V_124 ) ;
}
static int F_124 ( struct V_8 * V_9 , struct V_34 * V_35 )
{
T_1 V_189 ;
int V_10 = 0 ;
switch ( V_35 -> V_203 ) {
case V_223 :
if ( F_93 ( V_35 -> V_175 ) ) {
F_118 ( V_35 , & V_189 ,
V_35 -> V_175 -> V_224 ) ;
F_119 ( V_35 , V_189 ) ;
} else {
V_10 = - V_110 ;
}
break;
case V_225 :
F_118 ( V_35 , & V_189 , V_226 ) ;
if ( V_9 -> V_134 . type == V_227 )
F_122 (
V_9 , V_35 , V_189 ) ;
else if ( V_9 -> V_134 . type == V_228 )
F_123 ( V_35 ) ;
else
V_10 = - V_110 ;
break;
case V_229 :
V_10 = - V_230 ;
F_5 ( V_9 -> V_16 , L_9 ,
V_17 ) ;
break;
default:
V_10 = - V_230 ;
F_5 ( V_9 -> V_16 , L_10 ,
V_17 , V_35 -> V_203 ) ;
break;
}
return V_10 ;
}
static inline T_2 F_125 ( unsigned int V_231 )
{
if ( F_126 ( V_231 ) )
return ( V_231 & V_232 )
| V_233 ;
else
return V_231 & V_232 ;
}
static inline T_5 F_127 ( T_2 V_234 )
{
return ( V_234 & ~ V_233 ) | V_235 ;
}
static int F_128 ( struct V_236 * V_78 , struct V_174 * V_175 )
{
struct V_34 * V_35 ;
struct V_8 * V_9 ;
unsigned long V_74 ;
int V_43 ;
int V_23 = 0 ;
V_9 = F_129 ( V_78 ) ;
V_43 = V_175 -> V_147 -> V_43 ;
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
switch ( V_9 -> V_94 ) {
case V_95 :
break;
case V_237 :
V_23 = V_238 ;
goto V_239;
case V_240 :
F_130 ( V_175 , V_241 ) ;
V_175 -> V_242 ( V_175 ) ;
goto V_239;
default:
F_131 ( V_9 -> V_16 , 1 , L_11 ,
V_17 , V_9 -> V_94 ) ;
F_130 ( V_175 , V_243 ) ;
V_175 -> V_242 ( V_175 ) ;
goto V_239;
}
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
if ( F_21 ( V_43 , & V_9 -> V_96 ) ) {
V_23 = V_238 ;
goto V_44;
}
V_23 = F_54 ( V_9 , true ) ;
if ( V_23 ) {
V_23 = V_238 ;
F_23 ( V_43 , & V_9 -> V_96 ) ;
goto V_44;
}
F_99 ( V_9 -> V_75 . V_80 != V_81 ) ;
V_35 = & V_9 -> V_244 [ V_43 ] ;
F_99 ( V_35 -> V_175 ) ;
V_35 -> V_175 = V_175 ;
V_35 -> V_245 = V_131 ;
V_35 -> V_127 = V_175 -> V_127 ;
V_35 -> V_124 = V_43 ;
V_35 -> V_211 = F_125 ( V_175 -> V_103 -> V_211 ) ;
V_35 -> V_205 = false ;
V_35 -> V_203 = V_223 ;
F_124 ( V_9 , V_35 ) ;
V_23 = F_108 ( V_35 ) ;
if ( V_23 ) {
V_35 -> V_175 = NULL ;
F_23 ( V_43 , & V_9 -> V_96 ) ;
goto V_44;
}
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
F_87 ( V_9 , V_43 ) ;
V_239:
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
V_44:
return V_23 ;
}
static int F_132 ( struct V_8 * V_9 ,
struct V_34 * V_35 , enum V_246 V_247 , int V_43 )
{
V_35 -> V_175 = NULL ;
V_35 -> V_245 = 0 ;
V_35 -> V_127 = NULL ;
V_35 -> V_124 = V_43 ;
V_35 -> V_211 = 0 ;
V_35 -> V_203 = V_225 ;
V_35 -> V_205 = true ;
V_9 -> V_134 . type = V_247 ;
return F_124 ( V_9 , V_35 ) ;
}
static int
F_133 ( struct V_8 * V_9 , int V_43 )
{
int V_23 = 0 ;
unsigned long V_74 ;
T_1 V_19 = 1 << V_43 ;
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
F_24 ( V_9 , V_43 ) ;
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
V_23 = F_8 ( V_9 ,
V_125 ,
V_19 , ~ V_19 , 1000 , 1000 ) ;
return V_23 ;
}
static int
F_134 ( struct V_8 * V_9 , struct V_34 * V_35 )
{
struct V_132 * V_133 = & V_9 -> V_134 . V_135 . V_136 ;
V_133 -> V_136 = F_31 ( V_35 -> V_54 ) >>
V_248 ;
return V_133 -> V_136 ;
}
static int
F_135 ( struct V_8 * V_9 , struct V_34 * V_35 )
{
int V_249 ;
int V_23 = 0 ;
V_249 = F_29 ( V_35 -> V_54 ) ;
switch ( V_249 ) {
case V_250 :
if ( V_9 -> V_134 . type != V_228 ) {
V_23 = - V_110 ;
F_5 ( V_9 -> V_16 , L_12 ,
V_17 , V_249 ) ;
}
break;
case V_251 :
V_23 = F_134 ( V_9 , V_35 ) ;
if ( ! V_23 )
V_23 = F_92 ( V_9 , V_35 ) ;
break;
case V_252 :
V_23 = - V_253 ;
F_5 ( V_9 -> V_16 , L_13 ,
V_17 ) ;
break;
default:
V_23 = - V_110 ;
F_5 ( V_9 -> V_16 , L_14 ,
V_17 , V_249 ) ;
break;
}
return V_23 ;
}
static int F_136 ( struct V_8 * V_9 ,
struct V_34 * V_35 , int V_254 )
{
int V_23 = 0 ;
unsigned long V_255 ;
unsigned long V_74 ;
V_255 = F_101 ( V_9 -> V_134 . V_256 ,
F_9 ( V_254 ) ) ;
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
V_9 -> V_134 . V_256 = NULL ;
if ( F_93 ( V_255 ) ) {
V_23 = F_16 ( V_35 ) ;
if ( ! V_23 )
V_23 = F_135 ( V_9 , V_35 ) ;
}
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
if ( ! V_255 ) {
V_23 = - V_26 ;
if ( ! F_133 ( V_9 , V_35 -> V_124 ) )
V_23 = - V_92 ;
}
return V_23 ;
}
static bool F_137 ( struct V_8 * V_9 , int * V_257 )
{
int V_43 ;
bool V_10 = false ;
unsigned long V_258 ;
if ( ! V_257 )
goto V_44;
do {
V_258 = ~ V_9 -> V_96 ;
V_43 = F_138 ( & V_258 , V_9 -> V_153 ) ;
if ( V_43 >= V_9 -> V_153 )
goto V_44;
} while ( F_21 ( V_43 , & V_9 -> V_96 ) );
* V_257 = V_43 ;
V_10 = true ;
V_44:
return V_10 ;
}
static inline void F_139 ( struct V_8 * V_9 , int V_43 )
{
F_23 ( V_43 , & V_9 -> V_96 ) ;
}
static int F_140 ( struct V_8 * V_9 ,
enum V_246 V_247 , int V_24 )
{
struct V_34 * V_35 ;
int V_23 ;
int V_43 ;
struct V_259 V_260 ;
unsigned long V_74 ;
F_141 ( V_9 -> V_134 . V_261 , F_137 ( V_9 , & V_43 ) ) ;
F_103 ( & V_260 ) ;
V_35 = & V_9 -> V_244 [ V_43 ] ;
F_99 ( V_35 -> V_175 ) ;
V_23 = F_132 ( V_9 , V_35 , V_247 , V_43 ) ;
if ( F_142 ( V_23 ) )
goto V_262;
V_9 -> V_134 . V_256 = & V_260 ;
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
F_87 ( V_9 , V_43 ) ;
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
V_23 = F_136 ( V_9 , V_35 , V_24 ) ;
V_262:
F_139 ( V_9 , V_43 ) ;
F_143 ( & V_9 -> V_134 . V_261 ) ;
return V_23 ;
}
static inline void F_144 ( struct V_8 * V_9 ,
struct V_263 * * V_147 , struct V_132 * * V_136 ,
enum V_264 V_140 , T_2 V_265 , T_2 V_266 , T_2 V_267 )
{
* V_147 = & V_9 -> V_134 . V_135 . V_147 ;
* V_136 = & V_9 -> V_134 . V_135 . V_136 ;
memset ( * V_147 , 0 , sizeof( struct V_263 ) ) ;
memset ( * V_136 , 0 , sizeof( struct V_132 ) ) ;
( * V_147 ) -> V_148 . V_140 = V_140 ;
( * V_147 ) -> V_148 . V_265 = V_265 ;
( * V_147 ) -> V_148 . V_266 = V_266 ;
( * V_147 ) -> V_148 . V_267 = V_267 ;
}
static int F_145 ( struct V_8 * V_9 , enum V_264 V_140 ,
enum V_268 V_265 , bool * V_269 )
{
struct V_263 * V_147 = NULL ;
struct V_132 * V_136 = NULL ;
int V_23 , V_266 = 0 , V_267 = 0 ;
F_146 ( ! V_9 ) ;
F_54 ( V_9 , false ) ;
F_105 ( & V_9 -> V_134 . V_270 ) ;
F_144 ( V_9 , & V_147 , & V_136 , V_140 , V_265 , V_266 ,
V_267 ) ;
switch ( V_140 ) {
case V_271 :
case V_272 :
case V_273 :
V_147 -> V_220 = V_274 ;
break;
case V_275 :
V_147 -> V_220 = V_276 ;
if ( ! V_269 ) {
F_5 ( V_9 -> V_16 , L_15 ,
V_17 ) ;
V_23 = - V_110 ;
goto V_239;
}
break;
default:
F_5 ( V_9 -> V_16 ,
L_16 ,
V_17 , V_140 ) ;
V_23 = - V_110 ;
goto V_239;
}
V_23 = F_140 ( V_9 , V_227 , V_277 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 ,
L_17 ,
V_17 , V_265 , V_23 ) ;
goto V_239;
}
if ( V_269 )
* V_269 = ( F_30 ( V_136 -> V_137 . V_109 ) &
V_278 ) & 0x1 ;
V_239:
F_107 ( & V_9 -> V_134 . V_270 ) ;
F_68 ( V_9 ) ;
return V_23 ;
}
static int F_147 ( struct V_8 * V_9 , enum V_264 V_140 ,
enum V_279 V_265 , T_2 V_266 , T_2 V_267 , T_1 * V_280 )
{
struct V_263 * V_147 = NULL ;
struct V_132 * V_136 = NULL ;
int V_23 ;
F_146 ( ! V_9 ) ;
F_54 ( V_9 , false ) ;
if ( ! V_280 ) {
F_5 ( V_9 -> V_16 , L_18 ,
V_17 , V_140 ) ;
V_23 = - V_110 ;
goto V_44;
}
F_105 ( & V_9 -> V_134 . V_270 ) ;
F_144 ( V_9 , & V_147 , & V_136 , V_140 , V_265 , V_266 ,
V_267 ) ;
switch ( V_140 ) {
case V_281 :
V_147 -> V_220 = V_274 ;
V_147 -> V_148 . V_109 = F_121 ( * V_280 ) ;
break;
case V_282 :
V_147 -> V_220 = V_276 ;
break;
default:
F_5 ( V_9 -> V_16 , L_19 ,
V_17 , V_140 ) ;
V_23 = - V_110 ;
goto V_239;
}
V_23 = F_140 ( V_9 , V_227 , V_277 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_20 ,
V_17 , V_140 , V_265 , V_23 ) ;
goto V_239;
}
* V_280 = F_30 ( V_136 -> V_137 . V_109 ) ;
V_239:
F_107 ( & V_9 -> V_134 . V_270 ) ;
V_44:
F_68 ( V_9 ) ;
return V_23 ;
}
static int F_148 ( struct V_8 * V_9 ,
enum V_264 V_140 , enum V_283 V_265 , T_2 V_266 ,
T_2 V_267 , T_2 * V_284 , int * V_145 )
{
struct V_263 * V_147 = NULL ;
struct V_132 * V_136 = NULL ;
int V_23 ;
F_146 ( ! V_9 ) ;
F_54 ( V_9 , false ) ;
if ( ! V_284 ) {
F_5 ( V_9 -> V_16 , L_21 ,
V_17 , V_140 ) ;
V_23 = - V_110 ;
goto V_44;
}
if ( * V_145 <= V_285 || * V_145 > V_286 ) {
F_5 ( V_9 -> V_16 , L_22 ,
V_17 , * V_145 ) ;
V_23 = - V_110 ;
goto V_44;
}
F_105 ( & V_9 -> V_134 . V_270 ) ;
F_144 ( V_9 , & V_147 , & V_136 , V_140 , V_265 , V_266 ,
V_267 ) ;
V_9 -> V_134 . V_135 . V_150 = V_284 ;
V_147 -> V_148 . V_149 = F_149 ( * V_145 ) ;
switch ( V_140 ) {
case V_221 :
V_147 -> V_220 = V_274 ;
break;
case V_141 :
V_147 -> V_220 = V_276 ;
break;
default:
F_5 ( V_9 -> V_16 ,
L_23 ,
V_17 , V_140 ) ;
V_23 = - V_110 ;
goto V_239;
}
V_23 = F_140 ( V_9 , V_227 , V_277 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_20 ,
V_17 , V_140 , V_265 , V_23 ) ;
goto V_239;
}
V_9 -> V_134 . V_135 . V_150 = NULL ;
* V_145 = F_90 ( V_136 -> V_137 . V_149 ) ;
V_239:
F_107 ( & V_9 -> V_134 . V_270 ) ;
V_44:
F_68 ( V_9 ) ;
return V_23 ;
}
static int F_150 ( struct V_8 * V_9 ,
enum V_283 V_287 ,
int V_288 ,
T_1 V_289 ,
T_2 * V_290 ,
T_1 V_291 )
{
int V_10 ;
T_2 * V_284 ;
T_1 V_292 ;
bool V_293 = true ;
if ( V_287 >= V_294 )
return - V_110 ;
V_292 = V_295 [ V_287 ] ;
if ( ( V_289 + V_291 ) > V_292 )
return - V_110 ;
if ( ! V_289 && ( V_291 == V_292 ) ) {
V_284 = V_290 ;
V_293 = false ;
} else {
V_284 = F_151 ( V_292 , V_296 ) ;
if ( ! V_284 )
return - V_297 ;
}
V_10 = F_148 ( V_9 , V_141 ,
V_287 , V_288 , 0 , V_284 ,
& V_292 ) ;
if ( V_10 || ( V_292 < V_295 [ V_287 ] ) ||
( V_284 [ V_298 ] !=
V_295 [ V_287 ] )
|| ( V_284 [ V_299 ] != V_287 ) ) {
F_5 ( V_9 -> V_16 , L_24 ,
V_17 , V_287 , V_289 , V_292 , V_10 ) ;
if ( ! V_10 )
V_10 = - V_110 ;
goto V_44;
}
if ( V_293 )
memcpy ( V_290 , & V_284 [ V_289 ] , V_291 ) ;
V_44:
if ( V_293 )
F_152 ( V_284 ) ;
return V_10 ;
}
static inline int F_153 ( struct V_8 * V_9 ,
enum V_283 V_287 ,
int V_288 ,
T_2 * V_106 ,
T_1 V_180 )
{
return F_150 ( V_9 , V_287 , V_288 , 0 , V_106 , V_180 ) ;
}
static inline int F_154 ( struct V_8 * V_9 ,
T_2 * V_106 ,
T_1 V_180 )
{
return F_153 ( V_9 , V_300 , 0 , V_106 , V_180 ) ;
}
static inline int F_155 ( struct V_8 * V_9 ,
int V_211 ,
enum V_301 V_289 ,
T_2 * V_290 ,
T_1 V_291 )
{
if ( V_211 != V_302 && ( V_211 >= V_303 ) )
return - V_304 ;
return F_150 ( V_9 , V_305 , V_211 ,
V_289 , V_290 , V_291 ) ;
}
static int F_156 ( struct V_8 * V_9 )
{
T_4 V_306 , V_307 , V_308 ;
V_308 = ( sizeof( struct V_309 ) * V_9 -> V_153 ) ;
V_9 -> V_310 = F_157 ( V_9 -> V_16 ,
V_308 ,
& V_9 -> V_311 ,
V_296 ) ;
if ( ! V_9 -> V_310 ||
F_99 ( V_9 -> V_311 & ( V_107 - 1 ) ) ) {
F_5 ( V_9 -> V_16 ,
L_25 ) ;
goto V_44;
}
V_307 = ( sizeof( struct V_192 ) * V_9 -> V_153 ) ;
V_9 -> V_312 = F_157 ( V_9 -> V_16 ,
V_307 ,
& V_9 -> V_313 ,
V_296 ) ;
if ( ! V_9 -> V_312 ||
F_99 ( V_9 -> V_313 & ( V_107 - 1 ) ) ) {
F_5 ( V_9 -> V_16 ,
L_26 ) ;
goto V_44;
}
V_306 = sizeof( struct V_40 ) * V_9 -> V_46 ;
V_9 -> V_314 = F_157 ( V_9 -> V_16 ,
V_306 ,
& V_9 -> V_315 ,
V_296 ) ;
if ( ! V_9 -> V_314 ||
F_99 ( V_9 -> V_315 & ( V_107 - 1 ) ) ) {
F_5 ( V_9 -> V_16 ,
L_27 ) ;
goto V_44;
}
V_9 -> V_244 = F_158 ( V_9 -> V_16 ,
V_9 -> V_153 * sizeof( struct V_34 ) ,
V_296 ) ;
if ( ! V_9 -> V_244 ) {
F_5 ( V_9 -> V_16 , L_28 ) ;
goto V_44;
}
return 0 ;
V_44:
return - V_297 ;
}
static void F_159 ( struct V_8 * V_9 )
{
struct V_309 * V_316 ;
struct V_192 * V_317 ;
T_6 V_318 ;
T_6 V_319 ;
T_5 V_320 ;
T_5 V_321 ;
int V_322 ;
int V_177 ;
V_317 = V_9 -> V_312 ;
V_316 = V_9 -> V_310 ;
V_320 =
F_160 ( struct V_309 , V_323 ) ;
V_321 =
F_160 ( struct V_309 , V_171 ) ;
V_322 = sizeof( struct V_309 ) ;
V_318 = V_9 -> V_311 ;
for ( V_177 = 0 ; V_177 < V_9 -> V_153 ; V_177 ++ ) {
V_319 =
( V_318 + ( V_322 * V_177 ) ) ;
V_317 [ V_177 ] . V_324 =
F_112 ( F_114 ( V_319 ) ) ;
V_317 [ V_177 ] . V_325 =
F_112 ( F_115 ( V_319 ) ) ;
V_317 [ V_177 ] . V_326 =
F_110 ( ( V_320 >> 2 ) ) ;
V_317 [ V_177 ] . V_327 =
F_110 ( ( V_321 >> 2 ) ) ;
V_317 [ V_177 ] . V_328 =
F_110 ( V_329 >> 2 ) ;
V_9 -> V_244 [ V_177 ] . V_36 = ( V_317 + V_177 ) ;
V_9 -> V_244 [ V_177 ] . V_209 =
(struct V_208 * ) ( V_316 + V_177 ) ;
V_9 -> V_244 [ V_177 ] . V_54 =
(struct V_53 * ) V_316 [ V_177 ] . V_323 ;
V_9 -> V_244 [ V_177 ] . V_179 =
(struct V_170 * ) V_316 [ V_177 ] . V_171 ;
}
}
static int F_161 ( struct V_8 * V_9 )
{
struct V_157 V_158 = { 0 } ;
int V_10 ;
V_158 . V_163 = V_330 ;
V_10 = F_104 ( V_9 , & V_158 ) ;
if ( V_10 )
F_5 ( V_9 -> V_16 ,
L_29 , V_10 ) ;
return V_10 ;
}
static inline void F_106 ( struct V_8 * V_9 )
{
#define F_162 1000
unsigned long V_331 ;
if ( ! ( V_9 -> V_332 & V_333 ) )
return;
if ( F_142 ( ! F_84 ( V_9 -> V_334 ) ) ) {
V_331 = F_162 ;
} else {
unsigned long V_335 =
( unsigned long ) F_84 (
F_85 ( F_82 () ,
V_9 -> V_334 ) ) ;
if ( V_335 < F_162 )
V_331 =
F_162 - V_335 ;
else
return;
}
F_11 ( V_331 , V_331 + 50 ) ;
}
int F_163 ( struct V_8 * V_9 , T_1 V_336 ,
T_2 V_337 , T_1 V_338 , T_2 V_339 )
{
struct V_157 V_158 = { 0 } ;
static const char * const V_340 [] = {
L_30 ,
L_31
} ;
const char * V_185 = V_340 [ ! ! V_339 ] ;
int V_10 ;
V_158 . V_163 = V_339 ?
V_341 : V_342 ;
V_158 . V_159 = V_336 ;
V_158 . V_161 = F_164 ( V_337 ) ;
V_158 . V_162 = V_338 ;
V_10 = F_104 ( V_9 , & V_158 ) ;
if ( V_10 )
F_5 ( V_9 -> V_16 , L_32 ,
V_185 , F_165 ( V_336 ) , V_338 , V_10 ) ;
return V_10 ;
}
int F_166 ( struct V_8 * V_9 , T_1 V_336 ,
T_1 * V_338 , T_2 V_339 )
{
struct V_157 V_158 = { 0 } ;
static const char * const V_340 [] = {
L_33 ,
L_34
} ;
const char * V_343 = V_340 [ ! ! V_339 ] ;
int V_10 ;
V_158 . V_163 = V_339 ?
V_344 : V_345 ;
V_158 . V_159 = V_336 ;
V_10 = F_104 ( V_9 , & V_158 ) ;
if ( V_10 ) {
F_5 ( V_9 -> V_16 , L_35 ,
V_343 , F_165 ( V_336 ) , V_10 ) ;
goto V_44;
}
if ( V_338 )
* V_338 = V_158 . V_162 ;
V_44:
return V_10 ;
}
static int F_167 ( struct V_8 * V_9 , struct V_157 * V_175 )
{
struct V_259 V_99 ;
unsigned long V_74 ;
T_2 V_346 ;
int V_10 ;
F_105 ( & V_9 -> V_169 ) ;
F_103 ( & V_99 ) ;
F_106 ( V_9 ) ;
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
V_9 -> V_99 = & V_99 ;
V_10 = F_102 ( V_9 , V_175 ) ;
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
if ( V_10 ) {
F_5 ( V_9 -> V_16 ,
L_36 ,
V_175 -> V_163 , V_175 -> V_162 , V_10 ) ;
goto V_44;
}
V_10 = F_100 ( V_9 , V_175 ) ;
if ( V_10 ) {
F_5 ( V_9 -> V_16 ,
L_36 ,
V_175 -> V_163 , V_175 -> V_162 , V_10 ) ;
goto V_44;
}
if ( ! F_101 ( V_9 -> V_99 ,
F_9 ( V_167 ) ) ) {
F_5 ( V_9 -> V_16 ,
L_37 ,
V_175 -> V_163 , V_175 -> V_162 ) ;
V_10 = - V_26 ;
goto V_44;
}
V_346 = F_97 ( V_9 ) ;
if ( V_346 != V_347 ) {
F_5 ( V_9 -> V_16 ,
L_38 ,
V_175 -> V_163 , V_346 ) ;
V_10 = ( V_346 != V_348 ) ? V_346 : - 1 ;
}
V_44:
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
V_9 -> V_99 = NULL ;
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
F_107 ( & V_9 -> V_169 ) ;
return V_10 ;
}
static int F_168 ( struct V_8 * V_9 , T_2 V_115 )
{
struct V_157 V_158 = { 0 } ;
int V_10 ;
V_158 . V_163 = V_342 ;
V_158 . V_159 = F_169 ( V_349 ) ;
V_158 . V_162 = V_115 ;
F_54 ( V_9 , false ) ;
V_10 = F_167 ( V_9 , & V_158 ) ;
F_68 ( V_9 ) ;
return V_10 ;
}
static int F_61 ( struct V_8 * V_9 )
{
struct V_157 V_158 = { 0 } ;
V_158 . V_163 = V_350 ;
return F_167 ( V_9 , & V_158 ) ;
}
static int F_49 ( struct V_8 * V_9 )
{
struct V_157 V_158 = { 0 } ;
int V_10 ;
V_158 . V_163 = V_351 ;
V_10 = F_167 ( V_9 , & V_158 ) ;
if ( V_10 ) {
F_170 ( V_9 ) ;
V_10 = F_171 ( V_9 ) ;
}
return V_10 ;
}
static void F_172 ( struct V_8 * V_9 )
{
V_9 -> V_352 . V_353 = V_354 ;
V_9 -> V_352 . V_355 = V_354 ;
V_9 -> V_352 . V_356 = 1 ;
V_9 -> V_352 . V_357 = 1 ;
V_9 -> V_352 . V_358 = V_359 ;
V_9 -> V_352 . V_360 = V_359 ;
V_9 -> V_352 . V_361 = 0 ;
}
static int F_173 ( struct V_8 * V_9 )
{
struct V_362 * V_352 = & V_9 -> V_363 . V_364 ;
if ( V_9 -> V_363 . V_365 )
return 0 ;
V_352 -> V_360 = V_366 ;
V_352 -> V_358 = V_366 ;
V_352 -> V_361 = V_367 ;
F_174 ( V_9 , F_169 ( V_368 ) ,
& V_352 -> V_356 ) ;
F_174 ( V_9 , F_169 ( V_369 ) ,
& V_352 -> V_357 ) ;
if ( ! V_352 -> V_356 || ! V_352 -> V_357 ) {
F_5 ( V_9 -> V_16 , L_39 ,
V_17 ,
V_352 -> V_356 ,
V_352 -> V_357 ) ;
return - V_110 ;
}
F_174 ( V_9 , F_169 ( V_370 ) , & V_352 -> V_353 ) ;
if ( ! V_352 -> V_353 ) {
F_174 ( V_9 , F_169 ( V_371 ) ,
& V_352 -> V_353 ) ;
if ( ! V_352 -> V_353 ) {
F_5 ( V_9 -> V_16 , L_40 ,
V_17 , V_352 -> V_353 ) ;
return - V_110 ;
}
V_352 -> V_358 = V_359 ;
}
F_175 ( V_9 , F_169 ( V_370 ) ,
& V_352 -> V_355 ) ;
if ( ! V_352 -> V_355 ) {
F_175 ( V_9 , F_169 ( V_371 ) ,
& V_352 -> V_355 ) ;
if ( ! V_352 -> V_355 ) {
F_5 ( V_9 -> V_16 , L_41 ,
V_17 , V_352 -> V_355 ) ;
return - V_110 ;
}
V_352 -> V_360 = V_359 ;
}
V_9 -> V_363 . V_365 = true ;
return 0 ;
}
static int F_176 ( struct V_8 * V_9 ,
struct V_362 * V_372 )
{
int V_10 ;
if ( V_372 -> V_353 == V_9 -> V_352 . V_353 &&
V_372 -> V_355 == V_9 -> V_352 . V_355 &&
V_372 -> V_356 == V_9 -> V_352 . V_356 &&
V_372 -> V_357 == V_9 -> V_352 . V_357 &&
V_372 -> V_358 == V_9 -> V_352 . V_358 &&
V_372 -> V_360 == V_9 -> V_352 . V_360 &&
V_372 -> V_361 == V_9 -> V_352 . V_361 ) {
F_177 ( V_9 -> V_16 , L_42 , V_17 ) ;
return 0 ;
}
F_178 ( V_9 , F_169 ( V_373 ) , V_372 -> V_353 ) ;
F_178 ( V_9 , F_169 ( V_374 ) ,
V_372 -> V_356 ) ;
if ( V_372 -> V_358 == V_366 ||
V_372 -> V_358 == V_375 )
F_178 ( V_9 , F_169 ( V_376 ) , TRUE ) ;
else
F_178 ( V_9 , F_169 ( V_376 ) , FALSE ) ;
F_178 ( V_9 , F_169 ( V_377 ) , V_372 -> V_355 ) ;
F_178 ( V_9 , F_169 ( V_378 ) ,
V_372 -> V_357 ) ;
if ( V_372 -> V_360 == V_366 ||
V_372 -> V_360 == V_375 )
F_178 ( V_9 , F_169 ( V_379 ) , TRUE ) ;
else
F_178 ( V_9 , F_169 ( V_379 ) , FALSE ) ;
if ( V_372 -> V_358 == V_366 ||
V_372 -> V_360 == V_366 ||
V_372 -> V_358 == V_375 ||
V_372 -> V_360 == V_375 )
F_178 ( V_9 , F_169 ( V_380 ) ,
V_372 -> V_361 ) ;
V_10 = F_168 ( V_9 , V_372 -> V_358 << 4
| V_372 -> V_360 ) ;
if ( V_10 ) {
F_5 ( V_9 -> V_16 ,
L_43 , V_17 , V_10 ) ;
} else {
if ( V_9 -> V_381 && V_9 -> V_381 -> V_382 )
V_9 -> V_381 -> V_382 ( V_9 ,
V_383 , NULL , V_372 ) ;
memcpy ( & V_9 -> V_352 , V_372 ,
sizeof( struct V_362 ) ) ;
}
return V_10 ;
}
static int F_179 ( struct V_8 * V_9 ,
struct V_362 * V_384 )
{
struct V_362 V_385 = { 0 } ;
int V_10 ;
if ( V_9 -> V_381 && V_9 -> V_381 -> V_382 )
V_9 -> V_381 -> V_382 ( V_9 ,
V_386 , V_384 , & V_385 ) ;
else
memcpy ( & V_385 , V_384 , sizeof( V_385 ) ) ;
V_10 = F_176 ( V_9 , & V_385 ) ;
return V_10 ;
}
static int F_180 ( struct V_8 * V_9 )
{
int V_177 , V_387 , V_23 = 0 ;
bool V_269 = 1 ;
for ( V_387 = V_388 ; V_387 > 0 ; V_387 -- ) {
V_23 = F_145 ( V_9 , V_271 ,
V_389 , NULL ) ;
if ( ! V_23 || V_23 == - V_26 )
break;
F_177 ( V_9 -> V_16 , L_44 , V_17 , V_23 ) ;
}
if ( V_23 ) {
F_5 ( V_9 -> V_16 ,
L_45 ,
V_17 , V_23 ) ;
goto V_44;
}
for ( V_177 = 0 ; V_177 < 100 && ! V_23 && V_269 ; V_177 ++ ) {
for ( V_387 = V_388 ; V_387 > 0 ; V_387 -- ) {
V_23 = F_145 ( V_9 ,
V_275 ,
V_389 , & V_269 ) ;
if ( ! V_23 || V_23 == - V_26 )
break;
F_177 ( V_9 -> V_16 , L_44 , V_17 ,
V_23 ) ;
}
}
if ( V_23 )
F_5 ( V_9 -> V_16 ,
L_46 ,
V_17 , V_23 ) ;
else if ( V_269 )
F_5 ( V_9 -> V_16 ,
L_47 ,
V_17 ) ;
V_44:
return V_23 ;
}
static int F_181 ( struct V_8 * V_9 )
{
int V_23 = 0 ;
T_1 V_18 ;
F_116 ( V_9 , V_390 ) ;
F_35 ( V_9 , V_9 -> V_153 - 1 , V_391 ) ;
F_25 ( V_9 , F_114 ( V_9 -> V_313 ) ,
V_392 ) ;
F_25 ( V_9 , F_115 ( V_9 -> V_313 ) ,
V_393 ) ;
F_25 ( V_9 , F_114 ( V_9 -> V_315 ) ,
V_394 ) ;
F_25 ( V_9 , F_115 ( V_9 -> V_315 ) ,
V_395 ) ;
V_18 = F_10 ( V_9 , V_32 ) ;
if ( ! ( F_26 ( V_18 ) ) ) {
F_38 ( V_9 ) ;
} else {
F_5 ( V_9 -> V_16 ,
L_48 ) ;
V_23 = - V_168 ;
goto V_44;
}
V_44:
return V_23 ;
}
static int F_182 ( struct V_8 * V_9 )
{
int V_396 ;
if ( ! F_40 ( V_9 ) ) {
F_183 ( V_9 ) ;
F_184 ( 5 ) ;
}
F_170 ( V_9 ) ;
if ( V_9 -> V_381 && V_9 -> V_381 -> V_397 )
V_9 -> V_381 -> V_397 ( V_9 , V_386 ) ;
F_39 ( V_9 ) ;
F_184 ( 1 ) ;
V_396 = 10 ;
while ( F_40 ( V_9 ) ) {
if ( V_396 ) {
V_396 -- ;
} else {
F_5 ( V_9 -> V_16 ,
L_49 ) ;
return - V_168 ;
}
F_184 ( 5 ) ;
}
F_116 ( V_9 , V_398 ) ;
if ( V_9 -> V_381 && V_9 -> V_381 -> V_397 )
V_9 -> V_381 -> V_397 ( V_9 , V_383 ) ;
return 0 ;
}
static int F_185 ( struct V_8 * V_9 )
{
int V_10 ;
int V_387 = V_399 ;
do {
if ( V_9 -> V_381 && V_9 -> V_381 -> V_400 )
V_9 -> V_381 -> V_400 ( V_9 , V_386 ) ;
V_10 = F_161 ( V_9 ) ;
if ( ! V_10 && ! F_15 ( V_9 ) ) {
F_5 ( V_9 -> V_16 , L_50 , V_17 ) ;
V_10 = - V_401 ;
goto V_44;
}
if ( V_10 && F_182 ( V_9 ) )
goto V_44;
} while ( V_10 && V_387 -- );
if ( V_10 )
goto V_44;
if ( V_9 -> V_381 && V_9 -> V_381 -> V_400 ) {
V_10 = V_9 -> V_381 -> V_400 ( V_9 , V_383 ) ;
if ( V_10 )
goto V_44;
}
V_10 = F_181 ( V_9 ) ;
V_44:
if ( V_10 )
F_5 ( V_9 -> V_16 , L_51 , V_10 ) ;
return V_10 ;
}
static int F_186 ( struct V_8 * V_9 )
{
int V_23 = 0 ;
int V_387 ;
F_54 ( V_9 , false ) ;
F_105 ( & V_9 -> V_134 . V_270 ) ;
for ( V_387 = V_402 ; V_387 > 0 ; V_387 -- ) {
V_23 = F_140 ( V_9 , V_228 ,
V_403 ) ;
if ( ! V_23 || V_23 == - V_26 )
break;
F_177 ( V_9 -> V_16 , L_44 , V_17 , V_23 ) ;
}
F_107 ( & V_9 -> V_134 . V_270 ) ;
F_68 ( V_9 ) ;
if ( V_23 )
F_5 ( V_9 -> V_16 , L_52 , V_17 , V_23 ) ;
return V_23 ;
}
static void F_187 ( struct V_404 * V_405 )
{
int V_10 = 0 ;
T_2 V_406 ;
struct V_8 * V_9 ;
V_9 = F_129 ( V_405 -> V_78 ) ;
V_406 = V_9 -> V_153 ;
V_10 = F_155 ( V_9 ,
F_125 ( V_405 -> V_211 ) ,
V_407 ,
& V_406 ,
sizeof( V_406 ) ) ;
if ( V_10 == - V_304 )
V_406 = 1 ;
else if ( ! V_406 )
V_406 = V_9 -> V_153 ;
else
V_406 = F_91 ( int , V_406 , V_9 -> V_153 ) ;
F_177 ( V_9 -> V_16 , L_53 ,
V_17 , V_406 ) ;
F_188 ( V_405 , V_406 ) ;
}
static int F_189 ( struct V_8 * V_9 ,
T_2 V_211 ,
T_2 * V_408 )
{
int V_10 ;
if ( ! V_408 )
V_10 = - V_110 ;
else if ( V_211 >= V_303 )
V_10 = - V_230 ;
else
V_10 = F_155 ( V_9 ,
V_211 ,
V_409 ,
V_408 ,
sizeof( * V_408 ) ) ;
return V_10 ;
}
static inline void F_190 ( struct V_8 * V_9 ,
struct V_404 * V_405 )
{
if ( V_9 -> V_410 . V_411 &&
! V_9 -> V_410 . V_412 ) {
T_2 V_408 ;
if ( ! F_189 ( V_9 , F_125 ( V_405 -> V_211 ) ,
& V_408 ) &&
( V_408 == V_413 ) )
V_9 -> V_410 . V_412 = true ;
}
}
static int F_191 ( struct V_404 * V_405 )
{
struct V_8 * V_9 ;
V_9 = F_129 ( V_405 -> V_78 ) ;
V_405 -> V_414 = 1 ;
V_405 -> V_415 = 1 ;
V_405 -> V_416 = 1 ;
F_187 ( V_405 ) ;
F_190 ( V_9 , V_405 ) ;
return 0 ;
}
static int F_192 ( struct V_404 * V_405 , int V_417 )
{
struct V_8 * V_9 = F_129 ( V_405 -> V_78 ) ;
if ( V_417 > V_9 -> V_153 )
V_417 = V_9 -> V_153 ;
return F_188 ( V_405 , V_417 ) ;
}
static int F_193 ( struct V_404 * V_405 )
{
struct V_418 * V_419 = V_405 -> V_418 ;
F_194 ( V_419 , V_420 - 1 ) ;
F_195 ( V_419 , V_421 ) ;
return 0 ;
}
static void F_196 ( struct V_404 * V_405 )
{
struct V_8 * V_9 ;
V_9 = F_129 ( V_405 -> V_78 ) ;
if ( F_125 ( V_405 -> V_211 ) == V_422 ) {
unsigned long V_74 ;
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
V_9 -> V_423 = NULL ;
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
}
}
static int F_197 ( struct V_8 * V_9 , T_1 V_266 , T_2 * V_249 )
{
struct V_40 * V_41 ;
struct V_424 * V_425 ;
unsigned long V_74 ;
int V_426 ;
int V_427 ;
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
F_198 ( V_266 , & V_9 -> V_97 ) ;
V_41 = V_9 -> V_314 ;
V_426 = F_18 ( & V_41 [ V_266 ] ) ;
if ( V_426 == V_428 ) {
V_425 = (struct V_424 * )
V_41 [ V_266 ] . V_429 ;
V_427 = F_30 ( V_425 -> V_37 . V_56 ) ;
V_427 = ( ( V_427 & V_430 ) >> 8 ) ;
if ( V_249 )
* V_249 = ( T_2 ) V_427 ;
} else {
F_5 ( V_9 -> V_16 , L_54 ,
V_17 , V_426 ) ;
}
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
return V_426 ;
}
static inline int
F_199 ( struct V_34 * V_35 , int V_431 )
{
int V_432 = 0 ;
switch ( V_431 ) {
case V_433 :
F_89 ( V_35 ) ;
case V_434 :
V_432 |= V_435 << 16 |
V_436 << 8 |
V_431 ;
break;
case V_437 :
case V_438 :
case V_439 :
F_89 ( V_35 ) ;
V_432 |= V_431 ;
break;
default:
V_432 |= V_241 << 16 ;
break;
}
return V_432 ;
}
static inline int
F_200 ( struct V_8 * V_9 , struct V_34 * V_35 )
{
int V_432 = 0 ;
int V_431 ;
int V_440 ;
V_440 = F_16 ( V_35 ) ;
switch ( V_440 ) {
case V_428 :
V_432 = F_29 ( V_35 -> V_54 ) ;
switch ( V_432 ) {
case V_441 :
V_432 = F_31 ( V_35 -> V_54 ) ;
V_431 = V_432 & V_442 ;
V_432 = F_199 ( V_35 , V_431 ) ;
if ( F_33 ( V_35 -> V_54 ) )
F_58 ( & V_9 -> V_443 ) ;
break;
case V_252 :
V_432 = V_241 << 16 ;
F_5 ( V_9 -> V_16 ,
L_55 ) ;
break;
default:
V_432 = V_241 << 16 ;
F_5 ( V_9 -> V_16 ,
L_56 ,
V_432 ) ;
break;
}
break;
case V_444 :
V_432 |= V_445 << 16 ;
break;
case V_207 :
V_432 |= V_446 << 16 ;
break;
case V_447 :
case V_448 :
case V_449 :
case V_450 :
case V_451 :
case V_452 :
default:
V_432 |= V_241 << 16 ;
F_5 ( V_9 -> V_16 ,
L_57 , V_440 ) ;
break;
}
return V_432 ;
}
static void F_201 ( struct V_8 * V_9 , T_1 V_453 )
{
if ( ( V_453 & V_454 ) && V_9 -> V_98 ) {
V_9 -> V_98 -> V_161 |=
F_27 ( V_9 ) ;
V_9 -> V_98 -> V_162 =
F_28 ( V_9 ) ;
V_256 ( & V_9 -> V_98 -> V_166 ) ;
}
if ( ( V_453 & V_455 ) && V_9 -> V_99 )
V_256 ( V_9 -> V_99 ) ;
}
static void F_202 ( struct V_8 * V_9 )
{
struct V_34 * V_35 ;
struct V_174 * V_175 ;
unsigned long V_456 ;
T_1 V_457 ;
int V_432 ;
int V_266 ;
F_34 ( V_9 ) ;
V_457 = F_10 ( V_9 , V_125 ) ;
V_456 = V_457 ^ V_9 -> V_122 ;
F_203 (index, &completed_reqs, hba->nutrs) {
V_35 = & V_9 -> V_244 [ V_266 ] ;
V_175 = V_35 -> V_175 ;
if ( V_175 ) {
V_432 = F_200 ( V_9 , V_35 ) ;
F_204 ( V_175 ) ;
V_175 -> V_432 = V_432 ;
V_35 -> V_175 = NULL ;
F_23 ( V_266 , & V_9 -> V_96 ) ;
V_175 -> V_242 ( V_175 ) ;
F_66 ( V_9 ) ;
} else if ( V_35 -> V_203 == V_225 ) {
if ( V_9 -> V_134 . V_256 )
V_256 ( V_9 -> V_134 . V_256 ) ;
}
}
V_9 -> V_122 ^= V_456 ;
F_83 ( V_9 ) ;
F_143 ( & V_9 -> V_134 . V_261 ) ;
}
static int F_205 ( struct V_8 * V_9 , T_5 V_19 )
{
int V_23 = 0 ;
T_1 V_20 ;
if ( ! ( V_9 -> V_458 & V_19 ) )
goto V_44;
V_20 = V_9 -> V_458 & ~ V_19 ;
V_20 &= 0xFFFF ;
V_23 = F_147 ( V_9 , V_281 ,
V_459 , 0 , 0 , & V_20 ) ;
if ( ! V_23 )
V_9 -> V_458 &= ~ V_19 ;
V_44:
return V_23 ;
}
static int F_206 ( struct V_8 * V_9 , T_5 V_19 )
{
int V_23 = 0 ;
T_1 V_20 ;
if ( V_9 -> V_458 & V_19 )
goto V_44;
V_20 = V_9 -> V_458 | V_19 ;
V_20 &= 0xFFFF ;
V_23 = F_147 ( V_9 , V_281 ,
V_459 , 0 , 0 , & V_20 ) ;
if ( ! V_23 )
V_9 -> V_458 |= V_19 ;
V_44:
return V_23 ;
}
static int F_207 ( struct V_8 * V_9 )
{
int V_23 = 0 ;
if ( V_9 -> V_460 )
goto V_44;
V_23 = F_145 ( V_9 , V_271 ,
V_461 , NULL ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_58 ,
V_17 , V_23 ) ;
goto V_44;
}
V_9 -> V_460 = true ;
V_23 = F_205 ( V_9 , V_462 ) ;
if ( V_23 )
F_5 ( V_9 -> V_16 , L_59 ,
V_17 , V_23 ) ;
V_44:
return V_23 ;
}
static int F_208 ( struct V_8 * V_9 )
{
int V_23 = 0 ;
if ( ! V_9 -> V_460 )
goto V_44;
V_23 = F_206 ( V_9 , V_462 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_60 ,
V_17 , V_23 ) ;
goto V_44;
}
V_23 = F_145 ( V_9 , V_272 ,
V_461 , NULL ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_61 ,
V_17 , V_23 ) ;
F_205 ( V_9 , V_462 ) ;
goto V_44;
}
V_9 -> V_460 = false ;
V_44:
return V_23 ;
}
static void F_209 ( struct V_8 * V_9 )
{
V_9 -> V_460 = false ;
V_9 -> V_458 |= V_462 ;
F_207 ( V_9 ) ;
}
static inline int F_210 ( struct V_8 * V_9 , T_1 * V_346 )
{
return F_147 ( V_9 , V_282 ,
V_463 , 0 , 0 , V_346 ) ;
}
static int F_211 ( struct V_8 * V_9 ,
enum V_464 V_346 )
{
int V_23 ;
T_1 V_465 = 0 ;
V_23 = F_210 ( V_9 , & V_465 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_62 ,
V_17 , V_23 ) ;
goto V_44;
} else if ( V_465 > V_466 ) {
F_5 ( V_9 -> V_16 , L_63 ,
V_17 , V_465 ) ;
V_23 = - V_110 ;
goto V_44;
}
if ( V_465 >= V_346 )
V_23 = F_207 ( V_9 ) ;
else
V_23 = F_208 ( V_9 ) ;
V_44:
return V_23 ;
}
static int F_212 ( struct V_8 * V_9 )
{
return F_211 ( V_9 , V_467 ) ;
}
static inline int F_213 ( struct V_8 * V_9 , T_1 * V_346 )
{
return F_147 ( V_9 , V_282 ,
V_468 , 0 , 0 , V_346 ) ;
}
static void F_214 ( struct V_72 * V_73 )
{
struct V_8 * V_9 ;
int V_23 ;
T_1 V_346 = 0 ;
V_9 = F_42 ( V_73 , struct V_8 , V_443 ) ;
F_215 ( V_9 -> V_16 ) ;
V_23 = F_213 ( V_9 , & V_346 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_64 ,
V_17 , V_23 ) ;
goto V_44;
}
V_346 &= V_9 -> V_458 ;
if ( V_346 & V_462 ) {
V_23 = F_212 ( V_9 ) ;
if ( V_23 < 0 )
F_5 ( V_9 -> V_16 , L_65 ,
V_17 , V_23 ) ;
}
V_44:
F_216 ( V_9 -> V_16 ) ;
return;
}
static void F_217 ( struct V_72 * V_73 )
{
struct V_8 * V_9 ;
unsigned long V_74 ;
T_1 V_469 = 0 ;
T_1 V_470 = 0 ;
int V_23 = 0 ;
int V_43 ;
V_9 = F_42 ( V_73 , struct V_8 , V_471 ) ;
F_215 ( V_9 -> V_16 ) ;
F_54 ( V_9 , false ) ;
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
if ( V_9 -> V_94 == V_237 ) {
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
goto V_44;
}
V_9 -> V_94 = V_237 ;
F_218 ( V_9 ) ;
F_202 ( V_9 ) ;
F_219 ( V_9 ) ;
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
F_203 (tag, &hba->outstanding_reqs, hba->nutrs)
if ( F_133 ( V_9 , V_43 ) )
V_469 |= 1 << V_43 ;
F_203 (tag, &hba->outstanding_tasks, hba->nutmrs)
if ( F_220 ( V_9 , V_43 ) )
V_470 |= 1 << V_43 ;
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
F_202 ( V_9 ) ;
F_219 ( V_9 ) ;
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
if ( V_469 || V_470 || ( V_9 -> V_472 & V_473 ) ||
( ( V_9 -> V_472 & V_474 ) &&
( V_9 -> V_475 & V_476 ) ) ) {
V_23 = F_221 ( V_9 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_66 ,
V_17 ) ;
V_9 -> V_94 = V_240 ;
}
F_222 ( V_9 -> V_78 , 0 ) ;
V_9 -> V_472 = 0 ;
V_9 -> V_475 = 0 ;
}
F_223 ( V_9 ) ;
V_44:
F_53 ( V_9 -> V_78 ) ;
F_68 ( V_9 ) ;
F_216 ( V_9 -> V_16 ) ;
}
static void F_224 ( struct V_8 * V_9 )
{
T_1 V_18 ;
V_18 = F_10 ( V_9 , V_477 ) ;
if ( V_18 & V_478 )
V_9 -> V_479 |= V_476 ;
V_18 = F_10 ( V_9 , V_480 ) ;
if ( V_18 )
V_9 -> V_479 |= V_481 ;
V_18 = F_10 ( V_9 , V_482 ) ;
if ( V_18 )
V_9 -> V_479 |= V_483 ;
V_18 = F_10 ( V_9 , V_484 ) ;
if ( V_18 )
V_9 -> V_479 |= V_485 ;
F_177 ( V_9 -> V_16 , L_67 ,
V_17 , V_9 -> V_479 ) ;
}
static void F_225 ( struct V_8 * V_9 )
{
bool V_486 = false ;
if ( V_9 -> V_487 & V_473 )
V_486 = true ;
if ( V_9 -> V_487 & V_474 ) {
V_9 -> V_479 = 0 ;
F_224 ( V_9 ) ;
if ( V_9 -> V_479 )
V_486 = true ;
}
if ( V_486 ) {
if ( V_9 -> V_94 == V_95 ) {
F_57 ( V_9 -> V_78 ) ;
V_9 -> V_472 |= V_9 -> V_487 ;
V_9 -> V_475 |= V_9 -> V_479 ;
V_9 -> V_94 = V_240 ;
F_58 ( & V_9 -> V_471 ) ;
}
}
}
static void F_219 ( struct V_8 * V_9 )
{
T_1 V_488 ;
V_488 = F_10 ( V_9 , V_489 ) ;
V_9 -> V_490 = V_488 ^ V_9 -> V_97 ;
F_143 ( & V_9 -> V_491 ) ;
}
static void F_226 ( struct V_8 * V_9 , T_1 V_453 )
{
V_9 -> V_487 = V_492 & V_453 ;
if ( V_9 -> V_487 )
F_225 ( V_9 ) ;
if ( V_453 & V_398 )
F_201 ( V_9 , V_453 ) ;
if ( V_453 & V_493 )
F_219 ( V_9 ) ;
if ( V_453 & V_494 )
F_202 ( V_9 ) ;
}
static T_7 V_13 ( int V_12 , void * V_495 )
{
T_1 V_453 ;
T_7 V_496 = V_497 ;
struct V_8 * V_9 = V_495 ;
F_227 ( V_9 -> V_78 -> V_79 ) ;
V_453 = F_10 ( V_9 , V_498 ) ;
if ( V_453 ) {
F_25 ( V_9 , V_453 , V_498 ) ;
F_226 ( V_9 , V_453 ) ;
V_496 = V_499 ;
}
F_228 ( V_9 -> V_78 -> V_79 ) ;
return V_496 ;
}
static int F_220 ( struct V_8 * V_9 , int V_43 )
{
int V_23 = 0 ;
T_1 V_19 = 1 << V_43 ;
unsigned long V_74 ;
if ( ! F_229 ( V_43 , & V_9 -> V_97 ) )
goto V_44;
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
F_25 ( V_9 , ~ ( 1 << V_43 ) , V_500 ) ;
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
V_23 = F_8 ( V_9 ,
V_489 ,
V_19 , 0 , 1000 , 1000 ) ;
V_44:
return V_23 ;
}
static int F_230 ( struct V_8 * V_9 , int V_501 , int V_502 ,
T_2 V_503 , T_2 * V_504 )
{
struct V_40 * V_41 ;
struct V_505 * V_506 ;
struct V_236 * V_78 ;
unsigned long V_74 ;
int V_42 ;
int V_23 ;
int V_124 ;
V_78 = V_9 -> V_78 ;
F_141 ( V_9 -> V_507 , F_19 ( V_9 , & V_42 ) ) ;
F_54 ( V_9 , false ) ;
F_44 ( V_78 -> V_79 , V_74 ) ;
V_41 = V_9 -> V_314 ;
V_41 += V_42 ;
V_41 -> V_37 . V_55 = F_112 ( V_206 ) ;
V_41 -> V_37 . V_38 =
F_112 ( V_207 ) ;
V_506 =
(struct V_505 * ) V_41 -> V_508 ;
V_124 = V_9 -> V_153 + V_42 ;
V_506 -> V_37 . V_55 =
F_120 ( V_509 , 0 ,
V_501 , V_124 ) ;
V_506 -> V_37 . V_56 =
F_120 ( 0 , V_503 , 0 , 0 ) ;
V_506 -> V_510 = F_121 ( V_501 ) ;
V_506 -> V_511 = F_121 ( V_502 ) ;
F_88 ( V_42 , & V_9 -> V_97 ) ;
F_25 ( V_9 , 1 << V_42 , V_489 ) ;
F_45 ( V_78 -> V_79 , V_74 ) ;
V_23 = F_231 ( V_9 -> V_491 ,
F_229 ( V_42 , & V_9 -> V_490 ) ,
F_9 ( V_512 ) ) ;
if ( ! V_23 ) {
F_5 ( V_9 -> V_16 , L_68 ,
V_17 , V_503 ) ;
if ( F_220 ( V_9 , V_42 ) )
F_232 ( V_9 -> V_16 , L_69 ,
V_17 , V_42 ) ;
V_23 = - V_26 ;
} else {
V_23 = F_197 ( V_9 , V_42 , V_504 ) ;
}
F_233 ( V_42 , & V_9 -> V_490 ) ;
F_22 ( V_9 , V_42 ) ;
F_143 ( & V_9 -> V_507 ) ;
F_68 ( V_9 ) ;
return V_23 ;
}
static int F_234 ( struct V_174 * V_175 )
{
struct V_236 * V_78 ;
struct V_8 * V_9 ;
unsigned int V_43 ;
T_1 V_48 ;
int V_23 ;
T_2 V_249 = 0xF ;
struct V_34 * V_35 ;
unsigned long V_74 ;
V_78 = V_175 -> V_103 -> V_78 ;
V_9 = F_129 ( V_78 ) ;
V_43 = V_175 -> V_147 -> V_43 ;
V_35 = & V_9 -> V_244 [ V_43 ] ;
V_23 = F_230 ( V_9 , V_35 -> V_211 , 0 , V_513 , & V_249 ) ;
if ( V_23 || V_249 != V_514 ) {
if ( ! V_23 )
V_23 = V_249 ;
goto V_44;
}
F_203 (pos, &hba->outstanding_reqs, hba->nutrs) {
if ( V_9 -> V_244 [ V_48 ] . V_211 == V_35 -> V_211 ) {
V_23 = F_133 ( V_9 , V_48 ) ;
if ( V_23 )
break;
}
}
F_44 ( V_78 -> V_79 , V_74 ) ;
F_202 ( V_9 ) ;
F_45 ( V_78 -> V_79 , V_74 ) ;
V_44:
if ( ! V_23 ) {
V_23 = V_515 ;
} else {
F_5 ( V_9 -> V_16 , L_70 , V_17 , V_23 ) ;
V_23 = V_516 ;
}
return V_23 ;
}
static int F_235 ( struct V_174 * V_175 )
{
struct V_236 * V_78 ;
struct V_8 * V_9 ;
unsigned long V_74 ;
unsigned int V_43 ;
int V_23 = 0 ;
int V_517 ;
T_2 V_249 = 0xF ;
struct V_34 * V_35 ;
T_1 V_18 ;
V_78 = V_175 -> V_103 -> V_78 ;
V_9 = F_129 ( V_78 ) ;
V_43 = V_175 -> V_147 -> V_43 ;
F_54 ( V_9 , false ) ;
if ( ! ( F_229 ( V_43 , & V_9 -> V_122 ) ) )
goto V_44;
V_18 = F_10 ( V_9 , V_125 ) ;
if ( ! ( V_18 & ( 1 << V_43 ) ) ) {
F_5 ( V_9 -> V_16 ,
L_71 ,
V_17 , V_43 ) ;
}
V_35 = & V_9 -> V_244 [ V_43 ] ;
for ( V_517 = 100 ; V_517 ; V_517 -- ) {
V_23 = F_230 ( V_9 , V_35 -> V_211 , V_35 -> V_124 ,
V_518 , & V_249 ) ;
if ( ! V_23 && V_249 == V_519 ) {
break;
} else if ( ! V_23 && V_249 == V_514 ) {
V_18 = F_10 ( V_9 , V_125 ) ;
if ( V_18 & ( 1 << V_43 ) ) {
F_11 ( 100 , 200 ) ;
continue;
}
goto V_44;
} else {
if ( ! V_23 )
V_23 = V_249 ;
goto V_44;
}
}
if ( ! V_517 ) {
V_23 = - V_520 ;
goto V_44;
}
V_23 = F_230 ( V_9 , V_35 -> V_211 , V_35 -> V_124 ,
V_521 , & V_249 ) ;
if ( V_23 || V_249 != V_514 ) {
if ( ! V_23 )
V_23 = V_249 ;
goto V_44;
}
V_23 = F_133 ( V_9 , V_43 ) ;
if ( V_23 )
goto V_44;
F_204 ( V_175 ) ;
F_44 ( V_78 -> V_79 , V_74 ) ;
F_198 ( V_43 , & V_9 -> V_122 ) ;
V_9 -> V_244 [ V_43 ] . V_175 = NULL ;
F_45 ( V_78 -> V_79 , V_74 ) ;
F_23 ( V_43 , & V_9 -> V_96 ) ;
F_143 ( & V_9 -> V_134 . V_261 ) ;
V_44:
if ( ! V_23 ) {
V_23 = V_515 ;
} else {
F_5 ( V_9 -> V_16 , L_70 , V_17 , V_23 ) ;
V_23 = V_516 ;
}
F_68 ( V_9 ) ;
return V_23 ;
}
static int F_171 ( struct V_8 * V_9 )
{
int V_23 ;
unsigned long V_74 ;
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
F_183 ( V_9 ) ;
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
V_23 = F_182 ( V_9 ) ;
if ( V_23 )
goto V_44;
V_23 = F_236 ( V_9 ) ;
if ( ! V_23 && ( V_9 -> V_94 != V_95 ) )
V_23 = - V_168 ;
V_44:
if ( V_23 )
F_5 ( V_9 -> V_16 , L_72 , V_17 , V_23 ) ;
return V_23 ;
}
static int F_221 ( struct V_8 * V_9 )
{
int V_23 = 0 ;
unsigned long V_74 ;
int V_387 = V_522 ;
do {
V_23 = F_171 ( V_9 ) ;
} while ( V_23 && -- V_387 );
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
F_202 ( V_9 ) ;
F_219 ( V_9 ) ;
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
return V_23 ;
}
static int F_237 ( struct V_174 * V_175 )
{
int V_23 ;
unsigned long V_74 ;
struct V_8 * V_9 ;
V_9 = F_129 ( V_175 -> V_103 -> V_78 ) ;
F_54 ( V_9 , false ) ;
do {
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
if ( ! ( F_238 ( & V_9 -> V_471 ) ||
V_9 -> V_94 == V_237 ) )
break;
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
F_177 ( V_9 -> V_16 , L_73 , V_17 ) ;
F_59 ( & V_9 -> V_471 ) ;
} while ( 1 );
V_9 -> V_94 = V_237 ;
F_218 ( V_9 ) ;
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
V_23 = F_221 ( V_9 ) ;
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
if ( ! V_23 ) {
V_23 = V_515 ;
V_9 -> V_94 = V_95 ;
} else {
V_23 = V_516 ;
V_9 -> V_94 = V_240 ;
}
F_223 ( V_9 ) ;
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
F_68 ( V_9 ) ;
return V_23 ;
}
static T_1 F_239 ( int V_523 , T_1 V_524 , char * V_525 )
{
int V_177 ;
int V_526 ;
T_5 V_527 ;
T_5 V_528 ;
for ( V_177 = V_524 ; V_177 >= 0 ; V_177 -- ) {
V_527 = F_90 ( * ( ( T_5 * ) ( V_525 + 2 * V_177 ) ) ) ;
V_528 = ( V_527 & V_529 ) >>
V_530 ;
V_526 = V_527 & V_531 ;
switch ( V_528 ) {
case V_532 :
V_526 = V_526 / 1000 ;
break;
case V_533 :
V_526 = V_526 * 1000 ;
break;
case V_534 :
V_526 = V_526 * 1000 * 1000 ;
break;
case V_535 :
default:
break;
}
if ( V_523 >= V_526 )
break;
}
if ( V_177 < 0 ) {
V_177 = 0 ;
F_240 ( L_74 , V_17 , V_177 ) ;
}
return ( T_1 ) V_177 ;
}
static T_1 F_241 ( struct V_8 * V_9 ,
T_2 * V_284 , int V_126 )
{
T_1 V_536 = 0 ;
if ( ! V_9 -> V_537 . V_538 || ! V_9 -> V_537 . V_539 ||
! V_9 -> V_537 . V_540 ) {
F_5 ( V_9 -> V_16 ,
L_75 ,
V_17 , V_536 ) ;
goto V_44;
}
if ( V_9 -> V_537 . V_538 )
V_536 = F_239 (
V_9 -> V_537 . V_538 -> V_541 ,
V_542 - 1 ,
& V_284 [ V_543 ] ) ;
if ( V_9 -> V_537 . V_539 )
V_536 = F_239 (
V_9 -> V_537 . V_539 -> V_541 ,
V_536 ,
& V_284 [ V_544 ] ) ;
if ( V_9 -> V_537 . V_540 )
V_536 = F_239 (
V_9 -> V_537 . V_540 -> V_541 ,
V_536 ,
& V_284 [ V_545 ] ) ;
V_44:
return V_536 ;
}
static void F_242 ( struct V_8 * V_9 )
{
int V_10 ;
int V_292 = V_546 ;
T_2 V_284 [ V_546 ] ;
V_10 = F_154 ( V_9 , V_284 , V_292 ) ;
if ( V_10 ) {
F_5 ( V_9 -> V_16 ,
L_76 ,
V_17 , V_292 , V_10 ) ;
return;
}
V_9 -> V_547 . V_536 =
F_241 ( V_9 ,
V_284 , V_292 ) ;
F_177 ( V_9 -> V_16 , L_77 ,
V_17 , V_9 -> V_547 . V_536 ) ;
V_10 = F_147 ( V_9 , V_281 ,
V_548 , 0 , 0 ,
& V_9 -> V_547 . V_536 ) ;
if ( V_10 )
F_5 ( V_9 -> V_16 ,
L_78 ,
V_17 , V_9 -> V_547 . V_536 , V_10 ) ;
}
static int F_243 ( struct V_8 * V_9 )
{
int V_10 = 0 ;
struct V_404 * V_549 ;
struct V_404 * V_550 ;
V_9 -> V_423 = F_244 ( V_9 -> V_78 , 0 , 0 ,
F_127 ( V_422 ) , NULL ) ;
if ( F_245 ( V_9 -> V_423 ) ) {
V_10 = F_246 ( V_9 -> V_423 ) ;
V_9 -> V_423 = NULL ;
goto V_44;
}
F_247 ( V_9 -> V_423 ) ;
V_550 = F_244 ( V_9 -> V_78 , 0 , 0 ,
F_127 ( V_551 ) , NULL ) ;
if ( F_245 ( V_550 ) ) {
V_10 = F_246 ( V_550 ) ;
goto V_552;
}
F_247 ( V_550 ) ;
V_549 = F_244 ( V_9 -> V_78 , 0 , 0 ,
F_127 ( V_302 ) , NULL ) ;
if ( F_245 ( V_549 ) ) {
V_10 = F_246 ( V_549 ) ;
goto V_553;
}
F_247 ( V_549 ) ;
goto V_44;
V_553:
F_248 ( V_550 ) ;
V_552:
F_248 ( V_9 -> V_423 ) ;
V_44:
return V_10 ;
}
static int F_236 ( struct V_8 * V_9 )
{
int V_10 ;
V_10 = F_185 ( V_9 ) ;
if ( V_10 )
goto V_44;
F_172 ( V_9 ) ;
F_50 ( V_9 ) ;
V_10 = F_186 ( V_9 ) ;
if ( V_10 )
goto V_44;
V_10 = F_180 ( V_9 ) ;
if ( V_10 )
goto V_44;
F_249 ( V_9 ) ;
F_209 ( V_9 ) ;
V_9 -> V_94 = V_95 ;
V_9 -> V_554 = true ;
if ( F_173 ( V_9 ) ) {
F_5 ( V_9 -> V_16 ,
L_79 ,
V_17 ) ;
} else {
V_10 = F_179 ( V_9 , & V_9 -> V_363 . V_364 ) ;
if ( V_10 )
F_5 ( V_9 -> V_16 , L_80 ,
V_17 , V_10 ) ;
}
if ( ! F_250 ( V_9 ) && ! V_9 -> V_555 ) {
bool V_556 ;
memset ( & V_9 -> V_410 , 0 , sizeof( V_9 -> V_410 ) ) ;
if ( ! F_145 ( V_9 , V_275 ,
V_557 , & V_556 ) )
V_9 -> V_410 . V_411 = V_556 ;
if ( ! V_9 -> V_558 )
F_242 ( V_9 ) ;
if ( F_243 ( V_9 ) )
goto V_44;
F_251 ( V_9 -> V_78 ) ;
F_216 ( V_9 -> V_16 ) ;
}
if ( ! V_9 -> V_558 )
V_9 -> V_558 = true ;
if ( F_51 ( V_9 ) )
F_52 ( V_9 -> V_84 ) ;
V_44:
if ( V_10 && ! F_250 ( V_9 ) && ! V_9 -> V_555 ) {
F_216 ( V_9 -> V_16 ) ;
F_252 ( V_9 ) ;
}
return V_10 ;
}
static void F_253 ( void * V_527 , T_8 V_559 )
{
struct V_8 * V_9 = (struct V_8 * ) V_527 ;
F_236 ( V_9 ) ;
}
static int F_254 ( struct V_103 * V_16 , struct V_560 * V_561 ,
int V_562 )
{
int V_10 ;
if ( ! V_561 )
return 0 ;
V_10 = F_255 ( V_561 -> V_18 , V_562 ) ;
if ( V_10 < 0 ) {
F_5 ( V_16 , L_81 ,
V_17 , V_561 -> V_114 , V_562 , V_10 ) ;
}
return V_10 ;
}
static inline int F_256 ( struct V_8 * V_9 ,
struct V_560 * V_561 )
{
return F_254 ( V_9 -> V_16 , V_561 , V_563 ) ;
}
static inline int F_257 ( struct V_8 * V_9 ,
struct V_560 * V_561 )
{
return F_254 ( V_9 -> V_16 , V_561 , V_561 -> V_541 ) ;
}
static int F_258 ( struct V_103 * V_16 ,
struct V_560 * V_561 , bool V_564 )
{
int V_10 = 0 ;
struct V_565 * V_18 = V_561 -> V_18 ;
const char * V_114 = V_561 -> V_114 ;
int V_566 , V_567 ;
F_146 ( ! V_561 ) ;
if ( F_259 ( V_18 ) > 0 ) {
V_566 = V_564 ? V_561 -> V_566 : 0 ;
V_10 = F_260 ( V_18 , V_566 , V_561 -> V_568 ) ;
if ( V_10 ) {
F_5 ( V_16 , L_82 ,
V_17 , V_114 , V_10 ) ;
goto V_44;
}
V_567 = V_564 ? V_561 -> V_541 : 0 ;
V_10 = F_254 ( V_16 , V_561 , V_567 ) ;
if ( V_10 )
goto V_44;
}
V_44:
return V_10 ;
}
static int F_261 ( struct V_103 * V_16 , struct V_560 * V_561 )
{
int V_10 = 0 ;
if ( ! V_561 || V_561 -> V_569 )
goto V_44;
V_10 = F_258 ( V_16 , V_561 , true ) ;
if ( ! V_10 )
V_10 = F_262 ( V_561 -> V_18 ) ;
if ( ! V_10 )
V_561 -> V_569 = true ;
else
F_5 ( V_16 , L_83 ,
V_17 , V_561 -> V_114 , V_10 ) ;
V_44:
return V_10 ;
}
static int F_263 ( struct V_103 * V_16 , struct V_560 * V_561 )
{
int V_10 = 0 ;
if ( ! V_561 || ! V_561 -> V_569 )
goto V_44;
V_10 = F_264 ( V_561 -> V_18 ) ;
if ( ! V_10 ) {
F_258 ( V_16 , V_561 , false ) ;
V_561 -> V_569 = false ;
} else {
F_5 ( V_16 , L_84 ,
V_17 , V_561 -> V_114 , V_10 ) ;
}
V_44:
return V_10 ;
}
static int F_265 ( struct V_8 * V_9 , bool V_564 )
{
int V_10 = 0 ;
struct V_103 * V_16 = V_9 -> V_16 ;
struct V_570 * V_364 = & V_9 -> V_537 ;
if ( ! V_364 )
goto V_44;
V_10 = F_266 ( V_16 , V_364 -> V_538 , V_564 ) ;
if ( V_10 )
goto V_44;
V_10 = F_266 ( V_16 , V_364 -> V_539 , V_564 ) ;
if ( V_10 )
goto V_44;
V_10 = F_266 ( V_16 , V_364 -> V_540 , V_564 ) ;
if ( V_10 )
goto V_44;
V_44:
if ( V_10 ) {
F_266 ( V_16 , V_364 -> V_540 , false ) ;
F_266 ( V_16 , V_364 -> V_539 , false ) ;
F_266 ( V_16 , V_364 -> V_538 , false ) ;
}
return V_10 ;
}
static int F_267 ( struct V_8 * V_9 , bool V_564 )
{
struct V_570 * V_364 = & V_9 -> V_537 ;
if ( V_364 )
return F_266 ( V_9 -> V_16 , V_364 -> V_571 , V_564 ) ;
return 0 ;
}
static int F_268 ( struct V_103 * V_16 , struct V_560 * V_561 )
{
int V_10 = 0 ;
if ( ! V_561 )
goto V_44;
V_561 -> V_18 = F_269 ( V_16 , V_561 -> V_114 ) ;
if ( F_245 ( V_561 -> V_18 ) ) {
V_10 = F_246 ( V_561 -> V_18 ) ;
F_5 ( V_16 , L_85 ,
V_17 , V_561 -> V_114 , V_10 ) ;
}
V_44:
return V_10 ;
}
static int F_270 ( struct V_8 * V_9 )
{
int V_10 = 0 ;
struct V_103 * V_16 = V_9 -> V_16 ;
struct V_570 * V_364 = & V_9 -> V_537 ;
if ( ! V_364 )
goto V_44;
V_10 = F_268 ( V_16 , V_364 -> V_538 ) ;
if ( V_10 )
goto V_44;
V_10 = F_268 ( V_16 , V_364 -> V_539 ) ;
if ( V_10 )
goto V_44;
V_10 = F_268 ( V_16 , V_364 -> V_540 ) ;
V_44:
return V_10 ;
}
static int F_271 ( struct V_8 * V_9 )
{
struct V_570 * V_364 = & V_9 -> V_537 ;
if ( V_364 )
return F_268 ( V_9 -> V_16 , V_364 -> V_571 ) ;
return 0 ;
}
static int F_65 ( struct V_8 * V_9 , bool V_564 ,
bool V_572 )
{
int V_10 = 0 ;
struct V_573 * V_574 ;
struct V_575 * V_576 = & V_9 -> V_577 ;
unsigned long V_74 ;
if ( ! V_576 || F_272 ( V_576 ) )
goto V_44;
F_273 (clki, head, list) {
if ( ! F_274 ( V_574 -> V_578 ) ) {
if ( V_572 && ! strcmp ( V_574 -> V_114 , L_86 ) )
continue;
if ( V_564 && ! V_574 -> V_569 ) {
V_10 = F_275 ( V_574 -> V_578 ) ;
if ( V_10 ) {
F_5 ( V_9 -> V_16 , L_87 ,
V_17 , V_574 -> V_114 , V_10 ) ;
goto V_44;
}
} else if ( ! V_564 && V_574 -> V_569 ) {
F_276 ( V_574 -> V_578 ) ;
}
V_574 -> V_569 = V_564 ;
F_177 ( V_9 -> V_16 , L_88 , V_17 ,
V_574 -> V_114 , V_564 ? L_89 : L_90 ) ;
}
}
if ( V_9 -> V_381 && V_9 -> V_381 -> V_579 )
V_10 = V_9 -> V_381 -> V_579 ( V_9 , V_564 ) ;
V_44:
if ( V_10 ) {
F_273 (clki, head, list) {
if ( ! F_274 ( V_574 -> V_578 ) && V_574 -> V_569 )
F_276 ( V_574 -> V_578 ) ;
}
} else if ( V_564 ) {
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
V_9 -> V_75 . V_80 = V_81 ;
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
}
return V_10 ;
}
static int F_46 ( struct V_8 * V_9 , bool V_564 )
{
return F_65 ( V_9 , V_564 , false ) ;
}
static int F_277 ( struct V_8 * V_9 )
{
int V_10 = 0 ;
struct V_573 * V_574 ;
struct V_103 * V_16 = V_9 -> V_16 ;
struct V_575 * V_576 = & V_9 -> V_577 ;
if ( ! V_576 || F_272 ( V_576 ) )
goto V_44;
F_273 (clki, head, list) {
if ( ! V_574 -> V_114 )
continue;
V_574 -> V_578 = F_278 ( V_16 , V_574 -> V_114 ) ;
if ( F_245 ( V_574 -> V_578 ) ) {
V_10 = F_246 ( V_574 -> V_578 ) ;
F_5 ( V_16 , L_91 ,
V_17 , V_574 -> V_114 , V_10 ) ;
goto V_44;
}
if ( V_574 -> V_580 ) {
V_10 = F_279 ( V_574 -> V_578 , V_574 -> V_580 ) ;
if ( V_10 ) {
F_5 ( V_9 -> V_16 , L_92 ,
V_17 , V_574 -> V_114 ,
V_574 -> V_580 , V_10 ) ;
goto V_44;
}
V_574 -> V_581 = V_574 -> V_580 ;
}
F_177 ( V_16 , L_93 , V_17 ,
V_574 -> V_114 , F_280 ( V_574 -> V_578 ) ) ;
}
V_44:
return V_10 ;
}
static int F_281 ( struct V_8 * V_9 )
{
int V_23 = 0 ;
if ( ! V_9 -> V_381 )
goto V_44;
if ( V_9 -> V_381 -> V_582 ) {
V_23 = V_9 -> V_381 -> V_582 ( V_9 ) ;
if ( V_23 )
goto V_44;
}
if ( V_9 -> V_381 -> V_583 ) {
V_23 = V_9 -> V_381 -> V_583 ( V_9 , true ) ;
if ( V_23 )
goto V_584;
}
goto V_44;
V_584:
if ( V_9 -> V_381 -> exit )
V_9 -> V_381 -> exit ( V_9 ) ;
V_44:
if ( V_23 )
F_5 ( V_9 -> V_16 , L_94 ,
V_17 , V_9 -> V_381 ? V_9 -> V_381 -> V_114 : L_95 , V_23 ) ;
return V_23 ;
}
static void F_282 ( struct V_8 * V_9 )
{
if ( ! V_9 -> V_381 )
return;
if ( V_9 -> V_381 -> V_579 )
V_9 -> V_381 -> V_579 ( V_9 , false ) ;
if ( V_9 -> V_381 -> V_583 )
V_9 -> V_381 -> V_583 ( V_9 , false ) ;
if ( V_9 -> V_381 -> exit )
V_9 -> V_381 -> exit ( V_9 ) ;
}
static int F_283 ( struct V_8 * V_9 )
{
int V_23 ;
V_23 = F_271 ( V_9 ) ;
if ( V_23 )
goto V_44;
V_23 = F_267 ( V_9 , true ) ;
if ( V_23 )
goto V_44;
V_23 = F_277 ( V_9 ) ;
if ( V_23 )
goto V_585;
V_23 = F_46 ( V_9 , true ) ;
if ( V_23 )
goto V_585;
V_23 = F_270 ( V_9 ) ;
if ( V_23 )
goto V_586;
V_23 = F_265 ( V_9 , true ) ;
if ( V_23 )
goto V_586;
V_23 = F_281 ( V_9 ) ;
if ( V_23 )
goto V_587;
V_9 -> V_588 = true ;
goto V_44;
V_587:
F_265 ( V_9 , false ) ;
V_586:
F_46 ( V_9 , false ) ;
V_585:
F_267 ( V_9 , false ) ;
V_44:
return V_23 ;
}
static void F_252 ( struct V_8 * V_9 )
{
if ( V_9 -> V_588 ) {
F_282 ( V_9 ) ;
F_265 ( V_9 , false ) ;
F_46 ( V_9 , false ) ;
F_267 ( V_9 , false ) ;
V_9 -> V_588 = false ;
}
}
static int
F_284 ( struct V_8 * V_9 , struct V_404 * V_589 )
{
unsigned char V_175 [ 6 ] = { V_590 ,
0 ,
0 ,
0 ,
V_131 ,
0 } ;
char * V_591 ;
int V_10 ;
V_591 = F_285 ( V_131 , V_296 ) ;
if ( ! V_591 ) {
V_10 = - V_297 ;
goto V_44;
}
V_10 = F_286 ( V_589 , V_175 , V_195 , V_591 ,
V_131 , NULL ,
F_9 ( 1000 ) , 3 , NULL , V_592 ) ;
if ( V_10 )
F_240 ( L_70 , V_17 , V_10 ) ;
F_152 ( V_591 ) ;
V_44:
return V_10 ;
}
static int F_287 ( struct V_8 * V_9 ,
enum V_1 V_372 )
{
unsigned char V_175 [ 6 ] = { V_593 } ;
struct V_594 V_595 ;
struct V_404 * V_589 ;
unsigned long V_74 ;
int V_10 ;
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
V_589 = V_9 -> V_423 ;
if ( V_589 ) {
V_10 = F_288 ( V_589 ) ;
if ( ! V_10 && ! F_289 ( V_589 ) ) {
V_10 = - V_596 ;
F_247 ( V_589 ) ;
}
} else {
V_10 = - V_596 ;
}
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
if ( V_10 )
return V_10 ;
V_9 -> V_78 -> V_597 = 1 ;
if ( V_9 -> V_554 ) {
V_10 = F_284 ( V_9 , V_589 ) ;
if ( V_10 )
goto V_44;
V_9 -> V_554 = false ;
}
V_175 [ 4 ] = V_372 << 4 ;
V_10 = F_286 ( V_589 , V_175 , V_226 , NULL , 0 , & V_595 ,
V_598 , 0 , NULL , V_592 ) ;
if ( V_10 ) {
F_290 ( V_599 , V_589 ,
L_96 ,
V_372 , V_10 ) ;
if ( F_291 ( V_10 ) & V_600 )
F_292 ( V_589 , NULL , & V_595 ) ;
}
if ( ! V_10 )
V_9 -> V_601 = V_372 ;
V_44:
F_247 ( V_589 ) ;
V_9 -> V_78 -> V_597 = 0 ;
return V_10 ;
}
static int F_293 ( struct V_8 * V_9 ,
enum V_6 V_602 ,
int V_603 )
{
int V_10 = 0 ;
if ( V_602 == V_9 -> V_6 )
return 0 ;
if ( V_602 == V_604 ) {
V_10 = F_61 ( V_9 ) ;
if ( ! V_10 )
F_62 ( V_9 ) ;
else
goto V_44;
}
else if ( ( V_602 == V_605 ) &&
( ! V_603 || ( V_603 &&
! V_9 -> V_460 ) ) ) {
F_183 ( V_9 ) ;
F_170 ( V_9 ) ;
}
V_44:
return V_10 ;
}
static void F_294 ( struct V_8 * V_9 )
{
if ( F_295 ( V_9 ) && F_296 ( V_9 ) &&
! V_9 -> V_410 . V_412 ) {
F_265 ( V_9 , false ) ;
} else if ( ! F_297 ( V_9 ) ) {
F_266 ( V_9 -> V_16 , V_9 -> V_537 . V_538 , false ) ;
if ( ! F_64 ( V_9 ) ) {
F_256 ( V_9 , V_9 -> V_537 . V_539 ) ;
F_256 ( V_9 , V_9 -> V_537 . V_540 ) ;
}
}
}
static int F_298 ( struct V_8 * V_9 )
{
int V_10 = 0 ;
if ( F_295 ( V_9 ) && F_296 ( V_9 ) &&
! V_9 -> V_410 . V_412 ) {
V_10 = F_265 ( V_9 , true ) ;
} else if ( ! F_297 ( V_9 ) ) {
V_10 = F_266 ( V_9 -> V_16 , V_9 -> V_537 . V_538 , true ) ;
if ( ! V_10 && ! F_64 ( V_9 ) ) {
V_10 = F_257 ( V_9 , V_9 -> V_537 . V_539 ) ;
if ( V_10 )
goto V_606;
V_10 = F_257 ( V_9 , V_9 -> V_537 . V_540 ) ;
if ( V_10 )
goto V_607;
}
}
goto V_44;
V_607:
F_256 ( V_9 , V_9 -> V_537 . V_539 ) ;
V_606:
F_266 ( V_9 -> V_16 , V_9 -> V_537 . V_538 , false ) ;
V_44:
return V_10 ;
}
static void F_299 ( struct V_8 * V_9 )
{
if ( F_296 ( V_9 ) )
F_267 ( V_9 , false ) ;
}
static void F_300 ( struct V_8 * V_9 )
{
if ( F_296 ( V_9 ) )
F_267 ( V_9 , true ) ;
}
static int F_301 ( struct V_8 * V_9 , enum V_608 V_609 )
{
int V_10 = 0 ;
enum V_2 V_610 ;
enum V_1 V_611 ;
enum V_6 V_602 ;
V_9 -> V_555 = 1 ;
if ( ! F_302 ( V_609 ) ) {
V_610 = F_303 ( V_609 ) ?
V_9 -> V_612 : V_9 -> V_613 ;
V_611 = F_1 ( V_610 ) ;
V_602 = F_2 ( V_610 ) ;
} else {
V_611 = V_614 ;
V_602 = V_605 ;
}
F_54 ( V_9 , false ) ;
V_9 -> V_75 . V_83 = true ;
if ( V_611 == V_615 &&
V_602 == V_616 ) {
goto V_617;
}
if ( ( V_611 == V_9 -> V_601 ) &&
( V_602 == V_9 -> V_6 ) )
goto V_44;
if ( ! F_297 ( V_9 ) || ! F_64 ( V_9 ) ) {
V_10 = - V_110 ;
goto V_44;
}
if ( F_303 ( V_609 ) ) {
if ( F_304 ( V_9 ) ) {
V_10 = F_212 ( V_9 ) ;
if ( V_10 )
goto V_618;
} else {
F_208 ( V_9 ) ;
}
}
if ( ( V_611 != V_9 -> V_601 ) &&
( ( F_303 ( V_609 ) && ! V_9 -> V_460 ) ||
! F_303 ( V_609 ) ) ) {
F_208 ( V_9 ) ;
V_10 = F_287 ( V_9 , V_611 ) ;
if ( V_10 )
goto V_618;
}
V_10 = F_293 ( V_9 , V_602 , 1 ) ;
if ( V_10 )
goto V_619;
F_294 ( V_9 ) ;
V_617:
if ( F_51 ( V_9 ) ) {
F_63 ( V_9 -> V_84 ) ;
V_9 -> V_100 . V_101 = 0 ;
}
if ( V_9 -> V_381 && V_9 -> V_381 -> V_620 ) {
V_10 = V_9 -> V_381 -> V_620 ( V_9 , V_609 ) ;
if ( V_10 )
goto V_621;
}
if ( V_9 -> V_381 && V_9 -> V_381 -> V_579 ) {
V_10 = V_9 -> V_381 -> V_579 ( V_9 , false ) ;
if ( V_10 )
goto V_622;
}
if ( ! F_64 ( V_9 ) )
F_46 ( V_9 , false ) ;
else
F_65 ( V_9 , false , true ) ;
V_9 -> V_75 . V_80 = V_90 ;
F_6 ( V_9 ) ;
F_299 ( V_9 ) ;
goto V_44;
V_622:
if ( V_9 -> V_381 && V_9 -> V_381 -> V_623 )
V_9 -> V_381 -> V_623 ( V_9 , V_609 ) ;
V_621:
F_298 ( V_9 ) ;
if ( F_48 ( V_9 ) && ! F_49 ( V_9 ) )
F_50 ( V_9 ) ;
else if ( F_296 ( V_9 ) )
F_171 ( V_9 ) ;
V_619:
if ( ! F_287 ( V_9 , V_615 ) )
F_208 ( V_9 ) ;
V_618:
V_9 -> V_75 . V_83 = false ;
F_68 ( V_9 ) ;
V_44:
V_9 -> V_555 = 0 ;
return V_10 ;
}
static int F_305 ( struct V_8 * V_9 , enum V_608 V_609 )
{
int V_10 ;
enum V_6 V_624 ;
V_9 -> V_555 = 1 ;
V_624 = V_9 -> V_6 ;
F_300 ( V_9 ) ;
V_10 = F_46 ( V_9 , true ) ;
if ( V_10 )
goto V_44;
V_10 = F_3 ( V_9 ) ;
if ( V_10 )
goto V_625;
V_10 = F_298 ( V_9 ) ;
if ( V_10 )
goto V_625;
if ( V_9 -> V_381 && V_9 -> V_381 -> V_623 ) {
V_10 = V_9 -> V_381 -> V_623 ( V_9 , V_609 ) ;
if ( V_10 )
goto V_626;
}
if ( F_48 ( V_9 ) ) {
V_10 = F_49 ( V_9 ) ;
if ( ! V_10 )
F_50 ( V_9 ) ;
else
goto V_627;
} else if ( F_296 ( V_9 ) ) {
V_10 = F_171 ( V_9 ) ;
if ( V_10 || ! F_64 ( V_9 ) )
goto V_627;
}
if ( ! F_297 ( V_9 ) ) {
V_10 = F_287 ( V_9 , V_615 ) ;
if ( V_10 )
goto V_628;
}
F_212 ( V_9 ) ;
V_9 -> V_75 . V_83 = false ;
if ( F_51 ( V_9 ) )
F_52 ( V_9 -> V_84 ) ;
F_68 ( V_9 ) ;
goto V_44;
V_628:
F_293 ( V_9 , V_624 , 0 ) ;
V_627:
if ( V_9 -> V_381 && V_9 -> V_381 -> V_620 )
V_9 -> V_381 -> V_620 ( V_9 , V_609 ) ;
V_626:
F_294 ( V_9 ) ;
V_625:
F_6 ( V_9 ) ;
F_46 ( V_9 , false ) ;
V_44:
V_9 -> V_555 = 0 ;
return V_10 ;
}
int F_306 ( struct V_8 * V_9 )
{
int V_10 = 0 ;
if ( ! V_9 || ! V_9 -> V_588 )
return 0 ;
if ( F_307 ( V_9 -> V_16 ) ) {
if ( V_9 -> V_612 == V_9 -> V_613 )
if ( ( F_1 ( V_9 -> V_613 ) ==
V_9 -> V_601 ) && ! V_9 -> V_460 )
goto V_44;
V_10 = F_308 ( V_9 ) ;
if ( V_10 )
goto V_44;
}
V_10 = F_301 ( V_9 , V_629 ) ;
V_44:
if ( ! V_10 )
V_9 -> V_630 = true ;
return V_10 ;
}
int F_309 ( struct V_8 * V_9 )
{
if ( ! V_9 || ! V_9 -> V_588 || F_307 ( V_9 -> V_16 ) )
return 0 ;
return F_305 ( V_9 , V_629 ) ;
}
int F_310 ( struct V_8 * V_9 )
{
if ( ! V_9 || ! V_9 -> V_588 )
return 0 ;
return F_301 ( V_9 , V_631 ) ;
}
int F_308 ( struct V_8 * V_9 )
{
if ( ! V_9 || ! V_9 -> V_588 )
return 0 ;
else
return F_305 ( V_9 , V_631 ) ;
}
int F_311 ( struct V_8 * V_9 )
{
return 0 ;
}
int F_312 ( struct V_8 * V_9 )
{
int V_10 = 0 ;
if ( F_295 ( V_9 ) && F_296 ( V_9 ) )
goto V_44;
if ( F_307 ( V_9 -> V_16 ) ) {
V_10 = F_308 ( V_9 ) ;
if ( V_10 )
goto V_44;
}
V_10 = F_301 ( V_9 , V_632 ) ;
V_44:
if ( V_10 )
F_5 ( V_9 -> V_16 , L_97 , V_17 , V_10 ) ;
return 0 ;
}
void F_313 ( struct V_8 * V_9 )
{
F_314 ( V_9 -> V_78 ) ;
F_117 ( V_9 , V_9 -> V_633 ) ;
F_183 ( V_9 ) ;
F_315 ( V_9 -> V_78 ) ;
F_78 ( V_9 ) ;
if ( F_51 ( V_9 ) )
F_316 ( V_9 -> V_84 ) ;
F_252 ( V_9 ) ;
}
static int F_317 ( struct V_8 * V_9 )
{
if ( V_9 -> V_151 & V_634 ) {
if ( ! F_318 ( V_9 -> V_16 , F_319 ( 64 ) ) )
return 0 ;
}
return F_318 ( V_9 -> V_16 , F_319 ( 32 ) ) ;
}
int F_320 ( struct V_103 * V_16 , struct V_8 * * V_635 )
{
struct V_236 * V_78 ;
struct V_8 * V_9 ;
int V_23 = 0 ;
if ( ! V_16 ) {
F_5 ( V_16 ,
L_98 ) ;
V_23 = - V_596 ;
goto V_636;
}
V_78 = F_321 ( & V_637 ,
sizeof( struct V_8 ) ) ;
if ( ! V_78 ) {
F_5 ( V_16 , L_99 ) ;
V_23 = - V_297 ;
goto V_636;
}
V_9 = F_129 ( V_78 ) ;
V_9 -> V_78 = V_78 ;
V_9 -> V_16 = V_16 ;
* V_635 = V_9 ;
V_636:
return V_23 ;
}
static int F_322 ( struct V_8 * V_9 , bool V_638 )
{
int V_10 = 0 ;
struct V_573 * V_574 ;
struct V_575 * V_576 = & V_9 -> V_577 ;
if ( ! V_576 || F_272 ( V_576 ) )
goto V_44;
F_273 (clki, head, list) {
if ( ! F_274 ( V_574 -> V_578 ) ) {
if ( V_638 && V_574 -> V_580 ) {
if ( V_574 -> V_581 == V_574 -> V_580 )
continue;
V_10 = F_279 ( V_574 -> V_578 , V_574 -> V_580 ) ;
if ( V_10 ) {
F_5 ( V_9 -> V_16 , L_92 ,
V_17 , V_574 -> V_114 ,
V_574 -> V_580 , V_10 ) ;
break;
}
V_574 -> V_581 = V_574 -> V_580 ;
} else if ( ! V_638 && V_574 -> V_639 ) {
if ( V_574 -> V_581 == V_574 -> V_639 )
continue;
V_10 = F_279 ( V_574 -> V_578 , V_574 -> V_639 ) ;
if ( V_10 ) {
F_5 ( V_9 -> V_16 , L_92 ,
V_17 , V_574 -> V_114 ,
V_574 -> V_639 , V_10 ) ;
break;
}
V_574 -> V_581 = V_574 -> V_639 ;
}
}
F_177 ( V_9 -> V_16 , L_93 , V_17 ,
V_574 -> V_114 , F_280 ( V_574 -> V_578 ) ) ;
}
if ( V_9 -> V_381 -> V_640 )
V_9 -> V_381 -> V_640 ( V_9 ) ;
V_44:
return V_10 ;
}
static int F_323 ( struct V_103 * V_16 ,
unsigned long * V_641 , T_1 V_74 )
{
int V_23 = 0 ;
struct V_8 * V_9 = F_70 ( V_16 ) ;
if ( ! F_51 ( V_9 ) )
return - V_110 ;
if ( * V_641 == V_642 )
V_23 = F_322 ( V_9 , true ) ;
else if ( * V_641 == 0 )
V_23 = F_322 ( V_9 , false ) ;
return V_23 ;
}
static int F_324 ( struct V_103 * V_16 ,
struct V_643 * V_644 )
{
struct V_8 * V_9 = F_70 ( V_16 ) ;
struct V_120 * V_121 = & V_9 -> V_100 ;
unsigned long V_74 ;
if ( ! F_51 ( V_9 ) )
return - V_110 ;
memset ( V_644 , 0 , sizeof( * V_644 ) ) ;
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
if ( ! V_121 -> V_101 )
goto V_645;
if ( V_121 -> V_118 )
V_121 -> V_123 += F_84 ( F_85 ( F_82 () ,
V_121 -> V_119 ) ) ;
V_644 -> V_646 = F_325 ( ( long ) V_25 -
( long ) V_121 -> V_101 ) ;
V_644 -> V_647 = V_121 -> V_123 ;
V_645:
V_121 -> V_101 = V_25 ;
V_121 -> V_123 = 0 ;
if ( V_9 -> V_122 ) {
V_121 -> V_119 = F_82 () ;
V_121 -> V_118 = true ;
} else {
V_121 -> V_119 = F_86 ( 0 , 0 ) ;
V_121 -> V_118 = false ;
}
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
return 0 ;
}
int F_326 ( struct V_8 * V_9 , void T_9 * V_648 , unsigned int V_12 )
{
int V_23 ;
struct V_236 * V_78 = V_9 -> V_78 ;
struct V_103 * V_16 = V_9 -> V_16 ;
if ( ! V_648 ) {
F_5 ( V_9 -> V_16 ,
L_100 ) ;
V_23 = - V_596 ;
goto V_636;
}
V_9 -> V_648 = V_648 ;
V_9 -> V_12 = V_12 ;
V_23 = F_283 ( V_9 ) ;
if ( V_23 )
goto V_636;
F_95 ( V_9 ) ;
V_9 -> V_27 = F_14 ( V_9 ) ;
V_9 -> V_633 = F_13 ( V_9 ) ;
V_23 = F_317 ( V_9 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_101 ) ;
goto V_649;
}
V_23 = F_156 ( V_9 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_102 ) ;
goto V_649;
}
F_159 ( V_9 ) ;
V_78 -> V_650 = V_9 -> V_153 ;
V_78 -> V_651 = V_9 -> V_153 ;
V_78 -> V_652 = V_653 ;
V_78 -> V_654 = V_655 ;
V_78 -> V_656 = V_657 ;
V_78 -> V_658 = V_78 -> V_659 ;
V_78 -> V_660 = V_661 ;
V_9 -> V_363 . V_365 = false ;
F_327 ( & V_9 -> V_491 ) ;
F_327 ( & V_9 -> V_507 ) ;
F_75 ( & V_9 -> V_471 , F_217 ) ;
F_75 ( & V_9 -> V_443 , F_214 ) ;
F_328 ( & V_9 -> V_169 ) ;
F_328 ( & V_9 -> V_134 . V_270 ) ;
F_327 ( & V_9 -> V_134 . V_261 ) ;
F_73 ( V_9 ) ;
V_23 = F_329 ( V_16 , V_12 , V_13 , V_14 , V_15 , V_9 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_103 ) ;
goto V_662;
} else {
V_9 -> V_11 = true ;
}
V_23 = F_330 ( V_78 , V_78 -> V_650 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_104 ) ;
goto V_662;
}
V_23 = F_331 ( V_78 , V_9 -> V_16 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_105 ) ;
goto V_662;
}
V_23 = F_182 ( V_9 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_106 ) ;
goto V_663;
}
if ( F_51 ( V_9 ) ) {
V_9 -> V_84 = F_332 ( V_16 , & V_664 ,
L_107 , NULL ) ;
if ( F_245 ( V_9 -> V_84 ) ) {
F_5 ( V_9 -> V_16 , L_108 ,
F_246 ( V_9 -> V_84 ) ) ;
goto V_663;
}
F_63 ( V_9 -> V_84 ) ;
V_9 -> V_100 . V_101 = 0 ;
}
F_215 ( V_16 ) ;
F_333 ( V_9 ) ;
F_334 ( F_253 , V_9 ) ;
return 0 ;
V_663:
F_314 ( V_9 -> V_78 ) ;
V_662:
F_78 ( V_9 ) ;
V_649:
V_9 -> V_11 = false ;
F_315 ( V_78 ) ;
F_252 ( V_9 ) ;
V_636:
return V_23 ;
}

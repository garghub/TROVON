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
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
V_10 = F_102 ( V_9 , V_158 ) ;
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
if ( ! V_10 )
V_10 = F_100 ( V_9 , V_158 ) ;
F_106 ( & V_9 -> V_169 ) ;
F_68 ( V_9 ) ;
return V_10 ;
}
static int F_107 ( struct V_34 * V_35 )
{
struct V_170 * V_171 ;
struct V_172 * V_173 ;
struct V_174 * V_175 ;
int V_176 ;
int V_177 ;
V_175 = V_35 -> V_175 ;
V_176 = F_108 ( V_175 ) ;
if ( V_176 < 0 )
return V_176 ;
if ( V_176 ) {
V_35 -> V_36 -> V_178 =
F_109 ( ( T_5 ) ( V_176 ) ) ;
V_171 = (struct V_170 * ) V_35 -> V_179 ;
F_110 (cmd, sg, sg_segments, i) {
V_171 [ V_177 ] . V_180 =
F_111 ( ( ( T_1 ) F_112 ( V_173 ) ) - 1 ) ;
V_171 [ V_177 ] . V_181 =
F_111 ( F_113 ( V_173 -> V_182 ) ) ;
V_171 [ V_177 ] . V_183 =
F_111 ( F_114 ( V_173 -> V_182 ) ) ;
}
} else {
V_35 -> V_36 -> V_178 = 0 ;
}
return 0 ;
}
static void F_115 ( struct V_8 * V_9 , T_1 V_184 )
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
static void F_116 ( struct V_8 * V_9 , T_1 V_184 )
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
static void F_117 ( struct V_34 * V_35 ,
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
V_193 -> V_37 . V_55 = F_111 ( V_55 ) ;
V_193 -> V_37 . V_38 =
F_111 ( V_207 ) ;
}
static
void F_118 ( struct V_34 * V_35 , T_1 V_189 )
{
struct V_208 * V_209 = V_35 -> V_209 ;
V_209 -> V_37 . V_55 = F_119 (
V_210 , V_189 ,
V_35 -> V_211 , V_35 -> V_124 ) ;
V_209 -> V_37 . V_56 = F_119 (
V_212 , 0 , 0 , 0 ) ;
V_209 -> V_37 . V_38 = 0 ;
V_209 -> V_213 . V_214 =
F_120 ( V_35 -> V_175 -> V_215 . V_149 ) ;
memcpy ( V_209 -> V_213 . V_216 , V_35 -> V_175 -> V_217 ,
( F_91 (unsigned short, lrbp->cmd->cmd_len, MAX_CDB_SIZE) ) ) ;
}
static void F_121 ( struct V_8 * V_9 ,
struct V_34 * V_35 , T_1 V_189 )
{
struct V_208 * V_209 = V_35 -> V_209 ;
struct V_218 * V_135 = & V_9 -> V_134 . V_135 ;
T_5 V_126 = F_90 ( V_135 -> V_147 . V_148 . V_149 ) ;
T_2 * V_142 = ( T_2 * ) V_35 -> V_209 + V_143 ;
V_209 -> V_37 . V_55 = F_119 (
V_219 , V_189 ,
V_35 -> V_211 , V_35 -> V_124 ) ;
V_209 -> V_37 . V_56 = F_119 (
0 , V_135 -> V_147 . V_220 , 0 , 0 ) ;
V_209 -> V_37 . V_38 = F_119 (
0 , 0 , V_126 >> 8 , ( T_2 ) V_126 ) ;
memcpy ( & V_209 -> V_138 , & V_135 -> V_147 . V_148 ,
V_139 ) ;
if ( V_135 -> V_147 . V_148 . V_140 == V_221 )
memcpy ( V_142 , V_135 -> V_150 , V_126 ) ;
}
static inline void F_122 ( struct V_34 * V_35 )
{
struct V_208 * V_209 = V_35 -> V_209 ;
memset ( V_209 , 0 , sizeof( struct V_208 ) ) ;
V_209 -> V_37 . V_55 =
F_119 (
V_222 , 0 , 0 , V_35 -> V_124 ) ;
}
static int F_123 ( struct V_8 * V_9 , struct V_34 * V_35 )
{
T_1 V_189 ;
int V_10 = 0 ;
switch ( V_35 -> V_203 ) {
case V_223 :
if ( F_93 ( V_35 -> V_175 ) ) {
F_117 ( V_35 , & V_189 ,
V_35 -> V_175 -> V_224 ) ;
F_118 ( V_35 , V_189 ) ;
} else {
V_10 = - V_110 ;
}
break;
case V_225 :
F_117 ( V_35 , & V_189 , V_226 ) ;
if ( V_9 -> V_134 . type == V_227 )
F_121 (
V_9 , V_35 , V_189 ) ;
else if ( V_9 -> V_134 . type == V_228 )
F_122 ( V_35 ) ;
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
static inline T_2 F_124 ( unsigned int V_231 )
{
if ( F_125 ( V_231 ) )
return ( V_231 & V_232 )
| V_233 ;
else
return V_231 & V_232 ;
}
static inline T_5 F_126 ( T_2 V_234 )
{
return ( V_234 & ~ V_233 ) | V_235 ;
}
static int F_127 ( struct V_236 * V_78 , struct V_174 * V_175 )
{
struct V_34 * V_35 ;
struct V_8 * V_9 ;
unsigned long V_74 ;
int V_43 ;
int V_23 = 0 ;
V_9 = F_128 ( V_78 ) ;
V_43 = V_175 -> V_147 -> V_43 ;
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
switch ( V_9 -> V_94 ) {
case V_95 :
break;
case V_237 :
V_23 = V_238 ;
goto V_239;
case V_240 :
F_129 ( V_175 , V_241 ) ;
V_175 -> V_242 ( V_175 ) ;
goto V_239;
default:
F_130 ( V_9 -> V_16 , 1 , L_11 ,
V_17 , V_9 -> V_94 ) ;
F_129 ( V_175 , V_243 ) ;
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
V_35 -> V_211 = F_124 ( V_175 -> V_103 -> V_211 ) ;
V_35 -> V_205 = false ;
V_35 -> V_203 = V_223 ;
F_123 ( V_9 , V_35 ) ;
V_23 = F_107 ( V_35 ) ;
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
static int F_131 ( struct V_8 * V_9 ,
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
return F_123 ( V_9 , V_35 ) ;
}
static int
F_132 ( struct V_8 * V_9 , int V_43 )
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
F_133 ( struct V_8 * V_9 , struct V_34 * V_35 )
{
struct V_132 * V_133 = & V_9 -> V_134 . V_135 . V_136 ;
V_133 -> V_136 = F_31 ( V_35 -> V_54 ) >>
V_248 ;
return V_133 -> V_136 ;
}
static int
F_134 ( struct V_8 * V_9 , struct V_34 * V_35 )
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
V_23 = F_133 ( V_9 , V_35 ) ;
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
static int F_135 ( struct V_8 * V_9 ,
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
V_23 = F_134 ( V_9 , V_35 ) ;
}
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
if ( ! V_255 ) {
V_23 = - V_26 ;
if ( ! F_132 ( V_9 , V_35 -> V_124 ) )
V_23 = - V_92 ;
}
return V_23 ;
}
static bool F_136 ( struct V_8 * V_9 , int * V_257 )
{
int V_43 ;
bool V_10 = false ;
unsigned long V_258 ;
if ( ! V_257 )
goto V_44;
do {
V_258 = ~ V_9 -> V_96 ;
V_43 = F_137 ( & V_258 , V_9 -> V_153 ) ;
if ( V_43 >= V_9 -> V_153 )
goto V_44;
} while ( F_21 ( V_43 , & V_9 -> V_96 ) );
* V_257 = V_43 ;
V_10 = true ;
V_44:
return V_10 ;
}
static inline void F_138 ( struct V_8 * V_9 , int V_43 )
{
F_23 ( V_43 , & V_9 -> V_96 ) ;
}
static int F_139 ( struct V_8 * V_9 ,
enum V_246 V_247 , int V_24 )
{
struct V_34 * V_35 ;
int V_23 ;
int V_43 ;
struct V_259 V_260 ;
unsigned long V_74 ;
F_140 ( V_9 -> V_134 . V_261 , F_136 ( V_9 , & V_43 ) ) ;
F_103 ( & V_260 ) ;
V_35 = & V_9 -> V_244 [ V_43 ] ;
F_99 ( V_35 -> V_175 ) ;
V_23 = F_131 ( V_9 , V_35 , V_247 , V_43 ) ;
if ( F_141 ( V_23 ) )
goto V_262;
V_9 -> V_134 . V_256 = & V_260 ;
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
F_87 ( V_9 , V_43 ) ;
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
V_23 = F_135 ( V_9 , V_35 , V_24 ) ;
V_262:
F_138 ( V_9 , V_43 ) ;
F_142 ( & V_9 -> V_134 . V_261 ) ;
return V_23 ;
}
static inline void F_143 ( struct V_8 * V_9 ,
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
static int F_144 ( struct V_8 * V_9 , enum V_264 V_140 ,
enum V_268 V_265 , bool * V_269 )
{
struct V_263 * V_147 = NULL ;
struct V_132 * V_136 = NULL ;
int V_23 , V_266 = 0 , V_267 = 0 ;
F_145 ( ! V_9 ) ;
F_54 ( V_9 , false ) ;
F_105 ( & V_9 -> V_134 . V_270 ) ;
F_143 ( V_9 , & V_147 , & V_136 , V_140 , V_265 , V_266 ,
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
V_23 = F_139 ( V_9 , V_227 , V_277 ) ;
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
F_106 ( & V_9 -> V_134 . V_270 ) ;
F_68 ( V_9 ) ;
return V_23 ;
}
static int F_146 ( struct V_8 * V_9 , enum V_264 V_140 ,
enum V_279 V_265 , T_2 V_266 , T_2 V_267 , T_1 * V_280 )
{
struct V_263 * V_147 = NULL ;
struct V_132 * V_136 = NULL ;
int V_23 ;
F_145 ( ! V_9 ) ;
F_54 ( V_9 , false ) ;
if ( ! V_280 ) {
F_5 ( V_9 -> V_16 , L_18 ,
V_17 , V_140 ) ;
V_23 = - V_110 ;
goto V_44;
}
F_105 ( & V_9 -> V_134 . V_270 ) ;
F_143 ( V_9 , & V_147 , & V_136 , V_140 , V_265 , V_266 ,
V_267 ) ;
switch ( V_140 ) {
case V_281 :
V_147 -> V_220 = V_274 ;
V_147 -> V_148 . V_109 = F_120 ( * V_280 ) ;
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
V_23 = F_139 ( V_9 , V_227 , V_277 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_20 ,
V_17 , V_140 , V_265 , V_23 ) ;
goto V_239;
}
* V_280 = F_30 ( V_136 -> V_137 . V_109 ) ;
V_239:
F_106 ( & V_9 -> V_134 . V_270 ) ;
V_44:
F_68 ( V_9 ) ;
return V_23 ;
}
static int F_147 ( struct V_8 * V_9 ,
enum V_264 V_140 , enum V_283 V_265 , T_2 V_266 ,
T_2 V_267 , T_2 * V_284 , int * V_145 )
{
struct V_263 * V_147 = NULL ;
struct V_132 * V_136 = NULL ;
int V_23 ;
F_145 ( ! V_9 ) ;
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
F_143 ( V_9 , & V_147 , & V_136 , V_140 , V_265 , V_266 ,
V_267 ) ;
V_9 -> V_134 . V_135 . V_150 = V_284 ;
V_147 -> V_148 . V_149 = F_148 ( * V_145 ) ;
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
V_23 = F_139 ( V_9 , V_227 , V_277 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_20 ,
V_17 , V_140 , V_265 , V_23 ) ;
goto V_239;
}
V_9 -> V_134 . V_135 . V_150 = NULL ;
* V_145 = F_90 ( V_136 -> V_137 . V_149 ) ;
V_239:
F_106 ( & V_9 -> V_134 . V_270 ) ;
V_44:
F_68 ( V_9 ) ;
return V_23 ;
}
static int F_149 ( struct V_8 * V_9 ,
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
V_284 = F_150 ( V_292 , V_296 ) ;
if ( ! V_284 )
return - V_297 ;
}
V_10 = F_147 ( V_9 , V_141 ,
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
F_151 ( V_284 ) ;
return V_10 ;
}
static inline int F_152 ( struct V_8 * V_9 ,
enum V_283 V_287 ,
int V_288 ,
T_2 * V_106 ,
T_1 V_180 )
{
return F_149 ( V_9 , V_287 , V_288 , 0 , V_106 , V_180 ) ;
}
static inline int F_153 ( struct V_8 * V_9 ,
T_2 * V_106 ,
T_1 V_180 )
{
return F_152 ( V_9 , V_300 , 0 , V_106 , V_180 ) ;
}
static inline int F_154 ( struct V_8 * V_9 ,
int V_211 ,
enum V_301 V_289 ,
T_2 * V_290 ,
T_1 V_291 )
{
if ( V_211 != V_302 && ( V_211 >= V_303 ) )
return - V_304 ;
return F_149 ( V_9 , V_305 , V_211 ,
V_289 , V_290 , V_291 ) ;
}
static int F_155 ( struct V_8 * V_9 )
{
T_4 V_306 , V_307 , V_308 ;
V_308 = ( sizeof( struct V_309 ) * V_9 -> V_153 ) ;
V_9 -> V_310 = F_156 ( V_9 -> V_16 ,
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
V_9 -> V_312 = F_156 ( V_9 -> V_16 ,
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
V_9 -> V_314 = F_156 ( V_9 -> V_16 ,
V_306 ,
& V_9 -> V_315 ,
V_296 ) ;
if ( ! V_9 -> V_314 ||
F_99 ( V_9 -> V_315 & ( V_107 - 1 ) ) ) {
F_5 ( V_9 -> V_16 ,
L_27 ) ;
goto V_44;
}
V_9 -> V_244 = F_157 ( V_9 -> V_16 ,
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
static void F_158 ( struct V_8 * V_9 )
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
F_159 ( struct V_309 , V_323 ) ;
V_321 =
F_159 ( struct V_309 , V_171 ) ;
V_322 = sizeof( struct V_309 ) ;
V_318 = V_9 -> V_311 ;
for ( V_177 = 0 ; V_177 < V_9 -> V_153 ; V_177 ++ ) {
V_319 =
( V_318 + ( V_322 * V_177 ) ) ;
V_317 [ V_177 ] . V_324 =
F_111 ( F_113 ( V_319 ) ) ;
V_317 [ V_177 ] . V_325 =
F_111 ( F_114 ( V_319 ) ) ;
V_317 [ V_177 ] . V_326 =
F_109 ( ( V_320 >> 2 ) ) ;
V_317 [ V_177 ] . V_327 =
F_109 ( ( V_321 >> 2 ) ) ;
V_317 [ V_177 ] . V_328 =
F_109 ( V_329 >> 2 ) ;
V_9 -> V_244 [ V_177 ] . V_36 = ( V_317 + V_177 ) ;
V_9 -> V_244 [ V_177 ] . V_209 =
(struct V_208 * ) ( V_316 + V_177 ) ;
V_9 -> V_244 [ V_177 ] . V_54 =
(struct V_53 * ) V_316 [ V_177 ] . V_323 ;
V_9 -> V_244 [ V_177 ] . V_179 =
(struct V_170 * ) V_316 [ V_177 ] . V_171 ;
}
}
static int F_160 ( struct V_8 * V_9 )
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
int F_161 ( struct V_8 * V_9 , T_1 V_331 ,
T_2 V_332 , T_1 V_333 , T_2 V_334 )
{
struct V_157 V_158 = { 0 } ;
static const char * const V_335 [] = {
L_30 ,
L_31
} ;
const char * V_185 = V_335 [ ! ! V_334 ] ;
int V_10 ;
V_158 . V_163 = V_334 ?
V_336 : V_337 ;
V_158 . V_159 = V_331 ;
V_158 . V_161 = F_162 ( V_332 ) ;
V_158 . V_162 = V_333 ;
V_10 = F_104 ( V_9 , & V_158 ) ;
if ( V_10 )
F_5 ( V_9 -> V_16 , L_32 ,
V_185 , F_163 ( V_331 ) , V_333 , V_10 ) ;
return V_10 ;
}
int F_164 ( struct V_8 * V_9 , T_1 V_331 ,
T_1 * V_333 , T_2 V_334 )
{
struct V_157 V_158 = { 0 } ;
static const char * const V_335 [] = {
L_33 ,
L_34
} ;
const char * V_338 = V_335 [ ! ! V_334 ] ;
int V_10 ;
V_158 . V_163 = V_334 ?
V_339 : V_340 ;
V_158 . V_159 = V_331 ;
V_10 = F_104 ( V_9 , & V_158 ) ;
if ( V_10 ) {
F_5 ( V_9 -> V_16 , L_35 ,
V_338 , F_163 ( V_331 ) , V_10 ) ;
goto V_44;
}
if ( V_333 )
* V_333 = V_158 . V_162 ;
V_44:
return V_10 ;
}
static int F_165 ( struct V_8 * V_9 , struct V_157 * V_175 )
{
struct V_259 V_99 ;
unsigned long V_74 ;
T_2 V_341 ;
int V_10 ;
F_105 ( & V_9 -> V_169 ) ;
F_103 ( & V_99 ) ;
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
V_341 = F_97 ( V_9 ) ;
if ( V_341 != V_342 ) {
F_5 ( V_9 -> V_16 ,
L_38 ,
V_175 -> V_163 , V_341 ) ;
V_10 = ( V_341 != V_343 ) ? V_341 : - 1 ;
}
V_44:
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
V_9 -> V_99 = NULL ;
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
F_106 ( & V_9 -> V_169 ) ;
return V_10 ;
}
static int F_166 ( struct V_8 * V_9 , T_2 V_115 )
{
struct V_157 V_158 = { 0 } ;
int V_10 ;
V_158 . V_163 = V_337 ;
V_158 . V_159 = F_167 ( V_344 ) ;
V_158 . V_162 = V_115 ;
F_54 ( V_9 , false ) ;
V_10 = F_165 ( V_9 , & V_158 ) ;
F_68 ( V_9 ) ;
return V_10 ;
}
static int F_61 ( struct V_8 * V_9 )
{
struct V_157 V_158 = { 0 } ;
V_158 . V_163 = V_345 ;
return F_165 ( V_9 , & V_158 ) ;
}
static int F_49 ( struct V_8 * V_9 )
{
struct V_157 V_158 = { 0 } ;
int V_10 ;
V_158 . V_163 = V_346 ;
V_10 = F_165 ( V_9 , & V_158 ) ;
if ( V_10 ) {
F_168 ( V_9 ) ;
V_10 = F_169 ( V_9 ) ;
}
return V_10 ;
}
static void F_170 ( struct V_8 * V_9 )
{
V_9 -> V_347 . V_348 = V_349 ;
V_9 -> V_347 . V_350 = V_349 ;
V_9 -> V_347 . V_351 = 1 ;
V_9 -> V_347 . V_352 = 1 ;
V_9 -> V_347 . V_353 = V_354 ;
V_9 -> V_347 . V_355 = V_354 ;
V_9 -> V_347 . V_356 = 0 ;
}
static int F_171 ( struct V_8 * V_9 )
{
struct V_357 * V_347 = & V_9 -> V_358 . V_359 ;
if ( V_9 -> V_358 . V_360 )
return 0 ;
V_347 -> V_355 = V_361 ;
V_347 -> V_353 = V_361 ;
V_347 -> V_356 = V_362 ;
F_172 ( V_9 , F_167 ( V_363 ) ,
& V_347 -> V_351 ) ;
F_172 ( V_9 , F_167 ( V_364 ) ,
& V_347 -> V_352 ) ;
if ( ! V_347 -> V_351 || ! V_347 -> V_352 ) {
F_5 ( V_9 -> V_16 , L_39 ,
V_17 ,
V_347 -> V_351 ,
V_347 -> V_352 ) ;
return - V_110 ;
}
F_172 ( V_9 , F_167 ( V_365 ) , & V_347 -> V_348 ) ;
if ( ! V_347 -> V_348 ) {
F_172 ( V_9 , F_167 ( V_366 ) ,
& V_347 -> V_348 ) ;
if ( ! V_347 -> V_348 ) {
F_5 ( V_9 -> V_16 , L_40 ,
V_17 , V_347 -> V_348 ) ;
return - V_110 ;
}
V_347 -> V_353 = V_354 ;
}
F_173 ( V_9 , F_167 ( V_365 ) ,
& V_347 -> V_350 ) ;
if ( ! V_347 -> V_350 ) {
F_173 ( V_9 , F_167 ( V_366 ) ,
& V_347 -> V_350 ) ;
if ( ! V_347 -> V_350 ) {
F_5 ( V_9 -> V_16 , L_41 ,
V_17 , V_347 -> V_350 ) ;
return - V_110 ;
}
V_347 -> V_355 = V_354 ;
}
V_9 -> V_358 . V_360 = true ;
return 0 ;
}
static int F_174 ( struct V_8 * V_9 ,
struct V_357 * V_367 )
{
int V_10 ;
if ( V_367 -> V_348 == V_9 -> V_347 . V_348 &&
V_367 -> V_350 == V_9 -> V_347 . V_350 &&
V_367 -> V_351 == V_9 -> V_347 . V_351 &&
V_367 -> V_352 == V_9 -> V_347 . V_352 &&
V_367 -> V_353 == V_9 -> V_347 . V_353 &&
V_367 -> V_355 == V_9 -> V_347 . V_355 &&
V_367 -> V_356 == V_9 -> V_347 . V_356 ) {
F_175 ( V_9 -> V_16 , L_42 , V_17 ) ;
return 0 ;
}
F_176 ( V_9 , F_167 ( V_368 ) , V_367 -> V_348 ) ;
F_176 ( V_9 , F_167 ( V_369 ) ,
V_367 -> V_351 ) ;
if ( V_367 -> V_353 == V_361 ||
V_367 -> V_353 == V_370 )
F_176 ( V_9 , F_167 ( V_371 ) , TRUE ) ;
else
F_176 ( V_9 , F_167 ( V_371 ) , FALSE ) ;
F_176 ( V_9 , F_167 ( V_372 ) , V_367 -> V_350 ) ;
F_176 ( V_9 , F_167 ( V_373 ) ,
V_367 -> V_352 ) ;
if ( V_367 -> V_355 == V_361 ||
V_367 -> V_355 == V_370 )
F_176 ( V_9 , F_167 ( V_374 ) , TRUE ) ;
else
F_176 ( V_9 , F_167 ( V_374 ) , FALSE ) ;
if ( V_367 -> V_353 == V_361 ||
V_367 -> V_355 == V_361 ||
V_367 -> V_353 == V_370 ||
V_367 -> V_355 == V_370 )
F_176 ( V_9 , F_167 ( V_375 ) ,
V_367 -> V_356 ) ;
V_10 = F_166 ( V_9 , V_367 -> V_353 << 4
| V_367 -> V_355 ) ;
if ( V_10 ) {
F_5 ( V_9 -> V_16 ,
L_43 , V_17 , V_10 ) ;
} else {
if ( V_9 -> V_376 && V_9 -> V_376 -> V_377 )
V_9 -> V_376 -> V_377 ( V_9 ,
V_378 , NULL , V_367 ) ;
memcpy ( & V_9 -> V_347 , V_367 ,
sizeof( struct V_357 ) ) ;
}
return V_10 ;
}
static int F_177 ( struct V_8 * V_9 ,
struct V_357 * V_379 )
{
struct V_357 V_380 = { 0 } ;
int V_10 ;
if ( V_9 -> V_376 && V_9 -> V_376 -> V_377 )
V_9 -> V_376 -> V_377 ( V_9 ,
V_381 , V_379 , & V_380 ) ;
else
memcpy ( & V_380 , V_379 , sizeof( V_380 ) ) ;
V_10 = F_174 ( V_9 , & V_380 ) ;
return V_10 ;
}
static int F_178 ( struct V_8 * V_9 )
{
int V_177 , V_382 , V_23 = 0 ;
bool V_269 = 1 ;
for ( V_382 = V_383 ; V_382 > 0 ; V_382 -- ) {
V_23 = F_144 ( V_9 , V_271 ,
V_384 , NULL ) ;
if ( ! V_23 || V_23 == - V_26 )
break;
F_175 ( V_9 -> V_16 , L_44 , V_17 , V_23 ) ;
}
if ( V_23 ) {
F_5 ( V_9 -> V_16 ,
L_45 ,
V_17 , V_23 ) ;
goto V_44;
}
for ( V_177 = 0 ; V_177 < 100 && ! V_23 && V_269 ; V_177 ++ ) {
for ( V_382 = V_383 ; V_382 > 0 ; V_382 -- ) {
V_23 = F_144 ( V_9 ,
V_275 ,
V_384 , & V_269 ) ;
if ( ! V_23 || V_23 == - V_26 )
break;
F_175 ( V_9 -> V_16 , L_44 , V_17 ,
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
static int F_179 ( struct V_8 * V_9 )
{
int V_23 = 0 ;
T_1 V_18 ;
F_115 ( V_9 , V_385 ) ;
F_35 ( V_9 , V_9 -> V_153 - 1 , V_386 ) ;
F_25 ( V_9 , F_113 ( V_9 -> V_313 ) ,
V_387 ) ;
F_25 ( V_9 , F_114 ( V_9 -> V_313 ) ,
V_388 ) ;
F_25 ( V_9 , F_113 ( V_9 -> V_315 ) ,
V_389 ) ;
F_25 ( V_9 , F_114 ( V_9 -> V_315 ) ,
V_390 ) ;
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
static int F_180 ( struct V_8 * V_9 )
{
int V_391 ;
if ( ! F_40 ( V_9 ) ) {
F_181 ( V_9 ) ;
F_182 ( 5 ) ;
}
F_168 ( V_9 ) ;
if ( V_9 -> V_376 && V_9 -> V_376 -> V_392 )
V_9 -> V_376 -> V_392 ( V_9 , V_381 ) ;
F_39 ( V_9 ) ;
F_182 ( 1 ) ;
V_391 = 10 ;
while ( F_40 ( V_9 ) ) {
if ( V_391 ) {
V_391 -- ;
} else {
F_5 ( V_9 -> V_16 ,
L_49 ) ;
return - V_168 ;
}
F_182 ( 5 ) ;
}
F_115 ( V_9 , V_393 ) ;
if ( V_9 -> V_376 && V_9 -> V_376 -> V_392 )
V_9 -> V_376 -> V_392 ( V_9 , V_378 ) ;
return 0 ;
}
static int F_183 ( struct V_8 * V_9 )
{
int V_10 ;
int V_382 = V_394 ;
do {
if ( V_9 -> V_376 && V_9 -> V_376 -> V_395 )
V_9 -> V_376 -> V_395 ( V_9 , V_381 ) ;
V_10 = F_160 ( V_9 ) ;
if ( ! V_10 && ! F_15 ( V_9 ) ) {
F_5 ( V_9 -> V_16 , L_50 , V_17 ) ;
V_10 = - V_396 ;
goto V_44;
}
if ( V_10 && F_180 ( V_9 ) )
goto V_44;
} while ( V_10 && V_382 -- );
if ( V_10 )
goto V_44;
if ( V_9 -> V_376 && V_9 -> V_376 -> V_395 ) {
V_10 = V_9 -> V_376 -> V_395 ( V_9 , V_378 ) ;
if ( V_10 )
goto V_44;
}
V_10 = F_179 ( V_9 ) ;
V_44:
if ( V_10 )
F_5 ( V_9 -> V_16 , L_51 , V_10 ) ;
return V_10 ;
}
static int F_184 ( struct V_8 * V_9 )
{
int V_23 = 0 ;
int V_382 ;
F_54 ( V_9 , false ) ;
F_105 ( & V_9 -> V_134 . V_270 ) ;
for ( V_382 = V_397 ; V_382 > 0 ; V_382 -- ) {
V_23 = F_139 ( V_9 , V_228 ,
V_398 ) ;
if ( ! V_23 || V_23 == - V_26 )
break;
F_175 ( V_9 -> V_16 , L_44 , V_17 , V_23 ) ;
}
F_106 ( & V_9 -> V_134 . V_270 ) ;
F_68 ( V_9 ) ;
if ( V_23 )
F_5 ( V_9 -> V_16 , L_52 , V_17 , V_23 ) ;
return V_23 ;
}
static void F_185 ( struct V_399 * V_400 )
{
int V_10 = 0 ;
T_2 V_401 ;
struct V_8 * V_9 ;
V_9 = F_128 ( V_400 -> V_78 ) ;
V_401 = V_9 -> V_153 ;
V_10 = F_154 ( V_9 ,
F_124 ( V_400 -> V_211 ) ,
V_402 ,
& V_401 ,
sizeof( V_401 ) ) ;
if ( V_10 == - V_304 )
V_401 = 1 ;
else if ( ! V_401 )
V_401 = V_9 -> V_153 ;
else
V_401 = F_91 ( int , V_401 , V_9 -> V_153 ) ;
F_175 ( V_9 -> V_16 , L_53 ,
V_17 , V_401 ) ;
F_186 ( V_400 , V_401 ) ;
}
static int F_187 ( struct V_8 * V_9 ,
T_2 V_211 ,
T_2 * V_403 )
{
int V_10 ;
if ( ! V_403 )
V_10 = - V_110 ;
else if ( V_211 >= V_303 )
V_10 = - V_230 ;
else
V_10 = F_154 ( V_9 ,
V_211 ,
V_404 ,
V_403 ,
sizeof( * V_403 ) ) ;
return V_10 ;
}
static inline void F_188 ( struct V_8 * V_9 ,
struct V_399 * V_400 )
{
if ( V_9 -> V_405 . V_406 &&
! V_9 -> V_405 . V_407 ) {
T_2 V_403 ;
if ( ! F_187 ( V_9 , F_124 ( V_400 -> V_211 ) ,
& V_403 ) &&
( V_403 == V_408 ) )
V_9 -> V_405 . V_407 = true ;
}
}
static int F_189 ( struct V_399 * V_400 )
{
struct V_8 * V_9 ;
V_9 = F_128 ( V_400 -> V_78 ) ;
V_400 -> V_409 = 1 ;
V_400 -> V_410 = 1 ;
F_190 ( V_400 , V_411 ) ;
V_400 -> V_412 = 1 ;
V_400 -> V_413 = 1 ;
F_185 ( V_400 ) ;
F_188 ( V_9 , V_400 ) ;
return 0 ;
}
static int F_191 ( struct V_399 * V_400 ,
int V_414 , int V_415 )
{
struct V_8 * V_9 = F_128 ( V_400 -> V_78 ) ;
if ( V_414 > V_9 -> V_153 )
V_414 = V_9 -> V_153 ;
switch ( V_415 ) {
case V_416 :
case V_417 :
if ( ! V_400 -> V_409 )
V_414 = 1 ;
F_192 ( V_400 , F_193 ( V_400 ) , V_414 ) ;
break;
case V_418 :
F_194 ( V_400 , V_414 ) ;
break;
default:
return - V_304 ;
}
return V_414 ;
}
static int F_195 ( struct V_399 * V_400 )
{
struct V_419 * V_420 = V_400 -> V_419 ;
F_196 ( V_420 , V_421 - 1 ) ;
F_197 ( V_420 , V_422 ) ;
return 0 ;
}
static void F_198 ( struct V_399 * V_400 )
{
struct V_8 * V_9 ;
V_9 = F_128 ( V_400 -> V_78 ) ;
F_199 ( V_400 , V_9 -> V_153 ) ;
if ( F_124 ( V_400 -> V_211 ) == V_423 ) {
unsigned long V_74 ;
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
V_9 -> V_424 = NULL ;
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
}
}
static int F_200 ( struct V_8 * V_9 , T_1 V_266 , T_2 * V_249 )
{
struct V_40 * V_41 ;
struct V_425 * V_426 ;
unsigned long V_74 ;
int V_427 ;
int V_428 ;
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
F_201 ( V_266 , & V_9 -> V_97 ) ;
V_41 = V_9 -> V_314 ;
V_427 = F_18 ( & V_41 [ V_266 ] ) ;
if ( V_427 == V_429 ) {
V_426 = (struct V_425 * )
V_41 [ V_266 ] . V_430 ;
V_428 = F_30 ( V_426 -> V_37 . V_56 ) ;
V_428 = ( ( V_428 & V_431 ) >> 8 ) ;
if ( V_249 )
* V_249 = ( T_2 ) V_428 ;
} else {
F_5 ( V_9 -> V_16 , L_54 ,
V_17 , V_427 ) ;
}
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
return V_427 ;
}
static inline int
F_202 ( struct V_34 * V_35 , int V_432 )
{
int V_433 = 0 ;
switch ( V_432 ) {
case V_434 :
F_89 ( V_35 ) ;
case V_435 :
V_433 |= V_436 << 16 |
V_437 << 8 |
V_432 ;
break;
case V_438 :
case V_439 :
case V_440 :
F_89 ( V_35 ) ;
V_433 |= V_432 ;
break;
default:
V_433 |= V_241 << 16 ;
break;
}
return V_433 ;
}
static inline int
F_203 ( struct V_8 * V_9 , struct V_34 * V_35 )
{
int V_433 = 0 ;
int V_432 ;
int V_441 ;
V_441 = F_16 ( V_35 ) ;
switch ( V_441 ) {
case V_429 :
V_433 = F_29 ( V_35 -> V_54 ) ;
switch ( V_433 ) {
case V_442 :
V_433 = F_31 ( V_35 -> V_54 ) ;
V_432 = V_433 & V_443 ;
V_433 = F_202 ( V_35 , V_432 ) ;
if ( F_33 ( V_35 -> V_54 ) )
F_58 ( & V_9 -> V_444 ) ;
break;
case V_252 :
V_433 = V_241 << 16 ;
F_5 ( V_9 -> V_16 ,
L_55 ) ;
break;
default:
V_433 = V_241 << 16 ;
F_5 ( V_9 -> V_16 ,
L_56 ,
V_433 ) ;
break;
}
break;
case V_445 :
V_433 |= V_446 << 16 ;
break;
case V_207 :
V_433 |= V_447 << 16 ;
break;
case V_448 :
case V_449 :
case V_450 :
case V_451 :
case V_452 :
case V_453 :
default:
V_433 |= V_241 << 16 ;
F_5 ( V_9 -> V_16 ,
L_57 , V_441 ) ;
break;
}
return V_433 ;
}
static void F_204 ( struct V_8 * V_9 , T_1 V_454 )
{
if ( ( V_454 & V_455 ) && V_9 -> V_98 ) {
V_9 -> V_98 -> V_161 |=
F_27 ( V_9 ) ;
V_9 -> V_98 -> V_162 =
F_28 ( V_9 ) ;
V_256 ( & V_9 -> V_98 -> V_166 ) ;
}
if ( ( V_454 & V_456 ) && V_9 -> V_99 )
V_256 ( V_9 -> V_99 ) ;
}
static void F_205 ( struct V_8 * V_9 )
{
struct V_34 * V_35 ;
struct V_174 * V_175 ;
unsigned long V_457 ;
T_1 V_458 ;
int V_433 ;
int V_266 ;
F_34 ( V_9 ) ;
V_458 = F_10 ( V_9 , V_125 ) ;
V_457 = V_458 ^ V_9 -> V_122 ;
F_206 (index, &completed_reqs, hba->nutrs) {
V_35 = & V_9 -> V_244 [ V_266 ] ;
V_175 = V_35 -> V_175 ;
if ( V_175 ) {
V_433 = F_203 ( V_9 , V_35 ) ;
F_207 ( V_175 ) ;
V_175 -> V_433 = V_433 ;
V_35 -> V_175 = NULL ;
F_23 ( V_266 , & V_9 -> V_96 ) ;
V_175 -> V_242 ( V_175 ) ;
F_66 ( V_9 ) ;
} else if ( V_35 -> V_203 == V_225 ) {
if ( V_9 -> V_134 . V_256 )
V_256 ( V_9 -> V_134 . V_256 ) ;
}
}
V_9 -> V_122 ^= V_457 ;
F_83 ( V_9 ) ;
F_142 ( & V_9 -> V_134 . V_261 ) ;
}
static int F_208 ( struct V_8 * V_9 , T_5 V_19 )
{
int V_23 = 0 ;
T_1 V_20 ;
if ( ! ( V_9 -> V_459 & V_19 ) )
goto V_44;
V_20 = V_9 -> V_459 & ~ V_19 ;
V_20 &= 0xFFFF ;
V_23 = F_146 ( V_9 , V_281 ,
V_460 , 0 , 0 , & V_20 ) ;
if ( ! V_23 )
V_9 -> V_459 &= ~ V_19 ;
V_44:
return V_23 ;
}
static int F_209 ( struct V_8 * V_9 , T_5 V_19 )
{
int V_23 = 0 ;
T_1 V_20 ;
if ( V_9 -> V_459 & V_19 )
goto V_44;
V_20 = V_9 -> V_459 | V_19 ;
V_20 &= 0xFFFF ;
V_23 = F_146 ( V_9 , V_281 ,
V_460 , 0 , 0 , & V_20 ) ;
if ( ! V_23 )
V_9 -> V_459 |= V_19 ;
V_44:
return V_23 ;
}
static int F_210 ( struct V_8 * V_9 )
{
int V_23 = 0 ;
if ( V_9 -> V_461 )
goto V_44;
V_23 = F_144 ( V_9 , V_271 ,
V_462 , NULL ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_58 ,
V_17 , V_23 ) ;
goto V_44;
}
V_9 -> V_461 = true ;
V_23 = F_208 ( V_9 , V_463 ) ;
if ( V_23 )
F_5 ( V_9 -> V_16 , L_59 ,
V_17 , V_23 ) ;
V_44:
return V_23 ;
}
static int F_211 ( struct V_8 * V_9 )
{
int V_23 = 0 ;
if ( ! V_9 -> V_461 )
goto V_44;
V_23 = F_209 ( V_9 , V_463 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_60 ,
V_17 , V_23 ) ;
goto V_44;
}
V_23 = F_144 ( V_9 , V_272 ,
V_462 , NULL ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_61 ,
V_17 , V_23 ) ;
F_208 ( V_9 , V_463 ) ;
goto V_44;
}
V_9 -> V_461 = false ;
V_44:
return V_23 ;
}
static void F_212 ( struct V_8 * V_9 )
{
V_9 -> V_461 = false ;
V_9 -> V_459 |= V_463 ;
F_210 ( V_9 ) ;
}
static inline int F_213 ( struct V_8 * V_9 , T_1 * V_341 )
{
return F_146 ( V_9 , V_282 ,
V_464 , 0 , 0 , V_341 ) ;
}
static int F_214 ( struct V_8 * V_9 ,
enum V_465 V_341 )
{
int V_23 ;
T_1 V_466 = 0 ;
V_23 = F_213 ( V_9 , & V_466 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_62 ,
V_17 , V_23 ) ;
goto V_44;
} else if ( V_466 > V_467 ) {
F_5 ( V_9 -> V_16 , L_63 ,
V_17 , V_466 ) ;
V_23 = - V_110 ;
goto V_44;
}
if ( V_466 >= V_341 )
V_23 = F_210 ( V_9 ) ;
else
V_23 = F_211 ( V_9 ) ;
V_44:
return V_23 ;
}
static int F_215 ( struct V_8 * V_9 )
{
return F_214 ( V_9 , V_468 ) ;
}
static inline int F_216 ( struct V_8 * V_9 , T_1 * V_341 )
{
return F_146 ( V_9 , V_282 ,
V_469 , 0 , 0 , V_341 ) ;
}
static void F_217 ( struct V_72 * V_73 )
{
struct V_8 * V_9 ;
int V_23 ;
T_1 V_341 = 0 ;
V_9 = F_42 ( V_73 , struct V_8 , V_444 ) ;
F_218 ( V_9 -> V_16 ) ;
V_23 = F_216 ( V_9 , & V_341 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_64 ,
V_17 , V_23 ) ;
goto V_44;
}
V_341 &= V_9 -> V_459 ;
if ( V_341 & V_463 ) {
V_23 = F_215 ( V_9 ) ;
if ( V_23 < 0 )
F_5 ( V_9 -> V_16 , L_65 ,
V_17 , V_23 ) ;
}
V_44:
F_219 ( V_9 -> V_16 ) ;
return;
}
static void F_220 ( struct V_72 * V_73 )
{
struct V_8 * V_9 ;
unsigned long V_74 ;
T_1 V_470 = 0 ;
T_1 V_471 = 0 ;
int V_23 = 0 ;
int V_43 ;
V_9 = F_42 ( V_73 , struct V_8 , V_472 ) ;
F_218 ( V_9 -> V_16 ) ;
F_54 ( V_9 , false ) ;
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
if ( V_9 -> V_94 == V_237 ) {
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
goto V_44;
}
V_9 -> V_94 = V_237 ;
F_221 ( V_9 ) ;
F_205 ( V_9 ) ;
F_222 ( V_9 ) ;
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
F_206 (tag, &hba->outstanding_reqs, hba->nutrs)
if ( F_132 ( V_9 , V_43 ) )
V_470 |= 1 << V_43 ;
F_206 (tag, &hba->outstanding_tasks, hba->nutmrs)
if ( F_223 ( V_9 , V_43 ) )
V_471 |= 1 << V_43 ;
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
F_205 ( V_9 ) ;
F_222 ( V_9 ) ;
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
if ( V_470 || V_471 || ( V_9 -> V_473 & V_474 ) ||
( ( V_9 -> V_473 & V_475 ) &&
( V_9 -> V_476 & V_477 ) ) ) {
V_23 = F_224 ( V_9 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_66 ,
V_17 ) ;
V_9 -> V_94 = V_240 ;
}
F_225 ( V_9 -> V_78 , 0 ) ;
V_9 -> V_473 = 0 ;
V_9 -> V_476 = 0 ;
}
F_226 ( V_9 ) ;
V_44:
F_53 ( V_9 -> V_78 ) ;
F_68 ( V_9 ) ;
F_219 ( V_9 -> V_16 ) ;
}
static void F_227 ( struct V_8 * V_9 )
{
T_1 V_18 ;
V_18 = F_10 ( V_9 , V_478 ) ;
if ( V_18 & V_479 )
V_9 -> V_480 |= V_477 ;
V_18 = F_10 ( V_9 , V_481 ) ;
if ( V_18 )
V_9 -> V_480 |= V_482 ;
V_18 = F_10 ( V_9 , V_483 ) ;
if ( V_18 )
V_9 -> V_480 |= V_484 ;
V_18 = F_10 ( V_9 , V_485 ) ;
if ( V_18 )
V_9 -> V_480 |= V_486 ;
F_175 ( V_9 -> V_16 , L_67 ,
V_17 , V_9 -> V_480 ) ;
}
static void F_228 ( struct V_8 * V_9 )
{
bool V_487 = false ;
if ( V_9 -> V_488 & V_474 )
V_487 = true ;
if ( V_9 -> V_488 & V_475 ) {
V_9 -> V_480 = 0 ;
F_227 ( V_9 ) ;
if ( V_9 -> V_480 )
V_487 = true ;
}
if ( V_487 ) {
if ( V_9 -> V_94 == V_95 ) {
F_57 ( V_9 -> V_78 ) ;
V_9 -> V_473 |= V_9 -> V_488 ;
V_9 -> V_476 |= V_9 -> V_480 ;
V_9 -> V_94 = V_240 ;
F_58 ( & V_9 -> V_472 ) ;
}
}
}
static void F_222 ( struct V_8 * V_9 )
{
T_1 V_489 ;
V_489 = F_10 ( V_9 , V_490 ) ;
V_9 -> V_491 = V_489 ^ V_9 -> V_97 ;
F_142 ( & V_9 -> V_492 ) ;
}
static void F_229 ( struct V_8 * V_9 , T_1 V_454 )
{
V_9 -> V_488 = V_493 & V_454 ;
if ( V_9 -> V_488 )
F_228 ( V_9 ) ;
if ( V_454 & V_393 )
F_204 ( V_9 , V_454 ) ;
if ( V_454 & V_494 )
F_222 ( V_9 ) ;
if ( V_454 & V_495 )
F_205 ( V_9 ) ;
}
static T_7 V_13 ( int V_12 , void * V_496 )
{
T_1 V_454 ;
T_7 V_497 = V_498 ;
struct V_8 * V_9 = V_496 ;
F_230 ( V_9 -> V_78 -> V_79 ) ;
V_454 = F_10 ( V_9 , V_499 ) ;
if ( V_454 ) {
F_25 ( V_9 , V_454 , V_499 ) ;
F_229 ( V_9 , V_454 ) ;
V_497 = V_500 ;
}
F_231 ( V_9 -> V_78 -> V_79 ) ;
return V_497 ;
}
static int F_223 ( struct V_8 * V_9 , int V_43 )
{
int V_23 = 0 ;
T_1 V_19 = 1 << V_43 ;
unsigned long V_74 ;
if ( ! F_232 ( V_43 , & V_9 -> V_97 ) )
goto V_44;
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
F_25 ( V_9 , ~ ( 1 << V_43 ) , V_501 ) ;
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
V_23 = F_8 ( V_9 ,
V_490 ,
V_19 , 0 , 1000 , 1000 ) ;
V_44:
return V_23 ;
}
static int F_233 ( struct V_8 * V_9 , int V_502 , int V_503 ,
T_2 V_504 , T_2 * V_505 )
{
struct V_40 * V_41 ;
struct V_506 * V_507 ;
struct V_236 * V_78 ;
unsigned long V_74 ;
int V_42 ;
int V_23 ;
int V_124 ;
V_78 = V_9 -> V_78 ;
F_140 ( V_9 -> V_508 , F_19 ( V_9 , & V_42 ) ) ;
F_54 ( V_9 , false ) ;
F_44 ( V_78 -> V_79 , V_74 ) ;
V_41 = V_9 -> V_314 ;
V_41 += V_42 ;
V_41 -> V_37 . V_55 = F_111 ( V_206 ) ;
V_41 -> V_37 . V_38 =
F_111 ( V_207 ) ;
V_507 =
(struct V_506 * ) V_41 -> V_509 ;
V_124 = V_9 -> V_153 + V_42 ;
V_507 -> V_37 . V_55 =
F_119 ( V_510 , 0 ,
V_502 , V_124 ) ;
V_507 -> V_37 . V_56 =
F_119 ( 0 , V_504 , 0 , 0 ) ;
V_507 -> V_511 = F_120 ( V_502 ) ;
V_507 -> V_512 = F_120 ( V_503 ) ;
F_88 ( V_42 , & V_9 -> V_97 ) ;
F_25 ( V_9 , 1 << V_42 , V_490 ) ;
F_45 ( V_78 -> V_79 , V_74 ) ;
V_23 = F_234 ( V_9 -> V_492 ,
F_232 ( V_42 , & V_9 -> V_491 ) ,
F_9 ( V_513 ) ) ;
if ( ! V_23 ) {
F_5 ( V_9 -> V_16 , L_68 ,
V_17 , V_504 ) ;
if ( F_223 ( V_9 , V_42 ) )
F_235 ( V_9 -> V_16 , L_69 ,
V_17 , V_42 ) ;
V_23 = - V_26 ;
} else {
V_23 = F_200 ( V_9 , V_42 , V_505 ) ;
}
F_236 ( V_42 , & V_9 -> V_491 ) ;
F_22 ( V_9 , V_42 ) ;
F_142 ( & V_9 -> V_508 ) ;
F_68 ( V_9 ) ;
return V_23 ;
}
static int F_237 ( struct V_174 * V_175 )
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
V_9 = F_128 ( V_78 ) ;
V_43 = V_175 -> V_147 -> V_43 ;
V_35 = & V_9 -> V_244 [ V_43 ] ;
V_23 = F_233 ( V_9 , V_35 -> V_211 , 0 , V_514 , & V_249 ) ;
if ( V_23 || V_249 != V_515 ) {
if ( ! V_23 )
V_23 = V_249 ;
goto V_44;
}
F_206 (pos, &hba->outstanding_reqs, hba->nutrs) {
if ( V_9 -> V_244 [ V_48 ] . V_211 == V_35 -> V_211 ) {
V_23 = F_132 ( V_9 , V_48 ) ;
if ( V_23 )
break;
}
}
F_44 ( V_78 -> V_79 , V_74 ) ;
F_205 ( V_9 ) ;
F_45 ( V_78 -> V_79 , V_74 ) ;
V_44:
if ( ! V_23 ) {
V_23 = V_516 ;
} else {
F_5 ( V_9 -> V_16 , L_70 , V_17 , V_23 ) ;
V_23 = V_517 ;
}
return V_23 ;
}
static int F_238 ( struct V_174 * V_175 )
{
struct V_236 * V_78 ;
struct V_8 * V_9 ;
unsigned long V_74 ;
unsigned int V_43 ;
int V_23 = 0 ;
int V_518 ;
T_2 V_249 = 0xF ;
struct V_34 * V_35 ;
T_1 V_18 ;
V_78 = V_175 -> V_103 -> V_78 ;
V_9 = F_128 ( V_78 ) ;
V_43 = V_175 -> V_147 -> V_43 ;
F_54 ( V_9 , false ) ;
if ( ! ( F_232 ( V_43 , & V_9 -> V_122 ) ) )
goto V_44;
V_18 = F_10 ( V_9 , V_125 ) ;
if ( ! ( V_18 & ( 1 << V_43 ) ) ) {
F_5 ( V_9 -> V_16 ,
L_71 ,
V_17 , V_43 ) ;
}
V_35 = & V_9 -> V_244 [ V_43 ] ;
for ( V_518 = 100 ; V_518 ; V_518 -- ) {
V_23 = F_233 ( V_9 , V_35 -> V_211 , V_35 -> V_124 ,
V_519 , & V_249 ) ;
if ( ! V_23 && V_249 == V_520 ) {
break;
} else if ( ! V_23 && V_249 == V_515 ) {
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
if ( ! V_518 ) {
V_23 = - V_521 ;
goto V_44;
}
V_23 = F_233 ( V_9 , V_35 -> V_211 , V_35 -> V_124 ,
V_522 , & V_249 ) ;
if ( V_23 || V_249 != V_515 ) {
if ( ! V_23 )
V_23 = V_249 ;
goto V_44;
}
V_23 = F_132 ( V_9 , V_43 ) ;
if ( V_23 )
goto V_44;
F_207 ( V_175 ) ;
F_44 ( V_78 -> V_79 , V_74 ) ;
F_201 ( V_43 , & V_9 -> V_122 ) ;
V_9 -> V_244 [ V_43 ] . V_175 = NULL ;
F_45 ( V_78 -> V_79 , V_74 ) ;
F_23 ( V_43 , & V_9 -> V_96 ) ;
F_142 ( & V_9 -> V_134 . V_261 ) ;
V_44:
if ( ! V_23 ) {
V_23 = V_516 ;
} else {
F_5 ( V_9 -> V_16 , L_70 , V_17 , V_23 ) ;
V_23 = V_517 ;
}
F_68 ( V_9 ) ;
return V_23 ;
}
static int F_169 ( struct V_8 * V_9 )
{
int V_23 ;
unsigned long V_74 ;
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
F_181 ( V_9 ) ;
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
V_23 = F_180 ( V_9 ) ;
if ( V_23 )
goto V_44;
V_23 = F_239 ( V_9 ) ;
if ( ! V_23 && ( V_9 -> V_94 != V_95 ) )
V_23 = - V_168 ;
V_44:
if ( V_23 )
F_5 ( V_9 -> V_16 , L_72 , V_17 , V_23 ) ;
return V_23 ;
}
static int F_224 ( struct V_8 * V_9 )
{
int V_23 = 0 ;
unsigned long V_74 ;
int V_382 = V_523 ;
do {
V_23 = F_169 ( V_9 ) ;
} while ( V_23 && -- V_382 );
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
F_205 ( V_9 ) ;
F_222 ( V_9 ) ;
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
return V_23 ;
}
static int F_240 ( struct V_174 * V_175 )
{
int V_23 ;
unsigned long V_74 ;
struct V_8 * V_9 ;
V_9 = F_128 ( V_175 -> V_103 -> V_78 ) ;
F_54 ( V_9 , false ) ;
do {
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
if ( ! ( F_241 ( & V_9 -> V_472 ) ||
V_9 -> V_94 == V_237 ) )
break;
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
F_175 ( V_9 -> V_16 , L_73 , V_17 ) ;
F_59 ( & V_9 -> V_472 ) ;
} while ( 1 );
V_9 -> V_94 = V_237 ;
F_221 ( V_9 ) ;
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
V_23 = F_224 ( V_9 ) ;
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
if ( ! V_23 ) {
V_23 = V_516 ;
V_9 -> V_94 = V_95 ;
} else {
V_23 = V_517 ;
V_9 -> V_94 = V_240 ;
}
F_226 ( V_9 ) ;
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
F_68 ( V_9 ) ;
return V_23 ;
}
static T_1 F_242 ( int V_524 , T_1 V_525 , char * V_526 )
{
int V_177 ;
int V_527 ;
T_5 V_528 ;
T_5 V_529 ;
for ( V_177 = V_525 ; V_177 >= 0 ; V_177 -- ) {
V_528 = F_90 ( * ( ( T_5 * ) ( V_526 + 2 * V_177 ) ) ) ;
V_529 = ( V_528 & V_530 ) >>
V_531 ;
V_527 = V_528 & V_532 ;
switch ( V_529 ) {
case V_533 :
V_527 = V_527 / 1000 ;
break;
case V_534 :
V_527 = V_527 * 1000 ;
break;
case V_535 :
V_527 = V_527 * 1000 * 1000 ;
break;
case V_536 :
default:
break;
}
if ( V_524 >= V_527 )
break;
}
if ( V_177 < 0 ) {
V_177 = 0 ;
F_243 ( L_74 , V_17 , V_177 ) ;
}
return ( T_1 ) V_177 ;
}
static T_1 F_244 ( struct V_8 * V_9 ,
T_2 * V_284 , int V_126 )
{
T_1 V_537 = 0 ;
if ( ! V_9 -> V_538 . V_539 || ! V_9 -> V_538 . V_540 ||
! V_9 -> V_538 . V_541 ) {
F_5 ( V_9 -> V_16 ,
L_75 ,
V_17 , V_537 ) ;
goto V_44;
}
if ( V_9 -> V_538 . V_539 )
V_537 = F_242 (
V_9 -> V_538 . V_539 -> V_542 ,
V_543 - 1 ,
& V_284 [ V_544 ] ) ;
if ( V_9 -> V_538 . V_540 )
V_537 = F_242 (
V_9 -> V_538 . V_540 -> V_542 ,
V_537 ,
& V_284 [ V_545 ] ) ;
if ( V_9 -> V_538 . V_541 )
V_537 = F_242 (
V_9 -> V_538 . V_541 -> V_542 ,
V_537 ,
& V_284 [ V_546 ] ) ;
V_44:
return V_537 ;
}
static void F_245 ( struct V_8 * V_9 )
{
int V_10 ;
int V_292 = V_547 ;
T_2 V_284 [ V_547 ] ;
V_10 = F_153 ( V_9 , V_284 , V_292 ) ;
if ( V_10 ) {
F_5 ( V_9 -> V_16 ,
L_76 ,
V_17 , V_292 , V_10 ) ;
return;
}
V_9 -> V_548 . V_537 =
F_244 ( V_9 ,
V_284 , V_292 ) ;
F_175 ( V_9 -> V_16 , L_77 ,
V_17 , V_9 -> V_548 . V_537 ) ;
V_10 = F_146 ( V_9 , V_281 ,
V_549 , 0 , 0 ,
& V_9 -> V_548 . V_537 ) ;
if ( V_10 )
F_5 ( V_9 -> V_16 ,
L_78 ,
V_17 , V_9 -> V_548 . V_537 , V_10 ) ;
}
static int F_246 ( struct V_8 * V_9 )
{
int V_10 = 0 ;
struct V_399 * V_550 ;
struct V_399 * V_551 ;
V_9 -> V_424 = F_247 ( V_9 -> V_78 , 0 , 0 ,
F_126 ( V_423 ) , NULL ) ;
if ( F_248 ( V_9 -> V_424 ) ) {
V_10 = F_249 ( V_9 -> V_424 ) ;
V_9 -> V_424 = NULL ;
goto V_44;
}
F_250 ( V_9 -> V_424 ) ;
V_551 = F_247 ( V_9 -> V_78 , 0 , 0 ,
F_126 ( V_552 ) , NULL ) ;
if ( F_248 ( V_551 ) ) {
V_10 = F_249 ( V_551 ) ;
goto V_553;
}
F_250 ( V_551 ) ;
V_550 = F_247 ( V_9 -> V_78 , 0 , 0 ,
F_126 ( V_302 ) , NULL ) ;
if ( F_248 ( V_550 ) ) {
V_10 = F_249 ( V_550 ) ;
goto V_554;
}
F_250 ( V_550 ) ;
goto V_44;
V_554:
F_251 ( V_551 ) ;
V_553:
F_251 ( V_9 -> V_424 ) ;
V_44:
return V_10 ;
}
static int F_239 ( struct V_8 * V_9 )
{
int V_10 ;
V_10 = F_183 ( V_9 ) ;
if ( V_10 )
goto V_44;
F_170 ( V_9 ) ;
F_50 ( V_9 ) ;
V_10 = F_184 ( V_9 ) ;
if ( V_10 )
goto V_44;
V_10 = F_178 ( V_9 ) ;
if ( V_10 )
goto V_44;
F_252 ( V_9 ) ;
F_212 ( V_9 ) ;
V_9 -> V_94 = V_95 ;
V_9 -> V_555 = true ;
if ( F_171 ( V_9 ) ) {
F_5 ( V_9 -> V_16 ,
L_79 ,
V_17 ) ;
} else {
V_10 = F_177 ( V_9 , & V_9 -> V_358 . V_359 ) ;
if ( V_10 )
F_5 ( V_9 -> V_16 , L_80 ,
V_17 , V_10 ) ;
}
if ( ! F_253 ( V_9 ) && ! V_9 -> V_556 ) {
bool V_557 ;
memset ( & V_9 -> V_405 , 0 , sizeof( V_9 -> V_405 ) ) ;
if ( ! F_144 ( V_9 , V_275 ,
V_558 , & V_557 ) )
V_9 -> V_405 . V_406 = V_557 ;
if ( ! V_9 -> V_559 )
F_245 ( V_9 ) ;
if ( F_246 ( V_9 ) )
goto V_44;
F_254 ( V_9 -> V_78 ) ;
F_219 ( V_9 -> V_16 ) ;
}
if ( ! V_9 -> V_559 )
V_9 -> V_559 = true ;
if ( F_51 ( V_9 ) )
F_52 ( V_9 -> V_84 ) ;
V_44:
if ( V_10 && ! F_253 ( V_9 ) && ! V_9 -> V_556 ) {
F_219 ( V_9 -> V_16 ) ;
F_255 ( V_9 ) ;
}
return V_10 ;
}
static void F_256 ( void * V_528 , T_8 V_560 )
{
struct V_8 * V_9 = (struct V_8 * ) V_528 ;
F_239 ( V_9 ) ;
}
static int F_257 ( struct V_103 * V_16 , struct V_561 * V_562 ,
int V_563 )
{
int V_10 = 0 ;
struct V_564 * V_18 = V_562 -> V_18 ;
const char * V_114 = V_562 -> V_114 ;
F_145 ( ! V_562 ) ;
V_10 = F_258 ( V_18 , V_563 ) ;
if ( V_10 >= 0 ) {
V_10 = 0 ;
} else {
F_5 ( V_16 , L_81 ,
V_17 , V_114 , V_563 , V_10 ) ;
}
return V_10 ;
}
static inline int F_259 ( struct V_8 * V_9 ,
struct V_561 * V_562 )
{
if ( ! V_562 )
return 0 ;
return F_257 ( V_9 -> V_16 , V_562 , V_565 ) ;
}
static inline int F_260 ( struct V_8 * V_9 ,
struct V_561 * V_562 )
{
if ( ! V_562 )
return 0 ;
return F_257 ( V_9 -> V_16 , V_562 , V_562 -> V_542 ) ;
}
static int F_261 ( struct V_103 * V_16 ,
struct V_561 * V_562 , bool V_566 )
{
int V_10 = 0 ;
struct V_564 * V_18 = V_562 -> V_18 ;
const char * V_114 = V_562 -> V_114 ;
int V_567 , V_568 ;
F_145 ( ! V_562 ) ;
if ( F_262 ( V_18 ) > 0 ) {
V_567 = V_566 ? V_562 -> V_567 : 0 ;
V_10 = F_263 ( V_18 , V_567 , V_562 -> V_569 ) ;
if ( V_10 ) {
F_5 ( V_16 , L_82 ,
V_17 , V_114 , V_10 ) ;
goto V_44;
}
V_568 = V_566 ? V_562 -> V_542 : 0 ;
V_10 = F_257 ( V_16 , V_562 , V_568 ) ;
if ( V_10 )
goto V_44;
}
V_44:
return V_10 ;
}
static int F_264 ( struct V_103 * V_16 , struct V_561 * V_562 )
{
int V_10 = 0 ;
if ( ! V_562 || V_562 -> V_570 )
goto V_44;
V_10 = F_261 ( V_16 , V_562 , true ) ;
if ( ! V_10 )
V_10 = F_265 ( V_562 -> V_18 ) ;
if ( ! V_10 )
V_562 -> V_570 = true ;
else
F_5 ( V_16 , L_83 ,
V_17 , V_562 -> V_114 , V_10 ) ;
V_44:
return V_10 ;
}
static int F_266 ( struct V_103 * V_16 , struct V_561 * V_562 )
{
int V_10 = 0 ;
if ( ! V_562 || ! V_562 -> V_570 )
goto V_44;
V_10 = F_267 ( V_562 -> V_18 ) ;
if ( ! V_10 ) {
F_261 ( V_16 , V_562 , false ) ;
V_562 -> V_570 = false ;
} else {
F_5 ( V_16 , L_84 ,
V_17 , V_562 -> V_114 , V_10 ) ;
}
V_44:
return V_10 ;
}
static int F_268 ( struct V_8 * V_9 , bool V_566 )
{
int V_10 = 0 ;
struct V_103 * V_16 = V_9 -> V_16 ;
struct V_571 * V_359 = & V_9 -> V_538 ;
if ( ! V_359 )
goto V_44;
V_10 = F_269 ( V_16 , V_359 -> V_539 , V_566 ) ;
if ( V_10 )
goto V_44;
V_10 = F_269 ( V_16 , V_359 -> V_540 , V_566 ) ;
if ( V_10 )
goto V_44;
V_10 = F_269 ( V_16 , V_359 -> V_541 , V_566 ) ;
if ( V_10 )
goto V_44;
V_44:
if ( V_10 ) {
F_269 ( V_16 , V_359 -> V_541 , false ) ;
F_269 ( V_16 , V_359 -> V_540 , false ) ;
F_269 ( V_16 , V_359 -> V_539 , false ) ;
}
return V_10 ;
}
static int F_270 ( struct V_8 * V_9 , bool V_566 )
{
struct V_571 * V_359 = & V_9 -> V_538 ;
if ( V_359 )
return F_269 ( V_9 -> V_16 , V_359 -> V_572 , V_566 ) ;
return 0 ;
}
static int F_271 ( struct V_103 * V_16 , struct V_561 * V_562 )
{
int V_10 = 0 ;
if ( ! V_562 )
goto V_44;
V_562 -> V_18 = F_272 ( V_16 , V_562 -> V_114 ) ;
if ( F_248 ( V_562 -> V_18 ) ) {
V_10 = F_249 ( V_562 -> V_18 ) ;
F_5 ( V_16 , L_85 ,
V_17 , V_562 -> V_114 , V_10 ) ;
}
V_44:
return V_10 ;
}
static int F_273 ( struct V_8 * V_9 )
{
int V_10 = 0 ;
struct V_103 * V_16 = V_9 -> V_16 ;
struct V_571 * V_359 = & V_9 -> V_538 ;
if ( ! V_359 )
goto V_44;
V_10 = F_271 ( V_16 , V_359 -> V_539 ) ;
if ( V_10 )
goto V_44;
V_10 = F_271 ( V_16 , V_359 -> V_540 ) ;
if ( V_10 )
goto V_44;
V_10 = F_271 ( V_16 , V_359 -> V_541 ) ;
V_44:
return V_10 ;
}
static int F_274 ( struct V_8 * V_9 )
{
struct V_571 * V_359 = & V_9 -> V_538 ;
if ( V_359 )
return F_271 ( V_9 -> V_16 , V_359 -> V_572 ) ;
return 0 ;
}
static int F_65 ( struct V_8 * V_9 , bool V_566 ,
bool V_573 )
{
int V_10 = 0 ;
struct V_574 * V_575 ;
struct V_576 * V_577 = & V_9 -> V_578 ;
unsigned long V_74 ;
if ( ! V_577 || F_275 ( V_577 ) )
goto V_44;
F_276 (clki, head, list) {
if ( ! F_277 ( V_575 -> V_579 ) ) {
if ( V_573 && ! strcmp ( V_575 -> V_114 , L_86 ) )
continue;
if ( V_566 && ! V_575 -> V_570 ) {
V_10 = F_278 ( V_575 -> V_579 ) ;
if ( V_10 ) {
F_5 ( V_9 -> V_16 , L_87 ,
V_17 , V_575 -> V_114 , V_10 ) ;
goto V_44;
}
} else if ( ! V_566 && V_575 -> V_570 ) {
F_279 ( V_575 -> V_579 ) ;
}
V_575 -> V_570 = V_566 ;
F_175 ( V_9 -> V_16 , L_88 , V_17 ,
V_575 -> V_114 , V_566 ? L_89 : L_90 ) ;
}
}
if ( V_9 -> V_376 && V_9 -> V_376 -> V_580 )
V_10 = V_9 -> V_376 -> V_580 ( V_9 , V_566 ) ;
V_44:
if ( V_10 ) {
F_276 (clki, head, list) {
if ( ! F_277 ( V_575 -> V_579 ) && V_575 -> V_570 )
F_279 ( V_575 -> V_579 ) ;
}
} else if ( V_566 ) {
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
V_9 -> V_75 . V_80 = V_81 ;
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
}
return V_10 ;
}
static int F_46 ( struct V_8 * V_9 , bool V_566 )
{
return F_65 ( V_9 , V_566 , false ) ;
}
static int F_280 ( struct V_8 * V_9 )
{
int V_10 = 0 ;
struct V_574 * V_575 ;
struct V_103 * V_16 = V_9 -> V_16 ;
struct V_576 * V_577 = & V_9 -> V_578 ;
if ( ! V_577 || F_275 ( V_577 ) )
goto V_44;
F_276 (clki, head, list) {
if ( ! V_575 -> V_114 )
continue;
V_575 -> V_579 = F_281 ( V_16 , V_575 -> V_114 ) ;
if ( F_248 ( V_575 -> V_579 ) ) {
V_10 = F_249 ( V_575 -> V_579 ) ;
F_5 ( V_16 , L_91 ,
V_17 , V_575 -> V_114 , V_10 ) ;
goto V_44;
}
if ( V_575 -> V_581 ) {
V_10 = F_282 ( V_575 -> V_579 , V_575 -> V_581 ) ;
if ( V_10 ) {
F_5 ( V_9 -> V_16 , L_92 ,
V_17 , V_575 -> V_114 ,
V_575 -> V_581 , V_10 ) ;
goto V_44;
}
V_575 -> V_582 = V_575 -> V_581 ;
}
F_175 ( V_16 , L_93 , V_17 ,
V_575 -> V_114 , F_283 ( V_575 -> V_579 ) ) ;
}
V_44:
return V_10 ;
}
static int F_284 ( struct V_8 * V_9 )
{
int V_23 = 0 ;
if ( ! V_9 -> V_376 )
goto V_44;
if ( V_9 -> V_376 -> V_583 ) {
V_23 = V_9 -> V_376 -> V_583 ( V_9 ) ;
if ( V_23 )
goto V_44;
}
if ( V_9 -> V_376 -> V_584 ) {
V_23 = V_9 -> V_376 -> V_584 ( V_9 , true ) ;
if ( V_23 )
goto V_585;
}
goto V_44;
V_585:
if ( V_9 -> V_376 -> exit )
V_9 -> V_376 -> exit ( V_9 ) ;
V_44:
if ( V_23 )
F_5 ( V_9 -> V_16 , L_94 ,
V_17 , V_9 -> V_376 ? V_9 -> V_376 -> V_114 : L_95 , V_23 ) ;
return V_23 ;
}
static void F_285 ( struct V_8 * V_9 )
{
if ( ! V_9 -> V_376 )
return;
if ( V_9 -> V_376 -> V_580 )
V_9 -> V_376 -> V_580 ( V_9 , false ) ;
if ( V_9 -> V_376 -> V_584 )
V_9 -> V_376 -> V_584 ( V_9 , false ) ;
if ( V_9 -> V_376 -> exit )
V_9 -> V_376 -> exit ( V_9 ) ;
}
static int F_286 ( struct V_8 * V_9 )
{
int V_23 ;
V_23 = F_274 ( V_9 ) ;
if ( V_23 )
goto V_44;
V_23 = F_270 ( V_9 , true ) ;
if ( V_23 )
goto V_44;
V_23 = F_280 ( V_9 ) ;
if ( V_23 )
goto V_586;
V_23 = F_46 ( V_9 , true ) ;
if ( V_23 )
goto V_586;
V_23 = F_273 ( V_9 ) ;
if ( V_23 )
goto V_587;
V_23 = F_268 ( V_9 , true ) ;
if ( V_23 )
goto V_587;
V_23 = F_284 ( V_9 ) ;
if ( V_23 )
goto V_588;
V_9 -> V_589 = true ;
goto V_44;
V_588:
F_268 ( V_9 , false ) ;
V_587:
F_46 ( V_9 , false ) ;
V_586:
F_270 ( V_9 , false ) ;
V_44:
return V_23 ;
}
static void F_255 ( struct V_8 * V_9 )
{
if ( V_9 -> V_589 ) {
F_285 ( V_9 ) ;
F_268 ( V_9 , false ) ;
F_46 ( V_9 , false ) ;
F_270 ( V_9 , false ) ;
V_9 -> V_589 = false ;
}
}
static int
F_287 ( struct V_8 * V_9 , struct V_399 * V_590 )
{
unsigned char V_175 [ 6 ] = { V_591 ,
0 ,
0 ,
0 ,
V_131 ,
0 } ;
char * V_592 ;
int V_10 ;
V_592 = F_288 ( V_131 , V_296 ) ;
if ( ! V_592 ) {
V_10 = - V_297 ;
goto V_44;
}
V_10 = F_289 ( V_590 , V_175 , V_195 , V_592 ,
V_131 , NULL ,
F_9 ( 1000 ) , 3 , NULL , V_593 ) ;
if ( V_10 )
F_243 ( L_70 , V_17 , V_10 ) ;
F_151 ( V_592 ) ;
V_44:
return V_10 ;
}
static int F_290 ( struct V_8 * V_9 ,
enum V_1 V_367 )
{
unsigned char V_175 [ 6 ] = { V_594 } ;
struct V_595 V_596 ;
struct V_399 * V_590 ;
unsigned long V_74 ;
int V_10 ;
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
V_590 = V_9 -> V_424 ;
if ( V_590 ) {
V_10 = F_291 ( V_590 ) ;
if ( ! V_10 && ! F_292 ( V_590 ) ) {
V_10 = - V_597 ;
F_250 ( V_590 ) ;
}
} else {
V_10 = - V_597 ;
}
F_45 ( V_9 -> V_78 -> V_79 , V_74 ) ;
if ( V_10 )
return V_10 ;
V_9 -> V_78 -> V_598 = 1 ;
if ( V_9 -> V_555 ) {
V_10 = F_287 ( V_9 , V_590 ) ;
if ( V_10 )
goto V_44;
V_9 -> V_555 = false ;
}
V_175 [ 4 ] = V_367 << 4 ;
V_10 = F_289 ( V_590 , V_175 , V_226 , NULL , 0 , & V_596 ,
V_599 , 0 , NULL , V_593 ) ;
if ( V_10 ) {
F_293 ( V_600 , V_590 ,
L_96 , V_367 ) ;
F_294 ( V_10 ) ;
if ( F_295 ( V_10 ) & V_601 ) {
F_296 ( & V_596 ) ;
F_297 ( V_596 . V_602 , V_596 . V_603 ) ;
}
}
if ( ! V_10 )
V_9 -> V_604 = V_367 ;
V_44:
F_250 ( V_590 ) ;
V_9 -> V_78 -> V_598 = 0 ;
return V_10 ;
}
static int F_298 ( struct V_8 * V_9 ,
enum V_6 V_605 ,
int V_606 )
{
int V_10 = 0 ;
if ( V_605 == V_9 -> V_6 )
return 0 ;
if ( V_605 == V_607 ) {
V_10 = F_61 ( V_9 ) ;
if ( ! V_10 )
F_62 ( V_9 ) ;
else
goto V_44;
}
else if ( ( V_605 == V_608 ) &&
( ! V_606 || ( V_606 &&
! V_9 -> V_461 ) ) ) {
F_181 ( V_9 ) ;
F_168 ( V_9 ) ;
}
V_44:
return V_10 ;
}
static void F_299 ( struct V_8 * V_9 )
{
if ( F_300 ( V_9 ) && F_301 ( V_9 ) &&
! V_9 -> V_405 . V_407 ) {
F_268 ( V_9 , false ) ;
} else if ( ! F_302 ( V_9 ) ) {
F_269 ( V_9 -> V_16 , V_9 -> V_538 . V_539 , false ) ;
if ( ! F_64 ( V_9 ) ) {
F_259 ( V_9 , V_9 -> V_538 . V_540 ) ;
F_259 ( V_9 , V_9 -> V_538 . V_541 ) ;
}
}
}
static int F_303 ( struct V_8 * V_9 )
{
int V_10 = 0 ;
if ( F_300 ( V_9 ) && F_301 ( V_9 ) &&
! V_9 -> V_405 . V_407 ) {
V_10 = F_268 ( V_9 , true ) ;
} else if ( ! F_302 ( V_9 ) ) {
V_10 = F_269 ( V_9 -> V_16 , V_9 -> V_538 . V_539 , true ) ;
if ( ! V_10 && ! F_64 ( V_9 ) ) {
V_10 = F_260 ( V_9 , V_9 -> V_538 . V_540 ) ;
if ( V_10 )
goto V_609;
V_10 = F_260 ( V_9 , V_9 -> V_538 . V_541 ) ;
if ( V_10 )
goto V_610;
}
}
goto V_44;
V_610:
F_259 ( V_9 , V_9 -> V_538 . V_540 ) ;
V_609:
F_269 ( V_9 -> V_16 , V_9 -> V_538 . V_539 , false ) ;
V_44:
return V_10 ;
}
static void F_304 ( struct V_8 * V_9 )
{
if ( F_301 ( V_9 ) )
F_270 ( V_9 , false ) ;
}
static void F_305 ( struct V_8 * V_9 )
{
if ( F_301 ( V_9 ) )
F_270 ( V_9 , true ) ;
}
static int F_306 ( struct V_8 * V_9 , enum V_611 V_612 )
{
int V_10 = 0 ;
enum V_2 V_613 ;
enum V_1 V_614 ;
enum V_6 V_605 ;
V_9 -> V_556 = 1 ;
if ( ! F_307 ( V_612 ) ) {
V_613 = F_308 ( V_612 ) ?
V_9 -> V_615 : V_9 -> V_616 ;
V_614 = F_1 ( V_613 ) ;
V_605 = F_2 ( V_613 ) ;
} else {
V_614 = V_617 ;
V_605 = V_608 ;
}
F_54 ( V_9 , false ) ;
V_9 -> V_75 . V_83 = true ;
if ( V_614 == V_618 &&
V_605 == V_619 ) {
goto V_620;
}
if ( ( V_614 == V_9 -> V_604 ) &&
( V_605 == V_9 -> V_6 ) )
goto V_44;
if ( ! F_302 ( V_9 ) || ! F_64 ( V_9 ) ) {
V_10 = - V_110 ;
goto V_44;
}
if ( F_308 ( V_612 ) ) {
if ( F_309 ( V_9 ) ) {
V_10 = F_215 ( V_9 ) ;
if ( V_10 )
goto V_621;
} else {
F_211 ( V_9 ) ;
}
}
if ( ( V_614 != V_9 -> V_604 ) &&
( ( F_308 ( V_612 ) && ! V_9 -> V_461 ) ||
! F_308 ( V_612 ) ) ) {
F_211 ( V_9 ) ;
V_10 = F_290 ( V_9 , V_614 ) ;
if ( V_10 )
goto V_621;
}
V_10 = F_298 ( V_9 , V_605 , 1 ) ;
if ( V_10 )
goto V_622;
F_299 ( V_9 ) ;
V_620:
if ( F_51 ( V_9 ) ) {
F_63 ( V_9 -> V_84 ) ;
V_9 -> V_100 . V_101 = 0 ;
}
if ( V_9 -> V_376 && V_9 -> V_376 -> V_623 ) {
V_10 = V_9 -> V_376 -> V_623 ( V_9 , V_612 ) ;
if ( V_10 )
goto V_624;
}
if ( V_9 -> V_376 && V_9 -> V_376 -> V_580 ) {
V_10 = V_9 -> V_376 -> V_580 ( V_9 , false ) ;
if ( V_10 )
goto V_625;
}
if ( ! F_64 ( V_9 ) )
F_46 ( V_9 , false ) ;
else
F_65 ( V_9 , false , true ) ;
V_9 -> V_75 . V_80 = V_90 ;
F_6 ( V_9 ) ;
F_304 ( V_9 ) ;
goto V_44;
V_625:
if ( V_9 -> V_376 && V_9 -> V_376 -> V_626 )
V_9 -> V_376 -> V_626 ( V_9 , V_612 ) ;
V_624:
F_303 ( V_9 ) ;
if ( F_48 ( V_9 ) && ! F_49 ( V_9 ) )
F_50 ( V_9 ) ;
else if ( F_301 ( V_9 ) )
F_169 ( V_9 ) ;
V_622:
if ( ! F_290 ( V_9 , V_618 ) )
F_211 ( V_9 ) ;
V_621:
V_9 -> V_75 . V_83 = false ;
F_68 ( V_9 ) ;
V_44:
V_9 -> V_556 = 0 ;
return V_10 ;
}
static int F_310 ( struct V_8 * V_9 , enum V_611 V_612 )
{
int V_10 ;
enum V_6 V_627 ;
V_9 -> V_556 = 1 ;
V_627 = V_9 -> V_6 ;
F_305 ( V_9 ) ;
V_10 = F_46 ( V_9 , true ) ;
if ( V_10 )
goto V_44;
V_10 = F_3 ( V_9 ) ;
if ( V_10 )
goto V_628;
V_10 = F_303 ( V_9 ) ;
if ( V_10 )
goto V_628;
if ( V_9 -> V_376 && V_9 -> V_376 -> V_626 ) {
V_10 = V_9 -> V_376 -> V_626 ( V_9 , V_612 ) ;
if ( V_10 )
goto V_629;
}
if ( F_48 ( V_9 ) ) {
V_10 = F_49 ( V_9 ) ;
if ( ! V_10 )
F_50 ( V_9 ) ;
else
goto V_630;
} else if ( F_301 ( V_9 ) ) {
V_10 = F_169 ( V_9 ) ;
if ( V_10 || ! F_64 ( V_9 ) )
goto V_630;
}
if ( ! F_302 ( V_9 ) ) {
V_10 = F_290 ( V_9 , V_618 ) ;
if ( V_10 )
goto V_631;
}
F_215 ( V_9 ) ;
V_9 -> V_75 . V_83 = false ;
if ( F_51 ( V_9 ) )
F_52 ( V_9 -> V_84 ) ;
F_68 ( V_9 ) ;
goto V_44;
V_631:
F_298 ( V_9 , V_627 , 0 ) ;
V_630:
if ( V_9 -> V_376 && V_9 -> V_376 -> V_623 )
V_9 -> V_376 -> V_623 ( V_9 , V_612 ) ;
V_629:
F_299 ( V_9 ) ;
V_628:
F_6 ( V_9 ) ;
F_46 ( V_9 , false ) ;
V_44:
V_9 -> V_556 = 0 ;
return V_10 ;
}
int F_311 ( struct V_8 * V_9 )
{
int V_10 = 0 ;
if ( ! V_9 || ! V_9 -> V_589 )
return 0 ;
if ( F_312 ( V_9 -> V_16 ) ) {
if ( V_9 -> V_615 == V_9 -> V_616 )
if ( ( F_1 ( V_9 -> V_616 ) ==
V_9 -> V_604 ) && ! V_9 -> V_461 )
goto V_44;
V_10 = F_313 ( V_9 ) ;
if ( V_10 )
goto V_44;
}
V_10 = F_306 ( V_9 , V_632 ) ;
V_44:
if ( ! V_10 )
V_9 -> V_633 = true ;
return V_10 ;
}
int F_314 ( struct V_8 * V_9 )
{
if ( ! V_9 || ! V_9 -> V_589 || F_312 ( V_9 -> V_16 ) )
return 0 ;
return F_310 ( V_9 , V_632 ) ;
}
int F_315 ( struct V_8 * V_9 )
{
if ( ! V_9 || ! V_9 -> V_589 )
return 0 ;
return F_306 ( V_9 , V_634 ) ;
}
int F_313 ( struct V_8 * V_9 )
{
if ( ! V_9 || ! V_9 -> V_589 )
return 0 ;
else
return F_310 ( V_9 , V_634 ) ;
}
int F_316 ( struct V_8 * V_9 )
{
return 0 ;
}
int F_317 ( struct V_8 * V_9 )
{
int V_10 = 0 ;
if ( F_300 ( V_9 ) && F_301 ( V_9 ) )
goto V_44;
if ( F_312 ( V_9 -> V_16 ) ) {
V_10 = F_313 ( V_9 ) ;
if ( V_10 )
goto V_44;
}
V_10 = F_306 ( V_9 , V_635 ) ;
V_44:
if ( V_10 )
F_5 ( V_9 -> V_16 , L_97 , V_17 , V_10 ) ;
return 0 ;
}
void F_318 ( struct V_8 * V_9 )
{
F_319 ( V_9 -> V_78 ) ;
F_116 ( V_9 , V_9 -> V_636 ) ;
F_181 ( V_9 ) ;
F_320 ( V_9 -> V_78 ) ;
F_78 ( V_9 ) ;
if ( F_51 ( V_9 ) )
F_321 ( V_9 -> V_84 ) ;
F_255 ( V_9 ) ;
}
static int F_322 ( struct V_8 * V_9 )
{
if ( V_9 -> V_151 & V_637 ) {
if ( ! F_323 ( V_9 -> V_16 , F_324 ( 64 ) ) )
return 0 ;
}
return F_323 ( V_9 -> V_16 , F_324 ( 32 ) ) ;
}
int F_325 ( struct V_103 * V_16 , struct V_8 * * V_638 )
{
struct V_236 * V_78 ;
struct V_8 * V_9 ;
int V_23 = 0 ;
if ( ! V_16 ) {
F_5 ( V_16 ,
L_98 ) ;
V_23 = - V_597 ;
goto V_639;
}
V_78 = F_326 ( & V_640 ,
sizeof( struct V_8 ) ) ;
if ( ! V_78 ) {
F_5 ( V_16 , L_99 ) ;
V_23 = - V_297 ;
goto V_639;
}
V_9 = F_128 ( V_78 ) ;
V_9 -> V_78 = V_78 ;
V_9 -> V_16 = V_16 ;
* V_638 = V_9 ;
V_639:
return V_23 ;
}
static int F_327 ( struct V_8 * V_9 , bool V_641 )
{
int V_10 = 0 ;
struct V_574 * V_575 ;
struct V_576 * V_577 = & V_9 -> V_578 ;
if ( ! V_577 || F_275 ( V_577 ) )
goto V_44;
F_276 (clki, head, list) {
if ( ! F_277 ( V_575 -> V_579 ) ) {
if ( V_641 && V_575 -> V_581 ) {
if ( V_575 -> V_582 == V_575 -> V_581 )
continue;
V_10 = F_282 ( V_575 -> V_579 , V_575 -> V_581 ) ;
if ( V_10 ) {
F_5 ( V_9 -> V_16 , L_92 ,
V_17 , V_575 -> V_114 ,
V_575 -> V_581 , V_10 ) ;
break;
}
V_575 -> V_582 = V_575 -> V_581 ;
} else if ( ! V_641 && V_575 -> V_642 ) {
if ( V_575 -> V_582 == V_575 -> V_642 )
continue;
V_10 = F_282 ( V_575 -> V_579 , V_575 -> V_642 ) ;
if ( V_10 ) {
F_5 ( V_9 -> V_16 , L_92 ,
V_17 , V_575 -> V_114 ,
V_575 -> V_642 , V_10 ) ;
break;
}
V_575 -> V_582 = V_575 -> V_642 ;
}
}
F_175 ( V_9 -> V_16 , L_93 , V_17 ,
V_575 -> V_114 , F_283 ( V_575 -> V_579 ) ) ;
}
if ( V_9 -> V_376 -> V_643 )
V_9 -> V_376 -> V_643 ( V_9 ) ;
V_44:
return V_10 ;
}
static int F_328 ( struct V_103 * V_16 ,
unsigned long * V_644 , T_1 V_74 )
{
int V_23 = 0 ;
struct V_8 * V_9 = F_70 ( V_16 ) ;
if ( ! F_51 ( V_9 ) )
return - V_110 ;
if ( * V_644 == V_645 )
V_23 = F_327 ( V_9 , true ) ;
else if ( * V_644 == 0 )
V_23 = F_327 ( V_9 , false ) ;
return V_23 ;
}
static int F_329 ( struct V_103 * V_16 ,
struct V_646 * V_647 )
{
struct V_8 * V_9 = F_70 ( V_16 ) ;
struct V_120 * V_121 = & V_9 -> V_100 ;
unsigned long V_74 ;
if ( ! F_51 ( V_9 ) )
return - V_110 ;
memset ( V_647 , 0 , sizeof( * V_647 ) ) ;
F_44 ( V_9 -> V_78 -> V_79 , V_74 ) ;
if ( ! V_121 -> V_101 )
goto V_648;
if ( V_121 -> V_118 )
V_121 -> V_123 += F_84 ( F_85 ( F_82 () ,
V_121 -> V_119 ) ) ;
V_647 -> V_649 = F_330 ( ( long ) V_25 -
( long ) V_121 -> V_101 ) ;
V_647 -> V_650 = V_121 -> V_123 ;
V_648:
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
int F_331 ( struct V_8 * V_9 , void T_9 * V_651 , unsigned int V_12 )
{
int V_23 ;
struct V_236 * V_78 = V_9 -> V_78 ;
struct V_103 * V_16 = V_9 -> V_16 ;
if ( ! V_651 ) {
F_5 ( V_9 -> V_16 ,
L_100 ) ;
V_23 = - V_597 ;
goto V_639;
}
V_9 -> V_651 = V_651 ;
V_9 -> V_12 = V_12 ;
V_23 = F_286 ( V_9 ) ;
if ( V_23 )
goto V_639;
F_95 ( V_9 ) ;
V_9 -> V_27 = F_14 ( V_9 ) ;
V_9 -> V_636 = F_13 ( V_9 ) ;
V_23 = F_322 ( V_9 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_101 ) ;
goto V_652;
}
V_23 = F_155 ( V_9 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_102 ) ;
goto V_652;
}
F_158 ( V_9 ) ;
V_78 -> V_653 = V_9 -> V_153 ;
V_78 -> V_654 = V_9 -> V_153 ;
V_78 -> V_655 = V_656 ;
V_78 -> V_657 = V_658 ;
V_78 -> V_659 = V_660 ;
V_78 -> V_661 = V_78 -> V_662 ;
V_78 -> V_663 = V_664 ;
V_9 -> V_358 . V_360 = false ;
F_332 ( & V_9 -> V_492 ) ;
F_332 ( & V_9 -> V_508 ) ;
F_75 ( & V_9 -> V_472 , F_220 ) ;
F_75 ( & V_9 -> V_444 , F_217 ) ;
F_333 ( & V_9 -> V_169 ) ;
F_333 ( & V_9 -> V_134 . V_270 ) ;
F_332 ( & V_9 -> V_134 . V_261 ) ;
F_73 ( V_9 ) ;
V_23 = F_334 ( V_16 , V_12 , V_13 , V_14 , V_15 , V_9 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_103 ) ;
goto V_665;
} else {
V_9 -> V_11 = true ;
}
V_23 = F_335 ( V_78 , V_78 -> V_653 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_104 ) ;
goto V_665;
}
V_23 = F_336 ( V_78 , V_9 -> V_16 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_105 ) ;
goto V_665;
}
V_23 = F_180 ( V_9 ) ;
if ( V_23 ) {
F_5 ( V_9 -> V_16 , L_106 ) ;
goto V_666;
}
if ( F_51 ( V_9 ) ) {
V_9 -> V_84 = F_337 ( V_16 , & V_667 ,
L_107 , NULL ) ;
if ( F_248 ( V_9 -> V_84 ) ) {
F_5 ( V_9 -> V_16 , L_108 ,
F_249 ( V_9 -> V_84 ) ) ;
goto V_666;
}
F_63 ( V_9 -> V_84 ) ;
V_9 -> V_100 . V_101 = 0 ;
}
F_218 ( V_16 ) ;
F_338 ( V_9 ) ;
F_339 ( F_256 , V_9 ) ;
return 0 ;
V_666:
F_319 ( V_9 -> V_78 ) ;
V_665:
F_78 ( V_9 ) ;
V_652:
V_9 -> V_11 = false ;
F_320 ( V_78 ) ;
F_255 ( V_9 ) ;
V_639:
return V_23 ;
}

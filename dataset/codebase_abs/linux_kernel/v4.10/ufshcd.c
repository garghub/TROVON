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
T_1 V_30 = 0 ;
switch ( V_9 -> V_31 ) {
case V_32 :
V_30 = V_33 ;
break;
case V_34 :
case V_35 :
V_30 = V_36 ;
break;
case V_37 :
default:
V_30 = V_38 ;
}
return V_30 ;
}
static inline T_1 F_17 ( struct V_8 * V_9 )
{
if ( V_9 -> V_39 & V_40 )
return F_18 ( V_9 ) ;
return F_12 ( V_9 , V_41 ) ;
}
static inline int F_19 ( struct V_8 * V_9 )
{
return ( F_12 ( V_9 , V_42 ) &
V_43 ) ? 1 : 0 ;
}
static inline int F_20 ( struct V_44 * V_45 )
{
return F_21 ( V_45 -> V_46 -> V_47 . V_48 ) & V_49 ;
}
static inline int
F_22 ( struct V_50 * V_51 )
{
return F_21 ( V_51 -> V_47 . V_48 ) & V_49 ;
}
static bool F_23 ( struct V_8 * V_9 , int * V_52 )
{
int V_10 ;
bool V_12 = false ;
if ( ! V_52 )
goto V_53;
do {
V_10 = F_24 ( & V_9 -> V_54 , V_9 -> V_55 ) ;
if ( V_10 >= V_9 -> V_55 )
goto V_53;
} while ( F_25 ( V_10 , & V_9 -> V_54 ) );
* V_52 = V_10 ;
V_12 = true ;
V_53:
return V_12 ;
}
static inline void F_26 ( struct V_8 * V_9 , int V_56 )
{
F_27 ( V_56 , & V_9 -> V_54 ) ;
}
static inline void F_28 ( struct V_8 * V_9 , T_1 V_57 )
{
F_29 ( V_9 , ~ ( 1 << V_57 ) , V_58 ) ;
}
static inline void F_30 ( struct V_8 * V_9 , int V_10 )
{
F_31 ( V_10 , & V_9 -> V_59 ) ;
}
static inline int F_32 ( T_1 V_21 )
{
return ( ( V_21 & 0xFF ) >> 1 ) ^ 0x07 ;
}
static inline int F_33 ( struct V_8 * V_9 )
{
return F_12 ( V_9 , V_60 ) &
V_61 ;
}
static inline T_1 F_34 ( struct V_8 * V_9 )
{
return F_12 ( V_9 , V_62 ) ;
}
static inline int
F_35 ( struct V_63 * V_64 )
{
return F_36 ( V_64 -> V_47 . V_65 ) >> 24 ;
}
static inline int
F_37 ( struct V_63 * V_64 )
{
return F_36 ( V_64 -> V_47 . V_66 ) & V_67 ;
}
static inline unsigned int
F_38 ( struct V_63 * V_64 )
{
return F_36 ( V_64 -> V_47 . V_48 ) &
V_68 ;
}
static inline bool F_39 ( struct V_63 * V_64 )
{
return F_36 ( V_64 -> V_47 . V_48 ) &
V_69 ? true : false ;
}
static inline void
F_40 ( struct V_8 * V_9 )
{
F_29 ( V_9 , V_70 |
V_71 ,
V_72 ) ;
}
static inline void
F_41 ( struct V_8 * V_9 , T_2 V_73 , T_2 V_74 )
{
F_29 ( V_9 , V_70 | V_75 |
F_42 ( V_73 ) |
F_43 ( V_74 ) ,
V_72 ) ;
}
static inline void F_44 ( struct V_8 * V_9 )
{
F_29 ( V_9 , 0 , V_72 ) ;
}
static void F_45 ( struct V_8 * V_9 )
{
F_29 ( V_9 , V_76 ,
V_77 ) ;
F_29 ( V_9 , V_78 ,
V_79 ) ;
}
static inline void F_46 ( struct V_8 * V_9 )
{
F_29 ( V_9 , V_80 , V_81 ) ;
}
static inline int F_47 ( struct V_8 * V_9 )
{
return ( F_12 ( V_9 , V_81 ) & 0x1 ) ? 0 : 1 ;
}
T_1 F_48 ( struct V_8 * V_9 )
{
if ( ( V_9 -> V_31 == V_32 ) ||
( V_9 -> V_31 == V_34 ) )
return V_82 ;
else
return V_83 ;
}
static bool F_49 ( struct V_8 * V_9 )
{
if ( F_48 ( V_9 ) < V_83 )
return true ;
else
return false ;
}
static void F_50 ( struct V_8 * V_9 )
{
if ( F_51 ( V_9 ) ) {
F_52 ( V_9 -> V_84 ) ;
V_9 -> V_85 . V_86 = 0 ;
}
}
static void F_53 ( struct V_8 * V_9 )
{
if ( F_51 ( V_9 ) )
F_54 ( V_9 -> V_84 ) ;
}
static void F_55 ( struct V_87 * V_88 )
{
int V_12 ;
unsigned long V_89 ;
struct V_8 * V_9 = F_56 ( V_88 , struct V_8 ,
V_90 . V_91 ) ;
F_57 ( & V_9 -> V_90 . V_92 ) ;
F_58 ( V_9 -> V_93 -> V_94 , V_89 ) ;
if ( V_9 -> V_90 . V_95 == V_96 ) {
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
goto V_97;
}
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
F_60 ( V_9 , true ) ;
if ( F_61 ( V_9 ) ) {
V_9 -> V_90 . V_98 = true ;
if ( F_62 ( V_9 ) ) {
V_12 = F_63 ( V_9 ) ;
if ( V_12 )
F_6 ( V_9 -> V_18 , L_2 ,
V_19 , V_12 ) ;
else
F_64 ( V_9 ) ;
}
V_9 -> V_90 . V_98 = false ;
}
V_97:
F_53 ( V_9 ) ;
F_65 ( V_9 -> V_93 ) ;
}
int F_66 ( struct V_8 * V_9 , bool V_99 )
{
int V_100 = 0 ;
unsigned long V_89 ;
if ( ! F_67 ( V_9 ) )
goto V_53;
F_58 ( V_9 -> V_93 -> V_94 , V_89 ) ;
V_9 -> V_90 . V_101 ++ ;
if ( F_68 ( V_9 ) ) {
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
return 0 ;
}
V_102:
switch ( V_9 -> V_90 . V_95 ) {
case V_96 :
if ( F_61 ( V_9 ) &&
F_62 ( V_9 ) ) {
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
F_69 ( & V_9 -> V_90 . V_91 ) ;
F_58 ( V_9 -> V_93 -> V_94 , V_89 ) ;
goto V_102;
}
break;
case V_103 :
if ( F_70 ( & V_9 -> V_90 . V_92 ) ) {
V_9 -> V_90 . V_95 = V_96 ;
break;
}
case V_104 :
F_71 ( V_9 -> V_93 ) ;
V_9 -> V_90 . V_95 = V_105 ;
F_72 ( & V_9 -> V_90 . V_91 ) ;
case V_105 :
if ( V_99 ) {
V_100 = - V_106 ;
V_9 -> V_90 . V_101 -- ;
break;
}
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
F_69 ( & V_9 -> V_90 . V_91 ) ;
F_58 ( V_9 -> V_93 -> V_94 , V_89 ) ;
goto V_102;
default:
F_6 ( V_9 -> V_18 , L_3 ,
V_19 , V_9 -> V_90 . V_95 ) ;
break;
}
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
V_53:
return V_100 ;
}
static void F_73 ( struct V_87 * V_88 )
{
struct V_8 * V_9 = F_56 ( V_88 , struct V_8 ,
V_90 . V_92 . V_88 ) ;
unsigned long V_89 ;
F_58 ( V_9 -> V_93 -> V_94 , V_89 ) ;
if ( V_9 -> V_90 . V_98 ||
( V_9 -> V_90 . V_95 == V_105 ) ) {
V_9 -> V_90 . V_95 = V_96 ;
goto V_107;
}
if ( V_9 -> V_90 . V_101
|| V_9 -> V_108 != V_109
|| V_9 -> V_110 || V_9 -> V_111
|| V_9 -> V_112 || V_9 -> V_113 )
goto V_107;
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
if ( F_61 ( V_9 ) ) {
if ( F_74 ( V_9 ) ) {
V_9 -> V_90 . V_95 = V_96 ;
goto V_53;
}
F_75 ( V_9 ) ;
}
F_50 ( V_9 ) ;
if ( ! F_76 ( V_9 ) )
F_60 ( V_9 , false ) ;
else
F_77 ( V_9 , false , true ) ;
F_58 ( V_9 -> V_93 -> V_94 , V_89 ) ;
if ( V_9 -> V_90 . V_95 == V_103 )
V_9 -> V_90 . V_95 = V_104 ;
V_107:
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
V_53:
return;
}
static void F_78 ( struct V_8 * V_9 )
{
if ( ! F_67 ( V_9 ) )
return;
V_9 -> V_90 . V_101 -- ;
if ( V_9 -> V_90 . V_101 || V_9 -> V_90 . V_98
|| V_9 -> V_108 != V_109
|| V_9 -> V_110 || V_9 -> V_111
|| V_9 -> V_112 || V_9 -> V_113
|| F_68 ( V_9 ) )
return;
V_9 -> V_90 . V_95 = V_103 ;
F_79 ( & V_9 -> V_90 . V_92 ,
F_11 ( V_9 -> V_90 . V_114 ) ) ;
}
void F_80 ( struct V_8 * V_9 )
{
unsigned long V_89 ;
F_58 ( V_9 -> V_93 -> V_94 , V_89 ) ;
F_78 ( V_9 ) ;
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
}
static T_3 F_81 ( struct V_115 * V_18 ,
struct V_116 * V_117 , char * V_118 )
{
struct V_8 * V_9 = F_82 ( V_18 ) ;
return snprintf ( V_118 , V_119 , L_4 , V_9 -> V_90 . V_114 ) ;
}
static T_3 F_83 ( struct V_115 * V_18 ,
struct V_116 * V_117 , const char * V_118 , T_4 V_120 )
{
struct V_8 * V_9 = F_82 ( V_18 ) ;
unsigned long V_89 , V_121 ;
if ( F_84 ( V_118 , 0 , & V_121 ) )
return - V_122 ;
F_58 ( V_9 -> V_93 -> V_94 , V_89 ) ;
V_9 -> V_90 . V_114 = V_121 ;
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
return V_120 ;
}
static void F_85 ( struct V_8 * V_9 )
{
if ( ! F_67 ( V_9 ) )
return;
V_9 -> V_90 . V_114 = 150 ;
F_86 ( & V_9 -> V_90 . V_92 , F_73 ) ;
F_87 ( & V_9 -> V_90 . V_91 , F_55 ) ;
V_9 -> V_90 . V_123 . V_124 = F_81 ;
V_9 -> V_90 . V_123 . V_125 = F_83 ;
F_88 ( & V_9 -> V_90 . V_123 . V_117 ) ;
V_9 -> V_90 . V_123 . V_117 . V_126 = L_5 ;
V_9 -> V_90 . V_123 . V_117 . V_127 = V_128 | V_129 ;
if ( F_89 ( V_9 -> V_18 , & V_9 -> V_90 . V_123 ) )
F_6 ( V_9 -> V_18 , L_6 ) ;
}
static void F_90 ( struct V_8 * V_9 )
{
if ( ! F_67 ( V_9 ) )
return;
F_91 ( V_9 -> V_18 , & V_9 -> V_90 . V_123 ) ;
F_92 ( & V_9 -> V_90 . V_91 ) ;
F_57 ( & V_9 -> V_90 . V_92 ) ;
}
static void F_93 ( struct V_8 * V_9 )
{
if ( ! F_51 ( V_9 ) )
return;
if ( ! V_9 -> V_85 . V_130 ) {
V_9 -> V_85 . V_131 = F_94 () ;
V_9 -> V_85 . V_130 = true ;
}
}
static void F_95 ( struct V_8 * V_9 )
{
struct V_132 * V_133 = & V_9 -> V_85 ;
if ( ! F_51 ( V_9 ) )
return;
if ( ! V_9 -> V_59 && V_133 -> V_130 ) {
V_133 -> V_134 += F_96 ( F_97 ( F_94 () ,
V_133 -> V_131 ) ) ;
V_133 -> V_131 = 0 ;
V_133 -> V_130 = false ;
}
}
static inline
void F_98 ( struct V_8 * V_9 , unsigned int V_135 )
{
F_93 ( V_9 ) ;
F_99 ( V_135 , & V_9 -> V_59 ) ;
F_29 ( V_9 , 1 << V_135 , V_136 ) ;
F_100 () ;
}
static inline void F_101 ( struct V_44 * V_45 )
{
int V_137 ;
if ( V_45 -> V_138 &&
F_38 ( V_45 -> V_64 ) ) {
int V_139 ;
V_137 = F_102 ( V_45 -> V_64 -> V_140 . V_141 ) ;
V_139 = F_103 ( int , V_142 , V_137 ) ;
memcpy ( V_45 -> V_138 ,
V_45 -> V_64 -> V_140 . V_143 ,
F_103 ( int , V_139 , V_144 ) ) ;
}
}
static
int F_104 ( struct V_8 * V_9 , struct V_44 * V_45 )
{
struct V_145 * V_146 = & V_9 -> V_147 . V_148 . V_149 ;
memcpy ( & V_146 -> V_150 , & V_45 -> V_64 -> V_151 , V_152 ) ;
if ( V_45 -> V_64 -> V_151 . V_153 == V_154 ) {
T_2 * V_155 = ( T_2 * ) V_45 -> V_64 +
V_156 ;
T_5 V_157 ;
T_5 V_158 ;
V_157 = F_36 ( V_45 -> V_64 -> V_47 . V_48 ) &
V_159 ;
V_158 = F_102 (
V_9 -> V_147 . V_148 . V_160 . V_161 . V_162 ) ;
if ( F_105 ( V_158 >= V_157 ) ) {
memcpy ( V_9 -> V_147 . V_148 . V_163 , V_155 , V_157 ) ;
} else {
F_106 ( V_9 -> V_18 ,
L_7 ,
V_19 ) ;
return - V_122 ;
}
}
return 0 ;
}
static inline void F_107 ( struct V_8 * V_9 )
{
V_9 -> V_164 = F_12 ( V_9 , V_165 ) ;
V_9 -> V_11 = ( V_9 -> V_164 & V_166 ) + 1 ;
V_9 -> V_55 =
( ( V_9 -> V_164 & V_167 ) >> 16 ) + 1 ;
}
static inline bool F_108 ( struct V_8 * V_9 )
{
if ( F_12 ( V_9 , V_42 ) & V_168 )
return true ;
else
return false ;
}
static inline T_2 F_109 ( struct V_8 * V_9 )
{
return ( F_12 ( V_9 , V_42 ) >> 8 ) & 0x7 ;
}
static inline void
F_110 ( struct V_8 * V_9 , struct V_169 * V_170 )
{
F_111 ( V_9 -> V_112 ) ;
V_9 -> V_112 = V_170 ;
F_29 ( V_9 , V_170 -> V_171 , V_172 ) ;
F_29 ( V_9 , V_170 -> V_173 , V_60 ) ;
F_29 ( V_9 , V_170 -> V_174 , V_62 ) ;
F_29 ( V_9 , V_170 -> V_175 & V_176 ,
V_177 ) ;
}
static int
F_112 ( struct V_8 * V_9 , struct V_169 * V_170 )
{
int V_12 ;
unsigned long V_89 ;
if ( F_113 ( & V_170 -> V_178 ,
F_11 ( V_179 ) ) )
V_12 = V_170 -> V_173 & V_61 ;
else
V_12 = - V_29 ;
F_58 ( V_9 -> V_93 -> V_94 , V_89 ) ;
V_9 -> V_112 = NULL ;
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
return V_12 ;
}
static int
F_114 ( struct V_8 * V_9 , struct V_169 * V_170 ,
bool V_180 )
{
if ( ! F_108 ( V_9 ) ) {
F_6 ( V_9 -> V_18 ,
L_8 ) ;
return - V_181 ;
}
if ( V_180 )
F_115 ( & V_170 -> V_178 ) ;
F_110 ( V_9 , V_170 ) ;
return 0 ;
}
static int
F_116 ( struct V_8 * V_9 , struct V_169 * V_170 )
{
int V_12 ;
unsigned long V_89 ;
F_66 ( V_9 , false ) ;
F_117 ( & V_9 -> V_182 ) ;
F_118 ( V_9 ) ;
F_58 ( V_9 -> V_93 -> V_94 , V_89 ) ;
V_12 = F_114 ( V_9 , V_170 , true ) ;
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
if ( ! V_12 )
V_12 = F_112 ( V_9 , V_170 ) ;
F_119 ( & V_9 -> V_182 ) ;
F_80 ( V_9 ) ;
return V_12 ;
}
static int F_120 ( struct V_8 * V_9 , struct V_44 * V_45 )
{
struct V_183 * V_184 ;
struct V_185 * V_186 ;
struct V_187 * V_188 ;
int V_189 ;
int V_190 ;
V_188 = V_45 -> V_188 ;
V_189 = F_121 ( V_188 ) ;
if ( V_189 < 0 )
return V_189 ;
if ( V_189 ) {
if ( V_9 -> V_39 & V_191 )
V_45 -> V_46 -> V_192 =
F_122 ( ( T_5 ) ( V_189 *
sizeof( struct V_183 ) ) ) ;
else
V_45 -> V_46 -> V_192 =
F_122 ( ( T_5 ) ( V_189 ) ) ;
V_184 = (struct V_183 * ) V_45 -> V_193 ;
F_123 (cmd, sg, sg_segments, i) {
V_184 [ V_190 ] . V_194 =
F_124 ( ( ( T_1 ) F_125 ( V_186 ) ) - 1 ) ;
V_184 [ V_190 ] . V_195 =
F_124 ( F_126 ( V_186 -> V_196 ) ) ;
V_184 [ V_190 ] . V_197 =
F_124 ( F_127 ( V_186 -> V_196 ) ) ;
V_184 [ V_190 ] . V_198 = 0 ;
}
} else {
V_45 -> V_46 -> V_192 = 0 ;
}
return 0 ;
}
static void F_128 ( struct V_8 * V_9 , T_1 V_199 )
{
T_1 V_200 = F_12 ( V_9 , V_201 ) ;
if ( V_9 -> V_31 == V_32 ) {
T_1 V_202 ;
V_202 = V_200 & V_203 ;
V_200 = V_202 | ( ( V_200 ^ V_199 ) & V_199 ) ;
} else {
V_200 |= V_199 ;
}
F_29 ( V_9 , V_200 , V_201 ) ;
}
static void F_129 ( struct V_8 * V_9 , T_1 V_199 )
{
T_1 V_200 = F_12 ( V_9 , V_201 ) ;
if ( V_9 -> V_31 == V_32 ) {
T_1 V_202 ;
V_202 = ( V_200 & V_203 ) &
~ ( V_199 & V_203 ) ;
V_200 = V_202 | ( ( V_200 & V_199 ) & ~ V_203 ) ;
} else {
V_200 &= ~ V_199 ;
}
F_29 ( V_9 , V_200 , V_201 ) ;
}
static void F_130 ( struct V_44 * V_45 ,
T_1 * V_204 , enum V_205 V_206 )
{
struct V_207 * V_208 = V_45 -> V_46 ;
T_1 V_209 ;
T_1 V_65 ;
if ( V_206 == V_210 ) {
V_209 = V_211 ;
* V_204 = V_212 ;
} else if ( V_206 == V_213 ) {
V_209 = V_214 ;
* V_204 = V_215 ;
} else {
V_209 = V_216 ;
* V_204 = V_217 ;
}
V_65 = V_209 | ( V_45 -> V_218
<< V_219 ) ;
if ( V_45 -> V_220 )
V_65 |= V_221 ;
V_208 -> V_47 . V_65 = F_124 ( V_65 ) ;
V_208 -> V_47 . V_66 = 0 ;
V_208 -> V_47 . V_48 =
F_124 ( V_222 ) ;
V_208 -> V_47 . V_223 = 0 ;
V_208 -> V_192 = 0 ;
}
static
void F_131 ( struct V_44 * V_45 , T_1 V_204 )
{
struct V_224 * V_225 = V_45 -> V_225 ;
unsigned short V_226 ;
V_225 -> V_47 . V_65 = F_132 (
V_227 , V_204 ,
V_45 -> V_228 , V_45 -> V_135 ) ;
V_225 -> V_47 . V_66 = F_132 (
V_229 , 0 , 0 , 0 ) ;
V_225 -> V_47 . V_48 = 0 ;
V_225 -> V_230 . V_231 =
F_133 ( V_45 -> V_188 -> V_232 . V_162 ) ;
V_226 = F_103 (unsigned short, lrbp->cmd->cmd_len, MAX_CDB_SIZE) ;
memset ( V_225 -> V_230 . V_233 , 0 , V_234 ) ;
memcpy ( V_225 -> V_230 . V_233 , V_45 -> V_188 -> V_235 , V_226 ) ;
memset ( V_45 -> V_64 , 0 , sizeof( struct V_63 ) ) ;
}
static void F_134 ( struct V_8 * V_9 ,
struct V_44 * V_45 , T_1 V_204 )
{
struct V_224 * V_225 = V_45 -> V_225 ;
struct V_236 * V_148 = & V_9 -> V_147 . V_148 ;
T_5 V_137 = F_102 ( V_148 -> V_160 . V_161 . V_162 ) ;
T_2 * V_155 = ( T_2 * ) V_45 -> V_225 + V_156 ;
V_225 -> V_47 . V_65 = F_132 (
V_237 , V_204 ,
V_45 -> V_228 , V_45 -> V_135 ) ;
V_225 -> V_47 . V_66 = F_132 (
0 , V_148 -> V_160 . V_238 , 0 , 0 ) ;
if ( V_148 -> V_160 . V_161 . V_153 == V_239 )
V_225 -> V_47 . V_48 =
F_132 ( 0 , 0 , ( V_137 >> 8 ) , ( T_2 ) V_137 ) ;
else
V_225 -> V_47 . V_48 = 0 ;
memcpy ( & V_225 -> V_151 , & V_148 -> V_160 . V_161 ,
V_152 ) ;
if ( V_148 -> V_160 . V_161 . V_153 == V_239 )
memcpy ( V_155 , V_148 -> V_163 , V_137 ) ;
memset ( V_45 -> V_64 , 0 , sizeof( struct V_63 ) ) ;
}
static inline void F_135 ( struct V_44 * V_45 )
{
struct V_224 * V_225 = V_45 -> V_225 ;
memset ( V_225 , 0 , sizeof( struct V_224 ) ) ;
V_225 -> V_47 . V_65 =
F_132 (
V_240 , 0 , 0 , V_45 -> V_135 ) ;
V_225 -> V_47 . V_66 = 0 ;
V_225 -> V_47 . V_48 = 0 ;
memset ( V_45 -> V_64 , 0 , sizeof( struct V_63 ) ) ;
}
static int F_136 ( struct V_8 * V_9 , struct V_44 * V_45 )
{
T_1 V_204 ;
int V_12 = 0 ;
if ( V_9 -> V_31 == V_35 )
V_45 -> V_218 = V_241 ;
else
V_45 -> V_218 = V_242 ;
F_130 ( V_45 , & V_204 , V_243 ) ;
if ( V_9 -> V_147 . type == V_244 )
F_134 ( V_9 , V_45 , V_204 ) ;
else if ( V_9 -> V_147 . type == V_245 )
F_135 ( V_45 ) ;
else
V_12 = - V_122 ;
return V_12 ;
}
static int F_137 ( struct V_8 * V_9 , struct V_44 * V_45 )
{
T_1 V_204 ;
int V_12 = 0 ;
if ( V_9 -> V_31 == V_35 )
V_45 -> V_218 = V_241 ;
else
V_45 -> V_218 = V_246 ;
if ( F_105 ( V_45 -> V_188 ) ) {
F_130 ( V_45 , & V_204 ,
V_45 -> V_188 -> V_247 ) ;
F_131 ( V_45 , V_204 ) ;
} else {
V_12 = - V_122 ;
}
return V_12 ;
}
static inline T_2 F_138 ( unsigned int V_248 )
{
if ( F_139 ( V_248 ) )
return ( V_248 & V_249 )
| V_250 ;
else
return V_248 & V_249 ;
}
static inline T_5 F_140 ( T_2 V_251 )
{
return ( V_251 & ~ V_250 ) | V_252 ;
}
static int F_141 ( struct V_253 * V_93 , struct V_187 * V_188 )
{
struct V_44 * V_45 ;
struct V_8 * V_9 ;
unsigned long V_89 ;
int V_10 ;
int V_26 = 0 ;
V_9 = F_142 ( V_93 ) ;
V_10 = V_188 -> V_160 -> V_10 ;
if ( ! F_3 ( V_9 , V_10 ) ) {
F_6 ( V_9 -> V_18 ,
L_9 ,
V_19 , V_10 , V_188 , V_188 -> V_160 ) ;
F_143 () ;
}
F_58 ( V_9 -> V_93 -> V_94 , V_89 ) ;
switch ( V_9 -> V_108 ) {
case V_109 :
break;
case V_254 :
case V_255 :
V_26 = V_256 ;
goto V_257;
case V_258 :
F_144 ( V_188 , V_259 ) ;
V_188 -> V_260 ( V_188 ) ;
goto V_257;
default:
F_145 ( V_9 -> V_18 , 1 , L_10 ,
V_19 , V_9 -> V_108 ) ;
F_144 ( V_188 , V_261 ) ;
V_188 -> V_260 ( V_188 ) ;
goto V_257;
}
if ( F_68 ( V_9 ) ) {
F_144 ( V_188 , V_259 ) ;
V_188 -> V_260 ( V_188 ) ;
goto V_257;
}
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
if ( F_25 ( V_10 , & V_9 -> V_110 ) ) {
V_26 = V_256 ;
goto V_53;
}
V_26 = F_66 ( V_9 , true ) ;
if ( V_26 ) {
V_26 = V_256 ;
F_27 ( V_10 , & V_9 -> V_110 ) ;
goto V_53;
}
F_111 ( V_9 -> V_90 . V_95 != V_96 ) ;
V_45 = & V_9 -> V_262 [ V_10 ] ;
F_111 ( V_45 -> V_188 ) ;
V_45 -> V_188 = V_188 ;
V_45 -> V_263 = V_144 ;
V_45 -> V_138 = V_188 -> V_138 ;
V_45 -> V_135 = V_10 ;
V_45 -> V_228 = F_138 ( V_188 -> V_115 -> V_228 ) ;
V_45 -> V_220 = ! F_146 ( V_9 ) ? true : false ;
F_137 ( V_9 , V_45 ) ;
V_26 = F_120 ( V_9 , V_45 ) ;
if ( V_26 ) {
V_45 -> V_188 = NULL ;
F_27 ( V_10 , & V_9 -> V_110 ) ;
goto V_53;
}
F_100 () ;
F_58 ( V_9 -> V_93 -> V_94 , V_89 ) ;
F_147 ( V_9 , V_10 , ( V_45 -> V_188 ? true : false ) ) ;
F_98 ( V_9 , V_10 ) ;
V_257:
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
V_53:
return V_26 ;
}
static int F_148 ( struct V_8 * V_9 ,
struct V_44 * V_45 , enum V_264 V_265 , int V_10 )
{
V_45 -> V_188 = NULL ;
V_45 -> V_263 = 0 ;
V_45 -> V_138 = NULL ;
V_45 -> V_135 = V_10 ;
V_45 -> V_228 = 0 ;
V_45 -> V_220 = true ;
V_9 -> V_147 . type = V_265 ;
return F_136 ( V_9 , V_45 ) ;
}
static int
F_149 ( struct V_8 * V_9 , int V_10 )
{
int V_26 = 0 ;
unsigned long V_89 ;
T_1 V_22 = 1 << V_10 ;
F_58 ( V_9 -> V_93 -> V_94 , V_89 ) ;
F_28 ( V_9 , V_10 ) ;
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
V_26 = F_10 ( V_9 ,
V_136 ,
V_22 , ~ V_22 , 1000 , 1000 , true ) ;
return V_26 ;
}
static int
F_150 ( struct V_8 * V_9 , struct V_44 * V_45 )
{
struct V_145 * V_146 = & V_9 -> V_147 . V_148 . V_149 ;
V_146 -> V_149 = F_37 ( V_45 -> V_64 ) >>
V_266 ;
return V_146 -> V_149 ;
}
static int
F_151 ( struct V_8 * V_9 , struct V_44 * V_45 )
{
int V_267 ;
int V_26 = 0 ;
V_267 = F_35 ( V_45 -> V_64 ) ;
switch ( V_267 ) {
case V_268 :
if ( V_9 -> V_147 . type != V_245 ) {
V_26 = - V_122 ;
F_6 ( V_9 -> V_18 , L_11 ,
V_19 , V_267 ) ;
}
break;
case V_269 :
V_26 = F_150 ( V_9 , V_45 ) ;
if ( ! V_26 )
V_26 = F_104 ( V_9 , V_45 ) ;
break;
case V_270 :
V_26 = - V_271 ;
F_6 ( V_9 -> V_18 , L_12 ,
V_19 ) ;
break;
default:
V_26 = - V_122 ;
F_6 ( V_9 -> V_18 , L_13 ,
V_19 , V_267 ) ;
break;
}
return V_26 ;
}
static int F_152 ( struct V_8 * V_9 ,
struct V_44 * V_45 , int V_272 )
{
int V_26 = 0 ;
unsigned long V_273 ;
unsigned long V_89 ;
V_273 = F_113 ( V_9 -> V_147 . V_274 ,
F_11 ( V_272 ) ) ;
F_100 () ;
F_58 ( V_9 -> V_93 -> V_94 , V_89 ) ;
V_9 -> V_147 . V_274 = NULL ;
if ( F_105 ( V_273 ) ) {
V_26 = F_20 ( V_45 ) ;
if ( ! V_26 )
V_26 = F_151 ( V_9 , V_45 ) ;
}
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
if ( ! V_273 ) {
V_26 = - V_29 ;
F_153 ( V_9 -> V_18 , L_14 ,
V_19 , V_45 -> V_135 ) ;
if ( ! F_149 ( V_9 , V_45 -> V_135 ) )
V_26 = - V_106 ;
F_30 ( V_9 , V_45 -> V_135 ) ;
}
return V_26 ;
}
static bool F_154 ( struct V_8 * V_9 , int * V_275 )
{
int V_10 ;
bool V_12 = false ;
unsigned long V_276 ;
if ( ! V_275 )
goto V_53;
do {
V_276 = ~ V_9 -> V_110 ;
V_10 = F_155 ( & V_276 , V_9 -> V_11 ) ;
if ( V_10 >= V_9 -> V_11 )
goto V_53;
} while ( F_25 ( V_10 , & V_9 -> V_110 ) );
* V_275 = V_10 ;
V_12 = true ;
V_53:
return V_12 ;
}
static inline void F_156 ( struct V_8 * V_9 , int V_10 )
{
F_27 ( V_10 , & V_9 -> V_110 ) ;
}
static int F_157 ( struct V_8 * V_9 ,
enum V_264 V_265 , int V_27 )
{
struct V_44 * V_45 ;
int V_26 ;
int V_10 ;
struct V_180 V_277 ;
unsigned long V_89 ;
F_158 ( V_9 -> V_147 . V_278 , F_154 ( V_9 , & V_10 ) ) ;
F_115 ( & V_277 ) ;
V_45 = & V_9 -> V_262 [ V_10 ] ;
F_111 ( V_45 -> V_188 ) ;
V_26 = F_148 ( V_9 , V_45 , V_265 , V_10 ) ;
if ( F_159 ( V_26 ) )
goto V_279;
V_9 -> V_147 . V_274 = & V_277 ;
F_100 () ;
F_58 ( V_9 -> V_93 -> V_94 , V_89 ) ;
F_147 ( V_9 , V_10 , ( V_45 -> V_188 ? true : false ) ) ;
F_98 ( V_9 , V_10 ) ;
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
V_26 = F_152 ( V_9 , V_45 , V_27 ) ;
V_279:
F_156 ( V_9 , V_10 ) ;
F_160 ( & V_9 -> V_147 . V_278 ) ;
return V_26 ;
}
static inline void F_161 ( struct V_8 * V_9 ,
struct V_280 * * V_160 , struct V_145 * * V_149 ,
enum V_281 V_153 , T_2 V_282 , T_2 V_283 , T_2 V_284 )
{
* V_160 = & V_9 -> V_147 . V_148 . V_160 ;
* V_149 = & V_9 -> V_147 . V_148 . V_149 ;
memset ( * V_160 , 0 , sizeof( struct V_280 ) ) ;
memset ( * V_149 , 0 , sizeof( struct V_145 ) ) ;
( * V_160 ) -> V_161 . V_153 = V_153 ;
( * V_160 ) -> V_161 . V_282 = V_282 ;
( * V_160 ) -> V_161 . V_283 = V_283 ;
( * V_160 ) -> V_161 . V_284 = V_284 ;
}
static int F_162 ( struct V_8 * V_9 ,
enum V_281 V_153 , enum V_285 V_282 , bool * V_286 )
{
int V_12 ;
int V_287 ;
for ( V_287 = 0 ; V_287 < V_288 ; V_287 ++ ) {
V_12 = F_163 ( V_9 , V_153 , V_282 , V_286 ) ;
if ( V_12 )
F_153 ( V_9 -> V_18 ,
L_15 ,
V_19 , V_12 , V_287 ) ;
else
break;
}
if ( V_12 )
F_6 ( V_9 -> V_18 ,
L_16 ,
V_19 , V_153 , V_282 , V_12 , V_287 ) ;
return V_12 ;
}
int F_163 ( struct V_8 * V_9 , enum V_281 V_153 ,
enum V_285 V_282 , bool * V_286 )
{
struct V_280 * V_160 = NULL ;
struct V_145 * V_149 = NULL ;
int V_26 , V_283 = 0 , V_284 = 0 ;
int V_27 = V_289 ;
F_164 ( ! V_9 ) ;
F_66 ( V_9 , false ) ;
F_117 ( & V_9 -> V_147 . V_290 ) ;
F_161 ( V_9 , & V_160 , & V_149 , V_153 , V_282 , V_283 ,
V_284 ) ;
switch ( V_153 ) {
case V_291 :
case V_292 :
case V_293 :
V_160 -> V_238 = V_294 ;
break;
case V_295 :
V_160 -> V_238 = V_296 ;
if ( ! V_286 ) {
F_6 ( V_9 -> V_18 , L_17 ,
V_19 ) ;
V_26 = - V_122 ;
goto V_257;
}
break;
default:
F_6 ( V_9 -> V_18 ,
L_18 ,
V_19 , V_153 ) ;
V_26 = - V_122 ;
goto V_257;
}
V_26 = F_157 ( V_9 , V_244 , V_27 ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 ,
L_19 ,
V_19 , V_282 , V_26 ) ;
goto V_257;
}
if ( V_286 )
* V_286 = ( F_36 ( V_149 -> V_150 . V_121 ) &
V_297 ) & 0x1 ;
V_257:
F_119 ( & V_9 -> V_147 . V_290 ) ;
F_80 ( V_9 ) ;
return V_26 ;
}
static int F_165 ( struct V_8 * V_9 , enum V_281 V_153 ,
enum V_298 V_282 , T_2 V_283 , T_2 V_284 , T_1 * V_299 )
{
struct V_280 * V_160 = NULL ;
struct V_145 * V_149 = NULL ;
int V_26 ;
F_164 ( ! V_9 ) ;
F_66 ( V_9 , false ) ;
if ( ! V_299 ) {
F_6 ( V_9 -> V_18 , L_20 ,
V_19 , V_153 ) ;
V_26 = - V_122 ;
goto V_53;
}
F_117 ( & V_9 -> V_147 . V_290 ) ;
F_161 ( V_9 , & V_160 , & V_149 , V_153 , V_282 , V_283 ,
V_284 ) ;
switch ( V_153 ) {
case V_300 :
V_160 -> V_238 = V_294 ;
V_160 -> V_161 . V_121 = F_133 ( * V_299 ) ;
break;
case V_301 :
V_160 -> V_238 = V_296 ;
break;
default:
F_6 ( V_9 -> V_18 , L_21 ,
V_19 , V_153 ) ;
V_26 = - V_122 ;
goto V_257;
}
V_26 = F_157 ( V_9 , V_244 , V_289 ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_22 ,
V_19 , V_153 , V_282 , V_283 , V_26 ) ;
goto V_257;
}
* V_299 = F_36 ( V_149 -> V_150 . V_121 ) ;
V_257:
F_119 ( & V_9 -> V_147 . V_290 ) ;
V_53:
F_80 ( V_9 ) ;
return V_26 ;
}
static int F_166 ( struct V_8 * V_9 ,
enum V_281 V_153 , enum V_298 V_282 , T_2 V_283 , T_2 V_284 ,
T_1 * V_299 )
{
int V_12 = 0 ;
T_1 V_287 ;
for ( V_287 = V_288 ; V_287 > 0 ; V_287 -- ) {
V_12 = F_165 ( V_9 , V_153 , V_282 , V_283 ,
V_284 , V_299 ) ;
if ( V_12 )
F_153 ( V_9 -> V_18 , L_15 ,
V_19 , V_12 , V_287 ) ;
else
break;
}
if ( V_12 )
F_6 ( V_9 -> V_18 ,
L_23 ,
V_19 , V_282 , V_12 , V_288 ) ;
return V_12 ;
}
static int F_167 ( struct V_8 * V_9 ,
enum V_281 V_153 , enum V_302 V_282 , T_2 V_283 ,
T_2 V_284 , T_2 * V_303 , int * V_158 )
{
struct V_280 * V_160 = NULL ;
struct V_145 * V_149 = NULL ;
int V_26 ;
F_164 ( ! V_9 ) ;
F_66 ( V_9 , false ) ;
if ( ! V_303 ) {
F_6 ( V_9 -> V_18 , L_24 ,
V_19 , V_153 ) ;
V_26 = - V_122 ;
goto V_53;
}
if ( * V_158 <= V_304 || * V_158 > V_305 ) {
F_6 ( V_9 -> V_18 , L_25 ,
V_19 , * V_158 ) ;
V_26 = - V_122 ;
goto V_53;
}
F_117 ( & V_9 -> V_147 . V_290 ) ;
F_161 ( V_9 , & V_160 , & V_149 , V_153 , V_282 , V_283 ,
V_284 ) ;
V_9 -> V_147 . V_148 . V_163 = V_303 ;
V_160 -> V_161 . V_162 = F_168 ( * V_158 ) ;
switch ( V_153 ) {
case V_239 :
V_160 -> V_238 = V_294 ;
break;
case V_154 :
V_160 -> V_238 = V_296 ;
break;
default:
F_6 ( V_9 -> V_18 ,
L_26 ,
V_19 , V_153 ) ;
V_26 = - V_122 ;
goto V_257;
}
V_26 = F_157 ( V_9 , V_244 , V_289 ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_22 ,
V_19 , V_153 , V_282 , V_283 , V_26 ) ;
goto V_257;
}
V_9 -> V_147 . V_148 . V_163 = NULL ;
* V_158 = F_102 ( V_149 -> V_150 . V_162 ) ;
V_257:
F_119 ( & V_9 -> V_147 . V_290 ) ;
V_53:
F_80 ( V_9 ) ;
return V_26 ;
}
int F_169 ( struct V_8 * V_9 ,
enum V_281 V_153 , enum V_302 V_282 , T_2 V_283 ,
T_2 V_284 , T_2 * V_303 , int * V_158 )
{
int V_26 ;
int V_287 ;
for ( V_287 = V_288 ; V_287 > 0 ; V_287 -- ) {
V_26 = F_167 ( V_9 , V_153 , V_282 , V_283 ,
V_284 , V_303 , V_158 ) ;
if ( ! V_26 || V_26 == - V_122 )
break;
}
return V_26 ;
}
static int F_170 ( struct V_8 * V_9 ,
enum V_302 V_306 ,
int V_307 ,
T_1 V_308 ,
T_2 * V_309 ,
T_1 V_310 )
{
int V_12 ;
T_2 * V_303 ;
T_1 V_311 ;
bool V_312 = true ;
if ( V_306 >= V_313 )
return - V_122 ;
V_311 = V_314 [ V_306 ] ;
if ( ( V_308 + V_310 ) > V_311 )
return - V_122 ;
if ( ! V_308 && ( V_310 == V_311 ) ) {
V_303 = V_309 ;
V_312 = false ;
} else {
V_303 = F_171 ( V_311 , V_315 ) ;
if ( ! V_303 )
return - V_316 ;
}
V_12 = F_169 ( V_9 , V_154 ,
V_306 , V_307 , 0 , V_303 ,
& V_311 ) ;
if ( V_12 ) {
F_6 ( V_9 -> V_18 , L_27 ,
V_19 , V_306 , V_307 , V_308 , V_12 ) ;
goto V_53;
}
if ( V_303 [ V_317 ] != V_306 ) {
F_6 ( V_9 -> V_18 , L_28 ,
V_19 , V_303 [ V_317 ] ) ;
V_12 = - V_122 ;
goto V_53;
}
if ( ( V_306 != V_318 ) &&
( V_311 != V_303 [ V_319 ] ) ) {
F_6 ( V_9 -> V_18 , L_29 ,
V_19 , V_311 , V_303 [ V_319 ] ) ;
V_12 = - V_122 ;
goto V_53;
}
if ( V_312 )
memcpy ( V_309 , & V_303 [ V_308 ] , V_310 ) ;
V_53:
if ( V_312 )
F_172 ( V_303 ) ;
return V_12 ;
}
static inline int F_173 ( struct V_8 * V_9 ,
enum V_302 V_306 ,
int V_307 ,
T_2 * V_118 ,
T_1 V_194 )
{
return F_170 ( V_9 , V_306 , V_307 , 0 , V_118 , V_194 ) ;
}
static inline int F_174 ( struct V_8 * V_9 ,
T_2 * V_118 ,
T_1 V_194 )
{
int V_26 = 0 ;
int V_287 ;
for ( V_287 = V_288 ; V_287 > 0 ; V_287 -- ) {
V_26 = F_173 ( V_9 , V_320 , 0 , V_118 , V_194 ) ;
if ( ! V_26 )
break;
F_153 ( V_9 -> V_18 , L_30 , V_19 , V_26 ) ;
}
return V_26 ;
}
int F_175 ( struct V_8 * V_9 , T_2 * V_118 , T_1 V_194 )
{
return F_173 ( V_9 , V_321 , 0 , V_118 , V_194 ) ;
}
int F_176 ( struct V_8 * V_9 , int V_307 , T_2 * V_118 ,
T_1 V_194 , bool V_322 )
{
int V_26 = 0 ;
V_26 = F_173 ( V_9 ,
V_318 , V_307 , V_118 , V_194 ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_31 ,
V_19 , V_288 , V_26 ) ;
goto V_53;
}
if ( V_322 ) {
int V_323 ;
int V_324 ;
int V_190 ;
char * V_325 ;
V_323 = V_118 [ 0 ] ;
V_324 = ( V_323 - V_326 ) / 2 + 1 ;
if ( V_194 < V_324 + V_326 ) {
F_6 ( V_9 -> V_18 , L_32 ,
V_19 ) ;
V_26 = - V_316 ;
goto V_53;
}
V_325 = F_171 ( V_324 , V_315 ) ;
if ( ! V_325 ) {
V_26 = - V_316 ;
goto V_53;
}
F_177 ( ( V_327 * ) & V_118 [ V_326 ] ,
V_323 - V_326 ,
V_328 , V_325 , V_324 ) ;
for ( V_190 = 0 ; V_190 < V_324 ; V_190 ++ )
F_9 ( & V_325 [ V_190 ] ) ;
memset ( V_118 + V_326 , 0 ,
V_194 - V_326 ) ;
memcpy ( V_118 + V_326 , V_325 , V_324 ) ;
V_118 [ V_319 ] = V_324 + V_326 ;
F_172 ( V_325 ) ;
}
V_53:
return V_26 ;
}
static inline int F_178 ( struct V_8 * V_9 ,
int V_228 ,
enum V_329 V_308 ,
T_2 * V_309 ,
T_1 V_310 )
{
if ( V_228 != V_330 && ( V_228 >= V_331 ) )
return - V_332 ;
return F_170 ( V_9 , V_333 , V_228 ,
V_308 , V_309 , V_310 ) ;
}
static int F_179 ( struct V_8 * V_9 )
{
T_4 V_334 , V_335 , V_336 ;
V_336 = ( sizeof( struct V_337 ) * V_9 -> V_11 ) ;
V_9 -> V_338 = F_180 ( V_9 -> V_18 ,
V_336 ,
& V_9 -> V_339 ,
V_315 ) ;
if ( ! V_9 -> V_338 ||
F_111 ( V_9 -> V_339 & ( V_119 - 1 ) ) ) {
F_6 ( V_9 -> V_18 ,
L_33 ) ;
goto V_53;
}
V_335 = ( sizeof( struct V_207 ) * V_9 -> V_11 ) ;
V_9 -> V_340 = F_180 ( V_9 -> V_18 ,
V_335 ,
& V_9 -> V_341 ,
V_315 ) ;
if ( ! V_9 -> V_340 ||
F_111 ( V_9 -> V_341 & ( V_119 - 1 ) ) ) {
F_6 ( V_9 -> V_18 ,
L_34 ) ;
goto V_53;
}
V_334 = sizeof( struct V_50 ) * V_9 -> V_55 ;
V_9 -> V_342 = F_180 ( V_9 -> V_18 ,
V_334 ,
& V_9 -> V_343 ,
V_315 ) ;
if ( ! V_9 -> V_342 ||
F_111 ( V_9 -> V_343 & ( V_119 - 1 ) ) ) {
F_6 ( V_9 -> V_18 ,
L_35 ) ;
goto V_53;
}
V_9 -> V_262 = F_181 ( V_9 -> V_18 ,
V_9 -> V_11 * sizeof( struct V_44 ) ,
V_315 ) ;
if ( ! V_9 -> V_262 ) {
F_6 ( V_9 -> V_18 , L_36 ) ;
goto V_53;
}
return 0 ;
V_53:
return - V_316 ;
}
static void F_182 ( struct V_8 * V_9 )
{
struct V_337 * V_344 ;
struct V_207 * V_345 ;
T_6 V_346 ;
T_6 V_347 ;
T_5 V_348 ;
T_5 V_349 ;
int V_350 ;
int V_190 ;
V_345 = V_9 -> V_340 ;
V_344 = V_9 -> V_338 ;
V_348 =
F_183 ( struct V_337 , V_351 ) ;
V_349 =
F_183 ( struct V_337 , V_184 ) ;
V_350 = sizeof( struct V_337 ) ;
V_346 = V_9 -> V_339 ;
for ( V_190 = 0 ; V_190 < V_9 -> V_11 ; V_190 ++ ) {
V_347 =
( V_346 + ( V_350 * V_190 ) ) ;
V_345 [ V_190 ] . V_352 =
F_124 ( F_126 ( V_347 ) ) ;
V_345 [ V_190 ] . V_353 =
F_124 ( F_127 ( V_347 ) ) ;
if ( V_9 -> V_39 & V_191 ) {
V_345 [ V_190 ] . V_354 =
F_122 ( V_348 ) ;
V_345 [ V_190 ] . V_355 =
F_122 ( V_349 ) ;
V_345 [ V_190 ] . V_356 =
F_122 ( V_357 ) ;
} else {
V_345 [ V_190 ] . V_354 =
F_122 ( ( V_348 >> 2 ) ) ;
V_345 [ V_190 ] . V_355 =
F_122 ( ( V_349 >> 2 ) ) ;
V_345 [ V_190 ] . V_356 =
F_122 ( V_357 >> 2 ) ;
}
V_9 -> V_262 [ V_190 ] . V_46 = ( V_345 + V_190 ) ;
V_9 -> V_262 [ V_190 ] . V_225 =
(struct V_224 * ) ( V_344 + V_190 ) ;
V_9 -> V_262 [ V_190 ] . V_64 =
(struct V_63 * ) V_344 [ V_190 ] . V_351 ;
V_9 -> V_262 [ V_190 ] . V_193 =
(struct V_183 * ) V_344 [ V_190 ] . V_184 ;
}
}
static int F_184 ( struct V_8 * V_9 )
{
struct V_169 V_170 = { 0 } ;
int V_12 ;
V_170 . V_175 = V_358 ;
V_12 = F_116 ( V_9 , & V_170 ) ;
if ( V_12 )
F_6 ( V_9 -> V_18 ,
L_37 , V_12 ) ;
return V_12 ;
}
static inline void F_118 ( struct V_8 * V_9 )
{
#define F_185 1000
unsigned long V_359 ;
if ( ! ( V_9 -> V_39 & V_360 ) )
return;
if ( F_159 ( ! F_96 ( V_9 -> V_361 ) ) ) {
V_359 = F_185 ;
} else {
unsigned long V_362 =
( unsigned long ) F_96 (
F_97 ( F_94 () ,
V_9 -> V_361 ) ) ;
if ( V_362 < F_185 )
V_359 =
F_185 - V_362 ;
else
return;
}
F_13 ( V_359 , V_359 + 50 ) ;
}
int F_186 ( struct V_8 * V_9 , T_1 V_363 ,
T_2 V_364 , T_1 V_365 , T_2 V_366 )
{
struct V_169 V_170 = { 0 } ;
static const char * const V_367 [] = {
L_38 ,
L_39
} ;
const char * V_200 = V_367 [ ! ! V_366 ] ;
int V_12 ;
int V_287 = V_368 ;
V_170 . V_175 = V_366 ?
V_369 : V_370 ;
V_170 . V_171 = V_363 ;
V_170 . V_173 = F_187 ( V_364 ) ;
V_170 . V_174 = V_365 ;
do {
V_12 = F_116 ( V_9 , & V_170 ) ;
if ( V_12 )
F_153 ( V_9 -> V_18 , L_40 ,
V_200 , F_188 ( V_363 ) , V_365 , V_12 ) ;
} while ( V_12 && V_366 && -- V_287 );
if ( V_12 )
F_6 ( V_9 -> V_18 , L_41 ,
V_200 , F_188 ( V_363 ) , V_365 ,
V_368 - V_287 ) ;
return V_12 ;
}
int F_189 ( struct V_8 * V_9 , T_1 V_363 ,
T_1 * V_365 , T_2 V_366 )
{
struct V_169 V_170 = { 0 } ;
static const char * const V_367 [] = {
L_42 ,
L_43
} ;
const char * V_371 = V_367 [ ! ! V_366 ] ;
int V_12 ;
int V_287 = V_368 ;
struct V_372 V_373 ;
struct V_372 V_374 ;
bool V_375 = false ;
if ( V_366 && ( V_9 -> V_39 & V_376 ) ) {
V_373 = V_9 -> V_377 ;
V_374 = V_373 ;
if ( V_373 . V_378 == V_379 ||
V_373 . V_380 == V_379 ) {
V_374 . V_378 = V_381 ;
V_374 . V_380 = V_381 ;
V_375 = true ;
} else if ( V_373 . V_378 == V_382 ||
V_373 . V_380 == V_382 ) {
V_374 . V_378 = V_383 ;
V_374 . V_380 = V_383 ;
V_375 = true ;
}
if ( V_375 ) {
V_12 = F_190 ( V_9 , & V_374 ) ;
if ( V_12 )
goto V_53;
}
}
V_170 . V_175 = V_366 ?
V_384 : V_385 ;
V_170 . V_171 = V_363 ;
do {
V_12 = F_116 ( V_9 , & V_170 ) ;
if ( V_12 )
F_153 ( V_9 -> V_18 , L_44 ,
V_371 , F_188 ( V_363 ) , V_12 ) ;
} while ( V_12 && V_366 && -- V_287 );
if ( V_12 )
F_6 ( V_9 -> V_18 , L_45 ,
V_371 , F_188 ( V_363 ) ,
V_368 - V_287 ) ;
if ( V_365 && ! V_12 )
* V_365 = V_170 . V_174 ;
if ( V_366 && ( V_9 -> V_39 & V_376 )
&& V_375 )
F_190 ( V_9 , & V_373 ) ;
V_53:
return V_12 ;
}
static int F_191 ( struct V_8 * V_9 , struct V_169 * V_188 )
{
struct V_180 V_113 ;
unsigned long V_89 ;
T_2 V_386 ;
int V_12 ;
bool V_387 = false ;
F_117 ( & V_9 -> V_182 ) ;
F_115 ( & V_113 ) ;
F_118 ( V_9 ) ;
F_58 ( V_9 -> V_93 -> V_94 , V_89 ) ;
V_9 -> V_113 = & V_113 ;
if ( F_12 ( V_9 , V_201 ) & V_388 ) {
F_129 ( V_9 , V_388 ) ;
F_100 () ;
V_387 = true ;
}
V_12 = F_114 ( V_9 , V_188 , false ) ;
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
if ( V_12 ) {
F_6 ( V_9 -> V_18 ,
L_46 ,
V_188 -> V_175 , V_188 -> V_174 , V_12 ) ;
goto V_53;
}
if ( ! F_113 ( V_9 -> V_113 ,
F_11 ( V_179 ) ) ) {
F_6 ( V_9 -> V_18 ,
L_47 ,
V_188 -> V_175 , V_188 -> V_174 ) ;
V_12 = - V_29 ;
goto V_53;
}
V_386 = F_109 ( V_9 ) ;
if ( V_386 != V_389 ) {
F_6 ( V_9 -> V_18 ,
L_48 ,
V_188 -> V_175 , V_386 ) ;
V_12 = ( V_386 != V_390 ) ? V_386 : - 1 ;
}
V_53:
F_58 ( V_9 -> V_93 -> V_94 , V_89 ) ;
V_9 -> V_112 = NULL ;
V_9 -> V_113 = NULL ;
if ( V_387 )
F_128 ( V_9 , V_388 ) ;
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
F_119 ( & V_9 -> V_182 ) ;
return V_12 ;
}
static int F_192 ( struct V_8 * V_9 , T_2 V_127 )
{
struct V_169 V_170 = { 0 } ;
int V_12 ;
if ( V_9 -> V_39 & V_391 ) {
V_12 = F_193 ( V_9 ,
F_194 ( V_392 , 0 ) , 1 ) ;
if ( V_12 ) {
F_6 ( V_9 -> V_18 , L_49 ,
V_19 , V_12 ) ;
goto V_53;
}
}
V_170 . V_175 = V_370 ;
V_170 . V_171 = F_195 ( V_393 ) ;
V_170 . V_174 = V_127 ;
F_66 ( V_9 , false ) ;
V_12 = F_191 ( V_9 , & V_170 ) ;
F_80 ( V_9 ) ;
V_53:
return V_12 ;
}
static int F_196 ( struct V_8 * V_9 )
{
int V_12 ;
unsigned long V_89 ;
F_58 ( V_9 -> V_93 -> V_94 , V_89 ) ;
V_9 -> V_108 = V_255 ;
F_197 ( V_9 ) ;
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
V_12 = F_198 ( V_9 ) ;
F_58 ( V_9 -> V_93 -> V_94 , V_89 ) ;
if ( V_12 )
V_9 -> V_108 = V_258 ;
F_199 ( V_9 ) ;
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
if ( V_12 )
F_6 ( V_9 -> V_18 , L_50 ,
V_19 , V_12 ) ;
return V_12 ;
}
static int F_200 ( struct V_8 * V_9 )
{
int V_12 ;
struct V_169 V_170 = { 0 } ;
F_201 ( V_9 , V_394 , V_395 ) ;
V_170 . V_175 = V_394 ;
V_12 = F_191 ( V_9 , & V_170 ) ;
if ( V_12 ) {
F_6 ( V_9 -> V_18 , L_51 ,
V_19 , V_12 ) ;
if ( F_196 ( V_9 ) )
V_12 = - V_396 ;
} else
F_201 ( V_9 , V_394 ,
V_397 ) ;
return V_12 ;
}
static int F_74 ( struct V_8 * V_9 )
{
int V_12 = 0 , V_287 ;
for ( V_287 = V_398 ; V_287 > 0 ; V_287 -- ) {
V_12 = F_200 ( V_9 ) ;
if ( ! V_12 || V_12 == - V_396 )
goto V_53;
}
V_53:
return V_12 ;
}
static int F_63 ( struct V_8 * V_9 )
{
struct V_169 V_170 = { 0 } ;
int V_12 ;
F_201 ( V_9 , V_399 , V_395 ) ;
V_170 . V_175 = V_399 ;
V_12 = F_191 ( V_9 , & V_170 ) ;
if ( V_12 ) {
F_6 ( V_9 -> V_18 , L_52 ,
V_19 , V_12 ) ;
V_12 = F_196 ( V_9 ) ;
} else
F_201 ( V_9 , V_399 ,
V_397 ) ;
return V_12 ;
}
static void F_202 ( struct V_8 * V_9 )
{
V_9 -> V_377 . V_400 = V_401 ;
V_9 -> V_377 . V_402 = V_401 ;
V_9 -> V_377 . V_403 = 1 ;
V_9 -> V_377 . V_404 = 1 ;
V_9 -> V_377 . V_380 = V_383 ;
V_9 -> V_377 . V_378 = V_383 ;
V_9 -> V_377 . V_405 = 0 ;
}
static int F_203 ( struct V_8 * V_9 )
{
struct V_372 * V_377 = & V_9 -> V_406 . V_407 ;
if ( V_9 -> V_406 . V_408 )
return 0 ;
V_377 -> V_378 = V_379 ;
V_377 -> V_380 = V_379 ;
V_377 -> V_405 = V_409 ;
F_204 ( V_9 , F_195 ( V_410 ) ,
& V_377 -> V_403 ) ;
F_204 ( V_9 , F_195 ( V_411 ) ,
& V_377 -> V_404 ) ;
if ( ! V_377 -> V_403 || ! V_377 -> V_404 ) {
F_6 ( V_9 -> V_18 , L_53 ,
V_19 ,
V_377 -> V_403 ,
V_377 -> V_404 ) ;
return - V_122 ;
}
F_204 ( V_9 , F_195 ( V_412 ) , & V_377 -> V_400 ) ;
if ( ! V_377 -> V_400 ) {
F_204 ( V_9 , F_195 ( V_413 ) ,
& V_377 -> V_400 ) ;
if ( ! V_377 -> V_400 ) {
F_6 ( V_9 -> V_18 , L_54 ,
V_19 , V_377 -> V_400 ) ;
return - V_122 ;
}
V_377 -> V_380 = V_382 ;
}
F_205 ( V_9 , F_195 ( V_412 ) ,
& V_377 -> V_402 ) ;
if ( ! V_377 -> V_402 ) {
F_205 ( V_9 , F_195 ( V_413 ) ,
& V_377 -> V_402 ) ;
if ( ! V_377 -> V_402 ) {
F_6 ( V_9 -> V_18 , L_55 ,
V_19 , V_377 -> V_402 ) ;
return - V_122 ;
}
V_377 -> V_378 = V_382 ;
}
V_9 -> V_406 . V_408 = true ;
return 0 ;
}
static int F_190 ( struct V_8 * V_9 ,
struct V_372 * V_414 )
{
int V_12 ;
if ( V_414 -> V_400 == V_9 -> V_377 . V_400 &&
V_414 -> V_402 == V_9 -> V_377 . V_402 &&
V_414 -> V_403 == V_9 -> V_377 . V_403 &&
V_414 -> V_404 == V_9 -> V_377 . V_404 &&
V_414 -> V_380 == V_9 -> V_377 . V_380 &&
V_414 -> V_378 == V_9 -> V_377 . V_378 &&
V_414 -> V_405 == V_9 -> V_377 . V_405 ) {
F_153 ( V_9 -> V_18 , L_56 , V_19 ) ;
return 0 ;
}
F_193 ( V_9 , F_195 ( V_415 ) , V_414 -> V_400 ) ;
F_193 ( V_9 , F_195 ( V_416 ) ,
V_414 -> V_403 ) ;
if ( V_414 -> V_380 == V_381 ||
V_414 -> V_380 == V_379 )
F_193 ( V_9 , F_195 ( V_417 ) , TRUE ) ;
else
F_193 ( V_9 , F_195 ( V_417 ) , FALSE ) ;
F_193 ( V_9 , F_195 ( V_418 ) , V_414 -> V_402 ) ;
F_193 ( V_9 , F_195 ( V_419 ) ,
V_414 -> V_404 ) ;
if ( V_414 -> V_378 == V_381 ||
V_414 -> V_378 == V_379 )
F_193 ( V_9 , F_195 ( V_420 ) , TRUE ) ;
else
F_193 ( V_9 , F_195 ( V_420 ) , FALSE ) ;
if ( V_414 -> V_380 == V_381 ||
V_414 -> V_378 == V_381 ||
V_414 -> V_380 == V_379 ||
V_414 -> V_378 == V_379 )
F_193 ( V_9 , F_195 ( V_421 ) ,
V_414 -> V_405 ) ;
V_12 = F_192 ( V_9 , V_414 -> V_380 << 4
| V_414 -> V_378 ) ;
if ( V_12 ) {
F_6 ( V_9 -> V_18 ,
L_57 , V_19 , V_12 ) ;
} else {
F_206 ( V_9 , V_397 , NULL ,
V_414 ) ;
memcpy ( & V_9 -> V_377 , V_414 ,
sizeof( struct V_372 ) ) ;
}
return V_12 ;
}
static int F_207 ( struct V_8 * V_9 ,
struct V_372 * V_422 )
{
struct V_372 V_423 = { 0 } ;
int V_12 ;
V_12 = F_206 ( V_9 , V_395 ,
V_422 , & V_423 ) ;
if ( V_12 )
memcpy ( & V_423 , V_422 , sizeof( V_423 ) ) ;
V_12 = F_190 ( V_9 , & V_423 ) ;
return V_12 ;
}
static int F_208 ( struct V_8 * V_9 )
{
int V_190 ;
int V_26 ;
bool V_286 = 1 ;
V_26 = F_162 ( V_9 , V_291 ,
V_424 , NULL ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 ,
L_58 ,
V_19 , V_26 ) ;
goto V_53;
}
for ( V_190 = 0 ; V_190 < 1000 && ! V_26 && V_286 ; V_190 ++ )
V_26 = F_162 ( V_9 , V_295 ,
V_424 , & V_286 ) ;
if ( V_26 )
F_6 ( V_9 -> V_18 ,
L_59 ,
V_19 , V_26 ) ;
else if ( V_286 )
F_6 ( V_9 -> V_18 ,
L_60 ,
V_19 ) ;
V_53:
return V_26 ;
}
static int F_209 ( struct V_8 * V_9 )
{
int V_26 = 0 ;
T_1 V_21 ;
F_128 ( V_9 , V_425 ) ;
if ( F_146 ( V_9 ) )
F_41 ( V_9 , V_9 -> V_11 - 1 , V_426 ) ;
else
F_44 ( V_9 ) ;
F_29 ( V_9 , F_126 ( V_9 -> V_341 ) ,
V_427 ) ;
F_29 ( V_9 , F_127 ( V_9 -> V_341 ) ,
V_428 ) ;
F_29 ( V_9 , F_126 ( V_9 -> V_343 ) ,
V_429 ) ;
F_29 ( V_9 , F_127 ( V_9 -> V_343 ) ,
V_430 ) ;
F_100 () ;
V_21 = F_12 ( V_9 , V_42 ) ;
if ( ! ( F_32 ( V_21 ) ) ) {
F_45 ( V_9 ) ;
} else {
F_6 ( V_9 -> V_18 ,
L_61 ) ;
V_26 = - V_181 ;
goto V_53;
}
V_53:
return V_26 ;
}
static inline void F_210 ( struct V_8 * V_9 , bool V_25 )
{
int V_26 ;
F_29 ( V_9 , V_431 , V_81 ) ;
V_26 = F_10 ( V_9 , V_81 ,
V_80 , V_431 ,
10 , 1 , V_25 ) ;
if ( V_26 )
F_6 ( V_9 -> V_18 , L_62 , V_19 ) ;
}
static int F_211 ( struct V_8 * V_9 )
{
int V_432 ;
if ( ! F_47 ( V_9 ) )
F_210 ( V_9 , true ) ;
F_212 ( V_9 ) ;
F_213 ( V_9 , V_395 ) ;
F_46 ( V_9 ) ;
F_214 ( 1 ) ;
V_432 = 10 ;
while ( F_47 ( V_9 ) ) {
if ( V_432 ) {
V_432 -- ;
} else {
F_6 ( V_9 -> V_18 ,
L_63 ) ;
return - V_181 ;
}
F_214 ( 5 ) ;
}
F_128 ( V_9 , V_433 ) ;
F_213 ( V_9 , V_397 ) ;
return 0 ;
}
static int F_215 ( struct V_8 * V_9 , bool V_366 )
{
int V_434 , V_190 , V_26 = 0 ;
if ( ! V_366 )
F_204 ( V_9 , F_195 ( V_411 ) ,
& V_434 ) ;
else
F_205 ( V_9 , F_195 ( V_411 ) ,
& V_434 ) ;
for ( V_190 = 0 ; V_190 < V_434 ; V_190 ++ ) {
if ( ! V_366 )
V_26 = F_193 ( V_9 ,
F_194 ( V_435 ,
F_216 ( V_190 ) ) ,
0 ) ;
else
V_26 = F_217 ( V_9 ,
F_194 ( V_435 ,
F_216 ( V_190 ) ) ,
0 ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_64 ,
V_19 , V_366 , V_190 , V_26 ) ;
break;
}
}
return V_26 ;
}
static inline int F_218 ( struct V_8 * V_9 )
{
return F_215 ( V_9 , true ) ;
}
static int F_219 ( struct V_8 * V_9 )
{
int V_12 ;
int V_287 = V_436 ;
bool V_437 = false ;
if ( ! F_220 ( V_9 ) )
V_437 = true ;
V_438:
do {
F_221 ( V_9 , V_395 ) ;
V_12 = F_184 ( V_9 ) ;
if ( ! V_12 && ! F_19 ( V_9 ) ) {
F_6 ( V_9 -> V_18 , L_65 , V_19 ) ;
V_12 = - V_439 ;
goto V_53;
}
if ( V_12 && F_211 ( V_9 ) )
goto V_53;
} while ( V_12 && V_287 -- );
if ( V_12 )
goto V_53;
if ( V_437 ) {
V_437 = false ;
V_287 = V_436 ;
goto V_438;
}
if ( V_9 -> V_39 & V_440 ) {
V_12 = F_218 ( V_9 ) ;
if ( V_12 )
goto V_53;
}
V_12 = F_221 ( V_9 , V_397 ) ;
if ( V_12 )
goto V_53;
V_12 = F_209 ( V_9 ) ;
V_53:
if ( V_12 )
F_6 ( V_9 -> V_18 , L_66 , V_12 ) ;
return V_12 ;
}
static int F_222 ( struct V_8 * V_9 )
{
int V_26 = 0 ;
int V_287 ;
F_66 ( V_9 , false ) ;
F_117 ( & V_9 -> V_147 . V_290 ) ;
for ( V_287 = V_441 ; V_287 > 0 ; V_287 -- ) {
V_26 = F_157 ( V_9 , V_245 ,
V_442 ) ;
if ( ! V_26 || V_26 == - V_29 )
break;
F_153 ( V_9 -> V_18 , L_30 , V_19 , V_26 ) ;
}
F_119 ( & V_9 -> V_147 . V_290 ) ;
F_80 ( V_9 ) ;
if ( V_26 )
F_6 ( V_9 -> V_18 , L_67 , V_19 , V_26 ) ;
return V_26 ;
}
static void F_223 ( struct V_443 * V_444 )
{
int V_12 = 0 ;
T_2 V_445 ;
int V_287 ;
struct V_8 * V_9 ;
V_9 = F_142 ( V_444 -> V_93 ) ;
V_445 = V_9 -> V_11 ;
for ( V_287 = V_288 ; V_287 > 0 ; V_287 -- ) {
V_12 = F_178 ( V_9 ,
F_138 ( V_444 -> V_228 ) ,
V_446 ,
& V_445 ,
sizeof( V_445 ) ) ;
if ( ! V_12 || V_12 == - V_447 )
break;
F_153 ( V_9 -> V_18 , L_30 , V_19 , V_12 ) ;
}
if ( V_12 == - V_332 )
V_445 = 1 ;
else if ( ! V_445 )
V_445 = V_9 -> V_11 ;
else
V_445 = F_103 ( int , V_445 , V_9 -> V_11 ) ;
F_153 ( V_9 -> V_18 , L_68 ,
V_19 , V_445 ) ;
F_224 ( V_444 , V_445 ) ;
}
static int F_225 ( struct V_8 * V_9 ,
T_2 V_228 ,
T_2 * V_448 )
{
int V_12 ;
if ( ! V_448 )
V_12 = - V_122 ;
else if ( V_228 >= V_331 )
V_12 = - V_447 ;
else
V_12 = F_178 ( V_9 ,
V_228 ,
V_449 ,
V_448 ,
sizeof( * V_448 ) ) ;
return V_12 ;
}
static inline void F_226 ( struct V_8 * V_9 ,
struct V_443 * V_444 )
{
if ( V_9 -> V_450 . V_451 &&
! V_9 -> V_450 . V_452 ) {
T_2 V_448 ;
if ( ! F_225 ( V_9 , F_138 ( V_444 -> V_228 ) ,
& V_448 ) &&
( V_448 == V_453 ) )
V_9 -> V_450 . V_452 = true ;
}
}
static int F_227 ( struct V_443 * V_444 )
{
struct V_8 * V_9 ;
V_9 = F_142 ( V_444 -> V_93 ) ;
V_444 -> V_454 = 1 ;
V_444 -> V_455 = 1 ;
V_444 -> V_456 = 1 ;
F_223 ( V_444 ) ;
F_226 ( V_9 , V_444 ) ;
return 0 ;
}
static int F_228 ( struct V_443 * V_444 , int V_457 )
{
struct V_8 * V_9 = F_142 ( V_444 -> V_93 ) ;
if ( V_457 > V_9 -> V_11 )
V_457 = V_9 -> V_11 ;
return F_224 ( V_444 , V_457 ) ;
}
static int F_229 ( struct V_443 * V_444 )
{
struct V_458 * V_459 = V_444 -> V_458 ;
F_230 ( V_459 , V_460 - 1 ) ;
F_231 ( V_459 , V_461 ) ;
return 0 ;
}
static void F_232 ( struct V_443 * V_444 )
{
struct V_8 * V_9 ;
V_9 = F_142 ( V_444 -> V_93 ) ;
if ( F_138 ( V_444 -> V_228 ) == V_462 ) {
unsigned long V_89 ;
F_58 ( V_9 -> V_93 -> V_94 , V_89 ) ;
V_9 -> V_463 = NULL ;
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
}
}
static int F_233 ( struct V_8 * V_9 , T_1 V_283 , T_2 * V_267 )
{
struct V_50 * V_51 ;
struct V_464 * V_465 ;
unsigned long V_89 ;
int V_466 ;
int V_467 ;
F_58 ( V_9 -> V_93 -> V_94 , V_89 ) ;
F_31 ( V_283 , & V_9 -> V_111 ) ;
V_51 = V_9 -> V_342 ;
V_466 = F_22 ( & V_51 [ V_283 ] ) ;
if ( V_466 == V_468 ) {
V_465 = (struct V_464 * )
V_51 [ V_283 ] . V_469 ;
V_467 = F_36 ( V_465 -> V_470 ) ;
V_467 = V_467 & V_471 ;
if ( V_267 )
* V_267 = ( T_2 ) V_467 ;
} else {
F_6 ( V_9 -> V_18 , L_69 ,
V_19 , V_466 ) ;
}
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
return V_466 ;
}
static inline int
F_234 ( struct V_44 * V_45 , int V_472 )
{
int V_473 = 0 ;
switch ( V_472 ) {
case V_474 :
F_101 ( V_45 ) ;
case V_475 :
V_473 |= V_476 << 16 |
V_477 << 8 |
V_472 ;
break;
case V_478 :
case V_479 :
case V_480 :
F_101 ( V_45 ) ;
V_473 |= V_472 ;
break;
default:
V_473 |= V_259 << 16 ;
break;
}
return V_473 ;
}
static inline int
F_235 ( struct V_8 * V_9 , struct V_44 * V_45 )
{
int V_473 = 0 ;
int V_472 ;
int V_481 ;
V_481 = F_20 ( V_45 ) ;
switch ( V_481 ) {
case V_468 :
V_473 = F_35 ( V_45 -> V_64 ) ;
switch ( V_473 ) {
case V_482 :
V_473 = F_37 ( V_45 -> V_64 ) ;
V_472 = V_473 & V_483 ;
V_473 = F_234 ( V_45 , V_472 ) ;
if ( ! V_9 -> V_484 &&
F_39 ( V_45 -> V_64 ) )
F_72 ( & V_9 -> V_485 ) ;
break;
case V_270 :
V_473 = V_259 << 16 ;
F_6 ( V_9 -> V_18 ,
L_70 ) ;
break;
default:
V_473 = V_259 << 16 ;
F_6 ( V_9 -> V_18 ,
L_71 ,
V_473 ) ;
break;
}
break;
case V_486 :
V_473 |= V_487 << 16 ;
break;
case V_222 :
V_473 |= V_488 << 16 ;
break;
case V_489 :
case V_490 :
case V_491 :
case V_492 :
case V_493 :
case V_494 :
default:
V_473 |= V_259 << 16 ;
F_6 ( V_9 -> V_18 ,
L_72 , V_481 ) ;
break;
}
return V_473 ;
}
static void F_236 ( struct V_8 * V_9 , T_1 V_495 )
{
if ( ( V_495 & V_388 ) && V_9 -> V_112 ) {
V_9 -> V_112 -> V_173 |=
F_33 ( V_9 ) ;
V_9 -> V_112 -> V_174 =
F_34 ( V_9 ) ;
V_274 ( & V_9 -> V_112 -> V_178 ) ;
}
if ( ( V_495 & V_496 ) && V_9 -> V_113 )
V_274 ( V_9 -> V_113 ) ;
}
static void F_237 ( struct V_8 * V_9 ,
unsigned long V_497 )
{
struct V_44 * V_45 ;
struct V_187 * V_188 ;
int V_473 ;
int V_283 ;
F_238 (index, &completed_reqs, hba->nutrs) {
V_45 = & V_9 -> V_262 [ V_283 ] ;
V_188 = V_45 -> V_188 ;
if ( V_188 ) {
V_473 = F_235 ( V_9 , V_45 ) ;
F_239 ( V_188 ) ;
V_188 -> V_473 = V_473 ;
V_45 -> V_188 = NULL ;
F_27 ( V_283 , & V_9 -> V_110 ) ;
V_188 -> V_260 ( V_188 ) ;
F_78 ( V_9 ) ;
} else if ( V_45 -> V_218 == V_242 ||
V_45 -> V_218 == V_241 ) {
if ( V_9 -> V_147 . V_274 )
V_274 ( V_9 -> V_147 . V_274 ) ;
}
}
V_9 -> V_59 ^= V_497 ;
F_95 ( V_9 ) ;
F_160 ( & V_9 -> V_147 . V_278 ) ;
}
static void F_240 ( struct V_8 * V_9 )
{
unsigned long V_497 ;
T_1 V_498 ;
if ( F_146 ( V_9 ) )
F_40 ( V_9 ) ;
V_498 = F_12 ( V_9 , V_136 ) ;
V_497 = V_498 ^ V_9 -> V_59 ;
F_237 ( V_9 , V_497 ) ;
}
static int F_241 ( struct V_8 * V_9 , T_5 V_22 )
{
int V_26 = 0 ;
T_1 V_20 ;
if ( ! ( V_9 -> V_499 & V_22 ) )
goto V_53;
V_20 = V_9 -> V_499 & ~ V_22 ;
V_20 &= 0xFFFF ;
V_26 = F_166 ( V_9 , V_300 ,
V_500 , 0 , 0 , & V_20 ) ;
if ( ! V_26 )
V_9 -> V_499 &= ~ V_22 ;
V_53:
return V_26 ;
}
static int F_242 ( struct V_8 * V_9 , T_5 V_22 )
{
int V_26 = 0 ;
T_1 V_20 ;
if ( V_9 -> V_499 & V_22 )
goto V_53;
V_20 = V_9 -> V_499 | V_22 ;
V_20 &= 0xFFFF ;
V_26 = F_166 ( V_9 , V_300 ,
V_500 , 0 , 0 , & V_20 ) ;
if ( ! V_26 )
V_9 -> V_499 |= V_22 ;
V_53:
return V_26 ;
}
static int F_243 ( struct V_8 * V_9 )
{
int V_26 = 0 ;
if ( V_9 -> V_501 )
goto V_53;
V_26 = F_162 ( V_9 , V_291 ,
V_502 , NULL ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_73 ,
V_19 , V_26 ) ;
goto V_53;
}
V_9 -> V_501 = true ;
V_26 = F_241 ( V_9 , V_503 ) ;
if ( V_26 )
F_6 ( V_9 -> V_18 , L_74 ,
V_19 , V_26 ) ;
V_53:
return V_26 ;
}
static int F_244 ( struct V_8 * V_9 )
{
int V_26 = 0 ;
if ( ! V_9 -> V_501 )
goto V_53;
V_26 = F_242 ( V_9 , V_503 ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_75 ,
V_19 , V_26 ) ;
goto V_53;
}
V_26 = F_162 ( V_9 , V_292 ,
V_502 , NULL ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_76 ,
V_19 , V_26 ) ;
F_241 ( V_9 , V_503 ) ;
goto V_53;
}
V_9 -> V_501 = false ;
V_53:
return V_26 ;
}
static void F_245 ( struct V_8 * V_9 )
{
V_9 -> V_501 = false ;
V_9 -> V_499 |= V_503 ;
F_243 ( V_9 ) ;
}
static inline int F_246 ( struct V_8 * V_9 , T_1 * V_386 )
{
return F_166 ( V_9 , V_301 ,
V_504 , 0 , 0 , V_386 ) ;
}
static int F_247 ( struct V_8 * V_9 ,
enum V_505 V_386 )
{
int V_26 ;
T_1 V_506 = 0 ;
V_26 = F_246 ( V_9 , & V_506 ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_77 ,
V_19 , V_26 ) ;
goto V_53;
} else if ( V_506 > V_507 ) {
F_6 ( V_9 -> V_18 , L_78 ,
V_19 , V_506 ) ;
V_26 = - V_122 ;
goto V_53;
}
if ( V_506 >= V_386 )
V_26 = F_243 ( V_9 ) ;
else
V_26 = F_244 ( V_9 ) ;
V_53:
return V_26 ;
}
static int F_248 ( struct V_8 * V_9 )
{
return F_247 ( V_9 , V_9 -> V_508 ) ;
}
static inline int F_249 ( struct V_8 * V_9 , T_1 * V_386 )
{
return F_166 ( V_9 , V_301 ,
V_509 , 0 , 0 , V_386 ) ;
}
static void F_250 ( struct V_8 * V_9 )
{
int V_26 ;
T_1 V_506 = 0 ;
if ( V_9 -> V_510 )
goto V_511;
V_26 = F_246 ( V_9 , & V_506 ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_77 ,
V_19 , V_26 ) ;
goto V_53;
}
if ( V_506 < V_512 ) {
F_6 ( V_9 -> V_18 , L_79 ,
V_19 , V_506 ) ;
V_9 -> V_508 = V_506 ;
V_9 -> V_510 = true ;
}
V_511:
V_26 = F_243 ( V_9 ) ;
V_53:
if ( V_26 < 0 )
F_6 ( V_9 -> V_18 , L_80 ,
V_19 , V_26 ) ;
}
static void F_251 ( struct V_87 * V_88 )
{
struct V_8 * V_9 ;
int V_26 ;
T_1 V_386 = 0 ;
V_9 = F_56 ( V_88 , struct V_8 , V_485 ) ;
F_252 ( V_9 -> V_18 ) ;
V_26 = F_249 ( V_9 , & V_386 ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_81 ,
V_19 , V_26 ) ;
goto V_53;
}
V_386 &= V_9 -> V_499 ;
if ( V_386 & V_503 )
F_250 ( V_9 ) ;
V_53:
F_253 ( V_9 -> V_18 ) ;
return;
}
static void F_254 ( struct V_8 * V_9 )
{
F_240 ( V_9 ) ;
F_255 ( V_9 ) ;
}
static bool F_256 ( struct V_8 * V_9 )
{
unsigned long V_89 ;
bool V_513 = true ;
F_58 ( V_9 -> V_93 -> V_94 , V_89 ) ;
if ( V_9 -> V_514 & ( V_515 | V_516 ) )
goto V_53;
if ( ( V_9 -> V_514 & V_517 ) ||
( ( V_9 -> V_514 & V_518 ) &&
( V_9 -> V_519 & V_520 ) ) )
goto V_53;
if ( ( V_9 -> V_514 & V_518 ) &&
( V_9 -> V_519 & V_521 ) ) {
int V_26 ;
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
F_214 ( 50 ) ;
F_58 ( V_9 -> V_93 -> V_94 , V_89 ) ;
if ( ( V_9 -> V_514 & V_522 ) ||
( ( V_9 -> V_514 & V_518 ) &&
( V_9 -> V_519 & ~ V_521 ) ) )
goto V_53;
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
V_26 = F_222 ( V_9 ) ;
F_58 ( V_9 -> V_93 -> V_94 , V_89 ) ;
if ( V_26 )
goto V_53;
if ( V_9 -> V_519 == V_521 )
V_9 -> V_514 &= ~ V_518 ;
V_9 -> V_519 &= ~ V_521 ;
if ( ! V_9 -> V_519 ) {
V_513 = false ;
goto V_53;
}
}
V_53:
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
return V_513 ;
}
static void F_257 ( struct V_87 * V_88 )
{
struct V_8 * V_9 ;
unsigned long V_89 ;
T_1 V_523 = 0 ;
T_1 V_524 = 0 ;
int V_26 = 0 ;
int V_10 ;
bool V_525 = false ;
V_9 = F_56 ( V_88 , struct V_8 , V_526 ) ;
F_252 ( V_9 -> V_18 ) ;
F_66 ( V_9 , false ) ;
F_58 ( V_9 -> V_93 -> V_94 , V_89 ) ;
if ( V_9 -> V_108 == V_255 )
goto V_53;
V_9 -> V_108 = V_255 ;
F_197 ( V_9 ) ;
F_254 ( V_9 ) ;
if ( V_9 -> V_527 & V_528 ) {
bool V_12 ;
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
V_12 = F_256 ( V_9 ) ;
F_58 ( V_9 -> V_93 -> V_94 , V_89 ) ;
if ( ! V_12 )
goto V_529;
}
if ( ( V_9 -> V_514 & V_522 ) ||
( ( V_9 -> V_514 & V_518 ) &&
( V_9 -> V_519 & ( V_530 |
V_521 |
V_520 ) ) ) )
V_525 = true ;
if ( V_525 )
goto V_531;
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
F_238 (tag, &hba->outstanding_reqs, hba->nutrs) {
if ( F_149 ( V_9 , V_10 ) ) {
V_523 = true ;
goto V_532;
}
}
F_238 (tag, &hba->outstanding_tasks, hba->nutmrs) {
if ( F_258 ( V_9 , V_10 ) ) {
V_524 = true ;
goto V_532;
}
}
V_532:
F_58 ( V_9 -> V_93 -> V_94 , V_89 ) ;
F_254 ( V_9 ) ;
if ( V_523 || V_524 )
V_525 = true ;
V_531:
if ( V_525 ) {
unsigned long V_533 = ( 1UL << V_9 -> V_11 ) - 1 ;
if ( V_9 -> V_59 == V_533 )
F_237 ( V_9 ,
( 1UL << ( V_9 -> V_11 - 1 ) ) ) ;
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
V_26 = F_259 ( V_9 ) ;
F_58 ( V_9 -> V_93 -> V_94 , V_89 ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_82 ,
V_19 ) ;
V_9 -> V_108 = V_258 ;
}
F_260 ( V_9 -> V_93 , 0 ) ;
V_9 -> V_514 = 0 ;
V_9 -> V_519 = 0 ;
}
V_529:
if ( ! V_525 ) {
V_9 -> V_108 = V_109 ;
if ( V_9 -> V_514 || V_9 -> V_519 )
F_261 ( V_9 -> V_18 , L_83 ,
V_19 , V_9 -> V_514 , V_9 -> V_519 ) ;
}
F_199 ( V_9 ) ;
V_53:
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
F_65 ( V_9 -> V_93 ) ;
F_80 ( V_9 ) ;
F_253 ( V_9 -> V_18 ) ;
}
static void F_262 ( struct V_8 * V_9 )
{
T_1 V_21 ;
V_21 = F_12 ( V_9 , V_534 ) ;
if ( ( V_21 & V_535 ) &&
( V_21 & V_536 ) )
F_153 ( V_9 -> V_18 , L_84 , V_19 ) ;
V_21 = F_12 ( V_9 , V_537 ) ;
if ( V_21 & V_538 )
V_9 -> V_539 |= V_530 ;
else if ( V_9 -> V_527 &
V_528 ) {
if ( V_21 & V_540 )
V_9 -> V_539 |=
V_521 ;
else if ( V_21 & V_541 )
V_9 -> V_539 |= V_520 ;
}
V_21 = F_12 ( V_9 , V_542 ) ;
if ( V_21 )
V_9 -> V_539 |= V_543 ;
V_21 = F_12 ( V_9 , V_544 ) ;
if ( V_21 )
V_9 -> V_539 |= V_545 ;
V_21 = F_12 ( V_9 , V_546 ) ;
if ( V_21 )
V_9 -> V_539 |= V_547 ;
F_153 ( V_9 -> V_18 , L_85 ,
V_19 , V_9 -> V_539 ) ;
}
static void F_263 ( struct V_8 * V_9 )
{
bool V_548 = false ;
if ( V_9 -> V_549 & V_522 )
V_548 = true ;
if ( V_9 -> V_549 & V_518 ) {
V_9 -> V_539 = 0 ;
F_262 ( V_9 ) ;
if ( V_9 -> V_539 )
V_548 = true ;
}
if ( V_548 ) {
V_9 -> V_514 |= V_9 -> V_549 ;
V_9 -> V_519 |= V_9 -> V_539 ;
if ( V_9 -> V_108 == V_109 ) {
F_71 ( V_9 -> V_93 ) ;
V_9 -> V_108 = V_254 ;
F_72 ( & V_9 -> V_526 ) ;
}
}
}
static void F_255 ( struct V_8 * V_9 )
{
T_1 V_550 ;
V_550 = F_12 ( V_9 , V_551 ) ;
V_9 -> V_552 = V_550 ^ V_9 -> V_111 ;
F_160 ( & V_9 -> V_553 ) ;
}
static void F_264 ( struct V_8 * V_9 , T_1 V_495 )
{
V_9 -> V_549 = V_554 & V_495 ;
if ( V_9 -> V_549 )
F_263 ( V_9 ) ;
if ( V_495 & V_433 )
F_236 ( V_9 , V_495 ) ;
if ( V_495 & V_555 )
F_255 ( V_9 ) ;
if ( V_495 & V_556 )
F_240 ( V_9 ) ;
}
static T_7 V_15 ( int V_14 , void * V_557 )
{
T_1 V_495 , V_558 ;
T_7 V_559 = V_560 ;
struct V_8 * V_9 = V_557 ;
F_265 ( V_9 -> V_93 -> V_94 ) ;
V_495 = F_12 ( V_9 , V_561 ) ;
V_558 =
V_495 & F_12 ( V_9 , V_201 ) ;
if ( V_495 )
F_29 ( V_9 , V_495 , V_561 ) ;
if ( V_558 ) {
F_264 ( V_9 , V_558 ) ;
V_559 = V_562 ;
}
F_266 ( V_9 -> V_93 -> V_94 ) ;
return V_559 ;
}
static int F_258 ( struct V_8 * V_9 , int V_10 )
{
int V_26 = 0 ;
T_1 V_22 = 1 << V_10 ;
unsigned long V_89 ;
if ( ! F_267 ( V_10 , & V_9 -> V_111 ) )
goto V_53;
F_58 ( V_9 -> V_93 -> V_94 , V_89 ) ;
F_29 ( V_9 , ~ ( 1 << V_10 ) , V_563 ) ;
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
V_26 = F_10 ( V_9 ,
V_551 ,
V_22 , 0 , 1000 , 1000 , true ) ;
V_53:
return V_26 ;
}
static int F_268 ( struct V_8 * V_9 , int V_564 , int V_565 ,
T_2 V_566 , T_2 * V_567 )
{
struct V_50 * V_51 ;
struct V_568 * V_569 ;
struct V_253 * V_93 ;
unsigned long V_89 ;
int V_52 ;
int V_26 ;
int V_135 ;
V_93 = V_9 -> V_93 ;
F_158 ( V_9 -> V_570 , F_23 ( V_9 , & V_52 ) ) ;
F_66 ( V_9 , false ) ;
F_58 ( V_93 -> V_94 , V_89 ) ;
V_51 = V_9 -> V_342 ;
V_51 += V_52 ;
V_51 -> V_47 . V_65 = F_124 ( V_221 ) ;
V_51 -> V_47 . V_48 =
F_124 ( V_222 ) ;
V_569 =
(struct V_568 * ) V_51 -> V_571 ;
V_135 = V_9 -> V_11 + V_52 ;
V_569 -> V_47 . V_65 =
F_132 ( V_572 , 0 ,
V_564 , V_135 ) ;
V_569 -> V_47 . V_66 =
F_132 ( 0 , V_566 , 0 , 0 ) ;
V_569 -> V_573 = F_133 ( V_564 ) ;
V_569 -> V_574 = F_133 ( V_565 ) ;
F_269 ( V_9 , V_52 , V_566 ) ;
F_99 ( V_52 , & V_9 -> V_111 ) ;
F_100 () ;
F_29 ( V_9 , 1 << V_52 , V_551 ) ;
F_100 () ;
F_59 ( V_93 -> V_94 , V_89 ) ;
V_26 = F_270 ( V_9 -> V_553 ,
F_267 ( V_52 , & V_9 -> V_552 ) ,
F_11 ( V_575 ) ) ;
if ( ! V_26 ) {
F_6 ( V_9 -> V_18 , L_86 ,
V_19 , V_566 ) ;
if ( F_258 ( V_9 , V_52 ) )
F_271 ( V_9 -> V_18 , L_87 ,
V_19 , V_52 ) ;
V_26 = - V_29 ;
} else {
V_26 = F_233 ( V_9 , V_52 , V_567 ) ;
}
F_272 ( V_52 , & V_9 -> V_552 ) ;
F_26 ( V_9 , V_52 ) ;
F_160 ( & V_9 -> V_570 ) ;
F_80 ( V_9 ) ;
return V_26 ;
}
static int F_273 ( struct V_187 * V_188 )
{
struct V_253 * V_93 ;
struct V_8 * V_9 ;
unsigned int V_10 ;
T_1 V_57 ;
int V_26 ;
T_2 V_267 = 0xF ;
struct V_44 * V_45 ;
unsigned long V_89 ;
V_93 = V_188 -> V_115 -> V_93 ;
V_9 = F_142 ( V_93 ) ;
V_10 = V_188 -> V_160 -> V_10 ;
V_45 = & V_9 -> V_262 [ V_10 ] ;
V_26 = F_268 ( V_9 , V_45 -> V_228 , 0 , V_576 , & V_267 ) ;
if ( V_26 || V_267 != V_577 ) {
if ( ! V_26 )
V_26 = V_267 ;
goto V_53;
}
F_238 (pos, &hba->outstanding_reqs, hba->nutrs) {
if ( V_9 -> V_262 [ V_57 ] . V_228 == V_45 -> V_228 ) {
V_26 = F_149 ( V_9 , V_57 ) ;
if ( V_26 )
break;
}
}
F_58 ( V_93 -> V_94 , V_89 ) ;
F_240 ( V_9 ) ;
F_59 ( V_93 -> V_94 , V_89 ) ;
V_53:
if ( ! V_26 ) {
V_26 = V_578 ;
} else {
F_6 ( V_9 -> V_18 , L_88 , V_19 , V_26 ) ;
V_26 = V_579 ;
}
return V_26 ;
}
static int F_274 ( struct V_187 * V_188 )
{
struct V_253 * V_93 ;
struct V_8 * V_9 ;
unsigned long V_89 ;
unsigned int V_10 ;
int V_26 = 0 ;
int V_580 ;
T_2 V_267 = 0xF ;
struct V_44 * V_45 ;
T_1 V_21 ;
V_93 = V_188 -> V_115 -> V_93 ;
V_9 = F_142 ( V_93 ) ;
V_10 = V_188 -> V_160 -> V_10 ;
if ( ! F_3 ( V_9 , V_10 ) ) {
F_6 ( V_9 -> V_18 ,
L_9 ,
V_19 , V_10 , V_188 , V_188 -> V_160 ) ;
F_143 () ;
}
F_66 ( V_9 , false ) ;
V_21 = F_12 ( V_9 , V_136 ) ;
if ( ! ( F_267 ( V_10 , & V_9 -> V_59 ) ) ) {
F_6 ( V_9 -> V_18 ,
L_89 ,
V_19 , V_10 , V_9 -> V_59 , V_21 ) ;
goto V_53;
}
if ( ! ( V_21 & ( 1 << V_10 ) ) ) {
F_6 ( V_9 -> V_18 ,
L_90 ,
V_19 , V_10 ) ;
}
V_45 = & V_9 -> V_262 [ V_10 ] ;
for ( V_580 = 100 ; V_580 ; V_580 -- ) {
V_26 = F_268 ( V_9 , V_45 -> V_228 , V_45 -> V_135 ,
V_581 , & V_267 ) ;
if ( ! V_26 && V_267 == V_582 ) {
break;
} else if ( ! V_26 && V_267 == V_577 ) {
V_21 = F_12 ( V_9 , V_136 ) ;
if ( V_21 & ( 1 << V_10 ) ) {
F_13 ( 100 , 200 ) ;
continue;
}
goto V_53;
} else {
if ( ! V_26 )
V_26 = V_267 ;
goto V_53;
}
}
if ( ! V_580 ) {
V_26 = - V_583 ;
goto V_53;
}
V_26 = F_268 ( V_9 , V_45 -> V_228 , V_45 -> V_135 ,
V_584 , & V_267 ) ;
if ( V_26 || V_267 != V_577 ) {
if ( ! V_26 )
V_26 = V_267 ;
goto V_53;
}
V_26 = F_149 ( V_9 , V_10 ) ;
if ( V_26 )
goto V_53;
F_239 ( V_188 ) ;
F_58 ( V_93 -> V_94 , V_89 ) ;
F_30 ( V_9 , V_10 ) ;
V_9 -> V_262 [ V_10 ] . V_188 = NULL ;
F_59 ( V_93 -> V_94 , V_89 ) ;
F_27 ( V_10 , & V_9 -> V_110 ) ;
F_160 ( & V_9 -> V_147 . V_278 ) ;
V_53:
if ( ! V_26 ) {
V_26 = V_578 ;
} else {
F_6 ( V_9 -> V_18 , L_88 , V_19 , V_26 ) ;
V_26 = V_579 ;
}
F_80 ( V_9 ) ;
return V_26 ;
}
static int F_198 ( struct V_8 * V_9 )
{
int V_26 ;
unsigned long V_89 ;
F_58 ( V_9 -> V_93 -> V_94 , V_89 ) ;
F_210 ( V_9 , false ) ;
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
V_26 = F_211 ( V_9 ) ;
if ( V_26 )
goto V_53;
V_26 = F_275 ( V_9 ) ;
if ( ! V_26 && ( V_9 -> V_108 != V_109 ) )
V_26 = - V_181 ;
V_53:
if ( V_26 )
F_6 ( V_9 -> V_18 , L_91 , V_19 , V_26 ) ;
return V_26 ;
}
static int F_259 ( struct V_8 * V_9 )
{
int V_26 = 0 ;
unsigned long V_89 ;
int V_287 = V_585 ;
do {
V_26 = F_198 ( V_9 ) ;
} while ( V_26 && -- V_287 );
F_58 ( V_9 -> V_93 -> V_94 , V_89 ) ;
F_240 ( V_9 ) ;
F_255 ( V_9 ) ;
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
return V_26 ;
}
static int F_276 ( struct V_187 * V_188 )
{
int V_26 ;
unsigned long V_89 ;
struct V_8 * V_9 ;
V_9 = F_142 ( V_188 -> V_115 -> V_93 ) ;
F_66 ( V_9 , false ) ;
do {
F_58 ( V_9 -> V_93 -> V_94 , V_89 ) ;
if ( ! ( F_277 ( & V_9 -> V_526 ) ||
V_9 -> V_108 == V_255 ) )
break;
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
F_153 ( V_9 -> V_18 , L_92 , V_19 ) ;
F_69 ( & V_9 -> V_526 ) ;
} while ( 1 );
V_9 -> V_108 = V_255 ;
F_197 ( V_9 ) ;
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
V_26 = F_259 ( V_9 ) ;
F_58 ( V_9 -> V_93 -> V_94 , V_89 ) ;
if ( ! V_26 ) {
V_26 = V_578 ;
V_9 -> V_108 = V_109 ;
} else {
V_26 = V_579 ;
V_9 -> V_108 = V_258 ;
}
F_199 ( V_9 ) ;
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
F_80 ( V_9 ) ;
return V_26 ;
}
static T_1 F_278 ( int V_586 , T_1 V_587 , char * V_588 )
{
int V_190 ;
int V_589 ;
T_5 V_590 ;
T_5 V_591 ;
for ( V_190 = V_587 ; V_190 >= 0 ; V_190 -- ) {
V_590 = F_102 ( * ( ( T_5 * ) ( V_588 + 2 * V_190 ) ) ) ;
V_591 = ( V_590 & V_592 ) >>
V_593 ;
V_589 = V_590 & V_594 ;
switch ( V_591 ) {
case V_595 :
V_589 = V_589 / 1000 ;
break;
case V_596 :
V_589 = V_589 * 1000 ;
break;
case V_597 :
V_589 = V_589 * 1000 * 1000 ;
break;
case V_598 :
default:
break;
}
if ( V_586 >= V_589 )
break;
}
if ( V_190 < 0 ) {
V_190 = 0 ;
F_279 ( L_93 , V_19 , V_190 ) ;
}
return ( T_1 ) V_190 ;
}
static T_1 F_280 ( struct V_8 * V_9 ,
T_2 * V_303 , int V_137 )
{
T_1 V_599 = 0 ;
if ( ! V_9 -> V_600 . V_601 || ! V_9 -> V_600 . V_602 ||
! V_9 -> V_600 . V_603 ) {
F_6 ( V_9 -> V_18 ,
L_94 ,
V_19 , V_599 ) ;
goto V_53;
}
if ( V_9 -> V_600 . V_601 )
V_599 = F_278 (
V_9 -> V_600 . V_601 -> V_604 ,
V_605 - 1 ,
& V_303 [ V_606 ] ) ;
if ( V_9 -> V_600 . V_602 )
V_599 = F_278 (
V_9 -> V_600 . V_602 -> V_604 ,
V_599 ,
& V_303 [ V_607 ] ) ;
if ( V_9 -> V_600 . V_603 )
V_599 = F_278 (
V_9 -> V_600 . V_603 -> V_604 ,
V_599 ,
& V_303 [ V_608 ] ) ;
V_53:
return V_599 ;
}
static int F_281 ( struct V_8 * V_9 , T_1 V_599 )
{
int V_12 = 0 ;
int V_287 ;
for ( V_287 = V_288 ; V_287 > 0 ; V_287 -- ) {
V_12 = F_165 ( V_9 , V_300 ,
V_609 , 0 , 0 , & V_599 ) ;
if ( ! V_12 )
break;
F_153 ( V_9 -> V_18 , L_95 , V_19 , V_12 ) ;
}
return V_12 ;
}
static void F_282 ( struct V_8 * V_9 )
{
int V_12 ;
int V_311 = V_610 ;
T_2 V_303 [ V_610 ] ;
V_12 = F_174 ( V_9 , V_303 , V_311 ) ;
if ( V_12 ) {
F_6 ( V_9 -> V_18 ,
L_96 ,
V_19 , V_311 , V_12 ) ;
return;
}
V_9 -> V_611 . V_599 =
F_280 ( V_9 ,
V_303 , V_311 ) ;
F_153 ( V_9 -> V_18 , L_97 ,
V_19 , V_9 -> V_611 . V_599 ) ;
V_12 = F_281 ( V_9 ,
V_9 -> V_611 . V_599 ) ;
if ( V_12 )
F_6 ( V_9 -> V_18 ,
L_98 ,
V_19 , V_9 -> V_611 . V_599 , V_12 ) ;
}
static int F_283 ( struct V_8 * V_9 )
{
int V_12 = 0 ;
struct V_443 * V_612 ;
struct V_443 * V_613 ;
V_9 -> V_463 = F_284 ( V_9 -> V_93 , 0 , 0 ,
F_140 ( V_462 ) , NULL ) ;
if ( F_285 ( V_9 -> V_463 ) ) {
V_12 = F_286 ( V_9 -> V_463 ) ;
V_9 -> V_463 = NULL ;
goto V_53;
}
F_287 ( V_9 -> V_463 ) ;
V_613 = F_284 ( V_9 -> V_93 , 0 , 0 ,
F_140 ( V_614 ) , NULL ) ;
if ( F_285 ( V_613 ) ) {
V_12 = F_286 ( V_613 ) ;
goto V_615;
}
F_287 ( V_613 ) ;
V_612 = F_284 ( V_9 -> V_93 , 0 , 0 ,
F_140 ( V_330 ) , NULL ) ;
if ( F_285 ( V_612 ) ) {
V_12 = F_286 ( V_612 ) ;
goto V_616;
}
F_287 ( V_612 ) ;
goto V_53;
V_616:
F_288 ( V_613 ) ;
V_615:
F_288 ( V_9 -> V_463 ) ;
V_53:
return V_12 ;
}
static int F_289 ( struct V_8 * V_9 ,
struct V_617 * V_618 )
{
int V_26 ;
T_2 V_619 ;
T_2 V_620 [ V_621 + 1 ] = { 0 } ;
T_2 V_303 [ V_622 ] ;
V_26 = F_175 ( V_9 , V_303 ,
V_622 ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_99 ,
V_19 , V_26 ) ;
goto V_53;
}
V_618 -> V_623 = V_303 [ V_624 ] << 8 |
V_303 [ V_624 + 1 ] ;
V_619 = V_303 [ V_625 ] ;
V_26 = F_176 ( V_9 , V_619 , V_620 ,
V_621 , V_626 ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_100 ,
V_19 , V_26 ) ;
goto V_53;
}
V_620 [ V_621 ] = '\0' ;
F_290 ( V_618 -> V_627 , ( V_620 + V_326 ) ,
F_103 ( T_2 , V_620 [ V_319 ] ,
V_628 ) ) ;
V_618 -> V_627 [ V_628 ] = '\0' ;
V_53:
return V_26 ;
}
void F_291 ( struct V_8 * V_9 )
{
int V_26 ;
struct V_629 * V_630 ;
struct V_617 V_618 ;
V_618 . V_623 = 0 ;
V_26 = F_289 ( V_9 , & V_618 ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_101 ,
V_19 , V_26 ) ;
return;
}
for ( V_630 = V_631 ; V_630 -> V_632 ; V_630 ++ ) {
if ( ( ( V_630 -> V_633 . V_623 == V_618 . V_623 ) ||
( V_630 -> V_633 . V_623 == V_634 ) ) &&
( F_292 ( V_630 -> V_633 . V_627 , V_618 . V_627 ) ||
! strcmp ( V_630 -> V_633 . V_627 , V_635 ) ) )
V_9 -> V_527 |= V_630 -> V_632 ;
}
}
static int F_293 ( struct V_8 * V_9 )
{
int V_12 = 0 ;
T_1 V_636 = 0 , V_637 ;
V_12 = F_205 ( V_9 ,
F_194 (
V_638 ,
F_294 ( 0 ) ) ,
& V_636 ) ;
if ( V_12 )
goto V_53;
V_637 =
( ( V_636 * V_639 )
/ V_640 ) ;
V_12 = F_193 ( V_9 , F_195 ( V_641 ) ,
V_637 ) ;
V_53:
return V_12 ;
}
static int F_295 ( struct V_8 * V_9 )
{
int V_12 = 0 ;
T_1 V_642 = 0 , V_643 = 0 ;
T_1 V_644 , V_645 ;
V_12 = F_204 ( V_9 ,
F_194 ( V_646 ,
F_216 ( 0 ) ) ,
& V_642 ) ;
if ( V_12 )
goto V_53;
V_12 = F_205 ( V_9 ,
F_194 ( V_647 ,
F_294 ( 0 ) ) ,
& V_643 ) ;
if ( V_12 )
goto V_53;
V_644 = F_296 ( V_642 ,
V_643 ) ;
V_645 = ( ( V_644 * V_648 )
/ V_649 ) ;
V_12 = F_193 ( V_9 , F_195 ( V_650 ) ,
V_645 ) ;
V_53:
return V_12 ;
}
static int F_297 ( struct V_8 * V_9 )
{
int V_12 = 0 ;
T_1 V_651 , V_652 ;
T_1 V_653 , V_654 ;
T_1 V_655 , V_656 ;
T_2 V_657 [] = { 1 , 4 , 8 , 16 , 32 , 100 } ;
V_12 = F_204 ( V_9 , F_195 ( V_658 ) ,
& V_651 ) ;
if ( V_12 )
goto V_53;
V_12 = F_205 ( V_9 , F_195 ( V_658 ) ,
& V_652 ) ;
if ( V_12 )
goto V_53;
if ( ( V_651 < V_659 ) ||
( V_651 > V_660 ) ) {
F_6 ( V_9 -> V_18 , L_102 ,
V_19 , V_651 ) ;
return - V_122 ;
}
if ( ( V_652 < V_659 ) ||
( V_652 > V_660 ) ) {
F_6 ( V_9 -> V_18 , L_103 ,
V_19 , V_652 ) ;
return - V_122 ;
}
V_12 = F_204 ( V_9 , F_195 ( V_641 ) , & V_653 ) ;
if ( V_12 )
goto V_53;
V_12 = F_205 ( V_9 , F_195 ( V_641 ) ,
& V_654 ) ;
if ( V_12 )
goto V_53;
V_655 = V_653 * V_657 [ V_651 - 1 ] ;
V_656 = V_654 *
V_657 [ V_652 - 1 ] ;
if ( V_655 > V_656 ) {
T_1 V_661 ;
V_661 = V_655 /
V_657 [ V_652 - 1 ] ;
V_661 ++ ;
V_12 = F_217 ( V_9 , F_195 ( V_641 ) ,
V_661 ) ;
}
V_53:
return V_12 ;
}
static void F_298 ( struct V_8 * V_9 )
{
if ( F_49 ( V_9 ) ) {
F_293 ( V_9 ) ;
F_295 ( V_9 ) ;
}
if ( V_9 -> V_527 & V_662 )
F_193 ( V_9 , F_195 ( V_641 ) , 10 ) ;
if ( V_9 -> V_527 & V_663 )
F_297 ( V_9 ) ;
F_299 ( V_9 ) ;
}
static int F_275 ( struct V_8 * V_9 )
{
int V_12 ;
V_12 = F_219 ( V_9 ) ;
if ( V_12 )
goto V_53;
F_202 ( V_9 ) ;
V_9 -> V_508 = V_512 ;
V_9 -> V_510 = false ;
F_64 ( V_9 ) ;
V_12 = F_222 ( V_9 ) ;
if ( V_12 )
goto V_53;
V_12 = F_208 ( V_9 ) ;
if ( V_12 )
goto V_53;
F_291 ( V_9 ) ;
F_298 ( V_9 ) ;
V_12 = F_300 ( V_9 ,
( V_9 -> V_527 & V_664 ) ? true : false ) ;
if ( V_12 )
goto V_53;
F_301 ( V_9 ) ;
F_245 ( V_9 ) ;
V_9 -> V_665 = true ;
if ( F_203 ( V_9 ) ) {
F_6 ( V_9 -> V_18 ,
L_104 ,
V_19 ) ;
} else {
V_12 = F_207 ( V_9 , & V_9 -> V_406 . V_407 ) ;
if ( V_12 ) {
F_6 ( V_9 -> V_18 , L_105 ,
V_19 , V_12 ) ;
goto V_53;
}
}
V_9 -> V_108 = V_109 ;
if ( ! F_68 ( V_9 ) && ! V_9 -> V_484 ) {
bool V_666 ;
memset ( & V_9 -> V_450 , 0 , sizeof( V_9 -> V_450 ) ) ;
if ( ! F_162 ( V_9 , V_295 ,
V_667 , & V_666 ) )
V_9 -> V_450 . V_451 = V_666 ;
if ( ! V_9 -> V_668 )
F_282 ( V_9 ) ;
if ( F_283 ( V_9 ) )
goto V_53;
F_302 ( V_9 -> V_93 ) ;
F_253 ( V_9 -> V_18 ) ;
}
if ( ! V_9 -> V_668 )
V_9 -> V_668 = true ;
F_53 ( V_9 ) ;
V_53:
if ( V_12 && ! F_68 ( V_9 ) && ! V_9 -> V_484 ) {
F_253 ( V_9 -> V_18 ) ;
F_303 ( V_9 ) ;
}
return V_12 ;
}
static void F_304 ( void * V_590 , T_8 V_669 )
{
struct V_8 * V_9 = (struct V_8 * ) V_590 ;
F_275 ( V_9 ) ;
}
static enum V_670 F_305 ( struct V_187 * V_671 )
{
unsigned long V_89 ;
struct V_253 * V_93 ;
struct V_8 * V_9 ;
int V_283 ;
bool V_672 = false ;
if ( ! V_671 || ! V_671 -> V_115 || ! V_671 -> V_115 -> V_93 )
return V_673 ;
V_93 = V_671 -> V_115 -> V_93 ;
V_9 = F_142 ( V_93 ) ;
if ( ! V_9 )
return V_673 ;
F_58 ( V_93 -> V_94 , V_89 ) ;
F_238 (index, &hba->outstanding_reqs, hba->nutrs) {
if ( V_9 -> V_262 [ V_283 ] . V_188 == V_671 ) {
V_672 = true ;
break;
}
}
F_59 ( V_93 -> V_94 , V_89 ) ;
return V_672 ? V_673 : V_674 ;
}
static int F_306 ( struct V_115 * V_18 , struct V_675 * V_676 ,
int V_677 )
{
int V_12 ;
if ( ! V_676 )
return 0 ;
V_12 = F_307 ( V_676 -> V_21 , V_677 ) ;
if ( V_12 < 0 ) {
F_6 ( V_18 , L_106 ,
V_19 , V_676 -> V_126 , V_677 , V_12 ) ;
}
return V_12 ;
}
static inline int F_308 ( struct V_8 * V_9 ,
struct V_675 * V_676 )
{
if ( ! V_676 )
return 0 ;
else if ( V_676 -> V_678 )
return 0 ;
else
return F_306 ( V_9 -> V_18 , V_676 ,
V_679 ) ;
}
static inline int F_309 ( struct V_8 * V_9 ,
struct V_675 * V_676 )
{
if ( ! V_676 )
return 0 ;
else if ( V_676 -> V_678 )
return 0 ;
else
return F_306 ( V_9 -> V_18 , V_676 , V_676 -> V_604 ) ;
}
static int F_310 ( struct V_115 * V_18 ,
struct V_675 * V_676 , bool V_680 )
{
int V_12 = 0 ;
struct V_681 * V_21 = V_676 -> V_21 ;
const char * V_126 = V_676 -> V_126 ;
int V_682 , V_683 ;
F_164 ( ! V_676 ) ;
if ( F_311 ( V_21 ) > 0 ) {
V_682 = V_680 ? V_676 -> V_682 : 0 ;
V_12 = F_312 ( V_21 , V_682 , V_676 -> V_684 ) ;
if ( V_12 ) {
F_6 ( V_18 , L_107 ,
V_19 , V_126 , V_12 ) ;
goto V_53;
}
V_683 = V_680 ? V_676 -> V_604 : 0 ;
V_12 = F_306 ( V_18 , V_676 , V_683 ) ;
if ( V_12 )
goto V_53;
}
V_53:
return V_12 ;
}
static int F_313 ( struct V_115 * V_18 , struct V_675 * V_676 )
{
int V_12 = 0 ;
if ( ! V_676 )
goto V_53;
else if ( V_676 -> V_685 || V_676 -> V_678 )
goto V_53;
V_12 = F_310 ( V_18 , V_676 , true ) ;
if ( ! V_12 )
V_12 = F_314 ( V_676 -> V_21 ) ;
if ( ! V_12 )
V_676 -> V_685 = true ;
else
F_6 ( V_18 , L_108 ,
V_19 , V_676 -> V_126 , V_12 ) ;
V_53:
return V_12 ;
}
static int F_315 ( struct V_115 * V_18 , struct V_675 * V_676 )
{
int V_12 = 0 ;
if ( ! V_676 )
goto V_53;
else if ( ! V_676 -> V_685 || V_676 -> V_678 )
goto V_53;
V_12 = F_316 ( V_676 -> V_21 ) ;
if ( ! V_12 ) {
F_310 ( V_18 , V_676 , false ) ;
V_676 -> V_685 = false ;
} else {
F_6 ( V_18 , L_109 ,
V_19 , V_676 -> V_126 , V_12 ) ;
}
V_53:
return V_12 ;
}
static int F_317 ( struct V_8 * V_9 , bool V_680 )
{
int V_12 = 0 ;
struct V_115 * V_18 = V_9 -> V_18 ;
struct V_686 * V_407 = & V_9 -> V_600 ;
if ( ! V_407 )
goto V_53;
V_12 = F_318 ( V_18 , V_407 -> V_601 , V_680 ) ;
if ( V_12 )
goto V_53;
V_12 = F_318 ( V_18 , V_407 -> V_602 , V_680 ) ;
if ( V_12 )
goto V_53;
V_12 = F_318 ( V_18 , V_407 -> V_603 , V_680 ) ;
if ( V_12 )
goto V_53;
V_53:
if ( V_12 ) {
F_318 ( V_18 , V_407 -> V_603 , false ) ;
F_318 ( V_18 , V_407 -> V_602 , false ) ;
F_318 ( V_18 , V_407 -> V_601 , false ) ;
}
return V_12 ;
}
static int F_319 ( struct V_8 * V_9 , bool V_680 )
{
struct V_686 * V_407 = & V_9 -> V_600 ;
if ( V_407 )
return F_318 ( V_9 -> V_18 , V_407 -> V_687 , V_680 ) ;
return 0 ;
}
static int F_320 ( struct V_115 * V_18 , struct V_675 * V_676 )
{
int V_12 = 0 ;
if ( ! V_676 )
goto V_53;
V_676 -> V_21 = F_321 ( V_18 , V_676 -> V_126 ) ;
if ( F_285 ( V_676 -> V_21 ) ) {
V_12 = F_286 ( V_676 -> V_21 ) ;
F_6 ( V_18 , L_110 ,
V_19 , V_676 -> V_126 , V_12 ) ;
}
V_53:
return V_12 ;
}
static int F_322 ( struct V_8 * V_9 )
{
int V_12 = 0 ;
struct V_115 * V_18 = V_9 -> V_18 ;
struct V_686 * V_407 = & V_9 -> V_600 ;
if ( ! V_407 )
goto V_53;
V_12 = F_320 ( V_18 , V_407 -> V_601 ) ;
if ( V_12 )
goto V_53;
V_12 = F_320 ( V_18 , V_407 -> V_602 ) ;
if ( V_12 )
goto V_53;
V_12 = F_320 ( V_18 , V_407 -> V_603 ) ;
V_53:
return V_12 ;
}
static int F_323 ( struct V_8 * V_9 )
{
struct V_686 * V_407 = & V_9 -> V_600 ;
if ( V_407 )
return F_320 ( V_9 -> V_18 , V_407 -> V_687 ) ;
return 0 ;
}
static int F_300 ( struct V_8 * V_9 , bool V_678 )
{
int V_12 = 0 ;
struct V_686 * V_407 = & V_9 -> V_600 ;
if ( ! V_407 )
goto V_53;
else if ( ! V_407 -> V_602 )
goto V_53;
if ( V_678 ) {
V_12 = F_318 ( V_9 -> V_18 , V_407 -> V_602 , false ) ;
if ( ! V_12 )
V_407 -> V_602 -> V_678 = true ;
} else {
V_407 -> V_602 -> V_678 = false ;
}
V_53:
return V_12 ;
}
static int F_77 ( struct V_8 * V_9 , bool V_680 ,
bool V_688 )
{
int V_12 = 0 ;
struct V_689 * V_690 ;
struct V_691 * V_692 = & V_9 -> V_693 ;
unsigned long V_89 ;
if ( ! V_692 || F_324 ( V_692 ) )
goto V_53;
V_12 = F_325 ( V_9 , V_680 , V_395 ) ;
if ( V_12 )
return V_12 ;
F_326 (clki, head, list) {
if ( ! F_327 ( V_690 -> V_694 ) ) {
if ( V_688 && ! strcmp ( V_690 -> V_126 , L_111 ) )
continue;
if ( V_680 && ! V_690 -> V_685 ) {
V_12 = F_328 ( V_690 -> V_694 ) ;
if ( V_12 ) {
F_6 ( V_9 -> V_18 , L_112 ,
V_19 , V_690 -> V_126 , V_12 ) ;
goto V_53;
}
} else if ( ! V_680 && V_690 -> V_685 ) {
F_329 ( V_690 -> V_694 ) ;
}
V_690 -> V_685 = V_680 ;
F_153 ( V_9 -> V_18 , L_113 , V_19 ,
V_690 -> V_126 , V_680 ? L_114 : L_115 ) ;
}
}
V_12 = F_325 ( V_9 , V_680 , V_397 ) ;
if ( V_12 )
return V_12 ;
V_53:
if ( V_12 ) {
F_326 (clki, head, list) {
if ( ! F_327 ( V_690 -> V_694 ) && V_690 -> V_685 )
F_329 ( V_690 -> V_694 ) ;
}
} else if ( V_680 ) {
F_58 ( V_9 -> V_93 -> V_94 , V_89 ) ;
V_9 -> V_90 . V_95 = V_96 ;
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
}
return V_12 ;
}
static int F_60 ( struct V_8 * V_9 , bool V_680 )
{
return F_77 ( V_9 , V_680 , false ) ;
}
static int F_330 ( struct V_8 * V_9 )
{
int V_12 = 0 ;
struct V_689 * V_690 ;
struct V_115 * V_18 = V_9 -> V_18 ;
struct V_691 * V_692 = & V_9 -> V_693 ;
if ( ! V_692 || F_324 ( V_692 ) )
goto V_53;
F_326 (clki, head, list) {
if ( ! V_690 -> V_126 )
continue;
V_690 -> V_694 = F_331 ( V_18 , V_690 -> V_126 ) ;
if ( F_285 ( V_690 -> V_694 ) ) {
V_12 = F_286 ( V_690 -> V_694 ) ;
F_6 ( V_18 , L_116 ,
V_19 , V_690 -> V_126 , V_12 ) ;
goto V_53;
}
if ( V_690 -> V_695 ) {
V_12 = F_332 ( V_690 -> V_694 , V_690 -> V_695 ) ;
if ( V_12 ) {
F_6 ( V_9 -> V_18 , L_117 ,
V_19 , V_690 -> V_126 ,
V_690 -> V_695 , V_12 ) ;
goto V_53;
}
V_690 -> V_696 = V_690 -> V_695 ;
}
F_153 ( V_18 , L_118 , V_19 ,
V_690 -> V_126 , F_333 ( V_690 -> V_694 ) ) ;
}
V_53:
return V_12 ;
}
static int F_334 ( struct V_8 * V_9 )
{
int V_26 = 0 ;
if ( ! V_9 -> V_697 )
goto V_53;
V_26 = F_335 ( V_9 ) ;
if ( V_26 )
goto V_53;
V_26 = F_336 ( V_9 , true ) ;
if ( V_26 )
goto V_698;
goto V_53;
V_698:
F_337 ( V_9 ) ;
V_53:
if ( V_26 )
F_6 ( V_9 -> V_18 , L_119 ,
V_19 , F_338 ( V_9 ) , V_26 ) ;
return V_26 ;
}
static void F_339 ( struct V_8 * V_9 )
{
if ( ! V_9 -> V_697 )
return;
F_336 ( V_9 , false ) ;
F_337 ( V_9 ) ;
}
static int F_340 ( struct V_8 * V_9 )
{
int V_26 ;
V_26 = F_323 ( V_9 ) ;
if ( V_26 )
goto V_53;
V_26 = F_319 ( V_9 , true ) ;
if ( V_26 )
goto V_53;
V_26 = F_330 ( V_9 ) ;
if ( V_26 )
goto V_699;
V_26 = F_60 ( V_9 , true ) ;
if ( V_26 )
goto V_699;
V_26 = F_322 ( V_9 ) ;
if ( V_26 )
goto V_700;
V_26 = F_317 ( V_9 , true ) ;
if ( V_26 )
goto V_700;
V_26 = F_334 ( V_9 ) ;
if ( V_26 )
goto V_701;
V_9 -> V_702 = true ;
goto V_53;
V_701:
F_317 ( V_9 , false ) ;
V_700:
F_60 ( V_9 , false ) ;
V_699:
F_319 ( V_9 , false ) ;
V_53:
return V_26 ;
}
static void F_303 ( struct V_8 * V_9 )
{
if ( V_9 -> V_702 ) {
F_339 ( V_9 ) ;
F_317 ( V_9 , false ) ;
F_50 ( V_9 ) ;
F_60 ( V_9 , false ) ;
F_319 ( V_9 , false ) ;
V_9 -> V_702 = false ;
}
}
static int
F_341 ( struct V_8 * V_9 , struct V_443 * V_703 )
{
unsigned char V_188 [ 6 ] = { V_704 ,
0 ,
0 ,
0 ,
V_144 ,
0 } ;
char * V_705 ;
int V_12 ;
V_705 = F_342 ( V_144 , V_315 ) ;
if ( ! V_705 ) {
V_12 = - V_316 ;
goto V_53;
}
V_12 = F_343 ( V_703 , V_188 , V_210 , V_705 ,
V_144 , NULL ,
F_11 ( 1000 ) , 3 , NULL , 0 , V_706 ) ;
if ( V_12 )
F_279 ( L_88 , V_19 , V_12 ) ;
F_172 ( V_705 ) ;
V_53:
return V_12 ;
}
static int F_344 ( struct V_8 * V_9 ,
enum V_1 V_414 )
{
unsigned char V_188 [ 6 ] = { V_707 } ;
struct V_708 V_709 ;
struct V_443 * V_703 ;
unsigned long V_89 ;
int V_12 ;
F_58 ( V_9 -> V_93 -> V_94 , V_89 ) ;
V_703 = V_9 -> V_463 ;
if ( V_703 ) {
V_12 = F_345 ( V_703 ) ;
if ( ! V_12 && ! F_346 ( V_703 ) ) {
V_12 = - V_710 ;
F_287 ( V_703 ) ;
}
} else {
V_12 = - V_710 ;
}
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
if ( V_12 )
return V_12 ;
V_9 -> V_93 -> V_711 = 1 ;
if ( V_9 -> V_665 ) {
V_12 = F_341 ( V_9 , V_703 ) ;
if ( V_12 )
goto V_53;
V_9 -> V_665 = false ;
}
V_188 [ 4 ] = V_414 << 4 ;
V_12 = F_343 ( V_703 , V_188 , V_243 , NULL , 0 , & V_709 ,
V_712 , 0 , NULL , 0 , V_706 ) ;
if ( V_12 ) {
F_347 ( V_713 , V_703 ,
L_120 ,
V_414 , V_12 ) ;
if ( F_348 ( V_12 ) & V_714 )
F_349 ( V_703 , NULL , & V_709 ) ;
}
if ( ! V_12 )
V_9 -> V_715 = V_414 ;
V_53:
F_287 ( V_703 ) ;
V_9 -> V_93 -> V_711 = 0 ;
return V_12 ;
}
static int F_350 ( struct V_8 * V_9 ,
enum V_6 V_716 ,
int V_717 )
{
int V_12 = 0 ;
if ( V_716 == V_9 -> V_6 )
return 0 ;
if ( V_716 == V_718 ) {
V_12 = F_74 ( V_9 ) ;
if ( ! V_12 )
F_75 ( V_9 ) ;
else
goto V_53;
}
else if ( ( V_716 == V_719 ) &&
( ! V_717 || ( V_717 &&
! V_9 -> V_501 ) ) ) {
V_12 = F_74 ( V_9 ) ;
if ( V_12 )
goto V_53;
F_210 ( V_9 , true ) ;
F_212 ( V_9 ) ;
}
V_53:
return V_12 ;
}
static void F_351 ( struct V_8 * V_9 )
{
if ( ! F_76 ( V_9 ) &&
V_9 -> V_527 & V_720 )
F_13 ( 2000 , 2100 ) ;
if ( F_352 ( V_9 ) && F_353 ( V_9 ) &&
! V_9 -> V_450 . V_452 ) {
F_317 ( V_9 , false ) ;
} else if ( ! F_220 ( V_9 ) ) {
F_318 ( V_9 -> V_18 , V_9 -> V_600 . V_601 , false ) ;
if ( ! F_76 ( V_9 ) ) {
F_308 ( V_9 , V_9 -> V_600 . V_602 ) ;
F_308 ( V_9 , V_9 -> V_600 . V_603 ) ;
}
}
}
static int F_354 ( struct V_8 * V_9 )
{
int V_12 = 0 ;
if ( F_352 ( V_9 ) && F_353 ( V_9 ) &&
! V_9 -> V_450 . V_452 ) {
V_12 = F_317 ( V_9 , true ) ;
} else if ( ! F_220 ( V_9 ) ) {
if ( ! V_12 && ! F_76 ( V_9 ) ) {
V_12 = F_309 ( V_9 , V_9 -> V_600 . V_602 ) ;
if ( V_12 )
goto V_721;
V_12 = F_309 ( V_9 , V_9 -> V_600 . V_603 ) ;
if ( V_12 )
goto V_722;
}
V_12 = F_318 ( V_9 -> V_18 , V_9 -> V_600 . V_601 , true ) ;
}
goto V_53;
V_722:
F_308 ( V_9 , V_9 -> V_600 . V_602 ) ;
V_721:
F_318 ( V_9 -> V_18 , V_9 -> V_600 . V_601 , false ) ;
V_53:
return V_12 ;
}
static void F_355 ( struct V_8 * V_9 )
{
if ( F_353 ( V_9 ) )
F_319 ( V_9 , false ) ;
}
static void F_356 ( struct V_8 * V_9 )
{
if ( F_353 ( V_9 ) )
F_319 ( V_9 , true ) ;
}
static int F_357 ( struct V_8 * V_9 , enum V_723 V_724 )
{
int V_12 = 0 ;
enum V_2 V_725 ;
enum V_1 V_726 ;
enum V_6 V_716 ;
V_9 -> V_484 = 1 ;
if ( ! F_358 ( V_724 ) ) {
V_725 = F_359 ( V_724 ) ?
V_9 -> V_727 : V_9 -> V_728 ;
V_726 = F_1 ( V_725 ) ;
V_716 = F_2 ( V_725 ) ;
} else {
V_726 = V_729 ;
V_716 = V_719 ;
}
F_66 ( V_9 , false ) ;
V_9 -> V_90 . V_98 = true ;
F_50 ( V_9 ) ;
if ( V_726 == V_730 &&
V_716 == V_731 ) {
goto V_732;
}
if ( ( V_726 == V_9 -> V_715 ) &&
( V_716 == V_9 -> V_6 ) )
goto V_733;
if ( ! F_220 ( V_9 ) || ! F_76 ( V_9 ) ) {
V_12 = - V_122 ;
goto V_733;
}
if ( F_359 ( V_724 ) ) {
if ( F_360 ( V_9 ) ) {
V_12 = F_248 ( V_9 ) ;
if ( V_12 )
goto V_733;
} else {
F_244 ( V_9 ) ;
}
}
if ( ( V_726 != V_9 -> V_715 ) &&
( ( F_359 ( V_724 ) && ! V_9 -> V_501 ) ||
! F_359 ( V_724 ) ) ) {
F_244 ( V_9 ) ;
V_12 = F_344 ( V_9 , V_726 ) ;
if ( V_12 )
goto V_733;
}
V_12 = F_350 ( V_9 , V_716 , 1 ) ;
if ( V_12 )
goto V_734;
F_351 ( V_9 ) ;
V_732:
V_12 = F_361 ( V_9 , V_724 ) ;
if ( V_12 )
goto V_735;
if ( ! F_76 ( V_9 ) )
F_60 ( V_9 , false ) ;
else
F_77 ( V_9 , false , true ) ;
V_9 -> V_90 . V_95 = V_104 ;
F_7 ( V_9 ) ;
F_355 ( V_9 ) ;
goto V_53;
V_735:
F_53 ( V_9 ) ;
F_354 ( V_9 ) ;
if ( F_62 ( V_9 ) && ! F_63 ( V_9 ) )
F_64 ( V_9 ) ;
else if ( F_353 ( V_9 ) )
F_198 ( V_9 ) ;
V_734:
if ( ! F_344 ( V_9 , V_730 ) )
F_244 ( V_9 ) ;
V_733:
F_53 ( V_9 ) ;
V_9 -> V_90 . V_98 = false ;
F_80 ( V_9 ) ;
V_53:
V_9 -> V_484 = 0 ;
return V_12 ;
}
static int F_362 ( struct V_8 * V_9 , enum V_723 V_724 )
{
int V_12 ;
enum V_6 V_736 ;
V_9 -> V_484 = 1 ;
V_736 = V_9 -> V_6 ;
F_356 ( V_9 ) ;
V_12 = F_60 ( V_9 , true ) ;
if ( V_12 )
goto V_53;
V_12 = F_4 ( V_9 ) ;
if ( V_12 )
goto V_737;
V_12 = F_354 ( V_9 ) ;
if ( V_12 )
goto V_737;
V_12 = F_363 ( V_9 , V_724 ) ;
if ( V_12 )
goto V_738;
if ( F_62 ( V_9 ) ) {
V_12 = F_63 ( V_9 ) ;
if ( ! V_12 )
F_64 ( V_9 ) ;
else
goto V_739;
} else if ( F_353 ( V_9 ) ) {
V_12 = F_198 ( V_9 ) ;
if ( V_12 || ! F_76 ( V_9 ) )
goto V_739;
}
if ( ! F_220 ( V_9 ) ) {
V_12 = F_344 ( V_9 , V_730 ) ;
if ( V_12 )
goto V_740;
}
F_248 ( V_9 ) ;
V_9 -> V_90 . V_98 = false ;
F_53 ( V_9 ) ;
F_80 ( V_9 ) ;
goto V_53;
V_740:
F_350 ( V_9 , V_736 , 0 ) ;
V_739:
F_361 ( V_9 , V_724 ) ;
V_738:
F_351 ( V_9 ) ;
V_737:
F_7 ( V_9 ) ;
F_50 ( V_9 ) ;
F_60 ( V_9 , false ) ;
V_53:
V_9 -> V_484 = 0 ;
return V_12 ;
}
int F_364 ( struct V_8 * V_9 )
{
int V_12 = 0 ;
if ( ! V_9 || ! V_9 -> V_702 )
return 0 ;
if ( ( F_1 ( V_9 -> V_728 ) ==
V_9 -> V_715 ) &&
( F_2 ( V_9 -> V_728 ) ==
V_9 -> V_6 ) )
goto V_53;
if ( F_365 ( V_9 -> V_18 ) ) {
V_12 = F_366 ( V_9 ) ;
if ( V_12 )
goto V_53;
}
V_12 = F_357 ( V_9 , V_741 ) ;
V_53:
if ( ! V_12 )
V_9 -> V_742 = true ;
return V_12 ;
}
int F_367 ( struct V_8 * V_9 )
{
if ( ! V_9 )
return - V_122 ;
if ( ! V_9 -> V_702 || F_365 ( V_9 -> V_18 ) )
return 0 ;
return F_362 ( V_9 , V_741 ) ;
}
int F_368 ( struct V_8 * V_9 )
{
if ( ! V_9 )
return - V_122 ;
if ( ! V_9 -> V_702 )
return 0 ;
return F_357 ( V_9 , V_743 ) ;
}
int F_366 ( struct V_8 * V_9 )
{
if ( ! V_9 )
return - V_122 ;
if ( ! V_9 -> V_702 )
return 0 ;
return F_362 ( V_9 , V_743 ) ;
}
int F_369 ( struct V_8 * V_9 )
{
return 0 ;
}
int F_370 ( struct V_8 * V_9 )
{
int V_12 = 0 ;
if ( F_352 ( V_9 ) && F_353 ( V_9 ) )
goto V_53;
if ( F_365 ( V_9 -> V_18 ) ) {
V_12 = F_366 ( V_9 ) ;
if ( V_12 )
goto V_53;
}
V_12 = F_357 ( V_9 , V_744 ) ;
V_53:
if ( V_12 )
F_6 ( V_9 -> V_18 , L_121 , V_19 , V_12 ) ;
return 0 ;
}
void F_371 ( struct V_8 * V_9 )
{
F_372 ( V_9 -> V_93 ) ;
F_129 ( V_9 , V_9 -> V_30 ) ;
F_210 ( V_9 , true ) ;
F_90 ( V_9 ) ;
F_303 ( V_9 ) ;
}
void F_373 ( struct V_8 * V_9 )
{
F_374 ( V_9 -> V_93 ) ;
}
static int F_375 ( struct V_8 * V_9 )
{
if ( V_9 -> V_164 & V_745 ) {
if ( ! F_376 ( V_9 -> V_18 , F_377 ( 64 ) ) )
return 0 ;
}
return F_376 ( V_9 -> V_18 , F_377 ( 32 ) ) ;
}
int F_378 ( struct V_115 * V_18 , struct V_8 * * V_746 )
{
struct V_253 * V_93 ;
struct V_8 * V_9 ;
int V_26 = 0 ;
if ( ! V_18 ) {
F_6 ( V_18 ,
L_122 ) ;
V_26 = - V_710 ;
goto V_747;
}
V_93 = F_379 ( & V_748 ,
sizeof( struct V_8 ) ) ;
if ( ! V_93 ) {
F_6 ( V_18 , L_123 ) ;
V_26 = - V_316 ;
goto V_747;
}
V_9 = F_142 ( V_93 ) ;
V_9 -> V_93 = V_93 ;
V_9 -> V_18 = V_18 ;
* V_746 = V_9 ;
V_747:
return V_26 ;
}
static int F_380 ( struct V_8 * V_9 , bool V_749 )
{
int V_12 = 0 ;
struct V_689 * V_690 ;
struct V_691 * V_692 = & V_9 -> V_693 ;
if ( ! V_692 || F_324 ( V_692 ) )
goto V_53;
V_12 = F_381 ( V_9 , V_749 , V_395 ) ;
if ( V_12 )
return V_12 ;
F_326 (clki, head, list) {
if ( ! F_327 ( V_690 -> V_694 ) ) {
if ( V_749 && V_690 -> V_695 ) {
if ( V_690 -> V_696 == V_690 -> V_695 )
continue;
V_12 = F_332 ( V_690 -> V_694 , V_690 -> V_695 ) ;
if ( V_12 ) {
F_6 ( V_9 -> V_18 , L_117 ,
V_19 , V_690 -> V_126 ,
V_690 -> V_695 , V_12 ) ;
break;
}
V_690 -> V_696 = V_690 -> V_695 ;
} else if ( ! V_749 && V_690 -> V_750 ) {
if ( V_690 -> V_696 == V_690 -> V_750 )
continue;
V_12 = F_332 ( V_690 -> V_694 , V_690 -> V_750 ) ;
if ( V_12 ) {
F_6 ( V_9 -> V_18 , L_117 ,
V_19 , V_690 -> V_126 ,
V_690 -> V_750 , V_12 ) ;
break;
}
V_690 -> V_696 = V_690 -> V_750 ;
}
}
F_153 ( V_9 -> V_18 , L_118 , V_19 ,
V_690 -> V_126 , F_333 ( V_690 -> V_694 ) ) ;
}
V_12 = F_381 ( V_9 , V_749 , V_397 ) ;
V_53:
return V_12 ;
}
static int F_382 ( struct V_115 * V_18 ,
unsigned long * V_751 , T_1 V_89 )
{
int V_26 = 0 ;
struct V_8 * V_9 = F_82 ( V_18 ) ;
bool V_752 = false ;
unsigned long V_753 ;
if ( ! F_51 ( V_9 ) )
return - V_122 ;
F_58 ( V_9 -> V_93 -> V_94 , V_753 ) ;
if ( F_68 ( V_9 ) ) {
F_59 ( V_9 -> V_93 -> V_94 , V_753 ) ;
return 0 ;
}
if ( F_67 ( V_9 ) &&
( V_9 -> V_90 . V_95 != V_96 ) ) {
if ( F_70 ( & V_9 -> V_90 . V_92 ) ) {
V_9 -> V_90 . V_101 ++ ;
V_752 = true ;
V_9 -> V_90 . V_95 = V_96 ;
} else {
F_59 ( V_9 -> V_93 -> V_94 , V_753 ) ;
return 0 ;
}
}
F_59 ( V_9 -> V_93 -> V_94 , V_753 ) ;
if ( * V_751 == V_754 )
V_26 = F_380 ( V_9 , true ) ;
else if ( * V_751 == 0 )
V_26 = F_380 ( V_9 , false ) ;
F_58 ( V_9 -> V_93 -> V_94 , V_753 ) ;
if ( V_752 )
F_78 ( V_9 ) ;
F_59 ( V_9 -> V_93 -> V_94 , V_753 ) ;
return V_26 ;
}
static int F_383 ( struct V_115 * V_18 ,
struct V_755 * V_756 )
{
struct V_8 * V_9 = F_82 ( V_18 ) ;
struct V_132 * V_133 = & V_9 -> V_85 ;
unsigned long V_89 ;
if ( ! F_51 ( V_9 ) )
return - V_122 ;
memset ( V_756 , 0 , sizeof( * V_756 ) ) ;
F_58 ( V_9 -> V_93 -> V_94 , V_89 ) ;
if ( ! V_133 -> V_86 )
goto V_757;
if ( V_133 -> V_130 )
V_133 -> V_134 += F_96 ( F_97 ( F_94 () ,
V_133 -> V_131 ) ) ;
V_756 -> V_758 = F_384 ( ( long ) V_28 -
( long ) V_133 -> V_86 ) ;
V_756 -> V_759 = V_133 -> V_134 ;
V_757:
V_133 -> V_86 = V_28 ;
V_133 -> V_134 = 0 ;
if ( V_9 -> V_59 ) {
V_133 -> V_131 = F_94 () ;
V_133 -> V_130 = true ;
} else {
V_133 -> V_131 = 0 ;
V_133 -> V_130 = false ;
}
F_59 ( V_9 -> V_93 -> V_94 , V_89 ) ;
return 0 ;
}
int F_385 ( struct V_8 * V_9 , void T_9 * V_760 , unsigned int V_14 )
{
int V_26 ;
struct V_253 * V_93 = V_9 -> V_93 ;
struct V_115 * V_18 = V_9 -> V_18 ;
if ( ! V_760 ) {
F_6 ( V_9 -> V_18 ,
L_124 ) ;
V_26 = - V_710 ;
goto V_747;
}
V_9 -> V_760 = V_760 ;
V_9 -> V_14 = V_14 ;
V_26 = F_340 ( V_9 ) ;
if ( V_26 )
goto V_747;
F_107 ( V_9 ) ;
V_9 -> V_31 = F_17 ( V_9 ) ;
if ( ( V_9 -> V_31 != V_32 ) &&
( V_9 -> V_31 != V_34 ) &&
( V_9 -> V_31 != V_35 ) &&
( V_9 -> V_31 != V_37 ) )
F_6 ( V_9 -> V_18 , L_125 ,
V_9 -> V_31 ) ;
V_9 -> V_30 = F_16 ( V_9 ) ;
V_26 = F_375 ( V_9 ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_126 ) ;
goto V_761;
}
V_26 = F_179 ( V_9 ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_127 ) ;
goto V_761;
}
F_182 ( V_9 ) ;
V_93 -> V_762 = V_9 -> V_11 ;
V_93 -> V_763 = V_9 -> V_11 ;
V_93 -> V_764 = V_765 ;
V_93 -> V_766 = V_767 ;
V_93 -> V_768 = V_769 ;
V_93 -> V_770 = V_93 -> V_771 ;
V_93 -> V_772 = V_234 ;
V_9 -> V_406 . V_408 = false ;
F_386 ( & V_9 -> V_553 ) ;
F_386 ( & V_9 -> V_570 ) ;
F_87 ( & V_9 -> V_526 , F_257 ) ;
F_87 ( & V_9 -> V_485 , F_251 ) ;
F_387 ( & V_9 -> V_182 ) ;
F_387 ( & V_9 -> V_147 . V_290 ) ;
F_386 ( & V_9 -> V_147 . V_278 ) ;
F_85 ( V_9 ) ;
F_29 ( V_9 , F_12 ( V_9 , V_561 ) ,
V_561 ) ;
F_29 ( V_9 , 0 , V_201 ) ;
F_388 () ;
V_26 = F_389 ( V_18 , V_14 , V_15 , V_16 , V_17 , V_9 ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_128 ) ;
goto V_773;
} else {
V_9 -> V_13 = true ;
}
V_26 = F_390 ( V_93 , V_9 -> V_18 ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_129 ) ;
goto V_773;
}
V_26 = F_211 ( V_9 ) ;
if ( V_26 ) {
F_6 ( V_9 -> V_18 , L_130 ) ;
goto V_774;
}
if ( F_51 ( V_9 ) ) {
V_9 -> V_84 = F_391 ( V_18 , & V_775 ,
L_131 , NULL ) ;
if ( F_285 ( V_9 -> V_84 ) ) {
F_6 ( V_9 -> V_18 , L_132 ,
F_286 ( V_9 -> V_84 ) ) ;
V_26 = F_286 ( V_9 -> V_84 ) ;
goto V_774;
}
F_50 ( V_9 ) ;
}
F_252 ( V_18 ) ;
F_301 ( V_9 ) ;
F_392 ( F_304 , V_9 ) ;
return 0 ;
V_774:
F_372 ( V_9 -> V_93 ) ;
V_773:
F_90 ( V_9 ) ;
V_761:
V_9 -> V_13 = false ;
F_303 ( V_9 ) ;
V_747:
return V_26 ;
}

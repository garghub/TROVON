static inline bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 . V_4 == V_5 ;
}
static inline void F_2 ( struct V_6 * V_7 , T_1 V_8 ,
void * V_9 )
{
T_1 V_10 = V_8 & V_7 -> V_11 . V_12 ;
memcpy ( V_9 , F_3 ( & V_7 -> V_11 , V_10 ) , sizeof( struct V_13 ) ) ;
}
static inline void F_4 ( struct V_14 * V_15 ,
struct V_6 * V_7 , T_1 V_8 )
{
F_2 ( V_7 , V_8 , & V_7 -> V_16 ) ;
V_7 -> V_17 = F_5 ( V_7 -> V_16 . V_18 ) ;
V_7 -> V_19 = F_6 ( V_7 -> V_16 . V_20 ) ;
V_15 -> V_21 . V_22 ++ ;
}
static inline void F_7 ( struct V_6 * V_7 , T_1 V_8 )
{
F_2 ( V_7 , V_8 , V_7 -> V_23 ) ;
V_7 -> V_24 = 0 ;
}
static inline void F_8 ( struct V_6 * V_7 , T_1 V_8 , int V_25 )
{
T_2 V_26 = ( V_8 >> V_7 -> V_11 . V_27 ) & 1 ;
T_1 V_28 = 1 << V_7 -> V_11 . V_27 ;
T_1 V_10 = V_8 & V_7 -> V_11 . V_12 ;
T_1 V_29 = F_9 ( T_1 , V_28 , V_10 + V_25 ) ;
for (; V_10 < V_29 ; V_10 ++ , V_25 -- ) {
struct V_13 * V_30 = F_3 ( & V_7 -> V_11 , V_10 ) ;
V_30 -> V_26 = V_26 ;
}
if ( F_10 ( V_10 == V_28 ) ) {
V_26 = ! V_26 ;
for ( V_10 = 0 ; V_10 < V_25 ; V_10 ++ ) {
struct V_13 * V_30 = F_3 ( & V_7 -> V_11 , V_10 ) ;
V_30 -> V_26 = V_26 ;
}
}
}
static inline void F_11 ( struct V_14 * V_15 ,
struct V_6 * V_7 , T_1 V_8 )
{
T_3 V_31 ;
V_7 -> V_16 . V_18 = V_7 -> V_23 [ V_7 -> V_24 ] . V_18 ;
V_7 -> V_16 . V_32 = V_7 -> V_23 [ V_7 -> V_24 ] . V_33 ;
V_7 -> V_16 . V_26 &= 0xf0 ;
V_7 -> V_16 . V_26 |= 0x01 & ( V_8 >> V_7 -> V_11 . V_27 ) ;
V_7 -> V_16 . V_20 = F_12 ( V_7 -> V_19 ) ;
V_31 =
V_15 -> V_34 == V_35 ?
F_13 ( & V_7 -> V_16 ) : 1 ;
V_7 -> V_19 =
( V_7 -> V_19 + V_31 ) & V_15 -> V_11 . V_12 ;
}
static inline void F_14 ( struct V_14 * V_15 ,
struct V_6 * V_7 , T_1 V_8 )
{
F_11 ( V_15 , V_7 , V_8 ) ;
V_7 -> V_16 . V_36 = 0 ;
V_7 -> V_16 . V_37 = 0 ;
}
static inline T_1 F_15 ( struct V_14 * V_15 ,
struct V_6 * V_7 ,
int V_38 ,
int V_39 )
{
T_1 V_8 = V_7 -> V_11 . V_40 + V_38 ;
T_1 V_41 ;
T_1 V_42 ;
V_41 = F_9 ( T_1 , V_7 -> V_17 , V_39 ) ;
for ( V_42 = V_38 ; V_42 < V_41 ;
V_42 ++ , V_7 -> V_24 ++ , V_8 ++ ) {
if ( V_7 -> V_24 == V_43 )
F_7 ( V_7 , V_8 ) ;
F_14 ( V_15 , V_7 , V_8 ) ;
V_15 -> V_44 ( V_15 , & V_7 -> V_16 ) ;
}
F_8 ( V_7 , V_7 -> V_11 . V_40 , V_8 - V_7 -> V_11 . V_40 ) ;
V_7 -> V_11 . V_40 = V_8 ;
V_7 -> V_17 -= V_41 ;
V_15 -> V_21 . V_45 += V_41 ;
return V_41 ;
}
static inline T_1 F_16 ( struct V_14 * V_15 ,
struct V_6 * V_7 ,
int V_39 )
{
F_4 ( V_15 , V_7 , V_7 -> V_11 . V_40 ) ;
F_7 ( V_7 , V_7 -> V_11 . V_40 + 1 ) ;
F_11 ( V_15 , V_7 , V_7 -> V_11 . V_40 ) ;
V_15 -> V_44 ( V_15 , & V_7 -> V_16 ) ;
V_7 -> V_24 ++ ;
return F_15 ( V_15 , V_7 , 1 , V_39 ) - 1 ;
}
void F_17 ( struct V_46 * V_47 , bool V_48 )
{
bool V_49 ;
if ( ! F_18 ( V_47 -> V_50 , V_51 ) )
return;
F_19 ( & V_47 -> V_52 ) ;
if ( V_47 -> V_53 . V_54 == V_48 )
goto V_55;
V_49 = F_20 ( V_56 , & V_47 -> V_57 ) ;
if ( V_49 )
F_21 ( V_47 -> V_58 ) ;
V_47 -> V_53 . V_54 = V_48 ;
if ( V_49 )
F_22 ( V_47 -> V_58 ) ;
V_55:
F_23 ( & V_47 -> V_52 ) ;
}
static inline bool F_24 ( struct V_14 * V_15 ,
struct V_59 * V_60 )
{
struct V_61 * V_62 = & V_15 -> V_63 ;
T_1 V_64 = ( V_62 -> V_65 + 1 ) & ( V_66 - 1 ) ;
if ( V_64 == V_62 -> V_67 ) {
V_15 -> V_21 . V_68 ++ ;
return false ;
}
V_62 -> V_63 [ V_62 -> V_65 ] = * V_60 ;
V_62 -> V_65 = V_64 ;
return true ;
}
static inline bool F_25 ( struct V_14 * V_15 ,
struct V_59 * V_60 )
{
struct V_61 * V_62 = & V_15 -> V_63 ;
if ( F_10 ( V_62 -> V_67 == V_62 -> V_65 ) ) {
V_15 -> V_21 . V_69 ++ ;
return false ;
}
if ( F_26 ( V_62 -> V_63 [ V_62 -> V_67 ] . V_70 ) != 1 ) {
V_15 -> V_21 . V_71 ++ ;
return false ;
}
* V_60 = V_62 -> V_63 [ V_62 -> V_67 ] ;
V_62 -> V_67 = ( V_62 -> V_67 + 1 ) & ( V_66 - 1 ) ;
V_15 -> V_21 . V_72 ++ ;
F_27 ( V_15 -> V_73 , V_60 -> V_74 ,
F_28 ( V_15 ) ,
V_75 ) ;
return true ;
}
static inline int F_29 ( struct V_14 * V_15 ,
struct V_59 * V_60 )
{
struct V_70 * V_70 ;
if ( F_25 ( V_15 , V_60 ) )
return 0 ;
V_70 = F_30 ( V_15 -> V_76 . V_77 ) ;
if ( F_10 ( ! V_70 ) )
return - V_78 ;
V_60 -> V_70 = V_70 ;
V_60 -> V_74 = F_31 ( V_15 -> V_73 , V_70 , 0 ,
F_28 ( V_15 ) , V_15 -> V_76 . V_79 ) ;
if ( F_10 ( F_32 ( V_15 -> V_73 , V_60 -> V_74 ) ) ) {
F_33 ( V_70 ) ;
return - V_78 ;
}
return 0 ;
}
void F_34 ( struct V_14 * V_15 , struct V_59 * V_60 ,
bool V_80 )
{
if ( F_35 ( V_80 ) && F_24 ( V_15 , V_60 ) )
return;
F_36 ( V_15 -> V_73 , V_60 -> V_74 , F_28 ( V_15 ) ,
V_15 -> V_76 . V_79 ) ;
F_33 ( V_60 -> V_70 ) ;
}
int F_37 ( struct V_14 * V_15 , struct V_81 * V_82 , T_3 V_83 )
{
struct V_59 * V_84 = & V_15 -> V_60 [ V_83 ] ;
if ( F_10 ( F_29 ( V_15 , V_84 ) ) )
return - V_78 ;
V_82 -> V_9 . V_74 = F_38 ( V_84 -> V_74 + V_85 ) ;
return 0 ;
}
void F_39 ( struct V_14 * V_15 , T_3 V_83 )
{
struct V_59 * V_84 = & V_15 -> V_60 [ V_83 ] ;
F_34 ( V_15 , V_84 , true ) ;
}
static inline int F_40 ( struct V_14 * V_15 )
{
return V_15 -> V_86 >> V_87 ;
}
static inline void F_41 ( struct V_14 * V_15 ,
struct V_88 * V_89 ,
struct V_90 * V_91 ,
T_1 V_92 , T_1 V_93 ,
T_1 V_94 )
{
unsigned int V_95 = F_42 ( V_94 , V_15 -> V_96 ) ;
F_43 ( V_15 -> V_73 ,
V_91 -> V_97 . V_60 [ V_92 ] . V_74 + V_93 ,
V_94 , V_75 ) ;
V_91 -> V_98 [ V_92 ] ++ ;
F_44 ( V_89 , F_45 ( V_89 ) -> V_99 ,
V_91 -> V_97 . V_60 [ V_92 ] . V_70 , V_93 ,
V_94 , V_95 ) ;
}
static inline void
F_46 ( struct V_100 * V_73 ,
struct V_88 * V_89 ,
struct V_90 * V_91 ,
T_1 V_92 , T_1 V_101 ,
T_1 V_102 )
{
T_3 V_103 = F_9 ( T_1 , V_102 , V_104 - V_101 ) ;
struct V_59 * V_60 = & V_91 -> V_97 . V_60 [ V_92 ] ;
unsigned int V_94 ;
V_94 = F_42 ( V_103 , sizeof( long ) ) ;
F_43 ( V_73 , V_60 -> V_74 + V_101 , V_94 ,
V_75 ) ;
F_47 ( V_89 , 0 ,
F_48 ( V_60 -> V_70 ) + V_101 ,
V_94 ) ;
if ( F_10 ( V_101 + V_102 > V_104 ) ) {
V_60 ++ ;
V_103 = V_94 ;
V_94 = F_42 ( V_102 - V_103 , sizeof( long ) ) ;
F_43 ( V_73 , V_60 -> V_74 , V_94 ,
V_75 ) ;
F_47 ( V_89 , V_103 ,
F_48 ( V_60 -> V_70 ) ,
V_94 ) ;
}
}
static inline void F_49 ( struct V_14 * V_15 , T_3 V_83 )
{
struct V_90 * V_91 = & V_15 -> V_105 . V_106 [ V_83 ] ;
struct V_107 * V_108 = & V_15 -> V_109 -> V_110 ;
struct V_111 * V_11 = & V_108 -> V_11 ;
struct V_112 * V_82 ;
T_2 V_113 = F_50 ( sizeof( * V_82 ) , V_114 ) ;
T_3 V_115 ;
while ( ( V_115 = ( V_108 -> V_116 & V_11 -> V_12 ) ) > V_108 -> V_117 ) {
V_108 -> V_118 . V_119 [ V_115 ] . V_120 = V_121 ;
V_108 -> V_118 . V_119 [ V_115 ] . V_113 = 1 ;
F_51 ( V_108 , false ) ;
}
V_82 = F_52 ( V_11 , V_115 ) ;
memcpy ( V_82 , & V_91 -> V_97 . V_82 , sizeof( * V_82 ) ) ;
V_82 -> V_122 . V_123 =
F_53 ( ( V_108 -> V_116 << V_124 ) |
V_125 ) ;
V_108 -> V_118 . V_119 [ V_115 ] . V_120 = V_125 ;
V_108 -> V_118 . V_119 [ V_115 ] . V_113 = V_113 ;
V_108 -> V_116 += V_113 ;
F_54 ( V_108 , & V_82 -> V_122 , 0 ) ;
}
static int F_55 ( struct V_14 * V_15 ,
struct V_81 * V_82 ,
T_3 V_83 )
{
struct V_90 * V_91 = & V_15 -> V_105 . V_106 [ V_83 ] ;
T_4 V_126 = ( T_4 ) F_56 ( V_15 , V_83 ) << V_127 ;
int V_128 = F_40 ( V_15 ) ;
int V_129 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_130 ; V_42 ++ ) {
struct V_59 * V_60 = & V_91 -> V_97 . V_60 [ V_42 ] ;
V_129 = F_29 ( V_15 , V_60 ) ;
if ( F_10 ( V_129 ) )
goto V_131;
V_91 -> V_97 . V_132 [ V_42 ] = F_38 ( V_60 -> V_74 | V_133 ) ;
F_57 ( V_60 -> V_70 , V_128 ) ;
V_91 -> V_98 [ V_42 ] = 0 ;
}
V_91 -> V_134 = 0 ;
V_82 -> V_9 . V_74 = F_38 ( V_126 ) ;
return 0 ;
V_131:
while ( -- V_42 >= 0 ) {
struct V_59 * V_60 = & V_91 -> V_97 . V_60 [ V_42 ] ;
F_58 ( V_60 -> V_70 , V_128 ) ;
F_34 ( V_15 , V_60 , true ) ;
}
return V_129 ;
}
void F_59 ( struct V_14 * V_15 , struct V_90 * V_91 )
{
int V_128 = F_40 ( V_15 ) ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_130 ; V_42 ++ ) {
struct V_59 * V_60 = & V_91 -> V_97 . V_60 [ V_42 ] ;
F_58 ( V_60 -> V_70 , V_128 - V_91 -> V_98 [ V_42 ] ) ;
F_34 ( V_15 , V_60 , true ) ;
}
}
void F_60 ( struct V_14 * V_15 )
{
struct V_135 * V_11 = & V_15 -> V_11 ;
struct V_81 * V_82 = F_61 ( V_11 , V_11 -> V_67 ) ;
F_62 ( V_136 , & V_15 -> V_57 ) ;
if ( F_10 ( ! F_20 ( V_137 , & V_15 -> V_57 ) ) ) {
F_59 ( V_15 , & V_15 -> V_105 . V_106 [ V_11 -> V_67 ] ) ;
return;
}
F_63 ( V_11 , F_6 ( V_82 -> V_138 . V_139 ) ) ;
F_64 () ;
F_65 ( V_11 ) ;
}
int F_66 ( struct V_14 * V_15 , struct V_81 * V_82 , T_3 V_83 )
{
int V_129 ;
V_129 = F_55 ( V_15 , V_82 , V_83 ) ;
if ( F_10 ( V_129 ) )
return V_129 ;
F_67 ( V_136 , & V_15 -> V_57 ) ;
F_49 ( V_15 , V_83 ) ;
return - V_140 ;
}
void F_68 ( struct V_14 * V_15 , T_3 V_83 )
{
struct V_90 * V_91 = & V_15 -> V_105 . V_106 [ V_83 ] ;
F_59 ( V_15 , V_91 ) ;
}
bool F_69 ( struct V_14 * V_15 )
{
struct V_135 * V_11 = & V_15 -> V_11 ;
if ( F_10 ( F_70 ( V_15 ) ) )
return false ;
while ( ! F_71 ( V_11 ) ) {
struct V_81 * V_82 = F_61 ( V_11 , V_11 -> V_67 ) ;
int V_129 ;
V_129 = V_15 -> V_141 ( V_15 , V_82 , V_11 -> V_67 ) ;
if ( V_129 == - V_140 )
return true ;
if ( F_10 ( V_129 ) ) {
V_15 -> V_21 . V_142 ++ ;
break;
}
F_63 ( V_11 , F_6 ( V_82 -> V_138 . V_139 ) ) ;
}
F_64 () ;
F_65 ( V_11 ) ;
return ! F_71 ( V_11 ) ;
}
static void F_72 ( struct V_88 * V_89 , struct V_13 * V_30 ,
T_1 V_143 )
{
struct V_144 * V_145 = (struct V_144 * ) ( V_89 -> V_9 ) ;
struct V_146 * V_147 ;
struct V_148 * V_149 ;
struct V_150 * V_151 ;
int V_152 = 0 ;
T_5 V_153 ;
T_3 V_154 ;
T_2 V_155 = F_73 ( V_30 ) ;
int V_156 = ( ( V_157 == V_155 ) ||
( V_158 == V_155 ) ) ;
V_89 -> V_159 = V_160 ;
V_153 = F_74 ( V_89 , V_145 -> V_161 , & V_152 ) ;
V_147 = (struct V_146 * ) ( V_89 -> V_9 + V_152 ) ;
V_149 = (struct V_148 * ) ( V_89 -> V_9 + V_152 ) ;
V_154 = V_143 - V_152 ;
if ( V_153 == F_75 ( V_162 ) ) {
V_151 = (struct V_150 * ) ( V_89 -> V_9 + V_152 +
sizeof( struct V_146 ) ) ;
V_149 = NULL ;
F_45 ( V_89 ) -> V_163 = V_164 ;
} else {
V_151 = (struct V_150 * ) ( V_89 -> V_9 + V_152 +
sizeof( struct V_148 ) ) ;
V_147 = NULL ;
F_45 ( V_89 ) -> V_163 = V_165 ;
}
if ( F_76 ( V_30 ) )
V_151 -> V_166 = 1 ;
if ( V_156 ) {
V_151 -> V_167 = 1 ;
V_151 -> V_168 = V_30 -> V_169 ;
V_151 -> V_170 = V_30 -> V_171 ;
}
if ( V_147 ) {
V_147 -> V_172 = V_30 -> V_173 ;
V_147 -> V_154 = F_12 ( V_154 ) ;
V_147 -> V_174 = 0 ;
V_147 -> V_174 = F_77 ( ( unsigned char * ) V_147 ,
V_147 -> V_175 ) ;
} else {
V_149 -> V_176 = V_30 -> V_173 ;
V_149 -> V_177 = F_12 ( V_154 -
sizeof( struct V_148 ) ) ;
}
}
static inline void F_78 ( struct V_13 * V_30 ,
struct V_88 * V_89 )
{
T_2 V_178 = V_30 -> V_36 ;
int V_179 = ( V_178 & V_180 ) ? V_181 :
( V_178 & V_182 ) ? V_183 :
V_184 ;
F_79 ( V_89 , F_5 ( V_30 -> V_37 ) , V_179 ) ;
}
static inline bool F_80 ( struct V_88 * V_89 )
{
T_5 V_185 = ( (struct V_144 * ) V_89 -> V_9 ) -> V_161 ;
return ( V_185 == F_75 ( V_162 ) || V_185 == F_75 ( V_186 ) ) ;
}
static inline void F_81 ( struct V_187 * V_58 ,
struct V_13 * V_30 ,
struct V_14 * V_15 ,
struct V_88 * V_89 ,
bool V_188 )
{
if ( F_10 ( ! ( V_58 -> V_189 & V_190 ) ) )
goto V_191;
if ( V_188 ) {
V_89 -> V_192 = V_193 ;
return;
}
if ( F_80 ( V_89 ) ) {
V_89 -> V_192 = V_194 ;
V_89 -> V_195 = F_82 ( ( V_196 V_197 ) V_30 -> V_32 ) ;
V_15 -> V_21 . V_198 ++ ;
return;
}
if ( F_35 ( ( V_30 -> V_199 & V_200 ) &&
( V_30 -> V_199 & V_201 ) ) ) {
V_89 -> V_192 = V_193 ;
if ( F_83 ( V_30 ) ) {
V_89 -> V_202 = 1 ;
V_89 -> V_203 = 1 ;
V_15 -> V_21 . V_204 ++ ;
}
return;
}
V_191:
V_89 -> V_192 = V_205 ;
V_15 -> V_21 . V_191 ++ ;
}
static inline void F_84 ( struct V_13 * V_30 ,
T_1 V_143 ,
struct V_14 * V_15 ,
struct V_88 * V_89 )
{
struct V_187 * V_58 = V_15 -> V_58 ;
struct V_1 * V_2 = V_15 -> V_2 ;
int V_206 ;
V_206 = F_5 ( V_30 -> V_207 ) >> 24 ;
if ( V_206 > 1 ) {
F_72 ( V_89 , V_30 , V_143 ) ;
F_45 ( V_89 ) -> V_208 = F_50 ( V_143 , V_206 ) ;
V_15 -> V_21 . V_209 ++ ;
V_15 -> V_21 . V_210 += V_143 ;
}
if ( F_10 ( F_1 ( V_2 ) ) )
F_85 ( V_2 , F_86 ( V_30 ) , F_87 ( V_89 ) ) ;
F_88 ( V_89 , V_15 -> V_83 ) ;
if ( F_35 ( V_58 -> V_189 & V_211 ) )
F_78 ( V_30 , V_89 ) ;
if ( F_89 ( V_30 ) )
F_90 ( V_89 , F_75 ( V_212 ) ,
F_6 ( V_30 -> V_213 ) ) ;
V_89 -> V_214 = F_5 ( V_30 -> V_215 ) & V_216 ;
F_81 ( V_58 , V_30 , V_15 , V_89 , ! ! V_206 ) ;
V_89 -> V_217 = F_91 ( V_89 , V_58 ) ;
}
static inline void F_92 ( struct V_14 * V_15 ,
struct V_13 * V_30 ,
T_1 V_143 ,
struct V_88 * V_89 )
{
V_15 -> V_21 . V_218 ++ ;
V_15 -> V_21 . V_219 += V_143 ;
F_84 ( V_30 , V_143 , V_15 , V_89 ) ;
}
static inline void F_93 ( struct V_107 * V_108 )
{
struct V_111 * V_11 = & V_108 -> V_11 ;
struct V_220 * V_82 ;
T_3 V_115 = ( V_108 -> V_116 - V_221 ) & V_11 -> V_12 ;
V_82 = F_52 ( V_11 , V_115 ) ;
V_82 -> V_122 . V_222 = V_223 ;
F_54 ( V_108 , & V_82 -> V_122 , 0 ) ;
}
static inline void F_94 ( struct V_14 * V_15 ,
struct V_59 * V_84 ,
unsigned int V_224 ,
int V_94 )
{
struct V_107 * V_108 = & V_15 -> V_109 -> V_225 ;
struct V_111 * V_11 = & V_108 -> V_11 ;
T_3 V_115 = V_108 -> V_116 & V_11 -> V_12 ;
struct V_220 * V_82 = F_52 ( V_11 , V_115 ) ;
struct V_226 * V_91 = & V_108 -> V_118 . V_227 . V_228 [ V_115 ] ;
struct V_229 * V_230 = & V_82 -> V_122 ;
struct V_231 * V_232 = & V_82 -> V_145 ;
struct V_233 * V_234 ;
T_6 V_235 = V_84 -> V_74 + V_224 + V_236 ;
unsigned int V_237 = V_94 - V_236 ;
void * V_9 = F_48 ( V_84 -> V_70 ) + V_224 ;
if ( F_10 ( ! F_95 ( V_108 , V_221 ) ) ) {
if ( V_108 -> V_118 . V_227 . V_238 ) {
F_93 ( V_108 ) ;
V_108 -> V_118 . V_227 . V_238 = false ;
}
V_15 -> V_21 . V_239 ++ ;
F_34 ( V_15 , V_84 , true ) ;
return;
}
F_27 ( V_108 -> V_73 , V_235 , V_237 ,
V_240 ) ;
memset ( V_82 , 0 , sizeof( * V_82 ) ) ;
memcpy ( V_232 -> V_241 , V_9 , V_236 ) ;
V_232 -> V_242 = F_12 ( V_236 ) ;
V_234 = (struct V_233 * ) V_230 + ( V_243 - 1 ) ;
V_234 -> V_74 = F_38 ( V_235 ) ;
V_234 -> V_244 = F_53 ( V_237 ) ;
V_234 -> V_245 = V_108 -> V_246 ;
V_230 -> V_123 = F_53 ( ( V_108 -> V_116 << 8 ) | V_247 ) ;
V_230 -> V_248 = F_53 ( ( V_108 -> V_249 << 8 ) | V_243 ) ;
V_108 -> V_118 . V_227 . V_84 [ V_115 ] = * V_84 ;
V_91 -> V_120 = V_247 ;
V_91 -> V_113 = V_221 ;
V_108 -> V_116 += V_221 ;
V_108 -> V_118 . V_227 . V_238 = true ;
V_15 -> V_21 . V_250 ++ ;
}
static inline bool F_96 ( struct V_14 * V_15 ,
const struct V_251 * V_252 ,
struct V_59 * V_84 ,
void * V_9 , T_3 V_94 )
{
struct V_253 V_227 ;
T_1 V_254 ;
if ( ! V_252 )
return false ;
V_227 . V_9 = V_9 ;
V_227 . V_255 = V_227 . V_9 + V_94 ;
V_254 = F_97 ( V_252 , & V_227 ) ;
switch ( V_254 ) {
case V_256 :
return false ;
case V_257 :
F_94 ( V_15 , V_84 , V_85 , V_94 ) ;
return true ;
default:
F_98 ( V_254 ) ;
case V_258 :
case V_259 :
V_15 -> V_21 . V_260 ++ ;
F_34 ( V_15 , V_84 , true ) ;
return true ;
}
}
static inline
struct V_88 * F_99 ( struct V_14 * V_15 , struct V_13 * V_30 ,
T_3 V_20 , T_1 V_143 )
{
struct V_251 * V_261 = F_100 ( V_15 -> V_261 ) ;
struct V_59 * V_84 ;
struct V_88 * V_89 ;
void * V_262 , * V_9 ;
V_84 = & V_15 -> V_60 [ V_20 ] ;
V_262 = F_48 ( V_84 -> V_70 ) ;
V_9 = V_262 + V_85 ;
F_101 ( V_15 -> V_73 ,
V_84 -> V_74 ,
V_85 ,
V_15 -> V_76 . V_263 ,
V_75 ) ;
F_102 ( V_9 ) ;
if ( F_10 ( ( V_30 -> V_26 >> 4 ) != V_264 ) ) {
V_15 -> V_21 . V_265 ++ ;
F_34 ( V_15 , V_84 , true ) ;
return NULL ;
}
if ( F_96 ( V_15 , V_261 , V_84 , V_9 , V_143 ) )
return NULL ;
V_89 = F_103 ( V_262 , F_28 ( V_15 ) ) ;
if ( F_10 ( ! V_89 ) ) {
V_15 -> V_21 . V_142 ++ ;
F_34 ( V_15 , V_84 , true ) ;
return NULL ;
}
F_104 ( V_84 -> V_70 ) ;
F_34 ( V_15 , V_84 , true ) ;
F_105 ( V_89 , V_85 ) ;
F_106 ( V_89 , V_143 ) ;
return V_89 ;
}
void F_107 ( struct V_14 * V_15 , struct V_13 * V_30 )
{
struct V_81 * V_82 ;
T_5 V_266 ;
struct V_88 * V_89 ;
T_3 V_20 ;
T_1 V_143 ;
V_266 = V_30 -> V_20 ;
V_20 = F_6 ( V_266 ) ;
V_82 = F_61 ( & V_15 -> V_11 , V_20 ) ;
V_143 = F_5 ( V_30 -> V_18 ) ;
V_89 = F_99 ( V_15 , V_30 , V_20 , V_143 ) ;
if ( ! V_89 )
goto V_267;
F_92 ( V_15 , V_30 , V_143 , V_89 ) ;
F_108 ( V_15 -> V_7 . V_268 , V_89 ) ;
V_267:
F_109 ( & V_15 -> V_11 , V_266 ,
& V_82 -> V_138 . V_139 ) ;
}
void F_110 ( struct V_14 * V_15 , struct V_13 * V_30 )
{
struct V_187 * V_58 = V_15 -> V_58 ;
struct V_46 * V_47 = F_111 ( V_58 ) ;
struct V_269 * V_270 = V_47 -> V_271 ;
struct V_81 * V_82 ;
struct V_88 * V_89 ;
T_5 V_266 ;
T_3 V_20 ;
T_1 V_143 ;
V_266 = V_30 -> V_20 ;
V_20 = F_6 ( V_266 ) ;
V_82 = F_61 ( & V_15 -> V_11 , V_20 ) ;
V_143 = F_5 ( V_30 -> V_18 ) ;
V_89 = F_99 ( V_15 , V_30 , V_20 , V_143 ) ;
if ( ! V_89 )
goto V_267;
F_92 ( V_15 , V_30 , V_143 , V_89 ) ;
if ( V_270 -> V_272 && F_112 ( V_89 ) )
F_113 ( V_89 ) ;
F_108 ( V_15 -> V_7 . V_268 , V_89 ) ;
V_267:
F_109 ( & V_15 -> V_11 , V_266 ,
& V_82 -> V_138 . V_139 ) ;
}
static inline void F_114 ( struct V_14 * V_15 ,
struct V_13 * V_30 ,
struct V_90 * V_91 ,
T_1 V_143 ,
struct V_88 * V_89 )
{
T_3 V_273 = F_115 ( V_30 ) ;
T_1 V_274 = V_273 * V_15 -> V_96 ;
T_1 V_275 = V_274 & ( V_104 - 1 ) ;
T_1 V_92 = V_274 >> V_127 ;
T_1 V_276 = V_92 ;
T_3 V_102 = F_9 ( T_3 , V_277 , V_143 ) ;
T_1 V_93 = V_275 + V_102 ;
T_3 V_18 = V_143 - V_102 ;
if ( F_10 ( V_93 >= V_104 ) ) {
V_92 ++ ;
V_93 -= V_104 ;
}
while ( V_18 ) {
T_1 V_278 =
F_9 ( T_1 , V_104 - V_93 , V_18 ) ;
F_41 ( V_15 , V_89 , V_91 , V_92 , V_93 ,
V_278 ) ;
V_18 -= V_278 ;
V_93 = 0 ;
V_92 ++ ;
}
F_46 ( V_15 -> V_73 , V_89 , V_91 , V_276 ,
V_275 , V_102 ) ;
V_89 -> V_65 += V_102 ;
V_89 -> V_94 += V_102 ;
}
void F_116 ( struct V_14 * V_15 , struct V_13 * V_30 )
{
T_3 V_279 = F_13 ( V_30 ) ;
T_3 V_280 = F_6 ( V_30 -> V_280 ) ;
struct V_90 * V_91 = & V_15 -> V_105 . V_106 [ V_280 ] ;
struct V_81 * V_82 = F_61 ( & V_15 -> V_11 , V_280 ) ;
struct V_88 * V_89 ;
T_3 V_143 ;
V_91 -> V_134 += V_279 ;
if ( F_10 ( ( V_30 -> V_26 >> 4 ) != V_264 ) ) {
V_15 -> V_21 . V_265 ++ ;
goto V_281;
}
if ( F_10 ( F_117 ( V_30 ) ) ) {
V_15 -> V_21 . V_282 ++ ;
goto V_281;
}
V_89 = F_118 ( V_15 -> V_7 . V_268 ,
F_42 ( V_277 ,
sizeof( long ) ) ) ;
if ( F_10 ( ! V_89 ) ) {
V_15 -> V_21 . V_142 ++ ;
goto V_281;
}
F_102 ( V_89 -> V_9 ) ;
V_143 = F_119 ( V_30 ) ;
F_114 ( V_15 , V_30 , V_91 , V_143 , V_89 ) ;
F_92 ( V_15 , V_30 , V_143 , V_89 ) ;
F_108 ( V_15 -> V_7 . V_268 , V_89 ) ;
V_281:
if ( F_35 ( V_91 -> V_134 < V_15 -> V_86 ) )
return;
F_59 ( V_15 , V_91 ) ;
F_109 ( & V_15 -> V_11 , V_30 -> V_280 , & V_82 -> V_138 . V_139 ) ;
}
int F_120 ( struct V_6 * V_7 , int V_283 )
{
struct V_14 * V_15 = F_121 ( V_7 , struct V_14 , V_7 ) ;
struct V_107 * V_225 = & V_15 -> V_109 -> V_225 ;
int V_284 = 0 ;
if ( F_10 ( ! F_20 ( V_137 , & V_15 -> V_57 ) ) )
return 0 ;
if ( V_7 -> V_17 )
V_284 += F_15 ( V_15 , V_7 , 0 , V_283 ) ;
for (; V_284 < V_283 ; V_284 ++ ) {
struct V_13 * V_30 = F_122 ( V_7 ) ;
if ( ! V_30 )
break;
if ( F_123 ( V_30 ) == V_285 ) {
V_284 +=
F_16 ( V_15 , V_7 ,
V_283 - V_284 ) ;
continue;
}
F_124 ( & V_7 -> V_11 ) ;
V_15 -> V_44 ( V_15 , V_30 ) ;
}
if ( V_225 -> V_118 . V_227 . V_238 ) {
F_93 ( V_225 ) ;
V_225 -> V_118 . V_227 . V_238 = false ;
}
F_125 ( & V_7 -> V_11 ) ;
F_126 () ;
return V_284 ;
}

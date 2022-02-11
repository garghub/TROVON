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
if ( F_20 ( V_47 , V_53 ) == V_48 )
goto V_54;
V_49 = F_21 ( V_55 , & V_47 -> V_56 ) ;
if ( V_49 )
F_22 ( V_47 -> V_57 ) ;
F_23 ( V_47 , V_53 , V_48 ) ;
if ( V_49 )
F_24 ( V_47 -> V_57 ) ;
V_54:
F_25 ( & V_47 -> V_52 ) ;
}
static inline bool F_26 ( struct V_14 * V_15 ,
struct V_58 * V_59 )
{
struct V_60 * V_61 = & V_15 -> V_62 ;
T_1 V_63 = ( V_61 -> V_64 + 1 ) & ( V_65 - 1 ) ;
if ( V_63 == V_61 -> V_66 ) {
V_15 -> V_21 . V_67 ++ ;
return false ;
}
if ( F_10 ( F_27 ( V_59 -> V_68 ) ) )
return false ;
V_61 -> V_62 [ V_61 -> V_64 ] = * V_59 ;
V_61 -> V_64 = V_63 ;
return true ;
}
static inline bool F_28 ( struct V_14 * V_15 ,
struct V_58 * V_59 )
{
struct V_60 * V_61 = & V_15 -> V_62 ;
if ( F_10 ( V_61 -> V_66 == V_61 -> V_64 ) ) {
V_15 -> V_21 . V_69 ++ ;
return false ;
}
if ( F_29 ( V_61 -> V_62 [ V_61 -> V_66 ] . V_68 ) != 1 ) {
V_15 -> V_21 . V_70 ++ ;
return false ;
}
* V_59 = V_61 -> V_62 [ V_61 -> V_66 ] ;
V_61 -> V_66 = ( V_61 -> V_66 + 1 ) & ( V_65 - 1 ) ;
V_15 -> V_21 . V_71 ++ ;
F_30 ( V_15 -> V_72 , V_59 -> V_73 ,
F_31 ( V_15 ) ,
V_74 ) ;
return true ;
}
static inline int F_32 ( struct V_14 * V_15 ,
struct V_58 * V_59 )
{
struct V_68 * V_68 ;
if ( F_28 ( V_15 , V_59 ) )
return 0 ;
V_68 = F_33 ( V_15 -> V_75 . V_76 ) ;
if ( F_10 ( ! V_68 ) )
return - V_77 ;
V_59 -> V_68 = V_68 ;
V_59 -> V_73 = F_34 ( V_15 -> V_72 , V_68 , 0 ,
F_31 ( V_15 ) , V_15 -> V_75 . V_78 ) ;
if ( F_10 ( F_35 ( V_15 -> V_72 , V_59 -> V_73 ) ) ) {
F_36 ( V_68 ) ;
return - V_77 ;
}
return 0 ;
}
void F_37 ( struct V_14 * V_15 , struct V_58 * V_59 ,
bool V_79 )
{
if ( F_38 ( V_79 ) && F_26 ( V_15 , V_59 ) )
return;
F_39 ( V_15 -> V_72 , V_59 -> V_73 , F_31 ( V_15 ) ,
V_15 -> V_75 . V_78 ) ;
F_36 ( V_59 -> V_68 ) ;
}
int F_40 ( struct V_14 * V_15 , struct V_80 * V_81 , T_3 V_82 )
{
struct V_58 * V_83 = & V_15 -> V_59 [ V_82 ] ;
if ( F_10 ( F_32 ( V_15 , V_83 ) ) )
return - V_77 ;
V_81 -> V_9 . V_73 = F_41 ( V_83 -> V_73 + V_84 ) ;
return 0 ;
}
void F_42 ( struct V_14 * V_15 , T_3 V_82 )
{
struct V_58 * V_83 = & V_15 -> V_59 [ V_82 ] ;
F_37 ( V_15 , V_83 , true ) ;
}
static inline int F_43 ( struct V_14 * V_15 )
{
return V_15 -> V_85 >> V_86 ;
}
static inline void F_44 ( struct V_14 * V_15 ,
struct V_87 * V_88 ,
struct V_89 * V_90 ,
T_1 V_91 , T_1 V_92 ,
T_1 V_93 )
{
unsigned int V_94 = F_45 ( V_93 , V_15 -> V_95 ) ;
F_46 ( V_15 -> V_72 ,
V_90 -> V_96 . V_59 [ V_91 ] . V_73 + V_92 ,
V_93 , V_74 ) ;
V_90 -> V_97 [ V_91 ] ++ ;
F_47 ( V_88 , F_48 ( V_88 ) -> V_98 ,
V_90 -> V_96 . V_59 [ V_91 ] . V_68 , V_92 ,
V_93 , V_94 ) ;
}
static inline void
F_49 ( struct V_99 * V_72 ,
struct V_87 * V_88 ,
struct V_89 * V_90 ,
T_1 V_91 , T_1 V_100 ,
T_1 V_101 )
{
T_3 V_102 = F_9 ( T_1 , V_101 , V_103 - V_100 ) ;
struct V_58 * V_59 = & V_90 -> V_96 . V_59 [ V_91 ] ;
unsigned int V_93 ;
V_93 = F_45 ( V_102 , sizeof( long ) ) ;
F_46 ( V_72 , V_59 -> V_73 + V_100 , V_93 ,
V_74 ) ;
F_50 ( V_88 , 0 ,
F_51 ( V_59 -> V_68 ) + V_100 ,
V_93 ) ;
if ( F_10 ( V_100 + V_101 > V_103 ) ) {
V_59 ++ ;
V_102 = V_93 ;
V_93 = F_45 ( V_101 - V_102 , sizeof( long ) ) ;
F_46 ( V_72 , V_59 -> V_73 , V_93 ,
V_74 ) ;
F_50 ( V_88 , V_102 ,
F_51 ( V_59 -> V_68 ) ,
V_93 ) ;
}
}
static inline void F_52 ( struct V_14 * V_15 , T_3 V_82 )
{
struct V_89 * V_90 = & V_15 -> V_104 . V_105 [ V_82 ] ;
struct V_106 * V_107 = & V_15 -> V_108 -> V_109 ;
struct V_110 * V_11 = & V_107 -> V_11 ;
struct V_111 * V_81 ;
T_2 V_112 = F_53 ( sizeof( * V_81 ) , V_113 ) ;
T_3 V_114 ;
while ( ( V_114 = ( V_107 -> V_115 & V_11 -> V_12 ) ) > V_107 -> V_116 ) {
V_107 -> V_117 . V_118 [ V_114 ] . V_119 = V_120 ;
V_107 -> V_117 . V_118 [ V_114 ] . V_112 = 1 ;
F_54 ( V_107 , false ) ;
}
V_81 = F_55 ( V_11 , V_114 ) ;
memcpy ( V_81 , & V_90 -> V_96 . V_81 , sizeof( * V_81 ) ) ;
V_81 -> V_121 . V_122 =
F_56 ( ( V_107 -> V_115 << V_123 ) |
V_124 ) ;
V_107 -> V_117 . V_118 [ V_114 ] . V_119 = V_124 ;
V_107 -> V_117 . V_118 [ V_114 ] . V_112 = V_112 ;
V_107 -> V_115 += V_112 ;
F_57 ( V_107 , & V_81 -> V_121 , 0 ) ;
}
static int F_58 ( struct V_14 * V_15 ,
struct V_80 * V_81 ,
T_3 V_82 )
{
struct V_89 * V_90 = & V_15 -> V_104 . V_105 [ V_82 ] ;
T_4 V_125 = ( T_4 ) F_59 ( V_15 , V_82 ) << V_126 ;
int V_127 = F_43 ( V_15 ) ;
int V_128 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_129 ; V_42 ++ ) {
struct V_58 * V_59 = & V_90 -> V_96 . V_59 [ V_42 ] ;
V_128 = F_32 ( V_15 , V_59 ) ;
if ( F_10 ( V_128 ) )
goto V_130;
V_90 -> V_96 . V_131 [ V_42 ] = F_41 ( V_59 -> V_73 | V_132 ) ;
F_60 ( V_59 -> V_68 , V_127 ) ;
V_90 -> V_97 [ V_42 ] = 0 ;
}
V_90 -> V_133 = 0 ;
V_81 -> V_9 . V_73 = F_41 ( V_125 ) ;
return 0 ;
V_130:
while ( -- V_42 >= 0 ) {
struct V_58 * V_59 = & V_90 -> V_96 . V_59 [ V_42 ] ;
F_61 ( V_59 -> V_68 , V_127 ) ;
F_37 ( V_15 , V_59 , true ) ;
}
return V_128 ;
}
void F_62 ( struct V_14 * V_15 , struct V_89 * V_90 )
{
int V_127 = F_43 ( V_15 ) ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_129 ; V_42 ++ ) {
struct V_58 * V_59 = & V_90 -> V_96 . V_59 [ V_42 ] ;
F_61 ( V_59 -> V_68 , V_127 - V_90 -> V_97 [ V_42 ] ) ;
F_37 ( V_15 , V_59 , true ) ;
}
}
void F_63 ( struct V_14 * V_15 )
{
struct V_134 * V_11 = & V_15 -> V_11 ;
struct V_80 * V_81 = F_64 ( V_11 , V_11 -> V_66 ) ;
F_65 ( V_135 , & V_15 -> V_56 ) ;
if ( F_10 ( ! F_21 ( V_136 , & V_15 -> V_56 ) ) ) {
F_62 ( V_15 , & V_15 -> V_104 . V_105 [ V_11 -> V_66 ] ) ;
return;
}
F_66 ( V_11 , F_6 ( V_81 -> V_137 . V_138 ) ) ;
F_67 () ;
F_68 ( V_11 ) ;
}
int F_69 ( struct V_14 * V_15 , struct V_80 * V_81 , T_3 V_82 )
{
int V_128 ;
V_128 = F_58 ( V_15 , V_81 , V_82 ) ;
if ( F_10 ( V_128 ) )
return V_128 ;
F_70 ( V_135 , & V_15 -> V_56 ) ;
F_52 ( V_15 , V_82 ) ;
return - V_139 ;
}
void F_71 ( struct V_14 * V_15 , T_3 V_82 )
{
struct V_89 * V_90 = & V_15 -> V_104 . V_105 [ V_82 ] ;
F_62 ( V_15 , V_90 ) ;
}
bool F_72 ( struct V_14 * V_15 )
{
struct V_134 * V_11 = & V_15 -> V_11 ;
if ( F_10 ( F_73 ( V_15 ) ) )
return false ;
while ( ! F_74 ( V_11 ) ) {
struct V_80 * V_81 = F_64 ( V_11 , V_11 -> V_66 ) ;
int V_128 ;
V_128 = V_15 -> V_140 ( V_15 , V_81 , V_11 -> V_66 ) ;
if ( V_128 == - V_139 )
return true ;
if ( F_10 ( V_128 ) ) {
V_15 -> V_21 . V_141 ++ ;
break;
}
F_66 ( V_11 , F_6 ( V_81 -> V_137 . V_138 ) ) ;
}
F_67 () ;
F_68 ( V_11 ) ;
return ! F_74 ( V_11 ) ;
}
static void F_75 ( struct V_87 * V_88 , struct V_13 * V_30 ,
T_1 V_142 )
{
struct V_143 * V_144 = (struct V_143 * ) ( V_88 -> V_9 ) ;
struct V_145 * V_146 ;
struct V_147 * V_148 ;
struct V_149 * V_150 ;
int V_151 = 0 ;
T_5 V_152 ;
T_3 V_153 ;
T_2 V_154 = F_76 ( V_30 ) ;
int V_155 = ( ( V_156 == V_154 ) ||
( V_157 == V_154 ) ) ;
V_88 -> V_158 = V_159 ;
V_152 = F_77 ( V_88 , V_144 -> V_160 , & V_151 ) ;
V_146 = (struct V_145 * ) ( V_88 -> V_9 + V_151 ) ;
V_148 = (struct V_147 * ) ( V_88 -> V_9 + V_151 ) ;
V_153 = V_142 - V_151 ;
if ( V_152 == F_78 ( V_161 ) ) {
V_150 = (struct V_149 * ) ( V_88 -> V_9 + V_151 +
sizeof( struct V_145 ) ) ;
V_148 = NULL ;
F_48 ( V_88 ) -> V_162 = V_163 ;
} else {
V_150 = (struct V_149 * ) ( V_88 -> V_9 + V_151 +
sizeof( struct V_147 ) ) ;
V_146 = NULL ;
F_48 ( V_88 ) -> V_162 = V_164 ;
}
if ( F_79 ( V_30 ) )
V_150 -> V_165 = 1 ;
if ( V_155 ) {
V_150 -> V_166 = 1 ;
V_150 -> V_167 = V_30 -> V_168 ;
V_150 -> V_169 = V_30 -> V_170 ;
}
if ( V_146 ) {
V_146 -> V_171 = V_30 -> V_172 ;
V_146 -> V_153 = F_12 ( V_153 ) ;
V_146 -> V_173 = 0 ;
V_146 -> V_173 = F_80 ( ( unsigned char * ) V_146 ,
V_146 -> V_174 ) ;
} else {
V_148 -> V_175 = V_30 -> V_172 ;
V_148 -> V_176 = F_12 ( V_153 -
sizeof( struct V_147 ) ) ;
}
}
static inline void F_81 ( struct V_13 * V_30 ,
struct V_87 * V_88 )
{
T_2 V_177 = V_30 -> V_36 ;
int V_178 = ( V_177 & V_179 ) ? V_180 :
( V_177 & V_181 ) ? V_182 :
V_183 ;
F_82 ( V_88 , F_5 ( V_30 -> V_37 ) , V_178 ) ;
}
static inline bool F_83 ( struct V_87 * V_88 )
{
T_5 V_184 = ( (struct V_143 * ) V_88 -> V_9 ) -> V_160 ;
return ( V_184 == F_78 ( V_161 ) || V_184 == F_78 ( V_185 ) ) ;
}
static inline void F_84 ( struct V_186 * V_57 ,
struct V_13 * V_30 ,
struct V_14 * V_15 ,
struct V_87 * V_88 ,
bool V_187 )
{
if ( F_10 ( ! ( V_57 -> V_188 & V_189 ) ) )
goto V_190;
if ( V_187 ) {
V_88 -> V_191 = V_192 ;
return;
}
if ( F_83 ( V_88 ) ) {
V_88 -> V_191 = V_193 ;
V_88 -> V_194 = F_85 ( ( V_195 V_196 ) V_30 -> V_32 ) ;
V_15 -> V_21 . V_197 ++ ;
return;
}
if ( F_38 ( ( V_30 -> V_198 & V_199 ) &&
( V_30 -> V_198 & V_200 ) ) ) {
V_88 -> V_191 = V_192 ;
if ( F_86 ( V_30 ) ) {
V_88 -> V_201 = 1 ;
V_88 -> V_202 = 1 ;
V_15 -> V_21 . V_203 ++ ;
}
return;
}
V_190:
V_88 -> V_191 = V_204 ;
V_15 -> V_21 . V_190 ++ ;
}
static inline void F_87 ( struct V_13 * V_30 ,
T_1 V_142 ,
struct V_14 * V_15 ,
struct V_87 * V_88 )
{
struct V_186 * V_57 = V_15 -> V_57 ;
struct V_1 * V_2 = V_15 -> V_2 ;
int V_205 ;
V_205 = F_5 ( V_30 -> V_206 ) >> 24 ;
if ( V_205 > 1 ) {
F_75 ( V_88 , V_30 , V_142 ) ;
F_48 ( V_88 ) -> V_207 = F_53 ( V_142 , V_205 ) ;
V_15 -> V_21 . V_208 ++ ;
V_15 -> V_21 . V_209 += V_142 ;
}
if ( F_10 ( F_1 ( V_2 ) ) )
F_88 ( V_2 , F_89 ( V_30 ) , F_90 ( V_88 ) ) ;
F_91 ( V_88 , V_15 -> V_82 ) ;
if ( F_38 ( V_57 -> V_188 & V_210 ) )
F_81 ( V_30 , V_88 ) ;
if ( F_92 ( V_30 ) )
F_93 ( V_88 , F_78 ( V_211 ) ,
F_6 ( V_30 -> V_212 ) ) ;
V_88 -> V_213 = F_5 ( V_30 -> V_214 ) & V_215 ;
F_84 ( V_57 , V_30 , V_15 , V_88 , ! ! V_205 ) ;
V_88 -> V_216 = F_94 ( V_88 , V_57 ) ;
}
static inline void F_95 ( struct V_14 * V_15 ,
struct V_13 * V_30 ,
T_1 V_142 ,
struct V_87 * V_88 )
{
V_15 -> V_21 . V_217 ++ ;
V_15 -> V_21 . V_218 += V_142 ;
F_87 ( V_30 , V_142 , V_15 , V_88 ) ;
}
static inline void F_96 ( struct V_106 * V_107 )
{
struct V_110 * V_11 = & V_107 -> V_11 ;
struct V_219 * V_81 ;
T_3 V_114 = ( V_107 -> V_115 - V_220 ) & V_11 -> V_12 ;
V_81 = F_55 ( V_11 , V_114 ) ;
V_81 -> V_121 . V_221 = V_222 ;
F_57 ( V_107 , & V_81 -> V_121 , 0 ) ;
}
static inline void F_97 ( struct V_14 * V_15 ,
struct V_58 * V_83 ,
unsigned int V_223 ,
int V_93 )
{
struct V_106 * V_107 = & V_15 -> V_108 -> V_224 ;
struct V_110 * V_11 = & V_107 -> V_11 ;
T_3 V_114 = V_107 -> V_115 & V_11 -> V_12 ;
struct V_219 * V_81 = F_55 ( V_11 , V_114 ) ;
struct V_225 * V_90 = & V_107 -> V_117 . V_226 . V_227 [ V_114 ] ;
struct V_228 * V_229 = & V_81 -> V_121 ;
struct V_230 * V_231 = & V_81 -> V_144 ;
struct V_232 * V_233 ;
T_6 V_234 = V_83 -> V_73 + V_223 + V_235 ;
unsigned int V_236 = V_93 - V_235 ;
void * V_9 = F_51 ( V_83 -> V_68 ) + V_223 ;
if ( F_10 ( ! F_98 ( V_107 , V_220 ) ) ) {
if ( V_107 -> V_117 . V_226 . V_237 ) {
F_96 ( V_107 ) ;
V_107 -> V_117 . V_226 . V_237 = false ;
}
V_15 -> V_21 . V_238 ++ ;
F_37 ( V_15 , V_83 , true ) ;
return;
}
F_30 ( V_107 -> V_72 , V_234 , V_236 ,
V_239 ) ;
memset ( V_81 , 0 , sizeof( * V_81 ) ) ;
memcpy ( V_231 -> V_240 , V_9 , V_235 ) ;
V_231 -> V_241 = F_12 ( V_235 ) ;
V_233 = (struct V_232 * ) V_229 + ( V_242 - 1 ) ;
V_233 -> V_73 = F_41 ( V_234 ) ;
V_233 -> V_243 = F_56 ( V_236 ) ;
V_233 -> V_244 = V_107 -> V_245 ;
V_229 -> V_122 = F_56 ( ( V_107 -> V_115 << 8 ) | V_246 ) ;
V_229 -> V_247 = F_56 ( ( V_107 -> V_248 << 8 ) | V_242 ) ;
V_107 -> V_117 . V_226 . V_83 [ V_114 ] = * V_83 ;
V_90 -> V_119 = V_246 ;
V_90 -> V_112 = V_220 ;
V_107 -> V_115 += V_220 ;
V_107 -> V_117 . V_226 . V_237 = true ;
V_15 -> V_21 . V_249 ++ ;
}
static inline bool F_99 ( struct V_14 * V_15 ,
const struct V_250 * V_251 ,
struct V_58 * V_83 ,
void * V_9 , T_3 V_93 )
{
struct V_252 V_226 ;
T_1 V_253 ;
if ( ! V_251 )
return false ;
V_226 . V_9 = V_9 ;
V_226 . V_254 = V_226 . V_9 + V_93 ;
V_253 = F_100 ( V_251 , & V_226 ) ;
switch ( V_253 ) {
case V_255 :
return false ;
case V_256 :
F_97 ( V_15 , V_83 , V_84 , V_93 ) ;
return true ;
default:
F_101 ( V_253 ) ;
case V_257 :
case V_258 :
V_15 -> V_21 . V_259 ++ ;
F_37 ( V_15 , V_83 , true ) ;
return true ;
}
}
static inline
struct V_87 * F_102 ( struct V_14 * V_15 , struct V_13 * V_30 ,
T_3 V_20 , T_1 V_142 )
{
struct V_58 * V_83 ;
struct V_87 * V_88 ;
void * V_260 , * V_9 ;
bool V_261 ;
V_83 = & V_15 -> V_59 [ V_20 ] ;
V_260 = F_51 ( V_83 -> V_68 ) ;
V_9 = V_260 + V_84 ;
F_103 ( V_15 -> V_72 ,
V_83 -> V_73 ,
V_84 ,
V_15 -> V_75 . V_262 ,
V_74 ) ;
F_104 ( V_9 ) ;
if ( F_10 ( ( V_30 -> V_26 >> 4 ) != V_263 ) ) {
V_15 -> V_21 . V_264 ++ ;
F_37 ( V_15 , V_83 , true ) ;
return NULL ;
}
F_105 () ;
V_261 = F_99 ( V_15 , F_106 ( V_15 -> V_265 ) , V_83 , V_9 ,
V_142 ) ;
F_107 () ;
if ( V_261 )
return NULL ;
V_88 = F_108 ( V_260 , F_31 ( V_15 ) ) ;
if ( F_10 ( ! V_88 ) ) {
V_15 -> V_21 . V_141 ++ ;
F_37 ( V_15 , V_83 , true ) ;
return NULL ;
}
F_109 ( V_83 -> V_68 ) ;
F_37 ( V_15 , V_83 , true ) ;
F_110 ( V_88 , V_84 ) ;
F_111 ( V_88 , V_142 ) ;
return V_88 ;
}
void F_112 ( struct V_14 * V_15 , struct V_13 * V_30 )
{
struct V_80 * V_81 ;
T_5 V_266 ;
struct V_87 * V_88 ;
T_3 V_20 ;
T_1 V_142 ;
V_266 = V_30 -> V_20 ;
V_20 = F_6 ( V_266 ) ;
V_81 = F_64 ( & V_15 -> V_11 , V_20 ) ;
V_142 = F_5 ( V_30 -> V_18 ) ;
V_88 = F_102 ( V_15 , V_30 , V_20 , V_142 ) ;
if ( ! V_88 )
goto V_267;
F_95 ( V_15 , V_30 , V_142 , V_88 ) ;
F_113 ( V_15 -> V_7 . V_268 , V_88 ) ;
V_267:
F_114 ( & V_15 -> V_11 , V_266 ,
& V_81 -> V_137 . V_138 ) ;
}
void F_115 ( struct V_14 * V_15 , struct V_13 * V_30 )
{
struct V_186 * V_57 = V_15 -> V_57 ;
struct V_46 * V_47 = F_116 ( V_57 ) ;
struct V_269 * V_270 = V_47 -> V_271 ;
struct V_80 * V_81 ;
struct V_87 * V_88 ;
T_5 V_266 ;
T_3 V_20 ;
T_1 V_142 ;
V_266 = V_30 -> V_20 ;
V_20 = F_6 ( V_266 ) ;
V_81 = F_64 ( & V_15 -> V_11 , V_20 ) ;
V_142 = F_5 ( V_30 -> V_18 ) ;
V_88 = F_102 ( V_15 , V_30 , V_20 , V_142 ) ;
if ( ! V_88 )
goto V_267;
F_95 ( V_15 , V_30 , V_142 , V_88 ) ;
if ( V_270 -> V_272 && F_117 ( V_88 ) )
F_118 ( V_88 ) ;
F_113 ( V_15 -> V_7 . V_268 , V_88 ) ;
V_267:
F_114 ( & V_15 -> V_11 , V_266 ,
& V_81 -> V_137 . V_138 ) ;
}
static inline void F_119 ( struct V_14 * V_15 ,
struct V_13 * V_30 ,
struct V_89 * V_90 ,
T_1 V_142 ,
struct V_87 * V_88 )
{
T_3 V_273 = F_120 ( V_30 ) ;
T_1 V_274 = V_273 * V_15 -> V_95 ;
T_1 V_275 = V_274 & ( V_103 - 1 ) ;
T_1 V_91 = V_274 >> V_126 ;
T_1 V_276 = V_91 ;
T_3 V_101 = F_9 ( T_3 , V_277 , V_142 ) ;
T_1 V_92 = V_275 + V_101 ;
T_3 V_18 = V_142 - V_101 ;
if ( F_10 ( V_92 >= V_103 ) ) {
V_91 ++ ;
V_92 -= V_103 ;
}
while ( V_18 ) {
T_1 V_278 =
F_9 ( T_1 , V_103 - V_92 , V_18 ) ;
F_44 ( V_15 , V_88 , V_90 , V_91 , V_92 ,
V_278 ) ;
V_18 -= V_278 ;
V_92 = 0 ;
V_91 ++ ;
}
F_49 ( V_15 -> V_72 , V_88 , V_90 , V_276 ,
V_275 , V_101 ) ;
V_88 -> V_64 += V_101 ;
V_88 -> V_93 += V_101 ;
}
void F_121 ( struct V_14 * V_15 , struct V_13 * V_30 )
{
T_3 V_279 = F_13 ( V_30 ) ;
T_3 V_280 = F_6 ( V_30 -> V_280 ) ;
struct V_89 * V_90 = & V_15 -> V_104 . V_105 [ V_280 ] ;
struct V_80 * V_81 = F_64 ( & V_15 -> V_11 , V_280 ) ;
struct V_87 * V_88 ;
T_3 V_142 ;
V_90 -> V_133 += V_279 ;
if ( F_10 ( ( V_30 -> V_26 >> 4 ) != V_263 ) ) {
V_15 -> V_21 . V_264 ++ ;
goto V_281;
}
if ( F_10 ( F_122 ( V_30 ) ) ) {
V_15 -> V_21 . V_282 ++ ;
goto V_281;
}
V_88 = F_123 ( V_15 -> V_7 . V_268 ,
F_45 ( V_277 ,
sizeof( long ) ) ) ;
if ( F_10 ( ! V_88 ) ) {
V_15 -> V_21 . V_141 ++ ;
goto V_281;
}
F_104 ( V_88 -> V_9 ) ;
V_142 = F_124 ( V_30 ) ;
F_119 ( V_15 , V_30 , V_90 , V_142 , V_88 ) ;
F_95 ( V_15 , V_30 , V_142 , V_88 ) ;
F_113 ( V_15 -> V_7 . V_268 , V_88 ) ;
V_281:
if ( F_38 ( V_90 -> V_133 < V_15 -> V_85 ) )
return;
F_62 ( V_15 , V_90 ) ;
F_114 ( & V_15 -> V_11 , V_30 -> V_280 , & V_81 -> V_137 . V_138 ) ;
}
int F_125 ( struct V_6 * V_7 , int V_283 )
{
struct V_14 * V_15 = F_126 ( V_7 , struct V_14 , V_7 ) ;
struct V_106 * V_224 = & V_15 -> V_108 -> V_224 ;
int V_284 = 0 ;
if ( F_10 ( ! F_21 ( V_136 , & V_15 -> V_56 ) ) )
return 0 ;
if ( V_7 -> V_17 )
V_284 += F_15 ( V_15 , V_7 , 0 , V_283 ) ;
for (; V_284 < V_283 ; V_284 ++ ) {
struct V_13 * V_30 = F_127 ( V_7 ) ;
if ( ! V_30 )
break;
if ( F_128 ( V_30 ) == V_285 ) {
V_284 +=
F_16 ( V_15 , V_7 ,
V_283 - V_284 ) ;
continue;
}
F_129 ( & V_7 -> V_11 ) ;
V_15 -> V_44 ( V_15 , V_30 ) ;
}
if ( V_224 -> V_117 . V_226 . V_237 ) {
F_96 ( V_224 ) ;
V_224 -> V_117 . V_226 . V_237 = false ;
}
F_130 ( & V_7 -> V_11 ) ;
F_131 () ;
return V_284 ;
}

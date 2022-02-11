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
V_7 -> V_16 . V_18 = V_7 -> V_23 [ V_7 -> V_24 ] . V_18 ;
V_7 -> V_16 . V_31 = V_7 -> V_23 [ V_7 -> V_24 ] . V_32 ;
V_7 -> V_16 . V_26 &= 0xf0 ;
V_7 -> V_16 . V_26 |= 0x01 & ( V_8 >> V_7 -> V_11 . V_27 ) ;
V_7 -> V_16 . V_20 = F_12 ( V_7 -> V_19 ) ;
if ( V_15 -> V_33 == V_34 )
V_7 -> V_19 +=
F_13 ( & V_7 -> V_16 ) ;
else
V_7 -> V_19 =
( V_7 -> V_19 + 1 ) & V_15 -> V_11 . V_12 ;
}
static inline void F_14 ( struct V_14 * V_15 ,
struct V_6 * V_7 , T_1 V_8 )
{
F_11 ( V_15 , V_7 , V_8 ) ;
V_7 -> V_16 . V_35 = 0 ;
V_7 -> V_16 . V_36 = 0 ;
}
static inline T_1 F_15 ( struct V_14 * V_15 ,
struct V_6 * V_7 ,
int V_37 ,
int V_38 )
{
T_1 V_8 = V_7 -> V_11 . V_39 + V_37 ;
T_1 V_40 ;
T_1 V_41 ;
V_40 = F_9 ( T_1 , V_7 -> V_17 , V_38 ) ;
for ( V_41 = V_37 ; V_41 < V_40 ;
V_41 ++ , V_7 -> V_24 ++ , V_8 ++ ) {
if ( V_7 -> V_24 == V_42 )
F_7 ( V_7 , V_8 ) ;
F_14 ( V_15 , V_7 , V_8 ) ;
V_15 -> V_43 ( V_15 , & V_7 -> V_16 ) ;
}
F_8 ( V_7 , V_7 -> V_11 . V_39 , V_8 - V_7 -> V_11 . V_39 ) ;
V_7 -> V_11 . V_39 = V_8 ;
V_7 -> V_17 -= V_40 ;
V_15 -> V_21 . V_44 += V_40 ;
return V_40 ;
}
static inline T_1 F_16 ( struct V_14 * V_15 ,
struct V_6 * V_7 ,
int V_38 )
{
F_4 ( V_15 , V_7 , V_7 -> V_11 . V_39 ) ;
F_7 ( V_7 , V_7 -> V_11 . V_39 + 1 ) ;
F_11 ( V_15 , V_7 , V_7 -> V_11 . V_39 ) ;
V_15 -> V_43 ( V_15 , & V_7 -> V_16 ) ;
V_7 -> V_24 ++ ;
return F_15 ( V_15 , V_7 , 1 , V_38 ) - 1 ;
}
void F_17 ( struct V_45 * V_46 , bool V_47 )
{
bool V_48 ;
if ( ! F_18 ( V_46 -> V_49 , V_50 ) )
return;
if ( F_19 ( V_46 , V_51 ) == V_47 )
return;
V_48 = F_20 ( V_52 , & V_46 -> V_53 ) ;
if ( V_48 )
F_21 ( V_46 -> V_54 ) ;
F_22 ( V_46 , V_51 , V_47 ) ;
F_23 ( V_46 , V_46 -> V_55 . V_56 ) ;
if ( V_48 )
F_24 ( V_46 -> V_54 ) ;
}
static inline bool F_25 ( struct V_14 * V_15 ,
struct V_57 * V_58 )
{
struct V_59 * V_60 = & V_15 -> V_61 ;
T_1 V_62 = ( V_60 -> V_63 + 1 ) & ( V_64 - 1 ) ;
if ( V_62 == V_60 -> V_65 ) {
V_15 -> V_21 . V_66 ++ ;
return false ;
}
if ( F_10 ( F_26 ( V_58 -> V_67 ) ) )
return false ;
V_60 -> V_61 [ V_60 -> V_63 ] = * V_58 ;
V_60 -> V_63 = V_62 ;
return true ;
}
static inline bool F_27 ( struct V_14 * V_15 ,
struct V_57 * V_58 )
{
struct V_59 * V_60 = & V_15 -> V_61 ;
if ( F_10 ( V_60 -> V_65 == V_60 -> V_63 ) ) {
V_15 -> V_21 . V_68 ++ ;
return false ;
}
if ( F_28 ( V_60 -> V_61 [ V_60 -> V_65 ] . V_67 ) != 1 ) {
V_15 -> V_21 . V_69 ++ ;
return false ;
}
* V_58 = V_60 -> V_61 [ V_60 -> V_65 ] ;
V_60 -> V_65 = ( V_60 -> V_65 + 1 ) & ( V_64 - 1 ) ;
V_15 -> V_21 . V_70 ++ ;
F_29 ( V_15 -> V_71 , V_58 -> V_72 ,
F_30 ( V_15 ) ,
V_73 ) ;
return true ;
}
static inline int F_31 ( struct V_14 * V_15 ,
struct V_57 * V_58 )
{
struct V_67 * V_67 ;
if ( F_27 ( V_15 , V_58 ) )
return 0 ;
V_67 = F_32 ( V_15 -> V_74 . V_75 ) ;
if ( F_10 ( ! V_67 ) )
return - V_76 ;
V_58 -> V_67 = V_67 ;
V_58 -> V_72 = F_33 ( V_15 -> V_71 , V_67 , 0 ,
F_30 ( V_15 ) , V_15 -> V_74 . V_77 ) ;
if ( F_10 ( F_34 ( V_15 -> V_71 , V_58 -> V_72 ) ) ) {
F_35 ( V_67 ) ;
return - V_76 ;
}
return 0 ;
}
void F_36 ( struct V_14 * V_15 , struct V_57 * V_58 ,
bool V_78 )
{
if ( F_37 ( V_78 ) && F_25 ( V_15 , V_58 ) )
return;
F_38 ( V_15 -> V_71 , V_58 -> V_72 , F_30 ( V_15 ) ,
V_15 -> V_74 . V_77 ) ;
F_35 ( V_58 -> V_67 ) ;
}
int F_39 ( struct V_14 * V_15 , struct V_79 * V_80 , T_3 V_81 )
{
struct V_57 * V_82 = & V_15 -> V_58 [ V_81 ] ;
if ( F_10 ( F_31 ( V_15 , V_82 ) ) )
return - V_76 ;
V_80 -> V_9 . V_72 = F_40 ( V_82 -> V_72 + V_15 -> V_83 ) ;
return 0 ;
}
void F_41 ( struct V_14 * V_15 , T_3 V_81 )
{
struct V_57 * V_82 = & V_15 -> V_58 [ V_81 ] ;
F_36 ( V_15 , V_82 , true ) ;
}
static inline int F_42 ( struct V_14 * V_15 )
{
return V_15 -> V_84 >> V_85 ;
}
static inline void F_43 ( struct V_14 * V_15 ,
struct V_86 * V_87 ,
struct V_88 * V_89 ,
T_1 V_90 , T_1 V_91 ,
T_1 V_92 )
{
unsigned int V_93 = F_44 ( V_92 , V_15 -> V_94 ) ;
F_45 ( V_15 -> V_71 ,
V_89 -> V_95 . V_58 [ V_90 ] . V_72 + V_91 ,
V_92 , V_73 ) ;
V_89 -> V_96 [ V_90 ] ++ ;
F_46 ( V_87 , F_47 ( V_87 ) -> V_97 ,
V_89 -> V_95 . V_58 [ V_90 ] . V_67 , V_91 ,
V_92 , V_93 ) ;
}
static inline void
F_48 ( struct V_98 * V_71 ,
struct V_86 * V_87 ,
struct V_88 * V_89 ,
T_1 V_90 , T_1 V_99 ,
T_1 V_100 )
{
T_3 V_101 = F_9 ( T_1 , V_100 , V_102 - V_99 ) ;
struct V_57 * V_58 = & V_89 -> V_95 . V_58 [ V_90 ] ;
unsigned int V_92 ;
V_92 = F_44 ( V_101 , sizeof( long ) ) ;
F_45 ( V_71 , V_58 -> V_72 + V_99 , V_92 ,
V_73 ) ;
F_49 ( V_87 , 0 ,
F_50 ( V_58 -> V_67 ) + V_99 ,
V_92 ) ;
if ( F_10 ( V_99 + V_100 > V_102 ) ) {
V_58 ++ ;
V_101 = V_92 ;
V_92 = F_44 ( V_100 - V_101 , sizeof( long ) ) ;
F_45 ( V_71 , V_58 -> V_72 , V_92 ,
V_73 ) ;
F_49 ( V_87 , V_101 ,
F_50 ( V_58 -> V_67 ) ,
V_92 ) ;
}
}
static inline void F_51 ( struct V_14 * V_15 , T_3 V_81 )
{
struct V_88 * V_89 = & V_15 -> V_103 . V_104 [ V_81 ] ;
struct V_105 * V_106 = & V_15 -> V_107 -> V_108 ;
struct V_109 * V_11 = & V_106 -> V_11 ;
struct V_110 * V_80 ;
T_2 V_111 = F_52 ( sizeof( * V_80 ) , V_112 ) ;
T_3 V_113 ;
while ( ( V_113 = ( V_106 -> V_114 & V_11 -> V_12 ) ) > V_106 -> V_115 ) {
V_106 -> V_116 . V_117 [ V_113 ] . V_118 = V_119 ;
V_106 -> V_116 . V_117 [ V_113 ] . V_111 = 1 ;
F_53 ( V_106 , false ) ;
}
V_80 = F_54 ( V_11 , V_113 ) ;
memcpy ( V_80 , & V_89 -> V_95 . V_80 , sizeof( * V_80 ) ) ;
V_80 -> V_120 . V_121 =
F_55 ( ( V_106 -> V_114 << V_122 ) |
V_123 ) ;
V_106 -> V_116 . V_117 [ V_113 ] . V_118 = V_123 ;
V_106 -> V_116 . V_117 [ V_113 ] . V_111 = V_111 ;
V_106 -> V_114 += V_111 ;
F_56 ( V_106 , & V_80 -> V_120 , 0 ) ;
}
static int F_57 ( struct V_14 * V_15 ,
struct V_79 * V_80 ,
T_3 V_81 )
{
struct V_88 * V_89 = & V_15 -> V_103 . V_104 [ V_81 ] ;
T_4 V_124 = ( T_4 ) F_58 ( V_15 , V_81 ) << V_125 ;
int V_126 = F_42 ( V_15 ) ;
int V_127 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_128 ; V_41 ++ ) {
struct V_57 * V_58 = & V_89 -> V_95 . V_58 [ V_41 ] ;
V_127 = F_31 ( V_15 , V_58 ) ;
if ( F_10 ( V_127 ) )
goto V_129;
V_89 -> V_95 . V_130 [ V_41 ] = F_40 ( V_58 -> V_72 | V_131 ) ;
F_59 ( V_58 -> V_67 , V_126 ) ;
V_89 -> V_96 [ V_41 ] = 0 ;
}
V_89 -> V_132 = 0 ;
V_80 -> V_9 . V_72 = F_40 ( V_124 ) ;
return 0 ;
V_129:
while ( -- V_41 >= 0 ) {
struct V_57 * V_58 = & V_89 -> V_95 . V_58 [ V_41 ] ;
F_60 ( V_58 -> V_67 , V_126 ) ;
F_36 ( V_15 , V_58 , true ) ;
}
return V_127 ;
}
void F_61 ( struct V_14 * V_15 , struct V_88 * V_89 )
{
int V_126 = F_42 ( V_15 ) ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_128 ; V_41 ++ ) {
struct V_57 * V_58 = & V_89 -> V_95 . V_58 [ V_41 ] ;
F_60 ( V_58 -> V_67 , V_126 - V_89 -> V_96 [ V_41 ] ) ;
F_36 ( V_15 , V_58 , true ) ;
}
}
void F_62 ( struct V_14 * V_15 )
{
struct V_133 * V_11 = & V_15 -> V_11 ;
struct V_79 * V_80 = F_63 ( V_11 , V_11 -> V_65 ) ;
F_64 ( V_134 , & V_15 -> V_53 ) ;
if ( F_10 ( ! F_20 ( V_135 , & V_15 -> V_53 ) ) ) {
F_61 ( V_15 , & V_15 -> V_103 . V_104 [ V_11 -> V_65 ] ) ;
return;
}
F_65 ( V_11 , F_6 ( V_80 -> V_136 . V_137 ) ) ;
F_66 () ;
F_67 ( V_11 ) ;
}
int F_68 ( struct V_14 * V_15 , struct V_79 * V_80 , T_3 V_81 )
{
int V_127 ;
V_127 = F_57 ( V_15 , V_80 , V_81 ) ;
if ( F_10 ( V_127 ) )
return V_127 ;
F_69 ( V_134 , & V_15 -> V_53 ) ;
F_51 ( V_15 , V_81 ) ;
return - V_138 ;
}
void F_70 ( struct V_14 * V_15 , T_3 V_81 )
{
struct V_88 * V_89 = & V_15 -> V_103 . V_104 [ V_81 ] ;
F_61 ( V_15 , V_89 ) ;
}
bool F_71 ( struct V_14 * V_15 )
{
struct V_133 * V_11 = & V_15 -> V_11 ;
if ( F_10 ( F_72 ( V_15 ) ) )
return false ;
while ( ! F_73 ( V_11 ) ) {
struct V_79 * V_80 = F_63 ( V_11 , V_11 -> V_65 ) ;
int V_127 ;
V_127 = V_15 -> V_139 ( V_15 , V_80 , V_11 -> V_65 ) ;
if ( V_127 == - V_138 )
return true ;
if ( F_10 ( V_127 ) ) {
V_15 -> V_21 . V_140 ++ ;
break;
}
F_65 ( V_11 , F_6 ( V_80 -> V_136 . V_137 ) ) ;
}
F_66 () ;
F_67 ( V_11 ) ;
return ! F_73 ( V_11 ) ;
}
static void F_74 ( struct V_86 * V_87 , struct V_13 * V_30 ,
T_1 V_141 )
{
struct V_142 * V_143 = (struct V_142 * ) ( V_87 -> V_9 ) ;
struct V_144 * V_145 ;
struct V_146 * V_147 ;
struct V_148 * V_149 ;
int V_150 = 0 ;
T_5 V_151 ;
T_3 V_152 ;
T_2 V_153 = F_75 ( V_30 ) ;
int V_154 = ( ( V_155 == V_153 ) ||
( V_156 == V_153 ) ) ;
V_87 -> V_157 = V_158 ;
V_151 = F_76 ( V_87 , V_143 -> V_159 , & V_150 ) ;
V_145 = (struct V_144 * ) ( V_87 -> V_9 + V_150 ) ;
V_147 = (struct V_146 * ) ( V_87 -> V_9 + V_150 ) ;
V_152 = V_141 - V_150 ;
if ( V_151 == F_77 ( V_160 ) ) {
V_149 = (struct V_148 * ) ( V_87 -> V_9 + V_150 +
sizeof( struct V_144 ) ) ;
V_147 = NULL ;
F_47 ( V_87 ) -> V_161 = V_162 ;
} else {
V_149 = (struct V_148 * ) ( V_87 -> V_9 + V_150 +
sizeof( struct V_146 ) ) ;
V_145 = NULL ;
F_47 ( V_87 ) -> V_161 = V_163 ;
}
if ( F_78 ( V_30 ) )
V_149 -> V_164 = 1 ;
if ( V_154 ) {
V_149 -> V_165 = 1 ;
V_149 -> V_166 = V_30 -> V_167 ;
V_149 -> V_168 = V_30 -> V_169 ;
}
if ( V_145 ) {
V_145 -> V_170 = V_30 -> V_171 ;
V_145 -> V_152 = F_12 ( V_152 ) ;
V_145 -> V_172 = 0 ;
V_145 -> V_172 = F_79 ( ( unsigned char * ) V_145 ,
V_145 -> V_173 ) ;
} else {
V_147 -> V_174 = V_30 -> V_171 ;
V_147 -> V_175 = F_12 ( V_152 -
sizeof( struct V_146 ) ) ;
}
}
static inline void F_80 ( struct V_13 * V_30 ,
struct V_86 * V_87 )
{
T_2 V_176 = V_30 -> V_35 ;
int V_177 = ( V_176 & V_178 ) ? V_179 :
( V_176 & V_180 ) ? V_181 :
V_182 ;
F_81 ( V_87 , F_5 ( V_30 -> V_36 ) , V_177 ) ;
}
static inline bool F_82 ( struct V_86 * V_87 )
{
T_5 V_183 = ( (struct V_142 * ) V_87 -> V_9 ) -> V_159 ;
return ( V_183 == F_77 ( V_160 ) || V_183 == F_77 ( V_184 ) ) ;
}
static inline void F_83 ( struct V_185 * V_54 ,
struct V_13 * V_30 ,
struct V_14 * V_15 ,
struct V_86 * V_87 ,
bool V_186 )
{
if ( F_10 ( ! ( V_54 -> V_187 & V_188 ) ) )
goto V_189;
if ( V_186 ) {
V_87 -> V_190 = V_191 ;
return;
}
if ( F_82 ( V_87 ) ) {
V_87 -> V_190 = V_192 ;
V_87 -> V_193 = F_84 ( ( V_194 V_195 ) V_30 -> V_31 ) ;
V_15 -> V_21 . V_196 ++ ;
return;
}
if ( F_37 ( ( V_30 -> V_197 & V_198 ) &&
( V_30 -> V_197 & V_199 ) ) ) {
V_87 -> V_190 = V_191 ;
if ( F_85 ( V_30 ) ) {
V_87 -> V_200 = 1 ;
V_87 -> V_201 = 1 ;
V_15 -> V_21 . V_202 ++ ;
}
return;
}
V_189:
V_87 -> V_190 = V_203 ;
V_15 -> V_21 . V_189 ++ ;
}
static inline void F_86 ( struct V_13 * V_30 ,
T_1 V_141 ,
struct V_14 * V_15 ,
struct V_86 * V_87 )
{
struct V_185 * V_54 = V_15 -> V_54 ;
struct V_1 * V_2 = V_15 -> V_2 ;
int V_204 ;
V_204 = F_5 ( V_30 -> V_205 ) >> 24 ;
if ( V_204 > 1 ) {
F_74 ( V_87 , V_30 , V_141 ) ;
F_47 ( V_87 ) -> V_206 = F_52 ( V_141 , V_204 ) ;
V_15 -> V_21 . V_207 += V_204 - 1 ;
V_15 -> V_21 . V_208 ++ ;
V_15 -> V_21 . V_209 += V_141 ;
}
if ( F_10 ( F_1 ( V_2 ) ) )
F_87 ( V_2 , F_88 ( V_30 ) , F_89 ( V_87 ) ) ;
F_90 ( V_87 , V_15 -> V_81 ) ;
if ( F_37 ( V_54 -> V_187 & V_210 ) )
F_80 ( V_30 , V_87 ) ;
if ( F_91 ( V_30 ) )
F_92 ( V_87 , F_77 ( V_211 ) ,
F_6 ( V_30 -> V_212 ) ) ;
V_87 -> V_213 = F_5 ( V_30 -> V_214 ) & V_215 ;
F_83 ( V_54 , V_30 , V_15 , V_87 , ! ! V_204 ) ;
V_87 -> V_216 = F_93 ( V_87 , V_54 ) ;
}
static inline void F_94 ( struct V_14 * V_15 ,
struct V_13 * V_30 ,
T_1 V_141 ,
struct V_86 * V_87 )
{
V_15 -> V_21 . V_207 ++ ;
V_15 -> V_21 . V_217 += V_141 ;
F_86 ( V_30 , V_141 , V_15 , V_87 ) ;
}
static inline void F_95 ( struct V_105 * V_106 )
{
struct V_109 * V_11 = & V_106 -> V_11 ;
struct V_218 * V_80 ;
T_3 V_113 = ( V_106 -> V_114 - V_219 ) & V_11 -> V_12 ;
V_80 = F_54 ( V_11 , V_113 ) ;
V_80 -> V_120 . V_220 = V_221 ;
F_56 ( V_106 , & V_80 -> V_120 , 0 ) ;
}
static inline bool F_96 ( struct V_14 * V_15 ,
struct V_57 * V_82 ,
const struct V_222 * V_223 )
{
struct V_105 * V_106 = & V_15 -> V_107 -> V_224 ;
struct V_109 * V_11 = & V_106 -> V_11 ;
T_3 V_113 = V_106 -> V_114 & V_11 -> V_12 ;
struct V_218 * V_80 = F_54 ( V_11 , V_113 ) ;
struct V_225 * V_89 = & V_106 -> V_116 . V_223 . V_226 [ V_113 ] ;
struct V_227 * V_228 = & V_80 -> V_120 ;
struct V_229 * V_230 = & V_80 -> V_143 ;
struct V_231 * V_232 ;
T_2 V_233 = V_234 ;
T_6 V_235 = V_223 -> V_9 - V_223 -> V_236 ;
T_7 V_237 = V_82 -> V_72 + V_235 ;
unsigned int V_238 = V_223 -> V_239 - V_223 -> V_9 ;
if ( F_10 ( V_238 < V_240 ||
F_97 ( V_15 -> V_54 -> V_241 ) < V_238 ) ) {
V_15 -> V_21 . V_242 ++ ;
F_36 ( V_15 , V_82 , true ) ;
return false ;
}
if ( F_10 ( ! F_98 ( V_106 , V_219 ) ) ) {
if ( V_106 -> V_116 . V_223 . V_243 ) {
F_95 ( V_106 ) ;
V_106 -> V_116 . V_223 . V_243 = false ;
}
V_15 -> V_21 . V_244 ++ ;
F_36 ( V_15 , V_82 , true ) ;
return false ;
}
F_29 ( V_106 -> V_71 , V_237 , V_238 ,
V_245 ) ;
memset ( V_80 , 0 , sizeof( * V_80 ) ) ;
V_232 = (struct V_231 * ) V_230 + 1 ;
if ( V_106 -> V_246 != V_247 ) {
memcpy ( V_230 -> V_248 . V_249 , V_223 -> V_9 , V_240 ) ;
V_230 -> V_248 . V_250 = F_12 ( V_240 ) ;
V_238 -= V_240 ;
V_237 += V_240 ;
V_233 += V_251 ;
V_232 ++ ;
}
V_232 -> V_72 = F_40 ( V_237 ) ;
V_232 -> V_252 = F_55 ( V_238 ) ;
V_232 -> V_253 = V_106 -> V_254 ;
V_228 -> V_121 = F_55 ( ( V_106 -> V_114 << 8 ) | V_255 ) ;
V_228 -> V_256 = F_55 ( ( V_106 -> V_257 << 8 ) | V_233 ) ;
V_106 -> V_116 . V_223 . V_82 [ V_113 ] = * V_82 ;
V_89 -> V_118 = V_255 ;
V_89 -> V_111 = V_219 ;
V_106 -> V_114 += V_219 ;
V_106 -> V_116 . V_223 . V_243 = true ;
V_15 -> V_21 . V_258 ++ ;
return true ;
}
static inline int F_99 ( struct V_14 * V_15 ,
struct V_57 * V_82 ,
void * V_259 , T_3 * V_83 , T_1 * V_92 )
{
const struct V_260 * V_261 = F_100 ( V_15 -> V_262 ) ;
struct V_222 V_223 ;
T_1 V_263 ;
if ( ! V_261 )
return false ;
V_223 . V_9 = V_259 + * V_83 ;
V_223 . V_239 = V_223 . V_9 + * V_92 ;
V_223 . V_236 = V_259 ;
V_263 = F_101 ( V_261 , & V_223 ) ;
switch ( V_263 ) {
case V_264 :
* V_83 = V_223 . V_9 - V_223 . V_236 ;
* V_92 = V_223 . V_239 - V_223 . V_9 ;
return false ;
case V_265 :
if ( F_10 ( ! F_96 ( V_15 , V_82 , & V_223 ) ) )
F_102 ( V_15 -> V_54 , V_261 , V_263 ) ;
return true ;
default:
F_103 ( V_263 ) ;
case V_266 :
F_102 ( V_15 -> V_54 , V_261 , V_263 ) ;
case V_267 :
V_15 -> V_21 . V_242 ++ ;
F_36 ( V_15 , V_82 , true ) ;
return true ;
}
}
static inline
struct V_86 * F_104 ( struct V_14 * V_15 , struct V_13 * V_30 ,
T_3 V_20 , T_1 V_141 )
{
struct V_57 * V_82 ;
struct V_86 * V_87 ;
void * V_259 , * V_9 ;
T_3 V_83 = V_15 -> V_83 ;
bool V_268 ;
V_82 = & V_15 -> V_58 [ V_20 ] ;
V_259 = F_50 ( V_82 -> V_67 ) ;
V_9 = V_259 + V_83 ;
F_105 ( V_15 -> V_71 ,
V_82 -> V_72 ,
V_83 ,
V_15 -> V_74 . V_269 ,
V_73 ) ;
F_106 ( V_9 ) ;
if ( F_10 ( ( V_30 -> V_26 >> 4 ) != V_270 ) ) {
V_15 -> V_21 . V_271 ++ ;
F_36 ( V_15 , V_82 , true ) ;
return NULL ;
}
F_107 () ;
V_268 = F_99 ( V_15 , V_82 , V_259 , & V_83 , & V_141 ) ;
F_108 () ;
if ( V_268 )
return NULL ;
V_87 = F_109 ( V_259 , F_30 ( V_15 ) ) ;
if ( F_10 ( ! V_87 ) ) {
V_15 -> V_21 . V_140 ++ ;
F_36 ( V_15 , V_82 , true ) ;
return NULL ;
}
F_110 ( V_82 -> V_67 ) ;
F_36 ( V_15 , V_82 , true ) ;
F_111 ( V_87 , V_83 ) ;
F_112 ( V_87 , V_141 ) ;
return V_87 ;
}
void F_113 ( struct V_14 * V_15 , struct V_13 * V_30 )
{
struct V_79 * V_80 ;
T_5 V_272 ;
struct V_86 * V_87 ;
T_3 V_20 ;
T_1 V_141 ;
V_272 = V_30 -> V_20 ;
V_20 = F_6 ( V_272 ) ;
V_80 = F_63 ( & V_15 -> V_11 , V_20 ) ;
V_141 = F_5 ( V_30 -> V_18 ) ;
V_87 = F_104 ( V_15 , V_30 , V_20 , V_141 ) ;
if ( ! V_87 )
goto V_273;
F_94 ( V_15 , V_30 , V_141 , V_87 ) ;
F_114 ( V_15 -> V_7 . V_274 , V_87 ) ;
V_273:
F_115 ( & V_15 -> V_11 , V_272 ,
& V_80 -> V_136 . V_137 ) ;
}
void F_116 ( struct V_14 * V_15 , struct V_13 * V_30 )
{
struct V_185 * V_54 = V_15 -> V_54 ;
struct V_45 * V_46 = F_117 ( V_54 ) ;
struct V_275 * V_276 = V_46 -> V_277 ;
struct V_79 * V_80 ;
struct V_86 * V_87 ;
T_5 V_272 ;
T_3 V_20 ;
T_1 V_141 ;
V_272 = V_30 -> V_20 ;
V_20 = F_6 ( V_272 ) ;
V_80 = F_63 ( & V_15 -> V_11 , V_20 ) ;
V_141 = F_5 ( V_30 -> V_18 ) ;
V_87 = F_104 ( V_15 , V_30 , V_20 , V_141 ) ;
if ( ! V_87 )
goto V_273;
F_94 ( V_15 , V_30 , V_141 , V_87 ) ;
if ( V_276 -> V_278 && F_118 ( V_87 ) )
F_119 ( V_87 ) ;
F_114 ( V_15 -> V_7 . V_274 , V_87 ) ;
V_273:
F_115 ( & V_15 -> V_11 , V_272 ,
& V_80 -> V_136 . V_137 ) ;
}
static inline void F_120 ( struct V_14 * V_15 ,
struct V_13 * V_30 ,
struct V_88 * V_89 ,
T_1 V_141 ,
struct V_86 * V_87 )
{
T_3 V_279 = F_121 ( V_30 ) ;
T_1 V_280 = V_279 * V_15 -> V_94 ;
T_1 V_281 = V_280 & ( V_102 - 1 ) ;
T_1 V_90 = V_280 >> V_125 ;
T_1 V_282 = V_90 ;
T_3 V_100 = F_9 ( T_3 , V_283 , V_141 ) ;
T_1 V_91 = V_281 + V_100 ;
T_3 V_18 = V_141 - V_100 ;
if ( F_10 ( V_91 >= V_102 ) ) {
V_90 ++ ;
V_91 -= V_102 ;
}
while ( V_18 ) {
T_1 V_284 =
F_9 ( T_1 , V_102 - V_91 , V_18 ) ;
F_43 ( V_15 , V_87 , V_89 , V_90 , V_91 ,
V_284 ) ;
V_18 -= V_284 ;
V_91 = 0 ;
V_90 ++ ;
}
F_48 ( V_15 -> V_71 , V_87 , V_89 , V_282 ,
V_281 , V_100 ) ;
V_87 -> V_63 += V_100 ;
V_87 -> V_92 += V_100 ;
}
void F_122 ( struct V_14 * V_15 , struct V_13 * V_30 )
{
T_3 V_285 = F_13 ( V_30 ) ;
T_3 V_286 = F_6 ( V_30 -> V_286 ) ;
struct V_88 * V_89 = & V_15 -> V_103 . V_104 [ V_286 ] ;
struct V_79 * V_80 = F_63 ( & V_15 -> V_11 , V_286 ) ;
struct V_86 * V_87 ;
T_3 V_141 ;
V_89 -> V_132 += V_285 ;
if ( F_10 ( ( V_30 -> V_26 >> 4 ) != V_270 ) ) {
V_15 -> V_21 . V_271 ++ ;
goto V_287;
}
if ( F_10 ( F_123 ( V_30 ) ) ) {
V_15 -> V_21 . V_288 ++ ;
goto V_287;
}
V_87 = F_124 ( V_15 -> V_7 . V_274 ,
F_44 ( V_283 ,
sizeof( long ) ) ) ;
if ( F_10 ( ! V_87 ) ) {
V_15 -> V_21 . V_140 ++ ;
goto V_287;
}
F_106 ( V_87 -> V_9 ) ;
V_141 = F_125 ( V_30 ) ;
F_120 ( V_15 , V_30 , V_89 , V_141 , V_87 ) ;
F_94 ( V_15 , V_30 , V_141 , V_87 ) ;
F_114 ( V_15 -> V_7 . V_274 , V_87 ) ;
V_287:
if ( F_37 ( V_89 -> V_132 < V_15 -> V_84 ) )
return;
F_61 ( V_15 , V_89 ) ;
F_115 ( & V_15 -> V_11 , V_30 -> V_286 , & V_80 -> V_136 . V_137 ) ;
}
int F_126 ( struct V_6 * V_7 , int V_289 )
{
struct V_14 * V_15 = F_127 ( V_7 , struct V_14 , V_7 ) ;
struct V_105 * V_224 = & V_15 -> V_107 -> V_224 ;
int V_290 = 0 ;
if ( F_10 ( ! F_20 ( V_135 , & V_15 -> V_53 ) ) )
return 0 ;
if ( V_7 -> V_17 )
V_290 += F_15 ( V_15 , V_7 , 0 , V_289 ) ;
for (; V_290 < V_289 ; V_290 ++ ) {
struct V_13 * V_30 = F_128 ( V_7 ) ;
if ( ! V_30 )
break;
if ( F_129 ( V_30 ) == V_291 ) {
V_290 +=
F_16 ( V_15 , V_7 ,
V_289 - V_290 ) ;
continue;
}
F_130 ( & V_7 -> V_11 ) ;
V_15 -> V_43 ( V_15 , V_30 ) ;
}
if ( V_224 -> V_116 . V_223 . V_243 ) {
F_95 ( V_224 ) ;
V_224 -> V_116 . V_223 . V_243 = false ;
}
F_131 ( & V_7 -> V_11 ) ;
F_132 () ;
return V_290 ;
}

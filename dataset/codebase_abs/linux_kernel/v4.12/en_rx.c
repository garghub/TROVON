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
static inline bool F_17 ( struct V_14 * V_15 ,
struct V_45 * V_46 )
{
struct V_47 * V_48 = & V_15 -> V_49 ;
T_1 V_50 = ( V_48 -> V_51 + 1 ) & ( V_52 - 1 ) ;
if ( V_50 == V_48 -> V_53 ) {
V_15 -> V_21 . V_54 ++ ;
return false ;
}
if ( F_10 ( F_18 ( V_46 -> V_55 ) ) )
return false ;
V_48 -> V_49 [ V_48 -> V_51 ] = * V_46 ;
V_48 -> V_51 = V_50 ;
return true ;
}
static inline bool F_19 ( struct V_14 * V_15 ,
struct V_45 * V_46 )
{
struct V_47 * V_48 = & V_15 -> V_49 ;
if ( F_10 ( V_48 -> V_53 == V_48 -> V_51 ) ) {
V_15 -> V_21 . V_56 ++ ;
return false ;
}
if ( F_20 ( V_48 -> V_49 [ V_48 -> V_53 ] . V_55 ) != 1 ) {
V_15 -> V_21 . V_57 ++ ;
return false ;
}
* V_46 = V_48 -> V_49 [ V_48 -> V_53 ] ;
V_48 -> V_53 = ( V_48 -> V_53 + 1 ) & ( V_52 - 1 ) ;
V_15 -> V_21 . V_58 ++ ;
F_21 ( V_15 -> V_59 , V_46 -> V_60 ,
F_22 ( V_15 ) ,
V_61 ) ;
return true ;
}
static inline int F_23 ( struct V_14 * V_15 ,
struct V_45 * V_46 )
{
struct V_55 * V_55 ;
if ( F_19 ( V_15 , V_46 ) )
return 0 ;
V_55 = F_24 ( V_15 -> V_62 . V_63 ) ;
if ( F_10 ( ! V_55 ) )
return - V_64 ;
V_46 -> V_55 = V_55 ;
V_46 -> V_60 = F_25 ( V_15 -> V_59 , V_55 , 0 ,
F_22 ( V_15 ) , V_15 -> V_62 . V_65 ) ;
if ( F_10 ( F_26 ( V_15 -> V_59 , V_46 -> V_60 ) ) ) {
F_27 ( V_55 ) ;
return - V_64 ;
}
return 0 ;
}
void F_28 ( struct V_14 * V_15 , struct V_45 * V_46 ,
bool V_66 )
{
if ( F_29 ( V_66 ) && F_17 ( V_15 , V_46 ) )
return;
F_30 ( V_15 -> V_59 , V_46 -> V_60 , F_22 ( V_15 ) ,
V_15 -> V_62 . V_65 ) ;
F_27 ( V_46 -> V_55 ) ;
}
int F_31 ( struct V_14 * V_15 , struct V_67 * V_68 , T_3 V_69 )
{
struct V_45 * V_70 = & V_15 -> V_46 [ V_69 ] ;
if ( F_10 ( F_23 ( V_15 , V_70 ) ) )
return - V_64 ;
V_68 -> V_9 . V_60 = F_32 ( V_70 -> V_60 + V_15 -> V_71 ) ;
return 0 ;
}
void F_33 ( struct V_14 * V_15 , T_3 V_69 )
{
struct V_45 * V_70 = & V_15 -> V_46 [ V_69 ] ;
F_28 ( V_15 , V_70 , true ) ;
}
static inline int F_34 ( struct V_14 * V_15 )
{
return V_15 -> V_72 >> V_73 ;
}
static inline void F_35 ( struct V_14 * V_15 ,
struct V_74 * V_75 ,
struct V_76 * V_77 ,
T_1 V_78 , T_1 V_79 ,
T_1 V_80 )
{
unsigned int V_81 = F_36 ( V_80 , V_15 -> V_82 ) ;
F_37 ( V_15 -> V_59 ,
V_77 -> V_83 . V_46 [ V_78 ] . V_60 + V_79 ,
V_80 , V_61 ) ;
V_77 -> V_84 [ V_78 ] ++ ;
F_38 ( V_75 , F_39 ( V_75 ) -> V_85 ,
V_77 -> V_83 . V_46 [ V_78 ] . V_55 , V_79 ,
V_80 , V_81 ) ;
}
static inline void
F_40 ( struct V_86 * V_59 ,
struct V_74 * V_75 ,
struct V_76 * V_77 ,
T_1 V_78 , T_1 V_87 ,
T_1 V_88 )
{
T_3 V_89 = F_9 ( T_1 , V_88 , V_90 - V_87 ) ;
struct V_45 * V_46 = & V_77 -> V_83 . V_46 [ V_78 ] ;
unsigned int V_80 ;
V_80 = F_36 ( V_89 , sizeof( long ) ) ;
F_37 ( V_59 , V_46 -> V_60 + V_87 , V_80 ,
V_61 ) ;
F_41 ( V_75 , 0 ,
F_42 ( V_46 -> V_55 ) + V_87 ,
V_80 ) ;
if ( F_10 ( V_87 + V_88 > V_90 ) ) {
V_46 ++ ;
V_89 = V_80 ;
V_80 = F_36 ( V_88 - V_89 , sizeof( long ) ) ;
F_37 ( V_59 , V_46 -> V_60 , V_80 ,
V_61 ) ;
F_41 ( V_75 , V_89 ,
F_42 ( V_46 -> V_55 ) ,
V_80 ) ;
}
}
static inline void F_43 ( struct V_14 * V_15 , T_3 V_69 )
{
struct V_76 * V_77 = & V_15 -> V_91 . V_92 [ V_69 ] ;
struct V_93 * V_94 = & V_15 -> V_95 -> V_96 ;
struct V_97 * V_11 = & V_94 -> V_11 ;
struct V_98 * V_68 ;
T_2 V_99 = F_44 ( sizeof( * V_68 ) , V_100 ) ;
T_3 V_101 ;
while ( ( V_101 = ( V_94 -> V_102 & V_11 -> V_12 ) ) > V_94 -> V_103 ) {
V_94 -> V_104 . V_105 [ V_101 ] . V_106 = V_107 ;
V_94 -> V_104 . V_105 [ V_101 ] . V_99 = 1 ;
F_45 ( V_11 , V_94 -> V_108 , & V_94 -> V_102 ) ;
}
V_68 = F_46 ( V_11 , V_101 ) ;
memcpy ( V_68 , & V_77 -> V_83 . V_68 , sizeof( * V_68 ) ) ;
V_68 -> V_109 . V_110 =
F_47 ( ( V_94 -> V_102 << V_111 ) |
V_112 ) ;
V_94 -> V_104 . V_105 [ V_101 ] . V_106 = V_112 ;
V_94 -> V_104 . V_105 [ V_101 ] . V_99 = V_99 ;
V_94 -> V_102 += V_99 ;
F_48 ( & V_94 -> V_11 , V_94 -> V_102 , V_94 -> V_113 , & V_68 -> V_109 ) ;
}
static int F_49 ( struct V_14 * V_15 ,
struct V_67 * V_68 ,
T_3 V_69 )
{
struct V_76 * V_77 = & V_15 -> V_91 . V_92 [ V_69 ] ;
T_4 V_114 = ( T_4 ) F_50 ( V_15 , V_69 ) << V_115 ;
int V_116 = F_34 ( V_15 ) ;
int V_117 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_118 ; V_41 ++ ) {
struct V_45 * V_46 = & V_77 -> V_83 . V_46 [ V_41 ] ;
V_117 = F_23 ( V_15 , V_46 ) ;
if ( F_10 ( V_117 ) )
goto V_119;
V_77 -> V_83 . V_120 [ V_41 ] = F_32 ( V_46 -> V_60 | V_121 ) ;
F_51 ( V_46 -> V_55 , V_116 ) ;
V_77 -> V_84 [ V_41 ] = 0 ;
}
V_77 -> V_122 = 0 ;
V_68 -> V_9 . V_60 = F_32 ( V_114 ) ;
return 0 ;
V_119:
while ( -- V_41 >= 0 ) {
struct V_45 * V_46 = & V_77 -> V_83 . V_46 [ V_41 ] ;
F_52 ( V_46 -> V_55 , V_116 ) ;
F_28 ( V_15 , V_46 , true ) ;
}
return V_117 ;
}
void F_53 ( struct V_14 * V_15 , struct V_76 * V_77 )
{
int V_116 = F_34 ( V_15 ) ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_118 ; V_41 ++ ) {
struct V_45 * V_46 = & V_77 -> V_83 . V_46 [ V_41 ] ;
F_52 ( V_46 -> V_55 , V_116 - V_77 -> V_84 [ V_41 ] ) ;
F_28 ( V_15 , V_46 , true ) ;
}
}
void F_54 ( struct V_14 * V_15 )
{
struct V_123 * V_11 = & V_15 -> V_11 ;
struct V_67 * V_68 = F_55 ( V_11 , V_11 -> V_53 ) ;
F_56 ( V_124 , & V_15 -> V_125 ) ;
if ( F_10 ( ! F_57 ( V_126 , & V_15 -> V_125 ) ) ) {
F_53 ( V_15 , & V_15 -> V_91 . V_92 [ V_11 -> V_53 ] ) ;
return;
}
F_58 ( V_11 , F_6 ( V_68 -> V_127 . V_128 ) ) ;
F_59 () ;
F_60 ( V_11 ) ;
}
int F_61 ( struct V_14 * V_15 , struct V_67 * V_68 , T_3 V_69 )
{
int V_117 ;
V_117 = F_49 ( V_15 , V_68 , V_69 ) ;
if ( F_10 ( V_117 ) )
return V_117 ;
F_62 ( V_124 , & V_15 -> V_125 ) ;
F_43 ( V_15 , V_69 ) ;
return - V_129 ;
}
void F_63 ( struct V_14 * V_15 , T_3 V_69 )
{
struct V_76 * V_77 = & V_15 -> V_91 . V_92 [ V_69 ] ;
F_53 ( V_15 , V_77 ) ;
}
bool F_64 ( struct V_14 * V_15 )
{
struct V_123 * V_11 = & V_15 -> V_11 ;
if ( F_10 ( F_65 ( V_15 ) ) )
return false ;
while ( ! F_66 ( V_11 ) ) {
struct V_67 * V_68 = F_55 ( V_11 , V_11 -> V_53 ) ;
int V_117 ;
V_117 = V_15 -> V_130 ( V_15 , V_68 , V_11 -> V_53 ) ;
if ( V_117 == - V_129 )
return true ;
if ( F_10 ( V_117 ) ) {
V_15 -> V_21 . V_131 ++ ;
break;
}
F_58 ( V_11 , F_6 ( V_68 -> V_127 . V_128 ) ) ;
}
F_59 () ;
F_60 ( V_11 ) ;
return ! F_66 ( V_11 ) ;
}
static void F_67 ( struct V_74 * V_75 , struct V_13 * V_30 ,
T_1 V_132 )
{
struct V_133 * V_134 = (struct V_133 * ) ( V_75 -> V_9 ) ;
struct V_135 * V_136 ;
struct V_137 * V_138 ;
struct V_139 * V_140 ;
int V_141 = 0 ;
T_5 V_142 ;
T_3 V_143 ;
T_2 V_144 = F_68 ( V_30 ) ;
int V_145 = ( ( V_146 == V_144 ) ||
( V_147 == V_144 ) ) ;
V_75 -> V_148 = V_149 ;
V_142 = F_69 ( V_75 , V_134 -> V_150 , & V_141 ) ;
V_136 = (struct V_135 * ) ( V_75 -> V_9 + V_141 ) ;
V_138 = (struct V_137 * ) ( V_75 -> V_9 + V_141 ) ;
V_143 = V_132 - V_141 ;
if ( V_142 == F_70 ( V_151 ) ) {
V_140 = (struct V_139 * ) ( V_75 -> V_9 + V_141 +
sizeof( struct V_135 ) ) ;
V_138 = NULL ;
F_39 ( V_75 ) -> V_152 = V_153 ;
} else {
V_140 = (struct V_139 * ) ( V_75 -> V_9 + V_141 +
sizeof( struct V_137 ) ) ;
V_136 = NULL ;
F_39 ( V_75 ) -> V_152 = V_154 ;
}
if ( F_71 ( V_30 ) )
V_140 -> V_155 = 1 ;
if ( V_145 ) {
V_140 -> V_156 = 1 ;
V_140 -> V_157 = V_30 -> V_158 ;
V_140 -> V_159 = V_30 -> V_160 ;
}
if ( V_136 ) {
V_136 -> V_161 = V_30 -> V_162 ;
V_136 -> V_143 = F_12 ( V_143 ) ;
V_136 -> V_163 = 0 ;
V_136 -> V_163 = F_72 ( ( unsigned char * ) V_136 ,
V_136 -> V_164 ) ;
} else {
V_138 -> V_165 = V_30 -> V_162 ;
V_138 -> V_166 = F_12 ( V_143 -
sizeof( struct V_137 ) ) ;
}
}
static inline void F_73 ( struct V_13 * V_30 ,
struct V_74 * V_75 )
{
T_2 V_167 = V_30 -> V_35 ;
int V_168 = ( V_167 & V_169 ) ? V_170 :
( V_167 & V_171 ) ? V_172 :
V_173 ;
F_74 ( V_75 , F_5 ( V_30 -> V_36 ) , V_168 ) ;
}
static inline bool F_75 ( struct V_74 * V_75 )
{
T_5 V_174 = ( (struct V_133 * ) V_75 -> V_9 ) -> V_150 ;
return ( V_174 == F_70 ( V_151 ) || V_174 == F_70 ( V_175 ) ) ;
}
static inline void F_76 ( struct V_176 * V_177 ,
struct V_13 * V_30 ,
struct V_14 * V_15 ,
struct V_74 * V_75 ,
bool V_178 )
{
if ( F_10 ( ! ( V_177 -> V_179 & V_180 ) ) )
goto V_181;
if ( V_178 ) {
V_75 -> V_182 = V_183 ;
return;
}
if ( F_75 ( V_75 ) ) {
V_75 -> V_182 = V_184 ;
V_75 -> V_185 = F_77 ( ( V_186 V_187 ) V_30 -> V_31 ) ;
V_15 -> V_21 . V_188 ++ ;
return;
}
if ( F_29 ( ( V_30 -> V_189 & V_190 ) &&
( V_30 -> V_189 & V_191 ) ) ) {
V_75 -> V_182 = V_183 ;
if ( F_78 ( V_30 ) ) {
V_75 -> V_192 = 1 ;
V_75 -> V_193 = 1 ;
V_15 -> V_21 . V_194 ++ ;
}
return;
}
V_181:
V_75 -> V_182 = V_195 ;
V_15 -> V_21 . V_181 ++ ;
}
static inline void F_79 ( struct V_13 * V_30 ,
T_1 V_132 ,
struct V_14 * V_15 ,
struct V_74 * V_75 )
{
struct V_176 * V_177 = V_15 -> V_177 ;
struct V_1 * V_2 = V_15 -> V_2 ;
int V_196 ;
V_196 = F_5 ( V_30 -> V_197 ) >> 24 ;
if ( V_196 > 1 ) {
F_67 ( V_75 , V_30 , V_132 ) ;
F_39 ( V_75 ) -> V_198 = F_44 ( V_132 , V_196 ) ;
V_15 -> V_21 . V_199 += V_196 - 1 ;
V_15 -> V_21 . V_200 ++ ;
V_15 -> V_21 . V_201 += V_132 ;
}
if ( F_10 ( F_1 ( V_2 ) ) )
F_80 ( V_2 , F_81 ( V_30 ) , F_82 ( V_75 ) ) ;
F_83 ( V_75 , V_15 -> V_69 ) ;
if ( F_29 ( V_177 -> V_179 & V_202 ) )
F_73 ( V_30 , V_75 ) ;
if ( F_84 ( V_30 ) )
F_85 ( V_75 , F_70 ( V_203 ) ,
F_6 ( V_30 -> V_204 ) ) ;
V_75 -> V_205 = F_5 ( V_30 -> V_206 ) & V_207 ;
F_76 ( V_177 , V_30 , V_15 , V_75 , ! ! V_196 ) ;
V_75 -> V_208 = F_86 ( V_75 , V_177 ) ;
}
static inline void F_87 ( struct V_14 * V_15 ,
struct V_13 * V_30 ,
T_1 V_132 ,
struct V_74 * V_75 )
{
V_15 -> V_21 . V_199 ++ ;
V_15 -> V_21 . V_209 += V_132 ;
F_79 ( V_30 , V_132 , V_15 , V_75 ) ;
}
static inline void F_88 ( struct V_210 * V_94 )
{
struct V_97 * V_11 = & V_94 -> V_11 ;
struct V_211 * V_68 ;
T_3 V_101 = ( V_94 -> V_102 - 1 ) & V_11 -> V_12 ;
V_68 = F_46 ( V_11 , V_101 ) ;
F_48 ( V_11 , V_94 -> V_102 , V_94 -> V_113 , & V_68 -> V_109 ) ;
}
static inline bool F_89 ( struct V_14 * V_15 ,
struct V_45 * V_70 ,
const struct V_212 * V_213 )
{
struct V_210 * V_94 = & V_15 -> V_214 ;
struct V_97 * V_11 = & V_94 -> V_11 ;
T_3 V_101 = V_94 -> V_102 & V_11 -> V_12 ;
struct V_211 * V_68 = F_46 ( V_11 , V_101 ) ;
struct V_215 * V_216 = & V_68 -> V_109 ;
struct V_217 * V_218 = & V_68 -> V_134 ;
struct V_219 * V_220 ;
T_6 V_221 = V_213 -> V_9 - V_213 -> V_222 ;
T_7 V_223 = V_70 -> V_60 + V_221 ;
unsigned int V_224 = V_213 -> V_225 - V_213 -> V_9 ;
F_90 ( V_68 ) ;
if ( F_10 ( V_224 < V_226 ||
F_91 ( V_15 -> V_177 -> V_227 ) < V_224 ) ) {
V_15 -> V_21 . V_228 ++ ;
F_28 ( V_15 , V_70 , true ) ;
return false ;
}
if ( F_10 ( ! F_92 ( V_11 , V_94 -> V_39 , V_94 -> V_102 , 1 ) ) ) {
if ( V_94 -> V_104 . V_229 ) {
F_88 ( V_94 ) ;
V_94 -> V_104 . V_229 = false ;
}
V_15 -> V_21 . V_230 ++ ;
F_28 ( V_15 , V_70 , true ) ;
return false ;
}
F_21 ( V_94 -> V_59 , V_223 , V_224 , V_231 ) ;
V_216 -> V_232 = 0 ;
V_220 = (struct V_219 * ) V_218 + 1 ;
if ( V_94 -> V_233 != V_234 ) {
memcpy ( V_218 -> V_235 . V_236 , V_213 -> V_9 , V_226 ) ;
V_218 -> V_235 . V_237 = F_12 ( V_226 ) ;
V_224 -= V_226 ;
V_223 += V_226 ;
V_220 ++ ;
}
V_220 -> V_60 = F_32 ( V_223 ) ;
V_220 -> V_238 = F_47 ( V_224 ) ;
V_216 -> V_110 = F_47 ( ( V_94 -> V_102 << 8 ) | V_239 ) ;
V_94 -> V_104 . V_70 [ V_101 ] = * V_70 ;
V_94 -> V_102 ++ ;
V_94 -> V_104 . V_229 = true ;
V_15 -> V_21 . V_240 ++ ;
return true ;
}
static inline int F_93 ( struct V_14 * V_15 ,
struct V_45 * V_70 ,
void * V_241 , T_3 * V_71 , T_1 * V_80 )
{
const struct V_242 * V_243 = F_94 ( V_15 -> V_244 ) ;
struct V_212 V_213 ;
T_1 V_245 ;
if ( ! V_243 )
return false ;
V_213 . V_9 = V_241 + * V_71 ;
V_213 . V_225 = V_213 . V_9 + * V_80 ;
V_213 . V_222 = V_241 ;
V_245 = F_95 ( V_243 , & V_213 ) ;
switch ( V_245 ) {
case V_246 :
* V_71 = V_213 . V_9 - V_213 . V_222 ;
* V_80 = V_213 . V_225 - V_213 . V_9 ;
return false ;
case V_247 :
if ( F_10 ( ! F_89 ( V_15 , V_70 , & V_213 ) ) )
F_96 ( V_15 -> V_177 , V_243 , V_245 ) ;
return true ;
default:
F_97 ( V_245 ) ;
case V_248 :
F_96 ( V_15 -> V_177 , V_243 , V_245 ) ;
case V_249 :
V_15 -> V_21 . V_228 ++ ;
F_28 ( V_15 , V_70 , true ) ;
return true ;
}
}
static inline
struct V_74 * F_98 ( struct V_14 * V_15 , struct V_13 * V_30 ,
T_3 V_20 , T_1 V_132 )
{
struct V_45 * V_70 ;
struct V_74 * V_75 ;
void * V_241 , * V_9 ;
T_3 V_71 = V_15 -> V_71 ;
bool V_250 ;
V_70 = & V_15 -> V_46 [ V_20 ] ;
V_241 = F_42 ( V_70 -> V_55 ) ;
V_9 = V_241 + V_71 ;
F_99 ( V_15 -> V_59 ,
V_70 -> V_60 ,
V_71 ,
V_15 -> V_62 . V_251 ,
V_61 ) ;
F_100 ( V_9 ) ;
if ( F_10 ( ( V_30 -> V_26 >> 4 ) != V_252 ) ) {
V_15 -> V_21 . V_253 ++ ;
F_28 ( V_15 , V_70 , true ) ;
return NULL ;
}
F_101 () ;
V_250 = F_93 ( V_15 , V_70 , V_241 , & V_71 , & V_132 ) ;
F_102 () ;
if ( V_250 )
return NULL ;
V_75 = F_103 ( V_241 , F_22 ( V_15 ) ) ;
if ( F_10 ( ! V_75 ) ) {
V_15 -> V_21 . V_131 ++ ;
F_28 ( V_15 , V_70 , true ) ;
return NULL ;
}
F_104 ( V_70 -> V_55 ) ;
F_28 ( V_15 , V_70 , true ) ;
F_105 ( V_75 , V_71 ) ;
F_106 ( V_75 , V_132 ) ;
return V_75 ;
}
void F_107 ( struct V_14 * V_15 , struct V_13 * V_30 )
{
struct V_67 * V_68 ;
T_5 V_254 ;
struct V_74 * V_75 ;
T_3 V_20 ;
T_1 V_132 ;
V_254 = V_30 -> V_20 ;
V_20 = F_6 ( V_254 ) ;
V_68 = F_55 ( & V_15 -> V_11 , V_20 ) ;
V_132 = F_5 ( V_30 -> V_18 ) ;
V_75 = F_98 ( V_15 , V_30 , V_20 , V_132 ) ;
if ( ! V_75 )
goto V_255;
F_87 ( V_15 , V_30 , V_132 , V_75 ) ;
F_108 ( V_15 -> V_7 . V_256 , V_75 ) ;
V_255:
F_109 ( & V_15 -> V_11 , V_254 ,
& V_68 -> V_127 . V_128 ) ;
}
void F_110 ( struct V_14 * V_15 , struct V_13 * V_30 )
{
struct V_176 * V_177 = V_15 -> V_177 ;
struct V_257 * V_258 = F_111 ( V_177 ) ;
struct V_259 * V_260 = V_258 -> V_261 ;
struct V_262 * V_263 = V_260 -> V_263 ;
struct V_67 * V_68 ;
struct V_74 * V_75 ;
T_5 V_254 ;
T_3 V_20 ;
T_1 V_132 ;
V_254 = V_30 -> V_20 ;
V_20 = F_6 ( V_254 ) ;
V_68 = F_55 ( & V_15 -> V_11 , V_20 ) ;
V_132 = F_5 ( V_30 -> V_18 ) ;
V_75 = F_98 ( V_15 , V_30 , V_20 , V_132 ) ;
if ( ! V_75 )
goto V_255;
F_87 ( V_15 , V_30 , V_132 , V_75 ) ;
if ( V_263 -> V_264 && F_112 ( V_75 ) )
F_113 ( V_75 ) ;
F_108 ( V_15 -> V_7 . V_256 , V_75 ) ;
V_255:
F_109 ( & V_15 -> V_11 , V_254 ,
& V_68 -> V_127 . V_128 ) ;
}
static inline void F_114 ( struct V_14 * V_15 ,
struct V_13 * V_30 ,
struct V_76 * V_77 ,
T_1 V_132 ,
struct V_74 * V_75 )
{
T_3 V_265 = F_115 ( V_30 ) ;
T_1 V_266 = V_265 * V_15 -> V_82 ;
T_1 V_267 = V_266 & ( V_90 - 1 ) ;
T_1 V_78 = V_266 >> V_115 ;
T_1 V_268 = V_78 ;
T_3 V_88 = F_9 ( T_3 , V_269 , V_132 ) ;
T_1 V_79 = V_267 + V_88 ;
T_3 V_18 = V_132 - V_88 ;
if ( F_10 ( V_79 >= V_90 ) ) {
V_78 ++ ;
V_79 -= V_90 ;
}
while ( V_18 ) {
T_1 V_270 =
F_9 ( T_1 , V_90 - V_79 , V_18 ) ;
F_35 ( V_15 , V_75 , V_77 , V_78 , V_79 ,
V_270 ) ;
V_18 -= V_270 ;
V_79 = 0 ;
V_78 ++ ;
}
F_40 ( V_15 -> V_59 , V_75 , V_77 , V_268 ,
V_267 , V_88 ) ;
V_75 -> V_51 += V_88 ;
V_75 -> V_80 += V_88 ;
}
void F_116 ( struct V_14 * V_15 , struct V_13 * V_30 )
{
T_3 V_271 = F_13 ( V_30 ) ;
T_3 V_272 = F_6 ( V_30 -> V_272 ) ;
struct V_76 * V_77 = & V_15 -> V_91 . V_92 [ V_272 ] ;
struct V_67 * V_68 = F_55 ( & V_15 -> V_11 , V_272 ) ;
struct V_74 * V_75 ;
T_3 V_132 ;
V_77 -> V_122 += V_271 ;
if ( F_10 ( ( V_30 -> V_26 >> 4 ) != V_252 ) ) {
V_15 -> V_21 . V_253 ++ ;
goto V_273;
}
if ( F_10 ( F_117 ( V_30 ) ) ) {
V_15 -> V_21 . V_274 ++ ;
goto V_273;
}
V_75 = F_118 ( V_15 -> V_7 . V_256 ,
F_36 ( V_269 ,
sizeof( long ) ) ) ;
if ( F_10 ( ! V_75 ) ) {
V_15 -> V_21 . V_131 ++ ;
goto V_273;
}
F_90 ( V_75 -> V_9 ) ;
V_132 = F_119 ( V_30 ) ;
F_114 ( V_15 , V_30 , V_77 , V_132 , V_75 ) ;
F_87 ( V_15 , V_30 , V_132 , V_75 ) ;
F_108 ( V_15 -> V_7 . V_256 , V_75 ) ;
V_273:
if ( F_29 ( V_77 -> V_122 < V_15 -> V_72 ) )
return;
F_53 ( V_15 , V_77 ) ;
F_109 ( & V_15 -> V_11 , V_30 -> V_272 , & V_68 -> V_127 . V_128 ) ;
}
int F_120 ( struct V_6 * V_7 , int V_275 )
{
struct V_14 * V_15 = F_121 ( V_7 , struct V_14 , V_7 ) ;
struct V_210 * V_214 = & V_15 -> V_214 ;
int V_276 = 0 ;
if ( F_10 ( ! F_57 ( V_126 , & V_15 -> V_125 ) ) )
return 0 ;
if ( V_7 -> V_17 )
V_276 += F_15 ( V_15 , V_7 , 0 , V_275 ) ;
for (; V_276 < V_275 ; V_276 ++ ) {
struct V_13 * V_30 = F_122 ( V_7 ) ;
if ( ! V_30 )
break;
if ( F_123 ( V_30 ) == V_277 ) {
V_276 +=
F_16 ( V_15 , V_7 ,
V_275 - V_276 ) ;
continue;
}
F_124 ( & V_7 -> V_11 ) ;
V_15 -> V_43 ( V_15 , V_30 ) ;
}
if ( V_214 -> V_104 . V_229 ) {
F_88 ( V_214 ) ;
V_214 -> V_104 . V_229 = false ;
}
F_125 ( & V_7 -> V_11 ) ;
F_126 () ;
return V_276 ;
}
bool F_127 ( struct V_6 * V_7 )
{
struct V_210 * V_94 ;
struct V_14 * V_15 ;
T_3 V_278 ;
int V_41 ;
V_94 = F_121 ( V_7 , struct V_210 , V_7 ) ;
if ( F_10 ( ! F_57 ( V_279 , & V_94 -> V_125 ) ) )
return false ;
V_15 = F_121 ( V_94 , struct V_14 , V_214 ) ;
V_278 = V_94 -> V_39 ;
for ( V_41 = 0 ; V_41 < V_280 ; V_41 ++ ) {
struct V_13 * V_30 ;
T_3 V_20 ;
bool V_281 ;
V_30 = F_122 ( V_7 ) ;
if ( ! V_30 )
break;
F_124 ( & V_7 -> V_11 ) ;
V_20 = F_6 ( V_30 -> V_20 ) ;
do {
struct V_45 * V_70 ;
T_3 V_10 ;
V_281 = ( V_278 == V_20 ) ;
V_10 = V_278 & V_94 -> V_11 . V_12 ;
V_70 = & V_94 -> V_104 . V_70 [ V_10 ] ;
V_278 ++ ;
F_28 ( V_15 , V_70 , true ) ;
} while ( ! V_281 );
}
F_125 ( & V_7 -> V_11 ) ;
F_126 () ;
V_94 -> V_39 = V_278 ;
return ( V_41 == V_280 ) ;
}
void F_128 ( struct V_210 * V_94 )
{
struct V_14 * V_15 = F_121 ( V_94 , struct V_14 , V_214 ) ;
struct V_45 * V_70 ;
T_3 V_10 ;
while ( V_94 -> V_39 != V_94 -> V_102 ) {
V_10 = V_94 -> V_39 & V_94 -> V_11 . V_12 ;
V_70 = & V_94 -> V_104 . V_70 [ V_10 ] ;
V_94 -> V_39 ++ ;
F_28 ( V_15 , V_70 , false ) ;
}
}
static inline void F_129 ( struct V_14 * V_15 ,
struct V_13 * V_30 ,
T_1 V_132 ,
struct V_74 * V_75 )
{
struct V_176 * V_177 = V_15 -> V_177 ;
char * V_282 ;
T_2 * V_283 ;
T_2 V_284 ;
V_284 = ( F_5 ( V_30 -> V_285 ) >> 28 ) & 3 ;
V_283 = V_75 -> V_9 + V_286 ;
if ( ( ! V_284 ) || V_283 [ 0 ] != 0xff )
V_75 -> V_287 = V_288 ;
else if ( memcmp ( V_283 , V_177 -> V_289 + 4 , V_290 ) == 0 )
V_75 -> V_287 = V_291 ;
else
V_75 -> V_287 = V_292 ;
F_130 ( V_75 , V_293 ) ;
V_75 -> V_208 = * ( ( T_5 * ) ( V_75 -> V_9 ) ) ;
V_75 -> V_182 = V_184 ;
V_75 -> V_185 = F_77 ( ( V_186 V_187 ) V_30 -> V_31 ) ;
F_83 ( V_75 , V_15 -> V_69 ) ;
if ( F_29 ( V_177 -> V_179 & V_202 ) )
F_73 ( V_30 , V_75 ) ;
V_282 = F_131 ( V_75 , V_294 ) ;
memset ( V_282 , 0 , V_294 ) ;
F_132 ( V_75 ) ;
F_130 ( V_75 , V_295 ) ;
V_75 -> V_296 = V_177 ;
V_15 -> V_21 . V_188 ++ ;
V_15 -> V_21 . V_199 ++ ;
V_15 -> V_21 . V_209 += V_132 ;
}
void F_133 ( struct V_14 * V_15 , struct V_13 * V_30 )
{
struct V_67 * V_68 ;
T_5 V_254 ;
struct V_74 * V_75 ;
T_3 V_20 ;
T_1 V_132 ;
V_254 = V_30 -> V_20 ;
V_20 = F_6 ( V_254 ) ;
V_68 = F_55 ( & V_15 -> V_11 , V_20 ) ;
V_132 = F_5 ( V_30 -> V_18 ) ;
V_75 = F_98 ( V_15 , V_30 , V_20 , V_132 ) ;
if ( ! V_75 )
goto V_255;
F_129 ( V_15 , V_30 , V_132 , V_75 ) ;
F_108 ( V_15 -> V_7 . V_256 , V_75 ) ;
V_255:
F_109 ( & V_15 -> V_11 , V_254 ,
& V_68 -> V_127 . V_128 ) ;
}

static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 -> V_5 ;
}
static inline struct V_6 * F_2 ( struct V_2 * V_3 )
{
return V_3 -> V_4 -> V_7 ;
}
static inline struct V_8 * F_3 ( struct V_2 * V_3 )
{
return V_3 -> V_9 -> V_10 ;
}
static inline int F_4 ( const struct V_11 * V_12 )
{
return ( V_12 -> V_13 <= V_14 ) ;
}
static inline unsigned int F_5 ( unsigned int V_15 )
{
V_15 -- ;
return ( 3 * V_15 ) / 2 + ( V_15 & 1 ) + 2 ;
}
int F_6 ( struct V_16 * V_17 , unsigned char * V_18 ,
int V_19 )
{
struct V_20 * V_21 = V_17 -> V_21 ;
struct V_2 * V_3 = F_7 ( V_21 ) ;
struct V_8 * V_10 = F_3 ( V_3 ) ;
struct V_22 V_23 ;
struct V_24 * V_25 ;
unsigned int V_26 , V_27 ;
switch ( V_21 -> V_28 -> V_29 & V_30 ) {
case V_31 :
V_23 . V_17 . V_32 = (struct V_33 * ) V_17 ;
V_23 . V_3 . V_1 =
F_8 ( V_23 . V_17 . V_32 ) ;
if ( ! V_19 ) {
V_25 = (struct V_24 * ) V_18 ;
memcpy ( V_23 . V_17 . V_32 -> V_34 , & V_25 -> V_35 [ 2 ] ,
V_36 ) ;
}
F_9 ( & V_10 -> V_37 . V_38 -> V_9 , V_23 . V_17 . V_32 -> V_39 ,
F_1 ( V_3 ) -> V_40 , V_41 ) ;
if ( V_23 . V_3 . V_1 -> V_12 ) {
F_10 ( V_23 . V_3 . V_1 -> V_12 ) ;
V_23 . V_3 . V_1 -> V_12 = NULL ;
}
break;
case V_42 :
V_23 . V_17 . V_43 = (struct V_44 * ) V_17 ;
V_23 . V_3 . V_45 =
F_11 ( V_23 . V_17 . V_43 ) ;
V_26 =
F_12 ( F_13 (
V_23 . V_17 . V_43 ) ) ;
V_27 = V_26 ;
if ( V_26 == V_46 )
V_27 = V_47 ;
else if ( V_26 == V_48 )
V_27 = V_49 ;
if ( V_23 . V_3 . V_45 -> V_12 )
V_23 . V_3 . V_45 -> V_12 = NULL ;
if ( V_23 . V_3 . V_45 -> V_50 == 1 ) {
V_23 . V_3 . V_45 -> V_50 = 0 ;
memcpy ( V_23 . V_17 . V_43 -> V_50 , V_18 +
sizeof( struct V_24 ) ,
V_26 ) ;
} else {
memcpy ( V_23 . V_3 . V_45 -> V_51 , V_18 +
sizeof( struct V_24 ) ,
V_27 ) ;
}
F_14 ( V_23 . V_3 . V_45 -> V_52 ) ;
V_23 . V_3 . V_45 -> V_52 = NULL ;
break;
}
return 0 ;
}
static inline unsigned int F_15 ( const struct V_11 * V_12 )
{
unsigned int V_53 , V_54 ;
if ( F_4 ( V_12 ) )
return F_16 ( V_12 -> V_13 , 8 ) ;
V_53 = F_17 ( V_12 ) / 8 ;
V_54 = F_18 ( V_12 ) -> V_55 ;
if ( F_19 ( V_12 ) != F_20 ( V_12 ) )
V_54 ++ ;
return V_53 + F_5 ( V_54 ) ;
}
static struct V_56 * F_21 ( unsigned int V_57 )
{
struct V_58 * V_59 = NULL ;
struct V_56 * V_60 ;
switch ( V_57 ) {
case V_61 :
V_59 = F_22 ( L_1 , 0 , 0 ) ;
break;
case V_46 :
V_59 = F_22 ( L_2 , 0 , 0 ) ;
break;
case V_47 :
V_59 = F_22 ( L_3 , 0 , 0 ) ;
break;
case V_48 :
V_59 = F_22 ( L_4 , 0 , 0 ) ;
break;
case V_49 :
V_59 = F_22 ( L_5 , 0 , 0 ) ;
break;
}
if ( F_23 ( V_59 ) ) {
F_24 ( L_6 ) ;
return ( void * ) V_59 ;
}
V_60 = F_25 ( sizeof( * V_60 ) + F_26 ( V_59 ) ,
V_62 ) ;
if ( ! V_60 )
return F_27 ( - V_63 ) ;
V_60 -> V_21 = V_59 ;
V_60 -> V_64 = F_28 ( V_59 ) ;
return V_60 ;
}
static int F_29 ( struct V_56 * V_60 ,
char * V_65 , char * V_66 ,
int V_67 )
{
struct V_68 V_69 ;
struct V_70 V_71 ;
struct V_72 V_73 ;
int error ;
if ( V_67 == V_61 ) {
error = F_30 ( V_60 ) ? :
F_31 ( V_60 , V_65 , V_74 ) ? :
F_32 ( V_60 , ( void * ) & V_69 ) ;
memcpy ( V_66 , V_69 . V_75 , V_61 ) ;
} else if ( V_67 == V_46 ) {
error = F_30 ( V_60 ) ? :
F_31 ( V_60 , V_65 , V_76 ) ? :
F_32 ( V_60 , ( void * ) & V_71 ) ;
memcpy ( V_66 , V_71 . V_75 , V_47 ) ;
} else if ( V_67 == V_47 ) {
error = F_30 ( V_60 ) ? :
F_31 ( V_60 , V_65 , V_76 ) ? :
F_32 ( V_60 , ( void * ) & V_71 ) ;
memcpy ( V_66 , V_71 . V_75 , V_47 ) ;
} else if ( V_67 == V_48 ) {
error = F_30 ( V_60 ) ? :
F_31 ( V_60 , V_65 , V_77 ) ? :
F_32 ( V_60 , ( void * ) & V_73 ) ;
memcpy ( V_66 , V_73 . V_75 , V_49 ) ;
} else if ( V_67 == V_49 ) {
error = F_30 ( V_60 ) ? :
F_31 ( V_60 , V_65 , V_77 ) ? :
F_32 ( V_60 , ( void * ) & V_73 ) ;
memcpy ( V_66 , V_73 . V_75 , V_49 ) ;
} else {
error = - V_78 ;
F_24 ( L_7 , V_67 ) ;
}
return error ;
}
static void F_33 ( char * V_79 , int V_57 )
{
int V_80 ;
if ( V_57 == V_49 ) {
for ( V_80 = 0 ; V_80 < ( V_57 / sizeof( V_81 ) ) ; V_80 ++ )
* ( ( V_82 * ) V_79 + V_80 ) =
F_34 ( * ( ( V_81 * ) V_79 + V_80 ) ) ;
} else {
for ( V_80 = 0 ; V_80 < ( V_57 / sizeof( V_83 ) ) ; V_80 ++ )
* ( ( V_84 * ) V_79 + V_80 ) =
F_35 ( * ( ( V_83 * ) V_79 + V_80 ) ) ;
}
}
static inline int F_36 ( struct V_20 * V_21 )
{
struct V_85 * V_86 = V_21 -> V_28 ;
struct V_87 * V_88 =
F_37 ( F_38 ( V_86 ) , struct V_87 ,
V_86 . V_89 ) ;
if ( ( V_88 -> type & V_90 ) ==
V_91 )
return 1 ;
return 0 ;
}
static inline unsigned int F_39 ( struct V_92 * V_93 ,
unsigned int * V_94 )
{
unsigned int V_95 ;
for ( V_95 = 0 , * V_94 = 0 ; V_93 ; V_93 = F_40 ( V_93 ) ) {
V_95 ++ ;
* V_94 += V_93 -> V_96 ;
}
return V_95 ;
}
static void F_41 ( struct V_97 * V_98 ,
struct V_92 * V_93 ,
struct V_99 * V_100 )
{
struct V_101 * V_102 ;
unsigned int V_103 = V_100 -> V_104 ;
unsigned int V_95 = V_100 -> V_95 , V_80 , V_105 , V_106 = 0 ;
V_98 -> V_107 = F_42 ( F_43 ( V_108 )
| F_44 ( 0 ) ) ;
V_98 -> V_109 =
F_42 ( F_45 ( 0 ) |
F_46 ( 0 ) |
F_47 ( 0 ) |
F_48 ( 0 ) |
F_49 ( 0 ) |
F_50 ( V_95 ) ) ;
V_98 -> V_110 . V_111 = V_112 ;
V_98 -> V_110 . V_113 = F_51 ( V_100 -> V_113 ) ;
V_98 -> V_110 . V_114 = 0 ;
V_102 = (struct V_101 * ) ( ( unsigned char * ) V_98 +
sizeof( struct V_97 ) ) ;
for ( V_80 = 0 ; V_95 ; V_102 ++ ) {
for ( V_105 = V_80 ; ( V_95 && ( V_105 < ( 8 + V_80 ) ) ) ; V_105 ++ , V_95 -- ) {
V_102 -> V_13 [ V_105 ] = F_51 ( V_93 -> V_96 ) ;
V_102 -> V_115 [ V_105 ] = F_34 ( F_52 ( V_93 ) ) ;
if ( V_103 ) {
if ( V_106 + F_53 ( V_93 ) >= V_103 ) {
V_102 -> V_13 [ V_105 ] = F_51 ( V_103 -
V_106 ) ;
return;
}
V_106 += F_53 ( V_93 ) ;
}
V_93 = F_40 ( V_93 ) ;
}
}
}
static inline unsigned
int F_54 ( struct V_116 * V_9 , struct V_97 * V_98 ,
struct V_92 * V_93 , struct V_99 * V_100 )
{
if ( ! V_93 || ! V_100 -> V_95 )
return 0 ;
V_100 -> V_95 = F_55 ( V_9 , V_93 , V_100 -> V_95 , V_41 ) ;
if ( V_100 -> V_95 == 0 ) {
F_24 ( L_8 ) ;
return - V_78 ;
}
F_41 ( V_98 , V_93 , V_100 ) ;
return 0 ;
}
static inline int F_56 ( struct V_20 * V_21 )
{
struct V_85 * V_86 = V_21 -> V_28 ;
struct V_87 * V_88 =
F_37 ( V_86 , struct V_87 , V_86 . V_117 ) ;
return V_88 -> type & V_90 ;
}
static inline void
F_57 ( struct V_11 * V_12 , unsigned int * V_118 ,
struct V_92 * V_93 , unsigned int V_119 )
{
struct V_120 * V_121 ;
unsigned int V_122 ;
V_12 -> V_13 += V_119 ;
V_12 -> V_123 += V_119 ;
V_12 -> V_124 += V_119 ;
while ( V_119 > 0 ) {
if ( V_93 && ( ! ( V_93 -> V_96 ) ) )
break;
V_121 = F_58 ( V_93 ) ;
F_59 ( V_121 ) ;
V_122 = F_60 ( V_93 -> V_96 , V_119 ) ;
F_61 ( V_12 , * V_118 , V_121 , V_93 -> V_125 , V_122 ) ;
( * V_118 ) ++ ;
V_119 -= V_122 ;
V_93 = F_40 ( V_93 ) ;
}
}
static int F_62 ( struct V_1 * V_5 ,
struct V_126 * V_127 )
{
if ( V_5 -> V_128 == V_129 ) {
F_63 ( V_127 -> V_130 , V_5 -> V_130 ,
V_5 -> V_131 << 3 ) ;
memset ( V_127 -> V_130 + V_5 -> V_131 , 0 ,
V_132 - V_5 -> V_131 ) ;
} else {
memcpy ( V_127 -> V_130 ,
V_5 -> V_130 + ( V_5 -> V_131 >> 1 ) ,
V_5 -> V_131 >> 1 ) ;
F_63 ( V_127 -> V_130 + ( V_5 -> V_131 >> 1 ) ,
V_5 -> V_130 , V_5 -> V_131 << 2 ) ;
}
return 0 ;
}
static inline void F_64 ( struct V_2 * V_3 ,
struct V_133 * V_134 ,
void * V_17 , struct V_11 * V_12 ,
int V_135 , int V_136 ,
unsigned int V_137 )
{
struct V_8 * V_10 = F_3 ( V_3 ) ;
struct V_138 * V_139 = (struct V_138 * ) ( V_134 + 1 ) ;
struct V_140 * V_141 = (struct V_140 * ) ( V_139 + 1 ) ;
int V_142 = V_143 ;
int V_113 = V_10 -> V_37 . V_144 [ V_3 -> V_145 ] ;
unsigned int V_146 = 0 , V_55 = 0 ;
if ( F_4 ( V_12 ) ) {
V_146 = V_12 -> V_123 ;
V_142 = V_147 ;
} else {
V_55 = F_18 ( V_12 ) -> V_55 ;
}
V_134 -> V_148 = F_65 ( V_146 ,
( V_135 >> 4 ) ) ;
V_134 -> V_149 =
F_42 ( F_66 ( V_150 [ V_55 ] ) |
F_67 ( V_136 ) ) ;
V_134 -> V_151 = F_42 ( F_68 ( F_16 (
( F_15 ( V_12 ) * 8 ) , 16 ) ) ) ;
V_134 -> V_152 = F_34 ( ( V_153 ) V_17 ) ;
V_134 -> V_154 =
F_69 ( V_3 -> V_9 -> V_145 , V_113 ,
( V_136 ) ? V_155 : V_142 ) ;
V_139 -> V_156 = F_70 ( V_3 -> V_9 -> V_145 ) ;
V_139 -> V_13 = F_42 ( ( F_16 ( ( F_15 ( V_12 ) * 8 ) ,
16 ) - ( ( sizeof( * V_134 ) ) >> 4 ) ) ) ;
V_141 -> V_157 = F_71 ( V_146 ) ;
V_141 -> V_13 = F_35 ( sizeof( struct V_158 ) + V_135 +
( ( V_136 ) ? V_159 :
( sizeof( struct V_97 ) +
V_137 ) ) + V_146 ) ;
}
static struct V_11
* F_72 ( struct V_16 * V_160 ,
struct V_2 * V_3 , unsigned short V_113 ,
unsigned short V_161 )
{
struct V_33 * V_17 = (struct V_33 * ) V_160 ;
struct V_162 * V_21 = F_73 ( V_17 ) ;
struct V_8 * V_10 = F_3 ( V_3 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_11 * V_12 = NULL ;
struct V_126 * V_127 ;
struct V_133 * V_134 ;
struct V_158 * V_163 ;
struct V_97 * V_98 ;
struct V_164 * V_165 = F_8 ( V_17 ) ;
struct V_99 V_100 ;
unsigned int V_118 = 0 , V_166 , V_137 , V_167 = 0 ;
unsigned int V_168 = F_74 ( V_21 ) , V_135 ;
if ( ! V_17 -> V_34 )
return F_27 ( - V_78 ) ;
V_5 -> V_40 = F_39 ( V_17 -> V_39 , & V_167 ) ;
V_5 -> V_169 = V_161 ;
if ( ( V_5 -> V_131 == 0 ) || ( V_168 > V_36 ) ||
( V_17 -> V_170 <= 0 ) || ( V_17 -> V_170 % V_36 ) )
return F_27 ( - V_78 ) ;
V_137 = F_75 ( V_5 -> V_40 ) ;
V_135 = sizeof( * V_127 ) +
( F_16 ( V_5 -> V_131 , 16 ) * 16 ) ;
V_166 = F_76 ( V_135 , V_137 ) ;
V_12 = F_77 ( ( V_166 + sizeof( struct V_171 ) ) ,
V_172 ) ;
if ( ! V_12 )
return F_27 ( - V_63 ) ;
F_78 ( V_12 , sizeof( struct V_171 ) ) ;
V_134 = (struct V_133 * ) F_79 ( V_12 , V_166 ) ;
V_163 = (struct V_158 * ) ( ( V_173 * ) V_134 + V_174 ) ;
V_163 -> V_175 =
F_80 ( V_3 -> V_9 -> V_145 , 2 , 1 , 1 ) ;
V_163 -> V_176 = F_42 ( V_168 + V_17 -> V_170 ) ;
V_163 -> V_177 = F_81 ( 0 , 0 ,
V_168 + 1 , 0 ) ;
V_163 -> V_178 = F_82 ( 0 , 0 ,
0 , 0 ) ;
V_163 -> V_179 = F_83 ( V_161 , 0 ,
V_5 -> V_128 ,
0 , 0 , V_168 >> 1 , 1 ) ;
V_163 -> V_180 = F_84 ( 0 , 0 , 0 ,
0 , 1 , V_137 ) ;
V_127 = (struct V_126 * ) ( ( V_173 * ) V_163 + sizeof( * V_163 ) ) ;
V_127 -> V_181 = V_5 -> V_182 ;
if ( V_161 == V_183 ) {
if ( F_62 ( V_5 , V_127 ) )
goto V_184;
} else {
if ( V_5 -> V_128 == V_129 ) {
memcpy ( V_127 -> V_130 , V_5 -> V_130 , V_5 -> V_131 ) ;
} else {
memcpy ( V_127 -> V_130 , V_5 -> V_130 +
( V_5 -> V_131 >> 1 ) ,
V_5 -> V_131 >> 1 ) ;
memcpy ( V_127 -> V_130 +
( V_5 -> V_131 >> 1 ) ,
V_5 -> V_130 ,
V_5 -> V_131 >> 1 ) ;
}
}
V_98 = (struct V_97 * ) ( ( V_173 * ) V_127 + V_135 ) ;
memcpy ( V_5 -> V_185 , V_17 -> V_34 , V_168 ) ;
F_85 ( & V_5 -> V_186 , 1 ) ;
F_86 ( & V_5 -> V_186 , V_5 -> V_185 , V_168 ) ;
V_100 . V_95 = V_5 -> V_40 ;
V_100 . V_104 = V_167 ;
V_100 . V_113 = V_113 ;
V_100 . V_187 = 1 ;
if ( F_54 ( & V_10 -> V_37 . V_38 -> V_9 , V_98 , V_17 -> V_39 ,
& V_100 ) )
goto V_184;
F_87 ( V_12 , V_166 ) ;
F_57 ( V_12 , & V_118 , & V_5 -> V_186 , V_168 ) ;
F_57 ( V_12 , & V_118 , V_17 -> V_188 , V_17 -> V_170 ) ;
F_64 ( V_3 , V_134 , V_17 , V_12 , V_135 , 0 , V_137 ) ;
V_165 -> V_12 = V_12 ;
F_88 ( V_12 ) ;
return V_12 ;
V_184:
F_10 ( V_12 ) ;
return F_27 ( - V_63 ) ;
}
static int F_89 ( struct V_162 * V_21 , const V_173 * V_130 ,
unsigned int V_189 )
{
struct V_2 * V_3 = F_90 ( V_21 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_190 * V_86 = F_91 ( V_21 ) ;
unsigned int V_191 , V_192 ;
T_1 V_193 = 0 ;
if ( ( V_189 < V_86 -> V_194 ) || ( V_189 > V_86 -> V_195 ) )
goto V_196;
memcpy ( V_5 -> V_130 , V_130 , V_189 ) ;
V_5 -> V_131 = V_189 ;
if ( V_189 == V_197 ) {
V_191 = V_198 ;
} else if ( V_189 == V_199 ) {
V_193 = 8 ;
V_191 = V_200 ;
} else if ( V_189 == V_201 ) {
V_191 = V_202 ;
} else {
goto V_196;
}
V_192 = ( V_203 +
V_189 + V_193 ) >> 4 ;
V_5 -> V_182 = F_92 ( V_191 , V_204 ,
0 , 0 , V_192 ) ;
V_5 -> V_128 = V_129 ;
return 0 ;
V_196:
F_93 ( V_21 , V_205 ) ;
V_5 -> V_131 = 0 ;
return - V_78 ;
}
static int F_94 ( struct V_206 * V_9 , unsigned int V_207 )
{
int V_208 = 0 ;
struct V_209 * V_210 ;
struct V_211 * V_212 = F_95 ( V_9 ) ;
F_96 () ;
V_210 = & V_212 -> V_213 . V_214 [ V_207 ] ;
F_97 ( & V_210 -> V_215 . V_216 ) ;
if ( V_210 -> V_217 )
V_208 = - 1 ;
F_98 ( & V_210 -> V_215 . V_216 ) ;
F_99 () ;
return V_208 ;
}
static int F_100 ( struct V_33 * V_17 )
{
struct V_162 * V_21 = F_73 ( V_17 ) ;
struct V_2 * V_3 = F_90 ( V_21 ) ;
struct V_16 * V_160 = & V_17 -> V_218 ;
struct V_8 * V_10 = F_3 ( V_3 ) ;
struct V_11 * V_12 ;
if ( F_101 ( F_94 ( V_10 -> V_37 . V_219 [ 0 ] ,
V_3 -> V_145 ) ) ) {
if ( ! ( V_17 -> V_218 . V_64 & V_220 ) )
return - V_221 ;
}
V_12 = F_72 ( V_160 , V_3 ,
V_10 -> V_37 . V_144 [ V_3 -> V_145 ] ,
V_222 ) ;
if ( F_23 ( V_12 ) ) {
F_24 ( L_9 , V_223 ) ;
return F_102 ( V_12 ) ;
}
V_12 -> V_9 = V_10 -> V_37 . V_219 [ 0 ] ;
F_103 ( V_12 , V_224 , V_3 -> V_145 ) ;
F_104 ( V_12 ) ;
return - V_225 ;
}
static int F_105 ( struct V_33 * V_17 )
{
struct V_162 * V_21 = F_73 ( V_17 ) ;
struct V_2 * V_3 = F_90 ( V_21 ) ;
struct V_16 * V_160 = & V_17 -> V_218 ;
struct V_8 * V_10 = F_3 ( V_3 ) ;
struct V_11 * V_12 ;
if ( F_101 ( F_94 ( V_10 -> V_37 . V_219 [ 0 ] ,
V_3 -> V_145 ) ) ) {
if ( ! ( V_17 -> V_218 . V_64 & V_220 ) )
return - V_221 ;
}
V_12 = F_72 ( V_160 , V_3 , V_10 -> V_37 . V_144 [ 0 ] ,
V_183 ) ;
if ( F_23 ( V_12 ) ) {
F_24 ( L_9 , V_223 ) ;
return F_102 ( V_12 ) ;
}
V_12 -> V_9 = V_10 -> V_37 . V_219 [ 0 ] ;
F_103 ( V_12 , V_224 , V_3 -> V_145 ) ;
F_104 ( V_12 ) ;
return - V_225 ;
}
static int F_106 ( struct V_2 * V_3 )
{
struct V_8 * V_10 ;
unsigned int V_226 ;
int V_227 = 0 , V_228 , V_229 ;
V_226 = F_107 () ;
if ( ! V_3 -> V_9 ) {
V_227 = F_108 ( & V_3 -> V_9 ) ;
if ( V_227 ) {
F_24 ( L_10 ) ;
goto V_230;
}
V_10 = F_3 ( V_3 ) ;
V_228 = V_10 -> V_37 . V_231 / V_10 -> V_37 . V_232 ;
V_3 -> V_9 -> V_145 = 0 ;
V_229 = V_3 -> V_9 -> V_145 * V_228 ;
V_229 += V_226 % V_228 ;
F_97 ( & V_3 -> V_9 -> V_233 ) ;
V_3 -> V_145 = V_229 ;
F_98 ( & V_3 -> V_9 -> V_233 ) ;
}
V_230:
return V_227 ;
}
static int F_109 ( struct V_20 * V_21 )
{
V_21 -> V_234 . V_235 = sizeof( struct V_164 ) ;
return F_106 ( F_7 ( V_21 ) ) ;
}
static int F_110 ( struct V_236 * V_237 ,
unsigned int V_238 )
{
switch ( V_238 ) {
case V_61 :
V_237 -> V_239 = V_240 ;
V_237 -> V_241 = V_242 ;
V_237 -> V_243 = V_61 ;
break;
case V_46 :
V_237 -> V_239 = V_244 ;
V_237 -> V_241 = V_245 ;
V_237 -> V_243 = V_47 ;
break;
case V_47 :
V_237 -> V_239 = V_244 ;
V_237 -> V_241 = V_246 ;
V_237 -> V_243 = V_47 ;
break;
case V_48 :
V_237 -> V_239 = V_247 ;
V_237 -> V_241 = V_248 ;
V_237 -> V_243 = V_49 ;
break;
case V_49 :
V_237 -> V_239 = V_247 ;
V_237 -> V_241 = V_249 ;
V_237 -> V_243 = V_49 ;
break;
default:
F_24 ( L_11 ) ;
return - V_78 ;
}
return 0 ;
}
static inline int
F_111 ( struct V_250 * V_165 ,
struct V_11 * V_12 , unsigned int * V_118 , char * V_251 ,
V_173 V_252 )
{
void * V_253 = NULL ;
V_12 -> V_13 += V_252 ;
V_12 -> V_123 += V_252 ;
V_12 -> V_124 += V_252 ;
V_253 = F_25 ( V_254 , V_172 | V_255 ) ;
if ( ! V_253 )
return - V_63 ;
F_59 ( F_112 ( V_253 ) ) ;
V_165 -> V_52 = V_253 ;
memcpy ( V_253 , V_251 , V_252 ) ;
F_61 ( V_12 , * V_118 , F_112 ( V_253 ) ,
F_113 ( V_253 ) , V_252 ) ;
( * V_118 ) ++ ;
return 0 ;
}
static struct V_11 * F_114 ( struct V_44 * V_17 ,
struct V_256 * V_257 )
{
struct V_250 * V_165 = F_11 ( V_17 ) ;
struct V_258 * V_21 = F_13 ( V_17 ) ;
struct V_2 * V_3 = F_7 ( F_115 ( V_21 ) ) ;
struct V_6 * V_7 = F_2 ( V_3 ) ;
struct V_11 * V_12 = NULL ;
struct V_126 * V_127 ;
struct V_133 * V_134 ;
struct V_158 * V_163 ;
unsigned int V_118 = 0 , V_166 , V_259 = 0 ;
unsigned int V_26 = F_12 ( V_21 ) ;
unsigned int V_135 = sizeof( * V_127 ) ;
V_173 V_260 = 0 ;
V_259 = F_116 ( V_26 ) ;
V_135 += V_257 -> V_261 . V_243 + V_259 ;
if ( V_257 -> V_262 )
V_135 += V_257 -> V_261 . V_243 + V_259 ;
if ( V_165 -> V_50 )
V_260 = V_26 ;
else
V_260 = V_257 -> V_261 . V_243 ;
V_166 = F_117 ( V_135 ) ;
V_12 = F_77 ( ( V_166 + sizeof( struct V_171 ) ) ,
V_172 ) ;
if ( ! V_12 )
return V_12 ;
F_78 ( V_12 , sizeof( struct V_171 ) ) ;
V_134 = (struct V_133 * ) F_79 ( V_12 , V_166 ) ;
memset ( V_134 , 0 , V_166 ) ;
V_163 = (struct V_158 * ) ( ( V_173 * ) V_134 + V_174 ) ;
V_163 -> V_175 =
F_80 ( V_3 -> V_9 -> V_145 , 2 , 0 , 0 ) ;
V_163 -> V_176 = F_42 ( V_257 -> V_252 + V_257 -> V_263 ) ;
V_163 -> V_177 =
F_81 ( 0 , 0 , 0 , 0 ) ;
V_163 -> V_178 =
F_82 ( 0 , 1 , 0 , 0 ) ;
V_163 -> V_179 =
F_83 ( 0 , 0 , 0 , V_257 -> V_261 . V_241 ,
V_257 -> V_262 , 0 , 0 ) ;
V_163 -> V_180 =
F_84 ( V_257 -> V_264 , V_257 -> V_265 , 0 , 1 , 0 , 0 ) ;
V_127 = (struct V_126 * ) ( ( V_173 * ) V_163 + sizeof( * V_163 ) ) ;
memcpy ( V_127 -> V_130 , V_165 -> V_51 , V_257 -> V_261 . V_243 ) ;
if ( V_257 -> V_262 )
memcpy ( V_127 -> V_130 + ( ( V_257 -> V_261 . V_243 <= 32 ) ? 32 :
V_266 ) ,
V_7 -> V_267 , V_257 -> V_261 . V_243 ) ;
V_127 -> V_181 = F_92 ( V_204 ,
V_257 -> V_261 . V_239 , 0 ,
V_257 -> V_262 ,
( V_135 >> 4 ) ) ;
V_163 -> V_268 = F_34 ( ( V_81 ) V_257 -> V_268 ) ;
F_87 ( V_12 , V_166 ) ;
if ( V_257 -> V_252 != 0 )
F_111 ( V_165 , V_12 , & V_118 , V_165 -> V_251 ,
V_257 -> V_252 ) ;
if ( V_257 -> V_263 != 0 )
F_57 ( V_12 , & V_118 , V_17 -> V_188 , V_257 -> V_263 ) ;
F_64 ( V_3 , V_134 , V_17 , V_12 , V_135 , V_260 ,
0 ) ;
V_165 -> V_12 = V_12 ;
F_88 ( V_12 ) ;
return V_12 ;
}
static int F_118 ( struct V_44 * V_17 )
{
struct V_250 * V_165 = F_11 ( V_17 ) ;
struct V_258 * V_269 = F_13 ( V_17 ) ;
struct V_2 * V_3 = F_7 ( F_115 ( V_269 ) ) ;
struct V_8 * V_10 = NULL ;
struct V_11 * V_12 ;
V_173 V_270 = 0 , V_271 ;
unsigned int V_170 = V_17 -> V_170 ;
struct V_256 V_237 ;
V_271 = F_119 ( F_115 ( V_269 ) ) ;
V_10 = F_3 ( V_3 ) ;
if ( F_101 ( F_94 ( V_10 -> V_37 . V_219 [ 0 ] ,
V_3 -> V_145 ) ) ) {
if ( ! ( V_17 -> V_218 . V_64 & V_220 ) )
return - V_221 ;
}
if ( V_170 + V_165 -> V_252 >= V_271 ) {
V_270 = ( V_170 + V_165 -> V_252 ) % V_271 ;
V_170 = V_170 + V_165 -> V_252 - V_270 ;
} else {
F_120 ( V_17 -> V_188 , F_121 ( V_17 -> V_188 ) , V_165 -> V_251 +
V_165 -> V_252 , V_170 , 0 ) ;
V_165 -> V_252 += V_170 ;
return 0 ;
}
V_237 . V_262 = 0 ;
V_237 . V_265 = 1 ;
V_237 . V_264 = 0 ;
V_237 . V_263 = V_170 - V_165 -> V_252 ;
V_237 . V_252 = V_165 -> V_252 ;
V_237 . V_268 = 0 ;
F_110 ( & V_237 . V_261 , F_12 ( V_269 ) ) ;
V_165 -> V_50 = 0 ;
V_165 -> V_123 += V_237 . V_263 + V_237 . V_252 ;
V_12 = F_114 ( V_17 , & V_237 ) ;
if ( ! V_12 )
return - V_63 ;
V_165 -> V_252 = V_270 ;
if ( V_270 )
F_120 ( V_17 -> V_188 , F_121 ( V_17 -> V_188 ) ,
V_165 -> V_251 , V_270 , V_17 -> V_170 -
V_270 ) ;
V_12 -> V_9 = V_10 -> V_37 . V_219 [ 0 ] ;
F_103 ( V_12 , V_224 , V_3 -> V_145 ) ;
F_104 ( V_12 ) ;
return - V_225 ;
}
static void F_122 ( char * V_272 , unsigned int V_271 , V_81 V_268 )
{
memset ( V_272 , 0 , V_271 ) ;
* V_272 = 0x80 ;
if ( V_271 == 64 )
* ( V_82 * ) ( V_272 + 56 ) = F_34 ( V_268 << 3 ) ;
else
* ( V_82 * ) ( V_272 + 120 ) = F_34 ( V_268 << 3 ) ;
}
static int F_123 ( struct V_44 * V_17 )
{
struct V_250 * V_165 = F_11 ( V_17 ) ;
struct V_258 * V_269 = F_13 ( V_17 ) ;
struct V_2 * V_3 = F_7 ( F_115 ( V_269 ) ) ;
struct V_256 V_237 ;
struct V_11 * V_12 ;
struct V_8 * V_10 = NULL ;
V_173 V_271 = F_119 ( F_115 ( V_269 ) ) ;
V_10 = F_3 ( V_3 ) ;
if ( F_36 ( F_115 ( V_269 ) ) )
V_237 . V_262 = 1 ;
else
V_237 . V_262 = 0 ;
V_237 . V_263 = 0 ;
F_110 ( & V_237 . V_261 , F_12 ( V_269 ) ) ;
V_165 -> V_50 = 1 ;
V_237 . V_252 = V_165 -> V_252 ;
V_165 -> V_123 += V_237 . V_252 + V_237 . V_263 ;
if ( V_165 -> V_251 && ( V_165 -> V_252 == 0 ) ) {
F_122 ( V_165 -> V_251 , V_271 , V_165 -> V_123 ) ;
V_237 . V_264 = 0 ;
V_237 . V_265 = 1 ;
V_237 . V_268 = 0 ;
V_237 . V_252 = V_271 ;
} else {
V_237 . V_268 = V_165 -> V_123 ;
V_237 . V_264 = 1 ;
V_237 . V_265 = 0 ;
}
V_12 = F_114 ( V_17 , & V_237 ) ;
V_12 -> V_9 = V_10 -> V_37 . V_219 [ 0 ] ;
F_103 ( V_12 , V_224 , V_3 -> V_145 ) ;
F_104 ( V_12 ) ;
return - V_225 ;
}
static int F_124 ( struct V_44 * V_17 )
{
struct V_250 * V_165 = F_11 ( V_17 ) ;
struct V_258 * V_269 = F_13 ( V_17 ) ;
struct V_2 * V_3 = F_7 ( F_115 ( V_269 ) ) ;
struct V_8 * V_10 = NULL ;
struct V_11 * V_12 ;
struct V_256 V_237 ;
V_173 V_271 ;
V_271 = F_119 ( F_115 ( V_269 ) ) ;
V_10 = F_3 ( V_3 ) ;
if ( F_101 ( F_94 ( V_10 -> V_37 . V_219 [ 0 ] ,
V_3 -> V_145 ) ) ) {
if ( ! ( V_17 -> V_218 . V_64 & V_220 ) )
return - V_221 ;
}
if ( F_36 ( F_115 ( V_269 ) ) )
V_237 . V_262 = 1 ;
else
V_237 . V_262 = 0 ;
V_237 . V_263 = V_17 -> V_170 ;
V_237 . V_252 = V_165 -> V_252 ;
F_110 ( & V_237 . V_261 , F_12 ( V_269 ) ) ;
V_165 -> V_123 += V_237 . V_252 + V_237 . V_263 ;
V_165 -> V_50 = 1 ;
if ( V_165 -> V_251 && ( V_165 -> V_252 + V_17 -> V_170 ) == 0 ) {
F_122 ( V_165 -> V_251 , V_271 , V_165 -> V_123 ) ;
V_237 . V_264 = 0 ;
V_237 . V_265 = 1 ;
V_237 . V_268 = 0 ;
V_237 . V_252 = V_271 ;
} else {
V_237 . V_268 = V_165 -> V_123 ;
V_237 . V_264 = 1 ;
V_237 . V_265 = 0 ;
}
V_12 = F_114 ( V_17 , & V_237 ) ;
if ( ! V_12 )
return - V_63 ;
V_12 -> V_9 = V_10 -> V_37 . V_219 [ 0 ] ;
F_103 ( V_12 , V_224 , V_3 -> V_145 ) ;
F_104 ( V_12 ) ;
return - V_225 ;
}
static int F_125 ( struct V_44 * V_17 )
{
struct V_250 * V_165 = F_11 ( V_17 ) ;
struct V_258 * V_269 = F_13 ( V_17 ) ;
struct V_2 * V_3 = F_7 ( F_115 ( V_269 ) ) ;
struct V_8 * V_10 = NULL ;
struct V_11 * V_12 ;
struct V_256 V_237 ;
V_173 V_271 ;
V_269 -> V_273 ( V_17 ) ;
V_271 = F_119 ( F_115 ( V_269 ) ) ;
V_10 = F_3 ( V_3 ) ;
if ( F_101 ( F_94 ( V_10 -> V_37 . V_219 [ 0 ] ,
V_3 -> V_145 ) ) ) {
if ( ! ( V_17 -> V_218 . V_64 & V_220 ) )
return - V_221 ;
}
if ( F_36 ( F_115 ( V_269 ) ) )
V_237 . V_262 = 1 ;
else
V_237 . V_262 = 0 ;
V_237 . V_264 = 0 ;
V_237 . V_265 = 0 ;
V_237 . V_263 = V_17 -> V_170 ;
V_237 . V_252 = 0 ;
V_237 . V_268 = 0 ;
F_110 ( & V_237 . V_261 , F_12 ( V_269 ) ) ;
V_165 -> V_50 = 1 ;
V_165 -> V_123 += V_237 . V_252 + V_237 . V_263 ;
if ( V_165 -> V_251 && V_17 -> V_170 == 0 ) {
F_122 ( V_165 -> V_251 , V_271 , 0 ) ;
V_237 . V_265 = 1 ;
V_237 . V_252 = V_271 ;
}
V_12 = F_114 ( V_17 , & V_237 ) ;
if ( ! V_12 )
return - V_63 ;
V_12 -> V_9 = V_10 -> V_37 . V_219 [ 0 ] ;
F_103 ( V_12 , V_224 , V_3 -> V_145 ) ;
F_104 ( V_12 ) ;
return - V_225 ;
}
static int F_126 ( struct V_44 * V_274 , void * V_230 )
{
struct V_250 * V_165 = F_11 ( V_274 ) ;
struct V_250 * V_75 = V_230 ;
V_75 -> V_252 = V_165 -> V_252 ;
V_75 -> V_123 = V_165 -> V_123 ;
memcpy ( V_75 -> V_251 , V_165 -> V_251 , V_254 ) ;
memcpy ( V_75 -> V_51 , V_165 -> V_51 ,
V_266 ) ;
return 0 ;
}
static int F_127 ( struct V_44 * V_274 , const void * V_275 )
{
struct V_250 * V_165 = F_11 ( V_274 ) ;
struct V_250 * V_75 = (struct V_250 * ) V_275 ;
V_165 -> V_252 = V_75 -> V_252 ;
V_165 -> V_123 = V_75 -> V_123 ;
V_165 -> V_52 = NULL ;
memcpy ( V_165 -> V_251 , V_75 -> V_251 , V_254 ) ;
memcpy ( V_165 -> V_51 , V_75 -> V_51 ,
V_266 ) ;
return 0 ;
}
static int F_128 ( struct V_258 * V_21 , const V_173 * V_130 ,
unsigned int V_189 )
{
struct V_2 * V_3 = F_7 ( F_115 ( V_21 ) ) ;
struct V_6 * V_7 = F_2 ( V_3 ) ;
unsigned int V_26 = F_12 ( V_21 ) ;
unsigned int V_271 = F_119 ( F_115 ( V_21 ) ) ;
unsigned int V_80 , V_227 = 0 , V_27 ;
if ( ! V_7 -> V_60 )
return - V_78 ;
if ( V_189 > V_271 ) {
V_227 = F_129 ( V_7 -> V_60 , V_130 , V_189 ,
V_7 -> V_276 ) ;
if ( V_227 )
goto V_230;
V_189 = V_26 ;
} else {
memcpy ( V_7 -> V_276 , V_130 , V_189 ) ;
}
memset ( V_7 -> V_276 + V_189 , 0 , V_271 - V_189 ) ;
memcpy ( V_7 -> V_267 , V_7 -> V_276 , V_271 ) ;
for ( V_80 = 0 ; V_80 < V_271 / sizeof( int ) ; V_80 ++ ) {
* ( ( unsigned int * ) ( & V_7 -> V_276 ) + V_80 ) ^= V_277 ;
* ( ( unsigned int * ) ( & V_7 -> V_267 ) + V_80 ) ^= V_278 ;
}
V_27 = V_26 ;
if ( V_26 == V_46 )
V_27 = V_47 ;
else if ( V_26 == V_48 )
V_27 = V_49 ;
V_227 = F_29 ( V_7 -> V_60 , V_7 -> V_276 ,
V_7 -> V_276 , V_26 ) ;
if ( V_227 )
goto V_230;
F_33 ( V_7 -> V_276 , V_27 ) ;
V_227 = F_29 ( V_7 -> V_60 , V_7 -> V_267 ,
V_7 -> V_267 , V_26 ) ;
if ( V_227 )
goto V_230;
F_33 ( V_7 -> V_267 , V_27 ) ;
V_230:
return V_227 ;
}
static int F_130 ( struct V_162 * V_21 , const V_173 * V_130 ,
unsigned int V_279 )
{
struct V_2 * V_3 = F_90 ( V_21 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_280 = 0 ;
unsigned short V_192 = 0 ;
if ( ( V_279 == ( V_197 << 1 ) ) ||
( V_279 == ( V_201 << 1 ) ) ) {
memcpy ( V_5 -> V_130 , V_130 , V_279 ) ;
V_5 -> V_131 = V_279 ;
V_192 = ( V_203 + V_279 ) >> 4 ;
V_5 -> V_182 =
F_92 ( ( V_279 == V_201 ) ?
V_198 :
V_202 ,
V_204 , 1 ,
0 , V_192 ) ;
V_5 -> V_128 = V_281 ;
} else {
F_131 ( (struct V_20 * ) V_21 ,
V_205 ) ;
V_5 -> V_131 = 0 ;
V_280 = - V_78 ;
}
return V_280 ;
}
static int F_132 ( struct V_44 * V_274 )
{
struct V_250 * V_165 = F_11 ( V_274 ) ;
struct V_258 * V_21 = F_13 ( V_274 ) ;
int V_26 = F_12 ( V_21 ) ;
V_165 -> V_123 = 0 ;
V_165 -> V_52 = NULL ;
V_165 -> V_252 = 0 ;
V_165 -> V_12 = NULL ;
V_165 -> V_50 = 0 ;
F_133 ( V_165 -> V_51 , V_26 ) ;
return 0 ;
}
static int F_134 ( struct V_20 * V_21 )
{
F_135 ( F_136 ( V_21 ) ,
sizeof( struct V_250 ) ) ;
return F_106 ( F_7 ( V_21 ) ) ;
}
static int F_137 ( struct V_44 * V_274 )
{
struct V_250 * V_165 = F_11 ( V_274 ) ;
struct V_258 * V_269 = F_13 ( V_274 ) ;
struct V_2 * V_3 = F_7 ( F_115 ( V_269 ) ) ;
struct V_6 * V_7 = F_2 ( V_3 ) ;
unsigned int V_26 = F_12 ( V_269 ) ;
unsigned int V_271 = F_119 ( F_115 ( V_269 ) ) ;
F_132 ( V_274 ) ;
V_165 -> V_123 = V_271 ;
if ( F_36 ( F_115 ( V_269 ) ) ) {
if ( V_26 == V_46 )
memcpy ( V_165 -> V_51 , V_7 -> V_276 ,
V_47 ) ;
else if ( V_26 == V_48 )
memcpy ( V_165 -> V_51 , V_7 -> V_276 ,
V_49 ) ;
else
memcpy ( V_165 -> V_51 , V_7 -> V_276 ,
V_26 ) ;
}
return 0 ;
}
static int F_138 ( struct V_20 * V_21 )
{
struct V_2 * V_3 = F_7 ( V_21 ) ;
struct V_6 * V_7 = F_2 ( V_3 ) ;
unsigned int V_26 =
F_12 ( F_136 ( V_21 ) ) ;
F_135 ( F_136 ( V_21 ) ,
sizeof( struct V_250 ) ) ;
V_7 -> V_60 = F_21 ( V_26 ) ;
if ( F_23 ( V_7 -> V_60 ) )
return F_102 ( V_7 -> V_60 ) ;
return F_106 ( F_7 ( V_21 ) ) ;
}
static void F_139 ( struct V_56 * V_60 )
{
F_140 ( V_60 -> V_21 ) ;
F_14 ( V_60 ) ;
}
static void F_141 ( struct V_20 * V_21 )
{
struct V_2 * V_3 = F_7 ( V_21 ) ;
struct V_6 * V_7 = F_2 ( V_3 ) ;
if ( V_7 -> V_60 ) {
F_139 ( V_7 -> V_60 ) ;
V_7 -> V_60 = NULL ;
}
}
static int F_142 ( void )
{
int V_80 ;
for ( V_80 = 0 ; V_80 < F_143 ( V_282 ) ; V_80 ++ ) {
switch ( V_282 [ V_80 ] . type & V_30 ) {
case V_283 :
if ( V_282 [ V_80 ] . V_284 )
F_144 (
& V_282 [ V_80 ] . V_86 . V_117 ) ;
break;
case V_42 :
if ( V_282 [ V_80 ] . V_284 )
F_145 (
& V_282 [ V_80 ] . V_86 . V_89 ) ;
break;
}
V_282 [ V_80 ] . V_284 = 0 ;
}
return 0 ;
}
static int F_146 ( void )
{
struct V_85 V_285 ;
struct V_286 * V_287 ;
int V_227 = 0 , V_80 ;
char * V_288 = NULL ;
for ( V_80 = 0 ; V_80 < F_143 ( V_282 ) ; V_80 ++ ) {
if ( V_282 [ V_80 ] . V_284 )
continue;
switch ( V_282 [ V_80 ] . type & V_30 ) {
case V_283 :
V_227 = F_147 ( & V_282 [ V_80 ] . V_86 . V_117 ) ;
V_288 = V_282 [ V_80 ] . V_86 . V_117 . V_289 ;
break;
case V_42 :
V_287 = & V_282 [ V_80 ] . V_86 . V_89 ;
V_287 -> V_290 = F_118 ;
V_287 -> V_291 = F_123 ;
V_287 -> V_292 = F_124 ;
V_287 -> V_293 = F_125 ;
V_287 -> V_294 = F_126 ;
V_287 -> V_295 = F_127 ;
V_287 -> V_296 . V_297 = V_298 ;
V_287 -> V_296 . V_218 . V_299 = V_300 ;
V_287 -> V_296 . V_218 . V_301 = V_302 ;
V_287 -> V_296 . V_218 . V_29 = V_303 ;
V_287 -> V_296 . V_218 . V_304 = 0 ;
V_287 -> V_296 . V_218 . V_305 = NULL ;
V_287 -> V_296 . V_218 . V_306 = & V_307 ;
if ( V_282 [ V_80 ] . type == V_308 ) {
V_287 -> V_296 . V_218 . V_309 = F_138 ;
V_287 -> V_296 . V_218 . V_305 = F_141 ;
V_287 -> V_273 = F_137 ;
V_287 -> V_310 = F_128 ;
V_287 -> V_296 . V_218 . V_311 = V_312 ;
} else {
V_287 -> V_273 = F_132 ;
V_287 -> V_296 . V_218 . V_311 = V_313 ;
V_287 -> V_296 . V_218 . V_309 = F_134 ;
}
V_227 = F_148 ( & V_282 [ V_80 ] . V_86 . V_89 ) ;
V_285 = V_282 [ V_80 ] . V_86 . V_89 . V_296 . V_218 ;
V_288 = V_285 . V_289 ;
break;
}
if ( V_227 ) {
F_24 ( L_12 ,
V_288 ) ;
goto V_314;
} else {
V_282 [ V_80 ] . V_284 = 1 ;
}
}
return 0 ;
V_314:
F_142 () ;
return V_227 ;
}
int F_149 ( void )
{
return F_146 () ;
}
int F_150 ( void )
{
F_142 () ;
return 0 ;
}

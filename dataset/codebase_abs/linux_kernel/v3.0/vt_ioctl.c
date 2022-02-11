void F_1 ( unsigned int V_1 , unsigned int V_2 , unsigned int V_3 )
{
struct V_4 * V_5 , * V_6 ;
unsigned long V_7 ;
int V_8 = 0 ;
F_2 ( & V_9 , V_7 ) ;
V_6 = & V_10 ;
F_3 (pos, head) {
struct V_11 * V_12 = F_4 ( V_5 ,
struct V_11 , V_13 ) ;
if ( ! ( V_12 -> V_1 . V_1 & V_1 ) )
continue;
V_12 -> V_1 . V_1 = V_1 ;
V_12 -> V_1 . V_14 = V_2 + 1 ;
V_12 -> V_1 . V_15 = V_3 + 1 ;
V_8 = 1 ;
V_12 -> V_16 = 1 ;
}
F_5 ( & V_9 , V_7 ) ;
if ( V_8 )
F_6 ( & V_17 ) ;
}
static void V_11 ( struct V_11 * V_18 )
{
unsigned long V_7 ;
F_7 ( & V_18 -> V_13 ) ;
V_18 -> V_16 = 0 ;
F_2 ( & V_9 , V_7 ) ;
F_8 ( & V_18 -> V_13 , & V_10 ) ;
F_5 ( & V_9 , V_7 ) ;
F_9 ( V_17 , V_18 -> V_16 ) ;
F_2 ( & V_9 , V_7 ) ;
F_10 ( & V_18 -> V_13 ) ;
F_5 ( & V_9 , V_7 ) ;
}
static int F_11 ( struct V_19 T_1 * V_1 )
{
struct V_11 V_18 ;
if ( F_12 ( & V_18 . V_1 , V_1 , sizeof( struct V_19 ) ) )
return - V_20 ;
if ( V_18 . V_1 . V_1 & ~ V_21 )
return - V_22 ;
V_11 ( & V_18 ) ;
if ( V_18 . V_16 ) {
if ( F_13 ( V_1 , & V_18 . V_1 , sizeof( struct V_19 ) ) )
return - V_20 ;
return 0 ;
}
return - V_23 ;
}
int F_14 ( int V_24 )
{
struct V_11 V_18 ;
do {
if ( V_24 == V_25 + 1 )
break;
V_18 . V_1 . V_1 = V_26 ;
V_11 ( & V_18 ) ;
if ( V_18 . V_16 == 0 )
return - V_23 ;
} while ( V_18 . V_1 . V_15 != V_24 );
return 0 ;
}
static inline int
F_15 ( int V_27 , struct V_28 T_1 * V_29 , int V_30 , struct V_31 * V_32 )
{
struct V_28 V_33 ;
T_2 * V_34 , V_35 , V_36 ;
if ( F_12 ( & V_33 , V_29 , sizeof( struct V_28 ) ) )
return - V_20 ;
if ( ! F_16 ( V_37 ) )
V_30 = 0 ;
switch ( V_27 ) {
case V_38 :
V_34 = V_39 [ V_40 ] ;
if ( V_34 ) {
V_35 = F_17 ( V_34 [ V_41 ] ) ;
if ( V_32 -> V_42 != V_43 && F_18 ( V_35 ) >= V_44 )
V_35 = V_45 ;
} else
V_35 = ( V_41 ? V_45 : V_46 ) ;
return F_19 ( V_35 , & V_29 -> V_47 ) ;
case V_48 :
if ( ! V_30 )
return - V_49 ;
if ( ! V_41 && V_50 == V_46 ) {
V_34 = V_39 [ V_40 ] ;
if ( V_40 && V_34 ) {
V_39 [ V_40 ] = NULL ;
if ( V_34 [ 0 ] == F_17 ( V_51 ) ) {
F_20 ( V_34 ) ;
V_52 -- ;
}
}
break;
}
if ( F_18 ( V_50 ) < V_44 ) {
if ( F_21 ( V_50 ) > V_53 [ F_18 ( V_50 ) ] )
return - V_22 ;
} else
if ( V_32 -> V_42 != V_43 )
return - V_22 ;
#if ! F_22 ( V_54 ) && ! F_22 ( V_55 )
if ( ! V_41 )
break;
#endif
if ( ! ( V_34 = V_39 [ V_40 ] ) ) {
int V_56 ;
if ( V_52 >= V_57 &&
! F_16 ( V_58 ) )
return - V_49 ;
V_34 = F_23 ( sizeof( V_59 ) ,
V_60 ) ;
if ( ! V_34 )
return - V_61 ;
V_39 [ V_40 ] = V_34 ;
V_34 [ 0 ] = F_17 ( V_51 ) ;
for ( V_56 = 1 ; V_56 < V_62 ; V_56 ++ )
V_34 [ V_56 ] = F_17 ( V_45 ) ;
V_52 ++ ;
}
V_36 = F_17 ( V_34 [ V_41 ] ) ;
if ( V_50 == V_36 )
break;
if ( ( ( V_36 == V_63 ) || ( V_50 == V_63 ) ) && ! F_16 ( V_64 ) )
return - V_49 ;
V_34 [ V_41 ] = F_17 ( V_50 ) ;
if ( ! V_40 && ( F_18 ( V_36 ) == V_65 || F_18 ( V_50 ) == V_65 ) )
F_24 () ;
break;
}
return 0 ;
}
static inline int
F_25 ( int V_27 , struct V_66 T_1 * V_67 , int V_30 )
{
struct V_66 V_33 ;
int V_68 = 0 ;
if ( F_12 ( & V_33 , V_67 , sizeof( struct V_66 ) ) )
return - V_20 ;
switch ( V_27 ) {
case V_69 :
V_68 = F_26 ( V_33 . V_70 ) ;
if ( V_68 >= 0 )
V_68 = F_19 ( V_68 , & V_67 -> V_71 ) ;
break;
case V_72 :
if ( ! V_30 )
return - V_49 ;
V_68 = F_27 ( V_33 . V_70 , V_33 . V_71 ) ;
break;
}
return V_68 ;
}
static inline int
F_28 ( int V_27 , struct V_73 T_1 * V_74 , int V_30 )
{
struct V_73 * V_75 ;
char * V_76 ;
T_3 * V_77 ;
T_3 T_1 * V_78 ;
int V_79 ;
int V_80 ;
char * V_81 , * V_82 , * V_83 ;
int V_41 , V_56 , V_84 ;
int V_85 ;
if ( ! F_16 ( V_37 ) )
V_30 = 0 ;
V_75 = F_23 ( sizeof( * V_75 ) , V_60 ) ;
if ( ! V_75 ) {
V_85 = - V_61 ;
goto V_86;
}
if ( F_12 ( V_75 , V_74 , sizeof( struct V_73 ) ) ) {
V_85 = - V_20 ;
goto V_86;
}
V_75 -> V_87 [ sizeof( V_75 -> V_87 ) - 1 ] = '\0' ;
V_41 = V_75 -> V_88 ;
switch ( V_27 ) {
case V_89 :
V_79 = sizeof( V_75 -> V_87 ) - 1 ;
V_78 = V_74 -> V_87 ;
V_76 = V_90 [ V_41 ] ;
if( V_76 )
for ( ; * V_76 && V_79 ; V_76 ++ , V_79 -- )
if ( F_19 ( * V_76 , V_78 ++ ) ) {
V_85 = - V_20 ;
goto V_86;
}
if ( F_19 ( '\0' , V_78 ) ) {
V_85 = - V_20 ;
goto V_86;
}
F_20 ( V_75 ) ;
return ( ( V_76 && * V_76 ) ? - V_91 : 0 ) ;
case V_92 :
if ( ! V_30 ) {
V_85 = - V_49 ;
goto V_86;
}
V_77 = V_90 [ V_41 ] ;
V_81 = V_93 + ( V_94 - V_95 ) ;
for ( V_56 = V_41 + 1 ; V_56 < V_96 && ! V_90 [ V_56 ] ; V_56 ++ )
;
if ( V_56 < V_96 )
V_82 = V_90 [ V_56 ] ;
else
V_82 = V_81 ;
V_80 = ( V_77 ? - strlen ( V_77 ) : 1 ) + strlen ( V_75 -> V_87 ) ;
if ( V_80 <= V_95 ) {
if ( V_56 < V_96 ) {
memmove ( V_82 + V_80 , V_82 , V_81 - V_82 ) ;
for ( V_84 = V_56 ; V_84 < V_96 ; V_84 ++ )
if ( V_90 [ V_84 ] )
V_90 [ V_84 ] += V_80 ;
}
if ( ! V_77 )
V_90 [ V_41 ] = V_82 ;
V_95 -= V_80 ;
} else {
V_79 = 256 ;
while ( V_79 < V_94 - V_95 + V_80 )
V_79 <<= 1 ;
V_83 = F_23 ( V_79 , V_60 ) ;
if( ! V_83 ) {
V_85 = - V_61 ;
goto V_86;
}
if ( ! V_77 )
V_90 [ V_41 ] = V_82 ;
if ( V_82 > V_93 )
memmove ( V_83 , V_93 , V_82 - V_93 ) ;
for ( V_84 = 0 ; V_84 < V_56 ; V_84 ++ )
if ( V_90 [ V_84 ] )
V_90 [ V_84 ] = V_83 + ( V_90 [ V_84 ] - V_93 ) ;
if ( V_81 > V_82 ) {
memmove ( V_83 + ( V_82 - V_93 ) + V_80 , V_82 , V_81 - V_82 ) ;
for ( V_84 = V_56 ; V_84 < V_96 ; V_84 ++ )
if ( V_90 [ V_84 ] )
V_90 [ V_84 ] = V_83 + ( V_90 [ V_84 ] - V_93 ) + V_80 ;
}
if ( V_93 != V_97 )
F_20 ( V_93 ) ;
V_93 = V_83 ;
V_95 = V_95 - V_80 + V_79 - V_94 ;
V_94 = V_79 ;
}
strcpy ( V_90 [ V_41 ] , V_75 -> V_87 ) ;
break;
}
V_85 = 0 ;
V_86:
F_20 ( V_75 ) ;
return V_85 ;
}
static inline int
F_29 ( int V_27 , struct V_98 T_1 * V_99 , int V_30 , struct V_100 * V_101 )
{
struct V_98 V_102 ;
int V_41 ;
if ( F_12 ( & V_102 , V_99 , sizeof( struct V_98 ) ) )
return - V_20 ;
switch ( V_27 ) {
case V_103 :
if ( ! V_30 )
return - V_49 ;
V_101 -> V_101 = V_104 ;
V_101 -> V_7 = V_105 ;
V_101 -> V_106 = 8 ;
V_101 -> V_107 = V_102 . V_108 ;
V_101 -> V_109 = V_102 . V_109 ;
V_101 -> V_110 = V_102 . V_111 ;
return F_30 ( V_112 [ V_25 ] . V_113 , V_101 ) ;
case V_114 : {
V_101 -> V_101 = V_115 ;
V_101 -> V_7 = V_105 ;
V_101 -> V_106 = 8 ;
V_101 -> V_107 = V_102 . V_108 ;
V_101 -> V_109 = V_102 . V_109 ;
V_101 -> V_110 = V_102 . V_111 ;
V_41 = F_30 ( V_112 [ V_25 ] . V_113 , V_101 ) ;
if ( V_41 )
return V_41 ;
V_102 . V_108 = V_101 -> V_107 ;
V_102 . V_109 = V_101 -> V_109 ;
if ( F_13 ( V_99 , & V_102 , sizeof( struct V_98 ) ) )
return - V_20 ;
return 0 ;
}
}
return - V_22 ;
}
static inline int
F_31 ( int V_27 , struct V_116 T_1 * V_117 , int V_30 , struct V_118 * V_119 )
{
struct V_116 V_33 ;
if ( F_12 ( & V_33 , V_117 , sizeof V_33 ) )
return - V_20 ;
if ( V_33 . V_120 )
if ( ! F_32 ( V_121 , V_33 . V_120 ,
V_33 . V_122 * sizeof( struct V_123 ) ) )
return - V_20 ;
switch ( V_27 ) {
case V_124 :
if ( ! V_30 )
return - V_49 ;
return F_33 ( V_119 , V_33 . V_122 , V_33 . V_120 ) ;
case V_125 :
if ( ! V_30 && V_25 != V_119 -> V_126 )
return - V_49 ;
return F_34 ( V_119 , V_33 . V_122 , & ( V_117 -> V_122 ) , V_33 . V_120 ) ;
}
return 0 ;
}
int F_35 ( struct V_127 * V_128 ,
unsigned int V_27 , unsigned long V_129 )
{
struct V_118 * V_119 = V_128 -> V_130 ;
struct V_100 V_101 ;
struct V_31 * V_32 ;
unsigned int V_131 ;
unsigned char V_132 ;
unsigned int V_133 ;
void T_1 * V_78 = ( void T_1 * ) V_129 ;
int V_41 , V_30 ;
int V_85 = 0 ;
V_131 = V_119 -> V_126 ;
F_36 () ;
if ( ! F_37 ( V_131 ) ) {
V_85 = - V_134 ;
goto V_135;
}
V_30 = 0 ;
if ( V_136 -> signal -> V_128 == V_128 || F_16 ( V_37 ) )
V_30 = 1 ;
V_32 = V_137 + V_131 ;
switch ( V_27 ) {
case V_138 :
V_85 = F_38 ( V_128 , V_129 ) ;
break;
case V_139 :
if ( ! V_30 )
goto V_140;
if ( V_129 )
V_129 = V_141 / V_129 ;
F_39 ( V_129 , 0 ) ;
break;
case V_142 :
if ( ! V_30 )
goto V_140;
{
unsigned int V_143 , V_144 ;
V_143 = V_145 * ( ( V_129 >> 16 ) & 0xffff ) / 1000 ;
V_144 = V_143 ? ( V_129 & 0xffff ) : 0 ;
if ( V_144 )
V_144 = V_141 / V_144 ;
F_39 ( V_144 , V_143 ) ;
break;
}
case V_146 :
V_132 = V_147 ;
goto V_148;
#ifdef F_40
case V_149 :
case V_150 :
if ( V_129 < V_151 || V_129 > V_152 ) {
V_85 = - V_22 ;
break;
}
V_85 = F_41 ( V_129 , 1 , ( V_27 == V_149 ) ) ? - V_153 : 0 ;
break;
case V_154 :
case V_155 :
V_85 = F_41 ( V_151 , V_156 ,
( V_27 == V_154 ) ) ? - V_153 : 0 ;
break;
#endif
case V_157 :
{
struct V_158 V_159 ;
if ( ! F_16 ( V_37 ) )
goto V_140;
if ( F_12 ( & V_159 , V_78 , sizeof( struct V_158 ) ) ) {
V_85 = - V_20 ;
break;
}
V_85 = F_42 ( & V_159 ) ;
if ( V_85 )
break;
if ( F_13 ( V_78 , & V_159 , sizeof( struct V_158 ) ) )
V_85 = - V_20 ;
break;
}
case V_160 :
if ( ! V_30 )
goto V_140;
switch ( V_129 ) {
case V_161 :
break;
case V_162 :
case V_163 :
V_129 = V_164 ;
case V_164 :
break;
default:
V_85 = - V_22 ;
goto V_135;
}
if ( V_119 -> V_165 == ( unsigned char ) V_129 )
break;
V_119 -> V_165 = ( unsigned char ) V_129 ;
if ( V_131 != V_25 )
break;
F_43 () ;
if ( V_129 == V_164 )
F_44 ( 1 ) ;
else
F_45 ( 1 ) ;
F_46 () ;
break;
case V_166 :
V_133 = V_119 -> V_165 ;
goto V_167;
case V_168 :
case V_169 :
V_85 = - V_22 ;
break;
case V_170 :
if ( ! V_30 )
goto V_140;
switch( V_129 ) {
case V_171 :
V_32 -> V_42 = V_172 ;
break;
case V_173 :
V_32 -> V_42 = V_174 ;
break;
case V_175 :
V_32 -> V_42 = V_176 ;
F_24 () ;
break;
case V_177 :
V_32 -> V_42 = V_43 ;
F_24 () ;
break;
case V_178 :
V_32 -> V_42 = V_179 ;
break;
default:
V_85 = - V_22 ;
goto V_135;
}
F_47 ( V_128 ) ;
break;
case V_180 :
switch ( V_32 -> V_42 ) {
case V_172 :
V_133 = V_171 ;
break;
case V_174 :
V_133 = V_173 ;
break;
case V_43 :
V_133 = V_177 ;
break;
case V_179 :
V_133 = V_178 ;
break;
default:
V_133 = V_175 ;
break;
}
goto V_167;
case V_181 :
switch( V_129 ) {
case V_182 :
F_48 ( V_32 , V_183 ) ;
break;
case V_184 :
F_49 ( V_32 , V_183 ) ;
break;
default:
V_85 = - V_22 ;
}
break;
case V_185 :
V_133 = ( F_50 ( V_32 , V_183 ) ? V_184 : V_182 ) ;
V_167:
V_85 = F_19 ( V_133 , ( int T_1 * ) V_129 ) ;
break;
case V_69 :
case V_72 :
if( ! F_16 ( V_37 ) )
V_30 = 0 ;
V_85 = F_25 ( V_27 , V_78 , V_30 ) ;
break;
case V_38 :
case V_48 :
V_85 = F_15 ( V_27 , V_78 , V_30 , V_32 ) ;
break;
case V_89 :
case V_92 :
V_85 = F_28 ( V_27 , V_78 , V_30 ) ;
break;
case V_186 :
{
struct V_187 T_1 * V_188 = V_78 ;
struct V_189 V_190 ;
int V_41 ;
if ( F_19 ( V_191 , & V_188 -> V_192 ) ) {
V_85 = - V_20 ;
break;
}
for ( V_41 = 0 ; V_41 < V_191 ; V_41 ++ ) {
V_190 . V_190 = F_51 ( V_193 [ V_41 ] . V_190 ) ;
V_190 . V_194 = F_51 ( V_193 [ V_41 ] . V_194 ) ;
V_190 . V_195 = F_51 ( V_193 [ V_41 ] . V_195 ) ;
if ( F_13 ( V_188 -> V_189 + V_41 , & V_190 , sizeof( struct V_189 ) ) ) {
V_85 = - V_20 ;
break;
}
}
break;
}
case V_196 :
{
struct V_197 T_1 * V_188 = V_78 ;
if ( F_19 ( V_191 , & V_188 -> V_192 ) )
V_85 = - V_20 ;
else if ( F_13 ( V_188 -> V_198 , V_193 ,
V_191 * sizeof( struct V_198 ) ) )
V_85 = - V_20 ;
break;
}
case V_199 :
{
struct V_187 T_1 * V_188 = V_78 ;
struct V_189 V_190 ;
unsigned int V_200 ;
int V_41 ;
if ( ! V_30 )
goto V_140;
if ( F_52 ( V_200 , & V_188 -> V_192 ) ) {
V_85 = - V_20 ;
break;
}
if ( V_200 >= V_201 ) {
V_85 = - V_22 ;
break;
}
V_191 = V_200 ;
for ( V_41 = 0 ; V_41 < V_200 ; V_41 ++ ) {
if ( F_12 ( & V_190 , V_188 -> V_189 + V_41 , sizeof( struct V_189 ) ) ) {
V_85 = - V_20 ;
break;
}
V_193 [ V_41 ] . V_190 = F_53 ( V_190 . V_190 ) ;
V_193 [ V_41 ] . V_194 = F_53 ( V_190 . V_194 ) ;
V_193 [ V_41 ] . V_195 = F_53 ( V_190 . V_195 ) ;
}
break;
}
case V_202 :
{
struct V_197 T_1 * V_188 = V_78 ;
unsigned int V_200 ;
if ( ! V_30 )
goto V_140;
if ( F_52 ( V_200 , & V_188 -> V_192 ) ) {
V_85 = - V_20 ;
break;
}
if ( V_200 >= V_201 ) {
V_85 = - V_22 ;
break;
}
V_191 = V_200 ;
if ( F_12 ( V_193 , V_188 -> V_198 , V_200 * sizeof( struct V_198 ) ) )
V_85 = - V_20 ;
break;
}
case V_203 :
V_132 = V_32 -> V_204 | ( V_32 -> V_205 << 4 ) ;
goto V_148;
case V_206 :
if ( ! V_30 )
goto V_140;
if ( V_129 & ~ 0x77 ) {
V_85 = - V_22 ;
break;
}
V_32 -> V_204 = ( V_129 & 7 ) ;
V_32 -> V_205 = ( ( V_129 >> 4 ) & 7 ) ;
F_54 () ;
break;
case V_207 :
V_132 = F_55 () ;
V_148:
V_85 = F_19 ( V_132 , ( char T_1 * ) V_129 ) ;
break;
case V_208 :
if ( ! V_30 )
goto V_140;
F_56 ( V_32 , V_129 ) ;
break;
case V_209 :
{
if ( ! V_30 || ! F_16 ( V_210 ) )
goto V_140;
if ( ! F_57 ( V_129 ) || V_129 < 1 || V_129 == V_211 )
V_85 = - V_22 ;
else {
F_58 ( & V_212 . V_213 ) ;
F_59 ( V_212 . V_214 ) ;
V_212 . V_214 = F_60 ( F_61 ( V_136 ) ) ;
V_212 . V_215 = V_129 ;
F_62 ( & V_212 . V_213 ) ;
}
break;
}
case V_216 :
{
struct V_217 V_33 ;
if ( ! V_30 )
goto V_140;
if ( F_12 ( & V_33 , V_78 , sizeof( struct V_217 ) ) ) {
V_85 = - V_20 ;
goto V_135;
}
if ( V_33 . V_218 != V_219 && V_33 . V_218 != V_220 ) {
V_85 = - V_22 ;
goto V_135;
}
F_43 () ;
V_119 -> V_217 = V_33 ;
V_119 -> V_217 . V_221 = 0 ;
F_59 ( V_119 -> V_222 ) ;
V_119 -> V_222 = F_60 ( F_61 ( V_136 ) ) ;
V_119 -> V_223 = - 1 ;
F_46 () ;
break;
}
case V_224 :
{
struct V_217 V_33 ;
int V_225 ;
F_43 () ;
memcpy ( & V_33 , & V_119 -> V_217 , sizeof( struct V_217 ) ) ;
F_46 () ;
V_225 = F_13 ( V_78 , & V_33 , sizeof( struct V_217 ) ) ;
if ( V_225 )
V_85 = - V_20 ;
break;
}
case V_226 :
{
struct V_227 T_1 * V_228 = V_78 ;
unsigned short V_229 , V_230 ;
if ( F_19 ( V_25 + 1 , & V_228 -> V_231 ) )
V_85 = - V_20 ;
else {
V_229 = 1 ;
for ( V_41 = 0 , V_230 = 2 ; V_41 < V_232 && V_230 ;
++ V_41 , V_230 <<= 1 )
if ( F_63 ( V_41 ) )
V_229 |= V_230 ;
V_85 = F_19 ( V_229 , & V_228 -> V_233 ) ;
}
break;
}
case V_234 :
for ( V_41 = 0 ; V_41 < V_232 ; ++ V_41 )
if ( ! F_63 ( V_41 ) )
break;
V_133 = V_41 < V_232 ? ( V_41 + 1 ) : - 1 ;
goto V_167;
case V_235 :
if ( ! V_30 )
goto V_140;
if ( V_129 == 0 || V_129 > V_232 )
V_85 = - V_153 ;
else {
V_129 -- ;
F_43 () ;
V_85 = F_64 ( V_129 ) ;
F_46 () ;
if ( V_85 )
break;
F_65 ( V_129 ) ;
}
break;
case V_236 :
{
struct V_237 V_238 ;
if ( ! V_30 )
goto V_140;
if ( F_12 ( & V_238 , (struct V_237 T_1 * ) V_129 ,
sizeof( struct V_237 ) ) ) {
V_85 = - V_20 ;
goto V_135;
}
if ( V_238 . V_131 == 0 || V_238 . V_131 > V_232 )
V_85 = - V_153 ;
else {
V_238 . V_131 -- ;
F_43 () ;
V_85 = F_64 ( V_238 . V_131 ) ;
if ( V_85 == 0 ) {
struct V_118 * V_239 ;
V_239 = V_112 [ V_238 . V_131 ] . V_113 ;
V_239 -> V_217 = V_238 . V_218 ;
V_239 -> V_217 . V_221 = 0 ;
F_59 ( V_239 -> V_222 ) ;
V_239 -> V_222 = F_60 ( F_61 ( V_136 ) ) ;
}
F_46 () ;
if ( V_85 )
break;
F_65 ( V_238 . V_131 ) ;
}
break;
}
case V_240 :
if ( ! V_30 )
goto V_140;
if ( V_129 == 0 || V_129 > V_232 )
V_85 = - V_153 ;
else
V_85 = F_14 ( V_129 ) ;
break;
case V_241 :
if ( ! V_30 )
goto V_140;
if ( V_119 -> V_217 . V_218 != V_220 ) {
V_85 = - V_22 ;
break;
}
F_43 () ;
if ( V_119 -> V_223 >= 0 ) {
if ( V_129 == 0 )
V_119 -> V_223 = - 1 ;
else {
int V_242 ;
V_242 = V_119 -> V_223 ;
V_119 -> V_223 = - 1 ;
V_85 = F_64 ( V_242 ) ;
if ( V_85 ) {
F_46 () ;
break;
}
F_66 ( V_112 [ V_242 ] . V_113 ) ;
}
} else {
if ( V_129 != V_243 )
V_85 = - V_22 ;
}
F_46 () ;
break;
case V_244 :
if ( V_129 > V_232 ) {
V_85 = - V_153 ;
break;
}
if ( V_129 == 0 ) {
F_43 () ;
for ( V_41 = 1 ; V_41 < V_232 ; V_41 ++ )
if ( ! F_67 ( V_41 ) )
F_68 ( V_41 ) ;
F_46 () ;
} else {
V_129 -- ;
if ( F_67 ( V_129 ) )
V_85 = - V_245 ;
else if ( V_129 ) {
F_43 () ;
F_68 ( V_129 ) ;
F_46 () ;
}
}
break;
case V_246 :
{
struct V_247 T_1 * V_248 = V_78 ;
struct V_118 * V_119 ;
T_2 V_249 , V_250 ;
if ( ! V_30 )
goto V_140;
if ( F_52 ( V_249 , & V_248 -> V_251 ) ||
F_52 ( V_250 , & V_248 -> V_252 ) )
V_85 = - V_20 ;
else {
F_43 () ;
for ( V_41 = 0 ; V_41 < V_232 ; V_41 ++ ) {
V_119 = V_112 [ V_41 ] . V_113 ;
if ( V_119 ) {
V_119 -> V_253 = 1 ;
F_69 ( V_112 [ V_41 ] . V_113 , V_250 , V_249 ) ;
}
}
F_46 () ;
}
break;
}
case V_254 :
{
struct V_255 T_1 * V_256 = V_78 ;
T_2 V_249 , V_250 , V_257 , V_258 , V_259 , V_260 ;
if ( ! V_30 )
goto V_140;
if ( ! F_32 ( V_261 , V_256 ,
sizeof( struct V_255 ) ) ) {
V_85 = - V_20 ;
break;
}
F_70 ( V_249 , & V_256 -> V_251 ) ;
F_70 ( V_250 , & V_256 -> V_252 ) ;
F_70 ( V_257 , & V_256 -> V_262 ) ;
F_70 ( V_258 , & V_256 -> V_263 ) ;
F_70 ( V_259 , & V_256 -> V_264 ) ;
F_70 ( V_260 , & V_256 -> V_265 ) ;
V_257 = V_257 ? V_257 : V_119 -> V_266 ;
if ( V_258 ) {
if ( V_249 ) {
if ( V_249 != V_257 / V_258 ) {
V_85 = - V_22 ;
break;
}
} else
V_249 = V_257 / V_258 ;
}
if ( V_259 && V_260 ) {
if ( V_250 ) {
if ( V_250 != V_259 / V_260 ) {
V_85 = - V_22 ;
break;
}
} else
V_250 = V_259 / V_260 ;
}
if ( V_258 > 32 ) {
V_85 = - V_22 ;
break;
}
for ( V_41 = 0 ; V_41 < V_232 ; V_41 ++ ) {
if ( ! V_112 [ V_41 ] . V_113 )
continue;
F_43 () ;
if ( V_257 )
V_112 [ V_41 ] . V_113 -> V_266 = V_257 ;
if ( V_258 )
V_112 [ V_41 ] . V_113 -> V_267 . V_107 = V_258 ;
V_112 [ V_41 ] . V_113 -> V_253 = 1 ;
F_69 ( V_112 [ V_41 ] . V_113 , V_250 , V_249 ) ;
F_46 () ;
}
break;
}
case V_268 : {
if ( ! V_30 )
goto V_140;
V_101 . V_101 = V_104 ;
V_101 . V_7 = V_105 | V_269 ;
V_101 . V_106 = 8 ;
V_101 . V_107 = 0 ;
V_101 . V_109 = 256 ;
V_101 . V_110 = V_78 ;
V_85 = F_30 ( V_112 [ V_25 ] . V_113 , & V_101 ) ;
break;
}
case V_270 : {
V_101 . V_101 = V_115 ;
V_101 . V_7 = V_105 ;
V_101 . V_106 = 8 ;
V_101 . V_107 = 32 ;
V_101 . V_109 = 256 ;
V_101 . V_110 = V_78 ;
V_85 = F_30 ( V_112 [ V_25 ] . V_113 , & V_101 ) ;
break;
}
case V_271 :
if ( ! V_30 )
V_85 = - V_49 ;
else
V_85 = F_71 ( V_78 ) ;
break;
case V_272 :
V_85 = F_72 ( V_78 ) ;
break;
case V_103 :
case V_114 :
V_85 = F_29 ( V_27 , V_78 , V_30 , & V_101 ) ;
break;
case V_273 :
{
if ( ! V_30 )
goto V_140;
#ifdef F_73
V_85 = - V_274 ;
break;
#else
{
V_101 . V_101 = V_275 ;
V_101 . V_110 = NULL ;
V_85 = F_30 ( V_112 [ V_25 ] . V_113 , & V_101 ) ;
if ( V_85 )
break;
F_74 ( V_112 [ V_25 ] . V_113 ) ;
break;
}
#endif
}
case V_276 : {
if ( F_12 ( & V_101 , V_78 , sizeof( V_101 ) ) ) {
V_85 = - V_20 ;
break;
}
if ( ! V_30 && V_101 . V_101 != V_115 )
goto V_140;
V_85 = F_30 ( V_119 , & V_101 ) ;
if ( V_85 )
break;
if ( F_13 ( V_78 , & V_101 , sizeof( V_101 ) ) )
V_85 = - V_20 ;
break;
}
case V_277 :
if ( ! V_30 )
V_85 = - V_49 ;
else
V_85 = F_75 ( V_78 ) ;
break;
case V_278 :
V_85 = F_76 ( V_78 ) ;
break;
case V_279 :
if ( ! V_30 )
V_85 = - V_49 ;
else
V_85 = F_77 ( V_78 ) ;
break;
case V_280 :
V_85 = F_78 ( V_78 ) ;
break;
case V_281 :
{ struct V_282 V_283 ;
if ( ! V_30 )
goto V_140;
V_85 = F_12 ( & V_283 , V_78 , sizeof( struct V_282 ) ) ;
if ( V_85 )
V_85 = - V_20 ;
else
F_79 ( V_119 , & V_283 ) ;
break;
}
case V_124 :
case V_125 :
V_85 = F_31 ( V_27 , V_78 , V_30 , V_119 ) ;
break;
case V_284 :
if ( ! F_16 ( V_37 ) )
goto V_140;
V_285 = 1 ;
break;
case V_286 :
if ( ! F_16 ( V_37 ) )
goto V_140;
V_285 = 0 ;
break;
case V_287 :
V_85 = F_19 ( V_119 -> V_288 ,
( unsigned short T_1 * ) V_129 ) ;
break;
case V_289 :
V_85 = F_11 ( (struct V_19 T_1 * ) V_129 ) ;
break;
default:
V_85 = - V_134 ;
}
V_135:
F_80 () ;
return V_85 ;
V_140:
V_85 = - V_49 ;
goto V_135;
}
void F_81 ( struct V_118 * V_119 )
{
V_119 -> V_165 = V_164 ;
V_137 [ V_119 -> V_126 ] . V_42 = V_290 ? V_43 : V_176 ;
V_119 -> V_217 . V_218 = V_219 ;
V_119 -> V_217 . V_291 = 0 ;
V_119 -> V_217 . V_292 = 0 ;
V_119 -> V_217 . V_293 = 0 ;
V_119 -> V_217 . V_221 = 0 ;
F_59 ( V_119 -> V_222 ) ;
V_119 -> V_222 = NULL ;
V_119 -> V_223 = - 1 ;
if ( ! F_82 () )
F_83 ( V_119 ) ;
}
void F_84 ( struct V_294 * V_295 )
{
struct V_119 * V_296 =
F_85 ( V_295 , struct V_119 , V_297 ) ;
struct V_118 * V_119 ;
struct V_127 * V_128 ;
F_43 () ;
V_119 = V_296 -> V_113 ;
if ( V_119 ) {
V_128 = V_119 -> V_298 . V_128 ;
if ( V_128 )
F_86 ( V_128 ) ;
F_81 ( V_119 ) ;
}
F_46 () ;
}
static inline int
F_87 ( int V_27 , struct V_299 T_1 * V_99 ,
int V_30 , struct V_100 * V_101 )
{
struct V_299 V_102 ;
int V_41 ;
if ( F_12 ( & V_102 , V_99 , sizeof( struct V_299 ) ) )
return - V_20 ;
switch ( V_27 ) {
case V_103 :
if ( ! V_30 )
return - V_49 ;
V_101 -> V_101 = V_104 ;
V_101 -> V_7 = V_105 ;
V_101 -> V_106 = 8 ;
V_101 -> V_107 = V_102 . V_108 ;
V_101 -> V_109 = V_102 . V_109 ;
V_101 -> V_110 = F_88 ( V_102 . V_111 ) ;
return F_30 ( V_112 [ V_25 ] . V_113 , V_101 ) ;
case V_114 :
V_101 -> V_101 = V_115 ;
V_101 -> V_7 = V_105 ;
V_101 -> V_106 = 8 ;
V_101 -> V_107 = V_102 . V_108 ;
V_101 -> V_109 = V_102 . V_109 ;
V_101 -> V_110 = F_88 ( V_102 . V_111 ) ;
V_41 = F_30 ( V_112 [ V_25 ] . V_113 , V_101 ) ;
if ( V_41 )
return V_41 ;
V_102 . V_108 = V_101 -> V_107 ;
V_102 . V_109 = V_101 -> V_109 ;
if ( F_13 ( V_99 , & V_102 , sizeof( struct V_299 ) ) )
return - V_20 ;
return 0 ;
}
return - V_22 ;
}
static inline int
F_89 ( struct V_300 T_1 * V_301 ,
int V_30 , struct V_100 * V_101 , struct V_118 * V_119 )
{
int V_41 ;
if ( F_12 ( V_101 , V_301 , sizeof( struct V_300 ) ) )
return - V_20 ;
if ( ! V_30 && V_101 -> V_101 != V_115 )
return - V_49 ;
V_101 -> V_110 = F_88 ( ( (struct V_300 * ) V_101 ) -> V_110 ) ;
V_101 -> V_7 |= V_105 ;
V_41 = F_30 ( V_119 , V_101 ) ;
if ( V_41 )
return V_41 ;
( (struct V_300 * ) V_101 ) -> V_110 = ( unsigned long ) V_101 -> V_110 ;
if ( F_13 ( V_301 , V_101 , sizeof( struct V_300 ) ) )
return - V_20 ;
return 0 ;
}
static inline int
F_90 ( unsigned int V_27 , struct V_302 T_1 * V_117 ,
int V_30 , struct V_118 * V_119 )
{
struct V_302 V_33 ;
struct V_123 T_1 * V_303 ;
if ( F_12 ( & V_33 , V_117 , sizeof V_33 ) )
return - V_20 ;
V_303 = F_88 ( V_33 . V_120 ) ;
if ( V_303 )
if ( ! F_32 ( V_121 , V_303 ,
V_33 . V_122 * sizeof( struct V_123 ) ) )
return - V_20 ;
switch ( V_27 ) {
case V_124 :
if ( ! V_30 )
return - V_49 ;
return F_33 ( V_119 , V_33 . V_122 , V_303 ) ;
case V_125 :
if ( ! V_30 && V_25 != V_119 -> V_126 )
return - V_49 ;
return F_34 ( V_119 , V_33 . V_122 , & ( V_117 -> V_122 ) , V_303 ) ;
}
return 0 ;
}
long F_91 ( struct V_127 * V_128 ,
unsigned int V_27 , unsigned long V_129 )
{
struct V_118 * V_119 = V_128 -> V_130 ;
struct V_100 V_101 ;
unsigned int V_131 ;
void T_1 * V_78 = ( void T_1 * ) V_129 ;
int V_30 ;
int V_85 = 0 ;
V_131 = V_119 -> V_126 ;
F_36 () ;
if ( ! F_37 ( V_131 ) ) {
V_85 = - V_134 ;
goto V_135;
}
V_30 = 0 ;
if ( V_136 -> signal -> V_128 == V_128 || F_16 ( V_37 ) )
V_30 = 1 ;
switch ( V_27 ) {
case V_103 :
case V_114 :
V_85 = F_87 ( V_27 , V_78 , V_30 , & V_101 ) ;
break;
case V_276 :
V_85 = F_89 ( V_78 , V_30 , & V_101 , V_119 ) ;
break;
case V_124 :
case V_125 :
V_85 = F_90 ( V_27 , V_78 , V_30 , V_119 ) ;
break;
case V_139 :
case V_142 :
#ifdef F_40
case V_149 :
case V_150 :
#endif
case V_160 :
case V_168 :
case V_169 :
case V_170 :
case V_181 :
case V_206 :
case V_208 :
case V_209 :
case V_235 :
case V_240 :
case V_241 :
case V_244 :
case V_246 :
case V_254 :
goto V_304;
default:
V_129 = ( unsigned long ) F_88 ( V_129 ) ;
goto V_304;
}
V_135:
F_80 () ;
return V_85 ;
V_304:
F_80 () ;
return F_35 ( V_128 , V_27 , V_129 ) ;
}
static void F_66 ( struct V_118 * V_119 )
{
unsigned char V_305 ;
int V_2 = V_25 ;
V_306 = V_25 ;
V_305 = V_112 [ V_25 ] . V_113 -> V_165 ;
F_92 ( V_119 ) ;
if ( V_305 != V_119 -> V_165 ) {
if ( V_119 -> V_165 == V_164 )
F_44 ( 1 ) ;
else
F_45 ( 1 ) ;
}
if ( V_119 -> V_217 . V_218 == V_220 ) {
if ( F_93 ( V_119 -> V_222 , V_119 -> V_217 . V_293 , 1 ) != 0 ) {
F_81 ( V_119 ) ;
if ( V_305 != V_119 -> V_165 ) {
if ( V_119 -> V_165 == V_164 )
F_44 ( 1 ) ;
else
F_45 ( 1 ) ;
}
}
}
F_1 ( V_26 , V_2 , V_119 -> V_126 ) ;
return;
}
void F_94 ( struct V_118 * V_307 )
{
struct V_118 * V_119 ;
if ( ! V_307 || V_307 -> V_126 == V_25 || V_285 )
return;
V_119 = V_112 [ V_25 ] . V_113 ;
if ( V_119 -> V_217 . V_218 == V_220 ) {
V_119 -> V_223 = V_307 -> V_126 ;
if ( F_93 ( V_119 -> V_222 , V_119 -> V_217 . V_292 , 1 ) == 0 ) {
return;
}
F_81 ( V_119 ) ;
}
if ( V_119 -> V_165 == V_161 )
return;
F_66 ( V_307 ) ;
}
int F_95 ( unsigned int V_308 , int V_309 )
{
int V_310 ;
F_43 () ;
if ( V_311 ) {
F_46 () ;
return 0 ;
}
V_310 = V_25 ;
if ( V_309 && F_64 ( V_308 ) ) {
F_46 () ;
return - V_312 ;
}
if ( F_65 ( V_308 ) ) {
F_46 () ;
return - V_313 ;
}
F_46 () ;
F_36 () ;
if ( F_14 ( V_308 + 1 ) ) {
F_96 ( L_1 ) ;
F_80 () ;
return - V_23 ;
}
F_80 () ;
return V_310 ;
}
void F_97 ( int V_314 )
{
F_43 () ;
V_311 = ! V_314 ;
F_46 () ;
}

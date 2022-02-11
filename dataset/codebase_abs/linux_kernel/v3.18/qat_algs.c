static int F_1 ( void )
{
return F_2 ( F_3 () -> V_1 ) . V_2 ;
}
static int F_4 ( enum V_3 V_4 )
{
switch ( V_4 ) {
case V_5 :
return V_6 ;
case V_7 :
return V_8 ;
case V_9 :
return V_10 ;
default:
return - V_11 ;
} ;
return - V_11 ;
}
static int F_5 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
const T_1 * V_16 ,
unsigned int V_17 )
{
struct V_18 V_19 ;
F_6 ( V_20 , V_15 -> V_21 ) ;
struct V_22 V_23 ;
struct V_24 V_25 ;
struct V_26 V_27 ;
int V_28 = F_7 ( V_15 -> V_21 ) ;
int V_29 = F_8 ( V_15 -> V_21 ) ;
T_1 * V_30 = V_19 . V_31 ;
T_1 * V_32 = V_30 + V_28 ;
T_2 * V_33 ;
T_3 * V_34 ;
int V_35 , V_36 ;
memset ( V_19 . V_31 , '\0' , V_37 + 64 ) ;
V_20 -> V_38 = V_15 -> V_21 ;
V_20 -> V_39 = 0x0 ;
if ( V_17 > V_28 ) {
char V_40 [ V_41 ] ;
int V_42 = F_9 ( V_20 , V_16 ,
V_17 , V_40 ) ;
if ( V_42 )
return V_42 ;
memcpy ( V_30 , V_40 , V_29 ) ;
memcpy ( V_32 , V_40 , V_29 ) ;
memset ( V_30 + V_29 , 0 , V_28 - V_29 ) ;
memset ( V_32 + V_29 , 0 , V_28 - V_29 ) ;
} else {
memcpy ( V_30 , V_16 , V_17 ) ;
memcpy ( V_32 , V_16 , V_17 ) ;
memset ( V_30 + V_17 , 0 , V_28 - V_17 ) ;
memset ( V_32 + V_17 , 0 , V_28 - V_17 ) ;
}
for ( V_35 = 0 ; V_35 < V_28 ; V_35 ++ ) {
char * V_43 = V_30 + V_35 ;
char * V_44 = V_32 + V_35 ;
* V_43 ^= 0x36 ;
* V_44 ^= 0x5C ;
}
if ( F_10 ( V_20 ) )
return - V_11 ;
if ( F_11 ( V_20 , V_30 , V_28 ) )
return - V_11 ;
V_33 = ( T_2 * ) V_13 -> V_45 . V_46 ;
V_34 = ( T_3 * ) V_33 ;
switch ( V_15 -> V_4 ) {
case V_5 :
if ( F_12 ( V_20 , & V_23 ) )
return - V_11 ;
for ( V_35 = 0 ; V_35 < V_29 > > 2 ; V_35 ++ , V_33 ++ )
* V_33 = F_13 ( * ( V_23 . V_47 + V_35 ) ) ;
break;
case V_7 :
if ( F_12 ( V_20 , & V_25 ) )
return - V_11 ;
for ( V_35 = 0 ; V_35 < V_29 > > 2 ; V_35 ++ , V_33 ++ )
* V_33 = F_13 ( * ( V_25 . V_47 + V_35 ) ) ;
break;
case V_9 :
if ( F_12 ( V_20 , & V_27 ) )
return - V_11 ;
for ( V_35 = 0 ; V_35 < V_29 > > 3 ; V_35 ++ , V_34 ++ )
* V_34 = F_14 ( * ( V_27 . V_47 + V_35 ) ) ;
break;
default:
return - V_11 ;
}
if ( F_10 ( V_20 ) )
return - V_11 ;
if ( F_11 ( V_20 , V_32 , V_28 ) )
return - V_11 ;
V_36 = F_15 ( F_4 ( V_15 -> V_4 ) , 8 ) ;
V_33 = ( T_2 * ) ( V_13 -> V_45 . V_46 + V_36 ) ;
V_34 = ( T_3 * ) V_33 ;
switch ( V_15 -> V_4 ) {
case V_5 :
if ( F_12 ( V_20 , & V_23 ) )
return - V_11 ;
for ( V_35 = 0 ; V_35 < V_29 > > 2 ; V_35 ++ , V_33 ++ )
* V_33 = F_13 ( * ( V_23 . V_47 + V_35 ) ) ;
break;
case V_7 :
if ( F_12 ( V_20 , & V_25 ) )
return - V_11 ;
for ( V_35 = 0 ; V_35 < V_29 > > 2 ; V_35 ++ , V_33 ++ )
* V_33 = F_13 ( * ( V_25 . V_47 + V_35 ) ) ;
break;
case V_9 :
if ( F_12 ( V_20 , & V_27 ) )
return - V_11 ;
for ( V_35 = 0 ; V_35 < V_29 > > 3 ; V_35 ++ , V_34 ++ )
* V_34 = F_14 ( * ( V_27 . V_47 + V_35 ) ) ;
break;
default:
return - V_11 ;
}
return 0 ;
}
static void F_16 ( struct V_48 * V_49 )
{
V_49 -> V_50 =
F_17 ( V_51 ) ;
V_49 -> V_52 = V_53 ;
V_49 -> V_54 =
F_18 ( V_55 ,
V_56 ) ;
F_19 ( V_49 -> V_57 ,
V_58 ) ;
F_20 ( V_49 -> V_57 ,
V_59 ) ;
F_21 ( V_49 -> V_57 ,
V_60 ) ;
F_22 ( V_49 -> V_57 ,
V_61 ) ;
F_23 ( V_49 -> V_57 ,
V_62 ) ;
}
static int F_24 ( struct V_14 * V_15 ,
int V_63 , struct V_64 * V_65 )
{
struct V_66 * V_67 = F_25 ( V_15 -> V_38 ) ;
unsigned int V_68 = F_26 ( V_67 ) -> V_69 ;
struct V_70 * V_71 = & V_15 -> V_72 -> V_73 ;
struct V_74 * V_75 = & V_71 -> V_75 ;
struct V_12 * V_13 =
(struct V_12 * ) ( ( char * ) V_71 +
sizeof( struct V_76 ) + V_65 -> V_77 ) ;
struct V_78 * V_79 = & V_15 -> V_80 ;
struct V_81 * V_82 = & V_79 -> V_82 ;
struct V_48 * V_49 = & V_79 -> V_83 ;
void * V_84 = & V_79 -> V_85 ;
struct V_86 * V_87 = V_84 ;
struct V_88 * V_89 = V_84 ;
V_75 -> V_90 . V_91 . V_92 = F_27 ( V_63 ) ;
memcpy ( V_75 -> V_90 . V_93 , V_65 -> V_94 , V_65 -> V_77 ) ;
V_13 -> V_45 . V_95 . V_96 . V_97 =
F_28 ( V_98 ,
V_15 -> V_4 , V_68 ) ;
V_13 -> V_45 . V_95 . V_99 . V_100 =
F_13 ( F_7 ( V_15 -> V_21 ) ) ;
if ( F_5 ( V_13 , V_15 , V_65 -> V_101 , V_65 -> V_102 ) )
return - V_11 ;
F_16 ( V_49 ) ;
V_49 -> V_103 = V_104 ;
F_29 ( V_49 -> V_57 ,
V_105 ) ;
F_30 ( V_49 -> V_57 ,
V_106 ) ;
V_82 -> V_107 . V_108 . V_109 = V_15 -> V_110 ;
V_82 -> V_107 . V_108 . V_111 = sizeof( struct V_112 ) >> 3 ;
V_87 -> V_113 = V_65 -> V_77 >> 3 ;
V_87 -> V_114 = V_115 >> 3 ;
V_87 -> V_116 = 0 ;
F_31 ( V_87 , V_117 ) ;
F_32 ( V_87 , V_118 ) ;
V_89 -> V_119 = ( ( char * ) V_13 - ( char * ) V_75 ) >> 3 ;
V_89 -> V_120 = V_121 ;
V_89 -> V_122 = V_68 ;
V_89 -> V_123 = V_68 ;
switch ( V_15 -> V_4 ) {
case V_5 :
V_89 -> V_124 =
F_15 ( V_6 , 8 ) ;
V_89 -> V_125 =
F_15 ( V_126 , 8 ) ;
break;
case V_7 :
V_89 -> V_124 = V_8 ;
V_89 -> V_125 = V_127 ;
break;
case V_9 :
V_89 -> V_124 = V_10 ;
V_89 -> V_125 = V_128 ;
break;
default:
break;
}
V_89 -> V_129 = V_89 -> V_119 +
( ( sizeof( struct V_76 ) +
F_15 ( V_89 -> V_124 , 8 ) ) >> 3 ) ;
F_31 ( V_89 , V_118 ) ;
F_32 ( V_89 , V_130 ) ;
return 0 ;
}
static int F_33 ( struct V_14 * V_15 ,
int V_63 , struct V_64 * V_65 )
{
struct V_66 * V_67 = F_25 ( V_15 -> V_38 ) ;
unsigned int V_68 = F_26 ( V_67 ) -> V_69 ;
struct V_131 * V_132 = & V_15 -> V_133 -> V_134 ;
struct V_12 * V_13 = & V_132 -> V_13 ;
struct V_74 * V_75 =
(struct V_74 * ) ( ( char * ) V_132 +
sizeof( struct V_76 ) +
F_34 ( F_8 ( V_15 -> V_21 ) , 8 ) * 2 ) ;
struct V_78 * V_79 = & V_15 -> V_135 ;
struct V_81 * V_82 = & V_79 -> V_82 ;
struct V_48 * V_49 = & V_79 -> V_83 ;
void * V_84 = & V_79 -> V_85 ;
struct V_86 * V_87 = V_84 ;
struct V_88 * V_89 = V_84 ;
struct V_136 * V_137 =
(struct V_136 * )
( ( char * ) & V_79 -> V_138 +
sizeof( struct V_139 ) ) ;
V_75 -> V_90 . V_91 . V_92 = F_35 ( V_63 ) ;
memcpy ( V_75 -> V_90 . V_93 , V_65 -> V_94 , V_65 -> V_77 ) ;
V_13 -> V_45 . V_95 . V_96 . V_97 =
F_28 ( V_98 ,
V_15 -> V_4 ,
V_68 ) ;
V_13 -> V_45 . V_95 . V_99 . V_100 =
F_13 ( F_7 ( V_15 -> V_21 ) ) ;
if ( F_5 ( V_13 , V_15 , V_65 -> V_101 , V_65 -> V_102 ) )
return - V_11 ;
F_16 ( V_49 ) ;
V_49 -> V_103 = V_140 ;
F_29 ( V_49 -> V_57 ,
V_141 ) ;
F_30 ( V_49 -> V_57 ,
V_142 ) ;
V_82 -> V_107 . V_108 . V_109 = V_15 -> V_143 ;
V_82 -> V_107 . V_108 . V_111 = sizeof( struct V_112 ) >> 3 ;
V_87 -> V_113 = V_65 -> V_77 >> 3 ;
V_87 -> V_114 = V_115 >> 3 ;
V_87 -> V_116 =
( sizeof( struct V_76 ) +
F_34 ( F_8 ( V_15 -> V_21 ) , 8 ) * 2 ) >> 3 ;
F_31 ( V_87 , V_117 ) ;
F_32 ( V_87 , V_130 ) ;
V_89 -> V_119 = 0 ;
V_89 -> V_120 = V_121 ;
V_89 -> V_122 = V_68 ;
V_89 -> V_123 = V_68 ;
switch ( V_15 -> V_4 ) {
case V_5 :
V_89 -> V_124 =
F_15 ( V_6 , 8 ) ;
V_89 -> V_125 =
F_15 ( V_126 , 8 ) ;
break;
case V_7 :
V_89 -> V_124 = V_8 ;
V_89 -> V_125 = V_127 ;
break;
case V_9 :
V_89 -> V_124 = V_10 ;
V_89 -> V_125 = V_128 ;
break;
default:
break;
}
V_89 -> V_129 = V_89 -> V_119 +
( ( sizeof( struct V_76 ) +
F_15 ( V_89 -> V_124 , 8 ) ) >> 3 ) ;
V_137 -> V_144 = V_68 ;
F_31 ( V_89 , V_118 ) ;
F_32 ( V_89 , V_117 ) ;
return 0 ;
}
static int F_36 ( struct V_14 * V_15 ,
const T_1 * V_93 , unsigned int V_145 )
{
struct V_64 V_65 ;
int V_63 ;
if ( F_37 ( V_146 , V_15 -> V_147 , V_115 ) )
return - V_11 ;
if ( F_38 ( & V_65 , V_93 , V_145 ) )
goto V_148;
switch ( V_65 . V_77 ) {
case V_149 :
V_63 = V_150 ;
break;
case V_151 :
V_63 = V_152 ;
break;
case V_153 :
V_63 = V_154 ;
break;
default:
goto V_148;
break;
}
if ( F_24 ( V_15 , V_63 , & V_65 ) )
goto error;
if ( F_33 ( V_15 , V_63 , & V_65 ) )
goto error;
return 0 ;
V_148:
F_39 ( V_15 -> V_38 , V_155 ) ;
return - V_156 ;
error:
return - V_11 ;
}
static int F_40 ( struct V_66 * V_38 , const T_1 * V_93 ,
unsigned int V_145 )
{
struct V_14 * V_15 = F_41 ( V_38 ) ;
struct V_157 * V_158 ;
F_42 ( & V_15 -> V_159 ) ;
if ( V_15 -> V_72 ) {
V_158 = & F_43 ( V_15 -> V_160 -> V_161 ) ;
memset ( V_15 -> V_72 , 0 , sizeof( struct V_112 ) ) ;
memset ( V_15 -> V_133 , 0 , sizeof( struct V_112 ) ) ;
memset ( & V_15 -> V_80 , 0 ,
sizeof( struct V_78 ) ) ;
memset ( & V_15 -> V_135 , 0 ,
sizeof( struct V_78 ) ) ;
} else {
int V_162 = F_1 () ;
struct V_163 * V_160 =
F_44 ( V_162 ) ;
if ( ! V_160 ) {
F_45 ( & V_15 -> V_159 ) ;
return - V_156 ;
}
V_158 = & F_43 ( V_160 -> V_161 ) ;
V_15 -> V_160 = V_160 ;
V_15 -> V_72 = F_46 ( V_158 ,
sizeof( struct V_112 ) ,
& V_15 -> V_110 ,
V_164 ) ;
if ( ! V_15 -> V_72 ) {
F_45 ( & V_15 -> V_159 ) ;
return - V_165 ;
}
V_15 -> V_133 = F_46 ( V_158 ,
sizeof( struct V_112 ) ,
& V_15 -> V_143 ,
V_164 ) ;
if ( ! V_15 -> V_133 ) {
F_45 ( & V_15 -> V_159 ) ;
goto V_166;
}
}
F_45 ( & V_15 -> V_159 ) ;
if ( F_36 ( V_15 , V_93 , V_145 ) )
goto V_167;
return 0 ;
V_167:
F_47 ( V_158 , sizeof( struct V_112 ) ,
V_15 -> V_133 , V_15 -> V_143 ) ;
V_15 -> V_133 = NULL ;
V_166:
F_47 ( V_158 , sizeof( struct V_112 ) ,
V_15 -> V_72 , V_15 -> V_110 ) ;
V_15 -> V_72 = NULL ;
return - V_165 ;
}
static void F_48 ( struct V_163 * V_160 ,
struct V_168 * V_169 )
{
struct V_157 * V_158 = & F_43 ( V_160 -> V_161 ) ;
struct V_170 * V_171 = V_169 -> V_172 . V_171 ;
struct V_170 * V_173 = V_169 -> V_172 . V_173 ;
T_4 V_174 = V_169 -> V_172 . V_174 ;
T_4 V_175 = V_169 -> V_172 . V_176 ;
T_5 V_177 = V_169 -> V_172 . V_177 ;
int V_35 , V_178 = V_171 -> V_179 ;
for ( V_35 = 0 ; V_35 < V_171 -> V_179 ; V_35 ++ )
F_49 ( V_158 , V_171 -> V_180 [ V_35 ] . V_181 ,
V_171 -> V_180 [ V_35 ] . V_182 , V_183 ) ;
F_49 ( V_158 , V_174 , V_177 , V_184 ) ;
F_50 ( V_171 ) ;
if ( V_174 != V_175 ) {
int V_185 = V_178 - V_173 -> V_186 ;
for ( V_35 = V_185 ; V_35 < V_178 ; V_35 ++ ) {
F_49 ( V_158 , V_173 -> V_180 [ V_35 ] . V_181 ,
V_173 -> V_180 [ V_35 ] . V_182 ,
V_183 ) ;
}
F_49 ( V_158 , V_175 , V_177 , V_184 ) ;
F_50 ( V_173 ) ;
}
}
static int F_51 ( struct V_163 * V_160 ,
struct V_187 * V_188 ,
struct V_187 * V_189 ,
struct V_187 * V_190 , T_1 * V_191 ,
T_1 V_192 ,
struct V_168 * V_169 )
{
struct V_157 * V_158 = & F_43 ( V_160 -> V_161 ) ;
int V_35 , V_178 = 0 , V_193 = F_52 ( V_189 ) , V_194 = F_52 ( V_188 ) ;
struct V_170 * V_195 ;
struct V_170 * V_196 = NULL ;
T_4 V_174 ;
T_4 V_176 = 0 ;
struct V_187 * V_197 ;
T_5 V_177 = sizeof( struct V_170 ) +
( ( 1 + V_193 + V_194 ) * sizeof( struct V_198 ) ) ;
if ( F_53 ( ! V_193 ) )
return - V_156 ;
V_195 = F_54 ( V_177 , V_164 ,
F_55 ( & F_43 ( V_160 -> V_161 ) ) ) ;
if ( F_53 ( ! V_195 ) )
return - V_165 ;
V_174 = F_56 ( V_158 , V_195 , V_177 , V_184 ) ;
if ( F_53 ( F_57 ( V_158 , V_174 ) ) )
goto V_199;
F_58 (assoc, sg, assoc_n, i) {
if ( ! V_197 -> V_200 )
continue;
V_195 -> V_180 [ V_178 ] . V_181 = F_56 ( V_158 ,
F_59 ( V_197 ) ,
V_197 -> V_200 ,
V_183 ) ;
V_195 -> V_180 [ V_178 ] . V_182 = V_197 -> V_200 ;
if ( F_53 ( F_57 ( V_158 , V_195 -> V_180 [ V_178 ] . V_181 ) ) )
goto V_199;
V_178 ++ ;
}
V_195 -> V_180 [ V_178 ] . V_181 = F_56 ( V_158 , V_191 , V_192 ,
V_183 ) ;
V_195 -> V_180 [ V_178 ] . V_182 = V_192 ;
if ( F_53 ( F_57 ( V_158 , V_195 -> V_180 [ V_178 ] . V_181 ) ) )
goto V_199;
V_178 ++ ;
F_58 (sgl, sg, n, i) {
int V_201 = V_35 + V_178 ;
V_195 -> V_180 [ V_201 ] . V_181 = F_56 ( V_158 , F_59 ( V_197 ) ,
V_197 -> V_200 ,
V_183 ) ;
V_195 -> V_180 [ V_201 ] . V_182 = V_197 -> V_200 ;
if ( F_53 ( F_57 ( V_158 , V_195 -> V_180 [ V_201 ] . V_181 ) ) )
goto V_199;
}
V_195 -> V_179 = V_193 + V_178 ;
V_169 -> V_172 . V_171 = V_195 ;
V_169 -> V_172 . V_174 = V_174 ;
V_169 -> V_172 . V_177 = V_177 ;
if ( V_189 != V_190 ) {
struct V_198 * V_180 ;
V_196 = F_54 ( V_177 , V_164 ,
F_55 ( & F_43 ( V_160 -> V_161 ) ) ) ;
if ( F_53 ( ! V_196 ) )
goto V_199;
V_176 = F_56 ( V_158 , V_196 , V_177 , V_184 ) ;
if ( F_53 ( F_57 ( V_158 , V_176 ) ) )
goto V_199;
V_180 = V_196 -> V_180 ;
for ( V_35 = 0 ; V_35 < V_178 ; V_35 ++ ) {
V_180 [ V_35 ] . V_182 = V_195 -> V_180 [ V_35 ] . V_182 ;
V_180 [ V_35 ] . V_181 = V_195 -> V_180 [ V_35 ] . V_181 ;
}
F_58 (sglout, sg, n, i) {
int V_201 = V_35 + V_178 ;
V_180 [ V_201 ] . V_181 = F_56 ( V_158 , F_59 ( V_197 ) ,
V_197 -> V_200 ,
V_183 ) ;
V_196 -> V_180 [ V_201 ] . V_182 = V_197 -> V_200 ;
if ( F_53 ( F_57 ( V_158 , V_180 [ V_201 ] . V_181 ) ) )
goto V_199;
}
V_196 -> V_179 = V_193 + V_178 ;
V_196 -> V_186 = V_193 ;
V_169 -> V_172 . V_173 = V_196 ;
V_169 -> V_172 . V_176 = V_176 ;
} else {
V_169 -> V_172 . V_176 = V_169 -> V_172 . V_174 ;
}
return 0 ;
V_199:
F_60 ( V_158 , L_1 ) ;
F_58 (sgl, sg, n + bufs, i) {
if ( ! F_57 ( V_158 , V_195 -> V_180 [ V_35 ] . V_181 ) ) {
F_49 ( V_158 , V_195 -> V_180 [ V_35 ] . V_181 ,
V_195 -> V_180 [ V_35 ] . V_182 ,
V_183 ) ;
}
}
if ( ! F_57 ( V_158 , V_174 ) )
F_49 ( V_158 , V_174 , V_177 , V_184 ) ;
F_50 ( V_195 ) ;
if ( V_189 != V_190 && V_196 ) {
F_58 (sglout, sg, n, i) {
int V_201 = V_35 + V_178 ;
if ( ! F_57 ( V_158 , V_196 -> V_180 [ V_201 ] . V_181 ) )
F_49 ( V_158 , V_196 -> V_180 [ V_201 ] . V_181 ,
V_196 -> V_180 [ V_201 ] . V_182 ,
V_183 ) ;
}
if ( ! F_57 ( V_158 , V_176 ) )
F_49 ( V_158 , V_176 , V_177 , V_184 ) ;
F_50 ( V_196 ) ;
}
return - V_165 ;
}
void F_61 ( void * V_202 )
{
struct V_203 * V_204 = V_202 ;
struct V_168 * V_169 =
( void * ) ( V_205 long ) V_204 -> V_206 ;
struct V_14 * V_15 = V_169 -> V_15 ;
struct V_163 * V_160 = V_15 -> V_160 ;
struct V_207 * V_208 = V_169 -> V_208 ;
T_1 V_209 = V_204 -> V_210 . V_211 ;
int V_212 = 0 , V_213 = F_62 ( V_209 ) ;
F_48 ( V_160 , V_169 ) ;
if ( F_53 ( V_213 != V_214 ) )
V_212 = - V_215 ;
V_208 -> V_216 . V_217 ( & V_208 -> V_216 , V_212 ) ;
}
static int F_63 ( struct V_207 * V_208 )
{
struct V_66 * V_67 = F_64 ( V_208 ) ;
struct V_218 * V_38 = F_65 ( V_67 ) ;
struct V_14 * V_15 = F_66 ( V_38 ) ;
struct V_168 * V_169 = F_67 ( V_208 ) ;
struct V_139 * V_219 ;
struct V_136 * V_137 ;
struct V_78 * V_220 ;
int V_221 = F_26 ( V_67 ) -> V_69 ;
int V_42 , V_222 = 0 ;
V_42 = F_51 ( V_15 -> V_160 , V_208 -> V_188 , V_208 -> V_223 , V_208 -> V_224 ,
V_208 -> V_191 , V_115 , V_169 ) ;
if ( F_53 ( V_42 ) )
return V_42 ;
V_220 = & V_169 -> V_225 ;
* V_220 = V_15 -> V_135 ;
V_169 -> V_15 = V_15 ;
V_169 -> V_208 = V_208 ;
V_169 -> V_225 . V_226 . V_206 = ( V_227 ) ( V_205 long ) V_169 ;
V_169 -> V_225 . V_226 . V_228 = V_169 -> V_172 . V_174 ;
V_169 -> V_225 . V_226 . V_229 = V_169 -> V_172 . V_176 ;
V_219 = ( void * ) & V_169 -> V_225 . V_138 ;
V_219 -> V_230 = V_208 -> V_231 - V_221 ;
V_219 -> V_232 = V_208 -> V_233 + V_115 ;
memcpy ( V_219 -> V_107 . V_234 , V_208 -> V_191 , V_115 ) ;
V_137 = ( void * ) ( ( T_1 * ) V_219 + sizeof( * V_219 ) ) ;
V_137 -> V_235 = 0 ;
V_137 -> V_236 = V_208 -> V_233 +
V_219 -> V_230 + V_115 ;
do {
V_42 = F_68 ( V_15 -> V_160 -> V_237 , ( V_238 * ) V_220 ) ;
} while ( V_42 == - V_239 && V_222 ++ < 10 );
if ( V_42 == - V_239 ) {
F_48 ( V_15 -> V_160 , V_169 ) ;
return - V_240 ;
}
return - V_241 ;
}
static int F_69 ( struct V_207 * V_208 , T_1 * V_191 ,
int V_242 )
{
struct V_66 * V_67 = F_64 ( V_208 ) ;
struct V_218 * V_38 = F_65 ( V_67 ) ;
struct V_14 * V_15 = F_66 ( V_38 ) ;
struct V_168 * V_169 = F_67 ( V_208 ) ;
struct V_139 * V_219 ;
struct V_136 * V_137 ;
struct V_78 * V_220 ;
int V_42 , V_222 = 0 ;
V_42 = F_51 ( V_15 -> V_160 , V_208 -> V_188 , V_208 -> V_223 , V_208 -> V_224 ,
V_191 , V_115 , V_169 ) ;
if ( F_53 ( V_42 ) )
return V_42 ;
V_220 = & V_169 -> V_225 ;
* V_220 = V_15 -> V_80 ;
V_169 -> V_15 = V_15 ;
V_169 -> V_208 = V_208 ;
V_169 -> V_225 . V_226 . V_206 = ( V_227 ) ( V_205 long ) V_169 ;
V_169 -> V_225 . V_226 . V_228 = V_169 -> V_172 . V_174 ;
V_169 -> V_225 . V_226 . V_229 = V_169 -> V_172 . V_176 ;
V_219 = ( void * ) & V_169 -> V_225 . V_138 ;
V_137 = ( void * ) ( ( T_1 * ) V_219 + sizeof( * V_219 ) ) ;
if ( V_242 ) {
V_219 -> V_230 = V_208 -> V_231 + V_115 ;
V_219 -> V_232 = V_208 -> V_233 ;
} else {
memcpy ( V_219 -> V_107 . V_234 , V_191 , V_115 ) ;
V_219 -> V_230 = V_208 -> V_231 ;
V_219 -> V_232 = V_208 -> V_233 + V_115 ;
}
V_137 -> V_235 = 0 ;
V_137 -> V_236 = V_208 -> V_233 + V_208 -> V_231 + V_115 ;
do {
V_42 = F_68 ( V_15 -> V_160 -> V_237 , ( V_238 * ) V_220 ) ;
} while ( V_42 == - V_239 && V_222 ++ < 10 );
if ( V_42 == - V_239 ) {
F_48 ( V_15 -> V_160 , V_169 ) ;
return - V_240 ;
}
return - V_241 ;
}
static int F_70 ( struct V_207 * V_208 )
{
return F_69 ( V_208 , V_208 -> V_191 , 0 ) ;
}
static int F_71 ( struct V_243 * V_225 )
{
struct V_66 * V_67 = F_64 ( & V_225 -> V_208 ) ;
struct V_218 * V_38 = F_65 ( V_67 ) ;
struct V_14 * V_15 = F_66 ( V_38 ) ;
T_3 V_244 ;
memcpy ( V_225 -> V_245 , V_15 -> V_147 , V_115 ) ;
V_244 = F_14 ( V_225 -> V_244 ) ;
memcpy ( V_225 -> V_245 + V_115 - sizeof( V_227 ) ,
& V_244 , sizeof( V_227 ) ) ;
return F_69 ( & V_225 -> V_208 , V_225 -> V_245 , 1 ) ;
}
static int F_72 ( struct V_218 * V_38 ,
enum V_3 V_13 , const char * V_246 )
{
struct V_14 * V_15 = F_66 ( V_38 ) ;
memset ( V_15 , '\0' , sizeof( * V_15 ) ) ;
V_15 -> V_21 = F_73 ( V_246 , 0 , 0 ) ;
if ( F_74 ( V_15 -> V_21 ) )
return - V_11 ;
F_75 ( & V_15 -> V_159 ) ;
V_15 -> V_4 = V_13 ;
V_38 -> V_247 . V_248 = sizeof( struct V_207 ) +
sizeof( struct V_168 ) ;
V_15 -> V_38 = V_38 ;
return 0 ;
}
static int F_76 ( struct V_218 * V_38 )
{
return F_72 ( V_38 , V_5 , L_2 ) ;
}
static int F_77 ( struct V_218 * V_38 )
{
return F_72 ( V_38 , V_7 , L_3 ) ;
}
static int F_78 ( struct V_218 * V_38 )
{
return F_72 ( V_38 , V_9 , L_4 ) ;
}
static void F_79 ( struct V_218 * V_38 )
{
struct V_14 * V_15 = F_66 ( V_38 ) ;
struct V_163 * V_160 = V_15 -> V_160 ;
struct V_157 * V_158 ;
if ( ! F_74 ( V_15 -> V_21 ) )
F_80 ( V_15 -> V_21 ) ;
if ( ! V_160 )
return;
V_158 = & F_43 ( V_160 -> V_161 ) ;
if ( V_15 -> V_72 )
F_47 ( V_158 , sizeof( struct V_112 ) ,
V_15 -> V_72 , V_15 -> V_110 ) ;
if ( V_15 -> V_133 )
F_47 ( V_158 , sizeof( struct V_112 ) ,
V_15 -> V_133 , V_15 -> V_143 ) ;
F_81 ( V_160 ) ;
}
int F_82 ( void )
{
if ( F_83 ( 1 , & V_249 ) == 1 ) {
int V_35 ;
for ( V_35 = 0 ; V_35 < F_84 ( V_250 ) ; V_35 ++ )
V_250 [ V_35 ] . V_251 = V_252 |
V_253 ;
return F_85 ( V_250 , F_84 ( V_250 ) ) ;
}
return 0 ;
}
int F_86 ( void )
{
if ( F_87 ( 1 , & V_249 ) == 0 )
return F_88 ( V_250 , F_84 ( V_250 ) ) ;
return 0 ;
}
int F_89 ( void )
{
F_90 ( & V_249 , 0 ) ;
F_91 () ;
return 0 ;
}
void F_92 ( void )
{
F_93 () ;
}

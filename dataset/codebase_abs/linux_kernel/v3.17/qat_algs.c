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
unsigned int V_17 , T_1 * V_18 )
{
struct {
struct V_19 V_20 ;
char V_15 [ F_6 ( V_15 -> V_21 ) ] ;
} V_22 ;
struct V_23 V_24 ;
struct V_25 V_26 ;
struct V_27 V_28 ;
int V_29 = F_7 ( V_15 -> V_21 ) ;
int V_30 = F_8 ( V_15 -> V_21 ) ;
T_1 * V_31 = V_18 ;
T_1 * V_32 = V_31 + V_29 ;
T_2 * V_33 ;
T_3 * V_34 ;
int V_35 , V_36 ;
V_22 . V_20 . V_37 = V_15 -> V_21 ;
V_22 . V_20 . V_38 = 0x0 ;
if ( V_17 > V_29 ) {
char V_39 [ V_40 ] ;
int V_41 = F_9 ( & V_22 . V_20 , V_16 ,
V_17 , V_39 ) ;
if ( V_41 )
return V_41 ;
memcpy ( V_31 , V_39 , V_30 ) ;
memcpy ( V_32 , V_39 , V_30 ) ;
memset ( V_31 + V_30 , 0 , V_29 - V_30 ) ;
memset ( V_32 + V_30 , 0 , V_29 - V_30 ) ;
} else {
memcpy ( V_31 , V_16 , V_17 ) ;
memcpy ( V_32 , V_16 , V_17 ) ;
memset ( V_31 + V_17 , 0 , V_29 - V_17 ) ;
memset ( V_32 + V_17 , 0 , V_29 - V_17 ) ;
}
for ( V_35 = 0 ; V_35 < V_29 ; V_35 ++ ) {
char * V_42 = V_31 + V_35 ;
char * V_43 = V_32 + V_35 ;
* V_42 ^= 0x36 ;
* V_43 ^= 0x5C ;
}
if ( F_10 ( & V_22 . V_20 ) )
return - V_11 ;
if ( F_11 ( & V_22 . V_20 , V_31 , V_29 ) )
return - V_11 ;
V_33 = ( T_2 * ) V_13 -> V_44 . V_45 ;
V_34 = ( T_3 * ) V_33 ;
switch ( V_15 -> V_4 ) {
case V_5 :
if ( F_12 ( & V_22 . V_20 , & V_24 ) )
return - V_11 ;
for ( V_35 = 0 ; V_35 < V_30 > > 2 ; V_35 ++ , V_33 ++ )
* V_33 = F_13 ( * ( V_24 . V_46 + V_35 ) ) ;
break;
case V_7 :
if ( F_12 ( & V_22 . V_20 , & V_26 ) )
return - V_11 ;
for ( V_35 = 0 ; V_35 < V_30 > > 2 ; V_35 ++ , V_33 ++ )
* V_33 = F_13 ( * ( V_26 . V_46 + V_35 ) ) ;
break;
case V_9 :
if ( F_12 ( & V_22 . V_20 , & V_28 ) )
return - V_11 ;
for ( V_35 = 0 ; V_35 < V_30 > > 3 ; V_35 ++ , V_34 ++ )
* V_34 = F_14 ( * ( V_28 . V_46 + V_35 ) ) ;
break;
default:
return - V_11 ;
}
if ( F_10 ( & V_22 . V_20 ) )
return - V_11 ;
if ( F_11 ( & V_22 . V_20 , V_32 , V_29 ) )
return - V_11 ;
V_36 = F_15 ( F_4 ( V_15 -> V_4 ) , 8 ) ;
V_33 = ( T_2 * ) ( V_13 -> V_44 . V_45 + V_36 ) ;
V_34 = ( T_3 * ) V_33 ;
switch ( V_15 -> V_4 ) {
case V_5 :
if ( F_12 ( & V_22 . V_20 , & V_24 ) )
return - V_11 ;
for ( V_35 = 0 ; V_35 < V_30 > > 2 ; V_35 ++ , V_33 ++ )
* V_33 = F_13 ( * ( V_24 . V_46 + V_35 ) ) ;
break;
case V_7 :
if ( F_12 ( & V_22 . V_20 , & V_26 ) )
return - V_11 ;
for ( V_35 = 0 ; V_35 < V_30 > > 2 ; V_35 ++ , V_33 ++ )
* V_33 = F_13 ( * ( V_26 . V_46 + V_35 ) ) ;
break;
case V_9 :
if ( F_12 ( & V_22 . V_20 , & V_28 ) )
return - V_11 ;
for ( V_35 = 0 ; V_35 < V_30 > > 3 ; V_35 ++ , V_34 ++ )
* V_34 = F_14 ( * ( V_28 . V_46 + V_35 ) ) ;
break;
default:
return - V_11 ;
}
return 0 ;
}
static void F_16 ( struct V_47 * V_48 )
{
V_48 -> V_49 =
F_17 ( V_50 ) ;
V_48 -> V_51 = V_52 ;
V_48 -> V_53 =
F_18 ( V_54 ,
V_55 ) ;
F_19 ( V_48 -> V_56 ,
V_57 ) ;
F_20 ( V_48 -> V_56 ,
V_58 ) ;
F_21 ( V_48 -> V_56 ,
V_59 ) ;
F_22 ( V_48 -> V_56 ,
V_60 ) ;
F_23 ( V_48 -> V_56 ,
V_61 ) ;
}
static int F_24 ( struct V_14 * V_15 ,
int V_62 , struct V_63 * V_64 )
{
struct V_65 * V_66 = F_25 ( V_15 -> V_37 ) ;
unsigned int V_67 = F_26 ( V_66 ) -> V_68 ;
struct V_69 * V_70 = & V_15 -> V_71 -> V_72 ;
struct V_73 * V_74 = & V_70 -> V_74 ;
struct V_12 * V_13 =
(struct V_12 * ) ( ( char * ) V_70 +
sizeof( struct V_75 ) + V_64 -> V_76 ) ;
struct V_77 * V_78 = & V_15 -> V_79 ;
struct V_80 * V_81 = & V_78 -> V_81 ;
struct V_47 * V_48 = & V_78 -> V_82 ;
void * V_83 = & V_78 -> V_84 ;
struct V_85 * V_86 = V_83 ;
struct V_87 * V_88 = V_83 ;
struct V_89 * V_90 =
(struct V_89 * )
( ( char * ) & V_78 -> V_91 +
sizeof( struct V_92 ) ) ;
V_74 -> V_93 . V_94 . V_95 = F_27 ( V_62 ) ;
memcpy ( V_74 -> V_93 . V_96 , V_64 -> V_97 , V_64 -> V_76 ) ;
V_13 -> V_44 . V_98 . V_99 . V_100 =
F_28 ( V_101 ,
V_15 -> V_4 , V_67 ) ;
V_13 -> V_44 . V_98 . V_102 . V_103 =
F_13 ( F_7 ( V_15 -> V_21 ) ) ;
if ( F_5 ( V_13 , V_15 , V_64 -> V_104 , V_64 -> V_105 ,
( T_1 * ) V_15 -> V_106 ) )
return - V_11 ;
F_16 ( V_48 ) ;
V_48 -> V_107 = V_108 ;
F_29 ( V_48 -> V_56 ,
V_109 ) ;
F_30 ( V_48 -> V_56 ,
V_110 ) ;
V_81 -> V_111 . V_112 . V_113 = V_15 -> V_114 ;
V_81 -> V_111 . V_112 . V_115 = sizeof( struct V_116 ) >> 3 ;
V_86 -> V_117 = V_64 -> V_76 >> 3 ;
V_86 -> V_118 = V_119 >> 3 ;
V_86 -> V_120 = 0 ;
F_31 ( V_86 , V_121 ) ;
F_32 ( V_86 , V_122 ) ;
V_88 -> V_123 = ( ( char * ) V_13 - ( char * ) V_74 ) >> 3 ;
V_88 -> V_124 = V_125 ;
V_88 -> V_126 = V_67 ;
V_88 -> V_127 = V_67 ;
switch ( V_15 -> V_4 ) {
case V_5 :
V_88 -> V_128 =
F_15 ( V_6 , 8 ) ;
V_88 -> V_129 =
F_15 ( V_130 , 8 ) ;
break;
case V_7 :
V_88 -> V_128 = V_8 ;
V_88 -> V_129 = V_131 ;
break;
case V_9 :
V_88 -> V_128 = V_10 ;
V_88 -> V_129 = V_132 ;
break;
default:
break;
}
V_88 -> V_133 = V_88 -> V_123 +
( ( sizeof( struct V_75 ) +
F_15 ( V_88 -> V_128 , 8 ) ) >> 3 ) ;
V_90 -> V_134 . V_135 = V_15 -> V_136 +
sizeof( struct V_137 ) +
F_15 ( V_88 -> V_128 , 8 ) ;
F_31 ( V_88 , V_122 ) ;
F_32 ( V_88 , V_138 ) ;
return 0 ;
}
static int F_33 ( struct V_14 * V_15 ,
int V_62 , struct V_63 * V_64 )
{
struct V_65 * V_66 = F_25 ( V_15 -> V_37 ) ;
unsigned int V_67 = F_26 ( V_66 ) -> V_68 ;
struct V_139 * V_140 = & V_15 -> V_141 -> V_142 ;
struct V_12 * V_13 = & V_140 -> V_13 ;
struct V_73 * V_74 =
(struct V_73 * ) ( ( char * ) V_140 +
sizeof( struct V_75 ) +
F_34 ( F_8 ( V_15 -> V_21 ) , 8 ) * 2 ) ;
struct V_77 * V_78 = & V_15 -> V_143 ;
struct V_80 * V_81 = & V_78 -> V_81 ;
struct V_47 * V_48 = & V_78 -> V_82 ;
void * V_83 = & V_78 -> V_84 ;
struct V_85 * V_86 = V_83 ;
struct V_87 * V_88 = V_83 ;
struct V_89 * V_90 =
(struct V_89 * )
( ( char * ) & V_78 -> V_91 +
sizeof( struct V_92 ) ) ;
V_74 -> V_93 . V_94 . V_95 = F_35 ( V_62 ) ;
memcpy ( V_74 -> V_93 . V_96 , V_64 -> V_97 , V_64 -> V_76 ) ;
V_13 -> V_44 . V_98 . V_99 . V_100 =
F_28 ( V_101 ,
V_15 -> V_4 ,
V_67 ) ;
V_13 -> V_44 . V_98 . V_102 . V_103 =
F_13 ( F_7 ( V_15 -> V_21 ) ) ;
if ( F_5 ( V_13 , V_15 , V_64 -> V_104 , V_64 -> V_105 ,
( T_1 * ) V_15 -> V_144 ) )
return - V_11 ;
F_16 ( V_48 ) ;
V_48 -> V_107 = V_145 ;
F_29 ( V_48 -> V_56 ,
V_146 ) ;
F_30 ( V_48 -> V_56 ,
V_147 ) ;
V_81 -> V_111 . V_112 . V_113 = V_15 -> V_148 ;
V_81 -> V_111 . V_112 . V_115 = sizeof( struct V_116 ) >> 3 ;
V_86 -> V_117 = V_64 -> V_76 >> 3 ;
V_86 -> V_118 = V_119 >> 3 ;
V_86 -> V_120 =
( sizeof( struct V_75 ) +
F_34 ( F_8 ( V_15 -> V_21 ) , 8 ) * 2 ) >> 3 ;
F_31 ( V_86 , V_121 ) ;
F_32 ( V_86 , V_138 ) ;
V_88 -> V_123 = 0 ;
V_88 -> V_124 = V_125 ;
V_88 -> V_126 = V_67 ;
V_88 -> V_127 = V_67 ;
switch ( V_15 -> V_4 ) {
case V_5 :
V_88 -> V_128 =
F_15 ( V_6 , 8 ) ;
V_88 -> V_129 =
F_15 ( V_130 , 8 ) ;
break;
case V_7 :
V_88 -> V_128 = V_8 ;
V_88 -> V_129 = V_131 ;
break;
case V_9 :
V_88 -> V_128 = V_10 ;
V_88 -> V_129 = V_132 ;
break;
default:
break;
}
V_88 -> V_133 = V_88 -> V_123 +
( ( sizeof( struct V_75 ) +
F_15 ( V_88 -> V_128 , 8 ) ) >> 3 ) ;
V_90 -> V_134 . V_135 = V_15 -> V_136 +
sizeof( struct V_137 ) +
F_15 ( V_88 -> V_128 , 8 ) ;
V_90 -> V_149 = V_67 ;
F_31 ( V_88 , V_122 ) ;
F_32 ( V_88 , V_121 ) ;
return 0 ;
}
static int F_36 ( struct V_14 * V_15 ,
const T_1 * V_96 , unsigned int V_150 )
{
struct V_63 V_64 ;
int V_62 ;
if ( F_37 ( V_151 , V_15 -> V_152 , V_119 ) )
return - V_11 ;
if ( F_38 ( & V_64 , V_96 , V_150 ) )
goto V_153;
switch ( V_64 . V_76 ) {
case V_154 :
V_62 = V_155 ;
break;
case V_156 :
V_62 = V_157 ;
break;
case V_158 :
V_62 = V_159 ;
break;
default:
goto V_153;
break;
}
if ( F_24 ( V_15 , V_62 , & V_64 ) )
goto error;
if ( F_33 ( V_15 , V_62 , & V_64 ) )
goto error;
return 0 ;
V_153:
F_39 ( V_15 -> V_37 , V_160 ) ;
return - V_161 ;
error:
return - V_11 ;
}
static int F_40 ( struct V_65 * V_37 , const T_1 * V_96 ,
unsigned int V_150 )
{
struct V_14 * V_15 = F_41 ( V_37 ) ;
struct V_162 * V_163 ;
F_42 ( & V_15 -> V_164 ) ;
if ( V_15 -> V_71 ) {
V_163 = & F_43 ( V_15 -> V_165 -> V_166 ) ;
memset ( V_15 -> V_71 , 0 , sizeof( struct V_116 ) ) ;
memset ( V_15 -> V_141 , 0 , sizeof( struct V_116 ) ) ;
memset ( V_15 -> V_106 , 0 ,
sizeof( struct V_167 ) ) ;
memset ( V_15 -> V_144 , 0 ,
sizeof( struct V_167 ) ) ;
memset ( & V_15 -> V_79 , 0 ,
sizeof( struct V_77 ) ) ;
memset ( & V_15 -> V_143 , 0 ,
sizeof( struct V_77 ) ) ;
} else {
int V_168 = F_1 () ;
struct V_169 * V_165 =
F_44 ( V_168 ) ;
if ( ! V_165 ) {
F_45 ( & V_15 -> V_164 ) ;
return - V_161 ;
}
V_163 = & F_43 ( V_165 -> V_166 ) ;
V_15 -> V_165 = V_165 ;
V_15 -> V_71 = F_46 ( V_163 ,
sizeof( struct V_116 ) ,
& V_15 -> V_114 ,
V_170 ) ;
if ( ! V_15 -> V_71 ) {
F_45 ( & V_15 -> V_164 ) ;
return - V_171 ;
}
V_15 -> V_141 = F_46 ( V_163 ,
sizeof( struct V_116 ) ,
& V_15 -> V_148 ,
V_170 ) ;
if ( ! V_15 -> V_141 ) {
F_45 ( & V_15 -> V_164 ) ;
goto V_172;
}
V_15 -> V_106 =
F_46 ( V_163 , sizeof( struct V_167 ) ,
& V_15 -> V_136 ,
V_170 ) ;
if ( ! V_15 -> V_106 ) {
F_45 ( & V_15 -> V_164 ) ;
goto V_173;
}
V_15 -> V_144 =
F_46 ( V_163 , sizeof( struct V_167 ) ,
& V_15 -> V_174 ,
V_170 ) ;
if ( ! V_15 -> V_144 ) {
F_45 ( & V_15 -> V_164 ) ;
goto V_175;
}
}
F_45 ( & V_15 -> V_164 ) ;
if ( F_36 ( V_15 , V_96 , V_150 ) )
goto V_176;
return 0 ;
V_176:
F_47 ( V_163 , sizeof( struct V_167 ) ,
V_15 -> V_144 , V_15 -> V_174 ) ;
V_15 -> V_144 = NULL ;
V_175:
F_47 ( V_163 , sizeof( struct V_167 ) ,
V_15 -> V_106 , V_15 -> V_136 ) ;
V_15 -> V_106 = NULL ;
V_173:
F_47 ( V_163 , sizeof( struct V_116 ) ,
V_15 -> V_141 , V_15 -> V_148 ) ;
V_15 -> V_141 = NULL ;
V_172:
F_47 ( V_163 , sizeof( struct V_116 ) ,
V_15 -> V_71 , V_15 -> V_114 ) ;
V_15 -> V_71 = NULL ;
return - V_171 ;
}
static void F_48 ( struct V_169 * V_165 ,
struct V_177 * V_178 )
{
struct V_162 * V_163 = & F_43 ( V_165 -> V_166 ) ;
struct V_179 * V_180 = V_178 -> V_181 . V_180 ;
struct V_179 * V_182 = V_178 -> V_181 . V_182 ;
T_4 V_183 = V_178 -> V_181 . V_183 ;
T_4 V_184 = V_178 -> V_181 . V_185 ;
T_5 V_186 = V_178 -> V_181 . V_186 ;
int V_35 , V_187 = V_180 -> V_188 ;
for ( V_35 = 0 ; V_35 < V_180 -> V_188 ; V_35 ++ )
F_49 ( V_163 , V_180 -> V_189 [ V_35 ] . V_190 ,
V_180 -> V_189 [ V_35 ] . V_191 , V_192 ) ;
F_49 ( V_163 , V_183 , V_186 , V_193 ) ;
F_50 ( V_180 ) ;
if ( V_183 != V_184 ) {
int V_194 = V_187 - V_182 -> V_195 ;
for ( V_35 = V_194 ; V_35 < V_187 ; V_35 ++ ) {
F_49 ( V_163 , V_182 -> V_189 [ V_35 ] . V_190 ,
V_182 -> V_189 [ V_35 ] . V_191 ,
V_192 ) ;
}
F_49 ( V_163 , V_184 , V_186 , V_193 ) ;
F_50 ( V_182 ) ;
}
}
static int F_51 ( struct V_169 * V_165 ,
struct V_196 * V_197 ,
struct V_196 * V_198 ,
struct V_196 * V_199 , T_1 * V_200 ,
T_1 V_201 ,
struct V_177 * V_178 )
{
struct V_162 * V_163 = & F_43 ( V_165 -> V_166 ) ;
int V_35 , V_187 = 0 , V_202 = F_52 ( V_198 ) , V_203 = F_52 ( V_197 ) ;
struct V_179 * V_204 ;
struct V_179 * V_205 = NULL ;
T_4 V_183 ;
T_4 V_185 = 0 ;
struct V_196 * V_206 ;
T_5 V_186 = sizeof( struct V_179 ) +
( ( 1 + V_202 + V_203 ) * sizeof( struct V_207 ) ) ;
if ( F_53 ( ! V_202 ) )
return - V_161 ;
V_204 = F_54 ( V_186 , V_170 , V_165 -> V_166 -> V_208 ) ;
if ( F_53 ( ! V_204 ) )
return - V_171 ;
V_183 = F_55 ( V_163 , V_204 , V_186 , V_193 ) ;
if ( F_53 ( F_56 ( V_163 , V_183 ) ) )
goto V_209;
F_57 (assoc, sg, assoc_n, i) {
V_204 -> V_189 [ V_187 ] . V_190 = F_55 ( V_163 ,
F_58 ( V_206 ) ,
V_206 -> V_210 ,
V_192 ) ;
V_204 -> V_189 [ V_187 ] . V_191 = V_206 -> V_210 ;
if ( F_53 ( F_56 ( V_163 , V_204 -> V_189 [ V_187 ] . V_190 ) ) )
goto V_209;
V_187 ++ ;
}
V_204 -> V_189 [ V_187 ] . V_190 = F_55 ( V_163 , V_200 , V_201 ,
V_192 ) ;
V_204 -> V_189 [ V_187 ] . V_191 = V_201 ;
if ( F_53 ( F_56 ( V_163 , V_204 -> V_189 [ V_187 ] . V_190 ) ) )
goto V_209;
V_187 ++ ;
F_57 (sgl, sg, n, i) {
int V_211 = V_35 + V_187 ;
V_204 -> V_189 [ V_211 ] . V_190 = F_55 ( V_163 , F_58 ( V_206 ) ,
V_206 -> V_210 ,
V_192 ) ;
V_204 -> V_189 [ V_211 ] . V_191 = V_206 -> V_210 ;
if ( F_53 ( F_56 ( V_163 , V_204 -> V_189 [ V_211 ] . V_190 ) ) )
goto V_209;
}
V_204 -> V_188 = V_202 + V_187 ;
V_178 -> V_181 . V_180 = V_204 ;
V_178 -> V_181 . V_183 = V_183 ;
V_178 -> V_181 . V_186 = V_186 ;
if ( V_198 != V_199 ) {
struct V_207 * V_189 ;
V_205 = F_54 ( V_186 , V_170 ,
V_165 -> V_166 -> V_208 ) ;
if ( F_53 ( ! V_205 ) )
goto V_209;
V_185 = F_55 ( V_163 , V_205 , V_186 , V_193 ) ;
if ( F_53 ( F_56 ( V_163 , V_185 ) ) )
goto V_209;
V_189 = V_205 -> V_189 ;
for ( V_35 = 0 ; V_35 < V_187 ; V_35 ++ ) {
V_189 [ V_35 ] . V_191 = V_204 -> V_189 [ V_35 ] . V_191 ;
V_189 [ V_35 ] . V_190 = V_204 -> V_189 [ V_35 ] . V_190 ;
}
F_57 (sglout, sg, n, i) {
int V_211 = V_35 + V_187 ;
V_189 [ V_211 ] . V_190 = F_55 ( V_163 , F_58 ( V_206 ) ,
V_206 -> V_210 ,
V_192 ) ;
V_205 -> V_189 [ V_211 ] . V_191 = V_206 -> V_210 ;
if ( F_53 ( F_56 ( V_163 , V_189 [ V_211 ] . V_190 ) ) )
goto V_209;
}
V_205 -> V_188 = V_202 + V_187 ;
V_205 -> V_195 = V_202 ;
V_178 -> V_181 . V_182 = V_205 ;
V_178 -> V_181 . V_185 = V_185 ;
} else {
V_178 -> V_181 . V_185 = V_178 -> V_181 . V_183 ;
}
return 0 ;
V_209:
F_59 ( V_163 , L_1 ) ;
F_57 (sgl, sg, n + bufs, i) {
if ( ! F_56 ( V_163 , V_204 -> V_189 [ V_35 ] . V_190 ) ) {
F_49 ( V_163 , V_204 -> V_189 [ V_35 ] . V_190 ,
V_204 -> V_189 [ V_35 ] . V_191 ,
V_192 ) ;
}
}
if ( ! F_56 ( V_163 , V_183 ) )
F_49 ( V_163 , V_183 , V_186 , V_193 ) ;
F_50 ( V_204 ) ;
if ( V_198 != V_199 && V_205 ) {
F_57 (sglout, sg, n, i) {
int V_211 = V_35 + V_187 ;
if ( ! F_56 ( V_163 , V_205 -> V_189 [ V_211 ] . V_190 ) )
F_49 ( V_163 , V_205 -> V_189 [ V_211 ] . V_190 ,
V_205 -> V_189 [ V_211 ] . V_191 ,
V_192 ) ;
}
if ( ! F_56 ( V_163 , V_185 ) )
F_49 ( V_163 , V_185 , V_186 , V_193 ) ;
F_50 ( V_205 ) ;
}
return - V_171 ;
}
void F_60 ( void * V_212 )
{
struct V_213 * V_214 = V_212 ;
struct V_177 * V_178 =
( void * ) ( V_215 long ) V_214 -> V_216 ;
struct V_14 * V_15 = V_178 -> V_15 ;
struct V_169 * V_165 = V_15 -> V_165 ;
struct V_217 * V_218 = V_178 -> V_218 ;
T_1 V_219 = V_214 -> V_220 . V_221 ;
int V_222 = 0 , V_223 = F_61 ( V_219 ) ;
F_48 ( V_165 , V_178 ) ;
if ( F_53 ( V_223 != V_224 ) )
V_222 = - V_225 ;
V_218 -> V_226 . V_227 ( & V_218 -> V_226 , V_222 ) ;
}
static int F_62 ( struct V_217 * V_218 )
{
struct V_65 * V_66 = F_63 ( V_218 ) ;
struct V_228 * V_37 = F_64 ( V_66 ) ;
struct V_14 * V_15 = F_65 ( V_37 ) ;
struct V_177 * V_178 = F_66 ( V_218 ) ;
struct V_92 * V_229 ;
struct V_89 * V_90 ;
struct V_77 * V_230 ;
int V_231 = F_26 ( V_66 ) -> V_68 ;
int V_41 , V_232 = 0 ;
V_41 = F_51 ( V_15 -> V_165 , V_218 -> V_197 , V_218 -> V_233 , V_218 -> V_234 ,
V_218 -> V_200 , V_119 , V_178 ) ;
if ( F_53 ( V_41 ) )
return V_41 ;
V_230 = & V_178 -> V_235 ;
* V_230 = V_15 -> V_143 ;
V_178 -> V_15 = V_15 ;
V_178 -> V_218 = V_218 ;
V_178 -> V_235 . V_236 . V_216 = ( V_237 ) ( V_215 long ) V_178 ;
V_178 -> V_235 . V_236 . V_238 = V_178 -> V_181 . V_183 ;
V_178 -> V_235 . V_236 . V_239 = V_178 -> V_181 . V_185 ;
V_229 = ( void * ) & V_178 -> V_235 . V_91 ;
V_229 -> V_240 = V_218 -> V_241 - V_231 ;
V_229 -> V_242 = V_218 -> V_243 + V_119 ;
memcpy ( V_229 -> V_111 . V_244 , V_218 -> V_200 , V_119 ) ;
V_90 = ( void * ) ( ( T_1 * ) V_229 + sizeof( * V_229 ) ) ;
V_90 -> V_245 = 0 ;
V_90 -> V_246 = V_218 -> V_243 +
V_229 -> V_240 + V_119 ;
do {
V_41 = F_67 ( V_15 -> V_165 -> V_247 , ( V_248 * ) V_230 ) ;
} while ( V_41 == - V_249 && V_232 ++ < 10 );
if ( V_41 == - V_249 ) {
F_48 ( V_15 -> V_165 , V_178 ) ;
return - V_250 ;
}
return - V_251 ;
}
static int F_68 ( struct V_217 * V_218 , T_1 * V_200 ,
int V_252 )
{
struct V_65 * V_66 = F_63 ( V_218 ) ;
struct V_228 * V_37 = F_64 ( V_66 ) ;
struct V_14 * V_15 = F_65 ( V_37 ) ;
struct V_177 * V_178 = F_66 ( V_218 ) ;
struct V_92 * V_229 ;
struct V_89 * V_90 ;
struct V_77 * V_230 ;
int V_41 , V_232 = 0 ;
V_41 = F_51 ( V_15 -> V_165 , V_218 -> V_197 , V_218 -> V_233 , V_218 -> V_234 ,
V_200 , V_119 , V_178 ) ;
if ( F_53 ( V_41 ) )
return V_41 ;
V_230 = & V_178 -> V_235 ;
* V_230 = V_15 -> V_79 ;
V_178 -> V_15 = V_15 ;
V_178 -> V_218 = V_218 ;
V_178 -> V_235 . V_236 . V_216 = ( V_237 ) ( V_215 long ) V_178 ;
V_178 -> V_235 . V_236 . V_238 = V_178 -> V_181 . V_183 ;
V_178 -> V_235 . V_236 . V_239 = V_178 -> V_181 . V_185 ;
V_229 = ( void * ) & V_178 -> V_235 . V_91 ;
V_90 = ( void * ) ( ( T_1 * ) V_229 + sizeof( * V_229 ) ) ;
if ( V_252 ) {
V_229 -> V_240 = V_218 -> V_241 + V_119 ;
V_229 -> V_242 = V_218 -> V_243 ;
} else {
memcpy ( V_229 -> V_111 . V_244 , V_200 , V_119 ) ;
V_229 -> V_240 = V_218 -> V_241 ;
V_229 -> V_242 = V_218 -> V_243 + V_119 ;
}
V_90 -> V_245 = 0 ;
V_90 -> V_246 = V_218 -> V_243 + V_218 -> V_241 + V_119 ;
do {
V_41 = F_67 ( V_15 -> V_165 -> V_247 , ( V_248 * ) V_230 ) ;
} while ( V_41 == - V_249 && V_232 ++ < 10 );
if ( V_41 == - V_249 ) {
F_48 ( V_15 -> V_165 , V_178 ) ;
return - V_250 ;
}
return - V_251 ;
}
static int F_69 ( struct V_217 * V_218 )
{
return F_68 ( V_218 , V_218 -> V_200 , 0 ) ;
}
static int F_70 ( struct V_253 * V_235 )
{
struct V_65 * V_66 = F_63 ( & V_235 -> V_218 ) ;
struct V_228 * V_37 = F_64 ( V_66 ) ;
struct V_14 * V_15 = F_65 ( V_37 ) ;
T_3 V_254 ;
memcpy ( V_235 -> V_255 , V_15 -> V_152 , V_119 ) ;
V_254 = F_14 ( V_235 -> V_254 ) ;
memcpy ( V_235 -> V_255 + V_119 - sizeof( V_237 ) ,
& V_254 , sizeof( V_237 ) ) ;
return F_68 ( & V_235 -> V_218 , V_235 -> V_255 , 1 ) ;
}
static int F_71 ( struct V_228 * V_37 ,
enum V_3 V_13 , const char * V_256 )
{
struct V_14 * V_15 = F_65 ( V_37 ) ;
memset ( V_15 , '\0' , sizeof( * V_15 ) ) ;
V_15 -> V_21 = F_72 ( V_256 , 0 , 0 ) ;
if ( F_73 ( V_15 -> V_21 ) )
return - V_11 ;
F_74 ( & V_15 -> V_164 ) ;
V_15 -> V_4 = V_13 ;
V_37 -> V_257 . V_258 = sizeof( struct V_217 ) +
sizeof( struct V_177 ) ;
V_15 -> V_37 = V_37 ;
return 0 ;
}
static int F_75 ( struct V_228 * V_37 )
{
return F_71 ( V_37 , V_5 , L_2 ) ;
}
static int F_76 ( struct V_228 * V_37 )
{
return F_71 ( V_37 , V_7 , L_3 ) ;
}
static int F_77 ( struct V_228 * V_37 )
{
return F_71 ( V_37 , V_9 , L_4 ) ;
}
static void F_78 ( struct V_228 * V_37 )
{
struct V_14 * V_15 = F_65 ( V_37 ) ;
struct V_169 * V_165 = V_15 -> V_165 ;
struct V_162 * V_163 ;
if ( ! F_73 ( V_15 -> V_21 ) )
F_79 ( V_15 -> V_21 ) ;
if ( ! V_165 )
return;
V_163 = & F_43 ( V_165 -> V_166 ) ;
if ( V_15 -> V_71 )
F_47 ( V_163 , sizeof( struct V_116 ) ,
V_15 -> V_71 , V_15 -> V_114 ) ;
if ( V_15 -> V_141 )
F_47 ( V_163 , sizeof( struct V_116 ) ,
V_15 -> V_141 , V_15 -> V_148 ) ;
if ( V_15 -> V_106 )
F_47 ( V_163 , sizeof( struct V_167 ) ,
V_15 -> V_106 ,
V_15 -> V_136 ) ;
if ( V_15 -> V_144 )
F_47 ( V_163 , sizeof( struct V_167 ) ,
V_15 -> V_144 ,
V_15 -> V_174 ) ;
F_80 ( V_165 ) ;
}
int F_81 ( void )
{
if ( F_82 ( 1 , & V_259 ) == 1 ) {
int V_35 ;
for ( V_35 = 0 ; V_35 < F_83 ( V_260 ) ; V_35 ++ )
V_260 [ V_35 ] . V_261 = V_262 |
V_263 ;
return F_84 ( V_260 , F_83 ( V_260 ) ) ;
}
return 0 ;
}
int F_85 ( void )
{
if ( F_86 ( 1 , & V_259 ) == 0 )
return F_87 ( V_260 , F_83 ( V_260 ) ) ;
return 0 ;
}
int F_88 ( void )
{
F_89 ( & V_259 , 0 ) ;
F_90 () ;
return 0 ;
}
void F_91 ( void )
{
F_92 () ;
}

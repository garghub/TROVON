static int F_1 ( T_1 * V_1 ,
const void * V_2 , int V_3 ,
const void * V_4 , int V_5 ,
const void * V_6 , int V_7 ,
const void * V_8 , int V_9 ,
const void * V_10 , int V_11 ,
const unsigned char * V_12 , int V_13 ,
unsigned char * V_14 , int V_15 )
{
const T_2 * V_16 = F_2 ( V_1 ) ;
T_3 * V_17 = NULL ;
int V_18 = 0 ;
T_4 V_19 = V_15 ;
if ( V_16 == NULL ) {
F_3 ( V_20 , V_21 ) ;
return 0 ;
}
V_17 = F_4 ( V_22 , NULL ) ;
if ( V_17 == NULL || F_5 ( V_17 ) <= 0
|| F_6 ( V_17 , V_16 ) <= 0
|| F_7 ( V_17 , V_12 , V_13 ) <= 0 )
goto V_23;
if ( F_8 ( V_17 , V_2 , V_3 ) <= 0 )
goto V_23;
if ( F_8 ( V_17 , V_4 , V_5 ) <= 0 )
goto V_23;
if ( F_8 ( V_17 , V_6 , V_7 ) <= 0 )
goto V_23;
if ( F_8 ( V_17 , V_8 , V_9 ) <= 0 )
goto V_23;
if ( F_8 ( V_17 , V_10 , V_11 ) <= 0 )
goto V_23;
if ( F_9 ( V_17 , V_14 , & V_19 ) <= 0 )
goto V_23;
V_18 = 1 ;
V_23:
F_10 ( V_17 ) ;
return V_18 ;
}
static int F_11 ( T_1 * V_1 , unsigned char * V_24 , int V_25 )
{
int V_18 ;
V_18 = F_1 ( V_1 ,
V_26 ,
V_27 , V_1 -> V_28 -> V_29 ,
V_30 , V_1 -> V_28 -> V_31 , V_30 ,
NULL , 0 , NULL , 0 , V_1 -> V_32 -> V_33 ,
V_1 -> V_32 -> V_34 , V_24 , V_25 ) ;
return V_18 ;
}
int F_12 ( T_1 * V_1 , int V_35 )
{
unsigned char * V_36 , * V_37 ;
unsigned char V_38 [ V_39 ] ;
unsigned char V_40 [ V_39 ] ;
unsigned char V_41 [ V_42 * 2 ] ;
unsigned char V_43 [ V_42 * 2 ] ;
unsigned char * V_44 , * V_45 , * V_46 ;
T_5 * V_47 ;
const T_6 * V_48 ;
#ifndef F_13
const T_7 * V_49 ;
#endif
const T_2 * V_50 ;
int V_51 ;
int * V_52 ;
T_8 * V_53 ;
T_9 * V_54 ;
int V_55 , V_56 , V_57 , V_58 , V_59 ;
int V_60 = 0 ;
V_48 = V_1 -> V_28 -> V_61 . V_62 ;
V_50 = V_1 -> V_28 -> V_61 . V_63 ;
V_51 = V_1 -> V_28 -> V_61 . V_64 ;
#ifndef F_13
V_49 = V_1 -> V_28 -> V_61 . V_65 ;
#endif
if ( V_35 & V_66 ) {
if ( V_1 -> V_28 -> V_61 . V_67 -> V_68 & V_69 )
V_1 -> V_70 |= V_71 ;
else
V_1 -> V_70 &= ~ V_71 ;
if ( V_1 -> V_72 != NULL )
V_60 = 1 ;
else if ( ( V_1 -> V_72 = F_14 () ) == NULL )
goto V_23;
else
F_15 ( V_1 -> V_72 ) ;
V_47 = V_1 -> V_72 ;
V_53 = F_16 ( & V_1 -> V_73 , NULL ) ;
if ( V_53 == NULL )
goto V_23;
#ifndef F_13
F_17 ( V_1 -> V_74 ) ;
V_1 -> V_74 = NULL ;
if ( V_49 != NULL ) {
V_1 -> V_74 = F_18 ( V_49 -> V_75 ) ;
if ( V_1 -> V_74 == NULL ) {
F_3 ( V_76 ,
V_77 ) ;
goto V_78;
}
}
#endif
if ( ! F_19 ( V_1 ) )
F_20 ( & V_1 -> V_79 ) ;
V_37 = & ( V_1 -> V_28 -> V_80 [ 0 ] ) ;
V_52 = & ( V_1 -> V_28 -> V_81 ) ;
} else {
if ( V_1 -> V_28 -> V_61 . V_67 -> V_68 & V_69 )
V_1 -> V_70 |= V_82 ;
else
V_1 -> V_70 &= ~ V_82 ;
if ( V_1 -> V_83 != NULL && ! F_19 ( V_1 ) )
V_60 = 1 ;
else if ( ( V_1 -> V_83 = F_14 () ) == NULL )
goto V_23;
V_47 = V_1 -> V_83 ;
if ( F_19 ( V_1 ) ) {
V_53 = F_21 () ;
if ( V_53 == NULL )
goto V_23;
V_1 -> V_84 = V_53 ;
} else {
V_53 = F_16 ( & V_1 -> V_84 , NULL ) ;
if ( V_53 == NULL )
goto V_23;
}
#ifndef F_13
F_17 ( V_1 -> V_85 ) ;
V_1 -> V_85 = NULL ;
if ( V_49 != NULL ) {
V_1 -> V_85 = F_18 ( V_49 -> V_75 ) ;
if ( V_1 -> V_85 == NULL ) {
F_3 ( V_76 ,
V_77 ) ;
goto V_78;
}
}
#endif
if ( ! F_19 ( V_1 ) )
F_22 ( & V_1 -> V_79 ) ;
V_37 = & ( V_1 -> V_28 -> V_86 [ 0 ] ) ;
V_52 = & ( V_1 -> V_28 -> V_87 ) ;
}
if ( V_60 )
F_15 ( V_47 ) ;
V_36 = V_1 -> V_28 -> V_61 . V_88 ;
V_56 = * V_52 = V_1 -> V_28 -> V_61 . V_89 ;
V_59 = F_23 ( V_48 ) ;
V_57 = V_59 ;
if ( F_24 ( V_48 ) == V_90 )
V_58 = V_91 ;
else if ( F_24 ( V_48 ) == V_92 )
V_58 = V_93 ;
else
V_58 = F_25 ( V_48 ) ;
if ( ( V_35 == V_94 ) ||
( V_35 == V_95 ) ) {
V_44 = & ( V_36 [ 0 ] ) ;
V_55 = V_56 + V_56 ;
V_45 = & ( V_36 [ V_55 ] ) ;
V_55 += V_57 + V_57 ;
V_46 = & ( V_36 [ V_55 ] ) ;
V_55 += V_58 + V_58 ;
} else {
V_55 = V_56 ;
V_44 = & ( V_36 [ V_55 ] ) ;
V_55 += V_56 + V_57 ;
V_45 = & ( V_36 [ V_55 ] ) ;
V_55 += V_57 + V_58 ;
V_46 = & ( V_36 [ V_55 ] ) ;
V_55 += V_58 ;
}
if ( V_55 > V_1 -> V_28 -> V_61 . V_96 ) {
F_3 ( V_76 , V_21 ) ;
goto V_78;
}
memcpy ( V_37 , V_44 , V_56 ) ;
if ( ! ( F_26 ( V_48 ) & V_97 ) ) {
V_54 = F_27 ( V_51 , NULL ,
V_37 , * V_52 ) ;
if ( V_54 == NULL
|| F_28 ( V_53 , NULL , V_50 , NULL , V_54 ) <= 0 ) {
F_29 ( V_54 ) ;
F_3 ( V_76 , V_21 ) ;
goto V_78;
}
F_29 ( V_54 ) ;
}
#ifdef F_30
printf ( L_1 , V_35 ) ;
{
int V_98 ;
for ( V_98 = 0 ; V_98 < V_56 ; V_98 ++ )
printf ( L_2 , V_44 [ V_98 ] , ( ( V_98 + 1 ) % 16 ) ? ' ' : '\n' ) ;
}
#endif
if ( F_24 ( V_48 ) == V_90 ) {
if ( ! F_31 ( V_47 , V_48 , NULL , V_45 , NULL , ( V_35 & V_99 ) )
|| ! F_32 ( V_47 , V_100 , V_58 , V_46 ) ) {
F_3 ( V_76 , V_21 ) ;
goto V_78;
}
} else if ( F_24 ( V_48 ) == V_92 ) {
int V_101 ;
if ( V_1 -> V_28 -> V_61 .
V_67 -> V_102 & ( V_103 | V_104 ) )
V_101 = 8 ;
else
V_101 = 16 ;
if ( ! F_31 ( V_47 , V_48 , NULL , NULL , NULL , ( V_35 & V_99 ) )
|| ! F_32 ( V_47 , V_105 , 12 , NULL )
|| ! F_32 ( V_47 , V_106 , V_101 , NULL )
|| ! F_32 ( V_47 , V_107 , V_58 , V_46 )
|| ! F_31 ( V_47 , NULL , NULL , V_45 , NULL , - 1 ) ) {
F_3 ( V_76 , V_21 ) ;
goto V_78;
}
} else {
if ( ! F_31 ( V_47 , V_48 , NULL , V_45 , V_46 , ( V_35 & V_99 ) ) ) {
F_3 ( V_76 , V_21 ) ;
goto V_78;
}
}
if ( ( F_26 ( V_48 ) & V_97 ) && * V_52
&& ! F_32 ( V_47 , V_108 ,
* V_52 , V_37 ) ) {
F_3 ( V_76 , V_21 ) ;
goto V_78;
}
#ifdef F_33
if ( V_1 -> V_109 ) {
int V_110 = V_35 & V_99 ? V_111 : 0 ;
if ( * V_52 )
V_1 -> V_109 ( 2 , V_1 -> V_112 , V_110 | V_113 ,
V_37 , * V_52 ,
V_1 , V_1 -> V_114 ) ;
if ( V_48 -> V_115 )
V_1 -> V_109 ( 2 , V_1 -> V_112 , V_110 | V_116 ,
V_45 , V_48 -> V_115 , V_1 , V_1 -> V_114 ) ;
if ( V_58 ) {
if ( F_24 ( V_48 ) == V_90 )
V_110 |= V_117 ;
else
V_110 |= V_118 ;
V_1 -> V_109 ( 2 , V_1 -> V_112 , V_110 , V_46 , V_58 , V_1 , V_1 -> V_114 ) ;
}
}
#endif
#ifdef F_30
printf ( L_3 , V_35 ) ;
{
int V_98 ;
for ( V_98 = 0 ; V_98 < F_23 ( V_48 ) ; V_98 ++ )
printf ( L_2 , V_45 [ V_98 ] , ( ( V_98 + 1 ) % 16 ) ? ' ' : '\n' ) ;
}
printf ( L_4 ) ;
{
int V_98 ;
for ( V_98 = 0 ; V_98 < V_58 ; V_98 ++ )
printf ( L_2 , V_46 [ V_98 ] , ( ( V_98 + 1 ) % 16 ) ? ' ' : '\n' ) ;
}
printf ( L_5 ) ;
#endif
F_34 ( V_38 , sizeof( V_38 ) ) ;
F_34 ( V_40 , sizeof( V_38 ) ) ;
F_34 ( V_41 , sizeof( V_41 ) ) ;
F_34 ( V_43 , sizeof( V_43 ) ) ;
return ( 1 ) ;
V_23:
F_3 ( V_76 , V_119 ) ;
V_78:
F_34 ( V_38 , sizeof( V_38 ) ) ;
F_34 ( V_40 , sizeof( V_38 ) ) ;
F_34 ( V_41 , sizeof( V_41 ) ) ;
F_34 ( V_43 , sizeof( V_43 ) ) ;
return ( 0 ) ;
}
int F_35 ( T_1 * V_1 )
{
unsigned char * V_36 ;
const T_6 * V_48 ;
const T_2 * V_120 ;
int V_25 ;
T_7 * V_49 ;
int V_51 = V_121 , V_52 = 0 ;
int V_18 = 0 ;
if ( V_1 -> V_28 -> V_61 . V_96 != 0 )
return ( 1 ) ;
if ( ! F_36
( V_1 -> V_32 , & V_48 , & V_120 , & V_51 , & V_52 , & V_49 ,
F_37 ( V_1 ) ) ) {
F_3 ( V_122 , V_123 ) ;
return ( 0 ) ;
}
V_1 -> V_28 -> V_61 . V_62 = V_48 ;
V_1 -> V_28 -> V_61 . V_63 = V_120 ;
V_1 -> V_28 -> V_61 . V_64 = V_51 ;
V_1 -> V_28 -> V_61 . V_89 = V_52 ;
V_25 = F_23 ( V_48 ) + V_52 + F_25 ( V_48 ) ;
V_25 *= 2 ;
F_38 ( V_1 ) ;
if ( ( V_36 = F_39 ( V_25 ) ) == NULL ) {
F_3 ( V_122 , V_119 ) ;
goto V_23;
}
V_1 -> V_28 -> V_61 . V_96 = V_25 ;
V_1 -> V_28 -> V_61 . V_88 = V_36 ;
#ifdef F_30
printf ( L_6 ) ;
{
int V_98 ;
for ( V_98 = 0 ; V_98 < V_30 ; V_98 ++ )
printf ( L_2 , V_1 -> V_28 -> V_31 [ V_98 ] ,
( ( V_98 + 1 ) % 16 ) ? ' ' : '\n' ) ;
}
printf ( L_7 ) ;
{
int V_98 ;
for ( V_98 = 0 ; V_98 < V_30 ; V_98 ++ )
printf ( L_2 , V_1 -> V_28 -> V_29 [ V_98 ] ,
( ( V_98 + 1 ) % 16 ) ? ' ' : '\n' ) ;
}
printf ( L_8 ) ;
{
int V_98 ;
for ( V_98 = 0 ; V_98 < V_1 -> V_32 -> V_34 ; V_98 ++ )
printf ( L_2 , V_1 -> V_32 -> V_33 [ V_98 ] ,
( ( V_98 + 1 ) % 16 ) ? ' ' : '\n' ) ;
}
#endif
if ( ! F_11 ( V_1 , V_36 , V_25 ) )
goto V_23;
#ifdef F_30
printf ( L_9 ) ;
{
int V_98 ;
for ( V_98 = 0 ; V_98 < V_25 ; V_98 ++ )
printf ( L_2 , V_36 [ V_98 ] , ( ( V_98 + 1 ) % 16 ) ? ' ' : '\n' ) ;
}
#endif
if ( ! ( V_1 -> V_124 & V_125 )
&& V_1 -> V_75 -> V_112 <= V_126 ) {
V_1 -> V_28 -> V_127 = 1 ;
if ( V_1 -> V_32 -> V_128 != NULL ) {
if ( V_1 -> V_32 -> V_128 -> V_102 == V_129 )
V_1 -> V_28 -> V_127 = 0 ;
#ifndef F_40
if ( V_1 -> V_32 -> V_128 -> V_102 == V_130 )
V_1 -> V_28 -> V_127 = 0 ;
#endif
}
}
V_18 = 1 ;
V_23:
return ( V_18 ) ;
}
int F_41 ( T_1 * V_1 , const char * V_131 , int V_13 , unsigned char * V_14 )
{
int V_132 ;
unsigned char V_120 [ V_133 ] ;
if ( ! F_42 ( V_1 , 0 ) )
return 0 ;
V_132 = F_43 ( V_1 , V_120 , sizeof( V_120 ) ) ;
if ( V_132 == 0 )
return 0 ;
if ( ! F_1 ( V_1 , V_131 , V_13 , V_120 , V_132 , NULL , 0 , NULL , 0 , NULL , 0 ,
V_1 -> V_32 -> V_33 , V_1 -> V_32 -> V_34 ,
V_14 , V_134 ) )
return 0 ;
F_34 ( V_120 , V_132 ) ;
return V_134 ;
}
int F_44 ( T_1 * V_1 , unsigned char * V_14 , unsigned char * V_36 ,
int V_135 )
{
if ( V_1 -> V_32 -> V_136 & V_137 ) {
unsigned char V_120 [ V_133 * 2 ] ;
int V_132 ;
if ( ! F_42 ( V_1 , 1 ) )
return - 1 ;
V_132 = F_43 ( V_1 , V_120 , sizeof( V_120 ) ) ;
#ifdef F_30
fprintf ( V_138 , L_10 ) ;
F_45 ( V_138 , ( char * ) V_120 , V_132 ) ;
#endif
F_1 ( V_1 ,
V_139 ,
V_140 ,
V_120 , V_132 ,
NULL , 0 ,
NULL , 0 ,
NULL , 0 , V_36 , V_135 , V_1 -> V_32 -> V_33 ,
V_141 ) ;
F_34 ( V_120 , V_132 ) ;
} else {
F_1 ( V_1 ,
V_142 ,
V_143 ,
V_1 -> V_28 -> V_31 , V_30 ,
NULL , 0 ,
V_1 -> V_28 -> V_29 , V_30 ,
NULL , 0 , V_36 , V_135 , V_1 -> V_32 -> V_33 ,
V_141 ) ;
}
#ifdef F_30
fprintf ( V_138 , L_11 ) ;
F_45 ( V_138 , ( char * ) V_36 , V_135 ) ;
fprintf ( V_138 , L_12 ) ;
F_45 ( V_138 , ( char * ) V_1 -> V_28 -> V_31 , V_30 ) ;
fprintf ( V_138 , L_13 ) ;
F_45 ( V_138 , ( char * ) V_1 -> V_28 -> V_29 , V_30 ) ;
fprintf ( V_138 , L_14 ) ;
F_45 ( V_138 , ( char * ) V_1 -> V_32 -> V_33 ,
V_141 ) ;
#endif
#ifdef F_33
if ( V_1 -> V_109 ) {
V_1 -> V_109 ( 2 , V_1 -> V_112 , V_144 ,
V_36 , V_135 , V_1 , V_1 -> V_114 ) ;
V_1 -> V_109 ( 2 , V_1 -> V_112 , V_145 ,
V_1 -> V_28 -> V_31 , V_30 ,
V_1 , V_1 -> V_114 ) ;
V_1 -> V_109 ( 2 , V_1 -> V_112 , V_146 ,
V_1 -> V_28 -> V_29 , V_30 ,
V_1 , V_1 -> V_114 ) ;
V_1 -> V_109 ( 2 , V_1 -> V_112 , V_147 ,
V_1 -> V_32 -> V_33 ,
V_141 , V_1 , V_1 -> V_114 ) ;
}
#endif
return ( V_141 ) ;
}
int F_46 ( T_1 * V_1 , unsigned char * V_14 , T_4 V_15 ,
const char * V_148 , T_4 V_149 ,
const unsigned char * V_150 ,
T_4 V_151 , int V_152 )
{
unsigned char * V_153 = NULL ;
T_4 V_154 = 0 , V_155 ;
int V_156 ;
V_154 = V_149 + V_30 * 2 ;
if ( V_152 ) {
V_154 += 2 + V_151 ;
}
V_153 = F_39 ( V_154 ) ;
if ( V_153 == NULL )
goto V_78;
V_155 = 0 ;
memcpy ( V_153 + V_155 , ( unsigned char * ) V_148 , V_149 ) ;
V_155 += V_149 ;
memcpy ( V_153 + V_155 , V_1 -> V_28 -> V_31 , V_30 ) ;
V_155 += V_30 ;
memcpy ( V_153 + V_155 , V_1 -> V_28 -> V_29 , V_30 ) ;
V_155 += V_30 ;
if ( V_152 ) {
V_153 [ V_155 ] = ( V_151 >> 8 ) & 0xff ;
V_155 ++ ;
V_153 [ V_155 ] = V_151 & 0xff ;
V_155 ++ ;
if ( ( V_151 > 0 ) || ( V_150 != NULL ) ) {
memcpy ( V_153 + V_155 , V_150 , V_151 ) ;
}
}
if ( memcmp ( V_153 , V_157 ,
V_158 ) == 0 )
goto V_159;
if ( memcmp ( V_153 , V_160 ,
V_161 ) == 0 )
goto V_159;
if ( memcmp ( V_153 , V_142 ,
V_143 ) == 0 )
goto V_159;
if ( memcmp ( V_153 , V_139 ,
V_140 ) == 0 )
goto V_159;
if ( memcmp ( V_153 , V_26 ,
V_27 ) == 0 )
goto V_159;
V_156 = F_1 ( V_1 ,
V_153 , V_154 ,
NULL , 0 ,
NULL , 0 ,
NULL , 0 ,
NULL , 0 ,
V_1 -> V_32 -> V_33 , V_1 -> V_32 -> V_34 ,
V_14 , V_15 ) ;
goto V_18;
V_159:
F_3 ( V_162 , V_163 ) ;
V_156 = 0 ;
goto V_18;
V_78:
F_3 ( V_162 , V_119 ) ;
V_156 = 0 ;
V_18:
F_47 ( V_153 , V_154 ) ;
return ( V_156 ) ;
}
int F_48 ( int V_164 )
{
switch ( V_164 ) {
case V_165 :
return ( V_166 ) ;
case V_167 :
return ( V_168 ) ;
case V_169 :
return ( V_170 ) ;
case V_171 :
return ( V_172 ) ;
case V_173 :
return ( V_174 ) ;
case V_175 :
return ( V_176 ) ;
case V_177 :
return ( V_178 ) ;
case V_179 :
return ( - 1 ) ;
case V_180 :
return ( V_181 ) ;
case V_182 :
return ( V_183 ) ;
case V_184 :
return ( V_185 ) ;
case V_186 :
return ( V_187 ) ;
case V_188 :
return ( V_189 ) ;
case V_190 :
return ( V_191 ) ;
case V_192 :
return ( V_193 ) ;
case V_194 :
return ( V_195 ) ;
case V_196 :
return ( V_197 ) ;
case V_198 :
return ( V_199 ) ;
case V_200 :
return ( V_201 ) ;
case V_202 :
return ( V_203 ) ;
case V_204 :
return ( V_205 ) ;
case V_206 :
return ( V_207 ) ;
case V_208 :
return ( V_209 ) ;
case V_210 :
return ( V_211 ) ;
case V_212 :
return ( V_213 ) ;
case V_214 :
return ( V_215 ) ;
case V_216 :
return ( V_217 ) ;
case V_218 :
return ( V_219 ) ;
case V_220 :
return ( V_221 ) ;
case V_222 :
return ( V_223 ) ;
case V_224 :
return ( V_225 ) ;
case V_226 :
return ( V_227 ) ;
default:
return ( - 1 ) ;
}
}

long F_1 ( void )
{
return ( 60 * 60 * 2 ) ;
}
int F_2 ( T_1 * V_1 )
{
if ( ! F_3 ( V_1 ) )
return ( 0 ) ;
V_1 -> V_2 -> V_3 ( V_1 ) ;
return ( 1 ) ;
}
void F_4 ( T_1 * V_1 )
{
#ifndef F_5
if ( V_1 -> V_4 ) {
F_6 ( V_1 -> V_4 ) ;
}
#endif
F_7 ( V_1 ) ;
}
void F_8 ( T_1 * V_1 )
{
F_9 ( V_1 ) ;
V_1 -> V_5 = V_1 -> V_2 -> V_5 ;
}
int F_10 ( int V_6 )
{
if ( ( V_6 < 1 ) || ( ( unsigned int ) V_6 >
sizeof( V_7 ) / sizeof( V_7 [ 0 ] ) ) )
return 0 ;
return V_7 [ V_6 - 1 ] ;
}
int F_11 ( int V_8 )
{
switch ( V_8 ) {
case V_9 :
return 1 ;
case V_10 :
return 2 ;
case V_11 :
return 3 ;
case V_12 :
return 4 ;
case V_13 :
return 5 ;
case V_14 :
return 6 ;
case V_15 :
return 7 ;
case V_16 :
return 8 ;
case V_17 :
return 9 ;
case V_18 :
return 10 ;
case V_19 :
return 11 ;
case V_20 :
return 12 ;
case V_21 :
return 13 ;
case V_22 :
return 14 ;
case V_23 :
return 15 ;
case V_24 :
return 16 ;
case V_25 :
return 17 ;
case V_26 :
return 18 ;
case V_27 :
return 19 ;
case V_28 :
return 20 ;
case V_29 :
return 21 ;
case V_30 :
return 22 ;
case V_31 :
return 23 ;
case V_32 :
return 24 ;
case V_33 :
return 25 ;
case V_34 :
return 26 ;
case V_35 :
return 27 ;
case V_36 :
return 28 ;
default:
return 0 ;
}
}
static int F_12 ( T_1 * V_1 , int V_37 ,
const unsigned char * * V_38 ,
T_2 * V_39 )
{
T_2 V_40 = 0 ;
if ( V_37 ) {
* V_38 = V_1 -> V_41 -> V_42 ;
V_40 = V_1 -> V_41 -> V_43 ;
} else {
switch ( F_13 ( V_1 ) ) {
case V_44 :
* V_38 = V_45 ;
V_40 = sizeof( V_45 ) ;
break;
case V_46 :
* V_38 = V_45 ;
V_40 = 2 ;
break;
case V_47 :
* V_38 = V_45 + 2 ;
V_40 = 2 ;
break;
default:
* V_38 = V_1 -> V_42 ;
V_40 = V_1 -> V_43 ;
}
if ( ! * V_38 ) {
# ifdef F_14
if ( F_15 () ) {
* V_38 = V_48 ;
* V_40 = sizeof( V_48 ) ;
} else
# endif
{
* V_38 = V_49 ;
V_40 = sizeof( V_49 ) ;
}
}
}
if ( V_40 & 1 ) {
F_16 ( V_50 , V_51 ) ;
* V_39 = 0 ;
return 0 ;
} else {
* V_39 = V_40 / 2 ;
return 1 ;
}
}
int F_17 ( T_1 * V_1 , const unsigned char * V_52 , T_2 V_53 )
{
const unsigned char * V_54 ;
T_2 V_39 , V_55 ;
unsigned int V_56 = F_13 ( V_1 ) ;
if ( V_53 != 3 || V_52 [ 0 ] != V_57 )
return 0 ;
if ( V_56 ) {
unsigned long V_58 = V_1 -> V_59 -> V_60 . V_61 -> V_62 ;
if ( V_52 [ 1 ] )
return 0 ;
if ( V_58 == V_63 ) {
if ( V_52 [ 2 ] != V_64 )
return 0 ;
} else if ( V_58 == V_65 ) {
if ( V_52 [ 2 ] != V_66 )
return 0 ;
} else
return 0 ;
}
if ( ! F_12 ( V_1 , 0 , & V_54 , & V_39 ) )
return 0 ;
for ( V_55 = 0 ; V_55 < V_39 ; V_55 ++ , V_54 += 2 ) {
if ( V_52 [ 1 ] == V_54 [ 0 ] && V_52 [ 2 ] == V_54 [ 1 ] )
return 1 ;
}
return 0 ;
}
int F_18 ( T_1 * V_1 , int V_67 )
{
const unsigned char * V_68 , * V_69 ;
T_2 V_70 , V_71 , V_55 , V_72 ;
int V_73 ;
if ( V_1 -> V_74 == 0 )
return - 1 ;
if ( V_67 == - 2 ) {
if ( F_13 ( V_1 ) ) {
unsigned long V_58 = V_1 -> V_59 -> V_60 . V_61 -> V_62 ;
if ( V_58 == V_63 )
return V_31 ;
if ( V_58 == V_65 )
return V_32 ;
return V_75 ;
}
V_67 = 0 ;
}
if ( ! F_12
( V_1 , ( V_1 -> V_76 & V_77 ) != 0 , & V_69 ,
& V_71 ) )
return V_67 == - 1 ? 0 : V_75 ;
if ( ! F_12
( V_1 , ! ( V_1 -> V_76 & V_77 ) , & V_68 ,
& V_70 ) )
return V_67 == - 1 ? 0 : V_75 ;
V_73 = 0 ;
for ( V_55 = 0 ; V_55 < V_70 ; V_55 ++ , V_68 += 2 ) {
const unsigned char * V_78 = V_69 ;
for ( V_72 = 0 ; V_72 < V_71 ; V_72 ++ , V_78 += 2 ) {
if ( V_68 [ 0 ] == V_78 [ 0 ] && V_68 [ 1 ] == V_78 [ 1 ] ) {
if ( V_67 == V_73 ) {
int V_62 = ( V_68 [ 0 ] << 8 ) | V_68 [ 1 ] ;
return F_10 ( V_62 ) ;
}
V_73 ++ ;
}
}
}
if ( V_67 == - 1 )
return V_73 ;
return V_75 ;
}
int F_19 ( unsigned char * * V_79 , T_2 * V_80 ,
int * V_54 , T_2 V_81 )
{
unsigned char * V_82 , * V_52 ;
T_2 V_55 ;
unsigned long V_83 = 0 ;
# ifdef F_20
T_3 * V_84 ;
# endif
V_82 = F_21 ( V_81 * 2 ) ;
if ( ! V_82 )
return 0 ;
for ( V_55 = 0 , V_52 = V_82 ; V_55 < V_81 ; V_55 ++ ) {
unsigned long V_85 ;
int V_62 ;
V_62 = F_11 ( V_54 [ V_55 ] ) ;
# ifdef F_14
if ( F_15 () && V_62 > 25 ) {
F_6 ( V_82 ) ;
return 0 ;
}
# endif
# ifdef F_20
V_84 = F_22 ( V_54 [ V_55 ] ) ;
if ( ! V_84 || F_23 ( F_24 ( V_84 ) )
== V_86 ) {
if ( V_84 )
F_25 ( V_84 ) ;
F_6 ( V_82 ) ;
return 0 ;
} else
F_25 ( V_84 ) ;
# endif
V_85 = 1L << V_62 ;
if ( ! V_62 || ( V_83 & V_85 ) ) {
F_6 ( V_82 ) ;
return 0 ;
}
V_83 |= V_85 ;
F_26 ( V_62 , V_52 ) ;
}
if ( * V_79 )
F_6 ( * V_79 ) ;
* V_79 = V_82 ;
* V_80 = V_81 * 2 ;
return 1 ;
}
static int F_27 ( const char * V_87 , int V_53 , void * V_88 )
{
T_4 * V_89 = V_88 ;
T_2 V_55 ;
int V_8 ;
char V_90 [ 20 ] ;
if ( V_89 -> V_91 == V_92 )
return 0 ;
if ( V_53 > ( int ) ( sizeof( V_90 ) - 1 ) )
return 0 ;
memcpy ( V_90 , V_87 , V_53 ) ;
V_90 [ V_53 ] = 0 ;
V_8 = F_28 ( V_90 ) ;
if ( V_8 == V_75 )
V_8 = F_29 ( V_90 ) ;
if ( V_8 == V_75 )
V_8 = F_30 ( V_90 ) ;
if ( V_8 == V_75 )
return 0 ;
for ( V_55 = 0 ; V_55 < V_89 -> V_91 ; V_55 ++ )
if ( V_89 -> V_93 [ V_55 ] == V_8 )
return 0 ;
V_89 -> V_93 [ V_89 -> V_91 ++ ] = V_8 ;
return 1 ;
}
int F_31 ( unsigned char * * V_79 , T_2 * V_80 ,
const char * V_94 )
{
T_4 V_95 ;
V_95 . V_91 = 0 ;
if ( ! F_32 ( V_94 , ':' , 1 , F_27 , & V_95 ) )
return 0 ;
if ( V_79 == NULL )
return 1 ;
return F_19 ( V_79 , V_80 , V_95 . V_93 , V_95 . V_91 ) ;
}
static int F_33 ( unsigned char * V_6 , unsigned char * V_96 ,
T_5 * V_97 )
{
int V_98 , V_62 ;
const T_3 * V_99 ;
const T_6 * V_100 ;
if ( ! V_97 )
return 0 ;
V_99 = F_34 ( V_97 ) ;
if ( ! V_99 )
return 0 ;
V_100 = F_24 ( V_99 ) ;
if ( ! V_100 )
return 0 ;
if ( F_23 ( V_100 ) == V_101 )
V_98 = 1 ;
else
V_98 = 0 ;
V_62 = F_35 ( V_99 ) ;
V_62 = F_11 ( V_62 ) ;
if ( V_62 ) {
V_6 [ 0 ] = 0 ;
V_6 [ 1 ] = ( unsigned char ) V_62 ;
} else {
V_6 [ 0 ] = 0xff ;
if ( V_98 )
V_6 [ 1 ] = 0x01 ;
else
V_6 [ 1 ] = 0x02 ;
}
if ( V_96 ) {
if ( F_36 ( V_97 ) == NULL )
return 0 ;
if ( F_37 ( V_97 ) == V_102 ) {
if ( V_98 )
* V_96 = V_103 ;
else
* V_96 = V_104 ;
} else
* V_96 = V_105 ;
}
return 1 ;
}
static int F_38 ( T_1 * V_1 ,
unsigned char * V_6 , unsigned char * V_96 )
{
const unsigned char * V_106 , * V_38 ;
T_2 V_107 , V_39 , V_55 ;
int V_72 ;
if ( V_96 && V_1 -> V_41 -> V_108 ) {
V_106 = V_1 -> V_41 -> V_108 ;
V_107 = V_1 -> V_41 -> V_109 ;
for ( V_55 = 0 ; V_55 < V_107 ; V_55 ++ , V_106 ++ ) {
if ( * V_96 == * V_106 )
break;
}
if ( V_55 == V_107 )
return 0 ;
}
if ( ! V_6 )
return 1 ;
for ( V_72 = 0 ; V_72 <= 1 ; V_72 ++ ) {
if ( ! F_12 ( V_1 , V_72 , & V_38 , & V_39 ) )
return 0 ;
for ( V_55 = 0 ; V_55 < V_39 ; V_55 ++ , V_38 += 2 ) {
if ( V_38 [ 0 ] == V_6 [ 0 ] && V_38 [ 1 ] == V_6 [ 1 ] )
break;
}
if ( V_55 == V_39 )
return 0 ;
if ( ! V_1 -> V_74 )
return 1 ;
}
return 1 ;
}
static void F_39 ( T_1 * V_1 , const unsigned char * * V_106 ,
T_2 * V_107 )
{
if ( V_1 -> V_108 ) {
* V_106 = V_1 -> V_108 ;
* V_107 = V_1 -> V_109 ;
} else {
* V_106 = V_110 ;
if ( F_13 ( V_1 ) )
* V_107 = sizeof( V_110 ) - 1 ;
else
* V_107 = sizeof( V_110 ) ;
}
}
static int F_40 ( T_1 * V_1 , T_7 * V_111 , int V_112 )
{
unsigned char V_96 , V_6 [ 2 ] ;
T_8 * V_113 ;
int V_114 ;
V_113 = F_41 ( V_111 ) ;
if ( ! V_113 )
return 0 ;
if ( V_113 -> type != V_115 ) {
F_42 ( V_113 ) ;
return 1 ;
}
V_114 = F_33 ( V_6 , & V_96 , V_113 -> V_113 . V_97 ) ;
F_42 ( V_113 ) ;
if ( ! V_114 )
return 0 ;
V_114 = F_38 ( V_1 , V_1 -> V_74 ? V_6 : NULL , & V_96 ) ;
if ( ! V_114 )
return 0 ;
if ( V_112 && F_13 ( V_1 ) ) {
int V_116 ;
T_2 V_55 ;
T_9 * V_117 = V_1 -> V_118 ;
if ( V_6 [ 0 ] )
return 0 ;
if ( V_6 [ 1 ] == V_64 )
V_116 = V_119 ;
else if ( V_6 [ 1 ] == V_66 )
V_116 = V_120 ;
else
return 0 ;
for ( V_55 = 0 ; V_55 < V_117 -> V_121 ; V_55 ++ )
if ( V_116 == V_117 -> V_122 [ V_55 ] . V_123 )
break;
if ( V_55 == V_117 -> V_121 )
return 0 ;
if ( V_112 == 2 ) {
if ( V_116 == V_119 )
V_117 -> V_124 [ V_125 ] . V_126 = F_43 () ;
else
V_117 -> V_124 [ V_125 ] . V_126 = F_44 () ;
}
}
return V_114 ;
}
int F_45 ( T_1 * V_1 , unsigned long V_58 )
{
unsigned char V_6 [ 2 ] ;
T_5 * V_97 = V_1 -> V_118 -> V_127 ;
# ifdef F_46
if ( V_1 -> V_118 -> V_128 & V_129 )
return 1 ;
# endif
if ( F_13 ( V_1 ) ) {
if ( V_58 == V_63 )
V_6 [ 1 ] = V_64 ;
else if ( V_58 == V_65 )
V_6 [ 1 ] = V_66 ;
else
return 0 ;
V_6 [ 0 ] = 0 ;
if ( ! F_38 ( V_1 , V_6 , NULL ) )
return 0 ;
if ( V_1 -> V_118 -> V_130 || V_1 -> V_118 -> V_131 )
return 1 ;
else {
unsigned char V_132 [ 2 ] ;
if ( ! V_97 )
return 0 ;
if ( ! F_33 ( V_132 , NULL , V_97 ) )
return 0 ;
if ( ! V_132 [ 0 ] || V_132 [ 1 ] == V_6 [ 1 ] )
return 1 ;
return 0 ;
}
}
if ( V_1 -> V_118 -> V_130 ) {
if ( F_18 ( V_1 , 0 ) )
return 1 ;
else
return 0 ;
}
if ( ! V_97 ) {
if ( V_1 -> V_118 -> V_131 )
return 1 ;
else
return 0 ;
}
if ( ! F_33 ( V_6 , NULL , V_97 ) )
return 0 ;
# if 0
return 1;
# else
return F_38 ( V_1 , V_6 , NULL ) ;
# endif
}
static int F_40 ( T_1 * V_1 , T_7 * V_111 , int V_112 )
{
return 1 ;
}
T_2 F_47 ( T_1 * V_1 , const unsigned char * * V_133 )
{
# ifndef F_48
switch ( F_13 ( V_1 ) ) {
case V_44 :
* V_133 = V_134 ;
return sizeof( V_134 ) ;
case V_46 :
* V_133 = V_134 ;
return 2 ;
case V_47 :
* V_133 = V_134 + 2 ;
return 2 ;
}
# endif
if ( V_1 -> V_74 && V_1 -> V_118 -> V_135 ) {
* V_133 = V_1 -> V_118 -> V_135 ;
return V_1 -> V_118 -> V_136 ;
} else if ( V_1 -> V_118 -> V_137 ) {
* V_133 = V_1 -> V_118 -> V_137 ;
return V_1 -> V_118 -> V_138 ;
} else {
* V_133 = V_139 ;
return sizeof( V_139 ) ;
}
}
int F_49 ( const T_10 * * V_140 , T_1 * V_1 ,
const unsigned char * V_141 , T_8 * V_113 )
{
const unsigned char * V_142 ;
T_2 V_143 , V_55 ;
int V_144 = F_50 ( V_113 ) ;
if ( V_144 == - 1 )
return - 1 ;
if ( V_144 != ( int ) V_141 [ 1 ] ) {
F_16 ( V_145 , V_146 ) ;
return 0 ;
}
# ifndef F_48
if ( V_113 -> type == V_115 ) {
unsigned char V_6 [ 2 ] , V_96 ;
if ( ! F_33 ( V_6 , & V_96 , V_113 -> V_113 . V_97 ) )
return 0 ;
if ( ! V_1 -> V_74 && ! F_38 ( V_1 , V_6 , & V_96 ) ) {
F_16 ( V_145 , V_147 ) ;
return 0 ;
}
if ( F_13 ( V_1 ) ) {
if ( V_6 [ 0 ] )
return 0 ;
if ( V_6 [ 1 ] == V_64 ) {
if ( V_141 [ 0 ] != V_148 ) {
F_16 ( V_145 ,
V_149 ) ;
return 0 ;
}
} else if ( V_6 [ 1 ] == V_66 ) {
if ( V_141 [ 0 ] != V_150 ) {
F_16 ( V_145 ,
V_149 ) ;
return 0 ;
}
} else
return 0 ;
}
} else if ( F_13 ( V_1 ) )
return 0 ;
# endif
V_143 = F_47 ( V_1 , & V_142 ) ;
for ( V_55 = 0 ; V_55 < V_143 ; V_55 += 2 , V_142 += 2 ) {
if ( V_141 [ 0 ] == V_142 [ 0 ] && V_141 [ 1 ] == V_142 [ 1 ] )
break;
}
if ( V_55 == V_143
&& ( V_141 [ 0 ] != V_151
|| V_1 -> V_118 -> V_128 & V_152 ) ) {
F_16 ( V_145 , V_146 ) ;
return 0 ;
}
* V_140 = F_51 ( V_141 [ 0 ] ) ;
if ( * V_140 == NULL ) {
F_16 ( V_145 , V_153 ) ;
return 0 ;
}
if ( V_1 -> V_41 && V_1 -> V_41 -> V_154 )
V_1 -> V_41 -> V_154 -> V_155 -> V_126 = * V_140 ;
return 1 ;
}
void F_52 ( T_1 * V_1 )
{
T_9 * V_117 = V_1 -> V_118 ;
const unsigned char * V_156 ;
T_2 V_55 , V_157 ;
int V_158 = 0 , V_159 = 0 , V_160 = 0 ;
V_117 -> V_161 = 0 ;
V_117 -> V_162 = 0 ;
if ( ! F_53 ( V_1 ) )
V_117 -> V_163 = V_164 ;
else
V_117 -> V_163 = 0 ;
V_157 = F_47 ( V_1 , & V_156 ) ;
for ( V_55 = 0 ; V_55 < V_157 ; V_55 += 2 , V_156 += 2 ) {
switch ( V_156 [ 1 ] ) {
# ifndef F_54
case V_165 :
V_158 = 1 ;
break;
# endif
# ifndef F_55
case V_166 :
V_159 = 1 ;
break;
# endif
# ifndef F_56
case V_167 :
V_160 = 1 ;
break;
# endif
}
}
if ( ! V_158 ) {
V_117 -> V_161 |= V_168 ;
V_117 -> V_162 |= V_169 | V_170 ;
}
if ( ! V_159 ) {
V_117 -> V_161 |= V_171 ;
V_117 -> V_162 |= V_172 ;
}
if ( ! V_160 ) {
V_117 -> V_161 |= V_173 ;
V_117 -> V_162 |= V_174 ;
}
# ifndef F_57
if ( ! F_58 ( V_1 -> V_175 ) ) {
V_117 -> V_161 |= V_176 ;
V_117 -> V_162 |= V_177 ;
}
# endif
# ifndef F_59
if ( ! V_1 -> V_178 ) {
V_117 -> V_161 |= V_179 ;
V_117 -> V_162 |= V_180 ;
}
# endif
# ifndef F_60
if ( ! ( V_1 -> V_181 . V_182 & V_183 ) ) {
V_117 -> V_161 |= V_184 ;
V_117 -> V_162 |= V_183 ;
}
# endif
V_117 -> V_185 = 1 ;
}
unsigned char * F_61 ( T_1 * V_1 , unsigned char * V_186 ,
unsigned char * V_187 , int * V_188 )
{
int V_189 = 0 ;
unsigned char * V_190 = V_186 ;
unsigned char * V_191 = V_186 ;
# ifndef F_48
int V_192 = 0 ;
if ( V_1 -> V_5 >= V_193 || F_62 ( V_1 ) ) {
int V_55 ;
unsigned long V_194 , V_195 ;
F_63 ( V_196 ) * V_197 = F_64 ( V_1 ) ;
for ( V_55 = 0 ; V_55 < F_65 ( V_197 ) ; V_55 ++ ) {
V_196 * V_117 = F_66 ( V_197 , V_55 ) ;
V_194 = V_117 -> V_198 ;
V_195 = V_117 -> V_199 ;
if ( ( V_194 & ( V_200 | V_170 | V_174 )
|| ( V_195 & V_173 ) ) ) {
V_192 = 1 ;
break;
}
}
}
# endif
if ( V_1 -> V_201 == V_202 && ! V_1 -> V_59 -> V_203 )
return V_190 ;
V_191 += 2 ;
if ( V_191 >= V_187 )
return NULL ;
if ( V_1 -> V_204 != NULL ) {
unsigned long V_205 ;
long V_206 ;
if ( ( V_206 = V_187 - V_191 - 9 ) < 0
|| ( V_205 =
strlen ( V_1 -> V_204 ) ) > ( unsigned long ) V_206 )
return NULL ;
F_26 ( V_207 , V_191 ) ;
F_26 ( V_205 + 5 , V_191 ) ;
F_26 ( V_205 + 3 , V_191 ) ;
* ( V_191 ++ ) = ( unsigned char ) V_208 ;
F_26 ( V_205 , V_191 ) ;
memcpy ( V_191 , V_1 -> V_204 , V_205 ) ;
V_191 += V_205 ;
}
if ( V_1 -> V_209 ) {
int V_210 ;
if ( ! F_67 ( V_1 , 0 , & V_210 , 0 ) ) {
F_16 ( V_211 , V_51 ) ;
return NULL ;
}
if ( ( V_187 - V_191 - 4 - V_210 ) < 0 )
return NULL ;
F_26 ( V_212 , V_191 ) ;
F_26 ( V_210 , V_191 ) ;
if ( ! F_67 ( V_1 , V_191 , & V_210 , V_210 ) ) {
F_16 ( V_211 , V_51 ) ;
return NULL ;
}
V_191 += V_210 ;
}
# ifndef F_60
if ( V_1 -> V_181 . V_213 != NULL ) {
int V_214 = strlen ( V_1 -> V_181 . V_213 ) ;
if ( V_214 > 255 || V_214 == 0 ) {
F_16 ( V_211 , V_51 ) ;
return NULL ;
}
if ( ( V_187 - V_191 - 5 - V_214 ) < 0 )
return NULL ;
F_26 ( V_215 , V_191 ) ;
F_26 ( V_214 + 1 , V_191 ) ;
( * V_191 ++ ) = ( unsigned char ) V_214 ;
memcpy ( V_191 , V_1 -> V_181 . V_213 , V_214 ) ;
V_191 += V_214 ;
}
# endif
# ifndef F_48
if ( V_192 ) {
long V_206 ;
const unsigned char * V_38 , * V_106 ;
T_2 V_39 , V_107 , V_216 ;
F_39 ( V_1 , & V_106 , & V_107 ) ;
if ( ( V_206 = V_187 - V_191 - 5 ) < 0 )
return NULL ;
if ( V_107 > ( T_2 ) V_206 )
return NULL ;
if ( V_107 > 255 ) {
F_16 ( V_211 , V_51 ) ;
return NULL ;
}
F_26 ( V_217 , V_191 ) ;
F_26 ( V_107 + 1 , V_191 ) ;
* ( V_191 ++ ) = ( unsigned char ) V_107 ;
memcpy ( V_191 , V_106 , V_107 ) ;
V_191 += V_107 ;
V_38 = V_1 -> V_42 ;
if ( ! F_12 ( V_1 , 0 , & V_38 , & V_39 ) )
return NULL ;
if ( ( V_206 = V_187 - V_191 - 6 ) < 0 )
return NULL ;
if ( V_39 > ( T_2 ) V_206 / 2 )
return NULL ;
if ( V_39 > 65532 / 2 ) {
F_16 ( V_211 , V_51 ) ;
return NULL ;
}
V_216 = 2 * V_39 ;
F_26 ( V_218 , V_191 ) ;
F_26 ( V_216 + 2 , V_191 ) ;
F_26 ( V_216 , V_191 ) ;
memcpy ( V_191 , V_38 , V_216 ) ;
V_191 += V_216 ;
}
# endif
if ( ! ( F_68 ( V_1 ) & V_219 ) ) {
int V_220 ;
if ( ! V_1 -> V_221 && V_1 -> V_41 && V_1 -> V_41 -> V_222 )
V_220 = V_1 -> V_41 -> V_223 ;
else if ( V_1 -> V_41 && V_1 -> V_4 &&
V_1 -> V_4 -> V_224 ) {
V_220 = V_1 -> V_4 -> V_225 ;
V_1 -> V_41 -> V_222 = F_21 ( V_220 ) ;
if ( ! V_1 -> V_41 -> V_222 )
return NULL ;
memcpy ( V_1 -> V_41 -> V_222 ,
V_1 -> V_4 -> V_224 , V_220 ) ;
V_1 -> V_41 -> V_223 = V_220 ;
} else
V_220 = 0 ;
if ( V_220 == 0 && V_1 -> V_4 &&
V_1 -> V_4 -> V_224 == NULL )
goto V_226;
if ( ( long ) ( V_187 - V_191 - 4 - V_220 ) < 0 )
return NULL ;
F_26 ( V_227 , V_191 ) ;
F_26 ( V_220 , V_191 ) ;
if ( V_220 ) {
memcpy ( V_191 , V_1 -> V_41 -> V_222 , V_220 ) ;
V_191 += V_220 ;
}
}
V_226:
if ( F_69 ( V_1 ) ) {
T_2 V_228 ;
const unsigned char * V_229 ;
V_228 = F_47 ( V_1 , & V_229 ) ;
if ( ( T_2 ) ( V_187 - V_191 ) < V_228 + 6 )
return NULL ;
F_26 ( V_230 , V_191 ) ;
F_26 ( V_228 + 2 , V_191 ) ;
F_26 ( V_228 , V_191 ) ;
memcpy ( V_191 , V_229 , V_228 ) ;
V_191 += V_228 ;
}
# ifdef F_70
if ( V_1 -> V_59 -> V_231 != NULL ) {
T_2 V_232 = V_1 -> V_59 -> V_233 ;
if ( ( long ) ( V_187 - V_191 - 6 - V_232 < 0 ) )
return NULL ;
if ( V_232 > 0xFFFD )
return NULL ;
F_26 ( F_70 , V_191 ) ;
F_26 ( V_232 + 2 , V_191 ) ;
F_26 ( V_232 , V_191 ) ;
memcpy ( V_191 , V_1 -> V_59 -> V_231 , V_232 ) ;
V_191 += V_232 ;
}
# endif
if ( V_1 -> V_234 == V_235 ) {
int V_55 ;
long V_236 , V_237 , V_238 ;
T_11 * V_62 ;
V_237 = 0 ;
for ( V_55 = 0 ; V_55 < F_71 ( V_1 -> V_239 ) ; V_55 ++ ) {
V_62 = F_72 ( V_1 -> V_239 , V_55 ) ;
V_238 = F_73 ( V_62 , NULL ) ;
if ( V_238 <= 0 )
return NULL ;
V_237 += V_238 + 2 ;
}
if ( V_1 -> V_240 ) {
V_236 = F_74 ( V_1 -> V_240 , NULL ) ;
if ( V_236 < 0 )
return NULL ;
} else
V_236 = 0 ;
if ( ( long ) ( V_187 - V_191 - 7 - V_236 - V_237 ) < 0 )
return NULL ;
F_26 ( V_241 , V_191 ) ;
if ( V_236 + V_237 > 0xFFF0 )
return NULL ;
F_26 ( V_236 + V_237 + 5 , V_191 ) ;
* ( V_191 ++ ) = V_235 ;
F_26 ( V_237 , V_191 ) ;
for ( V_55 = 0 ; V_55 < F_71 ( V_1 -> V_239 ) ; V_55 ++ ) {
unsigned char * V_242 = V_191 ;
V_62 = F_72 ( V_1 -> V_239 , V_55 ) ;
V_191 += 2 ;
V_238 = F_73 ( V_62 , & V_191 ) ;
F_26 ( V_238 , V_242 ) ;
}
F_26 ( V_236 , V_191 ) ;
if ( V_236 > 0 )
F_74 ( V_1 -> V_240 , & V_191 ) ;
}
# ifndef F_75
if ( ( V_187 - V_191 - 4 - 1 ) < 0 )
return NULL ;
F_26 ( V_243 , V_191 ) ;
F_26 ( 1 , V_191 ) ;
if ( V_1 -> V_244 & V_245 )
* ( V_191 ++ ) = V_246 ;
else
* ( V_191 ++ ) = V_247 ;
# endif
# ifndef F_76
if ( V_1 -> V_248 -> V_249 && ! V_1 -> V_59 -> V_60 . V_250 ) {
if ( V_187 - V_191 - 4 < 0 )
return NULL ;
F_26 ( V_251 , V_191 ) ;
F_26 ( 0 , V_191 ) ;
}
# endif
if ( V_1 -> V_252 && ! V_1 -> V_59 -> V_60 . V_250 ) {
if ( ( T_2 ) ( V_187 - V_191 ) < 6 + V_1 -> V_253 )
return NULL ;
F_26 ( V_254 , V_191 ) ;
F_26 ( 2 + V_1 -> V_253 , V_191 ) ;
F_26 ( V_1 -> V_253 , V_191 ) ;
memcpy ( V_191 , V_1 -> V_252 , V_1 -> V_253 ) ;
V_191 += V_1 -> V_253 ;
}
# ifndef F_77
if ( F_62 ( V_1 ) && F_78 ( V_1 ) ) {
int V_210 ;
F_79 ( V_1 , 0 , & V_210 , 0 ) ;
if ( ( V_187 - V_191 - 4 - V_210 ) < 0 )
return NULL ;
F_26 ( V_255 , V_191 ) ;
F_26 ( V_210 , V_191 ) ;
if ( F_79 ( V_1 , V_191 , & V_210 , V_210 ) ) {
F_16 ( V_211 , V_51 ) ;
return NULL ;
}
V_191 += V_210 ;
}
# endif
F_80 ( & V_1 -> V_118 -> V_256 ) ;
if ( ! F_81 ( V_1 , 0 , & V_191 , V_187 , V_188 ) )
return NULL ;
if ( V_1 -> V_76 & V_257 ) {
int V_258 = V_191 - ( unsigned char * ) V_1 -> V_259 -> V_224 ;
if ( V_1 -> V_260 == V_261 )
V_258 -= 5 ;
if ( V_258 > 0xff && V_258 < 0x200 ) {
V_258 = 0x200 - V_258 ;
if ( V_258 >= 4 )
V_258 -= 4 ;
else
V_258 = 0 ;
F_26 ( V_262 , V_191 ) ;
F_26 ( V_258 , V_191 ) ;
memset ( V_191 , 0 , V_258 ) ;
V_191 += V_258 ;
}
}
if ( ( V_189 = V_191 - V_190 - 2 ) == 0 )
return V_190 ;
F_26 ( V_189 , V_190 ) ;
return V_191 ;
}
unsigned char * F_82 ( T_1 * V_1 , unsigned char * V_186 ,
unsigned char * V_187 , int * V_188 )
{
int V_189 = 0 ;
unsigned char * V_190 = V_186 ;
unsigned char * V_191 = V_186 ;
# ifndef F_76
int V_263 ;
# endif
# ifndef F_48
unsigned long V_194 = V_1 -> V_59 -> V_60 . V_61 -> V_198 ;
unsigned long V_195 = V_1 -> V_59 -> V_60 . V_61 -> V_199 ;
int V_192 = ( V_194 & ( V_200 | V_170 | V_174 ) )
|| ( V_195 & V_173 ) ;
V_192 = V_192 && ( V_1 -> V_41 -> V_108 != NULL ) ;
# endif
if ( V_1 -> V_5 == V_202 && ! V_1 -> V_59 -> V_203 )
return V_190 ;
V_191 += 2 ;
if ( V_191 >= V_187 )
return NULL ;
if ( ! V_1 -> V_264 && V_1 -> V_265 == 1
&& V_1 -> V_41 -> V_204 != NULL ) {
if ( ( long ) ( V_187 - V_191 - 4 ) < 0 )
return NULL ;
F_26 ( V_207 , V_191 ) ;
F_26 ( 0 , V_191 ) ;
}
if ( V_1 -> V_59 -> V_203 ) {
int V_210 ;
if ( ! F_83 ( V_1 , 0 , & V_210 , 0 ) ) {
F_16 ( V_266 , V_51 ) ;
return NULL ;
}
if ( ( V_187 - V_191 - 4 - V_210 ) < 0 )
return NULL ;
F_26 ( V_212 , V_191 ) ;
F_26 ( V_210 , V_191 ) ;
if ( ! F_83 ( V_1 , V_191 , & V_210 , V_210 ) ) {
F_16 ( V_266 , V_51 ) ;
return NULL ;
}
V_191 += V_210 ;
}
# ifndef F_48
if ( V_192 ) {
const unsigned char * V_267 ;
T_2 V_268 ;
long V_206 ;
F_39 ( V_1 , & V_267 , & V_268 ) ;
if ( ( V_206 = V_187 - V_191 - 5 ) < 0 )
return NULL ;
if ( V_268 > ( T_2 ) V_206 )
return NULL ;
if ( V_268 > 255 ) {
F_16 ( V_266 , V_51 ) ;
return NULL ;
}
F_26 ( V_217 , V_191 ) ;
F_26 ( V_268 + 1 , V_191 ) ;
* ( V_191 ++ ) = ( unsigned char ) V_268 ;
memcpy ( V_191 , V_267 , V_268 ) ;
V_191 += V_268 ;
}
# endif
if ( V_1 -> V_269 && ! ( F_68 ( V_1 ) & V_219 ) ) {
if ( ( long ) ( V_187 - V_191 - 4 ) < 0 )
return NULL ;
F_26 ( V_227 , V_191 ) ;
F_26 ( 0 , V_191 ) ;
}
if ( V_1 -> V_270 ) {
if ( ( long ) ( V_187 - V_191 - 4 ) < 0 )
return NULL ;
F_26 ( V_241 , V_191 ) ;
F_26 ( 0 , V_191 ) ;
}
# ifdef F_70
if ( V_1 -> V_59 -> V_271 != NULL ) {
T_2 V_272 = V_1 -> V_59 -> V_273 ;
if ( ( long ) ( V_187 - V_191 - 6 - V_272 ) < 0 )
return NULL ;
if ( V_272 > 0xFFFD )
return NULL ;
F_26 ( F_70 , V_191 ) ;
F_26 ( V_272 + 2 , V_191 ) ;
F_26 ( V_272 , V_191 ) ;
memcpy ( V_191 , V_1 -> V_59 -> V_271 , V_272 ) ;
V_191 += V_272 ;
}
# endif
# ifndef F_77
if ( F_62 ( V_1 ) && V_1 -> V_274 ) {
int V_210 ;
F_84 ( V_1 , 0 , & V_210 , 0 ) ;
if ( ( V_187 - V_191 - 4 - V_210 ) < 0 )
return NULL ;
F_26 ( V_255 , V_191 ) ;
F_26 ( V_210 , V_191 ) ;
if ( F_84 ( V_1 , V_191 , & V_210 , V_210 ) ) {
F_16 ( V_266 , V_51 ) ;
return NULL ;
}
V_191 += V_210 ;
}
# endif
if ( ( ( V_1 -> V_59 -> V_60 . V_61 -> V_62 & 0xFFFF ) == 0x80
|| ( V_1 -> V_59 -> V_60 . V_61 -> V_62 & 0xFFFF ) == 0x81 )
&& ( F_68 ( V_1 ) & V_275 ) ) {
const unsigned char V_276 [ 36 ] = {
0xfd , 0xe8 ,
0x00 , 0x20 ,
0x30 , 0x1e , 0x30 , 0x08 , 0x06 , 0x06 , 0x2a , 0x85 ,
0x03 , 0x02 , 0x02 , 0x09 , 0x30 , 0x08 , 0x06 , 0x06 ,
0x2a , 0x85 , 0x03 , 0x02 , 0x02 , 0x16 , 0x30 , 0x08 ,
0x06 , 0x06 , 0x2a , 0x85 , 0x03 , 0x02 , 0x02 , 0x17
} ;
if ( V_187 - V_191 < 36 )
return NULL ;
memcpy ( V_191 , V_276 , 36 ) ;
V_191 += 36 ;
}
# ifndef F_75
if ( V_1 -> V_244 & V_247 ) {
if ( ( V_187 - V_191 - 4 - 1 ) < 0 )
return NULL ;
F_26 ( V_243 , V_191 ) ;
F_26 ( 1 , V_191 ) ;
if ( V_1 -> V_244 & V_245 )
* ( V_191 ++ ) = V_246 ;
else
* ( V_191 ++ ) = V_247 ;
}
# endif
# ifndef F_76
V_263 = V_1 -> V_59 -> V_263 ;
V_1 -> V_59 -> V_263 = 0 ;
if ( V_263 && V_1 -> V_248 -> V_277 ) {
const unsigned char * V_278 ;
unsigned int V_279 ;
int V_280 ;
V_280 = V_1 -> V_248 -> V_277 ( V_1 , & V_278 , & V_279 ,
V_1 ->
V_248 -> V_281 ) ;
if ( V_280 == V_282 ) {
if ( ( long ) ( V_187 - V_191 - 4 - V_279 ) < 0 )
return NULL ;
F_26 ( V_251 , V_191 ) ;
F_26 ( V_279 , V_191 ) ;
memcpy ( V_191 , V_278 , V_279 ) ;
V_191 += V_279 ;
V_1 -> V_59 -> V_263 = 1 ;
}
}
# endif
if ( ! F_81 ( V_1 , 1 , & V_191 , V_187 , V_188 ) )
return NULL ;
if ( V_1 -> V_59 -> V_283 ) {
const unsigned char * V_284 = V_1 -> V_59 -> V_283 ;
unsigned V_53 = V_1 -> V_59 -> V_285 ;
if ( ( long ) ( V_187 - V_191 - 4 - 2 - 1 - V_53 ) < 0 )
return NULL ;
F_26 ( V_254 , V_191 ) ;
F_26 ( 3 + V_53 , V_191 ) ;
F_26 ( 1 + V_53 , V_191 ) ;
* V_191 ++ = V_53 ;
memcpy ( V_191 , V_284 , V_53 ) ;
V_191 += V_53 ;
}
if ( ( V_189 = V_191 - V_190 - 2 ) == 0 )
return V_190 ;
F_26 ( V_189 , V_190 ) ;
return V_191 ;
}
static void F_85 ( T_1 * V_1 , const unsigned char * V_224 ,
const unsigned char * V_286 , int V_287 )
{
unsigned short type , V_288 ;
static const unsigned char V_289 [] = {
0x00 , 0x0a ,
0x00 , 0x08 ,
0x00 , 0x06 ,
0x00 , 0x17 ,
0x00 , 0x18 ,
0x00 , 0x19 ,
0x00 , 0x0b ,
0x00 , 0x02 ,
0x01 ,
0x00 ,
} ;
static const unsigned char V_290 [] = {
0x00 , 0x0d ,
0x00 , 0x0c ,
0x00 , 0x0a ,
0x05 , 0x01 ,
0x04 , 0x01 ,
0x02 , 0x01 ,
0x04 , 0x03 ,
0x02 , 0x03 ,
} ;
if ( V_224 >= ( V_286 + V_287 - 2 ) )
return;
V_224 += 2 ;
if ( V_224 > ( V_286 + V_287 - 4 ) )
return;
F_86 ( V_224 , type ) ;
F_86 ( V_224 , V_288 ) ;
if ( type != V_207 )
return;
if ( V_224 + V_288 > V_286 + V_287 )
return;
V_224 += V_288 ;
if ( F_87 ( V_1 ) >= V_291 ) {
const T_2 V_292 = sizeof( V_289 ) ;
const T_2 V_293 = sizeof( V_290 ) ;
if ( V_224 + V_292 + V_293 != V_286 + V_287 )
return;
if ( memcmp ( V_224 , V_289 , V_292 ) != 0 )
return;
if ( memcmp ( V_224 + V_292 , V_290 , V_293 ) != 0 )
return;
} else {
const T_2 V_53 = sizeof( V_289 ) ;
if ( V_224 + V_53 != V_286 + V_287 )
return;
if ( memcmp ( V_224 , V_289 , V_53 ) != 0 )
return;
}
V_1 -> V_59 -> V_294 = 1 ;
}
static int F_88 ( T_1 * V_1 , const unsigned char * V_224 ,
unsigned V_295 , int * V_188 )
{
unsigned V_55 ;
unsigned V_296 ;
const unsigned char * V_284 ;
unsigned char V_297 ;
int V_280 ;
if ( V_1 -> V_248 -> V_298 == NULL )
return 0 ;
if ( V_295 < 2 )
goto V_299;
V_55 = ( ( unsigned ) V_224 [ 0 ] ) << 8 | ( ( unsigned ) V_224 [ 1 ] ) ;
V_295 -= 2 ;
V_224 += 2 ;
if ( V_295 != V_55 )
goto V_299;
if ( V_295 < 2 )
goto V_299;
for ( V_55 = 0 ; V_55 < V_295 ; ) {
V_296 = V_224 [ V_55 ] ;
V_55 ++ ;
if ( V_296 == 0 )
goto V_299;
if ( V_55 + V_296 < V_55 || V_55 + V_296 > V_295 )
goto V_299;
V_55 += V_296 ;
}
V_280 = V_1 -> V_248 -> V_298 ( V_1 , & V_284 , & V_297 , V_224 , V_295 ,
V_1 -> V_248 -> V_300 ) ;
if ( V_280 == V_282 ) {
if ( V_1 -> V_59 -> V_283 )
F_6 ( V_1 -> V_59 -> V_283 ) ;
V_1 -> V_59 -> V_283 = F_21 ( V_297 ) ;
if ( ! V_1 -> V_59 -> V_283 ) {
* V_188 = V_301 ;
return - 1 ;
}
memcpy ( V_1 -> V_59 -> V_283 , V_284 , V_297 ) ;
V_1 -> V_59 -> V_285 = V_297 ;
}
return 0 ;
V_299:
* V_188 = V_302 ;
return - 1 ;
}
static int F_89 ( T_1 * V_1 , unsigned char * * V_52 ,
unsigned char * V_286 , int V_287 , int * V_188 )
{
unsigned short type ;
unsigned short V_288 ;
unsigned short V_53 ;
unsigned char * V_224 = * V_52 ;
int V_303 = 0 ;
V_1 -> V_265 = 0 ;
V_1 -> V_234 = - 1 ;
# ifndef F_76
V_1 -> V_59 -> V_263 = 0 ;
# endif
if ( V_1 -> V_59 -> V_283 ) {
F_6 ( V_1 -> V_59 -> V_283 ) ;
V_1 -> V_59 -> V_283 = NULL ;
}
# ifndef F_75
V_1 -> V_244 &= ~ ( V_247 |
V_246 ) ;
# endif
# ifndef F_48
if ( V_1 -> V_76 & V_304 )
F_85 ( V_1 , V_224 , V_286 , V_287 ) ;
# endif
if ( V_1 -> V_118 -> V_305 ) {
F_6 ( V_1 -> V_118 -> V_305 ) ;
V_1 -> V_118 -> V_305 = NULL ;
}
# ifndef F_60
if ( V_1 -> V_181 . V_213 != NULL ) {
F_6 ( V_1 -> V_181 . V_213 ) ;
V_1 -> V_181 . V_213 = NULL ;
}
# endif
V_1 -> V_274 = NULL ;
if ( V_224 >= ( V_286 + V_287 - 2 ) )
goto V_306;
F_86 ( V_224 , V_53 ) ;
if ( V_224 > ( V_286 + V_287 - V_53 ) )
goto V_306;
while ( V_224 <= ( V_286 + V_287 - 4 ) ) {
F_86 ( V_224 , type ) ;
F_86 ( V_224 , V_288 ) ;
if ( V_224 + V_288 > ( V_286 + V_287 ) )
goto V_306;
# if 0
fprintf(stderr, "Received extension type %d size %d\n", type, size);
# endif
if ( V_1 -> V_307 )
V_1 -> V_307 ( V_1 , 0 , type , V_224 , V_288 , V_1 -> V_308 ) ;
if ( type == V_207 ) {
unsigned char * V_309 ;
int V_310 ;
int V_311 ;
if ( V_288 < 2 ) {
* V_188 = V_302 ;
return 0 ;
}
F_86 ( V_224 , V_311 ) ;
V_288 -= 2 ;
if ( V_311 > V_288 ) {
* V_188 = V_302 ;
return 0 ;
}
V_309 = V_224 ;
while ( V_311 > 3 ) {
V_310 = * ( V_309 ++ ) ;
F_86 ( V_309 , V_53 ) ;
V_311 -= 3 ;
if ( V_53 > V_311 ) {
* V_188 = V_302 ;
return 0 ;
}
if ( V_1 -> V_265 == 0 )
switch ( V_310 ) {
case V_208 :
if ( ! V_1 -> V_264 ) {
if ( V_1 -> V_41 -> V_204 ) {
* V_188 = V_302 ;
return 0 ;
}
if ( V_53 > V_312 ) {
* V_188 = V_313 ;
return 0 ;
}
if ( ( V_1 -> V_41 -> V_204 =
F_21 ( V_53 + 1 ) ) == NULL ) {
* V_188 = V_314 ;
return 0 ;
}
memcpy ( V_1 -> V_41 -> V_204 , V_309 , V_53 ) ;
V_1 -> V_41 -> V_204 [ V_53 ] = '\0' ;
if ( strlen ( V_1 -> V_41 -> V_204 ) != V_53 ) {
F_6 ( V_1 -> V_41 -> V_204 ) ;
V_1 -> V_41 -> V_204 = NULL ;
* V_188 = V_313 ;
return 0 ;
}
V_1 -> V_265 = 1 ;
} else
V_1 -> V_265 = V_1 -> V_41 -> V_204
&& strlen ( V_1 -> V_41 -> V_204 ) == V_53
&& strncmp ( V_1 -> V_41 -> V_204 ,
( char * ) V_309 , V_53 ) == 0 ;
break;
default:
break;
}
V_311 -= V_53 ;
}
if ( V_311 != 0 ) {
* V_188 = V_302 ;
return 0 ;
}
}
# ifndef F_60
else if ( type == V_215 ) {
if ( V_288 <= 0 || ( ( V_53 = V_224 [ 0 ] ) ) != ( V_288 - 1 ) ) {
* V_188 = V_302 ;
return 0 ;
}
if ( V_1 -> V_181 . V_213 != NULL ) {
* V_188 = V_302 ;
return 0 ;
}
if ( ( V_1 -> V_181 . V_213 = F_21 ( V_53 + 1 ) ) == NULL )
return - 1 ;
memcpy ( V_1 -> V_181 . V_213 , & V_224 [ 1 ] , V_53 ) ;
V_1 -> V_181 . V_213 [ V_53 ] = '\0' ;
if ( strlen ( V_1 -> V_181 . V_213 ) != V_53 ) {
* V_188 = V_302 ;
return 0 ;
}
}
# endif
# ifndef F_48
else if ( type == V_217 ) {
unsigned char * V_309 = V_224 ;
int V_315 = * ( V_309 ++ ) ;
if ( V_315 != V_288 - 1 ||
V_315 < 1 ) {
* V_188 = V_316 ;
return 0 ;
}
if ( ! V_1 -> V_264 ) {
if ( V_1 -> V_41 -> V_108 ) {
F_6 ( V_1 -> V_41 -> V_108 ) ;
V_1 -> V_41 -> V_108 = NULL ;
}
V_1 -> V_41 -> V_109 = 0 ;
if ( ( V_1 -> V_41 -> V_108 =
F_21 ( V_315 ) ) == NULL ) {
* V_188 = V_314 ;
return 0 ;
}
V_1 -> V_41 -> V_109 =
V_315 ;
memcpy ( V_1 -> V_41 -> V_108 , V_309 ,
V_315 ) ;
}
# if 0
fprintf(stderr,
"ssl_parse_clienthello_tlsext s->session->tlsext_ecpointformatlist (length=%i) ",
s->session->tlsext_ecpointformatlist_length);
sdata = s->session->tlsext_ecpointformatlist;
for (i = 0; i < s->session->tlsext_ecpointformatlist_length; i++)
fprintf(stderr, "%i ", *(sdata++));
fprintf(stderr, "\n");
# endif
} else if ( type == V_218 ) {
unsigned char * V_309 = V_224 ;
int V_317 = ( * ( V_309 ++ ) << 8 ) ;
V_317 += ( * ( V_309 ++ ) ) ;
if ( V_317 != V_288 - 2 ||
V_317 < 1 ||
V_317 & 1 ) {
* V_188 = V_316 ;
return 0 ;
}
if ( ! V_1 -> V_264 ) {
if ( V_1 -> V_41 -> V_42 ) {
* V_188 = V_316 ;
return 0 ;
}
V_1 -> V_41 -> V_43 = 0 ;
if ( ( V_1 -> V_41 -> V_42 =
F_21 ( V_317 ) ) == NULL ) {
* V_188 = V_314 ;
return 0 ;
}
V_1 -> V_41 -> V_43 =
V_317 ;
memcpy ( V_1 -> V_41 -> V_42 , V_309 ,
V_317 ) ;
}
# if 0
fprintf(stderr,
"ssl_parse_clienthello_tlsext s->session->tlsext_ellipticcurvelist (length=%i) ",
s->session->tlsext_ellipticcurvelist_length);
sdata = s->session->tlsext_ellipticcurvelist;
for (i = 0; i < s->session->tlsext_ellipticcurvelist_length; i++)
fprintf(stderr, "%i ", *(sdata++));
fprintf(stderr, "\n");
# endif
}
# endif
# ifdef F_70
else if ( type == F_70 ) {
unsigned char * V_309 = V_224 ;
if ( V_288 < 2 ) {
* V_188 = V_302 ;
return 0 ;
}
F_86 ( V_309 , V_1 -> V_59 -> V_233 ) ;
if ( V_1 -> V_59 -> V_233 != V_288 - 2 ) {
* V_188 = V_302 ;
return 0 ;
}
if ( V_1 -> V_59 -> V_231 != NULL ) {
F_6 ( V_1 -> V_59 -> V_231 ) ;
}
if ( V_1 -> V_59 -> V_233 == 0 )
V_1 -> V_59 -> V_231 = F_21 ( 1 ) ;
else
V_1 -> V_59 -> V_231 =
F_90 ( V_309 , V_1 -> V_59 -> V_233 ) ;
if ( V_1 -> V_59 -> V_231 == NULL ) {
* V_188 = V_314 ;
return 0 ;
}
}
# endif
else if ( type == V_227 ) {
if ( V_1 -> V_318 &&
! V_1 -> V_318 ( V_1 , V_224 , V_288 ,
V_1 -> V_319 ) )
{
* V_188 = V_314 ;
return 0 ;
}
} else if ( type == V_212 ) {
if ( ! F_91 ( V_1 , V_224 , V_288 , V_188 ) )
return 0 ;
V_303 = 1 ;
} else if ( type == V_230 ) {
int V_311 ;
if ( V_1 -> V_118 -> V_305 || V_288 < 2 ) {
* V_188 = V_302 ;
return 0 ;
}
F_86 ( V_224 , V_311 ) ;
V_288 -= 2 ;
if ( V_311 != V_288 || V_311 & 1 || ! V_311 ) {
* V_188 = V_302 ;
return 0 ;
}
if ( ! F_92 ( V_1 , V_224 , V_311 ) ) {
* V_188 = V_302 ;
return 0 ;
}
} else if ( type == V_241 ) {
if ( V_288 < 5 ) {
* V_188 = V_302 ;
return 0 ;
}
V_1 -> V_234 = * V_224 ++ ;
V_288 -- ;
if ( V_1 -> V_234 == V_235 ) {
const unsigned char * V_309 ;
int V_311 ;
F_86 ( V_224 , V_311 ) ;
V_288 -= 2 ;
if ( V_311 > V_288 ) {
* V_188 = V_302 ;
return 0 ;
}
while ( V_311 > 0 ) {
T_11 * V_62 ;
int V_320 ;
if ( V_311 < 4 ) {
* V_188 = V_302 ;
return 0 ;
}
F_86 ( V_224 , V_320 ) ;
V_311 -= 2 + V_320 ;
V_288 -= 2 + V_320 ;
if ( V_311 < 0 ) {
* V_188 = V_302 ;
return 0 ;
}
V_309 = V_224 ;
V_224 += V_320 ;
V_62 = F_93 ( NULL , & V_309 , V_320 ) ;
if ( ! V_62 ) {
* V_188 = V_302 ;
return 0 ;
}
if ( V_224 != V_309 ) {
F_94 ( V_62 ) ;
* V_188 = V_302 ;
return 0 ;
}
if ( ! V_1 -> V_239
&& ! ( V_1 -> V_239 =
F_95 () ) ) {
F_94 ( V_62 ) ;
* V_188 = V_301 ;
return 0 ;
}
if ( ! F_96 ( V_1 -> V_239 , V_62 ) ) {
F_94 ( V_62 ) ;
* V_188 = V_301 ;
return 0 ;
}
}
if ( V_288 < 2 ) {
* V_188 = V_302 ;
return 0 ;
}
F_86 ( V_224 , V_311 ) ;
V_288 -= 2 ;
if ( V_311 != V_288 ) {
* V_188 = V_302 ;
return 0 ;
}
V_309 = V_224 ;
if ( V_311 > 0 ) {
if ( V_1 -> V_240 ) {
F_97 ( V_1 -> V_240 ,
V_321 ) ;
}
V_1 -> V_240 =
F_98 ( NULL , & V_309 , V_311 ) ;
if ( ! V_1 -> V_240 || ( V_224 + V_311 != V_309 ) ) {
* V_188 = V_302 ;
return 0 ;
}
}
}
else
V_1 -> V_234 = - 1 ;
}
# ifndef F_75
else if ( type == V_243 ) {
switch ( V_224 [ 0 ] ) {
case 0x01 :
V_1 -> V_244 |= V_247 ;
break;
case 0x02 :
V_1 -> V_244 |= V_247 ;
V_1 -> V_244 |= V_246 ;
break;
default:
* V_188 = V_322 ;
return 0 ;
}
}
# endif
# ifndef F_76
else if ( type == V_251 &&
V_1 -> V_59 -> V_60 . V_250 == 0 &&
V_1 -> V_59 -> V_283 == NULL ) {
V_1 -> V_59 -> V_263 = 1 ;
}
# endif
else if ( type == V_254 &&
V_1 -> V_248 -> V_298 && V_1 -> V_59 -> V_60 . V_250 == 0 ) {
if ( F_88 ( V_1 , V_224 , V_288 , V_188 ) != 0 )
return 0 ;
# ifndef F_76
V_1 -> V_59 -> V_263 = 0 ;
# endif
}
# ifndef F_77
else if ( F_62 ( V_1 ) && F_78 ( V_1 )
&& type == V_255 ) {
if ( F_99 ( V_1 , V_224 , V_288 , V_188 ) )
return 0 ;
}
# endif
V_224 += V_288 ;
}
* V_52 = V_224 ;
V_306:
if ( ! V_303 && V_1 -> V_209 &&
! ( V_1 -> V_76 & V_323 ) ) {
* V_188 = V_324 ;
F_16 ( V_325 ,
V_326 ) ;
return 0 ;
}
return 1 ;
}
static int F_100 ( T_1 * V_1 ,
const unsigned char * V_224 ,
const unsigned char * V_187 ,
int * V_188 )
{
unsigned short type , V_288 , V_53 ;
if ( V_1 -> V_264 || V_1 -> V_118 -> V_327 . V_328 == 0 )
return 1 ;
if ( V_224 >= V_187 - 2 )
return 1 ;
F_86 ( V_224 , V_53 ) ;
if ( V_224 > V_187 - V_53 )
return 1 ;
while ( V_224 <= V_187 - 4 ) {
F_86 ( V_224 , type ) ;
F_86 ( V_224 , V_288 ) ;
if ( V_224 + V_288 > V_187 )
return 1 ;
if ( F_101 ( V_1 , 1 , type , V_224 , V_288 , V_188 ) <= 0 )
return 0 ;
V_224 += V_288 ;
}
return 1 ;
}
int F_102 ( T_1 * V_1 , unsigned char * * V_52 , unsigned char * V_286 ,
int V_287 )
{
int V_188 = - 1 ;
unsigned char * V_329 = * V_52 ;
if ( F_89 ( V_1 , V_52 , V_286 , V_287 , & V_188 ) <= 0 ) {
F_103 ( V_1 , V_330 , V_188 ) ;
return 0 ;
}
if ( F_104 ( V_1 ) <= 0 ) {
F_16 ( V_331 , V_332 ) ;
return 0 ;
}
F_80 ( & V_1 -> V_118 -> V_327 ) ;
if ( F_100 ( V_1 , V_329 , V_286 + V_287 , & V_188 ) <= 0 ) {
F_103 ( V_1 , V_330 , V_188 ) ;
return 0 ;
}
return 1 ;
}
static char F_105 ( unsigned char * V_286 , unsigned V_53 )
{
unsigned int V_333 = 0 ;
while ( V_333 < V_53 ) {
if ( V_286 [ V_333 ] == 0 )
return 0 ;
V_333 += V_286 [ V_333 ] ;
V_333 ++ ;
}
return V_333 == V_53 ;
}
static int F_106 ( T_1 * V_1 , unsigned char * * V_52 ,
unsigned char * V_286 , int V_287 , int * V_188 )
{
unsigned short V_225 ;
unsigned short type ;
unsigned short V_288 ;
unsigned char * V_224 = * V_52 ;
int V_334 = 0 ;
int V_303 = 0 ;
# ifndef F_76
V_1 -> V_59 -> V_263 = 0 ;
# endif
V_1 -> V_269 = 0 ;
if ( V_1 -> V_59 -> V_283 ) {
F_6 ( V_1 -> V_59 -> V_283 ) ;
V_1 -> V_59 -> V_283 = NULL ;
}
# ifndef F_75
V_1 -> V_244 &= ~ ( V_247 |
V_246 ) ;
# endif
if ( V_224 >= ( V_286 + V_287 - 2 ) )
goto V_306;
F_86 ( V_224 , V_225 ) ;
if ( V_224 + V_225 != V_286 + V_287 ) {
* V_188 = V_302 ;
return 0 ;
}
while ( V_224 <= ( V_286 + V_287 - 4 ) ) {
F_86 ( V_224 , type ) ;
F_86 ( V_224 , V_288 ) ;
if ( V_224 + V_288 > ( V_286 + V_287 ) )
goto V_306;
if ( V_1 -> V_307 )
V_1 -> V_307 ( V_1 , 1 , type , V_224 , V_288 , V_1 -> V_308 ) ;
if ( type == V_207 ) {
if ( V_1 -> V_204 == NULL || V_288 > 0 ) {
* V_188 = V_313 ;
return 0 ;
}
V_334 = 1 ;
}
# ifndef F_48
else if ( type == V_217 ) {
unsigned char * V_309 = V_224 ;
int V_315 = * ( V_309 ++ ) ;
if ( V_315 != V_288 - 1 ) {
* V_188 = V_316 ;
return 0 ;
}
if ( ! V_1 -> V_264 ) {
V_1 -> V_41 -> V_109 = 0 ;
if ( V_1 -> V_41 -> V_108 != NULL )
F_6 ( V_1 -> V_41 -> V_108 ) ;
if ( ( V_1 -> V_41 -> V_108 =
F_21 ( V_315 ) ) == NULL ) {
* V_188 = V_314 ;
return 0 ;
}
V_1 -> V_41 -> V_109 =
V_315 ;
memcpy ( V_1 -> V_41 -> V_108 , V_309 ,
V_315 ) ;
}
# if 0
fprintf(stderr,
"ssl_parse_serverhello_tlsext s->session->tlsext_ecpointformatlist ");
sdata = s->session->tlsext_ecpointformatlist;
for (i = 0; i < s->session->tlsext_ecpointformatlist_length; i++)
fprintf(stderr, "%i ", *(sdata++));
fprintf(stderr, "\n");
# endif
}
# endif
else if ( type == V_227 ) {
if ( V_1 -> V_318 &&
! V_1 -> V_318 ( V_1 , V_224 , V_288 ,
V_1 -> V_319 ) )
{
* V_188 = V_314 ;
return 0 ;
}
if ( ( F_68 ( V_1 ) & V_219 )
|| ( V_288 > 0 ) ) {
* V_188 = V_335 ;
return 0 ;
}
V_1 -> V_269 = 1 ;
}
# ifdef F_70
else if ( type == F_70 ) {
unsigned char * V_309 = V_224 ;
if ( V_288 < 2 ) {
* V_188 = V_302 ;
return 0 ;
}
F_86 ( V_309 , V_1 -> V_59 -> V_273 ) ;
if ( V_1 -> V_59 -> V_273 != V_288 - 2 ) {
* V_188 = V_302 ;
return 0 ;
}
if ( V_1 -> V_59 -> V_271 != NULL ) {
F_6 ( V_1 -> V_59 -> V_271 ) ;
}
if ( V_1 -> V_59 -> V_273 == 0 ) {
V_1 -> V_59 -> V_271 = F_21 ( 1 ) ;
} else {
V_1 -> V_59 -> V_271 =
F_90 ( V_309 , V_1 -> V_59 -> V_273 ) ;
}
if ( V_1 -> V_59 -> V_271 == NULL ) {
* V_188 = V_314 ;
return 0 ;
}
}
# endif
else if ( type == V_241 ) {
if ( ( V_1 -> V_234 == - 1 ) || ( V_288 > 0 ) ) {
* V_188 = V_335 ;
return 0 ;
}
V_1 -> V_270 = 1 ;
}
# ifndef F_76
else if ( type == V_251 &&
V_1 -> V_59 -> V_60 . V_250 == 0 ) {
unsigned char * V_284 ;
unsigned char V_297 ;
if ( V_1 -> V_248 -> V_249 == NULL ) {
* V_188 = V_335 ;
return 0 ;
}
if ( ! F_105 ( V_224 , V_288 ) ) {
* V_188 = V_316 ;
return 0 ;
}
if ( V_1 ->
V_248 -> V_249 ( V_1 , & V_284 , & V_297 , V_224 ,
V_288 ,
V_1 -> V_248 -> V_336 ) !=
V_282 ) {
* V_188 = V_314 ;
return 0 ;
}
V_1 -> V_337 = F_21 ( V_297 ) ;
if ( ! V_1 -> V_337 ) {
* V_188 = V_314 ;
return 0 ;
}
memcpy ( V_1 -> V_337 , V_284 , V_297 ) ;
V_1 -> V_338 = V_297 ;
V_1 -> V_59 -> V_263 = 1 ;
}
# endif
else if ( type == V_254 ) {
unsigned V_53 ;
if ( V_1 -> V_252 == NULL ) {
* V_188 = V_335 ;
return 0 ;
}
if ( V_288 < 4 ) {
* V_188 = V_316 ;
return 0 ;
}
V_53 = V_224 [ 0 ] ;
V_53 <<= 8 ;
V_53 |= V_224 [ 1 ] ;
if ( V_53 != ( unsigned ) V_288 - 2 ) {
* V_188 = V_316 ;
return 0 ;
}
V_53 = V_224 [ 2 ] ;
if ( V_53 != ( unsigned ) V_288 - 3 ) {
* V_188 = V_316 ;
return 0 ;
}
if ( V_1 -> V_59 -> V_283 )
F_6 ( V_1 -> V_59 -> V_283 ) ;
V_1 -> V_59 -> V_283 = F_21 ( V_53 ) ;
if ( ! V_1 -> V_59 -> V_283 ) {
* V_188 = V_314 ;
return 0 ;
}
memcpy ( V_1 -> V_59 -> V_283 , V_224 + 3 , V_53 ) ;
V_1 -> V_59 -> V_285 = V_53 ;
}
else if ( type == V_212 ) {
if ( ! F_107 ( V_1 , V_224 , V_288 , V_188 ) )
return 0 ;
V_303 = 1 ;
}
# ifndef F_75
else if ( type == V_243 ) {
switch ( V_224 [ 0 ] ) {
case 0x01 :
V_1 -> V_244 |= V_247 ;
break;
case 0x02 :
V_1 -> V_244 |= V_247 ;
V_1 -> V_244 |= V_246 ;
break;
default:
* V_188 = V_322 ;
return 0 ;
}
}
# endif
# ifndef F_77
else if ( F_62 ( V_1 ) && type == V_255 ) {
if ( F_108 ( V_1 , V_224 , V_288 , V_188 ) )
return 0 ;
}
# endif
else if ( F_101 ( V_1 , 0 , type , V_224 , V_288 , V_188 ) <= 0 )
return 0 ;
V_224 += V_288 ;
}
if ( V_224 != V_286 + V_287 ) {
* V_188 = V_302 ;
return 0 ;
}
if ( ! V_1 -> V_264 && V_334 == 1 ) {
if ( V_1 -> V_204 ) {
if ( V_1 -> V_41 -> V_204 == NULL ) {
V_1 -> V_41 -> V_204 = F_109 ( V_1 -> V_204 ) ;
if ( ! V_1 -> V_41 -> V_204 ) {
* V_188 = V_339 ;
return 0 ;
}
} else {
* V_188 = V_302 ;
return 0 ;
}
}
}
* V_52 = V_224 ;
V_306:
if ( ! V_303 && ! ( V_1 -> V_76 & V_340 )
&& ! ( V_1 -> V_76 & V_323 ) ) {
* V_188 = V_324 ;
F_16 ( V_341 ,
V_326 ) ;
return 0 ;
}
return 1 ;
}
int F_110 ( T_1 * V_1 )
{
# ifdef F_70
{
int V_280 = 1 ;
if ( V_1 -> V_248 -> V_342 != 0 ) {
V_280 = V_1 -> V_248 -> V_342 ( V_1 , NULL , 0 ,
V_1 ->
V_248 -> V_343 ) ;
if ( ! V_280 )
return - 1 ;
}
if ( V_1 -> V_344 != NULL ) {
if ( V_1 -> V_59 -> V_231 != NULL ) {
F_6 ( V_1 -> V_59 -> V_231 ) ;
}
if ( V_1 -> V_345 == 0 ) {
V_1 -> V_59 -> V_231 = F_21 ( 1 ) ;
} else {
V_1 -> V_59 -> V_231 =
F_90 ( V_1 -> V_344 ,
V_1 -> V_345 ) ;
}
if ( V_1 -> V_59 -> V_231 == NULL ) {
F_16 ( V_346 ,
V_347 ) ;
return - 1 ;
}
V_1 -> V_59 -> V_233 =
V_1 -> V_345 ;
}
if ( V_280 == 2 )
V_1 -> V_59 -> V_273 =
V_1 -> V_345 ;
}
# endif
return 1 ;
}
int F_111 ( T_1 * V_1 )
{
return 1 ;
}
static int F_104 ( T_1 * V_1 )
{
int V_191 = V_348 ;
int V_188 = V_339 ;
# ifndef F_48
# endif
if ( V_1 -> V_248 != NULL && V_1 -> V_248 -> V_349 != 0 )
V_191 =
V_1 -> V_248 -> V_349 ( V_1 , & V_188 ,
V_1 -> V_248 -> V_350 ) ;
else if ( V_1 -> V_351 != NULL
&& V_1 -> V_351 -> V_349 != 0 )
V_191 =
V_1 -> V_351 -> V_349 ( V_1 , & V_188 ,
V_1 ->
V_351 -> V_350 ) ;
# ifdef F_70
{
int V_280 = 1 ;
if ( V_1 -> V_248 -> V_342 != 0 ) {
V_280 = V_1 -> V_248 -> V_342 ( V_1 , NULL , 0 ,
V_1 ->
V_248 -> V_343 ) ;
if ( ! V_280 ) {
V_191 = V_352 ;
V_188 = V_301 ;
goto V_353;
}
}
if ( V_1 -> V_59 -> V_271 != NULL ) {
F_6 ( V_1 -> V_59 -> V_271 ) ;
}
V_1 -> V_59 -> V_271 = NULL ;
if ( V_1 -> V_344 != NULL ) {
if ( V_1 -> V_59 -> V_231 != NULL &&
V_1 -> V_59 -> V_233 ==
V_1 -> V_345 ) {
if ( V_1 -> V_345 == 0 ) {
V_1 -> V_59 -> V_271 = F_21 ( 1 ) ;
} else {
V_1 -> V_59 -> V_271 =
F_90 ( V_1 -> V_344 ,
V_1 -> V_345 ) ;
}
if ( V_1 -> V_59 -> V_271 == NULL ) {
V_191 = V_352 ;
V_188 = V_301 ;
goto V_353;
}
V_1 -> V_59 -> V_273 =
V_1 -> V_345 ;
}
}
if ( V_280 == 2 && V_1 -> V_59 -> V_271 == NULL ) {
V_191 = V_352 ;
V_188 = V_324 ;
}
}
V_353:
# endif
switch ( V_191 ) {
case V_352 :
F_103 ( V_1 , V_330 , V_188 ) ;
return - 1 ;
case V_354 :
F_103 ( V_1 , V_355 , V_188 ) ;
return 1 ;
case V_348 :
V_1 -> V_265 = 0 ;
default:
return 1 ;
}
}
int F_112 ( T_1 * V_1 )
{
int V_188 ;
T_2 V_55 ;
if ( V_1 -> V_118 -> V_122 ) {
F_6 ( V_1 -> V_118 -> V_122 ) ;
V_1 -> V_118 -> V_122 = NULL ;
}
for ( V_55 = 0 ; V_55 < V_356 ; V_55 ++ ) {
V_1 -> V_118 -> V_124 [ V_55 ] . V_126 = NULL ;
V_1 -> V_118 -> V_124 [ V_55 ] . V_357 = 0 ;
}
if ( V_1 -> V_118 -> V_305 ) {
if ( ! F_113 ( V_1 ) ) {
F_16 ( V_358 , V_347 ) ;
V_188 = V_301 ;
goto V_353;
}
if ( ! V_1 -> V_118 -> V_122 ) {
F_16 ( V_358 ,
V_359 ) ;
V_188 = V_322 ;
goto V_353;
}
} else
F_114 ( V_1 -> V_118 ) ;
return 1 ;
V_353:
F_103 ( V_1 , V_330 , V_188 ) ;
return 0 ;
}
int F_115 ( T_1 * V_1 )
{
int V_191 = V_282 ;
int V_188 ;
if ( ( V_1 -> V_234 != - 1 ) && V_1 -> V_248 && V_1 -> V_248 -> V_360 ) {
int V_280 ;
T_12 * V_361 ;
V_361 = F_116 ( V_1 ) ;
if ( V_361 == NULL ) {
V_1 -> V_270 = 0 ;
return 1 ;
}
V_1 -> V_118 -> V_362 = V_361 ;
V_280 = V_1 -> V_248 -> V_360 ( V_1 , V_1 -> V_248 -> V_363 ) ;
switch ( V_280 ) {
case V_348 :
V_1 -> V_270 = 0 ;
break;
case V_282 :
if ( V_1 -> V_364 )
V_1 -> V_270 = 1 ;
else
V_1 -> V_270 = 0 ;
break;
case V_352 :
V_191 = V_352 ;
V_188 = V_301 ;
goto V_353;
}
} else
V_1 -> V_270 = 0 ;
V_353:
switch ( V_191 ) {
case V_352 :
F_103 ( V_1 , V_330 , V_188 ) ;
return - 1 ;
case V_354 :
F_103 ( V_1 , V_355 , V_188 ) ;
return 1 ;
default:
return 1 ;
}
}
int F_117 ( T_1 * V_1 )
{
int V_191 = V_348 ;
int V_188 = V_339 ;
# ifndef F_48
unsigned long V_194 = V_1 -> V_59 -> V_60 . V_61 -> V_198 ;
unsigned long V_195 = V_1 -> V_59 -> V_60 . V_61 -> V_199 ;
if ( ( V_1 -> V_108 != NULL )
&& ( V_1 -> V_109 > 0 )
&& ( V_1 -> V_41 -> V_108 != NULL )
&& ( V_1 -> V_41 -> V_109 > 0 )
&& ( ( V_194 & ( V_200 | V_170 | V_174 ) )
|| ( V_195 & V_173 ) ) ) {
T_2 V_55 ;
unsigned char * V_365 ;
int V_366 = 0 ;
V_365 = V_1 -> V_41 -> V_108 ;
for ( V_55 = 0 ; V_55 < V_1 -> V_41 -> V_109 ; V_55 ++ ) {
if ( * ( V_365 ++ ) == V_105 ) {
V_366 = 1 ;
break;
}
}
if ( ! V_366 ) {
F_16 ( V_367 ,
V_368 ) ;
return - 1 ;
}
}
V_191 = V_282 ;
# endif
if ( V_1 -> V_248 != NULL && V_1 -> V_248 -> V_349 != 0 )
V_191 =
V_1 -> V_248 -> V_349 ( V_1 , & V_188 ,
V_1 -> V_248 -> V_350 ) ;
else if ( V_1 -> V_351 != NULL
&& V_1 -> V_351 -> V_349 != 0 )
V_191 =
V_1 -> V_351 -> V_349 ( V_1 , & V_188 ,
V_1 ->
V_351 -> V_350 ) ;
# ifdef F_70
if ( V_1 -> V_59 -> V_273 > 0 ) {
if ( V_1 -> V_59 -> V_271 == NULL ) {
V_191 = V_352 ;
V_188 = V_324 ;
}
if ( V_1 -> V_59 -> V_231 == NULL ||
V_1 -> V_59 -> V_233 !=
V_1 -> V_59 -> V_273 ) {
V_191 = V_352 ;
V_188 = V_322 ;
}
}
# endif
if ( ( V_1 -> V_234 != - 1 ) && ! ( V_1 -> V_270 )
&& V_1 -> V_248 && V_1 -> V_248 -> V_360 ) {
int V_280 ;
if ( V_1 -> V_364 ) {
F_6 ( V_1 -> V_364 ) ;
V_1 -> V_364 = NULL ;
}
V_1 -> V_369 = - 1 ;
V_280 = V_1 -> V_248 -> V_360 ( V_1 , V_1 -> V_248 -> V_363 ) ;
if ( V_280 == 0 ) {
V_188 = V_370 ;
V_191 = V_352 ;
}
if ( V_280 < 0 ) {
V_188 = V_301 ;
V_191 = V_352 ;
}
}
switch ( V_191 ) {
case V_352 :
F_103 ( V_1 , V_330 , V_188 ) ;
return - 1 ;
case V_354 :
F_103 ( V_1 , V_355 , V_188 ) ;
return 1 ;
case V_348 :
V_1 -> V_265 = 0 ;
default:
return 1 ;
}
}
int F_118 ( T_1 * V_1 , unsigned char * * V_52 , unsigned char * V_286 ,
int V_287 )
{
int V_188 = - 1 ;
if ( V_1 -> V_5 < V_202 )
return 1 ;
if ( F_106 ( V_1 , V_52 , V_286 , V_287 , & V_188 ) <= 0 ) {
F_103 ( V_1 , V_330 , V_188 ) ;
return 0 ;
}
if ( F_117 ( V_1 ) <= 0 ) {
F_16 ( V_371 , V_372 ) ;
return 0 ;
}
return 1 ;
}
int F_119 ( T_1 * V_1 , unsigned char * V_373 , int V_53 ,
const unsigned char * V_187 , T_13 * * V_191 )
{
const unsigned char * V_52 = V_373 + V_53 ;
unsigned short V_55 ;
* V_191 = NULL ;
V_1 -> V_269 = 0 ;
if ( F_68 ( V_1 ) & V_219 )
return 0 ;
if ( ( V_1 -> V_5 <= V_202 ) || ! V_187 )
return 0 ;
if ( V_52 >= V_187 )
return - 1 ;
if ( F_62 ( V_1 ) ) {
V_55 = * ( V_52 ++ ) ;
V_52 += V_55 ;
if ( V_52 >= V_187 )
return - 1 ;
}
F_86 ( V_52 , V_55 ) ;
V_52 += V_55 ;
if ( V_52 >= V_187 )
return - 1 ;
V_55 = * ( V_52 ++ ) ;
V_52 += V_55 ;
if ( V_52 > V_187 )
return - 1 ;
if ( ( V_52 + 2 ) >= V_187 )
return 0 ;
F_86 ( V_52 , V_55 ) ;
while ( ( V_52 + 4 ) <= V_187 ) {
unsigned short type , V_288 ;
F_86 ( V_52 , type ) ;
F_86 ( V_52 , V_288 ) ;
if ( V_52 + V_288 > V_187 )
return 0 ;
if ( type == V_227 ) {
int V_280 ;
if ( V_288 == 0 ) {
V_1 -> V_269 = 1 ;
return 1 ;
}
if ( V_1 -> V_374 ) {
return 2 ;
}
V_280 = F_120 ( V_1 , V_52 , V_288 , V_373 , V_53 , V_191 ) ;
switch ( V_280 ) {
case 2 :
V_1 -> V_269 = 1 ;
return 2 ;
case 3 :
return V_280 ;
case 4 :
V_1 -> V_269 = 1 ;
return 3 ;
default:
return - 1 ;
}
}
V_52 += V_288 ;
}
return 0 ;
}
static int F_120 ( T_1 * V_1 , const unsigned char * V_375 ,
int V_376 , const unsigned char * V_377 ,
int V_378 , T_13 * * V_379 )
{
T_13 * V_37 ;
unsigned char * V_380 ;
const unsigned char * V_52 ;
int V_381 , V_382 , V_383 = 0 ;
unsigned char V_384 [ V_385 ] ;
T_14 V_386 ;
T_15 V_248 ;
T_16 * V_387 = V_1 -> V_351 ;
if ( V_376 < 48 )
return 2 ;
F_121 ( & V_386 ) ;
F_122 ( & V_248 ) ;
if ( V_387 -> V_388 ) {
unsigned char * V_389 = ( unsigned char * ) V_375 ;
int V_114 = V_387 -> V_388 ( V_1 , V_389 , V_389 + 16 ,
& V_248 , & V_386 , 0 ) ;
if ( V_114 < 0 )
return - 1 ;
if ( V_114 == 0 )
return 2 ;
if ( V_114 == 2 )
V_383 = 1 ;
} else {
if ( memcmp ( V_375 , V_387 -> V_390 , 16 ) )
return 2 ;
F_123 ( & V_386 , V_387 -> V_391 , 16 ,
F_124 () , NULL ) ;
F_125 ( & V_248 , F_126 () , NULL ,
V_387 -> V_392 , V_375 + 16 ) ;
}
V_382 = F_127 ( & V_386 ) ;
if ( V_382 < 0 ) {
F_128 ( & V_248 ) ;
return - 1 ;
}
V_376 -= V_382 ;
F_129 ( & V_386 , V_375 , V_376 ) ;
F_130 ( & V_386 , V_384 , NULL ) ;
F_131 ( & V_386 ) ;
if ( F_132 ( V_384 , V_375 + V_376 , V_382 ) ) {
F_128 ( & V_248 ) ;
return 2 ;
}
V_52 = V_375 + 16 + F_133 ( & V_248 ) ;
V_376 -= 16 + F_133 ( & V_248 ) ;
V_380 = F_21 ( V_376 ) ;
if ( ! V_380 ) {
F_128 ( & V_248 ) ;
return - 1 ;
}
F_134 ( & V_248 , V_380 , & V_381 , V_52 , V_376 ) ;
if ( F_135 ( & V_248 , V_380 + V_381 , & V_382 ) <= 0 ) {
F_128 ( & V_248 ) ;
F_6 ( V_380 ) ;
return 2 ;
}
V_381 += V_382 ;
F_128 ( & V_248 ) ;
V_52 = V_380 ;
V_37 = F_136 ( NULL , & V_52 , V_381 ) ;
F_6 ( V_380 ) ;
if ( V_37 ) {
if ( V_378 )
memcpy ( V_37 -> V_373 , V_377 , V_378 ) ;
V_37 -> V_393 = V_378 ;
* V_379 = V_37 ;
if ( V_383 )
return 4 ;
else
return 3 ;
}
F_137 () ;
return 2 ;
}
static int F_138 ( int V_8 , T_17 * V_394 , T_2 V_395 )
{
T_2 V_55 ;
for ( V_55 = 0 ; V_55 < V_395 ; V_55 ++ ) {
if ( V_394 [ V_55 ] . V_8 == V_8 )
return V_394 [ V_55 ] . V_62 ;
}
return - 1 ;
}
static int F_139 ( int V_62 , T_17 * V_394 , T_2 V_395 )
{
T_2 V_55 ;
for ( V_55 = 0 ; V_55 < V_395 ; V_55 ++ ) {
if ( ( V_394 [ V_55 ] . V_62 ) == V_62 )
return V_394 [ V_55 ] . V_8 ;
}
return V_75 ;
}
int F_140 ( unsigned char * V_52 , const T_8 * V_396 ,
const T_10 * V_397 )
{
int V_398 , V_399 ;
if ( ! V_397 )
return 0 ;
V_399 = F_138 ( F_141 ( V_397 ) , V_400 ,
sizeof( V_400 ) / sizeof( T_17 ) ) ;
if ( V_399 == - 1 )
return 0 ;
V_398 = F_50 ( V_396 ) ;
if ( V_398 == - 1 )
return 0 ;
V_52 [ 0 ] = ( unsigned char ) V_399 ;
V_52 [ 1 ] = ( unsigned char ) V_398 ;
return 1 ;
}
int F_50 ( const T_8 * V_396 )
{
return F_138 ( V_396 -> type , V_401 ,
sizeof( V_401 ) / sizeof( T_17 ) ) ;
}
const T_10 * F_51 ( unsigned char V_402 )
{
switch ( V_402 ) {
# ifndef F_142
case V_403 :
# ifdef F_14
if ( F_15 () )
return NULL ;
# endif
return F_143 () ;
# endif
# ifndef F_144
case V_151 :
return F_145 () ;
# endif
# ifndef F_146
case V_404 :
return F_147 () ;
case V_148 :
return F_43 () ;
# endif
# ifndef F_148
case V_150 :
return F_44 () ;
case V_405 :
return F_149 () ;
# endif
default:
return NULL ;
}
}
static int F_150 ( unsigned char V_406 )
{
switch ( V_406 ) {
# ifndef F_54
case V_165 :
return V_407 ;
# endif
# ifndef F_55
case V_166 :
return V_408 ;
# endif
# ifndef F_56
case V_167 :
return V_125 ;
# endif
}
return - 1 ;
}
static void F_151 ( int * V_409 , int * V_410 ,
int * V_411 , const unsigned char * V_224 )
{
int V_412 = 0 , V_413 = 0 ;
if ( ! V_409 && ! V_410 && ! V_411 )
return;
if ( V_409 || V_411 ) {
V_413 = F_139 ( V_224 [ 0 ] , V_400 ,
sizeof( V_400 ) / sizeof( T_17 ) ) ;
if ( V_409 )
* V_409 = V_413 ;
}
if ( V_410 || V_411 ) {
V_412 = F_139 ( V_224 [ 1 ] , V_401 ,
sizeof( V_401 ) / sizeof( T_17 ) ) ;
if ( V_410 )
* V_410 = V_412 ;
}
if ( V_411 ) {
if ( V_412 && V_413 )
F_152 ( V_411 , V_413 , V_412 ) ;
else
* V_411 = V_75 ;
}
}
static int F_153 ( T_18 * V_414 ,
const unsigned char * V_68 , T_2 V_415 ,
const unsigned char * V_416 ,
T_2 V_417 )
{
const unsigned char * V_329 , * V_418 ;
T_2 V_55 , V_72 , V_67 = 0 ;
for ( V_55 = 0 , V_329 = V_68 ; V_55 < V_415 ; V_55 += 2 , V_329 += 2 ) {
if ( F_51 ( V_329 [ 0 ] ) == NULL )
continue;
if ( F_150 ( V_329 [ 1 ] ) == - 1 )
continue;
for ( V_72 = 0 , V_418 = V_416 ; V_72 < V_417 ; V_72 += 2 , V_418 += 2 ) {
if ( V_329 [ 0 ] == V_418 [ 0 ] && V_329 [ 1 ] == V_418 [ 1 ] ) {
V_67 ++ ;
if ( V_414 ) {
V_414 -> V_419 = V_329 [ 0 ] ;
V_414 -> V_420 = V_329 [ 1 ] ;
F_151 ( & V_414 -> V_413 ,
& V_414 -> V_412 ,
& V_414 -> V_123 , V_329 ) ;
V_414 ++ ;
}
break;
}
}
}
return V_67 ;
}
static int F_154 ( T_1 * V_1 )
{
const unsigned char * V_68 , * V_416 , * V_421 ;
T_2 V_415 , V_417 , V_422 ;
T_2 V_67 ;
T_18 * V_423 = NULL ;
T_9 * V_117 = V_1 -> V_118 ;
unsigned int V_424 = F_13 ( V_1 ) ;
if ( V_117 -> V_122 ) {
F_6 ( V_117 -> V_122 ) ;
V_117 -> V_122 = NULL ;
}
if ( ! V_1 -> V_74 && V_117 -> V_135 && ! V_424 ) {
V_421 = V_117 -> V_135 ;
V_422 = V_117 -> V_136 ;
} else if ( V_117 -> V_137 && ! V_424 ) {
V_421 = V_117 -> V_137 ;
V_422 = V_117 -> V_138 ;
} else
V_422 = F_47 ( V_1 , & V_421 ) ;
if ( V_1 -> V_76 & V_77 || V_424 ) {
V_68 = V_421 ;
V_415 = V_422 ;
V_416 = V_117 -> V_305 ;
V_417 = V_117 -> V_425 ;
} else {
V_416 = V_421 ;
V_417 = V_422 ;
V_68 = V_117 -> V_305 ;
V_415 = V_117 -> V_425 ;
}
V_67 = F_153 ( NULL , V_68 , V_415 , V_416 , V_417 ) ;
if ( ! V_67 )
return 1 ;
V_423 = F_21 ( V_67 * sizeof( T_18 ) ) ;
if ( ! V_423 )
return 0 ;
V_67 = F_153 ( V_423 , V_68 , V_415 , V_416 , V_417 ) ;
V_117 -> V_122 = V_423 ;
V_117 -> V_121 = V_67 ;
return 1 ;
}
int F_92 ( T_1 * V_1 , const unsigned char * V_224 , int V_311 )
{
T_9 * V_117 = V_1 -> V_118 ;
if ( ! F_69 ( V_1 ) )
return 1 ;
if ( ! V_117 )
return 0 ;
if ( V_117 -> V_305 )
F_6 ( V_117 -> V_305 ) ;
V_117 -> V_305 = F_21 ( V_311 ) ;
if ( ! V_117 -> V_305 )
return 0 ;
V_117 -> V_425 = V_311 ;
memcpy ( V_117 -> V_305 , V_224 , V_311 ) ;
return 1 ;
}
int F_113 ( T_1 * V_1 )
{
int V_426 ;
T_2 V_55 ;
const T_10 * V_397 ;
T_9 * V_117 = V_1 -> V_118 ;
T_18 * V_427 ;
if ( ! F_154 ( V_1 ) )
return 0 ;
# ifdef F_46
if ( V_1 -> V_118 -> V_128 & V_129 ) {
const unsigned char * V_428 = NULL ;
if ( V_1 -> V_74 )
V_428 = V_117 -> V_137 ;
else
V_428 = V_117 -> V_135 ;
if ( V_428 ) {
V_426 = F_150 ( V_428 [ 1 ] ) ;
V_397 = F_51 ( V_428 [ 0 ] ) ;
V_117 -> V_124 [ V_426 ] . V_126 = V_397 ;
V_117 -> V_124 [ V_426 ] . V_357 = V_429 ;
if ( V_426 == V_407 ) {
V_117 -> V_124 [ V_430 ] . V_357 =
V_429 ;
V_117 -> V_124 [ V_430 ] . V_126 = V_397 ;
}
}
}
# endif
for ( V_55 = 0 , V_427 = V_117 -> V_122 ;
V_55 < V_117 -> V_121 ; V_55 ++ , V_427 ++ ) {
V_426 = F_150 ( V_427 -> V_420 ) ;
if ( V_426 > 0 && V_117 -> V_124 [ V_426 ] . V_126 == NULL ) {
V_397 = F_51 ( V_427 -> V_419 ) ;
V_117 -> V_124 [ V_426 ] . V_126 = V_397 ;
V_117 -> V_124 [ V_426 ] . V_357 = V_429 ;
if ( V_426 == V_407 ) {
V_117 -> V_124 [ V_430 ] . V_357 =
V_429 ;
V_117 -> V_124 [ V_430 ] . V_126 = V_397 ;
}
}
}
if ( ! ( V_1 -> V_118 -> V_128 & V_152 ) ) {
# ifndef F_55
if ( ! V_117 -> V_124 [ V_408 ] . V_126 )
V_117 -> V_124 [ V_408 ] . V_126 = F_145 () ;
# endif
# ifndef F_54
if ( ! V_117 -> V_124 [ V_407 ] . V_126 ) {
V_117 -> V_124 [ V_407 ] . V_126 = F_145 () ;
V_117 -> V_124 [ V_430 ] . V_126 = F_145 () ;
}
# endif
# ifndef F_56
if ( ! V_117 -> V_124 [ V_125 ] . V_126 )
V_117 -> V_124 [ V_125 ] . V_126 = F_145 () ;
# endif
}
return 1 ;
}
int F_155 ( T_1 * V_1 , int V_426 ,
int * V_431 , int * V_432 , int * V_433 ,
unsigned char * V_434 , unsigned char * V_419 )
{
const unsigned char * V_435 = V_1 -> V_118 -> V_305 ;
if ( V_435 == NULL )
return 0 ;
if ( V_426 >= 0 ) {
V_426 <<= 1 ;
if ( V_426 >= ( int ) V_1 -> V_118 -> V_425 )
return 0 ;
V_435 += V_426 ;
if ( V_419 )
* V_419 = V_435 [ 0 ] ;
if ( V_434 )
* V_434 = V_435 [ 1 ] ;
F_151 ( V_432 , V_431 , V_433 , V_435 ) ;
}
return V_1 -> V_118 -> V_425 / 2 ;
}
int F_156 ( T_1 * V_1 , int V_426 ,
int * V_431 , int * V_432 , int * V_433 ,
unsigned char * V_434 , unsigned char * V_419 )
{
T_18 * V_436 = V_1 -> V_118 -> V_122 ;
if ( ! V_436 || V_426 >= ( int ) V_1 -> V_118 -> V_121 )
return 0 ;
V_436 += V_426 ;
if ( V_432 )
* V_432 = V_436 -> V_413 ;
if ( V_431 )
* V_431 = V_436 -> V_412 ;
if ( V_433 )
* V_433 = V_436 -> V_123 ;
if ( V_434 )
* V_434 = V_436 -> V_420 ;
if ( V_419 )
* V_419 = V_436 -> V_419 ;
return V_1 -> V_118 -> V_121 ;
}
int F_157 ( T_1 * V_1 )
{
unsigned char * V_52 = & V_1 -> V_59 -> V_437 . V_224 [ 0 ] , * V_438 ;
unsigned short V_439 ;
unsigned int V_440 ;
unsigned int V_441 = 16 ;
if ( V_1 -> V_442 )
V_1 -> V_442 ( 0 , V_1 -> V_5 , V_443 ,
& V_1 -> V_59 -> V_437 . V_224 [ 0 ] , V_1 -> V_59 -> V_437 . V_225 ,
V_1 , V_1 -> V_444 ) ;
if ( 1 + 2 + 16 > V_1 -> V_59 -> V_437 . V_225 )
return 0 ;
V_439 = * V_52 ++ ;
F_86 ( V_52 , V_440 ) ;
if ( 1 + 2 + V_440 + 16 > V_1 -> V_59 -> V_437 . V_225 )
return 0 ;
V_438 = V_52 ;
if ( V_439 == V_445 ) {
unsigned char * V_446 , * V_447 ;
int V_280 ;
V_446 = F_21 ( 1 + 2 + V_440 + V_441 ) ;
V_447 = V_446 ;
* V_447 ++ = V_448 ;
F_26 ( V_440 , V_447 ) ;
memcpy ( V_447 , V_438 , V_440 ) ;
V_447 += V_440 ;
F_158 ( V_447 , V_441 ) ;
V_280 = F_159 ( V_1 , V_443 , V_446 ,
3 + V_440 + V_441 ) ;
if ( V_280 >= 0 && V_1 -> V_442 )
V_1 -> V_442 ( 1 , V_1 -> V_5 , V_443 ,
V_446 , 3 + V_440 + V_441 ,
V_1 , V_1 -> V_444 ) ;
F_6 ( V_446 ) ;
if ( V_280 < 0 )
return V_280 ;
} else if ( V_439 == V_448 ) {
unsigned int V_449 ;
F_86 ( V_438 , V_449 ) ;
if ( V_440 == 18 && V_449 == V_1 -> V_450 ) {
V_1 -> V_450 ++ ;
V_1 -> V_451 = 0 ;
}
}
return 0 ;
}
int F_160 ( T_1 * V_1 )
{
unsigned char * V_186 , * V_52 ;
int V_191 ;
unsigned int V_440 = 18 ;
unsigned int V_441 = 16 ;
if ( ! ( V_1 -> V_244 & V_247 ) ||
V_1 -> V_244 & V_246 ) {
F_16 ( V_452 , V_453 ) ;
return - 1 ;
}
if ( V_1 -> V_451 ) {
F_16 ( V_452 , V_454 ) ;
return - 1 ;
}
if ( F_161 ( V_1 ) || V_1 -> V_455 ) {
F_16 ( V_452 , V_456 ) ;
return - 1 ;
}
F_162 ( V_440 + V_441 <= 16381 ) ;
V_186 = F_21 ( 1 + 2 + V_440 + V_441 ) ;
V_52 = V_186 ;
* V_52 ++ = V_445 ;
F_26 ( V_440 , V_52 ) ;
F_26 ( V_1 -> V_450 , V_52 ) ;
F_158 ( V_52 , 16 ) ;
V_52 += 16 ;
F_158 ( V_52 , V_441 ) ;
V_191 = F_159 ( V_1 , V_443 , V_186 , 3 + V_440 + V_441 ) ;
if ( V_191 >= 0 ) {
if ( V_1 -> V_442 )
V_1 -> V_442 ( 1 , V_1 -> V_5 , V_443 ,
V_186 , 3 + V_440 + V_441 ,
V_1 , V_1 -> V_444 ) ;
V_1 -> V_451 = 1 ;
}
F_6 ( V_186 ) ;
return V_191 ;
}
static int F_163 ( const char * V_87 , int V_53 , void * V_88 )
{
T_19 * V_457 = V_88 ;
T_2 V_55 ;
char V_90 [ 20 ] , * V_52 ;
int V_406 , V_402 ;
if ( V_457 -> V_458 == V_459 )
return 0 ;
if ( V_53 > ( int ) ( sizeof( V_90 ) - 1 ) )
return 0 ;
memcpy ( V_90 , V_87 , V_53 ) ;
V_90 [ V_53 ] = 0 ;
V_52 = strchr ( V_90 , '+' ) ;
if ( ! V_52 )
return 0 ;
* V_52 = 0 ;
V_52 ++ ;
if ( ! * V_52 )
return 0 ;
if ( ! strcmp ( V_90 , L_1 ) )
V_406 = V_460 ;
else if ( ! strcmp ( V_90 , L_2 ) )
V_406 = V_461 ;
else if ( ! strcmp ( V_90 , L_3 ) )
V_406 = V_115 ;
else
return 0 ;
V_402 = F_29 ( V_52 ) ;
if ( V_402 == V_75 )
V_402 = F_30 ( V_52 ) ;
if ( V_402 == V_75 )
return 0 ;
for ( V_55 = 0 ; V_55 < V_457 -> V_458 ; V_55 += 2 ) {
if ( V_457 -> V_156 [ V_55 ] == V_406 && V_457 -> V_156 [ V_55 + 1 ] == V_402 )
return 0 ;
}
V_457 -> V_156 [ V_457 -> V_458 ++ ] = V_402 ;
V_457 -> V_156 [ V_457 -> V_458 ++ ] = V_406 ;
return 1 ;
}
int F_164 ( T_9 * V_117 , const char * V_94 , int V_462 )
{
T_19 V_141 ;
V_141 . V_458 = 0 ;
if ( ! F_32 ( V_94 , ':' , 1 , F_163 , & V_141 ) )
return 0 ;
if ( V_117 == NULL )
return 1 ;
return F_165 ( V_117 , V_141 . V_156 , V_141 . V_458 , V_462 ) ;
}
int F_165 ( T_9 * V_117 , const int * V_463 , T_2 V_228 ,
int V_462 )
{
unsigned char * V_156 , * V_464 ;
int V_419 , V_420 ;
T_2 V_55 ;
if ( V_228 & 1 )
return 0 ;
V_156 = F_21 ( V_228 ) ;
if ( V_156 == NULL )
return 0 ;
for ( V_55 = 0 , V_464 = V_156 ; V_55 < V_228 ; V_55 += 2 ) {
V_419 = F_138 ( * V_463 ++ , V_400 ,
sizeof( V_400 ) / sizeof( T_17 ) ) ;
V_420 = F_138 ( * V_463 ++ , V_401 ,
sizeof( V_401 ) / sizeof( T_17 ) ) ;
if ( V_419 == - 1 || V_420 == - 1 )
goto V_353;
* V_464 ++ = V_419 ;
* V_464 ++ = V_420 ;
}
if ( V_462 ) {
if ( V_117 -> V_135 )
F_6 ( V_117 -> V_135 ) ;
V_117 -> V_135 = V_156 ;
V_117 -> V_136 = V_228 ;
} else {
if ( V_117 -> V_137 )
F_6 ( V_117 -> V_137 ) ;
V_117 -> V_137 = V_156 ;
V_117 -> V_138 = V_228 ;
}
return 1 ;
V_353:
F_6 ( V_156 ) ;
return 0 ;
}
static int F_166 ( T_9 * V_117 , T_7 * V_111 , int V_465 )
{
int V_466 ;
T_2 V_55 ;
if ( V_465 == - 1 )
return 1 ;
V_466 = F_167 ( V_111 ) ;
if ( V_465 )
return V_466 == V_465 ? 1 : 0 ;
for ( V_55 = 0 ; V_55 < V_117 -> V_121 ; V_55 ++ )
if ( V_466 == V_117 -> V_122 [ V_55 ] . V_123 )
return 1 ;
return 0 ;
}
void F_168 ( T_1 * V_1 )
{
F_169 ( V_1 , NULL , NULL , NULL , V_430 ) ;
F_169 ( V_1 , NULL , NULL , NULL , V_407 ) ;
F_169 ( V_1 , NULL , NULL , NULL , V_408 ) ;
F_169 ( V_1 , NULL , NULL , NULL , V_467 ) ;
F_169 ( V_1 , NULL , NULL , NULL , V_468 ) ;
F_169 ( V_1 , NULL , NULL , NULL , V_125 ) ;
}

long F_1 ( void )
{
return ( 60 * 60 * 2 ) ;
}
int F_2 ( void )
{
return ( V_1 ) ;
}
const T_1 * F_3 ( unsigned int V_2 )
{
if ( V_2 < V_1 )
return ( & ( V_3 [ V_1 - 1 - V_2 ] ) ) ;
else
return ( NULL ) ;
}
int F_4 ( const T_2 * V_4 )
{
if ( V_4 -> V_5 == V_6 )
return 0 ;
return ( V_4 -> V_7 -> V_8 . type ==
V_9 ) ? V_4 -> V_7 -> V_8 . V_10 : 0 ;
}
void F_5 ( T_2 * V_4 , int V_11 , unsigned long V_12 )
{
unsigned char * V_13 = ( unsigned char * ) V_4 -> V_14 -> V_15 ;
* ( V_13 ++ ) = V_11 ;
F_6 ( V_12 , V_13 ) ;
V_4 -> V_16 = ( int ) V_12 + V_17 ;
V_4 -> V_18 = 0 ;
}
int F_7 ( T_2 * V_4 )
{
return F_8 ( V_4 , V_19 ) ;
}
int F_9 ( T_2 * V_4 )
{
T_3 * V_7 ;
if ( ( V_7 = F_10 ( sizeof *V_7 ) ) == NULL )
goto V_20;
memset ( V_7 , 0 , sizeof *V_7 ) ;
memset ( V_7 -> V_8 . V_21 , 0 , sizeof( V_7 -> V_8 . V_21 ) ) ;
memset ( V_7 -> V_22 . V_21 , 0 , sizeof( V_7 -> V_22 . V_21 ) ) ;
V_4 -> V_7 = V_7 ;
#ifndef F_11
F_12 ( V_4 ) ;
#endif
V_4 -> V_23 -> V_24 ( V_4 ) ;
return ( 1 ) ;
V_20:
return ( 0 ) ;
}
void F_13 ( T_2 * V_4 )
{
if ( V_4 == NULL )
return;
#ifdef F_14
if ( V_4 -> V_7 -> V_25 != NULL )
F_15 ( V_4 -> V_7 -> V_25 ) ;
if ( V_4 -> V_7 -> V_26 != NULL )
F_15 ( V_4 -> V_7 -> V_26 ) ;
#endif
F_16 ( V_4 ) ;
if ( V_4 -> V_7 -> V_27 . V_28 != NULL )
F_17 ( V_4 ) ;
if ( V_4 -> V_7 -> V_29 . V_28 != NULL )
F_18 ( V_4 ) ;
if ( V_4 -> V_7 -> V_8 . V_30 != NULL )
F_15 ( V_4 -> V_7 -> V_8 . V_30 ) ;
#ifndef F_19
if ( V_4 -> V_7 -> V_31 . V_32 != NULL )
F_20 ( V_4 -> V_7 -> V_31 . V_32 ) ;
#endif
#ifndef F_21
if ( V_4 -> V_7 -> V_31 . V_33 != NULL )
F_22 ( V_4 -> V_7 -> V_31 . V_33 ) ;
#endif
if ( V_4 -> V_7 -> V_31 . V_34 != NULL )
F_23 ( V_4 -> V_7 -> V_31 . V_34 , V_35 ) ;
if ( V_4 -> V_7 -> V_36 ) {
F_24 ( V_4 -> V_7 -> V_36 ) ;
}
if ( V_4 -> V_7 -> V_37 )
F_25 ( V_4 ) ;
#ifndef F_26
if ( V_4 -> V_7 -> V_38 )
F_15 ( V_4 -> V_7 -> V_38 ) ;
#endif
#ifndef F_11
F_27 ( V_4 ) ;
#endif
F_28 ( V_4 -> V_7 , sizeof * V_4 -> V_7 ) ;
F_15 ( V_4 -> V_7 ) ;
V_4 -> V_7 = NULL ;
}
void F_29 ( T_2 * V_4 )
{
unsigned char * V_39 , * V_40 ;
T_4 V_41 , V_42 ;
int V_43 ;
#ifdef F_14
if ( V_4 -> V_7 -> V_25 != NULL )
F_15 ( V_4 -> V_7 -> V_25 ) ;
V_4 -> V_7 -> V_25 = NULL ;
if ( V_4 -> V_7 -> V_26 != NULL )
F_15 ( V_4 -> V_7 -> V_26 ) ;
V_4 -> V_7 -> V_26 = NULL ;
#endif
F_16 ( V_4 ) ;
if ( V_4 -> V_7 -> V_31 . V_34 != NULL )
F_23 ( V_4 -> V_7 -> V_31 . V_34 , V_35 ) ;
if ( V_4 -> V_7 -> V_8 . V_30 != NULL ) {
F_15 ( V_4 -> V_7 -> V_8 . V_30 ) ;
V_4 -> V_7 -> V_8 . V_30 = NULL ;
}
#ifndef F_19
if ( V_4 -> V_7 -> V_31 . V_32 != NULL ) {
F_20 ( V_4 -> V_7 -> V_31 . V_32 ) ;
V_4 -> V_7 -> V_31 . V_32 = NULL ;
}
#endif
#ifndef F_21
if ( V_4 -> V_7 -> V_31 . V_33 != NULL ) {
F_22 ( V_4 -> V_7 -> V_31 . V_33 ) ;
V_4 -> V_7 -> V_31 . V_33 = NULL ;
}
#endif
#ifndef F_26
# ifndef F_30
V_4 -> V_7 -> V_44 = 0 ;
# endif
#endif
V_39 = V_4 -> V_7 -> V_27 . V_28 ;
V_40 = V_4 -> V_7 -> V_29 . V_28 ;
V_41 = V_4 -> V_7 -> V_27 . V_12 ;
V_42 = V_4 -> V_7 -> V_29 . V_12 ;
V_43 = V_4 -> V_7 -> V_43 ;
if ( V_4 -> V_7 -> V_36 ) {
F_24 ( V_4 -> V_7 -> V_36 ) ;
V_4 -> V_7 -> V_36 = NULL ;
}
if ( V_4 -> V_7 -> V_37 ) {
F_25 ( V_4 ) ;
}
#if ! F_31 ( F_26 )
if ( V_4 -> V_7 -> V_38 ) {
free ( V_4 -> V_7 -> V_38 ) ;
V_4 -> V_7 -> V_38 = NULL ;
}
#endif
memset ( V_4 -> V_7 , 0 , sizeof * V_4 -> V_7 ) ;
V_4 -> V_7 -> V_27 . V_28 = V_39 ;
V_4 -> V_7 -> V_29 . V_28 = V_40 ;
V_4 -> V_7 -> V_27 . V_12 = V_41 ;
V_4 -> V_7 -> V_29 . V_12 = V_42 ;
V_4 -> V_7 -> V_43 = V_43 ;
F_32 ( V_4 ) ;
V_4 -> V_45 = 0 ;
V_4 -> V_7 -> V_46 = 0 ;
V_4 -> V_7 -> V_47 = 0 ;
V_4 -> V_7 -> V_48 = 0 ;
V_4 -> V_7 -> V_49 = 0 ;
V_4 -> V_50 = V_51 ;
#if ! F_31 ( F_26 ) && ! F_31 ( V_52 )
if ( V_4 -> V_53 ) {
F_15 ( V_4 -> V_53 ) ;
V_4 -> V_53 = NULL ;
V_4 -> V_54 = 0 ;
}
#endif
}
static char * T_5 F_33 ( T_2 * V_4 , void * V_55 )
{
return F_34 ( V_4 -> V_56 . V_57 ) ;
}
long F_35 ( T_2 * V_4 , int V_58 , long V_59 , void * V_60 )
{
int V_61 = 0 ;
#if ! F_31 ( V_62 ) || ! F_31 ( V_63 )
if (
# ifndef V_63
V_58 == V_64 || V_58 == V_65 ||
# endif
# ifndef V_62
V_58 == V_66 || V_58 == V_67 ||
# endif
0 ) {
if ( ! F_36 ( & V_4 -> V_68 ) ) {
F_37 ( V_69 , V_70 ) ;
return ( 0 ) ;
}
}
#endif
switch ( V_58 ) {
case V_71 :
V_61 = V_4 -> V_72 ;
break;
case V_73 :
break;
case V_74 :
V_61 = V_4 -> V_7 -> V_48 ;
break;
case V_75 :
V_61 = V_4 -> V_7 -> V_48 ;
V_4 -> V_7 -> V_48 = 0 ;
break;
case V_76 :
V_61 = V_4 -> V_7 -> V_47 ;
break;
case V_77 :
V_61 = ( int ) ( V_4 -> V_7 -> V_78 ) ;
break;
#ifndef V_63
case V_79 :
if ( ( V_4 -> V_68 != NULL ) && ( V_4 -> V_68 -> V_80 == NULL ) &&
( ( V_4 -> V_68 -> V_81 [ V_82 ] . V_83 == NULL ) ||
( F_38 ( V_4 -> V_68 -> V_81 [ V_82 ] . V_83 ) >
( 512 / 8 ) ) ) )
V_61 = 1 ;
break;
case V_64 :
{
T_6 * V_84 = ( T_6 * ) V_60 ;
if ( V_84 == NULL ) {
F_37 ( V_69 , V_85 ) ;
return ( V_61 ) ;
}
if ( ( V_84 = F_39 ( V_84 ) ) == NULL ) {
F_37 ( V_69 , V_86 ) ;
return ( V_61 ) ;
}
if ( V_4 -> V_68 -> V_80 != NULL )
F_40 ( V_4 -> V_68 -> V_80 ) ;
V_4 -> V_68 -> V_80 = V_84 ;
V_61 = 1 ;
}
break;
case V_65 :
{
F_37 ( V_69 , V_87 ) ;
return ( V_61 ) ;
}
break;
#endif
#ifndef F_19
case V_66 :
{
T_7 * V_32 = ( T_7 * ) V_60 ;
if ( V_32 == NULL ) {
F_37 ( V_69 , V_85 ) ;
return ( V_61 ) ;
}
if ( ( V_32 = F_41 ( V_32 ) ) == NULL ) {
F_37 ( V_69 , V_88 ) ;
return ( V_61 ) ;
}
if ( ! ( V_4 -> V_89 & V_90 ) ) {
if ( ! F_42 ( V_32 ) ) {
F_20 ( V_32 ) ;
F_37 ( V_69 , V_88 ) ;
return ( V_61 ) ;
}
}
if ( V_4 -> V_68 -> V_91 != NULL )
F_20 ( V_4 -> V_68 -> V_91 ) ;
V_4 -> V_68 -> V_91 = V_32 ;
V_61 = 1 ;
}
break;
case V_67 :
{
F_37 ( V_69 , V_87 ) ;
return ( V_61 ) ;
}
break;
#endif
#ifndef F_21
case V_92 :
{
T_8 * V_33 = NULL ;
if ( V_60 == NULL ) {
F_37 ( V_69 , V_85 ) ;
return ( V_61 ) ;
}
if ( ! F_43 ( ( T_8 * ) V_60 ) ) {
F_37 ( V_69 , V_93 ) ;
return ( V_61 ) ;
}
V_33 = ( T_8 * ) V_60 ;
if ( ! ( V_4 -> V_89 & V_94 ) ) {
if ( ! F_44 ( V_33 ) ) {
F_22 ( V_33 ) ;
F_37 ( V_69 , V_93 ) ;
return ( V_61 ) ;
}
}
if ( V_4 -> V_68 -> V_95 != NULL )
F_22 ( V_4 -> V_68 -> V_95 ) ;
V_4 -> V_68 -> V_95 = V_33 ;
V_61 = 1 ;
}
break;
case V_96 :
{
F_37 ( V_69 , V_87 ) ;
return ( V_61 ) ;
}
break;
#endif
#ifndef F_26
case V_97 :
if ( V_59 == V_98 ) {
if ( V_4 -> V_99 != NULL )
F_15 ( V_4 -> V_99 ) ;
V_4 -> V_99 = NULL ;
V_61 = 1 ;
if ( V_60 == NULL )
break;
if ( strlen ( ( char * ) V_60 ) > V_100 ) {
F_37 ( V_69 , V_101 ) ;
return 0 ;
}
if ( ( V_4 -> V_99 = F_34 ( ( char * ) V_60 ) ) == NULL ) {
F_37 ( V_69 , V_102 ) ;
return 0 ;
}
} else {
F_37 ( V_69 , V_103 ) ;
return 0 ;
}
break;
case V_104 :
V_4 -> V_105 = V_60 ;
V_61 = 1 ;
break;
# ifdef F_14
case V_106 :
if ( V_59 > 12288 ) {
F_37 ( V_69 , V_107 ) ;
break;
}
if ( V_4 -> V_108 != NULL )
F_15 ( V_4 -> V_108 ) ;
if ( ( T_4 ) V_59 == 0 )
V_4 -> V_108 = F_10 ( 1 ) ;
else
V_4 -> V_108 = F_45 ( V_60 , ( T_4 ) V_59 ) ;
if ( V_4 -> V_108 != NULL ) {
V_4 -> V_109 = ( T_4 ) V_59 ;
V_61 = 1 ;
} else
V_4 -> V_109 = 0 ;
break;
# endif
case V_110 :
V_4 -> V_111 = V_59 ;
V_61 = 1 ;
break;
case V_112 :
* ( F_46 ( V_113 ) * * ) V_60 = V_4 -> V_114 ;
V_61 = 1 ;
break;
case V_115 :
V_4 -> V_114 = V_60 ;
V_61 = 1 ;
break;
case V_116 :
* ( F_46 ( V_117 ) * * ) V_60 = V_4 -> V_118 ;
V_61 = 1 ;
break;
case V_119 :
V_4 -> V_118 = V_60 ;
V_61 = 1 ;
break;
case V_120 :
* ( unsigned char * * ) V_60 = V_4 -> V_121 ;
return V_4 -> V_122 ;
case V_123 :
if ( V_4 -> V_121 )
F_15 ( V_4 -> V_121 ) ;
V_4 -> V_121 = V_60 ;
V_4 -> V_122 = V_59 ;
V_61 = 1 ;
break;
# ifndef F_47
case V_124 :
if ( F_48 ( V_4 ) )
V_61 = F_49 ( V_4 ) ;
else
V_61 = F_50 ( V_4 ) ;
break;
case V_125 :
V_61 = V_4 -> V_126 ;
break;
case V_127 :
if ( V_59 )
V_4 -> V_128 |= V_129 ;
else
V_4 -> V_128 &= ~ V_129 ;
V_61 = 1 ;
break;
# endif
#endif
case V_130 :
if ( V_59 )
return F_51 ( V_4 -> V_68 , ( F_46 ( V_131 ) * ) V_60 ) ;
else
return F_52 ( V_4 -> V_68 , ( F_46 ( V_131 ) * ) V_60 ) ;
case V_132 :
if ( V_59 )
return F_53 ( V_4 -> V_68 , ( V_131 * ) V_60 ) ;
else
return F_54 ( V_4 -> V_68 , ( V_131 * ) V_60 ) ;
case V_133 :
* ( F_46 ( V_131 ) * * ) V_60 = V_4 -> V_68 -> V_134 -> V_135 ;
break;
case V_136 :
return F_55 ( V_4 -> V_68 , ( V_131 * ) V_60 ) ;
case V_137 :
if ( V_59 == V_138 ) {
T_9 * V_139 ;
const T_1 * V_140 ;
if ( ! V_4 -> V_141 )
return 0 ;
V_140 = V_4 -> V_7 -> V_31 . V_142 ;
if ( ! V_140 )
return 0 ;
if ( V_140 -> V_143 & ( V_144 | V_145 ) )
return 2 ;
V_139 = F_56 ( V_4 ) ;
if ( ! V_139 )
return 0 ;
V_4 -> V_68 -> V_134 = V_139 ;
return 1 ;
}
return F_57 ( V_4 -> V_68 , V_59 ) ;
#ifndef F_30
case V_146 :
{
unsigned char * V_147 ;
T_4 V_148 ;
if ( ! V_4 -> V_149 )
return 0 ;
V_147 = V_4 -> V_149 -> V_150 ;
V_148 = V_4 -> V_149 -> V_151 / 2 ;
if ( V_60 ) {
T_4 V_152 ;
int * V_153 = V_60 ;
unsigned int V_154 , V_155 ;
for ( V_152 = 0 ; V_152 < V_148 ; V_152 ++ ) {
F_58 ( V_147 , V_154 ) ;
V_155 = F_59 ( V_154 ) ;
if ( V_155 != 0 )
V_153 [ V_152 ] = V_155 ;
else
V_153 [ V_152 ] = V_156 | V_154 ;
}
}
return ( int ) V_148 ;
}
case V_157 :
return F_60 ( & V_4 -> V_150 ,
& V_4 -> V_151 ,
V_60 , V_59 ) ;
case V_158 :
return F_61 ( & V_4 -> V_150 ,
& V_4 -> V_151 ,
V_60 ) ;
case V_159 :
return F_62 ( V_4 , V_59 ) ;
# ifndef F_21
case V_160 :
V_4 -> V_68 -> V_161 = V_59 ;
return 1 ;
# endif
#endif
case V_162 :
return F_63 ( V_4 -> V_68 , V_60 , V_59 , 0 ) ;
case V_163 :
return F_64 ( V_4 -> V_68 , V_60 , 0 ) ;
case V_164 :
return F_63 ( V_4 -> V_68 , V_60 , V_59 , 1 ) ;
case V_165 :
return F_64 ( V_4 -> V_68 , V_60 , 1 ) ;
case V_166 :
{
const unsigned char * * V_167 = V_60 ;
if ( V_4 -> V_141 || ! V_4 -> V_7 -> V_31 . V_168 )
return 0 ;
if ( V_4 -> V_68 -> V_169 ) {
if ( V_167 )
* V_167 = V_4 -> V_68 -> V_169 ;
return ( int ) V_4 -> V_68 -> V_170 ;
}
if ( V_167 )
* V_167 = ( unsigned char * ) V_4 -> V_7 -> V_31 . V_171 ;
return V_4 -> V_7 -> V_31 . V_170 ;
}
case V_172 :
if ( ! V_4 -> V_141 )
return 0 ;
return F_65 ( V_4 -> V_68 , V_60 , V_59 ) ;
case V_173 :
return F_66 ( V_4 -> V_68 , V_4 -> V_174 -> V_175 , V_59 ) ;
case V_176 :
return F_67 ( V_4 -> V_68 , V_60 , 0 , V_59 ) ;
case V_177 :
return F_67 ( V_4 -> V_68 , V_60 , 1 , V_59 ) ;
case V_178 :
if ( F_68 ( V_4 ) ) {
if ( V_4 -> V_149 && V_4 -> V_149 -> V_179 ) {
const T_10 * V_180 ;
V_180 = V_4 -> V_149 -> V_179 -> V_181 -> V_182 ;
if ( V_180 ) {
* ( int * ) V_60 = F_69 ( V_180 ) ;
return 1 ;
}
}
return 0 ;
}
else
return 0 ;
case V_183 :
if ( V_4 -> V_141 || ! V_4 -> V_149 || ! V_4 -> V_149 -> V_179 )
return 0 ;
else {
T_11 * V_184 ;
T_12 * V_185 ;
int V_186 = 0 ;
V_184 = V_4 -> V_149 -> V_179 ;
#if ! F_31 ( V_63 ) && ! F_31 ( F_19 ) && ! F_31 ( F_30 ) && ! F_31 ( F_21 )
if ( ! V_184 -> V_187 && ! V_184 -> V_188 && ! V_184 -> V_189 )
return 0 ;
#endif
V_185 = F_70 () ;
if ( ! V_185 )
return 0 ;
if ( 0 ) ;
#ifndef V_63
else if ( V_184 -> V_187 )
V_186 = F_71 ( V_185 , V_184 -> V_187 ) ;
#endif
#ifndef F_19
else if ( V_184 -> V_188 )
V_186 = F_72 ( V_185 , V_184 -> V_188 ) ;
#endif
#ifndef F_21
else if ( V_184 -> V_189 )
V_186 = F_73 ( V_185 , V_184 -> V_189 ) ;
#endif
if ( V_186 ) {
* ( T_12 * * ) V_60 = V_185 ;
return 1 ;
}
F_74 ( V_185 ) ;
return 0 ;
}
#ifndef F_30
case V_190 :
{
T_13 * V_191 = V_4 -> V_149 ;
const unsigned char * * V_192 = V_60 ;
if ( ! V_191 || ! V_191 -> V_193 )
return 0 ;
* V_192 = V_191 -> V_193 ;
return ( int ) V_191 -> V_194 ;
}
#endif
case V_195 :
if ( V_4 -> V_50 == V_4 -> V_174 -> V_23 -> V_50 )
return 1 ;
if ( V_4 -> V_174 -> V_23 -> V_50 == F_75 () -> V_50 ) {
#if V_196 != V_197
# error Code needs update for SSLv23_method() support beyond TLS1_2_VERSION.
#endif
if ( ! ( V_4 -> V_89 & V_198 ) )
return V_4 -> V_50 == V_197 ;
if ( ! ( V_4 -> V_89 & V_199 ) )
return V_4 -> V_50 == V_200 ;
if ( ! ( V_4 -> V_89 & V_201 ) )
return V_4 -> V_50 == V_202 ;
if ( ! ( V_4 -> V_89 & V_203 ) )
return V_4 -> V_50 == V_51 ;
if ( ! ( V_4 -> V_89 & V_204 ) )
return V_4 -> V_50 == V_205 ;
}
return 0 ;
default:
break;
}
return ( V_61 ) ;
}
long F_76 ( T_2 * V_4 , int V_58 , void (* F_77) ( void ) )
{
int V_61 = 0 ;
#if ! F_31 ( V_62 ) || ! F_31 ( V_63 )
if (
# ifndef V_63
V_58 == V_65 ||
# endif
# ifndef V_62
V_58 == V_67 ||
# endif
0 ) {
if ( ! F_36 ( & V_4 -> V_68 ) ) {
F_37 ( V_206 , V_70 ) ;
return ( 0 ) ;
}
}
#endif
switch ( V_58 ) {
#ifndef V_63
case V_65 :
{
V_4 -> V_68 -> V_207 = ( T_6 * (*)( T_2 * , int , int ) ) F_77 ;
}
break;
#endif
#ifndef F_19
case V_67 :
{
V_4 -> V_68 -> V_208 = ( T_7 * (*)( T_2 * , int , int ) ) F_77 ;
}
break;
#endif
#ifndef F_21
case V_96 :
{
V_4 -> V_68 -> V_209 = ( T_8 * (*)( T_2 * , int , int ) ) F_77 ;
}
break;
#endif
#ifndef F_26
case V_210 :
V_4 -> V_211 = ( void (*) ( T_2 * , int , int ,
unsigned char * , int , void * ) ) F_77 ;
break;
#endif
default:
break;
}
return ( V_61 ) ;
}
long F_78 ( T_14 * V_174 , int V_58 , long V_59 , void * V_60 )
{
T_15 * V_68 ;
V_68 = V_174 -> V_68 ;
switch ( V_58 ) {
#ifndef V_63
case V_79 :
if ( ( V_68 -> V_80 == NULL ) &&
( ( V_68 -> V_81 [ V_82 ] . V_83 == NULL ) ||
( F_38 ( V_68 -> V_81 [ V_82 ] . V_83 ) >
( 512 / 8 ) ) )
)
return ( 1 ) ;
else
return ( 0 ) ;
case V_64 :
{
T_6 * V_84 ;
int V_152 ;
V_84 = ( T_6 * ) V_60 ;
V_152 = 1 ;
if ( V_84 == NULL )
V_152 = 0 ;
else {
if ( ( V_84 = F_39 ( V_84 ) ) == NULL )
V_152 = 0 ;
}
if ( ! V_152 ) {
F_37 ( V_212 , V_86 ) ;
return ( 0 ) ;
} else {
if ( V_68 -> V_80 != NULL )
F_40 ( V_68 -> V_80 ) ;
V_68 -> V_80 = V_84 ;
return ( 1 ) ;
}
}
case V_65 :
{
F_37 ( V_212 , V_87 ) ;
return ( 0 ) ;
}
break;
#endif
#ifndef F_19
case V_66 :
{
T_7 * V_213 = NULL , * V_32 ;
V_32 = ( T_7 * ) V_60 ;
if ( ( V_213 = F_41 ( V_32 ) ) == NULL ) {
F_37 ( V_212 , V_88 ) ;
return 0 ;
}
if ( ! ( V_174 -> V_89 & V_90 ) ) {
if ( ! F_42 ( V_213 ) ) {
F_37 ( V_212 , V_88 ) ;
F_20 ( V_213 ) ;
return 0 ;
}
}
if ( V_68 -> V_91 != NULL )
F_20 ( V_68 -> V_91 ) ;
V_68 -> V_91 = V_213 ;
return 1 ;
}
case V_67 :
{
F_37 ( V_212 , V_87 ) ;
return ( 0 ) ;
}
break;
#endif
#ifndef F_21
case V_92 :
{
T_8 * V_33 = NULL ;
if ( V_60 == NULL ) {
F_37 ( V_212 , V_93 ) ;
return 0 ;
}
V_33 = F_79 ( ( T_8 * ) V_60 ) ;
if ( V_33 == NULL ) {
F_37 ( V_212 , V_214 ) ;
return 0 ;
}
if ( ! ( V_174 -> V_89 & V_94 ) ) {
if ( ! F_44 ( V_33 ) ) {
F_22 ( V_33 ) ;
F_37 ( V_212 , V_93 ) ;
return 0 ;
}
}
if ( V_68 -> V_95 != NULL ) {
F_22 ( V_68 -> V_95 ) ;
}
V_68 -> V_95 = V_33 ;
return 1 ;
}
case V_96 :
{
F_37 ( V_212 , V_87 ) ;
return ( 0 ) ;
}
break;
#endif
#ifndef F_26
case V_215 :
V_174 -> V_216 = V_60 ;
break;
case V_217 :
case V_218 :
{
unsigned char * V_219 = V_60 ;
if ( ! V_219 )
return 48 ;
if ( V_59 != 48 ) {
F_37 ( V_212 , V_220 ) ;
return 0 ;
}
if ( V_58 == V_217 ) {
memcpy ( V_174 -> V_221 , V_219 , 16 ) ;
memcpy ( V_174 -> V_222 , V_219 + 16 , 16 ) ;
memcpy ( V_174 -> V_223 , V_219 + 32 , 16 ) ;
} else {
memcpy ( V_219 , V_174 -> V_221 , 16 ) ;
memcpy ( V_219 + 16 , V_174 -> V_222 , 16 ) ;
memcpy ( V_219 + 32 , V_174 -> V_223 , 16 ) ;
}
return 1 ;
}
# ifdef F_14
case V_224 :
V_174 -> V_225 = V_60 ;
return 1 ;
# endif
case V_226 :
V_174 -> V_227 = V_60 ;
return 1 ;
break;
# ifndef F_11
case V_228 :
V_174 -> V_56 . V_229 |= V_230 ;
if ( V_174 -> V_56 . V_231 != NULL )
F_15 ( V_174 -> V_56 . V_231 ) ;
V_174 -> V_56 . V_231 = NULL ;
if ( V_60 == NULL )
break;
if ( strlen ( ( const char * ) V_60 ) > 255
|| strlen ( ( const char * ) V_60 ) < 1 ) {
F_37 ( V_212 , V_232 ) ;
return 0 ;
}
if ( ( V_174 -> V_56 . V_231 = F_34 ( ( char * ) V_60 ) ) == NULL ) {
F_37 ( V_212 , V_102 ) ;
return 0 ;
}
break;
case V_233 :
V_174 -> V_56 . V_234 =
F_33 ;
V_174 -> V_56 . V_57 = V_60 ;
break;
case V_235 :
V_174 -> V_56 . V_229 |= V_230 ;
V_174 -> V_56 . V_236 = V_60 ;
break;
case V_237 :
V_174 -> V_56 . V_238 = V_59 ;
break;
# endif
# ifndef F_30
case V_157 :
return F_60 ( & V_174 -> V_150 ,
& V_174 -> V_151 ,
V_60 , V_59 ) ;
case V_158 :
return F_61 ( & V_174 -> V_150 ,
& V_174 -> V_151 ,
V_60 ) ;
# ifndef F_21
case V_160 :
V_174 -> V_68 -> V_161 = V_59 ;
return 1 ;
# endif
# endif
case V_162 :
return F_63 ( V_174 -> V_68 , V_60 , V_59 , 0 ) ;
case V_163 :
return F_64 ( V_174 -> V_68 , V_60 , 0 ) ;
case V_164 :
return F_63 ( V_174 -> V_68 , V_60 , V_59 , 1 ) ;
case V_165 :
return F_64 ( V_174 -> V_68 , V_60 , 1 ) ;
case V_172 :
return F_65 ( V_174 -> V_68 , V_60 , V_59 ) ;
case V_173 :
return F_66 ( V_174 -> V_68 , V_174 -> V_175 , V_59 ) ;
case V_176 :
return F_67 ( V_174 -> V_68 , V_60 , 0 , V_59 ) ;
case V_177 :
return F_67 ( V_174 -> V_68 , V_60 , 1 , V_59 ) ;
#endif
case V_239 :
if ( V_174 -> V_240 == NULL ) {
if ( ( V_174 -> V_240 = F_80 () ) == NULL )
return ( 0 ) ;
}
F_81 ( V_174 -> V_240 , ( V_131 * ) V_60 ) ;
break;
case V_241 :
if ( V_174 -> V_240 == NULL && V_59 == 0 )
* ( F_46 ( V_131 ) * * ) V_60 = V_174 -> V_68 -> V_134 -> V_135 ;
else
* ( F_46 ( V_131 ) * * ) V_60 = V_174 -> V_240 ;
break;
case V_242 :
if ( V_174 -> V_240 ) {
F_82 ( V_174 -> V_240 , V_243 ) ;
V_174 -> V_240 = NULL ;
}
break;
case V_130 :
if ( V_59 )
return F_51 ( V_174 -> V_68 , ( F_46 ( V_131 ) * ) V_60 ) ;
else
return F_52 ( V_174 -> V_68 , ( F_46 ( V_131 ) * ) V_60 ) ;
case V_132 :
if ( V_59 )
return F_53 ( V_174 -> V_68 , ( V_131 * ) V_60 ) ;
else
return F_54 ( V_174 -> V_68 , ( V_131 * ) V_60 ) ;
case V_133 :
* ( F_46 ( V_131 ) * * ) V_60 = V_174 -> V_68 -> V_134 -> V_135 ;
break;
case V_136 :
return F_55 ( V_174 -> V_68 , ( V_131 * ) V_60 ) ;
case V_137 :
return F_57 ( V_174 -> V_68 , V_59 ) ;
default:
return ( 0 ) ;
}
return ( 1 ) ;
}
long F_83 ( T_14 * V_174 , int V_58 , void (* F_77) ( void ) )
{
T_15 * V_68 ;
V_68 = V_174 -> V_68 ;
switch ( V_58 ) {
#ifndef V_63
case V_65 :
{
V_68 -> V_207 = ( T_6 * (*)( T_2 * , int , int ) ) F_77 ;
}
break;
#endif
#ifndef F_19
case V_67 :
{
V_68 -> V_208 = ( T_7 * (*)( T_2 * , int , int ) ) F_77 ;
}
break;
#endif
#ifndef F_21
case V_96 :
{
V_68 -> V_209 = ( T_8 * (*)( T_2 * , int , int ) ) F_77 ;
}
break;
#endif
#ifndef F_26
case V_244 :
V_174 -> V_245 = ( int ( * ) ( T_2 * , int * , void * ) ) F_77 ;
break;
# ifdef F_14
case V_246 :
V_174 -> V_247 =
( int ( * ) ( T_2 * , void * , T_4 , void * ) ) F_77 ;
break;
# endif
case V_248 :
V_174 -> V_249 = ( int ( * ) ( T_2 * , void * ) ) F_77 ;
break;
case V_250 :
V_174 -> V_251 = ( int (*) ( T_2 * , unsigned char * ,
unsigned char * ,
V_252 * ,
V_253 * , int ) ) F_77 ;
break;
# ifndef F_11
case V_254 :
V_174 -> V_56 . V_229 |= V_230 ;
V_174 -> V_56 . V_255 = ( int ( * ) ( T_2 * , void * ) ) F_77 ;
break;
case V_256 :
V_174 -> V_56 . V_229 |= V_230 ;
V_174 -> V_56 . V_257 =
( int ( * ) ( T_2 * , int * , void * ) ) F_77 ;
break;
case V_258 :
V_174 -> V_56 . V_229 |= V_230 ;
V_174 -> V_56 . V_234 =
( char * (*)( T_2 * , void * ) ) F_77 ;
break;
# endif
#endif
default:
return ( 0 ) ;
}
return ( 1 ) ;
}
const T_1 * F_84 ( const unsigned char * V_13 )
{
T_1 V_259 ;
const T_1 * V_260 ;
unsigned long V_261 ;
V_261 = 0x03000000L | ( ( unsigned long ) V_13 [ 0 ] << 8L ) | ( unsigned long ) V_13 [ 1 ] ;
V_259 . V_261 = V_261 ;
V_260 = F_85 ( & V_259 , V_3 , V_1 ) ;
#ifdef F_86
if ( V_260 == NULL )
fprintf ( V_262 , L_1 , ( V_13 [ 0 ] << 8 ) | V_13 [ 1 ] ) ;
#endif
return V_260 ;
}
int F_87 ( const T_1 * V_259 , unsigned char * V_13 )
{
long V_263 ;
if ( V_13 != NULL ) {
V_263 = V_259 -> V_261 ;
if ( ( V_263 & 0xff000000 ) != 0x03000000 )
return ( 0 ) ;
V_13 [ 0 ] = ( ( unsigned char ) ( V_263 >> 8L ) ) & 0xFF ;
V_13 [ 1 ] = ( ( unsigned char ) ( V_263 ) ) & 0xFF ;
}
return ( 2 ) ;
}
int F_88 ( T_2 * V_4 , unsigned char * V_13 )
{
int V_61 = 0 ;
const unsigned char * V_180 ;
T_4 V_152 , V_264 ;
int V_265 = 0 , V_266 = 0 ;
#ifndef F_89
int V_267 = 0 ;
#endif
int V_268 = 1 ;
unsigned long V_269 ;
if ( V_4 -> V_68 -> V_169 ) {
memcpy ( V_13 , V_4 -> V_68 -> V_169 , V_4 -> V_68 -> V_170 ) ;
return ( int ) V_4 -> V_68 -> V_170 ;
}
V_264 = F_90 ( V_4 , & V_180 ) ;
if ( V_4 -> V_68 -> V_270 & V_271 )
V_268 = 0 ;
for ( V_152 = 0 ; V_152 < V_264 ; V_152 += 2 , V_180 += 2 ) {
switch ( V_180 [ 1 ] ) {
case V_272 :
V_265 = 1 ;
break;
case V_273 :
V_266 = 1 ;
break;
#ifndef F_89
case V_274 :
V_267 = 1 ;
break;
#endif
}
}
V_269 = V_4 -> V_7 -> V_31 . V_142 -> V_275 ;
#ifndef F_91
if ( V_4 -> V_50 >= V_202 ) {
if ( V_269 & V_276 ) {
V_13 [ V_61 ++ ] = V_277 ;
V_13 [ V_61 ++ ] = V_278 ;
return ( V_61 ) ;
}
}
#endif
#ifndef F_19
if ( V_269 & ( V_279 | V_280 ) ) {
# ifndef V_63
if ( V_268 || V_265 )
V_13 [ V_61 ++ ] = V_281 ;
# endif
# ifndef V_62
if ( V_268 || V_266 )
V_13 [ V_61 ++ ] = V_282 ;
# endif
}
if ( ( V_4 -> V_50 == V_51 ) &&
( V_269 & ( V_280 | V_283 | V_279 ) ) ) {
# ifndef V_63
V_13 [ V_61 ++ ] = V_284 ;
# endif
# ifndef V_62
V_13 [ V_61 ++ ] = V_285 ;
# endif
}
#endif
#ifndef V_63
if ( V_265 )
V_13 [ V_61 ++ ] = V_286 ;
#endif
#ifndef V_62
if ( V_266 )
V_13 [ V_61 ++ ] = V_287 ;
#endif
#ifndef F_21
if ( ( V_269 & ( V_288 | V_289 ) ) && ( V_4 -> V_50 >= V_202 ) ) {
if ( V_268 || V_265 )
V_13 [ V_61 ++ ] = V_290 ;
if ( V_268 || V_267 )
V_13 [ V_61 ++ ] = V_291 ;
}
#endif
#ifndef F_89
if ( V_4 -> V_50 >= V_202 ) {
if ( V_267 )
V_13 [ V_61 ++ ] = V_292 ;
}
#endif
return ( V_61 ) ;
}
static int F_65 ( T_15 * V_259 , const unsigned char * V_13 , T_4 V_12 )
{
if ( V_259 -> V_169 ) {
F_15 ( V_259 -> V_169 ) ;
V_259 -> V_169 = NULL ;
}
if ( ! V_13 || ! V_12 )
return 1 ;
if ( V_12 > 0xff )
return 0 ;
V_259 -> V_169 = F_10 ( V_12 ) ;
if ( ! V_259 -> V_169 )
return 0 ;
memcpy ( V_259 -> V_169 , V_13 , V_12 ) ;
V_259 -> V_170 = V_12 ;
return 1 ;
}
int F_92 ( T_2 * V_4 )
{
int V_61 ;
if ( ( V_4 -> V_293 ) || ( V_4 -> V_294 == V_295 ) ) {
V_4 -> V_296 = ( V_297 | V_298 ) ;
return ( 1 ) ;
}
if ( ! ( V_4 -> V_296 & V_297 ) ) {
V_4 -> V_296 |= V_297 ;
#if 1
F_93 ( V_4 , V_299 , V_300 ) ;
#endif
if ( V_4 -> V_7 -> V_301 )
return ( - 1 ) ;
} else if ( V_4 -> V_7 -> V_301 ) {
#if 1
V_61 = V_4 -> V_23 -> V_302 ( V_4 ) ;
if ( V_61 == - 1 ) {
return ( V_61 ) ;
}
#endif
} else if ( ! ( V_4 -> V_296 & V_298 ) ) {
V_4 -> V_23 -> V_303 ( V_4 , 0 , NULL , 0 , 0 ) ;
if ( ! ( V_4 -> V_296 & V_298 ) ) {
return ( - 1 ) ;
}
}
if ( ( V_4 -> V_296 == ( V_297 | V_298 ) ) &&
! V_4 -> V_7 -> V_301 )
return ( 1 ) ;
else
return ( 0 ) ;
}
int F_94 ( T_2 * V_4 , const void * V_28 , int V_12 )
{
int V_61 , V_304 ;
#if 0
if (s->shutdown & SSL_SEND_SHUTDOWN) {
s->rwstate = SSL_NOTHING;
return (0);
}
#endif
F_95 () ;
if ( V_4 -> V_7 -> V_46 )
F_96 ( V_4 ) ;
if ( ( V_4 -> V_7 -> V_78 & V_305 ) && ( V_4 -> V_306 == V_4 -> V_307 ) ) {
if ( V_4 -> V_7 -> V_308 == 0 ) {
V_61 = F_97 ( V_4 , V_9 , V_28 , V_12 ) ;
if ( V_61 <= 0 )
return ( V_61 ) ;
V_4 -> V_7 -> V_308 = V_61 ;
}
V_4 -> V_309 = V_310 ;
V_304 = F_98 ( V_4 -> V_306 ) ;
if ( V_304 <= 0 )
return ( V_304 ) ;
V_4 -> V_309 = V_311 ;
F_32 ( V_4 ) ;
V_4 -> V_7 -> V_78 &= ~ V_305 ;
V_61 = V_4 -> V_7 -> V_308 ;
V_4 -> V_7 -> V_308 = 0 ;
} else {
V_61 = V_4 -> V_23 -> V_312 ( V_4 , V_9 ,
V_28 , V_12 ) ;
if ( V_61 <= 0 )
return ( V_61 ) ;
}
return ( V_61 ) ;
}
static int F_99 ( T_2 * V_4 , void * V_28 , int V_12 , int V_313 )
{
int V_61 ;
F_95 () ;
if ( V_4 -> V_7 -> V_46 )
F_96 ( V_4 ) ;
V_4 -> V_7 -> V_49 = 1 ;
V_61 =
V_4 -> V_23 -> V_303 ( V_4 , V_9 , V_28 , V_12 ,
V_313 ) ;
if ( ( V_61 == - 1 ) && ( V_4 -> V_7 -> V_49 == 2 ) ) {
V_4 -> V_314 ++ ;
V_61 =
V_4 -> V_23 -> V_303 ( V_4 , V_9 , V_28 , V_12 ,
V_313 ) ;
V_4 -> V_314 -- ;
} else
V_4 -> V_7 -> V_49 = 0 ;
return ( V_61 ) ;
}
int F_100 ( T_2 * V_4 , void * V_28 , int V_12 )
{
return F_99 ( V_4 , V_28 , V_12 , 0 ) ;
}
int F_101 ( T_2 * V_4 , void * V_28 , int V_12 )
{
return F_99 ( V_4 , V_28 , V_12 , 1 ) ;
}
int F_102 ( T_2 * V_4 )
{
if ( V_4 -> V_315 == NULL )
return ( 1 ) ;
if ( V_4 -> V_7 -> V_78 & V_316 )
return ( 0 ) ;
V_4 -> V_7 -> V_46 = 1 ;
return ( 1 ) ;
}
int F_96 ( T_2 * V_4 )
{
int V_61 = 0 ;
if ( V_4 -> V_7 -> V_46 ) {
if ( ( V_4 -> V_7 -> V_27 . V_317 == 0 ) &&
( V_4 -> V_7 -> V_29 . V_317 == 0 ) && ! F_103 ( V_4 ) ) {
V_4 -> V_294 = V_318 ;
V_4 -> V_7 -> V_46 = 0 ;
V_4 -> V_7 -> V_48 ++ ;
V_4 -> V_7 -> V_47 ++ ;
V_61 = 1 ;
}
}
return ( V_61 ) ;
}
long F_104 ( T_2 * V_4 )
{
long V_319 = V_4 -> V_7 -> V_31 . V_142 -> V_320 ;
if ( V_4 -> V_23 -> V_321 -> V_322 & V_323
&& V_319 == ( V_324 | V_325 ) )
return V_326 | V_327 ;
return V_319 ;
}

static int F_1 ( const void * V_1 , const void * V_2 )
{
const T_1 * V_3 = ( const T_1 * ) V_1 ;
const T_1 * V_4 = ( const T_1 * ) V_2 ;
return V_3 -> V_5 - V_4 -> V_5 ;
}
void F_2 ( void )
{
qsort ( V_6 , F_3 ( V_6 ) , sizeof V_6 [ 0 ] ,
F_1 ) ;
}
long F_4 ( void )
{
return ( 60 * 60 * 2 ) ;
}
int F_5 ( void )
{
return ( V_7 ) ;
}
const T_1 * F_6 ( unsigned int V_8 )
{
if ( V_8 < V_7 )
return ( & ( V_6 [ V_7 - 1 - V_8 ] ) ) ;
else
return ( NULL ) ;
}
int F_7 ( T_2 * V_9 , int V_10 , unsigned long V_11 )
{
unsigned char * V_12 = ( unsigned char * ) V_9 -> V_13 -> V_14 ;
* ( V_12 ++ ) = V_10 ;
F_8 ( V_11 , V_12 ) ;
V_9 -> V_15 = ( int ) V_11 + V_16 ;
V_9 -> V_17 = 0 ;
return 1 ;
}
int F_9 ( T_2 * V_9 )
{
return F_10 ( V_9 , V_18 ) ;
}
int F_11 ( T_2 * V_9 )
{
T_3 * V_19 ;
if ( ( V_19 = F_12 ( sizeof( * V_19 ) ) ) == NULL )
goto V_20;
V_9 -> V_19 = V_19 ;
#ifndef F_13
if ( ! F_14 ( V_9 ) )
goto V_20;
#endif
V_9 -> V_21 -> V_22 ( V_9 ) ;
return ( 1 ) ;
V_20:
return ( 0 ) ;
}
void F_15 ( T_2 * V_9 )
{
if ( V_9 == NULL || V_9 -> V_19 == NULL )
return;
F_16 ( V_9 ) ;
#if ! F_17 ( V_23 ) || ! F_17 ( V_24 )
F_18 ( V_9 -> V_19 -> V_25 ) ;
V_9 -> V_19 -> V_25 = NULL ;
F_18 ( V_9 -> V_19 -> V_26 . V_27 ) ;
V_9 -> V_19 -> V_26 . V_27 = NULL ;
#endif
F_19 ( V_9 -> V_19 -> V_26 . V_28 , V_29 ) ;
F_20 ( V_9 -> V_19 -> V_26 . V_30 ) ;
F_21 ( V_9 -> V_19 -> V_26 . V_31 , V_9 -> V_19 -> V_26 . V_32 ) ;
F_20 ( V_9 -> V_19 -> V_26 . V_33 ) ;
F_22 ( V_9 ) ;
F_20 ( V_9 -> V_19 -> V_34 ) ;
F_20 ( V_9 -> V_19 -> V_35 ) ;
#ifndef F_13
F_23 ( V_9 ) ;
#endif
F_21 ( V_9 -> V_19 , sizeof( * V_9 -> V_19 ) ) ;
V_9 -> V_19 = NULL ;
}
void F_24 ( T_2 * V_9 )
{
F_16 ( V_9 ) ;
F_19 ( V_9 -> V_19 -> V_26 . V_28 , V_29 ) ;
F_20 ( V_9 -> V_19 -> V_26 . V_30 ) ;
F_21 ( V_9 -> V_19 -> V_26 . V_31 , V_9 -> V_19 -> V_26 . V_32 ) ;
F_20 ( V_9 -> V_19 -> V_26 . V_33 ) ;
#if ! F_17 ( V_23 ) || ! F_17 ( V_24 )
F_18 ( V_9 -> V_19 -> V_26 . V_27 ) ;
F_18 ( V_9 -> V_19 -> V_25 ) ;
#endif
F_22 ( V_9 ) ;
F_20 ( V_9 -> V_19 -> V_34 ) ;
F_20 ( V_9 -> V_19 -> V_35 ) ;
memset ( V_9 -> V_19 , 0 , sizeof( * V_9 -> V_19 ) ) ;
F_25 ( V_9 ) ;
V_9 -> V_36 = V_37 ;
#if ! F_17 ( V_38 )
F_20 ( V_9 -> V_39 ) ;
V_9 -> V_39 = NULL ;
V_9 -> V_40 = 0 ;
#endif
}
static char * F_26 ( T_2 * V_9 , void * V_41 )
{
return F_27 ( V_9 -> V_42 . V_43 ) ;
}
long F_28 ( T_2 * V_9 , int V_44 , long V_45 , void * V_46 )
{
int V_47 = 0 ;
switch ( V_44 ) {
case V_48 :
break;
case V_49 :
V_47 = V_9 -> V_19 -> V_50 ;
break;
case V_51 :
V_47 = V_9 -> V_19 -> V_50 ;
V_9 -> V_19 -> V_50 = 0 ;
break;
case V_52 :
V_47 = V_9 -> V_19 -> V_53 ;
break;
case V_54 :
V_47 = ( int ) ( V_9 -> V_19 -> V_55 ) ;
break;
#ifndef V_24
case V_56 :
{
T_4 * V_57 = ( T_4 * ) V_46 ;
T_5 * V_58 = NULL ;
if ( V_57 == NULL ) {
F_29 ( V_59 , V_60 ) ;
return ( V_47 ) ;
}
V_58 = F_30 ( V_57 ) ;
if ( V_58 == NULL ) {
F_29 ( V_59 , V_61 ) ;
return 0 ;
}
if ( ! F_31 ( V_9 , V_62 ,
F_32 ( V_58 ) , 0 , V_58 ) ) {
F_29 ( V_59 , V_63 ) ;
F_18 ( V_58 ) ;
return V_47 ;
}
F_18 ( V_9 -> V_64 -> V_65 ) ;
V_9 -> V_64 -> V_65 = V_58 ;
V_47 = 1 ;
}
break;
case V_66 :
{
F_29 ( V_59 , V_67 ) ;
return ( V_47 ) ;
}
case V_68 :
V_9 -> V_64 -> V_69 = V_45 ;
return 1 ;
#endif
#ifndef V_23
case V_70 :
{
const T_6 * V_71 = NULL ;
int V_72 ;
if ( V_46 == NULL ) {
F_29 ( V_59 , V_60 ) ;
return 0 ;
}
V_71 = F_33 ( ( const V_73 * ) V_46 ) ;
if ( V_71 == NULL ) {
F_29 ( V_59 , V_74 ) ;
return 0 ;
}
V_72 = F_34 ( V_71 ) ;
if ( V_72 == V_75 )
return 0 ;
return F_35 ( & V_9 -> V_76 ,
& V_9 -> V_77 ,
& V_72 , 1 ) ;
}
break;
#endif
case V_78 :
if ( V_45 == V_79 ) {
T_7 V_11 ;
F_20 ( V_9 -> V_80 ) ;
V_9 -> V_80 = NULL ;
V_47 = 1 ;
if ( V_46 == NULL )
break;
V_11 = strlen ( ( char * ) V_46 ) ;
if ( V_11 == 0 || V_11 > V_81 ) {
F_29 ( V_59 , V_82 ) ;
return 0 ;
}
if ( ( V_9 -> V_80 = F_27 ( ( char * ) V_46 ) ) == NULL ) {
F_29 ( V_59 , V_83 ) ;
return 0 ;
}
} else {
F_29 ( V_59 , V_84 ) ;
return 0 ;
}
break;
case V_85 :
V_9 -> V_86 = V_46 ;
V_47 = 1 ;
break;
case V_87 :
V_47 = V_9 -> V_88 ;
break;
case V_89 :
V_9 -> V_88 = V_45 ;
V_47 = 1 ;
break;
case V_90 :
* ( F_36 ( V_91 ) * * ) V_46 = V_9 -> V_92 ;
V_47 = 1 ;
break;
case V_93 :
V_9 -> V_92 = V_46 ;
V_47 = 1 ;
break;
case V_94 :
* ( F_36 ( V_95 ) * * ) V_46 = V_9 -> V_96 ;
V_47 = 1 ;
break;
case V_97 :
V_9 -> V_96 = V_46 ;
V_47 = 1 ;
break;
case V_98 :
* ( unsigned char * * ) V_46 = V_9 -> V_99 ;
return V_9 -> V_100 ;
case V_101 :
F_20 ( V_9 -> V_99 ) ;
V_9 -> V_99 = V_46 ;
V_9 -> V_100 = V_45 ;
V_47 = 1 ;
break;
#ifndef F_37
case V_102 :
if ( F_38 ( V_9 ) )
V_47 = F_39 ( V_9 ) ;
break;
case V_103 :
if ( F_38 ( V_9 ) )
V_47 = V_9 -> V_104 ;
break;
case V_105 :
if ( F_38 ( V_9 ) ) {
if ( V_45 )
V_9 -> V_106 |= V_107 ;
else
V_9 -> V_106 &= ~ V_107 ;
V_47 = 1 ;
}
break;
#endif
case V_108 :
if ( V_45 )
return F_40 ( V_9 , NULL , ( F_36 ( V_109 ) * ) V_46 ) ;
else
return F_41 ( V_9 , NULL , ( F_36 ( V_109 ) * ) V_46 ) ;
case V_110 :
if ( V_45 )
return F_42 ( V_9 , NULL , ( V_109 * ) V_46 ) ;
else
return F_43 ( V_9 , NULL , ( V_109 * ) V_46 ) ;
case V_111 :
* ( F_36 ( V_109 ) * * ) V_46 = V_9 -> V_64 -> V_112 -> V_113 ;
break;
case V_114 :
return F_44 ( V_9 -> V_64 , ( V_109 * ) V_46 ) ;
case V_115 :
if ( V_45 == V_116 ) {
T_8 * V_117 ;
const T_1 * V_118 ;
if ( ! V_9 -> V_119 )
return 0 ;
V_118 = V_9 -> V_19 -> V_26 . V_120 ;
if ( ! V_118 )
return 0 ;
if ( V_118 -> V_121 & ( V_122 | V_123 ) )
return 2 ;
V_117 = F_45 ( V_9 ) ;
if ( ! V_117 )
return 0 ;
V_9 -> V_64 -> V_112 = V_117 ;
return 1 ;
}
return F_46 ( V_9 -> V_64 , V_45 ) ;
#ifndef V_23
case V_124 :
{
unsigned char * V_125 ;
T_7 V_126 ;
if ( ! V_9 -> V_127 )
return 0 ;
V_125 = V_9 -> V_127 -> V_76 ;
V_126 = V_9 -> V_127 -> V_77 / 2 ;
if ( V_46 ) {
T_7 V_128 ;
int * V_129 = V_46 ;
unsigned int V_130 , V_72 ;
for ( V_128 = 0 ; V_128 < V_126 ; V_128 ++ ) {
F_47 ( V_125 , V_130 ) ;
V_72 = F_48 ( V_130 , NULL ) ;
if ( V_72 != 0 )
V_129 [ V_128 ] = V_72 ;
else
V_129 [ V_128 ] = V_131 | V_130 ;
}
}
return ( int ) V_126 ;
}
case V_132 :
return F_35 ( & V_9 -> V_76 ,
& V_9 -> V_77 , V_46 , V_45 ) ;
case V_133 :
return F_49 ( & V_9 -> V_76 ,
& V_9 -> V_77 , V_46 ) ;
case V_134 :
return F_50 ( V_9 , V_45 ) ;
#endif
case V_135 :
return F_51 ( V_9 -> V_64 , V_46 , V_45 , 0 ) ;
case V_136 :
return F_52 ( V_9 -> V_64 , V_46 , 0 ) ;
case V_137 :
return F_51 ( V_9 -> V_64 , V_46 , V_45 , 1 ) ;
case V_138 :
return F_52 ( V_9 -> V_64 , V_46 , 1 ) ;
case V_139 :
{
const unsigned char * * V_140 = V_46 ;
if ( V_9 -> V_119 || ! V_9 -> V_19 -> V_26 . V_141 )
return 0 ;
if ( V_9 -> V_64 -> V_142 ) {
if ( V_140 )
* V_140 = V_9 -> V_64 -> V_142 ;
return ( int ) V_9 -> V_64 -> V_143 ;
}
if ( V_140 )
* V_140 = ( unsigned char * ) V_9 -> V_19 -> V_26 . V_144 ;
return V_9 -> V_19 -> V_26 . V_143 ;
}
case V_145 :
if ( ! V_9 -> V_119 )
return 0 ;
return F_53 ( V_9 -> V_64 , V_46 , V_45 ) ;
case V_146 :
return F_54 ( V_9 , NULL , V_45 ) ;
case V_147 :
return F_55 ( V_9 -> V_64 , V_46 , 0 , V_45 ) ;
case V_148 :
return F_55 ( V_9 -> V_64 , V_46 , 1 , V_45 ) ;
case V_149 :
if ( F_56 ( V_9 ) ) {
if ( V_9 -> V_127 ) {
const T_9 * V_150 ;
V_150 = V_9 -> V_19 -> V_26 . V_151 ;
if ( V_150 ) {
* ( int * ) V_46 = F_57 ( V_150 ) ;
return 1 ;
}
}
return 0 ;
}
else
return 0 ;
case V_152 :
#if ! F_17 ( V_24 ) || ! F_17 ( V_23 )
if ( V_9 -> V_119 || V_9 -> V_127 == NULL || V_9 -> V_19 -> V_25 == NULL ) {
return 0 ;
} else {
F_58 ( V_9 -> V_19 -> V_25 ) ;
* ( T_5 * * ) V_46 = V_9 -> V_19 -> V_25 ;
return 1 ;
}
#else
return 0 ;
#endif
#ifndef V_23
case V_153 :
{
T_10 * V_154 = V_9 -> V_127 ;
const unsigned char * * V_155 = V_46 ;
if ( ! V_154 || ! V_154 -> V_156 )
return 0 ;
* V_155 = V_154 -> V_156 ;
return ( int ) V_154 -> V_157 ;
}
#endif
default:
break;
}
return ( V_47 ) ;
}
long F_59 ( T_2 * V_9 , int V_44 , void (* F_60) ( void ) )
{
int V_47 = 0 ;
switch ( V_44 ) {
#ifndef V_24
case V_66 :
{
V_9 -> V_64 -> V_158 = ( T_4 * (*)( T_2 * , int , int ) ) F_60 ;
}
break;
#endif
case V_159 :
V_9 -> V_160 = ( void (*) ( T_2 * , int , int ,
const unsigned char * , int , void * ) ) F_60 ;
break;
case V_161 :
{
V_9 -> V_162 = ( int ( * ) ( T_2 * , int ) ) F_60 ;
}
break;
default:
break;
}
return ( V_47 ) ;
}
long F_61 ( T_11 * V_163 , int V_44 , long V_45 , void * V_46 )
{
switch ( V_44 ) {
#ifndef V_24
case V_56 :
{
T_4 * V_57 = ( T_4 * ) V_46 ;
T_5 * V_58 = NULL ;
if ( V_57 == NULL ) {
F_29 ( V_164 , V_60 ) ;
return 0 ;
}
V_58 = F_30 ( V_57 ) ;
if ( V_58 == NULL ) {
F_29 ( V_164 , V_61 ) ;
return 0 ;
}
if ( ! F_62 ( V_163 , V_62 ,
F_32 ( V_58 ) , 0 , V_58 ) ) {
F_29 ( V_164 , V_63 ) ;
F_18 ( V_58 ) ;
return 1 ;
}
F_18 ( V_163 -> V_64 -> V_65 ) ;
V_163 -> V_64 -> V_65 = V_58 ;
return 1 ;
}
case V_66 :
{
F_29 ( V_164 , V_67 ) ;
return ( 0 ) ;
}
case V_68 :
V_163 -> V_64 -> V_69 = V_45 ;
return 1 ;
#endif
#ifndef V_23
case V_70 :
{
const T_6 * V_71 = NULL ;
int V_72 ;
if ( V_46 == NULL ) {
F_29 ( V_164 , V_60 ) ;
return 0 ;
}
V_71 = F_33 ( ( const V_73 * ) V_46 ) ;
if ( V_71 == NULL ) {
F_29 ( V_164 , V_74 ) ;
return 0 ;
}
V_72 = F_34 ( V_71 ) ;
if ( V_72 == V_75 )
return 0 ;
return F_35 ( & V_163 -> V_76 ,
& V_163 -> V_77 ,
& V_72 , 1 ) ;
}
#endif
case V_165 :
V_163 -> V_166 = V_46 ;
break;
case V_167 :
case V_168 :
{
unsigned char * V_169 = V_46 ;
long V_170 = ( sizeof( V_163 -> V_171 ) +
sizeof( V_163 -> V_172 ) +
sizeof( V_163 -> V_173 ) ) ;
if ( V_169 == NULL )
return V_170 ;
if ( V_45 != V_170 ) {
F_29 ( V_164 , V_174 ) ;
return 0 ;
}
if ( V_44 == V_167 ) {
memcpy ( V_163 -> V_171 , V_169 ,
sizeof( V_163 -> V_171 ) ) ;
memcpy ( V_163 -> V_172 ,
V_169 + sizeof( V_163 -> V_171 ) ,
sizeof( V_163 -> V_172 ) ) ;
memcpy ( V_163 -> V_173 ,
V_169 + sizeof( V_163 -> V_171 ) +
sizeof( V_163 -> V_172 ) ,
sizeof( V_163 -> V_173 ) ) ;
} else {
memcpy ( V_169 , V_163 -> V_171 ,
sizeof( V_163 -> V_171 ) ) ;
memcpy ( V_169 + sizeof( V_163 -> V_171 ) ,
V_163 -> V_172 ,
sizeof( V_163 -> V_172 ) ) ;
memcpy ( V_169 + sizeof( V_163 -> V_171 ) +
sizeof( V_163 -> V_172 ) ,
V_163 -> V_173 ,
sizeof( V_163 -> V_173 ) ) ;
}
return 1 ;
}
case V_87 :
return V_163 -> V_88 ;
case V_89 :
V_163 -> V_88 = V_45 ;
break;
case V_175 :
V_163 -> V_176 = V_46 ;
return 1 ;
case V_177 :
* ( void * * ) V_46 = V_163 -> V_176 ;
break;
case V_178 :
* ( int ( * * ) ( T_2 * , void * ) ) V_46 = V_163 -> V_179 ;
break;
#ifndef F_13
case V_180 :
V_163 -> V_42 . V_181 |= V_182 ;
F_20 ( V_163 -> V_42 . V_183 ) ;
V_163 -> V_42 . V_183 = NULL ;
if ( V_46 == NULL )
break;
if ( strlen ( ( const char * ) V_46 ) > 255 || strlen ( ( const char * ) V_46 ) < 1 ) {
F_29 ( V_164 , V_184 ) ;
return 0 ;
}
if ( ( V_163 -> V_42 . V_183 = F_27 ( ( char * ) V_46 ) ) == NULL ) {
F_29 ( V_164 , V_83 ) ;
return 0 ;
}
break;
case V_185 :
V_163 -> V_42 . V_186 =
F_26 ;
V_163 -> V_42 . V_43 = V_46 ;
break;
case V_187 :
V_163 -> V_42 . V_181 |= V_182 ;
V_163 -> V_42 . V_188 = V_46 ;
break;
case V_189 :
V_163 -> V_42 . V_190 = V_45 ;
break;
#endif
#ifndef V_23
case V_132 :
return F_35 ( & V_163 -> V_76 ,
& V_163 -> V_77 ,
V_46 , V_45 ) ;
case V_133 :
return F_49 ( & V_163 -> V_76 ,
& V_163 -> V_77 ,
V_46 ) ;
#endif
case V_135 :
return F_51 ( V_163 -> V_64 , V_46 , V_45 , 0 ) ;
case V_136 :
return F_52 ( V_163 -> V_64 , V_46 , 0 ) ;
case V_137 :
return F_51 ( V_163 -> V_64 , V_46 , V_45 , 1 ) ;
case V_138 :
return F_52 ( V_163 -> V_64 , V_46 , 1 ) ;
case V_145 :
return F_53 ( V_163 -> V_64 , V_46 , V_45 ) ;
case V_146 :
return F_54 ( NULL , V_163 , V_45 ) ;
case V_147 :
return F_55 ( V_163 -> V_64 , V_46 , 0 , V_45 ) ;
case V_148 :
return F_55 ( V_163 -> V_64 , V_46 , 1 , V_45 ) ;
case V_191 :
if ( V_163 -> V_192 == NULL ) {
if ( ( V_163 -> V_192 = F_63 () ) == NULL ) {
F_29 ( V_164 , V_61 ) ;
return 0 ;
}
}
if ( ! F_64 ( V_163 -> V_192 , ( V_109 * ) V_46 ) ) {
F_29 ( V_164 , V_61 ) ;
return 0 ;
}
break;
case V_193 :
if ( V_163 -> V_192 == NULL && V_45 == 0 )
* ( F_36 ( V_109 ) * * ) V_46 = V_163 -> V_64 -> V_112 -> V_113 ;
else
* ( F_36 ( V_109 ) * * ) V_46 = V_163 -> V_192 ;
break;
case V_194 :
F_65 ( V_163 -> V_192 , V_195 ) ;
V_163 -> V_192 = NULL ;
break;
case V_108 :
if ( V_45 )
return F_40 ( NULL , V_163 , ( F_36 ( V_109 ) * ) V_46 ) ;
else
return F_41 ( NULL , V_163 , ( F_36 ( V_109 ) * ) V_46 ) ;
case V_110 :
if ( V_45 )
return F_42 ( NULL , V_163 , ( V_109 * ) V_46 ) ;
else
return F_43 ( NULL , V_163 , ( V_109 * ) V_46 ) ;
case V_111 :
* ( F_36 ( V_109 ) * * ) V_46 = V_163 -> V_64 -> V_112 -> V_113 ;
break;
case V_114 :
return F_44 ( V_163 -> V_64 , ( V_109 * ) V_46 ) ;
case V_115 :
return F_46 ( V_163 -> V_64 , V_45 ) ;
default:
return ( 0 ) ;
}
return ( 1 ) ;
}
long F_66 ( T_11 * V_163 , int V_44 , void (* F_60) ( void ) )
{
switch ( V_44 ) {
#ifndef V_24
case V_66 :
{
V_163 -> V_64 -> V_158 = ( T_4 * (*)( T_2 * , int , int ) ) F_60 ;
}
break;
#endif
case V_196 :
V_163 -> V_197 = ( int ( * ) ( T_2 * , int * , void * ) ) F_60 ;
break;
case V_198 :
V_163 -> V_179 = ( int ( * ) ( T_2 * , void * ) ) F_60 ;
break;
case V_199 :
V_163 -> V_200 = ( int (*) ( T_2 * , unsigned char * ,
unsigned char * ,
V_201 * ,
V_202 * , int ) ) F_60 ;
break;
#ifndef F_13
case V_203 :
V_163 -> V_42 . V_181 |= V_182 ;
V_163 -> V_42 . V_204 = ( int ( * ) ( T_2 * , void * ) ) F_60 ;
break;
case V_205 :
V_163 -> V_42 . V_181 |= V_182 ;
V_163 -> V_42 . V_206 =
( int ( * ) ( T_2 * , int * , void * ) ) F_60 ;
break;
case V_207 :
V_163 -> V_42 . V_181 |= V_182 ;
V_163 -> V_42 . V_186 =
( char * (*)( T_2 * , void * ) ) F_60 ;
break;
#endif
case V_161 :
{
V_163 -> V_162 = ( int ( * ) ( T_2 * , int ) ) F_60 ;
}
break;
default:
return ( 0 ) ;
}
return ( 1 ) ;
}
const T_1 * F_67 ( const unsigned char * V_12 )
{
T_1 V_208 ;
const T_1 * V_209 ;
T_12 V_5 ;
V_5 = 0x03000000 | ( ( T_12 ) V_12 [ 0 ] << 8L ) | ( T_12 ) V_12 [ 1 ] ;
V_208 . V_5 = V_5 ;
V_209 = F_68 ( & V_208 , V_6 , V_7 ) ;
return V_209 ;
}
int F_69 ( const T_1 * V_208 , unsigned char * V_12 )
{
long V_210 ;
if ( V_12 != NULL ) {
V_210 = V_208 -> V_5 ;
if ( ( V_210 & 0xff000000 ) != 0x03000000 )
return ( 0 ) ;
V_12 [ 0 ] = ( ( unsigned char ) ( V_210 >> 8L ) ) & 0xFF ;
V_12 [ 1 ] = ( ( unsigned char ) ( V_210 ) ) & 0xFF ;
}
return ( 2 ) ;
}
int F_70 ( T_2 * V_9 , unsigned char * V_12 )
{
int V_47 = 0 ;
T_12 V_211 , V_212 = 0 ;
if ( V_9 -> V_64 -> V_142 ) {
memcpy ( V_12 , V_9 -> V_64 -> V_142 , V_9 -> V_64 -> V_143 ) ;
return ( int ) V_9 -> V_64 -> V_143 ;
}
F_71 ( & V_212 , V_9 , V_213 ) ;
V_211 = V_9 -> V_19 -> V_26 . V_120 -> V_214 ;
#ifndef F_72
if ( V_9 -> V_36 >= V_215 ) {
if ( V_211 & V_216 ) {
V_12 [ V_47 ++ ] = V_217 ;
V_12 [ V_47 ++ ] = V_218 ;
V_12 [ V_47 ++ ] = V_219 ;
return ( V_47 ) ;
}
}
#endif
if ( ( V_9 -> V_36 == V_37 ) && ( V_211 & V_220 ) ) {
#ifndef V_24
# ifndef F_73
V_12 [ V_47 ++ ] = V_221 ;
# endif
# ifndef F_74
V_12 [ V_47 ++ ] = V_222 ;
# endif
#endif
}
#ifndef F_73
if ( ! ( V_212 & V_223 ) )
V_12 [ V_47 ++ ] = V_224 ;
#endif
#ifndef F_74
if ( ! ( V_212 & V_225 ) )
V_12 [ V_47 ++ ] = V_226 ;
#endif
#ifndef V_23
if ( V_9 -> V_36 >= V_215 ) {
if ( ! ( V_212 & V_227 ) )
V_12 [ V_47 ++ ] = V_228 ;
}
#endif
return ( V_47 ) ;
}
static int F_53 ( T_13 * V_208 , const unsigned char * V_12 , T_7 V_11 )
{
F_20 ( V_208 -> V_142 ) ;
V_208 -> V_142 = NULL ;
if ( ! V_12 || ! V_11 )
return 1 ;
if ( V_11 > 0xff )
return 0 ;
V_208 -> V_142 = F_75 ( V_11 ) ;
if ( V_208 -> V_142 == NULL )
return 0 ;
memcpy ( V_208 -> V_142 , V_12 , V_11 ) ;
V_208 -> V_143 = V_11 ;
return 1 ;
}
int F_76 ( T_2 * V_9 )
{
int V_47 ;
if ( V_9 -> V_229 || F_77 ( V_9 ) ) {
V_9 -> V_230 = ( V_231 | V_232 ) ;
return ( 1 ) ;
}
if ( ! ( V_9 -> V_230 & V_231 ) ) {
V_9 -> V_230 |= V_231 ;
F_78 ( V_9 , V_233 , V_234 ) ;
if ( V_9 -> V_19 -> V_235 )
return ( - 1 ) ;
} else if ( V_9 -> V_19 -> V_235 ) {
V_47 = V_9 -> V_21 -> V_236 ( V_9 ) ;
if ( V_47 == - 1 ) {
return ( V_47 ) ;
}
} else if ( ! ( V_9 -> V_230 & V_232 ) ) {
V_9 -> V_21 -> V_237 ( V_9 , 0 , NULL , NULL , 0 , 0 ) ;
if ( ! ( V_9 -> V_230 & V_232 ) ) {
return ( - 1 ) ;
}
}
if ( ( V_9 -> V_230 == ( V_231 | V_232 ) ) &&
! V_9 -> V_19 -> V_235 )
return ( 1 ) ;
else
return ( 0 ) ;
}
int F_79 ( T_2 * V_9 , const void * V_238 , int V_11 )
{
F_80 () ;
if ( V_9 -> V_19 -> V_239 )
F_81 ( V_9 ) ;
return V_9 -> V_21 -> V_240 ( V_9 , V_241 , V_238 , V_11 ) ;
}
static int F_82 ( T_2 * V_9 , void * V_238 , int V_11 , int V_242 )
{
int V_47 ;
F_80 () ;
if ( V_9 -> V_19 -> V_239 )
F_81 ( V_9 ) ;
V_9 -> V_19 -> V_243 = 1 ;
V_47 =
V_9 -> V_21 -> V_237 ( V_9 , V_241 , NULL , V_238 , V_11 ,
V_242 ) ;
if ( ( V_47 == - 1 ) && ( V_9 -> V_19 -> V_243 == 2 ) ) {
F_83 ( V_9 , 1 ) ;
V_47 =
V_9 -> V_21 -> V_237 ( V_9 , V_241 , NULL , V_238 ,
V_11 , V_242 ) ;
F_83 ( V_9 , 0 ) ;
} else
V_9 -> V_19 -> V_243 = 0 ;
return ( V_47 ) ;
}
int F_84 ( T_2 * V_9 , void * V_238 , int V_11 )
{
return F_82 ( V_9 , V_238 , V_11 , 0 ) ;
}
int F_85 ( T_2 * V_9 , void * V_238 , int V_11 )
{
return F_82 ( V_9 , V_238 , V_11 , 1 ) ;
}
int F_86 ( T_2 * V_9 )
{
if ( V_9 -> V_244 == NULL )
return ( 1 ) ;
if ( V_9 -> V_19 -> V_55 & V_245 )
return ( 0 ) ;
V_9 -> V_19 -> V_239 = 1 ;
return ( 1 ) ;
}
int F_81 ( T_2 * V_9 )
{
int V_47 = 0 ;
if ( V_9 -> V_19 -> V_239 ) {
if ( ! F_87 ( & V_9 -> V_246 )
&& ! F_88 ( & V_9 -> V_246 )
&& ! F_89 ( V_9 ) ) {
F_90 ( V_9 ) ;
V_9 -> V_19 -> V_239 = 0 ;
V_9 -> V_19 -> V_50 ++ ;
V_9 -> V_19 -> V_53 ++ ;
V_47 = 1 ;
}
}
return ( V_47 ) ;
}
long F_91 ( T_2 * V_9 )
{
long V_247 ;
if ( V_9 -> V_19 == NULL || V_9 -> V_19 -> V_26 . V_120 == NULL )
return - 1 ;
V_247 = V_9 -> V_19 -> V_26 . V_120 -> V_248 ;
if ( V_9 -> V_21 -> V_249 -> V_250 & V_251 ) {
if ( V_247 == ( V_252 | V_253 ) )
return V_254 | V_255 ;
} else if ( V_9 -> V_19 -> V_26 . V_120 -> V_214 & V_256 ) {
if ( V_247 == ( V_257 | V_258 ) )
return V_252 | V_253 ;
}
return V_247 ;
}
int F_92 ( T_2 * V_9 , int V_119 , unsigned char * V_259 , int V_11 )
{
int V_260 = 0 ;
if ( V_11 < 4 )
return 0 ;
if ( V_119 )
V_260 = ( V_9 -> V_261 & V_262 ) != 0 ;
else
V_260 = ( V_9 -> V_261 & V_263 ) != 0 ;
if ( V_260 ) {
unsigned long Time = ( unsigned long ) time ( NULL ) ;
unsigned char * V_12 = V_259 ;
F_93 ( Time , V_12 ) ;
return F_94 ( V_12 , V_11 - 4 ) ;
} else
return F_94 ( V_259 , V_11 ) ;
}
int F_95 ( T_2 * V_9 , unsigned char * V_31 , T_7 V_32 ,
int V_264 )
{
unsigned long V_211 = V_9 -> V_19 -> V_26 . V_120 -> V_214 ;
if ( V_211 & V_256 ) {
#ifndef F_96
unsigned char * V_265 , * V_266 ;
T_7 V_267 = V_9 -> V_19 -> V_26 . V_267 ;
T_7 V_268 ;
if ( V_211 & V_269 )
V_32 = V_267 ;
V_268 = 4 + V_32 + V_267 ;
V_265 = F_75 ( V_268 ) ;
if ( V_265 == NULL ) {
V_9 -> V_127 -> V_270 = 0 ;
goto V_20;
}
V_266 = V_265 ;
F_97 ( V_32 , V_266 ) ;
if ( V_211 & V_269 )
memset ( V_266 , 0 , V_32 ) ;
else
memcpy ( V_266 , V_31 , V_32 ) ;
V_266 += V_32 ;
F_97 ( V_267 , V_266 ) ;
memcpy ( V_266 , V_9 -> V_19 -> V_26 . V_271 , V_267 ) ;
F_21 ( V_9 -> V_19 -> V_26 . V_271 , V_267 ) ;
V_9 -> V_19 -> V_26 . V_271 = NULL ;
V_9 -> V_127 -> V_270 =
V_9 -> V_21 -> V_249 -> V_272 ( V_9 ,
V_9 -> V_127 -> V_273 ,
V_265 , V_268 ) ;
F_21 ( V_265 , V_268 ) ;
#else
V_9 -> V_127 -> V_270 = 0 ;
goto V_20;
#endif
} else {
V_9 -> V_127 -> V_270 =
V_9 -> V_21 -> V_249 -> V_272 ( V_9 ,
V_9 -> V_127 -> V_273 ,
V_31 , V_32 ) ;
}
V_20:
if ( V_31 ) {
if ( V_264 )
F_21 ( V_31 , V_32 ) ;
else
F_98 ( V_31 , V_32 ) ;
}
if ( V_9 -> V_119 == 0 )
V_9 -> V_19 -> V_26 . V_31 = NULL ;
return V_9 -> V_127 -> V_270 >= 0 ;
}
T_5 * F_99 ( T_5 * V_274 )
{
T_14 * V_275 = NULL ;
T_5 * V_27 = NULL ;
if ( V_274 == NULL )
return NULL ;
V_275 = F_100 ( V_274 , NULL ) ;
if ( V_275 == NULL )
goto V_20;
if ( F_101 ( V_275 ) <= 0 )
goto V_20;
if ( F_102 ( V_275 , & V_27 ) <= 0 ) {
F_18 ( V_27 ) ;
V_27 = NULL ;
}
V_20:
F_103 ( V_275 ) ;
return V_27 ;
}
T_5 * F_104 ( int V_5 )
{
T_14 * V_275 = NULL ;
T_5 * V_27 = NULL ;
unsigned int V_276 ;
int V_72 = F_48 ( V_5 , & V_276 ) ;
if ( V_72 == 0 )
goto V_20;
if ( ( V_276 & V_277 ) == V_278 ) {
V_275 = F_105 ( V_72 , NULL ) ;
V_72 = 0 ;
} else {
V_275 = F_105 ( V_279 , NULL ) ;
}
if ( V_275 == NULL )
goto V_20;
if ( F_101 ( V_275 ) <= 0 )
goto V_20;
if ( V_72 != 0 && F_106 ( V_275 , V_72 ) <= 0 )
goto V_20;
if ( F_102 ( V_275 , & V_27 ) <= 0 ) {
F_18 ( V_27 ) ;
V_27 = NULL ;
}
V_20:
F_103 ( V_275 ) ;
return V_27 ;
}
int F_107 ( T_2 * V_9 , T_5 * V_280 , T_5 * V_281 )
{
int V_282 = 0 ;
unsigned char * V_31 = NULL ;
T_7 V_32 = 0 ;
T_14 * V_275 ;
if ( V_280 == NULL || V_281 == NULL )
return 0 ;
V_275 = F_100 ( V_280 , NULL ) ;
if ( F_108 ( V_275 ) <= 0
|| F_109 ( V_275 , V_281 ) <= 0
|| F_110 ( V_275 , NULL , & V_32 ) <= 0 ) {
goto V_20;
}
V_31 = F_75 ( V_32 ) ;
if ( V_31 == NULL )
goto V_20;
if ( F_110 ( V_275 , V_31 , & V_32 ) <= 0 )
goto V_20;
if ( V_9 -> V_119 ) {
V_282 = F_95 ( V_9 , V_31 , V_32 , 1 ) ;
V_31 = NULL ;
} else {
V_9 -> V_19 -> V_26 . V_31 = V_31 ;
V_9 -> V_19 -> V_26 . V_32 = V_32 ;
V_31 = NULL ;
V_282 = 1 ;
}
V_20:
F_21 ( V_31 , V_32 ) ;
F_103 ( V_275 ) ;
return V_282 ;
}
T_5 * F_30 ( T_4 * V_57 )
{
T_5 * V_47 ;
if ( V_57 == NULL )
return NULL ;
V_47 = F_111 () ;
if ( F_112 ( V_47 , V_57 ) <= 0 ) {
F_18 ( V_47 ) ;
return NULL ;
}
return V_47 ;
}

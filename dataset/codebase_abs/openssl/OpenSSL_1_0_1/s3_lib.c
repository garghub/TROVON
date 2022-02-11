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
return ( V_4 -> V_7 -> V_8 . type == V_9 ) ? V_4 -> V_7 -> V_8 . V_10 : 0 ;
}
int F_5 ( T_2 * V_4 )
{
T_3 * V_7 ;
if ( ( V_7 = F_6 ( sizeof *V_7 ) ) == NULL ) goto V_11;
memset ( V_7 , 0 , sizeof *V_7 ) ;
memset ( V_7 -> V_8 . V_12 , 0 , sizeof( V_7 -> V_8 . V_12 ) ) ;
memset ( V_7 -> V_13 . V_12 , 0 , sizeof( V_7 -> V_13 . V_12 ) ) ;
V_4 -> V_7 = V_7 ;
#ifndef F_7
F_8 ( V_4 ) ;
#endif
V_4 -> V_14 -> V_15 ( V_4 ) ;
return ( 1 ) ;
V_11:
return ( 0 ) ;
}
void F_9 ( T_2 * V_4 )
{
if( V_4 == NULL )
return;
#ifdef F_10
if ( V_4 -> V_7 -> V_16 != NULL )
F_11 ( V_4 -> V_7 -> V_16 ) ;
if ( V_4 -> V_7 -> V_17 != NULL )
F_11 ( V_4 -> V_7 -> V_17 ) ;
#endif
F_12 ( V_4 ) ;
if ( V_4 -> V_7 -> V_18 . V_19 != NULL )
F_13 ( V_4 ) ;
if ( V_4 -> V_7 -> V_20 . V_19 != NULL )
F_14 ( V_4 ) ;
if ( V_4 -> V_7 -> V_8 . V_21 != NULL )
F_11 ( V_4 -> V_7 -> V_8 . V_21 ) ;
#ifndef F_15
if ( V_4 -> V_7 -> V_22 . V_23 != NULL )
F_16 ( V_4 -> V_7 -> V_22 . V_23 ) ;
#endif
#ifndef F_17
if ( V_4 -> V_7 -> V_22 . V_24 != NULL )
F_18 ( V_4 -> V_7 -> V_22 . V_24 ) ;
#endif
if ( V_4 -> V_7 -> V_22 . V_25 != NULL )
F_19 ( V_4 -> V_7 -> V_22 . V_25 , V_26 ) ;
if ( V_4 -> V_7 -> V_27 ) {
F_20 ( V_4 -> V_7 -> V_27 ) ;
}
if ( V_4 -> V_7 -> V_28 ) F_21 ( V_4 ) ;
#ifndef F_7
F_22 ( V_4 ) ;
#endif
F_23 ( V_4 -> V_7 , sizeof * V_4 -> V_7 ) ;
F_11 ( V_4 -> V_7 ) ;
V_4 -> V_7 = NULL ;
}
void F_24 ( T_2 * V_4 )
{
unsigned char * V_29 , * V_30 ;
T_4 V_31 , V_32 ;
int V_33 ;
#ifdef F_10
if ( V_4 -> V_7 -> V_16 != NULL )
F_11 ( V_4 -> V_7 -> V_16 ) ;
V_4 -> V_7 -> V_16 = NULL ;
if ( V_4 -> V_7 -> V_17 != NULL )
F_11 ( V_4 -> V_7 -> V_17 ) ;
V_4 -> V_7 -> V_17 = NULL ;
#endif
F_12 ( V_4 ) ;
if ( V_4 -> V_7 -> V_22 . V_25 != NULL )
F_19 ( V_4 -> V_7 -> V_22 . V_25 , V_26 ) ;
if ( V_4 -> V_7 -> V_8 . V_21 != NULL )
{
F_11 ( V_4 -> V_7 -> V_8 . V_21 ) ;
V_4 -> V_7 -> V_8 . V_21 = NULL ;
}
#ifndef F_15
if ( V_4 -> V_7 -> V_22 . V_23 != NULL )
{
F_16 ( V_4 -> V_7 -> V_22 . V_23 ) ;
V_4 -> V_7 -> V_22 . V_23 = NULL ;
}
#endif
#ifndef F_17
if ( V_4 -> V_7 -> V_22 . V_24 != NULL )
{
F_18 ( V_4 -> V_7 -> V_22 . V_24 ) ;
V_4 -> V_7 -> V_22 . V_24 = NULL ;
}
#endif
V_29 = V_4 -> V_7 -> V_18 . V_19 ;
V_30 = V_4 -> V_7 -> V_20 . V_19 ;
V_31 = V_4 -> V_7 -> V_18 . V_34 ;
V_32 = V_4 -> V_7 -> V_20 . V_34 ;
V_33 = V_4 -> V_7 -> V_33 ;
if ( V_4 -> V_7 -> V_27 ) {
F_20 ( V_4 -> V_7 -> V_27 ) ;
V_4 -> V_7 -> V_27 = NULL ;
}
if ( V_4 -> V_7 -> V_28 ) {
F_21 ( V_4 ) ;
}
memset ( V_4 -> V_7 , 0 , sizeof * V_4 -> V_7 ) ;
V_4 -> V_7 -> V_18 . V_19 = V_29 ;
V_4 -> V_7 -> V_20 . V_19 = V_30 ;
V_4 -> V_7 -> V_18 . V_34 = V_31 ;
V_4 -> V_7 -> V_20 . V_34 = V_32 ;
V_4 -> V_7 -> V_33 = V_33 ;
F_25 ( V_4 ) ;
V_4 -> V_35 = 0 ;
V_4 -> V_7 -> V_36 = 0 ;
V_4 -> V_7 -> V_37 = 0 ;
V_4 -> V_7 -> V_38 = 0 ;
V_4 -> V_7 -> V_39 = 0 ;
V_4 -> V_40 = V_41 ;
#if ! F_26 ( V_42 ) && ! F_26 ( V_43 )
if ( V_4 -> V_44 )
{
F_11 ( V_4 -> V_44 ) ;
V_4 -> V_44 = NULL ;
V_4 -> V_45 = 0 ;
}
#endif
}
static char * T_5 F_27 ( T_2 * V_4 , void * V_46 )
{
return F_28 ( V_4 -> V_47 . V_48 ) ;
}
long F_29 ( T_2 * V_4 , int V_49 , long V_50 , void * V_51 )
{
int V_52 = 0 ;
#if ! F_26 ( V_53 ) || ! F_26 ( V_54 )
if (
#ifndef V_54
V_49 == V_55 ||
V_49 == V_56 ||
#endif
#ifndef V_53
V_49 == V_57 ||
V_49 == V_58 ||
#endif
0 )
{
if ( ! F_30 ( & V_4 -> V_59 ) )
{
F_31 ( V_60 , V_61 ) ;
return ( 0 ) ;
}
}
#endif
switch ( V_49 )
{
case V_62 :
V_52 = V_4 -> V_63 ;
break;
case V_64 :
break;
case V_65 :
V_52 = V_4 -> V_7 -> V_38 ;
break;
case V_66 :
V_52 = V_4 -> V_7 -> V_38 ;
V_4 -> V_7 -> V_38 = 0 ;
break;
case V_67 :
V_52 = V_4 -> V_7 -> V_37 ;
break;
case V_68 :
V_52 = ( int ) ( V_4 -> V_7 -> V_69 ) ;
break;
#ifndef V_54
case V_70 :
if ( ( V_4 -> V_59 != NULL ) && ( V_4 -> V_59 -> V_71 == NULL ) &&
( ( V_4 -> V_59 -> V_72 [ V_73 ] . V_74 == NULL ) ||
( F_32 ( V_4 -> V_59 -> V_72 [ V_73 ] . V_74 ) > ( 512 / 8 ) ) ) )
V_52 = 1 ;
break;
case V_55 :
{
T_6 * V_75 = ( T_6 * ) V_51 ;
if ( V_75 == NULL )
{
F_31 ( V_60 , V_76 ) ;
return ( V_52 ) ;
}
if ( ( V_75 = F_33 ( V_75 ) ) == NULL )
{
F_31 ( V_60 , V_77 ) ;
return ( V_52 ) ;
}
if ( V_4 -> V_59 -> V_71 != NULL )
F_34 ( V_4 -> V_59 -> V_71 ) ;
V_4 -> V_59 -> V_71 = V_75 ;
V_52 = 1 ;
}
break;
case V_56 :
{
F_31 ( V_60 , V_78 ) ;
return ( V_52 ) ;
}
break;
#endif
#ifndef F_15
case V_57 :
{
T_7 * V_23 = ( T_7 * ) V_51 ;
if ( V_23 == NULL )
{
F_31 ( V_60 , V_76 ) ;
return ( V_52 ) ;
}
if ( ( V_23 = F_35 ( V_23 ) ) == NULL )
{
F_31 ( V_60 , V_79 ) ;
return ( V_52 ) ;
}
if ( ! ( V_4 -> V_80 & V_81 ) )
{
if ( ! F_36 ( V_23 ) )
{
F_16 ( V_23 ) ;
F_31 ( V_60 , V_79 ) ;
return ( V_52 ) ;
}
}
if ( V_4 -> V_59 -> V_82 != NULL )
F_16 ( V_4 -> V_59 -> V_82 ) ;
V_4 -> V_59 -> V_82 = V_23 ;
V_52 = 1 ;
}
break;
case V_58 :
{
F_31 ( V_60 , V_78 ) ;
return ( V_52 ) ;
}
break;
#endif
#ifndef F_17
case V_83 :
{
T_8 * V_24 = NULL ;
if ( V_51 == NULL )
{
F_31 ( V_60 , V_76 ) ;
return ( V_52 ) ;
}
if ( ! F_37 ( ( T_8 * ) V_51 ) )
{
F_31 ( V_60 , V_84 ) ;
return ( V_52 ) ;
}
V_24 = ( T_8 * ) V_51 ;
if ( ! ( V_4 -> V_80 & V_85 ) )
{
if ( ! F_38 ( V_24 ) )
{
F_18 ( V_24 ) ;
F_31 ( V_60 , V_84 ) ;
return ( V_52 ) ;
}
}
if ( V_4 -> V_59 -> V_86 != NULL )
F_18 ( V_4 -> V_59 -> V_86 ) ;
V_4 -> V_59 -> V_86 = V_24 ;
V_52 = 1 ;
}
break;
case V_87 :
{
F_31 ( V_60 , V_78 ) ;
return ( V_52 ) ;
}
break;
#endif
#ifndef V_42
case V_88 :
if ( V_50 == V_89 )
{
if ( V_4 -> V_90 != NULL )
F_11 ( V_4 -> V_90 ) ;
V_4 -> V_90 = NULL ;
V_52 = 1 ;
if ( V_51 == NULL )
break;
if ( strlen ( ( char * ) V_51 ) > V_91 )
{
F_31 ( V_60 , V_92 ) ;
return 0 ;
}
if ( ( V_4 -> V_90 = F_28 ( ( char * ) V_51 ) ) == NULL )
{
F_31 ( V_60 , V_93 ) ;
return 0 ;
}
}
else
{
F_31 ( V_60 , V_94 ) ;
return 0 ;
}
break;
case V_95 :
V_4 -> V_96 = V_51 ;
V_52 = 1 ;
break;
#ifdef F_10
case V_97 :
if ( V_50 > 12288 )
{
F_31 ( V_60 , V_98 ) ;
break;
}
if ( V_4 -> V_99 != NULL )
F_11 ( V_4 -> V_99 ) ;
if ( ( T_4 ) V_50 == 0 )
V_4 -> V_99 = F_6 ( 1 ) ;
else
V_4 -> V_99 = F_39 ( V_51 , ( T_4 ) V_50 ) ;
if ( V_4 -> V_99 != NULL )
{
V_4 -> V_100 = ( T_4 ) V_50 ;
V_52 = 1 ;
}
else
V_4 -> V_100 = 0 ;
break;
#endif
case V_101 :
V_4 -> V_102 = V_50 ;
V_52 = 1 ;
break;
case V_103 :
* ( F_40 ( V_104 ) * * ) V_51 = V_4 -> V_105 ;
V_52 = 1 ;
break;
case V_106 :
V_4 -> V_105 = V_51 ;
V_52 = 1 ;
break;
case V_107 :
* ( F_40 ( V_108 ) * * ) V_51 = V_4 -> V_109 ;
V_52 = 1 ;
break;
case V_110 :
V_4 -> V_109 = V_51 ;
V_52 = 1 ;
break;
case V_111 :
* ( unsigned char * * ) V_51 = V_4 -> V_112 ;
return V_4 -> V_113 ;
case V_114 :
if ( V_4 -> V_112 )
F_11 ( V_4 -> V_112 ) ;
V_4 -> V_112 = V_51 ;
V_4 -> V_113 = V_50 ;
V_52 = 1 ;
break;
#ifndef F_41
case V_115 :
if ( F_42 ( V_4 ) == V_116 || F_42 ( V_4 ) == V_117 )
V_52 = F_43 ( V_4 ) ;
else
V_52 = F_44 ( V_4 ) ;
break;
case V_118 :
V_52 = V_4 -> V_119 ;
break;
case V_120 :
if ( V_50 )
V_4 -> V_121 |= V_122 ;
else
V_4 -> V_121 &= ~ V_122 ;
V_52 = 1 ;
break;
#endif
#endif
default:
break;
}
return ( V_52 ) ;
}
long F_45 ( T_2 * V_4 , int V_49 , void (* F_46)( void ) )
{
int V_52 = 0 ;
#if ! F_26 ( V_53 ) || ! F_26 ( V_54 )
if (
#ifndef V_54
V_49 == V_56 ||
#endif
#ifndef V_53
V_49 == V_58 ||
#endif
0 )
{
if ( ! F_30 ( & V_4 -> V_59 ) )
{
F_31 ( V_123 , V_61 ) ;
return ( 0 ) ;
}
}
#endif
switch ( V_49 )
{
#ifndef V_54
case V_56 :
{
V_4 -> V_59 -> V_124 = ( T_6 * (*)( T_2 * , int , int ) ) F_46 ;
}
break;
#endif
#ifndef F_15
case V_58 :
{
V_4 -> V_59 -> V_125 = ( T_7 * (*)( T_2 * , int , int ) ) F_46 ;
}
break;
#endif
#ifndef F_17
case V_87 :
{
V_4 -> V_59 -> V_126 = ( T_8 * (*)( T_2 * , int , int ) ) F_46 ;
}
break;
#endif
#ifndef V_42
case V_127 :
V_4 -> V_128 = ( void (*) ( T_2 * , int , int ,
unsigned char * , int , void * ) ) F_46 ;
break;
#endif
default:
break;
}
return ( V_52 ) ;
}
long F_47 ( T_9 * V_129 , int V_49 , long V_50 , void * V_51 )
{
T_10 * V_59 ;
V_59 = V_129 -> V_59 ;
switch ( V_49 )
{
#ifndef V_54
case V_70 :
if ( ( V_59 -> V_71 == NULL ) &&
( ( V_59 -> V_72 [ V_73 ] . V_74 == NULL ) ||
( F_32 ( V_59 -> V_72 [ V_73 ] . V_74 ) > ( 512 / 8 ) ) )
)
return ( 1 ) ;
else
return ( 0 ) ;
case V_55 :
{
T_6 * V_75 ;
int V_130 ;
V_75 = ( T_6 * ) V_51 ;
V_130 = 1 ;
if ( V_75 == NULL )
V_130 = 0 ;
else
{
if ( ( V_75 = F_33 ( V_75 ) ) == NULL )
V_130 = 0 ;
}
if ( ! V_130 )
{
F_31 ( V_131 , V_77 ) ;
return ( 0 ) ;
}
else
{
if ( V_59 -> V_71 != NULL )
F_34 ( V_59 -> V_71 ) ;
V_59 -> V_71 = V_75 ;
return ( 1 ) ;
}
}
case V_56 :
{
F_31 ( V_131 , V_78 ) ;
return ( 0 ) ;
}
break;
#endif
#ifndef F_15
case V_57 :
{
T_7 * V_132 = NULL , * V_23 ;
V_23 = ( T_7 * ) V_51 ;
if ( ( V_132 = F_35 ( V_23 ) ) == NULL )
{
F_31 ( V_131 , V_79 ) ;
return 0 ;
}
if ( ! ( V_129 -> V_80 & V_81 ) )
{
if ( ! F_36 ( V_132 ) )
{
F_31 ( V_131 , V_79 ) ;
F_16 ( V_132 ) ;
return 0 ;
}
}
if ( V_59 -> V_82 != NULL )
F_16 ( V_59 -> V_82 ) ;
V_59 -> V_82 = V_132 ;
return 1 ;
}
case V_58 :
{
F_31 ( V_131 , V_78 ) ;
return ( 0 ) ;
}
break;
#endif
#ifndef F_17
case V_83 :
{
T_8 * V_24 = NULL ;
if ( V_51 == NULL )
{
F_31 ( V_131 , V_84 ) ;
return 0 ;
}
V_24 = F_48 ( ( T_8 * ) V_51 ) ;
if ( V_24 == NULL )
{
F_31 ( V_131 , V_133 ) ;
return 0 ;
}
if ( ! ( V_129 -> V_80 & V_85 ) )
{
if ( ! F_38 ( V_24 ) )
{
F_18 ( V_24 ) ;
F_31 ( V_131 , V_84 ) ;
return 0 ;
}
}
if ( V_59 -> V_86 != NULL )
{
F_18 ( V_59 -> V_86 ) ;
}
V_59 -> V_86 = V_24 ;
return 1 ;
}
case V_87 :
{
F_31 ( V_131 , V_78 ) ;
return ( 0 ) ;
}
break;
#endif
#ifndef V_42
case V_134 :
V_129 -> V_135 = V_51 ;
break;
case V_136 :
case V_137 :
{
unsigned char * V_138 = V_51 ;
if ( ! V_138 )
return 48 ;
if ( V_50 != 48 )
{
F_31 ( V_131 , V_139 ) ;
return 0 ;
}
if ( V_49 == V_136 )
{
memcpy ( V_129 -> V_140 , V_138 , 16 ) ;
memcpy ( V_129 -> V_141 , V_138 + 16 , 16 ) ;
memcpy ( V_129 -> V_142 , V_138 + 32 , 16 ) ;
}
else
{
memcpy ( V_138 , V_129 -> V_140 , 16 ) ;
memcpy ( V_138 + 16 , V_129 -> V_141 , 16 ) ;
memcpy ( V_138 + 32 , V_129 -> V_142 , 16 ) ;
}
return 1 ;
}
#ifdef F_10
case V_143 :
V_129 -> V_144 = V_51 ;
return 1 ;
#endif
case V_145 :
V_129 -> V_146 = V_51 ;
return 1 ;
break;
#ifndef F_7
case V_147 :
V_129 -> V_47 . V_148 |= V_149 ;
if ( V_129 -> V_47 . V_150 != NULL )
F_11 ( V_129 -> V_47 . V_150 ) ;
V_129 -> V_47 . V_150 = NULL ;
if ( V_51 == NULL )
break;
if ( strlen ( ( const char * ) V_51 ) > 255 || strlen ( ( const char * ) V_51 ) < 1 )
{
F_31 ( V_131 , V_151 ) ;
return 0 ;
}
if ( ( V_129 -> V_47 . V_150 = F_28 ( ( char * ) V_51 ) ) == NULL )
{
F_31 ( V_131 , V_93 ) ;
return 0 ;
}
break;
case V_152 :
V_129 -> V_47 . V_153 = F_27 ;
V_129 -> V_47 . V_48 = V_51 ;
break;
case V_154 :
V_129 -> V_47 . V_148 |= V_149 ;
V_129 -> V_47 . V_155 = V_51 ;
break;
case V_156 :
V_129 -> V_47 . V_157 = V_50 ;
break;
#endif
#endif
case V_158 :
if ( V_129 -> V_159 == NULL )
{
if ( ( V_129 -> V_159 = F_49 () ) == NULL )
return ( 0 ) ;
}
F_50 ( V_129 -> V_159 , ( V_160 * ) V_51 ) ;
break;
case V_161 :
* ( F_40 ( V_160 ) * * ) V_51 = V_129 -> V_159 ;
break;
case V_162 :
if ( V_129 -> V_159 )
{
F_51 ( V_129 -> V_159 , V_163 ) ;
V_129 -> V_159 = NULL ;
}
break;
default:
return ( 0 ) ;
}
return ( 1 ) ;
}
long F_52 ( T_9 * V_129 , int V_49 , void (* F_46)( void ) )
{
T_10 * V_59 ;
V_59 = V_129 -> V_59 ;
switch ( V_49 )
{
#ifndef V_54
case V_56 :
{
V_59 -> V_124 = ( T_6 * (*)( T_2 * , int , int ) ) F_46 ;
}
break;
#endif
#ifndef F_15
case V_58 :
{
V_59 -> V_125 = ( T_7 * (*)( T_2 * , int , int ) ) F_46 ;
}
break;
#endif
#ifndef F_17
case V_87 :
{
V_59 -> V_126 = ( T_8 * (*)( T_2 * , int , int ) ) F_46 ;
}
break;
#endif
#ifndef V_42
case V_164 :
V_129 -> V_165 = ( int ( * ) ( T_2 * , int * , void * ) ) F_46 ;
break;
#ifdef F_10
case V_166 :
V_129 -> V_167 = ( int ( * ) ( T_2 * , void * , T_4 , void * ) ) F_46 ;
break;
#endif
case V_168 :
V_129 -> V_169 = ( int ( * ) ( T_2 * , void * ) ) F_46 ;
break;
case V_170 :
V_129 -> V_171 = ( int (*) ( T_2 * , unsigned char * ,
unsigned char * ,
V_172 * ,
V_173 * , int ) ) F_46 ;
break;
#ifndef F_7
case V_174 :
V_129 -> V_47 . V_148 |= V_149 ;
V_129 -> V_47 . V_175 = ( int ( * ) ( T_2 * , void * ) ) F_46 ;
break;
case V_176 :
V_129 -> V_47 . V_148 |= V_149 ;
V_129 -> V_47 . V_177 = ( int ( * ) ( T_2 * , int * , void * ) ) F_46 ;
break;
case V_178 :
V_129 -> V_47 . V_148 |= V_149 ;
V_129 -> V_47 . V_153 = ( char * (*)( T_2 * , void * ) ) F_46 ;
break;
#endif
#endif
default:
return ( 0 ) ;
}
return ( 1 ) ;
}
const T_1 * F_53 ( const unsigned char * V_179 )
{
T_1 V_180 ;
const T_1 * V_181 ;
unsigned long V_182 ;
V_182 = 0x03000000L | ( ( unsigned long ) V_179 [ 0 ] << 8L ) | ( unsigned long ) V_179 [ 1 ] ;
V_180 . V_182 = V_182 ;
V_181 = F_54 ( & V_180 , V_3 , V_1 ) ;
#ifdef F_55
if ( V_181 == NULL ) fprintf ( V_183 , L_1 , ( V_179 [ 0 ] << 8 ) | V_179 [ 1 ] ) ;
#endif
if ( V_181 == NULL || V_181 -> V_184 == 0 )
return NULL ;
else
return V_181 ;
}
int F_56 ( const T_1 * V_180 , unsigned char * V_179 )
{
long V_185 ;
if ( V_179 != NULL )
{
V_185 = V_180 -> V_182 ;
if ( ( V_185 & 0xff000000 ) != 0x03000000 ) return ( 0 ) ;
V_179 [ 0 ] = ( ( unsigned char ) ( V_185 >> 8L ) ) & 0xFF ;
V_179 [ 1 ] = ( ( unsigned char ) ( V_185 ) ) & 0xFF ;
}
return ( 2 ) ;
}
int F_57 ( T_2 * V_4 , unsigned char * V_179 )
{
int V_52 = 0 ;
unsigned long V_186 ;
V_186 = V_4 -> V_7 -> V_22 . V_187 -> V_188 ;
#ifndef F_58
if ( V_4 -> V_40 >= V_189 )
{
if ( V_186 & V_190 )
{
V_179 [ V_52 ++ ] = V_191 ;
V_179 [ V_52 ++ ] = V_192 ;
return ( V_52 ) ;
}
}
#endif
#ifndef F_15
if ( V_186 & ( V_193 | V_194 ) )
{
# ifndef V_54
V_179 [ V_52 ++ ] = V_195 ;
# endif
# ifndef V_53
V_179 [ V_52 ++ ] = V_196 ;
# endif
}
if ( ( V_4 -> V_40 == V_41 ) &&
( V_186 & ( V_194 | V_197 | V_193 ) ) )
{
# ifndef V_54
V_179 [ V_52 ++ ] = V_198 ;
# endif
# ifndef V_53
V_179 [ V_52 ++ ] = V_199 ;
# endif
}
#endif
#ifndef V_54
V_179 [ V_52 ++ ] = V_200 ;
#endif
#ifndef V_53
V_179 [ V_52 ++ ] = V_201 ;
#endif
#ifndef F_17
if ( ( V_186 & ( V_202 | V_203 ) ) && ( V_4 -> V_40 >= V_189 ) )
{
V_179 [ V_52 ++ ] = V_204 ;
V_179 [ V_52 ++ ] = V_205 ;
}
#endif
#ifndef F_59
if ( V_4 -> V_40 >= V_189 )
{
V_179 [ V_52 ++ ] = V_206 ;
}
#endif
return ( V_52 ) ;
}
int F_60 ( T_2 * V_4 )
{
int V_52 ;
if ( ( V_4 -> V_207 ) || ( V_4 -> V_208 == V_209 ) )
{
V_4 -> V_210 = ( V_211 | V_212 ) ;
return ( 1 ) ;
}
if ( ! ( V_4 -> V_210 & V_211 ) )
{
V_4 -> V_210 |= V_211 ;
#if 1
F_61 ( V_4 , V_213 , V_214 ) ;
#endif
if ( V_4 -> V_7 -> V_215 )
return ( - 1 ) ;
}
else if ( V_4 -> V_7 -> V_215 )
{
#if 1
V_52 = V_4 -> V_14 -> V_216 ( V_4 ) ;
if( V_52 == - 1 )
{
return ( V_52 ) ;
}
#endif
}
else if ( ! ( V_4 -> V_210 & V_212 ) )
{
V_4 -> V_14 -> V_217 ( V_4 , 0 , NULL , 0 , 0 ) ;
if( ! ( V_4 -> V_210 & V_212 ) )
{
return ( - 1 ) ;
}
}
if ( ( V_4 -> V_210 == ( V_211 | V_212 ) ) &&
! V_4 -> V_7 -> V_215 )
return ( 1 ) ;
else
return ( 0 ) ;
}
int F_62 ( T_2 * V_4 , const void * V_19 , int V_34 )
{
int V_52 , V_218 ;
#if 0
if (s->shutdown & SSL_SEND_SHUTDOWN)
{
s->rwstate=SSL_NOTHING;
return(0);
}
#endif
F_63 () ;
if ( V_4 -> V_7 -> V_36 ) F_64 ( V_4 ) ;
if ( ( V_4 -> V_7 -> V_69 & V_219 ) && ( V_4 -> V_220 == V_4 -> V_221 ) )
{
if ( V_4 -> V_7 -> V_222 == 0 )
{
V_52 = F_65 ( V_4 , V_9 ,
V_19 , V_34 ) ;
if ( V_52 <= 0 ) return ( V_52 ) ;
V_4 -> V_7 -> V_222 = V_52 ;
}
V_4 -> V_223 = V_224 ;
V_218 = F_66 ( V_4 -> V_220 ) ;
if ( V_218 <= 0 ) return ( V_218 ) ;
V_4 -> V_223 = V_225 ;
F_25 ( V_4 ) ;
V_4 -> V_7 -> V_69 &= ~ V_219 ;
V_52 = V_4 -> V_7 -> V_222 ;
V_4 -> V_7 -> V_222 = 0 ;
}
else
{
V_52 = V_4 -> V_14 -> V_226 ( V_4 , V_9 ,
V_19 , V_34 ) ;
if ( V_52 <= 0 ) return ( V_52 ) ;
}
return ( V_52 ) ;
}
static int F_67 ( T_2 * V_4 , void * V_19 , int V_34 , int V_227 )
{
int V_52 ;
F_63 () ;
if ( V_4 -> V_7 -> V_36 ) F_64 ( V_4 ) ;
V_4 -> V_7 -> V_39 = 1 ;
V_52 = V_4 -> V_14 -> V_217 ( V_4 , V_9 , V_19 , V_34 , V_227 ) ;
if ( ( V_52 == - 1 ) && ( V_4 -> V_7 -> V_39 == 2 ) )
{
V_4 -> V_228 ++ ;
V_52 = V_4 -> V_14 -> V_217 ( V_4 , V_9 , V_19 , V_34 , V_227 ) ;
V_4 -> V_228 -- ;
}
else
V_4 -> V_7 -> V_39 = 0 ;
return ( V_52 ) ;
}
int F_68 ( T_2 * V_4 , void * V_19 , int V_34 )
{
return F_67 ( V_4 , V_19 , V_34 , 0 ) ;
}
int F_69 ( T_2 * V_4 , void * V_19 , int V_34 )
{
return F_67 ( V_4 , V_19 , V_34 , 1 ) ;
}
int F_70 ( T_2 * V_4 )
{
if ( V_4 -> V_229 == NULL )
return ( 1 ) ;
if ( V_4 -> V_7 -> V_69 & V_230 )
return ( 0 ) ;
V_4 -> V_7 -> V_36 = 1 ;
return ( 1 ) ;
}
int F_64 ( T_2 * V_4 )
{
int V_52 = 0 ;
if ( V_4 -> V_7 -> V_36 )
{
if ( ( V_4 -> V_7 -> V_18 . V_231 == 0 ) &&
( V_4 -> V_7 -> V_20 . V_231 == 0 ) &&
! F_71 ( V_4 ) )
{
V_4 -> V_208 = V_232 ;
V_4 -> V_7 -> V_36 = 0 ;
V_4 -> V_7 -> V_38 ++ ;
V_4 -> V_7 -> V_37 ++ ;
V_52 = 1 ;
}
}
return ( V_52 ) ;
}
long F_72 ( T_2 * V_4 )
{
long V_233 = V_4 -> V_7 -> V_22 . V_187 -> V_234 ;
if ( F_73 ( V_4 ) >= V_235 &&
V_233 == ( V_236 | V_237 ) )
return V_238 | V_239 ;
return V_233 ;
}

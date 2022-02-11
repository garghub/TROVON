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
V_4 -> V_14 -> V_15 ( V_4 ) ;
return ( 1 ) ;
V_11:
return ( 0 ) ;
}
void F_7 ( T_2 * V_4 )
{
if( V_4 == NULL )
return;
#ifdef F_8
if ( V_4 -> V_7 -> V_16 != NULL )
F_9 ( V_4 -> V_7 -> V_16 ) ;
if ( V_4 -> V_7 -> V_17 != NULL )
F_9 ( V_4 -> V_7 -> V_17 ) ;
#endif
F_10 ( V_4 ) ;
if ( V_4 -> V_7 -> V_18 . V_19 != NULL )
F_11 ( V_4 ) ;
if ( V_4 -> V_7 -> V_20 . V_19 != NULL )
F_12 ( V_4 ) ;
if ( V_4 -> V_7 -> V_8 . V_21 != NULL )
F_9 ( V_4 -> V_7 -> V_8 . V_21 ) ;
#ifndef F_13
if ( V_4 -> V_7 -> V_22 . V_23 != NULL )
F_14 ( V_4 -> V_7 -> V_22 . V_23 ) ;
#endif
#ifndef F_15
if ( V_4 -> V_7 -> V_22 . V_24 != NULL )
F_16 ( V_4 -> V_7 -> V_22 . V_24 ) ;
#endif
if ( V_4 -> V_7 -> V_22 . V_25 != NULL )
F_17 ( V_4 -> V_7 -> V_22 . V_25 , V_26 ) ;
if ( V_4 -> V_7 -> V_27 ) {
F_18 ( V_4 -> V_7 -> V_27 ) ;
}
if ( V_4 -> V_7 -> V_28 ) F_19 ( V_4 ) ;
F_20 ( V_4 -> V_7 , sizeof * V_4 -> V_7 ) ;
F_9 ( V_4 -> V_7 ) ;
V_4 -> V_7 = NULL ;
}
void F_21 ( T_2 * V_4 )
{
unsigned char * V_29 , * V_30 ;
T_4 V_31 , V_32 ;
#ifdef F_8
if ( V_4 -> V_7 -> V_16 != NULL )
F_9 ( V_4 -> V_7 -> V_16 ) ;
V_4 -> V_7 -> V_16 = NULL ;
if ( V_4 -> V_7 -> V_17 != NULL )
F_9 ( V_4 -> V_7 -> V_17 ) ;
V_4 -> V_7 -> V_17 = NULL ;
#endif
F_10 ( V_4 ) ;
if ( V_4 -> V_7 -> V_22 . V_25 != NULL )
F_17 ( V_4 -> V_7 -> V_22 . V_25 , V_26 ) ;
if ( V_4 -> V_7 -> V_8 . V_21 != NULL )
{
F_9 ( V_4 -> V_7 -> V_8 . V_21 ) ;
V_4 -> V_7 -> V_8 . V_21 = NULL ;
}
#ifndef F_13
if ( V_4 -> V_7 -> V_22 . V_23 != NULL )
F_14 ( V_4 -> V_7 -> V_22 . V_23 ) ;
#endif
#ifndef F_15
if ( V_4 -> V_7 -> V_22 . V_24 != NULL )
F_16 ( V_4 -> V_7 -> V_22 . V_24 ) ;
#endif
V_29 = V_4 -> V_7 -> V_18 . V_19 ;
V_30 = V_4 -> V_7 -> V_20 . V_19 ;
V_31 = V_4 -> V_7 -> V_18 . V_33 ;
V_32 = V_4 -> V_7 -> V_20 . V_33 ;
if ( V_4 -> V_7 -> V_27 ) {
F_18 ( V_4 -> V_7 -> V_27 ) ;
V_4 -> V_7 -> V_27 = NULL ;
}
if ( V_4 -> V_7 -> V_28 ) {
F_19 ( V_4 ) ;
}
memset ( V_4 -> V_7 , 0 , sizeof * V_4 -> V_7 ) ;
V_4 -> V_7 -> V_18 . V_19 = V_29 ;
V_4 -> V_7 -> V_20 . V_19 = V_30 ;
V_4 -> V_7 -> V_18 . V_33 = V_31 ;
V_4 -> V_7 -> V_20 . V_33 = V_32 ;
F_22 ( V_4 ) ;
V_4 -> V_34 = 0 ;
V_4 -> V_7 -> V_35 = 0 ;
V_4 -> V_7 -> V_36 = 0 ;
V_4 -> V_7 -> V_37 = 0 ;
V_4 -> V_7 -> V_38 = 0 ;
V_4 -> V_39 = V_40 ;
}
long F_23 ( T_2 * V_4 , int V_41 , long V_42 , void * V_43 )
{
int V_44 = 0 ;
#if ! F_24 ( V_45 ) || ! F_24 ( V_46 )
if (
#ifndef V_46
V_41 == V_47 ||
V_41 == V_48 ||
#endif
#ifndef V_45
V_41 == V_49 ||
V_41 == V_50 ||
#endif
0 )
{
if ( ! F_25 ( & V_4 -> V_51 ) )
{
F_26 ( V_52 , V_53 ) ;
return ( 0 ) ;
}
}
#endif
switch ( V_41 )
{
case V_54 :
V_44 = V_4 -> V_55 ;
break;
case V_56 :
break;
case V_57 :
V_44 = V_4 -> V_7 -> V_37 ;
break;
case V_58 :
V_44 = V_4 -> V_7 -> V_37 ;
V_4 -> V_7 -> V_37 = 0 ;
break;
case V_59 :
V_44 = V_4 -> V_7 -> V_36 ;
break;
case V_60 :
V_44 = ( int ) ( V_4 -> V_7 -> V_61 ) ;
break;
#ifndef V_46
case V_62 :
if ( ( V_4 -> V_51 != NULL ) && ( V_4 -> V_51 -> V_63 == NULL ) &&
( ( V_4 -> V_51 -> V_64 [ V_65 ] . V_66 == NULL ) ||
( F_27 ( V_4 -> V_51 -> V_64 [ V_65 ] . V_66 ) > ( 512 / 8 ) ) ) )
V_44 = 1 ;
break;
case V_47 :
{
T_5 * V_67 = ( T_5 * ) V_43 ;
if ( V_67 == NULL )
{
F_26 ( V_52 , V_68 ) ;
return ( V_44 ) ;
}
if ( ( V_67 = F_28 ( V_67 ) ) == NULL )
{
F_26 ( V_52 , V_69 ) ;
return ( V_44 ) ;
}
if ( V_4 -> V_51 -> V_63 != NULL )
F_29 ( V_4 -> V_51 -> V_63 ) ;
V_4 -> V_51 -> V_63 = V_67 ;
V_44 = 1 ;
}
break;
case V_48 :
{
F_26 ( V_52 , V_70 ) ;
return ( V_44 ) ;
}
break;
#endif
#ifndef F_13
case V_49 :
{
T_6 * V_23 = ( T_6 * ) V_43 ;
if ( V_23 == NULL )
{
F_26 ( V_52 , V_68 ) ;
return ( V_44 ) ;
}
if ( ( V_23 = F_30 ( V_23 ) ) == NULL )
{
F_26 ( V_52 , V_71 ) ;
return ( V_44 ) ;
}
if ( ! ( V_4 -> V_72 & V_73 ) )
{
if ( ! F_31 ( V_23 ) )
{
F_14 ( V_23 ) ;
F_26 ( V_52 , V_71 ) ;
return ( V_44 ) ;
}
}
if ( V_4 -> V_51 -> V_74 != NULL )
F_14 ( V_4 -> V_51 -> V_74 ) ;
V_4 -> V_51 -> V_74 = V_23 ;
V_44 = 1 ;
}
break;
case V_50 :
{
F_26 ( V_52 , V_70 ) ;
return ( V_44 ) ;
}
break;
#endif
#ifndef F_15
case V_75 :
{
T_7 * V_24 = NULL ;
if ( V_43 == NULL )
{
F_26 ( V_52 , V_68 ) ;
return ( V_44 ) ;
}
if ( ! F_32 ( ( T_7 * ) V_43 ) )
{
F_26 ( V_52 , V_76 ) ;
return ( V_44 ) ;
}
V_24 = ( T_7 * ) V_43 ;
if ( ! ( V_4 -> V_72 & V_77 ) )
{
if ( ! F_33 ( V_24 ) )
{
F_16 ( V_24 ) ;
F_26 ( V_52 , V_76 ) ;
return ( V_44 ) ;
}
}
if ( V_4 -> V_51 -> V_78 != NULL )
F_16 ( V_4 -> V_51 -> V_78 ) ;
V_4 -> V_51 -> V_78 = V_24 ;
V_44 = 1 ;
}
break;
case V_79 :
{
F_26 ( V_52 , V_70 ) ;
return ( V_44 ) ;
}
break;
#endif
#ifndef F_34
case V_80 :
if ( V_42 == V_81 )
{
if ( V_4 -> V_82 != NULL )
F_9 ( V_4 -> V_82 ) ;
V_4 -> V_82 = NULL ;
V_44 = 1 ;
if ( V_43 == NULL )
break;
if ( strlen ( ( char * ) V_43 ) > V_83 )
{
F_26 ( V_52 , V_84 ) ;
return 0 ;
}
if ( ( V_4 -> V_82 = F_35 ( ( char * ) V_43 ) ) == NULL )
{
F_26 ( V_52 , V_85 ) ;
return 0 ;
}
}
else
{
F_26 ( V_52 , V_86 ) ;
return 0 ;
}
break;
case V_87 :
V_4 -> V_88 = V_43 ;
V_44 = 1 ;
break;
#ifdef F_8
case V_89 :
if ( V_42 > 12288 )
{
F_26 ( V_52 , V_90 ) ;
break;
}
if ( V_4 -> V_91 != NULL )
F_9 ( V_4 -> V_91 ) ;
if ( ( T_4 ) V_42 == 0 )
V_4 -> V_91 = F_6 ( 1 ) ;
else
V_4 -> V_91 = F_36 ( V_43 , ( T_4 ) V_42 ) ;
if ( V_4 -> V_91 != NULL )
{
V_4 -> V_92 = ( T_4 ) V_42 ;
V_44 = 1 ;
}
else
V_4 -> V_92 = 0 ;
break;
#endif
case V_93 :
V_4 -> V_94 = V_42 ;
V_44 = 1 ;
break;
case V_95 :
* ( F_37 ( V_96 ) * * ) V_43 = V_4 -> V_97 ;
V_44 = 1 ;
break;
case V_98 :
V_4 -> V_97 = V_43 ;
V_44 = 1 ;
break;
case V_99 :
* ( F_37 ( V_100 ) * * ) V_43 = V_4 -> V_101 ;
V_44 = 1 ;
break;
case V_102 :
V_4 -> V_101 = V_43 ;
V_44 = 1 ;
break;
case V_103 :
* ( unsigned char * * ) V_43 = V_4 -> V_104 ;
return V_4 -> V_105 ;
case V_106 :
if ( V_4 -> V_104 )
F_9 ( V_4 -> V_104 ) ;
V_4 -> V_104 = V_43 ;
V_4 -> V_105 = V_42 ;
V_44 = 1 ;
break;
#endif
default:
break;
}
return ( V_44 ) ;
}
long F_38 ( T_2 * V_4 , int V_41 , void (* F_39)( void ) )
{
int V_44 = 0 ;
#if ! F_24 ( V_45 ) || ! F_24 ( V_46 )
if (
#ifndef V_46
V_41 == V_48 ||
#endif
#ifndef V_45
V_41 == V_50 ||
#endif
0 )
{
if ( ! F_25 ( & V_4 -> V_51 ) )
{
F_26 ( V_107 , V_53 ) ;
return ( 0 ) ;
}
}
#endif
switch ( V_41 )
{
#ifndef V_46
case V_48 :
{
V_4 -> V_51 -> V_108 = ( T_5 * (*)( T_2 * , int , int ) ) F_39 ;
}
break;
#endif
#ifndef F_13
case V_50 :
{
V_4 -> V_51 -> V_109 = ( T_6 * (*)( T_2 * , int , int ) ) F_39 ;
}
break;
#endif
#ifndef F_15
case V_79 :
{
V_4 -> V_51 -> V_110 = ( T_7 * (*)( T_2 * , int , int ) ) F_39 ;
}
break;
#endif
#ifndef F_34
case V_111 :
V_4 -> V_112 = ( void (*) ( T_2 * , int , int ,
unsigned char * , int , void * ) ) F_39 ;
break;
#endif
default:
break;
}
return ( V_44 ) ;
}
long F_40 ( T_8 * V_113 , int V_41 , long V_42 , void * V_43 )
{
T_9 * V_51 ;
V_51 = V_113 -> V_51 ;
switch ( V_41 )
{
#ifndef V_46
case V_62 :
if ( ( V_51 -> V_63 == NULL ) &&
( ( V_51 -> V_64 [ V_65 ] . V_66 == NULL ) ||
( F_27 ( V_51 -> V_64 [ V_65 ] . V_66 ) > ( 512 / 8 ) ) )
)
return ( 1 ) ;
else
return ( 0 ) ;
case V_47 :
{
T_5 * V_67 ;
int V_114 ;
V_67 = ( T_5 * ) V_43 ;
V_114 = 1 ;
if ( V_67 == NULL )
V_114 = 0 ;
else
{
if ( ( V_67 = F_28 ( V_67 ) ) == NULL )
V_114 = 0 ;
}
if ( ! V_114 )
{
F_26 ( V_115 , V_69 ) ;
return ( 0 ) ;
}
else
{
if ( V_51 -> V_63 != NULL )
F_29 ( V_51 -> V_63 ) ;
V_51 -> V_63 = V_67 ;
return ( 1 ) ;
}
}
case V_48 :
{
F_26 ( V_115 , V_70 ) ;
return ( 0 ) ;
}
break;
#endif
#ifndef F_13
case V_49 :
{
T_6 * V_116 = NULL , * V_23 ;
V_23 = ( T_6 * ) V_43 ;
if ( ( V_116 = F_30 ( V_23 ) ) == NULL )
{
F_26 ( V_115 , V_71 ) ;
return 0 ;
}
if ( ! ( V_113 -> V_72 & V_73 ) )
{
if ( ! F_31 ( V_116 ) )
{
F_26 ( V_115 , V_71 ) ;
F_14 ( V_116 ) ;
return 0 ;
}
}
if ( V_51 -> V_74 != NULL )
F_14 ( V_51 -> V_74 ) ;
V_51 -> V_74 = V_116 ;
return 1 ;
}
case V_50 :
{
F_26 ( V_115 , V_70 ) ;
return ( 0 ) ;
}
break;
#endif
#ifndef F_15
case V_75 :
{
T_7 * V_24 = NULL ;
if ( V_43 == NULL )
{
F_26 ( V_115 , V_76 ) ;
return 0 ;
}
V_24 = F_41 ( ( T_7 * ) V_43 ) ;
if ( V_24 == NULL )
{
F_26 ( V_115 , V_117 ) ;
return 0 ;
}
if ( ! ( V_113 -> V_72 & V_77 ) )
{
if ( ! F_33 ( V_24 ) )
{
F_16 ( V_24 ) ;
F_26 ( V_115 , V_76 ) ;
return 0 ;
}
}
if ( V_51 -> V_78 != NULL )
{
F_16 ( V_51 -> V_78 ) ;
}
V_51 -> V_78 = V_24 ;
return 1 ;
}
case V_79 :
{
F_26 ( V_115 , V_70 ) ;
return ( 0 ) ;
}
break;
#endif
#ifndef F_34
case V_118 :
V_113 -> V_119 = V_43 ;
break;
case V_120 :
case V_121 :
{
unsigned char * V_122 = V_43 ;
if ( ! V_122 )
return 48 ;
if ( V_42 != 48 )
{
F_26 ( V_115 , V_123 ) ;
return 0 ;
}
if ( V_41 == V_120 )
{
memcpy ( V_113 -> V_124 , V_122 , 16 ) ;
memcpy ( V_113 -> V_125 , V_122 + 16 , 16 ) ;
memcpy ( V_113 -> V_126 , V_122 + 32 , 16 ) ;
}
else
{
memcpy ( V_122 , V_113 -> V_124 , 16 ) ;
memcpy ( V_122 + 16 , V_113 -> V_125 , 16 ) ;
memcpy ( V_122 + 32 , V_113 -> V_126 , 16 ) ;
}
return 1 ;
}
#ifdef F_8
case V_127 :
V_113 -> V_128 = V_43 ;
return 1 ;
#endif
case V_129 :
V_113 -> V_130 = V_43 ;
return 1 ;
break;
#endif
case V_131 :
if ( V_113 -> V_132 == NULL )
{
if ( ( V_113 -> V_132 = F_42 () ) == NULL )
return ( 0 ) ;
}
F_43 ( V_113 -> V_132 , ( V_133 * ) V_43 ) ;
break;
default:
return ( 0 ) ;
}
return ( 1 ) ;
}
long F_44 ( T_8 * V_113 , int V_41 , void (* F_39)( void ) )
{
T_9 * V_51 ;
V_51 = V_113 -> V_51 ;
switch ( V_41 )
{
#ifndef V_46
case V_48 :
{
V_51 -> V_108 = ( T_5 * (*)( T_2 * , int , int ) ) F_39 ;
}
break;
#endif
#ifndef F_13
case V_50 :
{
V_51 -> V_109 = ( T_6 * (*)( T_2 * , int , int ) ) F_39 ;
}
break;
#endif
#ifndef F_15
case V_79 :
{
V_51 -> V_110 = ( T_7 * (*)( T_2 * , int , int ) ) F_39 ;
}
break;
#endif
#ifndef F_34
case V_134 :
V_113 -> V_135 = ( int ( * ) ( T_2 * , int * , void * ) ) F_39 ;
break;
#ifdef F_8
case V_136 :
V_113 -> V_137 = ( int ( * ) ( T_2 * , void * , T_4 , void * ) ) F_39 ;
break;
#endif
case V_138 :
V_113 -> V_139 = ( int ( * ) ( T_2 * , void * ) ) F_39 ;
break;
case V_140 :
V_113 -> V_141 = ( int (*) ( T_2 * , unsigned char * ,
unsigned char * ,
V_142 * ,
V_143 * , int ) ) F_39 ;
break;
#endif
default:
return ( 0 ) ;
}
return ( 1 ) ;
}
const T_1 * F_45 ( const unsigned char * V_144 )
{
T_1 V_145 ;
const T_1 * V_146 ;
unsigned long V_147 ;
V_147 = 0x03000000L | ( ( unsigned long ) V_144 [ 0 ] << 8L ) | ( unsigned long ) V_144 [ 1 ] ;
V_145 . V_147 = V_147 ;
V_146 = F_46 ( & V_145 , V_3 , V_1 ) ;
if ( V_146 == NULL || V_146 -> V_148 == 0 )
return NULL ;
else
return V_146 ;
}
int F_47 ( const T_1 * V_145 , unsigned char * V_144 )
{
long V_149 ;
if ( V_144 != NULL )
{
V_149 = V_145 -> V_147 ;
if ( ( V_149 & 0xff000000 ) != 0x03000000 ) return ( 0 ) ;
V_144 [ 0 ] = ( ( unsigned char ) ( V_149 >> 8L ) ) & 0xFF ;
V_144 [ 1 ] = ( ( unsigned char ) ( V_149 ) ) & 0xFF ;
}
return ( 2 ) ;
}
int F_48 ( T_2 * V_4 , unsigned char * V_144 )
{
int V_44 = 0 ;
unsigned long V_150 ;
V_150 = V_4 -> V_7 -> V_22 . V_151 -> V_152 ;
#ifndef F_49
if ( V_4 -> V_39 >= V_153 )
{
if ( V_150 & V_154 )
{
V_144 [ V_44 ++ ] = V_155 ;
V_144 [ V_44 ++ ] = V_156 ;
return ( V_44 ) ;
}
}
#endif
#ifndef F_13
if ( V_150 & ( V_157 | V_158 ) )
{
# ifndef V_46
V_144 [ V_44 ++ ] = V_159 ;
# endif
# ifndef V_45
V_144 [ V_44 ++ ] = V_160 ;
# endif
}
if ( ( V_4 -> V_39 == V_40 ) &&
( V_150 & ( V_158 | V_161 | V_157 ) ) )
{
# ifndef V_46
V_144 [ V_44 ++ ] = V_162 ;
# endif
# ifndef V_45
V_144 [ V_44 ++ ] = V_163 ;
# endif
}
#endif
#ifndef V_46
V_144 [ V_44 ++ ] = V_164 ;
#endif
#ifndef V_45
V_144 [ V_44 ++ ] = V_165 ;
#endif
#ifndef F_15
if ( ( V_150 & ( V_166 | V_167 ) ) && ( V_4 -> V_39 >= V_153 ) )
{
V_144 [ V_44 ++ ] = V_168 ;
V_144 [ V_44 ++ ] = V_169 ;
}
#endif
#ifndef F_50
if ( V_4 -> V_39 >= V_153 )
{
V_144 [ V_44 ++ ] = V_170 ;
}
#endif
return ( V_44 ) ;
}
int F_51 ( T_2 * V_4 )
{
int V_44 ;
if ( ( V_4 -> V_171 ) || ( V_4 -> V_172 == V_173 ) )
{
V_4 -> V_174 = ( V_175 | V_176 ) ;
return ( 1 ) ;
}
if ( ! ( V_4 -> V_174 & V_175 ) )
{
V_4 -> V_174 |= V_175 ;
#if 1
F_52 ( V_4 , V_177 , V_178 ) ;
#endif
if ( V_4 -> V_7 -> V_179 )
return ( - 1 ) ;
}
else if ( V_4 -> V_7 -> V_179 )
{
#if 1
V_44 = V_4 -> V_14 -> V_180 ( V_4 ) ;
if( V_44 == - 1 )
{
return ( V_44 ) ;
}
#endif
}
else if ( ! ( V_4 -> V_174 & V_176 ) )
{
V_4 -> V_14 -> V_181 ( V_4 , 0 , NULL , 0 , 0 ) ;
if( ! ( V_4 -> V_174 & V_176 ) )
{
return ( - 1 ) ;
}
}
if ( ( V_4 -> V_174 == ( V_175 | V_176 ) ) &&
! V_4 -> V_7 -> V_179 )
return ( 1 ) ;
else
return ( 0 ) ;
}
int F_53 ( T_2 * V_4 , const void * V_19 , int V_33 )
{
int V_44 , V_182 ;
#if 0
if (s->shutdown & SSL_SEND_SHUTDOWN)
{
s->rwstate=SSL_NOTHING;
return(0);
}
#endif
F_54 () ;
if ( V_4 -> V_7 -> V_35 ) F_55 ( V_4 ) ;
if ( ( V_4 -> V_7 -> V_61 & V_183 ) && ( V_4 -> V_184 == V_4 -> V_185 ) )
{
if ( V_4 -> V_7 -> V_186 == 0 )
{
V_44 = F_56 ( V_4 , V_9 ,
V_19 , V_33 ) ;
if ( V_44 <= 0 ) return ( V_44 ) ;
V_4 -> V_7 -> V_186 = V_44 ;
}
V_4 -> V_187 = V_188 ;
V_182 = F_57 ( V_4 -> V_184 ) ;
if ( V_182 <= 0 ) return ( V_182 ) ;
V_4 -> V_187 = V_189 ;
F_22 ( V_4 ) ;
V_4 -> V_7 -> V_61 &= ~ V_183 ;
V_44 = V_4 -> V_7 -> V_186 ;
V_4 -> V_7 -> V_186 = 0 ;
}
else
{
V_44 = V_4 -> V_14 -> V_190 ( V_4 , V_9 ,
V_19 , V_33 ) ;
if ( V_44 <= 0 ) return ( V_44 ) ;
}
return ( V_44 ) ;
}
static int F_58 ( T_2 * V_4 , void * V_19 , int V_33 , int V_191 )
{
int V_44 ;
F_54 () ;
if ( V_4 -> V_7 -> V_35 ) F_55 ( V_4 ) ;
V_4 -> V_7 -> V_38 = 1 ;
V_44 = V_4 -> V_14 -> V_181 ( V_4 , V_9 , V_19 , V_33 , V_191 ) ;
if ( ( V_44 == - 1 ) && ( V_4 -> V_7 -> V_38 == 2 ) )
{
V_4 -> V_192 ++ ;
V_44 = V_4 -> V_14 -> V_181 ( V_4 , V_9 , V_19 , V_33 , V_191 ) ;
V_4 -> V_192 -- ;
}
else
V_4 -> V_7 -> V_38 = 0 ;
return ( V_44 ) ;
}
int F_59 ( T_2 * V_4 , void * V_19 , int V_33 )
{
return F_58 ( V_4 , V_19 , V_33 , 0 ) ;
}
int F_60 ( T_2 * V_4 , void * V_19 , int V_33 )
{
return F_58 ( V_4 , V_19 , V_33 , 1 ) ;
}
int F_61 ( T_2 * V_4 )
{
if ( V_4 -> V_193 == NULL )
return ( 1 ) ;
if ( V_4 -> V_7 -> V_61 & V_194 )
return ( 0 ) ;
V_4 -> V_7 -> V_35 = 1 ;
return ( 1 ) ;
}
int F_55 ( T_2 * V_4 )
{
int V_44 = 0 ;
if ( V_4 -> V_7 -> V_35 )
{
if ( ( V_4 -> V_7 -> V_18 . V_195 == 0 ) &&
( V_4 -> V_7 -> V_20 . V_195 == 0 ) &&
! F_62 ( V_4 ) )
{
V_4 -> V_172 = V_196 ;
V_4 -> V_7 -> V_35 = 0 ;
V_4 -> V_7 -> V_37 ++ ;
V_4 -> V_7 -> V_36 ++ ;
V_44 = 1 ;
}
}
return ( V_44 ) ;
}

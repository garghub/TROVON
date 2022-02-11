static void F_1 ( const T_1 * V_1 , const unsigned char * V_2 ,
int V_3 , unsigned char * V_4 , int V_5 ,
unsigned char * V_6 , int V_7 )
{
int V_8 , V_9 ;
unsigned int V_10 ;
T_2 V_11 ;
T_2 V_12 ;
unsigned char V_13 [ V_14 ] ;
unsigned int V_15 ;
V_8 = F_2 ( V_1 ) ;
F_3 ( & V_11 , V_2 , V_3 , V_1 ) ;
F_4 ( & V_11 , V_4 , V_5 ) ;
F_5 ( & V_11 , V_13 , & V_15 ) ;
V_9 = 0 ;
for (; ; )
{
F_3 ( & V_11 , NULL , 0 , NULL ) ;
F_4 ( & V_11 , V_13 , V_15 ) ;
memcpy ( & V_12 , & V_11 , sizeof( V_11 ) ) ;
F_4 ( & V_11 , V_4 , V_5 ) ;
if ( V_7 > V_8 )
{
F_5 ( & V_11 , V_6 , & V_10 ) ;
V_6 += V_10 ;
V_7 -= V_10 ;
F_5 ( & V_12 , V_13 , & V_15 ) ;
}
else
{
F_5 ( & V_11 , V_13 , & V_15 ) ;
memcpy ( V_6 , V_13 , V_7 ) ;
break;
}
}
F_6 ( & V_11 ) ;
F_6 ( & V_12 ) ;
memset ( V_13 , 0 , sizeof( V_13 ) ) ;
}
static void F_7 ( const T_1 * V_16 , const T_1 * V_17 ,
unsigned char * V_18 , int V_19 ,
const unsigned char * V_2 , int V_20 , unsigned char * V_21 ,
unsigned char * V_22 , int V_7 )
{
int V_23 , V_24 ;
const unsigned char * V_25 , * V_26 ;
V_23 = V_20 / 2 ;
V_25 = V_2 ;
V_26 = & ( V_2 [ V_23 ] ) ;
V_23 += ( V_20 & 1 ) ;
F_1 ( V_16 , V_25 , V_23 , V_18 , V_19 , V_21 , V_7 ) ;
F_1 ( V_17 , V_26 , V_23 , V_18 , V_19 , V_22 , V_7 ) ;
for ( V_24 = 0 ; V_24 < V_7 ; V_24 ++ )
V_21 [ V_24 ] ^= V_22 [ V_24 ] ;
}
static void F_8 ( T_3 * V_27 , unsigned char * V_28 ,
unsigned char * V_29 , int V_30 )
{
unsigned char * V_31 ;
unsigned char V_32 [ V_33 * 2 +
V_34 ] ;
V_31 = V_32 ;
memcpy ( V_31 , V_35 ,
V_36 ) ;
V_31 += V_36 ;
memcpy ( V_31 , V_27 -> V_37 -> V_38 , V_33 ) ;
V_31 += V_33 ;
memcpy ( V_31 , V_27 -> V_37 -> V_39 , V_33 ) ;
V_31 += V_33 ;
F_7 ( V_27 -> V_11 -> V_16 , V_27 -> V_11 -> V_17 , V_32 , ( int ) ( V_31 - V_32 ) ,
V_27 -> V_40 -> V_41 , V_27 -> V_40 -> V_42 ,
V_28 , V_29 , V_30 ) ;
}
int F_9 ( T_3 * V_27 , int V_43 )
{
static const unsigned char V_44 [] = L_1 ;
unsigned char * V_31 , * V_45 , * V_46 ;
unsigned char * V_47 , V_32 [ V_34 +
V_33 * 2 ] ;
unsigned char V_48 [ V_49 ] ;
unsigned char V_50 [ V_49 ] ;
unsigned char V_51 [ V_52 * 2 ] ;
unsigned char V_53 [ V_52 * 2 ] ;
unsigned char * V_54 , * V_55 , * V_56 , * V_57 , * V_58 ;
int V_59 ;
T_4 * V_60 ;
const T_5 * V_61 ;
const T_6 * V_62 ;
const T_1 * V_63 ;
int V_64 , V_9 , V_24 , V_10 , V_65 , V_66 , V_67 ;
V_64 = F_10 ( V_27 -> V_37 -> V_29 . V_68 ) ;
V_61 = V_27 -> V_37 -> V_29 . V_69 ;
V_63 = V_27 -> V_37 -> V_29 . V_70 ;
V_62 = V_27 -> V_37 -> V_29 . V_71 ;
V_45 = V_27 -> V_37 -> V_29 . V_45 ;
if ( V_43 & V_72 )
{
if ( ( V_27 -> V_73 == NULL ) &&
( ( V_27 -> V_73 = ( T_4 * )
F_11 ( sizeof( T_4 ) ) ) == NULL ) )
goto V_74;
V_60 = V_27 -> V_73 ;
V_27 -> V_75 = V_63 ;
if ( V_27 -> V_76 != NULL )
{
F_12 ( V_27 -> V_76 ) ;
V_27 -> V_76 = NULL ;
}
if ( V_62 != NULL )
{
V_27 -> V_76 = F_13 ( V_62 -> V_77 ) ;
if ( V_27 -> V_76 == NULL )
{
F_14 ( V_78 , V_79 ) ;
goto V_80;
}
if ( V_27 -> V_37 -> V_81 . V_62 == NULL )
V_27 -> V_37 -> V_81 . V_62 = ( unsigned char * )
F_11 ( V_82 ) ;
if ( V_27 -> V_37 -> V_81 . V_62 == NULL )
goto V_74;
}
memset ( & ( V_27 -> V_37 -> V_83 [ 0 ] ) , 0 , 8 ) ;
V_46 = & ( V_27 -> V_37 -> V_84 [ 0 ] ) ;
}
else
{
if ( ( V_27 -> V_85 == NULL ) &&
( ( V_27 -> V_85 = ( T_4 * )
F_11 ( sizeof( T_4 ) ) ) == NULL ) )
goto V_74;
V_60 = V_27 -> V_85 ;
V_27 -> V_86 = V_63 ;
if ( V_27 -> V_87 != NULL )
{
F_12 ( V_27 -> V_87 ) ;
V_27 -> V_87 = NULL ;
}
if ( V_62 != NULL )
{
V_27 -> V_87 = F_13 ( V_62 -> V_77 ) ;
if ( V_27 -> V_87 == NULL )
{
F_14 ( V_78 , V_79 ) ;
goto V_80;
}
}
memset ( & ( V_27 -> V_37 -> V_88 [ 0 ] ) , 0 , 8 ) ;
V_46 = & ( V_27 -> V_37 -> V_89 [ 0 ] ) ;
}
F_15 ( V_60 ) ;
V_31 = V_27 -> V_37 -> V_29 . V_45 ;
V_24 = F_2 ( V_63 ) ;
V_67 = F_16 ( V_61 ) ;
V_10 = V_64 ? ( V_67 < F_17 ( V_27 -> V_37 -> V_29 . V_68 ) ?
V_67 : F_17 ( V_27 -> V_37 -> V_29 . V_68 ) ) : V_67 ;
V_65 = F_18 ( V_61 ) ;
V_57 = & ( V_27 -> V_37 -> V_39 [ 0 ] ) ;
V_58 = & ( V_27 -> V_37 -> V_38 [ 0 ] ) ;
if ( ( V_43 == V_90 ) ||
( V_43 == V_91 ) )
{
V_54 = & ( V_31 [ 0 ] ) ; V_9 = V_24 + V_24 ;
V_55 = & ( V_31 [ V_9 ] ) ; V_9 += V_10 + V_10 ;
V_56 = & ( V_31 [ V_9 ] ) ; V_9 += V_65 + V_65 ;
V_47 = ( unsigned char * ) V_92 ;
V_66 = V_93 ;
V_59 = 1 ;
}
else
{
V_9 = V_24 ;
V_54 = & ( V_31 [ V_9 ] ) ; V_9 += V_24 + V_10 ;
V_55 = & ( V_31 [ V_9 ] ) ; V_9 += V_10 + V_65 ;
V_56 = & ( V_31 [ V_9 ] ) ; V_9 += V_65 ;
V_47 = ( unsigned char * ) V_94 ;
V_66 = V_95 ;
V_59 = 0 ;
}
if ( V_9 > V_27 -> V_37 -> V_29 . V_96 )
{
F_14 ( V_78 , V_97 ) ;
goto V_80;
}
memcpy ( V_46 , V_54 , V_24 ) ;
#ifdef F_19
printf ( L_2 , V_43 ) ;
{ int V_98 ; for ( V_98 = 0 ; V_98 < V_24 ; V_98 ++ ) printf ( L_3 , V_54 [ V_98 ] , ( ( V_98 + 1 ) % 16 ) ? ' ' : '\n' ) ; }
#endif
if ( V_64 )
{
V_31 = V_32 ;
memcpy ( V_31 , V_47 , V_66 ) ;
V_31 += V_66 ;
memcpy ( V_31 , V_27 -> V_37 -> V_39 , V_33 ) ;
V_31 += V_33 ;
memcpy ( V_31 , V_27 -> V_37 -> V_38 , V_33 ) ;
V_31 += V_33 ;
F_7 ( V_27 -> V_11 -> V_16 , V_27 -> V_11 -> V_17 , V_32 , ( int ) ( V_31 - V_32 ) , V_55 , V_10 ,
V_48 , V_50 , F_16 ( V_61 ) ) ;
V_55 = V_48 ;
if ( V_65 > 0 )
{
V_31 = V_32 ;
memcpy ( V_31 , V_99 ,
V_100 ) ;
V_31 += V_100 ;
memcpy ( V_31 , V_27 -> V_37 -> V_39 , V_33 ) ;
V_31 += V_33 ;
memcpy ( V_31 , V_27 -> V_37 -> V_38 , V_33 ) ;
V_31 += V_33 ;
F_7 ( V_27 -> V_11 -> V_16 , V_27 -> V_11 -> V_17 , V_32 , V_31 - V_32 , V_44 , 0 ,
V_51 , V_53 , V_65 * 2 ) ;
if ( V_59 )
V_56 = V_51 ;
else
V_56 = & ( V_51 [ V_65 ] ) ;
}
}
V_27 -> V_40 -> V_101 = 0 ;
F_20 ( V_60 , V_61 , V_55 , V_56 , ( V_43 & V_102 ) ) ;
#ifdef F_19
printf ( L_4 , V_43 ) ;
{ int V_98 ; for ( V_98 = 0 ; V_98 < F_16 ( V_61 ) ; V_98 ++ ) printf ( L_3 , V_55 [ V_98 ] , ( ( V_98 + 1 ) % 16 ) ? ' ' : '\n' ) ; }
printf ( L_5 ) ;
{ int V_98 ; for ( V_98 = 0 ; V_98 < V_65 ; V_98 ++ ) printf ( L_3 , V_56 [ V_98 ] , ( ( V_98 + 1 ) % 16 ) ? ' ' : '\n' ) ; }
printf ( L_6 ) ;
#endif
memset ( V_48 , 0 , sizeof( V_48 ) ) ;
memset ( V_50 , 0 , sizeof( V_48 ) ) ;
memset ( V_51 , 0 , sizeof( V_51 ) ) ;
memset ( V_53 , 0 , sizeof( V_53 ) ) ;
return ( 1 ) ;
V_74:
F_14 ( V_78 , V_103 ) ;
V_80:
return ( 0 ) ;
}
int F_21 ( T_3 * V_27 )
{
unsigned char * V_104 , * V_105 ;
const T_5 * V_61 ;
const T_1 * V_106 ;
int V_30 ;
T_6 * V_62 ;
if ( V_27 -> V_37 -> V_29 . V_96 != 0 )
return ( 1 ) ;
if ( ! F_22 ( V_27 -> V_40 , & V_61 , & V_106 , & V_62 ) )
{
F_14 ( V_107 , V_108 ) ;
return ( 0 ) ;
}
V_27 -> V_37 -> V_29 . V_69 = V_61 ;
V_27 -> V_37 -> V_29 . V_70 = V_106 ;
V_30 = F_16 ( V_61 ) + F_2 ( V_106 ) + F_18 ( V_61 ) ;
V_30 *= 2 ;
F_23 ( V_27 ) ;
if ( ( V_104 = ( unsigned char * ) F_11 ( V_30 ) ) == NULL )
goto V_74;
if ( ( V_105 = ( unsigned char * ) F_11 ( V_30 ) ) == NULL )
goto V_74;
V_27 -> V_37 -> V_29 . V_96 = V_30 ;
V_27 -> V_37 -> V_29 . V_45 = V_104 ;
#ifdef F_19
printf ( L_7 ) ;
{ int V_98 ; for ( V_98 = 0 ; V_98 < V_33 ; V_98 ++ ) printf ( L_3 , V_27 -> V_37 -> V_39 [ V_98 ] , ( ( V_98 + 1 ) % 16 ) ? ' ' : '\n' ) ; }
printf ( L_8 ) ;
{ int V_98 ; for ( V_98 = 0 ; V_98 < V_33 ; V_98 ++ ) printf ( L_3 , V_27 -> V_37 -> V_38 [ V_98 ] , ( ( V_98 + 1 ) % 16 ) ? ' ' : '\n' ) ; }
printf ( L_9 ) ;
{ int V_98 ; for ( V_98 = 0 ; V_98 < V_27 -> V_40 -> V_42 ; V_98 ++ ) printf ( L_3 , V_27 -> V_40 -> V_41 [ V_98 ] , ( ( V_98 + 1 ) % 16 ) ? ' ' : '\n' ) ; }
#endif
F_8 ( V_27 , V_104 , V_105 , V_30 ) ;
memset ( V_105 , 0 , V_30 ) ;
F_24 ( V_105 ) ;
#ifdef F_19
printf ( L_10 ) ;
{ int V_98 ; for ( V_98 = 0 ; V_98 < V_30 ; V_98 ++ ) printf ( L_3 , V_104 [ V_98 ] , ( ( V_98 + 1 ) % 16 ) ? ' ' : '\n' ) ; }
#endif
return ( 1 ) ;
V_74:
F_14 ( V_107 , V_103 ) ;
return ( 0 ) ;
}
int F_25 ( T_3 * V_27 , int V_109 )
{
T_7 * V_110 ;
T_4 * V_111 ;
unsigned long V_112 ;
int V_113 , V_24 , V_114 , V_10 , V_65 , V_9 = 0 ;
const T_5 * V_115 ;
if ( V_109 )
{
if ( V_27 -> V_86 != NULL )
V_9 = F_2 ( V_27 -> V_86 ) ;
V_111 = V_27 -> V_85 ;
V_110 = & ( V_27 -> V_37 -> V_116 ) ;
if ( V_27 -> V_85 == NULL )
V_115 = NULL ;
else
V_115 = F_26 ( V_27 -> V_85 ) ;
}
else
{
if ( V_27 -> V_75 != NULL )
V_9 = F_2 ( V_27 -> V_75 ) ;
V_111 = V_27 -> V_73 ;
V_110 = & ( V_27 -> V_37 -> V_81 ) ;
if ( V_27 -> V_73 == NULL )
V_115 = NULL ;
else
V_115 = F_26 ( V_27 -> V_73 ) ;
}
if ( ( V_27 -> V_40 == NULL ) || ( V_111 == NULL ) ||
( V_115 == NULL ) )
{
memcpy ( V_110 -> V_117 , V_110 -> V_118 , V_110 -> V_119 ) ;
V_110 -> V_118 = V_110 -> V_117 ;
}
else
{
V_112 = V_110 -> V_119 ;
V_113 = F_27 ( V_111 -> V_120 ) ;
if ( ( V_113 != 1 ) && V_109 )
{
V_24 = V_113 - ( ( int ) V_112 % V_113 ) ;
V_10 = V_24 - 1 ;
if ( V_27 -> V_121 & V_122 )
{
if ( V_27 -> V_37 -> V_123 & V_124 )
V_10 ++ ;
}
for ( V_65 = ( int ) V_112 ; V_65 < ( int ) ( V_112 + V_24 ) ; V_65 ++ )
V_110 -> V_118 [ V_65 ] = V_10 ;
V_112 += V_24 ;
V_110 -> V_119 += V_24 ;
}
F_28 ( V_111 , V_110 -> V_117 , V_110 -> V_118 , V_112 ) ;
if ( ( V_113 != 1 ) && ! V_109 )
{
V_114 = V_24 = V_110 -> V_117 [ V_112 - 1 ] ;
V_24 ++ ;
if ( V_27 -> V_121 & V_122 )
{
if ( ( memcmp ( V_27 -> V_37 -> V_83 ,
L_11 , 8 ) == 0 ) && ! ( V_114 & 1 ) )
V_27 -> V_37 -> V_123 |= V_124 ;
if ( V_27 -> V_37 -> V_123 & V_124 )
V_24 -- ;
}
if ( V_24 > ( int ) V_110 -> V_119 )
{
F_14 ( V_125 , V_126 ) ;
F_29 ( V_27 , V_127 , V_128 ) ;
return ( 0 ) ;
}
for ( V_10 = ( int ) ( V_112 - V_24 ) ; V_10 < ( int ) V_112 ; V_10 ++ )
{
if ( V_110 -> V_117 [ V_10 ] != V_114 )
{
F_14 ( V_125 , V_129 ) ;
F_29 ( V_27 , V_127 , V_128 ) ;
return ( 0 ) ;
}
}
V_110 -> V_119 -= V_24 ;
}
}
return ( 1 ) ;
}
int F_30 ( T_3 * V_27 , T_8 * V_130 , unsigned char * V_6 )
{
unsigned int V_131 ;
T_8 V_11 ;
F_31 ( & V_11 , V_130 ) ;
F_32 ( & V_11 , V_6 , & V_131 ) ;
return ( ( int ) V_131 ) ;
}
int F_33 ( T_3 * V_27 , T_8 * V_132 , T_8 * V_133 ,
const char * V_134 , int V_20 , unsigned char * V_6 )
{
unsigned int V_24 ;
T_8 V_11 ;
unsigned char V_32 [ V_34 + V_135 + V_136 ] ;
unsigned char * V_137 , V_138 [ 12 ] ;
V_137 = V_32 ;
memcpy ( V_137 , V_134 , V_20 ) ;
V_137 += V_20 ;
F_31 ( & V_11 , V_132 ) ;
F_32 ( & V_11 , V_137 , & V_24 ) ;
V_137 += V_24 ;
F_31 ( & V_11 , V_133 ) ;
F_32 ( & V_11 , V_137 , & V_24 ) ;
V_137 += V_24 ;
F_7 ( V_27 -> V_11 -> V_16 , V_27 -> V_11 -> V_17 , V_32 , ( int ) ( V_137 - V_32 ) ,
V_27 -> V_40 -> V_41 , V_27 -> V_40 -> V_42 ,
V_6 , V_138 , 12 ) ;
memset ( & V_11 , 0 , sizeof( T_8 ) ) ;
return ( ( int ) 12 ) ;
}
int F_34 ( T_3 * V_139 , unsigned char * V_1 , int V_109 )
{
T_7 * V_110 ;
unsigned char * V_140 , * V_141 ;
const T_1 * V_106 ;
unsigned int V_142 ;
int V_24 ;
T_2 V_143 ;
unsigned char V_32 [ 5 ] ;
if ( V_109 )
{
V_110 = & ( V_139 -> V_37 -> V_116 ) ;
V_140 = & ( V_139 -> V_37 -> V_89 [ 0 ] ) ;
V_141 = & ( V_139 -> V_37 -> V_88 [ 0 ] ) ;
V_106 = V_139 -> V_86 ;
}
else
{
V_110 = & ( V_139 -> V_37 -> V_81 ) ;
V_140 = & ( V_139 -> V_37 -> V_84 [ 0 ] ) ;
V_141 = & ( V_139 -> V_37 -> V_83 [ 0 ] ) ;
V_106 = V_139 -> V_75 ;
}
V_142 = F_2 ( V_106 ) ;
V_32 [ 0 ] = V_110 -> type ;
V_32 [ 1 ] = V_144 ;
V_32 [ 2 ] = V_145 ;
V_32 [ 3 ] = V_110 -> V_119 >> 8 ;
V_32 [ 4 ] = V_110 -> V_119 & 0xff ;
F_3 ( & V_143 , V_140 , F_2 ( V_106 ) , V_106 ) ;
F_4 ( & V_143 , V_141 , 8 ) ;
F_4 ( & V_143 , V_32 , 5 ) ;
F_4 ( & V_143 , V_110 -> V_118 , V_110 -> V_119 ) ;
F_5 ( & V_143 , V_1 , & V_142 ) ;
#ifdef F_19
printf ( L_12 ) ;
{ unsigned int V_98 ; for ( V_98 = 0 ; V_98 < V_142 ; V_98 ++ ) printf ( L_13 , V_140 [ V_98 ] ) ; printf ( L_6 ) ; }
printf ( L_14 ) ;
{ int V_98 ; for ( V_98 = 0 ; V_98 < 8 ; V_98 ++ ) printf ( L_13 , V_141 [ V_98 ] ) ; printf ( L_6 ) ; }
printf ( L_15 ) ;
{ int V_98 ; for ( V_98 = 0 ; V_98 < 5 ; V_98 ++ ) printf ( L_13 , V_32 [ V_98 ] ) ; printf ( L_6 ) ; }
printf ( L_16 ) ;
{ unsigned int V_98 ; for ( V_98 = 0 ; V_98 < V_110 -> V_119 ; V_98 ++ ) printf ( L_13 , V_32 [ V_98 ] ) ; printf ( L_6 ) ; }
#endif
for ( V_24 = 7 ; V_24 >= 0 ; V_24 -- )
if ( ++ V_141 [ V_24 ] ) break;
#ifdef F_19
{ unsigned int V_98 ; for ( V_98 = 0 ; V_98 < V_142 ; V_98 ++ ) printf ( L_13 , V_1 [ V_98 ] ) ; printf ( L_6 ) ; }
#endif
return ( V_142 ) ;
}
int F_35 ( T_3 * V_27 , unsigned char * V_6 , unsigned char * V_31 ,
int V_23 )
{
unsigned char V_32 [ V_33 * 2 + V_146 ] ;
unsigned char V_147 [ V_148 ] ;
memcpy ( V_32 , V_149 ,
V_146 ) ;
memcpy ( & ( V_32 [ V_146 ] ) ,
V_27 -> V_37 -> V_39 , V_33 ) ;
memcpy ( & ( V_32 [ V_33 + V_146 ] ) ,
V_27 -> V_37 -> V_38 , V_33 ) ;
F_7 ( V_27 -> V_11 -> V_16 , V_27 -> V_11 -> V_17 ,
V_32 , V_146 + V_33 * 2 , V_31 , V_23 ,
V_27 -> V_40 -> V_41 , V_147 , V_150 ) ;
return ( V_150 ) ;
}
int F_36 ( int V_151 )
{
switch ( V_151 )
{
case V_152 : return ( V_153 ) ;
case V_154 : return ( V_155 ) ;
case V_156 : return ( V_157 ) ;
case V_128 : return ( V_158 ) ;
case V_159 : return ( V_160 ) ;
case V_161 : return ( V_162 ) ;
case V_163 : return ( V_164 ) ;
case V_165 : return ( - 1 ) ;
case V_166 : return ( V_167 ) ;
case V_168 : return ( V_169 ) ;
case V_170 : return ( V_171 ) ;
case V_172 : return ( V_173 ) ;
case V_174 : return ( V_175 ) ;
case V_176 : return ( V_177 ) ;
case V_178 : return ( V_179 ) ;
case V_180 : return ( V_181 ) ;
case V_182 : return ( V_183 ) ;
case V_184 : return ( V_185 ) ;
case V_186 : return ( V_187 ) ;
case V_188 : return ( V_189 ) ;
case V_190 : return ( V_191 ) ;
case V_192 : return ( V_193 ) ;
case V_194 : return ( V_195 ) ;
case V_196 : return ( V_197 ) ;
default: return ( - 1 ) ;
}
}

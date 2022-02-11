static int F_1 ( const T_1 * V_1 , const unsigned char * V_2 ,
int V_3 ,
const void * V_4 , int V_5 ,
const void * V_6 , int V_7 ,
const void * V_8 , int V_9 ,
const void * V_10 , int V_11 ,
const void * V_12 , int V_13 ,
unsigned char * V_14 , int V_15 )
{
int V_16 ;
T_2 V_17 ;
T_3 V_18 , V_19 ;
T_4 * V_20 ;
unsigned char V_21 [ V_22 ] ;
T_2 V_23 ;
int V_24 = 0 ;
V_16 = F_2 ( V_1 ) ;
F_3 ( V_16 >= 0 ) ;
F_4 ( & V_18 ) ;
F_4 ( & V_19 ) ;
F_5 ( & V_18 , V_25 ) ;
F_5 ( & V_19 , V_25 ) ;
V_20 = F_6 ( V_26 , NULL , V_2 , V_3 ) ;
if ( ! V_20 )
goto V_27;
if ( ! F_7 ( & V_18 , NULL , V_1 , NULL , V_20 ) )
goto V_27;
if ( ! F_7 ( & V_19 , NULL , V_1 , NULL , V_20 ) )
goto V_27;
if ( V_4 && ! F_8 ( & V_18 , V_4 , V_5 ) )
goto V_27;
if ( V_6 && ! F_8 ( & V_18 , V_6 , V_7 ) )
goto V_27;
if ( V_8 && ! F_8 ( & V_18 , V_8 , V_9 ) )
goto V_27;
if ( V_10 && ! F_8 ( & V_18 , V_10 , V_11 ) )
goto V_27;
if ( V_12 && ! F_8 ( & V_18 , V_12 , V_13 ) )
goto V_27;
if ( ! F_9 ( & V_18 , V_21 , & V_23 ) )
goto V_27;
for (; ; )
{
if ( ! F_7 ( & V_18 , NULL , V_1 , NULL , V_20 ) )
goto V_27;
if ( ! F_7 ( & V_19 , NULL , V_1 , NULL , V_20 ) )
goto V_27;
if ( ! F_8 ( & V_18 , V_21 , V_23 ) )
goto V_27;
if ( ! F_8 ( & V_19 , V_21 , V_23 ) )
goto V_27;
if ( V_4 && ! F_8 ( & V_18 , V_4 , V_5 ) )
goto V_27;
if ( V_6 && ! F_8 ( & V_18 , V_6 , V_7 ) )
goto V_27;
if ( V_8 && ! F_8 ( & V_18 , V_8 , V_9 ) )
goto V_27;
if ( V_10 && ! F_8 ( & V_18 , V_10 , V_11 ) )
goto V_27;
if ( V_12 && ! F_8 ( & V_18 , V_12 , V_13 ) )
goto V_27;
if ( V_15 > V_16 )
{
if ( ! F_9 ( & V_18 , V_14 , & V_17 ) )
goto V_27;
V_14 += V_17 ;
V_15 -= V_17 ;
if ( ! F_9 ( & V_19 , V_21 , & V_23 ) )
goto V_27;
}
else
{
if ( ! F_9 ( & V_18 , V_21 , & V_23 ) )
goto V_27;
memcpy ( V_14 , V_21 , V_15 ) ;
break;
}
}
V_24 = 1 ;
V_27:
F_10 ( V_20 ) ;
F_11 ( & V_18 ) ;
F_11 ( & V_19 ) ;
F_12 ( V_21 , sizeof( V_21 ) ) ;
return V_24 ;
}
static int F_13 ( long V_28 ,
const void * V_4 , int V_5 ,
const void * V_6 , int V_7 ,
const void * V_8 , int V_9 ,
const void * V_10 , int V_11 ,
const void * V_12 , int V_13 ,
const unsigned char * V_2 , int V_29 ,
unsigned char * V_30 ,
unsigned char * V_31 , int V_15 )
{
int V_32 , V_33 , V_34 , V_35 ;
const unsigned char * V_36 ;
long V_37 ;
const T_1 * V_1 ;
int V_24 = 0 ;
V_35 = 0 ;
for ( V_34 = 0 ; F_14 ( V_34 , & V_37 , & V_1 ) ; V_34 ++ ) {
if ( ( V_37 << V_38 ) & V_28 ) V_35 ++ ;
}
V_32 = V_29 / V_35 ;
if ( V_35 == 1 )
V_29 = 0 ;
V_36 = V_2 ;
memset ( V_30 , 0 , V_15 ) ;
for ( V_34 = 0 ; F_14 ( V_34 , & V_37 , & V_1 ) ; V_34 ++ ) {
if ( ( V_37 << V_38 ) & V_28 ) {
if ( ! V_1 ) {
F_15 ( V_39 ,
V_40 ) ;
goto V_27;
}
if ( ! F_1 ( V_1 , V_36 , V_32 + ( V_29 & 1 ) ,
V_4 , V_5 , V_6 , V_7 , V_8 , V_9 , V_10 , V_11 , V_12 , V_13 ,
V_31 , V_15 ) )
goto V_27;
V_36 += V_32 ;
for ( V_33 = 0 ; V_33 < V_15 ; V_33 ++ )
{
V_30 [ V_33 ] ^= V_31 [ V_33 ] ;
}
}
}
V_24 = 1 ;
V_27:
return V_24 ;
}
static int F_16 ( T_5 * V_41 , unsigned char * V_42 ,
unsigned char * V_43 , int V_44 )
{
int V_24 ;
V_24 = F_13 ( F_17 ( V_41 ) ,
V_45 , V_46 ,
V_41 -> V_47 -> V_48 , V_49 ,
V_41 -> V_47 -> V_50 , V_49 ,
NULL , 0 , NULL , 0 ,
V_41 -> V_51 -> V_52 , V_41 -> V_51 -> V_53 ,
V_42 , V_43 , V_44 ) ;
#ifdef F_18
printf ( L_1 ,
V_41 -> V_51 -> V_53 ) ;
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_41 -> V_51 -> V_53 ; V_33 ++ )
{
printf ( L_2 , V_41 -> V_51 -> V_52 [ V_33 ] ) ;
}
printf ( L_3 ) ; }
#endif
return V_24 ;
}
int F_19 ( T_5 * V_41 , int V_54 )
{
static const unsigned char V_55 [] = L_4 ;
unsigned char * V_56 , * V_57 ;
unsigned char * V_58 ;
unsigned char V_59 [ V_60 ] ;
unsigned char V_61 [ V_60 ] ;
unsigned char V_62 [ V_63 * 2 ] ;
unsigned char V_64 [ V_63 * 2 ] ;
unsigned char * V_65 , * V_66 , * V_67 ;
int V_68 ;
T_6 * V_69 ;
const T_7 * V_70 ;
#ifndef F_20
const T_8 * V_71 ;
#endif
const T_1 * V_37 ;
int V_72 ;
int * V_73 ;
T_3 * V_74 ;
T_4 * V_20 ;
int V_75 , V_76 , V_33 , V_17 , V_77 , V_78 , V_79 ;
int V_80 = 0 ;
V_75 = F_21 ( V_41 -> V_47 -> V_43 . V_81 ) ;
V_70 = V_41 -> V_47 -> V_43 . V_82 ;
V_37 = V_41 -> V_47 -> V_43 . V_83 ;
V_72 = V_41 -> V_47 -> V_43 . V_84 ;
#ifndef F_20
V_71 = V_41 -> V_47 -> V_43 . V_85 ;
#endif
#ifdef F_18
printf ( L_5 , V_54 ) ;
printf ( L_6 ,
V_41 -> V_47 -> V_43 . V_81 -> V_86 ,
V_41 -> V_47 -> V_43 . V_81 -> V_87 ,
V_71 ) ;
printf ( L_7 , V_70 ) ;
printf ( L_8 ,
V_70 -> V_88 , V_70 -> V_89 , V_70 -> V_90 , V_70 -> V_91 ) ;
printf ( L_9 , V_41 -> V_47 -> V_43 . V_92 ) ;
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_41 -> V_47 -> V_43 . V_92 ; V_33 ++ )
printf ( L_10 , V_93 [ V_33 ] ) ; printf ( L_3 ) ;
}
#endif
if ( V_54 & V_94 )
{
if ( V_41 -> V_47 -> V_43 . V_81 -> V_95 & V_96 )
V_41 -> V_97 |= V_98 ;
else
V_41 -> V_97 &= ~ V_98 ;
if ( V_41 -> V_99 != NULL )
V_80 = 1 ;
else if ( ( V_41 -> V_99 = F_22 ( sizeof( T_6 ) ) ) == NULL )
goto V_27;
else
F_23 ( V_41 -> V_99 ) ;
V_69 = V_41 -> V_99 ;
V_74 = F_24 ( & V_41 -> V_100 , NULL ) ;
#ifndef F_20
if ( V_41 -> V_101 != NULL )
{
F_25 ( V_41 -> V_101 ) ;
V_41 -> V_101 = NULL ;
}
if ( V_71 != NULL )
{
V_41 -> V_101 = F_26 ( V_71 -> V_102 ) ;
if ( V_41 -> V_101 == NULL )
{
F_15 ( V_103 , V_104 ) ;
goto V_105;
}
if ( V_41 -> V_47 -> V_106 . V_71 == NULL )
V_41 -> V_47 -> V_106 . V_71 = ( unsigned char * )
F_22 ( V_107 ) ;
if ( V_41 -> V_47 -> V_106 . V_71 == NULL )
goto V_27;
}
#endif
if ( V_41 -> V_108 != V_109 )
memset ( & ( V_41 -> V_47 -> V_110 [ 0 ] ) , 0 , 8 ) ;
V_57 = & ( V_41 -> V_47 -> V_111 [ 0 ] ) ;
V_73 = & ( V_41 -> V_47 -> V_112 ) ;
}
else
{
if ( V_41 -> V_47 -> V_43 . V_81 -> V_95 & V_96 )
V_41 -> V_97 |= V_113 ;
else
V_41 -> V_97 &= ~ V_113 ;
if ( V_41 -> V_114 != NULL )
V_80 = 1 ;
else if ( ( V_41 -> V_114 = F_22 ( sizeof( T_6 ) ) ) == NULL )
goto V_27;
else
F_23 ( V_41 -> V_114 ) ;
V_69 = V_41 -> V_114 ;
V_74 = F_24 ( & V_41 -> V_115 , NULL ) ;
#ifndef F_20
if ( V_41 -> V_116 != NULL )
{
F_25 ( V_41 -> V_116 ) ;
V_41 -> V_116 = NULL ;
}
if ( V_71 != NULL )
{
V_41 -> V_116 = F_26 ( V_71 -> V_102 ) ;
if ( V_41 -> V_116 == NULL )
{
F_15 ( V_103 , V_104 ) ;
goto V_105;
}
}
#endif
if ( V_41 -> V_108 != V_109 )
memset ( & ( V_41 -> V_47 -> V_117 [ 0 ] ) , 0 , 8 ) ;
V_57 = & ( V_41 -> V_47 -> V_118 [ 0 ] ) ;
V_73 = & ( V_41 -> V_47 -> V_119 ) ;
}
if ( V_80 )
F_27 ( V_69 ) ;
V_56 = V_41 -> V_47 -> V_43 . V_93 ;
V_33 = * V_73 = V_41 -> V_47 -> V_43 . V_120 ;
V_79 = F_28 ( V_70 ) ;
V_17 = V_75 ? ( V_79 < F_29 ( V_41 -> V_47 -> V_43 . V_81 ) ?
V_79 : F_29 ( V_41 -> V_47 -> V_43 . V_81 ) ) : V_79 ;
if ( F_30 ( V_70 ) == V_121 )
V_77 = V_122 ;
else
V_77 = F_31 ( V_70 ) ;
if ( ( V_54 == V_123 ) ||
( V_54 == V_124 ) )
{
V_65 = & ( V_56 [ 0 ] ) ; V_76 = V_33 + V_33 ;
V_66 = & ( V_56 [ V_76 ] ) ; V_76 += V_17 + V_17 ;
V_67 = & ( V_56 [ V_76 ] ) ; V_76 += V_77 + V_77 ;
V_58 = ( unsigned char * ) V_125 ;
V_78 = V_126 ;
V_68 = 1 ;
}
else
{
V_76 = V_33 ;
V_65 = & ( V_56 [ V_76 ] ) ; V_76 += V_33 + V_17 ;
V_66 = & ( V_56 [ V_76 ] ) ; V_76 += V_17 + V_77 ;
V_67 = & ( V_56 [ V_76 ] ) ; V_76 += V_77 ;
V_58 = ( unsigned char * ) V_127 ;
V_78 = V_128 ;
V_68 = 0 ;
}
if ( V_76 > V_41 -> V_47 -> V_43 . V_92 )
{
F_15 ( V_103 , V_129 ) ;
goto V_105;
}
memcpy ( V_57 , V_65 , V_33 ) ;
if ( ! ( F_32 ( V_70 ) & V_130 ) )
{
V_20 = F_6 ( V_72 , NULL ,
V_57 , * V_73 ) ;
F_7 ( V_74 , NULL , V_37 , NULL , V_20 ) ;
F_10 ( V_20 ) ;
}
#ifdef F_33
printf ( L_11 , V_54 ) ;
{ int V_131 ; for ( V_131 = 0 ; V_131 < V_33 ; V_131 ++ ) printf ( L_12 , V_65 [ V_131 ] , ( ( V_131 + 1 ) % 16 ) ? ' ' : '\n' ) ; }
#endif
if ( V_75 )
{
if ( ! F_13 ( F_17 ( V_41 ) ,
V_58 , V_78 ,
V_41 -> V_47 -> V_50 , V_49 ,
V_41 -> V_47 -> V_48 , V_49 ,
NULL , 0 , NULL , 0 ,
V_66 , V_17 , V_59 , V_61 , F_28 ( V_70 ) ) )
goto V_105;
V_66 = V_59 ;
if ( V_77 > 0 )
{
if ( ! F_13 ( F_17 ( V_41 ) ,
V_132 , V_133 ,
V_41 -> V_47 -> V_50 , V_49 ,
V_41 -> V_47 -> V_48 , V_49 ,
NULL , 0 , NULL , 0 ,
V_55 , 0 , V_62 , V_64 , V_77 * 2 ) )
goto V_105;
if ( V_68 )
V_67 = V_62 ;
else
V_67 = & ( V_62 [ V_77 ] ) ;
}
}
V_41 -> V_51 -> V_134 = 0 ;
#ifdef F_18
{
int V_33 ;
printf ( L_13 ) ;
printf ( L_14 ) ; for ( V_33 = 0 ; V_33 < V_70 -> V_90 ; V_33 ++ ) printf ( L_10 , V_66 [ V_33 ] ) ;
printf ( L_3 ) ;
printf ( L_15 ) ; for ( V_33 = 0 ; V_33 < V_70 -> V_91 ; V_33 ++ ) printf ( L_10 , V_67 [ V_33 ] ) ;
printf ( L_3 ) ;
}
#endif
if ( F_30 ( V_70 ) == V_121 )
{
F_34 ( V_69 , V_70 , NULL , V_66 , NULL , ( V_54 & V_135 ) ) ;
F_35 ( V_69 , V_136 , V_77 , V_67 ) ;
}
else
F_34 ( V_69 , V_70 , NULL , V_66 , V_67 , ( V_54 & V_135 ) ) ;
if ( ( F_32 ( V_70 ) & V_130 ) && * V_73 )
F_35 ( V_69 , V_137 ,
* V_73 , V_57 ) ;
#ifdef F_33
printf ( L_16 , V_54 ) ;
{ int V_131 ; for ( V_131 = 0 ; V_131 < F_28 ( V_70 ) ; V_131 ++ ) printf ( L_12 , V_66 [ V_131 ] , ( ( V_131 + 1 ) % 16 ) ? ' ' : '\n' ) ; }
printf ( L_17 ) ;
{ int V_131 ; for ( V_131 = 0 ; V_131 < V_77 ; V_131 ++ ) printf ( L_12 , V_67 [ V_131 ] , ( ( V_131 + 1 ) % 16 ) ? ' ' : '\n' ) ; }
printf ( L_3 ) ;
#endif
F_12 ( V_59 , sizeof( V_59 ) ) ;
F_12 ( V_61 , sizeof( V_59 ) ) ;
F_12 ( V_62 , sizeof( V_62 ) ) ;
F_12 ( V_64 , sizeof( V_64 ) ) ;
return ( 1 ) ;
V_27:
F_15 ( V_103 , V_138 ) ;
V_105:
return ( 0 ) ;
}
int F_36 ( T_5 * V_41 )
{
unsigned char * V_139 , * V_140 = NULL ;
const T_7 * V_70 ;
const T_1 * V_141 ;
int V_44 ;
T_8 * V_71 ;
int V_72 = V_142 , V_73 = 0 ;
int V_24 = 0 ;
#ifdef F_18
printf ( L_18 ) ;
#endif
if ( V_41 -> V_47 -> V_43 . V_92 != 0 )
return ( 1 ) ;
if ( ! F_37 ( V_41 -> V_51 , & V_70 , & V_141 , & V_72 , & V_73 , & V_71 ) )
{
F_15 ( V_143 , V_144 ) ;
return ( 0 ) ;
}
V_41 -> V_47 -> V_43 . V_82 = V_70 ;
V_41 -> V_47 -> V_43 . V_83 = V_141 ;
V_41 -> V_47 -> V_43 . V_84 = V_72 ;
V_41 -> V_47 -> V_43 . V_120 = V_73 ;
V_44 = F_28 ( V_70 ) + V_73 + F_31 ( V_70 ) ;
V_44 *= 2 ;
F_38 ( V_41 ) ;
if ( ( V_139 = ( unsigned char * ) F_22 ( V_44 ) ) == NULL )
{
F_15 ( V_143 , V_138 ) ;
goto V_27;
}
V_41 -> V_47 -> V_43 . V_92 = V_44 ;
V_41 -> V_47 -> V_43 . V_93 = V_139 ;
if ( ( V_140 = ( unsigned char * ) F_22 ( V_44 ) ) == NULL )
{
F_15 ( V_143 , V_138 ) ;
goto V_27;
}
#ifdef F_33
printf ( L_19 ) ;
{ int V_131 ; for ( V_131 = 0 ; V_131 < V_49 ; V_131 ++ ) printf ( L_12 , V_41 -> V_47 -> V_50 [ V_131 ] , ( ( V_131 + 1 ) % 16 ) ? ' ' : '\n' ) ; }
printf ( L_20 ) ;
{ int V_131 ; for ( V_131 = 0 ; V_131 < V_49 ; V_131 ++ ) printf ( L_12 , V_41 -> V_47 -> V_48 [ V_131 ] , ( ( V_131 + 1 ) % 16 ) ? ' ' : '\n' ) ; }
printf ( L_21 ) ;
{ int V_131 ; for ( V_131 = 0 ; V_131 < V_41 -> V_51 -> V_53 ; V_131 ++ ) printf ( L_12 , V_41 -> V_51 -> V_52 [ V_131 ] , ( ( V_131 + 1 ) % 16 ) ? ' ' : '\n' ) ; }
#endif
if ( ! F_16 ( V_41 , V_139 , V_140 , V_44 ) )
goto V_27;
#ifdef F_33
printf ( L_22 ) ;
{ int V_131 ; for ( V_131 = 0 ; V_131 < V_44 ; V_131 ++ ) printf ( L_12 , V_139 [ V_131 ] , ( ( V_131 + 1 ) % 16 ) ? ' ' : '\n' ) ; }
#endif
if ( ! ( V_41 -> V_145 & V_146 )
&& V_41 -> V_102 -> V_108 <= V_147 )
{
V_41 -> V_47 -> V_148 = 1 ;
if ( V_41 -> V_51 -> V_149 != NULL )
{
if ( V_41 -> V_51 -> V_149 -> V_150 == V_151 )
V_41 -> V_47 -> V_148 = 0 ;
#ifndef F_39
if ( V_41 -> V_51 -> V_149 -> V_150 == V_152 )
V_41 -> V_47 -> V_148 = 0 ;
#endif
}
}
V_24 = 1 ;
V_27:
if ( V_140 )
{
F_12 ( V_140 , V_44 ) ;
F_40 ( V_140 ) ;
}
return ( V_24 ) ;
}
int F_41 ( T_5 * V_41 , int V_153 )
{
T_9 * V_154 ;
T_6 * V_155 ;
unsigned long V_156 ;
int V_157 , V_33 , V_158 , V_17 , V_77 , V_159 = 0 ;
const T_7 * V_160 ;
if ( V_153 )
{
if ( F_42 ( V_41 -> V_115 ) )
{
int V_76 = F_43 ( V_41 -> V_115 ) ;
F_3 ( V_76 >= 0 ) ;
}
V_155 = V_41 -> V_114 ;
V_154 = & ( V_41 -> V_47 -> V_161 ) ;
if ( V_41 -> V_114 == NULL )
V_160 = NULL ;
else
{
int V_162 ;
V_160 = F_44 ( V_41 -> V_114 ) ;
if ( V_41 -> V_108 >= V_163
&& F_30 ( V_160 ) == V_164 )
V_162 = F_31 ( V_160 ) ;
else
V_162 = 0 ;
if ( V_162 > 1 )
{
if ( V_154 -> V_165 != V_154 -> V_166 )
fprintf ( V_167 ,
L_23 ,
__FILE__ , __LINE__ ) ;
else if ( F_45 ( V_154 -> V_166 , V_162 ) <= 0 )
return - 1 ;
}
}
}
else
{
if ( F_42 ( V_41 -> V_100 ) )
{
int V_76 = F_43 ( V_41 -> V_100 ) ;
F_3 ( V_76 >= 0 ) ;
}
V_155 = V_41 -> V_99 ;
V_154 = & ( V_41 -> V_47 -> V_106 ) ;
if ( V_41 -> V_99 == NULL )
V_160 = NULL ;
else
V_160 = F_44 ( V_41 -> V_99 ) ;
}
#ifdef F_18
printf ( L_24 , V_153 ) ;
#endif
if ( ( V_41 -> V_51 == NULL ) || ( V_155 == NULL ) ||
( V_160 == NULL ) )
{
memmove ( V_154 -> V_165 , V_154 -> V_166 , V_154 -> V_168 ) ;
V_154 -> V_166 = V_154 -> V_165 ;
}
else
{
V_156 = V_154 -> V_168 ;
V_157 = F_46 ( V_155 -> V_149 ) ;
if ( F_32 ( V_155 -> V_149 ) & V_130 )
{
unsigned char V_169 [ 13 ] , * V_170 ;
V_170 = V_153 ? V_41 -> V_47 -> V_117 : V_41 -> V_47 -> V_110 ;
if ( V_41 -> V_108 == V_109 || V_41 -> V_108 == V_171 )
{
unsigned char V_172 [ 9 ] , * V_56 = V_172 ;
F_47 ( V_153 ? V_41 -> V_173 -> V_174 : V_41 -> V_173 -> V_175 , V_56 ) ;
memcpy ( V_56 , & V_170 [ 2 ] , 6 ) ;
memcpy ( V_169 , V_172 , 8 ) ;
}
else
{
memcpy ( V_169 , V_170 , 8 ) ;
for ( V_33 = 7 ; V_33 >= 0 ; V_33 -- )
{
++ V_170 [ V_33 ] ;
if ( V_170 [ V_33 ] != 0 ) break;
}
}
V_169 [ 8 ] = V_154 -> type ;
V_169 [ 9 ] = ( unsigned char ) ( V_41 -> V_108 >> 8 ) ;
V_169 [ 10 ] = ( unsigned char ) ( V_41 -> V_108 ) ;
V_169 [ 11 ] = V_154 -> V_168 >> 8 ;
V_169 [ 12 ] = V_154 -> V_168 & 0xff ;
V_159 = F_35 ( V_155 , V_176 , 13 , V_169 ) ;
if ( V_153 )
{
V_156 += V_159 ;
V_154 -> V_168 += V_159 ;
}
}
else if ( ( V_157 != 1 ) && V_153 )
{
V_33 = V_157 - ( ( int ) V_156 % V_157 ) ;
V_17 = V_33 - 1 ;
if ( V_41 -> V_145 & V_177 )
{
if ( V_41 -> V_47 -> V_178 & V_179 )
V_17 ++ ;
}
for ( V_77 = ( int ) V_156 ; V_77 < ( int ) ( V_156 + V_33 ) ; V_77 ++ )
V_154 -> V_166 [ V_77 ] = V_17 ;
V_156 += V_33 ;
V_154 -> V_168 += V_33 ;
}
#ifdef F_18
{
unsigned long V_180 ;
printf ( L_25 ,
V_155 , V_154 -> V_165 , V_154 -> V_166 , V_156 ) ;
printf ( L_26 ,
V_155 -> V_181 , V_155 -> V_149 -> V_90 ,
V_182 , V_183 ,
V_155 -> V_149 -> V_91 ) ;
printf ( L_27 ) ;
for ( V_33 = 0 ; V_33 < V_155 -> V_149 -> V_91 ; V_33 ++ ) printf ( L_2 , V_155 -> V_67 [ V_33 ] ) ;
printf ( L_3 ) ;
printf ( L_28 ) ;
for ( V_180 = 0 ; V_180 < V_156 ; V_180 ++ ) printf ( L_29 , V_154 -> V_166 [ V_180 ] ) ;
printf ( L_3 ) ;
}
#endif
if ( ! V_153 )
{
if ( V_156 == 0 || V_156 % V_157 != 0 )
{
if ( V_41 -> V_108 >= V_163 )
return - 1 ;
F_15 ( V_184 , V_185 ) ;
F_48 ( V_41 , V_186 , V_187 ) ;
return 0 ;
}
}
V_33 = F_49 ( V_155 , V_154 -> V_165 , V_154 -> V_166 , V_156 ) ;
if ( ( F_32 ( V_155 -> V_149 ) & V_188 )
? ( V_33 < 0 )
: ( V_33 == 0 ) )
return - 1 ;
if ( F_30 ( V_160 ) == V_121 && ! V_153 )
{
V_154 -> V_165 += V_189 ;
V_154 -> V_166 += V_189 ;
V_154 -> V_168 -= V_189 ;
}
#ifdef F_18
{
unsigned long V_33 ;
printf ( L_30 ) ;
for ( V_33 = 0 ; V_33 < V_156 ; V_33 ++ )
printf ( L_29 , V_154 -> V_165 [ V_33 ] ) ; printf ( L_3 ) ;
}
#endif
if ( ( V_157 != 1 ) && ! V_153 )
{
V_158 = V_33 = V_154 -> V_165 [ V_156 - 1 ] ;
V_33 ++ ;
if ( ( V_41 -> V_145 & V_177 )
&& ! V_41 -> V_101 )
{
if ( ( memcmp ( V_41 -> V_47 -> V_110 ,
L_31 , 8 ) == 0 ) && ! ( V_158 & 1 ) )
V_41 -> V_47 -> V_178 |= V_179 ;
if ( V_41 -> V_47 -> V_178 & V_179 )
V_33 -- ;
}
if ( V_33 > ( int ) V_154 -> V_168 )
{
return - 1 ;
}
for ( V_17 = ( int ) ( V_156 - V_33 ) ; V_17 < ( int ) V_156 ; V_17 ++ )
{
if ( V_154 -> V_165 [ V_17 ] != V_158 )
{
return - 1 ;
}
}
V_154 -> V_168 -= V_33 ;
if ( V_41 -> V_108 >= V_163
&& F_50 ( V_155 ) == V_164 )
{
V_154 -> V_165 += V_157 ;
V_154 -> V_166 += V_157 ;
V_154 -> V_168 -= V_157 ;
}
}
if ( V_159 && ! V_153 )
V_154 -> V_168 -= V_159 ;
}
return ( 1 ) ;
}
int F_51 ( T_5 * V_41 , int V_190 , unsigned char * V_14 )
{
unsigned int V_24 ;
T_3 V_18 , * V_191 = NULL ;
int V_33 ;
if ( V_41 -> V_47 -> V_192 )
if ( ! F_52 ( V_41 ) )
return 0 ;
for ( V_33 = 0 ; V_33 < V_193 ; V_33 ++ )
{
if ( V_41 -> V_47 -> V_194 [ V_33 ] && F_53 ( V_41 -> V_47 -> V_194 [ V_33 ] ) == V_190 )
{
V_191 = V_41 -> V_47 -> V_194 [ V_33 ] ;
break;
}
}
if ( ! V_191 ) {
F_15 ( V_195 , V_196 ) ;
return 0 ;
}
F_4 ( & V_18 ) ;
F_54 ( & V_18 , V_191 ) ;
F_55 ( & V_18 , V_14 , & V_24 ) ;
F_11 ( & V_18 ) ;
return ( ( int ) V_24 ) ;
}
int F_56 ( T_5 * V_41 ,
const char * V_197 , int V_29 , unsigned char * V_14 )
{
unsigned int V_33 ;
T_3 V_18 ;
unsigned char V_169 [ 2 * V_22 ] ;
unsigned char * V_198 , V_199 [ 12 ] ;
int V_34 ;
long V_200 ;
int V_27 = 0 ;
const T_1 * V_1 ;
V_198 = V_169 ;
if ( V_41 -> V_47 -> V_192 )
if ( ! F_52 ( V_41 ) )
return 0 ;
F_4 ( & V_18 ) ;
for ( V_34 = 0 ; F_14 ( V_34 , & V_200 , & V_1 ) ; V_34 ++ )
{
if ( V_200 & F_17 ( V_41 ) )
{
int V_201 = F_2 ( V_1 ) ;
if ( V_201 < 0 || V_201 > ( int ) ( sizeof V_169 - ( T_2 ) ( V_198 - V_169 ) ) )
{
V_27 = 1 ;
}
else
{
F_54 ( & V_18 , V_41 -> V_47 -> V_194 [ V_34 ] ) ;
F_55 ( & V_18 , V_198 , & V_33 ) ;
if ( V_33 != ( unsigned int ) V_201 )
V_27 = 1 ;
V_198 += V_33 ;
}
}
}
if ( ! F_13 ( F_17 ( V_41 ) ,
V_197 , V_29 , V_169 , ( int ) ( V_198 - V_169 ) , NULL , 0 , NULL , 0 , NULL , 0 ,
V_41 -> V_51 -> V_52 , V_41 -> V_51 -> V_53 ,
V_14 , V_199 , sizeof V_199 ) )
V_27 = 1 ;
F_11 ( & V_18 ) ;
if ( V_27 )
return 0 ;
else
return sizeof V_199 ;
}
int F_57 ( T_5 * V_202 , unsigned char * V_1 , int V_153 )
{
T_9 * V_154 ;
unsigned char * V_170 ;
T_3 * V_141 ;
T_2 V_203 ;
int V_33 ;
T_3 V_204 , * V_74 ;
unsigned char V_169 [ 5 ] ;
int V_205 = ( V_153 ? ( V_202 -> V_97 & V_113 ) : ( V_202 -> V_97 & V_98 ) ) ;
int V_206 ;
if ( V_153 )
{
V_154 = & ( V_202 -> V_47 -> V_161 ) ;
V_170 = & ( V_202 -> V_47 -> V_117 [ 0 ] ) ;
V_141 = V_202 -> V_115 ;
}
else
{
V_154 = & ( V_202 -> V_47 -> V_106 ) ;
V_170 = & ( V_202 -> V_47 -> V_110 [ 0 ] ) ;
V_141 = V_202 -> V_100 ;
}
V_206 = F_43 ( V_141 ) ;
F_3 ( V_206 >= 0 ) ;
V_203 = V_206 ;
V_169 [ 0 ] = V_154 -> type ;
V_169 [ 1 ] = ( unsigned char ) ( V_202 -> V_108 >> 8 ) ;
V_169 [ 2 ] = ( unsigned char ) ( V_202 -> V_108 ) ;
V_169 [ 3 ] = V_154 -> V_168 >> 8 ;
V_169 [ 4 ] = V_154 -> V_168 & 0xff ;
if ( V_205 )
{
V_74 = V_141 ;
}
else
{
F_58 ( & V_204 , V_141 ) ;
V_74 = & V_204 ;
}
if ( V_202 -> V_108 == V_109 || V_202 -> V_108 == V_171 )
{
unsigned char V_172 [ 8 ] , * V_56 = V_172 ;
F_47 ( V_153 ? V_202 -> V_173 -> V_174 : V_202 -> V_173 -> V_175 , V_56 ) ;
memcpy ( V_56 , & V_170 [ 2 ] , 6 ) ;
F_8 ( V_74 , V_172 , 8 ) ;
}
else
F_8 ( V_74 , V_170 , 8 ) ;
F_8 ( V_74 , V_169 , 5 ) ;
F_8 ( V_74 , V_154 -> V_166 , V_154 -> V_168 ) ;
V_206 = F_9 ( V_74 , V_1 , & V_203 ) ;
F_3 ( V_206 > 0 ) ;
if ( ! V_205 ) F_11 ( & V_204 ) ;
#ifdef F_33
printf ( L_32 ) ;
{ unsigned int V_131 ; for ( V_131 = 0 ; V_131 < V_203 ; V_131 ++ ) printf ( L_33 , V_207 [ V_131 ] ) ; printf ( L_3 ) ; }
printf ( L_34 ) ;
{ int V_131 ; for ( V_131 = 0 ; V_131 < 8 ; V_131 ++ ) printf ( L_33 , V_170 [ V_131 ] ) ; printf ( L_3 ) ; }
printf ( L_35 ) ;
{ int V_131 ; for ( V_131 = 0 ; V_131 < 5 ; V_131 ++ ) printf ( L_33 , V_169 [ V_131 ] ) ; printf ( L_3 ) ; }
printf ( L_36 ) ;
{ unsigned int V_131 ; for ( V_131 = 0 ; V_131 < V_154 -> V_168 ; V_131 ++ ) printf ( L_33 , V_169 [ V_131 ] ) ; printf ( L_3 ) ; }
#endif
if ( V_202 -> V_108 != V_109 && V_202 -> V_108 != V_171 )
{
for ( V_33 = 7 ; V_33 >= 0 ; V_33 -- )
{
++ V_170 [ V_33 ] ;
if ( V_170 [ V_33 ] != 0 ) break;
}
}
#ifdef F_33
{ unsigned int V_131 ; for ( V_131 = 0 ; V_131 < V_203 ; V_131 ++ ) printf ( L_33 , V_1 [ V_131 ] ) ; printf ( L_3 ) ; }
#endif
return ( V_203 ) ;
}
int F_59 ( T_5 * V_41 , unsigned char * V_14 , unsigned char * V_56 ,
int V_32 )
{
unsigned char V_208 [ V_209 ] ;
const void * V_210 = NULL , * V_211 = NULL ;
int V_212 = 0 , V_213 = 0 ;
#ifdef F_18
printf ( L_37 , V_41 , V_14 , V_56 , V_32 ) ;
#endif
#ifdef F_60
if ( V_41 -> V_47 -> V_214 != NULL && V_41 -> V_47 -> V_215 != NULL &&
V_41 -> V_47 -> V_216 > 0 &&
V_41 -> V_47 -> V_216 == V_41 -> V_47 -> V_217 )
{
V_210 = V_41 -> V_47 -> V_214 ;
V_212 = V_41 -> V_47 -> V_217 ;
V_211 = V_41 -> V_47 -> V_215 ;
V_213 = V_41 -> V_47 -> V_216 ;
}
#endif
F_13 ( F_17 ( V_41 ) ,
V_218 , V_219 ,
V_41 -> V_47 -> V_50 , V_49 ,
V_210 , V_212 ,
V_41 -> V_47 -> V_48 , V_49 ,
V_211 , V_213 ,
V_56 , V_32 ,
V_41 -> V_51 -> V_52 , V_208 , sizeof V_208 ) ;
#ifdef F_61
fprintf ( V_167 , L_38 ) ;
F_62 ( V_167 , ( char * ) V_56 , V_32 ) ;
fprintf ( V_167 , L_39 ) ;
F_62 ( V_167 , ( char * ) V_41 -> V_47 -> V_50 , V_49 ) ;
fprintf ( V_167 , L_40 ) ;
F_62 ( V_167 , ( char * ) V_41 -> V_47 -> V_48 , V_49 ) ;
fprintf ( V_167 , L_41 ) ;
F_62 ( V_167 , ( char * ) V_41 -> V_51 -> V_52 , V_220 ) ;
#endif
#ifdef F_18
printf ( L_42 ) ;
#endif
return ( V_220 ) ;
}
int F_63 ( T_5 * V_41 , unsigned char * V_14 , T_2 V_15 ,
const char * V_221 , T_2 V_222 , const unsigned char * V_223 ,
T_2 V_224 , int V_225 )
{
unsigned char * V_208 ;
unsigned char * V_226 = NULL ;
T_2 V_227 , V_228 ;
int V_229 ;
#ifdef F_18
printf ( L_43 , V_41 , V_14 , V_15 , V_221 , V_222 , V_56 , V_230 ) ;
#endif
V_208 = F_22 ( V_15 ) ;
if ( V_208 == NULL ) goto V_105;
V_227 = V_222 + V_49 * 2 ;
if ( V_225 )
{
V_227 += 2 + V_224 ;
}
V_226 = F_22 ( V_227 ) ;
if ( V_226 == NULL ) goto V_105;
V_228 = 0 ;
memcpy ( V_226 + V_228 , ( unsigned char * ) V_221 , V_222 ) ;
V_228 += V_222 ;
memcpy ( V_226 + V_228 , V_41 -> V_47 -> V_50 , V_49 ) ;
V_228 += V_49 ;
memcpy ( V_226 + V_228 , V_41 -> V_47 -> V_48 , V_49 ) ;
V_228 += V_49 ;
if ( V_225 )
{
V_226 [ V_228 ] = ( V_224 >> 8 ) & 0xff ;
V_228 ++ ;
V_226 [ V_228 ] = V_224 & 0xff ;
V_228 ++ ;
if ( ( V_224 > 0 ) || ( V_223 != NULL ) )
{
memcpy ( V_226 + V_228 , V_223 , V_224 ) ;
}
}
if ( memcmp ( V_226 , V_231 ,
V_232 ) == 0 ) goto V_233;
if ( memcmp ( V_226 , V_234 ,
V_235 ) == 0 ) goto V_233;
if ( memcmp ( V_226 , V_218 ,
V_219 ) == 0 ) goto V_233;
if ( memcmp ( V_226 , V_45 ,
V_46 ) == 0 ) goto V_233;
V_229 = F_13 ( V_41 -> V_47 -> V_43 . V_81 -> V_95 ,
V_226 , V_227 ,
NULL , 0 ,
NULL , 0 ,
NULL , 0 ,
NULL , 0 ,
V_41 -> V_51 -> V_52 , V_41 -> V_51 -> V_53 ,
V_14 , V_208 , V_15 ) ;
#ifdef F_18
printf ( L_44 ) ;
#endif
goto V_24;
V_233:
F_15 ( V_236 , V_237 ) ;
V_229 = 0 ;
goto V_24;
V_105:
F_15 ( V_236 , V_138 ) ;
V_229 = 0 ;
V_24:
if ( V_208 != NULL ) F_40 ( V_208 ) ;
if ( V_226 != NULL ) F_40 ( V_226 ) ;
return ( V_229 ) ;
}
int F_64 ( int V_238 )
{
switch ( V_238 )
{
case V_239 : return ( V_240 ) ;
case V_241 : return ( V_242 ) ;
case V_243 : return ( V_244 ) ;
case V_187 : return ( V_245 ) ;
case V_246 : return ( V_247 ) ;
case V_248 : return ( V_249 ) ;
case V_250 : return ( V_251 ) ;
case V_252 : return ( - 1 ) ;
case V_253 : return ( V_254 ) ;
case V_255 : return ( V_256 ) ;
case V_257 : return ( V_258 ) ;
case V_259 : return ( V_260 ) ;
case V_261 : return ( V_262 ) ;
case V_263 : return ( V_264 ) ;
case V_265 : return ( V_266 ) ;
case V_267 : return ( V_268 ) ;
case V_269 : return ( V_270 ) ;
case V_271 : return ( V_272 ) ;
case V_273 : return ( V_274 ) ;
case V_275 : return ( V_276 ) ;
case V_277 : return ( V_278 ) ;
case V_279 : return ( V_280 ) ;
case V_281 : return ( V_282 ) ;
case V_283 : return ( V_284 ) ;
case V_285 : return ( V_286 ) ;
case V_287 : return ( V_288 ) ;
case V_289 : return ( V_290 ) ;
case V_291 : return ( V_292 ) ;
case V_293 : return ( V_294 ) ;
case V_295 : return ( V_296 ) ;
#if 0
case DTLS1_AD_MISSING_HANDSHAKE_MESSAGE: return
(DTLS1_AD_MISSING_HANDSHAKE_MESSAGE);
#endif
default: return ( - 1 ) ;
}
}

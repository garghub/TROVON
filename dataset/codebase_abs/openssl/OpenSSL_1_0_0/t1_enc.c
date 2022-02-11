static void F_1 ( const T_1 * V_1 , const unsigned char * V_2 ,
int V_3 ,
const void * V_4 , int V_5 ,
const void * V_6 , int V_7 ,
const void * V_8 , int V_9 ,
const void * V_10 , int V_11 ,
const void * V_12 , int V_13 ,
unsigned char * V_14 , int V_15 )
{
int V_16 , V_17 ;
unsigned int V_18 ;
T_2 V_19 ;
T_2 V_20 ;
unsigned char V_21 [ V_22 ] ;
unsigned int V_23 ;
V_16 = F_2 ( V_1 ) ;
F_3 ( V_16 >= 0 ) ;
F_4 ( & V_19 ) ;
F_4 ( & V_20 ) ;
F_5 ( & V_19 , V_2 , V_3 , V_1 , NULL ) ;
F_5 ( & V_20 , V_2 , V_3 , V_1 , NULL ) ;
if ( V_4 != NULL ) F_6 ( & V_19 , V_4 , V_5 ) ;
if ( V_6 != NULL ) F_6 ( & V_19 , V_6 , V_7 ) ;
if ( V_8 != NULL ) F_6 ( & V_19 , V_8 , V_9 ) ;
if ( V_10 != NULL ) F_6 ( & V_19 , V_10 , V_11 ) ;
if ( V_12 != NULL ) F_6 ( & V_19 , V_12 , V_13 ) ;
F_7 ( & V_19 , V_21 , & V_23 ) ;
V_17 = 0 ;
for (; ; )
{
F_5 ( & V_19 , NULL , 0 , NULL , NULL ) ;
F_5 ( & V_20 , NULL , 0 , NULL , NULL ) ;
F_6 ( & V_19 , V_21 , V_23 ) ;
F_6 ( & V_20 , V_21 , V_23 ) ;
if ( V_4 != NULL ) F_6 ( & V_19 , V_4 , V_5 ) ;
if ( V_6 != NULL ) F_6 ( & V_19 , V_6 , V_7 ) ;
if ( V_8 != NULL ) F_6 ( & V_19 , V_8 , V_9 ) ;
if ( V_10 != NULL ) F_6 ( & V_19 , V_10 , V_11 ) ;
if ( V_12 != NULL ) F_6 ( & V_19 , V_12 , V_13 ) ;
if ( V_15 > V_16 )
{
F_7 ( & V_19 , V_14 , & V_18 ) ;
V_14 += V_18 ;
V_15 -= V_18 ;
F_7 ( & V_20 , V_21 , & V_23 ) ;
}
else
{
F_7 ( & V_19 , V_21 , & V_23 ) ;
memcpy ( V_14 , V_21 , V_15 ) ;
break;
}
}
F_8 ( & V_19 ) ;
F_8 ( & V_20 ) ;
F_9 ( V_21 , sizeof( V_21 ) ) ;
}
static void F_10 ( long V_24 ,
const void * V_4 , int V_5 ,
const void * V_6 , int V_7 ,
const void * V_8 , int V_9 ,
const void * V_10 , int V_11 ,
const void * V_12 , int V_13 ,
const unsigned char * V_2 , int V_25 ,
unsigned char * V_26 ,
unsigned char * V_27 , int V_15 )
{
int V_28 , V_29 , V_30 , V_31 ;
const unsigned char * V_32 ;
long V_33 ;
const T_1 * V_1 ;
V_31 = 0 ;
for ( V_30 = 0 ; F_11 ( V_30 , & V_33 , & V_1 ) ; V_30 ++ ) {
if ( ( V_33 << V_34 ) & V_24 ) V_31 ++ ;
}
V_28 = V_25 / V_31 ;
V_32 = V_2 ;
memset ( V_26 , 0 , V_15 ) ;
for ( V_30 = 0 ; F_11 ( V_30 , & V_33 , & V_1 ) ; V_30 ++ ) {
if ( ( V_33 << V_34 ) & V_24 ) {
if ( ! V_1 ) {
F_12 ( V_35 ,
V_36 ) ;
return;
}
F_1 ( V_1 , V_32 , V_28 + ( V_25 & 1 ) ,
V_4 , V_5 , V_6 , V_7 , V_8 , V_9 , V_10 , V_11 , V_12 , V_13 ,
V_27 , V_15 ) ;
V_32 += V_28 ;
for ( V_29 = 0 ; V_29 < V_15 ; V_29 ++ )
{
V_26 [ V_29 ] ^= V_27 [ V_29 ] ;
}
}
}
}
static void F_13 ( T_3 * V_37 , unsigned char * V_38 ,
unsigned char * V_39 , int V_40 )
{
F_10 ( V_37 -> V_41 -> V_39 . V_42 -> V_43 ,
V_44 , V_45 ,
V_37 -> V_41 -> V_46 , V_47 ,
V_37 -> V_41 -> V_48 , V_47 ,
NULL , 0 , NULL , 0 ,
V_37 -> V_49 -> V_50 , V_37 -> V_49 -> V_51 ,
V_38 , V_39 , V_40 ) ;
#ifdef F_14
printf ( L_1 ,
V_37 -> V_49 -> V_51 ) ;
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_37 -> V_49 -> V_51 ; V_29 ++ )
{
printf ( L_2 , V_37 -> V_49 -> V_50 [ V_29 ] ) ;
}
printf ( L_3 ) ; }
#endif
}
int F_15 ( T_3 * V_37 , int V_52 )
{
static const unsigned char V_53 [] = L_4 ;
unsigned char * V_54 , * V_55 , * V_56 ;
unsigned char * V_57 ;
unsigned char V_58 [ V_59 ] ;
unsigned char V_60 [ V_59 ] ;
unsigned char V_61 [ V_62 * 2 ] ;
unsigned char V_63 [ V_62 * 2 ] ;
unsigned char * V_64 , * V_65 , * V_66 , * V_67 , * V_68 ;
int V_69 ;
T_4 * V_70 ;
const T_5 * V_71 ;
#ifndef F_16
const T_6 * V_72 ;
#endif
const T_1 * V_33 ;
int V_73 ;
int * V_74 ;
T_7 * V_75 ;
T_8 * V_76 ;
int V_77 , V_17 , V_29 , V_18 , V_78 , V_79 , V_80 ;
int V_81 = 0 ;
V_77 = F_17 ( V_37 -> V_41 -> V_39 . V_42 ) ;
V_71 = V_37 -> V_41 -> V_39 . V_82 ;
V_33 = V_37 -> V_41 -> V_39 . V_83 ;
V_73 = V_37 -> V_41 -> V_39 . V_84 ;
#ifndef F_16
V_72 = V_37 -> V_41 -> V_39 . V_85 ;
#endif
V_55 = V_37 -> V_41 -> V_39 . V_55 ;
#ifdef F_14
printf ( L_5 , V_52 ) ;
printf ( L_6 ,
V_37 -> V_41 -> V_39 . V_42 -> V_86 ,
V_37 -> V_41 -> V_39 . V_42 -> V_87 ,
V_72 ) ;
printf ( L_7 , V_71 ) ;
printf ( L_8 ,
V_71 -> V_88 , V_71 -> V_89 , V_71 -> V_90 , V_71 -> V_91 ) ;
printf ( L_9 , V_37 -> V_41 -> V_39 . V_92 ) ;
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_37 -> V_41 -> V_39 . V_92 ; V_29 ++ )
printf ( L_10 , V_55 [ V_29 ] ) ; printf ( L_3 ) ;
}
#endif
if ( V_52 & V_93 )
{
if ( V_37 -> V_41 -> V_39 . V_42 -> V_43 & V_94 )
V_37 -> V_95 |= V_96 ;
else
V_37 -> V_95 &= ~ V_96 ;
if ( V_37 -> V_97 != NULL )
V_81 = 1 ;
else if ( ( V_37 -> V_97 = F_18 ( sizeof( T_4 ) ) ) == NULL )
goto V_98;
else
F_19 ( V_37 -> V_97 ) ;
V_70 = V_37 -> V_97 ;
V_75 = F_20 ( & V_37 -> V_99 , NULL ) ;
#ifndef F_16
if ( V_37 -> V_100 != NULL )
{
F_21 ( V_37 -> V_100 ) ;
V_37 -> V_100 = NULL ;
}
if ( V_72 != NULL )
{
V_37 -> V_100 = F_22 ( V_72 -> V_101 ) ;
if ( V_37 -> V_100 == NULL )
{
F_12 ( V_102 , V_103 ) ;
goto V_104;
}
if ( V_37 -> V_41 -> V_105 . V_72 == NULL )
V_37 -> V_41 -> V_105 . V_72 = ( unsigned char * )
F_18 ( V_106 ) ;
if ( V_37 -> V_41 -> V_105 . V_72 == NULL )
goto V_98;
}
#endif
if ( V_37 -> V_107 != V_108 )
memset ( & ( V_37 -> V_41 -> V_109 [ 0 ] ) , 0 , 8 ) ;
V_56 = & ( V_37 -> V_41 -> V_110 [ 0 ] ) ;
V_74 = & ( V_37 -> V_41 -> V_111 ) ;
}
else
{
if ( V_37 -> V_41 -> V_39 . V_42 -> V_43 & V_94 )
V_37 -> V_95 |= V_112 ;
else
V_37 -> V_95 &= ~ V_112 ;
if ( V_37 -> V_113 != NULL )
V_81 = 1 ;
else if ( ( V_37 -> V_113 = F_18 ( sizeof( T_4 ) ) ) == NULL )
goto V_98;
else
F_19 ( V_37 -> V_113 ) ;
V_70 = V_37 -> V_113 ;
V_75 = F_20 ( & V_37 -> V_114 , NULL ) ;
#ifndef F_16
if ( V_37 -> V_115 != NULL )
{
F_21 ( V_37 -> V_115 ) ;
V_37 -> V_115 = NULL ;
}
if ( V_72 != NULL )
{
V_37 -> V_115 = F_22 ( V_72 -> V_101 ) ;
if ( V_37 -> V_115 == NULL )
{
F_12 ( V_102 , V_103 ) ;
goto V_104;
}
}
#endif
if ( V_37 -> V_107 != V_108 )
memset ( & ( V_37 -> V_41 -> V_116 [ 0 ] ) , 0 , 8 ) ;
V_56 = & ( V_37 -> V_41 -> V_117 [ 0 ] ) ;
V_74 = & ( V_37 -> V_41 -> V_118 ) ;
}
if ( V_81 )
F_23 ( V_70 ) ;
V_54 = V_37 -> V_41 -> V_39 . V_55 ;
V_29 = * V_74 = V_37 -> V_41 -> V_39 . V_119 ;
V_80 = F_24 ( V_71 ) ;
V_18 = V_77 ? ( V_80 < F_25 ( V_37 -> V_41 -> V_39 . V_42 ) ?
V_80 : F_25 ( V_37 -> V_41 -> V_39 . V_42 ) ) : V_80 ;
V_78 = F_26 ( V_71 ) ;
V_67 = & ( V_37 -> V_41 -> V_48 [ 0 ] ) ;
V_68 = & ( V_37 -> V_41 -> V_46 [ 0 ] ) ;
if ( ( V_52 == V_120 ) ||
( V_52 == V_121 ) )
{
V_64 = & ( V_54 [ 0 ] ) ; V_17 = V_29 + V_29 ;
V_65 = & ( V_54 [ V_17 ] ) ; V_17 += V_18 + V_18 ;
V_66 = & ( V_54 [ V_17 ] ) ; V_17 += V_78 + V_78 ;
V_57 = ( unsigned char * ) V_122 ;
V_79 = V_123 ;
V_69 = 1 ;
}
else
{
V_17 = V_29 ;
V_64 = & ( V_54 [ V_17 ] ) ; V_17 += V_29 + V_18 ;
V_65 = & ( V_54 [ V_17 ] ) ; V_17 += V_18 + V_78 ;
V_66 = & ( V_54 [ V_17 ] ) ; V_17 += V_78 ;
V_57 = ( unsigned char * ) V_124 ;
V_79 = V_125 ;
V_69 = 0 ;
}
if ( V_17 > V_37 -> V_41 -> V_39 . V_92 )
{
F_12 ( V_102 , V_126 ) ;
goto V_104;
}
memcpy ( V_56 , V_64 , V_29 ) ;
V_76 = F_27 ( V_73 , NULL ,
V_56 , * V_74 ) ;
F_28 ( V_75 , NULL , V_33 , NULL , V_76 ) ;
F_29 ( V_76 ) ;
#ifdef F_30
printf ( L_11 , V_52 ) ;
{ int V_127 ; for ( V_127 = 0 ; V_127 < V_29 ; V_127 ++ ) printf ( L_12 , V_64 [ V_127 ] , ( ( V_127 + 1 ) % 16 ) ? ' ' : '\n' ) ; }
#endif
if ( V_77 )
{
F_10 ( V_37 -> V_41 -> V_39 . V_42 -> V_43 ,
V_57 , V_79 ,
V_37 -> V_41 -> V_48 , V_47 ,
V_37 -> V_41 -> V_46 , V_47 ,
NULL , 0 , NULL , 0 ,
V_65 , V_18 , V_58 , V_60 , F_24 ( V_71 ) ) ;
V_65 = V_58 ;
if ( V_78 > 0 )
{
F_10 ( V_37 -> V_41 -> V_39 . V_42 -> V_43 ,
V_128 , V_129 ,
V_37 -> V_41 -> V_48 , V_47 ,
V_37 -> V_41 -> V_46 , V_47 ,
NULL , 0 , NULL , 0 ,
V_53 , 0 , V_61 , V_63 , V_78 * 2 ) ;
if ( V_69 )
V_66 = V_61 ;
else
V_66 = & ( V_61 [ V_78 ] ) ;
}
}
V_37 -> V_49 -> V_130 = 0 ;
#ifdef F_14
{
int V_29 ;
printf ( L_13 ) ;
printf ( L_14 ) ; for ( V_29 = 0 ; V_29 < V_71 -> V_90 ; V_29 ++ ) printf ( L_10 , V_65 [ V_29 ] ) ;
printf ( L_3 ) ;
printf ( L_15 ) ; for ( V_29 = 0 ; V_29 < V_71 -> V_91 ; V_29 ++ ) printf ( L_10 , V_66 [ V_29 ] ) ;
printf ( L_3 ) ;
}
#endif
F_31 ( V_70 , V_71 , NULL , V_65 , V_66 , ( V_52 & V_131 ) ) ;
#ifdef F_30
printf ( L_16 , V_52 ) ;
{ int V_127 ; for ( V_127 = 0 ; V_127 < F_24 ( V_71 ) ; V_127 ++ ) printf ( L_12 , V_65 [ V_127 ] , ( ( V_127 + 1 ) % 16 ) ? ' ' : '\n' ) ; }
printf ( L_17 ) ;
{ int V_127 ; for ( V_127 = 0 ; V_127 < V_78 ; V_127 ++ ) printf ( L_12 , V_66 [ V_127 ] , ( ( V_127 + 1 ) % 16 ) ? ' ' : '\n' ) ; }
printf ( L_3 ) ;
#endif
F_9 ( V_58 , sizeof( V_58 ) ) ;
F_9 ( V_60 , sizeof( V_58 ) ) ;
F_9 ( V_61 , sizeof( V_61 ) ) ;
F_9 ( V_63 , sizeof( V_63 ) ) ;
return ( 1 ) ;
V_98:
F_12 ( V_102 , V_132 ) ;
V_104:
return ( 0 ) ;
}
int F_32 ( T_3 * V_37 )
{
unsigned char * V_133 , * V_134 ;
const T_5 * V_71 ;
const T_1 * V_135 ;
int V_40 ;
T_6 * V_72 ;
int V_73 = V_136 , V_74 = 0 ;
#ifdef F_14
printf ( L_18 ) ;
#endif
if ( V_37 -> V_41 -> V_39 . V_92 != 0 )
return ( 1 ) ;
if ( ! F_33 ( V_37 -> V_49 , & V_71 , & V_135 , & V_73 , & V_74 , & V_72 ) )
{
F_12 ( V_137 , V_138 ) ;
return ( 0 ) ;
}
V_37 -> V_41 -> V_39 . V_82 = V_71 ;
V_37 -> V_41 -> V_39 . V_83 = V_135 ;
V_37 -> V_41 -> V_39 . V_84 = V_73 ;
V_37 -> V_41 -> V_39 . V_119 = V_74 ;
V_40 = F_24 ( V_71 ) + V_74 + F_26 ( V_71 ) ;
V_40 *= 2 ;
F_34 ( V_37 ) ;
if ( ( V_133 = ( unsigned char * ) F_18 ( V_40 ) ) == NULL )
goto V_98;
if ( ( V_134 = ( unsigned char * ) F_18 ( V_40 ) ) == NULL )
goto V_98;
V_37 -> V_41 -> V_39 . V_92 = V_40 ;
V_37 -> V_41 -> V_39 . V_55 = V_133 ;
#ifdef F_30
printf ( L_19 ) ;
{ int V_127 ; for ( V_127 = 0 ; V_127 < V_47 ; V_127 ++ ) printf ( L_12 , V_37 -> V_41 -> V_48 [ V_127 ] , ( ( V_127 + 1 ) % 16 ) ? ' ' : '\n' ) ; }
printf ( L_20 ) ;
{ int V_127 ; for ( V_127 = 0 ; V_127 < V_47 ; V_127 ++ ) printf ( L_12 , V_37 -> V_41 -> V_46 [ V_127 ] , ( ( V_127 + 1 ) % 16 ) ? ' ' : '\n' ) ; }
printf ( L_21 ) ;
{ int V_127 ; for ( V_127 = 0 ; V_127 < V_37 -> V_49 -> V_51 ; V_127 ++ ) printf ( L_12 , V_37 -> V_49 -> V_50 [ V_127 ] , ( ( V_127 + 1 ) % 16 ) ? ' ' : '\n' ) ; }
#endif
F_13 ( V_37 , V_133 , V_134 , V_40 ) ;
F_9 ( V_134 , V_40 ) ;
F_35 ( V_134 ) ;
#ifdef F_30
printf ( L_22 ) ;
{ int V_127 ; for ( V_127 = 0 ; V_127 < V_40 ; V_127 ++ ) printf ( L_12 , V_133 [ V_127 ] , ( ( V_127 + 1 ) % 16 ) ? ' ' : '\n' ) ; }
#endif
if ( ! ( V_37 -> V_139 & V_140 ) )
{
V_37 -> V_41 -> V_141 = 1 ;
if ( V_37 -> V_49 -> V_142 != NULL )
{
if ( V_37 -> V_49 -> V_142 -> V_143 == V_144 )
V_37 -> V_41 -> V_141 = 0 ;
#ifndef F_36
if ( V_37 -> V_49 -> V_142 -> V_143 == V_145 )
V_37 -> V_41 -> V_141 = 0 ;
#endif
}
}
return ( 1 ) ;
V_98:
F_12 ( V_137 , V_132 ) ;
return ( 0 ) ;
}
int F_37 ( T_3 * V_37 , int V_146 )
{
T_9 * V_147 ;
T_4 * V_148 ;
unsigned long V_149 ;
int V_150 , V_29 , V_151 , V_18 , V_78 , V_17 = 0 ;
const T_5 * V_152 ;
if ( V_146 )
{
if ( F_38 ( V_37 -> V_114 ) )
{
V_17 = F_39 ( V_37 -> V_114 ) ;
F_3 ( V_17 >= 0 ) ;
}
V_148 = V_37 -> V_113 ;
V_147 = & ( V_37 -> V_41 -> V_153 ) ;
if ( V_37 -> V_113 == NULL )
V_152 = NULL ;
else
V_152 = F_40 ( V_37 -> V_113 ) ;
}
else
{
if ( F_38 ( V_37 -> V_99 ) )
{
V_17 = F_39 ( V_37 -> V_99 ) ;
F_3 ( V_17 >= 0 ) ;
}
V_148 = V_37 -> V_97 ;
V_147 = & ( V_37 -> V_41 -> V_105 ) ;
if ( V_37 -> V_97 == NULL )
V_152 = NULL ;
else
V_152 = F_40 ( V_37 -> V_97 ) ;
}
#ifdef F_14
printf ( L_23 , V_146 ) ;
#endif
if ( ( V_37 -> V_49 == NULL ) || ( V_148 == NULL ) ||
( V_152 == NULL ) )
{
memmove ( V_147 -> V_154 , V_147 -> V_155 , V_147 -> V_156 ) ;
V_147 -> V_155 = V_147 -> V_154 ;
}
else
{
V_149 = V_147 -> V_156 ;
V_150 = F_41 ( V_148 -> V_142 ) ;
if ( ( V_150 != 1 ) && V_146 )
{
V_29 = V_150 - ( ( int ) V_149 % V_150 ) ;
V_18 = V_29 - 1 ;
if ( V_37 -> V_139 & V_157 )
{
if ( V_37 -> V_41 -> V_158 & V_159 )
V_18 ++ ;
}
for ( V_78 = ( int ) V_149 ; V_78 < ( int ) ( V_149 + V_29 ) ; V_78 ++ )
V_147 -> V_155 [ V_78 ] = V_18 ;
V_149 += V_29 ;
V_147 -> V_156 += V_29 ;
}
#ifdef F_14
{
unsigned long V_160 ;
printf ( L_24 ,
V_148 , V_147 -> V_154 , V_147 -> V_155 , V_149 ) ;
printf ( L_25 ,
V_148 -> V_161 , V_148 -> V_142 -> V_90 ,
V_162 , V_163 ,
V_148 -> V_142 -> V_91 ) ;
printf ( L_26 ) ;
for ( V_29 = 0 ; V_29 < V_148 -> V_142 -> V_91 ; V_29 ++ ) printf ( L_2 , V_148 -> V_66 [ V_29 ] ) ;
printf ( L_3 ) ;
printf ( L_27 ) ;
for ( V_160 = 0 ; V_160 < V_149 ; V_160 ++ ) printf ( L_28 , V_147 -> V_155 [ V_160 ] ) ;
printf ( L_3 ) ;
}
#endif
if ( ! V_146 )
{
if ( V_149 == 0 || V_149 % V_150 != 0 )
{
F_12 ( V_164 , V_165 ) ;
F_42 ( V_37 , V_166 , V_167 ) ;
return 0 ;
}
}
F_43 ( V_148 , V_147 -> V_154 , V_147 -> V_155 , V_149 ) ;
#ifdef F_14
{
unsigned long V_29 ;
printf ( L_29 ) ;
for ( V_29 = 0 ; V_29 < V_149 ; V_29 ++ )
printf ( L_28 , V_147 -> V_154 [ V_29 ] ) ; printf ( L_3 ) ;
}
#endif
if ( ( V_150 != 1 ) && ! V_146 )
{
V_151 = V_29 = V_147 -> V_154 [ V_149 - 1 ] ;
V_29 ++ ;
if ( ( V_37 -> V_139 & V_157 )
&& ! V_37 -> V_100 )
{
if ( ( memcmp ( V_37 -> V_41 -> V_109 ,
L_30 , 8 ) == 0 ) && ! ( V_151 & 1 ) )
V_37 -> V_41 -> V_158 |= V_159 ;
if ( V_37 -> V_41 -> V_158 & V_159 )
V_29 -- ;
}
if ( V_29 > ( int ) V_147 -> V_156 )
{
return - 1 ;
}
for ( V_18 = ( int ) ( V_149 - V_29 ) ; V_18 < ( int ) V_149 ; V_18 ++ )
{
if ( V_147 -> V_154 [ V_18 ] != V_151 )
{
return - 1 ;
}
}
V_147 -> V_156 -= V_29 ;
}
}
return ( 1 ) ;
}
int F_44 ( T_3 * V_37 , int V_168 , unsigned char * V_14 )
{
unsigned int V_169 ;
T_7 V_19 , * V_170 = NULL ;
int V_29 ;
if ( V_37 -> V_41 -> V_171 )
if ( ! F_45 ( V_37 ) )
return 0 ;
for ( V_29 = 0 ; V_29 < V_172 ; V_29 ++ )
{
if ( V_37 -> V_41 -> V_173 [ V_29 ] && F_46 ( V_37 -> V_41 -> V_173 [ V_29 ] ) == V_168 )
{
V_170 = V_37 -> V_41 -> V_173 [ V_29 ] ;
break;
}
}
if ( ! V_170 ) {
F_12 ( V_174 , V_175 ) ;
return 0 ;
}
F_47 ( & V_19 ) ;
F_48 ( & V_19 , V_170 ) ;
F_49 ( & V_19 , V_14 , & V_169 ) ;
F_50 ( & V_19 ) ;
return ( ( int ) V_169 ) ;
}
int F_51 ( T_3 * V_37 ,
const char * V_176 , int V_25 , unsigned char * V_14 )
{
unsigned int V_29 ;
T_7 V_19 ;
unsigned char V_177 [ 2 * V_22 ] ;
unsigned char * V_178 , V_179 [ 12 ] ;
int V_30 ;
long V_180 ;
int V_98 = 0 ;
const T_1 * V_1 ;
V_178 = V_177 ;
if ( V_37 -> V_41 -> V_171 )
if ( ! F_45 ( V_37 ) )
return 0 ;
F_47 ( & V_19 ) ;
for ( V_30 = 0 ; F_11 ( V_30 , & V_180 , & V_1 ) ; V_30 ++ )
{
if ( V_180 & V_37 -> V_41 -> V_39 . V_42 -> V_43 )
{
int V_181 = F_2 ( V_1 ) ;
if ( V_181 < 0 || V_181 > ( int ) ( sizeof V_177 - ( V_182 ) ( V_178 - V_177 ) ) )
{
V_98 = 1 ;
}
else
{
F_48 ( & V_19 , V_37 -> V_41 -> V_173 [ V_30 ] ) ;
F_49 ( & V_19 , V_178 , & V_29 ) ;
if ( V_29 != ( unsigned int ) V_181 )
V_98 = 1 ;
V_178 += V_29 ;
}
}
}
F_10 ( V_37 -> V_41 -> V_39 . V_42 -> V_43 ,
V_176 , V_25 , V_177 , ( int ) ( V_178 - V_177 ) , NULL , 0 , NULL , 0 , NULL , 0 ,
V_37 -> V_49 -> V_50 , V_37 -> V_49 -> V_51 ,
V_14 , V_179 , sizeof V_179 ) ;
F_50 ( & V_19 ) ;
if ( V_98 )
return 0 ;
else
return sizeof V_179 ;
}
int F_52 ( T_3 * V_183 , unsigned char * V_1 , int V_146 )
{
T_9 * V_147 ;
unsigned char * V_184 , * V_185 ;
T_7 * V_135 ;
V_182 V_186 ;
int V_29 ;
T_7 V_187 , * V_75 ;
unsigned char V_177 [ 5 ] ;
int V_188 = ( V_146 ? ( V_183 -> V_95 & V_112 ) : ( V_183 -> V_95 & V_96 ) ) ;
int V_189 ;
if ( V_146 )
{
V_147 = & ( V_183 -> V_41 -> V_153 ) ;
V_184 = & ( V_183 -> V_41 -> V_117 [ 0 ] ) ;
V_185 = & ( V_183 -> V_41 -> V_116 [ 0 ] ) ;
V_135 = V_183 -> V_114 ;
}
else
{
V_147 = & ( V_183 -> V_41 -> V_105 ) ;
V_184 = & ( V_183 -> V_41 -> V_110 [ 0 ] ) ;
V_185 = & ( V_183 -> V_41 -> V_109 [ 0 ] ) ;
V_135 = V_183 -> V_99 ;
}
V_189 = F_39 ( V_135 ) ;
F_3 ( V_189 >= 0 ) ;
V_186 = V_189 ;
V_177 [ 0 ] = V_147 -> type ;
V_177 [ 1 ] = ( unsigned char ) ( V_183 -> V_107 >> 8 ) ;
V_177 [ 2 ] = ( unsigned char ) ( V_183 -> V_107 ) ;
V_177 [ 3 ] = V_147 -> V_156 >> 8 ;
V_177 [ 4 ] = V_147 -> V_156 & 0xff ;
if ( V_188 )
{
V_75 = V_135 ;
}
else
{
F_53 ( & V_187 , V_135 ) ;
V_75 = & V_187 ;
}
if ( V_183 -> V_107 == V_108 || V_183 -> V_107 == V_190 )
{
unsigned char V_191 [ 8 ] , * V_54 = V_191 ;
F_54 ( V_146 ? V_183 -> V_192 -> V_193 : V_183 -> V_192 -> V_194 , V_54 ) ;
memcpy ( V_54 , & V_185 [ 2 ] , 6 ) ;
F_55 ( V_75 , V_191 , 8 ) ;
}
else
F_55 ( V_75 , V_185 , 8 ) ;
F_55 ( V_75 , V_177 , 5 ) ;
F_55 ( V_75 , V_147 -> V_155 , V_147 -> V_156 ) ;
V_189 = F_56 ( V_75 , V_1 , & V_186 ) ;
F_3 ( V_189 > 0 ) ;
if ( ! V_188 ) F_50 ( & V_187 ) ;
#ifdef F_30
printf ( L_31 ) ;
{ unsigned int V_127 ; for ( V_127 = 0 ; V_127 < V_186 ; V_127 ++ ) printf ( L_32 , V_184 [ V_127 ] ) ; printf ( L_3 ) ; }
printf ( L_33 ) ;
{ int V_127 ; for ( V_127 = 0 ; V_127 < 8 ; V_127 ++ ) printf ( L_32 , V_185 [ V_127 ] ) ; printf ( L_3 ) ; }
printf ( L_34 ) ;
{ int V_127 ; for ( V_127 = 0 ; V_127 < 5 ; V_127 ++ ) printf ( L_32 , V_177 [ V_127 ] ) ; printf ( L_3 ) ; }
printf ( L_35 ) ;
{ unsigned int V_127 ; for ( V_127 = 0 ; V_127 < V_147 -> V_156 ; V_127 ++ ) printf ( L_32 , V_177 [ V_127 ] ) ; printf ( L_3 ) ; }
#endif
if ( V_183 -> V_107 != V_108 && V_183 -> V_107 != V_190 )
{
for ( V_29 = 7 ; V_29 >= 0 ; V_29 -- )
{
++ V_185 [ V_29 ] ;
if ( V_185 [ V_29 ] != 0 ) break;
}
}
#ifdef F_30
{ unsigned int V_127 ; for ( V_127 = 0 ; V_127 < V_186 ; V_127 ++ ) printf ( L_32 , V_1 [ V_127 ] ) ; printf ( L_3 ) ; }
#endif
return ( V_186 ) ;
}
int F_57 ( T_3 * V_37 , unsigned char * V_14 , unsigned char * V_54 ,
int V_28 )
{
unsigned char V_195 [ V_196 ] ;
const void * V_197 = NULL , * V_198 = NULL ;
int V_199 = 0 , V_200 = 0 ;
#ifdef F_14
printf ( L_36 , V_37 , V_14 , V_54 , V_28 ) ;
#endif
#ifdef F_58
if ( V_37 -> V_41 -> V_201 != NULL && V_37 -> V_41 -> V_202 != NULL &&
V_37 -> V_41 -> V_203 > 0 &&
V_37 -> V_41 -> V_203 == V_37 -> V_41 -> V_204 )
{
V_197 = V_37 -> V_41 -> V_201 ;
V_199 = V_37 -> V_41 -> V_204 ;
V_198 = V_37 -> V_41 -> V_202 ;
V_200 = V_37 -> V_41 -> V_203 ;
}
#endif
F_10 ( V_37 -> V_41 -> V_39 . V_42 -> V_43 ,
V_205 , V_206 ,
V_37 -> V_41 -> V_48 , V_47 ,
V_197 , V_199 ,
V_37 -> V_41 -> V_46 , V_47 ,
V_198 , V_200 ,
V_54 , V_28 ,
V_37 -> V_49 -> V_50 , V_195 , sizeof V_195 ) ;
#ifdef F_14
printf ( L_37 ) ;
#endif
return ( V_207 ) ;
}
int F_59 ( int V_208 )
{
switch ( V_208 )
{
case V_209 : return ( V_210 ) ;
case V_211 : return ( V_212 ) ;
case V_213 : return ( V_214 ) ;
case V_167 : return ( V_215 ) ;
case V_216 : return ( V_217 ) ;
case V_218 : return ( V_219 ) ;
case V_220 : return ( V_221 ) ;
case V_222 : return ( - 1 ) ;
case V_223 : return ( V_224 ) ;
case V_225 : return ( V_226 ) ;
case V_227 : return ( V_228 ) ;
case V_229 : return ( V_230 ) ;
case V_231 : return ( V_232 ) ;
case V_233 : return ( V_234 ) ;
case V_235 : return ( V_236 ) ;
case V_237 : return ( V_238 ) ;
case V_239 : return ( V_240 ) ;
case V_241 : return ( V_242 ) ;
case V_243 : return ( V_244 ) ;
case V_245 : return ( V_246 ) ;
case V_247 : return ( V_248 ) ;
case V_249 : return ( V_250 ) ;
case V_251 : return ( V_252 ) ;
case V_253 : return ( V_254 ) ;
case V_255 : return ( V_256 ) ;
case V_257 : return ( V_258 ) ;
case V_259 : return ( V_260 ) ;
case V_261 : return ( V_262 ) ;
case V_263 : return ( V_264 ) ;
case V_265 : return ( V_266 ) ;
#if 0
case DTLS1_AD_MISSING_HANDSHAKE_MESSAGE: return
(DTLS1_AD_MISSING_HANDSHAKE_MESSAGE);
#endif
default: return ( - 1 ) ;
}
}

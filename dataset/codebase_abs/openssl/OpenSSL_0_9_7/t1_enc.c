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
F_3 ( & V_11 ) ;
F_3 ( & V_12 ) ;
F_4 ( & V_11 , V_2 , V_3 , V_1 , NULL ) ;
F_4 ( & V_12 , V_2 , V_3 , V_1 , NULL ) ;
F_5 ( & V_11 , V_4 , V_5 ) ;
F_6 ( & V_11 , V_13 , & V_15 ) ;
V_9 = 0 ;
for (; ; )
{
F_4 ( & V_11 , NULL , 0 , NULL , NULL ) ;
F_4 ( & V_12 , NULL , 0 , NULL , NULL ) ;
F_5 ( & V_11 , V_13 , V_15 ) ;
F_5 ( & V_12 , V_13 , V_15 ) ;
F_5 ( & V_11 , V_4 , V_5 ) ;
if ( V_7 > V_8 )
{
F_6 ( & V_11 , V_6 , & V_10 ) ;
V_6 += V_10 ;
V_7 -= V_10 ;
F_6 ( & V_12 , V_13 , & V_15 ) ;
}
else
{
F_6 ( & V_11 , V_13 , & V_15 ) ;
memcpy ( V_6 , V_13 , V_7 ) ;
break;
}
}
F_7 ( & V_11 ) ;
F_7 ( & V_12 ) ;
F_8 ( V_13 , sizeof( V_13 ) ) ;
}
static void F_9 ( const T_1 * V_16 , const T_1 * V_17 ,
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
static void F_10 ( T_3 * V_27 , unsigned char * V_28 ,
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
F_9 ( V_27 -> V_11 -> V_16 , V_27 -> V_11 -> V_17 , V_32 , ( int ) ( V_31 - V_32 ) ,
V_27 -> V_40 -> V_41 , V_27 -> V_40 -> V_42 ,
V_28 , V_29 , V_30 ) ;
#ifdef F_11
printf ( L_1 ,
V_27 -> V_40 -> V_42 ) ;
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_27 -> V_40 -> V_42 ; V_24 ++ )
{
printf ( L_2 , V_27 -> V_40 -> V_41 [ V_24 ] ) ;
}
printf ( L_3 ) ; }
#endif
}
int F_12 ( T_3 * V_27 , int V_43 )
{
static const unsigned char V_44 [] = L_4 ;
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
int V_68 = 0 ;
V_64 = F_13 ( V_27 -> V_37 -> V_29 . V_69 ) ;
V_61 = V_27 -> V_37 -> V_29 . V_70 ;
V_63 = V_27 -> V_37 -> V_29 . V_71 ;
V_62 = V_27 -> V_37 -> V_29 . V_72 ;
V_45 = V_27 -> V_37 -> V_29 . V_45 ;
#ifdef F_11
printf ( L_5 , V_43 ) ;
printf ( L_6 , V_27 -> V_37 -> V_29 . V_69 -> V_73 ,
V_62 ) ;
printf ( L_7 , V_61 ) ;
printf ( L_8 ,
V_61 -> V_74 , V_61 -> V_75 , V_61 -> V_76 , V_61 -> V_77 ) ;
printf ( L_9 , V_27 -> V_37 -> V_29 . V_78 ) ;
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_27 -> V_37 -> V_29 . V_78 ; V_24 ++ )
printf ( L_10 , V_45 [ V_24 ] ) ; printf ( L_3 ) ;
}
#endif
if ( V_43 & V_79 )
{
if ( V_27 -> V_80 != NULL )
V_68 = 1 ;
else if ( ( V_27 -> V_80 = F_14 ( sizeof( T_4 ) ) ) == NULL )
goto V_81;
V_60 = V_27 -> V_80 ;
V_27 -> V_82 = V_63 ;
if ( V_27 -> V_83 != NULL )
{
F_15 ( V_27 -> V_83 ) ;
V_27 -> V_83 = NULL ;
}
if ( V_62 != NULL )
{
V_27 -> V_83 = F_16 ( V_62 -> V_84 ) ;
if ( V_27 -> V_83 == NULL )
{
F_17 ( V_85 , V_86 ) ;
goto V_87;
}
if ( V_27 -> V_37 -> V_88 . V_62 == NULL )
V_27 -> V_37 -> V_88 . V_62 = ( unsigned char * )
F_14 ( V_89 ) ;
if ( V_27 -> V_37 -> V_88 . V_62 == NULL )
goto V_81;
}
memset ( & ( V_27 -> V_37 -> V_90 [ 0 ] ) , 0 , 8 ) ;
V_46 = & ( V_27 -> V_37 -> V_91 [ 0 ] ) ;
}
else
{
if ( V_27 -> V_92 != NULL )
V_68 = 1 ;
else if ( ( V_27 -> V_92 = F_14 ( sizeof( T_4 ) ) ) == NULL )
goto V_81;
if ( ( V_27 -> V_92 == NULL ) &&
( ( V_27 -> V_92 = ( T_4 * )
F_14 ( sizeof( T_4 ) ) ) == NULL ) )
goto V_81;
V_60 = V_27 -> V_92 ;
V_27 -> V_93 = V_63 ;
if ( V_27 -> V_94 != NULL )
{
F_15 ( V_27 -> V_94 ) ;
V_27 -> V_94 = NULL ;
}
if ( V_62 != NULL )
{
V_27 -> V_94 = F_16 ( V_62 -> V_84 ) ;
if ( V_27 -> V_94 == NULL )
{
F_17 ( V_85 , V_86 ) ;
goto V_87;
}
}
memset ( & ( V_27 -> V_37 -> V_95 [ 0 ] ) , 0 , 8 ) ;
V_46 = & ( V_27 -> V_37 -> V_96 [ 0 ] ) ;
}
if ( V_68 )
F_18 ( V_60 ) ;
F_19 ( V_60 ) ;
V_31 = V_27 -> V_37 -> V_29 . V_45 ;
V_24 = F_2 ( V_63 ) ;
V_67 = F_20 ( V_61 ) ;
V_10 = V_64 ? ( V_67 < F_21 ( V_27 -> V_37 -> V_29 . V_69 ) ?
V_67 : F_21 ( V_27 -> V_37 -> V_29 . V_69 ) ) : V_67 ;
V_65 = F_22 ( V_61 ) ;
V_57 = & ( V_27 -> V_37 -> V_39 [ 0 ] ) ;
V_58 = & ( V_27 -> V_37 -> V_38 [ 0 ] ) ;
if ( ( V_43 == V_97 ) ||
( V_43 == V_98 ) )
{
V_54 = & ( V_31 [ 0 ] ) ; V_9 = V_24 + V_24 ;
V_55 = & ( V_31 [ V_9 ] ) ; V_9 += V_10 + V_10 ;
V_56 = & ( V_31 [ V_9 ] ) ; V_9 += V_65 + V_65 ;
V_47 = ( unsigned char * ) V_99 ;
V_66 = V_100 ;
V_59 = 1 ;
}
else
{
V_9 = V_24 ;
V_54 = & ( V_31 [ V_9 ] ) ; V_9 += V_24 + V_10 ;
V_55 = & ( V_31 [ V_9 ] ) ; V_9 += V_10 + V_65 ;
V_56 = & ( V_31 [ V_9 ] ) ; V_9 += V_65 ;
V_47 = ( unsigned char * ) V_101 ;
V_66 = V_102 ;
V_59 = 0 ;
}
if ( V_9 > V_27 -> V_37 -> V_29 . V_78 )
{
F_17 ( V_85 , V_103 ) ;
goto V_87;
}
memcpy ( V_46 , V_54 , V_24 ) ;
#ifdef F_23
printf ( L_11 , V_43 ) ;
{ int V_104 ; for ( V_104 = 0 ; V_104 < V_24 ; V_104 ++ ) printf ( L_12 , V_54 [ V_104 ] , ( ( V_104 + 1 ) % 16 ) ? ' ' : '\n' ) ; }
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
F_9 ( V_27 -> V_11 -> V_16 , V_27 -> V_11 -> V_17 , V_32 , ( int ) ( V_31 - V_32 ) , V_55 , V_10 ,
V_48 , V_50 , F_20 ( V_61 ) ) ;
V_55 = V_48 ;
if ( V_65 > 0 )
{
V_31 = V_32 ;
memcpy ( V_31 , V_105 ,
V_106 ) ;
V_31 += V_106 ;
memcpy ( V_31 , V_27 -> V_37 -> V_39 , V_33 ) ;
V_31 += V_33 ;
memcpy ( V_31 , V_27 -> V_37 -> V_38 , V_33 ) ;
V_31 += V_33 ;
F_9 ( V_27 -> V_11 -> V_16 , V_27 -> V_11 -> V_17 , V_32 , V_31 - V_32 , V_44 , 0 ,
V_51 , V_53 , V_65 * 2 ) ;
if ( V_59 )
V_56 = V_51 ;
else
V_56 = & ( V_51 [ V_65 ] ) ;
}
}
V_27 -> V_40 -> V_107 = 0 ;
#ifdef F_11
{
int V_24 ;
printf ( L_13 ) ;
printf ( L_14 ) ; for ( V_24 = 0 ; V_24 < V_61 -> V_76 ; V_24 ++ ) printf ( L_10 , V_55 [ V_24 ] ) ;
printf ( L_3 ) ;
printf ( L_15 ) ; for ( V_24 = 0 ; V_24 < V_61 -> V_77 ; V_24 ++ ) printf ( L_10 , V_56 [ V_24 ] ) ;
printf ( L_3 ) ;
}
#endif
F_24 ( V_60 , V_61 , NULL , V_55 , V_56 , ( V_43 & V_108 ) ) ;
#ifdef F_23
printf ( L_16 , V_43 ) ;
{ int V_104 ; for ( V_104 = 0 ; V_104 < F_20 ( V_61 ) ; V_104 ++ ) printf ( L_12 , V_55 [ V_104 ] , ( ( V_104 + 1 ) % 16 ) ? ' ' : '\n' ) ; }
printf ( L_17 ) ;
{ int V_104 ; for ( V_104 = 0 ; V_104 < V_65 ; V_104 ++ ) printf ( L_12 , V_56 [ V_104 ] , ( ( V_104 + 1 ) % 16 ) ? ' ' : '\n' ) ; }
printf ( L_3 ) ;
#endif
F_8 ( V_48 , sizeof( V_48 ) ) ;
F_8 ( V_50 , sizeof( V_48 ) ) ;
F_8 ( V_51 , sizeof( V_51 ) ) ;
F_8 ( V_53 , sizeof( V_53 ) ) ;
return ( 1 ) ;
V_81:
F_17 ( V_85 , V_109 ) ;
V_87:
return ( 0 ) ;
}
int F_25 ( T_3 * V_27 )
{
unsigned char * V_110 , * V_111 ;
const T_5 * V_61 ;
const T_1 * V_112 ;
int V_30 ;
T_6 * V_62 ;
#ifdef F_11
printf ( L_18 ) ;
#endif
if ( V_27 -> V_37 -> V_29 . V_78 != 0 )
return ( 1 ) ;
if ( ! F_26 ( V_27 -> V_40 , & V_61 , & V_112 , & V_62 ) )
{
F_17 ( V_113 , V_114 ) ;
return ( 0 ) ;
}
V_27 -> V_37 -> V_29 . V_70 = V_61 ;
V_27 -> V_37 -> V_29 . V_71 = V_112 ;
V_30 = F_20 ( V_61 ) + F_2 ( V_112 ) + F_22 ( V_61 ) ;
V_30 *= 2 ;
F_27 ( V_27 ) ;
if ( ( V_110 = ( unsigned char * ) F_14 ( V_30 ) ) == NULL )
goto V_81;
if ( ( V_111 = ( unsigned char * ) F_14 ( V_30 ) ) == NULL )
goto V_81;
V_27 -> V_37 -> V_29 . V_78 = V_30 ;
V_27 -> V_37 -> V_29 . V_45 = V_110 ;
#ifdef F_23
printf ( L_19 ) ;
{ int V_104 ; for ( V_104 = 0 ; V_104 < V_33 ; V_104 ++ ) printf ( L_12 , V_27 -> V_37 -> V_39 [ V_104 ] , ( ( V_104 + 1 ) % 16 ) ? ' ' : '\n' ) ; }
printf ( L_20 ) ;
{ int V_104 ; for ( V_104 = 0 ; V_104 < V_33 ; V_104 ++ ) printf ( L_12 , V_27 -> V_37 -> V_38 [ V_104 ] , ( ( V_104 + 1 ) % 16 ) ? ' ' : '\n' ) ; }
printf ( L_21 ) ;
{ int V_104 ; for ( V_104 = 0 ; V_104 < V_27 -> V_40 -> V_42 ; V_104 ++ ) printf ( L_12 , V_27 -> V_40 -> V_41 [ V_104 ] , ( ( V_104 + 1 ) % 16 ) ? ' ' : '\n' ) ; }
#endif
F_10 ( V_27 , V_110 , V_111 , V_30 ) ;
F_8 ( V_111 , V_30 ) ;
F_28 ( V_111 ) ;
#ifdef F_23
printf ( L_22 ) ;
{ int V_104 ; for ( V_104 = 0 ; V_104 < V_30 ; V_104 ++ ) printf ( L_12 , V_110 [ V_104 ] , ( ( V_104 + 1 ) % 16 ) ? ' ' : '\n' ) ; }
#endif
if ( ! ( V_27 -> V_115 & V_116 ) )
{
V_27 -> V_37 -> V_117 = 1 ;
if ( V_27 -> V_40 -> V_118 != NULL )
{
if ( ( V_27 -> V_40 -> V_118 -> V_73 & V_119 ) == V_120 )
V_27 -> V_37 -> V_117 = 0 ;
#ifndef F_29
if ( ( V_27 -> V_40 -> V_118 -> V_73 & V_119 ) == V_121 )
V_27 -> V_37 -> V_117 = 0 ;
#endif
}
}
return ( 1 ) ;
V_81:
F_17 ( V_113 , V_109 ) ;
return ( 0 ) ;
}
int F_30 ( T_3 * V_27 , int V_122 )
{
T_7 * V_123 ;
T_4 * V_124 ;
unsigned long V_125 ;
int V_126 , V_24 , V_127 , V_10 , V_65 , V_9 = 0 ;
const T_5 * V_128 ;
if ( V_122 )
{
if ( V_27 -> V_93 != NULL )
V_9 = F_2 ( V_27 -> V_93 ) ;
V_124 = V_27 -> V_92 ;
V_123 = & ( V_27 -> V_37 -> V_129 ) ;
if ( V_27 -> V_92 == NULL )
V_128 = NULL ;
else
V_128 = F_31 ( V_27 -> V_92 ) ;
}
else
{
if ( V_27 -> V_82 != NULL )
V_9 = F_2 ( V_27 -> V_82 ) ;
V_124 = V_27 -> V_80 ;
V_123 = & ( V_27 -> V_37 -> V_88 ) ;
if ( V_27 -> V_80 == NULL )
V_128 = NULL ;
else
V_128 = F_31 ( V_27 -> V_80 ) ;
}
#ifdef F_11
printf ( L_23 , V_122 ) ;
#endif
if ( ( V_27 -> V_40 == NULL ) || ( V_124 == NULL ) ||
( V_128 == NULL ) )
{
memmove ( V_123 -> V_130 , V_123 -> V_131 , V_123 -> V_132 ) ;
V_123 -> V_131 = V_123 -> V_130 ;
}
else
{
V_125 = V_123 -> V_132 ;
V_126 = F_32 ( V_124 -> V_118 ) ;
if ( ( V_126 != 1 ) && V_122 )
{
V_24 = V_126 - ( ( int ) V_125 % V_126 ) ;
V_10 = V_24 - 1 ;
if ( V_27 -> V_115 & V_133 )
{
if ( V_27 -> V_37 -> V_134 & V_135 )
V_10 ++ ;
}
for ( V_65 = ( int ) V_125 ; V_65 < ( int ) ( V_125 + V_24 ) ; V_65 ++ )
V_123 -> V_131 [ V_65 ] = V_10 ;
V_125 += V_24 ;
V_123 -> V_132 += V_24 ;
}
#ifdef F_11
{
unsigned long V_136 ;
printf ( L_24 ,
V_124 , V_123 -> V_130 , V_123 -> V_131 , V_125 ) ;
printf ( L_25 ,
V_124 -> V_137 , V_124 -> V_118 -> V_76 ,
V_138 , V_139 ,
V_124 -> V_118 -> V_77 ) ;
printf ( L_26 ) ;
for ( V_24 = 0 ; V_24 < V_124 -> V_118 -> V_77 ; V_24 ++ ) printf ( L_2 , V_124 -> V_56 [ V_24 ] ) ;
printf ( L_3 ) ;
printf ( L_27 ) ;
for ( V_136 = 0 ; V_136 < V_125 ; V_136 ++ ) printf ( L_28 , V_123 -> V_131 [ V_136 ] ) ;
printf ( L_3 ) ;
}
#endif
if ( ! V_122 )
{
if ( V_125 == 0 || V_125 % V_126 != 0 )
{
F_17 ( V_140 , V_141 ) ;
F_33 ( V_27 , V_142 , V_143 ) ;
return 0 ;
}
}
F_34 ( V_124 , V_123 -> V_130 , V_123 -> V_131 , V_125 ) ;
#ifdef F_11
{
unsigned long V_24 ;
printf ( L_29 ) ;
for ( V_24 = 0 ; V_24 < V_125 ; V_24 ++ )
printf ( L_28 , V_123 -> V_130 [ V_24 ] ) ; printf ( L_3 ) ;
}
#endif
if ( ( V_126 != 1 ) && ! V_122 )
{
V_127 = V_24 = V_123 -> V_130 [ V_125 - 1 ] ;
V_24 ++ ;
if ( V_27 -> V_115 & V_133 )
{
if ( ( memcmp ( V_27 -> V_37 -> V_90 ,
L_30 , 8 ) == 0 ) && ! ( V_127 & 1 ) )
V_27 -> V_37 -> V_134 |= V_135 ;
if ( V_27 -> V_37 -> V_134 & V_135 )
V_24 -- ;
}
if ( V_24 > ( int ) V_123 -> V_132 )
{
return - 1 ;
}
for ( V_10 = ( int ) ( V_125 - V_24 ) ; V_10 < ( int ) V_125 ; V_10 ++ )
{
if ( V_123 -> V_130 [ V_10 ] != V_127 )
{
return - 1 ;
}
}
V_123 -> V_132 -= V_24 ;
}
}
return ( 1 ) ;
}
int F_35 ( T_3 * V_27 , T_8 * V_144 , unsigned char * V_6 )
{
unsigned int V_145 ;
T_8 V_11 ;
F_36 ( & V_11 ) ;
F_37 ( & V_11 , V_144 ) ;
F_38 ( & V_11 , V_6 , & V_145 ) ;
F_39 ( & V_11 ) ;
return ( ( int ) V_145 ) ;
}
int F_40 ( T_3 * V_27 , T_8 * V_146 , T_8 * V_147 ,
const char * V_148 , int V_20 , unsigned char * V_6 )
{
unsigned int V_24 ;
T_8 V_11 ;
unsigned char V_32 [ V_34 + V_149 + V_150 ] ;
unsigned char * V_151 , V_152 [ 12 ] ;
V_151 = V_32 ;
memcpy ( V_151 , V_148 , V_20 ) ;
V_151 += V_20 ;
F_36 ( & V_11 ) ;
F_37 ( & V_11 , V_146 ) ;
F_38 ( & V_11 , V_151 , & V_24 ) ;
V_151 += V_24 ;
F_37 ( & V_11 , V_147 ) ;
F_38 ( & V_11 , V_151 , & V_24 ) ;
V_151 += V_24 ;
F_9 ( V_27 -> V_11 -> V_16 , V_27 -> V_11 -> V_17 , V_32 , ( int ) ( V_151 - V_32 ) ,
V_27 -> V_40 -> V_41 , V_27 -> V_40 -> V_42 ,
V_6 , V_152 , sizeof V_152 ) ;
F_39 ( & V_11 ) ;
return sizeof V_152 ;
}
int F_41 ( T_3 * V_153 , unsigned char * V_1 , int V_122 )
{
T_7 * V_123 ;
unsigned char * V_154 , * V_155 ;
const T_1 * V_112 ;
unsigned int V_156 ;
int V_24 ;
T_2 V_157 ;
unsigned char V_32 [ 5 ] ;
if ( V_122 )
{
V_123 = & ( V_153 -> V_37 -> V_129 ) ;
V_154 = & ( V_153 -> V_37 -> V_96 [ 0 ] ) ;
V_155 = & ( V_153 -> V_37 -> V_95 [ 0 ] ) ;
V_112 = V_153 -> V_93 ;
}
else
{
V_123 = & ( V_153 -> V_37 -> V_88 ) ;
V_154 = & ( V_153 -> V_37 -> V_91 [ 0 ] ) ;
V_155 = & ( V_153 -> V_37 -> V_90 [ 0 ] ) ;
V_112 = V_153 -> V_82 ;
}
V_156 = F_2 ( V_112 ) ;
V_32 [ 0 ] = V_123 -> type ;
V_32 [ 1 ] = V_158 ;
V_32 [ 2 ] = V_159 ;
V_32 [ 3 ] = V_123 -> V_132 >> 8 ;
V_32 [ 4 ] = V_123 -> V_132 & 0xff ;
F_3 ( & V_157 ) ;
F_4 ( & V_157 , V_154 , F_2 ( V_112 ) , V_112 , NULL ) ;
F_5 ( & V_157 , V_155 , 8 ) ;
F_5 ( & V_157 , V_32 , 5 ) ;
F_5 ( & V_157 , V_123 -> V_131 , V_123 -> V_132 ) ;
F_6 ( & V_157 , V_1 , & V_156 ) ;
F_7 ( & V_157 ) ;
#ifdef F_23
printf ( L_31 ) ;
{ unsigned int V_104 ; for ( V_104 = 0 ; V_104 < V_156 ; V_104 ++ ) printf ( L_32 , V_154 [ V_104 ] ) ; printf ( L_3 ) ; }
printf ( L_33 ) ;
{ int V_104 ; for ( V_104 = 0 ; V_104 < 8 ; V_104 ++ ) printf ( L_32 , V_155 [ V_104 ] ) ; printf ( L_3 ) ; }
printf ( L_34 ) ;
{ int V_104 ; for ( V_104 = 0 ; V_104 < 5 ; V_104 ++ ) printf ( L_32 , V_32 [ V_104 ] ) ; printf ( L_3 ) ; }
printf ( L_35 ) ;
{ unsigned int V_104 ; for ( V_104 = 0 ; V_104 < V_123 -> V_132 ; V_104 ++ ) printf ( L_32 , V_32 [ V_104 ] ) ; printf ( L_3 ) ; }
#endif
for ( V_24 = 7 ; V_24 >= 0 ; V_24 -- )
{
++ V_155 [ V_24 ] ;
if ( V_155 [ V_24 ] != 0 ) break;
}
#ifdef F_23
{ unsigned int V_104 ; for ( V_104 = 0 ; V_104 < V_156 ; V_104 ++ ) printf ( L_32 , V_1 [ V_104 ] ) ; printf ( L_3 ) ; }
#endif
return ( V_156 ) ;
}
int F_42 ( T_3 * V_27 , unsigned char * V_6 , unsigned char * V_31 ,
int V_23 )
{
unsigned char V_32 [ V_33 * 2 + V_160 ] ;
unsigned char V_161 [ V_162 ] ;
#ifdef F_11
printf ( L_36 , V_27 , V_6 , V_31 , V_23 ) ;
#endif
memcpy ( V_32 , V_163 ,
V_160 ) ;
memcpy ( & ( V_32 [ V_160 ] ) ,
V_27 -> V_37 -> V_39 , V_33 ) ;
memcpy ( & ( V_32 [ V_33 + V_160 ] ) ,
V_27 -> V_37 -> V_38 , V_33 ) ;
F_9 ( V_27 -> V_11 -> V_16 , V_27 -> V_11 -> V_17 ,
V_32 , V_160 + V_33 * 2 , V_31 , V_23 ,
V_27 -> V_40 -> V_41 , V_161 , sizeof V_161 ) ;
#ifdef F_11
printf ( L_37 ) ;
#endif
return ( V_164 ) ;
}
int F_43 ( int V_165 )
{
switch ( V_165 )
{
case V_166 : return ( V_167 ) ;
case V_168 : return ( V_169 ) ;
case V_170 : return ( V_171 ) ;
case V_143 : return ( V_172 ) ;
case V_173 : return ( V_174 ) ;
case V_175 : return ( V_176 ) ;
case V_177 : return ( V_178 ) ;
case V_179 : return ( - 1 ) ;
case V_180 : return ( V_181 ) ;
case V_182 : return ( V_183 ) ;
case V_184 : return ( V_185 ) ;
case V_186 : return ( V_187 ) ;
case V_188 : return ( V_189 ) ;
case V_190 : return ( V_191 ) ;
case V_192 : return ( V_193 ) ;
case V_194 : return ( V_195 ) ;
case V_196 : return ( V_197 ) ;
case V_198 : return ( V_199 ) ;
case V_200 : return ( V_201 ) ;
case V_202 : return ( V_203 ) ;
case V_204 : return ( V_205 ) ;
case V_206 : return ( V_207 ) ;
case V_208 : return ( V_209 ) ;
case V_210 : return ( V_211 ) ;
default: return ( - 1 ) ;
}
}

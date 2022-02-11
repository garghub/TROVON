static int F_1 ( T_1 * V_1 , unsigned char * V_2 , int V_3 )
{
T_2 V_4 ;
T_2 V_5 ;
unsigned char V_6 [ 16 ] , V_7 [ V_8 ] ;
unsigned char V_9 = 'A' ;
unsigned int V_10 , V_11 , V_12 ;
#ifdef F_2
V_9 = V_13 [ V_9 ] ;
#endif
V_12 = 0 ;
F_3 ( & V_4 ) ;
F_3 ( & V_5 ) ;
for ( V_10 = 0 ; ( int ) V_10 < V_3 ; V_10 += V_14 )
{
V_12 ++ ;
if ( V_12 > sizeof V_6 )
{
F_4 ( V_15 , V_16 ) ;
return 0 ;
}
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ )
V_6 [ V_11 ] = V_9 ;
V_9 ++ ;
F_5 ( & V_5 , F_6 () , NULL ) ;
F_7 ( & V_5 , V_6 , V_12 ) ;
F_7 ( & V_5 , V_1 -> V_17 -> V_18 ,
V_1 -> V_17 -> V_19 ) ;
F_7 ( & V_5 , V_1 -> V_20 -> V_21 , V_22 ) ;
F_7 ( & V_5 , V_1 -> V_20 -> V_23 , V_22 ) ;
F_8 ( & V_5 , V_7 , NULL ) ;
F_5 ( & V_4 , F_9 () , NULL ) ;
F_7 ( & V_4 , V_1 -> V_17 -> V_18 ,
V_1 -> V_17 -> V_19 ) ;
F_7 ( & V_4 , V_7 , V_8 ) ;
if ( ( int ) ( V_10 + V_14 ) > V_3 )
{
F_8 ( & V_4 , V_7 , NULL ) ;
memcpy ( V_2 , V_7 , ( V_3 - V_10 ) ) ;
}
else
F_8 ( & V_4 , V_2 , NULL ) ;
V_2 += V_14 ;
}
F_10 ( V_7 , V_8 ) ;
F_11 ( & V_4 ) ;
F_11 ( & V_5 ) ;
return 1 ;
}
int F_12 ( T_1 * V_1 , int V_24 )
{
unsigned char * V_25 , * V_26 , * V_27 ;
unsigned char V_28 [ V_29 ] ;
unsigned char V_30 [ V_31 ] ;
unsigned char * V_32 , * V_33 , * V_34 , * V_35 , * V_36 ;
T_3 * V_37 ;
const T_4 * V_9 ;
T_5 * V_38 ;
const T_6 * V_39 ;
T_2 V_40 ;
int V_41 , V_42 , V_10 , V_11 , V_12 , V_43 ;
int V_44 = 0 ;
V_41 = F_13 ( V_1 -> V_20 -> V_45 . V_46 ) ;
V_9 = V_1 -> V_20 -> V_45 . V_47 ;
V_39 = V_1 -> V_20 -> V_45 . V_48 ;
if ( V_1 -> V_20 -> V_45 . V_49 == NULL )
V_38 = NULL ;
else
V_38 = V_1 -> V_20 -> V_45 . V_49 -> V_50 ;
V_26 = V_1 -> V_20 -> V_45 . V_26 ;
if ( V_24 & V_51 )
{
if ( V_1 -> V_52 != NULL )
V_44 = 1 ;
else if ( ( V_1 -> V_52 = F_14 ( sizeof( T_3 ) ) ) == NULL )
goto V_53;
V_37 = V_1 -> V_52 ;
V_1 -> V_54 = V_39 ;
if ( V_1 -> V_55 != NULL )
{
F_15 ( V_1 -> V_55 ) ;
V_1 -> V_55 = NULL ;
}
if ( V_38 != NULL )
{
V_1 -> V_55 = F_16 ( V_38 ) ;
if ( V_1 -> V_55 == NULL )
{
F_4 ( V_56 , V_57 ) ;
goto V_58;
}
if ( V_1 -> V_20 -> V_59 . V_38 == NULL )
V_1 -> V_20 -> V_59 . V_38 = ( unsigned char * )
F_14 ( V_60 ) ;
if ( V_1 -> V_20 -> V_59 . V_38 == NULL )
goto V_53;
}
memset ( & ( V_1 -> V_20 -> V_61 [ 0 ] ) , 0 , 8 ) ;
V_27 = & ( V_1 -> V_20 -> V_62 [ 0 ] ) ;
}
else
{
if ( V_1 -> V_63 != NULL )
V_44 = 1 ;
else if ( ( V_1 -> V_63 = F_14 ( sizeof( T_3 ) ) ) == NULL )
goto V_53;
V_37 = V_1 -> V_63 ;
V_1 -> V_64 = V_39 ;
if ( V_1 -> V_65 != NULL )
{
F_15 ( V_1 -> V_65 ) ;
V_1 -> V_65 = NULL ;
}
if ( V_38 != NULL )
{
V_1 -> V_65 = F_16 ( V_38 ) ;
if ( V_1 -> V_65 == NULL )
{
F_4 ( V_56 , V_57 ) ;
goto V_58;
}
}
memset ( & ( V_1 -> V_20 -> V_66 [ 0 ] ) , 0 , 8 ) ;
V_27 = & ( V_1 -> V_20 -> V_67 [ 0 ] ) ;
}
if ( V_44 )
F_17 ( V_37 ) ;
F_18 ( V_37 ) ;
V_25 = V_1 -> V_20 -> V_45 . V_26 ;
V_10 = F_19 ( V_39 ) ;
V_43 = F_20 ( V_9 ) ;
V_11 = V_41 ? ( V_43 < F_21 ( V_1 -> V_20 -> V_45 . V_46 ) ?
V_43 : F_21 ( V_1 -> V_20 -> V_45 . V_46 ) ) : V_43 ;
V_12 = F_22 ( V_9 ) ;
if ( ( V_24 == V_68 ) ||
( V_24 == V_69 ) )
{
V_32 = & ( V_25 [ 0 ] ) ; V_42 = V_10 + V_10 ;
V_33 = & ( V_25 [ V_42 ] ) ; V_42 += V_11 + V_11 ;
V_34 = & ( V_25 [ V_42 ] ) ; V_42 += V_12 + V_12 ;
V_35 = & ( V_1 -> V_20 -> V_23 [ 0 ] ) ;
V_36 = & ( V_1 -> V_20 -> V_21 [ 0 ] ) ;
}
else
{
V_42 = V_10 ;
V_32 = & ( V_25 [ V_42 ] ) ; V_42 += V_10 + V_11 ;
V_33 = & ( V_25 [ V_42 ] ) ; V_42 += V_11 + V_12 ;
V_34 = & ( V_25 [ V_42 ] ) ; V_42 += V_12 ;
V_35 = & ( V_1 -> V_20 -> V_21 [ 0 ] ) ;
V_36 = & ( V_1 -> V_20 -> V_23 [ 0 ] ) ;
}
if ( V_42 > V_1 -> V_20 -> V_45 . V_70 )
{
F_4 ( V_56 , V_16 ) ;
goto V_58;
}
F_3 ( & V_40 ) ;
memcpy ( V_27 , V_32 , V_10 ) ;
if ( V_41 )
{
F_5 ( & V_40 , F_9 () , NULL ) ;
F_7 ( & V_40 , V_33 , V_11 ) ;
F_7 ( & V_40 , V_35 , V_22 ) ;
F_7 ( & V_40 , V_36 , V_22 ) ;
F_8 ( & V_40 , & ( V_28 [ 0 ] ) , NULL ) ;
V_33 = & ( V_28 [ 0 ] ) ;
if ( V_12 > 0 )
{
F_5 ( & V_40 , F_9 () , NULL ) ;
F_7 ( & V_40 , V_35 , V_22 ) ;
F_7 ( & V_40 , V_36 , V_22 ) ;
F_8 ( & V_40 , & ( V_30 [ 0 ] ) , NULL ) ;
V_34 = & ( V_30 [ 0 ] ) ;
}
}
V_1 -> V_17 -> V_71 = 0 ;
F_23 ( V_37 , V_9 , NULL , V_33 , V_34 , ( V_24 & V_72 ) ) ;
F_10 ( & ( V_28 [ 0 ] ) , sizeof( V_28 ) ) ;
F_10 ( & ( V_30 [ 0 ] ) , sizeof( V_30 ) ) ;
F_11 ( & V_40 ) ;
return ( 1 ) ;
V_53:
F_4 ( V_56 , V_73 ) ;
V_58:
return ( 0 ) ;
}
int F_24 ( T_1 * V_1 )
{
unsigned char * V_25 ;
const T_4 * V_9 ;
const T_6 * V_74 ;
int V_3 ;
int V_75 = 0 ;
T_7 * V_38 ;
if ( V_1 -> V_20 -> V_45 . V_70 != 0 )
return ( 1 ) ;
if ( ! F_25 ( V_1 -> V_17 , & V_9 , & V_74 , & V_38 ) )
{
F_4 ( V_76 , V_77 ) ;
return ( 0 ) ;
}
V_1 -> V_20 -> V_45 . V_47 = V_9 ;
V_1 -> V_20 -> V_45 . V_48 = V_74 ;
V_1 -> V_20 -> V_45 . V_49 = V_38 ;
V_3 = F_20 ( V_9 ) + F_19 ( V_74 ) + F_22 ( V_9 ) ;
V_3 *= 2 ;
F_26 ( V_1 ) ;
if ( ( V_25 = F_14 ( V_3 ) ) == NULL )
goto V_53;
V_1 -> V_20 -> V_45 . V_70 = V_3 ;
V_1 -> V_20 -> V_45 . V_26 = V_25 ;
V_75 = F_1 ( V_1 , V_25 , V_3 ) ;
if ( ! ( V_1 -> V_78 & V_79 ) )
{
V_1 -> V_20 -> V_80 = 1 ;
if ( V_1 -> V_17 -> V_81 != NULL )
{
if ( ( V_1 -> V_17 -> V_81 -> V_82 & V_83 ) == V_84 )
V_1 -> V_20 -> V_80 = 0 ;
#ifndef F_27
if ( ( V_1 -> V_17 -> V_81 -> V_82 & V_83 ) == V_85 )
V_1 -> V_20 -> V_80 = 0 ;
#endif
}
}
return V_75 ;
V_53:
F_4 ( V_76 , V_73 ) ;
return ( 0 ) ;
}
void F_26 ( T_1 * V_1 )
{
if ( V_1 -> V_20 -> V_45 . V_26 != NULL )
{
F_10 ( V_1 -> V_20 -> V_45 . V_26 ,
V_1 -> V_20 -> V_45 . V_70 ) ;
F_28 ( V_1 -> V_20 -> V_45 . V_26 ) ;
V_1 -> V_20 -> V_45 . V_26 = NULL ;
}
V_1 -> V_20 -> V_45 . V_70 = 0 ;
}
int F_29 ( T_1 * V_1 , int V_86 )
{
T_8 * V_87 ;
T_3 * V_88 ;
unsigned long V_89 ;
int V_90 , V_10 ;
const T_4 * V_91 ;
if ( V_86 )
{
V_88 = V_1 -> V_63 ;
V_87 = & ( V_1 -> V_20 -> V_92 ) ;
if ( V_1 -> V_63 == NULL )
V_91 = NULL ;
else
V_91 = F_30 ( V_1 -> V_63 ) ;
}
else
{
V_88 = V_1 -> V_52 ;
V_87 = & ( V_1 -> V_20 -> V_59 ) ;
if ( V_1 -> V_52 == NULL )
V_91 = NULL ;
else
V_91 = F_30 ( V_1 -> V_52 ) ;
}
if ( ( V_1 -> V_17 == NULL ) || ( V_88 == NULL ) ||
( V_91 == NULL ) )
{
memmove ( V_87 -> V_93 , V_87 -> V_94 , V_87 -> V_95 ) ;
V_87 -> V_94 = V_87 -> V_93 ;
}
else
{
V_89 = V_87 -> V_95 ;
V_90 = F_31 ( V_88 -> V_81 ) ;
if ( ( V_90 != 1 ) && V_86 )
{
V_10 = V_90 - ( ( int ) V_89 % V_90 ) ;
V_89 += V_10 ;
V_87 -> V_95 += V_10 ;
V_87 -> V_94 [ V_89 - 1 ] = ( V_10 - 1 ) ;
}
if ( ! V_86 )
{
if ( V_89 == 0 || V_89 % V_90 != 0 )
{
F_4 ( V_96 , V_97 ) ;
F_32 ( V_1 , V_98 , V_99 ) ;
return 0 ;
}
}
F_33 ( V_88 , V_87 -> V_93 , V_87 -> V_94 , V_89 ) ;
if ( ( V_90 != 1 ) && ! V_86 )
{
V_10 = V_87 -> V_93 [ V_89 - 1 ] + 1 ;
if ( V_10 > V_90 )
{
return - 1 ;
}
V_87 -> V_95 -= V_10 ;
}
}
return ( 1 ) ;
}
void F_34 ( T_1 * V_1 )
{
F_5 ( & ( V_1 -> V_20 -> V_100 ) , V_1 -> V_101 -> V_102 , NULL ) ;
F_5 ( & ( V_1 -> V_20 -> V_103 ) , V_1 -> V_101 -> V_104 , NULL ) ;
}
void F_35 ( T_1 * V_1 , const unsigned char * V_6 , int V_105 )
{
F_7 ( & ( V_1 -> V_20 -> V_100 ) , V_6 , V_105 ) ;
F_7 ( & ( V_1 -> V_20 -> V_103 ) , V_6 , V_105 ) ;
}
int F_36 ( T_1 * V_1 , T_2 * V_101 , unsigned char * V_25 )
{
return ( F_37 ( V_1 , V_101 , NULL , 0 , V_25 ) ) ;
}
int F_38 ( T_1 * V_1 , T_2 * V_106 , T_2 * V_107 ,
const char * V_108 , int V_105 , unsigned char * V_25 )
{
int V_75 ;
V_75 = F_37 ( V_1 , V_106 , V_108 , V_105 , V_25 ) ;
V_25 += V_75 ;
V_75 += F_37 ( V_1 , V_107 , V_108 , V_105 , V_25 ) ;
return ( V_75 ) ;
}
static int F_37 ( T_1 * V_1 , T_2 * V_109 ,
const char * V_108 , int V_105 , unsigned char * V_25 )
{
unsigned int V_75 ;
int V_110 , V_42 ;
unsigned int V_10 ;
unsigned char V_111 [ V_112 ] ;
T_2 V_101 ;
F_3 ( & V_101 ) ;
F_39 ( & V_101 , V_109 ) ;
V_42 = F_40 ( & V_101 ) ;
V_110 = ( 48 / V_42 ) * V_42 ;
if ( V_108 != NULL )
F_7 ( & V_101 , V_108 , V_105 ) ;
F_7 ( & V_101 , V_1 -> V_17 -> V_18 ,
V_1 -> V_17 -> V_19 ) ;
F_7 ( & V_101 , V_113 , V_110 ) ;
F_8 ( & V_101 , V_111 , & V_10 ) ;
F_5 ( & V_101 , F_41 ( & V_101 ) , NULL ) ;
F_7 ( & V_101 , V_1 -> V_17 -> V_18 ,
V_1 -> V_17 -> V_19 ) ;
F_7 ( & V_101 , V_114 , V_110 ) ;
F_7 ( & V_101 , V_111 , V_10 ) ;
F_8 ( & V_101 , V_25 , & V_75 ) ;
F_11 ( & V_101 ) ;
return ( ( int ) V_75 ) ;
}
int F_42 ( T_1 * V_115 , unsigned char * V_40 , int V_86 )
{
T_8 * V_87 ;
unsigned char * V_116 , * V_117 ;
T_2 V_118 ;
const T_6 * V_74 ;
unsigned char * V_25 , V_119 ;
unsigned int V_120 ;
int V_110 ;
if ( V_86 )
{
V_87 = & ( V_115 -> V_20 -> V_92 ) ;
V_116 = & ( V_115 -> V_20 -> V_67 [ 0 ] ) ;
V_117 = & ( V_115 -> V_20 -> V_66 [ 0 ] ) ;
V_74 = V_115 -> V_64 ;
}
else
{
V_87 = & ( V_115 -> V_20 -> V_59 ) ;
V_116 = & ( V_115 -> V_20 -> V_62 [ 0 ] ) ;
V_117 = & ( V_115 -> V_20 -> V_61 [ 0 ] ) ;
V_74 = V_115 -> V_54 ;
}
V_120 = F_19 ( V_74 ) ;
V_110 = ( 48 / V_120 ) * V_120 ;
F_3 ( & V_118 ) ;
F_5 ( & V_118 , V_74 , NULL ) ;
F_7 ( & V_118 , V_116 , V_120 ) ;
F_7 ( & V_118 , V_113 , V_110 ) ;
F_7 ( & V_118 , V_117 , 8 ) ;
V_119 = V_87 -> type ;
F_7 ( & V_118 , & V_119 , 1 ) ;
V_25 = V_40 ;
F_43 ( V_87 -> V_95 , V_25 ) ;
F_7 ( & V_118 , V_40 , 2 ) ;
F_7 ( & V_118 , V_87 -> V_94 , V_87 -> V_95 ) ;
F_8 ( & V_118 , V_40 , NULL ) ;
F_5 ( & V_118 , V_74 , NULL ) ;
F_7 ( & V_118 , V_116 , V_120 ) ;
F_7 ( & V_118 , V_114 , V_110 ) ;
F_7 ( & V_118 , V_40 , V_120 ) ;
F_8 ( & V_118 , V_40 , & V_120 ) ;
F_11 ( & V_118 ) ;
F_44 ( V_117 ) ;
return ( V_120 ) ;
}
void F_44 ( unsigned char * V_117 )
{
int V_10 ;
for ( V_10 = 7 ; V_10 >= 0 ; V_10 -- )
{
++ V_117 [ V_10 ] ;
if ( V_117 [ V_10 ] != 0 ) break;
}
}
int F_45 ( T_1 * V_1 , unsigned char * V_121 , unsigned char * V_25 ,
int V_105 )
{
static const unsigned char * V_122 [ 3 ] = {
#ifndef F_2
( const unsigned char * ) L_1 ,
( const unsigned char * ) L_2 ,
( const unsigned char * ) L_3 ,
#else
( const unsigned char * ) L_4 ,
( const unsigned char * ) L_5 ,
( const unsigned char * ) L_6 ,
#endif
} ;
unsigned char V_6 [ V_112 ] ;
T_2 V_101 ;
int V_10 , V_75 = 0 ;
unsigned int V_42 ;
F_3 ( & V_101 ) ;
for ( V_10 = 0 ; V_10 < 3 ; V_10 ++ )
{
F_5 ( & V_101 , V_1 -> V_101 -> V_104 , NULL ) ;
F_7 ( & V_101 , V_122 [ V_10 ] , strlen ( ( const char * ) V_122 [ V_10 ] ) ) ;
F_7 ( & V_101 , V_25 , V_105 ) ;
F_7 ( & V_101 , & ( V_1 -> V_20 -> V_23 [ 0 ] ) ,
V_22 ) ;
F_7 ( & V_101 , & ( V_1 -> V_20 -> V_21 [ 0 ] ) ,
V_22 ) ;
F_8 ( & V_101 , V_6 , & V_42 ) ;
F_5 ( & V_101 , V_1 -> V_101 -> V_102 , NULL ) ;
F_7 ( & V_101 , V_25 , V_105 ) ;
F_7 ( & V_101 , V_6 , V_42 ) ;
F_8 ( & V_101 , V_121 , & V_42 ) ;
V_121 += V_42 ;
V_75 += V_42 ;
}
F_11 ( & V_101 ) ;
return ( V_75 ) ;
}
int F_46 ( int V_123 )
{
switch ( V_123 )
{
case V_124 : return ( V_125 ) ;
case V_126 : return ( V_127 ) ;
case V_128 : return ( V_129 ) ;
case V_99 : return ( V_129 ) ;
case V_130 : return ( V_129 ) ;
case V_131 : return ( V_132 ) ;
case V_133 : return ( V_134 ) ;
case V_135 : return ( V_136 ) ;
case V_137 : return ( V_138 ) ;
case V_139 : return ( V_140 ) ;
case V_141 : return ( V_142 ) ;
case V_143 : return ( V_144 ) ;
case V_145 : return ( V_146 ) ;
case V_147 : return ( V_148 ) ;
case V_149 : return ( V_138 ) ;
case V_150 : return ( V_134 ) ;
case V_151 : return ( V_134 ) ;
case V_152 : return ( V_134 ) ;
case V_153 : return ( V_134 ) ;
case V_154 : return ( V_134 ) ;
case V_155 : return ( V_134 ) ;
case V_156 : return ( V_134 ) ;
case V_157 : return ( V_134 ) ;
case V_158 : return ( - 1 ) ;
default: return ( - 1 ) ;
}
}

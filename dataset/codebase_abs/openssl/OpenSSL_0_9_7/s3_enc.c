static int F_1 ( T_1 * V_1 , unsigned char * V_2 , int V_3 )
{
T_2 V_4 ;
T_2 V_5 ;
unsigned char V_6 [ 16 ] , V_7 [ V_8 ] ;
unsigned char V_9 = 'A' ;
int V_10 , V_11 , V_12 ;
#ifdef F_2
V_9 = V_13 [ V_9 ] ;
#endif
V_12 = 0 ;
F_3 ( & V_4 ) ;
F_3 ( & V_5 ) ;
for ( V_10 = 0 ; V_10 < V_3 ; V_10 += V_14 )
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
if ( ( V_10 + V_14 ) > V_3 )
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
int exp , V_41 , V_10 , V_11 , V_12 , V_42 ;
int V_43 = 0 ;
exp = F_13 ( V_1 -> V_20 -> V_44 . V_45 ) ;
V_9 = V_1 -> V_20 -> V_44 . V_46 ;
V_39 = V_1 -> V_20 -> V_44 . V_47 ;
if ( V_1 -> V_20 -> V_44 . V_48 == NULL )
V_38 = NULL ;
else
V_38 = V_1 -> V_20 -> V_44 . V_48 -> V_49 ;
V_26 = V_1 -> V_20 -> V_44 . V_26 ;
if ( V_24 & V_50 )
{
if ( V_1 -> V_51 != NULL )
V_43 = 1 ;
else if ( ( V_1 -> V_51 = F_14 ( sizeof( T_3 ) ) ) == NULL )
goto V_52;
V_37 = V_1 -> V_51 ;
V_1 -> V_53 = V_39 ;
if ( V_1 -> V_54 != NULL )
{
F_15 ( V_1 -> V_54 ) ;
V_1 -> V_54 = NULL ;
}
if ( V_38 != NULL )
{
V_1 -> V_54 = F_16 ( V_38 ) ;
if ( V_1 -> V_54 == NULL )
{
F_4 ( V_55 , V_56 ) ;
goto V_57;
}
if ( V_1 -> V_20 -> V_58 . V_38 == NULL )
V_1 -> V_20 -> V_58 . V_38 = ( unsigned char * )
F_14 ( V_59 ) ;
if ( V_1 -> V_20 -> V_58 . V_38 == NULL )
goto V_52;
}
memset ( & ( V_1 -> V_20 -> V_60 [ 0 ] ) , 0 , 8 ) ;
V_27 = & ( V_1 -> V_20 -> V_61 [ 0 ] ) ;
}
else
{
if ( V_1 -> V_62 != NULL )
V_43 = 1 ;
else if ( ( V_1 -> V_62 = F_14 ( sizeof( T_3 ) ) ) == NULL )
goto V_52;
V_37 = V_1 -> V_62 ;
V_1 -> V_63 = V_39 ;
if ( V_1 -> V_64 != NULL )
{
F_15 ( V_1 -> V_64 ) ;
V_1 -> V_64 = NULL ;
}
if ( V_38 != NULL )
{
V_1 -> V_64 = F_16 ( V_38 ) ;
if ( V_1 -> V_64 == NULL )
{
F_4 ( V_55 , V_56 ) ;
goto V_57;
}
}
memset ( & ( V_1 -> V_20 -> V_65 [ 0 ] ) , 0 , 8 ) ;
V_27 = & ( V_1 -> V_20 -> V_66 [ 0 ] ) ;
}
if ( V_43 )
F_17 ( V_37 ) ;
F_18 ( V_37 ) ;
V_25 = V_1 -> V_20 -> V_44 . V_26 ;
V_10 = F_19 ( V_39 ) ;
V_42 = F_20 ( V_9 ) ;
V_11 = exp ? ( V_42 < F_21 ( V_1 -> V_20 -> V_44 . V_45 ) ?
V_42 : F_21 ( V_1 -> V_20 -> V_44 . V_45 ) ) : V_42 ;
V_12 = F_22 ( V_9 ) ;
if ( ( V_24 == V_67 ) ||
( V_24 == V_68 ) )
{
V_32 = & ( V_25 [ 0 ] ) ; V_41 = V_10 + V_10 ;
V_33 = & ( V_25 [ V_41 ] ) ; V_41 += V_11 + V_11 ;
V_34 = & ( V_25 [ V_41 ] ) ; V_41 += V_12 + V_12 ;
V_35 = & ( V_1 -> V_20 -> V_23 [ 0 ] ) ;
V_36 = & ( V_1 -> V_20 -> V_21 [ 0 ] ) ;
}
else
{
V_41 = V_10 ;
V_32 = & ( V_25 [ V_41 ] ) ; V_41 += V_10 + V_11 ;
V_33 = & ( V_25 [ V_41 ] ) ; V_41 += V_11 + V_12 ;
V_34 = & ( V_25 [ V_41 ] ) ; V_41 += V_12 ;
V_35 = & ( V_1 -> V_20 -> V_21 [ 0 ] ) ;
V_36 = & ( V_1 -> V_20 -> V_23 [ 0 ] ) ;
}
if ( V_41 > V_1 -> V_20 -> V_44 . V_69 )
{
F_4 ( V_55 , V_16 ) ;
goto V_57;
}
F_3 ( & V_40 ) ;
memcpy ( V_27 , V_32 , V_10 ) ;
if ( exp )
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
V_1 -> V_17 -> V_70 = 0 ;
F_23 ( V_37 , V_9 , NULL , V_33 , V_34 , ( V_24 & V_71 ) ) ;
F_10 ( & ( V_28 [ 0 ] ) , sizeof( V_28 ) ) ;
F_10 ( & ( V_30 [ 0 ] ) , sizeof( V_30 ) ) ;
F_11 ( & V_40 ) ;
return ( 1 ) ;
V_52:
F_4 ( V_55 , V_72 ) ;
V_57:
return ( 0 ) ;
}
int F_24 ( T_1 * V_1 )
{
unsigned char * V_25 ;
const T_4 * V_9 ;
const T_6 * V_73 ;
int V_3 ;
int V_74 = 0 ;
T_7 * V_38 ;
if ( V_1 -> V_20 -> V_44 . V_69 != 0 )
return ( 1 ) ;
if ( ! F_25 ( V_1 -> V_17 , & V_9 , & V_73 , & V_38 ) )
{
F_4 ( V_75 , V_76 ) ;
return ( 0 ) ;
}
V_1 -> V_20 -> V_44 . V_46 = V_9 ;
V_1 -> V_20 -> V_44 . V_47 = V_73 ;
V_1 -> V_20 -> V_44 . V_48 = V_38 ;
V_3 = F_20 ( V_9 ) + F_19 ( V_73 ) + F_22 ( V_9 ) ;
V_3 *= 2 ;
F_26 ( V_1 ) ;
if ( ( V_25 = F_14 ( V_3 ) ) == NULL )
goto V_52;
V_1 -> V_20 -> V_44 . V_69 = V_3 ;
V_1 -> V_20 -> V_44 . V_26 = V_25 ;
V_74 = F_1 ( V_1 , V_25 , V_3 ) ;
if ( ! ( V_1 -> V_77 & V_78 ) )
{
V_1 -> V_20 -> V_79 = 1 ;
if ( V_1 -> V_17 -> V_80 != NULL )
{
if ( ( V_1 -> V_17 -> V_80 -> V_81 & V_82 ) == V_83 )
V_1 -> V_20 -> V_79 = 0 ;
#ifndef F_27
if ( ( V_1 -> V_17 -> V_80 -> V_81 & V_82 ) == V_84 )
V_1 -> V_20 -> V_79 = 0 ;
#endif
}
}
return V_74 ;
V_52:
F_4 ( V_75 , V_72 ) ;
return ( 0 ) ;
}
void F_26 ( T_1 * V_1 )
{
if ( V_1 -> V_20 -> V_44 . V_26 != NULL )
{
F_10 ( V_1 -> V_20 -> V_44 . V_26 ,
V_1 -> V_20 -> V_44 . V_69 ) ;
F_28 ( V_1 -> V_20 -> V_44 . V_26 ) ;
V_1 -> V_20 -> V_44 . V_26 = NULL ;
}
V_1 -> V_20 -> V_44 . V_69 = 0 ;
}
int F_29 ( T_1 * V_1 , int V_85 )
{
T_8 * V_86 ;
T_3 * V_87 ;
unsigned long V_88 ;
int V_89 , V_10 ;
const T_4 * V_90 ;
if ( V_85 )
{
V_87 = V_1 -> V_62 ;
V_86 = & ( V_1 -> V_20 -> V_91 ) ;
if ( V_1 -> V_62 == NULL )
V_90 = NULL ;
else
V_90 = F_30 ( V_1 -> V_62 ) ;
}
else
{
V_87 = V_1 -> V_51 ;
V_86 = & ( V_1 -> V_20 -> V_58 ) ;
if ( V_1 -> V_51 == NULL )
V_90 = NULL ;
else
V_90 = F_30 ( V_1 -> V_51 ) ;
}
if ( ( V_1 -> V_17 == NULL ) || ( V_87 == NULL ) ||
( V_90 == NULL ) )
{
memmove ( V_86 -> V_92 , V_86 -> V_93 , V_86 -> V_94 ) ;
V_86 -> V_93 = V_86 -> V_92 ;
}
else
{
V_88 = V_86 -> V_94 ;
V_89 = F_31 ( V_87 -> V_80 ) ;
if ( ( V_89 != 1 ) && V_85 )
{
V_10 = V_89 - ( ( int ) V_88 % V_89 ) ;
V_88 += V_10 ;
V_86 -> V_94 += V_10 ;
V_86 -> V_93 [ V_88 - 1 ] = ( V_10 - 1 ) ;
}
if ( ! V_85 )
{
if ( V_88 == 0 || V_88 % V_89 != 0 )
{
F_4 ( V_95 , V_96 ) ;
F_32 ( V_1 , V_97 , V_98 ) ;
return 0 ;
}
}
F_33 ( V_87 , V_86 -> V_92 , V_86 -> V_93 , V_88 ) ;
if ( ( V_89 != 1 ) && ! V_85 )
{
V_10 = V_86 -> V_92 [ V_88 - 1 ] + 1 ;
if ( V_10 > V_89 )
{
return - 1 ;
}
V_86 -> V_94 -= V_10 ;
}
}
return ( 1 ) ;
}
void F_34 ( T_1 * V_1 )
{
F_5 ( & ( V_1 -> V_20 -> V_99 ) , V_1 -> V_100 -> V_101 , NULL ) ;
F_5 ( & ( V_1 -> V_20 -> V_102 ) , V_1 -> V_100 -> V_103 , NULL ) ;
}
void F_35 ( T_1 * V_1 , const unsigned char * V_6 , int V_104 )
{
F_7 ( & ( V_1 -> V_20 -> V_99 ) , V_6 , V_104 ) ;
F_7 ( & ( V_1 -> V_20 -> V_102 ) , V_6 , V_104 ) ;
}
int F_36 ( T_1 * V_1 , T_2 * V_100 , unsigned char * V_25 )
{
return ( F_37 ( V_1 , V_100 , NULL , 0 , V_25 ) ) ;
}
int F_38 ( T_1 * V_1 , T_2 * V_105 , T_2 * V_106 ,
const char * V_107 , int V_104 , unsigned char * V_25 )
{
int V_74 ;
V_74 = F_37 ( V_1 , V_105 , V_107 , V_104 , V_25 ) ;
V_25 += V_74 ;
V_74 += F_37 ( V_1 , V_106 , V_107 , V_104 , V_25 ) ;
return ( V_74 ) ;
}
static int F_37 ( T_1 * V_1 , T_2 * V_108 ,
const char * V_107 , int V_104 , unsigned char * V_25 )
{
unsigned int V_74 ;
int V_109 , V_41 ;
unsigned int V_10 ;
unsigned char V_110 [ V_111 ] ;
T_2 V_100 ;
F_3 ( & V_100 ) ;
F_39 ( & V_100 , V_108 ) ;
V_41 = F_40 ( & V_100 ) ;
V_109 = ( 48 / V_41 ) * V_41 ;
if ( V_107 != NULL )
F_7 ( & V_100 , V_107 , V_104 ) ;
F_7 ( & V_100 , V_1 -> V_17 -> V_18 ,
V_1 -> V_17 -> V_19 ) ;
F_7 ( & V_100 , V_112 , V_109 ) ;
F_8 ( & V_100 , V_110 , & V_10 ) ;
F_5 ( & V_100 , F_41 ( & V_100 ) , NULL ) ;
F_7 ( & V_100 , V_1 -> V_17 -> V_18 ,
V_1 -> V_17 -> V_19 ) ;
F_7 ( & V_100 , V_113 , V_109 ) ;
F_7 ( & V_100 , V_110 , V_10 ) ;
F_8 ( & V_100 , V_25 , & V_74 ) ;
F_11 ( & V_100 ) ;
return ( ( int ) V_74 ) ;
}
int F_42 ( T_1 * V_114 , unsigned char * V_40 , int V_85 )
{
T_8 * V_86 ;
unsigned char * V_115 , * V_116 ;
T_2 V_117 ;
const T_6 * V_73 ;
unsigned char * V_25 , V_118 ;
unsigned int V_119 ;
int V_109 , V_10 ;
if ( V_85 )
{
V_86 = & ( V_114 -> V_20 -> V_91 ) ;
V_115 = & ( V_114 -> V_20 -> V_66 [ 0 ] ) ;
V_116 = & ( V_114 -> V_20 -> V_65 [ 0 ] ) ;
V_73 = V_114 -> V_63 ;
}
else
{
V_86 = & ( V_114 -> V_20 -> V_58 ) ;
V_115 = & ( V_114 -> V_20 -> V_61 [ 0 ] ) ;
V_116 = & ( V_114 -> V_20 -> V_60 [ 0 ] ) ;
V_73 = V_114 -> V_53 ;
}
V_119 = F_19 ( V_73 ) ;
V_109 = ( 48 / V_119 ) * V_119 ;
F_3 ( & V_117 ) ;
F_5 ( & V_117 , V_73 , NULL ) ;
F_7 ( & V_117 , V_115 , V_119 ) ;
F_7 ( & V_117 , V_112 , V_109 ) ;
F_7 ( & V_117 , V_116 , 8 ) ;
V_118 = V_86 -> type ;
F_7 ( & V_117 , & V_118 , 1 ) ;
V_25 = V_40 ;
F_43 ( V_86 -> V_94 , V_25 ) ;
F_7 ( & V_117 , V_40 , 2 ) ;
F_7 ( & V_117 , V_86 -> V_93 , V_86 -> V_94 ) ;
F_8 ( & V_117 , V_40 , NULL ) ;
F_5 ( & V_117 , V_73 , NULL ) ;
F_7 ( & V_117 , V_115 , V_119 ) ;
F_7 ( & V_117 , V_113 , V_109 ) ;
F_7 ( & V_117 , V_40 , V_119 ) ;
F_8 ( & V_117 , V_40 , & V_119 ) ;
F_11 ( & V_117 ) ;
for ( V_10 = 7 ; V_10 >= 0 ; V_10 -- )
{
++ V_116 [ V_10 ] ;
if ( V_116 [ V_10 ] != 0 ) break;
}
return ( V_119 ) ;
}
int F_44 ( T_1 * V_1 , unsigned char * V_120 , unsigned char * V_25 ,
int V_104 )
{
static const unsigned char * V_121 [ 3 ] = {
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
unsigned char V_6 [ V_111 ] ;
T_2 V_100 ;
int V_10 , V_74 = 0 ;
unsigned int V_41 ;
F_3 ( & V_100 ) ;
for ( V_10 = 0 ; V_10 < 3 ; V_10 ++ )
{
F_5 ( & V_100 , V_1 -> V_100 -> V_103 , NULL ) ;
F_7 ( & V_100 , V_121 [ V_10 ] , strlen ( ( const char * ) V_121 [ V_10 ] ) ) ;
F_7 ( & V_100 , V_25 , V_104 ) ;
F_7 ( & V_100 , & ( V_1 -> V_20 -> V_23 [ 0 ] ) ,
V_22 ) ;
F_7 ( & V_100 , & ( V_1 -> V_20 -> V_21 [ 0 ] ) ,
V_22 ) ;
F_8 ( & V_100 , V_6 , & V_41 ) ;
F_5 ( & V_100 , V_1 -> V_100 -> V_101 , NULL ) ;
F_7 ( & V_100 , V_25 , V_104 ) ;
F_7 ( & V_100 , V_6 , V_41 ) ;
F_8 ( & V_100 , V_120 , & V_41 ) ;
V_120 += V_41 ;
V_74 += V_41 ;
}
F_11 ( & V_100 ) ;
return ( V_74 ) ;
}
int F_45 ( int V_122 )
{
switch ( V_122 )
{
case V_123 : return ( V_124 ) ;
case V_125 : return ( V_126 ) ;
case V_127 : return ( V_128 ) ;
case V_98 : return ( V_128 ) ;
case V_129 : return ( V_128 ) ;
case V_130 : return ( V_131 ) ;
case V_132 : return ( V_133 ) ;
case V_134 : return ( V_135 ) ;
case V_136 : return ( V_137 ) ;
case V_138 : return ( V_139 ) ;
case V_140 : return ( V_141 ) ;
case V_142 : return ( V_143 ) ;
case V_144 : return ( V_145 ) ;
case V_146 : return ( V_147 ) ;
case V_148 : return ( V_137 ) ;
case V_149 : return ( V_133 ) ;
case V_150 : return ( V_133 ) ;
case V_151 : return ( V_133 ) ;
case V_152 : return ( V_133 ) ;
case V_153 : return ( V_133 ) ;
case V_154 : return ( V_133 ) ;
case V_155 : return ( V_133 ) ;
case V_156 : return ( V_133 ) ;
case V_157 : return ( - 1 ) ;
default: return ( - 1 ) ;
}
}

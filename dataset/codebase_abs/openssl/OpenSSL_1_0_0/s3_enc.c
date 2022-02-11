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
#ifndef F_13
T_5 * V_38 ;
#endif
const T_6 * V_39 ;
T_2 V_40 ;
int V_41 , V_42 , V_10 , V_11 , V_12 , V_43 ;
int V_44 = 0 ;
V_41 = F_14 ( V_1 -> V_20 -> V_45 . V_46 ) ;
V_9 = V_1 -> V_20 -> V_45 . V_47 ;
V_39 = V_1 -> V_20 -> V_45 . V_48 ;
F_15 ( V_39 ) ;
#ifndef F_13
if ( V_1 -> V_20 -> V_45 . V_49 == NULL )
V_38 = NULL ;
else
V_38 = V_1 -> V_20 -> V_45 . V_49 -> V_50 ;
#endif
V_26 = V_1 -> V_20 -> V_45 . V_26 ;
if ( V_24 & V_51 )
{
if ( V_1 -> V_52 != NULL )
V_44 = 1 ;
else if ( ( V_1 -> V_52 = F_16 ( sizeof( T_3 ) ) ) == NULL )
goto V_53;
else
F_17 ( V_1 -> V_52 ) ;
V_37 = V_1 -> V_52 ;
F_18 ( & V_1 -> V_54 , V_39 ) ;
#ifndef F_13
if ( V_1 -> V_55 != NULL )
{
F_19 ( V_1 -> V_55 ) ;
V_1 -> V_55 = NULL ;
}
if ( V_38 != NULL )
{
V_1 -> V_55 = F_20 ( V_38 ) ;
if ( V_1 -> V_55 == NULL )
{
F_4 ( V_56 , V_57 ) ;
goto V_58;
}
if ( V_1 -> V_20 -> V_59 . V_38 == NULL )
V_1 -> V_20 -> V_59 . V_38 = ( unsigned char * )
F_16 ( V_60 ) ;
if ( V_1 -> V_20 -> V_59 . V_38 == NULL )
goto V_53;
}
#endif
memset ( & ( V_1 -> V_20 -> V_61 [ 0 ] ) , 0 , 8 ) ;
V_27 = & ( V_1 -> V_20 -> V_62 [ 0 ] ) ;
}
else
{
if ( V_1 -> V_63 != NULL )
V_44 = 1 ;
else if ( ( V_1 -> V_63 = F_16 ( sizeof( T_3 ) ) ) == NULL )
goto V_53;
else
F_17 ( V_1 -> V_63 ) ;
V_37 = V_1 -> V_63 ;
F_18 ( & V_1 -> V_64 , V_39 ) ;
#ifndef F_13
if ( V_1 -> V_65 != NULL )
{
F_19 ( V_1 -> V_65 ) ;
V_1 -> V_65 = NULL ;
}
if ( V_38 != NULL )
{
V_1 -> V_65 = F_20 ( V_38 ) ;
if ( V_1 -> V_65 == NULL )
{
F_4 ( V_56 , V_57 ) ;
goto V_58;
}
}
#endif
memset ( & ( V_1 -> V_20 -> V_66 [ 0 ] ) , 0 , 8 ) ;
V_27 = & ( V_1 -> V_20 -> V_67 [ 0 ] ) ;
}
if ( V_44 )
F_21 ( V_37 ) ;
V_25 = V_1 -> V_20 -> V_45 . V_26 ;
V_10 = F_22 ( V_39 ) ;
if ( V_10 < 0 )
goto V_58;
V_43 = F_23 ( V_9 ) ;
V_11 = V_41 ? ( V_43 < F_24 ( V_1 -> V_20 -> V_45 . V_46 ) ?
V_43 : F_24 ( V_1 -> V_20 -> V_45 . V_46 ) ) : V_43 ;
V_12 = F_25 ( V_9 ) ;
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
F_26 ( V_37 , V_9 , NULL , V_33 , V_34 , ( V_24 & V_72 ) ) ;
F_10 ( & ( V_28 [ 0 ] ) , sizeof( V_28 ) ) ;
F_10 ( & ( V_30 [ 0 ] ) , sizeof( V_30 ) ) ;
F_11 ( & V_40 ) ;
return ( 1 ) ;
V_53:
F_4 ( V_56 , V_73 ) ;
V_58:
return ( 0 ) ;
}
int F_27 ( T_1 * V_1 )
{
unsigned char * V_25 ;
const T_4 * V_9 ;
const T_6 * V_74 ;
int V_3 ;
int V_75 = 0 ;
T_7 * V_38 ;
if ( V_1 -> V_20 -> V_45 . V_70 != 0 )
return ( 1 ) ;
if ( ! F_28 ( V_1 -> V_17 , & V_9 , & V_74 , NULL , NULL , & V_38 ) )
{
F_4 ( V_76 , V_77 ) ;
return ( 0 ) ;
}
V_1 -> V_20 -> V_45 . V_47 = V_9 ;
V_1 -> V_20 -> V_45 . V_48 = V_74 ;
#ifdef F_13
V_1 -> V_20 -> V_45 . V_49 = NULL ;
#else
V_1 -> V_20 -> V_45 . V_49 = V_38 ;
#endif
V_3 = F_22 ( V_74 ) ;
if ( V_3 < 0 )
return 0 ;
V_3 = F_23 ( V_9 ) + V_3 + F_25 ( V_9 ) ;
V_3 *= 2 ;
F_29 ( V_1 ) ;
if ( ( V_25 = F_16 ( V_3 ) ) == NULL )
goto V_53;
V_1 -> V_20 -> V_45 . V_70 = V_3 ;
V_1 -> V_20 -> V_45 . V_26 = V_25 ;
V_75 = F_1 ( V_1 , V_25 , V_3 ) ;
if ( ! ( V_1 -> V_78 & V_79 ) )
{
V_1 -> V_20 -> V_80 = 1 ;
if ( V_1 -> V_17 -> V_81 != NULL )
{
if ( V_1 -> V_17 -> V_81 -> V_82 == V_83 )
V_1 -> V_20 -> V_80 = 0 ;
#ifndef F_30
if ( V_1 -> V_17 -> V_81 -> V_82 == V_84 )
V_1 -> V_20 -> V_80 = 0 ;
#endif
}
}
return V_75 ;
V_53:
F_4 ( V_76 , V_73 ) ;
return ( 0 ) ;
}
void F_29 ( T_1 * V_1 )
{
if ( V_1 -> V_20 -> V_45 . V_26 != NULL )
{
F_10 ( V_1 -> V_20 -> V_45 . V_26 ,
V_1 -> V_20 -> V_45 . V_70 ) ;
F_31 ( V_1 -> V_20 -> V_45 . V_26 ) ;
V_1 -> V_20 -> V_45 . V_26 = NULL ;
}
V_1 -> V_20 -> V_45 . V_70 = 0 ;
}
int F_32 ( T_1 * V_1 , int V_85 )
{
T_8 * V_86 ;
T_3 * V_87 ;
unsigned long V_88 ;
int V_89 , V_10 ;
const T_4 * V_90 ;
if ( V_85 )
{
V_87 = V_1 -> V_63 ;
V_86 = & ( V_1 -> V_20 -> V_91 ) ;
if ( V_1 -> V_63 == NULL )
V_90 = NULL ;
else
V_90 = F_33 ( V_1 -> V_63 ) ;
}
else
{
V_87 = V_1 -> V_52 ;
V_86 = & ( V_1 -> V_20 -> V_59 ) ;
if ( V_1 -> V_52 == NULL )
V_90 = NULL ;
else
V_90 = F_33 ( V_1 -> V_52 ) ;
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
V_89 = F_34 ( V_87 -> V_81 ) ;
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
F_35 ( V_1 , V_97 , V_98 ) ;
return 0 ;
}
}
F_36 ( V_87 , V_86 -> V_92 , V_86 -> V_93 , V_88 ) ;
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
void F_37 ( T_1 * V_1 )
{
if ( V_1 -> V_20 -> V_99 ) F_38 ( V_1 -> V_20 -> V_99 ) ;
if ( V_1 -> V_20 -> V_100 ) F_39 ( V_1 ) ;
V_1 -> V_20 -> V_99 = F_40 ( F_41 () ) ;
( void ) F_42 ( V_1 -> V_20 -> V_99 , V_101 ) ;
}
void F_39 ( T_1 * V_1 )
{
int V_10 ;
if ( ! V_1 -> V_20 -> V_100 ) return;
for ( V_10 = 0 ; V_10 < V_102 ; V_10 ++ )
{
if ( V_1 -> V_20 -> V_100 [ V_10 ] )
F_43 ( V_1 -> V_20 -> V_100 [ V_10 ] ) ;
}
F_31 ( V_1 -> V_20 -> V_100 ) ;
V_1 -> V_20 -> V_100 = NULL ;
}
void F_44 ( T_1 * V_1 , const unsigned char * V_6 , int V_103 )
{
if ( V_1 -> V_20 -> V_99 )
{
F_45 ( V_1 -> V_20 -> V_99 , ( void * ) V_6 , V_103 ) ;
}
else
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_102 ; V_10 ++ )
{
if ( V_1 -> V_20 -> V_100 [ V_10 ] != NULL )
F_7 ( V_1 -> V_20 -> V_100 [ V_10 ] , V_6 , V_103 ) ;
}
}
}
int F_46 ( T_1 * V_1 )
{
int V_10 ;
long V_104 ;
const T_6 * V_40 ;
long V_105 ;
void * V_106 ;
F_39 ( V_1 ) ;
V_1 -> V_20 -> V_100 = F_16 ( V_102 * sizeof( T_2 * ) ) ;
memset ( V_1 -> V_20 -> V_100 , 0 , V_102 * sizeof( T_2 * ) ) ;
V_105 = F_47 ( V_1 -> V_20 -> V_99 , & V_106 ) ;
if ( V_105 <= 0 )
{
F_4 ( V_107 , V_108 ) ;
return 0 ;
}
for ( V_10 = 0 ; F_48 ( V_10 , & V_104 , & V_40 ) ; V_10 ++ )
{
if ( ( V_104 & V_1 -> V_20 -> V_45 . V_46 -> V_109 ) && V_40 )
{
V_1 -> V_20 -> V_100 [ V_10 ] = F_49 () ;
F_5 ( V_1 -> V_20 -> V_100 [ V_10 ] , V_40 , NULL ) ;
F_7 ( V_1 -> V_20 -> V_100 [ V_10 ] , V_106 , V_105 ) ;
}
else
{
V_1 -> V_20 -> V_100 [ V_10 ] = NULL ;
}
}
F_38 ( V_1 -> V_20 -> V_99 ) ;
V_1 -> V_20 -> V_99 = NULL ;
return 1 ;
}
int F_50 ( T_1 * V_1 , int V_110 , unsigned char * V_25 )
{
return ( F_51 ( V_1 , V_110 , NULL , 0 , V_25 ) ) ;
}
int F_52 ( T_1 * V_1 ,
const char * V_111 , int V_103 , unsigned char * V_25 )
{
int V_75 ;
V_75 = F_51 ( V_1 , V_112 , V_111 , V_103 , V_25 ) ;
V_25 += V_75 ;
V_75 += F_51 ( V_1 , V_113 , V_111 , V_103 , V_25 ) ;
return ( V_75 ) ;
}
static int F_51 ( T_1 * V_1 , int V_110 ,
const char * V_111 , int V_103 , unsigned char * V_25 )
{
unsigned int V_75 ;
int V_114 , V_42 ;
unsigned int V_10 ;
unsigned char V_115 [ V_116 ] ;
T_2 V_117 , * V_118 = NULL ;
if ( V_1 -> V_20 -> V_99 )
if ( ! F_46 ( V_1 ) )
return 0 ;
for ( V_10 = 0 ; V_10 < V_102 ; V_10 ++ )
{
if ( V_1 -> V_20 -> V_100 [ V_10 ] && F_53 ( V_1 -> V_20 -> V_100 [ V_10 ] ) == V_110 )
{
V_118 = V_1 -> V_20 -> V_100 [ V_10 ] ;
break;
}
}
if ( ! V_118 ) {
F_4 ( V_119 , V_120 ) ;
return 0 ;
}
F_3 ( & V_117 ) ;
F_54 ( & V_117 , V_118 ) ;
V_42 = F_55 ( & V_117 ) ;
if ( V_42 < 0 )
return 0 ;
V_114 = ( 48 / V_42 ) * V_42 ;
if ( V_111 != NULL )
F_7 ( & V_117 , V_111 , V_103 ) ;
F_7 ( & V_117 , V_1 -> V_17 -> V_18 ,
V_1 -> V_17 -> V_19 ) ;
F_7 ( & V_117 , V_121 , V_114 ) ;
F_8 ( & V_117 , V_115 , & V_10 ) ;
F_5 ( & V_117 , F_56 ( & V_117 ) , NULL ) ;
F_7 ( & V_117 , V_1 -> V_17 -> V_18 ,
V_1 -> V_17 -> V_19 ) ;
F_7 ( & V_117 , V_122 , V_114 ) ;
F_7 ( & V_117 , V_115 , V_10 ) ;
F_8 ( & V_117 , V_25 , & V_75 ) ;
F_11 ( & V_117 ) ;
return ( ( int ) V_75 ) ;
}
int F_57 ( T_1 * V_123 , unsigned char * V_40 , int V_85 )
{
T_8 * V_86 ;
unsigned char * V_124 , * V_125 ;
T_2 V_126 ;
const T_2 * V_74 ;
unsigned char * V_25 , V_127 ;
unsigned int V_128 ;
int V_114 ;
int V_129 ;
if ( V_85 )
{
V_86 = & ( V_123 -> V_20 -> V_91 ) ;
V_124 = & ( V_123 -> V_20 -> V_67 [ 0 ] ) ;
V_125 = & ( V_123 -> V_20 -> V_66 [ 0 ] ) ;
V_74 = V_123 -> V_64 ;
}
else
{
V_86 = & ( V_123 -> V_20 -> V_59 ) ;
V_124 = & ( V_123 -> V_20 -> V_62 [ 0 ] ) ;
V_125 = & ( V_123 -> V_20 -> V_61 [ 0 ] ) ;
V_74 = V_123 -> V_54 ;
}
V_129 = F_55 ( V_74 ) ;
if ( V_129 < 0 )
return - 1 ;
V_128 = V_129 ;
V_114 = ( 48 / V_128 ) * V_128 ;
F_3 ( & V_126 ) ;
F_54 ( & V_126 , V_74 ) ;
F_7 ( & V_126 , V_124 , V_128 ) ;
F_7 ( & V_126 , V_121 , V_114 ) ;
F_7 ( & V_126 , V_125 , 8 ) ;
V_127 = V_86 -> type ;
F_7 ( & V_126 , & V_127 , 1 ) ;
V_25 = V_40 ;
F_58 ( V_86 -> V_94 , V_25 ) ;
F_7 ( & V_126 , V_40 , 2 ) ;
F_7 ( & V_126 , V_86 -> V_93 , V_86 -> V_94 ) ;
F_8 ( & V_126 , V_40 , NULL ) ;
F_54 ( & V_126 , V_74 ) ;
F_7 ( & V_126 , V_124 , V_128 ) ;
F_7 ( & V_126 , V_122 , V_114 ) ;
F_7 ( & V_126 , V_40 , V_128 ) ;
F_8 ( & V_126 , V_40 , & V_128 ) ;
F_11 ( & V_126 ) ;
F_59 ( V_125 ) ;
return ( V_128 ) ;
}
void F_59 ( unsigned char * V_125 )
{
int V_10 ;
for ( V_10 = 7 ; V_10 >= 0 ; V_10 -- )
{
++ V_125 [ V_10 ] ;
if ( V_125 [ V_10 ] != 0 ) break;
}
}
int F_60 ( T_1 * V_1 , unsigned char * V_130 , unsigned char * V_25 ,
int V_103 )
{
static const unsigned char * V_131 [ 3 ] = {
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
unsigned char V_6 [ V_116 ] ;
T_2 V_117 ;
int V_10 , V_75 = 0 ;
unsigned int V_42 ;
F_3 ( & V_117 ) ;
for ( V_10 = 0 ; V_10 < 3 ; V_10 ++ )
{
F_5 ( & V_117 , V_1 -> V_117 -> V_132 , NULL ) ;
F_7 ( & V_117 , V_131 [ V_10 ] , strlen ( ( const char * ) V_131 [ V_10 ] ) ) ;
F_7 ( & V_117 , V_25 , V_103 ) ;
F_7 ( & V_117 , & ( V_1 -> V_20 -> V_23 [ 0 ] ) ,
V_22 ) ;
F_7 ( & V_117 , & ( V_1 -> V_20 -> V_21 [ 0 ] ) ,
V_22 ) ;
F_8 ( & V_117 , V_6 , & V_42 ) ;
F_5 ( & V_117 , V_1 -> V_117 -> V_133 , NULL ) ;
F_7 ( & V_117 , V_25 , V_103 ) ;
F_7 ( & V_117 , V_6 , V_42 ) ;
F_8 ( & V_117 , V_130 , & V_42 ) ;
V_130 += V_42 ;
V_75 += V_42 ;
}
F_11 ( & V_117 ) ;
return ( V_75 ) ;
}
int F_61 ( int V_134 )
{
switch ( V_134 )
{
case V_135 : return ( V_136 ) ;
case V_137 : return ( V_138 ) ;
case V_139 : return ( V_140 ) ;
case V_98 : return ( V_140 ) ;
case V_141 : return ( V_140 ) ;
case V_142 : return ( V_143 ) ;
case V_144 : return ( V_145 ) ;
case V_146 : return ( V_147 ) ;
case V_148 : return ( V_149 ) ;
case V_150 : return ( V_151 ) ;
case V_152 : return ( V_153 ) ;
case V_154 : return ( V_155 ) ;
case V_156 : return ( V_157 ) ;
case V_158 : return ( V_159 ) ;
case V_160 : return ( V_149 ) ;
case V_161 : return ( V_145 ) ;
case V_162 : return ( V_145 ) ;
case V_163 : return ( V_145 ) ;
case V_164 : return ( V_145 ) ;
case V_165 : return ( V_145 ) ;
case V_166 : return ( V_145 ) ;
case V_167 : return ( V_145 ) ;
case V_168 : return ( V_145 ) ;
case V_169 : return ( - 1 ) ;
case V_170 : return ( V_145 ) ;
case V_171 : return ( V_145 ) ;
case V_172 : return ( V_145 ) ;
case V_173 : return ( V_145 ) ;
case V_174 : return ( V_145 ) ;
case V_175 : return ( V_176 ) ;
default: return ( - 1 ) ;
}
}

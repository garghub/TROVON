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
F_4 ( & V_4 , V_14 ) ;
F_3 ( & V_5 ) ;
for ( V_10 = 0 ; ( int ) V_10 < V_3 ; V_10 += V_15 )
{
V_12 ++ ;
if ( V_12 > sizeof V_6 )
{
F_5 ( V_16 , V_17 ) ;
return 0 ;
}
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ )
V_6 [ V_11 ] = V_9 ;
V_9 ++ ;
F_6 ( & V_5 , F_7 () , NULL ) ;
F_8 ( & V_5 , V_6 , V_12 ) ;
F_8 ( & V_5 , V_1 -> V_18 -> V_19 ,
V_1 -> V_18 -> V_20 ) ;
F_8 ( & V_5 , V_1 -> V_21 -> V_22 , V_23 ) ;
F_8 ( & V_5 , V_1 -> V_21 -> V_24 , V_23 ) ;
F_9 ( & V_5 , V_7 , NULL ) ;
F_6 ( & V_4 , F_10 () , NULL ) ;
F_8 ( & V_4 , V_1 -> V_18 -> V_19 ,
V_1 -> V_18 -> V_20 ) ;
F_8 ( & V_4 , V_7 , V_8 ) ;
if ( ( int ) ( V_10 + V_15 ) > V_3 )
{
F_9 ( & V_4 , V_7 , NULL ) ;
memcpy ( V_2 , V_7 , ( V_3 - V_10 ) ) ;
}
else
F_9 ( & V_4 , V_2 , NULL ) ;
V_2 += V_15 ;
}
F_11 ( V_7 , V_8 ) ;
F_12 ( & V_4 ) ;
F_12 ( & V_5 ) ;
return 1 ;
}
int F_13 ( T_1 * V_1 , int V_25 )
{
unsigned char * V_26 , * V_27 ;
unsigned char V_28 [ V_29 ] ;
unsigned char V_30 [ V_31 ] ;
unsigned char * V_32 , * V_33 , * V_34 , * V_35 , * V_36 ;
T_3 * V_37 ;
const T_4 * V_9 ;
#ifndef F_14
T_5 * V_38 ;
#endif
const T_6 * V_39 ;
T_2 V_40 ;
int V_41 , V_42 , V_10 , V_11 , V_12 , V_43 ;
int V_44 = 0 ;
V_41 = F_15 ( V_1 -> V_21 -> V_45 . V_46 ) ;
V_9 = V_1 -> V_21 -> V_45 . V_47 ;
V_39 = V_1 -> V_21 -> V_45 . V_48 ;
F_16 ( V_39 ) ;
#ifndef F_14
if ( V_1 -> V_21 -> V_45 . V_49 == NULL )
V_38 = NULL ;
else
V_38 = V_1 -> V_21 -> V_45 . V_49 -> V_50 ;
#endif
if ( V_25 & V_51 )
{
if ( V_1 -> V_52 != NULL )
V_44 = 1 ;
else if ( ( V_1 -> V_52 = F_17 ( sizeof( T_3 ) ) ) == NULL )
goto V_53;
else
F_18 ( V_1 -> V_52 ) ;
V_37 = V_1 -> V_52 ;
F_19 ( & V_1 -> V_54 , V_39 ) ;
#ifndef F_14
if ( V_1 -> V_55 != NULL )
{
F_20 ( V_1 -> V_55 ) ;
V_1 -> V_55 = NULL ;
}
if ( V_38 != NULL )
{
V_1 -> V_55 = F_21 ( V_38 ) ;
if ( V_1 -> V_55 == NULL )
{
F_5 ( V_56 , V_57 ) ;
goto V_58;
}
if ( V_1 -> V_21 -> V_59 . V_38 == NULL )
V_1 -> V_21 -> V_59 . V_38 = ( unsigned char * )
F_17 ( V_60 ) ;
if ( V_1 -> V_21 -> V_59 . V_38 == NULL )
goto V_53;
}
#endif
memset ( & ( V_1 -> V_21 -> V_61 [ 0 ] ) , 0 , 8 ) ;
V_27 = & ( V_1 -> V_21 -> V_62 [ 0 ] ) ;
}
else
{
if ( V_1 -> V_63 != NULL )
V_44 = 1 ;
else if ( ( V_1 -> V_63 = F_17 ( sizeof( T_3 ) ) ) == NULL )
goto V_53;
else
F_18 ( V_1 -> V_63 ) ;
V_37 = V_1 -> V_63 ;
F_19 ( & V_1 -> V_64 , V_39 ) ;
#ifndef F_14
if ( V_1 -> V_65 != NULL )
{
F_20 ( V_1 -> V_65 ) ;
V_1 -> V_65 = NULL ;
}
if ( V_38 != NULL )
{
V_1 -> V_65 = F_21 ( V_38 ) ;
if ( V_1 -> V_65 == NULL )
{
F_5 ( V_56 , V_57 ) ;
goto V_58;
}
}
#endif
memset ( & ( V_1 -> V_21 -> V_66 [ 0 ] ) , 0 , 8 ) ;
V_27 = & ( V_1 -> V_21 -> V_67 [ 0 ] ) ;
}
if ( V_44 )
F_22 ( V_37 ) ;
V_26 = V_1 -> V_21 -> V_45 . V_68 ;
V_10 = F_23 ( V_39 ) ;
if ( V_10 < 0 )
goto V_58;
V_43 = F_24 ( V_9 ) ;
V_11 = V_41 ? ( V_43 < F_25 ( V_1 -> V_21 -> V_45 . V_46 ) ?
V_43 : F_25 ( V_1 -> V_21 -> V_45 . V_46 ) ) : V_43 ;
V_12 = F_26 ( V_9 ) ;
if ( ( V_25 == V_69 ) ||
( V_25 == V_70 ) )
{
V_32 = & ( V_26 [ 0 ] ) ; V_42 = V_10 + V_10 ;
V_33 = & ( V_26 [ V_42 ] ) ; V_42 += V_11 + V_11 ;
V_34 = & ( V_26 [ V_42 ] ) ; V_42 += V_12 + V_12 ;
V_35 = & ( V_1 -> V_21 -> V_24 [ 0 ] ) ;
V_36 = & ( V_1 -> V_21 -> V_22 [ 0 ] ) ;
}
else
{
V_42 = V_10 ;
V_32 = & ( V_26 [ V_42 ] ) ; V_42 += V_10 + V_11 ;
V_33 = & ( V_26 [ V_42 ] ) ; V_42 += V_11 + V_12 ;
V_34 = & ( V_26 [ V_42 ] ) ; V_42 += V_12 ;
V_35 = & ( V_1 -> V_21 -> V_22 [ 0 ] ) ;
V_36 = & ( V_1 -> V_21 -> V_24 [ 0 ] ) ;
}
if ( V_42 > V_1 -> V_21 -> V_45 . V_71 )
{
F_5 ( V_56 , V_17 ) ;
goto V_58;
}
F_3 ( & V_40 ) ;
memcpy ( V_27 , V_32 , V_10 ) ;
if ( V_41 )
{
F_6 ( & V_40 , F_10 () , NULL ) ;
F_8 ( & V_40 , V_33 , V_11 ) ;
F_8 ( & V_40 , V_35 , V_23 ) ;
F_8 ( & V_40 , V_36 , V_23 ) ;
F_9 ( & V_40 , & ( V_28 [ 0 ] ) , NULL ) ;
V_33 = & ( V_28 [ 0 ] ) ;
if ( V_12 > 0 )
{
F_6 ( & V_40 , F_10 () , NULL ) ;
F_8 ( & V_40 , V_35 , V_23 ) ;
F_8 ( & V_40 , V_36 , V_23 ) ;
F_9 ( & V_40 , & ( V_30 [ 0 ] ) , NULL ) ;
V_34 = & ( V_30 [ 0 ] ) ;
}
}
V_1 -> V_18 -> V_72 = 0 ;
F_27 ( V_37 , V_9 , NULL , V_33 , V_34 , ( V_25 & V_73 ) ) ;
F_11 ( & ( V_28 [ 0 ] ) , sizeof( V_28 ) ) ;
F_11 ( & ( V_30 [ 0 ] ) , sizeof( V_30 ) ) ;
F_12 ( & V_40 ) ;
return ( 1 ) ;
V_53:
F_5 ( V_56 , V_74 ) ;
V_58:
return ( 0 ) ;
}
int F_28 ( T_1 * V_1 )
{
unsigned char * V_26 ;
const T_4 * V_9 ;
const T_6 * V_75 ;
int V_3 ;
int V_76 = 0 ;
T_7 * V_38 ;
if ( V_1 -> V_21 -> V_45 . V_71 != 0 )
return ( 1 ) ;
if ( ! F_29 ( V_1 -> V_18 , & V_9 , & V_75 , NULL , NULL , & V_38 ) )
{
F_5 ( V_77 , V_78 ) ;
return ( 0 ) ;
}
V_1 -> V_21 -> V_45 . V_47 = V_9 ;
V_1 -> V_21 -> V_45 . V_48 = V_75 ;
#ifdef F_14
V_1 -> V_21 -> V_45 . V_49 = NULL ;
#else
V_1 -> V_21 -> V_45 . V_49 = V_38 ;
#endif
V_3 = F_23 ( V_75 ) ;
if ( V_3 < 0 )
return 0 ;
V_3 = F_24 ( V_9 ) + V_3 + F_26 ( V_9 ) ;
V_3 *= 2 ;
F_30 ( V_1 ) ;
if ( ( V_26 = F_17 ( V_3 ) ) == NULL )
goto V_53;
V_1 -> V_21 -> V_45 . V_71 = V_3 ;
V_1 -> V_21 -> V_45 . V_68 = V_26 ;
V_76 = F_1 ( V_1 , V_26 , V_3 ) ;
if ( ! ( V_1 -> V_79 & V_80 ) )
{
V_1 -> V_21 -> V_81 = 1 ;
if ( V_1 -> V_18 -> V_82 != NULL )
{
if ( V_1 -> V_18 -> V_82 -> V_83 == V_84 )
V_1 -> V_21 -> V_81 = 0 ;
#ifndef F_31
if ( V_1 -> V_18 -> V_82 -> V_83 == V_85 )
V_1 -> V_21 -> V_81 = 0 ;
#endif
}
}
return V_76 ;
V_53:
F_5 ( V_77 , V_74 ) ;
return ( 0 ) ;
}
void F_30 ( T_1 * V_1 )
{
if ( V_1 -> V_21 -> V_45 . V_68 != NULL )
{
F_11 ( V_1 -> V_21 -> V_45 . V_68 ,
V_1 -> V_21 -> V_45 . V_71 ) ;
F_32 ( V_1 -> V_21 -> V_45 . V_68 ) ;
V_1 -> V_21 -> V_45 . V_68 = NULL ;
}
V_1 -> V_21 -> V_45 . V_71 = 0 ;
}
int F_33 ( T_1 * V_1 , int V_86 )
{
T_8 * V_87 ;
T_3 * V_88 ;
unsigned long V_89 ;
int V_90 , V_10 ;
const T_4 * V_91 ;
if ( V_86 )
{
V_88 = V_1 -> V_63 ;
V_87 = & ( V_1 -> V_21 -> V_92 ) ;
if ( V_1 -> V_63 == NULL )
V_91 = NULL ;
else
V_91 = F_34 ( V_1 -> V_63 ) ;
}
else
{
V_88 = V_1 -> V_52 ;
V_87 = & ( V_1 -> V_21 -> V_59 ) ;
if ( V_1 -> V_52 == NULL )
V_91 = NULL ;
else
V_91 = F_34 ( V_1 -> V_52 ) ;
}
if ( ( V_1 -> V_18 == NULL ) || ( V_88 == NULL ) ||
( V_91 == NULL ) )
{
memmove ( V_87 -> V_93 , V_87 -> V_94 , V_87 -> V_95 ) ;
V_87 -> V_94 = V_87 -> V_93 ;
}
else
{
V_89 = V_87 -> V_95 ;
V_90 = F_35 ( V_88 -> V_82 ) ;
if ( ( V_90 != 1 ) && V_86 )
{
V_10 = V_90 - ( ( int ) V_89 % V_90 ) ;
V_89 += V_10 ;
memset ( & V_87 -> V_94 [ V_87 -> V_95 ] , 0 , V_10 ) ;
V_87 -> V_95 += V_10 ;
V_87 -> V_94 [ V_89 - 1 ] = ( V_10 - 1 ) ;
}
if ( ! V_86 )
{
if ( V_89 == 0 || V_89 % V_90 != 0 )
{
F_5 ( V_96 , V_97 ) ;
F_36 ( V_1 , V_98 , V_99 ) ;
return 0 ;
}
}
F_37 ( V_88 , V_87 -> V_93 , V_87 -> V_94 , V_89 ) ;
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
void F_38 ( T_1 * V_1 )
{
if ( V_1 -> V_21 -> V_100 ) F_39 ( V_1 -> V_21 -> V_100 ) ;
if ( V_1 -> V_21 -> V_101 ) F_40 ( V_1 ) ;
V_1 -> V_21 -> V_100 = F_41 ( F_42 () ) ;
( void ) F_43 ( V_1 -> V_21 -> V_100 , V_102 ) ;
}
void F_40 ( T_1 * V_1 )
{
int V_10 ;
if ( ! V_1 -> V_21 -> V_101 ) return;
for ( V_10 = 0 ; V_10 < V_103 ; V_10 ++ )
{
if ( V_1 -> V_21 -> V_101 [ V_10 ] )
F_44 ( V_1 -> V_21 -> V_101 [ V_10 ] ) ;
}
F_32 ( V_1 -> V_21 -> V_101 ) ;
V_1 -> V_21 -> V_101 = NULL ;
}
void F_45 ( T_1 * V_1 , const unsigned char * V_6 , int V_104 )
{
if ( V_1 -> V_21 -> V_100 && ! ( V_1 -> V_21 -> V_105 & V_106 ) )
{
F_46 ( V_1 -> V_21 -> V_100 , ( void * ) V_6 , V_104 ) ;
}
else
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_103 ; V_10 ++ )
{
if ( V_1 -> V_21 -> V_101 [ V_10 ] != NULL )
F_8 ( V_1 -> V_21 -> V_101 [ V_10 ] , V_6 , V_104 ) ;
}
}
}
int F_47 ( T_1 * V_1 )
{
int V_10 ;
long V_107 ;
const T_6 * V_40 ;
long V_108 ;
void * V_109 ;
F_40 ( V_1 ) ;
V_1 -> V_21 -> V_101 = F_17 ( V_103 * sizeof( T_2 * ) ) ;
memset ( V_1 -> V_21 -> V_101 , 0 , V_103 * sizeof( T_2 * ) ) ;
V_108 = F_48 ( V_1 -> V_21 -> V_100 , & V_109 ) ;
if ( V_108 <= 0 )
{
F_5 ( V_110 , V_111 ) ;
return 0 ;
}
for ( V_10 = 0 ; F_49 ( V_10 , & V_107 , & V_40 ) ; V_10 ++ )
{
if ( ( V_107 & F_50 ( V_1 ) ) && V_40 )
{
V_1 -> V_21 -> V_101 [ V_10 ] = F_51 () ;
#ifdef F_52
if ( F_53 ( V_40 ) == V_112 )
{
F_4 ( V_1 -> V_21 -> V_101 [ V_10 ] ,
V_14 ) ;
}
#endif
F_6 ( V_1 -> V_21 -> V_101 [ V_10 ] , V_40 , NULL ) ;
F_8 ( V_1 -> V_21 -> V_101 [ V_10 ] , V_109 , V_108 ) ;
}
else
{
V_1 -> V_21 -> V_101 [ V_10 ] = NULL ;
}
}
if ( ! ( V_1 -> V_21 -> V_105 & V_106 ) )
{
F_39 ( V_1 -> V_21 -> V_100 ) ;
V_1 -> V_21 -> V_100 = NULL ;
}
return 1 ;
}
int F_54 ( T_1 * V_1 , int V_113 , unsigned char * V_26 )
{
return ( F_55 ( V_1 , V_113 , NULL , 0 , V_26 ) ) ;
}
int F_56 ( T_1 * V_1 ,
const char * V_114 , int V_104 , unsigned char * V_26 )
{
int V_76 ;
V_76 = F_55 ( V_1 , V_112 , V_114 , V_104 , V_26 ) ;
V_26 += V_76 ;
V_76 += F_55 ( V_1 , V_115 , V_114 , V_104 , V_26 ) ;
return ( V_76 ) ;
}
static int F_55 ( T_1 * V_1 , int V_113 ,
const char * V_114 , int V_104 , unsigned char * V_26 )
{
unsigned int V_76 ;
int V_116 , V_42 ;
unsigned int V_10 ;
unsigned char V_117 [ V_118 ] ;
T_2 V_119 , * V_120 = NULL ;
if ( V_1 -> V_21 -> V_100 )
if ( ! F_47 ( V_1 ) )
return 0 ;
for ( V_10 = 0 ; V_10 < V_103 ; V_10 ++ )
{
if ( V_1 -> V_21 -> V_101 [ V_10 ] && F_57 ( V_1 -> V_21 -> V_101 [ V_10 ] ) == V_113 )
{
V_120 = V_1 -> V_21 -> V_101 [ V_10 ] ;
break;
}
}
if ( ! V_120 ) {
F_5 ( V_121 , V_122 ) ;
return 0 ;
}
F_3 ( & V_119 ) ;
F_4 ( & V_119 , V_14 ) ;
F_58 ( & V_119 , V_120 ) ;
V_42 = F_59 ( & V_119 ) ;
if ( V_42 < 0 )
return 0 ;
V_116 = ( 48 / V_42 ) * V_42 ;
if ( V_114 != NULL )
F_8 ( & V_119 , V_114 , V_104 ) ;
F_8 ( & V_119 , V_1 -> V_18 -> V_19 ,
V_1 -> V_18 -> V_20 ) ;
F_8 ( & V_119 , V_123 , V_116 ) ;
F_9 ( & V_119 , V_117 , & V_10 ) ;
F_6 ( & V_119 , F_60 ( & V_119 ) , NULL ) ;
F_8 ( & V_119 , V_1 -> V_18 -> V_19 ,
V_1 -> V_18 -> V_20 ) ;
F_8 ( & V_119 , V_124 , V_116 ) ;
F_8 ( & V_119 , V_117 , V_10 ) ;
F_9 ( & V_119 , V_26 , & V_76 ) ;
F_12 ( & V_119 ) ;
return ( ( int ) V_76 ) ;
}
int F_61 ( T_1 * V_125 , unsigned char * V_40 , int V_86 )
{
T_8 * V_87 ;
unsigned char * V_126 , * V_127 ;
T_2 V_128 ;
const T_2 * V_75 ;
unsigned char * V_26 , V_129 ;
unsigned int V_130 ;
int V_116 ;
int V_131 ;
if ( V_86 )
{
V_87 = & ( V_125 -> V_21 -> V_92 ) ;
V_126 = & ( V_125 -> V_21 -> V_67 [ 0 ] ) ;
V_127 = & ( V_125 -> V_21 -> V_66 [ 0 ] ) ;
V_75 = V_125 -> V_64 ;
}
else
{
V_87 = & ( V_125 -> V_21 -> V_59 ) ;
V_126 = & ( V_125 -> V_21 -> V_62 [ 0 ] ) ;
V_127 = & ( V_125 -> V_21 -> V_61 [ 0 ] ) ;
V_75 = V_125 -> V_54 ;
}
V_131 = F_59 ( V_75 ) ;
if ( V_131 < 0 )
return - 1 ;
V_130 = V_131 ;
V_116 = ( 48 / V_130 ) * V_130 ;
F_3 ( & V_128 ) ;
F_58 ( & V_128 , V_75 ) ;
F_8 ( & V_128 , V_126 , V_130 ) ;
F_8 ( & V_128 , V_123 , V_116 ) ;
F_8 ( & V_128 , V_127 , 8 ) ;
V_129 = V_87 -> type ;
F_8 ( & V_128 , & V_129 , 1 ) ;
V_26 = V_40 ;
F_62 ( V_87 -> V_95 , V_26 ) ;
F_8 ( & V_128 , V_40 , 2 ) ;
F_8 ( & V_128 , V_87 -> V_94 , V_87 -> V_95 ) ;
F_9 ( & V_128 , V_40 , NULL ) ;
F_58 ( & V_128 , V_75 ) ;
F_8 ( & V_128 , V_126 , V_130 ) ;
F_8 ( & V_128 , V_124 , V_116 ) ;
F_8 ( & V_128 , V_40 , V_130 ) ;
F_9 ( & V_128 , V_40 , & V_130 ) ;
F_12 ( & V_128 ) ;
F_63 ( V_127 ) ;
return ( V_130 ) ;
}
void F_63 ( unsigned char * V_127 )
{
int V_10 ;
for ( V_10 = 7 ; V_10 >= 0 ; V_10 -- )
{
++ V_127 [ V_10 ] ;
if ( V_127 [ V_10 ] != 0 ) break;
}
}
int F_64 ( T_1 * V_1 , unsigned char * V_132 , unsigned char * V_26 ,
int V_104 )
{
static const unsigned char * V_133 [ 3 ] = {
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
unsigned char V_6 [ V_118 ] ;
T_2 V_119 ;
int V_10 , V_76 = 0 ;
unsigned int V_42 ;
F_3 ( & V_119 ) ;
for ( V_10 = 0 ; V_10 < 3 ; V_10 ++ )
{
F_6 ( & V_119 , V_1 -> V_119 -> V_134 , NULL ) ;
F_8 ( & V_119 , V_133 [ V_10 ] , strlen ( ( const char * ) V_133 [ V_10 ] ) ) ;
F_8 ( & V_119 , V_26 , V_104 ) ;
F_8 ( & V_119 , & ( V_1 -> V_21 -> V_24 [ 0 ] ) ,
V_23 ) ;
F_8 ( & V_119 , & ( V_1 -> V_21 -> V_22 [ 0 ] ) ,
V_23 ) ;
F_9 ( & V_119 , V_6 , & V_42 ) ;
F_6 ( & V_119 , V_1 -> V_119 -> V_135 , NULL ) ;
F_8 ( & V_119 , V_26 , V_104 ) ;
F_8 ( & V_119 , V_6 , V_42 ) ;
F_9 ( & V_119 , V_132 , & V_42 ) ;
V_132 += V_42 ;
V_76 += V_42 ;
}
F_12 ( & V_119 ) ;
return ( V_76 ) ;
}
int F_65 ( int V_136 )
{
switch ( V_136 )
{
case V_137 : return ( V_138 ) ;
case V_139 : return ( V_140 ) ;
case V_141 : return ( V_142 ) ;
case V_99 : return ( V_142 ) ;
case V_143 : return ( V_142 ) ;
case V_144 : return ( V_145 ) ;
case V_146 : return ( V_147 ) ;
case V_148 : return ( V_149 ) ;
case V_150 : return ( V_151 ) ;
case V_152 : return ( V_153 ) ;
case V_154 : return ( V_155 ) ;
case V_156 : return ( V_157 ) ;
case V_158 : return ( V_159 ) ;
case V_160 : return ( V_161 ) ;
case V_162 : return ( V_151 ) ;
case V_163 : return ( V_147 ) ;
case V_164 : return ( V_147 ) ;
case V_165 : return ( V_147 ) ;
case V_166 : return ( V_147 ) ;
case V_167 : return ( V_147 ) ;
case V_168 : return ( V_147 ) ;
case V_169 : return ( V_147 ) ;
case V_170 : return ( V_147 ) ;
case V_171 : return ( - 1 ) ;
case V_172 : return ( V_147 ) ;
case V_173 : return ( V_147 ) ;
case V_174 : return ( V_147 ) ;
case V_175 : return ( V_147 ) ;
case V_176 : return ( V_147 ) ;
case V_177 : return ( V_178 ) ;
default: return ( - 1 ) ;
}
}

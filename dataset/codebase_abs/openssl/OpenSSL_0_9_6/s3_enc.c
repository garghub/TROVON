static void F_1 ( T_1 * V_1 , unsigned char * V_2 , int V_3 )
{
T_2 V_4 ;
T_3 V_5 ;
unsigned char V_6 [ 8 ] , V_7 [ V_8 ] ;
unsigned char V_9 = 'A' ;
int V_10 , V_11 , V_12 ;
#ifdef F_2
V_9 = V_13 [ V_9 ] ;
#endif
V_12 = 0 ;
for ( V_10 = 0 ; V_10 < V_3 ; V_10 += V_14 )
{
V_12 ++ ;
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ )
V_6 [ V_11 ] = V_9 ;
V_9 ++ ;
F_3 ( & V_5 ) ;
F_4 ( & V_5 , V_6 , V_12 ) ;
F_4 ( & V_5 , V_1 -> V_15 -> V_16 ,
V_1 -> V_15 -> V_17 ) ;
F_4 ( & V_5 , V_1 -> V_18 -> V_19 , V_20 ) ;
F_4 ( & V_5 , V_1 -> V_18 -> V_21 , V_20 ) ;
F_5 ( V_7 , & V_5 ) ;
F_6 ( & V_4 ) ;
F_7 ( & V_4 , V_1 -> V_15 -> V_16 ,
V_1 -> V_15 -> V_17 ) ;
F_7 ( & V_4 , V_7 , V_8 ) ;
if ( ( V_10 + V_14 ) > V_3 )
{
F_8 ( V_7 , & V_4 ) ;
memcpy ( V_2 , V_7 , ( V_3 - V_10 ) ) ;
}
else
F_8 ( V_2 , & V_4 ) ;
V_2 += V_14 ;
}
memset ( V_7 , 0 , V_8 ) ;
}
int F_9 ( T_1 * V_1 , int V_22 )
{
unsigned char * V_23 , * V_24 , * V_25 ;
unsigned char V_26 [ V_27 ] ;
unsigned char V_28 [ V_27 ] ;
unsigned char * V_29 , * V_30 , * V_31 , * V_32 , * V_33 ;
T_4 * V_34 ;
const T_5 * V_9 ;
T_6 * V_35 ;
const T_7 * V_36 ;
T_2 V_37 ;
int exp , V_38 , V_10 , V_11 , V_12 , V_39 ;
exp = F_10 ( V_1 -> V_18 -> V_40 . V_41 ) ;
V_9 = V_1 -> V_18 -> V_40 . V_42 ;
V_36 = V_1 -> V_18 -> V_40 . V_43 ;
if ( V_1 -> V_18 -> V_40 . V_44 == NULL )
V_35 = NULL ;
else
V_35 = V_1 -> V_18 -> V_40 . V_44 -> V_45 ;
V_24 = V_1 -> V_18 -> V_40 . V_24 ;
if ( V_22 & V_46 )
{
if ( ( V_1 -> V_47 == NULL ) &&
( ( V_1 -> V_47 = ( T_4 * )
F_11 ( sizeof( T_4 ) ) ) == NULL ) )
goto V_48;
V_34 = V_1 -> V_47 ;
V_1 -> V_49 = V_36 ;
if ( V_1 -> V_50 != NULL )
{
F_12 ( V_1 -> V_50 ) ;
V_1 -> V_50 = NULL ;
}
if ( V_35 != NULL )
{
V_1 -> V_50 = F_13 ( V_35 ) ;
if ( V_1 -> V_50 == NULL )
{
F_14 ( V_51 , V_52 ) ;
goto V_53;
}
if ( V_1 -> V_18 -> V_54 . V_35 == NULL )
V_1 -> V_18 -> V_54 . V_35 = ( unsigned char * )
F_11 ( V_55 ) ;
if ( V_1 -> V_18 -> V_54 . V_35 == NULL )
goto V_48;
}
memset ( & ( V_1 -> V_18 -> V_56 [ 0 ] ) , 0 , 8 ) ;
V_25 = & ( V_1 -> V_18 -> V_57 [ 0 ] ) ;
}
else
{
if ( ( V_1 -> V_58 == NULL ) &&
( ( V_1 -> V_58 = ( T_4 * )
F_11 ( sizeof( T_4 ) ) ) == NULL ) )
goto V_48;
V_34 = V_1 -> V_58 ;
V_1 -> V_59 = V_36 ;
if ( V_1 -> V_60 != NULL )
{
F_12 ( V_1 -> V_60 ) ;
V_1 -> V_60 = NULL ;
}
if ( V_35 != NULL )
{
V_1 -> V_60 = F_13 ( V_35 ) ;
if ( V_1 -> V_60 == NULL )
{
F_14 ( V_51 , V_52 ) ;
goto V_53;
}
}
memset ( & ( V_1 -> V_18 -> V_61 [ 0 ] ) , 0 , 8 ) ;
V_25 = & ( V_1 -> V_18 -> V_62 [ 0 ] ) ;
}
F_15 ( V_34 ) ;
V_23 = V_1 -> V_18 -> V_40 . V_24 ;
V_10 = F_16 ( V_36 ) ;
V_39 = F_17 ( V_9 ) ;
V_11 = exp ? ( V_39 < F_18 ( V_1 -> V_18 -> V_40 . V_41 ) ?
V_39 : F_18 ( V_1 -> V_18 -> V_40 . V_41 ) ) : V_39 ;
V_12 = F_19 ( V_9 ) ;
if ( ( V_22 == V_63 ) ||
( V_22 == V_64 ) )
{
V_29 = & ( V_23 [ 0 ] ) ; V_38 = V_10 + V_10 ;
V_30 = & ( V_23 [ V_38 ] ) ; V_38 += V_11 + V_11 ;
V_31 = & ( V_23 [ V_38 ] ) ; V_38 += V_12 + V_12 ;
V_32 = & ( V_1 -> V_18 -> V_21 [ 0 ] ) ;
V_33 = & ( V_1 -> V_18 -> V_19 [ 0 ] ) ;
}
else
{
V_38 = V_10 ;
V_29 = & ( V_23 [ V_38 ] ) ; V_38 += V_10 + V_11 ;
V_30 = & ( V_23 [ V_38 ] ) ; V_38 += V_11 + V_12 ;
V_31 = & ( V_23 [ V_38 ] ) ; V_38 += V_12 ;
V_32 = & ( V_1 -> V_18 -> V_19 [ 0 ] ) ;
V_33 = & ( V_1 -> V_18 -> V_21 [ 0 ] ) ;
}
if ( V_38 > V_1 -> V_18 -> V_40 . V_65 )
{
F_14 ( V_51 , V_66 ) ;
goto V_53;
}
memcpy ( V_25 , V_29 , V_10 ) ;
if ( exp )
{
F_6 ( & V_37 ) ;
F_7 ( & V_37 , V_30 , V_11 ) ;
F_7 ( & V_37 , V_32 , V_20 ) ;
F_7 ( & V_37 , V_33 , V_20 ) ;
F_8 ( & ( V_26 [ 0 ] ) , & V_37 ) ;
V_30 = & ( V_26 [ 0 ] ) ;
if ( V_12 > 0 )
{
F_6 ( & V_37 ) ;
F_7 ( & V_37 , V_32 , V_20 ) ;
F_7 ( & V_37 , V_33 , V_20 ) ;
F_8 ( & ( V_28 [ 0 ] ) , & V_37 ) ;
V_31 = & ( V_28 [ 0 ] ) ;
}
}
V_1 -> V_15 -> V_67 = 0 ;
F_20 ( V_34 , V_9 , V_30 , V_31 , ( V_22 & V_68 ) ) ;
memset ( & ( V_26 [ 0 ] ) , 0 , sizeof( V_26 ) ) ;
memset ( & ( V_28 [ 0 ] ) , 0 , sizeof( V_28 ) ) ;
return ( 1 ) ;
V_48:
F_14 ( V_51 , V_69 ) ;
V_53:
return ( 0 ) ;
}
int F_21 ( T_1 * V_1 )
{
unsigned char * V_23 ;
const T_5 * V_9 ;
const T_7 * V_70 ;
int V_3 ;
T_8 * V_35 ;
if ( V_1 -> V_18 -> V_40 . V_65 != 0 )
return ( 1 ) ;
if ( ! F_22 ( V_1 -> V_15 , & V_9 , & V_70 , & V_35 ) )
{
F_14 ( V_71 , V_72 ) ;
return ( 0 ) ;
}
V_1 -> V_18 -> V_40 . V_42 = V_9 ;
V_1 -> V_18 -> V_40 . V_43 = V_70 ;
V_1 -> V_18 -> V_40 . V_44 = V_35 ;
V_3 = F_17 ( V_9 ) + F_16 ( V_70 ) + F_19 ( V_9 ) ;
V_3 *= 2 ;
F_23 ( V_1 ) ;
if ( ( V_23 = F_11 ( V_3 ) ) == NULL )
goto V_48;
V_1 -> V_18 -> V_40 . V_65 = V_3 ;
V_1 -> V_18 -> V_40 . V_24 = V_23 ;
F_1 ( V_1 , V_23 , V_3 ) ;
return ( 1 ) ;
V_48:
F_14 ( V_71 , V_69 ) ;
return ( 0 ) ;
}
void F_23 ( T_1 * V_1 )
{
if ( V_1 -> V_18 -> V_40 . V_24 != NULL )
{
memset ( V_1 -> V_18 -> V_40 . V_24 , 0 ,
V_1 -> V_18 -> V_40 . V_65 ) ;
F_24 ( V_1 -> V_18 -> V_40 . V_24 ) ;
V_1 -> V_18 -> V_40 . V_24 = NULL ;
}
V_1 -> V_18 -> V_40 . V_65 = 0 ;
}
int F_25 ( T_1 * V_1 , int V_73 )
{
T_9 * V_74 ;
T_4 * V_75 ;
unsigned long V_76 ;
int V_77 , V_10 ;
const T_5 * V_78 ;
if ( V_73 )
{
V_75 = V_1 -> V_58 ;
V_74 = & ( V_1 -> V_18 -> V_79 ) ;
if ( V_1 -> V_58 == NULL )
V_78 = NULL ;
else
V_78 = F_26 ( V_1 -> V_58 ) ;
}
else
{
V_75 = V_1 -> V_47 ;
V_74 = & ( V_1 -> V_18 -> V_54 ) ;
if ( V_1 -> V_47 == NULL )
V_78 = NULL ;
else
V_78 = F_26 ( V_1 -> V_47 ) ;
}
if ( ( V_1 -> V_15 == NULL ) || ( V_75 == NULL ) ||
( V_78 == NULL ) )
{
memcpy ( V_74 -> V_80 , V_74 -> V_81 , V_74 -> V_82 ) ;
V_74 -> V_81 = V_74 -> V_80 ;
}
else
{
V_76 = V_74 -> V_82 ;
V_77 = F_27 ( V_75 -> V_83 ) ;
if ( ( V_77 != 1 ) && V_73 )
{
V_10 = V_77 - ( ( int ) V_76 % V_77 ) ;
V_76 += V_10 ;
V_74 -> V_82 += V_10 ;
V_74 -> V_81 [ V_76 - 1 ] = ( V_10 - 1 ) ;
}
F_28 ( V_75 , V_74 -> V_80 , V_74 -> V_81 , V_76 ) ;
if ( ( V_77 != 1 ) && ! V_73 )
{
V_10 = V_74 -> V_80 [ V_76 - 1 ] + 1 ;
if ( V_10 > V_77 )
{
F_14 ( V_84 , V_85 ) ;
F_29 ( V_1 , V_86 , V_87 ) ;
return ( 0 ) ;
}
V_74 -> V_82 -= V_10 ;
}
}
return ( 1 ) ;
}
void F_30 ( T_1 * V_1 )
{
F_31 ( & ( V_1 -> V_18 -> V_88 ) , V_1 -> V_89 -> V_90 ) ;
F_31 ( & ( V_1 -> V_18 -> V_91 ) , V_1 -> V_89 -> V_92 ) ;
}
void F_32 ( T_1 * V_1 , const unsigned char * V_6 , int V_93 )
{
F_33 ( & ( V_1 -> V_18 -> V_88 ) , V_6 , V_93 ) ;
F_33 ( & ( V_1 -> V_18 -> V_91 ) , V_6 , V_93 ) ;
}
int F_34 ( T_1 * V_1 , T_10 * V_89 , unsigned char * V_23 )
{
return ( F_35 ( V_1 , V_89 , NULL , 0 , V_23 ) ) ;
}
int F_36 ( T_1 * V_1 , T_10 * V_94 , T_10 * V_95 ,
const char * V_96 , int V_93 , unsigned char * V_23 )
{
int V_97 ;
V_97 = F_35 ( V_1 , V_94 , V_96 , V_93 , V_23 ) ;
V_23 += V_97 ;
V_97 += F_35 ( V_1 , V_95 , V_96 , V_93 , V_23 ) ;
return ( V_97 ) ;
}
static int F_35 ( T_1 * V_1 , T_10 * V_98 ,
const char * V_96 , int V_93 , unsigned char * V_23 )
{
unsigned int V_97 ;
int V_99 , V_38 ;
unsigned int V_10 ;
unsigned char V_100 [ V_101 ] ;
T_10 V_89 ;
F_37 ( & V_89 , V_98 ) ;
V_38 = F_38 ( & V_89 ) ;
V_99 = ( 48 / V_38 ) * V_38 ;
if ( V_96 != NULL )
F_33 ( & V_89 , V_96 , V_93 ) ;
F_33 ( & V_89 , V_1 -> V_15 -> V_16 ,
V_1 -> V_15 -> V_17 ) ;
F_33 ( & V_89 , V_102 , V_99 ) ;
F_39 ( & V_89 , V_100 , & V_10 ) ;
F_31 ( & V_89 , F_40 ( & V_89 ) ) ;
F_33 ( & V_89 , V_1 -> V_15 -> V_16 ,
V_1 -> V_15 -> V_17 ) ;
F_33 ( & V_89 , V_103 , V_99 ) ;
F_33 ( & V_89 , V_100 , V_10 ) ;
F_39 ( & V_89 , V_23 , & V_97 ) ;
memset ( & V_89 , 0 , sizeof( T_10 ) ) ;
return ( ( int ) V_97 ) ;
}
int F_41 ( T_1 * V_104 , unsigned char * V_37 , int V_73 )
{
T_9 * V_74 ;
unsigned char * V_105 , * V_106 ;
T_10 V_107 ;
const T_7 * V_70 ;
unsigned char * V_23 , V_108 ;
unsigned int V_109 ;
int V_99 , V_10 ;
if ( V_73 )
{
V_74 = & ( V_104 -> V_18 -> V_79 ) ;
V_105 = & ( V_104 -> V_18 -> V_62 [ 0 ] ) ;
V_106 = & ( V_104 -> V_18 -> V_61 [ 0 ] ) ;
V_70 = V_104 -> V_59 ;
}
else
{
V_74 = & ( V_104 -> V_18 -> V_54 ) ;
V_105 = & ( V_104 -> V_18 -> V_57 [ 0 ] ) ;
V_106 = & ( V_104 -> V_18 -> V_56 [ 0 ] ) ;
V_70 = V_104 -> V_49 ;
}
V_109 = F_16 ( V_70 ) ;
V_99 = ( 48 / V_109 ) * V_109 ;
F_31 ( & V_107 , V_70 ) ;
F_33 ( & V_107 , V_105 , V_109 ) ;
F_33 ( & V_107 , V_102 , V_99 ) ;
F_33 ( & V_107 , V_106 , 8 ) ;
V_108 = V_74 -> type ;
F_33 ( & V_107 , & V_108 , 1 ) ;
V_23 = V_37 ;
F_42 ( V_74 -> V_82 , V_23 ) ;
F_33 ( & V_107 , V_37 , 2 ) ;
F_33 ( & V_107 , V_74 -> V_81 , V_74 -> V_82 ) ;
F_39 ( & V_107 , V_37 , NULL ) ;
F_31 ( & V_107 , V_70 ) ;
F_33 ( & V_107 , V_105 , V_109 ) ;
F_33 ( & V_107 , V_103 , V_99 ) ;
F_33 ( & V_107 , V_37 , V_109 ) ;
F_39 ( & V_107 , V_37 , & V_109 ) ;
for ( V_10 = 7 ; V_10 >= 0 ; V_10 -- )
if ( ++ V_106 [ V_10 ] ) break;
return ( V_109 ) ;
}
int F_43 ( T_1 * V_1 , unsigned char * V_110 , unsigned char * V_23 ,
int V_93 )
{
static const unsigned char * V_111 [ 3 ] = {
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
unsigned char V_6 [ V_101 ] ;
T_10 V_89 ;
int V_10 , V_97 = 0 ;
unsigned int V_38 ;
for ( V_10 = 0 ; V_10 < 3 ; V_10 ++ )
{
F_31 ( & V_89 , V_1 -> V_89 -> V_92 ) ;
F_33 ( & V_89 , V_111 [ V_10 ] , strlen ( ( const char * ) V_111 [ V_10 ] ) ) ;
F_33 ( & V_89 , V_23 , V_93 ) ;
F_33 ( & V_89 , & ( V_1 -> V_18 -> V_21 [ 0 ] ) ,
V_20 ) ;
F_33 ( & V_89 , & ( V_1 -> V_18 -> V_19 [ 0 ] ) ,
V_20 ) ;
F_39 ( & V_89 , V_6 , & V_38 ) ;
F_31 ( & V_89 , V_1 -> V_89 -> V_90 ) ;
F_33 ( & V_89 , V_23 , V_93 ) ;
F_33 ( & V_89 , V_6 , V_38 ) ;
F_39 ( & V_89 , V_110 , & V_38 ) ;
V_110 += V_38 ;
V_97 += V_38 ;
}
return ( V_97 ) ;
}
int F_44 ( int V_112 )
{
switch ( V_112 )
{
case V_113 : return ( V_114 ) ;
case V_115 : return ( V_116 ) ;
case V_117 : return ( V_118 ) ;
case V_119 : return ( V_118 ) ;
case V_120 : return ( V_118 ) ;
case V_121 : return ( V_122 ) ;
case V_123 : return ( V_124 ) ;
case V_125 : return ( V_126 ) ;
case V_127 : return ( V_128 ) ;
case V_129 : return ( V_130 ) ;
case V_131 : return ( V_132 ) ;
case V_133 : return ( V_134 ) ;
case V_135 : return ( V_136 ) ;
case V_137 : return ( V_138 ) ;
case V_139 : return ( V_128 ) ;
case V_140 : return ( V_124 ) ;
case V_141 : return ( V_124 ) ;
case V_87 : return ( V_124 ) ;
case V_142 : return ( V_124 ) ;
case V_143 : return ( V_124 ) ;
case V_144 : return ( V_124 ) ;
case V_145 : return ( V_124 ) ;
case V_146 : return ( V_124 ) ;
case V_147 : return ( - 1 ) ;
default: return ( - 1 ) ;
}
}

static void F_1 ( T_1 * V_1 , unsigned char * V_2 , int V_3 )
{
T_2 V_4 ;
T_3 V_5 ;
unsigned char V_6 [ 8 ] , V_7 [ V_8 ] ;
unsigned char V_9 = 'A' ;
int V_10 , V_11 , V_12 ;
V_12 = 0 ;
for ( V_10 = 0 ; V_10 < V_3 ; V_10 += V_13 )
{
V_12 ++ ;
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ )
V_6 [ V_11 ] = V_9 ;
V_9 ++ ;
F_2 ( & V_5 ) ;
F_3 ( & V_5 , V_6 , V_12 ) ;
F_3 ( & V_5 , V_1 -> V_14 -> V_15 ,
V_1 -> V_14 -> V_16 ) ;
F_3 ( & V_5 , V_1 -> V_17 -> V_18 , V_19 ) ;
F_3 ( & V_5 , V_1 -> V_17 -> V_20 , V_19 ) ;
F_4 ( V_7 , & V_5 ) ;
F_5 ( & V_4 ) ;
F_6 ( & V_4 , V_1 -> V_14 -> V_15 ,
V_1 -> V_14 -> V_16 ) ;
F_6 ( & V_4 , V_7 , V_8 ) ;
if ( ( V_10 + V_13 ) > V_3 )
{
F_7 ( V_7 , & V_4 ) ;
memcpy ( V_2 , V_7 , ( V_3 - V_10 ) ) ;
}
else
F_7 ( V_2 , & V_4 ) ;
V_2 += V_13 ;
}
memset ( V_7 , 0 , V_8 ) ;
}
int F_8 ( T_1 * V_1 , int V_21 )
{
unsigned char * V_22 , * V_23 , * V_24 ;
unsigned char V_25 [ V_26 ] ;
unsigned char V_27 [ V_26 ] ;
unsigned char * V_28 , * V_29 , * V_30 , * V_31 , * V_32 ;
T_4 * V_33 ;
const T_5 * V_9 ;
T_6 * V_34 ;
const T_7 * V_35 ;
T_2 V_36 ;
int exp , V_37 , V_10 , V_11 , V_12 , V_38 ;
exp = F_9 ( V_1 -> V_17 -> V_39 . V_40 ) ;
V_9 = V_1 -> V_17 -> V_39 . V_41 ;
V_35 = V_1 -> V_17 -> V_39 . V_42 ;
if ( V_1 -> V_17 -> V_39 . V_43 == NULL )
V_34 = NULL ;
else
V_34 = V_1 -> V_17 -> V_39 . V_43 -> V_44 ;
V_23 = V_1 -> V_17 -> V_39 . V_23 ;
if ( V_21 & V_45 )
{
if ( ( V_1 -> V_46 == NULL ) &&
( ( V_1 -> V_46 = ( T_4 * )
Malloc ( sizeof( T_4 ) ) ) == NULL ) )
goto V_47;
V_33 = V_1 -> V_46 ;
V_1 -> V_48 = V_35 ;
if ( V_1 -> V_49 != NULL )
{
F_10 ( V_1 -> V_49 ) ;
V_1 -> V_49 = NULL ;
}
if ( V_34 != NULL )
{
V_1 -> V_49 = F_11 ( V_34 ) ;
if ( V_1 -> V_49 == NULL )
{
F_12 ( V_50 , V_51 ) ;
goto V_52;
}
if ( V_1 -> V_17 -> V_53 . V_34 == NULL )
V_1 -> V_17 -> V_53 . V_34 = ( unsigned char * )
Malloc ( V_54 ) ;
if ( V_1 -> V_17 -> V_53 . V_34 == NULL )
goto V_47;
}
memset ( & ( V_1 -> V_17 -> V_55 [ 0 ] ) , 0 , 8 ) ;
V_24 = & ( V_1 -> V_17 -> V_56 [ 0 ] ) ;
}
else
{
if ( ( V_1 -> V_57 == NULL ) &&
( ( V_1 -> V_57 = ( T_4 * )
Malloc ( sizeof( T_4 ) ) ) == NULL ) )
goto V_47;
V_33 = V_1 -> V_57 ;
V_1 -> V_58 = V_35 ;
if ( V_1 -> V_59 != NULL )
{
F_10 ( V_1 -> V_59 ) ;
V_1 -> V_59 = NULL ;
}
if ( V_34 != NULL )
{
V_1 -> V_59 = F_11 ( V_34 ) ;
if ( V_1 -> V_59 == NULL )
{
F_12 ( V_50 , V_51 ) ;
goto V_52;
}
}
memset ( & ( V_1 -> V_17 -> V_60 [ 0 ] ) , 0 , 8 ) ;
V_24 = & ( V_1 -> V_17 -> V_61 [ 0 ] ) ;
}
F_13 ( V_33 ) ;
V_22 = V_1 -> V_17 -> V_39 . V_23 ;
V_10 = F_14 ( V_35 ) ;
V_38 = F_15 ( V_9 ) ;
V_11 = exp ? ( V_38 < F_16 ( V_1 -> V_17 -> V_39 . V_40 ) ?
V_38 : F_16 ( V_1 -> V_17 -> V_39 . V_40 ) ) : V_38 ;
V_12 = F_17 ( V_9 ) ;
if ( ( V_21 == V_62 ) ||
( V_21 == V_63 ) )
{
V_28 = & ( V_22 [ 0 ] ) ; V_37 = V_10 + V_10 ;
V_29 = & ( V_22 [ V_37 ] ) ; V_37 += V_11 + V_11 ;
V_30 = & ( V_22 [ V_37 ] ) ; V_37 += V_12 + V_12 ;
V_31 = & ( V_1 -> V_17 -> V_20 [ 0 ] ) ;
V_32 = & ( V_1 -> V_17 -> V_18 [ 0 ] ) ;
}
else
{
V_37 = V_10 ;
V_28 = & ( V_22 [ V_37 ] ) ; V_37 += V_10 + V_11 ;
V_29 = & ( V_22 [ V_37 ] ) ; V_37 += V_11 + V_12 ;
V_30 = & ( V_22 [ V_37 ] ) ; V_37 += V_12 ;
V_31 = & ( V_1 -> V_17 -> V_18 [ 0 ] ) ;
V_32 = & ( V_1 -> V_17 -> V_20 [ 0 ] ) ;
}
if ( V_37 > V_1 -> V_17 -> V_39 . V_64 )
{
F_12 ( V_50 , V_65 ) ;
goto V_52;
}
memcpy ( V_24 , V_28 , V_10 ) ;
if ( exp )
{
F_5 ( & V_36 ) ;
F_6 ( & V_36 , V_29 , V_11 ) ;
F_6 ( & V_36 , V_31 , V_19 ) ;
F_6 ( & V_36 , V_32 , V_19 ) ;
F_7 ( & ( V_25 [ 0 ] ) , & V_36 ) ;
V_29 = & ( V_25 [ 0 ] ) ;
if ( V_12 > 0 )
{
F_5 ( & V_36 ) ;
F_6 ( & V_36 , V_31 , V_19 ) ;
F_6 ( & V_36 , V_32 , V_19 ) ;
F_7 ( & ( V_27 [ 0 ] ) , & V_36 ) ;
V_30 = & ( V_27 [ 0 ] ) ;
}
}
V_1 -> V_14 -> V_66 = 0 ;
F_18 ( V_33 , V_9 , V_29 , V_30 , ( V_21 & V_67 ) ) ;
memset ( & ( V_25 [ 0 ] ) , 0 , sizeof( V_25 ) ) ;
memset ( & ( V_27 [ 0 ] ) , 0 , sizeof( V_27 ) ) ;
return ( 1 ) ;
V_47:
F_12 ( V_50 , V_68 ) ;
V_52:
return ( 0 ) ;
}
int F_19 ( T_1 * V_1 )
{
unsigned char * V_22 ;
const T_5 * V_9 ;
const T_7 * V_69 ;
int V_3 ;
T_8 * V_34 ;
if ( V_1 -> V_17 -> V_39 . V_64 != 0 )
return ( 1 ) ;
if ( ! F_20 ( V_1 -> V_14 , & V_9 , & V_69 , & V_34 ) )
{
F_12 ( V_70 , V_71 ) ;
return ( 0 ) ;
}
V_1 -> V_17 -> V_39 . V_41 = V_9 ;
V_1 -> V_17 -> V_39 . V_42 = V_69 ;
V_1 -> V_17 -> V_39 . V_43 = V_34 ;
V_3 = F_15 ( V_9 ) + F_14 ( V_69 ) + F_17 ( V_9 ) ;
V_3 *= 2 ;
F_21 ( V_1 ) ;
if ( ( V_22 = ( unsigned char * ) Malloc ( V_3 ) ) == NULL )
goto V_47;
V_1 -> V_17 -> V_39 . V_64 = V_3 ;
V_1 -> V_17 -> V_39 . V_23 = V_22 ;
F_1 ( V_1 , V_22 , V_3 ) ;
return ( 1 ) ;
V_47:
F_12 ( V_70 , V_68 ) ;
return ( 0 ) ;
}
void F_21 ( T_1 * V_1 )
{
if ( V_1 -> V_17 -> V_39 . V_23 != NULL )
{
memset ( V_1 -> V_17 -> V_39 . V_23 , 0 ,
V_1 -> V_17 -> V_39 . V_64 ) ;
Free ( V_1 -> V_17 -> V_39 . V_23 ) ;
V_1 -> V_17 -> V_39 . V_23 = NULL ;
}
V_1 -> V_17 -> V_39 . V_64 = 0 ;
}
int F_22 ( T_1 * V_1 , int V_72 )
{
T_9 * V_73 ;
T_4 * V_74 ;
unsigned long V_75 ;
int V_76 , V_10 ;
const T_5 * V_77 ;
if ( V_72 )
{
V_74 = V_1 -> V_57 ;
V_73 = & ( V_1 -> V_17 -> V_78 ) ;
if ( V_1 -> V_57 == NULL )
V_77 = NULL ;
else
V_77 = F_23 ( V_1 -> V_57 ) ;
}
else
{
V_74 = V_1 -> V_46 ;
V_73 = & ( V_1 -> V_17 -> V_53 ) ;
if ( V_1 -> V_46 == NULL )
V_77 = NULL ;
else
V_77 = F_23 ( V_1 -> V_46 ) ;
}
if ( ( V_1 -> V_14 == NULL ) || ( V_74 == NULL ) ||
( V_77 == NULL ) )
{
memcpy ( V_73 -> V_79 , V_73 -> V_80 , V_73 -> V_81 ) ;
V_73 -> V_80 = V_73 -> V_79 ;
}
else
{
V_75 = V_73 -> V_81 ;
V_76 = F_24 ( V_74 -> V_82 ) ;
if ( ( V_76 != 1 ) && V_72 )
{
V_10 = V_76 - ( ( int ) V_75 % V_76 ) ;
V_75 += V_10 ;
V_73 -> V_81 += V_10 ;
V_73 -> V_80 [ V_75 - 1 ] = ( V_10 - 1 ) ;
}
F_25 ( V_74 , V_73 -> V_79 , V_73 -> V_80 , V_75 ) ;
if ( ( V_76 != 1 ) && ! V_72 )
{
V_10 = V_73 -> V_79 [ V_75 - 1 ] + 1 ;
if ( V_10 > V_76 )
{
F_12 ( V_83 , V_84 ) ;
F_26 ( V_1 , V_85 , V_86 ) ;
return ( 0 ) ;
}
V_73 -> V_81 -= V_10 ;
}
}
return ( 1 ) ;
}
void F_27 ( T_1 * V_1 )
{
F_28 ( & ( V_1 -> V_17 -> V_87 ) , V_1 -> V_88 -> V_89 ) ;
F_28 ( & ( V_1 -> V_17 -> V_90 ) , V_1 -> V_88 -> V_91 ) ;
}
void F_29 ( T_1 * V_1 , const unsigned char * V_6 , int V_92 )
{
F_30 ( & ( V_1 -> V_17 -> V_87 ) , V_6 , V_92 ) ;
F_30 ( & ( V_1 -> V_17 -> V_90 ) , V_6 , V_92 ) ;
}
int F_31 ( T_1 * V_1 , T_10 * V_88 , unsigned char * V_22 )
{
return ( F_32 ( V_1 , V_88 , NULL , 0 , V_22 ) ) ;
}
int F_33 ( T_1 * V_1 , T_10 * V_93 , T_10 * V_94 ,
unsigned char * V_95 , int V_92 , unsigned char * V_22 )
{
int V_96 ;
V_96 = F_32 ( V_1 , V_93 , V_95 , V_92 , V_22 ) ;
V_22 += V_96 ;
V_96 += F_32 ( V_1 , V_94 , V_95 , V_92 , V_22 ) ;
return ( V_96 ) ;
}
static int F_32 ( T_1 * V_1 , T_10 * V_97 ,
unsigned char * V_95 , int V_92 , unsigned char * V_22 )
{
unsigned int V_96 ;
int V_98 , V_37 ;
unsigned int V_10 ;
unsigned char V_99 [ V_100 ] ;
T_10 V_88 ;
F_34 ( & V_88 , V_97 ) ;
V_37 = F_35 ( & V_88 ) ;
V_98 = ( 48 / V_37 ) * V_37 ;
if ( V_95 != NULL )
F_30 ( & V_88 , V_95 , V_92 ) ;
F_30 ( & V_88 , V_1 -> V_14 -> V_15 ,
V_1 -> V_14 -> V_16 ) ;
F_30 ( & V_88 , V_101 , V_98 ) ;
F_36 ( & V_88 , V_99 , & V_10 ) ;
F_28 ( & V_88 , F_37 ( & V_88 ) ) ;
F_30 ( & V_88 , V_1 -> V_14 -> V_15 ,
V_1 -> V_14 -> V_16 ) ;
F_30 ( & V_88 , V_102 , V_98 ) ;
F_30 ( & V_88 , V_99 , V_10 ) ;
F_36 ( & V_88 , V_22 , & V_96 ) ;
memset ( & V_88 , 0 , sizeof( T_10 ) ) ;
return ( ( int ) V_96 ) ;
}
int F_38 ( T_1 * V_103 , unsigned char * V_36 , int V_72 )
{
T_9 * V_73 ;
unsigned char * V_104 , * V_105 ;
T_10 V_106 ;
const T_7 * V_69 ;
unsigned char * V_22 , V_107 ;
unsigned int V_108 ;
int V_98 , V_10 ;
if ( V_72 )
{
V_73 = & ( V_103 -> V_17 -> V_78 ) ;
V_104 = & ( V_103 -> V_17 -> V_61 [ 0 ] ) ;
V_105 = & ( V_103 -> V_17 -> V_60 [ 0 ] ) ;
V_69 = V_103 -> V_58 ;
}
else
{
V_73 = & ( V_103 -> V_17 -> V_53 ) ;
V_104 = & ( V_103 -> V_17 -> V_56 [ 0 ] ) ;
V_105 = & ( V_103 -> V_17 -> V_55 [ 0 ] ) ;
V_69 = V_103 -> V_48 ;
}
V_108 = F_14 ( V_69 ) ;
V_98 = ( 48 / V_108 ) * V_108 ;
F_28 ( & V_106 , V_69 ) ;
F_30 ( & V_106 , V_104 , V_108 ) ;
F_30 ( & V_106 , V_101 , V_98 ) ;
F_30 ( & V_106 , V_105 , 8 ) ;
V_107 = V_73 -> type ;
F_30 ( & V_106 , & V_107 , 1 ) ;
V_22 = V_36 ;
F_39 ( V_73 -> V_81 , V_22 ) ;
F_30 ( & V_106 , V_36 , 2 ) ;
F_30 ( & V_106 , V_73 -> V_80 , V_73 -> V_81 ) ;
F_36 ( & V_106 , V_36 , NULL ) ;
F_28 ( & V_106 , V_69 ) ;
F_30 ( & V_106 , V_104 , V_108 ) ;
F_30 ( & V_106 , V_102 , V_98 ) ;
F_30 ( & V_106 , V_36 , V_108 ) ;
F_36 ( & V_106 , V_36 , & V_108 ) ;
for ( V_10 = 7 ; V_10 >= 0 ; V_10 -- )
if ( ++ V_105 [ V_10 ] ) break;
return ( V_108 ) ;
}
int F_40 ( T_1 * V_1 , unsigned char * V_109 , unsigned char * V_22 ,
int V_92 )
{
static const unsigned char * V_110 [ 3 ] = {
( const unsigned char * ) L_1 ,
( const unsigned char * ) L_2 ,
( const unsigned char * ) L_3 ,
} ;
unsigned char V_6 [ V_100 ] ;
T_10 V_88 ;
int V_10 , V_96 = 0 ;
unsigned int V_37 ;
for ( V_10 = 0 ; V_10 < 3 ; V_10 ++ )
{
F_28 ( & V_88 , V_1 -> V_88 -> V_91 ) ;
F_30 ( & V_88 , V_110 [ V_10 ] , strlen ( ( const char * ) V_110 [ V_10 ] ) ) ;
F_30 ( & V_88 , V_22 , V_92 ) ;
F_30 ( & V_88 , & ( V_1 -> V_17 -> V_20 [ 0 ] ) ,
V_19 ) ;
F_30 ( & V_88 , & ( V_1 -> V_17 -> V_18 [ 0 ] ) ,
V_19 ) ;
F_36 ( & V_88 , V_6 , & V_37 ) ;
F_28 ( & V_88 , V_1 -> V_88 -> V_89 ) ;
F_30 ( & V_88 , V_22 , V_92 ) ;
F_30 ( & V_88 , V_6 , V_37 ) ;
F_36 ( & V_88 , V_109 , & V_37 ) ;
V_109 += V_37 ;
V_96 += V_37 ;
}
return ( V_96 ) ;
}
int F_41 ( int V_111 )
{
switch ( V_111 )
{
case V_112 : return ( V_113 ) ;
case V_114 : return ( V_115 ) ;
case V_116 : return ( V_117 ) ;
case V_118 : return ( V_117 ) ;
case V_119 : return ( V_117 ) ;
case V_120 : return ( V_121 ) ;
case V_122 : return ( V_123 ) ;
case V_124 : return ( V_125 ) ;
case V_126 : return ( V_127 ) ;
case V_128 : return ( V_129 ) ;
case V_130 : return ( V_131 ) ;
case V_132 : return ( V_133 ) ;
case V_134 : return ( V_135 ) ;
case V_136 : return ( V_137 ) ;
case V_138 : return ( V_127 ) ;
case V_139 : return ( V_123 ) ;
case V_140 : return ( V_123 ) ;
case V_86 : return ( V_123 ) ;
case V_141 : return ( V_123 ) ;
case V_142 : return ( V_123 ) ;
case V_143 : return ( V_123 ) ;
case V_144 : return ( V_123 ) ;
case V_145 : return ( V_123 ) ;
case V_146 : return ( - 1 ) ;
default: return ( - 1 ) ;
}
}

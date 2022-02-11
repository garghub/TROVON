static int F_1 ( T_1 * V_1 , unsigned char * V_2 , int V_3 )
{
T_2 * V_4 ;
T_2 * V_5 ;
unsigned char V_6 [ 16 ] , V_7 [ V_8 ] ;
unsigned char V_9 = 'A' ;
unsigned int V_10 , V_11 , V_12 ;
int V_13 = 0 ;
#ifdef F_2
V_9 = V_14 [ V_9 ] ;
#endif
V_12 = 0 ;
V_4 = F_3 () ;
V_5 = F_3 () ;
if ( V_4 == NULL || V_5 == NULL ) {
F_4 ( V_15 , V_16 ) ;
goto V_17;
}
F_5 ( V_4 , V_18 ) ;
for ( V_10 = 0 ; ( int ) V_10 < V_3 ; V_10 += V_19 ) {
V_12 ++ ;
if ( V_12 > sizeof V_6 ) {
F_4 ( V_15 , V_20 ) ;
return 0 ;
}
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ )
V_6 [ V_11 ] = V_9 ;
V_9 ++ ;
if ( ! F_6 ( V_5 , F_7 () , NULL )
|| ! F_8 ( V_5 , V_6 , V_12 )
|| ! F_8 ( V_5 , V_1 -> V_21 -> V_22 ,
V_1 -> V_21 -> V_23 )
|| ! F_8 ( V_5 , V_1 -> V_24 -> V_25 , V_26 )
|| ! F_8 ( V_5 , V_1 -> V_24 -> V_27 , V_26 )
|| ! F_9 ( V_5 , V_7 , NULL )
|| ! F_6 ( V_4 , F_10 () , NULL )
|| ! F_8 ( V_4 , V_1 -> V_21 -> V_22 ,
V_1 -> V_21 -> V_23 )
|| ! F_8 ( V_4 , V_7 , V_8 ) )
goto V_17;
if ( ( int ) ( V_10 + V_19 ) > V_3 ) {
if ( ! F_9 ( V_4 , V_7 , NULL ) )
goto V_17;
memcpy ( V_2 , V_7 , ( V_3 - V_10 ) ) ;
} else {
if ( ! F_9 ( V_4 , V_2 , NULL ) )
goto V_17;
}
V_2 += V_19 ;
}
F_11 ( V_7 , sizeof( V_7 ) ) ;
V_13 = 1 ;
V_17:
F_12 ( V_4 ) ;
F_12 ( V_5 ) ;
return V_13 ;
}
int F_13 ( T_1 * V_1 , int V_28 )
{
unsigned char * V_29 , * V_30 ;
unsigned char V_31 [ V_32 ] ;
unsigned char V_33 [ V_34 ] ;
unsigned char * V_35 , * V_36 , * V_37 ;
T_3 * V_38 ;
const T_4 * V_9 ;
#ifndef F_14
T_5 * V_39 ;
#endif
const T_6 * V_40 ;
int V_41 , V_10 , V_11 , V_12 , V_42 ;
int V_43 = 0 ;
V_9 = V_1 -> V_24 -> V_44 . V_45 ;
V_40 = V_1 -> V_24 -> V_44 . V_46 ;
F_15 ( V_40 ) ;
#ifndef F_14
if ( V_1 -> V_24 -> V_44 . V_47 == NULL )
V_39 = NULL ;
else
V_39 = V_1 -> V_24 -> V_44 . V_47 -> V_48 ;
#endif
if ( V_28 & V_49 ) {
if ( V_1 -> V_50 != NULL )
V_43 = 1 ;
else if ( ( V_1 -> V_50 = F_16 () ) == NULL )
goto V_17;
else
F_17 ( V_1 -> V_50 ) ;
V_38 = V_1 -> V_50 ;
if ( F_18 ( & V_1 -> V_51 , V_40 ) == NULL ) {
F_4 ( V_52 , V_20 ) ;
goto V_53;
}
#ifndef F_14
F_19 ( V_1 -> V_54 ) ;
V_1 -> V_54 = NULL ;
if ( V_39 != NULL ) {
V_1 -> V_54 = F_20 ( V_39 ) ;
if ( V_1 -> V_54 == NULL ) {
F_4 ( V_52 ,
V_55 ) ;
goto V_53;
}
}
#endif
F_21 ( & V_1 -> V_56 ) ;
V_30 = & ( V_1 -> V_24 -> V_57 [ 0 ] ) ;
} else {
if ( V_1 -> V_58 != NULL )
V_43 = 1 ;
else if ( ( V_1 -> V_58 = F_16 () ) == NULL )
goto V_17;
else
F_17 ( V_1 -> V_58 ) ;
V_38 = V_1 -> V_58 ;
if ( F_18 ( & V_1 -> V_59 , V_40 ) == NULL ) {
F_4 ( V_52 , V_20 ) ;
goto V_53;
}
#ifndef F_14
F_19 ( V_1 -> V_60 ) ;
V_1 -> V_60 = NULL ;
if ( V_39 != NULL ) {
V_1 -> V_60 = F_20 ( V_39 ) ;
if ( V_1 -> V_60 == NULL ) {
F_4 ( V_52 ,
V_55 ) ;
goto V_53;
}
}
#endif
F_22 ( & V_1 -> V_56 ) ;
V_30 = & ( V_1 -> V_24 -> V_61 [ 0 ] ) ;
}
if ( V_43 )
F_17 ( V_38 ) ;
V_29 = V_1 -> V_24 -> V_44 . V_62 ;
V_10 = F_23 ( V_40 ) ;
if ( V_10 < 0 )
goto V_53;
V_42 = F_24 ( V_9 ) ;
V_11 = V_42 ;
V_12 = F_25 ( V_9 ) ;
if ( ( V_28 == V_63 ) ||
( V_28 == V_64 ) ) {
V_35 = & ( V_29 [ 0 ] ) ;
V_41 = V_10 + V_10 ;
V_36 = & ( V_29 [ V_41 ] ) ;
V_41 += V_11 + V_11 ;
V_37 = & ( V_29 [ V_41 ] ) ;
V_41 += V_12 + V_12 ;
} else {
V_41 = V_10 ;
V_35 = & ( V_29 [ V_41 ] ) ;
V_41 += V_10 + V_11 ;
V_36 = & ( V_29 [ V_41 ] ) ;
V_41 += V_11 + V_12 ;
V_37 = & ( V_29 [ V_41 ] ) ;
V_41 += V_12 ;
}
if ( V_41 > V_1 -> V_24 -> V_44 . V_65 ) {
F_4 ( V_52 , V_20 ) ;
goto V_53;
}
memcpy ( V_30 , V_35 , V_10 ) ;
F_26 ( V_38 , V_9 , NULL , V_36 , V_37 , ( V_28 & V_66 ) ) ;
#ifdef F_27
if ( V_1 -> V_67 ) {
int V_68 = V_28 & V_66 ?
V_69 : V_70 ;
V_1 -> V_67 ( 2 , V_1 -> V_71 , V_68 | V_72 ,
V_30 , F_23 ( V_40 ) , V_1 , V_1 -> V_73 ) ;
if ( V_9 -> V_74 )
V_1 -> V_67 ( 2 , V_1 -> V_71 , V_68 | V_75 ,
V_36 , V_9 -> V_74 , V_1 , V_1 -> V_73 ) ;
if ( V_12 ) {
V_1 -> V_67 ( 2 , V_1 -> V_71 , V_68 | V_76 ,
V_37 , V_12 , V_1 , V_1 -> V_73 ) ;
}
}
#endif
F_11 ( V_31 , sizeof( V_31 ) ) ;
F_11 ( V_33 , sizeof( V_33 ) ) ;
return ( 1 ) ;
V_17:
F_4 ( V_52 , V_16 ) ;
V_53:
F_11 ( V_31 , sizeof( V_31 ) ) ;
F_11 ( V_33 , sizeof( V_33 ) ) ;
return ( 0 ) ;
}
int F_28 ( T_1 * V_1 )
{
unsigned char * V_29 ;
const T_4 * V_9 ;
const T_6 * V_77 ;
int V_3 ;
int V_13 = 0 ;
T_7 * V_39 ;
if ( V_1 -> V_24 -> V_44 . V_65 != 0 )
return ( 1 ) ;
if ( ! F_29 ( V_1 -> V_21 , & V_9 , & V_77 , NULL , NULL , & V_39 , 0 ) ) {
F_4 ( V_78 , V_79 ) ;
return ( 0 ) ;
}
V_1 -> V_24 -> V_44 . V_45 = V_9 ;
V_1 -> V_24 -> V_44 . V_46 = V_77 ;
#ifdef F_14
V_1 -> V_24 -> V_44 . V_47 = NULL ;
#else
V_1 -> V_24 -> V_44 . V_47 = V_39 ;
#endif
V_3 = F_23 ( V_77 ) ;
if ( V_3 < 0 )
return 0 ;
V_3 = F_24 ( V_9 ) + V_3 + F_25 ( V_9 ) ;
V_3 *= 2 ;
F_30 ( V_1 ) ;
if ( ( V_29 = F_31 ( V_3 ) ) == NULL )
goto V_17;
V_1 -> V_24 -> V_44 . V_65 = V_3 ;
V_1 -> V_24 -> V_44 . V_62 = V_29 ;
V_13 = F_1 ( V_1 , V_29 , V_3 ) ;
if ( ! ( V_1 -> V_80 & V_81 ) ) {
V_1 -> V_24 -> V_82 = 1 ;
if ( V_1 -> V_21 -> V_83 != NULL ) {
if ( V_1 -> V_21 -> V_83 -> V_84 == V_85 )
V_1 -> V_24 -> V_82 = 0 ;
#ifndef F_32
if ( V_1 -> V_21 -> V_83 -> V_84 == V_86 )
V_1 -> V_24 -> V_82 = 0 ;
#endif
}
}
return V_13 ;
V_17:
F_4 ( V_78 , V_16 ) ;
return ( 0 ) ;
}
void F_30 ( T_1 * V_1 )
{
F_33 ( V_1 -> V_24 -> V_44 . V_62 , V_1 -> V_24 -> V_44 . V_65 ) ;
V_1 -> V_24 -> V_44 . V_62 = NULL ;
V_1 -> V_24 -> V_44 . V_65 = 0 ;
}
int F_34 ( T_1 * V_1 )
{
T_8 * V_6 = F_35 ( F_36 () ) ;
if ( V_6 == NULL ) {
F_4 ( V_87 , V_16 ) ;
return 0 ;
}
F_37 ( V_1 ) ;
V_1 -> V_24 -> V_88 = V_6 ;
( void ) F_38 ( V_1 -> V_24 -> V_88 , V_89 ) ;
return 1 ;
}
void F_37 ( T_1 * V_1 )
{
F_39 ( V_1 -> V_24 -> V_88 ) ;
V_1 -> V_24 -> V_88 = NULL ;
F_12 ( V_1 -> V_24 -> V_90 ) ;
V_1 -> V_24 -> V_90 = NULL ;
}
int F_40 ( T_1 * V_1 , const unsigned char * V_6 , int V_91 )
{
if ( V_1 -> V_24 -> V_90 == NULL )
return F_41 ( V_1 -> V_24 -> V_88 , ( void * ) V_6 , V_91 ) == V_91 ;
else
return F_8 ( V_1 -> V_24 -> V_90 , V_6 , V_91 ) ;
}
int F_42 ( T_1 * V_1 , int V_92 )
{
const T_6 * V_93 ;
long V_94 ;
void * V_95 ;
if ( V_1 -> V_24 -> V_90 == NULL ) {
V_94 = F_43 ( V_1 -> V_24 -> V_88 , & V_95 ) ;
if ( V_94 <= 0 ) {
F_4 ( V_96 ,
V_97 ) ;
return 0 ;
}
V_1 -> V_24 -> V_90 = F_3 () ;
if ( V_1 -> V_24 -> V_90 == NULL ) {
F_4 ( V_96 , V_16 ) ;
return 0 ;
}
V_93 = F_44 ( V_1 ) ;
if ( V_93 == NULL || ! F_6 ( V_1 -> V_24 -> V_90 , V_93 , NULL )
|| ! F_8 ( V_1 -> V_24 -> V_90 , V_95 , V_94 ) ) {
F_4 ( V_96 , V_20 ) ;
return 0 ;
}
}
if ( V_92 == 0 ) {
F_39 ( V_1 -> V_24 -> V_88 ) ;
V_1 -> V_24 -> V_88 = NULL ;
}
return 1 ;
}
int F_45 ( T_1 * V_1 , const char * V_98 , int V_91 , unsigned char * V_29 )
{
int V_13 ;
T_2 * V_99 = NULL ;
if ( ! F_42 ( V_1 , 0 ) )
return 0 ;
if ( F_46 ( V_1 -> V_24 -> V_90 ) != V_100 ) {
F_4 ( V_101 , V_102 ) ;
return 0 ;
}
V_99 = F_3 () ;
if ( V_99 == NULL ) {
F_4 ( V_101 , V_16 ) ;
return 0 ;
}
if ( ! F_47 ( V_99 , V_1 -> V_24 -> V_90 ) ) {
F_4 ( V_101 , V_20 ) ;
return 0 ;
}
V_13 = F_48 ( V_99 ) ;
if ( V_13 < 0 ) {
F_49 ( V_99 ) ;
return 0 ;
}
if ( ( V_98 != NULL && F_8 ( V_99 , V_98 , V_91 ) <= 0 )
|| F_50 ( V_99 , V_103 ,
V_1 -> V_21 -> V_23 ,
V_1 -> V_21 -> V_22 ) <= 0
|| F_9 ( V_99 , V_29 , NULL ) <= 0 ) {
F_4 ( V_101 , V_20 ) ;
V_13 = 0 ;
}
F_12 ( V_99 ) ;
return V_13 ;
}
int F_51 ( T_1 * V_1 , unsigned char * V_104 , unsigned char * V_29 ,
int V_91 )
{
static const unsigned char * V_105 [ 3 ] = {
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
unsigned char V_6 [ V_106 ] ;
T_2 * V_99 = F_3 () ;
int V_10 , V_13 = 0 ;
unsigned int V_41 ;
#ifdef F_27
unsigned char * V_107 = V_104 ;
#endif
if ( V_99 == NULL ) {
F_4 ( V_108 , V_16 ) ;
return 0 ;
}
for ( V_10 = 0 ; V_10 < 3 ; V_10 ++ ) {
if ( F_6 ( V_99 , V_1 -> V_99 -> V_109 , NULL ) <= 0
|| F_8 ( V_99 , V_105 [ V_10 ] ,
strlen ( ( const char * ) V_105 [ V_10 ] ) ) <= 0
|| F_8 ( V_99 , V_29 , V_91 ) <= 0
|| F_8 ( V_99 , & ( V_1 -> V_24 -> V_27 [ 0 ] ) ,
V_26 ) <= 0
|| F_8 ( V_99 , & ( V_1 -> V_24 -> V_25 [ 0 ] ) ,
V_26 ) <= 0
|| F_9 ( V_99 , V_6 , & V_41 ) <= 0
|| F_6 ( V_99 , V_1 -> V_99 -> V_110 , NULL ) <= 0
|| F_8 ( V_99 , V_29 , V_91 ) <= 0
|| F_8 ( V_99 , V_6 , V_41 ) <= 0
|| F_9 ( V_99 , V_104 , & V_41 ) <= 0 ) {
F_4 ( V_108 , V_20 ) ;
V_13 = 0 ;
break;
}
V_104 += V_41 ;
V_13 += V_41 ;
}
F_12 ( V_99 ) ;
#ifdef F_27
if ( V_13 > 0 && V_1 -> V_67 ) {
V_1 -> V_67 ( 2 , V_1 -> V_71 , V_111 ,
V_29 , V_91 , V_1 , V_1 -> V_73 ) ;
V_1 -> V_67 ( 2 , V_1 -> V_71 , V_112 ,
V_1 -> V_24 -> V_27 , V_26 ,
V_1 , V_1 -> V_73 ) ;
V_1 -> V_67 ( 2 , V_1 -> V_71 , V_113 ,
V_1 -> V_24 -> V_25 , V_26 ,
V_1 , V_1 -> V_73 ) ;
V_1 -> V_67 ( 2 , V_1 -> V_71 , V_114 ,
V_107 , V_115 ,
V_1 , V_1 -> V_73 ) ;
}
#endif
F_11 ( V_6 , sizeof( V_6 ) ) ;
return ( V_13 ) ;
}
int F_52 ( int V_116 )
{
switch ( V_116 ) {
case V_117 :
return ( V_118 ) ;
case V_119 :
return ( V_120 ) ;
case V_121 :
return ( V_122 ) ;
case V_123 :
return ( V_122 ) ;
case V_124 :
return ( V_122 ) ;
case V_125 :
return ( V_126 ) ;
case V_127 :
return ( V_128 ) ;
case V_129 :
return ( V_130 ) ;
case V_131 :
return ( V_132 ) ;
case V_133 :
return ( V_134 ) ;
case V_135 :
return ( V_136 ) ;
case V_137 :
return ( V_138 ) ;
case V_139 :
return ( V_140 ) ;
case V_141 :
return ( V_142 ) ;
case V_143 :
return ( V_132 ) ;
case V_144 :
return ( V_128 ) ;
case V_145 :
return ( V_128 ) ;
case V_146 :
return ( V_128 ) ;
case V_147 :
return ( V_128 ) ;
case V_148 :
return ( V_128 ) ;
case V_149 :
return ( V_128 ) ;
case V_150 :
return ( V_128 ) ;
case V_151 :
return ( V_128 ) ;
case V_152 :
return ( - 1 ) ;
case V_153 :
return ( V_128 ) ;
case V_154 :
return ( V_128 ) ;
case V_155 :
return ( V_128 ) ;
case V_156 :
return ( V_128 ) ;
case V_157 :
return ( V_128 ) ;
case V_158 :
return ( V_159 ) ;
case V_160 :
return ( V_161 ) ;
case V_162 :
return ( V_163 ) ;
default:
return ( - 1 ) ;
}
}

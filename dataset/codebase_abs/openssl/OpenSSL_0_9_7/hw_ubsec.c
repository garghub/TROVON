static int F_1 ( T_1 * V_1 )
{
#ifndef F_2
const T_2 * V_2 ;
#endif
#ifndef F_3
#ifndef F_4
const T_3 * V_3 ;
#endif
#endif
if( ! F_5 ( V_1 , V_4 ) ||
! F_6 ( V_1 , V_5 ) ||
#ifndef F_2
! F_7 ( V_1 , & V_6 ) ||
#endif
#ifndef F_8
! F_9 ( V_1 , & V_7 ) ||
#endif
#ifndef F_3
! F_10 ( V_1 , & V_8 ) ||
#endif
! F_11 ( V_1 , V_9 ) ||
! F_12 ( V_1 , V_10 ) ||
! F_13 ( V_1 , V_11 ) ||
! F_14 ( V_1 , V_12 ) ||
! F_15 ( V_1 , V_13 ) )
return 0 ;
#ifndef F_2
V_2 = F_16 () ;
V_6 . V_14 = V_2 -> V_14 ;
V_6 . V_15 = V_2 -> V_15 ;
V_6 . V_16 = V_2 -> V_16 ;
V_6 . V_17 = V_2 -> V_17 ;
#endif
#ifndef F_3
#ifndef F_4
V_3 = F_17 () ;
V_8 . V_18 = V_3 -> V_18 ;
V_8 . V_19 = V_3 -> V_19 ;
#endif
#endif
F_18 () ;
return 1 ;
}
static T_1 * F_19 ( void )
{
T_1 * V_20 = F_20 () ;
if( ! V_20 )
return NULL ;
if( ! F_1 ( V_20 ) )
{
F_21 ( V_20 ) ;
return NULL ;
}
return V_20 ;
}
void F_22 ( void )
{
T_1 * V_21 = F_19 () ;
if( ! V_21 ) return;
F_23 ( V_21 ) ;
F_21 ( V_21 ) ;
F_24 () ;
}
static const char * F_25 ( void )
{
if( V_22 )
return V_22 ;
return L_1 ;
}
static void F_26 ( void )
{
if( V_22 )
F_27 ( ( void * ) V_22 ) ;
V_22 = NULL ;
}
static long F_28 ( const char * V_23 )
{
F_26 () ;
return ( ( ( V_22 = F_29 ( V_23 ) ) != NULL ) ? 1 : 0 ) ;
}
static int V_9 ( T_1 * V_1 )
{
F_26 () ;
F_30 () ;
return 1 ;
}
static int V_10 ( T_1 * V_1 )
{
T_4 * V_24 ;
T_5 * V_25 ;
T_6 * V_26 ;
T_7 * V_27 ;
#ifndef F_3
T_8 * V_28 ;
T_9 * V_29 ;
#endif
T_10 * V_30 ;
T_11 * V_31 ;
#ifndef F_8
T_12 * V_32 ;
T_13 * V_33 ;
#endif
T_14 * V_34 ;
T_15 * V_35 ;
T_16 * V_36 ;
int V_37 = 0 ;
if( V_38 != NULL )
{
F_31 ( V_39 , V_40 ) ;
goto V_41;
}
V_38 = F_32 ( NULL , F_25 () , NULL , 0 ) ;
if( V_38 == NULL )
{
F_31 ( V_39 , V_42 ) ;
goto V_41;
}
if (
! ( V_24 = ( T_4 * ) F_33 ( V_38 , V_43 ) ) ||
! ( V_25 = ( T_5 * ) F_33 ( V_38 , V_44 ) ) ||
! ( V_26 = ( T_6 * ) F_33 ( V_38 , V_45 ) ) ||
! ( V_27 = ( T_7 * ) F_33 ( V_38 , V_46 ) ) ||
#ifndef F_3
! ( V_28 = ( T_8 * )
F_33 ( V_38 , V_47 ) ) ||
! ( V_29 = ( T_9 * )
F_33 ( V_38 , V_48 ) ) ||
#endif
! ( V_30 = ( T_10 * ) F_33 ( V_38 , V_49 ) ) ||
! ( V_31 = ( T_11 * ) F_33 ( V_38 , V_50 ) ) ||
#ifndef F_8
! ( V_32 = ( T_12 * ) F_33 ( V_38 , V_51 ) ) ||
! ( V_33 = ( T_13 * ) F_33 ( V_38 , V_52 ) ) ||
#endif
! ( V_34 = ( T_14 * )
F_33 ( V_38 , V_53 ) ) ||
! ( V_35 = ( T_15 * ) F_33 ( V_38 , V_54 ) ) ||
! ( V_36 = ( T_16 * ) F_33 ( V_38 , V_55 ) ) )
{
F_31 ( V_39 , V_42 ) ;
goto V_41;
}
V_56 = V_24 ;
V_57 = V_25 ;
V_58 = V_26 ;
V_59 = V_27 ;
#ifndef F_3
V_60 = V_28 ;
V_61 = V_29 ;
#endif
#ifndef F_2
V_62 = V_30 ;
V_63 = V_31 ;
#endif
#ifndef F_8
V_64 = V_32 ;
V_65 = V_33 ;
#endif
V_66 = V_34 ;
V_67 = V_35 ;
V_68 = V_36 ;
if ( ( ( V_37 = V_58 ( V_69 ) ) > 0 ) && ( V_68 ( V_37 , & V_70 ) == 0 ) )
{
V_59 ( V_37 ) ;
return 1 ;
}
else
{
F_31 ( V_39 , V_71 ) ;
}
V_41:
if( V_38 )
F_34 ( V_38 ) ;
V_56 = NULL ;
V_57 = NULL ;
V_58 = NULL ;
V_59 = NULL ;
#ifndef F_3
V_60 = NULL ;
V_61 = NULL ;
#endif
#ifndef F_2
V_62 = NULL ;
V_63 = NULL ;
#endif
#ifndef F_8
V_64 = NULL ;
V_65 = NULL ;
#endif
V_66 = NULL ;
V_67 = NULL ;
V_68 = NULL ;
return 0 ;
}
static int V_11 ( T_1 * V_1 )
{
F_26 () ;
if( V_38 == NULL )
{
F_31 ( V_72 , V_73 ) ;
return 0 ;
}
if( ! F_34 ( V_38 ) )
{
F_31 ( V_72 , V_42 ) ;
return 0 ;
}
V_38 = NULL ;
V_56 = NULL ;
V_57 = NULL ;
V_58 = NULL ;
V_59 = NULL ;
#ifndef F_3
V_60 = NULL ;
V_61 = NULL ;
#endif
#ifndef F_2
V_62 = NULL ;
V_63 = NULL ;
#endif
#ifndef F_8
V_64 = NULL ;
V_65 = NULL ;
#endif
V_66 = NULL ;
V_67 = NULL ;
V_68 = NULL ;
return 1 ;
}
static int V_12 ( T_1 * V_1 , int V_74 , long V_75 , void * V_76 , void (* F_35)() )
{
int V_77 = ( ( V_38 == NULL ) ? 0 : 1 ) ;
switch( V_74 )
{
case V_78 :
if( V_76 == NULL )
{
F_31 ( V_79 , V_80 ) ;
return 0 ;
}
if( V_77 )
{
F_31 ( V_79 , V_40 ) ;
return 0 ;
}
return F_28 ( ( const char * ) V_76 ) ;
default:
break;
}
F_31 ( V_79 , V_81 ) ;
return 0 ;
}
static int F_36 ( T_17 * V_82 , const T_17 * V_83 , const T_17 * V_76 ,
const T_17 * V_84 , T_18 * V_85 )
{
int V_86 = 0 ;
int V_37 ;
if( V_38 == NULL )
{
F_31 ( V_87 , V_73 ) ;
return 0 ;
}
V_86 = F_37 ( V_84 ) ;
if ( V_86 > V_70 ) {
F_31 ( V_87 , V_88 ) ;
return F_38 ( V_82 , V_83 , V_76 , V_84 , V_85 ) ;
}
if( ! F_39 ( V_82 , V_84 -> V_89 ) )
{
F_31 ( V_87 , V_90 ) ;
return 0 ;
}
memset ( V_82 -> V_91 , 0 , F_40 ( V_84 ) ) ;
if ( ( V_37 = V_58 ( V_69 ) ) <= 0 ) {
V_37 = 0 ;
F_31 ( V_39 , V_71 ) ;
return F_38 ( V_82 , V_83 , V_76 , V_84 , V_85 ) ;
}
if ( V_62 ( V_37 , ( unsigned char * ) V_83 -> V_91 , F_37 ( V_83 ) ,
( unsigned char * ) V_84 -> V_91 , F_37 ( V_84 ) , ( unsigned char * ) V_76 -> V_91 ,
F_37 ( V_76 ) , ( unsigned char * ) V_82 -> V_91 , & V_86 ) != 0 )
{
F_31 ( V_87 , V_92 ) ;
V_59 ( V_37 ) ;
return F_38 ( V_82 , V_83 , V_76 , V_84 , V_85 ) ;
}
V_59 ( V_37 ) ;
V_82 -> V_89 = ( F_37 ( V_84 ) + V_93 - 1 ) / V_93 ;
return 1 ;
}
static int F_41 ( T_17 * V_94 , const T_17 * V_95 , T_19 * V_96 )
{
T_18 * V_85 ;
int V_97 = 0 ;
if( ( V_85 = F_42 () ) == NULL )
goto V_41;
if( ! V_96 -> V_76 || ! V_96 -> V_98 || ! V_96 -> V_99 || ! V_96 -> V_100 || ! V_96 -> V_101 )
{
F_31 ( V_102 , V_103 ) ;
goto V_41;
}
V_97 = F_43 ( V_94 , V_95 , V_96 -> V_76 , V_96 -> V_98 , V_96 -> V_99 ,
V_96 -> V_100 , V_96 -> V_101 , V_85 ) ;
if ( V_97 == V_104 )
{
const T_2 * V_105 = F_16 () ;
V_97 = (* V_105 -> V_106 )( V_94 , V_95 , V_96 ) ;
}
V_41:
if( V_85 )
F_44 ( V_85 ) ;
return V_97 ;
}
static int F_43 ( T_17 * V_82 , const T_17 * V_83 , const T_17 * V_76 ,
const T_17 * V_98 , const T_17 * V_107 ,
const T_17 * V_108 , const T_17 * V_109 , T_18 * V_85 )
{
int V_86 ,
V_110 ,
V_37 ;
V_110 = F_40 ( V_76 ) + F_40 ( V_98 ) + 1 ;
V_86 = F_37 ( V_76 ) + F_37 ( V_98 ) ;
if ( V_86 > V_70 ) {
F_31 ( V_87 , V_88 ) ;
return V_104 ;
}
if ( ! F_39 ( V_82 , V_76 -> V_89 + V_98 -> V_89 + 1 ) ) {
F_31 ( V_111 , V_90 ) ;
return 0 ;
}
if ( ( V_37 = V_58 ( V_69 ) ) <= 0 ) {
V_37 = 0 ;
F_31 ( V_39 , V_71 ) ;
return V_104 ;
}
if ( V_63 ( V_37 ,
( unsigned char * ) V_83 -> V_91 , F_37 ( V_83 ) ,
( unsigned char * ) V_109 -> V_91 , F_37 ( V_109 ) ,
( unsigned char * ) V_107 -> V_91 , F_37 ( V_107 ) ,
( unsigned char * ) V_76 -> V_91 , F_37 ( V_76 ) ,
( unsigned char * ) V_108 -> V_91 , F_37 ( V_108 ) ,
( unsigned char * ) V_98 -> V_91 , F_37 ( V_98 ) ,
( unsigned char * ) V_82 -> V_91 , & V_86 ) != 0 ) {
F_31 ( V_87 , V_92 ) ;
V_59 ( V_37 ) ;
return V_104 ;
}
V_59 ( V_37 ) ;
V_82 -> V_89 = ( F_37 ( V_76 ) + F_37 ( V_98 ) + V_93 - 1 ) / V_93 ;
return 1 ;
}
static int F_45 ( T_20 * V_112 , T_17 * V_113 , T_17 * V_114 ,
T_17 * V_24 , T_17 * V_115 , T_17 * V_25 , T_17 * V_84 ,
T_18 * V_85 , T_21 * V_116 )
{
T_17 V_117 ;
int V_97 = 0 ;
F_46 ( & V_117 ) ;
if ( ! F_36 ( V_113 , V_114 , V_24 , V_84 , V_85 ) ) goto V_118;
if ( ! F_36 ( & V_117 , V_115 , V_25 , V_84 , V_85 ) ) goto V_118;
if ( ! F_47 ( V_113 , V_113 , & V_117 , V_84 , V_85 ) ) goto V_118;
V_97 = 1 ;
V_118:
F_48 ( & V_117 ) ;
return V_97 ;
}
static int F_49 ( T_20 * V_112 , T_17 * V_82 , T_17 * V_83 ,
const T_17 * V_76 , const T_17 * V_84 , T_18 * V_85 ,
T_21 * V_119 )
{
return F_36 ( V_82 , V_83 , V_76 , V_84 , V_85 ) ;
}
static int F_50 ( T_17 * V_82 , const T_17 * V_83 , const T_17 * V_76 ,
const T_17 * V_84 , T_18 * V_85 , T_21 * V_119 )
{
int V_20 = 0 ;
#ifndef F_2
if ( F_37 ( V_84 ) > V_70 )
{
const T_2 * V_105 = F_16 () ;
V_20 = (* V_105 -> V_120 )( V_82 , V_83 , V_76 , V_84 , V_85 , V_119 ) ;
}
else
#endif
{
V_20 = F_36 ( V_82 , V_83 , V_76 , V_84 , V_85 ) ;
}
return V_20 ;
}
static int F_51 ( const T_22 * V_121 , T_17 * V_82 , const T_17 * V_83 ,
const T_17 * V_76 , const T_17 * V_84 , T_18 * V_85 ,
T_21 * V_119 )
{
return F_36 ( V_82 , V_83 , V_76 , V_84 , V_85 ) ;
}
static T_23 * F_52 ( const unsigned char * V_122 , int V_123 , T_20 * V_112 )
{
T_23 * V_97 = NULL ;
int V_124 = 160 , V_125 = 160 , V_126 , V_37 ;
T_17 V_84 , * V_82 = NULL , * V_127 = NULL ;
F_46 ( & V_84 ) ;
V_127 = F_53 () ;
V_82 = F_53 () ;
if ( ( V_127 == NULL ) || ( V_82 == NULL ) )
goto V_41;
V_126 = V_56 ( ( unsigned char * ) V_122 , V_123 ) ;
if( ! F_39 ( V_82 , ( 160 + V_93 - 1 ) / V_93 ) ||
( ! F_39 ( V_127 , ( 160 + V_93 - 1 ) / V_93 ) ) ) {
F_31 ( V_128 , V_90 ) ;
goto V_41;
}
if ( F_54 ( V_122 , V_123 , & V_84 ) == NULL ) {
F_31 ( V_128 , V_90 ) ;
goto V_41;
}
if ( ( V_37 = V_58 ( V_69 ) ) <= 0 ) {
const T_24 * V_105 ;
V_37 = 0 ;
F_31 ( V_39 , V_71 ) ;
V_105 = F_55 () ;
V_97 = V_105 -> V_129 ( V_122 , V_123 , V_112 ) ;
goto V_41;
}
if ( V_64 ( V_37 , 0 ,
( unsigned char * ) V_122 , V_126 ,
NULL , 0 ,
( unsigned char * ) V_112 -> V_76 -> V_91 , F_37 ( V_112 -> V_76 ) ,
( unsigned char * ) V_112 -> V_98 -> V_91 , F_37 ( V_112 -> V_98 ) ,
( unsigned char * ) V_112 -> V_130 -> V_91 , F_37 ( V_112 -> V_130 ) ,
( unsigned char * ) V_112 -> V_131 -> V_91 , F_37 ( V_112 -> V_131 ) ,
( unsigned char * ) V_82 -> V_91 , & V_125 ,
( unsigned char * ) V_127 -> V_91 , & V_124 ) != 0 ) {
const T_24 * V_105 ;
F_31 ( V_128 , V_92 ) ;
V_59 ( V_37 ) ;
V_105 = F_55 () ;
V_97 = V_105 -> V_129 ( V_122 , V_123 , V_112 ) ;
goto V_41;
}
V_59 ( V_37 ) ;
V_82 -> V_89 = ( 160 + V_93 - 1 ) / V_93 ;
V_127 -> V_89 = ( 160 + V_93 - 1 ) / V_93 ;
V_97 = F_56 () ;
if( V_97 == NULL ) {
F_31 ( V_128 , V_90 ) ;
goto V_41;
}
V_97 -> V_82 = V_82 ;
V_97 -> V_127 = V_127 ;
V_41:
if ( ! V_97 ) {
if ( V_82 ) F_48 ( V_82 ) ;
if ( V_127 ) F_48 ( V_127 ) ;
}
F_57 ( & V_84 ) ;
return V_97 ;
}
static int F_58 ( const unsigned char * V_122 , int V_132 ,
T_23 * V_133 , T_20 * V_112 )
{
int V_134 , V_126 ;
int V_97 = 0 ;
int V_37 ;
T_17 V_135 ;
F_46 ( & V_135 ) ;
if( ! F_39 ( & V_135 , V_112 -> V_76 -> V_89 ) ) {
F_31 ( V_136 , V_90 ) ;
goto V_41;
}
V_134 = F_37 ( V_112 -> V_76 ) ;
V_126 = V_56 ( ( unsigned char * ) V_122 , V_132 ) ;
if ( ( V_37 = V_58 ( V_69 ) ) <= 0 ) {
const T_24 * V_105 ;
V_37 = 0 ;
F_31 ( V_39 , V_71 ) ;
V_105 = F_55 () ;
V_97 = V_105 -> V_137 ( V_122 , V_132 , V_133 , V_112 ) ;
goto V_41;
}
if ( V_65 ( V_37 , 0 ,
( unsigned char * ) V_122 , V_126 ,
( unsigned char * ) V_112 -> V_76 -> V_91 , F_37 ( V_112 -> V_76 ) ,
( unsigned char * ) V_112 -> V_98 -> V_91 , F_37 ( V_112 -> V_98 ) ,
( unsigned char * ) V_112 -> V_130 -> V_91 , F_37 ( V_112 -> V_130 ) ,
( unsigned char * ) V_112 -> V_138 -> V_91 , F_37 ( V_112 -> V_138 ) ,
( unsigned char * ) V_133 -> V_82 -> V_91 , F_37 ( V_133 -> V_82 ) ,
( unsigned char * ) V_133 -> V_127 -> V_91 , F_37 ( V_133 -> V_127 ) ,
( unsigned char * ) V_135 . V_91 , & V_134 ) != 0 ) {
const T_24 * V_105 ;
F_31 ( V_136 , V_92 ) ;
V_59 ( V_37 ) ;
V_105 = F_55 () ;
V_97 = V_105 -> V_137 ( V_122 , V_132 , V_133 , V_112 ) ;
goto V_41;
}
V_59 ( V_37 ) ;
V_97 = 1 ;
V_41:
F_57 ( & V_135 ) ;
return V_97 ;
}
static int F_59 ( unsigned char * V_139 , const T_17 * V_138 , T_22 * V_121 )
{
int V_20 = - 1 ,
V_140 ,
V_37 ;
V_140 = F_37 ( V_121 -> V_76 ) ;
if ( ( V_37 = V_58 ( V_69 ) ) <= 0 )
{
const T_3 * V_105 ;
F_60 ( V_39 , V_71 ) ;
V_105 = F_17 () ;
V_20 = V_105 -> V_19 ( V_139 , V_138 , V_121 ) ;
goto V_41;
}
if ( V_61 ( V_37 ,
( unsigned char * ) V_121 -> V_131 -> V_91 , F_37 ( V_121 -> V_131 ) ,
( unsigned char * ) V_138 -> V_91 , F_37 ( V_138 ) ,
( unsigned char * ) V_121 -> V_76 -> V_91 , F_37 ( V_121 -> V_76 ) ,
V_139 , & V_140 ) != 0 )
{
const T_3 * V_105 ;
F_60 ( V_141 , V_92 ) ;
V_59 ( V_37 ) ;
V_105 = F_17 () ;
V_20 = V_105 -> V_19 ( V_139 , V_138 , V_121 ) ;
goto V_41;
}
V_59 ( V_37 ) ;
V_20 = V_57 ( V_140 ) ;
V_41:
return V_20 ;
}
static int F_61 ( T_22 * V_121 )
{
int V_20 = 0 ,
V_142 = 0 ,
V_143 = 0 ,
V_144 = 0 ,
V_37 ;
T_17 * V_138 = NULL ;
T_17 * V_131 = NULL ;
if ( V_121 -> V_131 == NULL )
{
V_131 = F_53 () ;
if ( V_131 == NULL ) goto V_41;
V_144 = F_37 ( V_121 -> V_76 ) ;
F_39 ( V_131 , V_121 -> V_76 -> V_89 ) ;
do
if ( ! F_62 ( V_131 , V_121 -> V_76 ) ) goto V_41;
while ( F_63 ( V_131 ) );
V_142 = F_37 ( V_131 ) ;
}
else
{
V_131 = V_121 -> V_131 ;
}
if ( V_121 -> V_138 == NULL )
{
V_138 = F_53 () ;
V_143 = F_37 ( V_121 -> V_76 ) ;
F_39 ( V_138 , V_121 -> V_76 -> V_89 ) ;
if( V_138 == NULL ) goto V_41;
}
else
{
V_138 = V_121 -> V_138 ;
}
if ( ( V_37 = V_58 ( V_69 ) ) <= 0 )
{
const T_3 * V_105 ;
F_60 ( V_39 , V_71 ) ;
V_105 = F_17 () ;
V_20 = V_105 -> V_18 ( V_121 ) ;
goto V_41;
}
if ( V_60 ( V_37 ,
( unsigned char * ) V_131 -> V_91 , & V_144 ,
( unsigned char * ) V_138 -> V_91 , & V_143 ,
( unsigned char * ) V_121 -> V_130 -> V_91 , F_37 ( V_121 -> V_130 ) ,
( unsigned char * ) V_121 -> V_76 -> V_91 , F_37 ( V_121 -> V_76 ) ,
0 , 0 , V_142 ) != 0 )
{
const T_3 * V_105 ;
F_60 ( V_141 , V_92 ) ;
V_59 ( V_37 ) ;
V_105 = F_17 () ;
V_20 = V_105 -> V_18 ( V_121 ) ;
goto V_41;
}
V_59 ( V_37 ) ;
V_121 -> V_138 = V_138 ;
V_121 -> V_138 -> V_89 = ( V_143 + V_93 - 1 ) / V_93 ;
V_121 -> V_131 = V_131 ;
V_121 -> V_131 -> V_89 = ( V_144 + V_93 - 1 ) / V_93 ;
V_20 = 1 ;
V_41:
return V_20 ;
}
static int F_64 ( unsigned char * V_145 ,
int V_146 )
{
int V_20 = 0 ,
V_37 ;
if ( ( V_37 = V_58 ( V_69 ) ) <= 0 )
{
const T_25 * V_105 ;
F_60 ( V_39 , V_71 ) ;
V_146 = V_57 ( V_146 ) ;
V_105 = F_65 () ;
V_105 -> V_147 ( V_145 , V_146 ) ;
V_20 = V_105 -> V_148 ( V_145 , V_146 ) ;
goto V_41;
}
V_146 *= 8 ;
if ( V_67 ( V_37 ,
V_149 ,
V_145 ,
& V_146 ) != 0 )
{
const T_25 * V_105 ;
F_60 ( V_150 , V_92 ) ;
V_59 ( V_37 ) ;
V_146 = V_57 ( V_146 ) ;
V_105 = F_65 () ;
V_105 -> V_147 ( V_145 , V_146 ) ;
V_20 = V_105 -> V_148 ( V_145 , V_146 ) ;
goto V_41;
}
V_59 ( V_37 ) ;
V_20 = 1 ;
V_41:
return ( V_20 ) ;
}
static int F_66 ( void )
{
return 0 ;
}
static int F_67 ( T_1 * V_1 , const char * V_151 )
{
if( V_151 && ( strcmp ( V_151 , V_4 ) != 0 ) )
return 0 ;
if( ! F_1 ( V_1 ) )
return 0 ;
return 1 ;
}

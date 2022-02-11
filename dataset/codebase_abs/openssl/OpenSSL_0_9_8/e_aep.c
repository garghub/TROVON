static int F_1 ( T_1 * V_1 )
{
#ifndef F_2
const T_2 * V_2 ;
#endif
#ifndef F_3
const T_3 * V_3 ;
#endif
#ifndef F_4
const T_4 * V_4 ;
#endif
if( ! F_5 ( V_1 , V_5 ) ||
! F_6 ( V_1 , V_6 ) ||
#ifndef F_2
! F_7 ( V_1 , & V_7 ) ||
#endif
#ifndef F_3
! F_8 ( V_1 , & V_8 ) ||
#endif
#ifndef F_4
! F_9 ( V_1 , & V_9 ) ||
#endif
#ifdef F_10
! F_11 ( V_1 , & V_10 ) ||
#endif
! F_12 ( V_1 , V_11 ) ||
! F_13 ( V_1 , V_12 ) ||
! F_14 ( V_1 , V_13 ) ||
! F_15 ( V_1 , V_14 ) ||
! F_16 ( V_1 , V_15 ) )
return 0 ;
#ifndef F_2
V_2 = F_17 () ;
V_7 . V_16 = V_2 -> V_16 ;
V_7 . V_17 = V_2 -> V_17 ;
V_7 . V_18 = V_2 -> V_18 ;
V_7 . V_19 = V_2 -> V_19 ;
#endif
#ifndef F_3
V_3 = F_18 () ;
V_8 . V_20 = V_3 -> V_20 ;
V_8 . V_21 = V_3 -> V_21 ;
V_8 . V_22 = V_3 -> V_22 ;
V_8 = * F_19 () ;
V_8 . V_23 = V_24 ;
V_8 . V_25 = V_26 ;
#endif
#ifndef F_4
V_4 = F_20 () ;
V_9 . V_27 = V_4 -> V_27 ;
V_9 . V_28 = V_4 -> V_28 ;
V_9 . V_25 = V_4 -> V_25 ;
#endif
F_21 () ;
return 1 ;
}
static int F_22 ( T_1 * V_1 , const char * V_29 )
{
if( V_29 && ( strcmp ( V_29 , V_5 ) != 0 ) )
return 0 ;
if( ! F_1 ( V_1 ) )
return 0 ;
return 1 ;
}
static T_1 * F_23 ( void )
{
T_1 * V_30 = F_24 () ;
if( ! V_30 )
return NULL ;
if( ! F_1 ( V_30 ) )
{
F_25 ( V_30 ) ;
return NULL ;
}
return V_30 ;
}
void F_26 ( void )
{
T_1 * V_31 = F_23 () ;
if( ! V_31 ) return;
F_27 ( V_31 ) ;
F_25 ( V_31 ) ;
F_28 () ;
}
static const char * F_29 ( void )
{
if( V_32 )
return V_32 ;
return L_1 ;
}
static void F_30 ( void )
{
if( V_32 )
F_31 ( ( void * ) V_32 ) ;
V_32 = NULL ;
}
static long F_32 ( const char * V_33 )
{
F_30 () ;
return ( ( V_32 = F_33 ( V_33 ) ) != NULL ? 1 : 0 ) ;
}
static int V_11 ( T_1 * V_1 )
{
T_5 * V_34 ;
T_6 * V_35 ;
#ifdef F_10
T_7 * V_36 ;
#endif
T_8 * V_37 ;
T_9 * V_38 ;
T_10 * V_39 ;
T_11 * V_40 ;
T_12 * V_41 ;
int V_42 = 0 ;
if( V_43 != NULL )
{
F_34 ( V_44 , V_45 ) ;
goto V_46;
}
V_43 = F_35 ( NULL , F_29 () , NULL , 0 ) ;
if( V_43 == NULL )
{
F_34 ( V_44 , V_47 ) ;
goto V_46;
}
if( ! ( V_34 = ( T_5 * ) F_36 ( V_43 , V_48 ) ) ||
! ( V_35 = ( T_6 * ) F_36 ( V_43 , V_49 ) ) ||
#ifdef F_10
! ( V_36 = ( T_7 * ) F_36 ( V_43 , V_50 ) ) ||
#endif
! ( V_37 = ( T_8 * ) F_36 ( V_43 , V_51 ) ) ||
! ( V_38 = ( T_9 * ) F_36 ( V_43 , V_52 ) ) ||
! ( V_39 = ( T_10 * ) F_36 ( V_43 , V_53 ) ) ||
! ( V_40 = ( T_11 * ) F_36 ( V_43 , V_54 ) ) ||
! ( V_41 = ( T_12 * ) F_36 ( V_43 , V_55 ) ) )
{
F_34 ( V_44 , V_47 ) ;
goto V_46;
}
V_56 = V_34 ;
V_57 = V_35 ;
#ifdef F_10
V_58 = V_36 ;
#endif
V_59 = V_37 ;
V_60 = V_38 ;
V_61 = V_39 ;
V_62 = V_40 ;
V_63 = V_41 ;
V_42 = 1 ;
return V_42 ;
V_46:
if( V_43 )
F_37 ( V_43 ) ;
V_43 = NULL ;
V_61 = NULL ;
V_56 = NULL ;
V_57 = NULL ;
#ifdef F_10
V_58 = NULL ;
#endif
V_60 = NULL ;
V_59 = NULL ;
V_62 = NULL ;
V_63 = NULL ;
return V_42 ;
}
static int V_12 ( T_1 * V_1 )
{
F_30 () ;
F_38 () ;
return 1 ;
}
static int V_13 ( T_1 * V_1 )
{
int V_42 = 0 , V_64 ;
T_13 V_65 ;
if( V_43 == NULL )
{
F_34 ( V_66 , V_47 ) ;
goto V_46;
}
V_65 = F_39 ( 0 , & V_64 ) ;
if ( V_65 != V_67 )
{
F_34 ( V_66 , V_68 ) ;
goto V_46;
}
if ( V_64 )
{
F_34 ( V_66 , V_69 ) ;
goto V_46;
}
V_65 = V_59 () ;
if ( V_65 != V_67 )
{
F_34 ( V_66 , V_70 ) ;
goto V_46;
}
if( ! F_37 ( V_43 ) )
{
F_34 ( V_66 , V_71 ) ;
goto V_46;
}
V_43 = NULL ;
V_63 = NULL ;
V_61 = NULL ;
V_56 = NULL ;
V_57 = NULL ;
#ifdef F_10
V_58 = NULL ;
#endif
V_60 = NULL ;
V_59 = NULL ;
V_62 = NULL ;
V_42 = 1 ;
V_46:
return V_42 ;
}
static int V_14 ( T_1 * V_1 , int V_72 , long V_73 , void * V_74 , void (* F_40)( void ) )
{
int V_75 = ( ( V_43 == NULL ) ? 0 : 1 ) ;
switch( V_72 )
{
case V_76 :
if( V_74 == NULL )
{
F_34 ( V_77 ,
V_78 ) ;
return 0 ;
}
if( V_75 )
{
F_34 ( V_77 ,
V_45 ) ;
return 0 ;
}
return F_32 ( ( const char * ) V_74 ) ;
default:
break;
}
F_34 ( V_77 , V_79 ) ;
return 0 ;
}
static int F_41 ( T_14 * V_80 , const T_14 * V_81 , const T_14 * V_74 ,
const T_14 * V_82 , T_15 * V_83 )
{
int V_42 = 0 ;
int V_84 = 0 ;
T_16 V_85 ;
T_13 V_65 ;
V_84 = F_42 ( V_82 ) ;
if ( V_84 > V_86 ) {
F_34 ( V_87 , V_88 ) ;
return F_43 ( V_80 , V_81 , V_74 , V_82 , V_83 ) ;
}
V_65 = F_44 ( & V_85 ) ;
if ( V_65 != V_67 )
{
F_34 ( V_87 , V_89 ) ;
return F_43 ( V_80 , V_81 , V_74 , V_82 , V_83 ) ;
}
V_65 = V_56 ( V_85 , ( void * ) V_81 , ( void * ) V_74 , ( void * ) V_82 , ( void * ) V_80 , NULL ) ;
if ( V_65 != V_67 )
{
F_34 ( V_87 , V_90 ) ;
V_65 = F_45 ( V_85 ) ;
return F_43 ( V_80 , V_81 , V_74 , V_82 , V_83 ) ;
}
V_65 = F_46 ( V_85 ) ;
if ( V_65 != V_67 )
{
F_34 ( V_87 , V_91 ) ;
goto V_46;
}
V_42 = 1 ;
V_46:
return V_42 ;
}
static T_13 F_47 ( T_14 * V_80 , const T_14 * V_81 , const T_14 * V_74 ,
const T_14 * V_92 , const T_14 * V_93 ,
const T_14 * V_94 , const T_14 * V_95 , T_15 * V_83 )
{
T_13 V_65 = V_67 ;
T_16 V_85 ;
V_65 = F_44 ( & V_85 ) ;
if ( V_65 != V_67 )
{
F_34 ( V_96 , V_89 ) ;
return V_97 ;
}
V_65 = V_57 ( V_85 , ( void * ) V_81 , ( void * ) V_74 , ( void * ) V_92 , ( void * ) V_93 , ( void * ) V_94 ,
( void * ) V_95 , ( void * ) V_80 , NULL ) ;
if ( V_65 != V_67 )
{
F_34 ( V_96 , V_98 ) ;
V_65 = F_45 ( V_85 ) ;
return V_97 ;
}
V_65 = F_46 ( V_85 ) ;
if ( V_65 != V_67 )
{
F_34 ( V_96 , V_91 ) ;
goto V_46;
}
V_46:
return V_65 ;
}
static int F_48 ( unsigned char * V_99 , int V_100 )
{
T_13 V_65 = V_67 ;
T_16 V_85 ;
F_49 ( V_101 ) ;
if ( V_100 <= V_102 )
{
memcpy ( V_99 , & V_103 [ V_104 - V_102 ] , V_100 ) ;
V_102 -= V_100 ;
F_50 ( V_101 ) ;
}
else
{
F_50 ( V_101 ) ;
V_65 = F_44 ( & V_85 ) ;
if ( V_65 != V_67 )
{
F_34 ( V_105 , V_89 ) ;
goto V_106;
}
if ( V_100 > V_104 )
{
V_65 = V_58 ( V_85 , V_100 , 2 , V_99 , NULL ) ;
if ( V_65 != V_67 )
{
F_34 ( V_105 , V_107 ) ;
goto V_106;
}
}
else
{
F_49 ( V_101 ) ;
V_65 = V_58 ( V_85 , V_104 , 2 , & V_103 [ 0 ] , NULL ) ;
if ( V_65 != V_67 )
{
F_34 ( V_105 , V_107 ) ;
goto V_46;
}
V_102 = V_104 ;
memcpy ( V_99 , & V_103 [ V_104 - V_102 ] , V_100 ) ;
V_102 -= V_100 ;
F_50 ( V_101 ) ;
}
V_65 = F_46 ( V_85 ) ;
if ( V_65 != V_67 )
{
F_34 ( V_105 , V_91 ) ;
goto V_106;
}
}
return 1 ;
V_46:
F_50 ( V_101 ) ;
V_106:
return 0 ;
}
static int F_51 ( void )
{
return 1 ;
}
static int F_52 ( T_14 * V_108 , const T_14 * V_109 , T_17 * V_110 , T_15 * V_83 )
{
int V_42 = 0 ;
T_13 V_65 = V_67 ;
if ( ! V_43 )
{
F_34 ( V_111 , V_47 ) ;
goto V_46;
}
if ( V_110 -> V_92 && V_110 -> V_93 && V_110 -> V_94 && V_110 -> V_95 )
{
V_65 = F_47 ( V_108 , V_109 , V_110 -> V_74 , V_110 -> V_92 , V_110 -> V_93 , V_110 -> V_94 , V_110 -> V_95 , V_83 ) ;
if ( V_65 == V_97 ) {
const T_2 * V_112 = F_17 () ;
V_42 = (* V_112 -> V_113 )( V_108 , V_109 , V_110 , V_83 ) ;
goto V_46;
}
else if ( V_65 != V_67 )
goto V_46;
}
else
{
if ( ! V_110 -> V_114 || ! V_110 -> V_115 )
{
F_34 ( V_111 , V_116 ) ;
goto V_46;
}
V_65 = F_41 ( V_108 , V_109 , V_110 -> V_114 , V_110 -> V_115 , V_83 ) ;
if ( V_65 != V_67 )
goto V_46;
}
V_42 = 1 ;
V_46:
return V_42 ;
}
static int V_24 ( T_18 * V_117 , T_14 * V_118 , T_14 * V_119 ,
T_14 * V_34 , T_14 * V_120 , T_14 * V_35 , T_14 * V_82 ,
T_15 * V_83 , T_19 * V_121 )
{
T_14 V_122 ;
int V_42 = 0 ;
F_53 ( & V_122 ) ;
if ( ! F_41 ( V_118 , V_119 , V_34 , V_82 , V_83 ) ) goto V_123;
if ( ! F_41 ( & V_122 , V_120 , V_35 , V_82 , V_83 ) ) goto V_123;
if ( ! F_54 ( V_118 , V_118 , & V_122 , V_82 , V_83 ) ) goto V_123;
V_42 = 1 ;
V_123:
F_55 ( & V_122 ) ;
return V_42 ;
}
static int V_26 ( T_18 * V_117 , T_14 * V_80 , T_14 * V_81 ,
const T_14 * V_74 , const T_14 * V_82 , T_15 * V_83 ,
T_19 * V_124 )
{
return F_41 ( V_80 , V_81 , V_74 , V_82 , V_83 ) ;
}
static int F_56 ( T_14 * V_80 , const T_14 * V_81 , const T_14 * V_74 ,
const T_14 * V_82 , T_15 * V_83 , T_19 * V_124 )
{
return F_41 ( V_80 , V_81 , V_74 , V_82 , V_83 ) ;
}
static int F_57 ( const T_20 * V_125 , T_14 * V_80 , const T_14 * V_81 ,
const T_14 * V_74 , const T_14 * V_82 , T_15 * V_83 ,
T_19 * V_124 )
{
return F_41 ( V_80 , V_81 , V_74 , V_82 , V_83 ) ;
}
static T_13 F_44 ( T_21 V_126 )
{
int V_127 ;
T_13 V_65 = V_67 ;
T_22 V_128 ;
F_49 ( V_129 ) ;
#ifndef F_58
V_128 = F_59 () ;
#else
V_128 = F_60 () ;
#endif
if ( V_130 != V_128 )
{
V_130 = V_128 ;
V_59 () ;
V_65 = V_60 ( NULL ) ;
if ( V_65 != V_67 )
{
F_34 ( V_131 , V_132 ) ;
V_130 = 0 ;
goto V_123;
}
V_65 = V_62 ( & V_133 , & V_134 ,
& V_135 ) ;
if ( V_65 != V_67 )
{
F_34 ( V_131 , V_136 ) ;
V_130 = 0 ;
goto V_123;
}
#ifdef F_10
V_102 = 0 ;
#endif
for ( V_127 = 0 ; V_127 < V_137 ; V_127 ++ )
{
V_138 [ V_127 ] . V_139 = V_140 ;
V_138 [ V_127 ] . V_141 = 0 ;
}
V_65 = V_61 ( V_126 ) ;
if ( V_65 != V_67 )
{
F_34 ( V_131 , V_71 ) ;
V_130 = 0 ;
goto V_123;
}
V_138 [ 0 ] . V_139 = V_142 ;
V_138 [ 0 ] . V_141 = * V_126 ;
goto V_123;
}
for ( V_127 = 0 ; V_127 < V_137 ; V_127 ++ )
{
if ( V_138 [ V_127 ] . V_139 == V_143 )
{
V_138 [ V_127 ] . V_139 = V_142 ;
* V_126 = V_138 [ V_127 ] . V_141 ;
goto V_123;
}
}
for ( V_127 = 0 ; V_127 < V_137 ; V_127 ++ )
{
if ( V_138 [ V_127 ] . V_139 == V_140 )
{
V_65 = V_61 ( V_126 ) ;
if ( V_65 != V_67 )
{
F_34 ( V_131 , V_71 ) ;
goto V_123;
}
V_138 [ V_127 ] . V_139 = V_142 ;
V_138 [ V_127 ] . V_141 = * V_126 ;
goto V_123;
}
}
V_65 = V_144 ;
V_123:
F_50 ( V_129 ) ;
return V_65 ;
}
static T_13 F_46 ( T_16 V_85 )
{
int V_127 ;
F_49 ( V_129 ) ;
for( V_127 = 0 ; V_127 < V_137 ; V_127 ++ )
{
if ( V_138 [ V_127 ] . V_141 == V_85 )
{
V_138 [ V_127 ] . V_139 = V_143 ;
break;
}
}
F_50 ( V_129 ) ;
return V_67 ;
}
static T_13 F_45 ( T_16 V_85 )
{
int V_127 ;
T_13 V_65 = V_67 ;
F_49 ( V_129 ) ;
for( V_127 = 0 ; V_127 < V_137 ; V_127 ++ )
{
if ( V_138 [ V_127 ] . V_141 == V_85 )
{
V_65 = V_63 ( V_138 [ V_127 ] . V_141 ) ;
if ( V_65 != V_67 )
goto V_123;
V_138 [ V_127 ] . V_139 = V_140 ;
V_138 [ V_127 ] . V_141 = 0 ;
break;
}
}
V_123:
F_50 ( V_129 ) ;
return V_65 ;
}
static T_13 F_39 ( int V_145 , int * V_64 )
{
int V_127 ;
T_13 V_65 = V_67 ;
* V_64 = 0 ;
if ( V_145 ) F_49 ( V_129 ) ;
for ( V_127 = 0 ; V_127 < V_137 ; V_127 ++ )
{
switch ( V_138 [ V_127 ] . V_139 )
{
case V_143 :
V_65 = V_63 ( V_138 [ V_127 ] . V_141 ) ;
if ( V_65 != V_67 )
goto V_123;
V_138 [ V_127 ] . V_139 = V_140 ;
V_138 [ V_127 ] . V_141 = 0 ;
break;
case V_142 :
( * V_64 ) ++ ;
break;
case V_140 :
break;
}
}
V_123:
if ( V_145 ) F_50 ( V_129 ) ;
return V_65 ;
}
static T_13 V_133 ( T_23 V_146 , T_24 * V_147 )
{
T_14 * V_148 ;
V_148 = ( T_14 * ) V_146 ;
#ifdef F_61
* V_147 = V_148 -> V_149 << 3 ;
#else
* V_147 = V_148 -> V_149 << 2 ;
#endif
return V_67 ;
}
static T_13 V_134 ( T_23 V_146 , T_24 V_147 ,
unsigned char * V_150 )
{
T_14 * V_148 ;
#ifndef F_61
unsigned char * V_99 ;
int V_73 ;
#endif
V_148 = ( T_14 * ) V_146 ;
#ifdef F_61
memcpy ( V_150 , V_148 -> V_114 , V_147 ) ;
#else
for( V_73 = 0 ; V_73 < V_148 -> V_149 ; V_73 ++ )
{
V_99 = ( unsigned char * ) & V_148 -> V_114 [ V_73 ] ;
* ( ( T_24 * ) V_150 ) = ( T_24 )
( ( unsigned ) V_99 [ 1 ] << 8 | V_99 [ 0 ] ) |
( ( unsigned ) V_99 [ 3 ] << 8 | V_99 [ 2 ] ) << 16 ;
V_150 += 4 ;
}
#endif
return V_67 ;
}
static T_13 V_135 ( void * V_146 , T_24 V_147 ,
unsigned char * V_150 )
{
T_14 * V_148 ;
#ifndef F_61
int V_73 ;
#endif
V_148 = ( T_14 * ) V_146 ;
F_62 ( V_148 , ( int ) ( V_147 << 3 ) ) ;
#ifdef F_61
V_148 -> V_149 = V_147 >> 3 ;
if( ( V_147 & 7 ) != 0 )
V_148 -> V_149 ++ ;
memset ( V_148 -> V_114 , 0 , V_148 -> V_149 << 3 ) ;
memcpy ( V_148 -> V_114 , V_150 , V_147 ) ;
#else
V_148 -> V_149 = V_147 >> 2 ;
for( V_73 = 0 ; V_73 < V_148 -> V_149 ; V_73 ++ )
{
V_148 -> V_114 [ V_73 ] = ( T_24 )
( ( unsigned ) V_150 [ 3 ] << 8 | V_150 [ 2 ] ) << 16 |
( ( unsigned ) V_150 [ 1 ] << 8 | V_150 [ 0 ] ) ;
V_150 += 4 ;
}
#endif
return V_67 ;
}

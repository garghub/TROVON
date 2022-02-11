void
F_1 ( void )
{
return;
}
static int
F_2 ( void )
{
static int V_1 = - 1 ;
if ( V_1 == - 1 ) {
if ( ( V_1 = F_3 ( L_1 , V_2 , 0 ) ) == - 1 )
return ( - 1 ) ;
if ( F_4 ( V_1 , V_3 , 1 ) == - 1 ) {
F_5 ( V_1 ) ;
V_1 = - 1 ;
return ( - 1 ) ;
}
}
return ( V_1 ) ;
}
static int
F_6 ( void )
{
int V_1 , V_4 ;
if ( ( V_1 = F_2 () ) == - 1 )
return ( - 1 ) ;
#ifndef F_7
if ( F_8 ( V_1 , V_5 , & V_4 ) == - 1 )
return ( - 1 ) ;
if ( F_4 ( V_4 , V_3 , 1 ) == - 1 ) {
F_5 ( V_4 ) ;
return ( - 1 ) ;
}
#else
V_4 = V_1 ;
#endif
return ( V_4 ) ;
}
static void F_9 ( int V_1 )
{
#ifndef F_7
F_5 ( V_1 ) ;
#endif
}
static int
F_10 ( void )
{
static int V_1 = - 1 ;
if ( V_1 == - 1 )
V_1 = F_6 () ;
return V_1 ;
}
static int
F_11 ( const int * * V_6 )
{
static int V_7 [ V_8 ] ;
struct V_9 V_10 ;
int V_1 , V_11 , V_12 = 0 ;
if ( ( V_1 = F_6 () ) < 0 ) {
* V_6 = NULL ;
return ( 0 ) ;
}
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_10 . V_13 = ( V_14 ) L_2 ;
for ( V_11 = 0 ; V_15 [ V_11 ] . V_16 && V_12 < V_8 ; V_11 ++ ) {
if ( V_15 [ V_11 ] . V_17 == V_18 )
continue;
V_10 . V_19 = V_15 [ V_11 ] . V_16 ;
V_10 . V_20 = V_15 [ V_11 ] . V_20 ;
V_10 . V_21 = 0 ;
if ( F_8 ( V_1 , V_22 , & V_10 ) != - 1 &&
F_8 ( V_1 , V_23 , & V_10 . V_24 ) != - 1 )
V_7 [ V_12 ++ ] = V_15 [ V_11 ] . V_17 ;
}
F_9 ( V_1 ) ;
if ( V_12 > 0 )
* V_6 = V_7 ;
else
* V_6 = NULL ;
return ( V_12 ) ;
}
static int
F_12 ( const int * * V_6 )
{
static int V_7 [ V_8 ] ;
struct V_9 V_10 ;
int V_1 , V_11 , V_12 = 0 ;
if ( ( V_1 = F_6 () ) < 0 ) {
* V_6 = NULL ;
return ( 0 ) ;
}
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_10 . V_25 = ( V_14 ) L_2 ;
for ( V_11 = 0 ; V_26 [ V_11 ] . V_16 && V_12 < V_8 ; V_11 ++ ) {
if ( V_26 [ V_11 ] . V_17 == V_18 )
continue;
V_10 . V_21 = V_26 [ V_11 ] . V_16 ;
V_10 . V_27 = V_26 [ V_11 ] . V_20 ;
V_10 . V_19 = 0 ;
if ( F_8 ( V_1 , V_22 , & V_10 ) != - 1 &&
F_8 ( V_1 , V_23 , & V_10 . V_24 ) != - 1 )
V_7 [ V_12 ++ ] = V_26 [ V_11 ] . V_17 ;
}
F_9 ( V_1 ) ;
if ( V_12 > 0 )
* V_6 = V_7 ;
else
* V_6 = NULL ;
return ( V_12 ) ;
}
static int
F_13 ( const int * * V_7 )
{
return ( F_11 ( V_7 ) ) ;
}
static int
F_14 ( const int * * V_7 )
{
#ifdef F_15
return ( F_12 ( V_7 ) ) ;
#else
* V_7 = NULL ;
return ( 0 ) ;
#endif
}
static int
F_16 ( T_1 * V_28 , unsigned char * V_29 ,
const unsigned char * V_30 , T_2 V_31 )
{
struct V_32 V_33 ;
struct V_34 * V_35 = V_28 -> V_36 ;
struct V_9 * V_10 = & V_35 -> V_37 ;
const void * V_38 ;
unsigned char V_39 [ V_40 ] ;
if ( V_35 -> V_41 < 0 )
return ( 0 ) ;
if ( ! V_31 )
return ( 1 ) ;
if ( ( V_31 % V_28 -> V_19 -> V_42 ) != 0 )
return ( 0 ) ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_24 = V_10 -> V_24 ;
V_33 . V_43 = 0 ;
V_33 . V_44 = V_31 ;
V_33 . V_45 = ( V_14 ) V_30 ;
V_33 . V_46 = ( V_14 ) V_29 ;
V_33 . V_21 = 0 ;
V_33 . V_47 = V_28 -> V_48 ? V_49 : V_50 ;
if ( V_28 -> V_19 -> V_51 ) {
V_33 . V_52 = ( V_14 ) V_28 -> V_52 ;
if ( ! V_28 -> V_48 ) {
V_38 = V_30 + V_31 - V_28 -> V_19 -> V_51 ;
memcpy ( V_39 , V_38 , V_28 -> V_19 -> V_51 ) ;
}
} else
V_33 . V_52 = NULL ;
if ( F_8 ( V_35 -> V_41 , V_53 , & V_33 ) == - 1 ) {
return ( 0 ) ;
}
if ( V_28 -> V_19 -> V_51 ) {
if ( V_28 -> V_48 )
V_38 = V_29 + V_31 - V_28 -> V_19 -> V_51 ;
else
V_38 = V_39 ;
memcpy ( V_28 -> V_52 , V_38 , V_28 -> V_19 -> V_51 ) ;
}
return ( 1 ) ;
}
static int
F_17 ( T_1 * V_28 , const unsigned char * V_13 ,
const unsigned char * V_52 , int V_54 )
{
struct V_34 * V_35 = V_28 -> V_36 ;
struct V_9 * V_10 = & V_35 -> V_37 ;
int V_19 = - 1 , V_11 ;
for ( V_11 = 0 ; V_15 [ V_11 ] . V_16 ; V_11 ++ )
if ( V_28 -> V_19 -> V_17 == V_15 [ V_11 ] . V_17 &&
V_28 -> V_19 -> V_51 <= V_15 [ V_11 ] . V_55 &&
V_28 -> V_56 == V_15 [ V_11 ] . V_20 ) {
V_19 = V_15 [ V_11 ] . V_16 ;
break;
}
if ( ! V_15 [ V_11 ] . V_16 ) {
V_35 -> V_41 = - 1 ;
return ( 0 ) ;
}
memset ( V_10 , 0 , sizeof( struct V_9 ) ) ;
if ( ( V_35 -> V_41 = F_6 () ) < 0 )
return ( 0 ) ;
V_10 -> V_13 = ( V_14 ) V_13 ;
V_10 -> V_20 = V_28 -> V_56 ;
V_10 -> V_19 = V_19 ;
if ( F_8 ( V_35 -> V_41 , V_22 , V_10 ) == - 1 ) {
F_9 ( V_35 -> V_41 ) ;
V_35 -> V_41 = - 1 ;
return ( 0 ) ;
}
return ( 1 ) ;
}
static int
F_18 ( T_1 * V_28 )
{
int V_57 = 0 ;
struct V_34 * V_35 = V_28 -> V_36 ;
struct V_9 * V_10 = & V_35 -> V_37 ;
if ( V_35 -> V_41 < 0 )
return ( 0 ) ;
if ( F_8 ( V_35 -> V_41 , V_23 , & V_10 -> V_24 ) == - 1 ) {
V_57 = 0 ;
} else {
V_57 = 1 ;
}
F_9 ( V_35 -> V_41 ) ;
V_35 -> V_41 = - 1 ;
return ( V_57 ) ;
}
static int
F_19 ( T_3 * V_58 , const T_4 * * V_19 ,
const int * * V_7 , int V_17 )
{
if ( ! V_19 )
return ( F_13 ( V_7 ) ) ;
switch ( V_17 ) {
case V_59 :
* V_19 = & V_60 ;
break;
case V_61 :
* V_19 = & V_62 ;
break;
case V_63 :
* V_19 = & V_64 ;
break;
case V_65 :
* V_19 = & V_66 ;
break;
case V_67 :
* V_19 = & V_68 ;
break;
case V_69 :
* V_19 = & V_70 ;
break;
case V_71 :
* V_19 = & V_72 ;
break;
case V_73 :
* V_19 = & V_74 ;
break;
default:
* V_19 = NULL ;
break;
}
return ( * V_19 != NULL ) ;
}
static int
F_20 ( int V_17 )
{
int V_11 ;
for ( V_11 = 0 ; V_26 [ V_11 ] . V_16 ; V_11 ++ )
if ( V_26 [ V_11 ] . V_17 == V_17 )
return ( V_26 [ V_11 ] . V_16 ) ;
return ( 0 ) ;
}
static int
F_21 ( int V_17 )
{
int V_11 ;
for ( V_11 = 0 ; V_26 [ V_11 ] . V_16 ; V_11 ++ )
if ( V_26 [ V_11 ] . V_17 == V_17 )
return V_26 [ V_11 ] . V_20 ;
return ( 0 ) ;
}
static int F_22 ( T_5 * V_28 )
{
struct V_34 * V_35 = V_28 -> V_75 ;
struct V_9 * V_10 = & V_35 -> V_37 ;
int V_76 ;
if ( ( V_76 = F_20 ( V_28 -> V_76 -> type ) ) == V_18 ) {
printf ( L_3 ) ;
return ( 0 ) ;
}
memset ( V_35 , 0 , sizeof( struct V_34 ) ) ;
if ( ( V_35 -> V_41 = F_6 () ) < 0 ) {
printf ( L_4 ) ;
return ( 0 ) ;
}
V_10 -> V_25 = V_35 -> V_77 ;
V_10 -> V_27 = F_21 ( V_28 -> V_76 -> type ) ;
V_10 -> V_21 = V_76 ;
if ( F_8 ( V_35 -> V_41 , V_22 , V_10 ) < 0 ) {
F_9 ( V_35 -> V_41 ) ;
V_35 -> V_41 = - 1 ;
printf ( L_5 ) ;
return ( 0 ) ;
}
return ( 1 ) ;
}
static int F_23 ( T_5 * V_28 , const void * V_78 ,
T_2 V_12 )
{
struct V_32 V_33 ;
struct V_34 * V_35 = V_28 -> V_75 ;
struct V_9 * V_10 = & V_35 -> V_37 ;
if ( ! V_78 || V_35 -> V_41 < 0 ) {
printf ( L_6 ) ;
return ( 0 ) ;
}
if ( ! V_12 ) {
return ( 0 ) ;
}
if ( ! ( V_28 -> V_43 & V_79 ) ) {
V_35 -> V_80 = F_24 ( V_35 -> V_80 , V_35 -> V_81 + V_12 ) ;
if ( ! V_35 -> V_80 ) {
printf ( L_7 ) ;
return ( 0 ) ;
}
memcpy ( V_35 -> V_80 + V_35 -> V_81 , V_78 , V_12 ) ;
V_35 -> V_81 += V_12 ;
return ( 1 ) ;
}
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_24 = V_10 -> V_24 ;
V_33 . V_43 = 0 ;
V_33 . V_44 = V_12 ;
V_33 . V_45 = ( V_14 ) V_78 ;
V_33 . V_46 = NULL ;
V_33 . V_21 = ( V_14 ) V_35 -> V_82 ;
if ( F_8 ( V_35 -> V_41 , V_53 , & V_33 ) < 0 ) {
printf ( L_8 ) ;
return ( 0 ) ;
}
return ( 1 ) ;
}
static int F_25 ( T_5 * V_28 , unsigned char * V_83 )
{
struct V_32 V_33 ;
struct V_34 * V_35 = V_28 -> V_75 ;
struct V_9 * V_10 = & V_35 -> V_37 ;
int V_57 = 1 ;
if ( ! V_83 || V_35 -> V_41 < 0 ) {
printf ( L_9 ) ;
return ( 0 ) ;
}
if ( ! ( V_28 -> V_43 & V_79 ) ) {
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_24 = V_10 -> V_24 ;
V_33 . V_43 = 0 ;
V_33 . V_44 = V_35 -> V_81 ;
V_33 . V_45 = V_35 -> V_80 ;
V_33 . V_46 = NULL ;
V_33 . V_21 = ( V_14 ) V_83 ;
if ( F_8 ( V_35 -> V_41 , V_53 , & V_33 ) < 0 ) {
printf ( L_10 ) ;
return ( 0 ) ;
}
return 1 ;
}
memcpy ( V_83 , V_35 -> V_82 , V_28 -> V_76 -> V_84 ) ;
return ( V_57 ) ;
}
static int F_26 ( T_5 * V_28 )
{
int V_57 = 1 ;
struct V_34 * V_35 = V_28 -> V_75 ;
struct V_9 * V_10 = & V_35 -> V_37 ;
if ( V_35 == NULL )
return 0 ;
if ( V_35 -> V_41 < 0 ) {
printf ( L_11 ) ;
return ( 0 ) ;
}
if ( V_35 -> V_80 ) {
F_27 ( V_35 -> V_80 ) ;
V_35 -> V_80 = NULL ;
V_35 -> V_81 = 0 ;
}
if ( F_8 ( V_35 -> V_41 , V_23 , & V_10 -> V_24 ) < 0 ) {
printf ( L_12 ) ;
V_57 = 0 ;
} else {
V_57 = 1 ;
}
F_9 ( V_35 -> V_41 ) ;
V_35 -> V_41 = - 1 ;
return ( V_57 ) ;
}
static int F_28 ( T_5 * V_85 , const T_5 * V_86 )
{
struct V_34 * V_87 = V_86 -> V_75 ;
struct V_34 * V_88 = V_85 -> V_75 ;
struct V_9 * V_10 ;
int V_76 ;
if ( V_88 == NULL || V_87 == NULL )
return 1 ;
memcpy ( V_88 , V_87 , sizeof( struct V_34 ) ) ;
V_10 = & V_88 -> V_37 ;
V_76 = F_20 ( V_85 -> V_76 -> type ) ;
V_10 -> V_25 = V_88 -> V_77 ;
V_10 -> V_27 = F_21 ( V_85 -> V_76 -> type ) ;
V_10 -> V_21 = V_76 ;
V_88 -> V_41 = F_6 () ;
if ( F_8 ( V_88 -> V_41 , V_22 , V_10 ) < 0 ) {
F_9 ( V_88 -> V_41 ) ;
V_88 -> V_41 = - 1 ;
printf ( L_5 ) ;
return ( 0 ) ;
}
if ( V_87 -> V_81 != 0 ) {
if ( V_87 -> V_80 != NULL )
{
V_88 -> V_80 = F_29 ( V_87 -> V_81 ) ;
memcpy ( V_88 -> V_80 , V_87 -> V_80 , V_87 -> V_81 ) ;
V_88 -> V_81 = V_87 -> V_81 ;
}
}
return 1 ;
}
static int
F_30 ( T_3 * V_58 , const T_6 * * V_76 ,
const int * * V_7 , int V_17 )
{
if ( ! V_76 )
return ( F_14 ( V_7 ) ) ;
switch ( V_17 ) {
#ifdef F_15
case V_89 :
* V_76 = & V_90 ;
break;
case V_91 :
* V_76 = & V_92 ;
break;
default:
#endif
* V_76 = NULL ;
break;
}
return ( * V_76 != NULL ) ;
}
static int
F_31 ( const T_7 * V_93 , struct V_94 * V_95 )
{
int V_11 , V_96 , V_97 ;
T_8 V_98 , V_99 ;
T_9 * V_100 ;
V_95 -> V_101 = NULL ;
V_95 -> V_102 = 0 ;
V_99 = F_32 ( V_93 ) ;
V_98 = ( V_99 + 7 ) / 8 ;
V_100 = malloc ( V_98 ) ;
if ( V_100 == NULL )
return ( 1 ) ;
memset ( V_100 , 0 , V_98 ) ;
V_95 -> V_101 = ( V_14 ) V_100 ;
V_95 -> V_102 = V_99 ;
for ( V_11 = 0 , V_96 = 0 ; V_11 < V_93 -> V_103 ; V_11 ++ ) {
for ( V_97 = 0 ; V_97 < V_104 / 8 ; V_97 ++ ) {
if ( ( V_96 + V_97 ) >= V_98 )
return ( 0 ) ;
V_100 [ V_96 + V_97 ] = V_93 -> V_105 [ V_11 ] >> ( V_97 * 8 ) ;
}
V_96 += V_104 / 8 ;
}
return ( 0 ) ;
}
static int
F_33 ( struct V_94 * V_95 , T_7 * V_93 )
{
T_10 * V_106 ;
int V_11 , V_98 ;
V_98 = ( V_95 -> V_102 + 7 ) / 8 ;
if ( V_98 == 0 )
return ( - 1 ) ;
if ( ( V_106 = ( T_10 * ) malloc ( V_98 ) ) == NULL )
return ( - 1 ) ;
for ( V_11 = 0 ; V_11 < V_98 ; V_11 ++ )
V_106 [ V_11 ] = V_95 -> V_101 [ V_98 - V_11 - 1 ] ;
F_34 ( V_106 , V_98 , V_93 ) ;
free ( V_106 ) ;
return ( 0 ) ;
}
static void
F_35 ( struct V_107 * V_108 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_108 -> V_109 + V_108 -> V_110 ; V_11 ++ ) {
if ( V_108 -> V_111 [ V_11 ] . V_101 )
free ( V_108 -> V_111 [ V_11 ] . V_101 ) ;
V_108 -> V_111 [ V_11 ] . V_101 = NULL ;
V_108 -> V_111 [ V_11 ] . V_102 = 0 ;
}
}
static int
F_36 ( struct V_107 * V_108 , int V_112 , T_7 * V_113 , int V_114 , T_7 * V_115 )
{
int V_1 , V_57 = - 1 ;
if ( ( V_1 = F_10 () ) < 0 )
return ( V_57 ) ;
if ( V_113 ) {
V_108 -> V_111 [ V_108 -> V_109 ] . V_101 = calloc ( V_112 , sizeof( char ) ) ;
V_108 -> V_111 [ V_108 -> V_109 ] . V_102 = V_112 * 8 ;
V_108 -> V_110 ++ ;
}
if ( V_115 ) {
V_108 -> V_111 [ V_108 -> V_109 + 1 ] . V_101 = calloc ( V_114 , sizeof( char ) ) ;
V_108 -> V_111 [ V_108 -> V_109 + 1 ] . V_102 = V_114 * 8 ;
V_108 -> V_110 ++ ;
}
if ( F_8 ( V_1 , V_116 , V_108 ) == 0 ) {
if ( V_113 )
F_33 ( & V_108 -> V_111 [ V_108 -> V_109 ] , V_113 ) ;
if ( V_115 )
F_33 ( & V_108 -> V_111 [ V_108 -> V_109 + 1 ] , V_115 ) ;
V_57 = 0 ;
}
return ( V_57 ) ;
}
static int
F_37 ( T_7 * V_113 , const T_7 * V_93 , const T_7 * V_117 ,
const T_7 * V_118 , T_11 * V_28 , T_12 * V_119 )
{
struct V_107 V_108 ;
int V_57 = 1 ;
if ( V_120 == 0 ) {
V_57 = F_38 ( V_113 , V_93 , V_117 , V_118 , V_28 ) ;
return ( V_57 ) ;
}
memset ( & V_108 , 0 , sizeof V_108 ) ;
V_108 . V_121 = V_122 ;
if ( F_31 ( V_93 , & V_108 . V_111 [ 0 ] ) )
goto V_123;
if ( F_31 ( V_117 , & V_108 . V_111 [ 1 ] ) )
goto V_123;
if ( F_31 ( V_118 , & V_108 . V_111 [ 2 ] ) )
goto V_123;
V_108 . V_109 = 3 ;
if ( F_36 ( & V_108 , F_39 ( V_118 ) , V_113 , 0 , NULL ) ) {
const T_13 * V_124 = F_40 () ;
printf ( L_13 ) ;
V_57 = V_124 -> V_125 ( V_113 , V_93 , V_117 , V_118 , V_28 , V_119 ) ;
} else if ( V_126 == V_108 . V_127 ) {
const T_13 * V_124 = F_40 () ;
printf ( L_14 ) ;
V_57 = V_124 -> V_125 ( V_113 , V_93 , V_117 , V_118 , V_28 , V_119 ) ;
}
V_123:
F_35 ( & V_108 ) ;
return ( V_57 ) ;
}
static int
F_41 ( T_7 * V_128 , const T_7 * V_129 , T_14 * V_130 , T_11 * V_28 )
{
int V_113 ;
V_28 = F_42 () ;
V_113 = F_37 ( V_128 , V_129 , V_130 -> V_105 , V_130 -> V_131 , V_28 , NULL ) ;
F_43 ( V_28 ) ;
return ( V_113 ) ;
}
static int
F_44 ( T_7 * V_128 , const T_7 * V_129 , T_14 * V_130 , T_11 * V_28 )
{
struct V_107 V_108 ;
int V_57 = 1 ;
if ( ! V_130 -> V_117 || ! V_130 -> V_132 || ! V_130 -> V_133 || ! V_130 -> V_134 || ! V_130 -> V_135 ) {
return ( 0 ) ;
}
memset ( & V_108 , 0 , sizeof V_108 ) ;
V_108 . V_121 = V_136 ;
if ( F_31 ( V_130 -> V_117 , & V_108 . V_111 [ 0 ] ) )
goto V_123;
if ( F_31 ( V_130 -> V_132 , & V_108 . V_111 [ 1 ] ) )
goto V_123;
if ( F_31 ( V_129 , & V_108 . V_111 [ 2 ] ) )
goto V_123;
if ( F_31 ( V_130 -> V_133 , & V_108 . V_111 [ 3 ] ) )
goto V_123;
if ( F_31 ( V_130 -> V_134 , & V_108 . V_111 [ 4 ] ) )
goto V_123;
if ( F_31 ( V_130 -> V_135 , & V_108 . V_111 [ 5 ] ) )
goto V_123;
V_108 . V_109 = 6 ;
if ( F_36 ( & V_108 , F_39 ( V_130 -> V_131 ) , V_128 , 0 , NULL ) ) {
const T_13 * V_124 = F_40 () ;
printf ( L_15 ) ;
V_57 = (* V_124 -> V_137 )( V_128 , V_129 , V_130 , V_28 ) ;
} else if ( V_126 == V_108 . V_127 ) {
const T_13 * V_124 = F_40 () ;
printf ( L_14 ) ;
V_57 = (* V_124 -> V_137 )( V_128 , V_129 , V_130 , V_28 ) ;
}
V_123:
F_35 ( & V_108 ) ;
return ( V_57 ) ;
}
static int
F_45 ( T_15 * V_138 , T_7 * V_113 , T_7 * V_93 , const T_7 * V_117 ,
const T_7 * V_118 , T_11 * V_28 , T_12 * V_139 )
{
return ( F_37 ( V_113 , V_93 , V_117 , V_118 , V_28 , V_139 ) ) ;
}
static int
F_46 ( T_15 * V_138 , T_7 * V_140 , T_7 * V_141 ,
T_7 * V_142 , T_7 * V_143 , T_7 * V_144 , T_7 * V_117 ,
T_11 * V_28 , T_12 * V_145 )
{
T_7 V_146 ;
int V_57 = 0 ;
F_47 ( & V_146 ) ;
V_57 = 0 ;
if ( ! V_138 -> V_124 -> V_125 ( V_138 , V_140 , V_138 -> V_141 , V_142 , V_138 -> V_117 , V_28 , V_145 ) )
goto V_123;
if ( ! V_138 -> V_124 -> V_125 ( V_138 , & V_146 , V_138 -> V_143 , V_144 , V_138 -> V_117 , V_28 , V_145 ) )
goto V_123;
if ( ! F_48 ( V_142 , V_140 , & V_146 , V_138 -> V_117 , V_28 ) )
goto V_123;
F_49 ( V_140 , V_142 ) ;
V_57 = 1 ;
V_123:
F_50 ( & V_146 ) ;
return ( V_57 ) ;
}
static T_16 *
F_51 ( const unsigned char * V_147 , int V_148 , T_15 * V_138 )
{
struct V_107 V_108 ;
T_7 * V_113 = NULL , * V_115 = NULL ;
T_16 * V_149 = NULL ;
if ( ( V_113 = F_52 () ) == NULL )
goto V_123;
if ( ( V_115 = F_52 () ) == NULL ) {
F_50 ( V_113 ) ;
goto V_123;
}
memset ( & V_108 , 0 , sizeof V_108 ) ;
V_108 . V_121 = V_150 ;
V_108 . V_111 [ 0 ] . V_101 = ( V_14 ) V_147 ;
V_108 . V_111 [ 0 ] . V_102 = V_148 * 8 ;
if ( F_31 ( V_138 -> V_117 , & V_108 . V_111 [ 1 ] ) )
goto V_123;
if ( F_31 ( V_138 -> V_132 , & V_108 . V_111 [ 2 ] ) )
goto V_123;
if ( F_31 ( V_138 -> V_141 , & V_108 . V_111 [ 3 ] ) )
goto V_123;
if ( F_31 ( V_138 -> V_151 , & V_108 . V_111 [ 4 ] ) )
goto V_123;
V_108 . V_109 = 5 ;
if ( F_36 ( & V_108 , F_39 ( V_138 -> V_132 ) , V_113 ,
F_39 ( V_138 -> V_132 ) , V_115 ) == 0 ) {
V_149 = F_53 () ;
V_149 -> V_113 = V_113 ;
V_149 -> V_115 = V_115 ;
} else {
const T_17 * V_124 = F_54 () ;
F_50 ( V_113 ) ;
F_50 ( V_115 ) ;
V_149 = ( V_124 -> V_152 ) ( V_147 , V_148 , V_138 ) ;
}
V_123:
V_108 . V_111 [ 0 ] . V_101 = NULL ;
F_35 ( & V_108 ) ;
return ( V_149 ) ;
}
static int
F_55 ( const unsigned char * V_147 , int V_148 ,
T_16 * V_153 , T_15 * V_138 )
{
struct V_107 V_108 ;
int V_149 = 1 ;
memset ( & V_108 , 0 , sizeof V_108 ) ;
V_108 . V_121 = V_154 ;
V_108 . V_111 [ 0 ] . V_101 = ( V_14 ) V_147 ;
V_108 . V_111 [ 0 ] . V_102 = V_148 * 8 ;
if ( F_31 ( V_138 -> V_117 , & V_108 . V_111 [ 1 ] ) )
goto V_123;
if ( F_31 ( V_138 -> V_132 , & V_108 . V_111 [ 2 ] ) )
goto V_123;
if ( F_31 ( V_138 -> V_141 , & V_108 . V_111 [ 3 ] ) )
goto V_123;
if ( F_31 ( V_138 -> V_143 , & V_108 . V_111 [ 4 ] ) )
goto V_123;
if ( F_31 ( V_153 -> V_113 , & V_108 . V_111 [ 5 ] ) )
goto V_123;
if ( F_31 ( V_153 -> V_115 , & V_108 . V_111 [ 6 ] ) )
goto V_123;
V_108 . V_109 = 7 ;
if ( F_36 ( & V_108 , 0 , NULL , 0 , NULL ) == 0 ) {
if( 0 != V_108 . V_127 ) V_149 = 0 ;
} else {
const T_17 * V_124 = F_54 () ;
V_149 = ( V_124 -> V_155 ) ( V_147 , V_148 , V_153 , V_138 ) ;
}
V_123:
V_108 . V_111 [ 0 ] . V_101 = NULL ;
F_35 ( & V_108 ) ;
return ( V_149 ) ;
}
static int
F_56 ( const T_18 * V_156 , T_7 * V_113 , const T_7 * V_93 ,
const T_7 * V_117 , const T_7 * V_118 , T_11 * V_28 ,
T_12 * V_139 )
{
return ( F_37 ( V_113 , V_93 , V_117 , V_118 , V_28 , V_139 ) ) ;
}
static int
F_57 ( unsigned char * V_13 , const T_7 * V_143 , T_18 * V_156 )
{
struct V_107 V_108 ;
int V_157 = 1 ;
int V_1 , V_20 ;
if ( ( V_1 = F_10 () ) < 0 ) {
const T_19 * V_124 = F_58 () ;
return ( ( V_124 -> V_158 ) ( V_13 , V_143 , V_156 ) ) ;
}
V_20 = F_32 ( V_156 -> V_117 ) ;
memset ( & V_108 , 0 , sizeof V_108 ) ;
V_108 . V_121 = V_159 ;
if ( F_31 ( V_156 -> V_151 , & V_108 . V_111 [ 0 ] ) )
goto V_123;
if ( F_31 ( V_143 , & V_108 . V_111 [ 1 ] ) )
goto V_123;
if ( F_31 ( V_156 -> V_117 , & V_108 . V_111 [ 2 ] ) )
goto V_123;
V_108 . V_109 = 3 ;
V_108 . V_111 [ 3 ] . V_101 = ( V_14 ) V_13 ;
V_108 . V_111 [ 3 ] . V_102 = V_20 * 8 ;
V_108 . V_110 = 1 ;
if ( F_8 ( V_1 , V_116 , & V_108 ) == - 1 ) {
const T_19 * V_124 = F_58 () ;
V_157 = ( V_124 -> V_158 ) ( V_13 , V_143 , V_156 ) ;
}
V_123:
V_108 . V_111 [ 3 ] . V_101 = NULL ;
F_35 ( & V_108 ) ;
return ( V_157 ) ;
}
static int
F_59 ( T_3 * V_58 , int V_160 , long V_11 , void * V_117 , void (* F_60)( void ) )
{
#ifdef F_61
struct V_161 V_162 = V_163 ;
#endif
switch ( V_160 ) {
default:
#ifdef F_61
F_62 ( V_164 , & V_162 ,
L_16 , V_160 ) ;
#else
F_63 ( V_164 , L_16 , V_160 ) ;
#endif
break;
}
return ( 1 ) ;
}
void
F_1 ( void )
{
T_3 * V_165 = F_64 () ;
int V_1 ;
if ( V_165 == NULL )
return;
if ( ( V_1 = F_6 () ) < 0 ) {
F_65 ( V_165 ) ;
return;
}
if ( F_8 ( V_1 , V_166 , & V_120 ) == - 1 ) {
F_9 ( V_1 ) ;
F_65 ( V_165 ) ;
return;
}
F_9 ( V_1 ) ;
if ( ! F_66 ( V_165 , L_17 ) ||
! F_67 ( V_165 , L_18 ) ||
! F_68 ( V_165 , F_19 ) ||
! F_69 ( V_165 , F_30 ) ||
! F_70 ( V_165 , F_59 ) ||
! F_71 ( V_165 , V_167 ) ) {
F_65 ( V_165 ) ;
return;
}
if ( F_72 ( V_165 , & V_168 ) ) {
const T_13 * V_169 = F_40 () ;
V_168 . V_125 = V_169 -> V_125 ;
V_168 . V_137 = V_169 -> V_137 ;
V_168 . V_170 = V_169 -> V_170 ;
V_168 . V_171 = V_169 -> V_171 ;
V_168 . V_172 = V_169 -> V_172 ;
V_168 . V_173 = V_169 -> V_173 ;
if ( V_120 & V_174 ) {
V_168 . V_125 = F_37 ;
if ( V_120 & V_175 )
V_168 . V_137 =
F_44 ;
else
V_168 . V_137 =
F_41 ;
}
}
if ( F_73 ( V_165 , & V_176 ) ) {
const T_17 * V_124 = F_54 () ;
memcpy ( & V_176 , V_124 , sizeof( T_17 ) ) ;
if ( V_120 & V_177 )
V_176 . V_152 = F_51 ;
if ( V_120 & V_174 ) {
V_176 . V_125 = F_45 ;
V_176 . V_178 = F_46 ;
}
if ( V_120 & V_179 )
V_176 . V_155 = F_55 ;
}
if ( F_74 ( V_165 , & V_180 ) ) {
const T_19 * V_181 = F_58 () ;
V_180 . V_182 = V_181 -> V_182 ;
V_180 . V_158 = V_181 -> V_158 ;
V_180 . V_125 = V_181 -> V_125 ;
if ( V_120 & V_174 ) {
V_180 . V_125 = F_56 ;
if ( V_120 & V_183 )
V_180 . V_158 =
F_57 ;
}
}
F_75 ( V_165 ) ;
F_65 ( V_165 ) ;
F_76 () ;
}

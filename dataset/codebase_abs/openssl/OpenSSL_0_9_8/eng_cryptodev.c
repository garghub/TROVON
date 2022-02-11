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
if ( F_7 ( V_1 , V_5 , & V_4 ) == - 1 )
return ( - 1 ) ;
if ( F_4 ( V_4 , V_3 , 1 ) == - 1 ) {
F_5 ( V_4 ) ;
return ( - 1 ) ;
}
return ( V_4 ) ;
}
static int
F_8 ( void )
{
static int V_1 = - 1 ;
if ( V_1 == - 1 )
V_1 = F_6 () ;
return V_1 ;
}
static int
F_9 ( int V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_8 [ V_7 ] . V_9 ; V_7 ++ )
if ( V_8 [ V_7 ] . V_9 == V_6 )
return ( V_8 [ V_7 ] . V_10 ) ;
return ( 0 ) ;
}
static int
F_10 ( int V_6 , int V_11 )
{
int V_7 ;
for ( V_7 = 0 ; V_8 [ V_7 ] . V_9 ; V_7 ++ )
if ( V_8 [ V_7 ] . V_9 == V_6 )
return ( V_8 [ V_7 ] . V_12 == V_11 ) ;
return ( 0 ) ;
}
static int
F_11 ( int V_13 )
{
int V_7 ;
for ( V_7 = 0 ; V_8 [ V_7 ] . V_9 ; V_7 ++ )
if ( V_8 [ V_7 ] . V_13 == V_13 )
return ( V_8 [ V_7 ] . V_9 ) ;
return ( 0 ) ;
}
static int
F_12 ( const int * * V_14 )
{
static int V_15 [ V_16 ] ;
struct V_17 V_18 ;
int V_1 , V_7 , V_19 = 0 ;
if ( ( V_1 = F_6 () ) < 0 ) {
* V_14 = NULL ;
return ( 0 ) ;
}
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_20 = ( V_21 ) L_2 ;
for ( V_7 = 0 ; V_8 [ V_7 ] . V_9 && V_19 < V_16 ; V_7 ++ ) {
if ( V_8 [ V_7 ] . V_13 == V_22 )
continue;
V_18 . V_6 = V_8 [ V_7 ] . V_9 ;
V_18 . V_12 = V_8 [ V_7 ] . V_12 ;
V_18 . V_23 = 0 ;
if ( F_7 ( V_1 , V_24 , & V_18 ) != - 1 &&
F_7 ( V_1 , V_25 , & V_18 . V_26 ) != - 1 )
V_15 [ V_19 ++ ] = V_8 [ V_7 ] . V_13 ;
}
F_5 ( V_1 ) ;
if ( V_19 > 0 )
* V_14 = V_15 ;
else
* V_14 = NULL ;
return ( V_19 ) ;
}
static int
F_13 ( const int * * V_14 )
{
static int V_15 [ V_16 ] ;
struct V_17 V_18 ;
int V_1 , V_7 , V_19 = 0 ;
if ( ( V_1 = F_6 () ) < 0 ) {
* V_14 = NULL ;
return ( 0 ) ;
}
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
for ( V_7 = 0 ; V_27 [ V_7 ] . V_9 && V_19 < V_16 ; V_7 ++ ) {
if ( V_27 [ V_7 ] . V_13 == V_22 )
continue;
V_18 . V_23 = V_27 [ V_7 ] . V_9 ;
V_18 . V_6 = 0 ;
if ( F_7 ( V_1 , V_24 , & V_18 ) != - 1 &&
F_7 ( V_1 , V_25 , & V_18 . V_26 ) != - 1 )
V_15 [ V_19 ++ ] = V_27 [ V_7 ] . V_13 ;
}
F_5 ( V_1 ) ;
if ( V_19 > 0 )
* V_14 = V_15 ;
else
* V_14 = NULL ;
return ( V_19 ) ;
}
static int
F_14 ( const int * * V_15 )
{
return ( F_12 ( V_15 ) ) ;
}
static int
F_15 ( const int * * V_15 )
{
* V_15 = NULL ;
return ( 0 ) ;
}
static int
F_16 ( T_1 * V_28 , unsigned char * V_29 ,
const unsigned char * V_30 , unsigned int V_31 )
{
struct V_32 V_33 ;
struct V_34 * V_35 = V_28 -> V_36 ;
struct V_17 * V_18 = & V_35 -> V_37 ;
void * V_38 ;
unsigned char V_39 [ V_40 ] ;
if ( V_35 -> V_41 < 0 )
return ( 0 ) ;
if ( ! V_31 )
return ( 1 ) ;
if ( ( V_31 % V_28 -> V_6 -> V_42 ) != 0 )
return ( 0 ) ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_26 = V_18 -> V_26 ;
V_33 . V_43 = 0 ;
V_33 . V_11 = V_31 ;
V_33 . V_44 = ( V_21 ) V_30 ;
V_33 . V_45 = ( V_21 ) V_29 ;
V_33 . V_23 = 0 ;
V_33 . V_46 = V_28 -> V_47 ? V_48 : V_49 ;
if ( V_28 -> V_6 -> V_50 ) {
V_33 . V_51 = ( V_21 ) V_28 -> V_51 ;
if ( ! V_28 -> V_47 ) {
V_38 = ( void * ) V_30 + V_31 - V_28 -> V_6 -> V_50 ;
memcpy ( V_39 , V_38 , V_28 -> V_6 -> V_50 ) ;
}
} else
V_33 . V_51 = NULL ;
if ( F_7 ( V_35 -> V_41 , V_52 , & V_33 ) == - 1 ) {
return ( 0 ) ;
}
if ( V_28 -> V_6 -> V_50 ) {
if ( V_28 -> V_47 )
V_38 = ( void * ) V_29 + V_31 - V_28 -> V_6 -> V_50 ;
else
V_38 = V_39 ;
memcpy ( V_28 -> V_51 , V_38 , V_28 -> V_6 -> V_50 ) ;
}
return ( 1 ) ;
}
static int
F_17 ( T_1 * V_28 , const unsigned char * V_20 ,
const unsigned char * V_51 , int V_53 )
{
struct V_34 * V_35 = V_28 -> V_36 ;
struct V_17 * V_18 = & V_35 -> V_37 ;
int V_6 ;
if ( ( V_6 = F_11 ( V_28 -> V_6 -> V_13 ) ) == V_22 )
return ( 0 ) ;
if ( V_28 -> V_6 -> V_50 > F_9 ( V_6 ) )
return ( 0 ) ;
if ( ! F_10 ( V_6 , V_28 -> V_54 ) )
return ( 0 ) ;
memset ( V_18 , 0 , sizeof( struct V_17 ) ) ;
if ( ( V_35 -> V_41 = F_6 () ) < 0 )
return ( 0 ) ;
V_18 -> V_20 = ( unsigned char * ) V_20 ;
V_18 -> V_12 = V_28 -> V_54 ;
V_18 -> V_6 = V_6 ;
if ( F_7 ( V_35 -> V_41 , V_24 , V_18 ) == - 1 ) {
F_5 ( V_35 -> V_41 ) ;
V_35 -> V_41 = - 1 ;
return ( 0 ) ;
}
return ( 1 ) ;
}
static int
F_18 ( T_1 * V_28 )
{
int V_55 = 0 ;
struct V_34 * V_35 = V_28 -> V_36 ;
struct V_17 * V_18 = & V_35 -> V_37 ;
if ( V_35 -> V_41 < 0 )
return ( 0 ) ;
if ( F_7 ( V_35 -> V_41 , V_25 , & V_18 -> V_26 ) == - 1 ) {
V_55 = 0 ;
} else {
V_55 = 1 ;
}
F_5 ( V_35 -> V_41 ) ;
V_35 -> V_41 = - 1 ;
return ( V_55 ) ;
}
static int
F_19 ( T_2 * V_56 , const T_3 * * V_6 ,
const int * * V_15 , int V_13 )
{
if ( ! V_6 )
return ( F_14 ( V_15 ) ) ;
switch ( V_13 ) {
case V_57 :
* V_6 = & V_58 ;
break;
case V_59 :
* V_6 = & V_60 ;
break;
case V_61 :
* V_6 = & V_62 ;
break;
case V_63 :
* V_6 = & V_64 ;
break;
case V_65 :
* V_6 = & V_66 ;
break;
default:
* V_6 = NULL ;
break;
}
return ( * V_6 != NULL ) ;
}
static int
F_20 ( T_2 * V_56 , const T_4 * * V_67 ,
const int * * V_15 , int V_13 )
{
if ( ! V_67 )
return ( F_15 ( V_15 ) ) ;
switch ( V_13 ) {
case V_68 :
* V_67 = NULL ;
break;
default:
* V_67 = NULL ;
break;
}
return ( * V_67 != NULL ) ;
}
static int
F_21 ( const T_5 * V_69 , struct V_70 * V_71 )
{
int V_7 , V_72 , V_73 ;
T_6 V_74 , V_75 , V_76 ;
T_7 * V_77 ;
V_71 -> V_78 = NULL ;
V_71 -> V_79 = 0 ;
V_76 = F_22 ( V_69 ) ;
V_75 = ( V_76 + 7 ) / 8 ;
V_77 = malloc ( V_75 ) ;
if ( V_77 == NULL )
return ( 1 ) ;
V_71 -> V_78 = V_77 ;
V_71 -> V_79 = V_76 ;
for ( V_7 = 0 , V_72 = 0 ; V_7 < V_69 -> V_80 ; V_7 ++ ) {
for ( V_73 = 0 ; V_73 < V_81 / 8 ; V_73 ++ ) {
if ( ( V_72 + V_73 ) >= V_75 )
return ( 0 ) ;
V_77 [ V_72 + V_73 ] = V_69 -> V_82 [ V_7 ] >> ( V_73 * 8 ) ;
}
V_72 += V_81 / 8 ;
}
return ( 0 ) ;
}
static int
F_23 ( struct V_70 * V_71 , T_5 * V_69 )
{
T_8 * V_83 ;
int V_7 , V_75 ;
V_75 = ( V_71 -> V_79 + 7 ) / 8 ;
if ( V_75 == 0 )
return ( - 1 ) ;
if ( ( V_83 = ( T_8 * ) malloc ( V_75 ) ) == NULL )
return ( - 1 ) ;
for ( V_7 = 0 ; V_7 < V_75 ; V_7 ++ )
V_83 [ V_7 ] = V_71 -> V_78 [ V_75 - V_7 - 1 ] ;
F_24 ( V_83 , V_75 , V_69 ) ;
free ( V_83 ) ;
return ( 0 ) ;
}
static void
F_25 ( struct V_84 * V_85 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 <= V_85 -> V_86 + V_85 -> V_87 ; V_7 ++ ) {
if ( V_85 -> V_88 [ V_7 ] . V_78 )
free ( V_85 -> V_88 [ V_7 ] . V_78 ) ;
V_85 -> V_88 [ V_7 ] . V_78 = NULL ;
V_85 -> V_88 [ V_7 ] . V_79 = 0 ;
}
}
static int
F_26 ( struct V_84 * V_85 , int V_89 , T_5 * V_90 , int V_91 , T_5 * V_92 )
{
int V_1 , V_55 = - 1 ;
if ( ( V_1 = F_8 () ) < 0 )
return ( V_55 ) ;
if ( V_90 ) {
V_85 -> V_88 [ V_85 -> V_86 ] . V_78 = calloc ( V_89 , sizeof( char ) ) ;
V_85 -> V_88 [ V_85 -> V_86 ] . V_79 = V_89 * 8 ;
V_85 -> V_87 ++ ;
}
if ( V_92 ) {
V_85 -> V_88 [ V_85 -> V_86 + 1 ] . V_78 = calloc ( V_91 , sizeof( char ) ) ;
V_85 -> V_88 [ V_85 -> V_86 + 1 ] . V_79 = V_91 * 8 ;
V_85 -> V_87 ++ ;
}
if ( F_7 ( V_1 , V_93 , V_85 ) == 0 ) {
if ( V_90 )
F_23 ( & V_85 -> V_88 [ V_85 -> V_86 ] , V_90 ) ;
if ( V_92 )
F_23 ( & V_85 -> V_88 [ V_85 -> V_86 + 1 ] , V_92 ) ;
V_55 = 0 ;
}
return ( V_55 ) ;
}
static int
F_27 ( T_5 * V_90 , const T_5 * V_69 , const T_5 * V_94 ,
const T_5 * V_95 , T_9 * V_28 , T_10 * V_96 )
{
struct V_84 V_85 ;
int V_55 = 1 ;
if ( V_97 == 0 ) {
V_55 = F_28 ( V_90 , V_69 , V_94 , V_95 , V_28 ) ;
return ( V_55 ) ;
}
memset ( & V_85 , 0 , sizeof V_85 ) ;
V_85 . V_98 = V_99 ;
if ( F_21 ( V_69 , & V_85 . V_88 [ 0 ] ) )
goto V_100;
if ( F_21 ( V_94 , & V_85 . V_88 [ 1 ] ) )
goto V_100;
if ( F_21 ( V_95 , & V_85 . V_88 [ 2 ] ) )
goto V_100;
V_85 . V_86 = 3 ;
if ( F_26 ( & V_85 , F_29 ( V_95 ) , V_90 , 0 , NULL ) == - 1 ) {
const T_11 * V_101 = F_30 () ;
V_55 = V_101 -> V_102 ( V_90 , V_69 , V_94 , V_95 , V_28 , V_96 ) ;
}
V_100:
F_25 ( & V_85 ) ;
return ( V_55 ) ;
}
static int
F_31 ( T_5 * V_103 , const T_5 * V_104 , T_12 * V_105 )
{
int V_90 ;
T_9 * V_28 ;
V_28 = F_32 () ;
V_90 = F_27 ( V_103 , V_104 , V_105 -> V_82 , V_105 -> V_106 , V_28 , NULL ) ;
F_33 ( V_28 ) ;
return ( V_90 ) ;
}
static int
F_34 ( T_5 * V_103 , const T_5 * V_104 , T_12 * V_105 , T_9 * V_28 )
{
struct V_84 V_85 ;
int V_55 = 1 ;
if ( ! V_105 -> V_94 || ! V_105 -> V_107 || ! V_105 -> V_108 || ! V_105 -> V_109 || ! V_105 -> V_110 ) {
return ( 0 ) ;
}
memset ( & V_85 , 0 , sizeof V_85 ) ;
V_85 . V_98 = V_111 ;
if ( F_21 ( V_105 -> V_94 , & V_85 . V_88 [ 0 ] ) )
goto V_100;
if ( F_21 ( V_105 -> V_107 , & V_85 . V_88 [ 1 ] ) )
goto V_100;
if ( F_21 ( V_104 , & V_85 . V_88 [ 2 ] ) )
goto V_100;
if ( F_21 ( V_105 -> V_108 , & V_85 . V_88 [ 3 ] ) )
goto V_100;
if ( F_21 ( V_105 -> V_109 , & V_85 . V_88 [ 4 ] ) )
goto V_100;
if ( F_21 ( V_105 -> V_110 , & V_85 . V_88 [ 5 ] ) )
goto V_100;
V_85 . V_86 = 6 ;
if ( F_26 ( & V_85 , F_29 ( V_105 -> V_106 ) , V_103 , 0 , NULL ) == - 1 ) {
const T_11 * V_101 = F_30 () ;
V_55 = (* V_101 -> V_112 )( V_103 , V_104 , V_105 , V_28 ) ;
}
V_100:
F_25 ( & V_85 ) ;
return ( V_55 ) ;
}
static int
F_35 ( T_13 * V_113 , T_5 * V_90 , T_5 * V_69 , const T_5 * V_94 ,
const T_5 * V_95 , T_9 * V_28 , T_10 * V_114 )
{
return ( F_27 ( V_90 , V_69 , V_94 , V_95 , V_28 , V_114 ) ) ;
}
static int
F_36 ( T_13 * V_113 , T_5 * V_115 , T_5 * V_116 ,
T_5 * V_117 , T_5 * V_118 , T_5 * V_119 , T_5 * V_94 ,
T_9 * V_28 , T_10 * V_120 )
{
T_5 V_121 ;
int V_55 = 0 ;
F_37 ( & V_121 ) ;
V_55 = 0 ;
if ( ! V_113 -> V_101 -> V_102 ( V_113 , V_115 , V_113 -> V_116 , V_117 , V_113 -> V_94 , V_28 , V_120 ) )
goto V_100;
if ( ! V_113 -> V_101 -> V_102 ( V_113 , & V_121 , V_113 -> V_118 , V_119 , V_113 -> V_94 , V_28 , V_120 ) )
goto V_100;
if ( ! F_38 ( V_117 , V_115 , & V_121 , V_113 -> V_94 , V_28 ) )
goto V_100;
F_39 ( V_115 , V_117 ) ;
V_55 = 1 ;
V_100:
F_40 ( & V_121 ) ;
return ( V_55 ) ;
}
static T_14 *
F_41 ( const unsigned char * V_122 , int V_123 , T_13 * V_113 )
{
struct V_84 V_85 ;
T_5 * V_90 = NULL , * V_92 = NULL ;
T_14 * V_124 = NULL ;
if ( ( V_90 = F_42 () ) == NULL )
goto V_100;
if ( ( V_92 = F_42 () ) == NULL ) {
F_40 ( V_90 ) ;
goto V_100;
}
memset ( & V_85 , 0 , sizeof V_85 ) ;
V_85 . V_98 = V_125 ;
V_85 . V_88 [ 0 ] . V_78 = ( V_21 ) V_122 ;
V_85 . V_88 [ 0 ] . V_79 = V_123 * 8 ;
if ( F_21 ( V_113 -> V_94 , & V_85 . V_88 [ 1 ] ) )
goto V_100;
if ( F_21 ( V_113 -> V_107 , & V_85 . V_88 [ 2 ] ) )
goto V_100;
if ( F_21 ( V_113 -> V_116 , & V_85 . V_88 [ 3 ] ) )
goto V_100;
if ( F_21 ( V_113 -> V_126 , & V_85 . V_88 [ 4 ] ) )
goto V_100;
V_85 . V_86 = 5 ;
if ( F_26 ( & V_85 , F_29 ( V_113 -> V_107 ) , V_90 ,
F_29 ( V_113 -> V_107 ) , V_92 ) == 0 ) {
V_124 = F_43 () ;
V_124 -> V_90 = V_90 ;
V_124 -> V_92 = V_92 ;
} else {
const T_15 * V_101 = F_44 () ;
F_40 ( V_90 ) ;
F_40 ( V_92 ) ;
V_124 = ( V_101 -> V_127 ) ( V_122 , V_123 , V_113 ) ;
}
V_100:
V_85 . V_88 [ 0 ] . V_78 = NULL ;
F_25 ( & V_85 ) ;
return ( V_124 ) ;
}
static int
F_45 ( const unsigned char * V_122 , int V_123 ,
T_14 * V_128 , T_13 * V_113 )
{
struct V_84 V_85 ;
int V_124 = 1 ;
memset ( & V_85 , 0 , sizeof V_85 ) ;
V_85 . V_98 = V_129 ;
V_85 . V_88 [ 0 ] . V_78 = ( V_21 ) V_122 ;
V_85 . V_88 [ 0 ] . V_79 = V_123 * 8 ;
if ( F_21 ( V_113 -> V_94 , & V_85 . V_88 [ 1 ] ) )
goto V_100;
if ( F_21 ( V_113 -> V_107 , & V_85 . V_88 [ 2 ] ) )
goto V_100;
if ( F_21 ( V_113 -> V_116 , & V_85 . V_88 [ 3 ] ) )
goto V_100;
if ( F_21 ( V_113 -> V_118 , & V_85 . V_88 [ 4 ] ) )
goto V_100;
if ( F_21 ( V_128 -> V_90 , & V_85 . V_88 [ 5 ] ) )
goto V_100;
if ( F_21 ( V_128 -> V_92 , & V_85 . V_88 [ 6 ] ) )
goto V_100;
V_85 . V_86 = 7 ;
if ( F_26 ( & V_85 , 0 , NULL , 0 , NULL ) == 0 ) {
V_124 = V_85 . V_130 ;
} else {
const T_15 * V_101 = F_44 () ;
V_124 = ( V_101 -> V_131 ) ( V_122 , V_123 , V_128 , V_113 ) ;
}
V_100:
V_85 . V_88 [ 0 ] . V_78 = NULL ;
F_25 ( & V_85 ) ;
return ( V_124 ) ;
}
static int
F_46 ( const T_16 * V_132 , T_5 * V_90 , const T_5 * V_69 ,
const T_5 * V_94 , const T_5 * V_95 , T_9 * V_28 ,
T_10 * V_114 )
{
return ( F_27 ( V_90 , V_69 , V_94 , V_95 , V_28 , V_114 ) ) ;
}
static int
F_47 ( unsigned char * V_20 , const T_5 * V_118 , T_16 * V_132 )
{
struct V_84 V_85 ;
int V_133 = 1 ;
int V_1 , V_12 ;
if ( ( V_1 = F_8 () ) < 0 ) {
const T_17 * V_101 = F_48 () ;
return ( ( V_101 -> V_134 ) ( V_20 , V_118 , V_132 ) ) ;
}
V_12 = F_22 ( V_132 -> V_94 ) ;
memset ( & V_85 , 0 , sizeof V_85 ) ;
V_85 . V_98 = V_135 ;
if ( F_21 ( V_132 -> V_126 , & V_85 . V_88 [ 0 ] ) )
goto V_100;
if ( F_21 ( V_118 , & V_85 . V_88 [ 1 ] ) )
goto V_100;
if ( F_21 ( V_132 -> V_94 , & V_85 . V_88 [ 2 ] ) )
goto V_100;
V_85 . V_86 = 3 ;
V_85 . V_88 [ 3 ] . V_78 = V_20 ;
V_85 . V_88 [ 3 ] . V_79 = V_12 * 8 ;
V_85 . V_87 = 1 ;
if ( F_7 ( V_1 , V_93 , & V_85 ) == - 1 ) {
const T_17 * V_101 = F_48 () ;
V_133 = ( V_101 -> V_134 ) ( V_20 , V_118 , V_132 ) ;
}
V_100:
V_85 . V_88 [ 3 ] . V_78 = NULL ;
F_25 ( & V_85 ) ;
return ( V_133 ) ;
}
static int
F_49 ( T_2 * V_56 , int V_136 , long V_7 , void * V_94 , void (* F_50)() )
{
#ifdef F_51
struct V_137 V_138 = V_139 ;
#endif
switch ( V_136 ) {
default:
#ifdef F_51
F_52 ( V_140 , & V_138 ,
L_3 , V_136 ) ;
#else
F_53 ( V_140 , L_3 , V_136 ) ;
#endif
break;
}
return ( 1 ) ;
}
void
F_1 ( void )
{
T_2 * V_141 = F_54 () ;
int V_1 ;
if ( V_141 == NULL )
return;
if ( ( V_1 = F_6 () ) < 0 ) {
F_55 ( V_141 ) ;
return;
}
if ( F_7 ( V_1 , V_142 , & V_97 ) == - 1 ) {
F_5 ( V_1 ) ;
F_55 ( V_141 ) ;
return;
}
F_5 ( V_1 ) ;
if ( ! F_56 ( V_141 , L_4 ) ||
! F_57 ( V_141 , L_5 ) ||
! F_58 ( V_141 , F_19 ) ||
! F_59 ( V_141 , F_20 ) ||
! F_60 ( V_141 , F_49 ) ||
! F_61 ( V_141 , V_143 ) ) {
F_55 ( V_141 ) ;
return;
}
if ( F_62 ( V_141 , & V_144 ) ) {
const T_11 * V_145 = F_30 () ;
V_144 . V_102 = V_145 -> V_102 ;
V_144 . V_112 = V_145 -> V_112 ;
V_144 . V_146 = V_145 -> V_146 ;
V_144 . V_147 = V_145 -> V_147 ;
V_144 . V_148 = V_145 -> V_148 ;
V_144 . V_149 = V_145 -> V_149 ;
if ( V_97 & V_150 ) {
V_144 . V_102 = F_27 ;
if ( V_97 & V_151 )
V_144 . V_112 =
F_34 ;
else
V_144 . V_112 =
F_31 ;
}
}
if ( F_63 ( V_141 , & V_152 ) ) {
const T_15 * V_101 = F_44 () ;
memcpy ( & V_152 , V_101 , sizeof( T_15 ) ) ;
if ( V_97 & V_153 )
V_152 . V_127 = F_41 ;
if ( V_97 & V_150 ) {
V_152 . V_102 = F_35 ;
V_152 . V_154 = F_36 ;
}
if ( V_97 & V_155 )
V_152 . V_131 = F_45 ;
}
if ( F_64 ( V_141 , & V_156 ) ) {
const T_17 * V_157 = F_48 () ;
V_156 . V_158 = V_157 -> V_158 ;
V_156 . V_134 = V_157 -> V_134 ;
V_156 . V_102 = V_157 -> V_102 ;
if ( V_97 & V_150 ) {
V_156 . V_102 = F_46 ;
if ( V_97 & V_159 )
V_156 . V_134 =
F_47 ;
}
}
F_65 ( V_141 ) ;
F_55 ( V_141 ) ;
F_66 () ;
}

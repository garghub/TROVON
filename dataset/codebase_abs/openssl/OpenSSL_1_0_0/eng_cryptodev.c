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
F_9 ( const int * * V_6 )
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
if ( F_7 ( V_1 , V_22 , & V_10 ) != - 1 &&
F_7 ( V_1 , V_23 , & V_10 . V_24 ) != - 1 )
V_7 [ V_12 ++ ] = V_15 [ V_11 ] . V_17 ;
}
F_5 ( V_1 ) ;
if ( V_12 > 0 )
* V_6 = V_7 ;
else
* V_6 = NULL ;
return ( V_12 ) ;
}
static int
F_10 ( const int * * V_6 )
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
if ( F_7 ( V_1 , V_22 , & V_10 ) != - 1 &&
F_7 ( V_1 , V_23 , & V_10 . V_24 ) != - 1 )
V_7 [ V_12 ++ ] = V_26 [ V_11 ] . V_17 ;
}
F_5 ( V_1 ) ;
if ( V_12 > 0 )
* V_6 = V_7 ;
else
* V_6 = NULL ;
return ( V_12 ) ;
}
static int
F_11 ( const int * * V_7 )
{
return ( F_9 ( V_7 ) ) ;
}
static int
F_12 ( const int * * V_7 )
{
#ifdef F_13
return ( F_10 ( V_7 ) ) ;
#else
* V_7 = NULL ;
return ( 0 ) ;
#endif
}
static int
F_14 ( T_1 * V_28 , unsigned char * V_29 ,
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
if ( F_7 ( V_35 -> V_41 , V_53 , & V_33 ) == - 1 ) {
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
F_15 ( T_1 * V_28 , const unsigned char * V_13 ,
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
if ( F_7 ( V_35 -> V_41 , V_22 , V_10 ) == - 1 ) {
F_5 ( V_35 -> V_41 ) ;
V_35 -> V_41 = - 1 ;
return ( 0 ) ;
}
return ( 1 ) ;
}
static int
F_16 ( T_1 * V_28 )
{
int V_57 = 0 ;
struct V_34 * V_35 = V_28 -> V_36 ;
struct V_9 * V_10 = & V_35 -> V_37 ;
if ( V_35 -> V_41 < 0 )
return ( 0 ) ;
if ( F_7 ( V_35 -> V_41 , V_23 , & V_10 -> V_24 ) == - 1 ) {
V_57 = 0 ;
} else {
V_57 = 1 ;
}
F_5 ( V_35 -> V_41 ) ;
V_35 -> V_41 = - 1 ;
return ( V_57 ) ;
}
static int
F_17 ( T_3 * V_58 , const T_4 * * V_19 ,
const int * * V_7 , int V_17 )
{
if ( ! V_19 )
return ( F_11 ( V_7 ) ) ;
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
F_18 ( int V_17 )
{
int V_11 ;
for ( V_11 = 0 ; V_26 [ V_11 ] . V_16 ; V_11 ++ )
if ( V_26 [ V_11 ] . V_17 == V_17 )
return ( V_26 [ V_11 ] . V_16 ) ;
return ( 0 ) ;
}
static int
F_19 ( int V_17 )
{
int V_11 ;
for ( V_11 = 0 ; V_26 [ V_11 ] . V_16 ; V_11 ++ )
if ( V_26 [ V_11 ] . V_17 == V_17 )
return V_26 [ V_11 ] . V_20 ;
return ( 0 ) ;
}
static int F_20 ( T_5 * V_28 )
{
struct V_34 * V_35 = V_28 -> V_75 ;
struct V_9 * V_10 = & V_35 -> V_37 ;
int V_76 ;
if ( ( V_76 = F_18 ( V_28 -> V_76 -> type ) ) == V_18 ) {
printf ( L_3 ) ;
return ( 0 ) ;
}
memset ( V_35 , 0 , sizeof( struct V_34 ) ) ;
if ( ( V_35 -> V_41 = F_6 () ) < 0 ) {
printf ( L_4 ) ;
return ( 0 ) ;
}
V_10 -> V_25 = V_35 -> V_77 ;
V_10 -> V_27 = F_19 ( V_28 -> V_76 -> type ) ;
V_10 -> V_21 = V_76 ;
if ( F_7 ( V_35 -> V_41 , V_22 , V_10 ) < 0 ) {
F_5 ( V_35 -> V_41 ) ;
V_35 -> V_41 = - 1 ;
printf ( L_5 ) ;
return ( 0 ) ;
}
return ( 1 ) ;
}
static int F_21 ( T_5 * V_28 , const void * V_78 ,
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
V_35 -> V_80 = F_22 ( V_35 -> V_80 , V_35 -> V_81 + V_12 ) ;
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
if ( F_7 ( V_35 -> V_41 , V_53 , & V_33 ) < 0 ) {
printf ( L_8 ) ;
return ( 0 ) ;
}
return ( 1 ) ;
}
static int F_23 ( T_5 * V_28 , unsigned char * V_83 )
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
if ( F_7 ( V_35 -> V_41 , V_53 , & V_33 ) < 0 ) {
printf ( L_10 ) ;
return ( 0 ) ;
}
return 1 ;
}
memcpy ( V_83 , V_35 -> V_82 , V_28 -> V_76 -> V_84 ) ;
return ( V_57 ) ;
}
static int F_24 ( T_5 * V_28 )
{
int V_57 = 1 ;
struct V_34 * V_35 = V_28 -> V_75 ;
struct V_9 * V_10 = & V_35 -> V_37 ;
if ( V_35 -> V_41 < 0 ) {
printf ( L_11 ) ;
return ( 0 ) ;
}
if ( V_35 -> V_80 ) {
F_25 ( V_35 -> V_80 ) ;
V_35 -> V_80 = NULL ;
V_35 -> V_81 = 0 ;
}
if ( V_35 -> V_85 )
return 1 ;
if ( F_7 ( V_35 -> V_41 , V_23 , & V_10 -> V_24 ) < 0 ) {
printf ( L_12 ) ;
V_57 = 0 ;
} else {
V_57 = 1 ;
}
F_5 ( V_35 -> V_41 ) ;
V_35 -> V_41 = - 1 ;
return ( V_57 ) ;
}
static int F_26 ( T_5 * V_86 , const T_5 * V_87 )
{
struct V_34 * V_88 = V_87 -> V_75 ;
struct V_34 * V_89 = V_86 -> V_75 ;
memcpy ( V_89 , V_88 , sizeof( struct V_34 ) ) ;
if ( V_88 -> V_81 != 0 ) {
V_89 -> V_80 = F_27 ( V_88 -> V_81 ) ;
memcpy ( V_89 -> V_80 , V_88 -> V_80 , V_88 -> V_81 ) ;
}
V_89 -> V_85 = 1 ;
return 1 ;
}
static int
F_28 ( T_3 * V_58 , const T_6 * * V_76 ,
const int * * V_7 , int V_17 )
{
if ( ! V_76 )
return ( F_12 ( V_7 ) ) ;
switch ( V_17 ) {
#ifdef F_13
case V_90 :
* V_76 = & V_91 ;
break;
case V_92 :
* V_76 = & V_93 ;
break;
default:
#endif
* V_76 = NULL ;
break;
}
return ( * V_76 != NULL ) ;
}
static int
F_29 ( const T_7 * V_94 , struct V_95 * V_96 )
{
int V_11 , V_97 , V_98 ;
T_8 V_99 , V_100 ;
T_9 * V_101 ;
V_96 -> V_102 = NULL ;
V_96 -> V_103 = 0 ;
V_100 = F_30 ( V_94 ) ;
V_99 = ( V_100 + 7 ) / 8 ;
V_101 = malloc ( V_99 ) ;
if ( V_101 == NULL )
return ( 1 ) ;
memset ( V_101 , 0 , V_99 ) ;
V_96 -> V_102 = ( V_14 ) V_101 ;
V_96 -> V_103 = V_100 ;
for ( V_11 = 0 , V_97 = 0 ; V_11 < V_94 -> V_104 ; V_11 ++ ) {
for ( V_98 = 0 ; V_98 < V_105 / 8 ; V_98 ++ ) {
if ( ( V_97 + V_98 ) >= V_99 )
return ( 0 ) ;
V_101 [ V_97 + V_98 ] = V_94 -> V_106 [ V_11 ] >> ( V_98 * 8 ) ;
}
V_97 += V_105 / 8 ;
}
return ( 0 ) ;
}
static int
F_31 ( struct V_95 * V_96 , T_7 * V_94 )
{
T_10 * V_107 ;
int V_11 , V_99 ;
V_99 = ( V_96 -> V_103 + 7 ) / 8 ;
if ( V_99 == 0 )
return ( - 1 ) ;
if ( ( V_107 = ( T_10 * ) malloc ( V_99 ) ) == NULL )
return ( - 1 ) ;
for ( V_11 = 0 ; V_11 < V_99 ; V_11 ++ )
V_107 [ V_11 ] = V_96 -> V_102 [ V_99 - V_11 - 1 ] ;
F_32 ( V_107 , V_99 , V_94 ) ;
free ( V_107 ) ;
return ( 0 ) ;
}
static void
F_33 ( struct V_108 * V_109 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_109 -> V_110 + V_109 -> V_111 ; V_11 ++ ) {
if ( V_109 -> V_112 [ V_11 ] . V_102 )
free ( V_109 -> V_112 [ V_11 ] . V_102 ) ;
V_109 -> V_112 [ V_11 ] . V_102 = NULL ;
V_109 -> V_112 [ V_11 ] . V_103 = 0 ;
}
}
static int
F_34 ( struct V_108 * V_109 , int V_113 , T_7 * V_114 , int V_115 , T_7 * V_116 )
{
int V_1 , V_57 = - 1 ;
if ( ( V_1 = F_8 () ) < 0 )
return ( V_57 ) ;
if ( V_114 ) {
V_109 -> V_112 [ V_109 -> V_110 ] . V_102 = calloc ( V_113 , sizeof( char ) ) ;
V_109 -> V_112 [ V_109 -> V_110 ] . V_103 = V_113 * 8 ;
V_109 -> V_111 ++ ;
}
if ( V_116 ) {
V_109 -> V_112 [ V_109 -> V_110 + 1 ] . V_102 = calloc ( V_115 , sizeof( char ) ) ;
V_109 -> V_112 [ V_109 -> V_110 + 1 ] . V_103 = V_115 * 8 ;
V_109 -> V_111 ++ ;
}
if ( F_7 ( V_1 , V_117 , V_109 ) == 0 ) {
if ( V_114 )
F_31 ( & V_109 -> V_112 [ V_109 -> V_110 ] , V_114 ) ;
if ( V_116 )
F_31 ( & V_109 -> V_112 [ V_109 -> V_110 + 1 ] , V_116 ) ;
V_57 = 0 ;
}
return ( V_57 ) ;
}
static int
F_35 ( T_7 * V_114 , const T_7 * V_94 , const T_7 * V_118 ,
const T_7 * V_119 , T_11 * V_28 , T_12 * V_120 )
{
struct V_108 V_109 ;
int V_57 = 1 ;
if ( V_121 == 0 ) {
V_57 = F_36 ( V_114 , V_94 , V_118 , V_119 , V_28 ) ;
return ( V_57 ) ;
}
memset ( & V_109 , 0 , sizeof V_109 ) ;
V_109 . V_122 = V_123 ;
if ( F_29 ( V_94 , & V_109 . V_112 [ 0 ] ) )
goto V_124;
if ( F_29 ( V_118 , & V_109 . V_112 [ 1 ] ) )
goto V_124;
if ( F_29 ( V_119 , & V_109 . V_112 [ 2 ] ) )
goto V_124;
V_109 . V_110 = 3 ;
if ( F_34 ( & V_109 , F_37 ( V_119 ) , V_114 , 0 , NULL ) ) {
const T_13 * V_125 = F_38 () ;
printf ( L_13 ) ;
V_57 = V_125 -> V_126 ( V_114 , V_94 , V_118 , V_119 , V_28 , V_120 ) ;
} else if ( V_127 == V_109 . V_128 ) {
const T_13 * V_125 = F_38 () ;
printf ( L_14 ) ;
V_57 = V_125 -> V_126 ( V_114 , V_94 , V_118 , V_119 , V_28 , V_120 ) ;
}
V_124:
F_33 ( & V_109 ) ;
return ( V_57 ) ;
}
static int
F_39 ( T_7 * V_129 , const T_7 * V_130 , T_14 * V_131 , T_11 * V_28 )
{
int V_114 ;
V_28 = F_40 () ;
V_114 = F_35 ( V_129 , V_130 , V_131 -> V_106 , V_131 -> V_132 , V_28 , NULL ) ;
F_41 ( V_28 ) ;
return ( V_114 ) ;
}
static int
F_42 ( T_7 * V_129 , const T_7 * V_130 , T_14 * V_131 , T_11 * V_28 )
{
struct V_108 V_109 ;
int V_57 = 1 ;
if ( ! V_131 -> V_118 || ! V_131 -> V_133 || ! V_131 -> V_134 || ! V_131 -> V_135 || ! V_131 -> V_136 ) {
return ( 0 ) ;
}
memset ( & V_109 , 0 , sizeof V_109 ) ;
V_109 . V_122 = V_137 ;
if ( F_29 ( V_131 -> V_118 , & V_109 . V_112 [ 0 ] ) )
goto V_124;
if ( F_29 ( V_131 -> V_133 , & V_109 . V_112 [ 1 ] ) )
goto V_124;
if ( F_29 ( V_130 , & V_109 . V_112 [ 2 ] ) )
goto V_124;
if ( F_29 ( V_131 -> V_134 , & V_109 . V_112 [ 3 ] ) )
goto V_124;
if ( F_29 ( V_131 -> V_135 , & V_109 . V_112 [ 4 ] ) )
goto V_124;
if ( F_29 ( V_131 -> V_136 , & V_109 . V_112 [ 5 ] ) )
goto V_124;
V_109 . V_110 = 6 ;
if ( F_34 ( & V_109 , F_37 ( V_131 -> V_132 ) , V_129 , 0 , NULL ) ) {
const T_13 * V_125 = F_38 () ;
printf ( L_15 ) ;
V_57 = (* V_125 -> V_138 )( V_129 , V_130 , V_131 , V_28 ) ;
} else if ( V_127 == V_109 . V_128 ) {
const T_13 * V_125 = F_38 () ;
printf ( L_14 ) ;
V_57 = (* V_125 -> V_138 )( V_129 , V_130 , V_131 , V_28 ) ;
}
V_124:
F_33 ( & V_109 ) ;
return ( V_57 ) ;
}
static int
F_43 ( T_15 * V_139 , T_7 * V_114 , T_7 * V_94 , const T_7 * V_118 ,
const T_7 * V_119 , T_11 * V_28 , T_12 * V_140 )
{
return ( F_35 ( V_114 , V_94 , V_118 , V_119 , V_28 , V_140 ) ) ;
}
static int
F_44 ( T_15 * V_139 , T_7 * V_141 , T_7 * V_142 ,
T_7 * V_143 , T_7 * V_144 , T_7 * V_145 , T_7 * V_118 ,
T_11 * V_28 , T_12 * V_146 )
{
T_7 V_147 ;
int V_57 = 0 ;
F_45 ( & V_147 ) ;
V_57 = 0 ;
if ( ! V_139 -> V_125 -> V_126 ( V_139 , V_141 , V_139 -> V_142 , V_143 , V_139 -> V_118 , V_28 , V_146 ) )
goto V_124;
if ( ! V_139 -> V_125 -> V_126 ( V_139 , & V_147 , V_139 -> V_144 , V_145 , V_139 -> V_118 , V_28 , V_146 ) )
goto V_124;
if ( ! F_46 ( V_143 , V_141 , & V_147 , V_139 -> V_118 , V_28 ) )
goto V_124;
F_47 ( V_141 , V_143 ) ;
V_57 = 1 ;
V_124:
F_48 ( & V_147 ) ;
return ( V_57 ) ;
}
static T_16 *
F_49 ( const unsigned char * V_148 , int V_149 , T_15 * V_139 )
{
struct V_108 V_109 ;
T_7 * V_114 = NULL , * V_116 = NULL ;
T_16 * V_150 = NULL ;
if ( ( V_114 = F_50 () ) == NULL )
goto V_124;
if ( ( V_116 = F_50 () ) == NULL ) {
F_48 ( V_114 ) ;
goto V_124;
}
memset ( & V_109 , 0 , sizeof V_109 ) ;
V_109 . V_122 = V_151 ;
V_109 . V_112 [ 0 ] . V_102 = ( V_14 ) V_148 ;
V_109 . V_112 [ 0 ] . V_103 = V_149 * 8 ;
if ( F_29 ( V_139 -> V_118 , & V_109 . V_112 [ 1 ] ) )
goto V_124;
if ( F_29 ( V_139 -> V_133 , & V_109 . V_112 [ 2 ] ) )
goto V_124;
if ( F_29 ( V_139 -> V_142 , & V_109 . V_112 [ 3 ] ) )
goto V_124;
if ( F_29 ( V_139 -> V_152 , & V_109 . V_112 [ 4 ] ) )
goto V_124;
V_109 . V_110 = 5 ;
if ( F_34 ( & V_109 , F_37 ( V_139 -> V_133 ) , V_114 ,
F_37 ( V_139 -> V_133 ) , V_116 ) == 0 ) {
V_150 = F_51 () ;
V_150 -> V_114 = V_114 ;
V_150 -> V_116 = V_116 ;
} else {
const T_17 * V_125 = F_52 () ;
F_48 ( V_114 ) ;
F_48 ( V_116 ) ;
V_150 = ( V_125 -> V_153 ) ( V_148 , V_149 , V_139 ) ;
}
V_124:
V_109 . V_112 [ 0 ] . V_102 = NULL ;
F_33 ( & V_109 ) ;
return ( V_150 ) ;
}
static int
F_53 ( const unsigned char * V_148 , int V_149 ,
T_16 * V_154 , T_15 * V_139 )
{
struct V_108 V_109 ;
int V_150 = 1 ;
memset ( & V_109 , 0 , sizeof V_109 ) ;
V_109 . V_122 = V_155 ;
V_109 . V_112 [ 0 ] . V_102 = ( V_14 ) V_148 ;
V_109 . V_112 [ 0 ] . V_103 = V_149 * 8 ;
if ( F_29 ( V_139 -> V_118 , & V_109 . V_112 [ 1 ] ) )
goto V_124;
if ( F_29 ( V_139 -> V_133 , & V_109 . V_112 [ 2 ] ) )
goto V_124;
if ( F_29 ( V_139 -> V_142 , & V_109 . V_112 [ 3 ] ) )
goto V_124;
if ( F_29 ( V_139 -> V_144 , & V_109 . V_112 [ 4 ] ) )
goto V_124;
if ( F_29 ( V_154 -> V_114 , & V_109 . V_112 [ 5 ] ) )
goto V_124;
if ( F_29 ( V_154 -> V_116 , & V_109 . V_112 [ 6 ] ) )
goto V_124;
V_109 . V_110 = 7 ;
if ( F_34 ( & V_109 , 0 , NULL , 0 , NULL ) == 0 ) {
if( 0 != V_109 . V_128 ) V_150 = 0 ;
} else {
const T_17 * V_125 = F_52 () ;
V_150 = ( V_125 -> V_156 ) ( V_148 , V_149 , V_154 , V_139 ) ;
}
V_124:
V_109 . V_112 [ 0 ] . V_102 = NULL ;
F_33 ( & V_109 ) ;
return ( V_150 ) ;
}
static int
F_54 ( const T_18 * V_157 , T_7 * V_114 , const T_7 * V_94 ,
const T_7 * V_118 , const T_7 * V_119 , T_11 * V_28 ,
T_12 * V_140 )
{
return ( F_35 ( V_114 , V_94 , V_118 , V_119 , V_28 , V_140 ) ) ;
}
static int
F_55 ( unsigned char * V_13 , const T_7 * V_144 , T_18 * V_157 )
{
struct V_108 V_109 ;
int V_158 = 1 ;
int V_1 , V_20 ;
if ( ( V_1 = F_8 () ) < 0 ) {
const T_19 * V_125 = F_56 () ;
return ( ( V_125 -> V_159 ) ( V_13 , V_144 , V_157 ) ) ;
}
V_20 = F_30 ( V_157 -> V_118 ) ;
memset ( & V_109 , 0 , sizeof V_109 ) ;
V_109 . V_122 = V_160 ;
if ( F_29 ( V_157 -> V_152 , & V_109 . V_112 [ 0 ] ) )
goto V_124;
if ( F_29 ( V_144 , & V_109 . V_112 [ 1 ] ) )
goto V_124;
if ( F_29 ( V_157 -> V_118 , & V_109 . V_112 [ 2 ] ) )
goto V_124;
V_109 . V_110 = 3 ;
V_109 . V_112 [ 3 ] . V_102 = ( V_14 ) V_13 ;
V_109 . V_112 [ 3 ] . V_103 = V_20 * 8 ;
V_109 . V_111 = 1 ;
if ( F_7 ( V_1 , V_117 , & V_109 ) == - 1 ) {
const T_19 * V_125 = F_56 () ;
V_158 = ( V_125 -> V_159 ) ( V_13 , V_144 , V_157 ) ;
}
V_124:
V_109 . V_112 [ 3 ] . V_102 = NULL ;
F_33 ( & V_109 ) ;
return ( V_158 ) ;
}
static int
F_57 ( T_3 * V_58 , int V_161 , long V_11 , void * V_118 , void (* F_58)( void ) )
{
#ifdef F_59
struct V_162 V_163 = V_164 ;
#endif
switch ( V_161 ) {
default:
#ifdef F_59
F_60 ( V_165 , & V_163 ,
L_16 , V_161 ) ;
#else
F_61 ( V_165 , L_16 , V_161 ) ;
#endif
break;
}
return ( 1 ) ;
}
void
F_1 ( void )
{
T_3 * V_166 = F_62 () ;
int V_1 ;
if ( V_166 == NULL )
return;
if ( ( V_1 = F_6 () ) < 0 ) {
F_63 ( V_166 ) ;
return;
}
if ( F_7 ( V_1 , V_167 , & V_121 ) == - 1 ) {
F_5 ( V_1 ) ;
F_63 ( V_166 ) ;
return;
}
F_5 ( V_1 ) ;
if ( ! F_64 ( V_166 , L_17 ) ||
! F_65 ( V_166 , L_18 ) ||
! F_66 ( V_166 , F_17 ) ||
! F_67 ( V_166 , F_28 ) ||
! F_68 ( V_166 , F_57 ) ||
! F_69 ( V_166 , V_168 ) ) {
F_63 ( V_166 ) ;
return;
}
if ( F_70 ( V_166 , & V_169 ) ) {
const T_13 * V_170 = F_38 () ;
V_169 . V_126 = V_170 -> V_126 ;
V_169 . V_138 = V_170 -> V_138 ;
V_169 . V_171 = V_170 -> V_171 ;
V_169 . V_172 = V_170 -> V_172 ;
V_169 . V_173 = V_170 -> V_173 ;
V_169 . V_174 = V_170 -> V_174 ;
if ( V_121 & V_175 ) {
V_169 . V_126 = F_35 ;
if ( V_121 & V_176 )
V_169 . V_138 =
F_42 ;
else
V_169 . V_138 =
F_39 ;
}
}
if ( F_71 ( V_166 , & V_177 ) ) {
const T_17 * V_125 = F_52 () ;
memcpy ( & V_177 , V_125 , sizeof( T_17 ) ) ;
if ( V_121 & V_178 )
V_177 . V_153 = F_49 ;
if ( V_121 & V_175 ) {
V_177 . V_126 = F_43 ;
V_177 . V_179 = F_44 ;
}
if ( V_121 & V_180 )
V_177 . V_156 = F_53 ;
}
if ( F_72 ( V_166 , & V_181 ) ) {
const T_19 * V_182 = F_56 () ;
V_181 . V_183 = V_182 -> V_183 ;
V_181 . V_159 = V_182 -> V_159 ;
V_181 . V_126 = V_182 -> V_126 ;
if ( V_121 & V_175 ) {
V_181 . V_126 = F_54 ;
if ( V_121 & V_184 )
V_181 . V_159 =
F_55 ;
}
}
F_73 ( V_166 ) ;
F_63 ( V_166 ) ;
F_74 () ;
}

void F_1 ( void )
{
return;
}
static int F_2 ( void )
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
static int F_6 ( void )
{
int V_1 , V_4 ;
if ( ( V_1 = F_2 () ) == - 1 )
return ( - 1 ) ;
# ifndef F_7
if ( F_8 ( V_1 , V_5 , & V_4 ) == - 1 )
return ( - 1 ) ;
if ( F_4 ( V_4 , V_3 , 1 ) == - 1 ) {
F_5 ( V_4 ) ;
return ( - 1 ) ;
}
# else
V_4 = V_1 ;
# endif
return ( V_4 ) ;
}
static void F_9 ( int V_1 )
{
# ifndef F_7
F_5 ( V_1 ) ;
# endif
}
static int F_10 ( void )
{
static int V_1 = - 1 ;
if ( V_1 == - 1 )
V_1 = F_6 () ;
return V_1 ;
}
static int F_11 ( const int * * V_6 )
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
static int F_12 ( const int * * V_6 )
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
static int F_13 ( const int * * V_7 )
{
return ( F_11 ( V_7 ) ) ;
}
static int F_14 ( const int * * V_7 )
{
# ifdef F_15
return ( F_12 ( V_7 ) ) ;
# else
* V_7 = NULL ;
return ( 0 ) ;
# endif
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
static int F_18 ( T_1 * V_28 )
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
# ifdef F_20
case V_75 :
* V_19 = & V_76 ;
break;
case V_77 :
* V_19 = & V_78 ;
break;
case V_79 :
* V_19 = & V_80 ;
break;
# endif
default:
* V_19 = NULL ;
break;
}
return ( * V_19 != NULL ) ;
}
static int F_21 ( int V_17 )
{
int V_11 ;
for ( V_11 = 0 ; V_26 [ V_11 ] . V_16 ; V_11 ++ )
if ( V_26 [ V_11 ] . V_17 == V_17 )
return ( V_26 [ V_11 ] . V_16 ) ;
return ( 0 ) ;
}
static int F_22 ( int V_17 )
{
int V_11 ;
for ( V_11 = 0 ; V_26 [ V_11 ] . V_16 ; V_11 ++ )
if ( V_26 [ V_11 ] . V_17 == V_17 )
return V_26 [ V_11 ] . V_20 ;
return ( 0 ) ;
}
static int F_23 ( T_5 * V_28 )
{
struct V_34 * V_35 = V_28 -> V_81 ;
struct V_9 * V_10 = & V_35 -> V_37 ;
int V_82 ;
if ( ( V_82 = F_21 ( V_28 -> V_82 -> type ) ) == V_18 ) {
printf ( L_3 ) ;
return ( 0 ) ;
}
memset ( V_35 , 0 , sizeof( struct V_34 ) ) ;
if ( ( V_35 -> V_41 = F_6 () ) < 0 ) {
printf ( L_4 ) ;
return ( 0 ) ;
}
V_10 -> V_25 = V_35 -> V_83 ;
V_10 -> V_27 = F_22 ( V_28 -> V_82 -> type ) ;
V_10 -> V_21 = V_82 ;
if ( F_8 ( V_35 -> V_41 , V_22 , V_10 ) < 0 ) {
F_9 ( V_35 -> V_41 ) ;
V_35 -> V_41 = - 1 ;
printf ( L_5 ) ;
return ( 0 ) ;
}
return ( 1 ) ;
}
static int F_24 ( T_5 * V_28 , const void * V_84 ,
T_2 V_12 )
{
struct V_32 V_33 ;
struct V_34 * V_35 = V_28 -> V_81 ;
struct V_9 * V_10 = & V_35 -> V_37 ;
if ( ! V_84 || V_35 -> V_41 < 0 ) {
printf ( L_6 ) ;
return ( 0 ) ;
}
if ( ! V_12 ) {
return ( 0 ) ;
}
if ( ! ( V_28 -> V_43 & V_85 ) ) {
V_35 -> V_86 =
F_25 ( V_35 -> V_86 , V_35 -> V_87 + V_12 ) ;
if ( ! V_35 -> V_86 ) {
printf ( L_7 ) ;
return ( 0 ) ;
}
memcpy ( V_35 -> V_86 + V_35 -> V_87 , V_84 , V_12 ) ;
V_35 -> V_87 += V_12 ;
return ( 1 ) ;
}
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_24 = V_10 -> V_24 ;
V_33 . V_43 = 0 ;
V_33 . V_44 = V_12 ;
V_33 . V_45 = ( V_14 ) V_84 ;
V_33 . V_46 = NULL ;
V_33 . V_21 = ( V_14 ) V_35 -> V_88 ;
if ( F_8 ( V_35 -> V_41 , V_53 , & V_33 ) < 0 ) {
printf ( L_8 ) ;
return ( 0 ) ;
}
return ( 1 ) ;
}
static int F_26 ( T_5 * V_28 , unsigned char * V_89 )
{
struct V_32 V_33 ;
struct V_34 * V_35 = V_28 -> V_81 ;
struct V_9 * V_10 = & V_35 -> V_37 ;
int V_57 = 1 ;
if ( ! V_89 || V_35 -> V_41 < 0 ) {
printf ( L_9 ) ;
return ( 0 ) ;
}
if ( ! ( V_28 -> V_43 & V_85 ) ) {
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_24 = V_10 -> V_24 ;
V_33 . V_43 = 0 ;
V_33 . V_44 = V_35 -> V_87 ;
V_33 . V_45 = V_35 -> V_86 ;
V_33 . V_46 = NULL ;
V_33 . V_21 = ( V_14 ) V_89 ;
if ( F_8 ( V_35 -> V_41 , V_53 , & V_33 ) < 0 ) {
printf ( L_10 ) ;
return ( 0 ) ;
}
return 1 ;
}
memcpy ( V_89 , V_35 -> V_88 , V_28 -> V_82 -> V_90 ) ;
return ( V_57 ) ;
}
static int F_27 ( T_5 * V_28 )
{
int V_57 = 1 ;
struct V_34 * V_35 = V_28 -> V_81 ;
struct V_9 * V_10 = & V_35 -> V_37 ;
if ( V_35 == NULL )
return 0 ;
if ( V_35 -> V_41 < 0 ) {
printf ( L_11 ) ;
return ( 0 ) ;
}
if ( V_35 -> V_86 ) {
F_28 ( V_35 -> V_86 ) ;
V_35 -> V_86 = NULL ;
V_35 -> V_87 = 0 ;
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
static int F_29 ( T_5 * V_91 , const T_5 * V_92 )
{
struct V_34 * V_93 = V_92 -> V_81 ;
struct V_34 * V_94 = V_91 -> V_81 ;
struct V_9 * V_10 ;
int V_82 ;
if ( V_94 == NULL || V_93 == NULL )
return 1 ;
memcpy ( V_94 , V_93 , sizeof( struct V_34 ) ) ;
V_10 = & V_94 -> V_37 ;
V_82 = F_21 ( V_91 -> V_82 -> type ) ;
V_10 -> V_25 = V_94 -> V_83 ;
V_10 -> V_27 = F_22 ( V_91 -> V_82 -> type ) ;
V_10 -> V_21 = V_82 ;
V_94 -> V_41 = F_6 () ;
if ( F_8 ( V_94 -> V_41 , V_22 , V_10 ) < 0 ) {
F_9 ( V_94 -> V_41 ) ;
V_94 -> V_41 = - 1 ;
printf ( L_5 ) ;
return ( 0 ) ;
}
if ( V_93 -> V_87 != 0 ) {
if ( V_93 -> V_86 != NULL ) {
V_94 -> V_86 = F_30 ( V_93 -> V_87 ) ;
memcpy ( V_94 -> V_86 , V_93 -> V_86 , V_93 -> V_87 ) ;
V_94 -> V_87 = V_93 -> V_87 ;
}
}
return 1 ;
}
static int
F_31 ( T_3 * V_58 , const T_6 * * V_82 ,
const int * * V_7 , int V_17 )
{
if ( ! V_82 )
return ( F_14 ( V_7 ) ) ;
switch ( V_17 ) {
# ifdef F_15
case V_95 :
* V_82 = & V_96 ;
break;
case V_97 :
* V_82 = & V_98 ;
break;
default:
# endif
* V_82 = NULL ;
break;
}
return ( * V_82 != NULL ) ;
}
static int F_32 ( const T_7 * V_99 , struct V_100 * V_101 )
{
int V_11 , V_102 , V_103 ;
T_8 V_104 , V_105 ;
T_9 * V_106 ;
V_101 -> V_107 = NULL ;
V_101 -> V_108 = 0 ;
V_105 = F_33 ( V_99 ) ;
V_104 = ( V_105 + 7 ) / 8 ;
V_106 = malloc ( V_104 ) ;
if ( V_106 == NULL )
return ( 1 ) ;
memset ( V_106 , 0 , V_104 ) ;
V_101 -> V_107 = ( V_14 ) V_106 ;
V_101 -> V_108 = V_105 ;
for ( V_11 = 0 , V_102 = 0 ; V_11 < V_99 -> V_109 ; V_11 ++ ) {
for ( V_103 = 0 ; V_103 < V_110 / 8 ; V_103 ++ ) {
if ( ( V_102 + V_103 ) >= V_104 )
return ( 0 ) ;
V_106 [ V_102 + V_103 ] = V_99 -> V_111 [ V_11 ] >> ( V_103 * 8 ) ;
}
V_102 += V_110 / 8 ;
}
return ( 0 ) ;
}
static int F_34 ( struct V_100 * V_101 , T_7 * V_99 )
{
T_10 * V_112 ;
int V_11 , V_104 ;
V_104 = ( V_101 -> V_108 + 7 ) / 8 ;
if ( V_104 == 0 )
return ( - 1 ) ;
if ( ( V_112 = ( T_10 * ) malloc ( V_104 ) ) == NULL )
return ( - 1 ) ;
for ( V_11 = 0 ; V_11 < V_104 ; V_11 ++ )
V_112 [ V_11 ] = V_101 -> V_107 [ V_104 - V_11 - 1 ] ;
F_35 ( V_112 , V_104 , V_99 ) ;
free ( V_112 ) ;
return ( 0 ) ;
}
static void F_36 ( struct V_113 * V_114 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_114 -> V_115 + V_114 -> V_116 ; V_11 ++ ) {
if ( V_114 -> V_117 [ V_11 ] . V_107 )
free ( V_114 -> V_117 [ V_11 ] . V_107 ) ;
V_114 -> V_117 [ V_11 ] . V_107 = NULL ;
V_114 -> V_117 [ V_11 ] . V_108 = 0 ;
}
}
static int
F_37 ( struct V_113 * V_114 , int V_118 , T_7 * V_119 , int V_120 ,
T_7 * V_121 )
{
int V_1 , V_57 = - 1 ;
if ( ( V_1 = F_10 () ) < 0 )
return ( V_57 ) ;
if ( V_119 ) {
V_114 -> V_117 [ V_114 -> V_115 ] . V_107 = calloc ( V_118 , sizeof( char ) ) ;
V_114 -> V_117 [ V_114 -> V_115 ] . V_108 = V_118 * 8 ;
V_114 -> V_116 ++ ;
}
if ( V_121 ) {
V_114 -> V_117 [ V_114 -> V_115 + 1 ] . V_107 =
calloc ( V_120 , sizeof( char ) ) ;
V_114 -> V_117 [ V_114 -> V_115 + 1 ] . V_108 = V_120 * 8 ;
V_114 -> V_116 ++ ;
}
if ( F_8 ( V_1 , V_122 , V_114 ) == 0 ) {
if ( V_119 )
F_34 ( & V_114 -> V_117 [ V_114 -> V_115 ] , V_119 ) ;
if ( V_121 )
F_34 ( & V_114 -> V_117 [ V_114 -> V_115 + 1 ] , V_121 ) ;
V_57 = 0 ;
}
return ( V_57 ) ;
}
static int
F_38 ( T_7 * V_119 , const T_7 * V_99 , const T_7 * V_123 ,
const T_7 * V_124 , T_11 * V_28 , T_12 * V_125 )
{
struct V_113 V_114 ;
int V_57 = 1 ;
if ( V_126 == 0 ) {
V_57 = F_39 ( V_119 , V_99 , V_123 , V_124 , V_28 ) ;
return ( V_57 ) ;
}
memset ( & V_114 , 0 , sizeof V_114 ) ;
V_114 . V_127 = V_128 ;
if ( F_32 ( V_99 , & V_114 . V_117 [ 0 ] ) )
goto V_129;
if ( F_32 ( V_123 , & V_114 . V_117 [ 1 ] ) )
goto V_129;
if ( F_32 ( V_124 , & V_114 . V_117 [ 2 ] ) )
goto V_129;
V_114 . V_115 = 3 ;
if ( F_37 ( & V_114 , F_40 ( V_124 ) , V_119 , 0 , NULL ) ) {
const T_13 * V_130 = F_41 () ;
printf ( L_13 ) ;
V_57 = V_130 -> V_131 ( V_119 , V_99 , V_123 , V_124 , V_28 , V_125 ) ;
} else if ( V_132 == V_114 . V_133 ) {
const T_13 * V_130 = F_41 () ;
printf ( L_14 ) ;
V_57 = V_130 -> V_131 ( V_119 , V_99 , V_123 , V_124 , V_28 , V_125 ) ;
}
V_129:
F_36 ( & V_114 ) ;
return ( V_57 ) ;
}
static int
F_42 ( T_7 * V_134 , const T_7 * V_135 , T_14 * V_136 ,
T_11 * V_28 )
{
int V_119 ;
V_28 = F_43 () ;
V_119 = F_38 ( V_134 , V_135 , V_136 -> V_111 , V_136 -> V_137 , V_28 , NULL ) ;
F_44 ( V_28 ) ;
return ( V_119 ) ;
}
static int
F_45 ( T_7 * V_134 , const T_7 * V_135 , T_14 * V_136 , T_11 * V_28 )
{
struct V_113 V_114 ;
int V_57 = 1 ;
if ( ! V_136 -> V_123 || ! V_136 -> V_138 || ! V_136 -> V_139 || ! V_136 -> V_140 || ! V_136 -> V_141 ) {
return ( 0 ) ;
}
memset ( & V_114 , 0 , sizeof V_114 ) ;
V_114 . V_127 = V_142 ;
if ( F_32 ( V_136 -> V_123 , & V_114 . V_117 [ 0 ] ) )
goto V_129;
if ( F_32 ( V_136 -> V_138 , & V_114 . V_117 [ 1 ] ) )
goto V_129;
if ( F_32 ( V_135 , & V_114 . V_117 [ 2 ] ) )
goto V_129;
if ( F_32 ( V_136 -> V_139 , & V_114 . V_117 [ 3 ] ) )
goto V_129;
if ( F_32 ( V_136 -> V_140 , & V_114 . V_117 [ 4 ] ) )
goto V_129;
if ( F_32 ( V_136 -> V_141 , & V_114 . V_117 [ 5 ] ) )
goto V_129;
V_114 . V_115 = 6 ;
if ( F_37 ( & V_114 , F_40 ( V_136 -> V_137 ) , V_134 , 0 , NULL ) ) {
const T_13 * V_130 = F_41 () ;
printf ( L_15 ) ;
V_57 = (* V_130 -> V_143 ) ( V_134 , V_135 , V_136 , V_28 ) ;
} else if ( V_132 == V_114 . V_133 ) {
const T_13 * V_130 = F_41 () ;
printf ( L_14 ) ;
V_57 = (* V_130 -> V_143 ) ( V_134 , V_135 , V_136 , V_28 ) ;
}
V_129:
F_36 ( & V_114 ) ;
return ( V_57 ) ;
}
static int
F_46 ( T_15 * V_144 , T_7 * V_119 , T_7 * V_99 , const T_7 * V_123 ,
const T_7 * V_124 , T_11 * V_28 , T_12 * V_145 )
{
return ( F_38 ( V_119 , V_99 , V_123 , V_124 , V_28 , V_145 ) ) ;
}
static int
F_47 ( T_15 * V_144 , T_7 * V_146 , T_7 * V_147 ,
T_7 * V_148 , T_7 * V_149 , T_7 * V_150 , T_7 * V_123 ,
T_11 * V_28 , T_12 * V_151 )
{
T_7 V_152 ;
int V_57 = 0 ;
F_48 ( & V_152 ) ;
V_57 = 0 ;
if ( ! V_144 -> V_130 -> V_131 ( V_144 , V_146 , V_144 -> V_147 , V_148 , V_144 -> V_123 , V_28 , V_151 ) )
goto V_129;
if ( ! V_144 -> V_130 -> V_131 ( V_144 , & V_152 , V_144 -> V_149 , V_150 , V_144 -> V_123 , V_28 , V_151 ) )
goto V_129;
if ( ! F_49 ( V_148 , V_146 , & V_152 , V_144 -> V_123 , V_28 ) )
goto V_129;
F_50 ( V_146 , V_148 ) ;
V_57 = 1 ;
V_129:
F_51 ( & V_152 ) ;
return ( V_57 ) ;
}
static T_16 * F_52 ( const unsigned char * V_153 , int V_154 ,
T_15 * V_144 )
{
struct V_113 V_114 ;
T_7 * V_119 = NULL , * V_121 = NULL ;
T_16 * V_155 = NULL ;
if ( ( V_119 = F_53 () ) == NULL )
goto V_129;
if ( ( V_121 = F_53 () ) == NULL ) {
F_51 ( V_119 ) ;
goto V_129;
}
memset ( & V_114 , 0 , sizeof V_114 ) ;
V_114 . V_127 = V_156 ;
V_114 . V_117 [ 0 ] . V_107 = ( V_14 ) V_153 ;
V_114 . V_117 [ 0 ] . V_108 = V_154 * 8 ;
if ( F_32 ( V_144 -> V_123 , & V_114 . V_117 [ 1 ] ) )
goto V_129;
if ( F_32 ( V_144 -> V_138 , & V_114 . V_117 [ 2 ] ) )
goto V_129;
if ( F_32 ( V_144 -> V_147 , & V_114 . V_117 [ 3 ] ) )
goto V_129;
if ( F_32 ( V_144 -> V_157 , & V_114 . V_117 [ 4 ] ) )
goto V_129;
V_114 . V_115 = 5 ;
if ( F_37 ( & V_114 , F_40 ( V_144 -> V_138 ) , V_119 ,
F_40 ( V_144 -> V_138 ) , V_121 ) == 0 ) {
V_155 = F_54 () ;
V_155 -> V_119 = V_119 ;
V_155 -> V_121 = V_121 ;
} else {
const T_17 * V_130 = F_55 () ;
F_51 ( V_119 ) ;
F_51 ( V_121 ) ;
V_155 = ( V_130 -> V_158 ) ( V_153 , V_154 , V_144 ) ;
}
V_129:
V_114 . V_117 [ 0 ] . V_107 = NULL ;
F_36 ( & V_114 ) ;
return ( V_155 ) ;
}
static int
F_56 ( const unsigned char * V_153 , int V_154 ,
T_16 * V_159 , T_15 * V_144 )
{
struct V_113 V_114 ;
int V_155 = 1 ;
memset ( & V_114 , 0 , sizeof V_114 ) ;
V_114 . V_127 = V_160 ;
V_114 . V_117 [ 0 ] . V_107 = ( V_14 ) V_153 ;
V_114 . V_117 [ 0 ] . V_108 = V_154 * 8 ;
if ( F_32 ( V_144 -> V_123 , & V_114 . V_117 [ 1 ] ) )
goto V_129;
if ( F_32 ( V_144 -> V_138 , & V_114 . V_117 [ 2 ] ) )
goto V_129;
if ( F_32 ( V_144 -> V_147 , & V_114 . V_117 [ 3 ] ) )
goto V_129;
if ( F_32 ( V_144 -> V_149 , & V_114 . V_117 [ 4 ] ) )
goto V_129;
if ( F_32 ( V_159 -> V_119 , & V_114 . V_117 [ 5 ] ) )
goto V_129;
if ( F_32 ( V_159 -> V_121 , & V_114 . V_117 [ 6 ] ) )
goto V_129;
V_114 . V_115 = 7 ;
if ( F_37 ( & V_114 , 0 , NULL , 0 , NULL ) == 0 ) {
if ( 0 != V_114 . V_133 )
V_155 = 0 ;
} else {
const T_17 * V_130 = F_55 () ;
V_155 = ( V_130 -> V_161 ) ( V_153 , V_154 , V_159 , V_144 ) ;
}
V_129:
V_114 . V_117 [ 0 ] . V_107 = NULL ;
F_36 ( & V_114 ) ;
return ( V_155 ) ;
}
static int
F_57 ( const T_18 * V_162 , T_7 * V_119 , const T_7 * V_99 ,
const T_7 * V_123 , const T_7 * V_124 , T_11 * V_28 ,
T_12 * V_145 )
{
return ( F_38 ( V_119 , V_99 , V_123 , V_124 , V_28 , V_145 ) ) ;
}
static int
F_58 ( unsigned char * V_13 , const T_7 * V_149 , T_18 * V_162 )
{
struct V_113 V_114 ;
int V_163 = 1 ;
int V_1 , V_20 ;
if ( ( V_1 = F_10 () ) < 0 ) {
const T_19 * V_130 = F_59 () ;
return ( ( V_130 -> V_164 ) ( V_13 , V_149 , V_162 ) ) ;
}
V_20 = F_33 ( V_162 -> V_123 ) ;
memset ( & V_114 , 0 , sizeof V_114 ) ;
V_114 . V_127 = V_165 ;
if ( F_32 ( V_162 -> V_157 , & V_114 . V_117 [ 0 ] ) )
goto V_129;
if ( F_32 ( V_149 , & V_114 . V_117 [ 1 ] ) )
goto V_129;
if ( F_32 ( V_162 -> V_123 , & V_114 . V_117 [ 2 ] ) )
goto V_129;
V_114 . V_115 = 3 ;
V_114 . V_117 [ 3 ] . V_107 = ( V_14 ) V_13 ;
V_114 . V_117 [ 3 ] . V_108 = V_20 * 8 ;
V_114 . V_116 = 1 ;
if ( F_8 ( V_1 , V_122 , & V_114 ) == - 1 ) {
const T_19 * V_130 = F_59 () ;
V_163 = ( V_130 -> V_164 ) ( V_13 , V_149 , V_162 ) ;
}
V_129:
V_114 . V_117 [ 3 ] . V_107 = NULL ;
F_36 ( & V_114 ) ;
return ( V_163 ) ;
}
static int
F_60 ( T_3 * V_58 , int V_166 , long V_11 , void * V_123 , void (* F_61) ( void ) )
{
# ifdef F_62
struct V_167 V_168 = V_169 ;
# endif
switch ( V_166 ) {
default:
# ifdef F_62
F_63 ( V_170 , & V_168 , L_16 , V_166 ) ;
# else
F_64 ( V_170 , L_16 , V_166 ) ;
# endif
break;
}
return ( 1 ) ;
}
void F_1 ( void )
{
T_3 * V_171 = F_65 () ;
int V_1 ;
if ( V_171 == NULL )
return;
if ( ( V_1 = F_6 () ) < 0 ) {
F_66 ( V_171 ) ;
return;
}
if ( F_8 ( V_1 , V_172 , & V_126 ) == - 1 ) {
F_9 ( V_1 ) ;
F_66 ( V_171 ) ;
return;
}
F_9 ( V_1 ) ;
if ( ! F_67 ( V_171 , L_17 ) ||
! F_68 ( V_171 , L_18 ) ||
! F_69 ( V_171 , F_19 ) ||
! F_70 ( V_171 , F_31 ) ||
! F_71 ( V_171 , F_60 ) ||
! F_72 ( V_171 , V_173 ) ) {
F_66 ( V_171 ) ;
return;
}
if ( F_73 ( V_171 , & V_174 ) ) {
const T_13 * V_175 = F_41 () ;
V_174 . V_131 = V_175 -> V_131 ;
V_174 . V_143 = V_175 -> V_143 ;
V_174 . V_176 = V_175 -> V_176 ;
V_174 . V_177 = V_175 -> V_177 ;
V_174 . V_178 = V_175 -> V_178 ;
V_174 . V_179 = V_175 -> V_179 ;
if ( V_126 & V_180 ) {
V_174 . V_131 = F_38 ;
if ( V_126 & V_181 )
V_174 . V_143 = F_45 ;
else
V_174 . V_143 = F_42 ;
}
}
if ( F_74 ( V_171 , & V_182 ) ) {
const T_17 * V_130 = F_55 () ;
memcpy ( & V_182 , V_130 , sizeof( T_17 ) ) ;
if ( V_126 & V_183 )
V_182 . V_158 = F_52 ;
if ( V_126 & V_180 ) {
V_182 . V_131 = F_46 ;
V_182 . V_184 = F_47 ;
}
if ( V_126 & V_185 )
V_182 . V_161 = F_56 ;
}
if ( F_75 ( V_171 , & V_186 ) ) {
const T_19 * V_187 = F_59 () ;
V_186 . V_188 = V_187 -> V_188 ;
V_186 . V_164 = V_187 -> V_164 ;
V_186 . V_131 = V_187 -> V_131 ;
if ( V_126 & V_180 ) {
V_186 . V_131 = F_57 ;
if ( V_126 & V_189 )
V_186 . V_164 = F_58 ;
}
}
F_76 ( V_171 ) ;
F_66 ( V_171 ) ;
F_77 () ;
}

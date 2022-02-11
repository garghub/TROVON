T_1 * F_1 ( const T_2 * V_1 )
{
return ( V_1 -> V_2 ) ;
}
T_1 * F_2 ( T_2 * V_1 )
{
T_1 * V_3 ;
F_3 ( V_4 ) ;
V_3 = V_1 -> V_2 ;
if ( V_3 )
V_3 -> V_5 ++ ;
F_4 ( V_4 ) ;
return ( V_3 ) ;
}
int F_5 ( long V_6 , void * V_7 ,
T_3 * V_8 ,
T_4 * V_9 ,
T_5 * V_10 )
{
return F_6 ( V_11 , V_6 , V_7 ,
V_8 , V_9 , V_10 ) ;
}
int F_7 ( T_1 * V_12 , int V_13 , void * V_14 )
{
return ( F_8 ( & V_12 -> V_15 , V_13 , V_14 ) ) ;
}
void * F_9 ( const T_1 * V_12 , int V_13 )
{
return ( F_10 ( & V_12 -> V_15 , V_13 ) ) ;
}
T_1 * F_11 ( void )
{
T_1 * V_16 ;
V_16 = ( T_1 * ) F_12 ( sizeof( T_1 ) ) ;
if ( V_16 == NULL ) {
F_13 ( V_17 , V_18 ) ;
return ( 0 ) ;
}
memset ( V_16 , 0 , sizeof( T_1 ) ) ;
V_16 -> V_19 = 1 ;
V_16 -> V_5 = 1 ;
V_16 -> V_20 = 60 * 5 + 4 ;
V_16 -> time = ( unsigned long ) time ( NULL ) ;
V_16 -> V_21 = NULL ;
V_16 -> V_22 = NULL ;
V_16 -> V_23 = 0 ;
#ifndef F_14
V_16 -> V_24 = NULL ;
# ifndef F_15
V_16 -> V_25 = 0 ;
V_16 -> V_26 = NULL ;
V_16 -> V_27 = 0 ;
V_16 -> V_28 = NULL ;
# endif
#endif
F_16 ( V_11 , V_16 , & V_16 -> V_15 ) ;
#ifndef F_17
V_16 -> V_29 = NULL ;
V_16 -> V_30 = NULL ;
#endif
#ifndef F_18
V_16 -> V_31 = NULL ;
#endif
return ( V_16 ) ;
}
const unsigned char * F_19 ( const T_1 * V_12 ,
unsigned int * V_32 )
{
if ( V_32 )
* V_32 = V_12 -> V_33 ;
return V_12 -> V_34 ;
}
unsigned int F_20 ( const T_1 * V_12 )
{
return V_12 -> V_23 ;
}
static int F_21 ( const T_2 * V_1 , unsigned char * V_35 ,
unsigned int * V_36 )
{
unsigned int V_37 = 0 ;
do
if ( F_22 ( V_35 , * V_36 ) <= 0 )
return 0 ;
while ( F_23 ( V_1 , V_35 , * V_36 ) &&
( ++ V_37 < V_38 ) ) ;
if ( V_37 < V_38 )
return 1 ;
return 0 ;
}
int F_24 ( T_2 * V_12 , int V_2 )
{
unsigned int V_39 ;
T_1 * V_16 = NULL ;
T_6 V_40 = F_21 ;
if ( ( V_16 = F_11 () ) == NULL )
return ( 0 ) ;
if ( V_12 -> V_41 -> V_42 == 0 )
V_16 -> V_20 = F_25 ( V_12 ) ;
else
V_16 -> V_20 = V_12 -> V_41 -> V_42 ;
if ( V_12 -> V_2 != NULL ) {
F_26 ( V_12 -> V_2 ) ;
V_12 -> V_2 = NULL ;
}
if ( V_2 ) {
if ( V_12 -> V_43 == V_44 ) {
V_16 -> V_45 = V_44 ;
V_16 -> V_33 = V_46 ;
} else if ( V_12 -> V_43 == V_47 ) {
V_16 -> V_45 = V_47 ;
V_16 -> V_33 = V_48 ;
} else if ( V_12 -> V_43 == V_49 ) {
V_16 -> V_45 = V_49 ;
V_16 -> V_33 = V_48 ;
} else if ( V_12 -> V_43 == V_50 ) {
V_16 -> V_45 = V_50 ;
V_16 -> V_33 = V_48 ;
} else if ( V_12 -> V_43 == V_51 ) {
V_16 -> V_45 = V_51 ;
V_16 -> V_33 = V_48 ;
} else if ( V_12 -> V_43 == V_52 ) {
V_16 -> V_45 = V_52 ;
V_16 -> V_33 = V_48 ;
} else if ( V_12 -> V_43 == V_53 ) {
V_16 -> V_45 = V_53 ;
V_16 -> V_33 = V_48 ;
} else if ( V_12 -> V_43 == V_54 ) {
V_16 -> V_45 = V_54 ;
V_16 -> V_33 = V_48 ;
} else {
F_13 ( V_55 , V_56 ) ;
F_26 ( V_16 ) ;
return ( 0 ) ;
}
#ifndef F_14
if ( V_12 -> V_57 ) {
V_16 -> V_33 = 0 ;
goto V_58;
}
#endif
F_27 ( V_59 ) ;
if ( V_12 -> V_60 )
V_40 = V_12 -> V_60 ;
else if ( V_12 -> V_41 -> V_60 )
V_40 = V_12 -> V_41 -> V_60 ;
F_28 ( V_59 ) ;
V_39 = V_16 -> V_33 ;
if ( ! V_40 ( V_12 , V_16 -> V_34 , & V_39 ) ) {
F_13 ( V_55 ,
V_61 ) ;
F_26 ( V_16 ) ;
return ( 0 ) ;
}
if ( ! V_39 || ( V_39 > V_16 -> V_33 ) ) {
F_13 ( V_55 ,
V_62 ) ;
F_26 ( V_16 ) ;
return ( 0 ) ;
}
if ( ( V_39 < V_16 -> V_33 ) && ( V_12 -> V_43 == V_44 ) )
memset ( V_16 -> V_34 + V_39 , 0 , V_16 -> V_33 - V_39 ) ;
else
V_16 -> V_33 = V_39 ;
if ( F_23 ( V_12 , V_16 -> V_34 ,
V_16 -> V_33 ) ) {
F_13 ( V_55 , V_63 ) ;
F_26 ( V_16 ) ;
return ( 0 ) ;
}
#ifndef F_14
V_58:
if ( V_12 -> V_24 ) {
V_16 -> V_24 = F_29 ( V_12 -> V_24 ) ;
if ( V_16 -> V_24 == NULL ) {
F_13 ( V_55 , V_64 ) ;
F_26 ( V_16 ) ;
return 0 ;
}
}
#endif
} else {
V_16 -> V_33 = 0 ;
}
if ( V_12 -> V_65 > sizeof V_16 -> V_66 ) {
F_13 ( V_55 , V_64 ) ;
F_26 ( V_16 ) ;
return 0 ;
}
memcpy ( V_16 -> V_66 , V_12 -> V_66 , V_12 -> V_65 ) ;
V_16 -> V_65 = V_12 -> V_65 ;
V_12 -> V_2 = V_16 ;
V_16 -> V_45 = V_12 -> V_43 ;
V_16 -> V_19 = V_67 ;
return ( 1 ) ;
}
int F_30 ( T_2 * V_12 , unsigned char * V_34 , int V_32 ,
const unsigned char * V_68 )
{
T_1 * V_69 = NULL ;
int V_70 = 0 ;
int V_71 = 1 ;
#ifndef F_14
int V_72 ;
#endif
if ( V_32 > V_73 )
goto V_74;
if ( V_32 == 0 )
V_71 = 0 ;
#ifndef F_14
V_72 = F_31 ( V_12 , V_34 , V_32 , V_68 , & V_69 ) ;
switch ( V_72 ) {
case - 1 :
V_70 = 1 ;
goto V_74;
case 0 :
case 1 :
break;
case 2 :
case 3 :
V_71 = 0 ;
break;
default:
abort () ;
}
#endif
if ( V_71 &&
V_69 == NULL &&
! ( V_12 -> V_41 -> V_75 &
V_76 ) ) {
T_1 V_77 ;
V_77 . V_45 = V_12 -> V_43 ;
V_77 . V_33 = V_32 ;
if ( V_32 == 0 )
return 0 ;
memcpy ( V_77 . V_34 , V_34 , V_32 ) ;
F_27 ( V_59 ) ;
V_69 = F_32 ( V_12 -> V_41 -> V_78 , & V_77 ) ;
if ( V_69 != NULL ) {
F_33 ( & V_69 -> V_5 , 1 , V_4 ) ;
}
F_28 ( V_59 ) ;
if ( V_69 == NULL )
V_12 -> V_41 -> V_79 . V_80 ++ ;
}
if ( V_71 &&
V_69 == NULL && V_12 -> V_41 -> V_81 != NULL ) {
int V_82 = 1 ;
if ( ( V_69 = V_12 -> V_41 -> V_81 ( V_12 , V_34 , V_32 , & V_82 ) ) ) {
V_12 -> V_41 -> V_79 . V_83 ++ ;
if ( V_82 )
F_33 ( & V_69 -> V_5 , 1 , V_4 ) ;
if ( !
( V_12 -> V_41 -> V_75 &
V_84 ) )
F_34 ( V_12 -> V_41 , V_69 ) ;
}
}
if ( V_69 == NULL )
goto V_74;
if ( V_69 -> V_65 != V_12 -> V_65
|| memcmp ( V_69 -> V_66 , V_12 -> V_66 , V_69 -> V_65 ) ) {
goto V_74;
}
if ( ( V_12 -> V_85 & V_86 ) && V_12 -> V_65 == 0 ) {
F_13 ( V_87 ,
V_88 ) ;
V_70 = 1 ;
goto V_74;
}
if ( V_69 -> V_89 == NULL ) {
unsigned char V_90 [ 5 ] , * V_91 ;
unsigned long V_92 ;
V_91 = V_90 ;
V_92 = V_69 -> V_93 ;
F_35 ( V_92 , V_91 ) ;
if ( ( V_69 -> V_45 >> 8 ) >= V_94 )
V_69 -> V_89 = F_36 ( V_12 , & ( V_90 [ 2 ] ) ) ;
else
V_69 -> V_89 = F_36 ( V_12 , & ( V_90 [ 1 ] ) ) ;
if ( V_69 -> V_89 == NULL )
goto V_74;
}
if ( V_69 -> V_20 < ( long ) ( time ( NULL ) - V_69 -> time ) ) {
V_12 -> V_41 -> V_79 . V_95 ++ ;
if ( V_71 ) {
F_37 ( V_12 -> V_41 , V_69 ) ;
}
goto V_74;
}
V_12 -> V_41 -> V_79 . V_96 ++ ;
if ( V_12 -> V_2 != NULL )
F_26 ( V_12 -> V_2 ) ;
V_12 -> V_2 = V_69 ;
V_12 -> V_19 = V_12 -> V_2 -> V_19 ;
return 1 ;
V_74:
if ( V_69 != NULL ) {
F_26 ( V_69 ) ;
#ifndef F_14
if ( ! V_71 ) {
V_12 -> V_57 = 1 ;
}
#endif
}
if ( V_70 )
return - 1 ;
else
return 0 ;
}
int F_34 ( T_7 * V_97 , T_1 * V_98 )
{
int V_69 = 0 ;
T_1 * V_12 ;
F_33 ( & V_98 -> V_5 , 1 , V_4 ) ;
F_3 ( V_59 ) ;
V_12 = F_38 ( V_97 -> V_78 , V_98 ) ;
if ( V_12 != NULL && V_12 != V_98 ) {
F_39 ( V_97 , V_12 ) ;
F_26 ( V_12 ) ;
V_12 = NULL ;
}
if ( V_12 == NULL )
F_40 ( V_97 , V_98 ) ;
if ( V_12 != NULL ) {
F_26 ( V_12 ) ;
V_69 = 0 ;
} else {
V_69 = 1 ;
if ( F_41 ( V_97 ) > 0 ) {
while ( F_42 ( V_97 ) >
F_41 ( V_97 ) ) {
if ( ! F_43 ( V_97 , V_97 -> V_99 , 0 ) )
break;
else
V_97 -> V_79 . V_100 ++ ;
}
}
}
F_4 ( V_59 ) ;
return ( V_69 ) ;
}
int F_37 ( T_7 * V_97 , T_1 * V_98 )
{
return F_43 ( V_97 , V_98 , 1 ) ;
}
static int F_43 ( T_7 * V_97 , T_1 * V_98 , int V_101 )
{
T_1 * V_72 ;
int V_69 = 0 ;
if ( ( V_98 != NULL ) && ( V_98 -> V_33 != 0 ) ) {
if ( V_101 )
F_3 ( V_59 ) ;
if ( ( V_72 = F_32 ( V_97 -> V_78 , V_98 ) ) == V_98 ) {
V_69 = 1 ;
V_72 = F_44 ( V_97 -> V_78 , V_98 ) ;
F_39 ( V_97 , V_98 ) ;
}
if ( V_101 )
F_4 ( V_59 ) ;
if ( V_69 ) {
V_72 -> V_102 = 1 ;
if ( V_97 -> V_103 != NULL )
V_97 -> V_103 ( V_97 , V_72 ) ;
F_26 ( V_72 ) ;
}
} else
V_69 = 0 ;
return ( V_69 ) ;
}
void F_26 ( T_1 * V_16 )
{
int V_104 ;
if ( V_16 == NULL )
return;
V_104 = F_33 ( & V_16 -> V_5 , - 1 , V_4 ) ;
#ifdef F_45
F_45 ( L_1 , V_16 ) ;
#endif
if ( V_104 > 0 )
return;
#ifdef F_46
if ( V_104 < 0 ) {
fprintf ( V_105 , L_2 ) ;
abort () ;
}
#endif
F_47 ( V_11 , V_16 , & V_16 -> V_15 ) ;
F_48 ( V_16 -> V_106 , sizeof V_16 -> V_106 ) ;
F_48 ( V_16 -> V_107 , sizeof V_16 -> V_107 ) ;
F_48 ( V_16 -> V_34 , sizeof V_16 -> V_34 ) ;
if ( V_16 -> V_108 != NULL )
F_49 ( V_16 -> V_108 ) ;
if ( V_16 -> V_109 != NULL )
F_50 ( V_16 -> V_109 ) ;
if ( V_16 -> V_110 != NULL )
F_51 ( V_16 -> V_110 ) ;
#ifndef F_14
if ( V_16 -> V_24 != NULL )
F_52 ( V_16 -> V_24 ) ;
if ( V_16 -> V_111 != NULL )
F_52 ( V_16 -> V_111 ) ;
# ifndef F_15
V_16 -> V_25 = 0 ;
if ( V_16 -> V_26 != NULL )
F_52 ( V_16 -> V_26 ) ;
V_16 -> V_27 = 0 ;
if ( V_16 -> V_28 != NULL )
F_52 ( V_16 -> V_28 ) ;
# endif
#endif
#ifndef F_17
if ( V_16 -> V_29 != NULL )
F_52 ( V_16 -> V_29 ) ;
if ( V_16 -> V_30 != NULL )
F_52 ( V_16 -> V_30 ) ;
#endif
#ifndef F_18
if ( V_16 -> V_31 != NULL )
F_52 ( V_16 -> V_31 ) ;
#endif
F_48 ( V_16 , sizeof( * V_16 ) ) ;
F_52 ( V_16 ) ;
}
int F_53 ( T_2 * V_12 , T_1 * V_2 )
{
int V_69 = 0 ;
const T_8 * V_112 ;
if ( V_2 != NULL ) {
V_112 = V_12 -> V_97 -> V_113 -> V_114 ( V_2 -> V_45 ) ;
if ( V_112 == NULL )
V_112 = V_12 -> V_113 -> V_114 ( V_2 -> V_45 ) ;
if ( V_112 == NULL ) {
F_13 ( V_115 , V_116 ) ;
return ( 0 ) ;
}
if ( V_112 != V_12 -> V_113 ) {
if ( ! F_54 ( V_12 , V_112 ) )
return ( 0 ) ;
}
#ifndef F_55
if ( V_12 -> V_117 && ! V_12 -> V_117 -> V_118 &&
V_2 -> V_119 > 0 ) {
V_12 -> V_117 -> V_118 =
( char * ) F_12 ( V_2 -> V_119 + 1 ) ;
memcpy ( V_12 -> V_117 -> V_118 , V_2 -> V_120 ,
V_2 -> V_119 ) ;
V_12 -> V_117 -> V_118 [ V_2 -> V_119 ] = '\0' ;
}
#endif
F_33 ( & V_2 -> V_5 , 1 , V_4 ) ;
if ( V_12 -> V_2 != NULL )
F_26 ( V_12 -> V_2 ) ;
V_12 -> V_2 = V_2 ;
V_12 -> V_19 = V_12 -> V_2 -> V_19 ;
V_69 = 1 ;
} else {
if ( V_12 -> V_2 != NULL ) {
F_26 ( V_12 -> V_2 ) ;
V_12 -> V_2 = NULL ;
}
V_112 = V_12 -> V_97 -> V_113 ;
if ( V_112 != V_12 -> V_113 ) {
if ( ! F_54 ( V_12 , V_112 ) )
return ( 0 ) ;
}
V_69 = 1 ;
}
return ( V_69 ) ;
}
long F_56 ( T_1 * V_12 , long V_121 )
{
if ( V_12 == NULL )
return ( 0 ) ;
V_12 -> V_20 = V_121 ;
return ( 1 ) ;
}
long F_57 ( const T_1 * V_12 )
{
if ( V_12 == NULL )
return ( 0 ) ;
return ( V_12 -> V_20 ) ;
}
long F_58 ( const T_1 * V_12 )
{
if ( V_12 == NULL )
return ( 0 ) ;
return ( V_12 -> time ) ;
}
long F_59 ( T_1 * V_12 , long V_121 )
{
if ( V_12 == NULL )
return ( 0 ) ;
V_12 -> time = V_121 ;
return ( V_121 ) ;
}
T_9 * F_60 ( T_1 * V_12 )
{
return V_12 -> V_109 ;
}
int F_61 ( T_1 * V_12 , const unsigned char * V_66 ,
unsigned int V_122 )
{
if ( V_122 > V_123 ) {
F_13 ( V_124 ,
V_125 ) ;
return 0 ;
}
V_12 -> V_65 = V_122 ;
memcpy ( V_12 -> V_66 , V_66 , V_122 ) ;
return 1 ;
}
long F_62 ( T_7 * V_12 , long V_121 )
{
long V_92 ;
if ( V_12 == NULL )
return ( 0 ) ;
V_92 = V_12 -> V_42 ;
V_12 -> V_42 = V_121 ;
return ( V_92 ) ;
}
long F_63 ( const T_7 * V_12 )
{
if ( V_12 == NULL )
return ( 0 ) ;
return ( V_12 -> V_42 ) ;
}
int F_64 ( T_2 * V_12 , T_10 V_40 ,
void * V_14 )
{
if ( V_12 == NULL )
return ( 0 ) ;
V_12 -> V_126 = V_40 ;
V_12 -> V_127 = V_14 ;
return ( 1 ) ;
}
int F_65 ( T_2 * V_12 , void * V_128 , int V_129 )
{
if ( V_12 -> V_43 >= V_49 ) {
if ( V_12 -> V_130 ) {
F_52 ( V_12 -> V_130 ) ;
V_12 -> V_130 = NULL ;
}
V_12 -> V_130 =
F_12 ( sizeof( V_131 ) + V_129 ) ;
if ( ! V_12 -> V_130 ) {
F_13 ( V_132 , V_18 ) ;
return 0 ;
}
if ( V_128 ) {
V_12 -> V_130 -> V_133 = V_129 ;
V_12 -> V_130 -> V_77 = V_12 -> V_130 + 1 ;
memcpy ( V_12 -> V_130 -> V_77 , V_128 , V_129 ) ;
} else {
V_12 -> V_130 -> V_133 = 0 ;
V_12 -> V_130 -> V_77 = NULL ;
}
return 1 ;
}
return 0 ;
}
static void F_66 ( T_1 * V_12 , T_11 * V_91 )
{
if ( ( V_91 -> time == 0 ) || ( V_91 -> time > ( V_12 -> time + V_12 -> V_20 ) ) ) {
( void ) F_44 ( V_91 -> V_134 , V_12 ) ;
F_39 ( V_91 -> V_97 , V_12 ) ;
V_12 -> V_102 = 1 ;
if ( V_91 -> V_97 -> V_103 != NULL )
V_91 -> V_97 -> V_103 ( V_91 -> V_97 , V_12 ) ;
F_26 ( V_12 ) ;
}
}
static void F_39 ( T_7 * V_97 , T_1 * V_12 )
{
if ( ( V_12 -> V_22 == NULL ) || ( V_12 -> V_21 == NULL ) )
return;
if ( V_12 -> V_22 == ( T_1 * ) & ( V_97 -> V_99 ) ) {
if ( V_12 -> V_21 == ( T_1 * ) & ( V_97 -> V_135 ) ) {
V_97 -> V_135 = NULL ;
V_97 -> V_99 = NULL ;
} else {
V_97 -> V_99 = V_12 -> V_21 ;
V_12 -> V_21 -> V_22 = ( T_1 * ) & ( V_97 -> V_99 ) ;
}
} else {
if ( V_12 -> V_21 == ( T_1 * ) & ( V_97 -> V_135 ) ) {
V_97 -> V_135 = V_12 -> V_22 ;
V_12 -> V_22 -> V_21 = ( T_1 * ) & ( V_97 -> V_135 ) ;
} else {
V_12 -> V_22 -> V_21 = V_12 -> V_21 ;
V_12 -> V_21 -> V_22 = V_12 -> V_22 ;
}
}
V_12 -> V_21 = V_12 -> V_22 = NULL ;
}
static void F_40 ( T_7 * V_97 , T_1 * V_12 )
{
if ( ( V_12 -> V_22 != NULL ) && ( V_12 -> V_21 != NULL ) )
F_39 ( V_97 , V_12 ) ;
if ( V_97 -> V_135 == NULL ) {
V_97 -> V_135 = V_12 ;
V_97 -> V_99 = V_12 ;
V_12 -> V_21 = ( T_1 * ) & ( V_97 -> V_135 ) ;
V_12 -> V_22 = ( T_1 * ) & ( V_97 -> V_99 ) ;
} else {
V_12 -> V_22 = V_97 -> V_135 ;
V_12 -> V_22 -> V_21 = V_12 ;
V_12 -> V_21 = ( T_1 * ) & ( V_97 -> V_135 ) ;
V_97 -> V_135 = V_12 ;
}
}
void F_67 ( T_7 * V_97 ,
int (* V_40) ( struct V_136 * V_1 ,
T_1 * V_3 ) )
{
V_97 -> V_137 = V_40 ;
}
void F_68 ( T_7 * V_97 ,
void (* V_40) ( T_7 * V_97 , T_1 * V_3 ) )
{
V_97 -> V_103 = V_40 ;
}
void F_69 ( T_7 * V_97 ,
T_1 * (* V_40) ( struct V_136 * V_1 ,
unsigned char * V_77 , int V_32 ,
int * V_82 ) )
{
V_97 -> V_81 = V_40 ;
}
void F_70 ( T_7 * V_97 ,
void (* V_40) ( const T_2 * V_1 , int type , int V_138 ) )
{
V_97 -> V_139 = V_40 ;
}
void F_71 ( T_7 * V_97 ,
int (* V_40) ( T_2 * V_1 , T_9 * * V_140 ,
T_12 * * V_141 ) )
{
V_97 -> V_142 = V_40 ;
}
int F_72 ( T_7 * V_97 , T_13 * V_143 )
{
if ( ! F_73 ( V_143 ) ) {
F_13 ( V_144 , V_145 ) ;
return 0 ;
}
if ( ! F_74 ( V_143 ) ) {
F_13 ( V_144 ,
V_146 ) ;
F_75 ( V_143 ) ;
return 0 ;
}
V_97 -> V_147 = V_143 ;
return 1 ;
}
void F_76 ( T_7 * V_97 ,
int (* V_40) ( T_2 * V_1 ,
unsigned char * V_148 ,
unsigned int * V_149 ) )
{
V_97 -> V_150 = V_40 ;
}
void F_77 ( T_7 * V_97 ,
int (* V_40) ( T_2 * V_1 , unsigned char * V_148 ,
unsigned int V_149 ) )
{
V_97 -> V_151 = V_40 ;
}

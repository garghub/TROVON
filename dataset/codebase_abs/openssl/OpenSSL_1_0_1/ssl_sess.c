T_1 * F_1 ( const T_2 * V_1 )
{
return ( V_1 -> V_2 ) ;
}
T_1 * F_2 ( T_2 * V_1 )
{
T_1 * V_3 ;
F_3 ( V_4 ) ;
V_3 = V_1 -> V_2 ;
if( V_3 )
V_3 -> V_5 ++ ;
F_4 ( V_4 ) ;
return ( V_3 ) ;
}
int F_5 ( long V_6 , void * V_7 , T_3 * V_8 ,
T_4 * V_9 , T_5 * V_10 )
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
if ( V_16 == NULL )
{
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
#ifndef F_15
V_16 -> V_25 = 0 ;
V_16 -> V_26 = NULL ;
V_16 -> V_27 = 0 ;
V_16 -> V_28 = NULL ;
#endif
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
const unsigned char * F_19 ( const T_1 * V_12 , unsigned int * V_32 )
{
if( V_32 )
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
while( F_23 ( V_1 , V_35 , * V_36 ) &&
( ++ V_37 < V_38 ) );
if( V_37 < V_38 )
return 1 ;
return 0 ;
}
int F_24 ( T_2 * V_12 , int V_2 )
{
unsigned int V_39 ;
T_1 * V_16 = NULL ;
T_6 V_40 = F_21 ;
if ( ( V_16 = F_11 () ) == NULL ) return ( 0 ) ;
if ( V_12 -> V_41 -> V_42 == 0 )
V_16 -> V_20 = F_25 ( V_12 ) ;
else
V_16 -> V_20 = V_12 -> V_41 -> V_42 ;
if ( V_12 -> V_2 != NULL )
{
F_26 ( V_12 -> V_2 ) ;
V_12 -> V_2 = NULL ;
}
if ( V_2 )
{
if ( V_12 -> V_43 == V_44 )
{
V_16 -> V_45 = V_44 ;
V_16 -> V_33 = V_46 ;
}
else if ( V_12 -> V_43 == V_47 )
{
V_16 -> V_45 = V_47 ;
V_16 -> V_33 = V_48 ;
}
else if ( V_12 -> V_43 == V_49 )
{
V_16 -> V_45 = V_49 ;
V_16 -> V_33 = V_48 ;
}
else if ( V_12 -> V_43 == V_50 )
{
V_16 -> V_45 = V_50 ;
V_16 -> V_33 = V_48 ;
}
else if ( V_12 -> V_43 == V_51 )
{
V_16 -> V_45 = V_51 ;
V_16 -> V_33 = V_48 ;
}
else if ( V_12 -> V_43 == V_52 )
{
V_16 -> V_45 = V_52 ;
V_16 -> V_33 = V_48 ;
}
else if ( V_12 -> V_43 == V_53 )
{
V_16 -> V_45 = V_53 ;
V_16 -> V_33 = V_48 ;
}
else
{
F_13 ( V_54 , V_55 ) ;
F_26 ( V_16 ) ;
return ( 0 ) ;
}
#ifndef F_14
if ( V_12 -> V_56 )
{
V_16 -> V_33 = 0 ;
goto V_57;
}
#endif
F_27 ( V_58 ) ;
if( V_12 -> V_59 )
V_40 = V_12 -> V_59 ;
else if( V_12 -> V_41 -> V_59 )
V_40 = V_12 -> V_41 -> V_59 ;
F_28 ( V_58 ) ;
V_39 = V_16 -> V_33 ;
if( ! V_40 ( V_12 , V_16 -> V_34 , & V_39 ) )
{
F_13 ( V_54 ,
V_60 ) ;
F_26 ( V_16 ) ;
return ( 0 ) ;
}
if( ! V_39 || ( V_39 > V_16 -> V_33 ) )
{
F_13 ( V_54 ,
V_61 ) ;
F_26 ( V_16 ) ;
return ( 0 ) ;
}
if( ( V_39 < V_16 -> V_33 ) && ( V_12 -> V_43 == V_44 ) )
memset ( V_16 -> V_34 + V_39 , 0 , V_16 -> V_33 - V_39 ) ;
else
V_16 -> V_33 = V_39 ;
if( F_23 ( V_12 , V_16 -> V_34 ,
V_16 -> V_33 ) )
{
F_13 ( V_54 ,
V_62 ) ;
F_26 ( V_16 ) ;
return ( 0 ) ;
}
#ifndef F_14
V_57:
if ( V_12 -> V_24 ) {
V_16 -> V_24 = F_29 ( V_12 -> V_24 ) ;
if ( V_16 -> V_24 == NULL ) {
F_13 ( V_54 , V_63 ) ;
F_26 ( V_16 ) ;
return 0 ;
}
}
#ifndef F_15
if ( V_12 -> V_26 )
{
if ( V_16 -> V_26 != NULL ) F_30 ( V_16 -> V_26 ) ;
if ( ( V_16 -> V_26 = F_12 ( V_12 -> V_25 ) ) == NULL )
{
F_13 ( V_54 , V_18 ) ;
F_26 ( V_16 ) ;
return 0 ;
}
V_16 -> V_25 = V_12 -> V_25 ;
memcpy ( V_16 -> V_26 , V_12 -> V_26 , V_12 -> V_25 ) ;
}
if ( V_12 -> V_28 )
{
if ( V_16 -> V_28 != NULL ) F_30 ( V_16 -> V_28 ) ;
if ( ( V_16 -> V_28 = F_12 ( V_12 -> V_27 ) ) == NULL )
{
F_13 ( V_54 , V_18 ) ;
F_26 ( V_16 ) ;
return 0 ;
}
V_16 -> V_27 = V_12 -> V_27 ;
memcpy ( V_16 -> V_28 , V_12 -> V_28 , V_12 -> V_27 ) ;
}
#endif
#endif
}
else
{
V_16 -> V_33 = 0 ;
}
if ( V_12 -> V_64 > sizeof V_16 -> V_65 )
{
F_13 ( V_54 , V_63 ) ;
F_26 ( V_16 ) ;
return 0 ;
}
memcpy ( V_16 -> V_65 , V_12 -> V_65 , V_12 -> V_64 ) ;
V_16 -> V_64 = V_12 -> V_64 ;
V_12 -> V_2 = V_16 ;
V_16 -> V_45 = V_12 -> V_43 ;
V_16 -> V_19 = V_66 ;
return ( 1 ) ;
}
int F_31 ( T_2 * V_12 , unsigned char * V_34 , int V_32 ,
const unsigned char * V_67 )
{
T_1 * V_68 = NULL ;
int V_69 = 0 ;
int V_70 = 1 ;
#ifndef F_14
int V_71 ;
#endif
if ( V_32 > V_72 )
goto V_73;
if ( V_32 == 0 )
V_70 = 0 ;
#ifndef F_14
V_71 = F_32 ( V_12 , V_34 , V_32 , V_67 , & V_68 ) ;
switch ( V_71 )
{
case - 1 :
V_69 = 1 ;
goto V_73;
case 0 :
case 1 :
break;
case 2 :
case 3 :
V_70 = 0 ;
break;
default:
abort () ;
}
#endif
if ( V_70 &&
V_68 == NULL &&
! ( V_12 -> V_41 -> V_74 & V_75 ) )
{
T_1 V_76 ;
V_76 . V_45 = V_12 -> V_43 ;
V_76 . V_33 = V_32 ;
if ( V_32 == 0 )
return 0 ;
memcpy ( V_76 . V_34 , V_34 , V_32 ) ;
F_27 ( V_58 ) ;
V_68 = F_33 ( V_12 -> V_41 -> V_77 , & V_76 ) ;
if ( V_68 != NULL )
{
F_34 ( & V_68 -> V_5 , 1 , V_4 ) ;
}
F_28 ( V_58 ) ;
if ( V_68 == NULL )
V_12 -> V_41 -> V_78 . V_79 ++ ;
}
if ( V_70 &&
V_68 == NULL &&
V_12 -> V_41 -> V_80 != NULL )
{
int V_81 = 1 ;
if ( ( V_68 = V_12 -> V_41 -> V_80 ( V_12 , V_34 , V_32 , & V_81 ) ) )
{
V_12 -> V_41 -> V_78 . V_82 ++ ;
if ( V_81 )
F_34 ( & V_68 -> V_5 , 1 , V_4 ) ;
if( ! ( V_12 -> V_41 -> V_74 & V_83 ) )
F_35 ( V_12 -> V_41 , V_68 ) ;
}
}
if ( V_68 == NULL )
goto V_73;
if ( V_68 -> V_64 != V_12 -> V_64
|| memcmp ( V_68 -> V_65 , V_12 -> V_65 , V_68 -> V_64 ) )
{
goto V_73;
}
if( ( V_12 -> V_84 & V_85 ) && V_12 -> V_64 == 0 )
{
F_13 ( V_86 , V_87 ) ;
V_69 = 1 ;
goto V_73;
}
if ( V_68 -> V_88 == NULL )
{
unsigned char V_89 [ 5 ] , * V_90 ;
unsigned long V_91 ;
V_90 = V_89 ;
V_91 = V_68 -> V_92 ;
F_36 ( V_91 , V_90 ) ;
if ( ( V_68 -> V_45 >> 8 ) >= V_93 )
V_68 -> V_88 = F_37 ( V_12 , & ( V_89 [ 2 ] ) ) ;
else
V_68 -> V_88 = F_37 ( V_12 , & ( V_89 [ 1 ] ) ) ;
if ( V_68 -> V_88 == NULL )
goto V_73;
}
if ( V_68 -> V_20 < ( long ) ( time ( NULL ) - V_68 -> time ) )
{
V_12 -> V_41 -> V_78 . V_94 ++ ;
if ( V_70 )
{
F_38 ( V_12 -> V_41 , V_68 ) ;
}
goto V_73;
}
V_12 -> V_41 -> V_78 . V_95 ++ ;
if ( V_12 -> V_2 != NULL )
F_26 ( V_12 -> V_2 ) ;
V_12 -> V_2 = V_68 ;
V_12 -> V_19 = V_12 -> V_2 -> V_19 ;
return 1 ;
V_73:
if ( V_68 != NULL )
{
F_26 ( V_68 ) ;
#ifndef F_14
if ( ! V_70 )
{
V_12 -> V_56 = 1 ;
}
#endif
}
if ( V_69 )
return - 1 ;
else
return 0 ;
}
int F_35 ( T_7 * V_96 , T_1 * V_97 )
{
int V_68 = 0 ;
T_1 * V_12 ;
F_34 ( & V_97 -> V_5 , 1 , V_4 ) ;
F_3 ( V_58 ) ;
V_12 = F_39 ( V_96 -> V_77 , V_97 ) ;
if ( V_12 != NULL && V_12 != V_97 )
{
F_40 ( V_96 , V_12 ) ;
F_26 ( V_12 ) ;
V_12 = NULL ;
}
if ( V_12 == NULL )
F_41 ( V_96 , V_97 ) ;
if ( V_12 != NULL )
{
F_26 ( V_12 ) ;
V_68 = 0 ;
}
else
{
V_68 = 1 ;
if ( F_42 ( V_96 ) > 0 )
{
while ( F_43 ( V_96 ) >
F_42 ( V_96 ) )
{
if ( ! F_44 ( V_96 ,
V_96 -> V_98 , 0 ) )
break;
else
V_96 -> V_78 . V_99 ++ ;
}
}
}
F_4 ( V_58 ) ;
return ( V_68 ) ;
}
int F_38 ( T_7 * V_96 , T_1 * V_97 )
{
return F_44 ( V_96 , V_97 , 1 ) ;
}
static int F_44 ( T_7 * V_96 , T_1 * V_97 , int V_100 )
{
T_1 * V_71 ;
int V_68 = 0 ;
if ( ( V_97 != NULL ) && ( V_97 -> V_33 != 0 ) )
{
if( V_100 ) F_3 ( V_58 ) ;
if ( ( V_71 = F_33 ( V_96 -> V_77 , V_97 ) ) == V_97 )
{
V_68 = 1 ;
V_71 = F_45 ( V_96 -> V_77 , V_97 ) ;
F_40 ( V_96 , V_97 ) ;
}
if( V_100 ) F_4 ( V_58 ) ;
if ( V_68 )
{
V_71 -> V_101 = 1 ;
if ( V_96 -> V_102 != NULL )
V_96 -> V_102 ( V_96 , V_71 ) ;
F_26 ( V_71 ) ;
}
}
else
V_68 = 0 ;
return ( V_68 ) ;
}
void F_26 ( T_1 * V_16 )
{
int V_103 ;
if( V_16 == NULL )
return;
V_103 = F_34 ( & V_16 -> V_5 , - 1 , V_4 ) ;
#ifdef F_46
F_46 ( L_1 , V_16 ) ;
#endif
if ( V_103 > 0 ) return;
#ifdef F_47
if ( V_103 < 0 )
{
fprintf ( V_104 , L_2 ) ;
abort () ;
}
#endif
F_48 ( V_11 , V_16 , & V_16 -> V_15 ) ;
F_49 ( V_16 -> V_105 , sizeof V_16 -> V_105 ) ;
F_49 ( V_16 -> V_106 , sizeof V_16 -> V_106 ) ;
F_49 ( V_16 -> V_34 , sizeof V_16 -> V_34 ) ;
if ( V_16 -> V_107 != NULL ) F_50 ( V_16 -> V_107 ) ;
if ( V_16 -> V_108 != NULL ) F_51 ( V_16 -> V_108 ) ;
if ( V_16 -> V_109 != NULL ) F_52 ( V_16 -> V_109 ) ;
#ifndef F_14
if ( V_16 -> V_24 != NULL ) F_30 ( V_16 -> V_24 ) ;
if ( V_16 -> V_110 != NULL ) F_30 ( V_16 -> V_110 ) ;
#ifndef F_15
V_16 -> V_25 = 0 ;
if ( V_16 -> V_26 != NULL ) F_30 ( V_16 -> V_26 ) ;
V_16 -> V_27 = 0 ;
if ( V_16 -> V_28 != NULL ) F_30 ( V_16 -> V_28 ) ;
#endif
#endif
#ifndef F_17
if ( V_16 -> V_29 != NULL )
F_30 ( V_16 -> V_29 ) ;
if ( V_16 -> V_30 != NULL )
F_30 ( V_16 -> V_30 ) ;
#endif
#ifndef F_18
if ( V_16 -> V_31 != NULL )
F_30 ( V_16 -> V_31 ) ;
#endif
F_49 ( V_16 , sizeof( * V_16 ) ) ;
F_30 ( V_16 ) ;
}
int F_53 ( T_2 * V_12 , T_1 * V_2 )
{
int V_68 = 0 ;
const T_8 * V_111 ;
if ( V_2 != NULL )
{
V_111 = V_12 -> V_96 -> V_112 -> V_113 ( V_2 -> V_45 ) ;
if ( V_111 == NULL )
V_111 = V_12 -> V_112 -> V_113 ( V_2 -> V_45 ) ;
if ( V_111 == NULL )
{
F_13 ( V_114 , V_115 ) ;
return ( 0 ) ;
}
if ( V_111 != V_12 -> V_112 )
{
if ( ! F_54 ( V_12 , V_111 ) )
return ( 0 ) ;
}
#ifndef F_55
if ( V_12 -> V_116 && ! V_12 -> V_116 -> V_117 &&
V_2 -> V_118 > 0 )
{
V_12 -> V_116 -> V_117 = ( char * ) F_12 ( V_2 -> V_118 + 1 ) ;
memcpy ( V_12 -> V_116 -> V_117 , V_2 -> V_119 ,
V_2 -> V_118 ) ;
V_12 -> V_116 -> V_117 [ V_2 -> V_118 ] = '\0' ;
}
#endif
F_34 ( & V_2 -> V_5 , 1 , V_4 ) ;
if ( V_12 -> V_2 != NULL )
F_26 ( V_12 -> V_2 ) ;
V_12 -> V_2 = V_2 ;
V_12 -> V_19 = V_12 -> V_2 -> V_19 ;
V_68 = 1 ;
}
else
{
if ( V_12 -> V_2 != NULL )
{
F_26 ( V_12 -> V_2 ) ;
V_12 -> V_2 = NULL ;
}
V_111 = V_12 -> V_96 -> V_112 ;
if ( V_111 != V_12 -> V_112 )
{
if ( ! F_54 ( V_12 , V_111 ) )
return ( 0 ) ;
}
V_68 = 1 ;
}
return ( V_68 ) ;
}
long F_56 ( T_1 * V_12 , long V_120 )
{
if ( V_12 == NULL ) return ( 0 ) ;
V_12 -> V_20 = V_120 ;
return ( 1 ) ;
}
long F_57 ( const T_1 * V_12 )
{
if ( V_12 == NULL ) return ( 0 ) ;
return ( V_12 -> V_20 ) ;
}
long F_58 ( const T_1 * V_12 )
{
if ( V_12 == NULL ) return ( 0 ) ;
return ( V_12 -> time ) ;
}
long F_59 ( T_1 * V_12 , long V_120 )
{
if ( V_12 == NULL ) return ( 0 ) ;
V_12 -> time = V_120 ;
return ( V_120 ) ;
}
T_9 * F_60 ( T_1 * V_12 )
{
return V_12 -> V_108 ;
}
int F_61 ( T_1 * V_12 , const unsigned char * V_65 ,
unsigned int V_121 )
{
if( V_121 > V_122 )
{
F_13 ( V_123 , V_124 ) ;
return 0 ;
}
V_12 -> V_64 = V_121 ;
memcpy ( V_12 -> V_65 , V_65 , V_121 ) ;
return 1 ;
}
long F_62 ( T_7 * V_12 , long V_120 )
{
long V_91 ;
if ( V_12 == NULL ) return ( 0 ) ;
V_91 = V_12 -> V_42 ;
V_12 -> V_42 = V_120 ;
return ( V_91 ) ;
}
long F_63 ( const T_7 * V_12 )
{
if ( V_12 == NULL ) return ( 0 ) ;
return ( V_12 -> V_42 ) ;
}
int F_64 ( T_2 * V_12 , T_10 V_40 ,
void * V_14 )
{
if ( V_12 == NULL ) return ( 0 ) ;
V_12 -> V_125 = V_40 ;
V_12 -> V_126 = V_14 ;
return ( 1 ) ;
}
int F_65 ( T_2 * V_12 , void * V_127 , int V_128 )
{
if ( V_12 -> V_43 >= V_49 )
{
if ( V_12 -> V_129 )
{
F_30 ( V_12 -> V_129 ) ;
V_12 -> V_129 = NULL ;
}
V_12 -> V_129 = F_12 ( sizeof( V_130 ) + V_128 ) ;
if ( ! V_12 -> V_129 )
{
F_13 ( V_131 , V_18 ) ;
return 0 ;
}
if ( V_127 )
{
V_12 -> V_129 -> V_132 = V_128 ;
V_12 -> V_129 -> V_76 = V_12 -> V_129 + 1 ;
memcpy ( V_12 -> V_129 -> V_76 , V_127 , V_128 ) ;
}
else
{
V_12 -> V_129 -> V_132 = 0 ;
V_12 -> V_129 -> V_76 = NULL ;
}
return 1 ;
}
return 0 ;
}
static void F_66 ( T_1 * V_12 , T_11 * V_90 )
{
if ( ( V_90 -> time == 0 ) || ( V_90 -> time > ( V_12 -> time + V_12 -> V_20 ) ) )
{
( void ) F_45 ( V_90 -> V_133 , V_12 ) ;
F_40 ( V_90 -> V_96 , V_12 ) ;
V_12 -> V_101 = 1 ;
if ( V_90 -> V_96 -> V_102 != NULL )
V_90 -> V_96 -> V_102 ( V_90 -> V_96 , V_12 ) ;
F_26 ( V_12 ) ;
}
}
static void F_40 ( T_7 * V_96 , T_1 * V_12 )
{
if ( ( V_12 -> V_22 == NULL ) || ( V_12 -> V_21 == NULL ) ) return;
if ( V_12 -> V_22 == ( T_1 * ) & ( V_96 -> V_98 ) )
{
if ( V_12 -> V_21 == ( T_1 * ) & ( V_96 -> V_134 ) )
{
V_96 -> V_134 = NULL ;
V_96 -> V_98 = NULL ;
}
else
{
V_96 -> V_98 = V_12 -> V_21 ;
V_12 -> V_21 -> V_22 = ( T_1 * ) & ( V_96 -> V_98 ) ;
}
}
else
{
if ( V_12 -> V_21 == ( T_1 * ) & ( V_96 -> V_134 ) )
{
V_96 -> V_134 = V_12 -> V_22 ;
V_12 -> V_22 -> V_21 = ( T_1 * ) & ( V_96 -> V_134 ) ;
}
else
{
V_12 -> V_22 -> V_21 = V_12 -> V_21 ;
V_12 -> V_21 -> V_22 = V_12 -> V_22 ;
}
}
V_12 -> V_21 = V_12 -> V_22 = NULL ;
}
static void F_41 ( T_7 * V_96 , T_1 * V_12 )
{
if ( ( V_12 -> V_22 != NULL ) && ( V_12 -> V_21 != NULL ) )
F_40 ( V_96 , V_12 ) ;
if ( V_96 -> V_134 == NULL )
{
V_96 -> V_134 = V_12 ;
V_96 -> V_98 = V_12 ;
V_12 -> V_21 = ( T_1 * ) & ( V_96 -> V_134 ) ;
V_12 -> V_22 = ( T_1 * ) & ( V_96 -> V_98 ) ;
}
else
{
V_12 -> V_22 = V_96 -> V_134 ;
V_12 -> V_22 -> V_21 = V_12 ;
V_12 -> V_21 = ( T_1 * ) & ( V_96 -> V_134 ) ;
V_96 -> V_134 = V_12 ;
}
}
void F_67 ( T_7 * V_96 ,
int (* V_40)( struct V_135 * V_1 , T_1 * V_3 ) )
{
V_96 -> V_136 = V_40 ;
}
void F_68 ( T_7 * V_96 ,
void (* V_40)( T_7 * V_96 , T_1 * V_3 ) )
{
V_96 -> V_102 = V_40 ;
}
void F_69 ( T_7 * V_96 ,
T_1 * (* V_40)( struct V_135 * V_1 ,
unsigned char * V_76 , int V_32 , int * V_81 ) )
{
V_96 -> V_80 = V_40 ;
}
void F_70 ( T_7 * V_96 ,
void (* V_40)( const T_2 * V_1 , int type , int V_137 ) )
{
V_96 -> V_138 = V_40 ;
}
void F_71 ( T_7 * V_96 ,
int (* V_40)( T_2 * V_1 , T_9 * * V_139 , T_12 * * V_140 ) )
{
V_96 -> V_141 = V_40 ;
}
int F_72 ( T_7 * V_96 , T_13 * V_142 )
{
if ( ! F_73 ( V_142 ) )
{
F_13 ( V_143 , V_144 ) ;
return 0 ;
}
if( ! F_74 ( V_142 ) )
{
F_13 ( V_143 , V_145 ) ;
F_75 ( V_142 ) ;
return 0 ;
}
V_96 -> V_146 = V_142 ;
return 1 ;
}
void F_76 ( T_7 * V_96 ,
int (* V_40)( T_2 * V_1 , unsigned char * V_147 , unsigned int * V_148 ) )
{
V_96 -> V_149 = V_40 ;
}
void F_77 ( T_7 * V_96 ,
int (* V_40)( T_2 * V_1 , unsigned char * V_147 , unsigned int V_148 ) )
{
V_96 -> V_150 = V_40 ;
}

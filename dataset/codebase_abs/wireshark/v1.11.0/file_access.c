static T_1 * F_1 ( T_1 * V_1 , const T_2 * V_2 ,
T_1 * V_3 )
{
T_1 * V_4 ;
V_1 = F_2 ( V_1 , F_3 ( V_2 ) ) ;
for ( V_4 = V_3 ;
V_4 != NULL ;
V_4 = F_4 ( V_4 ) ) {
V_1 = F_2 ( V_1 ,
F_5 ( L_1 , V_2 ,
( T_2 * ) V_4 -> V_5 ) ) ;
}
return V_1 ;
}
static void F_6 ( void ) {
if ( V_6 ) return;
V_6 = F_7 ( FALSE , TRUE , sizeof( struct V_7 ) ) ;
F_8 ( V_6 , V_8 , V_9 ) ;
V_10 = (struct V_7 * ) ( void * ) V_6 -> V_5 ;
}
void F_9 ( const struct V_7 * V_11 ) {
F_6 () ;
F_10 ( V_6 , * V_11 ) ;
V_10 = ( const struct V_7 * ) ( void * ) V_6 -> V_5 ;
}
T_1 * F_11 ( void )
{
T_1 * V_3 ;
T_1 * V_1 ;
unsigned int V_12 ;
T_2 * * V_13 , * * V_14 , * V_2 ;
F_6 () ;
V_1 = NULL ;
V_3 = F_12 () ;
for ( V_12 = 0 ; V_12 < V_6 -> V_15 ; V_12 ++ ) {
V_13 = F_13 ( V_10 [ V_12 ] . V_1 ,
L_2 , 0 ) ;
for ( V_14 = V_13 ; * V_14 != NULL ;
V_14 ++ ) {
V_2 = * V_14 ;
V_1 = F_1 ( V_1 , V_2 ,
V_3 ) ;
}
F_14 ( V_13 ) ;
}
F_15 ( V_3 ) ;
return V_1 ;
}
static void F_16 ( void ) {
if ( V_16 ) return;
V_16 = F_7 ( FALSE , TRUE , sizeof( V_17 ) ) ;
F_8 ( V_16 , V_18 , V_19 ) ;
V_20 = ( V_17 * ) ( void * ) V_16 -> V_5 ;
}
void F_17 ( V_17 V_21 , T_3 V_22 ) {
F_16 () ;
if ( V_22 )
F_18 ( V_16 , V_21 ) ;
else
F_10 ( V_16 , V_21 ) ;
V_20 = ( V_17 * ) ( void * ) V_16 -> V_5 ;
}
T_4 * F_19 ( const char * V_23 , int * V_24 , char * * V_25 ,
T_3 V_26 )
{
int V_27 ;
T_5 V_28 ;
T_4 * V_29 ;
unsigned int V_12 ;
T_3 V_30 = FALSE ;
if ( strcmp ( V_23 , L_3 ) == 0 )
V_30 = TRUE ;
if ( V_30 ) {
if ( F_20 ( 0 , & V_28 ) < 0 ) {
* V_24 = V_31 ;
return NULL ;
}
} else {
if ( F_21 ( V_23 , & V_28 ) < 0 ) {
* V_24 = V_31 ;
return NULL ;
}
}
if ( F_22 ( V_28 . V_32 ) ) {
if ( V_26 ) {
* V_24 = V_33 ;
return NULL ;
}
} else if ( F_23 ( V_28 . V_32 ) ) {
* V_24 = V_34 ;
return NULL ;
} else if ( ! F_24 ( V_28 . V_32 ) ) {
* V_24 = V_35 ;
return NULL ;
}
if ( V_30 && V_26 ) {
* V_24 = V_36 ;
return NULL ;
}
V_31 = V_37 ;
V_29 = ( T_4 * ) F_25 ( sizeof( T_4 ) ) ;
V_31 = V_38 ;
if ( V_30 ) {
V_27 = F_26 ( 0 ) ;
if ( V_27 < 0 ) {
* V_24 = V_31 ;
F_27 ( V_29 ) ;
return NULL ;
}
#ifdef F_28
if ( F_29 ( V_27 , V_39 ) == - 1 ) {
* V_24 = V_31 ;
F_27 ( V_29 ) ;
return NULL ;
}
#endif
if ( ! ( V_29 -> V_40 = F_30 ( V_27 ) ) ) {
* V_24 = V_31 ;
F_31 ( V_27 ) ;
F_27 ( V_29 ) ;
return NULL ;
}
} else {
if ( ! ( V_29 -> V_40 = F_32 ( V_23 ) ) ) {
* V_24 = V_31 ;
F_27 ( V_29 ) ;
return NULL ;
}
}
if ( V_26 ) {
if ( ! ( V_29 -> V_41 = F_32 ( V_23 ) ) ) {
* V_24 = V_31 ;
F_33 ( V_29 -> V_40 ) ;
F_27 ( V_29 ) ;
return NULL ;
}
} else
V_29 -> V_41 = NULL ;
V_29 -> V_42 = V_43 ;
V_29 -> V_44 = NULL ;
V_29 -> V_45 = NULL ;
V_29 -> V_46 = V_47 ;
V_29 -> V_48 = NULL ;
F_16 () ;
if ( V_29 -> V_41 ) {
V_29 -> V_49 = F_34 () ;
F_35 ( V_29 -> V_40 , FALSE , V_29 -> V_49 ) ;
F_35 ( V_29 -> V_41 , TRUE , V_29 -> V_49 ) ;
}
for ( V_12 = 0 ; V_12 < V_16 -> V_15 ; V_12 ++ ) {
if ( F_36 ( V_29 -> V_40 , 0 , V_50 , V_24 ) == - 1 ) {
F_37 ( V_29 ) ;
return NULL ;
}
switch ( (* V_20 [ V_12 ])( V_29 , V_24 , V_25 ) ) {
case - 1 :
F_37 ( V_29 ) ;
return NULL ;
case 0 :
break;
case 1 :
goto V_51;
}
}
F_37 ( V_29 ) ;
* V_24 = V_52 ;
return NULL ;
V_51:
V_29 -> V_53 = (struct V_54 * ) F_38 ( sizeof( struct V_54 ) ) ;
F_39 ( V_29 -> V_53 , 1500 ) ;
if( V_29 -> V_55 == V_56 ) {
T_6 V_57 ;
V_57 . V_58 = V_29 -> V_42 ;
V_57 . V_59 = 1000000 ;
V_57 . V_60 = F_40 ( V_29 -> V_42 ) ;
V_57 . V_61 = V_29 -> V_62 ;
V_57 . V_63 = NULL ;
V_57 . V_64 = NULL ;
V_57 . V_65 = NULL ;
V_57 . V_66 = 0 ;
V_57 . V_67 = 6 ;
V_57 . V_68 = NULL ;
V_57 . V_69 = 0 ;
V_57 . V_70 = NULL ;
V_57 . V_71 = NULL ;
V_57 . V_72 = - 1 ;
V_57 . V_73 = 0 ;
V_57 . V_74 = NULL ;
V_29 -> V_75 = 1 ;
V_29 -> V_76 = F_7 ( FALSE , FALSE , sizeof( T_6 ) ) ;
F_10 ( V_29 -> V_76 , V_57 ) ;
}
return V_29 ;
}
T_3
F_41 ( T_4 * V_29 , const char * V_23 , int * V_24 )
{
T_5 V_28 ;
if ( strcmp ( V_23 , L_3 ) == 0 ) {
* V_24 = V_36 ;
return FALSE ;
}
if ( F_21 ( V_23 , & V_28 ) < 0 ) {
* V_24 = V_31 ;
return FALSE ;
}
if ( F_22 ( V_28 . V_32 ) ) {
* V_24 = V_33 ;
return FALSE ;
} else if ( F_23 ( V_28 . V_32 ) ) {
* V_24 = V_34 ;
return FALSE ;
} else if ( ! F_24 ( V_28 . V_32 ) ) {
* V_24 = V_35 ;
return FALSE ;
}
V_31 = V_38 ;
if ( ! F_42 ( V_29 -> V_41 , V_23 ) ) {
* V_24 = V_31 ;
return FALSE ;
}
return TRUE ;
}
static void F_43 ( void ) {
if ( V_77 ) return;
V_77 = F_7 ( FALSE , TRUE , sizeof( struct V_78 ) ) ;
F_8 ( V_77 , V_79 , V_80 ) ;
V_81 = ( const struct V_78 * ) ( void * ) V_77 -> V_5 ;
}
int F_44 ( const struct V_78 * V_82 ) {
F_43 () ;
F_10 ( V_77 , * V_82 ) ;
V_81 = ( const struct V_78 * ) ( void * ) V_77 -> V_5 ;
return V_80 ++ ;
}
int F_45 ( void )
{
return V_80 ;
}
int
F_46 ( const T_7 * V_83 )
{
int V_84 ;
V_84 = V_85 ;
if ( V_83 -> V_15 == 1 ) {
V_84 = F_47 ( V_83 , V_86 , 0 ) ;
}
return V_84 ;
}
static T_3
F_48 ( int V_87 , int V_84 )
{
if ( V_87 < 0 || V_87 >= V_80
|| V_81 [ V_87 ] . V_88 == NULL )
return FALSE ;
if ( ( * V_81 [ V_87 ] . V_88 ) ( V_84 ) != 0 )
return FALSE ;
return TRUE ;
}
static T_3
F_49 ( int V_89 , const T_7 * V_83 ,
T_8 V_90 )
{
T_9 V_12 ;
if ( ! F_50 ( V_89 ) ) {
return FALSE ;
}
if ( ! F_51 ( V_89 , V_90 ) ) {
return FALSE ;
}
if ( ! F_48 ( V_89 , F_46 ( V_83 ) ) ) {
return FALSE ;
}
for ( V_12 = 0 ; V_12 < V_83 -> V_15 ; V_12 ++ ) {
if ( ! F_48 ( V_89 ,
F_47 ( V_83 , int , V_12 ) ) ) {
return FALSE ;
}
}
return TRUE ;
}
T_3
F_52 ( const T_7 * V_83 , T_8 V_90 )
{
int V_89 ;
for ( V_89 = 0 ; V_89 < V_91 ; V_89 ++ ) {
if ( F_49 ( V_89 , V_83 , V_90 ) ) {
return TRUE ;
}
}
return FALSE ;
}
T_7 *
F_53 ( int V_55 , const T_7 * V_83 ,
T_8 V_90 )
{
T_7 * V_92 ;
int V_89 ;
int V_93 = - 1 ;
int V_94 = - 1 ;
if ( F_49 ( V_55 , V_83 ,
V_90 ) ) {
V_93 = V_55 ;
} else {
V_93 = - 1 ;
for ( V_89 = 0 ; V_89 < V_91 ; V_89 ++ ) {
if ( F_49 ( V_89 , V_83 ,
V_90 ) ) {
V_93 = V_89 ;
}
}
}
if ( V_93 == - 1 ) {
return NULL ;
}
V_92 = F_7 ( FALSE , FALSE , ( T_9 ) sizeof ( int ) ) ;
F_10 ( V_92 , V_93 ) ;
if ( V_93 == V_56 ) {
if ( F_49 ( V_95 , V_83 ,
V_90 ) )
V_94 = V_95 ;
} else if ( V_93 == V_95 ) {
if ( F_49 ( V_56 , V_83 ,
V_90 ) )
V_94 = V_56 ;
}
if ( V_94 != - 1 )
F_10 ( V_92 , V_94 ) ;
for ( V_89 = 0 ; V_89 < V_91 ; V_89 ++ ) {
if ( V_89 == V_96 )
continue;
if ( V_89 == V_93 || V_89 == V_94 )
continue;
if ( F_49 ( V_89 , V_83 ,
V_90 ) ) {
F_10 ( V_92 , V_89 ) ;
}
}
return V_92 ;
}
const char * F_54 ( int V_87 )
{
if ( V_87 < 0 || V_87 >= V_80 ) {
F_55 ( L_4 , V_87 ) ;
return L_5 ;
} else
return V_81 [ V_87 ] . V_97 ;
}
const char * F_56 ( int V_87 )
{
if ( V_87 < 0 || V_87 >= V_80 )
return NULL ;
else
return V_81 [ V_87 ] . V_98 ;
}
int F_57 ( const char * V_98 )
{
int V_87 ;
for ( V_87 = 0 ; V_87 < V_80 ; V_87 ++ ) {
if ( V_81 [ V_87 ] . V_98 != NULL &&
strcmp ( V_98 , V_81 [ V_87 ] . V_98 ) == 0 )
return V_87 ;
}
if ( strcmp ( V_98 , L_6 ) == 0 )
return V_56 ;
return - 1 ;
}
static T_1 *
F_58 ( int V_87 , T_1 * V_1 ,
T_1 * V_3 )
{
T_2 * * V_13 , * * V_14 ;
T_2 * V_2 ;
V_1 = F_1 ( V_1 ,
V_81 [ V_87 ] . V_99 ,
V_3 ) ;
if ( V_81 [ V_87 ] . V_100 != NULL ) {
V_13 = F_13 ( V_81 [ V_87 ] . V_100 ,
L_2 , 0 ) ;
for ( V_14 = V_13 ; * V_14 != NULL ;
V_14 ++ ) {
V_2 = * V_14 ;
V_1 = F_1 ( V_1 , V_2 ,
V_3 ) ;
}
F_14 ( V_13 ) ;
}
return V_1 ;
}
T_1 * F_59 ( int V_87 , T_3 V_101 )
{
T_1 * V_3 ;
T_1 * V_1 ;
if ( V_87 < 0 || V_87 >= V_80 )
return NULL ;
if ( V_81 [ V_87 ] . V_99 == NULL )
return NULL ;
V_1 = NULL ;
if ( V_101 )
V_3 = F_12 () ;
else
V_3 = NULL ;
V_1 = F_58 ( V_87 , V_1 ,
V_3 ) ;
F_15 ( V_3 ) ;
return V_1 ;
}
void F_60 ( T_1 * V_1 )
{
T_1 * V_2 ;
for ( V_2 = V_1 ; V_2 != NULL ;
V_2 = F_4 ( V_2 ) ) {
F_27 ( V_2 -> V_5 ) ;
}
F_15 ( V_1 ) ;
}
const char * F_61 ( int V_87 )
{
if ( V_87 < 0 || V_87 >= V_80 )
return NULL ;
else
return V_81 [ V_87 ] . V_99 ;
}
T_3 F_50 ( int V_87 )
{
if ( V_87 < 0 || V_87 >= V_80
|| V_81 [ V_87 ] . V_102 == NULL )
return FALSE ;
return TRUE ;
}
T_3 F_62 ( int V_87 )
{
if ( V_87 < 0 || V_87 >= V_80
|| V_81 [ V_87 ] . V_103 )
return FALSE ;
return TRUE ;
}
T_3 F_62 ( int V_87 V_104 )
{
return FALSE ;
}
T_3 F_63 ( int V_87 )
{
if ( V_87 < 0 || V_87 >= V_80
|| V_81 [ V_87 ] . V_105 == FALSE )
return FALSE ;
return TRUE ;
}
T_3 F_51 ( int V_87 , T_8 V_106 )
{
T_8 V_107 ;
if ( V_87 < 0 || V_87 >= V_80 )
return FALSE ;
V_107 = V_81 [ V_87 ] . V_107 ;
if ( ( V_106 & V_107 ) == V_106 )
return TRUE ;
return FALSE ;
}
T_10 * F_64 ( const char * V_23 , int V_87 , int V_84 ,
int V_108 , T_3 V_109 , int * V_24 )
{
return F_65 ( V_23 , V_87 , V_84 , V_108 , V_109 , NULL , NULL , V_24 ) ;
}
static T_10 *
F_66 ( int V_87 , int V_84 , int V_108 , T_3 V_109 ,
T_11 * V_110 , T_12 * V_111 , int * V_24 )
{
T_10 * V_112 ;
V_112 = F_67 ( V_87 , V_84 , V_108 , V_109 , V_24 ) ;
if ( V_112 == NULL )
return NULL ;
V_112 -> V_110 = V_110 ;
if ( ( V_111 != NULL ) && ( V_111 -> V_75 > 0 ) ) {
V_112 -> V_75 = V_111 -> V_75 ;
V_112 -> V_76 = V_111 -> V_76 ;
} else {
T_6 V_57 ;
V_57 . V_58 = V_84 ;
V_57 . V_59 = 1000000 ;
V_57 . V_60 = F_40 ( V_84 ) ;
V_57 . V_61 = V_108 ;
V_57 . V_63 = NULL ;
V_57 . V_64 = F_3 ( L_7 ) ;
V_57 . V_65 = NULL ;
V_57 . V_66 = 0 ;
V_57 . V_67 = 6 ;
V_57 . V_68 = NULL ;
V_57 . V_69 = 0 ;
V_57 . V_70 = NULL ;
V_57 . V_71 = NULL ;
V_57 . V_72 = - 1 ;
V_57 . V_73 = 0 ;
V_57 . V_74 = NULL ;
V_112 -> V_75 = 1 ;
V_112 -> V_76 = F_7 ( FALSE , FALSE , sizeof( T_6 ) ) ;
F_10 ( V_112 -> V_76 , V_57 ) ;
}
return V_112 ;
}
T_10 * F_65 ( const char * V_23 , int V_87 , int V_84 ,
int V_108 , T_3 V_109 , T_11 * V_110 , T_12 * V_111 , int * V_24 )
{
T_10 * V_112 ;
T_13 V_40 ;
if ( ! F_68 ( V_87 , V_84 , V_109 , V_24 ) )
return NULL ;
V_112 = F_66 ( V_87 , V_84 , V_108 , V_109 ,
V_110 , V_111 , V_24 ) ;
if ( V_112 == NULL )
return NULL ;
if ( strcmp ( V_23 , L_3 ) == 0 ) {
if ( V_109 ) {
* V_24 = V_113 ;
F_27 ( V_112 ) ;
return NULL ;
}
#ifdef F_28
if ( F_29 ( fileno ( stdout ) , V_39 ) == - 1 ) {
* V_24 = V_31 ;
F_27 ( V_112 ) ;
return NULL ;
}
#endif
V_112 -> V_40 = stdout ;
} else {
V_31 = V_38 ;
V_40 = F_69 ( V_112 , V_23 ) ;
if ( V_40 == NULL ) {
* V_24 = V_31 ;
F_27 ( V_112 ) ;
return NULL ;
}
V_112 -> V_40 = V_40 ;
}
if ( ! F_70 ( V_112 , V_87 , V_109 , V_24 ) ) {
if ( V_112 -> V_40 != stdout ) {
F_71 ( V_112 ) ;
F_72 ( V_23 ) ;
}
F_27 ( V_112 ) ;
return NULL ;
}
return V_112 ;
}
T_10 * F_73 ( int V_27 , int V_87 , int V_84 , int V_108 ,
T_3 V_109 , int * V_24 )
{
return F_74 ( V_27 , V_87 , V_84 , V_108 , V_109 , NULL , NULL , V_24 ) ;
}
T_10 * F_74 ( int V_27 , int V_87 , int V_84 , int V_108 ,
T_3 V_109 , T_11 * V_110 , T_12 * V_111 , int * V_24 )
{
T_10 * V_112 ;
T_13 V_40 ;
if ( ! F_68 ( V_87 , V_84 , V_109 , V_24 ) )
return NULL ;
V_112 = F_66 ( V_87 , V_84 , V_108 , V_109 ,
V_110 , V_111 , V_24 ) ;
if ( V_112 == NULL )
return NULL ;
#ifdef F_28
if ( V_27 == 1 ) {
if ( F_29 ( fileno ( stdout ) , V_39 ) == - 1 ) {
* V_24 = V_31 ;
F_27 ( V_112 ) ;
return NULL ;
}
}
#endif
V_31 = V_38 ;
V_40 = F_75 ( V_112 , V_27 ) ;
if ( V_40 == NULL ) {
* V_24 = V_31 ;
F_27 ( V_112 ) ;
return NULL ;
}
V_112 -> V_40 = V_40 ;
if ( ! F_70 ( V_112 , V_87 , V_109 , V_24 ) ) {
F_71 ( V_112 ) ;
F_27 ( V_112 ) ;
return NULL ;
}
return V_112 ;
}
static T_3 F_68 ( int V_87 , int V_84 , T_3 V_109 , int * V_24 )
{
if ( ! F_50 ( V_87 ) ) {
* V_24 = V_114 ;
return FALSE ;
}
* V_24 = ( * V_81 [ V_87 ] . V_88 ) ( V_84 ) ;
if ( * V_24 != 0 )
return FALSE ;
if( V_109 && ! F_62 ( V_87 ) ) {
* V_24 = V_115 ;
return FALSE ;
}
* V_24 = ( * V_81 [ V_87 ] . V_88 ) ( V_84 ) ;
if ( * V_24 != 0 )
return FALSE ;
return TRUE ;
}
static T_10 * F_67 ( int V_87 , int V_84 , int V_108 ,
T_3 V_109 , int * V_24 )
{
T_10 * V_112 ;
V_112 = ( T_10 * ) F_25 ( sizeof ( T_10 ) ) ;
if ( V_112 == NULL ) {
* V_24 = V_31 ;
return NULL ;
}
V_112 -> V_55 = V_87 ;
V_112 -> V_108 = V_108 ;
V_112 -> V_84 = V_84 ;
V_112 -> V_109 = V_109 ;
return V_112 ;
}
static T_3 F_70 ( T_10 * V_112 , int V_87 , T_3 V_109 , int * V_24 )
{
int V_27 ;
T_3 V_116 ;
if( V_109 ) {
V_116 = TRUE ;
} else {
V_27 = fileno ( ( V_117 * ) V_112 -> V_40 ) ;
if ( F_76 ( V_27 , 1 , V_118 ) == - 1 )
V_116 = TRUE ;
else {
F_76 ( V_27 , 0 , V_50 ) ;
V_116 = FALSE ;
}
}
if ( V_81 [ V_87 ] . V_103 && V_116 ) {
* V_24 = V_119 ;
return FALSE ;
}
if ( ! ( * V_81 [ V_87 ] . V_102 ) ( V_112 , V_24 ) ) {
return FALSE ;
}
return TRUE ;
}
T_3 F_77 ( T_10 * V_112 , const struct V_120 * V_121 ,
const T_14 * V_122 , int * V_24 )
{
return ( V_112 -> V_123 ) ( V_112 , V_121 , V_122 , V_24 ) ;
}
void F_78 ( T_10 * V_112 )
{
#ifdef F_79
if( V_112 -> V_109 ) {
F_80 ( ( V_124 ) V_112 -> V_40 ) ;
} else
#endif
{
fflush ( ( V_117 * ) V_112 -> V_40 ) ;
}
}
T_3 F_81 ( T_10 * V_112 , int * V_24 )
{
T_3 V_125 = TRUE ;
if ( V_112 -> V_45 != NULL ) {
if ( ! ( V_112 -> V_45 ) ( V_112 , V_24 ) )
V_125 = FALSE ;
}
V_31 = V_126 ;
if ( V_112 -> V_40 != stdout ) {
if ( F_71 ( V_112 ) == V_127 ) {
if ( V_125 ) {
if ( V_24 != NULL )
* V_24 = V_31 ;
}
V_125 = FALSE ;
}
} else {
F_78 ( V_112 ) ;
}
if ( V_112 -> V_48 != NULL )
F_27 ( V_112 -> V_48 ) ;
F_27 ( V_112 ) ;
return V_125 ;
}
T_15 F_82 ( T_10 * V_112 )
{
return V_112 -> V_128 ;
}
void F_83 ( T_10 * V_112 , T_15 V_128 )
{
V_112 -> V_128 = V_128 ;
}
T_3 F_84 ( T_10 * V_112 , T_16 * V_129 )
{
if ( ! V_112 || V_112 -> V_55 < 0 || V_112 -> V_55 >= V_80
|| V_81 [ V_112 -> V_55 ] . V_105 == FALSE )
return FALSE ;
V_112 -> V_129 = V_129 ;
return TRUE ;
}
static T_13 F_69 ( T_10 * V_112 , const char * V_23 )
{
if( V_112 -> V_109 ) {
return F_85 ( V_23 ) ;
} else {
return F_86 ( V_23 , L_8 ) ;
}
}
static T_13 F_69 ( T_10 * V_112 V_104 , const char * V_23 )
{
return F_86 ( V_23 , L_8 ) ;
}
static T_13 F_75 ( T_10 * V_112 , int V_27 )
{
if( V_112 -> V_109 ) {
return F_87 ( V_27 ) ;
} else {
return fdopen ( V_27 , L_8 ) ;
}
}
static T_13 F_75 ( T_10 * V_112 V_104 , int V_27 )
{
return fdopen ( V_27 , L_8 ) ;
}
T_3 F_88 ( T_10 * V_112 , const void * V_130 , T_17 V_131 ,
int * V_24 )
{
T_17 V_132 ;
#ifdef F_79
if ( V_112 -> V_109 ) {
V_132 = F_89 ( ( V_124 ) V_112 -> V_40 , V_130 , ( unsigned ) V_131 ) ;
if ( V_132 == 0 ) {
* V_24 = F_90 ( ( V_124 ) V_112 -> V_40 ) ;
return FALSE ;
}
} else
#endif
{
V_132 = fwrite ( V_130 , 1 , V_131 , ( V_117 * ) V_112 -> V_40 ) ;
if ( V_132 != V_131 ) {
if ( ferror ( ( V_117 * ) V_112 -> V_40 ) )
* V_24 = V_31 ;
else
* V_24 = V_133 ;
return FALSE ;
}
}
return TRUE ;
}
static int F_71 ( T_10 * V_112 )
{
#ifdef F_79
if( V_112 -> V_109 ) {
return F_91 ( ( V_124 ) V_112 -> V_40 ) ;
} else
#endif
{
return fclose ( ( V_117 * ) V_112 -> V_40 ) ;
}
}
T_15 F_92 ( T_10 * V_112 , T_15 V_134 , int V_135 , int * V_24 )
{
#ifdef F_79
if( V_112 -> V_109 ) {
* V_24 = V_136 ;
return - 1 ;
} else
#endif
{
if ( - 1 == fseek ( ( V_117 * ) V_112 -> V_40 , ( long ) V_134 , V_135 ) ) {
* V_24 = V_31 ;
return - 1 ;
} else
{
return 0 ;
}
}
}
T_15 F_93 ( T_10 * V_112 , int * V_24 )
{
T_15 V_137 ;
#ifdef F_79
if( V_112 -> V_109 ) {
* V_24 = V_136 ;
return - 1 ;
} else
#endif
{
if ( - 1 == ( V_137 = ftell ( ( V_117 * ) V_112 -> V_40 ) ) ) {
* V_24 = V_31 ;
return - 1 ;
} else
{
return V_137 ;
}
}
}

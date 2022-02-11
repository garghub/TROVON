static void F_1 ( void ) {
if ( V_1 ) return;
V_1 = F_2 ( FALSE , TRUE , sizeof( V_2 ) ) ;
F_3 ( V_1 , V_3 , V_4 ) ;
V_5 = ( V_2 * ) ( void * ) V_1 -> V_6 ;
}
void F_4 ( V_2 V_7 , T_1 V_8 ) {
F_1 () ;
if ( V_8 )
F_5 ( V_1 , V_7 ) ;
else
F_6 ( V_1 , V_7 ) ;
V_5 = ( V_2 * ) ( void * ) V_1 -> V_6 ;
}
T_2 * F_7 ( const char * V_9 , int * V_10 , char * * V_11 ,
T_1 V_12 )
{
int V_13 ;
T_3 V_14 ;
T_2 * V_15 ;
unsigned int V_16 ;
T_1 V_17 = FALSE ;
if ( strcmp ( V_9 , L_1 ) == 0 )
V_17 = TRUE ;
if ( V_17 ) {
if ( F_8 ( 0 , & V_14 ) < 0 ) {
* V_10 = V_18 ;
return NULL ;
}
} else {
if ( F_9 ( V_9 , & V_14 ) < 0 ) {
* V_10 = V_18 ;
return NULL ;
}
}
if ( F_10 ( V_14 . V_19 ) ) {
if ( V_12 ) {
* V_10 = V_20 ;
return NULL ;
}
} else if ( F_11 ( V_14 . V_19 ) ) {
* V_10 = V_21 ;
return NULL ;
} else if ( ! F_12 ( V_14 . V_19 ) ) {
* V_10 = V_22 ;
return NULL ;
}
if ( V_17 && V_12 ) {
* V_10 = V_23 ;
return NULL ;
}
V_18 = V_24 ;
V_15 = ( T_2 * ) F_13 ( sizeof( T_2 ) ) ;
V_18 = V_25 ;
if ( V_17 ) {
V_13 = F_14 ( 0 ) ;
if ( V_13 < 0 ) {
* V_10 = V_18 ;
F_15 ( V_15 ) ;
return NULL ;
}
#ifdef F_16
if ( F_17 ( V_13 , V_26 ) == - 1 ) {
* V_10 = V_18 ;
F_15 ( V_15 ) ;
return NULL ;
}
#endif
if ( ! ( V_15 -> V_27 = F_18 ( V_13 ) ) ) {
* V_10 = V_18 ;
F_19 ( V_13 ) ;
F_15 ( V_15 ) ;
return NULL ;
}
} else {
if ( ! ( V_15 -> V_27 = F_20 ( V_9 ) ) ) {
* V_10 = V_18 ;
F_15 ( V_15 ) ;
return NULL ;
}
}
if ( V_12 ) {
if ( ! ( V_15 -> V_28 = F_20 ( V_9 ) ) ) {
* V_10 = V_18 ;
F_21 ( V_15 -> V_27 ) ;
F_15 ( V_15 ) ;
return NULL ;
}
} else
V_15 -> V_28 = NULL ;
V_15 -> V_29 = V_30 ;
V_15 -> V_31 = NULL ;
V_15 -> V_32 = NULL ;
V_15 -> V_33 = V_34 ;
V_15 -> V_35 = NULL ;
F_1 () ;
if ( V_15 -> V_28 ) {
V_15 -> V_36 = F_22 () ;
F_23 ( V_15 -> V_27 , FALSE , V_15 -> V_36 ) ;
F_23 ( V_15 -> V_28 , TRUE , V_15 -> V_36 ) ;
}
for ( V_16 = 0 ; V_16 < V_1 -> V_37 ; V_16 ++ ) {
if ( F_24 ( V_15 -> V_27 , 0 , V_38 , V_10 ) == - 1 ) {
F_25 ( V_15 ) ;
return NULL ;
}
switch ( (* V_5 [ V_16 ])( V_15 , V_10 , V_11 ) ) {
case - 1 :
F_25 ( V_15 ) ;
return NULL ;
case 0 :
break;
case 1 :
goto V_39;
}
}
F_25 ( V_15 ) ;
* V_10 = V_40 ;
return NULL ;
V_39:
V_15 -> V_41 = (struct V_42 * ) F_26 ( sizeof( struct V_42 ) ) ;
F_27 ( V_15 -> V_41 , 1500 ) ;
if( V_15 -> V_43 == V_44 ) {
T_4 V_45 ;
V_45 . V_46 = V_15 -> V_29 ;
V_45 . V_47 = 1000000 ;
V_45 . V_48 = F_28 ( V_15 -> V_29 ) ;
V_45 . V_49 = V_15 -> V_50 ;
V_45 . V_51 = NULL ;
V_45 . V_52 = NULL ;
V_45 . V_53 = NULL ;
V_45 . V_54 = 0 ;
V_45 . V_55 = 6 ;
V_45 . V_56 = NULL ;
V_45 . V_57 = 0 ;
V_45 . V_58 = NULL ;
V_45 . V_59 = NULL ;
V_45 . V_60 = - 1 ;
V_45 . V_61 = 0 ;
V_45 . V_62 = NULL ;
V_15 -> V_63 = 1 ;
V_15 -> V_64 = F_2 ( FALSE , FALSE , sizeof( T_4 ) ) ;
F_6 ( V_15 -> V_64 , V_45 ) ;
}
return V_15 ;
}
T_1
F_29 ( T_2 * V_15 , const char * V_9 , int * V_10 )
{
T_3 V_14 ;
if ( strcmp ( V_9 , L_1 ) == 0 ) {
* V_10 = V_23 ;
return FALSE ;
}
if ( F_9 ( V_9 , & V_14 ) < 0 ) {
* V_10 = V_18 ;
return FALSE ;
}
if ( F_10 ( V_14 . V_19 ) ) {
* V_10 = V_20 ;
return FALSE ;
} else if ( F_11 ( V_14 . V_19 ) ) {
* V_10 = V_21 ;
return FALSE ;
} else if ( ! F_12 ( V_14 . V_19 ) ) {
* V_10 = V_22 ;
return FALSE ;
}
V_18 = V_25 ;
if ( ! F_30 ( V_15 -> V_28 , V_9 ) ) {
* V_10 = V_18 ;
return FALSE ;
}
return TRUE ;
}
static void F_31 ( void ) {
if ( V_65 ) return;
V_65 = F_2 ( FALSE , TRUE , sizeof( struct V_66 ) ) ;
F_3 ( V_65 , V_67 , V_68 ) ;
V_69 = ( const struct V_66 * ) ( void * ) V_65 -> V_6 ;
}
int F_32 ( const struct V_66 * V_70 ) {
F_31 () ;
F_6 ( V_65 , * V_70 ) ;
V_69 = ( const struct V_66 * ) ( void * ) V_65 -> V_6 ;
return V_68 ++ ;
}
int F_33 ( void )
{
return V_68 ;
}
int
F_34 ( const T_5 * V_71 )
{
int V_72 ;
V_72 = V_73 ;
if ( V_71 -> V_37 == 1 ) {
V_72 = F_35 ( V_71 , V_74 , 0 ) ;
}
return V_72 ;
}
static T_1
F_36 ( int V_75 , int V_72 )
{
if ( V_75 < 0 || V_75 >= V_68
|| V_69 [ V_75 ] . V_76 == NULL )
return FALSE ;
if ( ( * V_69 [ V_75 ] . V_76 ) ( V_72 ) != 0 )
return FALSE ;
return TRUE ;
}
static T_1
F_37 ( int V_77 , const T_5 * V_71 ,
T_6 V_78 )
{
T_7 V_16 ;
if ( ! F_38 ( V_77 ) ) {
return FALSE ;
}
if ( ! F_39 ( V_77 , V_78 ) ) {
return FALSE ;
}
if ( ! F_36 ( V_77 , F_34 ( V_71 ) ) ) {
return FALSE ;
}
for ( V_16 = 0 ; V_16 < V_71 -> V_37 ; V_16 ++ ) {
if ( ! F_36 ( V_77 ,
F_35 ( V_71 , int , V_16 ) ) ) {
return FALSE ;
}
}
return TRUE ;
}
T_1
F_40 ( const T_5 * V_71 , T_6 V_78 )
{
int V_77 ;
for ( V_77 = 0 ; V_77 < V_79 ; V_77 ++ ) {
if ( F_37 ( V_77 , V_71 , V_78 ) ) {
return TRUE ;
}
}
return FALSE ;
}
T_5 *
F_41 ( int V_43 , const T_5 * V_71 ,
T_6 V_78 )
{
T_5 * V_80 ;
int V_77 ;
int V_81 = - 1 ;
int V_82 = - 1 ;
if ( F_37 ( V_43 , V_71 ,
V_78 ) ) {
V_81 = V_43 ;
} else {
V_81 = - 1 ;
for ( V_77 = 0 ; V_77 < V_79 ; V_77 ++ ) {
if ( F_37 ( V_77 , V_71 ,
V_78 ) ) {
V_81 = V_77 ;
}
}
}
if ( V_81 == - 1 ) {
return NULL ;
}
V_80 = F_2 ( FALSE , FALSE , ( T_7 ) sizeof ( int ) ) ;
F_6 ( V_80 , V_81 ) ;
if ( V_81 == V_44 ) {
if ( F_37 ( V_83 , V_71 ,
V_78 ) )
V_82 = V_83 ;
} else if ( V_81 == V_83 ) {
if ( F_37 ( V_44 , V_71 ,
V_78 ) )
V_82 = V_44 ;
}
if ( V_82 != - 1 )
F_6 ( V_80 , V_82 ) ;
for ( V_77 = 0 ; V_77 < V_79 ; V_77 ++ ) {
if ( V_77 == V_84 )
continue;
if ( V_77 == V_81 || V_77 == V_82 )
continue;
if ( F_37 ( V_77 , V_71 ,
V_78 ) ) {
F_6 ( V_80 , V_77 ) ;
}
}
return V_80 ;
}
const char * F_42 ( int V_75 )
{
if ( V_75 < 0 || V_75 >= V_68 ) {
F_43 ( L_2 , V_75 ) ;
return L_3 ;
} else
return V_69 [ V_75 ] . V_85 ;
}
const char * F_44 ( int V_75 )
{
if ( V_75 < 0 || V_75 >= V_68 )
return NULL ;
else
return V_69 [ V_75 ] . V_86 ;
}
int F_45 ( const char * V_86 )
{
int V_75 ;
for ( V_75 = 0 ; V_75 < V_68 ; V_75 ++ ) {
if ( V_69 [ V_75 ] . V_86 != NULL &&
strcmp ( V_86 , V_69 [ V_75 ] . V_86 ) == 0 )
return V_75 ;
}
return - 1 ;
}
static T_8 * F_46 ( T_8 * V_87 , const T_9 * V_88 ,
T_8 * V_89 )
{
T_8 * V_90 ;
V_87 = F_47 ( V_87 , F_48 ( V_88 ) ) ;
for ( V_90 = V_89 ;
V_90 != NULL ;
V_90 = F_49 ( V_90 ) ) {
V_87 = F_47 ( V_87 ,
F_50 ( L_4 , V_88 ,
( T_9 * ) V_90 -> V_6 ) ) ;
}
return V_87 ;
}
T_8 * F_51 ( int V_75 , T_1 V_91 )
{
T_9 * * V_92 , * * V_93 ;
T_9 * V_88 ;
T_8 * V_89 ;
T_8 * V_87 ;
if ( V_75 < 0 || V_75 >= V_68 )
return NULL ;
if ( V_69 [ V_75 ] . V_94 == NULL )
return NULL ;
V_87 = NULL ;
if ( V_91 )
V_89 = F_52 () ;
else
V_89 = NULL ;
V_87 = F_46 ( V_87 ,
V_69 [ V_75 ] . V_94 ,
V_89 ) ;
if ( V_69 [ V_75 ] . V_95 != NULL ) {
V_92 = F_53 ( V_69 [ V_75 ] . V_95 ,
L_5 , 0 ) ;
for ( V_93 = V_92 ; * V_93 != NULL ;
V_93 ++ ) {
V_88 = * V_93 ;
V_87 = F_46 ( V_87 , V_88 ,
V_89 ) ;
}
F_54 ( V_92 ) ;
}
F_55 ( V_89 ) ;
return V_87 ;
}
void F_56 ( T_8 * V_87 )
{
T_8 * V_88 ;
for ( V_88 = V_87 ; V_88 != NULL ;
V_88 = F_49 ( V_88 ) ) {
F_15 ( V_88 -> V_6 ) ;
}
F_55 ( V_87 ) ;
}
const char * F_57 ( int V_75 )
{
if ( V_75 < 0 || V_75 >= V_68 )
return NULL ;
else
return V_69 [ V_75 ] . V_94 ;
}
T_1 F_38 ( int V_75 )
{
if ( V_75 < 0 || V_75 >= V_68
|| V_69 [ V_75 ] . V_96 == NULL )
return FALSE ;
return TRUE ;
}
T_1 F_58 ( int V_75 )
{
if ( V_75 < 0 || V_75 >= V_68
|| V_69 [ V_75 ] . V_97 )
return FALSE ;
return TRUE ;
}
T_1 F_58 ( int V_75 V_98 )
{
return FALSE ;
}
T_1 F_59 ( int V_75 )
{
if ( V_75 < 0 || V_75 >= V_68
|| V_69 [ V_75 ] . V_99 == FALSE )
return FALSE ;
return TRUE ;
}
T_1 F_39 ( int V_75 , T_6 V_100 )
{
T_6 V_101 ;
if ( V_75 < 0 || V_75 >= V_68 )
return FALSE ;
V_101 = V_69 [ V_75 ] . V_101 ;
if ( ( V_100 & V_101 ) == V_100 )
return TRUE ;
return FALSE ;
}
T_10 * F_60 ( const char * V_9 , int V_75 , int V_72 ,
int V_102 , T_1 V_103 , int * V_10 )
{
return F_61 ( V_9 , V_75 , V_72 , V_102 , V_103 , NULL , NULL , V_10 ) ;
}
static T_10 *
F_62 ( int V_75 , int V_72 , int V_102 , T_1 V_103 ,
T_11 * V_104 , T_12 * V_105 , int * V_10 )
{
T_10 * V_106 ;
V_106 = F_63 ( V_75 , V_72 , V_102 , V_103 , V_10 ) ;
if ( V_106 == NULL )
return NULL ;
V_106 -> V_104 = V_104 ;
if ( ( V_105 != NULL ) && ( V_105 -> V_63 > 0 ) ) {
V_106 -> V_63 = V_105 -> V_63 ;
V_106 -> V_64 = V_105 -> V_64 ;
} else {
T_4 V_45 ;
V_45 . V_46 = V_72 ;
V_45 . V_47 = 1000000 ;
V_45 . V_48 = F_28 ( V_72 ) ;
V_45 . V_49 = V_102 ;
V_45 . V_51 = NULL ;
V_45 . V_52 = F_48 ( L_6 ) ;
V_45 . V_53 = NULL ;
V_45 . V_54 = 0 ;
V_45 . V_55 = 6 ;
V_45 . V_56 = NULL ;
V_45 . V_57 = 0 ;
V_45 . V_58 = NULL ;
V_45 . V_59 = NULL ;
V_45 . V_60 = - 1 ;
V_45 . V_61 = 0 ;
V_45 . V_62 = NULL ;
V_106 -> V_63 = 1 ;
V_106 -> V_64 = F_2 ( FALSE , FALSE , sizeof( T_4 ) ) ;
F_6 ( V_106 -> V_64 , V_45 ) ;
}
return V_106 ;
}
T_10 * F_61 ( const char * V_9 , int V_75 , int V_72 ,
int V_102 , T_1 V_103 , T_11 * V_104 , T_12 * V_105 , int * V_10 )
{
T_10 * V_106 ;
T_13 V_27 ;
if ( ! F_64 ( V_75 , V_72 , V_103 , V_10 ) )
return NULL ;
V_106 = F_62 ( V_75 , V_72 , V_102 , V_103 ,
V_104 , V_105 , V_10 ) ;
if ( V_106 == NULL )
return NULL ;
if ( strcmp ( V_9 , L_1 ) == 0 ) {
if ( V_103 ) {
* V_10 = V_107 ;
F_15 ( V_106 ) ;
return NULL ;
}
#ifdef F_16
if ( F_17 ( fileno ( stdout ) , V_26 ) == - 1 ) {
* V_10 = V_18 ;
F_15 ( V_106 ) ;
return NULL ;
}
#endif
V_106 -> V_27 = stdout ;
} else {
V_18 = V_25 ;
V_27 = F_65 ( V_106 , V_9 ) ;
if ( V_27 == NULL ) {
* V_10 = V_18 ;
F_15 ( V_106 ) ;
return NULL ;
}
V_106 -> V_27 = V_27 ;
}
if ( ! F_66 ( V_106 , V_75 , V_103 , V_10 ) ) {
if ( V_106 -> V_27 != stdout ) {
F_67 ( V_106 ) ;
F_68 ( V_9 ) ;
}
F_15 ( V_106 ) ;
return NULL ;
}
return V_106 ;
}
T_10 * F_69 ( int V_13 , int V_75 , int V_72 , int V_102 ,
T_1 V_103 , int * V_10 )
{
return F_70 ( V_13 , V_75 , V_72 , V_102 , V_103 , NULL , NULL , V_10 ) ;
}
T_10 * F_70 ( int V_13 , int V_75 , int V_72 , int V_102 ,
T_1 V_103 , T_11 * V_104 , T_12 * V_105 , int * V_10 )
{
T_10 * V_106 ;
T_13 V_27 ;
if ( ! F_64 ( V_75 , V_72 , V_103 , V_10 ) )
return NULL ;
V_106 = F_62 ( V_75 , V_72 , V_102 , V_103 ,
V_104 , V_105 , V_10 ) ;
if ( V_106 == NULL )
return NULL ;
#ifdef F_16
if ( V_13 == 1 ) {
if ( F_17 ( fileno ( stdout ) , V_26 ) == - 1 ) {
* V_10 = V_18 ;
F_15 ( V_106 ) ;
return NULL ;
}
}
#endif
V_18 = V_25 ;
V_27 = F_71 ( V_106 , V_13 ) ;
if ( V_27 == NULL ) {
* V_10 = V_18 ;
F_15 ( V_106 ) ;
return NULL ;
}
V_106 -> V_27 = V_27 ;
if ( ! F_66 ( V_106 , V_75 , V_103 , V_10 ) ) {
F_67 ( V_106 ) ;
F_15 ( V_106 ) ;
return NULL ;
}
return V_106 ;
}
static T_1 F_64 ( int V_75 , int V_72 , T_1 V_103 , int * V_10 )
{
if ( ! F_38 ( V_75 ) ) {
* V_10 = V_108 ;
return FALSE ;
}
* V_10 = ( * V_69 [ V_75 ] . V_76 ) ( V_72 ) ;
if ( * V_10 != 0 )
return FALSE ;
if( V_103 && ! F_58 ( V_75 ) ) {
* V_10 = V_109 ;
return FALSE ;
}
* V_10 = ( * V_69 [ V_75 ] . V_76 ) ( V_72 ) ;
if ( * V_10 != 0 )
return FALSE ;
return TRUE ;
}
static T_10 * F_63 ( int V_75 , int V_72 , int V_102 ,
T_1 V_103 , int * V_10 )
{
T_10 * V_106 ;
V_106 = ( T_10 * ) F_13 ( sizeof ( T_10 ) ) ;
if ( V_106 == NULL ) {
* V_10 = V_18 ;
return NULL ;
}
V_106 -> V_43 = V_75 ;
V_106 -> V_102 = V_102 ;
V_106 -> V_72 = V_72 ;
V_106 -> V_103 = V_103 ;
return V_106 ;
}
static T_1 F_66 ( T_10 * V_106 , int V_75 , T_1 V_103 , int * V_10 )
{
int V_13 ;
T_1 V_110 ;
if( V_103 ) {
V_110 = TRUE ;
} else {
V_13 = fileno ( ( V_111 * ) V_106 -> V_27 ) ;
if ( F_72 ( V_13 , 1 , V_112 ) == - 1 )
V_110 = TRUE ;
else {
F_72 ( V_13 , 0 , V_38 ) ;
V_110 = FALSE ;
}
}
if ( V_69 [ V_75 ] . V_97 && V_110 ) {
* V_10 = V_113 ;
return FALSE ;
}
if ( ! ( * V_69 [ V_75 ] . V_96 ) ( V_106 , V_10 ) ) {
return FALSE ;
}
return TRUE ;
}
T_1 F_73 ( T_10 * V_106 , const struct V_114 * V_115 ,
const T_14 * V_116 , int * V_10 )
{
return ( V_106 -> V_117 ) ( V_106 , V_115 , V_116 , V_10 ) ;
}
void F_74 ( T_10 * V_106 )
{
#ifdef F_75
if( V_106 -> V_103 ) {
F_76 ( ( V_118 ) V_106 -> V_27 ) ;
} else
#endif
{
fflush ( ( V_111 * ) V_106 -> V_27 ) ;
}
}
T_1 F_77 ( T_10 * V_106 , int * V_10 )
{
T_1 V_119 = TRUE ;
if ( V_106 -> V_32 != NULL ) {
if ( ! ( V_106 -> V_32 ) ( V_106 , V_10 ) )
V_119 = FALSE ;
}
V_18 = V_120 ;
if ( V_106 -> V_27 != stdout ) {
if ( F_67 ( V_106 ) == V_121 ) {
if ( V_119 ) {
if ( V_10 != NULL )
* V_10 = V_18 ;
}
V_119 = FALSE ;
}
} else {
F_74 ( V_106 ) ;
}
if ( V_106 -> V_35 != NULL )
F_15 ( V_106 -> V_35 ) ;
F_15 ( V_106 ) ;
return V_119 ;
}
T_15 F_78 ( T_10 * V_106 )
{
return V_106 -> V_122 ;
}
void F_79 ( T_10 * V_106 , T_15 V_122 )
{
V_106 -> V_122 = V_122 ;
}
T_1 F_80 ( T_10 * V_106 , struct V_123 * V_124 )
{
if ( ! V_106 || V_106 -> V_43 < 0 || V_106 -> V_43 >= V_68
|| V_69 [ V_106 -> V_43 ] . V_99 == FALSE )
return FALSE ;
V_106 -> V_124 = V_124 ;
return TRUE ;
}
static T_13 F_65 ( T_10 * V_106 , const char * V_9 )
{
if( V_106 -> V_103 ) {
return F_81 ( V_9 ) ;
} else {
return F_82 ( V_9 , L_7 ) ;
}
}
static T_13 F_65 ( T_10 * V_106 V_98 , const char * V_9 )
{
return F_82 ( V_9 , L_7 ) ;
}
static T_13 F_71 ( T_10 * V_106 , int V_13 )
{
if( V_106 -> V_103 ) {
return F_83 ( V_13 ) ;
} else {
return fdopen ( V_13 , L_7 ) ;
}
}
static T_13 F_71 ( T_10 * V_106 V_98 , int V_13 )
{
return fdopen ( V_13 , L_7 ) ;
}
T_1 F_84 ( T_10 * V_106 , const void * V_125 , T_16 V_126 ,
int * V_10 )
{
T_16 V_127 ;
#ifdef F_75
if ( V_106 -> V_103 ) {
V_127 = F_85 ( ( V_118 ) V_106 -> V_27 , V_125 , ( unsigned ) V_126 ) ;
if ( V_127 == 0 ) {
* V_10 = F_86 ( ( V_118 ) V_106 -> V_27 ) ;
return FALSE ;
}
} else
#endif
{
V_127 = fwrite ( V_125 , 1 , V_126 , ( V_111 * ) V_106 -> V_27 ) ;
if ( V_127 != V_126 ) {
if ( ferror ( ( V_111 * ) V_106 -> V_27 ) )
* V_10 = V_18 ;
else
* V_10 = V_128 ;
return FALSE ;
}
}
return TRUE ;
}
static int F_67 ( T_10 * V_106 )
{
#ifdef F_75
if( V_106 -> V_103 ) {
return F_87 ( ( V_118 ) V_106 -> V_27 ) ;
} else
#endif
{
return fclose ( ( V_111 * ) V_106 -> V_27 ) ;
}
}
T_15 F_88 ( T_10 * V_106 , T_15 V_129 , int V_130 , int * V_10 )
{
#ifdef F_75
if( V_106 -> V_103 ) {
* V_10 = V_131 ;
return - 1 ;
} else
#endif
{
if ( - 1 == fseek ( ( V_111 * ) V_106 -> V_27 , ( long ) V_129 , V_130 ) ) {
* V_10 = V_18 ;
return - 1 ;
} else
{
return 0 ;
}
}
}
T_15 F_89 ( T_10 * V_106 , int * V_10 )
{
T_15 V_132 ;
#ifdef F_75
if( V_106 -> V_103 ) {
* V_10 = V_131 ;
return - 1 ;
} else
#endif
{
if ( - 1 == ( V_132 = ftell ( ( V_111 * ) V_106 -> V_27 ) ) ) {
* V_10 = V_18 ;
return - 1 ;
} else
{
return V_132 ;
}
}
}

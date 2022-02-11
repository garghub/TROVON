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
if ( V_15 -> V_28 != NULL )
F_21 ( V_15 -> V_28 ) ;
F_21 ( V_15 -> V_27 ) ;
F_15 ( V_15 ) ;
return NULL ;
}
switch ( (* V_5 [ V_16 ])( V_15 , V_10 , V_11 ) ) {
case - 1 :
if ( V_15 -> V_28 != NULL )
F_21 ( V_15 -> V_28 ) ;
F_21 ( V_15 -> V_27 ) ;
F_15 ( V_15 ) ;
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
return V_15 ;
}
T_1
F_28 ( T_2 * V_15 , const char * V_9 , int * V_10 )
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
if ( ! F_29 ( V_15 -> V_28 , V_9 ) ) {
* V_10 = V_18 ;
return FALSE ;
}
return TRUE ;
}
static void F_30 ( void ) {
if ( V_43 ) return;
V_43 = F_2 ( FALSE , TRUE , sizeof( struct V_44 ) ) ;
F_3 ( V_43 , V_45 , V_46 ) ;
V_47 = ( const struct V_44 * ) ( void * ) V_43 -> V_6 ;
}
int F_31 ( const struct V_44 * V_48 ) {
F_30 () ;
F_6 ( V_43 , * V_48 ) ;
V_47 = ( const struct V_44 * ) ( void * ) V_43 -> V_6 ;
return V_46 ++ ;
}
int F_32 ( void )
{
return V_46 ;
}
T_1
F_33 ( int V_49 , const T_4 * V_50 )
{
T_5 V_16 ;
if ( ! F_34 ( V_49 ) ) {
return FALSE ;
}
if ( V_50 -> V_37 > 1 ) {
if ( ! F_35 ( V_49 , V_51 ) )
return FALSE ;
}
for ( V_16 = 0 ; V_16 < V_50 -> V_37 ; V_16 ++ ) {
if ( ! F_35 ( V_49 ,
F_36 ( V_50 , int , V_16 ) ) )
return FALSE ;
}
return TRUE ;
}
T_4 *
F_37 ( int V_52 , const T_4 * V_50 )
{
T_4 * V_53 ;
int V_49 ;
int V_54 = - 1 ;
int V_55 = - 1 ;
if ( F_33 ( V_52 , V_50 ) ) {
V_54 = V_52 ;
} else {
if ( F_33 ( V_56 , V_50 ) ) {
V_54 = V_56 ;
} else {
V_54 = - 1 ;
for ( V_49 = 0 ; V_49 < V_57 ; V_49 ++ ) {
if ( F_33 ( V_49 , V_50 ) ) {
V_54 = V_49 ;
}
}
}
}
if ( V_54 == - 1 ) {
return NULL ;
}
V_53 = F_2 ( FALSE , FALSE , ( T_5 ) sizeof ( int ) ) ;
F_6 ( V_53 , V_54 ) ;
if ( V_54 == V_58 ) {
if ( F_33 ( V_56 , V_50 ) )
V_55 = V_56 ;
} else if ( V_54 == V_56 ) {
if ( F_33 ( V_58 , V_50 ) )
V_55 = V_58 ;
}
if ( V_55 != - 1 )
F_6 ( V_53 , V_55 ) ;
for ( V_49 = 0 ; V_49 < V_57 ; V_49 ++ ) {
if ( V_49 == V_59 )
continue;
if ( V_49 == V_54 || V_49 == V_55 )
continue;
if ( F_33 ( V_49 , V_50 ) ) {
F_6 ( V_53 , V_49 ) ;
}
}
return V_53 ;
}
const char * F_38 ( int V_60 )
{
if ( V_60 < 0 || V_60 >= V_46 ) {
F_39 ( L_2 , V_60 ) ;
return L_3 ;
} else
return V_47 [ V_60 ] . V_61 ;
}
const char * F_40 ( int V_60 )
{
if ( V_60 < 0 || V_60 >= V_46 )
return NULL ;
else
return V_47 [ V_60 ] . V_62 ;
}
int F_41 ( const char * V_62 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_46 ; V_60 ++ ) {
if ( V_47 [ V_60 ] . V_62 != NULL &&
strcmp ( V_62 , V_47 [ V_60 ] . V_62 ) == 0 )
return V_60 ;
}
return - 1 ;
}
static T_6 * F_42 ( T_6 * V_63 , const T_7 * V_64 ,
T_6 * V_65 )
{
T_6 * V_66 ;
V_63 = F_43 ( V_63 , F_44 ( V_64 ) ) ;
for ( V_66 = V_65 ;
V_66 != NULL ;
V_66 = F_45 ( V_66 ) ) {
V_63 = F_43 ( V_63 ,
F_46 ( L_4 , V_64 ,
( T_7 * ) V_66 -> V_6 ) ) ;
}
return V_63 ;
}
T_6 * F_47 ( int V_60 , T_1 V_67 )
{
T_7 * * V_68 , * * V_69 ;
T_7 * V_64 ;
T_6 * V_65 ;
T_6 * V_63 ;
if ( V_60 < 0 || V_60 >= V_46 )
return NULL ;
if ( V_47 [ V_60 ] . V_70 == NULL )
return NULL ;
V_63 = NULL ;
if ( V_67 )
V_65 = F_48 () ;
else
V_65 = NULL ;
V_63 = F_42 ( V_63 ,
V_47 [ V_60 ] . V_70 ,
V_65 ) ;
if ( V_47 [ V_60 ] . V_71 != NULL ) {
V_68 = F_49 ( V_47 [ V_60 ] . V_71 ,
L_5 , 0 ) ;
for ( V_69 = V_68 ; * V_69 != NULL ;
V_69 ++ ) {
V_64 = * V_69 ;
V_63 = F_42 ( V_63 , V_64 ,
V_65 ) ;
}
F_50 ( V_68 ) ;
}
F_51 ( V_65 ) ;
return V_63 ;
}
void F_52 ( T_6 * V_63 )
{
T_6 * V_64 ;
for ( V_64 = V_63 ; V_64 != NULL ;
V_64 = F_45 ( V_64 ) ) {
F_15 ( V_64 -> V_6 ) ;
}
F_51 ( V_63 ) ;
}
const char * F_53 ( int V_60 )
{
if ( V_60 < 0 || V_60 >= V_46 )
return NULL ;
else
return V_47 [ V_60 ] . V_70 ;
}
T_1 F_34 ( int V_60 )
{
if ( V_60 < 0 || V_60 >= V_46
|| V_47 [ V_60 ] . V_72 == NULL )
return FALSE ;
return TRUE ;
}
T_1 F_35 ( int V_60 , int V_73 )
{
if ( V_60 < 0 || V_60 >= V_46
|| V_47 [ V_60 ] . V_74 == NULL )
return FALSE ;
if ( ( * V_47 [ V_60 ] . V_74 ) ( V_73 ) != 0 )
return FALSE ;
return TRUE ;
}
T_1 F_54 ( int V_60 )
{
if ( V_60 < 0 || V_60 >= V_46
|| V_47 [ V_60 ] . V_75 )
return FALSE ;
return TRUE ;
}
T_1 F_54 ( int V_60 V_76 )
{
return FALSE ;
}
T_1 F_55 ( int V_60 )
{
if ( V_60 < 0 || V_60 >= V_46
|| V_47 [ V_60 ] . V_77 == FALSE )
return FALSE ;
return TRUE ;
}
T_8 * F_56 ( const char * V_9 , int V_60 , int V_73 ,
int V_78 , T_1 V_79 , int * V_10 )
{
return F_57 ( V_9 , V_60 , V_73 , V_78 , V_79 , NULL , NULL , V_10 ) ;
}
T_8 * F_57 ( const char * V_9 , int V_60 , int V_73 ,
int V_78 , T_1 V_79 , T_9 * V_80 , T_10 * V_81 , int * V_10 )
{
T_8 * V_82 ;
T_11 V_27 ;
if ( ! F_58 ( V_60 , V_73 , V_79 , V_10 ) )
return NULL ;
V_82 = F_59 ( V_60 , V_73 , V_78 , V_79 , V_10 ) ;
if ( V_82 == NULL )
return NULL ;
V_82 -> V_80 = V_80 ;
if ( ( V_81 != NULL ) && ( V_81 -> V_83 > 0 ) ) {
V_82 -> V_83 = V_81 -> V_83 ;
V_82 -> V_84 = V_81 -> V_84 ;
} else {
T_12 V_85 ;
V_85 . V_86 = V_73 ;
V_85 . V_87 = 0 ;
V_85 . V_88 = F_60 ( V_73 ) ;
V_85 . V_89 = V_78 ;
V_85 . V_90 = NULL ;
V_85 . V_91 = NULL ;
V_85 . V_92 = NULL ;
V_85 . V_93 = 0 ;
V_85 . V_94 = 6 ;
V_85 . V_95 = NULL ;
V_85 . V_96 = 0 ;
V_85 . V_97 = NULL ;
V_85 . V_98 = NULL ;
V_85 . V_99 = - 1 ;
V_85 . V_100 = 0 ;
V_85 . V_101 = NULL ;
V_82 -> V_83 = 1 ;
V_82 -> V_84 = F_2 ( FALSE , FALSE , sizeof( T_12 ) ) ;
F_6 ( V_82 -> V_84 , V_85 ) ;
}
if ( strcmp ( V_9 , L_1 ) == 0 ) {
if ( V_79 ) {
* V_10 = V_102 ;
F_15 ( V_82 ) ;
return NULL ;
}
#ifdef F_16
if ( F_17 ( fileno ( stdout ) , V_26 ) == - 1 ) {
* V_10 = V_18 ;
F_15 ( V_82 ) ;
return NULL ;
}
#endif
V_82 -> V_27 = stdout ;
} else {
V_18 = V_25 ;
V_27 = F_61 ( V_82 , V_9 ) ;
if ( V_27 == NULL ) {
* V_10 = V_18 ;
F_15 ( V_82 ) ;
return NULL ;
}
V_82 -> V_27 = V_27 ;
}
if ( ! F_62 ( V_82 , V_60 , V_79 , V_10 ) ) {
if ( V_82 -> V_27 != stdout ) {
F_63 ( V_82 ) ;
F_64 ( V_9 ) ;
}
F_15 ( V_82 ) ;
return NULL ;
}
return V_82 ;
}
T_8 * F_65 ( int V_13 , int V_60 , int V_73 , int V_78 ,
T_1 V_79 , int * V_10 )
{
return F_66 ( V_13 , V_60 , V_73 , V_78 , V_79 , NULL , NULL , V_10 ) ;
}
T_8 * F_66 ( int V_13 , int V_60 , int V_73 , int V_78 ,
T_1 V_79 , T_9 * V_80 , T_10 * V_81 , int * V_10 )
{
T_8 * V_82 ;
T_11 V_27 ;
if ( ! F_58 ( V_60 , V_73 , V_79 , V_10 ) )
return NULL ;
V_82 = F_59 ( V_60 , V_73 , V_78 , V_79 , V_10 ) ;
if ( V_82 == NULL )
return NULL ;
#ifdef F_16
if ( V_13 == 1 ) {
if ( F_17 ( fileno ( stdout ) , V_26 ) == - 1 ) {
* V_10 = V_18 ;
F_15 ( V_82 ) ;
return NULL ;
}
}
#endif
V_82 -> V_80 = V_80 ;
if ( ( V_81 != NULL ) && ( V_81 -> V_83 > 0 ) ) {
V_82 -> V_83 = V_81 -> V_83 ;
V_82 -> V_84 = V_81 -> V_84 ;
} else {
T_12 V_85 ;
V_85 . V_86 = V_73 ;
V_85 . V_87 = 0 ;
V_85 . V_88 = F_60 ( V_73 ) ;
V_85 . V_89 = V_78 ;
V_85 . V_90 = NULL ;
V_85 . V_91 = NULL ;
V_85 . V_92 = NULL ;
V_85 . V_93 = 0 ;
V_85 . V_94 = 6 ;
V_85 . V_95 = NULL ;
V_85 . V_96 = 0 ;
V_85 . V_97 = NULL ;
V_85 . V_98 = NULL ;
V_85 . V_99 = - 1 ;
V_85 . V_100 = 0 ;
V_85 . V_101 = NULL ;
V_82 -> V_83 = 1 ;
V_82 -> V_84 = F_2 ( FALSE , FALSE , sizeof( T_12 ) ) ;
F_6 ( V_82 -> V_84 , V_85 ) ;
}
V_18 = V_25 ;
V_27 = F_67 ( V_82 , V_13 ) ;
if ( V_27 == NULL ) {
* V_10 = V_18 ;
F_15 ( V_82 ) ;
return NULL ;
}
V_82 -> V_27 = V_27 ;
if ( ! F_62 ( V_82 , V_60 , V_79 , V_10 ) ) {
F_63 ( V_82 ) ;
F_15 ( V_82 ) ;
return NULL ;
}
return V_82 ;
}
static T_1 F_58 ( int V_60 , int V_73 , T_1 V_79 , int * V_10 )
{
if ( ! F_34 ( V_60 ) ) {
* V_10 = V_103 ;
return FALSE ;
}
* V_10 = ( * V_47 [ V_60 ] . V_74 ) ( V_73 ) ;
if ( * V_10 != 0 )
return FALSE ;
if( V_79 && ! F_54 ( V_60 ) ) {
* V_10 = V_104 ;
return FALSE ;
}
* V_10 = ( * V_47 [ V_60 ] . V_74 ) ( V_73 ) ;
if ( * V_10 != 0 )
return FALSE ;
return TRUE ;
}
static T_8 * F_59 ( int V_60 , int V_73 , int V_78 ,
T_1 V_79 , int * V_10 )
{
T_8 * V_82 ;
V_82 = ( T_8 * ) F_13 ( sizeof ( T_8 ) ) ;
if ( V_82 == NULL ) {
* V_10 = V_18 ;
return NULL ;
}
V_82 -> V_52 = V_60 ;
V_82 -> V_78 = V_78 ;
V_82 -> V_73 = V_73 ;
V_82 -> V_79 = V_79 ;
return V_82 ;
}
static T_1 F_62 ( T_8 * V_82 , int V_60 , T_1 V_79 , int * V_10 )
{
int V_13 ;
T_1 V_105 ;
if( V_79 ) {
V_105 = TRUE ;
} else {
V_13 = fileno ( ( V_106 * ) V_82 -> V_27 ) ;
if ( F_68 ( V_13 , 1 , V_107 ) == - 1 )
V_105 = TRUE ;
else {
F_68 ( V_13 , 0 , V_38 ) ;
V_105 = FALSE ;
}
}
if ( V_47 [ V_60 ] . V_75 && V_105 ) {
* V_10 = V_108 ;
return FALSE ;
}
if ( ! ( * V_47 [ V_60 ] . V_72 ) ( V_82 , V_10 ) ) {
return FALSE ;
}
return TRUE ;
}
T_1 F_69 ( T_8 * V_82 , const struct V_109 * V_110 ,
const union V_111 * V_112 , const T_13 * V_113 , int * V_10 )
{
return ( V_82 -> V_114 ) ( V_82 , V_110 , V_112 , V_113 , V_10 ) ;
}
void F_70 ( T_8 * V_82 )
{
#ifdef F_71
if( V_82 -> V_79 ) {
F_72 ( ( V_115 ) V_82 -> V_27 ) ;
} else
#endif
{
fflush ( ( V_106 * ) V_82 -> V_27 ) ;
}
}
T_1 F_73 ( T_8 * V_82 , int * V_10 )
{
T_1 V_116 = TRUE ;
if ( V_82 -> V_32 != NULL ) {
if ( ! ( V_82 -> V_32 ) ( V_82 , V_10 ) )
V_116 = FALSE ;
}
V_18 = V_117 ;
if ( V_82 -> V_27 != stdout ) {
if ( F_63 ( V_82 ) == V_118 ) {
if ( V_116 ) {
if ( V_10 != NULL )
* V_10 = V_18 ;
}
V_116 = FALSE ;
}
} else {
F_70 ( V_82 ) ;
}
if ( V_82 -> V_35 != NULL )
F_15 ( V_82 -> V_35 ) ;
F_15 ( V_82 ) ;
return V_116 ;
}
T_14 F_74 ( T_8 * V_82 )
{
return V_82 -> V_119 ;
}
void F_75 ( T_8 * V_82 , T_14 V_119 )
{
V_82 -> V_119 = V_119 ;
}
T_1 F_76 ( T_8 * V_82 , struct V_120 * V_121 )
{
if ( ! V_82 || V_82 -> V_52 < 0 || V_82 -> V_52 >= V_46
|| V_47 [ V_82 -> V_52 ] . V_77 == FALSE )
return FALSE ;
V_82 -> V_121 = V_121 ;
return TRUE ;
}
static T_11 F_61 ( T_8 * V_82 , const char * V_9 )
{
if( V_82 -> V_79 ) {
return F_77 ( V_9 ) ;
} else {
return F_78 ( V_9 , L_6 ) ;
}
}
static T_11 F_61 ( T_8 * V_82 V_76 , const char * V_9 )
{
return F_78 ( V_9 , L_6 ) ;
}
static T_11 F_67 ( T_8 * V_82 , int V_13 )
{
if( V_82 -> V_79 ) {
return F_79 ( V_13 ) ;
} else {
return fdopen ( V_13 , L_6 ) ;
}
}
static T_11 F_67 ( T_8 * V_82 V_76 , int V_13 )
{
return fdopen ( V_13 , L_6 ) ;
}
T_1 F_80 ( T_8 * V_82 , const void * V_122 , T_15 V_123 ,
int * V_10 )
{
T_15 V_124 ;
#ifdef F_71
if ( V_82 -> V_79 ) {
V_124 = F_81 ( ( V_115 ) V_82 -> V_27 , V_122 , ( unsigned ) V_123 ) ;
if ( V_124 == 0 ) {
* V_10 = F_82 ( ( V_115 ) V_82 -> V_27 ) ;
return FALSE ;
}
} else
#endif
{
V_124 = fwrite ( V_122 , 1 , V_123 , ( V_106 * ) V_82 -> V_27 ) ;
if ( V_124 != V_123 ) {
if ( ferror ( ( V_106 * ) V_82 -> V_27 ) )
* V_10 = V_18 ;
else
* V_10 = V_125 ;
return FALSE ;
}
}
return TRUE ;
}
static int F_63 ( T_8 * V_82 )
{
#ifdef F_71
if( V_82 -> V_79 ) {
return F_83 ( ( V_115 ) V_82 -> V_27 ) ;
} else
#endif
{
return fclose ( ( V_106 * ) V_82 -> V_27 ) ;
}
}

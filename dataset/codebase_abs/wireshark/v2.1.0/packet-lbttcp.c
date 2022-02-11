T_1 * F_1 ( const T_2 * V_1 , T_3 V_2 , T_4 V_3 , T_4 V_4 )
{
T_1 * V_5 = NULL ;
T_5 * V_6 = NULL ;
T_6 * V_7 = NULL ;
V_6 = F_2 ( V_4 , V_1 , & V_8 , V_9 , V_2 , 0 , 0 ) ;
if ( V_6 != NULL )
{
V_7 = ( T_6 * ) F_3 ( V_6 , V_10 ) ;
if ( V_7 != NULL )
{
V_5 = ( T_1 * ) F_4 ( V_7 -> V_11 , V_3 ) ;
}
}
return ( V_5 ) ;
}
static T_1 * F_5 ( const T_2 * V_1 , T_3 V_2 , T_4 V_3 )
{
T_1 * V_12 = NULL ;
V_12 = F_6 ( F_7 () , T_1 ) ;
F_8 ( F_7 () , & ( V_12 -> V_1 ) , V_1 ) ;
V_12 -> V_2 = V_2 ;
V_12 -> V_3 = V_3 ;
V_12 -> V_13 = F_9 ( V_14 ) ;
V_12 -> V_15 = 1 ;
V_12 -> V_16 = F_10 ( F_7 () ) ;
return ( V_12 ) ;
}
T_1 * F_11 ( const T_2 * V_1 , T_3 V_2 , T_4 V_3 , T_4 V_4 )
{
T_1 * V_5 = NULL ;
T_5 * V_6 = NULL ;
T_6 * V_7 = NULL ;
V_6 = F_2 ( V_4 , V_1 , & V_8 , V_9 , V_2 , 0 , 0 ) ;
if ( V_6 == NULL )
{
V_6 = F_12 ( V_4 , V_1 , & V_8 , V_9 , V_2 , 0 , 0 ) ;
}
V_7 = ( T_6 * ) F_3 ( V_6 , V_10 ) ;
if ( V_7 == NULL )
{
V_7 = F_6 ( F_7 () , T_6 ) ;
V_7 -> V_17 = F_13 ( F_7 () ) ;
V_7 -> V_11 = F_13 ( F_7 () ) ;
F_14 ( V_6 , V_10 , ( void * ) V_7 ) ;
}
V_5 = ( T_1 * ) F_4 ( V_7 -> V_11 , V_3 ) ;
if ( V_5 != NULL )
{
return ( V_5 ) ;
}
V_5 = F_5 ( V_1 , V_2 , V_3 ) ;
F_15 ( V_7 -> V_11 , V_3 , ( void * ) V_5 ) ;
F_15 ( V_7 -> V_17 , V_4 , ( void * ) V_5 ) ;
return ( V_5 ) ;
}
static T_7 * F_16 ( T_1 * V_12 , const T_2 * V_18 , T_3 V_19 , T_4 V_4 )
{
T_7 * V_5 = NULL ;
T_5 * V_20 = NULL ;
if ( V_12 == NULL )
{
return ( NULL ) ;
}
V_20 = F_2 ( V_4 , & ( V_12 -> V_1 ) , V_18 , V_9 , V_12 -> V_2 , V_19 , 0 ) ;
if ( V_20 != NULL )
{
T_8 * V_11 = NULL ;
V_11 = ( T_8 * ) F_3 ( V_20 , V_10 ) ;
if ( V_11 != NULL )
{
V_5 = ( T_7 * ) F_4 ( V_11 , V_12 -> V_3 ) ;
}
}
return ( V_5 ) ;
}
static T_7 * F_17 ( T_1 * V_12 , const T_2 * V_18 , T_3 V_19 , T_4 V_4 )
{
T_7 * V_5 ;
T_5 * V_20 = NULL ;
T_8 * V_11 = NULL ;
if ( V_12 == NULL )
{
return ( NULL ) ;
}
V_5 = F_16 ( V_12 , V_18 , V_19 , V_4 ) ;
if ( V_5 != NULL )
{
return ( V_5 ) ;
}
V_5 = F_6 ( F_7 () , T_7 ) ;
F_8 ( F_7 () , & ( V_5 -> V_18 ) , V_18 ) ;
V_5 -> V_19 = V_19 ;
V_5 -> V_21 = V_12 -> V_15 ++ ;
V_20 = F_2 ( V_4 , & ( V_12 -> V_1 ) , V_18 , V_9 , V_12 -> V_2 , V_19 , 0 ) ;
if ( V_20 == NULL )
{
V_20 = F_12 ( V_4 , & ( V_12 -> V_1 ) , V_18 , V_9 , V_12 -> V_2 , V_19 , 0 ) ;
V_11 = F_13 ( F_7 () ) ;
F_14 ( V_20 , V_10 , ( void * ) V_11 ) ;
}
V_11 = ( T_8 * ) F_3 ( V_20 , V_10 ) ;
if ( V_11 == NULL )
{
V_11 = F_13 ( F_7 () ) ;
F_14 ( V_20 , V_10 , ( void * ) V_11 ) ;
}
F_15 ( V_11 , V_12 -> V_3 , ( void * ) V_5 ) ;
F_18 ( V_12 -> V_16 , ( void * ) V_5 ) ;
return ( V_5 ) ;
}
char * F_19 ( const T_2 * V_1 , T_3 V_2 , T_4 V_3 )
{
char * V_22 = NULL ;
if ( V_3 == 0 )
{
V_22 = F_20 ( F_7 () , L_1 V_23 , F_21 ( F_22 () , V_1 ) , V_2 ) ;
}
else
{
V_22 = F_20 ( F_7 () , L_1 V_23 L_2 , F_21 ( F_22 () , V_1 ) , V_2 , V_3 ) ;
}
return ( V_22 ) ;
}
T_9 F_23 ( const T_2 * V_1 , T_3 V_2 , T_4 V_4 , T_4 * V_3 )
{
T_5 * V_6 = NULL ;
T_6 * V_7 = NULL ;
T_1 * V_12 = NULL ;
V_6 = F_2 ( V_4 , V_1 , & V_8 , V_9 , V_2 , 0 , 0 ) ;
if ( V_6 == NULL )
{
return ( FALSE ) ;
}
V_7 = ( T_6 * ) F_3 ( V_6 , V_10 ) ;
if ( V_7 == NULL )
{
return ( FALSE ) ;
}
if ( V_7 -> V_17 == NULL )
{
return ( FALSE ) ;
}
V_12 = ( T_1 * ) F_24 ( V_7 -> V_17 , V_4 ) ;
if ( V_12 == NULL )
{
return ( FALSE ) ;
}
* V_3 = V_12 -> V_3 ;
return ( TRUE ) ;
}
void F_25 ( const T_2 * V_1 , T_3 V_2 , T_4 V_4 , T_4 V_3 )
{
T_5 * V_6 = NULL ;
T_6 * V_7 = NULL ;
T_1 * V_12 = NULL ;
V_6 = F_2 ( V_4 , V_1 , & V_8 , V_9 , V_2 , 0 , 0 ) ;
if ( V_6 == NULL )
{
V_6 = F_12 ( V_4 , V_1 , & V_8 , V_9 , V_2 , 0 , 0 ) ;
}
V_7 = ( T_6 * ) F_3 ( V_6 , V_10 ) ;
if ( V_7 == NULL )
{
V_7 = F_6 ( F_7 () , T_6 ) ;
V_7 -> V_17 = F_13 ( F_7 () ) ;
V_7 -> V_11 = F_13 ( F_7 () ) ;
F_14 ( V_6 , V_10 , ( void * ) V_7 ) ;
}
V_12 = ( T_1 * ) F_24 ( V_7 -> V_17 , V_4 ) ;
if ( V_12 != NULL )
{
if ( V_12 -> V_3 != V_3 )
{
V_12 = NULL ;
}
}
if ( V_12 == NULL )
{
V_12 = F_5 ( V_1 , V_2 , V_3 ) ;
F_15 ( V_7 -> V_11 , V_3 , ( void * ) V_12 ) ;
F_15 ( V_7 -> V_17 , V_4 , ( void * ) V_12 ) ;
}
}
static T_9 F_26 ( void * V_24 , char * * V_25 )
{
T_10 * V_26 = ( T_10 * ) V_24 ;
if ( V_26 -> V_27 == NULL )
{
* V_25 = F_27 ( L_3 ) ;
return FALSE ;
}
else
{
F_28 ( V_26 -> V_27 ) ;
if ( V_26 -> V_27 [ 0 ] == 0 )
{
* V_25 = F_27 ( L_3 ) ;
return FALSE ;
}
}
return TRUE ;
}
static void * F_29 ( void * V_28 , const void * V_29 , T_11 T_12 V_30 )
{
const T_10 * V_31 = ( const T_10 * ) V_29 ;
T_10 * V_32 = ( T_10 * ) V_28 ;
V_32 -> V_27 = F_27 ( V_31 -> V_27 ) ;
V_32 -> V_33 = V_31 -> V_33 ;
V_32 -> V_34 = V_31 -> V_34 ;
V_32 -> V_35 = V_31 -> V_35 ;
V_32 -> V_36 = V_31 -> V_36 ;
V_32 -> V_37 = V_31 -> V_37 ;
V_32 -> V_38 = V_31 -> V_38 ;
return ( V_32 ) ;
}
static void F_30 ( void * V_24 )
{
T_10 * V_26 = ( T_10 * ) V_24 ;
if ( V_26 -> V_27 != NULL )
{
F_31 ( V_26 -> V_27 ) ;
V_26 -> V_27 = NULL ;
}
}
static const T_10 * F_32 ( T_13 * V_39 )
{
T_14 V_40 ;
const T_10 * V_26 = NULL ;
if ( ! V_41 )
{
return ( NULL ) ;
}
for ( V_40 = 0 ; V_40 < V_42 ; ++ V_40 )
{
V_26 = & ( V_43 [ V_40 ] ) ;
if ( ( ( V_39 -> V_44 >= V_26 -> V_33 ) && ( V_39 -> V_44 <= V_26 -> V_34 ) )
|| ( ( V_39 -> V_45 >= V_26 -> V_33 ) && ( V_39 -> V_45 <= V_26 -> V_34 ) )
|| ( ( V_39 -> V_44 >= V_26 -> V_35 ) && ( V_39 -> V_44 <= V_26 -> V_36 ) )
|| ( ( V_39 -> V_45 >= V_26 -> V_35 ) && ( V_39 -> V_45 <= V_26 -> V_36 ) )
|| ( ( V_39 -> V_44 >= V_26 -> V_37 ) && ( V_39 -> V_44 <= V_26 -> V_38 ) )
|| ( ( V_39 -> V_45 >= V_26 -> V_37 ) && ( V_39 -> V_45 <= V_26 -> V_38 ) ) )
{
return ( V_26 ) ;
}
}
return ( NULL ) ;
}
static char * F_33 ( T_13 * V_39 )
{
const T_10 * V_26 = NULL ;
if ( ! V_41 )
{
return ( NULL ) ;
}
V_26 = F_32 ( V_39 ) ;
if ( V_26 != NULL )
{
return V_26 -> V_27 ;
}
return ( NULL ) ;
}
static T_9 F_34 ( T_13 * V_39 , const T_10 * V_26 )
{
T_9 V_46 = FALSE ;
if ( V_26 == NULL )
{
if ( ( V_39 -> V_44 >= V_47 ) && ( V_39 -> V_44 <= V_48 ) )
{
V_46 = TRUE ;
}
}
else
{
if ( ( V_39 -> V_44 >= V_26 -> V_33 ) && ( V_39 -> V_44 <= V_26 -> V_34 ) )
{
V_46 = TRUE ;
}
}
return ( V_46 ) ;
}
static T_9 F_35 ( T_13 * V_39 , const T_10 * V_26 )
{
T_9 V_49 = FALSE ;
if ( V_26 == NULL )
{
if ( ( V_39 -> V_45 >= V_47 ) && ( V_39 -> V_45 <= V_48 ) )
{
V_49 = TRUE ;
}
}
else
{
if ( ( V_39 -> V_45 >= V_26 -> V_33 ) && ( V_39 -> V_45 <= V_26 -> V_34 ) )
{
V_49 = TRUE ;
}
}
return ( V_49 ) ;
}
static T_14 F_36 ( T_13 * V_39 V_30 , T_15 * V_50 ,
int V_51 , void * T_16 V_30 )
{
return F_37 ( V_50 , V_51 ) ;
}
static int F_38 ( T_15 * V_50 , T_13 * V_39 , T_17 * V_52 , void * T_18 V_30 )
{
T_17 * V_53 = NULL ;
T_19 * V_54 = NULL ;
char * V_55 = NULL ;
int V_56 ;
const T_10 * V_26 = NULL ;
T_20 V_13 = V_57 ;
T_4 V_58 = 0 ;
T_9 V_59 = FALSE ;
T_9 V_60 = FALSE ;
if ( V_41 )
{
V_26 = F_32 ( V_39 ) ;
V_55 = F_33 ( V_39 ) ;
}
if ( V_55 != NULL )
{
V_54 = F_39 ( V_52 , V_10 , V_50 , 0 , - 1 , L_4 , V_55 ) ;
}
else
{
V_54 = F_39 ( V_52 , V_10 , V_50 , 0 , - 1 , L_5 ) ;
}
V_53 = F_40 ( V_54 , V_61 ) ;
if ( V_55 != NULL )
{
T_19 * V_62 = NULL ;
V_62 = F_41 ( V_53 , V_63 , V_50 , 0 , 0 , V_55 ) ;
F_42 ( V_62 ) ;
}
if ( F_34 ( V_39 , V_26 ) )
{
V_59 = TRUE ;
V_60 = TRUE ;
}
else if ( F_35 ( V_39 , V_26 ) )
{
V_59 = FALSE ;
V_60 = TRUE ;
}
if ( V_60 )
{
T_2 V_1 ;
T_2 V_64 ;
T_3 V_44 ;
T_3 V_65 ;
T_4 V_66 = 0 ;
T_1 * V_12 = NULL ;
T_7 * V_67 = NULL ;
if ( V_59 )
{
F_43 ( & V_1 , & ( V_39 -> V_31 ) ) ;
V_44 = V_39 -> V_44 ;
F_43 ( & V_64 , & ( V_39 -> V_68 ) ) ;
V_65 = V_39 -> V_45 ;
}
else
{
F_43 ( & V_1 , & ( V_39 -> V_68 ) ) ;
V_44 = V_39 -> V_45 ;
F_43 ( & V_64 , & ( V_39 -> V_31 ) ) ;
V_65 = V_39 -> V_44 ;
}
V_12 = F_1 ( & V_1 , V_44 , V_66 , V_39 -> V_69 ) ;
if ( V_12 == NULL )
{
if ( F_23 ( & V_1 , V_44 , V_39 -> V_69 , & V_66 ) )
{
V_12 = F_1 ( & V_1 , V_44 , V_66 , V_39 -> V_69 ) ;
}
}
if ( V_12 != NULL )
{
V_13 = V_12 -> V_13 ;
V_67 = F_16 ( V_12 , & V_64 , V_65 , V_39 -> V_69 ) ;
if ( V_67 == NULL )
{
V_67 = F_17 ( V_12 , & V_64 , V_65 , V_39 -> V_69 ) ;
}
if ( V_67 != NULL )
{
V_58 = V_67 -> V_21 ;
}
}
else
{
if ( F_44 ( V_39 ) )
{
V_12 = F_11 ( & V_1 , V_44 , 0 , V_39 -> V_69 ) ;
if ( V_12 != NULL )
{
V_13 = V_12 -> V_13 ;
V_67 = F_17 ( V_12 , & V_64 , V_65 , V_39 -> V_69 ) ;
if ( V_67 != NULL )
{
V_58 = V_67 -> V_21 ;
}
}
}
else
{
if ( V_59 )
{
V_13 = F_45 () ;
}
else
{
V_13 = F_46 () ;
}
}
}
}
else
{
V_13 = F_47 () ;
}
if ( F_48 ( V_13 ) )
{
T_19 * V_70 = NULL ;
T_17 * V_71 = NULL ;
V_70 = F_49 ( V_53 , V_72 , V_50 , 0 , 0 , V_73 ) ;
F_42 ( V_70 ) ;
V_71 = F_40 ( V_70 , V_74 ) ;
V_70 = F_50 ( V_71 , V_75 , V_50 , 0 , 0 , V_13 ) ;
F_42 ( V_70 ) ;
V_70 = F_51 ( V_71 , V_76 , V_50 , 0 , 0 , V_58 ) ;
F_42 ( V_70 ) ;
}
V_56 = F_52 ( V_50 , 0 , V_39 , V_52 , V_55 , V_13 ) ;
return ( V_56 ) ;
}
static int F_53 ( T_15 * V_50 , T_13 * V_39 , T_17 * V_52 , void * T_16 V_30 )
{
char * V_55 = NULL ;
F_54 ( V_39 -> V_77 , V_78 , L_6 ) ;
F_55 ( V_39 -> V_77 , V_79 ) ;
if ( V_41 )
{
V_55 = F_33 ( V_39 ) ;
}
if ( V_55 != NULL )
{
F_56 ( V_39 -> V_77 , V_79 , L_7 , V_55 ) ;
}
F_57 ( V_39 -> V_77 , V_79 ) ;
F_58 ( V_50 , V_39 , V_52 , TRUE , F_59 () ,
F_36 , F_38 , NULL ) ;
return F_60 ( V_50 ) ;
}
static int F_61 ( T_15 * V_50 , T_13 * V_39 , T_17 * V_52 , void * T_16 )
{
if ( ! F_62 ( V_50 , 0 ) )
return 0 ;
return F_53 ( V_50 , V_39 , V_52 , T_16 ) ;
}
static T_9 F_63 ( T_15 * V_50 , T_13 * V_39 , T_17 * V_52 , void * T_16 )
{
if ( ( V_39 -> V_68 . type != V_80 ) || ( V_39 -> V_68 . V_81 != 4 ) )
{
return ( FALSE ) ;
}
if ( V_41 )
{
if ( F_33 ( V_39 ) != NULL )
{
F_53 ( V_50 , V_39 , V_52 , T_16 ) ;
return ( TRUE ) ;
}
else
{
return ( FALSE ) ;
}
}
if ( ! ( ( ( V_39 -> V_44 >= V_47 ) && ( V_39 -> V_44 <= V_48 ) )
|| ( ( V_39 -> V_45 >= V_47 ) && ( V_39 -> V_45 <= V_48 ) )
|| ( ( V_39 -> V_44 >= V_82 ) && ( V_39 -> V_44 <= V_83 ) )
|| ( ( V_39 -> V_45 >= V_82 ) && ( V_39 -> V_45 <= V_83 ) )
|| ( ( V_39 -> V_44 >= V_84 ) && ( V_39 -> V_44 <= V_85 ) )
|| ( ( V_39 -> V_45 >= V_84 ) && ( V_39 -> V_45 <= V_85 ) ) ) )
{
return ( FALSE ) ;
}
if ( ! F_62 ( V_50 , 0 ) )
return FALSE ;
F_53 ( V_50 , V_39 , V_52 , T_16 ) ;
return ( TRUE ) ;
}
void F_64 ( void )
{
static T_21 V_86 [] =
{
{ & V_63 ,
{ L_8 , L_9 , V_87 , V_88 , NULL , 0x0 , NULL , V_89 } } ,
{ & V_72 ,
{ L_10 , L_11 , V_90 , V_88 , NULL , 0x0 , NULL , V_89 } } ,
{ & V_75 ,
{ L_12 , L_13 , V_91 , V_92 , NULL , 0x0 , NULL , V_89 } } ,
{ & V_76 ,
{ L_14 , L_15 , V_93 , V_94 , NULL , 0x0 , NULL , V_89 } } ,
} ;
static T_22 * V_95 [] =
{
& V_61 ,
& V_74
} ;
T_23 * V_96 ;
T_24 * V_97 ;
V_10 = F_65 ( L_16 , L_6 , L_17 ) ;
F_66 ( V_10 , V_86 , F_67 ( V_86 ) ) ;
F_68 ( V_95 , F_67 ( V_95 ) ) ;
V_96 = F_69 ( L_18 , V_10 , V_98 ) ;
F_70 ( V_96 ,
L_19 ,
L_20 F_71 ( V_99 ) L_21 ,
L_22 ,
10 ,
& V_100 ) ;
F_70 ( V_96 ,
L_23 ,
L_24 F_71 ( V_101 ) L_21 ,
L_25 ,
10 ,
& V_102 ) ;
F_70 ( V_96 ,
L_26 ,
L_27 F_71 ( V_103 ) L_21 ,
L_28 ,
10 ,
& V_104 ) ;
F_70 ( V_96 ,
L_29 ,
L_30 F_71 ( V_105 ) L_21 ,
L_31 ,
10 ,
& V_106 ) ;
F_70 ( V_96 ,
L_32 ,
L_33 F_71 ( V_107 ) L_21 ,
L_34 ,
10 ,
& V_108 ) ;
F_70 ( V_96 ,
L_35 ,
L_36 F_71 ( V_109 ) L_21 ,
L_37 ,
10 ,
& V_110 ) ;
F_72 ( V_96 ,
L_38 ,
L_39 ,
L_40 ,
& V_111 ) ;
V_97 = F_73 ( L_41 ,
sizeof( T_10 ) ,
L_42 ,
TRUE ,
( void * * ) & V_43 ,
& V_42 ,
V_112 ,
NULL ,
F_29 ,
F_26 ,
F_30 ,
NULL ,
V_113 ) ;
F_74 ( V_96 ,
L_43 ,
L_44 ,
L_45 ,
V_97 ) ;
}
void V_98 ( void )
{
static T_9 V_114 = FALSE ;
if ( ! V_114 )
{
V_115 = F_75 ( F_61 , V_10 ) ;
F_76 ( L_46 , V_115 ) ;
F_77 ( L_47 , F_63 , L_48 , L_49 , V_10 , V_116 ) ;
}
if ( V_100 <= V_102 )
{
V_47 = V_100 ;
V_48 = V_102 ;
}
if ( V_104 <= V_106 )
{
V_82 = V_104 ;
V_83 = V_106 ;
}
if ( V_108 <= V_110 )
{
V_84 = V_108 ;
V_85 = V_110 ;
}
V_41 = V_111 ;
V_114 = TRUE ;
}

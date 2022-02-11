static void F_1 ( void )
{
V_1 . V_2 = F_2 () ;
V_1 . V_2 -> type = V_3 ;
V_1 . V_2 -> V_4 = TRUE ;
V_1 . V_2 -> V_5 = TRUE ;
}
static void F_3 ( T_1 * T_2 V_6 , T_3 T_4 V_6 )
{
if ( F_4 ( F_5 ( V_1 . V_7 ) ) )
{
V_1 . V_8 = V_9 ;
}
}
static void F_6 ( T_1 * T_2 V_6 , T_3 T_4 V_6 )
{
if ( F_4 ( F_5 ( V_1 . V_10 ) ) )
{
V_1 . V_8 = V_11 ;
}
}
static void F_7 ( void * T_5 V_6 )
{
if ( V_1 . V_2 != NULL )
{
F_8 ( V_1 . V_2 ) ;
}
}
static int F_9 ( T_6 * V_12 , const T_7 * V_13 )
{
T_8 V_14 ;
T_8 V_15 ;
T_9 * V_16 ;
T_10 * V_17 ;
T_10 * V_18 ;
T_11 V_19 = FALSE ;
int V_20 ;
if ( V_13 -> V_21 . type != V_13 -> V_22 . type )
{
return ( 1 ) ;
}
if ( V_13 -> V_21 . type == V_23 )
{
V_20 = memcmp ( ( void * ) V_13 -> V_21 . V_13 . V_24 . V_24 ,
( void * ) V_13 -> V_22 . V_13 . V_24 . V_24 ,
V_25 ) ;
if ( V_20 <= 0 )
{
V_19 = FALSE ;
}
else
{
V_19 = TRUE ;
}
}
else
{
if ( V_13 -> V_21 . V_13 . V_26 . V_27 < V_13 -> V_22 . V_13 . V_26 . V_27 )
{
V_19 = FALSE ;
}
else if ( V_13 -> V_21 . V_13 . V_26 . V_27 > V_13 -> V_22 . V_13 . V_26 . V_27 )
{
V_19 = TRUE ;
}
else
{
int V_28 ;
V_28 = F_10 ( & ( V_13 -> V_21 . V_13 . V_26 . V_29 ) , & ( V_13 -> V_22 . V_13 . V_26 . V_29 ) ) ;
if ( V_28 < 0 )
{
V_19 = FALSE ;
}
else if ( V_28 > 0 )
{
V_19 = TRUE ;
}
else
{
if ( V_13 -> V_21 . V_13 . V_26 . V_30 <= V_13 -> V_22 . V_13 . V_26 . V_30 )
{
V_19 = FALSE ;
}
else
{
V_19 = TRUE ;
}
}
}
}
if ( V_19 == FALSE )
{
V_14 = V_13 -> V_21 ;
V_15 = V_13 -> V_22 ;
}
else
{
V_15 = V_13 -> V_21 ;
V_14 = V_13 -> V_22 ;
}
V_16 = ( T_9 * ) F_11 ( sizeof( T_9 ) ) ;
F_12 ( & ( V_16 -> V_31 ) , & ( V_12 -> V_32 ) ) ;
F_12 ( & ( V_16 -> V_33 ) , & ( V_12 -> V_34 ) ) ;
V_16 -> V_35 = V_12 -> V_36 ;
V_16 -> V_37 = V_12 -> V_38 ;
V_16 -> V_39 = V_12 -> V_40 ;
V_16 -> V_41 = F_13 ( F_14 ( V_12 -> V_42 ) ) ;
if ( V_13 -> V_43 == NULL )
{
V_16 -> V_44 = F_15 ( L_1 V_45 L_2 , V_13 -> V_46 ) ;
}
else
{
V_16 -> V_44 = F_15 ( L_3 V_45 L_2 , V_13 -> V_43 , V_13 -> V_46 ) ;
}
if ( V_14 . type == V_23 )
{
V_17 = F_16 ( V_12 -> V_47 , V_14 . V_13 . V_24 . V_24 , sizeof( V_14 . V_13 . V_24 . V_24 ) ) ;
V_18 = F_16 ( V_12 -> V_47 , V_15 . V_13 . V_24 . V_24 , sizeof( V_15 . V_13 . V_24 . V_24 ) ) ;
V_16 -> V_48 = F_15 ( L_4 V_49 L_5 ,
V_17 ,
V_18 ,
V_13 -> V_50 ) ;
}
else
{
V_16 -> V_48 = F_15 ( L_6 V_45 L_7 V_51 L_8 V_45 L_7 V_51 L_9 V_49 L_5 ,
V_14 . V_13 . V_26 . V_27 ,
F_17 ( V_12 -> V_47 , & ( V_14 . V_13 . V_26 . V_29 ) ) ,
V_14 . V_13 . V_26 . V_30 ,
V_15 . V_13 . V_26 . V_27 ,
F_17 ( V_12 -> V_47 , & ( V_15 . V_13 . V_26 . V_29 ) ) ,
V_15 . V_13 . V_26 . V_30 ,
V_13 -> V_50 ) ;
}
V_16 -> V_52 = ( V_53 ) F_18 ( V_13 -> V_50 ) ;
V_16 -> V_54 = TRUE ;
V_16 -> V_55 = 1 ;
F_19 ( V_1 . V_2 -> V_56 , V_16 ) ;
return ( 1 ) ;
}
static T_11 F_20 ( void * T_5 V_6 , T_6 * V_12 , T_12 * T_13 V_6 , const void * V_13 )
{
const T_7 * V_57 = ( const T_7 * ) V_13 ;
if ( ( V_1 . V_8 == V_9 ) || ( V_12 -> V_58 -> V_59 . V_60 == 1 ) )
{
F_9 ( V_12 , V_57 ) ;
return ( TRUE ) ;
}
return ( FALSE ) ;
}
static void F_21 ( void * T_5 V_6 )
{
return;
}
static void F_22 ( void )
{
F_23 ( & ( V_1 . V_61 ) ) ;
V_1 . V_62 = FALSE ;
}
static void F_24 ( T_14 * T_15 V_6 , T_3 T_4 )
{
T_16 * V_63 = NULL ;
T_10 V_64 [ V_65 ] ;
if ( V_1 . V_62 == TRUE )
{
F_22 () ;
}
if ( V_1 . V_62 == FALSE )
{
T_17 * V_66 ;
V_66 = F_25 ( L_10 ,
& ( V_1 . V_61 ) ,
NULL ,
V_67 ,
F_7 ,
F_20 ,
F_21 ) ;
if ( V_66 != NULL )
{
fprintf ( V_68 , L_11 , V_66 -> V_69 ) ;
F_26 ( V_66 , TRUE ) ;
}
V_1 . V_62 = TRUE ;
}
F_27 ( & V_70 ) ;
V_63 = F_28 ( V_1 . V_2 -> V_56 , 0 ) ;
while ( V_63 != NULL )
{
T_9 * V_71 = ( T_9 * ) V_63 -> V_72 ;
F_29 ( V_70 . V_73 , F_30 ( V_70 . V_74 , V_71 -> V_35 ) , V_64 ) ;
V_71 -> V_64 = F_13 ( V_64 ) ;
V_63 = F_31 ( V_63 ) ;
}
if ( V_1 . V_75 -> V_76 . V_77 != NULL )
{
F_32 ( V_1 . V_75 ) ;
}
else
{
V_1 . V_75 -> V_76 . V_78 = ( T_1 * ) T_4 ;
F_33 ( V_1 . V_75 ) ;
}
}
static void F_34 ( T_1 * T_2 V_6 , T_3 T_4 V_6 )
{
F_22 () ;
F_7 ( NULL ) ;
F_35 ( V_1 . V_2 != NULL ) ;
F_35 ( V_1 . V_75 != NULL ) ;
F_36 ( V_1 . V_2 ) ;
V_1 . V_2 = NULL ;
F_37 ( V_1 . V_75 ) ;
V_1 . V_75 = NULL ;
V_1 . V_79 = NULL ;
}
static void F_38 ( void )
{
T_1 * V_80 = NULL ;
T_1 * V_81 = NULL ;
T_1 * V_82 = NULL ;
T_1 * V_83 = NULL ;
T_1 * V_84 = NULL ;
T_1 * V_85 = NULL ;
T_1 * V_86 = NULL ;
V_80 = F_39 ( L_12 ) ;
F_40 ( F_41 ( V_80 ) , TRUE ) ;
F_42 ( F_41 ( V_80 ) , 250 , 150 ) ;
V_81 = F_43 ( V_87 , 0 , FALSE ) ;
F_44 ( F_45 ( V_80 ) , V_81 ) ;
F_46 ( F_45 ( V_81 ) , 7 ) ;
F_47 ( V_80 ) ;
V_85 = F_48 ( L_13 ) ;
F_49 ( F_50 ( V_81 ) , V_85 , FALSE , FALSE , 5 ) ;
V_86 = F_51 () ;
F_46 ( F_45 ( V_86 ) , 5 ) ;
F_44 ( F_45 ( V_85 ) , V_86 ) ;
V_1 . V_7 = F_52 ( NULL , L_14 ) ;
F_53 ( V_1 . V_7 , ( L_15 ) ) ;
F_54 ( V_1 . V_7 , L_16 , F_55 ( F_3 ) , NULL ) ;
F_56 ( F_57 ( V_86 ) , V_1 . V_7 , 0 , 0 , 1 , 1 ,
( V_88 ) ( V_89 ) , ( V_88 ) ( 0 ) , 0 , 0 ) ;
if ( V_1 . V_8 == V_9 )
{
F_58 ( F_5 ( V_1 . V_7 ) , TRUE ) ;
}
F_47 ( V_1 . V_7 ) ;
V_1 . V_10 =
F_52 ( F_59 ( V_1 . V_7 ) , L_17 ) ;
F_53 ( V_1 . V_10 , ( L_18 ) ) ;
F_54 ( V_1 . V_10 , L_16 , F_55 ( F_6 ) , NULL ) ;
F_56 ( F_57 ( V_86 ) , V_1 . V_10 , 0 , 1 , 1 , 1 ,
( V_88 ) ( V_89 ) , ( V_88 ) ( 0 ) , 0 , 0 ) ;
if ( V_1 . V_8 == V_11 )
{
F_58 ( F_5 ( V_1 . V_10 ) , TRUE ) ;
}
F_47 ( V_1 . V_10 ) ;
F_47 ( V_86 ) ;
F_47 ( V_85 ) ;
V_82 = F_60 ( V_90 ) ;
F_49 ( F_50 ( V_81 ) , V_82 , FALSE , FALSE , 5 ) ;
F_61 ( F_62 ( V_82 ) , V_91 ) ;
F_63 ( F_50 ( V_82 ) , 30 ) ;
V_84 = F_64 ( V_92 ) ;
F_44 ( F_45 ( V_82 ) , V_84 ) ;
F_53 ( V_84 , L_19 ) ;
F_54 ( V_84 , L_20 , F_55 ( F_24 ) , V_80 ) ;
F_47 ( V_84 ) ;
V_83 = F_64 ( V_93 ) ;
F_44 ( F_45 ( V_82 ) , V_83 ) ;
#if F_65 ( 2 , 18 , 0 )
F_66 ( V_83 , TRUE ) ;
#else
F_67 ( V_83 , V_94 ) ;
#endif
F_53 ( V_83 , L_21 ) ;
F_68 ( V_80 , V_83 , V_95 ) ;
F_54 ( V_80 , L_22 , F_55 ( V_96 ) , NULL ) ;
F_54 ( V_80 , L_23 , F_55 ( F_34 ) , NULL ) ;
F_69 ( V_80 ) ;
F_70 ( V_80 ) ;
V_1 . V_79 = V_80 ;
}
static void F_71 ( const char * T_18 V_6 , void * T_4 V_6 )
{
if ( V_1 . V_79 != NULL )
{
F_35 ( V_1 . V_2 != NULL ) ;
F_35 ( V_1 . V_75 != NULL ) ;
F_72 ( V_1 . V_79 ) ;
}
else
{
F_35 ( V_1 . V_2 == NULL ) ;
F_35 ( V_1 . V_75 == NULL ) ;
F_1 () ;
V_1 . V_75 = F_73 ( V_1 . V_2 ) ;
F_38 () ;
}
}
void F_74 ( T_3 T_19 V_6 )
{
F_71 ( L_24 , NULL ) ;
}

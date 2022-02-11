static void
F_1 ( void )
{
if ( V_1 == 0 )
V_1 = F_2 ( V_2 , V_3 ) ;
}
static void F_3 ( T_1 V_4 , T_2 * V_5 )
{
T_3 V_6 ;
T_4 * V_7 = 0 ;
V_7 = ( T_4 * ) F_4 ( sizeof( T_4 ) ) ;
* V_7 = ( T_4 ) V_4 ;
F_1 () ;
if ( F_5 ( V_1 ) != 0 )
{
if ( F_6 ( V_1 , V_7 , NULL , ( V_8 * ) & V_6 ) )
{
if ( V_6 != NULL )
V_6 ( V_5 ) ;
}
}
}
extern T_5 * F_7 ( void )
{
return V_9 ;
}
extern T_6 * F_8 ( int V_10 , const T_7 * V_11 ,
T_8 V_12 )
{
T_9 * V_13 = NULL ;
T_7 * V_14 = NULL ;
F_9 ( V_11 != NULL && strlen ( V_11 ) > 0 ) ;
F_9 ( F_10 ( V_10 ) != NULL ) ;
V_14 = F_11 ( F_12 ( V_10 ) , L_1 , NULL ) ;
F_9 ( F_13 ( V_15 , V_14 ) == NULL ) ;
V_13 = ( T_9 * ) F_4 ( sizeof( T_9 ) ) ;
V_13 -> type = V_16 ;
V_13 -> V_17 = V_10 ;
V_13 -> V_12 = V_12 ;
V_13 -> V_18 = 0 ;
V_13 -> V_14 = V_14 ;
V_13 -> V_19 = F_14 ( V_11 ) ;
V_13 -> V_20 = F_14 ( V_11 ) ;
V_13 -> V_21 = 0 ;
V_13 -> V_22 = 0 ;
V_9 = F_15 ( V_9 , V_13 ) ;
V_15 = F_15 ( V_15 , V_14 ) ;
return V_13 ;
}
extern T_6 * F_16 ( T_6 * V_23 , const T_7 * V_24 )
{
F_9 ( V_23 != NULL && V_23 -> V_25 == NULL ) ;
F_9 ( V_24 != 0 ) ;
V_23 -> V_18 = F_14 ( V_24 ) ;
return V_23 ;
}
extern T_6 * F_17 ( T_6 * V_25 , const T_7 * V_11 )
{
T_9 * V_13 = NULL ;
F_9 ( V_11 != NULL && strlen ( V_11 ) > 0 ) ;
F_9 ( V_25 != NULL && V_25 -> type == V_16 ) ;
V_25 -> V_21 ++ ;
V_13 = ( T_9 * ) F_4 ( sizeof( T_9 ) ) ;
V_13 -> type = V_16 ;
V_13 -> V_25 = V_25 ;
V_13 -> V_17 = V_25 -> V_17 ;
V_13 -> V_12 = V_25 -> V_12 ;
V_13 -> V_14 = F_18 ( L_2 , V_25 -> V_14 , V_25 -> V_21 ) ;
V_13 -> V_19 = F_14 ( V_11 ) ;
V_13 -> V_20 = F_14 ( V_11 ) ;
V_25 -> V_26 = F_15 ( V_25 -> V_26 , V_13 ) ;
return V_13 ;
}
static void F_19 (
T_10 type , T_6 * V_25 , const T_7 * V_19 ,
const T_7 * V_20 , T_11 V_27 , V_8 V_28 )
{
T_9 * V_13 = NULL ;
F_9 ( V_25 != NULL && V_25 -> type == V_16 ) ;
F_9 ( V_19 != NULL && strlen ( V_19 ) > 0 ) ;
V_25 -> V_22 ++ ;
V_13 = ( T_9 * ) F_4 ( sizeof( T_9 ) ) ;
V_13 -> type = type ;
V_13 -> V_14 = F_18 ( L_3 , V_25 -> V_14 , V_25 -> V_22 ) ;
V_13 -> V_19 = F_14 ( V_19 ) ;
if ( V_20 != NULL && strlen ( V_20 ) > 0 )
V_13 -> V_20 = F_14 ( V_20 ) ;
V_13 -> V_27 = V_27 ;
V_13 -> V_28 = V_28 ;
V_25 -> V_26 = F_15 ( V_25 -> V_26 , V_13 ) ;
}
extern void F_20 ( T_6 * V_25 , const T_7 * V_19 ,
const T_7 * V_20 , T_11 V_27 , V_8 V_28 )
{
F_9 ( V_27 != NULL ) ;
F_19 ( V_29 , V_25 , V_19 , V_20 , V_27 , V_28 ) ;
}
extern void F_21 ( T_6 * V_25 , const T_7 * V_19 ,
const T_7 * V_20 , const T_7 * V_30 )
{
F_9 ( V_30 != NULL && strlen ( V_30 ) > 0 ) ;
F_19 ( V_31 , V_25 , V_19 , V_20 , NULL , ( V_8 ) F_14 ( V_30 ) ) ;
}
extern void F_22 ( T_6 * V_25 )
{
F_19 ( V_32 , V_25 , F_14 ( L_4 ) , NULL , NULL , NULL ) ;
}
extern T_5 * F_23 ( void )
{
return V_33 ;
}
T_12 * F_24 ( const T_7 * V_34 )
{
T_12 * V_13 = NULL ;
F_9 ( V_34 != NULL && strlen ( V_34 ) > 0 ) ;
V_13 = F_25 ( T_12 , 1 ) ;
V_13 -> type = V_35 ;
V_13 -> V_14 = F_14 ( V_34 ) ;
V_13 -> V_20 = F_14 ( V_34 ) ;
V_13 -> V_21 = 0 ;
V_13 -> V_22 = 0 ;
V_33 = F_15 ( V_33 , V_13 ) ;
return V_13 ;
}
static T_4
F_26 ( T_13 V_36 , T_13 V_37 )
{
if ( ! V_36 || ! V_37 )
return - 1 ;
T_12 * V_38 = ( T_12 * ) V_36 ;
T_12 * V_39 = ( T_12 * ) V_37 ;
return strcmp ( V_38 -> V_14 , V_39 -> V_14 ) ;
}
void F_27 ( const T_7 * V_40 )
{
T_5 * V_41 = 0 ;
if ( ! V_40 )
return;
V_41 = V_33 ;
while ( V_41 && V_41 -> V_42 )
{
T_12 * V_13 = ( T_12 * ) V_41 -> V_42 ;
if ( F_28 ( V_13 -> V_14 , V_40 ) == 0 )
{
F_29 ( V_13 ) ;
break;
}
V_41 = F_30 ( V_41 ) ;
}
}
void F_29 ( T_12 * V_43 )
{
if ( ! V_43 )
return;
T_5 * V_13 = F_31 ( V_33 , V_43 , ( V_44 ) F_26 ) ;
if ( V_13 && V_13 -> V_42 )
{
T_12 * V_45 = ( T_12 * ) V_13 -> V_42 ;
V_33 = F_32 ( V_33 , V_45 ) ;
if ( ! F_31 ( V_33 , V_43 , ( V_44 ) F_26 ) )
{
T_2 * V_5 = F_2 ( V_46 , V_47 ) ;
F_33 ( V_5 , F_14 ( L_5 ) , F_14 ( V_45 -> V_14 ) ) ;
F_3 ( V_48 , V_5 ) ;
F_34 ( V_45 -> V_14 ) ;
F_34 ( V_45 -> V_20 ) ;
F_34 ( V_45 -> V_49 ) ;
F_34 ( V_45 -> V_50 ) ;
F_34 ( V_45 ) ;
}
}
}
static T_4
F_35 ( T_13 V_36 , T_13 V_37 )
{
T_12 * V_51 = ( T_12 * ) V_36 ;
T_12 * V_52 = ( T_12 * ) V_37 ;
if ( V_51 == 0 || V_52 == 0 )
return 0 ;
if ( V_51 -> V_53 == V_54 && V_52 -> V_53 != V_54 )
return 1 ;
else if ( V_51 -> V_53 != V_54 && V_52 -> V_53 == V_54 )
return - 1 ;
else
{
if ( V_51 -> V_22 > V_52 -> V_22 )
return 2 ;
else if ( V_51 -> V_22 < V_52 -> V_22 )
return - 2 ;
else
return 0 ;
}
}
T_12 *
F_36 ( T_12 * V_25 , T_14 type , const T_7 * V_19 ,
const T_7 * V_49 , const T_7 * V_20 , T_8 V_55 , T_5 * V_56 ,
T_8 V_57 , const T_7 * V_50 , T_15 V_27 , V_8 V_28 )
{
T_12 * V_13 = NULL ;
F_9 ( V_25 != NULL && V_25 -> type == V_35 ) ;
F_9 ( V_19 != NULL && strlen ( V_19 ) > 0 ) ;
F_9 ( V_27 != NULL ) ;
V_25 -> V_22 ++ ;
V_13 = F_25 ( T_12 , 1 ) ;
V_13 -> type = V_58 ;
V_13 -> V_53 = type ;
V_13 -> V_22 = F_37 ( V_25 -> V_26 ) + 1 ;
V_13 -> V_14 = F_14 ( V_19 ) ;
if ( V_20 != NULL && strlen ( V_20 ) > 0 )
V_13 -> V_20 = F_14 ( V_20 ) ;
if ( V_49 != NULL && strlen ( V_49 ) > 0 )
V_13 -> V_49 = F_14 ( V_49 ) ;
if ( V_56 != NULL && F_37 ( V_56 ) > 0 )
V_13 -> V_59 = F_38 ( V_56 ) ;
if ( V_50 )
V_13 -> V_50 = F_14 ( V_50 ) ;
V_13 -> V_57 = V_57 ;
V_13 -> V_55 = V_55 ;
V_13 -> V_27 = V_27 ;
V_13 -> V_28 = V_28 ;
V_25 -> V_26 = F_39 ( V_25 -> V_26 , V_13 , F_35 ) ;
return V_13 ;
}
static T_4
F_40 ( T_13 V_39 , T_13 V_60 )
{
if ( ! V_39 || ! V_60 )
return - 1 ;
T_12 * V_43 = ( T_12 * ) V_39 ;
if ( V_43 -> type != V_58 )
return - 2 ;
T_7 * V_19 = ( T_7 * ) V_60 ;
return F_28 ( V_43 -> V_14 , V_19 ) ;
}
T_12 * F_41 ( const T_12 * V_43 , const T_7 * V_19 )
{
T_12 * V_61 = 0 ;
T_5 * V_13 = F_31 ( V_43 -> V_26 , V_19 , F_40 ) ;
if ( V_13 )
V_61 = ( T_12 * ) V_13 -> V_42 ;
return V_61 ;
}
T_5 * F_42 ( T_5 * V_62 , T_7 * V_63 , T_7 * V_64 , T_8 V_65 )
{
T_16 * V_66 = F_25 ( T_16 , 1 ) ;
V_66 -> V_63 = F_14 ( V_63 ) ;
V_66 -> V_64 = F_14 ( V_64 ) ;
V_66 -> V_65 = V_65 ;
return F_15 ( V_62 , V_66 ) ;
}
static T_4
F_43 ( T_13 V_36 , T_13 V_37 )
{
if ( V_36 == 0 || V_37 == 0 )
return - 1 ;
T_17 * V_67 = ( T_17 * ) V_36 ;
T_12 * V_13 = ( T_12 * ) V_37 ;
if ( V_67 -> V_67 && F_28 ( V_67 -> V_67 -> V_14 , V_13 -> V_14 ) == 0 )
return 0 ;
return - 1 ;
}
void F_44 ( T_12 * V_13 , T_15 V_27 , V_8 V_68 )
{
if ( V_13 == 0 || V_68 == 0 || V_27 == 0 )
return;
T_17 * V_69 = NULL ;
T_5 * V_70 = F_31 ( V_71 , V_13 , F_43 ) ;
if ( ! V_70 )
{
V_69 = F_25 ( T_17 , 1 ) ;
V_69 -> V_67 = V_13 ;
V_71 = F_15 ( V_71 , V_69 ) ;
}
else
{
V_69 = ( T_17 * ) V_70 -> V_42 ;
}
T_18 * V_72 = F_25 ( T_18 , 1 ) ;
V_72 -> V_27 = V_27 ;
V_72 -> V_68 = V_68 ;
V_69 -> V_62 = F_15 ( V_69 -> V_62 , V_72 ) ;
}
static void
F_45 ( T_19 V_73 , T_12 * V_13 , V_8 V_42 , V_8 V_74 , T_8 V_75 )
{
T_5 * V_69 = F_31 ( V_71 , V_13 , F_43 ) ;
T_5 * V_41 = NULL ;
if ( ! V_69 || ! V_69 -> V_42 )
return;
T_20 * V_76 = F_25 ( T_20 , 1 ) ;
V_76 -> V_28 = V_42 ;
V_76 -> V_77 = V_74 ;
V_76 -> V_75 = V_75 ;
V_76 -> type = V_73 ;
V_41 = ( ( T_17 * ) ( V_69 -> V_42 ) ) -> V_62 ;
while ( V_41 && V_41 -> V_42 )
{
T_18 * V_72 = ( T_18 * ) V_41 -> V_42 ;
if ( V_72 -> V_27 && V_72 -> V_68 )
V_72 -> V_27 ( V_13 , V_72 -> V_68 , V_76 ) ;
V_41 = F_30 ( V_41 ) ;
}
F_34 ( V_76 ) ;
}
void F_46 ( T_12 * V_13 , V_8 V_42 , T_8 V_75 )
{
F_45 ( V_78 , V_13 , V_42 , NULL , V_75 ) ;
}
void F_47 ( T_12 * V_13 , V_8 V_42 , T_8 V_75 )
{
if ( V_13 -> V_53 == V_79 )
F_45 ( V_80 , V_13 , V_42 , NULL , V_75 ) ;
}
void F_48 ( T_12 * V_13 , V_8 V_42 , V_8 V_74 , T_8 V_75 )
{
if ( V_13 -> V_53 == V_79 )
F_45 ( V_81 , V_13 , V_42 , V_74 , V_75 ) ;
}
void F_49 ( T_12 * V_13 , V_8 V_42 , V_8 V_74 , T_8 V_75 )
{
if ( V_13 -> V_53 == V_79 )
F_45 ( V_82 , V_13 , V_42 , V_74 , V_75 ) ;
}
void F_50 ( T_12 * V_13 , V_8 V_42 , V_8 V_74 , T_8 V_75 )
{
if ( V_13 -> V_53 == V_79 )
F_45 ( V_83 , V_13 , V_42 , V_74 , V_75 ) ;
}
void F_51 ( T_12 * V_13 , T_8 V_84 )
{
F_45 ( V_85 , V_13 , F_52 ( V_84 ? 1 : 0 ) , 0 , TRUE ) ;
}
extern void F_53 ( const char * V_86 , T_8 V_87 )
{
T_1 V_4 ;
T_2 * V_5 = NULL ;
V_4 = ( V_87 == TRUE ) ? V_88 : V_89 ;
V_5 = F_2 ( V_46 , V_47 ) ;
F_33 ( V_5 , F_14 ( L_6 ) , ( V_8 ) & V_4 ) ;
F_33 ( V_5 , F_14 ( L_7 ) , F_14 ( V_86 ) ) ;
F_33 ( V_5 , F_14 ( L_8 ) , ( V_8 ) & V_87 ) ;
F_3 ( V_4 , V_5 ) ;
}
extern void F_54 ( T_21 V_90 )
{
T_2 * V_5 = NULL ;
V_5 = F_2 ( V_46 , V_47 ) ;
F_33 ( V_5 , F_14 ( L_9 ) , F_55 ( V_90 ) ) ;
F_3 ( V_91 , V_5 ) ;
}
extern void F_56 ( const char * V_92 , const char * V_93 , const char * V_94 )
{
T_2 * V_5 = NULL ;
V_5 = F_2 ( V_46 , V_47 ) ;
F_33 ( V_5 , F_14 ( L_10 ) , F_14 ( V_92 ) ) ;
F_33 ( V_5 , F_14 ( L_11 ) , F_14 ( V_93 ) ) ;
F_33 ( V_5 , F_14 ( L_12 ) , F_14 ( V_94 ) ) ;
F_3 ( V_95 , V_5 ) ;
}
extern void F_57 ( T_22 * * V_96 )
{
static T_22 V_97 = { FALSE , V_98 , NULL , 0 , 0 , FALSE } ;
#ifdef F_58
T_2 * V_5 ;
T_7 * V_99 = F_14 ( L_13 ) ;
V_5 = F_2 ( V_46 , V_47 ) ;
F_33 ( V_5 , V_99 , & V_97 ) ;
F_3 ( V_100 , V_5 ) ;
F_59 ( V_5 ) ;
F_34 ( V_99 ) ;
#else
V_97 . V_101 = FALSE ;
V_97 . V_102 = 0 ;
V_97 . V_103 = NULL ;
V_97 . V_104 = 0 ;
V_97 . V_105 = FALSE ;
V_97 . V_106 = V_98 ;
#endif
* V_96 = & V_97 ;
}
extern void F_60 ( T_1 V_4 , T_3 V_27 )
{
T_4 * V_7 = 0 ;
V_7 = ( T_4 * ) F_4 ( sizeof( T_4 ) ) ;
* V_7 = V_4 ;
F_1 () ;
if ( ! F_6 ( V_1 , V_7 , NULL , NULL ) )
F_33 ( V_1 , V_7 , ( V_8 ) V_27 ) ;
}

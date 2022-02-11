void F_1 ( T_1 * V_1 ) {
T_2 * V_2 = F_2 ( V_1 ) ;
printf ( L_1 , V_2 ) ;
F_3 ( V_2 ) ;
}
T_2 * F_2 ( T_1 * V_1 ) {
return ( V_1 ? F_4 ( V_1 -> V_3 ) : NULL ) ;
}
T_1 * F_5 ( T_3 V_4 ,
const T_2 * V_5 ) {
T_1 * V_6 = F_6 ( T_1 , 1 ) ;
V_6 -> V_3 = F_4 ( V_5 ) ;
V_6 -> V_4 = V_4 ;
return V_6 ;
}
T_4 F_7 ( T_5 * V_7 , T_1 * V_8 ) {
if ( V_7 == NULL || V_7 -> V_9 == NULL || V_8 == NULL )
return FALSE ;
if ( F_8 ( V_7 -> V_9 -> V_3 , V_8 -> V_3 ) == 0 )
return TRUE ;
return FALSE ;
}
void F_9 ( T_1 * V_1 ) {
if ( V_1 )
F_3 ( V_1 -> V_3 ) ;
F_3 ( V_1 ) ;
}
T_6 F_10 ( T_1 * V_1 ) {
if ( V_1 == NULL || V_1 -> V_3 == NULL || V_1 -> V_4 != V_10 )
return ( T_6 ) 0 ;
return ( T_6 ) F_11 ( V_1 -> V_3 , NULL , 10 ) ;
}
T_7 F_12 ( T_1 * V_1 ) {
if ( V_1 == NULL || V_1 -> V_3 == NULL || V_1 -> V_4 != V_11 )
return ( T_7 ) 0 ;
return ( T_7 ) F_13 ( V_1 -> V_3 , NULL , 10 ) ;
}
T_8 F_14 ( T_1 * V_1 ) {
if ( V_1 == NULL || V_1 -> V_3 == NULL || V_1 -> V_4 != V_12 )
return ( T_8 ) 0 ;
return F_11 ( V_1 -> V_3 , NULL , 10 ) ;
}
T_9 F_15 ( T_1 * V_1 ) {
if ( V_1 == NULL || V_1 -> V_3 == NULL || V_1 -> V_4 != V_13 )
return ( T_9 ) 0 ;
return F_16 ( V_1 -> V_3 , NULL ) ;
}
T_4 F_17 ( T_1 * V_1 ) {
if ( V_1 == NULL || V_1 -> V_3 == NULL )
return FALSE ;
if ( V_1 -> V_4 != V_14 && V_1 -> V_4 != V_15 )
return FALSE ;
return F_18 ( V_16 , V_1 -> V_3 , V_17 , ( V_18 ) 0 ) ;
}
T_2 * F_19 ( T_1 * V_1 ) {
return V_1 != NULL ? V_1 -> V_3 : NULL ;
}
static T_10 * F_20 ( const T_2 * V_19 ) {
T_11 * V_20 = NULL ;
T_12 * V_21 = NULL ;
T_13 * error = NULL ;
T_2 * V_22 = NULL ;
T_7 V_23 = V_24 ;
T_10 * V_25 = F_6 ( T_10 , 1 ) ;
V_25 -> V_26 = NULL ;
if ( ( V_20 = F_21 ( L_2 ,
( V_27 ) V_17 , ( V_18 ) 0 , NULL ) ) != NULL ) {
F_22 ( V_20 , V_19 , ( V_18 ) 0 , & V_21 ) ;
if ( F_23 ( V_21 ) )
V_25 -> V_26 = F_24 ( V_21 , 0 ) ;
F_25 ( V_21 ) ;
F_26 ( V_20 ) ;
}
if ( V_25 -> V_26 == NULL ) {
F_3 ( V_25 ) ;
return NULL ;
}
V_25 -> V_28 = F_27 ( V_29 , V_30 , NULL , F_3 ) ;
V_20 = F_21 ( L_3 ,
( V_27 ) V_17 , ( V_18 ) 0 , NULL ) ;
if ( V_20 != NULL ) {
F_28 ( V_20 , V_19 , - 1 , 0 , ( V_18 ) 0 , & V_21 , & error ) ;
while ( F_23 ( V_21 ) ) {
T_2 * V_31 = F_24 ( V_21 , 1 ) ;
if ( V_31 == NULL )
break;
V_22 = F_24 ( V_21 , 2 ) ;
if ( F_29 ( V_31 , L_4 ) == 0 ) {
V_23 = V_32 ;
} else if ( F_29 ( V_31 , L_5 ) == 0 ) {
V_23 = V_33 ;
} else if ( F_29 ( V_31 , L_6 ) == 0 ) {
V_23 = V_34 ;
} else if ( F_29 ( V_31 , L_7 ) == 0 ) {
V_23 = V_35 ;
} else if ( F_29 ( V_31 , L_8 ) == 0 ) {
V_23 = V_36 ;
} else if ( F_29 ( V_31 , L_9 ) == 0 ) {
V_23 = V_37 ;
} else if ( F_29 ( V_31 , L_10 ) == 0 ) {
V_23 = V_38 ;
} else if ( F_29 ( V_31 , L_11 ) == 0 ) {
V_23 = V_39 ;
} else if ( F_29 ( V_31 , L_12 ) == 0 ) {
V_23 = V_40 ;
} else if ( F_29 ( V_31 , L_13 ) == 0 ) {
V_23 = V_41 ;
} else if ( F_29 ( V_31 , L_14 ) == 0 ) {
V_23 = V_42 ;
} else if ( F_29 ( V_31 , L_15 ) == 0 ) {
V_23 = V_43 ;
} else if ( F_29 ( V_31 , L_16 ) == 0 ) {
V_23 = V_44 ;
} else if ( F_29 ( V_31 , L_17 ) == 0 ) {
V_23 = V_45 ;
} else if ( F_29 ( V_31 , L_18 ) == 0 ) {
V_23 = V_46 ;
} else if ( F_29 ( V_31 , L_19 ) == 0 ) {
V_23 = V_47 ;
} else if ( F_29 ( V_31 , L_20 ) == 0 ) {
V_23 = V_48 ;
} else if ( F_29 ( V_31 , L_21 ) == 0 ) {
V_23 = V_49 ;
} else if ( F_29 ( V_31 , L_22 ) == 0 ) {
V_23 = V_50 ;
} else if ( F_29 ( V_31 , L_23 ) == 0 ) {
V_23 = V_51 ;
} else if ( F_29 ( V_31 , L_24 ) == 0 ) {
V_23 = V_52 ;
} else if ( F_29 ( V_31 , L_25 ) == 0 ) {
V_23 = V_53 ;
} else {
V_23 = V_24 ;
}
F_30 ( V_25 -> V_28 , F_31 ( V_23 ) , V_22 ) ;
F_32 ( V_21 , & error ) ;
F_3 ( V_31 ) ;
}
F_25 ( V_21 ) ;
F_26 ( V_20 ) ;
}
return V_25 ;
}
static T_14 * F_33 ( const T_2 * V_19 ) {
T_14 * V_54 = NULL ;
T_10 * V_55 = NULL ;
T_2 * * V_56 , * * V_57 ;
V_57 = V_56 = F_34 ( V_19 , L_26 , 0 ) ;
while ( * V_57 != NULL ) {
V_55 = F_20 ( * V_57 ) ;
if ( V_55 )
V_54 = F_35 ( V_54 , V_55 ) ;
V_57 ++ ;
}
F_36 ( V_56 ) ;
return V_54 ;
}
static void F_37 ( T_15 * V_58 ) {
if ( V_58 == NULL )
return;
F_3 ( V_58 -> V_59 ) ;
F_3 ( V_58 -> V_60 ) ;
F_3 ( V_58 ) ;
}
static void F_38 ( T_16 V_5 , T_16 T_17 V_61 ) {
F_37 ( ( T_15 * ) V_5 ) ;
}
void F_39 ( T_5 * V_62 ) {
if ( V_62 == NULL )
return;
F_3 ( V_62 -> V_59 ) ;
F_3 ( V_62 -> V_60 ) ;
F_3 ( V_62 -> V_63 ) ;
F_3 ( V_62 -> V_64 ) ;
F_3 ( V_62 -> V_65 ) ;
F_3 ( V_62 -> V_66 ) ;
F_3 ( V_62 -> V_67 ) ;
if ( V_62 -> V_68 != NULL )
F_9 ( V_62 -> V_68 ) ;
if ( V_62 -> V_69 != NULL )
F_9 ( V_62 -> V_69 ) ;
if ( V_62 -> V_9 != NULL )
F_9 ( V_62 -> V_9 ) ;
F_40 ( V_62 -> V_70 , ( V_71 ) F_38 , NULL ) ;
F_41 ( V_62 -> V_70 ) ;
F_3 ( V_62 ) ;
}
static void F_42 ( T_18 * V_58 ) {
if ( V_58 == NULL )
return;
F_3 ( V_58 -> V_72 ) ;
F_3 ( V_58 -> V_60 ) ;
}
static void F_43 ( T_19 * V_73 ) {
if ( V_73 == NULL )
return;
F_3 ( V_73 -> V_60 ) ;
F_3 ( V_73 -> V_74 ) ;
F_3 ( V_73 -> V_63 ) ;
F_3 ( V_73 -> V_64 ) ;
}
void F_44 ( T_14 * V_62 ) {
F_40 ( V_62 , ( V_71 ) F_39 , NULL ) ;
F_41 ( V_62 ) ;
}
static T_6 F_45 ( T_20 V_75 , T_20 V_76 ) {
if ( ( ( const T_5 * ) V_75 ) -> V_77 == * ( ( const int * ) V_76 ) )
return 0 ;
return 1 ;
}
static T_6 F_46 ( T_20 V_75 , T_20 V_76 ) {
if ( ( ( const T_19 * ) V_75 ) -> V_78 == * ( ( const int * ) V_76 ) )
return 0 ;
return 1 ;
}
static void F_47 ( T_16 V_19 , T_16 T_17 V_61 ) {
T_10 * V_79 = ( T_10 * ) V_19 ;
if ( V_79 == NULL )
return;
F_3 ( V_79 -> V_26 ) ;
F_48 ( V_79 -> V_28 ) ;
F_3 ( V_79 ) ;
}
static void F_49 ( T_14 * V_54 ) {
if ( V_54 == NULL )
return;
F_40 ( V_54 , F_47 , NULL ) ;
F_41 ( V_54 ) ;
}
static T_5 * F_50 ( T_14 * args , T_10 * V_19 ) {
T_2 * V_22 = NULL ;
T_5 * V_80 = NULL ;
T_15 * V_72 = NULL ;
T_14 * V_81 = NULL ;
int V_82 ;
T_21 V_83 = V_84 ;
if ( V_19 == NULL )
return V_80 ;
if ( F_29 ( V_19 -> V_26 , L_8 ) == 0 ) {
V_83 = V_85 ;
} else if ( F_29 ( V_19 -> V_26 , L_10 ) == 0 ) {
V_83 = V_86 ;
}
if ( V_83 == V_85 ) {
V_80 = F_6 ( T_5 , 1 ) ;
V_80 -> V_87 = V_88 ;
V_80 -> V_89 = TRUE ;
if ( ( V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_32 ) ) ) == NULL ) {
F_39 ( V_80 ) ;
return NULL ;
}
if ( sscanf ( V_22 , L_27 , & ( V_80 -> V_77 ) ) != 1 ) {
F_39 ( V_80 ) ;
return NULL ;
}
if ( ( V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_33 ) ) ) == NULL ) {
F_39 ( V_80 ) ;
return NULL ;
}
V_80 -> V_59 = F_4 ( V_22 ) ;
if ( strlen ( V_80 -> V_59 ) == 0 ) {
F_39 ( V_80 ) ;
return NULL ;
}
if ( ( V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_34 ) ) ) == NULL ) {
F_39 ( V_80 ) ;
return NULL ;
}
V_80 -> V_60 = F_4 ( V_22 ) ;
if ( ( V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_40 ) ) )
!= NULL ) {
V_80 -> V_63 = F_4 ( V_22 ) ;
}
if ( ( V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_41 ) ) )
!= NULL ) {
V_80 -> V_64 = F_4 ( V_22 ) ;
}
if ( ( V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_42 ) ) )
!= NULL ) {
V_80 -> V_90 = F_18 ( V_16 , V_22 , V_17 , ( V_18 ) 0 ) ;
}
if ( ( V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_43 ) ) )
!= NULL ) {
V_80 -> V_65 = F_4 ( V_22 ) ;
}
if ( ( V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_49 ) ) )
!= NULL ) {
V_80 -> V_66 = F_4 ( V_22 ) ;
}
if ( ( V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_47 ) ) )
!= NULL ) {
V_80 -> V_91 = F_18 ( V_16 , V_22 , V_17 , ( V_18 ) 0 ) ;
}
if ( ( V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_35 ) ) )
== NULL ) {
F_39 ( V_80 ) ;
return NULL ;
}
if ( F_29 ( V_22 , L_28 ) == 0 ) {
V_80 -> V_87 = V_10 ;
} else if ( F_29 ( V_22 , L_29 ) == 0 ) {
V_80 -> V_87 = V_11 ;
} else if ( F_29 ( V_22 , L_30 ) == 0 ) {
V_80 -> V_87 = V_12 ;
} else if ( F_29 ( V_22 , L_31 ) == 0 ) {
V_80 -> V_87 = V_13 ;
} else if ( F_29 ( V_22 , L_32 ) == 0 ) {
V_80 -> V_87 = V_14 ;
} else if ( F_29 ( V_22 , L_33 ) == 0 ) {
V_80 -> V_87 = V_15 ;
} else if ( F_29 ( V_22 , L_34 ) == 0 ) {
V_80 -> V_87 = V_92 ;
} else if ( F_29 ( V_22 , L_35 ) == 0 ) {
V_80 -> V_87 = V_93 ;
} else if ( F_29 ( V_22 , L_36 ) == 0 ) {
V_80 -> V_87 = V_94 ;
} else if ( F_29 ( V_22 , L_37 ) == 0 ) {
V_80 -> V_87 = V_95 ;
V_80 -> V_89 = FALSE ;
} else if ( F_29 ( V_22 , L_38 ) == 0 ) {
V_80 -> V_87 = V_96 ;
} else if ( F_29 ( V_22 , L_39 ) == 0 ) {
V_80 -> V_87 = V_97 ;
} else if ( F_29 ( V_22 , L_40 ) == 0 ) {
V_80 -> V_87 = V_98 ;
} else {
printf ( L_41 , V_22 ) ;
F_39 ( V_80 ) ;
return NULL ;
}
if ( ( V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_48 ) ) )
!= NULL ) {
V_80 -> V_89 = F_18 ( V_16 , V_22 , V_17 , ( V_18 ) 0 ) ;
}
if ( ( V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_39 ) ) )
!= NULL ) {
T_2 * V_99 = F_52 ( V_22 , - 1 , L_42 ) ;
if ( V_99 == NULL ) {
printf ( L_43 ,
V_22 ) ;
F_39 ( V_80 ) ;
return NULL ;
}
if ( ( V_80 -> V_68 = F_5 (
V_80 -> V_87 , V_22 ) ) == NULL ) {
printf ( L_43 ,
V_22 ) ;
F_39 ( V_80 ) ;
return NULL ;
}
if ( ( V_80 -> V_69 = F_5 (
V_80 -> V_87 , V_99 + 1 ) ) == NULL ) {
printf ( L_43 ,
V_22 ) ;
F_39 ( V_80 ) ;
return NULL ;
}
}
if ( ( V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_37 ) ) )
!= NULL ) {
if ( V_80 -> V_87 != V_97 && V_80 -> V_87 != V_92 )
{
if ( ( V_80 -> V_9 = F_5 (
V_80 -> V_87 , V_22 ) ) == NULL ) {
printf ( L_44 , V_22 ) ;
}
}
}
} else if ( V_83 == V_86 ) {
if ( ( V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_36 ) ) )
== NULL ) {
printf ( L_45 ) ;
return NULL ;
}
if ( sscanf ( V_22 , L_27 , & V_82 ) != 1 ) {
printf ( L_46 ) ;
return NULL ;
}
if ( ( V_81 = F_53 ( args , & V_82 , F_45 ) )
== NULL ) {
printf ( L_47 , V_82 ) ;
return NULL ;
}
V_72 = F_6 ( T_15 , 1 ) ;
V_72 -> V_77 = V_82 ;
if ( ( V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_38 ) ) )
== NULL ) {
F_37 ( V_72 ) ;
return NULL ;
}
V_72 -> V_59 = F_4 ( V_22 ) ;
if ( ( V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_34 ) ) )
== NULL ) {
F_37 ( V_72 ) ;
return NULL ;
}
V_72 -> V_60 = F_4 ( V_22 ) ;
if ( ( V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_46 ) ) )
!= NULL ) {
V_72 -> V_100 = F_4 ( V_22 ) ;
}
if ( ( V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_37 ) ) )
!= NULL ) {
V_72 -> V_101 = F_18 ( V_16 , V_22 , V_17 , ( V_18 ) 0 ) ;
}
if ( ( V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_45 ) ) )
!= NULL ) {
V_72 -> V_102 = F_18 ( V_16 , V_22 , V_17 , ( V_18 ) 0 ) ;
}
( ( T_5 * ) V_81 -> V_5 ) -> V_70 = F_35 (
( ( T_5 * ) V_81 -> V_5 ) -> V_70 , V_72 ) ;
return NULL ;
}
return V_80 ;
}
T_14 * F_54 ( T_2 * V_103 ) {
T_14 * V_104 = NULL ;
T_14 * V_105 = NULL ;
T_14 * V_106 = NULL ;
V_105 = F_33 ( V_103 ) ;
V_106 = V_105 ;
while ( V_105 ) {
T_5 * V_107 = NULL ;
T_10 * V_26 = ( T_10 * ) V_105 -> V_5 ;
if ( ( V_107 = F_50 ( V_104 , V_26 ) ) != NULL )
V_104 = F_35 ( V_104 , ( T_16 ) V_107 ) ;
V_105 = F_55 ( V_105 ) ;
}
F_49 ( V_106 ) ;
return V_104 ;
}
static T_22 * F_56 ( T_10 * V_19 ) {
T_21 V_83 = V_84 ;
T_2 * V_22 = NULL ;
T_22 * V_108 = NULL ;
if ( V_19 == NULL )
return NULL ;
if ( F_29 ( V_19 -> V_26 , L_48 ) == 0 ) {
V_83 = V_109 ;
} else if ( F_29 ( V_19 -> V_26 , L_49 ) == 0 ) {
V_83 = V_110 ;
}
if ( V_83 == V_84 )
return NULL ;
V_108 = F_6 ( T_22 , 1 ) ;
V_108 -> V_111 = V_83 ;
if ( ( V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_38 ) ) )
== NULL && V_83 == V_109 ) {
printf ( L_50 ) ;
F_3 ( V_108 ) ;
return NULL ;
}
V_108 -> V_59 = F_4 ( V_22 ) ;
if ( ( V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_34 ) ) )
== NULL && V_83 == V_109 ) {
printf ( L_51 ) ;
F_3 ( V_108 -> V_59 ) ;
F_3 ( V_108 ) ;
return NULL ;
}
V_108 -> V_60 = F_4 ( V_22 ) ;
if ( ( V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_50 ) ) )
!= NULL ) {
V_108 -> V_112 = F_4 ( V_22 ) ;
}
if ( ( V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_51 ) ) )
!= NULL ) {
V_108 -> V_113 = F_4 ( V_22 ) ;
}
return V_108 ;
}
static T_19 * F_57 ( T_14 * V_114 , T_10 * V_19 )
{
T_21 V_83 = V_84 ;
T_2 * V_22 = NULL ;
T_19 * V_115 = NULL ;
T_18 * V_72 = NULL ;
T_14 * V_81 = NULL ;
T_23 V_78 = 0 ;
if ( V_19 == NULL )
return NULL ;
if ( F_29 ( V_19 -> V_26 , L_24 ) == 0 ) {
V_83 = V_116 ;
} else if ( F_29 ( V_19 -> V_26 , L_10 ) == 0 ) {
V_83 = V_86 ;
}
if ( V_83 == V_84 )
return NULL ;
if ( V_83 == V_116 ) {
V_115 = F_6 ( T_19 , 1 ) ;
V_115 -> V_117 = V_118 ;
V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_32 ) ) ;
if ( V_22 == NULL ) {
F_43 ( V_115 ) ;
return NULL ;
}
if ( ! F_58 ( V_22 , NULL , & V_78 ) ) {
F_43 ( V_115 ) ;
return NULL ;
}
V_115 -> V_78 = ( int ) V_78 ;
V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_34 ) ) ;
if ( V_22 == NULL ) {
F_43 ( V_115 ) ;
return NULL ;
}
V_115 -> V_60 = F_4 ( V_22 ) ;
if ( ( V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_49 ) ) )
!= NULL ) {
V_115 -> V_74 = F_4 ( V_22 ) ;
}
if ( ( V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_47 ) ) )
!= NULL ) {
V_115 -> V_91 = F_18 ( V_16 , V_22 , V_17 , ( V_18 ) 0 ) ;
}
V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_40 ) ) ;
if ( V_22 != NULL ) {
V_115 -> V_63 = F_4 ( V_22 ) ;
}
V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_41 ) ) ;
if ( V_22 != NULL ) {
V_115 -> V_64 = F_4 ( V_22 ) ;
}
V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_35 ) ) ;
if ( V_22 == NULL ) {
F_43 ( V_115 ) ;
return NULL ;
}
T_3 V_87 = V_88 ;
if ( F_29 ( V_22 , L_32 ) == 0 ) {
V_115 -> V_117 = V_119 ;
V_87 = V_14 ;
} else if ( F_29 ( V_22 , L_52 ) == 0 ) {
V_115 -> V_117 = V_120 ;
} else if ( F_29 ( V_22 , L_34 ) == 0 ) {
V_115 -> V_117 = V_121 ;
} else if ( F_29 ( V_22 , L_36 ) == 0 ) {
V_115 -> V_117 = V_122 ;
V_87 = V_94 ;
} else {
printf ( L_53 , V_22 ) ;
F_43 ( V_115 ) ;
return NULL ;
}
V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_53 ) ) ;
if ( V_22 != NULL ) {
if ( F_29 ( V_22 , L_24 ) == 0 ) {
V_115 -> V_123 = V_124 ;
} else if ( F_29 ( V_22 , L_23 ) == 0 ) {
V_115 -> V_123 = V_125 ;
} else if ( F_29 ( V_22 , L_54 ) == 0 ) {
V_115 -> V_123 = V_126 ;
} else if ( F_29 ( V_22 , L_55 ) == 0 ) {
V_115 -> V_123 = V_127 ;
} else {
printf ( L_56 , V_22 ) ;
V_115 -> V_123 = V_128 ;
}
} else {
V_115 -> V_123 = V_124 ;
}
V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_37 ) ) ;
if ( V_22 != NULL ) {
if ( V_87 != V_88 ) {
T_1 * complex = F_5 ( V_87 , V_22 ) ;
if ( complex != NULL ) {
if ( V_87 == V_14 ) {
V_115 -> V_129 . boolean = F_17 ( complex ) ;
} else if ( V_87 == V_94 ) {
V_115 -> V_129 . string = F_4 ( complex -> V_3 ) ;
}
F_9 ( complex ) ;
} else {
printf ( L_44 , V_22 ) ;
}
}
}
} else if ( V_83 == V_86 ) {
V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_52 ) ) ;
if ( V_22 == NULL ) {
printf ( L_57 ) ;
return NULL ;
}
if ( ! F_58 ( V_22 , NULL , & V_78 ) ) {
F_43 ( V_115 ) ;
return NULL ;
}
V_81 = F_53 ( V_114 , & V_78 , F_46 ) ;
if ( V_81 == NULL ) {
printf ( L_58 , V_78 ) ;
return NULL ;
}
V_72 = F_6 ( T_18 , 1 ) ;
V_72 -> V_78 = ( int ) V_78 ;
V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_38 ) ) ;
if ( V_22 == NULL ) {
F_42 ( V_72 ) ;
return NULL ;
}
V_72 -> V_72 = F_4 ( V_22 ) ;
V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_34 ) ) ;
if ( V_22 == NULL ) {
F_42 ( V_72 ) ;
return NULL ;
}
V_72 -> V_60 = F_4 ( V_22 ) ;
V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_37 ) ) ;
if ( V_22 != NULL ) {
V_72 -> V_101 = F_18 ( V_16 , V_22 , V_17 , ( V_18 ) 0 ) ;
}
V_115 = ( T_19 * ) V_81 -> V_5 ;
V_115 -> V_70 = F_35 ( V_115 -> V_70 , V_72 ) ;
return NULL ;
}
return V_115 ;
}
T_14 * F_59 ( T_2 * V_103 , T_14 * * V_114 ) {
T_14 * V_104 = NULL ;
T_14 * V_130 = NULL ;
T_14 * V_105 = F_33 ( V_103 ) ;
V_130 = V_105 ;
while ( V_105 ) {
T_22 * V_108 = NULL ;
T_19 * V_131 = NULL ;
T_10 * V_132 = ( T_10 * ) V_105 -> V_5 ;
if ( V_132 ) {
if ( ( F_29 ( V_132 -> V_26 , L_48 ) == 0 ) ||
( F_29 ( V_132 -> V_26 , L_49 ) == 0 ) )
{
if ( ( V_108 = F_56 ( V_132 ) ) ) {
V_104 = F_35 ( V_104 , V_108 ) ;
}
} else if ( V_114 &&
( ( F_29 ( V_132 -> V_26 , L_24 ) == 0 ) ||
( F_29 ( V_132 -> V_26 , L_10 ) == 0 ) ) )
{
if ( ( V_131 = F_57 ( * V_114 , V_132 ) ) ) {
* V_114 = F_35 ( * V_114 , V_131 ) ;
}
}
}
V_105 = F_55 ( V_105 ) ;
}
F_49 ( V_130 ) ;
return V_104 ;
}
static T_24 * F_60 ( T_10 * V_19 ) {
T_2 * V_22 = NULL ;
T_21 V_83 = V_84 ;
T_24 * V_104 = NULL ;
if ( V_19 == NULL )
return V_104 ;
if ( F_29 ( V_19 -> V_26 , L_59 ) == 0 ) {
V_83 = V_133 ;
}
if ( V_83 == V_84 )
return V_104 ;
V_104 = F_6 ( T_24 , 1 ) ;
V_104 -> V_134 = - 1 ;
V_104 -> V_135 = NULL ;
V_104 -> V_60 = NULL ;
if ( ( V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_32 ) ) )
== NULL ) {
printf ( L_60 ) ;
F_3 ( V_104 ) ;
return NULL ;
}
if ( sscanf ( V_22 , L_27 , & ( V_104 -> V_134 ) ) != 1 ) {
printf ( L_61 ) ;
F_3 ( V_104 ) ;
return NULL ;
}
if ( ( V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_44 ) ) )
== NULL ) {
printf ( L_62 ) ;
F_3 ( V_104 ) ;
return NULL ;
}
V_104 -> V_135 = F_4 ( V_22 ) ;
if ( ( V_22 = ( T_2 * ) F_51 ( V_19 -> V_28 , F_31 ( V_34 ) ) )
== NULL ) {
printf ( L_63 ) ;
F_3 ( V_104 -> V_135 ) ;
F_3 ( V_104 ) ;
return NULL ;
}
V_104 -> V_60 = F_4 ( V_22 ) ;
return V_104 ;
}
T_14 * F_61 ( T_2 * V_103 ) {
T_14 * V_105 = NULL ;
T_14 * V_106 = NULL ;
T_14 * V_104 = NULL ;
V_105 = F_33 ( V_103 ) ;
V_106 = V_105 ;
while ( V_105 ) {
T_24 * V_5 = NULL ;
if ( ( V_5 = F_60 ( ( T_10 * ) V_105 -> V_5 ) ) != NULL )
V_104 = F_35 ( V_104 , V_5 ) ;
V_105 = F_55 ( V_105 ) ;
}
F_49 ( V_106 ) ;
return V_104 ;
}

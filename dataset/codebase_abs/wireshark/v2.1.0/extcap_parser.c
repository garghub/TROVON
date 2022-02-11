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
void F_20 ( T_10 * V_19 ) {
if ( V_19 != NULL )
{
F_3 ( V_19 -> V_20 ) ;
F_3 ( V_19 -> V_21 ) ;
}
F_3 ( V_19 ) ;
}
void F_21 ( T_11 * V_22 ) {
T_10 * V_23 ;
if ( V_22 == NULL )
return;
if ( V_22 -> V_24 != NULL )
F_3 ( V_22 -> V_24 ) ;
while ( V_22 -> V_25 != NULL ) {
V_23 = V_22 -> V_25 ;
V_22 -> V_25 = V_23 -> V_26 ;
F_20 ( V_23 ) ;
}
F_3 ( V_22 ) ;
}
void F_22 ( T_11 * V_27 ) {
T_11 * V_28 ;
while ( V_27 != NULL ) {
V_28 = V_27 -> V_29 ;
F_21 ( V_27 ) ;
V_27 = V_28 ;
}
}
T_11 * F_23 ( const T_2 * V_22 ) {
T_10 * V_23 = NULL ;
T_12 * V_30 = NULL ;
T_13 * V_31 = NULL ;
T_14 * error = NULL ;
T_11 * V_32 = F_24 ( T_11 , 1 ) ;
V_32 -> V_24 = NULL ;
V_32 -> V_29 = NULL ;
V_32 -> V_25 = NULL ;
if ( ( V_30 = F_25 ( L_2 ,
( V_33 ) V_17 , ( V_18 ) 0 , NULL ) ) != NULL ) {
F_26 ( V_30 , V_22 , ( V_18 ) 0 , & V_31 ) ;
if ( F_27 ( V_31 ) )
V_32 -> V_24 = F_28 ( V_31 , 0 ) ;
F_29 ( V_31 ) ;
F_30 ( V_30 ) ;
}
if ( V_32 -> V_24 == NULL ) {
F_21 ( V_32 ) ;
return NULL ;
}
V_30 = F_25 ( L_3 ,
( V_33 ) V_17 , ( V_18 ) 0 , NULL ) ;
if ( V_30 != NULL ) {
F_31 ( V_30 , V_22 , - 1 , 0 , ( V_18 ) 0 , & V_31 , & error ) ;
while( F_27 ( V_31 ) ) {
T_2 * V_20 = F_28 ( V_31 , 1 ) ;
if ( V_20 == NULL )
break;
V_23 = F_24 ( T_10 , 1 ) ;
V_23 -> V_20 = V_20 ;
V_23 -> V_21 = F_28 ( V_31 , 2 ) ;
if ( F_32 ( V_23 -> V_20 , L_4 ) == 0 ) {
V_23 -> V_34 = V_35 ;
} else if ( F_32 ( V_23 -> V_20 , L_5 ) == 0 ) {
V_23 -> V_34 = V_36 ;
} else if ( F_32 ( V_23 -> V_20 , L_6 ) == 0 ) {
V_23 -> V_34 = V_37 ;
} else if ( F_32 ( V_23 -> V_20 , L_7 ) == 0 ) {
V_23 -> V_34 = V_38 ;
} else if ( F_32 ( V_23 -> V_20 , L_8 ) == 0 ) {
V_23 -> V_34 = V_39 ;
} else if ( F_32 ( V_23 -> V_20 , L_9 ) == 0 ) {
V_23 -> V_34 = V_40 ;
} else if ( F_32 ( V_23 -> V_20 , L_10 ) == 0 ) {
V_23 -> V_34 = V_41 ;
} else if ( F_32 ( V_23 -> V_20 , L_11 ) == 0 ) {
V_23 -> V_34 = V_42 ;
} else if ( F_32 ( V_23 -> V_20 , L_12 ) == 0 ) {
V_23 -> V_34 = V_43 ;
} else if ( F_32 ( V_23 -> V_20 , L_13 ) == 0 ) {
V_23 -> V_34 = V_44 ;
} else if ( F_32 ( V_23 -> V_20 , L_14 ) == 0 ) {
V_23 -> V_34 = V_45 ;
} else if ( F_32 ( V_23 -> V_20 , L_15 ) == 0 ) {
V_23 -> V_34 = V_46 ;
} else if ( F_32 ( V_23 -> V_20 , L_16 ) == 0 ) {
V_23 -> V_34 = V_47 ;
} else if ( F_32 ( V_23 -> V_20 , L_17 ) == 0 ) {
V_23 -> V_34 = V_48 ;
} else if ( F_32 ( V_23 -> V_20 , L_18 ) == 0 ) {
V_23 -> V_34 = V_49 ;
} else if ( F_32 ( V_23 -> V_20 , L_19 ) == 0 ) {
V_23 -> V_34 = V_50 ;
} else if ( F_32 ( V_23 -> V_20 , L_20 ) == 0 ) {
V_23 -> V_34 = V_51 ;
} else if ( F_32 ( V_23 -> V_20 , L_21 ) == 0 ) {
V_23 -> V_34 = V_52 ;
} else {
V_23 -> V_34 = V_53 ;
}
V_23 -> V_26 = V_32 -> V_25 ;
V_32 -> V_25 = V_23 ;
F_33 ( V_31 , & error ) ;
}
F_29 ( V_31 ) ;
F_30 ( V_30 ) ;
}
return V_32 ;
}
T_11 * F_34 ( const T_2 * V_22 ) {
T_11 * V_54 = NULL , * V_55 = NULL , * V_56 = NULL ;
T_2 * * V_57 , * * V_58 ;
V_58 = V_57 = F_35 ( V_22 , L_22 , 0 ) ;
while ( * V_58 != NULL ) {
V_55 = F_23 ( * V_58 ) ;
if ( V_55 != NULL ) {
if ( V_54 == NULL ) {
V_54 = V_55 ;
V_56 = V_55 ;
} else {
V_56 -> V_29 = V_55 ;
V_56 = V_55 ;
}
}
V_58 ++ ;
}
F_36 ( V_57 ) ;
return V_54 ;
}
T_10 * F_37 ( T_10 * V_54 ,
T_15 V_28 ) {
while ( V_54 != NULL ) {
if ( V_54 -> V_34 == V_28 ) {
return V_54 ;
}
V_54 = V_54 -> V_26 ;
}
return NULL ;
}
void F_38 ( T_16 * V_19 ) {
if ( V_19 == NULL )
return;
F_3 ( V_19 -> V_59 ) ;
F_3 ( V_19 -> V_60 ) ;
F_3 ( V_19 ) ;
}
T_17 * F_39 ( void ) {
T_17 * V_61 = F_24 ( T_17 , 1 ) ;
V_61 -> V_59 = V_61 -> V_60 = V_61 -> V_62 = NULL ;
V_61 -> V_63 = V_64 ;
V_61 -> V_65 = NULL ;
return V_61 ;
}
void F_40 ( T_17 * V_66 ) {
T_17 * V_67 = V_66 ;
while ( V_66 ) {
V_67 = V_66 -> V_65 ;
F_3 ( V_66 -> V_59 ) ;
F_3 ( V_66 -> V_60 ) ;
F_3 ( V_66 -> V_62 ) ;
F_3 ( V_66 ) ;
V_66 = V_67 ;
}
}
T_18 * F_41 ( void ) {
T_18 * V_61 = F_24 ( T_18 , 1 ) ;
V_61 -> V_68 = - 1 ;
V_61 -> V_69 = V_61 -> V_60 = NULL ;
V_61 -> V_70 = NULL ;
return V_61 ;
}
void F_42 ( T_18 * V_71 ) {
if ( V_71 == NULL )
return;
F_3 ( V_71 -> V_69 ) ;
F_3 ( V_71 -> V_60 ) ;
}
static void F_43 ( T_19 V_5 , T_19 T_20 V_72 ) {
F_38 ( ( T_16 * ) V_5 ) ;
}
void F_44 ( T_5 * V_73 ) {
if ( V_73 == NULL )
return;
F_3 ( V_73 -> V_59 ) ;
F_3 ( V_73 -> V_60 ) ;
F_3 ( V_73 -> V_74 ) ;
F_3 ( V_73 -> V_75 ) ;
F_3 ( V_73 -> V_76 ) ;
F_3 ( V_73 -> V_77 ) ;
if ( V_73 -> V_78 != NULL )
F_9 ( V_73 -> V_78 ) ;
if ( V_73 -> V_79 != NULL )
F_9 ( V_73 -> V_79 ) ;
if ( V_73 -> V_9 != NULL )
F_9 ( V_73 -> V_9 ) ;
F_45 ( V_73 -> V_80 , ( V_81 ) F_43 , NULL ) ;
}
static void F_46 ( T_19 V_82 , T_19 V_5 V_72 ) {
if ( V_82 != NULL )
F_44 ( ( T_5 * ) V_82 ) ;
}
void F_47 ( T_21 * V_73 ) {
F_45 ( V_73 , F_46 , NULL ) ;
F_48 ( V_73 ) ;
}
static T_6 F_49 ( T_22 V_83 , T_22 V_84 ) {
if ( ( ( const T_5 * ) V_83 ) -> V_85 == * ( ( const int * ) V_84 ) )
return 0 ;
return 1 ;
}
T_5 * F_50 ( T_21 * args , T_11 * V_22 ) {
T_10 * V_19 = NULL ;
T_5 * V_86 = NULL ;
T_16 * V_21 = NULL ;
T_21 * V_87 = NULL ;
int V_88 ;
T_23 V_89 = V_64 ;
if ( V_22 == NULL )
return V_86 ;
if ( F_32 ( V_22 -> V_24 , L_8 ) == 0 ) {
V_89 = V_90 ;
} else if ( F_32 ( V_22 -> V_24 , L_10 ) == 0 ) {
V_89 = V_91 ;
}
if ( V_89 == V_90 ) {
V_86 = F_6 ( T_5 , 1 ) ;
V_86 -> V_92 = V_93 ;
V_86 -> V_94 = TRUE ;
if ( ( V_19 = F_37 ( V_22 -> V_25 , V_35 ) )
== NULL ) {
F_44 ( V_86 ) ;
return NULL ;
}
if ( sscanf ( V_19 -> V_21 , L_23 , & ( V_86 -> V_85 ) ) != 1 ) {
F_44 ( V_86 ) ;
return NULL ;
}
if ( ( V_19 = F_37 ( V_22 -> V_25 , V_36 ) )
== NULL ) {
F_44 ( V_86 ) ;
return NULL ;
}
V_86 -> V_59 = F_4 ( V_19 -> V_21 ) ;
if ( strlen ( V_86 -> V_59 ) == 0 ) {
F_44 ( V_86 ) ;
return NULL ;
}
if ( ( V_19 = F_37 ( V_22 -> V_25 , V_37 ) )
== NULL ) {
F_44 ( V_86 ) ;
return NULL ;
}
V_86 -> V_60 = F_4 ( V_19 -> V_21 ) ;
if ( ( V_19 = F_37 ( V_22 -> V_25 , V_43 ) )
!= NULL ) {
V_86 -> V_74 = F_4 ( V_19 -> V_21 ) ;
}
if ( ( V_19 = F_37 ( V_22 -> V_25 , V_44 ) )
!= NULL ) {
V_86 -> V_95 = F_18 ( V_16 , V_19 -> V_21 , V_17 , ( V_18 ) 0 ) ;
}
if ( ( V_19 = F_37 ( V_22 -> V_25 , V_45 ) )
!= NULL ) {
V_86 -> V_75 = F_4 ( V_19 -> V_21 ) ;
}
if ( ( V_19 = F_37 ( V_22 -> V_25 , V_51 ) )
!= NULL ) {
V_86 -> V_76 = F_4 ( V_19 -> V_21 ) ;
}
if ( ( V_19 = F_37 ( V_22 -> V_25 , V_49 ) )
!= NULL ) {
V_86 -> V_96 = F_18 ( V_16 , V_19 -> V_21 , V_17 , ( V_18 ) 0 ) ;
}
if ( ( V_19 = F_37 ( V_22 -> V_25 , V_38 ) )
== NULL ) {
F_44 ( V_86 ) ;
return NULL ;
}
if ( F_32 ( V_19 -> V_21 , L_24 ) == 0 ) {
V_86 -> V_92 = V_10 ;
} else if ( F_32 ( V_19 -> V_21 , L_25 ) == 0 ) {
V_86 -> V_92 = V_11 ;
} else if ( F_32 ( V_19 -> V_21 , L_26 ) == 0 ) {
V_86 -> V_92 = V_12 ;
} else if ( F_32 ( V_19 -> V_21 , L_27 ) == 0 ) {
V_86 -> V_92 = V_13 ;
} else if ( F_32 ( V_19 -> V_21 , L_28 ) == 0 ) {
V_86 -> V_92 = V_14 ;
} else if ( F_32 ( V_19 -> V_21 , L_29 ) == 0 ) {
V_86 -> V_92 = V_15 ;
} else if ( F_32 ( V_19 -> V_21 , L_30 ) == 0 ) {
V_86 -> V_92 = V_97 ;
} else if ( F_32 ( V_19 -> V_21 , L_31 ) == 0 ) {
V_86 -> V_92 = V_98 ;
} else if ( F_32 ( V_19 -> V_21 , L_32 ) == 0 ) {
V_86 -> V_92 = V_99 ;
} else if ( F_32 ( V_19 -> V_21 , L_33 ) == 0 ) {
V_86 -> V_92 = V_100 ;
V_86 -> V_94 = FALSE ;
} else if ( F_32 ( V_19 -> V_21 , L_34 ) == 0 ) {
V_86 -> V_92 = V_101 ;
} else if ( F_32 ( V_19 -> V_21 , L_35 ) == 0 ) {
V_86 -> V_92 = V_102 ;
} else {
printf ( L_36 , V_19 -> V_21 ) ;
F_44 ( V_86 ) ;
return NULL ;
}
if ( ( V_19 = F_37 ( V_22 -> V_25 , V_50 ) )
!= NULL ) {
V_86 -> V_94 = F_18 ( V_16 , V_19 -> V_21 , V_17 , ( V_18 ) 0 ) ;
}
if ( ( V_19 = F_37 ( V_22 -> V_25 , V_42 ) )
!= NULL ) {
T_2 * V_103 = F_51 ( V_19 -> V_21 , - 1 , L_37 ) ;
if ( V_103 == NULL ) {
printf ( L_38 ,
V_19 -> V_21 ) ;
F_44 ( V_86 ) ;
return NULL ;
}
if ( ( V_86 -> V_78 = F_5 (
V_86 -> V_92 , V_19 -> V_21 ) ) == NULL ) {
printf ( L_38 ,
V_19 -> V_21 ) ;
F_44 ( V_86 ) ;
return NULL ;
}
if ( ( V_86 -> V_79 = F_5 (
V_86 -> V_92 , V_103 + 1 ) ) == NULL ) {
printf ( L_38 ,
V_19 -> V_21 ) ;
F_44 ( V_86 ) ;
return NULL ;
}
}
if ( ( V_19 = F_37 ( V_22 -> V_25 , V_40 ) )
!= NULL ) {
if ( V_86 -> V_92 != V_102 && V_86 -> V_92 != V_97 )
{
if ( ( V_86 -> V_9 = F_5 (
V_86 -> V_92 , V_19 -> V_21 ) ) == NULL ) {
printf ( L_39 , V_19 -> V_21 ) ;
}
}
}
} else if ( V_89 == V_91 ) {
if ( ( V_19 = F_37 ( V_22 -> V_25 , V_39 ) )
== NULL ) {
printf ( L_40 ) ;
return NULL ;
}
if ( sscanf ( V_19 -> V_21 , L_23 , & V_88 ) != 1 ) {
printf ( L_41 ) ;
return NULL ;
}
;
if ( ( V_87 = F_52 ( args , & V_88 , F_49 ) )
== NULL ) {
printf ( L_42 , V_88 ) ;
return NULL ;
}
V_21 = F_6 ( T_16 , 1 ) ;
V_21 -> V_85 = V_88 ;
if ( ( V_19 = F_37 ( V_22 -> V_25 , V_41 ) )
== NULL ) {
F_38 ( V_21 ) ;
return NULL ;
}
V_21 -> V_59 = F_4 ( V_19 -> V_21 ) ;
if ( ( V_19 = F_37 ( V_22 -> V_25 , V_37 ) )
== NULL ) {
F_38 ( V_21 ) ;
return NULL ;
}
V_21 -> V_60 = F_4 ( V_19 -> V_21 ) ;
if ( ( V_19 = F_37 ( V_22 -> V_25 , V_48 ) )
!= NULL ) {
V_21 -> V_104 = F_4 ( V_19 -> V_21 ) ;
}
if ( ( V_19 = F_37 ( V_22 -> V_25 , V_40 ) )
!= NULL ) {
V_21 -> V_105 = F_18 ( V_16 , V_19 -> V_21 , V_17 , ( V_18 ) 0 ) ;
}
if ( ( V_19 = F_37 ( V_22 -> V_25 , V_47 ) )
!= NULL ) {
V_21 -> V_106 = F_18 ( V_16 , V_19 -> V_21 , V_17 , ( V_18 ) 0 ) ;
}
( ( T_5 * ) V_87 -> V_5 ) -> V_80 = F_53 (
( ( T_5 * ) V_87 -> V_5 ) -> V_80 , V_21 ) ;
return NULL ;
}
return V_86 ;
}
T_21 * F_54 ( T_11 * V_107 ) {
T_21 * args = NULL ;
while ( V_107 ) {
T_5 * V_108 = NULL ;
if ( ( V_108 = F_50 ( args , V_107 ) ) != NULL )
args = F_53 ( args , ( T_19 ) V_108 ) ;
V_107 = V_107 -> V_29 ;
}
return args ;
}
int F_55 ( T_11 * V_22 ,
T_17 * * V_109 ) {
T_10 * V_19 = NULL ;
T_23 V_89 = V_64 ;
* V_109 = NULL ;
if ( V_22 == NULL )
return - 1 ;
if ( F_32 ( V_22 -> V_24 , L_43 ) == 0 ) {
V_89 = V_110 ;
} else if ( F_32 ( V_22 -> V_24 , L_44 ) == 0 ) {
V_89 = V_111 ;
}
if ( V_89 == V_64 )
return - 1 ;
* V_109 = F_39 () ;
( * V_109 ) -> V_63 = V_89 ;
if ( ( V_19 = F_37 ( V_22 -> V_25 , V_41 ) )
== NULL && V_89 == V_110 ) {
printf ( L_45 ) ;
F_40 ( * V_109 ) ;
return - 1 ;
}
if ( V_19 != NULL )
( * V_109 ) -> V_59 = F_4 ( V_19 -> V_21 ) ;
if ( ( V_19 = F_37 ( V_22 -> V_25 , V_37 ) )
== NULL && V_89 == V_110 ) {
printf ( L_46 ) ;
F_40 ( * V_109 ) ;
return - 1 ;
}
if ( V_19 != NULL )
( * V_109 ) -> V_60 = F_4 ( V_19 -> V_21 ) ;
if ( ( V_19 = F_37 ( V_22 -> V_25 , V_52 ) )
!= NULL ) {
( * V_109 ) -> V_62 = F_4 ( V_19 -> V_21 ) ;
}
return 1 ;
}
int F_56 ( T_11 * V_107 ,
T_17 * * V_112 ) {
T_17 * V_113 = NULL , * V_114 = NULL ;
while ( V_107 ) {
T_17 * V_109 ;
if ( F_55 ( V_107 , & V_109 ) >= 0 && V_109 != NULL ) {
if ( V_113 == NULL ) {
V_113 = V_114 = V_109 ;
} else {
V_114 -> V_65 = V_109 ;
V_114 = V_109 ;
}
}
V_107 = V_107 -> V_29 ;
}
* V_112 = V_113 ;
return 1 ;
}
int F_57 ( T_11 * V_22 , T_18 * * V_115 ) {
T_10 * V_19 = NULL ;
T_23 V_89 = V_64 ;
* V_115 = NULL ;
if ( V_22 == NULL )
return - 1 ;
if ( F_32 ( V_22 -> V_24 , L_47 ) == 0 ) {
V_89 = V_116 ;
}
if ( V_89 == V_64 )
return - 1 ;
* V_115 = F_41 () ;
if ( ( V_19 = F_37 ( V_22 -> V_25 , V_35 ) )
== NULL ) {
printf ( L_48 ) ;
F_42 ( * V_115 ) ;
return - 1 ;
}
if ( sscanf ( V_19 -> V_21 , L_23 , & ( ( * V_115 ) -> V_68 ) ) != 1 ) {
printf ( L_49 ) ;
F_42 ( * V_115 ) ;
return - 1 ;
}
if ( ( V_19 = F_37 ( V_22 -> V_25 , V_46 ) )
== NULL ) {
printf ( L_50 ) ;
F_42 ( * V_115 ) ;
return - 1 ;
}
( * V_115 ) -> V_69 = F_4 ( V_19 -> V_21 ) ;
if ( ( V_19 = F_37 ( V_22 -> V_25 , V_37 ) )
== NULL ) {
printf ( L_51 ) ;
F_42 ( * V_115 ) ;
return - 1 ;
}
( * V_115 ) -> V_60 = F_4 ( V_19 -> V_21 ) ;
return 1 ;
}
int F_58 ( T_11 * V_107 , T_18 * * V_117 ) {
T_18 * V_118 = NULL , * V_119 = NULL ;
while ( V_107 ) {
T_18 * V_115 ;
if ( F_57 ( V_107 , & V_115 ) >= 0 && V_115 != NULL ) {
if ( V_118 == NULL ) {
V_118 = V_119 = V_115 ;
} else {
V_119 -> V_70 = V_115 ;
V_119 = V_115 ;
}
}
V_107 = V_107 -> V_29 ;
}
* V_117 = V_118 ;
return 1 ;
}

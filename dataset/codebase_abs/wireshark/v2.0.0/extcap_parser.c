void F_1 ( T_1 * V_1 ) {
T_2 * V_2 = F_2 ( V_1 ) ;
printf ( L_1 , V_2 ) ;
F_3 ( V_2 ) ;
}
T_2 * F_2 ( T_1 * V_1 ) {
T_2 * V_2 = F_4 ( T_2 , 32 ) ;
if ( V_1 == NULL ) {
F_5 ( V_2 , 32 , L_2 ) ;
return V_2 ;
}
switch ( V_1 -> V_3 ) {
case V_4 :
F_5 ( V_2 , 32 , L_3 , V_1 -> V_5 . V_6 ) ;
break;
case V_7 :
F_5 ( V_2 , 32 , L_4 , V_1 -> V_5 . V_8 ) ;
break;
case V_9 :
F_5 ( V_2 , 32 , L_5 , V_1 -> V_5 . V_10 ) ;
break;
case V_11 :
F_5 ( V_2 , 32 , L_6 , V_1 -> V_5 . V_12 ) ;
break;
case V_13 :
F_5 ( V_2 , 32 , L_1 ,
V_1 -> V_5 . V_14 ? L_7 : L_8 ) ;
break;
case V_15 :
case V_16 :
F_3 ( V_2 ) ;
V_2 = F_6 ( V_1 -> V_5 . V_17 ) ;
break;
default:
F_5 ( V_2 , 32 , L_9 ) ;
break;
}
return V_2 ;
}
T_1 * F_7 ( T_3 V_3 ,
const T_2 * V_18 ) {
T_1 * V_19 = F_4 ( T_1 , 1 ) ;
T_4 V_20 = FALSE ;
long double V_21 ;
switch ( V_3 ) {
case V_4 :
if ( sscanf ( V_18 , L_10 , & V_21 ) == 1 ) {
V_19 -> V_5 . V_6 = ( int ) V_21 ;
V_20 = TRUE ;
break;
}
break;
case V_7 :
if ( sscanf ( V_18 , L_10 , & V_21 ) == 1 ) {
V_19 -> V_5 . V_8 = ( unsigned int ) V_21 ;
V_20 = TRUE ;
break;
}
break;
case V_9 :
if ( sscanf ( V_18 , L_10 , & V_21 ) == 1 ) {
V_19 -> V_5 . V_10 = ( long ) V_21 ;
V_20 = TRUE ;
break;
}
break;
case V_11 :
if ( sscanf ( V_18 , L_10 , & V_21 ) == 1 ) {
V_19 -> V_5 . V_12 = ( double ) V_21 ;
V_20 = TRUE ;
break;
}
break;
case V_13 :
case V_22 :
if ( V_18 [ 0 ] == 't' || V_18 [ 0 ] == 'T' || V_18 [ 0 ] == '1' ) {
V_19 -> V_5 . V_14 = 1 ;
} else {
V_19 -> V_5 . V_14 = 0 ;
}
V_20 = TRUE ;
break;
case V_15 :
case V_16 :
V_19 -> V_5 . V_17 = F_6 ( V_18 ) ;
V_20 = TRUE ;
break;
default:
break;
}
if ( ! V_20 ) {
F_3 ( V_19 ) ;
return NULL ;
}
V_19 -> V_3 = V_3 ;
V_19 -> V_23 = TRUE ;
return V_19 ;
}
T_4 F_8 ( T_5 * V_24 , T_1 * V_25 ) {
T_4 V_26 = FALSE ;
if ( V_24 -> V_27 == NULL )
return V_26 ;
switch ( V_24 -> V_28 ) {
case V_4 :
if ( F_9 ( V_25 )
== F_9 ( V_24 -> V_27 ) )
V_26 = TRUE ;
break;
case V_7 :
if ( F_10 ( V_25 )
== F_10 ( V_24 -> V_27 ) )
V_26 = TRUE ;
break;
case V_9 :
if ( F_11 ( V_25 )
== F_11 ( V_24 -> V_27 ) )
V_26 = TRUE ;
break;
case V_11 :
if ( F_12 ( V_25 )
== F_12 ( V_24 -> V_27 ) )
V_26 = TRUE ;
break;
case V_13 :
case V_22 :
if ( F_13 ( V_25 )
== F_13 ( V_24 -> V_27 ) )
V_26 = TRUE ;
break;
case V_15 :
if ( strcmp ( F_14 ( V_25 ) ,
F_14 ( V_24 -> V_27 ) ) == 0 )
V_26 = TRUE ;
break;
default:
break;
}
return V_26 ;
}
void F_15 ( T_1 * V_1 ) {
if ( V_1 -> V_3 == V_15
|| V_1 -> V_3 == V_16 )
F_3 ( V_1 -> V_5 . V_17 ) ;
F_3 ( V_1 ) ;
}
int F_9 ( T_1 * V_1 ) {
if ( V_1 == NULL )
return ( int ) 0 ;
return V_1 -> V_5 . V_6 ;
}
unsigned int F_10 ( T_1 * V_1 ) {
if ( V_1 == NULL )
return ( unsigned int ) 0 ;
return V_1 -> V_5 . V_8 ;
}
long F_11 ( T_1 * V_1 ) {
if ( V_1 == NULL )
return ( long ) 0 ;
return V_1 -> V_5 . V_10 ;
}
double F_12 ( T_1 * V_1 ) {
if ( V_1 == NULL )
return ( double ) 0 ;
return V_1 -> V_5 . V_12 ;
}
T_4 F_13 ( T_1 * V_1 ) {
if ( V_1 == NULL )
return FALSE ;
return V_1 -> V_5 . V_14 ;
}
T_2 * F_14 ( T_1 * V_1 ) {
return V_1 -> V_5 . V_17 ;
}
void F_16 ( T_6 * V_29 ) {
if ( V_29 == NULL )
return;
if ( V_29 -> V_30 != NULL )
F_3 ( V_29 -> V_30 ) ;
if ( V_29 -> V_31 != NULL )
F_3 ( V_29 -> V_31 ) ;
F_3 ( V_29 ) ;
}
void F_17 ( T_7 * V_32 ) {
T_6 * V_33 ;
if ( V_32 == NULL )
return;
if ( V_32 -> V_34 != NULL )
F_3 ( V_32 -> V_34 ) ;
while ( V_32 -> V_35 != NULL ) {
V_33 = V_32 -> V_35 ;
V_32 -> V_35 = V_33 -> V_36 ;
F_16 ( V_33 ) ;
}
}
void F_18 ( T_7 * V_37 ) {
T_7 * V_38 ;
while ( V_37 != NULL ) {
V_38 = V_37 -> V_39 ;
F_17 ( V_37 ) ;
V_37 = V_38 ;
}
}
T_7 * F_19 ( const T_2 * V_32 ) {
T_2 * V_40 , * V_41 , * V_42 ;
T_6 * V_33 = NULL ;
T_7 * V_43 = F_4 ( T_7 , 1 ) ;
V_43 -> V_34 = NULL ;
V_43 -> V_39 = NULL ;
V_43 -> V_35 = NULL ;
if ( ( V_40 = F_20 ( V_32 , - 1 , L_9 ) ) == NULL ) {
F_17 ( V_43 ) ;
return NULL ;
}
V_43 -> V_34 = F_21 ( V_32 , V_40 - V_32 ) ;
if ( ( V_40 = F_20 ( V_32 , - 1 , L_11 ) ) == NULL ) {
F_17 ( V_43 ) ;
return NULL ;
}
while ( V_40 != NULL ) {
if ( ( V_41 = F_20 ( V_40 , - 1 , L_12 ) ) == NULL ) {
F_17 ( V_43 ) ;
return NULL ;
}
if ( ( V_42 = F_20 ( V_40 , - 1 , L_13 ) ) == NULL ) {
F_17 ( V_43 ) ;
return NULL ;
}
V_40 ++ ;
V_41 -- ;
if ( V_40 >= V_42 || V_41 <= V_42 ) {
F_17 ( V_43 ) ;
return NULL ;
}
V_33 = F_4 ( T_6 , 1 ) ;
V_33 -> V_30 = F_21 ( V_40 , V_42 - V_40 ) ;
V_33 -> V_31 = F_21 ( V_42 + 1 , V_41 - V_42 ) ;
if ( F_22 ( V_33 -> V_30 , L_14 ) == 0 ) {
V_33 -> V_44 = V_45 ;
} else if ( F_22 ( V_33 -> V_30 , L_15 ) == 0 ) {
V_33 -> V_44 = V_46 ;
} else if ( F_22 ( V_33 -> V_30 , L_16 ) == 0 ) {
V_33 -> V_44 = V_47 ;
} else if ( F_22 ( V_33 -> V_30 , L_17 ) == 0 ) {
V_33 -> V_44 = V_48 ;
} else if ( F_22 ( V_33 -> V_30 , L_18 ) == 0 ) {
V_33 -> V_44 = V_49 ;
} else if ( F_22 ( V_33 -> V_30 , L_19 ) == 0 ) {
V_33 -> V_44 = V_50 ;
} else if ( F_22 ( V_33 -> V_30 , L_20 ) == 0 ) {
V_33 -> V_44 = V_51 ;
} else if ( F_22 ( V_33 -> V_30 , L_21 ) == 0 ) {
V_33 -> V_44 = V_52 ;
} else if ( F_22 ( V_33 -> V_30 , L_22 ) == 0 ) {
V_33 -> V_44 = V_53 ;
} else if ( F_22 ( V_33 -> V_30 , L_23 ) == 0 ) {
V_33 -> V_44 = V_54 ;
} else if ( F_22 ( V_33 -> V_30 , L_24 ) == 0 ) {
V_33 -> V_44 = V_55 ;
} else if ( F_22 ( V_33 -> V_30 , L_25 ) == 0 ) {
V_33 -> V_44 = V_56 ;
} else if ( F_22 ( V_33 -> V_30 , L_26 ) == 0 ) {
V_33 -> V_44 = V_57 ;
} else {
V_33 -> V_44 = V_58 ;
}
V_33 -> V_36 = V_43 -> V_35 ;
V_43 -> V_35 = V_33 ;
V_40 = V_41 + 1 ;
if ( ( V_59 ) ( V_40 - V_32 ) > strlen ( V_32 ) )
break;
V_40 = F_20 ( V_40 , - 1 , L_11 ) ;
}
return V_43 ;
}
T_7 * F_23 ( const T_2 * V_32 ) {
T_7 * V_60 = NULL , * V_61 = NULL , * V_62 = NULL ;
T_2 * * V_63 , * * V_64 ;
V_64 = V_63 = F_24 ( V_32 , L_27 , 0 ) ;
while ( * V_64 != NULL ) {
V_61 = F_19 ( * V_64 ) ;
if ( V_61 != NULL ) {
if ( V_60 == NULL ) {
V_60 = V_61 ;
V_62 = V_61 ;
} else {
V_62 -> V_39 = V_61 ;
V_62 = V_61 ;
}
}
V_64 ++ ;
}
F_25 ( V_63 ) ;
return V_60 ;
}
T_6 * F_26 ( T_6 * V_60 ,
T_8 V_38 ) {
while ( V_60 != NULL ) {
if ( V_60 -> V_44 == V_38 ) {
return V_60 ;
}
V_60 = V_60 -> V_36 ;
}
return NULL ;
}
void F_27 ( T_9 * V_29 ) {
if ( V_29 == NULL )
return;
if ( V_29 -> V_65 != NULL )
F_3 ( V_29 -> V_65 ) ;
if ( V_29 -> V_66 != NULL )
F_3 ( V_29 -> V_66 ) ;
F_3 ( V_29 ) ;
}
T_10 * F_28 ( void ) {
T_10 * V_67 = F_4 ( T_10 , 1 ) ;
V_67 -> V_65 = V_67 -> V_66 = NULL ;
V_67 -> V_68 = NULL ;
return V_67 ;
}
void F_29 ( T_10 * V_69 ) {
if ( V_69 == NULL )
return;
if ( V_69 -> V_65 != NULL )
F_3 ( V_69 -> V_65 ) ;
if ( V_69 -> V_66 != NULL )
F_3 ( V_69 -> V_66 ) ;
}
T_11 * F_30 ( void ) {
T_11 * V_67 = F_4 ( T_11 , 1 ) ;
V_67 -> V_70 = - 1 ;
V_67 -> V_71 = V_67 -> V_66 = NULL ;
V_67 -> V_72 = NULL ;
return V_67 ;
}
void F_31 ( T_11 * V_73 ) {
if ( V_73 == NULL )
return;
if ( V_73 -> V_71 != NULL )
F_3 ( V_73 -> V_71 ) ;
if ( V_73 -> V_66 != NULL )
F_3 ( V_73 -> V_66 ) ;
}
T_5 * F_32 ( void ) {
T_5 * V_67 = F_4 ( T_5 , 1 ) ;
V_67 -> V_65 = NULL ;
V_67 -> V_66 = NULL ;
V_67 -> V_74 = NULL ;
V_67 -> V_28 = V_75 ;
V_67 -> V_76 = NULL ;
V_67 -> V_77 = NULL ;
V_67 -> V_27 = NULL ;
V_67 -> V_78 = FALSE ;
V_67 -> V_79 = NULL ;
return V_67 ;
}
static void F_33 ( T_12 V_18 , T_12 T_13 V_80 ) {
F_27 ( ( T_9 * ) V_18 ) ;
}
void F_34 ( T_5 * V_81 ) {
if ( V_81 == NULL )
return;
if ( V_81 -> V_65 != NULL )
F_3 ( V_81 -> V_65 ) ;
if ( V_81 -> V_66 != NULL )
F_3 ( V_81 -> V_66 ) ;
if ( V_81 -> V_74 != NULL )
F_3 ( V_81 -> V_74 ) ;
if ( V_81 -> V_76 != NULL )
F_15 ( V_81 -> V_76 ) ;
if ( V_81 -> V_77 != NULL )
F_15 ( V_81 -> V_77 ) ;
if ( V_81 -> V_27 != NULL )
F_15 ( V_81 -> V_27 ) ;
F_35 ( V_81 -> V_79 , ( V_82 ) F_33 , NULL ) ;
}
static void F_36 ( T_12 V_83 , T_12 V_18 V_80 ) {
if ( V_83 != NULL )
F_34 ( ( T_5 * ) V_83 ) ;
}
void F_37 ( T_14 * V_81 ) {
F_35 ( V_81 , F_36 , NULL ) ;
F_38 ( V_81 ) ;
}
static T_15 F_39 ( T_16 V_84 , T_16 V_85 ) {
if ( ( ( const T_5 * ) V_84 ) -> V_86 == * ( ( const int * ) V_85 ) )
return 0 ;
return 1 ;
}
T_5 * F_40 ( T_14 * args , T_7 * V_32 ) {
T_6 * V_29 = NULL ;
T_5 * V_87 = NULL ;
T_9 * V_31 = NULL ;
T_14 * V_88 = NULL ;
int V_89 ;
T_17 V_90 = V_91 ;
if ( V_32 == NULL )
return V_87 ;
if ( F_22 ( V_32 -> V_34 , L_18 ) == 0 ) {
V_90 = V_92 ;
} else if ( F_22 ( V_32 -> V_34 , L_20 ) == 0 ) {
V_90 = V_93 ;
}
if ( V_90 == V_92 ) {
V_87 = F_32 () ;
if ( ( V_29 = F_26 ( V_32 -> V_35 , V_45 ) )
== NULL ) {
F_34 ( V_87 ) ;
return NULL ;
}
if ( sscanf ( V_29 -> V_31 , L_3 , & ( V_87 -> V_86 ) ) != 1 ) {
F_34 ( V_87 ) ;
return NULL ;
}
if ( ( V_29 = F_26 ( V_32 -> V_35 , V_46 ) )
== NULL ) {
F_34 ( V_87 ) ;
return NULL ;
}
V_87 -> V_65 = F_6 ( V_29 -> V_31 ) ;
if ( strlen ( V_87 -> V_65 ) == 0 ) {
F_34 ( V_87 ) ;
return NULL ;
}
if ( ( V_29 = F_26 ( V_32 -> V_35 , V_47 ) )
== NULL ) {
F_34 ( V_87 ) ;
return NULL ;
}
V_87 -> V_66 = F_6 ( V_29 -> V_31 ) ;
if ( ( V_29 = F_26 ( V_32 -> V_35 , V_53 ) )
!= NULL ) {
V_87 -> V_74 = F_6 ( V_29 -> V_31 ) ;
}
if ( ( V_29 = F_26 ( V_32 -> V_35 , V_54 ) )
!= NULL ) {
V_87 -> V_78 = ( V_29 -> V_31 [ 0 ] == 't' || V_29 -> V_31 [ 0 ] == 'T' ) ;
}
if ( ( V_29 = F_26 ( V_32 -> V_35 , V_48 ) )
== NULL ) {
F_34 ( V_87 ) ;
return NULL ;
}
if ( F_22 ( V_29 -> V_31 , L_28 ) == 0 ) {
V_87 -> V_28 = V_4 ;
} else if ( F_22 ( V_29 -> V_31 , L_29 ) == 0 ) {
V_87 -> V_28 = V_7 ;
} else if ( F_22 ( V_29 -> V_31 , L_30 ) == 0 ) {
V_87 -> V_28 = V_9 ;
} else if ( F_22 ( V_29 -> V_31 , L_31 ) == 0 ) {
V_87 -> V_28 = V_11 ;
} else if ( F_22 ( V_29 -> V_31 , L_32 ) == 0 ) {
V_87 -> V_28 = V_13 ;
} else if ( F_22 ( V_29 -> V_31 , L_33 ) == 0 ) {
V_87 -> V_28 = V_22 ;
} else if ( F_22 ( V_29 -> V_31 , L_34 ) == 0 ) {
V_87 -> V_28 = V_94 ;
} else if ( F_22 ( V_29 -> V_31 , L_35 ) == 0 ) {
V_87 -> V_28 = V_95 ;
} else if ( F_22 ( V_29 -> V_31 , L_36 ) == 0 ) {
V_87 -> V_28 = V_15 ;
} else if ( F_22 ( V_29 -> V_31 , L_37 ) == 0 ) {
V_87 -> V_28 = V_16 ;
} else if ( F_22 ( V_29 -> V_31 , L_38 ) == 0 ) {
V_87 -> V_28 = V_96 ;
} else {
printf ( L_39 , V_29 -> V_31 ) ;
F_34 ( V_87 ) ;
return NULL ;
}
if ( ( V_29 = F_26 ( V_32 -> V_35 , V_52 ) )
!= NULL ) {
T_2 * V_97 = F_20 ( V_29 -> V_31 , - 1 , L_40 ) ;
if ( V_97 == NULL ) {
printf ( L_41 ,
V_29 -> V_31 ) ;
F_34 ( V_87 ) ;
return NULL ;
}
if ( ( V_87 -> V_76 = F_7 (
V_87 -> V_28 , V_29 -> V_31 ) ) == NULL ) {
printf ( L_41 ,
V_29 -> V_31 ) ;
F_34 ( V_87 ) ;
return NULL ;
}
if ( ( V_87 -> V_77 = F_7 (
V_87 -> V_28 , V_97 + 1 ) ) == NULL ) {
printf ( L_41 ,
V_29 -> V_31 ) ;
F_34 ( V_87 ) ;
return NULL ;
}
}
if ( ( V_29 = F_26 ( V_32 -> V_35 , V_50 ) )
!= NULL ) {
if ( ( V_87 -> V_27 = F_7 (
V_87 -> V_28 , V_29 -> V_31 ) ) == NULL ) {
printf ( L_42 , V_29 -> V_31 ) ;
}
}
} else if ( V_90 == V_93 ) {
if ( ( V_29 = F_26 ( V_32 -> V_35 , V_49 ) )
== NULL ) {
printf ( L_43 ) ;
return NULL ;
}
if ( sscanf ( V_29 -> V_31 , L_3 , & V_89 ) != 1 ) {
printf ( L_44 ) ;
return NULL ;
}
;
if ( ( V_88 = F_41 ( args , & V_89 , F_39 ) )
== NULL ) {
printf ( L_45 , V_89 ) ;
return NULL ;
}
V_31 = F_4 ( T_9 , 1 ) ;
V_31 -> V_66 = NULL ;
V_31 -> V_65 = NULL ;
V_31 -> V_98 = FALSE ;
V_31 -> V_99 = FALSE ;
V_31 -> V_86 = V_89 ;
V_31 -> V_100 = NULL ;
if ( ( V_29 = F_26 ( V_32 -> V_35 , V_51 ) )
== NULL ) {
F_27 ( V_31 ) ;
return NULL ;
}
V_31 -> V_65 = F_6 ( V_29 -> V_31 ) ;
if ( ( V_29 = F_26 ( V_32 -> V_35 , V_47 ) )
== NULL ) {
F_27 ( V_31 ) ;
return NULL ;
}
V_31 -> V_66 = F_6 ( V_29 -> V_31 ) ;
if ( ( V_29 = F_26 ( V_32 -> V_35 , V_57 ) )
!= NULL ) {
V_31 -> V_100 = F_6 ( V_29 -> V_31 ) ;
}
if ( ( V_29 = F_26 ( V_32 -> V_35 , V_50 ) )
!= NULL ) {
V_31 -> V_99 = ( V_29 -> V_31 [ 0 ] == 't' || V_29 -> V_31 [ 0 ] == 'T' ) ;
}
if ( ( V_29 = F_26 ( V_32 -> V_35 , V_56 ) )
!= NULL ) {
V_31 -> V_98 = ( V_29 -> V_31 [ 0 ] == 't' || V_29 -> V_31 [ 0 ] == 'T' ) ;
}
( ( T_5 * ) V_88 -> V_18 ) -> V_79 = F_42 (
( ( T_5 * ) V_88 -> V_18 ) -> V_79 , V_31 ) ;
return NULL ;
}
return V_87 ;
}
T_14 * F_43 ( T_7 * V_101 ) {
T_14 * args = NULL ;
while ( V_101 ) {
T_5 * V_102 = NULL ;
if ( ( V_102 = F_40 ( args , V_101 ) ) != NULL )
args = F_42 ( args , ( T_12 ) V_102 ) ;
V_101 = V_101 -> V_39 ;
}
return args ;
}
int F_44 ( T_7 * V_32 ,
T_10 * * V_103 ) {
T_6 * V_29 = NULL ;
T_17 V_90 = V_91 ;
* V_103 = NULL ;
if ( V_32 == NULL )
return - 1 ;
if ( F_22 ( V_32 -> V_34 , L_46 ) == 0 ) {
V_90 = V_104 ;
}
if ( V_90 == V_91 )
return - 1 ;
* V_103 = F_28 () ;
if ( ( V_29 = F_26 ( V_32 -> V_35 , V_51 ) )
== NULL ) {
printf ( L_47 ) ;
F_29 ( * V_103 ) ;
return - 1 ;
}
( * V_103 ) -> V_65 = F_6 ( V_29 -> V_31 ) ;
if ( ( V_29 = F_26 ( V_32 -> V_35 , V_47 ) )
== NULL ) {
printf ( L_48 ) ;
F_29 ( * V_103 ) ;
return - 1 ;
}
( * V_103 ) -> V_66 = F_6 ( V_29 -> V_31 ) ;
return 1 ;
}
int F_45 ( T_7 * V_101 ,
T_10 * * V_105 ) {
T_10 * V_106 = NULL , * V_107 = NULL ;
while ( V_101 ) {
T_10 * V_103 ;
if ( F_44 ( V_101 , & V_103 ) >= 0 && V_103 != NULL ) {
if ( V_106 == NULL ) {
V_106 = V_107 = V_103 ;
} else {
V_107 -> V_68 = V_103 ;
V_107 = V_103 ;
}
}
V_101 = V_101 -> V_39 ;
}
* V_105 = V_106 ;
return 1 ;
}
int F_46 ( T_7 * V_32 , T_11 * * V_108 ) {
T_6 * V_29 = NULL ;
T_17 V_90 = V_91 ;
* V_108 = NULL ;
if ( V_32 == NULL )
return - 1 ;
if ( F_22 ( V_32 -> V_34 , L_49 ) == 0 ) {
V_90 = V_109 ;
}
if ( V_90 == V_91 )
return - 1 ;
* V_108 = F_30 () ;
if ( ( V_29 = F_26 ( V_32 -> V_35 , V_45 ) )
== NULL ) {
printf ( L_50 ) ;
F_31 ( * V_108 ) ;
return - 1 ;
}
if ( sscanf ( V_29 -> V_31 , L_3 , & ( ( * V_108 ) -> V_70 ) ) != 1 ) {
printf ( L_51 ) ;
F_31 ( * V_108 ) ;
return - 1 ;
}
if ( ( V_29 = F_26 ( V_32 -> V_35 , V_55 ) )
== NULL ) {
printf ( L_52 ) ;
F_31 ( * V_108 ) ;
return - 1 ;
}
( * V_108 ) -> V_71 = F_6 ( V_29 -> V_31 ) ;
if ( ( V_29 = F_26 ( V_32 -> V_35 , V_47 ) )
== NULL ) {
printf ( L_53 ) ;
F_31 ( * V_108 ) ;
return - 1 ;
}
( * V_108 ) -> V_66 = F_6 ( V_29 -> V_31 ) ;
return 1 ;
}
int F_47 ( T_7 * V_101 , T_11 * * V_110 ) {
T_11 * V_111 = NULL , * V_112 = NULL ;
while ( V_101 ) {
T_11 * V_108 ;
if ( F_46 ( V_101 , & V_108 ) >= 0 && V_108 != NULL ) {
if ( V_111 == NULL ) {
V_111 = V_112 = V_108 ;
} else {
V_112 -> V_72 = V_108 ;
V_112 = V_108 ;
}
}
V_101 = V_101 -> V_39 ;
}
* V_110 = V_111 ;
return 1 ;
}

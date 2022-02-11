void
F_1 ( T_1 * V_1 )
{
V_1 -> V_2 = F_2 ( FALSE , FALSE , sizeof( V_3 ) ) ;
V_1 -> V_4 = F_2 ( FALSE , FALSE , sizeof( V_5 ) ) ;
V_1 -> V_6 = 0 ;
V_1 -> V_7 . V_8 = NULL ;
V_1 -> V_7 . V_9 = NULL ;
V_1 -> V_7 . V_10 = NULL ;
V_1 -> V_7 . V_11 = FALSE ;
V_1 -> V_7 . V_12 = V_13 ;
V_1 -> V_7 . V_14 = - 1 ;
V_1 -> V_7 . V_15 = TRUE ;
V_1 -> V_7 . V_16 = V_17 ;
#ifdef F_3
V_1 -> V_7 . V_18 = NULL ;
V_1 -> V_7 . V_19 = NULL ;
V_1 -> V_7 . V_20 = NULL ;
V_1 -> V_7 . V_21 = V_22 ;
#endif
#ifdef F_4
V_1 -> V_7 . V_23 = V_24 ;
#endif
V_1 -> V_7 . V_25 = FALSE ;
#ifdef F_5
V_1 -> V_7 . V_26 = V_27 ;
V_1 -> V_7 . V_28 = NULL ;
V_1 -> V_7 . V_29 = NULL ;
V_1 -> V_7 . V_30 = V_31 ;
V_1 -> V_7 . V_32 = NULL ;
V_1 -> V_7 . V_33 = NULL ;
V_1 -> V_7 . V_34 = FALSE ;
V_1 -> V_7 . V_35 = TRUE ;
V_1 -> V_7 . V_36 = FALSE ;
#endif
#ifdef F_6
V_1 -> V_7 . V_37 = V_38 ;
V_1 -> V_7 . V_39 = 0 ;
#endif
V_1 -> V_40 = FALSE ;
V_1 -> V_41 = NULL ;
V_1 -> V_42 = FALSE ;
#ifdef F_7
V_1 -> V_43 = TRUE ;
#else
V_1 -> V_43 = FALSE ;
#endif
V_1 -> V_44 = TRUE ;
V_1 -> V_45 = TRUE ;
V_1 -> V_46 = getenv ( L_1 ) ? TRUE : FALSE ;
V_1 -> V_47 = FALSE ;
V_1 -> V_48 = NULL ;
V_1 -> V_49 = FALSE ;
V_1 -> V_50 = FALSE ;
V_1 -> V_51 = 60 ;
V_1 -> V_52 = FALSE ;
V_1 -> V_53 = V_54 ;
V_1 -> V_55 = FALSE ;
V_1 -> V_56 = 1 ;
V_1 -> V_57 = FALSE ;
V_1 -> V_58 = 0 ;
V_1 -> V_59 = FALSE ;
V_1 -> V_60 = 1000 ;
V_1 -> V_61 = FALSE ;
V_1 -> V_62 = 60 ;
V_1 -> V_63 = NULL ;
V_1 -> V_64 = FALSE ;
V_1 -> V_65 = FALSE ;
}
void
F_8 ( const char * V_66 , T_2 V_67 , T_1 * V_1 ) {
T_3 V_68 ;
F_9 ( V_66 , V_67 , L_2 ) ;
for ( V_68 = 0 ; V_68 < V_1 -> V_2 -> V_69 ; V_68 ++ ) {
V_3 V_70 ;
V_70 = F_10 ( V_1 -> V_2 , V_3 , V_68 ) ;
F_9 ( V_66 , V_67 , L_3 , V_68 , V_70 . V_8 ? V_70 . V_8 : L_4 ) ;
F_9 ( V_66 , V_67 , L_5 , V_68 , V_70 . V_9 ? V_70 . V_9 : L_4 ) ;
F_9 ( V_66 , V_67 , L_6 , V_68 , V_70 . V_71 ? V_70 . V_71 : L_4 ) ;
F_9 ( V_66 , V_67 , L_7 , V_68 , V_70 . V_10 ? V_70 . V_10 : L_4 ) ;
F_9 ( V_66 , V_67 , L_8 , V_68 , V_70 . V_11 , V_70 . V_12 ) ;
F_9 ( V_66 , V_67 , L_9 , V_68 , V_70 . V_14 ) ;
F_9 ( V_66 , V_67 , L_10 , V_68 , V_70 . V_15 ? L_11 : L_12 ) ;
#ifdef F_3
F_9 ( V_66 , V_67 , L_13 , V_68 , V_70 . V_18 ? V_70 . V_18 : L_4 ) ;
F_9 ( V_66 , V_67 , L_14 , V_68 , V_70 . V_19 ? V_70 . V_19 : L_4 ) ;
F_9 ( V_66 , V_67 , L_15 , V_68 , V_70 . V_21 ) ;
#endif
#ifdef F_4
F_9 ( V_66 , V_67 , L_16 , V_68 , V_70 . V_23 ) ;
#endif
F_9 ( V_66 , V_67 , L_17 , V_68 , V_70 . V_25 ? L_11 : L_12 ) ;
#ifdef F_5
F_9 ( V_66 , V_67 , L_18 , V_68 ,
V_70 . V_26 == V_27 ? L_19 :
V_70 . V_26 == V_72 ? L_20 :
L_21 ) ;
if ( V_70 . V_26 == V_72 ) {
F_9 ( V_66 , V_67 , L_22 , V_68 , V_70 . V_28 ? V_70 . V_28 : L_4 ) ;
F_9 ( V_66 , V_67 , L_23 , V_68 , V_70 . V_29 ? V_70 . V_29 : L_4 ) ;
}
F_9 ( V_66 , V_67 , L_24 , V_68 ,
V_70 . V_30 == V_31 ? L_25 :
V_70 . V_30 == V_73 ? L_26 :
L_21 ) ;
if ( V_70 . V_30 == V_73 ) {
F_9 ( V_66 , V_67 , L_27 , V_68 , V_70 . V_32 ? V_70 . V_32 : L_4 ) ;
F_9 ( V_66 , V_67 , L_28 , V_68 ) ;
}
F_9 ( V_66 , V_67 , L_29 , V_68 , V_70 . V_34 ) ;
F_9 ( V_66 , V_67 , L_30 , V_68 , V_70 . V_35 ) ;
F_9 ( V_66 , V_67 , L_31 , V_68 , V_70 . V_36 ) ;
#endif
#ifdef F_6
F_9 ( V_66 , V_67 , L_32 , V_68 , V_70 . V_37 ) ;
F_9 ( V_66 , V_67 , L_33 , V_68 , V_70 . V_39 ) ;
#endif
}
F_9 ( V_66 , V_67 , L_34 , V_1 -> V_7 . V_8 ? V_1 -> V_7 . V_8 : L_4 ) ;
F_9 ( V_66 , V_67 , L_35 , V_1 -> V_7 . V_9 ? V_1 -> V_7 . V_9 : L_4 ) ;
F_9 ( V_66 , V_67 , L_36 , V_1 -> V_7 . V_10 ? V_1 -> V_7 . V_10 : L_4 ) ;
F_9 ( V_66 , V_67 , L_37 , V_1 -> V_7 . V_11 , V_1 -> V_7 . V_12 ) ;
F_9 ( V_66 , V_67 , L_38 , V_1 -> V_7 . V_14 ) ;
F_9 ( V_66 , V_67 , L_39 , V_1 -> V_7 . V_15 ? L_11 : L_12 ) ;
#ifdef F_3
F_9 ( V_66 , V_67 , L_40 , V_1 -> V_7 . V_18 ? V_1 -> V_7 . V_18 : L_4 ) ;
F_9 ( V_66 , V_67 , L_41 , V_1 -> V_7 . V_19 ? V_1 -> V_7 . V_19 : L_4 ) ;
#endif
#ifdef F_4
F_9 ( V_66 , V_67 , L_42 , V_1 -> V_7 . V_23 ) ;
#endif
F_9 ( V_66 , V_67 , L_43 , V_1 -> V_7 . V_25 ? L_11 : L_12 ) ;
#ifdef F_5
F_9 ( V_66 , V_67 , L_44 ,
V_1 -> V_7 . V_26 == V_27 ? L_19 :
V_1 -> V_7 . V_26 == V_72 ? L_20 :
L_21 ) ;
if ( V_1 -> V_7 . V_26 == V_72 ) {
F_9 ( V_66 , V_67 , L_45 , V_1 -> V_7 . V_28 ? V_1 -> V_7 . V_28 : L_4 ) ;
F_9 ( V_66 , V_67 , L_46 , V_1 -> V_7 . V_29 ? V_1 -> V_7 . V_29 : L_4 ) ;
}
F_9 ( V_66 , V_67 , L_47 ,
V_1 -> V_7 . V_30 == V_31 ? L_25 :
V_1 -> V_7 . V_30 == V_73 ? L_26 :
L_21 ) ;
if ( V_1 -> V_7 . V_30 == V_73 ) {
F_9 ( V_66 , V_67 , L_48 , V_1 -> V_7 . V_32 ? V_1 -> V_7 . V_32 : L_4 ) ;
F_9 ( V_66 , V_67 , L_49 ) ;
}
F_9 ( V_66 , V_67 , L_50 , V_1 -> V_7 . V_34 ) ;
F_9 ( V_66 , V_67 , L_51 , V_1 -> V_7 . V_35 ) ;
F_9 ( V_66 , V_67 , L_52 , V_1 -> V_7 . V_36 ) ;
#endif
#ifdef F_6
F_9 ( V_66 , V_67 , L_53 , V_1 -> V_7 . V_37 ) ;
F_9 ( V_66 , V_67 , L_54 , V_1 -> V_7 . V_39 ) ;
#endif
F_9 ( V_66 , V_67 , L_55 , V_1 -> V_40 ) ;
F_9 ( V_66 , V_67 , L_56 , ( V_1 -> V_41 ) ? V_1 -> V_41 : L_57 ) ;
F_9 ( V_66 , V_67 , L_58 , V_1 -> V_42 ) ;
F_9 ( V_66 , V_67 , L_59 , ( V_1 -> V_43 ) ? L_60 : L_61 ) ;
F_9 ( V_66 , V_67 , L_62 , V_1 -> V_44 ) ;
F_9 ( V_66 , V_67 , L_63 , V_1 -> V_45 ) ;
F_9 ( V_66 , V_67 , L_64 , V_1 -> V_46 ) ;
F_9 ( V_66 , V_67 , L_65 , V_1 -> V_49 ) ;
F_9 ( V_66 , V_67 , L_66 , V_1 -> V_50 , V_1 -> V_51 ) ;
F_9 ( V_66 , V_67 , L_67 , V_1 -> V_52 , V_1 -> V_53 ) ;
F_9 ( V_66 , V_67 , L_68 , V_1 -> V_55 , V_1 -> V_56 ) ;
F_9 ( V_66 , V_67 , L_69 , V_1 -> V_57 , V_1 -> V_58 ) ;
F_9 ( V_66 , V_67 , L_70 , V_1 -> V_59 , V_1 -> V_60 ) ;
F_9 ( V_66 , V_67 , L_71 , V_1 -> V_61 , V_1 -> V_62 ) ;
}
static T_4
F_11 ( T_1 * V_1 , const char * V_74 )
{
T_5 * V_75 , * V_76 ;
V_76 = strchr ( V_74 , ':' ) ;
if ( V_76 == NULL )
return FALSE ;
V_75 = V_76 ;
* V_75 ++ = '\0' ;
while ( F_12 ( * V_75 ) )
V_75 ++ ;
if ( * V_75 == '\0' ) {
* V_76 = ':' ;
return FALSE ;
}
if ( strcmp ( V_74 , L_72 ) == 0 ) {
V_1 -> V_61 = TRUE ;
V_1 -> V_62 = F_13 ( V_75 , L_73 ) ;
} else if ( strcmp ( V_74 , L_74 ) == 0 ) {
V_1 -> V_59 = TRUE ;
V_1 -> V_60 = F_13 ( V_75 , L_75 ) ;
} else if ( strcmp ( V_74 , L_76 ) == 0 ) {
V_1 -> V_49 = TRUE ;
V_1 -> V_55 = TRUE ;
V_1 -> V_56 = F_13 ( V_75 , L_77 ) ;
} else {
return FALSE ;
}
* V_76 = ':' ;
return TRUE ;
}
static T_4
F_14 ( T_1 * V_1 , const char * V_77 )
{
T_5 * V_75 = NULL , * V_76 ;
V_76 = strchr ( V_77 , ':' ) ;
if ( V_76 == NULL )
return FALSE ;
V_75 = V_76 ;
* V_75 ++ = '\0' ;
while ( F_12 ( * V_75 ) )
V_75 ++ ;
if ( * V_75 == '\0' ) {
* V_76 = ':' ;
return FALSE ;
}
if ( strcmp ( V_77 , L_76 ) == 0 ) {
V_1 -> V_52 = TRUE ;
V_1 -> V_53 = F_13 ( V_75 , L_78 ) ;
} else if ( strcmp ( V_77 , L_74 ) == 0 ) {
V_1 -> V_59 = TRUE ;
V_1 -> V_60 = F_13 ( V_75 , L_79 ) ;
} else if ( strcmp ( V_77 , L_72 ) == 0 ) {
V_1 -> V_50 = TRUE ;
V_1 -> V_51 = F_13 ( V_75 , L_80 ) ;
}
* V_76 = ':' ;
return TRUE ;
}
static T_4
F_15 ( T_1 * V_1 , const char * V_77 )
{
T_5 * V_75 = NULL , * V_76 ;
V_76 = strchr ( V_77 , ':' ) ;
if ( V_76 == NULL )
return FALSE ;
V_75 = V_76 ;
* V_75 ++ = '\0' ;
while ( F_12 ( * V_75 ) )
V_75 ++ ;
if ( * V_75 == '\0' ) {
* V_76 = ':' ;
return FALSE ;
}
if ( strcmp ( V_77 , L_81 ) == 0 ) {
if ( V_1 -> V_2 -> V_69 > 0 ) {
V_3 V_70 ;
V_70 = F_10 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_69 - 1 ) ;
V_1 -> V_2 = F_16 ( V_1 -> V_2 , V_1 -> V_2 -> V_69 - 1 ) ;
V_70 . V_37 = V_78 ;
V_70 . V_39 = F_13 ( V_75 , L_82 ) ;
F_17 ( V_1 -> V_2 , V_70 ) ;
} else {
V_1 -> V_7 . V_37 = V_78 ;
V_1 -> V_7 . V_39 = F_13 ( V_75 , L_82 ) ;
}
} else if ( strcmp ( V_77 , L_83 ) == 0 ) {
if ( V_1 -> V_2 -> V_69 > 0 ) {
V_3 V_70 ;
V_70 = F_10 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_69 - 1 ) ;
V_1 -> V_2 = F_16 ( V_1 -> V_2 , V_1 -> V_2 -> V_69 - 1 ) ;
V_70 . V_37 = V_79 ;
V_70 . V_39 = F_13 ( V_75 , L_84 ) ;
F_17 ( V_1 -> V_2 , V_70 ) ;
} else {
V_1 -> V_7 . V_37 = V_79 ;
V_1 -> V_7 . V_39 = F_13 ( V_75 , L_84 ) ;
}
}
* V_76 = ':' ;
return TRUE ;
}
static T_4
F_18 ( T_1 * V_1 , const char * V_77 )
{
T_5 * V_75 = NULL , * V_76 ;
V_76 = strchr ( V_77 , ':' ) ;
if ( V_76 == NULL )
return FALSE ;
V_75 = V_76 ;
* V_75 ++ = '\0' ;
while ( F_12 ( * V_75 ) )
V_75 ++ ;
if ( V_1 -> V_2 -> V_69 > 0 ) {
V_3 V_70 ;
V_70 = F_10 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_69 - 1 ) ;
V_1 -> V_2 = F_16 ( V_1 -> V_2 , V_1 -> V_2 -> V_69 - 1 ) ;
V_70 . V_30 = V_73 ;
V_70 . V_32 = F_19 ( V_77 ) ;
V_70 . V_33 = F_19 ( V_75 ) ;
F_17 ( V_1 -> V_2 , V_70 ) ;
} else {
V_1 -> V_7 . V_30 = V_73 ;
V_1 -> V_7 . V_32 = F_19 ( V_77 ) ;
V_1 -> V_7 . V_33 = F_19 ( V_75 ) ;
}
* V_76 = ':' ;
return TRUE ;
}
static int
F_20 ( T_1 * V_1 , const char * V_80 )
{
long V_81 ;
char * V_75 ;
T_6 * V_82 ;
T_7 * V_83 ;
int V_84 ;
T_5 * V_85 ;
V_3 V_70 ;
V_81 = strtol ( V_80 , & V_75 , 10 ) ;
if ( V_75 != NULL && * V_75 == '\0' ) {
if ( V_81 < 0 ) {
F_21 ( L_85 ) ;
return 1 ;
}
if ( V_81 > V_86 ) {
F_21 ( L_86 ,
V_86 ) ;
return 1 ;
}
if ( V_81 == 0 ) {
F_21 ( L_87 ) ;
return 1 ;
}
V_82 = F_22 ( & V_84 , & V_85 , NULL ) ;
if ( V_82 == NULL ) {
if ( V_84 == 0 )
F_21 ( L_88 ) ;
else {
F_21 ( L_89 , V_85 ) ;
F_23 ( V_85 ) ;
}
return 2 ;
}
V_83 = ( T_7 * ) F_24 ( V_82 , ( int ) ( V_81 - 1 ) ) ;
if ( V_83 == NULL ) {
F_21 ( L_87 ) ;
return 1 ;
}
V_70 . V_8 = F_19 ( V_83 -> V_8 ) ;
if ( V_83 -> V_87 != NULL ) {
V_70 . V_71 = F_19 ( V_83 -> V_87 ) ;
} else {
V_70 . V_71 = F_19 ( V_83 -> V_8 ) ;
}
V_70 . V_16 = V_83 -> type ;
#ifdef F_3
V_70 . V_18 = F_19 ( V_83 -> V_18 ) ;
#endif
F_25 ( V_82 ) ;
} else if ( V_1 -> V_65 ) {
V_70 . V_8 = F_19 ( V_80 ) ;
V_70 . V_71 = F_19 ( V_80 ) ;
V_70 . V_16 = V_1 -> V_7 . V_16 ;
#ifdef F_3
V_70 . V_18 = F_19 ( V_1 -> V_7 . V_18 ) ;
#endif
} else {
V_82 = F_22 ( & V_84 , NULL , NULL ) ;
if ( V_82 != NULL ) {
T_6 * V_88 ;
T_4 V_89 ;
V_89 = FALSE ;
for ( V_88 = F_26 ( V_82 ) ; V_88 != NULL ;
V_88 = F_27 ( V_88 ) )
{
V_83 = ( T_7 * ) V_88 -> V_90 ;
if ( F_28 ( V_83 -> V_8 , V_80 ) == 0 ) {
V_70 . V_8 = F_19 ( V_83 -> V_8 ) ;
if ( V_83 -> V_87 != NULL ) {
V_70 . V_71 = F_19 ( V_83 -> V_87 ) ;
} else {
V_70 . V_71 = F_19 ( V_83 -> V_8 ) ;
}
V_70 . V_16 = V_83 -> type ;
#ifdef F_3
V_70 . V_18 = F_19 ( V_83 -> V_18 ) ;
#endif
V_89 = TRUE ;
break;
}
if ( V_83 -> V_87 != NULL &&
F_28 ( V_83 -> V_87 , V_80 ) == 0 ) {
V_70 . V_8 = F_19 ( V_83 -> V_8 ) ;
V_70 . V_71 = F_19 ( V_83 -> V_87 ) ;
V_70 . V_16 = V_83 -> type ;
#ifdef F_3
V_70 . V_18 = F_19 ( V_83 -> V_18 ) ;
#endif
V_89 = TRUE ;
break;
}
}
if ( ! V_89 ) {
T_8 V_91 ;
V_91 = strlen ( V_80 ) ;
for ( V_88 = F_26 ( V_82 ) ; V_88 != NULL ;
V_88 = F_27 ( V_88 ) )
{
V_83 = ( T_7 * ) V_88 -> V_90 ;
if ( V_83 -> V_87 != NULL &&
F_29 ( V_83 -> V_87 , V_80 , V_91 ) == 0 ) {
V_70 . V_8 = F_19 ( V_83 -> V_8 ) ;
V_70 . V_71 = F_19 ( V_83 -> V_87 ) ;
V_70 . V_16 = V_83 -> type ;
#ifdef F_3
V_70 . V_18 = F_19 ( V_83 -> V_18 ) ;
#endif
V_89 = TRUE ;
break;
}
}
}
if ( ! V_89 ) {
V_70 . V_8 = F_19 ( V_80 ) ;
V_70 . V_71 = F_19 ( V_80 ) ;
V_70 . V_16 = V_1 -> V_7 . V_16 ;
#ifdef F_3
V_70 . V_18 = F_19 ( V_1 -> V_7 . V_18 ) ;
#endif
}
F_25 ( V_82 ) ;
} else {
V_70 . V_8 = F_19 ( V_80 ) ;
V_70 . V_71 = F_19 ( V_80 ) ;
V_70 . V_16 = V_1 -> V_7 . V_16 ;
#ifdef F_3
V_70 . V_18 = F_19 ( V_1 -> V_7 . V_18 ) ;
#endif
}
}
V_70 . V_9 = F_19 ( V_1 -> V_7 . V_9 ) ;
V_70 . V_10 = F_19 ( V_1 -> V_7 . V_10 ) ;
V_70 . V_12 = V_1 -> V_7 . V_12 ;
V_70 . V_11 = V_1 -> V_7 . V_11 ;
V_70 . V_14 = V_1 -> V_7 . V_14 ;
V_70 . V_15 = V_1 -> V_7 . V_15 ;
#ifdef F_3
V_70 . V_19 = F_19 ( V_1 -> V_7 . V_19 ) ;
V_70 . V_20 = NULL ;
V_70 . V_21 = V_22 ;
#endif
#ifdef F_4
V_70 . V_23 = V_1 -> V_7 . V_23 ;
#endif
V_70 . V_25 = V_1 -> V_7 . V_25 ;
#ifdef F_5
V_70 . V_26 = V_1 -> V_7 . V_26 ;
V_70 . V_28 = F_19 ( V_1 -> V_7 . V_28 ) ;
V_70 . V_29 = F_19 ( V_1 -> V_7 . V_29 ) ;
V_70 . V_30 = V_1 -> V_7 . V_30 ;
V_70 . V_32 = F_19 ( V_1 -> V_7 . V_32 ) ;
V_70 . V_33 = F_19 ( V_1 -> V_7 . V_33 ) ;
V_70 . V_34 = V_1 -> V_7 . V_34 ;
V_70 . V_35 = V_1 -> V_7 . V_35 ;
V_70 . V_36 = V_1 -> V_7 . V_36 ;
#endif
#ifdef F_6
V_70 . V_37 = V_1 -> V_7 . V_37 ;
V_70 . V_39 = V_1 -> V_7 . V_39 ;
#endif
F_17 ( V_1 -> V_2 , V_70 ) ;
return 0 ;
}
int
F_30 ( T_1 * V_1 , int V_92 , const char * V_80 , T_4 * V_93 )
{
int V_94 , V_12 ;
switch( V_92 ) {
case V_95 :
if ( V_1 -> V_63 ) {
F_21 ( L_90 ) ;
return 1 ;
}
V_1 -> V_63 = F_19 ( V_80 ) ;
break;
case 'a' :
if ( F_11 ( V_1 , V_80 ) == FALSE ) {
F_21 ( L_91 , V_80 ) ;
return 1 ;
}
break;
#ifdef F_5
case 'A' :
if ( F_18 ( V_1 , V_80 ) == FALSE ) {
F_21 ( L_92 , V_80 ) ;
return 1 ;
}
break;
#endif
case 'b' :
V_1 -> V_49 = TRUE ;
if ( F_14 ( V_1 , V_80 ) == FALSE ) {
F_21 ( L_93 , V_80 ) ;
return 1 ;
}
break;
#ifdef F_4
case 'B' :
if ( V_1 -> V_2 -> V_69 > 0 ) {
V_3 V_70 ;
V_70 = F_10 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_69 - 1 ) ;
V_1 -> V_2 = F_16 ( V_1 -> V_2 , V_1 -> V_2 -> V_69 - 1 ) ;
V_70 . V_23 = F_13 ( V_80 , L_94 ) ;
F_17 ( V_1 -> V_2 , V_70 ) ;
} else {
V_1 -> V_7 . V_23 = F_13 ( V_80 , L_94 ) ;
}
break;
#endif
case 'c' :
V_1 -> V_57 = TRUE ;
V_1 -> V_58 = F_13 ( V_80 , L_95 ) ;
break;
case 'f' :
if ( V_1 -> V_2 -> V_69 > 0 ) {
V_3 V_70 ;
V_70 = F_10 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_69 - 1 ) ;
V_1 -> V_2 = F_16 ( V_1 -> V_2 , V_1 -> V_2 -> V_69 - 1 ) ;
F_23 ( V_70 . V_10 ) ;
V_70 . V_10 = F_19 ( V_80 ) ;
F_17 ( V_1 -> V_2 , V_70 ) ;
} else {
F_23 ( V_1 -> V_7 . V_10 ) ;
V_1 -> V_7 . V_10 = F_19 ( V_80 ) ;
}
break;
case 'g' :
V_1 -> V_42 = TRUE ;
break;
case 'H' :
V_1 -> V_45 = FALSE ;
break;
case 'i' :
V_94 = F_20 ( V_1 , V_80 ) ;
if ( V_94 != 0 ) {
return V_94 ;
}
break;
#ifdef F_31
case 'I' :
if ( V_1 -> V_2 -> V_69 > 0 ) {
V_3 V_70 ;
V_70 = F_10 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_69 - 1 ) ;
V_1 -> V_2 = F_16 ( V_1 -> V_2 , V_1 -> V_2 -> V_69 - 1 ) ;
V_70 . V_25 = TRUE ;
F_17 ( V_1 -> V_2 , V_70 ) ;
} else {
V_1 -> V_7 . V_25 = TRUE ;
}
break;
#endif
case 'k' :
* V_93 = TRUE ;
break;
#ifdef F_6
case 'm' :
if ( F_15 ( V_1 , V_80 ) == FALSE ) {
F_21 ( L_96 , V_80 ) ;
return 1 ;
}
break;
#endif
case 'n' :
V_1 -> V_43 = TRUE ;
break;
case 'p' :
if ( V_1 -> V_2 -> V_69 > 0 ) {
V_3 V_70 ;
V_70 = F_10 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_69 - 1 ) ;
V_1 -> V_2 = F_16 ( V_1 -> V_2 , V_1 -> V_2 -> V_69 - 1 ) ;
V_70 . V_15 = FALSE ;
F_17 ( V_1 -> V_2 , V_70 ) ;
} else {
V_1 -> V_7 . V_15 = FALSE ;
}
break;
case 'P' :
V_1 -> V_43 = FALSE ;
break;
#ifdef F_5
case 'r' :
if ( V_1 -> V_2 -> V_69 > 0 ) {
V_3 V_70 ;
V_70 = F_10 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_69 - 1 ) ;
V_1 -> V_2 = F_16 ( V_1 -> V_2 , V_1 -> V_2 -> V_69 - 1 ) ;
V_70 . V_35 = FALSE ;
F_17 ( V_1 -> V_2 , V_70 ) ;
} else {
V_1 -> V_7 . V_35 = FALSE ;
}
break;
#endif
case 's' :
V_12 = F_32 ( V_80 , L_97 ) ;
if ( V_12 == 0 )
V_12 = V_13 ;
if ( V_1 -> V_2 -> V_69 > 0 ) {
V_3 V_70 ;
V_70 = F_10 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_69 - 1 ) ;
V_1 -> V_2 = F_16 ( V_1 -> V_2 , V_1 -> V_2 -> V_69 - 1 ) ;
V_70 . V_11 = TRUE ;
V_70 . V_12 = V_12 ;
F_17 ( V_1 -> V_2 , V_70 ) ;
} else {
V_1 -> V_7 . V_12 = V_12 ;
V_1 -> V_7 . V_11 = TRUE ;
}
break;
case 'S' :
V_1 -> V_44 = TRUE ;
break;
#ifdef F_5
case 'u' :
if ( V_1 -> V_2 -> V_69 > 0 ) {
V_3 V_70 ;
V_70 = F_10 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_69 - 1 ) ;
V_1 -> V_2 = F_16 ( V_1 -> V_2 , V_1 -> V_2 -> V_69 - 1 ) ;
V_70 . V_34 = TRUE ;
F_17 ( V_1 -> V_2 , V_70 ) ;
} else {
V_1 -> V_7 . V_34 = TRUE ;
}
break;
#endif
case 'w' :
V_1 -> V_40 = TRUE ;
F_23 ( V_1 -> V_41 ) ;
V_1 -> V_41 = F_19 ( V_80 ) ;
V_94 = F_33 ( V_1 -> V_41 , & V_1 -> V_64 ) ;
return V_94 ;
case 'y' :
if ( V_1 -> V_2 -> V_69 > 0 ) {
V_3 V_70 ;
V_70 = F_10 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_69 - 1 ) ;
V_1 -> V_2 = F_16 ( V_1 -> V_2 , V_1 -> V_2 -> V_69 - 1 ) ;
V_70 . V_14 = F_34 ( V_80 ) ;
if ( V_70 . V_14 == - 1 ) {
F_21 ( L_98 ,
V_80 ) ;
return 1 ;
}
F_17 ( V_1 -> V_2 , V_70 ) ;
} else {
V_1 -> V_7 . V_14 = F_34 ( V_80 ) ;
if ( V_1 -> V_7 . V_14 == - 1 ) {
F_21 ( L_98 ,
V_80 ) ;
return 1 ;
}
}
break;
default:
F_35 () ;
}
return 0 ;
}
void
F_36 ( T_9 * V_96 , char * V_8 ,
T_4 V_25 )
{
T_6 * V_97 ;
T_10 * V_98 ;
if ( V_96 -> V_99 )
printf ( L_99 ,
V_8 , V_25 ? L_57 : L_100 ) ;
else
printf ( L_101 , V_8 ) ;
for ( V_97 = V_96 -> V_100 ; V_97 != NULL ;
V_97 = F_27 ( V_97 ) ) {
V_98 = ( T_10 * ) V_97 -> V_90 ;
printf ( L_102 , V_98 -> V_8 ) ;
if ( V_98 -> V_101 != NULL )
printf ( L_103 , V_98 -> V_101 ) ;
else
printf ( L_104 ) ;
printf ( L_105 ) ;
}
}
void
F_37 ( T_6 * V_82 )
{
int V_68 ;
T_6 * V_88 ;
T_7 * V_83 ;
V_68 = 1 ;
for ( V_88 = F_26 ( V_82 ) ; V_88 != NULL ;
V_88 = F_27 ( V_88 ) ) {
V_83 = ( T_7 * ) V_88 -> V_90 ;
printf ( L_106 , V_68 ++ , V_83 -> V_8 ) ;
if ( V_83 -> V_87 != NULL ) {
printf ( L_103 , V_83 -> V_87 ) ;
} else {
if ( V_83 -> V_102 != NULL )
printf ( L_103 , V_83 -> V_102 ) ;
}
printf ( L_105 ) ;
}
}
void
F_38 ( T_1 * V_1 , int V_103 )
{
T_3 V_68 ;
V_3 V_70 ;
if ( V_1 -> V_2 -> V_69 > 0 ) {
for ( V_68 = 0 ; V_68 < V_1 -> V_2 -> V_69 ; V_68 ++ ) {
V_70 = F_10 ( V_1 -> V_2 , V_3 , 0 ) ;
V_1 -> V_2 = F_16 ( V_1 -> V_2 , 0 ) ;
if ( V_70 . V_12 < 1 )
V_70 . V_12 = V_13 ;
else if ( V_70 . V_12 < V_103 )
V_70 . V_12 = V_103 ;
F_17 ( V_1 -> V_2 , V_70 ) ;
}
} else {
if ( V_1 -> V_7 . V_12 < 1 )
V_1 -> V_7 . V_12 = V_13 ;
else if ( V_1 -> V_7 . V_12 < V_103 )
V_1 -> V_7 . V_12 = V_103 ;
}
}
void
F_39 ( T_1 * V_1 )
{
if ( V_1 -> V_53 > V_104 ) {
F_21 ( L_107 , V_1 -> V_53 , V_104 ) ;
V_1 -> V_53 = V_104 ;
} else if ( V_1 -> V_53 > V_105 ) {
F_21 ( L_108 , V_1 -> V_53 ) ;
}
#if V_54 > 0
else if ( V_1 -> V_53 < V_54 )
F_21 ( L_109 , V_1 -> V_53 , V_54 ) ;
V_1 -> V_53 = V_54 ;
#endif
}
int
F_40 ( T_1 * V_1 ,
const char * V_106 )
{
int V_94 ;
if ( V_1 -> V_6 != 0 || V_1 -> V_2 -> V_69 != 0 ) {
return 0 ;
}
if ( V_106 != NULL ) {
V_94 = F_20 ( V_1 , V_106 ) ;
return V_94 ;
}
return F_20 ( V_1 , L_110 ) ;
}
static int
F_41 ( const char * V_107 )
{
T_11 V_108 ;
if ( F_42 ( V_107 , & V_108 ) < 0 )
return V_109 ;
if ( F_43 ( V_108 . V_110 ) )
return V_111 ;
else
return 0 ;
}
static T_4
F_33 ( const char * V_41 , T_4 * V_112 )
{
int V_84 ;
* V_112 = FALSE ;
if ( V_41 != NULL ) {
if ( strcmp ( V_41 , L_111 ) == 0 ) {
* V_112 = TRUE ;
} else {
V_84 = F_41 ( V_41 ) ;
switch ( V_84 ) {
case V_113 :
case 0 :
break;
case V_111 :
* V_112 = TRUE ;
break;
default:
break;
}
}
}
return 0 ;
}
void
F_44 ( T_1 * V_1 , T_3 V_114 )
{
V_3 V_70 ;
V_70 = F_10 ( V_1 -> V_2 , V_3 , V_114 ) ;
F_23 ( V_70 . V_8 ) ;
F_23 ( V_70 . V_9 ) ;
if ( V_70 . V_71 != NULL )
F_23 ( V_70 . V_71 ) ;
F_23 ( V_70 . V_10 ) ;
#ifdef F_3
F_23 ( V_70 . V_18 ) ;
F_23 ( V_70 . V_19 ) ;
if ( V_70 . V_20 )
F_45 ( V_70 . V_20 ) ;
if ( V_70 . V_21 != V_22 )
F_46 ( V_70 . V_21 ) ;
#endif
#ifdef F_5
if ( V_70 . V_26 == V_72 ) {
F_23 ( V_70 . V_28 ) ;
F_23 ( V_70 . V_29 ) ;
F_23 ( V_70 . V_32 ) ;
F_23 ( V_70 . V_33 ) ;
}
#endif
V_1 -> V_2 = F_16 ( V_1 -> V_2 , V_114 ) ;
}
void
F_47 ( T_1 * V_1 )
{
T_3 V_68 ;
V_5 V_115 ;
V_3 V_70 ;
for ( V_68 = V_1 -> V_2 -> V_69 ; V_68 != 0 ; V_68 -- )
F_44 ( V_1 , V_68 - 1 ) ;
for ( V_68 = 0 ; V_68 < V_1 -> V_4 -> V_69 ; V_68 ++ ) {
V_115 = F_10 ( V_1 -> V_4 , V_5 , V_68 ) ;
if ( ! V_115 . V_116 && V_115 . V_117 ) {
V_70 . V_8 = F_19 ( V_115 . V_8 ) ;
V_70 . V_9 = F_19 ( V_115 . V_118 ) ;
V_70 . V_71 = F_19 ( V_115 . V_8 ) ;
V_70 . V_14 = V_115 . V_119 ;
V_70 . V_10 = F_19 ( V_115 . V_10 ) ;
V_70 . V_12 = V_115 . V_12 ;
V_70 . V_11 = V_115 . V_11 ;
V_70 . V_15 = V_115 . V_120 ;
V_70 . V_16 = V_115 . V_83 . type ;
#ifdef F_3
V_70 . V_18 = F_19 ( V_115 . V_83 . V_18 ) ;
V_70 . V_19 = NULL ;
V_70 . V_20 = V_115 . V_121 ;
V_70 . V_21 = V_22 ;
if ( V_70 . V_20 )
F_48 ( V_70 . V_20 ) ;
#endif
#ifdef F_4
V_70 . V_23 = V_115 . V_122 ;
#endif
#ifdef F_31
V_70 . V_25 = V_115 . V_123 ;
#endif
#ifdef F_5
V_70 . V_26 = V_72 ;
V_70 . V_28 = F_19 ( V_115 . V_124 . V_125 . V_28 ) ;
V_70 . V_29 = F_19 ( V_115 . V_124 . V_125 . V_29 ) ;
V_70 . V_30 = V_115 . V_124 . V_125 . V_30 ;
V_70 . V_32 = F_19 ( V_115 . V_124 . V_125 . V_32 ) ;
V_70 . V_33 = F_19 ( V_115 . V_124 . V_125 . V_33 ) ;
V_70 . V_34 = V_115 . V_124 . V_125 . V_34 ;
V_70 . V_35 = V_115 . V_124 . V_125 . V_35 ;
V_70 . V_36 = V_115 . V_124 . V_125 . V_36 ;
#endif
#ifdef F_6
V_70 . V_37 = V_115 . V_124 . V_37 ;
V_70 . V_39 = V_115 . V_124 . V_39 ;
#endif
F_17 ( V_1 -> V_2 , V_70 ) ;
} else {
continue;
}
}
}

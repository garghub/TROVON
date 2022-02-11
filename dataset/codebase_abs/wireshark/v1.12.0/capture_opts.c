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
#if F_3 ( V_18 ) || F_3 ( V_19 )
V_1 -> V_7 . V_20 = V_21 ;
#endif
V_1 -> V_7 . V_22 = FALSE ;
#ifdef F_4
V_1 -> V_7 . V_23 = V_24 ;
V_1 -> V_7 . V_25 = NULL ;
V_1 -> V_7 . V_26 = NULL ;
V_1 -> V_7 . V_27 = V_28 ;
V_1 -> V_7 . V_29 = NULL ;
V_1 -> V_7 . V_30 = NULL ;
V_1 -> V_7 . V_31 = FALSE ;
V_1 -> V_7 . V_32 = TRUE ;
V_1 -> V_7 . V_33 = FALSE ;
#endif
#ifdef F_5
V_1 -> V_7 . V_34 = V_35 ;
V_1 -> V_7 . V_36 = 0 ;
#endif
V_1 -> V_37 = FALSE ;
V_1 -> V_38 = NULL ;
V_1 -> V_39 = FALSE ;
#ifdef F_6
V_1 -> V_40 = TRUE ;
#else
V_1 -> V_40 = FALSE ;
#endif
V_1 -> V_41 = TRUE ;
V_1 -> V_42 = TRUE ;
V_1 -> V_43 = getenv ( L_1 ) ? TRUE : FALSE ;
V_1 -> V_44 = FALSE ;
V_1 -> V_45 = NULL ;
V_1 -> V_46 = FALSE ;
V_1 -> V_47 = FALSE ;
V_1 -> V_48 = 60 ;
V_1 -> V_49 = FALSE ;
V_1 -> V_50 = V_51 ;
V_1 -> V_52 = FALSE ;
V_1 -> V_53 = 1 ;
V_1 -> V_54 = FALSE ;
V_1 -> V_55 = 0 ;
V_1 -> V_56 = FALSE ;
V_1 -> V_57 = 1000 ;
V_1 -> V_58 = FALSE ;
V_1 -> V_59 = 60 ;
V_1 -> V_60 = NULL ;
V_1 -> V_61 = FALSE ;
V_1 -> V_62 = FALSE ;
}
void
F_7 ( const char * V_63 , T_2 V_64 , T_1 * V_1 ) {
T_3 V_65 ;
F_8 ( V_63 , V_64 , L_2 ) ;
for ( V_65 = 0 ; V_65 < V_1 -> V_2 -> V_66 ; V_65 ++ ) {
V_3 V_67 ;
V_67 = F_9 ( V_1 -> V_2 , V_3 , V_65 ) ;
F_8 ( V_63 , V_64 , L_3 , V_65 , V_67 . V_8 ? V_67 . V_8 : L_4 ) ;
F_8 ( V_63 , V_64 , L_5 , V_65 , V_67 . V_9 ? V_67 . V_9 : L_4 ) ;
F_8 ( V_63 , V_64 , L_6 , V_65 , V_67 . V_68 ? V_67 . V_68 : L_4 ) ;
F_8 ( V_63 , V_64 , L_7 , V_65 , V_67 . V_10 ? V_67 . V_10 : L_4 ) ;
F_8 ( V_63 , V_64 , L_8 , V_65 , V_67 . V_11 , V_67 . V_12 ) ;
F_8 ( V_63 , V_64 , L_9 , V_65 , V_67 . V_14 ) ;
F_8 ( V_63 , V_64 , L_10 , V_65 , V_67 . V_15 ? L_11 : L_12 ) ;
#if F_3 ( V_18 ) || F_3 ( V_19 )
F_8 ( V_63 , V_64 , L_13 , V_65 , V_67 . V_20 ) ;
#endif
F_8 ( V_63 , V_64 , L_14 , V_65 , V_67 . V_22 ? L_11 : L_12 ) ;
#ifdef F_4
F_8 ( V_63 , V_64 , L_15 , V_65 ,
V_67 . V_23 == V_24 ? L_16 :
V_67 . V_23 == V_69 ? L_17 :
L_18 ) ;
if ( V_67 . V_23 == V_69 ) {
F_8 ( V_63 , V_64 , L_19 , V_65 , V_67 . V_25 ? V_67 . V_25 : L_4 ) ;
F_8 ( V_63 , V_64 , L_20 , V_65 , V_67 . V_26 ? V_67 . V_26 : L_4 ) ;
}
F_8 ( V_63 , V_64 , L_21 , V_65 ,
V_67 . V_27 == V_28 ? L_22 :
V_67 . V_27 == V_70 ? L_23 :
L_18 ) ;
if ( V_67 . V_27 == V_70 ) {
F_8 ( V_63 , V_64 , L_24 , V_65 , V_67 . V_29 ? V_67 . V_29 : L_4 ) ;
F_8 ( V_63 , V_64 , L_25 , V_65 ) ;
}
F_8 ( V_63 , V_64 , L_26 , V_65 , V_67 . V_31 ) ;
F_8 ( V_63 , V_64 , L_27 , V_65 , V_67 . V_32 ) ;
F_8 ( V_63 , V_64 , L_28 , V_65 , V_67 . V_33 ) ;
#endif
#ifdef F_5
F_8 ( V_63 , V_64 , L_29 , V_65 , V_67 . V_34 ) ;
F_8 ( V_63 , V_64 , L_30 , V_65 , V_67 . V_36 ) ;
#endif
}
F_8 ( V_63 , V_64 , L_31 , V_1 -> V_7 . V_8 ? V_1 -> V_7 . V_8 : L_4 ) ;
F_8 ( V_63 , V_64 , L_32 , V_1 -> V_7 . V_9 ? V_1 -> V_7 . V_9 : L_4 ) ;
F_8 ( V_63 , V_64 , L_33 , V_1 -> V_7 . V_10 ? V_1 -> V_7 . V_10 : L_4 ) ;
F_8 ( V_63 , V_64 , L_34 , V_1 -> V_7 . V_11 , V_1 -> V_7 . V_12 ) ;
F_8 ( V_63 , V_64 , L_35 , V_1 -> V_7 . V_14 ) ;
F_8 ( V_63 , V_64 , L_36 , V_1 -> V_7 . V_15 ? L_11 : L_12 ) ;
#if F_3 ( V_18 ) || F_3 ( V_19 )
F_8 ( V_63 , V_64 , L_37 , V_1 -> V_7 . V_20 ) ;
#endif
F_8 ( V_63 , V_64 , L_38 , V_1 -> V_7 . V_22 ? L_11 : L_12 ) ;
#ifdef F_4
F_8 ( V_63 , V_64 , L_39 ,
V_1 -> V_7 . V_23 == V_24 ? L_16 :
V_1 -> V_7 . V_23 == V_69 ? L_17 :
L_18 ) ;
if ( V_1 -> V_7 . V_23 == V_69 ) {
F_8 ( V_63 , V_64 , L_40 , V_1 -> V_7 . V_25 ? V_1 -> V_7 . V_25 : L_4 ) ;
F_8 ( V_63 , V_64 , L_41 , V_1 -> V_7 . V_26 ? V_1 -> V_7 . V_26 : L_4 ) ;
}
F_8 ( V_63 , V_64 , L_42 ,
V_1 -> V_7 . V_27 == V_28 ? L_22 :
V_1 -> V_7 . V_27 == V_70 ? L_23 :
L_18 ) ;
if ( V_1 -> V_7 . V_27 == V_70 ) {
F_8 ( V_63 , V_64 , L_43 , V_1 -> V_7 . V_29 ? V_1 -> V_7 . V_29 : L_4 ) ;
F_8 ( V_63 , V_64 , L_44 ) ;
}
F_8 ( V_63 , V_64 , L_45 , V_1 -> V_7 . V_31 ) ;
F_8 ( V_63 , V_64 , L_46 , V_1 -> V_7 . V_32 ) ;
F_8 ( V_63 , V_64 , L_47 , V_1 -> V_7 . V_33 ) ;
#endif
#ifdef F_5
F_8 ( V_63 , V_64 , L_48 , V_1 -> V_7 . V_34 ) ;
F_8 ( V_63 , V_64 , L_49 , V_1 -> V_7 . V_36 ) ;
#endif
F_8 ( V_63 , V_64 , L_50 , V_1 -> V_37 ) ;
F_8 ( V_63 , V_64 , L_51 , ( V_1 -> V_38 ) ? V_1 -> V_38 : L_52 ) ;
F_8 ( V_63 , V_64 , L_53 , V_1 -> V_39 ) ;
F_8 ( V_63 , V_64 , L_54 , ( V_1 -> V_40 ) ? L_55 : L_56 ) ;
F_8 ( V_63 , V_64 , L_57 , V_1 -> V_41 ) ;
F_8 ( V_63 , V_64 , L_58 , V_1 -> V_42 ) ;
F_8 ( V_63 , V_64 , L_59 , V_1 -> V_43 ) ;
F_8 ( V_63 , V_64 , L_60 , V_1 -> V_46 ) ;
F_8 ( V_63 , V_64 , L_61 , V_1 -> V_47 , V_1 -> V_48 ) ;
F_8 ( V_63 , V_64 , L_62 , V_1 -> V_49 , V_1 -> V_50 ) ;
F_8 ( V_63 , V_64 , L_63 , V_1 -> V_52 , V_1 -> V_53 ) ;
F_8 ( V_63 , V_64 , L_64 , V_1 -> V_54 , V_1 -> V_55 ) ;
F_8 ( V_63 , V_64 , L_65 , V_1 -> V_56 , V_1 -> V_57 ) ;
F_8 ( V_63 , V_64 , L_66 , V_1 -> V_58 , V_1 -> V_59 ) ;
}
static T_4
F_10 ( T_1 * V_1 , const char * V_71 )
{
T_5 * V_72 , * V_73 ;
V_73 = strchr ( V_71 , ':' ) ;
if ( V_73 == NULL )
return FALSE ;
V_72 = V_73 ;
* V_72 ++ = '\0' ;
while ( isspace ( ( V_74 ) * V_72 ) )
V_72 ++ ;
if ( * V_72 == '\0' ) {
* V_73 = ':' ;
return FALSE ;
}
if ( strcmp ( V_71 , L_67 ) == 0 ) {
V_1 -> V_58 = TRUE ;
V_1 -> V_59 = F_11 ( V_72 , L_68 ) ;
} else if ( strcmp ( V_71 , L_69 ) == 0 ) {
V_1 -> V_56 = TRUE ;
V_1 -> V_57 = F_11 ( V_72 , L_70 ) ;
} else if ( strcmp ( V_71 , L_71 ) == 0 ) {
V_1 -> V_46 = TRUE ;
V_1 -> V_52 = TRUE ;
V_1 -> V_53 = F_11 ( V_72 , L_72 ) ;
} else {
return FALSE ;
}
* V_73 = ':' ;
return TRUE ;
}
static T_4
F_12 ( T_1 * V_1 , const char * V_75 )
{
T_5 * V_72 = NULL , * V_73 ;
V_73 = strchr ( V_75 , ':' ) ;
if ( V_73 == NULL )
return FALSE ;
V_72 = V_73 ;
* V_72 ++ = '\0' ;
while ( isspace ( ( V_74 ) * V_72 ) )
V_72 ++ ;
if ( * V_72 == '\0' ) {
* V_73 = ':' ;
return FALSE ;
}
if ( strcmp ( V_75 , L_71 ) == 0 ) {
V_1 -> V_49 = TRUE ;
V_1 -> V_50 = F_11 ( V_72 , L_73 ) ;
} else if ( strcmp ( V_75 , L_69 ) == 0 ) {
V_1 -> V_56 = TRUE ;
V_1 -> V_57 = F_11 ( V_72 , L_74 ) ;
} else if ( strcmp ( V_75 , L_67 ) == 0 ) {
V_1 -> V_47 = TRUE ;
V_1 -> V_48 = F_11 ( V_72 , L_75 ) ;
}
* V_73 = ':' ;
return TRUE ;
}
static T_4
F_13 ( T_1 * V_1 , const char * V_75 )
{
T_5 * V_72 = NULL , * V_73 ;
V_73 = strchr ( V_75 , ':' ) ;
if ( V_73 == NULL )
return FALSE ;
V_72 = V_73 ;
* V_72 ++ = '\0' ;
while ( isspace ( ( V_74 ) * V_72 ) )
V_72 ++ ;
if ( * V_72 == '\0' ) {
* V_73 = ':' ;
return FALSE ;
}
if ( strcmp ( V_75 , L_76 ) == 0 ) {
if ( V_1 -> V_2 -> V_66 > 0 ) {
V_3 V_67 ;
V_67 = F_9 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_66 - 1 ) ;
V_1 -> V_2 = F_14 ( V_1 -> V_2 , V_1 -> V_2 -> V_66 - 1 ) ;
V_67 . V_34 = V_76 ;
V_67 . V_36 = F_11 ( V_72 , L_77 ) ;
F_15 ( V_1 -> V_2 , V_67 ) ;
} else {
V_1 -> V_7 . V_34 = V_76 ;
V_1 -> V_7 . V_36 = F_11 ( V_72 , L_77 ) ;
}
} else if ( strcmp ( V_75 , L_78 ) == 0 ) {
if ( V_1 -> V_2 -> V_66 > 0 ) {
V_3 V_67 ;
V_67 = F_9 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_66 - 1 ) ;
V_1 -> V_2 = F_14 ( V_1 -> V_2 , V_1 -> V_2 -> V_66 - 1 ) ;
V_67 . V_34 = V_77 ;
V_67 . V_36 = F_11 ( V_72 , L_79 ) ;
F_15 ( V_1 -> V_2 , V_67 ) ;
} else {
V_1 -> V_7 . V_34 = V_77 ;
V_1 -> V_7 . V_36 = F_11 ( V_72 , L_79 ) ;
}
}
* V_73 = ':' ;
return TRUE ;
}
static T_4
F_16 ( T_1 * V_1 , const char * V_75 )
{
T_5 * V_72 = NULL , * V_73 ;
V_73 = strchr ( V_75 , ':' ) ;
if ( V_73 == NULL )
return FALSE ;
V_72 = V_73 ;
* V_72 ++ = '\0' ;
while ( isspace ( ( V_74 ) * V_72 ) )
V_72 ++ ;
if ( V_1 -> V_2 -> V_66 > 0 ) {
V_3 V_67 ;
V_67 = F_9 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_66 - 1 ) ;
V_1 -> V_2 = F_14 ( V_1 -> V_2 , V_1 -> V_2 -> V_66 - 1 ) ;
V_67 . V_27 = V_70 ;
V_67 . V_29 = F_17 ( V_75 ) ;
V_67 . V_30 = F_17 ( V_72 ) ;
F_15 ( V_1 -> V_2 , V_67 ) ;
} else {
V_1 -> V_7 . V_27 = V_70 ;
V_1 -> V_7 . V_29 = F_17 ( V_75 ) ;
V_1 -> V_7 . V_30 = F_17 ( V_72 ) ;
}
* V_73 = ':' ;
return TRUE ;
}
static int
F_18 ( T_1 * V_1 , const char * V_78 )
{
long V_79 ;
char * V_72 ;
T_6 * V_80 ;
T_7 * V_81 ;
int V_82 ;
T_5 * V_83 ;
V_3 V_67 ;
V_79 = strtol ( V_78 , & V_72 , 10 ) ;
if ( V_72 != NULL && * V_72 == '\0' ) {
if ( V_79 < 0 ) {
F_19 ( L_80 ) ;
return 1 ;
}
if ( V_79 > V_84 ) {
F_19 ( L_81 ,
V_84 ) ;
return 1 ;
}
if ( V_79 == 0 ) {
F_19 ( L_82 ) ;
return 1 ;
}
V_80 = F_20 ( & V_82 , & V_83 , NULL ) ;
if ( V_80 == NULL ) {
switch ( V_82 ) {
case V_85 :
case V_86 :
F_19 ( L_83 , V_83 ) ;
F_21 ( V_83 ) ;
break;
case V_87 :
F_19 ( L_84 ) ;
break;
}
return 2 ;
}
V_81 = ( T_7 * ) F_22 ( V_80 , ( int ) ( V_79 - 1 ) ) ;
if ( V_81 == NULL ) {
F_19 ( L_82 ) ;
return 1 ;
}
V_67 . V_8 = F_17 ( V_81 -> V_8 ) ;
if ( V_81 -> V_88 != NULL ) {
V_67 . V_68 = F_17 ( V_81 -> V_88 ) ;
} else {
V_67 . V_68 = F_17 ( V_81 -> V_8 ) ;
}
F_23 ( V_80 ) ;
} else if ( V_1 -> V_62 ) {
V_67 . V_8 = F_17 ( V_78 ) ;
V_67 . V_68 = F_17 ( V_78 ) ;
} else {
V_80 = F_20 ( & V_82 , NULL , NULL ) ;
if ( V_80 != NULL ) {
T_6 * V_89 ;
T_4 V_90 ;
V_90 = FALSE ;
for ( V_89 = F_24 ( V_80 ) ; V_89 != NULL ;
V_89 = F_25 ( V_89 ) )
{
V_81 = ( T_7 * ) V_89 -> V_91 ;
if ( F_26 ( V_81 -> V_8 , V_78 ) == 0 ) {
V_67 . V_8 = F_17 ( V_81 -> V_8 ) ;
if ( V_81 -> V_88 != NULL ) {
V_67 . V_68 = F_17 ( V_81 -> V_88 ) ;
} else {
V_67 . V_68 = F_17 ( V_81 -> V_8 ) ;
}
V_90 = TRUE ;
break;
}
if ( V_81 -> V_88 != NULL &&
F_26 ( V_81 -> V_88 , V_78 ) == 0 ) {
V_67 . V_8 = F_17 ( V_81 -> V_8 ) ;
V_67 . V_68 = F_17 ( V_81 -> V_88 ) ;
V_90 = TRUE ;
break;
}
}
if ( ! V_90 ) {
T_8 V_92 ;
V_92 = strlen ( V_78 ) ;
for ( V_89 = F_24 ( V_80 ) ; V_89 != NULL ;
V_89 = F_25 ( V_89 ) )
{
V_81 = ( T_7 * ) V_89 -> V_91 ;
if ( V_81 -> V_88 != NULL &&
F_27 ( V_81 -> V_88 , V_78 , V_92 ) == 0 ) {
V_67 . V_8 = F_17 ( V_81 -> V_8 ) ;
V_67 . V_68 = F_17 ( V_81 -> V_88 ) ;
V_90 = TRUE ;
break;
}
}
}
if ( ! V_90 ) {
V_67 . V_8 = F_17 ( V_78 ) ;
V_67 . V_68 = F_17 ( V_78 ) ;
}
F_23 ( V_80 ) ;
} else {
V_67 . V_8 = F_17 ( V_78 ) ;
V_67 . V_68 = F_17 ( V_78 ) ;
}
}
V_67 . V_9 = F_17 ( V_1 -> V_7 . V_9 ) ;
V_67 . V_10 = F_17 ( V_1 -> V_7 . V_10 ) ;
V_67 . V_12 = V_1 -> V_7 . V_12 ;
V_67 . V_11 = V_1 -> V_7 . V_11 ;
V_67 . V_14 = V_1 -> V_7 . V_14 ;
V_67 . V_15 = V_1 -> V_7 . V_15 ;
V_67 . V_16 = V_1 -> V_7 . V_16 ;
#if F_3 ( V_18 ) || F_3 ( V_19 )
V_67 . V_20 = V_1 -> V_7 . V_20 ;
#endif
V_67 . V_22 = V_1 -> V_7 . V_22 ;
#ifdef F_4
V_67 . V_23 = V_1 -> V_7 . V_23 ;
V_67 . V_25 = F_17 ( V_1 -> V_7 . V_25 ) ;
V_67 . V_26 = F_17 ( V_1 -> V_7 . V_26 ) ;
V_67 . V_27 = V_1 -> V_7 . V_27 ;
V_67 . V_29 = F_17 ( V_1 -> V_7 . V_29 ) ;
V_67 . V_30 = F_17 ( V_1 -> V_7 . V_30 ) ;
V_67 . V_31 = V_1 -> V_7 . V_31 ;
V_67 . V_32 = V_1 -> V_7 . V_32 ;
V_67 . V_33 = V_1 -> V_7 . V_33 ;
#endif
#ifdef F_5
V_67 . V_34 = V_1 -> V_7 . V_34 ;
V_67 . V_36 = V_1 -> V_7 . V_36 ;
#endif
F_15 ( V_1 -> V_2 , V_67 ) ;
return 0 ;
}
int
F_28 ( T_1 * V_1 , int V_93 , const char * V_78 , T_4 * V_94 )
{
int V_95 , V_12 ;
switch( V_93 ) {
case V_96 :
if ( V_1 -> V_60 ) {
F_19 ( L_85 ) ;
return 1 ;
}
V_1 -> V_60 = F_17 ( V_78 ) ;
break;
case 'a' :
if ( F_10 ( V_1 , V_78 ) == FALSE ) {
F_19 ( L_86 , V_78 ) ;
return 1 ;
}
break;
#ifdef F_4
case 'A' :
if ( F_16 ( V_1 , V_78 ) == FALSE ) {
F_19 ( L_87 , V_78 ) ;
return 1 ;
}
break;
#endif
case 'b' :
V_1 -> V_46 = TRUE ;
if ( F_12 ( V_1 , V_78 ) == FALSE ) {
F_19 ( L_88 , V_78 ) ;
return 1 ;
}
break;
#if F_3 ( V_18 ) || F_3 ( V_19 )
case 'B' :
if ( V_1 -> V_2 -> V_66 > 0 ) {
V_3 V_67 ;
V_67 = F_9 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_66 - 1 ) ;
V_1 -> V_2 = F_14 ( V_1 -> V_2 , V_1 -> V_2 -> V_66 - 1 ) ;
V_67 . V_20 = F_11 ( V_78 , L_89 ) ;
F_15 ( V_1 -> V_2 , V_67 ) ;
} else {
V_1 -> V_7 . V_20 = F_11 ( V_78 , L_89 ) ;
}
break;
#endif
case 'c' :
V_1 -> V_54 = TRUE ;
V_1 -> V_55 = F_11 ( V_78 , L_90 ) ;
break;
case 'f' :
if ( V_1 -> V_2 -> V_66 > 0 ) {
V_3 V_67 ;
V_67 = F_9 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_66 - 1 ) ;
V_1 -> V_2 = F_14 ( V_1 -> V_2 , V_1 -> V_2 -> V_66 - 1 ) ;
F_21 ( V_67 . V_10 ) ;
V_67 . V_10 = F_17 ( V_78 ) ;
F_15 ( V_1 -> V_2 , V_67 ) ;
} else {
F_21 ( V_1 -> V_7 . V_10 ) ;
V_1 -> V_7 . V_10 = F_17 ( V_78 ) ;
}
break;
case 'g' :
V_1 -> V_39 = TRUE ;
break;
case 'H' :
V_1 -> V_42 = FALSE ;
break;
case 'i' :
V_95 = F_18 ( V_1 , V_78 ) ;
if ( V_95 != 0 ) {
return V_95 ;
}
break;
#ifdef V_19
case 'I' :
if ( V_1 -> V_2 -> V_66 > 0 ) {
V_3 V_67 ;
V_67 = F_9 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_66 - 1 ) ;
V_1 -> V_2 = F_14 ( V_1 -> V_2 , V_1 -> V_2 -> V_66 - 1 ) ;
V_67 . V_22 = TRUE ;
F_15 ( V_1 -> V_2 , V_67 ) ;
} else {
V_1 -> V_7 . V_22 = TRUE ;
}
break;
#endif
case 'k' :
* V_94 = TRUE ;
break;
#ifdef F_5
case 'm' :
if ( F_13 ( V_1 , V_78 ) == FALSE ) {
F_19 ( L_91 , V_78 ) ;
return 1 ;
}
break;
#endif
case 'n' :
V_1 -> V_40 = TRUE ;
break;
case 'p' :
if ( V_1 -> V_2 -> V_66 > 0 ) {
V_3 V_67 ;
V_67 = F_9 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_66 - 1 ) ;
V_1 -> V_2 = F_14 ( V_1 -> V_2 , V_1 -> V_2 -> V_66 - 1 ) ;
V_67 . V_15 = FALSE ;
F_15 ( V_1 -> V_2 , V_67 ) ;
} else {
V_1 -> V_7 . V_15 = FALSE ;
}
break;
case 'P' :
V_1 -> V_40 = FALSE ;
break;
#ifdef F_4
case 'r' :
if ( V_1 -> V_2 -> V_66 > 0 ) {
V_3 V_67 ;
V_67 = F_9 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_66 - 1 ) ;
V_1 -> V_2 = F_14 ( V_1 -> V_2 , V_1 -> V_2 -> V_66 - 1 ) ;
V_67 . V_32 = FALSE ;
F_15 ( V_1 -> V_2 , V_67 ) ;
} else {
V_1 -> V_7 . V_32 = FALSE ;
}
break;
#endif
case 's' :
V_12 = F_29 ( V_78 , L_92 ) ;
if ( V_12 == 0 )
V_12 = V_13 ;
if ( V_1 -> V_2 -> V_66 > 0 ) {
V_3 V_67 ;
V_67 = F_9 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_66 - 1 ) ;
V_1 -> V_2 = F_14 ( V_1 -> V_2 , V_1 -> V_2 -> V_66 - 1 ) ;
V_67 . V_11 = TRUE ;
V_67 . V_12 = V_12 ;
F_15 ( V_1 -> V_2 , V_67 ) ;
} else {
V_1 -> V_7 . V_12 = V_12 ;
V_1 -> V_7 . V_11 = TRUE ;
}
break;
case 'S' :
V_1 -> V_41 = TRUE ;
break;
#ifdef F_4
case 'u' :
if ( V_1 -> V_2 -> V_66 > 0 ) {
V_3 V_67 ;
V_67 = F_9 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_66 - 1 ) ;
V_1 -> V_2 = F_14 ( V_1 -> V_2 , V_1 -> V_2 -> V_66 - 1 ) ;
V_67 . V_31 = TRUE ;
F_15 ( V_1 -> V_2 , V_67 ) ;
} else {
V_1 -> V_7 . V_31 = TRUE ;
}
break;
#endif
case 'w' :
V_1 -> V_37 = TRUE ;
F_21 ( V_1 -> V_38 ) ;
V_1 -> V_38 = F_17 ( V_78 ) ;
V_95 = F_30 ( V_1 -> V_38 , & V_1 -> V_61 ) ;
return V_95 ;
case 'y' :
if ( V_1 -> V_2 -> V_66 > 0 ) {
V_3 V_67 ;
V_67 = F_9 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_66 - 1 ) ;
V_1 -> V_2 = F_14 ( V_1 -> V_2 , V_1 -> V_2 -> V_66 - 1 ) ;
V_67 . V_14 = F_31 ( V_78 ) ;
if ( V_67 . V_14 == - 1 ) {
F_19 ( L_93 ,
V_78 ) ;
return 1 ;
}
F_15 ( V_1 -> V_2 , V_67 ) ;
} else {
V_1 -> V_7 . V_14 = F_31 ( V_78 ) ;
if ( V_1 -> V_7 . V_14 == - 1 ) {
F_19 ( L_93 ,
V_78 ) ;
return 1 ;
}
}
break;
default:
F_32 () ;
}
return 0 ;
}
void
F_33 ( T_9 * V_97 , char * V_8 ,
T_4 V_22 )
{
T_6 * V_98 ;
T_10 * V_99 ;
if ( V_97 -> V_100 )
printf ( L_94 ,
V_8 , V_22 ? L_52 : L_95 ) ;
else
printf ( L_96 , V_8 ) ;
for ( V_98 = V_97 -> V_101 ; V_98 != NULL ;
V_98 = F_25 ( V_98 ) ) {
V_99 = ( T_10 * ) V_98 -> V_91 ;
printf ( L_97 , V_99 -> V_8 ) ;
if ( V_99 -> V_102 != NULL )
printf ( L_98 , V_99 -> V_102 ) ;
else
printf ( L_99 ) ;
printf ( L_100 ) ;
}
}
void
F_34 ( T_6 * V_80 )
{
int V_65 ;
T_6 * V_89 ;
T_7 * V_81 ;
V_65 = 1 ;
for ( V_89 = F_24 ( V_80 ) ; V_89 != NULL ;
V_89 = F_25 ( V_89 ) ) {
V_81 = ( T_7 * ) V_89 -> V_91 ;
printf ( L_101 , V_65 ++ , V_81 -> V_8 ) ;
if ( V_81 -> V_88 != NULL ) {
printf ( L_98 , V_81 -> V_88 ) ;
} else {
if ( V_81 -> V_103 != NULL )
printf ( L_98 , V_81 -> V_103 ) ;
}
printf ( L_100 ) ;
}
}
void
F_35 ( T_1 * V_1 , int V_104 )
{
T_3 V_65 ;
V_3 V_67 ;
if ( V_1 -> V_2 -> V_66 > 0 ) {
for ( V_65 = 0 ; V_65 < V_1 -> V_2 -> V_66 ; V_65 ++ ) {
V_67 = F_9 ( V_1 -> V_2 , V_3 , 0 ) ;
V_1 -> V_2 = F_14 ( V_1 -> V_2 , 0 ) ;
if ( V_67 . V_12 < 1 )
V_67 . V_12 = V_13 ;
else if ( V_67 . V_12 < V_104 )
V_67 . V_12 = V_104 ;
F_15 ( V_1 -> V_2 , V_67 ) ;
}
} else {
if ( V_1 -> V_7 . V_12 < 1 )
V_1 -> V_7 . V_12 = V_13 ;
else if ( V_1 -> V_7 . V_12 < V_104 )
V_1 -> V_7 . V_12 = V_104 ;
}
}
void
F_36 ( T_1 * V_1 )
{
if ( V_1 -> V_50 > V_105 ) {
F_19 ( L_102 , V_1 -> V_50 , V_105 ) ;
V_1 -> V_50 = V_105 ;
} else if ( V_1 -> V_50 > V_106 ) {
F_19 ( L_103 , V_1 -> V_50 ) ;
}
#if V_51 > 0
else if ( V_1 -> V_50 < V_51 )
F_19 ( L_104 , V_1 -> V_50 , V_51 ) ;
V_1 -> V_50 = V_51 ;
#endif
}
int
F_37 ( T_1 * V_1 ,
const char * V_107 )
{
int V_95 ;
if ( V_1 -> V_6 != 0 || V_1 -> V_2 -> V_66 != 0 ) {
return 0 ;
}
if ( V_107 != NULL ) {
V_95 = F_18 ( V_1 , V_107 ) ;
return V_95 ;
}
return F_18 ( V_1 , L_105 ) ;
}
static int
F_38 ( const char * V_108 )
{
T_11 V_109 ;
if ( F_39 ( V_108 , & V_109 ) < 0 )
return V_110 ;
if ( F_40 ( V_109 . V_111 ) )
return V_112 ;
else
return 0 ;
}
static T_4
F_30 ( const char * V_38 , T_4 * V_113 )
{
int V_82 ;
* V_113 = FALSE ;
if ( V_38 != NULL ) {
if ( strcmp ( V_38 , L_106 ) == 0 ) {
* V_113 = TRUE ;
} else {
V_82 = F_38 ( V_38 ) ;
switch ( V_82 ) {
case V_114 :
case 0 :
break;
case V_112 :
* V_113 = TRUE ;
break;
default:
break;
}
}
}
return 0 ;
}
void
F_41 ( T_1 * V_1 )
{
T_3 V_65 ;
V_5 V_115 ;
V_3 V_67 ;
for ( V_65 = V_1 -> V_2 -> V_66 ; V_65 != 0 ; V_65 -- ) {
V_67 = F_9 ( V_1 -> V_2 , V_3 , V_65 - 1 ) ;
F_21 ( V_67 . V_8 ) ;
F_21 ( V_67 . V_9 ) ;
if ( V_67 . V_68 != NULL )
F_21 ( V_67 . V_68 ) ;
F_21 ( V_67 . V_10 ) ;
#ifdef F_4
if ( V_67 . V_23 == V_69 ) {
F_21 ( V_67 . V_25 ) ;
F_21 ( V_67 . V_26 ) ;
F_21 ( V_67 . V_29 ) ;
F_21 ( V_67 . V_30 ) ;
}
#endif
V_1 -> V_2 = F_14 ( V_1 -> V_2 , V_65 - 1 ) ;
}
for ( V_65 = 0 ; V_65 < V_1 -> V_4 -> V_66 ; V_65 ++ ) {
V_115 = F_9 ( V_1 -> V_4 , V_5 , V_65 ) ;
if ( ! V_115 . V_116 && V_115 . V_117 ) {
V_67 . V_8 = F_17 ( V_115 . V_8 ) ;
V_67 . V_9 = F_17 ( V_115 . V_118 ) ;
V_67 . V_68 = F_17 ( V_115 . V_8 ) ;
V_67 . V_14 = V_115 . V_119 ;
V_67 . V_10 = F_17 ( V_115 . V_10 ) ;
V_67 . V_12 = V_115 . V_12 ;
V_67 . V_11 = V_115 . V_11 ;
V_67 . V_15 = V_115 . V_120 ;
V_67 . V_16 = V_115 . V_81 . type ;
#if F_3 ( V_18 ) || F_3 ( V_19 )
V_67 . V_20 = V_115 . V_121 ;
#endif
#ifdef V_19
V_67 . V_22 = V_115 . V_122 ;
#endif
#ifdef F_4
V_67 . V_23 = V_69 ;
V_67 . V_25 = F_17 ( V_115 . V_123 . V_124 . V_25 ) ;
V_67 . V_26 = F_17 ( V_115 . V_123 . V_124 . V_26 ) ;
V_67 . V_27 = V_115 . V_123 . V_124 . V_27 ;
V_67 . V_29 = F_17 ( V_115 . V_123 . V_124 . V_29 ) ;
V_67 . V_30 = F_17 ( V_115 . V_123 . V_124 . V_30 ) ;
V_67 . V_31 = V_115 . V_123 . V_124 . V_31 ;
V_67 . V_32 = V_115 . V_123 . V_124 . V_32 ;
V_67 . V_33 = V_115 . V_123 . V_124 . V_33 ;
#endif
#ifdef F_5
V_67 . V_34 = V_115 . V_123 . V_34 ;
V_67 . V_36 = V_115 . V_123 . V_36 ;
#endif
F_15 ( V_1 -> V_2 , V_67 ) ;
} else {
continue;
}
}
}

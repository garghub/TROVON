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
#if F_3 ( V_16 ) || F_3 ( V_17 )
V_1 -> V_7 . V_18 = V_19 ;
#endif
V_1 -> V_7 . V_20 = FALSE ;
#ifdef F_4
V_1 -> V_7 . V_21 = V_22 ;
V_1 -> V_7 . V_23 = NULL ;
V_1 -> V_7 . V_24 = NULL ;
V_1 -> V_7 . V_25 = V_26 ;
V_1 -> V_7 . V_27 = NULL ;
V_1 -> V_7 . V_28 = NULL ;
V_1 -> V_7 . V_29 = FALSE ;
V_1 -> V_7 . V_30 = TRUE ;
V_1 -> V_7 . V_31 = FALSE ;
#endif
#ifdef F_5
V_1 -> V_7 . V_32 = V_33 ;
V_1 -> V_7 . V_34 = 0 ;
#endif
V_1 -> V_35 = FALSE ;
V_1 -> V_36 = NULL ;
V_1 -> V_37 = FALSE ;
#ifdef F_6
V_1 -> V_38 = TRUE ;
#else
V_1 -> V_38 = FALSE ;
#endif
V_1 -> V_39 = TRUE ;
V_1 -> V_40 = TRUE ;
V_1 -> V_41 = getenv ( L_1 ) ? TRUE : FALSE ;
V_1 -> V_42 = FALSE ;
V_1 -> V_43 = FALSE ;
V_1 -> V_44 = FALSE ;
V_1 -> V_45 = 60 ;
V_1 -> V_46 = FALSE ;
V_1 -> V_47 = V_48 ;
V_1 -> V_49 = FALSE ;
V_1 -> V_50 = 1 ;
V_1 -> V_51 = FALSE ;
V_1 -> V_52 = 0 ;
V_1 -> V_53 = FALSE ;
V_1 -> V_54 = 1024 ;
V_1 -> V_55 = FALSE ;
V_1 -> V_56 = 60 ;
V_1 -> V_57 = NULL ;
V_1 -> V_58 = FALSE ;
V_1 -> V_59 = FALSE ;
}
void
F_7 ( const char * V_60 , T_2 V_61 , T_1 * V_1 ) {
T_3 V_62 ;
F_8 ( V_60 , V_61 , L_2 ) ;
for ( V_62 = 0 ; V_62 < V_1 -> V_2 -> V_63 ; V_62 ++ ) {
V_3 V_64 ;
V_64 = F_9 ( V_1 -> V_2 , V_3 , V_62 ) ;
F_8 ( V_60 , V_61 , L_3 , V_62 , V_64 . V_8 ? V_64 . V_8 : L_4 ) ;
F_8 ( V_60 , V_61 , L_5 , V_62 , V_64 . V_9 ? V_64 . V_9 : L_4 ) ;
F_8 ( V_60 , V_61 , L_6 , V_62 , V_64 . V_65 ? V_64 . V_65 : L_4 ) ;
F_8 ( V_60 , V_61 , L_7 , V_62 , V_64 . V_10 ? V_64 . V_10 : L_4 ) ;
F_8 ( V_60 , V_61 , L_8 , V_62 , V_64 . V_11 , V_64 . V_12 ) ;
F_8 ( V_60 , V_61 , L_9 , V_62 , V_64 . V_14 ) ;
F_8 ( V_60 , V_61 , L_10 , V_62 , V_64 . V_15 ? L_11 : L_12 ) ;
#if F_3 ( V_16 ) || F_3 ( V_17 )
F_8 ( V_60 , V_61 , L_13 , V_62 , V_64 . V_18 ) ;
#endif
F_8 ( V_60 , V_61 , L_14 , V_62 , V_64 . V_20 ? L_11 : L_12 ) ;
#ifdef F_4
F_8 ( V_60 , V_61 , L_15 , V_62 ,
V_64 . V_21 == V_22 ? L_16 :
V_64 . V_21 == V_66 ? L_17 :
L_18 ) ;
if ( V_64 . V_21 == V_66 ) {
F_8 ( V_60 , V_61 , L_19 , V_62 , V_64 . V_23 ? V_64 . V_23 : L_4 ) ;
F_8 ( V_60 , V_61 , L_20 , V_62 , V_64 . V_24 ? V_64 . V_24 : L_4 ) ;
}
F_8 ( V_60 , V_61 , L_21 , V_62 ,
V_64 . V_25 == V_26 ? L_22 :
V_64 . V_25 == V_67 ? L_23 :
L_18 ) ;
if ( V_64 . V_25 == V_67 ) {
F_8 ( V_60 , V_61 , L_24 , V_62 , V_64 . V_27 ? V_64 . V_27 : L_4 ) ;
F_8 ( V_60 , V_61 , L_25 , V_62 ) ;
}
F_8 ( V_60 , V_61 , L_26 , V_62 , V_64 . V_29 ) ;
F_8 ( V_60 , V_61 , L_27 , V_62 , V_64 . V_30 ) ;
F_8 ( V_60 , V_61 , L_28 , V_62 , V_64 . V_31 ) ;
#endif
#ifdef F_5
F_8 ( V_60 , V_61 , L_29 , V_62 , V_64 . V_32 ) ;
F_8 ( V_60 , V_61 , L_30 , V_62 , V_64 . V_34 ) ;
#endif
}
F_8 ( V_60 , V_61 , L_31 , V_1 -> V_7 . V_8 ? V_1 -> V_7 . V_8 : L_4 ) ;
F_8 ( V_60 , V_61 , L_32 , V_1 -> V_7 . V_9 ? V_1 -> V_7 . V_9 : L_4 ) ;
F_8 ( V_60 , V_61 , L_33 , V_1 -> V_7 . V_10 ? V_1 -> V_7 . V_10 : L_4 ) ;
F_8 ( V_60 , V_61 , L_34 , V_1 -> V_7 . V_11 , V_1 -> V_7 . V_12 ) ;
F_8 ( V_60 , V_61 , L_35 , V_1 -> V_7 . V_14 ) ;
F_8 ( V_60 , V_61 , L_36 , V_1 -> V_7 . V_15 ? L_11 : L_12 ) ;
#if F_3 ( V_16 ) || F_3 ( V_17 )
F_8 ( V_60 , V_61 , L_37 , V_1 -> V_7 . V_18 ) ;
#endif
F_8 ( V_60 , V_61 , L_38 , V_1 -> V_7 . V_20 ? L_11 : L_12 ) ;
#ifdef F_4
F_8 ( V_60 , V_61 , L_39 ,
V_1 -> V_7 . V_21 == V_22 ? L_16 :
V_1 -> V_7 . V_21 == V_66 ? L_17 :
L_18 ) ;
if ( V_1 -> V_7 . V_21 == V_66 ) {
F_8 ( V_60 , V_61 , L_40 , V_1 -> V_7 . V_23 ? V_1 -> V_7 . V_23 : L_4 ) ;
F_8 ( V_60 , V_61 , L_41 , V_1 -> V_7 . V_24 ? V_1 -> V_7 . V_24 : L_4 ) ;
}
F_8 ( V_60 , V_61 , L_42 ,
V_1 -> V_7 . V_25 == V_26 ? L_22 :
V_1 -> V_7 . V_25 == V_67 ? L_23 :
L_18 ) ;
if ( V_1 -> V_7 . V_25 == V_67 ) {
F_8 ( V_60 , V_61 , L_43 , V_1 -> V_7 . V_27 ? V_1 -> V_7 . V_27 : L_4 ) ;
F_8 ( V_60 , V_61 , L_44 ) ;
}
F_8 ( V_60 , V_61 , L_45 , V_1 -> V_7 . V_29 ) ;
F_8 ( V_60 , V_61 , L_46 , V_1 -> V_7 . V_30 ) ;
F_8 ( V_60 , V_61 , L_47 , V_1 -> V_7 . V_31 ) ;
#endif
#ifdef F_5
F_8 ( V_60 , V_61 , L_48 , V_1 -> V_7 . V_32 ) ;
F_8 ( V_60 , V_61 , L_49 , V_1 -> V_7 . V_34 ) ;
#endif
F_8 ( V_60 , V_61 , L_50 , V_1 -> V_35 ) ;
F_8 ( V_60 , V_61 , L_51 , ( V_1 -> V_36 ) ? V_1 -> V_36 : L_52 ) ;
F_8 ( V_60 , V_61 , L_53 , V_1 -> V_37 ) ;
F_8 ( V_60 , V_61 , L_54 , ( V_1 -> V_38 ) ? L_55 : L_56 ) ;
F_8 ( V_60 , V_61 , L_57 , V_1 -> V_39 ) ;
F_8 ( V_60 , V_61 , L_58 , V_1 -> V_40 ) ;
F_8 ( V_60 , V_61 , L_59 , V_1 -> V_41 ) ;
F_8 ( V_60 , V_61 , L_60 , V_1 -> V_43 ) ;
F_8 ( V_60 , V_61 , L_61 , V_1 -> V_44 , V_1 -> V_45 ) ;
F_8 ( V_60 , V_61 , L_62 , V_1 -> V_46 , V_1 -> V_47 ) ;
F_8 ( V_60 , V_61 , L_63 , V_1 -> V_49 , V_1 -> V_50 ) ;
F_8 ( V_60 , V_61 , L_64 , V_1 -> V_51 , V_1 -> V_52 ) ;
F_8 ( V_60 , V_61 , L_65 , V_1 -> V_53 , V_1 -> V_54 ) ;
F_8 ( V_60 , V_61 , L_66 , V_1 -> V_55 , V_1 -> V_56 ) ;
}
static T_4
F_10 ( T_1 * V_1 , const char * V_68 )
{
T_5 * V_69 , * V_70 ;
V_70 = strchr ( V_68 , ':' ) ;
if ( V_70 == NULL )
return FALSE ;
V_69 = V_70 ;
* V_69 ++ = '\0' ;
while ( isspace ( ( V_71 ) * V_69 ) )
V_69 ++ ;
if ( * V_69 == '\0' ) {
* V_70 = ':' ;
return FALSE ;
}
if ( strcmp ( V_68 , L_67 ) == 0 ) {
V_1 -> V_55 = TRUE ;
V_1 -> V_56 = F_11 ( V_69 , L_68 ) ;
} else if ( strcmp ( V_68 , L_69 ) == 0 ) {
V_1 -> V_53 = TRUE ;
V_1 -> V_54 = F_11 ( V_69 , L_70 ) ;
} else if ( strcmp ( V_68 , L_71 ) == 0 ) {
V_1 -> V_43 = TRUE ;
V_1 -> V_49 = TRUE ;
V_1 -> V_50 = F_11 ( V_69 , L_72 ) ;
} else {
return FALSE ;
}
* V_70 = ':' ;
return TRUE ;
}
static T_4
F_12 ( T_1 * V_1 , const char * V_72 )
{
T_5 * V_69 = NULL , * V_70 ;
V_70 = strchr ( V_72 , ':' ) ;
if ( V_70 == NULL )
return FALSE ;
V_69 = V_70 ;
* V_69 ++ = '\0' ;
while ( isspace ( ( V_71 ) * V_69 ) )
V_69 ++ ;
if ( * V_69 == '\0' ) {
* V_70 = ':' ;
return FALSE ;
}
if ( strcmp ( V_72 , L_71 ) == 0 ) {
V_1 -> V_46 = TRUE ;
V_1 -> V_47 = F_11 ( V_69 , L_73 ) ;
} else if ( strcmp ( V_72 , L_69 ) == 0 ) {
V_1 -> V_53 = TRUE ;
V_1 -> V_54 = F_11 ( V_69 , L_74 ) ;
} else if ( strcmp ( V_72 , L_67 ) == 0 ) {
V_1 -> V_44 = TRUE ;
V_1 -> V_45 = F_11 ( V_69 , L_75 ) ;
}
* V_70 = ':' ;
return TRUE ;
}
static T_4
F_13 ( T_1 * V_1 , const char * V_72 )
{
T_5 * V_69 = NULL , * V_70 ;
V_70 = strchr ( V_72 , ':' ) ;
if ( V_70 == NULL )
return FALSE ;
V_69 = V_70 ;
* V_69 ++ = '\0' ;
while ( isspace ( ( V_71 ) * V_69 ) )
V_69 ++ ;
if ( * V_69 == '\0' ) {
* V_70 = ':' ;
return FALSE ;
}
if ( strcmp ( V_72 , L_76 ) == 0 ) {
if ( V_1 -> V_2 -> V_63 > 0 ) {
V_3 V_64 ;
V_64 = F_9 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_63 - 1 ) ;
V_1 -> V_2 = F_14 ( V_1 -> V_2 , V_1 -> V_2 -> V_63 - 1 ) ;
V_64 . V_32 = V_73 ;
V_64 . V_34 = F_11 ( V_69 , L_77 ) ;
F_15 ( V_1 -> V_2 , V_64 ) ;
} else {
V_1 -> V_7 . V_32 = V_73 ;
V_1 -> V_7 . V_34 = F_11 ( V_69 , L_77 ) ;
}
} else if ( strcmp ( V_72 , L_78 ) == 0 ) {
if ( V_1 -> V_2 -> V_63 > 0 ) {
V_3 V_64 ;
V_64 = F_9 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_63 - 1 ) ;
V_1 -> V_2 = F_14 ( V_1 -> V_2 , V_1 -> V_2 -> V_63 - 1 ) ;
V_64 . V_32 = V_74 ;
V_64 . V_34 = F_11 ( V_69 , L_79 ) ;
F_15 ( V_1 -> V_2 , V_64 ) ;
} else {
V_1 -> V_7 . V_32 = V_74 ;
V_1 -> V_7 . V_34 = F_11 ( V_69 , L_79 ) ;
}
}
* V_70 = ':' ;
return TRUE ;
}
static T_4
F_16 ( T_1 * V_1 , const char * V_72 )
{
T_5 * V_69 = NULL , * V_70 ;
V_70 = strchr ( V_72 , ':' ) ;
if ( V_70 == NULL )
return FALSE ;
V_69 = V_70 ;
* V_69 ++ = '\0' ;
while ( isspace ( ( V_71 ) * V_69 ) )
V_69 ++ ;
if ( V_1 -> V_2 -> V_63 > 0 ) {
V_3 V_64 ;
V_64 = F_9 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_63 - 1 ) ;
V_1 -> V_2 = F_14 ( V_1 -> V_2 , V_1 -> V_2 -> V_63 - 1 ) ;
V_64 . V_25 = V_67 ;
V_64 . V_27 = F_17 ( V_72 ) ;
V_64 . V_28 = F_17 ( V_69 ) ;
F_15 ( V_1 -> V_2 , V_64 ) ;
} else {
V_1 -> V_7 . V_25 = V_67 ;
V_1 -> V_7 . V_27 = F_17 ( V_72 ) ;
V_1 -> V_7 . V_28 = F_17 ( V_69 ) ;
}
* V_70 = ':' ;
return TRUE ;
}
static int
F_18 ( T_1 * V_1 , const char * V_75 )
{
long V_76 ;
char * V_69 ;
T_6 * V_77 ;
T_7 * V_78 ;
int V_79 ;
T_5 * V_80 ;
V_3 V_64 ;
V_76 = strtol ( V_75 , & V_69 , 10 ) ;
if ( V_69 != NULL && * V_69 == '\0' ) {
if ( V_76 < 0 ) {
F_19 ( L_80 ) ;
return 1 ;
}
if ( V_76 > V_81 ) {
F_19 ( L_81 ,
V_81 ) ;
return 1 ;
}
if ( V_76 == 0 ) {
F_19 ( L_82 ) ;
return 1 ;
}
V_77 = F_20 ( & V_79 , & V_80 , NULL ) ;
if ( V_77 == NULL ) {
switch ( V_79 ) {
case V_82 :
case V_83 :
F_19 ( L_83 , V_80 ) ;
F_21 ( V_80 ) ;
break;
case V_84 :
F_19 ( L_84 ) ;
break;
}
return 2 ;
}
V_78 = ( T_7 * ) F_22 ( V_77 , ( int ) ( V_76 - 1 ) ) ;
if ( V_78 == NULL ) {
F_19 ( L_82 ) ;
return 1 ;
}
V_64 . V_8 = F_17 ( V_78 -> V_8 ) ;
if ( V_78 -> V_85 != NULL ) {
V_64 . V_65 = F_17 ( V_78 -> V_85 ) ;
} else {
V_64 . V_65 = F_17 ( V_78 -> V_8 ) ;
}
F_23 ( V_77 ) ;
} else if ( V_1 -> V_59 ) {
V_64 . V_8 = F_17 ( V_75 ) ;
V_64 . V_65 = F_17 ( V_75 ) ;
} else {
V_77 = F_20 ( & V_79 , NULL , NULL ) ;
if ( V_77 != NULL ) {
T_6 * V_86 ;
T_4 V_87 ;
V_87 = FALSE ;
for ( V_86 = F_24 ( V_77 ) ; V_86 != NULL ;
V_86 = F_25 ( V_86 ) )
{
V_78 = ( T_7 * ) V_86 -> V_88 ;
if ( F_26 ( V_78 -> V_8 , V_75 ) == 0 ) {
V_64 . V_8 = F_17 ( V_78 -> V_8 ) ;
if ( V_78 -> V_85 != NULL ) {
V_64 . V_65 = F_17 ( V_78 -> V_85 ) ;
} else {
V_64 . V_65 = F_17 ( V_78 -> V_8 ) ;
}
V_87 = TRUE ;
break;
}
if ( V_78 -> V_85 != NULL &&
F_26 ( V_78 -> V_85 , V_75 ) == 0 ) {
V_64 . V_8 = F_17 ( V_78 -> V_8 ) ;
V_64 . V_65 = F_17 ( V_78 -> V_85 ) ;
V_87 = TRUE ;
break;
}
}
if ( ! V_87 ) {
T_8 V_89 ;
V_89 = strlen ( V_75 ) ;
for ( V_86 = F_24 ( V_77 ) ; V_86 != NULL ;
V_86 = F_25 ( V_86 ) )
{
V_78 = ( T_7 * ) V_86 -> V_88 ;
if ( V_78 -> V_85 != NULL &&
F_27 ( V_78 -> V_85 , V_75 , V_89 ) == 0 ) {
V_64 . V_8 = F_17 ( V_78 -> V_8 ) ;
V_64 . V_65 = F_17 ( V_78 -> V_85 ) ;
V_87 = TRUE ;
break;
}
}
}
if ( ! V_87 ) {
V_64 . V_8 = F_17 ( V_75 ) ;
V_64 . V_65 = F_17 ( V_75 ) ;
}
F_23 ( V_77 ) ;
} else {
V_64 . V_8 = F_17 ( V_75 ) ;
V_64 . V_65 = F_17 ( V_75 ) ;
}
}
V_64 . V_9 = F_17 ( V_1 -> V_7 . V_9 ) ;
V_64 . V_10 = F_17 ( V_1 -> V_7 . V_10 ) ;
V_64 . V_12 = V_1 -> V_7 . V_12 ;
V_64 . V_11 = V_1 -> V_7 . V_11 ;
V_64 . V_14 = V_1 -> V_7 . V_14 ;
V_64 . V_15 = V_1 -> V_7 . V_15 ;
#if F_3 ( V_16 ) || F_3 ( V_17 )
V_64 . V_18 = V_1 -> V_7 . V_18 ;
#endif
V_64 . V_20 = V_1 -> V_7 . V_20 ;
#ifdef F_4
V_64 . V_21 = V_1 -> V_7 . V_21 ;
V_64 . V_23 = F_17 ( V_1 -> V_7 . V_23 ) ;
V_64 . V_24 = F_17 ( V_1 -> V_7 . V_24 ) ;
V_64 . V_25 = V_1 -> V_7 . V_25 ;
V_64 . V_27 = F_17 ( V_1 -> V_7 . V_27 ) ;
V_64 . V_28 = F_17 ( V_1 -> V_7 . V_28 ) ;
V_64 . V_29 = V_1 -> V_7 . V_29 ;
V_64 . V_30 = V_1 -> V_7 . V_30 ;
V_64 . V_31 = V_1 -> V_7 . V_31 ;
#endif
#ifdef F_5
V_64 . V_32 = V_1 -> V_7 . V_32 ;
V_64 . V_34 = V_1 -> V_7 . V_34 ;
#endif
F_15 ( V_1 -> V_2 , V_64 ) ;
return 0 ;
}
int
F_28 ( T_1 * V_1 , int V_90 , const char * V_75 , T_4 * V_91 )
{
int V_92 , V_12 ;
switch( V_90 ) {
case V_93 :
if ( V_1 -> V_57 ) {
F_19 ( L_85 ) ;
return 1 ;
}
V_1 -> V_57 = F_17 ( V_75 ) ;
break;
case 'a' :
if ( F_10 ( V_1 , V_75 ) == FALSE ) {
F_19 ( L_86 , V_75 ) ;
return 1 ;
}
break;
#ifdef F_4
case 'A' :
if ( F_16 ( V_1 , V_75 ) == FALSE ) {
F_19 ( L_87 , V_75 ) ;
return 1 ;
}
break;
#endif
case 'b' :
V_1 -> V_43 = TRUE ;
if ( F_12 ( V_1 , V_75 ) == FALSE ) {
F_19 ( L_88 , V_75 ) ;
return 1 ;
}
break;
#if F_3 ( V_16 ) || F_3 ( V_17 )
case 'B' :
if ( V_1 -> V_2 -> V_63 > 0 ) {
V_3 V_64 ;
V_64 = F_9 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_63 - 1 ) ;
V_1 -> V_2 = F_14 ( V_1 -> V_2 , V_1 -> V_2 -> V_63 - 1 ) ;
V_64 . V_18 = F_11 ( V_75 , L_89 ) ;
F_15 ( V_1 -> V_2 , V_64 ) ;
} else {
V_1 -> V_7 . V_18 = F_11 ( V_75 , L_89 ) ;
}
break;
#endif
case 'c' :
V_1 -> V_51 = TRUE ;
V_1 -> V_52 = F_11 ( V_75 , L_90 ) ;
break;
case 'f' :
if ( V_1 -> V_2 -> V_63 > 0 ) {
V_3 V_64 ;
V_64 = F_9 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_63 - 1 ) ;
V_1 -> V_2 = F_14 ( V_1 -> V_2 , V_1 -> V_2 -> V_63 - 1 ) ;
F_21 ( V_64 . V_10 ) ;
V_64 . V_10 = F_17 ( V_75 ) ;
F_15 ( V_1 -> V_2 , V_64 ) ;
} else {
F_21 ( V_1 -> V_7 . V_10 ) ;
V_1 -> V_7 . V_10 = F_17 ( V_75 ) ;
}
break;
case 'g' :
V_1 -> V_37 = TRUE ;
break;
case 'H' :
V_1 -> V_40 = FALSE ;
break;
case 'i' :
V_92 = F_18 ( V_1 , V_75 ) ;
if ( V_92 != 0 ) {
return V_92 ;
}
break;
#ifdef V_17
case 'I' :
if ( V_1 -> V_2 -> V_63 > 0 ) {
V_3 V_64 ;
V_64 = F_9 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_63 - 1 ) ;
V_1 -> V_2 = F_14 ( V_1 -> V_2 , V_1 -> V_2 -> V_63 - 1 ) ;
V_64 . V_20 = TRUE ;
F_15 ( V_1 -> V_2 , V_64 ) ;
} else {
V_1 -> V_7 . V_20 = TRUE ;
}
break;
#endif
case 'k' :
* V_91 = TRUE ;
break;
#ifdef F_5
case 'm' :
if ( F_13 ( V_1 , V_75 ) == FALSE ) {
F_19 ( L_91 , V_75 ) ;
return 1 ;
}
break;
#endif
case 'n' :
V_1 -> V_38 = TRUE ;
break;
case 'p' :
if ( V_1 -> V_2 -> V_63 > 0 ) {
V_3 V_64 ;
V_64 = F_9 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_63 - 1 ) ;
V_1 -> V_2 = F_14 ( V_1 -> V_2 , V_1 -> V_2 -> V_63 - 1 ) ;
V_64 . V_15 = FALSE ;
F_15 ( V_1 -> V_2 , V_64 ) ;
} else {
V_1 -> V_7 . V_15 = FALSE ;
}
break;
case 'P' :
V_1 -> V_38 = FALSE ;
break;
#ifdef F_4
case 'r' :
if ( V_1 -> V_2 -> V_63 > 0 ) {
V_3 V_64 ;
V_64 = F_9 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_63 - 1 ) ;
V_1 -> V_2 = F_14 ( V_1 -> V_2 , V_1 -> V_2 -> V_63 - 1 ) ;
V_64 . V_30 = FALSE ;
F_15 ( V_1 -> V_2 , V_64 ) ;
} else {
V_1 -> V_7 . V_30 = FALSE ;
}
break;
#endif
case 's' :
V_12 = F_29 ( V_75 , L_92 ) ;
if ( V_12 == 0 )
V_12 = V_13 ;
if ( V_1 -> V_2 -> V_63 > 0 ) {
V_3 V_64 ;
V_64 = F_9 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_63 - 1 ) ;
V_1 -> V_2 = F_14 ( V_1 -> V_2 , V_1 -> V_2 -> V_63 - 1 ) ;
V_64 . V_11 = TRUE ;
V_64 . V_12 = V_12 ;
F_15 ( V_1 -> V_2 , V_64 ) ;
} else {
V_1 -> V_7 . V_12 = V_12 ;
V_1 -> V_7 . V_11 = TRUE ;
}
break;
case 'S' :
V_1 -> V_39 = TRUE ;
break;
#ifdef F_4
case 'u' :
if ( V_1 -> V_2 -> V_63 > 0 ) {
V_3 V_64 ;
V_64 = F_9 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_63 - 1 ) ;
V_1 -> V_2 = F_14 ( V_1 -> V_2 , V_1 -> V_2 -> V_63 - 1 ) ;
V_64 . V_29 = TRUE ;
F_15 ( V_1 -> V_2 , V_64 ) ;
} else {
V_1 -> V_7 . V_29 = TRUE ;
}
break;
#endif
case 'w' :
V_1 -> V_35 = TRUE ;
F_21 ( V_1 -> V_36 ) ;
V_1 -> V_36 = F_17 ( V_75 ) ;
V_92 = F_30 ( V_1 -> V_36 , & V_1 -> V_58 ) ;
return V_92 ;
case 'y' :
if ( V_1 -> V_2 -> V_63 > 0 ) {
V_3 V_64 ;
V_64 = F_9 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_63 - 1 ) ;
V_1 -> V_2 = F_14 ( V_1 -> V_2 , V_1 -> V_2 -> V_63 - 1 ) ;
V_64 . V_14 = F_31 ( V_75 ) ;
if ( V_64 . V_14 == - 1 ) {
F_19 ( L_93 ,
V_75 ) ;
return 1 ;
}
F_15 ( V_1 -> V_2 , V_64 ) ;
} else {
V_1 -> V_7 . V_14 = F_31 ( V_75 ) ;
if ( V_1 -> V_7 . V_14 == - 1 ) {
F_19 ( L_93 ,
V_75 ) ;
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
F_33 ( T_9 * V_94 , char * V_8 ,
T_4 V_20 )
{
T_6 * V_95 ;
T_10 * V_96 ;
if ( V_94 -> V_97 )
printf ( L_94 ,
V_8 , V_20 ? L_52 : L_95 ) ;
else
printf ( L_96 , V_8 ) ;
for ( V_95 = V_94 -> V_98 ; V_95 != NULL ;
V_95 = F_25 ( V_95 ) ) {
V_96 = ( T_10 * ) V_95 -> V_88 ;
printf ( L_97 , V_96 -> V_8 ) ;
if ( V_96 -> V_99 != NULL )
printf ( L_98 , V_96 -> V_99 ) ;
else
printf ( L_99 ) ;
printf ( L_100 ) ;
}
}
void
F_34 ( T_6 * V_77 )
{
int V_62 ;
T_6 * V_86 ;
T_7 * V_78 ;
V_62 = 1 ;
for ( V_86 = F_24 ( V_77 ) ; V_86 != NULL ;
V_86 = F_25 ( V_86 ) ) {
V_78 = ( T_7 * ) V_86 -> V_88 ;
printf ( L_101 , V_62 ++ , V_78 -> V_8 ) ;
if ( V_78 -> V_85 != NULL ) {
printf ( L_98 , V_78 -> V_85 ) ;
} else {
if ( V_78 -> V_100 != NULL )
printf ( L_98 , V_78 -> V_100 ) ;
}
printf ( L_100 ) ;
}
}
void
F_35 ( T_1 * V_1 , int V_101 )
{
T_3 V_62 ;
V_3 V_64 ;
if ( V_1 -> V_2 -> V_63 > 0 ) {
for ( V_62 = 0 ; V_62 < V_1 -> V_2 -> V_63 ; V_62 ++ ) {
V_64 = F_9 ( V_1 -> V_2 , V_3 , 0 ) ;
V_1 -> V_2 = F_14 ( V_1 -> V_2 , 0 ) ;
if ( V_64 . V_12 < 1 )
V_64 . V_12 = V_13 ;
else if ( V_64 . V_12 < V_101 )
V_64 . V_12 = V_101 ;
F_15 ( V_1 -> V_2 , V_64 ) ;
}
} else {
if ( V_1 -> V_7 . V_12 < 1 )
V_1 -> V_7 . V_12 = V_13 ;
else if ( V_1 -> V_7 . V_12 < V_101 )
V_1 -> V_7 . V_12 = V_101 ;
}
}
void
F_36 ( T_1 * V_1 )
{
if ( V_1 -> V_47 > V_102 ) {
F_19 ( L_102 , V_1 -> V_47 , V_102 ) ;
V_1 -> V_47 = V_102 ;
} else if ( V_1 -> V_47 > V_103 ) {
F_19 ( L_103 , V_1 -> V_47 ) ;
}
#if V_48 > 0
else if ( V_1 -> V_47 < V_48 )
F_19 ( L_104 , V_1 -> V_47 , V_48 ) ;
V_1 -> V_47 = V_48 ;
#endif
}
int
F_37 ( T_1 * V_1 ,
const char * V_104 )
{
int V_92 ;
if ( V_1 -> V_6 != 0 || V_1 -> V_2 -> V_63 != 0 ) {
return 0 ;
}
if ( V_104 != NULL ) {
V_92 = F_18 ( V_1 , V_104 ) ;
return V_92 ;
}
return F_18 ( V_1 , L_105 ) ;
}
static int
F_38 ( const char * V_105 )
{
T_11 V_106 ;
if ( F_39 ( V_105 , & V_106 ) < 0 )
return V_107 ;
if ( F_40 ( V_106 . V_108 ) )
return V_109 ;
else
return 0 ;
}
static T_4
F_30 ( const char * V_36 , T_4 * V_110 )
{
int V_79 ;
* V_110 = FALSE ;
if ( V_36 != NULL ) {
if ( strcmp ( V_36 , L_106 ) == 0 ) {
* V_110 = TRUE ;
} else {
V_79 = F_38 ( V_36 ) ;
switch ( V_79 ) {
case V_111 :
case 0 :
break;
case V_109 :
* V_110 = TRUE ;
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
T_3 V_62 ;
V_5 V_112 ;
V_3 V_64 ;
for ( V_62 = V_1 -> V_2 -> V_63 ; V_62 != 0 ; V_62 -- ) {
V_64 = F_9 ( V_1 -> V_2 , V_3 , V_62 - 1 ) ;
F_21 ( V_64 . V_8 ) ;
F_21 ( V_64 . V_9 ) ;
if ( V_64 . V_65 != NULL )
F_21 ( V_64 . V_65 ) ;
F_21 ( V_64 . V_10 ) ;
#ifdef F_4
if ( V_64 . V_21 == V_66 ) {
F_21 ( V_64 . V_23 ) ;
F_21 ( V_64 . V_24 ) ;
F_21 ( V_64 . V_27 ) ;
F_21 ( V_64 . V_28 ) ;
}
#endif
V_1 -> V_2 = F_14 ( V_1 -> V_2 , V_62 - 1 ) ;
}
for ( V_62 = 0 ; V_62 < V_1 -> V_4 -> V_63 ; V_62 ++ ) {
V_112 = F_9 ( V_1 -> V_4 , V_5 , V_62 ) ;
if ( ! V_112 . V_113 && V_112 . V_114 ) {
V_64 . V_8 = F_17 ( V_112 . V_8 ) ;
V_64 . V_9 = F_17 ( V_112 . V_115 ) ;
V_64 . V_65 = F_17 ( V_112 . V_8 ) ;
V_64 . V_14 = V_112 . V_116 ;
V_64 . V_10 = F_17 ( V_112 . V_10 ) ;
V_64 . V_12 = V_112 . V_12 ;
V_64 . V_11 = V_112 . V_11 ;
V_64 . V_15 = V_112 . V_117 ;
#if F_3 ( V_16 ) || F_3 ( V_17 )
V_64 . V_18 = V_112 . V_118 ;
#endif
#ifdef V_17
V_64 . V_20 = V_112 . V_119 ;
#endif
#ifdef F_4
V_64 . V_21 = V_66 ;
V_64 . V_23 = F_17 ( V_112 . V_120 . V_121 . V_23 ) ;
V_64 . V_24 = F_17 ( V_112 . V_120 . V_121 . V_24 ) ;
V_64 . V_25 = V_112 . V_120 . V_121 . V_25 ;
V_64 . V_27 = F_17 ( V_112 . V_120 . V_121 . V_27 ) ;
V_64 . V_28 = F_17 ( V_112 . V_120 . V_121 . V_28 ) ;
V_64 . V_29 = V_112 . V_120 . V_121 . V_29 ;
V_64 . V_30 = V_112 . V_120 . V_121 . V_30 ;
V_64 . V_31 = V_112 . V_120 . V_121 . V_31 ;
#endif
#ifdef F_5
V_64 . V_32 = V_112 . V_120 . V_32 ;
V_64 . V_34 = V_112 . V_120 . V_34 ;
#endif
F_15 ( V_1 -> V_2 , V_64 ) ;
} else {
continue;
}
}
}

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
V_1 -> V_57 = FALSE ;
V_1 -> V_58 = FALSE ;
}
void
F_7 ( const char * V_59 , T_2 V_60 , T_1 * V_1 ) {
T_3 V_61 ;
F_8 ( V_59 , V_60 , L_2 ) ;
for ( V_61 = 0 ; V_61 < V_1 -> V_2 -> V_62 ; V_61 ++ ) {
V_3 V_63 ;
V_63 = F_9 ( V_1 -> V_2 , V_3 , V_61 ) ;
F_8 ( V_59 , V_60 , L_3 , V_61 , V_63 . V_8 ? V_63 . V_8 : L_4 ) ;
F_8 ( V_59 , V_60 , L_5 , V_61 , V_63 . V_9 ? V_63 . V_9 : L_4 ) ;
F_8 ( V_59 , V_60 , L_6 , V_61 , V_63 . V_64 ? V_63 . V_64 : L_4 ) ;
F_8 ( V_59 , V_60 , L_7 , V_61 , V_63 . V_10 ? V_63 . V_10 : L_4 ) ;
F_8 ( V_59 , V_60 , L_8 , V_61 , V_63 . V_11 , V_63 . V_12 ) ;
F_8 ( V_59 , V_60 , L_9 , V_61 , V_63 . V_14 ) ;
F_8 ( V_59 , V_60 , L_10 , V_61 , V_63 . V_15 ? L_11 : L_12 ) ;
#if F_3 ( V_16 ) || F_3 ( V_17 )
F_8 ( V_59 , V_60 , L_13 , V_61 , V_63 . V_18 ) ;
#endif
F_8 ( V_59 , V_60 , L_14 , V_61 , V_63 . V_20 ? L_11 : L_12 ) ;
#ifdef F_4
F_8 ( V_59 , V_60 , L_15 , V_61 ,
V_63 . V_21 == V_22 ? L_16 :
V_63 . V_21 == V_65 ? L_17 :
L_18 ) ;
if ( V_63 . V_21 == V_65 ) {
F_8 ( V_59 , V_60 , L_19 , V_61 , V_63 . V_23 ? V_63 . V_23 : L_4 ) ;
F_8 ( V_59 , V_60 , L_20 , V_61 , V_63 . V_24 ? V_63 . V_24 : L_4 ) ;
}
F_8 ( V_59 , V_60 , L_21 , V_61 ,
V_63 . V_25 == V_26 ? L_22 :
V_63 . V_25 == V_66 ? L_23 :
L_18 ) ;
if ( V_63 . V_25 == V_66 ) {
F_8 ( V_59 , V_60 , L_24 , V_61 , V_63 . V_27 ? V_63 . V_27 : L_4 ) ;
F_8 ( V_59 , V_60 , L_25 , V_61 ) ;
}
F_8 ( V_59 , V_60 , L_26 , V_61 , V_63 . V_29 ) ;
F_8 ( V_59 , V_60 , L_27 , V_61 , V_63 . V_30 ) ;
F_8 ( V_59 , V_60 , L_28 , V_61 , V_63 . V_31 ) ;
#endif
#ifdef F_5
F_8 ( V_59 , V_60 , L_29 , V_61 , V_63 . V_32 ) ;
F_8 ( V_59 , V_60 , L_30 , V_61 , V_63 . V_34 ) ;
#endif
}
F_8 ( V_59 , V_60 , L_31 , V_1 -> V_7 . V_8 ? V_1 -> V_7 . V_8 : L_4 ) ;
F_8 ( V_59 , V_60 , L_32 , V_1 -> V_7 . V_9 ? V_1 -> V_7 . V_9 : L_4 ) ;
F_8 ( V_59 , V_60 , L_33 , V_1 -> V_7 . V_10 ? V_1 -> V_7 . V_10 : L_4 ) ;
F_8 ( V_59 , V_60 , L_34 , V_1 -> V_7 . V_11 , V_1 -> V_7 . V_12 ) ;
F_8 ( V_59 , V_60 , L_35 , V_1 -> V_7 . V_14 ) ;
F_8 ( V_59 , V_60 , L_36 , V_1 -> V_7 . V_15 ? L_11 : L_12 ) ;
#if F_3 ( V_16 ) || F_3 ( V_17 )
F_8 ( V_59 , V_60 , L_37 , V_1 -> V_7 . V_18 ) ;
#endif
F_8 ( V_59 , V_60 , L_38 , V_1 -> V_7 . V_20 ? L_11 : L_12 ) ;
#ifdef F_4
F_8 ( V_59 , V_60 , L_39 ,
V_1 -> V_7 . V_21 == V_22 ? L_16 :
V_1 -> V_7 . V_21 == V_65 ? L_17 :
L_18 ) ;
if ( V_1 -> V_7 . V_21 == V_65 ) {
F_8 ( V_59 , V_60 , L_40 , V_1 -> V_7 . V_23 ? V_1 -> V_7 . V_23 : L_4 ) ;
F_8 ( V_59 , V_60 , L_41 , V_1 -> V_7 . V_24 ? V_1 -> V_7 . V_24 : L_4 ) ;
}
F_8 ( V_59 , V_60 , L_42 ,
V_1 -> V_7 . V_25 == V_26 ? L_22 :
V_1 -> V_7 . V_25 == V_66 ? L_23 :
L_18 ) ;
if ( V_1 -> V_7 . V_25 == V_66 ) {
F_8 ( V_59 , V_60 , L_43 , V_1 -> V_7 . V_27 ? V_1 -> V_7 . V_27 : L_4 ) ;
F_8 ( V_59 , V_60 , L_44 ) ;
}
F_8 ( V_59 , V_60 , L_45 , V_1 -> V_7 . V_29 ) ;
F_8 ( V_59 , V_60 , L_46 , V_1 -> V_7 . V_30 ) ;
F_8 ( V_59 , V_60 , L_47 , V_1 -> V_7 . V_31 ) ;
#endif
#ifdef F_5
F_8 ( V_59 , V_60 , L_48 , V_1 -> V_7 . V_32 ) ;
F_8 ( V_59 , V_60 , L_49 , V_1 -> V_7 . V_34 ) ;
#endif
F_8 ( V_59 , V_60 , L_50 , V_1 -> V_35 ) ;
F_8 ( V_59 , V_60 , L_51 , ( V_1 -> V_36 ) ? V_1 -> V_36 : L_52 ) ;
F_8 ( V_59 , V_60 , L_53 , V_1 -> V_37 ) ;
F_8 ( V_59 , V_60 , L_54 , ( V_1 -> V_38 ) ? L_55 : L_56 ) ;
F_8 ( V_59 , V_60 , L_57 , V_1 -> V_39 ) ;
F_8 ( V_59 , V_60 , L_58 , V_1 -> V_40 ) ;
F_8 ( V_59 , V_60 , L_59 , V_1 -> V_41 ) ;
F_8 ( V_59 , V_60 , L_60 , V_1 -> V_43 ) ;
F_8 ( V_59 , V_60 , L_61 , V_1 -> V_44 , V_1 -> V_45 ) ;
F_8 ( V_59 , V_60 , L_62 , V_1 -> V_46 , V_1 -> V_47 ) ;
F_8 ( V_59 , V_60 , L_63 , V_1 -> V_49 , V_1 -> V_50 ) ;
F_8 ( V_59 , V_60 , L_64 , V_1 -> V_51 , V_1 -> V_52 ) ;
F_8 ( V_59 , V_60 , L_65 , V_1 -> V_53 , V_1 -> V_54 ) ;
F_8 ( V_59 , V_60 , L_66 , V_1 -> V_55 , V_1 -> V_56 ) ;
}
static T_4
F_10 ( T_1 * V_1 , const char * V_67 )
{
T_5 * V_68 , * V_69 ;
V_69 = strchr ( V_67 , ':' ) ;
if ( V_69 == NULL )
return FALSE ;
V_68 = V_69 ;
* V_68 ++ = '\0' ;
while ( isspace ( ( V_70 ) * V_68 ) )
V_68 ++ ;
if ( * V_68 == '\0' ) {
* V_69 = ':' ;
return FALSE ;
}
if ( strcmp ( V_67 , L_67 ) == 0 ) {
V_1 -> V_55 = TRUE ;
V_1 -> V_56 = F_11 ( V_68 , L_68 ) ;
} else if ( strcmp ( V_67 , L_69 ) == 0 ) {
V_1 -> V_53 = TRUE ;
V_1 -> V_54 = F_11 ( V_68 , L_70 ) ;
} else if ( strcmp ( V_67 , L_71 ) == 0 ) {
V_1 -> V_43 = TRUE ;
V_1 -> V_49 = TRUE ;
V_1 -> V_50 = F_11 ( V_68 , L_72 ) ;
} else {
return FALSE ;
}
* V_69 = ':' ;
return TRUE ;
}
static T_4
F_12 ( T_1 * V_1 , const char * V_71 )
{
T_5 * V_68 = NULL , * V_69 ;
V_69 = strchr ( V_71 , ':' ) ;
if ( V_69 == NULL )
return FALSE ;
V_68 = V_69 ;
* V_68 ++ = '\0' ;
while ( isspace ( ( V_70 ) * V_68 ) )
V_68 ++ ;
if ( * V_68 == '\0' ) {
* V_69 = ':' ;
return FALSE ;
}
if ( strcmp ( V_71 , L_71 ) == 0 ) {
V_1 -> V_46 = TRUE ;
V_1 -> V_47 = F_11 ( V_68 , L_73 ) ;
} else if ( strcmp ( V_71 , L_69 ) == 0 ) {
V_1 -> V_53 = TRUE ;
V_1 -> V_54 = F_11 ( V_68 , L_74 ) ;
} else if ( strcmp ( V_71 , L_67 ) == 0 ) {
V_1 -> V_44 = TRUE ;
V_1 -> V_45 = F_11 ( V_68 , L_75 ) ;
}
* V_69 = ':' ;
return TRUE ;
}
static T_4
F_13 ( T_1 * V_1 , const char * V_71 )
{
T_5 * V_68 = NULL , * V_69 ;
V_69 = strchr ( V_71 , ':' ) ;
if ( V_69 == NULL )
return FALSE ;
V_68 = V_69 ;
* V_68 ++ = '\0' ;
while ( isspace ( ( V_70 ) * V_68 ) )
V_68 ++ ;
if ( * V_68 == '\0' ) {
* V_69 = ':' ;
return FALSE ;
}
if ( strcmp ( V_71 , L_76 ) == 0 ) {
if ( V_1 -> V_2 -> V_62 > 0 ) {
V_3 V_63 ;
V_63 = F_9 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_62 - 1 ) ;
V_1 -> V_2 = F_14 ( V_1 -> V_2 , V_1 -> V_2 -> V_62 - 1 ) ;
V_63 . V_32 = V_72 ;
V_63 . V_34 = F_11 ( V_68 , L_77 ) ;
F_15 ( V_1 -> V_2 , V_63 ) ;
} else {
V_1 -> V_7 . V_32 = V_72 ;
V_1 -> V_7 . V_34 = F_11 ( V_68 , L_77 ) ;
}
} else if ( strcmp ( V_71 , L_78 ) == 0 ) {
if ( V_1 -> V_2 -> V_62 > 0 ) {
V_3 V_63 ;
V_63 = F_9 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_62 - 1 ) ;
V_1 -> V_2 = F_14 ( V_1 -> V_2 , V_1 -> V_2 -> V_62 - 1 ) ;
V_63 . V_32 = V_73 ;
V_63 . V_34 = F_11 ( V_68 , L_79 ) ;
F_15 ( V_1 -> V_2 , V_63 ) ;
} else {
V_1 -> V_7 . V_32 = V_73 ;
V_1 -> V_7 . V_34 = F_11 ( V_68 , L_79 ) ;
}
}
* V_69 = ':' ;
return TRUE ;
}
static T_4
F_16 ( T_1 * V_1 , const char * V_71 )
{
T_5 * V_68 = NULL , * V_69 ;
V_69 = strchr ( V_71 , ':' ) ;
if ( V_69 == NULL )
return FALSE ;
V_68 = V_69 ;
* V_68 ++ = '\0' ;
while ( isspace ( ( V_70 ) * V_68 ) )
V_68 ++ ;
if ( V_1 -> V_2 -> V_62 > 0 ) {
V_3 V_63 ;
V_63 = F_9 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_62 - 1 ) ;
V_1 -> V_2 = F_14 ( V_1 -> V_2 , V_1 -> V_2 -> V_62 - 1 ) ;
V_63 . V_25 = V_66 ;
V_63 . V_27 = F_17 ( V_71 ) ;
V_63 . V_28 = F_17 ( V_68 ) ;
F_15 ( V_1 -> V_2 , V_63 ) ;
} else {
V_1 -> V_7 . V_25 = V_66 ;
V_1 -> V_7 . V_27 = F_17 ( V_71 ) ;
V_1 -> V_7 . V_28 = F_17 ( V_68 ) ;
}
* V_69 = ':' ;
return TRUE ;
}
static int
F_18 ( T_1 * V_1 , const char * V_74 )
{
long V_75 ;
char * V_68 ;
T_6 * V_76 ;
T_7 * V_77 ;
int V_78 ;
T_5 * V_79 ;
V_3 V_63 ;
V_75 = strtol ( V_74 , & V_68 , 10 ) ;
if ( V_68 != NULL && * V_68 == '\0' ) {
if ( V_75 < 0 ) {
F_19 ( L_80 ) ;
return 1 ;
}
if ( V_75 > V_80 ) {
F_19 ( L_81 ,
V_80 ) ;
return 1 ;
}
if ( V_75 == 0 ) {
F_19 ( L_82 ) ;
return 1 ;
}
V_76 = F_20 ( & V_78 , & V_79 ) ;
if ( V_76 == NULL ) {
switch ( V_78 ) {
case V_81 :
case V_82 :
F_19 ( L_83 , V_79 ) ;
F_21 ( V_79 ) ;
break;
case V_83 :
F_19 ( L_84 ) ;
break;
}
return 2 ;
}
V_77 = ( T_7 * ) F_22 ( V_76 , ( int ) ( V_75 - 1 ) ) ;
if ( V_77 == NULL ) {
F_19 ( L_82 ) ;
return 1 ;
}
V_63 . V_8 = F_17 ( V_77 -> V_8 ) ;
if ( V_77 -> V_84 != NULL ) {
V_63 . V_64 = F_17 ( V_77 -> V_84 ) ;
} else {
V_63 . V_64 = F_17 ( V_77 -> V_8 ) ;
}
F_23 ( V_76 ) ;
} else if ( V_1 -> V_58 ) {
V_63 . V_8 = F_17 ( V_74 ) ;
V_63 . V_64 = F_17 ( V_74 ) ;
} else {
V_76 = F_20 ( & V_78 , NULL ) ;
if ( V_76 != NULL ) {
T_6 * V_85 ;
T_4 V_86 ;
V_86 = FALSE ;
for ( V_85 = F_24 ( V_76 ) ; V_85 != NULL ;
V_85 = F_25 ( V_85 ) )
{
V_77 = ( T_7 * ) V_85 -> V_87 ;
if ( F_26 ( V_77 -> V_8 , V_74 ) == 0 ) {
V_63 . V_8 = F_17 ( V_77 -> V_8 ) ;
if ( V_77 -> V_84 != NULL ) {
V_63 . V_64 = F_17 ( V_77 -> V_84 ) ;
} else {
V_63 . V_64 = F_17 ( V_77 -> V_8 ) ;
}
V_86 = TRUE ;
break;
}
if ( V_77 -> V_84 != NULL &&
F_26 ( V_77 -> V_84 , V_74 ) == 0 ) {
V_63 . V_8 = F_17 ( V_77 -> V_8 ) ;
V_63 . V_64 = F_17 ( V_77 -> V_84 ) ;
V_86 = TRUE ;
break;
}
}
if ( ! V_86 ) {
T_8 V_88 ;
V_88 = strlen ( V_74 ) ;
for ( V_85 = F_24 ( V_76 ) ; V_85 != NULL ;
V_85 = F_25 ( V_85 ) )
{
V_77 = ( T_7 * ) V_85 -> V_87 ;
if ( V_77 -> V_84 != NULL &&
F_27 ( V_77 -> V_84 , V_74 , V_88 ) == 0 ) {
V_63 . V_8 = F_17 ( V_77 -> V_8 ) ;
V_63 . V_64 = F_17 ( V_77 -> V_84 ) ;
V_86 = TRUE ;
break;
}
}
}
if ( ! V_86 ) {
V_63 . V_8 = F_17 ( V_74 ) ;
V_63 . V_64 = F_17 ( V_74 ) ;
}
F_23 ( V_76 ) ;
} else {
V_63 . V_8 = F_17 ( V_74 ) ;
V_63 . V_64 = F_17 ( V_74 ) ;
}
}
V_63 . V_9 = F_17 ( V_1 -> V_7 . V_9 ) ;
V_63 . V_10 = F_17 ( V_1 -> V_7 . V_10 ) ;
V_63 . V_12 = V_1 -> V_7 . V_12 ;
V_63 . V_11 = V_1 -> V_7 . V_11 ;
V_63 . V_14 = V_1 -> V_7 . V_14 ;
V_63 . V_15 = V_1 -> V_7 . V_15 ;
#if F_3 ( V_16 ) || F_3 ( V_17 )
V_63 . V_18 = V_1 -> V_7 . V_18 ;
#endif
V_63 . V_20 = V_1 -> V_7 . V_20 ;
#ifdef F_4
V_63 . V_21 = V_1 -> V_7 . V_21 ;
V_63 . V_23 = F_17 ( V_1 -> V_7 . V_23 ) ;
V_63 . V_24 = F_17 ( V_1 -> V_7 . V_24 ) ;
V_63 . V_25 = V_1 -> V_7 . V_25 ;
V_63 . V_27 = F_17 ( V_1 -> V_7 . V_27 ) ;
V_63 . V_28 = F_17 ( V_1 -> V_7 . V_28 ) ;
V_63 . V_29 = V_1 -> V_7 . V_29 ;
V_63 . V_30 = V_1 -> V_7 . V_30 ;
V_63 . V_31 = V_1 -> V_7 . V_31 ;
#endif
#ifdef F_5
V_63 . V_32 = V_1 -> V_7 . V_32 ;
V_63 . V_34 = V_1 -> V_7 . V_34 ;
#endif
F_15 ( V_1 -> V_2 , V_63 ) ;
return 0 ;
}
int
F_28 ( T_1 * V_1 , int V_89 , const char * V_74 , T_4 * V_90 )
{
int V_91 , V_12 ;
switch( V_89 ) {
case 'a' :
if ( F_10 ( V_1 , V_74 ) == FALSE ) {
F_19 ( L_85 , V_74 ) ;
return 1 ;
}
break;
#ifdef F_4
case 'A' :
if ( F_16 ( V_1 , V_74 ) == FALSE ) {
F_19 ( L_86 , V_74 ) ;
return 1 ;
}
break;
#endif
case 'b' :
V_1 -> V_43 = TRUE ;
if ( F_12 ( V_1 , V_74 ) == FALSE ) {
F_19 ( L_87 , V_74 ) ;
return 1 ;
}
break;
#if F_3 ( V_16 ) || F_3 ( V_17 )
case 'B' :
if ( V_1 -> V_2 -> V_62 > 0 ) {
V_3 V_63 ;
V_63 = F_9 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_62 - 1 ) ;
V_1 -> V_2 = F_14 ( V_1 -> V_2 , V_1 -> V_2 -> V_62 - 1 ) ;
V_63 . V_18 = F_11 ( V_74 , L_88 ) ;
F_15 ( V_1 -> V_2 , V_63 ) ;
} else {
V_1 -> V_7 . V_18 = F_11 ( V_74 , L_88 ) ;
}
break;
#endif
case 'c' :
V_1 -> V_51 = TRUE ;
V_1 -> V_52 = F_11 ( V_74 , L_89 ) ;
break;
case 'f' :
if ( V_1 -> V_2 -> V_62 > 0 ) {
V_3 V_63 ;
V_63 = F_9 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_62 - 1 ) ;
V_1 -> V_2 = F_14 ( V_1 -> V_2 , V_1 -> V_2 -> V_62 - 1 ) ;
F_21 ( V_63 . V_10 ) ;
V_63 . V_10 = F_17 ( V_74 ) ;
F_15 ( V_1 -> V_2 , V_63 ) ;
} else {
F_21 ( V_1 -> V_7 . V_10 ) ;
V_1 -> V_7 . V_10 = F_17 ( V_74 ) ;
}
break;
case 'g' :
V_1 -> V_37 = TRUE ;
break;
case 'H' :
V_1 -> V_40 = FALSE ;
break;
case 'i' :
V_91 = F_18 ( V_1 , V_74 ) ;
if ( V_91 != 0 ) {
return V_91 ;
}
break;
#ifdef V_17
case 'I' :
if ( V_1 -> V_2 -> V_62 > 0 ) {
V_3 V_63 ;
V_63 = F_9 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_62 - 1 ) ;
V_1 -> V_2 = F_14 ( V_1 -> V_2 , V_1 -> V_2 -> V_62 - 1 ) ;
V_63 . V_20 = TRUE ;
F_15 ( V_1 -> V_2 , V_63 ) ;
} else {
V_1 -> V_7 . V_20 = TRUE ;
}
break;
#endif
case 'k' :
* V_90 = TRUE ;
break;
#ifdef F_5
case 'm' :
if ( F_13 ( V_1 , V_74 ) == FALSE ) {
F_19 ( L_90 , V_74 ) ;
return 1 ;
}
break;
#endif
case 'n' :
V_1 -> V_38 = TRUE ;
break;
case 'p' :
if ( V_1 -> V_2 -> V_62 > 0 ) {
V_3 V_63 ;
V_63 = F_9 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_62 - 1 ) ;
V_1 -> V_2 = F_14 ( V_1 -> V_2 , V_1 -> V_2 -> V_62 - 1 ) ;
V_63 . V_15 = FALSE ;
F_15 ( V_1 -> V_2 , V_63 ) ;
} else {
V_1 -> V_7 . V_15 = FALSE ;
}
break;
case 'P' :
V_1 -> V_38 = FALSE ;
break;
#ifdef F_4
case 'r' :
if ( V_1 -> V_2 -> V_62 > 0 ) {
V_3 V_63 ;
V_63 = F_9 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_62 - 1 ) ;
V_1 -> V_2 = F_14 ( V_1 -> V_2 , V_1 -> V_2 -> V_62 - 1 ) ;
V_63 . V_30 = FALSE ;
F_15 ( V_1 -> V_2 , V_63 ) ;
} else {
V_1 -> V_7 . V_30 = FALSE ;
}
break;
#endif
case 's' :
V_12 = F_29 ( V_74 , L_91 ) ;
if ( V_12 == 0 )
V_12 = V_13 ;
if ( V_1 -> V_2 -> V_62 > 0 ) {
V_3 V_63 ;
V_63 = F_9 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_62 - 1 ) ;
V_1 -> V_2 = F_14 ( V_1 -> V_2 , V_1 -> V_2 -> V_62 - 1 ) ;
V_63 . V_11 = TRUE ;
V_63 . V_12 = V_12 ;
F_15 ( V_1 -> V_2 , V_63 ) ;
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
if ( V_1 -> V_2 -> V_62 > 0 ) {
V_3 V_63 ;
V_63 = F_9 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_62 - 1 ) ;
V_1 -> V_2 = F_14 ( V_1 -> V_2 , V_1 -> V_2 -> V_62 - 1 ) ;
V_63 . V_29 = TRUE ;
F_15 ( V_1 -> V_2 , V_63 ) ;
} else {
V_1 -> V_7 . V_29 = TRUE ;
}
break;
#endif
case 'w' :
V_1 -> V_35 = TRUE ;
F_21 ( V_1 -> V_36 ) ;
V_1 -> V_36 = F_17 ( V_74 ) ;
V_91 = F_30 ( V_1 -> V_36 , & V_1 -> V_57 ) ;
return V_91 ;
case 'y' :
if ( V_1 -> V_2 -> V_62 > 0 ) {
V_3 V_63 ;
V_63 = F_9 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_62 - 1 ) ;
V_1 -> V_2 = F_14 ( V_1 -> V_2 , V_1 -> V_2 -> V_62 - 1 ) ;
V_63 . V_14 = F_31 ( V_74 ) ;
if ( V_63 . V_14 == - 1 ) {
F_19 ( L_92 ,
V_74 ) ;
return 1 ;
}
F_15 ( V_1 -> V_2 , V_63 ) ;
} else {
V_1 -> V_7 . V_14 = F_31 ( V_74 ) ;
if ( V_1 -> V_7 . V_14 == - 1 ) {
F_19 ( L_92 ,
V_74 ) ;
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
F_33 ( T_9 * V_92 , char * V_8 ,
T_4 V_20 )
{
T_6 * V_93 ;
T_10 * V_94 ;
if ( V_92 -> V_95 )
printf ( L_93 ,
V_8 , V_20 ? L_52 : L_94 ) ;
else
printf ( L_95 , V_8 ) ;
for ( V_93 = V_92 -> V_96 ; V_93 != NULL ;
V_93 = F_25 ( V_93 ) ) {
V_94 = ( T_10 * ) V_93 -> V_87 ;
printf ( L_96 , V_94 -> V_8 ) ;
if ( V_94 -> V_97 != NULL )
printf ( L_97 , V_94 -> V_97 ) ;
else
printf ( L_98 ) ;
printf ( L_99 ) ;
}
}
void
F_34 ( T_6 * V_76 )
{
int V_61 ;
T_6 * V_85 ;
T_7 * V_77 ;
V_61 = 1 ;
for ( V_85 = F_24 ( V_76 ) ; V_85 != NULL ;
V_85 = F_25 ( V_85 ) ) {
V_77 = ( T_7 * ) V_85 -> V_87 ;
printf ( L_100 , V_61 ++ , V_77 -> V_8 ) ;
if ( V_77 -> V_84 != NULL ) {
printf ( L_97 , V_77 -> V_84 ) ;
} else {
if ( V_77 -> V_98 != NULL )
printf ( L_97 , V_77 -> V_98 ) ;
}
printf ( L_99 ) ;
}
}
void
F_35 ( T_1 * V_1 , int V_99 )
{
T_3 V_61 ;
V_3 V_63 ;
if ( V_1 -> V_2 -> V_62 > 0 ) {
for ( V_61 = 0 ; V_61 < V_1 -> V_2 -> V_62 ; V_61 ++ ) {
V_63 = F_9 ( V_1 -> V_2 , V_3 , 0 ) ;
V_1 -> V_2 = F_14 ( V_1 -> V_2 , 0 ) ;
if ( V_63 . V_12 < 1 )
V_63 . V_12 = V_13 ;
else if ( V_63 . V_12 < V_99 )
V_63 . V_12 = V_99 ;
F_15 ( V_1 -> V_2 , V_63 ) ;
}
} else {
if ( V_1 -> V_7 . V_12 < 1 )
V_1 -> V_7 . V_12 = V_13 ;
else if ( V_1 -> V_7 . V_12 < V_99 )
V_1 -> V_7 . V_12 = V_99 ;
}
}
void
F_36 ( T_1 * V_1 )
{
if ( V_1 -> V_47 > V_100 ) {
F_19 ( L_101 , V_1 -> V_47 , V_100 ) ;
V_1 -> V_47 = V_100 ;
} else if ( V_1 -> V_47 > V_101 ) {
F_19 ( L_102 , V_1 -> V_47 ) ;
}
#if V_48 > 0
else if ( V_1 -> V_47 < V_48 )
F_19 ( L_103 , V_1 -> V_47 , V_48 ) ;
V_1 -> V_47 = V_48 ;
#endif
}
int
F_37 ( T_1 * V_1 ,
const char * V_102 )
{
int V_91 ;
if ( V_1 -> V_6 != 0 || V_1 -> V_2 -> V_62 != 0 ) {
return 0 ;
}
if ( V_102 != NULL ) {
V_91 = F_18 ( V_1 , V_102 ) ;
return V_91 ;
}
return F_18 ( V_1 , L_104 ) ;
}
static int
F_38 ( const char * V_103 )
{
T_11 V_104 ;
if ( F_39 ( V_103 , & V_104 ) < 0 )
return V_105 ;
if ( F_40 ( V_104 . V_106 ) )
return V_107 ;
else
return 0 ;
}
static T_4
F_30 ( const char * V_36 , T_4 * V_108 )
{
int V_78 ;
* V_108 = FALSE ;
if ( V_36 != NULL ) {
if ( strcmp ( V_36 , L_105 ) == 0 ) {
* V_108 = TRUE ;
} else {
V_78 = F_38 ( V_36 ) ;
switch ( V_78 ) {
case V_109 :
case 0 :
break;
case V_107 :
* V_108 = TRUE ;
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
T_3 V_61 ;
V_5 V_110 ;
V_3 V_63 ;
for ( V_61 = V_1 -> V_2 -> V_62 ; V_61 != 0 ; V_61 -- ) {
V_63 = F_9 ( V_1 -> V_2 , V_3 , V_61 - 1 ) ;
F_21 ( V_63 . V_8 ) ;
F_21 ( V_63 . V_9 ) ;
if ( V_63 . V_64 != NULL )
F_21 ( V_63 . V_64 ) ;
F_21 ( V_63 . V_10 ) ;
#ifdef F_4
if ( V_63 . V_21 == V_65 ) {
F_21 ( V_63 . V_23 ) ;
F_21 ( V_63 . V_24 ) ;
F_21 ( V_63 . V_27 ) ;
F_21 ( V_63 . V_28 ) ;
}
#endif
V_1 -> V_2 = F_14 ( V_1 -> V_2 , V_61 - 1 ) ;
}
for ( V_61 = 0 ; V_61 < V_1 -> V_4 -> V_62 ; V_61 ++ ) {
V_110 = F_9 ( V_1 -> V_4 , V_5 , V_61 ) ;
if ( ! V_110 . V_111 && V_110 . V_112 ) {
V_63 . V_8 = F_17 ( V_110 . V_8 ) ;
V_63 . V_9 = F_17 ( V_110 . V_113 ) ;
V_63 . V_64 = F_17 ( V_110 . V_8 ) ;
V_63 . V_14 = V_110 . V_114 ;
V_63 . V_10 = F_17 ( V_110 . V_10 ) ;
V_63 . V_12 = V_110 . V_12 ;
V_63 . V_11 = V_110 . V_11 ;
V_63 . V_15 = V_110 . V_115 ;
#if F_3 ( V_16 ) || F_3 ( V_17 )
V_63 . V_18 = V_110 . V_116 ;
#endif
#ifdef V_17
V_63 . V_20 = V_110 . V_117 ;
#endif
#ifdef F_4
V_63 . V_21 = V_65 ;
V_63 . V_23 = F_17 ( V_110 . V_118 . V_119 . V_23 ) ;
V_63 . V_24 = F_17 ( V_110 . V_118 . V_119 . V_24 ) ;
V_63 . V_25 = V_110 . V_118 . V_119 . V_25 ;
V_63 . V_27 = F_17 ( V_110 . V_118 . V_119 . V_27 ) ;
V_63 . V_28 = F_17 ( V_110 . V_118 . V_119 . V_28 ) ;
V_63 . V_29 = V_110 . V_118 . V_119 . V_29 ;
V_63 . V_30 = V_110 . V_118 . V_119 . V_30 ;
V_63 . V_31 = V_110 . V_118 . V_119 . V_31 ;
#endif
#ifdef F_5
V_63 . V_32 = V_110 . V_118 . V_32 ;
V_63 . V_34 = V_110 . V_118 . V_34 ;
#endif
F_15 ( V_1 -> V_2 , V_63 ) ;
} else {
continue;
}
}
}

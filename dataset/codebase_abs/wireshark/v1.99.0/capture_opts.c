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
#if F_4 ( V_23 ) || F_4 ( V_24 )
V_1 -> V_7 . V_25 = V_26 ;
#endif
V_1 -> V_7 . V_27 = FALSE ;
#ifdef F_5
V_1 -> V_7 . V_28 = V_29 ;
V_1 -> V_7 . V_30 = NULL ;
V_1 -> V_7 . V_31 = NULL ;
V_1 -> V_7 . V_32 = V_33 ;
V_1 -> V_7 . V_34 = NULL ;
V_1 -> V_7 . V_35 = NULL ;
V_1 -> V_7 . V_36 = FALSE ;
V_1 -> V_7 . V_37 = TRUE ;
V_1 -> V_7 . V_38 = FALSE ;
#endif
#ifdef F_6
V_1 -> V_7 . V_39 = V_40 ;
V_1 -> V_7 . V_41 = 0 ;
#endif
V_1 -> V_42 = FALSE ;
V_1 -> V_43 = NULL ;
V_1 -> V_44 = FALSE ;
#ifdef F_7
V_1 -> V_45 = TRUE ;
#else
V_1 -> V_45 = FALSE ;
#endif
V_1 -> V_46 = TRUE ;
V_1 -> V_47 = TRUE ;
V_1 -> V_48 = getenv ( L_1 ) ? TRUE : FALSE ;
V_1 -> V_49 = FALSE ;
V_1 -> V_50 = NULL ;
V_1 -> V_51 = FALSE ;
V_1 -> V_52 = FALSE ;
V_1 -> V_53 = 60 ;
V_1 -> V_54 = FALSE ;
V_1 -> V_55 = V_56 ;
V_1 -> V_57 = FALSE ;
V_1 -> V_58 = 1 ;
V_1 -> V_59 = FALSE ;
V_1 -> V_60 = 0 ;
V_1 -> V_61 = FALSE ;
V_1 -> V_62 = 1000 ;
V_1 -> V_63 = FALSE ;
V_1 -> V_64 = 60 ;
V_1 -> V_65 = NULL ;
V_1 -> V_66 = FALSE ;
V_1 -> V_67 = FALSE ;
}
void
F_8 ( const char * V_68 , T_2 V_69 , T_1 * V_1 ) {
T_3 V_70 ;
F_9 ( V_68 , V_69 , L_2 ) ;
for ( V_70 = 0 ; V_70 < V_1 -> V_2 -> V_71 ; V_70 ++ ) {
V_3 V_72 ;
V_72 = F_10 ( V_1 -> V_2 , V_3 , V_70 ) ;
F_9 ( V_68 , V_69 , L_3 , V_70 , V_72 . V_8 ? V_72 . V_8 : L_4 ) ;
F_9 ( V_68 , V_69 , L_5 , V_70 , V_72 . V_9 ? V_72 . V_9 : L_4 ) ;
F_9 ( V_68 , V_69 , L_6 , V_70 , V_72 . V_73 ? V_72 . V_73 : L_4 ) ;
F_9 ( V_68 , V_69 , L_7 , V_70 , V_72 . V_10 ? V_72 . V_10 : L_4 ) ;
F_9 ( V_68 , V_69 , L_8 , V_70 , V_72 . V_11 , V_72 . V_12 ) ;
F_9 ( V_68 , V_69 , L_9 , V_70 , V_72 . V_14 ) ;
F_9 ( V_68 , V_69 , L_10 , V_70 , V_72 . V_15 ? L_11 : L_12 ) ;
#ifdef F_3
F_9 ( V_68 , V_69 , L_13 , V_70 , V_72 . V_18 ? V_72 . V_18 : L_4 ) ;
F_9 ( V_68 , V_69 , L_14 , V_70 , V_72 . V_19 ? V_72 . V_19 : L_4 ) ;
F_9 ( V_68 , V_69 , L_15 , V_70 , V_72 . V_21 ) ;
#endif
#if F_4 ( V_23 ) || F_4 ( V_24 )
F_9 ( V_68 , V_69 , L_16 , V_70 , V_72 . V_25 ) ;
#endif
F_9 ( V_68 , V_69 , L_17 , V_70 , V_72 . V_27 ? L_11 : L_12 ) ;
#ifdef F_5
F_9 ( V_68 , V_69 , L_18 , V_70 ,
V_72 . V_28 == V_29 ? L_19 :
V_72 . V_28 == V_74 ? L_20 :
L_21 ) ;
if ( V_72 . V_28 == V_74 ) {
F_9 ( V_68 , V_69 , L_22 , V_70 , V_72 . V_30 ? V_72 . V_30 : L_4 ) ;
F_9 ( V_68 , V_69 , L_23 , V_70 , V_72 . V_31 ? V_72 . V_31 : L_4 ) ;
}
F_9 ( V_68 , V_69 , L_24 , V_70 ,
V_72 . V_32 == V_33 ? L_25 :
V_72 . V_32 == V_75 ? L_26 :
L_21 ) ;
if ( V_72 . V_32 == V_75 ) {
F_9 ( V_68 , V_69 , L_27 , V_70 , V_72 . V_34 ? V_72 . V_34 : L_4 ) ;
F_9 ( V_68 , V_69 , L_28 , V_70 ) ;
}
F_9 ( V_68 , V_69 , L_29 , V_70 , V_72 . V_36 ) ;
F_9 ( V_68 , V_69 , L_30 , V_70 , V_72 . V_37 ) ;
F_9 ( V_68 , V_69 , L_31 , V_70 , V_72 . V_38 ) ;
#endif
#ifdef F_6
F_9 ( V_68 , V_69 , L_32 , V_70 , V_72 . V_39 ) ;
F_9 ( V_68 , V_69 , L_33 , V_70 , V_72 . V_41 ) ;
#endif
}
F_9 ( V_68 , V_69 , L_34 , V_1 -> V_7 . V_8 ? V_1 -> V_7 . V_8 : L_4 ) ;
F_9 ( V_68 , V_69 , L_35 , V_1 -> V_7 . V_9 ? V_1 -> V_7 . V_9 : L_4 ) ;
F_9 ( V_68 , V_69 , L_36 , V_1 -> V_7 . V_10 ? V_1 -> V_7 . V_10 : L_4 ) ;
F_9 ( V_68 , V_69 , L_37 , V_1 -> V_7 . V_11 , V_1 -> V_7 . V_12 ) ;
F_9 ( V_68 , V_69 , L_38 , V_1 -> V_7 . V_14 ) ;
F_9 ( V_68 , V_69 , L_39 , V_1 -> V_7 . V_15 ? L_11 : L_12 ) ;
#ifdef F_3
F_9 ( V_68 , V_69 , L_40 , V_1 -> V_7 . V_18 ? V_1 -> V_7 . V_18 : L_4 ) ;
F_9 ( V_68 , V_69 , L_41 , V_1 -> V_7 . V_19 ? V_1 -> V_7 . V_19 : L_4 ) ;
#endif
#if F_4 ( V_23 ) || F_4 ( V_24 )
F_9 ( V_68 , V_69 , L_42 , V_1 -> V_7 . V_25 ) ;
#endif
F_9 ( V_68 , V_69 , L_43 , V_1 -> V_7 . V_27 ? L_11 : L_12 ) ;
#ifdef F_5
F_9 ( V_68 , V_69 , L_44 ,
V_1 -> V_7 . V_28 == V_29 ? L_19 :
V_1 -> V_7 . V_28 == V_74 ? L_20 :
L_21 ) ;
if ( V_1 -> V_7 . V_28 == V_74 ) {
F_9 ( V_68 , V_69 , L_45 , V_1 -> V_7 . V_30 ? V_1 -> V_7 . V_30 : L_4 ) ;
F_9 ( V_68 , V_69 , L_46 , V_1 -> V_7 . V_31 ? V_1 -> V_7 . V_31 : L_4 ) ;
}
F_9 ( V_68 , V_69 , L_47 ,
V_1 -> V_7 . V_32 == V_33 ? L_25 :
V_1 -> V_7 . V_32 == V_75 ? L_26 :
L_21 ) ;
if ( V_1 -> V_7 . V_32 == V_75 ) {
F_9 ( V_68 , V_69 , L_48 , V_1 -> V_7 . V_34 ? V_1 -> V_7 . V_34 : L_4 ) ;
F_9 ( V_68 , V_69 , L_49 ) ;
}
F_9 ( V_68 , V_69 , L_50 , V_1 -> V_7 . V_36 ) ;
F_9 ( V_68 , V_69 , L_51 , V_1 -> V_7 . V_37 ) ;
F_9 ( V_68 , V_69 , L_52 , V_1 -> V_7 . V_38 ) ;
#endif
#ifdef F_6
F_9 ( V_68 , V_69 , L_53 , V_1 -> V_7 . V_39 ) ;
F_9 ( V_68 , V_69 , L_54 , V_1 -> V_7 . V_41 ) ;
#endif
F_9 ( V_68 , V_69 , L_55 , V_1 -> V_42 ) ;
F_9 ( V_68 , V_69 , L_56 , ( V_1 -> V_43 ) ? V_1 -> V_43 : L_57 ) ;
F_9 ( V_68 , V_69 , L_58 , V_1 -> V_44 ) ;
F_9 ( V_68 , V_69 , L_59 , ( V_1 -> V_45 ) ? L_60 : L_61 ) ;
F_9 ( V_68 , V_69 , L_62 , V_1 -> V_46 ) ;
F_9 ( V_68 , V_69 , L_63 , V_1 -> V_47 ) ;
F_9 ( V_68 , V_69 , L_64 , V_1 -> V_48 ) ;
F_9 ( V_68 , V_69 , L_65 , V_1 -> V_51 ) ;
F_9 ( V_68 , V_69 , L_66 , V_1 -> V_52 , V_1 -> V_53 ) ;
F_9 ( V_68 , V_69 , L_67 , V_1 -> V_54 , V_1 -> V_55 ) ;
F_9 ( V_68 , V_69 , L_68 , V_1 -> V_57 , V_1 -> V_58 ) ;
F_9 ( V_68 , V_69 , L_69 , V_1 -> V_59 , V_1 -> V_60 ) ;
F_9 ( V_68 , V_69 , L_70 , V_1 -> V_61 , V_1 -> V_62 ) ;
F_9 ( V_68 , V_69 , L_71 , V_1 -> V_63 , V_1 -> V_64 ) ;
}
static T_4
F_11 ( T_1 * V_1 , const char * V_76 )
{
T_5 * V_77 , * V_78 ;
V_78 = strchr ( V_76 , ':' ) ;
if ( V_78 == NULL )
return FALSE ;
V_77 = V_78 ;
* V_77 ++ = '\0' ;
while ( isspace ( ( V_79 ) * V_77 ) )
V_77 ++ ;
if ( * V_77 == '\0' ) {
* V_78 = ':' ;
return FALSE ;
}
if ( strcmp ( V_76 , L_72 ) == 0 ) {
V_1 -> V_63 = TRUE ;
V_1 -> V_64 = F_12 ( V_77 , L_73 ) ;
} else if ( strcmp ( V_76 , L_74 ) == 0 ) {
V_1 -> V_61 = TRUE ;
V_1 -> V_62 = F_12 ( V_77 , L_75 ) ;
} else if ( strcmp ( V_76 , L_76 ) == 0 ) {
V_1 -> V_51 = TRUE ;
V_1 -> V_57 = TRUE ;
V_1 -> V_58 = F_12 ( V_77 , L_77 ) ;
} else {
return FALSE ;
}
* V_78 = ':' ;
return TRUE ;
}
static T_4
F_13 ( T_1 * V_1 , const char * V_80 )
{
T_5 * V_77 = NULL , * V_78 ;
V_78 = strchr ( V_80 , ':' ) ;
if ( V_78 == NULL )
return FALSE ;
V_77 = V_78 ;
* V_77 ++ = '\0' ;
while ( isspace ( ( V_79 ) * V_77 ) )
V_77 ++ ;
if ( * V_77 == '\0' ) {
* V_78 = ':' ;
return FALSE ;
}
if ( strcmp ( V_80 , L_76 ) == 0 ) {
V_1 -> V_54 = TRUE ;
V_1 -> V_55 = F_12 ( V_77 , L_78 ) ;
} else if ( strcmp ( V_80 , L_74 ) == 0 ) {
V_1 -> V_61 = TRUE ;
V_1 -> V_62 = F_12 ( V_77 , L_79 ) ;
} else if ( strcmp ( V_80 , L_72 ) == 0 ) {
V_1 -> V_52 = TRUE ;
V_1 -> V_53 = F_12 ( V_77 , L_80 ) ;
}
* V_78 = ':' ;
return TRUE ;
}
static T_4
F_14 ( T_1 * V_1 , const char * V_80 )
{
T_5 * V_77 = NULL , * V_78 ;
V_78 = strchr ( V_80 , ':' ) ;
if ( V_78 == NULL )
return FALSE ;
V_77 = V_78 ;
* V_77 ++ = '\0' ;
while ( isspace ( ( V_79 ) * V_77 ) )
V_77 ++ ;
if ( * V_77 == '\0' ) {
* V_78 = ':' ;
return FALSE ;
}
if ( strcmp ( V_80 , L_81 ) == 0 ) {
if ( V_1 -> V_2 -> V_71 > 0 ) {
V_3 V_72 ;
V_72 = F_10 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_71 - 1 ) ;
V_1 -> V_2 = F_15 ( V_1 -> V_2 , V_1 -> V_2 -> V_71 - 1 ) ;
V_72 . V_39 = V_81 ;
V_72 . V_41 = F_12 ( V_77 , L_82 ) ;
F_16 ( V_1 -> V_2 , V_72 ) ;
} else {
V_1 -> V_7 . V_39 = V_81 ;
V_1 -> V_7 . V_41 = F_12 ( V_77 , L_82 ) ;
}
} else if ( strcmp ( V_80 , L_83 ) == 0 ) {
if ( V_1 -> V_2 -> V_71 > 0 ) {
V_3 V_72 ;
V_72 = F_10 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_71 - 1 ) ;
V_1 -> V_2 = F_15 ( V_1 -> V_2 , V_1 -> V_2 -> V_71 - 1 ) ;
V_72 . V_39 = V_82 ;
V_72 . V_41 = F_12 ( V_77 , L_84 ) ;
F_16 ( V_1 -> V_2 , V_72 ) ;
} else {
V_1 -> V_7 . V_39 = V_82 ;
V_1 -> V_7 . V_41 = F_12 ( V_77 , L_84 ) ;
}
}
* V_78 = ':' ;
return TRUE ;
}
static T_4
F_17 ( T_1 * V_1 , const char * V_80 )
{
T_5 * V_77 = NULL , * V_78 ;
V_78 = strchr ( V_80 , ':' ) ;
if ( V_78 == NULL )
return FALSE ;
V_77 = V_78 ;
* V_77 ++ = '\0' ;
while ( isspace ( ( V_79 ) * V_77 ) )
V_77 ++ ;
if ( V_1 -> V_2 -> V_71 > 0 ) {
V_3 V_72 ;
V_72 = F_10 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_71 - 1 ) ;
V_1 -> V_2 = F_15 ( V_1 -> V_2 , V_1 -> V_2 -> V_71 - 1 ) ;
V_72 . V_32 = V_75 ;
V_72 . V_34 = F_18 ( V_80 ) ;
V_72 . V_35 = F_18 ( V_77 ) ;
F_16 ( V_1 -> V_2 , V_72 ) ;
} else {
V_1 -> V_7 . V_32 = V_75 ;
V_1 -> V_7 . V_34 = F_18 ( V_80 ) ;
V_1 -> V_7 . V_35 = F_18 ( V_77 ) ;
}
* V_78 = ':' ;
return TRUE ;
}
static int
F_19 ( T_1 * V_1 , const char * V_83 )
{
long V_84 ;
char * V_77 ;
T_6 * V_85 ;
T_7 * V_86 ;
int V_87 ;
T_5 * V_88 ;
V_3 V_72 ;
V_84 = strtol ( V_83 , & V_77 , 10 ) ;
if ( V_77 != NULL && * V_77 == '\0' ) {
if ( V_84 < 0 ) {
F_20 ( L_85 ) ;
return 1 ;
}
if ( V_84 > V_89 ) {
F_20 ( L_86 ,
V_89 ) ;
return 1 ;
}
if ( V_84 == 0 ) {
F_20 ( L_87 ) ;
return 1 ;
}
V_85 = F_21 ( & V_87 , & V_88 , NULL ) ;
if ( V_85 == NULL ) {
if ( V_87 == 0 )
F_20 ( L_88 ) ;
else {
F_20 ( L_89 , V_88 ) ;
F_22 ( V_88 ) ;
}
return 2 ;
}
V_86 = ( T_7 * ) F_23 ( V_85 , ( int ) ( V_84 - 1 ) ) ;
if ( V_86 == NULL ) {
F_20 ( L_87 ) ;
return 1 ;
}
V_72 . V_8 = F_18 ( V_86 -> V_8 ) ;
if ( V_86 -> V_90 != NULL ) {
V_72 . V_73 = F_18 ( V_86 -> V_90 ) ;
} else {
V_72 . V_73 = F_18 ( V_86 -> V_8 ) ;
}
F_24 ( V_85 ) ;
} else if ( V_1 -> V_67 ) {
V_72 . V_8 = F_18 ( V_83 ) ;
V_72 . V_73 = F_18 ( V_83 ) ;
} else {
V_85 = F_21 ( & V_87 , NULL , NULL ) ;
if ( V_85 != NULL ) {
T_6 * V_91 ;
T_4 V_92 ;
V_92 = FALSE ;
for ( V_91 = F_25 ( V_85 ) ; V_91 != NULL ;
V_91 = F_26 ( V_91 ) )
{
V_86 = ( T_7 * ) V_91 -> V_93 ;
if ( F_27 ( V_86 -> V_8 , V_83 ) == 0 ) {
V_72 . V_8 = F_18 ( V_86 -> V_8 ) ;
if ( V_86 -> V_90 != NULL ) {
V_72 . V_73 = F_18 ( V_86 -> V_90 ) ;
} else {
V_72 . V_73 = F_18 ( V_86 -> V_8 ) ;
}
V_92 = TRUE ;
break;
}
if ( V_86 -> V_90 != NULL &&
F_27 ( V_86 -> V_90 , V_83 ) == 0 ) {
V_72 . V_8 = F_18 ( V_86 -> V_8 ) ;
V_72 . V_73 = F_18 ( V_86 -> V_90 ) ;
V_92 = TRUE ;
break;
}
}
if ( ! V_92 ) {
T_8 V_94 ;
V_94 = strlen ( V_83 ) ;
for ( V_91 = F_25 ( V_85 ) ; V_91 != NULL ;
V_91 = F_26 ( V_91 ) )
{
V_86 = ( T_7 * ) V_91 -> V_93 ;
if ( V_86 -> V_90 != NULL &&
F_28 ( V_86 -> V_90 , V_83 , V_94 ) == 0 ) {
V_72 . V_8 = F_18 ( V_86 -> V_8 ) ;
V_72 . V_73 = F_18 ( V_86 -> V_90 ) ;
V_92 = TRUE ;
break;
}
}
}
if ( ! V_92 ) {
V_72 . V_8 = F_18 ( V_83 ) ;
V_72 . V_73 = F_18 ( V_83 ) ;
}
F_24 ( V_85 ) ;
} else {
V_72 . V_8 = F_18 ( V_83 ) ;
V_72 . V_73 = F_18 ( V_83 ) ;
}
}
V_72 . V_9 = F_18 ( V_1 -> V_7 . V_9 ) ;
V_72 . V_10 = F_18 ( V_1 -> V_7 . V_10 ) ;
V_72 . V_12 = V_1 -> V_7 . V_12 ;
V_72 . V_11 = V_1 -> V_7 . V_11 ;
V_72 . V_14 = V_1 -> V_7 . V_14 ;
V_72 . V_15 = V_1 -> V_7 . V_15 ;
V_72 . V_16 = V_1 -> V_7 . V_16 ;
#ifdef F_3
V_72 . V_18 = F_18 ( V_1 -> V_7 . V_18 ) ;
V_72 . V_19 = F_18 ( V_1 -> V_7 . V_19 ) ;
V_72 . V_20 = NULL ;
V_72 . V_21 = V_22 ;
#endif
#if F_4 ( V_23 ) || F_4 ( V_24 )
V_72 . V_25 = V_1 -> V_7 . V_25 ;
#endif
V_72 . V_27 = V_1 -> V_7 . V_27 ;
#ifdef F_5
V_72 . V_28 = V_1 -> V_7 . V_28 ;
V_72 . V_30 = F_18 ( V_1 -> V_7 . V_30 ) ;
V_72 . V_31 = F_18 ( V_1 -> V_7 . V_31 ) ;
V_72 . V_32 = V_1 -> V_7 . V_32 ;
V_72 . V_34 = F_18 ( V_1 -> V_7 . V_34 ) ;
V_72 . V_35 = F_18 ( V_1 -> V_7 . V_35 ) ;
V_72 . V_36 = V_1 -> V_7 . V_36 ;
V_72 . V_37 = V_1 -> V_7 . V_37 ;
V_72 . V_38 = V_1 -> V_7 . V_38 ;
#endif
#ifdef F_6
V_72 . V_39 = V_1 -> V_7 . V_39 ;
V_72 . V_41 = V_1 -> V_7 . V_41 ;
#endif
F_16 ( V_1 -> V_2 , V_72 ) ;
return 0 ;
}
int
F_29 ( T_1 * V_1 , int V_95 , const char * V_83 , T_4 * V_96 )
{
int V_97 , V_12 ;
switch( V_95 ) {
case V_98 :
if ( V_1 -> V_65 ) {
F_20 ( L_90 ) ;
return 1 ;
}
V_1 -> V_65 = F_18 ( V_83 ) ;
break;
case 'a' :
if ( F_11 ( V_1 , V_83 ) == FALSE ) {
F_20 ( L_91 , V_83 ) ;
return 1 ;
}
break;
#ifdef F_5
case 'A' :
if ( F_17 ( V_1 , V_83 ) == FALSE ) {
F_20 ( L_92 , V_83 ) ;
return 1 ;
}
break;
#endif
case 'b' :
V_1 -> V_51 = TRUE ;
if ( F_13 ( V_1 , V_83 ) == FALSE ) {
F_20 ( L_93 , V_83 ) ;
return 1 ;
}
break;
#if F_4 ( V_23 ) || F_4 ( V_24 )
case 'B' :
if ( V_1 -> V_2 -> V_71 > 0 ) {
V_3 V_72 ;
V_72 = F_10 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_71 - 1 ) ;
V_1 -> V_2 = F_15 ( V_1 -> V_2 , V_1 -> V_2 -> V_71 - 1 ) ;
V_72 . V_25 = F_12 ( V_83 , L_94 ) ;
F_16 ( V_1 -> V_2 , V_72 ) ;
} else {
V_1 -> V_7 . V_25 = F_12 ( V_83 , L_94 ) ;
}
break;
#endif
case 'c' :
V_1 -> V_59 = TRUE ;
V_1 -> V_60 = F_12 ( V_83 , L_95 ) ;
break;
case 'f' :
if ( V_1 -> V_2 -> V_71 > 0 ) {
V_3 V_72 ;
V_72 = F_10 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_71 - 1 ) ;
V_1 -> V_2 = F_15 ( V_1 -> V_2 , V_1 -> V_2 -> V_71 - 1 ) ;
F_22 ( V_72 . V_10 ) ;
V_72 . V_10 = F_18 ( V_83 ) ;
F_16 ( V_1 -> V_2 , V_72 ) ;
} else {
F_22 ( V_1 -> V_7 . V_10 ) ;
V_1 -> V_7 . V_10 = F_18 ( V_83 ) ;
}
break;
case 'g' :
V_1 -> V_44 = TRUE ;
break;
case 'H' :
V_1 -> V_47 = FALSE ;
break;
case 'i' :
V_97 = F_19 ( V_1 , V_83 ) ;
if ( V_97 != 0 ) {
return V_97 ;
}
break;
#ifdef V_24
case 'I' :
if ( V_1 -> V_2 -> V_71 > 0 ) {
V_3 V_72 ;
V_72 = F_10 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_71 - 1 ) ;
V_1 -> V_2 = F_15 ( V_1 -> V_2 , V_1 -> V_2 -> V_71 - 1 ) ;
V_72 . V_27 = TRUE ;
F_16 ( V_1 -> V_2 , V_72 ) ;
} else {
V_1 -> V_7 . V_27 = TRUE ;
}
break;
#endif
case 'k' :
* V_96 = TRUE ;
break;
#ifdef F_6
case 'm' :
if ( F_14 ( V_1 , V_83 ) == FALSE ) {
F_20 ( L_96 , V_83 ) ;
return 1 ;
}
break;
#endif
case 'n' :
V_1 -> V_45 = TRUE ;
break;
case 'p' :
if ( V_1 -> V_2 -> V_71 > 0 ) {
V_3 V_72 ;
V_72 = F_10 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_71 - 1 ) ;
V_1 -> V_2 = F_15 ( V_1 -> V_2 , V_1 -> V_2 -> V_71 - 1 ) ;
V_72 . V_15 = FALSE ;
F_16 ( V_1 -> V_2 , V_72 ) ;
} else {
V_1 -> V_7 . V_15 = FALSE ;
}
break;
case 'P' :
V_1 -> V_45 = FALSE ;
break;
#ifdef F_5
case 'r' :
if ( V_1 -> V_2 -> V_71 > 0 ) {
V_3 V_72 ;
V_72 = F_10 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_71 - 1 ) ;
V_1 -> V_2 = F_15 ( V_1 -> V_2 , V_1 -> V_2 -> V_71 - 1 ) ;
V_72 . V_37 = FALSE ;
F_16 ( V_1 -> V_2 , V_72 ) ;
} else {
V_1 -> V_7 . V_37 = FALSE ;
}
break;
#endif
case 's' :
V_12 = F_30 ( V_83 , L_97 ) ;
if ( V_12 == 0 )
V_12 = V_13 ;
if ( V_1 -> V_2 -> V_71 > 0 ) {
V_3 V_72 ;
V_72 = F_10 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_71 - 1 ) ;
V_1 -> V_2 = F_15 ( V_1 -> V_2 , V_1 -> V_2 -> V_71 - 1 ) ;
V_72 . V_11 = TRUE ;
V_72 . V_12 = V_12 ;
F_16 ( V_1 -> V_2 , V_72 ) ;
} else {
V_1 -> V_7 . V_12 = V_12 ;
V_1 -> V_7 . V_11 = TRUE ;
}
break;
case 'S' :
V_1 -> V_46 = TRUE ;
break;
#ifdef F_5
case 'u' :
if ( V_1 -> V_2 -> V_71 > 0 ) {
V_3 V_72 ;
V_72 = F_10 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_71 - 1 ) ;
V_1 -> V_2 = F_15 ( V_1 -> V_2 , V_1 -> V_2 -> V_71 - 1 ) ;
V_72 . V_36 = TRUE ;
F_16 ( V_1 -> V_2 , V_72 ) ;
} else {
V_1 -> V_7 . V_36 = TRUE ;
}
break;
#endif
case 'w' :
V_1 -> V_42 = TRUE ;
F_22 ( V_1 -> V_43 ) ;
V_1 -> V_43 = F_18 ( V_83 ) ;
V_97 = F_31 ( V_1 -> V_43 , & V_1 -> V_66 ) ;
return V_97 ;
case 'y' :
if ( V_1 -> V_2 -> V_71 > 0 ) {
V_3 V_72 ;
V_72 = F_10 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_71 - 1 ) ;
V_1 -> V_2 = F_15 ( V_1 -> V_2 , V_1 -> V_2 -> V_71 - 1 ) ;
V_72 . V_14 = F_32 ( V_83 ) ;
if ( V_72 . V_14 == - 1 ) {
F_20 ( L_98 ,
V_83 ) ;
return 1 ;
}
F_16 ( V_1 -> V_2 , V_72 ) ;
} else {
V_1 -> V_7 . V_14 = F_32 ( V_83 ) ;
if ( V_1 -> V_7 . V_14 == - 1 ) {
F_20 ( L_98 ,
V_83 ) ;
return 1 ;
}
}
break;
default:
F_33 () ;
}
return 0 ;
}
void
F_34 ( T_9 * V_99 , char * V_8 ,
T_4 V_27 )
{
T_6 * V_100 ;
T_10 * V_101 ;
if ( V_99 -> V_102 )
printf ( L_99 ,
V_8 , V_27 ? L_57 : L_100 ) ;
else
printf ( L_101 , V_8 ) ;
for ( V_100 = V_99 -> V_103 ; V_100 != NULL ;
V_100 = F_26 ( V_100 ) ) {
V_101 = ( T_10 * ) V_100 -> V_93 ;
printf ( L_102 , V_101 -> V_8 ) ;
if ( V_101 -> V_104 != NULL )
printf ( L_103 , V_101 -> V_104 ) ;
else
printf ( L_104 ) ;
printf ( L_105 ) ;
}
}
void
F_35 ( T_6 * V_85 )
{
int V_70 ;
T_6 * V_91 ;
T_7 * V_86 ;
V_70 = 1 ;
for ( V_91 = F_25 ( V_85 ) ; V_91 != NULL ;
V_91 = F_26 ( V_91 ) ) {
V_86 = ( T_7 * ) V_91 -> V_93 ;
printf ( L_106 , V_70 ++ , V_86 -> V_8 ) ;
if ( V_86 -> V_90 != NULL ) {
printf ( L_103 , V_86 -> V_90 ) ;
} else {
if ( V_86 -> V_105 != NULL )
printf ( L_103 , V_86 -> V_105 ) ;
}
printf ( L_105 ) ;
}
}
void
F_36 ( T_1 * V_1 , int V_106 )
{
T_3 V_70 ;
V_3 V_72 ;
if ( V_1 -> V_2 -> V_71 > 0 ) {
for ( V_70 = 0 ; V_70 < V_1 -> V_2 -> V_71 ; V_70 ++ ) {
V_72 = F_10 ( V_1 -> V_2 , V_3 , 0 ) ;
V_1 -> V_2 = F_15 ( V_1 -> V_2 , 0 ) ;
if ( V_72 . V_12 < 1 )
V_72 . V_12 = V_13 ;
else if ( V_72 . V_12 < V_106 )
V_72 . V_12 = V_106 ;
F_16 ( V_1 -> V_2 , V_72 ) ;
}
} else {
if ( V_1 -> V_7 . V_12 < 1 )
V_1 -> V_7 . V_12 = V_13 ;
else if ( V_1 -> V_7 . V_12 < V_106 )
V_1 -> V_7 . V_12 = V_106 ;
}
}
void
F_37 ( T_1 * V_1 )
{
if ( V_1 -> V_55 > V_107 ) {
F_20 ( L_107 , V_1 -> V_55 , V_107 ) ;
V_1 -> V_55 = V_107 ;
} else if ( V_1 -> V_55 > V_108 ) {
F_20 ( L_108 , V_1 -> V_55 ) ;
}
#if V_56 > 0
else if ( V_1 -> V_55 < V_56 )
F_20 ( L_109 , V_1 -> V_55 , V_56 ) ;
V_1 -> V_55 = V_56 ;
#endif
}
int
F_38 ( T_1 * V_1 ,
const char * V_109 )
{
int V_97 ;
if ( V_1 -> V_6 != 0 || V_1 -> V_2 -> V_71 != 0 ) {
return 0 ;
}
if ( V_109 != NULL ) {
V_97 = F_19 ( V_1 , V_109 ) ;
return V_97 ;
}
return F_19 ( V_1 , L_110 ) ;
}
static int
F_39 ( const char * V_110 )
{
T_11 V_111 ;
if ( F_40 ( V_110 , & V_111 ) < 0 )
return V_112 ;
if ( F_41 ( V_111 . V_113 ) )
return V_114 ;
else
return 0 ;
}
static T_4
F_31 ( const char * V_43 , T_4 * V_115 )
{
int V_87 ;
* V_115 = FALSE ;
if ( V_43 != NULL ) {
if ( strcmp ( V_43 , L_111 ) == 0 ) {
* V_115 = TRUE ;
} else {
V_87 = F_39 ( V_43 ) ;
switch ( V_87 ) {
case V_116 :
case 0 :
break;
case V_114 :
* V_115 = TRUE ;
break;
default:
break;
}
}
}
return 0 ;
}
void
F_42 ( T_1 * V_1 , T_3 V_117 )
{
V_3 V_72 ;
V_72 = F_10 ( V_1 -> V_2 , V_3 , V_117 ) ;
F_22 ( V_72 . V_8 ) ;
F_22 ( V_72 . V_9 ) ;
if ( V_72 . V_73 != NULL )
F_22 ( V_72 . V_73 ) ;
F_22 ( V_72 . V_10 ) ;
#ifdef F_3
F_22 ( V_72 . V_18 ) ;
F_22 ( V_72 . V_19 ) ;
if ( V_72 . V_20 )
F_43 ( V_72 . V_20 ) ;
if ( V_72 . V_21 != V_22 )
F_44 ( V_72 . V_21 ) ;
#endif
#ifdef F_5
if ( V_72 . V_28 == V_74 ) {
F_22 ( V_72 . V_30 ) ;
F_22 ( V_72 . V_31 ) ;
F_22 ( V_72 . V_34 ) ;
F_22 ( V_72 . V_35 ) ;
}
#endif
V_1 -> V_2 = F_15 ( V_1 -> V_2 , V_117 ) ;
}
void
F_45 ( T_1 * V_1 )
{
T_3 V_70 ;
V_5 V_118 ;
V_3 V_72 ;
for ( V_70 = V_1 -> V_2 -> V_71 ; V_70 != 0 ; V_70 -- )
F_42 ( V_1 , V_70 - 1 ) ;
for ( V_70 = 0 ; V_70 < V_1 -> V_4 -> V_71 ; V_70 ++ ) {
V_118 = F_10 ( V_1 -> V_4 , V_5 , V_70 ) ;
if ( ! V_118 . V_119 && V_118 . V_120 ) {
V_72 . V_8 = F_18 ( V_118 . V_8 ) ;
V_72 . V_9 = F_18 ( V_118 . V_121 ) ;
V_72 . V_73 = F_18 ( V_118 . V_8 ) ;
V_72 . V_14 = V_118 . V_122 ;
V_72 . V_10 = F_18 ( V_118 . V_10 ) ;
V_72 . V_12 = V_118 . V_12 ;
V_72 . V_11 = V_118 . V_11 ;
V_72 . V_15 = V_118 . V_123 ;
V_72 . V_16 = V_118 . V_86 . type ;
#ifdef F_3
V_72 . V_18 = F_18 ( V_118 . V_86 . V_18 ) ;
V_72 . V_19 = NULL ;
V_72 . V_20 = V_118 . V_124 ;
V_72 . V_21 = V_22 ;
if ( V_72 . V_20 )
F_46 ( V_72 . V_20 ) ;
#endif
#if F_4 ( V_23 ) || F_4 ( V_24 )
V_72 . V_25 = V_118 . V_125 ;
#endif
#ifdef V_24
V_72 . V_27 = V_118 . V_126 ;
#endif
#ifdef F_5
V_72 . V_28 = V_74 ;
V_72 . V_30 = F_18 ( V_118 . V_127 . V_128 . V_30 ) ;
V_72 . V_31 = F_18 ( V_118 . V_127 . V_128 . V_31 ) ;
V_72 . V_32 = V_118 . V_127 . V_128 . V_32 ;
V_72 . V_34 = F_18 ( V_118 . V_127 . V_128 . V_34 ) ;
V_72 . V_35 = F_18 ( V_118 . V_127 . V_128 . V_35 ) ;
V_72 . V_36 = V_118 . V_127 . V_128 . V_36 ;
V_72 . V_37 = V_118 . V_127 . V_128 . V_37 ;
V_72 . V_38 = V_118 . V_127 . V_128 . V_38 ;
#endif
#ifdef F_6
V_72 . V_39 = V_118 . V_127 . V_39 ;
V_72 . V_41 = V_118 . V_127 . V_41 ;
#endif
F_16 ( V_1 -> V_2 , V_72 ) ;
} else {
continue;
}
}
}

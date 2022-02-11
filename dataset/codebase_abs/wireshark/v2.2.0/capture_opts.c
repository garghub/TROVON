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
V_1 -> V_7 . V_21 = NULL ;
V_1 -> V_7 . V_22 = V_23 ;
#endif
#ifdef F_4
V_1 -> V_7 . V_24 = V_25 ;
#endif
V_1 -> V_7 . V_26 = FALSE ;
#ifdef F_5
V_1 -> V_7 . V_27 = V_28 ;
V_1 -> V_7 . V_29 = NULL ;
V_1 -> V_7 . V_30 = NULL ;
V_1 -> V_7 . V_31 = V_32 ;
V_1 -> V_7 . V_33 = NULL ;
V_1 -> V_7 . V_34 = NULL ;
V_1 -> V_7 . V_35 = FALSE ;
V_1 -> V_7 . V_36 = TRUE ;
V_1 -> V_7 . V_37 = FALSE ;
#endif
#ifdef F_6
V_1 -> V_7 . V_38 = V_39 ;
V_1 -> V_7 . V_40 = 0 ;
#endif
V_1 -> V_41 = FALSE ;
V_1 -> V_42 = NULL ;
V_1 -> V_43 = FALSE ;
#ifdef F_7
V_1 -> V_44 = TRUE ;
#else
V_1 -> V_44 = FALSE ;
#endif
V_1 -> V_45 = TRUE ;
V_1 -> V_46 = TRUE ;
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
F_9 ( V_66 , V_67 , L_1 ) ;
for ( V_68 = 0 ; V_68 < V_1 -> V_2 -> V_69 ; V_68 ++ ) {
V_3 V_70 ;
V_70 = F_10 ( V_1 -> V_2 , V_3 , V_68 ) ;
F_9 ( V_66 , V_67 , L_2 , V_68 , V_70 . V_8 ? V_70 . V_8 : L_3 ) ;
F_9 ( V_66 , V_67 , L_4 , V_68 , V_70 . V_9 ? V_70 . V_9 : L_3 ) ;
F_9 ( V_66 , V_67 , L_5 , V_68 , V_70 . V_71 ? V_70 . V_71 : L_3 ) ;
F_9 ( V_66 , V_67 , L_6 , V_68 , V_70 . V_10 ? V_70 . V_10 : L_3 ) ;
F_9 ( V_66 , V_67 , L_7 , V_68 , V_70 . V_11 , V_70 . V_12 ) ;
F_9 ( V_66 , V_67 , L_8 , V_68 , V_70 . V_14 ) ;
F_9 ( V_66 , V_67 , L_9 , V_68 , V_70 . V_15 ? L_10 : L_11 ) ;
#ifdef F_3
F_9 ( V_66 , V_67 , L_12 , V_68 , V_70 . V_18 ? V_70 . V_18 : L_3 ) ;
F_9 ( V_66 , V_67 , L_13 , V_68 , V_70 . V_19 ? V_70 . V_19 : L_3 ) ;
F_9 ( V_66 , V_67 , L_14 , V_68 , V_70 . V_22 ) ;
#endif
#ifdef F_4
F_9 ( V_66 , V_67 , L_15 , V_68 , V_70 . V_24 ) ;
#endif
F_9 ( V_66 , V_67 , L_16 , V_68 , V_70 . V_26 ? L_10 : L_11 ) ;
#ifdef F_5
F_9 ( V_66 , V_67 , L_17 , V_68 ,
V_70 . V_27 == V_28 ? L_18 :
V_70 . V_27 == V_72 ? L_19 :
L_20 ) ;
if ( V_70 . V_27 == V_72 ) {
F_9 ( V_66 , V_67 , L_21 , V_68 , V_70 . V_29 ? V_70 . V_29 : L_3 ) ;
F_9 ( V_66 , V_67 , L_22 , V_68 , V_70 . V_30 ? V_70 . V_30 : L_3 ) ;
}
F_9 ( V_66 , V_67 , L_23 , V_68 ,
V_70 . V_31 == V_32 ? L_24 :
V_70 . V_31 == V_73 ? L_25 :
L_20 ) ;
if ( V_70 . V_31 == V_73 ) {
F_9 ( V_66 , V_67 , L_26 , V_68 , V_70 . V_33 ? V_70 . V_33 : L_3 ) ;
F_9 ( V_66 , V_67 , L_27 , V_68 ) ;
}
F_9 ( V_66 , V_67 , L_28 , V_68 , V_70 . V_35 ) ;
F_9 ( V_66 , V_67 , L_29 , V_68 , V_70 . V_36 ) ;
F_9 ( V_66 , V_67 , L_30 , V_68 , V_70 . V_37 ) ;
#endif
#ifdef F_6
F_9 ( V_66 , V_67 , L_31 , V_68 , V_70 . V_38 ) ;
F_9 ( V_66 , V_67 , L_32 , V_68 , V_70 . V_40 ) ;
#endif
}
F_9 ( V_66 , V_67 , L_33 , V_1 -> V_7 . V_8 ? V_1 -> V_7 . V_8 : L_3 ) ;
F_9 ( V_66 , V_67 , L_34 , V_1 -> V_7 . V_9 ? V_1 -> V_7 . V_9 : L_3 ) ;
F_9 ( V_66 , V_67 , L_35 , V_1 -> V_7 . V_10 ? V_1 -> V_7 . V_10 : L_3 ) ;
F_9 ( V_66 , V_67 , L_36 , V_1 -> V_7 . V_11 , V_1 -> V_7 . V_12 ) ;
F_9 ( V_66 , V_67 , L_37 , V_1 -> V_7 . V_14 ) ;
F_9 ( V_66 , V_67 , L_38 , V_1 -> V_7 . V_15 ? L_10 : L_11 ) ;
#ifdef F_3
F_9 ( V_66 , V_67 , L_39 , V_1 -> V_7 . V_18 ? V_1 -> V_7 . V_18 : L_3 ) ;
F_9 ( V_66 , V_67 , L_40 , V_1 -> V_7 . V_19 ? V_1 -> V_7 . V_19 : L_3 ) ;
#endif
#ifdef F_4
F_9 ( V_66 , V_67 , L_41 , V_1 -> V_7 . V_24 ) ;
#endif
F_9 ( V_66 , V_67 , L_42 , V_1 -> V_7 . V_26 ? L_10 : L_11 ) ;
#ifdef F_5
F_9 ( V_66 , V_67 , L_43 ,
V_1 -> V_7 . V_27 == V_28 ? L_18 :
V_1 -> V_7 . V_27 == V_72 ? L_19 :
L_20 ) ;
if ( V_1 -> V_7 . V_27 == V_72 ) {
F_9 ( V_66 , V_67 , L_44 , V_1 -> V_7 . V_29 ? V_1 -> V_7 . V_29 : L_3 ) ;
F_9 ( V_66 , V_67 , L_45 , V_1 -> V_7 . V_30 ? V_1 -> V_7 . V_30 : L_3 ) ;
}
F_9 ( V_66 , V_67 , L_46 ,
V_1 -> V_7 . V_31 == V_32 ? L_24 :
V_1 -> V_7 . V_31 == V_73 ? L_25 :
L_20 ) ;
if ( V_1 -> V_7 . V_31 == V_73 ) {
F_9 ( V_66 , V_67 , L_47 , V_1 -> V_7 . V_33 ? V_1 -> V_7 . V_33 : L_3 ) ;
F_9 ( V_66 , V_67 , L_48 ) ;
}
F_9 ( V_66 , V_67 , L_49 , V_1 -> V_7 . V_35 ) ;
F_9 ( V_66 , V_67 , L_50 , V_1 -> V_7 . V_36 ) ;
F_9 ( V_66 , V_67 , L_51 , V_1 -> V_7 . V_37 ) ;
#endif
#ifdef F_6
F_9 ( V_66 , V_67 , L_52 , V_1 -> V_7 . V_38 ) ;
F_9 ( V_66 , V_67 , L_53 , V_1 -> V_7 . V_40 ) ;
#endif
F_9 ( V_66 , V_67 , L_54 , V_1 -> V_41 ) ;
F_9 ( V_66 , V_67 , L_55 , ( V_1 -> V_42 ) ? V_1 -> V_42 : L_56 ) ;
F_9 ( V_66 , V_67 , L_57 , V_1 -> V_43 ) ;
F_9 ( V_66 , V_67 , L_58 , ( V_1 -> V_44 ) ? L_59 : L_60 ) ;
F_9 ( V_66 , V_67 , L_61 , V_1 -> V_45 ) ;
F_9 ( V_66 , V_67 , L_62 , V_1 -> V_46 ) ;
F_9 ( V_66 , V_67 , L_63 , V_1 -> V_49 ) ;
F_9 ( V_66 , V_67 , L_64 , V_1 -> V_50 , V_1 -> V_51 ) ;
F_9 ( V_66 , V_67 , L_65 , V_1 -> V_52 , V_1 -> V_53 ) ;
F_9 ( V_66 , V_67 , L_66 , V_1 -> V_55 , V_1 -> V_56 ) ;
F_9 ( V_66 , V_67 , L_67 , V_1 -> V_57 , V_1 -> V_58 ) ;
F_9 ( V_66 , V_67 , L_68 , V_1 -> V_59 , V_1 -> V_60 ) ;
F_9 ( V_66 , V_67 , L_69 , V_1 -> V_61 , V_1 -> V_62 ) ;
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
if ( strcmp ( V_74 , L_70 ) == 0 ) {
V_1 -> V_61 = TRUE ;
V_1 -> V_62 = F_13 ( V_75 , L_71 ) ;
} else if ( strcmp ( V_74 , L_72 ) == 0 ) {
V_1 -> V_59 = TRUE ;
V_1 -> V_60 = F_13 ( V_75 , L_73 ) ;
} else if ( strcmp ( V_74 , L_74 ) == 0 ) {
V_1 -> V_49 = TRUE ;
V_1 -> V_55 = TRUE ;
V_1 -> V_56 = F_13 ( V_75 , L_75 ) ;
} else {
return FALSE ;
}
* V_76 = ':' ;
return TRUE ;
}
static T_4 F_14 ( T_1 * V_1 , const char * V_77 )
{
char * V_76 ;
char * V_78 ;
char * V_79 = NULL ;
V_76 = strchr ( V_77 , ':' ) ;
if ( V_76 ) {
V_78 = V_76 ;
* V_78 = '\0' ;
V_78 ++ ;
if ( strcmp ( V_77 , L_76 ) == 0 ) {
T_6 * V_80 ;
V_80 = F_15 ( V_81 ) ;
while ( V_80 != NULL ) {
T_7 * V_82 ;
V_82 = ( T_7 * ) V_80 -> V_83 ;
if ( strcmp ( V_78 , V_82 -> V_8 ) == 0 ) {
V_79 = F_16 ( V_82 -> V_84 ) ;
break;
}
V_80 = V_80 -> V_85 ;
}
}
}
if ( V_79 == NULL ) {
if ( V_76 ) {
* V_76 = ':' ;
}
V_79 = F_16 ( V_77 ) ;
}
if ( V_1 -> V_2 -> V_69 > 0 ) {
V_3 V_70 ;
V_70 = F_10 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_69 - 1 ) ;
V_1 -> V_2 = F_17 ( V_1 -> V_2 , V_1 -> V_2 -> V_69 - 1 ) ;
F_18 ( V_70 . V_10 ) ;
V_70 . V_10 = V_79 ;
F_19 ( V_1 -> V_2 , V_70 ) ;
return TRUE ;
}
else {
F_18 ( V_1 -> V_7 . V_10 ) ;
V_1 -> V_7 . V_10 = V_79 ;
return TRUE ;
}
}
static T_4
F_20 ( T_1 * V_1 , const char * V_77 )
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
if ( strcmp ( V_77 , L_74 ) == 0 ) {
V_1 -> V_52 = TRUE ;
V_1 -> V_53 = F_13 ( V_75 , L_77 ) ;
} else if ( strcmp ( V_77 , L_72 ) == 0 ) {
V_1 -> V_59 = TRUE ;
V_1 -> V_60 = F_13 ( V_75 , L_78 ) ;
} else if ( strcmp ( V_77 , L_70 ) == 0 ) {
V_1 -> V_50 = TRUE ;
V_1 -> V_51 = F_13 ( V_75 , L_79 ) ;
}
* V_76 = ':' ;
return TRUE ;
}
static T_4
F_21 ( T_1 * V_1 , const char * V_77 )
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
if ( strcmp ( V_77 , L_80 ) == 0 ) {
if ( V_1 -> V_2 -> V_69 > 0 ) {
V_3 V_70 ;
V_70 = F_10 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_69 - 1 ) ;
V_1 -> V_2 = F_17 ( V_1 -> V_2 , V_1 -> V_2 -> V_69 - 1 ) ;
V_70 . V_38 = V_86 ;
V_70 . V_40 = F_13 ( V_75 , L_81 ) ;
F_19 ( V_1 -> V_2 , V_70 ) ;
} else {
V_1 -> V_7 . V_38 = V_86 ;
V_1 -> V_7 . V_40 = F_13 ( V_75 , L_81 ) ;
}
} else if ( strcmp ( V_77 , L_82 ) == 0 ) {
if ( V_1 -> V_2 -> V_69 > 0 ) {
V_3 V_70 ;
V_70 = F_10 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_69 - 1 ) ;
V_1 -> V_2 = F_17 ( V_1 -> V_2 , V_1 -> V_2 -> V_69 - 1 ) ;
V_70 . V_38 = V_87 ;
V_70 . V_40 = F_13 ( V_75 , L_83 ) ;
F_19 ( V_1 -> V_2 , V_70 ) ;
} else {
V_1 -> V_7 . V_38 = V_87 ;
V_1 -> V_7 . V_40 = F_13 ( V_75 , L_83 ) ;
}
}
* V_76 = ':' ;
return TRUE ;
}
static T_4
F_22 ( T_1 * V_1 , const char * V_77 )
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
V_1 -> V_2 = F_17 ( V_1 -> V_2 , V_1 -> V_2 -> V_69 - 1 ) ;
V_70 . V_31 = V_73 ;
V_70 . V_33 = F_16 ( V_77 ) ;
V_70 . V_34 = F_16 ( V_75 ) ;
F_19 ( V_1 -> V_2 , V_70 ) ;
} else {
V_1 -> V_7 . V_31 = V_73 ;
V_1 -> V_7 . V_33 = F_16 ( V_77 ) ;
V_1 -> V_7 . V_34 = F_16 ( V_75 ) ;
}
* V_76 = ':' ;
return TRUE ;
}
static int
F_23 ( T_1 * V_1 , const char * V_88 )
{
long V_89 ;
char * V_75 ;
T_6 * V_90 ;
T_8 * V_91 ;
int V_92 ;
T_5 * V_93 ;
V_3 V_70 ;
V_89 = strtol ( V_88 , & V_75 , 10 ) ;
if ( V_75 != NULL && * V_75 == '\0' ) {
if ( V_89 < 0 ) {
F_24 ( L_84 ) ;
return 1 ;
}
if ( V_89 > V_94 ) {
F_24 ( L_85 ,
V_94 ) ;
return 1 ;
}
if ( V_89 == 0 ) {
F_24 ( L_86 ) ;
return 1 ;
}
V_90 = F_25 ( & V_92 , & V_93 , NULL ) ;
if ( V_90 == NULL ) {
if ( V_92 == 0 )
F_24 ( L_87 ) ;
else {
F_24 ( L_88 , V_93 ) ;
F_18 ( V_93 ) ;
}
return 2 ;
}
V_91 = ( T_8 * ) F_26 ( V_90 , ( int ) ( V_89 - 1 ) ) ;
if ( V_91 == NULL ) {
F_24 ( L_86 ) ;
return 1 ;
}
V_70 . V_8 = F_16 ( V_91 -> V_8 ) ;
if ( V_91 -> V_95 != NULL ) {
V_70 . V_71 = F_16 ( V_91 -> V_95 ) ;
} else {
V_70 . V_71 = F_16 ( V_91 -> V_8 ) ;
}
V_70 . V_16 = V_91 -> type ;
#ifdef F_3
V_70 . V_18 = F_16 ( V_91 -> V_18 ) ;
#endif
F_27 ( V_90 ) ;
} else if ( V_1 -> V_65 ) {
V_70 . V_8 = F_16 ( V_88 ) ;
V_70 . V_71 = F_16 ( V_88 ) ;
V_70 . V_16 = V_1 -> V_7 . V_16 ;
#ifdef F_3
V_70 . V_18 = F_16 ( V_1 -> V_7 . V_18 ) ;
#endif
} else {
V_90 = F_25 ( & V_92 , NULL , NULL ) ;
if ( V_90 != NULL ) {
T_6 * V_96 ;
T_4 V_97 ;
V_97 = FALSE ;
for ( V_96 = F_28 ( V_90 ) ; V_96 != NULL ;
V_96 = F_29 ( V_96 ) )
{
V_91 = ( T_8 * ) V_96 -> V_83 ;
if ( F_30 ( V_91 -> V_8 , V_88 ) == 0 ) {
V_70 . V_8 = F_16 ( V_91 -> V_8 ) ;
if ( V_91 -> V_95 != NULL ) {
V_70 . V_71 = F_16 ( V_91 -> V_95 ) ;
} else {
V_70 . V_71 = F_16 ( V_91 -> V_8 ) ;
}
V_70 . V_16 = V_91 -> type ;
#ifdef F_3
V_70 . V_18 = F_16 ( V_91 -> V_18 ) ;
#endif
V_97 = TRUE ;
break;
}
if ( V_91 -> V_95 != NULL &&
F_30 ( V_91 -> V_95 , V_88 ) == 0 ) {
V_70 . V_8 = F_16 ( V_91 -> V_8 ) ;
V_70 . V_71 = F_16 ( V_91 -> V_95 ) ;
V_70 . V_16 = V_91 -> type ;
#ifdef F_3
V_70 . V_18 = F_16 ( V_91 -> V_18 ) ;
#endif
V_97 = TRUE ;
break;
}
}
if ( ! V_97 ) {
T_9 V_98 ;
V_98 = strlen ( V_88 ) ;
for ( V_96 = F_28 ( V_90 ) ; V_96 != NULL ;
V_96 = F_29 ( V_96 ) )
{
V_91 = ( T_8 * ) V_96 -> V_83 ;
if ( V_91 -> V_95 != NULL &&
F_31 ( V_91 -> V_95 , V_88 , V_98 ) == 0 ) {
V_70 . V_8 = F_16 ( V_91 -> V_8 ) ;
V_70 . V_71 = F_16 ( V_91 -> V_95 ) ;
V_70 . V_16 = V_91 -> type ;
#ifdef F_3
V_70 . V_18 = F_16 ( V_91 -> V_18 ) ;
#endif
V_97 = TRUE ;
break;
}
}
}
if ( ! V_97 ) {
V_70 . V_8 = F_16 ( V_88 ) ;
V_70 . V_71 = F_16 ( V_88 ) ;
V_70 . V_16 = V_1 -> V_7 . V_16 ;
#ifdef F_3
V_70 . V_18 = F_16 ( V_1 -> V_7 . V_18 ) ;
#endif
}
F_27 ( V_90 ) ;
} else {
V_70 . V_8 = F_16 ( V_88 ) ;
V_70 . V_71 = F_16 ( V_88 ) ;
V_70 . V_16 = V_1 -> V_7 . V_16 ;
#ifdef F_3
V_70 . V_18 = F_16 ( V_1 -> V_7 . V_18 ) ;
#endif
}
}
V_70 . V_9 = F_16 ( V_1 -> V_7 . V_9 ) ;
V_70 . V_10 = F_16 ( V_1 -> V_7 . V_10 ) ;
V_70 . V_12 = V_1 -> V_7 . V_12 ;
V_70 . V_11 = V_1 -> V_7 . V_11 ;
V_70 . V_14 = V_1 -> V_7 . V_14 ;
V_70 . V_15 = V_1 -> V_7 . V_15 ;
#ifdef F_3
V_70 . V_19 = F_16 ( V_1 -> V_7 . V_19 ) ;
V_70 . V_20 = NULL ;
V_70 . V_22 = V_23 ;
V_70 . V_21 = NULL ;
#endif
#ifdef F_4
V_70 . V_24 = V_1 -> V_7 . V_24 ;
#endif
V_70 . V_26 = V_1 -> V_7 . V_26 ;
#ifdef F_5
V_70 . V_27 = V_1 -> V_7 . V_27 ;
V_70 . V_29 = F_16 ( V_1 -> V_7 . V_29 ) ;
V_70 . V_30 = F_16 ( V_1 -> V_7 . V_30 ) ;
V_70 . V_31 = V_1 -> V_7 . V_31 ;
V_70 . V_33 = F_16 ( V_1 -> V_7 . V_33 ) ;
V_70 . V_34 = F_16 ( V_1 -> V_7 . V_34 ) ;
V_70 . V_35 = V_1 -> V_7 . V_35 ;
V_70 . V_36 = V_1 -> V_7 . V_36 ;
V_70 . V_37 = V_1 -> V_7 . V_37 ;
#endif
#ifdef F_6
V_70 . V_38 = V_1 -> V_7 . V_38 ;
V_70 . V_40 = V_1 -> V_7 . V_40 ;
#endif
F_19 ( V_1 -> V_2 , V_70 ) ;
return 0 ;
}
int
F_32 ( T_1 * V_1 , int V_99 , const char * V_88 , T_4 * V_100 )
{
int V_101 , V_12 ;
switch( V_99 ) {
case V_102 :
if ( V_1 -> V_63 ) {
F_24 ( L_89 ) ;
return 1 ;
}
V_1 -> V_63 = F_16 ( V_88 ) ;
break;
case 'a' :
if ( F_11 ( V_1 , V_88 ) == FALSE ) {
F_24 ( L_90 , V_88 ) ;
return 1 ;
}
break;
#ifdef F_5
case 'A' :
if ( F_22 ( V_1 , V_88 ) == FALSE ) {
F_24 ( L_91 , V_88 ) ;
return 1 ;
}
break;
#endif
case 'b' :
V_1 -> V_49 = TRUE ;
if ( F_20 ( V_1 , V_88 ) == FALSE ) {
F_24 ( L_92 , V_88 ) ;
return 1 ;
}
break;
#ifdef F_4
case 'B' :
if ( V_1 -> V_2 -> V_69 > 0 ) {
V_3 V_70 ;
V_70 = F_10 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_69 - 1 ) ;
V_1 -> V_2 = F_17 ( V_1 -> V_2 , V_1 -> V_2 -> V_69 - 1 ) ;
V_70 . V_24 = F_13 ( V_88 , L_93 ) ;
F_19 ( V_1 -> V_2 , V_70 ) ;
} else {
V_1 -> V_7 . V_24 = F_13 ( V_88 , L_93 ) ;
}
break;
#endif
case 'c' :
V_1 -> V_57 = TRUE ;
V_1 -> V_58 = F_13 ( V_88 , L_94 ) ;
break;
case 'f' :
F_14 ( V_1 , V_88 ) ;
break;
case 'g' :
V_1 -> V_43 = TRUE ;
break;
case 'H' :
V_1 -> V_46 = FALSE ;
break;
case 'i' :
V_101 = F_23 ( V_1 , V_88 ) ;
if ( V_101 != 0 ) {
return V_101 ;
}
break;
#ifdef F_33
case 'I' :
if ( V_1 -> V_2 -> V_69 > 0 ) {
V_3 V_70 ;
V_70 = F_10 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_69 - 1 ) ;
V_1 -> V_2 = F_17 ( V_1 -> V_2 , V_1 -> V_2 -> V_69 - 1 ) ;
V_70 . V_26 = TRUE ;
F_19 ( V_1 -> V_2 , V_70 ) ;
} else {
V_1 -> V_7 . V_26 = TRUE ;
}
break;
#endif
case 'k' :
* V_100 = TRUE ;
break;
#ifdef F_6
case 'm' :
if ( F_21 ( V_1 , V_88 ) == FALSE ) {
F_24 ( L_95 , V_88 ) ;
return 1 ;
}
break;
#endif
case 'n' :
V_1 -> V_44 = TRUE ;
break;
case 'p' :
if ( V_1 -> V_2 -> V_69 > 0 ) {
V_3 V_70 ;
V_70 = F_10 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_69 - 1 ) ;
V_1 -> V_2 = F_17 ( V_1 -> V_2 , V_1 -> V_2 -> V_69 - 1 ) ;
V_70 . V_15 = FALSE ;
F_19 ( V_1 -> V_2 , V_70 ) ;
} else {
V_1 -> V_7 . V_15 = FALSE ;
}
break;
case 'P' :
V_1 -> V_44 = FALSE ;
break;
#ifdef F_5
case 'r' :
if ( V_1 -> V_2 -> V_69 > 0 ) {
V_3 V_70 ;
V_70 = F_10 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_69 - 1 ) ;
V_1 -> V_2 = F_17 ( V_1 -> V_2 , V_1 -> V_2 -> V_69 - 1 ) ;
V_70 . V_36 = FALSE ;
F_19 ( V_1 -> V_2 , V_70 ) ;
} else {
V_1 -> V_7 . V_36 = FALSE ;
}
break;
#endif
case 's' :
V_12 = F_34 ( V_88 , L_96 ) ;
if ( V_12 == 0 )
V_12 = V_13 ;
if ( V_1 -> V_2 -> V_69 > 0 ) {
V_3 V_70 ;
V_70 = F_10 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_69 - 1 ) ;
V_1 -> V_2 = F_17 ( V_1 -> V_2 , V_1 -> V_2 -> V_69 - 1 ) ;
V_70 . V_11 = TRUE ;
V_70 . V_12 = V_12 ;
F_19 ( V_1 -> V_2 , V_70 ) ;
} else {
V_1 -> V_7 . V_12 = V_12 ;
V_1 -> V_7 . V_11 = TRUE ;
}
break;
case 'S' :
V_1 -> V_45 = TRUE ;
break;
#ifdef F_5
case 'u' :
if ( V_1 -> V_2 -> V_69 > 0 ) {
V_3 V_70 ;
V_70 = F_10 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_69 - 1 ) ;
V_1 -> V_2 = F_17 ( V_1 -> V_2 , V_1 -> V_2 -> V_69 - 1 ) ;
V_70 . V_35 = TRUE ;
F_19 ( V_1 -> V_2 , V_70 ) ;
} else {
V_1 -> V_7 . V_35 = TRUE ;
}
break;
#endif
case 'w' :
V_1 -> V_41 = TRUE ;
F_18 ( V_1 -> V_42 ) ;
V_1 -> V_42 = F_16 ( V_88 ) ;
V_101 = F_35 ( V_1 -> V_42 , & V_1 -> V_64 ) ;
return V_101 ;
case 'y' :
if ( V_1 -> V_2 -> V_69 > 0 ) {
V_3 V_70 ;
V_70 = F_10 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_69 - 1 ) ;
V_1 -> V_2 = F_17 ( V_1 -> V_2 , V_1 -> V_2 -> V_69 - 1 ) ;
V_70 . V_14 = F_36 ( V_88 ) ;
if ( V_70 . V_14 == - 1 ) {
F_24 ( L_97 ,
V_88 ) ;
return 1 ;
}
F_19 ( V_1 -> V_2 , V_70 ) ;
} else {
V_1 -> V_7 . V_14 = F_36 ( V_88 ) ;
if ( V_1 -> V_7 . V_14 == - 1 ) {
F_24 ( L_97 ,
V_88 ) ;
return 1 ;
}
}
break;
default:
F_37 () ;
}
return 0 ;
}
void
F_38 ( T_10 * V_103 , char * V_8 ,
T_4 V_26 )
{
T_6 * V_104 ;
T_11 * V_105 ;
if ( V_103 -> V_106 )
printf ( L_98 ,
V_8 , V_26 ? L_56 : L_99 ) ;
else
printf ( L_100 , V_8 ) ;
for ( V_104 = V_103 -> V_107 ; V_104 != NULL ;
V_104 = F_29 ( V_104 ) ) {
V_105 = ( T_11 * ) V_104 -> V_83 ;
printf ( L_101 , V_105 -> V_8 ) ;
if ( V_105 -> V_108 != NULL )
printf ( L_102 , V_105 -> V_108 ) ;
else
printf ( L_103 ) ;
printf ( L_104 ) ;
}
}
void
F_39 ( T_6 * V_90 )
{
int V_68 ;
T_6 * V_96 ;
T_8 * V_91 ;
V_68 = 1 ;
for ( V_96 = F_28 ( V_90 ) ; V_96 != NULL ;
V_96 = F_29 ( V_96 ) ) {
V_91 = ( T_8 * ) V_96 -> V_83 ;
printf ( L_105 , V_68 ++ , V_91 -> V_8 ) ;
if ( V_91 -> V_95 != NULL ) {
printf ( L_102 , V_91 -> V_95 ) ;
} else {
if ( V_91 -> V_109 != NULL )
printf ( L_102 , V_91 -> V_109 ) ;
}
printf ( L_104 ) ;
}
}
void
F_40 ( T_1 * V_1 , int V_110 )
{
T_3 V_68 ;
V_3 V_70 ;
if ( V_1 -> V_2 -> V_69 > 0 ) {
for ( V_68 = 0 ; V_68 < V_1 -> V_2 -> V_69 ; V_68 ++ ) {
V_70 = F_10 ( V_1 -> V_2 , V_3 , 0 ) ;
V_1 -> V_2 = F_17 ( V_1 -> V_2 , 0 ) ;
if ( V_70 . V_12 < 1 )
V_70 . V_12 = V_13 ;
else if ( V_70 . V_12 < V_110 )
V_70 . V_12 = V_110 ;
F_19 ( V_1 -> V_2 , V_70 ) ;
}
} else {
if ( V_1 -> V_7 . V_12 < 1 )
V_1 -> V_7 . V_12 = V_13 ;
else if ( V_1 -> V_7 . V_12 < V_110 )
V_1 -> V_7 . V_12 = V_110 ;
}
}
void
F_41 ( T_1 * V_1 )
{
if ( V_1 -> V_53 > V_111 ) {
F_24 ( L_106 , V_1 -> V_53 , V_111 ) ;
V_1 -> V_53 = V_111 ;
} else if ( V_1 -> V_53 > V_112 ) {
F_24 ( L_107 , V_1 -> V_53 ) ;
}
#if V_54 > 0
else if ( V_1 -> V_53 < V_54 )
F_24 ( L_108 , V_1 -> V_53 , V_54 ) ;
V_1 -> V_53 = V_54 ;
#endif
}
int
F_42 ( T_1 * V_1 ,
const char * V_113 )
{
int V_101 ;
if ( V_1 -> V_6 != 0 || V_1 -> V_2 -> V_69 != 0 ) {
return 0 ;
}
if ( V_113 != NULL ) {
V_101 = F_23 ( V_1 , V_113 ) ;
return V_101 ;
}
return F_23 ( V_1 , L_109 ) ;
}
static int
F_43 ( const char * V_114 )
{
T_12 V_115 ;
if ( F_44 ( V_114 , & V_115 ) < 0 )
return V_116 ;
if ( F_45 ( V_115 . V_117 ) )
return V_118 ;
else
return 0 ;
}
static T_4
F_35 ( const char * V_42 , T_4 * V_119 )
{
int V_92 ;
* V_119 = FALSE ;
if ( V_42 != NULL ) {
if ( strcmp ( V_42 , L_110 ) == 0 ) {
* V_119 = TRUE ;
} else {
V_92 = F_43 ( V_42 ) ;
switch ( V_92 ) {
case V_120 :
case 0 :
break;
case V_118 :
* V_119 = TRUE ;
break;
default:
break;
}
}
}
return 0 ;
}
void
F_46 ( T_1 * V_1 , T_3 V_121 )
{
V_3 V_70 ;
V_70 = F_10 ( V_1 -> V_2 , V_3 , V_121 ) ;
F_18 ( V_70 . V_8 ) ;
F_18 ( V_70 . V_9 ) ;
if ( V_70 . V_71 != NULL )
F_18 ( V_70 . V_71 ) ;
F_18 ( V_70 . V_10 ) ;
#ifdef F_3
F_18 ( V_70 . V_18 ) ;
F_18 ( V_70 . V_19 ) ;
if ( V_70 . V_20 )
F_47 ( V_70 . V_20 ) ;
if ( V_70 . V_22 != V_23 )
F_48 ( V_70 . V_22 ) ;
F_18 ( V_70 . V_21 ) ;
#endif
#ifdef F_5
if ( V_70 . V_27 == V_72 ) {
F_18 ( V_70 . V_29 ) ;
F_18 ( V_70 . V_30 ) ;
F_18 ( V_70 . V_33 ) ;
F_18 ( V_70 . V_34 ) ;
}
#endif
V_1 -> V_2 = F_17 ( V_1 -> V_2 , V_121 ) ;
}
void
F_49 ( T_1 * V_1 )
{
T_3 V_68 ;
V_5 V_122 ;
V_3 V_70 ;
for ( V_68 = V_1 -> V_2 -> V_69 ; V_68 != 0 ; V_68 -- )
F_46 ( V_1 , V_68 - 1 ) ;
for ( V_68 = 0 ; V_68 < V_1 -> V_4 -> V_69 ; V_68 ++ ) {
V_122 = F_10 ( V_1 -> V_4 , V_5 , V_68 ) ;
if ( ! V_122 . V_123 && V_122 . V_124 ) {
V_70 . V_8 = F_16 ( V_122 . V_8 ) ;
V_70 . V_9 = F_16 ( V_122 . V_125 ) ;
V_70 . V_71 = F_16 ( V_122 . V_8 ) ;
V_70 . V_14 = V_122 . V_126 ;
V_70 . V_10 = F_16 ( V_122 . V_10 ) ;
V_70 . V_12 = V_122 . V_12 ;
V_70 . V_11 = V_122 . V_11 ;
V_70 . V_15 = V_122 . V_127 ;
V_70 . V_16 = V_122 . V_91 . type ;
#ifdef F_3
V_70 . V_18 = F_16 ( V_122 . V_91 . V_18 ) ;
V_70 . V_19 = NULL ;
V_70 . V_21 = NULL ;
V_70 . V_20 = V_122 . V_128 ;
V_70 . V_22 = V_23 ;
if ( V_70 . V_20 )
F_50 ( V_70 . V_20 ) ;
V_70 . V_21 = NULL ;
#endif
#ifdef F_4
V_70 . V_24 = V_122 . V_129 ;
#endif
#ifdef F_33
V_70 . V_26 = V_122 . V_130 ;
#endif
#ifdef F_5
V_70 . V_27 = V_72 ;
V_70 . V_29 = F_16 ( V_122 . V_131 . V_132 . V_29 ) ;
V_70 . V_30 = F_16 ( V_122 . V_131 . V_132 . V_30 ) ;
V_70 . V_31 = V_122 . V_131 . V_132 . V_31 ;
V_70 . V_33 = F_16 ( V_122 . V_131 . V_132 . V_33 ) ;
V_70 . V_34 = F_16 ( V_122 . V_131 . V_132 . V_34 ) ;
V_70 . V_35 = V_122 . V_131 . V_132 . V_35 ;
V_70 . V_36 = V_122 . V_131 . V_132 . V_36 ;
V_70 . V_37 = V_122 . V_131 . V_132 . V_37 ;
#endif
#ifdef F_6
V_70 . V_38 = V_122 . V_131 . V_38 ;
V_70 . V_40 = V_122 . V_131 . V_40 ;
#endif
F_19 ( V_1 -> V_2 , V_70 ) ;
} else {
continue;
}
}
}
static void
F_51 ( T_13 V_133 , T_13 T_14 V_134 )
{
T_15 * V_135 = ( T_15 * ) V_133 ;
if ( V_135 != NULL )
F_18 ( V_135 -> V_8 ) ;
F_18 ( V_133 ) ;
}
static void
F_52 ( T_13 V_133 , T_13 T_14 V_134 )
{
F_18 ( V_133 ) ;
}
void
F_53 ( V_5 * V_122 )
{
if ( V_122 != NULL ) {
F_18 ( V_122 -> V_8 ) ;
F_18 ( V_122 -> V_125 ) ;
F_18 ( V_122 -> V_95 ) ;
F_18 ( V_122 -> V_136 ) ;
F_18 ( V_122 -> V_10 ) ;
F_54 ( V_122 -> V_137 ,
F_51 , NULL ) ;
F_55 ( V_122 -> V_137 ) ;
#ifdef F_5
F_18 ( V_122 -> V_131 . V_132 . V_29 ) ;
F_18 ( V_122 -> V_131 . V_132 . V_30 ) ;
F_18 ( V_122 -> V_131 . V_132 . V_33 ) ;
F_18 ( V_122 -> V_131 . V_132 . V_34 ) ;
#endif
F_18 ( V_122 -> V_91 . V_8 ) ;
F_18 ( V_122 -> V_91 . V_95 ) ;
F_18 ( V_122 -> V_91 . V_109 ) ;
F_56 ( V_122 -> V_91 . V_138 ,
F_52 , NULL ) ;
F_57 ( V_122 -> V_91 . V_138 ) ;
#ifdef F_3
F_18 ( V_122 -> V_91 . V_18 ) ;
#endif
}
}

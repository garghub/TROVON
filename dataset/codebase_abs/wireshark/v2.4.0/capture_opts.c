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
V_1 -> V_7 . V_24 = NULL ;
V_1 -> V_7 . V_25 = NULL ;
#endif
#ifdef F_4
V_1 -> V_7 . V_26 = V_27 ;
#endif
V_1 -> V_7 . V_28 = FALSE ;
#ifdef F_5
V_1 -> V_7 . V_29 = V_30 ;
V_1 -> V_7 . V_31 = NULL ;
V_1 -> V_7 . V_32 = NULL ;
V_1 -> V_7 . V_33 = V_34 ;
V_1 -> V_7 . V_35 = NULL ;
V_1 -> V_7 . V_36 = NULL ;
V_1 -> V_7 . V_37 = FALSE ;
V_1 -> V_7 . V_38 = TRUE ;
V_1 -> V_7 . V_39 = FALSE ;
#endif
#ifdef F_6
V_1 -> V_7 . V_40 = V_41 ;
V_1 -> V_7 . V_42 = 0 ;
#endif
V_1 -> V_43 = FALSE ;
V_1 -> V_44 = NULL ;
V_1 -> V_45 = FALSE ;
#ifdef F_7
V_1 -> V_46 = TRUE ;
#else
V_1 -> V_46 = FALSE ;
#endif
V_1 -> V_47 = TRUE ;
V_1 -> V_48 = TRUE ;
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
F_8 ( T_1 * V_1 )
{
if ( ! V_1 )
return;
if ( V_1 -> V_2 ) {
F_9 ( V_1 -> V_2 , TRUE ) ;
V_1 -> V_2 = NULL ;
}
if ( V_1 -> V_4 ) {
F_9 ( V_1 -> V_4 , TRUE ) ;
V_1 -> V_4 = NULL ;
}
}
void
F_10 ( const char * V_68 , T_2 V_69 , T_1 * V_1 ) {
T_3 V_70 ;
F_11 ( V_68 , V_69 , L_1 ) ;
for ( V_70 = 0 ; V_70 < V_1 -> V_2 -> V_71 ; V_70 ++ ) {
V_3 V_72 ;
V_72 = F_12 ( V_1 -> V_2 , V_3 , V_70 ) ;
F_11 ( V_68 , V_69 , L_2 , V_70 , V_72 . V_8 ? V_72 . V_8 : L_3 ) ;
F_11 ( V_68 , V_69 , L_4 , V_70 , V_72 . V_9 ? V_72 . V_9 : L_3 ) ;
F_11 ( V_68 , V_69 , L_5 , V_70 , V_72 . V_73 ? V_72 . V_73 : L_3 ) ;
F_11 ( V_68 , V_69 , L_6 , V_70 , V_72 . V_10 ? V_72 . V_10 : L_3 ) ;
F_11 ( V_68 , V_69 , L_7 , V_70 , V_72 . V_11 , V_72 . V_12 ) ;
F_11 ( V_68 , V_69 , L_8 , V_70 , V_72 . V_14 ) ;
F_11 ( V_68 , V_69 , L_9 , V_70 , V_72 . V_15 ? L_10 : L_11 ) ;
#ifdef F_3
F_11 ( V_68 , V_69 , L_12 , V_70 , V_72 . V_18 ? V_72 . V_18 : L_3 ) ;
F_11 ( V_68 , V_69 , L_13 , V_70 , V_72 . V_19 ? V_72 . V_19 : L_3 ) ;
F_11 ( V_68 , V_69 , L_14 , V_70 , V_72 . V_22 ) ;
#endif
#ifdef F_4
F_11 ( V_68 , V_69 , L_15 , V_70 , V_72 . V_26 ) ;
#endif
F_11 ( V_68 , V_69 , L_16 , V_70 , V_72 . V_28 ? L_10 : L_11 ) ;
#ifdef F_5
F_11 ( V_68 , V_69 , L_17 , V_70 ,
V_72 . V_29 == V_30 ? L_18 :
V_72 . V_29 == V_74 ? L_19 :
L_20 ) ;
if ( V_72 . V_29 == V_74 ) {
F_11 ( V_68 , V_69 , L_21 , V_70 , V_72 . V_31 ? V_72 . V_31 : L_3 ) ;
F_11 ( V_68 , V_69 , L_22 , V_70 , V_72 . V_32 ? V_72 . V_32 : L_3 ) ;
}
F_11 ( V_68 , V_69 , L_23 , V_70 ,
V_72 . V_33 == V_34 ? L_24 :
V_72 . V_33 == V_75 ? L_25 :
L_20 ) ;
if ( V_72 . V_33 == V_75 ) {
F_11 ( V_68 , V_69 , L_26 , V_70 , V_72 . V_35 ? V_72 . V_35 : L_3 ) ;
F_11 ( V_68 , V_69 , L_27 , V_70 ) ;
}
F_11 ( V_68 , V_69 , L_28 , V_70 , V_72 . V_37 ) ;
F_11 ( V_68 , V_69 , L_29 , V_70 , V_72 . V_38 ) ;
F_11 ( V_68 , V_69 , L_30 , V_70 , V_72 . V_39 ) ;
#endif
#ifdef F_6
F_11 ( V_68 , V_69 , L_31 , V_70 , V_72 . V_40 ) ;
F_11 ( V_68 , V_69 , L_32 , V_70 , V_72 . V_42 ) ;
#endif
}
F_11 ( V_68 , V_69 , L_33 , V_1 -> V_7 . V_8 ? V_1 -> V_7 . V_8 : L_3 ) ;
F_11 ( V_68 , V_69 , L_34 , V_1 -> V_7 . V_9 ? V_1 -> V_7 . V_9 : L_3 ) ;
F_11 ( V_68 , V_69 , L_35 , V_1 -> V_7 . V_10 ? V_1 -> V_7 . V_10 : L_3 ) ;
F_11 ( V_68 , V_69 , L_36 , V_1 -> V_7 . V_11 , V_1 -> V_7 . V_12 ) ;
F_11 ( V_68 , V_69 , L_37 , V_1 -> V_7 . V_14 ) ;
F_11 ( V_68 , V_69 , L_38 , V_1 -> V_7 . V_15 ? L_10 : L_11 ) ;
#ifdef F_3
F_11 ( V_68 , V_69 , L_39 , V_1 -> V_7 . V_18 ? V_1 -> V_7 . V_18 : L_3 ) ;
F_11 ( V_68 , V_69 , L_40 , V_1 -> V_7 . V_19 ? V_1 -> V_7 . V_19 : L_3 ) ;
#endif
#ifdef F_4
F_11 ( V_68 , V_69 , L_41 , V_1 -> V_7 . V_26 ) ;
#endif
F_11 ( V_68 , V_69 , L_42 , V_1 -> V_7 . V_28 ? L_10 : L_11 ) ;
#ifdef F_5
F_11 ( V_68 , V_69 , L_43 ,
V_1 -> V_7 . V_29 == V_30 ? L_18 :
V_1 -> V_7 . V_29 == V_74 ? L_19 :
L_20 ) ;
if ( V_1 -> V_7 . V_29 == V_74 ) {
F_11 ( V_68 , V_69 , L_44 , V_1 -> V_7 . V_31 ? V_1 -> V_7 . V_31 : L_3 ) ;
F_11 ( V_68 , V_69 , L_45 , V_1 -> V_7 . V_32 ? V_1 -> V_7 . V_32 : L_3 ) ;
}
F_11 ( V_68 , V_69 , L_46 ,
V_1 -> V_7 . V_33 == V_34 ? L_24 :
V_1 -> V_7 . V_33 == V_75 ? L_25 :
L_20 ) ;
if ( V_1 -> V_7 . V_33 == V_75 ) {
F_11 ( V_68 , V_69 , L_47 , V_1 -> V_7 . V_35 ? V_1 -> V_7 . V_35 : L_3 ) ;
F_11 ( V_68 , V_69 , L_48 ) ;
}
F_11 ( V_68 , V_69 , L_49 , V_1 -> V_7 . V_37 ) ;
F_11 ( V_68 , V_69 , L_50 , V_1 -> V_7 . V_38 ) ;
F_11 ( V_68 , V_69 , L_51 , V_1 -> V_7 . V_39 ) ;
#endif
#ifdef F_6
F_11 ( V_68 , V_69 , L_52 , V_1 -> V_7 . V_40 ) ;
F_11 ( V_68 , V_69 , L_53 , V_1 -> V_7 . V_42 ) ;
#endif
F_11 ( V_68 , V_69 , L_54 , V_1 -> V_43 ) ;
F_11 ( V_68 , V_69 , L_55 , ( V_1 -> V_44 ) ? V_1 -> V_44 : L_56 ) ;
F_11 ( V_68 , V_69 , L_57 , V_1 -> V_45 ) ;
F_11 ( V_68 , V_69 , L_58 , ( V_1 -> V_46 ) ? L_59 : L_60 ) ;
F_11 ( V_68 , V_69 , L_61 , V_1 -> V_47 ) ;
F_11 ( V_68 , V_69 , L_62 , V_1 -> V_48 ) ;
F_11 ( V_68 , V_69 , L_63 , V_1 -> V_51 ) ;
F_11 ( V_68 , V_69 , L_64 , V_1 -> V_52 , V_1 -> V_53 ) ;
F_11 ( V_68 , V_69 , L_65 , V_1 -> V_54 , V_1 -> V_55 ) ;
F_11 ( V_68 , V_69 , L_66 , V_1 -> V_57 , V_1 -> V_58 ) ;
F_11 ( V_68 , V_69 , L_67 , V_1 -> V_59 , V_1 -> V_60 ) ;
F_11 ( V_68 , V_69 , L_68 , V_1 -> V_61 , V_1 -> V_62 ) ;
F_11 ( V_68 , V_69 , L_69 , V_1 -> V_63 , V_1 -> V_64 ) ;
}
static T_4
F_13 ( T_1 * V_1 , const char * V_76 )
{
T_5 * V_77 , * V_78 ;
V_78 = strchr ( V_76 , ':' ) ;
if ( V_78 == NULL )
return FALSE ;
V_77 = V_78 ;
* V_77 ++ = '\0' ;
while ( F_14 ( * V_77 ) )
V_77 ++ ;
if ( * V_77 == '\0' ) {
* V_78 = ':' ;
return FALSE ;
}
if ( strcmp ( V_76 , L_70 ) == 0 ) {
V_1 -> V_63 = TRUE ;
V_1 -> V_64 = F_15 ( V_77 , L_71 ) ;
} else if ( strcmp ( V_76 , L_72 ) == 0 ) {
V_1 -> V_61 = TRUE ;
V_1 -> V_62 = F_16 ( V_77 , L_73 ) ;
} else if ( strcmp ( V_76 , L_74 ) == 0 ) {
V_1 -> V_51 = TRUE ;
V_1 -> V_57 = TRUE ;
V_1 -> V_58 = F_15 ( V_77 , L_75 ) ;
} else {
return FALSE ;
}
* V_78 = ':' ;
return TRUE ;
}
static T_4 F_17 ( T_1 * V_1 , const char * V_79 )
{
char * V_78 ;
char * V_80 ;
char * V_81 = NULL ;
V_78 = strchr ( V_79 , ':' ) ;
if ( V_78 ) {
V_80 = V_78 ;
* V_80 = '\0' ;
V_80 ++ ;
if ( strcmp ( V_79 , L_76 ) == 0 ) {
T_6 * V_82 ;
V_82 = F_18 ( V_83 ) ;
while ( V_82 != NULL ) {
T_7 * V_84 ;
V_84 = ( T_7 * ) V_82 -> V_85 ;
if ( strcmp ( V_80 , V_84 -> V_8 ) == 0 ) {
V_81 = F_19 ( V_84 -> V_86 ) ;
break;
}
V_82 = V_82 -> V_87 ;
}
}
}
if ( V_81 == NULL ) {
if ( V_78 ) {
* V_78 = ':' ;
}
V_81 = F_19 ( V_79 ) ;
}
if ( V_1 -> V_2 -> V_71 > 0 ) {
V_3 V_72 ;
V_72 = F_12 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_71 - 1 ) ;
V_1 -> V_2 = F_20 ( V_1 -> V_2 , V_1 -> V_2 -> V_71 - 1 ) ;
F_21 ( V_72 . V_10 ) ;
V_72 . V_10 = V_81 ;
F_22 ( V_1 -> V_2 , V_72 ) ;
return TRUE ;
}
else {
F_21 ( V_1 -> V_7 . V_10 ) ;
V_1 -> V_7 . V_10 = V_81 ;
return TRUE ;
}
}
static T_4
F_23 ( T_1 * V_1 , const char * V_79 )
{
T_5 * V_77 = NULL , * V_78 ;
V_78 = strchr ( V_79 , ':' ) ;
if ( V_78 == NULL )
return FALSE ;
V_77 = V_78 ;
* V_77 ++ = '\0' ;
while ( F_14 ( * V_77 ) )
V_77 ++ ;
if ( * V_77 == '\0' ) {
* V_78 = ':' ;
return FALSE ;
}
if ( strcmp ( V_79 , L_74 ) == 0 ) {
V_1 -> V_54 = TRUE ;
V_1 -> V_55 = F_16 ( V_77 , L_77 ) ;
} else if ( strcmp ( V_79 , L_72 ) == 0 ) {
V_1 -> V_61 = TRUE ;
V_1 -> V_62 = F_16 ( V_77 , L_78 ) ;
} else if ( strcmp ( V_79 , L_70 ) == 0 ) {
V_1 -> V_52 = TRUE ;
V_1 -> V_53 = F_15 ( V_77 , L_79 ) ;
}
* V_78 = ':' ;
return TRUE ;
}
static T_4
F_24 ( T_1 * V_1 , const char * V_79 )
{
T_5 * V_77 = NULL , * V_78 ;
V_78 = strchr ( V_79 , ':' ) ;
if ( V_78 == NULL )
return FALSE ;
V_77 = V_78 ;
* V_77 ++ = '\0' ;
while ( F_14 ( * V_77 ) )
V_77 ++ ;
if ( * V_77 == '\0' ) {
* V_78 = ':' ;
return FALSE ;
}
if ( strcmp ( V_79 , L_80 ) == 0 ) {
if ( V_1 -> V_2 -> V_71 > 0 ) {
V_3 V_72 ;
V_72 = F_12 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_71 - 1 ) ;
V_1 -> V_2 = F_20 ( V_1 -> V_2 , V_1 -> V_2 -> V_71 - 1 ) ;
V_72 . V_40 = V_88 ;
V_72 . V_42 = F_15 ( V_77 , L_81 ) ;
F_22 ( V_1 -> V_2 , V_72 ) ;
} else {
V_1 -> V_7 . V_40 = V_88 ;
V_1 -> V_7 . V_42 = F_15 ( V_77 , L_81 ) ;
}
} else if ( strcmp ( V_79 , L_82 ) == 0 ) {
if ( V_1 -> V_2 -> V_71 > 0 ) {
V_3 V_72 ;
V_72 = F_12 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_71 - 1 ) ;
V_1 -> V_2 = F_20 ( V_1 -> V_2 , V_1 -> V_2 -> V_71 - 1 ) ;
V_72 . V_40 = V_89 ;
V_72 . V_42 = F_15 ( V_77 , L_83 ) ;
F_22 ( V_1 -> V_2 , V_72 ) ;
} else {
V_1 -> V_7 . V_40 = V_89 ;
V_1 -> V_7 . V_42 = F_15 ( V_77 , L_83 ) ;
}
}
* V_78 = ':' ;
return TRUE ;
}
static T_4
F_25 ( T_1 * V_1 , const char * V_79 )
{
T_5 * V_77 = NULL , * V_78 ;
V_78 = strchr ( V_79 , ':' ) ;
if ( V_78 == NULL )
return FALSE ;
V_77 = V_78 ;
* V_77 ++ = '\0' ;
while ( F_14 ( * V_77 ) )
V_77 ++ ;
if ( V_1 -> V_2 -> V_71 > 0 ) {
V_3 V_72 ;
V_72 = F_12 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_71 - 1 ) ;
V_1 -> V_2 = F_20 ( V_1 -> V_2 , V_1 -> V_2 -> V_71 - 1 ) ;
V_72 . V_33 = V_75 ;
V_72 . V_35 = F_19 ( V_79 ) ;
V_72 . V_36 = F_19 ( V_77 ) ;
F_22 ( V_1 -> V_2 , V_72 ) ;
} else {
V_1 -> V_7 . V_33 = V_75 ;
V_1 -> V_7 . V_35 = F_19 ( V_79 ) ;
V_1 -> V_7 . V_36 = F_19 ( V_77 ) ;
}
* V_78 = ':' ;
return TRUE ;
}
static int
F_26 ( T_1 * V_1 , const char * V_90 )
{
long V_91 ;
char * V_77 ;
T_6 * V_92 ;
T_8 * V_93 ;
int V_94 ;
T_5 * V_95 ;
V_3 V_72 ;
V_91 = strtol ( V_90 , & V_77 , 10 ) ;
if ( V_77 != NULL && * V_77 == '\0' ) {
if ( V_91 < 0 ) {
F_27 ( L_84 ) ;
return 1 ;
}
if ( V_91 > V_96 ) {
F_27 ( L_85 ,
V_96 ) ;
return 1 ;
}
if ( V_91 == 0 ) {
F_27 ( L_86 ) ;
return 1 ;
}
V_92 = F_28 ( & V_94 , & V_95 , NULL ) ;
if ( V_92 == NULL ) {
if ( V_94 == 0 )
F_27 ( L_87 ) ;
else {
F_27 ( L_88 , V_95 ) ;
F_21 ( V_95 ) ;
}
return 2 ;
}
V_93 = ( T_8 * ) F_29 ( V_92 , ( int ) ( V_91 - 1 ) ) ;
if ( V_93 == NULL ) {
F_27 ( L_86 ) ;
return 1 ;
}
V_72 . V_8 = F_19 ( V_93 -> V_8 ) ;
if ( V_93 -> V_97 != NULL ) {
V_72 . V_73 = F_19 ( V_93 -> V_97 ) ;
} else {
V_72 . V_73 = F_19 ( V_93 -> V_8 ) ;
}
V_72 . V_16 = V_93 -> type ;
#ifdef F_3
V_72 . V_18 = F_19 ( V_93 -> V_18 ) ;
#endif
F_30 ( V_92 ) ;
} else if ( V_1 -> V_67 ) {
V_72 . V_8 = F_19 ( V_90 ) ;
V_72 . V_73 = F_19 ( V_90 ) ;
V_72 . V_16 = V_1 -> V_7 . V_16 ;
#ifdef F_3
V_72 . V_18 = F_19 ( V_1 -> V_7 . V_18 ) ;
#endif
} else {
V_92 = F_28 ( & V_94 , NULL , NULL ) ;
if ( V_92 != NULL ) {
T_6 * V_98 ;
T_4 V_99 ;
V_99 = FALSE ;
for ( V_98 = F_31 ( V_92 ) ; V_98 != NULL ;
V_98 = F_32 ( V_98 ) )
{
V_93 = ( T_8 * ) V_98 -> V_85 ;
if ( F_33 ( V_93 -> V_8 , V_90 ) == 0 ) {
V_72 . V_8 = F_19 ( V_93 -> V_8 ) ;
if ( V_93 -> V_97 != NULL ) {
V_72 . V_73 = F_19 ( V_93 -> V_97 ) ;
} else {
V_72 . V_73 = F_19 ( V_93 -> V_8 ) ;
}
V_72 . V_16 = V_93 -> type ;
#ifdef F_3
V_72 . V_18 = F_19 ( V_93 -> V_18 ) ;
#endif
V_99 = TRUE ;
break;
}
if ( V_93 -> V_97 != NULL &&
F_33 ( V_93 -> V_97 , V_90 ) == 0 ) {
V_72 . V_8 = F_19 ( V_93 -> V_8 ) ;
V_72 . V_73 = F_19 ( V_93 -> V_97 ) ;
V_72 . V_16 = V_93 -> type ;
#ifdef F_3
V_72 . V_18 = F_19 ( V_93 -> V_18 ) ;
#endif
V_99 = TRUE ;
break;
}
}
if ( ! V_99 ) {
T_9 V_100 ;
V_100 = strlen ( V_90 ) ;
for ( V_98 = F_31 ( V_92 ) ; V_98 != NULL ;
V_98 = F_32 ( V_98 ) )
{
V_93 = ( T_8 * ) V_98 -> V_85 ;
if ( V_93 -> V_97 != NULL &&
F_34 ( V_93 -> V_97 , V_90 , V_100 ) == 0 ) {
V_72 . V_8 = F_19 ( V_93 -> V_8 ) ;
V_72 . V_73 = F_19 ( V_93 -> V_97 ) ;
V_72 . V_16 = V_93 -> type ;
#ifdef F_3
V_72 . V_18 = F_19 ( V_93 -> V_18 ) ;
#endif
V_99 = TRUE ;
break;
}
}
}
if ( ! V_99 ) {
V_72 . V_8 = F_19 ( V_90 ) ;
V_72 . V_73 = F_19 ( V_90 ) ;
V_72 . V_16 = V_1 -> V_7 . V_16 ;
#ifdef F_3
V_72 . V_18 = F_19 ( V_1 -> V_7 . V_18 ) ;
#endif
}
F_30 ( V_92 ) ;
} else {
V_72 . V_8 = F_19 ( V_90 ) ;
V_72 . V_73 = F_19 ( V_90 ) ;
V_72 . V_16 = V_1 -> V_7 . V_16 ;
#ifdef F_3
V_72 . V_18 = F_19 ( V_1 -> V_7 . V_18 ) ;
#endif
}
}
V_72 . V_9 = F_19 ( V_1 -> V_7 . V_9 ) ;
V_72 . V_10 = F_19 ( V_1 -> V_7 . V_10 ) ;
V_72 . V_12 = V_1 -> V_7 . V_12 ;
V_72 . V_11 = V_1 -> V_7 . V_11 ;
V_72 . V_14 = V_1 -> V_7 . V_14 ;
V_72 . V_15 = V_1 -> V_7 . V_15 ;
#ifdef F_3
V_72 . V_19 = F_19 ( V_1 -> V_7 . V_19 ) ;
V_72 . V_20 = NULL ;
V_72 . V_22 = V_23 ;
V_72 . V_21 = NULL ;
V_72 . V_24 = F_19 ( V_1 -> V_7 . V_24 ) ;
V_72 . V_25 = F_19 ( V_1 -> V_7 . V_25 ) ;
#endif
#ifdef F_4
V_72 . V_26 = V_1 -> V_7 . V_26 ;
#endif
V_72 . V_28 = V_1 -> V_7 . V_28 ;
#ifdef F_5
V_72 . V_29 = V_1 -> V_7 . V_29 ;
V_72 . V_31 = F_19 ( V_1 -> V_7 . V_31 ) ;
V_72 . V_32 = F_19 ( V_1 -> V_7 . V_32 ) ;
V_72 . V_33 = V_1 -> V_7 . V_33 ;
V_72 . V_35 = F_19 ( V_1 -> V_7 . V_35 ) ;
V_72 . V_36 = F_19 ( V_1 -> V_7 . V_36 ) ;
V_72 . V_37 = V_1 -> V_7 . V_37 ;
V_72 . V_38 = V_1 -> V_7 . V_38 ;
V_72 . V_39 = V_1 -> V_7 . V_39 ;
#endif
#ifdef F_6
V_72 . V_40 = V_1 -> V_7 . V_40 ;
V_72 . V_42 = V_1 -> V_7 . V_42 ;
#endif
F_22 ( V_1 -> V_2 , V_72 ) ;
return 0 ;
}
int
F_35 ( T_1 * V_1 , int V_101 , const char * V_90 , T_4 * V_102 )
{
int V_103 , V_12 ;
switch( V_101 ) {
case V_104 :
if ( V_1 -> V_65 ) {
F_27 ( L_89 ) ;
return 1 ;
}
V_1 -> V_65 = F_19 ( V_90 ) ;
break;
case 'a' :
if ( F_13 ( V_1 , V_90 ) == FALSE ) {
F_27 ( L_90 , V_90 ) ;
return 1 ;
}
break;
#ifdef F_5
case 'A' :
if ( F_25 ( V_1 , V_90 ) == FALSE ) {
F_27 ( L_91 , V_90 ) ;
return 1 ;
}
break;
#endif
case 'b' :
V_1 -> V_51 = TRUE ;
if ( F_23 ( V_1 , V_90 ) == FALSE ) {
F_27 ( L_92 , V_90 ) ;
return 1 ;
}
break;
#ifdef F_4
case 'B' :
if ( V_1 -> V_2 -> V_71 > 0 ) {
V_3 V_72 ;
V_72 = F_12 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_71 - 1 ) ;
V_1 -> V_2 = F_20 ( V_1 -> V_2 , V_1 -> V_2 -> V_71 - 1 ) ;
V_72 . V_26 = F_15 ( V_90 , L_93 ) ;
F_22 ( V_1 -> V_2 , V_72 ) ;
} else {
V_1 -> V_7 . V_26 = F_15 ( V_90 , L_93 ) ;
}
break;
#endif
case 'c' :
V_1 -> V_59 = TRUE ;
V_1 -> V_60 = F_15 ( V_90 , L_94 ) ;
break;
case 'f' :
F_17 ( V_1 , V_90 ) ;
break;
case 'g' :
V_1 -> V_45 = TRUE ;
break;
case 'H' :
V_1 -> V_48 = FALSE ;
break;
case 'i' :
V_103 = F_26 ( V_1 , V_90 ) ;
if ( V_103 != 0 ) {
return V_103 ;
}
break;
#ifdef F_36
case 'I' :
if ( V_1 -> V_2 -> V_71 > 0 ) {
V_3 V_72 ;
V_72 = F_12 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_71 - 1 ) ;
V_1 -> V_2 = F_20 ( V_1 -> V_2 , V_1 -> V_2 -> V_71 - 1 ) ;
V_72 . V_28 = TRUE ;
F_22 ( V_1 -> V_2 , V_72 ) ;
} else {
V_1 -> V_7 . V_28 = TRUE ;
}
break;
#endif
case 'k' :
* V_102 = TRUE ;
break;
#ifdef F_6
case 'm' :
if ( F_24 ( V_1 , V_90 ) == FALSE ) {
F_27 ( L_95 , V_90 ) ;
return 1 ;
}
break;
#endif
case 'n' :
V_1 -> V_46 = TRUE ;
break;
case 'p' :
if ( V_1 -> V_2 -> V_71 > 0 ) {
V_3 V_72 ;
V_72 = F_12 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_71 - 1 ) ;
V_1 -> V_2 = F_20 ( V_1 -> V_2 , V_1 -> V_2 -> V_71 - 1 ) ;
V_72 . V_15 = FALSE ;
F_22 ( V_1 -> V_2 , V_72 ) ;
} else {
V_1 -> V_7 . V_15 = FALSE ;
}
break;
case 'P' :
V_1 -> V_46 = FALSE ;
break;
#ifdef F_5
case 'r' :
if ( V_1 -> V_2 -> V_71 > 0 ) {
V_3 V_72 ;
V_72 = F_12 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_71 - 1 ) ;
V_1 -> V_2 = F_20 ( V_1 -> V_2 , V_1 -> V_2 -> V_71 - 1 ) ;
V_72 . V_38 = FALSE ;
F_22 ( V_1 -> V_2 , V_72 ) ;
} else {
V_1 -> V_7 . V_38 = FALSE ;
}
break;
#endif
case 's' :
V_12 = F_37 ( V_90 , L_96 ) ;
if ( V_12 == 0 )
V_12 = V_13 ;
if ( V_1 -> V_2 -> V_71 > 0 ) {
V_3 V_72 ;
V_72 = F_12 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_71 - 1 ) ;
V_1 -> V_2 = F_20 ( V_1 -> V_2 , V_1 -> V_2 -> V_71 - 1 ) ;
V_72 . V_11 = TRUE ;
V_72 . V_12 = V_12 ;
F_22 ( V_1 -> V_2 , V_72 ) ;
} else {
V_1 -> V_7 . V_12 = V_12 ;
V_1 -> V_7 . V_11 = TRUE ;
}
break;
case 'S' :
V_1 -> V_47 = TRUE ;
break;
#ifdef F_5
case 'u' :
if ( V_1 -> V_2 -> V_71 > 0 ) {
V_3 V_72 ;
V_72 = F_12 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_71 - 1 ) ;
V_1 -> V_2 = F_20 ( V_1 -> V_2 , V_1 -> V_2 -> V_71 - 1 ) ;
V_72 . V_37 = TRUE ;
F_22 ( V_1 -> V_2 , V_72 ) ;
} else {
V_1 -> V_7 . V_37 = TRUE ;
}
break;
#endif
case 'w' :
V_1 -> V_43 = TRUE ;
F_21 ( V_1 -> V_44 ) ;
V_1 -> V_44 = F_19 ( V_90 ) ;
V_103 = F_38 ( V_1 -> V_44 , & V_1 -> V_66 ) ;
return V_103 ;
case 'y' :
if ( V_1 -> V_2 -> V_71 > 0 ) {
V_3 V_72 ;
V_72 = F_12 ( V_1 -> V_2 , V_3 , V_1 -> V_2 -> V_71 - 1 ) ;
V_1 -> V_2 = F_20 ( V_1 -> V_2 , V_1 -> V_2 -> V_71 - 1 ) ;
V_72 . V_14 = F_39 ( V_90 ) ;
if ( V_72 . V_14 == - 1 ) {
F_27 ( L_97 ,
V_90 ) ;
return 1 ;
}
F_22 ( V_1 -> V_2 , V_72 ) ;
} else {
V_1 -> V_7 . V_14 = F_39 ( V_90 ) ;
if ( V_1 -> V_7 . V_14 == - 1 ) {
F_27 ( L_97 ,
V_90 ) ;
return 1 ;
}
}
break;
default:
F_40 () ;
}
return 0 ;
}
void
F_41 ( T_10 * V_105 , char * V_8 ,
T_4 V_28 )
{
T_6 * V_106 ;
T_11 * V_107 ;
if ( V_105 -> V_108 )
printf ( L_98 ,
V_8 , V_28 ? L_56 : L_99 ) ;
else
printf ( L_100 , V_8 ) ;
for ( V_106 = V_105 -> V_109 ; V_106 != NULL ;
V_106 = F_32 ( V_106 ) ) {
V_107 = ( T_11 * ) V_106 -> V_85 ;
printf ( L_101 , V_107 -> V_8 ) ;
if ( V_107 -> V_110 != NULL )
printf ( L_102 , V_107 -> V_110 ) ;
else
printf ( L_103 ) ;
printf ( L_104 ) ;
}
}
void
F_42 ( T_6 * V_92 )
{
int V_70 ;
T_6 * V_98 ;
T_8 * V_93 ;
V_70 = 1 ;
for ( V_98 = F_31 ( V_92 ) ; V_98 != NULL ;
V_98 = F_32 ( V_98 ) ) {
V_93 = ( T_8 * ) V_98 -> V_85 ;
printf ( L_105 , V_70 ++ , V_93 -> V_8 ) ;
if ( V_93 -> V_97 != NULL ) {
printf ( L_102 , V_93 -> V_97 ) ;
} else {
if ( V_93 -> V_111 != NULL )
printf ( L_102 , V_93 -> V_111 ) ;
}
printf ( L_104 ) ;
}
}
void
F_43 ( T_1 * V_1 , int V_112 )
{
T_3 V_70 ;
V_3 V_72 ;
if ( V_1 -> V_2 -> V_71 > 0 ) {
for ( V_70 = 0 ; V_70 < V_1 -> V_2 -> V_71 ; V_70 ++ ) {
V_72 = F_12 ( V_1 -> V_2 , V_3 , 0 ) ;
V_1 -> V_2 = F_20 ( V_1 -> V_2 , 0 ) ;
if ( V_72 . V_12 < 1 )
V_72 . V_12 = V_13 ;
else if ( V_72 . V_12 < V_112 )
V_72 . V_12 = V_112 ;
F_22 ( V_1 -> V_2 , V_72 ) ;
}
} else {
if ( V_1 -> V_7 . V_12 < 1 )
V_1 -> V_7 . V_12 = V_13 ;
else if ( V_1 -> V_7 . V_12 < V_112 )
V_1 -> V_7 . V_12 = V_112 ;
}
}
void
F_44 ( T_1 * V_1 )
{
if ( V_1 -> V_55 > V_113 ) {
F_27 ( L_106 , V_1 -> V_55 , V_113 ) ;
V_1 -> V_55 = V_113 ;
} else if ( V_1 -> V_55 > V_114 ) {
F_27 ( L_107 , V_1 -> V_55 ) ;
}
#if V_56 > 0
else if ( V_1 -> V_55 < V_56 )
F_27 ( L_108 , V_1 -> V_55 , V_56 ) ;
V_1 -> V_55 = V_56 ;
#endif
}
int
F_45 ( T_1 * V_1 ,
const char * V_115 )
{
int V_103 ;
if ( V_1 -> V_6 != 0 || V_1 -> V_2 -> V_71 != 0 ) {
return 0 ;
}
if ( V_115 != NULL ) {
V_103 = F_26 ( V_1 , V_115 ) ;
return V_103 ;
}
return F_26 ( V_1 , L_109 ) ;
}
static int
F_46 ( const char * V_116 )
{
T_12 V_117 ;
if ( F_47 ( V_116 , & V_117 ) < 0 )
return V_118 ;
if ( F_48 ( V_117 . V_119 ) )
return V_120 ;
else
return 0 ;
}
static T_4
F_38 ( const char * V_44 , T_4 * V_121 )
{
int V_94 ;
* V_121 = FALSE ;
if ( V_44 != NULL ) {
if ( strcmp ( V_44 , L_110 ) == 0 ) {
* V_121 = TRUE ;
} else {
V_94 = F_46 ( V_44 ) ;
switch ( V_94 ) {
case V_122 :
case 0 :
break;
case V_120 :
* V_121 = TRUE ;
break;
default:
break;
}
}
}
return 0 ;
}
void
F_49 ( T_1 * V_1 , T_3 V_123 )
{
V_3 V_72 ;
V_72 = F_12 ( V_1 -> V_2 , V_3 , V_123 ) ;
F_21 ( V_72 . V_8 ) ;
F_21 ( V_72 . V_9 ) ;
if ( V_72 . V_73 != NULL )
F_21 ( V_72 . V_73 ) ;
F_21 ( V_72 . V_10 ) ;
#ifdef F_3
F_21 ( V_72 . V_18 ) ;
F_21 ( V_72 . V_19 ) ;
if ( V_72 . V_20 )
F_50 ( V_72 . V_20 ) ;
if ( V_72 . V_22 != V_23 )
F_51 ( V_72 . V_22 ) ;
F_21 ( V_72 . V_21 ) ;
F_21 ( V_72 . V_24 ) ;
F_21 ( V_72 . V_25 ) ;
#endif
#ifdef F_5
if ( V_72 . V_29 == V_74 ) {
F_21 ( V_72 . V_31 ) ;
F_21 ( V_72 . V_32 ) ;
F_21 ( V_72 . V_35 ) ;
F_21 ( V_72 . V_36 ) ;
}
#endif
V_1 -> V_2 = F_20 ( V_1 -> V_2 , V_123 ) ;
}
void
F_52 ( T_1 * V_1 )
{
T_3 V_70 ;
V_5 V_124 ;
V_3 V_72 ;
for ( V_70 = V_1 -> V_2 -> V_71 ; V_70 != 0 ; V_70 -- )
F_49 ( V_1 , V_70 - 1 ) ;
for ( V_70 = 0 ; V_70 < V_1 -> V_4 -> V_71 ; V_70 ++ ) {
V_124 = F_12 ( V_1 -> V_4 , V_5 , V_70 ) ;
if ( ! V_124 . V_125 && V_124 . V_126 ) {
V_72 . V_8 = F_19 ( V_124 . V_8 ) ;
V_72 . V_9 = F_19 ( V_124 . V_127 ) ;
V_72 . V_73 = F_19 ( V_124 . V_8 ) ;
V_72 . V_14 = V_124 . V_128 ;
V_72 . V_10 = F_19 ( V_124 . V_10 ) ;
V_72 . V_12 = V_124 . V_12 ;
V_72 . V_11 = V_124 . V_11 ;
V_72 . V_15 = V_124 . V_129 ;
V_72 . V_16 = V_124 . V_93 . type ;
#ifdef F_3
V_72 . V_18 = F_19 ( V_124 . V_93 . V_18 ) ;
V_72 . V_19 = NULL ;
V_72 . V_21 = NULL ;
V_72 . V_20 = V_124 . V_130 ;
V_72 . V_22 = V_23 ;
if ( V_72 . V_20 )
F_53 ( V_72 . V_20 ) ;
V_72 . V_21 = NULL ;
V_72 . V_24 = NULL ;
V_72 . V_25 = NULL ;
#endif
#ifdef F_4
V_72 . V_26 = V_124 . V_131 ;
#endif
#ifdef F_36
V_72 . V_28 = V_124 . V_132 ;
#endif
#ifdef F_5
V_72 . V_29 = V_74 ;
V_72 . V_31 = F_19 ( V_124 . V_133 . V_134 . V_31 ) ;
V_72 . V_32 = F_19 ( V_124 . V_133 . V_134 . V_32 ) ;
V_72 . V_33 = V_124 . V_133 . V_134 . V_33 ;
V_72 . V_35 = F_19 ( V_124 . V_133 . V_134 . V_35 ) ;
V_72 . V_36 = F_19 ( V_124 . V_133 . V_134 . V_36 ) ;
V_72 . V_37 = V_124 . V_133 . V_134 . V_37 ;
V_72 . V_38 = V_124 . V_133 . V_134 . V_38 ;
V_72 . V_39 = V_124 . V_133 . V_134 . V_39 ;
#endif
#ifdef F_6
V_72 . V_40 = V_124 . V_133 . V_40 ;
V_72 . V_42 = V_124 . V_133 . V_42 ;
#endif
F_22 ( V_1 -> V_2 , V_72 ) ;
} else {
continue;
}
}
}
static void
F_54 ( T_13 V_135 , T_13 T_14 V_136 )
{
T_15 * V_137 = ( T_15 * ) V_135 ;
if ( V_137 != NULL )
F_21 ( V_137 -> V_8 ) ;
F_21 ( V_135 ) ;
}
static void
F_55 ( T_13 V_135 , T_13 T_14 V_136 )
{
F_21 ( V_135 ) ;
}
void
F_56 ( V_5 * V_124 )
{
if ( V_124 != NULL ) {
F_21 ( V_124 -> V_8 ) ;
F_21 ( V_124 -> V_127 ) ;
F_21 ( V_124 -> V_97 ) ;
F_21 ( V_124 -> V_138 ) ;
F_21 ( V_124 -> V_10 ) ;
F_57 ( V_124 -> V_139 ,
F_54 , NULL ) ;
F_58 ( V_124 -> V_139 ) ;
#ifdef F_5
F_21 ( V_124 -> V_133 . V_134 . V_31 ) ;
F_21 ( V_124 -> V_133 . V_134 . V_32 ) ;
F_21 ( V_124 -> V_133 . V_134 . V_35 ) ;
F_21 ( V_124 -> V_133 . V_134 . V_36 ) ;
#endif
F_21 ( V_124 -> V_93 . V_8 ) ;
F_21 ( V_124 -> V_93 . V_97 ) ;
F_21 ( V_124 -> V_93 . V_111 ) ;
F_59 ( V_124 -> V_93 . V_140 ,
F_55 , NULL ) ;
F_60 ( V_124 -> V_93 . V_140 ) ;
#ifdef F_3
F_21 ( V_124 -> V_93 . V_18 ) ;
#endif
}
}

void
F_1 ( T_1 * V_1 , void * V_2 )
{
V_1 -> V_2 = V_2 ;
V_1 -> V_3 = F_2 ( FALSE , FALSE , sizeof( V_4 ) ) ;
V_1 -> V_5 = F_2 ( FALSE , FALSE , sizeof( V_6 ) ) ;
V_1 -> V_7 = 0 ;
V_1 -> V_8 . V_9 = NULL ;
V_1 -> V_8 . V_10 = NULL ;
V_1 -> V_8 . V_11 = NULL ;
V_1 -> V_8 . V_12 = FALSE ;
V_1 -> V_8 . V_13 = V_14 ;
V_1 -> V_8 . V_15 = - 1 ;
V_1 -> V_8 . V_16 = TRUE ;
#if F_3 ( V_17 ) || F_3 ( V_18 )
V_1 -> V_8 . V_19 = 1 ;
#endif
V_1 -> V_8 . V_20 = FALSE ;
#ifdef F_4
V_1 -> V_8 . V_21 = V_22 ;
V_1 -> V_8 . V_23 = NULL ;
V_1 -> V_8 . V_24 = NULL ;
V_1 -> V_8 . V_25 = V_26 ;
V_1 -> V_8 . V_27 = NULL ;
V_1 -> V_8 . V_28 = NULL ;
V_1 -> V_8 . V_29 = FALSE ;
V_1 -> V_8 . V_30 = TRUE ;
V_1 -> V_8 . V_31 = FALSE ;
#endif
#ifdef F_5
V_1 -> V_8 . V_32 = V_33 ;
V_1 -> V_8 . V_34 = 0 ;
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
V_1 -> V_57 = - 1 ;
#ifdef V_17
V_1 -> V_58 = - 1 ;
#endif
V_1 -> V_59 = V_60 ;
V_1 -> V_61 = FALSE ;
#ifndef V_17
V_1 -> V_62 = F_7 () ;
V_1 -> V_63 = F_8 () ;
#endif
}
void
F_9 ( const char * V_64 , T_2 V_65 , T_1 * V_1 ) {
T_3 V_66 ;
F_10 ( V_64 , V_65 , L_2 ) ;
F_10 ( V_64 , V_65 , L_3 , V_1 -> V_2 ) ;
for ( V_66 = 0 ; V_66 < V_1 -> V_3 -> V_67 ; V_66 ++ ) {
V_4 V_68 ;
V_68 = F_11 ( V_1 -> V_3 , V_4 , V_66 ) ;
F_10 ( V_64 , V_65 , L_4 , V_66 , V_68 . V_9 ) ;
F_10 ( V_64 , V_65 , L_5 , V_66 , V_68 . V_10 ) ;
F_10 ( V_64 , V_65 , L_6 , V_66 , V_68 . V_11 ) ;
F_10 ( V_64 , V_65 , L_7 , V_66 , V_68 . V_12 , V_68 . V_13 ) ;
F_10 ( V_64 , V_65 , L_8 , V_66 , V_68 . V_15 ) ;
F_10 ( V_64 , V_65 , L_9 , V_66 , V_68 . V_16 ? L_10 : L_11 ) ;
#if F_3 ( V_17 ) || F_3 ( V_18 )
F_10 ( V_64 , V_65 , L_12 , V_66 , V_68 . V_19 ) ;
#endif
F_10 ( V_64 , V_65 , L_13 , V_66 , V_68 . V_20 ? L_10 : L_11 ) ;
#ifdef F_4
F_10 ( V_64 , V_65 , L_14 , V_66 ,
V_68 . V_21 == V_22 ? L_15 :
V_68 . V_21 == V_69 ? L_16 :
L_17 ) ;
if ( V_68 . V_21 == V_69 ) {
F_10 ( V_64 , V_65 , L_18 , V_66 , V_68 . V_23 ) ;
F_10 ( V_64 , V_65 , L_19 , V_66 , V_68 . V_24 ) ;
}
F_10 ( V_64 , V_65 , L_20 , V_66 ,
V_68 . V_25 == V_26 ? L_21 :
V_68 . V_25 == V_70 ? L_22 :
L_17 ) ;
if ( V_68 . V_25 == V_70 ) {
F_10 ( V_64 , V_65 , L_23 , V_66 , V_68 . V_27 ) ;
F_10 ( V_64 , V_65 , L_24 , V_66 ) ;
}
F_10 ( V_64 , V_65 , L_25 , V_66 , V_68 . V_29 ) ;
F_10 ( V_64 , V_65 , L_26 , V_66 , V_68 . V_30 ) ;
F_10 ( V_64 , V_65 , L_27 , V_66 , V_68 . V_31 ) ;
#endif
#ifdef F_5
F_10 ( V_64 , V_65 , L_28 , V_66 , V_68 . V_32 ) ;
F_10 ( V_64 , V_65 , L_29 , V_66 , V_68 . V_34 ) ;
#endif
}
F_10 ( V_64 , V_65 , L_30 , V_1 -> V_8 . V_9 ) ;
F_10 ( V_64 , V_65 , L_31 , V_1 -> V_8 . V_10 ) ;
F_10 ( V_64 , V_65 , L_32 , V_1 -> V_8 . V_11 ) ;
F_10 ( V_64 , V_65 , L_33 , V_1 -> V_8 . V_12 , V_1 -> V_8 . V_13 ) ;
F_10 ( V_64 , V_65 , L_34 , V_1 -> V_8 . V_15 ) ;
F_10 ( V_64 , V_65 , L_35 , V_1 -> V_8 . V_16 ? L_10 : L_11 ) ;
#if F_3 ( V_17 ) || F_3 ( V_18 )
F_10 ( V_64 , V_65 , L_36 , V_1 -> V_8 . V_19 ) ;
#endif
F_10 ( V_64 , V_65 , L_37 , V_1 -> V_8 . V_20 ? L_10 : L_11 ) ;
#ifdef F_4
F_10 ( V_64 , V_65 , L_38 ,
V_1 -> V_8 . V_21 == V_22 ? L_15 :
V_1 -> V_8 . V_21 == V_69 ? L_16 :
L_17 ) ;
if ( V_1 -> V_8 . V_21 == V_69 ) {
F_10 ( V_64 , V_65 , L_39 , V_1 -> V_8 . V_23 ) ;
F_10 ( V_64 , V_65 , L_40 , V_1 -> V_8 . V_24 ) ;
}
F_10 ( V_64 , V_65 , L_41 ,
V_1 -> V_8 . V_25 == V_26 ? L_21 :
V_1 -> V_8 . V_25 == V_70 ? L_22 :
L_17 ) ;
if ( V_1 -> V_8 . V_25 == V_70 ) {
F_10 ( V_64 , V_65 , L_42 , V_1 -> V_8 . V_27 ) ;
F_10 ( V_64 , V_65 , L_43 ) ;
}
F_10 ( V_64 , V_65 , L_44 , V_1 -> V_8 . V_29 ) ;
F_10 ( V_64 , V_65 , L_45 , V_1 -> V_8 . V_30 ) ;
F_10 ( V_64 , V_65 , L_46 , V_1 -> V_8 . V_31 ) ;
#endif
#ifdef F_5
F_10 ( V_64 , V_65 , L_47 , V_1 -> V_8 . V_32 ) ;
F_10 ( V_64 , V_65 , L_48 , V_1 -> V_8 . V_34 ) ;
#endif
F_10 ( V_64 , V_65 , L_49 , V_1 -> V_35 ) ;
F_10 ( V_64 , V_65 , L_50 , ( V_1 -> V_36 ) ? V_1 -> V_36 : L_51 ) ;
F_10 ( V_64 , V_65 , L_52 , V_1 -> V_37 ) ;
F_10 ( V_64 , V_65 , L_53 , ( V_1 -> V_38 ) ? L_54 : L_55 ) ;
F_10 ( V_64 , V_65 , L_56 , V_1 -> V_39 ) ;
F_10 ( V_64 , V_65 , L_57 , V_1 -> V_40 ) ;
F_10 ( V_64 , V_65 , L_58 , V_1 -> V_41 ) ;
F_10 ( V_64 , V_65 , L_59 , V_1 -> V_43 ) ;
F_10 ( V_64 , V_65 , L_60 , V_1 -> V_44 , V_1 -> V_45 ) ;
F_10 ( V_64 , V_65 , L_61 , V_1 -> V_46 , V_1 -> V_47 ) ;
F_10 ( V_64 , V_65 , L_62 , V_1 -> V_49 , V_1 -> V_50 ) ;
F_10 ( V_64 , V_65 , L_63 , V_1 -> V_51 , V_1 -> V_52 ) ;
F_10 ( V_64 , V_65 , L_64 , V_1 -> V_53 , V_1 -> V_54 ) ;
F_10 ( V_64 , V_65 , L_65 , V_1 -> V_55 , V_1 -> V_56 ) ;
F_10 ( V_64 , V_65 , L_66 , V_1 -> V_57 ) ;
#ifdef V_17
F_10 ( V_64 , V_65 , L_67 , V_1 -> V_58 ) ;
#endif
}
static T_4
F_12 ( T_1 * V_1 , const char * V_71 )
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
if ( strcmp ( V_71 , L_68 ) == 0 ) {
V_1 -> V_55 = TRUE ;
V_1 -> V_56 = F_13 ( V_72 , L_69 ) ;
} else if ( strcmp ( V_71 , L_70 ) == 0 ) {
V_1 -> V_53 = TRUE ;
V_1 -> V_54 = F_13 ( V_72 , L_71 ) ;
} else if ( strcmp ( V_71 , L_72 ) == 0 ) {
V_1 -> V_43 = TRUE ;
V_1 -> V_49 = TRUE ;
V_1 -> V_50 = F_13 ( V_72 , L_73 ) ;
} else {
return FALSE ;
}
* V_73 = ':' ;
return TRUE ;
}
static T_4
F_14 ( T_1 * V_1 , const char * V_75 )
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
if ( strcmp ( V_75 , L_72 ) == 0 ) {
V_1 -> V_46 = TRUE ;
V_1 -> V_47 = F_13 ( V_72 , L_74 ) ;
} else if ( strcmp ( V_75 , L_70 ) == 0 ) {
V_1 -> V_53 = TRUE ;
V_1 -> V_54 = F_13 ( V_72 , L_75 ) ;
} else if ( strcmp ( V_75 , L_68 ) == 0 ) {
V_1 -> V_44 = TRUE ;
V_1 -> V_45 = F_13 ( V_72 , L_76 ) ;
}
* V_73 = ':' ;
return TRUE ;
}
static T_4
F_15 ( T_1 * V_1 , const char * V_75 )
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
if ( strcmp ( V_75 , L_77 ) == 0 ) {
if ( V_1 -> V_3 -> V_67 > 0 ) {
V_4 V_68 ;
V_68 = F_11 ( V_1 -> V_3 , V_4 , V_1 -> V_3 -> V_67 - 1 ) ;
V_1 -> V_3 = F_16 ( V_1 -> V_3 , V_1 -> V_3 -> V_67 - 1 ) ;
V_68 . V_32 = V_76 ;
V_68 . V_34 = F_13 ( V_72 , L_78 ) ;
F_17 ( V_1 -> V_3 , V_68 ) ;
} else {
V_1 -> V_8 . V_32 = V_76 ;
V_1 -> V_8 . V_34 = F_13 ( V_72 , L_78 ) ;
}
} else if ( strcmp ( V_75 , L_79 ) == 0 ) {
if ( V_1 -> V_3 -> V_67 > 0 ) {
V_4 V_68 ;
V_68 = F_11 ( V_1 -> V_3 , V_4 , V_1 -> V_3 -> V_67 - 1 ) ;
V_1 -> V_3 = F_16 ( V_1 -> V_3 , V_1 -> V_3 -> V_67 - 1 ) ;
V_68 . V_32 = V_77 ;
V_68 . V_34 = F_13 ( V_72 , L_80 ) ;
F_17 ( V_1 -> V_3 , V_68 ) ;
} else {
V_1 -> V_8 . V_32 = V_77 ;
V_1 -> V_8 . V_34 = F_13 ( V_72 , L_80 ) ;
}
}
* V_73 = ':' ;
return TRUE ;
}
static T_4
F_18 ( T_1 * V_1 , const char * V_75 )
{
T_5 * V_72 = NULL , * V_73 ;
V_73 = strchr ( V_75 , ':' ) ;
if ( V_73 == NULL )
return FALSE ;
V_72 = V_73 ;
* V_72 ++ = '\0' ;
while ( isspace ( ( V_74 ) * V_72 ) )
V_72 ++ ;
if ( V_1 -> V_3 -> V_67 > 0 ) {
V_4 V_68 ;
V_68 = F_11 ( V_1 -> V_3 , V_4 , V_1 -> V_3 -> V_67 - 1 ) ;
V_1 -> V_3 = F_16 ( V_1 -> V_3 , V_1 -> V_3 -> V_67 - 1 ) ;
V_68 . V_25 = V_70 ;
V_68 . V_27 = F_19 ( V_75 ) ;
V_68 . V_28 = F_19 ( V_72 ) ;
F_17 ( V_1 -> V_3 , V_68 ) ;
} else {
V_1 -> V_8 . V_25 = V_70 ;
V_1 -> V_8 . V_27 = F_19 ( V_75 ) ;
V_1 -> V_8 . V_28 = F_19 ( V_72 ) ;
}
* V_73 = ':' ;
return TRUE ;
}
static int
F_20 ( T_1 * V_1 , const char * V_78 )
{
long V_79 ;
char * V_72 ;
T_6 * V_80 ;
T_7 * V_81 ;
int V_82 ;
T_5 * V_83 ;
V_4 V_68 ;
V_79 = strtol ( V_78 , & V_72 , 10 ) ;
if ( V_72 != NULL && * V_72 == '\0' ) {
if ( V_79 < 0 ) {
F_21 ( L_81 ) ;
return 1 ;
}
if ( V_79 > V_84 ) {
F_21 ( L_82 ,
V_84 ) ;
return 1 ;
}
if ( V_79 == 0 ) {
F_21 ( L_83 ) ;
return 1 ;
}
V_80 = F_22 ( & V_82 , & V_83 ) ;
if ( V_80 == NULL ) {
switch ( V_82 ) {
case V_85 :
case V_86 :
F_21 ( L_84 , V_83 ) ;
F_23 ( V_83 ) ;
break;
case V_87 :
F_21 ( L_85 ) ;
break;
}
return 2 ;
}
V_81 = ( T_7 * ) F_24 ( V_80 , V_79 - 1 ) ;
if ( V_81 == NULL ) {
F_21 ( L_83 ) ;
return 1 ;
}
V_68 . V_9 = F_19 ( V_81 -> V_9 ) ;
F_25 ( V_80 ) ;
} else {
V_68 . V_9 = F_19 ( V_78 ) ;
}
V_68 . V_10 = F_19 ( V_1 -> V_8 . V_10 ) ;
V_68 . V_11 = F_19 ( V_1 -> V_8 . V_11 ) ;
V_68 . V_13 = V_1 -> V_8 . V_13 ;
V_68 . V_12 = V_1 -> V_8 . V_12 ;
V_68 . V_15 = V_1 -> V_8 . V_15 ;
V_68 . V_16 = V_1 -> V_8 . V_16 ;
#if F_3 ( V_17 ) || F_3 ( V_18 )
V_68 . V_19 = V_1 -> V_8 . V_19 ;
#endif
V_68 . V_20 = V_1 -> V_8 . V_20 ;
#ifdef F_4
V_68 . V_21 = V_1 -> V_8 . V_21 ;
V_68 . V_23 = F_19 ( V_1 -> V_8 . V_23 ) ;
V_68 . V_24 = F_19 ( V_1 -> V_8 . V_24 ) ;
V_68 . V_25 = V_1 -> V_8 . V_25 ;
V_68 . V_27 = F_19 ( V_1 -> V_8 . V_27 ) ;
V_68 . V_28 = F_19 ( V_1 -> V_8 . V_28 ) ;
V_68 . V_29 = V_1 -> V_8 . V_29 ;
V_68 . V_30 = V_1 -> V_8 . V_30 ;
V_68 . V_31 = V_1 -> V_8 . V_31 ;
#endif
#ifdef F_5
V_68 . V_32 = V_1 -> V_8 . V_32 ;
V_68 . V_34 = V_1 -> V_8 . V_34 ;
#endif
F_17 ( V_1 -> V_3 , V_68 ) ;
return 0 ;
}
int
F_26 ( T_1 * V_1 , int V_88 , const char * V_78 , T_4 * V_89 )
{
int V_90 , V_13 ;
switch( V_88 ) {
case 'a' :
if ( F_12 ( V_1 , V_78 ) == FALSE ) {
F_21 ( L_86 , V_78 ) ;
return 1 ;
}
break;
#ifdef F_4
case 'A' :
if ( F_18 ( V_1 , V_78 ) == FALSE ) {
F_21 ( L_87 , V_78 ) ;
return 1 ;
}
break;
#endif
case 'b' :
V_1 -> V_43 = TRUE ;
if ( F_14 ( V_1 , V_78 ) == FALSE ) {
F_21 ( L_88 , V_78 ) ;
return 1 ;
}
break;
#if F_3 ( V_17 ) || F_3 ( V_18 )
case 'B' :
if ( V_1 -> V_3 -> V_67 > 0 ) {
V_4 V_68 ;
V_68 = F_11 ( V_1 -> V_3 , V_4 , V_1 -> V_3 -> V_67 - 1 ) ;
V_1 -> V_3 = F_16 ( V_1 -> V_3 , V_1 -> V_3 -> V_67 - 1 ) ;
V_68 . V_19 = F_13 ( V_78 , L_89 ) ;
F_17 ( V_1 -> V_3 , V_68 ) ;
} else {
V_1 -> V_8 . V_19 = F_13 ( V_78 , L_89 ) ;
}
break;
#endif
case 'c' :
V_1 -> V_51 = TRUE ;
V_1 -> V_52 = F_13 ( V_78 , L_90 ) ;
break;
case 'f' :
if ( V_1 -> V_3 -> V_67 > 0 ) {
V_4 V_68 ;
V_68 = F_11 ( V_1 -> V_3 , V_4 , V_1 -> V_3 -> V_67 - 1 ) ;
V_1 -> V_3 = F_16 ( V_1 -> V_3 , V_1 -> V_3 -> V_67 - 1 ) ;
F_23 ( V_68 . V_11 ) ;
V_68 . V_11 = F_19 ( V_78 ) ;
F_17 ( V_1 -> V_3 , V_68 ) ;
} else {
F_23 ( V_1 -> V_8 . V_11 ) ;
V_1 -> V_8 . V_11 = F_19 ( V_78 ) ;
}
break;
case 'H' :
V_1 -> V_40 = FALSE ;
break;
case 'i' :
V_90 = F_20 ( V_1 , V_78 ) ;
if ( V_90 != 0 ) {
return V_90 ;
}
break;
#ifdef V_18
case 'I' :
if ( V_1 -> V_3 -> V_67 > 0 ) {
V_4 V_68 ;
V_68 = F_11 ( V_1 -> V_3 , V_4 , V_1 -> V_3 -> V_67 - 1 ) ;
V_1 -> V_3 = F_16 ( V_1 -> V_3 , V_1 -> V_3 -> V_67 - 1 ) ;
V_68 . V_20 = TRUE ;
F_17 ( V_1 -> V_3 , V_68 ) ;
} else {
V_1 -> V_8 . V_20 = TRUE ;
}
break;
#endif
case 'k' :
* V_89 = TRUE ;
break;
#ifdef F_5
case 'm' :
if ( F_15 ( V_1 , V_78 ) == FALSE ) {
F_21 ( L_91 , V_78 ) ;
return 1 ;
}
break;
#endif
case 'n' :
V_1 -> V_38 = TRUE ;
break;
case 'p' :
if ( V_1 -> V_3 -> V_67 > 0 ) {
V_4 V_68 ;
V_68 = F_11 ( V_1 -> V_3 , V_4 , V_1 -> V_3 -> V_67 - 1 ) ;
V_1 -> V_3 = F_16 ( V_1 -> V_3 , V_1 -> V_3 -> V_67 - 1 ) ;
V_68 . V_16 = FALSE ;
F_17 ( V_1 -> V_3 , V_68 ) ;
} else {
V_1 -> V_8 . V_16 = FALSE ;
}
break;
case 'P' :
V_1 -> V_38 = FALSE ;
break;
#ifdef F_4
case 'r' :
if ( V_1 -> V_3 -> V_67 > 0 ) {
V_4 V_68 ;
V_68 = F_11 ( V_1 -> V_3 , V_4 , V_1 -> V_3 -> V_67 - 1 ) ;
V_1 -> V_3 = F_16 ( V_1 -> V_3 , V_1 -> V_3 -> V_67 - 1 ) ;
V_68 . V_30 = FALSE ;
F_17 ( V_1 -> V_3 , V_68 ) ;
} else {
V_1 -> V_8 . V_30 = FALSE ;
}
break;
#endif
case 's' :
V_13 = F_27 ( V_78 , L_92 ) ;
if ( V_13 == 0 )
V_13 = V_14 ;
if ( V_1 -> V_3 -> V_67 > 0 ) {
V_4 V_68 ;
V_68 = F_11 ( V_1 -> V_3 , V_4 , V_1 -> V_3 -> V_67 - 1 ) ;
V_1 -> V_3 = F_16 ( V_1 -> V_3 , V_1 -> V_3 -> V_67 - 1 ) ;
V_68 . V_12 = TRUE ;
V_68 . V_13 = V_13 ;
F_17 ( V_1 -> V_3 , V_68 ) ;
} else {
V_1 -> V_8 . V_13 = V_13 ;
V_1 -> V_8 . V_12 = TRUE ;
}
break;
case 'S' :
V_1 -> V_39 = TRUE ;
break;
#ifdef F_4
case 'u' :
if ( V_1 -> V_3 -> V_67 > 0 ) {
V_4 V_68 ;
V_68 = F_11 ( V_1 -> V_3 , V_4 , V_1 -> V_3 -> V_67 - 1 ) ;
V_1 -> V_3 = F_16 ( V_1 -> V_3 , V_1 -> V_3 -> V_67 - 1 ) ;
V_68 . V_29 = TRUE ;
F_17 ( V_1 -> V_3 , V_68 ) ;
} else {
V_1 -> V_8 . V_29 = TRUE ;
}
break;
#endif
case 'w' :
V_1 -> V_35 = TRUE ;
F_23 ( V_1 -> V_36 ) ;
V_1 -> V_36 = F_19 ( V_78 ) ;
V_90 = F_28 ( V_1 -> V_36 , & V_1 -> V_61 ) ;
return V_90 ;
case 'g' :
V_1 -> V_37 = TRUE ;
break;
case 'y' :
if ( V_1 -> V_3 -> V_67 > 0 ) {
V_4 V_68 ;
V_68 = F_11 ( V_1 -> V_3 , V_4 , V_1 -> V_3 -> V_67 - 1 ) ;
V_1 -> V_3 = F_16 ( V_1 -> V_3 , V_1 -> V_3 -> V_67 - 1 ) ;
V_68 . V_15 = F_29 ( V_78 ) ;
if ( V_68 . V_15 == - 1 ) {
F_21 ( L_93 ,
V_78 ) ;
return 1 ;
}
F_17 ( V_1 -> V_3 , V_68 ) ;
} else {
V_1 -> V_8 . V_15 = F_29 ( V_78 ) ;
if ( V_1 -> V_8 . V_15 == - 1 ) {
F_21 ( L_93 ,
V_78 ) ;
return 1 ;
}
}
break;
default:
F_30 () ;
}
return 0 ;
}
void
F_31 ( T_8 * V_91 , char * V_9 ,
T_4 V_20 )
{
T_6 * V_92 ;
T_9 * V_93 ;
if ( V_91 -> V_94 )
F_32 ( L_94 ,
V_9 , V_20 ? L_51 : L_95 ) ;
else
F_32 ( L_96 , V_9 ) ;
for ( V_92 = V_91 -> V_95 ; V_92 != NULL ;
V_92 = F_33 ( V_92 ) ) {
V_93 = ( T_9 * ) V_92 -> V_96 ;
F_32 ( L_97 , V_93 -> V_9 ) ;
if ( V_93 -> V_97 != NULL )
F_32 ( L_98 , V_93 -> V_97 ) ;
else
F_32 ( L_99 ) ;
F_32 ( L_100 ) ;
}
}
void
F_34 ( T_6 * V_80 )
{
int V_66 ;
T_6 * V_98 ;
T_7 * V_81 ;
V_66 = 1 ;
for ( V_98 = F_35 ( V_80 ) ; V_98 != NULL ;
V_98 = F_33 ( V_98 ) ) {
V_81 = ( T_7 * ) V_98 -> V_96 ;
F_32 ( L_101 , V_66 ++ , V_81 -> V_9 ) ;
if ( V_81 -> V_97 != NULL )
F_32 ( L_98 , V_81 -> V_97 ) ;
F_32 ( L_100 ) ;
}
}
void F_36 ( T_1 * V_1 , int V_99 )
{
T_3 V_66 ;
V_4 V_68 ;
if ( V_1 -> V_3 -> V_67 > 0 ) {
for ( V_66 = 0 ; V_66 < V_1 -> V_3 -> V_67 ; V_66 ++ ) {
V_68 = F_11 ( V_1 -> V_3 , V_4 , 0 ) ;
V_1 -> V_3 = F_16 ( V_1 -> V_3 , 0 ) ;
if ( V_68 . V_13 < 1 )
V_68 . V_13 = V_14 ;
else if ( V_68 . V_13 < V_99 )
V_68 . V_13 = V_99 ;
F_17 ( V_1 -> V_3 , V_68 ) ;
}
} else {
if ( V_1 -> V_8 . V_13 < 1 )
V_1 -> V_8 . V_13 = V_14 ;
else if ( V_1 -> V_8 . V_13 < V_99 )
V_1 -> V_8 . V_13 = V_99 ;
}
}
void F_37 ( T_1 * V_1 )
{
if ( V_1 -> V_47 > V_100 ) {
F_21 ( L_102 , V_1 -> V_47 , V_100 ) ;
V_1 -> V_47 = V_100 ;
} else if ( V_1 -> V_47 > V_101 ) {
F_21 ( L_103 , V_1 -> V_47 ) ;
}
#if V_48 > 0
else if ( V_1 -> V_47 < V_48 )
F_21 ( L_104 , V_1 -> V_47 , V_48 ) ;
V_1 -> V_47 = V_48 ;
#endif
}
T_4 F_38 ( T_1 * V_1 , const char * V_102 )
{
T_6 * V_80 ;
T_7 * V_81 ;
int V_82 ;
T_5 * V_83 ;
V_4 V_68 ;
if ( V_1 -> V_7 == 0 && V_1 -> V_3 -> V_67 == 0 ) {
if ( V_102 != NULL ) {
V_68 . V_9 = F_19 ( V_102 ) ;
} else {
V_80 = F_22 ( & V_82 , & V_83 ) ;
if ( V_80 == NULL ) {
switch ( V_82 ) {
case V_85 :
case V_86 :
F_21 ( L_84 , V_83 ) ;
F_23 ( V_83 ) ;
break;
case V_87 :
F_21 ( L_85 ) ;
break;
}
return FALSE ;
}
V_81 = ( T_7 * ) V_80 -> V_96 ;
V_68 . V_9 = F_19 ( V_81 -> V_9 ) ;
F_25 ( V_80 ) ;
}
if ( V_1 -> V_8 . V_10 ) {
V_68 . V_10 = F_19 ( V_1 -> V_8 . V_10 ) ;
} else {
V_68 . V_10 = NULL ;
}
V_68 . V_11 = F_19 ( V_1 -> V_8 . V_11 ) ;
V_68 . V_13 = V_1 -> V_8 . V_13 ;
V_68 . V_12 = V_1 -> V_8 . V_12 ;
V_68 . V_15 = V_1 -> V_8 . V_15 ;
V_68 . V_16 = V_1 -> V_8 . V_16 ;
#if F_3 ( V_17 ) || F_3 ( V_18 )
V_68 . V_19 = V_1 -> V_8 . V_19 ;
#endif
V_68 . V_20 = V_1 -> V_8 . V_20 ;
#ifdef F_4
V_68 . V_21 = V_1 -> V_8 . V_21 ;
V_68 . V_23 = F_19 ( V_1 -> V_8 . V_23 ) ;
V_68 . V_24 = F_19 ( V_1 -> V_8 . V_24 ) ;
V_68 . V_25 = V_1 -> V_8 . V_25 ;
V_68 . V_27 = F_19 ( V_1 -> V_8 . V_27 ) ;
V_68 . V_28 = F_19 ( V_1 -> V_8 . V_28 ) ;
V_68 . V_29 = V_1 -> V_8 . V_29 ;
V_68 . V_30 = V_1 -> V_8 . V_30 ;
V_68 . V_31 = V_1 -> V_8 . V_31 ;
#endif
#ifdef F_5
V_68 . V_32 = V_1 -> V_8 . V_32 ;
V_68 . V_34 = V_1 -> V_8 . V_34 ;
#endif
F_17 ( V_1 -> V_3 , V_68 ) ;
}
return TRUE ;
}
static int F_39 ( const char * V_103 )
{
T_10 V_104 ;
if ( F_40 ( V_103 , & V_104 ) < 0 )
return V_105 ;
if ( F_41 ( V_104 . V_106 ) )
return V_107 ;
else
return 0 ;
}
static T_4 F_28 ( const char * V_36 , T_4 * V_108 )
{
int V_82 ;
* V_108 = FALSE ;
if ( V_36 != NULL ) {
if ( strcmp ( V_36 , L_105 ) == 0 ) {
* V_108 = TRUE ;
} else {
V_82 = F_39 ( V_36 ) ;
switch ( V_82 ) {
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
F_42 ( T_1 * V_1 )
{
T_3 V_66 ;
V_6 V_110 ;
V_4 V_68 ;
for ( V_66 = V_1 -> V_3 -> V_67 ; V_66 != 0 ; V_66 -- ) {
V_68 = F_11 ( V_1 -> V_3 , V_4 , V_66 - 1 ) ;
F_23 ( V_68 . V_9 ) ;
F_23 ( V_68 . V_10 ) ;
F_23 ( V_68 . V_11 ) ;
#ifdef F_4
if ( V_68 . V_21 == V_69 ) {
F_23 ( V_68 . V_23 ) ;
F_23 ( V_68 . V_24 ) ;
F_23 ( V_68 . V_27 ) ;
F_23 ( V_68 . V_28 ) ;
}
#endif
V_1 -> V_3 = F_16 ( V_1 -> V_3 , V_66 - 1 ) ;
}
for ( V_66 = 0 ; V_66 < V_1 -> V_5 -> V_67 ; V_66 ++ ) {
V_110 = F_11 ( V_1 -> V_5 , V_6 , V_66 ) ;
if ( ! V_110 . V_111 && V_110 . V_112 ) {
V_68 . V_9 = F_19 ( V_110 . V_9 ) ;
V_68 . V_10 = F_19 ( V_110 . V_113 ) ;
V_68 . V_15 = V_110 . V_114 ;
V_68 . V_11 = F_19 ( V_110 . V_11 ) ;
V_68 . V_13 = V_110 . V_13 ;
V_68 . V_12 = V_110 . V_12 ;
V_68 . V_16 = V_110 . V_115 ;
#if F_3 ( V_17 ) || F_3 ( V_18 )
V_68 . V_19 = V_110 . V_116 ;
#endif
#ifdef V_18
V_68 . V_20 = V_110 . V_117 ;
#endif
#ifdef F_4
V_68 . V_21 = V_69 ;
V_68 . V_23 = F_19 ( V_110 . V_118 . V_119 . V_23 ) ;
V_68 . V_24 = F_19 ( V_110 . V_118 . V_119 . V_24 ) ;
V_68 . V_25 = V_110 . V_118 . V_119 . V_25 ;
V_68 . V_27 = F_19 ( V_110 . V_118 . V_119 . V_27 ) ;
V_68 . V_28 = F_19 ( V_110 . V_118 . V_119 . V_28 ) ;
V_68 . V_29 = V_110 . V_118 . V_119 . V_29 ;
V_68 . V_30 = V_110 . V_118 . V_119 . V_30 ;
V_68 . V_31 = V_110 . V_118 . V_119 . V_31 ;
#endif
#ifdef F_5
V_68 . V_32 = V_110 . V_118 . V_32 ;
V_68 . V_34 = V_110 . V_118 . V_34 ;
#endif
F_17 ( V_1 -> V_3 , V_68 ) ;
} else {
continue;
}
}
}

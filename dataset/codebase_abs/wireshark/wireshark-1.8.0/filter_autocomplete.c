static T_1
F_1 ( T_2 * V_1 , int V_2 )
{
unsigned int V_3 ;
int V_4 , V_5 ;
T_3 * V_6 ;
T_3 * V_7 ;
static const T_3 * V_8 [] =
{ L_1 , L_2 ,
L_3 , L_4 ,
L_5 , L_6 ,
L_7 , L_8 } ;
if( ! ( V_5 = F_2 ( F_3 ( V_1 ) ) ) )
return TRUE ;
V_6 = F_4 ( F_3 ( V_1 ) , 0 , ( V_9 ) V_5 ) ;
V_7 = V_6 + ( V_5 - V_2 ) ;
while( V_7 > V_6 ) {
if( * V_7 != ' ' && * V_7 != '(' ) {
for( V_3 = 0 ; V_3 < ( sizeof( V_8 ) / sizeof( V_8 [ 0 ] ) ) ; V_3 ++ ) {
V_4 = ( int ) strlen ( V_8 [ V_3 ] ) ;
if( V_7 - V_6 + 1 < V_4 )
continue;
if( ! strncmp ( V_7 - V_4 + 1 , V_8 [ V_3 ] , V_4 ) ) {
F_5 ( V_6 ) ;
return TRUE ;
}
}
F_5 ( V_6 ) ;
return FALSE ;
}
V_7 -- ;
}
F_5 ( V_6 ) ;
return TRUE ;
}
static void
F_6 ( T_2 * V_1 , T_3 * V_10 )
{
int V_7 ;
T_3 * V_11 ;
T_3 * V_12 ;
V_7 = F_2 ( F_3 ( V_1 ) ) ;
V_11 = F_4 ( F_3 ( V_1 ) , 0 , V_7 ) ;
V_12 = V_11 + strlen ( V_11 ) ;
while( V_12 != V_11 ) {
V_12 -- ;
if( ! F_7 ( * V_12 ) && ( * V_12 ) != '.' && ( * V_12 ) != '_' && ( * V_12 ) != '-' ) {
V_12 ++ ;
break;
}
}
if( strncmp ( V_12 , V_10 , V_7 - ( V_12 - V_11 ) ) ) {
F_8 ( F_3 ( V_1 ) , ( V_9 ) ( V_12 - V_11 ) , V_7 ) ;
V_7 = ( int ) ( V_12 - V_11 ) ;
V_12 = V_10 ;
} else {
V_12 = ( V_10 + strlen ( V_12 ) ) ;
}
F_9 ( F_3 ( V_1 ) , V_12 , ( V_9 ) strlen ( V_12 ) , & V_7 ) ;
F_10 ( F_3 ( V_1 ) , V_7 ) ;
F_5 ( V_11 ) ;
}
static void
F_11 ( T_4 * V_13 ,
T_5 * V_14 ,
T_6 * T_7 V_15 ,
T_8 V_16 )
{
T_2 * V_17 ;
T_9 * V_18 ;
T_10 V_19 ;
T_2 * V_20 ;
T_3 * V_21 ;
V_18 = F_12 ( V_13 ) ;
if ( F_13 ( V_18 , & V_19 , V_14 ) ) {
F_14 ( V_18 , & V_19 , 0 , & V_21 , - 1 ) ;
F_6 ( F_15 ( V_16 ) , V_21 ) ;
F_5 ( V_21 ) ;
}
V_17 = F_16 ( F_15 ( V_16 ) ) ;
V_20 = F_17 ( F_18 ( V_17 ) , V_22 ) ;
if( V_20 != NULL ) {
F_19 ( V_20 ) ;
F_20 ( F_18 ( V_17 ) , V_22 , NULL ) ;
}
}
static T_1
F_21 ( T_2 * V_1 V_15 ,
T_11 * T_12 V_15 ,
T_8 V_16 )
{
T_2 * V_20 ;
V_20 = F_17 ( F_18 ( V_16 ) , V_22 ) ;
if( V_20 != NULL ) {
F_19 ( V_20 ) ;
F_20 ( F_18 ( V_16 ) , V_22 , NULL ) ;
}
return FALSE ;
}
static T_1
F_22 ( T_2 * V_1 , T_2 * V_23 ,
const T_3 * string , unsigned int V_2 )
{
V_9 V_24 = F_2 ( F_3 ( V_1 ) ) ;
V_9 V_25 = V_24 + ( V_9 ) strlen ( string ) - V_2 ;
V_9 V_26 = V_24 ;
if ( V_25 > V_24 ) {
F_9 ( F_3 ( V_1 ) , & string [ V_2 - 1 ] ,
V_25 - V_24 + 1 , & V_26 ) ;
F_10 ( F_3 ( V_1 ) , V_24 + 1 ) ;
F_23 ( F_3 ( V_1 ) , V_24 + 1 , V_25 + 1 ) ;
F_24 ( V_23 ) ;
return TRUE ;
}
return FALSE ;
}
static void
F_25 ( T_2 * V_27 )
{
T_13 * V_28 ;
T_6 * T_7 ;
T_14 * V_29 ;
V_28 = F_26 () ;
T_7 = F_27 ( NULL , V_28 , L_9 , 0 , NULL ) ;
F_28 ( F_29 ( V_27 ) , T_7 ) ;
F_30 ( F_29 ( V_27 ) , FALSE ) ;
V_29 = F_31 ( 1 , V_30 ) ;
F_32 ( F_29 ( V_27 ) , F_33 ( V_29 ) ) ;
F_34 ( V_29 ) ;
}
static void
F_35 ( T_2 * V_27 , const T_3 * V_31 )
{
T_14 * V_29 ;
T_10 V_19 ;
V_29 = F_36 ( F_12 ( F_29 ( V_27 ) ) ) ;
F_37 ( V_29 , & V_19 ) ;
F_38 ( V_29 , & V_19 , 0 , V_31 , - 1 ) ;
}
static T_1
F_39 ( T_2 * V_1 , T_2 * V_23 , T_2 * V_27 ,
const T_3 * V_31 , T_1 * V_32 )
{
T_15 V_33 ;
T_14 * V_29 ;
T_10 V_19 ;
T_16 V_34 ;
T_3 * V_35 ;
unsigned int V_2 = ( unsigned int ) strlen ( V_31 ) ;
T_3 * V_36 = NULL ;
V_9 V_37 = 0 ;
T_1 V_38 = TRUE ;
T_1 V_39 = FALSE ;
V_29 = F_36 ( F_12 ( F_29 ( V_27 ) ) ) ;
if( F_40 ( F_33 ( V_29 ) , & V_19 ) ) {
do {
F_14 ( F_33 ( V_29 ) , & V_19 , 0 , & V_35 , - 1 ) ;
if( ! F_41 ( V_31 , V_35 , V_2 ) ) {
V_38 = F_42 ( F_33 ( V_29 ) , & V_19 ) ;
if ( strlen ( V_35 ) == V_2 ) {
V_39 = TRUE ;
}
V_37 ++ ;
if ( V_37 == 1 )
V_36 = F_43 ( V_35 ) ;
} else {
V_38 = F_44 ( V_29 , & V_19 ) ;
}
F_5 ( V_35 ) ;
} while( V_38 );
if ( V_37 == 1 && ! V_39 && strncmp ( V_31 , V_36 , V_2 ) == 0 ) {
* V_32 = F_22 ( V_1 , V_23 , V_36 , V_2 ) ;
}
if ( ( V_37 == 1 && V_39 && strncmp ( V_31 , V_36 , V_2 ) == 0 ) ||
! F_40 ( F_33 ( V_29 ) , & V_19 ) )
{
F_5 ( V_36 ) ;
return FALSE ;
}
F_5 ( V_36 ) ;
F_45 ( F_29 ( V_27 ) ) ;
#if F_46 ( 3 , 0 , 0 )
F_47 ( V_27 , & V_33 , NULL ) ;
#else
F_48 ( V_27 , & V_33 ) ;
#endif
#if F_46 ( 2 , 18 , 0 )
F_49 ( V_23 , & V_34 ) ;
#else
V_34 = V_23 -> V_40 ;
#endif
F_50 ( V_23 , V_34 . V_41 ,
( V_33 . V_42 < 200 ? V_33 . V_42 + 8 : 200 ) ) ;
F_51 ( F_52 ( V_23 ) , V_34 . V_41 ,
( V_33 . V_42 < 200 ? V_33 . V_42 + 8 : 200 ) ) ;
return TRUE ;
}
return FALSE ;
}
T_1
F_53 ( T_2 * V_1 , T_17 * T_12 , T_8 T_18 V_15 )
{
T_2 * V_23 ;
T_2 * V_43 ;
T_2 * V_13 ;
T_9 * V_18 ;
T_5 * V_14 ;
T_19 * V_44 ;
T_10 V_19 ;
T_3 * V_45 ;
T_3 * V_46 ;
T_1 V_32 = FALSE ;
T_20 V_47 ;
T_3 V_48 ;
V_9 V_7 ;
V_43 = F_16 ( V_1 ) ;
V_23 = F_17 ( F_18 ( V_43 ) , V_22 ) ;
V_47 = T_12 -> V_49 ;
V_48 = T_12 -> string [ 0 ] ;
if( V_47 == V_50 || V_47 == V_51 )
return FALSE ;
if ( V_23 )
F_54 ( V_23 ) ;
V_7 = F_2 ( F_3 ( V_1 ) ) ;
if ( F_7 ( V_48 ) ||
V_47 == V_52 || V_47 == V_53 ||
V_47 == V_54 || V_47 == V_55 )
{
F_55 ( F_3 ( V_1 ) ) ;
} else if ( V_47 == V_56 || V_47 == V_57 ) {
F_23 ( F_3 ( V_1 ) , V_7 , V_7 ) ;
}
V_46 = F_4 ( F_3 ( V_1 ) , 0 , V_7 ) ;
if( ! F_7 ( V_48 ) &&
V_47 != V_52 && V_47 != V_53 &&
V_47 != V_54 && V_47 != V_55 &&
V_47 != V_58 && V_47 != V_56 && V_47 != V_57 &&
V_47 != V_59 && V_47 != V_60 && V_47 != V_61 && V_47 != V_62 &&
V_47 != V_63 )
{
if ( V_23 ) {
F_19 ( V_23 ) ;
F_20 ( F_18 ( V_43 ) , V_22 , NULL ) ;
}
return FALSE ;
}
V_45 = V_46 + strlen ( V_46 ) ;
while( V_45 != V_46 ) {
V_45 -- ;
if( ! F_7 ( ( * V_45 ) ) && ( * V_45 ) != '.' && ( * V_45 ) != '_' && ( * V_45 ) != '-' ) {
V_45 ++ ;
break;
}
}
if( V_47 == V_53 || V_47 == V_52 ) {
if( ! strchr ( V_45 , '.' ) || ! V_23 ) {
T_3 * V_64 ;
if ( V_23 ) {
F_19 ( V_23 ) ;
}
V_64 = F_56 ( V_45 , T_12 -> string , NULL ) ;
V_23 = F_57 ( V_1 , V_64 , FALSE , & V_32 ) ;
F_20 ( F_18 ( V_43 ) , V_22 , V_23 ) ;
F_5 ( V_64 ) ;
F_5 ( V_46 ) ;
return V_32 ;
}
} else if( V_47 == V_63 && ! V_23 ) {
if( strlen ( V_45 ) > 1 ) {
V_45 [ strlen ( V_45 ) - 1 ] = '\0' ;
if( strchr ( V_45 , '.' ) ) {
V_23 = F_57 ( V_1 , V_45 , FALSE , NULL ) ;
F_20 ( F_18 ( V_43 ) , V_22 , V_23 ) ;
} else if( strlen ( V_45 ) && F_1 ( V_1 , ( int ) strlen ( V_45 ) + 2 ) ) {
V_23 = F_57 ( V_1 , V_45 , TRUE , NULL ) ;
F_20 ( F_18 ( V_43 ) , V_22 , V_23 ) ;
}
}
F_5 ( V_46 ) ;
return FALSE ;
} else if( F_7 ( V_48 ) && ! V_23 ) {
T_3 * V_65 = F_56 ( V_45 , T_12 -> string , NULL ) ;
if( ! strchr ( V_65 , '.' ) && F_1 ( V_1 , ( int ) strlen ( V_65 ) ) ) {
V_23 = F_57 ( V_1 , V_65 , TRUE , & V_32 ) ;
F_20 ( F_18 ( V_43 ) , V_22 , V_23 ) ;
}
F_5 ( V_65 ) ;
F_5 ( V_46 ) ;
return V_32 ;
}
if( ! V_23 ) {
F_5 ( V_46 ) ;
return FALSE ;
}
V_13 = F_17 ( F_18 ( V_23 ) , V_66 ) ;
V_44 = F_58 ( F_29 ( V_13 ) ) ;
V_18 = F_12 ( F_29 ( V_13 ) ) ;
switch( V_47 )
{
case V_59 :
case V_60 :
if ( F_59 ( V_44 , & V_18 , & V_19 ) ) {
if ( F_42 ( V_18 , & V_19 ) ) {
if ( V_47 == V_59 ) {
T_10 V_67 ;
V_9 V_37 = 0 ;
do {
V_67 = V_19 ;
} while ( ++ V_37 < 8 && F_42 ( V_18 , & V_19 ) );
V_19 = V_67 ;
}
F_60 ( F_61 ( V_44 ) , & V_19 ) ;
V_14 = F_62 ( V_18 , & V_19 ) ;
F_63 ( F_29 ( V_13 ) , V_14 ,
NULL , FALSE , 0 , 0 ) ;
F_64 ( V_14 ) ;
} else {
F_65 ( V_44 ) ;
}
} else if ( F_40 ( V_18 , & V_19 ) ) {
F_60 ( F_61 ( V_44 ) , & V_19 ) ;
V_14 = F_62 ( V_18 , & V_19 ) ;
F_63 ( F_29 ( V_13 ) , V_14 ,
NULL , FALSE , 0 , 0 ) ;
F_64 ( V_14 ) ;
}
F_5 ( V_46 ) ;
return TRUE ;
case V_61 :
case V_62 :
{
T_10 V_67 ;
if ( F_59 ( V_44 , & V_18 , & V_19 ) ) {
V_14 = F_62 ( V_18 , & V_19 ) ;
if ( F_66 ( V_14 ) ) {
if ( V_47 == V_61 ) {
T_5 * V_68 ;
V_9 V_37 = 0 ;
do {
V_68 = V_14 ;
} while ( ++ V_37 < 8 && F_66 ( V_14 ) );
V_14 = V_68 ;
}
F_67 ( F_61 ( V_44 ) , V_14 ) ;
F_63 ( F_29 ( V_13 ) , V_14 , NULL , FALSE , 0 , 0 ) ;
} else {
F_68 ( V_44 , & V_19 ) ;
}
F_64 ( V_14 ) ;
} else if ( F_40 ( V_18 , & V_19 ) ) {
do {
V_67 = V_19 ;
} while ( F_42 ( V_18 , & V_19 ) );
F_60 ( F_61 ( V_44 ) , & V_67 ) ;
V_14 = F_62 ( V_18 , & V_67 ) ;
F_63 ( F_29 ( V_13 ) , V_14 ,
NULL , FALSE , 0 , 0 ) ;
F_64 ( V_14 ) ;
}
F_5 ( V_46 ) ;
return TRUE ;
}
case V_58 :
case V_56 :
case V_57 :
if( F_59 ( V_44 , & V_18 , & V_19 ) ) {
T_3 * V_69 ;
if( V_47 != V_58 || strchr ( V_45 , '.' ) ) {
F_14 ( V_18 , & V_19 , 0 , & V_69 , - 1 ) ;
F_6 ( V_1 , V_69 ) ;
F_5 ( V_69 ) ;
}
if( V_47 != V_58 ) {
V_32 = TRUE ;
}
}
F_19 ( V_23 ) ;
F_20 ( F_18 ( V_43 ) , V_22 , NULL ) ;
break;
case V_63 :
F_69 ( V_1 , V_13 , V_23 , V_45 , V_43 ) ;
break;
default: {
T_3 * V_70 ;
V_70 = F_56 ( V_45 , T_12 -> string , NULL ) ;
if( ! F_39 ( V_1 , V_23 , V_13 , V_70 , & V_32 ) ) {
F_19 ( V_23 ) ;
F_20 ( F_18 ( V_43 ) , V_22 , NULL ) ;
}
F_5 ( V_70 ) ;
}
}
F_5 ( V_46 ) ;
return V_32 ;
}
static T_1
F_70 ( T_2 * V_1 , T_2 * V_13 , T_2 * V_23 ,
const T_3 * V_71 , T_1 V_72 , T_1 * V_32 )
{
void * V_73 , * V_74 ;
T_21 * V_75 ;
unsigned int V_76 ;
T_22 * V_77 ;
V_9 V_37 = 0 ;
T_1 V_39 = FALSE ;
const T_3 * V_36 = NULL ;
int V_3 ;
V_76 = ( unsigned int ) strlen ( V_71 ) ;
if( V_71 [ V_76 - 1 ] == '.' )
F_71 ( V_71 ) ;
for ( V_3 = F_72 ( & V_73 ) ; V_3 != - 1 ; V_3 = F_73 ( & V_73 ) ) {
V_75 = F_74 ( V_3 ) ;
if ( ! F_75 ( V_75 ) )
continue;
if ( V_72 ) {
const T_3 * V_65 = F_76 ( V_3 ) ;
if ( ! F_41 ( V_71 , V_65 , V_76 ) ) {
F_35 ( V_13 , V_65 ) ;
if ( strlen ( V_65 ) == V_76 ) {
V_39 = TRUE ;
}
V_37 ++ ;
if ( V_37 == 1 )
V_36 = V_65 ;
}
} else {
for ( V_77 = F_77 ( V_3 , & V_74 ) ;
V_77 != NULL ;
V_77 = F_78 ( & V_74 ) )
{
if ( V_77 -> V_78 != NULL )
continue;
if( ! F_41 ( V_71 , V_77 -> V_79 , V_76 ) ) {
F_35 ( V_13 , V_77 -> V_79 ) ;
if ( strlen ( V_77 -> V_79 ) == V_76 ) {
V_39 = TRUE ;
}
V_37 ++ ;
if ( V_37 == 1 )
V_36 = V_77 -> V_79 ;
}
}
}
}
if ( V_37 == 1 && ! V_39 && V_32 &&
strncmp ( V_71 , V_36 , V_76 ) == 0 )
{
* V_32 = F_22 ( V_1 , V_23 , V_36 , V_76 ) ;
}
if ( V_37 == 0 || ( V_37 == 1 && V_39 &&
strncmp ( V_71 , V_36 , V_76 ) == 0 ) )
return FALSE ;
return TRUE ;
}
static void
F_79 ( T_9 * V_18 )
{
F_80 ( F_81 ( V_18 ) ,
V_80 , V_81 ) ;
}
static void
F_82 ( T_9 * V_18 )
{
F_80 ( F_81 ( V_18 ) , 0 , V_81 ) ;
}
static T_2 *
F_57 ( T_2 * V_1 , const T_3 * V_71 ,
T_1 V_72 , T_1 * V_32 )
{
T_2 * V_23 ;
T_2 * V_13 ;
T_2 * V_82 ;
V_9 V_83 , V_84 ;
T_9 * V_18 ;
T_19 * V_44 ;
T_15 V_33 ;
T_2 * V_43 ;
T_16 V_85 ;
V_43 = F_16 ( V_1 ) ;
V_23 = F_83 ( V_86 ) ;
V_82 = F_84 ( NULL , NULL ) ;
F_85 ( F_86 ( V_82 ) , V_87 , V_87 ) ;
F_87 ( F_86 ( V_82 ) , V_88 ) ;
F_88 ( F_89 ( V_23 ) , V_82 ) ;
V_13 = F_90 () ;
F_91 ( F_29 ( V_13 ) , TRUE ) ;
F_25 ( V_13 ) ;
F_20 ( F_18 ( V_23 ) , V_66 , V_13 ) ;
if ( ! F_70 ( V_1 , V_13 , V_23 , V_71 , V_72 , V_32 ) ) {
F_19 ( V_23 ) ;
return NULL ;
}
V_18 = F_12 ( F_29 ( V_13 ) ) ;
if( V_18 )
F_82 ( V_18 ) ;
F_88 ( F_89 ( V_82 ) , V_13 ) ;
F_92 ( V_13 , L_10 , F_93 ( F_11 ) , V_1 ) ;
F_92 ( V_1 , L_11 , F_93 ( F_21 ) , V_43 ) ;
F_92 ( V_23 , L_12 , F_93 ( V_89 ) , NULL ) ;
#if F_46 ( 3 , 0 , 0 )
F_47 ( V_13 , & V_33 , NULL ) ;
#else
F_48 ( V_13 , & V_33 ) ;
#endif
#if F_46 ( 2 , 18 , 0 )
F_49 ( V_1 , & V_85 ) ;
#else
V_85 = V_1 -> V_40 ;
#endif
F_50 ( V_23 , V_85 . V_41 ,
( V_33 . V_42 < 200 ? V_33 . V_42 + 8 : 200 ) ) ;
F_51 ( F_52 ( V_23 ) , V_85 . V_41 ,
( V_33 . V_42 < 200 ? V_33 . V_42 + 8 : 200 ) ) ;
F_94 ( F_95 ( V_1 ) , & V_83 , & V_84 ) ;
#if F_46 ( 3 , 0 , 0 )
V_83 += V_85 . V_90 ;
V_84 += ( V_85 . V_91 + V_85 . V_42 ) ;
#else
V_84 += V_85 . V_42 ;
#endif
F_96 ( F_52 ( V_23 ) , V_83 , V_84 ) ;
F_97 ( V_23 ) ;
V_44 = F_58 ( F_29 ( V_13 ) ) ;
F_65 ( V_44 ) ;
return V_23 ;
}
static void
F_69 ( T_2 * V_1 , T_2 * V_27 , T_2 * V_23 ,
T_3 * V_45 , T_2 * V_92 )
{
T_9 * V_18 ;
T_14 * V_29 ;
T_15 V_33 ;
T_23 V_93 ;
T_1 V_72 = FALSE ;
T_16 V_34 ;
V_93 = strlen ( V_45 ) ;
if ( V_93 <= 1 ) {
F_19 ( V_23 ) ;
F_20 ( F_18 ( V_92 ) , V_22 , NULL ) ;
return;
}
V_93 -- ;
V_45 [ V_93 ] = '\0' ;
if( strchr ( V_45 , '.' ) == NULL ) {
V_72 = TRUE ;
}
V_18 = F_12 ( F_29 ( V_27 ) ) ;
V_29 = F_36 ( V_18 ) ;
F_98 ( V_29 ) ;
F_79 ( V_18 ) ;
if ( ! F_70 ( V_1 , V_27 , V_23 , V_45 , V_72 , NULL ) ) {
F_19 ( V_23 ) ;
F_20 ( F_18 ( V_92 ) , V_22 , NULL ) ;
return;
}
F_82 ( V_18 ) ;
F_45 ( F_29 ( V_27 ) ) ;
#if F_46 ( 3 , 0 , 0 )
F_47 ( V_27 , & V_33 , NULL ) ;
#else
F_48 ( V_27 , & V_33 ) ;
#endif
#if F_46 ( 2 , 18 , 0 )
F_49 ( V_23 , & V_34 ) ;
#else
V_34 = V_23 -> V_40 ;
#endif
F_50 ( V_23 , V_34 . V_41 ,
( V_33 . V_42 < 200 ? V_33 . V_42 + 8 : 200 ) ) ;
F_51 ( F_52 ( V_23 ) , V_34 . V_41 ,
( V_33 . V_42 < 200 ? V_33 . V_42 + 8 : 200 ) ) ;
}
static void
V_89 ( T_2 * V_20 , T_8 V_16 V_15 )
{
F_20 ( F_18 ( V_20 ) , V_22 , NULL ) ;
}
T_1
F_99 ( T_2 * V_20 , T_17 * T_12 , T_8 T_18 V_15 )
{
T_2 * V_23 ;
V_23 = F_17 ( F_18 ( V_20 ) , V_22 ) ;
if( V_23 && T_12 -> V_49 == V_94 ) {
F_19 ( V_23 ) ;
F_20 ( F_18 ( V_20 ) , V_22 , NULL ) ;
return TRUE ;
}
return FALSE ;
}

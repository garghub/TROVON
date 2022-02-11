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
V_20 = ( T_2 * ) F_17 ( F_18 ( V_17 ) , V_22 ) ;
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
V_20 = ( T_2 * ) F_17 ( F_18 ( V_16 ) , V_22 ) ;
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
F_49 ( V_23 , & V_34 ) ;
F_50 ( V_23 , V_34 . V_40 ,
( V_33 . V_41 < 200 ? V_33 . V_41 + 8 : 200 ) ) ;
F_51 ( F_52 ( V_23 ) , V_34 . V_40 ,
( V_33 . V_41 < 200 ? V_33 . V_41 + 8 : 200 ) ) ;
return TRUE ;
}
return FALSE ;
}
T_1
F_53 ( T_2 * V_1 , T_17 * T_12 , T_8 T_18 V_15 )
{
T_2 * V_23 ;
T_2 * V_42 ;
T_2 * V_13 ;
T_9 * V_18 ;
T_5 * V_14 ;
T_19 * V_43 ;
T_10 V_19 ;
T_3 * V_44 ;
T_3 * V_45 = NULL ;
T_1 V_32 = FALSE ;
T_20 V_46 ;
T_21 V_47 = '\0' ;
V_9 V_48 ;
T_3 V_49 [ 6 ] ;
T_3 * V_50 = NULL ;
V_9 V_7 ;
V_42 = F_16 ( V_1 ) ;
V_23 = ( T_2 * ) F_17 ( F_18 ( V_42 ) , V_22 ) ;
V_46 = T_12 -> V_51 ;
if ( V_46 != V_52 ) {
V_47 = F_54 ( V_46 ) ;
V_48 = F_55 ( V_47 , V_49 ) ;
V_50 =
F_56 ( V_49 , V_48 , NULL , NULL , NULL ) ;
}
if ( ! V_50 )
V_50 = F_43 ( L_10 ) ;
if ( T_12 -> V_53 & V_54 )
goto exit;
switch ( V_46 ) {
case V_55 :
case V_56 :
case V_57 :
case V_58 :
goto exit;
}
if ( V_23 )
F_57 ( V_23 ) ;
V_7 = F_2 ( F_3 ( V_1 ) ) ;
if ( F_7 ( V_47 ) ||
V_46 == V_59 || V_46 == V_60 ||
V_46 == V_61 || V_46 == V_62 )
{
F_58 ( F_3 ( V_1 ) ) ;
} else if ( V_46 == V_63 || V_46 == V_64 ) {
F_23 ( F_3 ( V_1 ) , V_7 , V_7 ) ;
}
V_45 = F_4 ( F_3 ( V_1 ) , 0 , V_7 ) ;
if( ! F_7 ( V_47 ) &&
V_46 != V_59 && V_46 != V_60 &&
V_46 != V_61 && V_46 != V_62 &&
V_46 != V_65 && V_46 != V_63 && V_46 != V_64 &&
V_46 != V_66 && V_46 != V_67 && V_46 != V_68 && V_46 != V_69 &&
V_46 != V_70 )
{
if ( V_23 ) {
F_19 ( V_23 ) ;
F_20 ( F_18 ( V_42 ) , V_22 , NULL ) ;
}
return FALSE ;
}
V_44 = V_45 + strlen ( V_45 ) ;
while( V_44 != V_45 ) {
V_44 -- ;
if( ! F_7 ( ( * V_44 ) ) && ( * V_44 ) != '.' && ( * V_44 ) != '_' && ( * V_44 ) != '-' ) {
V_44 ++ ;
break;
}
}
if( V_46 == V_60 || V_46 == V_59 ) {
if( ! strchr ( V_44 , '.' ) || ! V_23 ) {
T_3 * V_71 ;
if ( V_23 ) {
F_19 ( V_23 ) ;
}
V_71 = F_59 ( V_44 , V_50 , NULL ) ;
V_23 = F_60 ( V_1 , V_71 , FALSE , & V_32 ) ;
F_20 ( F_18 ( V_42 ) , V_22 , V_23 ) ;
F_5 ( V_71 ) ;
goto exit;
}
} else if( V_46 == V_70 && ! V_23 ) {
if( strlen ( V_44 ) > 1 ) {
V_44 [ strlen ( V_44 ) - 1 ] = '\0' ;
if( strchr ( V_44 , '.' ) ) {
V_23 = F_60 ( V_1 , V_44 , FALSE , NULL ) ;
F_20 ( F_18 ( V_42 ) , V_22 , V_23 ) ;
} else if( strlen ( V_44 ) && F_1 ( V_1 , ( int ) strlen ( V_44 ) + 2 ) ) {
V_23 = F_60 ( V_1 , V_44 , TRUE , NULL ) ;
F_20 ( F_18 ( V_42 ) , V_22 , V_23 ) ;
}
}
goto exit;
} else if( F_7 ( V_47 ) && ! V_23 ) {
T_3 * V_72 = F_59 ( V_44 , V_50 , NULL ) ;
if( ! strchr ( V_72 , '.' ) && F_1 ( V_1 , ( int ) strlen ( V_72 ) ) ) {
V_23 = F_60 ( V_1 , V_72 , TRUE , & V_32 ) ;
F_20 ( F_18 ( V_42 ) , V_22 , V_23 ) ;
}
F_5 ( V_72 ) ;
goto exit;
}
if( ! V_23 ) {
V_32 = FALSE ;
goto exit;
}
V_13 = ( T_2 * ) F_17 ( F_18 ( V_23 ) , V_73 ) ;
V_43 = F_61 ( F_29 ( V_13 ) ) ;
V_18 = F_12 ( F_29 ( V_13 ) ) ;
switch( V_46 )
{
case V_66 :
case V_67 :
if ( F_62 ( V_43 , & V_18 , & V_19 ) ) {
if ( F_42 ( V_18 , & V_19 ) ) {
if ( V_46 == V_66 ) {
T_10 V_74 ;
V_9 V_37 = 0 ;
do {
V_74 = V_19 ;
} while ( ++ V_37 < 8 && F_42 ( V_18 , & V_19 ) );
V_19 = V_74 ;
}
F_63 ( F_64 ( V_43 ) , & V_19 ) ;
V_14 = F_65 ( V_18 , & V_19 ) ;
F_66 ( F_29 ( V_13 ) , V_14 ,
NULL , FALSE , 0 , 0 ) ;
F_67 ( V_14 ) ;
} else {
F_68 ( V_43 ) ;
}
} else if ( F_40 ( V_18 , & V_19 ) ) {
F_63 ( F_64 ( V_43 ) , & V_19 ) ;
V_14 = F_65 ( V_18 , & V_19 ) ;
F_66 ( F_29 ( V_13 ) , V_14 ,
NULL , FALSE , 0 , 0 ) ;
F_67 ( V_14 ) ;
}
V_32 = TRUE ;
goto exit;
case V_68 :
case V_69 :
{
T_10 V_74 ;
if ( F_62 ( V_43 , & V_18 , & V_19 ) ) {
V_14 = F_65 ( V_18 , & V_19 ) ;
if ( F_69 ( V_14 ) ) {
if ( V_46 == V_68 ) {
T_5 * V_75 ;
V_9 V_37 = 0 ;
do {
V_75 = V_14 ;
} while ( ++ V_37 < 8 && F_69 ( V_14 ) );
V_14 = V_75 ;
}
F_70 ( F_64 ( V_43 ) , V_14 ) ;
F_66 ( F_29 ( V_13 ) , V_14 , NULL , FALSE , 0 , 0 ) ;
} else {
F_71 ( V_43 , & V_19 ) ;
}
F_67 ( V_14 ) ;
} else if ( F_40 ( V_18 , & V_19 ) ) {
do {
V_74 = V_19 ;
} while ( F_42 ( V_18 , & V_19 ) );
F_63 ( F_64 ( V_43 ) , & V_74 ) ;
V_14 = F_65 ( V_18 , & V_74 ) ;
F_66 ( F_29 ( V_13 ) , V_14 ,
NULL , FALSE , 0 , 0 ) ;
F_67 ( V_14 ) ;
}
V_32 = TRUE ;
goto exit;
}
case V_65 :
case V_63 :
case V_64 :
if( F_62 ( V_43 , & V_18 , & V_19 ) ) {
T_3 * V_76 ;
if( V_46 != V_65 || strchr ( V_44 , '.' ) ) {
F_14 ( V_18 , & V_19 , 0 , & V_76 , - 1 ) ;
F_6 ( V_1 , V_76 ) ;
F_5 ( V_76 ) ;
}
if( V_46 != V_65 ) {
V_32 = TRUE ;
}
}
F_19 ( V_23 ) ;
F_20 ( F_18 ( V_42 ) , V_22 , NULL ) ;
break;
case V_70 :
F_72 ( V_1 , V_13 , V_23 , V_44 , V_42 ) ;
break;
default: {
T_3 * V_77 ;
V_77 = F_59 ( V_44 , V_50 , NULL ) ;
if( ! F_39 ( V_1 , V_23 , V_13 , V_77 , & V_32 ) ) {
F_19 ( V_23 ) ;
F_20 ( F_18 ( V_42 ) , V_22 , NULL ) ;
}
F_5 ( V_77 ) ;
}
}
exit:
F_5 ( V_45 ) ;
F_5 ( V_50 ) ;
return V_32 ;
}
static T_1
F_73 ( T_2 * V_1 , T_2 * V_13 , T_2 * V_23 ,
const T_3 * V_78 , T_1 V_79 , T_1 * V_32 )
{
void * V_80 , * V_81 ;
T_22 * V_82 ;
unsigned int V_83 ;
T_23 * V_84 ;
V_9 V_37 = 0 ;
T_1 V_39 = FALSE ;
const T_3 * V_36 = NULL ;
int V_3 ;
V_83 = ( unsigned int ) strlen ( V_78 ) ;
if( V_78 [ V_83 - 1 ] == '.' )
F_74 ( V_78 ) ;
for ( V_3 = F_75 ( & V_80 ) ; V_3 != - 1 ; V_3 = F_76 ( & V_80 ) ) {
V_82 = F_77 ( V_3 ) ;
if ( ! F_78 ( V_82 ) )
continue;
if ( V_79 ) {
const T_3 * V_72 = F_79 ( V_3 ) ;
if ( ! F_41 ( V_78 , V_72 , V_83 ) ) {
F_35 ( V_13 , V_72 ) ;
if ( strlen ( V_72 ) == V_83 ) {
V_39 = TRUE ;
}
V_37 ++ ;
if ( V_37 == 1 )
V_36 = V_72 ;
}
} else {
for ( V_84 = F_80 ( V_3 , & V_81 ) ;
V_84 != NULL ;
V_84 = F_81 ( V_3 , & V_81 ) )
{
if ( V_84 -> V_85 != - 1 )
continue;
if( ! F_41 ( V_78 , V_84 -> V_86 , V_83 ) ) {
F_35 ( V_13 , V_84 -> V_86 ) ;
if ( strlen ( V_84 -> V_86 ) == V_83 ) {
V_39 = TRUE ;
}
V_37 ++ ;
if ( V_37 == 1 )
V_36 = V_84 -> V_86 ;
}
}
}
}
if ( V_37 == 1 && ! V_39 && V_32 &&
strncmp ( V_78 , V_36 , V_83 ) == 0 )
{
* V_32 = F_22 ( V_1 , V_23 , V_36 , V_83 ) ;
}
if ( V_37 == 0 || ( V_37 == 1 && V_39 &&
strncmp ( V_78 , V_36 , V_83 ) == 0 ) )
return FALSE ;
return TRUE ;
}
static void
F_82 ( T_9 * V_18 )
{
F_83 ( F_84 ( V_18 ) ,
V_87 , V_88 ) ;
}
static void
F_85 ( T_9 * V_18 )
{
F_83 ( F_84 ( V_18 ) , 0 , V_88 ) ;
}
static T_2 *
F_60 ( T_2 * V_1 , const T_3 * V_78 ,
T_1 V_79 , T_1 * V_32 )
{
T_2 * V_23 ;
T_2 * V_13 ;
T_2 * V_89 ;
V_9 V_90 , V_91 ;
T_9 * V_18 ;
T_19 * V_43 ;
T_15 V_33 ;
T_2 * V_42 ;
T_16 V_92 ;
V_42 = F_16 ( V_1 ) ;
V_23 = F_86 ( V_93 ) ;
V_89 = F_87 ( NULL , NULL ) ;
F_88 ( F_89 ( V_89 ) , V_94 , V_94 ) ;
F_90 ( F_89 ( V_89 ) , V_95 ) ;
F_91 ( F_92 ( V_23 ) , V_89 ) ;
V_13 = F_93 () ;
F_94 ( F_29 ( V_13 ) , TRUE ) ;
F_25 ( V_13 ) ;
F_20 ( F_18 ( V_23 ) , V_73 , V_13 ) ;
if ( ! F_73 ( V_1 , V_13 , V_23 , V_78 , V_79 , V_32 ) ) {
F_19 ( V_23 ) ;
return NULL ;
}
V_18 = F_12 ( F_29 ( V_13 ) ) ;
if( V_18 )
F_85 ( V_18 ) ;
F_91 ( F_92 ( V_89 ) , V_13 ) ;
F_95 ( V_13 , L_11 , F_96 ( F_11 ) , V_1 ) ;
F_95 ( V_1 , L_12 , F_96 ( F_21 ) , V_42 ) ;
F_95 ( V_23 , L_13 , F_96 ( V_96 ) , NULL ) ;
#if F_46 ( 3 , 0 , 0 )
F_47 ( V_13 , & V_33 , NULL ) ;
#else
F_48 ( V_13 , & V_33 ) ;
#endif
F_49 ( V_1 , & V_92 ) ;
F_50 ( V_23 , V_92 . V_40 ,
( V_33 . V_41 < 200 ? V_33 . V_41 + 8 : 200 ) ) ;
F_51 ( F_52 ( V_23 ) , V_92 . V_40 ,
( V_33 . V_41 < 200 ? V_33 . V_41 + 8 : 200 ) ) ;
F_97 ( F_98 ( V_1 ) , & V_90 , & V_91 ) ;
#if F_46 ( 3 , 0 , 0 )
V_90 += V_92 . V_97 ;
V_91 += ( V_92 . V_98 + V_92 . V_41 ) ;
#else
V_91 += V_92 . V_41 ;
#endif
F_99 ( F_52 ( V_23 ) , V_90 , V_91 ) ;
F_100 ( V_23 ) ;
V_43 = F_61 ( F_29 ( V_13 ) ) ;
F_68 ( V_43 ) ;
return V_23 ;
}
static void
F_72 ( T_2 * V_1 , T_2 * V_27 , T_2 * V_23 ,
T_3 * V_44 , T_2 * V_99 )
{
T_9 * V_18 ;
T_14 * V_29 ;
T_15 V_33 ;
T_24 V_100 ;
T_1 V_79 = FALSE ;
T_16 V_34 ;
V_100 = strlen ( V_44 ) ;
if ( V_100 <= 1 ) {
F_19 ( V_23 ) ;
F_20 ( F_18 ( V_99 ) , V_22 , NULL ) ;
return;
}
V_100 -- ;
V_44 [ V_100 ] = '\0' ;
if( strchr ( V_44 , '.' ) == NULL ) {
V_79 = TRUE ;
}
V_18 = F_12 ( F_29 ( V_27 ) ) ;
V_29 = F_36 ( V_18 ) ;
F_101 ( V_29 ) ;
F_82 ( V_18 ) ;
if ( ! F_73 ( V_1 , V_27 , V_23 , V_44 , V_79 , NULL ) ) {
F_19 ( V_23 ) ;
F_20 ( F_18 ( V_99 ) , V_22 , NULL ) ;
return;
}
F_85 ( V_18 ) ;
F_45 ( F_29 ( V_27 ) ) ;
#if F_46 ( 3 , 0 , 0 )
F_47 ( V_27 , & V_33 , NULL ) ;
#else
F_48 ( V_27 , & V_33 ) ;
#endif
F_49 ( V_23 , & V_34 ) ;
F_50 ( V_23 , V_34 . V_40 ,
( V_33 . V_41 < 200 ? V_33 . V_41 + 8 : 200 ) ) ;
F_51 ( F_52 ( V_23 ) , V_34 . V_40 ,
( V_33 . V_41 < 200 ? V_33 . V_41 + 8 : 200 ) ) ;
}
static void
V_96 ( T_2 * V_20 , T_8 V_16 V_15 )
{
F_20 ( F_18 ( V_20 ) , V_22 , NULL ) ;
}
T_1
F_102 ( T_2 * V_20 , T_17 * T_12 , T_8 T_18 V_15 )
{
T_2 * V_23 ;
V_23 = ( T_2 * ) F_17 ( F_18 ( V_20 ) , V_22 ) ;
if( V_23 && T_12 -> V_51 == V_101 ) {
F_19 ( V_23 ) ;
F_20 ( F_18 ( V_20 ) , V_22 , NULL ) ;
return TRUE ;
}
return FALSE ;
}

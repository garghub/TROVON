static T_1 *
F_1 ( T_2 * V_1 , T_1 * V_2 , char * V_3 )
{
char * V_4 ;
T_1 * V_5 ;
V_4 = F_2 ( F_3 () , V_2 , 0 , F_4 ( V_2 ) , V_6 ) ;
V_5 = F_5 ( V_2 , V_4 ) ;
F_6 ( V_1 , V_5 , V_3 ) ;
return V_5 ;
}
static char *
F_7 ( const char * V_7 , T_3 * V_8 )
{
const char * V_9 = V_7 ;
char V_10 ;
char * V_11 , * V_12 ;
char V_13 = 0 ;
char V_14 = FALSE ;
T_3 V_15 = - 1 ;
if ( ! V_7 ) return NULL ;
V_10 = * V_9 ;
V_11 = ( char * ) F_8 ( F_3 () , strlen ( V_7 ) + 1 ) ;
V_12 = V_11 ;
while ( V_10 ) {
if ( V_10 == ':' ) {
V_14 = FALSE ;
if ( V_15 == - 1 ) {
V_15 = ( T_3 ) ( V_12 - V_11 ) ;
}
* ( V_12 ++ ) = V_13 = V_10 ;
V_9 ++ ;
} else if ( V_10 == ';' || V_10 == ',' || V_10 == '=' ) {
V_14 = FALSE ;
* ( V_12 ++ ) = V_13 = V_10 ;
V_9 ++ ;
} else if ( V_10 == ' ' || V_10 == '\t' ) {
V_14 = TRUE ;
V_9 ++ ;
} else if ( V_10 == '\n' ) {
V_14 = FALSE ;
if ( ( V_10 = * ( V_9 + 1 ) ) ) {
if ( V_10 == ' ' || V_10 == '\t' ) {
V_14 = TRUE ;
V_9 += 2 ;
} else {
* V_12 = V_10 = 0 ;
}
}
} else if ( V_10 == '\r' ) {
V_14 = FALSE ;
if ( ( V_10 = * ( V_9 + 1 ) ) ) {
if ( V_10 == '\n' ) {
if ( ( V_10 = * ( V_9 + 2 ) ) ) {
if ( V_10 == ' ' || V_10 == '\t' ) {
V_14 = TRUE ;
V_9 += 3 ;
} else {
* V_12 = V_10 = 0 ;
}
}
} else if ( V_10 == ' ' || V_10 == '\t' ) {
V_14 = TRUE ;
V_9 += 2 ;
} else {
* V_12 = V_10 = 0 ;
}
}
} else if ( V_10 == '"' ) {
V_14 = FALSE ;
* ( V_12 ++ ) = V_10 ;
while ( V_10 ) {
V_10 = * ( V_12 ++ ) = * ( ++ V_9 ) ;
if ( V_10 == '"' ) {
V_9 ++ ;
break;
}
}
if( V_10 == 0 ) {
V_12 -- ;
}
} else {
if ( V_13 ) {
V_13 = 0 ;
} else {
if ( V_14 ) {
* ( V_12 ++ ) = ' ' ;
}
}
V_14 = FALSE ;
* ( V_12 ++ ) = V_10 ;
V_9 ++ ;
}
if ( V_10 ) {
V_10 = * V_9 ;
}
}
* V_12 = 0 ;
* V_8 = V_15 ;
return ( V_11 ) ;
}
static T_3
F_9 ( const char * V_16 , const char V_10 )
{
T_3 V_17 = 0 ;
const char * V_9 = V_16 ;
while ( * V_9 && * V_9 != V_10 ) {
V_9 ++ ;
V_17 ++ ;
}
if ( * V_9 )
return V_17 ;
return - 1 ;
}
static char * F_10 ( char * V_18 , const char * V_19 , int * V_20 )
{
char * V_21 , * V_9 ;
int V_22 = 0 ;
int V_17 = 0 ;
if( ! V_18 || ! * V_18 || ! V_19 || strlen ( V_19 ) == 0 )
return NULL ;
V_22 = ( int ) strlen ( V_19 ) ;
V_9 = V_18 ;
while ( * V_9 ) {
while ( ( * V_9 ) && F_11 ( * V_9 ) )
V_9 ++ ;
if ( F_12 ( V_9 , V_19 , V_22 ) == 0 )
break;
V_9 = strchr ( V_9 , ';' ) ;
if ( V_9 == NULL )
{
return NULL ;
}
V_9 ++ ;
}
if ( * V_9 == 0x0 )
return NULL ;
V_21 = V_9 + V_22 ;
if ( V_21 [ 0 ] == 0 ) {
return NULL ;
}
if ( V_21 [ 0 ] == '"' ) {
V_21 ++ ;
V_17 = F_9 ( V_21 , '"' ) ;
if ( V_17 < 0 ) {
return NULL ;
}
} else {
V_9 = V_21 ;
while ( * V_9 ) {
if ( * V_9 == ';' || F_11 ( * V_9 ) )
break;
V_9 ++ ;
V_17 ++ ;
}
}
if( V_20 )
( * V_20 ) = V_17 ;
return V_21 ;
}
static T_4 *
F_13 ( T_2 * V_1 , const char * V_16 )
{
const char * V_21 ;
int V_17 = 0 ;
T_4 * V_23 = NULL ;
const char * type = V_1 -> V_24 ;
char * V_18 ;
T_3 V_25 ;
if ( ( type == NULL ) || ( V_16 == NULL ) ) {
return NULL ;
}
V_18 = F_7 ( V_16 , & V_25 ) ;
V_21 = F_10 ( V_18 , L_1 , & V_17 ) ;
if( ! V_21 ) {
return NULL ;
}
V_23 = ( T_4 * ) F_14 ( sizeof( T_4 ) ) ;
V_23 -> type = type ;
V_23 -> V_26 = F_15 ( V_21 , V_17 ) ;
V_23 -> V_27 = V_17 ;
return V_23 ;
}
static void
F_16 ( void * V_4 )
{
T_4 * V_23 = ( T_4 * ) V_4 ;
if ( V_23 ) {
F_17 ( V_23 -> V_26 ) ;
F_17 ( V_23 ) ;
}
}
static T_3
F_18 ( T_1 * V_5 , T_3 V_21 , const T_5 * V_26 ,
T_3 V_28 , T_3 * V_29 , T_6 * V_30 )
{
T_3 V_31 = V_21 , V_32 , V_33 , V_34 ;
while ( F_19 ( V_5 , V_31 + 2 + V_28 ) ) {
V_34 = V_31 ;
if ( ( ( F_20 ( V_5 , V_31 , ( const T_5 * ) L_2 , 2 ) == 0 )
&& ( F_20 ( V_5 , V_31 + 2 , V_26 , V_28 ) == 0 ) ) )
{
if ( ( F_21 ( V_5 , V_31 + 2 + V_28 + 2 ) >= 0 )
&& ( F_20 ( V_5 , V_31 + 2 + V_28 ,
( const T_5 * ) L_2 , 2 ) == 0 ) ) {
* V_30 = TRUE ;
} else {
* V_30 = FALSE ;
}
V_33 = F_22 ( V_5 , V_31 , - 1 , & V_31 , FALSE ) ;
if ( V_33 == - 1 ) {
* V_29 = - 1 ;
} else {
* V_29 = V_31 - V_34 ;
}
return V_34 ;
}
V_33 = F_22 ( V_5 , V_31 , - 1 , & V_32 , FALSE ) ;
if ( V_33 == - 1 ) {
return - 1 ;
}
V_31 = V_32 ;
}
return - 1 ;
}
static T_3
F_23 ( T_1 * V_5 , T_3 V_21 , const T_5 * V_26 ,
T_3 V_28 , T_3 * V_29 , T_6 * V_30 )
{
T_3 V_31 = V_21 , V_32 , V_33 , V_34 ;
while ( F_19 ( V_5 , V_31 + 2 + V_28 ) ) {
V_33 = F_22 ( V_5 , V_31 , - 1 , & V_32 , FALSE ) ;
if ( V_33 == - 1 ) {
return - 1 ;
}
V_34 = V_31 + V_33 ;
if ( ( ( F_20 ( V_5 , V_32 , ( const T_5 * ) L_2 , 2 ) == 0 )
&& ( F_20 ( V_5 , V_32 + 2 , V_26 , V_28 ) == 0 ) ) )
{
if ( ( F_21 ( V_5 , V_32 + 2 + V_28 + 2 ) >= 0 )
&& ( F_20 ( V_5 , V_32 + 2 + V_28 ,
( const T_5 * ) L_2 , 2 ) == 0 ) ) {
* V_30 = TRUE ;
} else {
* V_30 = FALSE ;
}
V_33 = F_22 ( V_5 , V_32 , - 1 , & V_31 , FALSE ) ;
if ( V_33 == - 1 ) {
* V_29 = - 1 ;
} else {
* V_29 = V_31 - V_34 ;
}
return V_34 ;
}
V_31 = V_32 ;
}
return - 1 ;
}
static T_3
F_24 ( T_7 * V_35 , T_1 * V_5 , const T_5 * V_26 ,
T_3 V_28 , T_6 * V_30 )
{
T_3 V_34 , V_29 ;
V_34 = F_18 ( V_5 , 0 , V_26 , V_28 ,
& V_29 , V_30 ) ;
if ( V_34 == 0 ) {
F_25 ( V_35 , V_36 , V_5 , V_34 , V_29 , V_37 | V_6 ) ;
return V_34 + V_29 ;
} else if ( V_34 > 0 ) {
if ( V_29 > 0 ) {
T_3 V_38 = V_34 + V_29 ;
if ( V_34 > 0 ) {
F_25 ( V_35 , V_39 , V_5 , 0 , V_34 , V_37 ) ;
}
F_25 ( V_35 , V_36 , V_5 , V_34 , V_29 , V_37 | V_6 ) ;
return V_38 ;
}
}
return - 1 ;
}
static T_3
F_26 ( T_7 * V_35 , T_1 * V_5 , const T_5 * V_26 ,
T_3 V_28 , T_2 * V_1 , T_3 V_21 ,
T_6 * V_30 )
{
T_7 * V_40 ;
T_8 * V_41 ;
T_3 V_31 = V_21 , V_32 = 0 ;
char * V_18 = NULL ;
T_3 V_42 , V_34 , V_29 ;
T_9 * V_43 = NULL ;
T_9 * V_44 = NULL ;
char * V_45 = NULL ;
char * V_46 = NULL ;
int V_17 = 0 ;
T_6 V_47 = FALSE ;
V_41 = F_25 ( V_35 , V_48 , V_5 , V_21 , 0 , V_6 | V_37 ) ;
V_40 = F_27 ( V_41 , V_49 ) ;
while ( ! V_47 )
{
T_3 V_50 ;
char * V_51 ;
char * V_52 ;
V_32 = F_28 ( V_5 , V_31 , F_21 ( V_5 , V_31 ) + V_31 , & V_47 ) ;
if ( V_32 == V_31 ) {
break;
}
if ( V_47 ) {
V_32 += 2 ;
}
V_51 = F_2 ( F_3 () , V_5 , V_31 , V_32 - V_31 , V_6 ) ;
V_52 = F_7 ( V_51 , & V_50 ) ;
if ( V_50 <= 0 ) {
F_29 ( V_40 , V_5 , V_31 , V_32 - V_31 ) ;
} else {
T_3 V_53 ;
V_52 [ V_50 ] = '\0' ;
V_53 = F_30 ( V_52 , V_50 ) ;
if ( V_53 == - 1 ) {
F_29 ( V_40 , V_5 , V_31 , V_32 - V_31 ) ;
} else {
char * V_54 = V_52 + V_50 + 1 ;
F_31 ( V_40 ,
V_55 [ V_53 ] , V_5 ,
V_31 , V_32 - V_31 ,
( const char * ) V_54 , L_3 ,
F_32 ( V_5 , V_31 , V_32 - V_31 ) ) ;
switch ( V_53 ) {
case V_56 :
{
T_3 V_57 = F_9 (
V_54 , ';' ) ;
if ( V_57 > 0 ) {
V_54 [ V_57 ] = '\0' ;
V_18 = F_33 ( F_3 () , V_54 + V_57 + 1 ) ;
} else {
V_18 = NULL ;
}
V_43 = F_34 ( F_3 () , V_54 , - 1 ) ;
F_35 ( V_41 , L_4 , V_43 ) ;
if( ( V_46 = F_10 ( V_18 , L_5 , & V_17 ) ) != NULL ) {
V_46 = F_15 ( V_46 , V_17 ) ;
}
}
break;
case V_58 :
{
T_3 V_59 = F_9 ( V_54 , '\r' ) ;
if ( V_59 > 0 ) {
V_54 [ V_59 ] = '\0' ;
}
V_44 = F_34 ( F_3 () , V_54 , - 1 ) ;
}
break;
case V_60 :
{
if( ( V_45 = F_10 ( V_54 , L_6 , & V_17 ) ) != NULL ) {
V_45 = F_15 ( V_45 , V_17 ) ;
}
}
break;
default:
break;
}
}
}
V_31 = V_32 ;
}
V_42 = V_32 ;
V_34 = F_23 ( V_5 , V_42 , V_26 , V_28 ,
& V_29 , V_30 ) ;
if ( V_34 > 0 ) {
T_3 V_61 = V_34 - V_42 ;
T_1 * V_62 = F_36 ( V_5 , V_42 , V_61 ) ;
if ( V_43 ) {
T_6 V_63 ;
if( V_44 && V_64 ) {
if( ! F_12 ( V_44 , L_7 , 6 ) )
V_62 = F_1 ( V_1 , V_62 , V_45 ? V_45 : ( V_46 ? V_46 : V_43 ) ) ;
}
V_63 = F_37 ( V_65 ,
V_43 , V_62 , V_1 , V_40 , V_18 ) ;
if ( ! V_63 ) {
V_63 = F_37 ( V_66 ,
V_43 , V_62 , V_1 , V_40 , V_18 ) ;
}
if ( ! V_63 ) {
const char * V_67 = V_1 -> V_24 ;
V_1 -> V_24 = V_43 ;
F_38 ( V_68 , V_62 , V_1 , V_40 , V_18 ) ;
V_1 -> V_24 = V_67 ;
}
V_18 = NULL ;
} else {
F_39 ( V_69 , V_62 , V_1 , V_40 ) ;
}
F_40 ( V_41 , V_34 - V_21 ) ;
if ( * V_30 == TRUE ) {
F_25 ( V_35 , V_70 , V_5 , V_34 , V_29 , V_37 | V_6 ) ;
} else {
F_25 ( V_35 , V_71 , V_5 , V_34 , V_29 , V_37 | V_6 ) ;
}
F_17 ( V_45 ) ;
F_17 ( V_46 ) ;
return V_34 + V_29 ;
}
F_17 ( V_45 ) ;
F_17 ( V_46 ) ;
return - 1 ;
}
static int F_41 ( T_1 * V_5 , T_2 * V_1 , T_7 * V_35 , void * V_4 )
{
T_7 * V_40 ;
T_8 * V_41 ;
T_8 * V_72 ;
T_4 * V_23 = F_13 ( V_1 , ( const char * ) V_4 ) ;
T_3 V_73 = 0 ;
T_5 * V_26 ;
T_3 V_28 ;
T_6 V_30 = FALSE ;
if ( V_23 == NULL ) {
F_42 ( V_35 , V_1 , & V_74 , V_5 , 0 , - 1 ) ;
F_39 ( V_69 , V_5 , V_1 , V_35 ) ;
return F_4 ( V_5 ) ;
}
V_26 = ( T_5 * ) V_23 -> V_26 ;
V_28 = V_23 -> V_27 ;
V_41 = F_25 ( V_35 , V_75 ,
V_5 , 0 , - 1 , V_37 ) ;
V_40 = F_27 ( V_41 , V_76 ) ;
F_35 ( V_41 , L_8 ,
V_23 -> type , V_23 -> V_26 ) ;
V_72 = F_43 ( V_40 , V_77 ,
V_5 , 0 , 0 , V_1 -> V_24 ) ;
F_44 ( V_72 ) ;
F_45 ( V_1 -> V_78 , V_79 ) ;
V_73 = F_24 ( V_40 , V_5 , V_26 ,
V_28 , & V_30 ) ;
if ( V_73 == - 1 ) {
F_39 ( V_69 , V_5 , V_1 , V_40 ) ;
F_16 ( V_23 ) ;
return F_4 ( V_5 ) ;
}
while ( V_30 == FALSE ) {
V_73 = F_26 ( V_40 , V_5 , V_26 , V_28 ,
V_1 , V_73 , & V_30 ) ;
if ( V_73 == - 1 ) {
F_16 ( V_23 ) ;
return F_4 ( V_5 ) ;
}
}
if ( F_21 ( V_5 , V_73 ) > 0 ) {
F_25 ( V_40 , V_80 , V_5 , V_73 , - 1 , V_37 ) ;
}
F_16 ( V_23 ) ;
return F_4 ( V_5 ) ;
}
static T_3
F_30 ( const char * V_52 , T_10 V_17 )
{
T_10 V_81 ;
for ( V_81 = 1 ; V_81 < F_46 ( V_82 ) ; V_81 ++ ) {
if ( V_17 == strlen ( V_82 [ V_81 ] . V_3 ) &&
F_12 ( V_52 , V_82 [ V_81 ] . V_3 , V_17 ) == 0 )
return V_81 ;
if ( V_82 [ V_81 ] . V_83 != NULL &&
V_17 == strlen ( V_82 [ V_81 ] . V_83 ) &&
F_12 ( V_52 , V_82 [ V_81 ] . V_83 , V_17 ) == 0 )
return V_81 ;
}
return - 1 ;
}
void
F_47 ( void )
{
static T_11 V_84 [] = {
{ & V_77 ,
{ L_9 ,
L_10 ,
V_85 , V_86 , NULL , 0x00 ,
L_11 , V_87
}
} ,
{ & V_48 ,
{ L_12 ,
L_13 ,
V_85 , V_86 , NULL , 0x00 ,
NULL , V_87
}
} ,
{ & V_55 [ V_60 ] ,
{ L_14 ,
L_15 ,
V_85 , V_86 , NULL , 0x00 ,
L_16 , V_87
}
} ,
{ & V_55 [ V_88 ] ,
{ L_17 ,
L_18 ,
V_85 , V_86 , NULL , 0x00 ,
L_19 , V_87
}
} ,
{ & V_55 [ V_89 ] ,
{ L_20 ,
L_21 ,
V_85 , V_86 , NULL , 0x00 ,
L_22 , V_87
}
} ,
{ & V_55 [ V_90 ] ,
{ L_23 ,
L_24 ,
V_85 , V_86 , NULL , 0x00 ,
L_25 , V_87
}
} ,
{ & V_55 [ V_91 ] ,
{ L_26 ,
L_27 ,
V_85 , V_86 , NULL , 0x0 ,
L_28 , V_87
}
} ,
{ & V_55 [ V_58 ] ,
{ L_29 ,
L_30 ,
V_85 , V_86 , NULL , 0x00 ,
L_31 , V_87
}
} ,
{ & V_55 [ V_56 ] ,
{ L_32 ,
L_33 ,
V_85 , V_86 , NULL , 0x0 ,
L_34 , V_87
}
} ,
{ & V_36 , { L_35 , L_36 , V_85 , V_86 , NULL , 0x0 , NULL , V_87 } } ,
{ & V_39 , { L_37 , L_38 , V_92 , V_86 , NULL , 0x0 , NULL , V_87 } } ,
{ & V_70 , { L_39 , L_40 , V_85 , V_86 , NULL , 0x0 , NULL , V_87 } } ,
{ & V_71 , { L_41 , L_42 , V_85 , V_86 , NULL , 0x0 , NULL , V_87 } } ,
{ & V_80 , { L_43 , L_44 , V_92 , V_86 , NULL , 0x0 , NULL , V_87 } } ,
} ;
T_12 * V_93 ;
T_13 * V_94 ;
static T_3 * V_95 [] = {
& V_76 ,
& V_96 ,
& V_49 ,
} ;
static T_14 V_97 [] = {
{ & V_74 , { L_45 , V_98 , V_99 , L_46 , V_100 } } ,
} ;
V_75 = F_48 (
L_47 ,
L_48 ,
L_49 ) ;
F_49 ( V_75 , V_84 , F_46 ( V_84 ) ) ;
F_50 ( V_95 , F_46 ( V_95 ) ) ;
V_94 = F_51 ( V_75 ) ;
F_52 ( V_94 , V_97 , F_46 ( V_97 ) ) ;
V_93 = F_53 ( V_75 , NULL ) ;
F_54 ( V_93 ,
L_50 ,
L_51 ,
L_52
L_53 ,
& V_101 ) ;
F_54 ( V_93 ,
L_54 ,
L_55 ,
L_56
L_57 ,
& V_64 ) ;
V_65 = F_55 (
L_58 ,
L_59 ,
V_85 , V_86 ) ;
}
void
F_56 ( void )
{
T_15 V_102 ;
V_69 = F_57 ( L_60 ) ;
V_68 = F_57 ( L_61 ) ;
V_66 = F_58 ( L_62 ) ;
V_102 = F_59 (
F_41 , V_75 ) ;
F_60 ( L_62 ,
L_63 , V_102 ) ;
F_60 ( L_62 ,
L_64 , V_102 ) ;
F_60 ( L_62 ,
L_65 , V_102 ) ;
F_60 ( L_62 ,
L_66 , V_102 ) ;
F_60 ( L_62 ,
L_67 , V_102 ) ;
F_60 ( L_62 ,
L_68 , V_102 ) ;
F_60 ( L_62 ,
L_69 , V_102 ) ;
}

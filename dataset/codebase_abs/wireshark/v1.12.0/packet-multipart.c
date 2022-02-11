static T_1 *
F_1 ( T_2 * V_1 , T_1 * V_2 , char * V_3 )
{
char * V_4 ;
T_1 * V_5 ;
V_4 = F_2 ( F_3 () , V_2 , 0 , F_4 ( V_2 ) ) ;
V_5 = F_5 ( V_2 , V_4 ) ;
F_6 ( V_1 , V_5 , V_3 ) ;
return V_5 ;
}
static char *
F_7 ( const char * V_6 , T_3 * V_7 )
{
const char * V_8 = V_6 ;
char V_9 ;
char * V_10 , * V_11 ;
char V_12 = 0 ;
char V_13 = FALSE ;
T_3 V_14 = - 1 ;
if ( ! V_6 ) return NULL ;
V_9 = * V_8 ;
V_10 = ( char * ) F_8 ( F_3 () , strlen ( V_6 ) + 1 ) ;
V_11 = V_10 ;
while ( V_9 ) {
if ( V_9 == ':' ) {
V_13 = FALSE ;
if ( V_14 == - 1 ) {
V_14 = ( T_3 ) ( V_11 - V_10 ) ;
}
* ( V_11 ++ ) = V_12 = V_9 ;
V_8 ++ ;
} else if ( V_9 == ';' || V_9 == ',' || V_9 == '=' ) {
V_13 = FALSE ;
* ( V_11 ++ ) = V_12 = V_9 ;
V_8 ++ ;
} else if ( V_9 == ' ' || V_9 == '\t' ) {
V_13 = TRUE ;
V_8 ++ ;
} else if ( V_9 == '\n' ) {
V_13 = FALSE ;
if ( ( V_9 = * ( V_8 + 1 ) ) ) {
if ( V_9 == ' ' || V_9 == '\t' ) {
V_13 = TRUE ;
V_8 += 2 ;
} else {
* V_11 = V_9 = 0 ;
}
}
} else if ( V_9 == '\r' ) {
V_13 = FALSE ;
if ( ( V_9 = * ( V_8 + 1 ) ) ) {
if ( V_9 == '\n' ) {
if ( ( V_9 = * ( V_8 + 2 ) ) ) {
if ( V_9 == ' ' || V_9 == '\t' ) {
V_13 = TRUE ;
V_8 += 3 ;
} else {
* V_11 = V_9 = 0 ;
}
}
} else if ( V_9 == ' ' || V_9 == '\t' ) {
V_13 = TRUE ;
V_8 += 2 ;
} else {
* V_11 = V_9 = 0 ;
}
}
} else if ( V_9 == '"' ) {
V_13 = FALSE ;
* ( V_11 ++ ) = V_9 ;
while ( V_9 ) {
V_9 = * ( V_11 ++ ) = * ( ++ V_8 ) ;
if ( V_9 == '"' ) {
V_8 ++ ;
break;
}
}
if( V_9 == 0 ) {
V_11 -- ;
}
} else {
if ( V_12 ) {
V_12 = 0 ;
} else {
if ( V_13 ) {
* ( V_11 ++ ) = ' ' ;
}
}
V_13 = FALSE ;
* ( V_11 ++ ) = V_9 ;
V_8 ++ ;
}
if ( V_9 ) {
V_9 = * V_8 ;
}
}
* V_11 = 0 ;
* V_7 = V_14 ;
return ( V_10 ) ;
}
static T_3
F_9 ( const char * V_15 , const char V_9 )
{
T_3 V_16 = 0 ;
const char * V_8 = V_15 ;
while ( * V_8 && * V_8 != V_9 ) {
V_8 ++ ;
V_16 ++ ;
}
if ( * V_8 )
return V_16 ;
return - 1 ;
}
static char * F_10 ( char * V_17 , const char * V_18 , int * V_19 )
{
char * V_20 , * V_8 ;
int V_21 = 0 ;
int V_16 = 0 ;
if( ! V_17 || ! * V_17 || ! V_18 || strlen ( V_18 ) == 0 )
return NULL ;
V_21 = ( int ) strlen ( V_18 ) ;
V_8 = V_17 ;
while ( * V_8 ) {
while ( ( * V_8 ) && isspace ( ( V_22 ) * V_8 ) )
V_8 ++ ;
if ( F_11 ( V_8 , V_18 , V_21 ) == 0 )
break;
V_8 = strchr ( V_8 , ';' ) ;
if ( V_8 == NULL )
{
return NULL ;
}
V_8 ++ ;
}
V_20 = V_8 + V_21 ;
if ( V_20 [ 0 ] == 0 ) {
return NULL ;
}
if ( V_20 [ 0 ] == '"' ) {
V_20 ++ ;
V_16 = F_9 ( V_20 , '"' ) ;
if ( V_16 < 0 ) {
return NULL ;
}
} else {
V_8 = V_20 ;
while ( * V_8 ) {
if ( * V_8 == ';' || isspace ( ( V_22 ) * V_8 ) )
break;
V_8 ++ ;
V_16 ++ ;
}
}
if( V_19 )
( * V_19 ) = V_16 ;
return V_20 ;
}
static T_4 *
F_12 ( T_2 * V_1 )
{
const char * V_20 ;
int V_16 = 0 ;
T_4 * V_23 = NULL ;
const char * type = V_1 -> V_24 ;
char * V_17 ;
T_3 V_25 ;
if ( ( type == NULL ) || ( V_1 -> V_26 == NULL ) ) {
return NULL ;
}
V_17 = F_7 ( ( const char * ) V_1 -> V_26 , & V_25 ) ;
V_20 = F_10 ( V_17 , L_1 , & V_16 ) ;
if( ! V_20 ) {
return NULL ;
}
V_23 = ( T_4 * ) F_13 ( sizeof( T_4 ) ) ;
V_23 -> type = type ;
V_23 -> V_27 = F_14 ( V_20 , V_16 ) ;
V_23 -> V_28 = V_16 ;
return V_23 ;
}
static void
F_15 ( void * V_4 )
{
T_4 * V_23 = ( T_4 * ) V_4 ;
if ( V_23 ) {
F_16 ( V_23 -> V_27 ) ;
F_16 ( V_23 ) ;
}
}
static T_3
F_17 ( T_1 * V_5 , T_3 V_20 , const T_5 * V_27 ,
T_3 V_29 , T_3 * V_30 , T_6 * V_31 )
{
T_3 V_32 = V_20 , V_33 , V_34 , V_35 ;
while ( F_18 ( V_5 , V_32 + 2 + V_29 ) > 0 ) {
V_35 = V_32 ;
if ( ( ( F_19 ( V_5 , V_32 , ( const T_5 * ) L_2 , 2 ) == 0 )
&& ( F_19 ( V_5 , V_32 + 2 , V_27 , V_29 ) == 0 ) ) )
{
if ( ( F_18 ( V_5 , V_32 + 2 + V_29 + 2 ) >= 0 )
&& ( F_19 ( V_5 , V_32 + 2 + V_29 ,
( const T_5 * ) L_2 , 2 ) == 0 ) ) {
* V_31 = TRUE ;
} else {
* V_31 = FALSE ;
}
V_34 = F_20 ( V_5 , V_32 , - 1 , & V_32 , FALSE ) ;
if ( V_34 == - 1 ) {
* V_30 = - 1 ;
} else {
* V_30 = V_32 - V_35 ;
}
return V_35 ;
}
V_34 = F_20 ( V_5 , V_32 , - 1 , & V_33 , FALSE ) ;
if ( V_34 == - 1 ) {
return - 1 ;
}
V_32 = V_33 ;
}
return - 1 ;
}
static T_3
F_21 ( T_1 * V_5 , T_3 V_20 , const T_5 * V_27 ,
T_3 V_29 , T_3 * V_30 , T_6 * V_31 )
{
T_3 V_32 = V_20 , V_33 , V_34 , V_35 ;
while ( F_18 ( V_5 , V_32 + 2 + V_29 ) > 0 ) {
V_34 = F_20 ( V_5 , V_32 , - 1 , & V_33 , FALSE ) ;
if ( V_34 == - 1 ) {
return - 1 ;
}
V_35 = V_32 + V_34 ;
if ( ( ( F_19 ( V_5 , V_33 , ( const T_5 * ) L_2 , 2 ) == 0 )
&& ( F_19 ( V_5 , V_33 + 2 , V_27 , V_29 ) == 0 ) ) )
{
if ( ( F_18 ( V_5 , V_33 + 2 + V_29 + 2 ) >= 0 )
&& ( F_19 ( V_5 , V_33 + 2 + V_29 ,
( const T_5 * ) L_2 , 2 ) == 0 ) ) {
* V_31 = TRUE ;
} else {
* V_31 = FALSE ;
}
V_34 = F_20 ( V_5 , V_33 , - 1 , & V_32 , FALSE ) ;
if ( V_34 == - 1 ) {
* V_30 = - 1 ;
} else {
* V_30 = V_32 - V_35 ;
}
return V_35 ;
}
V_32 = V_33 ;
}
return - 1 ;
}
static T_3
F_22 ( T_7 * V_36 , T_1 * V_5 , const T_5 * V_27 ,
T_3 V_29 , T_6 * V_31 )
{
T_3 V_35 , V_30 ;
V_35 = F_17 ( V_5 , 0 , V_27 , V_29 ,
& V_30 , V_31 ) ;
if ( V_35 == 0 ) {
F_23 ( V_36 , V_5 , V_35 , V_30 ,
L_3 ,
F_24 ( V_5 , V_35 , V_30 ) ) ;
return V_35 + V_30 ;
} else if ( V_35 > 0 ) {
if ( V_30 > 0 ) {
T_3 V_37 = V_35 + V_30 ;
if ( V_37 > 0 ) {
F_23 ( V_36 , V_5 , 0 , V_37 ,
L_4 ) ;
}
F_23 ( V_36 , V_5 , V_35 ,
V_30 , L_3 ,
F_24 ( V_5 , V_35 ,
V_30 ) ) ;
return V_37 ;
}
}
return - 1 ;
}
static T_3
F_25 ( T_7 * V_36 , T_1 * V_5 , const T_5 * V_27 ,
T_3 V_29 , T_2 * V_1 , T_3 V_20 ,
T_6 * V_31 )
{
T_7 * V_38 ;
T_8 * V_39 ;
T_3 V_32 = V_20 , V_33 = 0 ;
char * V_17 = NULL ;
T_3 V_40 , V_35 , V_30 ;
T_9 * V_41 = NULL ;
T_9 * V_42 = NULL ;
char * V_43 = NULL ;
char * V_44 = NULL ;
int V_16 = 0 ;
T_6 V_45 = FALSE ;
V_39 = F_26 ( V_36 , V_46 , V_5 , V_20 , 0 , V_47 | V_48 ) ;
V_38 = F_27 ( V_39 , V_49 ) ;
while ( ! V_45 )
{
T_3 V_50 ;
char * V_51 ;
char * V_52 ;
V_33 = F_28 ( V_5 , V_32 , F_18 ( V_5 , V_32 ) + V_32 , & V_45 ) ;
if ( V_33 == V_32 ) {
break;
}
V_51 = F_2 ( F_3 () , V_5 , V_32 , V_33 - V_32 ) ;
V_52 = F_7 ( V_51 , & V_50 ) ;
if ( V_50 <= 0 ) {
F_23 ( V_38 , V_5 , V_32 , V_33 - V_32 ,
L_5 ,
F_24 ( V_5 , V_32 , V_33 - V_32 ) ) ;
} else {
T_3 V_53 ;
V_52 [ V_50 ] = '\0' ;
V_53 = F_29 ( V_52 , V_50 ) ;
if ( V_53 == - 1 ) {
F_23 ( V_38 , V_5 , V_32 ,
V_33 - V_32 ,
L_5 ,
F_24 ( V_5 , V_32 , V_33 - V_32 ) ) ;
} else {
char * V_54 = V_52 + V_50 + 1 ;
F_30 ( V_38 ,
V_55 [ V_53 ] , V_5 ,
V_32 , V_33 - V_32 ,
( const char * ) V_54 , L_5 ,
F_24 ( V_5 , V_32 , V_33 - V_32 ) ) ;
switch ( V_53 ) {
case V_56 :
{
T_3 V_57 = F_9 (
V_54 , ';' ) ;
if ( V_57 > 0 ) {
V_54 [ V_57 ] = '\0' ;
V_17 = F_31 ( F_3 () , V_54 + V_57 + 1 ) ;
} else {
V_17 = NULL ;
}
V_41 = F_32 ( F_3 () , V_54 , - 1 ) ;
F_33 ( V_39 , L_6 , V_41 ) ;
if( ( V_44 = F_10 ( V_17 , L_7 , & V_16 ) ) != NULL ) {
V_44 = F_14 ( V_44 , V_16 ) ;
}
}
break;
case V_58 :
{
T_3 V_59 = F_9 ( V_54 , '\r' ) ;
if ( V_59 > 0 ) {
V_54 [ V_59 ] = '\0' ;
}
V_42 = F_32 ( F_3 () , V_54 , - 1 ) ;
}
break;
case V_60 :
{
if( ( V_43 = F_10 ( V_54 , L_8 , & V_16 ) ) != NULL ) {
V_43 = F_14 ( V_43 , V_16 ) ;
}
}
break;
default:
break;
}
}
}
V_32 = V_33 ;
}
V_40 = V_33 ;
V_35 = F_21 ( V_5 , V_40 , V_27 , V_29 ,
& V_30 , V_31 ) ;
if ( V_35 > 0 ) {
T_3 V_61 = V_35 - V_40 ;
T_1 * V_62 = F_34 ( V_5 , V_40 ,
V_61 , V_61 ) ;
if ( V_41 ) {
void * V_63 = V_1 -> V_26 ;
T_6 V_64 ;
if( V_42 && V_65 ) {
if( ! F_11 ( V_42 , L_9 , 6 ) )
V_62 = F_1 ( V_1 , V_62 , V_43 ? V_43 : ( V_44 ? V_44 : V_41 ) ) ;
}
V_1 -> V_26 = V_17 ;
V_64 = F_35 ( V_66 ,
V_41 , V_62 , V_1 , V_38 , NULL ) ;
if ( ! V_64 ) {
V_64 = F_35 ( V_67 ,
V_41 , V_62 , V_1 , V_38 , NULL ) ;
}
if ( ! V_64 ) {
const char * V_68 = V_1 -> V_24 ;
V_1 -> V_24 = V_41 ;
F_36 ( V_69 , V_62 , V_1 , V_38 ) ;
V_1 -> V_24 = V_68 ;
}
V_1 -> V_26 = V_63 ;
V_17 = NULL ;
} else {
F_36 ( V_70 , V_62 , V_1 , V_38 ) ;
}
F_37 ( V_39 , V_35 - V_20 ) ;
if ( * V_31 == TRUE ) {
F_23 ( V_36 , V_5 ,
V_35 , V_30 ,
L_10 ,
F_24 ( V_5 , V_35 ,
V_30 ) ) ;
} else {
F_23 ( V_36 , V_5 ,
V_35 , V_30 ,
L_11 ,
F_24 ( V_5 , V_35 ,
V_30 ) ) ;
}
F_16 ( V_43 ) ;
F_16 ( V_44 ) ;
return V_35 + V_30 ;
}
F_16 ( V_43 ) ;
F_16 ( V_44 ) ;
return - 1 ;
}
static int F_38 ( T_1 * V_5 , T_2 * V_1 , T_7 * V_36 , void * V_4 V_71 )
{
T_7 * V_38 ;
T_8 * V_39 ;
T_8 * V_72 ;
T_4 * V_23 = F_12 ( V_1 ) ;
T_3 V_73 = 0 ;
T_5 * V_27 ;
T_3 V_29 ;
T_6 V_31 = FALSE ;
if ( V_23 == NULL ) {
F_23 ( V_36 , V_5 , 0 , - 1 ,
L_12
L_13 ) ;
F_36 ( V_70 , V_5 , V_1 , V_36 ) ;
return F_4 ( V_5 ) ;
}
V_27 = ( T_5 * ) V_23 -> V_27 ;
V_29 = V_23 -> V_28 ;
V_39 = F_26 ( V_36 , V_74 ,
V_5 , 0 , - 1 , V_48 ) ;
V_38 = F_27 ( V_39 , V_75 ) ;
F_33 ( V_39 , L_14 ,
V_23 -> type , V_23 -> V_27 ) ;
V_72 = F_39 ( V_38 , V_76 ,
V_5 , 0 , 0 , V_1 -> V_24 ) ;
F_40 ( V_72 ) ;
F_41 ( V_1 -> V_77 , V_78 ) ;
V_73 = F_22 ( V_38 , V_5 , V_27 ,
V_29 , & V_31 ) ;
if ( V_73 == - 1 ) {
F_36 ( V_70 , V_5 , V_1 , V_38 ) ;
F_15 ( V_23 ) ;
return F_4 ( V_5 ) ;
}
while ( V_31 == FALSE ) {
V_73 = F_25 ( V_38 , V_5 , V_27 , V_29 ,
V_1 , V_73 , & V_31 ) ;
if ( V_73 == - 1 ) {
F_15 ( V_23 ) ;
return F_4 ( V_5 ) ;
}
}
if ( F_18 ( V_5 , V_73 ) > 0 ) {
F_23 ( V_38 , V_5 , V_73 , - 1 , L_15 ) ;
}
F_15 ( V_23 ) ;
return F_4 ( V_5 ) ;
}
static T_3
F_29 ( const char * V_52 , T_10 V_16 )
{
T_10 V_79 ;
for ( V_79 = 1 ; V_79 < F_42 ( V_80 ) ; V_79 ++ ) {
if ( V_16 == strlen ( V_80 [ V_79 ] . V_3 ) &&
F_11 ( V_52 , V_80 [ V_79 ] . V_3 , V_16 ) == 0 )
return V_79 ;
if ( V_80 [ V_79 ] . V_81 != NULL &&
V_16 == strlen ( V_80 [ V_79 ] . V_81 ) &&
F_11 ( V_52 , V_80 [ V_79 ] . V_81 , V_16 ) == 0 )
return V_79 ;
}
return - 1 ;
}
void
F_43 ( void )
{
static T_11 V_82 [] = {
{ & V_76 ,
{ L_16 ,
L_17 ,
V_83 , V_84 , NULL , 0x00 ,
L_18 , V_85
}
} ,
{ & V_46 ,
{ L_19 ,
L_20 ,
V_83 , V_84 , NULL , 0x00 ,
NULL , V_85
}
} ,
{ & V_55 [ V_60 ] ,
{ L_21 ,
L_22 ,
V_83 , V_84 , NULL , 0x00 ,
L_23 , V_85
}
} ,
{ & V_55 [ V_86 ] ,
{ L_24 ,
L_25 ,
V_83 , V_84 , NULL , 0x00 ,
L_26 , V_85
}
} ,
{ & V_55 [ V_87 ] ,
{ L_27 ,
L_28 ,
V_83 , V_84 , NULL , 0x00 ,
L_29 , V_85
}
} ,
{ & V_55 [ V_88 ] ,
{ L_30 ,
L_31 ,
V_83 , V_84 , NULL , 0x00 ,
L_32 , V_85
}
} ,
{ & V_55 [ V_89 ] ,
{ L_33 ,
L_34 ,
V_83 , V_84 , NULL , 0x0 ,
L_35 , V_85
}
} ,
{ & V_55 [ V_58 ] ,
{ L_36 ,
L_37 ,
V_83 , V_84 , NULL , 0x00 ,
L_38 , V_85
}
} ,
{ & V_55 [ V_56 ] ,
{ L_39 ,
L_40 ,
V_83 , V_84 , NULL , 0x0 ,
L_41 , V_85
}
} ,
} ;
T_12 * V_90 ;
static T_3 * V_91 [] = {
& V_75 ,
& V_92 ,
& V_49 ,
} ;
V_74 = F_44 (
L_42 ,
L_43 ,
L_44 ) ;
F_45 ( V_74 , V_82 , F_42 ( V_82 ) ) ;
F_46 ( V_91 , F_42 ( V_91 ) ) ;
V_90 = F_47 ( V_74 , NULL ) ;
F_48 ( V_90 ,
L_45 ,
L_46 ,
L_47
L_48 ,
& V_93 ) ;
F_48 ( V_90 ,
L_49 ,
L_50 ,
L_51
L_52 ,
& V_65 ) ;
V_66 = F_49 (
L_53 ,
L_54 ,
V_83 , V_84 ) ;
}
void
F_50 ( void )
{
T_13 V_94 ;
V_70 = F_51 ( L_55 ) ;
V_69 = F_51 ( L_56 ) ;
V_67 = F_52 ( L_57 ) ;
V_94 = F_53 (
F_38 , V_74 ) ;
F_54 ( L_57 ,
L_58 , V_94 ) ;
F_54 ( L_57 ,
L_59 , V_94 ) ;
F_54 ( L_57 ,
L_60 , V_94 ) ;
F_54 ( L_57 ,
L_61 , V_94 ) ;
F_54 ( L_57 ,
L_62 , V_94 ) ;
F_54 ( L_57 ,
L_63 , V_94 ) ;
}

static void
F_1 ( T_1 V_1 , T_1 V_2 )
{
T_2 V_3 = ( T_2 ) V_1 ;
T_3 * V_4 = ( T_3 * ) V_2 ;
const T_4 * V_5 = F_2 ( V_3 ) ;
if ( V_5 && strcmp ( V_4 -> V_6 , V_5 ) == 0 ) {
V_4 -> V_3 = V_3 ;
}
}
static T_5
F_3 ( T_4 * V_7 , const T_4 * V_8 ,
void * V_2 V_9 ,
T_6 T_7 V_9 )
{
T_4 * V_10 [ 4 ] = { NULL , NULL , NULL , NULL } ;
T_4 V_11 [ 4 ] = { ',' , ',' , ',' , '\0' } ;
T_4 * V_12 ;
T_8 V_13 , V_14 ;
T_9 V_15 ;
T_5 V_16 = V_17 ;
T_6 V_18 = FALSE ;
if ( strcmp ( V_7 , V_19 ) == 0 ) {
for ( V_13 = 0 ; V_13 < 4 ; V_13 ++ ) {
V_12 = strchr ( V_8 , V_11 [ V_13 ] ) ;
if ( V_12 == NULL ) {
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ ) {
F_4 ( V_10 [ V_14 ] ) ;
}
return V_20 ;
}
V_10 [ V_13 ] = F_5 ( V_8 , V_12 - V_8 ) ;
V_8 = V_12 + 1 ;
}
V_15 = F_6 ( V_10 [ 0 ] ) ;
if ( V_15 != NULL ) {
T_3 V_4 ;
T_10 V_21 ;
V_4 . V_6 = V_10 [ 3 ] ;
V_4 . V_3 = NULL ;
V_21 = F_7 ( V_15 ) ;
F_8 ( F_9 ( V_15 ) ,
F_1 , & V_4 ) ;
if ( V_4 . V_3 != NULL || F_10 ( V_10 [ 3 ] , V_22 ) == 0 ) {
V_18 = TRUE ;
}
if ( V_18 ) {
if ( F_11 ( V_21 ) ) {
F_12 ( V_10 [ 0 ] , V_10 [ 1 ] , V_4 . V_3 ) ;
} else {
char * V_23 ;
long V_24 ;
V_24 = strtol ( V_10 [ 1 ] , & V_23 , 0 ) ;
if ( V_23 == V_10 [ 0 ] || * V_23 != '\0' || V_24 < 0 ||
( unsigned long ) V_24 > V_25 ) {
V_16 = V_20 ;
V_18 = FALSE ;
} else
F_13 ( V_10 [ 0 ] , ( T_8 ) V_24 , V_4 . V_3 ) ;
}
}
if ( V_18 ) {
F_14 ( V_10 [ 0 ] , V_21 , V_10 [ 1 ] , NULL , NULL ) ;
}
} else {
V_16 = V_20 ;
}
} else {
V_16 = V_26 ;
}
for ( V_13 = 0 ; V_13 < 4 ; V_13 ++ ) {
F_4 ( V_10 [ V_13 ] ) ;
}
return V_16 ;
}
void
F_15 ( void )
{
char * V_27 ;
T_11 * V_28 ;
if ( V_29 ) {
F_16 () ;
}
V_27 = F_17 ( V_30 , TRUE ) ;
if ( ( V_28 = F_18 ( V_27 , L_1 ) ) != NULL ) {
F_19 ( V_27 , V_28 , F_3 , NULL ) ;
fclose ( V_28 ) ;
}
F_4 ( V_27 ) ;
}
void
F_14 ( const T_4 * V_31 , T_10 V_21 ,
T_1 V_7 , T_1 V_8 V_9 ,
T_1 V_2 V_9 )
{
T_12 * V_1 ;
V_1 = F_20 ( T_12 , 1 ) ;
V_1 -> V_32 = F_21 ( V_31 ) ;
V_1 -> V_33 = V_21 ;
switch ( V_21 ) {
case V_34 :
case V_35 :
case V_36 :
case V_37 :
V_1 -> V_38 . V_39 = F_22 ( V_7 ) ;
break;
case V_40 :
case V_41 :
case V_42 :
case V_43 :
V_1 -> V_38 . V_44 = F_21 ( ( char * ) V_7 ) ;
break;
default:
F_23 () ;
}
V_29 = F_24 ( V_29 , V_1 ) ;
}
void
F_16 ( void )
{
T_12 * V_1 ;
T_13 * V_45 ;
F_25 ( F_14 , NULL ) ;
for ( V_45 = V_29 ; V_45 ; V_45 = F_26 ( V_45 ) ) {
V_1 = ( T_12 * ) V_45 -> V_46 ;
switch ( V_1 -> V_33 ) {
case V_34 :
case V_35 :
case V_36 :
case V_37 :
F_27 ( V_1 -> V_32 ,
V_1 -> V_38 . V_39 ) ;
break;
case V_40 :
case V_41 :
case V_42 :
case V_43 :
F_28 ( V_1 -> V_32 ,
V_1 -> V_38 . V_44 ) ;
F_4 ( V_1 -> V_38 . V_44 ) ;
break;
default:
F_23 () ;
}
F_4 ( V_1 -> V_32 ) ;
F_4 ( V_1 ) ;
}
F_29 ( V_29 ) ;
V_29 = NULL ;
F_30 () ;
}
static void
F_31 ( const T_4 * V_31 , T_10 V_21 ,
T_1 V_7 , T_1 V_8 , T_1 V_2 )
{
T_11 * V_47 = ( T_11 * ) V_2 ;
T_2 V_48 , V_49 ;
const T_4 * V_50 , * V_51 ;
V_48 = F_32 ( ( V_52 * ) V_8 ) ;
if ( V_48 == NULL )
V_50 = V_22 ;
else
V_50 = F_2 ( V_48 ) ;
V_49 = F_33 ( ( V_52 * ) V_8 ) ;
if ( V_49 == NULL )
V_51 = V_22 ;
else
V_51 = F_2 ( V_49 ) ;
switch ( V_21 ) {
case V_34 :
case V_35 :
case V_36 :
case V_37 :
fprintf ( V_47 ,
V_19 L_2 ,
V_31 , F_22 ( V_7 ) , V_51 ,
V_50 ) ;
break;
case V_40 :
case V_41 :
case V_42 :
case V_43 :
fprintf ( V_47 ,
V_19 L_3 ,
V_31 , ( T_4 * ) V_7 , V_51 ,
V_50 ) ;
break;
default:
F_23 () ;
break;
}
}
int
F_34 ( T_4 * * V_53 )
{
char * V_54 ;
char * V_27 ;
T_11 * V_47 ;
if ( F_35 ( & V_54 ) == - 1 ) {
* V_53 = F_36 ( L_4 ,
V_54 , F_37 ( V_55 ) ) ;
F_4 ( V_54 ) ;
return - 1 ;
}
V_27 = F_17 ( V_30 , TRUE ) ;
if ( ( V_47 = F_18 ( V_27 , L_5 ) ) == NULL ) {
* V_53 = F_36 ( L_6 ,
V_27 , F_37 ( V_55 ) ) ;
F_4 ( V_27 ) ;
return - 1 ;
}
fputs ( L_7 V_56 L_8
L_9
L_10
L_11
L_12 , V_47 ) ;
F_25 ( F_31 , V_47 ) ;
fclose ( V_47 ) ;
return 0 ;
}
static void
F_38 ( const char * V_31 , const char * V_57 ,
T_1 V_58 )
{
if ( ( V_59 == NULL ) ||
( strcmp ( V_59 , V_31 ) != 0 ) ) {
fprintf ( ( T_11 * ) V_58 , L_13 , V_31 , V_57 ) ;
V_59 = V_31 ;
}
}
static void
F_39 ( const T_4 * T_14 V_9 , T_1 V_3 , T_1 V_58 )
{
int V_60 ;
const T_4 * V_61 ;
const T_4 * V_62 ;
V_60 = F_40 ( ( T_2 ) V_3 ) ;
if ( V_60 != - 1 ) {
V_61 = F_41 ( V_60 ) ;
V_62 = F_42 ( V_60 ) ;
F_43 ( V_61 != NULL ) ;
F_43 ( V_62 != NULL ) ;
if ( ( V_59 == NULL ) ||
( strcmp ( V_59 , V_61 ) != 0 ) ) {
fprintf ( ( T_11 * ) V_58 , L_13 ,
V_61 ,
V_62 ) ;
V_59 = V_61 ;
}
}
}
static T_15
F_44 ( T_16 V_63 , T_16 V_64 )
{
return strcmp ( ( const char * ) V_63 , ( const char * ) V_64 ) ;
}
static void
F_45 ( T_11 * V_58 )
{
V_59 = NULL ;
F_46 ( F_38 , ( T_1 ) V_58 , ( V_65 ) F_44 ) ;
}
static void
F_47 ( T_11 * V_58 , T_4 * V_31 )
{
V_59 = NULL ;
F_48 ( V_31 ,
F_39 ,
( T_1 ) V_58 ) ;
}
static void
F_49 ( const T_4 * T_14 V_9 , T_1 V_3 , T_1 V_2 )
{
int V_60 ;
const T_4 * V_66 ;
T_17 V_67 ;
F_43 ( V_3 ) ;
V_67 = ( T_17 ) V_2 ;
V_60 = F_40 ( ( T_2 ) V_3 ) ;
if ( V_60 != - 1 ) {
V_66 = F_41 ( V_60 ) ;
F_43 ( V_66 != NULL ) ;
if ( strcmp ( V_66 , V_67 -> V_68 ) == 0 ) {
if ( V_67 -> V_69 == 0 ) {
V_67 -> V_70 = ( T_2 ) V_3 ;
}
V_67 -> V_69 ++ ;
}
}
}
T_6 F_50 ( const T_4 * V_71 )
{
T_4 * V_31 ;
T_18 V_72 , V_73 ;
T_4 * V_74 ;
T_4 * V_75 ;
T_4 * V_76 ;
T_4 * V_77 ;
T_2 V_78 ;
T_9 V_79 ;
T_10 V_80 ;
struct V_81 V_82 ;
T_19 V_13 ;
char V_83 ;
F_43 ( V_71 ) ;
V_74 = F_21 ( V_71 ) ;
F_43 ( V_74 ) ;
V_31 = V_74 ;
V_75 = strchr ( V_31 , '=' ) ;
if ( V_75 == NULL ) {
F_51 ( L_14 , V_71 , V_84 ) ;
}
else {
* V_75 = '\0' ;
}
while ( V_31 [ 0 ] == ' ' )
V_31 ++ ;
while ( V_31 [ strlen ( V_31 ) - 1 ] == ' ' )
V_31 [ strlen ( V_31 ) - 1 ] = '\0' ;
V_79 = NULL ;
if ( ! ( * ( V_31 ) ) ) {
F_51 ( L_15 ) ;
}
else {
V_79 = F_6 ( V_31 ) ;
if ( ! V_79 ) {
F_51 ( L_16 , V_31 ) ;
}
}
if ( ! V_79 ) {
F_51 ( L_17 ) ;
F_45 ( V_85 ) ;
}
if ( V_75 == NULL || ! V_79 ) {
F_4 ( V_74 ) ;
return FALSE ;
}
if ( * ( V_75 + 1 ) != '=' ) {
F_51 ( L_18 , V_31 , V_75 + 1 ) ;
}
else {
V_75 ++ ;
* V_75 = '\0' ;
}
V_75 ++ ;
V_76 = V_75 ;
V_75 = strchr ( V_76 , ',' ) ;
if ( V_75 == NULL ) {
F_51 ( L_14 , V_71 , V_84 ) ;
}
else {
* V_75 = '\0' ;
}
V_80 = F_52 ( V_31 ) ;
switch ( V_80 ) {
case V_34 :
case V_35 :
case V_36 :
case V_37 :
switch ( sscanf ( V_76 , L_19 , & V_72 , & V_83 , & V_73 ) ) {
case 1 :
V_83 = '\0' ;
break;
case 3 :
if ( V_83 != ':' && V_83 != '-' ) {
F_51 ( L_20 , V_76 ) ;
F_4 ( V_74 ) ;
return FALSE ;
}
if ( V_83 == ':' ) {
if ( ( V_73 == 0 ) || ( ( T_19 ) V_72 + V_73 - 1 ) > V_86 ) {
F_51 ( L_20 , V_76 ) ;
F_4 ( V_74 ) ;
return FALSE ;
}
}
else if ( V_73 < V_72 ) {
F_51 ( L_20 , V_76 ) ;
F_4 ( V_74 ) ;
return FALSE ;
}
break;
default:
F_51 ( L_21 , V_76 ) ;
F_4 ( V_74 ) ;
return FALSE ;
}
break;
case V_40 :
case V_41 :
case V_42 :
case V_43 :
break;
default:
F_23 () ;
}
if ( V_75 == NULL ) {
F_51 ( L_22 , V_31 ) ;
F_47 ( V_85 , V_31 ) ;
F_4 ( V_74 ) ;
return FALSE ;
}
V_75 ++ ;
V_77 = V_75 ;
while ( V_77 [ 0 ] == ' ' )
V_77 ++ ;
while ( V_77 [ strlen ( V_77 ) - 1 ] == ' ' )
V_77 [ strlen ( V_77 ) - 1 ] = '\0' ;
V_78 = NULL ;
if ( ! ( * V_77 ) ) {
F_51 ( L_23 ) ;
}
else {
V_82 . V_69 = 0 ;
V_82 . V_68 = V_77 ;
V_82 . V_70 = NULL ;
F_48 ( V_31 , F_49 , & V_82 ) ;
if ( V_82 . V_69 != 0 ) {
V_78 = V_82 . V_70 ;
if ( V_82 . V_69 > 1 ) {
F_51 ( L_24 , V_77 , V_82 . V_69 ) ;
}
}
else {
if ( F_53 ( V_77 ) == - 1 ) {
F_51 ( L_25 , V_77 ) ;
}
else {
F_51 ( L_26 ,
V_77 , V_31 ) ;
}
}
}
if ( ! V_78 ) {
F_51 ( L_22 , V_31 ) ;
F_47 ( V_85 , V_31 ) ;
F_4 ( V_74 ) ;
return FALSE ;
}
switch ( V_80 ) {
case V_34 :
case V_35 :
case V_36 :
case V_37 :
if ( V_83 == '\0' ) {
F_13 ( V_31 , V_72 , V_78 ) ;
}
else if ( V_83 == ':' ) {
for ( V_13 = V_72 ; V_13 < ( T_19 ) V_72 + V_73 ; V_13 ++ ) {
F_13 ( V_31 , ( T_18 ) V_13 , V_78 ) ;
}
}
else {
for ( V_13 = V_72 ; V_13 <= V_73 ; V_13 ++ ) {
F_13 ( V_31 , ( T_18 ) V_13 , V_78 ) ;
}
}
break;
case V_40 :
case V_41 :
case V_42 :
case V_43 :
F_12 ( V_31 , V_76 , V_78 ) ;
break;
default:
F_23 () ;
}
F_4 ( V_74 ) ;
return TRUE ;
}

static void
F_1 ( const char * V_1 , const char * V_2 ,
T_1 V_3 )
{
if ( ( V_4 == NULL ) ||
( strcmp ( V_4 , V_1 ) != 0 ) ) {
fprintf ( ( V_5 * ) V_3 , L_1 , V_1 , V_2 ) ;
V_4 = V_1 ;
}
}
static void
F_2 ( const T_2 * T_3 V_6 , T_1 V_7 , T_1 V_3 )
{
int V_8 ;
const T_2 * V_9 ;
const T_2 * V_10 ;
V_8 = F_3 ( ( V_11 ) V_7 ) ;
if ( V_8 != - 1 ) {
V_9 = F_4 ( V_8 ) ;
V_10 = F_5 ( V_8 ) ;
F_6 ( V_9 != NULL ) ;
F_6 ( V_10 != NULL ) ;
if ( ( V_4 == NULL ) ||
( strcmp ( V_4 , V_9 ) != 0 ) ) {
fprintf ( ( V_5 * ) V_3 , L_1 ,
V_9 ,
V_10 ) ;
V_4 = V_9 ;
}
}
}
static T_4
F_7 ( T_5 V_12 , T_5 V_13 )
{
return strcmp ( ( const char * ) V_12 , ( const char * ) V_13 ) ;
}
static void
F_8 ( V_5 * V_3 )
{
V_4 = NULL ;
F_9 ( F_1 , ( T_1 ) V_3 , ( V_14 ) F_7 ) ;
}
static void
F_10 ( V_5 * V_3 , T_2 * V_1 )
{
V_4 = NULL ;
F_11 ( V_1 ,
F_2 ,
( T_1 ) V_3 ) ;
}
static void
F_12 ( const T_2 * T_3 V_6 , T_1 V_7 , T_1 V_15 )
{
int V_8 ;
const T_2 * V_16 ;
T_6 V_17 ;
F_6 ( V_7 ) ;
V_17 = ( T_6 ) V_15 ;
V_8 = F_3 ( ( V_11 ) V_7 ) ;
if ( V_8 != - 1 ) {
V_16 = F_4 ( V_8 ) ;
F_6 ( V_16 != NULL ) ;
if ( strcmp ( V_16 , V_17 -> V_18 ) == 0 ) {
if ( V_17 -> V_19 == 0 ) {
V_17 -> V_20 = ( V_11 ) V_7 ;
}
V_17 -> V_19 ++ ;
}
}
}
T_7 F_13 ( const T_2 * V_21 )
{
T_2 * V_1 ;
T_8 V_22 , V_23 ;
T_2 * V_24 ;
T_2 * V_25 ;
T_2 * V_26 ;
T_2 * V_27 ;
V_11 V_28 ;
T_9 V_29 ;
T_10 V_30 ;
struct V_31 V_32 ;
T_11 V_33 ;
char V_34 ;
F_6 ( V_21 ) ;
V_24 = F_14 ( V_21 ) ;
F_6 ( V_24 ) ;
V_1 = V_24 ;
V_25 = strchr ( V_1 , '=' ) ;
if ( V_25 == NULL ) {
F_15 ( L_2 , V_21 , V_35 ) ;
}
else {
* V_25 = '\0' ;
}
while ( V_1 [ 0 ] == ' ' )
V_1 ++ ;
while ( V_1 [ strlen ( V_1 ) - 1 ] == ' ' )
V_1 [ strlen ( V_1 ) - 1 ] = '\0' ;
V_29 = NULL ;
if ( ! ( * ( V_1 ) ) ) {
F_15 ( L_3 ) ;
}
else {
V_29 = F_16 ( V_1 ) ;
if ( ! V_29 ) {
F_15 ( L_4 , V_1 ) ;
}
}
if ( ! V_29 ) {
F_15 ( L_5 ) ;
F_8 ( V_36 ) ;
}
if ( V_25 == NULL || ! V_29 ) {
F_17 ( V_24 ) ;
return FALSE ;
}
if ( * ( V_25 + 1 ) != '=' ) {
F_15 ( L_6 , V_1 , V_25 + 1 ) ;
}
else {
V_25 ++ ;
* V_25 = '\0' ;
}
V_25 ++ ;
V_26 = V_25 ;
V_25 = strchr ( V_26 , ',' ) ;
if ( V_25 == NULL ) {
F_15 ( L_2 , V_21 , V_35 ) ;
}
else {
* V_25 = '\0' ;
}
V_30 = F_18 ( V_1 ) ;
switch ( V_30 ) {
case V_37 :
case V_38 :
case V_39 :
case V_40 :
switch ( sscanf ( V_26 , L_7 , & V_22 , & V_34 , & V_23 ) ) {
case 1 :
V_34 = '\0' ;
break;
case 3 :
if ( V_34 != ':' && V_34 != '-' ) {
F_15 ( L_8 , V_26 ) ;
F_17 ( V_24 ) ;
return FALSE ;
}
if ( V_34 == ':' ) {
if ( ( V_23 == 0 ) || ( ( T_11 ) V_22 + V_23 - 1 ) > V_41 ) {
F_15 ( L_8 , V_26 ) ;
F_17 ( V_24 ) ;
return FALSE ;
}
}
else if ( V_23 < V_22 ) {
F_15 ( L_8 , V_26 ) ;
F_17 ( V_24 ) ;
return FALSE ;
}
break;
default:
F_15 ( L_9 , V_26 ) ;
F_17 ( V_24 ) ;
return FALSE ;
}
break;
case V_42 :
case V_43 :
case V_44 :
case V_45 :
break;
default:
F_19 () ;
}
if ( V_25 == NULL ) {
F_15 ( L_10 , V_1 ) ;
F_10 ( V_36 , V_1 ) ;
F_17 ( V_24 ) ;
return FALSE ;
}
V_25 ++ ;
V_27 = V_25 ;
while ( V_27 [ 0 ] == ' ' )
V_27 ++ ;
while ( V_27 [ strlen ( V_27 ) - 1 ] == ' ' )
V_27 [ strlen ( V_27 ) - 1 ] = '\0' ;
V_28 = NULL ;
if ( ! ( * V_27 ) ) {
F_15 ( L_11 ) ;
}
else {
V_32 . V_19 = 0 ;
V_32 . V_18 = V_27 ;
V_32 . V_20 = NULL ;
F_11 ( V_1 , F_12 , & V_32 ) ;
if ( V_32 . V_19 != 0 ) {
V_28 = V_32 . V_20 ;
if ( V_32 . V_19 > 1 ) {
F_15 ( L_12 , V_27 , V_32 . V_19 ) ;
}
}
else {
if ( F_20 ( V_27 ) == - 1 ) {
F_15 ( L_13 , V_27 ) ;
}
else {
F_15 ( L_14 ,
V_27 , V_1 ) ;
}
}
}
if ( ! V_28 ) {
F_15 ( L_10 , V_1 ) ;
F_10 ( V_36 , V_1 ) ;
F_17 ( V_24 ) ;
return FALSE ;
}
switch ( V_30 ) {
case V_37 :
case V_38 :
case V_39 :
case V_40 :
if ( V_34 == '\0' ) {
F_21 ( V_1 , V_22 , V_28 ) ;
}
else if ( V_34 == ':' ) {
for ( V_33 = V_22 ; V_33 < ( T_11 ) V_22 + V_23 ; V_33 ++ ) {
F_21 ( V_1 , ( T_8 ) V_33 , V_28 ) ;
}
}
else {
for ( V_33 = V_22 ; V_33 <= V_23 ; V_33 ++ ) {
F_21 ( V_1 , ( T_8 ) V_33 , V_28 ) ;
}
}
break;
case V_42 :
case V_43 :
case V_44 :
case V_45 :
F_22 ( V_1 , V_26 , V_28 ) ;
break;
default:
F_19 () ;
}
F_17 ( V_24 ) ;
return TRUE ;
}

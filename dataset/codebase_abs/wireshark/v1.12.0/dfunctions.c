static T_1
F_1 ( T_1 V_1 )
{
return ( ( V_1 & 0x80 ) ? V_1 : tolower ( V_1 ) ) ;
}
static T_1
F_2 ( T_1 V_1 )
{
return ( ( V_1 & 0x80 ) ? V_1 : toupper ( V_1 ) ) ;
}
static T_2
F_3 ( T_3 * V_2 , T_3 * * V_3 , T_1 (* F_4)( T_1 ) )
{
T_3 * V_4 ;
T_4 * V_5 ;
T_4 * V_6 ;
char * V_7 , * V_1 ;
V_4 = V_2 ;
while ( V_4 ) {
V_5 = ( T_4 * ) V_4 -> V_8 ;
if ( F_5 ( F_6 ( V_5 ) ) ) {
V_7 = ( char * ) F_7 ( ( T_1 * ) F_8 ( V_5 ) ) ;
for ( V_1 = V_7 ; * V_1 ; V_1 ++ ) {
* V_1 = F_4 ( * V_1 ) ;
}
V_6 = F_9 ( V_9 ) ;
F_10 ( V_6 , V_7 ) ;
* V_3 = F_11 ( * V_3 , V_6 ) ;
}
V_4 = V_4 -> V_10 ;
}
return TRUE ;
}
static T_2
F_12 ( T_3 * V_2 , T_3 * T_5 V_11 , T_3 * * V_3 )
{
return F_3 ( V_2 , V_3 , F_1 ) ;
}
static T_2
F_13 ( T_3 * V_2 , T_3 * T_5 V_11 , T_3 * * V_3 )
{
return F_3 ( V_2 , V_3 , F_2 ) ;
}
static T_2
F_14 ( T_3 * V_2 , T_3 * T_5 V_11 , T_3 * * V_3 )
{
T_3 * V_4 ;
T_4 * V_5 ;
T_4 * V_12 ;
V_4 = V_2 ;
while ( V_4 ) {
V_5 = ( T_4 * ) V_4 -> V_8 ;
if ( F_5 ( F_6 ( V_5 ) ) ) {
V_12 = F_9 ( V_13 ) ;
F_15 ( V_12 , ( V_14 ) strlen ( ( char * ) F_8 ( V_5 ) ) ) ;
* V_3 = F_11 ( * V_3 , V_12 ) ;
}
V_4 = V_4 -> V_10 ;
}
return TRUE ;
}
static T_2
F_16 ( T_3 * V_2 , T_3 * T_5 V_11 , T_3 * * V_3 )
{
T_3 * V_4 ;
T_4 * V_5 ;
T_4 * V_12 ;
V_4 = V_2 ;
while ( V_4 ) {
V_5 = ( T_4 * ) V_4 -> V_8 ;
V_12 = F_9 ( V_13 ) ;
F_15 ( V_12 , F_17 ( V_5 ) ) ;
* V_3 = F_11 ( * V_3 , V_12 ) ;
V_4 = V_4 -> V_10 ;
}
return TRUE ;
}
static T_2
F_18 ( T_3 * V_2 , T_3 * T_5 V_11 , T_3 * * V_3 )
{
T_4 * V_15 ;
T_6 V_16 ;
V_16 = ( T_6 ) F_19 ( V_2 ) ;
V_15 = F_9 ( V_13 ) ;
F_15 ( V_15 , V_16 ) ;
* V_3 = F_11 ( * V_3 , V_15 ) ;
return TRUE ;
}
static void
F_20 ( int V_17 , T_7 * V_18 )
{
T_8 type ;
T_9 V_19 ;
T_10 * V_20 ;
type = F_21 ( V_18 ) ;
if ( V_17 == 0 ) {
switch( type ) {
case V_21 :
V_20 = ( T_10 * ) F_22 ( V_18 ) ;
V_19 = V_20 -> type ;
if ( F_5 ( V_19 ) ) {
F_23 ( L_1 ) ;
F_24 ( V_22 ) ;
}
break;
default:
F_23 ( L_2 ) ;
F_24 ( V_22 ) ;
}
}
else {
F_25 () ;
}
}
static void
F_26 ( int V_17 , T_7 * V_18 )
{
T_8 type ;
type = F_21 ( V_18 ) ;
if ( V_17 == 0 ) {
switch( type ) {
case V_21 :
break;
default:
F_23 ( L_3
L_4 ) ;
F_24 ( V_22 ) ;
}
}
else {
F_25 () ;
}
}
T_11 *
F_27 ( char * V_23 )
{
T_11 * V_24 ;
V_24 = V_25 ;
while ( V_24 -> V_26 != NULL ) {
if ( strcmp ( V_24 -> V_23 , V_23 ) == 0 ) {
return V_24 ;
}
V_24 ++ ;
}
return NULL ;
}

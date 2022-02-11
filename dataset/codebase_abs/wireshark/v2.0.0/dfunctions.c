static T_1
F_1 ( T_2 * V_1 , T_2 * * V_2 , T_3 (* F_2)( T_3 ) )
{
T_2 * V_3 ;
T_4 * V_4 ;
T_4 * V_5 ;
char * V_6 , * V_7 ;
V_3 = V_1 ;
while ( V_3 ) {
V_4 = ( T_4 * ) V_3 -> V_8 ;
if ( F_3 ( F_4 ( V_4 ) ) ) {
V_6 = ( char * ) F_5 ( NULL , ( T_3 * ) F_6 ( V_4 ) ) ;
for ( V_7 = V_6 ; * V_7 ; V_7 ++ ) {
* V_7 = F_2 ( * V_7 ) ;
}
V_5 = F_7 ( V_9 ) ;
F_8 ( V_5 , V_6 ) ;
F_9 ( NULL , V_6 ) ;
* V_2 = F_10 ( * V_2 , V_5 ) ;
}
V_3 = V_3 -> V_10 ;
}
return TRUE ;
}
static T_1
F_11 ( T_2 * V_1 , T_2 * T_5 V_11 , T_2 * * V_2 )
{
return F_1 ( V_1 , V_2 , V_12 ) ;
}
static T_1
F_12 ( T_2 * V_1 , T_2 * T_5 V_11 , T_2 * * V_2 )
{
return F_1 ( V_1 , V_2 , V_13 ) ;
}
static T_1
F_13 ( T_2 * V_1 , T_2 * T_5 V_11 , T_2 * * V_2 )
{
T_2 * V_3 ;
T_4 * V_4 ;
T_4 * V_14 ;
V_3 = V_1 ;
while ( V_3 ) {
V_4 = ( T_4 * ) V_3 -> V_8 ;
if ( F_3 ( F_4 ( V_4 ) ) ) {
V_14 = F_7 ( V_15 ) ;
F_14 ( V_14 , ( V_16 ) strlen ( ( char * ) F_6 ( V_4 ) ) ) ;
* V_2 = F_10 ( * V_2 , V_14 ) ;
}
V_3 = V_3 -> V_10 ;
}
return TRUE ;
}
static T_1
F_15 ( T_2 * V_1 , T_2 * T_5 V_11 , T_2 * * V_2 )
{
T_2 * V_3 ;
T_4 * V_4 ;
T_4 * V_14 ;
V_3 = V_1 ;
while ( V_3 ) {
V_4 = ( T_4 * ) V_3 -> V_8 ;
V_14 = F_7 ( V_15 ) ;
F_14 ( V_14 , F_16 ( V_4 ) ) ;
* V_2 = F_10 ( * V_2 , V_14 ) ;
V_3 = V_3 -> V_10 ;
}
return TRUE ;
}
static T_1
F_17 ( T_2 * V_1 , T_2 * T_5 V_11 , T_2 * * V_2 )
{
T_4 * V_17 ;
T_6 V_18 ;
V_18 = ( T_6 ) F_18 ( V_1 ) ;
V_17 = F_7 ( V_15 ) ;
F_14 ( V_17 , V_18 ) ;
* V_2 = F_10 ( * V_2 , V_17 ) ;
return TRUE ;
}
static void
F_19 ( T_7 * V_19 , int V_20 , T_8 * V_21 )
{
T_9 type ;
T_10 V_22 ;
T_11 * V_23 ;
type = F_20 ( V_21 ) ;
if ( V_20 == 0 ) {
switch( type ) {
case V_24 :
V_23 = ( T_11 * ) F_21 ( V_21 ) ;
V_22 = V_23 -> type ;
if ( ! F_3 ( V_22 ) ) {
F_22 ( V_19 , L_1 ) ;
F_23 ( V_25 ) ;
}
break;
default:
F_22 ( V_19 , L_2 ) ;
F_23 ( V_25 ) ;
}
}
else {
F_24 () ;
}
}
static void
F_25 ( T_7 * V_19 , int V_20 , T_8 * V_21 )
{
T_9 type ;
type = F_20 ( V_21 ) ;
if ( V_20 == 0 ) {
switch( type ) {
case V_24 :
break;
default:
F_22 ( V_19 , L_3
L_4 ) ;
F_23 ( V_25 ) ;
}
}
else {
F_24 () ;
}
}
T_12 *
F_26 ( char * V_26 )
{
T_12 * V_27 ;
V_27 = V_28 ;
while ( V_27 -> V_29 != NULL ) {
if ( strcmp ( V_27 -> V_26 , V_26 ) == 0 ) {
return V_27 ;
}
V_27 ++ ;
}
return NULL ;
}

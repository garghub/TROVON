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
switch ( F_4 ( V_4 ) )
{
case V_9 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
V_14 = F_7 ( V_20 ) ;
F_14 ( V_14 , F_15 ( V_4 ) ) ;
* V_2 = F_10 ( * V_2 , V_14 ) ;
break;
default:
break;
}
V_3 = V_3 -> V_10 ;
}
return TRUE ;
}
static T_1
F_16 ( T_2 * V_1 , T_2 * T_5 V_11 , T_2 * * V_2 )
{
T_2 * V_3 ;
T_4 * V_4 ;
T_4 * V_14 ;
V_3 = V_1 ;
while ( V_3 ) {
V_4 = ( T_4 * ) V_3 -> V_8 ;
V_14 = F_7 ( V_20 ) ;
F_14 ( V_14 , F_15 ( V_4 ) ) ;
* V_2 = F_10 ( * V_2 , V_14 ) ;
V_3 = V_3 -> V_10 ;
}
return TRUE ;
}
static T_1
F_17 ( T_2 * V_1 , T_2 * T_5 V_11 , T_2 * * V_2 )
{
T_4 * V_21 ;
T_6 V_22 ;
V_22 = ( T_6 ) F_18 ( V_1 ) ;
V_21 = F_7 ( V_20 ) ;
F_14 ( V_21 , V_22 ) ;
* V_2 = F_10 ( * V_2 , V_21 ) ;
return TRUE ;
}
static void
F_19 ( T_7 * V_23 , int V_24 , T_8 * V_25 )
{
T_9 type ;
T_10 V_26 ;
T_11 * V_27 ;
type = F_20 ( V_25 ) ;
if ( V_24 == 0 ) {
switch( type ) {
case V_28 :
V_27 = ( T_11 * ) F_21 ( V_25 ) ;
V_26 = V_27 -> type ;
if ( ! F_3 ( V_26 ) ) {
F_22 ( V_23 , L_1 ) ;
F_23 ( V_29 ) ;
}
break;
default:
F_22 ( V_23 , L_2 ) ;
F_23 ( V_29 ) ;
}
}
else {
F_24 () ;
}
}
static void
F_25 ( T_7 * V_23 , int V_24 , T_8 * V_25 )
{
T_9 type ;
T_10 V_26 ;
T_11 * V_27 ;
type = F_20 ( V_25 ) ;
if ( V_24 == 0 ) {
switch( type ) {
case V_28 :
V_27 = ( T_11 * ) F_21 ( V_25 ) ;
V_26 = V_27 -> type ;
switch ( V_26 )
{
case V_9 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
break;
default:
F_22 ( V_23 , L_3 ) ;
F_23 ( V_29 ) ;
break;
}
break;
default:
F_22 ( V_23 , L_3 ) ;
F_23 ( V_29 ) ;
}
}
else {
F_24 () ;
}
}
static void
F_26 ( T_7 * V_23 , int V_24 , T_8 * V_25 )
{
T_9 type ;
type = F_20 ( V_25 ) ;
if ( V_24 == 0 ) {
switch( type ) {
case V_28 :
break;
default:
F_22 ( V_23 , L_4
L_5 ) ;
F_23 ( V_29 ) ;
}
}
else {
F_24 () ;
}
}
T_12 *
F_27 ( char * V_30 )
{
T_12 * V_31 ;
V_31 = V_32 ;
while ( V_31 -> V_33 != NULL ) {
if ( strcmp ( V_31 -> V_30 , V_30 ) == 0 ) {
return V_31 ;
}
V_31 ++ ;
}
return NULL ;
}

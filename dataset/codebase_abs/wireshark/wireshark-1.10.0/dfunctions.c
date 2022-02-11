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
switch ( F_5 ( V_5 ) -> V_9 ) {
case V_10 :
case V_11 :
case V_12 :
V_7 = ( char * ) F_6 ( ( T_1 * ) F_7 ( V_5 ) ) ;
for ( V_1 = V_7 ; * V_1 ; V_1 ++ ) {
* V_1 = F_4 ( * V_1 ) ;
}
V_6 = F_8 ( V_10 ) ;
F_9 ( V_6 , V_7 , FALSE ) ;
* V_3 = F_10 ( * V_3 , V_6 ) ;
break;
default:
break;
}
V_4 = V_4 -> V_13 ;
}
return TRUE ;
}
static T_2
F_11 ( T_3 * V_2 , T_3 * T_5 V_14 , T_3 * * V_3 )
{
return F_3 ( V_2 , V_3 , F_1 ) ;
}
static T_2
F_12 ( T_3 * V_2 , T_3 * T_5 V_14 , T_3 * * V_3 )
{
return F_3 ( V_2 , V_3 , F_2 ) ;
}
static T_2
F_13 ( T_3 * V_2 , T_3 * T_5 V_14 , T_3 * * V_3 )
{
T_3 * V_4 ;
T_4 * V_5 ;
T_4 * V_15 ;
V_4 = V_2 ;
while ( V_4 ) {
V_5 = ( T_4 * ) V_4 -> V_8 ;
switch ( F_5 ( V_5 ) -> V_9 ) {
case V_10 :
case V_11 :
case V_12 :
V_15 = F_8 ( V_16 ) ;
F_14 ( V_15 , ( V_17 ) strlen ( ( char * ) F_7 ( V_5 ) ) ) ;
* V_3 = F_10 ( * V_3 , V_15 ) ;
break;
default:
break;
}
V_4 = V_4 -> V_13 ;
}
return TRUE ;
}
static void
F_15 ( int V_18 , T_6 * V_19 )
{
T_7 type ;
T_8 V_9 ;
T_9 * V_20 ;
type = F_16 ( V_19 ) ;
if ( V_18 == 0 ) {
switch( type ) {
case V_21 :
V_20 = ( T_9 * ) F_17 ( V_19 ) ;
V_9 = V_20 -> type ;
if ( V_9 != V_10 && V_9 != V_11
&& V_9 != V_12 ) {
F_18 ( L_1 ) ;
F_19 ( V_22 ) ;
}
break;
default:
F_18 ( L_2 ) ;
F_19 ( V_22 ) ;
}
}
else {
F_20 () ;
}
}
T_10 *
F_21 ( char * V_23 )
{
T_10 * V_24 ;
V_24 = V_25 ;
while ( V_24 -> V_26 != NULL ) {
if ( strcmp ( V_24 -> V_23 , V_23 ) == 0 ) {
return V_24 ;
}
V_24 ++ ;
}
return NULL ;
}

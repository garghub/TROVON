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
V_7 = ( char * ) F_6 ( F_7 ( ( T_4 * ) V_4 -> V_8 ) ) ;
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
V_4 = V_4 -> V_11 ;
}
return TRUE ;
}
static T_2
F_11 ( T_3 * V_2 , T_3 * T_5 V_12 , T_3 * * V_3 )
{
return F_3 ( V_2 , V_3 , F_1 ) ;
}
static T_2
F_12 ( T_3 * V_2 , T_3 * T_5 V_12 , T_3 * * V_3 )
{
return F_3 ( V_2 , V_3 , F_2 ) ;
}
static void
F_13 ( int V_13 , T_6 * V_14 )
{
T_7 type ;
T_8 V_9 ;
T_9 * V_15 ;
type = F_14 ( V_14 ) ;
if ( V_13 == 0 ) {
switch( type ) {
case V_16 :
V_15 = ( T_9 * ) F_15 ( V_14 ) ;
V_9 = V_15 -> type ;
if ( V_9 != V_10 && V_9 != V_17
&& V_9 != V_18 ) {
F_16 ( L_1 ) ;
F_17 ( V_19 ) ;
}
break;
default:
F_16 ( L_2 ) ;
F_17 ( V_19 ) ;
}
}
else {
F_18 () ;
}
}
T_10 *
F_19 ( char * V_20 )
{
T_10 * V_21 ;
V_21 = V_22 ;
while ( V_21 -> V_23 != NULL ) {
if ( strcmp ( V_21 -> V_20 , V_20 ) == 0 ) {
return V_21 ;
}
V_21 ++ ;
}
return NULL ;
}

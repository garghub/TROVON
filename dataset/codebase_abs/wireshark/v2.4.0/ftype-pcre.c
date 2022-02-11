static void
F_1 ( T_1 * V_1 )
{
V_1 -> V_2 . V_3 = NULL ;
}
static void
F_2 ( T_1 * V_1 )
{
if ( V_1 -> V_2 . V_3 ) {
F_3 ( V_1 -> V_2 . V_3 ) ;
V_1 -> V_2 . V_3 = NULL ;
}
}
static T_2
F_4 ( const T_3 * V_4 )
{
T_2 V_5 = FALSE ;
const T_3 * V_6 = V_4 ;
T_4 V_7 , V_8 ;
V_8 = strlen ( V_6 ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
if ( ( V_9 ) ( V_6 [ V_7 ] & 0xF0 ) >= 0xA0 &&
( V_9 ) ( V_6 [ V_7 ] & 0x0F ) >= 0x0A )
{
V_5 = TRUE ;
break;
}
}
return V_5 ;
}
static T_2
F_5 ( T_1 * V_1 , const char * V_4 , T_3 * * V_10 )
{
T_5 * V_11 = NULL ;
T_6 V_12 = V_13 ;
if ( F_4 ( V_4 ) ) {
V_12 = ( T_6 ) ( V_13 | V_14 ) ;
}
F_2 ( V_1 ) ;
V_1 -> V_2 . V_3 = F_6 (
V_4 ,
V_12 ,
( V_15 ) 0 ,
& V_11
) ;
if ( V_11 ) {
if ( V_10 ) {
* V_10 = F_7 ( V_11 -> V_16 ) ;
}
F_8 ( V_11 ) ;
if ( V_1 -> V_2 . V_3 ) {
F_3 ( V_1 -> V_2 . V_3 ) ;
}
return FALSE ;
}
return TRUE ;
}
static T_2
F_9 ( T_1 * V_1 , const char * V_4 , T_2 V_17 , T_3 * * V_10 )
{
F_10 ( ! V_17 ) ;
return F_5 ( V_1 , V_4 , V_10 ) ;
}
static int
F_11 ( T_1 * V_1 , T_7 V_18 , int T_8 V_19 )
{
F_10 ( V_18 == V_20 ) ;
return ( int ) strlen ( F_12 ( V_1 -> V_2 . V_3 ) ) ;
}
static void
F_13 ( T_1 * V_1 , T_7 V_18 , int T_8 V_19 , char * V_21 , unsigned int V_22 )
{
F_10 ( V_18 == V_20 ) ;
F_14 ( V_21 , F_12 ( V_1 -> V_2 . V_3 ) , V_22 ) ;
}
static void
F_15 ( T_1 * V_1 , const char * V_2 )
{
F_10 ( V_2 != NULL ) ;
F_2 ( V_1 ) ;
F_9 ( V_1 , V_2 , FALSE , NULL ) ;
}
static T_9
F_16 ( T_1 * V_1 )
{
return V_1 -> V_2 . V_3 ;
}
void
F_17 ( void )
{
static T_10 V_23 = {
V_24 ,
L_1 ,
L_2 ,
0 ,
F_1 ,
F_2 ,
F_9 ,
F_5 ,
F_13 ,
F_11 ,
{ . V_25 = F_15 } ,
{ . V_26 = F_16 } ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
F_18 ( V_24 , & V_23 ) ;
}

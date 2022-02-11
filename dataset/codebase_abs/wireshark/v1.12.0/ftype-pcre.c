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
if ( ( V_6 [ V_7 ] >= '\xAA' && V_6 [ V_7 ] <= '\xAF' ) ||
( V_6 [ V_7 ] >= '\xBA' && V_6 [ V_7 ] <= '\xBF' ) ||
( V_6 [ V_7 ] >= '\xCA' && V_6 [ V_7 ] <= '\xCF' ) ||
( V_6 [ V_7 ] >= '\xDA' && V_6 [ V_7 ] <= '\xDF' ) ||
( V_6 [ V_7 ] >= '\xEA' && V_6 [ V_7 ] <= '\xEF' ) ||
( V_6 [ V_7 ] >= '\xFA' && V_6 [ V_7 ] <= '\xFF' ) )
{
V_5 = TRUE ;
break;
}
}
return V_5 ;
}
static T_2
F_5 ( T_1 * V_1 , const char * V_4 , T_5 V_9 )
{
T_6 * V_10 = NULL ;
T_7 V_11 = V_12 ;
if ( F_4 ( V_4 ) ) {
V_11 = ( T_7 ) ( V_12 | V_13 ) ;
}
F_2 ( V_1 ) ;
V_1 -> V_2 . V_3 = F_6 (
V_4 ,
V_11 ,
( V_14 ) 0 ,
& V_10
) ;
if ( V_10 ) {
if ( V_9 ) {
V_9 ( V_10 -> V_15 ) ;
}
F_7 ( V_10 ) ;
if ( V_1 -> V_2 . V_3 ) {
F_3 ( V_1 -> V_2 . V_3 ) ;
}
return FALSE ;
}
return TRUE ;
}
static T_2
F_8 ( T_1 * V_1 , const char * V_4 , T_2 T_8 V_16 , T_5 V_9 )
{
F_9 ( ! T_8 ) ;
return F_5 ( V_1 , V_4 , V_9 ) ;
}
static int
F_10 ( T_1 * V_1 , T_9 V_17 )
{
F_9 ( V_17 == V_18 ) ;
return ( int ) strlen ( F_11 ( V_1 -> V_2 . V_3 ) ) ;
}
static void
F_12 ( T_1 * V_1 , T_9 V_17 , char * V_19 )
{
F_9 ( V_17 == V_18 ) ;
strcpy ( V_19 , F_11 ( V_1 -> V_2 . V_3 ) ) ;
}
static void
F_13 ( T_1 * V_1 , const char * V_2 )
{
F_9 ( V_2 != NULL ) ;
F_2 ( V_1 ) ;
F_8 ( V_1 , V_2 , FALSE , NULL ) ;
}
static T_10
F_14 ( T_1 * V_1 )
{
return V_1 -> V_2 . V_3 ;
}
void
F_15 ( void )
{
static T_11 V_20 = {
V_21 ,
L_1 ,
L_2 ,
0 ,
F_1 ,
F_2 ,
F_8 ,
F_5 ,
F_12 ,
F_10 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_13 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
F_14 ,
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
NULL ,
NULL ,
NULL ,
NULL ,
} ;
F_16 ( V_21 , & V_20 ) ;
}

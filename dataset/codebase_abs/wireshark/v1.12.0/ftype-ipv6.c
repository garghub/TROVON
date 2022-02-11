static void
F_1 ( T_1 * V_1 , const T_2 * V_2 )
{
memcpy ( V_1 -> V_2 . V_3 . V_4 . V_5 , V_2 , V_6 ) ;
V_1 -> V_2 . V_3 . V_7 = 128 ;
}
static T_3
F_2 ( T_1 * V_1 , const char * V_8 , T_3 T_4 V_9 , T_5 V_10 )
{
const char * V_11 , * V_12 ;
unsigned int V_13 ;
T_1 * V_14 ;
if ( ( V_11 = strchr ( V_8 , '/' ) ) )
V_12 = F_3 ( V_8 , V_11 - V_8 ) ;
else
V_12 = V_8 ;
if ( ! F_4 ( V_12 , & ( V_1 -> V_2 . V_3 . V_4 ) ) ) {
V_10 ( L_1 , V_8 ) ;
return FALSE ;
}
if ( V_11 ) {
V_14 = F_5 ( V_15 , V_11 + 1 , FALSE , V_10 ) ;
if ( ! V_14 ) {
return FALSE ;
}
V_13 = F_6 ( V_14 ) ;
F_7 ( V_14 ) ;
if ( V_13 > 128 ) {
V_10 ( L_2 ,
V_13 ) ;
return FALSE ;
}
V_1 -> V_2 . V_3 . V_7 = V_13 ;
} else {
V_1 -> V_2 . V_3 . V_7 = 128 ;
}
return TRUE ;
}
static int
F_8 ( T_1 * V_1 V_9 , T_6 T_7 V_9 )
{
return 39 ;
}
static void
F_9 ( T_1 * V_1 , T_6 T_7 V_9 , char * V_16 )
{
F_10 ( & ( V_1 -> V_2 . V_3 . V_4 ) , V_16 ) ;
}
static T_8
F_11 ( T_1 * V_1 )
{
return V_1 -> V_2 . V_3 . V_4 . V_5 ;
}
static T_9
F_12 ( const T_1 * V_17 , const T_1 * V_18 )
{
const T_10 * V_19 = & ( V_17 -> V_2 . V_3 ) ;
const T_10 * V_20 = & ( V_18 -> V_2 . V_3 ) ;
T_11 V_7 ;
int V_21 = 0 ;
V_7 = F_13 ( V_19 -> V_7 , V_20 -> V_7 ) ;
V_7 = F_13 ( V_7 , 128 ) ;
while ( V_7 >= 8 ) {
T_9 V_22 = ( T_9 ) ( V_19 -> V_4 . V_5 [ V_21 ] ) ;
T_9 V_23 = ( T_9 ) ( V_20 -> V_4 . V_5 [ V_21 ] ) ;
if ( V_22 != V_23 )
return V_22 - V_23 ;
V_7 -= 8 ;
V_21 ++ ;
}
if ( V_7 != 0 ) {
T_9 V_22 = ( T_9 ) ( V_19 -> V_4 . V_5 [ V_21 ] & ( V_24 [ V_7 ] ) ) ;
T_9 V_23 = ( T_9 ) ( V_20 -> V_4 . V_5 [ V_21 ] & ( V_24 [ V_7 ] ) ) ;
if ( V_22 != V_23 )
return V_22 - V_23 ;
}
return 0 ;
}
static T_3
F_14 ( const T_1 * V_17 , const T_1 * V_18 )
{
return ( F_12 ( V_17 , V_18 ) == 0 ) ;
}
static T_3
F_15 ( const T_1 * V_17 , const T_1 * V_18 )
{
return ( F_12 ( V_17 , V_18 ) != 0 ) ;
}
static T_3
F_16 ( const T_1 * V_17 , const T_1 * V_18 )
{
return ( F_12 ( V_17 , V_18 ) > 0 ) ;
}
static T_3
F_17 ( const T_1 * V_17 , const T_1 * V_18 )
{
return ( F_12 ( V_17 , V_18 ) >= 0 ) ;
}
static T_3
F_18 ( const T_1 * V_17 , const T_1 * V_18 )
{
return ( F_12 ( V_17 , V_18 ) < 0 ) ;
}
static T_3
F_19 ( const T_1 * V_17 , const T_1 * V_18 )
{
return ( F_12 ( V_17 , V_18 ) <= 0 ) ;
}
static T_3
F_20 ( const T_1 * V_17 , const T_1 * V_18 )
{
const T_10 * V_19 = & ( V_17 -> V_2 . V_3 ) ;
const T_10 * V_20 = & ( V_18 -> V_2 . V_3 ) ;
T_11 V_7 ;
int V_21 = 0 ;
V_7 = F_13 ( V_19 -> V_7 , V_20 -> V_7 ) ;
V_7 = F_13 ( V_7 , 128 ) ;
while ( V_7 >= 8 ) {
if ( V_19 -> V_4 . V_5 [ V_21 ] & V_20 -> V_4 . V_5 [ V_21 ] )
return TRUE ;
V_7 -= 8 ;
V_21 ++ ;
}
if ( V_7 != 0 ) {
T_2 V_22 = ( V_19 -> V_4 . V_5 [ V_21 ] & ( V_24 [ V_7 ] ) ) ;
T_2 V_23 = ( V_20 -> V_4 . V_5 [ V_21 ] & ( V_24 [ V_7 ] ) ) ;
if ( V_22 & V_23 )
return TRUE ;
}
return FALSE ;
}
static void
F_21 ( T_1 * V_1 , T_12 * V_5 , T_13 V_25 , T_13 V_26 )
{
T_2 * V_27 ;
V_27 = V_1 -> V_2 . V_3 . V_4 . V_5 + V_25 ;
F_22 ( V_5 , V_27 , V_26 ) ;
}
void
F_23 ( void )
{
static T_14 V_28 = {
V_29 ,
L_3 ,
L_4 ,
V_6 ,
NULL ,
NULL ,
F_2 ,
NULL ,
F_9 ,
F_8 ,
NULL ,
F_1 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
F_11 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_14 ,
F_15 ,
F_16 ,
F_17 ,
F_18 ,
F_19 ,
F_20 ,
NULL ,
NULL ,
NULL ,
F_21 ,
} ;
F_24 ( V_29 , & V_28 ) ;
}

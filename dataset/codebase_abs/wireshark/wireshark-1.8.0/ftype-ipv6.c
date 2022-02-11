static void
F_1 ( T_1 * V_1 , T_2 V_2 , T_3 V_3 )
{
F_2 ( ! V_3 ) ;
memcpy ( V_1 -> V_2 . V_4 . V_5 . V_6 , V_2 , V_7 ) ;
V_1 -> V_2 . V_4 . V_8 = 128 ;
}
static T_3
F_3 ( T_1 * V_1 , char * V_9 , T_3 T_4 V_10 , T_5 V_11 )
{
char * V_12 , * V_13 ;
unsigned int V_14 ;
T_1 * V_15 ;
if ( ( V_12 = strchr ( V_9 , '/' ) ) )
V_13 = F_4 ( V_9 , V_12 - V_9 ) ;
else
V_13 = V_9 ;
if ( ! F_5 ( V_13 , & ( V_1 -> V_2 . V_4 . V_5 ) ) ) {
V_11 ( L_1 , V_9 ) ;
return FALSE ;
}
if ( V_12 ) {
V_15 = F_6 ( V_16 , V_12 + 1 , FALSE , V_11 ) ;
if ( ! V_15 ) {
return FALSE ;
}
V_14 = F_7 ( V_15 ) ;
F_8 ( V_15 ) ;
if ( V_14 > 128 ) {
V_11 ( L_2 ,
V_14 ) ;
return FALSE ;
}
V_1 -> V_2 . V_4 . V_8 = V_14 ;
} else {
V_1 -> V_2 . V_4 . V_8 = 128 ;
}
return TRUE ;
}
static int
F_9 ( T_1 * V_1 V_10 , T_6 T_7 V_10 )
{
return 39 ;
}
static void
F_10 ( T_1 * V_1 , T_6 T_7 V_10 , char * V_17 )
{
F_11 ( & ( V_1 -> V_2 . V_4 . V_5 ) , V_17 ) ;
}
static T_2
F_12 ( T_1 * V_1 )
{
return V_1 -> V_2 . V_4 . V_5 . V_6 ;
}
static T_8
F_13 ( const T_1 * V_18 , const T_1 * V_19 )
{
const T_9 * V_20 = & ( V_18 -> V_2 . V_4 ) ;
const T_9 * V_21 = & ( V_19 -> V_2 . V_4 ) ;
T_10 V_8 ;
int V_22 = 0 ;
V_8 = F_14 ( V_20 -> V_8 , V_21 -> V_8 ) ;
V_8 = F_14 ( V_8 , 128 ) ;
while ( V_8 >= 8 ) {
T_8 V_23 = ( T_8 ) ( V_20 -> V_5 . V_6 [ V_22 ] ) ;
T_8 V_24 = ( T_8 ) ( V_21 -> V_5 . V_6 [ V_22 ] ) ;
if ( V_23 != V_24 )
return V_23 - V_24 ;
V_8 -= 8 ;
V_22 ++ ;
}
if ( V_8 != 0 ) {
T_8 V_23 = ( T_8 ) ( V_20 -> V_5 . V_6 [ V_22 ] & ( V_25 [ V_8 ] ) ) ;
T_8 V_24 = ( T_8 ) ( V_21 -> V_5 . V_6 [ V_22 ] & ( V_25 [ V_8 ] ) ) ;
if ( V_23 != V_24 )
return V_23 - V_24 ;
}
return 0 ;
}
static T_3
F_15 ( T_1 * V_18 , T_1 * V_19 )
{
return ( F_13 ( V_18 , V_19 ) == 0 ) ;
}
static T_3
F_16 ( T_1 * V_18 , T_1 * V_19 )
{
return ( F_13 ( V_18 , V_19 ) != 0 ) ;
}
static T_3
F_17 ( T_1 * V_18 , T_1 * V_19 )
{
return ( F_13 ( V_18 , V_19 ) > 0 ) ;
}
static T_3
F_18 ( T_1 * V_18 , T_1 * V_19 )
{
return ( F_13 ( V_18 , V_19 ) >= 0 ) ;
}
static T_3
F_19 ( T_1 * V_18 , T_1 * V_19 )
{
return ( F_13 ( V_18 , V_19 ) < 0 ) ;
}
static T_3
F_20 ( T_1 * V_18 , T_1 * V_19 )
{
return ( F_13 ( V_18 , V_19 ) <= 0 ) ;
}
static T_3
F_21 ( T_1 * V_18 , T_1 * V_19 )
{
T_9 * V_20 = & ( V_18 -> V_2 . V_4 ) ;
T_9 * V_21 = & ( V_19 -> V_2 . V_4 ) ;
T_10 V_8 ;
int V_22 = 0 ;
V_8 = F_14 ( V_20 -> V_8 , V_21 -> V_8 ) ;
V_8 = F_14 ( V_8 , 128 ) ;
while ( V_8 >= 8 ) {
if ( V_20 -> V_5 . V_6 [ V_22 ] & V_21 -> V_5 . V_6 [ V_22 ] )
return TRUE ;
V_8 -= 8 ;
V_22 ++ ;
}
if ( V_8 != 0 ) {
T_11 V_23 = ( V_20 -> V_5 . V_6 [ V_22 ] & ( V_25 [ V_8 ] ) ) ;
T_11 V_24 = ( V_21 -> V_5 . V_6 [ V_22 ] & ( V_25 [ V_8 ] ) ) ;
if ( V_23 & V_24 )
return TRUE ;
}
return FALSE ;
}
static void
F_22 ( T_1 * V_1 , T_12 * V_6 , T_13 V_26 , T_13 V_27 )
{
T_11 * V_28 ;
V_28 = V_1 -> V_2 . V_4 . V_5 . V_6 + V_26 ;
F_23 ( V_6 , V_28 , V_27 ) ;
}
void
F_24 ( void )
{
static T_14 V_29 = {
V_30 ,
L_3 ,
L_4 ,
V_7 ,
NULL ,
NULL ,
F_3 ,
NULL ,
F_10 ,
F_9 ,
F_1 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_12 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_15 ,
F_16 ,
F_17 ,
F_18 ,
F_19 ,
F_20 ,
F_21 ,
NULL ,
NULL ,
NULL ,
F_22 ,
} ;
F_25 ( V_30 , & V_29 ) ;
}

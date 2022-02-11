static inline int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return ( 0 == F_2 ( V_4 -> V_5 ) &&
V_2 -> V_5 == V_4 -> V_5 -> V_6 &&
V_2 -> V_7 == F_3 ( V_4 -> V_8 ) &&
V_2 -> V_9 == F_4 ( V_4 -> V_8 ) ) ;
}
static inline bool F_5 ( struct V_10 * V_11 ,
struct V_3 * V_12 )
{
T_1 V_13 = V_11 -> type ;
T_2 V_14 = F_6 ( V_12 ) ;
if ( ( V_13 == V_15 &&
V_14 == V_16 ) ||
( V_13 == V_17 &&
V_14 == V_18 ) ||
( V_13 == V_19 &&
( V_12 -> V_20 >> 16 ) == V_21 ) )
return true ;
return false ;
}
static int F_7 ( struct V_10 * V_11 , void * V_22 )
{
struct V_23 * V_24 = V_22 ;
struct V_1 * V_2 ;
int V_25 ;
V_2 = (struct V_1 * ) ( V_11 + 1 ) ;
V_25 = ! ! ( V_2 -> V_26 & V_27 ) ;
if ( V_2 -> V_26 & V_28 ) {
if ( F_5 ( V_11 , V_24 -> V_3 ) )
V_24 -> V_29 = V_25 ;
} else
if ( F_1 ( V_2 , V_24 -> V_3 ) )
V_24 -> V_29 = V_25 ;
return 0 ;
}
static void F_8 ( struct V_3 * V_3 )
{
int V_30 ;
struct V_23 V_24 = {
. V_3 = V_3 ,
. V_29 = 0 ,
} ;
V_30 = F_9 ( F_7 , & V_24 ) ;
if ( V_30 )
V_3 -> V_31 = 0 ;
else
V_3 -> V_31 = V_24 . V_29 ;
V_3 -> V_32 = 1 ;
}
int F_10 ( struct V_3 * V_12 )
{
if ( ! F_11 ( V_12 ) )
return 0 ;
if ( ! V_12 -> V_32 )
F_8 ( V_12 ) ;
return V_12 -> V_31 ;
}
static int F_12 ( struct V_10 * V_11 , void * V_22 )
{
struct V_1 * V_2 ;
if ( V_33 )
return 0 ;
switch ( V_11 -> type ) {
case V_15 :
case V_17 :
case V_19 :
V_2 = (struct V_1 * ) ( V_11 + 1 ) ;
V_33 = ! ! ( V_2 -> V_26 & V_27 ) ;
default:
return 0 ;
}
}
bool F_13 ( void )
{
static bool V_34 = false ;
if ( ! V_34 ) {
F_9 ( F_12 , NULL ) ;
V_34 = true ;
}
return V_33 ;
}

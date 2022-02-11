static T_1 F_1 ( T_1 V_1 , int V_2 )
{
return V_2 ? F_2 ( V_1 ) : V_1 ;
}
static void F_3 ( struct V_3 * V_4 , T_1 V_5 ,
T_1 V_6 , T_1 V_7 , T_1 V_8 ,
T_1 V_9 )
{
struct V_10 * V_11 = V_4 -> V_11 ;
struct V_12 V_13 ;
V_13 . V_14 = ( void * ) & V_4 -> V_15 ;
V_13 . V_16 = sizeof( struct V_17 ) ;
V_4 -> V_15 . V_7 = F_1 ( V_7 , V_4 -> V_2 ) ;
V_4 -> V_15 . V_5 = F_1 ( V_5 , V_4 -> V_2 ) ;
V_4 -> V_15 . V_6 = F_1 ( V_6 , V_4 -> V_2 ) ;
V_4 -> V_15 . V_18 . V_19 = F_1 ( V_8 , V_4 -> V_2 ) ;
V_4 -> V_15 . V_18 . V_9 = F_1 ( V_9 , V_4 -> V_2 ) ;
F_4 ( & V_20 , V_11 -> V_21 , NULL , V_13 . V_14 ,
V_13 . V_16 ) ;
}
int F_5 ( struct V_3 * V_4 , T_1 V_5 ,
T_1 V_6 )
{
if ( V_5 < V_4 -> V_22 . V_23 )
V_5 = V_4 -> V_22 . V_23 ;
if ( V_6 > V_4 -> V_22 . V_24 )
V_6 = V_4 -> V_22 . V_24 ;
if ( V_5 > V_6 )
return 0 ;
return 1 ;
}
void F_6 ( struct V_3 * V_4 , T_1 V_5 ,
T_1 V_6 , T_1 V_7 , T_1 V_8 ,
T_1 V_9 , int V_25 )
{
if ( ! F_5 ( V_4 , V_5 , V_6 ) )
return;
if ( ! V_25 && ! ( V_4 -> V_26 & V_27 ) )
return;
F_3 ( V_4 , V_5 , V_6 , V_7 , V_8 , V_9 ) ;
}
static void F_7 ( struct V_3 * V_4 )
{
struct V_10 * V_11 = V_4 -> V_11 ;
F_8 ( & V_11 -> V_28 ) ;
if ( V_4 -> V_29 == V_30 ) {
F_9 ( & V_11 -> V_28 ) ;
return;
}
F_10 ( V_4 ) ;
F_11 ( & V_4 -> V_31 ) ;
F_9 ( & V_11 -> V_28 ) ;
F_3 ( V_4 , V_4 -> V_15 . V_32 . V_22 . V_23 , V_4 -> V_15 . V_32 . V_22 . V_24 ,
V_33 , 0 , 0 ) ;
F_12 ( & V_4 -> V_34 ) ;
F_13 ( V_4 ) ;
F_14 ( & V_35 ) ;
}
static void F_15 ( struct V_3 * V_4 )
{
F_10 ( V_4 ) ;
F_11 ( & V_4 -> V_31 ) ;
F_13 ( V_4 ) ;
F_14 ( & V_35 ) ;
}
static void F_16 ( struct V_10 * V_11 )
{
F_17 ( & V_20 , V_11 -> V_21 ) ;
}
static void F_18 ( struct V_10 * V_11 )
{
struct V_3 * V_4 ;
struct V_3 * V_36 ;
F_8 ( & V_11 -> V_28 ) ;
F_19 (sub, sub_temp, &subscriber->subscription_list,
subscription_list) {
if ( V_4 -> V_29 != V_30 ) {
F_9 ( & V_11 -> V_28 ) ;
F_20 ( & V_4 -> V_34 ) ;
F_12 ( & V_4 -> V_34 ) ;
F_8 ( & V_11 -> V_28 ) ;
}
F_15 ( V_4 ) ;
}
F_9 ( & V_11 -> V_28 ) ;
F_13 ( V_11 ) ;
}
static void F_21 ( struct V_37 * V_32 ,
struct V_10 * V_11 )
{
struct V_3 * V_4 ;
struct V_3 * V_36 ;
int V_38 = 0 ;
F_19 (sub, sub_temp, &subscriber->subscription_list,
subscription_list) {
if ( ! memcmp ( V_32 , & V_4 -> V_15 . V_32 , sizeof( struct V_37 ) ) ) {
V_38 = 1 ;
break;
}
}
if ( ! V_38 )
return;
if ( V_4 -> V_29 != V_30 ) {
V_4 -> V_29 = V_30 ;
F_9 ( & V_11 -> V_28 ) ;
F_20 ( & V_4 -> V_34 ) ;
F_12 ( & V_4 -> V_34 ) ;
F_8 ( & V_11 -> V_28 ) ;
}
F_15 ( V_4 ) ;
}
static int F_22 ( struct V_37 * V_32 ,
struct V_10 * V_11 ,
struct V_3 * * V_39 ) {
struct V_3 * V_4 ;
int V_2 ;
V_2 = ! ( V_32 -> V_26 & ( V_27 | V_40 ) ) ;
if ( V_32 -> V_26 & F_1 ( V_41 , V_2 ) ) {
V_32 -> V_26 &= ~ F_1 ( V_41 , V_2 ) ;
F_21 ( V_32 , V_11 ) ;
return 0 ;
}
if ( F_23 ( & V_35 ) >= V_42 ) {
F_24 ( L_1 ,
V_42 ) ;
return - V_43 ;
}
V_4 = F_25 ( sizeof( * V_4 ) , V_44 ) ;
if ( ! V_4 ) {
F_24 ( L_2 ) ;
return - V_45 ;
}
V_4 -> V_22 . type = F_1 ( V_32 -> V_22 . type , V_2 ) ;
V_4 -> V_22 . V_23 = F_1 ( V_32 -> V_22 . V_23 , V_2 ) ;
V_4 -> V_22 . V_24 = F_1 ( V_32 -> V_22 . V_24 , V_2 ) ;
V_4 -> V_29 = F_1 ( V_32 -> V_29 , V_2 ) ;
V_4 -> V_26 = F_1 ( V_32 -> V_26 , V_2 ) ;
if ( ( ! ( V_4 -> V_26 & V_27 ) ==
! ( V_4 -> V_26 & V_40 ) ) ||
( V_4 -> V_22 . V_23 > V_4 -> V_22 . V_24 ) ) {
F_24 ( L_3 ) ;
F_13 ( V_4 ) ;
return - V_43 ;
}
F_26 ( & V_4 -> V_46 ) ;
F_27 ( & V_4 -> V_31 , & V_11 -> V_31 ) ;
V_4 -> V_11 = V_11 ;
V_4 -> V_2 = V_2 ;
memcpy ( & V_4 -> V_15 . V_32 , V_32 , sizeof( struct V_37 ) ) ;
F_28 ( & V_35 ) ;
if ( V_4 -> V_29 != V_30 ) {
F_29 ( & V_4 -> V_34 ,
( V_47 ) F_7 , ( unsigned long ) V_4 ) ;
F_30 ( & V_4 -> V_34 , V_4 -> V_29 ) ;
}
* V_39 = V_4 ;
return 0 ;
}
static void F_31 ( int V_21 , void * V_48 )
{
F_18 ( (struct V_10 * ) V_48 ) ;
}
static void F_32 ( int V_21 , struct V_49 * V_50 ,
void * V_48 , void * V_51 , T_2 V_52 )
{
struct V_10 * V_11 = V_48 ;
struct V_3 * V_4 = NULL ;
F_8 ( & V_11 -> V_28 ) ;
if ( F_22 ( (struct V_37 * ) V_51 , V_11 , & V_4 ) < 0 ) {
F_9 ( & V_11 -> V_28 ) ;
F_16 ( V_11 ) ;
return;
}
if ( V_4 )
F_33 ( V_4 ) ;
F_9 ( & V_11 -> V_28 ) ;
}
static void * F_34 ( int V_21 )
{
struct V_10 * V_11 ;
V_11 = F_35 ( sizeof( struct V_10 ) , V_44 ) ;
if ( V_11 == NULL ) {
F_24 ( L_4 ) ;
return NULL ;
}
F_26 ( & V_11 -> V_31 ) ;
V_11 -> V_21 = V_21 ;
F_36 ( & V_11 -> V_28 ) ;
return ( void * ) V_11 ;
}
int F_37 ( void )
{
return F_38 ( & V_20 ) ;
}
void F_39 ( void )
{
F_40 ( & V_20 ) ;
}

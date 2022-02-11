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
int V_14 ;
V_13 . V_15 = ( void * ) & V_4 -> V_16 ;
V_13 . V_17 = sizeof( struct V_18 ) ;
V_4 -> V_16 . V_7 = F_1 ( V_7 , V_4 -> V_2 ) ;
V_4 -> V_16 . V_5 = F_1 ( V_5 , V_4 -> V_2 ) ;
V_4 -> V_16 . V_6 = F_1 ( V_6 , V_4 -> V_2 ) ;
V_4 -> V_16 . V_19 . V_20 = F_1 ( V_8 , V_4 -> V_2 ) ;
V_4 -> V_16 . V_19 . V_9 = F_1 ( V_9 , V_4 -> V_2 ) ;
V_14 = F_4 ( & V_21 , V_11 -> V_22 , NULL ,
V_13 . V_15 , V_13 . V_17 ) ;
if ( V_14 < 0 )
F_5 ( L_1 ) ;
}
int F_6 ( struct V_3 * V_4 , T_1 V_5 ,
T_1 V_6 )
{
if ( V_5 < V_4 -> V_23 . V_24 )
V_5 = V_4 -> V_23 . V_24 ;
if ( V_6 > V_4 -> V_23 . V_25 )
V_6 = V_4 -> V_23 . V_25 ;
if ( V_5 > V_6 )
return 0 ;
return 1 ;
}
void F_7 ( struct V_3 * V_4 , T_1 V_5 ,
T_1 V_6 , T_1 V_7 , T_1 V_8 ,
T_1 V_9 , int V_26 )
{
if ( ! F_6 ( V_4 , V_5 , V_6 ) )
return;
if ( ! V_26 && ! ( V_4 -> V_27 & V_28 ) )
return;
F_3 ( V_4 , V_5 , V_6 , V_7 , V_8 , V_9 ) ;
}
static void F_8 ( struct V_3 * V_4 )
{
struct V_10 * V_11 = V_4 -> V_11 ;
F_9 ( & V_11 -> V_29 ) ;
if ( V_11 -> V_22 == 0 ) {
F_10 ( & V_11 -> V_29 ) ;
return;
}
if ( V_4 -> V_30 == V_31 ) {
F_10 ( & V_11 -> V_29 ) ;
return;
}
F_11 ( V_4 ) ;
F_12 ( & V_4 -> V_32 ) ;
F_10 ( & V_11 -> V_29 ) ;
F_3 ( V_4 , V_4 -> V_16 . V_33 . V_23 . V_24 , V_4 -> V_16 . V_33 . V_23 . V_25 ,
V_34 , 0 , 0 ) ;
F_13 ( & V_4 -> V_35 ) ;
F_14 ( V_4 ) ;
F_15 ( & V_36 ) ;
}
static void F_16 ( struct V_3 * V_4 )
{
F_11 ( V_4 ) ;
F_12 ( & V_4 -> V_32 ) ;
F_14 ( V_4 ) ;
F_15 ( & V_36 ) ;
}
static void F_17 ( struct V_10 * V_11 )
{
F_18 ( & V_21 , V_11 -> V_22 ) ;
}
static void F_19 ( struct V_10 * V_11 )
{
struct V_3 * V_4 ;
struct V_3 * V_37 ;
F_9 ( & V_11 -> V_29 ) ;
V_11 -> V_22 = 0 ;
F_20 (sub, sub_temp, &subscriber->subscription_list,
subscription_list) {
if ( V_4 -> V_30 != V_31 ) {
F_10 ( & V_11 -> V_29 ) ;
F_21 ( & V_4 -> V_35 ) ;
F_13 ( & V_4 -> V_35 ) ;
F_9 ( & V_11 -> V_29 ) ;
}
F_16 ( V_4 ) ;
}
F_10 ( & V_11 -> V_29 ) ;
F_14 ( V_11 ) ;
}
static void F_22 ( struct V_38 * V_33 ,
struct V_10 * V_11 )
{
struct V_3 * V_4 ;
struct V_3 * V_37 ;
int V_39 = 0 ;
F_20 (sub, sub_temp, &subscriber->subscription_list,
subscription_list) {
if ( ! memcmp ( V_33 , & V_4 -> V_16 . V_33 , sizeof( struct V_38 ) ) ) {
V_39 = 1 ;
break;
}
}
if ( ! V_39 )
return;
if ( V_4 -> V_30 != V_31 ) {
V_4 -> V_30 = V_31 ;
F_10 ( & V_11 -> V_29 ) ;
F_21 ( & V_4 -> V_35 ) ;
F_13 ( & V_4 -> V_35 ) ;
F_9 ( & V_11 -> V_29 ) ;
}
F_16 ( V_4 ) ;
}
static struct V_3 * F_23 ( struct V_38 * V_33 ,
struct V_10 * V_11 )
{
struct V_3 * V_4 ;
int V_2 ;
V_2 = ! ( V_33 -> V_27 & ( V_28 | V_40 ) ) ;
if ( V_33 -> V_27 & F_1 ( V_41 , V_2 ) ) {
V_33 -> V_27 &= ~ F_1 ( V_41 , V_2 ) ;
F_22 ( V_33 , V_11 ) ;
return NULL ;
}
if ( F_24 ( & V_36 ) >= V_42 ) {
F_25 ( L_2 ,
V_42 ) ;
F_17 ( V_11 ) ;
return NULL ;
}
V_4 = F_26 ( sizeof( * V_4 ) , V_43 ) ;
if ( ! V_4 ) {
F_25 ( L_3 ) ;
F_17 ( V_11 ) ;
return NULL ;
}
V_4 -> V_23 . type = F_1 ( V_33 -> V_23 . type , V_2 ) ;
V_4 -> V_23 . V_24 = F_1 ( V_33 -> V_23 . V_24 , V_2 ) ;
V_4 -> V_23 . V_25 = F_1 ( V_33 -> V_23 . V_25 , V_2 ) ;
V_4 -> V_30 = F_1 ( V_33 -> V_30 , V_2 ) ;
V_4 -> V_27 = F_1 ( V_33 -> V_27 , V_2 ) ;
if ( ( ! ( V_4 -> V_27 & V_28 ) ==
! ( V_4 -> V_27 & V_40 ) ) ||
( V_4 -> V_23 . V_24 > V_4 -> V_23 . V_25 ) ) {
F_25 ( L_4 ) ;
F_14 ( V_4 ) ;
F_17 ( V_11 ) ;
return NULL ;
}
F_27 ( & V_4 -> V_44 ) ;
F_28 ( & V_4 -> V_32 , & V_11 -> V_32 ) ;
V_4 -> V_11 = V_11 ;
V_4 -> V_2 = V_2 ;
memcpy ( & V_4 -> V_16 . V_33 , V_33 , sizeof( struct V_38 ) ) ;
F_29 ( & V_36 ) ;
if ( V_4 -> V_30 != V_31 ) {
F_30 ( & V_4 -> V_35 ,
( V_45 ) F_8 , ( unsigned long ) V_4 ) ;
F_31 ( & V_4 -> V_35 , V_4 -> V_30 ) ;
}
return V_4 ;
}
static void F_32 ( int V_22 , void * V_46 )
{
F_19 ( (struct V_10 * ) V_46 ) ;
}
static void F_33 ( int V_22 , struct V_47 * V_48 ,
void * V_46 , void * V_49 , T_2 V_50 )
{
struct V_10 * V_11 = V_46 ;
struct V_3 * V_4 ;
F_9 ( & V_11 -> V_29 ) ;
V_4 = F_23 ( (struct V_38 * ) V_49 , V_11 ) ;
if ( V_4 )
F_34 ( V_4 ) ;
F_10 ( & V_11 -> V_29 ) ;
}
static void * F_35 ( int V_22 )
{
struct V_10 * V_11 ;
V_11 = F_36 ( sizeof( struct V_10 ) , V_43 ) ;
if ( V_11 == NULL ) {
F_25 ( L_5 ) ;
return NULL ;
}
F_27 ( & V_11 -> V_32 ) ;
V_11 -> V_22 = V_22 ;
F_37 ( & V_11 -> V_29 ) ;
return ( void * ) V_11 ;
}
int F_38 ( void )
{
return F_39 ( & V_21 ) ;
}
void F_40 ( void )
{
F_41 ( & V_21 ) ;
}

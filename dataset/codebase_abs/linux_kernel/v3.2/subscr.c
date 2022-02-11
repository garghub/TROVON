static T_1 F_1 ( T_1 V_1 , int V_2 )
{
return V_2 ? F_2 ( V_1 ) : V_1 ;
}
static void F_3 ( struct V_3 * V_4 ,
T_1 V_5 ,
T_1 V_6 ,
T_1 V_7 ,
T_1 V_8 ,
T_1 V_9 )
{
struct V_10 V_11 ;
V_11 . V_12 = ( void * ) & V_4 -> V_13 ;
V_11 . V_14 = sizeof( struct V_15 ) ;
V_4 -> V_13 . V_7 = F_1 ( V_7 , V_4 -> V_2 ) ;
V_4 -> V_13 . V_5 = F_1 ( V_5 , V_4 -> V_2 ) ;
V_4 -> V_13 . V_6 = F_1 ( V_6 , V_4 -> V_2 ) ;
V_4 -> V_13 . V_16 . V_17 = F_1 ( V_8 , V_4 -> V_2 ) ;
V_4 -> V_13 . V_16 . V_9 = F_1 ( V_9 , V_4 -> V_2 ) ;
F_4 ( V_4 -> V_18 , 1 , & V_11 , V_11 . V_14 ) ;
}
int F_5 ( struct V_3 * V_4 ,
T_1 V_5 ,
T_1 V_6 )
{
if ( V_5 < V_4 -> V_19 . V_20 )
V_5 = V_4 -> V_19 . V_20 ;
if ( V_6 > V_4 -> V_19 . V_21 )
V_6 = V_4 -> V_19 . V_21 ;
if ( V_5 > V_6 )
return 0 ;
return 1 ;
}
void F_6 ( struct V_3 * V_4 ,
T_1 V_5 ,
T_1 V_6 ,
T_1 V_7 ,
T_1 V_8 ,
T_1 V_9 ,
int V_22 )
{
if ( ! F_5 ( V_4 , V_5 , V_6 ) )
return;
if ( ! V_22 && ! ( V_4 -> V_23 & V_24 ) )
return;
F_3 ( V_4 , V_5 , V_6 , V_7 , V_8 , V_9 ) ;
}
static void F_7 ( struct V_3 * V_4 )
{
struct V_25 * V_26 ;
V_26 = F_8 ( V_4 -> V_18 ) ;
if ( V_26 == NULL )
return;
if ( V_4 -> V_27 == V_28 ) {
F_9 ( V_26 ) ;
return;
}
F_10 ( V_4 ) ;
F_11 ( & V_4 -> V_29 ) ;
F_9 ( V_26 ) ;
F_3 ( V_4 , V_4 -> V_13 . V_30 . V_19 . V_20 , V_4 -> V_13 . V_30 . V_19 . V_21 ,
V_31 , 0 , 0 ) ;
F_12 ( & V_4 -> V_32 ) ;
F_13 ( V_4 ) ;
F_14 ( & V_33 . V_34 ) ;
}
static void F_15 ( struct V_3 * V_4 )
{
F_10 ( V_4 ) ;
F_11 ( & V_4 -> V_29 ) ;
F_13 ( V_4 ) ;
F_14 ( & V_33 . V_34 ) ;
}
static void F_16 ( struct V_35 * V_35 )
{
T_1 V_8 ;
struct V_3 * V_4 ;
struct V_3 * V_36 ;
V_8 = V_35 -> V_8 ;
V_35 -> V_8 = 0 ;
F_17 ( V_35 -> V_37 ) ;
F_18 ( V_8 ) ;
F_19 ( V_8 ) ;
F_20 (sub, sub_temp, &subscriber->subscription_list,
subscription_list) {
if ( V_4 -> V_27 != V_28 ) {
F_21 ( & V_4 -> V_32 ) ;
F_12 ( & V_4 -> V_32 ) ;
}
F_15 ( V_4 ) ;
}
F_22 ( & V_33 . V_37 ) ;
F_11 ( & V_35 -> V_38 ) ;
F_17 ( & V_33 . V_37 ) ;
F_22 ( V_35 -> V_37 ) ;
F_13 ( V_35 ) ;
}
static void F_23 ( struct V_39 * V_30 ,
struct V_35 * V_35 )
{
struct V_3 * V_4 ;
struct V_3 * V_36 ;
int V_40 = 0 ;
F_20 (sub, sub_temp, &subscriber->subscription_list,
subscription_list) {
if ( ! memcmp ( V_30 , & V_4 -> V_13 . V_30 , sizeof( struct V_39 ) ) ) {
V_40 = 1 ;
break;
}
}
if ( ! V_40 )
return;
if ( V_4 -> V_27 != V_28 ) {
V_4 -> V_27 = V_28 ;
F_17 ( V_35 -> V_37 ) ;
F_21 ( & V_4 -> V_32 ) ;
F_12 ( & V_4 -> V_32 ) ;
F_22 ( V_35 -> V_37 ) ;
}
F_15 ( V_4 ) ;
}
static struct V_3 * F_24 ( struct V_39 * V_30 ,
struct V_35 * V_35 )
{
struct V_3 * V_4 ;
int V_2 ;
V_2 = ! ( V_30 -> V_23 & ( V_24 | V_41 ) ) ;
if ( V_30 -> V_23 & F_1 ( V_42 , V_2 ) ) {
V_30 -> V_23 &= ~ F_1 ( V_42 , V_2 ) ;
F_23 ( V_30 , V_35 ) ;
return NULL ;
}
if ( F_25 ( & V_33 . V_34 ) >= V_43 ) {
F_26 ( L_1 ,
V_43 ) ;
F_16 ( V_35 ) ;
return NULL ;
}
V_4 = F_27 ( sizeof( * V_4 ) , V_44 ) ;
if ( ! V_4 ) {
F_26 ( L_2 ) ;
F_16 ( V_35 ) ;
return NULL ;
}
V_4 -> V_19 . type = F_1 ( V_30 -> V_19 . type , V_2 ) ;
V_4 -> V_19 . V_20 = F_1 ( V_30 -> V_19 . V_20 , V_2 ) ;
V_4 -> V_19 . V_21 = F_1 ( V_30 -> V_19 . V_21 , V_2 ) ;
V_4 -> V_27 = F_1 ( V_30 -> V_27 , V_2 ) ;
V_4 -> V_23 = F_1 ( V_30 -> V_23 , V_2 ) ;
if ( ( ! ( V_4 -> V_23 & V_24 ) ==
! ( V_4 -> V_23 & V_41 ) ) ||
( V_4 -> V_19 . V_20 > V_4 -> V_19 . V_21 ) ) {
F_26 ( L_3 ) ;
F_13 ( V_4 ) ;
F_16 ( V_35 ) ;
return NULL ;
}
F_28 ( & V_4 -> V_45 ) ;
F_29 ( & V_4 -> V_29 , & V_35 -> V_29 ) ;
V_4 -> V_18 = V_35 -> V_8 ;
V_4 -> V_2 = V_2 ;
memcpy ( & V_4 -> V_13 . V_30 , V_30 , sizeof( struct V_39 ) ) ;
F_30 ( & V_33 . V_34 ) ;
if ( V_4 -> V_27 != V_28 ) {
F_31 ( & V_4 -> V_32 ,
( V_46 ) F_7 , ( unsigned long ) V_4 ) ;
F_32 ( & V_4 -> V_32 , V_4 -> V_27 ) ;
}
return V_4 ;
}
static void F_33 ( void * V_47 ,
T_1 V_8 ,
struct V_48 * * V_49 ,
unsigned char const * V_50 ,
unsigned int V_51 ,
int V_52 )
{
struct V_35 * V_35 = V_47 ;
T_2 * V_53 ;
if ( F_8 ( V_8 ) == NULL )
return;
V_53 = V_35 -> V_37 ;
F_16 ( V_35 ) ;
F_17 ( V_53 ) ;
}
static void F_34 ( void * V_47 ,
T_1 V_8 ,
struct V_48 * * V_49 ,
const T_3 * V_50 ,
T_1 V_51 )
{
struct V_35 * V_35 = V_47 ;
T_2 * V_53 ;
struct V_3 * V_4 ;
if ( F_8 ( V_8 ) == NULL )
return;
V_53 = V_35 -> V_37 ;
if ( V_51 != sizeof( struct V_39 ) ) {
F_16 ( V_35 ) ;
F_17 ( V_53 ) ;
} else {
V_4 = F_24 ( (struct V_39 * ) V_50 , V_35 ) ;
F_17 ( V_53 ) ;
if ( V_4 != NULL ) {
F_35 ( V_4 ) ;
}
}
}
static void F_36 ( void * V_47 ,
T_1 V_8 ,
struct V_48 * * V_49 ,
const T_3 * V_50 ,
T_1 V_51 ,
T_1 V_54 ,
struct V_55 const * V_56 ,
struct V_57 const * V_58 )
{
struct V_35 * V_35 ;
T_1 V_59 ;
V_35 = F_37 ( sizeof( struct V_35 ) , V_44 ) ;
if ( V_35 == NULL ) {
F_26 ( L_4 ) ;
return;
}
F_28 ( & V_35 -> V_29 ) ;
F_28 ( & V_35 -> V_38 ) ;
F_38 ( V_35 ,
V_54 ,
NULL ,
NULL ,
F_33 ,
NULL ,
NULL ,
F_34 ,
NULL ,
& V_35 -> V_8 ) ;
if ( V_35 -> V_8 == 0 ) {
F_26 ( L_5 ) ;
F_13 ( V_35 ) ;
return;
}
F_39 ( V_35 -> V_8 , V_56 ) ;
V_35 -> V_37 = F_8 ( V_35 -> V_8 ) -> V_37 ;
F_22 ( & V_33 . V_37 ) ;
F_29 ( & V_35 -> V_38 , & V_33 . V_38 ) ;
F_17 ( & V_33 . V_37 ) ;
V_59 = V_35 -> V_8 ;
F_17 ( V_35 -> V_37 ) ;
F_4 ( V_59 , 0 , NULL , 0 ) ;
if ( V_51 != 0 ) {
F_34 ( V_35 , V_59 ,
V_49 , V_50 , V_51 ) ;
}
}
int F_40 ( void )
{
struct V_57 V_19 = { V_60 , V_60 , V_60 } ;
int V_61 ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
F_41 ( & V_33 . V_37 ) ;
F_28 ( & V_33 . V_38 ) ;
V_61 = F_38 ( NULL ,
V_62 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_36 ,
NULL ,
NULL ,
& V_33 . V_63 ) ;
if ( V_61 )
goto V_64;
V_61 = F_42 ( V_33 . V_63 , V_65 , & V_19 ) ;
if ( V_61 ) {
F_19 ( V_33 . V_63 ) ;
V_33 . V_63 = 0 ;
goto V_64;
}
return 0 ;
V_64:
F_43 ( L_6 ) ;
return V_61 ;
}
void F_44 ( void )
{
struct V_35 * V_35 ;
struct V_35 * V_66 ;
T_2 * V_53 ;
if ( V_33 . V_63 ) {
F_19 ( V_33 . V_63 ) ;
V_33 . V_63 = 0 ;
F_20 (subscriber, subscriber_temp,
&topsrv.subscriber_list,
subscriber_list) {
V_53 = V_35 -> V_37 ;
F_22 ( V_53 ) ;
F_16 ( V_35 ) ;
F_17 ( V_53 ) ;
}
}
}

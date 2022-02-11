static T_1 F_1 ( T_1 V_1 , int V_2 )
{
return V_2 ? F_2 ( V_1 ) : V_1 ;
}
static void F_3 ( struct V_3 * V_4 , T_1 V_5 ,
T_1 V_6 , T_1 V_7 , T_1 V_8 ,
T_1 V_9 )
{
struct V_10 * V_11 = F_4 ( V_4 -> V_12 , V_13 ) ;
struct V_14 * V_15 = V_4 -> V_15 ;
struct V_16 V_17 ;
V_17 . V_18 = ( void * ) & V_4 -> V_19 ;
V_17 . V_20 = sizeof( struct V_21 ) ;
V_4 -> V_19 . V_7 = F_1 ( V_7 , V_4 -> V_2 ) ;
V_4 -> V_19 . V_5 = F_1 ( V_5 , V_4 -> V_2 ) ;
V_4 -> V_19 . V_6 = F_1 ( V_6 , V_4 -> V_2 ) ;
V_4 -> V_19 . V_22 . V_23 = F_1 ( V_8 , V_4 -> V_2 ) ;
V_4 -> V_19 . V_22 . V_9 = F_1 ( V_9 , V_4 -> V_2 ) ;
F_5 ( V_11 -> V_24 , V_15 -> V_25 , NULL ,
V_17 . V_18 , V_17 . V_20 ) ;
}
int F_6 ( struct V_3 * V_4 , T_1 V_5 ,
T_1 V_6 )
{
if ( V_5 < V_4 -> V_26 . V_27 )
V_5 = V_4 -> V_26 . V_27 ;
if ( V_6 > V_4 -> V_26 . V_28 )
V_6 = V_4 -> V_26 . V_28 ;
if ( V_5 > V_6 )
return 0 ;
return 1 ;
}
void F_7 ( struct V_3 * V_4 , T_1 V_5 ,
T_1 V_6 , T_1 V_7 , T_1 V_8 ,
T_1 V_9 , int V_29 )
{
if ( ! F_6 ( V_4 , V_5 , V_6 ) )
return;
if ( ! V_29 && ! ( V_4 -> V_30 & V_31 ) )
return;
F_3 ( V_4 , V_5 , V_6 , V_7 , V_8 , V_9 ) ;
}
static void F_8 ( unsigned long V_32 )
{
struct V_3 * V_4 = (struct V_3 * ) V_32 ;
struct V_14 * V_15 = V_4 -> V_15 ;
struct V_10 * V_11 = F_4 ( V_4 -> V_12 , V_13 ) ;
F_9 ( & V_15 -> V_33 ) ;
if ( V_4 -> V_34 == V_35 ) {
F_10 ( & V_15 -> V_33 ) ;
return;
}
F_11 ( V_4 ) ;
F_12 ( & V_4 -> V_36 ) ;
F_10 ( & V_15 -> V_33 ) ;
F_3 ( V_4 , V_4 -> V_19 . V_37 . V_26 . V_27 , V_4 -> V_19 . V_37 . V_26 . V_28 ,
V_38 , 0 , 0 ) ;
F_13 ( V_4 ) ;
F_14 ( & V_11 -> V_39 ) ;
}
static void F_15 ( struct V_3 * V_4 )
{
struct V_10 * V_11 = F_4 ( V_4 -> V_12 , V_13 ) ;
F_11 ( V_4 ) ;
F_12 ( & V_4 -> V_36 ) ;
F_13 ( V_4 ) ;
F_14 ( & V_11 -> V_39 ) ;
}
static void F_16 ( struct V_14 * V_15 )
{
struct V_3 * V_4 ;
struct V_3 * V_40 ;
F_9 ( & V_15 -> V_33 ) ;
F_17 (sub, sub_temp, &subscriber->subscription_list,
subscription_list) {
if ( V_4 -> V_34 != V_35 ) {
F_10 ( & V_15 -> V_33 ) ;
F_18 ( & V_4 -> V_41 ) ;
F_9 ( & V_15 -> V_33 ) ;
}
F_15 ( V_4 ) ;
}
F_10 ( & V_15 -> V_33 ) ;
F_13 ( V_15 ) ;
}
static void F_19 ( struct V_42 * V_37 ,
struct V_14 * V_15 )
{
struct V_3 * V_4 ;
struct V_3 * V_40 ;
int V_43 = 0 ;
F_17 (sub, sub_temp, &subscriber->subscription_list,
subscription_list) {
if ( ! memcmp ( V_37 , & V_4 -> V_19 . V_37 , sizeof( struct V_42 ) ) ) {
V_43 = 1 ;
break;
}
}
if ( ! V_43 )
return;
if ( V_4 -> V_34 != V_35 ) {
V_4 -> V_34 = V_35 ;
F_10 ( & V_15 -> V_33 ) ;
F_18 ( & V_4 -> V_41 ) ;
F_9 ( & V_15 -> V_33 ) ;
}
F_15 ( V_4 ) ;
}
static int F_20 ( struct V_12 * V_12 , struct V_42 * V_37 ,
struct V_14 * V_15 ,
struct V_3 * * V_44 )
{
struct V_10 * V_11 = F_4 ( V_12 , V_13 ) ;
struct V_3 * V_4 ;
int V_2 ;
V_2 = ! ( V_37 -> V_30 & ( V_31 | V_45 ) ) ;
if ( V_37 -> V_30 & F_1 ( V_46 , V_2 ) ) {
V_37 -> V_30 &= ~ F_1 ( V_46 , V_2 ) ;
F_19 ( V_37 , V_15 ) ;
return 0 ;
}
if ( F_21 ( & V_11 -> V_39 ) >= V_47 ) {
F_22 ( L_1 ,
V_47 ) ;
return - V_48 ;
}
V_4 = F_23 ( sizeof( * V_4 ) , V_49 ) ;
if ( ! V_4 ) {
F_22 ( L_2 ) ;
return - V_50 ;
}
V_4 -> V_12 = V_12 ;
V_4 -> V_26 . type = F_1 ( V_37 -> V_26 . type , V_2 ) ;
V_4 -> V_26 . V_27 = F_1 ( V_37 -> V_26 . V_27 , V_2 ) ;
V_4 -> V_26 . V_28 = F_1 ( V_37 -> V_26 . V_28 , V_2 ) ;
V_4 -> V_34 = F_24 ( F_1 ( V_37 -> V_34 , V_2 ) ) ;
V_4 -> V_30 = F_1 ( V_37 -> V_30 , V_2 ) ;
if ( ( ! ( V_4 -> V_30 & V_31 ) ==
! ( V_4 -> V_30 & V_45 ) ) ||
( V_4 -> V_26 . V_27 > V_4 -> V_26 . V_28 ) ) {
F_22 ( L_3 ) ;
F_13 ( V_4 ) ;
return - V_48 ;
}
F_25 ( & V_4 -> V_36 , & V_15 -> V_36 ) ;
V_4 -> V_15 = V_15 ;
V_4 -> V_2 = V_2 ;
memcpy ( & V_4 -> V_19 . V_37 , V_37 , sizeof( struct V_42 ) ) ;
F_26 ( & V_11 -> V_39 ) ;
if ( V_4 -> V_34 != V_35 ) {
F_27 ( & V_4 -> V_41 , F_8 , ( unsigned long ) V_4 ) ;
F_28 ( & V_4 -> V_41 , V_51 + V_4 -> V_34 ) ;
}
* V_44 = V_4 ;
return 0 ;
}
static void F_29 ( int V_25 , void * V_52 )
{
F_16 ( (struct V_14 * ) V_52 ) ;
}
static void F_30 ( struct V_12 * V_12 , int V_25 ,
struct V_53 * V_54 , void * V_52 ,
void * V_55 , T_2 V_56 )
{
struct V_14 * V_15 = V_52 ;
struct V_3 * V_4 = NULL ;
struct V_10 * V_11 = F_4 ( V_12 , V_13 ) ;
F_9 ( & V_15 -> V_33 ) ;
F_20 ( V_12 , (struct V_42 * ) V_55 , V_15 , & V_4 ) ;
if ( V_4 )
F_31 ( V_4 ) ;
else
F_32 ( V_11 -> V_24 , V_15 -> V_25 ) ;
F_10 ( & V_15 -> V_33 ) ;
}
static void * F_33 ( int V_25 )
{
struct V_14 * V_15 ;
V_15 = F_34 ( sizeof( struct V_14 ) , V_49 ) ;
if ( V_15 == NULL ) {
F_22 ( L_4 ) ;
return NULL ;
}
F_35 ( & V_15 -> V_36 ) ;
V_15 -> V_25 = V_25 ;
F_36 ( & V_15 -> V_33 ) ;
return ( void * ) V_15 ;
}
int F_37 ( struct V_12 * V_12 )
{
struct V_10 * V_11 = F_4 ( V_12 , V_13 ) ;
const char V_57 [] = L_5 ;
struct V_58 * V_24 ;
struct V_53 * V_59 ;
V_59 = F_34 ( sizeof( * V_59 ) , V_49 ) ;
if ( ! V_59 )
return - V_50 ;
V_59 -> V_60 = V_61 ;
V_59 -> V_62 = V_63 ;
V_59 -> V_54 . V_64 . type = V_65 ;
V_59 -> V_54 . V_64 . V_27 = V_65 ;
V_59 -> V_54 . V_64 . V_28 = V_65 ;
V_59 -> V_66 = V_67 ;
V_24 = F_34 ( sizeof( * V_24 ) , V_49 ) ;
if ( ! V_24 ) {
F_13 ( V_59 ) ;
return - V_50 ;
}
V_24 -> V_12 = V_12 ;
V_24 -> V_59 = V_59 ;
V_24 -> V_68 = V_69 ;
V_24 -> type = V_70 ;
V_24 -> V_71 = sizeof( struct V_42 ) ;
V_24 -> V_72 = F_30 ;
V_24 -> V_73 = F_33 ;
V_24 -> V_74 = F_29 ;
strncpy ( V_24 -> V_57 , V_57 , strlen ( V_57 ) + 1 ) ;
V_11 -> V_24 = V_24 ;
F_38 ( & V_11 -> V_39 , 0 ) ;
return F_39 ( V_24 ) ;
}
void F_40 ( struct V_12 * V_12 )
{
struct V_10 * V_11 = F_4 ( V_12 , V_13 ) ;
struct V_58 * V_24 = V_11 -> V_24 ;
F_41 ( V_24 ) ;
F_13 ( V_24 -> V_59 ) ;
F_13 ( V_24 ) ;
}

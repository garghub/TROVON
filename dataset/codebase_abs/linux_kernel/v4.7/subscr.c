static T_1 F_1 ( T_1 V_1 , int V_2 )
{
return V_2 ? F_2 ( V_1 ) : V_1 ;
}
static void F_3 ( struct V_3 * V_4 ,
T_1 V_5 , T_1 V_6 ,
T_1 V_7 , T_1 V_8 , T_1 V_9 )
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
int F_6 ( struct V_26 * V_27 , T_1 V_5 ,
T_1 V_6 )
{
if ( V_5 < V_27 -> V_28 )
V_5 = V_27 -> V_28 ;
if ( V_6 > V_27 -> V_29 )
V_6 = V_27 -> V_29 ;
if ( V_5 > V_6 )
return 0 ;
return 1 ;
}
T_1 F_7 ( T_1 type , int V_2 )
{
return F_1 ( type , V_2 ) ;
}
void F_8 ( struct V_26 * V_1 , int V_2 ,
struct V_26 * V_30 )
{
V_30 -> type = F_1 ( V_1 -> type , V_2 ) ;
V_30 -> V_28 = F_1 ( V_1 -> V_28 , V_2 ) ;
V_30 -> V_29 = F_1 ( V_1 -> V_29 , V_2 ) ;
}
void F_9 ( struct V_3 * V_4 , T_1 V_5 ,
T_1 V_6 , T_1 V_7 , T_1 V_8 ,
T_1 V_9 , int V_31 )
{
struct V_26 V_27 ;
F_8 ( & V_4 -> V_19 . V_32 . V_27 , V_4 -> V_2 , & V_27 ) ;
if ( ! F_6 ( & V_27 , V_5 , V_6 ) )
return;
if ( ! V_31 &&
! ( F_1 ( V_4 -> V_19 . V_32 . V_33 , V_4 -> V_2 ) & V_34 ) )
return;
F_3 ( V_4 , V_5 , V_6 , V_7 , V_8 ,
V_9 ) ;
}
static void F_10 ( unsigned long V_35 )
{
struct V_3 * V_4 = (struct V_3 * ) V_35 ;
struct V_14 * V_15 = V_4 -> V_15 ;
F_3 ( V_4 , V_4 -> V_19 . V_32 . V_27 . V_28 , V_4 -> V_19 . V_32 . V_27 . V_29 ,
V_36 , 0 , 0 ) ;
F_11 ( & V_15 -> V_37 ) ;
F_12 ( V_4 ) ;
F_13 ( & V_15 -> V_37 ) ;
F_14 ( V_15 ) ;
}
static void F_15 ( struct V_38 * V_38 )
{
struct V_14 * V_39 = F_16 ( V_38 ,
struct V_14 , V_38 ) ;
F_17 ( V_39 ) ;
}
static void F_14 ( struct V_14 * V_15 )
{
F_18 ( & V_15 -> V_38 , F_15 ) ;
}
static void F_19 ( struct V_14 * V_15 )
{
F_20 ( & V_15 -> V_38 ) ;
}
static struct V_14 * F_21 ( int V_25 )
{
struct V_14 * V_15 ;
V_15 = F_22 ( sizeof( * V_15 ) , V_40 ) ;
if ( ! V_15 ) {
F_23 ( L_1 ) ;
return NULL ;
}
F_24 ( & V_15 -> V_38 ) ;
F_25 ( & V_15 -> V_41 ) ;
V_15 -> V_25 = V_25 ;
F_26 ( & V_15 -> V_37 ) ;
return V_15 ;
}
static void F_27 ( struct V_14 * V_15 )
{
struct V_3 * V_4 , * V_42 ;
T_1 V_43 ;
F_11 ( & V_15 -> V_37 ) ;
F_28 (sub, temp, &subscriber->subscrp_list,
subscrp_list) {
V_43 = F_1 ( V_4 -> V_19 . V_32 . V_43 , V_4 -> V_2 ) ;
if ( ( V_43 == V_44 ) || F_29 ( & V_4 -> V_45 ) ) {
F_12 ( V_4 ) ;
F_14 ( V_15 ) ;
}
}
F_13 ( & V_15 -> V_37 ) ;
F_14 ( V_15 ) ;
}
static void F_12 ( struct V_3 * V_4 )
{
struct V_10 * V_11 = F_4 ( V_4 -> V_12 , V_13 ) ;
F_30 ( V_4 ) ;
F_31 ( & V_4 -> V_41 ) ;
F_17 ( V_4 ) ;
F_32 ( & V_11 -> V_46 ) ;
}
static void F_33 ( struct V_47 * V_32 ,
struct V_14 * V_15 )
{
struct V_3 * V_4 , * V_42 ;
T_1 V_43 ;
F_11 ( & V_15 -> V_37 ) ;
F_28 (sub, temp, &subscriber->subscrp_list,
subscrp_list) {
if ( ! memcmp ( V_32 , & V_4 -> V_19 . V_32 , sizeof( struct V_47 ) ) ) {
V_43 = F_1 ( V_4 -> V_19 . V_32 . V_43 , V_4 -> V_2 ) ;
if ( ( V_43 == V_44 ) ||
F_29 ( & V_4 -> V_45 ) ) {
F_12 ( V_4 ) ;
F_14 ( V_15 ) ;
}
break;
}
}
F_13 ( & V_15 -> V_37 ) ;
}
static struct V_3 * F_34 ( struct V_12 * V_12 ,
struct V_47 * V_32 ,
int V_2 )
{
struct V_10 * V_11 = F_4 ( V_12 , V_13 ) ;
struct V_3 * V_4 ;
T_1 V_33 = F_1 ( V_32 -> V_33 , V_2 ) ;
if ( F_35 ( & V_11 -> V_46 ) >= V_48 ) {
F_23 ( L_2 ,
V_48 ) ;
return NULL ;
}
V_4 = F_36 ( sizeof( * V_4 ) , V_40 ) ;
if ( ! V_4 ) {
F_23 ( L_3 ) ;
return NULL ;
}
V_4 -> V_12 = V_12 ;
if ( ( ( V_33 & V_34 ) && ( V_33 & V_49 ) ) ||
( F_1 ( V_32 -> V_27 . V_28 , V_2 ) > F_1 ( V_32 -> V_27 . V_29 , V_2 ) ) ) {
F_23 ( L_4 ) ;
F_17 ( V_4 ) ;
return NULL ;
}
V_4 -> V_2 = V_2 ;
memcpy ( & V_4 -> V_19 . V_32 , V_32 , sizeof( * V_32 ) ) ;
F_37 ( & V_11 -> V_46 ) ;
return V_4 ;
}
static void F_38 ( struct V_12 * V_12 , struct V_47 * V_32 ,
struct V_14 * V_15 , int V_2 )
{
struct V_10 * V_11 = F_4 ( V_12 , V_13 ) ;
struct V_3 * V_4 = NULL ;
T_1 V_43 ;
V_4 = F_34 ( V_12 , V_32 , V_2 ) ;
if ( ! V_4 )
return F_39 ( V_11 -> V_24 , V_15 -> V_25 ) ;
F_11 ( & V_15 -> V_37 ) ;
F_40 ( & V_4 -> V_41 , & V_15 -> V_41 ) ;
F_19 ( V_15 ) ;
V_4 -> V_15 = V_15 ;
F_41 ( V_4 ) ;
F_13 ( & V_15 -> V_37 ) ;
V_43 = F_1 ( V_4 -> V_19 . V_32 . V_43 , V_2 ) ;
if ( V_43 == V_44 )
return;
F_42 ( & V_4 -> V_45 , F_10 , ( unsigned long ) V_4 ) ;
F_43 ( & V_4 -> V_45 , V_50 + F_44 ( V_43 ) ) ;
}
static void F_45 ( int V_25 , void * V_51 )
{
F_27 ( (struct V_14 * ) V_51 ) ;
}
static void F_46 ( struct V_12 * V_12 , int V_25 ,
struct V_52 * V_53 , void * V_51 ,
void * V_54 , T_2 V_55 )
{
struct V_14 * V_15 = V_51 ;
struct V_47 * V_32 = (struct V_47 * ) V_54 ;
int V_2 ;
V_2 = ! ( V_32 -> V_33 & ( V_34 | V_49 |
V_56 ) ) ;
if ( V_32 -> V_33 & F_1 ( V_56 , V_2 ) ) {
V_32 -> V_33 &= ~ F_1 ( V_56 , V_2 ) ;
return F_33 ( V_32 , V_15 ) ;
}
F_38 ( V_12 , V_32 , V_15 , V_2 ) ;
}
static void * F_47 ( int V_25 )
{
return ( void * ) F_21 ( V_25 ) ;
}
int F_48 ( struct V_12 * V_12 )
{
struct V_10 * V_11 = F_4 ( V_12 , V_13 ) ;
const char V_57 [] = L_5 ;
struct V_58 * V_24 ;
struct V_52 * V_59 ;
V_59 = F_22 ( sizeof( * V_59 ) , V_40 ) ;
if ( ! V_59 )
return - V_60 ;
V_59 -> V_61 = V_62 ;
V_59 -> V_63 = V_64 ;
V_59 -> V_53 . V_65 . type = V_66 ;
V_59 -> V_53 . V_65 . V_28 = V_66 ;
V_59 -> V_53 . V_65 . V_29 = V_66 ;
V_59 -> V_67 = V_68 ;
V_24 = F_22 ( sizeof( * V_24 ) , V_40 ) ;
if ( ! V_24 ) {
F_17 ( V_59 ) ;
return - V_60 ;
}
V_24 -> V_12 = V_12 ;
V_24 -> V_59 = V_59 ;
V_24 -> V_69 = V_70 ;
V_24 -> type = V_71 ;
V_24 -> V_72 = sizeof( struct V_47 ) ;
V_24 -> V_73 = F_46 ;
V_24 -> V_74 = F_47 ;
V_24 -> V_75 = F_45 ;
strncpy ( V_24 -> V_57 , V_57 , strlen ( V_57 ) + 1 ) ;
V_11 -> V_24 = V_24 ;
F_49 ( & V_11 -> V_46 , 0 ) ;
return F_50 ( V_24 ) ;
}
void F_51 ( struct V_12 * V_12 )
{
struct V_10 * V_11 = F_4 ( V_12 , V_13 ) ;
struct V_58 * V_24 = V_11 -> V_24 ;
F_52 ( V_24 ) ;
F_17 ( V_24 -> V_59 ) ;
F_17 ( V_24 ) ;
}

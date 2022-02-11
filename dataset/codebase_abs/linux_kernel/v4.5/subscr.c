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
F_3 ( V_4 , V_5 , V_6 , V_7 , V_8 ,
V_9 ) ;
}
static void F_8 ( unsigned long V_32 )
{
struct V_3 * V_4 = (struct V_3 * ) V_32 ;
struct V_14 * V_15 = V_4 -> V_15 ;
F_3 ( V_4 , V_4 -> V_19 . V_33 . V_26 . V_27 , V_4 -> V_19 . V_33 . V_26 . V_28 ,
V_34 , 0 , 0 ) ;
F_9 ( & V_15 -> V_35 ) ;
F_10 ( V_4 ) ;
F_11 ( & V_15 -> V_35 ) ;
F_12 ( V_15 ) ;
}
static void F_13 ( struct V_36 * V_36 )
{
struct V_14 * V_37 = F_14 ( V_36 ,
struct V_14 , V_36 ) ;
F_15 ( V_37 ) ;
}
static void F_12 ( struct V_14 * V_15 )
{
F_16 ( & V_15 -> V_36 , F_13 ) ;
}
static void F_17 ( struct V_14 * V_15 )
{
F_18 ( & V_15 -> V_36 ) ;
}
static struct V_14 * F_19 ( int V_25 )
{
struct V_14 * V_15 ;
V_15 = F_20 ( sizeof( * V_15 ) , V_38 ) ;
if ( ! V_15 ) {
F_21 ( L_1 ) ;
return NULL ;
}
F_22 ( & V_15 -> V_36 ) ;
F_23 ( & V_15 -> V_39 ) ;
V_15 -> V_25 = V_25 ;
F_24 ( & V_15 -> V_35 ) ;
return V_15 ;
}
static void F_25 ( struct V_14 * V_15 )
{
struct V_3 * V_4 , * V_40 ;
F_9 ( & V_15 -> V_35 ) ;
F_26 (sub, temp, &subscriber->subscrp_list,
subscrp_list) {
if ( F_27 ( & V_4 -> V_41 ) ) {
F_10 ( V_4 ) ;
F_12 ( V_15 ) ;
}
}
F_11 ( & V_15 -> V_35 ) ;
F_12 ( V_15 ) ;
}
static void F_10 ( struct V_3 * V_4 )
{
struct V_10 * V_11 = F_4 ( V_4 -> V_12 , V_13 ) ;
F_28 ( V_4 ) ;
F_29 ( & V_4 -> V_39 ) ;
F_15 ( V_4 ) ;
F_30 ( & V_11 -> V_42 ) ;
}
static void F_31 ( struct V_43 * V_33 ,
struct V_14 * V_15 )
{
struct V_3 * V_4 , * V_40 ;
F_9 ( & V_15 -> V_35 ) ;
F_26 (sub, temp, &subscriber->subscrp_list,
subscrp_list) {
if ( ! memcmp ( V_33 , & V_4 -> V_19 . V_33 , sizeof( struct V_43 ) ) ) {
if ( F_27 ( & V_4 -> V_41 ) ) {
F_10 ( V_4 ) ;
F_12 ( V_15 ) ;
}
break;
}
}
F_11 ( & V_15 -> V_35 ) ;
}
static int F_32 ( struct V_12 * V_12 , struct V_43 * V_33 ,
struct V_14 * V_15 ,
struct V_3 * * V_44 )
{
struct V_10 * V_11 = F_4 ( V_12 , V_13 ) ;
struct V_3 * V_4 ;
int V_2 ;
V_2 = ! ( V_33 -> V_30 & ( V_31 | V_45 ) ) ;
if ( V_33 -> V_30 & F_1 ( V_46 , V_2 ) ) {
V_33 -> V_30 &= ~ F_1 ( V_46 , V_2 ) ;
F_31 ( V_33 , V_15 ) ;
return 0 ;
}
if ( F_33 ( & V_11 -> V_42 ) >= V_47 ) {
F_21 ( L_2 ,
V_47 ) ;
return - V_48 ;
}
V_4 = F_34 ( sizeof( * V_4 ) , V_38 ) ;
if ( ! V_4 ) {
F_21 ( L_3 ) ;
return - V_49 ;
}
V_4 -> V_12 = V_12 ;
V_4 -> V_26 . type = F_1 ( V_33 -> V_26 . type , V_2 ) ;
V_4 -> V_26 . V_27 = F_1 ( V_33 -> V_26 . V_27 , V_2 ) ;
V_4 -> V_26 . V_28 = F_1 ( V_33 -> V_26 . V_28 , V_2 ) ;
V_4 -> V_50 = F_35 ( F_1 ( V_33 -> V_50 , V_2 ) ) ;
V_4 -> V_30 = F_1 ( V_33 -> V_30 , V_2 ) ;
if ( ( ! ( V_4 -> V_30 & V_31 ) ==
! ( V_4 -> V_30 & V_45 ) ) ||
( V_4 -> V_26 . V_27 > V_4 -> V_26 . V_28 ) ) {
F_21 ( L_4 ) ;
F_15 ( V_4 ) ;
return - V_48 ;
}
F_9 ( & V_15 -> V_35 ) ;
F_36 ( & V_4 -> V_39 , & V_15 -> V_39 ) ;
F_11 ( & V_15 -> V_35 ) ;
V_4 -> V_15 = V_15 ;
V_4 -> V_2 = V_2 ;
memcpy ( & V_4 -> V_19 . V_33 , V_33 , sizeof( * V_33 ) ) ;
F_37 ( & V_11 -> V_42 ) ;
F_38 ( & V_4 -> V_41 , F_8 , ( unsigned long ) V_4 ) ;
if ( V_4 -> V_50 != V_51 )
V_4 -> V_50 += V_52 ;
if ( ! F_39 ( & V_4 -> V_41 , V_4 -> V_50 ) )
F_17 ( V_15 ) ;
* V_44 = V_4 ;
return 0 ;
}
static void F_40 ( int V_25 , void * V_53 )
{
F_25 ( (struct V_14 * ) V_53 ) ;
}
static void F_41 ( struct V_12 * V_12 , int V_25 ,
struct V_54 * V_55 , void * V_53 ,
void * V_56 , T_2 V_57 )
{
struct V_14 * V_58 = V_53 ;
struct V_3 * V_4 = NULL ;
struct V_10 * V_11 = F_4 ( V_12 , V_13 ) ;
if ( F_32 ( V_12 , (struct V_43 * ) V_56 , V_58 , & V_4 ) )
return F_42 ( V_11 -> V_24 , V_58 -> V_25 ) ;
if ( V_4 )
F_43 ( V_4 ) ;
}
static void * F_44 ( int V_25 )
{
return ( void * ) F_19 ( V_25 ) ;
}
int F_45 ( struct V_12 * V_12 )
{
struct V_10 * V_11 = F_4 ( V_12 , V_13 ) ;
const char V_59 [] = L_5 ;
struct V_60 * V_24 ;
struct V_54 * V_61 ;
V_61 = F_20 ( sizeof( * V_61 ) , V_38 ) ;
if ( ! V_61 )
return - V_49 ;
V_61 -> V_62 = V_63 ;
V_61 -> V_64 = V_65 ;
V_61 -> V_55 . V_66 . type = V_67 ;
V_61 -> V_55 . V_66 . V_27 = V_67 ;
V_61 -> V_55 . V_66 . V_28 = V_67 ;
V_61 -> V_68 = V_69 ;
V_24 = F_20 ( sizeof( * V_24 ) , V_38 ) ;
if ( ! V_24 ) {
F_15 ( V_61 ) ;
return - V_49 ;
}
V_24 -> V_12 = V_12 ;
V_24 -> V_61 = V_61 ;
V_24 -> V_70 = V_71 ;
V_24 -> type = V_72 ;
V_24 -> V_73 = sizeof( struct V_43 ) ;
V_24 -> V_74 = F_41 ;
V_24 -> V_75 = F_44 ;
V_24 -> V_76 = F_40 ;
strncpy ( V_24 -> V_59 , V_59 , strlen ( V_59 ) + 1 ) ;
V_11 -> V_24 = V_24 ;
F_46 ( & V_11 -> V_42 , 0 ) ;
return F_47 ( V_24 ) ;
}
void F_48 ( struct V_12 * V_12 )
{
struct V_10 * V_11 = F_4 ( V_12 , V_13 ) ;
struct V_60 * V_24 = V_11 -> V_24 ;
F_49 ( V_24 ) ;
F_15 ( V_24 -> V_61 ) ;
F_15 ( V_24 ) ;
}

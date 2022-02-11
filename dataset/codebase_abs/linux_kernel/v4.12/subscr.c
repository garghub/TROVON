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
F_11 ( & V_15 -> V_36 ) ;
F_12 ( V_4 ) ;
F_13 ( & V_4 -> V_37 ) ;
F_14 ( & V_15 -> V_36 ) ;
F_3 ( V_4 , V_4 -> V_19 . V_32 . V_27 . V_28 , V_4 -> V_19 . V_32 . V_27 . V_29 ,
V_38 , 0 , 0 ) ;
F_15 ( V_4 ) ;
}
static void F_16 ( struct V_39 * V_39 )
{
F_17 ( F_18 ( V_39 , struct V_14 , V_39 ) ) ;
}
static void F_19 ( struct V_14 * V_15 )
{
F_20 ( & V_15 -> V_39 , F_16 ) ;
}
static void F_21 ( struct V_14 * V_15 )
{
F_22 ( & V_15 -> V_39 ) ;
}
static void F_23 ( struct V_39 * V_39 )
{
struct V_3 * V_4 = F_18 ( V_39 ,
struct V_3 ,
V_39 ) ;
struct V_10 * V_11 = F_4 ( V_4 -> V_12 , V_13 ) ;
struct V_14 * V_15 = V_4 -> V_15 ;
F_24 ( & V_11 -> V_40 ) ;
F_17 ( V_4 ) ;
F_19 ( V_15 ) ;
}
void F_15 ( struct V_3 * V_41 )
{
F_20 ( & V_41 -> V_39 , F_23 ) ;
}
void F_25 ( struct V_3 * V_41 )
{
F_22 ( & V_41 -> V_39 ) ;
}
static void F_26 ( struct V_14 * V_15 ,
struct V_42 * V_32 )
{
struct V_43 * V_44 = & V_15 -> V_37 ;
struct V_3 * V_4 , * V_45 ;
F_11 ( & V_15 -> V_36 ) ;
F_27 (sub, temp, subscription_list, subscrp_list) {
if ( V_32 && memcmp ( V_32 , & V_4 -> V_19 . V_32 , sizeof( struct V_42 ) ) )
continue;
F_12 ( V_4 ) ;
F_13 ( & V_4 -> V_37 ) ;
F_28 ( V_4 ) ;
if ( V_32 )
break;
}
F_14 ( & V_15 -> V_36 ) ;
}
static struct V_14 * F_29 ( int V_25 )
{
struct V_14 * V_15 ;
V_15 = F_30 ( sizeof( * V_15 ) , V_46 ) ;
if ( ! V_15 ) {
F_31 ( L_1 ) ;
return NULL ;
}
F_32 ( & V_15 -> V_37 ) ;
F_33 ( & V_15 -> V_39 ) ;
V_15 -> V_25 = V_25 ;
F_34 ( & V_15 -> V_36 ) ;
return V_15 ;
}
static void F_35 ( struct V_14 * V_15 )
{
F_26 ( V_15 , NULL ) ;
F_19 ( V_15 ) ;
}
static void F_28 ( struct V_3 * V_4 )
{
T_1 V_47 = F_1 ( V_4 -> V_19 . V_32 . V_47 , V_4 -> V_2 ) ;
if ( V_47 == V_48 || F_36 ( & V_4 -> V_49 ) )
F_15 ( V_4 ) ;
}
static void F_37 ( struct V_42 * V_32 ,
struct V_14 * V_15 )
{
F_26 ( V_15 , V_32 ) ;
}
static struct V_3 * F_38 ( struct V_12 * V_12 ,
struct V_42 * V_32 ,
int V_2 )
{
struct V_10 * V_11 = F_4 ( V_12 , V_13 ) ;
struct V_3 * V_4 ;
T_1 V_33 = F_1 ( V_32 -> V_33 , V_2 ) ;
if ( F_39 ( & V_11 -> V_40 ) >= V_50 ) {
F_31 ( L_2 ,
V_50 ) ;
return NULL ;
}
V_4 = F_40 ( sizeof( * V_4 ) , V_46 ) ;
if ( ! V_4 ) {
F_31 ( L_3 ) ;
return NULL ;
}
V_4 -> V_12 = V_12 ;
if ( ( ( V_33 & V_34 ) && ( V_33 & V_51 ) ) ||
( F_1 ( V_32 -> V_27 . V_28 , V_2 ) > F_1 ( V_32 -> V_27 . V_29 , V_2 ) ) ) {
F_31 ( L_4 ) ;
F_17 ( V_4 ) ;
return NULL ;
}
V_4 -> V_2 = V_2 ;
memcpy ( & V_4 -> V_19 . V_32 , V_32 , sizeof( * V_32 ) ) ;
F_41 ( & V_11 -> V_40 ) ;
F_33 ( & V_4 -> V_39 ) ;
return V_4 ;
}
static void F_42 ( struct V_12 * V_12 , struct V_42 * V_32 ,
struct V_14 * V_15 , int V_2 )
{
struct V_10 * V_11 = F_4 ( V_12 , V_13 ) ;
struct V_3 * V_4 = NULL ;
T_1 V_47 ;
V_4 = F_38 ( V_12 , V_32 , V_2 ) ;
if ( ! V_4 )
return F_43 ( V_11 -> V_24 , V_15 -> V_25 ) ;
F_11 ( & V_15 -> V_36 ) ;
F_44 ( & V_4 -> V_37 , & V_15 -> V_37 ) ;
V_4 -> V_15 = V_15 ;
F_45 ( V_4 ) ;
F_21 ( V_15 ) ;
F_14 ( & V_15 -> V_36 ) ;
F_46 ( & V_4 -> V_49 , F_10 , ( unsigned long ) V_4 ) ;
V_47 = F_1 ( V_4 -> V_19 . V_32 . V_47 , V_2 ) ;
if ( V_47 != V_48 )
F_47 ( & V_4 -> V_49 , V_52 + F_48 ( V_47 ) ) ;
}
static void F_49 ( int V_25 , void * V_53 )
{
F_35 ( (struct V_14 * ) V_53 ) ;
}
static void F_50 ( struct V_12 * V_12 , int V_25 ,
struct V_54 * V_55 , void * V_53 ,
void * V_56 , T_2 V_57 )
{
struct V_14 * V_15 = V_53 ;
struct V_42 * V_32 = (struct V_42 * ) V_56 ;
int V_2 ;
V_2 = ! ( V_32 -> V_33 & ( V_34 | V_51 |
V_58 ) ) ;
if ( V_32 -> V_33 & F_1 ( V_58 , V_2 ) ) {
V_32 -> V_33 &= ~ F_1 ( V_58 , V_2 ) ;
return F_37 ( V_32 , V_15 ) ;
}
F_42 ( V_12 , V_32 , V_15 , V_2 ) ;
}
static void * F_51 ( int V_25 )
{
return ( void * ) F_29 ( V_25 ) ;
}
int F_52 ( struct V_12 * V_12 )
{
struct V_10 * V_11 = F_4 ( V_12 , V_13 ) ;
const char V_59 [] = L_5 ;
struct V_60 * V_24 ;
struct V_54 * V_61 ;
V_61 = F_30 ( sizeof( * V_61 ) , V_46 ) ;
if ( ! V_61 )
return - V_62 ;
V_61 -> V_63 = V_64 ;
V_61 -> V_65 = V_66 ;
V_61 -> V_55 . V_67 . type = V_68 ;
V_61 -> V_55 . V_67 . V_28 = V_68 ;
V_61 -> V_55 . V_67 . V_29 = V_68 ;
V_61 -> V_69 = V_70 ;
V_24 = F_30 ( sizeof( * V_24 ) , V_46 ) ;
if ( ! V_24 ) {
F_17 ( V_61 ) ;
return - V_62 ;
}
V_24 -> V_12 = V_12 ;
V_24 -> V_61 = V_61 ;
V_24 -> V_71 = V_72 ;
V_24 -> type = V_73 ;
V_24 -> V_74 = sizeof( struct V_42 ) ;
V_24 -> V_75 = F_50 ;
V_24 -> V_76 = F_51 ;
V_24 -> V_77 = F_49 ;
strncpy ( V_24 -> V_59 , V_59 , strlen ( V_59 ) + 1 ) ;
V_11 -> V_24 = V_24 ;
F_53 ( & V_11 -> V_40 , 0 ) ;
return F_54 ( V_24 ) ;
}
void F_55 ( struct V_12 * V_12 )
{
struct V_10 * V_11 = F_4 ( V_12 , V_13 ) ;
struct V_60 * V_24 = V_11 -> V_24 ;
F_56 ( V_24 ) ;
F_17 ( V_24 -> V_61 ) ;
F_17 ( V_24 ) ;
}

static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 = 0 ;
F_2 ( V_2 ) ;
F_3 (mc_list_entry, dev) {
V_8 = F_4 ( sizeof( * V_8 ) , V_10 ) ;
if ( ! V_8 ) {
V_9 = - V_11 ;
break;
}
F_5 ( V_8 -> V_12 , V_6 -> V_12 ) ;
F_6 ( & V_8 -> V_13 , V_4 ) ;
V_9 ++ ;
}
F_7 ( V_2 ) ;
return V_9 ;
}
static bool F_8 ( T_1 * V_14 ,
struct V_3 * V_4 )
{
struct V_7 * V_15 ;
F_9 (mcast_entry, mcast_list, list)
if ( F_10 ( V_15 -> V_12 , V_14 ) )
return true ;
return false ;
}
static void F_11 ( struct V_3 * V_4 )
{
struct V_7 * V_15 ;
struct V_16 * V_17 ;
F_12 (mcast_entry, tmp, mcast_list, list) {
F_13 ( & V_15 -> V_13 ) ;
F_14 ( V_15 ) ;
}
}
static void F_15 ( struct V_18 * V_19 ,
struct V_3 * V_4 )
{
struct V_7 * V_15 ;
struct V_16 * V_17 ;
F_12 (mcast_entry, tmp, &bat_priv->mcast.mla_list,
list) {
if ( V_4 &&
F_8 ( V_15 -> V_12 ,
V_4 ) )
continue;
F_16 ( V_19 , V_15 -> V_12 ,
V_20 ,
L_1 , false ) ;
F_13 ( & V_15 -> V_13 ) ;
F_14 ( V_15 ) ;
}
}
static void F_17 ( struct V_18 * V_19 ,
struct V_3 * V_4 )
{
struct V_7 * V_15 ;
struct V_16 * V_17 ;
if ( ! V_4 )
return;
F_12 (mcast_entry, tmp, mcast_list, list) {
if ( F_8 ( V_15 -> V_12 ,
& V_19 -> V_21 . V_22 ) )
continue;
if ( ! F_18 ( V_19 -> V_23 ,
V_15 -> V_12 , V_20 ,
V_24 , V_25 ) )
continue;
F_13 ( & V_15 -> V_13 ) ;
F_6 ( & V_15 -> V_13 , & V_19 -> V_21 . V_22 ) ;
}
}
static bool F_19 ( struct V_18 * V_19 )
{
struct V_1 * V_26 = V_19 -> V_23 ;
F_20 () ;
do {
V_26 = F_21 ( V_26 ) ;
} while ( V_26 && ! ( V_26 -> V_27 & V_28 ) );
F_22 () ;
return V_26 ;
}
static bool F_23 ( struct V_18 * V_19 )
{
struct V_29 V_30 ;
V_30 . V_31 = V_20 ;
memset ( V_30 . V_32 , 0 , sizeof( V_30 . V_32 ) ) ;
if ( F_19 ( V_19 ) ) {
if ( V_19 -> V_21 . V_33 ) {
F_24 ( V_19 ,
V_34 , 1 ) ;
V_19 -> V_21 . V_33 = false ;
}
return false ;
}
if ( ! V_19 -> V_21 . V_33 ||
V_30 . V_31 != V_19 -> V_21 . V_31 ) {
F_25 ( V_19 , V_34 , 1 ,
& V_30 , sizeof( V_30 ) ) ;
V_19 -> V_21 . V_31 = V_30 . V_31 ;
V_19 -> V_21 . V_33 = true ;
}
return true ;
}
void F_26 ( struct V_18 * V_19 )
{
struct V_1 * V_23 = V_19 -> V_23 ;
struct V_3 V_4 = V_35 ;
int V_9 ;
if ( ! F_23 ( V_19 ) )
goto V_36;
V_9 = F_1 ( V_23 , & V_4 ) ;
if ( V_9 < 0 )
goto V_37;
V_36:
F_15 ( V_19 , & V_4 ) ;
F_17 ( V_19 , & V_4 ) ;
V_37:
F_11 ( & V_4 ) ;
}
static int F_27 ( struct V_18 * V_19 ,
struct V_38 * V_39 ,
bool * V_40 )
{
struct V_41 * V_41 ;
if ( ! F_28 ( V_39 , sizeof( struct V_42 ) + sizeof( * V_41 ) ) )
return - V_11 ;
V_41 = F_29 ( V_39 ) ;
if ( ! F_30 ( V_41 -> V_43 ) )
return - V_44 ;
* V_40 = true ;
return 0 ;
}
static int F_31 ( struct V_18 * V_19 ,
struct V_38 * V_39 ,
bool * V_40 )
{
struct V_45 * V_46 ;
if ( ! F_28 ( V_39 , sizeof( struct V_42 ) + sizeof( * V_46 ) ) )
return - V_11 ;
V_46 = F_32 ( V_39 ) ;
if ( F_33 ( & V_46 -> V_43 ) != V_47 )
return - V_44 ;
if ( F_34 ( & V_46 -> V_43 ) )
* V_40 = true ;
return 0 ;
}
static int F_35 ( struct V_18 * V_19 ,
struct V_38 * V_39 ,
bool * V_40 )
{
struct V_42 * V_42 = F_36 ( V_39 ) ;
if ( ! F_37 ( & V_19 -> V_48 ) )
return - V_44 ;
if ( F_37 ( & V_19 -> V_21 . V_49 ) )
return - V_44 ;
switch ( F_38 ( V_42 -> V_50 ) ) {
case V_51 :
return F_27 ( V_19 , V_39 ,
V_40 ) ;
case V_52 :
return F_31 ( V_19 , V_39 ,
V_40 ) ;
default:
return - V_44 ;
}
}
static int F_39 ( struct V_18 * V_19 ,
struct V_42 * V_42 )
{
switch ( F_38 ( V_42 -> V_50 ) ) {
case V_51 :
return F_37 ( & V_19 -> V_21 . V_53 ) ;
case V_52 :
return F_37 ( & V_19 -> V_21 . V_54 ) ;
default:
return 0 ;
}
}
static struct V_55 *
F_40 ( struct V_18 * V_19 ,
struct V_42 * V_42 )
{
return F_41 ( V_19 , V_42 -> V_56 ,
V_42 -> V_57 , V_20 ) ;
}
static struct V_55 *
F_42 ( struct V_18 * V_19 )
{
struct V_55 * V_58 , * V_59 = NULL ;
F_20 () ;
F_43 (tmp_orig_node,
&bat_priv->mcast.want_all_ipv4_list,
mcast_want_all_ipv4_node) {
if ( ! F_44 ( & V_58 -> V_60 ) )
continue;
V_59 = V_58 ;
break;
}
F_22 () ;
return V_59 ;
}
static struct V_55 *
F_45 ( struct V_18 * V_19 )
{
struct V_55 * V_58 , * V_59 = NULL ;
F_20 () ;
F_43 (tmp_orig_node,
&bat_priv->mcast.want_all_ipv6_list,
mcast_want_all_ipv6_node) {
if ( ! F_44 ( & V_58 -> V_60 ) )
continue;
V_59 = V_58 ;
break;
}
F_22 () ;
return V_59 ;
}
static struct V_55 *
F_46 ( struct V_18 * V_19 ,
struct V_42 * V_42 )
{
switch ( F_38 ( V_42 -> V_50 ) ) {
case V_51 :
return F_42 ( V_19 ) ;
case V_52 :
return F_45 ( V_19 ) ;
default:
return NULL ;
}
}
static struct V_55 *
F_47 ( struct V_18 * V_19 )
{
struct V_55 * V_58 , * V_59 = NULL ;
F_20 () ;
F_43 (tmp_orig_node,
&bat_priv->mcast.want_all_unsnoopables_list,
mcast_want_all_unsnoopables_node) {
if ( ! F_44 ( & V_58 -> V_60 ) )
continue;
V_59 = V_58 ;
break;
}
F_22 () ;
return V_59 ;
}
enum V_61
F_48 ( struct V_18 * V_19 , struct V_38 * V_39 ,
struct V_55 * * V_62 )
{
int V_9 , V_63 , V_64 , V_65 , V_66 ;
bool V_40 = false ;
struct V_42 * V_42 ;
V_9 = F_35 ( V_19 , V_39 , & V_40 ) ;
if ( V_9 == - V_11 )
return V_67 ;
else if ( V_9 < 0 )
return V_68 ;
V_42 = F_36 ( V_39 ) ;
V_63 = F_49 ( V_19 , V_42 -> V_57 ,
V_20 ) ;
V_64 = F_39 ( V_19 , V_42 ) ;
V_65 = ! V_40 ? 0 :
F_37 ( & V_19 -> V_21 . V_69 ) ;
V_66 = V_63 + V_64 + V_65 ;
switch ( V_66 ) {
case 1 :
if ( V_63 )
* V_62 = F_40 ( V_19 , V_42 ) ;
else if ( V_64 )
* V_62 = F_46 ( V_19 , V_42 ) ;
else if ( V_65 )
* V_62 = F_47 ( V_19 ) ;
if ( * V_62 )
return V_70 ;
case 0 :
return V_67 ;
default:
return V_68 ;
}
}
static void F_50 ( struct V_18 * V_19 ,
struct V_55 * V_62 ,
T_1 V_71 )
{
if ( V_71 & V_72 &&
! ( V_62 -> V_71 & V_72 ) ) {
F_51 ( & V_19 -> V_21 . V_69 ) ;
F_52 ( & V_19 -> V_21 . V_73 ) ;
F_53 ( & V_62 -> V_74 ,
& V_19 -> V_21 . V_75 ) ;
F_54 ( & V_19 -> V_21 . V_73 ) ;
} else if ( ! ( V_71 & V_72 ) &&
V_62 -> V_71 & V_72 ) {
F_55 ( & V_19 -> V_21 . V_69 ) ;
F_52 ( & V_19 -> V_21 . V_73 ) ;
F_56 ( & V_62 -> V_74 ) ;
F_54 ( & V_19 -> V_21 . V_73 ) ;
}
}
static void F_57 ( struct V_18 * V_19 ,
struct V_55 * V_62 ,
T_1 V_71 )
{
if ( V_71 & V_76 &&
! ( V_62 -> V_71 & V_76 ) ) {
F_51 ( & V_19 -> V_21 . V_53 ) ;
F_52 ( & V_19 -> V_21 . V_73 ) ;
F_53 ( & V_62 -> V_77 ,
& V_19 -> V_21 . V_78 ) ;
F_54 ( & V_19 -> V_21 . V_73 ) ;
} else if ( ! ( V_71 & V_76 ) &&
V_62 -> V_71 & V_76 ) {
F_55 ( & V_19 -> V_21 . V_53 ) ;
F_52 ( & V_19 -> V_21 . V_73 ) ;
F_56 ( & V_62 -> V_77 ) ;
F_54 ( & V_19 -> V_21 . V_73 ) ;
}
}
static void F_58 ( struct V_18 * V_19 ,
struct V_55 * V_62 ,
T_1 V_71 )
{
if ( V_71 & V_79 &&
! ( V_62 -> V_71 & V_79 ) ) {
F_51 ( & V_19 -> V_21 . V_54 ) ;
F_52 ( & V_19 -> V_21 . V_73 ) ;
F_53 ( & V_62 -> V_80 ,
& V_19 -> V_21 . V_81 ) ;
F_54 ( & V_19 -> V_21 . V_73 ) ;
} else if ( ! ( V_71 & V_79 ) &&
V_62 -> V_71 & V_79 ) {
F_55 ( & V_19 -> V_21 . V_54 ) ;
F_52 ( & V_19 -> V_21 . V_73 ) ;
F_56 ( & V_62 -> V_80 ) ;
F_54 ( & V_19 -> V_21 . V_73 ) ;
}
}
static void F_59 ( struct V_18 * V_19 ,
struct V_55 * V_62 ,
T_1 V_31 ,
void * V_82 ,
T_2 V_83 )
{
bool V_84 = ! ( V_31 & V_85 ) ;
T_1 V_71 = V_20 ;
bool V_86 ;
V_86 = V_62 -> V_87 & V_88 ;
if ( V_84 &&
! ( V_62 -> V_89 & V_88 ) ) {
if ( V_86 )
F_55 ( & V_19 -> V_21 . V_49 ) ;
V_62 -> V_89 |= V_88 ;
} else if ( ! V_84 &&
( V_62 -> V_89 & V_88 ||
! V_86 ) ) {
F_51 ( & V_19 -> V_21 . V_49 ) ;
V_62 -> V_89 &= ~ V_88 ;
}
V_62 -> V_87 |= V_88 ;
if ( V_84 && V_82 &&
( V_83 >= sizeof( V_71 ) ) )
V_71 = * ( T_1 * ) V_82 ;
F_50 ( V_19 , V_62 , V_71 ) ;
F_57 ( V_19 , V_62 , V_71 ) ;
F_58 ( V_19 , V_62 , V_71 ) ;
V_62 -> V_71 = V_71 ;
}
void F_60 ( struct V_18 * V_19 )
{
F_61 ( V_19 , F_59 ,
NULL , V_34 , 1 ,
V_85 ) ;
}
void F_62 ( struct V_18 * V_19 )
{
F_24 ( V_19 , V_34 , 1 ) ;
F_63 ( V_19 , V_34 , 1 ) ;
F_15 ( V_19 , NULL ) ;
}
void F_64 ( struct V_55 * V_62 )
{
struct V_18 * V_19 = V_62 -> V_19 ;
if ( ! ( V_62 -> V_89 & V_88 ) &&
V_62 -> V_87 & V_88 )
F_55 ( & V_19 -> V_21 . V_49 ) ;
F_50 ( V_19 , V_62 , V_20 ) ;
F_57 ( V_19 , V_62 , V_20 ) ;
F_58 ( V_19 , V_62 , V_20 ) ;
}

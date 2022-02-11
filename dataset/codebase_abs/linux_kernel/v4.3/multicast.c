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
static void F_11 ( struct V_16 * V_17 ,
struct V_3 * V_4 )
{
struct V_7 * V_15 ;
struct V_18 * V_19 ;
F_12 ( & V_17 -> V_20 . V_21 ) ;
F_13 (mcast_entry, tmp, mcast_list, list) {
F_14 ( & V_15 -> V_13 ) ;
F_15 ( V_15 ) ;
}
}
static void F_16 ( struct V_16 * V_17 ,
struct V_3 * V_4 )
{
struct V_7 * V_15 ;
struct V_18 * V_19 ;
F_12 ( & V_17 -> V_20 . V_21 ) ;
F_13 (mcast_entry, tmp, &bat_priv->mcast.mla_list,
list) {
if ( V_4 &&
F_8 ( V_15 -> V_12 ,
V_4 ) )
continue;
F_17 ( V_17 , V_15 -> V_12 ,
V_22 ,
L_1 , false ) ;
F_14 ( & V_15 -> V_13 ) ;
F_15 ( V_15 ) ;
}
}
static void F_18 ( struct V_16 * V_17 ,
struct V_3 * V_4 )
{
struct V_7 * V_15 ;
struct V_18 * V_19 ;
F_12 ( & V_17 -> V_20 . V_21 ) ;
if ( ! V_4 )
return;
F_13 (mcast_entry, tmp, mcast_list, list) {
if ( F_8 ( V_15 -> V_12 ,
& V_17 -> V_23 . V_24 ) )
continue;
if ( ! F_19 ( V_17 -> V_25 ,
V_15 -> V_12 , V_22 ,
V_26 , V_27 ) )
continue;
F_14 ( & V_15 -> V_13 ) ;
F_6 ( & V_15 -> V_13 , & V_17 -> V_23 . V_24 ) ;
}
}
static bool F_20 ( struct V_16 * V_17 )
{
struct V_1 * V_28 = V_17 -> V_25 ;
F_21 () ;
do {
V_28 = F_22 ( V_28 ) ;
} while ( V_28 && ! ( V_28 -> V_29 & V_30 ) );
F_23 () ;
return V_28 ;
}
static bool F_24 ( struct V_16 * V_17 )
{
struct V_31 V_32 ;
V_32 . V_33 = V_22 ;
memset ( V_32 . V_34 , 0 , sizeof( V_32 . V_34 ) ) ;
if ( F_20 ( V_17 ) ) {
if ( V_17 -> V_23 . V_35 ) {
F_25 ( V_17 ,
V_36 , 1 ) ;
V_17 -> V_23 . V_35 = false ;
}
return false ;
}
if ( ! V_17 -> V_23 . V_35 ||
V_32 . V_33 != V_17 -> V_23 . V_33 ) {
F_26 ( V_17 , V_36 , 1 ,
& V_32 , sizeof( V_32 ) ) ;
V_17 -> V_23 . V_33 = V_32 . V_33 ;
V_17 -> V_23 . V_35 = true ;
}
return true ;
}
void F_27 ( struct V_16 * V_17 )
{
struct V_1 * V_25 = V_17 -> V_25 ;
struct V_3 V_4 = V_37 ;
int V_9 ;
if ( ! F_24 ( V_17 ) )
goto V_38;
V_9 = F_1 ( V_25 , & V_4 ) ;
if ( V_9 < 0 )
goto V_39;
V_38:
F_16 ( V_17 , & V_4 ) ;
F_18 ( V_17 , & V_4 ) ;
V_39:
F_11 ( V_17 , & V_4 ) ;
}
static int F_28 ( struct V_16 * V_17 ,
struct V_40 * V_41 ,
bool * V_42 )
{
struct V_43 * V_43 ;
if ( ! F_29 ( V_41 , sizeof( struct V_44 ) + sizeof( * V_43 ) ) )
return - V_11 ;
V_43 = F_30 ( V_41 ) ;
if ( ! F_31 ( V_43 -> V_45 ) )
return - V_46 ;
* V_42 = true ;
return 0 ;
}
static int F_32 ( struct V_16 * V_17 ,
struct V_40 * V_41 ,
bool * V_42 )
{
struct V_47 * V_48 ;
if ( ! F_29 ( V_41 , sizeof( struct V_44 ) + sizeof( * V_48 ) ) )
return - V_11 ;
V_48 = F_33 ( V_41 ) ;
if ( F_34 ( & V_48 -> V_45 ) != V_49 )
return - V_46 ;
if ( F_35 ( & V_48 -> V_45 ) )
* V_42 = true ;
return 0 ;
}
static int F_36 ( struct V_16 * V_17 ,
struct V_40 * V_41 ,
bool * V_42 )
{
struct V_44 * V_44 = F_37 ( V_41 ) ;
if ( ! F_38 ( & V_17 -> V_50 ) )
return - V_46 ;
if ( F_38 ( & V_17 -> V_23 . V_51 ) )
return - V_46 ;
switch ( F_39 ( V_44 -> V_52 ) ) {
case V_53 :
return F_28 ( V_17 , V_41 ,
V_42 ) ;
case V_54 :
return F_32 ( V_17 , V_41 ,
V_42 ) ;
default:
return - V_46 ;
}
}
static int F_40 ( struct V_16 * V_17 ,
struct V_44 * V_44 )
{
switch ( F_39 ( V_44 -> V_52 ) ) {
case V_53 :
return F_38 ( & V_17 -> V_23 . V_55 ) ;
case V_54 :
return F_38 ( & V_17 -> V_23 . V_56 ) ;
default:
return 0 ;
}
}
static struct V_57 *
F_41 ( struct V_16 * V_17 ,
struct V_44 * V_44 )
{
return F_42 ( V_17 , V_44 -> V_58 ,
V_44 -> V_59 , V_22 ) ;
}
static struct V_57 *
F_43 ( struct V_16 * V_17 )
{
struct V_57 * V_60 , * V_61 = NULL ;
F_21 () ;
F_44 (tmp_orig_node,
&bat_priv->mcast.want_all_ipv4_list,
mcast_want_all_ipv4_node) {
if ( ! F_45 ( & V_60 -> V_62 ) )
continue;
V_61 = V_60 ;
break;
}
F_23 () ;
return V_61 ;
}
static struct V_57 *
F_46 ( struct V_16 * V_17 )
{
struct V_57 * V_60 , * V_61 = NULL ;
F_21 () ;
F_44 (tmp_orig_node,
&bat_priv->mcast.want_all_ipv6_list,
mcast_want_all_ipv6_node) {
if ( ! F_45 ( & V_60 -> V_62 ) )
continue;
V_61 = V_60 ;
break;
}
F_23 () ;
return V_61 ;
}
static struct V_57 *
F_47 ( struct V_16 * V_17 ,
struct V_44 * V_44 )
{
switch ( F_39 ( V_44 -> V_52 ) ) {
case V_53 :
return F_43 ( V_17 ) ;
case V_54 :
return F_46 ( V_17 ) ;
default:
return NULL ;
}
}
static struct V_57 *
F_48 ( struct V_16 * V_17 )
{
struct V_57 * V_60 , * V_61 = NULL ;
F_21 () ;
F_44 (tmp_orig_node,
&bat_priv->mcast.want_all_unsnoopables_list,
mcast_want_all_unsnoopables_node) {
if ( ! F_45 ( & V_60 -> V_62 ) )
continue;
V_61 = V_60 ;
break;
}
F_23 () ;
return V_61 ;
}
enum V_63
F_49 ( struct V_16 * V_17 , struct V_40 * V_41 ,
struct V_57 * * V_64 )
{
int V_9 , V_65 , V_66 , V_67 , V_68 ;
bool V_42 = false ;
struct V_44 * V_44 ;
V_9 = F_36 ( V_17 , V_41 , & V_42 ) ;
if ( V_9 == - V_11 )
return V_69 ;
else if ( V_9 < 0 )
return V_70 ;
V_44 = F_37 ( V_41 ) ;
V_65 = F_50 ( V_17 , V_44 -> V_59 ,
V_22 ) ;
V_66 = F_40 ( V_17 , V_44 ) ;
V_67 = ! V_42 ? 0 :
F_38 ( & V_17 -> V_23 . V_71 ) ;
V_68 = V_65 + V_66 + V_67 ;
switch ( V_68 ) {
case 1 :
if ( V_65 )
* V_64 = F_41 ( V_17 , V_44 ) ;
else if ( V_66 )
* V_64 = F_47 ( V_17 , V_44 ) ;
else if ( V_67 )
* V_64 = F_48 ( V_17 ) ;
if ( * V_64 )
return V_72 ;
case 0 :
return V_69 ;
default:
return V_70 ;
}
}
static void F_51 ( struct V_16 * V_17 ,
struct V_57 * V_64 ,
T_1 V_73 )
{
struct V_18 * V_74 = & V_64 -> V_75 ;
struct V_3 * V_76 = & V_17 -> V_23 . V_77 ;
F_12 ( & V_64 -> V_78 ) ;
if ( V_73 & V_79 &&
! ( V_64 -> V_73 & V_79 ) ) {
F_52 ( & V_17 -> V_23 . V_71 ) ;
F_53 ( & V_17 -> V_23 . V_80 ) ;
F_54 ( ! F_55 ( V_74 ) ) ;
F_56 ( V_74 , V_76 ) ;
F_57 ( & V_17 -> V_23 . V_80 ) ;
} else if ( ! ( V_73 & V_79 ) &&
V_64 -> V_73 & V_79 ) {
F_58 ( & V_17 -> V_23 . V_71 ) ;
F_53 ( & V_17 -> V_23 . V_80 ) ;
F_54 ( F_55 ( V_74 ) ) ;
F_59 ( V_74 ) ;
F_57 ( & V_17 -> V_23 . V_80 ) ;
}
}
static void F_60 ( struct V_16 * V_17 ,
struct V_57 * V_64 ,
T_1 V_73 )
{
struct V_18 * V_74 = & V_64 -> V_81 ;
struct V_3 * V_76 = & V_17 -> V_23 . V_82 ;
F_12 ( & V_64 -> V_78 ) ;
if ( V_73 & V_83 &&
! ( V_64 -> V_73 & V_83 ) ) {
F_52 ( & V_17 -> V_23 . V_55 ) ;
F_53 ( & V_17 -> V_23 . V_80 ) ;
F_54 ( ! F_55 ( V_74 ) ) ;
F_56 ( V_74 , V_76 ) ;
F_57 ( & V_17 -> V_23 . V_80 ) ;
} else if ( ! ( V_73 & V_83 ) &&
V_64 -> V_73 & V_83 ) {
F_58 ( & V_17 -> V_23 . V_55 ) ;
F_53 ( & V_17 -> V_23 . V_80 ) ;
F_54 ( F_55 ( V_74 ) ) ;
F_59 ( V_74 ) ;
F_57 ( & V_17 -> V_23 . V_80 ) ;
}
}
static void F_61 ( struct V_16 * V_17 ,
struct V_57 * V_64 ,
T_1 V_73 )
{
struct V_18 * V_74 = & V_64 -> V_84 ;
struct V_3 * V_76 = & V_17 -> V_23 . V_85 ;
F_12 ( & V_64 -> V_78 ) ;
if ( V_73 & V_86 &&
! ( V_64 -> V_73 & V_86 ) ) {
F_52 ( & V_17 -> V_23 . V_56 ) ;
F_53 ( & V_17 -> V_23 . V_80 ) ;
F_54 ( ! F_55 ( V_74 ) ) ;
F_56 ( V_74 , V_76 ) ;
F_57 ( & V_17 -> V_23 . V_80 ) ;
} else if ( ! ( V_73 & V_86 ) &&
V_64 -> V_73 & V_86 ) {
F_58 ( & V_17 -> V_23 . V_56 ) ;
F_53 ( & V_17 -> V_23 . V_80 ) ;
F_54 ( F_55 ( V_74 ) ) ;
F_59 ( V_74 ) ;
F_57 ( & V_17 -> V_23 . V_80 ) ;
}
}
static void F_62 ( struct V_16 * V_17 ,
struct V_57 * V_64 ,
T_1 V_33 ,
void * V_87 ,
T_2 V_88 )
{
bool V_89 = ! ( V_33 & V_90 ) ;
T_1 V_73 = V_22 ;
bool V_91 ;
if ( V_89 && V_87 &&
( V_88 >= sizeof( V_73 ) ) )
V_73 = * ( T_1 * ) V_87 ;
F_53 ( & V_64 -> V_78 ) ;
V_91 = F_63 ( V_92 ,
& V_64 -> V_93 ) ;
if ( V_89 &&
! F_63 ( V_92 , & V_64 -> V_94 ) ) {
if ( V_91 )
F_58 ( & V_17 -> V_23 . V_51 ) ;
F_64 ( V_92 , & V_64 -> V_94 ) ;
} else if ( ! V_89 &&
( F_63 ( V_92 , & V_64 -> V_94 ) ||
! V_91 ) ) {
F_52 ( & V_17 -> V_23 . V_51 ) ;
F_65 ( V_92 , & V_64 -> V_94 ) ;
}
F_64 ( V_92 , & V_64 -> V_93 ) ;
F_51 ( V_17 , V_64 , V_73 ) ;
F_60 ( V_17 , V_64 , V_73 ) ;
F_61 ( V_17 , V_64 , V_73 ) ;
V_64 -> V_73 = V_73 ;
F_57 ( & V_64 -> V_78 ) ;
}
void F_66 ( struct V_16 * V_17 )
{
F_67 ( V_17 , F_62 ,
NULL , V_36 , 1 ,
V_90 ) ;
}
void F_68 ( struct V_16 * V_17 )
{
F_25 ( V_17 , V_36 , 1 ) ;
F_69 ( V_17 , V_36 , 1 ) ;
F_16 ( V_17 , NULL ) ;
}
void F_70 ( struct V_57 * V_64 )
{
struct V_16 * V_17 = V_64 -> V_17 ;
F_53 ( & V_64 -> V_78 ) ;
if ( ! F_63 ( V_92 , & V_64 -> V_94 ) &&
F_63 ( V_92 , & V_64 -> V_93 ) )
F_58 ( & V_17 -> V_23 . V_51 ) ;
F_51 ( V_17 , V_64 , V_22 ) ;
F_60 ( V_17 , V_64 , V_22 ) ;
F_61 ( V_17 , V_64 , V_22 ) ;
F_57 ( & V_64 -> V_78 ) ;
}

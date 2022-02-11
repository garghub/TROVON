int F_1 ( const struct V_1 * V_2 , const void * V_3 )
{
const void * V_4 = F_2 ( V_2 , struct V_5 ,
V_6 ) ;
return F_3 ( V_4 , V_3 ) ;
}
struct V_7 *
F_4 ( struct V_5 * V_8 ,
unsigned short V_9 )
{
struct V_7 * V_10 = NULL , * V_11 ;
F_5 () ;
F_6 (tmp, &orig_node->vlan_list, list) {
if ( V_11 -> V_9 != V_9 )
continue;
if ( ! F_7 ( & V_11 -> V_12 ) )
continue;
V_10 = V_11 ;
break;
}
F_8 () ;
return V_10 ;
}
struct V_7 *
F_9 ( struct V_5 * V_8 ,
unsigned short V_9 )
{
struct V_7 * V_10 ;
F_10 ( & V_8 -> V_13 ) ;
V_10 = F_4 ( V_8 , V_9 ) ;
if ( V_10 )
goto V_14;
V_10 = F_11 ( sizeof( * V_10 ) , V_15 ) ;
if ( ! V_10 )
goto V_14;
F_12 ( & V_10 -> V_12 , 2 ) ;
V_10 -> V_9 = V_9 ;
F_13 ( & V_10 -> V_16 , & V_8 -> V_17 ) ;
V_14:
F_14 ( & V_8 -> V_13 ) ;
return V_10 ;
}
void F_15 ( struct V_7 * V_18 )
{
if ( F_16 ( & V_18 -> V_12 ) )
F_17 ( V_18 , V_19 ) ;
}
int F_18 ( struct V_20 * V_21 )
{
if ( V_21 -> V_22 )
return 0 ;
V_21 -> V_22 = F_19 ( 1024 ) ;
if ( ! V_21 -> V_22 )
goto V_23;
F_20 ( V_21 -> V_22 ,
& V_24 ) ;
F_21 ( & V_21 -> V_25 , V_26 ) ;
F_22 ( V_27 ,
& V_21 -> V_25 ,
F_23 ( V_28 ) ) ;
return 0 ;
V_23:
return - V_29 ;
}
static void
F_24 ( struct V_30 * V_31 )
{
if ( V_31 -> V_32 != V_33 )
F_25 ( V_31 -> V_32 ) ;
F_17 ( V_31 , V_19 ) ;
}
void F_26 ( struct V_30 * V_31 )
{
if ( F_16 ( & V_31 -> V_12 ) )
F_24 ( V_31 ) ;
}
static void
F_27 ( struct V_34 * V_35 )
{
F_10 ( & V_35 -> V_36 -> V_37 ) ;
F_28 ( & V_35 -> V_16 ) ;
F_14 ( & V_35 -> V_36 -> V_37 ) ;
F_25 ( V_35 -> V_36 ) ;
F_17 ( V_35 , V_19 ) ;
}
void F_29 ( struct V_34 * V_35 )
{
if ( F_16 ( & V_35 -> V_12 ) )
F_27 ( V_35 ) ;
}
static void F_30 ( struct V_38 * V_39 )
{
struct V_1 * V_40 ;
struct V_34 * V_35 ;
struct V_30 * V_31 ;
struct V_41 * V_42 ;
V_42 = V_39 -> V_8 -> V_21 -> V_43 ;
F_31 (neigh_ifinfo, node_tmp,
&neigh_node->ifinfo_list, list) {
F_26 ( V_31 ) ;
}
V_35 = F_32 ( V_39 -> V_36 ,
V_39 -> V_44 ) ;
if ( V_35 ) {
F_29 ( V_35 ) ;
F_29 ( V_35 ) ;
}
if ( V_42 -> V_45 )
V_42 -> V_45 ( V_39 ) ;
F_25 ( V_39 -> V_36 ) ;
F_17 ( V_39 , V_19 ) ;
}
void F_33 ( struct V_38 * V_39 )
{
if ( F_16 ( & V_39 -> V_12 ) )
F_30 ( V_39 ) ;
}
struct V_38 *
F_34 ( struct V_5 * V_8 ,
const struct V_46 * V_32 )
{
struct V_47 * V_48 ;
struct V_38 * V_49 = NULL ;
F_5 () ;
F_6 (orig_ifinfo, &orig_node->ifinfo_list, list) {
if ( V_48 -> V_32 != V_32 )
continue;
V_49 = F_35 ( V_48 -> V_49 ) ;
break;
}
if ( V_49 && ! F_7 ( & V_49 -> V_12 ) )
V_49 = NULL ;
F_8 () ;
return V_49 ;
}
struct V_47 *
F_36 ( struct V_5 * V_8 ,
struct V_46 * V_32 )
{
struct V_47 * V_11 , * V_48 = NULL ;
F_5 () ;
F_6 (tmp, &orig_node->ifinfo_list,
list) {
if ( V_11 -> V_32 != V_32 )
continue;
if ( ! F_7 ( & V_11 -> V_12 ) )
continue;
V_48 = V_11 ;
break;
}
F_8 () ;
return V_48 ;
}
struct V_47 *
F_37 ( struct V_5 * V_8 ,
struct V_46 * V_32 )
{
struct V_47 * V_48 = NULL ;
unsigned long V_50 ;
F_10 ( & V_8 -> V_37 ) ;
V_48 = F_36 ( V_8 , V_32 ) ;
if ( V_48 )
goto V_14;
V_48 = F_11 ( sizeof( * V_48 ) , V_15 ) ;
if ( ! V_48 )
goto V_14;
if ( V_32 != V_33 &&
! F_7 ( & V_32 -> V_12 ) ) {
F_38 ( V_48 ) ;
V_48 = NULL ;
goto V_14;
}
V_50 = V_51 - 1 ;
V_50 -= F_23 ( V_52 ) ;
V_48 -> V_53 = V_50 ;
V_48 -> V_32 = V_32 ;
F_39 ( & V_48 -> V_16 ) ;
F_12 ( & V_48 -> V_12 , 2 ) ;
F_13 ( & V_48 -> V_16 ,
& V_8 -> V_54 ) ;
V_14:
F_14 ( & V_8 -> V_37 ) ;
return V_48 ;
}
struct V_30 *
F_40 ( struct V_38 * V_55 ,
struct V_46 * V_32 )
{
struct V_30 * V_31 = NULL ,
* V_56 ;
F_5 () ;
F_6 (tmp_neigh_ifinfo, &neigh->ifinfo_list,
list) {
if ( V_56 -> V_32 != V_32 )
continue;
if ( ! F_7 ( & V_56 -> V_12 ) )
continue;
V_31 = V_56 ;
break;
}
F_8 () ;
return V_31 ;
}
struct V_30 *
F_41 ( struct V_38 * V_55 ,
struct V_46 * V_32 )
{
struct V_30 * V_31 ;
F_10 ( & V_55 -> V_57 ) ;
V_31 = F_40 ( V_55 , V_32 ) ;
if ( V_31 )
goto V_14;
V_31 = F_11 ( sizeof( * V_31 ) , V_15 ) ;
if ( ! V_31 )
goto V_14;
if ( V_32 && ! F_7 ( & V_32 -> V_12 ) ) {
F_38 ( V_31 ) ;
V_31 = NULL ;
goto V_14;
}
F_39 ( & V_31 -> V_16 ) ;
F_12 ( & V_31 -> V_12 , 2 ) ;
V_31 -> V_32 = V_32 ;
F_13 ( & V_31 -> V_16 , & V_55 -> V_54 ) ;
V_14:
F_14 ( & V_55 -> V_57 ) ;
return V_31 ;
}
static struct V_38 *
F_42 ( const struct V_5 * V_8 ,
const struct V_46 * V_58 ,
const T_1 * V_44 )
{
struct V_38 * V_59 , * V_60 = NULL ;
F_5 () ;
F_6 (tmp_neigh_node, &orig_node->neigh_list, list) {
if ( ! F_3 ( V_59 -> V_44 , V_44 ) )
continue;
if ( V_59 -> V_36 != V_58 )
continue;
if ( ! F_7 ( & V_59 -> V_12 ) )
continue;
V_60 = V_59 ;
break;
}
F_8 () ;
return V_60 ;
}
static struct V_34 *
F_43 ( struct V_46 * V_58 ,
const T_1 * V_61 )
{
struct V_20 * V_21 = F_44 ( V_58 -> V_62 ) ;
struct V_34 * V_35 = NULL ;
F_10 ( & V_58 -> V_37 ) ;
V_35 = F_32 ( V_58 , V_61 ) ;
if ( V_35 )
goto V_14;
if ( ! F_7 ( & V_58 -> V_12 ) )
goto V_14;
V_35 = F_11 ( sizeof( * V_35 ) , V_15 ) ;
if ( ! V_35 ) {
F_25 ( V_58 ) ;
goto V_14;
}
F_39 ( & V_35 -> V_16 ) ;
F_45 ( V_35 -> V_44 , V_61 ) ;
V_35 -> V_36 = V_58 ;
V_35 -> V_63 = V_51 ;
F_12 ( & V_35 -> V_12 , 1 ) ;
if ( V_21 -> V_43 -> V_64 )
V_21 -> V_43 -> V_64 ( V_35 ) ;
F_46 ( & V_35 -> V_16 , & V_58 -> V_65 ) ;
V_14:
F_14 ( & V_58 -> V_37 ) ;
return V_35 ;
}
static struct V_34 *
F_47 ( struct V_46 * V_58 ,
const T_1 * V_61 )
{
struct V_34 * V_35 = NULL ;
V_35 = F_32 ( V_58 , V_61 ) ;
if ( V_35 )
return V_35 ;
return F_43 ( V_58 , V_61 ) ;
}
struct V_34 *
F_32 ( const struct V_46 * V_58 ,
const T_1 * V_61 )
{
struct V_34 * V_66 , * V_35 = NULL ;
F_5 () ;
F_6 (tmp_hardif_neigh,
&hard_iface->neigh_list, list) {
if ( ! F_3 ( V_66 -> V_44 , V_61 ) )
continue;
if ( ! F_7 ( & V_66 -> V_12 ) )
continue;
V_35 = V_66 ;
break;
}
F_8 () ;
return V_35 ;
}
struct V_38 *
F_48 ( struct V_5 * V_8 ,
struct V_46 * V_58 ,
const T_1 * V_61 )
{
struct V_38 * V_39 ;
struct V_34 * V_35 = NULL ;
V_39 = F_42 ( V_8 , V_58 , V_61 ) ;
if ( V_39 )
goto V_14;
V_35 = F_47 ( V_58 ,
V_61 ) ;
if ( ! V_35 )
goto V_14;
V_39 = F_11 ( sizeof( * V_39 ) , V_15 ) ;
if ( ! V_39 )
goto V_14;
if ( ! F_7 ( & V_58 -> V_12 ) ) {
F_38 ( V_39 ) ;
V_39 = NULL ;
goto V_14;
}
F_39 ( & V_39 -> V_16 ) ;
F_49 ( & V_39 -> V_54 ) ;
F_50 ( & V_39 -> V_57 ) ;
F_45 ( V_39 -> V_44 , V_61 ) ;
V_39 -> V_36 = V_58 ;
V_39 -> V_8 = V_8 ;
F_12 ( & V_39 -> V_12 , 2 ) ;
F_10 ( & V_8 -> V_37 ) ;
F_13 ( & V_39 -> V_16 , & V_8 -> V_65 ) ;
F_14 ( & V_8 -> V_37 ) ;
F_51 ( & V_35 -> V_12 ) ;
F_52 ( V_67 , V_8 -> V_21 ,
L_1 ,
V_61 , V_8 -> V_68 , V_58 -> V_69 -> V_70 ) ;
V_14:
if ( V_35 )
F_29 ( V_35 ) ;
return V_39 ;
}
int F_53 ( struct V_71 * V_72 , void * V_73 )
{
struct V_74 * V_69 = (struct V_74 * ) V_72 -> V_75 ;
struct V_20 * V_21 = F_44 ( V_69 ) ;
struct V_46 * V_76 ;
V_76 = F_54 ( V_72 ) ;
if ( ! V_76 )
return 0 ;
F_55 ( V_72 , L_2 ,
V_77 , V_76 -> V_69 -> V_70 ,
V_76 -> V_69 -> V_78 , V_69 -> V_70 ,
V_21 -> V_43 -> V_70 ) ;
F_25 ( V_76 ) ;
if ( ! V_21 -> V_43 -> V_79 ) {
F_56 ( V_72 ,
L_3 ) ;
return 0 ;
}
V_21 -> V_43 -> V_79 ( V_21 , V_72 ) ;
return 0 ;
}
static void F_57 ( struct V_47 * V_48 )
{
struct V_38 * V_49 ;
if ( V_48 -> V_32 != V_33 )
F_25 ( V_48 -> V_32 ) ;
V_49 = F_58 ( V_48 -> V_49 , true ) ;
if ( V_49 )
F_33 ( V_49 ) ;
F_17 ( V_48 , V_19 ) ;
}
void F_59 ( struct V_47 * V_48 )
{
if ( F_16 ( & V_48 -> V_12 ) )
F_57 ( V_48 ) ;
}
static void F_60 ( struct V_80 * V_19 )
{
struct V_5 * V_8 ;
V_8 = F_2 ( V_19 , struct V_5 , V_19 ) ;
F_61 ( V_8 ) ;
F_62 ( V_8 , NULL ) ;
if ( V_8 -> V_21 -> V_43 -> V_81 )
V_8 -> V_21 -> V_43 -> V_81 ( V_8 ) ;
F_38 ( V_8 -> V_82 ) ;
F_38 ( V_8 ) ;
}
static void F_63 ( struct V_5 * V_8 )
{
struct V_1 * V_40 ;
struct V_38 * V_39 ;
struct V_47 * V_48 ;
F_10 ( & V_8 -> V_37 ) ;
F_31 (neigh_node, node_tmp,
&orig_node->neigh_list, list) {
F_64 ( & V_39 -> V_16 ) ;
F_33 ( V_39 ) ;
}
F_31 (orig_ifinfo, node_tmp,
&orig_node->ifinfo_list, list) {
F_64 ( & V_48 -> V_16 ) ;
F_59 ( V_48 ) ;
}
F_14 ( & V_8 -> V_37 ) ;
F_65 ( V_8 -> V_21 , V_8 , NULL ) ;
F_66 ( & V_8 -> V_19 , F_60 ) ;
}
void F_67 ( struct V_5 * V_8 )
{
if ( F_16 ( & V_8 -> V_12 ) )
F_63 ( V_8 ) ;
}
void F_68 ( struct V_20 * V_21 )
{
struct V_83 * V_84 = V_21 -> V_22 ;
struct V_1 * V_40 ;
struct V_85 * V_86 ;
T_2 * V_87 ;
struct V_5 * V_8 ;
T_3 V_88 ;
if ( ! V_84 )
return;
F_69 ( & V_21 -> V_25 ) ;
V_21 -> V_22 = NULL ;
for ( V_88 = 0 ; V_88 < V_84 -> V_89 ; V_88 ++ ) {
V_86 = & V_84 -> V_90 [ V_88 ] ;
V_87 = & V_84 -> V_91 [ V_88 ] ;
F_10 ( V_87 ) ;
F_31 (orig_node, node_tmp,
head, hash_entry) {
F_64 ( & V_8 -> V_6 ) ;
F_67 ( V_8 ) ;
}
F_14 ( V_87 ) ;
}
F_70 ( V_84 ) ;
}
struct V_5 * F_71 ( struct V_20 * V_21 ,
const T_1 * V_44 )
{
struct V_5 * V_8 ;
struct V_7 * V_10 ;
unsigned long V_50 ;
int V_88 ;
F_52 ( V_67 , V_21 ,
L_4 , V_44 ) ;
V_8 = F_11 ( sizeof( * V_8 ) , V_15 ) ;
if ( ! V_8 )
return NULL ;
F_49 ( & V_8 -> V_65 ) ;
F_49 ( & V_8 -> V_17 ) ;
F_49 ( & V_8 -> V_54 ) ;
F_50 ( & V_8 -> V_92 ) ;
F_50 ( & V_8 -> V_37 ) ;
F_50 ( & V_8 -> V_93 ) ;
F_50 ( & V_8 -> V_94 ) ;
F_50 ( & V_8 -> V_13 ) ;
F_72 ( V_8 ) ;
F_12 ( & V_8 -> V_12 , 2 ) ;
V_8 -> V_21 = V_21 ;
F_45 ( V_8 -> V_68 , V_44 ) ;
F_73 ( V_8 ) ;
F_12 ( & V_8 -> V_95 , 0 ) ;
V_8 -> V_82 = NULL ;
V_8 -> V_96 = 0 ;
V_8 -> V_63 = V_51 ;
V_50 = V_51 - 1 - F_23 ( V_52 ) ;
V_8 -> V_97 = V_50 ;
#ifdef F_74
V_8 -> V_98 = V_99 ;
F_39 ( & V_8 -> V_100 ) ;
F_39 ( & V_8 -> V_101 ) ;
F_39 ( & V_8 -> V_102 ) ;
F_50 ( & V_8 -> V_103 ) ;
#endif
V_10 = F_9 ( V_8 , V_99 ) ;
if ( ! V_10 )
goto V_104;
F_15 ( V_10 ) ;
for ( V_88 = 0 ; V_88 < V_105 ; V_88 ++ ) {
F_49 ( & V_8 -> V_106 [ V_88 ] . V_86 ) ;
F_50 ( & V_8 -> V_106 [ V_88 ] . V_107 ) ;
V_8 -> V_106 [ V_88 ] . V_89 = 0 ;
}
return V_8 ;
V_104:
F_38 ( V_8 ) ;
return NULL ;
}
static void
F_75 ( struct V_20 * V_21 ,
struct V_38 * V_55 )
{
struct V_30 * V_31 ;
struct V_46 * V_32 ;
struct V_1 * V_40 ;
F_10 ( & V_55 -> V_57 ) ;
F_31 (neigh_ifinfo, node_tmp,
&neigh->ifinfo_list, list) {
V_32 = V_31 -> V_32 ;
if ( V_32 == V_33 )
continue;
if ( ( V_32 -> V_108 != V_109 ) &&
( V_32 -> V_108 != V_110 ) &&
( V_32 -> V_108 != V_111 ) )
continue;
F_52 ( V_67 , V_21 ,
L_5 ,
V_55 -> V_44 , V_32 -> V_69 -> V_70 ) ;
F_64 ( & V_31 -> V_16 ) ;
F_26 ( V_31 ) ;
}
F_14 ( & V_55 -> V_57 ) ;
}
static bool
F_76 ( struct V_20 * V_21 ,
struct V_5 * V_8 )
{
struct V_47 * V_48 ;
struct V_46 * V_32 ;
struct V_1 * V_40 ;
bool V_112 = false ;
F_10 ( & V_8 -> V_37 ) ;
F_31 (orig_ifinfo, node_tmp,
&orig_node->ifinfo_list, list) {
V_32 = V_48 -> V_32 ;
if ( V_32 == V_33 )
continue;
if ( ( V_32 -> V_108 != V_109 ) &&
( V_32 -> V_108 != V_110 ) &&
( V_32 -> V_108 != V_111 ) )
continue;
F_52 ( V_67 , V_21 ,
L_6 ,
V_8 -> V_68 , V_32 -> V_69 -> V_70 ) ;
V_112 = true ;
F_64 ( & V_48 -> V_16 ) ;
F_59 ( V_48 ) ;
if ( V_8 -> V_113 == V_48 ) {
V_8 -> V_113 = NULL ;
F_59 ( V_48 ) ;
}
}
F_14 ( & V_8 -> V_37 ) ;
return V_112 ;
}
static bool
F_77 ( struct V_20 * V_21 ,
struct V_5 * V_8 )
{
struct V_1 * V_40 ;
struct V_38 * V_39 ;
bool V_114 = false ;
unsigned long V_63 ;
struct V_46 * V_36 ;
F_10 ( & V_8 -> V_37 ) ;
F_31 (neigh_node, node_tmp,
&orig_node->neigh_list, list) {
V_63 = V_39 -> V_63 ;
V_36 = V_39 -> V_36 ;
if ( ( F_78 ( V_63 , V_115 ) ) ||
( V_36 -> V_108 == V_109 ) ||
( V_36 -> V_108 == V_110 ) ||
( V_36 -> V_108 == V_111 ) ) {
if ( ( V_36 -> V_108 == V_109 ) ||
( V_36 -> V_108 == V_110 ) ||
( V_36 -> V_108 == V_111 ) )
F_52 ( V_67 , V_21 ,
L_7 ,
V_8 -> V_68 , V_39 -> V_44 ,
V_36 -> V_69 -> V_70 ) ;
else
F_52 ( V_67 , V_21 ,
L_8 ,
V_8 -> V_68 , V_39 -> V_44 ,
F_79 ( V_63 ) ) ;
V_114 = true ;
F_64 ( & V_39 -> V_16 ) ;
F_33 ( V_39 ) ;
} else {
F_75 ( V_21 , V_39 ) ;
}
}
F_14 ( & V_8 -> V_37 ) ;
return V_114 ;
}
static struct V_38 *
F_80 ( struct V_20 * V_21 ,
struct V_5 * V_8 ,
struct V_46 * V_32 )
{
struct V_38 * V_116 = NULL , * V_55 ;
struct V_41 * V_42 = V_21 -> V_43 ;
F_5 () ;
F_6 (neigh, &orig_node->neigh_list, list) {
if ( V_116 && ( V_42 -> V_117 ( V_55 , V_32 ,
V_116 , V_32 ) <= 0 ) )
continue;
if ( ! F_7 ( & V_55 -> V_12 ) )
continue;
if ( V_116 )
F_33 ( V_116 ) ;
V_116 = V_55 ;
}
F_8 () ;
return V_116 ;
}
static bool F_81 ( struct V_20 * V_21 ,
struct V_5 * V_8 )
{
struct V_38 * V_118 ;
struct V_46 * V_58 ;
bool V_119 , V_120 ;
if ( F_78 ( V_8 -> V_63 ,
2 * V_115 ) ) {
F_52 ( V_67 , V_21 ,
L_9 ,
V_8 -> V_68 ,
F_79 ( V_8 -> V_63 ) ) ;
return true ;
}
V_119 = F_76 ( V_21 , V_8 ) ;
V_120 = F_77 ( V_21 , V_8 ) ;
if ( ! V_119 && ! V_120 )
return false ;
V_118 = F_80 ( V_21 , V_8 ,
V_33 ) ;
F_82 ( V_21 , V_8 , V_33 ,
V_118 ) ;
if ( V_118 )
F_33 ( V_118 ) ;
F_5 () ;
F_83 (hard_iface, &batadv_hardif_list, list) {
if ( V_58 -> V_108 != V_121 )
continue;
if ( V_58 -> V_62 != V_21 -> V_62 )
continue;
V_118 = F_80 ( V_21 ,
V_8 ,
V_58 ) ;
F_82 ( V_21 , V_8 , V_58 ,
V_118 ) ;
if ( V_118 )
F_33 ( V_118 ) ;
}
F_8 () ;
return false ;
}
static void F_84 ( struct V_20 * V_21 )
{
struct V_83 * V_84 = V_21 -> V_22 ;
struct V_1 * V_40 ;
struct V_85 * V_86 ;
T_2 * V_87 ;
struct V_5 * V_8 ;
T_3 V_88 ;
if ( ! V_84 )
return;
for ( V_88 = 0 ; V_88 < V_84 -> V_89 ; V_88 ++ ) {
V_86 = & V_84 -> V_90 [ V_88 ] ;
V_87 = & V_84 -> V_91 [ V_88 ] ;
F_10 ( V_87 ) ;
F_31 (orig_node, node_tmp,
head, hash_entry) {
if ( F_81 ( V_21 , V_8 ) ) {
F_85 ( V_21 , V_8 ) ;
F_64 ( & V_8 -> V_6 ) ;
F_86 ( V_8 -> V_21 ,
V_8 , - 1 ,
L_10 ) ;
F_67 ( V_8 ) ;
continue;
}
F_62 ( V_8 ,
V_122 ) ;
}
F_14 ( V_87 ) ;
}
F_87 ( V_21 ) ;
}
static void V_26 ( struct V_123 * V_124 )
{
struct V_125 * V_125 ;
struct V_20 * V_21 ;
V_125 = F_2 ( V_124 , struct V_125 , V_124 ) ;
V_21 = F_2 ( V_125 , struct V_20 , V_25 ) ;
F_84 ( V_21 ) ;
F_22 ( V_27 ,
& V_21 -> V_25 ,
F_23 ( V_28 ) ) ;
}
void F_88 ( struct V_20 * V_21 )
{
F_84 ( V_21 ) ;
}
int F_89 ( struct V_71 * V_72 , void * V_73 )
{
struct V_74 * V_69 = (struct V_74 * ) V_72 -> V_75 ;
struct V_20 * V_21 = F_44 ( V_69 ) ;
struct V_46 * V_76 ;
V_76 = F_54 ( V_72 ) ;
if ( ! V_76 )
return 0 ;
F_55 ( V_72 , L_2 ,
V_77 , V_76 -> V_69 -> V_70 ,
V_76 -> V_69 -> V_78 , V_69 -> V_70 ,
V_21 -> V_43 -> V_70 ) ;
F_25 ( V_76 ) ;
if ( ! V_21 -> V_43 -> V_126 ) {
F_56 ( V_72 ,
L_3 ) ;
return 0 ;
}
V_21 -> V_43 -> V_126 ( V_21 , V_72 ,
V_33 ) ;
return 0 ;
}
int F_90 ( struct V_71 * V_72 , void * V_73 )
{
struct V_74 * V_69 = (struct V_74 * ) V_72 -> V_75 ;
struct V_46 * V_58 ;
struct V_20 * V_21 ;
V_58 = F_91 ( V_69 ) ;
if ( ! V_58 || ! V_58 -> V_62 ) {
F_56 ( V_72 , L_11 ) ;
goto V_14;
}
V_21 = F_44 ( V_58 -> V_62 ) ;
if ( ! V_21 -> V_43 -> V_126 ) {
F_56 ( V_72 ,
L_3 ) ;
goto V_14;
}
if ( V_58 -> V_108 != V_121 ) {
F_56 ( V_72 , L_12 ) ;
goto V_14;
}
F_55 ( V_72 , L_13 ,
V_77 , V_58 -> V_69 -> V_70 ,
V_58 -> V_69 -> V_78 ,
V_58 -> V_62 -> V_70 , V_21 -> V_43 -> V_70 ) ;
V_21 -> V_43 -> V_126 ( V_21 , V_72 , V_58 ) ;
V_14:
if ( V_58 )
F_25 ( V_58 ) ;
return 0 ;
}
int F_92 ( struct V_46 * V_58 ,
int V_127 )
{
struct V_20 * V_21 = F_44 ( V_58 -> V_62 ) ;
struct V_41 * V_42 = V_21 -> V_43 ;
struct V_83 * V_84 = V_21 -> V_22 ;
struct V_85 * V_86 ;
struct V_5 * V_8 ;
T_3 V_88 ;
int V_128 ;
for ( V_88 = 0 ; V_88 < V_84 -> V_89 ; V_88 ++ ) {
V_86 = & V_84 -> V_90 [ V_88 ] ;
F_5 () ;
F_6 (orig_node, head, hash_entry) {
V_128 = 0 ;
if ( V_42 -> V_129 )
V_128 = V_42 -> V_129 ( V_8 ,
V_127 ) ;
if ( V_128 == - V_29 )
goto V_23;
}
F_8 () ;
}
return 0 ;
V_23:
F_8 () ;
return - V_29 ;
}
int F_93 ( struct V_46 * V_58 ,
int V_127 )
{
struct V_20 * V_21 = F_44 ( V_58 -> V_62 ) ;
struct V_83 * V_84 = V_21 -> V_22 ;
struct V_85 * V_86 ;
struct V_46 * V_130 ;
struct V_5 * V_8 ;
struct V_41 * V_42 = V_21 -> V_43 ;
T_3 V_88 ;
int V_128 ;
for ( V_88 = 0 ; V_88 < V_84 -> V_89 ; V_88 ++ ) {
V_86 = & V_84 -> V_90 [ V_88 ] ;
F_5 () ;
F_6 (orig_node, head, hash_entry) {
V_128 = 0 ;
if ( V_42 -> V_131 )
V_128 = V_42 -> V_131 ( V_8 ,
V_127 ,
V_58 -> V_132 ) ;
if ( V_128 == - V_29 )
goto V_23;
}
F_8 () ;
}
F_5 () ;
F_83 (hard_iface_tmp, &batadv_hardif_list, list) {
if ( V_130 -> V_108 == V_110 )
continue;
if ( V_58 == V_130 )
continue;
if ( V_58 -> V_62 != V_130 -> V_62 )
continue;
if ( V_130 -> V_132 > V_58 -> V_132 )
V_130 -> V_132 -- ;
}
F_8 () ;
V_58 -> V_132 = - 1 ;
return 0 ;
V_23:
F_8 () ;
return - V_29 ;
}

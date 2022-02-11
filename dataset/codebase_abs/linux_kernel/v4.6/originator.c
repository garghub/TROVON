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
F_12 ( & V_10 -> V_12 ) ;
F_13 ( & V_10 -> V_12 ) ;
V_10 -> V_9 = V_9 ;
F_14 ( & V_10 -> V_16 , & V_8 -> V_17 ) ;
V_14:
F_15 ( & V_8 -> V_13 ) ;
return V_10 ;
}
static void F_16 ( struct V_18 * V_19 )
{
struct V_7 * V_20 ;
V_20 = F_2 ( V_19 , struct V_7 , V_12 ) ;
F_17 ( V_20 , V_21 ) ;
}
void F_18 ( struct V_7 * V_20 )
{
F_19 ( & V_20 -> V_12 , F_16 ) ;
}
int F_20 ( struct V_22 * V_23 )
{
if ( V_23 -> V_24 )
return 0 ;
V_23 -> V_24 = F_21 ( 1024 ) ;
if ( ! V_23 -> V_24 )
goto V_25;
F_22 ( V_23 -> V_24 ,
& V_26 ) ;
F_23 ( & V_23 -> V_27 , V_28 ) ;
F_24 ( V_29 ,
& V_23 -> V_27 ,
F_25 ( V_30 ) ) ;
return 0 ;
V_25:
return - V_31 ;
}
static void F_26 ( struct V_18 * V_19 )
{
struct V_32 * V_33 ;
V_33 = F_2 ( V_19 , struct V_32 , V_12 ) ;
if ( V_33 -> V_34 != V_35 )
F_27 ( V_33 -> V_34 ) ;
F_17 ( V_33 , V_21 ) ;
}
void F_28 ( struct V_32 * V_33 )
{
F_19 ( & V_33 -> V_12 , F_26 ) ;
}
static void F_29 ( struct V_18 * V_19 )
{
struct V_36 * V_37 ;
V_37 = F_2 ( V_19 , struct V_36 ,
V_12 ) ;
F_10 ( & V_37 -> V_38 -> V_39 ) ;
F_30 ( & V_37 -> V_16 ) ;
F_15 ( & V_37 -> V_38 -> V_39 ) ;
F_27 ( V_37 -> V_38 ) ;
F_17 ( V_37 , V_21 ) ;
}
void F_31 ( struct V_36 * V_37 )
{
F_19 ( & V_37 -> V_12 , F_29 ) ;
}
static void F_32 ( struct V_18 * V_19 )
{
struct V_1 * V_40 ;
struct V_41 * V_42 ;
struct V_32 * V_33 ;
struct V_43 * V_44 ;
V_42 = F_2 ( V_19 , struct V_41 , V_12 ) ;
V_44 = V_42 -> V_8 -> V_23 -> V_45 ;
F_33 (neigh_ifinfo, node_tmp,
&neigh_node->ifinfo_list, list) {
F_28 ( V_33 ) ;
}
F_31 ( V_42 -> V_37 ) ;
if ( V_44 -> V_46 )
V_44 -> V_46 ( V_42 ) ;
F_27 ( V_42 -> V_38 ) ;
F_17 ( V_42 , V_21 ) ;
}
void F_34 ( struct V_41 * V_42 )
{
F_19 ( & V_42 -> V_12 , F_32 ) ;
}
struct V_41 *
F_35 ( struct V_5 * V_8 ,
const struct V_47 * V_34 )
{
struct V_48 * V_49 ;
struct V_41 * V_50 = NULL ;
F_5 () ;
F_6 (orig_ifinfo, &orig_node->ifinfo_list, list) {
if ( V_49 -> V_34 != V_34 )
continue;
V_50 = F_36 ( V_49 -> V_50 ) ;
break;
}
if ( V_50 && ! F_7 ( & V_50 -> V_12 ) )
V_50 = NULL ;
F_8 () ;
return V_50 ;
}
struct V_48 *
F_37 ( struct V_5 * V_8 ,
struct V_47 * V_34 )
{
struct V_48 * V_11 , * V_49 = NULL ;
F_5 () ;
F_6 (tmp, &orig_node->ifinfo_list,
list) {
if ( V_11 -> V_34 != V_34 )
continue;
if ( ! F_7 ( & V_11 -> V_12 ) )
continue;
V_49 = V_11 ;
break;
}
F_8 () ;
return V_49 ;
}
struct V_48 *
F_38 ( struct V_5 * V_8 ,
struct V_47 * V_34 )
{
struct V_48 * V_49 = NULL ;
unsigned long V_51 ;
F_10 ( & V_8 -> V_39 ) ;
V_49 = F_37 ( V_8 , V_34 ) ;
if ( V_49 )
goto V_14;
V_49 = F_11 ( sizeof( * V_49 ) , V_15 ) ;
if ( ! V_49 )
goto V_14;
if ( V_34 != V_35 &&
! F_7 ( & V_34 -> V_12 ) ) {
F_39 ( V_49 ) ;
V_49 = NULL ;
goto V_14;
}
V_51 = V_52 - 1 ;
V_51 -= F_25 ( V_53 ) ;
V_49 -> V_54 = V_51 ;
V_49 -> V_34 = V_34 ;
F_40 ( & V_49 -> V_16 ) ;
F_12 ( & V_49 -> V_12 ) ;
F_13 ( & V_49 -> V_12 ) ;
F_14 ( & V_49 -> V_16 ,
& V_8 -> V_55 ) ;
V_14:
F_15 ( & V_8 -> V_39 ) ;
return V_49 ;
}
struct V_32 *
F_41 ( struct V_41 * V_56 ,
struct V_47 * V_34 )
{
struct V_32 * V_33 = NULL ,
* V_57 ;
F_5 () ;
F_6 (tmp_neigh_ifinfo, &neigh->ifinfo_list,
list) {
if ( V_57 -> V_34 != V_34 )
continue;
if ( ! F_7 ( & V_57 -> V_12 ) )
continue;
V_33 = V_57 ;
break;
}
F_8 () ;
return V_33 ;
}
struct V_32 *
F_42 ( struct V_41 * V_56 ,
struct V_47 * V_34 )
{
struct V_32 * V_33 ;
F_10 ( & V_56 -> V_58 ) ;
V_33 = F_41 ( V_56 , V_34 ) ;
if ( V_33 )
goto V_14;
V_33 = F_11 ( sizeof( * V_33 ) , V_15 ) ;
if ( ! V_33 )
goto V_14;
if ( V_34 && ! F_7 ( & V_34 -> V_12 ) ) {
F_39 ( V_33 ) ;
V_33 = NULL ;
goto V_14;
}
F_40 ( & V_33 -> V_16 ) ;
F_12 ( & V_33 -> V_12 ) ;
F_13 ( & V_33 -> V_12 ) ;
V_33 -> V_34 = V_34 ;
F_14 ( & V_33 -> V_16 , & V_56 -> V_55 ) ;
V_14:
F_15 ( & V_56 -> V_58 ) ;
return V_33 ;
}
static struct V_41 *
F_43 ( const struct V_5 * V_8 ,
const struct V_47 * V_59 ,
const T_1 * V_60 )
{
struct V_41 * V_61 , * V_62 = NULL ;
F_5 () ;
F_6 (tmp_neigh_node, &orig_node->neigh_list, list) {
if ( ! F_3 ( V_61 -> V_60 , V_60 ) )
continue;
if ( V_61 -> V_38 != V_59 )
continue;
if ( ! F_7 ( & V_61 -> V_12 ) )
continue;
V_62 = V_61 ;
break;
}
F_8 () ;
return V_62 ;
}
static struct V_36 *
F_44 ( struct V_47 * V_59 ,
const T_1 * V_63 )
{
struct V_22 * V_23 = F_45 ( V_59 -> V_64 ) ;
struct V_36 * V_37 = NULL ;
F_10 ( & V_59 -> V_39 ) ;
V_37 = F_46 ( V_59 , V_63 ) ;
if ( V_37 )
goto V_14;
if ( ! F_7 ( & V_59 -> V_12 ) )
goto V_14;
V_37 = F_11 ( sizeof( * V_37 ) , V_15 ) ;
if ( ! V_37 ) {
F_27 ( V_59 ) ;
goto V_14;
}
F_40 ( & V_37 -> V_16 ) ;
F_47 ( V_37 -> V_60 , V_63 ) ;
V_37 -> V_38 = V_59 ;
V_37 -> V_65 = V_52 ;
F_12 ( & V_37 -> V_12 ) ;
if ( V_23 -> V_45 -> V_66 )
V_23 -> V_45 -> V_66 ( V_37 ) ;
F_48 ( & V_37 -> V_16 , & V_59 -> V_67 ) ;
V_14:
F_15 ( & V_59 -> V_39 ) ;
return V_37 ;
}
static struct V_36 *
F_49 ( struct V_47 * V_59 ,
const T_1 * V_63 )
{
struct V_36 * V_37 = NULL ;
V_37 = F_46 ( V_59 , V_63 ) ;
if ( V_37 )
return V_37 ;
return F_44 ( V_59 , V_63 ) ;
}
struct V_36 *
F_46 ( const struct V_47 * V_59 ,
const T_1 * V_63 )
{
struct V_36 * V_68 , * V_37 = NULL ;
F_5 () ;
F_6 (tmp_hardif_neigh,
&hard_iface->neigh_list, list) {
if ( ! F_3 ( V_68 -> V_60 , V_63 ) )
continue;
if ( ! F_7 ( & V_68 -> V_12 ) )
continue;
V_37 = V_68 ;
break;
}
F_8 () ;
return V_37 ;
}
struct V_41 *
F_50 ( struct V_5 * V_8 ,
struct V_47 * V_59 ,
const T_1 * V_63 )
{
struct V_41 * V_42 ;
struct V_36 * V_37 = NULL ;
V_42 = F_43 ( V_8 , V_59 , V_63 ) ;
if ( V_42 )
goto V_14;
V_37 = F_49 ( V_59 ,
V_63 ) ;
if ( ! V_37 )
goto V_14;
V_42 = F_11 ( sizeof( * V_42 ) , V_15 ) ;
if ( ! V_42 )
goto V_14;
if ( ! F_7 ( & V_59 -> V_12 ) ) {
F_39 ( V_42 ) ;
V_42 = NULL ;
goto V_14;
}
F_40 ( & V_42 -> V_16 ) ;
F_51 ( & V_42 -> V_55 ) ;
F_52 ( & V_42 -> V_58 ) ;
F_47 ( V_42 -> V_60 , V_63 ) ;
V_42 -> V_38 = V_59 ;
V_42 -> V_8 = V_8 ;
V_42 -> V_65 = V_52 ;
F_13 ( & V_37 -> V_12 ) ;
V_42 -> V_37 = V_37 ;
F_12 ( & V_42 -> V_12 ) ;
F_13 ( & V_42 -> V_12 ) ;
F_10 ( & V_8 -> V_39 ) ;
F_14 ( & V_42 -> V_16 , & V_8 -> V_67 ) ;
F_15 ( & V_8 -> V_39 ) ;
F_53 ( V_69 , V_8 -> V_23 ,
L_1 ,
V_63 , V_8 -> V_70 , V_59 -> V_71 -> V_72 ) ;
V_14:
if ( V_37 )
F_31 ( V_37 ) ;
return V_42 ;
}
int F_54 ( struct V_73 * V_74 , void * V_75 )
{
struct V_76 * V_71 = (struct V_76 * ) V_74 -> V_77 ;
struct V_22 * V_23 = F_45 ( V_71 ) ;
struct V_47 * V_78 ;
V_78 = F_55 ( V_74 ) ;
if ( ! V_78 )
return 0 ;
F_56 ( V_74 , L_2 ,
V_79 , V_78 -> V_71 -> V_72 ,
V_78 -> V_71 -> V_80 , V_71 -> V_72 ,
V_23 -> V_45 -> V_72 ) ;
F_27 ( V_78 ) ;
if ( ! V_23 -> V_45 -> V_81 ) {
F_57 ( V_74 ,
L_3 ) ;
return 0 ;
}
V_23 -> V_45 -> V_81 ( V_23 , V_74 ) ;
return 0 ;
}
static void F_58 ( struct V_18 * V_19 )
{
struct V_48 * V_49 ;
struct V_41 * V_50 ;
V_49 = F_2 ( V_19 , struct V_48 , V_12 ) ;
if ( V_49 -> V_34 != V_35 )
F_27 ( V_49 -> V_34 ) ;
V_50 = F_59 ( V_49 -> V_50 , true ) ;
if ( V_50 )
F_34 ( V_50 ) ;
F_17 ( V_49 , V_21 ) ;
}
void F_60 ( struct V_48 * V_49 )
{
F_19 ( & V_49 -> V_12 , F_58 ) ;
}
static void F_61 ( struct V_82 * V_21 )
{
struct V_5 * V_8 ;
V_8 = F_2 ( V_21 , struct V_5 , V_21 ) ;
F_62 ( V_8 ) ;
F_63 ( V_8 , NULL ) ;
if ( V_8 -> V_23 -> V_45 -> V_83 )
V_8 -> V_23 -> V_45 -> V_83 ( V_8 ) ;
F_39 ( V_8 -> V_84 ) ;
F_39 ( V_8 ) ;
}
static void F_64 ( struct V_18 * V_19 )
{
struct V_1 * V_40 ;
struct V_41 * V_42 ;
struct V_5 * V_8 ;
struct V_48 * V_49 ;
V_8 = F_2 ( V_19 , struct V_5 , V_12 ) ;
F_10 ( & V_8 -> V_39 ) ;
F_33 (neigh_node, node_tmp,
&orig_node->neigh_list, list) {
F_65 ( & V_42 -> V_16 ) ;
F_34 ( V_42 ) ;
}
F_33 (orig_ifinfo, node_tmp,
&orig_node->ifinfo_list, list) {
F_65 ( & V_49 -> V_16 ) ;
F_60 ( V_49 ) ;
}
F_15 ( & V_8 -> V_39 ) ;
F_66 ( V_8 -> V_23 , V_8 , NULL ) ;
F_67 ( & V_8 -> V_21 , F_61 ) ;
}
void F_68 ( struct V_5 * V_8 )
{
F_19 ( & V_8 -> V_12 , F_64 ) ;
}
void F_69 ( struct V_22 * V_23 )
{
struct V_85 * V_86 = V_23 -> V_24 ;
struct V_1 * V_40 ;
struct V_87 * V_88 ;
T_2 * V_89 ;
struct V_5 * V_8 ;
T_3 V_90 ;
if ( ! V_86 )
return;
F_70 ( & V_23 -> V_27 ) ;
V_23 -> V_24 = NULL ;
for ( V_90 = 0 ; V_90 < V_86 -> V_91 ; V_90 ++ ) {
V_88 = & V_86 -> V_92 [ V_90 ] ;
V_89 = & V_86 -> V_93 [ V_90 ] ;
F_10 ( V_89 ) ;
F_33 (orig_node, node_tmp,
head, hash_entry) {
F_65 ( & V_8 -> V_6 ) ;
F_68 ( V_8 ) ;
}
F_15 ( V_89 ) ;
}
F_71 ( V_86 ) ;
}
struct V_5 * F_72 ( struct V_22 * V_23 ,
const T_1 * V_60 )
{
struct V_5 * V_8 ;
struct V_7 * V_10 ;
unsigned long V_51 ;
int V_90 ;
F_53 ( V_69 , V_23 ,
L_4 , V_60 ) ;
V_8 = F_11 ( sizeof( * V_8 ) , V_15 ) ;
if ( ! V_8 )
return NULL ;
F_51 ( & V_8 -> V_67 ) ;
F_51 ( & V_8 -> V_17 ) ;
F_51 ( & V_8 -> V_55 ) ;
F_52 ( & V_8 -> V_94 ) ;
F_52 ( & V_8 -> V_39 ) ;
F_52 ( & V_8 -> V_95 ) ;
F_52 ( & V_8 -> V_96 ) ;
F_52 ( & V_8 -> V_13 ) ;
F_73 ( V_8 ) ;
F_12 ( & V_8 -> V_12 ) ;
F_13 ( & V_8 -> V_12 ) ;
V_8 -> V_23 = V_23 ;
F_47 ( V_8 -> V_70 , V_60 ) ;
F_74 ( V_8 ) ;
F_75 ( & V_8 -> V_97 , 0 ) ;
V_8 -> V_84 = NULL ;
V_8 -> V_98 = 0 ;
V_8 -> V_65 = V_52 ;
V_51 = V_52 - 1 - F_25 ( V_53 ) ;
V_8 -> V_99 = V_51 ;
#ifdef F_76
V_8 -> V_100 = V_101 ;
F_40 ( & V_8 -> V_102 ) ;
F_40 ( & V_8 -> V_103 ) ;
F_40 ( & V_8 -> V_104 ) ;
F_52 ( & V_8 -> V_105 ) ;
#endif
V_10 = F_9 ( V_8 , V_101 ) ;
if ( ! V_10 )
goto V_106;
F_18 ( V_10 ) ;
for ( V_90 = 0 ; V_90 < V_107 ; V_90 ++ ) {
F_51 ( & V_8 -> V_108 [ V_90 ] . V_88 ) ;
F_52 ( & V_8 -> V_108 [ V_90 ] . V_109 ) ;
V_8 -> V_108 [ V_90 ] . V_91 = 0 ;
}
return V_8 ;
V_106:
F_39 ( V_8 ) ;
return NULL ;
}
static void
F_77 ( struct V_22 * V_23 ,
struct V_41 * V_56 )
{
struct V_32 * V_33 ;
struct V_47 * V_34 ;
struct V_1 * V_40 ;
F_10 ( & V_56 -> V_58 ) ;
F_33 (neigh_ifinfo, node_tmp,
&neigh->ifinfo_list, list) {
V_34 = V_33 -> V_34 ;
if ( V_34 == V_35 )
continue;
if ( ( V_34 -> V_110 != V_111 ) &&
( V_34 -> V_110 != V_112 ) &&
( V_34 -> V_110 != V_113 ) )
continue;
F_53 ( V_69 , V_23 ,
L_5 ,
V_56 -> V_60 , V_34 -> V_71 -> V_72 ) ;
F_65 ( & V_33 -> V_16 ) ;
F_28 ( V_33 ) ;
}
F_15 ( & V_56 -> V_58 ) ;
}
static bool
F_78 ( struct V_22 * V_23 ,
struct V_5 * V_8 )
{
struct V_48 * V_49 ;
struct V_47 * V_34 ;
struct V_1 * V_40 ;
bool V_114 = false ;
F_10 ( & V_8 -> V_39 ) ;
F_33 (orig_ifinfo, node_tmp,
&orig_node->ifinfo_list, list) {
V_34 = V_49 -> V_34 ;
if ( V_34 == V_35 )
continue;
if ( ( V_34 -> V_110 != V_111 ) &&
( V_34 -> V_110 != V_112 ) &&
( V_34 -> V_110 != V_113 ) )
continue;
F_53 ( V_69 , V_23 ,
L_6 ,
V_8 -> V_70 , V_34 -> V_71 -> V_72 ) ;
V_114 = true ;
F_65 ( & V_49 -> V_16 ) ;
F_60 ( V_49 ) ;
if ( V_8 -> V_115 == V_49 ) {
V_8 -> V_115 = NULL ;
F_60 ( V_49 ) ;
}
}
F_15 ( & V_8 -> V_39 ) ;
return V_114 ;
}
static bool
F_79 ( struct V_22 * V_23 ,
struct V_5 * V_8 )
{
struct V_1 * V_40 ;
struct V_41 * V_42 ;
bool V_116 = false ;
unsigned long V_65 ;
struct V_47 * V_38 ;
F_10 ( & V_8 -> V_39 ) ;
F_33 (neigh_node, node_tmp,
&orig_node->neigh_list, list) {
V_65 = V_42 -> V_65 ;
V_38 = V_42 -> V_38 ;
if ( ( F_80 ( V_65 , V_117 ) ) ||
( V_38 -> V_110 == V_111 ) ||
( V_38 -> V_110 == V_112 ) ||
( V_38 -> V_110 == V_113 ) ) {
if ( ( V_38 -> V_110 == V_111 ) ||
( V_38 -> V_110 == V_112 ) ||
( V_38 -> V_110 == V_113 ) )
F_53 ( V_69 , V_23 ,
L_7 ,
V_8 -> V_70 , V_42 -> V_60 ,
V_38 -> V_71 -> V_72 ) ;
else
F_53 ( V_69 , V_23 ,
L_8 ,
V_8 -> V_70 , V_42 -> V_60 ,
F_81 ( V_65 ) ) ;
V_116 = true ;
F_65 ( & V_42 -> V_16 ) ;
F_34 ( V_42 ) ;
} else {
F_77 ( V_23 , V_42 ) ;
}
}
F_15 ( & V_8 -> V_39 ) ;
return V_116 ;
}
static struct V_41 *
F_82 ( struct V_22 * V_23 ,
struct V_5 * V_8 ,
struct V_47 * V_34 )
{
struct V_41 * V_118 = NULL , * V_56 ;
struct V_43 * V_44 = V_23 -> V_45 ;
F_5 () ;
F_6 (neigh, &orig_node->neigh_list, list) {
if ( V_118 && ( V_44 -> V_119 ( V_56 , V_34 ,
V_118 , V_34 ) <= 0 ) )
continue;
if ( ! F_7 ( & V_56 -> V_12 ) )
continue;
if ( V_118 )
F_34 ( V_118 ) ;
V_118 = V_56 ;
}
F_8 () ;
return V_118 ;
}
static bool F_83 ( struct V_22 * V_23 ,
struct V_5 * V_8 )
{
struct V_41 * V_120 ;
struct V_47 * V_59 ;
bool V_121 , V_122 ;
if ( F_80 ( V_8 -> V_65 ,
2 * V_117 ) ) {
F_53 ( V_69 , V_23 ,
L_9 ,
V_8 -> V_70 ,
F_81 ( V_8 -> V_65 ) ) ;
return true ;
}
V_121 = F_78 ( V_23 , V_8 ) ;
V_122 = F_79 ( V_23 , V_8 ) ;
if ( ! V_121 && ! V_122 )
return false ;
V_120 = F_82 ( V_23 , V_8 ,
V_35 ) ;
F_84 ( V_23 , V_8 , V_35 ,
V_120 ) ;
if ( V_120 )
F_34 ( V_120 ) ;
F_5 () ;
F_85 (hard_iface, &batadv_hardif_list, list) {
if ( V_59 -> V_110 != V_123 )
continue;
if ( V_59 -> V_64 != V_23 -> V_64 )
continue;
V_120 = F_82 ( V_23 ,
V_8 ,
V_59 ) ;
F_84 ( V_23 , V_8 , V_59 ,
V_120 ) ;
if ( V_120 )
F_34 ( V_120 ) ;
}
F_8 () ;
return false ;
}
static void F_86 ( struct V_22 * V_23 )
{
struct V_85 * V_86 = V_23 -> V_24 ;
struct V_1 * V_40 ;
struct V_87 * V_88 ;
T_2 * V_89 ;
struct V_5 * V_8 ;
T_3 V_90 ;
if ( ! V_86 )
return;
for ( V_90 = 0 ; V_90 < V_86 -> V_91 ; V_90 ++ ) {
V_88 = & V_86 -> V_92 [ V_90 ] ;
V_89 = & V_86 -> V_93 [ V_90 ] ;
F_10 ( V_89 ) ;
F_33 (orig_node, node_tmp,
head, hash_entry) {
if ( F_83 ( V_23 , V_8 ) ) {
F_87 ( V_23 , V_8 ) ;
F_65 ( & V_8 -> V_6 ) ;
F_88 ( V_8 -> V_23 ,
V_8 , - 1 ,
L_10 ) ;
F_68 ( V_8 ) ;
continue;
}
F_63 ( V_8 ,
V_124 ) ;
}
F_15 ( V_89 ) ;
}
F_89 ( V_23 ) ;
}
static void V_28 ( struct V_125 * V_126 )
{
struct V_127 * V_127 ;
struct V_22 * V_23 ;
V_127 = F_2 ( V_126 , struct V_127 , V_126 ) ;
V_23 = F_2 ( V_127 , struct V_22 , V_27 ) ;
F_86 ( V_23 ) ;
F_24 ( V_29 ,
& V_23 -> V_27 ,
F_25 ( V_30 ) ) ;
}
void F_90 ( struct V_22 * V_23 )
{
F_86 ( V_23 ) ;
}
int F_91 ( struct V_73 * V_74 , void * V_75 )
{
struct V_76 * V_71 = (struct V_76 * ) V_74 -> V_77 ;
struct V_22 * V_23 = F_45 ( V_71 ) ;
struct V_47 * V_78 ;
V_78 = F_55 ( V_74 ) ;
if ( ! V_78 )
return 0 ;
F_56 ( V_74 , L_2 ,
V_79 , V_78 -> V_71 -> V_72 ,
V_78 -> V_71 -> V_80 , V_71 -> V_72 ,
V_23 -> V_45 -> V_72 ) ;
F_27 ( V_78 ) ;
if ( ! V_23 -> V_45 -> V_128 ) {
F_57 ( V_74 ,
L_3 ) ;
return 0 ;
}
V_23 -> V_45 -> V_128 ( V_23 , V_74 ,
V_35 ) ;
return 0 ;
}
int F_92 ( struct V_73 * V_74 , void * V_75 )
{
struct V_76 * V_71 = (struct V_76 * ) V_74 -> V_77 ;
struct V_47 * V_59 ;
struct V_22 * V_23 ;
V_59 = F_93 ( V_71 ) ;
if ( ! V_59 || ! V_59 -> V_64 ) {
F_57 ( V_74 , L_11 ) ;
goto V_14;
}
V_23 = F_45 ( V_59 -> V_64 ) ;
if ( ! V_23 -> V_45 -> V_128 ) {
F_57 ( V_74 ,
L_3 ) ;
goto V_14;
}
if ( V_59 -> V_110 != V_123 ) {
F_57 ( V_74 , L_12 ) ;
goto V_14;
}
F_56 ( V_74 , L_13 ,
V_79 , V_59 -> V_71 -> V_72 ,
V_59 -> V_71 -> V_80 ,
V_59 -> V_64 -> V_72 , V_23 -> V_45 -> V_72 ) ;
V_23 -> V_45 -> V_128 ( V_23 , V_74 , V_59 ) ;
V_14:
if ( V_59 )
F_27 ( V_59 ) ;
return 0 ;
}
int F_94 ( struct V_47 * V_59 ,
int V_129 )
{
struct V_22 * V_23 = F_45 ( V_59 -> V_64 ) ;
struct V_43 * V_44 = V_23 -> V_45 ;
struct V_85 * V_86 = V_23 -> V_24 ;
struct V_87 * V_88 ;
struct V_5 * V_8 ;
T_3 V_90 ;
int V_130 ;
for ( V_90 = 0 ; V_90 < V_86 -> V_91 ; V_90 ++ ) {
V_88 = & V_86 -> V_92 [ V_90 ] ;
F_5 () ;
F_6 (orig_node, head, hash_entry) {
V_130 = 0 ;
if ( V_44 -> V_131 )
V_130 = V_44 -> V_131 ( V_8 ,
V_129 ) ;
if ( V_130 == - V_31 )
goto V_25;
}
F_8 () ;
}
return 0 ;
V_25:
F_8 () ;
return - V_31 ;
}
int F_95 ( struct V_47 * V_59 ,
int V_129 )
{
struct V_22 * V_23 = F_45 ( V_59 -> V_64 ) ;
struct V_85 * V_86 = V_23 -> V_24 ;
struct V_87 * V_88 ;
struct V_47 * V_132 ;
struct V_5 * V_8 ;
struct V_43 * V_44 = V_23 -> V_45 ;
T_3 V_90 ;
int V_130 ;
for ( V_90 = 0 ; V_90 < V_86 -> V_91 ; V_90 ++ ) {
V_88 = & V_86 -> V_92 [ V_90 ] ;
F_5 () ;
F_6 (orig_node, head, hash_entry) {
V_130 = 0 ;
if ( V_44 -> V_133 )
V_130 = V_44 -> V_133 ( V_8 ,
V_129 ,
V_59 -> V_134 ) ;
if ( V_130 == - V_31 )
goto V_25;
}
F_8 () ;
}
F_5 () ;
F_85 (hard_iface_tmp, &batadv_hardif_list, list) {
if ( V_132 -> V_110 == V_112 )
continue;
if ( V_59 == V_132 )
continue;
if ( V_59 -> V_64 != V_132 -> V_64 )
continue;
if ( V_132 -> V_134 > V_59 -> V_134 )
V_132 -> V_134 -- ;
}
F_8 () ;
V_59 -> V_134 = - 1 ;
return 0 ;
V_25:
F_8 () ;
return - V_31 ;
}

bool F_1 ( const struct V_1 * V_2 , const void * V_3 )
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
V_42 = F_2 ( V_19 , struct V_41 , V_12 ) ;
F_33 (neigh_ifinfo, node_tmp,
&neigh_node->ifinfo_list, list) {
F_28 ( V_33 ) ;
}
F_31 ( V_42 -> V_37 ) ;
F_27 ( V_42 -> V_38 ) ;
F_17 ( V_42 , V_21 ) ;
}
void F_34 ( struct V_41 * V_42 )
{
F_19 ( & V_42 -> V_12 , F_32 ) ;
}
struct V_41 *
F_35 ( struct V_5 * V_8 ,
const struct V_43 * V_34 )
{
struct V_44 * V_45 ;
struct V_41 * V_46 = NULL ;
F_5 () ;
F_6 (orig_ifinfo, &orig_node->ifinfo_list, list) {
if ( V_45 -> V_34 != V_34 )
continue;
V_46 = F_36 ( V_45 -> V_46 ) ;
break;
}
if ( V_46 && ! F_7 ( & V_46 -> V_12 ) )
V_46 = NULL ;
F_8 () ;
return V_46 ;
}
struct V_44 *
F_37 ( struct V_5 * V_8 ,
struct V_43 * V_34 )
{
struct V_44 * V_11 , * V_45 = NULL ;
F_5 () ;
F_6 (tmp, &orig_node->ifinfo_list,
list) {
if ( V_11 -> V_34 != V_34 )
continue;
if ( ! F_7 ( & V_11 -> V_12 ) )
continue;
V_45 = V_11 ;
break;
}
F_8 () ;
return V_45 ;
}
struct V_44 *
F_38 ( struct V_5 * V_8 ,
struct V_43 * V_34 )
{
struct V_44 * V_45 = NULL ;
unsigned long V_47 ;
F_10 ( & V_8 -> V_39 ) ;
V_45 = F_37 ( V_8 , V_34 ) ;
if ( V_45 )
goto V_14;
V_45 = F_11 ( sizeof( * V_45 ) , V_15 ) ;
if ( ! V_45 )
goto V_14;
if ( V_34 != V_35 )
F_13 ( & V_34 -> V_12 ) ;
V_47 = V_48 - 1 ;
V_47 -= F_25 ( V_49 ) ;
V_45 -> V_50 = V_47 ;
V_45 -> V_34 = V_34 ;
F_39 ( & V_45 -> V_16 ) ;
F_12 ( & V_45 -> V_12 ) ;
F_13 ( & V_45 -> V_12 ) ;
F_14 ( & V_45 -> V_16 ,
& V_8 -> V_51 ) ;
V_14:
F_15 ( & V_8 -> V_39 ) ;
return V_45 ;
}
struct V_32 *
F_40 ( struct V_41 * V_52 ,
struct V_43 * V_34 )
{
struct V_32 * V_33 = NULL ,
* V_53 ;
F_5 () ;
F_6 (tmp_neigh_ifinfo, &neigh->ifinfo_list,
list) {
if ( V_53 -> V_34 != V_34 )
continue;
if ( ! F_7 ( & V_53 -> V_12 ) )
continue;
V_33 = V_53 ;
break;
}
F_8 () ;
return V_33 ;
}
struct V_32 *
F_41 ( struct V_41 * V_52 ,
struct V_43 * V_34 )
{
struct V_32 * V_33 ;
F_10 ( & V_52 -> V_54 ) ;
V_33 = F_40 ( V_52 , V_34 ) ;
if ( V_33 )
goto V_14;
V_33 = F_11 ( sizeof( * V_33 ) , V_15 ) ;
if ( ! V_33 )
goto V_14;
if ( V_34 )
F_13 ( & V_34 -> V_12 ) ;
F_39 ( & V_33 -> V_16 ) ;
F_12 ( & V_33 -> V_12 ) ;
F_13 ( & V_33 -> V_12 ) ;
V_33 -> V_34 = V_34 ;
F_14 ( & V_33 -> V_16 , & V_52 -> V_51 ) ;
V_14:
F_15 ( & V_52 -> V_54 ) ;
return V_33 ;
}
static struct V_41 *
F_42 ( const struct V_5 * V_8 ,
const struct V_43 * V_55 ,
const T_1 * V_56 )
{
struct V_41 * V_57 , * V_58 = NULL ;
F_5 () ;
F_6 (tmp_neigh_node, &orig_node->neigh_list, list) {
if ( ! F_3 ( V_57 -> V_56 , V_56 ) )
continue;
if ( V_57 -> V_38 != V_55 )
continue;
if ( ! F_7 ( & V_57 -> V_12 ) )
continue;
V_58 = V_57 ;
break;
}
F_8 () ;
return V_58 ;
}
static struct V_36 *
F_43 ( struct V_43 * V_55 ,
const T_1 * V_59 )
{
struct V_22 * V_23 = F_44 ( V_55 -> V_60 ) ;
struct V_36 * V_37 = NULL ;
F_10 ( & V_55 -> V_39 ) ;
V_37 = F_45 ( V_55 , V_59 ) ;
if ( V_37 )
goto V_14;
V_37 = F_11 ( sizeof( * V_37 ) , V_15 ) ;
if ( ! V_37 )
goto V_14;
F_13 ( & V_55 -> V_12 ) ;
F_39 ( & V_37 -> V_16 ) ;
F_46 ( V_37 -> V_56 , V_59 ) ;
V_37 -> V_38 = V_55 ;
V_37 -> V_61 = V_48 ;
F_12 ( & V_37 -> V_12 ) ;
if ( V_23 -> V_62 -> V_52 . V_63 )
V_23 -> V_62 -> V_52 . V_63 ( V_37 ) ;
F_47 ( & V_37 -> V_16 , & V_55 -> V_64 ) ;
V_14:
F_15 ( & V_55 -> V_39 ) ;
return V_37 ;
}
static struct V_36 *
F_48 ( struct V_43 * V_55 ,
const T_1 * V_59 )
{
struct V_36 * V_37 = NULL ;
V_37 = F_45 ( V_55 , V_59 ) ;
if ( V_37 )
return V_37 ;
return F_43 ( V_55 , V_59 ) ;
}
struct V_36 *
F_45 ( const struct V_43 * V_55 ,
const T_1 * V_59 )
{
struct V_36 * V_65 , * V_37 = NULL ;
F_5 () ;
F_6 (tmp_hardif_neigh,
&hard_iface->neigh_list, list) {
if ( ! F_3 ( V_65 -> V_56 , V_59 ) )
continue;
if ( ! F_7 ( & V_65 -> V_12 ) )
continue;
V_37 = V_65 ;
break;
}
F_8 () ;
return V_37 ;
}
static struct V_41 *
F_49 ( struct V_5 * V_8 ,
struct V_43 * V_55 ,
const T_1 * V_59 )
{
struct V_41 * V_42 ;
struct V_36 * V_37 = NULL ;
F_10 ( & V_8 -> V_39 ) ;
V_42 = F_42 ( V_8 , V_55 , V_59 ) ;
if ( V_42 )
goto V_14;
V_37 = F_48 ( V_55 ,
V_59 ) ;
if ( ! V_37 )
goto V_14;
V_42 = F_11 ( sizeof( * V_42 ) , V_15 ) ;
if ( ! V_42 )
goto V_14;
F_39 ( & V_42 -> V_16 ) ;
F_50 ( & V_42 -> V_51 ) ;
F_51 ( & V_42 -> V_54 ) ;
F_13 ( & V_55 -> V_12 ) ;
F_46 ( V_42 -> V_56 , V_59 ) ;
V_42 -> V_38 = V_55 ;
V_42 -> V_8 = V_8 ;
V_42 -> V_61 = V_48 ;
F_13 ( & V_37 -> V_12 ) ;
V_42 -> V_37 = V_37 ;
F_12 ( & V_42 -> V_12 ) ;
F_13 ( & V_42 -> V_12 ) ;
F_14 ( & V_42 -> V_16 , & V_8 -> V_64 ) ;
F_52 ( V_66 , V_8 -> V_23 ,
L_1 ,
V_59 , V_8 -> V_67 , V_55 -> V_68 -> V_69 ) ;
V_14:
F_15 ( & V_8 -> V_39 ) ;
if ( V_37 )
F_31 ( V_37 ) ;
return V_42 ;
}
struct V_41 *
F_53 ( struct V_5 * V_8 ,
struct V_43 * V_55 ,
const T_1 * V_59 )
{
struct V_41 * V_42 = NULL ;
V_42 = F_42 ( V_8 , V_55 , V_59 ) ;
if ( V_42 )
return V_42 ;
return F_49 ( V_8 , V_55 , V_59 ) ;
}
int F_54 ( struct V_70 * V_71 , void * V_72 )
{
struct V_73 * V_68 = (struct V_73 * ) V_71 -> V_74 ;
struct V_22 * V_23 = F_44 ( V_68 ) ;
struct V_43 * V_75 ;
V_75 = F_55 ( V_71 ) ;
if ( ! V_75 )
return 0 ;
F_56 ( V_71 , L_2 ,
V_76 , V_75 -> V_68 -> V_69 ,
V_75 -> V_68 -> V_77 , V_68 -> V_69 ,
V_23 -> V_62 -> V_69 ) ;
F_27 ( V_75 ) ;
if ( ! V_23 -> V_62 -> V_52 . V_78 ) {
F_57 ( V_71 ,
L_3 ) ;
return 0 ;
}
V_23 -> V_62 -> V_52 . V_78 ( V_23 , V_71 ) ;
return 0 ;
}
static void F_58 ( struct V_18 * V_19 )
{
struct V_44 * V_45 ;
struct V_41 * V_46 ;
V_45 = F_2 ( V_19 , struct V_44 , V_12 ) ;
if ( V_45 -> V_34 != V_35 )
F_27 ( V_45 -> V_34 ) ;
V_46 = F_59 ( V_45 -> V_46 , true ) ;
if ( V_46 )
F_34 ( V_46 ) ;
F_17 ( V_45 , V_21 ) ;
}
void F_60 ( struct V_44 * V_45 )
{
F_19 ( & V_45 -> V_12 , F_58 ) ;
}
static void F_61 ( struct V_79 * V_21 )
{
struct V_5 * V_8 ;
V_8 = F_2 ( V_21 , struct V_5 , V_21 ) ;
F_62 ( V_8 ) ;
F_63 ( V_8 , NULL ) ;
if ( V_8 -> V_23 -> V_62 -> V_67 . free )
V_8 -> V_23 -> V_62 -> V_67 . free ( V_8 ) ;
F_64 ( V_8 -> V_80 ) ;
F_64 ( V_8 ) ;
}
static void F_65 ( struct V_18 * V_19 )
{
struct V_1 * V_40 ;
struct V_41 * V_42 ;
struct V_5 * V_8 ;
struct V_44 * V_45 ;
struct V_7 * V_10 ;
struct V_44 * V_81 ;
V_8 = F_2 ( V_19 , struct V_5 , V_12 ) ;
F_10 ( & V_8 -> V_39 ) ;
F_33 (neigh_node, node_tmp,
&orig_node->neigh_list, list) {
F_66 ( & V_42 -> V_16 ) ;
F_34 ( V_42 ) ;
}
F_33 (orig_ifinfo, node_tmp,
&orig_node->ifinfo_list, list) {
F_66 ( & V_45 -> V_16 ) ;
F_60 ( V_45 ) ;
}
V_81 = V_8 -> V_82 ;
V_8 -> V_82 = NULL ;
F_15 ( & V_8 -> V_39 ) ;
if ( V_81 )
F_60 ( V_81 ) ;
F_10 ( & V_8 -> V_13 ) ;
F_33 (vlan, node_tmp, &orig_node->vlan_list, list) {
F_66 ( & V_10 -> V_16 ) ;
F_18 ( V_10 ) ;
}
F_15 ( & V_8 -> V_13 ) ;
F_67 ( V_8 -> V_23 , V_8 , NULL ) ;
F_68 ( & V_8 -> V_21 , F_61 ) ;
}
void F_69 ( struct V_5 * V_8 )
{
F_19 ( & V_8 -> V_12 , F_65 ) ;
}
void F_70 ( struct V_22 * V_23 )
{
struct V_83 * V_84 = V_23 -> V_24 ;
struct V_1 * V_40 ;
struct V_85 * V_86 ;
T_2 * V_87 ;
struct V_5 * V_8 ;
T_3 V_88 ;
if ( ! V_84 )
return;
F_71 ( & V_23 -> V_27 ) ;
V_23 -> V_24 = NULL ;
for ( V_88 = 0 ; V_88 < V_84 -> V_89 ; V_88 ++ ) {
V_86 = & V_84 -> V_90 [ V_88 ] ;
V_87 = & V_84 -> V_91 [ V_88 ] ;
F_10 ( V_87 ) ;
F_33 (orig_node, node_tmp,
head, hash_entry) {
F_66 ( & V_8 -> V_6 ) ;
F_69 ( V_8 ) ;
}
F_15 ( V_87 ) ;
}
F_72 ( V_84 ) ;
}
struct V_5 * F_73 ( struct V_22 * V_23 ,
const T_1 * V_56 )
{
struct V_5 * V_8 ;
struct V_7 * V_10 ;
unsigned long V_47 ;
int V_88 ;
F_52 ( V_66 , V_23 ,
L_4 , V_56 ) ;
V_8 = F_11 ( sizeof( * V_8 ) , V_15 ) ;
if ( ! V_8 )
return NULL ;
F_50 ( & V_8 -> V_64 ) ;
F_50 ( & V_8 -> V_17 ) ;
F_50 ( & V_8 -> V_51 ) ;
F_51 ( & V_8 -> V_92 ) ;
F_51 ( & V_8 -> V_39 ) ;
F_51 ( & V_8 -> V_93 ) ;
F_51 ( & V_8 -> V_94 ) ;
F_51 ( & V_8 -> V_13 ) ;
F_74 ( V_8 ) ;
F_12 ( & V_8 -> V_12 ) ;
F_13 ( & V_8 -> V_12 ) ;
V_8 -> V_23 = V_23 ;
F_46 ( V_8 -> V_67 , V_56 ) ;
F_75 ( V_8 ) ;
F_76 ( & V_8 -> V_95 , 0 ) ;
V_8 -> V_80 = NULL ;
V_8 -> V_96 = 0 ;
V_8 -> V_61 = V_48 ;
V_47 = V_48 - 1 - F_25 ( V_49 ) ;
V_8 -> V_97 = V_47 ;
#ifdef F_77
V_8 -> V_98 = V_99 ;
F_39 ( & V_8 -> V_100 ) ;
F_39 ( & V_8 -> V_101 ) ;
F_39 ( & V_8 -> V_102 ) ;
F_51 ( & V_8 -> V_103 ) ;
#endif
V_10 = F_9 ( V_8 , V_99 ) ;
if ( ! V_10 )
goto V_104;
F_18 ( V_10 ) ;
for ( V_88 = 0 ; V_88 < V_105 ; V_88 ++ ) {
F_50 ( & V_8 -> V_106 [ V_88 ] . V_86 ) ;
F_51 ( & V_8 -> V_106 [ V_88 ] . V_107 ) ;
V_8 -> V_106 [ V_88 ] . V_89 = 0 ;
}
return V_8 ;
V_104:
F_64 ( V_8 ) ;
return NULL ;
}
static void
F_78 ( struct V_22 * V_23 ,
struct V_41 * V_52 )
{
struct V_32 * V_33 ;
struct V_43 * V_34 ;
struct V_1 * V_40 ;
F_10 ( & V_52 -> V_54 ) ;
F_33 (neigh_ifinfo, node_tmp,
&neigh->ifinfo_list, list) {
V_34 = V_33 -> V_34 ;
if ( V_34 == V_35 )
continue;
if ( ( V_34 -> V_108 != V_109 ) &&
( V_34 -> V_108 != V_110 ) &&
( V_34 -> V_108 != V_111 ) )
continue;
F_52 ( V_66 , V_23 ,
L_5 ,
V_52 -> V_56 , V_34 -> V_68 -> V_69 ) ;
F_66 ( & V_33 -> V_16 ) ;
F_28 ( V_33 ) ;
}
F_15 ( & V_52 -> V_54 ) ;
}
static bool
F_79 ( struct V_22 * V_23 ,
struct V_5 * V_8 )
{
struct V_44 * V_45 ;
struct V_43 * V_34 ;
struct V_1 * V_40 ;
bool V_112 = false ;
F_10 ( & V_8 -> V_39 ) ;
F_33 (orig_ifinfo, node_tmp,
&orig_node->ifinfo_list, list) {
V_34 = V_45 -> V_34 ;
if ( V_34 == V_35 )
continue;
if ( ( V_34 -> V_108 != V_109 ) &&
( V_34 -> V_108 != V_110 ) &&
( V_34 -> V_108 != V_111 ) )
continue;
F_52 ( V_66 , V_23 ,
L_6 ,
V_8 -> V_67 , V_34 -> V_68 -> V_69 ) ;
V_112 = true ;
F_66 ( & V_45 -> V_16 ) ;
F_60 ( V_45 ) ;
if ( V_8 -> V_82 == V_45 ) {
V_8 -> V_82 = NULL ;
F_60 ( V_45 ) ;
}
}
F_15 ( & V_8 -> V_39 ) ;
return V_112 ;
}
static bool
F_80 ( struct V_22 * V_23 ,
struct V_5 * V_8 )
{
struct V_1 * V_40 ;
struct V_41 * V_42 ;
bool V_113 = false ;
unsigned long V_61 ;
struct V_43 * V_38 ;
F_10 ( & V_8 -> V_39 ) ;
F_33 (neigh_node, node_tmp,
&orig_node->neigh_list, list) {
V_61 = V_42 -> V_61 ;
V_38 = V_42 -> V_38 ;
if ( ( F_81 ( V_61 , V_114 ) ) ||
( V_38 -> V_108 == V_109 ) ||
( V_38 -> V_108 == V_110 ) ||
( V_38 -> V_108 == V_111 ) ) {
if ( ( V_38 -> V_108 == V_109 ) ||
( V_38 -> V_108 == V_110 ) ||
( V_38 -> V_108 == V_111 ) )
F_52 ( V_66 , V_23 ,
L_7 ,
V_8 -> V_67 , V_42 -> V_56 ,
V_38 -> V_68 -> V_69 ) ;
else
F_52 ( V_66 , V_23 ,
L_8 ,
V_8 -> V_67 , V_42 -> V_56 ,
F_82 ( V_61 ) ) ;
V_113 = true ;
F_66 ( & V_42 -> V_16 ) ;
F_34 ( V_42 ) ;
} else {
F_78 ( V_23 , V_42 ) ;
}
}
F_15 ( & V_8 -> V_39 ) ;
return V_113 ;
}
static struct V_41 *
F_83 ( struct V_22 * V_23 ,
struct V_5 * V_8 ,
struct V_43 * V_34 )
{
struct V_41 * V_115 = NULL , * V_52 ;
struct V_116 * V_117 = V_23 -> V_62 ;
F_5 () ;
F_6 (neigh, &orig_node->neigh_list, list) {
if ( V_115 && ( V_117 -> V_52 . V_118 ( V_52 , V_34 , V_115 ,
V_34 ) <= 0 ) )
continue;
if ( ! F_7 ( & V_52 -> V_12 ) )
continue;
if ( V_115 )
F_34 ( V_115 ) ;
V_115 = V_52 ;
}
F_8 () ;
return V_115 ;
}
static bool F_84 ( struct V_22 * V_23 ,
struct V_5 * V_8 )
{
struct V_41 * V_119 ;
struct V_43 * V_55 ;
bool V_120 , V_121 ;
if ( F_81 ( V_8 -> V_61 ,
2 * V_114 ) ) {
F_52 ( V_66 , V_23 ,
L_9 ,
V_8 -> V_67 ,
F_82 ( V_8 -> V_61 ) ) ;
return true ;
}
V_120 = F_79 ( V_23 , V_8 ) ;
V_121 = F_80 ( V_23 , V_8 ) ;
if ( ! V_120 && ! V_121 )
return false ;
V_119 = F_83 ( V_23 , V_8 ,
V_35 ) ;
F_85 ( V_23 , V_8 , V_35 ,
V_119 ) ;
if ( V_119 )
F_34 ( V_119 ) ;
F_5 () ;
F_86 (hard_iface, &batadv_hardif_list, list) {
if ( V_55 -> V_108 != V_122 )
continue;
if ( V_55 -> V_60 != V_23 -> V_60 )
continue;
if ( ! F_7 ( & V_55 -> V_12 ) )
continue;
V_119 = F_83 ( V_23 ,
V_8 ,
V_55 ) ;
F_85 ( V_23 , V_8 , V_55 ,
V_119 ) ;
if ( V_119 )
F_34 ( V_119 ) ;
F_27 ( V_55 ) ;
}
F_8 () ;
return false ;
}
static void F_87 ( struct V_22 * V_23 )
{
struct V_83 * V_84 = V_23 -> V_24 ;
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
F_33 (orig_node, node_tmp,
head, hash_entry) {
if ( F_84 ( V_23 , V_8 ) ) {
F_88 ( V_23 , V_8 ) ;
F_66 ( & V_8 -> V_6 ) ;
F_89 ( V_8 -> V_23 ,
V_8 , - 1 ,
L_10 ) ;
F_69 ( V_8 ) ;
continue;
}
F_63 ( V_8 ,
V_123 ) ;
}
F_15 ( V_87 ) ;
}
F_90 ( V_23 ) ;
}
static void V_28 ( struct V_124 * V_125 )
{
struct V_126 * V_126 ;
struct V_22 * V_23 ;
V_126 = F_91 ( V_125 ) ;
V_23 = F_2 ( V_126 , struct V_22 , V_27 ) ;
F_87 ( V_23 ) ;
F_24 ( V_29 ,
& V_23 -> V_27 ,
F_25 ( V_30 ) ) ;
}
void F_92 ( struct V_22 * V_23 )
{
F_87 ( V_23 ) ;
}
int F_93 ( struct V_70 * V_71 , void * V_72 )
{
struct V_73 * V_68 = (struct V_73 * ) V_71 -> V_74 ;
struct V_22 * V_23 = F_44 ( V_68 ) ;
struct V_43 * V_75 ;
V_75 = F_55 ( V_71 ) ;
if ( ! V_75 )
return 0 ;
F_56 ( V_71 , L_2 ,
V_76 , V_75 -> V_68 -> V_69 ,
V_75 -> V_68 -> V_77 , V_68 -> V_69 ,
V_23 -> V_62 -> V_69 ) ;
F_27 ( V_75 ) ;
if ( ! V_23 -> V_62 -> V_67 . V_78 ) {
F_57 ( V_71 ,
L_3 ) ;
return 0 ;
}
V_23 -> V_62 -> V_67 . V_78 ( V_23 , V_71 , V_35 ) ;
return 0 ;
}
int F_94 ( struct V_70 * V_71 , void * V_72 )
{
struct V_73 * V_68 = (struct V_73 * ) V_71 -> V_74 ;
struct V_43 * V_55 ;
struct V_22 * V_23 ;
V_55 = F_95 ( V_68 ) ;
if ( ! V_55 || ! V_55 -> V_60 ) {
F_57 ( V_71 , L_11 ) ;
goto V_14;
}
V_23 = F_44 ( V_55 -> V_60 ) ;
if ( ! V_23 -> V_62 -> V_67 . V_78 ) {
F_57 ( V_71 ,
L_3 ) ;
goto V_14;
}
if ( V_55 -> V_108 != V_122 ) {
F_57 ( V_71 , L_12 ) ;
goto V_14;
}
F_56 ( V_71 , L_13 ,
V_76 , V_55 -> V_68 -> V_69 ,
V_55 -> V_68 -> V_77 ,
V_55 -> V_60 -> V_69 , V_23 -> V_62 -> V_69 ) ;
V_23 -> V_62 -> V_67 . V_78 ( V_23 , V_71 , V_55 ) ;
V_14:
if ( V_55 )
F_27 ( V_55 ) ;
return 0 ;
}
int F_96 ( struct V_43 * V_55 ,
int V_127 )
{
struct V_22 * V_23 = F_44 ( V_55 -> V_60 ) ;
struct V_116 * V_117 = V_23 -> V_62 ;
struct V_83 * V_84 = V_23 -> V_24 ;
struct V_85 * V_86 ;
struct V_5 * V_8 ;
T_3 V_88 ;
int V_128 ;
for ( V_88 = 0 ; V_88 < V_84 -> V_89 ; V_88 ++ ) {
V_86 = & V_84 -> V_90 [ V_88 ] ;
F_5 () ;
F_6 (orig_node, head, hash_entry) {
V_128 = 0 ;
if ( V_117 -> V_67 . V_129 )
V_128 = V_117 -> V_67 . V_129 ( V_8 , V_127 ) ;
if ( V_128 == - V_31 )
goto V_25;
}
F_8 () ;
}
return 0 ;
V_25:
F_8 () ;
return - V_31 ;
}
int F_97 ( struct V_43 * V_55 ,
int V_127 )
{
struct V_22 * V_23 = F_44 ( V_55 -> V_60 ) ;
struct V_83 * V_84 = V_23 -> V_24 ;
struct V_85 * V_86 ;
struct V_43 * V_130 ;
struct V_5 * V_8 ;
struct V_116 * V_117 = V_23 -> V_62 ;
T_3 V_88 ;
int V_128 ;
for ( V_88 = 0 ; V_88 < V_84 -> V_89 ; V_88 ++ ) {
V_86 = & V_84 -> V_90 [ V_88 ] ;
F_5 () ;
F_6 (orig_node, head, hash_entry) {
V_128 = 0 ;
if ( V_117 -> V_67 . V_131 )
V_128 = V_117 -> V_67 . V_131 ( V_8 , V_127 ,
V_55 -> V_132 ) ;
if ( V_128 == - V_31 )
goto V_25;
}
F_8 () ;
}
F_5 () ;
F_86 (hard_iface_tmp, &batadv_hardif_list, list) {
if ( V_130 -> V_108 == V_110 )
continue;
if ( V_55 == V_130 )
continue;
if ( V_55 -> V_60 != V_130 -> V_60 )
continue;
if ( V_130 -> V_132 > V_55 -> V_132 )
V_130 -> V_132 -- ;
}
F_8 () ;
V_55 -> V_132 = - 1 ;
return 0 ;
V_25:
F_8 () ;
return - V_31 ;
}

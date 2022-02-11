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
V_10 -> V_9 = V_9 ;
F_13 ( & V_10 -> V_12 ) ;
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
struct V_44 * V_45 ;
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
V_33 -> V_34 = V_34 ;
F_13 ( & V_33 -> V_12 ) ;
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
const T_1 * V_59 ,
struct V_5 * V_8 )
{
struct V_22 * V_23 = F_44 ( V_55 -> V_60 ) ;
struct V_36 * V_37 ;
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
F_46 ( V_37 -> V_61 , V_8 -> V_61 ) ;
V_37 -> V_38 = V_55 ;
V_37 -> V_62 = V_48 ;
F_12 ( & V_37 -> V_12 ) ;
if ( V_23 -> V_63 -> V_52 . V_64 )
V_23 -> V_63 -> V_52 . V_64 ( V_37 ) ;
F_14 ( & V_37 -> V_16 , & V_55 -> V_65 ) ;
V_14:
F_15 ( & V_55 -> V_39 ) ;
return V_37 ;
}
static struct V_36 *
F_47 ( struct V_43 * V_55 ,
const T_1 * V_59 ,
struct V_5 * V_8 )
{
struct V_36 * V_37 ;
V_37 = F_45 ( V_55 , V_59 ) ;
if ( V_37 )
return V_37 ;
return F_43 ( V_55 , V_59 , V_8 ) ;
}
struct V_36 *
F_45 ( const struct V_43 * V_55 ,
const T_1 * V_59 )
{
struct V_36 * V_66 , * V_37 = NULL ;
F_5 () ;
F_6 (tmp_hardif_neigh,
&hard_iface->neigh_list, list) {
if ( ! F_3 ( V_66 -> V_56 , V_59 ) )
continue;
if ( ! F_7 ( & V_66 -> V_12 ) )
continue;
V_37 = V_66 ;
break;
}
F_8 () ;
return V_37 ;
}
static struct V_41 *
F_48 ( struct V_5 * V_8 ,
struct V_43 * V_55 ,
const T_1 * V_59 )
{
struct V_41 * V_42 ;
struct V_36 * V_37 = NULL ;
F_10 ( & V_8 -> V_39 ) ;
V_42 = F_42 ( V_8 , V_55 , V_59 ) ;
if ( V_42 )
goto V_14;
V_37 = F_47 ( V_55 ,
V_59 , V_8 ) ;
if ( ! V_37 )
goto V_14;
V_42 = F_11 ( sizeof( * V_42 ) , V_15 ) ;
if ( ! V_42 )
goto V_14;
F_39 ( & V_42 -> V_16 ) ;
F_49 ( & V_42 -> V_51 ) ;
F_50 ( & V_42 -> V_54 ) ;
F_13 ( & V_55 -> V_12 ) ;
F_46 ( V_42 -> V_56 , V_59 ) ;
V_42 -> V_38 = V_55 ;
V_42 -> V_8 = V_8 ;
V_42 -> V_62 = V_48 ;
F_13 ( & V_37 -> V_12 ) ;
V_42 -> V_37 = V_37 ;
F_12 ( & V_42 -> V_12 ) ;
F_13 ( & V_42 -> V_12 ) ;
F_14 ( & V_42 -> V_16 , & V_8 -> V_65 ) ;
F_51 ( V_67 , V_8 -> V_23 ,
L_1 ,
V_59 , V_8 -> V_61 , V_55 -> V_68 -> V_69 ) ;
V_14:
F_15 ( & V_8 -> V_39 ) ;
if ( V_37 )
F_31 ( V_37 ) ;
return V_42 ;
}
struct V_41 *
F_52 ( struct V_5 * V_8 ,
struct V_43 * V_55 ,
const T_1 * V_59 )
{
struct V_41 * V_42 ;
V_42 = F_42 ( V_8 , V_55 , V_59 ) ;
if ( V_42 )
return V_42 ;
return F_48 ( V_8 , V_55 , V_59 ) ;
}
int F_53 ( struct V_70 * V_71 , void * V_72 )
{
struct V_73 * V_68 = (struct V_73 * ) V_71 -> V_74 ;
struct V_22 * V_23 = F_44 ( V_68 ) ;
struct V_43 * V_75 ;
V_75 = F_54 ( V_71 ) ;
if ( ! V_75 )
return 0 ;
F_55 ( V_71 , L_2 ,
V_76 , V_75 -> V_68 -> V_69 ,
V_75 -> V_68 -> V_77 , V_68 -> V_69 ,
V_23 -> V_63 -> V_69 ) ;
F_27 ( V_75 ) ;
if ( ! V_23 -> V_63 -> V_52 . V_78 ) {
F_56 ( V_71 ,
L_3 ) ;
return 0 ;
}
V_23 -> V_63 -> V_52 . V_78 ( V_23 , V_71 ) ;
return 0 ;
}
int F_57 ( struct V_79 * V_80 , struct V_81 * V_82 )
{
struct V_83 * V_83 = F_58 ( V_82 -> V_84 -> V_85 ) ;
struct V_73 * V_60 ;
struct V_73 * V_55 = NULL ;
struct V_43 * V_86 = V_35 ;
struct V_22 * V_23 ;
struct V_43 * V_75 = NULL ;
int V_87 ;
int V_88 , V_89 ;
V_88 = F_59 ( V_82 -> V_90 , V_91 ) ;
if ( ! V_88 )
return - V_92 ;
V_60 = F_60 ( V_83 , V_88 ) ;
if ( ! V_60 || ! F_61 ( V_60 ) ) {
V_87 = - V_93 ;
goto V_14;
}
V_23 = F_44 ( V_60 ) ;
V_75 = F_62 ( V_23 ) ;
if ( ! V_75 || V_75 -> V_94 != V_95 ) {
V_87 = - V_96 ;
goto V_14;
}
V_89 = F_59 ( V_82 -> V_90 ,
V_97 ) ;
if ( V_89 ) {
V_55 = F_60 ( V_83 , V_89 ) ;
if ( V_55 )
V_86 = F_63 ( V_55 ) ;
if ( ! V_86 ) {
V_87 = - V_93 ;
goto V_14;
}
if ( V_86 -> V_60 != V_60 ) {
V_87 = - V_96 ;
goto V_14;
}
}
if ( ! V_23 -> V_63 -> V_52 . V_98 ) {
V_87 = - V_99 ;
goto V_14;
}
V_23 -> V_63 -> V_52 . V_98 ( V_80 , V_82 , V_23 , V_86 ) ;
V_87 = V_80 -> V_100 ;
V_14:
if ( V_86 )
F_27 ( V_86 ) ;
if ( V_55 )
F_64 ( V_55 ) ;
if ( V_75 )
F_27 ( V_75 ) ;
if ( V_60 )
F_64 ( V_60 ) ;
return V_87 ;
}
static void F_65 ( struct V_18 * V_19 )
{
struct V_44 * V_45 ;
struct V_41 * V_46 ;
V_45 = F_2 ( V_19 , struct V_44 , V_12 ) ;
if ( V_45 -> V_34 != V_35 )
F_27 ( V_45 -> V_34 ) ;
V_46 = F_66 ( V_45 -> V_46 , true ) ;
if ( V_46 )
F_34 ( V_46 ) ;
F_17 ( V_45 , V_21 ) ;
}
void F_67 ( struct V_44 * V_45 )
{
F_19 ( & V_45 -> V_12 , F_65 ) ;
}
static void F_68 ( struct V_101 * V_21 )
{
struct V_5 * V_8 ;
V_8 = F_2 ( V_21 , struct V_5 , V_21 ) ;
F_69 ( V_8 ) ;
F_70 ( V_8 , NULL ) ;
if ( V_8 -> V_23 -> V_63 -> V_61 . free )
V_8 -> V_23 -> V_63 -> V_61 . free ( V_8 ) ;
F_71 ( V_8 -> V_102 ) ;
F_71 ( V_8 ) ;
}
static void F_72 ( struct V_18 * V_19 )
{
struct V_1 * V_40 ;
struct V_41 * V_42 ;
struct V_5 * V_8 ;
struct V_44 * V_45 ;
struct V_7 * V_10 ;
struct V_44 * V_103 ;
V_8 = F_2 ( V_19 , struct V_5 , V_12 ) ;
F_10 ( & V_8 -> V_39 ) ;
F_33 (neigh_node, node_tmp,
&orig_node->neigh_list, list) {
F_73 ( & V_42 -> V_16 ) ;
F_34 ( V_42 ) ;
}
F_33 (orig_ifinfo, node_tmp,
&orig_node->ifinfo_list, list) {
F_73 ( & V_45 -> V_16 ) ;
F_67 ( V_45 ) ;
}
V_103 = V_8 -> V_104 ;
V_8 -> V_104 = NULL ;
F_15 ( & V_8 -> V_39 ) ;
if ( V_103 )
F_67 ( V_103 ) ;
F_10 ( & V_8 -> V_13 ) ;
F_33 (vlan, node_tmp, &orig_node->vlan_list, list) {
F_73 ( & V_10 -> V_16 ) ;
F_18 ( V_10 ) ;
}
F_15 ( & V_8 -> V_13 ) ;
F_74 ( V_8 -> V_23 , V_8 , NULL ) ;
F_75 ( & V_8 -> V_21 , F_68 ) ;
}
void F_76 ( struct V_5 * V_8 )
{
F_19 ( & V_8 -> V_12 , F_72 ) ;
}
void F_77 ( struct V_22 * V_23 )
{
struct V_105 * V_106 = V_23 -> V_24 ;
struct V_1 * V_40 ;
struct V_107 * V_108 ;
T_2 * V_109 ;
struct V_5 * V_8 ;
T_3 V_110 ;
if ( ! V_106 )
return;
F_78 ( & V_23 -> V_27 ) ;
V_23 -> V_24 = NULL ;
for ( V_110 = 0 ; V_110 < V_106 -> V_111 ; V_110 ++ ) {
V_108 = & V_106 -> V_112 [ V_110 ] ;
V_109 = & V_106 -> V_113 [ V_110 ] ;
F_10 ( V_109 ) ;
F_33 (orig_node, node_tmp,
head, hash_entry) {
F_73 ( & V_8 -> V_6 ) ;
F_76 ( V_8 ) ;
}
F_15 ( V_109 ) ;
}
F_79 ( V_106 ) ;
}
struct V_5 * F_80 ( struct V_22 * V_23 ,
const T_1 * V_56 )
{
struct V_5 * V_8 ;
struct V_7 * V_10 ;
unsigned long V_47 ;
int V_110 ;
F_51 ( V_67 , V_23 ,
L_4 , V_56 ) ;
V_8 = F_11 ( sizeof( * V_8 ) , V_15 ) ;
if ( ! V_8 )
return NULL ;
F_49 ( & V_8 -> V_65 ) ;
F_49 ( & V_8 -> V_17 ) ;
F_49 ( & V_8 -> V_51 ) ;
F_50 ( & V_8 -> V_114 ) ;
F_50 ( & V_8 -> V_39 ) ;
F_50 ( & V_8 -> V_115 ) ;
F_50 ( & V_8 -> V_116 ) ;
F_50 ( & V_8 -> V_13 ) ;
F_81 ( V_8 ) ;
F_12 ( & V_8 -> V_12 ) ;
V_8 -> V_23 = V_23 ;
F_46 ( V_8 -> V_61 , V_56 ) ;
F_82 ( V_8 ) ;
F_83 ( & V_8 -> V_117 , 0 ) ;
V_8 -> V_102 = NULL ;
V_8 -> V_118 = 0 ;
V_8 -> V_62 = V_48 ;
V_47 = V_48 - 1 - F_25 ( V_49 ) ;
V_8 -> V_119 = V_47 ;
#ifdef F_84
V_8 -> V_120 = V_121 ;
F_39 ( & V_8 -> V_122 ) ;
F_39 ( & V_8 -> V_123 ) ;
F_39 ( & V_8 -> V_124 ) ;
F_50 ( & V_8 -> V_125 ) ;
#endif
V_10 = F_9 ( V_8 , V_121 ) ;
if ( ! V_10 )
goto V_126;
F_18 ( V_10 ) ;
for ( V_110 = 0 ; V_110 < V_127 ; V_110 ++ ) {
F_49 ( & V_8 -> V_128 [ V_110 ] . V_129 ) ;
F_50 ( & V_8 -> V_128 [ V_110 ] . V_130 ) ;
V_8 -> V_128 [ V_110 ] . V_111 = 0 ;
}
return V_8 ;
V_126:
F_71 ( V_8 ) ;
return NULL ;
}
static void
F_85 ( struct V_22 * V_23 ,
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
if ( ( V_34 -> V_94 != V_131 ) &&
( V_34 -> V_94 != V_132 ) &&
( V_34 -> V_94 != V_133 ) )
continue;
F_51 ( V_67 , V_23 ,
L_5 ,
V_52 -> V_56 , V_34 -> V_68 -> V_69 ) ;
F_73 ( & V_33 -> V_16 ) ;
F_28 ( V_33 ) ;
}
F_15 ( & V_52 -> V_54 ) ;
}
static bool
F_86 ( struct V_22 * V_23 ,
struct V_5 * V_8 )
{
struct V_44 * V_45 ;
struct V_43 * V_34 ;
struct V_1 * V_40 ;
bool V_134 = false ;
F_10 ( & V_8 -> V_39 ) ;
F_33 (orig_ifinfo, node_tmp,
&orig_node->ifinfo_list, list) {
V_34 = V_45 -> V_34 ;
if ( V_34 == V_35 )
continue;
if ( ( V_34 -> V_94 != V_131 ) &&
( V_34 -> V_94 != V_132 ) &&
( V_34 -> V_94 != V_133 ) )
continue;
F_51 ( V_67 , V_23 ,
L_6 ,
V_8 -> V_61 , V_34 -> V_68 -> V_69 ) ;
V_134 = true ;
F_73 ( & V_45 -> V_16 ) ;
F_67 ( V_45 ) ;
if ( V_8 -> V_104 == V_45 ) {
V_8 -> V_104 = NULL ;
F_67 ( V_45 ) ;
}
}
F_15 ( & V_8 -> V_39 ) ;
return V_134 ;
}
static bool
F_87 ( struct V_22 * V_23 ,
struct V_5 * V_8 )
{
struct V_1 * V_40 ;
struct V_41 * V_42 ;
bool V_135 = false ;
unsigned long V_62 ;
struct V_43 * V_38 ;
F_10 ( & V_8 -> V_39 ) ;
F_33 (neigh_node, node_tmp,
&orig_node->neigh_list, list) {
V_62 = V_42 -> V_62 ;
V_38 = V_42 -> V_38 ;
if ( ( F_88 ( V_62 , V_136 ) ) ||
( V_38 -> V_94 == V_131 ) ||
( V_38 -> V_94 == V_132 ) ||
( V_38 -> V_94 == V_133 ) ) {
if ( ( V_38 -> V_94 == V_131 ) ||
( V_38 -> V_94 == V_132 ) ||
( V_38 -> V_94 == V_133 ) )
F_51 ( V_67 , V_23 ,
L_7 ,
V_8 -> V_61 , V_42 -> V_56 ,
V_38 -> V_68 -> V_69 ) ;
else
F_51 ( V_67 , V_23 ,
L_8 ,
V_8 -> V_61 , V_42 -> V_56 ,
F_89 ( V_62 ) ) ;
V_135 = true ;
F_73 ( & V_42 -> V_16 ) ;
F_34 ( V_42 ) ;
} else {
F_85 ( V_23 , V_42 ) ;
}
}
F_15 ( & V_8 -> V_39 ) ;
return V_135 ;
}
static struct V_41 *
F_90 ( struct V_22 * V_23 ,
struct V_5 * V_8 ,
struct V_43 * V_34 )
{
struct V_41 * V_137 = NULL , * V_52 ;
struct V_138 * V_139 = V_23 -> V_63 ;
F_5 () ;
F_6 (neigh, &orig_node->neigh_list, list) {
if ( V_137 && ( V_139 -> V_52 . V_140 ( V_52 , V_34 , V_137 ,
V_34 ) <= 0 ) )
continue;
if ( ! F_7 ( & V_52 -> V_12 ) )
continue;
if ( V_137 )
F_34 ( V_137 ) ;
V_137 = V_52 ;
}
F_8 () ;
return V_137 ;
}
static bool F_91 ( struct V_22 * V_23 ,
struct V_5 * V_8 )
{
struct V_41 * V_141 ;
struct V_43 * V_55 ;
bool V_142 , V_143 ;
if ( F_88 ( V_8 -> V_62 ,
2 * V_136 ) ) {
F_51 ( V_67 , V_23 ,
L_9 ,
V_8 -> V_61 ,
F_89 ( V_8 -> V_62 ) ) ;
return true ;
}
V_142 = F_86 ( V_23 , V_8 ) ;
V_143 = F_87 ( V_23 , V_8 ) ;
if ( ! V_142 && ! V_143 )
return false ;
V_141 = F_90 ( V_23 , V_8 ,
V_35 ) ;
F_92 ( V_23 , V_8 , V_35 ,
V_141 ) ;
if ( V_141 )
F_34 ( V_141 ) ;
F_5 () ;
F_93 (hard_iface, &batadv_hardif_list, list) {
if ( V_55 -> V_94 != V_95 )
continue;
if ( V_55 -> V_60 != V_23 -> V_60 )
continue;
if ( ! F_7 ( & V_55 -> V_12 ) )
continue;
V_141 = F_90 ( V_23 ,
V_8 ,
V_55 ) ;
F_92 ( V_23 , V_8 , V_55 ,
V_141 ) ;
if ( V_141 )
F_34 ( V_141 ) ;
F_27 ( V_55 ) ;
}
F_8 () ;
return false ;
}
static void F_94 ( struct V_22 * V_23 )
{
struct V_105 * V_106 = V_23 -> V_24 ;
struct V_1 * V_40 ;
struct V_107 * V_108 ;
T_2 * V_109 ;
struct V_5 * V_8 ;
T_3 V_110 ;
if ( ! V_106 )
return;
for ( V_110 = 0 ; V_110 < V_106 -> V_111 ; V_110 ++ ) {
V_108 = & V_106 -> V_112 [ V_110 ] ;
V_109 = & V_106 -> V_113 [ V_110 ] ;
F_10 ( V_109 ) ;
F_33 (orig_node, node_tmp,
head, hash_entry) {
if ( F_91 ( V_23 , V_8 ) ) {
F_95 ( V_23 , V_8 ) ;
F_73 ( & V_8 -> V_6 ) ;
F_96 ( V_8 -> V_23 ,
V_8 , - 1 ,
L_10 ) ;
F_76 ( V_8 ) ;
continue;
}
F_70 ( V_8 ,
V_144 ) ;
}
F_15 ( V_109 ) ;
}
F_97 ( V_23 ) ;
}
static void V_28 ( struct V_145 * V_146 )
{
struct V_147 * V_147 ;
struct V_22 * V_23 ;
V_147 = F_98 ( V_146 ) ;
V_23 = F_2 ( V_147 , struct V_22 , V_27 ) ;
F_94 ( V_23 ) ;
F_24 ( V_29 ,
& V_23 -> V_27 ,
F_25 ( V_30 ) ) ;
}
void F_99 ( struct V_22 * V_23 )
{
F_94 ( V_23 ) ;
}
int F_100 ( struct V_70 * V_71 , void * V_72 )
{
struct V_73 * V_68 = (struct V_73 * ) V_71 -> V_74 ;
struct V_22 * V_23 = F_44 ( V_68 ) ;
struct V_43 * V_75 ;
V_75 = F_54 ( V_71 ) ;
if ( ! V_75 )
return 0 ;
F_55 ( V_71 , L_2 ,
V_76 , V_75 -> V_68 -> V_69 ,
V_75 -> V_68 -> V_77 , V_68 -> V_69 ,
V_23 -> V_63 -> V_69 ) ;
F_27 ( V_75 ) ;
if ( ! V_23 -> V_63 -> V_61 . V_78 ) {
F_56 ( V_71 ,
L_3 ) ;
return 0 ;
}
V_23 -> V_63 -> V_61 . V_78 ( V_23 , V_71 , V_35 ) ;
return 0 ;
}
int F_101 ( struct V_70 * V_71 , void * V_72 )
{
struct V_73 * V_68 = (struct V_73 * ) V_71 -> V_74 ;
struct V_43 * V_55 ;
struct V_22 * V_23 ;
V_55 = F_63 ( V_68 ) ;
if ( ! V_55 || ! V_55 -> V_60 ) {
F_56 ( V_71 , L_11 ) ;
goto V_14;
}
V_23 = F_44 ( V_55 -> V_60 ) ;
if ( ! V_23 -> V_63 -> V_61 . V_78 ) {
F_56 ( V_71 ,
L_3 ) ;
goto V_14;
}
if ( V_55 -> V_94 != V_95 ) {
F_56 ( V_71 , L_12 ) ;
goto V_14;
}
F_55 ( V_71 , L_13 ,
V_76 , V_55 -> V_68 -> V_69 ,
V_55 -> V_68 -> V_77 ,
V_55 -> V_60 -> V_69 , V_23 -> V_63 -> V_69 ) ;
V_23 -> V_63 -> V_61 . V_78 ( V_23 , V_71 , V_55 ) ;
V_14:
if ( V_55 )
F_27 ( V_55 ) ;
return 0 ;
}
int F_102 ( struct V_79 * V_80 , struct V_81 * V_82 )
{
struct V_83 * V_83 = F_58 ( V_82 -> V_84 -> V_85 ) ;
struct V_73 * V_60 ;
struct V_73 * V_55 = NULL ;
struct V_43 * V_86 = V_35 ;
struct V_22 * V_23 ;
struct V_43 * V_75 = NULL ;
int V_87 ;
int V_88 , V_89 ;
V_88 = F_59 ( V_82 -> V_90 , V_91 ) ;
if ( ! V_88 )
return - V_92 ;
V_60 = F_60 ( V_83 , V_88 ) ;
if ( ! V_60 || ! F_61 ( V_60 ) ) {
V_87 = - V_93 ;
goto V_14;
}
V_23 = F_44 ( V_60 ) ;
V_75 = F_62 ( V_23 ) ;
if ( ! V_75 || V_75 -> V_94 != V_95 ) {
V_87 = - V_96 ;
goto V_14;
}
V_89 = F_59 ( V_82 -> V_90 ,
V_97 ) ;
if ( V_89 ) {
V_55 = F_60 ( V_83 , V_89 ) ;
if ( V_55 )
V_86 = F_63 ( V_55 ) ;
if ( ! V_86 ) {
V_87 = - V_93 ;
goto V_14;
}
if ( V_86 -> V_60 != V_60 ) {
V_87 = - V_96 ;
goto V_14;
}
}
if ( ! V_23 -> V_63 -> V_61 . V_98 ) {
V_87 = - V_99 ;
goto V_14;
}
V_23 -> V_63 -> V_61 . V_98 ( V_80 , V_82 , V_23 , V_86 ) ;
V_87 = V_80 -> V_100 ;
V_14:
if ( V_86 )
F_27 ( V_86 ) ;
if ( V_55 )
F_64 ( V_55 ) ;
if ( V_75 )
F_27 ( V_75 ) ;
if ( V_60 )
F_64 ( V_60 ) ;
return V_87 ;
}
int F_103 ( struct V_43 * V_55 ,
int V_148 )
{
struct V_22 * V_23 = F_44 ( V_55 -> V_60 ) ;
struct V_138 * V_139 = V_23 -> V_63 ;
struct V_105 * V_106 = V_23 -> V_24 ;
struct V_107 * V_108 ;
struct V_5 * V_8 ;
T_3 V_110 ;
int V_87 ;
for ( V_110 = 0 ; V_110 < V_106 -> V_111 ; V_110 ++ ) {
V_108 = & V_106 -> V_112 [ V_110 ] ;
F_5 () ;
F_6 (orig_node, head, hash_entry) {
V_87 = 0 ;
if ( V_139 -> V_61 . V_149 )
V_87 = V_139 -> V_61 . V_149 ( V_8 , V_148 ) ;
if ( V_87 == - V_31 )
goto V_25;
}
F_8 () ;
}
return 0 ;
V_25:
F_8 () ;
return - V_31 ;
}
int F_104 ( struct V_43 * V_55 ,
int V_148 )
{
struct V_22 * V_23 = F_44 ( V_55 -> V_60 ) ;
struct V_105 * V_106 = V_23 -> V_24 ;
struct V_107 * V_108 ;
struct V_43 * V_150 ;
struct V_5 * V_8 ;
struct V_138 * V_139 = V_23 -> V_63 ;
T_3 V_110 ;
int V_87 ;
for ( V_110 = 0 ; V_110 < V_106 -> V_111 ; V_110 ++ ) {
V_108 = & V_106 -> V_112 [ V_110 ] ;
F_5 () ;
F_6 (orig_node, head, hash_entry) {
V_87 = 0 ;
if ( V_139 -> V_61 . V_151 )
V_87 = V_139 -> V_61 . V_151 ( V_8 , V_148 ,
V_55 -> V_152 ) ;
if ( V_87 == - V_31 )
goto V_25;
}
F_8 () ;
}
F_5 () ;
F_93 (hard_iface_tmp, &batadv_hardif_list, list) {
if ( V_150 -> V_94 == V_132 )
continue;
if ( V_55 == V_150 )
continue;
if ( V_55 -> V_60 != V_150 -> V_60 )
continue;
if ( V_150 -> V_152 > V_55 -> V_152 )
V_150 -> V_152 -- ;
}
F_8 () ;
V_55 -> V_152 = - 1 ;
return 0 ;
V_25:
F_8 () ;
return - V_31 ;
}

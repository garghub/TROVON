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
static void F_24 ( struct V_30 * V_19 )
{
struct V_31 * V_32 ;
V_32 = F_2 ( V_19 , struct V_31 , V_19 ) ;
if ( V_32 -> V_33 != V_34 )
F_25 ( V_32 -> V_33 ) ;
F_26 ( V_32 ) ;
}
static void
F_27 ( struct V_31 * V_32 )
{
if ( F_16 ( & V_32 -> V_12 ) )
F_24 ( & V_32 -> V_19 ) ;
}
void F_28 ( struct V_31 * V_32 )
{
if ( F_16 ( & V_32 -> V_12 ) )
F_29 ( & V_32 -> V_19 , F_24 ) ;
}
static void F_30 ( struct V_30 * V_19 )
{
struct V_1 * V_35 ;
struct V_36 * V_37 ;
struct V_31 * V_32 ;
struct V_38 * V_39 ;
V_37 = F_2 ( V_19 , struct V_36 , V_19 ) ;
V_39 = V_37 -> V_8 -> V_21 -> V_40 ;
F_31 (neigh_ifinfo, node_tmp,
&neigh_node->ifinfo_list, list) {
F_27 ( V_32 ) ;
}
if ( V_39 -> V_41 )
V_39 -> V_41 ( V_37 ) ;
F_25 ( V_37 -> V_42 ) ;
F_26 ( V_37 ) ;
}
static void
F_32 ( struct V_36 * V_37 )
{
if ( F_16 ( & V_37 -> V_12 ) )
F_30 ( & V_37 -> V_19 ) ;
}
void F_33 ( struct V_36 * V_37 )
{
if ( F_16 ( & V_37 -> V_12 ) )
F_29 ( & V_37 -> V_19 , F_30 ) ;
}
struct V_36 *
F_34 ( struct V_5 * V_8 ,
const struct V_43 * V_33 )
{
struct V_44 * V_45 ;
struct V_36 * V_46 = NULL ;
F_5 () ;
F_6 (orig_ifinfo, &orig_node->ifinfo_list, list) {
if ( V_45 -> V_33 != V_33 )
continue;
V_46 = F_35 ( V_45 -> V_46 ) ;
break;
}
if ( V_46 && ! F_7 ( & V_46 -> V_12 ) )
V_46 = NULL ;
F_8 () ;
return V_46 ;
}
struct V_44 *
F_36 ( struct V_5 * V_8 ,
struct V_43 * V_33 )
{
struct V_44 * V_11 , * V_45 = NULL ;
F_5 () ;
F_6 (tmp, &orig_node->ifinfo_list,
list) {
if ( V_11 -> V_33 != V_33 )
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
F_37 ( struct V_5 * V_8 ,
struct V_43 * V_33 )
{
struct V_44 * V_45 = NULL ;
unsigned long V_47 ;
F_10 ( & V_8 -> V_48 ) ;
V_45 = F_36 ( V_8 , V_33 ) ;
if ( V_45 )
goto V_14;
V_45 = F_11 ( sizeof( * V_45 ) , V_15 ) ;
if ( ! V_45 )
goto V_14;
if ( V_33 != V_34 &&
! F_7 ( & V_33 -> V_12 ) ) {
F_26 ( V_45 ) ;
V_45 = NULL ;
goto V_14;
}
V_47 = V_49 - 1 ;
V_47 -= F_23 ( V_50 ) ;
V_45 -> V_51 = V_47 ;
V_45 -> V_33 = V_33 ;
F_38 ( & V_45 -> V_16 ) ;
F_12 ( & V_45 -> V_12 , 2 ) ;
F_13 ( & V_45 -> V_16 ,
& V_8 -> V_52 ) ;
V_14:
F_14 ( & V_8 -> V_48 ) ;
return V_45 ;
}
struct V_31 *
F_39 ( struct V_36 * V_53 ,
struct V_43 * V_33 )
{
struct V_31 * V_32 = NULL ,
* V_54 ;
F_5 () ;
F_6 (tmp_neigh_ifinfo, &neigh->ifinfo_list,
list) {
if ( V_54 -> V_33 != V_33 )
continue;
if ( ! F_7 ( & V_54 -> V_12 ) )
continue;
V_32 = V_54 ;
break;
}
F_8 () ;
return V_32 ;
}
struct V_31 *
F_40 ( struct V_36 * V_53 ,
struct V_43 * V_33 )
{
struct V_31 * V_32 ;
F_10 ( & V_53 -> V_55 ) ;
V_32 = F_39 ( V_53 , V_33 ) ;
if ( V_32 )
goto V_14;
V_32 = F_11 ( sizeof( * V_32 ) , V_15 ) ;
if ( ! V_32 )
goto V_14;
if ( V_33 && ! F_7 ( & V_33 -> V_12 ) ) {
F_26 ( V_32 ) ;
V_32 = NULL ;
goto V_14;
}
F_38 ( & V_32 -> V_16 ) ;
F_12 ( & V_32 -> V_12 , 2 ) ;
V_32 -> V_33 = V_33 ;
F_13 ( & V_32 -> V_16 , & V_53 -> V_52 ) ;
V_14:
F_14 ( & V_53 -> V_55 ) ;
return V_32 ;
}
static struct V_36 *
F_41 ( const struct V_5 * V_8 ,
const struct V_43 * V_56 ,
const T_1 * V_57 )
{
struct V_36 * V_58 , * V_59 = NULL ;
F_5 () ;
F_6 (tmp_neigh_node, &orig_node->neigh_list, list) {
if ( ! F_3 ( V_58 -> V_57 , V_57 ) )
continue;
if ( V_58 -> V_42 != V_56 )
continue;
if ( ! F_7 ( & V_58 -> V_12 ) )
continue;
V_59 = V_58 ;
break;
}
F_8 () ;
return V_59 ;
}
struct V_36 *
F_42 ( struct V_5 * V_8 ,
struct V_43 * V_56 ,
const T_1 * V_60 )
{
struct V_36 * V_37 ;
V_37 = F_41 ( V_8 , V_56 , V_60 ) ;
if ( V_37 )
goto V_14;
V_37 = F_11 ( sizeof( * V_37 ) , V_15 ) ;
if ( ! V_37 )
goto V_14;
if ( ! F_7 ( & V_56 -> V_12 ) ) {
F_26 ( V_37 ) ;
V_37 = NULL ;
goto V_14;
}
F_38 ( & V_37 -> V_16 ) ;
F_43 ( & V_37 -> V_52 ) ;
F_44 ( & V_37 -> V_55 ) ;
F_45 ( V_37 -> V_57 , V_60 ) ;
V_37 -> V_42 = V_56 ;
V_37 -> V_8 = V_8 ;
F_12 ( & V_37 -> V_12 , 2 ) ;
F_10 ( & V_8 -> V_48 ) ;
F_13 ( & V_37 -> V_16 , & V_8 -> V_61 ) ;
F_14 ( & V_8 -> V_48 ) ;
F_46 ( V_62 , V_8 -> V_21 ,
L_1 ,
V_60 , V_8 -> V_63 , V_56 -> V_64 -> V_65 ) ;
V_14:
return V_37 ;
}
static void F_47 ( struct V_30 * V_19 )
{
struct V_44 * V_45 ;
struct V_36 * V_46 ;
V_45 = F_2 ( V_19 , struct V_44 , V_19 ) ;
if ( V_45 -> V_33 != V_34 )
F_25 ( V_45 -> V_33 ) ;
V_46 = F_48 ( V_45 -> V_46 , true ) ;
if ( V_46 )
F_32 ( V_46 ) ;
F_26 ( V_45 ) ;
}
static void
F_49 ( struct V_44 * V_45 )
{
if ( F_16 ( & V_45 -> V_12 ) )
F_47 ( & V_45 -> V_19 ) ;
}
void F_50 ( struct V_44 * V_45 )
{
if ( F_16 ( & V_45 -> V_12 ) )
F_29 ( & V_45 -> V_19 , F_47 ) ;
}
static void F_51 ( struct V_30 * V_19 )
{
struct V_1 * V_35 ;
struct V_36 * V_37 ;
struct V_5 * V_8 ;
struct V_44 * V_45 ;
V_8 = F_2 ( V_19 , struct V_5 , V_19 ) ;
F_10 ( & V_8 -> V_48 ) ;
F_31 (neigh_node, node_tmp,
&orig_node->neigh_list, list) {
F_52 ( & V_37 -> V_16 ) ;
F_32 ( V_37 ) ;
}
F_31 (orig_ifinfo, node_tmp,
&orig_node->ifinfo_list, list) {
F_52 ( & V_45 -> V_16 ) ;
F_49 ( V_45 ) ;
}
F_14 ( & V_8 -> V_48 ) ;
F_53 ( V_8 ) ;
F_54 ( V_8 -> V_21 , V_8 , NULL ) ;
F_55 ( V_8 , NULL ) ;
if ( V_8 -> V_21 -> V_40 -> V_66 )
V_8 -> V_21 -> V_40 -> V_66 ( V_8 ) ;
F_26 ( V_8 -> V_67 ) ;
F_26 ( V_8 ) ;
}
void F_56 ( struct V_5 * V_8 )
{
if ( F_16 ( & V_8 -> V_12 ) )
F_29 ( & V_8 -> V_19 , F_51 ) ;
}
void F_57 ( struct V_5 * V_8 )
{
if ( F_16 ( & V_8 -> V_12 ) )
F_51 ( & V_8 -> V_19 ) ;
}
void F_58 ( struct V_20 * V_21 )
{
struct V_68 * V_69 = V_21 -> V_22 ;
struct V_1 * V_35 ;
struct V_70 * V_71 ;
T_2 * V_72 ;
struct V_5 * V_8 ;
T_3 V_73 ;
if ( ! V_69 )
return;
F_59 ( & V_21 -> V_25 ) ;
V_21 -> V_22 = NULL ;
for ( V_73 = 0 ; V_73 < V_69 -> V_74 ; V_73 ++ ) {
V_71 = & V_69 -> V_75 [ V_73 ] ;
V_72 = & V_69 -> V_76 [ V_73 ] ;
F_10 ( V_72 ) ;
F_31 (orig_node, node_tmp,
head, hash_entry) {
F_52 ( & V_8 -> V_6 ) ;
F_56 ( V_8 ) ;
}
F_14 ( V_72 ) ;
}
F_60 ( V_69 ) ;
}
struct V_5 * F_61 ( struct V_20 * V_21 ,
const T_1 * V_57 )
{
struct V_5 * V_8 ;
struct V_7 * V_10 ;
unsigned long V_47 ;
int V_73 ;
F_46 ( V_62 , V_21 ,
L_2 , V_57 ) ;
V_8 = F_11 ( sizeof( * V_8 ) , V_15 ) ;
if ( ! V_8 )
return NULL ;
F_43 ( & V_8 -> V_61 ) ;
F_43 ( & V_8 -> V_17 ) ;
F_43 ( & V_8 -> V_52 ) ;
F_44 ( & V_8 -> V_77 ) ;
F_44 ( & V_8 -> V_48 ) ;
F_44 ( & V_8 -> V_78 ) ;
F_44 ( & V_8 -> V_79 ) ;
F_44 ( & V_8 -> V_13 ) ;
F_62 ( V_8 ) ;
F_12 ( & V_8 -> V_12 , 2 ) ;
V_8 -> V_21 = V_21 ;
F_45 ( V_8 -> V_63 , V_57 ) ;
F_63 ( V_8 ) ;
F_12 ( & V_8 -> V_80 , 0 ) ;
V_8 -> V_67 = NULL ;
V_8 -> V_81 = 0 ;
V_8 -> V_82 = V_49 ;
V_47 = V_49 - 1 - F_23 ( V_50 ) ;
V_8 -> V_83 = V_47 ;
#ifdef F_64
V_8 -> V_84 = V_85 ;
F_38 ( & V_8 -> V_86 ) ;
F_38 ( & V_8 -> V_87 ) ;
F_38 ( & V_8 -> V_88 ) ;
F_44 ( & V_8 -> V_89 ) ;
#endif
V_10 = F_9 ( V_8 , V_85 ) ;
if ( ! V_10 )
goto V_90;
F_15 ( V_10 ) ;
for ( V_73 = 0 ; V_73 < V_91 ; V_73 ++ ) {
F_43 ( & V_8 -> V_92 [ V_73 ] . V_71 ) ;
F_44 ( & V_8 -> V_92 [ V_73 ] . V_93 ) ;
V_8 -> V_92 [ V_73 ] . V_74 = 0 ;
}
return V_8 ;
V_90:
F_26 ( V_8 ) ;
return NULL ;
}
static void
F_65 ( struct V_20 * V_21 ,
struct V_36 * V_53 )
{
struct V_31 * V_32 ;
struct V_43 * V_33 ;
struct V_1 * V_35 ;
F_10 ( & V_53 -> V_55 ) ;
F_31 (neigh_ifinfo, node_tmp,
&neigh->ifinfo_list, list) {
V_33 = V_32 -> V_33 ;
if ( V_33 == V_34 )
continue;
if ( ( V_33 -> V_94 != V_95 ) &&
( V_33 -> V_94 != V_96 ) &&
( V_33 -> V_94 != V_97 ) )
continue;
F_46 ( V_62 , V_21 ,
L_3 ,
V_53 -> V_57 , V_33 -> V_64 -> V_65 ) ;
F_52 ( & V_32 -> V_16 ) ;
F_28 ( V_32 ) ;
}
F_14 ( & V_53 -> V_55 ) ;
}
static bool
F_66 ( struct V_20 * V_21 ,
struct V_5 * V_8 )
{
struct V_44 * V_45 ;
struct V_43 * V_33 ;
struct V_1 * V_35 ;
bool V_98 = false ;
F_10 ( & V_8 -> V_48 ) ;
F_31 (orig_ifinfo, node_tmp,
&orig_node->ifinfo_list, list) {
V_33 = V_45 -> V_33 ;
if ( V_33 == V_34 )
continue;
if ( ( V_33 -> V_94 != V_95 ) &&
( V_33 -> V_94 != V_96 ) &&
( V_33 -> V_94 != V_97 ) )
continue;
F_46 ( V_62 , V_21 ,
L_4 ,
V_8 -> V_63 , V_33 -> V_64 -> V_65 ) ;
V_98 = true ;
F_52 ( & V_45 -> V_16 ) ;
F_50 ( V_45 ) ;
if ( V_8 -> V_99 == V_45 ) {
V_8 -> V_99 = NULL ;
F_50 ( V_45 ) ;
}
}
F_14 ( & V_8 -> V_48 ) ;
return V_98 ;
}
static bool
F_67 ( struct V_20 * V_21 ,
struct V_5 * V_8 )
{
struct V_1 * V_35 ;
struct V_36 * V_37 ;
bool V_100 = false ;
unsigned long V_82 ;
struct V_43 * V_42 ;
F_10 ( & V_8 -> V_48 ) ;
F_31 (neigh_node, node_tmp,
&orig_node->neigh_list, list) {
V_82 = V_37 -> V_82 ;
V_42 = V_37 -> V_42 ;
if ( ( F_68 ( V_82 , V_101 ) ) ||
( V_42 -> V_94 == V_95 ) ||
( V_42 -> V_94 == V_96 ) ||
( V_42 -> V_94 == V_97 ) ) {
if ( ( V_42 -> V_94 == V_95 ) ||
( V_42 -> V_94 == V_96 ) ||
( V_42 -> V_94 == V_97 ) )
F_46 ( V_62 , V_21 ,
L_5 ,
V_8 -> V_63 , V_37 -> V_57 ,
V_42 -> V_64 -> V_65 ) ;
else
F_46 ( V_62 , V_21 ,
L_6 ,
V_8 -> V_63 , V_37 -> V_57 ,
F_69 ( V_82 ) ) ;
V_100 = true ;
F_52 ( & V_37 -> V_16 ) ;
F_33 ( V_37 ) ;
} else {
F_65 ( V_21 , V_37 ) ;
}
}
F_14 ( & V_8 -> V_48 ) ;
return V_100 ;
}
static struct V_36 *
F_70 ( struct V_20 * V_21 ,
struct V_5 * V_8 ,
struct V_43 * V_33 )
{
struct V_36 * V_102 = NULL , * V_53 ;
struct V_38 * V_39 = V_21 -> V_40 ;
F_5 () ;
F_6 (neigh, &orig_node->neigh_list, list) {
if ( V_102 && ( V_39 -> V_103 ( V_53 , V_33 ,
V_102 , V_33 ) <= 0 ) )
continue;
if ( ! F_7 ( & V_53 -> V_12 ) )
continue;
if ( V_102 )
F_33 ( V_102 ) ;
V_102 = V_53 ;
}
F_8 () ;
return V_102 ;
}
static bool F_71 ( struct V_20 * V_21 ,
struct V_5 * V_8 )
{
struct V_36 * V_104 ;
struct V_43 * V_56 ;
bool V_105 , V_106 ;
if ( F_68 ( V_8 -> V_82 ,
2 * V_101 ) ) {
F_46 ( V_62 , V_21 ,
L_7 ,
V_8 -> V_63 ,
F_69 ( V_8 -> V_82 ) ) ;
return true ;
}
V_105 = F_66 ( V_21 , V_8 ) ;
V_106 = F_67 ( V_21 , V_8 ) ;
if ( ! V_105 && ! V_106 )
return false ;
V_104 = F_70 ( V_21 , V_8 ,
V_34 ) ;
F_72 ( V_21 , V_8 , V_34 ,
V_104 ) ;
if ( V_104 )
F_33 ( V_104 ) ;
F_5 () ;
F_73 (hard_iface, &batadv_hardif_list, list) {
if ( V_56 -> V_94 != V_107 )
continue;
if ( V_56 -> V_108 != V_21 -> V_108 )
continue;
V_104 = F_70 ( V_21 ,
V_8 ,
V_56 ) ;
F_72 ( V_21 , V_8 , V_56 ,
V_104 ) ;
if ( V_104 )
F_33 ( V_104 ) ;
}
F_8 () ;
return false ;
}
static void F_74 ( struct V_20 * V_21 )
{
struct V_68 * V_69 = V_21 -> V_22 ;
struct V_1 * V_35 ;
struct V_70 * V_71 ;
T_2 * V_72 ;
struct V_5 * V_8 ;
T_3 V_73 ;
if ( ! V_69 )
return;
for ( V_73 = 0 ; V_73 < V_69 -> V_74 ; V_73 ++ ) {
V_71 = & V_69 -> V_75 [ V_73 ] ;
V_72 = & V_69 -> V_76 [ V_73 ] ;
F_10 ( V_72 ) ;
F_31 (orig_node, node_tmp,
head, hash_entry) {
if ( F_71 ( V_21 , V_8 ) ) {
F_75 ( V_21 , V_8 ) ;
F_52 ( & V_8 -> V_6 ) ;
F_76 ( V_8 -> V_21 ,
V_8 , - 1 ,
L_8 ) ;
F_56 ( V_8 ) ;
continue;
}
F_55 ( V_8 ,
V_109 ) ;
}
F_14 ( V_72 ) ;
}
F_77 ( V_21 ) ;
}
static void V_26 ( struct V_110 * V_111 )
{
struct V_112 * V_112 ;
struct V_20 * V_21 ;
V_112 = F_2 ( V_111 , struct V_112 , V_111 ) ;
V_21 = F_2 ( V_112 , struct V_20 , V_25 ) ;
F_74 ( V_21 ) ;
F_22 ( V_27 ,
& V_21 -> V_25 ,
F_23 ( V_28 ) ) ;
}
void F_78 ( struct V_20 * V_21 )
{
F_74 ( V_21 ) ;
}
int F_79 ( struct V_113 * V_114 , void * V_115 )
{
struct V_116 * V_64 = (struct V_116 * ) V_114 -> V_117 ;
struct V_20 * V_21 = F_80 ( V_64 ) ;
struct V_43 * V_118 ;
V_118 = F_81 ( V_114 ) ;
if ( ! V_118 )
return 0 ;
F_82 ( V_114 , L_9 ,
V_119 , V_118 -> V_64 -> V_65 ,
V_118 -> V_64 -> V_120 , V_64 -> V_65 ,
V_21 -> V_40 -> V_65 ) ;
F_83 ( V_118 ) ;
if ( ! V_21 -> V_40 -> V_121 ) {
F_84 ( V_114 ,
L_10 ) ;
return 0 ;
}
V_21 -> V_40 -> V_121 ( V_21 , V_114 ,
V_34 ) ;
return 0 ;
}
int F_85 ( struct V_113 * V_114 , void * V_115 )
{
struct V_116 * V_64 = (struct V_116 * ) V_114 -> V_117 ;
struct V_43 * V_56 ;
struct V_20 * V_21 ;
V_56 = F_86 ( V_64 ) ;
if ( ! V_56 || ! V_56 -> V_108 ) {
F_84 ( V_114 , L_11 ) ;
goto V_14;
}
V_21 = F_80 ( V_56 -> V_108 ) ;
if ( ! V_21 -> V_40 -> V_121 ) {
F_84 ( V_114 ,
L_10 ) ;
goto V_14;
}
if ( V_56 -> V_94 != V_107 ) {
F_84 ( V_114 , L_12 ) ;
goto V_14;
}
F_82 ( V_114 , L_13 ,
V_119 , V_56 -> V_64 -> V_65 ,
V_56 -> V_64 -> V_120 ,
V_56 -> V_108 -> V_65 , V_21 -> V_40 -> V_65 ) ;
V_21 -> V_40 -> V_121 ( V_21 , V_114 , V_56 ) ;
V_14:
if ( V_56 )
F_83 ( V_56 ) ;
return 0 ;
}
int F_87 ( struct V_43 * V_56 ,
int V_122 )
{
struct V_20 * V_21 = F_80 ( V_56 -> V_108 ) ;
struct V_38 * V_39 = V_21 -> V_40 ;
struct V_68 * V_69 = V_21 -> V_22 ;
struct V_70 * V_71 ;
struct V_5 * V_8 ;
T_3 V_73 ;
int V_123 ;
for ( V_73 = 0 ; V_73 < V_69 -> V_74 ; V_73 ++ ) {
V_71 = & V_69 -> V_75 [ V_73 ] ;
F_5 () ;
F_6 (orig_node, head, hash_entry) {
V_123 = 0 ;
if ( V_39 -> V_124 )
V_123 = V_39 -> V_124 ( V_8 ,
V_122 ) ;
if ( V_123 == - V_29 )
goto V_23;
}
F_8 () ;
}
return 0 ;
V_23:
F_8 () ;
return - V_29 ;
}
int F_88 ( struct V_43 * V_56 ,
int V_122 )
{
struct V_20 * V_21 = F_80 ( V_56 -> V_108 ) ;
struct V_68 * V_69 = V_21 -> V_22 ;
struct V_70 * V_71 ;
struct V_43 * V_125 ;
struct V_5 * V_8 ;
struct V_38 * V_39 = V_21 -> V_40 ;
T_3 V_73 ;
int V_123 ;
for ( V_73 = 0 ; V_73 < V_69 -> V_74 ; V_73 ++ ) {
V_71 = & V_69 -> V_75 [ V_73 ] ;
F_5 () ;
F_6 (orig_node, head, hash_entry) {
V_123 = 0 ;
if ( V_39 -> V_126 )
V_123 = V_39 -> V_126 ( V_8 ,
V_122 ,
V_56 -> V_127 ) ;
if ( V_123 == - V_29 )
goto V_23;
}
F_8 () ;
}
F_5 () ;
F_73 (hard_iface_tmp, &batadv_hardif_list, list) {
if ( V_125 -> V_94 == V_96 )
continue;
if ( V_56 == V_125 )
continue;
if ( V_56 -> V_108 != V_125 -> V_108 )
continue;
if ( V_125 -> V_127 > V_56 -> V_127 )
V_125 -> V_127 -- ;
}
F_8 () ;
V_56 -> V_127 = - 1 ;
return 0 ;
V_23:
F_8 () ;
return - V_29 ;
}

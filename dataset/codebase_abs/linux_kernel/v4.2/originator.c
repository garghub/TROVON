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
F_35 (orig_ifinfo, &orig_node->ifinfo_list, list) {
if ( V_45 -> V_33 != V_33 )
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
struct V_43 * V_33 )
{
struct V_44 * V_11 , * V_45 = NULL ;
F_5 () ;
F_35 (tmp, &orig_node->ifinfo_list,
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
F_38 ( struct V_5 * V_8 ,
struct V_43 * V_33 )
{
struct V_44 * V_45 = NULL ;
unsigned long V_47 ;
F_10 ( & V_8 -> V_48 ) ;
V_45 = F_37 ( V_8 , V_33 ) ;
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
F_39 ( & V_45 -> V_16 ) ;
F_12 ( & V_45 -> V_12 , 2 ) ;
F_40 ( & V_45 -> V_16 ,
& V_8 -> V_52 ) ;
V_14:
F_14 ( & V_8 -> V_48 ) ;
return V_45 ;
}
struct V_31 *
F_41 ( struct V_36 * V_53 ,
struct V_43 * V_33 )
{
struct V_31 * V_32 = NULL ,
* V_54 ;
F_5 () ;
F_35 (tmp_neigh_ifinfo, &neigh->ifinfo_list,
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
F_42 ( struct V_36 * V_53 ,
struct V_43 * V_33 )
{
struct V_31 * V_32 ;
F_10 ( & V_53 -> V_55 ) ;
V_32 = F_41 ( V_53 , V_33 ) ;
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
F_39 ( & V_32 -> V_16 ) ;
F_12 ( & V_32 -> V_12 , 2 ) ;
V_32 -> V_33 = V_33 ;
F_40 ( & V_32 -> V_16 , & V_53 -> V_52 ) ;
V_14:
F_14 ( & V_53 -> V_55 ) ;
return V_32 ;
}
struct V_36 *
F_43 ( struct V_43 * V_56 ,
const T_1 * V_57 ,
struct V_5 * V_8 )
{
struct V_36 * V_37 ;
V_37 = F_11 ( sizeof( * V_37 ) , V_15 ) ;
if ( ! V_37 )
goto V_14;
F_39 ( & V_37 -> V_16 ) ;
F_44 ( & V_37 -> V_52 ) ;
F_45 ( & V_37 -> V_55 ) ;
F_46 ( V_37 -> V_58 , V_57 ) ;
V_37 -> V_42 = V_56 ;
V_37 -> V_8 = V_8 ;
F_12 ( & V_37 -> V_12 , 2 ) ;
V_14:
return V_37 ;
}
struct V_36 *
F_47 ( const struct V_5 * V_8 ,
const struct V_43 * V_56 ,
const T_1 * V_58 )
{
struct V_36 * V_59 , * V_60 = NULL ;
F_5 () ;
F_35 (tmp_neigh_node, &orig_node->neigh_list, list) {
if ( ! F_3 ( V_59 -> V_58 , V_58 ) )
continue;
if ( V_59 -> V_42 != V_56 )
continue;
if ( ! F_7 ( & V_59 -> V_12 ) )
continue;
V_60 = V_59 ;
break;
}
F_8 () ;
return V_60 ;
}
static void F_48 ( struct V_30 * V_19 )
{
struct V_44 * V_45 ;
struct V_36 * V_46 ;
V_45 = F_2 ( V_19 , struct V_44 , V_19 ) ;
if ( V_45 -> V_33 != V_34 )
F_25 ( V_45 -> V_33 ) ;
V_46 = F_49 ( V_45 -> V_46 , true ) ;
if ( V_46 )
F_32 ( V_46 ) ;
F_26 ( V_45 ) ;
}
static void
F_50 ( struct V_44 * V_45 )
{
if ( F_16 ( & V_45 -> V_12 ) )
F_48 ( & V_45 -> V_19 ) ;
}
void F_51 ( struct V_44 * V_45 )
{
if ( F_16 ( & V_45 -> V_12 ) )
F_29 ( & V_45 -> V_19 , F_48 ) ;
}
static void F_52 ( struct V_30 * V_19 )
{
struct V_1 * V_35 ;
struct V_36 * V_37 ;
struct V_5 * V_8 ;
struct V_44 * V_45 ;
V_8 = F_2 ( V_19 , struct V_5 , V_19 ) ;
F_10 ( & V_8 -> V_48 ) ;
F_31 (neigh_node, node_tmp,
&orig_node->neigh_list, list) {
F_53 ( & V_37 -> V_16 ) ;
F_32 ( V_37 ) ;
}
F_31 (orig_ifinfo, node_tmp,
&orig_node->ifinfo_list, list) {
F_53 ( & V_45 -> V_16 ) ;
F_50 ( V_45 ) ;
}
F_14 ( & V_8 -> V_48 ) ;
F_54 ( V_8 ) ;
F_55 ( V_8 -> V_21 , V_8 , NULL ) ;
F_56 ( V_8 , NULL ) ;
if ( V_8 -> V_21 -> V_40 -> V_61 )
V_8 -> V_21 -> V_40 -> V_61 ( V_8 ) ;
F_26 ( V_8 -> V_62 ) ;
F_26 ( V_8 ) ;
}
void F_57 ( struct V_5 * V_8 )
{
if ( F_16 ( & V_8 -> V_12 ) )
F_29 ( & V_8 -> V_19 , F_52 ) ;
}
void F_58 ( struct V_5 * V_8 )
{
if ( F_16 ( & V_8 -> V_12 ) )
F_52 ( & V_8 -> V_19 ) ;
}
void F_59 ( struct V_20 * V_21 )
{
struct V_63 * V_64 = V_21 -> V_22 ;
struct V_1 * V_35 ;
struct V_65 * V_66 ;
T_2 * V_67 ;
struct V_5 * V_8 ;
T_3 V_68 ;
if ( ! V_64 )
return;
F_60 ( & V_21 -> V_25 ) ;
V_21 -> V_22 = NULL ;
for ( V_68 = 0 ; V_68 < V_64 -> V_69 ; V_68 ++ ) {
V_66 = & V_64 -> V_70 [ V_68 ] ;
V_67 = & V_64 -> V_71 [ V_68 ] ;
F_10 ( V_67 ) ;
F_31 (orig_node, node_tmp,
head, hash_entry) {
F_53 ( & V_8 -> V_6 ) ;
F_57 ( V_8 ) ;
}
F_14 ( V_67 ) ;
}
F_61 ( V_64 ) ;
}
struct V_5 * F_62 ( struct V_20 * V_21 ,
const T_1 * V_58 )
{
struct V_5 * V_8 ;
struct V_7 * V_10 ;
unsigned long V_47 ;
int V_68 ;
F_63 ( V_72 , V_21 ,
L_1 , V_58 ) ;
V_8 = F_11 ( sizeof( * V_8 ) , V_15 ) ;
if ( ! V_8 )
return NULL ;
F_44 ( & V_8 -> V_73 ) ;
F_64 ( & V_8 -> V_17 ) ;
F_44 ( & V_8 -> V_52 ) ;
F_45 ( & V_8 -> V_74 ) ;
F_45 ( & V_8 -> V_48 ) ;
F_45 ( & V_8 -> V_75 ) ;
F_45 ( & V_8 -> V_76 ) ;
F_45 ( & V_8 -> V_13 ) ;
F_65 ( V_8 ) ;
F_12 ( & V_8 -> V_12 , 2 ) ;
V_8 -> V_21 = V_21 ;
F_46 ( V_8 -> V_77 , V_58 ) ;
F_66 ( V_8 ) ;
F_12 ( & V_8 -> V_78 , 0 ) ;
V_8 -> V_62 = NULL ;
V_8 -> V_79 = 0 ;
V_8 -> V_80 = V_49 ;
V_47 = V_49 - 1 - F_23 ( V_50 ) ;
V_8 -> V_81 = V_47 ;
#ifdef F_67
V_8 -> V_82 = V_83 ;
#endif
V_10 = F_9 ( V_8 , V_83 ) ;
if ( ! V_10 )
goto V_84;
F_15 ( V_10 ) ;
for ( V_68 = 0 ; V_68 < V_85 ; V_68 ++ ) {
F_44 ( & V_8 -> V_86 [ V_68 ] . V_66 ) ;
F_45 ( & V_8 -> V_86 [ V_68 ] . V_87 ) ;
V_8 -> V_86 [ V_68 ] . V_69 = 0 ;
}
return V_8 ;
V_84:
F_26 ( V_8 ) ;
return NULL ;
}
static void
F_68 ( struct V_20 * V_21 ,
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
if ( ( V_33 -> V_88 != V_89 ) &&
( V_33 -> V_88 != V_90 ) &&
( V_33 -> V_88 != V_91 ) )
continue;
F_63 ( V_72 , V_21 ,
L_2 ,
V_53 -> V_58 , V_33 -> V_92 -> V_93 ) ;
F_53 ( & V_32 -> V_16 ) ;
F_28 ( V_32 ) ;
}
F_14 ( & V_53 -> V_55 ) ;
}
static bool
F_69 ( struct V_20 * V_21 ,
struct V_5 * V_8 )
{
struct V_44 * V_45 ;
struct V_43 * V_33 ;
struct V_1 * V_35 ;
bool V_94 = false ;
F_10 ( & V_8 -> V_48 ) ;
F_31 (orig_ifinfo, node_tmp,
&orig_node->ifinfo_list, list) {
V_33 = V_45 -> V_33 ;
if ( V_33 == V_34 )
continue;
if ( ( V_33 -> V_88 != V_89 ) &&
( V_33 -> V_88 != V_90 ) &&
( V_33 -> V_88 != V_91 ) )
continue;
F_63 ( V_72 , V_21 ,
L_3 ,
V_8 -> V_77 , V_33 -> V_92 -> V_93 ) ;
V_94 = true ;
F_53 ( & V_45 -> V_16 ) ;
F_51 ( V_45 ) ;
if ( V_8 -> V_95 == V_45 ) {
V_8 -> V_95 = NULL ;
F_51 ( V_45 ) ;
}
}
F_14 ( & V_8 -> V_48 ) ;
return V_94 ;
}
static bool
F_70 ( struct V_20 * V_21 ,
struct V_5 * V_8 )
{
struct V_1 * V_35 ;
struct V_36 * V_37 ;
bool V_96 = false ;
unsigned long V_80 ;
struct V_43 * V_42 ;
F_10 ( & V_8 -> V_48 ) ;
F_31 (neigh_node, node_tmp,
&orig_node->neigh_list, list) {
V_80 = V_37 -> V_80 ;
V_42 = V_37 -> V_42 ;
if ( ( F_71 ( V_80 , V_97 ) ) ||
( V_42 -> V_88 == V_89 ) ||
( V_42 -> V_88 == V_90 ) ||
( V_42 -> V_88 == V_91 ) ) {
if ( ( V_42 -> V_88 == V_89 ) ||
( V_42 -> V_88 == V_90 ) ||
( V_42 -> V_88 == V_91 ) )
F_63 ( V_72 , V_21 ,
L_4 ,
V_8 -> V_77 , V_37 -> V_58 ,
V_42 -> V_92 -> V_93 ) ;
else
F_63 ( V_72 , V_21 ,
L_5 ,
V_8 -> V_77 , V_37 -> V_58 ,
F_72 ( V_80 ) ) ;
V_96 = true ;
F_53 ( & V_37 -> V_16 ) ;
F_33 ( V_37 ) ;
} else {
F_68 ( V_21 , V_37 ) ;
}
}
F_14 ( & V_8 -> V_48 ) ;
return V_96 ;
}
static struct V_36 *
F_73 ( struct V_20 * V_21 ,
struct V_5 * V_8 ,
struct V_43 * V_33 )
{
struct V_36 * V_98 = NULL , * V_53 ;
struct V_38 * V_39 = V_21 -> V_40 ;
F_5 () ;
F_35 (neigh, &orig_node->neigh_list, list) {
if ( V_98 && ( V_39 -> V_99 ( V_53 , V_33 ,
V_98 , V_33 ) <= 0 ) )
continue;
if ( ! F_7 ( & V_53 -> V_12 ) )
continue;
if ( V_98 )
F_33 ( V_98 ) ;
V_98 = V_53 ;
}
F_8 () ;
return V_98 ;
}
static bool F_74 ( struct V_20 * V_21 ,
struct V_5 * V_8 )
{
struct V_36 * V_100 ;
struct V_43 * V_56 ;
bool V_101 , V_102 ;
if ( F_71 ( V_8 -> V_80 ,
2 * V_97 ) ) {
F_63 ( V_72 , V_21 ,
L_6 ,
V_8 -> V_77 ,
F_72 ( V_8 -> V_80 ) ) ;
return true ;
}
V_101 = F_69 ( V_21 , V_8 ) ;
V_102 = F_70 ( V_21 , V_8 ) ;
if ( ! V_101 && ! V_102 )
return false ;
V_100 = F_73 ( V_21 , V_8 ,
V_34 ) ;
F_75 ( V_21 , V_8 , V_34 ,
V_100 ) ;
if ( V_100 )
F_33 ( V_100 ) ;
F_5 () ;
F_6 (hard_iface, &batadv_hardif_list, list) {
if ( V_56 -> V_88 != V_103 )
continue;
if ( V_56 -> V_104 != V_21 -> V_104 )
continue;
V_100 = F_73 ( V_21 ,
V_8 ,
V_56 ) ;
F_75 ( V_21 , V_8 , V_56 ,
V_100 ) ;
if ( V_100 )
F_33 ( V_100 ) ;
}
F_8 () ;
return false ;
}
static void F_76 ( struct V_20 * V_21 )
{
struct V_63 * V_64 = V_21 -> V_22 ;
struct V_1 * V_35 ;
struct V_65 * V_66 ;
T_2 * V_67 ;
struct V_5 * V_8 ;
T_3 V_68 ;
if ( ! V_64 )
return;
for ( V_68 = 0 ; V_68 < V_64 -> V_69 ; V_68 ++ ) {
V_66 = & V_64 -> V_70 [ V_68 ] ;
V_67 = & V_64 -> V_71 [ V_68 ] ;
F_10 ( V_67 ) ;
F_31 (orig_node, node_tmp,
head, hash_entry) {
if ( F_74 ( V_21 , V_8 ) ) {
F_77 ( V_21 , V_8 ) ;
F_53 ( & V_8 -> V_6 ) ;
F_78 ( V_8 -> V_21 ,
V_8 , - 1 ,
L_7 ) ;
F_57 ( V_8 ) ;
continue;
}
F_56 ( V_8 ,
V_105 ) ;
}
F_14 ( V_67 ) ;
}
F_79 ( V_21 ) ;
F_80 ( V_21 ) ;
}
static void V_26 ( struct V_106 * V_107 )
{
struct V_108 * V_108 ;
struct V_20 * V_21 ;
V_108 = F_2 ( V_107 , struct V_108 , V_107 ) ;
V_21 = F_2 ( V_108 , struct V_20 , V_25 ) ;
F_76 ( V_21 ) ;
F_22 ( V_27 ,
& V_21 -> V_25 ,
F_23 ( V_28 ) ) ;
}
void F_81 ( struct V_20 * V_21 )
{
F_76 ( V_21 ) ;
}
int F_82 ( struct V_109 * V_110 , void * V_111 )
{
struct V_112 * V_92 = (struct V_112 * ) V_110 -> V_113 ;
struct V_20 * V_21 = F_83 ( V_92 ) ;
struct V_43 * V_114 ;
V_114 = F_84 ( V_110 ) ;
if ( ! V_114 )
return 0 ;
F_85 ( V_110 , L_8 ,
V_115 , V_114 -> V_92 -> V_93 ,
V_114 -> V_92 -> V_116 , V_92 -> V_93 ,
V_21 -> V_40 -> V_93 ) ;
F_86 ( V_114 ) ;
if ( ! V_21 -> V_40 -> V_117 ) {
F_87 ( V_110 ,
L_9 ) ;
return 0 ;
}
V_21 -> V_40 -> V_117 ( V_21 , V_110 ,
V_34 ) ;
return 0 ;
}
int F_88 ( struct V_109 * V_110 , void * V_111 )
{
struct V_112 * V_92 = (struct V_112 * ) V_110 -> V_113 ;
struct V_43 * V_56 ;
struct V_20 * V_21 ;
V_56 = F_89 ( V_92 ) ;
if ( ! V_56 || ! V_56 -> V_104 ) {
F_87 ( V_110 , L_10 ) ;
goto V_14;
}
V_21 = F_83 ( V_56 -> V_104 ) ;
if ( ! V_21 -> V_40 -> V_117 ) {
F_87 ( V_110 ,
L_9 ) ;
goto V_14;
}
if ( V_56 -> V_88 != V_103 ) {
F_87 ( V_110 , L_11 ) ;
goto V_14;
}
F_85 ( V_110 , L_12 ,
V_115 , V_56 -> V_92 -> V_93 ,
V_56 -> V_92 -> V_116 ,
V_56 -> V_104 -> V_93 , V_21 -> V_40 -> V_93 ) ;
V_21 -> V_40 -> V_117 ( V_21 , V_110 , V_56 ) ;
V_14:
if ( V_56 )
F_86 ( V_56 ) ;
return 0 ;
}
int F_90 ( struct V_43 * V_56 ,
int V_118 )
{
struct V_20 * V_21 = F_83 ( V_56 -> V_104 ) ;
struct V_38 * V_39 = V_21 -> V_40 ;
struct V_63 * V_64 = V_21 -> V_22 ;
struct V_65 * V_66 ;
struct V_5 * V_8 ;
T_3 V_68 ;
int V_119 ;
for ( V_68 = 0 ; V_68 < V_64 -> V_69 ; V_68 ++ ) {
V_66 = & V_64 -> V_70 [ V_68 ] ;
F_5 () ;
F_35 (orig_node, head, hash_entry) {
V_119 = 0 ;
if ( V_39 -> V_120 )
V_119 = V_39 -> V_120 ( V_8 ,
V_118 ) ;
if ( V_119 == - V_29 )
goto V_23;
}
F_8 () ;
}
return 0 ;
V_23:
F_8 () ;
return - V_29 ;
}
int F_91 ( struct V_43 * V_56 ,
int V_118 )
{
struct V_20 * V_21 = F_83 ( V_56 -> V_104 ) ;
struct V_63 * V_64 = V_21 -> V_22 ;
struct V_65 * V_66 ;
struct V_43 * V_121 ;
struct V_5 * V_8 ;
struct V_38 * V_39 = V_21 -> V_40 ;
T_3 V_68 ;
int V_119 ;
for ( V_68 = 0 ; V_68 < V_64 -> V_69 ; V_68 ++ ) {
V_66 = & V_64 -> V_70 [ V_68 ] ;
F_5 () ;
F_35 (orig_node, head, hash_entry) {
V_119 = 0 ;
if ( V_39 -> V_122 )
V_119 = V_39 -> V_122 ( V_8 ,
V_118 ,
V_56 -> V_123 ) ;
if ( V_119 == - V_29 )
goto V_23;
}
F_8 () ;
}
F_5 () ;
F_6 (hard_iface_tmp, &batadv_hardif_list, list) {
if ( V_121 -> V_88 == V_90 )
continue;
if ( V_56 == V_121 )
continue;
if ( V_56 -> V_104 != V_121 -> V_104 )
continue;
if ( V_121 -> V_123 > V_56 -> V_123 )
V_121 -> V_123 -- ;
}
F_8 () ;
V_56 -> V_123 = - 1 ;
return 0 ;
V_23:
F_8 () ;
return - V_29 ;
}

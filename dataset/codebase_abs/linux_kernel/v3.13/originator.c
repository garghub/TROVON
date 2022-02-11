int F_1 ( const struct V_1 * V_2 , const void * V_3 )
{
const void * V_4 = F_2 ( V_2 , struct V_5 ,
V_6 ) ;
return ( memcmp ( V_4 , V_3 , V_7 ) == 0 ? 1 : 0 ) ;
}
struct V_8 *
F_3 ( struct V_5 * V_9 ,
unsigned short V_10 )
{
struct V_8 * V_11 = NULL , * V_12 ;
F_4 () ;
F_5 (tmp, &orig_node->vlan_list, list) {
if ( V_12 -> V_10 != V_10 )
continue;
if ( ! F_6 ( & V_12 -> V_13 ) )
continue;
V_11 = V_12 ;
break;
}
F_7 () ;
return V_11 ;
}
struct V_8 *
F_8 ( struct V_5 * V_9 ,
unsigned short V_10 )
{
struct V_8 * V_11 ;
F_9 ( & V_9 -> V_14 ) ;
V_11 = F_3 ( V_9 , V_10 ) ;
if ( V_11 )
goto V_15;
V_11 = F_10 ( sizeof( * V_11 ) , V_16 ) ;
if ( ! V_11 )
goto V_15;
F_11 ( & V_11 -> V_13 , 2 ) ;
V_11 -> V_10 = V_10 ;
F_12 ( & V_11 -> V_17 , & V_9 -> V_18 ) ;
V_15:
F_13 ( & V_9 -> V_14 ) ;
return V_11 ;
}
void F_14 ( struct V_8 * V_19 )
{
if ( F_15 ( & V_19 -> V_13 ) )
F_16 ( V_19 , V_20 ) ;
}
int F_17 ( struct V_21 * V_22 )
{
if ( V_22 -> V_23 )
return 0 ;
V_22 -> V_23 = F_18 ( 1024 ) ;
if ( ! V_22 -> V_23 )
goto V_24;
F_19 ( V_22 -> V_23 ,
& V_25 ) ;
F_20 ( & V_22 -> V_26 , V_27 ) ;
F_21 ( V_28 ,
& V_22 -> V_26 ,
F_22 ( V_29 ) ) ;
return 0 ;
V_24:
return - V_30 ;
}
void F_23 ( struct V_31 * V_32 )
{
if ( F_15 ( & V_32 -> V_13 ) )
F_16 ( V_32 , V_20 ) ;
}
struct V_31 *
F_24 ( struct V_5 * V_9 )
{
struct V_31 * V_33 ;
F_4 () ;
V_33 = F_25 ( V_9 -> V_33 ) ;
if ( V_33 && ! F_6 ( & V_33 -> V_13 ) )
V_33 = NULL ;
F_7 () ;
return V_33 ;
}
struct V_31 *
F_26 ( struct V_34 * V_35 ,
const T_1 * V_36 ,
struct V_5 * V_9 )
{
struct V_31 * V_32 ;
V_32 = F_10 ( sizeof( * V_32 ) , V_16 ) ;
if ( ! V_32 )
goto V_15;
F_27 ( & V_32 -> V_17 ) ;
memcpy ( V_32 -> V_37 , V_36 , V_7 ) ;
V_32 -> V_38 = V_35 ;
V_32 -> V_9 = V_9 ;
F_28 ( & V_32 -> V_39 ) ;
F_11 ( & V_32 -> V_13 , 2 ) ;
V_15:
return V_32 ;
}
static void F_29 ( struct V_40 * V_20 )
{
struct V_1 * V_41 ;
struct V_31 * V_32 , * V_42 ;
struct V_5 * V_9 ;
V_9 = F_2 ( V_20 , struct V_5 , V_20 ) ;
F_9 ( & V_9 -> V_43 ) ;
F_30 (neigh_node, tmp_neigh_node,
&orig_node->bond_list, bonding_list) {
F_31 ( & V_32 -> V_39 ) ;
F_23 ( V_32 ) ;
}
F_32 (neigh_node, node_tmp,
&orig_node->neigh_list, list) {
F_33 ( & V_32 -> V_17 ) ;
F_23 ( V_32 ) ;
}
F_13 ( & V_9 -> V_43 ) ;
F_34 ( V_9 -> V_22 , V_9 , NULL ) ;
F_35 ( V_9 , NULL ) ;
F_36 ( V_9 -> V_22 , V_9 , - 1 ,
L_1 ) ;
if ( V_9 -> V_22 -> V_44 -> V_45 )
V_9 -> V_22 -> V_44 -> V_45 ( V_9 ) ;
F_37 ( V_9 -> V_46 ) ;
F_37 ( V_9 ) ;
}
void F_38 ( struct V_5 * V_9 )
{
if ( F_15 ( & V_9 -> V_13 ) )
F_39 ( & V_9 -> V_20 , F_29 ) ;
}
void F_40 ( struct V_5 * V_9 )
{
if ( F_15 ( & V_9 -> V_13 ) )
F_29 ( & V_9 -> V_20 ) ;
}
void F_41 ( struct V_21 * V_22 )
{
struct V_47 * V_48 = V_22 -> V_23 ;
struct V_1 * V_41 ;
struct V_49 * V_50 ;
T_2 * V_51 ;
struct V_5 * V_9 ;
T_3 V_52 ;
if ( ! V_48 )
return;
F_42 ( & V_22 -> V_26 ) ;
V_22 -> V_23 = NULL ;
for ( V_52 = 0 ; V_52 < V_48 -> V_53 ; V_52 ++ ) {
V_50 = & V_48 -> V_54 [ V_52 ] ;
V_51 = & V_48 -> V_55 [ V_52 ] ;
F_9 ( V_51 ) ;
F_32 (orig_node, node_tmp,
head, hash_entry) {
F_33 ( & V_9 -> V_6 ) ;
F_38 ( V_9 ) ;
}
F_13 ( V_51 ) ;
}
F_43 ( V_48 ) ;
}
struct V_5 * F_44 ( struct V_21 * V_22 ,
const T_1 * V_37 )
{
struct V_5 * V_9 ;
struct V_8 * V_11 ;
unsigned long V_56 ;
int V_52 ;
F_45 ( V_57 , V_22 ,
L_2 , V_37 ) ;
V_9 = F_10 ( sizeof( * V_9 ) , V_16 ) ;
if ( ! V_9 )
return NULL ;
F_46 ( & V_9 -> V_58 ) ;
F_28 ( & V_9 -> V_59 ) ;
F_28 ( & V_9 -> V_18 ) ;
F_47 ( & V_9 -> V_60 ) ;
F_47 ( & V_9 -> V_43 ) ;
F_47 ( & V_9 -> V_61 ) ;
F_47 ( & V_9 -> V_62 ) ;
F_47 ( & V_9 -> V_14 ) ;
F_48 ( V_9 ) ;
F_11 ( & V_9 -> V_13 , 2 ) ;
V_9 -> V_63 = false ;
V_9 -> V_22 = V_22 ;
memcpy ( V_9 -> V_64 , V_37 , V_7 ) ;
F_49 ( V_9 ) ;
V_9 -> V_33 = NULL ;
F_11 ( & V_9 -> V_65 , 0 ) ;
V_9 -> V_46 = NULL ;
V_9 -> V_66 = 0 ;
V_56 = V_67 - 1 - F_22 ( V_68 ) ;
V_9 -> V_69 = V_56 ;
V_9 -> V_70 = V_56 ;
F_11 ( & V_9 -> V_71 , 0 ) ;
V_11 = F_8 ( V_9 , V_72 ) ;
if ( ! V_11 )
goto V_73;
F_14 ( V_11 ) ;
for ( V_52 = 0 ; V_52 < V_74 ; V_52 ++ ) {
F_46 ( & V_9 -> V_75 [ V_52 ] . V_50 ) ;
F_47 ( & V_9 -> V_75 [ V_52 ] . V_76 ) ;
V_9 -> V_75 [ V_52 ] . V_53 = 0 ;
}
return V_9 ;
V_73:
F_37 ( V_9 ) ;
return NULL ;
}
static bool
F_50 ( struct V_21 * V_22 ,
struct V_5 * V_9 ,
struct V_31 * * V_77 )
{
struct V_78 * V_79 = V_22 -> V_44 ;
struct V_1 * V_41 ;
struct V_31 * V_32 ;
bool V_80 = false ;
unsigned long V_81 ;
struct V_34 * V_38 ;
* V_77 = NULL ;
F_9 ( & V_9 -> V_43 ) ;
F_32 (neigh_node, node_tmp,
&orig_node->neigh_list, list) {
V_81 = V_32 -> V_81 ;
V_38 = V_32 -> V_38 ;
if ( ( F_51 ( V_81 , V_82 ) ) ||
( V_38 -> V_83 == V_84 ) ||
( V_38 -> V_83 == V_85 ) ||
( V_38 -> V_83 == V_86 ) ) {
if ( ( V_38 -> V_83 == V_84 ) ||
( V_38 -> V_83 == V_85 ) ||
( V_38 -> V_83 == V_86 ) )
F_45 ( V_57 , V_22 ,
L_3 ,
V_9 -> V_64 , V_32 -> V_37 ,
V_38 -> V_87 -> V_88 ) ;
else
F_45 ( V_57 , V_22 ,
L_4 ,
V_9 -> V_64 , V_32 -> V_37 ,
F_52 ( V_81 ) ) ;
V_80 = true ;
F_33 ( & V_32 -> V_17 ) ;
F_53 ( V_9 , V_32 ) ;
F_23 ( V_32 ) ;
} else {
if ( ! * V_77 ||
V_79 -> V_89 ( V_32 , * V_77 ) > 0 )
* V_77 = V_32 ;
}
}
F_13 ( & V_9 -> V_43 ) ;
return V_80 ;
}
static bool F_54 ( struct V_21 * V_22 ,
struct V_5 * V_9 )
{
struct V_31 * V_90 ;
if ( F_51 ( V_9 -> V_81 ,
2 * V_82 ) ) {
F_45 ( V_57 , V_22 ,
L_5 ,
V_9 -> V_64 ,
F_52 ( V_9 -> V_81 ) ) ;
return true ;
} else {
if ( F_50 ( V_22 , V_9 ,
& V_90 ) )
F_55 ( V_22 , V_9 ,
V_90 ) ;
}
return false ;
}
static void F_56 ( struct V_21 * V_22 )
{
struct V_47 * V_48 = V_22 -> V_23 ;
struct V_1 * V_41 ;
struct V_49 * V_50 ;
T_2 * V_51 ;
struct V_5 * V_9 ;
T_3 V_52 ;
if ( ! V_48 )
return;
for ( V_52 = 0 ; V_52 < V_48 -> V_53 ; V_52 ++ ) {
V_50 = & V_48 -> V_54 [ V_52 ] ;
V_51 = & V_48 -> V_55 [ V_52 ] ;
F_9 ( V_51 ) ;
F_32 (orig_node, node_tmp,
head, hash_entry) {
if ( F_54 ( V_22 , V_9 ) ) {
F_57 ( V_22 , V_9 ) ;
F_33 ( & V_9 -> V_6 ) ;
F_38 ( V_9 ) ;
continue;
}
F_35 ( V_9 ,
V_91 ) ;
}
F_13 ( V_51 ) ;
}
F_58 ( V_22 ) ;
F_59 ( V_22 ) ;
}
static void V_27 ( struct V_92 * V_93 )
{
struct V_94 * V_94 ;
struct V_21 * V_22 ;
V_94 = F_2 ( V_93 , struct V_94 , V_93 ) ;
V_22 = F_2 ( V_94 , struct V_21 , V_26 ) ;
F_56 ( V_22 ) ;
F_21 ( V_28 ,
& V_22 -> V_26 ,
F_22 ( V_29 ) ) ;
}
void F_60 ( struct V_21 * V_22 )
{
F_56 ( V_22 ) ;
}
int F_61 ( struct V_95 * V_96 , void * V_97 )
{
struct V_98 * V_87 = (struct V_98 * ) V_96 -> V_99 ;
struct V_21 * V_22 = F_62 ( V_87 ) ;
struct V_34 * V_100 ;
V_100 = F_63 ( V_96 ) ;
if ( ! V_100 )
return 0 ;
F_64 ( V_96 , L_6 ,
V_101 , V_100 -> V_87 -> V_88 ,
V_100 -> V_87 -> V_102 , V_87 -> V_88 ,
V_22 -> V_44 -> V_88 ) ;
F_65 ( V_100 ) ;
if ( ! V_22 -> V_44 -> V_103 ) {
F_66 ( V_96 ,
L_7 ) ;
return 0 ;
}
V_22 -> V_44 -> V_103 ( V_22 , V_96 ) ;
return 0 ;
}
int F_67 ( struct V_34 * V_35 ,
int V_104 )
{
struct V_21 * V_22 = F_62 ( V_35 -> V_105 ) ;
struct V_78 * V_79 = V_22 -> V_44 ;
struct V_47 * V_48 = V_22 -> V_23 ;
struct V_49 * V_50 ;
struct V_5 * V_9 ;
T_3 V_52 ;
int V_106 ;
for ( V_52 = 0 ; V_52 < V_48 -> V_53 ; V_52 ++ ) {
V_50 = & V_48 -> V_54 [ V_52 ] ;
F_4 () ;
F_68 (orig_node, head, hash_entry) {
V_106 = 0 ;
if ( V_79 -> V_107 )
V_106 = V_79 -> V_107 ( V_9 ,
V_104 ) ;
if ( V_106 == - V_30 )
goto V_24;
}
F_7 () ;
}
return 0 ;
V_24:
F_7 () ;
return - V_30 ;
}
int F_69 ( struct V_34 * V_35 ,
int V_104 )
{
struct V_21 * V_22 = F_62 ( V_35 -> V_105 ) ;
struct V_47 * V_48 = V_22 -> V_23 ;
struct V_49 * V_50 ;
struct V_34 * V_108 ;
struct V_5 * V_9 ;
struct V_78 * V_79 = V_22 -> V_44 ;
T_3 V_52 ;
int V_106 ;
for ( V_52 = 0 ; V_52 < V_48 -> V_53 ; V_52 ++ ) {
V_50 = & V_48 -> V_54 [ V_52 ] ;
F_4 () ;
F_68 (orig_node, head, hash_entry) {
V_106 = 0 ;
if ( V_79 -> V_109 )
V_106 = V_79 -> V_109 ( V_9 ,
V_104 ,
V_35 -> V_110 ) ;
if ( V_106 == - V_30 )
goto V_24;
}
F_7 () ;
}
F_4 () ;
F_5 (hard_iface_tmp, &batadv_hardif_list, list) {
if ( V_108 -> V_83 == V_85 )
continue;
if ( V_35 == V_108 )
continue;
if ( V_35 -> V_105 != V_108 -> V_105 )
continue;
if ( V_108 -> V_110 > V_35 -> V_110 )
V_108 -> V_110 -- ;
}
F_7 () ;
V_35 -> V_110 = - 1 ;
return 0 ;
V_24:
F_7 () ;
return - V_30 ;
}

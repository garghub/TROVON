static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 , V_4 ) ;
F_3 ( V_5 ,
& V_2 -> V_3 , F_4 ( 1000 ) ) ;
}
static int F_5 ( const struct V_6 * V_7 , const void * V_8 )
{
const void * V_9 = F_6 ( V_7 , struct V_10 ,
V_11 ) ;
return ( memcmp ( V_9 , V_8 , V_12 ) == 0 ? 1 : 0 ) ;
}
int F_7 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 )
return 0 ;
V_2 -> V_13 = F_8 ( 1024 ) ;
if ( ! V_2 -> V_13 )
goto V_14;
F_1 ( V_2 ) ;
return 0 ;
V_14:
return - V_15 ;
}
void F_9 ( struct V_16 * V_17 )
{
if ( F_10 ( & V_17 -> V_18 ) )
F_11 ( V_17 , V_19 ) ;
}
struct V_16 *
F_12 ( struct V_10 * V_20 )
{
struct V_16 * V_21 ;
F_13 () ;
V_21 = F_14 ( V_20 -> V_21 ) ;
if ( V_21 && ! F_15 ( & V_21 -> V_18 ) )
V_21 = NULL ;
F_16 () ;
return V_21 ;
}
struct V_16 *
F_17 ( struct V_22 * V_23 ,
const T_1 * V_24 , T_2 V_25 )
{
struct V_1 * V_2 = F_18 ( V_23 -> V_26 ) ;
struct V_16 * V_17 ;
V_17 = F_19 ( sizeof( * V_17 ) , V_27 ) ;
if ( ! V_17 )
goto V_28;
F_20 ( & V_17 -> V_29 ) ;
memcpy ( V_17 -> V_30 , V_24 , V_12 ) ;
F_21 ( & V_17 -> V_31 ) ;
F_22 ( & V_17 -> V_18 , 2 ) ;
F_23 ( V_32 , V_2 ,
L_1 ,
V_24 , V_25 ) ;
V_28:
return V_17 ;
}
static void F_24 ( struct V_33 * V_19 )
{
struct V_6 * V_7 , * V_34 ;
struct V_16 * V_17 , * V_35 ;
struct V_10 * V_20 ;
V_20 = F_6 ( V_19 , struct V_10 , V_19 ) ;
F_25 ( & V_20 -> V_36 ) ;
F_26 (neigh_node, tmp_neigh_node,
&orig_node->bond_list, bonding_list) {
F_27 ( & V_17 -> V_37 ) ;
F_9 ( V_17 ) ;
}
F_28 (neigh_node, node, node_tmp,
&orig_node->neigh_list, list) {
F_29 ( & V_17 -> V_29 ) ;
F_9 ( V_17 ) ;
}
F_30 ( & V_20 -> V_36 ) ;
F_31 ( & V_20 -> V_38 ) ;
F_32 ( V_20 -> V_2 , V_20 ,
L_2 ) ;
F_33 ( V_20 -> V_39 ) ;
F_33 ( V_20 -> V_40 ) ;
F_33 ( V_20 -> V_41 ) ;
F_33 ( V_20 ) ;
}
void F_34 ( struct V_10 * V_20 )
{
if ( F_10 ( & V_20 -> V_18 ) )
F_35 ( & V_20 -> V_19 , F_24 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_13 ;
struct V_6 * V_7 , * V_34 ;
struct V_44 * V_45 ;
T_3 * V_46 ;
struct V_10 * V_20 ;
T_2 V_47 ;
if ( ! V_43 )
return;
F_37 ( & V_2 -> V_3 ) ;
V_2 -> V_13 = NULL ;
for ( V_47 = 0 ; V_47 < V_43 -> V_48 ; V_47 ++ ) {
V_45 = & V_43 -> V_49 [ V_47 ] ;
V_46 = & V_43 -> V_50 [ V_47 ] ;
F_25 ( V_46 ) ;
F_28 (orig_node, node, node_tmp,
head, hash_entry) {
F_29 ( V_7 ) ;
F_34 ( V_20 ) ;
}
F_30 ( V_46 ) ;
}
F_38 ( V_43 ) ;
}
struct V_10 * F_39 ( struct V_1 * V_2 ,
const T_1 * V_30 )
{
struct V_10 * V_20 ;
int V_48 ;
int V_51 ;
unsigned long V_52 ;
V_20 = F_40 ( V_2 , V_30 ) ;
if ( V_20 )
return V_20 ;
F_23 ( V_32 , V_2 ,
L_3 , V_30 ) ;
V_20 = F_19 ( sizeof( * V_20 ) , V_27 ) ;
if ( ! V_20 )
return NULL ;
F_41 ( & V_20 -> V_53 ) ;
F_42 ( & V_20 -> V_54 ) ;
F_21 ( & V_20 -> V_55 ) ;
F_21 ( & V_20 -> V_56 ) ;
F_21 ( & V_20 -> V_36 ) ;
F_21 ( & V_20 -> V_57 ) ;
F_22 ( & V_20 -> V_18 , 2 ) ;
V_20 -> V_58 = false ;
V_20 -> V_2 = V_2 ;
memcpy ( V_20 -> V_59 , V_30 , V_12 ) ;
F_43 ( V_20 ) ;
V_20 -> V_21 = NULL ;
V_20 -> V_60 = 0 ;
F_22 ( & V_20 -> V_61 , 0 ) ;
V_20 -> V_39 = NULL ;
V_20 -> V_62 = 0 ;
F_22 ( & V_20 -> V_63 , 0 ) ;
V_52 = V_64 - 1 - F_4 ( V_65 ) ;
V_20 -> V_66 = V_52 ;
V_20 -> V_67 = V_52 ;
F_22 ( & V_20 -> V_68 , 0 ) ;
V_48 = V_2 -> V_69 * sizeof( unsigned long ) * V_70 ;
V_20 -> V_40 = F_19 ( V_48 , V_27 ) ;
if ( ! V_20 -> V_40 )
goto V_71;
V_48 = V_2 -> V_69 * sizeof( T_1 ) ;
V_20 -> V_41 = F_19 ( V_48 , V_27 ) ;
F_42 ( & V_20 -> V_38 ) ;
V_20 -> V_72 = 0 ;
if ( ! V_20 -> V_41 )
goto V_73;
V_51 = F_44 ( V_2 -> V_13 , F_5 ,
V_74 , V_20 ,
& V_20 -> V_11 ) ;
if ( V_51 != 0 )
goto V_75;
return V_20 ;
V_75:
F_33 ( V_20 -> V_41 ) ;
V_73:
F_33 ( V_20 -> V_40 ) ;
V_71:
F_33 ( V_20 ) ;
return NULL ;
}
static bool
F_45 ( struct V_1 * V_2 ,
struct V_10 * V_20 ,
struct V_16 * * V_76 )
{
struct V_6 * V_7 , * V_34 ;
struct V_16 * V_17 ;
bool V_77 = false ;
unsigned long V_78 ;
struct V_22 * V_79 ;
* V_76 = NULL ;
F_25 ( & V_20 -> V_36 ) ;
F_28 (neigh_node, node, node_tmp,
&orig_node->neigh_list, list) {
V_78 = V_17 -> V_78 ;
V_79 = V_17 -> V_79 ;
if ( ( F_46 ( V_78 , V_80 ) ) ||
( V_79 -> V_81 == V_82 ) ||
( V_79 -> V_81 == V_83 ) ||
( V_79 -> V_81 == V_84 ) ) {
if ( ( V_79 -> V_81 == V_82 ) ||
( V_79 -> V_81 == V_83 ) ||
( V_79 -> V_81 == V_84 ) )
F_23 ( V_32 , V_2 ,
L_4 ,
V_20 -> V_59 , V_17 -> V_30 ,
V_79 -> V_85 -> V_86 ) ;
else
F_23 ( V_32 , V_2 ,
L_5 ,
V_20 -> V_59 , V_17 -> V_30 ,
F_47 ( V_78 ) ) ;
V_77 = true ;
F_29 ( & V_17 -> V_29 ) ;
F_48 ( V_20 , V_17 ) ;
F_9 ( V_17 ) ;
} else {
if ( ( ! * V_76 ) ||
( V_17 -> V_87 > ( * V_76 ) -> V_87 ) )
* V_76 = V_17 ;
}
}
F_30 ( & V_20 -> V_36 ) ;
return V_77 ;
}
static bool F_49 ( struct V_1 * V_2 ,
struct V_10 * V_20 )
{
struct V_16 * V_76 ;
if ( F_46 ( V_20 -> V_78 ,
2 * V_80 ) ) {
F_23 ( V_32 , V_2 ,
L_6 ,
V_20 -> V_59 ,
F_47 ( V_20 -> V_78 ) ) ;
return true ;
} else {
if ( F_45 ( V_2 , V_20 ,
& V_76 ) )
F_50 ( V_2 , V_20 ,
V_76 ) ;
}
return false ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_13 ;
struct V_6 * V_7 , * V_34 ;
struct V_44 * V_45 ;
T_3 * V_46 ;
struct V_10 * V_20 ;
T_2 V_47 ;
if ( ! V_43 )
return;
for ( V_47 = 0 ; V_47 < V_43 -> V_48 ; V_47 ++ ) {
V_45 = & V_43 -> V_49 [ V_47 ] ;
V_46 = & V_43 -> V_50 [ V_47 ] ;
F_25 ( V_46 ) ;
F_28 (orig_node, node, node_tmp,
head, hash_entry) {
if ( F_49 ( V_2 , V_20 ) ) {
if ( V_20 -> V_88 )
F_52 ( V_2 ,
V_20 ) ;
F_29 ( V_7 ) ;
F_34 ( V_20 ) ;
continue;
}
if ( F_46 ( V_20 -> V_72 ,
V_89 ) )
F_31 ( & V_20 -> V_38 ) ;
}
F_30 ( V_46 ) ;
}
F_53 ( V_2 ) ;
F_54 ( V_2 ) ;
}
static void V_4 ( struct V_90 * V_91 )
{
struct V_92 * V_92 ;
struct V_1 * V_2 ;
V_92 = F_6 ( V_91 , struct V_92 , V_91 ) ;
V_2 = F_6 ( V_92 , struct V_1 , V_3 ) ;
F_51 ( V_2 ) ;
F_1 ( V_2 ) ;
}
void F_55 ( struct V_1 * V_2 )
{
F_51 ( V_2 ) ;
}
int F_56 ( struct V_93 * V_94 , void * V_95 )
{
struct V_96 * V_85 = (struct V_96 * ) V_94 -> V_97 ;
struct V_1 * V_2 = F_18 ( V_85 ) ;
struct V_42 * V_43 = V_2 -> V_13 ;
struct V_6 * V_7 , * V_34 ;
struct V_44 * V_45 ;
struct V_22 * V_98 ;
struct V_10 * V_20 ;
struct V_16 * V_17 , * V_99 ;
int V_100 = 0 ;
int V_101 ;
int V_102 ;
unsigned long V_103 ;
T_2 V_47 ;
V_98 = F_57 ( V_94 ) ;
if ( ! V_98 )
goto V_28;
F_58 ( V_94 , L_7 ,
V_104 , V_98 -> V_85 -> V_86 ,
V_98 -> V_85 -> V_105 , V_85 -> V_86 ) ;
F_58 ( V_94 , L_8 ,
L_9 , L_10 , L_11 , V_106 ,
L_12 , L_13 , L_14 ) ;
for ( V_47 = 0 ; V_47 < V_43 -> V_48 ; V_47 ++ ) {
V_45 = & V_43 -> V_49 [ V_47 ] ;
F_13 () ;
F_59 (orig_node, node, head, hash_entry) {
V_17 = F_12 ( V_20 ) ;
if ( ! V_17 )
continue;
if ( V_17 -> V_87 == 0 )
goto V_107;
V_103 = V_64 - V_20 -> V_78 ;
V_102 = F_47 ( V_103 ) ;
V_101 = V_102 / 1000 ;
V_102 = V_102 % 1000 ;
F_58 ( V_94 , L_15 ,
V_20 -> V_59 , V_101 ,
V_102 , V_17 -> V_87 ,
V_17 -> V_30 ,
V_17 -> V_79 -> V_85 -> V_86 ) ;
F_59 (neigh_node_tmp, node_tmp,
&orig_node->neigh_list, list) {
F_58 ( V_94 , L_16 ,
V_99 -> V_30 ,
V_99 -> V_87 ) ;
}
F_58 ( V_94 , L_17 ) ;
V_100 ++ ;
V_107:
F_9 ( V_17 ) ;
}
F_16 () ;
}
if ( V_100 == 0 )
F_58 ( V_94 , L_18 ) ;
V_28:
if ( V_98 )
F_60 ( V_98 ) ;
return 0 ;
}
static int F_61 ( struct V_10 * V_20 ,
int V_108 )
{
void * V_109 ;
T_4 V_110 , V_111 ;
V_110 = V_108 * sizeof( unsigned long ) * V_70 ;
V_111 = ( V_108 - 1 ) * sizeof( unsigned long ) * V_70 ;
V_109 = F_62 ( V_110 , V_27 ) ;
if ( ! V_109 )
return - V_15 ;
memcpy ( V_109 , V_20 -> V_40 , V_111 ) ;
F_33 ( V_20 -> V_40 ) ;
V_20 -> V_40 = V_109 ;
V_109 = F_62 ( V_108 * sizeof( T_1 ) , V_27 ) ;
if ( ! V_109 )
return - V_15 ;
memcpy ( V_109 , V_20 -> V_41 ,
( V_108 - 1 ) * sizeof( T_1 ) ) ;
F_33 ( V_20 -> V_41 ) ;
V_20 -> V_41 = V_109 ;
return 0 ;
}
int F_63 ( struct V_22 * V_23 ,
int V_108 )
{
struct V_1 * V_2 = F_18 ( V_23 -> V_26 ) ;
struct V_42 * V_43 = V_2 -> V_13 ;
struct V_6 * V_7 ;
struct V_44 * V_45 ;
struct V_10 * V_20 ;
T_2 V_47 ;
int V_112 ;
for ( V_47 = 0 ; V_47 < V_43 -> V_48 ; V_47 ++ ) {
V_45 = & V_43 -> V_49 [ V_47 ] ;
F_13 () ;
F_59 (orig_node, node, head, hash_entry) {
F_25 ( & V_20 -> V_55 ) ;
V_112 = F_61 ( V_20 , V_108 ) ;
F_30 ( & V_20 -> V_55 ) ;
if ( V_112 == - V_15 )
goto V_14;
}
F_16 () ;
}
return 0 ;
V_14:
F_16 () ;
return - V_15 ;
}
static int F_64 ( struct V_10 * V_20 ,
int V_108 , int V_113 )
{
void * V_109 = NULL ;
int V_114 ;
if ( V_108 == 0 )
goto V_73;
V_114 = sizeof( unsigned long ) * V_70 ;
V_109 = F_62 ( V_108 * V_114 , V_27 ) ;
if ( ! V_109 )
return - V_15 ;
memcpy ( V_109 , V_20 -> V_40 , V_113 * V_114 ) ;
memcpy ( ( char * ) V_109 + V_113 * V_114 ,
V_20 -> V_40 + ( ( V_113 + 1 ) * V_114 ) ,
( V_108 - V_113 ) * V_114 ) ;
V_73:
F_33 ( V_20 -> V_40 ) ;
V_20 -> V_40 = V_109 ;
if ( V_108 == 0 )
goto V_115;
V_109 = F_62 ( V_108 * sizeof( T_1 ) , V_27 ) ;
if ( ! V_109 )
return - V_15 ;
memcpy ( V_109 , V_20 -> V_41 ,
V_113 * sizeof( T_1 ) ) ;
memcpy ( ( char * ) V_109 + V_113 * sizeof( T_1 ) ,
V_20 -> V_41 + ( ( V_113 + 1 ) * sizeof( T_1 ) ) ,
( V_108 - V_113 ) * sizeof( T_1 ) ) ;
V_115:
F_33 ( V_20 -> V_41 ) ;
V_20 -> V_41 = V_109 ;
return 0 ;
}
int F_65 ( struct V_22 * V_23 ,
int V_108 )
{
struct V_1 * V_2 = F_18 ( V_23 -> V_26 ) ;
struct V_42 * V_43 = V_2 -> V_13 ;
struct V_6 * V_7 ;
struct V_44 * V_45 ;
struct V_22 * V_116 ;
struct V_10 * V_20 ;
T_2 V_47 ;
int V_112 ;
for ( V_47 = 0 ; V_47 < V_43 -> V_48 ; V_47 ++ ) {
V_45 = & V_43 -> V_49 [ V_47 ] ;
F_13 () ;
F_59 (orig_node, node, head, hash_entry) {
F_25 ( & V_20 -> V_55 ) ;
V_112 = F_64 ( V_20 , V_108 ,
V_23 -> V_117 ) ;
F_30 ( & V_20 -> V_55 ) ;
if ( V_112 == - V_15 )
goto V_14;
}
F_16 () ;
}
F_13 () ;
F_66 (hard_iface_tmp, &batadv_hardif_list, list) {
if ( V_116 -> V_81 == V_83 )
continue;
if ( V_23 == V_116 )
continue;
if ( V_23 -> V_26 != V_116 -> V_26 )
continue;
if ( V_116 -> V_117 > V_23 -> V_117 )
V_116 -> V_117 -- ;
}
F_16 () ;
V_23 -> V_117 = - 1 ;
return 0 ;
V_14:
F_16 () ;
return - V_15 ;
}

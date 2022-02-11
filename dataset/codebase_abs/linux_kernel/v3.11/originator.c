static int F_1 ( const struct V_1 * V_2 , const void * V_3 )
{
const void * V_4 = F_2 ( V_2 , struct V_5 ,
V_6 ) ;
return ( memcmp ( V_4 , V_3 , V_7 ) == 0 ? 1 : 0 ) ;
}
int F_3 ( struct V_8 * V_9 )
{
if ( V_9 -> V_10 )
return 0 ;
V_9 -> V_10 = F_4 ( 1024 ) ;
if ( ! V_9 -> V_10 )
goto V_11;
F_5 ( V_9 -> V_10 ,
& V_12 ) ;
F_6 ( & V_9 -> V_13 , V_14 ) ;
F_7 ( V_15 ,
& V_9 -> V_13 ,
F_8 ( V_16 ) ) ;
return 0 ;
V_11:
return - V_17 ;
}
void F_9 ( struct V_18 * V_19 )
{
if ( F_10 ( & V_19 -> V_20 ) )
F_11 ( V_19 , V_21 ) ;
}
struct V_18 *
F_12 ( struct V_5 * V_22 )
{
struct V_18 * V_23 ;
F_13 () ;
V_23 = F_14 ( V_22 -> V_23 ) ;
if ( V_23 && ! F_15 ( & V_23 -> V_20 ) )
V_23 = NULL ;
F_16 () ;
return V_23 ;
}
struct V_18 *
F_17 ( struct V_24 * V_25 ,
const T_1 * V_26 )
{
struct V_8 * V_9 = F_18 ( V_25 -> V_27 ) ;
struct V_18 * V_19 ;
V_19 = F_19 ( sizeof( * V_19 ) , V_28 ) ;
if ( ! V_19 )
goto V_29;
F_20 ( & V_19 -> V_30 ) ;
memcpy ( V_19 -> V_31 , V_26 , V_7 ) ;
F_21 ( & V_19 -> V_32 ) ;
F_22 ( & V_19 -> V_20 , 2 ) ;
F_23 ( V_33 , V_9 ,
L_1 , V_26 ,
V_25 -> V_34 -> V_35 ) ;
V_29:
return V_19 ;
}
static void F_24 ( struct V_36 * V_21 )
{
struct V_1 * V_37 ;
struct V_18 * V_19 , * V_38 ;
struct V_5 * V_22 ;
V_22 = F_2 ( V_21 , struct V_5 , V_21 ) ;
F_25 ( & V_22 -> V_39 ) ;
F_26 (neigh_node, tmp_neigh_node,
&orig_node->bond_list, bonding_list) {
F_27 ( & V_19 -> V_40 ) ;
F_9 ( V_19 ) ;
}
F_28 (neigh_node, node_tmp,
&orig_node->neigh_list, list) {
F_29 ( & V_19 -> V_30 ) ;
F_9 ( V_19 ) ;
}
F_30 ( & V_22 -> V_39 ) ;
F_31 ( V_22 -> V_9 , V_22 , NULL ) ;
F_32 ( & V_22 -> V_41 ) ;
F_33 ( V_22 -> V_9 , V_22 ,
L_2 ) ;
F_34 ( V_22 -> V_42 ) ;
F_34 ( V_22 -> V_43 ) ;
F_34 ( V_22 -> V_44 ) ;
F_34 ( V_22 ) ;
}
void F_35 ( struct V_5 * V_22 )
{
if ( F_10 ( & V_22 -> V_20 ) )
F_36 ( & V_22 -> V_21 , F_24 ) ;
}
void F_37 ( struct V_5 * V_22 )
{
if ( F_10 ( & V_22 -> V_20 ) )
F_24 ( & V_22 -> V_21 ) ;
}
void F_38 ( struct V_8 * V_9 )
{
struct V_45 * V_46 = V_9 -> V_10 ;
struct V_1 * V_37 ;
struct V_47 * V_48 ;
T_2 * V_49 ;
struct V_5 * V_22 ;
T_3 V_50 ;
if ( ! V_46 )
return;
F_39 ( & V_9 -> V_13 ) ;
V_9 -> V_10 = NULL ;
for ( V_50 = 0 ; V_50 < V_46 -> V_51 ; V_50 ++ ) {
V_48 = & V_46 -> V_52 [ V_50 ] ;
V_49 = & V_46 -> V_53 [ V_50 ] ;
F_25 ( V_49 ) ;
F_28 (orig_node, node_tmp,
head, hash_entry) {
F_29 ( & V_22 -> V_6 ) ;
F_35 ( V_22 ) ;
}
F_30 ( V_49 ) ;
}
F_40 ( V_46 ) ;
}
struct V_5 * F_41 ( struct V_8 * V_9 ,
const T_1 * V_31 )
{
struct V_5 * V_22 ;
int V_51 ;
int V_54 ;
unsigned long V_55 ;
V_22 = F_42 ( V_9 , V_31 ) ;
if ( V_22 )
return V_22 ;
F_23 ( V_33 , V_9 ,
L_3 , V_31 ) ;
V_22 = F_19 ( sizeof( * V_22 ) , V_28 ) ;
if ( ! V_22 )
return NULL ;
F_43 ( & V_22 -> V_56 ) ;
F_44 ( & V_22 -> V_57 ) ;
F_21 ( & V_22 -> V_58 ) ;
F_21 ( & V_22 -> V_59 ) ;
F_21 ( & V_22 -> V_39 ) ;
F_21 ( & V_22 -> V_60 ) ;
F_45 ( V_22 ) ;
F_22 ( & V_22 -> V_20 , 2 ) ;
V_22 -> V_61 = false ;
V_22 -> V_9 = V_9 ;
memcpy ( V_22 -> V_62 , V_31 , V_7 ) ;
F_46 ( V_22 ) ;
V_22 -> V_23 = NULL ;
V_22 -> V_63 = 0 ;
F_22 ( & V_22 -> V_64 , 0 ) ;
V_22 -> V_42 = NULL ;
V_22 -> V_65 = 0 ;
F_22 ( & V_22 -> V_66 , 0 ) ;
V_55 = V_67 - 1 - F_8 ( V_68 ) ;
V_22 -> V_69 = V_55 ;
V_22 -> V_70 = V_55 ;
F_22 ( & V_22 -> V_71 , 0 ) ;
V_51 = V_9 -> V_72 * sizeof( unsigned long ) * V_73 ;
V_22 -> V_43 = F_19 ( V_51 , V_28 ) ;
if ( ! V_22 -> V_43 )
goto V_74;
V_51 = V_9 -> V_72 * sizeof( T_1 ) ;
V_22 -> V_44 = F_19 ( V_51 , V_28 ) ;
F_44 ( & V_22 -> V_41 ) ;
V_22 -> V_75 = 0 ;
if ( ! V_22 -> V_44 )
goto V_76;
V_54 = F_47 ( V_9 -> V_10 , F_1 ,
V_77 , V_22 ,
& V_22 -> V_6 ) ;
if ( V_54 != 0 )
goto V_78;
return V_22 ;
V_78:
F_34 ( V_22 -> V_44 ) ;
V_76:
F_34 ( V_22 -> V_43 ) ;
V_74:
F_34 ( V_22 ) ;
return NULL ;
}
static bool
F_48 ( struct V_8 * V_9 ,
struct V_5 * V_22 ,
struct V_18 * * V_79 )
{
struct V_1 * V_37 ;
struct V_18 * V_19 ;
bool V_80 = false ;
unsigned long V_81 ;
struct V_24 * V_82 ;
* V_79 = NULL ;
F_25 ( & V_22 -> V_39 ) ;
F_28 (neigh_node, node_tmp,
&orig_node->neigh_list, list) {
V_81 = V_19 -> V_81 ;
V_82 = V_19 -> V_82 ;
if ( ( F_49 ( V_81 , V_83 ) ) ||
( V_82 -> V_84 == V_85 ) ||
( V_82 -> V_84 == V_86 ) ||
( V_82 -> V_84 == V_87 ) ) {
if ( ( V_82 -> V_84 == V_85 ) ||
( V_82 -> V_84 == V_86 ) ||
( V_82 -> V_84 == V_87 ) )
F_23 ( V_33 , V_9 ,
L_4 ,
V_22 -> V_62 , V_19 -> V_31 ,
V_82 -> V_34 -> V_35 ) ;
else
F_23 ( V_33 , V_9 ,
L_5 ,
V_22 -> V_62 , V_19 -> V_31 ,
F_50 ( V_81 ) ) ;
V_80 = true ;
F_29 ( & V_19 -> V_30 ) ;
F_51 ( V_22 , V_19 ) ;
F_9 ( V_19 ) ;
} else {
if ( ( ! * V_79 ) ||
( V_19 -> V_88 > ( * V_79 ) -> V_88 ) )
* V_79 = V_19 ;
}
}
F_30 ( & V_22 -> V_39 ) ;
return V_80 ;
}
static bool F_52 ( struct V_8 * V_9 ,
struct V_5 * V_22 )
{
struct V_18 * V_79 ;
if ( F_49 ( V_22 -> V_81 ,
2 * V_83 ) ) {
F_23 ( V_33 , V_9 ,
L_6 ,
V_22 -> V_62 ,
F_50 ( V_22 -> V_81 ) ) ;
return true ;
} else {
if ( F_48 ( V_9 , V_22 ,
& V_79 ) )
F_53 ( V_9 , V_22 ,
V_79 ) ;
}
return false ;
}
static void F_54 ( struct V_8 * V_9 )
{
struct V_45 * V_46 = V_9 -> V_10 ;
struct V_1 * V_37 ;
struct V_47 * V_48 ;
T_2 * V_49 ;
struct V_5 * V_22 ;
T_3 V_50 ;
if ( ! V_46 )
return;
for ( V_50 = 0 ; V_50 < V_46 -> V_51 ; V_50 ++ ) {
V_48 = & V_46 -> V_52 [ V_50 ] ;
V_49 = & V_46 -> V_53 [ V_50 ] ;
F_25 ( V_49 ) ;
F_28 (orig_node, node_tmp,
head, hash_entry) {
if ( F_52 ( V_9 , V_22 ) ) {
if ( V_22 -> V_89 )
F_55 ( V_9 ,
V_22 ) ;
F_29 ( & V_22 -> V_6 ) ;
F_35 ( V_22 ) ;
continue;
}
if ( F_49 ( V_22 -> V_75 ,
V_90 ) )
F_32 ( & V_22 -> V_41 ) ;
}
F_30 ( V_49 ) ;
}
F_56 ( V_9 ) ;
F_57 ( V_9 ) ;
}
static void V_14 ( struct V_91 * V_92 )
{
struct V_93 * V_93 ;
struct V_8 * V_9 ;
V_93 = F_2 ( V_92 , struct V_93 , V_92 ) ;
V_9 = F_2 ( V_93 , struct V_8 , V_13 ) ;
F_54 ( V_9 ) ;
F_7 ( V_15 ,
& V_9 -> V_13 ,
F_8 ( V_16 ) ) ;
}
void F_58 ( struct V_8 * V_9 )
{
F_54 ( V_9 ) ;
}
int F_59 ( struct V_94 * V_95 , void * V_96 )
{
struct V_97 * V_34 = (struct V_97 * ) V_95 -> V_98 ;
struct V_8 * V_9 = F_18 ( V_34 ) ;
struct V_45 * V_46 = V_9 -> V_10 ;
struct V_47 * V_48 ;
struct V_24 * V_99 ;
struct V_5 * V_22 ;
struct V_18 * V_19 , * V_100 ;
int V_101 = 0 ;
int V_102 ;
int V_103 ;
unsigned long V_104 ;
T_3 V_50 ;
V_99 = F_60 ( V_95 ) ;
if ( ! V_99 )
goto V_29;
F_61 ( V_95 , L_7 ,
V_105 , V_99 -> V_34 -> V_35 ,
V_99 -> V_34 -> V_106 , V_34 -> V_35 ) ;
F_61 ( V_95 , L_8 ,
L_9 , L_10 , L_11 , V_107 ,
L_12 , L_13 , L_14 ) ;
for ( V_50 = 0 ; V_50 < V_46 -> V_51 ; V_50 ++ ) {
V_48 = & V_46 -> V_52 [ V_50 ] ;
F_13 () ;
F_62 (orig_node, head, hash_entry) {
V_19 = F_12 ( V_22 ) ;
if ( ! V_19 )
continue;
if ( V_19 -> V_88 == 0 )
goto V_108;
V_104 = V_67 - V_22 -> V_81 ;
V_103 = F_50 ( V_104 ) ;
V_102 = V_103 / 1000 ;
V_103 = V_103 % 1000 ;
F_61 ( V_95 , L_15 ,
V_22 -> V_62 , V_102 ,
V_103 , V_19 -> V_88 ,
V_19 -> V_31 ,
V_19 -> V_82 -> V_34 -> V_35 ) ;
F_62 (neigh_node_tmp,
&orig_node->neigh_list, list) {
F_61 ( V_95 , L_16 ,
V_100 -> V_31 ,
V_100 -> V_88 ) ;
}
F_63 ( V_95 , L_17 ) ;
V_101 ++ ;
V_108:
F_9 ( V_19 ) ;
}
F_16 () ;
}
if ( V_101 == 0 )
F_63 ( V_95 , L_18 ) ;
V_29:
if ( V_99 )
F_64 ( V_99 ) ;
return 0 ;
}
static int F_65 ( struct V_5 * V_22 ,
int V_109 )
{
void * V_110 ;
T_4 V_111 , V_112 ;
V_111 = V_109 * sizeof( unsigned long ) * V_73 ;
V_112 = ( V_109 - 1 ) * sizeof( unsigned long ) * V_73 ;
V_110 = F_66 ( V_111 , V_28 ) ;
if ( ! V_110 )
return - V_17 ;
memcpy ( V_110 , V_22 -> V_43 , V_112 ) ;
F_34 ( V_22 -> V_43 ) ;
V_22 -> V_43 = V_110 ;
V_110 = F_66 ( V_109 * sizeof( T_1 ) , V_28 ) ;
if ( ! V_110 )
return - V_17 ;
memcpy ( V_110 , V_22 -> V_44 ,
( V_109 - 1 ) * sizeof( T_1 ) ) ;
F_34 ( V_22 -> V_44 ) ;
V_22 -> V_44 = V_110 ;
return 0 ;
}
int F_67 ( struct V_24 * V_25 ,
int V_109 )
{
struct V_8 * V_9 = F_18 ( V_25 -> V_27 ) ;
struct V_45 * V_46 = V_9 -> V_10 ;
struct V_47 * V_48 ;
struct V_5 * V_22 ;
T_3 V_50 ;
int V_113 ;
for ( V_50 = 0 ; V_50 < V_46 -> V_51 ; V_50 ++ ) {
V_48 = & V_46 -> V_52 [ V_50 ] ;
F_13 () ;
F_62 (orig_node, head, hash_entry) {
F_25 ( & V_22 -> V_58 ) ;
V_113 = F_65 ( V_22 , V_109 ) ;
F_30 ( & V_22 -> V_58 ) ;
if ( V_113 == - V_17 )
goto V_11;
}
F_16 () ;
}
return 0 ;
V_11:
F_16 () ;
return - V_17 ;
}
static int F_68 ( struct V_5 * V_22 ,
int V_109 , int V_114 )
{
void * V_110 = NULL ;
int V_115 ;
if ( V_109 == 0 )
goto V_76;
V_115 = sizeof( unsigned long ) * V_73 ;
V_110 = F_66 ( V_109 * V_115 , V_28 ) ;
if ( ! V_110 )
return - V_17 ;
memcpy ( V_110 , V_22 -> V_43 , V_114 * V_115 ) ;
memcpy ( ( char * ) V_110 + V_114 * V_115 ,
V_22 -> V_43 + ( ( V_114 + 1 ) * V_115 ) ,
( V_109 - V_114 ) * V_115 ) ;
V_76:
F_34 ( V_22 -> V_43 ) ;
V_22 -> V_43 = V_110 ;
if ( V_109 == 0 )
goto V_116;
V_110 = F_66 ( V_109 * sizeof( T_1 ) , V_28 ) ;
if ( ! V_110 )
return - V_17 ;
memcpy ( V_110 , V_22 -> V_44 ,
V_114 * sizeof( T_1 ) ) ;
memcpy ( ( char * ) V_110 + V_114 * sizeof( T_1 ) ,
V_22 -> V_44 + ( ( V_114 + 1 ) * sizeof( T_1 ) ) ,
( V_109 - V_114 ) * sizeof( T_1 ) ) ;
V_116:
F_34 ( V_22 -> V_44 ) ;
V_22 -> V_44 = V_110 ;
return 0 ;
}
int F_69 ( struct V_24 * V_25 ,
int V_109 )
{
struct V_8 * V_9 = F_18 ( V_25 -> V_27 ) ;
struct V_45 * V_46 = V_9 -> V_10 ;
struct V_47 * V_48 ;
struct V_24 * V_117 ;
struct V_5 * V_22 ;
T_3 V_50 ;
int V_113 ;
for ( V_50 = 0 ; V_50 < V_46 -> V_51 ; V_50 ++ ) {
V_48 = & V_46 -> V_52 [ V_50 ] ;
F_13 () ;
F_62 (orig_node, head, hash_entry) {
F_25 ( & V_22 -> V_58 ) ;
V_113 = F_68 ( V_22 , V_109 ,
V_25 -> V_118 ) ;
F_30 ( & V_22 -> V_58 ) ;
if ( V_113 == - V_17 )
goto V_11;
}
F_16 () ;
}
F_13 () ;
F_70 (hard_iface_tmp, &batadv_hardif_list, list) {
if ( V_117 -> V_84 == V_86 )
continue;
if ( V_25 == V_117 )
continue;
if ( V_25 -> V_27 != V_117 -> V_27 )
continue;
if ( V_117 -> V_118 > V_25 -> V_118 )
V_117 -> V_118 -- ;
}
F_16 () ;
V_25 -> V_118 = - 1 ;
return 0 ;
V_11:
F_16 () ;
return - V_17 ;
}

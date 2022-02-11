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
const T_1 * V_26 , T_2 V_27 )
{
struct V_8 * V_9 = F_18 ( V_25 -> V_28 ) ;
struct V_18 * V_19 ;
V_19 = F_19 ( sizeof( * V_19 ) , V_29 ) ;
if ( ! V_19 )
goto V_30;
F_20 ( & V_19 -> V_31 ) ;
memcpy ( V_19 -> V_32 , V_26 , V_7 ) ;
F_21 ( & V_19 -> V_33 ) ;
F_22 ( & V_19 -> V_20 , 2 ) ;
F_23 ( V_34 , V_9 ,
L_1 ,
V_26 , V_27 ) ;
V_30:
return V_19 ;
}
static void F_24 ( struct V_35 * V_21 )
{
struct V_1 * V_36 ;
struct V_18 * V_19 , * V_37 ;
struct V_5 * V_22 ;
V_22 = F_2 ( V_21 , struct V_5 , V_21 ) ;
F_25 ( & V_22 -> V_38 ) ;
F_26 (neigh_node, tmp_neigh_node,
&orig_node->bond_list, bonding_list) {
F_27 ( & V_19 -> V_39 ) ;
F_9 ( V_19 ) ;
}
F_28 (neigh_node, node_tmp,
&orig_node->neigh_list, list) {
F_29 ( & V_19 -> V_31 ) ;
F_9 ( V_19 ) ;
}
F_30 ( & V_22 -> V_38 ) ;
F_31 ( & V_22 -> V_40 ) ;
F_32 ( V_22 -> V_9 , V_22 ,
L_2 ) ;
F_33 ( V_22 -> V_41 ) ;
F_33 ( V_22 -> V_42 ) ;
F_33 ( V_22 -> V_43 ) ;
F_33 ( V_22 ) ;
}
void F_34 ( struct V_5 * V_22 )
{
if ( F_10 ( & V_22 -> V_20 ) )
F_35 ( & V_22 -> V_21 , F_24 ) ;
}
void F_36 ( struct V_8 * V_9 )
{
struct V_44 * V_45 = V_9 -> V_10 ;
struct V_1 * V_36 ;
struct V_46 * V_47 ;
T_3 * V_48 ;
struct V_5 * V_22 ;
T_2 V_49 ;
if ( ! V_45 )
return;
F_37 ( & V_9 -> V_13 ) ;
V_9 -> V_10 = NULL ;
for ( V_49 = 0 ; V_49 < V_45 -> V_50 ; V_49 ++ ) {
V_47 = & V_45 -> V_51 [ V_49 ] ;
V_48 = & V_45 -> V_52 [ V_49 ] ;
F_25 ( V_48 ) ;
F_28 (orig_node, node_tmp,
head, hash_entry) {
F_29 ( & V_22 -> V_6 ) ;
F_34 ( V_22 ) ;
}
F_30 ( V_48 ) ;
}
F_38 ( V_45 ) ;
}
struct V_5 * F_39 ( struct V_8 * V_9 ,
const T_1 * V_32 )
{
struct V_5 * V_22 ;
int V_50 ;
int V_53 ;
unsigned long V_54 ;
V_22 = F_40 ( V_9 , V_32 ) ;
if ( V_22 )
return V_22 ;
F_23 ( V_34 , V_9 ,
L_3 , V_32 ) ;
V_22 = F_19 ( sizeof( * V_22 ) , V_29 ) ;
if ( ! V_22 )
return NULL ;
F_41 ( & V_22 -> V_55 ) ;
F_42 ( & V_22 -> V_56 ) ;
F_21 ( & V_22 -> V_57 ) ;
F_21 ( & V_22 -> V_58 ) ;
F_21 ( & V_22 -> V_38 ) ;
F_21 ( & V_22 -> V_59 ) ;
F_22 ( & V_22 -> V_20 , 2 ) ;
V_22 -> V_60 = false ;
V_22 -> V_9 = V_9 ;
memcpy ( V_22 -> V_61 , V_32 , V_7 ) ;
F_43 ( V_22 ) ;
V_22 -> V_23 = NULL ;
V_22 -> V_62 = 0 ;
F_22 ( & V_22 -> V_63 , 0 ) ;
V_22 -> V_41 = NULL ;
V_22 -> V_64 = 0 ;
F_22 ( & V_22 -> V_65 , 0 ) ;
V_54 = V_66 - 1 - F_8 ( V_67 ) ;
V_22 -> V_68 = V_54 ;
V_22 -> V_69 = V_54 ;
F_22 ( & V_22 -> V_70 , 0 ) ;
V_50 = V_9 -> V_71 * sizeof( unsigned long ) * V_72 ;
V_22 -> V_42 = F_19 ( V_50 , V_29 ) ;
if ( ! V_22 -> V_42 )
goto V_73;
V_50 = V_9 -> V_71 * sizeof( T_1 ) ;
V_22 -> V_43 = F_19 ( V_50 , V_29 ) ;
F_42 ( & V_22 -> V_40 ) ;
V_22 -> V_74 = 0 ;
if ( ! V_22 -> V_43 )
goto V_75;
V_53 = F_44 ( V_9 -> V_10 , F_1 ,
V_76 , V_22 ,
& V_22 -> V_6 ) ;
if ( V_53 != 0 )
goto V_77;
return V_22 ;
V_77:
F_33 ( V_22 -> V_43 ) ;
V_75:
F_33 ( V_22 -> V_42 ) ;
V_73:
F_33 ( V_22 ) ;
return NULL ;
}
static bool
F_45 ( struct V_8 * V_9 ,
struct V_5 * V_22 ,
struct V_18 * * V_78 )
{
struct V_1 * V_36 ;
struct V_18 * V_19 ;
bool V_79 = false ;
unsigned long V_80 ;
struct V_24 * V_81 ;
* V_78 = NULL ;
F_25 ( & V_22 -> V_38 ) ;
F_28 (neigh_node, node_tmp,
&orig_node->neigh_list, list) {
V_80 = V_19 -> V_80 ;
V_81 = V_19 -> V_81 ;
if ( ( F_46 ( V_80 , V_82 ) ) ||
( V_81 -> V_83 == V_84 ) ||
( V_81 -> V_83 == V_85 ) ||
( V_81 -> V_83 == V_86 ) ) {
if ( ( V_81 -> V_83 == V_84 ) ||
( V_81 -> V_83 == V_85 ) ||
( V_81 -> V_83 == V_86 ) )
F_23 ( V_34 , V_9 ,
L_4 ,
V_22 -> V_61 , V_19 -> V_32 ,
V_81 -> V_87 -> V_88 ) ;
else
F_23 ( V_34 , V_9 ,
L_5 ,
V_22 -> V_61 , V_19 -> V_32 ,
F_47 ( V_80 ) ) ;
V_79 = true ;
F_29 ( & V_19 -> V_31 ) ;
F_48 ( V_22 , V_19 ) ;
F_9 ( V_19 ) ;
} else {
if ( ( ! * V_78 ) ||
( V_19 -> V_89 > ( * V_78 ) -> V_89 ) )
* V_78 = V_19 ;
}
}
F_30 ( & V_22 -> V_38 ) ;
return V_79 ;
}
static bool F_49 ( struct V_8 * V_9 ,
struct V_5 * V_22 )
{
struct V_18 * V_78 ;
if ( F_46 ( V_22 -> V_80 ,
2 * V_82 ) ) {
F_23 ( V_34 , V_9 ,
L_6 ,
V_22 -> V_61 ,
F_47 ( V_22 -> V_80 ) ) ;
return true ;
} else {
if ( F_45 ( V_9 , V_22 ,
& V_78 ) )
F_50 ( V_9 , V_22 ,
V_78 ) ;
}
return false ;
}
static void F_51 ( struct V_8 * V_9 )
{
struct V_44 * V_45 = V_9 -> V_10 ;
struct V_1 * V_36 ;
struct V_46 * V_47 ;
T_3 * V_48 ;
struct V_5 * V_22 ;
T_2 V_49 ;
if ( ! V_45 )
return;
for ( V_49 = 0 ; V_49 < V_45 -> V_50 ; V_49 ++ ) {
V_47 = & V_45 -> V_51 [ V_49 ] ;
V_48 = & V_45 -> V_52 [ V_49 ] ;
F_25 ( V_48 ) ;
F_28 (orig_node, node_tmp,
head, hash_entry) {
if ( F_49 ( V_9 , V_22 ) ) {
if ( V_22 -> V_90 )
F_52 ( V_9 ,
V_22 ) ;
F_29 ( & V_22 -> V_6 ) ;
F_34 ( V_22 ) ;
continue;
}
if ( F_46 ( V_22 -> V_74 ,
V_91 ) )
F_31 ( & V_22 -> V_40 ) ;
}
F_30 ( V_48 ) ;
}
F_53 ( V_9 ) ;
F_54 ( V_9 ) ;
}
static void V_14 ( struct V_92 * V_93 )
{
struct V_94 * V_94 ;
struct V_8 * V_9 ;
V_94 = F_2 ( V_93 , struct V_94 , V_93 ) ;
V_9 = F_2 ( V_94 , struct V_8 , V_13 ) ;
F_51 ( V_9 ) ;
F_7 ( V_15 ,
& V_9 -> V_13 ,
F_8 ( V_16 ) ) ;
}
void F_55 ( struct V_8 * V_9 )
{
F_51 ( V_9 ) ;
}
int F_56 ( struct V_95 * V_96 , void * V_97 )
{
struct V_98 * V_87 = (struct V_98 * ) V_96 -> V_99 ;
struct V_8 * V_9 = F_18 ( V_87 ) ;
struct V_44 * V_45 = V_9 -> V_10 ;
struct V_46 * V_47 ;
struct V_24 * V_100 ;
struct V_5 * V_22 ;
struct V_18 * V_19 , * V_101 ;
int V_102 = 0 ;
int V_103 ;
int V_104 ;
unsigned long V_105 ;
T_2 V_49 ;
V_100 = F_57 ( V_96 ) ;
if ( ! V_100 )
goto V_30;
F_58 ( V_96 , L_7 ,
V_106 , V_100 -> V_87 -> V_88 ,
V_100 -> V_87 -> V_107 , V_87 -> V_88 ) ;
F_58 ( V_96 , L_8 ,
L_9 , L_10 , L_11 , V_108 ,
L_12 , L_13 , L_14 ) ;
for ( V_49 = 0 ; V_49 < V_45 -> V_50 ; V_49 ++ ) {
V_47 = & V_45 -> V_51 [ V_49 ] ;
F_13 () ;
F_59 (orig_node, head, hash_entry) {
V_19 = F_12 ( V_22 ) ;
if ( ! V_19 )
continue;
if ( V_19 -> V_89 == 0 )
goto V_109;
V_105 = V_66 - V_22 -> V_80 ;
V_104 = F_47 ( V_105 ) ;
V_103 = V_104 / 1000 ;
V_104 = V_104 % 1000 ;
F_58 ( V_96 , L_15 ,
V_22 -> V_61 , V_103 ,
V_104 , V_19 -> V_89 ,
V_19 -> V_32 ,
V_19 -> V_81 -> V_87 -> V_88 ) ;
F_59 (neigh_node_tmp,
&orig_node->neigh_list, list) {
F_58 ( V_96 , L_16 ,
V_101 -> V_32 ,
V_101 -> V_89 ) ;
}
F_58 ( V_96 , L_17 ) ;
V_102 ++ ;
V_109:
F_9 ( V_19 ) ;
}
F_16 () ;
}
if ( V_102 == 0 )
F_58 ( V_96 , L_18 ) ;
V_30:
if ( V_100 )
F_60 ( V_100 ) ;
return 0 ;
}
static int F_61 ( struct V_5 * V_22 ,
int V_110 )
{
void * V_111 ;
T_4 V_112 , V_113 ;
V_112 = V_110 * sizeof( unsigned long ) * V_72 ;
V_113 = ( V_110 - 1 ) * sizeof( unsigned long ) * V_72 ;
V_111 = F_62 ( V_112 , V_29 ) ;
if ( ! V_111 )
return - V_17 ;
memcpy ( V_111 , V_22 -> V_42 , V_113 ) ;
F_33 ( V_22 -> V_42 ) ;
V_22 -> V_42 = V_111 ;
V_111 = F_62 ( V_110 * sizeof( T_1 ) , V_29 ) ;
if ( ! V_111 )
return - V_17 ;
memcpy ( V_111 , V_22 -> V_43 ,
( V_110 - 1 ) * sizeof( T_1 ) ) ;
F_33 ( V_22 -> V_43 ) ;
V_22 -> V_43 = V_111 ;
return 0 ;
}
int F_63 ( struct V_24 * V_25 ,
int V_110 )
{
struct V_8 * V_9 = F_18 ( V_25 -> V_28 ) ;
struct V_44 * V_45 = V_9 -> V_10 ;
struct V_46 * V_47 ;
struct V_5 * V_22 ;
T_2 V_49 ;
int V_114 ;
for ( V_49 = 0 ; V_49 < V_45 -> V_50 ; V_49 ++ ) {
V_47 = & V_45 -> V_51 [ V_49 ] ;
F_13 () ;
F_59 (orig_node, head, hash_entry) {
F_25 ( & V_22 -> V_57 ) ;
V_114 = F_61 ( V_22 , V_110 ) ;
F_30 ( & V_22 -> V_57 ) ;
if ( V_114 == - V_17 )
goto V_11;
}
F_16 () ;
}
return 0 ;
V_11:
F_16 () ;
return - V_17 ;
}
static int F_64 ( struct V_5 * V_22 ,
int V_110 , int V_115 )
{
void * V_111 = NULL ;
int V_116 ;
if ( V_110 == 0 )
goto V_75;
V_116 = sizeof( unsigned long ) * V_72 ;
V_111 = F_62 ( V_110 * V_116 , V_29 ) ;
if ( ! V_111 )
return - V_17 ;
memcpy ( V_111 , V_22 -> V_42 , V_115 * V_116 ) ;
memcpy ( ( char * ) V_111 + V_115 * V_116 ,
V_22 -> V_42 + ( ( V_115 + 1 ) * V_116 ) ,
( V_110 - V_115 ) * V_116 ) ;
V_75:
F_33 ( V_22 -> V_42 ) ;
V_22 -> V_42 = V_111 ;
if ( V_110 == 0 )
goto V_117;
V_111 = F_62 ( V_110 * sizeof( T_1 ) , V_29 ) ;
if ( ! V_111 )
return - V_17 ;
memcpy ( V_111 , V_22 -> V_43 ,
V_115 * sizeof( T_1 ) ) ;
memcpy ( ( char * ) V_111 + V_115 * sizeof( T_1 ) ,
V_22 -> V_43 + ( ( V_115 + 1 ) * sizeof( T_1 ) ) ,
( V_110 - V_115 ) * sizeof( T_1 ) ) ;
V_117:
F_33 ( V_22 -> V_43 ) ;
V_22 -> V_43 = V_111 ;
return 0 ;
}
int F_65 ( struct V_24 * V_25 ,
int V_110 )
{
struct V_8 * V_9 = F_18 ( V_25 -> V_28 ) ;
struct V_44 * V_45 = V_9 -> V_10 ;
struct V_46 * V_47 ;
struct V_24 * V_118 ;
struct V_5 * V_22 ;
T_2 V_49 ;
int V_114 ;
for ( V_49 = 0 ; V_49 < V_45 -> V_50 ; V_49 ++ ) {
V_47 = & V_45 -> V_51 [ V_49 ] ;
F_13 () ;
F_59 (orig_node, head, hash_entry) {
F_25 ( & V_22 -> V_57 ) ;
V_114 = F_64 ( V_22 , V_110 ,
V_25 -> V_119 ) ;
F_30 ( & V_22 -> V_57 ) ;
if ( V_114 == - V_17 )
goto V_11;
}
F_16 () ;
}
F_13 () ;
F_66 (hard_iface_tmp, &batadv_hardif_list, list) {
if ( V_118 -> V_83 == V_85 )
continue;
if ( V_25 == V_118 )
continue;
if ( V_25 -> V_28 != V_118 -> V_28 )
continue;
if ( V_118 -> V_119 > V_25 -> V_119 )
V_118 -> V_119 -- ;
}
F_16 () ;
V_25 -> V_119 = - 1 ;
return 0 ;
V_11:
F_16 () ;
return - V_17 ;
}

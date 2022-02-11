static void F_1 ( struct V_1 * V_1 )
{
F_2 ( & V_1 -> V_2 , V_3 ) ;
F_3 ( V_4 , & V_1 -> V_2 , 1 * V_5 ) ;
}
static int F_4 ( const struct V_6 * V_7 , const void * V_8 )
{
const void * V_9 = F_5 ( V_7 , struct V_10 , V_11 ) ;
return ( memcmp ( V_9 , V_8 , V_12 ) == 0 ? 1 : 0 ) ;
}
int F_6 ( struct V_1 * V_1 )
{
if ( V_1 -> V_13 )
return 1 ;
V_1 -> V_13 = F_7 ( 1024 ) ;
if ( ! V_1 -> V_13 )
goto V_14;
F_1 ( V_1 ) ;
return 1 ;
V_14:
return 0 ;
}
void F_8 ( struct V_15 * V_15 )
{
if ( F_9 ( & V_15 -> V_16 ) )
F_10 ( V_15 , V_17 ) ;
}
struct V_15 * F_11 ( struct V_10 * V_10 )
{
struct V_15 * V_18 ;
F_12 () ;
V_18 = F_13 ( V_10 -> V_18 ) ;
if ( V_18 && ! F_14 ( & V_18 -> V_16 ) )
V_18 = NULL ;
F_15 () ;
return V_18 ;
}
struct V_15 * F_16 ( struct V_10 * V_10 ,
struct V_10 * V_19 ,
const T_1 * V_20 ,
struct V_21 * V_22 )
{
struct V_1 * V_1 = F_17 ( V_22 -> V_23 ) ;
struct V_15 * V_15 ;
F_18 ( V_24 , V_1 ,
L_1 ) ;
V_15 = F_19 ( sizeof( * V_15 ) , V_25 ) ;
if ( ! V_15 )
return NULL ;
F_20 ( & V_15 -> V_26 ) ;
F_21 ( & V_15 -> V_27 ) ;
F_22 ( & V_15 -> V_28 ) ;
memcpy ( V_15 -> V_29 , V_20 , V_12 ) ;
V_15 -> V_10 = V_19 ;
V_15 -> V_22 = V_22 ;
F_23 ( & V_15 -> V_16 , 2 ) ;
F_24 ( & V_10 -> V_30 ) ;
F_25 ( & V_15 -> V_26 , & V_10 -> V_31 ) ;
F_26 ( & V_10 -> V_30 ) ;
return V_15 ;
}
static void F_27 ( struct V_32 * V_17 )
{
struct V_6 * V_7 , * V_33 ;
struct V_15 * V_15 , * V_34 ;
struct V_10 * V_10 ;
V_10 = F_5 ( V_17 , struct V_10 , V_17 ) ;
F_24 ( & V_10 -> V_30 ) ;
F_28 (neigh_node, tmp_neigh_node,
&orig_node->bond_list, bonding_list) {
F_29 ( & V_15 -> V_27 ) ;
F_8 ( V_15 ) ;
}
F_30 (neigh_node, node, node_tmp,
&orig_node->neigh_list, list) {
F_31 ( & V_15 -> V_26 ) ;
F_8 ( V_15 ) ;
}
F_26 ( & V_10 -> V_30 ) ;
F_32 ( & V_10 -> V_35 ) ;
F_33 ( V_10 -> V_1 , V_10 ,
L_2 ) ;
F_34 ( V_10 -> V_36 ) ;
F_34 ( V_10 -> V_37 ) ;
F_34 ( V_10 -> V_38 ) ;
F_34 ( V_10 ) ;
}
void F_35 ( struct V_10 * V_10 )
{
if ( F_9 ( & V_10 -> V_16 ) )
F_36 ( & V_10 -> V_17 , F_27 ) ;
}
void F_37 ( struct V_1 * V_1 )
{
struct V_39 * V_40 = V_1 -> V_13 ;
struct V_6 * V_7 , * V_33 ;
struct V_41 * V_42 ;
T_2 * V_43 ;
struct V_10 * V_10 ;
T_3 V_44 ;
if ( ! V_40 )
return;
F_38 ( & V_1 -> V_2 ) ;
V_1 -> V_13 = NULL ;
for ( V_44 = 0 ; V_44 < V_40 -> V_45 ; V_44 ++ ) {
V_42 = & V_40 -> V_46 [ V_44 ] ;
V_43 = & V_40 -> V_47 [ V_44 ] ;
F_24 ( V_43 ) ;
F_30 (orig_node, node, node_tmp,
head, hash_entry) {
F_31 ( V_7 ) ;
F_35 ( V_10 ) ;
}
F_26 ( V_43 ) ;
}
F_39 ( V_40 ) ;
}
struct V_10 * F_40 ( struct V_1 * V_1 , const T_1 * V_29 )
{
struct V_10 * V_10 ;
int V_45 ;
int V_48 ;
V_10 = F_41 ( V_1 , V_29 ) ;
if ( V_10 )
return V_10 ;
F_18 ( V_24 , V_1 ,
L_3 , V_29 ) ;
V_10 = F_19 ( sizeof( * V_10 ) , V_25 ) ;
if ( ! V_10 )
return NULL ;
F_42 ( & V_10 -> V_31 ) ;
F_21 ( & V_10 -> V_49 ) ;
F_22 ( & V_10 -> V_50 ) ;
F_22 ( & V_10 -> V_51 ) ;
F_22 ( & V_10 -> V_30 ) ;
F_22 ( & V_10 -> V_52 ) ;
F_23 ( & V_10 -> V_16 , 2 ) ;
V_10 -> V_53 = false ;
V_10 -> V_1 = V_1 ;
memcpy ( V_10 -> V_54 , V_29 , V_12 ) ;
V_10 -> V_18 = NULL ;
V_10 -> V_55 = 0 ;
F_23 ( & V_10 -> V_56 , 0 ) ;
V_10 -> V_36 = NULL ;
V_10 -> V_57 = 0 ;
F_23 ( & V_10 -> V_58 , 0 ) ;
V_10 -> V_59 = V_60 - 1
- F_43 ( V_61 ) ;
V_10 -> V_62 = V_60 - 1
- F_43 ( V_61 ) ;
F_23 ( & V_10 -> V_63 , 0 ) ;
V_45 = V_1 -> V_64 * sizeof( unsigned long ) * V_65 ;
V_10 -> V_37 = F_19 ( V_45 , V_25 ) ;
if ( ! V_10 -> V_37 )
goto V_66;
V_45 = V_1 -> V_64 * sizeof( T_1 ) ;
V_10 -> V_38 = F_19 ( V_45 , V_25 ) ;
F_21 ( & V_10 -> V_35 ) ;
V_10 -> V_67 = 0 ;
if ( ! V_10 -> V_38 )
goto V_68;
V_48 = F_44 ( V_1 -> V_13 , F_4 ,
V_69 , V_10 , & V_10 -> V_11 ) ;
if ( V_48 != 0 )
goto V_70;
return V_10 ;
V_70:
F_34 ( V_10 -> V_38 ) ;
V_68:
F_34 ( V_10 -> V_37 ) ;
V_66:
F_34 ( V_10 ) ;
return NULL ;
}
static bool F_45 ( struct V_1 * V_1 ,
struct V_10 * V_10 ,
struct V_15 * * V_71 )
{
struct V_6 * V_7 , * V_33 ;
struct V_15 * V_15 ;
bool V_72 = false ;
* V_71 = NULL ;
F_24 ( & V_10 -> V_30 ) ;
F_30 (neigh_node, node, node_tmp,
&orig_node->neigh_list, list) {
if ( ( F_46 ( V_60 ,
V_15 -> V_73 + V_74 * V_5 ) ) ||
( V_15 -> V_22 -> V_75 == V_76 ) ||
( V_15 -> V_22 -> V_75 == V_77 ) ||
( V_15 -> V_22 -> V_75 == V_78 ) ) {
if ( ( V_15 -> V_22 -> V_75 ==
V_76 ) ||
( V_15 -> V_22 -> V_75 ==
V_77 ) ||
( V_15 -> V_22 -> V_75 ==
V_78 ) )
F_18 ( V_24 , V_1 ,
L_4
L_5 ,
V_10 -> V_54 , V_15 -> V_29 ,
V_15 -> V_22 -> V_79 -> V_80 ) ;
else
F_18 ( V_24 , V_1 ,
L_6
L_7 ,
V_10 -> V_54 , V_15 -> V_29 ,
( V_15 -> V_73 / V_5 ) ) ;
V_72 = true ;
F_31 ( & V_15 -> V_26 ) ;
F_47 ( V_10 , V_15 ) ;
F_8 ( V_15 ) ;
} else {
if ( ( ! * V_71 ) ||
( V_15 -> V_81 > ( * V_71 ) -> V_81 ) )
* V_71 = V_15 ;
}
}
F_26 ( & V_10 -> V_30 ) ;
return V_72 ;
}
static bool F_48 ( struct V_1 * V_1 ,
struct V_10 * V_10 )
{
struct V_15 * V_71 ;
if ( F_46 ( V_60 ,
V_10 -> V_73 + 2 * V_74 * V_5 ) ) {
F_18 ( V_24 , V_1 ,
L_8 ,
V_10 -> V_54 , ( V_10 -> V_73 / V_5 ) ) ;
return true ;
} else {
if ( F_45 ( V_1 , V_10 ,
& V_71 ) ) {
F_49 ( V_1 , V_10 , V_71 ) ;
}
}
return false ;
}
static void F_50 ( struct V_1 * V_1 )
{
struct V_39 * V_40 = V_1 -> V_13 ;
struct V_6 * V_7 , * V_33 ;
struct V_41 * V_42 ;
T_2 * V_43 ;
struct V_10 * V_10 ;
T_3 V_44 ;
if ( ! V_40 )
return;
for ( V_44 = 0 ; V_44 < V_40 -> V_45 ; V_44 ++ ) {
V_42 = & V_40 -> V_46 [ V_44 ] ;
V_43 = & V_40 -> V_47 [ V_44 ] ;
F_24 ( V_43 ) ;
F_30 (orig_node, node, node_tmp,
head, hash_entry) {
if ( F_48 ( V_1 , V_10 ) ) {
if ( V_10 -> V_82 )
F_51 ( V_1 , V_10 ) ;
F_31 ( V_7 ) ;
F_35 ( V_10 ) ;
continue;
}
if ( F_46 ( V_60 , V_10 -> V_67 +
F_43 ( V_83 ) ) )
F_32 ( & V_10 -> V_35 ) ;
}
F_26 ( V_43 ) ;
}
F_52 ( V_1 ) ;
F_53 ( V_1 ) ;
F_54 ( V_1 ) ;
}
static void V_3 ( struct V_84 * V_85 )
{
struct V_86 * V_86 =
F_5 ( V_85 , struct V_86 , V_85 ) ;
struct V_1 * V_1 =
F_5 ( V_86 , struct V_1 , V_2 ) ;
F_50 ( V_1 ) ;
F_1 ( V_1 ) ;
}
void F_55 ( struct V_1 * V_1 )
{
F_50 ( V_1 ) ;
}
int F_56 ( struct V_87 * V_88 , void * V_89 )
{
struct V_90 * V_79 = (struct V_90 * ) V_88 -> V_91 ;
struct V_1 * V_1 = F_17 ( V_79 ) ;
struct V_39 * V_40 = V_1 -> V_13 ;
struct V_6 * V_7 , * V_33 ;
struct V_41 * V_42 ;
struct V_21 * V_92 ;
struct V_10 * V_10 ;
struct V_15 * V_15 , * V_93 ;
int V_94 = 0 ;
int V_95 ;
int V_96 ;
T_3 V_44 ;
int V_97 = 0 ;
V_92 = F_57 ( V_1 ) ;
if ( ! V_92 ) {
V_97 = F_58 ( V_88 , L_9
L_10 ,
V_79 -> V_80 ) ;
goto V_98;
}
if ( V_92 -> V_75 != V_99 ) {
V_97 = F_58 ( V_88 , L_11
L_12 ,
V_79 -> V_80 ) ;
goto V_98;
}
F_58 ( V_88 , L_13 ,
V_100 , V_92 -> V_79 -> V_80 ,
V_92 -> V_79 -> V_101 , V_79 -> V_80 ) ;
F_58 ( V_88 , L_14 ,
L_15 , L_16 , L_17 , V_102 , L_18 ,
L_19 , L_20 ) ;
for ( V_44 = 0 ; V_44 < V_40 -> V_45 ; V_44 ++ ) {
V_42 = & V_40 -> V_46 [ V_44 ] ;
F_12 () ;
F_59 (orig_node, node, head, hash_entry) {
V_15 = F_11 ( V_10 ) ;
if ( ! V_15 )
continue;
if ( V_15 -> V_81 == 0 )
goto V_103;
V_95 = F_60 ( V_60 -
V_10 -> V_73 ) / 1000 ;
V_96 = F_60 ( V_60 -
V_10 -> V_73 ) % 1000 ;
F_58 ( V_88 , L_21 ,
V_10 -> V_54 , V_95 ,
V_96 , V_15 -> V_81 ,
V_15 -> V_29 ,
V_15 -> V_22 -> V_79 -> V_80 ) ;
F_59 (neigh_node_tmp, node_tmp,
&orig_node->neigh_list, list) {
F_58 ( V_88 , L_22 ,
V_93 -> V_29 ,
V_93 -> V_81 ) ;
}
F_58 ( V_88 , L_23 ) ;
V_94 ++ ;
V_103:
F_8 ( V_15 ) ;
}
F_15 () ;
}
if ( V_94 == 0 )
F_58 ( V_88 , L_24 ) ;
V_98:
if ( V_92 )
F_61 ( V_92 ) ;
return V_97 ;
}
static int F_62 ( struct V_10 * V_10 , int V_104 )
{
void * V_105 ;
V_105 = F_63 ( V_104 * sizeof( unsigned long ) * V_65 ,
V_25 ) ;
if ( ! V_105 )
return - 1 ;
memcpy ( V_105 , V_10 -> V_37 ,
( V_104 - 1 ) * sizeof( unsigned long ) * V_65 ) ;
F_34 ( V_10 -> V_37 ) ;
V_10 -> V_37 = V_105 ;
V_105 = F_63 ( V_104 * sizeof( T_1 ) , V_25 ) ;
if ( ! V_105 )
return - 1 ;
memcpy ( V_105 , V_10 -> V_38 ,
( V_104 - 1 ) * sizeof( T_1 ) ) ;
F_34 ( V_10 -> V_38 ) ;
V_10 -> V_38 = V_105 ;
return 0 ;
}
int F_64 ( struct V_21 * V_21 , int V_104 )
{
struct V_1 * V_1 = F_17 ( V_21 -> V_23 ) ;
struct V_39 * V_40 = V_1 -> V_13 ;
struct V_6 * V_7 ;
struct V_41 * V_42 ;
struct V_10 * V_10 ;
T_3 V_44 ;
int V_97 ;
for ( V_44 = 0 ; V_44 < V_40 -> V_45 ; V_44 ++ ) {
V_42 = & V_40 -> V_46 [ V_44 ] ;
F_12 () ;
F_59 (orig_node, node, head, hash_entry) {
F_24 ( & V_10 -> V_50 ) ;
V_97 = F_62 ( V_10 , V_104 ) ;
F_26 ( & V_10 -> V_50 ) ;
if ( V_97 == - 1 )
goto V_14;
}
F_15 () ;
}
return 0 ;
V_14:
F_15 () ;
return - V_106 ;
}
static int F_65 ( struct V_10 * V_10 ,
int V_104 , int V_107 )
{
void * V_105 = NULL ;
int V_108 ;
if ( V_104 == 0 )
goto V_68;
V_108 = sizeof( unsigned long ) * V_65 ;
V_105 = F_63 ( V_104 * V_108 , V_25 ) ;
if ( ! V_105 )
return - 1 ;
memcpy ( V_105 , V_10 -> V_37 , V_107 * V_108 ) ;
memcpy ( ( char * ) V_105 + V_107 * V_108 ,
V_10 -> V_37 + ( ( V_107 + 1 ) * V_108 ) ,
( V_104 - V_107 ) * V_108 ) ;
V_68:
F_34 ( V_10 -> V_37 ) ;
V_10 -> V_37 = V_105 ;
if ( V_104 == 0 )
goto V_109;
V_105 = F_63 ( V_104 * sizeof( T_1 ) , V_25 ) ;
if ( ! V_105 )
return - 1 ;
memcpy ( V_105 , V_10 -> V_38 ,
V_107 * sizeof( T_1 ) ) ;
memcpy ( ( char * ) V_105 + V_107 * sizeof( T_1 ) ,
V_10 -> V_38 + ( ( V_107 + 1 ) * sizeof( T_1 ) ) ,
( V_104 - V_107 ) * sizeof( T_1 ) ) ;
V_109:
F_34 ( V_10 -> V_38 ) ;
V_10 -> V_38 = V_105 ;
return 0 ;
}
int F_66 ( struct V_21 * V_21 , int V_104 )
{
struct V_1 * V_1 = F_17 ( V_21 -> V_23 ) ;
struct V_39 * V_40 = V_1 -> V_13 ;
struct V_6 * V_7 ;
struct V_41 * V_42 ;
struct V_21 * V_110 ;
struct V_10 * V_10 ;
T_3 V_44 ;
int V_97 ;
for ( V_44 = 0 ; V_44 < V_40 -> V_45 ; V_44 ++ ) {
V_42 = & V_40 -> V_46 [ V_44 ] ;
F_12 () ;
F_59 (orig_node, node, head, hash_entry) {
F_24 ( & V_10 -> V_50 ) ;
V_97 = F_65 ( V_10 , V_104 ,
V_21 -> V_111 ) ;
F_26 ( & V_10 -> V_50 ) ;
if ( V_97 == - 1 )
goto V_14;
}
F_15 () ;
}
F_12 () ;
F_67 (hard_iface_tmp, &hardif_list, list) {
if ( V_110 -> V_75 == V_77 )
continue;
if ( V_21 == V_110 )
continue;
if ( V_21 -> V_23 != V_110 -> V_23 )
continue;
if ( V_110 -> V_111 > V_21 -> V_111 )
V_110 -> V_111 -- ;
}
F_15 () ;
V_21 -> V_111 = - 1 ;
return 0 ;
V_14:
F_15 () ;
return - V_106 ;
}

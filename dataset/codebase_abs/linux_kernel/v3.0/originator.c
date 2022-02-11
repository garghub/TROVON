static void F_1 ( struct V_1 * V_1 )
{
F_2 ( & V_1 -> V_2 , V_3 ) ;
F_3 ( V_4 , & V_1 -> V_2 , 1 * V_5 ) ;
}
int F_4 ( struct V_1 * V_1 )
{
if ( V_1 -> V_6 )
return 1 ;
V_1 -> V_6 = F_5 ( 1024 ) ;
if ( ! V_1 -> V_6 )
goto V_7;
F_1 ( V_1 ) ;
return 1 ;
V_7:
return 0 ;
}
void F_6 ( struct V_8 * V_8 )
{
if ( F_7 ( & V_8 -> V_9 ) )
F_8 ( V_8 , V_10 ) ;
}
struct V_8 * F_9 ( struct V_11 * V_11 )
{
struct V_8 * V_12 ;
F_10 () ;
V_12 = F_11 ( V_11 -> V_12 ) ;
if ( V_12 && ! F_12 ( & V_12 -> V_9 ) )
V_12 = NULL ;
F_13 () ;
return V_12 ;
}
struct V_8 * F_14 ( struct V_11 * V_11 ,
struct V_11 * V_13 ,
T_1 * V_14 ,
struct V_15 * V_16 )
{
struct V_1 * V_1 = F_15 ( V_16 -> V_17 ) ;
struct V_8 * V_8 ;
F_16 ( V_18 , V_1 ,
L_1 ) ;
V_8 = F_17 ( sizeof( struct V_8 ) , V_19 ) ;
if ( ! V_8 )
return NULL ;
F_18 ( & V_8 -> V_20 ) ;
F_19 ( & V_8 -> V_21 ) ;
F_20 ( & V_8 -> V_22 ) ;
memcpy ( V_8 -> V_23 , V_14 , V_24 ) ;
V_8 -> V_11 = V_13 ;
V_8 -> V_16 = V_16 ;
F_21 ( & V_8 -> V_9 , 2 ) ;
F_22 ( & V_11 -> V_25 ) ;
F_23 ( & V_8 -> V_20 , & V_11 -> V_26 ) ;
F_24 ( & V_11 -> V_25 ) ;
return V_8 ;
}
static void F_25 ( struct V_27 * V_10 )
{
struct V_28 * V_29 , * V_30 ;
struct V_8 * V_8 , * V_31 ;
struct V_11 * V_11 ;
V_11 = F_26 ( V_10 , struct V_11 , V_10 ) ;
F_22 ( & V_11 -> V_25 ) ;
F_27 (neigh_node, tmp_neigh_node,
&orig_node->bond_list, bonding_list) {
F_28 ( & V_8 -> V_21 ) ;
F_6 ( V_8 ) ;
}
F_29 (neigh_node, node, node_tmp,
&orig_node->neigh_list, list) {
F_30 ( & V_8 -> V_20 ) ;
F_6 ( V_8 ) ;
}
F_24 ( & V_11 -> V_25 ) ;
F_31 ( & V_11 -> V_32 ) ;
F_32 ( V_11 -> V_1 , V_11 ,
L_2 ) ;
F_33 ( V_11 -> V_33 ) ;
F_33 ( V_11 -> V_34 ) ;
F_33 ( V_11 ) ;
}
void F_34 ( struct V_11 * V_11 )
{
if ( F_7 ( & V_11 -> V_9 ) )
F_35 ( & V_11 -> V_10 , F_25 ) ;
}
void F_36 ( struct V_1 * V_1 )
{
struct V_35 * V_36 = V_1 -> V_6 ;
struct V_28 * V_29 , * V_30 ;
struct V_37 * V_38 ;
T_2 * V_39 ;
struct V_11 * V_11 ;
int V_40 ;
if ( ! V_36 )
return;
F_37 ( & V_1 -> V_2 ) ;
V_1 -> V_6 = NULL ;
for ( V_40 = 0 ; V_40 < V_36 -> V_41 ; V_40 ++ ) {
V_38 = & V_36 -> V_42 [ V_40 ] ;
V_39 = & V_36 -> V_43 [ V_40 ] ;
F_22 ( V_39 ) ;
F_29 (orig_node, node, node_tmp,
head, hash_entry) {
F_30 ( V_29 ) ;
F_34 ( V_11 ) ;
}
F_24 ( V_39 ) ;
}
F_38 ( V_36 ) ;
}
struct V_11 * F_39 ( struct V_1 * V_1 , T_1 * V_23 )
{
struct V_11 * V_11 ;
int V_41 ;
int V_44 ;
V_11 = F_40 ( V_1 , V_23 ) ;
if ( V_11 )
return V_11 ;
F_16 ( V_18 , V_1 ,
L_3 , V_23 ) ;
V_11 = F_17 ( sizeof( struct V_11 ) , V_19 ) ;
if ( ! V_11 )
return NULL ;
F_41 ( & V_11 -> V_26 ) ;
F_19 ( & V_11 -> V_45 ) ;
F_20 ( & V_11 -> V_46 ) ;
F_20 ( & V_11 -> V_47 ) ;
F_20 ( & V_11 -> V_25 ) ;
F_21 ( & V_11 -> V_9 , 2 ) ;
V_11 -> V_1 = V_1 ;
memcpy ( V_11 -> V_48 , V_23 , V_24 ) ;
V_11 -> V_12 = NULL ;
V_11 -> V_49 = NULL ;
V_11 -> V_50 = V_51 - 1
- F_42 ( V_52 ) ;
V_11 -> V_53 = V_51 - 1
- F_42 ( V_52 ) ;
F_21 ( & V_11 -> V_54 , 0 ) ;
V_41 = V_1 -> V_55 * sizeof( unsigned long ) * V_56 ;
V_11 -> V_33 = F_17 ( V_41 , V_19 ) ;
if ( ! V_11 -> V_33 )
goto V_57;
V_41 = V_1 -> V_55 * sizeof( T_1 ) ;
V_11 -> V_34 = F_17 ( V_41 , V_19 ) ;
F_19 ( & V_11 -> V_32 ) ;
V_11 -> V_58 = 0 ;
if ( ! V_11 -> V_34 )
goto V_59;
V_44 = F_43 ( V_1 -> V_6 , V_60 ,
V_61 , V_11 , & V_11 -> V_62 ) ;
if ( V_44 < 0 )
goto V_63;
return V_11 ;
V_63:
F_33 ( V_11 -> V_34 ) ;
V_59:
F_33 ( V_11 -> V_33 ) ;
V_57:
F_33 ( V_11 ) ;
return NULL ;
}
static bool F_44 ( struct V_1 * V_1 ,
struct V_11 * V_11 ,
struct V_8 * * V_64 )
{
struct V_28 * V_29 , * V_30 ;
struct V_8 * V_8 ;
bool V_65 = false ;
* V_64 = NULL ;
F_22 ( & V_11 -> V_25 ) ;
F_29 (neigh_node, node, node_tmp,
&orig_node->neigh_list, list) {
if ( ( F_45 ( V_51 ,
V_8 -> V_66 + V_67 * V_5 ) ) ||
( V_8 -> V_16 -> V_68 == V_69 ) ||
( V_8 -> V_16 -> V_68 == V_70 ) ||
( V_8 -> V_16 -> V_68 == V_71 ) ) {
if ( ( V_8 -> V_16 -> V_68 ==
V_69 ) ||
( V_8 -> V_16 -> V_68 ==
V_70 ) ||
( V_8 -> V_16 -> V_68 ==
V_71 ) )
F_16 ( V_18 , V_1 ,
L_4
L_5 ,
V_11 -> V_48 , V_8 -> V_23 ,
V_8 -> V_16 -> V_72 -> V_73 ) ;
else
F_16 ( V_18 , V_1 ,
L_6
L_7 ,
V_11 -> V_48 , V_8 -> V_23 ,
( V_8 -> V_66 / V_5 ) ) ;
V_65 = true ;
F_30 ( & V_8 -> V_20 ) ;
F_46 ( V_11 , V_8 ) ;
F_6 ( V_8 ) ;
} else {
if ( ( ! * V_64 ) ||
( V_8 -> V_74 > ( * V_64 ) -> V_74 ) )
* V_64 = V_8 ;
}
}
F_24 ( & V_11 -> V_25 ) ;
return V_65 ;
}
static bool F_47 ( struct V_1 * V_1 ,
struct V_11 * V_11 )
{
struct V_8 * V_64 ;
if ( F_45 ( V_51 ,
V_11 -> V_66 + 2 * V_67 * V_5 ) ) {
F_16 ( V_18 , V_1 ,
L_8 ,
V_11 -> V_48 , ( V_11 -> V_66 / V_5 ) ) ;
return true ;
} else {
if ( F_44 ( V_1 , V_11 ,
& V_64 ) ) {
F_48 ( V_1 , V_11 ,
V_64 ,
V_11 -> V_49 ,
V_11 -> V_75 ) ;
}
}
return false ;
}
static void F_49 ( struct V_1 * V_1 )
{
struct V_35 * V_36 = V_1 -> V_6 ;
struct V_28 * V_29 , * V_30 ;
struct V_37 * V_38 ;
T_2 * V_39 ;
struct V_11 * V_11 ;
int V_40 ;
if ( ! V_36 )
return;
for ( V_40 = 0 ; V_40 < V_36 -> V_41 ; V_40 ++ ) {
V_38 = & V_36 -> V_42 [ V_40 ] ;
V_39 = & V_36 -> V_43 [ V_40 ] ;
F_22 ( V_39 ) ;
F_29 (orig_node, node, node_tmp,
head, hash_entry) {
if ( F_47 ( V_1 , V_11 ) ) {
if ( V_11 -> V_76 )
F_50 ( V_1 , V_11 ) ;
F_30 ( V_29 ) ;
F_34 ( V_11 ) ;
continue;
}
if ( F_45 ( V_51 , V_11 -> V_58 +
F_42 ( V_77 ) ) )
F_31 ( & V_11 -> V_32 ) ;
}
F_24 ( V_39 ) ;
}
F_51 ( V_1 ) ;
F_52 ( V_1 ) ;
F_53 ( V_1 ) ;
}
static void V_3 ( struct V_78 * V_79 )
{
struct V_80 * V_80 =
F_26 ( V_79 , struct V_80 , V_79 ) ;
struct V_1 * V_1 =
F_26 ( V_80 , struct V_1 , V_2 ) ;
F_49 ( V_1 ) ;
F_1 ( V_1 ) ;
}
void F_54 ( struct V_1 * V_1 )
{
F_49 ( V_1 ) ;
}
int F_55 ( struct V_81 * V_82 , void * V_83 )
{
struct V_84 * V_72 = (struct V_84 * ) V_82 -> V_85 ;
struct V_1 * V_1 = F_15 ( V_72 ) ;
struct V_35 * V_36 = V_1 -> V_6 ;
struct V_28 * V_29 , * V_30 ;
struct V_37 * V_38 ;
struct V_15 * V_86 ;
struct V_11 * V_11 ;
struct V_8 * V_8 , * V_87 ;
int V_88 = 0 ;
int V_89 ;
int V_90 ;
int V_40 , V_91 = 0 ;
V_86 = F_56 ( V_1 ) ;
if ( ! V_86 ) {
V_91 = F_57 ( V_82 , L_9
L_10 ,
V_72 -> V_73 ) ;
goto V_92;
}
if ( V_86 -> V_68 != V_93 ) {
V_91 = F_57 ( V_82 , L_11
L_12 ,
V_72 -> V_73 ) ;
goto V_92;
}
F_57 ( V_82 , L_13 ,
V_94 , V_95 ,
V_86 -> V_72 -> V_73 ,
V_86 -> V_72 -> V_96 , V_72 -> V_73 ) ;
F_57 ( V_82 , L_14 ,
L_15 , L_16 , L_17 , V_97 , L_18 ,
L_19 , L_20 ) ;
for ( V_40 = 0 ; V_40 < V_36 -> V_41 ; V_40 ++ ) {
V_38 = & V_36 -> V_42 [ V_40 ] ;
F_10 () ;
F_58 (orig_node, node, head, hash_entry) {
V_8 = F_9 ( V_11 ) ;
if ( ! V_8 )
continue;
if ( V_8 -> V_74 == 0 )
goto V_98;
V_89 = F_59 ( V_51 -
V_11 -> V_66 ) / 1000 ;
V_90 = F_59 ( V_51 -
V_11 -> V_66 ) % 1000 ;
F_57 ( V_82 , L_21 ,
V_11 -> V_48 , V_89 ,
V_90 , V_8 -> V_74 ,
V_8 -> V_23 ,
V_8 -> V_16 -> V_72 -> V_73 ) ;
F_58 (neigh_node_tmp, node_tmp,
&orig_node->neigh_list, list) {
F_57 ( V_82 , L_22 ,
V_87 -> V_23 ,
V_87 -> V_74 ) ;
}
F_57 ( V_82 , L_23 ) ;
V_88 ++ ;
V_98:
F_6 ( V_8 ) ;
}
F_13 () ;
}
if ( V_88 == 0 )
F_57 ( V_82 , L_24 ) ;
V_92:
if ( V_86 )
F_60 ( V_86 ) ;
return V_91 ;
}
static int F_61 ( struct V_11 * V_11 , int V_99 )
{
void * V_100 ;
V_100 = F_62 ( V_99 * sizeof( unsigned long ) * V_56 ,
V_19 ) ;
if ( ! V_100 ) {
F_63 ( L_25 ) ;
return - 1 ;
}
memcpy ( V_100 , V_11 -> V_33 ,
( V_99 - 1 ) * sizeof( unsigned long ) * V_56 ) ;
F_33 ( V_11 -> V_33 ) ;
V_11 -> V_33 = V_100 ;
V_100 = F_62 ( V_99 * sizeof( T_1 ) , V_19 ) ;
if ( ! V_100 ) {
F_63 ( L_25 ) ;
return - 1 ;
}
memcpy ( V_100 , V_11 -> V_34 ,
( V_99 - 1 ) * sizeof( T_1 ) ) ;
F_33 ( V_11 -> V_34 ) ;
V_11 -> V_34 = V_100 ;
return 0 ;
}
int F_64 ( struct V_15 * V_15 , int V_99 )
{
struct V_1 * V_1 = F_15 ( V_15 -> V_17 ) ;
struct V_35 * V_36 = V_1 -> V_6 ;
struct V_28 * V_29 ;
struct V_37 * V_38 ;
struct V_11 * V_11 ;
int V_40 , V_91 ;
for ( V_40 = 0 ; V_40 < V_36 -> V_41 ; V_40 ++ ) {
V_38 = & V_36 -> V_42 [ V_40 ] ;
F_10 () ;
F_58 (orig_node, node, head, hash_entry) {
F_22 ( & V_11 -> V_46 ) ;
V_91 = F_61 ( V_11 , V_99 ) ;
F_24 ( & V_11 -> V_46 ) ;
if ( V_91 == - 1 )
goto V_7;
}
F_13 () ;
}
return 0 ;
V_7:
F_13 () ;
return - V_101 ;
}
static int F_65 ( struct V_11 * V_11 ,
int V_99 , int V_102 )
{
void * V_100 = NULL ;
int V_103 ;
if ( V_99 == 0 )
goto V_59;
V_103 = sizeof( unsigned long ) * V_56 ;
V_100 = F_62 ( V_99 * V_103 , V_19 ) ;
if ( ! V_100 ) {
F_63 ( L_25 ) ;
return - 1 ;
}
memcpy ( V_100 , V_11 -> V_33 , V_102 * V_103 ) ;
memcpy ( V_100 + V_102 * V_103 ,
V_11 -> V_33 + ( ( V_102 + 1 ) * V_103 ) ,
( V_99 - V_102 ) * V_103 ) ;
V_59:
F_33 ( V_11 -> V_33 ) ;
V_11 -> V_33 = V_100 ;
if ( V_99 == 0 )
goto V_104;
V_100 = F_62 ( V_99 * sizeof( T_1 ) , V_19 ) ;
if ( ! V_100 ) {
F_63 ( L_25 ) ;
return - 1 ;
}
memcpy ( V_100 , V_11 -> V_34 ,
V_102 * sizeof( T_1 ) ) ;
memcpy ( V_100 + V_102 * sizeof( T_1 ) ,
V_11 -> V_34 + ( ( V_102 + 1 ) * sizeof( T_1 ) ) ,
( V_99 - V_102 ) * sizeof( T_1 ) ) ;
V_104:
F_33 ( V_11 -> V_34 ) ;
V_11 -> V_34 = V_100 ;
return 0 ;
}
int F_66 ( struct V_15 * V_15 , int V_99 )
{
struct V_1 * V_1 = F_15 ( V_15 -> V_17 ) ;
struct V_35 * V_36 = V_1 -> V_6 ;
struct V_28 * V_29 ;
struct V_37 * V_38 ;
struct V_15 * V_105 ;
struct V_11 * V_11 ;
int V_40 , V_91 ;
for ( V_40 = 0 ; V_40 < V_36 -> V_41 ; V_40 ++ ) {
V_38 = & V_36 -> V_42 [ V_40 ] ;
F_10 () ;
F_58 (orig_node, node, head, hash_entry) {
F_22 ( & V_11 -> V_46 ) ;
V_91 = F_65 ( V_11 , V_99 ,
V_15 -> V_106 ) ;
F_24 ( & V_11 -> V_46 ) ;
if ( V_91 == - 1 )
goto V_7;
}
F_13 () ;
}
F_10 () ;
F_67 (hard_iface_tmp, &hardif_list, list) {
if ( V_105 -> V_68 == V_70 )
continue;
if ( V_15 == V_105 )
continue;
if ( V_15 -> V_17 != V_105 -> V_17 )
continue;
if ( V_105 -> V_106 > V_15 -> V_106 )
V_105 -> V_106 -- ;
}
F_13 () ;
V_15 -> V_106 = - 1 ;
return 0 ;
V_7:
F_13 () ;
return - V_101 ;
}

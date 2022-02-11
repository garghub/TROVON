static void F_1 ( struct V_1 * V_1 )
{
F_2 ( & V_1 -> V_2 , V_3 ) ;
F_3 ( V_4 ,
& V_1 -> V_2 , F_4 ( 1000 ) ) ;
}
static int F_5 ( const struct V_5 * V_6 , const void * V_7 )
{
const void * V_8 = F_6 ( V_6 , struct V_9 , V_10 ) ;
return ( memcmp ( V_8 , V_7 , V_11 ) == 0 ? 1 : 0 ) ;
}
int F_7 ( struct V_1 * V_1 )
{
if ( V_1 -> V_12 )
return 1 ;
V_1 -> V_12 = F_8 ( 1024 ) ;
if ( ! V_1 -> V_12 )
goto V_13;
F_1 ( V_1 ) ;
return 1 ;
V_13:
return 0 ;
}
void F_9 ( struct V_14 * V_14 )
{
if ( F_10 ( & V_14 -> V_15 ) )
F_11 ( V_14 , V_16 ) ;
}
struct V_14 * F_12 ( struct V_9 * V_9 )
{
struct V_14 * V_17 ;
F_13 () ;
V_17 = F_14 ( V_9 -> V_17 ) ;
if ( V_17 && ! F_15 ( & V_17 -> V_15 ) )
V_17 = NULL ;
F_16 () ;
return V_17 ;
}
struct V_14 * F_17 ( struct V_18 * V_18 ,
const T_1 * V_19 ,
T_2 V_20 )
{
struct V_1 * V_1 = F_18 ( V_18 -> V_21 ) ;
struct V_14 * V_14 ;
V_14 = F_19 ( sizeof( * V_14 ) , V_22 ) ;
if ( ! V_14 )
goto V_23;
F_20 ( & V_14 -> V_24 ) ;
memcpy ( V_14 -> V_25 , V_19 , V_11 ) ;
F_21 ( & V_14 -> V_26 ) ;
F_22 ( & V_14 -> V_15 , 2 ) ;
F_23 ( V_27 , V_1 ,
L_1 ,
V_19 , V_20 ) ;
V_23:
return V_14 ;
}
static void F_24 ( struct V_28 * V_16 )
{
struct V_5 * V_6 , * V_29 ;
struct V_14 * V_14 , * V_30 ;
struct V_9 * V_9 ;
V_9 = F_6 ( V_16 , struct V_9 , V_16 ) ;
F_25 ( & V_9 -> V_31 ) ;
F_26 (neigh_node, tmp_neigh_node,
&orig_node->bond_list, bonding_list) {
F_27 ( & V_14 -> V_32 ) ;
F_9 ( V_14 ) ;
}
F_28 (neigh_node, node, node_tmp,
&orig_node->neigh_list, list) {
F_29 ( & V_14 -> V_24 ) ;
F_9 ( V_14 ) ;
}
F_30 ( & V_9 -> V_31 ) ;
F_31 ( & V_9 -> V_33 ) ;
F_32 ( V_9 -> V_1 , V_9 ,
L_2 ) ;
F_33 ( V_9 -> V_34 ) ;
F_33 ( V_9 -> V_35 ) ;
F_33 ( V_9 -> V_36 ) ;
F_33 ( V_9 ) ;
}
void F_34 ( struct V_9 * V_9 )
{
if ( F_10 ( & V_9 -> V_15 ) )
F_35 ( & V_9 -> V_16 , F_24 ) ;
}
void F_36 ( struct V_1 * V_1 )
{
struct V_37 * V_38 = V_1 -> V_12 ;
struct V_5 * V_6 , * V_29 ;
struct V_39 * V_40 ;
T_3 * V_41 ;
struct V_9 * V_9 ;
T_2 V_42 ;
if ( ! V_38 )
return;
F_37 ( & V_1 -> V_2 ) ;
V_1 -> V_12 = NULL ;
for ( V_42 = 0 ; V_42 < V_38 -> V_43 ; V_42 ++ ) {
V_40 = & V_38 -> V_44 [ V_42 ] ;
V_41 = & V_38 -> V_45 [ V_42 ] ;
F_25 ( V_41 ) ;
F_28 (orig_node, node, node_tmp,
head, hash_entry) {
F_29 ( V_6 ) ;
F_34 ( V_9 ) ;
}
F_30 ( V_41 ) ;
}
F_38 ( V_38 ) ;
}
struct V_9 * F_39 ( struct V_1 * V_1 , const T_1 * V_25 )
{
struct V_9 * V_9 ;
int V_43 ;
int V_46 ;
V_9 = F_40 ( V_1 , V_25 ) ;
if ( V_9 )
return V_9 ;
F_23 ( V_27 , V_1 ,
L_3 , V_25 ) ;
V_9 = F_19 ( sizeof( * V_9 ) , V_22 ) ;
if ( ! V_9 )
return NULL ;
F_41 ( & V_9 -> V_47 ) ;
F_42 ( & V_9 -> V_48 ) ;
F_21 ( & V_9 -> V_49 ) ;
F_21 ( & V_9 -> V_50 ) ;
F_21 ( & V_9 -> V_31 ) ;
F_21 ( & V_9 -> V_51 ) ;
F_22 ( & V_9 -> V_15 , 2 ) ;
V_9 -> V_52 = false ;
V_9 -> V_53 = false ;
V_9 -> V_1 = V_1 ;
memcpy ( V_9 -> V_54 , V_25 , V_11 ) ;
V_9 -> V_17 = NULL ;
V_9 -> V_55 = 0 ;
F_22 ( & V_9 -> V_56 , 0 ) ;
V_9 -> V_34 = NULL ;
V_9 -> V_57 = 0 ;
F_22 ( & V_9 -> V_58 , 0 ) ;
V_9 -> V_59 = V_60 - 1
- F_4 ( V_61 ) ;
V_9 -> V_62 = V_60 - 1
- F_4 ( V_61 ) ;
F_22 ( & V_9 -> V_63 , 0 ) ;
V_43 = V_1 -> V_64 * sizeof( unsigned long ) * V_65 ;
V_9 -> V_35 = F_19 ( V_43 , V_22 ) ;
if ( ! V_9 -> V_35 )
goto V_66;
V_43 = V_1 -> V_64 * sizeof( T_1 ) ;
V_9 -> V_36 = F_19 ( V_43 , V_22 ) ;
F_42 ( & V_9 -> V_33 ) ;
V_9 -> V_67 = 0 ;
if ( ! V_9 -> V_36 )
goto V_68;
V_46 = F_43 ( V_1 -> V_12 , F_5 ,
V_69 , V_9 , & V_9 -> V_10 ) ;
if ( V_46 != 0 )
goto V_70;
return V_9 ;
V_70:
F_33 ( V_9 -> V_36 ) ;
V_68:
F_33 ( V_9 -> V_35 ) ;
V_66:
F_33 ( V_9 ) ;
return NULL ;
}
static bool F_44 ( struct V_1 * V_1 ,
struct V_9 * V_9 ,
struct V_14 * * V_71 )
{
struct V_5 * V_6 , * V_29 ;
struct V_14 * V_14 ;
bool V_72 = false ;
unsigned long V_73 ;
* V_71 = NULL ;
F_25 ( & V_9 -> V_31 ) ;
F_28 (neigh_node, node, node_tmp,
&orig_node->neigh_list, list) {
if ( ( F_45 ( V_14 -> V_73 , V_74 ) ) ||
( V_14 -> V_75 -> V_76 == V_77 ) ||
( V_14 -> V_75 -> V_76 == V_78 ) ||
( V_14 -> V_75 -> V_76 == V_79 ) ) {
V_73 = V_14 -> V_73 ;
if ( ( V_14 -> V_75 -> V_76 ==
V_77 ) ||
( V_14 -> V_75 -> V_76 ==
V_78 ) ||
( V_14 -> V_75 -> V_76 ==
V_79 ) )
F_23 ( V_27 , V_1 ,
L_4 ,
V_9 -> V_54 , V_14 -> V_25 ,
V_14 -> V_75 -> V_80 -> V_81 ) ;
else
F_23 ( V_27 , V_1 ,
L_5 ,
V_9 -> V_54 , V_14 -> V_25 ,
F_46 ( V_73 ) ) ;
V_72 = true ;
F_29 ( & V_14 -> V_24 ) ;
F_47 ( V_9 , V_14 ) ;
F_9 ( V_14 ) ;
} else {
if ( ( ! * V_71 ) ||
( V_14 -> V_82 > ( * V_71 ) -> V_82 ) )
* V_71 = V_14 ;
}
}
F_30 ( & V_9 -> V_31 ) ;
return V_72 ;
}
static bool F_48 ( struct V_1 * V_1 ,
struct V_9 * V_9 )
{
struct V_14 * V_71 ;
if ( F_45 ( V_9 -> V_73 , 2 * V_74 ) ) {
F_23 ( V_27 , V_1 ,
L_6 ,
V_9 -> V_54 ,
F_46 ( V_9 -> V_73 ) ) ;
return true ;
} else {
if ( F_44 ( V_1 , V_9 ,
& V_71 ) )
F_49 ( V_1 , V_9 , V_71 ) ;
}
return false ;
}
static void F_50 ( struct V_1 * V_1 )
{
struct V_37 * V_38 = V_1 -> V_12 ;
struct V_5 * V_6 , * V_29 ;
struct V_39 * V_40 ;
T_3 * V_41 ;
struct V_9 * V_9 ;
T_2 V_42 ;
if ( ! V_38 )
return;
for ( V_42 = 0 ; V_42 < V_38 -> V_43 ; V_42 ++ ) {
V_40 = & V_38 -> V_44 [ V_42 ] ;
V_41 = & V_38 -> V_45 [ V_42 ] ;
F_25 ( V_41 ) ;
F_28 (orig_node, node, node_tmp,
head, hash_entry) {
if ( F_48 ( V_1 , V_9 ) ) {
if ( V_9 -> V_83 )
F_51 ( V_1 , V_9 ) ;
F_29 ( V_6 ) ;
F_34 ( V_9 ) ;
continue;
}
if ( F_45 ( V_9 -> V_67 ,
V_84 ) )
F_31 ( & V_9 -> V_33 ) ;
}
F_30 ( V_41 ) ;
}
F_52 ( V_1 ) ;
F_53 ( V_1 ) ;
}
static void V_3 ( struct V_85 * V_86 )
{
struct V_87 * V_87 =
F_6 ( V_86 , struct V_87 , V_86 ) ;
struct V_1 * V_1 =
F_6 ( V_87 , struct V_1 , V_2 ) ;
F_50 ( V_1 ) ;
F_1 ( V_1 ) ;
}
void F_54 ( struct V_1 * V_1 )
{
F_50 ( V_1 ) ;
}
int F_55 ( struct V_88 * V_89 , void * V_90 )
{
struct V_91 * V_80 = (struct V_91 * ) V_89 -> V_92 ;
struct V_1 * V_1 = F_18 ( V_80 ) ;
struct V_37 * V_38 = V_1 -> V_12 ;
struct V_5 * V_6 , * V_29 ;
struct V_39 * V_40 ;
struct V_18 * V_93 ;
struct V_9 * V_9 ;
struct V_14 * V_14 , * V_94 ;
int V_95 = 0 ;
int V_96 ;
int V_97 ;
T_2 V_42 ;
int V_98 = 0 ;
V_93 = F_56 ( V_1 ) ;
if ( ! V_93 ) {
V_98 = F_57 ( V_89 ,
L_7 ,
V_80 -> V_81 ) ;
goto V_23;
}
if ( V_93 -> V_76 != V_99 ) {
V_98 = F_57 ( V_89 ,
L_8 ,
V_80 -> V_81 ) ;
goto V_23;
}
F_57 ( V_89 , L_9 ,
V_100 , V_93 -> V_80 -> V_81 ,
V_93 -> V_80 -> V_101 , V_80 -> V_81 ) ;
F_57 ( V_89 , L_10 ,
L_11 , L_12 , L_13 , V_102 , L_14 ,
L_15 , L_16 ) ;
for ( V_42 = 0 ; V_42 < V_38 -> V_43 ; V_42 ++ ) {
V_40 = & V_38 -> V_44 [ V_42 ] ;
F_13 () ;
F_58 (orig_node, node, head, hash_entry) {
V_14 = F_12 ( V_9 ) ;
if ( ! V_14 )
continue;
if ( V_14 -> V_82 == 0 )
goto V_103;
V_96 = F_46 ( V_60 -
V_9 -> V_73 ) / 1000 ;
V_97 = F_46 ( V_60 -
V_9 -> V_73 ) % 1000 ;
F_57 ( V_89 , L_17 ,
V_9 -> V_54 , V_96 ,
V_97 , V_14 -> V_82 ,
V_14 -> V_25 ,
V_14 -> V_75 -> V_80 -> V_81 ) ;
F_58 (neigh_node_tmp, node_tmp,
&orig_node->neigh_list, list) {
F_57 ( V_89 , L_18 ,
V_94 -> V_25 ,
V_94 -> V_82 ) ;
}
F_57 ( V_89 , L_19 ) ;
V_95 ++ ;
V_103:
F_9 ( V_14 ) ;
}
F_16 () ;
}
if ( V_95 == 0 )
F_57 ( V_89 , L_20 ) ;
V_23:
if ( V_93 )
F_59 ( V_93 ) ;
return V_98 ;
}
static int F_60 ( struct V_9 * V_9 , int V_104 )
{
void * V_105 ;
V_105 = F_61 ( V_104 * sizeof( unsigned long ) * V_65 ,
V_22 ) ;
if ( ! V_105 )
return - 1 ;
memcpy ( V_105 , V_9 -> V_35 ,
( V_104 - 1 ) * sizeof( unsigned long ) * V_65 ) ;
F_33 ( V_9 -> V_35 ) ;
V_9 -> V_35 = V_105 ;
V_105 = F_61 ( V_104 * sizeof( T_1 ) , V_22 ) ;
if ( ! V_105 )
return - 1 ;
memcpy ( V_105 , V_9 -> V_36 ,
( V_104 - 1 ) * sizeof( T_1 ) ) ;
F_33 ( V_9 -> V_36 ) ;
V_9 -> V_36 = V_105 ;
return 0 ;
}
int F_62 ( struct V_18 * V_18 , int V_104 )
{
struct V_1 * V_1 = F_18 ( V_18 -> V_21 ) ;
struct V_37 * V_38 = V_1 -> V_12 ;
struct V_5 * V_6 ;
struct V_39 * V_40 ;
struct V_9 * V_9 ;
T_2 V_42 ;
int V_98 ;
for ( V_42 = 0 ; V_42 < V_38 -> V_43 ; V_42 ++ ) {
V_40 = & V_38 -> V_44 [ V_42 ] ;
F_13 () ;
F_58 (orig_node, node, head, hash_entry) {
F_25 ( & V_9 -> V_49 ) ;
V_98 = F_60 ( V_9 , V_104 ) ;
F_30 ( & V_9 -> V_49 ) ;
if ( V_98 == - 1 )
goto V_13;
}
F_16 () ;
}
return 0 ;
V_13:
F_16 () ;
return - V_106 ;
}
static int F_63 ( struct V_9 * V_9 ,
int V_104 , int V_107 )
{
void * V_105 = NULL ;
int V_108 ;
if ( V_104 == 0 )
goto V_68;
V_108 = sizeof( unsigned long ) * V_65 ;
V_105 = F_61 ( V_104 * V_108 , V_22 ) ;
if ( ! V_105 )
return - 1 ;
memcpy ( V_105 , V_9 -> V_35 , V_107 * V_108 ) ;
memcpy ( ( char * ) V_105 + V_107 * V_108 ,
V_9 -> V_35 + ( ( V_107 + 1 ) * V_108 ) ,
( V_104 - V_107 ) * V_108 ) ;
V_68:
F_33 ( V_9 -> V_35 ) ;
V_9 -> V_35 = V_105 ;
if ( V_104 == 0 )
goto V_109;
V_105 = F_61 ( V_104 * sizeof( T_1 ) , V_22 ) ;
if ( ! V_105 )
return - 1 ;
memcpy ( V_105 , V_9 -> V_36 ,
V_107 * sizeof( T_1 ) ) ;
memcpy ( ( char * ) V_105 + V_107 * sizeof( T_1 ) ,
V_9 -> V_36 + ( ( V_107 + 1 ) * sizeof( T_1 ) ) ,
( V_104 - V_107 ) * sizeof( T_1 ) ) ;
V_109:
F_33 ( V_9 -> V_36 ) ;
V_9 -> V_36 = V_105 ;
return 0 ;
}
int F_64 ( struct V_18 * V_18 , int V_104 )
{
struct V_1 * V_1 = F_18 ( V_18 -> V_21 ) ;
struct V_37 * V_38 = V_1 -> V_12 ;
struct V_5 * V_6 ;
struct V_39 * V_40 ;
struct V_18 * V_110 ;
struct V_9 * V_9 ;
T_2 V_42 ;
int V_98 ;
for ( V_42 = 0 ; V_42 < V_38 -> V_43 ; V_42 ++ ) {
V_40 = & V_38 -> V_44 [ V_42 ] ;
F_13 () ;
F_58 (orig_node, node, head, hash_entry) {
F_25 ( & V_9 -> V_49 ) ;
V_98 = F_63 ( V_9 , V_104 ,
V_18 -> V_111 ) ;
F_30 ( & V_9 -> V_49 ) ;
if ( V_98 == - 1 )
goto V_13;
}
F_16 () ;
}
F_13 () ;
F_65 (hard_iface_tmp, &hardif_list, list) {
if ( V_110 -> V_76 == V_78 )
continue;
if ( V_18 == V_110 )
continue;
if ( V_18 -> V_21 != V_110 -> V_21 )
continue;
if ( V_110 -> V_111 > V_18 -> V_111 )
V_110 -> V_111 -- ;
}
F_16 () ;
V_18 -> V_111 = - 1 ;
return 0 ;
V_13:
F_16 () ;
return - V_106 ;
}

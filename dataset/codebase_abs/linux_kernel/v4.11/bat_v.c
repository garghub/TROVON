static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_1 * V_6 ;
V_6 = F_3 ( V_4 ) ;
if ( V_6 ) {
F_4 ( V_6 , V_2 ) ;
F_5 ( V_6 ) ;
}
if ( V_2 -> V_7 == V_8 )
V_2 -> V_7 = V_9 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_10 ;
V_10 = F_7 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_8 ( V_2 ) ;
if ( V_10 < 0 )
F_9 ( V_2 ) ;
return V_10 ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_9 ( V_2 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
F_13 ( V_2 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_1 * V_6 ;
V_6 = F_3 ( V_4 ) ;
if ( V_6 != V_2 )
goto V_11;
F_11 ( V_2 ) ;
V_11:
if ( V_6 )
F_5 ( V_6 ) ;
}
static void
F_15 ( struct V_12 * V_13 )
{
F_16 ( & V_13 -> V_14 . V_15 ) ;
F_17 ( & V_13 -> V_14 . V_16 ,
V_17 ) ;
}
static void
F_18 ( struct V_18 * V_19 ,
struct V_1 * V_20 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 ;
struct V_25 * V_26 ;
F_19 (neigh_node, &orig_node->neigh_list, list) {
V_26 = F_20 ( V_24 , V_20 ) ;
if ( ! V_26 )
continue;
F_21 ( V_22 , L_1 ,
V_24 -> V_27 ,
V_26 -> V_14 . V_15 / 10 ,
V_26 -> V_14 . V_15 % 10 ) ;
F_22 ( V_26 ) ;
}
}
static void
F_23 ( struct V_21 * V_22 ,
struct V_12 * V_13 )
{
int V_28 , V_29 ;
T_1 V_15 ;
V_28 = F_24 ( V_30 - V_13 -> V_31 ) / 1000 ;
V_29 = F_24 ( V_30 - V_13 -> V_31 ) % 1000 ;
V_15 = F_25 ( & V_13 -> V_14 . V_15 ) ;
F_21 ( V_22 , L_2 ,
V_13 -> V_27 , V_28 , V_29 , V_15 / 10 ,
V_15 % 10 , V_13 -> V_32 -> V_33 -> V_34 ) ;
}
static void F_26 ( struct V_3 * V_4 ,
struct V_21 * V_22 )
{
struct V_35 * V_33 = (struct V_35 * ) V_22 -> V_36 ;
struct V_12 * V_13 ;
struct V_1 * V_2 ;
int V_37 = 0 ;
F_27 ( V_22 ,
L_3 ) ;
F_28 () ;
F_29 (hard_iface, &batadv_hardif_list, list) {
if ( V_2 -> V_5 != V_33 )
continue;
F_19 (hardif_neigh,
&hard_iface->neigh_list, list) {
F_23 ( V_22 , V_13 ) ;
V_37 ++ ;
}
}
F_30 () ;
if ( V_37 == 0 )
F_27 ( V_22 , L_4 ) ;
}
static int
F_31 ( struct V_38 * V_39 , T_1 V_40 , T_1 V_22 ,
struct V_12 * V_13 )
{
void * V_41 ;
unsigned int V_42 ;
T_1 V_15 ;
V_42 = F_24 ( V_30 - V_13 -> V_31 ) ;
V_15 = F_25 ( & V_13 -> V_14 . V_15 ) ;
V_15 = V_15 * 100 ;
V_41 = F_32 ( V_39 , V_40 , V_22 , & V_43 , V_44 ,
V_45 ) ;
if ( ! V_41 )
return - V_46 ;
if ( F_33 ( V_39 , V_47 , V_48 ,
V_13 -> V_27 ) ||
F_34 ( V_39 , V_49 ,
V_13 -> V_32 -> V_33 -> V_50 ) ||
F_34 ( V_39 , V_51 ,
V_42 ) ||
F_34 ( V_39 , V_52 , V_15 ) )
goto V_53;
F_35 ( V_39 , V_41 ) ;
return 0 ;
V_53:
F_36 ( V_39 , V_41 ) ;
return - V_54 ;
}
static int
F_37 ( struct V_38 * V_39 , T_1 V_40 , T_1 V_22 ,
struct V_3 * V_4 ,
struct V_1 * V_2 ,
int * V_55 )
{
struct V_12 * V_13 ;
int V_56 = 0 ;
F_19 (hardif_neigh,
&hard_iface->neigh_list, list) {
if ( V_56 ++ < * V_55 )
continue;
if ( F_31 ( V_39 , V_40 , V_22 , V_13 ) ) {
* V_55 = V_56 - 1 ;
return - V_54 ;
}
}
* V_55 = 0 ;
return 0 ;
}
static void
F_38 ( struct V_38 * V_39 , struct V_57 * V_58 ,
struct V_3 * V_4 ,
struct V_1 * V_59 )
{
struct V_1 * V_2 ;
int V_60 = 0 ;
int V_61 = V_58 -> args [ 0 ] ;
int V_56 = V_58 -> args [ 1 ] ;
int V_40 = F_39 ( V_58 -> V_62 ) . V_40 ;
F_28 () ;
if ( V_59 ) {
if ( V_61 == 0 ) {
if ( F_37 ( V_39 , V_40 ,
V_58 -> V_63 -> V_64 ,
V_4 , V_59 ,
& V_56 ) == 0 )
V_60 ++ ;
}
} else {
F_29 (hard_iface, &batadv_hardif_list, list) {
if ( V_2 -> V_5 != V_4 -> V_5 )
continue;
if ( V_60 ++ < V_61 )
continue;
if ( F_37 ( V_39 , V_40 ,
V_58 -> V_63 -> V_64 ,
V_4 , V_2 ,
& V_56 ) ) {
V_60 -- ;
break;
}
}
}
F_30 () ;
V_58 -> args [ 0 ] = V_60 ;
V_58 -> args [ 1 ] = V_56 ;
}
static void F_40 ( struct V_3 * V_4 ,
struct V_21 * V_22 ,
struct V_1 * V_20 )
{
struct V_23 * V_24 ;
struct V_65 * V_66 = V_4 -> V_67 ;
int V_42 , V_68 ;
struct V_18 * V_19 ;
struct V_25 * V_26 ;
unsigned long V_69 ;
struct V_70 * V_71 ;
int V_37 = 0 ;
T_1 V_72 ;
F_27 ( V_22 ,
L_5 ) ;
for ( V_72 = 0 ; V_72 < V_66 -> V_73 ; V_72 ++ ) {
V_71 = & V_66 -> V_74 [ V_72 ] ;
F_28 () ;
F_19 (orig_node, head, hash_entry) {
V_24 = F_41 ( V_19 ,
V_20 ) ;
if ( ! V_24 )
continue;
V_26 = F_20 ( V_24 ,
V_20 ) ;
if ( ! V_26 )
goto V_75;
V_69 = V_30 - V_19 -> V_31 ;
V_42 = F_24 ( V_69 ) ;
V_68 = V_42 / 1000 ;
V_42 = V_42 % 1000 ;
F_21 ( V_22 , L_6 ,
V_19 -> V_76 , V_68 ,
V_42 ,
V_26 -> V_14 . V_15 / 10 ,
V_26 -> V_14 . V_15 % 10 ,
V_24 -> V_27 ,
V_24 -> V_32 -> V_33 -> V_34 ) ;
F_18 ( V_19 , V_20 , V_22 ) ;
F_27 ( V_22 , L_7 ) ;
V_37 ++ ;
V_75:
F_42 ( V_24 ) ;
if ( V_26 )
F_22 ( V_26 ) ;
}
F_30 () ;
}
if ( V_37 == 0 )
F_27 ( V_22 , L_4 ) ;
}
static int
F_43 ( struct V_38 * V_39 , T_1 V_40 , T_1 V_22 ,
struct V_3 * V_4 ,
struct V_1 * V_20 ,
struct V_18 * V_19 ,
struct V_23 * V_24 ,
bool V_77 )
{
struct V_25 * V_26 ;
unsigned int V_42 ;
T_1 V_15 ;
void * V_41 ;
V_26 = F_20 ( V_24 , V_20 ) ;
if ( ! V_26 )
return 0 ;
V_15 = V_26 -> V_14 . V_15 * 100 ;
F_22 ( V_26 ) ;
V_42 = F_24 ( V_30 - V_19 -> V_31 ) ;
if ( V_20 != V_78 &&
V_20 != V_24 -> V_32 )
return 0 ;
V_41 = F_32 ( V_39 , V_40 , V_22 , & V_43 , V_44 ,
V_79 ) ;
if ( ! V_41 )
return - V_46 ;
if ( F_33 ( V_39 , V_80 , V_48 , V_19 -> V_76 ) ||
F_33 ( V_39 , V_47 , V_48 ,
V_24 -> V_27 ) ||
F_34 ( V_39 , V_49 ,
V_24 -> V_32 -> V_33 -> V_50 ) ||
F_34 ( V_39 , V_52 , V_15 ) ||
F_34 ( V_39 , V_51 ,
V_42 ) )
goto V_53;
if ( V_77 && F_44 ( V_39 , V_81 ) )
goto V_53;
F_35 ( V_39 , V_41 ) ;
return 0 ;
V_53:
F_36 ( V_39 , V_41 ) ;
return - V_54 ;
}
static int
F_45 ( struct V_38 * V_39 , T_1 V_40 , T_1 V_22 ,
struct V_3 * V_4 ,
struct V_1 * V_20 ,
struct V_18 * V_19 , int * V_82 )
{
struct V_23 * V_83 ;
struct V_23 * V_24 ;
int V_84 = 0 ;
bool V_77 ;
V_83 = F_41 ( V_19 , V_20 ) ;
if ( ! V_83 )
goto V_11;
F_19 (neigh_node, &orig_node->neigh_list, list) {
if ( V_84 ++ < * V_82 )
continue;
V_77 = ( V_24 == V_83 ) ;
if ( F_43 ( V_39 , V_40 , V_22 , V_4 ,
V_20 , V_19 ,
V_24 , V_77 ) ) {
F_42 ( V_83 ) ;
* V_82 = V_84 - 1 ;
return - V_54 ;
}
}
V_11:
if ( V_83 )
F_42 ( V_83 ) ;
* V_82 = 0 ;
return 0 ;
}
static int
F_46 ( struct V_38 * V_39 , T_1 V_40 , T_1 V_22 ,
struct V_3 * V_4 ,
struct V_1 * V_20 ,
struct V_70 * V_71 , int * V_55 , int * V_84 )
{
struct V_18 * V_19 ;
int V_56 = 0 ;
F_28 () ;
F_19 (orig_node, head, hash_entry) {
if ( V_56 ++ < * V_55 )
continue;
if ( F_45 ( V_39 , V_40 , V_22 , V_4 ,
V_20 , V_19 , V_84 ) ) {
F_30 () ;
* V_55 = V_56 - 1 ;
return - V_54 ;
}
}
F_30 () ;
* V_55 = 0 ;
* V_84 = 0 ;
return 0 ;
}
static void
F_47 ( struct V_38 * V_39 , struct V_57 * V_58 ,
struct V_3 * V_4 ,
struct V_1 * V_20 )
{
struct V_65 * V_66 = V_4 -> V_67 ;
struct V_70 * V_71 ;
int V_85 = V_58 -> args [ 0 ] ;
int V_56 = V_58 -> args [ 1 ] ;
int V_84 = V_58 -> args [ 2 ] ;
int V_40 = F_39 ( V_58 -> V_62 ) . V_40 ;
while ( V_85 < V_66 -> V_73 ) {
V_71 = & V_66 -> V_74 [ V_85 ] ;
if ( F_46 ( V_39 , V_40 ,
V_58 -> V_63 -> V_64 ,
V_4 , V_20 , V_71 , & V_56 ,
& V_84 ) )
break;
V_85 ++ ;
}
V_58 -> args [ 0 ] = V_85 ;
V_58 -> args [ 1 ] = V_56 ;
V_58 -> args [ 2 ] = V_84 ;
}
static int F_48 ( struct V_23 * V_86 ,
struct V_1 * V_87 ,
struct V_23 * V_88 ,
struct V_1 * V_89 )
{
struct V_25 * V_90 , * V_91 ;
int V_10 = 0 ;
V_90 = F_20 ( V_86 , V_87 ) ;
if ( F_49 ( ! V_90 ) )
goto V_92;
V_91 = F_20 ( V_88 , V_89 ) ;
if ( F_49 ( ! V_91 ) )
goto V_93;
V_10 = V_90 -> V_14 . V_15 - V_91 -> V_14 . V_15 ;
F_22 ( V_91 ) ;
V_93:
F_22 ( V_90 ) ;
V_92:
return V_10 ;
}
static bool F_50 ( struct V_23 * V_86 ,
struct V_1 * V_87 ,
struct V_23 * V_88 ,
struct V_1 * V_89 )
{
struct V_25 * V_90 , * V_91 ;
T_1 V_94 ;
bool V_10 = false ;
V_90 = F_20 ( V_86 , V_87 ) ;
if ( F_49 ( ! V_90 ) )
goto V_92;
V_91 = F_20 ( V_88 , V_89 ) ;
if ( F_49 ( ! V_91 ) )
goto V_93;
V_94 = V_90 -> V_14 . V_15 / 4 ;
V_94 = V_90 -> V_14 . V_15 - V_94 ;
V_10 = V_91 -> V_14 . V_15 > V_94 ;
F_22 ( V_91 ) ;
V_93:
F_22 ( V_90 ) ;
V_92:
return V_10 ;
}
static void F_51 ( struct V_3 * V_4 )
{
F_52 ( & V_4 -> V_95 . V_96 , 50 ) ;
}
static T_2 F_53 ( struct V_3 * V_4 ,
char * V_97 , T_3 V_98 )
{
T_1 V_99 , V_100 ;
if ( ! F_54 ( V_4 -> V_5 , V_97 ,
L_8 ,
& V_100 ) )
return - V_101 ;
V_99 = F_55 ( & V_4 -> V_95 . V_96 ) ;
F_52 ( & V_4 -> V_95 . V_96 , V_100 ) ;
if ( V_99 != V_100 )
F_56 ( V_4 ) ;
return V_98 ;
}
static T_2 F_57 ( struct V_3 * V_4 , char * V_97 )
{
T_1 V_100 = F_55 ( & V_4 -> V_95 . V_96 ) ;
return sprintf ( V_97 , L_9 , V_100 / 10 , V_100 % 10 ) ;
}
static int F_58 ( struct V_102 * V_103 , T_1 * V_104 )
{
struct V_25 * V_105 = NULL ;
struct V_18 * V_19 ;
struct V_23 * V_106 ;
int V_10 = - 1 ;
V_19 = V_103 -> V_19 ;
V_106 = F_41 ( V_19 , V_78 ) ;
if ( ! V_106 )
goto V_11;
V_105 = F_20 ( V_106 , V_78 ) ;
if ( ! V_105 )
goto V_11;
* V_104 = V_105 -> V_14 . V_15 ;
* V_104 = F_59 ( T_1 , * V_104 , V_103 -> V_107 ) ;
V_10 = 0 ;
V_11:
if ( V_106 )
F_42 ( V_106 ) ;
if ( V_105 )
F_22 ( V_105 ) ;
return V_10 ;
}
static struct V_102 *
F_60 ( struct V_3 * V_4 )
{
struct V_102 * V_103 , * V_108 = NULL ;
T_1 V_109 = 0 , V_104 ;
F_28 () ;
F_19 (gw_node, &bat_priv->gw.gateway_list, list) {
if ( ! F_61 ( & V_103 -> V_110 ) )
continue;
if ( F_58 ( V_103 , & V_104 ) < 0 )
goto V_75;
if ( V_108 && ( V_104 <= V_109 ) )
goto V_75;
if ( V_108 )
F_62 ( V_108 ) ;
V_108 = V_103 ;
F_63 ( & V_108 -> V_110 ) ;
V_109 = V_104 ;
V_75:
F_62 ( V_103 ) ;
}
F_30 () ;
return V_108 ;
}
static bool F_64 ( struct V_3 * V_4 ,
struct V_18 * V_111 ,
struct V_18 * V_19 )
{
struct V_102 * V_108 , * V_112 = NULL ;
T_1 V_113 , V_114 , V_94 ;
bool V_10 = false ;
V_94 = F_55 ( & V_4 -> V_95 . V_96 ) ;
V_108 = F_65 ( V_4 , V_111 ) ;
if ( ! V_108 ) {
V_10 = true ;
goto V_11;
}
if ( F_58 ( V_108 , & V_113 ) < 0 ) {
V_10 = true ;
goto V_11;
}
V_112 = F_65 ( V_4 , V_19 ) ;
if ( ! V_19 )
goto V_11;
if ( F_58 ( V_112 , & V_114 ) < 0 )
goto V_11;
if ( V_114 < V_113 )
goto V_11;
if ( ( V_114 - V_113 ) < V_94 )
goto V_11;
F_66 ( V_115 , V_4 ,
L_10 ,
V_113 , V_114 ) ;
V_10 = true ;
V_11:
if ( V_108 )
F_62 ( V_108 ) ;
if ( V_112 )
F_62 ( V_112 ) ;
return V_10 ;
}
static int F_67 ( struct V_3 * V_4 ,
struct V_21 * V_22 ,
const struct V_102 * V_103 )
{
struct V_102 * V_108 ;
struct V_23 * V_106 ;
struct V_25 * V_105 = NULL ;
int V_10 = - 1 ;
V_106 = F_41 ( V_103 -> V_19 , V_78 ) ;
if ( ! V_106 )
goto V_11;
V_105 = F_20 ( V_106 , V_78 ) ;
if ( ! V_105 )
goto V_11;
V_108 = F_68 ( V_4 ) ;
F_21 ( V_22 , L_11 ,
( V_108 == V_103 ? L_12 : L_13 ) ,
V_103 -> V_19 -> V_76 ,
V_105 -> V_14 . V_15 / 10 ,
V_105 -> V_14 . V_15 % 10 , V_106 -> V_27 ,
V_106 -> V_32 -> V_33 -> V_34 ,
V_103 -> V_107 / 10 ,
V_103 -> V_107 % 10 ,
V_103 -> V_116 / 10 ,
V_103 -> V_116 % 10 ) ;
V_10 = F_69 ( V_22 ) ? - 1 : 0 ;
if ( V_108 )
F_62 ( V_108 ) ;
V_11:
if ( V_105 )
F_22 ( V_105 ) ;
if ( V_106 )
F_42 ( V_106 ) ;
return V_10 ;
}
static void F_70 ( struct V_3 * V_4 ,
struct V_21 * V_22 )
{
struct V_102 * V_103 ;
int V_117 = 0 ;
F_27 ( V_22 ,
L_14 ) ;
F_28 () ;
F_19 (gw_node, &bat_priv->gw.gateway_list, list) {
if ( F_67 ( V_4 , V_22 , V_103 ) < 0 )
continue;
V_117 ++ ;
}
F_30 () ;
if ( V_117 == 0 )
F_27 ( V_22 , L_15 ) ;
}
static int F_71 ( struct V_38 * V_39 , T_1 V_40 , T_1 V_22 ,
struct V_3 * V_4 ,
struct V_102 * V_103 )
{
struct V_25 * V_105 = NULL ;
struct V_23 * V_106 ;
struct V_102 * V_108 ;
int V_10 = - V_101 ;
void * V_41 ;
V_106 = F_41 ( V_103 -> V_19 , V_78 ) ;
if ( ! V_106 )
goto V_11;
V_105 = F_20 ( V_106 , V_78 ) ;
if ( ! V_105 )
goto V_11;
V_108 = F_68 ( V_4 ) ;
V_41 = F_32 ( V_39 , V_40 , V_22 , & V_43 ,
V_44 , V_118 ) ;
if ( ! V_41 ) {
V_10 = - V_46 ;
goto V_11;
}
V_10 = - V_54 ;
if ( V_108 == V_103 ) {
if ( F_44 ( V_39 , V_81 ) ) {
F_36 ( V_39 , V_41 ) ;
goto V_11;
}
}
if ( F_33 ( V_39 , V_80 , V_48 ,
V_103 -> V_19 -> V_76 ) ) {
F_36 ( V_39 , V_41 ) ;
goto V_11;
}
if ( F_34 ( V_39 , V_52 ,
V_105 -> V_14 . V_15 ) ) {
F_36 ( V_39 , V_41 ) ;
goto V_11;
}
if ( F_33 ( V_39 , V_119 , V_48 , V_106 -> V_27 ) ) {
F_36 ( V_39 , V_41 ) ;
goto V_11;
}
if ( F_72 ( V_39 , V_120 ,
V_106 -> V_32 -> V_33 -> V_34 ) ) {
F_36 ( V_39 , V_41 ) ;
goto V_11;
}
if ( F_34 ( V_39 , V_121 ,
V_103 -> V_107 ) ) {
F_36 ( V_39 , V_41 ) ;
goto V_11;
}
if ( F_34 ( V_39 , V_122 , V_103 -> V_116 ) ) {
F_36 ( V_39 , V_41 ) ;
goto V_11;
}
F_35 ( V_39 , V_41 ) ;
V_10 = 0 ;
V_11:
if ( V_105 )
F_22 ( V_105 ) ;
if ( V_106 )
F_42 ( V_106 ) ;
return V_10 ;
}
static void F_73 ( struct V_38 * V_39 , struct V_57 * V_58 ,
struct V_3 * V_4 )
{
int V_40 = F_39 ( V_58 -> V_62 ) . V_40 ;
struct V_102 * V_103 ;
int V_123 = V_58 -> args [ 0 ] ;
int V_56 = 0 ;
F_28 () ;
F_19 (gw_node, &bat_priv->gw.gateway_list, list) {
if ( V_56 ++ < V_123 )
continue;
if ( F_71 ( V_39 , V_40 , V_58 -> V_63 -> V_64 ,
V_4 , V_103 ) ) {
V_123 = V_56 - 1 ;
goto V_124;
}
}
V_123 = V_56 ;
V_124:
F_30 () ;
V_58 -> args [ 0 ] = V_123 ;
}
void F_74 ( struct V_1 * V_2 )
{
F_52 ( & V_2 -> V_14 . V_125 , 0 ) ;
F_52 ( & V_2 -> V_14 . V_126 , 500 ) ;
}
int F_75 ( struct V_3 * V_4 )
{
int V_10 = 0 ;
V_10 = F_76 ( V_4 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
void F_77 ( struct V_3 * V_4 )
{
F_78 ( V_4 ) ;
}
int T_4 F_79 ( void )
{
int V_10 ;
V_10 = F_80 ( V_127 ,
V_128 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_80 ( V_129 ,
V_130 ) ;
if ( V_10 < 0 )
goto V_131;
V_10 = F_81 ( & V_132 ) ;
if ( V_10 < 0 )
goto V_133;
return V_10 ;
V_133:
F_82 ( V_129 ) ;
V_131:
F_82 ( V_127 ) ;
return V_10 ;
}

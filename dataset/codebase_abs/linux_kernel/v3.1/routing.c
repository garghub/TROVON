void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = F_2 ( V_1 -> V_3 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_11 ;
unsigned long * V_12 ;
int V_13 ;
T_1 V_14 ;
for ( V_13 = 0 ; V_13 < V_5 -> V_15 ; V_13 ++ ) {
V_10 = & V_5 -> V_16 [ V_13 ] ;
F_3 () ;
F_4 (orig_node, node, head, hash_entry) {
F_5 ( & V_11 -> V_17 ) ;
V_14 = V_1 -> V_18 * V_19 ;
V_12 = & ( V_11 -> V_20 [ V_14 ] ) ;
F_6 ( V_2 , V_12 , 1 , 0 ) ;
V_11 -> V_21 [ V_1 -> V_18 ] =
F_7 ( V_12 ) ;
F_8 ( & V_11 -> V_17 ) ;
}
F_9 () ;
}
}
static void F_10 ( struct V_2 * V_2 ,
struct V_11 * V_11 ,
const unsigned char * V_22 ,
T_2 V_23 , T_2 V_24 ,
T_3 V_25 )
{
T_2 V_26 = ( T_2 ) F_11 ( & V_11 -> V_27 ) ;
bool V_28 = true ;
if ( V_24 - V_26 == 1 ) {
if ( ! V_23 ) {
V_28 = false ;
goto V_29;
}
F_12 ( V_2 , V_11 , V_23 , V_24 ,
(struct V_30 * ) V_22 ) ;
V_11 -> V_25 = F_13 ( V_2 , V_11 ) ;
if ( V_11 -> V_25 != V_25 )
goto V_29;
V_11 -> V_31 = false ;
} else {
if ( V_24 != V_26 || V_11 -> V_25 != V_25 ) {
V_29:
F_14 ( V_32 , V_2 , L_1
L_2
L_3
L_4 , V_11 -> V_33 , V_24 ,
V_26 , V_25 , V_11 -> V_25 ,
V_23 ) ;
F_15 ( V_2 , V_11 , V_24 , V_25 ,
V_28 ) ;
return;
}
}
}
static void F_16 ( struct V_2 * V_2 ,
struct V_11 * V_11 ,
struct V_34 * V_34 )
{
struct V_34 * V_35 ;
V_35 = F_17 ( V_11 ) ;
if ( ( V_35 ) && ( ! V_34 ) ) {
F_14 ( V_36 , V_2 , L_5 ,
V_11 -> V_33 ) ;
F_18 ( V_2 , V_11 ,
L_6 ) ;
} else if ( ( ! V_35 ) && ( V_34 ) ) {
F_14 ( V_36 , V_2 ,
L_7 ,
V_11 -> V_33 , V_34 -> V_37 ) ;
} else if ( V_34 && V_35 ) {
F_14 ( V_36 , V_2 ,
L_8
L_9 ,
V_11 -> V_33 , V_34 -> V_37 ,
V_35 -> V_37 ) ;
}
if ( V_35 )
F_19 ( V_35 ) ;
if ( V_34 && ! F_20 ( & V_34 -> V_38 ) )
V_34 = NULL ;
F_5 ( & V_11 -> V_39 ) ;
F_21 ( V_11 -> V_40 , V_34 ) ;
F_8 ( & V_11 -> V_39 ) ;
if ( V_35 )
F_19 ( V_35 ) ;
}
void F_22 ( struct V_2 * V_2 , struct V_11 * V_11 ,
struct V_34 * V_34 )
{
struct V_34 * V_40 = NULL ;
if ( ! V_11 )
goto V_41;
V_40 = F_17 ( V_11 ) ;
if ( V_40 != V_34 )
F_16 ( V_2 , V_11 , V_34 ) ;
V_41:
if ( V_40 )
F_19 ( V_40 ) ;
}
static int F_23 ( struct V_11 * V_11 ,
struct V_11 * V_42 ,
struct V_43 * V_43 ,
struct V_1 * V_44 )
{
struct V_2 * V_2 = F_2 ( V_44 -> V_3 ) ;
struct V_34 * V_34 = NULL , * V_45 ;
struct V_7 * V_8 ;
T_2 V_46 ;
T_2 V_47 , V_48 , V_49 ;
int V_50 , V_51 = 0 ;
F_3 () ;
F_4 (tmp_neigh_node, node,
&orig_neigh_node->neigh_list, list) {
if ( ! F_24 ( V_45 -> V_37 , V_42 -> V_33 ) )
continue;
if ( V_45 -> V_44 != V_44 )
continue;
if ( ! F_20 ( & V_45 -> V_38 ) )
continue;
V_34 = V_45 ;
break;
}
F_9 () ;
if ( ! V_34 )
V_34 = F_25 ( V_42 ,
V_42 ,
V_42 -> V_33 ,
V_44 ) ;
if ( ! V_34 )
goto V_41;
if ( V_11 == V_42 )
V_34 -> V_52 = V_53 ;
V_11 -> V_52 = V_53 ;
F_5 ( & V_11 -> V_17 ) ;
V_47 = V_42 -> V_21 [ V_44 -> V_18 ] ;
V_48 = V_34 -> V_54 ;
F_8 ( & V_11 -> V_17 ) ;
V_46 = ( V_47 > V_48 ?
V_48 : V_47 ) ;
if ( ( V_46 < V_55 ) ||
( V_48 < V_56 ) )
V_49 = 0 ;
else
V_49 = ( V_57 * V_46 ) / V_48 ;
V_50 = V_57 - ( V_57 *
( V_58 - V_48 ) *
( V_58 - V_48 ) *
( V_58 - V_48 ) ) /
( V_58 *
V_58 *
V_58 ) ;
V_43 -> V_59 = ( ( V_43 -> V_59 * V_49 * V_50 ) /
( V_57 * V_57 ) ) ;
F_14 ( V_60 , V_2 ,
L_10
L_11
L_12
L_13 ,
V_11 -> V_33 , V_42 -> V_33 , V_46 ,
V_48 , V_49 , V_50 , V_43 -> V_59 ) ;
if ( V_43 -> V_59 >= V_61 )
V_51 = 1 ;
V_41:
if ( V_34 )
F_19 ( V_34 ) ;
return V_51 ;
}
void F_26 ( struct V_11 * V_11 ,
struct V_34 * V_34 )
{
if ( F_27 ( & V_34 -> V_62 ) )
goto V_41;
F_28 ( & V_34 -> V_62 ) ;
F_29 ( & V_34 -> V_62 ) ;
F_19 ( V_34 ) ;
F_30 ( & V_11 -> V_63 ) ;
V_41:
return;
}
static void F_31 ( struct V_11 * V_11 ,
struct V_34 * V_34 )
{
struct V_7 * V_8 ;
struct V_34 * V_45 , * V_40 = NULL ;
T_2 V_64 = 0 ;
F_5 ( & V_11 -> V_39 ) ;
if ( ! F_24 ( V_11 -> V_33 ,
V_34 -> V_11 -> V_65 ) )
goto V_66;
V_40 = F_17 ( V_11 ) ;
if ( ! V_40 )
goto V_66;
if ( V_34 -> V_67 < V_40 -> V_67 - V_68 )
goto V_66;
F_4 (tmp_neigh_node, node,
&orig_node->neigh_list, list) {
if ( V_45 == V_34 )
continue;
if ( F_27 ( & V_45 -> V_62 ) )
continue;
if ( ( V_34 -> V_44 == V_45 -> V_44 ) ||
( F_24 ( V_34 -> V_37 , V_45 -> V_37 ) ) ) {
V_64 = 1 ;
break;
}
}
if ( V_64 )
goto V_66;
if ( ! F_27 ( & V_34 -> V_62 ) )
goto V_41;
if ( ! F_20 ( & V_34 -> V_38 ) )
goto V_41;
F_32 ( & V_34 -> V_62 , & V_11 -> V_69 ) ;
F_33 ( & V_11 -> V_63 ) ;
goto V_41;
V_66:
F_26 ( V_11 , V_34 ) ;
V_41:
F_8 ( & V_11 -> V_39 ) ;
if ( V_40 )
F_19 ( V_40 ) ;
}
static void F_34 ( const struct V_11 * V_11 ,
struct V_11 * V_42 ,
const struct V_43 * V_43 )
{
if ( ! ( V_43 -> V_70 & V_71 ) )
return;
memcpy ( V_42 -> V_65 , V_11 -> V_33 , V_72 ) ;
}
static void F_35 ( struct V_2 * V_2 , struct V_11 * V_11 ,
const struct V_73 * V_73 ,
const struct V_43 * V_43 ,
struct V_1 * V_44 ,
const unsigned char * V_22 , int V_74 )
{
struct V_34 * V_34 = NULL , * V_45 = NULL ;
struct V_34 * V_40 = NULL ;
struct V_11 * V_75 ;
struct V_7 * V_8 ;
T_2 V_76 , V_77 ;
F_14 ( V_60 , V_2 , L_14
L_15 ) ;
F_3 () ;
F_4 (tmp_neigh_node, node,
&orig_node->neigh_list, list) {
if ( F_24 ( V_45 -> V_37 , V_73 -> V_78 ) &&
( V_45 -> V_44 == V_44 ) &&
F_20 ( & V_45 -> V_38 ) ) {
if ( V_34 )
F_19 ( V_34 ) ;
V_34 = V_45 ;
continue;
}
if ( V_74 )
continue;
F_5 ( & V_45 -> V_79 ) ;
F_36 ( V_45 -> V_80 ,
& V_45 -> V_81 , 0 ) ;
V_45 -> V_67 =
F_37 ( V_45 -> V_80 ) ;
F_8 ( & V_45 -> V_79 ) ;
}
if ( ! V_34 ) {
struct V_11 * V_82 ;
V_82 = F_38 ( V_2 , V_73 -> V_78 ) ;
if ( ! V_82 )
goto V_83;
V_34 = F_25 ( V_11 , V_82 ,
V_73 -> V_78 , V_44 ) ;
F_39 ( V_82 ) ;
if ( ! V_34 )
goto V_83;
} else
F_14 ( V_60 , V_2 ,
L_16 ) ;
F_9 () ;
V_11 -> V_70 = V_43 -> V_70 ;
V_34 -> V_52 = V_53 ;
F_5 ( & V_34 -> V_79 ) ;
F_36 ( V_34 -> V_80 ,
& V_34 -> V_81 ,
V_43 -> V_59 ) ;
V_34 -> V_67 = F_37 ( V_34 -> V_80 ) ;
F_8 ( & V_34 -> V_79 ) ;
if ( ! V_74 ) {
V_11 -> V_84 = V_43 -> V_85 ;
V_34 -> V_84 = V_43 -> V_85 ;
}
F_31 ( V_11 , V_34 ) ;
V_40 = F_17 ( V_11 ) ;
if ( V_40 == V_34 )
goto V_86;
if ( V_40 && ( V_40 -> V_67 > V_34 -> V_67 ) )
goto V_86;
if ( V_40 && ( V_34 -> V_67 == V_40 -> V_67 ) ) {
V_75 = V_40 -> V_11 ;
F_5 ( & V_75 -> V_17 ) ;
V_76 =
V_75 -> V_21 [ V_44 -> V_18 ] ;
F_8 ( & V_75 -> V_17 ) ;
V_75 = V_34 -> V_11 ;
F_5 ( & V_75 -> V_17 ) ;
V_77 =
V_75 -> V_21 [ V_44 -> V_18 ] ;
F_8 ( & V_75 -> V_17 ) ;
if ( V_76 >= V_77 )
goto V_86;
}
F_22 ( V_2 , V_11 , V_34 ) ;
V_86:
if ( ( ( V_43 -> V_33 != V_73 -> V_78 ) &&
( V_43 -> V_85 > 2 ) ) ||
( V_43 -> V_70 & V_71 ) )
F_10 ( V_2 , V_11 , V_22 ,
V_43 -> V_23 ,
V_43 -> V_24 ,
V_43 -> V_25 ) ;
if ( V_11 -> V_87 != V_43 -> V_87 )
F_40 ( V_2 , V_11 , V_43 -> V_87 ) ;
V_11 -> V_87 = V_43 -> V_87 ;
if ( ( V_11 -> V_87 ) &&
( F_11 ( & V_2 -> V_88 ) == V_89 ) &&
( F_11 ( & V_2 -> V_90 ) > 2 ) )
F_41 ( V_2 , V_11 ) ;
goto V_41;
V_83:
F_9 () ;
V_41:
if ( V_34 )
F_19 ( V_34 ) ;
if ( V_40 )
F_19 ( V_40 ) ;
}
static int F_42 ( struct V_2 * V_2 ,
T_4 V_91 ,
unsigned long * V_92 )
{
if ( ( V_91 <= - V_58 )
|| ( V_91 >= V_93 ) ) {
if ( F_43 ( V_53 , * V_92 +
F_44 ( V_94 ) ) ) {
* V_92 = V_53 ;
F_14 ( V_60 , V_2 ,
L_17 ) ;
return 0 ;
} else
return 1 ;
}
return 0 ;
}
static int F_45 ( const struct V_73 * V_73 ,
const struct V_43 * V_43 ,
const struct V_1 * V_44 )
{
struct V_2 * V_2 = F_2 ( V_44 -> V_3 ) ;
struct V_11 * V_11 ;
struct V_34 * V_45 ;
struct V_7 * V_8 ;
int V_74 = 0 ;
T_4 V_95 ;
int V_96 = 0 ;
int V_97 , V_51 = - 1 ;
V_11 = F_38 ( V_2 , V_43 -> V_33 ) ;
if ( ! V_11 )
return 0 ;
F_5 ( & V_11 -> V_17 ) ;
V_95 = V_43 -> V_98 - V_11 -> V_99 ;
if ( F_42 ( V_2 , V_95 ,
& V_11 -> V_100 ) )
goto V_41;
F_3 () ;
F_4 (tmp_neigh_node, node,
&orig_node->neigh_list, list) {
V_74 |= F_46 ( V_45 -> V_101 ,
V_11 -> V_99 ,
V_43 -> V_98 ) ;
if ( F_24 ( V_45 -> V_37 , V_73 -> V_78 ) &&
( V_45 -> V_44 == V_44 ) )
V_97 = 1 ;
else
V_97 = 0 ;
V_96 |= F_6 ( V_2 ,
V_45 -> V_101 ,
V_95 , V_97 ) ;
V_45 -> V_54 =
F_7 ( V_45 -> V_101 ) ;
}
F_9 () ;
if ( V_96 ) {
F_14 ( V_60 , V_2 ,
L_18 ,
V_11 -> V_99 , V_43 -> V_98 ) ;
V_11 -> V_99 = V_43 -> V_98 ;
}
V_51 = V_74 ;
V_41:
F_8 ( & V_11 -> V_17 ) ;
F_39 ( V_11 ) ;
return V_51 ;
}
void F_47 ( const struct V_73 * V_73 ,
struct V_43 * V_43 ,
const unsigned char * V_22 ,
struct V_1 * V_44 )
{
struct V_2 * V_2 = F_2 ( V_44 -> V_3 ) ;
struct V_1 * V_1 ;
struct V_11 * V_42 , * V_11 ;
struct V_34 * V_40 = NULL , * V_102 = NULL ;
struct V_34 * V_103 = NULL ;
int V_104 ;
int V_105 = 0 , V_106 = 0 , V_107 = 0 ;
int V_108 = 0 , V_109 , V_110 ;
int V_74 ;
T_5 V_111 ;
if ( V_43 -> V_112 != V_113 )
return;
V_111 = F_11 ( & V_44 -> V_98 ) ;
V_104 = ( V_43 -> V_70 & V_114 ? 1 : 0 ) ;
V_110 = ( F_24 ( V_73 -> V_78 ,
V_43 -> V_33 ) ? 1 : 0 ) ;
F_14 ( V_60 , V_2 ,
L_19
L_20
L_21 ,
V_73 -> V_78 , V_44 -> V_115 -> V_116 ,
V_44 -> V_115 -> V_117 , V_43 -> V_33 ,
V_43 -> V_118 , V_43 -> V_98 ,
V_43 -> V_24 , V_43 -> V_25 ,
V_43 -> V_23 , V_43 -> V_59 ,
V_43 -> V_85 , V_43 -> V_119 ,
V_104 ) ;
F_3 () ;
F_48 (hard_iface, &hardif_list, list) {
if ( V_1 -> V_120 != V_121 )
continue;
if ( V_1 -> V_3 != V_44 -> V_3 )
continue;
if ( F_24 ( V_73 -> V_78 ,
V_1 -> V_115 -> V_117 ) )
V_105 = 1 ;
if ( F_24 ( V_43 -> V_33 ,
V_1 -> V_115 -> V_117 ) )
V_106 = 1 ;
if ( F_24 ( V_43 -> V_118 ,
V_1 -> V_115 -> V_117 ) )
V_107 = 1 ;
if ( F_49 ( V_73 -> V_78 ) )
V_108 = 1 ;
}
F_9 () ;
if ( V_43 -> V_119 != V_122 ) {
F_14 ( V_60 , V_2 ,
L_22 ,
V_43 -> V_119 ) ;
return;
}
if ( V_105 ) {
F_14 ( V_60 , V_2 ,
L_23
L_24 ,
V_73 -> V_78 ) ;
return;
}
if ( V_108 ) {
F_14 ( V_60 , V_2 , L_25
L_26
L_24 , V_73 -> V_78 ) ;
return;
}
if ( V_106 ) {
unsigned long * V_12 ;
int V_123 ;
V_42 = F_38 ( V_2 , V_73 -> V_78 ) ;
if ( ! V_42 )
return;
if ( V_104 &&
F_24 ( V_44 -> V_115 -> V_117 ,
V_43 -> V_33 ) ) {
V_123 = V_44 -> V_18 * V_19 ;
F_5 ( & V_42 -> V_17 ) ;
V_12 = & ( V_42 -> V_20 [ V_123 ] ) ;
F_50 ( V_12 ,
V_111 - V_43 -> V_98 - 2 ) ;
V_42 -> V_21 [ V_44 -> V_18 ] =
F_7 ( V_12 ) ;
F_8 ( & V_42 -> V_17 ) ;
}
F_14 ( V_60 , V_2 , L_25
L_27 ) ;
F_39 ( V_42 ) ;
return;
}
if ( V_107 ) {
F_14 ( V_60 , V_2 ,
L_28
L_29 , V_73 -> V_78 ) ;
return;
}
V_11 = F_38 ( V_2 , V_43 -> V_33 ) ;
if ( ! V_11 )
return;
V_74 = F_45 ( V_73 , V_43 , V_44 ) ;
if ( V_74 == - 1 ) {
F_14 ( V_60 , V_2 ,
L_30
L_31 , V_73 -> V_78 ) ;
goto V_41;
}
if ( V_43 -> V_59 == 0 ) {
F_14 ( V_60 , V_2 ,
L_32 ) ;
goto V_41;
}
V_40 = F_17 ( V_11 ) ;
if ( V_40 )
V_102 = F_17 ( V_40 -> V_11 ) ;
if ( V_40 && V_102 &&
( F_24 ( V_40 -> V_37 , V_43 -> V_118 ) ) &&
! ( F_24 ( V_43 -> V_33 , V_43 -> V_118 ) ) &&
( F_24 ( V_40 -> V_37 , V_102 -> V_37 ) ) ) {
F_14 ( V_60 , V_2 ,
L_33
L_34 , V_73 -> V_78 ) ;
goto V_41;
}
V_42 = ( V_110 ?
V_11 :
F_38 ( V_2 , V_73 -> V_78 ) ) ;
if ( ! V_42 )
goto V_41;
V_103 = F_17 ( V_42 ) ;
if ( ! V_110 && ( ! V_103 ) ) {
F_14 ( V_60 , V_2 ,
L_35 ) ;
goto V_124;
}
V_109 = F_23 ( V_11 , V_42 ,
V_43 , V_44 ) ;
F_34 ( V_11 , V_42 , V_43 ) ;
if ( V_109 &&
( ! V_74 ||
( ( V_11 -> V_99 == V_43 -> V_98 ) &&
( V_11 -> V_84 - 3 <= V_43 -> V_85 ) ) ) )
F_35 ( V_2 , V_11 , V_73 , V_43 ,
V_44 , V_22 , V_74 ) ;
if ( V_110 ) {
F_51 ( V_11 , V_73 , V_43 ,
1 , V_44 ) ;
F_14 ( V_60 , V_2 , L_36
L_37 ) ;
goto V_124;
}
if ( ! V_109 ) {
F_14 ( V_60 , V_2 ,
L_38 ) ;
goto V_124;
}
if ( V_74 ) {
F_14 ( V_60 , V_2 ,
L_39 ) ;
goto V_124;
}
F_14 ( V_60 , V_2 ,
L_40 ) ;
F_51 ( V_11 , V_73 , V_43 ,
0 , V_44 ) ;
V_124:
if ( ( V_42 ) && ( ! V_110 ) )
F_39 ( V_42 ) ;
V_41:
if ( V_40 )
F_19 ( V_40 ) ;
if ( V_102 )
F_19 ( V_102 ) ;
if ( V_103 )
F_19 ( V_103 ) ;
F_39 ( V_11 ) ;
}
int F_52 ( struct V_125 * V_126 , struct V_1 * V_1 )
{
struct V_73 * V_73 ;
if ( F_53 ( ! F_54 ( V_126 , sizeof( struct V_43 ) ) ) )
return V_127 ;
V_73 = (struct V_73 * ) F_55 ( V_126 ) ;
if ( ! F_49 ( V_73 -> V_128 ) )
return V_127 ;
if ( F_49 ( V_73 -> V_78 ) )
return V_127 ;
if ( F_56 ( V_126 , 0 ) < 0 )
return V_127 ;
if ( F_57 ( V_126 ) < 0 )
return V_127 ;
V_73 = (struct V_73 * ) F_55 ( V_126 ) ;
F_58 ( V_73 ,
V_126 -> V_129 ,
F_59 ( V_126 ) ,
V_1 ) ;
F_60 ( V_126 ) ;
return V_130 ;
}
static int F_61 ( struct V_2 * V_2 ,
struct V_125 * V_126 , T_1 V_131 )
{
struct V_1 * V_132 = NULL ;
struct V_11 * V_11 = NULL ;
struct V_34 * V_40 = NULL ;
struct V_133 * V_134 ;
int V_51 = V_127 ;
V_134 = (struct V_133 * ) V_126 -> V_129 ;
if ( V_134 -> V_135 != V_136 ) {
F_62 ( V_134 , V_131 ) ;
goto V_41;
}
V_132 = F_63 ( V_2 ) ;
if ( ! V_132 )
goto V_41;
V_11 = F_64 ( V_2 , V_134 -> V_33 ) ;
if ( ! V_11 )
goto V_41;
V_40 = F_17 ( V_11 ) ;
if ( ! V_40 )
goto V_41;
if ( F_56 ( V_126 , sizeof( struct V_73 ) ) < 0 )
goto V_41;
V_134 = (struct V_133 * ) V_126 -> V_129 ;
memcpy ( V_134 -> V_137 , V_134 -> V_33 , V_72 ) ;
memcpy ( V_134 -> V_33 , V_132 -> V_115 -> V_117 , V_72 ) ;
V_134 -> V_135 = V_138 ;
V_134 -> V_85 = V_139 ;
F_65 ( V_126 , V_40 -> V_44 , V_40 -> V_37 ) ;
V_51 = V_130 ;
V_41:
if ( V_132 )
F_66 ( V_132 ) ;
if ( V_40 )
F_19 ( V_40 ) ;
if ( V_11 )
F_39 ( V_11 ) ;
return V_51 ;
}
static int F_67 ( struct V_2 * V_2 ,
struct V_125 * V_126 )
{
struct V_1 * V_132 = NULL ;
struct V_11 * V_11 = NULL ;
struct V_34 * V_40 = NULL ;
struct V_134 * V_134 ;
int V_51 = V_127 ;
V_134 = (struct V_134 * ) V_126 -> V_129 ;
if ( V_134 -> V_135 != V_136 ) {
F_68 ( L_41
L_42 , V_134 -> V_33 ,
V_134 -> V_137 ) ;
goto V_41;
}
V_132 = F_63 ( V_2 ) ;
if ( ! V_132 )
goto V_41;
V_11 = F_64 ( V_2 , V_134 -> V_33 ) ;
if ( ! V_11 )
goto V_41;
V_40 = F_17 ( V_11 ) ;
if ( ! V_40 )
goto V_41;
if ( F_56 ( V_126 , sizeof( struct V_73 ) ) < 0 )
goto V_41;
V_134 = (struct V_134 * ) V_126 -> V_129 ;
memcpy ( V_134 -> V_137 , V_134 -> V_33 , V_72 ) ;
memcpy ( V_134 -> V_33 , V_132 -> V_115 -> V_117 , V_72 ) ;
V_134 -> V_135 = V_140 ;
V_134 -> V_85 = V_139 ;
F_65 ( V_126 , V_40 -> V_44 , V_40 -> V_37 ) ;
V_51 = V_130 ;
V_41:
if ( V_132 )
F_66 ( V_132 ) ;
if ( V_40 )
F_19 ( V_40 ) ;
if ( V_11 )
F_39 ( V_11 ) ;
return V_51 ;
}
int F_69 ( struct V_125 * V_126 , struct V_1 * V_141 )
{
struct V_2 * V_2 = F_2 ( V_141 -> V_3 ) ;
struct V_133 * V_134 ;
struct V_73 * V_73 ;
struct V_11 * V_11 = NULL ;
struct V_34 * V_40 = NULL ;
int V_142 = sizeof( struct V_134 ) ;
int V_51 = V_127 ;
if ( V_126 -> V_143 >= sizeof( struct V_133 ) )
V_142 = sizeof( struct V_133 ) ;
if ( F_53 ( ! F_54 ( V_126 , V_142 ) ) )
goto V_41;
V_73 = (struct V_73 * ) F_55 ( V_126 ) ;
if ( F_49 ( V_73 -> V_128 ) )
goto V_41;
if ( F_49 ( V_73 -> V_78 ) )
goto V_41;
if ( ! F_70 ( V_73 -> V_128 ) )
goto V_41;
V_134 = (struct V_133 * ) V_126 -> V_129 ;
if ( ( V_142 == sizeof( struct V_133 ) ) &&
( V_134 -> V_144 < V_145 ) ) {
memcpy ( & ( V_134 -> V_146 [ V_134 -> V_144 ] ) ,
V_73 -> V_128 , V_72 ) ;
V_134 -> V_144 ++ ;
}
if ( F_70 ( V_134 -> V_137 ) )
return F_61 ( V_2 , V_126 , V_142 ) ;
if ( V_134 -> V_85 < 2 )
return F_67 ( V_2 , V_126 ) ;
V_11 = F_64 ( V_2 , V_134 -> V_137 ) ;
if ( ! V_11 )
goto V_41;
V_40 = F_17 ( V_11 ) ;
if ( ! V_40 )
goto V_41;
if ( F_56 ( V_126 , sizeof( struct V_73 ) ) < 0 )
goto V_41;
V_134 = (struct V_133 * ) V_126 -> V_129 ;
V_134 -> V_85 -- ;
F_65 ( V_126 , V_40 -> V_44 , V_40 -> V_37 ) ;
V_51 = V_130 ;
V_41:
if ( V_40 )
F_19 ( V_40 ) ;
if ( V_11 )
F_39 ( V_11 ) ;
return V_51 ;
}
static struct V_34 * F_71 ( struct V_11 * V_147 ,
const struct V_1 * V_141 )
{
struct V_34 * V_45 ;
struct V_34 * V_40 = NULL , * V_148 = NULL ;
F_3 () ;
F_48 (tmp_neigh_node, &primary_orig->bond_list,
bonding_list) {
if ( ! V_148 )
V_148 = V_45 ;
if ( V_45 -> V_44 == V_141 )
continue;
if ( ! F_20 ( & V_45 -> V_38 ) )
continue;
V_40 = V_45 ;
break;
}
if ( ! V_40 && V_148 &&
F_20 ( & V_148 -> V_38 ) )
V_40 = V_148 ;
if ( ! V_40 )
goto V_41;
F_5 ( & V_147 -> V_39 ) ;
F_28 ( & V_147 -> V_69 ) ;
F_32 ( & V_147 -> V_69 ,
& V_40 -> V_62 ) ;
F_8 ( & V_147 -> V_39 ) ;
V_41:
F_9 () ;
return V_40 ;
}
static struct V_34 * F_72 ( struct V_11 * V_147 ,
const struct V_1 * V_141 )
{
struct V_34 * V_45 ;
struct V_34 * V_40 = NULL , * V_148 = NULL ;
F_3 () ;
F_48 (tmp_neigh_node, &primary_orig->bond_list,
bonding_list) {
if ( ! V_148 )
V_148 = V_45 ;
if ( V_45 -> V_44 == V_141 )
continue;
if ( ! F_20 ( & V_45 -> V_38 ) )
continue;
if ( ( ! V_40 ) ||
( V_45 -> V_67 > V_40 -> V_67 ) ) {
if ( V_40 )
F_19 ( V_40 ) ;
V_40 = V_45 ;
F_20 ( & V_40 -> V_38 ) ;
}
F_19 ( V_45 ) ;
}
if ( ! V_40 && V_148 &&
F_20 ( & V_148 -> V_38 ) )
V_40 = V_148 ;
F_9 () ;
return V_40 ;
}
int F_73 ( struct V_125 * V_126 , struct V_1 * V_141 )
{
struct V_2 * V_2 = F_2 ( V_141 -> V_3 ) ;
struct V_149 * V_150 ;
struct V_73 * V_73 ;
if ( F_53 ( ! F_54 ( V_126 , sizeof( struct V_149 ) ) ) )
goto V_41;
if ( F_56 ( V_126 , sizeof( struct V_149 ) ) < 0 )
goto V_41;
V_73 = (struct V_73 * ) F_55 ( V_126 ) ;
if ( F_49 ( V_73 -> V_128 ) )
goto V_41;
if ( F_49 ( V_73 -> V_78 ) )
goto V_41;
V_150 = (struct V_149 * ) V_126 -> V_129 ;
V_150 -> V_151 = F_74 ( V_150 -> V_151 ) ;
switch ( V_150 -> V_70 & V_152 ) {
case V_153 :
if ( ! F_75 ( V_2 , V_150 ) ) {
F_14 ( V_32 , V_2 ,
L_43 ,
V_150 -> V_137 ,
( V_150 -> V_70 & V_154 ? 'F' : '.' ) ) ;
V_150 -> V_151 = F_76 ( V_150 -> V_151 ) ;
return F_77 ( V_126 , V_141 ) ;
}
break;
case V_155 :
if ( F_57 ( V_126 ) < 0 )
goto V_41;
if ( F_70 ( V_150 -> V_137 ) )
F_78 ( V_2 , V_150 ) ;
else {
F_14 ( V_32 , V_2 ,
L_44 ,
V_150 -> V_137 ,
( V_150 -> V_70 & V_154 ? 'F' : '.' ) ) ;
V_150 -> V_151 = F_76 ( V_150 -> V_151 ) ;
return F_77 ( V_126 , V_141 ) ;
}
break;
}
V_41:
return V_127 ;
}
int F_79 ( struct V_125 * V_126 , struct V_1 * V_141 )
{
struct V_2 * V_2 = F_2 ( V_141 -> V_3 ) ;
struct V_156 * V_156 ;
struct V_11 * V_11 ;
struct V_73 * V_73 ;
if ( F_53 ( ! F_54 ( V_126 , sizeof( struct V_156 ) ) ) )
goto V_41;
V_73 = (struct V_73 * ) F_55 ( V_126 ) ;
if ( F_49 ( V_73 -> V_128 ) )
goto V_41;
if ( F_49 ( V_73 -> V_78 ) )
goto V_41;
V_156 = (struct V_156 * ) V_126 -> V_129 ;
if ( ! F_70 ( V_156 -> V_137 ) )
return F_77 ( V_126 , V_141 ) ;
V_11 = F_64 ( V_2 , V_156 -> V_157 ) ;
if ( ! V_11 )
goto V_41;
F_14 ( V_32 , V_2 , L_45
L_46 , V_156 -> V_157 ,
V_156 -> V_158 ) ;
F_80 ( V_2 , V_11 , V_156 -> V_158 ,
F_11 ( & V_11 -> V_27 ) + 1 , true ) ;
V_2 -> V_31 = true ;
F_39 ( V_11 ) ;
V_41:
return V_127 ;
}
struct V_34 * F_81 ( struct V_2 * V_2 ,
struct V_11 * V_11 ,
const struct V_1 * V_141 )
{
struct V_11 * V_159 ;
struct V_11 * V_160 ;
struct V_34 * V_40 ;
static T_2 V_161 [ V_72 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
int V_162 ;
if ( ! V_11 )
return NULL ;
V_40 = F_17 ( V_11 ) ;
if ( ! V_40 )
goto V_163;
V_162 = F_11 ( & V_2 -> V_164 ) ;
F_3 () ;
V_160 = V_40 -> V_11 ;
if ( ! V_160 )
goto V_165;
if ( ( ! V_141 ) && ( ! V_162 ) )
goto V_166;
if ( F_24 ( V_160 -> V_65 , V_161 ) )
goto V_166;
if ( F_24 ( V_160 -> V_65 , V_160 -> V_33 ) ) {
V_159 = V_160 ;
} else {
V_159 = F_64 ( V_2 ,
V_160 -> V_65 ) ;
if ( ! V_159 )
goto V_166;
F_39 ( V_159 ) ;
}
if ( F_11 ( & V_159 -> V_63 ) < 2 )
goto V_166;
F_19 ( V_40 ) ;
if ( V_162 )
V_40 = F_71 ( V_159 , V_141 ) ;
else
V_40 = F_72 ( V_159 , V_141 ) ;
V_166:
if ( V_40 && V_40 -> V_44 -> V_120 != V_121 )
goto V_165;
F_9 () ;
return V_40 ;
V_165:
F_9 () ;
V_163:
if ( V_40 )
F_19 ( V_40 ) ;
return NULL ;
}
static int F_82 ( struct V_125 * V_126 , int V_142 )
{
struct V_73 * V_73 ;
if ( F_53 ( ! F_54 ( V_126 , V_142 ) ) )
return - 1 ;
V_73 = (struct V_73 * ) F_55 ( V_126 ) ;
if ( F_49 ( V_73 -> V_128 ) )
return - 1 ;
if ( F_49 ( V_73 -> V_78 ) )
return - 1 ;
if ( ! F_70 ( V_73 -> V_128 ) )
return - 1 ;
return 0 ;
}
int F_77 ( struct V_125 * V_126 , struct V_1 * V_141 )
{
struct V_2 * V_2 = F_2 ( V_141 -> V_3 ) ;
struct V_11 * V_11 = NULL ;
struct V_34 * V_34 = NULL ;
struct V_167 * V_167 ;
struct V_73 * V_73 = (struct V_73 * ) F_55 ( V_126 ) ;
int V_51 = V_127 ;
struct V_125 * V_168 ;
V_167 = (struct V_167 * ) V_126 -> V_129 ;
if ( V_167 -> V_85 < 2 ) {
F_68 ( L_47
L_42 , V_73 -> V_78 ,
V_167 -> V_169 ) ;
goto V_41;
}
V_11 = F_64 ( V_2 , V_167 -> V_169 ) ;
if ( ! V_11 )
goto V_41;
V_34 = F_81 ( V_2 , V_11 , V_141 ) ;
if ( ! V_34 )
goto V_41;
if ( F_56 ( V_126 , sizeof( struct V_73 ) ) < 0 )
goto V_41;
V_167 = (struct V_167 * ) V_126 -> V_129 ;
if ( V_167 -> V_112 == V_170 &&
F_11 ( & V_2 -> V_171 ) &&
V_126 -> V_143 > V_34 -> V_44 -> V_115 -> V_172 ) {
V_51 = F_83 ( V_126 , V_2 ,
V_34 -> V_44 , V_34 -> V_37 ) ;
goto V_41;
}
if ( V_167 -> V_112 == V_173 &&
F_84 ( V_126 , V_34 -> V_44 -> V_115 -> V_172 ) ) {
V_51 = F_85 ( V_126 , V_2 , & V_168 ) ;
if ( V_51 == V_127 )
goto V_41;
if ( ! V_168 ) {
V_51 = V_130 ;
goto V_41;
}
V_126 = V_168 ;
V_167 = (struct V_167 * ) V_126 -> V_129 ;
}
V_167 -> V_85 -- ;
F_65 ( V_126 , V_34 -> V_44 , V_34 -> V_37 ) ;
V_51 = V_130 ;
V_41:
if ( V_34 )
F_19 ( V_34 ) ;
if ( V_11 )
F_39 ( V_11 ) ;
return V_51 ;
}
static int F_86 ( struct V_2 * V_2 ,
struct V_125 * V_126 ) {
T_2 V_174 ;
struct V_11 * V_11 ;
struct V_73 * V_73 ;
struct V_1 * V_132 ;
struct V_167 * V_167 ;
bool V_31 ;
if ( F_56 ( V_126 , sizeof( struct V_167 ) ) < 0 )
return 0 ;
V_167 = (struct V_167 * ) V_126 -> V_129 ;
if ( F_70 ( V_167 -> V_169 ) ) {
V_31 = V_2 -> V_31 ;
V_174 = ( T_2 ) F_11 ( & V_2 -> V_24 ) ;
} else {
V_11 = F_64 ( V_2 , V_167 -> V_169 ) ;
if ( ! V_11 )
return 0 ;
V_174 = ( T_2 ) F_11 ( & V_11 -> V_27 ) ;
V_31 = V_11 -> V_31 ;
F_39 ( V_11 ) ;
}
if ( F_87 ( V_167 -> V_24 , V_174 ) || V_31 ) {
if ( F_57 ( V_126 ) < 0 )
return 0 ;
V_73 = (struct V_73 * ) ( V_126 -> V_129 +
sizeof( struct V_167 ) ) ;
V_11 = F_88 ( V_2 , V_73 -> V_128 ) ;
if ( ! V_11 ) {
if ( ! F_89 ( V_2 , V_73 -> V_128 ) )
return 0 ;
V_132 = F_63 ( V_2 ) ;
if ( ! V_132 )
return 0 ;
memcpy ( V_167 -> V_169 ,
V_132 -> V_115 -> V_117 , V_72 ) ;
F_66 ( V_132 ) ;
} else {
memcpy ( V_167 -> V_169 , V_11 -> V_33 ,
V_72 ) ;
V_174 = ( T_2 )
F_11 ( & V_11 -> V_27 ) ;
F_39 ( V_11 ) ;
}
F_14 ( V_36 , V_2 , L_48
L_49
L_50 , V_167 -> V_24 , V_174 ,
V_73 -> V_128 , V_167 -> V_169 ) ;
V_167 -> V_24 = V_174 ;
}
return 1 ;
}
int F_90 ( struct V_125 * V_126 , struct V_1 * V_141 )
{
struct V_2 * V_2 = F_2 ( V_141 -> V_3 ) ;
struct V_167 * V_167 ;
int V_142 = sizeof( * V_167 ) ;
if ( F_82 ( V_126 , V_142 ) < 0 )
return V_127 ;
if ( ! F_86 ( V_2 , V_126 ) )
return V_127 ;
V_167 = (struct V_167 * ) V_126 -> V_129 ;
if ( F_70 ( V_167 -> V_169 ) ) {
F_91 ( V_141 -> V_3 , V_126 , V_141 , V_142 ) ;
return V_130 ;
}
return F_77 ( V_126 , V_141 ) ;
}
int F_92 ( struct V_125 * V_126 , struct V_1 * V_141 )
{
struct V_2 * V_2 = F_2 ( V_141 -> V_3 ) ;
struct V_175 * V_167 ;
int V_142 = sizeof( * V_167 ) ;
struct V_125 * V_168 = NULL ;
int V_51 ;
if ( F_82 ( V_126 , V_142 ) < 0 )
return V_127 ;
if ( ! F_86 ( V_2 , V_126 ) )
return V_127 ;
V_167 = (struct V_175 * ) V_126 -> V_129 ;
if ( F_70 ( V_167 -> V_169 ) ) {
V_51 = F_85 ( V_126 , V_2 , & V_168 ) ;
if ( V_51 == V_127 )
return V_127 ;
if ( ! V_168 )
return V_130 ;
F_91 ( V_141 -> V_3 , V_168 , V_141 ,
sizeof( struct V_167 ) ) ;
return V_130 ;
}
return F_77 ( V_126 , V_141 ) ;
}
int F_93 ( struct V_125 * V_126 , struct V_1 * V_141 )
{
struct V_2 * V_2 = F_2 ( V_141 -> V_3 ) ;
struct V_11 * V_11 = NULL ;
struct V_176 * V_176 ;
struct V_73 * V_73 ;
int V_142 = sizeof( * V_176 ) ;
int V_51 = V_127 ;
T_4 V_95 ;
if ( F_53 ( ! F_54 ( V_126 , V_142 ) ) )
goto V_41;
V_73 = (struct V_73 * ) F_55 ( V_126 ) ;
if ( ! F_49 ( V_73 -> V_128 ) )
goto V_41;
if ( F_49 ( V_73 -> V_78 ) )
goto V_41;
if ( F_70 ( V_73 -> V_78 ) )
goto V_41;
V_176 = (struct V_176 * ) V_126 -> V_129 ;
if ( F_70 ( V_176 -> V_33 ) )
goto V_41;
if ( V_176 -> V_85 < 2 )
goto V_41;
V_11 = F_64 ( V_2 , V_176 -> V_33 ) ;
if ( ! V_11 )
goto V_41;
F_5 ( & V_11 -> V_177 ) ;
if ( F_46 ( V_11 -> V_178 , V_11 -> V_179 ,
F_94 ( V_176 -> V_98 ) ) )
goto V_180;
V_95 = F_94 ( V_176 -> V_98 ) - V_11 -> V_179 ;
if ( F_42 ( V_2 , V_95 ,
& V_11 -> V_181 ) )
goto V_180;
if ( F_6 ( V_2 , V_11 -> V_178 , V_95 , 1 ) )
V_11 -> V_179 = F_94 ( V_176 -> V_98 ) ;
F_8 ( & V_11 -> V_177 ) ;
F_95 ( V_2 , V_126 , 1 ) ;
F_91 ( V_141 -> V_3 , V_126 , V_141 , V_142 ) ;
V_51 = V_130 ;
goto V_41;
V_180:
F_8 ( & V_11 -> V_177 ) ;
V_41:
if ( V_11 )
F_39 ( V_11 ) ;
return V_51 ;
}
int F_96 ( struct V_125 * V_126 , struct V_1 * V_141 )
{
struct V_182 * V_182 ;
struct V_73 * V_73 ;
struct V_2 * V_2 = F_2 ( V_141 -> V_3 ) ;
int V_142 = sizeof( * V_182 ) ;
if ( F_57 ( V_126 ) < 0 )
return V_127 ;
if ( F_53 ( ! F_54 ( V_126 , V_142 ) ) )
return V_127 ;
V_182 = (struct V_182 * ) V_126 -> V_129 ;
V_73 = (struct V_73 * ) F_55 ( V_126 ) ;
if ( ! F_70 ( V_73 -> V_128 ) )
return V_127 ;
if ( F_70 ( V_182 -> V_183 ) )
return V_127 ;
if ( F_70 ( V_182 -> V_184 ) )
return V_127 ;
switch ( V_182 -> V_185 ) {
case V_186 :
F_97 ( V_2 , V_182 ,
F_59 ( V_126 ) ) ;
break;
case V_187 :
F_98 ( V_2 , V_182 ,
F_59 ( V_126 ) ) ;
break;
default:
break;
}
return V_127 ;
}

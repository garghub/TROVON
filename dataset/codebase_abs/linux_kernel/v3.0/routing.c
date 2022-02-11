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
static void F_10 ( struct V_2 * V_2 , struct V_11 * V_11 ,
unsigned char * V_22 , int V_23 )
{
if ( ( V_23 != V_11 -> V_23 ) ||
( ( V_23 > 0 ) &&
( V_11 -> V_23 > 0 ) &&
( memcmp ( V_11 -> V_22 , V_22 , V_23 ) != 0 ) ) ) {
if ( V_11 -> V_23 > 0 )
F_11 ( V_2 , V_11 ,
L_1 ) ;
if ( ( V_23 > 0 ) && ( V_22 ) )
F_12 ( V_2 , V_11 ,
V_22 , V_23 ) ;
}
}
static void F_13 ( struct V_2 * V_2 ,
struct V_11 * V_11 ,
struct V_24 * V_24 ,
unsigned char * V_22 , int V_23 )
{
struct V_24 * V_25 ;
V_25 = F_14 ( V_11 ) ;
if ( ( V_25 ) && ( ! V_24 ) ) {
F_15 ( V_26 , V_2 , L_2 ,
V_11 -> V_27 ) ;
F_11 ( V_2 , V_11 ,
L_3 ) ;
} else if ( ( ! V_25 ) && ( V_24 ) ) {
F_15 ( V_26 , V_2 ,
L_4 ,
V_11 -> V_27 , V_24 -> V_28 ) ;
F_12 ( V_2 , V_11 ,
V_22 , V_23 ) ;
} else {
F_15 ( V_26 , V_2 ,
L_5
L_6 ,
V_11 -> V_27 , V_24 -> V_28 ,
V_25 -> V_28 ) ;
}
if ( V_25 )
F_16 ( V_25 ) ;
if ( V_24 && ! F_17 ( & V_24 -> V_29 ) )
V_24 = NULL ;
F_5 ( & V_11 -> V_30 ) ;
F_18 ( V_11 -> V_31 , V_24 ) ;
F_8 ( & V_11 -> V_30 ) ;
if ( V_25 )
F_16 ( V_25 ) ;
}
void F_19 ( struct V_2 * V_2 , struct V_11 * V_11 ,
struct V_24 * V_24 , unsigned char * V_22 ,
int V_23 )
{
struct V_24 * V_31 = NULL ;
if ( ! V_11 )
goto V_32;
V_31 = F_14 ( V_11 ) ;
if ( V_31 != V_24 )
F_13 ( V_2 , V_11 , V_24 ,
V_22 , V_23 ) ;
else
F_10 ( V_2 , V_11 , V_22 , V_23 ) ;
V_32:
if ( V_31 )
F_16 ( V_31 ) ;
}
static int F_20 ( struct V_11 * V_11 ,
struct V_11 * V_33 ,
struct V_34 * V_34 ,
struct V_1 * V_35 )
{
struct V_2 * V_2 = F_2 ( V_35 -> V_3 ) ;
struct V_24 * V_24 = NULL , * V_36 ;
struct V_7 * V_8 ;
unsigned char V_37 ;
T_2 V_38 , V_39 , V_40 ;
int V_41 , V_42 = 0 ;
F_3 () ;
F_4 (tmp_neigh_node, node,
&orig_neigh_node->neigh_list, list) {
if ( ! F_21 ( V_36 -> V_28 , V_33 -> V_27 ) )
continue;
if ( V_36 -> V_35 != V_35 )
continue;
if ( ! F_17 ( & V_36 -> V_29 ) )
continue;
V_24 = V_36 ;
break;
}
F_9 () ;
if ( ! V_24 )
V_24 = F_22 ( V_33 ,
V_33 ,
V_33 -> V_27 ,
V_35 ) ;
if ( ! V_24 )
goto V_32;
if ( V_11 == V_33 )
V_24 -> V_43 = V_44 ;
V_11 -> V_43 = V_44 ;
F_5 ( & V_11 -> V_17 ) ;
V_38 = V_33 -> V_21 [ V_35 -> V_18 ] ;
V_39 = V_24 -> V_45 ;
F_8 ( & V_11 -> V_17 ) ;
V_37 = ( V_38 > V_39 ?
V_39 : V_38 ) ;
if ( ( V_37 < V_46 ) ||
( V_39 < V_47 ) )
V_40 = 0 ;
else
V_40 = ( V_48 * V_37 ) / V_39 ;
V_41 = V_48 - ( V_48 *
( V_49 - V_39 ) *
( V_49 - V_39 ) *
( V_49 - V_39 ) ) /
( V_49 *
V_49 *
V_49 ) ;
V_34 -> V_50 = ( ( V_34 -> V_50 * V_40 * V_41 ) /
( V_48 * V_48 ) ) ;
F_15 ( V_51 , V_2 ,
L_7
L_8
L_9
L_10 ,
V_11 -> V_27 , V_33 -> V_27 , V_37 ,
V_39 , V_40 , V_41 , V_34 -> V_50 ) ;
if ( V_34 -> V_50 >= V_52 )
V_42 = 1 ;
V_32:
if ( V_24 )
F_16 ( V_24 ) ;
return V_42 ;
}
void F_23 ( struct V_11 * V_11 ,
struct V_24 * V_24 )
{
if ( F_24 ( & V_24 -> V_53 ) )
goto V_32;
F_25 ( & V_24 -> V_53 ) ;
F_26 ( & V_24 -> V_53 ) ;
F_16 ( V_24 ) ;
F_27 ( & V_11 -> V_54 ) ;
V_32:
return;
}
static void F_28 ( struct V_11 * V_11 ,
struct V_24 * V_24 )
{
struct V_7 * V_8 ;
struct V_24 * V_36 , * V_31 = NULL ;
T_2 V_55 = 0 ;
F_5 ( & V_11 -> V_30 ) ;
if ( ! F_21 ( V_11 -> V_27 ,
V_24 -> V_11 -> V_56 ) )
goto V_57;
V_31 = F_14 ( V_11 ) ;
if ( ! V_31 )
goto V_57;
if ( V_24 -> V_58 < V_31 -> V_58 - V_59 )
goto V_57;
F_4 (tmp_neigh_node, node,
&orig_node->neigh_list, list) {
if ( V_36 == V_24 )
continue;
if ( F_24 ( & V_36 -> V_53 ) )
continue;
if ( ( V_24 -> V_35 == V_36 -> V_35 ) ||
( F_21 ( V_24 -> V_28 , V_36 -> V_28 ) ) ) {
V_55 = 1 ;
break;
}
}
if ( V_55 )
goto V_57;
if ( ! F_24 ( & V_24 -> V_53 ) )
goto V_32;
if ( ! F_17 ( & V_24 -> V_29 ) )
goto V_32;
F_29 ( & V_24 -> V_53 , & V_11 -> V_60 ) ;
F_30 ( & V_11 -> V_54 ) ;
goto V_32;
V_57:
F_23 ( V_11 , V_24 ) ;
V_32:
F_8 ( & V_11 -> V_30 ) ;
if ( V_31 )
F_16 ( V_31 ) ;
}
static void F_31 ( struct V_11 * V_11 ,
struct V_11 * V_33 ,
struct V_34 * V_34 )
{
if ( ! ( V_34 -> V_61 & V_62 ) )
return;
memcpy ( V_33 -> V_56 , V_11 -> V_27 , V_63 ) ;
}
static void F_32 ( struct V_2 * V_2 ,
struct V_11 * V_11 ,
struct V_64 * V_64 ,
struct V_34 * V_34 ,
struct V_1 * V_35 ,
unsigned char * V_22 , int V_23 ,
char V_65 )
{
struct V_24 * V_24 = NULL , * V_36 = NULL ;
struct V_24 * V_31 = NULL ;
struct V_11 * V_66 ;
struct V_7 * V_8 ;
int V_67 ;
T_2 V_68 , V_69 ;
F_15 ( V_51 , V_2 , L_11
L_12 ) ;
F_3 () ;
F_4 (tmp_neigh_node, node,
&orig_node->neigh_list, list) {
if ( F_21 ( V_36 -> V_28 , V_64 -> V_70 ) &&
( V_36 -> V_35 == V_35 ) &&
F_17 ( & V_36 -> V_29 ) ) {
if ( V_24 )
F_16 ( V_24 ) ;
V_24 = V_36 ;
continue;
}
if ( V_65 )
continue;
F_5 ( & V_36 -> V_71 ) ;
F_33 ( V_36 -> V_72 ,
& V_36 -> V_73 , 0 ) ;
V_36 -> V_58 =
F_34 ( V_36 -> V_72 ) ;
F_8 ( & V_36 -> V_71 ) ;
}
if ( ! V_24 ) {
struct V_11 * V_74 ;
V_74 = F_35 ( V_2 , V_64 -> V_70 ) ;
if ( ! V_74 )
goto V_75;
V_24 = F_22 ( V_11 , V_74 ,
V_64 -> V_70 , V_35 ) ;
F_36 ( V_74 ) ;
if ( ! V_24 )
goto V_75;
} else
F_15 ( V_51 , V_2 ,
L_13 ) ;
F_9 () ;
V_11 -> V_61 = V_34 -> V_61 ;
V_24 -> V_43 = V_44 ;
F_5 ( & V_24 -> V_71 ) ;
F_33 ( V_24 -> V_72 ,
& V_24 -> V_73 ,
V_34 -> V_50 ) ;
V_24 -> V_58 = F_34 ( V_24 -> V_72 ) ;
F_8 ( & V_24 -> V_71 ) ;
if ( ! V_65 ) {
V_11 -> V_76 = V_34 -> V_77 ;
V_24 -> V_76 = V_34 -> V_77 ;
}
F_28 ( V_11 , V_24 ) ;
V_67 = ( V_23 > V_34 -> V_78 * V_63 ?
V_34 -> V_78 * V_63 : V_23 ) ;
V_31 = F_14 ( V_11 ) ;
if ( V_31 == V_24 )
goto V_79;
if ( V_31 && ( V_31 -> V_58 > V_24 -> V_58 ) )
goto V_79;
if ( V_31 && ( V_24 -> V_58 == V_31 -> V_58 ) ) {
V_66 = V_31 -> V_11 ;
F_5 ( & V_66 -> V_17 ) ;
V_68 =
V_66 -> V_21 [ V_35 -> V_18 ] ;
F_8 ( & V_66 -> V_17 ) ;
V_66 = V_24 -> V_11 ;
F_5 ( & V_66 -> V_17 ) ;
V_69 =
V_66 -> V_21 [ V_35 -> V_18 ] ;
F_8 ( & V_66 -> V_17 ) ;
if ( V_68 >= V_69 )
goto V_79;
}
F_19 ( V_2 , V_11 , V_24 ,
V_22 , V_67 ) ;
goto V_80;
V_79:
F_19 ( V_2 , V_11 , V_31 ,
V_22 , V_67 ) ;
V_80:
if ( V_11 -> V_81 != V_34 -> V_81 )
F_37 ( V_2 , V_11 , V_34 -> V_81 ) ;
V_11 -> V_81 = V_34 -> V_81 ;
if ( ( V_11 -> V_81 ) &&
( F_38 ( & V_2 -> V_82 ) == V_83 ) &&
( F_38 ( & V_2 -> V_84 ) > 2 ) )
F_39 ( V_2 , V_11 ) ;
goto V_32;
V_75:
F_9 () ;
V_32:
if ( V_24 )
F_16 ( V_24 ) ;
if ( V_31 )
F_16 ( V_31 ) ;
}
static int F_40 ( struct V_2 * V_2 ,
T_3 V_85 ,
unsigned long * V_86 )
{
if ( ( V_85 <= - V_49 )
|| ( V_85 >= V_87 ) ) {
if ( F_41 ( V_44 , * V_86 +
F_42 ( V_88 ) ) ) {
* V_86 = V_44 ;
F_15 ( V_51 , V_2 ,
L_14 ) ;
return 0 ;
} else
return 1 ;
}
return 0 ;
}
static char F_43 ( struct V_64 * V_64 ,
struct V_34 * V_34 ,
struct V_1 * V_35 )
{
struct V_2 * V_2 = F_2 ( V_35 -> V_3 ) ;
struct V_11 * V_11 ;
struct V_24 * V_36 ;
struct V_7 * V_8 ;
char V_65 = 0 ;
T_3 V_89 ;
int V_90 = 0 ;
int V_91 , V_42 = - 1 ;
V_11 = F_35 ( V_2 , V_34 -> V_27 ) ;
if ( ! V_11 )
return 0 ;
F_5 ( & V_11 -> V_17 ) ;
V_89 = V_34 -> V_92 - V_11 -> V_93 ;
if ( F_40 ( V_2 , V_89 ,
& V_11 -> V_94 ) )
goto V_32;
F_3 () ;
F_4 (tmp_neigh_node, node,
&orig_node->neigh_list, list) {
V_65 |= F_44 ( V_36 -> V_95 ,
V_11 -> V_93 ,
V_34 -> V_92 ) ;
if ( F_21 ( V_36 -> V_28 , V_64 -> V_70 ) &&
( V_36 -> V_35 == V_35 ) )
V_91 = 1 ;
else
V_91 = 0 ;
V_90 |= F_6 ( V_2 ,
V_36 -> V_95 ,
V_89 , V_91 ) ;
V_36 -> V_45 =
F_7 ( V_36 -> V_95 ) ;
}
F_9 () ;
if ( V_90 ) {
F_15 ( V_51 , V_2 ,
L_15 ,
V_11 -> V_93 , V_34 -> V_92 ) ;
V_11 -> V_93 = V_34 -> V_92 ;
}
V_42 = V_65 ;
V_32:
F_8 ( & V_11 -> V_17 ) ;
F_36 ( V_11 ) ;
return V_42 ;
}
void F_45 ( struct V_64 * V_64 ,
struct V_34 * V_34 ,
unsigned char * V_22 , int V_23 ,
struct V_1 * V_35 )
{
struct V_2 * V_2 = F_2 ( V_35 -> V_3 ) ;
struct V_1 * V_1 ;
struct V_11 * V_33 , * V_11 ;
struct V_24 * V_31 = NULL , * V_96 = NULL ;
struct V_24 * V_97 = NULL ;
char V_98 ;
char V_99 = 0 , V_100 = 0 , V_101 = 0 ;
char V_102 = 0 , V_103 , V_104 ;
char V_65 ;
T_4 V_105 ;
if ( V_34 -> V_106 != V_107 )
return;
V_105 = F_38 ( & V_35 -> V_92 ) ;
V_98 = ( V_34 -> V_61 & V_108 ? 1 : 0 ) ;
V_104 = ( F_21 ( V_64 -> V_70 ,
V_34 -> V_27 ) ? 1 : 0 ) ;
F_15 ( V_51 , V_2 ,
L_16
L_17
L_18 ,
V_64 -> V_70 , V_35 -> V_109 -> V_110 ,
V_35 -> V_109 -> V_111 , V_34 -> V_27 ,
V_34 -> V_112 , V_34 -> V_92 ,
V_34 -> V_50 , V_34 -> V_77 , V_34 -> V_113 ,
V_98 ) ;
F_3 () ;
F_46 (hard_iface, &hardif_list, list) {
if ( V_1 -> V_114 != V_115 )
continue;
if ( V_1 -> V_3 != V_35 -> V_3 )
continue;
if ( F_21 ( V_64 -> V_70 ,
V_1 -> V_109 -> V_111 ) )
V_99 = 1 ;
if ( F_21 ( V_34 -> V_27 ,
V_1 -> V_109 -> V_111 ) )
V_100 = 1 ;
if ( F_21 ( V_34 -> V_112 ,
V_1 -> V_109 -> V_111 ) )
V_101 = 1 ;
if ( F_21 ( V_64 -> V_70 , V_116 ) )
V_102 = 1 ;
}
F_9 () ;
if ( V_34 -> V_113 != V_117 ) {
F_15 ( V_51 , V_2 ,
L_19 ,
V_34 -> V_113 ) ;
return;
}
if ( V_99 ) {
F_15 ( V_51 , V_2 ,
L_20
L_21 ,
V_64 -> V_70 ) ;
return;
}
if ( V_102 ) {
F_15 ( V_51 , V_2 , L_22
L_23
L_21 , V_64 -> V_70 ) ;
return;
}
if ( V_100 ) {
unsigned long * V_12 ;
int V_118 ;
V_33 = F_35 ( V_2 , V_64 -> V_70 ) ;
if ( ! V_33 )
return;
if ( V_98 &&
F_21 ( V_35 -> V_109 -> V_111 ,
V_34 -> V_27 ) &&
( V_34 -> V_92 - V_105 + 2 == 0 ) ) {
V_118 = V_35 -> V_18 * V_19 ;
F_5 ( & V_33 -> V_17 ) ;
V_12 = & ( V_33 -> V_20 [ V_118 ] ) ;
F_47 ( V_12 , 0 ) ;
V_33 -> V_21 [ V_35 -> V_18 ] =
F_7 ( V_12 ) ;
F_8 ( & V_33 -> V_17 ) ;
}
F_15 ( V_51 , V_2 , L_22
L_24 ) ;
F_36 ( V_33 ) ;
return;
}
if ( V_101 ) {
F_15 ( V_51 , V_2 ,
L_25
L_26 , V_64 -> V_70 ) ;
return;
}
V_11 = F_35 ( V_2 , V_34 -> V_27 ) ;
if ( ! V_11 )
return;
V_65 = F_43 ( V_64 , V_34 , V_35 ) ;
if ( V_65 == - 1 ) {
F_15 ( V_51 , V_2 ,
L_27
L_28 , V_64 -> V_70 ) ;
goto V_32;
}
if ( V_34 -> V_50 == 0 ) {
F_15 ( V_51 , V_2 ,
L_29 ) ;
goto V_32;
}
V_31 = F_14 ( V_11 ) ;
if ( V_31 )
V_96 = F_14 ( V_31 -> V_11 ) ;
if ( V_31 && V_96 &&
( F_21 ( V_31 -> V_28 , V_34 -> V_112 ) ) &&
! ( F_21 ( V_34 -> V_27 , V_34 -> V_112 ) ) &&
( F_21 ( V_31 -> V_28 , V_96 -> V_28 ) ) ) {
F_15 ( V_51 , V_2 ,
L_30
L_31 , V_64 -> V_70 ) ;
goto V_32;
}
V_33 = ( V_104 ?
V_11 :
F_35 ( V_2 , V_64 -> V_70 ) ) ;
if ( ! V_33 )
goto V_32;
V_97 = F_14 ( V_33 ) ;
if ( ! V_104 && ( ! V_97 ) ) {
F_15 ( V_51 , V_2 ,
L_32 ) ;
goto V_119;
}
V_103 = F_20 ( V_11 , V_33 ,
V_34 , V_35 ) ;
F_31 ( V_11 , V_33 , V_34 ) ;
if ( V_103 &&
( ! V_65 ||
( ( V_11 -> V_93 == V_34 -> V_92 ) &&
( V_11 -> V_76 - 3 <= V_34 -> V_77 ) ) ) )
F_32 ( V_2 , V_11 , V_64 , V_34 ,
V_35 , V_22 , V_23 , V_65 ) ;
if ( V_104 ) {
F_48 ( V_11 , V_64 , V_34 ,
1 , V_23 , V_35 ) ;
F_15 ( V_51 , V_2 , L_33
L_34 ) ;
goto V_119;
}
if ( ! V_103 ) {
F_15 ( V_51 , V_2 ,
L_35 ) ;
goto V_119;
}
if ( V_65 ) {
F_15 ( V_51 , V_2 ,
L_36 ) ;
goto V_119;
}
F_15 ( V_51 , V_2 ,
L_37 ) ;
F_48 ( V_11 , V_64 , V_34 ,
0 , V_23 , V_35 ) ;
V_119:
if ( ( V_33 ) && ( ! V_104 ) )
F_36 ( V_33 ) ;
V_32:
if ( V_31 )
F_16 ( V_31 ) ;
if ( V_96 )
F_16 ( V_96 ) ;
if ( V_97 )
F_16 ( V_97 ) ;
F_36 ( V_11 ) ;
}
int F_49 ( struct V_120 * V_121 , struct V_1 * V_1 )
{
struct V_64 * V_64 ;
if ( F_50 ( ! F_51 ( V_121 , sizeof( struct V_34 ) ) ) )
return V_122 ;
V_64 = (struct V_64 * ) F_52 ( V_121 ) ;
if ( ! F_53 ( V_64 -> V_123 ) )
return V_122 ;
if ( F_53 ( V_64 -> V_70 ) )
return V_122 ;
if ( F_54 ( V_121 , 0 ) < 0 )
return V_122 ;
if ( F_55 ( V_121 ) < 0 )
return V_122 ;
V_64 = (struct V_64 * ) F_52 ( V_121 ) ;
F_56 ( V_64 ,
V_121 -> V_124 ,
F_57 ( V_121 ) ,
V_1 ) ;
F_58 ( V_121 ) ;
return V_125 ;
}
static int F_59 ( struct V_2 * V_2 ,
struct V_120 * V_121 , T_1 V_126 )
{
struct V_1 * V_127 = NULL ;
struct V_11 * V_11 = NULL ;
struct V_24 * V_31 = NULL ;
struct V_128 * V_129 ;
int V_42 = V_122 ;
V_129 = (struct V_128 * ) V_121 -> V_124 ;
if ( V_129 -> V_130 != V_131 ) {
F_60 ( V_129 , V_126 ) ;
goto V_32;
}
V_127 = F_61 ( V_2 ) ;
if ( ! V_127 )
goto V_32;
V_11 = F_62 ( V_2 , V_129 -> V_27 ) ;
if ( ! V_11 )
goto V_32;
V_31 = F_14 ( V_11 ) ;
if ( ! V_31 )
goto V_32;
if ( F_54 ( V_121 , sizeof( struct V_64 ) ) < 0 )
goto V_32;
V_129 = (struct V_128 * ) V_121 -> V_124 ;
memcpy ( V_129 -> V_132 , V_129 -> V_27 , V_63 ) ;
memcpy ( V_129 -> V_27 , V_127 -> V_109 -> V_111 , V_63 ) ;
V_129 -> V_130 = V_133 ;
V_129 -> V_77 = V_134 ;
F_63 ( V_121 , V_31 -> V_35 , V_31 -> V_28 ) ;
V_42 = V_125 ;
V_32:
if ( V_127 )
F_64 ( V_127 ) ;
if ( V_31 )
F_16 ( V_31 ) ;
if ( V_11 )
F_36 ( V_11 ) ;
return V_42 ;
}
static int F_65 ( struct V_2 * V_2 ,
struct V_120 * V_121 )
{
struct V_1 * V_127 = NULL ;
struct V_11 * V_11 = NULL ;
struct V_24 * V_31 = NULL ;
struct V_129 * V_129 ;
int V_42 = V_122 ;
V_129 = (struct V_129 * ) V_121 -> V_124 ;
if ( V_129 -> V_130 != V_131 ) {
F_66 ( L_38
L_39 , V_129 -> V_27 ,
V_129 -> V_132 ) ;
goto V_32;
}
V_127 = F_61 ( V_2 ) ;
if ( ! V_127 )
goto V_32;
V_11 = F_62 ( V_2 , V_129 -> V_27 ) ;
if ( ! V_11 )
goto V_32;
V_31 = F_14 ( V_11 ) ;
if ( ! V_31 )
goto V_32;
if ( F_54 ( V_121 , sizeof( struct V_64 ) ) < 0 )
goto V_32;
V_129 = (struct V_129 * ) V_121 -> V_124 ;
memcpy ( V_129 -> V_132 , V_129 -> V_27 , V_63 ) ;
memcpy ( V_129 -> V_27 , V_127 -> V_109 -> V_111 , V_63 ) ;
V_129 -> V_130 = V_135 ;
V_129 -> V_77 = V_134 ;
F_63 ( V_121 , V_31 -> V_35 , V_31 -> V_28 ) ;
V_42 = V_125 ;
V_32:
if ( V_127 )
F_64 ( V_127 ) ;
if ( V_31 )
F_16 ( V_31 ) ;
if ( V_11 )
F_36 ( V_11 ) ;
return V_42 ;
}
int F_67 ( struct V_120 * V_121 , struct V_1 * V_136 )
{
struct V_2 * V_2 = F_2 ( V_136 -> V_3 ) ;
struct V_128 * V_129 ;
struct V_64 * V_64 ;
struct V_11 * V_11 = NULL ;
struct V_24 * V_31 = NULL ;
int V_137 = sizeof( struct V_129 ) ;
int V_42 = V_122 ;
if ( V_121 -> V_138 >= sizeof( struct V_128 ) )
V_137 = sizeof( struct V_128 ) ;
if ( F_50 ( ! F_51 ( V_121 , V_137 ) ) )
goto V_32;
V_64 = (struct V_64 * ) F_52 ( V_121 ) ;
if ( F_53 ( V_64 -> V_123 ) )
goto V_32;
if ( F_53 ( V_64 -> V_70 ) )
goto V_32;
if ( ! F_68 ( V_64 -> V_123 ) )
goto V_32;
V_129 = (struct V_128 * ) V_121 -> V_124 ;
if ( ( V_137 == sizeof( struct V_128 ) ) &&
( V_129 -> V_139 < V_140 ) ) {
memcpy ( & ( V_129 -> V_141 [ V_129 -> V_139 ] ) ,
V_64 -> V_123 , V_63 ) ;
V_129 -> V_139 ++ ;
}
if ( F_68 ( V_129 -> V_132 ) )
return F_59 ( V_2 , V_121 , V_137 ) ;
if ( V_129 -> V_77 < 2 )
return F_65 ( V_2 , V_121 ) ;
V_11 = F_62 ( V_2 , V_129 -> V_132 ) ;
if ( ! V_11 )
goto V_32;
V_31 = F_14 ( V_11 ) ;
if ( ! V_31 )
goto V_32;
if ( F_54 ( V_121 , sizeof( struct V_64 ) ) < 0 )
goto V_32;
V_129 = (struct V_128 * ) V_121 -> V_124 ;
V_129 -> V_77 -- ;
F_63 ( V_121 , V_31 -> V_35 , V_31 -> V_28 ) ;
V_42 = V_125 ;
V_32:
if ( V_31 )
F_16 ( V_31 ) ;
if ( V_11 )
F_36 ( V_11 ) ;
return V_42 ;
}
static struct V_24 * F_69 ( struct V_11 * V_142 ,
struct V_1 * V_136 )
{
struct V_24 * V_36 ;
struct V_24 * V_31 = NULL , * V_143 = NULL ;
F_3 () ;
F_46 (tmp_neigh_node, &primary_orig->bond_list,
bonding_list) {
if ( ! V_143 )
V_143 = V_36 ;
if ( V_36 -> V_35 == V_136 )
continue;
if ( ! F_17 ( & V_36 -> V_29 ) )
continue;
V_31 = V_36 ;
break;
}
if ( ! V_31 && V_143 &&
F_17 ( & V_143 -> V_29 ) )
V_31 = V_143 ;
if ( ! V_31 )
goto V_32;
F_5 ( & V_142 -> V_30 ) ;
F_25 ( & V_142 -> V_60 ) ;
F_29 ( & V_142 -> V_60 ,
& V_31 -> V_53 ) ;
F_8 ( & V_142 -> V_30 ) ;
V_32:
F_9 () ;
return V_31 ;
}
static struct V_24 * F_70 ( struct V_11 * V_142 ,
struct V_1 * V_136 )
{
struct V_24 * V_36 ;
struct V_24 * V_31 = NULL , * V_143 = NULL ;
F_3 () ;
F_46 (tmp_neigh_node, &primary_orig->bond_list,
bonding_list) {
if ( ! V_143 )
V_143 = V_36 ;
if ( V_36 -> V_35 == V_136 )
continue;
if ( ! F_17 ( & V_36 -> V_29 ) )
continue;
if ( ( ! V_31 ) ||
( V_36 -> V_58 > V_31 -> V_58 ) ) {
if ( V_31 )
F_16 ( V_31 ) ;
V_31 = V_36 ;
F_17 ( & V_31 -> V_29 ) ;
}
F_16 ( V_36 ) ;
}
if ( ! V_31 && V_143 &&
F_17 ( & V_143 -> V_29 ) )
V_31 = V_143 ;
F_9 () ;
return V_31 ;
}
struct V_24 * F_71 ( struct V_2 * V_2 ,
struct V_11 * V_11 ,
struct V_1 * V_136 )
{
struct V_11 * V_144 ;
struct V_11 * V_145 ;
struct V_24 * V_31 ;
static T_2 V_146 [ V_63 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
int V_147 ;
if ( ! V_11 )
return NULL ;
V_31 = F_14 ( V_11 ) ;
if ( ! V_31 )
goto V_148;
V_147 = F_38 ( & V_2 -> V_149 ) ;
F_3 () ;
V_145 = V_31 -> V_11 ;
if ( ! V_145 )
goto V_150;
if ( ( ! V_136 ) && ( ! V_147 ) )
goto V_151;
if ( F_21 ( V_145 -> V_56 , V_146 ) )
goto V_151;
if ( F_21 ( V_145 -> V_56 , V_145 -> V_27 ) ) {
V_144 = V_145 ;
} else {
V_144 = F_62 ( V_2 ,
V_145 -> V_56 ) ;
if ( ! V_144 )
goto V_151;
F_36 ( V_144 ) ;
}
if ( F_38 ( & V_144 -> V_54 ) < 2 )
goto V_151;
F_16 ( V_31 ) ;
if ( V_147 )
V_31 = F_69 ( V_144 , V_136 ) ;
else
V_31 = F_70 ( V_144 , V_136 ) ;
V_151:
F_9 () ;
return V_31 ;
V_150:
F_9 () ;
V_148:
if ( V_31 )
F_16 ( V_31 ) ;
return NULL ;
}
static int F_72 ( struct V_120 * V_121 , int V_137 )
{
struct V_64 * V_64 ;
if ( F_50 ( ! F_51 ( V_121 , V_137 ) ) )
return - 1 ;
V_64 = (struct V_64 * ) F_52 ( V_121 ) ;
if ( F_53 ( V_64 -> V_123 ) )
return - 1 ;
if ( F_53 ( V_64 -> V_70 ) )
return - 1 ;
if ( ! F_68 ( V_64 -> V_123 ) )
return - 1 ;
return 0 ;
}
int F_73 ( struct V_120 * V_121 , struct V_1 * V_136 )
{
struct V_2 * V_2 = F_2 ( V_136 -> V_3 ) ;
struct V_11 * V_11 = NULL ;
struct V_24 * V_24 = NULL ;
struct V_152 * V_152 ;
struct V_64 * V_64 = (struct V_64 * ) F_52 ( V_121 ) ;
int V_42 = V_122 ;
struct V_120 * V_153 ;
V_152 = (struct V_152 * ) V_121 -> V_124 ;
if ( V_152 -> V_77 < 2 ) {
F_66 ( L_40
L_39 , V_64 -> V_70 ,
V_152 -> V_154 ) ;
goto V_32;
}
V_11 = F_62 ( V_2 , V_152 -> V_154 ) ;
if ( ! V_11 )
goto V_32;
V_24 = F_71 ( V_2 , V_11 , V_136 ) ;
if ( ! V_24 )
goto V_32;
if ( F_54 ( V_121 , sizeof( struct V_64 ) ) < 0 )
goto V_32;
V_152 = (struct V_152 * ) V_121 -> V_124 ;
if ( V_152 -> V_106 == V_155 &&
F_38 ( & V_2 -> V_156 ) &&
V_121 -> V_138 > V_24 -> V_35 -> V_109 -> V_157 ) {
V_42 = F_74 ( V_121 , V_2 ,
V_24 -> V_35 , V_24 -> V_28 ) ;
goto V_32;
}
if ( V_152 -> V_106 == V_158 &&
F_75 ( V_121 , V_24 -> V_35 -> V_109 -> V_157 ) ) {
V_42 = F_76 ( V_121 , V_2 , & V_153 ) ;
if ( V_42 == V_122 )
goto V_32;
if ( ! V_153 ) {
V_42 = V_125 ;
goto V_32;
}
V_121 = V_153 ;
V_152 = (struct V_152 * ) V_121 -> V_124 ;
}
V_152 -> V_77 -- ;
F_63 ( V_121 , V_24 -> V_35 , V_24 -> V_28 ) ;
V_42 = V_125 ;
V_32:
if ( V_24 )
F_16 ( V_24 ) ;
if ( V_11 )
F_36 ( V_11 ) ;
return V_42 ;
}
int F_77 ( struct V_120 * V_121 , struct V_1 * V_136 )
{
struct V_152 * V_152 ;
int V_137 = sizeof( struct V_152 ) ;
if ( F_72 ( V_121 , V_137 ) < 0 )
return V_122 ;
V_152 = (struct V_152 * ) V_121 -> V_124 ;
if ( F_68 ( V_152 -> V_154 ) ) {
F_78 ( V_136 -> V_3 , V_121 , V_136 , V_137 ) ;
return V_125 ;
}
return F_73 ( V_121 , V_136 ) ;
}
int F_79 ( struct V_120 * V_121 , struct V_1 * V_136 )
{
struct V_2 * V_2 = F_2 ( V_136 -> V_3 ) ;
struct V_159 * V_152 ;
int V_137 = sizeof( struct V_159 ) ;
struct V_120 * V_153 = NULL ;
int V_42 ;
if ( F_72 ( V_121 , V_137 ) < 0 )
return V_122 ;
V_152 = (struct V_159 * ) V_121 -> V_124 ;
if ( F_68 ( V_152 -> V_154 ) ) {
V_42 = F_76 ( V_121 , V_2 , & V_153 ) ;
if ( V_42 == V_122 )
return V_122 ;
if ( ! V_153 )
return V_125 ;
F_78 ( V_136 -> V_3 , V_153 , V_136 ,
sizeof( struct V_152 ) ) ;
return V_125 ;
}
return F_73 ( V_121 , V_136 ) ;
}
int F_80 ( struct V_120 * V_121 , struct V_1 * V_136 )
{
struct V_2 * V_2 = F_2 ( V_136 -> V_3 ) ;
struct V_11 * V_11 = NULL ;
struct V_160 * V_160 ;
struct V_64 * V_64 ;
int V_137 = sizeof( struct V_160 ) ;
int V_42 = V_122 ;
T_3 V_89 ;
if ( F_50 ( ! F_51 ( V_121 , V_137 ) ) )
goto V_32;
V_64 = (struct V_64 * ) F_52 ( V_121 ) ;
if ( ! F_53 ( V_64 -> V_123 ) )
goto V_32;
if ( F_53 ( V_64 -> V_70 ) )
goto V_32;
if ( F_68 ( V_64 -> V_70 ) )
goto V_32;
V_160 = (struct V_160 * ) V_121 -> V_124 ;
if ( F_68 ( V_160 -> V_27 ) )
goto V_32;
if ( V_160 -> V_77 < 2 )
goto V_32;
V_11 = F_62 ( V_2 , V_160 -> V_27 ) ;
if ( ! V_11 )
goto V_32;
F_5 ( & V_11 -> V_161 ) ;
if ( F_44 ( V_11 -> V_162 , V_11 -> V_163 ,
F_81 ( V_160 -> V_92 ) ) )
goto V_164;
V_89 = F_81 ( V_160 -> V_92 ) - V_11 -> V_163 ;
if ( F_40 ( V_2 , V_89 ,
& V_11 -> V_165 ) )
goto V_164;
if ( F_6 ( V_2 , V_11 -> V_162 , V_89 , 1 ) )
V_11 -> V_163 = F_81 ( V_160 -> V_92 ) ;
F_8 ( & V_11 -> V_161 ) ;
F_82 ( V_2 , V_121 ) ;
F_78 ( V_136 -> V_3 , V_121 , V_136 , V_137 ) ;
V_42 = V_125 ;
goto V_32;
V_164:
F_8 ( & V_11 -> V_161 ) ;
V_32:
if ( V_11 )
F_36 ( V_11 ) ;
return V_42 ;
}
int F_83 ( struct V_120 * V_121 , struct V_1 * V_136 )
{
struct V_166 * V_166 ;
struct V_64 * V_64 ;
struct V_2 * V_2 = F_2 ( V_136 -> V_3 ) ;
int V_137 = sizeof( struct V_166 ) ;
if ( F_55 ( V_121 ) < 0 )
return V_122 ;
if ( F_50 ( ! F_51 ( V_121 , V_137 ) ) )
return V_122 ;
V_166 = (struct V_166 * ) V_121 -> V_124 ;
V_64 = (struct V_64 * ) F_52 ( V_121 ) ;
if ( ! F_68 ( V_64 -> V_123 ) )
return V_122 ;
if ( F_68 ( V_166 -> V_167 ) )
return V_122 ;
if ( F_68 ( V_166 -> V_168 ) )
return V_122 ;
switch ( V_166 -> V_169 ) {
case V_170 :
F_84 ( V_2 , V_166 ,
F_57 ( V_121 ) ) ;
break;
case V_171 :
F_85 ( V_2 , V_166 ,
F_57 ( V_121 ) ) ;
break;
default:
break;
}
return V_122 ;
}

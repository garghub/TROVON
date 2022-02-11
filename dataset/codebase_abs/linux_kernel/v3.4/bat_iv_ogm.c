static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_2 ;
V_1 -> V_3 = V_4 ;
V_1 -> V_5 = F_2 ( V_1 -> V_3 , V_6 ) ;
V_2 = (struct V_2 * ) V_1 -> V_5 ;
V_2 -> V_7 . V_8 = V_9 ;
V_2 -> V_7 . V_10 = V_11 ;
V_2 -> V_7 . V_12 = 2 ;
V_2 -> V_13 = V_14 ;
V_2 -> V_15 = V_16 ;
V_2 -> V_17 = 0 ;
V_2 -> V_18 = 0 ;
}
static void F_3 ( struct V_1 * V_1 )
{
struct V_2 * V_2 ;
V_2 = (struct V_2 * ) V_1 -> V_5 ;
V_2 -> V_13 = V_19 ;
V_2 -> V_7 . V_12 = V_20 ;
}
static void F_4 ( struct V_1 * V_1 )
{
struct V_2 * V_2 ;
V_2 = (struct V_2 * ) V_1 -> V_5 ;
memcpy ( V_2 -> V_21 ,
V_1 -> V_22 -> V_23 , V_24 ) ;
memcpy ( V_2 -> V_25 ,
V_1 -> V_22 -> V_23 , V_24 ) ;
}
static unsigned long F_5 ( const struct V_26 * V_26 )
{
return V_27 + F_6 (
F_7 ( & V_26 -> V_28 ) -
V_29 + ( F_8 () % 2 * V_29 ) ) ;
}
static unsigned long F_9 ( void )
{
return V_27 + F_6 ( F_8 () % ( V_29 / 2 ) ) ;
}
static T_1 F_10 ( T_1 V_15 , const struct V_26 * V_26 )
{
int F_10 = F_7 ( & V_26 -> F_10 ) ;
return ( V_15 * ( V_16 - F_10 ) ) / ( V_16 ) ;
}
static int F_11 ( int V_30 , int V_3 ,
int V_17 )
{
int V_31 = V_30 + V_4 + F_12 ( V_17 ) ;
return ( V_31 <= V_3 ) &&
( V_31 <= V_32 ) ;
}
static void F_13 ( struct V_33 * V_33 ,
struct V_1 * V_1 )
{
struct V_26 * V_26 = F_14 ( V_1 -> V_34 ) ;
char * V_35 ;
T_1 V_36 ;
T_2 V_30 ;
struct V_2 * V_2 ;
struct V_37 * V_38 ;
if ( V_1 -> V_39 != V_40 )
return;
V_36 = 0 ;
V_30 = 0 ;
V_2 = (struct V_2 * ) V_33 -> V_38 -> V_41 ;
while ( F_11 ( V_30 , V_33 -> V_3 ,
V_2 -> V_17 ) ) {
if ( ( V_33 -> V_42 & ( 1 << V_36 ) ) &&
( V_33 -> V_43 == V_1 ) )
V_2 -> V_13 |= V_44 ;
else
V_2 -> V_13 &= ~ V_44 ;
V_35 = ( V_36 > 0 ? L_1 : ( V_33 -> V_45 ?
L_2 :
L_1 ) ) ;
F_15 ( V_46 , V_26 ,
L_3 ,
V_35 , ( V_36 > 0 ? L_4 : L_5 ) ,
V_2 -> V_21 ,
F_16 ( V_2 -> V_47 ) ,
V_2 -> V_15 , V_2 -> V_7 . V_12 ,
( V_2 -> V_13 & V_44 ?
L_6 : L_7 ) ,
V_2 -> V_18 , V_1 -> V_22 -> V_48 ,
V_1 -> V_22 -> V_23 ) ;
V_30 += V_4 +
F_12 ( V_2 -> V_17 ) ;
V_36 ++ ;
V_2 = (struct V_2 * )
( V_33 -> V_38 -> V_41 + V_30 ) ;
}
V_38 = F_17 ( V_33 -> V_38 , V_6 ) ;
if ( V_38 )
F_18 ( V_38 , V_1 , V_49 ) ;
}
static void F_19 ( struct V_33 * V_33 )
{
struct V_1 * V_1 ;
struct V_50 * V_34 ;
struct V_26 * V_26 ;
struct V_1 * V_51 = NULL ;
struct V_2 * V_2 ;
unsigned char V_52 ;
V_2 = (struct V_2 * )
( V_33 -> V_38 -> V_41 ) ;
V_52 = ( V_2 -> V_13 & V_44 ? 1 : 0 ) ;
if ( ! V_33 -> V_43 ) {
F_20 ( L_8 ) ;
goto V_53;
}
V_34 = V_33 -> V_43 -> V_34 ;
V_26 = F_14 ( V_34 ) ;
if ( V_33 -> V_43 -> V_39 != V_40 )
goto V_53;
V_51 = F_21 ( V_26 ) ;
if ( ! V_51 )
goto V_53;
if ( ( V_52 && ( V_2 -> V_7 . V_12 == 1 ) ) ||
( V_33 -> V_45 && ( V_33 -> V_43 != V_51 ) ) ) {
F_15 ( V_46 , V_26 ,
L_9 ,
( V_33 -> V_45 ? L_2 : L_1 ) ,
V_2 -> V_21 ,
F_16 ( V_2 -> V_47 ) ,
V_2 -> V_7 . V_12 ,
V_33 -> V_43 -> V_22 -> V_48 ,
V_33 -> V_43 -> V_22 -> V_23 ) ;
F_18 ( V_33 -> V_38 , V_33 -> V_43 ,
V_49 ) ;
V_33 -> V_38 = NULL ;
goto V_53;
}
F_22 () ;
F_23 (hard_iface, &hardif_list, list) {
if ( V_1 -> V_34 != V_34 )
continue;
F_13 ( V_33 , V_1 ) ;
}
F_24 () ;
V_53:
if ( V_51 )
F_25 ( V_51 ) ;
}
static bool F_26 ( const struct V_2
* V_54 ,
struct V_26 * V_26 ,
int V_3 , unsigned long V_55 ,
bool V_52 ,
const struct V_1 * V_43 ,
const struct V_33 * V_33 )
{
struct V_2 * V_2 ;
int V_56 = V_33 -> V_3 + V_3 ;
struct V_1 * V_51 = NULL ;
bool V_57 = false ;
V_2 = (struct V_2 * ) V_33 -> V_38 -> V_41 ;
if ( F_27 ( V_55 , V_33 -> V_55 ) &&
F_28 ( V_55 + F_6 ( V_58 ) ,
V_33 -> V_55 ) &&
( V_56 <= V_32 ) ) {
V_51 = F_21 ( V_26 ) ;
if ( ! V_51 )
goto V_53;
if ( ( ! V_52 ) &&
( ! ( V_2 -> V_13 & V_44 ) ) &&
( V_2 -> V_7 . V_12 != 1 ) &&
( ( ! V_33 -> V_45 ) ||
( V_33 -> V_43 == V_51 ) ) ) {
V_57 = true ;
goto V_53;
}
if ( ( V_52 ) &&
( V_54 -> V_7 . V_12 == 1 ) &&
( V_33 -> V_43 == V_43 ) &&
( V_2 -> V_13 & V_44 ||
( V_33 -> V_45 &&
V_33 -> V_43 != V_51 ) ) ) {
V_57 = true ;
goto V_53;
}
}
V_53:
if ( V_51 )
F_25 ( V_51 ) ;
return V_57 ;
}
static void F_29 ( const unsigned char * V_5 ,
int V_3 , unsigned long V_55 ,
bool V_59 ,
struct V_1 * V_43 ,
int V_60 )
{
struct V_26 * V_26 = F_14 ( V_43 -> V_34 ) ;
struct V_33 * V_61 ;
unsigned char * V_62 ;
if ( ! F_30 ( & V_43 -> V_63 ) )
return;
if ( ! V_60 ) {
if ( ! F_31 ( & V_26 -> V_64 ) ) {
F_15 ( V_46 , V_26 ,
L_10 ) ;
goto V_53;
}
}
V_61 = F_2 ( sizeof( * V_61 ) , V_6 ) ;
if ( ! V_61 ) {
if ( ! V_60 )
F_32 ( & V_26 -> V_64 ) ;
goto V_53;
}
if ( ( F_7 ( & V_26 -> V_65 ) ) &&
( V_3 < V_32 ) )
V_61 -> V_38 = F_33 ( V_32 +
sizeof( struct V_66 ) ) ;
else
V_61 -> V_38 = F_33 ( V_3 +
sizeof( struct V_66 ) ) ;
if ( ! V_61 -> V_38 ) {
if ( ! V_60 )
F_32 ( & V_26 -> V_64 ) ;
F_34 ( V_61 ) ;
goto V_53;
}
F_35 ( V_61 -> V_38 , sizeof( struct V_66 ) ) ;
F_36 ( & V_61 -> V_67 ) ;
V_62 = F_37 ( V_61 -> V_38 , V_3 ) ;
V_61 -> V_3 = V_3 ;
memcpy ( V_62 , V_5 , V_3 ) ;
V_61 -> V_45 = V_60 ;
V_61 -> V_43 = V_43 ;
V_61 -> V_68 = 0 ;
V_61 -> V_42 = V_14 ;
V_61 -> V_55 = V_55 ;
if ( V_59 )
V_61 -> V_42 |= 1 ;
F_38 ( & V_26 -> V_69 ) ;
F_39 ( & V_61 -> V_67 , & V_26 -> V_70 ) ;
F_40 ( & V_26 -> V_69 ) ;
F_41 ( & V_61 -> V_71 ,
V_72 ) ;
F_42 ( V_73 ,
& V_61 -> V_71 ,
V_55 - V_27 ) ;
return;
V_53:
F_25 ( V_43 ) ;
}
static void F_43 ( struct V_33 * V_61 ,
const unsigned char * V_5 ,
int V_3 , bool V_59 )
{
unsigned char * V_62 ;
V_62 = F_37 ( V_61 -> V_38 , V_3 ) ;
memcpy ( V_62 , V_5 , V_3 ) ;
V_61 -> V_3 += V_3 ;
V_61 -> V_68 ++ ;
if ( V_59 )
V_61 -> V_42 |=
( 1 << V_61 -> V_68 ) ;
}
static void F_44 ( struct V_26 * V_26 ,
unsigned char * V_5 ,
int V_3 , struct V_1 * V_43 ,
int V_60 , unsigned long V_55 )
{
struct V_33 * V_61 = NULL , * V_74 = NULL ;
struct V_75 * V_76 ;
struct V_2 * V_2 ;
bool V_59 ;
V_2 = (struct V_2 * ) V_5 ;
V_59 = V_2 -> V_13 & V_44 ? 1 : 0 ;
F_38 ( & V_26 -> V_69 ) ;
if ( ( F_7 ( & V_26 -> V_65 ) ) && ( ! V_60 ) ) {
F_45 (forw_packet_pos, tmp_node,
&bat_priv->forw_bat_list, list) {
if ( F_26 ( V_2 ,
V_26 , V_3 ,
V_55 , V_59 ,
V_43 ,
V_74 ) ) {
V_61 = V_74 ;
break;
}
}
}
if ( ! V_61 ) {
F_40 ( & V_26 -> V_69 ) ;
if ( ( ! V_60 ) &&
( F_7 ( & V_26 -> V_65 ) ) )
V_55 += F_6 ( V_58 ) ;
F_29 ( V_5 , V_3 ,
V_55 , V_59 ,
V_43 , V_60 ) ;
} else {
F_43 ( V_61 , V_5 ,
V_3 , V_59 ) ;
F_40 ( & V_26 -> V_69 ) ;
}
}
static void F_46 ( struct V_77 * V_77 ,
const struct V_66 * V_66 ,
struct V_2 * V_2 ,
int V_52 , struct V_1 * V_43 )
{
struct V_26 * V_26 = F_14 ( V_43 -> V_34 ) ;
struct V_78 * V_79 ;
T_1 V_80 , V_81 , V_82 = 0 ;
T_1 V_17 ;
if ( V_2 -> V_7 . V_12 <= 1 ) {
F_15 ( V_46 , V_26 , L_11 ) ;
return;
}
V_79 = F_47 ( V_77 ) ;
V_80 = V_2 -> V_15 ;
V_81 = V_2 -> V_7 . V_12 ;
V_17 = V_2 -> V_17 ;
V_2 -> V_7 . V_12 -- ;
memcpy ( V_2 -> V_25 , V_66 -> V_83 , V_24 ) ;
if ( V_79 && V_79 -> V_82 != 0 ) {
if ( ! F_48 ( V_79 -> V_84 , V_66 -> V_83 ) ) {
V_2 -> V_15 = V_79 -> V_82 ;
if ( V_79 -> V_85 )
V_2 -> V_7 . V_12 =
V_79 -> V_85 - 1 ;
}
V_82 = V_79 -> V_82 ;
}
if ( V_79 )
F_49 ( V_79 ) ;
V_2 -> V_15 = F_10 ( V_2 -> V_15 , V_26 ) ;
F_15 ( V_46 , V_26 ,
L_12 ,
V_80 , V_82 , V_2 -> V_15 , V_81 - 1 ,
V_2 -> V_7 . V_12 ) ;
V_2 -> V_47 = F_50 ( V_2 -> V_47 ) ;
V_2 -> V_86 = F_51 ( V_2 -> V_86 ) ;
V_2 -> V_13 &= ~ V_19 ;
if ( V_52 )
V_2 -> V_13 |= V_44 ;
else
V_2 -> V_13 &= ~ V_44 ;
F_44 ( V_26 , ( unsigned char * ) V_2 ,
V_4 + F_12 ( V_17 ) ,
V_43 , 0 , F_9 () ) ;
}
static void F_52 ( struct V_1 * V_1 ,
int V_17 )
{
struct V_26 * V_26 = F_14 ( V_1 -> V_34 ) ;
struct V_2 * V_2 ;
struct V_1 * V_51 ;
int V_87 ;
V_87 = F_7 ( & V_26 -> V_88 ) ;
V_51 = F_21 ( V_26 ) ;
V_2 = (struct V_2 * ) V_1 -> V_5 ;
V_2 -> V_47 =
F_50 ( ( V_89 ) F_7 ( & V_1 -> V_47 ) ) ;
V_2 -> V_18 = F_7 ( & V_26 -> V_18 ) ;
V_2 -> V_86 = F_51 ( ( V_90 )
F_7 ( & V_26 -> V_86 ) ) ;
if ( V_17 >= 0 )
V_2 -> V_17 = V_17 ;
if ( V_87 == V_91 )
V_2 -> V_13 |= V_92 ;
else
V_2 -> V_13 &= ~ V_92 ;
if ( ( V_1 == V_51 ) &&
( F_7 ( & V_26 -> V_93 ) == V_94 ) )
V_2 -> V_95 =
( T_1 ) F_7 ( & V_26 -> V_96 ) ;
else
V_2 -> V_95 = V_14 ;
F_32 ( & V_1 -> V_47 ) ;
F_53 ( V_1 ) ;
F_44 ( V_26 , V_1 -> V_5 ,
V_1 -> V_3 , V_1 , 1 ,
F_5 ( V_26 ) ) ;
if ( V_51 )
F_25 ( V_51 ) ;
}
static void F_54 ( struct V_26 * V_26 ,
struct V_77 * V_77 ,
const struct V_66 * V_66 ,
const struct V_2
* V_2 ,
struct V_1 * V_43 ,
const unsigned char * V_97 ,
int V_98 )
{
struct V_78 * V_78 = NULL , * V_99 = NULL ;
struct V_78 * V_79 = NULL ;
struct V_77 * V_100 ;
struct V_75 * V_101 ;
T_1 V_102 , V_103 ;
F_15 ( V_46 , V_26 ,
L_13 ) ;
F_22 () ;
F_55 (tmp_neigh_node, node,
&orig_node->neigh_list, list) {
if ( F_48 ( V_99 -> V_84 , V_66 -> V_83 ) &&
( V_99 -> V_43 == V_43 ) &&
F_30 ( & V_99 -> V_63 ) ) {
if ( V_78 )
F_49 ( V_78 ) ;
V_78 = V_99 ;
continue;
}
if ( V_98 )
continue;
F_38 ( & V_99 -> V_104 ) ;
F_56 ( V_99 -> V_105 ,
& V_99 -> V_106 , 0 ) ;
V_99 -> V_82 =
F_57 ( V_99 -> V_105 ) ;
F_40 ( & V_99 -> V_104 ) ;
}
if ( ! V_78 ) {
struct V_77 * V_107 ;
V_107 = F_58 ( V_26 , V_66 -> V_83 ) ;
if ( ! V_107 )
goto V_108;
V_78 = F_59 ( V_77 , V_107 ,
V_66 -> V_83 , V_43 ) ;
F_60 ( V_107 ) ;
if ( ! V_78 )
goto V_108;
} else
F_15 ( V_46 , V_26 ,
L_14 ) ;
F_24 () ;
V_77 -> V_13 = V_2 -> V_13 ;
V_78 -> V_109 = V_27 ;
F_38 ( & V_78 -> V_104 ) ;
F_56 ( V_78 -> V_105 ,
& V_78 -> V_106 ,
V_2 -> V_15 ) ;
V_78 -> V_82 = F_57 ( V_78 -> V_105 ) ;
F_40 ( & V_78 -> V_104 ) ;
if ( ! V_98 ) {
V_77 -> V_85 = V_2 -> V_7 . V_12 ;
V_78 -> V_85 = V_2 -> V_7 . V_12 ;
}
F_61 ( V_77 , V_78 ) ;
V_79 = F_47 ( V_77 ) ;
if ( V_79 == V_78 )
goto V_110;
if ( V_79 && ( V_79 -> V_82 > V_78 -> V_82 ) )
goto V_110;
if ( V_79 && ( V_78 -> V_82 == V_79 -> V_82 ) ) {
V_100 = V_79 -> V_77 ;
F_38 ( & V_100 -> V_111 ) ;
V_102 =
V_100 -> V_112 [ V_43 -> V_113 ] ;
F_40 ( & V_100 -> V_111 ) ;
V_100 = V_78 -> V_77 ;
F_38 ( & V_100 -> V_111 ) ;
V_103 =
V_100 -> V_112 [ V_43 -> V_113 ] ;
F_40 ( & V_100 -> V_111 ) ;
if ( V_102 >= V_103 )
goto V_110;
}
F_62 ( V_26 , V_77 , V_78 ) ;
V_110:
if ( ( ( V_2 -> V_21 != V_66 -> V_83 ) &&
( V_2 -> V_7 . V_12 > 2 ) ) ||
( V_2 -> V_13 & V_19 ) )
F_63 ( V_26 , V_77 , V_97 ,
V_2 -> V_17 ,
V_2 -> V_18 ,
V_2 -> V_86 ) ;
if ( V_77 -> V_95 != V_2 -> V_95 )
F_64 ( V_26 , V_77 ,
V_2 -> V_95 ) ;
V_77 -> V_95 = V_2 -> V_95 ;
if ( ( V_77 -> V_95 ) &&
( F_7 ( & V_26 -> V_93 ) == V_114 ) &&
( F_7 ( & V_26 -> V_115 ) > 2 ) )
F_65 ( V_26 , V_77 ) ;
goto V_53;
V_108:
F_24 () ;
V_53:
if ( V_78 )
F_49 ( V_78 ) ;
if ( V_79 )
F_49 ( V_79 ) ;
}
static int F_66 ( struct V_77 * V_77 ,
struct V_77 * V_116 ,
struct V_2 * V_2 ,
struct V_1 * V_43 )
{
struct V_26 * V_26 = F_14 ( V_43 -> V_34 ) ;
struct V_78 * V_78 = NULL , * V_99 ;
struct V_75 * V_101 ;
T_1 V_117 ;
T_1 V_118 , V_119 , V_120 ;
int V_121 , V_122 = 0 ;
F_22 () ;
F_55 (tmp_neigh_node, node,
&orig_neigh_node->neigh_list, list) {
if ( ! F_48 ( V_99 -> V_84 , V_116 -> V_21 ) )
continue;
if ( V_99 -> V_43 != V_43 )
continue;
if ( ! F_30 ( & V_99 -> V_63 ) )
continue;
V_78 = V_99 ;
break;
}
F_24 () ;
if ( ! V_78 )
V_78 = F_59 ( V_116 ,
V_116 ,
V_116 -> V_21 ,
V_43 ) ;
if ( ! V_78 )
goto V_53;
if ( V_77 == V_116 )
V_78 -> V_109 = V_27 ;
V_77 -> V_109 = V_27 ;
F_38 ( & V_77 -> V_111 ) ;
V_118 = V_116 -> V_112 [ V_43 -> V_113 ] ;
V_119 = V_78 -> V_123 ;
F_40 ( & V_77 -> V_111 ) ;
V_117 = ( V_118 > V_119 ?
V_119 : V_118 ) ;
if ( ( V_117 < V_124 ) ||
( V_119 < V_125 ) )
V_120 = 0 ;
else
V_120 = ( V_16 * V_117 ) / V_119 ;
V_121 = V_16 - ( V_16 *
( V_126 - V_119 ) *
( V_126 - V_119 ) *
( V_126 - V_119 ) ) /
( V_126 *
V_126 *
V_126 ) ;
V_2 -> V_15 = ( ( V_2 -> V_15 * V_120
* V_121 ) /
( V_16 * V_16 ) ) ;
F_15 ( V_46 , V_26 ,
L_15 ,
V_77 -> V_21 , V_116 -> V_21 , V_117 ,
V_119 , V_120 , V_121 , V_2 -> V_15 ) ;
if ( V_2 -> V_15 >= V_127 )
V_122 = 1 ;
V_53:
if ( V_78 )
F_49 ( V_78 ) ;
return V_122 ;
}
static int F_67 ( const struct V_66 * V_66 ,
const struct V_2
* V_2 ,
const struct V_1 * V_43 )
{
struct V_26 * V_26 = F_14 ( V_43 -> V_34 ) ;
struct V_77 * V_77 ;
struct V_78 * V_99 ;
struct V_75 * V_101 ;
int V_98 = 0 ;
T_3 V_128 ;
int V_129 = 0 ;
int V_130 , V_122 = - 1 ;
V_77 = F_58 ( V_26 , V_2 -> V_21 ) ;
if ( ! V_77 )
return 0 ;
F_38 ( & V_77 -> V_111 ) ;
V_128 = V_2 -> V_47 - V_77 -> V_131 ;
if ( F_68 ( V_26 , V_128 ,
& V_77 -> V_132 ) )
goto V_53;
F_22 () ;
F_55 (tmp_neigh_node, node,
&orig_node->neigh_list, list) {
V_98 |= F_69 ( V_99 -> V_133 ,
V_77 -> V_131 ,
V_2 -> V_47 ) ;
if ( F_48 ( V_99 -> V_84 , V_66 -> V_83 ) &&
( V_99 -> V_43 == V_43 ) )
V_130 = 1 ;
else
V_130 = 0 ;
V_129 |= F_70 ( V_26 ,
V_99 -> V_133 ,
V_128 , V_130 ) ;
V_99 -> V_123 =
F_71 ( V_99 -> V_133 ) ;
}
F_24 () ;
if ( V_129 ) {
F_15 ( V_46 , V_26 ,
L_16 ,
V_77 -> V_131 , V_2 -> V_47 ) ;
V_77 -> V_131 = V_2 -> V_47 ;
}
V_122 = V_98 ;
V_53:
F_40 ( & V_77 -> V_111 ) ;
F_60 ( V_77 ) ;
return V_122 ;
}
static void F_72 ( const struct V_66 * V_66 ,
struct V_2 * V_2 ,
const unsigned char * V_97 ,
struct V_1 * V_43 )
{
struct V_26 * V_26 = F_14 ( V_43 -> V_34 ) ;
struct V_1 * V_1 ;
struct V_77 * V_116 , * V_77 ;
struct V_78 * V_79 = NULL , * V_134 = NULL ;
struct V_78 * V_135 = NULL ;
int V_136 ;
int V_137 = 0 , V_138 = 0 , V_139 = 0 ;
int V_140 = 0 , V_141 , V_142 ;
int V_98 ;
V_89 V_143 ;
if ( V_2 -> V_7 . V_8 != V_9 )
return;
V_143 = F_7 ( & V_43 -> V_47 ) ;
V_136 = ( V_2 -> V_13 & V_44 ? 1 : 0 ) ;
V_142 = ( F_48 ( V_66 -> V_83 ,
V_2 -> V_21 ) ? 1 : 0 ) ;
F_15 ( V_46 , V_26 ,
L_17 ,
V_66 -> V_83 , V_43 -> V_22 -> V_48 ,
V_43 -> V_22 -> V_23 , V_2 -> V_21 ,
V_2 -> V_25 , V_2 -> V_47 ,
V_2 -> V_18 , V_2 -> V_86 ,
V_2 -> V_17 , V_2 -> V_15 ,
V_2 -> V_7 . V_12 ,
V_2 -> V_7 . V_10 , V_136 ) ;
F_22 () ;
F_23 (hard_iface, &hardif_list, list) {
if ( V_1 -> V_39 != V_40 )
continue;
if ( V_1 -> V_34 != V_43 -> V_34 )
continue;
if ( F_48 ( V_66 -> V_83 ,
V_1 -> V_22 -> V_23 ) )
V_137 = 1 ;
if ( F_48 ( V_2 -> V_21 ,
V_1 -> V_22 -> V_23 ) )
V_138 = 1 ;
if ( F_48 ( V_2 -> V_25 ,
V_1 -> V_22 -> V_23 ) )
V_139 = 1 ;
if ( F_73 ( V_66 -> V_83 ) )
V_140 = 1 ;
}
F_24 () ;
if ( V_2 -> V_7 . V_10 != V_11 ) {
F_15 ( V_46 , V_26 ,
L_18 ,
V_2 -> V_7 . V_10 ) ;
return;
}
if ( V_137 ) {
F_15 ( V_46 , V_26 ,
L_19 ,
V_66 -> V_83 ) ;
return;
}
if ( V_140 ) {
F_15 ( V_46 , V_26 ,
L_20 ,
V_66 -> V_83 ) ;
return;
}
if ( V_138 ) {
unsigned long * V_144 ;
int V_145 ;
V_116 = F_58 ( V_26 , V_66 -> V_83 ) ;
if ( ! V_116 )
return;
if ( V_136 &&
F_48 ( V_43 -> V_22 -> V_23 ,
V_2 -> V_21 ) ) {
V_145 = V_43 -> V_113 * V_146 ;
F_38 ( & V_116 -> V_111 ) ;
V_144 = & ( V_116 -> V_147 [ V_145 ] ) ;
F_74 ( V_144 ,
V_143 -
V_2 -> V_47 - 2 ) ;
V_116 -> V_112 [ V_43 -> V_113 ] =
F_71 ( V_144 ) ;
F_40 ( & V_116 -> V_111 ) ;
}
F_15 ( V_46 , V_26 ,
L_21 ) ;
F_60 ( V_116 ) ;
return;
}
if ( V_139 ) {
F_15 ( V_46 , V_26 ,
L_22 ,
V_66 -> V_83 ) ;
return;
}
V_77 = F_58 ( V_26 , V_2 -> V_21 ) ;
if ( ! V_77 )
return;
V_98 = F_67 ( V_66 , V_2 ,
V_43 ) ;
if ( V_98 == - 1 ) {
F_15 ( V_46 , V_26 ,
L_23 ,
V_66 -> V_83 ) ;
goto V_53;
}
if ( V_2 -> V_15 == 0 ) {
F_15 ( V_46 , V_26 ,
L_24 ) ;
goto V_53;
}
V_79 = F_47 ( V_77 ) ;
if ( V_79 )
V_134 = F_47 ( V_79 -> V_77 ) ;
if ( V_79 && V_134 &&
( F_48 ( V_79 -> V_84 , V_2 -> V_25 ) ) &&
! ( F_48 ( V_2 -> V_21 ,
V_2 -> V_25 ) ) &&
( F_48 ( V_79 -> V_84 , V_134 -> V_84 ) ) ) {
F_15 ( V_46 , V_26 ,
L_25 ,
V_66 -> V_83 ) ;
goto V_53;
}
V_116 = ( V_142 ?
V_77 :
F_58 ( V_26 , V_66 -> V_83 ) ) ;
if ( ! V_116 )
goto V_53;
V_135 = F_47 ( V_116 ) ;
if ( ! V_142 && ( ! V_135 ) ) {
F_15 ( V_46 , V_26 ,
L_26 ) ;
goto V_148;
}
V_141 = F_66 ( V_77 , V_116 ,
V_2 , V_43 ) ;
F_75 ( V_77 , V_116 , V_2 ) ;
if ( V_141 &&
( ! V_98 ||
( ( V_77 -> V_131 == V_2 -> V_47 ) &&
( V_77 -> V_85 - 3 <= V_2 -> V_7 . V_12 ) ) ) )
F_54 ( V_26 , V_77 , V_66 ,
V_2 , V_43 ,
V_97 , V_98 ) ;
if ( V_142 ) {
F_46 ( V_77 , V_66 , V_2 ,
1 , V_43 ) ;
F_15 ( V_46 , V_26 ,
L_27 ) ;
goto V_148;
}
if ( ! V_141 ) {
F_15 ( V_46 , V_26 ,
L_28 ) ;
goto V_148;
}
if ( V_98 ) {
F_15 ( V_46 , V_26 ,
L_29 ) ;
goto V_148;
}
F_15 ( V_46 , V_26 ,
L_30 ) ;
F_46 ( V_77 , V_66 , V_2 ,
0 , V_43 ) ;
V_148:
if ( ( V_116 ) && ( ! V_142 ) )
F_60 ( V_116 ) ;
V_53:
if ( V_79 )
F_49 ( V_79 ) ;
if ( V_134 )
F_49 ( V_134 ) ;
if ( V_135 )
F_49 ( V_135 ) ;
F_60 ( V_77 ) ;
}
static void F_76 ( struct V_1 * V_43 ,
struct V_37 * V_38 )
{
struct V_2 * V_2 ;
struct V_66 * V_66 ;
int V_30 = 0 , V_3 ;
unsigned char * V_97 , * V_5 ;
V_3 = F_77 ( V_38 ) ;
V_66 = (struct V_66 * ) F_78 ( V_38 ) ;
V_5 = V_38 -> V_41 ;
V_2 = (struct V_2 * ) V_5 ;
do {
V_2 -> V_47 = F_16 ( V_2 -> V_47 ) ;
V_2 -> V_86 = F_79 ( V_2 -> V_86 ) ;
V_97 = V_5 + V_30 + V_4 ;
F_72 ( V_66 , V_2 ,
V_97 , V_43 ) ;
V_30 += V_4 +
F_12 ( V_2 -> V_17 ) ;
V_2 = (struct V_2 * )
( V_5 + V_30 ) ;
} while ( F_11 ( V_30 , V_3 ,
V_2 -> V_17 ) );
}
int T_4 F_80 ( void )
{
return F_81 ( & V_149 ) ;
}

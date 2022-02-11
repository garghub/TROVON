void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_2 ;
V_1 -> V_3 = V_4 ;
V_1 -> V_5 = F_2 ( V_1 -> V_3 , V_6 ) ;
V_2 = (struct V_2 * ) V_1 -> V_5 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = V_10 ;
V_2 -> V_11 = V_12 ;
V_2 -> V_13 = 2 ;
V_2 -> V_14 = V_15 ;
V_2 -> V_16 = 0 ;
V_2 -> V_17 = 0 ;
}
void F_3 ( struct V_1 * V_1 )
{
struct V_2 * V_2 ;
V_2 = (struct V_2 * ) V_1 -> V_5 ;
V_2 -> V_11 = V_18 ;
V_2 -> V_13 = V_19 ;
}
void F_4 ( struct V_1 * V_1 )
{
struct V_2 * V_2 ;
V_2 = (struct V_2 * ) V_1 -> V_5 ;
memcpy ( V_2 -> V_20 ,
V_1 -> V_21 -> V_22 , V_23 ) ;
memcpy ( V_2 -> V_24 ,
V_1 -> V_21 -> V_22 , V_23 ) ;
}
static unsigned long F_5 ( const struct V_25 * V_25 )
{
return V_26 + F_6 (
F_7 ( & V_25 -> V_27 ) -
V_28 + ( F_8 () % 2 * V_28 ) ) ;
}
static unsigned long F_9 ( void )
{
return V_26 + F_6 ( F_8 () % ( V_28 / 2 ) ) ;
}
static T_1 F_10 ( T_1 V_14 , const struct V_25 * V_25 )
{
int F_10 = F_7 ( & V_25 -> F_10 ) ;
return ( V_14 * ( V_15 - F_10 ) ) / ( V_15 ) ;
}
static int F_11 ( int V_29 , int V_3 ,
int V_16 )
{
int V_30 = V_29 + V_4 + F_12 ( V_16 ) ;
return ( V_30 <= V_3 ) &&
( V_30 <= V_31 ) ;
}
static void F_13 ( struct V_32 * V_32 ,
struct V_1 * V_1 )
{
struct V_25 * V_25 = F_14 ( V_1 -> V_33 ) ;
char * V_34 ;
T_1 V_35 ;
T_2 V_29 ;
struct V_2 * V_2 ;
struct V_36 * V_37 ;
if ( V_1 -> V_38 != V_39 )
return;
V_35 = 0 ;
V_29 = 0 ;
V_2 = (struct V_2 * ) V_32 -> V_37 -> V_40 ;
while ( F_11 ( V_29 , V_32 -> V_3 ,
V_2 -> V_16 ) ) {
if ( ( V_32 -> V_41 & ( 1 << V_35 ) ) &&
( V_32 -> V_42 == V_1 ) )
V_2 -> V_11 |= V_43 ;
else
V_2 -> V_11 &= ~ V_43 ;
V_34 = ( V_35 > 0 ? L_1 : ( V_32 -> V_44 ?
L_2 :
L_1 ) ) ;
F_15 ( V_45 , V_25 ,
L_3
L_4 ,
V_34 , ( V_35 > 0 ? L_5 : L_6 ) ,
V_2 -> V_20 ,
F_16 ( V_2 -> V_46 ) ,
V_2 -> V_14 , V_2 -> V_13 ,
( V_2 -> V_11 & V_43 ?
L_7 : L_8 ) ,
V_2 -> V_17 , V_1 -> V_21 -> V_47 ,
V_1 -> V_21 -> V_22 ) ;
V_29 += V_4 +
F_12 ( V_2 -> V_16 ) ;
V_35 ++ ;
V_2 = (struct V_2 * )
( V_32 -> V_37 -> V_40 + V_29 ) ;
}
V_37 = F_17 ( V_32 -> V_37 , V_6 ) ;
if ( V_37 )
F_18 ( V_37 , V_1 , V_48 ) ;
}
void F_19 ( struct V_32 * V_32 )
{
struct V_1 * V_1 ;
struct V_49 * V_33 ;
struct V_25 * V_25 ;
struct V_1 * V_50 = NULL ;
struct V_2 * V_2 ;
unsigned char V_51 ;
V_2 = (struct V_2 * )
( V_32 -> V_37 -> V_40 ) ;
V_51 = ( V_2 -> V_11 & V_43 ? 1 : 0 ) ;
if ( ! V_32 -> V_42 ) {
F_20 ( L_9
L_10 ) ;
goto V_52;
}
V_33 = V_32 -> V_42 -> V_33 ;
V_25 = F_14 ( V_33 ) ;
if ( V_32 -> V_42 -> V_38 != V_39 )
goto V_52;
V_50 = F_21 ( V_25 ) ;
if ( ! V_50 )
goto V_52;
if ( ( V_51 && ( V_2 -> V_13 == 1 ) ) ||
( V_32 -> V_44 && ( V_32 -> V_42 != V_50 ) ) ) {
F_15 ( V_45 , V_25 ,
L_11
L_12 ,
( V_32 -> V_44 ? L_2 : L_1 ) ,
V_2 -> V_20 ,
F_16 ( V_2 -> V_46 ) ,
V_2 -> V_13 ,
V_32 -> V_42 -> V_21 -> V_47 ,
V_32 -> V_42 -> V_21 -> V_22 ) ;
F_18 ( V_32 -> V_37 , V_32 -> V_42 ,
V_48 ) ;
V_32 -> V_37 = NULL ;
goto V_52;
}
F_22 () ;
F_23 (hard_iface, &hardif_list, list) {
if ( V_1 -> V_33 != V_33 )
continue;
F_13 ( V_32 , V_1 ) ;
}
F_24 () ;
V_52:
if ( V_50 )
F_25 ( V_50 ) ;
}
static bool F_26 ( const struct V_2
* V_53 ,
struct V_25 * V_25 ,
int V_3 , unsigned long V_54 ,
bool V_51 ,
const struct V_1 * V_42 ,
const struct V_32 * V_32 )
{
struct V_2 * V_2 ;
int V_55 = V_32 -> V_3 + V_3 ;
struct V_1 * V_50 = NULL ;
bool V_56 = false ;
V_2 = (struct V_2 * ) V_32 -> V_37 -> V_40 ;
if ( F_27 ( V_54 , V_32 -> V_54 ) &&
F_28 ( V_54 + F_6 ( V_57 ) ,
V_32 -> V_54 ) &&
( V_55 <= V_31 ) ) {
V_50 = F_21 ( V_25 ) ;
if ( ! V_50 )
goto V_52;
if ( ( ! V_51 ) &&
( ! ( V_2 -> V_11 & V_43 ) ) &&
( V_2 -> V_13 != 1 ) &&
( ( ! V_32 -> V_44 ) ||
( V_32 -> V_42 == V_50 ) ) ) {
V_56 = true ;
goto V_52;
}
if ( ( V_51 ) &&
( V_53 -> V_13 == 1 ) &&
( V_32 -> V_42 == V_42 ) &&
( V_2 -> V_11 & V_43 ||
( V_32 -> V_44 &&
V_32 -> V_42 != V_50 ) ) ) {
V_56 = true ;
goto V_52;
}
}
V_52:
if ( V_50 )
F_25 ( V_50 ) ;
return V_56 ;
}
static void F_29 ( const unsigned char * V_5 ,
int V_3 , unsigned long V_54 ,
bool V_58 ,
struct V_1 * V_42 ,
int V_59 )
{
struct V_25 * V_25 = F_14 ( V_42 -> V_33 ) ;
struct V_32 * V_60 ;
unsigned char * V_61 ;
if ( ! F_30 ( & V_42 -> V_62 ) )
return;
if ( ! V_59 ) {
if ( ! F_31 ( & V_25 -> V_63 ) ) {
F_15 ( V_45 , V_25 ,
L_13 ) ;
goto V_52;
}
}
V_60 = F_2 ( sizeof( * V_60 ) , V_6 ) ;
if ( ! V_60 ) {
if ( ! V_59 )
F_32 ( & V_25 -> V_63 ) ;
goto V_52;
}
if ( ( F_7 ( & V_25 -> V_64 ) ) &&
( V_3 < V_31 ) )
V_60 -> V_37 = F_33 ( V_31 +
sizeof( struct V_65 ) ) ;
else
V_60 -> V_37 = F_33 ( V_3 +
sizeof( struct V_65 ) ) ;
if ( ! V_60 -> V_37 ) {
if ( ! V_59 )
F_32 ( & V_25 -> V_63 ) ;
F_34 ( V_60 ) ;
goto V_52;
}
F_35 ( V_60 -> V_37 , sizeof( struct V_65 ) ) ;
F_36 ( & V_60 -> V_66 ) ;
V_61 = F_37 ( V_60 -> V_37 , V_3 ) ;
V_60 -> V_3 = V_3 ;
memcpy ( V_61 , V_5 , V_3 ) ;
V_60 -> V_44 = V_59 ;
V_60 -> V_42 = V_42 ;
V_60 -> V_67 = 0 ;
V_60 -> V_41 = V_12 ;
V_60 -> V_54 = V_54 ;
if ( V_58 )
V_60 -> V_41 |= 1 ;
F_38 ( & V_25 -> V_68 ) ;
F_39 ( & V_60 -> V_66 , & V_25 -> V_69 ) ;
F_40 ( & V_25 -> V_68 ) ;
F_41 ( & V_60 -> V_70 ,
V_71 ) ;
F_42 ( V_72 ,
& V_60 -> V_70 ,
V_54 - V_26 ) ;
return;
V_52:
F_25 ( V_42 ) ;
}
static void F_43 ( struct V_32 * V_60 ,
const unsigned char * V_5 ,
int V_3 , bool V_58 )
{
unsigned char * V_61 ;
V_61 = F_37 ( V_60 -> V_37 , V_3 ) ;
memcpy ( V_61 , V_5 , V_3 ) ;
V_60 -> V_3 += V_3 ;
V_60 -> V_67 ++ ;
if ( V_58 )
V_60 -> V_41 |=
( 1 << V_60 -> V_67 ) ;
}
static void F_44 ( struct V_25 * V_25 ,
unsigned char * V_5 ,
int V_3 , struct V_1 * V_42 ,
int V_59 , unsigned long V_54 )
{
struct V_32 * V_60 = NULL , * V_73 = NULL ;
struct V_74 * V_75 ;
struct V_2 * V_2 ;
bool V_58 ;
V_2 = (struct V_2 * ) V_5 ;
V_58 = V_2 -> V_11 & V_43 ? 1 : 0 ;
F_38 ( & V_25 -> V_68 ) ;
if ( ( F_7 ( & V_25 -> V_64 ) ) && ( ! V_59 ) ) {
F_45 (forw_packet_pos, tmp_node,
&bat_priv->forw_bat_list, list) {
if ( F_26 ( V_2 ,
V_25 , V_3 ,
V_54 , V_58 ,
V_42 ,
V_73 ) ) {
V_60 = V_73 ;
break;
}
}
}
if ( ! V_60 ) {
F_40 ( & V_25 -> V_68 ) ;
if ( ( ! V_59 ) &&
( F_7 ( & V_25 -> V_64 ) ) )
V_54 += F_6 ( V_57 ) ;
F_29 ( V_5 , V_3 ,
V_54 , V_58 ,
V_42 , V_59 ) ;
} else {
F_43 ( V_60 , V_5 , V_3 ,
V_58 ) ;
F_40 ( & V_25 -> V_68 ) ;
}
}
static void F_46 ( struct V_76 * V_76 ,
const struct V_65 * V_65 ,
struct V_2 * V_2 ,
int V_51 , struct V_1 * V_42 )
{
struct V_25 * V_25 = F_14 ( V_42 -> V_33 ) ;
struct V_77 * V_78 ;
T_1 V_79 , V_80 , V_81 = 0 ;
T_1 V_16 ;
if ( V_2 -> V_13 <= 1 ) {
F_15 ( V_45 , V_25 , L_14 ) ;
return;
}
V_78 = F_47 ( V_76 ) ;
V_79 = V_2 -> V_14 ;
V_80 = V_2 -> V_13 ;
V_16 = V_2 -> V_16 ;
V_2 -> V_13 -- ;
memcpy ( V_2 -> V_24 , V_65 -> V_82 , V_23 ) ;
if ( V_78 && V_78 -> V_81 != 0 ) {
if ( ! F_48 ( V_78 -> V_83 , V_65 -> V_82 ) ) {
V_2 -> V_14 = V_78 -> V_81 ;
if ( V_78 -> V_84 )
V_2 -> V_13 = V_78 -> V_84 - 1 ;
}
V_81 = V_78 -> V_81 ;
}
if ( V_78 )
F_49 ( V_78 ) ;
V_2 -> V_14 = F_10 ( V_2 -> V_14 , V_25 ) ;
F_15 ( V_45 , V_25 ,
L_15
L_16 ,
V_79 , V_81 , V_2 -> V_14 , V_80 - 1 ,
V_2 -> V_13 ) ;
V_2 -> V_46 = F_50 ( V_2 -> V_46 ) ;
V_2 -> V_85 = F_51 ( V_2 -> V_85 ) ;
V_2 -> V_11 &= ~ V_18 ;
if ( V_51 )
V_2 -> V_11 |= V_43 ;
else
V_2 -> V_11 &= ~ V_43 ;
F_44 ( V_25 , ( unsigned char * ) V_2 ,
V_4 + F_12 ( V_16 ) ,
V_42 , 0 , F_9 () ) ;
}
void F_52 ( struct V_1 * V_1 , int V_16 )
{
struct V_25 * V_25 = F_14 ( V_1 -> V_33 ) ;
struct V_2 * V_2 ;
struct V_1 * V_50 ;
int V_86 ;
V_86 = F_7 ( & V_25 -> V_87 ) ;
V_50 = F_21 ( V_25 ) ;
V_2 = (struct V_2 * ) V_1 -> V_5 ;
V_2 -> V_46 =
F_50 ( ( V_88 ) F_7 ( & V_1 -> V_46 ) ) ;
V_2 -> V_17 = F_7 ( & V_25 -> V_17 ) ;
V_2 -> V_85 = F_51 ( ( V_89 )
F_7 ( & V_25 -> V_85 ) ) ;
if ( V_16 >= 0 )
V_2 -> V_16 = V_16 ;
if ( V_86 == V_90 )
V_2 -> V_11 |= V_91 ;
else
V_2 -> V_11 &= ~ V_91 ;
if ( ( V_1 == V_50 ) &&
( F_7 ( & V_25 -> V_92 ) == V_93 ) )
V_2 -> V_94 =
( T_1 ) F_7 ( & V_25 -> V_95 ) ;
else
V_2 -> V_94 = V_12 ;
F_32 ( & V_1 -> V_46 ) ;
F_53 ( V_1 ) ;
F_44 ( V_25 , V_1 -> V_5 ,
V_1 -> V_3 , V_1 , 1 ,
F_5 ( V_25 ) ) ;
if ( V_50 )
F_25 ( V_50 ) ;
}
static void F_54 ( struct V_25 * V_25 ,
struct V_76 * V_76 ,
const struct V_65 * V_65 ,
const struct V_2
* V_2 ,
struct V_1 * V_42 ,
const unsigned char * V_96 , int V_97 )
{
struct V_77 * V_77 = NULL , * V_98 = NULL ;
struct V_77 * V_78 = NULL ;
struct V_76 * V_99 ;
struct V_74 * V_100 ;
T_1 V_101 , V_102 ;
F_15 ( V_45 , V_25 , L_17
L_18 ) ;
F_22 () ;
F_55 (tmp_neigh_node, node,
&orig_node->neigh_list, list) {
if ( F_48 ( V_98 -> V_83 , V_65 -> V_82 ) &&
( V_98 -> V_42 == V_42 ) &&
F_30 ( & V_98 -> V_62 ) ) {
if ( V_77 )
F_49 ( V_77 ) ;
V_77 = V_98 ;
continue;
}
if ( V_97 )
continue;
F_38 ( & V_98 -> V_103 ) ;
F_56 ( V_98 -> V_104 ,
& V_98 -> V_105 , 0 ) ;
V_98 -> V_81 =
F_57 ( V_98 -> V_104 ) ;
F_40 ( & V_98 -> V_103 ) ;
}
if ( ! V_77 ) {
struct V_76 * V_106 ;
V_106 = F_58 ( V_25 , V_65 -> V_82 ) ;
if ( ! V_106 )
goto V_107;
V_77 = F_59 ( V_76 , V_106 ,
V_65 -> V_82 , V_42 ) ;
F_60 ( V_106 ) ;
if ( ! V_77 )
goto V_107;
} else
F_15 ( V_45 , V_25 ,
L_19 ) ;
F_24 () ;
V_76 -> V_11 = V_2 -> V_11 ;
V_77 -> V_108 = V_26 ;
F_38 ( & V_77 -> V_103 ) ;
F_56 ( V_77 -> V_104 ,
& V_77 -> V_105 ,
V_2 -> V_14 ) ;
V_77 -> V_81 = F_57 ( V_77 -> V_104 ) ;
F_40 ( & V_77 -> V_103 ) ;
if ( ! V_97 ) {
V_76 -> V_84 = V_2 -> V_13 ;
V_77 -> V_84 = V_2 -> V_13 ;
}
F_61 ( V_76 , V_77 ) ;
V_78 = F_47 ( V_76 ) ;
if ( V_78 == V_77 )
goto V_109;
if ( V_78 && ( V_78 -> V_81 > V_77 -> V_81 ) )
goto V_109;
if ( V_78 && ( V_77 -> V_81 == V_78 -> V_81 ) ) {
V_99 = V_78 -> V_76 ;
F_38 ( & V_99 -> V_110 ) ;
V_101 =
V_99 -> V_111 [ V_42 -> V_112 ] ;
F_40 ( & V_99 -> V_110 ) ;
V_99 = V_77 -> V_76 ;
F_38 ( & V_99 -> V_110 ) ;
V_102 =
V_99 -> V_111 [ V_42 -> V_112 ] ;
F_40 ( & V_99 -> V_110 ) ;
if ( V_101 >= V_102 )
goto V_109;
}
F_62 ( V_25 , V_76 , V_77 ) ;
V_109:
if ( ( ( V_2 -> V_20 != V_65 -> V_82 ) &&
( V_2 -> V_13 > 2 ) ) ||
( V_2 -> V_11 & V_18 ) )
F_63 ( V_25 , V_76 , V_96 ,
V_2 -> V_16 ,
V_2 -> V_17 ,
V_2 -> V_85 ) ;
if ( V_76 -> V_94 != V_2 -> V_94 )
F_64 ( V_25 , V_76 ,
V_2 -> V_94 ) ;
V_76 -> V_94 = V_2 -> V_94 ;
if ( ( V_76 -> V_94 ) &&
( F_7 ( & V_25 -> V_92 ) == V_113 ) &&
( F_7 ( & V_25 -> V_114 ) > 2 ) )
F_65 ( V_25 , V_76 ) ;
goto V_52;
V_107:
F_24 () ;
V_52:
if ( V_77 )
F_49 ( V_77 ) ;
if ( V_78 )
F_49 ( V_78 ) ;
}
static int F_66 ( struct V_76 * V_76 ,
struct V_76 * V_115 ,
struct V_2 * V_2 ,
struct V_1 * V_42 )
{
struct V_25 * V_25 = F_14 ( V_42 -> V_33 ) ;
struct V_77 * V_77 = NULL , * V_98 ;
struct V_74 * V_100 ;
T_1 V_116 ;
T_1 V_117 , V_118 , V_119 ;
int V_120 , V_121 = 0 ;
F_22 () ;
F_55 (tmp_neigh_node, node,
&orig_neigh_node->neigh_list, list) {
if ( ! F_48 ( V_98 -> V_83 , V_115 -> V_20 ) )
continue;
if ( V_98 -> V_42 != V_42 )
continue;
if ( ! F_30 ( & V_98 -> V_62 ) )
continue;
V_77 = V_98 ;
break;
}
F_24 () ;
if ( ! V_77 )
V_77 = F_59 ( V_115 ,
V_115 ,
V_115 -> V_20 ,
V_42 ) ;
if ( ! V_77 )
goto V_52;
if ( V_76 == V_115 )
V_77 -> V_108 = V_26 ;
V_76 -> V_108 = V_26 ;
F_38 ( & V_76 -> V_110 ) ;
V_117 = V_115 -> V_111 [ V_42 -> V_112 ] ;
V_118 = V_77 -> V_122 ;
F_40 ( & V_76 -> V_110 ) ;
V_116 = ( V_117 > V_118 ?
V_118 : V_117 ) ;
if ( ( V_116 < V_123 ) ||
( V_118 < V_124 ) )
V_119 = 0 ;
else
V_119 = ( V_15 * V_116 ) / V_118 ;
V_120 = V_15 - ( V_15 *
( V_125 - V_118 ) *
( V_125 - V_118 ) *
( V_125 - V_118 ) ) /
( V_125 *
V_125 *
V_125 ) ;
V_2 -> V_14 = ( ( V_2 -> V_14 * V_119
* V_120 ) /
( V_15 * V_15 ) ) ;
F_15 ( V_45 , V_25 ,
L_20
L_21
L_22
L_23 ,
V_76 -> V_20 , V_115 -> V_20 , V_116 ,
V_118 , V_119 , V_120 , V_2 -> V_14 ) ;
if ( V_2 -> V_14 >= V_126 )
V_121 = 1 ;
V_52:
if ( V_77 )
F_49 ( V_77 ) ;
return V_121 ;
}
static int F_67 ( const struct V_65 * V_65 ,
const struct V_2
* V_2 ,
const struct V_1 * V_42 )
{
struct V_25 * V_25 = F_14 ( V_42 -> V_33 ) ;
struct V_76 * V_76 ;
struct V_77 * V_98 ;
struct V_74 * V_100 ;
int V_97 = 0 ;
T_3 V_127 ;
int V_128 = 0 ;
int V_129 , V_121 = - 1 ;
V_76 = F_58 ( V_25 , V_2 -> V_20 ) ;
if ( ! V_76 )
return 0 ;
F_38 ( & V_76 -> V_110 ) ;
V_127 = V_2 -> V_46 - V_76 -> V_130 ;
if ( F_68 ( V_25 , V_127 ,
& V_76 -> V_131 ) )
goto V_52;
F_22 () ;
F_55 (tmp_neigh_node, node,
&orig_node->neigh_list, list) {
V_97 |= F_69 ( V_98 -> V_132 ,
V_76 -> V_130 ,
V_2 -> V_46 ) ;
if ( F_48 ( V_98 -> V_83 , V_65 -> V_82 ) &&
( V_98 -> V_42 == V_42 ) )
V_129 = 1 ;
else
V_129 = 0 ;
V_128 |= F_70 ( V_25 ,
V_98 -> V_132 ,
V_127 , V_129 ) ;
V_98 -> V_122 =
F_71 ( V_98 -> V_132 ) ;
}
F_24 () ;
if ( V_128 ) {
F_15 ( V_45 , V_25 ,
L_24 ,
V_76 -> V_130 , V_2 -> V_46 ) ;
V_76 -> V_130 = V_2 -> V_46 ;
}
V_121 = V_97 ;
V_52:
F_40 ( & V_76 -> V_110 ) ;
F_60 ( V_76 ) ;
return V_121 ;
}
static void F_72 ( const struct V_65 * V_65 ,
struct V_2 * V_2 ,
const unsigned char * V_96 ,
struct V_1 * V_42 )
{
struct V_25 * V_25 = F_14 ( V_42 -> V_33 ) ;
struct V_1 * V_1 ;
struct V_76 * V_115 , * V_76 ;
struct V_77 * V_78 = NULL , * V_133 = NULL ;
struct V_77 * V_134 = NULL ;
int V_135 ;
int V_136 = 0 , V_137 = 0 , V_138 = 0 ;
int V_139 = 0 , V_140 , V_141 ;
int V_97 ;
V_88 V_142 ;
if ( V_2 -> V_7 != V_8 )
return;
V_142 = F_7 ( & V_42 -> V_46 ) ;
V_135 = ( V_2 -> V_11 & V_43 ? 1 : 0 ) ;
V_141 = ( F_48 ( V_65 -> V_82 ,
V_2 -> V_20 ) ? 1 : 0 ) ;
F_15 ( V_45 , V_25 ,
L_25
L_26
L_27 ,
V_65 -> V_82 , V_42 -> V_21 -> V_47 ,
V_42 -> V_21 -> V_22 , V_2 -> V_20 ,
V_2 -> V_24 , V_2 -> V_46 ,
V_2 -> V_17 , V_2 -> V_85 ,
V_2 -> V_16 , V_2 -> V_14 ,
V_2 -> V_13 , V_2 -> V_9 ,
V_135 ) ;
F_22 () ;
F_23 (hard_iface, &hardif_list, list) {
if ( V_1 -> V_38 != V_39 )
continue;
if ( V_1 -> V_33 != V_42 -> V_33 )
continue;
if ( F_48 ( V_65 -> V_82 ,
V_1 -> V_21 -> V_22 ) )
V_136 = 1 ;
if ( F_48 ( V_2 -> V_20 ,
V_1 -> V_21 -> V_22 ) )
V_137 = 1 ;
if ( F_48 ( V_2 -> V_24 ,
V_1 -> V_21 -> V_22 ) )
V_138 = 1 ;
if ( F_73 ( V_65 -> V_82 ) )
V_139 = 1 ;
}
F_24 () ;
if ( V_2 -> V_9 != V_10 ) {
F_15 ( V_45 , V_25 ,
L_28 ,
V_2 -> V_9 ) ;
return;
}
if ( V_136 ) {
F_15 ( V_45 , V_25 ,
L_29
L_30 ,
V_65 -> V_82 ) ;
return;
}
if ( V_139 ) {
F_15 ( V_45 , V_25 , L_31
L_32
L_30 , V_65 -> V_82 ) ;
return;
}
if ( V_137 ) {
unsigned long * V_143 ;
int V_144 ;
V_115 = F_58 ( V_25 , V_65 -> V_82 ) ;
if ( ! V_115 )
return;
if ( V_135 &&
F_48 ( V_42 -> V_21 -> V_22 ,
V_2 -> V_20 ) ) {
V_144 = V_42 -> V_112 * V_145 ;
F_38 ( & V_115 -> V_110 ) ;
V_143 = & ( V_115 -> V_146 [ V_144 ] ) ;
F_74 ( V_143 ,
V_142 -
V_2 -> V_46 - 2 ) ;
V_115 -> V_111 [ V_42 -> V_112 ] =
F_71 ( V_143 ) ;
F_40 ( & V_115 -> V_110 ) ;
}
F_15 ( V_45 , V_25 , L_31
L_33 ) ;
F_60 ( V_115 ) ;
return;
}
if ( V_138 ) {
F_15 ( V_45 , V_25 ,
L_34
L_35 , V_65 -> V_82 ) ;
return;
}
V_76 = F_58 ( V_25 , V_2 -> V_20 ) ;
if ( ! V_76 )
return;
V_97 = F_67 ( V_65 , V_2 ,
V_42 ) ;
if ( V_97 == - 1 ) {
F_15 ( V_45 , V_25 ,
L_36
L_37 , V_65 -> V_82 ) ;
goto V_52;
}
if ( V_2 -> V_14 == 0 ) {
F_15 ( V_45 , V_25 ,
L_38 ) ;
goto V_52;
}
V_78 = F_47 ( V_76 ) ;
if ( V_78 )
V_133 = F_47 ( V_78 -> V_76 ) ;
if ( V_78 && V_133 &&
( F_48 ( V_78 -> V_83 , V_2 -> V_24 ) ) &&
! ( F_48 ( V_2 -> V_20 ,
V_2 -> V_24 ) ) &&
( F_48 ( V_78 -> V_83 , V_133 -> V_83 ) ) ) {
F_15 ( V_45 , V_25 ,
L_39
L_40 , V_65 -> V_82 ) ;
goto V_52;
}
V_115 = ( V_141 ?
V_76 :
F_58 ( V_25 , V_65 -> V_82 ) ) ;
if ( ! V_115 )
goto V_52;
V_134 = F_47 ( V_115 ) ;
if ( ! V_141 && ( ! V_134 ) ) {
F_15 ( V_45 , V_25 ,
L_41 ) ;
goto V_147;
}
V_140 = F_66 ( V_76 , V_115 ,
V_2 , V_42 ) ;
F_75 ( V_76 , V_115 , V_2 ) ;
if ( V_140 &&
( ! V_97 ||
( ( V_76 -> V_130 == V_2 -> V_46 ) &&
( V_76 -> V_84 - 3 <= V_2 -> V_13 ) ) ) )
F_54 ( V_25 , V_76 , V_65 ,
V_2 , V_42 ,
V_96 , V_97 ) ;
if ( V_141 ) {
F_46 ( V_76 , V_65 , V_2 ,
1 , V_42 ) ;
F_15 ( V_45 , V_25 , L_42
L_43 ) ;
goto V_147;
}
if ( ! V_140 ) {
F_15 ( V_45 , V_25 ,
L_44 ) ;
goto V_147;
}
if ( V_97 ) {
F_15 ( V_45 , V_25 ,
L_45 ) ;
goto V_147;
}
F_15 ( V_45 , V_25 ,
L_46 ) ;
F_46 ( V_76 , V_65 , V_2 , 0 , V_42 ) ;
V_147:
if ( ( V_115 ) && ( ! V_141 ) )
F_60 ( V_115 ) ;
V_52:
if ( V_78 )
F_49 ( V_78 ) ;
if ( V_133 )
F_49 ( V_133 ) ;
if ( V_134 )
F_49 ( V_134 ) ;
F_60 ( V_76 ) ;
}
void F_76 ( const struct V_65 * V_65 , unsigned char * V_5 ,
int V_3 , struct V_1 * V_42 )
{
struct V_2 * V_2 ;
int V_29 = 0 ;
unsigned char * V_96 ;
V_2 = (struct V_2 * ) V_5 ;
do {
V_2 -> V_46 = F_16 ( V_2 -> V_46 ) ;
V_2 -> V_85 = F_77 ( V_2 -> V_85 ) ;
V_96 = V_5 + V_29 + V_4 ;
F_72 ( V_65 , V_2 ,
V_96 , V_42 ) ;
V_29 += V_4 +
F_12 ( V_2 -> V_16 ) ;
V_2 = (struct V_2 * )
( V_5 + V_29 ) ;
} while ( F_11 ( V_29 , V_3 ,
V_2 -> V_16 ) );
}

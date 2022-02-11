static struct V_1 * F_1 ( struct V_2 * V_2 ,
const T_1 * V_3 ,
struct V_4 * V_4 ,
struct V_4 * V_5 ,
T_2 V_6 )
{
struct V_1 * V_1 ;
V_1 = F_2 ( V_2 , V_3 , V_6 ) ;
if ( ! V_1 )
goto V_7;
F_3 ( & V_1 -> V_8 ) ;
V_1 -> V_4 = V_5 ;
V_1 -> V_9 = V_2 ;
F_4 ( & V_4 -> V_10 ) ;
F_5 ( & V_1 -> V_11 , & V_4 -> V_12 ) ;
F_6 ( & V_4 -> V_10 ) ;
V_7:
return V_1 ;
}
static int F_7 ( struct V_2 * V_2 )
{
struct V_13 * V_13 ;
T_2 V_14 ;
int V_15 = - 1 ;
F_8 ( & V_14 , sizeof( V_14 ) ) ;
F_9 ( & V_2 -> V_6 , V_14 ) ;
V_2 -> V_16 = V_17 ;
V_2 -> V_18 = F_10 ( V_2 -> V_16 , V_19 ) ;
if ( ! V_2 -> V_18 )
goto V_7;
V_13 = (struct V_13 * ) V_2 -> V_18 ;
V_13 -> V_20 . V_21 = V_22 ;
V_13 -> V_20 . V_23 = V_24 ;
V_13 -> V_20 . V_25 = 2 ;
V_13 -> V_26 = V_27 ;
V_13 -> V_28 = V_29 ;
V_13 -> V_30 = 0 ;
V_13 -> V_31 = 0 ;
V_15 = 0 ;
V_7:
return V_15 ;
}
static void F_11 ( struct V_2 * V_2 )
{
F_12 ( V_2 -> V_18 ) ;
V_2 -> V_18 = NULL ;
}
static void F_13 ( struct V_2 * V_2 )
{
struct V_13 * V_13 ;
V_13 = (struct V_13 * ) V_2 -> V_18 ;
memcpy ( V_13 -> V_32 ,
V_2 -> V_33 -> V_34 , V_35 ) ;
memcpy ( V_13 -> V_36 ,
V_2 -> V_33 -> V_34 , V_35 ) ;
}
static void F_14 ( struct V_2 * V_2 )
{
struct V_13 * V_13 ;
V_13 = (struct V_13 * ) V_2 -> V_18 ;
V_13 -> V_26 = V_37 ;
V_13 -> V_20 . V_25 = V_38 ;
}
static unsigned long F_15 ( const struct V_39 * V_39 )
{
return V_40 + F_16 (
F_17 ( & V_39 -> V_41 ) -
V_42 + ( F_18 () % 2 * V_42 ) ) ;
}
static unsigned long F_19 ( void )
{
return V_40 + F_16 ( F_18 () % ( V_42 / 2 ) ) ;
}
static T_1 F_20 ( T_1 V_28 , const struct V_39 * V_39 )
{
int F_20 = F_17 ( & V_39 -> F_20 ) ;
return ( V_28 * ( V_29 - F_20 ) ) / ( V_29 ) ;
}
static int F_21 ( int V_43 , int V_16 ,
int V_30 )
{
int V_44 = V_43 + V_17 + F_22 ( V_30 ) ;
return ( V_44 <= V_16 ) &&
( V_44 <= V_45 ) ;
}
static void F_23 ( struct V_46 * V_46 ,
struct V_2 * V_2 )
{
struct V_39 * V_39 = F_24 ( V_2 -> V_47 ) ;
char * V_48 ;
T_1 V_49 ;
T_3 V_43 ;
struct V_13 * V_13 ;
struct V_50 * V_51 ;
if ( V_2 -> V_52 != V_53 )
return;
V_49 = 0 ;
V_43 = 0 ;
V_13 = (struct V_13 * ) V_46 -> V_51 -> V_54 ;
while ( F_21 ( V_43 , V_46 -> V_16 ,
V_13 -> V_30 ) ) {
if ( ( V_46 -> V_55 & ( 1 << V_49 ) ) &&
( V_46 -> V_9 == V_2 ) )
V_13 -> V_26 |= V_56 ;
else
V_13 -> V_26 &= ~ V_56 ;
V_48 = ( V_49 > 0 ? L_1 : ( V_46 -> V_57 ?
L_2 :
L_1 ) ) ;
F_25 ( V_58 , V_39 ,
L_3 ,
V_48 , ( V_49 > 0 ? L_4 : L_5 ) ,
V_13 -> V_32 ,
F_26 ( V_13 -> V_6 ) ,
V_13 -> V_28 , V_13 -> V_20 . V_25 ,
( V_13 -> V_26 & V_56 ?
L_6 : L_7 ) ,
V_13 -> V_31 , V_2 -> V_33 -> V_59 ,
V_2 -> V_33 -> V_34 ) ;
V_43 += V_17 +
F_22 ( V_13 -> V_30 ) ;
V_49 ++ ;
V_13 = (struct V_13 * )
( V_46 -> V_51 -> V_54 + V_43 ) ;
}
V_51 = F_27 ( V_46 -> V_51 , V_19 ) ;
if ( V_51 )
F_28 ( V_51 , V_2 , V_60 ) ;
}
static void F_29 ( struct V_46 * V_46 )
{
struct V_2 * V_2 ;
struct V_61 * V_47 ;
struct V_39 * V_39 ;
struct V_2 * V_62 = NULL ;
struct V_13 * V_13 ;
unsigned char V_63 ;
V_13 = (struct V_13 * )
( V_46 -> V_51 -> V_54 ) ;
V_63 = ( V_13 -> V_26 & V_56 ? 1 : 0 ) ;
if ( ! V_46 -> V_9 ) {
F_30 ( L_8 ) ;
goto V_7;
}
V_47 = V_46 -> V_9 -> V_47 ;
V_39 = F_24 ( V_47 ) ;
if ( V_46 -> V_9 -> V_52 != V_53 )
goto V_7;
V_62 = F_31 ( V_39 ) ;
if ( ! V_62 )
goto V_7;
if ( ( V_63 && ( V_13 -> V_20 . V_25 == 1 ) ) ||
( V_46 -> V_57 && ( V_46 -> V_9 != V_62 ) ) ) {
F_25 ( V_58 , V_39 ,
L_9 ,
( V_46 -> V_57 ? L_2 : L_1 ) ,
V_13 -> V_32 ,
F_26 ( V_13 -> V_6 ) ,
V_13 -> V_20 . V_25 ,
V_46 -> V_9 -> V_33 -> V_59 ,
V_46 -> V_9 -> V_33 -> V_34 ) ;
F_28 ( V_46 -> V_51 , V_46 -> V_9 ,
V_60 ) ;
V_46 -> V_51 = NULL ;
goto V_7;
}
F_32 () ;
F_33 (hard_iface, &hardif_list, list) {
if ( V_2 -> V_47 != V_47 )
continue;
F_23 ( V_46 , V_2 ) ;
}
F_34 () ;
V_7:
if ( V_62 )
F_35 ( V_62 ) ;
}
static bool F_36 ( const struct V_13
* V_64 ,
struct V_39 * V_39 ,
int V_16 , unsigned long V_65 ,
bool V_63 ,
const struct V_2 * V_9 ,
const struct V_46 * V_46 )
{
struct V_13 * V_13 ;
int V_66 = V_46 -> V_16 + V_16 ;
struct V_2 * V_62 = NULL ;
bool V_15 = false ;
V_13 = (struct V_13 * ) V_46 -> V_51 -> V_54 ;
if ( F_37 ( V_65 , V_46 -> V_65 ) &&
F_38 ( V_65 + F_16 ( V_67 ) ,
V_46 -> V_65 ) &&
( V_66 <= V_45 ) ) {
V_62 = F_31 ( V_39 ) ;
if ( ! V_62 )
goto V_7;
if ( ( ! V_63 ) &&
( ! ( V_13 -> V_26 & V_56 ) ) &&
( V_13 -> V_20 . V_25 != 1 ) &&
( ( ! V_46 -> V_57 ) ||
( V_46 -> V_9 == V_62 ) ) ) {
V_15 = true ;
goto V_7;
}
if ( ( V_63 ) &&
( V_64 -> V_20 . V_25 == 1 ) &&
( V_46 -> V_9 == V_9 ) &&
( V_13 -> V_26 & V_56 ||
( V_46 -> V_57 &&
V_46 -> V_9 != V_62 ) ) ) {
V_15 = true ;
goto V_7;
}
}
V_7:
if ( V_62 )
F_35 ( V_62 ) ;
return V_15 ;
}
static void F_39 ( const unsigned char * V_18 ,
int V_16 , unsigned long V_65 ,
bool V_68 ,
struct V_2 * V_9 ,
int V_69 )
{
struct V_39 * V_39 = F_24 ( V_9 -> V_47 ) ;
struct V_46 * V_70 ;
unsigned char * V_71 ;
if ( ! F_40 ( & V_9 -> V_72 ) )
return;
if ( ! V_69 ) {
if ( ! F_41 ( & V_39 -> V_73 ) ) {
F_25 ( V_58 , V_39 ,
L_10 ) ;
goto V_7;
}
}
V_70 = F_10 ( sizeof( * V_70 ) , V_19 ) ;
if ( ! V_70 ) {
if ( ! V_69 )
F_42 ( & V_39 -> V_73 ) ;
goto V_7;
}
if ( ( F_17 ( & V_39 -> V_74 ) ) &&
( V_16 < V_45 ) )
V_70 -> V_51 = F_43 ( V_45 +
V_75 ) ;
else
V_70 -> V_51 = F_43 ( V_16 + V_75 ) ;
if ( ! V_70 -> V_51 ) {
if ( ! V_69 )
F_42 ( & V_39 -> V_73 ) ;
F_12 ( V_70 ) ;
goto V_7;
}
F_44 ( V_70 -> V_51 , V_75 ) ;
F_45 ( & V_70 -> V_11 ) ;
V_71 = F_46 ( V_70 -> V_51 , V_16 ) ;
V_70 -> V_16 = V_16 ;
memcpy ( V_71 , V_18 , V_16 ) ;
V_70 -> V_57 = V_69 ;
V_70 -> V_9 = V_9 ;
V_70 -> V_76 = 0 ;
V_70 -> V_55 = V_27 ;
V_70 -> V_65 = V_65 ;
if ( V_68 )
V_70 -> V_55 |= 1 ;
F_4 ( & V_39 -> V_77 ) ;
F_47 ( & V_70 -> V_11 , & V_39 -> V_78 ) ;
F_6 ( & V_39 -> V_77 ) ;
F_48 ( & V_70 -> V_79 ,
V_80 ) ;
F_49 ( V_81 ,
& V_70 -> V_79 ,
V_65 - V_40 ) ;
return;
V_7:
F_35 ( V_9 ) ;
}
static void F_50 ( struct V_46 * V_70 ,
const unsigned char * V_18 ,
int V_16 , bool V_68 )
{
unsigned char * V_71 ;
V_71 = F_46 ( V_70 -> V_51 , V_16 ) ;
memcpy ( V_71 , V_18 , V_16 ) ;
V_70 -> V_16 += V_16 ;
V_70 -> V_76 ++ ;
if ( V_68 )
V_70 -> V_55 |=
( 1 << V_70 -> V_76 ) ;
}
static void F_51 ( struct V_39 * V_39 ,
unsigned char * V_18 ,
int V_16 , struct V_2 * V_9 ,
int V_69 , unsigned long V_65 )
{
struct V_46 * V_70 = NULL , * V_82 = NULL ;
struct V_83 * V_84 ;
struct V_13 * V_13 ;
bool V_68 ;
V_13 = (struct V_13 * ) V_18 ;
V_68 = V_13 -> V_26 & V_56 ? 1 : 0 ;
F_4 ( & V_39 -> V_77 ) ;
if ( ( F_17 ( & V_39 -> V_74 ) ) && ( ! V_69 ) ) {
F_52 (forw_packet_pos, tmp_node,
&bat_priv->forw_bat_list, list) {
if ( F_36 ( V_13 ,
V_39 , V_16 ,
V_65 , V_68 ,
V_9 ,
V_82 ) ) {
V_70 = V_82 ;
break;
}
}
}
if ( ! V_70 ) {
F_6 ( & V_39 -> V_77 ) ;
if ( ( ! V_69 ) &&
( F_17 ( & V_39 -> V_74 ) ) )
V_65 += F_16 ( V_67 ) ;
F_39 ( V_18 , V_16 ,
V_65 , V_68 ,
V_9 , V_69 ) ;
} else {
F_50 ( V_70 , V_18 ,
V_16 , V_68 ) ;
F_6 ( & V_39 -> V_77 ) ;
}
}
static void F_53 ( struct V_4 * V_4 ,
const struct V_85 * V_85 ,
struct V_13 * V_13 ,
bool V_86 ,
bool V_87 ,
struct V_2 * V_9 )
{
struct V_39 * V_39 = F_24 ( V_9 -> V_47 ) ;
T_1 V_30 ;
if ( V_13 -> V_20 . V_25 <= 1 ) {
F_25 ( V_58 , V_39 , L_11 ) ;
return;
}
if ( ! V_87 ) {
if ( V_86 )
V_13 -> V_26 |= V_88 ;
else
return;
}
V_30 = V_13 -> V_30 ;
V_13 -> V_20 . V_25 -- ;
memcpy ( V_13 -> V_36 , V_85 -> V_89 , V_35 ) ;
V_13 -> V_28 = F_20 ( V_13 -> V_28 , V_39 ) ;
F_25 ( V_58 , V_39 ,
L_12 ,
V_13 -> V_28 , V_13 -> V_20 . V_25 ) ;
V_13 -> V_6 = F_54 ( V_13 -> V_6 ) ;
V_13 -> V_90 = F_55 ( V_13 -> V_90 ) ;
V_13 -> V_26 &= ~ V_37 ;
if ( V_86 )
V_13 -> V_26 |= V_56 ;
else
V_13 -> V_26 &= ~ V_56 ;
F_51 ( V_39 , ( unsigned char * ) V_13 ,
V_17 + F_22 ( V_30 ) ,
V_9 , 0 , F_19 () ) ;
}
static void F_56 ( struct V_2 * V_2 ,
int V_30 )
{
struct V_39 * V_39 = F_24 ( V_2 -> V_47 ) ;
struct V_13 * V_13 ;
struct V_2 * V_62 ;
int V_91 ;
V_91 = F_17 ( & V_39 -> V_92 ) ;
V_62 = F_31 ( V_39 ) ;
V_13 = (struct V_13 * ) V_2 -> V_18 ;
V_13 -> V_6 =
F_54 ( ( T_2 ) F_17 ( & V_2 -> V_6 ) ) ;
V_13 -> V_31 = F_17 ( & V_39 -> V_31 ) ;
V_13 -> V_90 = F_55 ( ( V_93 )
F_17 ( & V_39 -> V_90 ) ) ;
if ( V_30 >= 0 )
V_13 -> V_30 = V_30 ;
if ( V_91 == V_94 )
V_13 -> V_26 |= V_95 ;
else
V_13 -> V_26 &= ~ V_95 ;
if ( ( V_2 == V_62 ) &&
( F_17 ( & V_39 -> V_96 ) == V_97 ) )
V_13 -> V_98 =
( T_1 ) F_17 ( & V_39 -> V_99 ) ;
else
V_13 -> V_98 = V_27 ;
F_42 ( & V_2 -> V_6 ) ;
F_57 ( V_2 ) ;
F_51 ( V_39 , V_2 -> V_18 ,
V_2 -> V_16 , V_2 , 1 ,
F_15 ( V_39 ) ) ;
if ( V_62 )
F_35 ( V_62 ) ;
}
static void F_58 ( struct V_39 * V_39 ,
struct V_4 * V_4 ,
const struct V_85 * V_85 ,
const struct V_13
* V_13 ,
struct V_2 * V_9 ,
const unsigned char * V_100 ,
int V_101 )
{
struct V_1 * V_1 = NULL , * V_102 = NULL ;
struct V_1 * V_103 = NULL ;
struct V_4 * V_104 ;
struct V_83 * V_105 ;
T_1 V_106 , V_107 ;
F_25 ( V_58 , V_39 ,
L_13 ) ;
F_32 () ;
F_59 (tmp_neigh_node, node,
&orig_node->neigh_list, list) {
if ( F_60 ( V_102 -> V_108 , V_85 -> V_89 ) &&
( V_102 -> V_9 == V_9 ) &&
F_40 ( & V_102 -> V_72 ) ) {
if ( V_1 )
F_61 ( V_1 ) ;
V_1 = V_102 ;
continue;
}
if ( V_101 )
continue;
F_4 ( & V_102 -> V_109 ) ;
F_62 ( V_102 -> V_110 ,
& V_102 -> V_111 , 0 ) ;
V_102 -> V_112 =
F_63 ( V_102 -> V_110 ) ;
F_6 ( & V_102 -> V_109 ) ;
}
if ( ! V_1 ) {
struct V_4 * V_113 ;
V_113 = F_64 ( V_39 , V_85 -> V_89 ) ;
if ( ! V_113 )
goto V_114;
V_1 = F_1 ( V_9 , V_85 -> V_89 ,
V_4 , V_113 ,
V_13 -> V_6 ) ;
F_65 ( V_113 ) ;
if ( ! V_1 )
goto V_114;
} else
F_25 ( V_58 , V_39 ,
L_14 ) ;
F_34 () ;
V_4 -> V_26 = V_13 -> V_26 ;
V_1 -> V_115 = V_40 ;
F_4 ( & V_1 -> V_109 ) ;
F_62 ( V_1 -> V_110 ,
& V_1 -> V_111 ,
V_13 -> V_28 ) ;
V_1 -> V_112 = F_63 ( V_1 -> V_110 ) ;
F_6 ( & V_1 -> V_109 ) ;
if ( ! V_101 ) {
V_4 -> V_116 = V_13 -> V_20 . V_25 ;
V_1 -> V_116 = V_13 -> V_20 . V_25 ;
}
F_66 ( V_4 , V_1 ) ;
V_103 = F_67 ( V_4 ) ;
if ( V_103 == V_1 )
goto V_117;
if ( V_103 && ( V_103 -> V_112 > V_1 -> V_112 ) )
goto V_117;
if ( V_103 && ( V_1 -> V_112 == V_103 -> V_112 ) ) {
V_104 = V_103 -> V_4 ;
F_4 ( & V_104 -> V_118 ) ;
V_106 =
V_104 -> V_119 [ V_9 -> V_120 ] ;
F_6 ( & V_104 -> V_118 ) ;
V_104 = V_1 -> V_4 ;
F_4 ( & V_104 -> V_118 ) ;
V_107 =
V_104 -> V_119 [ V_9 -> V_120 ] ;
F_6 ( & V_104 -> V_118 ) ;
if ( V_106 >= V_107 )
goto V_117;
}
F_68 ( V_39 , V_4 , V_1 ) ;
V_117:
if ( ( ( V_13 -> V_32 != V_85 -> V_89 ) &&
( V_13 -> V_20 . V_25 > 2 ) ) ||
( V_13 -> V_26 & V_37 ) )
F_69 ( V_39 , V_4 , V_100 ,
V_13 -> V_30 ,
V_13 -> V_31 ,
V_13 -> V_90 ) ;
if ( V_4 -> V_98 != V_13 -> V_98 )
F_70 ( V_39 , V_4 ,
V_13 -> V_98 ) ;
V_4 -> V_98 = V_13 -> V_98 ;
if ( ( V_4 -> V_98 ) &&
( F_17 ( & V_39 -> V_96 ) == V_121 ) &&
( F_17 ( & V_39 -> V_122 ) > 2 ) )
F_71 ( V_39 , V_4 ) ;
goto V_7;
V_114:
F_34 () ;
V_7:
if ( V_1 )
F_61 ( V_1 ) ;
if ( V_103 )
F_61 ( V_103 ) ;
}
static int F_72 ( struct V_4 * V_4 ,
struct V_4 * V_123 ,
struct V_13 * V_13 ,
struct V_2 * V_9 )
{
struct V_39 * V_39 = F_24 ( V_9 -> V_47 ) ;
struct V_1 * V_1 = NULL , * V_102 ;
struct V_83 * V_105 ;
T_1 V_124 ;
T_1 V_125 , V_126 , V_127 ;
int V_128 , V_129 = 0 ;
F_32 () ;
F_59 (tmp_neigh_node, node,
&orig_neigh_node->neigh_list, list) {
if ( ! F_60 ( V_102 -> V_108 , V_123 -> V_32 ) )
continue;
if ( V_102 -> V_9 != V_9 )
continue;
if ( ! F_40 ( & V_102 -> V_72 ) )
continue;
V_1 = V_102 ;
break;
}
F_34 () ;
if ( ! V_1 )
V_1 = F_1 ( V_9 ,
V_123 -> V_32 ,
V_123 ,
V_123 ,
V_13 -> V_6 ) ;
if ( ! V_1 )
goto V_7;
if ( V_4 == V_123 )
V_1 -> V_115 = V_40 ;
V_4 -> V_115 = V_40 ;
F_4 ( & V_4 -> V_118 ) ;
V_125 = V_123 -> V_119 [ V_9 -> V_120 ] ;
V_126 = V_1 -> V_130 ;
F_6 ( & V_4 -> V_118 ) ;
V_124 = ( V_125 > V_126 ?
V_126 : V_125 ) ;
if ( ( V_124 < V_131 ) ||
( V_126 < V_132 ) )
V_127 = 0 ;
else
V_127 = ( V_29 * V_124 ) / V_126 ;
V_128 = V_29 - ( V_29 *
( V_133 - V_126 ) *
( V_133 - V_126 ) *
( V_133 - V_126 ) ) /
( V_133 *
V_133 *
V_133 ) ;
V_13 -> V_28 = ( ( V_13 -> V_28 * V_127
* V_128 ) /
( V_29 * V_29 ) ) ;
F_25 ( V_58 , V_39 ,
L_15 ,
V_4 -> V_32 , V_123 -> V_32 , V_124 ,
V_126 , V_127 , V_128 , V_13 -> V_28 ) ;
if ( V_13 -> V_28 >= V_134 )
V_129 = 1 ;
V_7:
if ( V_1 )
F_61 ( V_1 ) ;
return V_129 ;
}
static int F_73 ( const struct V_85 * V_85 ,
const struct V_13
* V_13 ,
const struct V_2 * V_9 )
{
struct V_39 * V_39 = F_24 ( V_9 -> V_47 ) ;
struct V_4 * V_4 ;
struct V_1 * V_102 ;
struct V_83 * V_105 ;
int V_101 = 0 ;
T_4 V_135 ;
int V_136 = 0 ;
int V_137 , V_129 = - 1 ;
V_4 = F_64 ( V_39 , V_13 -> V_32 ) ;
if ( ! V_4 )
return 0 ;
F_4 ( & V_4 -> V_118 ) ;
V_135 = V_13 -> V_6 - V_4 -> V_138 ;
if ( ! F_74 ( & V_4 -> V_12 ) &&
F_75 ( V_39 , V_135 ,
& V_4 -> V_139 ) )
goto V_7;
F_32 () ;
F_59 (tmp_neigh_node, node,
&orig_node->neigh_list, list) {
V_101 |= F_76 ( V_102 -> V_140 ,
V_4 -> V_138 ,
V_13 -> V_6 ) ;
if ( F_60 ( V_102 -> V_108 , V_85 -> V_89 ) &&
( V_102 -> V_9 == V_9 ) )
V_137 = 1 ;
else
V_137 = 0 ;
V_136 |= F_77 ( V_39 ,
V_102 -> V_140 ,
V_135 , V_137 ) ;
V_102 -> V_130 =
F_78 ( V_102 -> V_140 ,
V_133 ) ;
}
F_34 () ;
if ( V_136 ) {
F_25 ( V_58 , V_39 ,
L_16 ,
V_4 -> V_138 , V_13 -> V_6 ) ;
V_4 -> V_138 = V_13 -> V_6 ;
}
V_129 = V_101 ;
V_7:
F_6 ( & V_4 -> V_118 ) ;
F_65 ( V_4 ) ;
return V_129 ;
}
static void F_79 ( const struct V_85 * V_85 ,
struct V_13 * V_13 ,
const unsigned char * V_100 ,
struct V_2 * V_9 )
{
struct V_39 * V_39 = F_24 ( V_9 -> V_47 ) ;
struct V_2 * V_2 ;
struct V_4 * V_123 , * V_4 ;
struct V_1 * V_103 = NULL , * V_141 = NULL ;
struct V_1 * V_142 = NULL ;
int V_143 ;
int V_144 = 0 , V_145 = 0 , V_146 = 0 ;
int V_147 = 0 , V_148 ;
bool V_86 = false ;
bool V_87 = false ;
int V_101 ;
T_2 V_149 ;
if ( V_13 -> V_20 . V_21 != V_22 )
return;
V_149 = F_17 ( & V_9 -> V_6 ) ;
V_143 = ( V_13 -> V_26 & V_56 ? 1 : 0 ) ;
if ( F_60 ( V_85 -> V_89 , V_13 -> V_32 ) )
V_86 = true ;
F_25 ( V_58 , V_39 ,
L_17 ,
V_85 -> V_89 , V_9 -> V_33 -> V_59 ,
V_9 -> V_33 -> V_34 , V_13 -> V_32 ,
V_13 -> V_36 , V_13 -> V_6 ,
V_13 -> V_31 , V_13 -> V_90 ,
V_13 -> V_30 , V_13 -> V_28 ,
V_13 -> V_20 . V_25 ,
V_13 -> V_20 . V_23 , V_143 ) ;
F_32 () ;
F_33 (hard_iface, &hardif_list, list) {
if ( V_2 -> V_52 != V_53 )
continue;
if ( V_2 -> V_47 != V_9 -> V_47 )
continue;
if ( F_60 ( V_85 -> V_89 ,
V_2 -> V_33 -> V_34 ) )
V_144 = 1 ;
if ( F_60 ( V_13 -> V_32 ,
V_2 -> V_33 -> V_34 ) )
V_145 = 1 ;
if ( F_60 ( V_13 -> V_36 ,
V_2 -> V_33 -> V_34 ) )
V_146 = 1 ;
if ( F_80 ( V_85 -> V_89 ) )
V_147 = 1 ;
}
F_34 () ;
if ( V_13 -> V_20 . V_23 != V_24 ) {
F_25 ( V_58 , V_39 ,
L_18 ,
V_13 -> V_20 . V_23 ) ;
return;
}
if ( V_144 ) {
F_25 ( V_58 , V_39 ,
L_19 ,
V_85 -> V_89 ) ;
return;
}
if ( V_147 ) {
F_25 ( V_58 , V_39 ,
L_20 ,
V_85 -> V_89 ) ;
return;
}
if ( V_145 ) {
unsigned long * V_150 ;
int V_151 ;
V_123 = F_64 ( V_39 , V_85 -> V_89 ) ;
if ( ! V_123 )
return;
if ( V_143 &&
F_60 ( V_9 -> V_33 -> V_34 ,
V_13 -> V_32 ) ) {
V_151 = V_9 -> V_120 * V_152 ;
F_4 ( & V_123 -> V_118 ) ;
V_150 = & ( V_123 -> V_153 [ V_151 ] ) ;
F_81 ( V_150 ,
V_149 -
V_13 -> V_6 - 2 ) ;
V_123 -> V_119 [ V_9 -> V_120 ] =
F_78 ( V_150 , V_133 ) ;
F_6 ( & V_123 -> V_118 ) ;
}
F_25 ( V_58 , V_39 ,
L_21 ) ;
F_65 ( V_123 ) ;
return;
}
if ( V_146 ) {
F_25 ( V_58 , V_39 ,
L_22 ,
V_85 -> V_89 ) ;
return;
}
if ( V_13 -> V_26 & V_88 ) {
F_25 ( V_58 , V_39 ,
L_23 ,
V_85 -> V_89 ) ;
return;
}
V_4 = F_64 ( V_39 , V_13 -> V_32 ) ;
if ( ! V_4 )
return;
V_101 = F_73 ( V_85 , V_13 ,
V_9 ) ;
if ( V_101 == - 1 ) {
F_25 ( V_58 , V_39 ,
L_24 ,
V_85 -> V_89 ) ;
goto V_7;
}
if ( V_13 -> V_28 == 0 ) {
F_25 ( V_58 , V_39 ,
L_25 ) ;
goto V_7;
}
V_103 = F_67 ( V_4 ) ;
if ( V_103 )
V_141 = F_67 ( V_103 -> V_4 ) ;
if ( ( V_103 && V_103 -> V_112 != 0 ) &&
( F_60 ( V_103 -> V_108 , V_85 -> V_89 ) ) )
V_87 = true ;
if ( V_103 && V_141 &&
( F_60 ( V_103 -> V_108 , V_13 -> V_36 ) ) &&
! ( F_60 ( V_13 -> V_32 ,
V_13 -> V_36 ) ) &&
( F_60 ( V_103 -> V_108 , V_141 -> V_108 ) ) ) {
F_25 ( V_58 , V_39 ,
L_26 ,
V_85 -> V_89 ) ;
goto V_7;
}
V_123 = ( V_86 ?
V_4 :
F_64 ( V_39 , V_85 -> V_89 ) ) ;
if ( ! V_123 )
goto V_7;
V_142 = F_67 ( V_123 ) ;
if ( ! V_86 && ( ! V_142 ) ) {
F_25 ( V_58 , V_39 ,
L_27 ) ;
goto V_154;
}
V_148 = F_72 ( V_4 , V_123 ,
V_13 , V_9 ) ;
F_82 ( V_4 , V_123 , V_13 ) ;
if ( V_148 &&
( ! V_101 ||
( ( V_4 -> V_138 == V_13 -> V_6 ) &&
( V_4 -> V_116 - 3 <= V_13 -> V_20 . V_25 ) ) ) )
F_58 ( V_39 , V_4 , V_85 ,
V_13 , V_9 ,
V_100 , V_101 ) ;
if ( V_86 ) {
F_53 ( V_4 , V_85 , V_13 ,
V_86 , V_87 ,
V_9 ) ;
F_25 ( V_58 , V_39 ,
L_28 ) ;
goto V_154;
}
if ( ! V_148 ) {
F_25 ( V_58 , V_39 ,
L_29 ) ;
goto V_154;
}
if ( V_101 ) {
F_25 ( V_58 , V_39 ,
L_30 ) ;
goto V_154;
}
F_25 ( V_58 , V_39 ,
L_31 ) ;
F_53 ( V_4 , V_85 , V_13 ,
V_86 , V_87 ,
V_9 ) ;
V_154:
if ( ( V_123 ) && ( ! V_86 ) )
F_65 ( V_123 ) ;
V_7:
if ( V_103 )
F_61 ( V_103 ) ;
if ( V_141 )
F_61 ( V_141 ) ;
if ( V_142 )
F_61 ( V_142 ) ;
F_65 ( V_4 ) ;
}
static int F_83 ( struct V_50 * V_51 ,
struct V_2 * V_9 )
{
struct V_39 * V_39 = F_24 ( V_9 -> V_47 ) ;
struct V_13 * V_13 ;
struct V_85 * V_85 ;
int V_43 = 0 , V_16 ;
unsigned char * V_100 , * V_18 ;
bool V_129 ;
V_129 = F_84 ( V_51 , V_9 , V_17 ) ;
if ( ! V_129 )
return V_155 ;
if ( V_39 -> V_156 -> V_157 != F_29 )
return V_155 ;
V_16 = F_85 ( V_51 ) ;
V_85 = (struct V_85 * ) F_86 ( V_51 ) ;
V_18 = V_51 -> V_54 ;
V_13 = (struct V_13 * ) V_18 ;
do {
V_13 -> V_6 = F_26 ( V_13 -> V_6 ) ;
V_13 -> V_90 = F_87 ( V_13 -> V_90 ) ;
V_100 = V_18 + V_43 + V_17 ;
F_79 ( V_85 , V_13 ,
V_100 , V_9 ) ;
V_43 += V_17 +
F_22 ( V_13 -> V_30 ) ;
V_13 = (struct V_13 * )
( V_18 + V_43 ) ;
} while ( F_21 ( V_43 , V_16 ,
V_13 -> V_30 ) );
F_88 ( V_51 ) ;
return V_158 ;
}
int T_5 F_89 ( void )
{
int V_129 ;
V_129 = F_90 ( V_22 , F_83 ) ;
if ( V_129 < 0 )
goto V_7;
V_129 = F_91 ( & V_159 ) ;
if ( V_129 < 0 )
goto V_160;
goto V_7;
V_160:
F_92 ( V_22 ) ;
V_7:
return V_129 ;
}

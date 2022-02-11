static struct V_1 *
F_1 ( struct V_2 * V_3 ,
const T_1 * V_4 ,
struct V_5 * V_6 ,
struct V_5 * V_7 , T_2 V_8 )
{
struct V_1 * V_9 ;
V_9 = F_2 ( V_3 , V_4 ,
F_3 ( V_8 ) ) ;
if ( ! V_9 )
goto V_10;
F_4 ( & V_9 -> V_11 ) ;
V_9 -> V_6 = V_7 ;
V_9 -> V_12 = V_3 ;
F_5 ( & V_6 -> V_13 ) ;
F_6 ( & V_9 -> V_14 , & V_6 -> V_15 ) ;
F_7 ( & V_6 -> V_13 ) ;
V_10:
return V_9 ;
}
static int F_8 ( struct V_2 * V_3 )
{
struct V_16 * V_16 ;
T_3 V_17 ;
int V_18 = - V_19 ;
F_9 ( & V_17 , sizeof( V_17 ) ) ;
F_10 ( & V_3 -> V_8 , V_17 ) ;
V_3 -> V_20 = V_21 ;
V_3 -> V_22 = F_11 ( V_3 -> V_20 , V_23 ) ;
if ( ! V_3 -> V_22 )
goto V_10;
V_16 = (struct V_16 * ) V_3 -> V_22 ;
V_16 -> V_24 . V_25 = V_26 ;
V_16 -> V_24 . V_27 = V_28 ;
V_16 -> V_24 . V_29 = 2 ;
V_16 -> V_30 = V_31 ;
V_16 -> V_32 = V_33 ;
V_16 -> V_34 = 0 ;
V_16 -> V_35 = 0 ;
V_18 = 0 ;
V_10:
return V_18 ;
}
static void F_12 ( struct V_2 * V_3 )
{
F_13 ( V_3 -> V_22 ) ;
V_3 -> V_22 = NULL ;
}
static void F_14 ( struct V_2 * V_3 )
{
struct V_16 * V_16 ;
V_16 = (struct V_16 * ) V_3 -> V_22 ;
memcpy ( V_16 -> V_36 ,
V_3 -> V_37 -> V_38 , V_39 ) ;
memcpy ( V_16 -> V_40 ,
V_3 -> V_37 -> V_38 , V_39 ) ;
}
static void
F_15 ( struct V_2 * V_3 )
{
struct V_16 * V_16 ;
V_16 = (struct V_16 * ) V_3 -> V_22 ;
V_16 -> V_30 = V_41 ;
V_16 -> V_24 . V_29 = V_42 ;
}
static unsigned long
F_16 ( const struct V_43 * V_44 )
{
unsigned int V_45 ;
V_45 = F_17 ( & V_44 -> V_46 ) - V_47 ;
V_45 += ( F_18 () % 2 * V_47 ) ;
return V_48 + F_19 ( V_45 ) ;
}
static unsigned long F_20 ( void )
{
return V_48 + F_19 ( F_18 () % ( V_47 / 2 ) ) ;
}
static T_1 F_21 ( T_1 V_32 ,
const struct V_43 * V_44 )
{
int V_49 = F_17 ( & V_44 -> V_49 ) ;
int V_50 ;
V_50 = V_32 * ( V_33 - V_49 ) ;
V_50 /= V_33 ;
return V_50 ;
}
static int F_22 ( int V_51 , int V_20 ,
int V_34 )
{
int V_52 = 0 ;
V_52 += V_51 + V_21 ;
V_52 += F_23 ( V_34 ) ;
return ( V_52 <= V_20 ) &&
( V_52 <= V_53 ) ;
}
static void F_24 ( struct V_54 * V_55 ,
struct V_2 * V_3 )
{
struct V_43 * V_44 = F_25 ( V_3 -> V_56 ) ;
char * V_57 ;
T_1 V_58 ;
T_4 V_51 ;
struct V_16 * V_16 ;
struct V_59 * V_60 ;
if ( V_3 -> V_61 != V_62 )
return;
V_58 = 0 ;
V_51 = 0 ;
V_16 = (struct V_16 * ) V_55 -> V_60 -> V_63 ;
while ( F_22 ( V_51 , V_55 -> V_20 ,
V_16 -> V_34 ) ) {
if ( ( V_55 -> V_64 & ( 1 << V_58 ) ) &&
( V_55 -> V_12 == V_3 ) )
V_16 -> V_30 |= V_65 ;
else
V_16 -> V_30 &= ~ V_65 ;
V_57 = ( V_58 > 0 ? L_1 : ( V_55 -> V_66 ?
L_2 :
L_1 ) ) ;
F_26 ( V_67 , V_44 ,
L_3 ,
V_57 , ( V_58 > 0 ? L_4 : L_5 ) ,
V_16 -> V_36 ,
F_3 ( V_16 -> V_8 ) ,
V_16 -> V_32 , V_16 -> V_24 . V_29 ,
( V_16 -> V_30 & V_65 ?
L_6 : L_7 ) ,
V_16 -> V_35 , V_3 -> V_37 -> V_68 ,
V_3 -> V_37 -> V_38 ) ;
V_51 += V_21 ;
V_51 += F_23 ( V_16 -> V_34 ) ;
V_58 ++ ;
V_16 = (struct V_16 * )
( V_55 -> V_60 -> V_63 + V_51 ) ;
}
V_60 = F_27 ( V_55 -> V_60 , V_23 ) ;
if ( V_60 ) {
F_28 ( V_44 , V_69 ) ;
F_29 ( V_44 , V_70 ,
V_60 -> V_71 + V_72 ) ;
F_30 ( V_60 , V_3 , V_73 ) ;
}
}
static void F_31 ( struct V_54 * V_55 )
{
struct V_2 * V_3 ;
struct V_74 * V_56 ;
struct V_43 * V_44 ;
struct V_2 * V_75 = NULL ;
struct V_16 * V_16 ;
unsigned char V_76 ;
V_16 = (struct V_16 * )
( V_55 -> V_60 -> V_63 ) ;
V_76 = ( V_16 -> V_30 & V_65 ? 1 : 0 ) ;
if ( ! V_55 -> V_12 ) {
F_32 ( L_8 ) ;
goto V_10;
}
V_56 = V_55 -> V_12 -> V_56 ;
V_44 = F_25 ( V_56 ) ;
if ( V_55 -> V_12 -> V_61 != V_62 )
goto V_10;
V_75 = F_33 ( V_44 ) ;
if ( ! V_75 )
goto V_10;
if ( ( V_76 && ( V_16 -> V_24 . V_29 == 1 ) ) ||
( V_55 -> V_66 && ( V_55 -> V_12 != V_75 ) ) ) {
F_26 ( V_67 , V_44 ,
L_9 ,
( V_55 -> V_66 ? L_2 : L_1 ) ,
V_16 -> V_36 ,
F_3 ( V_16 -> V_8 ) ,
V_16 -> V_24 . V_29 ,
V_55 -> V_12 -> V_37 -> V_68 ,
V_55 -> V_12 -> V_37 -> V_38 ) ;
F_30 ( V_55 -> V_60 ,
V_55 -> V_12 ,
V_73 ) ;
V_55 -> V_60 = NULL ;
goto V_10;
}
F_34 () ;
F_35 (hard_iface, &batadv_hardif_list, list) {
if ( V_3 -> V_56 != V_56 )
continue;
F_24 ( V_55 , V_3 ) ;
}
F_36 () ;
V_10:
if ( V_75 )
F_37 ( V_75 ) ;
}
static bool
F_38 ( const struct V_16 * V_77 ,
struct V_43 * V_44 ,
int V_20 , unsigned long V_78 ,
bool V_76 ,
const struct V_2 * V_12 ,
const struct V_54 * V_55 )
{
struct V_16 * V_16 ;
int V_79 = V_55 -> V_20 + V_20 ;
struct V_2 * V_75 = NULL ;
bool V_18 = false ;
unsigned long V_80 ;
V_16 = (struct V_16 * ) V_55 -> V_60 -> V_63 ;
V_80 = V_78 ;
V_80 += F_19 ( V_81 ) ;
if ( F_39 ( V_78 , V_55 -> V_78 ) &&
F_40 ( V_80 , V_55 -> V_78 ) &&
( V_79 <= V_53 ) ) {
V_75 = F_33 ( V_44 ) ;
if ( ! V_75 )
goto V_10;
if ( ( ! V_76 ) &&
( ! ( V_16 -> V_30 & V_65 ) ) &&
( V_16 -> V_24 . V_29 != 1 ) &&
( ( ! V_55 -> V_66 ) ||
( V_55 -> V_12 == V_75 ) ) ) {
V_18 = true ;
goto V_10;
}
if ( ( V_76 ) &&
( V_77 -> V_24 . V_29 == 1 ) &&
( V_55 -> V_12 == V_12 ) &&
( V_16 -> V_30 & V_65 ||
( V_55 -> V_66 &&
V_55 -> V_12 != V_75 ) ) ) {
V_18 = true ;
goto V_10;
}
}
V_10:
if ( V_75 )
F_37 ( V_75 ) ;
return V_18 ;
}
static void F_41 ( const unsigned char * V_22 ,
int V_20 , unsigned long V_78 ,
bool V_82 ,
struct V_2 * V_12 ,
int V_83 )
{
struct V_43 * V_44 = F_25 ( V_12 -> V_56 ) ;
struct V_54 * V_84 ;
unsigned char * V_85 ;
unsigned int V_86 ;
if ( ! F_42 ( & V_12 -> V_87 ) )
return;
if ( ! V_83 ) {
if ( ! F_43 ( & V_44 -> V_88 ) ) {
F_26 ( V_67 , V_44 ,
L_10 ) ;
goto V_10;
}
}
V_84 = F_11 ( sizeof( * V_84 ) , V_23 ) ;
if ( ! V_84 ) {
if ( ! V_83 )
F_44 ( & V_44 -> V_88 ) ;
goto V_10;
}
if ( ( F_17 ( & V_44 -> V_89 ) ) &&
( V_20 < V_53 ) )
V_86 = V_53 + V_72 ;
else
V_86 = V_20 + V_72 ;
V_84 -> V_60 = F_45 ( V_86 ) ;
if ( ! V_84 -> V_60 ) {
if ( ! V_83 )
F_44 ( & V_44 -> V_88 ) ;
F_13 ( V_84 ) ;
goto V_10;
}
F_46 ( V_84 -> V_60 , V_72 ) ;
F_47 ( & V_84 -> V_14 ) ;
V_85 = F_48 ( V_84 -> V_60 , V_20 ) ;
V_84 -> V_20 = V_20 ;
memcpy ( V_85 , V_22 , V_20 ) ;
V_84 -> V_66 = V_83 ;
V_84 -> V_12 = V_12 ;
V_84 -> V_90 = 0 ;
V_84 -> V_64 = V_31 ;
V_84 -> V_78 = V_78 ;
if ( V_82 )
V_84 -> V_64 |= 1 ;
F_5 ( & V_44 -> V_91 ) ;
F_49 ( & V_84 -> V_14 , & V_44 -> V_92 ) ;
F_7 ( & V_44 -> V_91 ) ;
F_50 ( & V_84 -> V_93 ,
V_94 ) ;
F_51 ( V_95 ,
& V_84 -> V_93 ,
V_78 - V_48 ) ;
return;
V_10:
F_37 ( V_12 ) ;
}
static void F_52 ( struct V_54 * V_84 ,
const unsigned char * V_22 ,
int V_20 , bool V_82 )
{
unsigned char * V_85 ;
V_85 = F_48 ( V_84 -> V_60 , V_20 ) ;
memcpy ( V_85 , V_22 , V_20 ) ;
V_84 -> V_20 += V_20 ;
V_84 -> V_90 ++ ;
if ( V_82 )
V_84 -> V_64 |=
( 1 << V_84 -> V_90 ) ;
}
static void F_53 ( struct V_43 * V_44 ,
unsigned char * V_22 ,
int V_20 ,
struct V_2 * V_12 ,
int V_83 , unsigned long V_78 )
{
struct V_54 * V_84 = NULL ;
struct V_54 * V_96 = NULL ;
struct V_97 * V_98 ;
struct V_16 * V_16 ;
bool V_82 ;
unsigned long V_99 ;
V_16 = (struct V_16 * ) V_22 ;
V_82 = V_16 -> V_30 & V_65 ? 1 : 0 ;
V_99 = F_19 ( V_81 ) ;
F_5 ( & V_44 -> V_91 ) ;
if ( ( F_17 ( & V_44 -> V_89 ) ) && ( ! V_83 ) ) {
F_54 (forw_packet_pos, tmp_node,
&bat_priv->forw_bat_list, list) {
if ( F_38 ( V_16 ,
V_44 , V_20 ,
V_78 , V_82 ,
V_12 ,
V_96 ) ) {
V_84 = V_96 ;
break;
}
}
}
if ( ! V_84 ) {
F_7 ( & V_44 -> V_91 ) ;
if ( ! V_83 && F_17 ( & V_44 -> V_89 ) )
V_78 += V_99 ;
F_41 ( V_22 , V_20 ,
V_78 , V_82 ,
V_12 , V_83 ) ;
} else {
F_52 ( V_84 , V_22 ,
V_20 , V_82 ) ;
F_7 ( & V_44 -> V_91 ) ;
}
}
static void F_55 ( struct V_5 * V_6 ,
const struct V_100 * V_100 ,
struct V_16 * V_16 ,
bool V_101 ,
bool V_102 ,
struct V_2 * V_12 )
{
struct V_43 * V_44 = F_25 ( V_12 -> V_56 ) ;
T_1 V_34 ;
if ( V_16 -> V_24 . V_29 <= 1 ) {
F_26 ( V_67 , V_44 , L_11 ) ;
return;
}
if ( ! V_102 ) {
if ( V_101 )
V_16 -> V_30 |= V_103 ;
else
return;
}
V_34 = V_16 -> V_34 ;
V_16 -> V_24 . V_29 -- ;
memcpy ( V_16 -> V_40 , V_100 -> V_104 , V_39 ) ;
V_16 -> V_32 = F_21 ( V_16 -> V_32 ,
V_44 ) ;
F_26 ( V_67 , V_44 ,
L_12 ,
V_16 -> V_32 , V_16 -> V_24 . V_29 ) ;
V_16 -> V_30 &= ~ V_41 ;
if ( V_101 )
V_16 -> V_30 |= V_65 ;
else
V_16 -> V_30 &= ~ V_65 ;
F_53 ( V_44 , ( unsigned char * ) V_16 ,
V_21 + F_23 ( V_34 ) ,
V_12 , 0 , F_20 () ) ;
}
static void F_56 ( struct V_2 * V_3 )
{
struct V_43 * V_44 = F_25 ( V_3 -> V_56 ) ;
struct V_16 * V_16 ;
struct V_2 * V_75 ;
int V_105 , V_34 = 0 ;
V_105 = F_17 ( & V_44 -> V_106 ) ;
V_75 = F_33 ( V_44 ) ;
if ( V_3 == V_75 )
V_34 = F_57 ( V_44 ,
& V_3 -> V_22 ,
& V_3 -> V_20 ,
V_21 ) ;
V_16 = (struct V_16 * ) V_3 -> V_22 ;
V_16 -> V_8 =
F_58 ( ( T_3 ) F_17 ( & V_3 -> V_8 ) ) ;
F_44 ( & V_3 -> V_8 ) ;
V_16 -> V_35 = F_17 ( & V_44 -> V_35 ) ;
V_16 -> V_107 = F_59 ( V_44 -> V_107 ) ;
if ( V_34 >= 0 )
V_16 -> V_34 = V_34 ;
if ( V_105 == V_108 )
V_16 -> V_30 |= V_109 ;
else
V_16 -> V_30 &= ~ V_109 ;
if ( ( V_3 == V_75 ) &&
( F_17 ( & V_44 -> V_110 ) == V_111 ) )
V_16 -> V_112 =
( T_1 ) F_17 ( & V_44 -> V_113 ) ;
else
V_16 -> V_112 = V_31 ;
F_60 ( V_3 ) ;
F_53 ( V_44 , V_3 -> V_22 ,
V_3 -> V_20 , V_3 , 1 ,
F_16 ( V_44 ) ) ;
if ( V_75 )
F_37 ( V_75 ) ;
}
static void
F_61 ( struct V_43 * V_44 ,
struct V_5 * V_6 ,
const struct V_100 * V_100 ,
const struct V_16 * V_16 ,
struct V_2 * V_12 ,
const unsigned char * V_114 ,
int V_115 )
{
struct V_1 * V_9 = NULL , * V_116 = NULL ;
struct V_1 * V_117 = NULL ;
struct V_5 * V_118 ;
struct V_97 * V_119 ;
int V_120 ;
T_1 V_121 , V_122 ;
T_1 * V_4 ;
F_26 ( V_67 , V_44 ,
L_13 ) ;
F_34 () ;
F_62 (tmp_neigh_node, node,
&orig_node->neigh_list, list) {
V_4 = V_116 -> V_123 ;
if ( F_63 ( V_4 , V_100 -> V_104 ) &&
V_116 -> V_12 == V_12 &&
F_42 ( & V_116 -> V_87 ) ) {
if ( V_9 )
F_64 ( V_9 ) ;
V_9 = V_116 ;
continue;
}
if ( V_115 )
continue;
F_5 ( & V_116 -> V_124 ) ;
F_65 ( V_116 -> V_125 ,
& V_116 -> V_126 , 0 ) ;
V_116 -> V_127 =
F_66 ( V_116 -> V_125 ) ;
F_7 ( & V_116 -> V_124 ) ;
}
if ( ! V_9 ) {
struct V_5 * V_128 ;
V_128 = F_67 ( V_44 , V_100 -> V_104 ) ;
if ( ! V_128 )
goto V_129;
V_9 = F_1 ( V_12 ,
V_100 -> V_104 ,
V_6 , V_128 ,
V_16 -> V_8 ) ;
F_68 ( V_128 ) ;
if ( ! V_9 )
goto V_129;
} else
F_26 ( V_67 , V_44 ,
L_14 ) ;
F_36 () ;
V_6 -> V_30 = V_16 -> V_30 ;
V_9 -> V_130 = V_48 ;
F_5 ( & V_9 -> V_124 ) ;
F_65 ( V_9 -> V_125 ,
& V_9 -> V_126 ,
V_16 -> V_32 ) ;
V_9 -> V_127 = F_66 ( V_9 -> V_125 ) ;
F_7 ( & V_9 -> V_124 ) ;
if ( ! V_115 ) {
V_6 -> V_131 = V_16 -> V_24 . V_29 ;
V_9 -> V_131 = V_16 -> V_24 . V_29 ;
}
F_69 ( V_6 , V_9 ) ;
V_117 = F_70 ( V_6 ) ;
if ( V_117 == V_9 )
goto V_132;
if ( V_117 && ( V_117 -> V_127 > V_9 -> V_127 ) )
goto V_132;
if ( V_117 && ( V_9 -> V_127 == V_117 -> V_127 ) ) {
V_118 = V_117 -> V_6 ;
F_5 ( & V_118 -> V_133 ) ;
V_120 = V_117 -> V_12 -> V_120 ;
V_121 = V_118 -> V_134 [ V_120 ] ;
F_7 ( & V_118 -> V_133 ) ;
V_118 = V_9 -> V_6 ;
F_5 ( & V_118 -> V_133 ) ;
V_120 = V_9 -> V_12 -> V_120 ;
V_122 = V_118 -> V_134 [ V_120 ] ;
F_7 ( & V_118 -> V_133 ) ;
if ( V_121 >= V_122 )
goto V_132;
}
F_71 ( V_44 , V_6 , V_9 ) ;
V_132:
if ( ( ( V_16 -> V_36 != V_100 -> V_104 ) &&
( V_16 -> V_24 . V_29 > 2 ) ) ||
( V_16 -> V_30 & V_41 ) )
F_72 ( V_44 , V_6 , V_114 ,
V_16 -> V_34 ,
V_16 -> V_35 ,
F_73 ( V_16 -> V_107 ) ) ;
if ( V_6 -> V_112 != V_16 -> V_112 )
F_74 ( V_44 , V_6 ,
V_16 -> V_112 ) ;
V_6 -> V_112 = V_16 -> V_112 ;
if ( ( V_6 -> V_112 ) &&
( F_17 ( & V_44 -> V_110 ) == V_135 ) &&
( F_17 ( & V_44 -> V_136 ) > 2 ) )
F_75 ( V_44 , V_6 ) ;
goto V_10;
V_129:
F_36 () ;
V_10:
if ( V_9 )
F_64 ( V_9 ) ;
if ( V_117 )
F_64 ( V_117 ) ;
}
static int F_76 ( struct V_5 * V_6 ,
struct V_5 * V_137 ,
struct V_16 * V_16 ,
struct V_2 * V_12 )
{
struct V_43 * V_44 = F_25 ( V_12 -> V_56 ) ;
struct V_1 * V_9 = NULL , * V_116 ;
struct V_97 * V_119 ;
T_1 V_138 ;
T_1 V_139 , V_140 , V_141 , V_142 ;
unsigned int V_143 , V_144 ;
int V_145 , V_146 , V_147 = 0 ;
unsigned int V_148 ;
F_34 () ;
F_62 (tmp_neigh_node, node,
&orig_neigh_node->neigh_list, list) {
if ( ! F_63 ( V_116 -> V_123 ,
V_137 -> V_36 ) )
continue;
if ( V_116 -> V_12 != V_12 )
continue;
if ( ! F_42 ( & V_116 -> V_87 ) )
continue;
V_9 = V_116 ;
break;
}
F_36 () ;
if ( ! V_9 )
V_9 = F_1 ( V_12 ,
V_137 -> V_36 ,
V_137 ,
V_137 ,
V_16 -> V_8 ) ;
if ( ! V_9 )
goto V_10;
if ( V_6 == V_137 )
V_9 -> V_130 = V_48 ;
V_6 -> V_130 = V_48 ;
F_5 ( & V_6 -> V_133 ) ;
V_139 = V_137 -> V_134 [ V_12 -> V_120 ] ;
V_140 = V_9 -> V_149 ;
F_7 ( & V_6 -> V_133 ) ;
V_138 = ( V_139 > V_140 ?
V_140 : V_139 ) ;
if ( V_138 < V_150 ||
V_140 < V_151 )
V_142 = 0 ;
else
V_142 = ( V_33 * V_138 ) / V_140 ;
V_141 = V_152 - V_140 ;
V_143 = V_141 * V_141 * V_141 ;
V_144 = V_152 *
V_152 *
V_152 ;
V_146 = V_33 * V_143 ;
V_146 /= V_144 ;
V_145 = V_33 - V_146 ;
V_148 = V_16 -> V_32 * V_142 * V_145 ;
V_148 /= V_33 * V_33 ;
V_16 -> V_32 = V_148 ;
F_26 ( V_67 , V_44 ,
L_15 ,
V_6 -> V_36 , V_137 -> V_36 , V_138 ,
V_140 , V_142 ,
V_145 , V_16 -> V_32 ) ;
if ( V_16 -> V_32 >= V_153 )
V_147 = 1 ;
V_10:
if ( V_9 )
F_64 ( V_9 ) ;
return V_147 ;
}
static int
F_77 ( const struct V_100 * V_100 ,
const struct V_16 * V_16 ,
const struct V_2 * V_12 )
{
struct V_43 * V_44 = F_25 ( V_12 -> V_56 ) ;
struct V_5 * V_6 ;
struct V_1 * V_116 ;
struct V_97 * V_119 ;
int V_115 = 0 ;
T_5 V_154 ;
int V_155 = 0 ;
int V_156 , V_147 = - 1 ;
T_3 V_8 = F_3 ( V_16 -> V_8 ) ;
T_1 * V_4 ;
V_6 = F_67 ( V_44 , V_16 -> V_36 ) ;
if ( ! V_6 )
return 0 ;
F_5 ( & V_6 -> V_133 ) ;
V_154 = V_8 - V_6 -> V_157 ;
if ( ! F_78 ( & V_6 -> V_15 ) &&
F_79 ( V_44 , V_154 ,
& V_6 -> V_158 ) )
goto V_10;
F_34 () ;
F_62 (tmp_neigh_node, node,
&orig_node->neigh_list, list) {
V_115 |= F_80 ( V_116 -> V_159 ,
V_6 -> V_157 ,
V_8 ) ;
V_4 = V_116 -> V_123 ;
if ( F_63 ( V_4 , V_100 -> V_104 ) &&
V_116 -> V_12 == V_12 )
V_156 = 1 ;
else
V_156 = 0 ;
V_155 |= F_81 ( V_44 ,
V_116 -> V_159 ,
V_154 , V_156 ) ;
V_116 -> V_149 =
F_82 ( V_116 -> V_159 ,
V_152 ) ;
}
F_36 () ;
if ( V_155 ) {
F_26 ( V_67 , V_44 ,
L_16 ,
V_6 -> V_157 , V_8 ) ;
V_6 -> V_157 = V_8 ;
}
V_147 = V_115 ;
V_10:
F_7 ( & V_6 -> V_133 ) ;
F_68 ( V_6 ) ;
return V_147 ;
}
static void F_83 ( const struct V_100 * V_100 ,
struct V_16 * V_16 ,
const unsigned char * V_114 ,
struct V_2 * V_12 )
{
struct V_43 * V_44 = F_25 ( V_12 -> V_56 ) ;
struct V_2 * V_3 ;
struct V_5 * V_137 , * V_6 ;
struct V_1 * V_117 = NULL , * V_160 = NULL ;
struct V_1 * V_161 = NULL ;
int V_162 ;
int V_163 = 0 , V_164 = 0 , V_165 = 0 ;
int V_166 = 0 , V_167 ;
bool V_101 = false ;
bool V_102 = false ;
int V_115 , V_168 , V_169 ;
T_3 V_170 ;
T_1 * V_40 ;
if ( V_16 -> V_24 . V_25 != V_26 )
return;
V_170 = F_17 ( & V_12 -> V_8 ) ;
if ( V_16 -> V_30 & V_65 )
V_162 = 1 ;
else
V_162 = 0 ;
if ( F_63 ( V_100 -> V_104 , V_16 -> V_36 ) )
V_101 = true ;
F_26 ( V_67 , V_44 ,
L_17 ,
V_100 -> V_104 , V_12 -> V_37 -> V_68 ,
V_12 -> V_37 -> V_38 , V_16 -> V_36 ,
V_16 -> V_40 ,
F_3 ( V_16 -> V_8 ) , V_16 -> V_35 ,
F_73 ( V_16 -> V_107 ) ,
V_16 -> V_34 , V_16 -> V_32 ,
V_16 -> V_24 . V_29 ,
V_16 -> V_24 . V_27 , V_162 ) ;
F_34 () ;
F_35 (hard_iface, &batadv_hardif_list, list) {
if ( V_3 -> V_61 != V_62 )
continue;
if ( V_3 -> V_56 != V_12 -> V_56 )
continue;
if ( F_63 ( V_100 -> V_104 ,
V_3 -> V_37 -> V_38 ) )
V_163 = 1 ;
if ( F_63 ( V_16 -> V_36 ,
V_3 -> V_37 -> V_38 ) )
V_164 = 1 ;
if ( F_63 ( V_16 -> V_40 ,
V_3 -> V_37 -> V_38 ) )
V_165 = 1 ;
if ( F_84 ( V_100 -> V_104 ) )
V_166 = 1 ;
}
F_36 () ;
if ( V_16 -> V_24 . V_27 != V_28 ) {
F_26 ( V_67 , V_44 ,
L_18 ,
V_16 -> V_24 . V_27 ) ;
return;
}
if ( V_163 ) {
F_26 ( V_67 , V_44 ,
L_19 ,
V_100 -> V_104 ) ;
return;
}
if ( V_166 ) {
F_26 ( V_67 , V_44 ,
L_20 ,
V_100 -> V_104 ) ;
return;
}
if ( V_164 ) {
unsigned long * V_171 ;
int V_172 ;
T_5 V_173 ;
T_4 V_120 ;
T_1 * V_174 ;
V_137 = F_67 ( V_44 ,
V_100 -> V_104 ) ;
if ( ! V_137 )
return;
if ( V_162 &&
F_63 ( V_12 -> V_37 -> V_38 ,
V_16 -> V_36 ) ) {
V_120 = V_12 -> V_120 ;
V_172 = V_120 * V_175 ;
F_5 ( & V_137 -> V_133 ) ;
V_171 = & ( V_137 -> V_176 [ V_172 ] ) ;
V_173 = V_170 - 2 ;
V_173 -= F_3 ( V_16 -> V_8 ) ;
F_85 ( V_171 , V_173 ) ;
V_174 = & V_137 -> V_134 [ V_120 ] ;
* V_174 = F_82 ( V_171 ,
V_152 ) ;
F_7 ( & V_137 -> V_133 ) ;
}
F_26 ( V_67 , V_44 ,
L_21 ) ;
F_68 ( V_137 ) ;
return;
}
if ( V_165 ) {
F_26 ( V_67 , V_44 ,
L_22 ,
V_100 -> V_104 ) ;
return;
}
if ( V_16 -> V_30 & V_103 ) {
F_26 ( V_67 , V_44 ,
L_23 ,
V_100 -> V_104 ) ;
return;
}
V_6 = F_67 ( V_44 , V_16 -> V_36 ) ;
if ( ! V_6 )
return;
V_115 = F_77 ( V_100 , V_16 ,
V_12 ) ;
if ( V_115 == - 1 ) {
F_26 ( V_67 , V_44 ,
L_24 ,
V_100 -> V_104 ) ;
goto V_10;
}
if ( V_16 -> V_32 == 0 ) {
F_26 ( V_67 , V_44 ,
L_25 ) ;
goto V_10;
}
V_117 = F_70 ( V_6 ) ;
if ( V_117 )
V_160 = F_70 ( V_117 -> V_6 ) ;
if ( ( V_117 && V_117 -> V_127 != 0 ) &&
( F_63 ( V_117 -> V_123 , V_100 -> V_104 ) ) )
V_102 = true ;
V_40 = V_16 -> V_40 ;
if ( V_117 && V_160 &&
( F_63 ( V_117 -> V_123 , V_40 ) ) &&
! ( F_63 ( V_16 -> V_36 , V_40 ) ) &&
( F_63 ( V_117 -> V_123 , V_160 -> V_123 ) ) ) {
F_26 ( V_67 , V_44 ,
L_26 ,
V_100 -> V_104 ) ;
goto V_10;
}
V_137 = ( V_101 ?
V_6 :
F_67 ( V_44 , V_100 -> V_104 ) ) ;
if ( ! V_137 )
goto V_10;
V_161 = F_70 ( V_137 ) ;
if ( ! V_101 && ( ! V_161 ) ) {
F_26 ( V_67 , V_44 ,
L_27 ) ;
goto V_177;
}
V_167 = F_76 ( V_6 , V_137 ,
V_16 , V_12 ) ;
F_86 ( V_6 , V_137 ,
V_16 ) ;
V_168 = V_6 -> V_157 == F_3 ( V_16 -> V_8 ) ;
V_169 = V_6 -> V_131 - 3 <= V_16 -> V_24 . V_29 ;
if ( V_167 && ( ! V_115 || ( V_168 && V_169 ) ) )
F_61 ( V_44 , V_6 , V_100 ,
V_16 , V_12 ,
V_114 , V_115 ) ;
if ( V_101 ) {
F_55 ( V_6 , V_100 , V_16 ,
V_101 ,
V_102 , V_12 ) ;
F_26 ( V_67 , V_44 ,
L_28 ) ;
goto V_177;
}
if ( ! V_167 ) {
F_26 ( V_67 , V_44 ,
L_29 ) ;
goto V_177;
}
if ( V_115 ) {
F_26 ( V_67 , V_44 ,
L_30 ) ;
goto V_177;
}
F_26 ( V_67 , V_44 ,
L_31 ) ;
F_55 ( V_6 , V_100 , V_16 ,
V_101 , V_102 ,
V_12 ) ;
V_177:
if ( ( V_137 ) && ( ! V_101 ) )
F_68 ( V_137 ) ;
V_10:
if ( V_117 )
F_64 ( V_117 ) ;
if ( V_160 )
F_64 ( V_160 ) ;
if ( V_161 )
F_64 ( V_161 ) ;
F_68 ( V_6 ) ;
}
static int F_87 ( struct V_59 * V_60 ,
struct V_2 * V_12 )
{
struct V_43 * V_44 = F_25 ( V_12 -> V_56 ) ;
struct V_16 * V_16 ;
struct V_100 * V_100 ;
int V_51 = 0 , V_20 ;
unsigned char * V_114 , * V_22 ;
bool V_147 ;
V_147 = F_88 ( V_60 , V_12 , V_21 ) ;
if ( ! V_147 )
return V_178 ;
if ( V_44 -> V_179 -> V_180 != F_31 )
return V_178 ;
F_28 ( V_44 , V_181 ) ;
F_29 ( V_44 , V_182 ,
V_60 -> V_71 + V_72 ) ;
V_20 = F_89 ( V_60 ) ;
V_100 = (struct V_100 * ) F_90 ( V_60 ) ;
V_22 = V_60 -> V_63 ;
V_16 = (struct V_16 * ) V_22 ;
do {
V_114 = V_22 + V_51 + V_21 ;
F_83 ( V_100 , V_16 , V_114 ,
V_12 ) ;
V_51 += V_21 ;
V_51 += F_23 ( V_16 -> V_34 ) ;
V_16 = (struct V_16 * )
( V_22 + V_51 ) ;
} while ( F_22 ( V_51 , V_20 ,
V_16 -> V_34 ) );
F_91 ( V_60 ) ;
return V_183 ;
}
int T_6 F_92 ( void )
{
int V_147 ;
V_147 = F_93 ( V_26 ,
F_87 ) ;
if ( V_147 < 0 )
goto V_10;
V_147 = F_94 ( & V_184 ) ;
if ( V_147 < 0 )
goto V_185;
goto V_10;
V_185:
F_95 ( V_26 ) ;
V_10:
return V_147 ;
}

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
T_1 * V_61 ;
if ( V_3 -> V_62 != V_63 )
return;
V_58 = 0 ;
V_51 = 0 ;
V_61 = V_55 -> V_60 -> V_64 ;
V_16 = (struct V_16 * ) V_61 ;
while ( F_22 ( V_51 , V_55 -> V_20 ,
V_16 -> V_34 ) ) {
if ( V_55 -> V_65 & F_26 ( V_58 ) &&
V_55 -> V_12 == V_3 )
V_16 -> V_30 |= V_66 ;
else
V_16 -> V_30 &= ~ V_66 ;
if ( V_58 > 0 || ! V_55 -> V_67 )
V_57 = L_1 ;
else
V_57 = L_2 ;
F_27 ( V_68 , V_44 ,
L_3 ,
V_57 , ( V_58 > 0 ? L_4 : L_5 ) ,
V_16 -> V_36 ,
F_3 ( V_16 -> V_8 ) ,
V_16 -> V_32 , V_16 -> V_24 . V_29 ,
( V_16 -> V_30 & V_66 ?
L_6 : L_7 ) ,
V_16 -> V_35 , V_3 -> V_37 -> V_69 ,
V_3 -> V_37 -> V_38 ) ;
V_51 += V_21 ;
V_51 += F_23 ( V_16 -> V_34 ) ;
V_58 ++ ;
V_61 = V_55 -> V_60 -> V_64 + V_51 ;
V_16 = (struct V_16 * ) V_61 ;
}
V_60 = F_28 ( V_55 -> V_60 , V_23 ) ;
if ( V_60 ) {
F_29 ( V_44 , V_70 ) ;
F_30 ( V_44 , V_71 ,
V_60 -> V_72 + V_73 ) ;
F_31 ( V_60 , V_3 , V_74 ) ;
}
}
static void F_32 ( struct V_54 * V_55 )
{
struct V_2 * V_3 ;
struct V_75 * V_56 ;
struct V_43 * V_44 ;
struct V_2 * V_76 = NULL ;
struct V_16 * V_16 ;
unsigned char V_77 ;
T_1 * V_61 ;
V_61 = V_55 -> V_60 -> V_64 ;
V_16 = (struct V_16 * ) V_61 ;
V_77 = ( V_16 -> V_30 & V_66 ? 1 : 0 ) ;
if ( ! V_55 -> V_12 ) {
F_33 ( L_8 ) ;
goto V_10;
}
V_56 = V_55 -> V_12 -> V_56 ;
V_44 = F_25 ( V_56 ) ;
if ( V_55 -> V_12 -> V_62 != V_63 )
goto V_10;
V_76 = F_34 ( V_44 ) ;
if ( ! V_76 )
goto V_10;
if ( ( V_77 && ( V_16 -> V_24 . V_29 == 1 ) ) ||
( V_55 -> V_67 && ( V_55 -> V_12 != V_76 ) ) ) {
F_27 ( V_68 , V_44 ,
L_9 ,
( V_55 -> V_67 ? L_2 : L_1 ) ,
V_16 -> V_36 ,
F_3 ( V_16 -> V_8 ) ,
V_16 -> V_24 . V_29 ,
V_55 -> V_12 -> V_37 -> V_69 ,
V_55 -> V_12 -> V_37 -> V_38 ) ;
F_31 ( V_55 -> V_60 ,
V_55 -> V_12 ,
V_74 ) ;
V_55 -> V_60 = NULL ;
goto V_10;
}
F_35 () ;
F_36 (hard_iface, &batadv_hardif_list, list) {
if ( V_3 -> V_56 != V_56 )
continue;
F_24 ( V_55 , V_3 ) ;
}
F_37 () ;
V_10:
if ( V_76 )
F_38 ( V_76 ) ;
}
static bool
F_39 ( const struct V_16 * V_78 ,
struct V_43 * V_44 ,
int V_20 , unsigned long V_79 ,
bool V_77 ,
const struct V_2 * V_12 ,
const struct V_54 * V_55 )
{
struct V_16 * V_16 ;
int V_80 = V_55 -> V_20 + V_20 ;
struct V_2 * V_76 = NULL ;
bool V_18 = false ;
unsigned long V_81 ;
V_16 = (struct V_16 * ) V_55 -> V_60 -> V_64 ;
V_81 = V_79 ;
V_81 += F_19 ( V_82 ) ;
if ( F_40 ( V_79 , V_55 -> V_79 ) &&
F_41 ( V_81 , V_55 -> V_79 ) &&
( V_80 <= V_53 ) ) {
V_76 = F_34 ( V_44 ) ;
if ( ! V_76 )
goto V_10;
if ( ( ! V_77 ) &&
( ! ( V_16 -> V_30 & V_66 ) ) &&
( V_16 -> V_24 . V_29 != 1 ) &&
( ( ! V_55 -> V_67 ) ||
( V_55 -> V_12 == V_76 ) ) ) {
V_18 = true ;
goto V_10;
}
if ( ( V_77 ) &&
( V_78 -> V_24 . V_29 == 1 ) &&
( V_55 -> V_12 == V_12 ) &&
( V_16 -> V_30 & V_66 ||
( V_55 -> V_67 &&
V_55 -> V_12 != V_76 ) ) ) {
V_18 = true ;
goto V_10;
}
}
V_10:
if ( V_76 )
F_38 ( V_76 ) ;
return V_18 ;
}
static void F_42 ( const unsigned char * V_22 ,
int V_20 , unsigned long V_79 ,
bool V_83 ,
struct V_2 * V_12 ,
int V_84 )
{
struct V_43 * V_44 = F_25 ( V_12 -> V_56 ) ;
struct V_54 * V_85 ;
unsigned char * V_86 ;
unsigned int V_87 ;
if ( ! F_43 ( & V_12 -> V_88 ) )
return;
if ( ! V_84 ) {
if ( ! F_44 ( & V_44 -> V_89 ) ) {
F_27 ( V_68 , V_44 ,
L_10 ) ;
goto V_10;
}
}
V_85 = F_11 ( sizeof( * V_85 ) , V_23 ) ;
if ( ! V_85 ) {
if ( ! V_84 )
F_45 ( & V_44 -> V_89 ) ;
goto V_10;
}
if ( ( F_17 ( & V_44 -> V_90 ) ) &&
( V_20 < V_53 ) )
V_87 = V_53 + V_73 ;
else
V_87 = V_20 + V_73 ;
V_85 -> V_60 = F_46 ( V_87 ) ;
if ( ! V_85 -> V_60 ) {
if ( ! V_84 )
F_45 ( & V_44 -> V_89 ) ;
F_13 ( V_85 ) ;
goto V_10;
}
F_47 ( V_85 -> V_60 , V_73 ) ;
F_48 ( & V_85 -> V_14 ) ;
V_86 = F_49 ( V_85 -> V_60 , V_20 ) ;
V_85 -> V_20 = V_20 ;
memcpy ( V_86 , V_22 , V_20 ) ;
V_85 -> V_67 = V_84 ;
V_85 -> V_12 = V_12 ;
V_85 -> V_91 = 0 ;
V_85 -> V_65 = V_31 ;
V_85 -> V_79 = V_79 ;
if ( V_83 )
V_85 -> V_65 |= 1 ;
F_5 ( & V_44 -> V_92 ) ;
F_50 ( & V_85 -> V_14 , & V_44 -> V_93 ) ;
F_7 ( & V_44 -> V_92 ) ;
F_51 ( & V_85 -> V_94 ,
V_95 ) ;
F_52 ( V_96 ,
& V_85 -> V_94 ,
V_79 - V_48 ) ;
return;
V_10:
F_38 ( V_12 ) ;
}
static void F_53 ( struct V_54 * V_85 ,
const unsigned char * V_22 ,
int V_20 , bool V_83 )
{
unsigned char * V_86 ;
unsigned long V_97 ;
V_86 = F_49 ( V_85 -> V_60 , V_20 ) ;
memcpy ( V_86 , V_22 , V_20 ) ;
V_85 -> V_20 += V_20 ;
V_85 -> V_91 ++ ;
if ( V_83 ) {
V_97 = F_26 ( V_85 -> V_91 ) ;
V_85 -> V_65 |= V_97 ;
}
}
static void F_54 ( struct V_43 * V_44 ,
unsigned char * V_22 ,
int V_20 ,
struct V_2 * V_12 ,
int V_84 , unsigned long V_79 )
{
struct V_54 * V_85 = NULL ;
struct V_54 * V_98 = NULL ;
struct V_99 * V_100 ;
struct V_16 * V_16 ;
bool V_83 ;
unsigned long V_101 ;
V_16 = (struct V_16 * ) V_22 ;
V_83 = V_16 -> V_30 & V_66 ? 1 : 0 ;
V_101 = F_19 ( V_82 ) ;
F_5 ( & V_44 -> V_92 ) ;
if ( ( F_17 ( & V_44 -> V_90 ) ) && ( ! V_84 ) ) {
F_55 (forw_packet_pos, tmp_node,
&bat_priv->forw_bat_list, list) {
if ( F_39 ( V_16 ,
V_44 , V_20 ,
V_79 , V_83 ,
V_12 ,
V_98 ) ) {
V_85 = V_98 ;
break;
}
}
}
if ( ! V_85 ) {
F_7 ( & V_44 -> V_92 ) ;
if ( ! V_84 && F_17 ( & V_44 -> V_90 ) )
V_79 += V_101 ;
F_42 ( V_22 , V_20 ,
V_79 , V_83 ,
V_12 , V_84 ) ;
} else {
F_53 ( V_85 , V_22 ,
V_20 , V_83 ) ;
F_7 ( & V_44 -> V_92 ) ;
}
}
static void F_56 ( struct V_5 * V_6 ,
const struct V_102 * V_102 ,
struct V_16 * V_16 ,
bool V_103 ,
bool V_104 ,
struct V_2 * V_12 )
{
struct V_43 * V_44 = F_25 ( V_12 -> V_56 ) ;
T_1 V_34 ;
if ( V_16 -> V_24 . V_29 <= 1 ) {
F_27 ( V_68 , V_44 , L_11 ) ;
return;
}
if ( ! V_104 ) {
if ( V_103 )
V_16 -> V_30 |= V_105 ;
else
return;
}
V_34 = V_16 -> V_34 ;
V_16 -> V_24 . V_29 -- ;
memcpy ( V_16 -> V_40 , V_102 -> V_106 , V_39 ) ;
V_16 -> V_32 = F_21 ( V_16 -> V_32 ,
V_44 ) ;
F_27 ( V_68 , V_44 ,
L_12 ,
V_16 -> V_32 , V_16 -> V_24 . V_29 ) ;
V_16 -> V_30 &= ~ V_41 ;
if ( V_103 )
V_16 -> V_30 |= V_66 ;
else
V_16 -> V_30 &= ~ V_66 ;
F_54 ( V_44 , ( unsigned char * ) V_16 ,
V_21 + F_23 ( V_34 ) ,
V_12 , 0 , F_20 () ) ;
}
static void F_57 ( struct V_2 * V_3 )
{
struct V_43 * V_44 = F_25 ( V_3 -> V_56 ) ;
struct V_16 * V_16 ;
struct V_2 * V_76 ;
int V_107 , V_34 = 0 ;
T_3 V_8 ;
T_1 V_108 ;
V_107 = F_17 ( & V_44 -> V_109 ) ;
V_76 = F_34 ( V_44 ) ;
if ( V_3 == V_76 )
V_34 = F_58 ( V_44 ,
& V_3 -> V_22 ,
& V_3 -> V_20 ,
V_21 ) ;
V_16 = (struct V_16 * ) V_3 -> V_22 ;
V_8 = ( T_3 ) F_17 ( & V_3 -> V_8 ) ;
V_16 -> V_8 = F_59 ( V_8 ) ;
F_45 ( & V_3 -> V_8 ) ;
V_16 -> V_35 = F_17 ( & V_44 -> V_110 . V_111 ) ;
V_16 -> V_112 = F_60 ( V_44 -> V_110 . V_113 ) ;
if ( V_34 >= 0 )
V_16 -> V_34 = V_34 ;
if ( V_107 == V_114 )
V_16 -> V_30 |= V_115 ;
else
V_16 -> V_30 &= ~ V_115 ;
if ( V_3 == V_76 &&
F_17 ( & V_44 -> V_116 ) == V_117 ) {
V_108 = ( T_1 ) F_17 ( & V_44 -> V_118 ) ;
V_16 -> V_119 = V_108 ;
} else {
V_16 -> V_119 = V_31 ;
}
F_61 ( V_3 ) ;
F_54 ( V_44 , V_3 -> V_22 ,
V_3 -> V_20 , V_3 , 1 ,
F_16 ( V_44 ) ) ;
if ( V_76 )
F_38 ( V_76 ) ;
}
static void
F_62 ( struct V_43 * V_44 ,
struct V_5 * V_6 ,
const struct V_102 * V_102 ,
const struct V_16 * V_16 ,
struct V_2 * V_12 ,
const unsigned char * V_120 ,
int V_121 )
{
struct V_1 * V_9 = NULL , * V_122 = NULL ;
struct V_1 * V_123 = NULL ;
struct V_5 * V_124 ;
struct V_99 * V_125 ;
int V_126 ;
T_1 V_127 , V_128 ;
T_1 * V_4 ;
T_1 V_129 ;
F_27 ( V_68 , V_44 ,
L_13 ) ;
F_35 () ;
F_63 (tmp_neigh_node, node,
&orig_node->neigh_list, list) {
V_4 = V_122 -> V_130 ;
if ( F_64 ( V_4 , V_102 -> V_106 ) &&
V_122 -> V_12 == V_12 &&
F_43 ( & V_122 -> V_88 ) ) {
if ( V_9 )
F_65 ( V_9 ) ;
V_9 = V_122 ;
continue;
}
if ( V_121 )
continue;
F_5 ( & V_122 -> V_131 ) ;
F_66 ( V_122 -> V_132 ,
& V_122 -> V_133 , 0 ) ;
V_129 = F_67 ( V_122 -> V_132 ) ;
V_122 -> V_129 = V_129 ;
F_7 ( & V_122 -> V_131 ) ;
}
if ( ! V_9 ) {
struct V_5 * V_134 ;
V_134 = F_68 ( V_44 , V_102 -> V_106 ) ;
if ( ! V_134 )
goto V_135;
V_9 = F_1 ( V_12 ,
V_102 -> V_106 ,
V_6 , V_134 ,
V_16 -> V_8 ) ;
F_69 ( V_134 ) ;
if ( ! V_9 )
goto V_135;
} else
F_27 ( V_68 , V_44 ,
L_14 ) ;
F_37 () ;
V_6 -> V_30 = V_16 -> V_30 ;
V_9 -> V_136 = V_48 ;
F_5 ( & V_9 -> V_131 ) ;
F_66 ( V_9 -> V_132 ,
& V_9 -> V_133 ,
V_16 -> V_32 ) ;
V_9 -> V_129 = F_67 ( V_9 -> V_132 ) ;
F_7 ( & V_9 -> V_131 ) ;
if ( ! V_121 ) {
V_6 -> V_137 = V_16 -> V_24 . V_29 ;
V_9 -> V_137 = V_16 -> V_24 . V_29 ;
}
F_70 ( V_6 , V_9 ) ;
V_123 = F_71 ( V_6 ) ;
if ( V_123 == V_9 )
goto V_138;
if ( V_123 && ( V_123 -> V_129 > V_9 -> V_129 ) )
goto V_138;
if ( V_123 && ( V_9 -> V_129 == V_123 -> V_129 ) ) {
V_124 = V_123 -> V_6 ;
F_5 ( & V_124 -> V_139 ) ;
V_126 = V_123 -> V_12 -> V_126 ;
V_127 = V_124 -> V_140 [ V_126 ] ;
F_7 ( & V_124 -> V_139 ) ;
V_124 = V_9 -> V_6 ;
F_5 ( & V_124 -> V_139 ) ;
V_126 = V_9 -> V_12 -> V_126 ;
V_128 = V_124 -> V_140 [ V_126 ] ;
F_7 ( & V_124 -> V_139 ) ;
if ( V_127 >= V_128 )
goto V_138;
}
F_72 ( V_44 , V_6 , V_9 ) ;
V_138:
if ( ( ( V_16 -> V_36 != V_102 -> V_106 ) &&
( V_16 -> V_24 . V_29 > 2 ) ) ||
( V_16 -> V_30 & V_41 ) )
F_73 ( V_44 , V_6 , V_120 ,
V_16 -> V_34 ,
V_16 -> V_35 ,
F_74 ( V_16 -> V_112 ) ) ;
if ( V_6 -> V_119 != V_16 -> V_119 )
F_75 ( V_44 , V_6 ,
V_16 -> V_119 ) ;
V_6 -> V_119 = V_16 -> V_119 ;
if ( ( V_6 -> V_119 ) &&
( F_17 ( & V_44 -> V_116 ) == V_141 ) &&
( F_17 ( & V_44 -> V_142 ) > 2 ) )
F_76 ( V_44 , V_6 ) ;
goto V_10;
V_135:
F_37 () ;
V_10:
if ( V_9 )
F_65 ( V_9 ) ;
if ( V_123 )
F_65 ( V_123 ) ;
}
static int F_77 ( struct V_5 * V_6 ,
struct V_5 * V_143 ,
struct V_16 * V_16 ,
struct V_2 * V_12 )
{
struct V_43 * V_44 = F_25 ( V_12 -> V_56 ) ;
struct V_1 * V_9 = NULL , * V_122 ;
struct V_99 * V_125 ;
T_1 V_144 ;
T_1 V_145 , V_146 , V_147 , V_148 ;
unsigned int V_149 , V_150 ;
int V_151 , V_152 , V_153 = 0 ;
unsigned int V_154 ;
F_35 () ;
F_63 (tmp_neigh_node, node,
&orig_neigh_node->neigh_list, list) {
if ( ! F_64 ( V_122 -> V_130 ,
V_143 -> V_36 ) )
continue;
if ( V_122 -> V_12 != V_12 )
continue;
if ( ! F_43 ( & V_122 -> V_88 ) )
continue;
V_9 = V_122 ;
break;
}
F_37 () ;
if ( ! V_9 )
V_9 = F_1 ( V_12 ,
V_143 -> V_36 ,
V_143 ,
V_143 ,
V_16 -> V_8 ) ;
if ( ! V_9 )
goto V_10;
if ( V_6 == V_143 )
V_9 -> V_136 = V_48 ;
V_6 -> V_136 = V_48 ;
F_5 ( & V_6 -> V_139 ) ;
V_145 = V_143 -> V_140 [ V_12 -> V_126 ] ;
V_146 = V_9 -> V_155 ;
F_7 ( & V_6 -> V_139 ) ;
if ( V_145 > V_146 )
V_144 = V_146 ;
else
V_144 = V_145 ;
if ( V_144 < V_156 ||
V_146 < V_157 )
V_148 = 0 ;
else
V_148 = ( V_33 * V_144 ) / V_146 ;
V_147 = V_158 - V_146 ;
V_149 = V_147 * V_147 * V_147 ;
V_150 = V_158 *
V_158 *
V_158 ;
V_152 = V_33 * V_149 ;
V_152 /= V_150 ;
V_151 = V_33 - V_152 ;
V_154 = V_16 -> V_32 * V_148 * V_151 ;
V_154 /= V_33 * V_33 ;
V_16 -> V_32 = V_154 ;
F_27 ( V_68 , V_44 ,
L_15 ,
V_6 -> V_36 , V_143 -> V_36 , V_144 ,
V_146 , V_148 ,
V_151 , V_16 -> V_32 ) ;
if ( V_16 -> V_32 >= V_159 )
V_153 = 1 ;
V_10:
if ( V_9 )
F_65 ( V_9 ) ;
return V_153 ;
}
static int
F_78 ( const struct V_102 * V_102 ,
const struct V_16 * V_16 ,
const struct V_2 * V_12 )
{
struct V_43 * V_44 = F_25 ( V_12 -> V_56 ) ;
struct V_5 * V_6 ;
struct V_1 * V_122 ;
struct V_99 * V_125 ;
int V_121 = 0 ;
T_5 V_160 ;
int V_161 = 0 ;
int V_162 , V_153 = - 1 ;
T_3 V_8 = F_3 ( V_16 -> V_8 ) ;
T_1 * V_4 ;
T_1 V_163 ;
V_6 = F_68 ( V_44 , V_16 -> V_36 ) ;
if ( ! V_6 )
return 0 ;
F_5 ( & V_6 -> V_139 ) ;
V_160 = V_8 - V_6 -> V_164 ;
if ( ! F_79 ( & V_6 -> V_15 ) &&
F_80 ( V_44 , V_160 ,
& V_6 -> V_165 ) )
goto V_10;
F_35 () ;
F_63 (tmp_neigh_node, node,
&orig_node->neigh_list, list) {
V_121 |= F_81 ( V_122 -> V_166 ,
V_6 -> V_164 ,
V_8 ) ;
V_4 = V_122 -> V_130 ;
if ( F_64 ( V_4 , V_102 -> V_106 ) &&
V_122 -> V_12 == V_12 )
V_162 = 1 ;
else
V_162 = 0 ;
V_161 |= F_82 ( V_44 ,
V_122 -> V_166 ,
V_160 , V_162 ) ;
V_163 = F_83 ( V_122 -> V_166 ,
V_158 ) ;
V_122 -> V_155 = V_163 ;
}
F_37 () ;
if ( V_161 ) {
F_27 ( V_68 , V_44 ,
L_16 ,
V_6 -> V_164 , V_8 ) ;
V_6 -> V_164 = V_8 ;
}
V_153 = V_121 ;
V_10:
F_7 ( & V_6 -> V_139 ) ;
F_69 ( V_6 ) ;
return V_153 ;
}
static void F_84 ( const struct V_102 * V_102 ,
struct V_16 * V_16 ,
const unsigned char * V_120 ,
struct V_2 * V_12 )
{
struct V_43 * V_44 = F_25 ( V_12 -> V_56 ) ;
struct V_2 * V_3 ;
struct V_5 * V_143 , * V_6 ;
struct V_1 * V_123 = NULL , * V_167 = NULL ;
struct V_1 * V_168 = NULL ;
int V_169 ;
int V_170 = 0 , V_171 = 0 , V_172 = 0 ;
int V_173 = 0 , V_174 ;
bool V_103 = false ;
bool V_104 = false ;
int V_121 , V_175 , V_176 ;
T_3 V_177 ;
T_1 * V_40 ;
if ( V_16 -> V_24 . V_25 != V_26 )
return;
V_177 = F_17 ( & V_12 -> V_8 ) ;
if ( V_16 -> V_30 & V_66 )
V_169 = 1 ;
else
V_169 = 0 ;
if ( F_64 ( V_102 -> V_106 , V_16 -> V_36 ) )
V_103 = true ;
F_27 ( V_68 , V_44 ,
L_17 ,
V_102 -> V_106 , V_12 -> V_37 -> V_69 ,
V_12 -> V_37 -> V_38 , V_16 -> V_36 ,
V_16 -> V_40 ,
F_3 ( V_16 -> V_8 ) , V_16 -> V_35 ,
F_74 ( V_16 -> V_112 ) ,
V_16 -> V_34 , V_16 -> V_32 ,
V_16 -> V_24 . V_29 ,
V_16 -> V_24 . V_27 , V_169 ) ;
F_35 () ;
F_36 (hard_iface, &batadv_hardif_list, list) {
if ( V_3 -> V_62 != V_63 )
continue;
if ( V_3 -> V_56 != V_12 -> V_56 )
continue;
if ( F_64 ( V_102 -> V_106 ,
V_3 -> V_37 -> V_38 ) )
V_170 = 1 ;
if ( F_64 ( V_16 -> V_36 ,
V_3 -> V_37 -> V_38 ) )
V_171 = 1 ;
if ( F_64 ( V_16 -> V_40 ,
V_3 -> V_37 -> V_38 ) )
V_172 = 1 ;
if ( F_85 ( V_102 -> V_106 ) )
V_173 = 1 ;
}
F_37 () ;
if ( V_16 -> V_24 . V_27 != V_28 ) {
F_27 ( V_68 , V_44 ,
L_18 ,
V_16 -> V_24 . V_27 ) ;
return;
}
if ( V_170 ) {
F_27 ( V_68 , V_44 ,
L_19 ,
V_102 -> V_106 ) ;
return;
}
if ( V_173 ) {
F_27 ( V_68 , V_44 ,
L_20 ,
V_102 -> V_106 ) ;
return;
}
if ( V_171 ) {
unsigned long * V_178 ;
int V_179 ;
T_5 V_180 ;
T_4 V_126 ;
T_1 * V_181 ;
V_143 = F_68 ( V_44 ,
V_102 -> V_106 ) ;
if ( ! V_143 )
return;
if ( V_169 &&
F_64 ( V_12 -> V_37 -> V_38 ,
V_16 -> V_36 ) ) {
V_126 = V_12 -> V_126 ;
V_179 = V_126 * V_182 ;
F_5 ( & V_143 -> V_139 ) ;
V_178 = & ( V_143 -> V_183 [ V_179 ] ) ;
V_180 = V_177 - 2 ;
V_180 -= F_3 ( V_16 -> V_8 ) ;
F_86 ( V_178 , V_180 ) ;
V_181 = & V_143 -> V_140 [ V_126 ] ;
* V_181 = F_83 ( V_178 ,
V_158 ) ;
F_7 ( & V_143 -> V_139 ) ;
}
F_27 ( V_68 , V_44 ,
L_21 ) ;
F_69 ( V_143 ) ;
return;
}
if ( V_172 ) {
F_27 ( V_68 , V_44 ,
L_22 ,
V_102 -> V_106 ) ;
return;
}
if ( V_16 -> V_30 & V_105 ) {
F_27 ( V_68 , V_44 ,
L_23 ,
V_102 -> V_106 ) ;
return;
}
V_6 = F_68 ( V_44 , V_16 -> V_36 ) ;
if ( ! V_6 )
return;
V_121 = F_78 ( V_102 , V_16 ,
V_12 ) ;
if ( V_121 == - 1 ) {
F_27 ( V_68 , V_44 ,
L_24 ,
V_102 -> V_106 ) ;
goto V_10;
}
if ( V_16 -> V_32 == 0 ) {
F_27 ( V_68 , V_44 ,
L_25 ) ;
goto V_10;
}
V_123 = F_71 ( V_6 ) ;
if ( V_123 )
V_167 = F_71 ( V_123 -> V_6 ) ;
if ( ( V_123 && V_123 -> V_129 != 0 ) &&
( F_64 ( V_123 -> V_130 , V_102 -> V_106 ) ) )
V_104 = true ;
V_40 = V_16 -> V_40 ;
if ( V_123 && V_167 &&
( F_64 ( V_123 -> V_130 , V_40 ) ) &&
! ( F_64 ( V_16 -> V_36 , V_40 ) ) &&
( F_64 ( V_123 -> V_130 , V_167 -> V_130 ) ) ) {
F_27 ( V_68 , V_44 ,
L_26 ,
V_102 -> V_106 ) ;
goto V_10;
}
if ( V_103 )
V_143 = V_6 ;
else
V_143 = F_68 ( V_44 ,
V_102 -> V_106 ) ;
if ( ! V_143 )
goto V_10;
V_168 = F_71 ( V_143 ) ;
if ( ! V_103 && ( ! V_168 ) ) {
F_27 ( V_68 , V_44 ,
L_27 ) ;
goto V_184;
}
V_174 = F_77 ( V_6 , V_143 ,
V_16 , V_12 ) ;
F_87 ( V_6 , V_143 ,
V_16 ) ;
V_175 = V_6 -> V_164 == F_3 ( V_16 -> V_8 ) ;
V_176 = V_6 -> V_137 - 3 <= V_16 -> V_24 . V_29 ;
if ( V_174 && ( ! V_121 || ( V_175 && V_176 ) ) )
F_62 ( V_44 , V_6 , V_102 ,
V_16 , V_12 ,
V_120 , V_121 ) ;
if ( V_103 ) {
F_56 ( V_6 , V_102 , V_16 ,
V_103 ,
V_104 , V_12 ) ;
F_27 ( V_68 , V_44 ,
L_28 ) ;
goto V_184;
}
if ( ! V_174 ) {
F_27 ( V_68 , V_44 ,
L_29 ) ;
goto V_184;
}
if ( V_121 ) {
F_27 ( V_68 , V_44 ,
L_30 ) ;
goto V_184;
}
F_27 ( V_68 , V_44 ,
L_31 ) ;
F_56 ( V_6 , V_102 , V_16 ,
V_103 , V_104 ,
V_12 ) ;
V_184:
if ( ( V_143 ) && ( ! V_103 ) )
F_69 ( V_143 ) ;
V_10:
if ( V_123 )
F_65 ( V_123 ) ;
if ( V_167 )
F_65 ( V_167 ) ;
if ( V_168 )
F_65 ( V_168 ) ;
F_69 ( V_6 ) ;
}
static int F_88 ( struct V_59 * V_60 ,
struct V_2 * V_12 )
{
struct V_43 * V_44 = F_25 ( V_12 -> V_56 ) ;
struct V_16 * V_16 ;
struct V_102 * V_102 ;
int V_51 = 0 , V_20 ;
unsigned char * V_120 , * V_22 ;
bool V_153 ;
T_1 * V_61 ;
V_153 = F_89 ( V_60 , V_12 , V_21 ) ;
if ( ! V_153 )
return V_185 ;
if ( V_44 -> V_186 -> V_187 != F_32 )
return V_185 ;
F_29 ( V_44 , V_188 ) ;
F_30 ( V_44 , V_189 ,
V_60 -> V_72 + V_73 ) ;
V_20 = F_90 ( V_60 ) ;
V_102 = (struct V_102 * ) F_91 ( V_60 ) ;
V_22 = V_60 -> V_64 ;
V_16 = (struct V_16 * ) V_22 ;
do {
V_120 = V_22 + V_51 + V_21 ;
F_84 ( V_102 , V_16 , V_120 ,
V_12 ) ;
V_51 += V_21 ;
V_51 += F_23 ( V_16 -> V_34 ) ;
V_61 = V_22 + V_51 ;
V_16 = (struct V_16 * ) V_61 ;
} while ( F_22 ( V_51 , V_20 ,
V_16 -> V_34 ) );
F_92 ( V_60 ) ;
return V_190 ;
}
int T_6 F_93 ( void )
{
int V_153 ;
V_153 = F_94 ( V_26 ,
F_88 ) ;
if ( V_153 < 0 )
goto V_10;
V_153 = F_95 ( & V_191 ) ;
if ( V_153 < 0 )
goto V_192;
goto V_10;
V_192:
F_96 ( V_26 ) ;
V_10:
return V_153 ;
}

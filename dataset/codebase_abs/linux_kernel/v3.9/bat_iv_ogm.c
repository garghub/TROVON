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
unsigned char * V_17 ;
T_3 V_18 ;
int V_19 = - V_20 ;
F_9 ( & V_18 , sizeof( V_18 ) ) ;
F_10 ( & V_3 -> V_21 . V_22 , V_18 ) ;
V_3 -> V_21 . V_23 = V_24 ;
V_17 = F_11 ( V_3 -> V_21 . V_23 , V_25 ) ;
if ( ! V_17 )
goto V_10;
V_3 -> V_21 . V_17 = V_17 ;
V_16 = (struct V_16 * ) V_17 ;
V_16 -> V_26 . V_27 = V_28 ;
V_16 -> V_26 . V_29 = V_30 ;
V_16 -> V_26 . V_31 = 2 ;
V_16 -> V_32 = V_33 ;
V_16 -> V_34 = V_35 ;
V_16 -> V_36 = 0 ;
V_16 -> V_37 = 0 ;
V_19 = 0 ;
V_10:
return V_19 ;
}
static void F_12 ( struct V_2 * V_3 )
{
F_13 ( V_3 -> V_21 . V_17 ) ;
V_3 -> V_21 . V_17 = NULL ;
}
static void F_14 ( struct V_2 * V_3 )
{
struct V_16 * V_16 ;
unsigned char * V_17 = V_3 -> V_21 . V_17 ;
V_16 = (struct V_16 * ) V_17 ;
memcpy ( V_16 -> V_38 ,
V_3 -> V_39 -> V_40 , V_41 ) ;
memcpy ( V_16 -> V_42 ,
V_3 -> V_39 -> V_40 , V_41 ) ;
}
static void
F_15 ( struct V_2 * V_3 )
{
struct V_16 * V_16 ;
unsigned char * V_17 = V_3 -> V_21 . V_17 ;
V_16 = (struct V_16 * ) V_17 ;
V_16 -> V_32 = V_43 ;
V_16 -> V_26 . V_31 = V_44 ;
}
static unsigned long
F_16 ( const struct V_45 * V_46 )
{
unsigned int V_47 ;
V_47 = F_17 ( & V_46 -> V_48 ) - V_49 ;
V_47 += F_18 () % ( 2 * V_49 ) ;
return V_50 + F_19 ( V_47 ) ;
}
static unsigned long F_20 ( void )
{
return V_50 + F_19 ( F_18 () % ( V_49 / 2 ) ) ;
}
static T_1 F_21 ( T_1 V_34 ,
const struct V_45 * V_46 )
{
int V_51 = F_17 ( & V_46 -> V_51 ) ;
int V_52 ;
V_52 = V_34 * ( V_35 - V_51 ) ;
V_52 /= V_35 ;
return V_52 ;
}
static int F_22 ( int V_53 , int V_54 ,
int V_36 )
{
int V_55 = 0 ;
V_55 += V_53 + V_24 ;
V_55 += F_23 ( V_36 ) ;
return ( V_55 <= V_54 ) &&
( V_55 <= V_56 ) ;
}
static void F_24 ( struct V_57 * V_58 ,
struct V_2 * V_3 )
{
struct V_45 * V_46 = F_25 ( V_3 -> V_59 ) ;
char * V_60 ;
T_1 V_61 ;
T_4 V_53 ;
struct V_16 * V_16 ;
struct V_62 * V_63 ;
T_1 * V_64 ;
if ( V_3 -> V_65 != V_66 )
return;
V_61 = 0 ;
V_53 = 0 ;
V_64 = V_58 -> V_63 -> V_67 ;
V_16 = (struct V_16 * ) V_64 ;
while ( F_22 ( V_53 , V_58 -> V_54 ,
V_16 -> V_36 ) ) {
if ( V_58 -> V_68 & F_26 ( V_61 ) &&
V_58 -> V_12 == V_3 )
V_16 -> V_32 |= V_69 ;
else
V_16 -> V_32 &= ~ V_69 ;
if ( V_61 > 0 || ! V_58 -> V_70 )
V_60 = L_1 ;
else
V_60 = L_2 ;
F_27 ( V_71 , V_46 ,
L_3 ,
V_60 , ( V_61 > 0 ? L_4 : L_5 ) ,
V_16 -> V_38 ,
F_3 ( V_16 -> V_8 ) ,
V_16 -> V_34 , V_16 -> V_26 . V_31 ,
( V_16 -> V_32 & V_69 ?
L_6 : L_7 ) ,
V_16 -> V_37 , V_3 -> V_39 -> V_72 ,
V_3 -> V_39 -> V_40 ) ;
V_53 += V_24 ;
V_53 += F_23 ( V_16 -> V_36 ) ;
V_61 ++ ;
V_64 = V_58 -> V_63 -> V_67 + V_53 ;
V_16 = (struct V_16 * ) V_64 ;
}
V_63 = F_28 ( V_58 -> V_63 , V_25 ) ;
if ( V_63 ) {
F_29 ( V_46 , V_73 ) ;
F_30 ( V_46 , V_74 ,
V_63 -> V_75 + V_76 ) ;
F_31 ( V_63 , V_3 , V_77 ) ;
}
}
static void F_32 ( struct V_57 * V_58 )
{
struct V_2 * V_3 ;
struct V_78 * V_59 ;
struct V_45 * V_46 ;
struct V_2 * V_79 = NULL ;
struct V_16 * V_16 ;
unsigned char V_80 ;
T_1 * V_64 ;
V_64 = V_58 -> V_63 -> V_67 ;
V_16 = (struct V_16 * ) V_64 ;
V_80 = ( V_16 -> V_32 & V_69 ? 1 : 0 ) ;
if ( ! V_58 -> V_12 ) {
F_33 ( L_8 ) ;
goto V_10;
}
V_59 = V_58 -> V_12 -> V_59 ;
V_46 = F_25 ( V_59 ) ;
if ( V_58 -> V_12 -> V_65 != V_66 )
goto V_10;
V_79 = F_34 ( V_46 ) ;
if ( ! V_79 )
goto V_10;
if ( ( V_80 && ( V_16 -> V_26 . V_31 == 1 ) ) ||
( V_58 -> V_70 && ( V_58 -> V_12 != V_79 ) ) ) {
F_27 ( V_71 , V_46 ,
L_9 ,
( V_58 -> V_70 ? L_2 : L_1 ) ,
V_16 -> V_38 ,
F_3 ( V_16 -> V_8 ) ,
V_16 -> V_26 . V_31 ,
V_58 -> V_12 -> V_39 -> V_72 ,
V_58 -> V_12 -> V_39 -> V_40 ) ;
F_31 ( V_58 -> V_63 ,
V_58 -> V_12 ,
V_77 ) ;
V_58 -> V_63 = NULL ;
goto V_10;
}
F_35 () ;
F_36 (hard_iface, &batadv_hardif_list, list) {
if ( V_3 -> V_59 != V_59 )
continue;
F_24 ( V_58 , V_3 ) ;
}
F_37 () ;
V_10:
if ( V_79 )
F_38 ( V_79 ) ;
}
static bool
F_39 ( const struct V_16 * V_81 ,
struct V_45 * V_46 ,
int V_54 , unsigned long V_82 ,
bool V_80 ,
const struct V_2 * V_12 ,
const struct V_57 * V_58 )
{
struct V_16 * V_16 ;
int V_83 = V_58 -> V_54 + V_54 ;
struct V_2 * V_79 = NULL ;
bool V_19 = false ;
unsigned long V_84 ;
V_16 = (struct V_16 * ) V_58 -> V_63 -> V_67 ;
V_84 = V_82 ;
V_84 += F_19 ( V_85 ) ;
if ( F_40 ( V_82 , V_58 -> V_82 ) &&
F_41 ( V_84 , V_58 -> V_82 ) &&
( V_83 <= V_56 ) ) {
V_79 = F_34 ( V_46 ) ;
if ( ! V_79 )
goto V_10;
if ( ( ! V_80 ) &&
( ! ( V_16 -> V_32 & V_69 ) ) &&
( V_16 -> V_26 . V_31 != 1 ) &&
( ( ! V_58 -> V_70 ) ||
( V_58 -> V_12 == V_79 ) ) ) {
V_19 = true ;
goto V_10;
}
if ( ( V_80 ) &&
( V_81 -> V_26 . V_31 == 1 ) &&
( V_58 -> V_12 == V_12 ) &&
( V_16 -> V_32 & V_69 ||
( V_58 -> V_70 &&
V_58 -> V_12 != V_79 ) ) ) {
V_19 = true ;
goto V_10;
}
}
V_10:
if ( V_79 )
F_38 ( V_79 ) ;
return V_19 ;
}
static void F_42 ( const unsigned char * V_86 ,
int V_54 , unsigned long V_82 ,
bool V_87 ,
struct V_2 * V_12 ,
int V_88 )
{
struct V_45 * V_46 = F_25 ( V_12 -> V_59 ) ;
struct V_57 * V_89 ;
unsigned char * V_90 ;
unsigned int V_91 ;
if ( ! F_43 ( & V_12 -> V_92 ) )
return;
if ( ! V_88 ) {
if ( ! F_44 ( & V_46 -> V_93 ) ) {
F_27 ( V_71 , V_46 ,
L_10 ) ;
goto V_10;
}
}
V_89 = F_11 ( sizeof( * V_89 ) , V_25 ) ;
if ( ! V_89 ) {
if ( ! V_88 )
F_45 ( & V_46 -> V_93 ) ;
goto V_10;
}
if ( ( F_17 ( & V_46 -> V_94 ) ) &&
( V_54 < V_56 ) )
V_91 = V_56 ;
else
V_91 = V_54 ;
V_91 += V_76 + V_95 ;
V_89 -> V_63 = F_46 ( V_91 ) ;
if ( ! V_89 -> V_63 ) {
if ( ! V_88 )
F_45 ( & V_46 -> V_93 ) ;
F_13 ( V_89 ) ;
goto V_10;
}
F_47 ( V_89 -> V_63 , V_76 + V_95 ) ;
F_48 ( & V_89 -> V_14 ) ;
V_90 = F_49 ( V_89 -> V_63 , V_54 ) ;
V_89 -> V_54 = V_54 ;
memcpy ( V_90 , V_86 , V_54 ) ;
V_89 -> V_70 = V_88 ;
V_89 -> V_12 = V_12 ;
V_89 -> V_96 = 0 ;
V_89 -> V_68 = V_33 ;
V_89 -> V_82 = V_82 ;
if ( V_87 )
V_89 -> V_68 |= 1 ;
F_5 ( & V_46 -> V_97 ) ;
F_50 ( & V_89 -> V_14 , & V_46 -> V_98 ) ;
F_7 ( & V_46 -> V_97 ) ;
F_51 ( & V_89 -> V_99 ,
V_100 ) ;
F_52 ( V_101 ,
& V_89 -> V_99 ,
V_82 - V_50 ) ;
return;
V_10:
F_38 ( V_12 ) ;
}
static void F_53 ( struct V_57 * V_89 ,
const unsigned char * V_86 ,
int V_54 , bool V_87 )
{
unsigned char * V_90 ;
unsigned long V_102 ;
V_90 = F_49 ( V_89 -> V_63 , V_54 ) ;
memcpy ( V_90 , V_86 , V_54 ) ;
V_89 -> V_54 += V_54 ;
V_89 -> V_96 ++ ;
if ( V_87 ) {
V_102 = F_26 ( V_89 -> V_96 ) ;
V_89 -> V_68 |= V_102 ;
}
}
static void F_54 ( struct V_45 * V_46 ,
unsigned char * V_86 ,
int V_54 ,
struct V_2 * V_12 ,
int V_88 , unsigned long V_82 )
{
struct V_57 * V_89 = NULL ;
struct V_57 * V_103 = NULL ;
struct V_16 * V_16 ;
bool V_87 ;
unsigned long V_104 ;
V_16 = (struct V_16 * ) V_86 ;
V_87 = V_16 -> V_32 & V_69 ? 1 : 0 ;
V_104 = F_19 ( V_85 ) ;
F_5 ( & V_46 -> V_97 ) ;
if ( ( F_17 ( & V_46 -> V_94 ) ) && ( ! V_88 ) ) {
F_55 (forw_packet_pos,
&bat_priv->forw_bat_list, list) {
if ( F_39 ( V_16 ,
V_46 , V_54 ,
V_82 , V_87 ,
V_12 ,
V_103 ) ) {
V_89 = V_103 ;
break;
}
}
}
if ( ! V_89 ) {
F_7 ( & V_46 -> V_97 ) ;
if ( ! V_88 && F_17 ( & V_46 -> V_94 ) )
V_82 += V_104 ;
F_42 ( V_86 , V_54 ,
V_82 , V_87 ,
V_12 , V_88 ) ;
} else {
F_53 ( V_89 , V_86 ,
V_54 , V_87 ) ;
F_7 ( & V_46 -> V_97 ) ;
}
}
static void F_56 ( struct V_5 * V_6 ,
const struct V_105 * V_105 ,
struct V_16 * V_16 ,
bool V_106 ,
bool V_107 ,
struct V_2 * V_12 )
{
struct V_45 * V_46 = F_25 ( V_12 -> V_59 ) ;
T_1 V_36 ;
if ( V_16 -> V_26 . V_31 <= 1 ) {
F_27 ( V_71 , V_46 , L_11 ) ;
return;
}
if ( ! V_107 ) {
if ( V_106 )
V_16 -> V_32 |= V_108 ;
else
return;
}
V_36 = V_16 -> V_36 ;
V_16 -> V_26 . V_31 -- ;
memcpy ( V_16 -> V_42 , V_105 -> V_109 , V_41 ) ;
V_16 -> V_34 = F_21 ( V_16 -> V_34 ,
V_46 ) ;
F_27 ( V_71 , V_46 ,
L_12 ,
V_16 -> V_34 , V_16 -> V_26 . V_31 ) ;
V_16 -> V_32 &= ~ V_43 ;
if ( V_106 )
V_16 -> V_32 |= V_69 ;
else
V_16 -> V_32 &= ~ V_69 ;
F_54 ( V_46 , ( unsigned char * ) V_16 ,
V_24 + F_23 ( V_36 ) ,
V_12 , 0 , F_20 () ) ;
}
static void F_57 ( struct V_2 * V_3 )
{
struct V_45 * V_46 = F_25 ( V_3 -> V_59 ) ;
unsigned char * * V_17 = & V_3 -> V_21 . V_17 ;
struct V_16 * V_16 ;
struct V_2 * V_79 ;
int * V_23 = & V_3 -> V_21 . V_23 ;
int V_110 , V_36 = 0 ;
T_3 V_8 ;
T_1 V_111 ;
V_110 = F_17 ( & V_46 -> V_112 ) ;
V_79 = F_34 ( V_46 ) ;
if ( V_3 == V_79 )
V_36 = F_58 ( V_46 , V_17 ,
V_23 ,
V_24 ) ;
V_16 = (struct V_16 * ) ( * V_17 ) ;
V_8 = ( T_3 ) F_17 ( & V_3 -> V_21 . V_22 ) ;
V_16 -> V_8 = F_59 ( V_8 ) ;
F_45 ( & V_3 -> V_21 . V_22 ) ;
V_16 -> V_37 = F_17 ( & V_46 -> V_113 . V_114 ) ;
V_16 -> V_115 = F_60 ( V_46 -> V_113 . V_116 ) ;
if ( V_36 >= 0 )
V_16 -> V_36 = V_36 ;
if ( V_110 == V_117 )
V_16 -> V_32 |= V_118 ;
else
V_16 -> V_32 &= ~ V_118 ;
if ( V_3 == V_79 &&
F_17 ( & V_46 -> V_119 ) == V_120 ) {
V_111 = ( T_1 ) F_17 ( & V_46 -> V_121 ) ;
V_16 -> V_122 = V_111 ;
} else {
V_16 -> V_122 = V_33 ;
}
F_61 ( V_3 ) ;
F_54 ( V_46 , V_3 -> V_21 . V_17 ,
V_3 -> V_21 . V_23 , V_3 , 1 ,
F_16 ( V_46 ) ) ;
if ( V_79 )
F_38 ( V_79 ) ;
}
static void
F_62 ( struct V_45 * V_46 ,
struct V_5 * V_6 ,
const struct V_105 * V_105 ,
const struct V_16 * V_16 ,
struct V_2 * V_12 ,
const unsigned char * V_123 ,
int V_124 )
{
struct V_1 * V_9 = NULL , * V_125 = NULL ;
struct V_1 * V_126 = NULL ;
struct V_5 * V_127 ;
int V_128 ;
T_1 V_129 , V_130 ;
T_1 * V_4 ;
T_1 V_131 ;
F_27 ( V_71 , V_46 ,
L_13 ) ;
F_35 () ;
F_63 (tmp_neigh_node,
&orig_node->neigh_list, list) {
V_4 = V_125 -> V_132 ;
if ( F_64 ( V_4 , V_105 -> V_109 ) &&
V_125 -> V_12 == V_12 &&
F_43 ( & V_125 -> V_92 ) ) {
if ( V_9 )
F_65 ( V_9 ) ;
V_9 = V_125 ;
continue;
}
if ( V_124 )
continue;
F_5 ( & V_125 -> V_133 ) ;
F_66 ( V_125 -> V_134 ,
& V_125 -> V_135 , 0 ) ;
V_131 = F_67 ( V_125 -> V_134 ) ;
V_125 -> V_131 = V_131 ;
F_7 ( & V_125 -> V_133 ) ;
}
if ( ! V_9 ) {
struct V_5 * V_136 ;
V_136 = F_68 ( V_46 , V_105 -> V_109 ) ;
if ( ! V_136 )
goto V_137;
V_9 = F_1 ( V_12 ,
V_105 -> V_109 ,
V_6 , V_136 ,
V_16 -> V_8 ) ;
F_69 ( V_136 ) ;
if ( ! V_9 )
goto V_137;
} else
F_27 ( V_71 , V_46 ,
L_14 ) ;
F_37 () ;
V_6 -> V_32 = V_16 -> V_32 ;
V_9 -> V_138 = V_50 ;
F_5 ( & V_9 -> V_133 ) ;
F_66 ( V_9 -> V_134 ,
& V_9 -> V_135 ,
V_16 -> V_34 ) ;
V_9 -> V_131 = F_67 ( V_9 -> V_134 ) ;
F_7 ( & V_9 -> V_133 ) ;
if ( ! V_124 ) {
V_6 -> V_139 = V_16 -> V_26 . V_31 ;
V_9 -> V_139 = V_16 -> V_26 . V_31 ;
}
F_70 ( V_6 , V_9 ) ;
V_126 = F_71 ( V_6 ) ;
if ( V_126 == V_9 )
goto V_140;
if ( V_126 && ( V_126 -> V_131 > V_9 -> V_131 ) )
goto V_140;
if ( V_126 && ( V_9 -> V_131 == V_126 -> V_131 ) ) {
V_127 = V_126 -> V_6 ;
F_5 ( & V_127 -> V_141 ) ;
V_128 = V_126 -> V_12 -> V_128 ;
V_129 = V_127 -> V_142 [ V_128 ] ;
F_7 ( & V_127 -> V_141 ) ;
V_127 = V_9 -> V_6 ;
F_5 ( & V_127 -> V_141 ) ;
V_128 = V_9 -> V_12 -> V_128 ;
V_130 = V_127 -> V_142 [ V_128 ] ;
F_7 ( & V_127 -> V_141 ) ;
if ( V_129 >= V_130 )
goto V_140;
}
F_72 ( V_46 , V_6 , V_9 ) ;
V_140:
if ( ( ( V_16 -> V_38 != V_105 -> V_109 ) &&
( V_16 -> V_26 . V_31 > 2 ) ) ||
( V_16 -> V_32 & V_43 ) )
F_73 ( V_46 , V_6 , V_123 ,
V_16 -> V_36 ,
V_16 -> V_37 ,
F_74 ( V_16 -> V_115 ) ) ;
if ( V_6 -> V_122 != V_16 -> V_122 )
F_75 ( V_46 , V_6 ,
V_16 -> V_122 ) ;
V_6 -> V_122 = V_16 -> V_122 ;
if ( ( V_6 -> V_122 ) &&
( F_17 ( & V_46 -> V_119 ) == V_143 ) &&
( F_17 ( & V_46 -> V_144 ) > 2 ) )
F_76 ( V_46 , V_6 ) ;
goto V_10;
V_137:
F_37 () ;
V_10:
if ( V_9 )
F_65 ( V_9 ) ;
if ( V_126 )
F_65 ( V_126 ) ;
}
static int F_77 ( struct V_5 * V_6 ,
struct V_5 * V_145 ,
struct V_16 * V_16 ,
struct V_2 * V_12 )
{
struct V_45 * V_46 = F_25 ( V_12 -> V_59 ) ;
struct V_1 * V_9 = NULL , * V_125 ;
T_1 V_146 ;
T_1 V_147 , V_148 , V_149 , V_150 ;
unsigned int V_151 , V_152 ;
int V_153 , V_154 , V_155 = 0 ;
unsigned int V_156 ;
F_35 () ;
F_63 (tmp_neigh_node,
&orig_neigh_node->neigh_list, list) {
if ( ! F_64 ( V_125 -> V_132 ,
V_145 -> V_38 ) )
continue;
if ( V_125 -> V_12 != V_12 )
continue;
if ( ! F_43 ( & V_125 -> V_92 ) )
continue;
V_9 = V_125 ;
break;
}
F_37 () ;
if ( ! V_9 )
V_9 = F_1 ( V_12 ,
V_145 -> V_38 ,
V_145 ,
V_145 ,
V_16 -> V_8 ) ;
if ( ! V_9 )
goto V_10;
if ( V_6 == V_145 )
V_9 -> V_138 = V_50 ;
V_6 -> V_138 = V_50 ;
F_5 ( & V_6 -> V_141 ) ;
V_147 = V_145 -> V_142 [ V_12 -> V_128 ] ;
V_148 = V_9 -> V_157 ;
F_7 ( & V_6 -> V_141 ) ;
if ( V_147 > V_148 )
V_146 = V_148 ;
else
V_146 = V_147 ;
if ( V_146 < V_158 ||
V_148 < V_159 )
V_150 = 0 ;
else
V_150 = ( V_35 * V_146 ) / V_148 ;
V_149 = V_160 - V_148 ;
V_151 = V_149 * V_149 * V_149 ;
V_152 = V_160 *
V_160 *
V_160 ;
V_154 = V_35 * V_151 ;
V_154 /= V_152 ;
V_153 = V_35 - V_154 ;
V_156 = V_16 -> V_34 * V_150 * V_153 ;
V_156 /= V_35 * V_35 ;
V_16 -> V_34 = V_156 ;
F_27 ( V_71 , V_46 ,
L_15 ,
V_6 -> V_38 , V_145 -> V_38 , V_146 ,
V_148 , V_150 ,
V_153 , V_16 -> V_34 ) ;
if ( V_16 -> V_34 >= V_161 )
V_155 = 1 ;
V_10:
if ( V_9 )
F_65 ( V_9 ) ;
return V_155 ;
}
static int
F_78 ( const struct V_105 * V_105 ,
const struct V_16 * V_16 ,
const struct V_2 * V_12 )
{
struct V_45 * V_46 = F_25 ( V_12 -> V_59 ) ;
struct V_5 * V_6 ;
struct V_1 * V_125 ;
int V_124 = 0 ;
T_5 V_162 ;
int V_163 = 0 ;
int V_164 , V_155 = - 1 ;
T_3 V_8 = F_3 ( V_16 -> V_8 ) ;
T_1 * V_4 ;
T_1 V_165 ;
V_6 = F_68 ( V_46 , V_16 -> V_38 ) ;
if ( ! V_6 )
return 0 ;
F_5 ( & V_6 -> V_141 ) ;
V_162 = V_8 - V_6 -> V_166 ;
if ( ! F_79 ( & V_6 -> V_15 ) &&
F_80 ( V_46 , V_162 ,
& V_6 -> V_167 ) )
goto V_10;
F_35 () ;
F_63 (tmp_neigh_node,
&orig_node->neigh_list, list) {
V_124 |= F_81 ( V_125 -> V_168 ,
V_6 -> V_166 ,
V_8 ) ;
V_4 = V_125 -> V_132 ;
if ( F_64 ( V_4 , V_105 -> V_109 ) &&
V_125 -> V_12 == V_12 )
V_164 = 1 ;
else
V_164 = 0 ;
V_163 |= F_82 ( V_46 ,
V_125 -> V_168 ,
V_162 , V_164 ) ;
V_165 = F_83 ( V_125 -> V_168 ,
V_160 ) ;
V_125 -> V_157 = V_165 ;
}
F_37 () ;
if ( V_163 ) {
F_27 ( V_71 , V_46 ,
L_16 ,
V_6 -> V_166 , V_8 ) ;
V_6 -> V_166 = V_8 ;
}
V_155 = V_124 ;
V_10:
F_7 ( & V_6 -> V_141 ) ;
F_69 ( V_6 ) ;
return V_155 ;
}
static void F_84 ( const struct V_105 * V_105 ,
struct V_16 * V_16 ,
const unsigned char * V_123 ,
struct V_2 * V_12 )
{
struct V_45 * V_46 = F_25 ( V_12 -> V_59 ) ;
struct V_2 * V_3 ;
struct V_5 * V_145 , * V_6 ;
struct V_1 * V_126 = NULL , * V_169 = NULL ;
struct V_1 * V_170 = NULL ;
int V_171 ;
int V_172 = 0 , V_173 = 0 , V_174 = 0 ;
int V_175 = 0 , V_176 ;
bool V_106 = false ;
bool V_107 = false ;
int V_124 , V_177 , V_178 ;
T_3 V_179 ;
T_1 * V_42 ;
if ( V_16 -> V_26 . V_27 != V_28 )
return;
V_179 = F_17 ( & V_12 -> V_21 . V_22 ) ;
if ( V_16 -> V_32 & V_69 )
V_171 = 1 ;
else
V_171 = 0 ;
if ( F_64 ( V_105 -> V_109 , V_16 -> V_38 ) )
V_106 = true ;
F_27 ( V_71 , V_46 ,
L_17 ,
V_105 -> V_109 , V_12 -> V_39 -> V_72 ,
V_12 -> V_39 -> V_40 , V_16 -> V_38 ,
V_16 -> V_42 ,
F_3 ( V_16 -> V_8 ) , V_16 -> V_37 ,
F_74 ( V_16 -> V_115 ) ,
V_16 -> V_36 , V_16 -> V_34 ,
V_16 -> V_26 . V_31 ,
V_16 -> V_26 . V_29 , V_171 ) ;
F_35 () ;
F_36 (hard_iface, &batadv_hardif_list, list) {
if ( V_3 -> V_65 != V_66 )
continue;
if ( V_3 -> V_59 != V_12 -> V_59 )
continue;
if ( F_64 ( V_105 -> V_109 ,
V_3 -> V_39 -> V_40 ) )
V_172 = 1 ;
if ( F_64 ( V_16 -> V_38 ,
V_3 -> V_39 -> V_40 ) )
V_173 = 1 ;
if ( F_64 ( V_16 -> V_42 ,
V_3 -> V_39 -> V_40 ) )
V_174 = 1 ;
if ( F_85 ( V_105 -> V_109 ) )
V_175 = 1 ;
}
F_37 () ;
if ( V_16 -> V_26 . V_29 != V_30 ) {
F_27 ( V_71 , V_46 ,
L_18 ,
V_16 -> V_26 . V_29 ) ;
return;
}
if ( V_172 ) {
F_27 ( V_71 , V_46 ,
L_19 ,
V_105 -> V_109 ) ;
return;
}
if ( V_175 ) {
F_27 ( V_71 , V_46 ,
L_20 ,
V_105 -> V_109 ) ;
return;
}
if ( V_173 ) {
unsigned long * V_180 ;
int V_181 ;
T_5 V_182 ;
T_4 V_128 ;
T_1 * V_183 ;
V_145 = F_68 ( V_46 ,
V_105 -> V_109 ) ;
if ( ! V_145 )
return;
if ( V_171 &&
F_64 ( V_12 -> V_39 -> V_40 ,
V_16 -> V_38 ) ) {
V_128 = V_12 -> V_128 ;
V_181 = V_128 * V_184 ;
F_5 ( & V_145 -> V_141 ) ;
V_180 = & ( V_145 -> V_185 [ V_181 ] ) ;
V_182 = V_179 - 2 ;
V_182 -= F_3 ( V_16 -> V_8 ) ;
F_86 ( V_180 , V_182 ) ;
V_183 = & V_145 -> V_142 [ V_128 ] ;
* V_183 = F_83 ( V_180 ,
V_160 ) ;
F_7 ( & V_145 -> V_141 ) ;
}
F_27 ( V_71 , V_46 ,
L_21 ) ;
F_69 ( V_145 ) ;
return;
}
if ( V_174 ) {
F_27 ( V_71 , V_46 ,
L_22 ,
V_105 -> V_109 ) ;
return;
}
if ( V_16 -> V_32 & V_108 ) {
F_27 ( V_71 , V_46 ,
L_23 ,
V_105 -> V_109 ) ;
return;
}
V_6 = F_68 ( V_46 , V_16 -> V_38 ) ;
if ( ! V_6 )
return;
V_124 = F_78 ( V_105 , V_16 ,
V_12 ) ;
if ( V_124 == - 1 ) {
F_27 ( V_71 , V_46 ,
L_24 ,
V_105 -> V_109 ) ;
goto V_10;
}
if ( V_16 -> V_34 == 0 ) {
F_27 ( V_71 , V_46 ,
L_25 ) ;
goto V_10;
}
V_126 = F_71 ( V_6 ) ;
if ( V_126 )
V_169 = F_71 ( V_126 -> V_6 ) ;
if ( ( V_126 && V_126 -> V_131 != 0 ) &&
( F_64 ( V_126 -> V_132 , V_105 -> V_109 ) ) )
V_107 = true ;
V_42 = V_16 -> V_42 ;
if ( V_126 && V_169 &&
( F_64 ( V_126 -> V_132 , V_42 ) ) &&
! ( F_64 ( V_16 -> V_38 , V_42 ) ) &&
( F_64 ( V_126 -> V_132 , V_169 -> V_132 ) ) ) {
F_27 ( V_71 , V_46 ,
L_26 ,
V_105 -> V_109 ) ;
goto V_10;
}
if ( V_106 )
V_145 = V_6 ;
else
V_145 = F_68 ( V_46 ,
V_105 -> V_109 ) ;
if ( ! V_145 )
goto V_10;
V_170 = F_71 ( V_145 ) ;
if ( ! V_106 && ( ! V_170 ) ) {
F_27 ( V_71 , V_46 ,
L_27 ) ;
goto V_186;
}
V_176 = F_77 ( V_6 , V_145 ,
V_16 , V_12 ) ;
F_87 ( V_6 , V_145 ,
V_16 ) ;
V_177 = V_6 -> V_166 == F_3 ( V_16 -> V_8 ) ;
V_178 = V_6 -> V_139 - 3 <= V_16 -> V_26 . V_31 ;
if ( V_176 && ( ! V_124 || ( V_177 && V_178 ) ) )
F_62 ( V_46 , V_6 , V_105 ,
V_16 , V_12 ,
V_123 , V_124 ) ;
if ( V_106 ) {
F_56 ( V_6 , V_105 , V_16 ,
V_106 ,
V_107 , V_12 ) ;
F_27 ( V_71 , V_46 ,
L_28 ) ;
goto V_186;
}
if ( ! V_176 ) {
F_27 ( V_71 , V_46 ,
L_29 ) ;
goto V_186;
}
if ( V_124 ) {
F_27 ( V_71 , V_46 ,
L_30 ) ;
goto V_186;
}
F_27 ( V_71 , V_46 ,
L_31 ) ;
F_56 ( V_6 , V_105 , V_16 ,
V_106 , V_107 ,
V_12 ) ;
V_186:
if ( ( V_145 ) && ( ! V_106 ) )
F_69 ( V_145 ) ;
V_10:
if ( V_126 )
F_65 ( V_126 ) ;
if ( V_169 )
F_65 ( V_169 ) ;
if ( V_170 )
F_65 ( V_170 ) ;
F_69 ( V_6 ) ;
}
static int F_88 ( struct V_62 * V_63 ,
struct V_2 * V_12 )
{
struct V_45 * V_46 = F_25 ( V_12 -> V_59 ) ;
struct V_16 * V_16 ;
struct V_105 * V_105 ;
int V_53 = 0 , V_54 ;
unsigned char * V_123 , * V_86 ;
bool V_155 ;
T_1 * V_64 ;
V_155 = F_89 ( V_63 , V_12 , V_24 ) ;
if ( ! V_155 )
return V_187 ;
if ( V_46 -> V_188 -> V_189 != F_32 )
return V_187 ;
F_29 ( V_46 , V_190 ) ;
F_30 ( V_46 , V_191 ,
V_63 -> V_75 + V_76 ) ;
V_54 = F_90 ( V_63 ) ;
V_105 = (struct V_105 * ) F_91 ( V_63 ) ;
V_86 = V_63 -> V_67 ;
V_16 = (struct V_16 * ) V_86 ;
while ( F_22 ( V_53 , V_54 ,
V_16 -> V_36 ) ) {
V_123 = V_86 + V_53 + V_24 ;
F_84 ( V_105 , V_16 , V_123 ,
V_12 ) ;
V_53 += V_24 ;
V_53 += F_23 ( V_16 -> V_36 ) ;
V_64 = V_86 + V_53 ;
V_16 = (struct V_16 * ) V_64 ;
}
F_92 ( V_63 ) ;
return V_192 ;
}
int T_6 F_93 ( void )
{
int V_155 ;
V_155 = F_94 ( V_28 ,
F_88 ) ;
if ( V_155 < 0 )
goto V_10;
V_155 = F_95 ( & V_193 ) ;
if ( V_155 < 0 )
goto V_194;
goto V_10;
V_194:
F_96 ( V_28 ) ;
V_10:
return V_155 ;
}

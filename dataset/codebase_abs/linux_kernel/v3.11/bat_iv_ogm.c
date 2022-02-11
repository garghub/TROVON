static void F_1 ( T_1 V_1 [] , T_1 * V_2 ,
T_1 V_3 )
{
V_1 [ * V_2 ] = V_3 ;
* V_2 = ( * V_2 + 1 ) % V_4 ;
}
static T_1 F_2 ( const T_1 V_1 [] )
{
const T_1 * V_5 ;
T_2 V_6 = 0 , V_7 = 0 , V_8 = 0 ;
V_5 = V_1 ;
while ( V_7 < V_4 ) {
if ( * V_5 != 0 ) {
V_6 ++ ;
V_8 += * V_5 ;
}
V_7 ++ ;
V_5 ++ ;
}
if ( V_6 == 0 )
return 0 ;
return ( T_1 ) ( V_8 / V_6 ) ;
}
static struct V_9 *
F_3 ( struct V_10 * V_11 ,
const T_1 * V_12 ,
struct V_13 * V_14 ,
struct V_13 * V_15 )
{
struct V_9 * V_16 ;
V_16 = F_4 ( V_11 , V_12 ) ;
if ( ! V_16 )
goto V_17;
F_5 ( & V_16 -> V_18 ) ;
V_16 -> V_14 = V_15 ;
V_16 -> V_19 = V_11 ;
F_6 ( & V_14 -> V_20 ) ;
F_7 ( & V_16 -> V_21 , & V_14 -> V_22 ) ;
F_8 ( & V_14 -> V_20 ) ;
V_17:
return V_16 ;
}
static int F_9 ( struct V_10 * V_11 )
{
struct V_23 * V_23 ;
unsigned char * V_24 ;
T_3 V_25 ;
int V_26 = - V_27 ;
F_10 ( & V_25 , sizeof( V_25 ) ) ;
F_11 ( & V_11 -> V_28 . V_29 , V_25 ) ;
V_11 -> V_28 . V_30 = V_31 ;
V_24 = F_12 ( V_11 -> V_28 . V_30 , V_32 ) ;
if ( ! V_24 )
goto V_17;
V_11 -> V_28 . V_24 = V_24 ;
V_23 = (struct V_23 * ) V_24 ;
V_23 -> V_33 . V_34 = V_35 ;
V_23 -> V_33 . V_36 = V_37 ;
V_23 -> V_33 . V_38 = 2 ;
V_23 -> V_39 = V_40 ;
V_23 -> V_41 = V_42 ;
V_23 -> V_43 = 0 ;
V_23 -> V_44 = 0 ;
V_26 = 0 ;
V_17:
return V_26 ;
}
static void F_13 ( struct V_10 * V_11 )
{
F_14 ( V_11 -> V_28 . V_24 ) ;
V_11 -> V_28 . V_24 = NULL ;
}
static void F_15 ( struct V_10 * V_11 )
{
struct V_23 * V_23 ;
unsigned char * V_24 = V_11 -> V_28 . V_24 ;
V_23 = (struct V_23 * ) V_24 ;
memcpy ( V_23 -> V_45 ,
V_11 -> V_46 -> V_47 , V_48 ) ;
memcpy ( V_23 -> V_49 ,
V_11 -> V_46 -> V_47 , V_48 ) ;
}
static void
F_16 ( struct V_10 * V_11 )
{
struct V_23 * V_23 ;
unsigned char * V_24 = V_11 -> V_28 . V_24 ;
V_23 = (struct V_23 * ) V_24 ;
V_23 -> V_39 = V_50 ;
V_23 -> V_33 . V_38 = V_51 ;
}
static unsigned long
F_17 ( const struct V_52 * V_53 )
{
unsigned int V_54 ;
V_54 = F_18 ( & V_53 -> V_55 ) - V_56 ;
V_54 += F_19 () % ( 2 * V_56 ) ;
return V_57 + F_20 ( V_54 ) ;
}
static unsigned long F_21 ( void )
{
return V_57 + F_20 ( F_19 () % ( V_56 / 2 ) ) ;
}
static T_1 F_22 ( T_1 V_41 ,
const struct V_52 * V_53 )
{
int V_58 = F_18 ( & V_53 -> V_58 ) ;
int V_59 ;
V_59 = V_41 * ( V_42 - V_58 ) ;
V_59 /= V_42 ;
return V_59 ;
}
static int F_23 ( int V_60 , int V_61 ,
int V_43 )
{
int V_62 = 0 ;
V_62 += V_60 + V_31 ;
V_62 += F_24 ( V_43 ) ;
return ( V_62 <= V_61 ) &&
( V_62 <= V_63 ) ;
}
static void F_25 ( struct V_64 * V_65 ,
struct V_10 * V_11 )
{
struct V_52 * V_53 = F_26 ( V_11 -> V_66 ) ;
char * V_67 ;
T_1 V_68 ;
T_4 V_60 ;
struct V_23 * V_23 ;
struct V_69 * V_70 ;
T_1 * V_71 ;
if ( V_11 -> V_72 != V_73 )
return;
V_68 = 0 ;
V_60 = 0 ;
V_71 = V_65 -> V_70 -> V_74 ;
V_23 = (struct V_23 * ) V_71 ;
while ( F_23 ( V_60 , V_65 -> V_61 ,
V_23 -> V_43 ) ) {
if ( V_65 -> V_75 & F_27 ( V_68 ) &&
V_65 -> V_19 == V_11 )
V_23 -> V_39 |= V_76 ;
else
V_23 -> V_39 &= ~ V_76 ;
if ( V_68 > 0 || ! V_65 -> V_77 )
V_67 = L_1 ;
else
V_67 = L_2 ;
F_28 ( V_78 , V_53 ,
L_3 ,
V_67 , ( V_68 > 0 ? L_4 : L_5 ) ,
V_23 -> V_45 ,
F_29 ( V_23 -> V_79 ) ,
V_23 -> V_41 , V_23 -> V_33 . V_38 ,
( V_23 -> V_39 & V_76 ?
L_6 : L_7 ) ,
V_23 -> V_44 , V_11 -> V_46 -> V_80 ,
V_11 -> V_46 -> V_47 ) ;
V_60 += V_31 ;
V_60 += F_24 ( V_23 -> V_43 ) ;
V_68 ++ ;
V_71 = V_65 -> V_70 -> V_74 + V_60 ;
V_23 = (struct V_23 * ) V_71 ;
}
V_70 = F_30 ( V_65 -> V_70 , V_32 ) ;
if ( V_70 ) {
F_31 ( V_53 , V_81 ) ;
F_32 ( V_53 , V_82 ,
V_70 -> V_83 + V_84 ) ;
F_33 ( V_70 , V_11 , V_85 ) ;
}
}
static void F_34 ( struct V_64 * V_65 )
{
struct V_10 * V_11 ;
struct V_86 * V_66 ;
struct V_52 * V_53 ;
struct V_10 * V_87 = NULL ;
struct V_23 * V_23 ;
unsigned char V_88 ;
T_1 * V_71 ;
V_71 = V_65 -> V_70 -> V_74 ;
V_23 = (struct V_23 * ) V_71 ;
V_88 = ( V_23 -> V_39 & V_76 ? 1 : 0 ) ;
if ( ! V_65 -> V_19 ) {
F_35 ( L_8 ) ;
goto V_17;
}
V_66 = V_65 -> V_19 -> V_66 ;
V_53 = F_26 ( V_66 ) ;
if ( V_65 -> V_19 -> V_72 != V_73 )
goto V_17;
V_87 = F_36 ( V_53 ) ;
if ( ! V_87 )
goto V_17;
if ( ( V_88 && ( V_23 -> V_33 . V_38 == 1 ) ) ||
( V_65 -> V_77 && ( V_65 -> V_19 != V_87 ) ) ) {
F_28 ( V_78 , V_53 ,
L_9 ,
( V_65 -> V_77 ? L_2 : L_1 ) ,
V_23 -> V_45 ,
F_29 ( V_23 -> V_79 ) ,
V_23 -> V_33 . V_38 ,
V_65 -> V_19 -> V_46 -> V_80 ,
V_65 -> V_19 -> V_46 -> V_47 ) ;
F_33 ( V_65 -> V_70 ,
V_65 -> V_19 ,
V_85 ) ;
V_65 -> V_70 = NULL ;
goto V_17;
}
F_37 () ;
F_38 (hard_iface, &batadv_hardif_list, list) {
if ( V_11 -> V_66 != V_66 )
continue;
F_25 ( V_65 , V_11 ) ;
}
F_39 () ;
V_17:
if ( V_87 )
F_40 ( V_87 ) ;
}
static bool
F_41 ( const struct V_23 * V_89 ,
struct V_52 * V_53 ,
int V_61 , unsigned long V_90 ,
bool V_88 ,
const struct V_10 * V_19 ,
const struct V_64 * V_65 )
{
struct V_23 * V_23 ;
int V_91 = V_65 -> V_61 + V_61 ;
struct V_10 * V_87 = NULL ;
bool V_26 = false ;
unsigned long V_92 ;
V_23 = (struct V_23 * ) V_65 -> V_70 -> V_74 ;
V_92 = V_90 ;
V_92 += F_20 ( V_93 ) ;
if ( F_42 ( V_90 , V_65 -> V_90 ) &&
F_43 ( V_92 , V_65 -> V_90 ) &&
( V_91 <= V_63 ) ) {
V_87 = F_36 ( V_53 ) ;
if ( ! V_87 )
goto V_17;
if ( ( ! V_88 ) &&
( ! ( V_23 -> V_39 & V_76 ) ) &&
( V_23 -> V_33 . V_38 != 1 ) &&
( ( ! V_65 -> V_77 ) ||
( V_65 -> V_19 == V_87 ) ) ) {
V_26 = true ;
goto V_17;
}
if ( ( V_88 ) &&
( V_89 -> V_33 . V_38 == 1 ) &&
( V_65 -> V_19 == V_19 ) &&
( V_23 -> V_39 & V_76 ||
( V_65 -> V_77 &&
V_65 -> V_19 != V_87 ) ) ) {
V_26 = true ;
goto V_17;
}
}
V_17:
if ( V_87 )
F_40 ( V_87 ) ;
return V_26 ;
}
static void F_44 ( const unsigned char * V_94 ,
int V_61 , unsigned long V_90 ,
bool V_95 ,
struct V_10 * V_19 ,
int V_96 )
{
struct V_52 * V_53 = F_26 ( V_19 -> V_66 ) ;
struct V_64 * V_97 ;
unsigned char * V_98 ;
unsigned int V_99 ;
if ( ! F_45 ( & V_19 -> V_100 ) )
return;
if ( ! V_96 ) {
if ( ! F_46 ( & V_53 -> V_101 ) ) {
F_28 ( V_78 , V_53 ,
L_10 ) ;
goto V_17;
}
}
V_97 = F_12 ( sizeof( * V_97 ) , V_32 ) ;
if ( ! V_97 ) {
if ( ! V_96 )
F_47 ( & V_53 -> V_101 ) ;
goto V_17;
}
if ( ( F_18 ( & V_53 -> V_102 ) ) &&
( V_61 < V_63 ) )
V_99 = V_63 ;
else
V_99 = V_61 ;
V_99 += V_84 ;
V_97 -> V_70 = F_48 ( NULL , V_99 ) ;
if ( ! V_97 -> V_70 ) {
if ( ! V_96 )
F_47 ( & V_53 -> V_101 ) ;
F_14 ( V_97 ) ;
goto V_17;
}
F_49 ( V_97 -> V_70 , V_84 ) ;
V_98 = F_50 ( V_97 -> V_70 , V_61 ) ;
V_97 -> V_61 = V_61 ;
memcpy ( V_98 , V_94 , V_61 ) ;
V_97 -> V_77 = V_96 ;
V_97 -> V_19 = V_19 ;
V_97 -> V_103 = 0 ;
V_97 -> V_75 = V_40 ;
V_97 -> V_90 = V_90 ;
if ( V_95 )
V_97 -> V_75 |= 1 ;
F_6 ( & V_53 -> V_104 ) ;
F_51 ( & V_97 -> V_21 , & V_53 -> V_105 ) ;
F_8 ( & V_53 -> V_104 ) ;
F_52 ( & V_97 -> V_106 ,
V_107 ) ;
F_53 ( V_108 ,
& V_97 -> V_106 ,
V_90 - V_57 ) ;
return;
V_17:
F_40 ( V_19 ) ;
}
static void F_54 ( struct V_64 * V_97 ,
const unsigned char * V_94 ,
int V_61 , bool V_95 )
{
unsigned char * V_98 ;
unsigned long V_109 ;
V_98 = F_50 ( V_97 -> V_70 , V_61 ) ;
memcpy ( V_98 , V_94 , V_61 ) ;
V_97 -> V_61 += V_61 ;
V_97 -> V_103 ++ ;
if ( V_95 ) {
V_109 = F_27 ( V_97 -> V_103 ) ;
V_97 -> V_75 |= V_109 ;
}
}
static void F_55 ( struct V_52 * V_53 ,
unsigned char * V_94 ,
int V_61 ,
struct V_10 * V_19 ,
int V_96 , unsigned long V_90 )
{
struct V_64 * V_97 = NULL ;
struct V_64 * V_110 = NULL ;
struct V_23 * V_23 ;
bool V_95 ;
unsigned long V_111 ;
V_23 = (struct V_23 * ) V_94 ;
V_95 = V_23 -> V_39 & V_76 ? 1 : 0 ;
V_111 = F_20 ( V_93 ) ;
F_6 ( & V_53 -> V_104 ) ;
if ( ( F_18 ( & V_53 -> V_102 ) ) && ( ! V_96 ) ) {
F_56 (forw_packet_pos,
&bat_priv->forw_bat_list, list) {
if ( F_41 ( V_23 ,
V_53 , V_61 ,
V_90 , V_95 ,
V_19 ,
V_110 ) ) {
V_97 = V_110 ;
break;
}
}
}
if ( ! V_97 ) {
F_8 ( & V_53 -> V_104 ) ;
if ( ! V_96 && F_18 ( & V_53 -> V_102 ) )
V_90 += V_111 ;
F_44 ( V_94 , V_61 ,
V_90 , V_95 ,
V_19 , V_96 ) ;
} else {
F_54 ( V_97 , V_94 ,
V_61 , V_95 ) ;
F_8 ( & V_53 -> V_104 ) ;
}
}
static void F_57 ( struct V_13 * V_14 ,
const struct V_112 * V_112 ,
struct V_23 * V_23 ,
bool V_113 ,
bool V_114 ,
struct V_10 * V_19 )
{
struct V_52 * V_53 = F_26 ( V_19 -> V_66 ) ;
T_1 V_43 ;
if ( V_23 -> V_33 . V_38 <= 1 ) {
F_28 ( V_78 , V_53 , L_11 ) ;
return;
}
if ( ! V_114 ) {
if ( V_113 )
V_23 -> V_39 |= V_115 ;
else
return;
}
V_43 = V_23 -> V_43 ;
V_23 -> V_33 . V_38 -- ;
memcpy ( V_23 -> V_49 , V_112 -> V_116 , V_48 ) ;
V_23 -> V_41 = F_22 ( V_23 -> V_41 ,
V_53 ) ;
F_28 ( V_78 , V_53 ,
L_12 ,
V_23 -> V_41 , V_23 -> V_33 . V_38 ) ;
V_23 -> V_39 &= ~ V_50 ;
if ( V_113 )
V_23 -> V_39 |= V_76 ;
else
V_23 -> V_39 &= ~ V_76 ;
F_55 ( V_53 , ( unsigned char * ) V_23 ,
V_31 + F_24 ( V_43 ) ,
V_19 , 0 , F_21 () ) ;
}
static void
F_58 ( struct V_10 * V_11 )
{
struct V_52 * V_53 = F_26 ( V_11 -> V_66 ) ;
struct V_117 * V_118 = V_53 -> V_119 ;
struct V_120 * V_121 ;
struct V_13 * V_14 ;
unsigned long * V_122 ;
T_3 V_7 ;
T_5 V_123 ;
T_1 * V_124 ;
for ( V_7 = 0 ; V_7 < V_118 -> V_125 ; V_7 ++ ) {
V_121 = & V_118 -> V_126 [ V_7 ] ;
F_37 () ;
F_59 (orig_node, head, hash_entry) {
F_6 ( & V_14 -> V_127 ) ;
V_123 = V_11 -> V_128 * V_129 ;
V_122 = & ( V_14 -> V_130 [ V_123 ] ) ;
F_60 ( V_53 , V_122 , 1 , 0 ) ;
V_124 = & V_14 -> V_131 [ V_11 -> V_128 ] ;
* V_124 = F_61 ( V_122 , V_132 ) ;
F_8 ( & V_14 -> V_127 ) ;
}
F_39 () ;
}
}
static void F_62 ( struct V_10 * V_11 )
{
struct V_52 * V_53 = F_26 ( V_11 -> V_66 ) ;
unsigned char * * V_24 = & V_11 -> V_28 . V_24 ;
struct V_23 * V_23 ;
struct V_10 * V_87 ;
int * V_30 = & V_11 -> V_28 . V_30 ;
int V_133 , V_43 = 0 ;
T_3 V_79 ;
T_1 V_134 ;
V_133 = F_18 ( & V_53 -> V_135 ) ;
V_87 = F_36 ( V_53 ) ;
if ( V_11 == V_87 )
V_43 = F_63 ( V_53 , V_24 ,
V_30 ,
V_31 ) ;
V_23 = (struct V_23 * ) ( * V_24 ) ;
V_79 = ( T_3 ) F_18 ( & V_11 -> V_28 . V_29 ) ;
V_23 -> V_79 = F_64 ( V_79 ) ;
F_47 ( & V_11 -> V_28 . V_29 ) ;
V_23 -> V_44 = F_18 ( & V_53 -> V_136 . V_137 ) ;
V_23 -> V_138 = F_65 ( V_53 -> V_136 . V_139 ) ;
if ( V_43 >= 0 )
V_23 -> V_43 = V_43 ;
if ( V_133 == V_140 )
V_23 -> V_39 |= V_141 ;
else
V_23 -> V_39 &= ~ V_141 ;
if ( V_11 == V_87 &&
F_18 ( & V_53 -> V_142 ) == V_143 ) {
V_134 = ( T_1 ) F_18 ( & V_53 -> V_144 ) ;
V_23 -> V_145 = V_134 ;
} else {
V_23 -> V_145 = V_40 ;
}
F_58 ( V_11 ) ;
F_55 ( V_53 , V_11 -> V_28 . V_24 ,
V_11 -> V_28 . V_30 , V_11 , 1 ,
F_17 ( V_53 ) ) ;
if ( V_87 )
F_40 ( V_87 ) ;
}
static void
F_66 ( struct V_52 * V_53 ,
struct V_13 * V_14 ,
const struct V_112 * V_112 ,
const struct V_23 * V_23 ,
struct V_10 * V_19 ,
const unsigned char * V_146 ,
enum V_147 V_148 )
{
struct V_9 * V_16 = NULL , * V_149 = NULL ;
struct V_9 * V_150 = NULL ;
struct V_13 * V_151 ;
int V_128 ;
T_1 V_152 , V_153 ;
T_1 * V_12 ;
T_1 V_154 ;
F_28 ( V_78 , V_53 ,
L_13 ) ;
F_37 () ;
F_59 (tmp_neigh_node,
&orig_node->neigh_list, list) {
V_12 = V_149 -> V_155 ;
if ( F_67 ( V_12 , V_112 -> V_116 ) &&
V_149 -> V_19 == V_19 &&
F_45 ( & V_149 -> V_100 ) ) {
if ( F_68 ( V_16 , L_14 ) )
F_69 ( V_16 ) ;
V_16 = V_149 ;
continue;
}
if ( V_148 != V_156 )
continue;
F_6 ( & V_149 -> V_157 ) ;
F_1 ( V_149 -> V_158 ,
& V_149 -> V_159 , 0 ) ;
V_154 = F_2 ( V_149 -> V_158 ) ;
V_149 -> V_154 = V_154 ;
F_8 ( & V_149 -> V_157 ) ;
}
if ( ! V_16 ) {
struct V_13 * V_160 ;
V_160 = F_70 ( V_53 , V_112 -> V_116 ) ;
if ( ! V_160 )
goto V_161;
V_16 = F_3 ( V_19 ,
V_112 -> V_116 ,
V_14 , V_160 ) ;
F_71 ( V_160 ) ;
if ( ! V_16 )
goto V_161;
} else
F_28 ( V_78 , V_53 ,
L_15 ) ;
F_39 () ;
V_14 -> V_39 = V_23 -> V_39 ;
V_16 -> V_162 = V_57 ;
F_6 ( & V_16 -> V_157 ) ;
F_1 ( V_16 -> V_158 ,
& V_16 -> V_159 ,
V_23 -> V_41 ) ;
V_16 -> V_154 = F_2 ( V_16 -> V_158 ) ;
F_8 ( & V_16 -> V_157 ) ;
if ( V_148 == V_156 ) {
V_14 -> V_163 = V_23 -> V_33 . V_38 ;
V_16 -> V_163 = V_23 -> V_33 . V_38 ;
}
F_72 ( V_14 , V_16 ) ;
V_150 = F_73 ( V_14 ) ;
if ( V_150 == V_16 )
goto V_164;
if ( V_150 && ( V_150 -> V_154 > V_16 -> V_154 ) )
goto V_164;
if ( V_150 && ( V_16 -> V_154 == V_150 -> V_154 ) ) {
V_151 = V_150 -> V_14 ;
F_6 ( & V_151 -> V_127 ) ;
V_128 = V_150 -> V_19 -> V_128 ;
V_152 = V_151 -> V_131 [ V_128 ] ;
F_8 ( & V_151 -> V_127 ) ;
V_151 = V_16 -> V_14 ;
F_6 ( & V_151 -> V_127 ) ;
V_128 = V_16 -> V_19 -> V_128 ;
V_153 = V_151 -> V_131 [ V_128 ] ;
F_8 ( & V_151 -> V_127 ) ;
if ( V_152 >= V_153 )
goto V_164;
}
F_74 ( V_53 , V_14 , V_16 ) ;
V_164:
if ( ( ( V_23 -> V_45 != V_112 -> V_116 ) &&
( V_23 -> V_33 . V_38 > 2 ) ) ||
( V_23 -> V_39 & V_50 ) )
F_75 ( V_53 , V_14 , V_146 ,
V_23 -> V_43 ,
V_23 -> V_44 ,
F_76 ( V_23 -> V_138 ) ) ;
if ( V_14 -> V_145 != V_23 -> V_145 )
F_77 ( V_53 , V_14 ,
V_23 -> V_145 ) ;
V_14 -> V_145 = V_23 -> V_145 ;
if ( ( V_14 -> V_145 ) &&
( F_18 ( & V_53 -> V_142 ) == V_165 ) &&
( F_18 ( & V_53 -> V_166 ) > 2 ) )
F_78 ( V_53 , V_14 ) ;
goto V_17;
V_161:
F_39 () ;
V_17:
if ( V_16 )
F_69 ( V_16 ) ;
if ( V_150 )
F_69 ( V_150 ) ;
}
static int F_79 ( struct V_13 * V_14 ,
struct V_13 * V_167 ,
struct V_23 * V_23 ,
struct V_10 * V_19 )
{
struct V_52 * V_53 = F_26 ( V_19 -> V_66 ) ;
struct V_9 * V_16 = NULL , * V_149 ;
T_1 V_168 ;
T_1 V_169 , V_170 , V_171 , V_172 ;
unsigned int V_173 , V_174 ;
int V_175 , V_176 , V_177 = 0 ;
unsigned int V_178 ;
F_37 () ;
F_59 (tmp_neigh_node,
&orig_neigh_node->neigh_list, list) {
if ( ! F_67 ( V_149 -> V_155 ,
V_167 -> V_45 ) )
continue;
if ( V_149 -> V_19 != V_19 )
continue;
if ( ! F_45 ( & V_149 -> V_100 ) )
continue;
V_16 = V_149 ;
break;
}
F_39 () ;
if ( ! V_16 )
V_16 = F_3 ( V_19 ,
V_167 -> V_45 ,
V_167 ,
V_167 ) ;
if ( ! V_16 )
goto V_17;
if ( V_14 == V_167 )
V_16 -> V_162 = V_57 ;
V_14 -> V_162 = V_57 ;
F_6 ( & V_14 -> V_127 ) ;
V_169 = V_167 -> V_131 [ V_19 -> V_128 ] ;
V_170 = V_16 -> V_179 ;
F_8 ( & V_14 -> V_127 ) ;
if ( V_169 > V_170 )
V_168 = V_170 ;
else
V_168 = V_169 ;
if ( V_168 < V_180 ||
V_170 < V_181 )
V_172 = 0 ;
else
V_172 = ( V_42 * V_168 ) / V_170 ;
V_171 = V_132 - V_170 ;
V_173 = V_171 * V_171 * V_171 ;
V_174 = V_132 *
V_132 *
V_132 ;
V_176 = V_42 * V_173 ;
V_176 /= V_174 ;
V_175 = V_42 - V_176 ;
V_178 = V_23 -> V_41 * V_172 * V_175 ;
V_178 /= V_42 * V_42 ;
V_23 -> V_41 = V_178 ;
F_28 ( V_78 , V_53 ,
L_16 ,
V_14 -> V_45 , V_167 -> V_45 , V_168 ,
V_170 , V_172 ,
V_175 , V_23 -> V_41 ) ;
if ( V_23 -> V_41 >= V_182 )
V_177 = 1 ;
V_17:
if ( V_16 )
F_69 ( V_16 ) ;
return V_177 ;
}
static enum V_147
F_80 ( const struct V_112 * V_112 ,
const struct V_23 * V_23 ,
const struct V_10 * V_19 )
{
struct V_52 * V_53 = F_26 ( V_19 -> V_66 ) ;
struct V_13 * V_14 ;
struct V_9 * V_149 ;
int V_183 ;
T_6 V_184 ;
int V_185 = 0 ;
int V_186 ;
enum V_147 V_177 = V_156 ;
T_3 V_79 = F_29 ( V_23 -> V_79 ) ;
T_1 * V_12 ;
T_1 V_187 ;
V_14 = F_70 ( V_53 , V_23 -> V_45 ) ;
if ( ! V_14 )
return V_156 ;
F_6 ( & V_14 -> V_127 ) ;
V_184 = V_79 - V_14 -> V_188 ;
if ( ! F_81 ( & V_14 -> V_22 ) &&
F_82 ( V_53 , V_184 ,
& V_14 -> V_189 ) ) {
V_177 = V_190 ;
goto V_17;
}
F_37 () ;
F_59 (tmp_neigh_node,
&orig_node->neigh_list, list) {
V_12 = V_149 -> V_155 ;
V_183 = F_83 ( V_149 -> V_191 ,
V_14 -> V_188 ,
V_79 ) ;
if ( F_67 ( V_12 , V_112 -> V_116 ) &&
V_149 -> V_19 == V_19 ) {
V_186 = 1 ;
if ( V_183 )
V_177 = V_192 ;
} else {
V_186 = 0 ;
if ( V_183 && ( V_177 != V_192 ) )
V_177 = V_193 ;
}
V_185 |= F_60 ( V_53 ,
V_149 -> V_191 ,
V_184 , V_186 ) ;
V_187 = F_61 ( V_149 -> V_191 ,
V_132 ) ;
V_149 -> V_179 = V_187 ;
}
F_39 () ;
if ( V_185 ) {
F_28 ( V_78 , V_53 ,
L_17 ,
V_14 -> V_188 , V_79 ) ;
V_14 -> V_188 = V_79 ;
}
V_17:
F_8 ( & V_14 -> V_127 ) ;
F_71 ( V_14 ) ;
return V_177 ;
}
static void F_84 ( const struct V_112 * V_112 ,
struct V_23 * V_23 ,
const unsigned char * V_146 ,
struct V_10 * V_19 )
{
struct V_52 * V_53 = F_26 ( V_19 -> V_66 ) ;
struct V_10 * V_11 ;
struct V_13 * V_167 , * V_14 ;
struct V_9 * V_150 = NULL , * V_194 = NULL ;
struct V_9 * V_195 = NULL ;
int V_196 ;
int V_197 = 0 , V_198 = 0 , V_199 = 0 ;
int V_200 ;
bool V_113 = false ;
bool V_114 = false ;
int V_201 , V_202 ;
enum V_147 V_148 ;
T_3 V_203 ;
T_1 * V_49 ;
if ( V_23 -> V_33 . V_34 != V_35 )
return;
V_203 = F_18 ( & V_19 -> V_28 . V_29 ) ;
if ( V_23 -> V_39 & V_76 )
V_196 = 1 ;
else
V_196 = 0 ;
if ( F_67 ( V_112 -> V_116 , V_23 -> V_45 ) )
V_113 = true ;
F_28 ( V_78 , V_53 ,
L_18 ,
V_112 -> V_116 , V_19 -> V_46 -> V_80 ,
V_19 -> V_46 -> V_47 , V_23 -> V_45 ,
V_23 -> V_49 ,
F_29 ( V_23 -> V_79 ) , V_23 -> V_44 ,
F_76 ( V_23 -> V_138 ) ,
V_23 -> V_43 , V_23 -> V_41 ,
V_23 -> V_33 . V_38 ,
V_23 -> V_33 . V_36 , V_196 ) ;
F_37 () ;
F_38 (hard_iface, &batadv_hardif_list, list) {
if ( V_11 -> V_72 != V_73 )
continue;
if ( V_11 -> V_66 != V_19 -> V_66 )
continue;
if ( F_67 ( V_112 -> V_116 ,
V_11 -> V_46 -> V_47 ) )
V_197 = 1 ;
if ( F_67 ( V_23 -> V_45 ,
V_11 -> V_46 -> V_47 ) )
V_198 = 1 ;
if ( F_67 ( V_23 -> V_49 ,
V_11 -> V_46 -> V_47 ) )
V_199 = 1 ;
}
F_39 () ;
if ( V_197 ) {
F_28 ( V_78 , V_53 ,
L_19 ,
V_112 -> V_116 ) ;
return;
}
if ( V_198 ) {
unsigned long * V_122 ;
int V_204 ;
T_6 V_205 ;
T_4 V_128 ;
T_1 * V_206 ;
V_167 = F_70 ( V_53 ,
V_112 -> V_116 ) ;
if ( ! V_167 )
return;
if ( V_196 &&
F_67 ( V_19 -> V_46 -> V_47 ,
V_23 -> V_45 ) ) {
V_128 = V_19 -> V_128 ;
V_204 = V_128 * V_129 ;
F_6 ( & V_167 -> V_127 ) ;
V_122 = & ( V_167 -> V_130 [ V_204 ] ) ;
V_205 = V_203 - 2 ;
V_205 -= F_29 ( V_23 -> V_79 ) ;
F_85 ( V_122 , V_205 ) ;
V_206 = & V_167 -> V_131 [ V_128 ] ;
* V_206 = F_61 ( V_122 ,
V_132 ) ;
F_8 ( & V_167 -> V_127 ) ;
}
F_28 ( V_78 , V_53 ,
L_20 ) ;
F_71 ( V_167 ) ;
return;
}
if ( V_199 ) {
F_28 ( V_78 , V_53 ,
L_21 ,
V_112 -> V_116 ) ;
return;
}
if ( V_23 -> V_39 & V_115 ) {
F_28 ( V_78 , V_53 ,
L_22 ,
V_112 -> V_116 ) ;
return;
}
V_14 = F_70 ( V_53 , V_23 -> V_45 ) ;
if ( ! V_14 )
return;
V_148 = F_80 ( V_112 , V_23 ,
V_19 ) ;
if ( V_148 == V_190 ) {
F_28 ( V_78 , V_53 ,
L_23 ,
V_112 -> V_116 ) ;
goto V_17;
}
if ( V_23 -> V_41 == 0 ) {
F_28 ( V_78 , V_53 ,
L_24 ) ;
goto V_17;
}
V_150 = F_73 ( V_14 ) ;
if ( V_150 )
V_194 = F_73 ( V_150 -> V_14 ) ;
if ( ( V_150 && V_150 -> V_154 != 0 ) &&
( F_67 ( V_150 -> V_155 , V_112 -> V_116 ) ) )
V_114 = true ;
V_49 = V_23 -> V_49 ;
if ( V_150 && V_194 &&
( F_67 ( V_150 -> V_155 , V_49 ) ) &&
! ( F_67 ( V_23 -> V_45 , V_49 ) ) &&
( F_67 ( V_150 -> V_155 , V_194 -> V_155 ) ) ) {
F_28 ( V_78 , V_53 ,
L_25 ,
V_112 -> V_116 ) ;
goto V_17;
}
if ( V_113 )
V_167 = V_14 ;
else
V_167 = F_70 ( V_53 ,
V_112 -> V_116 ) ;
if ( ! V_167 )
goto V_17;
F_86 ( V_53 , V_14 , V_167 ,
V_23 , V_113 ) ;
V_195 = F_73 ( V_167 ) ;
if ( ! V_113 && ( ! V_195 ) ) {
F_28 ( V_78 , V_53 ,
L_26 ) ;
goto V_207;
}
V_200 = F_79 ( V_14 , V_167 ,
V_23 , V_19 ) ;
F_87 ( V_14 , V_167 ,
V_23 ) ;
V_201 = V_14 -> V_188 == F_29 ( V_23 -> V_79 ) ;
V_202 = V_14 -> V_163 - 3 <= V_23 -> V_33 . V_38 ;
if ( V_200 && ( ( V_148 == V_156 ) ||
( V_201 && V_202 ) ) )
F_66 ( V_53 , V_14 , V_112 ,
V_23 , V_19 ,
V_146 , V_148 ) ;
if ( V_113 ) {
F_57 ( V_14 , V_112 , V_23 ,
V_113 ,
V_114 , V_19 ) ;
F_28 ( V_78 , V_53 ,
L_27 ) ;
goto V_207;
}
if ( ! V_200 ) {
F_28 ( V_78 , V_53 ,
L_28 ) ;
goto V_207;
}
if ( V_148 == V_192 ) {
F_28 ( V_78 , V_53 ,
L_29 ) ;
goto V_207;
}
F_28 ( V_78 , V_53 ,
L_30 ) ;
F_57 ( V_14 , V_112 , V_23 ,
V_113 , V_114 ,
V_19 ) ;
V_207:
if ( ( V_167 ) && ( ! V_113 ) )
F_71 ( V_167 ) ;
V_17:
if ( V_150 )
F_69 ( V_150 ) ;
if ( V_194 )
F_69 ( V_194 ) ;
if ( V_195 )
F_69 ( V_195 ) ;
F_71 ( V_14 ) ;
}
static int F_88 ( struct V_69 * V_70 ,
struct V_10 * V_19 )
{
struct V_52 * V_53 = F_26 ( V_19 -> V_66 ) ;
struct V_23 * V_23 ;
struct V_112 * V_112 ;
int V_60 = 0 , V_61 ;
unsigned char * V_146 , * V_94 ;
bool V_177 ;
T_1 * V_71 ;
V_177 = F_89 ( V_70 , V_19 , V_31 ) ;
if ( ! V_177 )
return V_208 ;
if ( V_53 -> V_209 -> V_210 != F_34 )
return V_208 ;
F_31 ( V_53 , V_211 ) ;
F_32 ( V_53 , V_212 ,
V_70 -> V_83 + V_84 ) ;
V_61 = F_90 ( V_70 ) ;
V_112 = F_91 ( V_70 ) ;
V_94 = V_70 -> V_74 ;
V_23 = (struct V_23 * ) V_94 ;
while ( F_23 ( V_60 , V_61 ,
V_23 -> V_43 ) ) {
V_146 = V_94 + V_60 + V_31 ;
F_84 ( V_112 , V_23 , V_146 ,
V_19 ) ;
V_60 += V_31 ;
V_60 += F_24 ( V_23 -> V_43 ) ;
V_71 = V_94 + V_60 ;
V_23 = (struct V_23 * ) V_71 ;
}
F_92 ( V_70 ) ;
return V_213 ;
}
int T_7 F_93 ( void )
{
int V_177 ;
V_177 = F_94 ( V_35 ,
F_88 ) ;
if ( V_177 < 0 )
goto V_17;
V_177 = F_95 ( & V_214 ) ;
if ( V_177 < 0 )
goto V_215;
goto V_17;
V_215:
F_96 ( V_35 ) ;
V_17:
return V_177 ;
}

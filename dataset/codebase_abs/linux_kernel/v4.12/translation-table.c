static bool F_1 ( const struct V_1 * V_2 , const void * V_3 )
{
const void * V_4 = F_2 ( V_2 , struct V_5 ,
V_6 ) ;
const struct V_5 * V_7 = V_4 ;
const struct V_5 * V_8 = V_3 ;
return ( V_7 -> V_9 == V_8 -> V_9 ) && F_3 ( V_4 , V_3 ) ;
}
static inline T_1 F_4 ( const void * V_10 , T_1 V_11 )
{
struct V_5 * V_12 ;
T_1 V_13 = 0 ;
V_12 = (struct V_5 * ) V_10 ;
V_13 = F_5 ( & V_12 -> V_14 , V_15 , V_13 ) ;
V_13 = F_5 ( & V_12 -> V_9 , sizeof( V_12 -> V_9 ) , V_13 ) ;
return V_13 % V_11 ;
}
static struct V_5 *
F_6 ( struct V_16 * V_13 , const T_2 * V_14 ,
unsigned short V_9 )
{
struct V_17 * V_18 ;
struct V_5 V_19 , * V_12 , * V_20 = NULL ;
T_1 V_21 ;
if ( ! V_13 )
return NULL ;
F_7 ( V_19 . V_14 , V_14 ) ;
V_19 . V_9 = V_9 ;
V_21 = F_4 ( & V_19 , V_13 -> V_11 ) ;
V_18 = & V_13 -> V_22 [ V_21 ] ;
F_8 () ;
F_9 (tt, head, hash_entry) {
if ( ! F_3 ( V_12 , V_14 ) )
continue;
if ( V_12 -> V_9 != V_9 )
continue;
if ( ! F_10 ( & V_12 -> V_23 ) )
continue;
V_20 = V_12 ;
break;
}
F_11 () ;
return V_20 ;
}
static struct V_24 *
F_12 ( struct V_25 * V_26 , const T_2 * V_14 ,
unsigned short V_9 )
{
struct V_5 * V_27 ;
struct V_24 * V_28 = NULL ;
V_27 = F_6 ( V_26 -> V_12 . V_29 , V_14 ,
V_9 ) ;
if ( V_27 )
V_28 = F_2 ( V_27 ,
struct V_24 ,
V_30 ) ;
return V_28 ;
}
static struct V_31 *
F_13 ( struct V_25 * V_26 , const T_2 * V_14 ,
unsigned short V_9 )
{
struct V_5 * V_27 ;
struct V_31 * V_32 = NULL ;
V_27 = F_6 ( V_26 -> V_12 . V_33 , V_14 ,
V_9 ) ;
if ( V_27 )
V_32 = F_2 ( V_27 ,
struct V_31 ,
V_30 ) ;
return V_32 ;
}
static void F_14 ( struct V_34 * V_35 )
{
struct V_24 * V_28 ;
V_28 = F_2 ( V_35 , struct V_24 ,
V_30 . V_35 ) ;
F_15 ( V_36 , V_28 ) ;
}
static void F_16 ( struct V_37 * V_38 )
{
struct V_24 * V_28 ;
V_28 = F_2 ( V_38 , struct V_24 ,
V_30 . V_23 ) ;
F_17 ( V_28 -> V_39 ) ;
F_18 ( & V_28 -> V_30 . V_35 , F_14 ) ;
}
static void
F_19 ( struct V_24 * V_28 )
{
F_20 ( & V_28 -> V_30 . V_23 ,
F_16 ) ;
}
static void F_21 ( struct V_34 * V_35 )
{
struct V_31 * V_32 ;
V_32 = F_2 ( V_35 , struct V_31 ,
V_30 . V_35 ) ;
F_15 ( V_40 , V_32 ) ;
}
static void F_22 ( struct V_37 * V_38 )
{
struct V_31 * V_32 ;
V_32 = F_2 ( V_38 , struct V_31 ,
V_30 . V_23 ) ;
F_23 ( V_32 ) ;
F_18 ( & V_32 -> V_30 . V_35 , F_21 ) ;
}
static void
F_24 ( struct V_31 * V_32 )
{
F_20 ( & V_32 -> V_30 . V_23 ,
F_22 ) ;
}
int F_25 ( struct V_25 * V_26 ,
const T_2 * V_14 , unsigned short V_9 )
{
struct V_31 * V_32 ;
int V_41 ;
V_32 = F_13 ( V_26 , V_14 , V_9 ) ;
if ( ! V_32 )
return 0 ;
V_41 = F_26 ( & V_32 -> V_42 ) ;
F_24 ( V_32 ) ;
return V_41 ;
}
static void F_27 ( struct V_25 * V_26 ,
unsigned short V_9 , int V_43 )
{
struct V_44 * V_39 ;
V_39 = F_28 ( V_26 , V_9 ) ;
if ( ! V_39 )
return;
F_29 ( V_43 , & V_39 -> V_12 . V_45 ) ;
F_17 ( V_39 ) ;
}
static void F_30 ( struct V_25 * V_26 ,
unsigned short V_9 )
{
F_27 ( V_26 , V_9 , 1 ) ;
}
static void F_31 ( struct V_25 * V_26 ,
unsigned short V_9 )
{
F_27 ( V_26 , V_9 , - 1 ) ;
}
static void F_32 ( struct V_46 * V_47 ,
unsigned short V_9 , int V_43 )
{
struct V_48 * V_39 ;
V_39 = F_33 ( V_47 , V_9 ) ;
if ( ! V_39 )
return;
if ( F_34 ( V_43 , & V_39 -> V_12 . V_45 ) == 0 ) {
F_35 ( & V_47 -> V_49 ) ;
if ( ! F_36 ( & V_39 -> V_50 ) ) {
F_37 ( & V_39 -> V_50 ) ;
F_38 ( V_39 ) ;
}
F_39 ( & V_47 -> V_49 ) ;
}
F_38 ( V_39 ) ;
}
static void F_40 ( struct V_46 * V_47 ,
unsigned short V_9 )
{
F_32 ( V_47 , V_9 , 1 ) ;
}
static void F_41 ( struct V_46 * V_47 ,
unsigned short V_9 )
{
F_32 ( V_47 , V_9 , - 1 ) ;
}
static void F_42 ( struct V_34 * V_35 )
{
struct V_51 * V_52 ;
V_52 = F_2 ( V_35 , struct V_51 , V_35 ) ;
F_15 ( V_53 , V_52 ) ;
}
static void F_43 ( struct V_37 * V_38 )
{
struct V_51 * V_52 ;
V_52 = F_2 ( V_38 , struct V_51 ,
V_23 ) ;
F_44 ( V_52 -> V_47 ) ;
F_18 ( & V_52 -> V_35 , F_42 ) ;
}
static void
F_45 ( struct V_51 * V_52 )
{
F_20 ( & V_52 -> V_23 , F_43 ) ;
}
static void F_46 ( struct V_25 * V_26 ,
struct V_24 * V_28 ,
T_2 V_54 )
{
struct V_55 * V_56 , * V_57 , * V_58 ;
struct V_5 * V_30 = & V_28 -> V_30 ;
T_2 V_59 = V_30 -> V_59 | V_54 ;
bool V_60 = false ;
bool V_61 , V_62 ;
V_56 = F_47 ( V_63 , V_64 ) ;
if ( ! V_56 )
return;
V_56 -> V_65 . V_59 = V_59 ;
memset ( V_56 -> V_65 . V_66 , 0 ,
sizeof( V_56 -> V_65 . V_66 ) ) ;
F_7 ( V_56 -> V_65 . V_14 , V_30 -> V_14 ) ;
V_56 -> V_65 . V_9 = F_48 ( V_30 -> V_9 ) ;
V_61 = V_59 & V_67 ;
F_35 ( & V_26 -> V_12 . V_68 ) ;
F_49 (entry, safe, &bat_priv->tt.changes_list,
list) {
if ( ! F_3 ( V_57 -> V_65 . V_14 , V_30 -> V_14 ) )
continue;
V_62 = V_57 -> V_65 . V_59 & V_67 ;
if ( ! V_61 && V_62 )
goto V_69;
if ( V_61 && ! V_62 )
goto V_69;
if ( ! V_61 && ! V_62 )
V_57 -> V_65 . V_59 = V_59 ;
continue;
V_69:
F_50 ( & V_57 -> V_50 ) ;
F_15 ( V_63 , V_57 ) ;
F_15 ( V_63 , V_56 ) ;
V_60 = true ;
goto V_70;
}
F_51 ( & V_56 -> V_50 , & V_26 -> V_12 . V_71 ) ;
V_70:
F_39 ( & V_26 -> V_12 . V_68 ) ;
if ( V_60 )
F_52 ( & V_26 -> V_12 . V_72 ) ;
else
F_53 ( & V_26 -> V_12 . V_72 ) ;
}
static int F_54 ( int V_73 )
{
return V_73 * sizeof( struct V_74 ) ;
}
static T_3 F_55 ( T_3 V_75 )
{
return V_75 / F_54 ( 1 ) ;
}
static int F_56 ( struct V_25 * V_26 )
{
T_3 V_76 = 0 ;
T_3 V_77 = 0 ;
struct V_44 * V_39 ;
int V_78 ;
F_8 () ;
F_9 (vlan, &bat_priv->softif_vlan_list, list) {
V_76 ++ ;
V_77 += F_26 ( & V_39 -> V_12 . V_45 ) ;
}
F_11 () ;
V_78 = sizeof( struct V_79 ) ;
V_78 += sizeof( struct V_80 ) ;
V_78 += sizeof( struct V_81 ) ;
V_78 += V_76 * sizeof( struct V_82 ) ;
return V_78 + F_54 ( V_77 ) ;
}
static int F_57 ( struct V_25 * V_26 )
{
if ( V_26 -> V_12 . V_29 )
return 0 ;
V_26 -> V_12 . V_29 = F_58 ( 1024 ) ;
if ( ! V_26 -> V_12 . V_29 )
return - V_83 ;
F_59 ( V_26 -> V_12 . V_29 ,
& V_84 ) ;
return 0 ;
}
static void F_60 ( struct V_25 * V_26 ,
struct V_31 * V_85 ,
const char * V_86 )
{
F_61 ( V_87 , V_26 ,
L_1 ,
V_85 -> V_30 . V_14 ,
F_62 ( V_85 -> V_30 . V_9 ) , V_86 ) ;
F_63 ( V_26 -> V_12 . V_33 , F_1 ,
F_4 , & V_85 -> V_30 ) ;
F_24 ( V_85 ) ;
}
bool F_64 ( struct V_88 * V_89 , const T_2 * V_14 ,
unsigned short V_9 , int V_90 , T_1 V_91 )
{
struct V_25 * V_26 = F_65 ( V_89 ) ;
struct V_24 * V_92 ;
struct V_31 * V_85 = NULL ;
struct V_93 * V_93 = F_66 ( V_89 ) ;
struct V_44 * V_39 ;
struct V_88 * V_94 = NULL ;
struct V_95 * V_96 = NULL ;
struct V_17 * V_18 ;
struct V_51 * V_52 ;
int V_97 , V_98 , V_99 ;
bool V_100 = false ;
bool V_101 = false ;
T_2 V_102 ;
T_1 V_103 ;
if ( V_90 != V_104 )
V_94 = F_67 ( V_93 , V_90 ) ;
if ( V_94 )
V_96 = F_68 ( V_94 ) ;
V_92 = F_12 ( V_26 , V_14 , V_9 ) ;
if ( ! F_69 ( V_14 ) )
V_85 = F_13 ( V_26 , V_14 , V_9 ) ;
if ( V_92 ) {
V_92 -> V_105 = V_106 ;
if ( V_92 -> V_30 . V_59 & V_107 ) {
F_61 ( V_87 , V_26 ,
L_2 ,
V_14 , F_62 ( V_9 ) ) ;
V_92 -> V_30 . V_59 &= ~ V_107 ;
goto V_108;
}
if ( V_92 -> V_30 . V_59 & V_109 ) {
F_61 ( V_87 , V_26 ,
L_3 ,
V_14 , F_62 ( V_9 ) ) ;
V_92 -> V_30 . V_59 &= ~ V_109 ;
V_101 = true ;
}
goto V_110;
}
V_98 = F_56 ( V_26 ) ;
V_98 += F_54 ( 1 ) ;
V_99 = F_26 ( & V_26 -> V_99 ) ;
if ( V_98 > V_99 ) {
F_70 ( V_111 , V_89 ,
L_4 ,
V_98 , V_99 , V_14 ) ;
goto V_112;
}
V_92 = F_47 ( V_36 , V_64 ) ;
if ( ! V_92 )
goto V_112;
V_39 = F_28 ( V_26 , V_9 ) ;
if ( ! V_39 ) {
F_70 ( V_111 , V_89 ,
L_5 ,
V_14 , F_62 ( V_9 ) ) ;
F_15 ( V_36 , V_92 ) ;
V_92 = NULL ;
goto V_112;
}
F_61 ( V_87 , V_26 ,
L_6 ,
V_14 , F_62 ( V_9 ) ,
( T_2 ) F_26 ( & V_26 -> V_12 . V_113 ) ) ;
F_7 ( V_92 -> V_30 . V_14 , V_14 ) ;
V_92 -> V_30 . V_59 = V_114 ;
V_92 -> V_30 . V_9 = V_9 ;
if ( F_71 ( V_96 ) )
V_92 -> V_30 . V_59 |= V_115 ;
F_72 ( & V_92 -> V_30 . V_23 ) ;
V_92 -> V_105 = V_106 ;
V_92 -> V_30 . V_116 = V_92 -> V_105 ;
V_92 -> V_39 = V_39 ;
if ( F_3 ( V_14 , V_89 -> V_117 ) ||
F_69 ( V_14 ) )
V_92 -> V_30 . V_59 |= V_118 ;
F_73 ( & V_92 -> V_30 . V_23 ) ;
V_97 = F_74 ( V_26 -> V_12 . V_29 , F_1 ,
F_4 , & V_92 -> V_30 ,
& V_92 -> V_30 . V_6 ) ;
if ( F_75 ( V_97 != 0 ) ) {
F_19 ( V_92 ) ;
goto V_112;
}
V_108:
F_46 ( V_26 , V_92 , V_119 ) ;
V_110:
if ( V_85 && ! ( V_85 -> V_30 . V_59 & V_109 ) ) {
V_18 = & V_85 -> V_120 ;
F_8 () ;
F_9 (orig_entry, head, list) {
F_76 ( V_26 , V_85 -> V_30 . V_14 ,
V_85 -> V_30 . V_9 ,
V_52 -> V_47 ) ;
}
F_11 () ;
if ( V_101 ) {
F_60 ( V_26 , V_85 ,
L_7 ) ;
V_85 = NULL ;
} else {
V_85 -> V_30 . V_59 |= V_109 ;
V_85 -> V_121 = V_106 ;
}
}
V_102 = V_92 -> V_30 . V_59 & V_122 ;
if ( F_71 ( V_96 ) )
V_92 -> V_30 . V_59 |= V_115 ;
else
V_92 -> V_30 . V_59 &= ~ V_115 ;
V_103 = ( V_91 & V_26 -> V_123 ) ;
if ( V_26 -> V_123 &&
V_103 == V_26 -> V_124 )
V_92 -> V_30 . V_59 |= V_125 ;
else
V_92 -> V_30 . V_59 &= ~ V_125 ;
if ( V_102 ^ ( V_92 -> V_30 . V_59 & V_122 ) )
F_46 ( V_26 , V_92 , V_119 ) ;
V_100 = true ;
V_112:
if ( V_96 )
F_77 ( V_96 ) ;
if ( V_94 )
F_78 ( V_94 ) ;
if ( V_92 )
F_19 ( V_92 ) ;
if ( V_85 )
F_24 ( V_85 ) ;
return V_100 ;
}
static T_3
F_79 ( struct V_46 * V_47 ,
struct V_81 * * V_126 ,
struct V_74 * * V_127 ,
T_4 * V_75 )
{
T_3 V_76 = 0 ;
T_3 V_45 = 0 ;
T_3 V_128 ;
T_3 V_129 ;
struct V_82 * V_130 ;
struct V_48 * V_39 ;
T_2 * V_131 ;
F_8 () ;
F_9 (vlan, &orig_node->vlan_list, list) {
V_76 ++ ;
V_45 += F_26 ( & V_39 -> V_12 . V_45 ) ;
}
V_128 = sizeof( * * V_126 ) ;
V_128 += V_76 * sizeof( * V_130 ) ;
if ( * V_75 < 0 )
* V_75 = F_54 ( V_45 ) ;
V_129 = * V_75 ;
V_129 += V_128 ;
* V_126 = F_80 ( V_129 , V_64 ) ;
if ( ! * V_126 ) {
* V_75 = 0 ;
goto V_112;
}
( * V_126 ) -> V_59 = V_119 ;
( * V_126 ) -> V_132 = F_26 ( & V_47 -> V_133 ) ;
( * V_126 ) -> V_76 = F_48 ( V_76 ) ;
V_130 = (struct V_82 * ) ( * V_126 + 1 ) ;
F_9 (vlan, &orig_node->vlan_list, list) {
V_130 -> V_9 = F_48 ( V_39 -> V_9 ) ;
V_130 -> V_134 = F_81 ( V_39 -> V_12 . V_134 ) ;
V_130 ++ ;
}
V_131 = ( T_2 * ) * V_126 + V_128 ;
* V_127 = (struct V_74 * ) V_131 ;
V_112:
F_11 () ;
return V_129 ;
}
static T_3
F_82 ( struct V_25 * V_26 ,
struct V_81 * * V_126 ,
struct V_74 * * V_127 ,
T_4 * V_75 )
{
struct V_82 * V_130 ;
struct V_44 * V_39 ;
T_3 V_76 = 0 ;
T_3 V_45 = 0 ;
T_3 V_129 ;
T_2 * V_131 ;
int V_128 ;
F_8 () ;
F_9 (vlan, &bat_priv->softif_vlan_list, list) {
V_76 ++ ;
V_45 += F_26 ( & V_39 -> V_12 . V_45 ) ;
}
V_128 = sizeof( * * V_126 ) ;
V_128 += V_76 * sizeof( * V_130 ) ;
if ( * V_75 < 0 )
* V_75 = F_54 ( V_45 ) ;
V_129 = * V_75 ;
V_129 += V_128 ;
* V_126 = F_80 ( V_129 , V_64 ) ;
if ( ! * V_126 ) {
V_129 = 0 ;
goto V_112;
}
( * V_126 ) -> V_59 = V_119 ;
( * V_126 ) -> V_132 = F_26 ( & V_26 -> V_12 . V_113 ) ;
( * V_126 ) -> V_76 = F_48 ( V_76 ) ;
V_130 = (struct V_82 * ) ( * V_126 + 1 ) ;
F_9 (vlan, &bat_priv->softif_vlan_list, list) {
V_130 -> V_9 = F_48 ( V_39 -> V_9 ) ;
V_130 -> V_134 = F_81 ( V_39 -> V_12 . V_134 ) ;
V_130 ++ ;
}
V_131 = ( T_2 * ) * V_126 + V_128 ;
* V_127 = (struct V_74 * ) V_131 ;
V_112:
F_11 () ;
return V_129 ;
}
static void F_83 ( struct V_25 * V_26 )
{
struct V_55 * V_57 , * V_58 ;
struct V_81 * V_126 ;
struct V_74 * V_127 ;
int V_135 , V_136 = 0 ;
int V_137 = 0 ;
int V_138 = 0 ;
T_3 V_129 ;
V_137 = F_26 ( & V_26 -> V_12 . V_72 ) ;
V_135 = F_54 ( V_137 ) ;
if ( V_135 > V_26 -> V_89 -> V_139 )
V_135 = 0 ;
V_129 = F_82 ( V_26 , & V_126 ,
& V_127 , & V_135 ) ;
if ( ! V_129 )
return;
V_126 -> V_59 = V_140 ;
if ( V_135 == 0 )
goto V_141;
F_35 ( & V_26 -> V_12 . V_68 ) ;
F_84 ( & V_26 -> V_12 . V_72 , 0 ) ;
F_49 (entry, safe, &bat_priv->tt.changes_list,
list) {
if ( V_138 < V_137 ) {
memcpy ( V_127 + V_138 ,
& V_57 -> V_65 ,
sizeof( struct V_74 ) ) ;
V_138 ++ ;
}
F_50 ( & V_57 -> V_50 ) ;
F_15 ( V_63 , V_57 ) ;
}
F_39 ( & V_26 -> V_12 . V_68 ) ;
F_35 ( & V_26 -> V_12 . V_142 ) ;
F_85 ( V_26 -> V_12 . V_143 ) ;
V_26 -> V_12 . V_144 = 0 ;
V_26 -> V_12 . V_143 = NULL ;
V_136 = F_54 ( V_138 ) ;
if ( V_138 > 0 ) {
V_26 -> V_12 . V_143 = F_86 ( V_135 , V_64 ) ;
if ( V_26 -> V_12 . V_143 ) {
memcpy ( V_26 -> V_12 . V_143 ,
V_127 , V_136 ) ;
V_26 -> V_12 . V_144 = V_135 ;
}
}
F_39 ( & V_26 -> V_12 . V_142 ) ;
V_141:
F_87 ( V_26 , V_145 , 1 , V_126 ,
V_129 ) ;
F_85 ( V_126 ) ;
}
int F_88 ( struct V_146 * V_147 , void * V_148 )
{
struct V_88 * V_149 = (struct V_88 * ) V_147 -> V_150 ;
struct V_25 * V_26 = F_65 ( V_149 ) ;
struct V_16 * V_13 = V_26 -> V_12 . V_29 ;
struct V_5 * V_27 ;
struct V_24 * V_92 ;
struct V_95 * V_151 ;
struct V_17 * V_18 ;
T_1 V_152 ;
int V_153 ;
int V_154 ;
unsigned long V_155 ;
bool V_156 ;
T_3 V_157 = V_118 ;
V_151 = F_89 ( V_147 ) ;
if ( ! V_151 )
goto V_112;
F_90 ( V_147 ,
L_8 ,
V_149 -> V_158 , ( T_2 ) F_26 ( & V_26 -> V_12 . V_113 ) ) ;
F_91 ( V_147 ,
L_9 ) ;
for ( V_152 = 0 ; V_152 < V_13 -> V_11 ; V_152 ++ ) {
V_18 = & V_13 -> V_22 [ V_152 ] ;
F_8 () ;
F_9 (tt_common_entry,
head, hash_entry) {
V_92 = F_2 ( V_27 ,
struct V_24 ,
V_30 ) ;
V_155 = V_106 - V_92 -> V_105 ;
V_154 = F_92 ( V_155 ) ;
V_153 = V_154 / 1000 ;
V_154 = V_154 % 1000 ;
V_156 = V_27 -> V_59 & V_157 ;
F_90 ( V_147 ,
L_10 ,
V_27 -> V_14 ,
F_62 ( V_27 -> V_9 ) ,
( ( V_27 -> V_59 &
V_109 ) ? 'R' : '.' ) ,
V_156 ? 'P' : '.' ,
( ( V_27 -> V_59 &
V_114 ) ? 'N' : '.' ) ,
( ( V_27 -> V_59 &
V_107 ) ? 'X' : '.' ) ,
( ( V_27 -> V_59 &
V_115 ) ? 'W' : '.' ) ,
( ( V_27 -> V_59 &
V_125 ) ? 'I' : '.' ) ,
V_156 ? 0 : V_153 ,
V_156 ? 0 : V_154 ,
V_92 -> V_39 -> V_12 . V_134 ) ;
}
F_11 () ;
}
V_112:
if ( V_151 )
F_77 ( V_151 ) ;
return 0 ;
}
static int
F_93 ( struct V_159 * V_160 , T_1 V_161 , T_1 V_147 ,
struct V_25 * V_26 ,
struct V_5 * V_30 )
{
void * V_162 ;
struct V_44 * V_39 ;
struct V_24 * V_163 ;
unsigned int V_154 ;
T_1 V_134 ;
V_163 = F_2 ( V_30 , struct V_24 , V_30 ) ;
V_154 = F_92 ( V_106 - V_163 -> V_105 ) ;
V_39 = F_28 ( V_26 , V_30 -> V_9 ) ;
if ( ! V_39 )
return 0 ;
V_134 = V_39 -> V_12 . V_134 ;
F_17 ( V_39 ) ;
V_162 = F_94 ( V_160 , V_161 , V_147 , & V_164 ,
V_165 ,
V_166 ) ;
if ( ! V_162 )
return - V_167 ;
if ( F_95 ( V_160 , V_168 , V_15 , V_30 -> V_14 ) ||
F_96 ( V_160 , V_169 , V_134 ) ||
F_97 ( V_160 , V_170 , V_30 -> V_9 ) ||
F_96 ( V_160 , V_171 , V_30 -> V_59 ) )
goto V_172;
if ( ! ( V_30 -> V_59 & V_118 ) &&
F_96 ( V_160 , V_173 , V_154 ) )
goto V_172;
F_98 ( V_160 , V_162 ) ;
return 0 ;
V_172:
F_99 ( V_160 , V_162 ) ;
return - V_174 ;
}
static int
F_100 ( struct V_159 * V_160 , T_1 V_161 , T_1 V_147 ,
struct V_25 * V_26 ,
struct V_17 * V_18 , int * V_175 )
{
struct V_5 * V_30 ;
int V_176 = 0 ;
F_8 () ;
F_9 (common, head, hash_entry) {
if ( V_176 ++ < * V_175 )
continue;
if ( F_93 ( V_160 , V_161 , V_147 , V_26 ,
V_30 ) ) {
F_11 () ;
* V_175 = V_176 - 1 ;
return - V_174 ;
}
}
F_11 () ;
* V_175 = 0 ;
return 0 ;
}
int F_101 ( struct V_159 * V_160 , struct V_177 * V_178 )
{
struct V_93 * V_93 = F_102 ( V_178 -> V_179 -> V_180 ) ;
struct V_88 * V_89 ;
struct V_25 * V_26 ;
struct V_95 * V_151 = NULL ;
struct V_16 * V_13 ;
struct V_17 * V_18 ;
int V_100 ;
int V_90 ;
int V_181 = V_178 -> args [ 0 ] ;
int V_176 = V_178 -> args [ 1 ] ;
int V_161 = F_103 ( V_178 -> V_179 ) . V_161 ;
V_90 = F_104 ( V_178 -> V_182 , V_183 ) ;
if ( ! V_90 )
return - V_184 ;
V_89 = F_67 ( V_93 , V_90 ) ;
if ( ! V_89 || ! F_105 ( V_89 ) ) {
V_100 = - V_185 ;
goto V_112;
}
V_26 = F_65 ( V_89 ) ;
V_151 = F_106 ( V_26 ) ;
if ( ! V_151 || V_151 -> V_186 != V_187 ) {
V_100 = - V_188 ;
goto V_112;
}
V_13 = V_26 -> V_12 . V_29 ;
while ( V_181 < V_13 -> V_11 ) {
V_18 = & V_13 -> V_22 [ V_181 ] ;
if ( F_100 ( V_160 , V_161 , V_178 -> V_182 -> V_189 ,
V_26 , V_18 , & V_176 ) )
break;
V_181 ++ ;
}
V_100 = V_160 -> V_190 ;
V_112:
if ( V_151 )
F_77 ( V_151 ) ;
if ( V_89 )
F_78 ( V_89 ) ;
V_178 -> args [ 0 ] = V_181 ;
V_178 -> args [ 1 ] = V_176 ;
return V_100 ;
}
static void
F_107 ( struct V_25 * V_26 ,
struct V_24 * V_28 ,
T_3 V_59 , const char * V_86 )
{
F_46 ( V_26 , V_28 , V_59 ) ;
V_28 -> V_30 . V_59 |= V_107 ;
F_61 ( V_87 , V_26 ,
L_11 ,
V_28 -> V_30 . V_14 ,
F_62 ( V_28 -> V_30 . V_9 ) , V_86 ) ;
}
T_3 F_108 ( struct V_25 * V_26 , const T_2 * V_14 ,
unsigned short V_9 , const char * V_86 ,
bool V_191 )
{
struct V_24 * V_28 ;
T_3 V_59 , V_192 = V_119 ;
void * V_193 ;
V_28 = F_12 ( V_26 , V_14 , V_9 ) ;
if ( ! V_28 )
goto V_112;
V_192 = V_28 -> V_30 . V_59 ;
V_59 = V_67 ;
if ( V_191 ) {
V_59 |= V_109 ;
V_28 -> V_30 . V_59 |= V_109 ;
}
if ( ! ( V_28 -> V_30 . V_59 & V_114 ) ) {
F_107 ( V_26 , V_28 , V_59 ,
V_86 ) ;
goto V_112;
}
F_46 ( V_26 , V_28 , V_67 ) ;
V_193 = F_63 ( V_26 -> V_12 . V_29 ,
F_1 ,
F_4 ,
& V_28 -> V_30 ) ;
if ( ! V_193 )
goto V_112;
F_19 ( V_28 ) ;
V_112:
if ( V_28 )
F_19 ( V_28 ) ;
return V_192 ;
}
static void F_109 ( struct V_25 * V_26 ,
struct V_17 * V_18 ,
int V_194 )
{
struct V_24 * V_28 ;
struct V_5 * V_27 ;
struct V_1 * V_195 ;
F_110 (tt_common_entry, node_tmp, head,
hash_entry) {
V_28 = F_2 ( V_27 ,
struct V_24 ,
V_30 ) ;
if ( V_28 -> V_30 . V_59 & V_118 )
continue;
if ( V_28 -> V_30 . V_59 & V_107 )
continue;
if ( ! F_111 ( V_28 -> V_105 , V_194 ) )
continue;
F_107 ( V_26 , V_28 ,
V_67 , L_12 ) ;
}
}
static void F_112 ( struct V_25 * V_26 ,
int V_194 )
{
struct V_16 * V_13 = V_26 -> V_12 . V_29 ;
struct V_17 * V_18 ;
T_5 * V_196 ;
T_1 V_152 ;
for ( V_152 = 0 ; V_152 < V_13 -> V_11 ; V_152 ++ ) {
V_18 = & V_13 -> V_22 [ V_152 ] ;
V_196 = & V_13 -> V_197 [ V_152 ] ;
F_35 ( V_196 ) ;
F_109 ( V_26 , V_18 , V_194 ) ;
F_39 ( V_196 ) ;
}
}
static void F_113 ( struct V_25 * V_26 )
{
struct V_16 * V_13 ;
T_5 * V_196 ;
struct V_5 * V_27 ;
struct V_24 * V_92 ;
struct V_1 * V_195 ;
struct V_17 * V_18 ;
T_1 V_152 ;
if ( ! V_26 -> V_12 . V_29 )
return;
V_13 = V_26 -> V_12 . V_29 ;
for ( V_152 = 0 ; V_152 < V_13 -> V_11 ; V_152 ++ ) {
V_18 = & V_13 -> V_22 [ V_152 ] ;
V_196 = & V_13 -> V_197 [ V_152 ] ;
F_35 ( V_196 ) ;
F_110 (tt_common_entry, node_tmp,
head, hash_entry) {
F_114 ( & V_27 -> V_6 ) ;
V_92 = F_2 ( V_27 ,
struct V_24 ,
V_30 ) ;
F_19 ( V_92 ) ;
}
F_39 ( V_196 ) ;
}
F_115 ( V_13 ) ;
V_26 -> V_12 . V_29 = NULL ;
}
static int F_116 ( struct V_25 * V_26 )
{
if ( V_26 -> V_12 . V_33 )
return 0 ;
V_26 -> V_12 . V_33 = F_58 ( 1024 ) ;
if ( ! V_26 -> V_12 . V_33 )
return - V_83 ;
F_59 ( V_26 -> V_12 . V_33 ,
& V_198 ) ;
return 0 ;
}
static void F_117 ( struct V_25 * V_26 )
{
struct V_55 * V_57 , * V_58 ;
F_35 ( & V_26 -> V_12 . V_68 ) ;
F_49 (entry, safe, &bat_priv->tt.changes_list,
list) {
F_50 ( & V_57 -> V_50 ) ;
F_15 ( V_63 , V_57 ) ;
}
F_84 ( & V_26 -> V_12 . V_72 , 0 ) ;
F_39 ( & V_26 -> V_12 . V_68 ) ;
}
static struct V_51 *
F_118 ( const struct V_31 * V_57 ,
const struct V_46 * V_47 )
{
struct V_51 * V_199 , * V_52 = NULL ;
const struct V_17 * V_18 ;
F_8 () ;
V_18 = & V_57 -> V_120 ;
F_9 (tmp_orig_entry, head, list) {
if ( V_199 -> V_47 != V_47 )
continue;
if ( ! F_10 ( & V_199 -> V_23 ) )
continue;
V_52 = V_199 ;
break;
}
F_11 () ;
return V_52 ;
}
static bool
F_119 ( const struct V_31 * V_57 ,
const struct V_46 * V_47 )
{
struct V_51 * V_52 ;
bool V_200 = false ;
V_52 = F_118 ( V_57 , V_47 ) ;
if ( V_52 ) {
V_200 = true ;
F_45 ( V_52 ) ;
}
return V_200 ;
}
static void
F_120 ( struct V_31 * V_85 ,
struct V_46 * V_47 , int V_132 )
{
struct V_51 * V_52 ;
V_52 = F_118 ( V_85 , V_47 ) ;
if ( V_52 ) {
V_52 -> V_132 = V_132 ;
goto V_112;
}
V_52 = F_121 ( V_53 , V_64 ) ;
if ( ! V_52 )
goto V_112;
F_122 ( & V_52 -> V_50 ) ;
F_73 ( & V_47 -> V_23 ) ;
F_40 ( V_47 , V_85 -> V_30 . V_9 ) ;
V_52 -> V_47 = V_47 ;
V_52 -> V_132 = V_132 ;
F_72 ( & V_52 -> V_23 ) ;
F_35 ( & V_85 -> V_196 ) ;
F_73 ( & V_52 -> V_23 ) ;
F_123 ( & V_52 -> V_50 ,
& V_85 -> V_120 ) ;
F_39 ( & V_85 -> V_196 ) ;
F_53 ( & V_85 -> V_42 ) ;
V_112:
if ( V_52 )
F_45 ( V_52 ) ;
}
static bool F_124 ( struct V_25 * V_26 ,
struct V_46 * V_47 ,
const unsigned char * V_201 ,
unsigned short V_9 , T_3 V_59 , T_2 V_132 )
{
struct V_31 * V_32 ;
struct V_24 * V_28 ;
bool V_100 = false ;
int V_97 ;
struct V_5 * V_30 ;
T_3 V_202 ;
if ( F_125 ( V_26 , V_47 -> V_203 , V_9 ) )
return true ;
V_32 = F_13 ( V_26 , V_201 , V_9 ) ;
V_28 = F_12 ( V_26 , V_201 , V_9 ) ;
if ( ( V_59 & V_204 ) && V_28 &&
! ( V_28 -> V_30 . V_59 & V_114 ) )
goto V_112;
if ( ! V_32 ) {
V_32 = F_121 ( V_40 ,
V_64 ) ;
if ( ! V_32 )
goto V_112;
V_30 = & V_32 -> V_30 ;
F_7 ( V_30 -> V_14 , V_201 ) ;
V_30 -> V_9 = V_9 ;
V_30 -> V_59 = V_59 ;
V_32 -> V_121 = 0 ;
if ( V_59 & V_109 )
V_32 -> V_121 = V_106 ;
F_72 ( & V_30 -> V_23 ) ;
V_30 -> V_116 = V_106 ;
F_126 ( & V_32 -> V_120 ) ;
F_84 ( & V_32 -> V_42 , 0 ) ;
F_127 ( & V_32 -> V_196 ) ;
F_73 ( & V_30 -> V_23 ) ;
V_97 = F_74 ( V_26 -> V_12 . V_33 ,
F_1 ,
F_4 , V_30 ,
& V_30 -> V_6 ) ;
if ( F_75 ( V_97 != 0 ) ) {
F_24 ( V_32 ) ;
goto V_205;
}
} else {
V_30 = & V_32 -> V_30 ;
if ( V_59 & V_204 ) {
if ( ! ( V_30 -> V_59 & V_204 ) )
goto V_112;
if ( F_119 ( V_32 ,
V_47 ) )
goto V_205;
F_23 ( V_32 ) ;
goto V_206;
}
if ( V_30 -> V_59 & V_204 ) {
F_23 ( V_32 ) ;
V_30 -> V_59 &= ~ V_204 ;
}
V_30 -> V_59 |= V_59 ;
if ( V_30 -> V_59 & V_109 ) {
F_23 ( V_32 ) ;
V_30 -> V_59 &= ~ V_109 ;
V_32 -> V_121 = 0 ;
}
}
V_206:
F_120 ( V_32 , V_47 , V_132 ) ;
F_61 ( V_87 , V_26 ,
L_13 ,
V_30 -> V_14 , F_62 ( V_30 -> V_9 ) ,
V_47 -> V_203 ) ;
V_100 = true ;
V_205:
if ( F_69 ( V_201 ) )
goto V_112;
V_202 = F_108 ( V_26 , V_201 , V_9 ,
L_14 ,
V_59 & V_109 ) ;
V_32 -> V_30 . V_59 |= V_202 & V_115 ;
if ( ! ( V_59 & V_109 ) )
V_32 -> V_30 . V_59 &= ~ V_109 ;
V_112:
if ( V_32 )
F_24 ( V_32 ) ;
if ( V_28 )
F_19 ( V_28 ) ;
return V_100 ;
}
static struct V_51 *
F_128 ( struct V_25 * V_26 ,
struct V_31 * V_32 )
{
struct V_207 * V_208 , * V_209 = NULL ;
struct V_210 * V_211 = V_26 -> V_212 ;
struct V_17 * V_18 ;
struct V_51 * V_52 , * V_213 = NULL ;
V_18 = & V_32 -> V_120 ;
F_9 (orig_entry, head, list) {
V_208 = F_129 ( V_52 -> V_47 ,
V_214 ) ;
if ( ! V_208 )
continue;
if ( V_209 &&
V_211 -> V_215 . V_216 ( V_208 , V_214 , V_209 ,
V_214 ) <= 0 ) {
F_130 ( V_208 ) ;
continue;
}
if ( V_209 )
F_130 ( V_209 ) ;
V_213 = V_52 ;
V_209 = V_208 ;
}
if ( V_209 )
F_130 ( V_209 ) ;
return V_213 ;
}
static void
F_131 ( struct V_25 * V_26 ,
struct V_31 * V_32 ,
struct V_146 * V_147 )
{
struct V_51 * V_52 , * V_213 ;
struct V_5 * V_27 ;
struct V_48 * V_39 ;
struct V_17 * V_18 ;
T_2 V_133 ;
T_3 V_59 ;
V_27 = & V_32 -> V_30 ;
V_59 = V_27 -> V_59 ;
V_213 = F_128 ( V_26 , V_32 ) ;
if ( V_213 ) {
V_39 = F_132 ( V_213 -> V_47 ,
V_27 -> V_9 ) ;
if ( ! V_39 ) {
F_90 ( V_147 ,
L_15 ,
F_62 ( V_27 -> V_9 ) ,
V_213 -> V_47 -> V_203 ) ;
goto V_217;
}
V_133 = F_26 ( & V_213 -> V_47 -> V_133 ) ;
F_90 ( V_147 ,
L_16 ,
'*' , V_32 -> V_30 . V_14 ,
F_62 ( V_32 -> V_30 . V_9 ) ,
V_213 -> V_132 , V_213 -> V_47 -> V_203 ,
V_133 , V_39 -> V_12 . V_134 ,
( ( V_59 & V_109 ) ? 'R' : '.' ) ,
( ( V_59 & V_115 ) ? 'W' : '.' ) ,
( ( V_59 & V_125 ) ? 'I' : '.' ) ,
( ( V_59 & V_204 ) ? 'T' : '.' ) ) ;
F_38 ( V_39 ) ;
}
V_217:
V_18 = & V_32 -> V_120 ;
F_9 (orig_entry, head, list) {
if ( V_213 == V_52 )
continue;
V_39 = F_132 ( V_52 -> V_47 ,
V_27 -> V_9 ) ;
if ( ! V_39 ) {
F_90 ( V_147 ,
L_17 ,
F_62 ( V_27 -> V_9 ) ,
V_52 -> V_47 -> V_203 ) ;
continue;
}
V_133 = F_26 ( & V_52 -> V_47 -> V_133 ) ;
F_90 ( V_147 ,
L_18 ,
'+' , V_32 -> V_30 . V_14 ,
F_62 ( V_32 -> V_30 . V_9 ) ,
V_52 -> V_132 , V_52 -> V_47 -> V_203 ,
V_133 , V_39 -> V_12 . V_134 ,
( ( V_59 & V_109 ) ? 'R' : '.' ) ,
( ( V_59 & V_115 ) ? 'W' : '.' ) ,
( ( V_59 & V_125 ) ? 'I' : '.' ) ,
( ( V_59 & V_204 ) ? 'T' : '.' ) ) ;
F_38 ( V_39 ) ;
}
}
int F_133 ( struct V_146 * V_147 , void * V_148 )
{
struct V_88 * V_149 = (struct V_88 * ) V_147 -> V_150 ;
struct V_25 * V_26 = F_65 ( V_149 ) ;
struct V_16 * V_13 = V_26 -> V_12 . V_33 ;
struct V_5 * V_27 ;
struct V_31 * V_85 ;
struct V_95 * V_151 ;
struct V_17 * V_18 ;
T_1 V_152 ;
V_151 = F_89 ( V_147 ) ;
if ( ! V_151 )
goto V_112;
F_90 ( V_147 ,
L_19 ,
V_149 -> V_158 ) ;
F_91 ( V_147 ,
L_20 ) ;
for ( V_152 = 0 ; V_152 < V_13 -> V_11 ; V_152 ++ ) {
V_18 = & V_13 -> V_22 [ V_152 ] ;
F_8 () ;
F_9 (tt_common_entry,
head, hash_entry) {
V_85 = F_2 ( V_27 ,
struct V_31 ,
V_30 ) ;
F_131 ( V_26 , V_85 , V_147 ) ;
}
F_11 () ;
}
V_112:
if ( V_151 )
F_77 ( V_151 ) ;
return 0 ;
}
static int
F_134 ( struct V_159 * V_160 , T_1 V_161 , T_1 V_147 ,
struct V_5 * V_30 ,
struct V_51 * V_203 ,
bool V_218 )
{
void * V_162 ;
struct V_48 * V_39 ;
T_2 V_133 ;
T_1 V_134 ;
V_39 = F_132 ( V_203 -> V_47 ,
V_30 -> V_9 ) ;
if ( ! V_39 )
return 0 ;
V_134 = V_39 -> V_12 . V_134 ;
F_38 ( V_39 ) ;
V_162 = F_94 ( V_160 , V_161 , V_147 , & V_164 ,
V_165 ,
V_219 ) ;
if ( ! V_162 )
return - V_167 ;
V_133 = F_26 ( & V_203 -> V_47 -> V_133 ) ;
if ( F_95 ( V_160 , V_168 , V_15 , V_30 -> V_14 ) ||
F_95 ( V_160 , V_220 , V_15 ,
V_203 -> V_47 -> V_203 ) ||
F_135 ( V_160 , V_221 , V_203 -> V_132 ) ||
F_135 ( V_160 , V_222 , V_133 ) ||
F_96 ( V_160 , V_169 , V_134 ) ||
F_97 ( V_160 , V_170 , V_30 -> V_9 ) ||
F_96 ( V_160 , V_171 , V_30 -> V_59 ) )
goto V_172;
if ( V_218 && F_136 ( V_160 , V_223 ) )
goto V_172;
F_98 ( V_160 , V_162 ) ;
return 0 ;
V_172:
F_99 ( V_160 , V_162 ) ;
return - V_174 ;
}
static int
F_137 ( struct V_159 * V_160 , T_1 V_161 , T_1 V_147 ,
struct V_25 * V_26 ,
struct V_5 * V_30 , int * V_224 )
{
struct V_51 * V_52 , * V_213 ;
struct V_31 * V_225 ;
struct V_17 * V_18 ;
int V_226 = 0 ;
bool V_218 ;
V_225 = F_2 ( V_30 , struct V_31 , V_30 ) ;
V_213 = F_128 ( V_26 , V_225 ) ;
V_18 = & V_225 -> V_120 ;
F_9 (orig_entry, head, list) {
if ( V_226 ++ < * V_224 )
continue;
V_218 = ( V_52 == V_213 ) ;
if ( F_134 ( V_160 , V_161 , V_147 , V_30 ,
V_52 , V_218 ) ) {
* V_224 = V_226 - 1 ;
return - V_174 ;
}
}
* V_224 = 0 ;
return 0 ;
}
static int
F_138 ( struct V_159 * V_160 , T_1 V_161 , T_1 V_147 ,
struct V_25 * V_26 ,
struct V_17 * V_18 , int * V_175 , int * V_226 )
{
struct V_5 * V_30 ;
int V_176 = 0 ;
F_8 () ;
F_9 (common, head, hash_entry) {
if ( V_176 ++ < * V_175 )
continue;
if ( F_137 ( V_160 , V_161 , V_147 , V_26 ,
V_30 , V_226 ) ) {
F_11 () ;
* V_175 = V_176 - 1 ;
return - V_174 ;
}
}
F_11 () ;
* V_175 = 0 ;
* V_226 = 0 ;
return 0 ;
}
int F_139 ( struct V_159 * V_160 , struct V_177 * V_178 )
{
struct V_93 * V_93 = F_102 ( V_178 -> V_179 -> V_180 ) ;
struct V_88 * V_89 ;
struct V_25 * V_26 ;
struct V_95 * V_151 = NULL ;
struct V_16 * V_13 ;
struct V_17 * V_18 ;
int V_100 ;
int V_90 ;
int V_181 = V_178 -> args [ 0 ] ;
int V_176 = V_178 -> args [ 1 ] ;
int V_226 = V_178 -> args [ 2 ] ;
int V_161 = F_103 ( V_178 -> V_179 ) . V_161 ;
V_90 = F_104 ( V_178 -> V_182 , V_183 ) ;
if ( ! V_90 )
return - V_184 ;
V_89 = F_67 ( V_93 , V_90 ) ;
if ( ! V_89 || ! F_105 ( V_89 ) ) {
V_100 = - V_185 ;
goto V_112;
}
V_26 = F_65 ( V_89 ) ;
V_151 = F_106 ( V_26 ) ;
if ( ! V_151 || V_151 -> V_186 != V_187 ) {
V_100 = - V_188 ;
goto V_112;
}
V_13 = V_26 -> V_12 . V_33 ;
while ( V_181 < V_13 -> V_11 ) {
V_18 = & V_13 -> V_22 [ V_181 ] ;
if ( F_138 ( V_160 , V_161 ,
V_178 -> V_182 -> V_189 , V_26 ,
V_18 , & V_176 , & V_226 ) )
break;
V_181 ++ ;
}
V_100 = V_160 -> V_190 ;
V_112:
if ( V_151 )
F_77 ( V_151 ) ;
if ( V_89 )
F_78 ( V_89 ) ;
V_178 -> args [ 0 ] = V_181 ;
V_178 -> args [ 1 ] = V_176 ;
V_178 -> args [ 2 ] = V_226 ;
return V_100 ;
}
static void
F_140 ( struct V_31 * V_32 ,
struct V_51 * V_52 )
{
F_141 ( & V_32 -> V_196 ) ;
F_41 ( V_52 -> V_47 ,
V_32 -> V_30 . V_9 ) ;
F_52 ( & V_32 -> V_42 ) ;
F_114 ( & V_52 -> V_50 ) ;
F_45 ( V_52 ) ;
}
static void
F_23 ( struct V_31 * V_32 )
{
struct V_17 * V_18 ;
struct V_1 * V_58 ;
struct V_51 * V_52 ;
F_35 ( & V_32 -> V_196 ) ;
V_18 = & V_32 -> V_120 ;
F_110 (orig_entry, safe, head, list)
F_140 ( V_32 , V_52 ) ;
F_39 ( & V_32 -> V_196 ) ;
}
static void
F_142 ( struct V_25 * V_26 ,
struct V_31 * V_32 ,
struct V_46 * V_47 ,
const char * V_86 )
{
struct V_17 * V_18 ;
struct V_1 * V_58 ;
struct V_51 * V_52 ;
unsigned short V_9 ;
F_35 ( & V_32 -> V_196 ) ;
V_18 = & V_32 -> V_120 ;
F_110 (orig_entry, safe, head, list) {
if ( V_52 -> V_47 == V_47 ) {
V_9 = V_32 -> V_30 . V_9 ;
F_61 ( V_87 , V_26 ,
L_21 ,
V_47 -> V_203 ,
V_32 -> V_30 . V_14 ,
F_62 ( V_9 ) , V_86 ) ;
F_140 ( V_32 ,
V_52 ) ;
}
}
F_39 ( & V_32 -> V_196 ) ;
}
static void
F_143 ( struct V_25 * V_26 ,
struct V_31 * V_32 ,
struct V_46 * V_47 ,
const char * V_86 )
{
bool V_227 = true ;
struct V_17 * V_18 ;
struct V_51 * V_52 ;
F_8 () ;
V_18 = & V_32 -> V_120 ;
F_9 (orig_entry, head, list) {
if ( V_52 -> V_47 != V_47 ) {
V_227 = false ;
break;
}
}
F_11 () ;
if ( V_227 ) {
V_32 -> V_30 . V_59 |= V_109 ;
V_32 -> V_121 = V_106 ;
} else {
F_142 ( V_26 , V_32 ,
V_47 , V_86 ) ;
}
}
static void F_144 ( struct V_25 * V_26 ,
struct V_46 * V_47 ,
const unsigned char * V_14 , unsigned short V_9 ,
const char * V_86 , bool V_191 )
{
struct V_31 * V_32 ;
struct V_24 * V_228 = NULL ;
V_32 = F_13 ( V_26 , V_14 , V_9 ) ;
if ( ! V_32 )
goto V_112;
if ( ! V_191 ) {
F_142 ( V_26 , V_32 ,
V_47 , V_86 ) ;
if ( F_145 ( & V_32 -> V_120 ) )
F_60 ( V_26 , V_32 ,
V_86 ) ;
goto V_112;
}
V_228 = F_12 ( V_26 ,
V_32 -> V_30 . V_14 ,
V_9 ) ;
if ( V_228 ) {
F_23 ( V_32 ) ;
F_60 ( V_26 , V_32 , V_86 ) ;
} else {
F_143 ( V_26 , V_32 ,
V_47 , V_86 ) ;
}
V_112:
if ( V_32 )
F_24 ( V_32 ) ;
if ( V_228 )
F_19 ( V_228 ) ;
}
void F_146 ( struct V_25 * V_26 ,
struct V_46 * V_47 ,
T_4 V_229 ,
const char * V_86 )
{
struct V_31 * V_85 ;
struct V_5 * V_27 ;
T_1 V_152 ;
struct V_16 * V_13 = V_26 -> V_12 . V_33 ;
struct V_1 * V_58 ;
struct V_17 * V_18 ;
T_5 * V_196 ;
unsigned short V_9 ;
if ( ! V_13 )
return;
for ( V_152 = 0 ; V_152 < V_13 -> V_11 ; V_152 ++ ) {
V_18 = & V_13 -> V_22 [ V_152 ] ;
V_196 = & V_13 -> V_197 [ V_152 ] ;
F_35 ( V_196 ) ;
F_110 (tt_common_entry, safe,
head, hash_entry) {
if ( V_229 >= 0 && V_27 -> V_9 != V_229 )
continue;
V_85 = F_2 ( V_27 ,
struct V_31 ,
V_30 ) ;
F_142 ( V_26 , V_85 ,
V_47 , V_86 ) ;
if ( F_145 ( & V_85 -> V_120 ) ) {
V_9 = V_85 -> V_30 . V_9 ;
F_61 ( V_87 , V_26 ,
L_1 ,
V_85 -> V_30 . V_14 ,
F_62 ( V_9 ) , V_86 ) ;
F_114 ( & V_27 -> V_6 ) ;
F_24 ( V_85 ) ;
}
}
F_39 ( V_196 ) ;
}
F_147 ( V_230 , & V_47 -> V_231 ) ;
}
static bool F_148 ( struct V_31 * V_85 ,
char * * V_160 )
{
bool V_232 = false ;
unsigned long V_233 = V_234 ;
unsigned long V_235 = V_236 ;
if ( ( V_85 -> V_30 . V_59 & V_109 ) &&
F_111 ( V_85 -> V_121 , V_233 ) ) {
V_232 = true ;
* V_160 = L_22 ;
}
if ( ( V_85 -> V_30 . V_59 & V_204 ) &&
F_111 ( V_85 -> V_30 . V_116 , V_235 ) ) {
V_232 = true ;
* V_160 = L_23 ;
}
return V_232 ;
}
static void F_149 ( struct V_25 * V_26 )
{
struct V_16 * V_13 = V_26 -> V_12 . V_33 ;
struct V_17 * V_18 ;
struct V_1 * V_195 ;
T_5 * V_196 ;
T_1 V_152 ;
char * V_160 = NULL ;
struct V_5 * V_237 ;
struct V_31 * V_85 ;
for ( V_152 = 0 ; V_152 < V_13 -> V_11 ; V_152 ++ ) {
V_18 = & V_13 -> V_22 [ V_152 ] ;
V_196 = & V_13 -> V_197 [ V_152 ] ;
F_35 ( V_196 ) ;
F_110 (tt_common, node_tmp, head,
hash_entry) {
V_85 = F_2 ( V_237 ,
struct V_31 ,
V_30 ) ;
if ( ! F_148 ( V_85 , & V_160 ) )
continue;
F_61 ( V_87 , V_26 ,
L_1 ,
V_85 -> V_30 . V_14 ,
F_62 ( V_85 -> V_30 . V_9 ) ,
V_160 ) ;
F_114 ( & V_237 -> V_6 ) ;
F_24 ( V_85 ) ;
}
F_39 ( V_196 ) ;
}
}
static void F_150 ( struct V_25 * V_26 )
{
struct V_16 * V_13 ;
T_5 * V_196 ;
struct V_5 * V_27 ;
struct V_31 * V_85 ;
struct V_1 * V_195 ;
struct V_17 * V_18 ;
T_1 V_152 ;
if ( ! V_26 -> V_12 . V_33 )
return;
V_13 = V_26 -> V_12 . V_33 ;
for ( V_152 = 0 ; V_152 < V_13 -> V_11 ; V_152 ++ ) {
V_18 = & V_13 -> V_22 [ V_152 ] ;
V_196 = & V_13 -> V_197 [ V_152 ] ;
F_35 ( V_196 ) ;
F_110 (tt_common_entry, node_tmp,
head, hash_entry) {
F_114 ( & V_27 -> V_6 ) ;
V_85 = F_2 ( V_27 ,
struct V_31 ,
V_30 ) ;
F_24 ( V_85 ) ;
}
F_39 ( V_196 ) ;
}
F_115 ( V_13 ) ;
V_26 -> V_12 . V_33 = NULL ;
}
static bool
F_151 ( struct V_24 * V_28 ,
struct V_31 * V_32 )
{
bool V_100 = false ;
if ( V_28 -> V_30 . V_59 & V_115 &&
V_32 -> V_30 . V_59 & V_115 )
V_100 = true ;
if ( V_28 -> V_30 . V_59 & V_125 &&
V_32 -> V_30 . V_59 & V_125 )
V_100 = true ;
return V_100 ;
}
struct V_46 * F_152 ( struct V_25 * V_26 ,
const T_2 * V_238 ,
const T_2 * V_14 ,
unsigned short V_9 )
{
struct V_24 * V_28 = NULL ;
struct V_31 * V_32 = NULL ;
struct V_46 * V_47 = NULL ;
struct V_51 * V_213 ;
if ( V_238 && F_153 ( V_26 , V_9 ) ) {
V_28 = F_12 ( V_26 , V_238 , V_9 ) ;
if ( ! V_28 ||
( V_28 -> V_30 . V_59 & V_107 ) )
goto V_112;
}
V_32 = F_13 ( V_26 , V_14 , V_9 ) ;
if ( ! V_32 )
goto V_112;
if ( V_28 &&
F_151 ( V_28 , V_32 ) )
goto V_112;
F_8 () ;
V_213 = F_128 ( V_26 , V_32 ) ;
if ( V_213 )
V_47 = V_213 -> V_47 ;
if ( V_47 && ! F_10 ( & V_47 -> V_23 ) )
V_47 = NULL ;
F_11 () ;
V_112:
if ( V_32 )
F_24 ( V_32 ) ;
if ( V_28 )
F_19 ( V_28 ) ;
return V_47 ;
}
static T_1 F_154 ( struct V_25 * V_26 ,
struct V_46 * V_47 ,
unsigned short V_9 )
{
struct V_16 * V_13 = V_26 -> V_12 . V_33 ;
struct V_5 * V_237 ;
struct V_31 * V_85 ;
struct V_17 * V_18 ;
T_1 V_152 , V_239 , V_134 = 0 ;
T_2 V_59 ;
T_6 V_240 ;
for ( V_152 = 0 ; V_152 < V_13 -> V_11 ; V_152 ++ ) {
V_18 = & V_13 -> V_22 [ V_152 ] ;
F_8 () ;
F_9 (tt_common, head, hash_entry) {
V_85 = F_2 ( V_237 ,
struct V_31 ,
V_30 ) ;
if ( V_237 -> V_9 != V_9 )
continue;
if ( V_237 -> V_59 & V_109 )
continue;
if ( V_237 -> V_59 & V_204 )
continue;
if ( ! F_119 ( V_85 ,
V_47 ) )
continue;
V_240 = F_48 ( V_237 -> V_9 ) ;
V_239 = F_155 ( 0 , & V_240 , sizeof( V_240 ) ) ;
V_59 = V_237 -> V_59 & V_241 ;
V_239 = F_155 ( V_239 , & V_59 , sizeof( V_59 ) ) ;
V_134 ^= F_155 ( V_239 , V_237 -> V_14 , V_15 ) ;
}
F_11 () ;
}
return V_134 ;
}
static T_1 F_156 ( struct V_25 * V_26 ,
unsigned short V_9 )
{
struct V_16 * V_13 = V_26 -> V_12 . V_29 ;
struct V_5 * V_237 ;
struct V_17 * V_18 ;
T_1 V_152 , V_239 , V_134 = 0 ;
T_2 V_59 ;
T_6 V_240 ;
for ( V_152 = 0 ; V_152 < V_13 -> V_11 ; V_152 ++ ) {
V_18 = & V_13 -> V_22 [ V_152 ] ;
F_8 () ;
F_9 (tt_common, head, hash_entry) {
if ( V_237 -> V_9 != V_9 )
continue;
if ( V_237 -> V_59 & V_114 )
continue;
V_240 = F_48 ( V_237 -> V_9 ) ;
V_239 = F_155 ( 0 , & V_240 , sizeof( V_240 ) ) ;
V_59 = V_237 -> V_59 & V_241 ;
V_239 = F_155 ( V_239 , & V_59 , sizeof( V_59 ) ) ;
V_134 ^= F_155 ( V_239 , V_237 -> V_14 , V_15 ) ;
}
F_11 () ;
}
return V_134 ;
}
static void F_157 ( struct V_37 * V_38 )
{
struct V_242 * V_243 ;
V_243 = F_2 ( V_38 , struct V_242 , V_23 ) ;
F_15 ( V_244 , V_243 ) ;
}
static void F_158 ( struct V_242 * V_243 )
{
F_20 ( & V_243 -> V_23 , F_157 ) ;
}
static void F_159 ( struct V_25 * V_26 )
{
struct V_242 * V_2 ;
struct V_1 * V_58 ;
F_35 ( & V_26 -> V_12 . V_245 ) ;
F_110 (node, safe, &bat_priv->tt.req_list, list) {
F_160 ( & V_2 -> V_50 ) ;
F_158 ( V_2 ) ;
}
F_39 ( & V_26 -> V_12 . V_245 ) ;
}
static void F_161 ( struct V_25 * V_26 ,
struct V_46 * V_47 ,
const void * V_246 ,
T_3 V_247 )
{
F_35 ( & V_47 -> V_248 ) ;
if ( V_247 > 0 ) {
F_85 ( V_47 -> V_246 ) ;
V_47 -> V_247 = 0 ;
V_47 -> V_246 = F_80 ( V_247 , V_64 ) ;
if ( V_47 -> V_246 ) {
memcpy ( V_47 -> V_246 , V_246 , V_247 ) ;
V_47 -> V_247 = V_247 ;
}
}
F_39 ( & V_47 -> V_248 ) ;
}
static void F_162 ( struct V_25 * V_26 )
{
struct V_242 * V_2 ;
struct V_1 * V_58 ;
F_35 ( & V_26 -> V_12 . V_245 ) ;
F_110 (node, safe, &bat_priv->tt.req_list, list) {
if ( F_111 ( V_2 -> V_249 ,
V_250 ) ) {
F_160 ( & V_2 -> V_50 ) ;
F_158 ( V_2 ) ;
}
}
F_39 ( & V_26 -> V_12 . V_245 ) ;
}
static struct V_242 *
F_163 ( struct V_25 * V_26 ,
struct V_46 * V_47 )
{
struct V_242 * V_251 , * V_243 = NULL ;
F_35 ( & V_26 -> V_12 . V_245 ) ;
F_164 (tt_req_node_tmp, &bat_priv->tt.req_list, list) {
if ( F_3 ( V_251 , V_47 ) &&
! F_111 ( V_251 -> V_249 ,
V_250 ) )
goto V_70;
}
V_243 = F_47 ( V_244 , V_64 ) ;
if ( ! V_243 )
goto V_70;
F_72 ( & V_243 -> V_23 ) ;
F_7 ( V_243 -> V_14 , V_47 -> V_203 ) ;
V_243 -> V_249 = V_106 ;
F_73 ( & V_243 -> V_23 ) ;
F_165 ( & V_243 -> V_50 , & V_26 -> V_12 . V_252 ) ;
V_70:
F_39 ( & V_26 -> V_12 . V_245 ) ;
return V_243 ;
}
static bool F_166 ( const void * V_253 , const void * V_254 )
{
const struct V_5 * V_27 = V_253 ;
if ( V_27 -> V_59 & V_114 )
return false ;
return true ;
}
static bool F_167 ( const void * V_253 ,
const void * V_254 )
{
const struct V_5 * V_27 = V_253 ;
const struct V_31 * V_32 ;
const struct V_46 * V_47 = V_254 ;
if ( V_27 -> V_59 & V_109 ||
V_27 -> V_59 & V_204 )
return false ;
V_32 = F_2 ( V_27 ,
struct V_31 ,
V_30 ) ;
return F_119 ( V_32 , V_47 ) ;
}
static void F_168 ( struct V_25 * V_26 ,
struct V_16 * V_13 ,
void * V_255 , T_3 V_75 ,
bool (* F_169)( const void * ,
const void * ) ,
void * V_256 )
{
struct V_5 * V_27 ;
struct V_74 * V_127 ;
struct V_17 * V_18 ;
T_3 V_257 , V_258 = 0 ;
T_1 V_152 ;
V_257 = F_55 ( V_75 ) ;
V_127 = (struct V_74 * ) V_255 ;
F_8 () ;
for ( V_152 = 0 ; V_152 < V_13 -> V_11 ; V_152 ++ ) {
V_18 = & V_13 -> V_22 [ V_152 ] ;
F_9 (tt_common_entry,
head, hash_entry) {
if ( V_257 == V_258 )
break;
if ( ( F_169 ) && ( ! F_169 ( V_27 , V_256 ) ) )
continue;
F_7 ( V_127 -> V_14 , V_27 -> V_14 ) ;
V_127 -> V_59 = V_27 -> V_59 ;
V_127 -> V_9 = F_48 ( V_27 -> V_9 ) ;
memset ( V_127 -> V_66 , 0 ,
sizeof( V_127 -> V_66 ) ) ;
V_258 ++ ;
V_127 ++ ;
}
}
F_11 () ;
}
static bool F_170 ( struct V_46 * V_47 ,
struct V_82 * V_130 ,
T_3 V_76 )
{
struct V_82 * V_259 ;
struct V_48 * V_39 ;
int V_152 , V_260 ;
T_1 V_134 ;
for ( V_152 = 0 ; V_152 < V_76 ; V_152 ++ ) {
V_259 = V_130 + V_152 ;
if ( F_125 ( V_47 -> V_26 ,
V_47 -> V_203 ,
F_171 ( V_259 -> V_9 ) ) )
continue;
V_39 = F_132 ( V_47 ,
F_171 ( V_259 -> V_9 ) ) ;
if ( ! V_39 )
return false ;
V_134 = V_39 -> V_12 . V_134 ;
F_38 ( V_39 ) ;
if ( V_134 != F_172 ( V_259 -> V_134 ) )
return false ;
}
F_8 () ;
V_260 = 0 ;
F_9 (vlan, &orig_node->vlan_list, list)
V_260 ++ ;
F_11 () ;
if ( V_260 > V_76 )
return false ;
return true ;
}
static void F_173 ( struct V_25 * V_26 )
{
struct V_44 * V_39 ;
F_8 () ;
F_9 (vlan, &bat_priv->softif_vlan_list, list) {
V_39 -> V_12 . V_134 = F_156 ( V_26 , V_39 -> V_9 ) ;
}
F_11 () ;
}
static void F_174 ( struct V_25 * V_26 ,
struct V_46 * V_47 )
{
struct V_48 * V_39 ;
T_1 V_134 ;
F_8 () ;
F_9 (vlan, &orig_node->vlan_list, list) {
if ( F_125 ( V_26 , V_47 -> V_203 ,
V_39 -> V_9 ) )
continue;
V_134 = F_154 ( V_26 , V_47 , V_39 -> V_9 ) ;
V_39 -> V_12 . V_134 = V_134 ;
}
F_11 () ;
}
static bool F_175 ( struct V_25 * V_26 ,
struct V_46 * V_261 ,
T_2 V_132 ,
struct V_82 * V_130 ,
T_3 V_76 , bool V_262 )
{
struct V_81 * V_263 = NULL ;
struct V_242 * V_243 = NULL ;
struct V_82 * V_264 ;
struct V_95 * V_151 ;
bool V_100 = false ;
int V_152 , V_11 ;
V_151 = F_106 ( V_26 ) ;
if ( ! V_151 )
goto V_112;
V_243 = F_163 ( V_26 , V_261 ) ;
if ( ! V_243 )
goto V_112;
V_11 = sizeof( * V_263 ) + sizeof( * V_264 ) * V_76 ;
V_263 = F_86 ( V_11 , V_64 ) ;
if ( ! V_263 )
goto V_112;
V_263 -> V_59 = V_265 ;
V_263 -> V_132 = V_132 ;
V_263 -> V_76 = F_48 ( V_76 ) ;
V_264 = (struct V_82 * ) ( V_263 + 1 ) ;
for ( V_152 = 0 ; V_152 < V_76 ; V_152 ++ ) {
V_264 -> V_9 = V_130 -> V_9 ;
V_264 -> V_134 = V_130 -> V_134 ;
V_264 ++ ;
V_130 ++ ;
}
if ( V_262 )
V_263 -> V_59 |= V_266 ;
F_61 ( V_87 , V_26 , L_24 ,
V_261 -> V_203 , V_262 ? 'F' : '.' ) ;
F_176 ( V_26 , V_267 ) ;
F_177 ( V_26 , V_151 -> V_149 -> V_117 ,
V_261 -> V_203 , V_145 , 1 ,
V_263 , V_11 ) ;
V_100 = true ;
V_112:
if ( V_151 )
F_77 ( V_151 ) ;
if ( V_100 && V_243 ) {
F_35 ( & V_26 -> V_12 . V_245 ) ;
if ( ! F_36 ( & V_243 -> V_50 ) ) {
F_160 ( & V_243 -> V_50 ) ;
F_158 ( V_243 ) ;
}
F_39 ( & V_26 -> V_12 . V_245 ) ;
}
if ( V_243 )
F_158 ( V_243 ) ;
F_85 ( V_263 ) ;
return V_100 ;
}
static bool F_178 ( struct V_25 * V_26 ,
struct V_81 * V_126 ,
T_2 * V_268 , T_2 * V_269 )
{
struct V_46 * V_270 ;
struct V_46 * V_271 = NULL ;
struct V_74 * V_127 ;
struct V_81 * V_263 = NULL ;
struct V_82 * V_130 ;
bool V_100 = false , V_262 ;
T_2 V_272 , V_273 ;
T_3 V_129 ;
T_4 V_75 ;
F_61 ( V_87 , V_26 ,
L_25 ,
V_268 , V_126 -> V_132 , V_269 ,
( ( V_126 -> V_59 & V_266 ) ? 'F' : '.' ) ) ;
V_270 = F_179 ( V_26 , V_269 ) ;
if ( ! V_270 )
goto V_112;
V_271 = F_179 ( V_26 , V_268 ) ;
if ( ! V_271 )
goto V_112;
V_272 = ( T_2 ) F_26 ( & V_270 -> V_133 ) ;
V_273 = V_126 -> V_132 ;
V_130 = (struct V_82 * ) ( V_126 + 1 ) ;
if ( V_272 != V_273 ||
! F_170 ( V_270 , V_130 ,
F_171 ( V_126 -> V_76 ) ) )
goto V_112;
if ( V_126 -> V_59 & V_266 ||
! V_270 -> V_246 )
V_262 = true ;
else
V_262 = false ;
if ( ! V_262 ) {
F_35 ( & V_270 -> V_248 ) ;
V_75 = V_270 -> V_247 ;
V_129 = F_79 ( V_270 ,
& V_263 ,
& V_127 ,
& V_75 ) ;
if ( ! V_75 )
goto V_70;
memcpy ( V_127 , V_270 -> V_246 ,
V_270 -> V_247 ) ;
F_39 ( & V_270 -> V_248 ) ;
} else {
V_75 = - 1 ;
V_129 = F_79 ( V_270 ,
& V_263 ,
& V_127 ,
& V_75 ) ;
if ( ! V_75 )
goto V_112;
F_168 ( V_26 , V_26 -> V_12 . V_33 ,
V_127 , V_75 ,
F_167 ,
V_270 ) ;
}
V_75 = sizeof( struct V_79 ) + V_129 ;
if ( V_75 > F_26 ( & V_26 -> V_99 ) ) {
F_70 ( V_111 , V_26 -> V_89 ,
L_26 ,
V_271 -> V_203 ) ;
goto V_112;
}
V_263 -> V_59 = V_274 ;
V_263 -> V_132 = V_273 ;
if ( V_262 )
V_263 -> V_59 |= V_266 ;
F_61 ( V_87 , V_26 ,
L_27 ,
V_271 -> V_203 , V_270 -> V_203 ,
V_262 ? 'F' : '.' , V_273 ) ;
F_176 ( V_26 , V_275 ) ;
F_177 ( V_26 , V_270 -> V_203 ,
V_268 , V_145 , 1 , V_263 ,
V_129 ) ;
V_100 = true ;
goto V_112;
V_70:
F_39 ( & V_270 -> V_248 ) ;
V_112:
if ( V_271 )
F_44 ( V_271 ) ;
if ( V_270 )
F_44 ( V_270 ) ;
F_85 ( V_263 ) ;
return V_100 ;
}
static bool F_180 ( struct V_25 * V_26 ,
struct V_81 * V_126 ,
T_2 * V_268 )
{
struct V_81 * V_263 = NULL ;
struct V_95 * V_151 = NULL ;
struct V_74 * V_127 ;
struct V_46 * V_47 ;
T_2 V_276 , V_273 ;
T_3 V_129 ;
bool V_262 ;
T_4 V_75 ;
F_61 ( V_87 , V_26 ,
L_28 ,
V_268 , V_126 -> V_132 ,
( ( V_126 -> V_59 & V_266 ) ? 'F' : '.' ) ) ;
F_35 ( & V_26 -> V_12 . V_277 ) ;
V_276 = ( T_2 ) F_26 ( & V_26 -> V_12 . V_113 ) ;
V_273 = V_126 -> V_132 ;
V_47 = F_179 ( V_26 , V_268 ) ;
if ( ! V_47 )
goto V_112;
V_151 = F_106 ( V_26 ) ;
if ( ! V_151 )
goto V_112;
if ( V_126 -> V_59 & V_266 || V_276 != V_273 ||
! V_26 -> V_12 . V_143 )
V_262 = true ;
else
V_262 = false ;
if ( ! V_262 ) {
F_35 ( & V_26 -> V_12 . V_142 ) ;
V_75 = V_26 -> V_12 . V_144 ;
V_129 = F_82 ( V_26 ,
& V_263 ,
& V_127 ,
& V_75 ) ;
if ( ! V_75 || ! V_129 )
goto V_70;
memcpy ( V_127 , V_26 -> V_12 . V_143 ,
V_26 -> V_12 . V_144 ) ;
F_39 ( & V_26 -> V_12 . V_142 ) ;
} else {
V_273 = ( T_2 ) F_26 ( & V_26 -> V_12 . V_113 ) ;
V_75 = - 1 ;
V_129 = F_82 ( V_26 ,
& V_263 ,
& V_127 ,
& V_75 ) ;
if ( ! V_75 || ! V_129 )
goto V_112;
F_168 ( V_26 , V_26 -> V_12 . V_29 ,
V_127 , V_75 ,
F_166 , NULL ) ;
}
V_263 -> V_59 = V_274 ;
V_263 -> V_132 = V_273 ;
if ( V_262 )
V_263 -> V_59 |= V_266 ;
F_61 ( V_87 , V_26 ,
L_29 ,
V_47 -> V_203 , V_262 ? 'F' : '.' , V_273 ) ;
F_176 ( V_26 , V_275 ) ;
F_177 ( V_26 , V_151 -> V_149 -> V_117 ,
V_268 , V_145 , 1 , V_263 ,
V_129 ) ;
goto V_112;
V_70:
F_39 ( & V_26 -> V_12 . V_142 ) ;
V_112:
F_39 ( & V_26 -> V_12 . V_277 ) ;
if ( V_47 )
F_44 ( V_47 ) ;
if ( V_151 )
F_77 ( V_151 ) ;
F_85 ( V_263 ) ;
return true ;
}
static bool F_181 ( struct V_25 * V_26 ,
struct V_81 * V_126 ,
T_2 * V_268 , T_2 * V_269 )
{
if ( F_182 ( V_26 , V_269 ) )
return F_180 ( V_26 , V_126 , V_268 ) ;
return F_178 ( V_26 , V_126 , V_268 ,
V_269 ) ;
}
static void F_183 ( struct V_25 * V_26 ,
struct V_46 * V_47 ,
struct V_74 * V_127 ,
T_3 V_278 , T_2 V_132 )
{
int V_152 ;
int V_279 ;
for ( V_152 = 0 ; V_152 < V_278 ; V_152 ++ ) {
if ( ( V_127 + V_152 ) -> V_59 & V_67 ) {
V_279 = ( V_127 + V_152 ) -> V_59 & V_109 ;
F_144 ( V_26 , V_47 ,
( V_127 + V_152 ) -> V_14 ,
F_171 ( ( V_127 + V_152 ) -> V_9 ) ,
L_30 ,
V_279 ) ;
} else {
if ( ! F_124 ( V_26 , V_47 ,
( V_127 + V_152 ) -> V_14 ,
F_171 ( ( V_127 + V_152 ) -> V_9 ) ,
( V_127 + V_152 ) -> V_59 , V_132 ) )
return;
}
}
F_184 ( V_230 , & V_47 -> V_231 ) ;
}
static void F_185 ( struct V_25 * V_26 ,
struct V_74 * V_127 ,
T_2 V_132 , T_2 * V_280 ,
T_3 V_45 )
{
struct V_46 * V_47 ;
V_47 = F_179 ( V_26 , V_280 ) ;
if ( ! V_47 )
goto V_112;
F_146 ( V_26 , V_47 , - 1 ,
L_31 ) ;
F_183 ( V_26 , V_47 , V_127 , V_45 ,
V_132 ) ;
F_35 ( & V_47 -> V_248 ) ;
F_85 ( V_47 -> V_246 ) ;
V_47 -> V_247 = 0 ;
V_47 -> V_246 = NULL ;
F_39 ( & V_47 -> V_248 ) ;
F_84 ( & V_47 -> V_133 , V_132 ) ;
V_112:
if ( V_47 )
F_44 ( V_47 ) ;
}
static void F_186 ( struct V_25 * V_26 ,
struct V_46 * V_47 ,
T_3 V_278 , T_2 V_132 ,
struct V_74 * V_127 )
{
F_183 ( V_26 , V_47 , V_127 ,
V_278 , V_132 ) ;
F_161 ( V_26 , V_47 , V_127 ,
F_54 ( V_278 ) ) ;
F_84 ( & V_47 -> V_133 , V_132 ) ;
}
bool F_187 ( struct V_25 * V_26 , const T_2 * V_14 ,
unsigned short V_9 )
{
struct V_24 * V_28 ;
bool V_100 = false ;
V_28 = F_12 ( V_26 , V_14 , V_9 ) ;
if ( ! V_28 )
goto V_112;
if ( ( V_28 -> V_30 . V_59 & V_107 ) ||
( V_28 -> V_30 . V_59 & V_109 ) )
goto V_112;
V_100 = true ;
V_112:
if ( V_28 )
F_19 ( V_28 ) ;
return V_100 ;
}
static void F_188 ( struct V_25 * V_26 ,
struct V_81 * V_126 ,
T_2 * V_280 , T_3 V_45 )
{
struct V_242 * V_2 ;
struct V_1 * V_58 ;
struct V_46 * V_47 = NULL ;
struct V_74 * V_127 ;
T_2 * V_281 = ( T_2 * ) V_126 ;
T_3 V_128 ;
F_61 ( V_87 , V_26 ,
L_32 ,
V_280 , V_126 -> V_132 , V_45 ,
( ( V_126 -> V_59 & V_266 ) ? 'F' : '.' ) ) ;
V_47 = F_179 ( V_26 , V_280 ) ;
if ( ! V_47 )
goto V_112;
F_35 ( & V_47 -> V_282 ) ;
V_128 = sizeof( struct V_82 ) ;
V_128 *= F_171 ( V_126 -> V_76 ) ;
V_128 += sizeof( * V_126 ) ;
V_281 += V_128 ;
V_127 = (struct V_74 * ) V_281 ;
if ( V_126 -> V_59 & V_266 ) {
F_185 ( V_26 , V_127 , V_126 -> V_132 ,
V_280 , V_45 ) ;
} else {
F_186 ( V_26 , V_47 , V_45 ,
V_126 -> V_132 , V_127 ) ;
}
F_174 ( V_26 , V_47 ) ;
F_39 ( & V_47 -> V_282 ) ;
F_35 ( & V_26 -> V_12 . V_245 ) ;
F_110 (node, safe, &bat_priv->tt.req_list, list) {
if ( ! F_3 ( V_2 -> V_14 , V_280 ) )
continue;
F_160 ( & V_2 -> V_50 ) ;
F_158 ( V_2 ) ;
}
F_39 ( & V_26 -> V_12 . V_245 ) ;
V_112:
if ( V_47 )
F_44 ( V_47 ) ;
}
static void F_189 ( struct V_25 * V_26 )
{
struct V_283 * V_2 , * V_58 ;
F_35 ( & V_26 -> V_12 . V_284 ) ;
F_49 (node, safe, &bat_priv->tt.roam_list, list) {
F_50 ( & V_2 -> V_50 ) ;
F_15 ( V_285 , V_2 ) ;
}
F_39 ( & V_26 -> V_12 . V_284 ) ;
}
static void F_190 ( struct V_25 * V_26 )
{
struct V_283 * V_2 , * V_58 ;
F_35 ( & V_26 -> V_12 . V_284 ) ;
F_49 (node, safe, &bat_priv->tt.roam_list, list) {
if ( ! F_111 ( V_2 -> V_286 ,
V_287 ) )
continue;
F_50 ( & V_2 -> V_50 ) ;
F_15 ( V_285 , V_2 ) ;
}
F_39 ( & V_26 -> V_12 . V_284 ) ;
}
static bool F_191 ( struct V_25 * V_26 , T_2 * V_288 )
{
struct V_283 * V_289 ;
bool V_100 = false ;
F_35 ( & V_26 -> V_12 . V_284 ) ;
F_192 (tt_roam_node, &bat_priv->tt.roam_list, list) {
if ( ! F_3 ( V_289 -> V_14 , V_288 ) )
continue;
if ( F_111 ( V_289 -> V_286 ,
V_287 ) )
continue;
if ( ! F_193 ( & V_289 -> V_290 ) )
goto V_70;
V_100 = true ;
break;
}
if ( ! V_100 ) {
V_289 = F_47 ( V_285 ,
V_64 ) ;
if ( ! V_289 )
goto V_70;
V_289 -> V_286 = V_106 ;
F_84 ( & V_289 -> V_290 ,
V_291 - 1 ) ;
F_7 ( V_289 -> V_14 , V_288 ) ;
F_194 ( & V_289 -> V_50 , & V_26 -> V_12 . V_292 ) ;
V_100 = true ;
}
V_70:
F_39 ( & V_26 -> V_12 . V_284 ) ;
return V_100 ;
}
static void F_76 ( struct V_25 * V_26 , T_2 * V_288 ,
unsigned short V_9 ,
struct V_46 * V_47 )
{
struct V_95 * V_151 ;
struct V_293 V_294 ;
V_151 = F_106 ( V_26 ) ;
if ( ! V_151 )
goto V_112;
if ( ! F_191 ( V_26 , V_288 ) )
goto V_112;
F_61 ( V_87 , V_26 ,
L_33 ,
V_47 -> V_203 , V_288 , F_62 ( V_9 ) ) ;
F_176 ( V_26 , V_295 ) ;
memcpy ( V_294 . V_288 , V_288 , sizeof( V_294 . V_288 ) ) ;
V_294 . V_9 = F_48 ( V_9 ) ;
F_177 ( V_26 , V_151 -> V_149 -> V_117 ,
V_47 -> V_203 , V_296 , 1 ,
& V_294 , sizeof( V_294 ) ) ;
V_112:
if ( V_151 )
F_77 ( V_151 ) ;
}
static void F_195 ( struct V_297 * V_298 )
{
struct V_299 * V_299 ;
struct V_300 * V_301 ;
struct V_25 * V_26 ;
V_299 = F_196 ( V_298 ) ;
V_301 = F_2 ( V_299 , struct V_300 , V_298 ) ;
V_26 = F_2 ( V_301 , struct V_25 , V_12 ) ;
F_112 ( V_26 , V_302 ) ;
F_149 ( V_26 ) ;
F_162 ( V_26 ) ;
F_190 ( V_26 ) ;
F_197 ( V_303 , & V_26 -> V_12 . V_298 ,
F_198 ( V_304 ) ) ;
}
void F_199 ( struct V_25 * V_26 )
{
F_200 ( V_26 , V_145 , 1 ) ;
F_201 ( V_26 , V_145 , 1 ) ;
F_202 ( & V_26 -> V_12 . V_298 ) ;
F_113 ( V_26 ) ;
F_150 ( V_26 ) ;
F_159 ( V_26 ) ;
F_117 ( V_26 ) ;
F_189 ( V_26 ) ;
F_85 ( V_26 -> V_12 . V_143 ) ;
}
static void F_203 ( struct V_25 * V_26 , T_3 V_59 ,
bool V_305 , bool V_41 )
{
struct V_16 * V_13 = V_26 -> V_12 . V_29 ;
struct V_5 * V_27 ;
struct V_17 * V_18 ;
T_1 V_152 ;
if ( ! V_13 )
return;
for ( V_152 = 0 ; V_152 < V_13 -> V_11 ; V_152 ++ ) {
V_18 = & V_13 -> V_22 [ V_152 ] ;
F_8 () ;
F_9 (tt_common_entry,
head, hash_entry) {
if ( V_305 ) {
if ( ( V_27 -> V_59 & V_59 ) == V_59 )
continue;
V_27 -> V_59 |= V_59 ;
} else {
if ( ! ( V_27 -> V_59 & V_59 ) )
continue;
V_27 -> V_59 &= ~ V_59 ;
}
if ( ! V_41 )
continue;
F_30 ( V_26 ,
V_27 -> V_9 ) ;
}
F_11 () ;
}
}
static void F_204 ( struct V_25 * V_26 )
{
struct V_16 * V_13 = V_26 -> V_12 . V_29 ;
struct V_5 * V_237 ;
struct V_24 * V_92 ;
struct V_1 * V_195 ;
struct V_17 * V_18 ;
T_5 * V_196 ;
T_1 V_152 ;
if ( ! V_13 )
return;
for ( V_152 = 0 ; V_152 < V_13 -> V_11 ; V_152 ++ ) {
V_18 = & V_13 -> V_22 [ V_152 ] ;
V_196 = & V_13 -> V_197 [ V_152 ] ;
F_35 ( V_196 ) ;
F_110 (tt_common, node_tmp, head,
hash_entry) {
if ( ! ( V_237 -> V_59 & V_107 ) )
continue;
F_61 ( V_87 , V_26 ,
L_34 ,
V_237 -> V_14 ,
F_62 ( V_237 -> V_9 ) ) ;
F_31 ( V_26 , V_237 -> V_9 ) ;
F_114 ( & V_237 -> V_6 ) ;
V_92 = F_2 ( V_237 ,
struct V_24 ,
V_30 ) ;
F_19 ( V_92 ) ;
}
F_39 ( V_196 ) ;
}
}
static void F_205 ( struct V_25 * V_26 )
{
F_141 ( & V_26 -> V_12 . V_277 ) ;
if ( F_26 ( & V_26 -> V_12 . V_72 ) < 1 ) {
if ( ! F_193 ( & V_26 -> V_12 . V_306 ) )
F_83 ( V_26 ) ;
return;
}
F_203 ( V_26 , V_114 , false , true ) ;
F_204 ( V_26 ) ;
F_173 ( V_26 ) ;
F_53 ( & V_26 -> V_12 . V_113 ) ;
F_61 ( V_87 , V_26 ,
L_35 ,
( T_2 ) F_26 ( & V_26 -> V_12 . V_113 ) ) ;
F_84 ( & V_26 -> V_12 . V_306 , V_307 ) ;
F_83 ( V_26 ) ;
}
void F_206 ( struct V_25 * V_26 )
{
F_35 ( & V_26 -> V_12 . V_277 ) ;
F_205 ( V_26 ) ;
F_39 ( & V_26 -> V_12 . V_277 ) ;
}
bool F_207 ( struct V_25 * V_26 , T_2 * V_238 , T_2 * V_308 ,
unsigned short V_9 )
{
struct V_24 * V_28 ;
struct V_31 * V_32 ;
struct V_44 * V_39 ;
bool V_100 = false ;
V_39 = F_28 ( V_26 , V_9 ) ;
if ( ! V_39 )
return false ;
if ( ! F_26 ( & V_39 -> V_309 ) )
goto V_310;
V_28 = F_12 ( V_26 , V_308 , V_9 ) ;
if ( ! V_28 )
goto V_310;
V_32 = F_13 ( V_26 , V_238 , V_9 ) ;
if ( ! V_32 )
goto V_311;
if ( F_151 ( V_28 , V_32 ) )
V_100 = true ;
F_24 ( V_32 ) ;
V_311:
F_19 ( V_28 ) ;
V_310:
F_17 ( V_39 ) ;
return V_100 ;
}
static void F_208 ( struct V_25 * V_26 ,
struct V_46 * V_47 ,
const void * V_246 , T_3 V_312 ,
struct V_74 * V_127 ,
T_3 V_278 , T_2 V_132 )
{
T_2 V_272 = ( T_2 ) F_26 ( & V_47 -> V_133 ) ;
struct V_82 * V_130 ;
bool V_262 = true ;
bool V_313 ;
V_130 = (struct V_82 * ) V_246 ;
V_313 = F_209 ( V_230 ,
& V_47 -> V_231 ) ;
if ( ( ! V_313 && V_132 == 1 ) || V_132 - V_272 == 1 ) {
if ( ! V_278 ) {
V_262 = false ;
goto V_314;
}
F_35 ( & V_47 -> V_282 ) ;
F_186 ( V_26 , V_47 , V_278 ,
V_132 , V_127 ) ;
F_174 ( V_26 , V_47 ) ;
F_39 ( & V_47 -> V_282 ) ;
if ( ! F_170 ( V_47 , V_130 ,
V_312 ) )
goto V_314;
} else {
if ( ! V_313 || V_132 != V_272 ||
! F_170 ( V_47 , V_130 ,
V_312 ) ) {
V_314:
F_61 ( V_87 , V_26 ,
L_36 ,
V_47 -> V_203 , V_132 , V_272 ,
V_278 ) ;
F_175 ( V_26 , V_47 , V_132 ,
V_130 , V_312 ,
V_262 ) ;
return;
}
}
}
bool F_210 ( struct V_25 * V_26 ,
T_2 * V_14 , unsigned short V_9 )
{
struct V_31 * V_32 ;
bool V_100 = false ;
V_32 = F_13 ( V_26 , V_14 , V_9 ) ;
if ( ! V_32 )
goto V_112;
V_100 = V_32 -> V_30 . V_59 & V_109 ;
F_24 ( V_32 ) ;
V_112:
return V_100 ;
}
bool F_211 ( struct V_25 * V_26 ,
T_2 * V_14 , unsigned short V_9 )
{
struct V_24 * V_28 ;
bool V_100 = false ;
V_28 = F_12 ( V_26 , V_14 , V_9 ) ;
if ( ! V_28 )
goto V_112;
V_100 = V_28 -> V_30 . V_59 & V_109 ;
F_19 ( V_28 ) ;
V_112:
return V_100 ;
}
bool F_212 ( struct V_25 * V_26 ,
struct V_46 * V_47 ,
const unsigned char * V_14 ,
unsigned short V_9 )
{
bool V_100 = false ;
if ( ! F_124 ( V_26 , V_47 , V_14 , V_9 ,
V_204 ,
F_26 ( & V_47 -> V_133 ) ) )
goto V_112;
F_61 ( V_87 , V_26 ,
L_37 ,
V_14 , F_62 ( V_9 ) , V_47 -> V_203 ) ;
V_100 = true ;
V_112:
return V_100 ;
}
void F_213 ( struct V_88 * V_89 )
{
struct V_25 * V_26 = F_65 ( V_89 ) ;
int V_99 = F_26 ( & V_26 -> V_99 ) ;
int V_98 , V_194 = V_302 / 2 ;
bool V_315 = false ;
F_35 ( & V_26 -> V_12 . V_277 ) ;
while ( true ) {
V_98 = F_56 ( V_26 ) ;
if ( V_99 >= V_98 )
break;
F_112 ( V_26 , V_194 ) ;
F_204 ( V_26 ) ;
V_194 /= 2 ;
V_315 = true ;
F_70 ( V_111 , V_89 ,
L_38 ,
V_99 ) ;
}
if ( V_315 )
F_205 ( V_26 ) ;
F_39 ( & V_26 -> V_12 . V_277 ) ;
}
static void F_214 ( struct V_25 * V_26 ,
struct V_46 * V_203 ,
T_2 V_59 , void * V_316 ,
T_3 V_317 )
{
struct V_82 * V_130 ;
struct V_74 * V_127 ;
struct V_81 * V_126 ;
T_3 V_45 , V_76 ;
if ( V_317 < sizeof( * V_126 ) )
return;
V_126 = (struct V_81 * ) V_316 ;
V_317 -= sizeof( * V_126 ) ;
V_76 = F_171 ( V_126 -> V_76 ) ;
if ( V_317 < sizeof( * V_130 ) * V_76 )
return;
V_130 = (struct V_82 * ) ( V_126 + 1 ) ;
V_127 = (struct V_74 * ) ( V_130 + V_76 ) ;
V_317 -= sizeof( * V_130 ) * V_76 ;
V_45 = F_55 ( V_317 ) ;
F_208 ( V_26 , V_203 , V_130 , V_76 , V_127 ,
V_45 , V_126 -> V_132 ) ;
}
static int F_215 ( struct V_25 * V_26 ,
T_2 * V_238 , T_2 * V_308 ,
void * V_316 ,
T_3 V_317 )
{
struct V_81 * V_126 ;
T_3 V_318 , V_258 ;
char V_319 ;
bool V_100 ;
if ( V_317 < sizeof( * V_126 ) )
return V_320 ;
V_126 = (struct V_81 * ) V_316 ;
V_317 -= sizeof( * V_126 ) ;
V_318 = sizeof( struct V_82 ) ;
V_318 *= F_171 ( V_126 -> V_76 ) ;
if ( V_317 < V_318 )
return V_320 ;
V_317 -= V_318 ;
V_258 = F_55 ( V_317 ) ;
switch ( V_126 -> V_59 & V_321 ) {
case V_265 :
F_176 ( V_26 , V_322 ) ;
V_100 = F_181 ( V_26 , V_126 , V_238 , V_308 ) ;
if ( ! V_100 ) {
if ( V_126 -> V_59 & V_266 )
V_319 = 'F' ;
else
V_319 = '.' ;
F_61 ( V_87 , V_26 ,
L_39 ,
V_308 , V_319 ) ;
return V_323 ;
}
break;
case V_274 :
F_176 ( V_26 , V_324 ) ;
if ( F_182 ( V_26 , V_308 ) ) {
F_188 ( V_26 , V_126 ,
V_238 , V_258 ) ;
return V_320 ;
}
if ( V_126 -> V_59 & V_266 )
V_319 = 'F' ;
else
V_319 = '.' ;
F_61 ( V_87 , V_26 ,
L_40 , V_308 , V_319 ) ;
return V_323 ;
}
return V_320 ;
}
static int F_216 ( struct V_25 * V_26 ,
T_2 * V_238 , T_2 * V_308 ,
void * V_316 ,
T_3 V_317 )
{
struct V_293 * V_325 ;
struct V_46 * V_47 = NULL ;
if ( ! F_182 ( V_26 , V_308 ) )
return V_323 ;
if ( V_317 < sizeof( * V_325 ) )
goto V_112;
V_47 = F_179 ( V_26 , V_238 ) ;
if ( ! V_47 )
goto V_112;
F_176 ( V_26 , V_326 ) ;
V_325 = (struct V_293 * ) V_316 ;
F_61 ( V_87 , V_26 ,
L_41 ,
V_238 , V_325 -> V_288 ) ;
F_124 ( V_26 , V_47 , V_325 -> V_288 ,
F_171 ( V_325 -> V_9 ) , V_109 ,
F_26 ( & V_47 -> V_133 ) + 1 ) ;
V_112:
if ( V_47 )
F_44 ( V_47 ) ;
return V_320 ;
}
int F_217 ( struct V_25 * V_26 )
{
int V_100 ;
F_218 ( ! ( V_241 & V_122 ) ) ;
V_100 = F_57 ( V_26 ) ;
if ( V_100 < 0 )
return V_100 ;
V_100 = F_116 ( V_26 ) ;
if ( V_100 < 0 )
return V_100 ;
F_219 ( V_26 , F_214 ,
F_215 ,
V_145 , 1 , V_119 ) ;
F_219 ( V_26 , NULL ,
F_216 ,
V_296 , 1 , V_119 ) ;
F_220 ( & V_26 -> V_12 . V_298 , F_195 ) ;
F_197 ( V_303 , & V_26 -> V_12 . V_298 ,
F_198 ( V_304 ) ) ;
return 1 ;
}
bool F_221 ( struct V_25 * V_26 ,
const T_2 * V_14 , unsigned short V_9 )
{
struct V_31 * V_12 ;
bool V_100 ;
V_12 = F_13 ( V_26 , V_14 , V_9 ) ;
if ( ! V_12 )
return false ;
V_100 = V_12 -> V_30 . V_59 & V_125 ;
F_24 ( V_12 ) ;
return V_100 ;
}
int T_7 F_222 ( void )
{
T_8 V_327 = sizeof( struct V_24 ) ;
T_8 V_328 = sizeof( struct V_31 ) ;
T_8 V_329 = sizeof( struct V_51 ) ;
T_8 V_330 = sizeof( struct V_55 ) ;
T_8 V_331 = sizeof( struct V_242 ) ;
T_8 V_332 = sizeof( struct V_283 ) ;
V_36 = F_223 ( L_42 , V_327 , 0 ,
V_333 , NULL ) ;
if ( ! V_36 )
return - V_83 ;
V_40 = F_223 ( L_43 , V_328 , 0 ,
V_333 , NULL ) ;
if ( ! V_40 )
goto V_334;
V_53 = F_223 ( L_44 ,
V_329 , 0 ,
V_333 , NULL ) ;
if ( ! V_53 )
goto V_335;
V_63 = F_223 ( L_45 ,
V_330 , 0 ,
V_333 , NULL ) ;
if ( ! V_63 )
goto V_336;
V_244 = F_223 ( L_46 ,
V_331 , 0 ,
V_333 , NULL ) ;
if ( ! V_244 )
goto V_337;
V_285 = F_223 ( L_47 ,
V_332 , 0 ,
V_333 , NULL ) ;
if ( ! V_285 )
goto V_338;
return 0 ;
V_338:
F_224 ( V_244 ) ;
V_244 = NULL ;
V_337:
F_224 ( V_63 ) ;
V_63 = NULL ;
V_336:
F_224 ( V_53 ) ;
V_53 = NULL ;
V_335:
F_224 ( V_40 ) ;
V_40 = NULL ;
V_334:
F_224 ( V_36 ) ;
V_36 = NULL ;
return - V_83 ;
}
void F_225 ( void )
{
F_224 ( V_36 ) ;
F_224 ( V_40 ) ;
F_224 ( V_53 ) ;
F_224 ( V_63 ) ;
F_224 ( V_244 ) ;
F_224 ( V_285 ) ;
}

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
F_120 ( struct V_31 * V_85 )
{
struct V_51 * V_52 ;
const struct V_17 * V_18 ;
T_3 V_59 = V_119 ;
F_8 () ;
V_18 = & V_85 -> V_120 ;
F_9 (orig_entry, head, list)
V_59 |= V_52 -> V_59 ;
F_11 () ;
V_59 |= V_85 -> V_30 . V_59 & ( ~ V_201 ) ;
V_85 -> V_30 . V_59 = V_59 ;
}
static void
F_121 ( struct V_31 * V_85 ,
struct V_46 * V_47 , int V_132 ,
T_2 V_59 )
{
struct V_51 * V_52 ;
V_52 = F_118 ( V_85 , V_47 ) ;
if ( V_52 ) {
V_52 -> V_132 = V_132 ;
V_52 -> V_59 = V_59 ;
goto V_202;
}
V_52 = F_122 ( V_53 , V_64 ) ;
if ( ! V_52 )
goto V_112;
F_123 ( & V_52 -> V_50 ) ;
F_73 ( & V_47 -> V_23 ) ;
F_40 ( V_47 , V_85 -> V_30 . V_9 ) ;
V_52 -> V_47 = V_47 ;
V_52 -> V_132 = V_132 ;
V_52 -> V_59 = V_59 ;
F_72 ( & V_52 -> V_23 ) ;
F_35 ( & V_85 -> V_196 ) ;
F_73 ( & V_52 -> V_23 ) ;
F_124 ( & V_52 -> V_50 ,
& V_85 -> V_120 ) ;
F_39 ( & V_85 -> V_196 ) ;
F_53 ( & V_85 -> V_42 ) ;
V_202:
F_120 ( V_85 ) ;
V_112:
if ( V_52 )
F_45 ( V_52 ) ;
}
static bool F_125 ( struct V_25 * V_26 ,
struct V_46 * V_47 ,
const unsigned char * V_203 ,
unsigned short V_9 , T_3 V_59 , T_2 V_132 )
{
struct V_31 * V_32 ;
struct V_24 * V_28 ;
bool V_100 = false ;
int V_97 ;
struct V_5 * V_30 ;
T_3 V_204 ;
if ( F_126 ( V_26 , V_47 -> V_205 , V_9 ) )
return true ;
V_32 = F_13 ( V_26 , V_203 , V_9 ) ;
V_28 = F_12 ( V_26 , V_203 , V_9 ) ;
if ( ( V_59 & V_206 ) && V_28 &&
! ( V_28 -> V_30 . V_59 & V_114 ) )
goto V_112;
if ( ! V_32 ) {
V_32 = F_122 ( V_40 ,
V_64 ) ;
if ( ! V_32 )
goto V_112;
V_30 = & V_32 -> V_30 ;
F_7 ( V_30 -> V_14 , V_203 ) ;
V_30 -> V_9 = V_9 ;
V_30 -> V_59 = V_59 ;
V_32 -> V_121 = 0 ;
if ( V_59 & V_109 )
V_32 -> V_121 = V_106 ;
F_72 ( & V_30 -> V_23 ) ;
V_30 -> V_116 = V_106 ;
F_127 ( & V_32 -> V_120 ) ;
F_84 ( & V_32 -> V_42 , 0 ) ;
F_128 ( & V_32 -> V_196 ) ;
F_73 ( & V_30 -> V_23 ) ;
V_97 = F_74 ( V_26 -> V_12 . V_33 ,
F_1 ,
F_4 , V_30 ,
& V_30 -> V_6 ) ;
if ( F_75 ( V_97 != 0 ) ) {
F_24 ( V_32 ) ;
goto V_207;
}
} else {
V_30 = & V_32 -> V_30 ;
if ( V_59 & V_206 ) {
if ( ! ( V_30 -> V_59 & V_206 ) )
goto V_112;
if ( F_119 ( V_32 ,
V_47 ) )
goto V_207;
F_23 ( V_32 ) ;
goto V_208;
}
if ( V_30 -> V_59 & V_206 ) {
F_23 ( V_32 ) ;
V_30 -> V_59 &= ~ V_206 ;
}
V_30 -> V_59 |= V_59 & ( ~ V_201 ) ;
if ( V_30 -> V_59 & V_109 ) {
F_23 ( V_32 ) ;
V_30 -> V_59 &= ~ V_109 ;
V_32 -> V_121 = 0 ;
}
}
V_208:
F_121 ( V_32 , V_47 , V_132 ,
V_59 & V_201 ) ;
F_61 ( V_87 , V_26 ,
L_13 ,
V_30 -> V_14 , F_62 ( V_30 -> V_9 ) ,
V_47 -> V_205 ) ;
V_100 = true ;
V_207:
if ( F_69 ( V_203 ) )
goto V_112;
V_204 = F_108 ( V_26 , V_203 , V_9 ,
L_14 ,
V_59 & V_109 ) ;
V_32 -> V_30 . V_59 |= V_204 & V_115 ;
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
F_129 ( struct V_25 * V_26 ,
struct V_31 * V_32 )
{
struct V_209 * V_210 , * V_211 = NULL ;
struct V_212 * V_213 = V_26 -> V_214 ;
struct V_17 * V_18 ;
struct V_51 * V_52 , * V_215 = NULL ;
V_18 = & V_32 -> V_120 ;
F_9 (orig_entry, head, list) {
V_210 = F_130 ( V_52 -> V_47 ,
V_216 ) ;
if ( ! V_210 )
continue;
if ( V_211 &&
V_213 -> V_217 . V_218 ( V_210 , V_216 , V_211 ,
V_216 ) <= 0 ) {
F_131 ( V_210 ) ;
continue;
}
if ( V_211 )
F_131 ( V_211 ) ;
V_215 = V_52 ;
V_211 = V_210 ;
}
if ( V_211 )
F_131 ( V_211 ) ;
return V_215 ;
}
static void
F_132 ( struct V_25 * V_26 ,
struct V_31 * V_32 ,
struct V_146 * V_147 )
{
struct V_51 * V_52 , * V_215 ;
struct V_5 * V_27 ;
struct V_48 * V_39 ;
struct V_17 * V_18 ;
T_2 V_133 ;
T_3 V_59 ;
V_27 = & V_32 -> V_30 ;
V_59 = V_27 -> V_59 ;
V_215 = F_129 ( V_26 , V_32 ) ;
if ( V_215 ) {
V_39 = F_133 ( V_215 -> V_47 ,
V_27 -> V_9 ) ;
if ( ! V_39 ) {
F_90 ( V_147 ,
L_15 ,
F_62 ( V_27 -> V_9 ) ,
V_215 -> V_47 -> V_205 ) ;
goto V_219;
}
V_133 = F_26 ( & V_215 -> V_47 -> V_133 ) ;
F_90 ( V_147 ,
L_16 ,
'*' , V_32 -> V_30 . V_14 ,
F_62 ( V_32 -> V_30 . V_9 ) ,
V_215 -> V_132 , V_215 -> V_47 -> V_205 ,
V_133 , V_39 -> V_12 . V_134 ,
( ( V_59 & V_109 ) ? 'R' : '.' ) ,
( ( V_59 & V_115 ) ? 'W' : '.' ) ,
( ( V_59 & V_125 ) ? 'I' : '.' ) ,
( ( V_59 & V_206 ) ? 'T' : '.' ) ) ;
F_38 ( V_39 ) ;
}
V_219:
V_18 = & V_32 -> V_120 ;
F_9 (orig_entry, head, list) {
if ( V_215 == V_52 )
continue;
V_39 = F_133 ( V_52 -> V_47 ,
V_27 -> V_9 ) ;
if ( ! V_39 ) {
F_90 ( V_147 ,
L_17 ,
F_62 ( V_27 -> V_9 ) ,
V_52 -> V_47 -> V_205 ) ;
continue;
}
V_133 = F_26 ( & V_52 -> V_47 -> V_133 ) ;
F_90 ( V_147 ,
L_18 ,
'+' , V_32 -> V_30 . V_14 ,
F_62 ( V_32 -> V_30 . V_9 ) ,
V_52 -> V_132 , V_52 -> V_47 -> V_205 ,
V_133 , V_39 -> V_12 . V_134 ,
( ( V_59 & V_109 ) ? 'R' : '.' ) ,
( ( V_59 & V_115 ) ? 'W' : '.' ) ,
( ( V_59 & V_125 ) ? 'I' : '.' ) ,
( ( V_59 & V_206 ) ? 'T' : '.' ) ) ;
F_38 ( V_39 ) ;
}
}
int F_134 ( struct V_146 * V_147 , void * V_148 )
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
F_132 ( V_26 , V_85 , V_147 ) ;
}
F_11 () ;
}
V_112:
if ( V_151 )
F_77 ( V_151 ) ;
return 0 ;
}
static int
F_135 ( struct V_159 * V_160 , T_1 V_161 , T_1 V_147 ,
struct V_5 * V_30 ,
struct V_51 * V_205 ,
bool V_220 )
{
T_3 V_59 = ( V_30 -> V_59 & ( ~ V_201 ) ) | V_205 -> V_59 ;
void * V_162 ;
struct V_48 * V_39 ;
T_2 V_133 ;
T_1 V_134 ;
V_39 = F_133 ( V_205 -> V_47 ,
V_30 -> V_9 ) ;
if ( ! V_39 )
return 0 ;
V_134 = V_39 -> V_12 . V_134 ;
F_38 ( V_39 ) ;
V_162 = F_94 ( V_160 , V_161 , V_147 , & V_164 ,
V_165 ,
V_221 ) ;
if ( ! V_162 )
return - V_167 ;
V_133 = F_26 ( & V_205 -> V_47 -> V_133 ) ;
if ( F_95 ( V_160 , V_168 , V_15 , V_30 -> V_14 ) ||
F_95 ( V_160 , V_222 , V_15 ,
V_205 -> V_47 -> V_205 ) ||
F_136 ( V_160 , V_223 , V_205 -> V_132 ) ||
F_136 ( V_160 , V_224 , V_133 ) ||
F_96 ( V_160 , V_169 , V_134 ) ||
F_97 ( V_160 , V_170 , V_30 -> V_9 ) ||
F_96 ( V_160 , V_171 , V_59 ) )
goto V_172;
if ( V_220 && F_137 ( V_160 , V_225 ) )
goto V_172;
F_98 ( V_160 , V_162 ) ;
return 0 ;
V_172:
F_99 ( V_160 , V_162 ) ;
return - V_174 ;
}
static int
F_138 ( struct V_159 * V_160 , T_1 V_161 , T_1 V_147 ,
struct V_25 * V_26 ,
struct V_5 * V_30 , int * V_226 )
{
struct V_51 * V_52 , * V_215 ;
struct V_31 * V_227 ;
struct V_17 * V_18 ;
int V_228 = 0 ;
bool V_220 ;
V_227 = F_2 ( V_30 , struct V_31 , V_30 ) ;
V_215 = F_129 ( V_26 , V_227 ) ;
V_18 = & V_227 -> V_120 ;
F_9 (orig_entry, head, list) {
if ( V_228 ++ < * V_226 )
continue;
V_220 = ( V_52 == V_215 ) ;
if ( F_135 ( V_160 , V_161 , V_147 , V_30 ,
V_52 , V_220 ) ) {
* V_226 = V_228 - 1 ;
return - V_174 ;
}
}
* V_226 = 0 ;
return 0 ;
}
static int
F_139 ( struct V_159 * V_160 , T_1 V_161 , T_1 V_147 ,
struct V_25 * V_26 ,
struct V_17 * V_18 , int * V_175 , int * V_228 )
{
struct V_5 * V_30 ;
int V_176 = 0 ;
F_8 () ;
F_9 (common, head, hash_entry) {
if ( V_176 ++ < * V_175 )
continue;
if ( F_138 ( V_160 , V_161 , V_147 , V_26 ,
V_30 , V_228 ) ) {
F_11 () ;
* V_175 = V_176 - 1 ;
return - V_174 ;
}
}
F_11 () ;
* V_175 = 0 ;
* V_228 = 0 ;
return 0 ;
}
int F_140 ( struct V_159 * V_160 , struct V_177 * V_178 )
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
int V_228 = V_178 -> args [ 2 ] ;
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
if ( F_139 ( V_160 , V_161 ,
V_178 -> V_182 -> V_189 , V_26 ,
V_18 , & V_176 , & V_228 ) )
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
V_178 -> args [ 2 ] = V_228 ;
return V_100 ;
}
static void
F_141 ( struct V_31 * V_32 ,
struct V_51 * V_52 )
{
F_142 ( & V_32 -> V_196 ) ;
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
F_141 ( V_32 , V_52 ) ;
F_39 ( & V_32 -> V_196 ) ;
}
static void
F_143 ( struct V_25 * V_26 ,
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
V_47 -> V_205 ,
V_32 -> V_30 . V_14 ,
F_62 ( V_9 ) , V_86 ) ;
F_141 ( V_32 ,
V_52 ) ;
}
}
F_39 ( & V_32 -> V_196 ) ;
}
static void
F_144 ( struct V_25 * V_26 ,
struct V_31 * V_32 ,
struct V_46 * V_47 ,
const char * V_86 )
{
bool V_229 = true ;
struct V_17 * V_18 ;
struct V_51 * V_52 ;
F_8 () ;
V_18 = & V_32 -> V_120 ;
F_9 (orig_entry, head, list) {
if ( V_52 -> V_47 != V_47 ) {
V_229 = false ;
break;
}
}
F_11 () ;
if ( V_229 ) {
V_32 -> V_30 . V_59 |= V_109 ;
V_32 -> V_121 = V_106 ;
} else {
F_143 ( V_26 , V_32 ,
V_47 , V_86 ) ;
}
}
static void F_145 ( struct V_25 * V_26 ,
struct V_46 * V_47 ,
const unsigned char * V_14 , unsigned short V_9 ,
const char * V_86 , bool V_191 )
{
struct V_31 * V_32 ;
struct V_24 * V_230 = NULL ;
V_32 = F_13 ( V_26 , V_14 , V_9 ) ;
if ( ! V_32 )
goto V_112;
if ( ! V_191 ) {
F_143 ( V_26 , V_32 ,
V_47 , V_86 ) ;
if ( F_146 ( & V_32 -> V_120 ) )
F_60 ( V_26 , V_32 ,
V_86 ) ;
goto V_112;
}
V_230 = F_12 ( V_26 ,
V_32 -> V_30 . V_14 ,
V_9 ) ;
if ( V_230 ) {
F_23 ( V_32 ) ;
F_60 ( V_26 , V_32 , V_86 ) ;
} else {
F_144 ( V_26 , V_32 ,
V_47 , V_86 ) ;
}
V_112:
if ( V_32 )
F_24 ( V_32 ) ;
if ( V_230 )
F_19 ( V_230 ) ;
}
void F_147 ( struct V_25 * V_26 ,
struct V_46 * V_47 ,
T_4 V_231 ,
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
if ( V_231 >= 0 && V_27 -> V_9 != V_231 )
continue;
V_85 = F_2 ( V_27 ,
struct V_31 ,
V_30 ) ;
F_143 ( V_26 , V_85 ,
V_47 , V_86 ) ;
if ( F_146 ( & V_85 -> V_120 ) ) {
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
F_148 ( V_232 , & V_47 -> V_233 ) ;
}
static bool F_149 ( struct V_31 * V_85 ,
char * * V_160 )
{
bool V_234 = false ;
unsigned long V_235 = V_236 ;
unsigned long V_237 = V_238 ;
if ( ( V_85 -> V_30 . V_59 & V_109 ) &&
F_111 ( V_85 -> V_121 , V_235 ) ) {
V_234 = true ;
* V_160 = L_22 ;
}
if ( ( V_85 -> V_30 . V_59 & V_206 ) &&
F_111 ( V_85 -> V_30 . V_116 , V_237 ) ) {
V_234 = true ;
* V_160 = L_23 ;
}
return V_234 ;
}
static void F_150 ( struct V_25 * V_26 )
{
struct V_16 * V_13 = V_26 -> V_12 . V_33 ;
struct V_17 * V_18 ;
struct V_1 * V_195 ;
T_5 * V_196 ;
T_1 V_152 ;
char * V_160 = NULL ;
struct V_5 * V_239 ;
struct V_31 * V_85 ;
for ( V_152 = 0 ; V_152 < V_13 -> V_11 ; V_152 ++ ) {
V_18 = & V_13 -> V_22 [ V_152 ] ;
V_196 = & V_13 -> V_197 [ V_152 ] ;
F_35 ( V_196 ) ;
F_110 (tt_common, node_tmp, head,
hash_entry) {
V_85 = F_2 ( V_239 ,
struct V_31 ,
V_30 ) ;
if ( ! F_149 ( V_85 , & V_160 ) )
continue;
F_61 ( V_87 , V_26 ,
L_1 ,
V_85 -> V_30 . V_14 ,
F_62 ( V_85 -> V_30 . V_9 ) ,
V_160 ) ;
F_114 ( & V_239 -> V_6 ) ;
F_24 ( V_85 ) ;
}
F_39 ( V_196 ) ;
}
}
static void F_151 ( struct V_25 * V_26 )
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
F_152 ( struct V_24 * V_28 ,
struct V_31 * V_32 )
{
if ( V_28 -> V_30 . V_59 & V_115 &&
V_32 -> V_30 . V_59 & V_115 )
return true ;
if ( V_28 -> V_30 . V_59 & V_125 &&
V_32 -> V_30 . V_59 & V_125 )
return true ;
return false ;
}
struct V_46 * F_153 ( struct V_25 * V_26 ,
const T_2 * V_240 ,
const T_2 * V_14 ,
unsigned short V_9 )
{
struct V_24 * V_28 = NULL ;
struct V_31 * V_32 = NULL ;
struct V_46 * V_47 = NULL ;
struct V_51 * V_215 ;
if ( V_240 && F_154 ( V_26 , V_9 ) ) {
V_28 = F_12 ( V_26 , V_240 , V_9 ) ;
if ( ! V_28 ||
( V_28 -> V_30 . V_59 & V_107 ) )
goto V_112;
}
V_32 = F_13 ( V_26 , V_14 , V_9 ) ;
if ( ! V_32 )
goto V_112;
if ( V_28 &&
F_152 ( V_28 , V_32 ) )
goto V_112;
F_8 () ;
V_215 = F_129 ( V_26 , V_32 ) ;
if ( V_215 )
V_47 = V_215 -> V_47 ;
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
static T_1 F_155 ( struct V_25 * V_26 ,
struct V_46 * V_47 ,
unsigned short V_9 )
{
struct V_16 * V_13 = V_26 -> V_12 . V_33 ;
struct V_51 * V_241 ;
struct V_5 * V_239 ;
struct V_31 * V_85 ;
struct V_17 * V_18 ;
T_1 V_152 , V_242 , V_134 = 0 ;
T_2 V_59 ;
T_6 V_243 ;
for ( V_152 = 0 ; V_152 < V_13 -> V_11 ; V_152 ++ ) {
V_18 = & V_13 -> V_22 [ V_152 ] ;
F_8 () ;
F_9 (tt_common, head, hash_entry) {
V_85 = F_2 ( V_239 ,
struct V_31 ,
V_30 ) ;
if ( V_239 -> V_9 != V_9 )
continue;
if ( V_239 -> V_59 & V_109 )
continue;
if ( V_239 -> V_59 & V_206 )
continue;
V_241 = F_118 ( V_85 ,
V_47 ) ;
if ( ! V_241 )
continue;
V_243 = F_48 ( V_239 -> V_9 ) ;
V_242 = F_156 ( 0 , & V_243 , sizeof( V_243 ) ) ;
V_59 = V_241 -> V_59 ;
V_242 = F_156 ( V_242 , & V_59 , sizeof( V_59 ) ) ;
V_134 ^= F_156 ( V_242 , V_239 -> V_14 , V_15 ) ;
F_45 ( V_241 ) ;
}
F_11 () ;
}
return V_134 ;
}
static T_1 F_157 ( struct V_25 * V_26 ,
unsigned short V_9 )
{
struct V_16 * V_13 = V_26 -> V_12 . V_29 ;
struct V_5 * V_239 ;
struct V_17 * V_18 ;
T_1 V_152 , V_242 , V_134 = 0 ;
T_2 V_59 ;
T_6 V_243 ;
for ( V_152 = 0 ; V_152 < V_13 -> V_11 ; V_152 ++ ) {
V_18 = & V_13 -> V_22 [ V_152 ] ;
F_8 () ;
F_9 (tt_common, head, hash_entry) {
if ( V_239 -> V_9 != V_9 )
continue;
if ( V_239 -> V_59 & V_114 )
continue;
V_243 = F_48 ( V_239 -> V_9 ) ;
V_242 = F_156 ( 0 , & V_243 , sizeof( V_243 ) ) ;
V_59 = V_239 -> V_59 & V_201 ;
V_242 = F_156 ( V_242 , & V_59 , sizeof( V_59 ) ) ;
V_134 ^= F_156 ( V_242 , V_239 -> V_14 , V_15 ) ;
}
F_11 () ;
}
return V_134 ;
}
static void F_158 ( struct V_37 * V_38 )
{
struct V_244 * V_245 ;
V_245 = F_2 ( V_38 , struct V_244 , V_23 ) ;
F_15 ( V_246 , V_245 ) ;
}
static void F_159 ( struct V_244 * V_245 )
{
F_20 ( & V_245 -> V_23 , F_158 ) ;
}
static void F_160 ( struct V_25 * V_26 )
{
struct V_244 * V_2 ;
struct V_1 * V_58 ;
F_35 ( & V_26 -> V_12 . V_247 ) ;
F_110 (node, safe, &bat_priv->tt.req_list, list) {
F_161 ( & V_2 -> V_50 ) ;
F_159 ( V_2 ) ;
}
F_39 ( & V_26 -> V_12 . V_247 ) ;
}
static void F_162 ( struct V_25 * V_26 ,
struct V_46 * V_47 ,
const void * V_248 ,
T_3 V_249 )
{
F_35 ( & V_47 -> V_250 ) ;
if ( V_249 > 0 ) {
F_85 ( V_47 -> V_248 ) ;
V_47 -> V_249 = 0 ;
V_47 -> V_248 = F_80 ( V_249 , V_64 ) ;
if ( V_47 -> V_248 ) {
memcpy ( V_47 -> V_248 , V_248 , V_249 ) ;
V_47 -> V_249 = V_249 ;
}
}
F_39 ( & V_47 -> V_250 ) ;
}
static void F_163 ( struct V_25 * V_26 )
{
struct V_244 * V_2 ;
struct V_1 * V_58 ;
F_35 ( & V_26 -> V_12 . V_247 ) ;
F_110 (node, safe, &bat_priv->tt.req_list, list) {
if ( F_111 ( V_2 -> V_251 ,
V_252 ) ) {
F_161 ( & V_2 -> V_50 ) ;
F_159 ( V_2 ) ;
}
}
F_39 ( & V_26 -> V_12 . V_247 ) ;
}
static struct V_244 *
F_164 ( struct V_25 * V_26 ,
struct V_46 * V_47 )
{
struct V_244 * V_253 , * V_245 = NULL ;
F_35 ( & V_26 -> V_12 . V_247 ) ;
F_165 (tt_req_node_tmp, &bat_priv->tt.req_list, list) {
if ( F_3 ( V_253 , V_47 ) &&
! F_111 ( V_253 -> V_251 ,
V_252 ) )
goto V_70;
}
V_245 = F_47 ( V_246 , V_64 ) ;
if ( ! V_245 )
goto V_70;
F_72 ( & V_245 -> V_23 ) ;
F_7 ( V_245 -> V_14 , V_47 -> V_205 ) ;
V_245 -> V_251 = V_106 ;
F_73 ( & V_245 -> V_23 ) ;
F_166 ( & V_245 -> V_50 , & V_26 -> V_12 . V_254 ) ;
V_70:
F_39 ( & V_26 -> V_12 . V_247 ) ;
return V_245 ;
}
static bool F_167 ( const void * V_255 , const void * V_256 )
{
const struct V_5 * V_27 = V_255 ;
if ( V_27 -> V_59 & V_114 )
return false ;
return true ;
}
static bool F_168 ( const void * V_255 ,
const void * V_256 )
{
const struct V_5 * V_27 = V_255 ;
const struct V_31 * V_32 ;
const struct V_46 * V_47 = V_256 ;
if ( V_27 -> V_59 & V_109 ||
V_27 -> V_59 & V_206 )
return false ;
V_32 = F_2 ( V_27 ,
struct V_31 ,
V_30 ) ;
return F_119 ( V_32 , V_47 ) ;
}
static void F_169 ( struct V_25 * V_26 ,
struct V_16 * V_13 ,
void * V_257 , T_3 V_75 ,
bool (* F_170)( const void * ,
const void * ) ,
void * V_258 )
{
struct V_5 * V_27 ;
struct V_74 * V_127 ;
struct V_17 * V_18 ;
T_3 V_259 , V_260 = 0 ;
T_1 V_152 ;
V_259 = F_55 ( V_75 ) ;
V_127 = (struct V_74 * ) V_257 ;
F_8 () ;
for ( V_152 = 0 ; V_152 < V_13 -> V_11 ; V_152 ++ ) {
V_18 = & V_13 -> V_22 [ V_152 ] ;
F_9 (tt_common_entry,
head, hash_entry) {
if ( V_259 == V_260 )
break;
if ( ( F_170 ) && ( ! F_170 ( V_27 , V_258 ) ) )
continue;
F_7 ( V_127 -> V_14 , V_27 -> V_14 ) ;
V_127 -> V_59 = V_27 -> V_59 ;
V_127 -> V_9 = F_48 ( V_27 -> V_9 ) ;
memset ( V_127 -> V_66 , 0 ,
sizeof( V_127 -> V_66 ) ) ;
V_260 ++ ;
V_127 ++ ;
}
}
F_11 () ;
}
static bool F_171 ( struct V_46 * V_47 ,
struct V_82 * V_130 ,
T_3 V_76 )
{
struct V_82 * V_261 ;
struct V_48 * V_39 ;
int V_152 , V_262 ;
T_1 V_134 ;
for ( V_152 = 0 ; V_152 < V_76 ; V_152 ++ ) {
V_261 = V_130 + V_152 ;
if ( F_126 ( V_47 -> V_26 ,
V_47 -> V_205 ,
F_172 ( V_261 -> V_9 ) ) )
continue;
V_39 = F_133 ( V_47 ,
F_172 ( V_261 -> V_9 ) ) ;
if ( ! V_39 )
return false ;
V_134 = V_39 -> V_12 . V_134 ;
F_38 ( V_39 ) ;
if ( V_134 != F_173 ( V_261 -> V_134 ) )
return false ;
}
F_8 () ;
V_262 = 0 ;
F_9 (vlan, &orig_node->vlan_list, list)
V_262 ++ ;
F_11 () ;
if ( V_262 > V_76 )
return false ;
return true ;
}
static void F_174 ( struct V_25 * V_26 )
{
struct V_44 * V_39 ;
F_8 () ;
F_9 (vlan, &bat_priv->softif_vlan_list, list) {
V_39 -> V_12 . V_134 = F_157 ( V_26 , V_39 -> V_9 ) ;
}
F_11 () ;
}
static void F_175 ( struct V_25 * V_26 ,
struct V_46 * V_47 )
{
struct V_48 * V_39 ;
T_1 V_134 ;
F_8 () ;
F_9 (vlan, &orig_node->vlan_list, list) {
if ( F_126 ( V_26 , V_47 -> V_205 ,
V_39 -> V_9 ) )
continue;
V_134 = F_155 ( V_26 , V_47 , V_39 -> V_9 ) ;
V_39 -> V_12 . V_134 = V_134 ;
}
F_11 () ;
}
static bool F_176 ( struct V_25 * V_26 ,
struct V_46 * V_263 ,
T_2 V_132 ,
struct V_82 * V_130 ,
T_3 V_76 , bool V_264 )
{
struct V_81 * V_265 = NULL ;
struct V_244 * V_245 = NULL ;
struct V_82 * V_266 ;
struct V_95 * V_151 ;
bool V_100 = false ;
int V_152 , V_11 ;
V_151 = F_106 ( V_26 ) ;
if ( ! V_151 )
goto V_112;
V_245 = F_164 ( V_26 , V_263 ) ;
if ( ! V_245 )
goto V_112;
V_11 = sizeof( * V_265 ) + sizeof( * V_266 ) * V_76 ;
V_265 = F_86 ( V_11 , V_64 ) ;
if ( ! V_265 )
goto V_112;
V_265 -> V_59 = V_267 ;
V_265 -> V_132 = V_132 ;
V_265 -> V_76 = F_48 ( V_76 ) ;
V_266 = (struct V_82 * ) ( V_265 + 1 ) ;
for ( V_152 = 0 ; V_152 < V_76 ; V_152 ++ ) {
V_266 -> V_9 = V_130 -> V_9 ;
V_266 -> V_134 = V_130 -> V_134 ;
V_266 ++ ;
V_130 ++ ;
}
if ( V_264 )
V_265 -> V_59 |= V_268 ;
F_61 ( V_87 , V_26 , L_24 ,
V_263 -> V_205 , V_264 ? 'F' : '.' ) ;
F_177 ( V_26 , V_269 ) ;
F_178 ( V_26 , V_151 -> V_149 -> V_117 ,
V_263 -> V_205 , V_145 , 1 ,
V_265 , V_11 ) ;
V_100 = true ;
V_112:
if ( V_151 )
F_77 ( V_151 ) ;
if ( V_100 && V_245 ) {
F_35 ( & V_26 -> V_12 . V_247 ) ;
if ( ! F_36 ( & V_245 -> V_50 ) ) {
F_161 ( & V_245 -> V_50 ) ;
F_159 ( V_245 ) ;
}
F_39 ( & V_26 -> V_12 . V_247 ) ;
}
if ( V_245 )
F_159 ( V_245 ) ;
F_85 ( V_265 ) ;
return V_100 ;
}
static bool F_179 ( struct V_25 * V_26 ,
struct V_81 * V_126 ,
T_2 * V_270 , T_2 * V_271 )
{
struct V_46 * V_272 ;
struct V_46 * V_273 = NULL ;
struct V_74 * V_127 ;
struct V_81 * V_265 = NULL ;
struct V_82 * V_130 ;
bool V_100 = false , V_264 ;
T_2 V_274 , V_275 ;
T_3 V_129 ;
T_4 V_75 ;
F_61 ( V_87 , V_26 ,
L_25 ,
V_270 , V_126 -> V_132 , V_271 ,
( ( V_126 -> V_59 & V_268 ) ? 'F' : '.' ) ) ;
V_272 = F_180 ( V_26 , V_271 ) ;
if ( ! V_272 )
goto V_112;
V_273 = F_180 ( V_26 , V_270 ) ;
if ( ! V_273 )
goto V_112;
V_274 = ( T_2 ) F_26 ( & V_272 -> V_133 ) ;
V_275 = V_126 -> V_132 ;
V_130 = (struct V_82 * ) ( V_126 + 1 ) ;
if ( V_274 != V_275 ||
! F_171 ( V_272 , V_130 ,
F_172 ( V_126 -> V_76 ) ) )
goto V_112;
if ( V_126 -> V_59 & V_268 ||
! V_272 -> V_248 )
V_264 = true ;
else
V_264 = false ;
if ( ! V_264 ) {
F_35 ( & V_272 -> V_250 ) ;
V_75 = V_272 -> V_249 ;
V_129 = F_79 ( V_272 ,
& V_265 ,
& V_127 ,
& V_75 ) ;
if ( ! V_75 )
goto V_70;
memcpy ( V_127 , V_272 -> V_248 ,
V_272 -> V_249 ) ;
F_39 ( & V_272 -> V_250 ) ;
} else {
V_75 = - 1 ;
V_129 = F_79 ( V_272 ,
& V_265 ,
& V_127 ,
& V_75 ) ;
if ( ! V_75 )
goto V_112;
F_169 ( V_26 , V_26 -> V_12 . V_33 ,
V_127 , V_75 ,
F_168 ,
V_272 ) ;
}
V_75 = sizeof( struct V_79 ) + V_129 ;
if ( V_75 > F_26 ( & V_26 -> V_99 ) ) {
F_70 ( V_111 , V_26 -> V_89 ,
L_26 ,
V_273 -> V_205 ) ;
goto V_112;
}
V_265 -> V_59 = V_276 ;
V_265 -> V_132 = V_275 ;
if ( V_264 )
V_265 -> V_59 |= V_268 ;
F_61 ( V_87 , V_26 ,
L_27 ,
V_273 -> V_205 , V_272 -> V_205 ,
V_264 ? 'F' : '.' , V_275 ) ;
F_177 ( V_26 , V_277 ) ;
F_178 ( V_26 , V_272 -> V_205 ,
V_270 , V_145 , 1 , V_265 ,
V_129 ) ;
V_100 = true ;
goto V_112;
V_70:
F_39 ( & V_272 -> V_250 ) ;
V_112:
if ( V_273 )
F_44 ( V_273 ) ;
if ( V_272 )
F_44 ( V_272 ) ;
F_85 ( V_265 ) ;
return V_100 ;
}
static bool F_181 ( struct V_25 * V_26 ,
struct V_81 * V_126 ,
T_2 * V_270 )
{
struct V_81 * V_265 = NULL ;
struct V_95 * V_151 = NULL ;
struct V_74 * V_127 ;
struct V_46 * V_47 ;
T_2 V_278 , V_275 ;
T_3 V_129 ;
bool V_264 ;
T_4 V_75 ;
F_61 ( V_87 , V_26 ,
L_28 ,
V_270 , V_126 -> V_132 ,
( ( V_126 -> V_59 & V_268 ) ? 'F' : '.' ) ) ;
F_35 ( & V_26 -> V_12 . V_279 ) ;
V_278 = ( T_2 ) F_26 ( & V_26 -> V_12 . V_113 ) ;
V_275 = V_126 -> V_132 ;
V_47 = F_180 ( V_26 , V_270 ) ;
if ( ! V_47 )
goto V_112;
V_151 = F_106 ( V_26 ) ;
if ( ! V_151 )
goto V_112;
if ( V_126 -> V_59 & V_268 || V_278 != V_275 ||
! V_26 -> V_12 . V_143 )
V_264 = true ;
else
V_264 = false ;
if ( ! V_264 ) {
F_35 ( & V_26 -> V_12 . V_142 ) ;
V_75 = V_26 -> V_12 . V_144 ;
V_129 = F_82 ( V_26 ,
& V_265 ,
& V_127 ,
& V_75 ) ;
if ( ! V_75 || ! V_129 )
goto V_70;
memcpy ( V_127 , V_26 -> V_12 . V_143 ,
V_26 -> V_12 . V_144 ) ;
F_39 ( & V_26 -> V_12 . V_142 ) ;
} else {
V_275 = ( T_2 ) F_26 ( & V_26 -> V_12 . V_113 ) ;
V_75 = - 1 ;
V_129 = F_82 ( V_26 ,
& V_265 ,
& V_127 ,
& V_75 ) ;
if ( ! V_75 || ! V_129 )
goto V_112;
F_169 ( V_26 , V_26 -> V_12 . V_29 ,
V_127 , V_75 ,
F_167 , NULL ) ;
}
V_265 -> V_59 = V_276 ;
V_265 -> V_132 = V_275 ;
if ( V_264 )
V_265 -> V_59 |= V_268 ;
F_61 ( V_87 , V_26 ,
L_29 ,
V_47 -> V_205 , V_264 ? 'F' : '.' , V_275 ) ;
F_177 ( V_26 , V_277 ) ;
F_178 ( V_26 , V_151 -> V_149 -> V_117 ,
V_270 , V_145 , 1 , V_265 ,
V_129 ) ;
goto V_112;
V_70:
F_39 ( & V_26 -> V_12 . V_142 ) ;
V_112:
F_39 ( & V_26 -> V_12 . V_279 ) ;
if ( V_47 )
F_44 ( V_47 ) ;
if ( V_151 )
F_77 ( V_151 ) ;
F_85 ( V_265 ) ;
return true ;
}
static bool F_182 ( struct V_25 * V_26 ,
struct V_81 * V_126 ,
T_2 * V_270 , T_2 * V_271 )
{
if ( F_183 ( V_26 , V_271 ) )
return F_181 ( V_26 , V_126 , V_270 ) ;
return F_179 ( V_26 , V_126 , V_270 ,
V_271 ) ;
}
static void F_184 ( struct V_25 * V_26 ,
struct V_46 * V_47 ,
struct V_74 * V_127 ,
T_3 V_280 , T_2 V_132 )
{
int V_152 ;
int V_281 ;
for ( V_152 = 0 ; V_152 < V_280 ; V_152 ++ ) {
if ( ( V_127 + V_152 ) -> V_59 & V_67 ) {
V_281 = ( V_127 + V_152 ) -> V_59 & V_109 ;
F_145 ( V_26 , V_47 ,
( V_127 + V_152 ) -> V_14 ,
F_172 ( ( V_127 + V_152 ) -> V_9 ) ,
L_30 ,
V_281 ) ;
} else {
if ( ! F_125 ( V_26 , V_47 ,
( V_127 + V_152 ) -> V_14 ,
F_172 ( ( V_127 + V_152 ) -> V_9 ) ,
( V_127 + V_152 ) -> V_59 , V_132 ) )
return;
}
}
F_185 ( V_232 , & V_47 -> V_233 ) ;
}
static void F_186 ( struct V_25 * V_26 ,
struct V_74 * V_127 ,
T_2 V_132 , T_2 * V_282 ,
T_3 V_45 )
{
struct V_46 * V_47 ;
V_47 = F_180 ( V_26 , V_282 ) ;
if ( ! V_47 )
goto V_112;
F_147 ( V_26 , V_47 , - 1 ,
L_31 ) ;
F_184 ( V_26 , V_47 , V_127 , V_45 ,
V_132 ) ;
F_35 ( & V_47 -> V_250 ) ;
F_85 ( V_47 -> V_248 ) ;
V_47 -> V_249 = 0 ;
V_47 -> V_248 = NULL ;
F_39 ( & V_47 -> V_250 ) ;
F_84 ( & V_47 -> V_133 , V_132 ) ;
V_112:
if ( V_47 )
F_44 ( V_47 ) ;
}
static void F_187 ( struct V_25 * V_26 ,
struct V_46 * V_47 ,
T_3 V_280 , T_2 V_132 ,
struct V_74 * V_127 )
{
F_184 ( V_26 , V_47 , V_127 ,
V_280 , V_132 ) ;
F_162 ( V_26 , V_47 , V_127 ,
F_54 ( V_280 ) ) ;
F_84 ( & V_47 -> V_133 , V_132 ) ;
}
bool F_188 ( struct V_25 * V_26 , const T_2 * V_14 ,
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
static void F_189 ( struct V_25 * V_26 ,
struct V_81 * V_126 ,
T_2 * V_282 , T_3 V_45 )
{
struct V_244 * V_2 ;
struct V_1 * V_58 ;
struct V_46 * V_47 = NULL ;
struct V_74 * V_127 ;
T_2 * V_283 = ( T_2 * ) V_126 ;
T_3 V_128 ;
F_61 ( V_87 , V_26 ,
L_32 ,
V_282 , V_126 -> V_132 , V_45 ,
( ( V_126 -> V_59 & V_268 ) ? 'F' : '.' ) ) ;
V_47 = F_180 ( V_26 , V_282 ) ;
if ( ! V_47 )
goto V_112;
F_35 ( & V_47 -> V_284 ) ;
V_128 = sizeof( struct V_82 ) ;
V_128 *= F_172 ( V_126 -> V_76 ) ;
V_128 += sizeof( * V_126 ) ;
V_283 += V_128 ;
V_127 = (struct V_74 * ) V_283 ;
if ( V_126 -> V_59 & V_268 ) {
F_186 ( V_26 , V_127 , V_126 -> V_132 ,
V_282 , V_45 ) ;
} else {
F_187 ( V_26 , V_47 , V_45 ,
V_126 -> V_132 , V_127 ) ;
}
F_175 ( V_26 , V_47 ) ;
F_39 ( & V_47 -> V_284 ) ;
F_35 ( & V_26 -> V_12 . V_247 ) ;
F_110 (node, safe, &bat_priv->tt.req_list, list) {
if ( ! F_3 ( V_2 -> V_14 , V_282 ) )
continue;
F_161 ( & V_2 -> V_50 ) ;
F_159 ( V_2 ) ;
}
F_39 ( & V_26 -> V_12 . V_247 ) ;
V_112:
if ( V_47 )
F_44 ( V_47 ) ;
}
static void F_190 ( struct V_25 * V_26 )
{
struct V_285 * V_2 , * V_58 ;
F_35 ( & V_26 -> V_12 . V_286 ) ;
F_49 (node, safe, &bat_priv->tt.roam_list, list) {
F_50 ( & V_2 -> V_50 ) ;
F_15 ( V_287 , V_2 ) ;
}
F_39 ( & V_26 -> V_12 . V_286 ) ;
}
static void F_191 ( struct V_25 * V_26 )
{
struct V_285 * V_2 , * V_58 ;
F_35 ( & V_26 -> V_12 . V_286 ) ;
F_49 (node, safe, &bat_priv->tt.roam_list, list) {
if ( ! F_111 ( V_2 -> V_288 ,
V_289 ) )
continue;
F_50 ( & V_2 -> V_50 ) ;
F_15 ( V_287 , V_2 ) ;
}
F_39 ( & V_26 -> V_12 . V_286 ) ;
}
static bool F_192 ( struct V_25 * V_26 , T_2 * V_290 )
{
struct V_285 * V_291 ;
bool V_100 = false ;
F_35 ( & V_26 -> V_12 . V_286 ) ;
F_193 (tt_roam_node, &bat_priv->tt.roam_list, list) {
if ( ! F_3 ( V_291 -> V_14 , V_290 ) )
continue;
if ( F_111 ( V_291 -> V_288 ,
V_289 ) )
continue;
if ( ! F_194 ( & V_291 -> V_292 ) )
goto V_70;
V_100 = true ;
break;
}
if ( ! V_100 ) {
V_291 = F_47 ( V_287 ,
V_64 ) ;
if ( ! V_291 )
goto V_70;
V_291 -> V_288 = V_106 ;
F_84 ( & V_291 -> V_292 ,
V_293 - 1 ) ;
F_7 ( V_291 -> V_14 , V_290 ) ;
F_195 ( & V_291 -> V_50 , & V_26 -> V_12 . V_294 ) ;
V_100 = true ;
}
V_70:
F_39 ( & V_26 -> V_12 . V_286 ) ;
return V_100 ;
}
static void F_76 ( struct V_25 * V_26 , T_2 * V_290 ,
unsigned short V_9 ,
struct V_46 * V_47 )
{
struct V_95 * V_151 ;
struct V_295 V_296 ;
V_151 = F_106 ( V_26 ) ;
if ( ! V_151 )
goto V_112;
if ( ! F_192 ( V_26 , V_290 ) )
goto V_112;
F_61 ( V_87 , V_26 ,
L_33 ,
V_47 -> V_205 , V_290 , F_62 ( V_9 ) ) ;
F_177 ( V_26 , V_297 ) ;
memcpy ( V_296 . V_290 , V_290 , sizeof( V_296 . V_290 ) ) ;
V_296 . V_9 = F_48 ( V_9 ) ;
F_178 ( V_26 , V_151 -> V_149 -> V_117 ,
V_47 -> V_205 , V_298 , 1 ,
& V_296 , sizeof( V_296 ) ) ;
V_112:
if ( V_151 )
F_77 ( V_151 ) ;
}
static void F_196 ( struct V_299 * V_300 )
{
struct V_301 * V_301 ;
struct V_302 * V_303 ;
struct V_25 * V_26 ;
V_301 = F_197 ( V_300 ) ;
V_303 = F_2 ( V_301 , struct V_302 , V_300 ) ;
V_26 = F_2 ( V_303 , struct V_25 , V_12 ) ;
F_112 ( V_26 , V_304 ) ;
F_150 ( V_26 ) ;
F_163 ( V_26 ) ;
F_191 ( V_26 ) ;
F_198 ( V_305 , & V_26 -> V_12 . V_300 ,
F_199 ( V_306 ) ) ;
}
void F_200 ( struct V_25 * V_26 )
{
F_201 ( V_26 , V_145 , 1 ) ;
F_202 ( V_26 , V_145 , 1 ) ;
F_203 ( & V_26 -> V_12 . V_300 ) ;
F_113 ( V_26 ) ;
F_151 ( V_26 ) ;
F_160 ( V_26 ) ;
F_117 ( V_26 ) ;
F_190 ( V_26 ) ;
F_85 ( V_26 -> V_12 . V_143 ) ;
}
static void F_204 ( struct V_25 * V_26 , T_3 V_59 ,
bool V_307 , bool V_41 )
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
if ( V_307 ) {
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
static void F_205 ( struct V_25 * V_26 )
{
struct V_16 * V_13 = V_26 -> V_12 . V_29 ;
struct V_5 * V_239 ;
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
if ( ! ( V_239 -> V_59 & V_107 ) )
continue;
F_61 ( V_87 , V_26 ,
L_34 ,
V_239 -> V_14 ,
F_62 ( V_239 -> V_9 ) ) ;
F_31 ( V_26 , V_239 -> V_9 ) ;
F_114 ( & V_239 -> V_6 ) ;
V_92 = F_2 ( V_239 ,
struct V_24 ,
V_30 ) ;
F_19 ( V_92 ) ;
}
F_39 ( V_196 ) ;
}
}
static void F_206 ( struct V_25 * V_26 )
{
F_142 ( & V_26 -> V_12 . V_279 ) ;
if ( F_26 ( & V_26 -> V_12 . V_72 ) < 1 ) {
if ( ! F_194 ( & V_26 -> V_12 . V_308 ) )
F_83 ( V_26 ) ;
return;
}
F_204 ( V_26 , V_114 , false , true ) ;
F_205 ( V_26 ) ;
F_174 ( V_26 ) ;
F_53 ( & V_26 -> V_12 . V_113 ) ;
F_61 ( V_87 , V_26 ,
L_35 ,
( T_2 ) F_26 ( & V_26 -> V_12 . V_113 ) ) ;
F_84 ( & V_26 -> V_12 . V_308 , V_309 ) ;
F_83 ( V_26 ) ;
}
void F_207 ( struct V_25 * V_26 )
{
F_35 ( & V_26 -> V_12 . V_279 ) ;
F_206 ( V_26 ) ;
F_39 ( & V_26 -> V_12 . V_279 ) ;
}
bool F_208 ( struct V_25 * V_26 , T_2 * V_240 , T_2 * V_310 ,
unsigned short V_9 )
{
struct V_24 * V_28 ;
struct V_31 * V_32 ;
struct V_44 * V_39 ;
bool V_100 = false ;
V_39 = F_28 ( V_26 , V_9 ) ;
if ( ! V_39 )
return false ;
if ( ! F_26 ( & V_39 -> V_311 ) )
goto V_312;
V_28 = F_12 ( V_26 , V_310 , V_9 ) ;
if ( ! V_28 )
goto V_312;
V_32 = F_13 ( V_26 , V_240 , V_9 ) ;
if ( ! V_32 )
goto V_313;
if ( F_152 ( V_28 , V_32 ) )
V_100 = true ;
F_24 ( V_32 ) ;
V_313:
F_19 ( V_28 ) ;
V_312:
F_17 ( V_39 ) ;
return V_100 ;
}
static void F_209 ( struct V_25 * V_26 ,
struct V_46 * V_47 ,
const void * V_248 , T_3 V_314 ,
struct V_74 * V_127 ,
T_3 V_280 , T_2 V_132 )
{
T_2 V_274 = ( T_2 ) F_26 ( & V_47 -> V_133 ) ;
struct V_82 * V_130 ;
bool V_264 = true ;
bool V_315 ;
V_130 = (struct V_82 * ) V_248 ;
V_315 = F_210 ( V_232 ,
& V_47 -> V_233 ) ;
if ( ( ! V_315 && V_132 == 1 ) || V_132 - V_274 == 1 ) {
if ( ! V_280 ) {
V_264 = false ;
goto V_316;
}
F_35 ( & V_47 -> V_284 ) ;
F_187 ( V_26 , V_47 , V_280 ,
V_132 , V_127 ) ;
F_175 ( V_26 , V_47 ) ;
F_39 ( & V_47 -> V_284 ) ;
if ( ! F_171 ( V_47 , V_130 ,
V_314 ) )
goto V_316;
} else {
if ( ! V_315 || V_132 != V_274 ||
! F_171 ( V_47 , V_130 ,
V_314 ) ) {
V_316:
F_61 ( V_87 , V_26 ,
L_36 ,
V_47 -> V_205 , V_132 , V_274 ,
V_280 ) ;
F_176 ( V_26 , V_47 , V_132 ,
V_130 , V_314 ,
V_264 ) ;
return;
}
}
}
bool F_211 ( struct V_25 * V_26 ,
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
bool F_212 ( struct V_25 * V_26 ,
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
bool F_213 ( struct V_25 * V_26 ,
struct V_46 * V_47 ,
const unsigned char * V_14 ,
unsigned short V_9 )
{
if ( F_214 ( V_14 ) )
return false ;
if ( ! F_125 ( V_26 , V_47 , V_14 , V_9 ,
V_206 ,
F_26 ( & V_47 -> V_133 ) ) )
return false ;
F_61 ( V_87 , V_26 ,
L_37 ,
V_14 , F_62 ( V_9 ) , V_47 -> V_205 ) ;
return true ;
}
void F_215 ( struct V_88 * V_89 )
{
struct V_25 * V_26 = F_65 ( V_89 ) ;
int V_99 = F_26 ( & V_26 -> V_99 ) ;
int V_98 , V_194 = V_304 / 2 ;
bool V_317 = false ;
F_35 ( & V_26 -> V_12 . V_279 ) ;
while ( true ) {
V_98 = F_56 ( V_26 ) ;
if ( V_99 >= V_98 )
break;
F_112 ( V_26 , V_194 ) ;
F_205 ( V_26 ) ;
V_194 /= 2 ;
V_317 = true ;
F_70 ( V_111 , V_89 ,
L_38 ,
V_99 ) ;
}
if ( V_317 )
F_206 ( V_26 ) ;
F_39 ( & V_26 -> V_12 . V_279 ) ;
}
static void F_216 ( struct V_25 * V_26 ,
struct V_46 * V_205 ,
T_2 V_59 , void * V_318 ,
T_3 V_319 )
{
struct V_82 * V_130 ;
struct V_74 * V_127 ;
struct V_81 * V_126 ;
T_3 V_45 , V_76 ;
if ( V_319 < sizeof( * V_126 ) )
return;
V_126 = (struct V_81 * ) V_318 ;
V_319 -= sizeof( * V_126 ) ;
V_76 = F_172 ( V_126 -> V_76 ) ;
if ( V_319 < sizeof( * V_130 ) * V_76 )
return;
V_130 = (struct V_82 * ) ( V_126 + 1 ) ;
V_127 = (struct V_74 * ) ( V_130 + V_76 ) ;
V_319 -= sizeof( * V_130 ) * V_76 ;
V_45 = F_55 ( V_319 ) ;
F_209 ( V_26 , V_205 , V_130 , V_76 , V_127 ,
V_45 , V_126 -> V_132 ) ;
}
static int F_217 ( struct V_25 * V_26 ,
T_2 * V_240 , T_2 * V_310 ,
void * V_318 ,
T_3 V_319 )
{
struct V_81 * V_126 ;
T_3 V_320 , V_260 ;
char V_321 ;
bool V_100 ;
if ( V_319 < sizeof( * V_126 ) )
return V_322 ;
V_126 = (struct V_81 * ) V_318 ;
V_319 -= sizeof( * V_126 ) ;
V_320 = sizeof( struct V_82 ) ;
V_320 *= F_172 ( V_126 -> V_76 ) ;
if ( V_319 < V_320 )
return V_322 ;
V_319 -= V_320 ;
V_260 = F_55 ( V_319 ) ;
switch ( V_126 -> V_59 & V_323 ) {
case V_267 :
F_177 ( V_26 , V_324 ) ;
V_100 = F_182 ( V_26 , V_126 , V_240 , V_310 ) ;
if ( ! V_100 ) {
if ( V_126 -> V_59 & V_268 )
V_321 = 'F' ;
else
V_321 = '.' ;
F_61 ( V_87 , V_26 ,
L_39 ,
V_310 , V_321 ) ;
return V_325 ;
}
break;
case V_276 :
F_177 ( V_26 , V_326 ) ;
if ( F_183 ( V_26 , V_310 ) ) {
F_189 ( V_26 , V_126 ,
V_240 , V_260 ) ;
return V_322 ;
}
if ( V_126 -> V_59 & V_268 )
V_321 = 'F' ;
else
V_321 = '.' ;
F_61 ( V_87 , V_26 ,
L_40 , V_310 , V_321 ) ;
return V_325 ;
}
return V_322 ;
}
static int F_218 ( struct V_25 * V_26 ,
T_2 * V_240 , T_2 * V_310 ,
void * V_318 ,
T_3 V_319 )
{
struct V_295 * V_327 ;
struct V_46 * V_47 = NULL ;
if ( ! F_183 ( V_26 , V_310 ) )
return V_325 ;
if ( V_319 < sizeof( * V_327 ) )
goto V_112;
V_47 = F_180 ( V_26 , V_240 ) ;
if ( ! V_47 )
goto V_112;
F_177 ( V_26 , V_328 ) ;
V_327 = (struct V_295 * ) V_318 ;
F_61 ( V_87 , V_26 ,
L_41 ,
V_240 , V_327 -> V_290 ) ;
F_125 ( V_26 , V_47 , V_327 -> V_290 ,
F_172 ( V_327 -> V_9 ) , V_109 ,
F_26 ( & V_47 -> V_133 ) + 1 ) ;
V_112:
if ( V_47 )
F_44 ( V_47 ) ;
return V_322 ;
}
int F_219 ( struct V_25 * V_26 )
{
int V_100 ;
F_220 ( ! ( V_201 & V_122 ) ) ;
V_100 = F_57 ( V_26 ) ;
if ( V_100 < 0 )
return V_100 ;
V_100 = F_116 ( V_26 ) ;
if ( V_100 < 0 )
return V_100 ;
F_221 ( V_26 , F_216 ,
F_217 ,
V_145 , 1 , V_119 ) ;
F_221 ( V_26 , NULL ,
F_218 ,
V_298 , 1 , V_119 ) ;
F_222 ( & V_26 -> V_12 . V_300 , F_196 ) ;
F_198 ( V_305 , & V_26 -> V_12 . V_300 ,
F_199 ( V_306 ) ) ;
return 1 ;
}
bool F_223 ( struct V_25 * V_26 ,
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
int T_7 F_224 ( void )
{
T_8 V_329 = sizeof( struct V_24 ) ;
T_8 V_330 = sizeof( struct V_31 ) ;
T_8 V_331 = sizeof( struct V_51 ) ;
T_8 V_332 = sizeof( struct V_55 ) ;
T_8 V_333 = sizeof( struct V_244 ) ;
T_8 V_334 = sizeof( struct V_285 ) ;
V_36 = F_225 ( L_42 , V_329 , 0 ,
V_335 , NULL ) ;
if ( ! V_36 )
return - V_83 ;
V_40 = F_225 ( L_43 , V_330 , 0 ,
V_335 , NULL ) ;
if ( ! V_40 )
goto V_336;
V_53 = F_225 ( L_44 ,
V_331 , 0 ,
V_335 , NULL ) ;
if ( ! V_53 )
goto V_337;
V_63 = F_225 ( L_45 ,
V_332 , 0 ,
V_335 , NULL ) ;
if ( ! V_63 )
goto V_338;
V_246 = F_225 ( L_46 ,
V_333 , 0 ,
V_335 , NULL ) ;
if ( ! V_246 )
goto V_339;
V_287 = F_225 ( L_47 ,
V_334 , 0 ,
V_335 , NULL ) ;
if ( ! V_287 )
goto V_340;
return 0 ;
V_340:
F_226 ( V_246 ) ;
V_246 = NULL ;
V_339:
F_226 ( V_63 ) ;
V_63 = NULL ;
V_338:
F_226 ( V_53 ) ;
V_53 = NULL ;
V_337:
F_226 ( V_40 ) ;
V_40 = NULL ;
V_336:
F_226 ( V_36 ) ;
V_36 = NULL ;
return - V_83 ;
}
void F_227 ( void )
{
F_226 ( V_36 ) ;
F_226 ( V_40 ) ;
F_226 ( V_53 ) ;
F_226 ( V_63 ) ;
F_226 ( V_246 ) ;
F_226 ( V_287 ) ;
}

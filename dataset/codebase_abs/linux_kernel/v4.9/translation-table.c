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
struct V_17 * V_18 ;
struct V_51 * V_52 ;
int V_95 , V_96 , V_97 ;
bool V_98 = false ;
bool V_99 = false ;
T_2 V_100 ;
T_1 V_101 ;
if ( V_90 != V_102 )
V_94 = F_67 ( V_93 , V_90 ) ;
V_92 = F_12 ( V_26 , V_14 , V_9 ) ;
if ( ! F_68 ( V_14 ) )
V_85 = F_13 ( V_26 , V_14 , V_9 ) ;
if ( V_92 ) {
V_92 -> V_103 = V_104 ;
if ( V_92 -> V_30 . V_59 & V_105 ) {
F_61 ( V_87 , V_26 ,
L_2 ,
V_14 , F_62 ( V_9 ) ) ;
V_92 -> V_30 . V_59 &= ~ V_105 ;
goto V_106;
}
if ( V_92 -> V_30 . V_59 & V_107 ) {
F_61 ( V_87 , V_26 ,
L_3 ,
V_14 , F_62 ( V_9 ) ) ;
V_92 -> V_30 . V_59 &= ~ V_107 ;
V_99 = true ;
}
goto V_108;
}
V_96 = F_56 ( V_26 ) ;
V_96 += F_54 ( 1 ) ;
V_97 = F_26 ( & V_26 -> V_97 ) ;
if ( V_96 > V_97 ) {
F_69 ( V_109 , V_89 ,
L_4 ,
V_96 , V_97 , V_14 ) ;
goto V_110;
}
V_92 = F_47 ( V_36 , V_64 ) ;
if ( ! V_92 )
goto V_110;
V_39 = F_28 ( V_26 , V_9 ) ;
if ( ! V_39 ) {
F_69 ( V_109 , V_89 ,
L_5 ,
V_14 , F_62 ( V_9 ) ) ;
F_15 ( V_36 , V_92 ) ;
V_92 = NULL ;
goto V_110;
}
F_61 ( V_87 , V_26 ,
L_6 ,
V_14 , F_62 ( V_9 ) ,
( T_2 ) F_26 ( & V_26 -> V_12 . V_111 ) ) ;
F_7 ( V_92 -> V_30 . V_14 , V_14 ) ;
V_92 -> V_30 . V_59 = V_112 ;
V_92 -> V_30 . V_9 = V_9 ;
if ( F_70 ( V_94 ) )
V_92 -> V_30 . V_59 |= V_113 ;
F_71 ( & V_92 -> V_30 . V_23 ) ;
V_92 -> V_103 = V_104 ;
V_92 -> V_30 . V_114 = V_92 -> V_103 ;
V_92 -> V_39 = V_39 ;
if ( F_3 ( V_14 , V_89 -> V_115 ) ||
F_68 ( V_14 ) )
V_92 -> V_30 . V_59 |= V_116 ;
F_72 ( & V_92 -> V_30 . V_23 ) ;
V_95 = F_73 ( V_26 -> V_12 . V_29 , F_1 ,
F_4 , & V_92 -> V_30 ,
& V_92 -> V_30 . V_6 ) ;
if ( F_74 ( V_95 != 0 ) ) {
F_19 ( V_92 ) ;
goto V_110;
}
V_106:
F_46 ( V_26 , V_92 , V_117 ) ;
V_108:
if ( V_85 && ! ( V_85 -> V_30 . V_59 & V_107 ) ) {
V_18 = & V_85 -> V_118 ;
F_8 () ;
F_9 (orig_entry, head, list) {
F_75 ( V_26 , V_85 -> V_30 . V_14 ,
V_85 -> V_30 . V_9 ,
V_52 -> V_47 ) ;
}
F_11 () ;
if ( V_99 ) {
F_60 ( V_26 , V_85 ,
L_7 ) ;
V_85 = NULL ;
} else {
V_85 -> V_30 . V_59 |= V_107 ;
V_85 -> V_119 = V_104 ;
}
}
V_100 = V_92 -> V_30 . V_59 & V_120 ;
if ( F_70 ( V_94 ) )
V_92 -> V_30 . V_59 |= V_113 ;
else
V_92 -> V_30 . V_59 &= ~ V_113 ;
V_101 = ( V_91 & V_26 -> V_121 ) ;
if ( V_26 -> V_121 &&
V_101 == V_26 -> V_122 )
V_92 -> V_30 . V_59 |= V_123 ;
else
V_92 -> V_30 . V_59 &= ~ V_123 ;
if ( V_100 ^ ( V_92 -> V_30 . V_59 & V_120 ) )
F_46 ( V_26 , V_92 , V_117 ) ;
V_98 = true ;
V_110:
if ( V_94 )
F_76 ( V_94 ) ;
if ( V_92 )
F_19 ( V_92 ) ;
if ( V_85 )
F_24 ( V_85 ) ;
return V_98 ;
}
static T_3
F_77 ( struct V_46 * V_47 ,
struct V_81 * * V_124 ,
struct V_74 * * V_125 ,
T_4 * V_75 )
{
T_3 V_76 = 0 ;
T_3 V_45 = 0 ;
T_3 V_126 ;
T_3 V_127 ;
struct V_82 * V_128 ;
struct V_48 * V_39 ;
T_2 * V_129 ;
F_8 () ;
F_9 (vlan, &orig_node->vlan_list, list) {
V_76 ++ ;
V_45 += F_26 ( & V_39 -> V_12 . V_45 ) ;
}
V_126 = sizeof( * * V_124 ) ;
V_126 += V_76 * sizeof( * V_128 ) ;
if ( * V_75 < 0 )
* V_75 = F_54 ( V_45 ) ;
V_127 = * V_75 ;
V_127 += V_126 ;
* V_124 = F_78 ( V_127 , V_64 ) ;
if ( ! * V_124 ) {
* V_75 = 0 ;
goto V_110;
}
( * V_124 ) -> V_59 = V_117 ;
( * V_124 ) -> V_130 = F_26 ( & V_47 -> V_131 ) ;
( * V_124 ) -> V_76 = F_48 ( V_76 ) ;
V_128 = (struct V_82 * ) ( * V_124 + 1 ) ;
F_9 (vlan, &orig_node->vlan_list, list) {
V_128 -> V_9 = F_48 ( V_39 -> V_9 ) ;
V_128 -> V_132 = F_79 ( V_39 -> V_12 . V_132 ) ;
V_128 ++ ;
}
V_129 = ( T_2 * ) * V_124 + V_126 ;
* V_125 = (struct V_74 * ) V_129 ;
V_110:
F_11 () ;
return V_127 ;
}
static T_3
F_80 ( struct V_25 * V_26 ,
struct V_81 * * V_124 ,
struct V_74 * * V_125 ,
T_4 * V_75 )
{
struct V_82 * V_128 ;
struct V_44 * V_39 ;
T_3 V_76 = 0 ;
T_3 V_45 = 0 ;
T_3 V_127 ;
T_2 * V_129 ;
int V_126 ;
F_8 () ;
F_9 (vlan, &bat_priv->softif_vlan_list, list) {
V_76 ++ ;
V_45 += F_26 ( & V_39 -> V_12 . V_45 ) ;
}
V_126 = sizeof( * * V_124 ) ;
V_126 += V_76 * sizeof( * V_128 ) ;
if ( * V_75 < 0 )
* V_75 = F_54 ( V_45 ) ;
V_127 = * V_75 ;
V_127 += V_126 ;
* V_124 = F_78 ( V_127 , V_64 ) ;
if ( ! * V_124 ) {
V_127 = 0 ;
goto V_110;
}
( * V_124 ) -> V_59 = V_117 ;
( * V_124 ) -> V_130 = F_26 ( & V_26 -> V_12 . V_111 ) ;
( * V_124 ) -> V_76 = F_48 ( V_76 ) ;
V_128 = (struct V_82 * ) ( * V_124 + 1 ) ;
F_9 (vlan, &bat_priv->softif_vlan_list, list) {
V_128 -> V_9 = F_48 ( V_39 -> V_9 ) ;
V_128 -> V_132 = F_79 ( V_39 -> V_12 . V_132 ) ;
V_128 ++ ;
}
V_129 = ( T_2 * ) * V_124 + V_126 ;
* V_125 = (struct V_74 * ) V_129 ;
V_110:
F_11 () ;
return V_127 ;
}
static void F_81 ( struct V_25 * V_26 )
{
struct V_55 * V_57 , * V_58 ;
struct V_81 * V_124 ;
struct V_74 * V_125 ;
int V_133 , V_134 = 0 ;
int V_135 = 0 ;
int V_136 = 0 ;
T_3 V_127 ;
V_135 = F_26 ( & V_26 -> V_12 . V_72 ) ;
V_133 = F_54 ( V_135 ) ;
if ( V_133 > V_26 -> V_89 -> V_137 )
V_133 = 0 ;
V_127 = F_80 ( V_26 , & V_124 ,
& V_125 , & V_133 ) ;
if ( ! V_127 )
return;
V_124 -> V_59 = V_138 ;
if ( V_133 == 0 )
goto V_139;
F_35 ( & V_26 -> V_12 . V_68 ) ;
F_82 ( & V_26 -> V_12 . V_72 , 0 ) ;
F_49 (entry, safe, &bat_priv->tt.changes_list,
list) {
if ( V_136 < V_135 ) {
memcpy ( V_125 + V_136 ,
& V_57 -> V_65 ,
sizeof( struct V_74 ) ) ;
V_136 ++ ;
}
F_50 ( & V_57 -> V_50 ) ;
F_15 ( V_63 , V_57 ) ;
}
F_39 ( & V_26 -> V_12 . V_68 ) ;
F_35 ( & V_26 -> V_12 . V_140 ) ;
F_83 ( V_26 -> V_12 . V_141 ) ;
V_26 -> V_12 . V_142 = 0 ;
V_26 -> V_12 . V_141 = NULL ;
V_134 = F_54 ( V_136 ) ;
if ( V_136 > 0 ) {
V_26 -> V_12 . V_141 = F_84 ( V_133 , V_64 ) ;
if ( V_26 -> V_12 . V_141 ) {
memcpy ( V_26 -> V_12 . V_141 ,
V_125 , V_134 ) ;
V_26 -> V_12 . V_142 = V_133 ;
}
}
F_39 ( & V_26 -> V_12 . V_140 ) ;
V_139:
F_85 ( V_26 , V_143 , 1 , V_124 ,
V_127 ) ;
F_83 ( V_124 ) ;
}
int F_86 ( struct V_144 * V_145 , void * V_146 )
{
struct V_88 * V_147 = (struct V_88 * ) V_145 -> V_148 ;
struct V_25 * V_26 = F_65 ( V_147 ) ;
struct V_16 * V_13 = V_26 -> V_12 . V_29 ;
struct V_5 * V_27 ;
struct V_24 * V_92 ;
struct V_149 * V_150 ;
struct V_17 * V_18 ;
T_1 V_151 ;
int V_152 ;
int V_153 ;
unsigned long V_154 ;
bool V_155 ;
T_3 V_156 = V_116 ;
V_150 = F_87 ( V_145 ) ;
if ( ! V_150 )
goto V_110;
F_88 ( V_145 ,
L_8 ,
V_147 -> V_157 , ( T_2 ) F_26 ( & V_26 -> V_12 . V_111 ) ) ;
F_89 ( V_145 ,
L_9 ) ;
for ( V_151 = 0 ; V_151 < V_13 -> V_11 ; V_151 ++ ) {
V_18 = & V_13 -> V_22 [ V_151 ] ;
F_8 () ;
F_9 (tt_common_entry,
head, hash_entry) {
V_92 = F_2 ( V_27 ,
struct V_24 ,
V_30 ) ;
V_154 = V_104 - V_92 -> V_103 ;
V_153 = F_90 ( V_154 ) ;
V_152 = V_153 / 1000 ;
V_153 = V_153 % 1000 ;
V_155 = V_27 -> V_59 & V_156 ;
F_88 ( V_145 ,
L_10 ,
V_27 -> V_14 ,
F_62 ( V_27 -> V_9 ) ,
( ( V_27 -> V_59 &
V_107 ) ? 'R' : '.' ) ,
V_155 ? 'P' : '.' ,
( ( V_27 -> V_59 &
V_112 ) ? 'N' : '.' ) ,
( ( V_27 -> V_59 &
V_105 ) ? 'X' : '.' ) ,
( ( V_27 -> V_59 &
V_113 ) ? 'W' : '.' ) ,
( ( V_27 -> V_59 &
V_123 ) ? 'I' : '.' ) ,
V_155 ? 0 : V_152 ,
V_155 ? 0 : V_153 ,
V_92 -> V_39 -> V_12 . V_132 ) ;
}
F_11 () ;
}
V_110:
if ( V_150 )
F_91 ( V_150 ) ;
return 0 ;
}
static int
F_92 ( struct V_158 * V_159 , T_1 V_160 , T_1 V_145 ,
struct V_25 * V_26 ,
struct V_5 * V_30 )
{
void * V_161 ;
struct V_44 * V_39 ;
struct V_24 * V_162 ;
unsigned int V_153 ;
T_1 V_132 ;
V_162 = F_2 ( V_30 , struct V_24 , V_30 ) ;
V_153 = F_90 ( V_104 - V_162 -> V_103 ) ;
V_39 = F_28 ( V_26 , V_30 -> V_9 ) ;
if ( ! V_39 )
return 0 ;
V_132 = V_39 -> V_12 . V_132 ;
F_17 ( V_39 ) ;
V_161 = F_93 ( V_159 , V_160 , V_145 , & V_163 ,
V_164 ,
V_165 ) ;
if ( ! V_161 )
return - V_166 ;
if ( F_94 ( V_159 , V_167 , V_15 , V_30 -> V_14 ) ||
F_95 ( V_159 , V_168 , V_132 ) ||
F_96 ( V_159 , V_169 , V_30 -> V_9 ) ||
F_95 ( V_159 , V_170 , V_30 -> V_59 ) )
goto V_171;
if ( ! ( V_30 -> V_59 & V_116 ) &&
F_95 ( V_159 , V_172 , V_153 ) )
goto V_171;
F_97 ( V_159 , V_161 ) ;
return 0 ;
V_171:
F_98 ( V_159 , V_161 ) ;
return - V_173 ;
}
static int
F_99 ( struct V_158 * V_159 , T_1 V_160 , T_1 V_145 ,
struct V_25 * V_26 ,
struct V_17 * V_18 , int * V_174 )
{
struct V_5 * V_30 ;
int V_175 = 0 ;
F_8 () ;
F_9 (common, head, hash_entry) {
if ( V_175 ++ < * V_174 )
continue;
if ( F_92 ( V_159 , V_160 , V_145 , V_26 ,
V_30 ) ) {
F_11 () ;
* V_174 = V_175 - 1 ;
return - V_173 ;
}
}
F_11 () ;
* V_174 = 0 ;
return 0 ;
}
int F_100 ( struct V_158 * V_159 , struct V_176 * V_177 )
{
struct V_93 * V_93 = F_101 ( V_177 -> V_178 -> V_179 ) ;
struct V_88 * V_89 ;
struct V_25 * V_26 ;
struct V_149 * V_150 = NULL ;
struct V_16 * V_13 ;
struct V_17 * V_18 ;
int V_98 ;
int V_90 ;
int V_180 = V_177 -> args [ 0 ] ;
int V_175 = V_177 -> args [ 1 ] ;
int V_160 = F_102 ( V_177 -> V_178 ) . V_160 ;
V_90 = F_103 ( V_177 -> V_181 , V_182 ) ;
if ( ! V_90 )
return - V_183 ;
V_89 = F_67 ( V_93 , V_90 ) ;
if ( ! V_89 || ! F_104 ( V_89 ) ) {
V_98 = - V_184 ;
goto V_110;
}
V_26 = F_65 ( V_89 ) ;
V_150 = F_105 ( V_26 ) ;
if ( ! V_150 || V_150 -> V_185 != V_186 ) {
V_98 = - V_187 ;
goto V_110;
}
V_13 = V_26 -> V_12 . V_29 ;
while ( V_180 < V_13 -> V_11 ) {
V_18 = & V_13 -> V_22 [ V_180 ] ;
if ( F_99 ( V_159 , V_160 , V_177 -> V_181 -> V_188 ,
V_26 , V_18 , & V_175 ) )
break;
V_180 ++ ;
}
V_98 = V_159 -> V_189 ;
V_110:
if ( V_150 )
F_91 ( V_150 ) ;
if ( V_89 )
F_76 ( V_89 ) ;
V_177 -> args [ 0 ] = V_180 ;
V_177 -> args [ 1 ] = V_175 ;
return V_98 ;
}
static void
F_106 ( struct V_25 * V_26 ,
struct V_24 * V_28 ,
T_3 V_59 , const char * V_86 )
{
F_46 ( V_26 , V_28 , V_59 ) ;
V_28 -> V_30 . V_59 |= V_105 ;
F_61 ( V_87 , V_26 ,
L_11 ,
V_28 -> V_30 . V_14 ,
F_62 ( V_28 -> V_30 . V_9 ) , V_86 ) ;
}
T_3 F_107 ( struct V_25 * V_26 , const T_2 * V_14 ,
unsigned short V_9 , const char * V_86 ,
bool V_190 )
{
struct V_24 * V_28 ;
T_3 V_59 , V_191 = V_117 ;
void * V_192 ;
V_28 = F_12 ( V_26 , V_14 , V_9 ) ;
if ( ! V_28 )
goto V_110;
V_191 = V_28 -> V_30 . V_59 ;
V_59 = V_67 ;
if ( V_190 ) {
V_59 |= V_107 ;
V_28 -> V_30 . V_59 |= V_107 ;
}
if ( ! ( V_28 -> V_30 . V_59 & V_112 ) ) {
F_106 ( V_26 , V_28 , V_59 ,
V_86 ) ;
goto V_110;
}
F_46 ( V_26 , V_28 , V_67 ) ;
V_192 = F_63 ( V_26 -> V_12 . V_29 ,
F_1 ,
F_4 ,
& V_28 -> V_30 ) ;
if ( ! V_192 )
goto V_110;
F_19 ( V_28 ) ;
V_110:
if ( V_28 )
F_19 ( V_28 ) ;
return V_191 ;
}
static void F_108 ( struct V_25 * V_26 ,
struct V_17 * V_18 ,
int V_193 )
{
struct V_24 * V_28 ;
struct V_5 * V_27 ;
struct V_1 * V_194 ;
F_109 (tt_common_entry, node_tmp, head,
hash_entry) {
V_28 = F_2 ( V_27 ,
struct V_24 ,
V_30 ) ;
if ( V_28 -> V_30 . V_59 & V_116 )
continue;
if ( V_28 -> V_30 . V_59 & V_105 )
continue;
if ( ! F_110 ( V_28 -> V_103 , V_193 ) )
continue;
F_106 ( V_26 , V_28 ,
V_67 , L_12 ) ;
}
}
static void F_111 ( struct V_25 * V_26 ,
int V_193 )
{
struct V_16 * V_13 = V_26 -> V_12 . V_29 ;
struct V_17 * V_18 ;
T_5 * V_195 ;
T_1 V_151 ;
for ( V_151 = 0 ; V_151 < V_13 -> V_11 ; V_151 ++ ) {
V_18 = & V_13 -> V_22 [ V_151 ] ;
V_195 = & V_13 -> V_196 [ V_151 ] ;
F_35 ( V_195 ) ;
F_108 ( V_26 , V_18 , V_193 ) ;
F_39 ( V_195 ) ;
}
}
static void F_112 ( struct V_25 * V_26 )
{
struct V_16 * V_13 ;
T_5 * V_195 ;
struct V_5 * V_27 ;
struct V_24 * V_92 ;
struct V_1 * V_194 ;
struct V_17 * V_18 ;
T_1 V_151 ;
if ( ! V_26 -> V_12 . V_29 )
return;
V_13 = V_26 -> V_12 . V_29 ;
for ( V_151 = 0 ; V_151 < V_13 -> V_11 ; V_151 ++ ) {
V_18 = & V_13 -> V_22 [ V_151 ] ;
V_195 = & V_13 -> V_196 [ V_151 ] ;
F_35 ( V_195 ) ;
F_109 (tt_common_entry, node_tmp,
head, hash_entry) {
F_113 ( & V_27 -> V_6 ) ;
V_92 = F_2 ( V_27 ,
struct V_24 ,
V_30 ) ;
F_19 ( V_92 ) ;
}
F_39 ( V_195 ) ;
}
F_114 ( V_13 ) ;
V_26 -> V_12 . V_29 = NULL ;
}
static int F_115 ( struct V_25 * V_26 )
{
if ( V_26 -> V_12 . V_33 )
return 0 ;
V_26 -> V_12 . V_33 = F_58 ( 1024 ) ;
if ( ! V_26 -> V_12 . V_33 )
return - V_83 ;
F_59 ( V_26 -> V_12 . V_33 ,
& V_197 ) ;
return 0 ;
}
static void F_116 ( struct V_25 * V_26 )
{
struct V_55 * V_57 , * V_58 ;
F_35 ( & V_26 -> V_12 . V_68 ) ;
F_49 (entry, safe, &bat_priv->tt.changes_list,
list) {
F_50 ( & V_57 -> V_50 ) ;
F_15 ( V_63 , V_57 ) ;
}
F_82 ( & V_26 -> V_12 . V_72 , 0 ) ;
F_39 ( & V_26 -> V_12 . V_68 ) ;
}
static struct V_51 *
F_117 ( const struct V_31 * V_57 ,
const struct V_46 * V_47 )
{
struct V_51 * V_198 , * V_52 = NULL ;
const struct V_17 * V_18 ;
F_8 () ;
V_18 = & V_57 -> V_118 ;
F_9 (tmp_orig_entry, head, list) {
if ( V_198 -> V_47 != V_47 )
continue;
if ( ! F_10 ( & V_198 -> V_23 ) )
continue;
V_52 = V_198 ;
break;
}
F_11 () ;
return V_52 ;
}
static bool
F_118 ( const struct V_31 * V_57 ,
const struct V_46 * V_47 )
{
struct V_51 * V_52 ;
bool V_199 = false ;
V_52 = F_117 ( V_57 , V_47 ) ;
if ( V_52 ) {
V_199 = true ;
F_45 ( V_52 ) ;
}
return V_199 ;
}
static void
F_119 ( struct V_31 * V_85 ,
struct V_46 * V_47 , int V_130 )
{
struct V_51 * V_52 ;
V_52 = F_117 ( V_85 , V_47 ) ;
if ( V_52 ) {
V_52 -> V_130 = V_130 ;
goto V_110;
}
V_52 = F_120 ( V_53 , V_64 ) ;
if ( ! V_52 )
goto V_110;
F_121 ( & V_52 -> V_50 ) ;
F_72 ( & V_47 -> V_23 ) ;
F_40 ( V_47 , V_85 -> V_30 . V_9 ) ;
V_52 -> V_47 = V_47 ;
V_52 -> V_130 = V_130 ;
F_71 ( & V_52 -> V_23 ) ;
F_35 ( & V_85 -> V_195 ) ;
F_72 ( & V_52 -> V_23 ) ;
F_122 ( & V_52 -> V_50 ,
& V_85 -> V_118 ) ;
F_39 ( & V_85 -> V_195 ) ;
F_53 ( & V_85 -> V_42 ) ;
V_110:
if ( V_52 )
F_45 ( V_52 ) ;
}
static bool F_123 ( struct V_25 * V_26 ,
struct V_46 * V_47 ,
const unsigned char * V_200 ,
unsigned short V_9 , T_3 V_59 , T_2 V_130 )
{
struct V_31 * V_32 ;
struct V_24 * V_28 ;
bool V_98 = false ;
int V_95 ;
struct V_5 * V_30 ;
T_3 V_201 ;
if ( F_124 ( V_26 , V_47 -> V_202 , V_9 ) )
return true ;
V_32 = F_13 ( V_26 , V_200 , V_9 ) ;
V_28 = F_12 ( V_26 , V_200 , V_9 ) ;
if ( ( V_59 & V_203 ) && V_28 &&
! ( V_28 -> V_30 . V_59 & V_112 ) )
goto V_110;
if ( ! V_32 ) {
V_32 = F_120 ( V_40 ,
V_64 ) ;
if ( ! V_32 )
goto V_110;
V_30 = & V_32 -> V_30 ;
F_7 ( V_30 -> V_14 , V_200 ) ;
V_30 -> V_9 = V_9 ;
V_30 -> V_59 = V_59 ;
V_32 -> V_119 = 0 ;
if ( V_59 & V_107 )
V_32 -> V_119 = V_104 ;
F_71 ( & V_30 -> V_23 ) ;
V_30 -> V_114 = V_104 ;
F_125 ( & V_32 -> V_118 ) ;
F_82 ( & V_32 -> V_42 , 0 ) ;
F_126 ( & V_32 -> V_195 ) ;
F_72 ( & V_30 -> V_23 ) ;
V_95 = F_73 ( V_26 -> V_12 . V_33 ,
F_1 ,
F_4 , V_30 ,
& V_30 -> V_6 ) ;
if ( F_74 ( V_95 != 0 ) ) {
F_24 ( V_32 ) ;
goto V_204;
}
} else {
V_30 = & V_32 -> V_30 ;
if ( V_59 & V_203 ) {
if ( ! ( V_30 -> V_59 & V_203 ) )
goto V_110;
if ( F_118 ( V_32 ,
V_47 ) )
goto V_204;
F_23 ( V_32 ) ;
goto V_205;
}
if ( V_30 -> V_59 & V_203 ) {
F_23 ( V_32 ) ;
V_30 -> V_59 &= ~ V_203 ;
}
V_30 -> V_59 |= V_59 ;
if ( V_30 -> V_59 & V_107 ) {
F_23 ( V_32 ) ;
V_30 -> V_59 &= ~ V_107 ;
V_32 -> V_119 = 0 ;
}
}
V_205:
F_119 ( V_32 , V_47 , V_130 ) ;
F_61 ( V_87 , V_26 ,
L_13 ,
V_30 -> V_14 , F_62 ( V_30 -> V_9 ) ,
V_47 -> V_202 ) ;
V_98 = true ;
V_204:
if ( F_68 ( V_200 ) )
goto V_110;
V_201 = F_107 ( V_26 , V_200 , V_9 ,
L_14 ,
V_59 & V_107 ) ;
V_32 -> V_30 . V_59 |= V_201 & V_113 ;
if ( ! ( V_59 & V_107 ) )
V_32 -> V_30 . V_59 &= ~ V_107 ;
V_110:
if ( V_32 )
F_24 ( V_32 ) ;
if ( V_28 )
F_19 ( V_28 ) ;
return V_98 ;
}
static struct V_51 *
F_127 ( struct V_25 * V_26 ,
struct V_31 * V_32 )
{
struct V_206 * V_207 , * V_208 = NULL ;
struct V_209 * V_210 = V_26 -> V_211 ;
struct V_17 * V_18 ;
struct V_51 * V_52 , * V_212 = NULL ;
V_18 = & V_32 -> V_118 ;
F_9 (orig_entry, head, list) {
V_207 = F_128 ( V_52 -> V_47 ,
V_213 ) ;
if ( ! V_207 )
continue;
if ( V_208 &&
V_210 -> V_214 . V_215 ( V_207 , V_213 , V_208 ,
V_213 ) <= 0 ) {
F_129 ( V_207 ) ;
continue;
}
if ( V_208 )
F_129 ( V_208 ) ;
V_212 = V_52 ;
V_208 = V_207 ;
}
if ( V_208 )
F_129 ( V_208 ) ;
return V_212 ;
}
static void
F_130 ( struct V_25 * V_26 ,
struct V_31 * V_32 ,
struct V_144 * V_145 )
{
struct V_51 * V_52 , * V_212 ;
struct V_5 * V_27 ;
struct V_48 * V_39 ;
struct V_17 * V_18 ;
T_2 V_131 ;
T_3 V_59 ;
V_27 = & V_32 -> V_30 ;
V_59 = V_27 -> V_59 ;
V_212 = F_127 ( V_26 , V_32 ) ;
if ( V_212 ) {
V_39 = F_131 ( V_212 -> V_47 ,
V_27 -> V_9 ) ;
if ( ! V_39 ) {
F_88 ( V_145 ,
L_15 ,
F_62 ( V_27 -> V_9 ) ,
V_212 -> V_47 -> V_202 ) ;
goto V_216;
}
V_131 = F_26 ( & V_212 -> V_47 -> V_131 ) ;
F_88 ( V_145 ,
L_16 ,
'*' , V_32 -> V_30 . V_14 ,
F_62 ( V_32 -> V_30 . V_9 ) ,
V_212 -> V_130 , V_212 -> V_47 -> V_202 ,
V_131 , V_39 -> V_12 . V_132 ,
( ( V_59 & V_107 ) ? 'R' : '.' ) ,
( ( V_59 & V_113 ) ? 'W' : '.' ) ,
( ( V_59 & V_123 ) ? 'I' : '.' ) ,
( ( V_59 & V_203 ) ? 'T' : '.' ) ) ;
F_38 ( V_39 ) ;
}
V_216:
V_18 = & V_32 -> V_118 ;
F_9 (orig_entry, head, list) {
if ( V_212 == V_52 )
continue;
V_39 = F_131 ( V_52 -> V_47 ,
V_27 -> V_9 ) ;
if ( ! V_39 ) {
F_88 ( V_145 ,
L_17 ,
F_62 ( V_27 -> V_9 ) ,
V_52 -> V_47 -> V_202 ) ;
continue;
}
V_131 = F_26 ( & V_52 -> V_47 -> V_131 ) ;
F_88 ( V_145 ,
L_18 ,
'+' , V_32 -> V_30 . V_14 ,
F_62 ( V_32 -> V_30 . V_9 ) ,
V_52 -> V_130 , V_52 -> V_47 -> V_202 ,
V_131 , V_39 -> V_12 . V_132 ,
( ( V_59 & V_107 ) ? 'R' : '.' ) ,
( ( V_59 & V_113 ) ? 'W' : '.' ) ,
( ( V_59 & V_123 ) ? 'I' : '.' ) ,
( ( V_59 & V_203 ) ? 'T' : '.' ) ) ;
F_38 ( V_39 ) ;
}
}
int F_132 ( struct V_144 * V_145 , void * V_146 )
{
struct V_88 * V_147 = (struct V_88 * ) V_145 -> V_148 ;
struct V_25 * V_26 = F_65 ( V_147 ) ;
struct V_16 * V_13 = V_26 -> V_12 . V_33 ;
struct V_5 * V_27 ;
struct V_31 * V_85 ;
struct V_149 * V_150 ;
struct V_17 * V_18 ;
T_1 V_151 ;
V_150 = F_87 ( V_145 ) ;
if ( ! V_150 )
goto V_110;
F_88 ( V_145 ,
L_19 ,
V_147 -> V_157 ) ;
F_89 ( V_145 ,
L_20 ) ;
for ( V_151 = 0 ; V_151 < V_13 -> V_11 ; V_151 ++ ) {
V_18 = & V_13 -> V_22 [ V_151 ] ;
F_8 () ;
F_9 (tt_common_entry,
head, hash_entry) {
V_85 = F_2 ( V_27 ,
struct V_31 ,
V_30 ) ;
F_130 ( V_26 , V_85 , V_145 ) ;
}
F_11 () ;
}
V_110:
if ( V_150 )
F_91 ( V_150 ) ;
return 0 ;
}
static int
F_133 ( struct V_158 * V_159 , T_1 V_160 , T_1 V_145 ,
struct V_5 * V_30 ,
struct V_51 * V_202 ,
bool V_217 )
{
void * V_161 ;
struct V_48 * V_39 ;
T_2 V_131 ;
T_1 V_132 ;
V_39 = F_131 ( V_202 -> V_47 ,
V_30 -> V_9 ) ;
if ( ! V_39 )
return 0 ;
V_132 = V_39 -> V_12 . V_132 ;
F_38 ( V_39 ) ;
V_161 = F_93 ( V_159 , V_160 , V_145 , & V_163 ,
V_164 ,
V_218 ) ;
if ( ! V_161 )
return - V_166 ;
V_131 = F_26 ( & V_202 -> V_47 -> V_131 ) ;
if ( F_94 ( V_159 , V_167 , V_15 , V_30 -> V_14 ) ||
F_94 ( V_159 , V_219 , V_15 ,
V_202 -> V_47 -> V_202 ) ||
F_134 ( V_159 , V_220 , V_202 -> V_130 ) ||
F_134 ( V_159 , V_221 , V_131 ) ||
F_95 ( V_159 , V_168 , V_132 ) ||
F_96 ( V_159 , V_169 , V_30 -> V_9 ) ||
F_95 ( V_159 , V_170 , V_30 -> V_59 ) )
goto V_171;
if ( V_217 && F_135 ( V_159 , V_222 ) )
goto V_171;
F_97 ( V_159 , V_161 ) ;
return 0 ;
V_171:
F_98 ( V_159 , V_161 ) ;
return - V_173 ;
}
static int
F_136 ( struct V_158 * V_159 , T_1 V_160 , T_1 V_145 ,
struct V_25 * V_26 ,
struct V_5 * V_30 , int * V_223 )
{
struct V_51 * V_52 , * V_212 ;
struct V_31 * V_224 ;
struct V_17 * V_18 ;
int V_225 = 0 ;
bool V_217 ;
V_224 = F_2 ( V_30 , struct V_31 , V_30 ) ;
V_212 = F_127 ( V_26 , V_224 ) ;
V_18 = & V_224 -> V_118 ;
F_9 (orig_entry, head, list) {
if ( V_225 ++ < * V_223 )
continue;
V_217 = ( V_52 == V_212 ) ;
if ( F_133 ( V_159 , V_160 , V_145 , V_30 ,
V_52 , V_217 ) ) {
* V_223 = V_225 - 1 ;
return - V_173 ;
}
}
* V_223 = 0 ;
return 0 ;
}
static int
F_137 ( struct V_158 * V_159 , T_1 V_160 , T_1 V_145 ,
struct V_25 * V_26 ,
struct V_17 * V_18 , int * V_174 , int * V_225 )
{
struct V_5 * V_30 ;
int V_175 = 0 ;
F_8 () ;
F_9 (common, head, hash_entry) {
if ( V_175 ++ < * V_174 )
continue;
if ( F_136 ( V_159 , V_160 , V_145 , V_26 ,
V_30 , V_225 ) ) {
F_11 () ;
* V_174 = V_175 - 1 ;
return - V_173 ;
}
}
F_11 () ;
* V_174 = 0 ;
* V_225 = 0 ;
return 0 ;
}
int F_138 ( struct V_158 * V_159 , struct V_176 * V_177 )
{
struct V_93 * V_93 = F_101 ( V_177 -> V_178 -> V_179 ) ;
struct V_88 * V_89 ;
struct V_25 * V_26 ;
struct V_149 * V_150 = NULL ;
struct V_16 * V_13 ;
struct V_17 * V_18 ;
int V_98 ;
int V_90 ;
int V_180 = V_177 -> args [ 0 ] ;
int V_175 = V_177 -> args [ 1 ] ;
int V_225 = V_177 -> args [ 2 ] ;
int V_160 = F_102 ( V_177 -> V_178 ) . V_160 ;
V_90 = F_103 ( V_177 -> V_181 , V_182 ) ;
if ( ! V_90 )
return - V_183 ;
V_89 = F_67 ( V_93 , V_90 ) ;
if ( ! V_89 || ! F_104 ( V_89 ) ) {
V_98 = - V_184 ;
goto V_110;
}
V_26 = F_65 ( V_89 ) ;
V_150 = F_105 ( V_26 ) ;
if ( ! V_150 || V_150 -> V_185 != V_186 ) {
V_98 = - V_187 ;
goto V_110;
}
V_13 = V_26 -> V_12 . V_33 ;
while ( V_180 < V_13 -> V_11 ) {
V_18 = & V_13 -> V_22 [ V_180 ] ;
if ( F_137 ( V_159 , V_160 ,
V_177 -> V_181 -> V_188 , V_26 ,
V_18 , & V_175 , & V_225 ) )
break;
V_180 ++ ;
}
V_98 = V_159 -> V_189 ;
V_110:
if ( V_150 )
F_91 ( V_150 ) ;
if ( V_89 )
F_76 ( V_89 ) ;
V_177 -> args [ 0 ] = V_180 ;
V_177 -> args [ 1 ] = V_175 ;
V_177 -> args [ 2 ] = V_225 ;
return V_98 ;
}
static void
F_139 ( struct V_31 * V_32 ,
struct V_51 * V_52 )
{
F_140 ( & V_32 -> V_195 ) ;
F_41 ( V_52 -> V_47 ,
V_32 -> V_30 . V_9 ) ;
F_52 ( & V_32 -> V_42 ) ;
F_113 ( & V_52 -> V_50 ) ;
F_45 ( V_52 ) ;
}
static void
F_23 ( struct V_31 * V_32 )
{
struct V_17 * V_18 ;
struct V_1 * V_58 ;
struct V_51 * V_52 ;
F_35 ( & V_32 -> V_195 ) ;
V_18 = & V_32 -> V_118 ;
F_109 (orig_entry, safe, head, list)
F_139 ( V_32 , V_52 ) ;
F_39 ( & V_32 -> V_195 ) ;
}
static void
F_141 ( struct V_25 * V_26 ,
struct V_31 * V_32 ,
struct V_46 * V_47 ,
const char * V_86 )
{
struct V_17 * V_18 ;
struct V_1 * V_58 ;
struct V_51 * V_52 ;
unsigned short V_9 ;
F_35 ( & V_32 -> V_195 ) ;
V_18 = & V_32 -> V_118 ;
F_109 (orig_entry, safe, head, list) {
if ( V_52 -> V_47 == V_47 ) {
V_9 = V_32 -> V_30 . V_9 ;
F_61 ( V_87 , V_26 ,
L_21 ,
V_47 -> V_202 ,
V_32 -> V_30 . V_14 ,
F_62 ( V_9 ) , V_86 ) ;
F_139 ( V_32 ,
V_52 ) ;
}
}
F_39 ( & V_32 -> V_195 ) ;
}
static void
F_142 ( struct V_25 * V_26 ,
struct V_31 * V_32 ,
struct V_46 * V_47 ,
const char * V_86 )
{
bool V_226 = true ;
struct V_17 * V_18 ;
struct V_51 * V_52 ;
F_8 () ;
V_18 = & V_32 -> V_118 ;
F_9 (orig_entry, head, list) {
if ( V_52 -> V_47 != V_47 ) {
V_226 = false ;
break;
}
}
F_11 () ;
if ( V_226 ) {
V_32 -> V_30 . V_59 |= V_107 ;
V_32 -> V_119 = V_104 ;
} else
F_141 ( V_26 , V_32 ,
V_47 , V_86 ) ;
}
static void F_143 ( struct V_25 * V_26 ,
struct V_46 * V_47 ,
const unsigned char * V_14 , unsigned short V_9 ,
const char * V_86 , bool V_190 )
{
struct V_31 * V_32 ;
struct V_24 * V_227 = NULL ;
V_32 = F_13 ( V_26 , V_14 , V_9 ) ;
if ( ! V_32 )
goto V_110;
if ( ! V_190 ) {
F_141 ( V_26 , V_32 ,
V_47 , V_86 ) ;
if ( F_144 ( & V_32 -> V_118 ) )
F_60 ( V_26 , V_32 ,
V_86 ) ;
goto V_110;
}
V_227 = F_12 ( V_26 ,
V_32 -> V_30 . V_14 ,
V_9 ) ;
if ( V_227 ) {
F_23 ( V_32 ) ;
F_60 ( V_26 , V_32 , V_86 ) ;
} else
F_142 ( V_26 , V_32 ,
V_47 , V_86 ) ;
V_110:
if ( V_32 )
F_24 ( V_32 ) ;
if ( V_227 )
F_19 ( V_227 ) ;
}
void F_145 ( struct V_25 * V_26 ,
struct V_46 * V_47 ,
T_4 V_228 ,
const char * V_86 )
{
struct V_31 * V_85 ;
struct V_5 * V_27 ;
T_1 V_151 ;
struct V_16 * V_13 = V_26 -> V_12 . V_33 ;
struct V_1 * V_58 ;
struct V_17 * V_18 ;
T_5 * V_195 ;
unsigned short V_9 ;
if ( ! V_13 )
return;
for ( V_151 = 0 ; V_151 < V_13 -> V_11 ; V_151 ++ ) {
V_18 = & V_13 -> V_22 [ V_151 ] ;
V_195 = & V_13 -> V_196 [ V_151 ] ;
F_35 ( V_195 ) ;
F_109 (tt_common_entry, safe,
head, hash_entry) {
if ( V_228 >= 0 && V_27 -> V_9 != V_228 )
continue;
V_85 = F_2 ( V_27 ,
struct V_31 ,
V_30 ) ;
F_141 ( V_26 , V_85 ,
V_47 , V_86 ) ;
if ( F_144 ( & V_85 -> V_118 ) ) {
V_9 = V_85 -> V_30 . V_9 ;
F_61 ( V_87 , V_26 ,
L_1 ,
V_85 -> V_30 . V_14 ,
F_62 ( V_9 ) , V_86 ) ;
F_113 ( & V_27 -> V_6 ) ;
F_24 ( V_85 ) ;
}
}
F_39 ( V_195 ) ;
}
F_146 ( V_229 , & V_47 -> V_230 ) ;
}
static bool F_147 ( struct V_31 * V_85 ,
char * * V_159 )
{
bool V_231 = false ;
unsigned long V_232 = V_233 ;
unsigned long V_234 = V_235 ;
if ( ( V_85 -> V_30 . V_59 & V_107 ) &&
F_110 ( V_85 -> V_119 , V_232 ) ) {
V_231 = true ;
* V_159 = L_22 ;
}
if ( ( V_85 -> V_30 . V_59 & V_203 ) &&
F_110 ( V_85 -> V_30 . V_114 , V_234 ) ) {
V_231 = true ;
* V_159 = L_23 ;
}
return V_231 ;
}
static void F_148 ( struct V_25 * V_26 )
{
struct V_16 * V_13 = V_26 -> V_12 . V_33 ;
struct V_17 * V_18 ;
struct V_1 * V_194 ;
T_5 * V_195 ;
T_1 V_151 ;
char * V_159 = NULL ;
struct V_5 * V_236 ;
struct V_31 * V_85 ;
for ( V_151 = 0 ; V_151 < V_13 -> V_11 ; V_151 ++ ) {
V_18 = & V_13 -> V_22 [ V_151 ] ;
V_195 = & V_13 -> V_196 [ V_151 ] ;
F_35 ( V_195 ) ;
F_109 (tt_common, node_tmp, head,
hash_entry) {
V_85 = F_2 ( V_236 ,
struct V_31 ,
V_30 ) ;
if ( ! F_147 ( V_85 , & V_159 ) )
continue;
F_61 ( V_87 , V_26 ,
L_1 ,
V_85 -> V_30 . V_14 ,
F_62 ( V_85 -> V_30 . V_9 ) ,
V_159 ) ;
F_113 ( & V_236 -> V_6 ) ;
F_24 ( V_85 ) ;
}
F_39 ( V_195 ) ;
}
}
static void F_149 ( struct V_25 * V_26 )
{
struct V_16 * V_13 ;
T_5 * V_195 ;
struct V_5 * V_27 ;
struct V_31 * V_85 ;
struct V_1 * V_194 ;
struct V_17 * V_18 ;
T_1 V_151 ;
if ( ! V_26 -> V_12 . V_33 )
return;
V_13 = V_26 -> V_12 . V_33 ;
for ( V_151 = 0 ; V_151 < V_13 -> V_11 ; V_151 ++ ) {
V_18 = & V_13 -> V_22 [ V_151 ] ;
V_195 = & V_13 -> V_196 [ V_151 ] ;
F_35 ( V_195 ) ;
F_109 (tt_common_entry, node_tmp,
head, hash_entry) {
F_113 ( & V_27 -> V_6 ) ;
V_85 = F_2 ( V_27 ,
struct V_31 ,
V_30 ) ;
F_24 ( V_85 ) ;
}
F_39 ( V_195 ) ;
}
F_114 ( V_13 ) ;
V_26 -> V_12 . V_33 = NULL ;
}
static bool
F_150 ( struct V_24 * V_28 ,
struct V_31 * V_32 )
{
bool V_98 = false ;
if ( V_28 -> V_30 . V_59 & V_113 &&
V_32 -> V_30 . V_59 & V_113 )
V_98 = true ;
if ( V_28 -> V_30 . V_59 & V_123 &&
V_32 -> V_30 . V_59 & V_123 )
V_98 = true ;
return V_98 ;
}
struct V_46 * F_151 ( struct V_25 * V_26 ,
const T_2 * V_237 ,
const T_2 * V_14 ,
unsigned short V_9 )
{
struct V_24 * V_28 = NULL ;
struct V_31 * V_32 = NULL ;
struct V_46 * V_47 = NULL ;
struct V_51 * V_212 ;
if ( V_237 && F_152 ( V_26 , V_9 ) ) {
V_28 = F_12 ( V_26 , V_237 , V_9 ) ;
if ( ! V_28 ||
( V_28 -> V_30 . V_59 & V_105 ) )
goto V_110;
}
V_32 = F_13 ( V_26 , V_14 , V_9 ) ;
if ( ! V_32 )
goto V_110;
if ( V_28 &&
F_150 ( V_28 , V_32 ) )
goto V_110;
F_8 () ;
V_212 = F_127 ( V_26 , V_32 ) ;
if ( V_212 )
V_47 = V_212 -> V_47 ;
if ( V_47 && ! F_10 ( & V_47 -> V_23 ) )
V_47 = NULL ;
F_11 () ;
V_110:
if ( V_32 )
F_24 ( V_32 ) ;
if ( V_28 )
F_19 ( V_28 ) ;
return V_47 ;
}
static T_1 F_153 ( struct V_25 * V_26 ,
struct V_46 * V_47 ,
unsigned short V_9 )
{
struct V_16 * V_13 = V_26 -> V_12 . V_33 ;
struct V_5 * V_236 ;
struct V_31 * V_85 ;
struct V_17 * V_18 ;
T_1 V_151 , V_238 , V_132 = 0 ;
T_2 V_59 ;
T_6 V_239 ;
for ( V_151 = 0 ; V_151 < V_13 -> V_11 ; V_151 ++ ) {
V_18 = & V_13 -> V_22 [ V_151 ] ;
F_8 () ;
F_9 (tt_common, head, hash_entry) {
V_85 = F_2 ( V_236 ,
struct V_31 ,
V_30 ) ;
if ( V_236 -> V_9 != V_9 )
continue;
if ( V_236 -> V_59 & V_107 )
continue;
if ( V_236 -> V_59 & V_203 )
continue;
if ( ! F_118 ( V_85 ,
V_47 ) )
continue;
V_239 = F_48 ( V_236 -> V_9 ) ;
V_238 = F_154 ( 0 , & V_239 , sizeof( V_239 ) ) ;
V_59 = V_236 -> V_59 & V_240 ;
V_238 = F_154 ( V_238 , & V_59 , sizeof( V_59 ) ) ;
V_132 ^= F_154 ( V_238 , V_236 -> V_14 , V_15 ) ;
}
F_11 () ;
}
return V_132 ;
}
static T_1 F_155 ( struct V_25 * V_26 ,
unsigned short V_9 )
{
struct V_16 * V_13 = V_26 -> V_12 . V_29 ;
struct V_5 * V_236 ;
struct V_17 * V_18 ;
T_1 V_151 , V_238 , V_132 = 0 ;
T_2 V_59 ;
T_6 V_239 ;
for ( V_151 = 0 ; V_151 < V_13 -> V_11 ; V_151 ++ ) {
V_18 = & V_13 -> V_22 [ V_151 ] ;
F_8 () ;
F_9 (tt_common, head, hash_entry) {
if ( V_236 -> V_9 != V_9 )
continue;
if ( V_236 -> V_59 & V_112 )
continue;
V_239 = F_48 ( V_236 -> V_9 ) ;
V_238 = F_154 ( 0 , & V_239 , sizeof( V_239 ) ) ;
V_59 = V_236 -> V_59 & V_240 ;
V_238 = F_154 ( V_238 , & V_59 , sizeof( V_59 ) ) ;
V_132 ^= F_154 ( V_238 , V_236 -> V_14 , V_15 ) ;
}
F_11 () ;
}
return V_132 ;
}
static void F_156 ( struct V_37 * V_38 )
{
struct V_241 * V_242 ;
V_242 = F_2 ( V_38 , struct V_241 , V_23 ) ;
F_15 ( V_243 , V_242 ) ;
}
static void F_157 ( struct V_241 * V_242 )
{
F_20 ( & V_242 -> V_23 , F_156 ) ;
}
static void F_158 ( struct V_25 * V_26 )
{
struct V_241 * V_2 ;
struct V_1 * V_58 ;
F_35 ( & V_26 -> V_12 . V_244 ) ;
F_109 (node, safe, &bat_priv->tt.req_list, list) {
F_159 ( & V_2 -> V_50 ) ;
F_157 ( V_2 ) ;
}
F_39 ( & V_26 -> V_12 . V_244 ) ;
}
static void F_160 ( struct V_25 * V_26 ,
struct V_46 * V_47 ,
const void * V_245 ,
T_3 V_246 )
{
F_35 ( & V_47 -> V_247 ) ;
if ( V_246 > 0 ) {
F_83 ( V_47 -> V_245 ) ;
V_47 -> V_246 = 0 ;
V_47 -> V_245 = F_78 ( V_246 , V_64 ) ;
if ( V_47 -> V_245 ) {
memcpy ( V_47 -> V_245 , V_245 , V_246 ) ;
V_47 -> V_246 = V_246 ;
}
}
F_39 ( & V_47 -> V_247 ) ;
}
static void F_161 ( struct V_25 * V_26 )
{
struct V_241 * V_2 ;
struct V_1 * V_58 ;
F_35 ( & V_26 -> V_12 . V_244 ) ;
F_109 (node, safe, &bat_priv->tt.req_list, list) {
if ( F_110 ( V_2 -> V_248 ,
V_249 ) ) {
F_159 ( & V_2 -> V_50 ) ;
F_157 ( V_2 ) ;
}
}
F_39 ( & V_26 -> V_12 . V_244 ) ;
}
static struct V_241 *
F_162 ( struct V_25 * V_26 ,
struct V_46 * V_47 )
{
struct V_241 * V_250 , * V_242 = NULL ;
F_35 ( & V_26 -> V_12 . V_244 ) ;
F_163 (tt_req_node_tmp, &bat_priv->tt.req_list, list) {
if ( F_3 ( V_250 , V_47 ) &&
! F_110 ( V_250 -> V_248 ,
V_249 ) )
goto V_70;
}
V_242 = F_47 ( V_243 , V_64 ) ;
if ( ! V_242 )
goto V_70;
F_71 ( & V_242 -> V_23 ) ;
F_7 ( V_242 -> V_14 , V_47 -> V_202 ) ;
V_242 -> V_248 = V_104 ;
F_72 ( & V_242 -> V_23 ) ;
F_164 ( & V_242 -> V_50 , & V_26 -> V_12 . V_251 ) ;
V_70:
F_39 ( & V_26 -> V_12 . V_244 ) ;
return V_242 ;
}
static bool F_165 ( const void * V_252 , const void * V_253 )
{
const struct V_5 * V_27 = V_252 ;
if ( V_27 -> V_59 & V_112 )
return false ;
return true ;
}
static bool F_166 ( const void * V_252 ,
const void * V_253 )
{
const struct V_5 * V_27 = V_252 ;
const struct V_31 * V_32 ;
const struct V_46 * V_47 = V_253 ;
if ( V_27 -> V_59 & V_107 ||
V_27 -> V_59 & V_203 )
return false ;
V_32 = F_2 ( V_27 ,
struct V_31 ,
V_30 ) ;
return F_118 ( V_32 , V_47 ) ;
}
static void F_167 ( struct V_25 * V_26 ,
struct V_16 * V_13 ,
void * V_254 , T_3 V_75 ,
bool (* F_168)( const void * ,
const void * ) ,
void * V_255 )
{
struct V_5 * V_27 ;
struct V_74 * V_125 ;
struct V_17 * V_18 ;
T_3 V_256 , V_257 = 0 ;
T_1 V_151 ;
V_256 = F_55 ( V_75 ) ;
V_125 = (struct V_74 * ) V_254 ;
F_8 () ;
for ( V_151 = 0 ; V_151 < V_13 -> V_11 ; V_151 ++ ) {
V_18 = & V_13 -> V_22 [ V_151 ] ;
F_9 (tt_common_entry,
head, hash_entry) {
if ( V_256 == V_257 )
break;
if ( ( F_168 ) && ( ! F_168 ( V_27 , V_255 ) ) )
continue;
F_7 ( V_125 -> V_14 , V_27 -> V_14 ) ;
V_125 -> V_59 = V_27 -> V_59 ;
V_125 -> V_9 = F_48 ( V_27 -> V_9 ) ;
memset ( V_125 -> V_66 , 0 ,
sizeof( V_125 -> V_66 ) ) ;
V_257 ++ ;
V_125 ++ ;
}
}
F_11 () ;
}
static bool F_169 ( struct V_46 * V_47 ,
struct V_82 * V_128 ,
T_3 V_76 )
{
struct V_82 * V_258 ;
struct V_48 * V_39 ;
int V_151 , V_259 ;
T_1 V_132 ;
for ( V_151 = 0 ; V_151 < V_76 ; V_151 ++ ) {
V_258 = V_128 + V_151 ;
if ( F_124 ( V_47 -> V_26 ,
V_47 -> V_202 ,
F_170 ( V_258 -> V_9 ) ) )
continue;
V_39 = F_131 ( V_47 ,
F_170 ( V_258 -> V_9 ) ) ;
if ( ! V_39 )
return false ;
V_132 = V_39 -> V_12 . V_132 ;
F_38 ( V_39 ) ;
if ( V_132 != F_171 ( V_258 -> V_132 ) )
return false ;
}
F_8 () ;
V_259 = 0 ;
F_9 (vlan, &orig_node->vlan_list, list)
V_259 ++ ;
F_11 () ;
if ( V_259 > V_76 )
return false ;
return true ;
}
static void F_172 ( struct V_25 * V_26 )
{
struct V_44 * V_39 ;
F_8 () ;
F_9 (vlan, &bat_priv->softif_vlan_list, list) {
V_39 -> V_12 . V_132 = F_155 ( V_26 , V_39 -> V_9 ) ;
}
F_11 () ;
}
static void F_173 ( struct V_25 * V_26 ,
struct V_46 * V_47 )
{
struct V_48 * V_39 ;
T_1 V_132 ;
F_8 () ;
F_9 (vlan, &orig_node->vlan_list, list) {
if ( F_124 ( V_26 , V_47 -> V_202 ,
V_39 -> V_9 ) )
continue;
V_132 = F_153 ( V_26 , V_47 , V_39 -> V_9 ) ;
V_39 -> V_12 . V_132 = V_132 ;
}
F_11 () ;
}
static bool F_174 ( struct V_25 * V_26 ,
struct V_46 * V_260 ,
T_2 V_130 ,
struct V_82 * V_128 ,
T_3 V_76 , bool V_261 )
{
struct V_81 * V_262 = NULL ;
struct V_241 * V_242 = NULL ;
struct V_82 * V_263 ;
struct V_149 * V_150 ;
bool V_98 = false ;
int V_151 , V_11 ;
V_150 = F_105 ( V_26 ) ;
if ( ! V_150 )
goto V_110;
V_242 = F_162 ( V_26 , V_260 ) ;
if ( ! V_242 )
goto V_110;
V_11 = sizeof( * V_262 ) + sizeof( * V_263 ) * V_76 ;
V_262 = F_84 ( V_11 , V_64 ) ;
if ( ! V_262 )
goto V_110;
V_262 -> V_59 = V_264 ;
V_262 -> V_130 = V_130 ;
V_262 -> V_76 = F_48 ( V_76 ) ;
V_263 = (struct V_82 * ) ( V_262 + 1 ) ;
for ( V_151 = 0 ; V_151 < V_76 ; V_151 ++ ) {
V_263 -> V_9 = V_128 -> V_9 ;
V_263 -> V_132 = V_128 -> V_132 ;
V_263 ++ ;
V_128 ++ ;
}
if ( V_261 )
V_262 -> V_59 |= V_265 ;
F_61 ( V_87 , V_26 , L_24 ,
V_260 -> V_202 , V_261 ? 'F' : '.' ) ;
F_175 ( V_26 , V_266 ) ;
F_176 ( V_26 , V_150 -> V_147 -> V_115 ,
V_260 -> V_202 , V_143 , 1 ,
V_262 , V_11 ) ;
V_98 = true ;
V_110:
if ( V_150 )
F_91 ( V_150 ) ;
if ( V_98 && V_242 ) {
F_35 ( & V_26 -> V_12 . V_244 ) ;
if ( ! F_36 ( & V_242 -> V_50 ) ) {
F_159 ( & V_242 -> V_50 ) ;
F_157 ( V_242 ) ;
}
F_39 ( & V_26 -> V_12 . V_244 ) ;
}
if ( V_242 )
F_157 ( V_242 ) ;
F_83 ( V_262 ) ;
return V_98 ;
}
static bool F_177 ( struct V_25 * V_26 ,
struct V_81 * V_124 ,
T_2 * V_267 , T_2 * V_268 )
{
struct V_46 * V_269 ;
struct V_46 * V_270 = NULL ;
struct V_74 * V_125 ;
struct V_81 * V_262 = NULL ;
struct V_82 * V_128 ;
bool V_98 = false , V_261 ;
T_2 V_271 , V_272 ;
T_3 V_127 ;
T_4 V_75 ;
F_61 ( V_87 , V_26 ,
L_25 ,
V_267 , V_124 -> V_130 , V_268 ,
( ( V_124 -> V_59 & V_265 ) ? 'F' : '.' ) ) ;
V_269 = F_178 ( V_26 , V_268 ) ;
if ( ! V_269 )
goto V_110;
V_270 = F_178 ( V_26 , V_267 ) ;
if ( ! V_270 )
goto V_110;
V_271 = ( T_2 ) F_26 ( & V_269 -> V_131 ) ;
V_272 = V_124 -> V_130 ;
V_128 = (struct V_82 * ) ( V_124 + 1 ) ;
if ( V_271 != V_272 ||
! F_169 ( V_269 , V_128 ,
F_170 ( V_124 -> V_76 ) ) )
goto V_110;
if ( V_124 -> V_59 & V_265 ||
! V_269 -> V_245 )
V_261 = true ;
else
V_261 = false ;
if ( ! V_261 ) {
F_35 ( & V_269 -> V_247 ) ;
V_75 = V_269 -> V_246 ;
V_127 = F_77 ( V_269 ,
& V_262 ,
& V_125 ,
& V_75 ) ;
if ( ! V_75 )
goto V_70;
memcpy ( V_125 , V_269 -> V_245 ,
V_269 -> V_246 ) ;
F_39 ( & V_269 -> V_247 ) ;
} else {
V_75 = - 1 ;
V_127 = F_77 ( V_269 ,
& V_262 ,
& V_125 ,
& V_75 ) ;
if ( ! V_75 )
goto V_110;
F_167 ( V_26 , V_26 -> V_12 . V_33 ,
V_125 , V_75 ,
F_166 ,
V_269 ) ;
}
V_75 = sizeof( struct V_79 ) + V_127 ;
if ( V_75 > F_26 ( & V_26 -> V_97 ) ) {
F_69 ( V_109 , V_26 -> V_89 ,
L_26 ,
V_270 -> V_202 ) ;
goto V_110;
}
V_262 -> V_59 = V_273 ;
V_262 -> V_130 = V_272 ;
if ( V_261 )
V_262 -> V_59 |= V_265 ;
F_61 ( V_87 , V_26 ,
L_27 ,
V_270 -> V_202 , V_269 -> V_202 ,
V_261 ? 'F' : '.' , V_272 ) ;
F_175 ( V_26 , V_274 ) ;
F_176 ( V_26 , V_269 -> V_202 ,
V_267 , V_143 , 1 , V_262 ,
V_127 ) ;
V_98 = true ;
goto V_110;
V_70:
F_39 ( & V_269 -> V_247 ) ;
V_110:
if ( V_270 )
F_44 ( V_270 ) ;
if ( V_269 )
F_44 ( V_269 ) ;
F_83 ( V_262 ) ;
return V_98 ;
}
static bool F_179 ( struct V_25 * V_26 ,
struct V_81 * V_124 ,
T_2 * V_267 )
{
struct V_81 * V_262 = NULL ;
struct V_149 * V_150 = NULL ;
struct V_74 * V_125 ;
struct V_46 * V_47 ;
T_2 V_275 , V_272 ;
T_3 V_127 ;
bool V_261 ;
T_4 V_75 ;
F_61 ( V_87 , V_26 ,
L_28 ,
V_267 , V_124 -> V_130 ,
( ( V_124 -> V_59 & V_265 ) ? 'F' : '.' ) ) ;
F_35 ( & V_26 -> V_12 . V_276 ) ;
V_275 = ( T_2 ) F_26 ( & V_26 -> V_12 . V_111 ) ;
V_272 = V_124 -> V_130 ;
V_47 = F_178 ( V_26 , V_267 ) ;
if ( ! V_47 )
goto V_110;
V_150 = F_105 ( V_26 ) ;
if ( ! V_150 )
goto V_110;
if ( V_124 -> V_59 & V_265 || V_275 != V_272 ||
! V_26 -> V_12 . V_141 )
V_261 = true ;
else
V_261 = false ;
if ( ! V_261 ) {
F_35 ( & V_26 -> V_12 . V_140 ) ;
V_75 = V_26 -> V_12 . V_142 ;
V_127 = F_80 ( V_26 ,
& V_262 ,
& V_125 ,
& V_75 ) ;
if ( ! V_75 || ! V_127 )
goto V_70;
memcpy ( V_125 , V_26 -> V_12 . V_141 ,
V_26 -> V_12 . V_142 ) ;
F_39 ( & V_26 -> V_12 . V_140 ) ;
} else {
V_272 = ( T_2 ) F_26 ( & V_26 -> V_12 . V_111 ) ;
V_75 = - 1 ;
V_127 = F_80 ( V_26 ,
& V_262 ,
& V_125 ,
& V_75 ) ;
if ( ! V_75 || ! V_127 )
goto V_110;
F_167 ( V_26 , V_26 -> V_12 . V_29 ,
V_125 , V_75 ,
F_165 , NULL ) ;
}
V_262 -> V_59 = V_273 ;
V_262 -> V_130 = V_272 ;
if ( V_261 )
V_262 -> V_59 |= V_265 ;
F_61 ( V_87 , V_26 ,
L_29 ,
V_47 -> V_202 , V_261 ? 'F' : '.' , V_272 ) ;
F_175 ( V_26 , V_274 ) ;
F_176 ( V_26 , V_150 -> V_147 -> V_115 ,
V_267 , V_143 , 1 , V_262 ,
V_127 ) ;
goto V_110;
V_70:
F_39 ( & V_26 -> V_12 . V_140 ) ;
V_110:
F_39 ( & V_26 -> V_12 . V_276 ) ;
if ( V_47 )
F_44 ( V_47 ) ;
if ( V_150 )
F_91 ( V_150 ) ;
F_83 ( V_262 ) ;
return true ;
}
static bool F_180 ( struct V_25 * V_26 ,
struct V_81 * V_124 ,
T_2 * V_267 , T_2 * V_268 )
{
if ( F_181 ( V_26 , V_268 ) )
return F_179 ( V_26 , V_124 , V_267 ) ;
return F_177 ( V_26 , V_124 , V_267 ,
V_268 ) ;
}
static void F_182 ( struct V_25 * V_26 ,
struct V_46 * V_47 ,
struct V_74 * V_125 ,
T_3 V_277 , T_2 V_130 )
{
int V_151 ;
int V_278 ;
for ( V_151 = 0 ; V_151 < V_277 ; V_151 ++ ) {
if ( ( V_125 + V_151 ) -> V_59 & V_67 ) {
V_278 = ( V_125 + V_151 ) -> V_59 & V_107 ;
F_143 ( V_26 , V_47 ,
( V_125 + V_151 ) -> V_14 ,
F_170 ( ( V_125 + V_151 ) -> V_9 ) ,
L_30 ,
V_278 ) ;
} else {
if ( ! F_123 ( V_26 , V_47 ,
( V_125 + V_151 ) -> V_14 ,
F_170 ( ( V_125 + V_151 ) -> V_9 ) ,
( V_125 + V_151 ) -> V_59 , V_130 ) )
return;
}
}
F_183 ( V_229 , & V_47 -> V_230 ) ;
}
static void F_184 ( struct V_25 * V_26 ,
struct V_74 * V_125 ,
T_2 V_130 , T_2 * V_279 ,
T_3 V_45 )
{
struct V_46 * V_47 ;
V_47 = F_178 ( V_26 , V_279 ) ;
if ( ! V_47 )
goto V_110;
F_145 ( V_26 , V_47 , - 1 ,
L_31 ) ;
F_182 ( V_26 , V_47 , V_125 , V_45 ,
V_130 ) ;
F_35 ( & V_47 -> V_247 ) ;
F_83 ( V_47 -> V_245 ) ;
V_47 -> V_246 = 0 ;
V_47 -> V_245 = NULL ;
F_39 ( & V_47 -> V_247 ) ;
F_82 ( & V_47 -> V_131 , V_130 ) ;
V_110:
if ( V_47 )
F_44 ( V_47 ) ;
}
static void F_185 ( struct V_25 * V_26 ,
struct V_46 * V_47 ,
T_3 V_277 , T_2 V_130 ,
struct V_74 * V_125 )
{
F_182 ( V_26 , V_47 , V_125 ,
V_277 , V_130 ) ;
F_160 ( V_26 , V_47 , V_125 ,
F_54 ( V_277 ) ) ;
F_82 ( & V_47 -> V_131 , V_130 ) ;
}
bool F_186 ( struct V_25 * V_26 , const T_2 * V_14 ,
unsigned short V_9 )
{
struct V_24 * V_28 ;
bool V_98 = false ;
V_28 = F_12 ( V_26 , V_14 , V_9 ) ;
if ( ! V_28 )
goto V_110;
if ( ( V_28 -> V_30 . V_59 & V_105 ) ||
( V_28 -> V_30 . V_59 & V_107 ) )
goto V_110;
V_98 = true ;
V_110:
if ( V_28 )
F_19 ( V_28 ) ;
return V_98 ;
}
static void F_187 ( struct V_25 * V_26 ,
struct V_81 * V_124 ,
T_2 * V_279 , T_3 V_45 )
{
struct V_241 * V_2 ;
struct V_1 * V_58 ;
struct V_46 * V_47 = NULL ;
struct V_74 * V_125 ;
T_2 * V_280 = ( T_2 * ) V_124 ;
T_3 V_126 ;
F_61 ( V_87 , V_26 ,
L_32 ,
V_279 , V_124 -> V_130 , V_45 ,
( ( V_124 -> V_59 & V_265 ) ? 'F' : '.' ) ) ;
V_47 = F_178 ( V_26 , V_279 ) ;
if ( ! V_47 )
goto V_110;
F_35 ( & V_47 -> V_281 ) ;
V_126 = sizeof( struct V_82 ) ;
V_126 *= F_170 ( V_124 -> V_76 ) ;
V_126 += sizeof( * V_124 ) ;
V_280 += V_126 ;
V_125 = (struct V_74 * ) V_280 ;
if ( V_124 -> V_59 & V_265 ) {
F_184 ( V_26 , V_125 , V_124 -> V_130 ,
V_279 , V_45 ) ;
} else {
F_185 ( V_26 , V_47 , V_45 ,
V_124 -> V_130 , V_125 ) ;
}
F_173 ( V_26 , V_47 ) ;
F_39 ( & V_47 -> V_281 ) ;
F_35 ( & V_26 -> V_12 . V_244 ) ;
F_109 (node, safe, &bat_priv->tt.req_list, list) {
if ( ! F_3 ( V_2 -> V_14 , V_279 ) )
continue;
F_159 ( & V_2 -> V_50 ) ;
F_157 ( V_2 ) ;
}
F_39 ( & V_26 -> V_12 . V_244 ) ;
V_110:
if ( V_47 )
F_44 ( V_47 ) ;
}
static void F_188 ( struct V_25 * V_26 )
{
struct V_282 * V_2 , * V_58 ;
F_35 ( & V_26 -> V_12 . V_283 ) ;
F_49 (node, safe, &bat_priv->tt.roam_list, list) {
F_50 ( & V_2 -> V_50 ) ;
F_15 ( V_284 , V_2 ) ;
}
F_39 ( & V_26 -> V_12 . V_283 ) ;
}
static void F_189 ( struct V_25 * V_26 )
{
struct V_282 * V_2 , * V_58 ;
F_35 ( & V_26 -> V_12 . V_283 ) ;
F_49 (node, safe, &bat_priv->tt.roam_list, list) {
if ( ! F_110 ( V_2 -> V_285 ,
V_286 ) )
continue;
F_50 ( & V_2 -> V_50 ) ;
F_15 ( V_284 , V_2 ) ;
}
F_39 ( & V_26 -> V_12 . V_283 ) ;
}
static bool F_190 ( struct V_25 * V_26 , T_2 * V_287 )
{
struct V_282 * V_288 ;
bool V_98 = false ;
F_35 ( & V_26 -> V_12 . V_283 ) ;
F_191 (tt_roam_node, &bat_priv->tt.roam_list, list) {
if ( ! F_3 ( V_288 -> V_14 , V_287 ) )
continue;
if ( F_110 ( V_288 -> V_285 ,
V_286 ) )
continue;
if ( ! F_192 ( & V_288 -> V_289 ) )
goto V_70;
V_98 = true ;
break;
}
if ( ! V_98 ) {
V_288 = F_47 ( V_284 ,
V_64 ) ;
if ( ! V_288 )
goto V_70;
V_288 -> V_285 = V_104 ;
F_82 ( & V_288 -> V_289 ,
V_290 - 1 ) ;
F_7 ( V_288 -> V_14 , V_287 ) ;
F_193 ( & V_288 -> V_50 , & V_26 -> V_12 . V_291 ) ;
V_98 = true ;
}
V_70:
F_39 ( & V_26 -> V_12 . V_283 ) ;
return V_98 ;
}
static void F_75 ( struct V_25 * V_26 , T_2 * V_287 ,
unsigned short V_9 ,
struct V_46 * V_47 )
{
struct V_149 * V_150 ;
struct V_292 V_293 ;
V_150 = F_105 ( V_26 ) ;
if ( ! V_150 )
goto V_110;
if ( ! F_190 ( V_26 , V_287 ) )
goto V_110;
F_61 ( V_87 , V_26 ,
L_33 ,
V_47 -> V_202 , V_287 , F_62 ( V_9 ) ) ;
F_175 ( V_26 , V_294 ) ;
memcpy ( V_293 . V_287 , V_287 , sizeof( V_293 . V_287 ) ) ;
V_293 . V_9 = F_48 ( V_9 ) ;
F_176 ( V_26 , V_150 -> V_147 -> V_115 ,
V_47 -> V_202 , V_295 , 1 ,
& V_293 , sizeof( V_293 ) ) ;
V_110:
if ( V_150 )
F_91 ( V_150 ) ;
}
static void F_194 ( struct V_296 * V_297 )
{
struct V_298 * V_298 ;
struct V_299 * V_300 ;
struct V_25 * V_26 ;
V_298 = F_195 ( V_297 ) ;
V_300 = F_2 ( V_298 , struct V_299 , V_297 ) ;
V_26 = F_2 ( V_300 , struct V_25 , V_12 ) ;
F_111 ( V_26 , V_301 ) ;
F_148 ( V_26 ) ;
F_161 ( V_26 ) ;
F_189 ( V_26 ) ;
F_196 ( V_302 , & V_26 -> V_12 . V_297 ,
F_197 ( V_303 ) ) ;
}
void F_198 ( struct V_25 * V_26 )
{
F_199 ( V_26 , V_143 , 1 ) ;
F_200 ( V_26 , V_143 , 1 ) ;
F_201 ( & V_26 -> V_12 . V_297 ) ;
F_112 ( V_26 ) ;
F_149 ( V_26 ) ;
F_158 ( V_26 ) ;
F_116 ( V_26 ) ;
F_188 ( V_26 ) ;
F_83 ( V_26 -> V_12 . V_141 ) ;
}
static void F_202 ( struct V_25 * V_26 , T_3 V_59 ,
bool V_304 , bool V_41 )
{
struct V_16 * V_13 = V_26 -> V_12 . V_29 ;
struct V_5 * V_27 ;
T_3 V_305 = 0 ;
struct V_17 * V_18 ;
T_1 V_151 ;
if ( ! V_13 )
return;
for ( V_151 = 0 ; V_151 < V_13 -> V_11 ; V_151 ++ ) {
V_18 = & V_13 -> V_22 [ V_151 ] ;
F_8 () ;
F_9 (tt_common_entry,
head, hash_entry) {
if ( V_304 ) {
if ( ( V_27 -> V_59 & V_59 ) == V_59 )
continue;
V_27 -> V_59 |= V_59 ;
} else {
if ( ! ( V_27 -> V_59 & V_59 ) )
continue;
V_27 -> V_59 &= ~ V_59 ;
}
V_305 ++ ;
if ( ! V_41 )
continue;
F_30 ( V_26 ,
V_27 -> V_9 ) ;
}
F_11 () ;
}
}
static void F_203 ( struct V_25 * V_26 )
{
struct V_16 * V_13 = V_26 -> V_12 . V_29 ;
struct V_5 * V_236 ;
struct V_24 * V_92 ;
struct V_1 * V_194 ;
struct V_17 * V_18 ;
T_5 * V_195 ;
T_1 V_151 ;
if ( ! V_13 )
return;
for ( V_151 = 0 ; V_151 < V_13 -> V_11 ; V_151 ++ ) {
V_18 = & V_13 -> V_22 [ V_151 ] ;
V_195 = & V_13 -> V_196 [ V_151 ] ;
F_35 ( V_195 ) ;
F_109 (tt_common, node_tmp, head,
hash_entry) {
if ( ! ( V_236 -> V_59 & V_105 ) )
continue;
F_61 ( V_87 , V_26 ,
L_34 ,
V_236 -> V_14 ,
F_62 ( V_236 -> V_9 ) ) ;
F_31 ( V_26 , V_236 -> V_9 ) ;
F_113 ( & V_236 -> V_6 ) ;
V_92 = F_2 ( V_236 ,
struct V_24 ,
V_30 ) ;
F_19 ( V_92 ) ;
}
F_39 ( V_195 ) ;
}
}
static void F_204 ( struct V_25 * V_26 )
{
F_140 ( & V_26 -> V_12 . V_276 ) ;
F_205 ( V_26 ) ;
if ( F_26 ( & V_26 -> V_12 . V_72 ) < 1 ) {
if ( ! F_192 ( & V_26 -> V_12 . V_306 ) )
F_81 ( V_26 ) ;
return;
}
F_202 ( V_26 , V_112 , false , true ) ;
F_203 ( V_26 ) ;
F_172 ( V_26 ) ;
F_53 ( & V_26 -> V_12 . V_111 ) ;
F_61 ( V_87 , V_26 ,
L_35 ,
( T_2 ) F_26 ( & V_26 -> V_12 . V_111 ) ) ;
F_82 ( & V_26 -> V_12 . V_306 , V_307 ) ;
F_81 ( V_26 ) ;
}
void F_206 ( struct V_25 * V_26 )
{
F_35 ( & V_26 -> V_12 . V_276 ) ;
F_204 ( V_26 ) ;
F_39 ( & V_26 -> V_12 . V_276 ) ;
}
bool F_207 ( struct V_25 * V_26 , T_2 * V_237 , T_2 * V_308 ,
unsigned short V_9 )
{
struct V_24 * V_28 = NULL ;
struct V_31 * V_32 = NULL ;
struct V_44 * V_39 ;
bool V_98 = false ;
V_39 = F_28 ( V_26 , V_9 ) ;
if ( ! V_39 )
return false ;
if ( ! F_26 ( & V_39 -> V_309 ) )
goto V_110;
V_28 = F_12 ( V_26 , V_308 , V_9 ) ;
if ( ! V_28 )
goto V_110;
V_32 = F_13 ( V_26 , V_237 , V_9 ) ;
if ( ! V_32 )
goto V_110;
if ( ! F_150 ( V_28 , V_32 ) )
goto V_110;
V_98 = true ;
V_110:
F_17 ( V_39 ) ;
if ( V_32 )
F_24 ( V_32 ) ;
if ( V_28 )
F_19 ( V_28 ) ;
return V_98 ;
}
static void F_208 ( struct V_25 * V_26 ,
struct V_46 * V_47 ,
const void * V_245 , T_3 V_310 ,
struct V_74 * V_125 ,
T_3 V_277 , T_2 V_130 )
{
T_2 V_271 = ( T_2 ) F_26 ( & V_47 -> V_131 ) ;
struct V_82 * V_128 ;
bool V_261 = true ;
bool V_311 ;
V_128 = (struct V_82 * ) V_245 ;
V_311 = F_209 ( V_229 ,
& V_47 -> V_230 ) ;
if ( ( ! V_311 && V_130 == 1 ) || V_130 - V_271 == 1 ) {
if ( ! V_277 ) {
V_261 = false ;
goto V_312;
}
F_35 ( & V_47 -> V_281 ) ;
F_185 ( V_26 , V_47 , V_277 ,
V_130 , V_125 ) ;
F_173 ( V_26 , V_47 ) ;
F_39 ( & V_47 -> V_281 ) ;
if ( ! F_169 ( V_47 , V_128 ,
V_310 ) )
goto V_312;
} else {
if ( ! V_311 || V_130 != V_271 ||
! F_169 ( V_47 , V_128 ,
V_310 ) ) {
V_312:
F_61 ( V_87 , V_26 ,
L_36 ,
V_47 -> V_202 , V_130 , V_271 ,
V_277 ) ;
F_174 ( V_26 , V_47 , V_130 ,
V_128 , V_310 ,
V_261 ) ;
return;
}
}
}
bool F_210 ( struct V_25 * V_26 ,
T_2 * V_14 , unsigned short V_9 )
{
struct V_31 * V_32 ;
bool V_98 = false ;
V_32 = F_13 ( V_26 , V_14 , V_9 ) ;
if ( ! V_32 )
goto V_110;
V_98 = V_32 -> V_30 . V_59 & V_107 ;
F_24 ( V_32 ) ;
V_110:
return V_98 ;
}
bool F_211 ( struct V_25 * V_26 ,
T_2 * V_14 , unsigned short V_9 )
{
struct V_24 * V_28 ;
bool V_98 = false ;
V_28 = F_12 ( V_26 , V_14 , V_9 ) ;
if ( ! V_28 )
goto V_110;
V_98 = V_28 -> V_30 . V_59 & V_107 ;
F_19 ( V_28 ) ;
V_110:
return V_98 ;
}
bool F_212 ( struct V_25 * V_26 ,
struct V_46 * V_47 ,
const unsigned char * V_14 ,
unsigned short V_9 )
{
bool V_98 = false ;
if ( ! F_123 ( V_26 , V_47 , V_14 , V_9 ,
V_203 ,
F_26 ( & V_47 -> V_131 ) ) )
goto V_110;
F_61 ( V_87 , V_26 ,
L_37 ,
V_14 , F_62 ( V_9 ) , V_47 -> V_202 ) ;
V_98 = true ;
V_110:
return V_98 ;
}
void F_213 ( struct V_88 * V_89 )
{
struct V_25 * V_26 = F_65 ( V_89 ) ;
int V_97 = F_26 ( & V_26 -> V_97 ) ;
int V_96 , V_193 = V_301 / 2 ;
bool V_313 = false ;
F_35 ( & V_26 -> V_12 . V_276 ) ;
while ( true ) {
V_96 = F_56 ( V_26 ) ;
if ( V_97 >= V_96 )
break;
F_111 ( V_26 , V_193 ) ;
F_203 ( V_26 ) ;
V_193 /= 2 ;
V_313 = true ;
F_69 ( V_109 , V_89 ,
L_38 ,
V_97 ) ;
}
if ( V_313 )
F_204 ( V_26 ) ;
F_39 ( & V_26 -> V_12 . V_276 ) ;
}
static void F_214 ( struct V_25 * V_26 ,
struct V_46 * V_202 ,
T_2 V_59 , void * V_314 ,
T_3 V_315 )
{
struct V_82 * V_128 ;
struct V_74 * V_125 ;
struct V_81 * V_124 ;
T_3 V_45 , V_76 ;
if ( V_315 < sizeof( * V_124 ) )
return;
V_124 = (struct V_81 * ) V_314 ;
V_315 -= sizeof( * V_124 ) ;
V_76 = F_170 ( V_124 -> V_76 ) ;
if ( V_315 < sizeof( * V_128 ) * V_76 )
return;
V_128 = (struct V_82 * ) ( V_124 + 1 ) ;
V_125 = (struct V_74 * ) ( V_128 + V_76 ) ;
V_315 -= sizeof( * V_128 ) * V_76 ;
V_45 = F_55 ( V_315 ) ;
F_208 ( V_26 , V_202 , V_128 , V_76 , V_125 ,
V_45 , V_124 -> V_130 ) ;
}
static int F_215 ( struct V_25 * V_26 ,
T_2 * V_237 , T_2 * V_308 ,
void * V_314 ,
T_3 V_315 )
{
struct V_81 * V_124 ;
T_3 V_316 , V_257 ;
char V_317 ;
bool V_98 ;
if ( V_315 < sizeof( * V_124 ) )
return V_318 ;
V_124 = (struct V_81 * ) V_314 ;
V_315 -= sizeof( * V_124 ) ;
V_316 = sizeof( struct V_82 ) ;
V_316 *= F_170 ( V_124 -> V_76 ) ;
if ( V_315 < V_316 )
return V_318 ;
V_315 -= V_316 ;
V_257 = F_55 ( V_315 ) ;
switch ( V_124 -> V_59 & V_319 ) {
case V_264 :
F_175 ( V_26 , V_320 ) ;
V_98 = F_180 ( V_26 , V_124 , V_237 , V_308 ) ;
if ( ! V_98 ) {
if ( V_124 -> V_59 & V_265 )
V_317 = 'F' ;
else
V_317 = '.' ;
F_61 ( V_87 , V_26 ,
L_39 ,
V_308 , V_317 ) ;
return V_321 ;
}
break;
case V_273 :
F_175 ( V_26 , V_322 ) ;
if ( F_181 ( V_26 , V_308 ) ) {
F_187 ( V_26 , V_124 ,
V_237 , V_257 ) ;
return V_318 ;
}
if ( V_124 -> V_59 & V_265 )
V_317 = 'F' ;
else
V_317 = '.' ;
F_61 ( V_87 , V_26 ,
L_40 , V_308 , V_317 ) ;
return V_321 ;
}
return V_318 ;
}
static int F_216 ( struct V_25 * V_26 ,
T_2 * V_237 , T_2 * V_308 ,
void * V_314 ,
T_3 V_315 )
{
struct V_292 * V_323 ;
struct V_46 * V_47 = NULL ;
if ( ! F_181 ( V_26 , V_308 ) )
return V_321 ;
if ( V_315 < sizeof( * V_323 ) )
goto V_110;
V_47 = F_178 ( V_26 , V_237 ) ;
if ( ! V_47 )
goto V_110;
F_175 ( V_26 , V_324 ) ;
V_323 = (struct V_292 * ) V_314 ;
F_61 ( V_87 , V_26 ,
L_41 ,
V_237 , V_323 -> V_287 ) ;
F_123 ( V_26 , V_47 , V_323 -> V_287 ,
F_170 ( V_323 -> V_9 ) , V_107 ,
F_26 ( & V_47 -> V_131 ) + 1 ) ;
V_110:
if ( V_47 )
F_44 ( V_47 ) ;
return V_318 ;
}
int F_217 ( struct V_25 * V_26 )
{
int V_98 ;
F_218 ( ! ( V_240 & V_120 ) ) ;
V_98 = F_57 ( V_26 ) ;
if ( V_98 < 0 )
return V_98 ;
V_98 = F_115 ( V_26 ) ;
if ( V_98 < 0 )
return V_98 ;
F_219 ( V_26 , F_214 ,
F_215 ,
V_143 , 1 , V_117 ) ;
F_219 ( V_26 , NULL ,
F_216 ,
V_295 , 1 , V_117 ) ;
F_220 ( & V_26 -> V_12 . V_297 , F_194 ) ;
F_196 ( V_302 , & V_26 -> V_12 . V_297 ,
F_197 ( V_303 ) ) ;
return 1 ;
}
bool F_221 ( struct V_25 * V_26 ,
const T_2 * V_14 , unsigned short V_9 )
{
struct V_31 * V_12 ;
bool V_98 ;
V_12 = F_13 ( V_26 , V_14 , V_9 ) ;
if ( ! V_12 )
return false ;
V_98 = V_12 -> V_30 . V_59 & V_123 ;
F_24 ( V_12 ) ;
return V_98 ;
}
int T_7 F_222 ( void )
{
T_8 V_325 = sizeof( struct V_24 ) ;
T_8 V_326 = sizeof( struct V_31 ) ;
T_8 V_327 = sizeof( struct V_51 ) ;
T_8 V_328 = sizeof( struct V_55 ) ;
T_8 V_329 = sizeof( struct V_241 ) ;
T_8 V_330 = sizeof( struct V_282 ) ;
V_36 = F_223 ( L_42 , V_325 , 0 ,
V_331 , NULL ) ;
if ( ! V_36 )
return - V_83 ;
V_40 = F_223 ( L_43 , V_326 , 0 ,
V_331 , NULL ) ;
if ( ! V_40 )
goto V_332;
V_53 = F_223 ( L_44 ,
V_327 , 0 ,
V_331 , NULL ) ;
if ( ! V_53 )
goto V_333;
V_63 = F_223 ( L_45 ,
V_328 , 0 ,
V_331 , NULL ) ;
if ( ! V_63 )
goto V_334;
V_243 = F_223 ( L_46 ,
V_329 , 0 ,
V_331 , NULL ) ;
if ( ! V_243 )
goto V_335;
V_284 = F_223 ( L_47 ,
V_330 , 0 ,
V_331 , NULL ) ;
if ( ! V_284 )
goto V_336;
return 0 ;
V_336:
F_224 ( V_243 ) ;
V_243 = NULL ;
V_335:
F_224 ( V_63 ) ;
V_63 = NULL ;
V_334:
F_224 ( V_53 ) ;
V_53 = NULL ;
V_333:
F_224 ( V_40 ) ;
V_40 = NULL ;
V_332:
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
F_224 ( V_243 ) ;
F_224 ( V_284 ) ;
}

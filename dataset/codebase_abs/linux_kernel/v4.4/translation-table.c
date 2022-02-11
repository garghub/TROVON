static int F_1 ( const struct V_1 * V_2 , const void * V_3 )
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
static void
F_14 ( struct V_24 * V_28 )
{
if ( F_15 ( & V_28 -> V_30 . V_23 ) )
F_16 ( V_28 , V_30 . V_34 ) ;
}
static void
F_17 ( struct V_31 * V_32 )
{
if ( F_15 ( & V_32 -> V_30 . V_23 ) ) {
F_18 ( V_32 ) ;
F_16 ( V_32 , V_30 . V_34 ) ;
}
}
int F_19 ( struct V_25 * V_26 ,
const T_2 * V_14 , unsigned short V_9 )
{
struct V_31 * V_32 ;
int V_35 ;
V_32 = F_13 ( V_26 , V_14 , V_9 ) ;
if ( ! V_32 )
return 0 ;
V_35 = F_20 ( & V_32 -> V_36 ) ;
F_17 ( V_32 ) ;
return V_35 ;
}
static void F_21 ( struct V_37 * V_34 )
{
struct V_38 * V_39 ;
V_39 = F_2 ( V_34 , struct V_38 , V_34 ) ;
F_22 ( V_39 -> V_40 ) ;
F_23 ( V_39 ) ;
}
static void F_24 ( struct V_25 * V_26 ,
unsigned short V_9 , int V_41 )
{
struct V_42 * V_43 ;
V_43 = F_25 ( V_26 , V_9 ) ;
if ( ! V_43 )
return;
F_26 ( V_41 , & V_43 -> V_12 . V_44 ) ;
F_27 ( V_43 ) ;
}
static void F_28 ( struct V_25 * V_26 ,
unsigned short V_9 )
{
F_24 ( V_26 , V_9 , 1 ) ;
}
static void F_29 ( struct V_25 * V_26 ,
unsigned short V_9 )
{
F_24 ( V_26 , V_9 , - 1 ) ;
}
static void F_30 ( struct V_45 * V_40 ,
unsigned short V_9 , int V_41 )
{
struct V_46 * V_43 ;
V_43 = F_31 ( V_40 , V_9 ) ;
if ( ! V_43 )
return;
if ( F_32 ( V_41 , & V_43 -> V_12 . V_44 ) == 0 ) {
F_33 ( & V_40 -> V_47 ) ;
F_34 ( & V_43 -> V_48 ) ;
F_35 ( & V_40 -> V_47 ) ;
F_36 ( V_43 ) ;
}
F_36 ( V_43 ) ;
}
static void F_37 ( struct V_45 * V_40 ,
unsigned short V_9 )
{
F_30 ( V_40 , V_9 , 1 ) ;
}
static void F_38 ( struct V_45 * V_40 ,
unsigned short V_9 )
{
F_30 ( V_40 , V_9 , - 1 ) ;
}
static void
F_39 ( struct V_38 * V_39 )
{
if ( ! F_15 ( & V_39 -> V_23 ) )
return;
F_40 ( & V_39 -> V_34 , F_21 ) ;
}
static void F_41 ( struct V_25 * V_26 ,
struct V_24 * V_28 ,
T_2 V_49 )
{
struct V_50 * V_51 , * V_52 , * V_53 ;
struct V_5 * V_30 = & V_28 -> V_30 ;
T_2 V_54 = V_30 -> V_54 | V_49 ;
bool V_55 = false ;
bool V_56 , V_57 ;
V_51 = F_42 ( sizeof( * V_51 ) , V_58 ) ;
if ( ! V_51 )
return;
V_51 -> V_59 . V_54 = V_54 ;
memset ( V_51 -> V_59 . V_60 , 0 ,
sizeof( V_51 -> V_59 . V_60 ) ) ;
F_7 ( V_51 -> V_59 . V_14 , V_30 -> V_14 ) ;
V_51 -> V_59 . V_9 = F_43 ( V_30 -> V_9 ) ;
V_56 = V_54 & V_61 ;
F_33 ( & V_26 -> V_12 . V_62 ) ;
F_44 (entry, safe, &bat_priv->tt.changes_list,
list) {
if ( ! F_3 ( V_52 -> V_59 . V_14 , V_30 -> V_14 ) )
continue;
V_57 = V_52 -> V_59 . V_54 & V_61 ;
if ( ! V_56 && V_57 )
goto V_63;
if ( V_56 && ! V_57 )
goto V_63;
if ( ! V_56 && ! V_57 )
V_52 -> V_59 . V_54 = V_54 ;
continue;
V_63:
F_45 ( & V_52 -> V_48 ) ;
F_23 ( V_52 ) ;
F_23 ( V_51 ) ;
V_55 = true ;
goto V_64;
}
F_46 ( & V_51 -> V_48 , & V_26 -> V_12 . V_65 ) ;
V_64:
F_35 ( & V_26 -> V_12 . V_62 ) ;
if ( V_55 )
F_47 ( & V_26 -> V_12 . V_66 ) ;
else
F_48 ( & V_26 -> V_12 . V_66 ) ;
}
static int F_49 ( int V_67 )
{
return V_67 * sizeof( struct V_68 ) ;
}
static T_3 F_50 ( T_3 V_69 )
{
return V_69 / F_49 ( 1 ) ;
}
static int F_51 ( struct V_25 * V_26 )
{
T_3 V_70 = 0 ;
T_3 V_71 = 0 ;
struct V_42 * V_43 ;
int V_72 ;
F_8 () ;
F_9 (vlan, &bat_priv->softif_vlan_list, list) {
V_70 ++ ;
V_71 += F_20 ( & V_43 -> V_12 . V_44 ) ;
}
F_11 () ;
V_72 = sizeof( struct V_73 ) ;
V_72 += sizeof( struct V_74 ) ;
V_72 += sizeof( struct V_75 ) ;
V_72 += V_70 * sizeof( struct V_76 ) ;
return V_72 + F_49 ( V_71 ) ;
}
static int F_52 ( struct V_25 * V_26 )
{
if ( V_26 -> V_12 . V_29 )
return 0 ;
V_26 -> V_12 . V_29 = F_53 ( 1024 ) ;
if ( ! V_26 -> V_12 . V_29 )
return - V_77 ;
F_54 ( V_26 -> V_12 . V_29 ,
& V_78 ) ;
return 0 ;
}
static void F_55 ( struct V_25 * V_26 ,
struct V_31 * V_79 ,
const char * V_80 )
{
F_56 ( V_81 , V_26 ,
L_1 ,
V_79 -> V_30 . V_14 ,
F_57 ( V_79 -> V_30 . V_9 ) , V_80 ) ;
F_58 ( V_26 -> V_12 . V_33 , F_1 ,
F_4 , & V_79 -> V_30 ) ;
F_17 ( V_79 ) ;
}
bool F_59 ( struct V_82 * V_83 , const T_2 * V_14 ,
unsigned short V_9 , int V_84 , T_1 V_85 )
{
struct V_25 * V_26 = F_60 ( V_83 ) ;
struct V_24 * V_86 ;
struct V_31 * V_79 = NULL ;
struct V_42 * V_43 ;
struct V_82 * V_87 = NULL ;
struct V_17 * V_18 ;
struct V_38 * V_39 ;
int V_88 , V_89 , V_90 ;
bool V_91 = false ;
bool V_92 = false ;
T_2 V_93 ;
T_1 V_94 ;
if ( V_84 != V_95 )
V_87 = F_61 ( & V_96 , V_84 ) ;
V_86 = F_12 ( V_26 , V_14 , V_9 ) ;
if ( ! F_62 ( V_14 ) )
V_79 = F_13 ( V_26 , V_14 , V_9 ) ;
if ( V_86 ) {
V_86 -> V_97 = V_98 ;
if ( V_86 -> V_30 . V_54 & V_99 ) {
F_56 ( V_81 , V_26 ,
L_2 ,
V_14 , F_57 ( V_9 ) ) ;
V_86 -> V_30 . V_54 &= ~ V_99 ;
goto V_100;
}
if ( V_86 -> V_30 . V_54 & V_101 ) {
F_56 ( V_81 , V_26 ,
L_3 ,
V_14 , F_57 ( V_9 ) ) ;
V_86 -> V_30 . V_54 &= ~ V_101 ;
V_92 = true ;
}
goto V_102;
}
V_89 = F_51 ( V_26 ) ;
V_89 += F_49 ( 1 ) ;
V_90 = F_20 ( & V_26 -> V_90 ) ;
if ( V_89 > V_90 ) {
F_63 ( V_103 , V_83 ,
L_4 ,
V_89 , V_90 , V_14 ) ;
goto V_104;
}
V_86 = F_42 ( sizeof( * V_86 ) , V_58 ) ;
if ( ! V_86 )
goto V_104;
V_43 = F_25 ( V_26 , V_9 ) ;
if ( F_64 ( ! V_43 , L_5 ,
V_14 , F_57 ( V_9 ) ) ) {
F_23 ( V_86 ) ;
V_86 = NULL ;
goto V_104;
}
F_56 ( V_81 , V_26 ,
L_6 ,
V_14 , F_57 ( V_9 ) ,
( T_2 ) F_20 ( & V_26 -> V_12 . V_105 ) ) ;
F_7 ( V_86 -> V_30 . V_14 , V_14 ) ;
V_86 -> V_30 . V_54 = V_106 ;
V_86 -> V_30 . V_9 = V_9 ;
if ( F_65 ( V_87 ) )
V_86 -> V_30 . V_54 |= V_107 ;
F_66 ( & V_86 -> V_30 . V_23 , 2 ) ;
V_86 -> V_97 = V_98 ;
V_86 -> V_30 . V_108 = V_86 -> V_97 ;
if ( F_3 ( V_14 , V_83 -> V_109 ) ||
F_62 ( V_14 ) )
V_86 -> V_30 . V_54 |= V_110 ;
V_88 = F_67 ( V_26 -> V_12 . V_29 , F_1 ,
F_4 , & V_86 -> V_30 ,
& V_86 -> V_30 . V_6 ) ;
if ( F_68 ( V_88 != 0 ) ) {
F_14 ( V_86 ) ;
F_27 ( V_43 ) ;
goto V_104;
}
V_100:
F_41 ( V_26 , V_86 , V_111 ) ;
V_102:
if ( V_79 && ! ( V_79 -> V_30 . V_54 & V_101 ) ) {
V_18 = & V_79 -> V_112 ;
F_8 () ;
F_9 (orig_entry, head, list) {
F_69 ( V_26 , V_79 -> V_30 . V_14 ,
V_79 -> V_30 . V_9 ,
V_39 -> V_40 ) ;
}
F_11 () ;
if ( V_92 ) {
F_55 ( V_26 , V_79 ,
L_7 ) ;
V_79 = NULL ;
} else {
V_79 -> V_30 . V_54 |= V_101 ;
V_79 -> V_113 = V_98 ;
}
}
V_93 = V_86 -> V_30 . V_54 & V_114 ;
if ( F_65 ( V_87 ) )
V_86 -> V_30 . V_54 |= V_107 ;
else
V_86 -> V_30 . V_54 &= ~ V_107 ;
V_94 = ( V_85 & V_26 -> V_115 ) ;
if ( V_26 -> V_115 &&
V_94 == V_26 -> V_116 )
V_86 -> V_30 . V_54 |= V_117 ;
else
V_86 -> V_30 . V_54 &= ~ V_117 ;
if ( V_93 ^ ( V_86 -> V_30 . V_54 & V_114 ) )
F_41 ( V_26 , V_86 , V_111 ) ;
V_91 = true ;
V_104:
if ( V_87 )
F_70 ( V_87 ) ;
if ( V_86 )
F_14 ( V_86 ) ;
if ( V_79 )
F_17 ( V_79 ) ;
return V_91 ;
}
static T_3
F_71 ( struct V_45 * V_40 ,
struct V_75 * * V_118 ,
struct V_68 * * V_119 ,
T_4 * V_69 )
{
T_3 V_70 = 0 ;
T_3 V_44 = 0 ;
T_3 V_120 ;
T_3 V_121 ;
struct V_76 * V_122 ;
struct V_46 * V_43 ;
T_2 * V_123 ;
F_8 () ;
F_9 (vlan, &orig_node->vlan_list, list) {
V_70 ++ ;
V_44 += F_20 ( & V_43 -> V_12 . V_44 ) ;
}
V_120 = sizeof( * * V_118 ) ;
V_120 += V_70 * sizeof( * V_122 ) ;
if ( * V_69 < 0 )
* V_69 = F_49 ( V_44 ) ;
V_121 = * V_69 ;
V_121 += V_120 ;
* V_118 = F_42 ( V_121 , V_58 ) ;
if ( ! * V_118 ) {
* V_69 = 0 ;
goto V_104;
}
( * V_118 ) -> V_54 = V_111 ;
( * V_118 ) -> V_124 = F_20 ( & V_40 -> V_125 ) ;
( * V_118 ) -> V_70 = F_43 ( V_70 ) ;
V_122 = (struct V_76 * ) ( * V_118 + 1 ) ;
F_9 (vlan, &orig_node->vlan_list, list) {
V_122 -> V_9 = F_43 ( V_43 -> V_9 ) ;
V_122 -> V_126 = F_72 ( V_43 -> V_12 . V_126 ) ;
V_122 ++ ;
}
V_123 = ( T_2 * ) * V_118 + V_120 ;
* V_119 = (struct V_68 * ) V_123 ;
V_104:
F_11 () ;
return V_121 ;
}
static T_3
F_73 ( struct V_25 * V_26 ,
struct V_75 * * V_118 ,
struct V_68 * * V_119 ,
T_4 * V_69 )
{
struct V_76 * V_122 ;
struct V_42 * V_43 ;
T_3 V_70 = 0 ;
T_3 V_44 = 0 ;
T_3 V_121 ;
T_2 * V_123 ;
int V_120 ;
F_8 () ;
F_9 (vlan, &bat_priv->softif_vlan_list, list) {
V_70 ++ ;
V_44 += F_20 ( & V_43 -> V_12 . V_44 ) ;
}
V_120 = sizeof( * * V_118 ) ;
V_120 += V_70 * sizeof( * V_122 ) ;
if ( * V_69 < 0 )
* V_69 = F_49 ( V_44 ) ;
V_121 = * V_69 ;
V_121 += V_120 ;
* V_118 = F_42 ( V_121 , V_58 ) ;
if ( ! * V_118 ) {
V_121 = 0 ;
goto V_104;
}
( * V_118 ) -> V_54 = V_111 ;
( * V_118 ) -> V_124 = F_20 ( & V_26 -> V_12 . V_105 ) ;
( * V_118 ) -> V_70 = F_43 ( V_70 ) ;
V_122 = (struct V_76 * ) ( * V_118 + 1 ) ;
F_9 (vlan, &bat_priv->softif_vlan_list, list) {
V_122 -> V_9 = F_43 ( V_43 -> V_9 ) ;
V_122 -> V_126 = F_72 ( V_43 -> V_12 . V_126 ) ;
V_122 ++ ;
}
V_123 = ( T_2 * ) * V_118 + V_120 ;
* V_119 = (struct V_68 * ) V_123 ;
V_104:
F_11 () ;
return V_121 ;
}
static void F_74 ( struct V_25 * V_26 )
{
struct V_50 * V_52 , * V_53 ;
struct V_75 * V_118 ;
struct V_68 * V_119 ;
int V_127 , V_128 = 0 ;
int V_129 = 0 ;
int V_130 = 0 ;
T_3 V_121 ;
V_129 = F_20 ( & V_26 -> V_12 . V_66 ) ;
V_127 = F_49 ( V_129 ) ;
if ( V_127 > V_26 -> V_83 -> V_131 )
V_127 = 0 ;
V_121 = F_73 ( V_26 , & V_118 ,
& V_119 , & V_127 ) ;
if ( ! V_121 )
return;
V_118 -> V_54 = V_132 ;
if ( V_127 == 0 )
goto V_133;
F_33 ( & V_26 -> V_12 . V_62 ) ;
F_66 ( & V_26 -> V_12 . V_66 , 0 ) ;
F_44 (entry, safe, &bat_priv->tt.changes_list,
list) {
if ( V_130 < V_129 ) {
memcpy ( V_119 + V_130 ,
& V_52 -> V_59 ,
sizeof( struct V_68 ) ) ;
V_130 ++ ;
}
F_45 ( & V_52 -> V_48 ) ;
F_23 ( V_52 ) ;
}
F_35 ( & V_26 -> V_12 . V_62 ) ;
F_33 ( & V_26 -> V_12 . V_134 ) ;
F_23 ( V_26 -> V_12 . V_135 ) ;
V_26 -> V_12 . V_136 = 0 ;
V_26 -> V_12 . V_135 = NULL ;
V_128 = F_49 ( V_130 ) ;
if ( V_130 > 0 ) {
V_26 -> V_12 . V_135 = F_75 ( V_127 , V_58 ) ;
if ( V_26 -> V_12 . V_135 ) {
memcpy ( V_26 -> V_12 . V_135 ,
V_119 , V_128 ) ;
V_26 -> V_12 . V_136 = V_127 ;
}
}
F_35 ( & V_26 -> V_12 . V_134 ) ;
V_133:
F_76 ( V_26 , V_137 , 1 , V_118 ,
V_121 ) ;
F_23 ( V_118 ) ;
}
int F_77 ( struct V_138 * V_139 , void * V_140 )
{
struct V_82 * V_141 = (struct V_82 * ) V_139 -> V_142 ;
struct V_25 * V_26 = F_60 ( V_141 ) ;
struct V_16 * V_13 = V_26 -> V_12 . V_29 ;
struct V_5 * V_27 ;
struct V_24 * V_86 ;
struct V_143 * V_144 ;
struct V_42 * V_43 ;
struct V_17 * V_18 ;
unsigned short V_9 ;
T_1 V_145 ;
int V_146 ;
int V_147 ;
unsigned long V_148 ;
bool V_149 ;
T_3 V_150 = V_110 ;
V_144 = F_78 ( V_139 ) ;
if ( ! V_144 )
goto V_104;
F_79 ( V_139 ,
L_8 ,
V_141 -> V_151 , ( T_2 ) F_20 ( & V_26 -> V_12 . V_105 ) ) ;
F_79 ( V_139 , L_9 , L_10 , L_11 ,
L_12 , L_13 , L_14 ) ;
for ( V_145 = 0 ; V_145 < V_13 -> V_11 ; V_145 ++ ) {
V_18 = & V_13 -> V_22 [ V_145 ] ;
F_8 () ;
F_9 (tt_common_entry,
head, hash_entry) {
V_86 = F_2 ( V_27 ,
struct V_24 ,
V_30 ) ;
V_9 = V_27 -> V_9 ;
V_148 = V_98 - V_86 -> V_97 ;
V_147 = F_80 ( V_148 ) ;
V_146 = V_147 / 1000 ;
V_147 = V_147 % 1000 ;
V_149 = V_27 -> V_54 & V_150 ;
V_43 = F_25 ( V_26 , V_9 ) ;
if ( ! V_43 ) {
F_79 ( V_139 , L_15 ,
F_57 ( V_9 ) ) ;
continue;
}
F_79 ( V_139 ,
L_16 ,
V_27 -> V_14 ,
F_57 ( V_27 -> V_9 ) ,
( ( V_27 -> V_54 &
V_101 ) ? 'R' : '.' ) ,
V_149 ? 'P' : '.' ,
( ( V_27 -> V_54 &
V_106 ) ? 'N' : '.' ) ,
( ( V_27 -> V_54 &
V_99 ) ? 'X' : '.' ) ,
( ( V_27 -> V_54 &
V_107 ) ? 'W' : '.' ) ,
( ( V_27 -> V_54 &
V_117 ) ? 'I' : '.' ) ,
V_149 ? 0 : V_146 ,
V_149 ? 0 : V_147 ,
V_43 -> V_12 . V_126 ) ;
F_27 ( V_43 ) ;
}
F_11 () ;
}
V_104:
if ( V_144 )
F_81 ( V_144 ) ;
return 0 ;
}
static void
F_82 ( struct V_25 * V_26 ,
struct V_24 * V_28 ,
T_3 V_54 , const char * V_80 )
{
F_41 ( V_26 , V_28 , V_54 ) ;
V_28 -> V_30 . V_54 |= V_99 ;
F_56 ( V_81 , V_26 ,
L_17 ,
V_28 -> V_30 . V_14 ,
F_57 ( V_28 -> V_30 . V_9 ) , V_80 ) ;
}
T_3 F_83 ( struct V_25 * V_26 , const T_2 * V_14 ,
unsigned short V_9 , const char * V_80 ,
bool V_152 )
{
struct V_24 * V_28 ;
T_3 V_54 , V_153 = V_111 ;
struct V_42 * V_43 ;
void * V_154 ;
V_28 = F_12 ( V_26 , V_14 , V_9 ) ;
if ( ! V_28 )
goto V_104;
V_153 = V_28 -> V_30 . V_54 ;
V_54 = V_61 ;
if ( V_152 ) {
V_54 |= V_101 ;
V_28 -> V_30 . V_54 |= V_101 ;
}
if ( ! ( V_28 -> V_30 . V_54 & V_106 ) ) {
F_82 ( V_26 , V_28 , V_54 ,
V_80 ) ;
goto V_104;
}
F_41 ( V_26 , V_28 , V_61 ) ;
V_154 = F_58 ( V_26 -> V_12 . V_29 ,
F_1 ,
F_4 ,
& V_28 -> V_30 ) ;
if ( ! V_154 )
goto V_104;
F_14 ( V_28 ) ;
V_43 = F_25 ( V_26 , V_9 ) ;
if ( ! V_43 )
goto V_104;
F_27 ( V_43 ) ;
F_27 ( V_43 ) ;
V_104:
if ( V_28 )
F_14 ( V_28 ) ;
return V_153 ;
}
static void F_84 ( struct V_25 * V_26 ,
struct V_17 * V_18 ,
int V_155 )
{
struct V_24 * V_28 ;
struct V_5 * V_27 ;
struct V_1 * V_156 ;
F_85 (tt_common_entry, node_tmp, head,
hash_entry) {
V_28 = F_2 ( V_27 ,
struct V_24 ,
V_30 ) ;
if ( V_28 -> V_30 . V_54 & V_110 )
continue;
if ( V_28 -> V_30 . V_54 & V_99 )
continue;
if ( ! F_86 ( V_28 -> V_97 , V_155 ) )
continue;
F_82 ( V_26 , V_28 ,
V_61 , L_18 ) ;
}
}
static void F_87 ( struct V_25 * V_26 ,
int V_155 )
{
struct V_16 * V_13 = V_26 -> V_12 . V_29 ;
struct V_17 * V_18 ;
T_5 * V_157 ;
T_1 V_145 ;
for ( V_145 = 0 ; V_145 < V_13 -> V_11 ; V_145 ++ ) {
V_18 = & V_13 -> V_22 [ V_145 ] ;
V_157 = & V_13 -> V_158 [ V_145 ] ;
F_33 ( V_157 ) ;
F_84 ( V_26 , V_18 , V_155 ) ;
F_35 ( V_157 ) ;
}
}
static void F_88 ( struct V_25 * V_26 )
{
struct V_16 * V_13 ;
T_5 * V_157 ;
struct V_5 * V_27 ;
struct V_24 * V_86 ;
struct V_42 * V_43 ;
struct V_1 * V_156 ;
struct V_17 * V_18 ;
T_1 V_145 ;
if ( ! V_26 -> V_12 . V_29 )
return;
V_13 = V_26 -> V_12 . V_29 ;
for ( V_145 = 0 ; V_145 < V_13 -> V_11 ; V_145 ++ ) {
V_18 = & V_13 -> V_22 [ V_145 ] ;
V_157 = & V_13 -> V_158 [ V_145 ] ;
F_33 ( V_157 ) ;
F_85 (tt_common_entry, node_tmp,
head, hash_entry) {
F_89 ( & V_27 -> V_6 ) ;
V_86 = F_2 ( V_27 ,
struct V_24 ,
V_30 ) ;
V_43 = F_25 ( V_26 ,
V_27 -> V_9 ) ;
if ( V_43 ) {
F_27 ( V_43 ) ;
F_27 ( V_43 ) ;
}
F_14 ( V_86 ) ;
}
F_35 ( V_157 ) ;
}
F_90 ( V_13 ) ;
V_26 -> V_12 . V_29 = NULL ;
}
static int F_91 ( struct V_25 * V_26 )
{
if ( V_26 -> V_12 . V_33 )
return 0 ;
V_26 -> V_12 . V_33 = F_53 ( 1024 ) ;
if ( ! V_26 -> V_12 . V_33 )
return - V_77 ;
F_54 ( V_26 -> V_12 . V_33 ,
& V_159 ) ;
return 0 ;
}
static void F_92 ( struct V_25 * V_26 )
{
struct V_50 * V_52 , * V_53 ;
F_33 ( & V_26 -> V_12 . V_62 ) ;
F_44 (entry, safe, &bat_priv->tt.changes_list,
list) {
F_45 ( & V_52 -> V_48 ) ;
F_23 ( V_52 ) ;
}
F_66 ( & V_26 -> V_12 . V_66 , 0 ) ;
F_35 ( & V_26 -> V_12 . V_62 ) ;
}
static struct V_38 *
F_93 ( const struct V_31 * V_52 ,
const struct V_45 * V_40 )
{
struct V_38 * V_160 , * V_39 = NULL ;
const struct V_17 * V_18 ;
F_8 () ;
V_18 = & V_52 -> V_112 ;
F_9 (tmp_orig_entry, head, list) {
if ( V_160 -> V_40 != V_40 )
continue;
if ( ! F_10 ( & V_160 -> V_23 ) )
continue;
V_39 = V_160 ;
break;
}
F_11 () ;
return V_39 ;
}
static bool
F_94 ( const struct V_31 * V_52 ,
const struct V_45 * V_40 )
{
struct V_38 * V_39 ;
bool V_161 = false ;
V_39 = F_93 ( V_52 , V_40 ) ;
if ( V_39 ) {
V_161 = true ;
F_39 ( V_39 ) ;
}
return V_161 ;
}
static void
F_95 ( struct V_31 * V_79 ,
struct V_45 * V_40 , int V_124 )
{
struct V_38 * V_39 ;
V_39 = F_93 ( V_79 , V_40 ) ;
if ( V_39 ) {
V_39 -> V_124 = V_124 ;
goto V_104;
}
V_39 = F_75 ( sizeof( * V_39 ) , V_58 ) ;
if ( ! V_39 )
goto V_104;
F_96 ( & V_39 -> V_48 ) ;
F_48 ( & V_40 -> V_23 ) ;
F_37 ( V_40 , V_79 -> V_30 . V_9 ) ;
V_39 -> V_40 = V_40 ;
V_39 -> V_124 = V_124 ;
F_66 ( & V_39 -> V_23 , 2 ) ;
F_33 ( & V_79 -> V_157 ) ;
F_97 ( & V_39 -> V_48 ,
& V_79 -> V_112 ) ;
F_35 ( & V_79 -> V_157 ) ;
F_48 ( & V_79 -> V_36 ) ;
V_104:
if ( V_39 )
F_39 ( V_39 ) ;
}
static bool F_98 ( struct V_25 * V_26 ,
struct V_45 * V_40 ,
const unsigned char * V_162 ,
unsigned short V_9 , T_3 V_54 , T_2 V_124 )
{
struct V_31 * V_32 ;
struct V_24 * V_28 ;
bool V_91 = false ;
int V_88 ;
struct V_5 * V_30 ;
T_3 V_163 ;
if ( F_99 ( V_26 , V_40 -> V_164 , V_9 ) )
return true ;
V_32 = F_13 ( V_26 , V_162 , V_9 ) ;
V_28 = F_12 ( V_26 , V_162 , V_9 ) ;
if ( ( V_54 & V_165 ) && V_28 &&
! ( V_28 -> V_30 . V_54 & V_106 ) )
goto V_104;
if ( ! V_32 ) {
V_32 = F_75 ( sizeof( * V_32 ) , V_58 ) ;
if ( ! V_32 )
goto V_104;
V_30 = & V_32 -> V_30 ;
F_7 ( V_30 -> V_14 , V_162 ) ;
V_30 -> V_9 = V_9 ;
V_30 -> V_54 = V_54 ;
V_32 -> V_113 = 0 ;
if ( V_54 & V_101 )
V_32 -> V_113 = V_98 ;
F_66 ( & V_30 -> V_23 , 2 ) ;
V_30 -> V_108 = V_98 ;
F_100 ( & V_32 -> V_112 ) ;
F_66 ( & V_32 -> V_36 , 0 ) ;
F_101 ( & V_32 -> V_157 ) ;
V_88 = F_67 ( V_26 -> V_12 . V_33 ,
F_1 ,
F_4 , V_30 ,
& V_30 -> V_6 ) ;
if ( F_68 ( V_88 != 0 ) ) {
F_17 ( V_32 ) ;
goto V_166;
}
} else {
V_30 = & V_32 -> V_30 ;
if ( V_54 & V_165 ) {
if ( ! ( V_30 -> V_54 & V_165 ) )
goto V_104;
if ( F_94 ( V_32 ,
V_40 ) )
goto V_166;
F_18 ( V_32 ) ;
goto V_167;
}
if ( V_30 -> V_54 & V_165 ) {
F_18 ( V_32 ) ;
V_30 -> V_54 &= ~ V_165 ;
}
V_32 -> V_30 . V_54 |= V_54 ;
if ( V_30 -> V_54 & V_101 ) {
F_18 ( V_32 ) ;
V_30 -> V_54 &= ~ V_101 ;
V_32 -> V_113 = 0 ;
}
}
V_167:
F_95 ( V_32 , V_40 , V_124 ) ;
F_56 ( V_81 , V_26 ,
L_19 ,
V_30 -> V_14 , F_57 ( V_30 -> V_9 ) ,
V_40 -> V_164 ) ;
V_91 = true ;
V_166:
if ( F_62 ( V_162 ) )
goto V_104;
V_163 = F_83 ( V_26 , V_162 , V_9 ,
L_20 ,
V_54 & V_101 ) ;
V_32 -> V_30 . V_54 |= V_163 & V_107 ;
if ( ! ( V_54 & V_101 ) )
V_32 -> V_30 . V_54 &= ~ V_101 ;
V_104:
if ( V_32 )
F_17 ( V_32 ) ;
if ( V_28 )
F_14 ( V_28 ) ;
return V_91 ;
}
static struct V_38 *
F_102 ( struct V_25 * V_26 ,
struct V_31 * V_32 )
{
struct V_168 * V_169 , * V_170 = NULL ;
struct V_171 * V_172 = V_26 -> V_173 ;
struct V_17 * V_18 ;
struct V_38 * V_39 , * V_174 = NULL ;
V_18 = & V_32 -> V_112 ;
F_9 (orig_entry, head, list) {
V_169 = F_103 ( V_39 -> V_40 ,
V_175 ) ;
if ( ! V_169 )
continue;
if ( V_170 &&
V_172 -> V_176 ( V_169 , V_175 ,
V_170 , V_175 ) <= 0 ) {
F_104 ( V_169 ) ;
continue;
}
if ( V_170 )
F_104 ( V_170 ) ;
V_174 = V_39 ;
V_170 = V_169 ;
}
if ( V_170 )
F_104 ( V_170 ) ;
return V_174 ;
}
static void
F_105 ( struct V_25 * V_26 ,
struct V_31 * V_32 ,
struct V_138 * V_139 )
{
struct V_38 * V_39 , * V_174 ;
struct V_5 * V_27 ;
struct V_46 * V_43 ;
struct V_17 * V_18 ;
T_2 V_125 ;
T_3 V_54 ;
V_27 = & V_32 -> V_30 ;
V_54 = V_27 -> V_54 ;
V_174 = F_102 ( V_26 , V_32 ) ;
if ( V_174 ) {
V_43 = F_106 ( V_174 -> V_40 ,
V_27 -> V_9 ) ;
if ( ! V_43 ) {
F_79 ( V_139 ,
L_21 ,
F_57 ( V_27 -> V_9 ) ,
V_174 -> V_40 -> V_164 ) ;
goto V_177;
}
V_125 = F_20 ( & V_174 -> V_40 -> V_125 ) ;
F_79 ( V_139 ,
L_22 ,
'*' , V_32 -> V_30 . V_14 ,
F_57 ( V_32 -> V_30 . V_9 ) ,
V_174 -> V_124 , V_174 -> V_40 -> V_164 ,
V_125 , V_43 -> V_12 . V_126 ,
( ( V_54 & V_101 ) ? 'R' : '.' ) ,
( ( V_54 & V_107 ) ? 'W' : '.' ) ,
( ( V_54 & V_117 ) ? 'I' : '.' ) ,
( ( V_54 & V_165 ) ? 'T' : '.' ) ) ;
F_36 ( V_43 ) ;
}
V_177:
V_18 = & V_32 -> V_112 ;
F_9 (orig_entry, head, list) {
if ( V_174 == V_39 )
continue;
V_43 = F_106 ( V_39 -> V_40 ,
V_27 -> V_9 ) ;
if ( ! V_43 ) {
F_79 ( V_139 ,
L_23 ,
F_57 ( V_27 -> V_9 ) ,
V_39 -> V_40 -> V_164 ) ;
continue;
}
V_125 = F_20 ( & V_39 -> V_40 -> V_125 ) ;
F_79 ( V_139 ,
L_24 ,
'+' , V_32 -> V_30 . V_14 ,
F_57 ( V_32 -> V_30 . V_9 ) ,
V_39 -> V_124 , V_39 -> V_40 -> V_164 ,
V_125 , V_43 -> V_12 . V_126 ,
( ( V_54 & V_101 ) ? 'R' : '.' ) ,
( ( V_54 & V_107 ) ? 'W' : '.' ) ,
( ( V_54 & V_117 ) ? 'I' : '.' ) ,
( ( V_54 & V_165 ) ? 'T' : '.' ) ) ;
F_36 ( V_43 ) ;
}
}
int F_107 ( struct V_138 * V_139 , void * V_140 )
{
struct V_82 * V_141 = (struct V_82 * ) V_139 -> V_142 ;
struct V_25 * V_26 = F_60 ( V_141 ) ;
struct V_16 * V_13 = V_26 -> V_12 . V_33 ;
struct V_5 * V_27 ;
struct V_31 * V_79 ;
struct V_143 * V_144 ;
struct V_17 * V_18 ;
T_1 V_145 ;
V_144 = F_78 ( V_139 ) ;
if ( ! V_144 )
goto V_104;
F_79 ( V_139 ,
L_25 ,
V_141 -> V_151 ) ;
F_79 ( V_139 , L_26 ,
L_10 , L_11 , L_27 , L_28 , L_29 ,
L_14 , L_12 ) ;
for ( V_145 = 0 ; V_145 < V_13 -> V_11 ; V_145 ++ ) {
V_18 = & V_13 -> V_22 [ V_145 ] ;
F_8 () ;
F_9 (tt_common_entry,
head, hash_entry) {
V_79 = F_2 ( V_27 ,
struct V_31 ,
V_30 ) ;
F_105 ( V_26 , V_79 , V_139 ) ;
}
F_11 () ;
}
V_104:
if ( V_144 )
F_81 ( V_144 ) ;
return 0 ;
}
static void
F_108 ( struct V_31 * V_32 ,
struct V_38 * V_39 )
{
F_109 ( & V_32 -> V_157 ) ;
F_38 ( V_39 -> V_40 ,
V_32 -> V_30 . V_9 ) ;
F_47 ( & V_32 -> V_36 ) ;
F_89 ( & V_39 -> V_48 ) ;
F_39 ( V_39 ) ;
}
static void
F_18 ( struct V_31 * V_32 )
{
struct V_17 * V_18 ;
struct V_1 * V_53 ;
struct V_38 * V_39 ;
F_33 ( & V_32 -> V_157 ) ;
V_18 = & V_32 -> V_112 ;
F_85 (orig_entry, safe, head, list)
F_108 ( V_32 , V_39 ) ;
F_35 ( & V_32 -> V_157 ) ;
}
static void
F_110 ( struct V_25 * V_26 ,
struct V_31 * V_32 ,
struct V_45 * V_40 ,
const char * V_80 )
{
struct V_17 * V_18 ;
struct V_1 * V_53 ;
struct V_38 * V_39 ;
unsigned short V_9 ;
F_33 ( & V_32 -> V_157 ) ;
V_18 = & V_32 -> V_112 ;
F_85 (orig_entry, safe, head, list) {
if ( V_39 -> V_40 == V_40 ) {
V_9 = V_32 -> V_30 . V_9 ;
F_56 ( V_81 , V_26 ,
L_30 ,
V_40 -> V_164 ,
V_32 -> V_30 . V_14 ,
F_57 ( V_9 ) , V_80 ) ;
F_108 ( V_32 ,
V_39 ) ;
}
}
F_35 ( & V_32 -> V_157 ) ;
}
static void
F_111 ( struct V_25 * V_26 ,
struct V_31 * V_32 ,
struct V_45 * V_40 ,
const char * V_80 )
{
bool V_178 = true ;
struct V_17 * V_18 ;
struct V_38 * V_39 ;
F_8 () ;
V_18 = & V_32 -> V_112 ;
F_9 (orig_entry, head, list) {
if ( V_39 -> V_40 != V_40 ) {
V_178 = false ;
break;
}
}
F_11 () ;
if ( V_178 ) {
V_32 -> V_30 . V_54 |= V_101 ;
V_32 -> V_113 = V_98 ;
} else
F_110 ( V_26 , V_32 ,
V_40 , V_80 ) ;
}
static void F_112 ( struct V_25 * V_26 ,
struct V_45 * V_40 ,
const unsigned char * V_14 , unsigned short V_9 ,
const char * V_80 , bool V_152 )
{
struct V_31 * V_32 ;
struct V_24 * V_179 = NULL ;
V_32 = F_13 ( V_26 , V_14 , V_9 ) ;
if ( ! V_32 )
goto V_104;
if ( ! V_152 ) {
F_110 ( V_26 , V_32 ,
V_40 , V_80 ) ;
if ( F_113 ( & V_32 -> V_112 ) )
F_55 ( V_26 , V_32 ,
V_80 ) ;
goto V_104;
}
V_179 = F_12 ( V_26 ,
V_32 -> V_30 . V_14 ,
V_9 ) ;
if ( V_179 ) {
F_18 ( V_32 ) ;
F_55 ( V_26 , V_32 , V_80 ) ;
} else
F_111 ( V_26 , V_32 ,
V_40 , V_80 ) ;
V_104:
if ( V_32 )
F_17 ( V_32 ) ;
if ( V_179 )
F_14 ( V_179 ) ;
}
void F_114 ( struct V_25 * V_26 ,
struct V_45 * V_40 ,
T_4 V_180 ,
const char * V_80 )
{
struct V_31 * V_79 ;
struct V_5 * V_27 ;
T_1 V_145 ;
struct V_16 * V_13 = V_26 -> V_12 . V_33 ;
struct V_1 * V_53 ;
struct V_17 * V_18 ;
T_5 * V_157 ;
unsigned short V_9 ;
if ( ! V_13 )
return;
for ( V_145 = 0 ; V_145 < V_13 -> V_11 ; V_145 ++ ) {
V_18 = & V_13 -> V_22 [ V_145 ] ;
V_157 = & V_13 -> V_158 [ V_145 ] ;
F_33 ( V_157 ) ;
F_85 (tt_common_entry, safe,
head, hash_entry) {
if ( V_180 >= 0 && V_27 -> V_9 != V_180 )
continue;
V_79 = F_2 ( V_27 ,
struct V_31 ,
V_30 ) ;
F_110 ( V_26 , V_79 ,
V_40 , V_80 ) ;
if ( F_113 ( & V_79 -> V_112 ) ) {
V_9 = V_79 -> V_30 . V_9 ;
F_56 ( V_81 , V_26 ,
L_1 ,
V_79 -> V_30 . V_14 ,
F_57 ( V_9 ) , V_80 ) ;
F_89 ( & V_27 -> V_6 ) ;
F_17 ( V_79 ) ;
}
}
F_35 ( V_157 ) ;
}
F_115 ( V_181 , & V_40 -> V_182 ) ;
}
static bool F_116 ( struct V_31 * V_79 ,
char * * V_183 )
{
bool V_184 = false ;
unsigned long V_185 = V_186 ;
unsigned long V_187 = V_188 ;
if ( ( V_79 -> V_30 . V_54 & V_101 ) &&
F_86 ( V_79 -> V_113 , V_185 ) ) {
V_184 = true ;
* V_183 = L_31 ;
}
if ( ( V_79 -> V_30 . V_54 & V_165 ) &&
F_86 ( V_79 -> V_30 . V_108 , V_187 ) ) {
V_184 = true ;
* V_183 = L_32 ;
}
return V_184 ;
}
static void F_117 ( struct V_25 * V_26 )
{
struct V_16 * V_13 = V_26 -> V_12 . V_33 ;
struct V_17 * V_18 ;
struct V_1 * V_156 ;
T_5 * V_157 ;
T_1 V_145 ;
char * V_183 = NULL ;
struct V_5 * V_189 ;
struct V_31 * V_79 ;
for ( V_145 = 0 ; V_145 < V_13 -> V_11 ; V_145 ++ ) {
V_18 = & V_13 -> V_22 [ V_145 ] ;
V_157 = & V_13 -> V_158 [ V_145 ] ;
F_33 ( V_157 ) ;
F_85 (tt_common, node_tmp, head,
hash_entry) {
V_79 = F_2 ( V_189 ,
struct V_31 ,
V_30 ) ;
if ( ! F_116 ( V_79 , & V_183 ) )
continue;
F_56 ( V_81 , V_26 ,
L_1 ,
V_79 -> V_30 . V_14 ,
F_57 ( V_79 -> V_30 . V_9 ) ,
V_183 ) ;
F_89 ( & V_189 -> V_6 ) ;
F_17 ( V_79 ) ;
}
F_35 ( V_157 ) ;
}
}
static void F_118 ( struct V_25 * V_26 )
{
struct V_16 * V_13 ;
T_5 * V_157 ;
struct V_5 * V_27 ;
struct V_31 * V_79 ;
struct V_1 * V_156 ;
struct V_17 * V_18 ;
T_1 V_145 ;
if ( ! V_26 -> V_12 . V_33 )
return;
V_13 = V_26 -> V_12 . V_33 ;
for ( V_145 = 0 ; V_145 < V_13 -> V_11 ; V_145 ++ ) {
V_18 = & V_13 -> V_22 [ V_145 ] ;
V_157 = & V_13 -> V_158 [ V_145 ] ;
F_33 ( V_157 ) ;
F_85 (tt_common_entry, node_tmp,
head, hash_entry) {
F_89 ( & V_27 -> V_6 ) ;
V_79 = F_2 ( V_27 ,
struct V_31 ,
V_30 ) ;
F_17 ( V_79 ) ;
}
F_35 ( V_157 ) ;
}
F_90 ( V_13 ) ;
V_26 -> V_12 . V_33 = NULL ;
}
static bool
F_119 ( struct V_24 * V_28 ,
struct V_31 * V_32 )
{
bool V_91 = false ;
if ( V_28 -> V_30 . V_54 & V_107 &&
V_32 -> V_30 . V_54 & V_107 )
V_91 = true ;
if ( V_28 -> V_30 . V_54 & V_117 &&
V_32 -> V_30 . V_54 & V_117 )
V_91 = true ;
return V_91 ;
}
struct V_45 * F_120 ( struct V_25 * V_26 ,
const T_2 * V_190 ,
const T_2 * V_14 ,
unsigned short V_9 )
{
struct V_24 * V_28 = NULL ;
struct V_31 * V_32 = NULL ;
struct V_45 * V_40 = NULL ;
struct V_38 * V_174 ;
if ( V_190 && F_121 ( V_26 , V_9 ) ) {
V_28 = F_12 ( V_26 , V_190 , V_9 ) ;
if ( ! V_28 ||
( V_28 -> V_30 . V_54 & V_99 ) )
goto V_104;
}
V_32 = F_13 ( V_26 , V_14 , V_9 ) ;
if ( ! V_32 )
goto V_104;
if ( V_28 &&
F_119 ( V_28 , V_32 ) )
goto V_104;
F_8 () ;
V_174 = F_102 ( V_26 , V_32 ) ;
if ( V_174 )
V_40 = V_174 -> V_40 ;
if ( V_40 && ! F_10 ( & V_40 -> V_23 ) )
V_40 = NULL ;
F_11 () ;
V_104:
if ( V_32 )
F_17 ( V_32 ) ;
if ( V_28 )
F_14 ( V_28 ) ;
return V_40 ;
}
static T_1 F_122 ( struct V_25 * V_26 ,
struct V_45 * V_40 ,
unsigned short V_9 )
{
struct V_16 * V_13 = V_26 -> V_12 . V_33 ;
struct V_5 * V_189 ;
struct V_31 * V_79 ;
struct V_17 * V_18 ;
T_1 V_145 , V_191 , V_126 = 0 ;
T_2 V_54 ;
T_6 V_192 ;
for ( V_145 = 0 ; V_145 < V_13 -> V_11 ; V_145 ++ ) {
V_18 = & V_13 -> V_22 [ V_145 ] ;
F_8 () ;
F_9 (tt_common, head, hash_entry) {
V_79 = F_2 ( V_189 ,
struct V_31 ,
V_30 ) ;
if ( V_189 -> V_9 != V_9 )
continue;
if ( V_189 -> V_54 & V_101 )
continue;
if ( V_189 -> V_54 & V_165 )
continue;
if ( ! F_94 ( V_79 ,
V_40 ) )
continue;
V_192 = F_43 ( V_189 -> V_9 ) ;
V_191 = F_123 ( 0 , & V_192 , sizeof( V_192 ) ) ;
V_54 = V_189 -> V_54 & V_193 ;
V_191 = F_123 ( V_191 , & V_54 , sizeof( V_54 ) ) ;
V_126 ^= F_123 ( V_191 , V_189 -> V_14 , V_15 ) ;
}
F_11 () ;
}
return V_126 ;
}
static T_1 F_124 ( struct V_25 * V_26 ,
unsigned short V_9 )
{
struct V_16 * V_13 = V_26 -> V_12 . V_29 ;
struct V_5 * V_189 ;
struct V_17 * V_18 ;
T_1 V_145 , V_191 , V_126 = 0 ;
T_2 V_54 ;
T_6 V_192 ;
for ( V_145 = 0 ; V_145 < V_13 -> V_11 ; V_145 ++ ) {
V_18 = & V_13 -> V_22 [ V_145 ] ;
F_8 () ;
F_9 (tt_common, head, hash_entry) {
if ( V_189 -> V_9 != V_9 )
continue;
if ( V_189 -> V_54 & V_106 )
continue;
V_192 = F_43 ( V_189 -> V_9 ) ;
V_191 = F_123 ( 0 , & V_192 , sizeof( V_192 ) ) ;
V_54 = V_189 -> V_54 & V_193 ;
V_191 = F_123 ( V_191 , & V_54 , sizeof( V_54 ) ) ;
V_126 ^= F_123 ( V_191 , V_189 -> V_14 , V_15 ) ;
}
F_11 () ;
}
return V_126 ;
}
static void F_125 ( struct V_25 * V_26 )
{
struct V_194 * V_2 ;
struct V_1 * V_53 ;
F_33 ( & V_26 -> V_12 . V_195 ) ;
F_85 (node, safe, &bat_priv->tt.req_list, list) {
F_126 ( & V_2 -> V_48 ) ;
F_23 ( V_2 ) ;
}
F_35 ( & V_26 -> V_12 . V_195 ) ;
}
static void F_127 ( struct V_25 * V_26 ,
struct V_45 * V_40 ,
const void * V_196 ,
T_3 V_197 )
{
F_33 ( & V_40 -> V_198 ) ;
if ( V_197 > 0 ) {
F_23 ( V_40 -> V_196 ) ;
V_40 -> V_197 = 0 ;
V_40 -> V_196 = F_42 ( V_197 , V_58 ) ;
if ( V_40 -> V_196 ) {
memcpy ( V_40 -> V_196 , V_196 , V_197 ) ;
V_40 -> V_197 = V_197 ;
}
}
F_35 ( & V_40 -> V_198 ) ;
}
static void F_128 ( struct V_25 * V_26 )
{
struct V_194 * V_2 ;
struct V_1 * V_53 ;
F_33 ( & V_26 -> V_12 . V_195 ) ;
F_85 (node, safe, &bat_priv->tt.req_list, list) {
if ( F_86 ( V_2 -> V_199 ,
V_200 ) ) {
F_126 ( & V_2 -> V_48 ) ;
F_23 ( V_2 ) ;
}
}
F_35 ( & V_26 -> V_12 . V_195 ) ;
}
static struct V_194 *
F_129 ( struct V_25 * V_26 ,
struct V_45 * V_40 )
{
struct V_194 * V_201 , * V_202 = NULL ;
F_33 ( & V_26 -> V_12 . V_195 ) ;
F_130 (tt_req_node_tmp, &bat_priv->tt.req_list, list) {
if ( F_3 ( V_201 , V_40 ) &&
! F_86 ( V_201 -> V_199 ,
V_200 ) )
goto V_64;
}
V_202 = F_42 ( sizeof( * V_202 ) , V_58 ) ;
if ( ! V_202 )
goto V_64;
F_7 ( V_202 -> V_14 , V_40 -> V_164 ) ;
V_202 -> V_199 = V_98 ;
F_131 ( & V_202 -> V_48 , & V_26 -> V_12 . V_203 ) ;
V_64:
F_35 ( & V_26 -> V_12 . V_195 ) ;
return V_202 ;
}
static int F_132 ( const void * V_204 , const void * V_205 )
{
const struct V_5 * V_27 = V_204 ;
if ( V_27 -> V_54 & V_106 )
return 0 ;
return 1 ;
}
static int F_133 ( const void * V_204 ,
const void * V_205 )
{
const struct V_5 * V_27 = V_204 ;
const struct V_31 * V_32 ;
const struct V_45 * V_40 = V_205 ;
if ( V_27 -> V_54 & V_101 ||
V_27 -> V_54 & V_165 )
return 0 ;
V_32 = F_2 ( V_27 ,
struct V_31 ,
V_30 ) ;
return F_94 ( V_32 , V_40 ) ;
}
static void F_134 ( struct V_25 * V_26 ,
struct V_16 * V_13 ,
void * V_206 , T_3 V_69 ,
int (* F_135)( const void * , const void * ) ,
void * V_207 )
{
struct V_5 * V_27 ;
struct V_68 * V_119 ;
struct V_17 * V_18 ;
T_3 V_208 , V_209 = 0 ;
T_1 V_145 ;
V_208 = F_50 ( V_69 ) ;
V_119 = (struct V_68 * ) V_206 ;
F_8 () ;
for ( V_145 = 0 ; V_145 < V_13 -> V_11 ; V_145 ++ ) {
V_18 = & V_13 -> V_22 [ V_145 ] ;
F_9 (tt_common_entry,
head, hash_entry) {
if ( V_208 == V_209 )
break;
if ( ( F_135 ) && ( ! F_135 ( V_27 , V_207 ) ) )
continue;
F_7 ( V_119 -> V_14 , V_27 -> V_14 ) ;
V_119 -> V_54 = V_27 -> V_54 ;
V_119 -> V_9 = F_43 ( V_27 -> V_9 ) ;
memset ( V_119 -> V_60 , 0 ,
sizeof( V_119 -> V_60 ) ) ;
V_209 ++ ;
V_119 ++ ;
}
}
F_11 () ;
}
static bool F_136 ( struct V_45 * V_40 ,
struct V_76 * V_122 ,
T_3 V_70 )
{
struct V_76 * V_210 ;
struct V_46 * V_43 ;
T_1 V_126 ;
int V_145 ;
for ( V_145 = 0 ; V_145 < V_70 ; V_145 ++ ) {
V_210 = V_122 + V_145 ;
if ( F_99 ( V_40 -> V_26 ,
V_40 -> V_164 ,
F_137 ( V_210 -> V_9 ) ) )
continue;
V_43 = F_106 ( V_40 ,
F_137 ( V_210 -> V_9 ) ) ;
if ( ! V_43 )
return false ;
V_126 = V_43 -> V_12 . V_126 ;
F_36 ( V_43 ) ;
if ( V_126 != F_138 ( V_210 -> V_126 ) )
return false ;
}
return true ;
}
static void F_139 ( struct V_25 * V_26 )
{
struct V_42 * V_43 ;
F_8 () ;
F_9 (vlan, &bat_priv->softif_vlan_list, list) {
V_43 -> V_12 . V_126 = F_124 ( V_26 , V_43 -> V_9 ) ;
}
F_11 () ;
}
static void F_140 ( struct V_25 * V_26 ,
struct V_45 * V_40 )
{
struct V_46 * V_43 ;
T_1 V_126 ;
F_8 () ;
F_9 (vlan, &orig_node->vlan_list, list) {
if ( F_99 ( V_26 , V_40 -> V_164 ,
V_43 -> V_9 ) )
continue;
V_126 = F_122 ( V_26 , V_40 , V_43 -> V_9 ) ;
V_43 -> V_12 . V_126 = V_126 ;
}
F_11 () ;
}
static int F_141 ( struct V_25 * V_26 ,
struct V_45 * V_211 ,
T_2 V_124 ,
struct V_76 * V_122 ,
T_3 V_70 , bool V_212 )
{
struct V_75 * V_213 = NULL ;
struct V_194 * V_202 = NULL ;
struct V_76 * V_214 ;
struct V_143 * V_144 ;
bool V_91 = false ;
int V_145 , V_11 ;
V_144 = F_142 ( V_26 ) ;
if ( ! V_144 )
goto V_104;
V_202 = F_129 ( V_26 , V_211 ) ;
if ( ! V_202 )
goto V_104;
V_11 = sizeof( * V_213 ) + sizeof( * V_214 ) * V_70 ;
V_213 = F_75 ( V_11 , V_58 ) ;
if ( ! V_213 )
goto V_104;
V_213 -> V_54 = V_215 ;
V_213 -> V_124 = V_124 ;
V_213 -> V_70 = F_43 ( V_70 ) ;
V_214 = (struct V_76 * ) ( V_213 + 1 ) ;
for ( V_145 = 0 ; V_145 < V_70 ; V_145 ++ ) {
V_214 -> V_9 = V_122 -> V_9 ;
V_214 -> V_126 = V_122 -> V_126 ;
V_214 ++ ;
V_122 ++ ;
}
if ( V_212 )
V_213 -> V_54 |= V_216 ;
F_56 ( V_81 , V_26 , L_33 ,
V_211 -> V_164 , V_212 ? 'F' : '.' ) ;
F_143 ( V_26 , V_217 ) ;
F_144 ( V_26 , V_144 -> V_141 -> V_109 ,
V_211 -> V_164 , V_137 , 1 ,
V_213 , V_11 ) ;
V_91 = true ;
V_104:
if ( V_144 )
F_81 ( V_144 ) ;
if ( V_91 && V_202 ) {
F_33 ( & V_26 -> V_12 . V_195 ) ;
F_126 ( & V_202 -> V_48 ) ;
F_35 ( & V_26 -> V_12 . V_195 ) ;
F_23 ( V_202 ) ;
}
F_23 ( V_213 ) ;
return V_91 ;
}
static bool F_145 ( struct V_25 * V_26 ,
struct V_75 * V_118 ,
T_2 * V_218 , T_2 * V_219 )
{
struct V_45 * V_220 ;
struct V_45 * V_221 = NULL ;
struct V_68 * V_119 ;
struct V_75 * V_213 = NULL ;
struct V_76 * V_122 ;
bool V_91 = false , V_212 ;
T_2 V_222 , V_223 ;
T_3 V_121 ;
T_4 V_69 ;
F_56 ( V_81 , V_26 ,
L_34 ,
V_218 , V_118 -> V_124 , V_219 ,
( ( V_118 -> V_54 & V_216 ) ? 'F' : '.' ) ) ;
V_220 = F_146 ( V_26 , V_219 ) ;
if ( ! V_220 )
goto V_104;
V_221 = F_146 ( V_26 , V_218 ) ;
if ( ! V_221 )
goto V_104;
V_222 = ( T_2 ) F_20 ( & V_220 -> V_125 ) ;
V_223 = V_118 -> V_124 ;
V_122 = (struct V_76 * ) ( V_118 + 1 ) ;
if ( V_222 != V_223 ||
! F_136 ( V_220 , V_122 ,
F_137 ( V_118 -> V_70 ) ) )
goto V_104;
if ( V_118 -> V_54 & V_216 ||
! V_220 -> V_196 )
V_212 = true ;
else
V_212 = false ;
if ( ! V_212 ) {
F_33 ( & V_220 -> V_198 ) ;
V_69 = V_220 -> V_197 ;
V_121 = F_71 ( V_220 ,
& V_213 ,
& V_119 ,
& V_69 ) ;
if ( ! V_69 )
goto V_64;
memcpy ( V_119 , V_220 -> V_196 ,
V_220 -> V_197 ) ;
F_35 ( & V_220 -> V_198 ) ;
} else {
V_69 = - 1 ;
V_121 = F_71 ( V_220 ,
& V_213 ,
& V_119 ,
& V_69 ) ;
if ( ! V_69 )
goto V_104;
F_134 ( V_26 , V_26 -> V_12 . V_33 ,
V_119 , V_69 ,
F_133 ,
V_220 ) ;
}
V_69 = sizeof( struct V_73 ) + V_121 ;
if ( V_69 > F_20 ( & V_26 -> V_90 ) ) {
F_63 ( V_103 , V_26 -> V_83 ,
L_35 ,
V_221 -> V_164 ) ;
goto V_104;
}
V_213 -> V_54 = V_224 ;
V_213 -> V_124 = V_223 ;
if ( V_212 )
V_213 -> V_54 |= V_216 ;
F_56 ( V_81 , V_26 ,
L_36 ,
V_221 -> V_164 , V_220 -> V_164 ,
V_212 ? 'F' : '.' , V_223 ) ;
F_143 ( V_26 , V_225 ) ;
F_144 ( V_26 , V_220 -> V_164 ,
V_218 , V_137 , 1 , V_213 ,
V_121 ) ;
V_91 = true ;
goto V_104;
V_64:
F_35 ( & V_220 -> V_198 ) ;
V_104:
if ( V_221 )
F_147 ( V_221 ) ;
if ( V_220 )
F_147 ( V_220 ) ;
F_23 ( V_213 ) ;
return V_91 ;
}
static bool F_148 ( struct V_25 * V_26 ,
struct V_75 * V_118 ,
T_2 * V_218 )
{
struct V_75 * V_213 = NULL ;
struct V_143 * V_144 = NULL ;
struct V_68 * V_119 ;
struct V_45 * V_40 ;
T_2 V_226 , V_223 ;
T_3 V_121 ;
bool V_212 ;
T_4 V_69 ;
F_56 ( V_81 , V_26 ,
L_37 ,
V_218 , V_118 -> V_124 ,
( ( V_118 -> V_54 & V_216 ) ? 'F' : '.' ) ) ;
F_33 ( & V_26 -> V_12 . V_227 ) ;
V_226 = ( T_2 ) F_20 ( & V_26 -> V_12 . V_105 ) ;
V_223 = V_118 -> V_124 ;
V_40 = F_146 ( V_26 , V_218 ) ;
if ( ! V_40 )
goto V_104;
V_144 = F_142 ( V_26 ) ;
if ( ! V_144 )
goto V_104;
if ( V_118 -> V_54 & V_216 || V_226 != V_223 ||
! V_26 -> V_12 . V_135 )
V_212 = true ;
else
V_212 = false ;
if ( ! V_212 ) {
F_33 ( & V_26 -> V_12 . V_134 ) ;
V_69 = V_26 -> V_12 . V_136 ;
V_121 = F_73 ( V_26 ,
& V_213 ,
& V_119 ,
& V_69 ) ;
if ( ! V_69 )
goto V_64;
memcpy ( V_119 , V_26 -> V_12 . V_135 ,
V_26 -> V_12 . V_136 ) ;
F_35 ( & V_26 -> V_12 . V_134 ) ;
} else {
V_223 = ( T_2 ) F_20 ( & V_26 -> V_12 . V_105 ) ;
V_69 = - 1 ;
V_121 = F_73 ( V_26 ,
& V_213 ,
& V_119 ,
& V_69 ) ;
if ( ! V_69 )
goto V_104;
F_134 ( V_26 , V_26 -> V_12 . V_29 ,
V_119 , V_69 ,
F_132 , NULL ) ;
}
V_213 -> V_54 = V_224 ;
V_213 -> V_124 = V_223 ;
if ( V_212 )
V_213 -> V_54 |= V_216 ;
F_56 ( V_81 , V_26 ,
L_38 ,
V_40 -> V_164 , V_212 ? 'F' : '.' , V_223 ) ;
F_143 ( V_26 , V_225 ) ;
F_144 ( V_26 , V_144 -> V_141 -> V_109 ,
V_218 , V_137 , 1 , V_213 ,
V_121 ) ;
goto V_104;
V_64:
F_35 ( & V_26 -> V_12 . V_134 ) ;
V_104:
F_35 ( & V_26 -> V_12 . V_227 ) ;
if ( V_40 )
F_147 ( V_40 ) ;
if ( V_144 )
F_81 ( V_144 ) ;
F_23 ( V_213 ) ;
return true ;
}
static bool F_149 ( struct V_25 * V_26 ,
struct V_75 * V_118 ,
T_2 * V_218 , T_2 * V_219 )
{
if ( F_150 ( V_26 , V_219 ) )
return F_148 ( V_26 , V_118 , V_218 ) ;
return F_145 ( V_26 , V_118 , V_218 ,
V_219 ) ;
}
static void F_151 ( struct V_25 * V_26 ,
struct V_45 * V_40 ,
struct V_68 * V_119 ,
T_3 V_228 , T_2 V_124 )
{
int V_145 ;
int V_229 ;
for ( V_145 = 0 ; V_145 < V_228 ; V_145 ++ ) {
if ( ( V_119 + V_145 ) -> V_54 & V_61 ) {
V_229 = ( V_119 + V_145 ) -> V_54 & V_101 ;
F_112 ( V_26 , V_40 ,
( V_119 + V_145 ) -> V_14 ,
F_137 ( ( V_119 + V_145 ) -> V_9 ) ,
L_39 ,
V_229 ) ;
} else {
if ( ! F_98 ( V_26 , V_40 ,
( V_119 + V_145 ) -> V_14 ,
F_137 ( ( V_119 + V_145 ) -> V_9 ) ,
( V_119 + V_145 ) -> V_54 , V_124 ) )
return;
}
}
F_152 ( V_181 , & V_40 -> V_182 ) ;
}
static void F_153 ( struct V_25 * V_26 ,
struct V_68 * V_119 ,
T_2 V_124 , T_2 * V_230 ,
T_3 V_44 )
{
struct V_45 * V_40 ;
V_40 = F_146 ( V_26 , V_230 ) ;
if ( ! V_40 )
goto V_104;
F_114 ( V_26 , V_40 , - 1 ,
L_40 ) ;
F_151 ( V_26 , V_40 , V_119 , V_44 ,
V_124 ) ;
F_33 ( & V_40 -> V_198 ) ;
F_23 ( V_40 -> V_196 ) ;
V_40 -> V_197 = 0 ;
V_40 -> V_196 = NULL ;
F_35 ( & V_40 -> V_198 ) ;
F_66 ( & V_40 -> V_125 , V_124 ) ;
V_104:
if ( V_40 )
F_147 ( V_40 ) ;
}
static void F_154 ( struct V_25 * V_26 ,
struct V_45 * V_40 ,
T_3 V_228 , T_2 V_124 ,
struct V_68 * V_119 )
{
F_151 ( V_26 , V_40 , V_119 ,
V_228 , V_124 ) ;
F_127 ( V_26 , V_40 , V_119 ,
F_49 ( V_228 ) ) ;
F_66 ( & V_40 -> V_125 , V_124 ) ;
}
bool F_155 ( struct V_25 * V_26 , const T_2 * V_14 ,
unsigned short V_9 )
{
struct V_24 * V_28 ;
bool V_91 = false ;
V_28 = F_12 ( V_26 , V_14 , V_9 ) ;
if ( ! V_28 )
goto V_104;
if ( ( V_28 -> V_30 . V_54 & V_99 ) ||
( V_28 -> V_30 . V_54 & V_101 ) )
goto V_104;
V_91 = true ;
V_104:
if ( V_28 )
F_14 ( V_28 ) ;
return V_91 ;
}
static void F_156 ( struct V_25 * V_26 ,
struct V_75 * V_118 ,
T_2 * V_230 , T_3 V_44 )
{
struct V_194 * V_2 ;
struct V_1 * V_53 ;
struct V_45 * V_40 = NULL ;
struct V_68 * V_119 ;
T_2 * V_231 = ( T_2 * ) V_118 ;
T_3 V_120 ;
F_56 ( V_81 , V_26 ,
L_41 ,
V_230 , V_118 -> V_124 , V_44 ,
( ( V_118 -> V_54 & V_216 ) ? 'F' : '.' ) ) ;
V_40 = F_146 ( V_26 , V_230 ) ;
if ( ! V_40 )
goto V_104;
F_33 ( & V_40 -> V_232 ) ;
V_120 = sizeof( struct V_76 ) ;
V_120 *= F_137 ( V_118 -> V_70 ) ;
V_120 += sizeof( * V_118 ) ;
V_231 += V_120 ;
V_119 = (struct V_68 * ) V_231 ;
if ( V_118 -> V_54 & V_216 ) {
F_153 ( V_26 , V_119 , V_118 -> V_124 ,
V_230 , V_44 ) ;
} else {
F_154 ( V_26 , V_40 , V_44 ,
V_118 -> V_124 , V_119 ) ;
}
F_140 ( V_26 , V_40 ) ;
F_35 ( & V_40 -> V_232 ) ;
F_33 ( & V_26 -> V_12 . V_195 ) ;
F_85 (node, safe, &bat_priv->tt.req_list, list) {
if ( ! F_3 ( V_2 -> V_14 , V_230 ) )
continue;
F_126 ( & V_2 -> V_48 ) ;
F_23 ( V_2 ) ;
}
F_35 ( & V_26 -> V_12 . V_195 ) ;
V_104:
if ( V_40 )
F_147 ( V_40 ) ;
}
static void F_157 ( struct V_25 * V_26 )
{
struct V_233 * V_2 , * V_53 ;
F_33 ( & V_26 -> V_12 . V_234 ) ;
F_44 (node, safe, &bat_priv->tt.roam_list, list) {
F_45 ( & V_2 -> V_48 ) ;
F_23 ( V_2 ) ;
}
F_35 ( & V_26 -> V_12 . V_234 ) ;
}
static void F_158 ( struct V_25 * V_26 )
{
struct V_233 * V_2 , * V_53 ;
F_33 ( & V_26 -> V_12 . V_234 ) ;
F_44 (node, safe, &bat_priv->tt.roam_list, list) {
if ( ! F_86 ( V_2 -> V_235 ,
V_236 ) )
continue;
F_45 ( & V_2 -> V_48 ) ;
F_23 ( V_2 ) ;
}
F_35 ( & V_26 -> V_12 . V_234 ) ;
}
static bool F_159 ( struct V_25 * V_26 , T_2 * V_237 )
{
struct V_233 * V_238 ;
bool V_91 = false ;
F_33 ( & V_26 -> V_12 . V_234 ) ;
F_160 (tt_roam_node, &bat_priv->tt.roam_list, list) {
if ( ! F_3 ( V_238 -> V_14 , V_237 ) )
continue;
if ( F_86 ( V_238 -> V_235 ,
V_236 ) )
continue;
if ( ! F_161 ( & V_238 -> V_239 ) )
goto V_64;
V_91 = true ;
break;
}
if ( ! V_91 ) {
V_238 = F_42 ( sizeof( * V_238 ) , V_58 ) ;
if ( ! V_238 )
goto V_64;
V_238 -> V_235 = V_98 ;
F_66 ( & V_238 -> V_239 ,
V_240 - 1 ) ;
F_7 ( V_238 -> V_14 , V_237 ) ;
F_162 ( & V_238 -> V_48 , & V_26 -> V_12 . V_241 ) ;
V_91 = true ;
}
V_64:
F_35 ( & V_26 -> V_12 . V_234 ) ;
return V_91 ;
}
static void F_69 ( struct V_25 * V_26 , T_2 * V_237 ,
unsigned short V_9 ,
struct V_45 * V_40 )
{
struct V_143 * V_144 ;
struct V_242 V_243 ;
V_144 = F_142 ( V_26 ) ;
if ( ! V_144 )
goto V_104;
if ( ! F_159 ( V_26 , V_237 ) )
goto V_104;
F_56 ( V_81 , V_26 ,
L_42 ,
V_40 -> V_164 , V_237 , F_57 ( V_9 ) ) ;
F_143 ( V_26 , V_244 ) ;
memcpy ( V_243 . V_237 , V_237 , sizeof( V_243 . V_237 ) ) ;
V_243 . V_9 = F_43 ( V_9 ) ;
F_144 ( V_26 , V_144 -> V_141 -> V_109 ,
V_40 -> V_164 , V_245 , 1 ,
& V_243 , sizeof( V_243 ) ) ;
V_104:
if ( V_144 )
F_81 ( V_144 ) ;
}
static void F_163 ( struct V_246 * V_247 )
{
struct V_248 * V_248 ;
struct V_249 * V_250 ;
struct V_25 * V_26 ;
V_248 = F_2 ( V_247 , struct V_248 , V_247 ) ;
V_250 = F_2 ( V_248 , struct V_249 , V_247 ) ;
V_26 = F_2 ( V_250 , struct V_25 , V_12 ) ;
F_87 ( V_26 , V_251 ) ;
F_117 ( V_26 ) ;
F_128 ( V_26 ) ;
F_158 ( V_26 ) ;
F_164 ( V_252 , & V_26 -> V_12 . V_247 ,
F_165 ( V_253 ) ) ;
}
void F_166 ( struct V_25 * V_26 )
{
F_167 ( V_26 , V_137 , 1 ) ;
F_168 ( V_26 , V_137 , 1 ) ;
F_169 ( & V_26 -> V_12 . V_247 ) ;
F_88 ( V_26 ) ;
F_118 ( V_26 ) ;
F_125 ( V_26 ) ;
F_92 ( V_26 ) ;
F_157 ( V_26 ) ;
F_23 ( V_26 -> V_12 . V_135 ) ;
}
static void F_170 ( struct V_25 * V_26 , T_3 V_54 ,
bool V_254 , bool V_35 )
{
struct V_16 * V_13 = V_26 -> V_12 . V_29 ;
struct V_5 * V_27 ;
T_3 V_255 = 0 ;
struct V_17 * V_18 ;
T_1 V_145 ;
if ( ! V_13 )
return;
for ( V_145 = 0 ; V_145 < V_13 -> V_11 ; V_145 ++ ) {
V_18 = & V_13 -> V_22 [ V_145 ] ;
F_8 () ;
F_9 (tt_common_entry,
head, hash_entry) {
if ( V_254 ) {
if ( ( V_27 -> V_54 & V_54 ) == V_54 )
continue;
V_27 -> V_54 |= V_54 ;
} else {
if ( ! ( V_27 -> V_54 & V_54 ) )
continue;
V_27 -> V_54 &= ~ V_54 ;
}
V_255 ++ ;
if ( ! V_35 )
continue;
F_28 ( V_26 ,
V_27 -> V_9 ) ;
}
F_11 () ;
}
}
static void F_171 ( struct V_25 * V_26 )
{
struct V_16 * V_13 = V_26 -> V_12 . V_29 ;
struct V_5 * V_189 ;
struct V_24 * V_86 ;
struct V_42 * V_43 ;
struct V_1 * V_156 ;
struct V_17 * V_18 ;
T_5 * V_157 ;
T_1 V_145 ;
if ( ! V_13 )
return;
for ( V_145 = 0 ; V_145 < V_13 -> V_11 ; V_145 ++ ) {
V_18 = & V_13 -> V_22 [ V_145 ] ;
V_157 = & V_13 -> V_158 [ V_145 ] ;
F_33 ( V_157 ) ;
F_85 (tt_common, node_tmp, head,
hash_entry) {
if ( ! ( V_189 -> V_54 & V_99 ) )
continue;
F_56 ( V_81 , V_26 ,
L_43 ,
V_189 -> V_14 ,
F_57 ( V_189 -> V_9 ) ) ;
F_29 ( V_26 , V_189 -> V_9 ) ;
F_89 ( & V_189 -> V_6 ) ;
V_86 = F_2 ( V_189 ,
struct V_24 ,
V_30 ) ;
V_43 = F_25 ( V_26 , V_189 -> V_9 ) ;
if ( V_43 ) {
F_27 ( V_43 ) ;
F_27 ( V_43 ) ;
}
F_14 ( V_86 ) ;
}
F_35 ( V_157 ) ;
}
}
static void F_172 ( struct V_25 * V_26 )
{
F_109 ( & V_26 -> V_12 . V_227 ) ;
F_173 ( V_26 ) ;
if ( F_20 ( & V_26 -> V_12 . V_66 ) < 1 ) {
if ( ! F_161 ( & V_26 -> V_12 . V_256 ) )
F_74 ( V_26 ) ;
return;
}
F_170 ( V_26 , V_106 , false , true ) ;
F_171 ( V_26 ) ;
F_139 ( V_26 ) ;
F_48 ( & V_26 -> V_12 . V_105 ) ;
F_56 ( V_81 , V_26 ,
L_44 ,
( T_2 ) F_20 ( & V_26 -> V_12 . V_105 ) ) ;
F_66 ( & V_26 -> V_12 . V_256 , V_257 ) ;
F_74 ( V_26 ) ;
}
void F_174 ( struct V_25 * V_26 )
{
F_33 ( & V_26 -> V_12 . V_227 ) ;
F_172 ( V_26 ) ;
F_35 ( & V_26 -> V_12 . V_227 ) ;
}
bool F_175 ( struct V_25 * V_26 , T_2 * V_190 , T_2 * V_258 ,
unsigned short V_9 )
{
struct V_24 * V_28 = NULL ;
struct V_31 * V_32 = NULL ;
struct V_42 * V_43 ;
bool V_91 = false ;
V_43 = F_25 ( V_26 , V_9 ) ;
if ( ! V_43 || ! F_20 ( & V_43 -> V_259 ) )
goto V_104;
V_28 = F_12 ( V_26 , V_258 , V_9 ) ;
if ( ! V_28 )
goto V_104;
V_32 = F_13 ( V_26 , V_190 , V_9 ) ;
if ( ! V_32 )
goto V_104;
if ( ! F_119 ( V_28 , V_32 ) )
goto V_104;
V_91 = true ;
V_104:
if ( V_43 )
F_27 ( V_43 ) ;
if ( V_32 )
F_17 ( V_32 ) ;
if ( V_28 )
F_14 ( V_28 ) ;
return V_91 ;
}
static void F_176 ( struct V_25 * V_26 ,
struct V_45 * V_40 ,
const void * V_196 , T_3 V_260 ,
struct V_68 * V_119 ,
T_3 V_228 , T_2 V_124 )
{
T_2 V_222 = ( T_2 ) F_20 ( & V_40 -> V_125 ) ;
struct V_76 * V_122 ;
bool V_212 = true ;
bool V_261 ;
V_122 = (struct V_76 * ) V_196 ;
V_261 = F_177 ( V_181 ,
& V_40 -> V_182 ) ;
if ( ( ! V_261 && V_124 == 1 ) || V_124 - V_222 == 1 ) {
if ( ! V_228 ) {
V_212 = false ;
goto V_262;
}
F_33 ( & V_40 -> V_232 ) ;
F_154 ( V_26 , V_40 , V_228 ,
V_124 , V_119 ) ;
F_140 ( V_26 , V_40 ) ;
F_35 ( & V_40 -> V_232 ) ;
if ( ! F_136 ( V_40 , V_122 ,
V_260 ) )
goto V_262;
} else {
if ( ! V_261 || V_124 != V_222 ||
! F_136 ( V_40 , V_122 ,
V_260 ) ) {
V_262:
F_56 ( V_81 , V_26 ,
L_45 ,
V_40 -> V_164 , V_124 , V_222 ,
V_228 ) ;
F_141 ( V_26 , V_40 , V_124 ,
V_122 , V_260 ,
V_212 ) ;
return;
}
}
}
bool F_178 ( struct V_25 * V_26 ,
T_2 * V_14 , unsigned short V_9 )
{
struct V_31 * V_32 ;
bool V_91 = false ;
V_32 = F_13 ( V_26 , V_14 , V_9 ) ;
if ( ! V_32 )
goto V_104;
V_91 = V_32 -> V_30 . V_54 & V_101 ;
F_17 ( V_32 ) ;
V_104:
return V_91 ;
}
bool F_179 ( struct V_25 * V_26 ,
T_2 * V_14 , unsigned short V_9 )
{
struct V_24 * V_28 ;
bool V_91 = false ;
V_28 = F_12 ( V_26 , V_14 , V_9 ) ;
if ( ! V_28 )
goto V_104;
V_91 = V_28 -> V_30 . V_54 & V_101 ;
F_14 ( V_28 ) ;
V_104:
return V_91 ;
}
bool F_180 ( struct V_25 * V_26 ,
struct V_45 * V_40 ,
const unsigned char * V_14 ,
unsigned short V_9 )
{
bool V_91 = false ;
if ( ! F_98 ( V_26 , V_40 , V_14 , V_9 ,
V_165 ,
F_20 ( & V_40 -> V_125 ) ) )
goto V_104;
F_56 ( V_81 , V_26 ,
L_46 ,
V_14 , F_57 ( V_9 ) , V_40 -> V_164 ) ;
V_91 = true ;
V_104:
return V_91 ;
}
void F_181 ( struct V_82 * V_83 )
{
struct V_25 * V_26 = F_60 ( V_83 ) ;
int V_90 = F_20 ( & V_26 -> V_90 ) ;
int V_89 , V_155 = V_251 / 2 ;
bool V_263 = false ;
F_33 ( & V_26 -> V_12 . V_227 ) ;
while ( true ) {
V_89 = F_51 ( V_26 ) ;
if ( V_90 >= V_89 )
break;
F_87 ( V_26 , V_155 ) ;
F_171 ( V_26 ) ;
V_155 /= 2 ;
V_263 = true ;
F_63 ( V_103 , V_83 ,
L_47 ,
V_90 ) ;
}
if ( V_263 )
F_172 ( V_26 ) ;
F_35 ( & V_26 -> V_12 . V_227 ) ;
}
static void F_182 ( struct V_25 * V_26 ,
struct V_45 * V_164 ,
T_2 V_54 , void * V_264 ,
T_3 V_265 )
{
struct V_76 * V_122 ;
struct V_68 * V_119 ;
struct V_75 * V_118 ;
T_3 V_44 , V_70 ;
if ( V_265 < sizeof( * V_118 ) )
return;
V_118 = (struct V_75 * ) V_264 ;
V_265 -= sizeof( * V_118 ) ;
V_70 = F_137 ( V_118 -> V_70 ) ;
if ( V_265 < sizeof( * V_122 ) * V_70 )
return;
V_122 = (struct V_76 * ) ( V_118 + 1 ) ;
V_119 = (struct V_68 * ) ( V_122 + V_70 ) ;
V_265 -= sizeof( * V_122 ) * V_70 ;
V_44 = F_50 ( V_265 ) ;
F_176 ( V_26 , V_164 , V_122 , V_70 , V_119 ,
V_44 , V_118 -> V_124 ) ;
}
static int F_183 ( struct V_25 * V_26 ,
T_2 * V_190 , T_2 * V_258 ,
void * V_264 ,
T_3 V_265 )
{
struct V_75 * V_118 ;
T_3 V_266 , V_209 ;
char V_267 ;
bool V_91 ;
if ( V_265 < sizeof( * V_118 ) )
return V_268 ;
V_118 = (struct V_75 * ) V_264 ;
V_265 -= sizeof( * V_118 ) ;
V_266 = sizeof( struct V_76 ) ;
V_266 *= F_137 ( V_118 -> V_70 ) ;
if ( V_265 < V_266 )
return V_268 ;
V_265 -= V_266 ;
V_209 = F_50 ( V_265 ) ;
switch ( V_118 -> V_54 & V_269 ) {
case V_215 :
F_143 ( V_26 , V_270 ) ;
V_91 = F_149 ( V_26 , V_118 , V_190 , V_258 ) ;
if ( ! V_91 ) {
if ( V_118 -> V_54 & V_216 )
V_267 = 'F' ;
else
V_267 = '.' ;
F_56 ( V_81 , V_26 ,
L_48 ,
V_258 , V_267 ) ;
return V_271 ;
}
break;
case V_224 :
F_143 ( V_26 , V_272 ) ;
if ( F_150 ( V_26 , V_258 ) ) {
F_156 ( V_26 , V_118 ,
V_190 , V_209 ) ;
return V_268 ;
}
if ( V_118 -> V_54 & V_216 )
V_267 = 'F' ;
else
V_267 = '.' ;
F_56 ( V_81 , V_26 ,
L_49 , V_258 , V_267 ) ;
return V_271 ;
}
return V_268 ;
}
static int F_184 ( struct V_25 * V_26 ,
T_2 * V_190 , T_2 * V_258 ,
void * V_264 ,
T_3 V_265 )
{
struct V_242 * V_273 ;
struct V_45 * V_40 = NULL ;
if ( ! F_150 ( V_26 , V_258 ) )
return V_271 ;
if ( V_265 < sizeof( * V_273 ) )
goto V_104;
V_40 = F_146 ( V_26 , V_190 ) ;
if ( ! V_40 )
goto V_104;
F_143 ( V_26 , V_274 ) ;
V_273 = (struct V_242 * ) V_264 ;
F_56 ( V_81 , V_26 ,
L_50 ,
V_190 , V_273 -> V_237 ) ;
F_98 ( V_26 , V_40 , V_273 -> V_237 ,
F_137 ( V_273 -> V_9 ) , V_101 ,
F_20 ( & V_40 -> V_125 ) + 1 ) ;
V_104:
if ( V_40 )
F_147 ( V_40 ) ;
return V_268 ;
}
int F_185 ( struct V_25 * V_26 )
{
int V_91 ;
F_186 ( ! ( V_193 & V_114 ) ) ;
V_91 = F_52 ( V_26 ) ;
if ( V_91 < 0 )
return V_91 ;
V_91 = F_91 ( V_26 ) ;
if ( V_91 < 0 )
return V_91 ;
F_187 ( V_26 , F_182 ,
F_183 ,
V_137 , 1 , V_111 ) ;
F_187 ( V_26 , NULL ,
F_184 ,
V_245 , 1 , V_111 ) ;
F_188 ( & V_26 -> V_12 . V_247 , F_163 ) ;
F_164 ( V_252 , & V_26 -> V_12 . V_247 ,
F_165 ( V_253 ) ) ;
return 1 ;
}
bool F_189 ( struct V_25 * V_26 ,
const T_2 * V_14 , unsigned short V_9 )
{
struct V_31 * V_12 ;
bool V_91 ;
V_12 = F_13 ( V_26 , V_14 , V_9 ) ;
if ( ! V_12 )
return false ;
V_91 = V_12 -> V_30 . V_54 & V_117 ;
F_17 ( V_12 ) ;
return V_91 ;
}

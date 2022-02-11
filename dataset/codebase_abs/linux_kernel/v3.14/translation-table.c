static int F_1 ( const struct V_1 * V_2 , const void * V_3 )
{
const void * V_4 = F_2 ( V_2 , struct V_5 ,
V_6 ) ;
return F_3 ( V_4 , V_3 ) ;
}
static inline T_1 F_4 ( const void * V_7 , T_1 V_8 )
{
struct V_5 * V_9 ;
T_1 V_10 = 0 ;
V_9 = (struct V_5 * ) V_7 ;
V_10 = F_5 ( V_10 , & V_9 -> V_11 , V_12 ) ;
V_10 = F_5 ( V_10 , & V_9 -> V_13 , sizeof( V_9 -> V_13 ) ) ;
V_10 += ( V_10 << 3 ) ;
V_10 ^= ( V_10 >> 11 ) ;
V_10 += ( V_10 << 15 ) ;
return V_10 % V_8 ;
}
static struct V_5 *
F_6 ( struct V_14 * V_10 , const T_2 * V_11 ,
unsigned short V_13 )
{
struct V_15 * V_16 ;
struct V_5 V_17 , * V_9 , * V_18 = NULL ;
T_1 V_19 ;
if ( ! V_10 )
return NULL ;
memcpy ( V_17 . V_11 , V_11 , V_12 ) ;
V_17 . V_13 = V_13 ;
V_19 = F_4 ( & V_17 , V_10 -> V_8 ) ;
V_16 = & V_10 -> V_20 [ V_19 ] ;
F_7 () ;
F_8 (tt, head, hash_entry) {
if ( ! F_3 ( V_9 , V_11 ) )
continue;
if ( V_9 -> V_13 != V_13 )
continue;
if ( ! F_9 ( & V_9 -> V_21 ) )
continue;
V_18 = V_9 ;
break;
}
F_10 () ;
return V_18 ;
}
static struct V_22 *
F_11 ( struct V_23 * V_24 , const T_2 * V_11 ,
unsigned short V_13 )
{
struct V_5 * V_25 ;
struct V_22 * V_26 = NULL ;
V_25 = F_6 ( V_24 -> V_9 . V_27 , V_11 ,
V_13 ) ;
if ( V_25 )
V_26 = F_2 ( V_25 ,
struct V_22 ,
V_28 ) ;
return V_26 ;
}
static struct V_29 *
F_12 ( struct V_23 * V_24 , const T_2 * V_11 ,
unsigned short V_13 )
{
struct V_5 * V_25 ;
struct V_29 * V_30 = NULL ;
V_25 = F_6 ( V_24 -> V_9 . V_31 , V_11 ,
V_13 ) ;
if ( V_25 )
V_30 = F_2 ( V_25 ,
struct V_29 ,
V_28 ) ;
return V_30 ;
}
static void
F_13 ( struct V_22 * V_26 )
{
if ( F_14 ( & V_26 -> V_28 . V_21 ) )
F_15 ( V_26 , V_28 . V_32 ) ;
}
static void
F_16 ( struct V_29 * V_30 )
{
if ( F_14 ( & V_30 -> V_28 . V_21 ) ) {
F_17 ( V_30 ) ;
F_15 ( V_30 , V_28 . V_32 ) ;
}
}
static void F_18 ( struct V_33 * V_32 )
{
struct V_34 * V_35 ;
V_35 = F_2 ( V_32 , struct V_34 , V_32 ) ;
F_19 ( V_35 -> V_36 ) ;
F_20 ( V_35 ) ;
}
static void F_21 ( struct V_23 * V_24 ,
unsigned short V_13 , int V_37 )
{
struct V_38 * V_39 ;
V_39 = F_22 ( V_24 , V_13 ) ;
if ( ! V_39 )
return;
F_23 ( V_37 , & V_39 -> V_9 . V_40 ) ;
F_24 ( V_39 ) ;
}
static void F_25 ( struct V_23 * V_24 ,
unsigned short V_13 )
{
F_21 ( V_24 , V_13 , 1 ) ;
}
static void F_26 ( struct V_23 * V_24 ,
unsigned short V_13 )
{
F_21 ( V_24 , V_13 , - 1 ) ;
}
static void F_27 ( struct V_41 * V_36 ,
unsigned short V_13 , int V_37 )
{
struct V_42 * V_39 ;
V_39 = F_28 ( V_36 , V_13 ) ;
if ( ! V_39 )
return;
if ( F_29 ( V_37 , & V_39 -> V_9 . V_40 ) == 0 ) {
F_30 ( & V_36 -> V_43 ) ;
F_31 ( & V_39 -> V_44 ) ;
F_32 ( & V_36 -> V_43 ) ;
F_33 ( V_39 ) ;
}
F_33 ( V_39 ) ;
}
static void F_34 ( struct V_41 * V_36 ,
unsigned short V_13 )
{
F_27 ( V_36 , V_13 , 1 ) ;
}
static void F_35 ( struct V_41 * V_36 ,
unsigned short V_13 )
{
F_27 ( V_36 , V_13 , - 1 ) ;
}
static void
F_36 ( struct V_34 * V_35 )
{
if ( ! F_14 ( & V_35 -> V_21 ) )
return;
F_37 ( & V_35 -> V_32 , F_18 ) ;
}
static void F_38 ( struct V_23 * V_24 ,
struct V_22 * V_26 ,
T_2 V_45 )
{
struct V_46 * V_47 , * V_48 , * V_49 ;
struct V_5 * V_28 = & V_26 -> V_28 ;
T_2 V_50 = V_28 -> V_50 | V_45 ;
bool V_51 = false ;
bool V_52 , V_53 ;
V_47 = F_39 ( sizeof( * V_47 ) , V_54 ) ;
if ( ! V_47 )
return;
V_47 -> V_55 . V_50 = V_50 ;
memset ( V_47 -> V_55 . V_56 , 0 ,
sizeof( V_47 -> V_55 . V_56 ) ) ;
memcpy ( V_47 -> V_55 . V_11 , V_28 -> V_11 , V_12 ) ;
V_47 -> V_55 . V_13 = F_40 ( V_28 -> V_13 ) ;
V_52 = V_50 & V_57 ;
F_30 ( & V_24 -> V_9 . V_58 ) ;
F_41 (entry, safe, &bat_priv->tt.changes_list,
list) {
if ( ! F_3 ( V_48 -> V_55 . V_11 , V_28 -> V_11 ) )
continue;
V_53 = V_48 -> V_55 . V_50 & V_57 ;
if ( ! V_52 && V_53 )
goto V_59;
if ( V_52 && ! V_53 )
goto V_59;
if ( ! V_52 && ! V_53 )
V_48 -> V_55 . V_50 = V_50 ;
continue;
V_59:
F_42 ( & V_48 -> V_44 ) ;
F_20 ( V_48 ) ;
F_20 ( V_47 ) ;
V_51 = true ;
goto V_60;
}
F_43 ( & V_47 -> V_44 , & V_24 -> V_9 . V_61 ) ;
V_60:
F_32 ( & V_24 -> V_9 . V_58 ) ;
if ( V_51 )
F_44 ( & V_24 -> V_9 . V_62 ) ;
else
F_45 ( & V_24 -> V_9 . V_62 ) ;
}
static int F_46 ( int V_63 )
{
return V_63 * sizeof( struct V_64 ) ;
}
static T_3 F_47 ( T_3 V_65 )
{
return V_65 / F_46 ( 1 ) ;
}
static int F_48 ( struct V_23 * V_24 )
{
T_3 V_66 = 0 , V_67 = 0 ;
struct V_38 * V_39 ;
int V_68 ;
F_7 () ;
F_8 (vlan, &bat_priv->softif_vlan_list, list) {
V_66 ++ ;
V_67 += F_49 ( & V_39 -> V_9 . V_40 ) ;
}
F_10 () ;
V_68 = sizeof( struct V_69 ) ;
V_68 += sizeof( struct V_70 ) ;
V_68 += sizeof( struct V_71 ) ;
V_68 += V_66 * sizeof( struct V_72 ) ;
return V_68 + F_46 ( V_67 ) ;
}
static int F_50 ( struct V_23 * V_24 )
{
if ( V_24 -> V_9 . V_27 )
return 0 ;
V_24 -> V_9 . V_27 = F_51 ( 1024 ) ;
if ( ! V_24 -> V_9 . V_27 )
return - V_73 ;
F_52 ( V_24 -> V_9 . V_27 ,
& V_74 ) ;
return 0 ;
}
static void F_53 ( struct V_23 * V_24 ,
struct V_29 * V_75 ,
const char * V_76 )
{
F_54 ( V_77 , V_24 ,
L_1 ,
V_75 -> V_28 . V_11 ,
F_55 ( V_75 -> V_28 . V_13 ) , V_76 ) ;
F_56 ( V_24 -> V_9 . V_31 , F_1 ,
F_4 , & V_75 -> V_28 ) ;
F_16 ( V_75 ) ;
}
bool F_57 ( struct V_78 * V_79 , const T_2 * V_11 ,
unsigned short V_13 , int V_80 , T_1 V_81 )
{
struct V_23 * V_24 = F_58 ( V_79 ) ;
struct V_22 * V_82 ;
struct V_29 * V_75 ;
struct V_78 * V_83 = NULL ;
struct V_15 * V_16 ;
struct V_34 * V_35 ;
int V_84 , V_85 , V_86 ;
bool V_87 = false , V_88 = false ;
T_2 V_89 ;
T_1 V_90 ;
if ( V_80 != V_91 )
V_83 = F_59 ( & V_92 , V_80 ) ;
V_82 = F_11 ( V_24 , V_11 , V_13 ) ;
V_75 = F_12 ( V_24 , V_11 , V_13 ) ;
if ( V_82 ) {
V_82 -> V_93 = V_94 ;
if ( V_82 -> V_28 . V_50 & V_95 ) {
F_54 ( V_77 , V_24 ,
L_2 ,
V_11 , F_55 ( V_13 ) ) ;
V_82 -> V_28 . V_50 &= ~ V_95 ;
goto V_96;
}
if ( V_82 -> V_28 . V_50 & V_97 ) {
F_54 ( V_77 , V_24 ,
L_3 ,
V_11 , F_55 ( V_13 ) ) ;
V_82 -> V_28 . V_50 &= ~ V_97 ;
V_88 = true ;
}
goto V_98;
}
V_85 = F_48 ( V_24 ) ;
V_85 += F_46 ( 1 ) ;
V_86 = F_49 ( & V_24 -> V_86 ) ;
if ( V_85 > V_86 ) {
F_60 ( V_99 , V_79 ,
L_4 ,
V_85 , V_86 , V_11 ) ;
goto V_100;
}
V_82 = F_39 ( sizeof( * V_82 ) , V_54 ) ;
if ( ! V_82 )
goto V_100;
F_54 ( V_77 , V_24 ,
L_5 ,
V_11 , F_55 ( V_13 ) ,
( T_2 ) F_49 ( & V_24 -> V_9 . V_101 ) ) ;
memcpy ( V_82 -> V_28 . V_11 , V_11 , V_12 ) ;
V_82 -> V_28 . V_50 = V_102 ;
V_82 -> V_28 . V_13 = V_13 ;
if ( F_61 ( V_83 ) )
V_82 -> V_28 . V_50 |= V_103 ;
F_62 ( & V_82 -> V_28 . V_21 , 2 ) ;
V_82 -> V_93 = V_94 ;
V_82 -> V_28 . V_104 = V_82 -> V_93 ;
if ( F_3 ( V_11 , V_79 -> V_105 ) )
V_82 -> V_28 . V_50 |= V_106 ;
V_84 = F_63 ( V_24 -> V_9 . V_27 , F_1 ,
F_4 , & V_82 -> V_28 ,
& V_82 -> V_28 . V_6 ) ;
if ( F_64 ( V_84 != 0 ) ) {
F_13 ( V_82 ) ;
goto V_100;
}
V_96:
F_38 ( V_24 , V_82 , V_107 ) ;
V_98:
if ( V_75 && ! ( V_75 -> V_28 . V_50 & V_97 ) ) {
V_16 = & V_75 -> V_108 ;
F_7 () ;
F_8 (orig_entry, head, list) {
F_65 ( V_24 , V_75 -> V_28 . V_11 ,
V_75 -> V_28 . V_13 ,
V_35 -> V_36 ) ;
}
F_10 () ;
if ( V_88 ) {
F_53 ( V_24 , V_75 ,
L_6 ) ;
V_75 = NULL ;
} else {
V_75 -> V_28 . V_50 |= V_97 ;
V_75 -> V_109 = V_94 ;
}
}
V_89 = V_82 -> V_28 . V_50 & V_110 ;
if ( F_61 ( V_83 ) )
V_82 -> V_28 . V_50 |= V_103 ;
else
V_82 -> V_28 . V_50 &= ~ V_103 ;
V_90 = ( V_81 & V_24 -> V_111 ) ;
if ( V_24 -> V_111 &&
V_90 == V_24 -> V_112 )
V_82 -> V_28 . V_50 |= V_113 ;
else
V_82 -> V_28 . V_50 &= ~ V_113 ;
if ( V_89 ^ ( V_82 -> V_28 . V_50 & V_110 ) )
F_38 ( V_24 , V_82 , V_107 ) ;
V_87 = true ;
V_100:
if ( V_83 )
F_66 ( V_83 ) ;
if ( V_82 )
F_13 ( V_82 ) ;
if ( V_75 )
F_16 ( V_75 ) ;
return V_87 ;
}
static T_3
F_67 ( struct V_41 * V_36 ,
struct V_71 * * V_114 ,
struct V_64 * * V_115 ,
T_4 * V_65 )
{
T_3 V_66 = 0 , V_40 = 0 , V_116 , V_117 ;
struct V_72 * V_118 ;
struct V_42 * V_39 ;
T_2 * V_119 ;
F_7 () ;
F_68 (vlan, &orig_node->vlan_list, list) {
V_66 ++ ;
V_40 += F_49 ( & V_39 -> V_9 . V_40 ) ;
}
V_116 = sizeof( * * V_114 ) ;
V_116 += V_66 * sizeof( * V_118 ) ;
if ( * V_65 < 0 )
* V_65 = F_46 ( V_40 ) ;
V_117 = * V_65 ;
V_117 += V_116 ;
* V_114 = F_39 ( V_117 , V_54 ) ;
if ( ! * V_114 ) {
* V_65 = 0 ;
goto V_100;
}
( * V_114 ) -> V_50 = V_107 ;
( * V_114 ) -> V_120 = F_49 ( & V_36 -> V_121 ) ;
( * V_114 ) -> V_66 = F_40 ( V_66 ) ;
V_118 = (struct V_72 * ) ( * V_114 + 1 ) ;
F_68 (vlan, &orig_node->vlan_list, list) {
V_118 -> V_13 = F_40 ( V_39 -> V_13 ) ;
V_118 -> V_122 = F_69 ( V_39 -> V_9 . V_122 ) ;
V_118 ++ ;
}
V_119 = ( T_2 * ) * V_114 + V_116 ;
* V_115 = (struct V_64 * ) V_119 ;
V_100:
F_10 () ;
return V_117 ;
}
static T_3
F_70 ( struct V_23 * V_24 ,
struct V_71 * * V_114 ,
struct V_64 * * V_115 ,
T_4 * V_65 )
{
struct V_72 * V_118 ;
struct V_38 * V_39 ;
T_3 V_66 = 0 , V_40 = 0 , V_117 ;
T_2 * V_119 ;
int V_116 ;
F_7 () ;
F_8 (vlan, &bat_priv->softif_vlan_list, list) {
V_66 ++ ;
V_40 += F_49 ( & V_39 -> V_9 . V_40 ) ;
}
V_116 = sizeof( * * V_114 ) ;
V_116 += V_66 * sizeof( * V_118 ) ;
if ( * V_65 < 0 )
* V_65 = F_46 ( V_40 ) ;
V_117 = * V_65 ;
V_117 += V_116 ;
* V_114 = F_39 ( V_117 , V_54 ) ;
if ( ! * V_114 ) {
V_117 = 0 ;
goto V_100;
}
( * V_114 ) -> V_50 = V_107 ;
( * V_114 ) -> V_120 = F_49 ( & V_24 -> V_9 . V_101 ) ;
( * V_114 ) -> V_66 = F_40 ( V_66 ) ;
V_118 = (struct V_72 * ) ( * V_114 + 1 ) ;
F_8 (vlan, &bat_priv->softif_vlan_list, list) {
V_118 -> V_13 = F_40 ( V_39 -> V_13 ) ;
V_118 -> V_122 = F_69 ( V_39 -> V_9 . V_122 ) ;
V_118 ++ ;
}
V_119 = ( T_2 * ) * V_114 + V_116 ;
* V_115 = (struct V_64 * ) V_119 ;
V_100:
F_10 () ;
return V_117 ;
}
static void F_71 ( struct V_23 * V_24 )
{
struct V_46 * V_48 , * V_49 ;
struct V_71 * V_114 ;
struct V_64 * V_115 ;
int V_123 , V_124 = 0 ;
int V_125 = 0 , V_126 = 0 ;
T_3 V_117 ;
V_125 = F_49 ( & V_24 -> V_9 . V_62 ) ;
V_123 = F_46 ( V_125 ) ;
if ( V_123 > V_24 -> V_79 -> V_127 )
V_123 = 0 ;
V_117 = F_70 ( V_24 , & V_114 ,
& V_115 , & V_123 ) ;
if ( ! V_117 )
return;
V_114 -> V_50 = V_128 ;
if ( V_123 == 0 )
goto V_129;
F_30 ( & V_24 -> V_9 . V_58 ) ;
F_62 ( & V_24 -> V_9 . V_62 , 0 ) ;
F_41 (entry, safe, &bat_priv->tt.changes_list,
list) {
if ( V_126 < V_125 ) {
memcpy ( V_115 + V_126 ,
& V_48 -> V_55 ,
sizeof( struct V_64 ) ) ;
V_126 ++ ;
}
F_42 ( & V_48 -> V_44 ) ;
F_20 ( V_48 ) ;
}
F_32 ( & V_24 -> V_9 . V_58 ) ;
F_30 ( & V_24 -> V_9 . V_130 ) ;
F_20 ( V_24 -> V_9 . V_131 ) ;
V_24 -> V_9 . V_132 = 0 ;
V_24 -> V_9 . V_131 = NULL ;
V_124 = F_46 ( V_126 ) ;
if ( V_126 > 0 ) {
V_24 -> V_9 . V_131 = F_72 ( V_123 , V_54 ) ;
if ( V_24 -> V_9 . V_131 ) {
memcpy ( V_24 -> V_9 . V_131 ,
V_115 , V_124 ) ;
V_24 -> V_9 . V_132 = V_123 ;
}
}
F_32 ( & V_24 -> V_9 . V_130 ) ;
V_129:
F_73 ( V_24 , V_133 , 1 , V_114 ,
V_117 ) ;
F_20 ( V_114 ) ;
}
int F_74 ( struct V_134 * V_135 , void * V_136 )
{
struct V_78 * V_137 = (struct V_78 * ) V_135 -> V_138 ;
struct V_23 * V_24 = F_58 ( V_137 ) ;
struct V_14 * V_10 = V_24 -> V_9 . V_27 ;
struct V_5 * V_25 ;
struct V_22 * V_82 ;
struct V_139 * V_140 ;
struct V_38 * V_39 ;
struct V_15 * V_16 ;
unsigned short V_13 ;
T_1 V_141 ;
int V_142 ;
int V_143 ;
unsigned long V_144 ;
bool V_145 ;
T_3 V_146 = V_106 ;
V_140 = F_75 ( V_135 ) ;
if ( ! V_140 )
goto V_100;
F_76 ( V_135 ,
L_7 ,
V_137 -> V_147 , ( T_2 ) F_49 ( & V_24 -> V_9 . V_101 ) ) ;
F_76 ( V_135 , L_8 , L_9 , L_10 ,
L_11 , L_12 , L_13 ) ;
for ( V_141 = 0 ; V_141 < V_10 -> V_8 ; V_141 ++ ) {
V_16 = & V_10 -> V_20 [ V_141 ] ;
F_7 () ;
F_8 (tt_common_entry,
head, hash_entry) {
V_82 = F_2 ( V_25 ,
struct V_22 ,
V_28 ) ;
V_13 = V_25 -> V_13 ;
V_144 = V_94 - V_82 -> V_93 ;
V_143 = F_77 ( V_144 ) ;
V_142 = V_143 / 1000 ;
V_143 = V_143 % 1000 ;
V_145 = V_25 -> V_50 & V_146 ;
V_39 = F_22 ( V_24 , V_13 ) ;
if ( ! V_39 ) {
F_76 ( V_135 , L_14 ,
F_55 ( V_13 ) ) ;
continue;
}
F_76 ( V_135 ,
L_15 ,
V_25 -> V_11 ,
F_55 ( V_25 -> V_13 ) ,
( V_25 -> V_50 &
V_97 ? 'R' : '.' ) ,
V_145 ? 'P' : '.' ,
( V_25 -> V_50 &
V_102 ? 'N' : '.' ) ,
( V_25 -> V_50 &
V_95 ? 'X' : '.' ) ,
( V_25 -> V_50 &
V_103 ? 'W' : '.' ) ,
( V_25 -> V_50 &
V_113 ? 'I' : '.' ) ,
V_145 ? 0 : V_142 ,
V_145 ? 0 : V_143 ,
V_39 -> V_9 . V_122 ) ;
F_24 ( V_39 ) ;
}
F_10 () ;
}
V_100:
if ( V_140 )
F_78 ( V_140 ) ;
return 0 ;
}
static void
F_79 ( struct V_23 * V_24 ,
struct V_22 * V_26 ,
T_3 V_50 , const char * V_76 )
{
F_38 ( V_24 , V_26 , V_50 ) ;
V_26 -> V_28 . V_50 |= V_95 ;
F_54 ( V_77 , V_24 ,
L_16 ,
V_26 -> V_28 . V_11 ,
F_55 ( V_26 -> V_28 . V_13 ) , V_76 ) ;
}
T_3 F_80 ( struct V_23 * V_24 ,
const T_2 * V_11 , unsigned short V_13 ,
const char * V_76 , bool V_148 )
{
struct V_22 * V_26 ;
T_3 V_50 , V_149 = V_107 ;
V_26 = F_11 ( V_24 , V_11 , V_13 ) ;
if ( ! V_26 )
goto V_100;
V_149 = V_26 -> V_28 . V_50 ;
V_50 = V_57 ;
if ( V_148 ) {
V_50 |= V_97 ;
V_26 -> V_28 . V_50 |= V_97 ;
}
if ( ! ( V_26 -> V_28 . V_50 & V_102 ) ) {
F_79 ( V_24 , V_26 , V_50 ,
V_76 ) ;
goto V_100;
}
F_38 ( V_24 , V_26 , V_57 ) ;
F_81 ( & V_26 -> V_28 . V_6 ) ;
F_13 ( V_26 ) ;
V_100:
if ( V_26 )
F_13 ( V_26 ) ;
return V_149 ;
}
static void F_82 ( struct V_23 * V_24 ,
struct V_15 * V_16 ,
int V_150 )
{
struct V_22 * V_26 ;
struct V_5 * V_25 ;
struct V_1 * V_151 ;
F_83 (tt_common_entry, node_tmp, head,
hash_entry) {
V_26 = F_2 ( V_25 ,
struct V_22 ,
V_28 ) ;
if ( V_26 -> V_28 . V_50 & V_106 )
continue;
if ( V_26 -> V_28 . V_50 & V_95 )
continue;
if ( ! F_84 ( V_26 -> V_93 , V_150 ) )
continue;
F_79 ( V_24 , V_26 ,
V_57 , L_17 ) ;
}
}
static void F_85 ( struct V_23 * V_24 ,
int V_150 )
{
struct V_14 * V_10 = V_24 -> V_9 . V_27 ;
struct V_15 * V_16 ;
T_5 * V_152 ;
T_1 V_141 ;
for ( V_141 = 0 ; V_141 < V_10 -> V_8 ; V_141 ++ ) {
V_16 = & V_10 -> V_20 [ V_141 ] ;
V_152 = & V_10 -> V_153 [ V_141 ] ;
F_30 ( V_152 ) ;
F_82 ( V_24 , V_16 , V_150 ) ;
F_32 ( V_152 ) ;
}
}
static void F_86 ( struct V_23 * V_24 )
{
struct V_14 * V_10 ;
T_5 * V_152 ;
struct V_5 * V_25 ;
struct V_22 * V_82 ;
struct V_1 * V_151 ;
struct V_15 * V_16 ;
T_1 V_141 ;
if ( ! V_24 -> V_9 . V_27 )
return;
V_10 = V_24 -> V_9 . V_27 ;
for ( V_141 = 0 ; V_141 < V_10 -> V_8 ; V_141 ++ ) {
V_16 = & V_10 -> V_20 [ V_141 ] ;
V_152 = & V_10 -> V_153 [ V_141 ] ;
F_30 ( V_152 ) ;
F_83 (tt_common_entry, node_tmp,
head, hash_entry) {
F_81 ( & V_25 -> V_6 ) ;
V_82 = F_2 ( V_25 ,
struct V_22 ,
V_28 ) ;
F_13 ( V_82 ) ;
}
F_32 ( V_152 ) ;
}
F_87 ( V_10 ) ;
V_24 -> V_9 . V_27 = NULL ;
}
static int F_88 ( struct V_23 * V_24 )
{
if ( V_24 -> V_9 . V_31 )
return 0 ;
V_24 -> V_9 . V_31 = F_51 ( 1024 ) ;
if ( ! V_24 -> V_9 . V_31 )
return - V_73 ;
F_52 ( V_24 -> V_9 . V_31 ,
& V_154 ) ;
return 0 ;
}
static void F_89 ( struct V_23 * V_24 )
{
struct V_46 * V_48 , * V_49 ;
F_30 ( & V_24 -> V_9 . V_58 ) ;
F_41 (entry, safe, &bat_priv->tt.changes_list,
list) {
F_42 ( & V_48 -> V_44 ) ;
F_20 ( V_48 ) ;
}
F_62 ( & V_24 -> V_9 . V_62 , 0 ) ;
F_32 ( & V_24 -> V_9 . V_58 ) ;
}
static struct V_34 *
F_90 ( const struct V_29 * V_48 ,
const struct V_41 * V_36 )
{
struct V_34 * V_155 , * V_35 = NULL ;
const struct V_15 * V_16 ;
F_7 () ;
V_16 = & V_48 -> V_108 ;
F_8 (tmp_orig_entry, head, list) {
if ( V_155 -> V_36 != V_36 )
continue;
if ( ! F_9 ( & V_155 -> V_21 ) )
continue;
V_35 = V_155 ;
break;
}
F_10 () ;
return V_35 ;
}
static bool
F_91 ( const struct V_29 * V_48 ,
const struct V_41 * V_36 )
{
struct V_34 * V_35 ;
bool V_156 = false ;
V_35 = F_90 ( V_48 , V_36 ) ;
if ( V_35 ) {
V_156 = true ;
F_36 ( V_35 ) ;
}
return V_156 ;
}
static void
F_92 ( struct V_29 * V_75 ,
struct V_41 * V_36 , int V_120 )
{
struct V_34 * V_35 ;
V_35 = F_90 ( V_75 , V_36 ) ;
if ( V_35 ) {
V_35 -> V_120 = V_120 ;
goto V_100;
}
V_35 = F_72 ( sizeof( * V_35 ) , V_54 ) ;
if ( ! V_35 )
goto V_100;
F_93 ( & V_35 -> V_44 ) ;
F_45 ( & V_36 -> V_21 ) ;
F_34 ( V_36 , V_75 -> V_28 . V_13 ) ;
V_35 -> V_36 = V_36 ;
V_35 -> V_120 = V_120 ;
F_62 ( & V_35 -> V_21 , 2 ) ;
F_30 ( & V_75 -> V_152 ) ;
F_94 ( & V_35 -> V_44 ,
& V_75 -> V_108 ) ;
F_32 ( & V_75 -> V_152 ) ;
V_100:
if ( V_35 )
F_36 ( V_35 ) ;
}
static bool F_95 ( struct V_23 * V_24 ,
struct V_41 * V_36 ,
const unsigned char * V_157 ,
unsigned short V_13 , T_3 V_50 ,
T_2 V_120 )
{
struct V_29 * V_30 ;
struct V_22 * V_26 ;
bool V_87 = false ;
int V_84 ;
struct V_5 * V_28 ;
T_3 V_158 ;
if ( F_96 ( V_24 , V_36 -> V_159 , V_13 ) )
return true ;
V_30 = F_12 ( V_24 , V_157 , V_13 ) ;
V_26 = F_11 ( V_24 , V_157 , V_13 ) ;
if ( ( V_50 & V_160 ) && V_26 &&
! ( V_26 -> V_28 . V_50 & V_102 ) )
goto V_100;
if ( ! V_30 ) {
V_30 = F_72 ( sizeof( * V_30 ) , V_54 ) ;
if ( ! V_30 )
goto V_100;
V_28 = & V_30 -> V_28 ;
memcpy ( V_28 -> V_11 , V_157 , V_12 ) ;
V_28 -> V_13 = V_13 ;
V_28 -> V_50 = V_50 ;
V_30 -> V_109 = 0 ;
if ( V_50 & V_97 )
V_30 -> V_109 = V_94 ;
F_62 ( & V_28 -> V_21 , 2 ) ;
V_28 -> V_104 = V_94 ;
F_97 ( & V_30 -> V_108 ) ;
F_98 ( & V_30 -> V_152 ) ;
V_84 = F_63 ( V_24 -> V_9 . V_31 ,
F_1 ,
F_4 , V_28 ,
& V_28 -> V_6 ) ;
if ( F_64 ( V_84 != 0 ) ) {
F_16 ( V_30 ) ;
goto V_161;
}
} else {
V_28 = & V_30 -> V_28 ;
if ( V_50 & V_160 ) {
if ( ! ( V_28 -> V_50 & V_160 ) )
goto V_100;
if ( F_91 ( V_30 ,
V_36 ) )
goto V_161;
F_17 ( V_30 ) ;
goto V_162;
}
V_28 -> V_50 &= ~ V_160 ;
V_30 -> V_28 . V_50 |= V_50 ;
if ( V_28 -> V_50 & V_97 ) {
F_17 ( V_30 ) ;
V_28 -> V_50 &= ~ V_97 ;
V_30 -> V_109 = 0 ;
}
}
V_162:
F_92 ( V_30 , V_36 , V_120 ) ;
F_54 ( V_77 , V_24 ,
L_18 ,
V_28 -> V_11 , F_55 ( V_28 -> V_13 ) ,
V_36 -> V_159 ) ;
V_87 = true ;
V_161:
V_158 = F_80 ( V_24 , V_157 , V_13 ,
L_19 ,
V_50 & V_97 ) ;
V_30 -> V_28 . V_50 |= V_158 & V_103 ;
if ( ! ( V_50 & V_97 ) )
V_30 -> V_28 . V_50 &= ~ V_97 ;
V_100:
if ( V_30 )
F_16 ( V_30 ) ;
if ( V_26 )
F_13 ( V_26 ) ;
return V_87 ;
}
static struct V_34 *
F_99 ( struct V_23 * V_24 ,
struct V_29 * V_30 )
{
struct V_163 * V_164 , * V_165 = NULL ;
struct V_166 * V_167 = V_24 -> V_168 ;
struct V_15 * V_16 ;
struct V_34 * V_35 , * V_169 = NULL ;
V_16 = & V_30 -> V_108 ;
F_8 (orig_entry, head, list) {
V_164 = F_100 ( V_35 -> V_36 ,
V_170 ) ;
if ( ! V_164 )
continue;
if ( V_165 &&
V_167 -> V_171 ( V_164 , V_170 ,
V_165 , V_170 ) <= 0 ) {
F_101 ( V_164 ) ;
continue;
}
if ( V_165 )
F_101 ( V_165 ) ;
V_169 = V_35 ;
V_165 = V_164 ;
}
if ( V_165 )
F_101 ( V_165 ) ;
return V_169 ;
}
static void
F_102 ( struct V_23 * V_24 ,
struct V_29 * V_30 ,
struct V_134 * V_135 )
{
struct V_34 * V_35 , * V_169 ;
struct V_5 * V_25 ;
struct V_42 * V_39 ;
struct V_15 * V_16 ;
T_2 V_121 ;
T_3 V_50 ;
V_25 = & V_30 -> V_28 ;
V_50 = V_25 -> V_50 ;
V_169 = F_99 ( V_24 , V_30 ) ;
if ( V_169 ) {
V_39 = F_103 ( V_169 -> V_36 ,
V_25 -> V_13 ) ;
if ( ! V_39 ) {
F_76 ( V_135 ,
L_20 ,
F_55 ( V_25 -> V_13 ) ,
V_169 -> V_36 -> V_159 ) ;
goto V_172;
}
V_121 = F_49 ( & V_169 -> V_36 -> V_121 ) ;
F_76 ( V_135 ,
L_21 ,
'*' , V_30 -> V_28 . V_11 ,
F_55 ( V_30 -> V_28 . V_13 ) ,
V_169 -> V_120 , V_169 -> V_36 -> V_159 ,
V_121 , V_39 -> V_9 . V_122 ,
( V_50 & V_97 ? 'R' : '.' ) ,
( V_50 & V_103 ? 'W' : '.' ) ,
( V_50 & V_113 ? 'I' : '.' ) ,
( V_50 & V_160 ? 'T' : '.' ) ) ;
F_33 ( V_39 ) ;
}
V_172:
V_16 = & V_30 -> V_108 ;
F_8 (orig_entry, head, list) {
if ( V_169 == V_35 )
continue;
V_39 = F_103 ( V_35 -> V_36 ,
V_25 -> V_13 ) ;
if ( ! V_39 ) {
F_76 ( V_135 ,
L_22 ,
F_55 ( V_25 -> V_13 ) ,
V_35 -> V_36 -> V_159 ) ;
continue;
}
V_121 = F_49 ( & V_35 -> V_36 -> V_121 ) ;
F_76 ( V_135 ,
L_23 ,
'+' , V_30 -> V_28 . V_11 ,
F_55 ( V_30 -> V_28 . V_13 ) ,
V_35 -> V_120 , V_35 -> V_36 -> V_159 ,
V_121 , V_39 -> V_9 . V_122 ,
( V_50 & V_97 ? 'R' : '.' ) ,
( V_50 & V_103 ? 'W' : '.' ) ,
( V_50 & V_113 ? 'I' : '.' ) ,
( V_50 & V_160 ? 'T' : '.' ) ) ;
F_33 ( V_39 ) ;
}
}
int F_104 ( struct V_134 * V_135 , void * V_136 )
{
struct V_78 * V_137 = (struct V_78 * ) V_135 -> V_138 ;
struct V_23 * V_24 = F_58 ( V_137 ) ;
struct V_14 * V_10 = V_24 -> V_9 . V_31 ;
struct V_5 * V_25 ;
struct V_29 * V_75 ;
struct V_139 * V_140 ;
struct V_15 * V_16 ;
T_1 V_141 ;
V_140 = F_75 ( V_135 ) ;
if ( ! V_140 )
goto V_100;
F_76 ( V_135 ,
L_24 ,
V_137 -> V_147 ) ;
F_76 ( V_135 , L_25 ,
L_9 , L_10 , L_26 , L_27 , L_28 ,
L_13 , L_11 ) ;
for ( V_141 = 0 ; V_141 < V_10 -> V_8 ; V_141 ++ ) {
V_16 = & V_10 -> V_20 [ V_141 ] ;
F_7 () ;
F_8 (tt_common_entry,
head, hash_entry) {
V_75 = F_2 ( V_25 ,
struct V_29 ,
V_28 ) ;
F_102 ( V_24 , V_75 , V_135 ) ;
}
F_10 () ;
}
V_100:
if ( V_140 )
F_78 ( V_140 ) ;
return 0 ;
}
static void
F_17 ( struct V_29 * V_30 )
{
struct V_15 * V_16 ;
struct V_1 * V_49 ;
struct V_34 * V_35 ;
F_30 ( & V_30 -> V_152 ) ;
V_16 = & V_30 -> V_108 ;
F_83 (orig_entry, safe, head, list) {
F_81 ( & V_35 -> V_44 ) ;
F_35 ( V_35 -> V_36 ,
V_30 -> V_28 . V_13 ) ;
F_36 ( V_35 ) ;
}
F_32 ( & V_30 -> V_152 ) ;
}
static void
F_105 ( struct V_23 * V_24 ,
struct V_29 * V_30 ,
struct V_41 * V_36 ,
const char * V_76 )
{
struct V_15 * V_16 ;
struct V_1 * V_49 ;
struct V_34 * V_35 ;
unsigned short V_13 ;
F_30 ( & V_30 -> V_152 ) ;
V_16 = & V_30 -> V_108 ;
F_83 (orig_entry, safe, head, list) {
if ( V_35 -> V_36 == V_36 ) {
V_13 = V_30 -> V_28 . V_13 ;
F_54 ( V_77 , V_24 ,
L_29 ,
V_36 -> V_159 ,
V_30 -> V_28 . V_11 ,
F_55 ( V_13 ) , V_76 ) ;
F_81 ( & V_35 -> V_44 ) ;
F_35 ( V_36 ,
V_30 -> V_28 . V_13 ) ;
F_36 ( V_35 ) ;
}
}
F_32 ( & V_30 -> V_152 ) ;
}
static void
F_106 ( struct V_23 * V_24 ,
struct V_29 * V_30 ,
struct V_41 * V_36 ,
const char * V_76 )
{
bool V_173 = true ;
struct V_15 * V_16 ;
struct V_34 * V_35 ;
F_7 () ;
V_16 = & V_30 -> V_108 ;
F_8 (orig_entry, head, list) {
if ( V_35 -> V_36 != V_36 ) {
V_173 = false ;
break;
}
}
F_10 () ;
if ( V_173 ) {
V_30 -> V_28 . V_50 |= V_97 ;
V_30 -> V_109 = V_94 ;
} else
F_105 ( V_24 , V_30 ,
V_36 , V_76 ) ;
}
static void F_107 ( struct V_23 * V_24 ,
struct V_41 * V_36 ,
const unsigned char * V_11 , unsigned short V_13 ,
const char * V_76 , bool V_148 )
{
struct V_29 * V_30 ;
struct V_22 * V_174 = NULL ;
V_30 = F_12 ( V_24 , V_11 , V_13 ) ;
if ( ! V_30 )
goto V_100;
if ( ! V_148 ) {
F_105 ( V_24 , V_30 ,
V_36 , V_76 ) ;
if ( F_108 ( & V_30 -> V_108 ) )
F_53 ( V_24 , V_30 ,
V_76 ) ;
goto V_100;
}
V_174 = F_11 ( V_24 ,
V_30 -> V_28 . V_11 ,
V_13 ) ;
if ( V_174 ) {
F_17 ( V_30 ) ;
F_53 ( V_24 , V_30 , V_76 ) ;
} else
F_106 ( V_24 , V_30 ,
V_36 , V_76 ) ;
V_100:
if ( V_30 )
F_16 ( V_30 ) ;
if ( V_174 )
F_13 ( V_174 ) ;
}
void F_109 ( struct V_23 * V_24 ,
struct V_41 * V_36 ,
T_4 V_175 ,
const char * V_76 )
{
struct V_29 * V_75 ;
struct V_5 * V_25 ;
T_1 V_141 ;
struct V_14 * V_10 = V_24 -> V_9 . V_31 ;
struct V_1 * V_49 ;
struct V_15 * V_16 ;
T_5 * V_152 ;
unsigned short V_13 ;
if ( ! V_10 )
return;
for ( V_141 = 0 ; V_141 < V_10 -> V_8 ; V_141 ++ ) {
V_16 = & V_10 -> V_20 [ V_141 ] ;
V_152 = & V_10 -> V_153 [ V_141 ] ;
F_30 ( V_152 ) ;
F_83 (tt_common_entry, safe,
head, hash_entry) {
if ( V_175 >= 0 && V_25 -> V_13 != V_175 )
continue;
V_75 = F_2 ( V_25 ,
struct V_29 ,
V_28 ) ;
F_105 ( V_24 , V_75 ,
V_36 , V_76 ) ;
if ( F_108 ( & V_75 -> V_108 ) ) {
V_13 = V_75 -> V_28 . V_13 ;
F_54 ( V_77 , V_24 ,
L_1 ,
V_75 -> V_28 . V_11 ,
F_55 ( V_13 ) , V_76 ) ;
F_81 ( & V_25 -> V_6 ) ;
F_16 ( V_75 ) ;
}
}
F_32 ( V_152 ) ;
}
V_36 -> V_176 = false ;
}
static bool F_110 ( struct V_29 * V_75 ,
char * * V_177 )
{
bool V_178 = false ;
unsigned long V_179 = V_180 ;
unsigned long V_181 = V_182 ;
if ( ( V_75 -> V_28 . V_50 & V_97 ) &&
F_84 ( V_75 -> V_109 , V_179 ) ) {
V_178 = true ;
* V_177 = L_30 ;
}
if ( ( V_75 -> V_28 . V_50 & V_160 ) &&
F_84 ( V_75 -> V_28 . V_104 , V_181 ) ) {
V_178 = true ;
* V_177 = L_31 ;
}
return V_178 ;
}
static void F_111 ( struct V_23 * V_24 )
{
struct V_14 * V_10 = V_24 -> V_9 . V_31 ;
struct V_15 * V_16 ;
struct V_1 * V_151 ;
T_5 * V_152 ;
T_1 V_141 ;
char * V_177 = NULL ;
struct V_5 * V_183 ;
struct V_29 * V_75 ;
for ( V_141 = 0 ; V_141 < V_10 -> V_8 ; V_141 ++ ) {
V_16 = & V_10 -> V_20 [ V_141 ] ;
V_152 = & V_10 -> V_153 [ V_141 ] ;
F_30 ( V_152 ) ;
F_83 (tt_common, node_tmp, head,
hash_entry) {
V_75 = F_2 ( V_183 ,
struct V_29 ,
V_28 ) ;
if ( ! F_110 ( V_75 , & V_177 ) )
continue;
F_54 ( V_77 , V_24 ,
L_1 ,
V_75 -> V_28 . V_11 ,
F_55 ( V_75 -> V_28 . V_13 ) ,
V_177 ) ;
F_81 ( & V_183 -> V_6 ) ;
F_16 ( V_75 ) ;
}
F_32 ( V_152 ) ;
}
}
static void F_112 ( struct V_23 * V_24 )
{
struct V_14 * V_10 ;
T_5 * V_152 ;
struct V_5 * V_25 ;
struct V_29 * V_75 ;
struct V_1 * V_151 ;
struct V_15 * V_16 ;
T_1 V_141 ;
if ( ! V_24 -> V_9 . V_31 )
return;
V_10 = V_24 -> V_9 . V_31 ;
for ( V_141 = 0 ; V_141 < V_10 -> V_8 ; V_141 ++ ) {
V_16 = & V_10 -> V_20 [ V_141 ] ;
V_152 = & V_10 -> V_153 [ V_141 ] ;
F_30 ( V_152 ) ;
F_83 (tt_common_entry, node_tmp,
head, hash_entry) {
F_81 ( & V_25 -> V_6 ) ;
V_75 = F_2 ( V_25 ,
struct V_29 ,
V_28 ) ;
F_16 ( V_75 ) ;
}
F_32 ( V_152 ) ;
}
F_87 ( V_10 ) ;
V_24 -> V_9 . V_31 = NULL ;
}
static bool
F_113 ( struct V_22 * V_26 ,
struct V_29 * V_30 )
{
bool V_87 = false ;
if ( V_26 -> V_28 . V_50 & V_103 &&
V_30 -> V_28 . V_50 & V_103 )
V_87 = true ;
if ( V_26 -> V_28 . V_50 & V_113 &&
V_30 -> V_28 . V_50 & V_113 )
V_87 = true ;
return V_87 ;
}
struct V_41 * F_114 ( struct V_23 * V_24 ,
const T_2 * V_184 ,
const T_2 * V_11 ,
unsigned short V_13 )
{
struct V_22 * V_26 = NULL ;
struct V_29 * V_30 = NULL ;
struct V_41 * V_36 = NULL ;
struct V_34 * V_169 ;
if ( V_184 && F_115 ( V_24 , V_13 ) ) {
V_26 = F_11 ( V_24 , V_184 , V_13 ) ;
if ( ! V_26 ||
( V_26 -> V_28 . V_50 & V_95 ) )
goto V_100;
}
V_30 = F_12 ( V_24 , V_11 , V_13 ) ;
if ( ! V_30 )
goto V_100;
if ( V_26 &&
F_113 ( V_26 , V_30 ) )
goto V_100;
F_7 () ;
V_169 = F_99 ( V_24 , V_30 ) ;
if ( V_169 )
V_36 = V_169 -> V_36 ;
if ( V_36 && ! F_9 ( & V_36 -> V_21 ) )
V_36 = NULL ;
F_10 () ;
V_100:
if ( V_30 )
F_16 ( V_30 ) ;
if ( V_26 )
F_13 ( V_26 ) ;
return V_36 ;
}
static T_1 F_116 ( struct V_23 * V_24 ,
struct V_41 * V_36 ,
unsigned short V_13 )
{
struct V_14 * V_10 = V_24 -> V_9 . V_31 ;
struct V_5 * V_183 ;
struct V_29 * V_75 ;
struct V_15 * V_16 ;
T_1 V_141 , V_185 , V_122 = 0 ;
T_2 V_50 ;
T_6 V_186 ;
for ( V_141 = 0 ; V_141 < V_10 -> V_8 ; V_141 ++ ) {
V_16 = & V_10 -> V_20 [ V_141 ] ;
F_7 () ;
F_8 (tt_common, head, hash_entry) {
V_75 = F_2 ( V_183 ,
struct V_29 ,
V_28 ) ;
if ( V_183 -> V_13 != V_13 )
continue;
if ( V_183 -> V_50 & V_97 )
continue;
if ( V_183 -> V_50 & V_160 )
continue;
if ( ! F_91 ( V_75 ,
V_36 ) )
continue;
V_186 = F_40 ( V_183 -> V_13 ) ;
V_185 = F_117 ( 0 , & V_186 , sizeof( V_186 ) ) ;
V_50 = V_183 -> V_50 & V_187 ;
V_185 = F_117 ( V_185 , & V_50 , sizeof( V_50 ) ) ;
V_122 ^= F_117 ( V_185 , V_183 -> V_11 , V_12 ) ;
}
F_10 () ;
}
return V_122 ;
}
static T_1 F_118 ( struct V_23 * V_24 ,
unsigned short V_13 )
{
struct V_14 * V_10 = V_24 -> V_9 . V_27 ;
struct V_5 * V_183 ;
struct V_15 * V_16 ;
T_1 V_141 , V_185 , V_122 = 0 ;
T_2 V_50 ;
T_6 V_186 ;
for ( V_141 = 0 ; V_141 < V_10 -> V_8 ; V_141 ++ ) {
V_16 = & V_10 -> V_20 [ V_141 ] ;
F_7 () ;
F_8 (tt_common, head, hash_entry) {
if ( V_183 -> V_13 != V_13 )
continue;
if ( V_183 -> V_50 & V_102 )
continue;
V_186 = F_40 ( V_183 -> V_13 ) ;
V_185 = F_117 ( 0 , & V_186 , sizeof( V_186 ) ) ;
V_50 = V_183 -> V_50 & V_187 ;
V_185 = F_117 ( V_185 , & V_50 , sizeof( V_50 ) ) ;
V_122 ^= F_117 ( V_185 , V_183 -> V_11 , V_12 ) ;
}
F_10 () ;
}
return V_122 ;
}
static void F_119 ( struct V_23 * V_24 )
{
struct V_188 * V_2 , * V_49 ;
F_30 ( & V_24 -> V_9 . V_189 ) ;
F_41 (node, safe, &bat_priv->tt.req_list, list) {
F_42 ( & V_2 -> V_44 ) ;
F_20 ( V_2 ) ;
}
F_32 ( & V_24 -> V_9 . V_189 ) ;
}
static void F_120 ( struct V_23 * V_24 ,
struct V_41 * V_36 ,
const void * V_190 ,
T_3 V_191 )
{
F_30 ( & V_36 -> V_192 ) ;
if ( V_191 > 0 ) {
F_20 ( V_36 -> V_190 ) ;
V_36 -> V_191 = 0 ;
V_36 -> V_190 = F_39 ( V_191 , V_54 ) ;
if ( V_36 -> V_190 ) {
memcpy ( V_36 -> V_190 , V_190 , V_191 ) ;
V_36 -> V_191 = V_191 ;
}
}
F_32 ( & V_36 -> V_192 ) ;
}
static void F_121 ( struct V_23 * V_24 )
{
struct V_188 * V_2 , * V_49 ;
F_30 ( & V_24 -> V_9 . V_189 ) ;
F_41 (node, safe, &bat_priv->tt.req_list, list) {
if ( F_84 ( V_2 -> V_193 ,
V_194 ) ) {
F_42 ( & V_2 -> V_44 ) ;
F_20 ( V_2 ) ;
}
}
F_32 ( & V_24 -> V_9 . V_189 ) ;
}
static struct V_188 *
F_122 ( struct V_23 * V_24 ,
struct V_41 * V_36 )
{
struct V_188 * V_195 , * V_196 = NULL ;
F_30 ( & V_24 -> V_9 . V_189 ) ;
F_123 (tt_req_node_tmp, &bat_priv->tt.req_list, list) {
if ( F_3 ( V_195 , V_36 ) &&
! F_84 ( V_195 -> V_193 ,
V_194 ) )
goto V_60;
}
V_196 = F_39 ( sizeof( * V_196 ) , V_54 ) ;
if ( ! V_196 )
goto V_60;
memcpy ( V_196 -> V_11 , V_36 -> V_159 , V_12 ) ;
V_196 -> V_193 = V_94 ;
F_124 ( & V_196 -> V_44 , & V_24 -> V_9 . V_197 ) ;
V_60:
F_32 ( & V_24 -> V_9 . V_189 ) ;
return V_196 ;
}
static int F_125 ( const void * V_198 , const void * V_199 )
{
const struct V_5 * V_25 = V_198 ;
if ( V_25 -> V_50 & V_102 )
return 0 ;
return 1 ;
}
static int F_126 ( const void * V_198 ,
const void * V_199 )
{
const struct V_5 * V_25 = V_198 ;
const struct V_29 * V_30 ;
const struct V_41 * V_36 = V_199 ;
if ( V_25 -> V_50 & V_97 ||
V_25 -> V_50 & V_160 )
return 0 ;
V_30 = F_2 ( V_25 ,
struct V_29 ,
V_28 ) ;
return F_91 ( V_30 , V_36 ) ;
}
static void F_127 ( struct V_23 * V_24 ,
struct V_14 * V_10 ,
void * V_200 , T_3 V_65 ,
int (* F_128)( const void * , const void * ) ,
void * V_201 )
{
struct V_5 * V_25 ;
struct V_64 * V_115 ;
struct V_15 * V_16 ;
T_3 V_202 , V_203 = 0 ;
T_1 V_141 ;
V_202 = F_47 ( V_65 ) ;
V_115 = (struct V_64 * ) V_200 ;
F_7 () ;
for ( V_141 = 0 ; V_141 < V_10 -> V_8 ; V_141 ++ ) {
V_16 = & V_10 -> V_20 [ V_141 ] ;
F_8 (tt_common_entry,
head, hash_entry) {
if ( V_202 == V_203 )
break;
if ( ( F_128 ) && ( ! F_128 ( V_25 , V_201 ) ) )
continue;
memcpy ( V_115 -> V_11 , V_25 -> V_11 ,
V_12 ) ;
V_115 -> V_50 = V_25 -> V_50 ;
V_115 -> V_13 = F_40 ( V_25 -> V_13 ) ;
memset ( V_115 -> V_56 , 0 ,
sizeof( V_115 -> V_56 ) ) ;
V_203 ++ ;
V_115 ++ ;
}
}
F_10 () ;
}
static bool F_129 ( struct V_41 * V_36 ,
struct V_72 * V_118 ,
T_3 V_66 )
{
struct V_72 * V_204 ;
struct V_42 * V_39 ;
T_1 V_122 ;
int V_141 ;
for ( V_141 = 0 ; V_141 < V_66 ; V_141 ++ ) {
V_204 = V_118 + V_141 ;
if ( F_96 ( V_36 -> V_24 ,
V_36 -> V_159 ,
F_130 ( V_204 -> V_13 ) ) )
continue;
V_39 = F_103 ( V_36 ,
F_130 ( V_204 -> V_13 ) ) ;
if ( ! V_39 )
return false ;
V_122 = V_39 -> V_9 . V_122 ;
F_33 ( V_39 ) ;
if ( V_122 != F_131 ( V_204 -> V_122 ) )
return false ;
}
return true ;
}
static void F_132 ( struct V_23 * V_24 )
{
struct V_38 * V_39 ;
F_7 () ;
F_8 (vlan, &bat_priv->softif_vlan_list, list) {
V_39 -> V_9 . V_122 = F_118 ( V_24 , V_39 -> V_13 ) ;
}
F_10 () ;
}
static void F_133 ( struct V_23 * V_24 ,
struct V_41 * V_36 )
{
struct V_42 * V_39 ;
T_1 V_122 ;
F_7 () ;
F_68 (vlan, &orig_node->vlan_list, list) {
if ( F_96 ( V_24 , V_36 -> V_159 ,
V_39 -> V_13 ) )
continue;
V_122 = F_116 ( V_24 , V_36 , V_39 -> V_13 ) ;
V_39 -> V_9 . V_122 = V_122 ;
}
F_10 () ;
}
static int F_134 ( struct V_23 * V_24 ,
struct V_41 * V_205 ,
T_2 V_120 ,
struct V_72 * V_118 ,
T_3 V_66 , bool V_206 )
{
struct V_71 * V_207 = NULL ;
struct V_188 * V_196 = NULL ;
struct V_72 * V_208 ;
struct V_139 * V_140 ;
bool V_87 = false ;
int V_141 , V_8 ;
V_140 = F_135 ( V_24 ) ;
if ( ! V_140 )
goto V_100;
V_196 = F_122 ( V_24 , V_205 ) ;
if ( ! V_196 )
goto V_100;
V_8 = sizeof( * V_207 ) + sizeof( * V_208 ) * V_66 ;
V_207 = F_72 ( V_8 , V_54 ) ;
if ( ! V_207 )
goto V_100;
V_207 -> V_50 = V_209 ;
V_207 -> V_120 = V_120 ;
V_207 -> V_66 = F_40 ( V_66 ) ;
V_208 = (struct V_72 * ) ( V_207 + 1 ) ;
for ( V_141 = 0 ; V_141 < V_66 ; V_141 ++ ) {
V_208 -> V_13 = V_118 -> V_13 ;
V_208 -> V_122 = V_118 -> V_122 ;
V_208 ++ ;
V_118 ++ ;
}
if ( V_206 )
V_207 -> V_50 |= V_210 ;
F_54 ( V_77 , V_24 , L_32 ,
V_205 -> V_159 , V_206 ? 'F' : '.' ) ;
F_136 ( V_24 , V_211 ) ;
F_137 ( V_24 , V_140 -> V_137 -> V_105 ,
V_205 -> V_159 , V_133 , 1 ,
V_207 , V_8 ) ;
V_87 = true ;
V_100:
if ( V_140 )
F_78 ( V_140 ) ;
if ( V_87 && V_196 ) {
F_30 ( & V_24 -> V_9 . V_189 ) ;
F_42 ( & V_196 -> V_44 ) ;
F_32 ( & V_24 -> V_9 . V_189 ) ;
F_20 ( V_196 ) ;
}
F_20 ( V_207 ) ;
return V_87 ;
}
static bool F_138 ( struct V_23 * V_24 ,
struct V_71 * V_114 ,
T_2 * V_212 , T_2 * V_213 )
{
struct V_41 * V_214 ;
struct V_41 * V_215 = NULL ;
struct V_64 * V_115 ;
struct V_71 * V_207 = NULL ;
struct V_72 * V_118 ;
bool V_87 = false , V_206 ;
T_2 V_216 , V_217 ;
T_3 V_117 ;
T_4 V_65 ;
F_54 ( V_77 , V_24 ,
L_33 ,
V_212 , V_114 -> V_120 , V_213 ,
( V_114 -> V_50 & V_210 ? 'F' : '.' ) ) ;
V_214 = F_139 ( V_24 , V_213 ) ;
if ( ! V_214 )
goto V_100;
V_215 = F_139 ( V_24 , V_212 ) ;
if ( ! V_215 )
goto V_100;
V_216 = ( T_2 ) F_49 ( & V_214 -> V_121 ) ;
V_217 = V_114 -> V_120 ;
V_118 = (struct V_72 * ) ( V_114 + 1 ) ;
if ( V_216 != V_217 ||
! F_129 ( V_214 , V_118 ,
F_130 ( V_114 -> V_66 ) ) )
goto V_100;
if ( V_114 -> V_50 & V_210 ||
! V_214 -> V_190 )
V_206 = true ;
else
V_206 = false ;
if ( ! V_206 ) {
F_30 ( & V_214 -> V_192 ) ;
V_65 = V_214 -> V_191 ;
V_117 = F_67 ( V_214 ,
& V_207 ,
& V_115 ,
& V_65 ) ;
if ( ! V_65 )
goto V_60;
memcpy ( V_115 , V_214 -> V_190 ,
V_214 -> V_191 ) ;
F_32 ( & V_214 -> V_192 ) ;
} else {
V_65 = - 1 ;
V_117 = F_67 ( V_214 ,
& V_207 ,
& V_115 ,
& V_65 ) ;
if ( ! V_65 )
goto V_100;
F_127 ( V_24 , V_24 -> V_9 . V_31 ,
V_115 , V_65 ,
F_126 ,
V_214 ) ;
}
V_65 = sizeof( struct V_69 ) + V_117 ;
if ( V_65 > F_49 ( & V_24 -> V_86 ) ) {
F_60 ( V_99 , V_24 -> V_79 ,
L_34 ,
V_215 -> V_159 ) ;
goto V_100;
}
V_207 -> V_50 = V_218 ;
V_207 -> V_120 = V_217 ;
if ( V_206 )
V_207 -> V_50 |= V_210 ;
F_54 ( V_77 , V_24 ,
L_35 ,
V_215 -> V_159 , V_214 -> V_159 ,
V_206 ? 'F' : '.' , V_217 ) ;
F_136 ( V_24 , V_219 ) ;
F_137 ( V_24 , V_214 -> V_159 ,
V_212 , V_133 , 1 , V_207 ,
V_117 ) ;
V_87 = true ;
goto V_100;
V_60:
F_32 ( & V_214 -> V_192 ) ;
V_100:
if ( V_215 )
F_140 ( V_215 ) ;
if ( V_214 )
F_140 ( V_214 ) ;
F_20 ( V_207 ) ;
return V_87 ;
}
static bool F_141 ( struct V_23 * V_24 ,
struct V_71 * V_114 ,
T_2 * V_212 )
{
struct V_71 * V_207 = NULL ;
struct V_139 * V_140 = NULL ;
struct V_64 * V_115 ;
struct V_41 * V_36 ;
T_2 V_220 , V_217 ;
T_3 V_117 ;
bool V_206 ;
T_4 V_65 ;
F_54 ( V_77 , V_24 ,
L_36 ,
V_212 , V_114 -> V_120 ,
( V_114 -> V_50 & V_210 ? 'F' : '.' ) ) ;
F_30 ( & V_24 -> V_9 . V_221 ) ;
V_220 = ( T_2 ) F_49 ( & V_24 -> V_9 . V_101 ) ;
V_217 = V_114 -> V_120 ;
V_36 = F_139 ( V_24 , V_212 ) ;
if ( ! V_36 )
goto V_100;
V_140 = F_135 ( V_24 ) ;
if ( ! V_140 )
goto V_100;
if ( V_114 -> V_50 & V_210 || V_220 != V_217 ||
! V_24 -> V_9 . V_131 )
V_206 = true ;
else
V_206 = false ;
if ( ! V_206 ) {
F_30 ( & V_24 -> V_9 . V_130 ) ;
V_65 = V_24 -> V_9 . V_132 ;
V_117 = F_70 ( V_24 ,
& V_207 ,
& V_115 ,
& V_65 ) ;
if ( ! V_65 )
goto V_60;
memcpy ( V_115 , V_24 -> V_9 . V_131 ,
V_24 -> V_9 . V_132 ) ;
F_32 ( & V_24 -> V_9 . V_130 ) ;
} else {
V_217 = ( T_2 ) F_49 ( & V_24 -> V_9 . V_101 ) ;
V_65 = - 1 ;
V_117 = F_70 ( V_24 ,
& V_207 ,
& V_115 ,
& V_65 ) ;
if ( ! V_65 )
goto V_100;
F_127 ( V_24 , V_24 -> V_9 . V_27 ,
V_115 , V_65 ,
F_125 , NULL ) ;
}
V_207 -> V_50 = V_218 ;
V_207 -> V_120 = V_217 ;
if ( V_206 )
V_207 -> V_50 |= V_210 ;
F_54 ( V_77 , V_24 ,
L_37 ,
V_36 -> V_159 , V_206 ? 'F' : '.' , V_217 ) ;
F_136 ( V_24 , V_219 ) ;
F_137 ( V_24 , V_140 -> V_137 -> V_105 ,
V_212 , V_133 , 1 , V_207 ,
V_117 ) ;
goto V_100;
V_60:
F_32 ( & V_24 -> V_9 . V_130 ) ;
V_100:
F_32 ( & V_24 -> V_9 . V_221 ) ;
if ( V_36 )
F_140 ( V_36 ) ;
if ( V_140 )
F_78 ( V_140 ) ;
F_20 ( V_207 ) ;
return true ;
}
static bool F_142 ( struct V_23 * V_24 ,
struct V_71 * V_114 ,
T_2 * V_212 , T_2 * V_213 )
{
if ( F_143 ( V_24 , V_213 ) )
return F_141 ( V_24 , V_114 , V_212 ) ;
else
return F_138 ( V_24 , V_114 ,
V_212 , V_213 ) ;
}
static void F_144 ( struct V_23 * V_24 ,
struct V_41 * V_36 ,
struct V_64 * V_115 ,
T_3 V_222 , T_2 V_120 )
{
int V_141 ;
int V_223 ;
for ( V_141 = 0 ; V_141 < V_222 ; V_141 ++ ) {
if ( ( V_115 + V_141 ) -> V_50 & V_57 ) {
V_223 = ( V_115 + V_141 ) -> V_50 & V_97 ;
F_107 ( V_24 , V_36 ,
( V_115 + V_141 ) -> V_11 ,
F_130 ( ( V_115 + V_141 ) -> V_13 ) ,
L_38 ,
V_223 ) ;
} else {
if ( ! F_95 ( V_24 , V_36 ,
( V_115 + V_141 ) -> V_11 ,
F_130 ( ( V_115 + V_141 ) -> V_13 ) ,
( V_115 + V_141 ) -> V_50 , V_120 ) )
return;
}
}
V_36 -> V_176 = true ;
}
static void F_145 ( struct V_23 * V_24 ,
struct V_64 * V_115 ,
T_2 V_120 , T_2 * V_224 ,
T_3 V_40 )
{
struct V_41 * V_36 ;
V_36 = F_139 ( V_24 , V_224 ) ;
if ( ! V_36 )
goto V_100;
F_109 ( V_24 , V_36 , - 1 ,
L_39 ) ;
F_144 ( V_24 , V_36 , V_115 , V_40 ,
V_120 ) ;
F_30 ( & V_36 -> V_192 ) ;
F_20 ( V_36 -> V_190 ) ;
V_36 -> V_191 = 0 ;
V_36 -> V_190 = NULL ;
F_32 ( & V_36 -> V_192 ) ;
F_62 ( & V_36 -> V_121 , V_120 ) ;
V_100:
if ( V_36 )
F_140 ( V_36 ) ;
}
static void F_146 ( struct V_23 * V_24 ,
struct V_41 * V_36 ,
T_3 V_222 , T_2 V_120 ,
struct V_64 * V_115 )
{
F_144 ( V_24 , V_36 , V_115 ,
V_222 , V_120 ) ;
F_120 ( V_24 , V_36 , V_115 ,
F_46 ( V_222 ) ) ;
F_62 ( & V_36 -> V_121 , V_120 ) ;
}
bool F_147 ( struct V_23 * V_24 , const T_2 * V_11 ,
unsigned short V_13 )
{
struct V_22 * V_26 ;
bool V_87 = false ;
V_26 = F_11 ( V_24 , V_11 , V_13 ) ;
if ( ! V_26 )
goto V_100;
if ( ( V_26 -> V_28 . V_50 & V_95 ) ||
( V_26 -> V_28 . V_50 & V_97 ) )
goto V_100;
V_87 = true ;
V_100:
if ( V_26 )
F_13 ( V_26 ) ;
return V_87 ;
}
static void F_148 ( struct V_23 * V_24 ,
struct V_71 * V_114 ,
T_2 * V_224 , T_3 V_40 )
{
struct V_188 * V_2 , * V_49 ;
struct V_41 * V_36 = NULL ;
struct V_64 * V_115 ;
T_2 * V_225 = ( T_2 * ) V_114 ;
T_3 V_116 ;
F_54 ( V_77 , V_24 ,
L_40 ,
V_224 , V_114 -> V_120 , V_40 ,
( V_114 -> V_50 & V_210 ? 'F' : '.' ) ) ;
V_36 = F_139 ( V_24 , V_224 ) ;
if ( ! V_36 )
goto V_100;
F_30 ( & V_36 -> V_226 ) ;
V_116 = sizeof( struct V_72 ) ;
V_116 *= F_130 ( V_114 -> V_66 ) ;
V_116 += sizeof( * V_114 ) ;
V_225 += V_116 ;
V_115 = (struct V_64 * ) V_225 ;
if ( V_114 -> V_50 & V_210 ) {
F_145 ( V_24 , V_115 , V_114 -> V_120 ,
V_224 , V_40 ) ;
} else {
F_146 ( V_24 , V_36 , V_40 ,
V_114 -> V_120 , V_115 ) ;
}
F_133 ( V_24 , V_36 ) ;
F_32 ( & V_36 -> V_226 ) ;
F_30 ( & V_24 -> V_9 . V_189 ) ;
F_41 (node, safe, &bat_priv->tt.req_list, list) {
if ( ! F_3 ( V_2 -> V_11 , V_224 ) )
continue;
F_42 ( & V_2 -> V_44 ) ;
F_20 ( V_2 ) ;
}
F_32 ( & V_24 -> V_9 . V_189 ) ;
V_100:
if ( V_36 )
F_140 ( V_36 ) ;
}
static void F_149 ( struct V_23 * V_24 )
{
struct V_227 * V_2 , * V_49 ;
F_30 ( & V_24 -> V_9 . V_228 ) ;
F_41 (node, safe, &bat_priv->tt.roam_list, list) {
F_42 ( & V_2 -> V_44 ) ;
F_20 ( V_2 ) ;
}
F_32 ( & V_24 -> V_9 . V_228 ) ;
}
static void F_150 ( struct V_23 * V_24 )
{
struct V_227 * V_2 , * V_49 ;
F_30 ( & V_24 -> V_9 . V_228 ) ;
F_41 (node, safe, &bat_priv->tt.roam_list, list) {
if ( ! F_84 ( V_2 -> V_229 ,
V_230 ) )
continue;
F_42 ( & V_2 -> V_44 ) ;
F_20 ( V_2 ) ;
}
F_32 ( & V_24 -> V_9 . V_228 ) ;
}
static bool F_151 ( struct V_23 * V_24 ,
T_2 * V_231 )
{
struct V_227 * V_232 ;
bool V_87 = false ;
F_30 ( & V_24 -> V_9 . V_228 ) ;
F_123 (tt_roam_node, &bat_priv->tt.roam_list, list) {
if ( ! F_3 ( V_232 -> V_11 , V_231 ) )
continue;
if ( F_84 ( V_232 -> V_229 ,
V_230 ) )
continue;
if ( ! F_152 ( & V_232 -> V_233 ) )
goto V_60;
V_87 = true ;
break;
}
if ( ! V_87 ) {
V_232 = F_39 ( sizeof( * V_232 ) , V_54 ) ;
if ( ! V_232 )
goto V_60;
V_232 -> V_229 = V_94 ;
F_62 ( & V_232 -> V_233 ,
V_234 - 1 ) ;
memcpy ( V_232 -> V_11 , V_231 , V_12 ) ;
F_124 ( & V_232 -> V_44 , & V_24 -> V_9 . V_235 ) ;
V_87 = true ;
}
V_60:
F_32 ( & V_24 -> V_9 . V_228 ) ;
return V_87 ;
}
static void F_65 ( struct V_23 * V_24 , T_2 * V_231 ,
unsigned short V_13 ,
struct V_41 * V_36 )
{
struct V_139 * V_140 ;
struct V_236 V_237 ;
V_140 = F_135 ( V_24 ) ;
if ( ! V_140 )
goto V_100;
if ( ! F_151 ( V_24 , V_231 ) )
goto V_100;
F_54 ( V_77 , V_24 ,
L_41 ,
V_36 -> V_159 , V_231 , F_55 ( V_13 ) ) ;
F_136 ( V_24 , V_238 ) ;
memcpy ( V_237 . V_231 , V_231 , sizeof( V_237 . V_231 ) ) ;
V_237 . V_13 = F_40 ( V_13 ) ;
F_137 ( V_24 , V_140 -> V_137 -> V_105 ,
V_36 -> V_159 , V_239 , 1 ,
& V_237 , sizeof( V_237 ) ) ;
V_100:
if ( V_140 )
F_78 ( V_140 ) ;
}
static void F_153 ( struct V_240 * V_241 )
{
struct V_242 * V_242 ;
struct V_243 * V_244 ;
struct V_23 * V_24 ;
V_242 = F_2 ( V_241 , struct V_242 , V_241 ) ;
V_244 = F_2 ( V_242 , struct V_243 , V_241 ) ;
V_24 = F_2 ( V_244 , struct V_23 , V_9 ) ;
F_85 ( V_24 , V_245 ) ;
F_111 ( V_24 ) ;
F_121 ( V_24 ) ;
F_150 ( V_24 ) ;
F_154 ( V_246 , & V_24 -> V_9 . V_241 ,
F_155 ( V_247 ) ) ;
}
void F_156 ( struct V_23 * V_24 )
{
F_157 ( V_24 , V_133 , 1 ) ;
F_158 ( V_24 , V_133 , 1 ) ;
F_159 ( & V_24 -> V_9 . V_241 ) ;
F_86 ( V_24 ) ;
F_112 ( V_24 ) ;
F_119 ( V_24 ) ;
F_89 ( V_24 ) ;
F_149 ( V_24 ) ;
F_20 ( V_24 -> V_9 . V_131 ) ;
}
static void F_160 ( struct V_23 * V_24 ,
T_3 V_50 , bool V_248 , bool V_249 )
{
struct V_14 * V_10 = V_24 -> V_9 . V_27 ;
struct V_5 * V_25 ;
T_3 V_250 = 0 ;
struct V_15 * V_16 ;
T_1 V_141 ;
if ( ! V_10 )
return;
for ( V_141 = 0 ; V_141 < V_10 -> V_8 ; V_141 ++ ) {
V_16 = & V_10 -> V_20 [ V_141 ] ;
F_7 () ;
F_8 (tt_common_entry,
head, hash_entry) {
if ( V_248 ) {
if ( ( V_25 -> V_50 & V_50 ) == V_50 )
continue;
V_25 -> V_50 |= V_50 ;
} else {
if ( ! ( V_25 -> V_50 & V_50 ) )
continue;
V_25 -> V_50 &= ~ V_50 ;
}
V_250 ++ ;
if ( ! V_249 )
continue;
F_25 ( V_24 ,
V_25 -> V_13 ) ;
}
F_10 () ;
}
}
static void F_161 ( struct V_23 * V_24 )
{
struct V_14 * V_10 = V_24 -> V_9 . V_27 ;
struct V_5 * V_183 ;
struct V_22 * V_82 ;
struct V_1 * V_151 ;
struct V_15 * V_16 ;
T_5 * V_152 ;
T_1 V_141 ;
if ( ! V_10 )
return;
for ( V_141 = 0 ; V_141 < V_10 -> V_8 ; V_141 ++ ) {
V_16 = & V_10 -> V_20 [ V_141 ] ;
V_152 = & V_10 -> V_153 [ V_141 ] ;
F_30 ( V_152 ) ;
F_83 (tt_common, node_tmp, head,
hash_entry) {
if ( ! ( V_183 -> V_50 & V_95 ) )
continue;
F_54 ( V_77 , V_24 ,
L_42 ,
V_183 -> V_11 ,
F_55 ( V_183 -> V_13 ) ) ;
F_26 ( V_24 , V_183 -> V_13 ) ;
F_81 ( & V_183 -> V_6 ) ;
V_82 = F_2 ( V_183 ,
struct V_22 ,
V_28 ) ;
F_13 ( V_82 ) ;
}
F_32 ( V_152 ) ;
}
}
static void F_162 ( struct V_23 * V_24 )
{
if ( F_49 ( & V_24 -> V_9 . V_62 ) < 1 ) {
if ( ! F_152 ( & V_24 -> V_9 . V_251 ) )
F_71 ( V_24 ) ;
return;
}
F_160 ( V_24 , V_102 , false , true ) ;
F_161 ( V_24 ) ;
F_132 ( V_24 ) ;
F_45 ( & V_24 -> V_9 . V_101 ) ;
F_54 ( V_77 , V_24 ,
L_43 ,
( T_2 ) F_49 ( & V_24 -> V_9 . V_101 ) ) ;
F_62 ( & V_24 -> V_9 . V_251 , V_252 ) ;
F_71 ( V_24 ) ;
}
void F_163 ( struct V_23 * V_24 )
{
F_30 ( & V_24 -> V_9 . V_221 ) ;
F_162 ( V_24 ) ;
F_32 ( & V_24 -> V_9 . V_221 ) ;
}
bool F_164 ( struct V_23 * V_24 , T_2 * V_184 ,
T_2 * V_253 , unsigned short V_13 )
{
struct V_22 * V_26 = NULL ;
struct V_29 * V_30 = NULL ;
struct V_38 * V_39 ;
bool V_87 = false ;
V_39 = F_22 ( V_24 , V_13 ) ;
if ( ! V_39 || ! F_49 ( & V_39 -> V_254 ) )
goto V_100;
V_26 = F_11 ( V_24 , V_253 , V_13 ) ;
if ( ! V_26 )
goto V_100;
V_30 = F_12 ( V_24 , V_184 , V_13 ) ;
if ( ! V_30 )
goto V_100;
if ( ! F_113 ( V_26 , V_30 ) )
goto V_100;
V_87 = true ;
V_100:
if ( V_39 )
F_24 ( V_39 ) ;
if ( V_30 )
F_16 ( V_30 ) ;
if ( V_26 )
F_13 ( V_26 ) ;
return V_87 ;
}
static void F_165 ( struct V_23 * V_24 ,
struct V_41 * V_36 ,
const void * V_190 , T_3 V_255 ,
struct V_64 * V_115 ,
T_3 V_222 , T_2 V_120 )
{
T_2 V_216 = ( T_2 ) F_49 ( & V_36 -> V_121 ) ;
struct V_72 * V_118 ;
bool V_206 = true ;
V_118 = (struct V_72 * ) V_190 ;
if ( ( ! V_36 -> V_176 && V_120 == 1 ) ||
V_120 - V_216 == 1 ) {
if ( ! V_222 ) {
V_206 = false ;
goto V_256;
}
F_30 ( & V_36 -> V_226 ) ;
F_146 ( V_24 , V_36 , V_222 ,
V_120 , V_115 ) ;
F_133 ( V_24 , V_36 ) ;
F_32 ( & V_36 -> V_226 ) ;
if ( ! F_129 ( V_36 , V_118 ,
V_255 ) )
goto V_256;
} else {
if ( ! V_36 -> V_176 || V_120 != V_216 ||
! F_129 ( V_36 , V_118 ,
V_255 ) ) {
V_256:
F_54 ( V_77 , V_24 ,
L_44 ,
V_36 -> V_159 , V_120 , V_216 ,
V_222 ) ;
F_134 ( V_24 , V_36 , V_120 ,
V_118 , V_255 ,
V_206 ) ;
return;
}
}
}
bool F_166 ( struct V_23 * V_24 ,
T_2 * V_11 , unsigned short V_13 )
{
struct V_29 * V_30 ;
bool V_87 = false ;
V_30 = F_12 ( V_24 , V_11 , V_13 ) ;
if ( ! V_30 )
goto V_100;
V_87 = V_30 -> V_28 . V_50 & V_97 ;
F_16 ( V_30 ) ;
V_100:
return V_87 ;
}
bool F_167 ( struct V_23 * V_24 ,
T_2 * V_11 , unsigned short V_13 )
{
struct V_22 * V_26 ;
bool V_87 = false ;
V_26 = F_11 ( V_24 , V_11 , V_13 ) ;
if ( ! V_26 )
goto V_100;
V_87 = V_26 -> V_28 . V_50 & V_97 ;
F_13 ( V_26 ) ;
V_100:
return V_87 ;
}
bool F_168 ( struct V_23 * V_24 ,
struct V_41 * V_36 ,
const unsigned char * V_11 ,
unsigned short V_13 )
{
bool V_87 = false ;
if ( ! F_95 ( V_24 , V_36 , V_11 , V_13 ,
V_160 ,
F_49 ( & V_36 -> V_121 ) ) )
goto V_100;
F_54 ( V_77 , V_24 ,
L_45 ,
V_11 , F_55 ( V_13 ) , V_36 -> V_159 ) ;
V_87 = true ;
V_100:
return V_87 ;
}
void F_169 ( struct V_78 * V_79 )
{
struct V_23 * V_24 = F_58 ( V_79 ) ;
int V_86 = F_49 ( & V_24 -> V_86 ) ;
int V_85 , V_150 = V_245 / 2 ;
bool V_257 = false ;
F_30 ( & V_24 -> V_9 . V_221 ) ;
while ( true ) {
V_85 = F_48 ( V_24 ) ;
if ( V_86 >= V_85 )
break;
F_85 ( V_24 , V_150 ) ;
F_161 ( V_24 ) ;
V_150 /= 2 ;
V_257 = true ;
F_60 ( V_99 , V_79 ,
L_46 ,
V_86 ) ;
}
if ( V_257 )
F_162 ( V_24 ) ;
F_32 ( & V_24 -> V_9 . V_221 ) ;
}
static void F_170 ( struct V_23 * V_24 ,
struct V_41 * V_159 ,
T_2 V_50 , void * V_258 ,
T_3 V_259 )
{
struct V_72 * V_118 ;
struct V_64 * V_115 ;
struct V_71 * V_114 ;
T_3 V_40 , V_66 ;
if ( V_259 < sizeof( * V_114 ) )
return;
V_114 = (struct V_71 * ) V_258 ;
V_259 -= sizeof( * V_114 ) ;
V_66 = F_130 ( V_114 -> V_66 ) ;
if ( V_259 < sizeof( * V_118 ) * V_66 )
return;
V_118 = (struct V_72 * ) ( V_114 + 1 ) ;
V_115 = (struct V_64 * ) ( V_118 + V_66 ) ;
V_259 -= sizeof( * V_118 ) * V_66 ;
V_40 = F_47 ( V_259 ) ;
F_165 ( V_24 , V_159 , V_118 , V_66 , V_115 ,
V_40 , V_114 -> V_120 ) ;
}
static int F_171 ( struct V_23 * V_24 ,
T_2 * V_184 , T_2 * V_253 ,
void * V_258 ,
T_3 V_259 )
{
struct V_71 * V_114 ;
T_3 V_260 , V_203 ;
char V_261 ;
bool V_87 ;
if ( V_259 < sizeof( * V_114 ) )
return V_262 ;
V_114 = (struct V_71 * ) V_258 ;
V_259 -= sizeof( * V_114 ) ;
V_260 = sizeof( struct V_72 ) ;
V_260 *= F_130 ( V_114 -> V_66 ) ;
if ( V_259 < V_260 )
return V_262 ;
V_259 -= V_260 ;
V_203 = F_47 ( V_259 ) ;
switch ( V_114 -> V_50 & V_263 ) {
case V_209 :
F_136 ( V_24 , V_264 ) ;
V_87 = F_142 ( V_24 , V_114 , V_184 , V_253 ) ;
if ( ! V_87 ) {
if ( V_114 -> V_50 & V_210 )
V_261 = 'F' ;
else
V_261 = '.' ;
F_54 ( V_77 , V_24 ,
L_47 ,
V_253 , V_261 ) ;
return V_265 ;
}
break;
case V_218 :
F_136 ( V_24 , V_266 ) ;
if ( F_143 ( V_24 , V_253 ) ) {
F_148 ( V_24 , V_114 ,
V_184 , V_203 ) ;
return V_262 ;
}
if ( V_114 -> V_50 & V_210 )
V_261 = 'F' ;
else
V_261 = '.' ;
F_54 ( V_77 , V_24 ,
L_48 , V_253 , V_261 ) ;
return V_265 ;
}
return V_262 ;
}
static int F_172 ( struct V_23 * V_24 ,
T_2 * V_184 , T_2 * V_253 ,
void * V_258 ,
T_3 V_259 )
{
struct V_236 * V_267 ;
struct V_41 * V_36 = NULL ;
if ( ! F_143 ( V_24 , V_253 ) )
return V_265 ;
if ( V_259 < sizeof( * V_267 ) )
goto V_100;
V_36 = F_139 ( V_24 , V_184 ) ;
if ( ! V_36 )
goto V_100;
F_136 ( V_24 , V_268 ) ;
V_267 = (struct V_236 * ) V_258 ;
F_54 ( V_77 , V_24 ,
L_49 ,
V_184 , V_267 -> V_231 ) ;
F_95 ( V_24 , V_36 , V_267 -> V_231 ,
F_130 ( V_267 -> V_13 ) , V_97 ,
F_49 ( & V_36 -> V_121 ) + 1 ) ;
V_100:
if ( V_36 )
F_140 ( V_36 ) ;
return V_262 ;
}
int F_173 ( struct V_23 * V_24 )
{
int V_87 ;
F_174 ( ! ( V_187 & V_110 ) ) ;
V_87 = F_50 ( V_24 ) ;
if ( V_87 < 0 )
return V_87 ;
V_87 = F_88 ( V_24 ) ;
if ( V_87 < 0 )
return V_87 ;
F_175 ( V_24 , F_170 ,
F_171 ,
V_133 , 1 , V_107 ) ;
F_175 ( V_24 , NULL ,
F_172 ,
V_239 , 1 , V_107 ) ;
F_176 ( & V_24 -> V_9 . V_241 , F_153 ) ;
F_154 ( V_246 , & V_24 -> V_9 . V_241 ,
F_155 ( V_247 ) ) ;
return 1 ;
}
bool F_177 ( struct V_23 * V_24 ,
const T_2 * V_11 , unsigned short V_13 )
{
struct V_29 * V_9 ;
bool V_87 ;
V_9 = F_12 ( V_24 , V_11 , V_13 ) ;
if ( ! V_9 )
return false ;
V_87 = V_9 -> V_28 . V_50 & V_113 ;
F_16 ( V_9 ) ;
return V_87 ;
}

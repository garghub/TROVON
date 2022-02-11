static int F_1 ( const struct V_1 * V_2 , const void * V_3 )
{
const void * V_4 = F_2 ( V_2 , struct V_5 ,
V_6 ) ;
return ( memcmp ( V_4 , V_3 , V_7 ) == 0 ? 1 : 0 ) ;
}
static inline T_1 F_3 ( const void * V_8 , T_1 V_9 )
{
struct V_5 * V_10 ;
T_1 V_11 = 0 ;
V_10 = (struct V_5 * ) V_8 ;
V_11 = F_4 ( V_11 , & V_10 -> V_12 , V_7 ) ;
V_11 = F_4 ( V_11 , & V_10 -> V_13 , sizeof( V_10 -> V_13 ) ) ;
V_11 += ( V_11 << 3 ) ;
V_11 ^= ( V_11 >> 11 ) ;
V_11 += ( V_11 << 15 ) ;
return V_11 % V_9 ;
}
static struct V_5 *
F_5 ( struct V_14 * V_11 , const T_2 * V_12 ,
unsigned short V_13 )
{
struct V_15 * V_16 ;
struct V_5 V_17 , * V_10 , * V_18 = NULL ;
T_1 V_19 ;
if ( ! V_11 )
return NULL ;
memcpy ( V_17 . V_12 , V_12 , V_7 ) ;
V_17 . V_13 = V_13 ;
V_19 = F_3 ( & V_17 , V_11 -> V_9 ) ;
V_16 = & V_11 -> V_20 [ V_19 ] ;
F_6 () ;
F_7 (tt, head, hash_entry) {
if ( ! F_8 ( V_10 , V_12 ) )
continue;
if ( V_10 -> V_13 != V_13 )
continue;
if ( ! F_9 ( & V_10 -> V_21 ) )
continue;
V_18 = V_10 ;
break;
}
F_10 () ;
return V_18 ;
}
static struct V_22 *
F_11 ( struct V_23 * V_24 , const T_2 * V_12 ,
unsigned short V_13 )
{
struct V_5 * V_25 ;
struct V_22 * V_26 = NULL ;
V_25 = F_5 ( V_24 -> V_10 . V_27 , V_12 ,
V_13 ) ;
if ( V_25 )
V_26 = F_2 ( V_25 ,
struct V_22 ,
V_28 ) ;
return V_26 ;
}
static struct V_29 *
F_12 ( struct V_23 * V_24 , const T_2 * V_12 ,
unsigned short V_13 )
{
struct V_5 * V_25 ;
struct V_29 * V_30 = NULL ;
V_25 = F_5 ( V_24 -> V_10 . V_31 , V_12 ,
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
F_23 ( V_37 , & V_39 -> V_10 . V_40 ) ;
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
if ( F_29 ( V_37 , & V_39 -> V_10 . V_40 ) == 0 ) {
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
memcpy ( V_47 -> V_55 . V_12 , V_28 -> V_12 , V_7 ) ;
V_47 -> V_55 . V_13 = F_40 ( V_28 -> V_13 ) ;
V_52 = V_50 & V_57 ;
F_30 ( & V_24 -> V_10 . V_58 ) ;
F_41 (entry, safe, &bat_priv->tt.changes_list,
list) {
if ( ! F_8 ( V_48 -> V_55 . V_12 , V_28 -> V_12 ) )
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
F_43 ( & V_47 -> V_44 , & V_24 -> V_10 . V_61 ) ;
V_60:
F_32 ( & V_24 -> V_10 . V_58 ) ;
if ( V_51 )
F_44 ( & V_24 -> V_10 . V_62 ) ;
else
F_45 ( & V_24 -> V_10 . V_62 ) ;
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
F_6 () ;
F_7 (vlan, &bat_priv->softif_vlan_list, list) {
V_66 ++ ;
V_67 += F_49 ( & V_39 -> V_10 . V_40 ) ;
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
if ( V_24 -> V_10 . V_27 )
return 0 ;
V_24 -> V_10 . V_27 = F_51 ( 1024 ) ;
if ( ! V_24 -> V_10 . V_27 )
return - V_73 ;
F_52 ( V_24 -> V_10 . V_27 ,
& V_74 ) ;
return 0 ;
}
static void F_53 ( struct V_23 * V_24 ,
struct V_29 * V_75 ,
const char * V_76 )
{
F_54 ( V_77 , V_24 ,
L_1 ,
V_75 -> V_28 . V_12 ,
F_55 ( V_75 -> V_28 . V_13 ) , V_76 ) ;
F_56 ( V_24 -> V_10 . V_31 , F_1 ,
F_3 , & V_75 -> V_28 ) ;
F_16 ( V_75 ) ;
}
bool F_57 ( struct V_78 * V_79 , const T_2 * V_12 ,
unsigned short V_13 , int V_80 )
{
struct V_23 * V_24 = F_58 ( V_79 ) ;
struct V_22 * V_81 ;
struct V_29 * V_75 ;
struct V_78 * V_82 = NULL ;
struct V_15 * V_16 ;
struct V_34 * V_35 ;
int V_83 , V_84 , V_85 ;
bool V_86 = false , V_87 = false ;
T_2 V_88 ;
if ( V_80 != V_89 )
V_82 = F_59 ( & V_90 , V_80 ) ;
V_81 = F_11 ( V_24 , V_12 , V_13 ) ;
V_75 = F_12 ( V_24 , V_12 , V_13 ) ;
if ( V_81 ) {
V_81 -> V_91 = V_92 ;
if ( V_81 -> V_28 . V_50 & V_93 ) {
F_54 ( V_77 , V_24 ,
L_2 ,
V_12 , F_55 ( V_13 ) ) ;
V_81 -> V_28 . V_50 &= ~ V_93 ;
goto V_94;
}
if ( V_81 -> V_28 . V_50 & V_95 ) {
F_54 ( V_77 , V_24 ,
L_3 ,
V_12 , F_55 ( V_13 ) ) ;
V_81 -> V_28 . V_50 &= ~ V_95 ;
V_87 = true ;
}
goto V_96;
}
V_84 = F_48 ( V_24 ) ;
V_84 += F_46 ( 1 ) ;
V_85 = F_49 ( & V_24 -> V_85 ) ;
if ( V_84 > V_85 ) {
F_60 ( V_97 , V_79 ,
L_4 ,
V_84 , V_85 , V_12 ) ;
goto V_98;
}
V_81 = F_39 ( sizeof( * V_81 ) , V_54 ) ;
if ( ! V_81 )
goto V_98;
F_54 ( V_77 , V_24 ,
L_5 ,
V_12 , F_55 ( V_13 ) ,
( T_2 ) F_49 ( & V_24 -> V_10 . V_99 ) ) ;
memcpy ( V_81 -> V_28 . V_12 , V_12 , V_7 ) ;
V_81 -> V_28 . V_50 = V_100 ;
V_81 -> V_28 . V_13 = V_13 ;
if ( F_61 ( V_82 ) )
V_81 -> V_28 . V_50 |= V_101 ;
F_62 ( & V_81 -> V_28 . V_21 , 2 ) ;
V_81 -> V_91 = V_92 ;
V_81 -> V_28 . V_102 = V_81 -> V_91 ;
if ( F_8 ( V_12 , V_79 -> V_103 ) )
V_81 -> V_28 . V_50 |= V_104 ;
V_83 = F_63 ( V_24 -> V_10 . V_27 , F_1 ,
F_3 , & V_81 -> V_28 ,
& V_81 -> V_28 . V_6 ) ;
if ( F_64 ( V_83 != 0 ) ) {
F_13 ( V_81 ) ;
goto V_98;
}
V_94:
F_38 ( V_24 , V_81 , V_105 ) ;
V_96:
if ( V_75 && ! ( V_75 -> V_28 . V_50 & V_95 ) ) {
V_16 = & V_75 -> V_106 ;
F_6 () ;
F_7 (orig_entry, head, list) {
F_65 ( V_24 , V_75 -> V_28 . V_12 ,
V_75 -> V_28 . V_13 ,
V_35 -> V_36 ) ;
}
F_10 () ;
if ( V_87 ) {
F_53 ( V_24 , V_75 ,
L_6 ) ;
V_75 = NULL ;
} else {
V_75 -> V_28 . V_50 |= V_95 ;
V_75 -> V_107 = V_92 ;
}
}
V_88 = V_81 -> V_28 . V_50 & V_108 ;
if ( F_61 ( V_82 ) )
V_81 -> V_28 . V_50 |= V_101 ;
else
V_81 -> V_28 . V_50 &= ~ V_101 ;
if ( V_88 ^ ( V_81 -> V_28 . V_50 & V_108 ) )
F_38 ( V_24 , V_81 , V_105 ) ;
V_86 = true ;
V_98:
if ( V_82 )
F_66 ( V_82 ) ;
if ( V_81 )
F_13 ( V_81 ) ;
if ( V_75 )
F_16 ( V_75 ) ;
return V_86 ;
}
static T_3
F_67 ( struct V_41 * V_36 ,
struct V_71 * * V_109 ,
struct V_64 * * V_110 ,
T_4 * V_65 )
{
T_3 V_66 = 0 , V_40 = 0 , V_111 , V_112 ;
struct V_72 * V_113 ;
struct V_42 * V_39 ;
T_2 * V_114 ;
F_6 () ;
F_68 (vlan, &orig_node->vlan_list, list) {
V_66 ++ ;
V_40 += F_49 ( & V_39 -> V_10 . V_40 ) ;
}
V_111 = sizeof( * * V_109 ) ;
V_111 += V_66 * sizeof( * V_113 ) ;
if ( * V_65 < 0 )
* V_65 = F_46 ( V_40 ) ;
V_112 = * V_65 ;
V_112 += V_111 ;
* V_109 = F_39 ( V_112 , V_54 ) ;
if ( ! * V_109 ) {
* V_65 = 0 ;
goto V_98;
}
( * V_109 ) -> V_50 = V_105 ;
( * V_109 ) -> V_115 = F_49 ( & V_36 -> V_116 ) ;
( * V_109 ) -> V_66 = F_40 ( V_66 ) ;
V_113 = (struct V_72 * ) ( * V_109 + 1 ) ;
F_68 (vlan, &orig_node->vlan_list, list) {
V_113 -> V_13 = F_40 ( V_39 -> V_13 ) ;
V_113 -> V_117 = F_69 ( V_39 -> V_10 . V_117 ) ;
V_113 ++ ;
}
V_114 = ( T_2 * ) * V_109 + V_111 ;
* V_110 = (struct V_64 * ) V_114 ;
V_98:
F_10 () ;
return V_112 ;
}
static T_3
F_70 ( struct V_23 * V_24 ,
struct V_71 * * V_109 ,
struct V_64 * * V_110 ,
T_4 * V_65 )
{
struct V_72 * V_113 ;
struct V_38 * V_39 ;
T_3 V_66 = 0 , V_40 = 0 , V_112 ;
T_2 * V_114 ;
int V_111 ;
F_6 () ;
F_7 (vlan, &bat_priv->softif_vlan_list, list) {
V_66 ++ ;
V_40 += F_49 ( & V_39 -> V_10 . V_40 ) ;
}
V_111 = sizeof( * * V_109 ) ;
V_111 += V_66 * sizeof( * V_113 ) ;
if ( * V_65 < 0 )
* V_65 = F_46 ( V_40 ) ;
V_112 = * V_65 ;
V_112 += V_111 ;
* V_109 = F_39 ( V_112 , V_54 ) ;
if ( ! * V_109 ) {
V_112 = 0 ;
goto V_98;
}
( * V_109 ) -> V_50 = V_105 ;
( * V_109 ) -> V_115 = F_49 ( & V_24 -> V_10 . V_99 ) ;
( * V_109 ) -> V_66 = F_40 ( V_66 ) ;
V_113 = (struct V_72 * ) ( * V_109 + 1 ) ;
F_7 (vlan, &bat_priv->softif_vlan_list, list) {
V_113 -> V_13 = F_40 ( V_39 -> V_13 ) ;
V_113 -> V_117 = F_69 ( V_39 -> V_10 . V_117 ) ;
V_113 ++ ;
}
V_114 = ( T_2 * ) * V_109 + V_111 ;
* V_110 = (struct V_64 * ) V_114 ;
V_98:
F_10 () ;
return V_112 ;
}
static void F_71 ( struct V_23 * V_24 )
{
struct V_46 * V_48 , * V_49 ;
struct V_71 * V_109 ;
struct V_64 * V_110 ;
int V_118 , V_119 = 0 ;
int V_120 = 0 , V_121 = 0 ;
T_3 V_112 ;
V_120 = F_49 ( & V_24 -> V_10 . V_62 ) ;
V_118 = F_46 ( V_120 ) ;
if ( V_118 > V_24 -> V_79 -> V_122 )
V_118 = 0 ;
V_112 = F_70 ( V_24 , & V_109 ,
& V_110 , & V_118 ) ;
if ( ! V_112 )
return;
V_109 -> V_50 = V_123 ;
if ( V_118 == 0 )
goto V_124;
F_30 ( & V_24 -> V_10 . V_58 ) ;
F_62 ( & V_24 -> V_10 . V_62 , 0 ) ;
F_41 (entry, safe, &bat_priv->tt.changes_list,
list) {
if ( V_121 < V_120 ) {
memcpy ( V_110 + V_121 ,
& V_48 -> V_55 ,
sizeof( struct V_64 ) ) ;
V_121 ++ ;
}
F_42 ( & V_48 -> V_44 ) ;
F_20 ( V_48 ) ;
}
F_32 ( & V_24 -> V_10 . V_58 ) ;
F_30 ( & V_24 -> V_10 . V_125 ) ;
F_20 ( V_24 -> V_10 . V_126 ) ;
V_24 -> V_10 . V_127 = 0 ;
V_24 -> V_10 . V_126 = NULL ;
V_119 = F_46 ( V_121 ) ;
if ( V_121 > 0 ) {
V_24 -> V_10 . V_126 = F_72 ( V_118 , V_54 ) ;
if ( V_24 -> V_10 . V_126 ) {
memcpy ( V_24 -> V_10 . V_126 ,
V_110 , V_119 ) ;
V_24 -> V_10 . V_127 = V_118 ;
}
}
F_32 ( & V_24 -> V_10 . V_125 ) ;
V_124:
F_73 ( V_24 , V_128 , 1 , V_109 ,
V_112 ) ;
F_20 ( V_109 ) ;
}
int F_74 ( struct V_129 * V_130 , void * V_131 )
{
struct V_78 * V_132 = (struct V_78 * ) V_130 -> V_133 ;
struct V_23 * V_24 = F_58 ( V_132 ) ;
struct V_14 * V_11 = V_24 -> V_10 . V_27 ;
struct V_5 * V_25 ;
struct V_22 * V_81 ;
struct V_134 * V_135 ;
struct V_38 * V_39 ;
struct V_15 * V_16 ;
unsigned short V_13 ;
T_1 V_136 ;
int V_137 ;
int V_138 ;
unsigned long V_139 ;
bool V_140 ;
T_3 V_141 = V_104 ;
V_135 = F_75 ( V_130 ) ;
if ( ! V_135 )
goto V_98;
F_76 ( V_130 ,
L_7 ,
V_132 -> V_142 , ( T_2 ) F_49 ( & V_24 -> V_10 . V_99 ) ) ;
F_76 ( V_130 , L_8 , L_9 , L_10 ,
L_11 , L_12 , L_13 ) ;
for ( V_136 = 0 ; V_136 < V_11 -> V_9 ; V_136 ++ ) {
V_16 = & V_11 -> V_20 [ V_136 ] ;
F_6 () ;
F_7 (tt_common_entry,
head, hash_entry) {
V_81 = F_2 ( V_25 ,
struct V_22 ,
V_28 ) ;
V_13 = V_25 -> V_13 ;
V_139 = V_92 - V_81 -> V_91 ;
V_138 = F_77 ( V_139 ) ;
V_137 = V_138 / 1000 ;
V_138 = V_138 % 1000 ;
V_140 = V_25 -> V_50 & V_141 ;
V_39 = F_22 ( V_24 , V_13 ) ;
if ( ! V_39 ) {
F_76 ( V_130 , L_14 ,
F_55 ( V_13 ) ) ;
continue;
}
F_76 ( V_130 ,
L_15 ,
V_25 -> V_12 ,
F_55 ( V_25 -> V_13 ) ,
( V_25 -> V_50 &
V_95 ? 'R' : '.' ) ,
V_140 ? 'P' : '.' ,
( V_25 -> V_50 &
V_100 ? 'N' : '.' ) ,
( V_25 -> V_50 &
V_93 ? 'X' : '.' ) ,
( V_25 -> V_50 &
V_101 ? 'W' : '.' ) ,
V_140 ? 0 : V_137 ,
V_140 ? 0 : V_138 ,
V_39 -> V_10 . V_117 ) ;
F_24 ( V_39 ) ;
}
F_10 () ;
}
V_98:
if ( V_135 )
F_78 ( V_135 ) ;
return 0 ;
}
static void
F_79 ( struct V_23 * V_24 ,
struct V_22 * V_26 ,
T_3 V_50 , const char * V_76 )
{
F_38 ( V_24 , V_26 , V_50 ) ;
V_26 -> V_28 . V_50 |= V_93 ;
F_54 ( V_77 , V_24 ,
L_16 ,
V_26 -> V_28 . V_12 ,
F_55 ( V_26 -> V_28 . V_13 ) , V_76 ) ;
}
T_3 F_80 ( struct V_23 * V_24 ,
const T_2 * V_12 , unsigned short V_13 ,
const char * V_76 , bool V_143 )
{
struct V_22 * V_26 ;
T_3 V_50 , V_144 = V_105 ;
V_26 = F_11 ( V_24 , V_12 , V_13 ) ;
if ( ! V_26 )
goto V_98;
V_144 = V_26 -> V_28 . V_50 ;
V_50 = V_57 ;
if ( V_143 ) {
V_50 |= V_95 ;
V_26 -> V_28 . V_50 |= V_95 ;
}
if ( ! ( V_26 -> V_28 . V_50 & V_100 ) ) {
F_79 ( V_24 , V_26 , V_50 ,
V_76 ) ;
goto V_98;
}
F_38 ( V_24 , V_26 , V_57 ) ;
F_81 ( & V_26 -> V_28 . V_6 ) ;
F_13 ( V_26 ) ;
V_98:
if ( V_26 )
F_13 ( V_26 ) ;
return V_144 ;
}
static void F_82 ( struct V_23 * V_24 ,
struct V_15 * V_16 ,
int V_145 )
{
struct V_22 * V_26 ;
struct V_5 * V_25 ;
struct V_1 * V_146 ;
F_83 (tt_common_entry, node_tmp, head,
hash_entry) {
V_26 = F_2 ( V_25 ,
struct V_22 ,
V_28 ) ;
if ( V_26 -> V_28 . V_50 & V_104 )
continue;
if ( V_26 -> V_28 . V_50 & V_93 )
continue;
if ( ! F_84 ( V_26 -> V_91 , V_145 ) )
continue;
F_79 ( V_24 , V_26 ,
V_57 , L_17 ) ;
}
}
static void F_85 ( struct V_23 * V_24 ,
int V_145 )
{
struct V_14 * V_11 = V_24 -> V_10 . V_27 ;
struct V_15 * V_16 ;
T_5 * V_147 ;
T_1 V_136 ;
for ( V_136 = 0 ; V_136 < V_11 -> V_9 ; V_136 ++ ) {
V_16 = & V_11 -> V_20 [ V_136 ] ;
V_147 = & V_11 -> V_148 [ V_136 ] ;
F_30 ( V_147 ) ;
F_82 ( V_24 , V_16 , V_145 ) ;
F_32 ( V_147 ) ;
}
}
static void F_86 ( struct V_23 * V_24 )
{
struct V_14 * V_11 ;
T_5 * V_147 ;
struct V_5 * V_25 ;
struct V_22 * V_81 ;
struct V_1 * V_146 ;
struct V_15 * V_16 ;
T_1 V_136 ;
if ( ! V_24 -> V_10 . V_27 )
return;
V_11 = V_24 -> V_10 . V_27 ;
for ( V_136 = 0 ; V_136 < V_11 -> V_9 ; V_136 ++ ) {
V_16 = & V_11 -> V_20 [ V_136 ] ;
V_147 = & V_11 -> V_148 [ V_136 ] ;
F_30 ( V_147 ) ;
F_83 (tt_common_entry, node_tmp,
head, hash_entry) {
F_81 ( & V_25 -> V_6 ) ;
V_81 = F_2 ( V_25 ,
struct V_22 ,
V_28 ) ;
F_13 ( V_81 ) ;
}
F_32 ( V_147 ) ;
}
F_87 ( V_11 ) ;
V_24 -> V_10 . V_27 = NULL ;
}
static int F_88 ( struct V_23 * V_24 )
{
if ( V_24 -> V_10 . V_31 )
return 0 ;
V_24 -> V_10 . V_31 = F_51 ( 1024 ) ;
if ( ! V_24 -> V_10 . V_31 )
return - V_73 ;
F_52 ( V_24 -> V_10 . V_31 ,
& V_149 ) ;
return 0 ;
}
static void F_89 ( struct V_23 * V_24 )
{
struct V_46 * V_48 , * V_49 ;
F_30 ( & V_24 -> V_10 . V_58 ) ;
F_41 (entry, safe, &bat_priv->tt.changes_list,
list) {
F_42 ( & V_48 -> V_44 ) ;
F_20 ( V_48 ) ;
}
F_62 ( & V_24 -> V_10 . V_62 , 0 ) ;
F_32 ( & V_24 -> V_10 . V_58 ) ;
}
static struct V_34 *
F_90 ( const struct V_29 * V_48 ,
const struct V_41 * V_36 )
{
struct V_34 * V_150 , * V_35 = NULL ;
const struct V_15 * V_16 ;
F_6 () ;
V_16 = & V_48 -> V_106 ;
F_7 (tmp_orig_entry, head, list) {
if ( V_150 -> V_36 != V_36 )
continue;
if ( ! F_9 ( & V_150 -> V_21 ) )
continue;
V_35 = V_150 ;
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
bool V_151 = false ;
V_35 = F_90 ( V_48 , V_36 ) ;
if ( V_35 ) {
V_151 = true ;
F_36 ( V_35 ) ;
}
return V_151 ;
}
static void
F_92 ( struct V_29 * V_75 ,
struct V_41 * V_36 , int V_115 )
{
struct V_34 * V_35 ;
V_35 = F_90 ( V_75 , V_36 ) ;
if ( V_35 ) {
V_35 -> V_115 = V_115 ;
goto V_98;
}
V_35 = F_72 ( sizeof( * V_35 ) , V_54 ) ;
if ( ! V_35 )
goto V_98;
F_93 ( & V_35 -> V_44 ) ;
F_45 ( & V_36 -> V_21 ) ;
F_34 ( V_36 , V_75 -> V_28 . V_13 ) ;
V_35 -> V_36 = V_36 ;
V_35 -> V_115 = V_115 ;
F_62 ( & V_35 -> V_21 , 2 ) ;
F_30 ( & V_75 -> V_147 ) ;
F_94 ( & V_35 -> V_44 ,
& V_75 -> V_106 ) ;
F_32 ( & V_75 -> V_147 ) ;
V_98:
if ( V_35 )
F_36 ( V_35 ) ;
}
static bool F_95 ( struct V_23 * V_24 ,
struct V_41 * V_36 ,
const unsigned char * V_152 ,
unsigned short V_13 , T_3 V_50 ,
T_2 V_115 )
{
struct V_29 * V_30 ;
struct V_22 * V_26 ;
bool V_86 = false ;
int V_83 ;
struct V_5 * V_28 ;
T_3 V_153 ;
if ( F_96 ( V_24 , V_36 -> V_154 , V_13 ) )
return true ;
V_30 = F_12 ( V_24 , V_152 , V_13 ) ;
V_26 = F_11 ( V_24 , V_152 , V_13 ) ;
if ( ( V_50 & V_155 ) && V_26 &&
! ( V_26 -> V_28 . V_50 & V_100 ) )
goto V_98;
if ( ! V_30 ) {
V_30 = F_72 ( sizeof( * V_30 ) , V_54 ) ;
if ( ! V_30 )
goto V_98;
V_28 = & V_30 -> V_28 ;
memcpy ( V_28 -> V_12 , V_152 , V_7 ) ;
V_28 -> V_13 = V_13 ;
V_28 -> V_50 = V_50 ;
V_30 -> V_107 = 0 ;
if ( V_50 & V_95 )
V_30 -> V_107 = V_92 ;
F_62 ( & V_28 -> V_21 , 2 ) ;
V_28 -> V_102 = V_92 ;
F_97 ( & V_30 -> V_106 ) ;
F_98 ( & V_30 -> V_147 ) ;
V_83 = F_63 ( V_24 -> V_10 . V_31 ,
F_1 ,
F_3 , V_28 ,
& V_28 -> V_6 ) ;
if ( F_64 ( V_83 != 0 ) ) {
F_16 ( V_30 ) ;
goto V_156;
}
} else {
V_28 = & V_30 -> V_28 ;
if ( V_50 & V_155 ) {
if ( ! ( V_28 -> V_50 & V_155 ) )
goto V_98;
if ( F_91 ( V_30 ,
V_36 ) )
goto V_156;
F_17 ( V_30 ) ;
goto V_157;
}
V_28 -> V_50 &= ~ V_155 ;
V_30 -> V_28 . V_50 |= V_50 ;
if ( V_28 -> V_50 & V_95 ) {
F_17 ( V_30 ) ;
V_28 -> V_50 &= ~ V_95 ;
V_30 -> V_107 = 0 ;
}
}
V_157:
F_92 ( V_30 , V_36 , V_115 ) ;
F_54 ( V_77 , V_24 ,
L_18 ,
V_28 -> V_12 , F_55 ( V_28 -> V_13 ) ,
V_36 -> V_154 ) ;
V_86 = true ;
V_156:
V_153 = F_80 ( V_24 , V_152 , V_13 ,
L_19 ,
V_50 & V_95 ) ;
V_30 -> V_28 . V_50 |= V_153 & V_101 ;
if ( ! ( V_50 & V_95 ) )
V_30 -> V_28 . V_50 &= ~ V_95 ;
V_98:
if ( V_30 )
F_16 ( V_30 ) ;
if ( V_26 )
F_13 ( V_26 ) ;
return V_86 ;
}
static struct V_34 *
F_99 ( struct V_23 * V_24 ,
struct V_29 * V_30 )
{
struct V_158 * V_159 , * V_160 = NULL ;
struct V_161 * V_162 = V_24 -> V_163 ;
struct V_15 * V_16 ;
struct V_34 * V_35 , * V_164 = NULL ;
V_16 = & V_30 -> V_106 ;
F_7 (orig_entry, head, list) {
V_159 = F_100 ( V_35 -> V_36 ) ;
if ( ! V_159 )
continue;
if ( V_160 &&
V_162 -> V_165 ( V_159 , V_160 ) <= 0 ) {
F_101 ( V_159 ) ;
continue;
}
if ( V_160 )
F_101 ( V_160 ) ;
V_164 = V_35 ;
V_160 = V_159 ;
}
if ( V_160 )
F_101 ( V_160 ) ;
return V_164 ;
}
static void
F_102 ( struct V_23 * V_24 ,
struct V_29 * V_30 ,
struct V_129 * V_130 )
{
struct V_34 * V_35 , * V_164 ;
struct V_5 * V_25 ;
struct V_42 * V_39 ;
struct V_15 * V_16 ;
T_2 V_116 ;
T_3 V_50 ;
V_25 = & V_30 -> V_28 ;
V_50 = V_25 -> V_50 ;
V_164 = F_99 ( V_24 , V_30 ) ;
if ( V_164 ) {
V_39 = F_103 ( V_164 -> V_36 ,
V_25 -> V_13 ) ;
if ( ! V_39 ) {
F_76 ( V_130 ,
L_20 ,
F_55 ( V_25 -> V_13 ) ,
V_164 -> V_36 -> V_154 ) ;
goto V_166;
}
V_116 = F_49 ( & V_164 -> V_36 -> V_116 ) ;
F_76 ( V_130 ,
L_21 ,
'*' , V_30 -> V_28 . V_12 ,
F_55 ( V_30 -> V_28 . V_13 ) ,
V_164 -> V_115 , V_164 -> V_36 -> V_154 ,
V_116 , V_39 -> V_10 . V_117 ,
( V_50 & V_95 ? 'R' : '.' ) ,
( V_50 & V_101 ? 'W' : '.' ) ,
( V_50 & V_155 ? 'T' : '.' ) ) ;
F_33 ( V_39 ) ;
}
V_166:
V_16 = & V_30 -> V_106 ;
F_7 (orig_entry, head, list) {
if ( V_164 == V_35 )
continue;
V_39 = F_103 ( V_35 -> V_36 ,
V_25 -> V_13 ) ;
if ( ! V_39 ) {
F_76 ( V_130 ,
L_22 ,
F_55 ( V_25 -> V_13 ) ,
V_35 -> V_36 -> V_154 ) ;
continue;
}
V_116 = F_49 ( & V_35 -> V_36 -> V_116 ) ;
F_76 ( V_130 ,
L_23 ,
'+' , V_30 -> V_28 . V_12 ,
F_55 ( V_30 -> V_28 . V_13 ) ,
V_35 -> V_115 , V_35 -> V_36 -> V_154 ,
V_116 , V_39 -> V_10 . V_117 ,
( V_50 & V_95 ? 'R' : '.' ) ,
( V_50 & V_101 ? 'W' : '.' ) ,
( V_50 & V_155 ? 'T' : '.' ) ) ;
F_33 ( V_39 ) ;
}
}
int F_104 ( struct V_129 * V_130 , void * V_131 )
{
struct V_78 * V_132 = (struct V_78 * ) V_130 -> V_133 ;
struct V_23 * V_24 = F_58 ( V_132 ) ;
struct V_14 * V_11 = V_24 -> V_10 . V_31 ;
struct V_5 * V_25 ;
struct V_29 * V_75 ;
struct V_134 * V_135 ;
struct V_15 * V_16 ;
T_1 V_136 ;
V_135 = F_75 ( V_130 ) ;
if ( ! V_135 )
goto V_98;
F_76 ( V_130 ,
L_24 ,
V_132 -> V_142 ) ;
F_76 ( V_130 , L_25 ,
L_9 , L_10 , L_26 , L_27 , L_28 ,
L_13 , L_11 ) ;
for ( V_136 = 0 ; V_136 < V_11 -> V_9 ; V_136 ++ ) {
V_16 = & V_11 -> V_20 [ V_136 ] ;
F_6 () ;
F_7 (tt_common_entry,
head, hash_entry) {
V_75 = F_2 ( V_25 ,
struct V_29 ,
V_28 ) ;
F_102 ( V_24 , V_75 , V_130 ) ;
}
F_10 () ;
}
V_98:
if ( V_135 )
F_78 ( V_135 ) ;
return 0 ;
}
static void
F_17 ( struct V_29 * V_30 )
{
struct V_15 * V_16 ;
struct V_1 * V_49 ;
struct V_34 * V_35 ;
F_30 ( & V_30 -> V_147 ) ;
V_16 = & V_30 -> V_106 ;
F_83 (orig_entry, safe, head, list) {
F_81 ( & V_35 -> V_44 ) ;
F_35 ( V_35 -> V_36 ,
V_30 -> V_28 . V_13 ) ;
F_36 ( V_35 ) ;
}
F_32 ( & V_30 -> V_147 ) ;
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
F_30 ( & V_30 -> V_147 ) ;
V_16 = & V_30 -> V_106 ;
F_83 (orig_entry, safe, head, list) {
if ( V_35 -> V_36 == V_36 ) {
V_13 = V_30 -> V_28 . V_13 ;
F_54 ( V_77 , V_24 ,
L_29 ,
V_36 -> V_154 ,
V_30 -> V_28 . V_12 ,
F_55 ( V_13 ) , V_76 ) ;
F_81 ( & V_35 -> V_44 ) ;
F_35 ( V_36 ,
V_30 -> V_28 . V_13 ) ;
F_36 ( V_35 ) ;
}
}
F_32 ( & V_30 -> V_147 ) ;
}
static void
F_106 ( struct V_23 * V_24 ,
struct V_29 * V_30 ,
struct V_41 * V_36 ,
const char * V_76 )
{
bool V_167 = true ;
struct V_15 * V_16 ;
struct V_34 * V_35 ;
F_6 () ;
V_16 = & V_30 -> V_106 ;
F_7 (orig_entry, head, list) {
if ( V_35 -> V_36 != V_36 ) {
V_167 = false ;
break;
}
}
F_10 () ;
if ( V_167 ) {
V_30 -> V_28 . V_50 |= V_95 ;
V_30 -> V_107 = V_92 ;
} else
F_105 ( V_24 , V_30 ,
V_36 , V_76 ) ;
}
static void F_107 ( struct V_23 * V_24 ,
struct V_41 * V_36 ,
const unsigned char * V_12 , unsigned short V_13 ,
const char * V_76 , bool V_143 )
{
struct V_29 * V_30 ;
struct V_22 * V_168 = NULL ;
V_30 = F_12 ( V_24 , V_12 , V_13 ) ;
if ( ! V_30 )
goto V_98;
if ( ! V_143 ) {
F_105 ( V_24 , V_30 ,
V_36 , V_76 ) ;
if ( F_108 ( & V_30 -> V_106 ) )
F_53 ( V_24 , V_30 ,
V_76 ) ;
goto V_98;
}
V_168 = F_11 ( V_24 ,
V_30 -> V_28 . V_12 ,
V_13 ) ;
if ( V_168 ) {
F_17 ( V_30 ) ;
F_53 ( V_24 , V_30 , V_76 ) ;
} else
F_106 ( V_24 , V_30 ,
V_36 , V_76 ) ;
V_98:
if ( V_30 )
F_16 ( V_30 ) ;
if ( V_168 )
F_13 ( V_168 ) ;
}
void F_109 ( struct V_23 * V_24 ,
struct V_41 * V_36 ,
T_4 V_169 ,
const char * V_76 )
{
struct V_29 * V_75 ;
struct V_5 * V_25 ;
T_1 V_136 ;
struct V_14 * V_11 = V_24 -> V_10 . V_31 ;
struct V_1 * V_49 ;
struct V_15 * V_16 ;
T_5 * V_147 ;
unsigned short V_13 ;
if ( ! V_11 )
return;
for ( V_136 = 0 ; V_136 < V_11 -> V_9 ; V_136 ++ ) {
V_16 = & V_11 -> V_20 [ V_136 ] ;
V_147 = & V_11 -> V_148 [ V_136 ] ;
F_30 ( V_147 ) ;
F_83 (tt_common_entry, safe,
head, hash_entry) {
if ( V_169 >= 0 && V_25 -> V_13 != V_169 )
continue;
V_75 = F_2 ( V_25 ,
struct V_29 ,
V_28 ) ;
F_105 ( V_24 , V_75 ,
V_36 , V_76 ) ;
if ( F_108 ( & V_75 -> V_106 ) ) {
V_13 = V_75 -> V_28 . V_13 ;
F_54 ( V_77 , V_24 ,
L_1 ,
V_75 -> V_28 . V_12 ,
F_55 ( V_13 ) , V_76 ) ;
F_81 ( & V_25 -> V_6 ) ;
F_16 ( V_75 ) ;
}
}
F_32 ( V_147 ) ;
}
V_36 -> V_170 = false ;
}
static bool F_110 ( struct V_29 * V_75 ,
char * * V_171 )
{
bool V_172 = false ;
unsigned long V_173 = V_174 ;
unsigned long V_175 = V_176 ;
if ( ( V_75 -> V_28 . V_50 & V_95 ) &&
F_84 ( V_75 -> V_107 , V_173 ) ) {
V_172 = true ;
* V_171 = L_30 ;
}
if ( ( V_75 -> V_28 . V_50 & V_155 ) &&
F_84 ( V_75 -> V_28 . V_102 , V_175 ) ) {
V_172 = true ;
* V_171 = L_31 ;
}
return V_172 ;
}
static void F_111 ( struct V_23 * V_24 )
{
struct V_14 * V_11 = V_24 -> V_10 . V_31 ;
struct V_15 * V_16 ;
struct V_1 * V_146 ;
T_5 * V_147 ;
T_1 V_136 ;
char * V_171 = NULL ;
struct V_5 * V_177 ;
struct V_29 * V_75 ;
for ( V_136 = 0 ; V_136 < V_11 -> V_9 ; V_136 ++ ) {
V_16 = & V_11 -> V_20 [ V_136 ] ;
V_147 = & V_11 -> V_148 [ V_136 ] ;
F_30 ( V_147 ) ;
F_83 (tt_common, node_tmp, head,
hash_entry) {
V_75 = F_2 ( V_177 ,
struct V_29 ,
V_28 ) ;
if ( ! F_110 ( V_75 , & V_171 ) )
continue;
F_54 ( V_77 , V_24 ,
L_1 ,
V_75 -> V_28 . V_12 ,
F_55 ( V_75 -> V_28 . V_13 ) ,
V_171 ) ;
F_81 ( & V_177 -> V_6 ) ;
F_16 ( V_75 ) ;
}
F_32 ( V_147 ) ;
}
}
static void F_112 ( struct V_23 * V_24 )
{
struct V_14 * V_11 ;
T_5 * V_147 ;
struct V_5 * V_25 ;
struct V_29 * V_75 ;
struct V_1 * V_146 ;
struct V_15 * V_16 ;
T_1 V_136 ;
if ( ! V_24 -> V_10 . V_31 )
return;
V_11 = V_24 -> V_10 . V_31 ;
for ( V_136 = 0 ; V_136 < V_11 -> V_9 ; V_136 ++ ) {
V_16 = & V_11 -> V_20 [ V_136 ] ;
V_147 = & V_11 -> V_148 [ V_136 ] ;
F_30 ( V_147 ) ;
F_83 (tt_common_entry, node_tmp,
head, hash_entry) {
F_81 ( & V_25 -> V_6 ) ;
V_75 = F_2 ( V_25 ,
struct V_29 ,
V_28 ) ;
F_16 ( V_75 ) ;
}
F_32 ( V_147 ) ;
}
F_87 ( V_11 ) ;
V_24 -> V_10 . V_31 = NULL ;
}
static bool
F_113 ( struct V_22 * V_26 ,
struct V_29 * V_30 )
{
bool V_86 = false ;
if ( V_26 -> V_28 . V_50 & V_101 &&
V_30 -> V_28 . V_50 & V_101 )
V_86 = true ;
return V_86 ;
}
struct V_41 * F_114 ( struct V_23 * V_24 ,
const T_2 * V_178 ,
const T_2 * V_12 ,
unsigned short V_13 )
{
struct V_22 * V_26 = NULL ;
struct V_29 * V_30 = NULL ;
struct V_41 * V_36 = NULL ;
struct V_34 * V_164 ;
bool V_179 = false ;
struct V_38 * V_39 ;
V_39 = F_22 ( V_24 , V_13 ) ;
if ( V_39 ) {
V_179 = F_49 ( & V_39 -> V_180 ) ;
F_24 ( V_39 ) ;
}
if ( V_178 && V_179 ) {
V_26 = F_11 ( V_24 , V_178 , V_13 ) ;
if ( ! V_26 ||
( V_26 -> V_28 . V_50 & V_93 ) )
goto V_98;
}
V_30 = F_12 ( V_24 , V_12 , V_13 ) ;
if ( ! V_30 )
goto V_98;
if ( V_26 &&
F_113 ( V_26 , V_30 ) )
goto V_98;
F_6 () ;
V_164 = F_99 ( V_24 , V_30 ) ;
if ( V_164 )
V_36 = V_164 -> V_36 ;
if ( V_36 && ! F_9 ( & V_36 -> V_21 ) )
V_36 = NULL ;
F_10 () ;
V_98:
if ( V_30 )
F_16 ( V_30 ) ;
if ( V_26 )
F_13 ( V_26 ) ;
return V_36 ;
}
static T_1 F_115 ( struct V_23 * V_24 ,
struct V_41 * V_36 ,
unsigned short V_13 )
{
struct V_14 * V_11 = V_24 -> V_10 . V_31 ;
struct V_5 * V_177 ;
struct V_29 * V_75 ;
struct V_15 * V_16 ;
T_1 V_136 , V_181 , V_117 = 0 ;
T_2 V_50 ;
for ( V_136 = 0 ; V_136 < V_11 -> V_9 ; V_136 ++ ) {
V_16 = & V_11 -> V_20 [ V_136 ] ;
F_6 () ;
F_7 (tt_common, head, hash_entry) {
V_75 = F_2 ( V_177 ,
struct V_29 ,
V_28 ) ;
if ( V_177 -> V_13 != V_13 )
continue;
if ( V_177 -> V_50 & V_95 )
continue;
if ( V_177 -> V_50 & V_155 )
continue;
if ( ! F_91 ( V_75 ,
V_36 ) )
continue;
V_181 = F_116 ( 0 , & V_177 -> V_13 ,
sizeof( V_177 -> V_13 ) ) ;
V_50 = V_177 -> V_50 & V_182 ;
V_181 = F_116 ( V_181 , & V_50 , sizeof( V_50 ) ) ;
V_117 ^= F_116 ( V_181 , V_177 -> V_12 , V_7 ) ;
}
F_10 () ;
}
return V_117 ;
}
static T_1 F_117 ( struct V_23 * V_24 ,
unsigned short V_13 )
{
struct V_14 * V_11 = V_24 -> V_10 . V_27 ;
struct V_5 * V_177 ;
struct V_15 * V_16 ;
T_1 V_136 , V_181 , V_117 = 0 ;
T_2 V_50 ;
for ( V_136 = 0 ; V_136 < V_11 -> V_9 ; V_136 ++ ) {
V_16 = & V_11 -> V_20 [ V_136 ] ;
F_6 () ;
F_7 (tt_common, head, hash_entry) {
if ( V_177 -> V_13 != V_13 )
continue;
if ( V_177 -> V_50 & V_100 )
continue;
V_181 = F_116 ( 0 , & V_177 -> V_13 ,
sizeof( V_177 -> V_13 ) ) ;
V_50 = V_177 -> V_50 & V_182 ;
V_181 = F_116 ( V_181 , & V_50 , sizeof( V_50 ) ) ;
V_117 ^= F_116 ( V_181 , V_177 -> V_12 , V_7 ) ;
}
F_10 () ;
}
return V_117 ;
}
static void F_118 ( struct V_23 * V_24 )
{
struct V_183 * V_2 , * V_49 ;
F_30 ( & V_24 -> V_10 . V_184 ) ;
F_41 (node, safe, &bat_priv->tt.req_list, list) {
F_42 ( & V_2 -> V_44 ) ;
F_20 ( V_2 ) ;
}
F_32 ( & V_24 -> V_10 . V_184 ) ;
}
static void F_119 ( struct V_23 * V_24 ,
struct V_41 * V_36 ,
const void * V_185 ,
T_3 V_186 )
{
F_30 ( & V_36 -> V_187 ) ;
if ( V_186 > 0 ) {
F_20 ( V_36 -> V_185 ) ;
V_36 -> V_186 = 0 ;
V_36 -> V_185 = F_39 ( V_186 , V_54 ) ;
if ( V_36 -> V_185 ) {
memcpy ( V_36 -> V_185 , V_185 , V_186 ) ;
V_36 -> V_186 = V_186 ;
}
}
F_32 ( & V_36 -> V_187 ) ;
}
static void F_120 ( struct V_23 * V_24 )
{
struct V_183 * V_2 , * V_49 ;
F_30 ( & V_24 -> V_10 . V_184 ) ;
F_41 (node, safe, &bat_priv->tt.req_list, list) {
if ( F_84 ( V_2 -> V_188 ,
V_189 ) ) {
F_42 ( & V_2 -> V_44 ) ;
F_20 ( V_2 ) ;
}
}
F_32 ( & V_24 -> V_10 . V_184 ) ;
}
static struct V_183 *
F_121 ( struct V_23 * V_24 ,
struct V_41 * V_36 )
{
struct V_183 * V_190 , * V_191 = NULL ;
F_30 ( & V_24 -> V_10 . V_184 ) ;
F_122 (tt_req_node_tmp, &bat_priv->tt.req_list, list) {
if ( F_8 ( V_190 , V_36 ) &&
! F_84 ( V_190 -> V_188 ,
V_189 ) )
goto V_60;
}
V_191 = F_39 ( sizeof( * V_191 ) , V_54 ) ;
if ( ! V_191 )
goto V_60;
memcpy ( V_191 -> V_12 , V_36 -> V_154 , V_7 ) ;
V_191 -> V_188 = V_92 ;
F_123 ( & V_191 -> V_44 , & V_24 -> V_10 . V_192 ) ;
V_60:
F_32 ( & V_24 -> V_10 . V_184 ) ;
return V_191 ;
}
static int F_124 ( const void * V_193 , const void * V_194 )
{
const struct V_5 * V_25 = V_193 ;
if ( V_25 -> V_50 & V_100 )
return 0 ;
return 1 ;
}
static int F_125 ( const void * V_193 ,
const void * V_194 )
{
const struct V_5 * V_25 = V_193 ;
const struct V_29 * V_30 ;
const struct V_41 * V_36 = V_194 ;
if ( V_25 -> V_50 & V_95 ||
V_25 -> V_50 & V_155 )
return 0 ;
V_30 = F_2 ( V_25 ,
struct V_29 ,
V_28 ) ;
return F_91 ( V_30 , V_36 ) ;
}
static void F_126 ( struct V_23 * V_24 ,
struct V_14 * V_11 ,
void * V_195 , T_3 V_65 ,
int (* F_127)( const void * , const void * ) ,
void * V_196 )
{
struct V_5 * V_25 ;
struct V_64 * V_110 ;
struct V_15 * V_16 ;
T_3 V_197 , V_198 = 0 ;
T_1 V_136 ;
V_197 = F_47 ( V_65 ) ;
V_110 = (struct V_64 * ) V_195 ;
F_6 () ;
for ( V_136 = 0 ; V_136 < V_11 -> V_9 ; V_136 ++ ) {
V_16 = & V_11 -> V_20 [ V_136 ] ;
F_7 (tt_common_entry,
head, hash_entry) {
if ( V_197 == V_198 )
break;
if ( ( F_127 ) && ( ! F_127 ( V_25 , V_196 ) ) )
continue;
memcpy ( V_110 -> V_12 , V_25 -> V_12 ,
V_7 ) ;
V_110 -> V_50 = V_25 -> V_50 ;
V_110 -> V_13 = F_40 ( V_25 -> V_13 ) ;
memset ( V_110 -> V_56 , 0 ,
sizeof( V_110 -> V_56 ) ) ;
V_198 ++ ;
V_110 ++ ;
}
}
F_10 () ;
}
static bool F_128 ( struct V_41 * V_36 ,
struct V_72 * V_113 ,
T_3 V_66 )
{
struct V_72 * V_199 ;
struct V_42 * V_39 ;
int V_136 ;
for ( V_136 = 0 ; V_136 < V_66 ; V_136 ++ ) {
V_199 = V_113 + V_136 ;
if ( F_96 ( V_36 -> V_24 ,
V_36 -> V_154 ,
F_129 ( V_199 -> V_13 ) ) )
continue;
V_39 = F_103 ( V_36 ,
F_129 ( V_199 -> V_13 ) ) ;
if ( ! V_39 )
return false ;
if ( V_39 -> V_10 . V_117 != F_130 ( V_199 -> V_117 ) )
return false ;
}
return true ;
}
static void F_131 ( struct V_23 * V_24 )
{
struct V_38 * V_39 ;
F_6 () ;
F_7 (vlan, &bat_priv->softif_vlan_list, list) {
V_39 -> V_10 . V_117 = F_117 ( V_24 , V_39 -> V_13 ) ;
}
F_10 () ;
}
static void F_132 ( struct V_23 * V_24 ,
struct V_41 * V_36 )
{
struct V_42 * V_39 ;
T_1 V_117 ;
F_6 () ;
F_68 (vlan, &orig_node->vlan_list, list) {
if ( F_96 ( V_24 , V_36 -> V_154 ,
V_39 -> V_13 ) )
continue;
V_117 = F_115 ( V_24 , V_36 , V_39 -> V_13 ) ;
V_39 -> V_10 . V_117 = V_117 ;
}
F_10 () ;
}
static int F_133 ( struct V_23 * V_24 ,
struct V_41 * V_200 ,
T_2 V_115 ,
struct V_72 * V_113 ,
T_3 V_66 , bool V_201 )
{
struct V_71 * V_202 = NULL ;
struct V_183 * V_191 = NULL ;
struct V_72 * V_203 ;
struct V_134 * V_135 ;
bool V_86 = false ;
int V_136 , V_9 ;
V_135 = F_134 ( V_24 ) ;
if ( ! V_135 )
goto V_98;
V_191 = F_121 ( V_24 , V_200 ) ;
if ( ! V_191 )
goto V_98;
V_9 = sizeof( * V_202 ) + sizeof( * V_203 ) * V_66 ;
V_202 = F_72 ( V_9 , V_54 ) ;
if ( ! V_202 )
goto V_98;
V_202 -> V_50 = V_204 ;
V_202 -> V_115 = V_115 ;
V_202 -> V_66 = F_40 ( V_66 ) ;
V_203 = (struct V_72 * ) ( V_202 + 1 ) ;
for ( V_136 = 0 ; V_136 < V_66 ; V_136 ++ ) {
V_203 -> V_13 = V_113 -> V_13 ;
V_203 -> V_117 = V_113 -> V_117 ;
V_203 ++ ;
V_113 ++ ;
}
if ( V_201 )
V_202 -> V_50 |= V_205 ;
F_54 ( V_77 , V_24 , L_32 ,
V_200 -> V_154 , V_201 ? 'F' : '.' ) ;
F_135 ( V_24 , V_206 ) ;
F_136 ( V_24 , V_135 -> V_132 -> V_103 ,
V_200 -> V_154 , V_128 , 1 ,
V_202 , V_9 ) ;
V_86 = true ;
V_98:
if ( V_135 )
F_78 ( V_135 ) ;
if ( V_86 && V_191 ) {
F_30 ( & V_24 -> V_10 . V_184 ) ;
F_42 ( & V_191 -> V_44 ) ;
F_32 ( & V_24 -> V_10 . V_184 ) ;
F_20 ( V_191 ) ;
}
F_20 ( V_202 ) ;
return V_86 ;
}
static bool F_137 ( struct V_23 * V_24 ,
struct V_71 * V_109 ,
T_2 * V_207 , T_2 * V_208 )
{
struct V_41 * V_209 ;
struct V_41 * V_210 = NULL ;
struct V_64 * V_110 ;
struct V_71 * V_202 = NULL ;
struct V_72 * V_113 ;
bool V_86 = false , V_201 ;
T_2 V_211 , V_212 ;
T_3 V_112 ;
T_4 V_65 ;
F_54 ( V_77 , V_24 ,
L_33 ,
V_207 , V_109 -> V_115 , V_208 ,
( V_109 -> V_50 & V_205 ? 'F' : '.' ) ) ;
V_209 = F_138 ( V_24 , V_208 ) ;
if ( ! V_209 )
goto V_98;
V_210 = F_138 ( V_24 , V_207 ) ;
if ( ! V_210 )
goto V_98;
V_211 = ( T_2 ) F_49 ( & V_209 -> V_116 ) ;
V_212 = V_109 -> V_115 ;
V_113 = (struct V_72 * ) ( V_109 + 1 ) ;
if ( V_211 != V_212 ||
! F_128 ( V_209 , V_113 ,
F_129 ( V_109 -> V_66 ) ) )
goto V_98;
if ( V_109 -> V_50 & V_205 ||
! V_209 -> V_185 )
V_201 = true ;
else
V_201 = false ;
if ( ! V_201 ) {
F_30 ( & V_209 -> V_187 ) ;
V_65 = V_209 -> V_186 ;
V_112 = F_67 ( V_209 ,
& V_202 ,
& V_110 ,
& V_65 ) ;
if ( ! V_65 )
goto V_60;
memcpy ( V_110 , V_209 -> V_185 ,
V_209 -> V_186 ) ;
F_32 ( & V_209 -> V_187 ) ;
} else {
V_65 = - 1 ;
V_112 = F_67 ( V_209 ,
& V_202 ,
& V_110 ,
& V_65 ) ;
if ( ! V_65 )
goto V_98;
F_126 ( V_24 , V_24 -> V_10 . V_31 ,
V_110 , V_65 ,
F_125 ,
V_209 ) ;
}
V_65 = sizeof( struct V_69 ) + V_112 ;
if ( V_65 > F_49 ( & V_24 -> V_85 ) ) {
F_60 ( V_97 , V_24 -> V_79 ,
L_34 ,
V_210 -> V_154 ) ;
goto V_98;
}
V_202 -> V_50 = V_213 ;
V_202 -> V_115 = V_212 ;
if ( V_201 )
V_202 -> V_50 |= V_205 ;
F_54 ( V_77 , V_24 ,
L_35 ,
V_210 -> V_154 , V_209 -> V_154 ,
V_201 ? 'F' : '.' , V_212 ) ;
F_135 ( V_24 , V_214 ) ;
F_136 ( V_24 , V_209 -> V_154 ,
V_207 , V_128 , 1 , V_202 ,
V_112 ) ;
V_86 = true ;
goto V_98;
V_60:
F_32 ( & V_209 -> V_187 ) ;
V_98:
if ( V_210 )
F_139 ( V_210 ) ;
if ( V_209 )
F_139 ( V_209 ) ;
F_20 ( V_202 ) ;
return V_86 ;
}
static bool F_140 ( struct V_23 * V_24 ,
struct V_71 * V_109 ,
T_2 * V_207 )
{
struct V_71 * V_202 = NULL ;
struct V_134 * V_135 = NULL ;
struct V_64 * V_110 ;
struct V_41 * V_36 ;
T_2 V_215 , V_212 ;
T_3 V_112 ;
bool V_201 ;
T_4 V_65 ;
F_54 ( V_77 , V_24 ,
L_36 ,
V_207 , V_109 -> V_115 ,
( V_109 -> V_50 & V_205 ? 'F' : '.' ) ) ;
F_30 ( & V_24 -> V_10 . V_216 ) ;
V_215 = ( T_2 ) F_49 ( & V_24 -> V_10 . V_99 ) ;
V_212 = V_109 -> V_115 ;
V_36 = F_138 ( V_24 , V_207 ) ;
if ( ! V_36 )
goto V_98;
V_135 = F_134 ( V_24 ) ;
if ( ! V_135 )
goto V_98;
if ( V_109 -> V_50 & V_205 || V_215 != V_212 ||
! V_24 -> V_10 . V_126 )
V_201 = true ;
else
V_201 = false ;
if ( ! V_201 ) {
F_30 ( & V_24 -> V_10 . V_125 ) ;
V_65 = V_24 -> V_10 . V_127 ;
V_112 = F_70 ( V_24 ,
& V_202 ,
& V_110 ,
& V_65 ) ;
if ( ! V_65 )
goto V_60;
memcpy ( V_110 , V_24 -> V_10 . V_126 ,
V_24 -> V_10 . V_127 ) ;
F_32 ( & V_24 -> V_10 . V_125 ) ;
} else {
V_212 = ( T_2 ) F_49 ( & V_24 -> V_10 . V_99 ) ;
V_65 = - 1 ;
V_112 = F_70 ( V_24 ,
& V_202 ,
& V_110 ,
& V_65 ) ;
if ( ! V_65 )
goto V_98;
F_126 ( V_24 , V_24 -> V_10 . V_27 ,
V_110 , V_65 ,
F_124 , NULL ) ;
}
V_202 -> V_50 = V_213 ;
V_202 -> V_115 = V_212 ;
if ( V_201 )
V_202 -> V_50 |= V_205 ;
F_54 ( V_77 , V_24 ,
L_37 ,
V_36 -> V_154 , V_201 ? 'F' : '.' , V_212 ) ;
F_135 ( V_24 , V_214 ) ;
F_136 ( V_24 , V_135 -> V_132 -> V_103 ,
V_207 , V_128 , 1 , V_202 ,
V_112 ) ;
goto V_98;
V_60:
F_32 ( & V_24 -> V_10 . V_125 ) ;
V_98:
F_32 ( & V_24 -> V_10 . V_216 ) ;
if ( V_36 )
F_139 ( V_36 ) ;
if ( V_135 )
F_78 ( V_135 ) ;
F_20 ( V_202 ) ;
return true ;
}
static bool F_141 ( struct V_23 * V_24 ,
struct V_71 * V_109 ,
T_2 * V_207 , T_2 * V_208 )
{
if ( F_142 ( V_24 , V_208 ) )
return F_140 ( V_24 , V_109 , V_207 ) ;
else
return F_137 ( V_24 , V_109 ,
V_207 , V_208 ) ;
}
static void F_143 ( struct V_23 * V_24 ,
struct V_41 * V_36 ,
struct V_64 * V_110 ,
T_3 V_217 , T_2 V_115 )
{
int V_136 ;
int V_218 ;
for ( V_136 = 0 ; V_136 < V_217 ; V_136 ++ ) {
if ( ( V_110 + V_136 ) -> V_50 & V_57 ) {
V_218 = ( V_110 + V_136 ) -> V_50 & V_95 ;
F_107 ( V_24 , V_36 ,
( V_110 + V_136 ) -> V_12 ,
F_129 ( ( V_110 + V_136 ) -> V_13 ) ,
L_38 ,
V_218 ) ;
} else {
if ( ! F_95 ( V_24 , V_36 ,
( V_110 + V_136 ) -> V_12 ,
F_129 ( ( V_110 + V_136 ) -> V_13 ) ,
( V_110 + V_136 ) -> V_50 , V_115 ) )
return;
}
}
V_36 -> V_170 = true ;
}
static void F_144 ( struct V_23 * V_24 ,
struct V_64 * V_110 ,
T_2 V_115 , T_2 * V_219 ,
T_3 V_40 )
{
struct V_41 * V_36 ;
V_36 = F_138 ( V_24 , V_219 ) ;
if ( ! V_36 )
goto V_98;
F_109 ( V_24 , V_36 , - 1 ,
L_39 ) ;
F_143 ( V_24 , V_36 , V_110 , V_40 ,
V_115 ) ;
F_30 ( & V_36 -> V_187 ) ;
F_20 ( V_36 -> V_185 ) ;
V_36 -> V_186 = 0 ;
V_36 -> V_185 = NULL ;
F_32 ( & V_36 -> V_187 ) ;
F_62 ( & V_36 -> V_116 , V_115 ) ;
V_98:
if ( V_36 )
F_139 ( V_36 ) ;
}
static void F_145 ( struct V_23 * V_24 ,
struct V_41 * V_36 ,
T_3 V_217 , T_2 V_115 ,
struct V_64 * V_110 )
{
F_143 ( V_24 , V_36 , V_110 ,
V_217 , V_115 ) ;
F_119 ( V_24 , V_36 , V_110 ,
F_46 ( V_217 ) ) ;
F_62 ( & V_36 -> V_116 , V_115 ) ;
}
bool F_146 ( struct V_23 * V_24 , const T_2 * V_12 ,
unsigned short V_13 )
{
struct V_22 * V_26 ;
bool V_86 = false ;
V_26 = F_11 ( V_24 , V_12 , V_13 ) ;
if ( ! V_26 )
goto V_98;
if ( ( V_26 -> V_28 . V_50 & V_93 ) ||
( V_26 -> V_28 . V_50 & V_95 ) )
goto V_98;
V_86 = true ;
V_98:
if ( V_26 )
F_13 ( V_26 ) ;
return V_86 ;
}
static void F_147 ( struct V_23 * V_24 ,
struct V_71 * V_109 ,
T_2 * V_219 , T_3 V_40 )
{
struct V_183 * V_2 , * V_49 ;
struct V_41 * V_36 = NULL ;
struct V_64 * V_110 ;
T_2 * V_220 = ( T_2 * ) V_109 ;
T_3 V_111 ;
F_54 ( V_77 , V_24 ,
L_40 ,
V_219 , V_109 -> V_115 , V_40 ,
( V_109 -> V_50 & V_205 ? 'F' : '.' ) ) ;
V_36 = F_138 ( V_24 , V_219 ) ;
if ( ! V_36 )
goto V_98;
F_30 ( & V_36 -> V_221 ) ;
V_111 = sizeof( struct V_72 ) ;
V_111 *= F_129 ( V_109 -> V_66 ) ;
V_111 += sizeof( * V_109 ) ;
V_220 += V_111 ;
V_110 = (struct V_64 * ) V_220 ;
if ( V_109 -> V_50 & V_205 ) {
F_144 ( V_24 , V_110 , V_109 -> V_115 ,
V_219 , V_40 ) ;
} else {
F_145 ( V_24 , V_36 , V_40 ,
V_109 -> V_115 , V_110 ) ;
}
F_132 ( V_24 , V_36 ) ;
F_32 ( & V_36 -> V_221 ) ;
F_30 ( & V_24 -> V_10 . V_184 ) ;
F_41 (node, safe, &bat_priv->tt.req_list, list) {
if ( ! F_8 ( V_2 -> V_12 , V_219 ) )
continue;
F_42 ( & V_2 -> V_44 ) ;
F_20 ( V_2 ) ;
}
F_32 ( & V_24 -> V_10 . V_184 ) ;
V_98:
if ( V_36 )
F_139 ( V_36 ) ;
}
static void F_148 ( struct V_23 * V_24 )
{
struct V_222 * V_2 , * V_49 ;
F_30 ( & V_24 -> V_10 . V_223 ) ;
F_41 (node, safe, &bat_priv->tt.roam_list, list) {
F_42 ( & V_2 -> V_44 ) ;
F_20 ( V_2 ) ;
}
F_32 ( & V_24 -> V_10 . V_223 ) ;
}
static void F_149 ( struct V_23 * V_24 )
{
struct V_222 * V_2 , * V_49 ;
F_30 ( & V_24 -> V_10 . V_223 ) ;
F_41 (node, safe, &bat_priv->tt.roam_list, list) {
if ( ! F_84 ( V_2 -> V_224 ,
V_225 ) )
continue;
F_42 ( & V_2 -> V_44 ) ;
F_20 ( V_2 ) ;
}
F_32 ( & V_24 -> V_10 . V_223 ) ;
}
static bool F_150 ( struct V_23 * V_24 ,
T_2 * V_226 )
{
struct V_222 * V_227 ;
bool V_86 = false ;
F_30 ( & V_24 -> V_10 . V_223 ) ;
F_122 (tt_roam_node, &bat_priv->tt.roam_list, list) {
if ( ! F_8 ( V_227 -> V_12 , V_226 ) )
continue;
if ( F_84 ( V_227 -> V_224 ,
V_225 ) )
continue;
if ( ! F_151 ( & V_227 -> V_228 ) )
goto V_60;
V_86 = true ;
break;
}
if ( ! V_86 ) {
V_227 = F_39 ( sizeof( * V_227 ) , V_54 ) ;
if ( ! V_227 )
goto V_60;
V_227 -> V_224 = V_92 ;
F_62 ( & V_227 -> V_228 ,
V_229 - 1 ) ;
memcpy ( V_227 -> V_12 , V_226 , V_7 ) ;
F_123 ( & V_227 -> V_44 , & V_24 -> V_10 . V_230 ) ;
V_86 = true ;
}
V_60:
F_32 ( & V_24 -> V_10 . V_223 ) ;
return V_86 ;
}
static void F_65 ( struct V_23 * V_24 , T_2 * V_226 ,
unsigned short V_13 ,
struct V_41 * V_36 )
{
struct V_134 * V_135 ;
struct V_231 V_232 ;
V_135 = F_134 ( V_24 ) ;
if ( ! V_135 )
goto V_98;
if ( ! F_150 ( V_24 , V_226 ) )
goto V_98;
F_54 ( V_77 , V_24 ,
L_41 ,
V_36 -> V_154 , V_226 , F_55 ( V_13 ) ) ;
F_135 ( V_24 , V_233 ) ;
memcpy ( V_232 . V_226 , V_226 , sizeof( V_232 . V_226 ) ) ;
V_232 . V_13 = F_40 ( V_13 ) ;
F_136 ( V_24 , V_135 -> V_132 -> V_103 ,
V_36 -> V_154 , V_234 , 1 ,
& V_232 , sizeof( V_232 ) ) ;
V_98:
if ( V_135 )
F_78 ( V_135 ) ;
}
static void F_152 ( struct V_235 * V_236 )
{
struct V_237 * V_237 ;
struct V_238 * V_239 ;
struct V_23 * V_24 ;
V_237 = F_2 ( V_236 , struct V_237 , V_236 ) ;
V_239 = F_2 ( V_237 , struct V_238 , V_236 ) ;
V_24 = F_2 ( V_239 , struct V_23 , V_10 ) ;
F_85 ( V_24 , V_240 ) ;
F_111 ( V_24 ) ;
F_120 ( V_24 ) ;
F_149 ( V_24 ) ;
F_153 ( V_241 , & V_24 -> V_10 . V_236 ,
F_154 ( V_242 ) ) ;
}
void F_155 ( struct V_23 * V_24 )
{
F_156 ( V_24 , V_128 , 1 ) ;
F_157 ( V_24 , V_128 , 1 ) ;
F_158 ( & V_24 -> V_10 . V_236 ) ;
F_86 ( V_24 ) ;
F_112 ( V_24 ) ;
F_118 ( V_24 ) ;
F_89 ( V_24 ) ;
F_148 ( V_24 ) ;
F_20 ( V_24 -> V_10 . V_126 ) ;
}
static void F_159 ( struct V_23 * V_24 ,
T_3 V_50 , bool V_243 , bool V_244 )
{
struct V_14 * V_11 = V_24 -> V_10 . V_27 ;
struct V_5 * V_25 ;
T_3 V_245 = 0 ;
struct V_15 * V_16 ;
T_1 V_136 ;
if ( ! V_11 )
return;
for ( V_136 = 0 ; V_136 < V_11 -> V_9 ; V_136 ++ ) {
V_16 = & V_11 -> V_20 [ V_136 ] ;
F_6 () ;
F_7 (tt_common_entry,
head, hash_entry) {
if ( V_243 ) {
if ( ( V_25 -> V_50 & V_50 ) == V_50 )
continue;
V_25 -> V_50 |= V_50 ;
} else {
if ( ! ( V_25 -> V_50 & V_50 ) )
continue;
V_25 -> V_50 &= ~ V_50 ;
}
V_245 ++ ;
if ( ! V_244 )
continue;
F_25 ( V_24 ,
V_25 -> V_13 ) ;
}
F_10 () ;
}
}
static void F_160 ( struct V_23 * V_24 )
{
struct V_14 * V_11 = V_24 -> V_10 . V_27 ;
struct V_5 * V_177 ;
struct V_22 * V_81 ;
struct V_1 * V_146 ;
struct V_15 * V_16 ;
T_5 * V_147 ;
T_1 V_136 ;
if ( ! V_11 )
return;
for ( V_136 = 0 ; V_136 < V_11 -> V_9 ; V_136 ++ ) {
V_16 = & V_11 -> V_20 [ V_136 ] ;
V_147 = & V_11 -> V_148 [ V_136 ] ;
F_30 ( V_147 ) ;
F_83 (tt_common, node_tmp, head,
hash_entry) {
if ( ! ( V_177 -> V_50 & V_93 ) )
continue;
F_54 ( V_77 , V_24 ,
L_42 ,
V_177 -> V_12 ,
F_55 ( V_177 -> V_13 ) ) ;
F_26 ( V_24 , V_177 -> V_13 ) ;
F_81 ( & V_177 -> V_6 ) ;
V_81 = F_2 ( V_177 ,
struct V_22 ,
V_28 ) ;
F_13 ( V_81 ) ;
}
F_32 ( V_147 ) ;
}
}
static void F_161 ( struct V_23 * V_24 )
{
if ( F_49 ( & V_24 -> V_10 . V_62 ) < 1 ) {
if ( ! F_151 ( & V_24 -> V_10 . V_246 ) )
F_71 ( V_24 ) ;
return;
}
F_159 ( V_24 , V_100 , false , true ) ;
F_160 ( V_24 ) ;
F_131 ( V_24 ) ;
F_45 ( & V_24 -> V_10 . V_99 ) ;
F_54 ( V_77 , V_24 ,
L_43 ,
( T_2 ) F_49 ( & V_24 -> V_10 . V_99 ) ) ;
F_62 ( & V_24 -> V_10 . V_246 , V_247 ) ;
F_71 ( V_24 ) ;
}
void F_162 ( struct V_23 * V_24 )
{
F_30 ( & V_24 -> V_10 . V_216 ) ;
F_161 ( V_24 ) ;
F_32 ( & V_24 -> V_10 . V_216 ) ;
}
bool F_163 ( struct V_23 * V_24 , T_2 * V_178 ,
T_2 * V_248 , unsigned short V_13 )
{
struct V_22 * V_26 = NULL ;
struct V_29 * V_30 = NULL ;
struct V_38 * V_39 ;
bool V_86 = false ;
V_39 = F_22 ( V_24 , V_13 ) ;
if ( ! V_39 || ! F_49 ( & V_39 -> V_180 ) )
goto V_98;
V_26 = F_11 ( V_24 , V_248 , V_13 ) ;
if ( ! V_26 )
goto V_98;
V_30 = F_12 ( V_24 , V_178 , V_13 ) ;
if ( ! V_30 )
goto V_98;
if ( ! F_113 ( V_26 , V_30 ) )
goto V_98;
V_86 = true ;
V_98:
if ( V_39 )
F_24 ( V_39 ) ;
if ( V_30 )
F_16 ( V_30 ) ;
if ( V_26 )
F_13 ( V_26 ) ;
return V_86 ;
}
static void F_164 ( struct V_23 * V_24 ,
struct V_41 * V_36 ,
const void * V_185 , T_3 V_249 ,
struct V_64 * V_110 ,
T_3 V_217 , T_2 V_115 )
{
T_2 V_211 = ( T_2 ) F_49 ( & V_36 -> V_116 ) ;
struct V_72 * V_113 ;
bool V_201 = true ;
V_113 = (struct V_72 * ) V_185 ;
if ( ( ! V_36 -> V_170 && V_115 == 1 ) ||
V_115 - V_211 == 1 ) {
if ( ! V_217 ) {
V_201 = false ;
goto V_250;
}
F_30 ( & V_36 -> V_221 ) ;
V_110 = (struct V_64 * ) V_185 ;
F_145 ( V_24 , V_36 , V_217 ,
V_115 , V_110 ) ;
F_132 ( V_24 , V_36 ) ;
F_32 ( & V_36 -> V_221 ) ;
if ( ! F_128 ( V_36 , V_113 ,
V_249 ) )
goto V_250;
} else {
if ( ! V_36 -> V_170 || V_115 != V_211 ||
! F_128 ( V_36 , V_113 ,
V_249 ) ) {
V_250:
F_54 ( V_77 , V_24 ,
L_44 ,
V_36 -> V_154 , V_115 , V_211 ,
V_217 ) ;
F_133 ( V_24 , V_36 , V_115 ,
V_113 , V_249 ,
V_201 ) ;
return;
}
}
}
bool F_165 ( struct V_23 * V_24 ,
T_2 * V_12 , unsigned short V_13 )
{
struct V_29 * V_30 ;
bool V_86 = false ;
V_30 = F_12 ( V_24 , V_12 , V_13 ) ;
if ( ! V_30 )
goto V_98;
V_86 = V_30 -> V_28 . V_50 & V_95 ;
F_16 ( V_30 ) ;
V_98:
return V_86 ;
}
bool F_166 ( struct V_23 * V_24 ,
T_2 * V_12 , unsigned short V_13 )
{
struct V_22 * V_26 ;
bool V_86 = false ;
V_26 = F_11 ( V_24 , V_12 , V_13 ) ;
if ( ! V_26 )
goto V_98;
V_86 = V_26 -> V_28 . V_50 & V_95 ;
F_13 ( V_26 ) ;
V_98:
return V_86 ;
}
bool F_167 ( struct V_23 * V_24 ,
struct V_41 * V_36 ,
const unsigned char * V_12 ,
unsigned short V_13 )
{
bool V_86 = false ;
if ( ! F_95 ( V_24 , V_36 , V_12 , V_13 ,
V_155 ,
F_49 ( & V_36 -> V_116 ) ) )
goto V_98;
F_54 ( V_77 , V_24 ,
L_45 ,
V_12 , F_55 ( V_13 ) , V_36 -> V_154 ) ;
V_86 = true ;
V_98:
return V_86 ;
}
void F_168 ( struct V_78 * V_79 )
{
struct V_23 * V_24 = F_58 ( V_79 ) ;
int V_85 = F_49 ( & V_24 -> V_85 ) ;
int V_84 , V_145 = V_240 / 2 ;
bool V_251 = false ;
F_30 ( & V_24 -> V_10 . V_216 ) ;
while ( true ) {
V_84 = F_48 ( V_24 ) ;
if ( V_85 >= V_84 )
break;
F_85 ( V_24 , V_145 ) ;
F_160 ( V_24 ) ;
V_145 /= 2 ;
V_251 = true ;
F_60 ( V_97 , V_79 ,
L_46 ,
V_85 ) ;
}
if ( V_251 )
F_161 ( V_24 ) ;
F_32 ( & V_24 -> V_10 . V_216 ) ;
}
static void F_169 ( struct V_23 * V_24 ,
struct V_41 * V_154 ,
T_2 V_50 , void * V_252 ,
T_3 V_253 )
{
struct V_72 * V_113 ;
struct V_64 * V_110 ;
struct V_71 * V_109 ;
T_3 V_40 , V_66 ;
if ( V_253 < sizeof( * V_109 ) )
return;
V_109 = (struct V_71 * ) V_252 ;
V_253 -= sizeof( * V_109 ) ;
V_66 = F_129 ( V_109 -> V_66 ) ;
if ( V_253 < sizeof( * V_113 ) * V_66 )
return;
V_113 = (struct V_72 * ) ( V_109 + 1 ) ;
V_110 = (struct V_64 * ) ( V_113 + V_66 ) ;
V_253 -= sizeof( * V_113 ) * V_66 ;
V_40 = F_47 ( V_253 ) ;
F_164 ( V_24 , V_154 , V_113 , V_66 , V_110 ,
V_40 , V_109 -> V_115 ) ;
}
static int F_170 ( struct V_23 * V_24 ,
T_2 * V_178 , T_2 * V_248 ,
void * V_252 ,
T_3 V_253 )
{
struct V_71 * V_109 ;
T_3 V_254 , V_198 ;
char V_255 ;
bool V_86 ;
if ( V_253 < sizeof( * V_109 ) )
return V_256 ;
V_109 = (struct V_71 * ) V_252 ;
V_253 -= sizeof( * V_109 ) ;
V_254 = sizeof( struct V_72 ) ;
V_254 *= F_129 ( V_109 -> V_66 ) ;
if ( V_253 < V_254 )
return V_256 ;
V_253 -= V_254 ;
V_198 = F_47 ( V_253 ) ;
switch ( V_109 -> V_50 & V_257 ) {
case V_204 :
F_135 ( V_24 , V_258 ) ;
V_86 = F_141 ( V_24 , V_109 , V_178 , V_248 ) ;
if ( ! V_86 ) {
if ( V_109 -> V_50 & V_205 )
V_255 = 'F' ;
else
V_255 = '.' ;
F_54 ( V_77 , V_24 ,
L_47 ,
V_248 , V_255 ) ;
return V_259 ;
}
break;
case V_213 :
F_135 ( V_24 , V_260 ) ;
if ( F_142 ( V_24 , V_248 ) ) {
F_147 ( V_24 , V_109 ,
V_178 , V_198 ) ;
return V_256 ;
}
if ( V_109 -> V_50 & V_205 )
V_255 = 'F' ;
else
V_255 = '.' ;
F_54 ( V_77 , V_24 ,
L_48 , V_248 , V_255 ) ;
return V_259 ;
}
return V_256 ;
}
static int F_171 ( struct V_23 * V_24 ,
T_2 * V_178 , T_2 * V_248 ,
void * V_252 ,
T_3 V_253 )
{
struct V_231 * V_261 ;
struct V_41 * V_36 = NULL ;
if ( ! F_142 ( V_24 , V_248 ) )
return V_259 ;
if ( V_253 < sizeof( * V_261 ) )
goto V_98;
V_36 = F_138 ( V_24 , V_178 ) ;
if ( ! V_36 )
goto V_98;
F_135 ( V_24 , V_262 ) ;
V_261 = (struct V_231 * ) V_252 ;
F_54 ( V_77 , V_24 ,
L_49 ,
V_178 , V_261 -> V_226 ) ;
F_95 ( V_24 , V_36 , V_261 -> V_226 ,
F_129 ( V_261 -> V_13 ) , V_95 ,
F_49 ( & V_36 -> V_116 ) + 1 ) ;
V_98:
if ( V_36 )
F_139 ( V_36 ) ;
return V_256 ;
}
int F_172 ( struct V_23 * V_24 )
{
int V_86 ;
F_173 ( ! ( V_182 & V_108 ) ) ;
V_86 = F_50 ( V_24 ) ;
if ( V_86 < 0 )
return V_86 ;
V_86 = F_88 ( V_24 ) ;
if ( V_86 < 0 )
return V_86 ;
F_174 ( V_24 , F_169 ,
F_170 ,
V_128 , 1 , V_105 ) ;
F_174 ( V_24 , NULL ,
F_171 ,
V_234 , 1 , V_105 ) ;
F_175 ( & V_24 -> V_10 . V_236 , F_152 ) ;
F_153 ( V_241 , & V_24 -> V_10 . V_236 ,
F_154 ( V_242 ) ) ;
return 1 ;
}

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
static void F_21 ( struct V_25 * V_26 ,
unsigned short V_9 , int V_37 )
{
struct V_38 * V_39 ;
V_39 = F_22 ( V_26 , V_9 ) ;
if ( ! V_39 )
return;
F_23 ( V_37 , & V_39 -> V_12 . V_40 ) ;
F_24 ( V_39 ) ;
}
static void F_25 ( struct V_25 * V_26 ,
unsigned short V_9 )
{
F_21 ( V_26 , V_9 , 1 ) ;
}
static void F_26 ( struct V_25 * V_26 ,
unsigned short V_9 )
{
F_21 ( V_26 , V_9 , - 1 ) ;
}
static void F_27 ( struct V_41 * V_42 ,
unsigned short V_9 , int V_37 )
{
struct V_43 * V_39 ;
V_39 = F_28 ( V_42 , V_9 ) ;
if ( ! V_39 )
return;
if ( F_29 ( V_37 , & V_39 -> V_12 . V_40 ) == 0 ) {
F_30 ( & V_42 -> V_44 ) ;
if ( ! F_31 ( & V_39 -> V_45 ) ) {
F_32 ( & V_39 -> V_45 ) ;
F_33 ( V_39 ) ;
}
F_34 ( & V_42 -> V_44 ) ;
}
F_33 ( V_39 ) ;
}
static void F_35 ( struct V_41 * V_42 ,
unsigned short V_9 )
{
F_27 ( V_42 , V_9 , 1 ) ;
}
static void F_36 ( struct V_41 * V_42 ,
unsigned short V_9 )
{
F_27 ( V_42 , V_9 , - 1 ) ;
}
static void
F_37 ( struct V_46 * V_47 )
{
F_38 ( V_47 -> V_42 ) ;
F_16 ( V_47 , V_34 ) ;
}
static void
F_39 ( struct V_46 * V_47 )
{
if ( ! F_15 ( & V_47 -> V_23 ) )
return;
F_37 ( V_47 ) ;
}
static void F_40 ( struct V_25 * V_26 ,
struct V_24 * V_28 ,
T_2 V_48 )
{
struct V_49 * V_50 , * V_51 , * V_52 ;
struct V_5 * V_30 = & V_28 -> V_30 ;
T_2 V_53 = V_30 -> V_53 | V_48 ;
bool V_54 = false ;
bool V_55 , V_56 ;
V_50 = F_41 ( sizeof( * V_50 ) , V_57 ) ;
if ( ! V_50 )
return;
V_50 -> V_58 . V_53 = V_53 ;
memset ( V_50 -> V_58 . V_59 , 0 ,
sizeof( V_50 -> V_58 . V_59 ) ) ;
F_7 ( V_50 -> V_58 . V_14 , V_30 -> V_14 ) ;
V_50 -> V_58 . V_9 = F_42 ( V_30 -> V_9 ) ;
V_55 = V_53 & V_60 ;
F_30 ( & V_26 -> V_12 . V_61 ) ;
F_43 (entry, safe, &bat_priv->tt.changes_list,
list) {
if ( ! F_3 ( V_51 -> V_58 . V_14 , V_30 -> V_14 ) )
continue;
V_56 = V_51 -> V_58 . V_53 & V_60 ;
if ( ! V_55 && V_56 )
goto V_62;
if ( V_55 && ! V_56 )
goto V_62;
if ( ! V_55 && ! V_56 )
V_51 -> V_58 . V_53 = V_53 ;
continue;
V_62:
F_44 ( & V_51 -> V_45 ) ;
F_45 ( V_51 ) ;
F_45 ( V_50 ) ;
V_54 = true ;
goto V_63;
}
F_46 ( & V_50 -> V_45 , & V_26 -> V_12 . V_64 ) ;
V_63:
F_34 ( & V_26 -> V_12 . V_61 ) ;
if ( V_54 )
F_47 ( & V_26 -> V_12 . V_65 ) ;
else
F_48 ( & V_26 -> V_12 . V_65 ) ;
}
static int F_49 ( int V_66 )
{
return V_66 * sizeof( struct V_67 ) ;
}
static T_3 F_50 ( T_3 V_68 )
{
return V_68 / F_49 ( 1 ) ;
}
static int F_51 ( struct V_25 * V_26 )
{
T_3 V_69 = 0 ;
T_3 V_70 = 0 ;
struct V_38 * V_39 ;
int V_71 ;
F_8 () ;
F_9 (vlan, &bat_priv->softif_vlan_list, list) {
V_69 ++ ;
V_70 += F_20 ( & V_39 -> V_12 . V_40 ) ;
}
F_11 () ;
V_71 = sizeof( struct V_72 ) ;
V_71 += sizeof( struct V_73 ) ;
V_71 += sizeof( struct V_74 ) ;
V_71 += V_69 * sizeof( struct V_75 ) ;
return V_71 + F_49 ( V_70 ) ;
}
static int F_52 ( struct V_25 * V_26 )
{
if ( V_26 -> V_12 . V_29 )
return 0 ;
V_26 -> V_12 . V_29 = F_53 ( 1024 ) ;
if ( ! V_26 -> V_12 . V_29 )
return - V_76 ;
F_54 ( V_26 -> V_12 . V_29 ,
& V_77 ) ;
return 0 ;
}
static void F_55 ( struct V_25 * V_26 ,
struct V_31 * V_78 ,
const char * V_79 )
{
F_56 ( V_80 , V_26 ,
L_1 ,
V_78 -> V_30 . V_14 ,
F_57 ( V_78 -> V_30 . V_9 ) , V_79 ) ;
F_58 ( V_26 -> V_12 . V_33 , F_1 ,
F_4 , & V_78 -> V_30 ) ;
F_17 ( V_78 ) ;
}
bool F_59 ( struct V_81 * V_82 , const T_2 * V_14 ,
unsigned short V_9 , int V_83 , T_1 V_84 )
{
struct V_25 * V_26 = F_60 ( V_82 ) ;
struct V_24 * V_85 ;
struct V_31 * V_78 = NULL ;
struct V_38 * V_39 ;
struct V_81 * V_86 = NULL ;
struct V_17 * V_18 ;
struct V_46 * V_47 ;
int V_87 , V_88 , V_89 ;
bool V_90 = false ;
bool V_91 = false ;
T_2 V_92 ;
T_1 V_93 ;
if ( V_83 != V_94 )
V_86 = F_61 ( & V_95 , V_83 ) ;
V_85 = F_12 ( V_26 , V_14 , V_9 ) ;
if ( ! F_62 ( V_14 ) )
V_78 = F_13 ( V_26 , V_14 , V_9 ) ;
if ( V_85 ) {
V_85 -> V_96 = V_97 ;
if ( V_85 -> V_30 . V_53 & V_98 ) {
F_56 ( V_80 , V_26 ,
L_2 ,
V_14 , F_57 ( V_9 ) ) ;
V_85 -> V_30 . V_53 &= ~ V_98 ;
goto V_99;
}
if ( V_85 -> V_30 . V_53 & V_100 ) {
F_56 ( V_80 , V_26 ,
L_3 ,
V_14 , F_57 ( V_9 ) ) ;
V_85 -> V_30 . V_53 &= ~ V_100 ;
V_91 = true ;
}
goto V_101;
}
V_88 = F_51 ( V_26 ) ;
V_88 += F_49 ( 1 ) ;
V_89 = F_20 ( & V_26 -> V_89 ) ;
if ( V_88 > V_89 ) {
F_63 ( V_102 , V_82 ,
L_4 ,
V_88 , V_89 , V_14 ) ;
goto V_103;
}
V_85 = F_41 ( sizeof( * V_85 ) , V_57 ) ;
if ( ! V_85 )
goto V_103;
V_39 = F_22 ( V_26 , V_9 ) ;
if ( F_64 ( ! V_39 , L_5 ,
V_14 , F_57 ( V_9 ) ) ) {
F_45 ( V_85 ) ;
V_85 = NULL ;
goto V_103;
}
F_56 ( V_80 , V_26 ,
L_6 ,
V_14 , F_57 ( V_9 ) ,
( T_2 ) F_20 ( & V_26 -> V_12 . V_104 ) ) ;
F_7 ( V_85 -> V_30 . V_14 , V_14 ) ;
V_85 -> V_30 . V_53 = V_105 ;
V_85 -> V_30 . V_9 = V_9 ;
if ( F_65 ( V_86 ) )
V_85 -> V_30 . V_53 |= V_106 ;
F_66 ( & V_85 -> V_30 . V_23 , 2 ) ;
V_85 -> V_96 = V_97 ;
V_85 -> V_30 . V_107 = V_85 -> V_96 ;
if ( F_3 ( V_14 , V_82 -> V_108 ) ||
F_62 ( V_14 ) )
V_85 -> V_30 . V_53 |= V_109 ;
V_87 = F_67 ( V_26 -> V_12 . V_29 , F_1 ,
F_4 , & V_85 -> V_30 ,
& V_85 -> V_30 . V_6 ) ;
if ( F_68 ( V_87 != 0 ) ) {
F_14 ( V_85 ) ;
F_24 ( V_39 ) ;
goto V_103;
}
V_99:
F_40 ( V_26 , V_85 , V_110 ) ;
V_101:
if ( V_78 && ! ( V_78 -> V_30 . V_53 & V_100 ) ) {
V_18 = & V_78 -> V_111 ;
F_8 () ;
F_9 (orig_entry, head, list) {
F_69 ( V_26 , V_78 -> V_30 . V_14 ,
V_78 -> V_30 . V_9 ,
V_47 -> V_42 ) ;
}
F_11 () ;
if ( V_91 ) {
F_55 ( V_26 , V_78 ,
L_7 ) ;
V_78 = NULL ;
} else {
V_78 -> V_30 . V_53 |= V_100 ;
V_78 -> V_112 = V_97 ;
}
}
V_92 = V_85 -> V_30 . V_53 & V_113 ;
if ( F_65 ( V_86 ) )
V_85 -> V_30 . V_53 |= V_106 ;
else
V_85 -> V_30 . V_53 &= ~ V_106 ;
V_93 = ( V_84 & V_26 -> V_114 ) ;
if ( V_26 -> V_114 &&
V_93 == V_26 -> V_115 )
V_85 -> V_30 . V_53 |= V_116 ;
else
V_85 -> V_30 . V_53 &= ~ V_116 ;
if ( V_92 ^ ( V_85 -> V_30 . V_53 & V_113 ) )
F_40 ( V_26 , V_85 , V_110 ) ;
V_90 = true ;
V_103:
if ( V_86 )
F_70 ( V_86 ) ;
if ( V_85 )
F_14 ( V_85 ) ;
if ( V_78 )
F_17 ( V_78 ) ;
return V_90 ;
}
static T_3
F_71 ( struct V_41 * V_42 ,
struct V_74 * * V_117 ,
struct V_67 * * V_118 ,
T_4 * V_68 )
{
T_3 V_69 = 0 ;
T_3 V_40 = 0 ;
T_3 V_119 ;
T_3 V_120 ;
struct V_75 * V_121 ;
struct V_43 * V_39 ;
T_2 * V_122 ;
F_8 () ;
F_9 (vlan, &orig_node->vlan_list, list) {
V_69 ++ ;
V_40 += F_20 ( & V_39 -> V_12 . V_40 ) ;
}
V_119 = sizeof( * * V_117 ) ;
V_119 += V_69 * sizeof( * V_121 ) ;
if ( * V_68 < 0 )
* V_68 = F_49 ( V_40 ) ;
V_120 = * V_68 ;
V_120 += V_119 ;
* V_117 = F_41 ( V_120 , V_57 ) ;
if ( ! * V_117 ) {
* V_68 = 0 ;
goto V_103;
}
( * V_117 ) -> V_53 = V_110 ;
( * V_117 ) -> V_123 = F_20 ( & V_42 -> V_124 ) ;
( * V_117 ) -> V_69 = F_42 ( V_69 ) ;
V_121 = (struct V_75 * ) ( * V_117 + 1 ) ;
F_9 (vlan, &orig_node->vlan_list, list) {
V_121 -> V_9 = F_42 ( V_39 -> V_9 ) ;
V_121 -> V_125 = F_72 ( V_39 -> V_12 . V_125 ) ;
V_121 ++ ;
}
V_122 = ( T_2 * ) * V_117 + V_119 ;
* V_118 = (struct V_67 * ) V_122 ;
V_103:
F_11 () ;
return V_120 ;
}
static T_3
F_73 ( struct V_25 * V_26 ,
struct V_74 * * V_117 ,
struct V_67 * * V_118 ,
T_4 * V_68 )
{
struct V_75 * V_121 ;
struct V_38 * V_39 ;
T_3 V_69 = 0 ;
T_3 V_40 = 0 ;
T_3 V_120 ;
T_2 * V_122 ;
int V_119 ;
F_8 () ;
F_9 (vlan, &bat_priv->softif_vlan_list, list) {
V_69 ++ ;
V_40 += F_20 ( & V_39 -> V_12 . V_40 ) ;
}
V_119 = sizeof( * * V_117 ) ;
V_119 += V_69 * sizeof( * V_121 ) ;
if ( * V_68 < 0 )
* V_68 = F_49 ( V_40 ) ;
V_120 = * V_68 ;
V_120 += V_119 ;
* V_117 = F_41 ( V_120 , V_57 ) ;
if ( ! * V_117 ) {
V_120 = 0 ;
goto V_103;
}
( * V_117 ) -> V_53 = V_110 ;
( * V_117 ) -> V_123 = F_20 ( & V_26 -> V_12 . V_104 ) ;
( * V_117 ) -> V_69 = F_42 ( V_69 ) ;
V_121 = (struct V_75 * ) ( * V_117 + 1 ) ;
F_9 (vlan, &bat_priv->softif_vlan_list, list) {
V_121 -> V_9 = F_42 ( V_39 -> V_9 ) ;
V_121 -> V_125 = F_72 ( V_39 -> V_12 . V_125 ) ;
V_121 ++ ;
}
V_122 = ( T_2 * ) * V_117 + V_119 ;
* V_118 = (struct V_67 * ) V_122 ;
V_103:
F_11 () ;
return V_120 ;
}
static void F_74 ( struct V_25 * V_26 )
{
struct V_49 * V_51 , * V_52 ;
struct V_74 * V_117 ;
struct V_67 * V_118 ;
int V_126 , V_127 = 0 ;
int V_128 = 0 ;
int V_129 = 0 ;
T_3 V_120 ;
V_128 = F_20 ( & V_26 -> V_12 . V_65 ) ;
V_126 = F_49 ( V_128 ) ;
if ( V_126 > V_26 -> V_82 -> V_130 )
V_126 = 0 ;
V_120 = F_73 ( V_26 , & V_117 ,
& V_118 , & V_126 ) ;
if ( ! V_120 )
return;
V_117 -> V_53 = V_131 ;
if ( V_126 == 0 )
goto V_132;
F_30 ( & V_26 -> V_12 . V_61 ) ;
F_66 ( & V_26 -> V_12 . V_65 , 0 ) ;
F_43 (entry, safe, &bat_priv->tt.changes_list,
list) {
if ( V_129 < V_128 ) {
memcpy ( V_118 + V_129 ,
& V_51 -> V_58 ,
sizeof( struct V_67 ) ) ;
V_129 ++ ;
}
F_44 ( & V_51 -> V_45 ) ;
F_45 ( V_51 ) ;
}
F_34 ( & V_26 -> V_12 . V_61 ) ;
F_30 ( & V_26 -> V_12 . V_133 ) ;
F_45 ( V_26 -> V_12 . V_134 ) ;
V_26 -> V_12 . V_135 = 0 ;
V_26 -> V_12 . V_134 = NULL ;
V_127 = F_49 ( V_129 ) ;
if ( V_129 > 0 ) {
V_26 -> V_12 . V_134 = F_75 ( V_126 , V_57 ) ;
if ( V_26 -> V_12 . V_134 ) {
memcpy ( V_26 -> V_12 . V_134 ,
V_118 , V_127 ) ;
V_26 -> V_12 . V_135 = V_126 ;
}
}
F_34 ( & V_26 -> V_12 . V_133 ) ;
V_132:
F_76 ( V_26 , V_136 , 1 , V_117 ,
V_120 ) ;
F_45 ( V_117 ) ;
}
int F_77 ( struct V_137 * V_138 , void * V_139 )
{
struct V_81 * V_140 = (struct V_81 * ) V_138 -> V_141 ;
struct V_25 * V_26 = F_60 ( V_140 ) ;
struct V_16 * V_13 = V_26 -> V_12 . V_29 ;
struct V_5 * V_27 ;
struct V_24 * V_85 ;
struct V_142 * V_143 ;
struct V_38 * V_39 ;
struct V_17 * V_18 ;
unsigned short V_9 ;
T_1 V_144 ;
int V_145 ;
int V_146 ;
unsigned long V_147 ;
bool V_148 ;
T_3 V_149 = V_109 ;
V_143 = F_78 ( V_138 ) ;
if ( ! V_143 )
goto V_103;
F_79 ( V_138 ,
L_8 ,
V_140 -> V_150 , ( T_2 ) F_20 ( & V_26 -> V_12 . V_104 ) ) ;
F_79 ( V_138 , L_9 , L_10 , L_11 ,
L_12 , L_13 , L_14 ) ;
for ( V_144 = 0 ; V_144 < V_13 -> V_11 ; V_144 ++ ) {
V_18 = & V_13 -> V_22 [ V_144 ] ;
F_8 () ;
F_9 (tt_common_entry,
head, hash_entry) {
V_85 = F_2 ( V_27 ,
struct V_24 ,
V_30 ) ;
V_9 = V_27 -> V_9 ;
V_147 = V_97 - V_85 -> V_96 ;
V_146 = F_80 ( V_147 ) ;
V_145 = V_146 / 1000 ;
V_146 = V_146 % 1000 ;
V_148 = V_27 -> V_53 & V_149 ;
V_39 = F_22 ( V_26 , V_9 ) ;
if ( ! V_39 ) {
F_79 ( V_138 , L_15 ,
F_57 ( V_9 ) ) ;
continue;
}
F_79 ( V_138 ,
L_16 ,
V_27 -> V_14 ,
F_57 ( V_27 -> V_9 ) ,
( ( V_27 -> V_53 &
V_100 ) ? 'R' : '.' ) ,
V_148 ? 'P' : '.' ,
( ( V_27 -> V_53 &
V_105 ) ? 'N' : '.' ) ,
( ( V_27 -> V_53 &
V_98 ) ? 'X' : '.' ) ,
( ( V_27 -> V_53 &
V_106 ) ? 'W' : '.' ) ,
( ( V_27 -> V_53 &
V_116 ) ? 'I' : '.' ) ,
V_148 ? 0 : V_145 ,
V_148 ? 0 : V_146 ,
V_39 -> V_12 . V_125 ) ;
F_24 ( V_39 ) ;
}
F_11 () ;
}
V_103:
if ( V_143 )
F_81 ( V_143 ) ;
return 0 ;
}
static void
F_82 ( struct V_25 * V_26 ,
struct V_24 * V_28 ,
T_3 V_53 , const char * V_79 )
{
F_40 ( V_26 , V_28 , V_53 ) ;
V_28 -> V_30 . V_53 |= V_98 ;
F_56 ( V_80 , V_26 ,
L_17 ,
V_28 -> V_30 . V_14 ,
F_57 ( V_28 -> V_30 . V_9 ) , V_79 ) ;
}
T_3 F_83 ( struct V_25 * V_26 , const T_2 * V_14 ,
unsigned short V_9 , const char * V_79 ,
bool V_151 )
{
struct V_24 * V_28 ;
T_3 V_53 , V_152 = V_110 ;
struct V_38 * V_39 ;
void * V_153 ;
V_28 = F_12 ( V_26 , V_14 , V_9 ) ;
if ( ! V_28 )
goto V_103;
V_152 = V_28 -> V_30 . V_53 ;
V_53 = V_60 ;
if ( V_151 ) {
V_53 |= V_100 ;
V_28 -> V_30 . V_53 |= V_100 ;
}
if ( ! ( V_28 -> V_30 . V_53 & V_105 ) ) {
F_82 ( V_26 , V_28 , V_53 ,
V_79 ) ;
goto V_103;
}
F_40 ( V_26 , V_28 , V_60 ) ;
V_153 = F_58 ( V_26 -> V_12 . V_29 ,
F_1 ,
F_4 ,
& V_28 -> V_30 ) ;
if ( ! V_153 )
goto V_103;
F_14 ( V_28 ) ;
V_39 = F_22 ( V_26 , V_9 ) ;
if ( ! V_39 )
goto V_103;
F_24 ( V_39 ) ;
F_24 ( V_39 ) ;
V_103:
if ( V_28 )
F_14 ( V_28 ) ;
return V_152 ;
}
static void F_84 ( struct V_25 * V_26 ,
struct V_17 * V_18 ,
int V_154 )
{
struct V_24 * V_28 ;
struct V_5 * V_27 ;
struct V_1 * V_155 ;
F_85 (tt_common_entry, node_tmp, head,
hash_entry) {
V_28 = F_2 ( V_27 ,
struct V_24 ,
V_30 ) ;
if ( V_28 -> V_30 . V_53 & V_109 )
continue;
if ( V_28 -> V_30 . V_53 & V_98 )
continue;
if ( ! F_86 ( V_28 -> V_96 , V_154 ) )
continue;
F_82 ( V_26 , V_28 ,
V_60 , L_18 ) ;
}
}
static void F_87 ( struct V_25 * V_26 ,
int V_154 )
{
struct V_16 * V_13 = V_26 -> V_12 . V_29 ;
struct V_17 * V_18 ;
T_5 * V_156 ;
T_1 V_144 ;
for ( V_144 = 0 ; V_144 < V_13 -> V_11 ; V_144 ++ ) {
V_18 = & V_13 -> V_22 [ V_144 ] ;
V_156 = & V_13 -> V_157 [ V_144 ] ;
F_30 ( V_156 ) ;
F_84 ( V_26 , V_18 , V_154 ) ;
F_34 ( V_156 ) ;
}
}
static void F_88 ( struct V_25 * V_26 )
{
struct V_16 * V_13 ;
T_5 * V_156 ;
struct V_5 * V_27 ;
struct V_24 * V_85 ;
struct V_38 * V_39 ;
struct V_1 * V_155 ;
struct V_17 * V_18 ;
T_1 V_144 ;
if ( ! V_26 -> V_12 . V_29 )
return;
V_13 = V_26 -> V_12 . V_29 ;
for ( V_144 = 0 ; V_144 < V_13 -> V_11 ; V_144 ++ ) {
V_18 = & V_13 -> V_22 [ V_144 ] ;
V_156 = & V_13 -> V_157 [ V_144 ] ;
F_30 ( V_156 ) ;
F_85 (tt_common_entry, node_tmp,
head, hash_entry) {
F_89 ( & V_27 -> V_6 ) ;
V_85 = F_2 ( V_27 ,
struct V_24 ,
V_30 ) ;
V_39 = F_22 ( V_26 ,
V_27 -> V_9 ) ;
if ( V_39 ) {
F_24 ( V_39 ) ;
F_24 ( V_39 ) ;
}
F_14 ( V_85 ) ;
}
F_34 ( V_156 ) ;
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
return - V_76 ;
F_54 ( V_26 -> V_12 . V_33 ,
& V_158 ) ;
return 0 ;
}
static void F_92 ( struct V_25 * V_26 )
{
struct V_49 * V_51 , * V_52 ;
F_30 ( & V_26 -> V_12 . V_61 ) ;
F_43 (entry, safe, &bat_priv->tt.changes_list,
list) {
F_44 ( & V_51 -> V_45 ) ;
F_45 ( V_51 ) ;
}
F_66 ( & V_26 -> V_12 . V_65 , 0 ) ;
F_34 ( & V_26 -> V_12 . V_61 ) ;
}
static struct V_46 *
F_93 ( const struct V_31 * V_51 ,
const struct V_41 * V_42 )
{
struct V_46 * V_159 , * V_47 = NULL ;
const struct V_17 * V_18 ;
F_8 () ;
V_18 = & V_51 -> V_111 ;
F_9 (tmp_orig_entry, head, list) {
if ( V_159 -> V_42 != V_42 )
continue;
if ( ! F_10 ( & V_159 -> V_23 ) )
continue;
V_47 = V_159 ;
break;
}
F_11 () ;
return V_47 ;
}
static bool
F_94 ( const struct V_31 * V_51 ,
const struct V_41 * V_42 )
{
struct V_46 * V_47 ;
bool V_160 = false ;
V_47 = F_93 ( V_51 , V_42 ) ;
if ( V_47 ) {
V_160 = true ;
F_39 ( V_47 ) ;
}
return V_160 ;
}
static void
F_95 ( struct V_31 * V_78 ,
struct V_41 * V_42 , int V_123 )
{
struct V_46 * V_47 ;
V_47 = F_93 ( V_78 , V_42 ) ;
if ( V_47 ) {
V_47 -> V_123 = V_123 ;
goto V_103;
}
V_47 = F_75 ( sizeof( * V_47 ) , V_57 ) ;
if ( ! V_47 )
goto V_103;
F_96 ( & V_47 -> V_45 ) ;
F_48 ( & V_42 -> V_23 ) ;
F_35 ( V_42 , V_78 -> V_30 . V_9 ) ;
V_47 -> V_42 = V_42 ;
V_47 -> V_123 = V_123 ;
F_66 ( & V_47 -> V_23 , 2 ) ;
F_30 ( & V_78 -> V_156 ) ;
F_97 ( & V_47 -> V_45 ,
& V_78 -> V_111 ) ;
F_34 ( & V_78 -> V_156 ) ;
F_48 ( & V_78 -> V_36 ) ;
V_103:
if ( V_47 )
F_39 ( V_47 ) ;
}
static bool F_98 ( struct V_25 * V_26 ,
struct V_41 * V_42 ,
const unsigned char * V_161 ,
unsigned short V_9 , T_3 V_53 , T_2 V_123 )
{
struct V_31 * V_32 ;
struct V_24 * V_28 ;
bool V_90 = false ;
int V_87 ;
struct V_5 * V_30 ;
T_3 V_162 ;
if ( F_99 ( V_26 , V_42 -> V_163 , V_9 ) )
return true ;
V_32 = F_13 ( V_26 , V_161 , V_9 ) ;
V_28 = F_12 ( V_26 , V_161 , V_9 ) ;
if ( ( V_53 & V_164 ) && V_28 &&
! ( V_28 -> V_30 . V_53 & V_105 ) )
goto V_103;
if ( ! V_32 ) {
V_32 = F_75 ( sizeof( * V_32 ) , V_57 ) ;
if ( ! V_32 )
goto V_103;
V_30 = & V_32 -> V_30 ;
F_7 ( V_30 -> V_14 , V_161 ) ;
V_30 -> V_9 = V_9 ;
V_30 -> V_53 = V_53 ;
V_32 -> V_112 = 0 ;
if ( V_53 & V_100 )
V_32 -> V_112 = V_97 ;
F_66 ( & V_30 -> V_23 , 2 ) ;
V_30 -> V_107 = V_97 ;
F_100 ( & V_32 -> V_111 ) ;
F_66 ( & V_32 -> V_36 , 0 ) ;
F_101 ( & V_32 -> V_156 ) ;
V_87 = F_67 ( V_26 -> V_12 . V_33 ,
F_1 ,
F_4 , V_30 ,
& V_30 -> V_6 ) ;
if ( F_68 ( V_87 != 0 ) ) {
F_17 ( V_32 ) ;
goto V_165;
}
} else {
V_30 = & V_32 -> V_30 ;
if ( V_53 & V_164 ) {
if ( ! ( V_30 -> V_53 & V_164 ) )
goto V_103;
if ( F_94 ( V_32 ,
V_42 ) )
goto V_165;
F_18 ( V_32 ) ;
goto V_166;
}
if ( V_30 -> V_53 & V_164 ) {
F_18 ( V_32 ) ;
V_30 -> V_53 &= ~ V_164 ;
}
V_30 -> V_53 |= V_53 ;
if ( V_30 -> V_53 & V_100 ) {
F_18 ( V_32 ) ;
V_30 -> V_53 &= ~ V_100 ;
V_32 -> V_112 = 0 ;
}
}
V_166:
F_95 ( V_32 , V_42 , V_123 ) ;
F_56 ( V_80 , V_26 ,
L_19 ,
V_30 -> V_14 , F_57 ( V_30 -> V_9 ) ,
V_42 -> V_163 ) ;
V_90 = true ;
V_165:
if ( F_62 ( V_161 ) )
goto V_103;
V_162 = F_83 ( V_26 , V_161 , V_9 ,
L_20 ,
V_53 & V_100 ) ;
V_32 -> V_30 . V_53 |= V_162 & V_106 ;
if ( ! ( V_53 & V_100 ) )
V_32 -> V_30 . V_53 &= ~ V_100 ;
V_103:
if ( V_32 )
F_17 ( V_32 ) ;
if ( V_28 )
F_14 ( V_28 ) ;
return V_90 ;
}
static struct V_46 *
F_102 ( struct V_25 * V_26 ,
struct V_31 * V_32 )
{
struct V_167 * V_168 , * V_169 = NULL ;
struct V_170 * V_171 = V_26 -> V_172 ;
struct V_17 * V_18 ;
struct V_46 * V_47 , * V_173 = NULL ;
V_18 = & V_32 -> V_111 ;
F_9 (orig_entry, head, list) {
V_168 = F_103 ( V_47 -> V_42 ,
V_174 ) ;
if ( ! V_168 )
continue;
if ( V_169 &&
V_171 -> V_175 ( V_168 , V_174 ,
V_169 , V_174 ) <= 0 ) {
F_104 ( V_168 ) ;
continue;
}
if ( V_169 )
F_104 ( V_169 ) ;
V_173 = V_47 ;
V_169 = V_168 ;
}
if ( V_169 )
F_104 ( V_169 ) ;
return V_173 ;
}
static void
F_105 ( struct V_25 * V_26 ,
struct V_31 * V_32 ,
struct V_137 * V_138 )
{
struct V_46 * V_47 , * V_173 ;
struct V_5 * V_27 ;
struct V_43 * V_39 ;
struct V_17 * V_18 ;
T_2 V_124 ;
T_3 V_53 ;
V_27 = & V_32 -> V_30 ;
V_53 = V_27 -> V_53 ;
V_173 = F_102 ( V_26 , V_32 ) ;
if ( V_173 ) {
V_39 = F_106 ( V_173 -> V_42 ,
V_27 -> V_9 ) ;
if ( ! V_39 ) {
F_79 ( V_138 ,
L_21 ,
F_57 ( V_27 -> V_9 ) ,
V_173 -> V_42 -> V_163 ) ;
goto V_176;
}
V_124 = F_20 ( & V_173 -> V_42 -> V_124 ) ;
F_79 ( V_138 ,
L_22 ,
'*' , V_32 -> V_30 . V_14 ,
F_57 ( V_32 -> V_30 . V_9 ) ,
V_173 -> V_123 , V_173 -> V_42 -> V_163 ,
V_124 , V_39 -> V_12 . V_125 ,
( ( V_53 & V_100 ) ? 'R' : '.' ) ,
( ( V_53 & V_106 ) ? 'W' : '.' ) ,
( ( V_53 & V_116 ) ? 'I' : '.' ) ,
( ( V_53 & V_164 ) ? 'T' : '.' ) ) ;
F_33 ( V_39 ) ;
}
V_176:
V_18 = & V_32 -> V_111 ;
F_9 (orig_entry, head, list) {
if ( V_173 == V_47 )
continue;
V_39 = F_106 ( V_47 -> V_42 ,
V_27 -> V_9 ) ;
if ( ! V_39 ) {
F_79 ( V_138 ,
L_23 ,
F_57 ( V_27 -> V_9 ) ,
V_47 -> V_42 -> V_163 ) ;
continue;
}
V_124 = F_20 ( & V_47 -> V_42 -> V_124 ) ;
F_79 ( V_138 ,
L_24 ,
'+' , V_32 -> V_30 . V_14 ,
F_57 ( V_32 -> V_30 . V_9 ) ,
V_47 -> V_123 , V_47 -> V_42 -> V_163 ,
V_124 , V_39 -> V_12 . V_125 ,
( ( V_53 & V_100 ) ? 'R' : '.' ) ,
( ( V_53 & V_106 ) ? 'W' : '.' ) ,
( ( V_53 & V_116 ) ? 'I' : '.' ) ,
( ( V_53 & V_164 ) ? 'T' : '.' ) ) ;
F_33 ( V_39 ) ;
}
}
int F_107 ( struct V_137 * V_138 , void * V_139 )
{
struct V_81 * V_140 = (struct V_81 * ) V_138 -> V_141 ;
struct V_25 * V_26 = F_60 ( V_140 ) ;
struct V_16 * V_13 = V_26 -> V_12 . V_33 ;
struct V_5 * V_27 ;
struct V_31 * V_78 ;
struct V_142 * V_143 ;
struct V_17 * V_18 ;
T_1 V_144 ;
V_143 = F_78 ( V_138 ) ;
if ( ! V_143 )
goto V_103;
F_79 ( V_138 ,
L_25 ,
V_140 -> V_150 ) ;
F_79 ( V_138 , L_26 ,
L_10 , L_11 , L_27 , L_28 , L_29 ,
L_14 , L_12 ) ;
for ( V_144 = 0 ; V_144 < V_13 -> V_11 ; V_144 ++ ) {
V_18 = & V_13 -> V_22 [ V_144 ] ;
F_8 () ;
F_9 (tt_common_entry,
head, hash_entry) {
V_78 = F_2 ( V_27 ,
struct V_31 ,
V_30 ) ;
F_105 ( V_26 , V_78 , V_138 ) ;
}
F_11 () ;
}
V_103:
if ( V_143 )
F_81 ( V_143 ) ;
return 0 ;
}
static void
F_108 ( struct V_31 * V_32 ,
struct V_46 * V_47 )
{
F_109 ( & V_32 -> V_156 ) ;
F_36 ( V_47 -> V_42 ,
V_32 -> V_30 . V_9 ) ;
F_47 ( & V_32 -> V_36 ) ;
F_89 ( & V_47 -> V_45 ) ;
F_39 ( V_47 ) ;
}
static void
F_18 ( struct V_31 * V_32 )
{
struct V_17 * V_18 ;
struct V_1 * V_52 ;
struct V_46 * V_47 ;
F_30 ( & V_32 -> V_156 ) ;
V_18 = & V_32 -> V_111 ;
F_85 (orig_entry, safe, head, list)
F_108 ( V_32 , V_47 ) ;
F_34 ( & V_32 -> V_156 ) ;
}
static void
F_110 ( struct V_25 * V_26 ,
struct V_31 * V_32 ,
struct V_41 * V_42 ,
const char * V_79 )
{
struct V_17 * V_18 ;
struct V_1 * V_52 ;
struct V_46 * V_47 ;
unsigned short V_9 ;
F_30 ( & V_32 -> V_156 ) ;
V_18 = & V_32 -> V_111 ;
F_85 (orig_entry, safe, head, list) {
if ( V_47 -> V_42 == V_42 ) {
V_9 = V_32 -> V_30 . V_9 ;
F_56 ( V_80 , V_26 ,
L_30 ,
V_42 -> V_163 ,
V_32 -> V_30 . V_14 ,
F_57 ( V_9 ) , V_79 ) ;
F_108 ( V_32 ,
V_47 ) ;
}
}
F_34 ( & V_32 -> V_156 ) ;
}
static void
F_111 ( struct V_25 * V_26 ,
struct V_31 * V_32 ,
struct V_41 * V_42 ,
const char * V_79 )
{
bool V_177 = true ;
struct V_17 * V_18 ;
struct V_46 * V_47 ;
F_8 () ;
V_18 = & V_32 -> V_111 ;
F_9 (orig_entry, head, list) {
if ( V_47 -> V_42 != V_42 ) {
V_177 = false ;
break;
}
}
F_11 () ;
if ( V_177 ) {
V_32 -> V_30 . V_53 |= V_100 ;
V_32 -> V_112 = V_97 ;
} else
F_110 ( V_26 , V_32 ,
V_42 , V_79 ) ;
}
static void F_112 ( struct V_25 * V_26 ,
struct V_41 * V_42 ,
const unsigned char * V_14 , unsigned short V_9 ,
const char * V_79 , bool V_151 )
{
struct V_31 * V_32 ;
struct V_24 * V_178 = NULL ;
V_32 = F_13 ( V_26 , V_14 , V_9 ) ;
if ( ! V_32 )
goto V_103;
if ( ! V_151 ) {
F_110 ( V_26 , V_32 ,
V_42 , V_79 ) ;
if ( F_113 ( & V_32 -> V_111 ) )
F_55 ( V_26 , V_32 ,
V_79 ) ;
goto V_103;
}
V_178 = F_12 ( V_26 ,
V_32 -> V_30 . V_14 ,
V_9 ) ;
if ( V_178 ) {
F_18 ( V_32 ) ;
F_55 ( V_26 , V_32 , V_79 ) ;
} else
F_111 ( V_26 , V_32 ,
V_42 , V_79 ) ;
V_103:
if ( V_32 )
F_17 ( V_32 ) ;
if ( V_178 )
F_14 ( V_178 ) ;
}
void F_114 ( struct V_25 * V_26 ,
struct V_41 * V_42 ,
T_4 V_179 ,
const char * V_79 )
{
struct V_31 * V_78 ;
struct V_5 * V_27 ;
T_1 V_144 ;
struct V_16 * V_13 = V_26 -> V_12 . V_33 ;
struct V_1 * V_52 ;
struct V_17 * V_18 ;
T_5 * V_156 ;
unsigned short V_9 ;
if ( ! V_13 )
return;
for ( V_144 = 0 ; V_144 < V_13 -> V_11 ; V_144 ++ ) {
V_18 = & V_13 -> V_22 [ V_144 ] ;
V_156 = & V_13 -> V_157 [ V_144 ] ;
F_30 ( V_156 ) ;
F_85 (tt_common_entry, safe,
head, hash_entry) {
if ( V_179 >= 0 && V_27 -> V_9 != V_179 )
continue;
V_78 = F_2 ( V_27 ,
struct V_31 ,
V_30 ) ;
F_110 ( V_26 , V_78 ,
V_42 , V_79 ) ;
if ( F_113 ( & V_78 -> V_111 ) ) {
V_9 = V_78 -> V_30 . V_9 ;
F_56 ( V_80 , V_26 ,
L_1 ,
V_78 -> V_30 . V_14 ,
F_57 ( V_9 ) , V_79 ) ;
F_89 ( & V_27 -> V_6 ) ;
F_17 ( V_78 ) ;
}
}
F_34 ( V_156 ) ;
}
F_115 ( V_180 , & V_42 -> V_181 ) ;
}
static bool F_116 ( struct V_31 * V_78 ,
char * * V_182 )
{
bool V_183 = false ;
unsigned long V_184 = V_185 ;
unsigned long V_186 = V_187 ;
if ( ( V_78 -> V_30 . V_53 & V_100 ) &&
F_86 ( V_78 -> V_112 , V_184 ) ) {
V_183 = true ;
* V_182 = L_31 ;
}
if ( ( V_78 -> V_30 . V_53 & V_164 ) &&
F_86 ( V_78 -> V_30 . V_107 , V_186 ) ) {
V_183 = true ;
* V_182 = L_32 ;
}
return V_183 ;
}
static void F_117 ( struct V_25 * V_26 )
{
struct V_16 * V_13 = V_26 -> V_12 . V_33 ;
struct V_17 * V_18 ;
struct V_1 * V_155 ;
T_5 * V_156 ;
T_1 V_144 ;
char * V_182 = NULL ;
struct V_5 * V_188 ;
struct V_31 * V_78 ;
for ( V_144 = 0 ; V_144 < V_13 -> V_11 ; V_144 ++ ) {
V_18 = & V_13 -> V_22 [ V_144 ] ;
V_156 = & V_13 -> V_157 [ V_144 ] ;
F_30 ( V_156 ) ;
F_85 (tt_common, node_tmp, head,
hash_entry) {
V_78 = F_2 ( V_188 ,
struct V_31 ,
V_30 ) ;
if ( ! F_116 ( V_78 , & V_182 ) )
continue;
F_56 ( V_80 , V_26 ,
L_1 ,
V_78 -> V_30 . V_14 ,
F_57 ( V_78 -> V_30 . V_9 ) ,
V_182 ) ;
F_89 ( & V_188 -> V_6 ) ;
F_17 ( V_78 ) ;
}
F_34 ( V_156 ) ;
}
}
static void F_118 ( struct V_25 * V_26 )
{
struct V_16 * V_13 ;
T_5 * V_156 ;
struct V_5 * V_27 ;
struct V_31 * V_78 ;
struct V_1 * V_155 ;
struct V_17 * V_18 ;
T_1 V_144 ;
if ( ! V_26 -> V_12 . V_33 )
return;
V_13 = V_26 -> V_12 . V_33 ;
for ( V_144 = 0 ; V_144 < V_13 -> V_11 ; V_144 ++ ) {
V_18 = & V_13 -> V_22 [ V_144 ] ;
V_156 = & V_13 -> V_157 [ V_144 ] ;
F_30 ( V_156 ) ;
F_85 (tt_common_entry, node_tmp,
head, hash_entry) {
F_89 ( & V_27 -> V_6 ) ;
V_78 = F_2 ( V_27 ,
struct V_31 ,
V_30 ) ;
F_17 ( V_78 ) ;
}
F_34 ( V_156 ) ;
}
F_90 ( V_13 ) ;
V_26 -> V_12 . V_33 = NULL ;
}
static bool
F_119 ( struct V_24 * V_28 ,
struct V_31 * V_32 )
{
bool V_90 = false ;
if ( V_28 -> V_30 . V_53 & V_106 &&
V_32 -> V_30 . V_53 & V_106 )
V_90 = true ;
if ( V_28 -> V_30 . V_53 & V_116 &&
V_32 -> V_30 . V_53 & V_116 )
V_90 = true ;
return V_90 ;
}
struct V_41 * F_120 ( struct V_25 * V_26 ,
const T_2 * V_189 ,
const T_2 * V_14 ,
unsigned short V_9 )
{
struct V_24 * V_28 = NULL ;
struct V_31 * V_32 = NULL ;
struct V_41 * V_42 = NULL ;
struct V_46 * V_173 ;
if ( V_189 && F_121 ( V_26 , V_9 ) ) {
V_28 = F_12 ( V_26 , V_189 , V_9 ) ;
if ( ! V_28 ||
( V_28 -> V_30 . V_53 & V_98 ) )
goto V_103;
}
V_32 = F_13 ( V_26 , V_14 , V_9 ) ;
if ( ! V_32 )
goto V_103;
if ( V_28 &&
F_119 ( V_28 , V_32 ) )
goto V_103;
F_8 () ;
V_173 = F_102 ( V_26 , V_32 ) ;
if ( V_173 )
V_42 = V_173 -> V_42 ;
if ( V_42 && ! F_10 ( & V_42 -> V_23 ) )
V_42 = NULL ;
F_11 () ;
V_103:
if ( V_32 )
F_17 ( V_32 ) ;
if ( V_28 )
F_14 ( V_28 ) ;
return V_42 ;
}
static T_1 F_122 ( struct V_25 * V_26 ,
struct V_41 * V_42 ,
unsigned short V_9 )
{
struct V_16 * V_13 = V_26 -> V_12 . V_33 ;
struct V_5 * V_188 ;
struct V_31 * V_78 ;
struct V_17 * V_18 ;
T_1 V_144 , V_190 , V_125 = 0 ;
T_2 V_53 ;
T_6 V_191 ;
for ( V_144 = 0 ; V_144 < V_13 -> V_11 ; V_144 ++ ) {
V_18 = & V_13 -> V_22 [ V_144 ] ;
F_8 () ;
F_9 (tt_common, head, hash_entry) {
V_78 = F_2 ( V_188 ,
struct V_31 ,
V_30 ) ;
if ( V_188 -> V_9 != V_9 )
continue;
if ( V_188 -> V_53 & V_100 )
continue;
if ( V_188 -> V_53 & V_164 )
continue;
if ( ! F_94 ( V_78 ,
V_42 ) )
continue;
V_191 = F_42 ( V_188 -> V_9 ) ;
V_190 = F_123 ( 0 , & V_191 , sizeof( V_191 ) ) ;
V_53 = V_188 -> V_53 & V_192 ;
V_190 = F_123 ( V_190 , & V_53 , sizeof( V_53 ) ) ;
V_125 ^= F_123 ( V_190 , V_188 -> V_14 , V_15 ) ;
}
F_11 () ;
}
return V_125 ;
}
static T_1 F_124 ( struct V_25 * V_26 ,
unsigned short V_9 )
{
struct V_16 * V_13 = V_26 -> V_12 . V_29 ;
struct V_5 * V_188 ;
struct V_17 * V_18 ;
T_1 V_144 , V_190 , V_125 = 0 ;
T_2 V_53 ;
T_6 V_191 ;
for ( V_144 = 0 ; V_144 < V_13 -> V_11 ; V_144 ++ ) {
V_18 = & V_13 -> V_22 [ V_144 ] ;
F_8 () ;
F_9 (tt_common, head, hash_entry) {
if ( V_188 -> V_9 != V_9 )
continue;
if ( V_188 -> V_53 & V_105 )
continue;
V_191 = F_42 ( V_188 -> V_9 ) ;
V_190 = F_123 ( 0 , & V_191 , sizeof( V_191 ) ) ;
V_53 = V_188 -> V_53 & V_192 ;
V_190 = F_123 ( V_190 , & V_53 , sizeof( V_53 ) ) ;
V_125 ^= F_123 ( V_190 , V_188 -> V_14 , V_15 ) ;
}
F_11 () ;
}
return V_125 ;
}
static void F_125 ( struct V_25 * V_26 )
{
struct V_193 * V_2 ;
struct V_1 * V_52 ;
F_30 ( & V_26 -> V_12 . V_194 ) ;
F_85 (node, safe, &bat_priv->tt.req_list, list) {
F_126 ( & V_2 -> V_45 ) ;
F_45 ( V_2 ) ;
}
F_34 ( & V_26 -> V_12 . V_194 ) ;
}
static void F_127 ( struct V_25 * V_26 ,
struct V_41 * V_42 ,
const void * V_195 ,
T_3 V_196 )
{
F_30 ( & V_42 -> V_197 ) ;
if ( V_196 > 0 ) {
F_45 ( V_42 -> V_195 ) ;
V_42 -> V_196 = 0 ;
V_42 -> V_195 = F_41 ( V_196 , V_57 ) ;
if ( V_42 -> V_195 ) {
memcpy ( V_42 -> V_195 , V_195 , V_196 ) ;
V_42 -> V_196 = V_196 ;
}
}
F_34 ( & V_42 -> V_197 ) ;
}
static void F_128 ( struct V_25 * V_26 )
{
struct V_193 * V_2 ;
struct V_1 * V_52 ;
F_30 ( & V_26 -> V_12 . V_194 ) ;
F_85 (node, safe, &bat_priv->tt.req_list, list) {
if ( F_86 ( V_2 -> V_198 ,
V_199 ) ) {
F_126 ( & V_2 -> V_45 ) ;
F_45 ( V_2 ) ;
}
}
F_34 ( & V_26 -> V_12 . V_194 ) ;
}
static struct V_193 *
F_129 ( struct V_25 * V_26 ,
struct V_41 * V_42 )
{
struct V_193 * V_200 , * V_201 = NULL ;
F_30 ( & V_26 -> V_12 . V_194 ) ;
F_130 (tt_req_node_tmp, &bat_priv->tt.req_list, list) {
if ( F_3 ( V_200 , V_42 ) &&
! F_86 ( V_200 -> V_198 ,
V_199 ) )
goto V_63;
}
V_201 = F_41 ( sizeof( * V_201 ) , V_57 ) ;
if ( ! V_201 )
goto V_63;
F_7 ( V_201 -> V_14 , V_42 -> V_163 ) ;
V_201 -> V_198 = V_97 ;
F_131 ( & V_201 -> V_45 , & V_26 -> V_12 . V_202 ) ;
V_63:
F_34 ( & V_26 -> V_12 . V_194 ) ;
return V_201 ;
}
static int F_132 ( const void * V_203 , const void * V_204 )
{
const struct V_5 * V_27 = V_203 ;
if ( V_27 -> V_53 & V_105 )
return 0 ;
return 1 ;
}
static int F_133 ( const void * V_203 ,
const void * V_204 )
{
const struct V_5 * V_27 = V_203 ;
const struct V_31 * V_32 ;
const struct V_41 * V_42 = V_204 ;
if ( V_27 -> V_53 & V_100 ||
V_27 -> V_53 & V_164 )
return 0 ;
V_32 = F_2 ( V_27 ,
struct V_31 ,
V_30 ) ;
return F_94 ( V_32 , V_42 ) ;
}
static void F_134 ( struct V_25 * V_26 ,
struct V_16 * V_13 ,
void * V_205 , T_3 V_68 ,
int (* F_135)( const void * , const void * ) ,
void * V_206 )
{
struct V_5 * V_27 ;
struct V_67 * V_118 ;
struct V_17 * V_18 ;
T_3 V_207 , V_208 = 0 ;
T_1 V_144 ;
V_207 = F_50 ( V_68 ) ;
V_118 = (struct V_67 * ) V_205 ;
F_8 () ;
for ( V_144 = 0 ; V_144 < V_13 -> V_11 ; V_144 ++ ) {
V_18 = & V_13 -> V_22 [ V_144 ] ;
F_9 (tt_common_entry,
head, hash_entry) {
if ( V_207 == V_208 )
break;
if ( ( F_135 ) && ( ! F_135 ( V_27 , V_206 ) ) )
continue;
F_7 ( V_118 -> V_14 , V_27 -> V_14 ) ;
V_118 -> V_53 = V_27 -> V_53 ;
V_118 -> V_9 = F_42 ( V_27 -> V_9 ) ;
memset ( V_118 -> V_59 , 0 ,
sizeof( V_118 -> V_59 ) ) ;
V_208 ++ ;
V_118 ++ ;
}
}
F_11 () ;
}
static bool F_136 ( struct V_41 * V_42 ,
struct V_75 * V_121 ,
T_3 V_69 )
{
struct V_75 * V_209 ;
struct V_43 * V_39 ;
int V_144 , V_210 ;
T_1 V_125 ;
for ( V_144 = 0 ; V_144 < V_69 ; V_144 ++ ) {
V_209 = V_121 + V_144 ;
if ( F_99 ( V_42 -> V_26 ,
V_42 -> V_163 ,
F_137 ( V_209 -> V_9 ) ) )
continue;
V_39 = F_106 ( V_42 ,
F_137 ( V_209 -> V_9 ) ) ;
if ( ! V_39 )
return false ;
V_125 = V_39 -> V_12 . V_125 ;
F_33 ( V_39 ) ;
if ( V_125 != F_138 ( V_209 -> V_125 ) )
return false ;
}
F_8 () ;
V_210 = 0 ;
F_9 (vlan, &orig_node->vlan_list, list)
V_210 ++ ;
F_11 () ;
if ( V_210 > V_69 )
return false ;
return true ;
}
static void F_139 ( struct V_25 * V_26 )
{
struct V_38 * V_39 ;
F_8 () ;
F_9 (vlan, &bat_priv->softif_vlan_list, list) {
V_39 -> V_12 . V_125 = F_124 ( V_26 , V_39 -> V_9 ) ;
}
F_11 () ;
}
static void F_140 ( struct V_25 * V_26 ,
struct V_41 * V_42 )
{
struct V_43 * V_39 ;
T_1 V_125 ;
F_8 () ;
F_9 (vlan, &orig_node->vlan_list, list) {
if ( F_99 ( V_26 , V_42 -> V_163 ,
V_39 -> V_9 ) )
continue;
V_125 = F_122 ( V_26 , V_42 , V_39 -> V_9 ) ;
V_39 -> V_12 . V_125 = V_125 ;
}
F_11 () ;
}
static int F_141 ( struct V_25 * V_26 ,
struct V_41 * V_211 ,
T_2 V_123 ,
struct V_75 * V_121 ,
T_3 V_69 , bool V_212 )
{
struct V_74 * V_213 = NULL ;
struct V_193 * V_201 = NULL ;
struct V_75 * V_214 ;
struct V_142 * V_143 ;
bool V_90 = false ;
int V_144 , V_11 ;
V_143 = F_142 ( V_26 ) ;
if ( ! V_143 )
goto V_103;
V_201 = F_129 ( V_26 , V_211 ) ;
if ( ! V_201 )
goto V_103;
V_11 = sizeof( * V_213 ) + sizeof( * V_214 ) * V_69 ;
V_213 = F_75 ( V_11 , V_57 ) ;
if ( ! V_213 )
goto V_103;
V_213 -> V_53 = V_215 ;
V_213 -> V_123 = V_123 ;
V_213 -> V_69 = F_42 ( V_69 ) ;
V_214 = (struct V_75 * ) ( V_213 + 1 ) ;
for ( V_144 = 0 ; V_144 < V_69 ; V_144 ++ ) {
V_214 -> V_9 = V_121 -> V_9 ;
V_214 -> V_125 = V_121 -> V_125 ;
V_214 ++ ;
V_121 ++ ;
}
if ( V_212 )
V_213 -> V_53 |= V_216 ;
F_56 ( V_80 , V_26 , L_33 ,
V_211 -> V_163 , V_212 ? 'F' : '.' ) ;
F_143 ( V_26 , V_217 ) ;
F_144 ( V_26 , V_143 -> V_140 -> V_108 ,
V_211 -> V_163 , V_136 , 1 ,
V_213 , V_11 ) ;
V_90 = true ;
V_103:
if ( V_143 )
F_81 ( V_143 ) ;
if ( V_90 && V_201 ) {
F_30 ( & V_26 -> V_12 . V_194 ) ;
F_126 ( & V_201 -> V_45 ) ;
F_34 ( & V_26 -> V_12 . V_194 ) ;
F_45 ( V_201 ) ;
}
F_45 ( V_213 ) ;
return V_90 ;
}
static bool F_145 ( struct V_25 * V_26 ,
struct V_74 * V_117 ,
T_2 * V_218 , T_2 * V_219 )
{
struct V_41 * V_220 ;
struct V_41 * V_221 = NULL ;
struct V_67 * V_118 ;
struct V_74 * V_213 = NULL ;
struct V_75 * V_121 ;
bool V_90 = false , V_212 ;
T_2 V_222 , V_223 ;
T_3 V_120 ;
T_4 V_68 ;
F_56 ( V_80 , V_26 ,
L_34 ,
V_218 , V_117 -> V_123 , V_219 ,
( ( V_117 -> V_53 & V_216 ) ? 'F' : '.' ) ) ;
V_220 = F_146 ( V_26 , V_219 ) ;
if ( ! V_220 )
goto V_103;
V_221 = F_146 ( V_26 , V_218 ) ;
if ( ! V_221 )
goto V_103;
V_222 = ( T_2 ) F_20 ( & V_220 -> V_124 ) ;
V_223 = V_117 -> V_123 ;
V_121 = (struct V_75 * ) ( V_117 + 1 ) ;
if ( V_222 != V_223 ||
! F_136 ( V_220 , V_121 ,
F_137 ( V_117 -> V_69 ) ) )
goto V_103;
if ( V_117 -> V_53 & V_216 ||
! V_220 -> V_195 )
V_212 = true ;
else
V_212 = false ;
if ( ! V_212 ) {
F_30 ( & V_220 -> V_197 ) ;
V_68 = V_220 -> V_196 ;
V_120 = F_71 ( V_220 ,
& V_213 ,
& V_118 ,
& V_68 ) ;
if ( ! V_68 )
goto V_63;
memcpy ( V_118 , V_220 -> V_195 ,
V_220 -> V_196 ) ;
F_34 ( & V_220 -> V_197 ) ;
} else {
V_68 = - 1 ;
V_120 = F_71 ( V_220 ,
& V_213 ,
& V_118 ,
& V_68 ) ;
if ( ! V_68 )
goto V_103;
F_134 ( V_26 , V_26 -> V_12 . V_33 ,
V_118 , V_68 ,
F_133 ,
V_220 ) ;
}
V_68 = sizeof( struct V_72 ) + V_120 ;
if ( V_68 > F_20 ( & V_26 -> V_89 ) ) {
F_63 ( V_102 , V_26 -> V_82 ,
L_35 ,
V_221 -> V_163 ) ;
goto V_103;
}
V_213 -> V_53 = V_224 ;
V_213 -> V_123 = V_223 ;
if ( V_212 )
V_213 -> V_53 |= V_216 ;
F_56 ( V_80 , V_26 ,
L_36 ,
V_221 -> V_163 , V_220 -> V_163 ,
V_212 ? 'F' : '.' , V_223 ) ;
F_143 ( V_26 , V_225 ) ;
F_144 ( V_26 , V_220 -> V_163 ,
V_218 , V_136 , 1 , V_213 ,
V_120 ) ;
V_90 = true ;
goto V_103;
V_63:
F_34 ( & V_220 -> V_197 ) ;
V_103:
if ( V_221 )
F_38 ( V_221 ) ;
if ( V_220 )
F_38 ( V_220 ) ;
F_45 ( V_213 ) ;
return V_90 ;
}
static bool F_147 ( struct V_25 * V_26 ,
struct V_74 * V_117 ,
T_2 * V_218 )
{
struct V_74 * V_213 = NULL ;
struct V_142 * V_143 = NULL ;
struct V_67 * V_118 ;
struct V_41 * V_42 ;
T_2 V_226 , V_223 ;
T_3 V_120 ;
bool V_212 ;
T_4 V_68 ;
F_56 ( V_80 , V_26 ,
L_37 ,
V_218 , V_117 -> V_123 ,
( ( V_117 -> V_53 & V_216 ) ? 'F' : '.' ) ) ;
F_30 ( & V_26 -> V_12 . V_227 ) ;
V_226 = ( T_2 ) F_20 ( & V_26 -> V_12 . V_104 ) ;
V_223 = V_117 -> V_123 ;
V_42 = F_146 ( V_26 , V_218 ) ;
if ( ! V_42 )
goto V_103;
V_143 = F_142 ( V_26 ) ;
if ( ! V_143 )
goto V_103;
if ( V_117 -> V_53 & V_216 || V_226 != V_223 ||
! V_26 -> V_12 . V_134 )
V_212 = true ;
else
V_212 = false ;
if ( ! V_212 ) {
F_30 ( & V_26 -> V_12 . V_133 ) ;
V_68 = V_26 -> V_12 . V_135 ;
V_120 = F_73 ( V_26 ,
& V_213 ,
& V_118 ,
& V_68 ) ;
if ( ! V_68 )
goto V_63;
memcpy ( V_118 , V_26 -> V_12 . V_134 ,
V_26 -> V_12 . V_135 ) ;
F_34 ( & V_26 -> V_12 . V_133 ) ;
} else {
V_223 = ( T_2 ) F_20 ( & V_26 -> V_12 . V_104 ) ;
V_68 = - 1 ;
V_120 = F_73 ( V_26 ,
& V_213 ,
& V_118 ,
& V_68 ) ;
if ( ! V_68 )
goto V_103;
F_134 ( V_26 , V_26 -> V_12 . V_29 ,
V_118 , V_68 ,
F_132 , NULL ) ;
}
V_213 -> V_53 = V_224 ;
V_213 -> V_123 = V_223 ;
if ( V_212 )
V_213 -> V_53 |= V_216 ;
F_56 ( V_80 , V_26 ,
L_38 ,
V_42 -> V_163 , V_212 ? 'F' : '.' , V_223 ) ;
F_143 ( V_26 , V_225 ) ;
F_144 ( V_26 , V_143 -> V_140 -> V_108 ,
V_218 , V_136 , 1 , V_213 ,
V_120 ) ;
goto V_103;
V_63:
F_34 ( & V_26 -> V_12 . V_133 ) ;
V_103:
F_34 ( & V_26 -> V_12 . V_227 ) ;
if ( V_42 )
F_38 ( V_42 ) ;
if ( V_143 )
F_81 ( V_143 ) ;
F_45 ( V_213 ) ;
return true ;
}
static bool F_148 ( struct V_25 * V_26 ,
struct V_74 * V_117 ,
T_2 * V_218 , T_2 * V_219 )
{
if ( F_149 ( V_26 , V_219 ) )
return F_147 ( V_26 , V_117 , V_218 ) ;
return F_145 ( V_26 , V_117 , V_218 ,
V_219 ) ;
}
static void F_150 ( struct V_25 * V_26 ,
struct V_41 * V_42 ,
struct V_67 * V_118 ,
T_3 V_228 , T_2 V_123 )
{
int V_144 ;
int V_229 ;
for ( V_144 = 0 ; V_144 < V_228 ; V_144 ++ ) {
if ( ( V_118 + V_144 ) -> V_53 & V_60 ) {
V_229 = ( V_118 + V_144 ) -> V_53 & V_100 ;
F_112 ( V_26 , V_42 ,
( V_118 + V_144 ) -> V_14 ,
F_137 ( ( V_118 + V_144 ) -> V_9 ) ,
L_39 ,
V_229 ) ;
} else {
if ( ! F_98 ( V_26 , V_42 ,
( V_118 + V_144 ) -> V_14 ,
F_137 ( ( V_118 + V_144 ) -> V_9 ) ,
( V_118 + V_144 ) -> V_53 , V_123 ) )
return;
}
}
F_151 ( V_180 , & V_42 -> V_181 ) ;
}
static void F_152 ( struct V_25 * V_26 ,
struct V_67 * V_118 ,
T_2 V_123 , T_2 * V_230 ,
T_3 V_40 )
{
struct V_41 * V_42 ;
V_42 = F_146 ( V_26 , V_230 ) ;
if ( ! V_42 )
goto V_103;
F_114 ( V_26 , V_42 , - 1 ,
L_40 ) ;
F_150 ( V_26 , V_42 , V_118 , V_40 ,
V_123 ) ;
F_30 ( & V_42 -> V_197 ) ;
F_45 ( V_42 -> V_195 ) ;
V_42 -> V_196 = 0 ;
V_42 -> V_195 = NULL ;
F_34 ( & V_42 -> V_197 ) ;
F_66 ( & V_42 -> V_124 , V_123 ) ;
V_103:
if ( V_42 )
F_38 ( V_42 ) ;
}
static void F_153 ( struct V_25 * V_26 ,
struct V_41 * V_42 ,
T_3 V_228 , T_2 V_123 ,
struct V_67 * V_118 )
{
F_150 ( V_26 , V_42 , V_118 ,
V_228 , V_123 ) ;
F_127 ( V_26 , V_42 , V_118 ,
F_49 ( V_228 ) ) ;
F_66 ( & V_42 -> V_124 , V_123 ) ;
}
bool F_154 ( struct V_25 * V_26 , const T_2 * V_14 ,
unsigned short V_9 )
{
struct V_24 * V_28 ;
bool V_90 = false ;
V_28 = F_12 ( V_26 , V_14 , V_9 ) ;
if ( ! V_28 )
goto V_103;
if ( ( V_28 -> V_30 . V_53 & V_98 ) ||
( V_28 -> V_30 . V_53 & V_100 ) )
goto V_103;
V_90 = true ;
V_103:
if ( V_28 )
F_14 ( V_28 ) ;
return V_90 ;
}
static void F_155 ( struct V_25 * V_26 ,
struct V_74 * V_117 ,
T_2 * V_230 , T_3 V_40 )
{
struct V_193 * V_2 ;
struct V_1 * V_52 ;
struct V_41 * V_42 = NULL ;
struct V_67 * V_118 ;
T_2 * V_231 = ( T_2 * ) V_117 ;
T_3 V_119 ;
F_56 ( V_80 , V_26 ,
L_41 ,
V_230 , V_117 -> V_123 , V_40 ,
( ( V_117 -> V_53 & V_216 ) ? 'F' : '.' ) ) ;
V_42 = F_146 ( V_26 , V_230 ) ;
if ( ! V_42 )
goto V_103;
F_30 ( & V_42 -> V_232 ) ;
V_119 = sizeof( struct V_75 ) ;
V_119 *= F_137 ( V_117 -> V_69 ) ;
V_119 += sizeof( * V_117 ) ;
V_231 += V_119 ;
V_118 = (struct V_67 * ) V_231 ;
if ( V_117 -> V_53 & V_216 ) {
F_152 ( V_26 , V_118 , V_117 -> V_123 ,
V_230 , V_40 ) ;
} else {
F_153 ( V_26 , V_42 , V_40 ,
V_117 -> V_123 , V_118 ) ;
}
F_140 ( V_26 , V_42 ) ;
F_34 ( & V_42 -> V_232 ) ;
F_30 ( & V_26 -> V_12 . V_194 ) ;
F_85 (node, safe, &bat_priv->tt.req_list, list) {
if ( ! F_3 ( V_2 -> V_14 , V_230 ) )
continue;
F_126 ( & V_2 -> V_45 ) ;
F_45 ( V_2 ) ;
}
F_34 ( & V_26 -> V_12 . V_194 ) ;
V_103:
if ( V_42 )
F_38 ( V_42 ) ;
}
static void F_156 ( struct V_25 * V_26 )
{
struct V_233 * V_2 , * V_52 ;
F_30 ( & V_26 -> V_12 . V_234 ) ;
F_43 (node, safe, &bat_priv->tt.roam_list, list) {
F_44 ( & V_2 -> V_45 ) ;
F_45 ( V_2 ) ;
}
F_34 ( & V_26 -> V_12 . V_234 ) ;
}
static void F_157 ( struct V_25 * V_26 )
{
struct V_233 * V_2 , * V_52 ;
F_30 ( & V_26 -> V_12 . V_234 ) ;
F_43 (node, safe, &bat_priv->tt.roam_list, list) {
if ( ! F_86 ( V_2 -> V_235 ,
V_236 ) )
continue;
F_44 ( & V_2 -> V_45 ) ;
F_45 ( V_2 ) ;
}
F_34 ( & V_26 -> V_12 . V_234 ) ;
}
static bool F_158 ( struct V_25 * V_26 , T_2 * V_237 )
{
struct V_233 * V_238 ;
bool V_90 = false ;
F_30 ( & V_26 -> V_12 . V_234 ) ;
F_159 (tt_roam_node, &bat_priv->tt.roam_list, list) {
if ( ! F_3 ( V_238 -> V_14 , V_237 ) )
continue;
if ( F_86 ( V_238 -> V_235 ,
V_236 ) )
continue;
if ( ! F_160 ( & V_238 -> V_239 ) )
goto V_63;
V_90 = true ;
break;
}
if ( ! V_90 ) {
V_238 = F_41 ( sizeof( * V_238 ) , V_57 ) ;
if ( ! V_238 )
goto V_63;
V_238 -> V_235 = V_97 ;
F_66 ( & V_238 -> V_239 ,
V_240 - 1 ) ;
F_7 ( V_238 -> V_14 , V_237 ) ;
F_161 ( & V_238 -> V_45 , & V_26 -> V_12 . V_241 ) ;
V_90 = true ;
}
V_63:
F_34 ( & V_26 -> V_12 . V_234 ) ;
return V_90 ;
}
static void F_69 ( struct V_25 * V_26 , T_2 * V_237 ,
unsigned short V_9 ,
struct V_41 * V_42 )
{
struct V_142 * V_143 ;
struct V_242 V_243 ;
V_143 = F_142 ( V_26 ) ;
if ( ! V_143 )
goto V_103;
if ( ! F_158 ( V_26 , V_237 ) )
goto V_103;
F_56 ( V_80 , V_26 ,
L_42 ,
V_42 -> V_163 , V_237 , F_57 ( V_9 ) ) ;
F_143 ( V_26 , V_244 ) ;
memcpy ( V_243 . V_237 , V_237 , sizeof( V_243 . V_237 ) ) ;
V_243 . V_9 = F_42 ( V_9 ) ;
F_144 ( V_26 , V_143 -> V_140 -> V_108 ,
V_42 -> V_163 , V_245 , 1 ,
& V_243 , sizeof( V_243 ) ) ;
V_103:
if ( V_143 )
F_81 ( V_143 ) ;
}
static void F_162 ( struct V_246 * V_247 )
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
F_157 ( V_26 ) ;
F_163 ( V_252 , & V_26 -> V_12 . V_247 ,
F_164 ( V_253 ) ) ;
}
void F_165 ( struct V_25 * V_26 )
{
F_166 ( V_26 , V_136 , 1 ) ;
F_167 ( V_26 , V_136 , 1 ) ;
F_168 ( & V_26 -> V_12 . V_247 ) ;
F_88 ( V_26 ) ;
F_118 ( V_26 ) ;
F_125 ( V_26 ) ;
F_92 ( V_26 ) ;
F_156 ( V_26 ) ;
F_45 ( V_26 -> V_12 . V_134 ) ;
}
static void F_169 ( struct V_25 * V_26 , T_3 V_53 ,
bool V_254 , bool V_35 )
{
struct V_16 * V_13 = V_26 -> V_12 . V_29 ;
struct V_5 * V_27 ;
T_3 V_255 = 0 ;
struct V_17 * V_18 ;
T_1 V_144 ;
if ( ! V_13 )
return;
for ( V_144 = 0 ; V_144 < V_13 -> V_11 ; V_144 ++ ) {
V_18 = & V_13 -> V_22 [ V_144 ] ;
F_8 () ;
F_9 (tt_common_entry,
head, hash_entry) {
if ( V_254 ) {
if ( ( V_27 -> V_53 & V_53 ) == V_53 )
continue;
V_27 -> V_53 |= V_53 ;
} else {
if ( ! ( V_27 -> V_53 & V_53 ) )
continue;
V_27 -> V_53 &= ~ V_53 ;
}
V_255 ++ ;
if ( ! V_35 )
continue;
F_25 ( V_26 ,
V_27 -> V_9 ) ;
}
F_11 () ;
}
}
static void F_170 ( struct V_25 * V_26 )
{
struct V_16 * V_13 = V_26 -> V_12 . V_29 ;
struct V_5 * V_188 ;
struct V_24 * V_85 ;
struct V_38 * V_39 ;
struct V_1 * V_155 ;
struct V_17 * V_18 ;
T_5 * V_156 ;
T_1 V_144 ;
if ( ! V_13 )
return;
for ( V_144 = 0 ; V_144 < V_13 -> V_11 ; V_144 ++ ) {
V_18 = & V_13 -> V_22 [ V_144 ] ;
V_156 = & V_13 -> V_157 [ V_144 ] ;
F_30 ( V_156 ) ;
F_85 (tt_common, node_tmp, head,
hash_entry) {
if ( ! ( V_188 -> V_53 & V_98 ) )
continue;
F_56 ( V_80 , V_26 ,
L_43 ,
V_188 -> V_14 ,
F_57 ( V_188 -> V_9 ) ) ;
F_26 ( V_26 , V_188 -> V_9 ) ;
F_89 ( & V_188 -> V_6 ) ;
V_85 = F_2 ( V_188 ,
struct V_24 ,
V_30 ) ;
V_39 = F_22 ( V_26 , V_188 -> V_9 ) ;
if ( V_39 ) {
F_24 ( V_39 ) ;
F_24 ( V_39 ) ;
}
F_14 ( V_85 ) ;
}
F_34 ( V_156 ) ;
}
}
static void F_171 ( struct V_25 * V_26 )
{
F_109 ( & V_26 -> V_12 . V_227 ) ;
F_172 ( V_26 ) ;
if ( F_20 ( & V_26 -> V_12 . V_65 ) < 1 ) {
if ( ! F_160 ( & V_26 -> V_12 . V_256 ) )
F_74 ( V_26 ) ;
return;
}
F_169 ( V_26 , V_105 , false , true ) ;
F_170 ( V_26 ) ;
F_139 ( V_26 ) ;
F_48 ( & V_26 -> V_12 . V_104 ) ;
F_56 ( V_80 , V_26 ,
L_44 ,
( T_2 ) F_20 ( & V_26 -> V_12 . V_104 ) ) ;
F_66 ( & V_26 -> V_12 . V_256 , V_257 ) ;
F_74 ( V_26 ) ;
}
void F_173 ( struct V_25 * V_26 )
{
F_30 ( & V_26 -> V_12 . V_227 ) ;
F_171 ( V_26 ) ;
F_34 ( & V_26 -> V_12 . V_227 ) ;
}
bool F_174 ( struct V_25 * V_26 , T_2 * V_189 , T_2 * V_258 ,
unsigned short V_9 )
{
struct V_24 * V_28 = NULL ;
struct V_31 * V_32 = NULL ;
struct V_38 * V_39 ;
bool V_90 = false ;
V_39 = F_22 ( V_26 , V_9 ) ;
if ( ! V_39 )
return false ;
if ( ! F_20 ( & V_39 -> V_259 ) )
goto V_103;
V_28 = F_12 ( V_26 , V_258 , V_9 ) ;
if ( ! V_28 )
goto V_103;
V_32 = F_13 ( V_26 , V_189 , V_9 ) ;
if ( ! V_32 )
goto V_103;
if ( ! F_119 ( V_28 , V_32 ) )
goto V_103;
V_90 = true ;
V_103:
F_24 ( V_39 ) ;
if ( V_32 )
F_17 ( V_32 ) ;
if ( V_28 )
F_14 ( V_28 ) ;
return V_90 ;
}
static void F_175 ( struct V_25 * V_26 ,
struct V_41 * V_42 ,
const void * V_195 , T_3 V_260 ,
struct V_67 * V_118 ,
T_3 V_228 , T_2 V_123 )
{
T_2 V_222 = ( T_2 ) F_20 ( & V_42 -> V_124 ) ;
struct V_75 * V_121 ;
bool V_212 = true ;
bool V_261 ;
V_121 = (struct V_75 * ) V_195 ;
V_261 = F_176 ( V_180 ,
& V_42 -> V_181 ) ;
if ( ( ! V_261 && V_123 == 1 ) || V_123 - V_222 == 1 ) {
if ( ! V_228 ) {
V_212 = false ;
goto V_262;
}
F_30 ( & V_42 -> V_232 ) ;
F_153 ( V_26 , V_42 , V_228 ,
V_123 , V_118 ) ;
F_140 ( V_26 , V_42 ) ;
F_34 ( & V_42 -> V_232 ) ;
if ( ! F_136 ( V_42 , V_121 ,
V_260 ) )
goto V_262;
} else {
if ( ! V_261 || V_123 != V_222 ||
! F_136 ( V_42 , V_121 ,
V_260 ) ) {
V_262:
F_56 ( V_80 , V_26 ,
L_45 ,
V_42 -> V_163 , V_123 , V_222 ,
V_228 ) ;
F_141 ( V_26 , V_42 , V_123 ,
V_121 , V_260 ,
V_212 ) ;
return;
}
}
}
bool F_177 ( struct V_25 * V_26 ,
T_2 * V_14 , unsigned short V_9 )
{
struct V_31 * V_32 ;
bool V_90 = false ;
V_32 = F_13 ( V_26 , V_14 , V_9 ) ;
if ( ! V_32 )
goto V_103;
V_90 = V_32 -> V_30 . V_53 & V_100 ;
F_17 ( V_32 ) ;
V_103:
return V_90 ;
}
bool F_178 ( struct V_25 * V_26 ,
T_2 * V_14 , unsigned short V_9 )
{
struct V_24 * V_28 ;
bool V_90 = false ;
V_28 = F_12 ( V_26 , V_14 , V_9 ) ;
if ( ! V_28 )
goto V_103;
V_90 = V_28 -> V_30 . V_53 & V_100 ;
F_14 ( V_28 ) ;
V_103:
return V_90 ;
}
bool F_179 ( struct V_25 * V_26 ,
struct V_41 * V_42 ,
const unsigned char * V_14 ,
unsigned short V_9 )
{
bool V_90 = false ;
if ( ! F_98 ( V_26 , V_42 , V_14 , V_9 ,
V_164 ,
F_20 ( & V_42 -> V_124 ) ) )
goto V_103;
F_56 ( V_80 , V_26 ,
L_46 ,
V_14 , F_57 ( V_9 ) , V_42 -> V_163 ) ;
V_90 = true ;
V_103:
return V_90 ;
}
void F_180 ( struct V_81 * V_82 )
{
struct V_25 * V_26 = F_60 ( V_82 ) ;
int V_89 = F_20 ( & V_26 -> V_89 ) ;
int V_88 , V_154 = V_251 / 2 ;
bool V_263 = false ;
F_30 ( & V_26 -> V_12 . V_227 ) ;
while ( true ) {
V_88 = F_51 ( V_26 ) ;
if ( V_89 >= V_88 )
break;
F_87 ( V_26 , V_154 ) ;
F_170 ( V_26 ) ;
V_154 /= 2 ;
V_263 = true ;
F_63 ( V_102 , V_82 ,
L_47 ,
V_89 ) ;
}
if ( V_263 )
F_171 ( V_26 ) ;
F_34 ( & V_26 -> V_12 . V_227 ) ;
}
static void F_181 ( struct V_25 * V_26 ,
struct V_41 * V_163 ,
T_2 V_53 , void * V_264 ,
T_3 V_265 )
{
struct V_75 * V_121 ;
struct V_67 * V_118 ;
struct V_74 * V_117 ;
T_3 V_40 , V_69 ;
if ( V_265 < sizeof( * V_117 ) )
return;
V_117 = (struct V_74 * ) V_264 ;
V_265 -= sizeof( * V_117 ) ;
V_69 = F_137 ( V_117 -> V_69 ) ;
if ( V_265 < sizeof( * V_121 ) * V_69 )
return;
V_121 = (struct V_75 * ) ( V_117 + 1 ) ;
V_118 = (struct V_67 * ) ( V_121 + V_69 ) ;
V_265 -= sizeof( * V_121 ) * V_69 ;
V_40 = F_50 ( V_265 ) ;
F_175 ( V_26 , V_163 , V_121 , V_69 , V_118 ,
V_40 , V_117 -> V_123 ) ;
}
static int F_182 ( struct V_25 * V_26 ,
T_2 * V_189 , T_2 * V_258 ,
void * V_264 ,
T_3 V_265 )
{
struct V_74 * V_117 ;
T_3 V_266 , V_208 ;
char V_267 ;
bool V_90 ;
if ( V_265 < sizeof( * V_117 ) )
return V_268 ;
V_117 = (struct V_74 * ) V_264 ;
V_265 -= sizeof( * V_117 ) ;
V_266 = sizeof( struct V_75 ) ;
V_266 *= F_137 ( V_117 -> V_69 ) ;
if ( V_265 < V_266 )
return V_268 ;
V_265 -= V_266 ;
V_208 = F_50 ( V_265 ) ;
switch ( V_117 -> V_53 & V_269 ) {
case V_215 :
F_143 ( V_26 , V_270 ) ;
V_90 = F_148 ( V_26 , V_117 , V_189 , V_258 ) ;
if ( ! V_90 ) {
if ( V_117 -> V_53 & V_216 )
V_267 = 'F' ;
else
V_267 = '.' ;
F_56 ( V_80 , V_26 ,
L_48 ,
V_258 , V_267 ) ;
return V_271 ;
}
break;
case V_224 :
F_143 ( V_26 , V_272 ) ;
if ( F_149 ( V_26 , V_258 ) ) {
F_155 ( V_26 , V_117 ,
V_189 , V_208 ) ;
return V_268 ;
}
if ( V_117 -> V_53 & V_216 )
V_267 = 'F' ;
else
V_267 = '.' ;
F_56 ( V_80 , V_26 ,
L_49 , V_258 , V_267 ) ;
return V_271 ;
}
return V_268 ;
}
static int F_183 ( struct V_25 * V_26 ,
T_2 * V_189 , T_2 * V_258 ,
void * V_264 ,
T_3 V_265 )
{
struct V_242 * V_273 ;
struct V_41 * V_42 = NULL ;
if ( ! F_149 ( V_26 , V_258 ) )
return V_271 ;
if ( V_265 < sizeof( * V_273 ) )
goto V_103;
V_42 = F_146 ( V_26 , V_189 ) ;
if ( ! V_42 )
goto V_103;
F_143 ( V_26 , V_274 ) ;
V_273 = (struct V_242 * ) V_264 ;
F_56 ( V_80 , V_26 ,
L_50 ,
V_189 , V_273 -> V_237 ) ;
F_98 ( V_26 , V_42 , V_273 -> V_237 ,
F_137 ( V_273 -> V_9 ) , V_100 ,
F_20 ( & V_42 -> V_124 ) + 1 ) ;
V_103:
if ( V_42 )
F_38 ( V_42 ) ;
return V_268 ;
}
int F_184 ( struct V_25 * V_26 )
{
int V_90 ;
F_185 ( ! ( V_192 & V_113 ) ) ;
V_90 = F_52 ( V_26 ) ;
if ( V_90 < 0 )
return V_90 ;
V_90 = F_91 ( V_26 ) ;
if ( V_90 < 0 )
return V_90 ;
F_186 ( V_26 , F_181 ,
F_182 ,
V_136 , 1 , V_110 ) ;
F_186 ( V_26 , NULL ,
F_183 ,
V_245 , 1 , V_110 ) ;
F_187 ( & V_26 -> V_12 . V_247 , F_162 ) ;
F_163 ( V_252 , & V_26 -> V_12 . V_247 ,
F_164 ( V_253 ) ) ;
return 1 ;
}
bool F_188 ( struct V_25 * V_26 ,
const T_2 * V_14 , unsigned short V_9 )
{
struct V_31 * V_12 ;
bool V_90 ;
V_12 = F_13 ( V_26 , V_14 , V_9 ) ;
if ( ! V_12 )
return false ;
V_90 = V_12 -> V_30 . V_53 & V_116 ;
F_17 ( V_12 ) ;
return V_90 ;
}

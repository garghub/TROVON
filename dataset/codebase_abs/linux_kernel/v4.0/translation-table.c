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
F_7 ( V_17 . V_11 , V_11 ) ;
V_17 . V_13 = V_13 ;
V_19 = F_4 ( & V_17 , V_10 -> V_8 ) ;
V_16 = & V_10 -> V_20 [ V_19 ] ;
F_8 () ;
F_9 (tt, head, hash_entry) {
if ( ! F_3 ( V_9 , V_11 ) )
continue;
if ( V_9 -> V_13 != V_13 )
continue;
if ( ! F_10 ( & V_9 -> V_21 ) )
continue;
V_18 = V_9 ;
break;
}
F_11 () ;
return V_18 ;
}
static struct V_22 *
F_12 ( struct V_23 * V_24 , const T_2 * V_11 ,
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
F_13 ( struct V_23 * V_24 , const T_2 * V_11 ,
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
F_14 ( struct V_22 * V_26 )
{
if ( F_15 ( & V_26 -> V_28 . V_21 ) )
F_16 ( V_26 , V_28 . V_32 ) ;
}
static void
F_17 ( struct V_29 * V_30 )
{
if ( F_15 ( & V_30 -> V_28 . V_21 ) ) {
F_18 ( V_30 ) ;
F_16 ( V_30 , V_28 . V_32 ) ;
}
}
int F_19 ( struct V_23 * V_24 ,
const T_2 * V_11 , unsigned short V_13 )
{
struct V_29 * V_30 ;
int V_33 ;
V_30 = F_13 ( V_24 , V_11 , V_13 ) ;
if ( ! V_30 )
return 0 ;
V_33 = F_20 ( & V_30 -> V_34 ) ;
F_17 ( V_30 ) ;
return V_33 ;
}
static void F_21 ( struct V_35 * V_32 )
{
struct V_36 * V_37 ;
V_37 = F_2 ( V_32 , struct V_36 , V_32 ) ;
F_22 ( V_37 -> V_38 ) ;
F_23 ( V_37 ) ;
}
static void F_24 ( struct V_23 * V_24 ,
unsigned short V_13 , int V_39 )
{
struct V_40 * V_41 ;
V_41 = F_25 ( V_24 , V_13 ) ;
if ( ! V_41 )
return;
F_26 ( V_39 , & V_41 -> V_9 . V_42 ) ;
F_27 ( V_41 ) ;
}
static void F_28 ( struct V_23 * V_24 ,
unsigned short V_13 )
{
F_24 ( V_24 , V_13 , 1 ) ;
}
static void F_29 ( struct V_23 * V_24 ,
unsigned short V_13 )
{
F_24 ( V_24 , V_13 , - 1 ) ;
}
static void F_30 ( struct V_43 * V_38 ,
unsigned short V_13 , int V_39 )
{
struct V_44 * V_41 ;
V_41 = F_31 ( V_38 , V_13 ) ;
if ( ! V_41 )
return;
if ( F_32 ( V_39 , & V_41 -> V_9 . V_42 ) == 0 ) {
F_33 ( & V_38 -> V_45 ) ;
F_34 ( & V_41 -> V_46 ) ;
F_35 ( & V_38 -> V_45 ) ;
F_36 ( V_41 ) ;
}
F_36 ( V_41 ) ;
}
static void F_37 ( struct V_43 * V_38 ,
unsigned short V_13 )
{
F_30 ( V_38 , V_13 , 1 ) ;
}
static void F_38 ( struct V_43 * V_38 ,
unsigned short V_13 )
{
F_30 ( V_38 , V_13 , - 1 ) ;
}
static void
F_39 ( struct V_36 * V_37 )
{
if ( ! F_15 ( & V_37 -> V_21 ) )
return;
F_40 ( & V_37 -> V_32 , F_21 ) ;
}
static void F_41 ( struct V_23 * V_24 ,
struct V_22 * V_26 ,
T_2 V_47 )
{
struct V_48 * V_49 , * V_50 , * V_51 ;
struct V_5 * V_28 = & V_26 -> V_28 ;
T_2 V_52 = V_28 -> V_52 | V_47 ;
bool V_53 = false ;
bool V_54 , V_55 ;
V_49 = F_42 ( sizeof( * V_49 ) , V_56 ) ;
if ( ! V_49 )
return;
V_49 -> V_57 . V_52 = V_52 ;
memset ( V_49 -> V_57 . V_58 , 0 ,
sizeof( V_49 -> V_57 . V_58 ) ) ;
F_7 ( V_49 -> V_57 . V_11 , V_28 -> V_11 ) ;
V_49 -> V_57 . V_13 = F_43 ( V_28 -> V_13 ) ;
V_54 = V_52 & V_59 ;
F_33 ( & V_24 -> V_9 . V_60 ) ;
F_44 (entry, safe, &bat_priv->tt.changes_list,
list) {
if ( ! F_3 ( V_50 -> V_57 . V_11 , V_28 -> V_11 ) )
continue;
V_55 = V_50 -> V_57 . V_52 & V_59 ;
if ( ! V_54 && V_55 )
goto V_61;
if ( V_54 && ! V_55 )
goto V_61;
if ( ! V_54 && ! V_55 )
V_50 -> V_57 . V_52 = V_52 ;
continue;
V_61:
F_45 ( & V_50 -> V_46 ) ;
F_23 ( V_50 ) ;
F_23 ( V_49 ) ;
V_53 = true ;
goto V_62;
}
F_46 ( & V_49 -> V_46 , & V_24 -> V_9 . V_63 ) ;
V_62:
F_35 ( & V_24 -> V_9 . V_60 ) ;
if ( V_53 )
F_47 ( & V_24 -> V_9 . V_64 ) ;
else
F_48 ( & V_24 -> V_9 . V_64 ) ;
}
static int F_49 ( int V_65 )
{
return V_65 * sizeof( struct V_66 ) ;
}
static T_3 F_50 ( T_3 V_67 )
{
return V_67 / F_49 ( 1 ) ;
}
static int F_51 ( struct V_23 * V_24 )
{
T_3 V_68 = 0 , V_69 = 0 ;
struct V_40 * V_41 ;
int V_70 ;
F_8 () ;
F_9 (vlan, &bat_priv->softif_vlan_list, list) {
V_68 ++ ;
V_69 += F_20 ( & V_41 -> V_9 . V_42 ) ;
}
F_11 () ;
V_70 = sizeof( struct V_71 ) ;
V_70 += sizeof( struct V_72 ) ;
V_70 += sizeof( struct V_73 ) ;
V_70 += V_68 * sizeof( struct V_74 ) ;
return V_70 + F_49 ( V_69 ) ;
}
static int F_52 ( struct V_23 * V_24 )
{
if ( V_24 -> V_9 . V_27 )
return 0 ;
V_24 -> V_9 . V_27 = F_53 ( 1024 ) ;
if ( ! V_24 -> V_9 . V_27 )
return - V_75 ;
F_54 ( V_24 -> V_9 . V_27 ,
& V_76 ) ;
return 0 ;
}
static void F_55 ( struct V_23 * V_24 ,
struct V_29 * V_77 ,
const char * V_78 )
{
F_56 ( V_79 , V_24 ,
L_1 ,
V_77 -> V_28 . V_11 ,
F_57 ( V_77 -> V_28 . V_13 ) , V_78 ) ;
F_58 ( V_24 -> V_9 . V_31 , F_1 ,
F_4 , & V_77 -> V_28 ) ;
F_17 ( V_77 ) ;
}
bool F_59 ( struct V_80 * V_81 , const T_2 * V_11 ,
unsigned short V_13 , int V_82 , T_1 V_83 )
{
struct V_23 * V_24 = F_60 ( V_81 ) ;
struct V_22 * V_84 ;
struct V_29 * V_77 = NULL ;
struct V_40 * V_41 ;
struct V_80 * V_85 = NULL ;
struct V_15 * V_16 ;
struct V_36 * V_37 ;
int V_86 , V_87 , V_88 ;
bool V_89 = false , V_90 = false ;
T_2 V_91 ;
T_1 V_92 ;
if ( V_82 != V_93 )
V_85 = F_61 ( & V_94 , V_82 ) ;
V_84 = F_12 ( V_24 , V_11 , V_13 ) ;
if ( ! F_62 ( V_11 ) )
V_77 = F_13 ( V_24 , V_11 , V_13 ) ;
if ( V_84 ) {
V_84 -> V_95 = V_96 ;
if ( V_84 -> V_28 . V_52 & V_97 ) {
F_56 ( V_79 , V_24 ,
L_2 ,
V_11 , F_57 ( V_13 ) ) ;
V_84 -> V_28 . V_52 &= ~ V_97 ;
goto V_98;
}
if ( V_84 -> V_28 . V_52 & V_99 ) {
F_56 ( V_79 , V_24 ,
L_3 ,
V_11 , F_57 ( V_13 ) ) ;
V_84 -> V_28 . V_52 &= ~ V_99 ;
V_90 = true ;
}
goto V_100;
}
V_87 = F_51 ( V_24 ) ;
V_87 += F_49 ( 1 ) ;
V_88 = F_20 ( & V_24 -> V_88 ) ;
if ( V_87 > V_88 ) {
F_63 ( V_101 , V_81 ,
L_4 ,
V_87 , V_88 , V_11 ) ;
goto V_102;
}
V_84 = F_42 ( sizeof( * V_84 ) , V_56 ) ;
if ( ! V_84 )
goto V_102;
V_41 = F_25 ( V_24 , V_13 ) ;
F_56 ( V_79 , V_24 ,
L_5 ,
V_11 , F_57 ( V_13 ) ,
( T_2 ) F_20 ( & V_24 -> V_9 . V_103 ) ) ;
F_7 ( V_84 -> V_28 . V_11 , V_11 ) ;
V_84 -> V_28 . V_52 = V_104 ;
V_84 -> V_28 . V_13 = V_13 ;
if ( F_64 ( V_85 ) )
V_84 -> V_28 . V_52 |= V_105 ;
F_65 ( & V_84 -> V_28 . V_21 , 2 ) ;
V_84 -> V_95 = V_96 ;
V_84 -> V_28 . V_106 = V_84 -> V_95 ;
if ( F_3 ( V_11 , V_81 -> V_107 ) ||
F_62 ( V_11 ) )
V_84 -> V_28 . V_52 |= V_108 ;
V_86 = F_66 ( V_24 -> V_9 . V_27 , F_1 ,
F_4 , & V_84 -> V_28 ,
& V_84 -> V_28 . V_6 ) ;
if ( F_67 ( V_86 != 0 ) ) {
F_14 ( V_84 ) ;
F_27 ( V_41 ) ;
goto V_102;
}
V_98:
F_41 ( V_24 , V_84 , V_109 ) ;
V_100:
if ( V_77 && ! ( V_77 -> V_28 . V_52 & V_99 ) ) {
V_16 = & V_77 -> V_110 ;
F_8 () ;
F_9 (orig_entry, head, list) {
F_68 ( V_24 , V_77 -> V_28 . V_11 ,
V_77 -> V_28 . V_13 ,
V_37 -> V_38 ) ;
}
F_11 () ;
if ( V_90 ) {
F_55 ( V_24 , V_77 ,
L_6 ) ;
V_77 = NULL ;
} else {
V_77 -> V_28 . V_52 |= V_99 ;
V_77 -> V_111 = V_96 ;
}
}
V_91 = V_84 -> V_28 . V_52 & V_112 ;
if ( F_64 ( V_85 ) )
V_84 -> V_28 . V_52 |= V_105 ;
else
V_84 -> V_28 . V_52 &= ~ V_105 ;
V_92 = ( V_83 & V_24 -> V_113 ) ;
if ( V_24 -> V_113 &&
V_92 == V_24 -> V_114 )
V_84 -> V_28 . V_52 |= V_115 ;
else
V_84 -> V_28 . V_52 &= ~ V_115 ;
if ( V_91 ^ ( V_84 -> V_28 . V_52 & V_112 ) )
F_41 ( V_24 , V_84 , V_109 ) ;
V_89 = true ;
V_102:
if ( V_85 )
F_69 ( V_85 ) ;
if ( V_84 )
F_14 ( V_84 ) ;
if ( V_77 )
F_17 ( V_77 ) ;
return V_89 ;
}
static T_3
F_70 ( struct V_43 * V_38 ,
struct V_73 * * V_116 ,
struct V_66 * * V_117 ,
T_4 * V_67 )
{
T_3 V_68 = 0 , V_42 = 0 , V_118 , V_119 ;
struct V_74 * V_120 ;
struct V_44 * V_41 ;
T_2 * V_121 ;
F_8 () ;
F_71 (vlan, &orig_node->vlan_list, list) {
V_68 ++ ;
V_42 += F_20 ( & V_41 -> V_9 . V_42 ) ;
}
V_118 = sizeof( * * V_116 ) ;
V_118 += V_68 * sizeof( * V_120 ) ;
if ( * V_67 < 0 )
* V_67 = F_49 ( V_42 ) ;
V_119 = * V_67 ;
V_119 += V_118 ;
* V_116 = F_42 ( V_119 , V_56 ) ;
if ( ! * V_116 ) {
* V_67 = 0 ;
goto V_102;
}
( * V_116 ) -> V_52 = V_109 ;
( * V_116 ) -> V_122 = F_20 ( & V_38 -> V_123 ) ;
( * V_116 ) -> V_68 = F_43 ( V_68 ) ;
V_120 = (struct V_74 * ) ( * V_116 + 1 ) ;
F_71 (vlan, &orig_node->vlan_list, list) {
V_120 -> V_13 = F_43 ( V_41 -> V_13 ) ;
V_120 -> V_124 = F_72 ( V_41 -> V_9 . V_124 ) ;
V_120 ++ ;
}
V_121 = ( T_2 * ) * V_116 + V_118 ;
* V_117 = (struct V_66 * ) V_121 ;
V_102:
F_11 () ;
return V_119 ;
}
static T_3
F_73 ( struct V_23 * V_24 ,
struct V_73 * * V_116 ,
struct V_66 * * V_117 ,
T_4 * V_67 )
{
struct V_74 * V_120 ;
struct V_40 * V_41 ;
T_3 V_68 = 0 , V_42 = 0 , V_119 ;
T_2 * V_121 ;
int V_118 ;
F_8 () ;
F_9 (vlan, &bat_priv->softif_vlan_list, list) {
V_68 ++ ;
V_42 += F_20 ( & V_41 -> V_9 . V_42 ) ;
}
V_118 = sizeof( * * V_116 ) ;
V_118 += V_68 * sizeof( * V_120 ) ;
if ( * V_67 < 0 )
* V_67 = F_49 ( V_42 ) ;
V_119 = * V_67 ;
V_119 += V_118 ;
* V_116 = F_42 ( V_119 , V_56 ) ;
if ( ! * V_116 ) {
V_119 = 0 ;
goto V_102;
}
( * V_116 ) -> V_52 = V_109 ;
( * V_116 ) -> V_122 = F_20 ( & V_24 -> V_9 . V_103 ) ;
( * V_116 ) -> V_68 = F_43 ( V_68 ) ;
V_120 = (struct V_74 * ) ( * V_116 + 1 ) ;
F_9 (vlan, &bat_priv->softif_vlan_list, list) {
V_120 -> V_13 = F_43 ( V_41 -> V_13 ) ;
V_120 -> V_124 = F_72 ( V_41 -> V_9 . V_124 ) ;
V_120 ++ ;
}
V_121 = ( T_2 * ) * V_116 + V_118 ;
* V_117 = (struct V_66 * ) V_121 ;
V_102:
F_11 () ;
return V_119 ;
}
static void F_74 ( struct V_23 * V_24 )
{
struct V_48 * V_50 , * V_51 ;
struct V_73 * V_116 ;
struct V_66 * V_117 ;
int V_125 , V_126 = 0 ;
int V_127 = 0 , V_128 = 0 ;
T_3 V_119 ;
V_127 = F_20 ( & V_24 -> V_9 . V_64 ) ;
V_125 = F_49 ( V_127 ) ;
if ( V_125 > V_24 -> V_81 -> V_129 )
V_125 = 0 ;
V_119 = F_73 ( V_24 , & V_116 ,
& V_117 , & V_125 ) ;
if ( ! V_119 )
return;
V_116 -> V_52 = V_130 ;
if ( V_125 == 0 )
goto V_131;
F_33 ( & V_24 -> V_9 . V_60 ) ;
F_65 ( & V_24 -> V_9 . V_64 , 0 ) ;
F_44 (entry, safe, &bat_priv->tt.changes_list,
list) {
if ( V_128 < V_127 ) {
memcpy ( V_117 + V_128 ,
& V_50 -> V_57 ,
sizeof( struct V_66 ) ) ;
V_128 ++ ;
}
F_45 ( & V_50 -> V_46 ) ;
F_23 ( V_50 ) ;
}
F_35 ( & V_24 -> V_9 . V_60 ) ;
F_33 ( & V_24 -> V_9 . V_132 ) ;
F_23 ( V_24 -> V_9 . V_133 ) ;
V_24 -> V_9 . V_134 = 0 ;
V_24 -> V_9 . V_133 = NULL ;
V_126 = F_49 ( V_128 ) ;
if ( V_128 > 0 ) {
V_24 -> V_9 . V_133 = F_75 ( V_125 , V_56 ) ;
if ( V_24 -> V_9 . V_133 ) {
memcpy ( V_24 -> V_9 . V_133 ,
V_117 , V_126 ) ;
V_24 -> V_9 . V_134 = V_125 ;
}
}
F_35 ( & V_24 -> V_9 . V_132 ) ;
V_131:
F_76 ( V_24 , V_135 , 1 , V_116 ,
V_119 ) ;
F_23 ( V_116 ) ;
}
int F_77 ( struct V_136 * V_137 , void * V_138 )
{
struct V_80 * V_139 = (struct V_80 * ) V_137 -> V_140 ;
struct V_23 * V_24 = F_60 ( V_139 ) ;
struct V_14 * V_10 = V_24 -> V_9 . V_27 ;
struct V_5 * V_25 ;
struct V_22 * V_84 ;
struct V_141 * V_142 ;
struct V_40 * V_41 ;
struct V_15 * V_16 ;
unsigned short V_13 ;
T_1 V_143 ;
int V_144 ;
int V_145 ;
unsigned long V_146 ;
bool V_147 ;
T_3 V_148 = V_108 ;
V_142 = F_78 ( V_137 ) ;
if ( ! V_142 )
goto V_102;
F_79 ( V_137 ,
L_7 ,
V_139 -> V_149 , ( T_2 ) F_20 ( & V_24 -> V_9 . V_103 ) ) ;
F_79 ( V_137 , L_8 , L_9 , L_10 ,
L_11 , L_12 , L_13 ) ;
for ( V_143 = 0 ; V_143 < V_10 -> V_8 ; V_143 ++ ) {
V_16 = & V_10 -> V_20 [ V_143 ] ;
F_8 () ;
F_9 (tt_common_entry,
head, hash_entry) {
V_84 = F_2 ( V_25 ,
struct V_22 ,
V_28 ) ;
V_13 = V_25 -> V_13 ;
V_146 = V_96 - V_84 -> V_95 ;
V_145 = F_80 ( V_146 ) ;
V_144 = V_145 / 1000 ;
V_145 = V_145 % 1000 ;
V_147 = V_25 -> V_52 & V_148 ;
V_41 = F_25 ( V_24 , V_13 ) ;
if ( ! V_41 ) {
F_79 ( V_137 , L_14 ,
F_57 ( V_13 ) ) ;
continue;
}
F_79 ( V_137 ,
L_15 ,
V_25 -> V_11 ,
F_57 ( V_25 -> V_13 ) ,
( V_25 -> V_52 &
V_99 ? 'R' : '.' ) ,
V_147 ? 'P' : '.' ,
( V_25 -> V_52 &
V_104 ? 'N' : '.' ) ,
( V_25 -> V_52 &
V_97 ? 'X' : '.' ) ,
( V_25 -> V_52 &
V_105 ? 'W' : '.' ) ,
( V_25 -> V_52 &
V_115 ? 'I' : '.' ) ,
V_147 ? 0 : V_144 ,
V_147 ? 0 : V_145 ,
V_41 -> V_9 . V_124 ) ;
F_27 ( V_41 ) ;
}
F_11 () ;
}
V_102:
if ( V_142 )
F_81 ( V_142 ) ;
return 0 ;
}
static void
F_82 ( struct V_23 * V_24 ,
struct V_22 * V_26 ,
T_3 V_52 , const char * V_78 )
{
F_41 ( V_24 , V_26 , V_52 ) ;
V_26 -> V_28 . V_52 |= V_97 ;
F_56 ( V_79 , V_24 ,
L_16 ,
V_26 -> V_28 . V_11 ,
F_57 ( V_26 -> V_28 . V_13 ) , V_78 ) ;
}
T_3 F_83 ( struct V_23 * V_24 ,
const T_2 * V_11 , unsigned short V_13 ,
const char * V_78 , bool V_150 )
{
struct V_22 * V_26 ;
T_3 V_52 , V_151 = V_109 ;
struct V_40 * V_41 ;
V_26 = F_12 ( V_24 , V_11 , V_13 ) ;
if ( ! V_26 )
goto V_102;
V_151 = V_26 -> V_28 . V_52 ;
V_52 = V_59 ;
if ( V_150 ) {
V_52 |= V_99 ;
V_26 -> V_28 . V_52 |= V_99 ;
}
if ( ! ( V_26 -> V_28 . V_52 & V_104 ) ) {
F_82 ( V_24 , V_26 , V_52 ,
V_78 ) ;
goto V_102;
}
F_41 ( V_24 , V_26 , V_59 ) ;
F_84 ( & V_26 -> V_28 . V_6 ) ;
F_14 ( V_26 ) ;
V_41 = F_25 ( V_24 , V_13 ) ;
F_27 ( V_41 ) ;
F_27 ( V_41 ) ;
V_102:
if ( V_26 )
F_14 ( V_26 ) ;
return V_151 ;
}
static void F_85 ( struct V_23 * V_24 ,
struct V_15 * V_16 ,
int V_152 )
{
struct V_22 * V_26 ;
struct V_5 * V_25 ;
struct V_1 * V_153 ;
F_86 (tt_common_entry, node_tmp, head,
hash_entry) {
V_26 = F_2 ( V_25 ,
struct V_22 ,
V_28 ) ;
if ( V_26 -> V_28 . V_52 & V_108 )
continue;
if ( V_26 -> V_28 . V_52 & V_97 )
continue;
if ( ! F_87 ( V_26 -> V_95 , V_152 ) )
continue;
F_82 ( V_24 , V_26 ,
V_59 , L_17 ) ;
}
}
static void F_88 ( struct V_23 * V_24 ,
int V_152 )
{
struct V_14 * V_10 = V_24 -> V_9 . V_27 ;
struct V_15 * V_16 ;
T_5 * V_154 ;
T_1 V_143 ;
for ( V_143 = 0 ; V_143 < V_10 -> V_8 ; V_143 ++ ) {
V_16 = & V_10 -> V_20 [ V_143 ] ;
V_154 = & V_10 -> V_155 [ V_143 ] ;
F_33 ( V_154 ) ;
F_85 ( V_24 , V_16 , V_152 ) ;
F_35 ( V_154 ) ;
}
}
static void F_89 ( struct V_23 * V_24 )
{
struct V_14 * V_10 ;
T_5 * V_154 ;
struct V_5 * V_25 ;
struct V_22 * V_84 ;
struct V_40 * V_41 ;
struct V_1 * V_153 ;
struct V_15 * V_16 ;
T_1 V_143 ;
if ( ! V_24 -> V_9 . V_27 )
return;
V_10 = V_24 -> V_9 . V_27 ;
for ( V_143 = 0 ; V_143 < V_10 -> V_8 ; V_143 ++ ) {
V_16 = & V_10 -> V_20 [ V_143 ] ;
V_154 = & V_10 -> V_155 [ V_143 ] ;
F_33 ( V_154 ) ;
F_86 (tt_common_entry, node_tmp,
head, hash_entry) {
F_84 ( & V_25 -> V_6 ) ;
V_84 = F_2 ( V_25 ,
struct V_22 ,
V_28 ) ;
V_41 = F_25 ( V_24 ,
V_25 -> V_13 ) ;
F_27 ( V_41 ) ;
F_27 ( V_41 ) ;
F_14 ( V_84 ) ;
}
F_35 ( V_154 ) ;
}
F_90 ( V_10 ) ;
V_24 -> V_9 . V_27 = NULL ;
}
static int F_91 ( struct V_23 * V_24 )
{
if ( V_24 -> V_9 . V_31 )
return 0 ;
V_24 -> V_9 . V_31 = F_53 ( 1024 ) ;
if ( ! V_24 -> V_9 . V_31 )
return - V_75 ;
F_54 ( V_24 -> V_9 . V_31 ,
& V_156 ) ;
return 0 ;
}
static void F_92 ( struct V_23 * V_24 )
{
struct V_48 * V_50 , * V_51 ;
F_33 ( & V_24 -> V_9 . V_60 ) ;
F_44 (entry, safe, &bat_priv->tt.changes_list,
list) {
F_45 ( & V_50 -> V_46 ) ;
F_23 ( V_50 ) ;
}
F_65 ( & V_24 -> V_9 . V_64 , 0 ) ;
F_35 ( & V_24 -> V_9 . V_60 ) ;
}
static struct V_36 *
F_93 ( const struct V_29 * V_50 ,
const struct V_43 * V_38 )
{
struct V_36 * V_157 , * V_37 = NULL ;
const struct V_15 * V_16 ;
F_8 () ;
V_16 = & V_50 -> V_110 ;
F_9 (tmp_orig_entry, head, list) {
if ( V_157 -> V_38 != V_38 )
continue;
if ( ! F_10 ( & V_157 -> V_21 ) )
continue;
V_37 = V_157 ;
break;
}
F_11 () ;
return V_37 ;
}
static bool
F_94 ( const struct V_29 * V_50 ,
const struct V_43 * V_38 )
{
struct V_36 * V_37 ;
bool V_158 = false ;
V_37 = F_93 ( V_50 , V_38 ) ;
if ( V_37 ) {
V_158 = true ;
F_39 ( V_37 ) ;
}
return V_158 ;
}
static void
F_95 ( struct V_29 * V_77 ,
struct V_43 * V_38 , int V_122 )
{
struct V_36 * V_37 ;
V_37 = F_93 ( V_77 , V_38 ) ;
if ( V_37 ) {
V_37 -> V_122 = V_122 ;
goto V_102;
}
V_37 = F_75 ( sizeof( * V_37 ) , V_56 ) ;
if ( ! V_37 )
goto V_102;
F_96 ( & V_37 -> V_46 ) ;
F_48 ( & V_38 -> V_21 ) ;
F_37 ( V_38 , V_77 -> V_28 . V_13 ) ;
V_37 -> V_38 = V_38 ;
V_37 -> V_122 = V_122 ;
F_65 ( & V_37 -> V_21 , 2 ) ;
F_33 ( & V_77 -> V_154 ) ;
F_97 ( & V_37 -> V_46 ,
& V_77 -> V_110 ) ;
F_35 ( & V_77 -> V_154 ) ;
F_48 ( & V_77 -> V_34 ) ;
V_102:
if ( V_37 )
F_39 ( V_37 ) ;
}
static bool F_98 ( struct V_23 * V_24 ,
struct V_43 * V_38 ,
const unsigned char * V_159 ,
unsigned short V_13 , T_3 V_52 ,
T_2 V_122 )
{
struct V_29 * V_30 ;
struct V_22 * V_26 ;
bool V_89 = false ;
int V_86 ;
struct V_5 * V_28 ;
T_3 V_160 ;
if ( F_99 ( V_24 , V_38 -> V_161 , V_13 ) )
return true ;
V_30 = F_13 ( V_24 , V_159 , V_13 ) ;
V_26 = F_12 ( V_24 , V_159 , V_13 ) ;
if ( ( V_52 & V_162 ) && V_26 &&
! ( V_26 -> V_28 . V_52 & V_104 ) )
goto V_102;
if ( ! V_30 ) {
V_30 = F_75 ( sizeof( * V_30 ) , V_56 ) ;
if ( ! V_30 )
goto V_102;
V_28 = & V_30 -> V_28 ;
F_7 ( V_28 -> V_11 , V_159 ) ;
V_28 -> V_13 = V_13 ;
V_28 -> V_52 = V_52 ;
V_30 -> V_111 = 0 ;
if ( V_52 & V_99 )
V_30 -> V_111 = V_96 ;
F_65 ( & V_28 -> V_21 , 2 ) ;
V_28 -> V_106 = V_96 ;
F_100 ( & V_30 -> V_110 ) ;
F_65 ( & V_30 -> V_34 , 0 ) ;
F_101 ( & V_30 -> V_154 ) ;
V_86 = F_66 ( V_24 -> V_9 . V_31 ,
F_1 ,
F_4 , V_28 ,
& V_28 -> V_6 ) ;
if ( F_67 ( V_86 != 0 ) ) {
F_17 ( V_30 ) ;
goto V_163;
}
} else {
V_28 = & V_30 -> V_28 ;
if ( V_52 & V_162 ) {
if ( ! ( V_28 -> V_52 & V_162 ) )
goto V_102;
if ( F_94 ( V_30 ,
V_38 ) )
goto V_163;
F_18 ( V_30 ) ;
goto V_164;
}
V_28 -> V_52 &= ~ V_162 ;
V_30 -> V_28 . V_52 |= V_52 ;
if ( V_28 -> V_52 & V_99 ) {
F_18 ( V_30 ) ;
V_28 -> V_52 &= ~ V_99 ;
V_30 -> V_111 = 0 ;
}
}
V_164:
F_95 ( V_30 , V_38 , V_122 ) ;
F_56 ( V_79 , V_24 ,
L_18 ,
V_28 -> V_11 , F_57 ( V_28 -> V_13 ) ,
V_38 -> V_161 ) ;
V_89 = true ;
V_163:
if ( F_62 ( V_159 ) )
goto V_102;
V_160 = F_83 ( V_24 , V_159 , V_13 ,
L_19 ,
V_52 & V_99 ) ;
V_30 -> V_28 . V_52 |= V_160 & V_105 ;
if ( ! ( V_52 & V_99 ) )
V_30 -> V_28 . V_52 &= ~ V_99 ;
V_102:
if ( V_30 )
F_17 ( V_30 ) ;
if ( V_26 )
F_14 ( V_26 ) ;
return V_89 ;
}
static struct V_36 *
F_102 ( struct V_23 * V_24 ,
struct V_29 * V_30 )
{
struct V_165 * V_166 , * V_167 = NULL ;
struct V_168 * V_169 = V_24 -> V_170 ;
struct V_15 * V_16 ;
struct V_36 * V_37 , * V_171 = NULL ;
V_16 = & V_30 -> V_110 ;
F_9 (orig_entry, head, list) {
V_166 = F_103 ( V_37 -> V_38 ,
V_172 ) ;
if ( ! V_166 )
continue;
if ( V_167 &&
V_169 -> V_173 ( V_166 , V_172 ,
V_167 , V_172 ) <= 0 ) {
F_104 ( V_166 ) ;
continue;
}
if ( V_167 )
F_104 ( V_167 ) ;
V_171 = V_37 ;
V_167 = V_166 ;
}
if ( V_167 )
F_104 ( V_167 ) ;
return V_171 ;
}
static void
F_105 ( struct V_23 * V_24 ,
struct V_29 * V_30 ,
struct V_136 * V_137 )
{
struct V_36 * V_37 , * V_171 ;
struct V_5 * V_25 ;
struct V_44 * V_41 ;
struct V_15 * V_16 ;
T_2 V_123 ;
T_3 V_52 ;
V_25 = & V_30 -> V_28 ;
V_52 = V_25 -> V_52 ;
V_171 = F_102 ( V_24 , V_30 ) ;
if ( V_171 ) {
V_41 = F_106 ( V_171 -> V_38 ,
V_25 -> V_13 ) ;
if ( ! V_41 ) {
F_79 ( V_137 ,
L_20 ,
F_57 ( V_25 -> V_13 ) ,
V_171 -> V_38 -> V_161 ) ;
goto V_174;
}
V_123 = F_20 ( & V_171 -> V_38 -> V_123 ) ;
F_79 ( V_137 ,
L_21 ,
'*' , V_30 -> V_28 . V_11 ,
F_57 ( V_30 -> V_28 . V_13 ) ,
V_171 -> V_122 , V_171 -> V_38 -> V_161 ,
V_123 , V_41 -> V_9 . V_124 ,
( V_52 & V_99 ? 'R' : '.' ) ,
( V_52 & V_105 ? 'W' : '.' ) ,
( V_52 & V_115 ? 'I' : '.' ) ,
( V_52 & V_162 ? 'T' : '.' ) ) ;
F_36 ( V_41 ) ;
}
V_174:
V_16 = & V_30 -> V_110 ;
F_9 (orig_entry, head, list) {
if ( V_171 == V_37 )
continue;
V_41 = F_106 ( V_37 -> V_38 ,
V_25 -> V_13 ) ;
if ( ! V_41 ) {
F_79 ( V_137 ,
L_22 ,
F_57 ( V_25 -> V_13 ) ,
V_37 -> V_38 -> V_161 ) ;
continue;
}
V_123 = F_20 ( & V_37 -> V_38 -> V_123 ) ;
F_79 ( V_137 ,
L_23 ,
'+' , V_30 -> V_28 . V_11 ,
F_57 ( V_30 -> V_28 . V_13 ) ,
V_37 -> V_122 , V_37 -> V_38 -> V_161 ,
V_123 , V_41 -> V_9 . V_124 ,
( V_52 & V_99 ? 'R' : '.' ) ,
( V_52 & V_105 ? 'W' : '.' ) ,
( V_52 & V_115 ? 'I' : '.' ) ,
( V_52 & V_162 ? 'T' : '.' ) ) ;
F_36 ( V_41 ) ;
}
}
int F_107 ( struct V_136 * V_137 , void * V_138 )
{
struct V_80 * V_139 = (struct V_80 * ) V_137 -> V_140 ;
struct V_23 * V_24 = F_60 ( V_139 ) ;
struct V_14 * V_10 = V_24 -> V_9 . V_31 ;
struct V_5 * V_25 ;
struct V_29 * V_77 ;
struct V_141 * V_142 ;
struct V_15 * V_16 ;
T_1 V_143 ;
V_142 = F_78 ( V_137 ) ;
if ( ! V_142 )
goto V_102;
F_79 ( V_137 ,
L_24 ,
V_139 -> V_149 ) ;
F_79 ( V_137 , L_25 ,
L_9 , L_10 , L_26 , L_27 , L_28 ,
L_13 , L_11 ) ;
for ( V_143 = 0 ; V_143 < V_10 -> V_8 ; V_143 ++ ) {
V_16 = & V_10 -> V_20 [ V_143 ] ;
F_8 () ;
F_9 (tt_common_entry,
head, hash_entry) {
V_77 = F_2 ( V_25 ,
struct V_29 ,
V_28 ) ;
F_105 ( V_24 , V_77 , V_137 ) ;
}
F_11 () ;
}
V_102:
if ( V_142 )
F_81 ( V_142 ) ;
return 0 ;
}
static void
F_108 ( struct V_29 * V_30 ,
struct V_36 * V_37 )
{
F_38 ( V_37 -> V_38 ,
V_30 -> V_28 . V_13 ) ;
F_47 ( & V_30 -> V_34 ) ;
F_84 ( & V_37 -> V_46 ) ;
F_39 ( V_37 ) ;
}
static void
F_18 ( struct V_29 * V_30 )
{
struct V_15 * V_16 ;
struct V_1 * V_51 ;
struct V_36 * V_37 ;
F_33 ( & V_30 -> V_154 ) ;
V_16 = & V_30 -> V_110 ;
F_86 (orig_entry, safe, head, list)
F_108 ( V_30 , V_37 ) ;
F_35 ( & V_30 -> V_154 ) ;
}
static void
F_109 ( struct V_23 * V_24 ,
struct V_29 * V_30 ,
struct V_43 * V_38 ,
const char * V_78 )
{
struct V_15 * V_16 ;
struct V_1 * V_51 ;
struct V_36 * V_37 ;
unsigned short V_13 ;
F_33 ( & V_30 -> V_154 ) ;
V_16 = & V_30 -> V_110 ;
F_86 (orig_entry, safe, head, list) {
if ( V_37 -> V_38 == V_38 ) {
V_13 = V_30 -> V_28 . V_13 ;
F_56 ( V_79 , V_24 ,
L_29 ,
V_38 -> V_161 ,
V_30 -> V_28 . V_11 ,
F_57 ( V_13 ) , V_78 ) ;
F_108 ( V_30 ,
V_37 ) ;
}
}
F_35 ( & V_30 -> V_154 ) ;
}
static void
F_110 ( struct V_23 * V_24 ,
struct V_29 * V_30 ,
struct V_43 * V_38 ,
const char * V_78 )
{
bool V_175 = true ;
struct V_15 * V_16 ;
struct V_36 * V_37 ;
F_8 () ;
V_16 = & V_30 -> V_110 ;
F_9 (orig_entry, head, list) {
if ( V_37 -> V_38 != V_38 ) {
V_175 = false ;
break;
}
}
F_11 () ;
if ( V_175 ) {
V_30 -> V_28 . V_52 |= V_99 ;
V_30 -> V_111 = V_96 ;
} else
F_109 ( V_24 , V_30 ,
V_38 , V_78 ) ;
}
static void F_111 ( struct V_23 * V_24 ,
struct V_43 * V_38 ,
const unsigned char * V_11 , unsigned short V_13 ,
const char * V_78 , bool V_150 )
{
struct V_29 * V_30 ;
struct V_22 * V_176 = NULL ;
V_30 = F_13 ( V_24 , V_11 , V_13 ) ;
if ( ! V_30 )
goto V_102;
if ( ! V_150 ) {
F_109 ( V_24 , V_30 ,
V_38 , V_78 ) ;
if ( F_112 ( & V_30 -> V_110 ) )
F_55 ( V_24 , V_30 ,
V_78 ) ;
goto V_102;
}
V_176 = F_12 ( V_24 ,
V_30 -> V_28 . V_11 ,
V_13 ) ;
if ( V_176 ) {
F_18 ( V_30 ) ;
F_55 ( V_24 , V_30 , V_78 ) ;
} else
F_110 ( V_24 , V_30 ,
V_38 , V_78 ) ;
V_102:
if ( V_30 )
F_17 ( V_30 ) ;
if ( V_176 )
F_14 ( V_176 ) ;
}
void F_113 ( struct V_23 * V_24 ,
struct V_43 * V_38 ,
T_4 V_177 ,
const char * V_78 )
{
struct V_29 * V_77 ;
struct V_5 * V_25 ;
T_1 V_143 ;
struct V_14 * V_10 = V_24 -> V_9 . V_31 ;
struct V_1 * V_51 ;
struct V_15 * V_16 ;
T_5 * V_154 ;
unsigned short V_13 ;
if ( ! V_10 )
return;
for ( V_143 = 0 ; V_143 < V_10 -> V_8 ; V_143 ++ ) {
V_16 = & V_10 -> V_20 [ V_143 ] ;
V_154 = & V_10 -> V_155 [ V_143 ] ;
F_33 ( V_154 ) ;
F_86 (tt_common_entry, safe,
head, hash_entry) {
if ( V_177 >= 0 && V_25 -> V_13 != V_177 )
continue;
V_77 = F_2 ( V_25 ,
struct V_29 ,
V_28 ) ;
F_109 ( V_24 , V_77 ,
V_38 , V_78 ) ;
if ( F_112 ( & V_77 -> V_110 ) ) {
V_13 = V_77 -> V_28 . V_13 ;
F_56 ( V_79 , V_24 ,
L_1 ,
V_77 -> V_28 . V_11 ,
F_57 ( V_13 ) , V_78 ) ;
F_84 ( & V_25 -> V_6 ) ;
F_17 ( V_77 ) ;
}
}
F_35 ( V_154 ) ;
}
V_38 -> V_178 &= ~ V_179 ;
}
static bool F_114 ( struct V_29 * V_77 ,
char * * V_180 )
{
bool V_181 = false ;
unsigned long V_182 = V_183 ;
unsigned long V_184 = V_185 ;
if ( ( V_77 -> V_28 . V_52 & V_99 ) &&
F_87 ( V_77 -> V_111 , V_182 ) ) {
V_181 = true ;
* V_180 = L_30 ;
}
if ( ( V_77 -> V_28 . V_52 & V_162 ) &&
F_87 ( V_77 -> V_28 . V_106 , V_184 ) ) {
V_181 = true ;
* V_180 = L_31 ;
}
return V_181 ;
}
static void F_115 ( struct V_23 * V_24 )
{
struct V_14 * V_10 = V_24 -> V_9 . V_31 ;
struct V_15 * V_16 ;
struct V_1 * V_153 ;
T_5 * V_154 ;
T_1 V_143 ;
char * V_180 = NULL ;
struct V_5 * V_186 ;
struct V_29 * V_77 ;
for ( V_143 = 0 ; V_143 < V_10 -> V_8 ; V_143 ++ ) {
V_16 = & V_10 -> V_20 [ V_143 ] ;
V_154 = & V_10 -> V_155 [ V_143 ] ;
F_33 ( V_154 ) ;
F_86 (tt_common, node_tmp, head,
hash_entry) {
V_77 = F_2 ( V_186 ,
struct V_29 ,
V_28 ) ;
if ( ! F_114 ( V_77 , & V_180 ) )
continue;
F_56 ( V_79 , V_24 ,
L_1 ,
V_77 -> V_28 . V_11 ,
F_57 ( V_77 -> V_28 . V_13 ) ,
V_180 ) ;
F_84 ( & V_186 -> V_6 ) ;
F_17 ( V_77 ) ;
}
F_35 ( V_154 ) ;
}
}
static void F_116 ( struct V_23 * V_24 )
{
struct V_14 * V_10 ;
T_5 * V_154 ;
struct V_5 * V_25 ;
struct V_29 * V_77 ;
struct V_1 * V_153 ;
struct V_15 * V_16 ;
T_1 V_143 ;
if ( ! V_24 -> V_9 . V_31 )
return;
V_10 = V_24 -> V_9 . V_31 ;
for ( V_143 = 0 ; V_143 < V_10 -> V_8 ; V_143 ++ ) {
V_16 = & V_10 -> V_20 [ V_143 ] ;
V_154 = & V_10 -> V_155 [ V_143 ] ;
F_33 ( V_154 ) ;
F_86 (tt_common_entry, node_tmp,
head, hash_entry) {
F_84 ( & V_25 -> V_6 ) ;
V_77 = F_2 ( V_25 ,
struct V_29 ,
V_28 ) ;
F_17 ( V_77 ) ;
}
F_35 ( V_154 ) ;
}
F_90 ( V_10 ) ;
V_24 -> V_9 . V_31 = NULL ;
}
static bool
F_117 ( struct V_22 * V_26 ,
struct V_29 * V_30 )
{
bool V_89 = false ;
if ( V_26 -> V_28 . V_52 & V_105 &&
V_30 -> V_28 . V_52 & V_105 )
V_89 = true ;
if ( V_26 -> V_28 . V_52 & V_115 &&
V_30 -> V_28 . V_52 & V_115 )
V_89 = true ;
return V_89 ;
}
struct V_43 * F_118 ( struct V_23 * V_24 ,
const T_2 * V_187 ,
const T_2 * V_11 ,
unsigned short V_13 )
{
struct V_22 * V_26 = NULL ;
struct V_29 * V_30 = NULL ;
struct V_43 * V_38 = NULL ;
struct V_36 * V_171 ;
if ( V_187 && F_119 ( V_24 , V_13 ) ) {
V_26 = F_12 ( V_24 , V_187 , V_13 ) ;
if ( ! V_26 ||
( V_26 -> V_28 . V_52 & V_97 ) )
goto V_102;
}
V_30 = F_13 ( V_24 , V_11 , V_13 ) ;
if ( ! V_30 )
goto V_102;
if ( V_26 &&
F_117 ( V_26 , V_30 ) )
goto V_102;
F_8 () ;
V_171 = F_102 ( V_24 , V_30 ) ;
if ( V_171 )
V_38 = V_171 -> V_38 ;
if ( V_38 && ! F_10 ( & V_38 -> V_21 ) )
V_38 = NULL ;
F_11 () ;
V_102:
if ( V_30 )
F_17 ( V_30 ) ;
if ( V_26 )
F_14 ( V_26 ) ;
return V_38 ;
}
static T_1 F_120 ( struct V_23 * V_24 ,
struct V_43 * V_38 ,
unsigned short V_13 )
{
struct V_14 * V_10 = V_24 -> V_9 . V_31 ;
struct V_5 * V_186 ;
struct V_29 * V_77 ;
struct V_15 * V_16 ;
T_1 V_143 , V_188 , V_124 = 0 ;
T_2 V_52 ;
T_6 V_189 ;
for ( V_143 = 0 ; V_143 < V_10 -> V_8 ; V_143 ++ ) {
V_16 = & V_10 -> V_20 [ V_143 ] ;
F_8 () ;
F_9 (tt_common, head, hash_entry) {
V_77 = F_2 ( V_186 ,
struct V_29 ,
V_28 ) ;
if ( V_186 -> V_13 != V_13 )
continue;
if ( V_186 -> V_52 & V_99 )
continue;
if ( V_186 -> V_52 & V_162 )
continue;
if ( ! F_94 ( V_77 ,
V_38 ) )
continue;
V_189 = F_43 ( V_186 -> V_13 ) ;
V_188 = F_121 ( 0 , & V_189 , sizeof( V_189 ) ) ;
V_52 = V_186 -> V_52 & V_190 ;
V_188 = F_121 ( V_188 , & V_52 , sizeof( V_52 ) ) ;
V_124 ^= F_121 ( V_188 , V_186 -> V_11 , V_12 ) ;
}
F_11 () ;
}
return V_124 ;
}
static T_1 F_122 ( struct V_23 * V_24 ,
unsigned short V_13 )
{
struct V_14 * V_10 = V_24 -> V_9 . V_27 ;
struct V_5 * V_186 ;
struct V_15 * V_16 ;
T_1 V_143 , V_188 , V_124 = 0 ;
T_2 V_52 ;
T_6 V_189 ;
for ( V_143 = 0 ; V_143 < V_10 -> V_8 ; V_143 ++ ) {
V_16 = & V_10 -> V_20 [ V_143 ] ;
F_8 () ;
F_9 (tt_common, head, hash_entry) {
if ( V_186 -> V_13 != V_13 )
continue;
if ( V_186 -> V_52 & V_104 )
continue;
V_189 = F_43 ( V_186 -> V_13 ) ;
V_188 = F_121 ( 0 , & V_189 , sizeof( V_189 ) ) ;
V_52 = V_186 -> V_52 & V_190 ;
V_188 = F_121 ( V_188 , & V_52 , sizeof( V_52 ) ) ;
V_124 ^= F_121 ( V_188 , V_186 -> V_11 , V_12 ) ;
}
F_11 () ;
}
return V_124 ;
}
static void F_123 ( struct V_23 * V_24 )
{
struct V_191 * V_2 , * V_51 ;
F_33 ( & V_24 -> V_9 . V_192 ) ;
F_44 (node, safe, &bat_priv->tt.req_list, list) {
F_45 ( & V_2 -> V_46 ) ;
F_23 ( V_2 ) ;
}
F_35 ( & V_24 -> V_9 . V_192 ) ;
}
static void F_124 ( struct V_23 * V_24 ,
struct V_43 * V_38 ,
const void * V_193 ,
T_3 V_194 )
{
F_33 ( & V_38 -> V_195 ) ;
if ( V_194 > 0 ) {
F_23 ( V_38 -> V_193 ) ;
V_38 -> V_194 = 0 ;
V_38 -> V_193 = F_42 ( V_194 , V_56 ) ;
if ( V_38 -> V_193 ) {
memcpy ( V_38 -> V_193 , V_193 , V_194 ) ;
V_38 -> V_194 = V_194 ;
}
}
F_35 ( & V_38 -> V_195 ) ;
}
static void F_125 ( struct V_23 * V_24 )
{
struct V_191 * V_2 , * V_51 ;
F_33 ( & V_24 -> V_9 . V_192 ) ;
F_44 (node, safe, &bat_priv->tt.req_list, list) {
if ( F_87 ( V_2 -> V_196 ,
V_197 ) ) {
F_45 ( & V_2 -> V_46 ) ;
F_23 ( V_2 ) ;
}
}
F_35 ( & V_24 -> V_9 . V_192 ) ;
}
static struct V_191 *
F_126 ( struct V_23 * V_24 ,
struct V_43 * V_38 )
{
struct V_191 * V_198 , * V_199 = NULL ;
F_33 ( & V_24 -> V_9 . V_192 ) ;
F_127 (tt_req_node_tmp, &bat_priv->tt.req_list, list) {
if ( F_3 ( V_198 , V_38 ) &&
! F_87 ( V_198 -> V_196 ,
V_197 ) )
goto V_62;
}
V_199 = F_42 ( sizeof( * V_199 ) , V_56 ) ;
if ( ! V_199 )
goto V_62;
F_7 ( V_199 -> V_11 , V_38 -> V_161 ) ;
V_199 -> V_196 = V_96 ;
F_128 ( & V_199 -> V_46 , & V_24 -> V_9 . V_200 ) ;
V_62:
F_35 ( & V_24 -> V_9 . V_192 ) ;
return V_199 ;
}
static int F_129 ( const void * V_201 , const void * V_202 )
{
const struct V_5 * V_25 = V_201 ;
if ( V_25 -> V_52 & V_104 )
return 0 ;
return 1 ;
}
static int F_130 ( const void * V_201 ,
const void * V_202 )
{
const struct V_5 * V_25 = V_201 ;
const struct V_29 * V_30 ;
const struct V_43 * V_38 = V_202 ;
if ( V_25 -> V_52 & V_99 ||
V_25 -> V_52 & V_162 )
return 0 ;
V_30 = F_2 ( V_25 ,
struct V_29 ,
V_28 ) ;
return F_94 ( V_30 , V_38 ) ;
}
static void F_131 ( struct V_23 * V_24 ,
struct V_14 * V_10 ,
void * V_203 , T_3 V_67 ,
int (* F_132)( const void * , const void * ) ,
void * V_204 )
{
struct V_5 * V_25 ;
struct V_66 * V_117 ;
struct V_15 * V_16 ;
T_3 V_205 , V_206 = 0 ;
T_1 V_143 ;
V_205 = F_50 ( V_67 ) ;
V_117 = (struct V_66 * ) V_203 ;
F_8 () ;
for ( V_143 = 0 ; V_143 < V_10 -> V_8 ; V_143 ++ ) {
V_16 = & V_10 -> V_20 [ V_143 ] ;
F_9 (tt_common_entry,
head, hash_entry) {
if ( V_205 == V_206 )
break;
if ( ( F_132 ) && ( ! F_132 ( V_25 , V_204 ) ) )
continue;
F_7 ( V_117 -> V_11 , V_25 -> V_11 ) ;
V_117 -> V_52 = V_25 -> V_52 ;
V_117 -> V_13 = F_43 ( V_25 -> V_13 ) ;
memset ( V_117 -> V_58 , 0 ,
sizeof( V_117 -> V_58 ) ) ;
V_206 ++ ;
V_117 ++ ;
}
}
F_11 () ;
}
static bool F_133 ( struct V_43 * V_38 ,
struct V_74 * V_120 ,
T_3 V_68 )
{
struct V_74 * V_207 ;
struct V_44 * V_41 ;
T_1 V_124 ;
int V_143 ;
for ( V_143 = 0 ; V_143 < V_68 ; V_143 ++ ) {
V_207 = V_120 + V_143 ;
if ( F_99 ( V_38 -> V_24 ,
V_38 -> V_161 ,
F_134 ( V_207 -> V_13 ) ) )
continue;
V_41 = F_106 ( V_38 ,
F_134 ( V_207 -> V_13 ) ) ;
if ( ! V_41 )
return false ;
V_124 = V_41 -> V_9 . V_124 ;
F_36 ( V_41 ) ;
if ( V_124 != F_135 ( V_207 -> V_124 ) )
return false ;
}
return true ;
}
static void F_136 ( struct V_23 * V_24 )
{
struct V_40 * V_41 ;
F_8 () ;
F_9 (vlan, &bat_priv->softif_vlan_list, list) {
V_41 -> V_9 . V_124 = F_122 ( V_24 , V_41 -> V_13 ) ;
}
F_11 () ;
}
static void F_137 ( struct V_23 * V_24 ,
struct V_43 * V_38 )
{
struct V_44 * V_41 ;
T_1 V_124 ;
F_8 () ;
F_71 (vlan, &orig_node->vlan_list, list) {
if ( F_99 ( V_24 , V_38 -> V_161 ,
V_41 -> V_13 ) )
continue;
V_124 = F_120 ( V_24 , V_38 , V_41 -> V_13 ) ;
V_41 -> V_9 . V_124 = V_124 ;
}
F_11 () ;
}
static int F_138 ( struct V_23 * V_24 ,
struct V_43 * V_208 ,
T_2 V_122 ,
struct V_74 * V_120 ,
T_3 V_68 , bool V_209 )
{
struct V_73 * V_210 = NULL ;
struct V_191 * V_199 = NULL ;
struct V_74 * V_211 ;
struct V_141 * V_142 ;
bool V_89 = false ;
int V_143 , V_8 ;
V_142 = F_139 ( V_24 ) ;
if ( ! V_142 )
goto V_102;
V_199 = F_126 ( V_24 , V_208 ) ;
if ( ! V_199 )
goto V_102;
V_8 = sizeof( * V_210 ) + sizeof( * V_211 ) * V_68 ;
V_210 = F_75 ( V_8 , V_56 ) ;
if ( ! V_210 )
goto V_102;
V_210 -> V_52 = V_212 ;
V_210 -> V_122 = V_122 ;
V_210 -> V_68 = F_43 ( V_68 ) ;
V_211 = (struct V_74 * ) ( V_210 + 1 ) ;
for ( V_143 = 0 ; V_143 < V_68 ; V_143 ++ ) {
V_211 -> V_13 = V_120 -> V_13 ;
V_211 -> V_124 = V_120 -> V_124 ;
V_211 ++ ;
V_120 ++ ;
}
if ( V_209 )
V_210 -> V_52 |= V_213 ;
F_56 ( V_79 , V_24 , L_32 ,
V_208 -> V_161 , V_209 ? 'F' : '.' ) ;
F_140 ( V_24 , V_214 ) ;
F_141 ( V_24 , V_142 -> V_139 -> V_107 ,
V_208 -> V_161 , V_135 , 1 ,
V_210 , V_8 ) ;
V_89 = true ;
V_102:
if ( V_142 )
F_81 ( V_142 ) ;
if ( V_89 && V_199 ) {
F_33 ( & V_24 -> V_9 . V_192 ) ;
F_45 ( & V_199 -> V_46 ) ;
F_35 ( & V_24 -> V_9 . V_192 ) ;
F_23 ( V_199 ) ;
}
F_23 ( V_210 ) ;
return V_89 ;
}
static bool F_142 ( struct V_23 * V_24 ,
struct V_73 * V_116 ,
T_2 * V_215 , T_2 * V_216 )
{
struct V_43 * V_217 ;
struct V_43 * V_218 = NULL ;
struct V_66 * V_117 ;
struct V_73 * V_210 = NULL ;
struct V_74 * V_120 ;
bool V_89 = false , V_209 ;
T_2 V_219 , V_220 ;
T_3 V_119 ;
T_4 V_67 ;
F_56 ( V_79 , V_24 ,
L_33 ,
V_215 , V_116 -> V_122 , V_216 ,
( V_116 -> V_52 & V_213 ? 'F' : '.' ) ) ;
V_217 = F_143 ( V_24 , V_216 ) ;
if ( ! V_217 )
goto V_102;
V_218 = F_143 ( V_24 , V_215 ) ;
if ( ! V_218 )
goto V_102;
V_219 = ( T_2 ) F_20 ( & V_217 -> V_123 ) ;
V_220 = V_116 -> V_122 ;
V_120 = (struct V_74 * ) ( V_116 + 1 ) ;
if ( V_219 != V_220 ||
! F_133 ( V_217 , V_120 ,
F_134 ( V_116 -> V_68 ) ) )
goto V_102;
if ( V_116 -> V_52 & V_213 ||
! V_217 -> V_193 )
V_209 = true ;
else
V_209 = false ;
if ( ! V_209 ) {
F_33 ( & V_217 -> V_195 ) ;
V_67 = V_217 -> V_194 ;
V_119 = F_70 ( V_217 ,
& V_210 ,
& V_117 ,
& V_67 ) ;
if ( ! V_67 )
goto V_62;
memcpy ( V_117 , V_217 -> V_193 ,
V_217 -> V_194 ) ;
F_35 ( & V_217 -> V_195 ) ;
} else {
V_67 = - 1 ;
V_119 = F_70 ( V_217 ,
& V_210 ,
& V_117 ,
& V_67 ) ;
if ( ! V_67 )
goto V_102;
F_131 ( V_24 , V_24 -> V_9 . V_31 ,
V_117 , V_67 ,
F_130 ,
V_217 ) ;
}
V_67 = sizeof( struct V_71 ) + V_119 ;
if ( V_67 > F_20 ( & V_24 -> V_88 ) ) {
F_63 ( V_101 , V_24 -> V_81 ,
L_34 ,
V_218 -> V_161 ) ;
goto V_102;
}
V_210 -> V_52 = V_221 ;
V_210 -> V_122 = V_220 ;
if ( V_209 )
V_210 -> V_52 |= V_213 ;
F_56 ( V_79 , V_24 ,
L_35 ,
V_218 -> V_161 , V_217 -> V_161 ,
V_209 ? 'F' : '.' , V_220 ) ;
F_140 ( V_24 , V_222 ) ;
F_141 ( V_24 , V_217 -> V_161 ,
V_215 , V_135 , 1 , V_210 ,
V_119 ) ;
V_89 = true ;
goto V_102;
V_62:
F_35 ( & V_217 -> V_195 ) ;
V_102:
if ( V_218 )
F_144 ( V_218 ) ;
if ( V_217 )
F_144 ( V_217 ) ;
F_23 ( V_210 ) ;
return V_89 ;
}
static bool F_145 ( struct V_23 * V_24 ,
struct V_73 * V_116 ,
T_2 * V_215 )
{
struct V_73 * V_210 = NULL ;
struct V_141 * V_142 = NULL ;
struct V_66 * V_117 ;
struct V_43 * V_38 ;
T_2 V_223 , V_220 ;
T_3 V_119 ;
bool V_209 ;
T_4 V_67 ;
F_56 ( V_79 , V_24 ,
L_36 ,
V_215 , V_116 -> V_122 ,
( V_116 -> V_52 & V_213 ? 'F' : '.' ) ) ;
F_33 ( & V_24 -> V_9 . V_224 ) ;
V_223 = ( T_2 ) F_20 ( & V_24 -> V_9 . V_103 ) ;
V_220 = V_116 -> V_122 ;
V_38 = F_143 ( V_24 , V_215 ) ;
if ( ! V_38 )
goto V_102;
V_142 = F_139 ( V_24 ) ;
if ( ! V_142 )
goto V_102;
if ( V_116 -> V_52 & V_213 || V_223 != V_220 ||
! V_24 -> V_9 . V_133 )
V_209 = true ;
else
V_209 = false ;
if ( ! V_209 ) {
F_33 ( & V_24 -> V_9 . V_132 ) ;
V_67 = V_24 -> V_9 . V_134 ;
V_119 = F_73 ( V_24 ,
& V_210 ,
& V_117 ,
& V_67 ) ;
if ( ! V_67 )
goto V_62;
memcpy ( V_117 , V_24 -> V_9 . V_133 ,
V_24 -> V_9 . V_134 ) ;
F_35 ( & V_24 -> V_9 . V_132 ) ;
} else {
V_220 = ( T_2 ) F_20 ( & V_24 -> V_9 . V_103 ) ;
V_67 = - 1 ;
V_119 = F_73 ( V_24 ,
& V_210 ,
& V_117 ,
& V_67 ) ;
if ( ! V_67 )
goto V_102;
F_131 ( V_24 , V_24 -> V_9 . V_27 ,
V_117 , V_67 ,
F_129 , NULL ) ;
}
V_210 -> V_52 = V_221 ;
V_210 -> V_122 = V_220 ;
if ( V_209 )
V_210 -> V_52 |= V_213 ;
F_56 ( V_79 , V_24 ,
L_37 ,
V_38 -> V_161 , V_209 ? 'F' : '.' , V_220 ) ;
F_140 ( V_24 , V_222 ) ;
F_141 ( V_24 , V_142 -> V_139 -> V_107 ,
V_215 , V_135 , 1 , V_210 ,
V_119 ) ;
goto V_102;
V_62:
F_35 ( & V_24 -> V_9 . V_132 ) ;
V_102:
F_35 ( & V_24 -> V_9 . V_224 ) ;
if ( V_38 )
F_144 ( V_38 ) ;
if ( V_142 )
F_81 ( V_142 ) ;
F_23 ( V_210 ) ;
return true ;
}
static bool F_146 ( struct V_23 * V_24 ,
struct V_73 * V_116 ,
T_2 * V_215 , T_2 * V_216 )
{
if ( F_147 ( V_24 , V_216 ) )
return F_145 ( V_24 , V_116 , V_215 ) ;
return F_142 ( V_24 , V_116 , V_215 ,
V_216 ) ;
}
static void F_148 ( struct V_23 * V_24 ,
struct V_43 * V_38 ,
struct V_66 * V_117 ,
T_3 V_225 , T_2 V_122 )
{
int V_143 ;
int V_226 ;
for ( V_143 = 0 ; V_143 < V_225 ; V_143 ++ ) {
if ( ( V_117 + V_143 ) -> V_52 & V_59 ) {
V_226 = ( V_117 + V_143 ) -> V_52 & V_99 ;
F_111 ( V_24 , V_38 ,
( V_117 + V_143 ) -> V_11 ,
F_134 ( ( V_117 + V_143 ) -> V_13 ) ,
L_38 ,
V_226 ) ;
} else {
if ( ! F_98 ( V_24 , V_38 ,
( V_117 + V_143 ) -> V_11 ,
F_134 ( ( V_117 + V_143 ) -> V_13 ) ,
( V_117 + V_143 ) -> V_52 , V_122 ) )
return;
}
}
V_38 -> V_178 |= V_179 ;
}
static void F_149 ( struct V_23 * V_24 ,
struct V_66 * V_117 ,
T_2 V_122 , T_2 * V_227 ,
T_3 V_42 )
{
struct V_43 * V_38 ;
V_38 = F_143 ( V_24 , V_227 ) ;
if ( ! V_38 )
goto V_102;
F_113 ( V_24 , V_38 , - 1 ,
L_39 ) ;
F_148 ( V_24 , V_38 , V_117 , V_42 ,
V_122 ) ;
F_33 ( & V_38 -> V_195 ) ;
F_23 ( V_38 -> V_193 ) ;
V_38 -> V_194 = 0 ;
V_38 -> V_193 = NULL ;
F_35 ( & V_38 -> V_195 ) ;
F_65 ( & V_38 -> V_123 , V_122 ) ;
V_102:
if ( V_38 )
F_144 ( V_38 ) ;
}
static void F_150 ( struct V_23 * V_24 ,
struct V_43 * V_38 ,
T_3 V_225 , T_2 V_122 ,
struct V_66 * V_117 )
{
F_148 ( V_24 , V_38 , V_117 ,
V_225 , V_122 ) ;
F_124 ( V_24 , V_38 , V_117 ,
F_49 ( V_225 ) ) ;
F_65 ( & V_38 -> V_123 , V_122 ) ;
}
bool F_151 ( struct V_23 * V_24 , const T_2 * V_11 ,
unsigned short V_13 )
{
struct V_22 * V_26 ;
bool V_89 = false ;
V_26 = F_12 ( V_24 , V_11 , V_13 ) ;
if ( ! V_26 )
goto V_102;
if ( ( V_26 -> V_28 . V_52 & V_97 ) ||
( V_26 -> V_28 . V_52 & V_99 ) )
goto V_102;
V_89 = true ;
V_102:
if ( V_26 )
F_14 ( V_26 ) ;
return V_89 ;
}
static void F_152 ( struct V_23 * V_24 ,
struct V_73 * V_116 ,
T_2 * V_227 , T_3 V_42 )
{
struct V_191 * V_2 , * V_51 ;
struct V_43 * V_38 = NULL ;
struct V_66 * V_117 ;
T_2 * V_228 = ( T_2 * ) V_116 ;
T_3 V_118 ;
F_56 ( V_79 , V_24 ,
L_40 ,
V_227 , V_116 -> V_122 , V_42 ,
( V_116 -> V_52 & V_213 ? 'F' : '.' ) ) ;
V_38 = F_143 ( V_24 , V_227 ) ;
if ( ! V_38 )
goto V_102;
F_33 ( & V_38 -> V_229 ) ;
V_118 = sizeof( struct V_74 ) ;
V_118 *= F_134 ( V_116 -> V_68 ) ;
V_118 += sizeof( * V_116 ) ;
V_228 += V_118 ;
V_117 = (struct V_66 * ) V_228 ;
if ( V_116 -> V_52 & V_213 ) {
F_149 ( V_24 , V_117 , V_116 -> V_122 ,
V_227 , V_42 ) ;
} else {
F_150 ( V_24 , V_38 , V_42 ,
V_116 -> V_122 , V_117 ) ;
}
F_137 ( V_24 , V_38 ) ;
F_35 ( & V_38 -> V_229 ) ;
F_33 ( & V_24 -> V_9 . V_192 ) ;
F_44 (node, safe, &bat_priv->tt.req_list, list) {
if ( ! F_3 ( V_2 -> V_11 , V_227 ) )
continue;
F_45 ( & V_2 -> V_46 ) ;
F_23 ( V_2 ) ;
}
F_35 ( & V_24 -> V_9 . V_192 ) ;
V_102:
if ( V_38 )
F_144 ( V_38 ) ;
}
static void F_153 ( struct V_23 * V_24 )
{
struct V_230 * V_2 , * V_51 ;
F_33 ( & V_24 -> V_9 . V_231 ) ;
F_44 (node, safe, &bat_priv->tt.roam_list, list) {
F_45 ( & V_2 -> V_46 ) ;
F_23 ( V_2 ) ;
}
F_35 ( & V_24 -> V_9 . V_231 ) ;
}
static void F_154 ( struct V_23 * V_24 )
{
struct V_230 * V_2 , * V_51 ;
F_33 ( & V_24 -> V_9 . V_231 ) ;
F_44 (node, safe, &bat_priv->tt.roam_list, list) {
if ( ! F_87 ( V_2 -> V_232 ,
V_233 ) )
continue;
F_45 ( & V_2 -> V_46 ) ;
F_23 ( V_2 ) ;
}
F_35 ( & V_24 -> V_9 . V_231 ) ;
}
static bool F_155 ( struct V_23 * V_24 ,
T_2 * V_234 )
{
struct V_230 * V_235 ;
bool V_89 = false ;
F_33 ( & V_24 -> V_9 . V_231 ) ;
F_127 (tt_roam_node, &bat_priv->tt.roam_list, list) {
if ( ! F_3 ( V_235 -> V_11 , V_234 ) )
continue;
if ( F_87 ( V_235 -> V_232 ,
V_233 ) )
continue;
if ( ! F_156 ( & V_235 -> V_236 ) )
goto V_62;
V_89 = true ;
break;
}
if ( ! V_89 ) {
V_235 = F_42 ( sizeof( * V_235 ) , V_56 ) ;
if ( ! V_235 )
goto V_62;
V_235 -> V_232 = V_96 ;
F_65 ( & V_235 -> V_236 ,
V_237 - 1 ) ;
F_7 ( V_235 -> V_11 , V_234 ) ;
F_128 ( & V_235 -> V_46 , & V_24 -> V_9 . V_238 ) ;
V_89 = true ;
}
V_62:
F_35 ( & V_24 -> V_9 . V_231 ) ;
return V_89 ;
}
static void F_68 ( struct V_23 * V_24 , T_2 * V_234 ,
unsigned short V_13 ,
struct V_43 * V_38 )
{
struct V_141 * V_142 ;
struct V_239 V_240 ;
V_142 = F_139 ( V_24 ) ;
if ( ! V_142 )
goto V_102;
if ( ! F_155 ( V_24 , V_234 ) )
goto V_102;
F_56 ( V_79 , V_24 ,
L_41 ,
V_38 -> V_161 , V_234 , F_57 ( V_13 ) ) ;
F_140 ( V_24 , V_241 ) ;
memcpy ( V_240 . V_234 , V_234 , sizeof( V_240 . V_234 ) ) ;
V_240 . V_13 = F_43 ( V_13 ) ;
F_141 ( V_24 , V_142 -> V_139 -> V_107 ,
V_38 -> V_161 , V_242 , 1 ,
& V_240 , sizeof( V_240 ) ) ;
V_102:
if ( V_142 )
F_81 ( V_142 ) ;
}
static void F_157 ( struct V_243 * V_244 )
{
struct V_245 * V_245 ;
struct V_246 * V_247 ;
struct V_23 * V_24 ;
V_245 = F_2 ( V_244 , struct V_245 , V_244 ) ;
V_247 = F_2 ( V_245 , struct V_246 , V_244 ) ;
V_24 = F_2 ( V_247 , struct V_23 , V_9 ) ;
F_88 ( V_24 , V_248 ) ;
F_115 ( V_24 ) ;
F_125 ( V_24 ) ;
F_154 ( V_24 ) ;
F_158 ( V_249 , & V_24 -> V_9 . V_244 ,
F_159 ( V_250 ) ) ;
}
void F_160 ( struct V_23 * V_24 )
{
F_161 ( V_24 , V_135 , 1 ) ;
F_162 ( V_24 , V_135 , 1 ) ;
F_163 ( & V_24 -> V_9 . V_244 ) ;
F_89 ( V_24 ) ;
F_116 ( V_24 ) ;
F_123 ( V_24 ) ;
F_92 ( V_24 ) ;
F_153 ( V_24 ) ;
F_23 ( V_24 -> V_9 . V_133 ) ;
}
static void F_164 ( struct V_23 * V_24 ,
T_3 V_52 , bool V_251 , bool V_33 )
{
struct V_14 * V_10 = V_24 -> V_9 . V_27 ;
struct V_5 * V_25 ;
T_3 V_252 = 0 ;
struct V_15 * V_16 ;
T_1 V_143 ;
if ( ! V_10 )
return;
for ( V_143 = 0 ; V_143 < V_10 -> V_8 ; V_143 ++ ) {
V_16 = & V_10 -> V_20 [ V_143 ] ;
F_8 () ;
F_9 (tt_common_entry,
head, hash_entry) {
if ( V_251 ) {
if ( ( V_25 -> V_52 & V_52 ) == V_52 )
continue;
V_25 -> V_52 |= V_52 ;
} else {
if ( ! ( V_25 -> V_52 & V_52 ) )
continue;
V_25 -> V_52 &= ~ V_52 ;
}
V_252 ++ ;
if ( ! V_33 )
continue;
F_28 ( V_24 ,
V_25 -> V_13 ) ;
}
F_11 () ;
}
}
static void F_165 ( struct V_23 * V_24 )
{
struct V_14 * V_10 = V_24 -> V_9 . V_27 ;
struct V_5 * V_186 ;
struct V_22 * V_84 ;
struct V_40 * V_41 ;
struct V_1 * V_153 ;
struct V_15 * V_16 ;
T_5 * V_154 ;
T_1 V_143 ;
if ( ! V_10 )
return;
for ( V_143 = 0 ; V_143 < V_10 -> V_8 ; V_143 ++ ) {
V_16 = & V_10 -> V_20 [ V_143 ] ;
V_154 = & V_10 -> V_155 [ V_143 ] ;
F_33 ( V_154 ) ;
F_86 (tt_common, node_tmp, head,
hash_entry) {
if ( ! ( V_186 -> V_52 & V_97 ) )
continue;
F_56 ( V_79 , V_24 ,
L_42 ,
V_186 -> V_11 ,
F_57 ( V_186 -> V_13 ) ) ;
F_29 ( V_24 , V_186 -> V_13 ) ;
F_84 ( & V_186 -> V_6 ) ;
V_84 = F_2 ( V_186 ,
struct V_22 ,
V_28 ) ;
V_41 = F_25 ( V_24 , V_186 -> V_13 ) ;
F_27 ( V_41 ) ;
F_27 ( V_41 ) ;
F_14 ( V_84 ) ;
}
F_35 ( V_154 ) ;
}
}
static void F_166 ( struct V_23 * V_24 )
{
F_167 ( V_24 ) ;
if ( F_20 ( & V_24 -> V_9 . V_64 ) < 1 ) {
if ( ! F_156 ( & V_24 -> V_9 . V_253 ) )
F_74 ( V_24 ) ;
return;
}
F_164 ( V_24 , V_104 , false , true ) ;
F_165 ( V_24 ) ;
F_136 ( V_24 ) ;
F_48 ( & V_24 -> V_9 . V_103 ) ;
F_56 ( V_79 , V_24 ,
L_43 ,
( T_2 ) F_20 ( & V_24 -> V_9 . V_103 ) ) ;
F_65 ( & V_24 -> V_9 . V_253 , V_254 ) ;
F_74 ( V_24 ) ;
}
void F_168 ( struct V_23 * V_24 )
{
F_33 ( & V_24 -> V_9 . V_224 ) ;
F_166 ( V_24 ) ;
F_35 ( & V_24 -> V_9 . V_224 ) ;
}
bool F_169 ( struct V_23 * V_24 , T_2 * V_187 ,
T_2 * V_255 , unsigned short V_13 )
{
struct V_22 * V_26 = NULL ;
struct V_29 * V_30 = NULL ;
struct V_40 * V_41 ;
bool V_89 = false ;
V_41 = F_25 ( V_24 , V_13 ) ;
if ( ! V_41 || ! F_20 ( & V_41 -> V_256 ) )
goto V_102;
V_26 = F_12 ( V_24 , V_255 , V_13 ) ;
if ( ! V_26 )
goto V_102;
V_30 = F_13 ( V_24 , V_187 , V_13 ) ;
if ( ! V_30 )
goto V_102;
if ( ! F_117 ( V_26 , V_30 ) )
goto V_102;
V_89 = true ;
V_102:
if ( V_41 )
F_27 ( V_41 ) ;
if ( V_30 )
F_17 ( V_30 ) ;
if ( V_26 )
F_14 ( V_26 ) ;
return V_89 ;
}
static void F_170 ( struct V_23 * V_24 ,
struct V_43 * V_38 ,
const void * V_193 , T_3 V_257 ,
struct V_66 * V_117 ,
T_3 V_225 , T_2 V_122 )
{
T_2 V_219 = ( T_2 ) F_20 ( & V_38 -> V_123 ) ;
struct V_74 * V_120 ;
bool V_209 = true ;
bool V_258 ;
V_120 = (struct V_74 * ) V_193 ;
V_258 = V_38 -> V_178 & V_179 ;
if ( ( ! V_258 && V_122 == 1 ) || V_122 - V_219 == 1 ) {
if ( ! V_225 ) {
V_209 = false ;
goto V_259;
}
F_33 ( & V_38 -> V_229 ) ;
F_150 ( V_24 , V_38 , V_225 ,
V_122 , V_117 ) ;
F_137 ( V_24 , V_38 ) ;
F_35 ( & V_38 -> V_229 ) ;
if ( ! F_133 ( V_38 , V_120 ,
V_257 ) )
goto V_259;
} else {
if ( ! V_258 || V_122 != V_219 ||
! F_133 ( V_38 , V_120 ,
V_257 ) ) {
V_259:
F_56 ( V_79 , V_24 ,
L_44 ,
V_38 -> V_161 , V_122 , V_219 ,
V_225 ) ;
F_138 ( V_24 , V_38 , V_122 ,
V_120 , V_257 ,
V_209 ) ;
return;
}
}
}
bool F_171 ( struct V_23 * V_24 ,
T_2 * V_11 , unsigned short V_13 )
{
struct V_29 * V_30 ;
bool V_89 = false ;
V_30 = F_13 ( V_24 , V_11 , V_13 ) ;
if ( ! V_30 )
goto V_102;
V_89 = V_30 -> V_28 . V_52 & V_99 ;
F_17 ( V_30 ) ;
V_102:
return V_89 ;
}
bool F_172 ( struct V_23 * V_24 ,
T_2 * V_11 , unsigned short V_13 )
{
struct V_22 * V_26 ;
bool V_89 = false ;
V_26 = F_12 ( V_24 , V_11 , V_13 ) ;
if ( ! V_26 )
goto V_102;
V_89 = V_26 -> V_28 . V_52 & V_99 ;
F_14 ( V_26 ) ;
V_102:
return V_89 ;
}
bool F_173 ( struct V_23 * V_24 ,
struct V_43 * V_38 ,
const unsigned char * V_11 ,
unsigned short V_13 )
{
bool V_89 = false ;
if ( ! F_98 ( V_24 , V_38 , V_11 , V_13 ,
V_162 ,
F_20 ( & V_38 -> V_123 ) ) )
goto V_102;
F_56 ( V_79 , V_24 ,
L_45 ,
V_11 , F_57 ( V_13 ) , V_38 -> V_161 ) ;
V_89 = true ;
V_102:
return V_89 ;
}
void F_174 ( struct V_80 * V_81 )
{
struct V_23 * V_24 = F_60 ( V_81 ) ;
int V_88 = F_20 ( & V_24 -> V_88 ) ;
int V_87 , V_152 = V_248 / 2 ;
bool V_260 = false ;
F_33 ( & V_24 -> V_9 . V_224 ) ;
while ( true ) {
V_87 = F_51 ( V_24 ) ;
if ( V_88 >= V_87 )
break;
F_88 ( V_24 , V_152 ) ;
F_165 ( V_24 ) ;
V_152 /= 2 ;
V_260 = true ;
F_63 ( V_101 , V_81 ,
L_46 ,
V_88 ) ;
}
if ( V_260 )
F_166 ( V_24 ) ;
F_35 ( & V_24 -> V_9 . V_224 ) ;
}
static void F_175 ( struct V_23 * V_24 ,
struct V_43 * V_161 ,
T_2 V_52 , void * V_261 ,
T_3 V_262 )
{
struct V_74 * V_120 ;
struct V_66 * V_117 ;
struct V_73 * V_116 ;
T_3 V_42 , V_68 ;
if ( V_262 < sizeof( * V_116 ) )
return;
V_116 = (struct V_73 * ) V_261 ;
V_262 -= sizeof( * V_116 ) ;
V_68 = F_134 ( V_116 -> V_68 ) ;
if ( V_262 < sizeof( * V_120 ) * V_68 )
return;
V_120 = (struct V_74 * ) ( V_116 + 1 ) ;
V_117 = (struct V_66 * ) ( V_120 + V_68 ) ;
V_262 -= sizeof( * V_120 ) * V_68 ;
V_42 = F_50 ( V_262 ) ;
F_170 ( V_24 , V_161 , V_120 , V_68 , V_117 ,
V_42 , V_116 -> V_122 ) ;
}
static int F_176 ( struct V_23 * V_24 ,
T_2 * V_187 , T_2 * V_255 ,
void * V_261 ,
T_3 V_262 )
{
struct V_73 * V_116 ;
T_3 V_263 , V_206 ;
char V_264 ;
bool V_89 ;
if ( V_262 < sizeof( * V_116 ) )
return V_265 ;
V_116 = (struct V_73 * ) V_261 ;
V_262 -= sizeof( * V_116 ) ;
V_263 = sizeof( struct V_74 ) ;
V_263 *= F_134 ( V_116 -> V_68 ) ;
if ( V_262 < V_263 )
return V_265 ;
V_262 -= V_263 ;
V_206 = F_50 ( V_262 ) ;
switch ( V_116 -> V_52 & V_266 ) {
case V_212 :
F_140 ( V_24 , V_267 ) ;
V_89 = F_146 ( V_24 , V_116 , V_187 , V_255 ) ;
if ( ! V_89 ) {
if ( V_116 -> V_52 & V_213 )
V_264 = 'F' ;
else
V_264 = '.' ;
F_56 ( V_79 , V_24 ,
L_47 ,
V_255 , V_264 ) ;
return V_268 ;
}
break;
case V_221 :
F_140 ( V_24 , V_269 ) ;
if ( F_147 ( V_24 , V_255 ) ) {
F_152 ( V_24 , V_116 ,
V_187 , V_206 ) ;
return V_265 ;
}
if ( V_116 -> V_52 & V_213 )
V_264 = 'F' ;
else
V_264 = '.' ;
F_56 ( V_79 , V_24 ,
L_48 , V_255 , V_264 ) ;
return V_268 ;
}
return V_265 ;
}
static int F_177 ( struct V_23 * V_24 ,
T_2 * V_187 , T_2 * V_255 ,
void * V_261 ,
T_3 V_262 )
{
struct V_239 * V_270 ;
struct V_43 * V_38 = NULL ;
if ( ! F_147 ( V_24 , V_255 ) )
return V_268 ;
if ( V_262 < sizeof( * V_270 ) )
goto V_102;
V_38 = F_143 ( V_24 , V_187 ) ;
if ( ! V_38 )
goto V_102;
F_140 ( V_24 , V_271 ) ;
V_270 = (struct V_239 * ) V_261 ;
F_56 ( V_79 , V_24 ,
L_49 ,
V_187 , V_270 -> V_234 ) ;
F_98 ( V_24 , V_38 , V_270 -> V_234 ,
F_134 ( V_270 -> V_13 ) , V_99 ,
F_20 ( & V_38 -> V_123 ) + 1 ) ;
V_102:
if ( V_38 )
F_144 ( V_38 ) ;
return V_265 ;
}
int F_178 ( struct V_23 * V_24 )
{
int V_89 ;
F_179 ( ! ( V_190 & V_112 ) ) ;
V_89 = F_52 ( V_24 ) ;
if ( V_89 < 0 )
return V_89 ;
V_89 = F_91 ( V_24 ) ;
if ( V_89 < 0 )
return V_89 ;
F_180 ( V_24 , F_175 ,
F_176 ,
V_135 , 1 , V_109 ) ;
F_180 ( V_24 , NULL ,
F_177 ,
V_242 , 1 , V_109 ) ;
F_181 ( & V_24 -> V_9 . V_244 , F_157 ) ;
F_158 ( V_249 , & V_24 -> V_9 . V_244 ,
F_159 ( V_250 ) ) ;
return 1 ;
}
bool F_182 ( struct V_23 * V_24 ,
const T_2 * V_11 , unsigned short V_13 )
{
struct V_29 * V_9 ;
bool V_89 ;
V_9 = F_13 ( V_24 , V_11 , V_13 ) ;
if ( ! V_9 )
return false ;
V_89 = V_9 -> V_28 . V_52 & V_115 ;
F_17 ( V_9 ) ;
return V_89 ;
}

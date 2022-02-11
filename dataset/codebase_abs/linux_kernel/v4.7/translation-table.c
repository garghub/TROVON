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
V_30 . V_23 ) ;
F_15 ( V_28 -> V_36 ) ;
F_16 ( V_28 , V_30 . V_37 ) ;
}
static void
F_17 ( struct V_24 * V_28 )
{
F_18 ( & V_28 -> V_30 . V_23 ,
F_14 ) ;
}
static void F_19 ( struct V_34 * V_35 )
{
struct V_31 * V_32 ;
V_32 = F_2 ( V_35 , struct V_31 ,
V_30 . V_23 ) ;
F_20 ( V_32 ) ;
F_16 ( V_32 , V_30 . V_37 ) ;
}
static void
F_21 ( struct V_31 * V_32 )
{
F_18 ( & V_32 -> V_30 . V_23 ,
F_19 ) ;
}
int F_22 ( struct V_25 * V_26 ,
const T_2 * V_14 , unsigned short V_9 )
{
struct V_31 * V_32 ;
int V_38 ;
V_32 = F_13 ( V_26 , V_14 , V_9 ) ;
if ( ! V_32 )
return 0 ;
V_38 = F_23 ( & V_32 -> V_39 ) ;
F_21 ( V_32 ) ;
return V_38 ;
}
static void F_24 ( struct V_25 * V_26 ,
unsigned short V_9 , int V_40 )
{
struct V_41 * V_36 ;
V_36 = F_25 ( V_26 , V_9 ) ;
if ( ! V_36 )
return;
F_26 ( V_40 , & V_36 -> V_12 . V_42 ) ;
F_15 ( V_36 ) ;
}
static void F_27 ( struct V_25 * V_26 ,
unsigned short V_9 )
{
F_24 ( V_26 , V_9 , 1 ) ;
}
static void F_28 ( struct V_25 * V_26 ,
unsigned short V_9 )
{
F_24 ( V_26 , V_9 , - 1 ) ;
}
static void F_29 ( struct V_43 * V_44 ,
unsigned short V_9 , int V_40 )
{
struct V_45 * V_36 ;
V_36 = F_30 ( V_44 , V_9 ) ;
if ( ! V_36 )
return;
if ( F_31 ( V_40 , & V_36 -> V_12 . V_42 ) == 0 ) {
F_32 ( & V_44 -> V_46 ) ;
if ( ! F_33 ( & V_36 -> V_47 ) ) {
F_34 ( & V_36 -> V_47 ) ;
F_35 ( V_36 ) ;
}
F_36 ( & V_44 -> V_46 ) ;
}
F_35 ( V_36 ) ;
}
static void F_37 ( struct V_43 * V_44 ,
unsigned short V_9 )
{
F_29 ( V_44 , V_9 , 1 ) ;
}
static void F_38 ( struct V_43 * V_44 ,
unsigned short V_9 )
{
F_29 ( V_44 , V_9 , - 1 ) ;
}
static void F_39 ( struct V_34 * V_35 )
{
struct V_48 * V_49 ;
V_49 = F_2 ( V_35 , struct V_48 ,
V_23 ) ;
F_40 ( V_49 -> V_44 ) ;
F_16 ( V_49 , V_37 ) ;
}
static void
F_41 ( struct V_48 * V_49 )
{
F_18 ( & V_49 -> V_23 , F_39 ) ;
}
static void F_42 ( struct V_25 * V_26 ,
struct V_24 * V_28 ,
T_2 V_50 )
{
struct V_51 * V_52 , * V_53 , * V_54 ;
struct V_5 * V_30 = & V_28 -> V_30 ;
T_2 V_55 = V_30 -> V_55 | V_50 ;
bool V_56 = false ;
bool V_57 , V_58 ;
V_52 = F_43 ( sizeof( * V_52 ) , V_59 ) ;
if ( ! V_52 )
return;
V_52 -> V_60 . V_55 = V_55 ;
memset ( V_52 -> V_60 . V_61 , 0 ,
sizeof( V_52 -> V_60 . V_61 ) ) ;
F_7 ( V_52 -> V_60 . V_14 , V_30 -> V_14 ) ;
V_52 -> V_60 . V_9 = F_44 ( V_30 -> V_9 ) ;
V_57 = V_55 & V_62 ;
F_32 ( & V_26 -> V_12 . V_63 ) ;
F_45 (entry, safe, &bat_priv->tt.changes_list,
list) {
if ( ! F_3 ( V_53 -> V_60 . V_14 , V_30 -> V_14 ) )
continue;
V_58 = V_53 -> V_60 . V_55 & V_62 ;
if ( ! V_57 && V_58 )
goto V_64;
if ( V_57 && ! V_58 )
goto V_64;
if ( ! V_57 && ! V_58 )
V_53 -> V_60 . V_55 = V_55 ;
continue;
V_64:
F_46 ( & V_53 -> V_47 ) ;
F_47 ( V_53 ) ;
F_47 ( V_52 ) ;
V_56 = true ;
goto V_65;
}
F_48 ( & V_52 -> V_47 , & V_26 -> V_12 . V_66 ) ;
V_65:
F_36 ( & V_26 -> V_12 . V_63 ) ;
if ( V_56 )
F_49 ( & V_26 -> V_12 . V_67 ) ;
else
F_50 ( & V_26 -> V_12 . V_67 ) ;
}
static int F_51 ( int V_68 )
{
return V_68 * sizeof( struct V_69 ) ;
}
static T_3 F_52 ( T_3 V_70 )
{
return V_70 / F_51 ( 1 ) ;
}
static int F_53 ( struct V_25 * V_26 )
{
T_3 V_71 = 0 ;
T_3 V_72 = 0 ;
struct V_41 * V_36 ;
int V_73 ;
F_8 () ;
F_9 (vlan, &bat_priv->softif_vlan_list, list) {
V_71 ++ ;
V_72 += F_23 ( & V_36 -> V_12 . V_42 ) ;
}
F_11 () ;
V_73 = sizeof( struct V_74 ) ;
V_73 += sizeof( struct V_75 ) ;
V_73 += sizeof( struct V_76 ) ;
V_73 += V_71 * sizeof( struct V_77 ) ;
return V_73 + F_51 ( V_72 ) ;
}
static int F_54 ( struct V_25 * V_26 )
{
if ( V_26 -> V_12 . V_29 )
return 0 ;
V_26 -> V_12 . V_29 = F_55 ( 1024 ) ;
if ( ! V_26 -> V_12 . V_29 )
return - V_78 ;
F_56 ( V_26 -> V_12 . V_29 ,
& V_79 ) ;
return 0 ;
}
static void F_57 ( struct V_25 * V_26 ,
struct V_31 * V_80 ,
const char * V_81 )
{
F_58 ( V_82 , V_26 ,
L_1 ,
V_80 -> V_30 . V_14 ,
F_59 ( V_80 -> V_30 . V_9 ) , V_81 ) ;
F_60 ( V_26 -> V_12 . V_33 , F_1 ,
F_4 , & V_80 -> V_30 ) ;
F_21 ( V_80 ) ;
}
bool F_61 ( struct V_83 * V_84 , const T_2 * V_14 ,
unsigned short V_9 , int V_85 , T_1 V_86 )
{
struct V_25 * V_26 = F_62 ( V_84 ) ;
struct V_24 * V_87 ;
struct V_31 * V_80 = NULL ;
struct V_88 * V_88 = F_63 ( V_84 ) ;
struct V_41 * V_36 ;
struct V_83 * V_89 = NULL ;
struct V_17 * V_18 ;
struct V_48 * V_49 ;
int V_90 , V_91 , V_92 ;
bool V_93 = false ;
bool V_94 = false ;
T_2 V_95 ;
T_1 V_96 ;
if ( V_85 != V_97 )
V_89 = F_64 ( V_88 , V_85 ) ;
V_87 = F_12 ( V_26 , V_14 , V_9 ) ;
if ( ! F_65 ( V_14 ) )
V_80 = F_13 ( V_26 , V_14 , V_9 ) ;
if ( V_87 ) {
V_87 -> V_98 = V_99 ;
if ( V_87 -> V_30 . V_55 & V_100 ) {
F_58 ( V_82 , V_26 ,
L_2 ,
V_14 , F_59 ( V_9 ) ) ;
V_87 -> V_30 . V_55 &= ~ V_100 ;
goto V_101;
}
if ( V_87 -> V_30 . V_55 & V_102 ) {
F_58 ( V_82 , V_26 ,
L_3 ,
V_14 , F_59 ( V_9 ) ) ;
V_87 -> V_30 . V_55 &= ~ V_102 ;
V_94 = true ;
}
goto V_103;
}
V_91 = F_53 ( V_26 ) ;
V_91 += F_51 ( 1 ) ;
V_92 = F_23 ( & V_26 -> V_92 ) ;
if ( V_91 > V_92 ) {
F_66 ( V_104 , V_84 ,
L_4 ,
V_91 , V_92 , V_14 ) ;
goto V_105;
}
V_87 = F_43 ( sizeof( * V_87 ) , V_59 ) ;
if ( ! V_87 )
goto V_105;
V_36 = F_25 ( V_26 , V_9 ) ;
if ( ! V_36 ) {
F_66 ( V_104 , V_84 ,
L_5 ,
V_14 , F_59 ( V_9 ) ) ;
F_47 ( V_87 ) ;
V_87 = NULL ;
goto V_105;
}
F_58 ( V_82 , V_26 ,
L_6 ,
V_14 , F_59 ( V_9 ) ,
( T_2 ) F_23 ( & V_26 -> V_12 . V_106 ) ) ;
F_7 ( V_87 -> V_30 . V_14 , V_14 ) ;
V_87 -> V_30 . V_55 = V_107 ;
V_87 -> V_30 . V_9 = V_9 ;
if ( F_67 ( V_89 ) )
V_87 -> V_30 . V_55 |= V_108 ;
F_68 ( & V_87 -> V_30 . V_23 ) ;
F_69 ( & V_87 -> V_30 . V_23 ) ;
V_87 -> V_98 = V_99 ;
V_87 -> V_30 . V_109 = V_87 -> V_98 ;
V_87 -> V_36 = V_36 ;
if ( F_3 ( V_14 , V_84 -> V_110 ) ||
F_65 ( V_14 ) )
V_87 -> V_30 . V_55 |= V_111 ;
V_90 = F_70 ( V_26 -> V_12 . V_29 , F_1 ,
F_4 , & V_87 -> V_30 ,
& V_87 -> V_30 . V_6 ) ;
if ( F_71 ( V_90 != 0 ) ) {
F_17 ( V_87 ) ;
goto V_105;
}
V_101:
F_42 ( V_26 , V_87 , V_112 ) ;
V_103:
if ( V_80 && ! ( V_80 -> V_30 . V_55 & V_102 ) ) {
V_18 = & V_80 -> V_113 ;
F_8 () ;
F_9 (orig_entry, head, list) {
F_72 ( V_26 , V_80 -> V_30 . V_14 ,
V_80 -> V_30 . V_9 ,
V_49 -> V_44 ) ;
}
F_11 () ;
if ( V_94 ) {
F_57 ( V_26 , V_80 ,
L_7 ) ;
V_80 = NULL ;
} else {
V_80 -> V_30 . V_55 |= V_102 ;
V_80 -> V_114 = V_99 ;
}
}
V_95 = V_87 -> V_30 . V_55 & V_115 ;
if ( F_67 ( V_89 ) )
V_87 -> V_30 . V_55 |= V_108 ;
else
V_87 -> V_30 . V_55 &= ~ V_108 ;
V_96 = ( V_86 & V_26 -> V_116 ) ;
if ( V_26 -> V_116 &&
V_96 == V_26 -> V_117 )
V_87 -> V_30 . V_55 |= V_118 ;
else
V_87 -> V_30 . V_55 &= ~ V_118 ;
if ( V_95 ^ ( V_87 -> V_30 . V_55 & V_115 ) )
F_42 ( V_26 , V_87 , V_112 ) ;
V_93 = true ;
V_105:
if ( V_89 )
F_73 ( V_89 ) ;
if ( V_87 )
F_17 ( V_87 ) ;
if ( V_80 )
F_21 ( V_80 ) ;
return V_93 ;
}
static T_3
F_74 ( struct V_43 * V_44 ,
struct V_76 * * V_119 ,
struct V_69 * * V_120 ,
T_4 * V_70 )
{
T_3 V_71 = 0 ;
T_3 V_42 = 0 ;
T_3 V_121 ;
T_3 V_122 ;
struct V_77 * V_123 ;
struct V_45 * V_36 ;
T_2 * V_124 ;
F_8 () ;
F_9 (vlan, &orig_node->vlan_list, list) {
V_71 ++ ;
V_42 += F_23 ( & V_36 -> V_12 . V_42 ) ;
}
V_121 = sizeof( * * V_119 ) ;
V_121 += V_71 * sizeof( * V_123 ) ;
if ( * V_70 < 0 )
* V_70 = F_51 ( V_42 ) ;
V_122 = * V_70 ;
V_122 += V_121 ;
* V_119 = F_43 ( V_122 , V_59 ) ;
if ( ! * V_119 ) {
* V_70 = 0 ;
goto V_105;
}
( * V_119 ) -> V_55 = V_112 ;
( * V_119 ) -> V_125 = F_23 ( & V_44 -> V_126 ) ;
( * V_119 ) -> V_71 = F_44 ( V_71 ) ;
V_123 = (struct V_77 * ) ( * V_119 + 1 ) ;
F_9 (vlan, &orig_node->vlan_list, list) {
V_123 -> V_9 = F_44 ( V_36 -> V_9 ) ;
V_123 -> V_127 = F_75 ( V_36 -> V_12 . V_127 ) ;
V_123 ++ ;
}
V_124 = ( T_2 * ) * V_119 + V_121 ;
* V_120 = (struct V_69 * ) V_124 ;
V_105:
F_11 () ;
return V_122 ;
}
static T_3
F_76 ( struct V_25 * V_26 ,
struct V_76 * * V_119 ,
struct V_69 * * V_120 ,
T_4 * V_70 )
{
struct V_77 * V_123 ;
struct V_41 * V_36 ;
T_3 V_71 = 0 ;
T_3 V_42 = 0 ;
T_3 V_122 ;
T_2 * V_124 ;
int V_121 ;
F_8 () ;
F_9 (vlan, &bat_priv->softif_vlan_list, list) {
V_71 ++ ;
V_42 += F_23 ( & V_36 -> V_12 . V_42 ) ;
}
V_121 = sizeof( * * V_119 ) ;
V_121 += V_71 * sizeof( * V_123 ) ;
if ( * V_70 < 0 )
* V_70 = F_51 ( V_42 ) ;
V_122 = * V_70 ;
V_122 += V_121 ;
* V_119 = F_43 ( V_122 , V_59 ) ;
if ( ! * V_119 ) {
V_122 = 0 ;
goto V_105;
}
( * V_119 ) -> V_55 = V_112 ;
( * V_119 ) -> V_125 = F_23 ( & V_26 -> V_12 . V_106 ) ;
( * V_119 ) -> V_71 = F_44 ( V_71 ) ;
V_123 = (struct V_77 * ) ( * V_119 + 1 ) ;
F_9 (vlan, &bat_priv->softif_vlan_list, list) {
V_123 -> V_9 = F_44 ( V_36 -> V_9 ) ;
V_123 -> V_127 = F_75 ( V_36 -> V_12 . V_127 ) ;
V_123 ++ ;
}
V_124 = ( T_2 * ) * V_119 + V_121 ;
* V_120 = (struct V_69 * ) V_124 ;
V_105:
F_11 () ;
return V_122 ;
}
static void F_77 ( struct V_25 * V_26 )
{
struct V_51 * V_53 , * V_54 ;
struct V_76 * V_119 ;
struct V_69 * V_120 ;
int V_128 , V_129 = 0 ;
int V_130 = 0 ;
int V_131 = 0 ;
T_3 V_122 ;
V_130 = F_23 ( & V_26 -> V_12 . V_67 ) ;
V_128 = F_51 ( V_130 ) ;
if ( V_128 > V_26 -> V_84 -> V_132 )
V_128 = 0 ;
V_122 = F_76 ( V_26 , & V_119 ,
& V_120 , & V_128 ) ;
if ( ! V_122 )
return;
V_119 -> V_55 = V_133 ;
if ( V_128 == 0 )
goto V_134;
F_32 ( & V_26 -> V_12 . V_63 ) ;
F_78 ( & V_26 -> V_12 . V_67 , 0 ) ;
F_45 (entry, safe, &bat_priv->tt.changes_list,
list) {
if ( V_131 < V_130 ) {
memcpy ( V_120 + V_131 ,
& V_53 -> V_60 ,
sizeof( struct V_69 ) ) ;
V_131 ++ ;
}
F_46 ( & V_53 -> V_47 ) ;
F_47 ( V_53 ) ;
}
F_36 ( & V_26 -> V_12 . V_63 ) ;
F_32 ( & V_26 -> V_12 . V_135 ) ;
F_47 ( V_26 -> V_12 . V_136 ) ;
V_26 -> V_12 . V_137 = 0 ;
V_26 -> V_12 . V_136 = NULL ;
V_129 = F_51 ( V_131 ) ;
if ( V_131 > 0 ) {
V_26 -> V_12 . V_136 = F_79 ( V_128 , V_59 ) ;
if ( V_26 -> V_12 . V_136 ) {
memcpy ( V_26 -> V_12 . V_136 ,
V_120 , V_129 ) ;
V_26 -> V_12 . V_137 = V_128 ;
}
}
F_36 ( & V_26 -> V_12 . V_135 ) ;
V_134:
F_80 ( V_26 , V_138 , 1 , V_119 ,
V_122 ) ;
F_47 ( V_119 ) ;
}
int F_81 ( struct V_139 * V_140 , void * V_141 )
{
struct V_83 * V_142 = (struct V_83 * ) V_140 -> V_143 ;
struct V_25 * V_26 = F_62 ( V_142 ) ;
struct V_16 * V_13 = V_26 -> V_12 . V_29 ;
struct V_5 * V_27 ;
struct V_24 * V_87 ;
struct V_144 * V_145 ;
struct V_17 * V_18 ;
unsigned short V_9 ;
T_1 V_146 ;
int V_147 ;
int V_148 ;
unsigned long V_149 ;
bool V_150 ;
T_3 V_151 = V_111 ;
V_145 = F_82 ( V_140 ) ;
if ( ! V_145 )
goto V_105;
F_83 ( V_140 ,
L_8 ,
V_142 -> V_152 , ( T_2 ) F_23 ( & V_26 -> V_12 . V_106 ) ) ;
F_84 ( V_140 ,
L_9 ) ;
for ( V_146 = 0 ; V_146 < V_13 -> V_11 ; V_146 ++ ) {
V_18 = & V_13 -> V_22 [ V_146 ] ;
F_8 () ;
F_9 (tt_common_entry,
head, hash_entry) {
V_87 = F_2 ( V_27 ,
struct V_24 ,
V_30 ) ;
V_9 = V_27 -> V_9 ;
V_149 = V_99 - V_87 -> V_98 ;
V_148 = F_85 ( V_149 ) ;
V_147 = V_148 / 1000 ;
V_148 = V_148 % 1000 ;
V_150 = V_27 -> V_55 & V_151 ;
F_83 ( V_140 ,
L_10 ,
V_27 -> V_14 ,
F_59 ( V_27 -> V_9 ) ,
( ( V_27 -> V_55 &
V_102 ) ? 'R' : '.' ) ,
V_150 ? 'P' : '.' ,
( ( V_27 -> V_55 &
V_107 ) ? 'N' : '.' ) ,
( ( V_27 -> V_55 &
V_100 ) ? 'X' : '.' ) ,
( ( V_27 -> V_55 &
V_108 ) ? 'W' : '.' ) ,
( ( V_27 -> V_55 &
V_118 ) ? 'I' : '.' ) ,
V_150 ? 0 : V_147 ,
V_150 ? 0 : V_148 ,
V_87 -> V_36 -> V_12 . V_127 ) ;
}
F_11 () ;
}
V_105:
if ( V_145 )
F_86 ( V_145 ) ;
return 0 ;
}
static void
F_87 ( struct V_25 * V_26 ,
struct V_24 * V_28 ,
T_3 V_55 , const char * V_81 )
{
F_42 ( V_26 , V_28 , V_55 ) ;
V_28 -> V_30 . V_55 |= V_100 ;
F_58 ( V_82 , V_26 ,
L_11 ,
V_28 -> V_30 . V_14 ,
F_59 ( V_28 -> V_30 . V_9 ) , V_81 ) ;
}
T_3 F_88 ( struct V_25 * V_26 , const T_2 * V_14 ,
unsigned short V_9 , const char * V_81 ,
bool V_153 )
{
struct V_24 * V_28 ;
T_3 V_55 , V_154 = V_112 ;
void * V_155 ;
V_28 = F_12 ( V_26 , V_14 , V_9 ) ;
if ( ! V_28 )
goto V_105;
V_154 = V_28 -> V_30 . V_55 ;
V_55 = V_62 ;
if ( V_153 ) {
V_55 |= V_102 ;
V_28 -> V_30 . V_55 |= V_102 ;
}
if ( ! ( V_28 -> V_30 . V_55 & V_107 ) ) {
F_87 ( V_26 , V_28 , V_55 ,
V_81 ) ;
goto V_105;
}
F_42 ( V_26 , V_28 , V_62 ) ;
V_155 = F_60 ( V_26 -> V_12 . V_29 ,
F_1 ,
F_4 ,
& V_28 -> V_30 ) ;
if ( ! V_155 )
goto V_105;
F_17 ( V_28 ) ;
V_105:
if ( V_28 )
F_17 ( V_28 ) ;
return V_154 ;
}
static void F_89 ( struct V_25 * V_26 ,
struct V_17 * V_18 ,
int V_156 )
{
struct V_24 * V_28 ;
struct V_5 * V_27 ;
struct V_1 * V_157 ;
F_90 (tt_common_entry, node_tmp, head,
hash_entry) {
V_28 = F_2 ( V_27 ,
struct V_24 ,
V_30 ) ;
if ( V_28 -> V_30 . V_55 & V_111 )
continue;
if ( V_28 -> V_30 . V_55 & V_100 )
continue;
if ( ! F_91 ( V_28 -> V_98 , V_156 ) )
continue;
F_87 ( V_26 , V_28 ,
V_62 , L_12 ) ;
}
}
static void F_92 ( struct V_25 * V_26 ,
int V_156 )
{
struct V_16 * V_13 = V_26 -> V_12 . V_29 ;
struct V_17 * V_18 ;
T_5 * V_158 ;
T_1 V_146 ;
for ( V_146 = 0 ; V_146 < V_13 -> V_11 ; V_146 ++ ) {
V_18 = & V_13 -> V_22 [ V_146 ] ;
V_158 = & V_13 -> V_159 [ V_146 ] ;
F_32 ( V_158 ) ;
F_89 ( V_26 , V_18 , V_156 ) ;
F_36 ( V_158 ) ;
}
}
static void F_93 ( struct V_25 * V_26 )
{
struct V_16 * V_13 ;
T_5 * V_158 ;
struct V_5 * V_27 ;
struct V_24 * V_87 ;
struct V_1 * V_157 ;
struct V_17 * V_18 ;
T_1 V_146 ;
if ( ! V_26 -> V_12 . V_29 )
return;
V_13 = V_26 -> V_12 . V_29 ;
for ( V_146 = 0 ; V_146 < V_13 -> V_11 ; V_146 ++ ) {
V_18 = & V_13 -> V_22 [ V_146 ] ;
V_158 = & V_13 -> V_159 [ V_146 ] ;
F_32 ( V_158 ) ;
F_90 (tt_common_entry, node_tmp,
head, hash_entry) {
F_94 ( & V_27 -> V_6 ) ;
V_87 = F_2 ( V_27 ,
struct V_24 ,
V_30 ) ;
F_17 ( V_87 ) ;
}
F_36 ( V_158 ) ;
}
F_95 ( V_13 ) ;
V_26 -> V_12 . V_29 = NULL ;
}
static int F_96 ( struct V_25 * V_26 )
{
if ( V_26 -> V_12 . V_33 )
return 0 ;
V_26 -> V_12 . V_33 = F_55 ( 1024 ) ;
if ( ! V_26 -> V_12 . V_33 )
return - V_78 ;
F_56 ( V_26 -> V_12 . V_33 ,
& V_160 ) ;
return 0 ;
}
static void F_97 ( struct V_25 * V_26 )
{
struct V_51 * V_53 , * V_54 ;
F_32 ( & V_26 -> V_12 . V_63 ) ;
F_45 (entry, safe, &bat_priv->tt.changes_list,
list) {
F_46 ( & V_53 -> V_47 ) ;
F_47 ( V_53 ) ;
}
F_78 ( & V_26 -> V_12 . V_67 , 0 ) ;
F_36 ( & V_26 -> V_12 . V_63 ) ;
}
static struct V_48 *
F_98 ( const struct V_31 * V_53 ,
const struct V_43 * V_44 )
{
struct V_48 * V_161 , * V_49 = NULL ;
const struct V_17 * V_18 ;
F_8 () ;
V_18 = & V_53 -> V_113 ;
F_9 (tmp_orig_entry, head, list) {
if ( V_161 -> V_44 != V_44 )
continue;
if ( ! F_10 ( & V_161 -> V_23 ) )
continue;
V_49 = V_161 ;
break;
}
F_11 () ;
return V_49 ;
}
static bool
F_99 ( const struct V_31 * V_53 ,
const struct V_43 * V_44 )
{
struct V_48 * V_49 ;
bool V_162 = false ;
V_49 = F_98 ( V_53 , V_44 ) ;
if ( V_49 ) {
V_162 = true ;
F_41 ( V_49 ) ;
}
return V_162 ;
}
static void
F_100 ( struct V_31 * V_80 ,
struct V_43 * V_44 , int V_125 )
{
struct V_48 * V_49 ;
V_49 = F_98 ( V_80 , V_44 ) ;
if ( V_49 ) {
V_49 -> V_125 = V_125 ;
goto V_105;
}
V_49 = F_79 ( sizeof( * V_49 ) , V_59 ) ;
if ( ! V_49 )
goto V_105;
F_101 ( & V_49 -> V_47 ) ;
F_69 ( & V_44 -> V_23 ) ;
F_37 ( V_44 , V_80 -> V_30 . V_9 ) ;
V_49 -> V_44 = V_44 ;
V_49 -> V_125 = V_125 ;
F_68 ( & V_49 -> V_23 ) ;
F_69 ( & V_49 -> V_23 ) ;
F_32 ( & V_80 -> V_158 ) ;
F_102 ( & V_49 -> V_47 ,
& V_80 -> V_113 ) ;
F_36 ( & V_80 -> V_158 ) ;
F_50 ( & V_80 -> V_39 ) ;
V_105:
if ( V_49 )
F_41 ( V_49 ) ;
}
static bool F_103 ( struct V_25 * V_26 ,
struct V_43 * V_44 ,
const unsigned char * V_163 ,
unsigned short V_9 , T_3 V_55 , T_2 V_125 )
{
struct V_31 * V_32 ;
struct V_24 * V_28 ;
bool V_93 = false ;
int V_90 ;
struct V_5 * V_30 ;
T_3 V_164 ;
if ( F_104 ( V_26 , V_44 -> V_165 , V_9 ) )
return true ;
V_32 = F_13 ( V_26 , V_163 , V_9 ) ;
V_28 = F_12 ( V_26 , V_163 , V_9 ) ;
if ( ( V_55 & V_166 ) && V_28 &&
! ( V_28 -> V_30 . V_55 & V_107 ) )
goto V_105;
if ( ! V_32 ) {
V_32 = F_79 ( sizeof( * V_32 ) , V_59 ) ;
if ( ! V_32 )
goto V_105;
V_30 = & V_32 -> V_30 ;
F_7 ( V_30 -> V_14 , V_163 ) ;
V_30 -> V_9 = V_9 ;
V_30 -> V_55 = V_55 ;
V_32 -> V_114 = 0 ;
if ( V_55 & V_102 )
V_32 -> V_114 = V_99 ;
F_68 ( & V_30 -> V_23 ) ;
F_69 ( & V_30 -> V_23 ) ;
V_30 -> V_109 = V_99 ;
F_105 ( & V_32 -> V_113 ) ;
F_78 ( & V_32 -> V_39 , 0 ) ;
F_106 ( & V_32 -> V_158 ) ;
V_90 = F_70 ( V_26 -> V_12 . V_33 ,
F_1 ,
F_4 , V_30 ,
& V_30 -> V_6 ) ;
if ( F_71 ( V_90 != 0 ) ) {
F_21 ( V_32 ) ;
goto V_167;
}
} else {
V_30 = & V_32 -> V_30 ;
if ( V_55 & V_166 ) {
if ( ! ( V_30 -> V_55 & V_166 ) )
goto V_105;
if ( F_99 ( V_32 ,
V_44 ) )
goto V_167;
F_20 ( V_32 ) ;
goto V_168;
}
if ( V_30 -> V_55 & V_166 ) {
F_20 ( V_32 ) ;
V_30 -> V_55 &= ~ V_166 ;
}
V_30 -> V_55 |= V_55 ;
if ( V_30 -> V_55 & V_102 ) {
F_20 ( V_32 ) ;
V_30 -> V_55 &= ~ V_102 ;
V_32 -> V_114 = 0 ;
}
}
V_168:
F_100 ( V_32 , V_44 , V_125 ) ;
F_58 ( V_82 , V_26 ,
L_13 ,
V_30 -> V_14 , F_59 ( V_30 -> V_9 ) ,
V_44 -> V_165 ) ;
V_93 = true ;
V_167:
if ( F_65 ( V_163 ) )
goto V_105;
V_164 = F_88 ( V_26 , V_163 , V_9 ,
L_14 ,
V_55 & V_102 ) ;
V_32 -> V_30 . V_55 |= V_164 & V_108 ;
if ( ! ( V_55 & V_102 ) )
V_32 -> V_30 . V_55 &= ~ V_102 ;
V_105:
if ( V_32 )
F_21 ( V_32 ) ;
if ( V_28 )
F_17 ( V_28 ) ;
return V_93 ;
}
static struct V_48 *
F_107 ( struct V_25 * V_26 ,
struct V_31 * V_32 )
{
struct V_169 * V_170 , * V_171 = NULL ;
struct V_172 * V_173 = V_26 -> V_174 ;
struct V_17 * V_18 ;
struct V_48 * V_49 , * V_175 = NULL ;
V_18 = & V_32 -> V_113 ;
F_9 (orig_entry, head, list) {
V_170 = F_108 ( V_49 -> V_44 ,
V_176 ) ;
if ( ! V_170 )
continue;
if ( V_171 &&
V_173 -> V_177 ( V_170 , V_176 ,
V_171 , V_176 ) <= 0 ) {
F_109 ( V_170 ) ;
continue;
}
if ( V_171 )
F_109 ( V_171 ) ;
V_175 = V_49 ;
V_171 = V_170 ;
}
if ( V_171 )
F_109 ( V_171 ) ;
return V_175 ;
}
static void
F_110 ( struct V_25 * V_26 ,
struct V_31 * V_32 ,
struct V_139 * V_140 )
{
struct V_48 * V_49 , * V_175 ;
struct V_5 * V_27 ;
struct V_45 * V_36 ;
struct V_17 * V_18 ;
T_2 V_126 ;
T_3 V_55 ;
V_27 = & V_32 -> V_30 ;
V_55 = V_27 -> V_55 ;
V_175 = F_107 ( V_26 , V_32 ) ;
if ( V_175 ) {
V_36 = F_111 ( V_175 -> V_44 ,
V_27 -> V_9 ) ;
if ( ! V_36 ) {
F_83 ( V_140 ,
L_15 ,
F_59 ( V_27 -> V_9 ) ,
V_175 -> V_44 -> V_165 ) ;
goto V_178;
}
V_126 = F_23 ( & V_175 -> V_44 -> V_126 ) ;
F_83 ( V_140 ,
L_16 ,
'*' , V_32 -> V_30 . V_14 ,
F_59 ( V_32 -> V_30 . V_9 ) ,
V_175 -> V_125 , V_175 -> V_44 -> V_165 ,
V_126 , V_36 -> V_12 . V_127 ,
( ( V_55 & V_102 ) ? 'R' : '.' ) ,
( ( V_55 & V_108 ) ? 'W' : '.' ) ,
( ( V_55 & V_118 ) ? 'I' : '.' ) ,
( ( V_55 & V_166 ) ? 'T' : '.' ) ) ;
F_35 ( V_36 ) ;
}
V_178:
V_18 = & V_32 -> V_113 ;
F_9 (orig_entry, head, list) {
if ( V_175 == V_49 )
continue;
V_36 = F_111 ( V_49 -> V_44 ,
V_27 -> V_9 ) ;
if ( ! V_36 ) {
F_83 ( V_140 ,
L_17 ,
F_59 ( V_27 -> V_9 ) ,
V_49 -> V_44 -> V_165 ) ;
continue;
}
V_126 = F_23 ( & V_49 -> V_44 -> V_126 ) ;
F_83 ( V_140 ,
L_18 ,
'+' , V_32 -> V_30 . V_14 ,
F_59 ( V_32 -> V_30 . V_9 ) ,
V_49 -> V_125 , V_49 -> V_44 -> V_165 ,
V_126 , V_36 -> V_12 . V_127 ,
( ( V_55 & V_102 ) ? 'R' : '.' ) ,
( ( V_55 & V_108 ) ? 'W' : '.' ) ,
( ( V_55 & V_118 ) ? 'I' : '.' ) ,
( ( V_55 & V_166 ) ? 'T' : '.' ) ) ;
F_35 ( V_36 ) ;
}
}
int F_112 ( struct V_139 * V_140 , void * V_141 )
{
struct V_83 * V_142 = (struct V_83 * ) V_140 -> V_143 ;
struct V_25 * V_26 = F_62 ( V_142 ) ;
struct V_16 * V_13 = V_26 -> V_12 . V_33 ;
struct V_5 * V_27 ;
struct V_31 * V_80 ;
struct V_144 * V_145 ;
struct V_17 * V_18 ;
T_1 V_146 ;
V_145 = F_82 ( V_140 ) ;
if ( ! V_145 )
goto V_105;
F_83 ( V_140 ,
L_19 ,
V_142 -> V_152 ) ;
F_84 ( V_140 ,
L_20 ) ;
for ( V_146 = 0 ; V_146 < V_13 -> V_11 ; V_146 ++ ) {
V_18 = & V_13 -> V_22 [ V_146 ] ;
F_8 () ;
F_9 (tt_common_entry,
head, hash_entry) {
V_80 = F_2 ( V_27 ,
struct V_31 ,
V_30 ) ;
F_110 ( V_26 , V_80 , V_140 ) ;
}
F_11 () ;
}
V_105:
if ( V_145 )
F_86 ( V_145 ) ;
return 0 ;
}
static void
F_113 ( struct V_31 * V_32 ,
struct V_48 * V_49 )
{
F_114 ( & V_32 -> V_158 ) ;
F_38 ( V_49 -> V_44 ,
V_32 -> V_30 . V_9 ) ;
F_49 ( & V_32 -> V_39 ) ;
F_94 ( & V_49 -> V_47 ) ;
F_41 ( V_49 ) ;
}
static void
F_20 ( struct V_31 * V_32 )
{
struct V_17 * V_18 ;
struct V_1 * V_54 ;
struct V_48 * V_49 ;
F_32 ( & V_32 -> V_158 ) ;
V_18 = & V_32 -> V_113 ;
F_90 (orig_entry, safe, head, list)
F_113 ( V_32 , V_49 ) ;
F_36 ( & V_32 -> V_158 ) ;
}
static void
F_115 ( struct V_25 * V_26 ,
struct V_31 * V_32 ,
struct V_43 * V_44 ,
const char * V_81 )
{
struct V_17 * V_18 ;
struct V_1 * V_54 ;
struct V_48 * V_49 ;
unsigned short V_9 ;
F_32 ( & V_32 -> V_158 ) ;
V_18 = & V_32 -> V_113 ;
F_90 (orig_entry, safe, head, list) {
if ( V_49 -> V_44 == V_44 ) {
V_9 = V_32 -> V_30 . V_9 ;
F_58 ( V_82 , V_26 ,
L_21 ,
V_44 -> V_165 ,
V_32 -> V_30 . V_14 ,
F_59 ( V_9 ) , V_81 ) ;
F_113 ( V_32 ,
V_49 ) ;
}
}
F_36 ( & V_32 -> V_158 ) ;
}
static void
F_116 ( struct V_25 * V_26 ,
struct V_31 * V_32 ,
struct V_43 * V_44 ,
const char * V_81 )
{
bool V_179 = true ;
struct V_17 * V_18 ;
struct V_48 * V_49 ;
F_8 () ;
V_18 = & V_32 -> V_113 ;
F_9 (orig_entry, head, list) {
if ( V_49 -> V_44 != V_44 ) {
V_179 = false ;
break;
}
}
F_11 () ;
if ( V_179 ) {
V_32 -> V_30 . V_55 |= V_102 ;
V_32 -> V_114 = V_99 ;
} else
F_115 ( V_26 , V_32 ,
V_44 , V_81 ) ;
}
static void F_117 ( struct V_25 * V_26 ,
struct V_43 * V_44 ,
const unsigned char * V_14 , unsigned short V_9 ,
const char * V_81 , bool V_153 )
{
struct V_31 * V_32 ;
struct V_24 * V_180 = NULL ;
V_32 = F_13 ( V_26 , V_14 , V_9 ) ;
if ( ! V_32 )
goto V_105;
if ( ! V_153 ) {
F_115 ( V_26 , V_32 ,
V_44 , V_81 ) ;
if ( F_118 ( & V_32 -> V_113 ) )
F_57 ( V_26 , V_32 ,
V_81 ) ;
goto V_105;
}
V_180 = F_12 ( V_26 ,
V_32 -> V_30 . V_14 ,
V_9 ) ;
if ( V_180 ) {
F_20 ( V_32 ) ;
F_57 ( V_26 , V_32 , V_81 ) ;
} else
F_116 ( V_26 , V_32 ,
V_44 , V_81 ) ;
V_105:
if ( V_32 )
F_21 ( V_32 ) ;
if ( V_180 )
F_17 ( V_180 ) ;
}
void F_119 ( struct V_25 * V_26 ,
struct V_43 * V_44 ,
T_4 V_181 ,
const char * V_81 )
{
struct V_31 * V_80 ;
struct V_5 * V_27 ;
T_1 V_146 ;
struct V_16 * V_13 = V_26 -> V_12 . V_33 ;
struct V_1 * V_54 ;
struct V_17 * V_18 ;
T_5 * V_158 ;
unsigned short V_9 ;
if ( ! V_13 )
return;
for ( V_146 = 0 ; V_146 < V_13 -> V_11 ; V_146 ++ ) {
V_18 = & V_13 -> V_22 [ V_146 ] ;
V_158 = & V_13 -> V_159 [ V_146 ] ;
F_32 ( V_158 ) ;
F_90 (tt_common_entry, safe,
head, hash_entry) {
if ( V_181 >= 0 && V_27 -> V_9 != V_181 )
continue;
V_80 = F_2 ( V_27 ,
struct V_31 ,
V_30 ) ;
F_115 ( V_26 , V_80 ,
V_44 , V_81 ) ;
if ( F_118 ( & V_80 -> V_113 ) ) {
V_9 = V_80 -> V_30 . V_9 ;
F_58 ( V_82 , V_26 ,
L_1 ,
V_80 -> V_30 . V_14 ,
F_59 ( V_9 ) , V_81 ) ;
F_94 ( & V_27 -> V_6 ) ;
F_21 ( V_80 ) ;
}
}
F_36 ( V_158 ) ;
}
F_120 ( V_182 , & V_44 -> V_183 ) ;
}
static bool F_121 ( struct V_31 * V_80 ,
char * * V_184 )
{
bool V_185 = false ;
unsigned long V_186 = V_187 ;
unsigned long V_188 = V_189 ;
if ( ( V_80 -> V_30 . V_55 & V_102 ) &&
F_91 ( V_80 -> V_114 , V_186 ) ) {
V_185 = true ;
* V_184 = L_22 ;
}
if ( ( V_80 -> V_30 . V_55 & V_166 ) &&
F_91 ( V_80 -> V_30 . V_109 , V_188 ) ) {
V_185 = true ;
* V_184 = L_23 ;
}
return V_185 ;
}
static void F_122 ( struct V_25 * V_26 )
{
struct V_16 * V_13 = V_26 -> V_12 . V_33 ;
struct V_17 * V_18 ;
struct V_1 * V_157 ;
T_5 * V_158 ;
T_1 V_146 ;
char * V_184 = NULL ;
struct V_5 * V_190 ;
struct V_31 * V_80 ;
for ( V_146 = 0 ; V_146 < V_13 -> V_11 ; V_146 ++ ) {
V_18 = & V_13 -> V_22 [ V_146 ] ;
V_158 = & V_13 -> V_159 [ V_146 ] ;
F_32 ( V_158 ) ;
F_90 (tt_common, node_tmp, head,
hash_entry) {
V_80 = F_2 ( V_190 ,
struct V_31 ,
V_30 ) ;
if ( ! F_121 ( V_80 , & V_184 ) )
continue;
F_58 ( V_82 , V_26 ,
L_1 ,
V_80 -> V_30 . V_14 ,
F_59 ( V_80 -> V_30 . V_9 ) ,
V_184 ) ;
F_94 ( & V_190 -> V_6 ) ;
F_21 ( V_80 ) ;
}
F_36 ( V_158 ) ;
}
}
static void F_123 ( struct V_25 * V_26 )
{
struct V_16 * V_13 ;
T_5 * V_158 ;
struct V_5 * V_27 ;
struct V_31 * V_80 ;
struct V_1 * V_157 ;
struct V_17 * V_18 ;
T_1 V_146 ;
if ( ! V_26 -> V_12 . V_33 )
return;
V_13 = V_26 -> V_12 . V_33 ;
for ( V_146 = 0 ; V_146 < V_13 -> V_11 ; V_146 ++ ) {
V_18 = & V_13 -> V_22 [ V_146 ] ;
V_158 = & V_13 -> V_159 [ V_146 ] ;
F_32 ( V_158 ) ;
F_90 (tt_common_entry, node_tmp,
head, hash_entry) {
F_94 ( & V_27 -> V_6 ) ;
V_80 = F_2 ( V_27 ,
struct V_31 ,
V_30 ) ;
F_21 ( V_80 ) ;
}
F_36 ( V_158 ) ;
}
F_95 ( V_13 ) ;
V_26 -> V_12 . V_33 = NULL ;
}
static bool
F_124 ( struct V_24 * V_28 ,
struct V_31 * V_32 )
{
bool V_93 = false ;
if ( V_28 -> V_30 . V_55 & V_108 &&
V_32 -> V_30 . V_55 & V_108 )
V_93 = true ;
if ( V_28 -> V_30 . V_55 & V_118 &&
V_32 -> V_30 . V_55 & V_118 )
V_93 = true ;
return V_93 ;
}
struct V_43 * F_125 ( struct V_25 * V_26 ,
const T_2 * V_191 ,
const T_2 * V_14 ,
unsigned short V_9 )
{
struct V_24 * V_28 = NULL ;
struct V_31 * V_32 = NULL ;
struct V_43 * V_44 = NULL ;
struct V_48 * V_175 ;
if ( V_191 && F_126 ( V_26 , V_9 ) ) {
V_28 = F_12 ( V_26 , V_191 , V_9 ) ;
if ( ! V_28 ||
( V_28 -> V_30 . V_55 & V_100 ) )
goto V_105;
}
V_32 = F_13 ( V_26 , V_14 , V_9 ) ;
if ( ! V_32 )
goto V_105;
if ( V_28 &&
F_124 ( V_28 , V_32 ) )
goto V_105;
F_8 () ;
V_175 = F_107 ( V_26 , V_32 ) ;
if ( V_175 )
V_44 = V_175 -> V_44 ;
if ( V_44 && ! F_10 ( & V_44 -> V_23 ) )
V_44 = NULL ;
F_11 () ;
V_105:
if ( V_32 )
F_21 ( V_32 ) ;
if ( V_28 )
F_17 ( V_28 ) ;
return V_44 ;
}
static T_1 F_127 ( struct V_25 * V_26 ,
struct V_43 * V_44 ,
unsigned short V_9 )
{
struct V_16 * V_13 = V_26 -> V_12 . V_33 ;
struct V_5 * V_190 ;
struct V_31 * V_80 ;
struct V_17 * V_18 ;
T_1 V_146 , V_192 , V_127 = 0 ;
T_2 V_55 ;
T_6 V_193 ;
for ( V_146 = 0 ; V_146 < V_13 -> V_11 ; V_146 ++ ) {
V_18 = & V_13 -> V_22 [ V_146 ] ;
F_8 () ;
F_9 (tt_common, head, hash_entry) {
V_80 = F_2 ( V_190 ,
struct V_31 ,
V_30 ) ;
if ( V_190 -> V_9 != V_9 )
continue;
if ( V_190 -> V_55 & V_102 )
continue;
if ( V_190 -> V_55 & V_166 )
continue;
if ( ! F_99 ( V_80 ,
V_44 ) )
continue;
V_193 = F_44 ( V_190 -> V_9 ) ;
V_192 = F_128 ( 0 , & V_193 , sizeof( V_193 ) ) ;
V_55 = V_190 -> V_55 & V_194 ;
V_192 = F_128 ( V_192 , & V_55 , sizeof( V_55 ) ) ;
V_127 ^= F_128 ( V_192 , V_190 -> V_14 , V_15 ) ;
}
F_11 () ;
}
return V_127 ;
}
static T_1 F_129 ( struct V_25 * V_26 ,
unsigned short V_9 )
{
struct V_16 * V_13 = V_26 -> V_12 . V_29 ;
struct V_5 * V_190 ;
struct V_17 * V_18 ;
T_1 V_146 , V_192 , V_127 = 0 ;
T_2 V_55 ;
T_6 V_193 ;
for ( V_146 = 0 ; V_146 < V_13 -> V_11 ; V_146 ++ ) {
V_18 = & V_13 -> V_22 [ V_146 ] ;
F_8 () ;
F_9 (tt_common, head, hash_entry) {
if ( V_190 -> V_9 != V_9 )
continue;
if ( V_190 -> V_55 & V_107 )
continue;
V_193 = F_44 ( V_190 -> V_9 ) ;
V_192 = F_128 ( 0 , & V_193 , sizeof( V_193 ) ) ;
V_55 = V_190 -> V_55 & V_194 ;
V_192 = F_128 ( V_192 , & V_55 , sizeof( V_55 ) ) ;
V_127 ^= F_128 ( V_192 , V_190 -> V_14 , V_15 ) ;
}
F_11 () ;
}
return V_127 ;
}
static void F_130 ( struct V_34 * V_35 )
{
struct V_195 * V_196 ;
V_196 = F_2 ( V_35 , struct V_195 , V_23 ) ;
F_47 ( V_196 ) ;
}
static void F_131 ( struct V_195 * V_196 )
{
F_18 ( & V_196 -> V_23 , F_130 ) ;
}
static void F_132 ( struct V_25 * V_26 )
{
struct V_195 * V_2 ;
struct V_1 * V_54 ;
F_32 ( & V_26 -> V_12 . V_197 ) ;
F_90 (node, safe, &bat_priv->tt.req_list, list) {
F_133 ( & V_2 -> V_47 ) ;
F_131 ( V_2 ) ;
}
F_36 ( & V_26 -> V_12 . V_197 ) ;
}
static void F_134 ( struct V_25 * V_26 ,
struct V_43 * V_44 ,
const void * V_198 ,
T_3 V_199 )
{
F_32 ( & V_44 -> V_200 ) ;
if ( V_199 > 0 ) {
F_47 ( V_44 -> V_198 ) ;
V_44 -> V_199 = 0 ;
V_44 -> V_198 = F_43 ( V_199 , V_59 ) ;
if ( V_44 -> V_198 ) {
memcpy ( V_44 -> V_198 , V_198 , V_199 ) ;
V_44 -> V_199 = V_199 ;
}
}
F_36 ( & V_44 -> V_200 ) ;
}
static void F_135 ( struct V_25 * V_26 )
{
struct V_195 * V_2 ;
struct V_1 * V_54 ;
F_32 ( & V_26 -> V_12 . V_197 ) ;
F_90 (node, safe, &bat_priv->tt.req_list, list) {
if ( F_91 ( V_2 -> V_201 ,
V_202 ) ) {
F_133 ( & V_2 -> V_47 ) ;
F_131 ( V_2 ) ;
}
}
F_36 ( & V_26 -> V_12 . V_197 ) ;
}
static struct V_195 *
F_136 ( struct V_25 * V_26 ,
struct V_43 * V_44 )
{
struct V_195 * V_203 , * V_196 = NULL ;
F_32 ( & V_26 -> V_12 . V_197 ) ;
F_137 (tt_req_node_tmp, &bat_priv->tt.req_list, list) {
if ( F_3 ( V_203 , V_44 ) &&
! F_91 ( V_203 -> V_201 ,
V_202 ) )
goto V_65;
}
V_196 = F_43 ( sizeof( * V_196 ) , V_59 ) ;
if ( ! V_196 )
goto V_65;
F_68 ( & V_196 -> V_23 ) ;
F_7 ( V_196 -> V_14 , V_44 -> V_165 ) ;
V_196 -> V_201 = V_99 ;
F_69 ( & V_196 -> V_23 ) ;
F_138 ( & V_196 -> V_47 , & V_26 -> V_12 . V_204 ) ;
V_65:
F_36 ( & V_26 -> V_12 . V_197 ) ;
return V_196 ;
}
static bool F_139 ( const void * V_205 , const void * V_206 )
{
const struct V_5 * V_27 = V_205 ;
if ( V_27 -> V_55 & V_107 )
return false ;
return true ;
}
static bool F_140 ( const void * V_205 ,
const void * V_206 )
{
const struct V_5 * V_27 = V_205 ;
const struct V_31 * V_32 ;
const struct V_43 * V_44 = V_206 ;
if ( V_27 -> V_55 & V_102 ||
V_27 -> V_55 & V_166 )
return false ;
V_32 = F_2 ( V_27 ,
struct V_31 ,
V_30 ) ;
return F_99 ( V_32 , V_44 ) ;
}
static void F_141 ( struct V_25 * V_26 ,
struct V_16 * V_13 ,
void * V_207 , T_3 V_70 ,
bool (* F_142)( const void * ,
const void * ) ,
void * V_208 )
{
struct V_5 * V_27 ;
struct V_69 * V_120 ;
struct V_17 * V_18 ;
T_3 V_209 , V_210 = 0 ;
T_1 V_146 ;
V_209 = F_52 ( V_70 ) ;
V_120 = (struct V_69 * ) V_207 ;
F_8 () ;
for ( V_146 = 0 ; V_146 < V_13 -> V_11 ; V_146 ++ ) {
V_18 = & V_13 -> V_22 [ V_146 ] ;
F_9 (tt_common_entry,
head, hash_entry) {
if ( V_209 == V_210 )
break;
if ( ( F_142 ) && ( ! F_142 ( V_27 , V_208 ) ) )
continue;
F_7 ( V_120 -> V_14 , V_27 -> V_14 ) ;
V_120 -> V_55 = V_27 -> V_55 ;
V_120 -> V_9 = F_44 ( V_27 -> V_9 ) ;
memset ( V_120 -> V_61 , 0 ,
sizeof( V_120 -> V_61 ) ) ;
V_210 ++ ;
V_120 ++ ;
}
}
F_11 () ;
}
static bool F_143 ( struct V_43 * V_44 ,
struct V_77 * V_123 ,
T_3 V_71 )
{
struct V_77 * V_211 ;
struct V_45 * V_36 ;
int V_146 , V_212 ;
T_1 V_127 ;
for ( V_146 = 0 ; V_146 < V_71 ; V_146 ++ ) {
V_211 = V_123 + V_146 ;
if ( F_104 ( V_44 -> V_26 ,
V_44 -> V_165 ,
F_144 ( V_211 -> V_9 ) ) )
continue;
V_36 = F_111 ( V_44 ,
F_144 ( V_211 -> V_9 ) ) ;
if ( ! V_36 )
return false ;
V_127 = V_36 -> V_12 . V_127 ;
F_35 ( V_36 ) ;
if ( V_127 != F_145 ( V_211 -> V_127 ) )
return false ;
}
F_8 () ;
V_212 = 0 ;
F_9 (vlan, &orig_node->vlan_list, list)
V_212 ++ ;
F_11 () ;
if ( V_212 > V_71 )
return false ;
return true ;
}
static void F_146 ( struct V_25 * V_26 )
{
struct V_41 * V_36 ;
F_8 () ;
F_9 (vlan, &bat_priv->softif_vlan_list, list) {
V_36 -> V_12 . V_127 = F_129 ( V_26 , V_36 -> V_9 ) ;
}
F_11 () ;
}
static void F_147 ( struct V_25 * V_26 ,
struct V_43 * V_44 )
{
struct V_45 * V_36 ;
T_1 V_127 ;
F_8 () ;
F_9 (vlan, &orig_node->vlan_list, list) {
if ( F_104 ( V_26 , V_44 -> V_165 ,
V_36 -> V_9 ) )
continue;
V_127 = F_127 ( V_26 , V_44 , V_36 -> V_9 ) ;
V_36 -> V_12 . V_127 = V_127 ;
}
F_11 () ;
}
static bool F_148 ( struct V_25 * V_26 ,
struct V_43 * V_213 ,
T_2 V_125 ,
struct V_77 * V_123 ,
T_3 V_71 , bool V_214 )
{
struct V_76 * V_215 = NULL ;
struct V_195 * V_196 = NULL ;
struct V_77 * V_216 ;
struct V_144 * V_145 ;
bool V_93 = false ;
int V_146 , V_11 ;
V_145 = F_149 ( V_26 ) ;
if ( ! V_145 )
goto V_105;
V_196 = F_136 ( V_26 , V_213 ) ;
if ( ! V_196 )
goto V_105;
V_11 = sizeof( * V_215 ) + sizeof( * V_216 ) * V_71 ;
V_215 = F_79 ( V_11 , V_59 ) ;
if ( ! V_215 )
goto V_105;
V_215 -> V_55 = V_217 ;
V_215 -> V_125 = V_125 ;
V_215 -> V_71 = F_44 ( V_71 ) ;
V_216 = (struct V_77 * ) ( V_215 + 1 ) ;
for ( V_146 = 0 ; V_146 < V_71 ; V_146 ++ ) {
V_216 -> V_9 = V_123 -> V_9 ;
V_216 -> V_127 = V_123 -> V_127 ;
V_216 ++ ;
V_123 ++ ;
}
if ( V_214 )
V_215 -> V_55 |= V_218 ;
F_58 ( V_82 , V_26 , L_24 ,
V_213 -> V_165 , V_214 ? 'F' : '.' ) ;
F_150 ( V_26 , V_219 ) ;
F_151 ( V_26 , V_145 -> V_142 -> V_110 ,
V_213 -> V_165 , V_138 , 1 ,
V_215 , V_11 ) ;
V_93 = true ;
V_105:
if ( V_145 )
F_86 ( V_145 ) ;
if ( V_93 && V_196 ) {
F_32 ( & V_26 -> V_12 . V_197 ) ;
if ( ! F_33 ( & V_196 -> V_47 ) ) {
F_133 ( & V_196 -> V_47 ) ;
F_131 ( V_196 ) ;
}
F_36 ( & V_26 -> V_12 . V_197 ) ;
}
if ( V_196 )
F_131 ( V_196 ) ;
F_47 ( V_215 ) ;
return V_93 ;
}
static bool F_152 ( struct V_25 * V_26 ,
struct V_76 * V_119 ,
T_2 * V_220 , T_2 * V_221 )
{
struct V_43 * V_222 ;
struct V_43 * V_223 = NULL ;
struct V_69 * V_120 ;
struct V_76 * V_215 = NULL ;
struct V_77 * V_123 ;
bool V_93 = false , V_214 ;
T_2 V_224 , V_225 ;
T_3 V_122 ;
T_4 V_70 ;
F_58 ( V_82 , V_26 ,
L_25 ,
V_220 , V_119 -> V_125 , V_221 ,
( ( V_119 -> V_55 & V_218 ) ? 'F' : '.' ) ) ;
V_222 = F_153 ( V_26 , V_221 ) ;
if ( ! V_222 )
goto V_105;
V_223 = F_153 ( V_26 , V_220 ) ;
if ( ! V_223 )
goto V_105;
V_224 = ( T_2 ) F_23 ( & V_222 -> V_126 ) ;
V_225 = V_119 -> V_125 ;
V_123 = (struct V_77 * ) ( V_119 + 1 ) ;
if ( V_224 != V_225 ||
! F_143 ( V_222 , V_123 ,
F_144 ( V_119 -> V_71 ) ) )
goto V_105;
if ( V_119 -> V_55 & V_218 ||
! V_222 -> V_198 )
V_214 = true ;
else
V_214 = false ;
if ( ! V_214 ) {
F_32 ( & V_222 -> V_200 ) ;
V_70 = V_222 -> V_199 ;
V_122 = F_74 ( V_222 ,
& V_215 ,
& V_120 ,
& V_70 ) ;
if ( ! V_70 )
goto V_65;
memcpy ( V_120 , V_222 -> V_198 ,
V_222 -> V_199 ) ;
F_36 ( & V_222 -> V_200 ) ;
} else {
V_70 = - 1 ;
V_122 = F_74 ( V_222 ,
& V_215 ,
& V_120 ,
& V_70 ) ;
if ( ! V_70 )
goto V_105;
F_141 ( V_26 , V_26 -> V_12 . V_33 ,
V_120 , V_70 ,
F_140 ,
V_222 ) ;
}
V_70 = sizeof( struct V_74 ) + V_122 ;
if ( V_70 > F_23 ( & V_26 -> V_92 ) ) {
F_66 ( V_104 , V_26 -> V_84 ,
L_26 ,
V_223 -> V_165 ) ;
goto V_105;
}
V_215 -> V_55 = V_226 ;
V_215 -> V_125 = V_225 ;
if ( V_214 )
V_215 -> V_55 |= V_218 ;
F_58 ( V_82 , V_26 ,
L_27 ,
V_223 -> V_165 , V_222 -> V_165 ,
V_214 ? 'F' : '.' , V_225 ) ;
F_150 ( V_26 , V_227 ) ;
F_151 ( V_26 , V_222 -> V_165 ,
V_220 , V_138 , 1 , V_215 ,
V_122 ) ;
V_93 = true ;
goto V_105;
V_65:
F_36 ( & V_222 -> V_200 ) ;
V_105:
if ( V_223 )
F_40 ( V_223 ) ;
if ( V_222 )
F_40 ( V_222 ) ;
F_47 ( V_215 ) ;
return V_93 ;
}
static bool F_154 ( struct V_25 * V_26 ,
struct V_76 * V_119 ,
T_2 * V_220 )
{
struct V_76 * V_215 = NULL ;
struct V_144 * V_145 = NULL ;
struct V_69 * V_120 ;
struct V_43 * V_44 ;
T_2 V_228 , V_225 ;
T_3 V_122 ;
bool V_214 ;
T_4 V_70 ;
F_58 ( V_82 , V_26 ,
L_28 ,
V_220 , V_119 -> V_125 ,
( ( V_119 -> V_55 & V_218 ) ? 'F' : '.' ) ) ;
F_32 ( & V_26 -> V_12 . V_229 ) ;
V_228 = ( T_2 ) F_23 ( & V_26 -> V_12 . V_106 ) ;
V_225 = V_119 -> V_125 ;
V_44 = F_153 ( V_26 , V_220 ) ;
if ( ! V_44 )
goto V_105;
V_145 = F_149 ( V_26 ) ;
if ( ! V_145 )
goto V_105;
if ( V_119 -> V_55 & V_218 || V_228 != V_225 ||
! V_26 -> V_12 . V_136 )
V_214 = true ;
else
V_214 = false ;
if ( ! V_214 ) {
F_32 ( & V_26 -> V_12 . V_135 ) ;
V_70 = V_26 -> V_12 . V_137 ;
V_122 = F_76 ( V_26 ,
& V_215 ,
& V_120 ,
& V_70 ) ;
if ( ! V_70 )
goto V_65;
memcpy ( V_120 , V_26 -> V_12 . V_136 ,
V_26 -> V_12 . V_137 ) ;
F_36 ( & V_26 -> V_12 . V_135 ) ;
} else {
V_225 = ( T_2 ) F_23 ( & V_26 -> V_12 . V_106 ) ;
V_70 = - 1 ;
V_122 = F_76 ( V_26 ,
& V_215 ,
& V_120 ,
& V_70 ) ;
if ( ! V_70 )
goto V_105;
F_141 ( V_26 , V_26 -> V_12 . V_29 ,
V_120 , V_70 ,
F_139 , NULL ) ;
}
V_215 -> V_55 = V_226 ;
V_215 -> V_125 = V_225 ;
if ( V_214 )
V_215 -> V_55 |= V_218 ;
F_58 ( V_82 , V_26 ,
L_29 ,
V_44 -> V_165 , V_214 ? 'F' : '.' , V_225 ) ;
F_150 ( V_26 , V_227 ) ;
F_151 ( V_26 , V_145 -> V_142 -> V_110 ,
V_220 , V_138 , 1 , V_215 ,
V_122 ) ;
goto V_105;
V_65:
F_36 ( & V_26 -> V_12 . V_135 ) ;
V_105:
F_36 ( & V_26 -> V_12 . V_229 ) ;
if ( V_44 )
F_40 ( V_44 ) ;
if ( V_145 )
F_86 ( V_145 ) ;
F_47 ( V_215 ) ;
return true ;
}
static bool F_155 ( struct V_25 * V_26 ,
struct V_76 * V_119 ,
T_2 * V_220 , T_2 * V_221 )
{
if ( F_156 ( V_26 , V_221 ) )
return F_154 ( V_26 , V_119 , V_220 ) ;
return F_152 ( V_26 , V_119 , V_220 ,
V_221 ) ;
}
static void F_157 ( struct V_25 * V_26 ,
struct V_43 * V_44 ,
struct V_69 * V_120 ,
T_3 V_230 , T_2 V_125 )
{
int V_146 ;
int V_231 ;
for ( V_146 = 0 ; V_146 < V_230 ; V_146 ++ ) {
if ( ( V_120 + V_146 ) -> V_55 & V_62 ) {
V_231 = ( V_120 + V_146 ) -> V_55 & V_102 ;
F_117 ( V_26 , V_44 ,
( V_120 + V_146 ) -> V_14 ,
F_144 ( ( V_120 + V_146 ) -> V_9 ) ,
L_30 ,
V_231 ) ;
} else {
if ( ! F_103 ( V_26 , V_44 ,
( V_120 + V_146 ) -> V_14 ,
F_144 ( ( V_120 + V_146 ) -> V_9 ) ,
( V_120 + V_146 ) -> V_55 , V_125 ) )
return;
}
}
F_158 ( V_182 , & V_44 -> V_183 ) ;
}
static void F_159 ( struct V_25 * V_26 ,
struct V_69 * V_120 ,
T_2 V_125 , T_2 * V_232 ,
T_3 V_42 )
{
struct V_43 * V_44 ;
V_44 = F_153 ( V_26 , V_232 ) ;
if ( ! V_44 )
goto V_105;
F_119 ( V_26 , V_44 , - 1 ,
L_31 ) ;
F_157 ( V_26 , V_44 , V_120 , V_42 ,
V_125 ) ;
F_32 ( & V_44 -> V_200 ) ;
F_47 ( V_44 -> V_198 ) ;
V_44 -> V_199 = 0 ;
V_44 -> V_198 = NULL ;
F_36 ( & V_44 -> V_200 ) ;
F_78 ( & V_44 -> V_126 , V_125 ) ;
V_105:
if ( V_44 )
F_40 ( V_44 ) ;
}
static void F_160 ( struct V_25 * V_26 ,
struct V_43 * V_44 ,
T_3 V_230 , T_2 V_125 ,
struct V_69 * V_120 )
{
F_157 ( V_26 , V_44 , V_120 ,
V_230 , V_125 ) ;
F_134 ( V_26 , V_44 , V_120 ,
F_51 ( V_230 ) ) ;
F_78 ( & V_44 -> V_126 , V_125 ) ;
}
bool F_161 ( struct V_25 * V_26 , const T_2 * V_14 ,
unsigned short V_9 )
{
struct V_24 * V_28 ;
bool V_93 = false ;
V_28 = F_12 ( V_26 , V_14 , V_9 ) ;
if ( ! V_28 )
goto V_105;
if ( ( V_28 -> V_30 . V_55 & V_100 ) ||
( V_28 -> V_30 . V_55 & V_102 ) )
goto V_105;
V_93 = true ;
V_105:
if ( V_28 )
F_17 ( V_28 ) ;
return V_93 ;
}
static void F_162 ( struct V_25 * V_26 ,
struct V_76 * V_119 ,
T_2 * V_232 , T_3 V_42 )
{
struct V_195 * V_2 ;
struct V_1 * V_54 ;
struct V_43 * V_44 = NULL ;
struct V_69 * V_120 ;
T_2 * V_233 = ( T_2 * ) V_119 ;
T_3 V_121 ;
F_58 ( V_82 , V_26 ,
L_32 ,
V_232 , V_119 -> V_125 , V_42 ,
( ( V_119 -> V_55 & V_218 ) ? 'F' : '.' ) ) ;
V_44 = F_153 ( V_26 , V_232 ) ;
if ( ! V_44 )
goto V_105;
F_32 ( & V_44 -> V_234 ) ;
V_121 = sizeof( struct V_77 ) ;
V_121 *= F_144 ( V_119 -> V_71 ) ;
V_121 += sizeof( * V_119 ) ;
V_233 += V_121 ;
V_120 = (struct V_69 * ) V_233 ;
if ( V_119 -> V_55 & V_218 ) {
F_159 ( V_26 , V_120 , V_119 -> V_125 ,
V_232 , V_42 ) ;
} else {
F_160 ( V_26 , V_44 , V_42 ,
V_119 -> V_125 , V_120 ) ;
}
F_147 ( V_26 , V_44 ) ;
F_36 ( & V_44 -> V_234 ) ;
F_32 ( & V_26 -> V_12 . V_197 ) ;
F_90 (node, safe, &bat_priv->tt.req_list, list) {
if ( ! F_3 ( V_2 -> V_14 , V_232 ) )
continue;
F_133 ( & V_2 -> V_47 ) ;
F_131 ( V_2 ) ;
}
F_36 ( & V_26 -> V_12 . V_197 ) ;
V_105:
if ( V_44 )
F_40 ( V_44 ) ;
}
static void F_163 ( struct V_25 * V_26 )
{
struct V_235 * V_2 , * V_54 ;
F_32 ( & V_26 -> V_12 . V_236 ) ;
F_45 (node, safe, &bat_priv->tt.roam_list, list) {
F_46 ( & V_2 -> V_47 ) ;
F_47 ( V_2 ) ;
}
F_36 ( & V_26 -> V_12 . V_236 ) ;
}
static void F_164 ( struct V_25 * V_26 )
{
struct V_235 * V_2 , * V_54 ;
F_32 ( & V_26 -> V_12 . V_236 ) ;
F_45 (node, safe, &bat_priv->tt.roam_list, list) {
if ( ! F_91 ( V_2 -> V_237 ,
V_238 ) )
continue;
F_46 ( & V_2 -> V_47 ) ;
F_47 ( V_2 ) ;
}
F_36 ( & V_26 -> V_12 . V_236 ) ;
}
static bool F_165 ( struct V_25 * V_26 , T_2 * V_239 )
{
struct V_235 * V_240 ;
bool V_93 = false ;
F_32 ( & V_26 -> V_12 . V_236 ) ;
F_166 (tt_roam_node, &bat_priv->tt.roam_list, list) {
if ( ! F_3 ( V_240 -> V_14 , V_239 ) )
continue;
if ( F_91 ( V_240 -> V_237 ,
V_238 ) )
continue;
if ( ! F_167 ( & V_240 -> V_241 ) )
goto V_65;
V_93 = true ;
break;
}
if ( ! V_93 ) {
V_240 = F_43 ( sizeof( * V_240 ) , V_59 ) ;
if ( ! V_240 )
goto V_65;
V_240 -> V_237 = V_99 ;
F_78 ( & V_240 -> V_241 ,
V_242 - 1 ) ;
F_7 ( V_240 -> V_14 , V_239 ) ;
F_168 ( & V_240 -> V_47 , & V_26 -> V_12 . V_243 ) ;
V_93 = true ;
}
V_65:
F_36 ( & V_26 -> V_12 . V_236 ) ;
return V_93 ;
}
static void F_72 ( struct V_25 * V_26 , T_2 * V_239 ,
unsigned short V_9 ,
struct V_43 * V_44 )
{
struct V_144 * V_145 ;
struct V_244 V_245 ;
V_145 = F_149 ( V_26 ) ;
if ( ! V_145 )
goto V_105;
if ( ! F_165 ( V_26 , V_239 ) )
goto V_105;
F_58 ( V_82 , V_26 ,
L_33 ,
V_44 -> V_165 , V_239 , F_59 ( V_9 ) ) ;
F_150 ( V_26 , V_246 ) ;
memcpy ( V_245 . V_239 , V_239 , sizeof( V_245 . V_239 ) ) ;
V_245 . V_9 = F_44 ( V_9 ) ;
F_151 ( V_26 , V_145 -> V_142 -> V_110 ,
V_44 -> V_165 , V_247 , 1 ,
& V_245 , sizeof( V_245 ) ) ;
V_105:
if ( V_145 )
F_86 ( V_145 ) ;
}
static void F_169 ( struct V_248 * V_249 )
{
struct V_250 * V_250 ;
struct V_251 * V_252 ;
struct V_25 * V_26 ;
V_250 = F_170 ( V_249 ) ;
V_252 = F_2 ( V_250 , struct V_251 , V_249 ) ;
V_26 = F_2 ( V_252 , struct V_25 , V_12 ) ;
F_92 ( V_26 , V_253 ) ;
F_122 ( V_26 ) ;
F_135 ( V_26 ) ;
F_164 ( V_26 ) ;
F_171 ( V_254 , & V_26 -> V_12 . V_249 ,
F_172 ( V_255 ) ) ;
}
void F_173 ( struct V_25 * V_26 )
{
F_174 ( V_26 , V_138 , 1 ) ;
F_175 ( V_26 , V_138 , 1 ) ;
F_176 ( & V_26 -> V_12 . V_249 ) ;
F_93 ( V_26 ) ;
F_123 ( V_26 ) ;
F_132 ( V_26 ) ;
F_97 ( V_26 ) ;
F_163 ( V_26 ) ;
F_47 ( V_26 -> V_12 . V_136 ) ;
}
static void F_177 ( struct V_25 * V_26 , T_3 V_55 ,
bool V_256 , bool V_38 )
{
struct V_16 * V_13 = V_26 -> V_12 . V_29 ;
struct V_5 * V_27 ;
T_3 V_257 = 0 ;
struct V_17 * V_18 ;
T_1 V_146 ;
if ( ! V_13 )
return;
for ( V_146 = 0 ; V_146 < V_13 -> V_11 ; V_146 ++ ) {
V_18 = & V_13 -> V_22 [ V_146 ] ;
F_8 () ;
F_9 (tt_common_entry,
head, hash_entry) {
if ( V_256 ) {
if ( ( V_27 -> V_55 & V_55 ) == V_55 )
continue;
V_27 -> V_55 |= V_55 ;
} else {
if ( ! ( V_27 -> V_55 & V_55 ) )
continue;
V_27 -> V_55 &= ~ V_55 ;
}
V_257 ++ ;
if ( ! V_38 )
continue;
F_27 ( V_26 ,
V_27 -> V_9 ) ;
}
F_11 () ;
}
}
static void F_178 ( struct V_25 * V_26 )
{
struct V_16 * V_13 = V_26 -> V_12 . V_29 ;
struct V_5 * V_190 ;
struct V_24 * V_87 ;
struct V_1 * V_157 ;
struct V_17 * V_18 ;
T_5 * V_158 ;
T_1 V_146 ;
if ( ! V_13 )
return;
for ( V_146 = 0 ; V_146 < V_13 -> V_11 ; V_146 ++ ) {
V_18 = & V_13 -> V_22 [ V_146 ] ;
V_158 = & V_13 -> V_159 [ V_146 ] ;
F_32 ( V_158 ) ;
F_90 (tt_common, node_tmp, head,
hash_entry) {
if ( ! ( V_190 -> V_55 & V_100 ) )
continue;
F_58 ( V_82 , V_26 ,
L_34 ,
V_190 -> V_14 ,
F_59 ( V_190 -> V_9 ) ) ;
F_28 ( V_26 , V_190 -> V_9 ) ;
F_94 ( & V_190 -> V_6 ) ;
V_87 = F_2 ( V_190 ,
struct V_24 ,
V_30 ) ;
F_17 ( V_87 ) ;
}
F_36 ( V_158 ) ;
}
}
static void F_179 ( struct V_25 * V_26 )
{
F_114 ( & V_26 -> V_12 . V_229 ) ;
F_180 ( V_26 ) ;
if ( F_23 ( & V_26 -> V_12 . V_67 ) < 1 ) {
if ( ! F_167 ( & V_26 -> V_12 . V_258 ) )
F_77 ( V_26 ) ;
return;
}
F_177 ( V_26 , V_107 , false , true ) ;
F_178 ( V_26 ) ;
F_146 ( V_26 ) ;
F_50 ( & V_26 -> V_12 . V_106 ) ;
F_58 ( V_82 , V_26 ,
L_35 ,
( T_2 ) F_23 ( & V_26 -> V_12 . V_106 ) ) ;
F_78 ( & V_26 -> V_12 . V_258 , V_259 ) ;
F_77 ( V_26 ) ;
}
void F_181 ( struct V_25 * V_26 )
{
F_32 ( & V_26 -> V_12 . V_229 ) ;
F_179 ( V_26 ) ;
F_36 ( & V_26 -> V_12 . V_229 ) ;
}
bool F_182 ( struct V_25 * V_26 , T_2 * V_191 , T_2 * V_260 ,
unsigned short V_9 )
{
struct V_24 * V_28 = NULL ;
struct V_31 * V_32 = NULL ;
struct V_41 * V_36 ;
bool V_93 = false ;
V_36 = F_25 ( V_26 , V_9 ) ;
if ( ! V_36 )
return false ;
if ( ! F_23 ( & V_36 -> V_261 ) )
goto V_105;
V_28 = F_12 ( V_26 , V_260 , V_9 ) ;
if ( ! V_28 )
goto V_105;
V_32 = F_13 ( V_26 , V_191 , V_9 ) ;
if ( ! V_32 )
goto V_105;
if ( ! F_124 ( V_28 , V_32 ) )
goto V_105;
V_93 = true ;
V_105:
F_15 ( V_36 ) ;
if ( V_32 )
F_21 ( V_32 ) ;
if ( V_28 )
F_17 ( V_28 ) ;
return V_93 ;
}
static void F_183 ( struct V_25 * V_26 ,
struct V_43 * V_44 ,
const void * V_198 , T_3 V_262 ,
struct V_69 * V_120 ,
T_3 V_230 , T_2 V_125 )
{
T_2 V_224 = ( T_2 ) F_23 ( & V_44 -> V_126 ) ;
struct V_77 * V_123 ;
bool V_214 = true ;
bool V_263 ;
V_123 = (struct V_77 * ) V_198 ;
V_263 = F_184 ( V_182 ,
& V_44 -> V_183 ) ;
if ( ( ! V_263 && V_125 == 1 ) || V_125 - V_224 == 1 ) {
if ( ! V_230 ) {
V_214 = false ;
goto V_264;
}
F_32 ( & V_44 -> V_234 ) ;
F_160 ( V_26 , V_44 , V_230 ,
V_125 , V_120 ) ;
F_147 ( V_26 , V_44 ) ;
F_36 ( & V_44 -> V_234 ) ;
if ( ! F_143 ( V_44 , V_123 ,
V_262 ) )
goto V_264;
} else {
if ( ! V_263 || V_125 != V_224 ||
! F_143 ( V_44 , V_123 ,
V_262 ) ) {
V_264:
F_58 ( V_82 , V_26 ,
L_36 ,
V_44 -> V_165 , V_125 , V_224 ,
V_230 ) ;
F_148 ( V_26 , V_44 , V_125 ,
V_123 , V_262 ,
V_214 ) ;
return;
}
}
}
bool F_185 ( struct V_25 * V_26 ,
T_2 * V_14 , unsigned short V_9 )
{
struct V_31 * V_32 ;
bool V_93 = false ;
V_32 = F_13 ( V_26 , V_14 , V_9 ) ;
if ( ! V_32 )
goto V_105;
V_93 = V_32 -> V_30 . V_55 & V_102 ;
F_21 ( V_32 ) ;
V_105:
return V_93 ;
}
bool F_186 ( struct V_25 * V_26 ,
T_2 * V_14 , unsigned short V_9 )
{
struct V_24 * V_28 ;
bool V_93 = false ;
V_28 = F_12 ( V_26 , V_14 , V_9 ) ;
if ( ! V_28 )
goto V_105;
V_93 = V_28 -> V_30 . V_55 & V_102 ;
F_17 ( V_28 ) ;
V_105:
return V_93 ;
}
bool F_187 ( struct V_25 * V_26 ,
struct V_43 * V_44 ,
const unsigned char * V_14 ,
unsigned short V_9 )
{
bool V_93 = false ;
if ( ! F_103 ( V_26 , V_44 , V_14 , V_9 ,
V_166 ,
F_23 ( & V_44 -> V_126 ) ) )
goto V_105;
F_58 ( V_82 , V_26 ,
L_37 ,
V_14 , F_59 ( V_9 ) , V_44 -> V_165 ) ;
V_93 = true ;
V_105:
return V_93 ;
}
void F_188 ( struct V_83 * V_84 )
{
struct V_25 * V_26 = F_62 ( V_84 ) ;
int V_92 = F_23 ( & V_26 -> V_92 ) ;
int V_91 , V_156 = V_253 / 2 ;
bool V_265 = false ;
F_32 ( & V_26 -> V_12 . V_229 ) ;
while ( true ) {
V_91 = F_53 ( V_26 ) ;
if ( V_92 >= V_91 )
break;
F_92 ( V_26 , V_156 ) ;
F_178 ( V_26 ) ;
V_156 /= 2 ;
V_265 = true ;
F_66 ( V_104 , V_84 ,
L_38 ,
V_92 ) ;
}
if ( V_265 )
F_179 ( V_26 ) ;
F_36 ( & V_26 -> V_12 . V_229 ) ;
}
static void F_189 ( struct V_25 * V_26 ,
struct V_43 * V_165 ,
T_2 V_55 , void * V_266 ,
T_3 V_267 )
{
struct V_77 * V_123 ;
struct V_69 * V_120 ;
struct V_76 * V_119 ;
T_3 V_42 , V_71 ;
if ( V_267 < sizeof( * V_119 ) )
return;
V_119 = (struct V_76 * ) V_266 ;
V_267 -= sizeof( * V_119 ) ;
V_71 = F_144 ( V_119 -> V_71 ) ;
if ( V_267 < sizeof( * V_123 ) * V_71 )
return;
V_123 = (struct V_77 * ) ( V_119 + 1 ) ;
V_120 = (struct V_69 * ) ( V_123 + V_71 ) ;
V_267 -= sizeof( * V_123 ) * V_71 ;
V_42 = F_52 ( V_267 ) ;
F_183 ( V_26 , V_165 , V_123 , V_71 , V_120 ,
V_42 , V_119 -> V_125 ) ;
}
static int F_190 ( struct V_25 * V_26 ,
T_2 * V_191 , T_2 * V_260 ,
void * V_266 ,
T_3 V_267 )
{
struct V_76 * V_119 ;
T_3 V_268 , V_210 ;
char V_269 ;
bool V_93 ;
if ( V_267 < sizeof( * V_119 ) )
return V_270 ;
V_119 = (struct V_76 * ) V_266 ;
V_267 -= sizeof( * V_119 ) ;
V_268 = sizeof( struct V_77 ) ;
V_268 *= F_144 ( V_119 -> V_71 ) ;
if ( V_267 < V_268 )
return V_270 ;
V_267 -= V_268 ;
V_210 = F_52 ( V_267 ) ;
switch ( V_119 -> V_55 & V_271 ) {
case V_217 :
F_150 ( V_26 , V_272 ) ;
V_93 = F_155 ( V_26 , V_119 , V_191 , V_260 ) ;
if ( ! V_93 ) {
if ( V_119 -> V_55 & V_218 )
V_269 = 'F' ;
else
V_269 = '.' ;
F_58 ( V_82 , V_26 ,
L_39 ,
V_260 , V_269 ) ;
return V_273 ;
}
break;
case V_226 :
F_150 ( V_26 , V_274 ) ;
if ( F_156 ( V_26 , V_260 ) ) {
F_162 ( V_26 , V_119 ,
V_191 , V_210 ) ;
return V_270 ;
}
if ( V_119 -> V_55 & V_218 )
V_269 = 'F' ;
else
V_269 = '.' ;
F_58 ( V_82 , V_26 ,
L_40 , V_260 , V_269 ) ;
return V_273 ;
}
return V_270 ;
}
static int F_191 ( struct V_25 * V_26 ,
T_2 * V_191 , T_2 * V_260 ,
void * V_266 ,
T_3 V_267 )
{
struct V_244 * V_275 ;
struct V_43 * V_44 = NULL ;
if ( ! F_156 ( V_26 , V_260 ) )
return V_273 ;
if ( V_267 < sizeof( * V_275 ) )
goto V_105;
V_44 = F_153 ( V_26 , V_191 ) ;
if ( ! V_44 )
goto V_105;
F_150 ( V_26 , V_276 ) ;
V_275 = (struct V_244 * ) V_266 ;
F_58 ( V_82 , V_26 ,
L_41 ,
V_191 , V_275 -> V_239 ) ;
F_103 ( V_26 , V_44 , V_275 -> V_239 ,
F_144 ( V_275 -> V_9 ) , V_102 ,
F_23 ( & V_44 -> V_126 ) + 1 ) ;
V_105:
if ( V_44 )
F_40 ( V_44 ) ;
return V_270 ;
}
int F_192 ( struct V_25 * V_26 )
{
int V_93 ;
F_193 ( ! ( V_194 & V_115 ) ) ;
V_93 = F_54 ( V_26 ) ;
if ( V_93 < 0 )
return V_93 ;
V_93 = F_96 ( V_26 ) ;
if ( V_93 < 0 )
return V_93 ;
F_194 ( V_26 , F_189 ,
F_190 ,
V_138 , 1 , V_112 ) ;
F_194 ( V_26 , NULL ,
F_191 ,
V_247 , 1 , V_112 ) ;
F_195 ( & V_26 -> V_12 . V_249 , F_169 ) ;
F_171 ( V_254 , & V_26 -> V_12 . V_249 ,
F_172 ( V_255 ) ) ;
return 1 ;
}
bool F_196 ( struct V_25 * V_26 ,
const T_2 * V_14 , unsigned short V_9 )
{
struct V_31 * V_12 ;
bool V_93 ;
V_12 = F_13 ( V_26 , V_14 , V_9 ) ;
if ( ! V_12 )
return false ;
V_93 = V_12 -> V_30 . V_55 & V_118 ;
F_21 ( V_12 ) ;
return V_93 ;
}

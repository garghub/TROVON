static void F_1 ( T_1 V_1 [] , T_1 * V_2 , T_1 V_3 )
{
V_1 [ * V_2 ] = V_3 ;
* V_2 = ( * V_2 + 1 ) % V_4 ;
}
static T_1 F_2 ( const T_1 V_1 [] )
{
const T_1 * V_5 ;
T_2 V_6 = 0 ;
T_2 V_7 = 0 ;
T_2 V_8 = 0 ;
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
static void F_3 ( struct V_9 * V_10 )
{
F_4 ( V_10 -> V_11 . V_12 ) ;
F_4 ( V_10 -> V_11 . V_13 ) ;
}
static int F_5 ( struct V_9 * V_10 ,
int V_14 )
{
void * V_15 ;
T_3 V_16 ;
int V_17 = - V_18 ;
F_6 ( & V_10 -> V_11 . V_19 ) ;
V_16 = ( V_14 - 1 ) * sizeof( unsigned long ) * V_20 ;
V_15 = F_7 ( V_14 ,
V_20 * sizeof( unsigned long ) ,
V_21 ) ;
if ( ! V_15 )
goto V_22;
memcpy ( V_15 , V_10 -> V_11 . V_12 , V_16 ) ;
F_4 ( V_10 -> V_11 . V_12 ) ;
V_10 -> V_11 . V_12 = V_15 ;
V_15 = F_7 ( V_14 , sizeof( T_1 ) , V_21 ) ;
if ( ! V_15 ) {
F_4 ( V_10 -> V_11 . V_12 ) ;
goto V_22;
}
memcpy ( V_15 , V_10 -> V_11 . V_13 ,
( V_14 - 1 ) * sizeof( T_1 ) ) ;
F_4 ( V_10 -> V_11 . V_13 ) ;
V_10 -> V_11 . V_13 = V_15 ;
V_17 = 0 ;
V_22:
F_8 ( & V_10 -> V_11 . V_19 ) ;
return V_17 ;
}
static int F_9 ( struct V_9 * V_10 ,
int V_14 , int V_23 )
{
int V_17 = - V_18 ;
T_3 V_24 , V_25 ;
void * V_15 = NULL ;
F_6 ( & V_10 -> V_11 . V_19 ) ;
if ( V_14 == 0 )
goto V_26;
V_24 = sizeof( unsigned long ) * V_20 ;
V_15 = F_7 ( V_14 , V_24 , V_21 ) ;
if ( ! V_15 )
goto V_22;
memcpy ( V_15 , V_10 -> V_11 . V_12 , V_23 * V_24 ) ;
V_25 = ( V_23 + 1 ) * V_24 ;
memcpy ( ( char * ) V_15 + V_23 * V_24 ,
( V_27 * ) V_10 -> V_11 . V_12 + V_25 ,
( V_14 - V_23 ) * V_24 ) ;
V_26:
F_4 ( V_10 -> V_11 . V_12 ) ;
V_10 -> V_11 . V_12 = V_15 ;
if ( V_14 == 0 )
goto V_28;
V_15 = F_7 ( V_14 , sizeof( T_1 ) , V_21 ) ;
if ( ! V_15 ) {
F_4 ( V_10 -> V_11 . V_12 ) ;
goto V_22;
}
memcpy ( V_15 , V_10 -> V_11 . V_13 ,
V_23 * sizeof( T_1 ) ) ;
V_25 = ( V_23 + 1 ) * sizeof( T_1 ) ;
memcpy ( ( char * ) V_15 + V_23 * sizeof( T_1 ) ,
V_10 -> V_11 . V_13 + V_25 ,
( V_14 - V_23 ) * sizeof( T_1 ) ) ;
V_28:
F_4 ( V_10 -> V_11 . V_13 ) ;
V_10 -> V_11 . V_13 = V_15 ;
V_17 = 0 ;
V_22:
F_8 ( & V_10 -> V_11 . V_19 ) ;
return V_17 ;
}
static struct V_9 *
F_10 ( struct V_29 * V_30 , const T_1 * V_31 )
{
struct V_9 * V_10 ;
int V_32 , V_33 ;
V_10 = F_11 ( V_30 , V_31 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_12 ( V_30 , V_31 ) ;
if ( ! V_10 )
return NULL ;
F_13 ( & V_10 -> V_11 . V_19 ) ;
V_32 = V_30 -> V_34 * sizeof( unsigned long ) * V_20 ;
V_10 -> V_11 . V_12 = F_14 ( V_32 , V_21 ) ;
if ( ! V_10 -> V_11 . V_12 )
goto V_35;
V_32 = V_30 -> V_34 * sizeof( T_1 ) ;
V_10 -> V_11 . V_13 = F_14 ( V_32 , V_21 ) ;
if ( ! V_10 -> V_11 . V_13 )
goto V_35;
V_33 = F_15 ( V_30 -> V_36 , V_37 ,
V_38 , V_10 ,
& V_10 -> V_39 ) ;
if ( V_33 != 0 )
goto V_35;
return V_10 ;
V_35:
F_16 ( V_10 ) ;
F_16 ( V_10 ) ;
return NULL ;
}
static struct V_40 *
F_17 ( struct V_41 * V_42 ,
const T_1 * V_43 ,
struct V_9 * V_10 ,
struct V_9 * V_44 )
{
struct V_40 * V_45 ;
V_45 = F_18 ( V_10 , V_42 , V_43 ) ;
if ( ! V_45 )
goto V_46;
V_45 -> V_10 = V_44 ;
V_46:
return V_45 ;
}
static int F_19 ( struct V_41 * V_42 )
{
struct V_47 * V_47 ;
unsigned char * V_48 ;
T_4 V_49 ;
F_20 ( & V_49 , sizeof( V_49 ) ) ;
F_21 ( & V_42 -> V_11 . V_50 , V_49 ) ;
V_42 -> V_11 . V_51 = V_52 ;
V_48 = F_22 ( V_42 -> V_11 . V_51 , V_21 ) ;
if ( ! V_48 )
return - V_18 ;
V_42 -> V_11 . V_48 = V_48 ;
V_47 = (struct V_47 * ) V_48 ;
V_47 -> V_53 = V_54 ;
V_47 -> V_55 = V_56 ;
V_47 -> V_57 = 2 ;
V_47 -> V_58 = V_59 ;
V_47 -> V_60 = 0 ;
V_47 -> V_61 = V_62 ;
return 0 ;
}
static void F_23 ( struct V_41 * V_42 )
{
F_4 ( V_42 -> V_11 . V_48 ) ;
V_42 -> V_11 . V_48 = NULL ;
}
static void F_24 ( struct V_41 * V_42 )
{
struct V_47 * V_47 ;
unsigned char * V_48 = V_42 -> V_11 . V_48 ;
V_47 = (struct V_47 * ) V_48 ;
F_25 ( V_47 -> V_63 ,
V_42 -> V_64 -> V_65 ) ;
F_25 ( V_47 -> V_66 ,
V_42 -> V_64 -> V_65 ) ;
}
static void
F_26 ( struct V_41 * V_42 )
{
struct V_47 * V_47 ;
unsigned char * V_48 = V_42 -> V_11 . V_48 ;
V_47 = (struct V_47 * ) V_48 ;
V_47 -> V_57 = V_67 ;
}
static unsigned long
F_27 ( const struct V_29 * V_30 )
{
unsigned int V_68 ;
V_68 = F_28 ( & V_30 -> V_69 ) - V_70 ;
V_68 += F_29 () % ( 2 * V_70 ) ;
return V_71 + F_30 ( V_68 ) ;
}
static unsigned long F_31 ( void )
{
return V_71 + F_30 ( F_29 () % ( V_70 / 2 ) ) ;
}
static T_1 F_32 ( T_1 V_61 , const struct V_29 * V_30 )
{
int V_72 = F_28 ( & V_30 -> V_72 ) ;
int V_73 ;
V_73 = V_61 * ( V_62 - V_72 ) ;
V_73 /= V_62 ;
return V_73 ;
}
static bool F_33 ( int V_74 , int V_75 ,
T_5 V_76 )
{
int V_77 = 0 ;
V_77 += V_74 + V_52 ;
V_77 += F_34 ( V_76 ) ;
return ( V_77 <= V_75 ) &&
( V_77 <= V_78 ) ;
}
static void F_35 ( struct V_79 * V_80 ,
struct V_41 * V_42 )
{
struct V_29 * V_30 = F_36 ( V_42 -> V_81 ) ;
const char * V_82 ;
T_1 V_83 ;
T_6 V_74 ;
struct V_47 * V_47 ;
struct V_84 * V_85 ;
T_1 * V_86 ;
if ( V_42 -> V_87 != V_88 )
return;
V_83 = 0 ;
V_74 = 0 ;
V_86 = V_80 -> V_85 -> V_89 ;
V_47 = (struct V_47 * ) V_86 ;
while ( F_33 ( V_74 , V_80 -> V_75 ,
V_47 -> V_76 ) ) {
if ( V_80 -> V_90 & F_37 ( V_83 ) &&
V_80 -> V_91 == V_42 )
V_47 -> V_58 |= V_92 ;
else
V_47 -> V_58 &= ~ V_92 ;
if ( V_83 > 0 || ! V_80 -> V_93 )
V_82 = L_1 ;
else
V_82 = L_2 ;
F_38 ( V_94 , V_30 ,
L_3 ,
V_82 , ( V_83 > 0 ? L_4 : L_5 ) ,
V_47 -> V_63 ,
F_39 ( V_47 -> V_95 ) ,
V_47 -> V_61 , V_47 -> V_57 ,
( ( V_47 -> V_58 & V_92 ) ?
L_6 : L_7 ) ,
V_42 -> V_64 -> V_96 ,
V_42 -> V_64 -> V_65 ) ;
V_74 += V_52 ;
V_74 += F_34 ( V_47 -> V_76 ) ;
V_83 ++ ;
V_86 = V_80 -> V_85 -> V_89 + V_74 ;
V_47 = (struct V_47 * ) V_86 ;
}
V_85 = F_40 ( V_80 -> V_85 , V_21 ) ;
if ( V_85 ) {
F_41 ( V_30 , V_97 ) ;
F_42 ( V_30 , V_98 ,
V_85 -> V_99 + V_100 ) ;
F_43 ( V_85 , V_42 ) ;
}
}
static void F_44 ( struct V_79 * V_80 )
{
struct V_101 * V_81 ;
struct V_29 * V_30 ;
struct V_41 * V_102 = NULL ;
if ( ! V_80 -> V_91 ) {
F_45 ( L_8 ) ;
goto V_46;
}
V_81 = V_80 -> V_91 -> V_81 ;
V_30 = F_36 ( V_81 ) ;
if ( F_46 ( ! V_80 -> V_103 ) )
goto V_46;
if ( F_46 ( V_80 -> V_103 -> V_81 != V_81 ) )
goto V_46;
if ( V_80 -> V_91 -> V_87 != V_88 )
goto V_46;
V_102 = F_47 ( V_30 ) ;
if ( ! V_102 )
goto V_46;
F_35 ( V_80 , V_80 -> V_103 ) ;
V_46:
if ( V_102 )
F_48 ( V_102 ) ;
}
static bool
F_49 ( const struct V_47 * V_104 ,
struct V_29 * V_30 ,
int V_75 , unsigned long V_105 ,
bool V_106 ,
const struct V_41 * V_91 ,
const struct V_41 * V_103 ,
const struct V_79 * V_80 )
{
struct V_47 * V_47 ;
int V_107 = V_80 -> V_75 + V_75 ;
struct V_41 * V_102 = NULL ;
bool V_108 = false ;
unsigned long V_109 ;
V_47 = (struct V_47 * ) V_80 -> V_85 -> V_89 ;
V_109 = V_105 ;
V_109 += F_30 ( V_110 ) ;
if ( ! F_50 ( V_105 , V_80 -> V_105 ) ||
! F_51 ( V_109 , V_80 -> V_105 ) )
return false ;
if ( V_107 > V_78 )
return false ;
if ( V_80 -> V_103 != V_103 )
return false ;
V_102 = F_47 ( V_30 ) ;
if ( ! V_102 )
return false ;
if ( ! V_106 &&
! ( V_47 -> V_58 & V_92 ) &&
V_47 -> V_57 != 1 &&
( ! V_80 -> V_93 ||
V_80 -> V_91 == V_102 ) ) {
V_108 = true ;
goto V_46;
}
if ( V_106 &&
V_104 -> V_57 == 1 &&
V_80 -> V_91 == V_91 &&
( V_47 -> V_58 & V_92 ||
( V_80 -> V_93 &&
V_80 -> V_91 != V_102 ) ) ) {
V_108 = true ;
goto V_46;
}
V_46:
if ( V_102 )
F_48 ( V_102 ) ;
return V_108 ;
}
static void F_52 ( const unsigned char * V_111 ,
int V_75 , unsigned long V_105 ,
bool V_112 ,
struct V_41 * V_91 ,
struct V_41 * V_103 ,
int V_113 )
{
struct V_29 * V_30 = F_36 ( V_91 -> V_81 ) ;
struct V_79 * V_114 ;
unsigned char * V_115 ;
unsigned int V_116 ;
if ( ! F_53 ( & V_91 -> V_117 ) )
return;
if ( ! F_53 ( & V_103 -> V_117 ) )
goto V_118;
if ( ! V_113 ) {
if ( ! F_54 ( & V_30 -> V_119 ) ) {
F_38 ( V_94 , V_30 ,
L_9 ) ;
goto V_120;
}
}
V_114 = F_22 ( sizeof( * V_114 ) , V_21 ) ;
if ( ! V_114 )
goto V_121;
if ( F_28 ( & V_30 -> V_122 ) &&
V_75 < V_78 )
V_116 = V_78 ;
else
V_116 = V_75 ;
V_116 += V_100 ;
V_114 -> V_85 = F_55 ( NULL , V_116 ) ;
if ( ! V_114 -> V_85 )
goto V_123;
V_114 -> V_85 -> V_124 = V_125 ;
F_56 ( V_114 -> V_85 , V_100 ) ;
V_115 = F_57 ( V_114 -> V_85 , V_75 ) ;
V_114 -> V_75 = V_75 ;
memcpy ( V_115 , V_111 , V_75 ) ;
V_114 -> V_93 = V_113 ;
V_114 -> V_91 = V_91 ;
V_114 -> V_103 = V_103 ;
V_114 -> V_126 = 0 ;
V_114 -> V_90 = V_59 ;
V_114 -> V_105 = V_105 ;
if ( V_112 )
V_114 -> V_90 |= 1 ;
F_6 ( & V_30 -> V_127 ) ;
F_58 ( & V_114 -> V_128 , & V_30 -> V_129 ) ;
F_8 ( & V_30 -> V_127 ) ;
F_59 ( & V_114 -> V_130 ,
V_131 ) ;
F_60 ( V_132 ,
& V_114 -> V_130 ,
V_105 - V_71 ) ;
return;
V_123:
F_4 ( V_114 ) ;
V_121:
if ( ! V_113 )
F_61 ( & V_30 -> V_119 ) ;
V_120:
F_48 ( V_103 ) ;
V_118:
F_48 ( V_91 ) ;
}
static void F_62 ( struct V_79 * V_114 ,
const unsigned char * V_111 ,
int V_75 , bool V_112 )
{
unsigned char * V_115 ;
unsigned long V_133 ;
V_115 = F_57 ( V_114 -> V_85 , V_75 ) ;
memcpy ( V_115 , V_111 , V_75 ) ;
V_114 -> V_75 += V_75 ;
V_114 -> V_126 ++ ;
if ( V_112 ) {
V_133 = F_37 ( V_114 -> V_126 ) ;
V_114 -> V_90 |= V_133 ;
}
}
static void F_63 ( struct V_29 * V_30 ,
unsigned char * V_111 ,
int V_75 ,
struct V_41 * V_91 ,
struct V_41 * V_103 ,
int V_113 , unsigned long V_105 )
{
struct V_79 * V_114 = NULL ;
struct V_79 * V_134 = NULL ;
struct V_47 * V_47 ;
bool V_112 ;
unsigned long V_135 ;
V_47 = (struct V_47 * ) V_111 ;
V_112 = ! ! ( V_47 -> V_58 & V_92 ) ;
V_135 = F_30 ( V_110 ) ;
F_6 ( & V_30 -> V_127 ) ;
if ( F_28 ( & V_30 -> V_122 ) && ! V_113 ) {
F_64 (forw_packet_pos,
&bat_priv->forw_bat_list, list) {
if ( F_49 ( V_47 ,
V_30 , V_75 ,
V_105 , V_112 ,
V_91 ,
V_103 ,
V_134 ) ) {
V_114 = V_134 ;
break;
}
}
}
if ( ! V_114 ) {
F_8 ( & V_30 -> V_127 ) ;
if ( ! V_113 && F_28 ( & V_30 -> V_122 ) )
V_105 += V_135 ;
F_52 ( V_111 , V_75 ,
V_105 , V_112 ,
V_91 , V_103 ,
V_113 ) ;
} else {
F_62 ( V_114 , V_111 ,
V_75 , V_112 ) ;
F_8 ( & V_30 -> V_127 ) ;
}
}
static void F_65 ( struct V_9 * V_10 ,
const struct V_136 * V_136 ,
struct V_47 * V_47 ,
bool V_137 ,
bool V_138 ,
struct V_41 * V_91 ,
struct V_41 * V_103 )
{
struct V_29 * V_30 = F_36 ( V_91 -> V_81 ) ;
T_2 V_76 ;
if ( V_47 -> V_57 <= 1 ) {
F_38 ( V_94 , V_30 , L_10 ) ;
return;
}
if ( ! V_138 ) {
if ( V_137 )
V_47 -> V_58 |= V_139 ;
else
return;
}
V_76 = F_34 ( V_47 -> V_76 ) ;
V_47 -> V_57 -- ;
F_25 ( V_47 -> V_66 , V_136 -> V_140 ) ;
V_47 -> V_61 = F_32 ( V_47 -> V_61 ,
V_30 ) ;
F_38 ( V_94 , V_30 ,
L_11 ,
V_47 -> V_61 , V_47 -> V_57 ) ;
if ( V_137 )
V_47 -> V_58 |= V_92 ;
else
V_47 -> V_58 &= ~ V_92 ;
F_63 ( V_30 , ( unsigned char * ) V_47 ,
V_52 + V_76 ,
V_91 , V_103 , 0 ,
F_31 () ) ;
}
static void
F_66 ( struct V_41 * V_42 )
{
struct V_29 * V_30 = F_36 ( V_42 -> V_81 ) ;
struct V_141 * V_142 = V_30 -> V_36 ;
struct V_143 * V_144 ;
struct V_9 * V_10 ;
unsigned long * V_145 ;
T_4 V_7 ;
T_3 V_146 ;
T_1 * V_147 ;
int V_148 ;
for ( V_7 = 0 ; V_7 < V_142 -> V_32 ; V_7 ++ ) {
V_144 = & V_142 -> V_149 [ V_7 ] ;
F_67 () ;
F_68 (orig_node, head, hash_entry) {
F_6 ( & V_10 -> V_11 . V_19 ) ;
V_146 = V_42 -> V_148 * V_20 ;
V_145 = & V_10 -> V_11 . V_12 [ V_146 ] ;
F_69 ( V_30 , V_145 , 1 , 0 ) ;
V_148 = V_42 -> V_148 ;
V_147 = & V_10 -> V_11 . V_13 [ V_148 ] ;
* V_147 = F_70 ( V_145 , V_150 ) ;
F_8 ( & V_10 -> V_11 . V_19 ) ;
}
F_71 () ;
}
}
static void F_72 ( struct V_41 * V_42 )
{
struct V_29 * V_30 = F_36 ( V_42 -> V_81 ) ;
unsigned char * * V_48 = & V_42 -> V_11 . V_48 ;
struct V_47 * V_47 ;
struct V_41 * V_102 , * V_151 ;
int * V_51 = & V_42 -> V_11 . V_51 ;
T_4 V_95 ;
T_2 V_76 = 0 ;
unsigned long V_105 ;
V_102 = F_47 ( V_30 ) ;
if ( V_42 == V_102 ) {
F_73 ( V_30 ) ;
V_76 = F_74 ( V_30 , V_48 ,
V_51 ,
V_52 ) ;
}
V_47 = (struct V_47 * ) ( * V_48 ) ;
V_47 -> V_76 = F_75 ( V_76 ) ;
V_95 = ( T_4 ) F_28 ( & V_42 -> V_11 . V_50 ) ;
V_47 -> V_95 = F_76 ( V_95 ) ;
F_61 ( & V_42 -> V_11 . V_50 ) ;
F_66 ( V_42 ) ;
V_105 = F_27 ( V_30 ) ;
if ( V_42 != V_102 ) {
F_63 ( V_30 , * V_48 , * V_51 ,
V_42 , V_42 , 1 , V_105 ) ;
goto V_46;
}
F_67 () ;
F_77 (tmp_hard_iface, &batadv_hardif_list, list) {
if ( V_151 -> V_81 != V_42 -> V_81 )
continue;
F_63 ( V_30 , * V_48 ,
* V_51 , V_42 ,
V_151 , 1 , V_105 ) ;
}
F_71 () ;
V_46:
if ( V_102 )
F_48 ( V_102 ) ;
}
static void
F_78 ( struct V_29 * V_30 ,
struct V_9 * V_10 ,
struct V_152 * V_153 ,
const struct V_136 * V_136 ,
const struct V_47 * V_47 ,
struct V_41 * V_91 ,
struct V_41 * V_103 ,
enum V_154 V_155 )
{
struct V_156 * V_157 = NULL ;
struct V_156 * V_158 = NULL ;
struct V_40 * V_45 = NULL ;
struct V_40 * V_159 = NULL ;
struct V_40 * V_160 = NULL ;
struct V_9 * V_161 ;
int V_148 ;
T_1 V_162 , V_163 ;
T_1 * V_43 ;
T_1 V_164 ;
F_38 ( V_94 , V_30 ,
L_12 ) ;
F_67 () ;
F_68 (tmp_neigh_node,
&orig_node->neigh_list, list) {
V_43 = V_159 -> V_31 ;
if ( F_79 ( V_43 , V_136 -> V_140 ) &&
V_159 -> V_91 == V_91 &&
F_53 ( & V_159 -> V_117 ) ) {
if ( F_80 ( V_45 , L_13 ) )
F_81 ( V_45 ) ;
V_45 = V_159 ;
continue;
}
if ( V_155 != V_165 )
continue;
V_157 = F_82 ( V_159 ,
V_103 ) ;
if ( ! V_157 )
continue;
F_6 ( & V_159 -> V_166 ) ;
F_1 ( V_157 -> V_11 . V_167 ,
& V_157 -> V_11 . V_168 , 0 ) ;
V_164 = F_2 ( V_157 -> V_11 . V_167 ) ;
V_157 -> V_11 . V_164 = V_164 ;
F_8 ( & V_159 -> V_166 ) ;
F_83 ( V_157 ) ;
V_157 = NULL ;
}
if ( ! V_45 ) {
struct V_9 * V_169 ;
V_169 = F_10 ( V_30 , V_136 -> V_140 ) ;
if ( ! V_169 )
goto V_22;
V_45 = F_17 ( V_91 ,
V_136 -> V_140 ,
V_10 , V_169 ) ;
F_16 ( V_169 ) ;
if ( ! V_45 )
goto V_22;
} else {
F_38 ( V_94 , V_30 ,
L_14 ) ;
}
F_71 () ;
V_157 = F_84 ( V_45 , V_103 ) ;
if ( ! V_157 )
goto V_46;
V_45 -> V_170 = V_71 ;
F_6 ( & V_45 -> V_166 ) ;
F_1 ( V_157 -> V_11 . V_167 ,
& V_157 -> V_11 . V_168 ,
V_47 -> V_61 ) ;
V_164 = F_2 ( V_157 -> V_11 . V_167 ) ;
V_157 -> V_11 . V_164 = V_164 ;
F_8 ( & V_45 -> V_166 ) ;
if ( V_155 == V_165 ) {
V_153 -> V_171 = V_47 -> V_57 ;
V_157 -> V_171 = V_47 -> V_57 ;
}
V_160 = F_85 ( V_10 , V_103 ) ;
if ( V_160 == V_45 )
goto V_46;
if ( V_160 ) {
V_158 = F_82 ( V_160 , V_103 ) ;
if ( ! V_158 )
goto V_46;
if ( V_158 -> V_11 . V_164 > V_157 -> V_11 . V_164 )
goto V_46;
}
if ( V_158 &&
V_157 -> V_11 . V_164 == V_158 -> V_11 . V_164 ) {
V_161 = V_160 -> V_10 ;
F_6 ( & V_161 -> V_11 . V_19 ) ;
V_148 = V_160 -> V_91 -> V_148 ;
V_162 = V_161 -> V_11 . V_13 [ V_148 ] ;
F_8 ( & V_161 -> V_11 . V_19 ) ;
V_161 = V_45 -> V_10 ;
F_6 ( & V_161 -> V_11 . V_19 ) ;
V_148 = V_45 -> V_91 -> V_148 ;
V_163 = V_161 -> V_11 . V_13 [ V_148 ] ;
F_8 ( & V_161 -> V_11 . V_19 ) ;
if ( V_162 >= V_163 )
goto V_46;
}
F_86 ( V_30 , V_10 , V_103 , V_45 ) ;
goto V_46;
V_22:
F_71 () ;
V_46:
if ( V_45 )
F_81 ( V_45 ) ;
if ( V_160 )
F_81 ( V_160 ) ;
if ( V_157 )
F_83 ( V_157 ) ;
if ( V_158 )
F_83 ( V_158 ) ;
}
static int F_87 ( struct V_9 * V_10 ,
struct V_9 * V_172 ,
struct V_47 * V_47 ,
struct V_41 * V_91 ,
struct V_41 * V_103 )
{
struct V_29 * V_30 = F_36 ( V_91 -> V_81 ) ;
struct V_40 * V_45 = NULL , * V_159 ;
struct V_156 * V_157 ;
T_1 V_173 ;
T_1 V_174 , V_175 , V_176 , V_177 ;
unsigned int V_178 , V_179 ;
int V_180 , V_181 , V_148 , V_17 = 0 ;
unsigned int V_182 ;
int V_183 ;
F_67 () ;
F_68 (tmp_neigh_node,
&orig_neigh_node->neigh_list, list) {
if ( ! F_79 ( V_159 -> V_31 ,
V_172 -> V_63 ) )
continue;
if ( V_159 -> V_91 != V_91 )
continue;
if ( ! F_53 ( & V_159 -> V_117 ) )
continue;
V_45 = V_159 ;
break;
}
F_71 () ;
if ( ! V_45 )
V_45 = F_17 ( V_91 ,
V_172 -> V_63 ,
V_172 ,
V_172 ) ;
if ( ! V_45 )
goto V_46;
if ( V_10 == V_172 )
V_45 -> V_170 = V_71 ;
V_10 -> V_170 = V_71 ;
F_6 ( & V_10 -> V_11 . V_19 ) ;
V_148 = V_91 -> V_148 ;
V_174 = V_172 -> V_11 . V_13 [ V_148 ] ;
V_157 = F_84 ( V_45 , V_103 ) ;
if ( V_157 ) {
V_175 = V_157 -> V_11 . V_184 ;
F_83 ( V_157 ) ;
} else {
V_175 = 0 ;
}
F_8 ( & V_10 -> V_11 . V_19 ) ;
if ( V_174 > V_175 )
V_173 = V_175 ;
else
V_173 = V_174 ;
if ( V_173 < V_185 ||
V_175 < V_186 )
V_177 = 0 ;
else
V_177 = ( V_62 * V_173 ) / V_175 ;
V_176 = V_150 - V_175 ;
V_178 = V_176 * V_176 * V_176 ;
V_179 = V_150 *
V_150 *
V_150 ;
V_181 = V_62 * V_178 ;
V_181 /= V_179 ;
V_180 = V_62 - V_181 ;
V_183 = V_62 ;
if ( V_103 && ( V_91 == V_103 ) &&
F_88 ( V_103 -> V_64 ) )
V_183 = F_32 ( V_62 ,
V_30 ) ;
V_182 = V_47 -> V_61 *
V_177 *
V_180 *
V_183 ;
V_182 /= V_62 *
V_62 *
V_62 ;
V_47 -> V_61 = V_182 ;
F_38 ( V_94 , V_30 ,
L_15 ,
V_10 -> V_63 , V_172 -> V_63 , V_173 ,
V_175 , V_177 , V_180 , V_183 ,
V_47 -> V_61 , V_91 -> V_64 -> V_96 ,
V_103 ? V_103 -> V_64 -> V_96 : L_16 ) ;
if ( V_47 -> V_61 >= V_187 )
V_17 = 1 ;
V_46:
if ( V_45 )
F_81 ( V_45 ) ;
return V_17 ;
}
static enum V_154
F_89 ( const struct V_136 * V_136 ,
const struct V_47 * V_47 ,
const struct V_41 * V_91 ,
struct V_41 * V_103 )
{
struct V_29 * V_30 = F_36 ( V_91 -> V_81 ) ;
struct V_9 * V_10 ;
struct V_152 * V_153 = NULL ;
struct V_40 * V_45 ;
struct V_156 * V_157 ;
int V_188 ;
T_7 V_189 ;
int V_190 = 0 ;
int V_191 ;
enum V_154 V_17 = V_165 ;
T_4 V_95 = F_39 ( V_47 -> V_95 ) ;
T_1 * V_43 ;
T_1 V_192 ;
unsigned long * V_193 ;
V_10 = F_10 ( V_30 , V_47 -> V_63 ) ;
if ( ! V_10 )
return V_165 ;
V_153 = F_90 ( V_10 , V_103 ) ;
if ( F_46 ( ! V_153 ) ) {
F_16 ( V_10 ) ;
return 0 ;
}
F_6 ( & V_10 -> V_11 . V_19 ) ;
V_189 = V_95 - V_153 -> V_194 ;
if ( ! F_91 ( & V_10 -> V_195 ) &&
F_92 ( V_30 , V_189 ,
V_150 ,
& V_153 -> V_196 , NULL ) ) {
V_17 = V_197 ;
goto V_46;
}
F_67 () ;
F_68 (neigh_node, &orig_node->neigh_list, list) {
V_157 = F_84 ( V_45 ,
V_103 ) ;
if ( ! V_157 )
continue;
V_43 = V_45 -> V_31 ;
V_188 = F_93 ( V_157 -> V_11 . V_198 ,
V_153 -> V_194 ,
V_95 ) ;
if ( F_79 ( V_43 , V_136 -> V_140 ) &&
V_45 -> V_91 == V_91 ) {
V_191 = 1 ;
if ( V_188 )
V_17 = V_199 ;
} else {
V_191 = 0 ;
if ( V_188 && ( V_17 != V_199 ) )
V_17 = V_200 ;
}
V_193 = V_157 -> V_11 . V_198 ;
V_190 |= F_69 ( V_30 , V_193 ,
V_189 , V_191 ) ;
V_192 = F_70 ( V_193 ,
V_150 ) ;
V_157 -> V_11 . V_184 = V_192 ;
F_83 ( V_157 ) ;
}
F_71 () ;
if ( V_190 ) {
F_38 ( V_94 , V_30 ,
L_17 ,
V_103 ? V_103 -> V_64 -> V_96 : L_16 ,
V_153 -> V_194 , V_95 ) ;
V_153 -> V_194 = V_95 ;
}
V_46:
F_8 ( & V_10 -> V_11 . V_19 ) ;
F_16 ( V_10 ) ;
F_94 ( V_153 ) ;
return V_17 ;
}
static void
F_95 ( const struct V_84 * V_85 , int V_201 ,
struct V_9 * V_10 ,
struct V_41 * V_91 ,
struct V_41 * V_103 )
{
struct V_29 * V_30 = F_36 ( V_91 -> V_81 ) ;
struct V_202 * V_203 = NULL ;
struct V_40 * V_160 = NULL ;
struct V_40 * V_204 = NULL ;
struct V_9 * V_172 ;
struct V_152 * V_153 ;
struct V_40 * V_205 = NULL ;
struct V_156 * V_158 = NULL ;
struct V_47 * V_206 ;
enum V_154 V_155 ;
bool V_138 = false ;
bool V_137 = false ;
bool V_207 , V_208 ;
struct V_84 * V_209 ;
struct V_136 * V_136 ;
T_1 * V_66 ;
int V_210 ;
V_209 = F_96 ( V_85 , V_21 ) ;
if ( ! V_209 )
return;
V_136 = F_97 ( V_209 ) ;
V_206 = (struct V_47 * ) ( V_209 -> V_89 + V_201 ) ;
V_155 = F_89 ( V_136 , V_206 ,
V_91 , V_103 ) ;
if ( F_79 ( V_136 -> V_140 , V_206 -> V_63 ) )
V_137 = true ;
if ( V_155 == V_197 ) {
F_38 ( V_94 , V_30 ,
L_18 ,
V_136 -> V_140 ) ;
goto V_46;
}
if ( V_206 -> V_61 == 0 ) {
F_38 ( V_94 , V_30 ,
L_19 ) ;
goto V_46;
}
if ( V_137 ) {
V_203 = F_98 ( V_91 ,
V_136 -> V_140 ) ;
if ( V_203 )
V_203 -> V_170 = V_71 ;
}
V_160 = F_85 ( V_10 , V_103 ) ;
if ( V_160 ) {
V_204 = F_85 ( V_160 -> V_10 ,
V_103 ) ;
V_158 = F_82 ( V_160 , V_103 ) ;
}
if ( ( V_158 && V_158 -> V_11 . V_164 != 0 ) &&
( F_79 ( V_160 -> V_31 , V_136 -> V_140 ) ) )
V_138 = true ;
V_66 = V_206 -> V_66 ;
if ( V_160 && V_204 &&
( F_79 ( V_160 -> V_31 , V_66 ) ) &&
! ( F_79 ( V_206 -> V_63 , V_66 ) ) &&
( F_79 ( V_160 -> V_31 , V_204 -> V_31 ) ) ) {
F_38 ( V_94 , V_30 ,
L_20 ,
V_136 -> V_140 ) ;
goto V_46;
}
if ( V_103 == V_211 )
F_99 ( V_30 , V_206 , V_10 ) ;
if ( V_137 )
V_172 = V_10 ;
else
V_172 = F_10 ( V_30 ,
V_136 -> V_140 ) ;
if ( ! V_172 )
goto V_46;
F_100 ( V_30 , V_10 , V_172 ,
V_206 , V_137 ) ;
V_205 = F_85 ( V_172 ,
V_103 ) ;
if ( ! V_137 && ( ! V_205 ) ) {
F_38 ( V_94 , V_30 ,
L_21 ) ;
goto V_212;
}
V_210 = F_87 ( V_10 , V_172 ,
V_206 , V_91 ,
V_103 ) ;
V_153 = F_90 ( V_10 , V_103 ) ;
if ( ! V_153 )
goto V_212;
V_207 = V_153 -> V_194 == F_39 ( V_206 -> V_95 ) ;
V_208 = ( V_153 -> V_171 - 3 ) <= V_206 -> V_57 ;
if ( V_210 && ( ( V_155 == V_165 ) ||
( V_207 && V_208 ) ) ) {
F_78 ( V_30 , V_10 ,
V_153 , V_136 ,
V_206 , V_91 ,
V_103 , V_155 ) ;
}
F_94 ( V_153 ) ;
if ( V_103 == V_211 )
goto V_212;
if ( V_137 ) {
if ( ( V_206 -> V_57 <= 2 ) &&
( V_91 != V_103 ) ) {
F_38 ( V_94 , V_30 ,
L_22 ) ;
goto V_212;
}
F_65 ( V_10 , V_136 , V_206 ,
V_137 ,
V_138 , V_91 ,
V_103 ) ;
F_38 ( V_94 , V_30 ,
L_23 ) ;
goto V_212;
}
if ( ! V_210 ) {
F_38 ( V_94 , V_30 ,
L_24 ) ;
goto V_212;
}
if ( V_155 == V_199 ) {
F_38 ( V_94 , V_30 ,
L_25 ) ;
goto V_212;
}
F_38 ( V_94 , V_30 ,
L_26 ) ;
F_65 ( V_10 , V_136 , V_206 ,
V_137 , V_138 ,
V_91 , V_103 ) ;
V_212:
if ( ( V_172 ) && ( ! V_137 ) )
F_16 ( V_172 ) ;
V_46:
if ( V_158 )
F_83 ( V_158 ) ;
if ( V_160 )
F_81 ( V_160 ) ;
if ( V_204 )
F_81 ( V_204 ) ;
if ( V_205 )
F_81 ( V_205 ) ;
if ( V_203 )
F_101 ( V_203 ) ;
F_102 ( V_209 ) ;
}
static void F_103 ( const struct V_84 * V_85 , int V_201 ,
struct V_41 * V_91 )
{
struct V_29 * V_30 = F_36 ( V_91 -> V_81 ) ;
struct V_9 * V_172 , * V_10 ;
struct V_41 * V_42 ;
struct V_47 * V_206 ;
T_4 V_213 ;
bool V_214 ;
struct V_136 * V_136 ;
bool V_215 = false ;
bool V_216 = false ;
bool V_217 = false ;
V_206 = (struct V_47 * ) ( V_85 -> V_89 + V_201 ) ;
V_136 = F_97 ( V_85 ) ;
if ( V_206 -> V_53 != V_54 )
return;
V_213 = F_28 ( & V_91 -> V_11 . V_50 ) ;
if ( V_206 -> V_58 & V_92 )
V_214 = true ;
else
V_214 = false ;
F_38 ( V_94 , V_30 ,
L_27 ,
V_136 -> V_140 , V_91 -> V_64 -> V_96 ,
V_91 -> V_64 -> V_65 , V_206 -> V_63 ,
V_206 -> V_66 , F_39 ( V_206 -> V_95 ) ,
V_206 -> V_61 , V_206 -> V_57 ,
V_206 -> V_55 , V_214 ) ;
F_67 () ;
F_77 (hard_iface, &batadv_hardif_list, list) {
if ( V_42 -> V_87 != V_88 )
continue;
if ( V_42 -> V_81 != V_91 -> V_81 )
continue;
if ( F_79 ( V_136 -> V_140 ,
V_42 -> V_64 -> V_65 ) )
V_216 = true ;
if ( F_79 ( V_206 -> V_63 ,
V_42 -> V_64 -> V_65 ) )
V_217 = true ;
if ( F_79 ( V_206 -> V_66 ,
V_42 -> V_64 -> V_65 ) )
V_215 = true ;
}
F_71 () ;
if ( V_216 ) {
F_38 ( V_94 , V_30 ,
L_28 ,
V_136 -> V_140 ) ;
return;
}
if ( V_217 ) {
unsigned long * V_145 ;
int V_218 ;
T_7 V_219 ;
T_6 V_148 ;
T_1 * V_220 ;
V_172 = F_10 ( V_30 ,
V_136 -> V_140 ) ;
if ( ! V_172 )
return;
if ( V_214 &&
F_79 ( V_91 -> V_64 -> V_65 ,
V_206 -> V_63 ) ) {
V_148 = V_91 -> V_148 ;
V_218 = V_148 * V_20 ;
F_6 ( & V_172 -> V_11 . V_19 ) ;
V_145 = & V_172 -> V_11 . V_12 [ V_218 ] ;
V_219 = V_213 - 2 ;
V_219 -= F_39 ( V_206 -> V_95 ) ;
F_104 ( V_145 , V_219 ) ;
V_220 = & V_172 -> V_11 . V_13 [ V_148 ] ;
* V_220 = F_70 ( V_145 ,
V_150 ) ;
F_8 ( & V_172 -> V_11 . V_19 ) ;
}
F_38 ( V_94 , V_30 ,
L_29 ) ;
F_16 ( V_172 ) ;
return;
}
if ( V_215 ) {
F_38 ( V_94 , V_30 ,
L_30 ,
V_136 -> V_140 ) ;
return;
}
if ( V_206 -> V_58 & V_139 ) {
F_38 ( V_94 , V_30 ,
L_31 ,
V_136 -> V_140 ) ;
return;
}
V_10 = F_10 ( V_30 , V_206 -> V_63 ) ;
if ( ! V_10 )
return;
F_95 ( V_85 , V_201 , V_10 ,
V_91 , V_211 ) ;
F_67 () ;
F_77 (hard_iface, &batadv_hardif_list, list) {
if ( V_42 -> V_87 != V_88 )
continue;
if ( V_42 -> V_81 != V_30 -> V_81 )
continue;
F_95 ( V_85 , V_201 , V_10 ,
V_91 , V_42 ) ;
}
F_71 () ;
F_16 ( V_10 ) ;
}
static int F_105 ( struct V_84 * V_85 ,
struct V_41 * V_91 )
{
struct V_29 * V_30 = F_36 ( V_91 -> V_81 ) ;
struct V_47 * V_206 ;
T_1 * V_86 ;
int V_201 ;
bool V_17 ;
V_17 = F_106 ( V_85 , V_91 , V_52 ) ;
if ( ! V_17 )
return V_221 ;
if ( V_30 -> V_222 -> V_223 != F_44 )
return V_221 ;
F_41 ( V_30 , V_224 ) ;
F_42 ( V_30 , V_225 ,
V_85 -> V_99 + V_100 ) ;
V_201 = 0 ;
V_206 = (struct V_47 * ) V_85 -> V_89 ;
while ( F_33 ( V_201 , F_107 ( V_85 ) ,
V_206 -> V_76 ) ) {
F_103 ( V_85 , V_201 , V_91 ) ;
V_201 += V_52 ;
V_201 += F_34 ( V_206 -> V_76 ) ;
V_86 = V_85 -> V_89 + V_201 ;
V_206 = (struct V_47 * ) V_86 ;
}
F_102 ( V_85 ) ;
return V_226 ;
}
static void
F_108 ( struct V_9 * V_10 ,
struct V_41 * V_103 ,
struct V_227 * V_228 )
{
struct V_40 * V_45 ;
struct V_156 * V_229 ;
F_68 (neigh_node, &orig_node->neigh_list, list) {
V_229 = F_82 ( V_45 , V_103 ) ;
if ( ! V_229 )
continue;
F_109 ( V_228 , L_32 ,
V_45 -> V_31 ,
V_229 -> V_11 . V_164 ) ;
F_83 ( V_229 ) ;
}
}
static void F_110 ( struct V_29 * V_30 ,
struct V_227 * V_228 ,
struct V_41 * V_103 )
{
struct V_40 * V_45 ;
struct V_141 * V_142 = V_30 -> V_36 ;
int V_230 , V_231 ;
struct V_9 * V_10 ;
struct V_156 * V_229 ;
unsigned long V_232 ;
struct V_143 * V_144 ;
int V_233 = 0 ;
T_4 V_7 ;
F_109 ( V_228 , L_33 ,
L_34 , L_35 , L_36 , V_62 ,
L_37 , L_38 , L_39 ) ;
for ( V_7 = 0 ; V_7 < V_142 -> V_32 ; V_7 ++ ) {
V_144 = & V_142 -> V_149 [ V_7 ] ;
F_67 () ;
F_68 (orig_node, head, hash_entry) {
V_45 = F_85 ( V_10 ,
V_103 ) ;
if ( ! V_45 )
continue;
V_229 = F_82 ( V_45 ,
V_103 ) ;
if ( ! V_229 )
goto V_234;
if ( V_229 -> V_11 . V_164 == 0 )
goto V_234;
V_232 = V_71 - V_10 -> V_170 ;
V_230 = F_111 ( V_232 ) ;
V_231 = V_230 / 1000 ;
V_230 = V_230 % 1000 ;
F_109 ( V_228 , L_40 ,
V_10 -> V_63 , V_231 ,
V_230 , V_229 -> V_11 . V_164 ,
V_45 -> V_31 ,
V_45 -> V_91 -> V_64 -> V_96 ) ;
F_108 ( V_10 , V_103 ,
V_228 ) ;
F_112 ( V_228 , L_41 ) ;
V_233 ++ ;
V_234:
F_81 ( V_45 ) ;
if ( V_229 )
F_83 ( V_229 ) ;
}
F_71 () ;
}
if ( V_233 == 0 )
F_112 ( V_228 , L_42 ) ;
}
static void
F_113 ( struct V_227 * V_228 ,
struct V_202 * V_203 )
{
int V_235 , V_236 ;
V_235 = F_111 ( V_71 - V_203 -> V_170 ) / 1000 ;
V_236 = F_111 ( V_71 - V_203 -> V_170 ) % 1000 ;
F_109 ( V_228 , L_43 ,
V_203 -> V_91 -> V_64 -> V_96 ,
V_203 -> V_31 , V_235 , V_236 ) ;
}
static void F_114 ( struct V_29 * V_30 ,
struct V_227 * V_228 )
{
struct V_101 * V_64 = (struct V_101 * ) V_228 -> V_237 ;
struct V_202 * V_203 ;
struct V_41 * V_42 ;
int V_233 = 0 ;
F_109 ( V_228 , L_44 ,
L_45 , L_46 , L_35 ) ;
F_67 () ;
F_77 (hard_iface, &batadv_hardif_list, list) {
if ( V_42 -> V_81 != V_64 )
continue;
F_68 (hardif_neigh,
&hard_iface->neigh_list, list) {
F_113 ( V_228 , V_203 ) ;
V_233 ++ ;
}
}
F_71 () ;
if ( V_233 == 0 )
F_112 ( V_228 , L_42 ) ;
}
static int F_115 ( struct V_40 * V_238 ,
struct V_41 * V_239 ,
struct V_40 * V_240 ,
struct V_41 * V_241 )
{
struct V_156 * V_242 , * V_243 ;
T_1 V_244 , V_245 ;
int V_246 ;
V_242 = F_82 ( V_238 , V_239 ) ;
V_243 = F_82 ( V_240 , V_241 ) ;
if ( ! V_242 || ! V_243 ) {
V_246 = 0 ;
goto V_46;
}
V_244 = V_242 -> V_11 . V_164 ;
V_245 = V_243 -> V_11 . V_164 ;
V_246 = V_244 - V_245 ;
V_46:
if ( V_242 )
F_83 ( V_242 ) ;
if ( V_243 )
F_83 ( V_243 ) ;
return V_246 ;
}
static bool
F_116 ( struct V_40 * V_238 ,
struct V_41 * V_239 ,
struct V_40 * V_240 ,
struct V_41 * V_241 )
{
struct V_156 * V_242 , * V_243 ;
T_1 V_244 , V_245 ;
bool V_17 ;
V_242 = F_82 ( V_238 , V_239 ) ;
V_243 = F_82 ( V_240 , V_241 ) ;
if ( ! V_242 || ! V_243 ) {
V_17 = false ;
goto V_46;
}
V_244 = V_242 -> V_11 . V_164 ;
V_245 = V_243 -> V_11 . V_164 ;
V_17 = ( V_244 - V_245 ) > - V_247 ;
V_46:
if ( V_242 )
F_83 ( V_242 ) ;
if ( V_243 )
F_83 ( V_243 ) ;
return V_17 ;
}
int T_8 F_117 ( void )
{
int V_17 ;
V_17 = F_118 ( V_54 ,
F_105 ) ;
if ( V_17 < 0 )
goto V_46;
V_17 = F_119 ( & V_248 ) ;
if ( V_17 < 0 )
goto V_249;
goto V_46;
V_249:
F_120 ( V_54 ) ;
V_46:
return V_17 ;
}

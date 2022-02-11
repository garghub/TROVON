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
if ( ! V_15 )
goto V_22;
memcpy ( V_15 , V_10 -> V_11 . V_13 ,
( V_14 - 1 ) * sizeof( T_1 ) ) ;
F_4 ( V_10 -> V_11 . V_13 ) ;
V_10 -> V_11 . V_13 = V_15 ;
V_17 = 0 ;
V_22:
F_8 ( & V_10 -> V_11 . V_19 ) ;
return V_17 ;
}
static void
F_9 ( struct V_9 * V_10 ,
int V_14 , int V_23 )
{
T_3 V_24 ;
T_3 V_25 ;
void * V_15 ;
F_10 ( & V_10 -> V_11 . V_19 ) ;
V_24 = sizeof( unsigned long ) * V_20 ;
V_15 = F_7 ( V_14 , V_24 , V_21 ) ;
if ( ! V_15 )
V_15 = V_10 -> V_11 . V_12 ;
memmove ( V_15 , V_10 -> V_11 . V_12 , V_23 * V_24 ) ;
V_25 = ( V_23 + 1 ) * V_24 ;
memmove ( ( char * ) V_15 + V_23 * V_24 ,
( V_26 * ) V_10 -> V_11 . V_12 + V_25 ,
( V_14 - V_23 ) * V_24 ) ;
if ( V_10 -> V_11 . V_12 != V_15 ) {
F_4 ( V_10 -> V_11 . V_12 ) ;
V_10 -> V_11 . V_12 = V_15 ;
}
}
static void
F_11 ( struct V_9 * V_10 ,
int V_14 , int V_23 )
{
T_3 V_25 ;
void * V_15 ;
F_10 ( & V_10 -> V_11 . V_19 ) ;
V_15 = F_7 ( V_14 , sizeof( T_1 ) , V_21 ) ;
if ( ! V_15 )
V_15 = V_10 -> V_11 . V_13 ;
memmove ( V_15 , V_10 -> V_11 . V_13 ,
V_23 * sizeof( T_1 ) ) ;
V_25 = ( V_23 + 1 ) * sizeof( T_1 ) ;
memmove ( ( char * ) V_15 + V_23 * sizeof( T_1 ) ,
V_10 -> V_11 . V_13 + V_25 ,
( V_14 - V_23 ) * sizeof( T_1 ) ) ;
if ( V_10 -> V_11 . V_13 != V_15 ) {
F_4 ( V_10 -> V_11 . V_13 ) ;
V_10 -> V_11 . V_13 = V_15 ;
}
}
static int F_12 ( struct V_9 * V_10 ,
int V_14 , int V_23 )
{
F_6 ( & V_10 -> V_11 . V_19 ) ;
if ( V_14 == 0 ) {
F_4 ( V_10 -> V_11 . V_12 ) ;
F_4 ( V_10 -> V_11 . V_13 ) ;
V_10 -> V_11 . V_12 = NULL ;
V_10 -> V_11 . V_13 = NULL ;
} else {
F_9 ( V_10 , V_14 ,
V_23 ) ;
F_11 ( V_10 , V_14 ,
V_23 ) ;
}
F_8 ( & V_10 -> V_11 . V_19 ) ;
return 0 ;
}
static struct V_9 *
F_13 ( struct V_27 * V_28 , const T_1 * V_29 )
{
struct V_9 * V_10 ;
int V_30 , V_31 ;
V_10 = F_14 ( V_28 , V_29 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_15 ( V_28 , V_29 ) ;
if ( ! V_10 )
return NULL ;
F_16 ( & V_10 -> V_11 . V_19 ) ;
V_30 = V_28 -> V_32 * sizeof( unsigned long ) * V_20 ;
V_10 -> V_11 . V_12 = F_17 ( V_30 , V_21 ) ;
if ( ! V_10 -> V_11 . V_12 )
goto V_33;
V_30 = V_28 -> V_32 * sizeof( T_1 ) ;
V_10 -> V_11 . V_13 = F_17 ( V_30 , V_21 ) ;
if ( ! V_10 -> V_11 . V_13 )
goto V_33;
F_18 ( & V_10 -> V_34 ) ;
V_31 = F_19 ( V_28 -> V_35 , V_36 ,
V_37 , V_10 ,
& V_10 -> V_38 ) ;
if ( V_31 != 0 )
goto V_39;
return V_10 ;
V_39:
F_20 ( V_10 ) ;
V_33:
F_20 ( V_10 ) ;
return NULL ;
}
static struct V_40 *
F_21 ( struct V_41 * V_42 ,
const T_1 * V_43 ,
struct V_9 * V_10 ,
struct V_9 * V_44 )
{
struct V_40 * V_45 ;
V_45 = F_22 ( V_10 ,
V_42 , V_43 ) ;
if ( ! V_45 )
goto V_46;
V_45 -> V_10 = V_44 ;
V_46:
return V_45 ;
}
static int F_23 ( struct V_41 * V_42 )
{
struct V_47 * V_47 ;
unsigned char * V_48 ;
T_4 V_49 ;
F_24 ( & V_49 , sizeof( V_49 ) ) ;
F_25 ( & V_42 -> V_11 . V_50 , V_49 ) ;
V_42 -> V_11 . V_51 = V_52 ;
V_48 = F_26 ( V_42 -> V_11 . V_51 , V_21 ) ;
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
static void F_27 ( struct V_41 * V_42 )
{
F_4 ( V_42 -> V_11 . V_48 ) ;
V_42 -> V_11 . V_48 = NULL ;
}
static void F_28 ( struct V_41 * V_42 )
{
struct V_47 * V_47 ;
unsigned char * V_48 = V_42 -> V_11 . V_48 ;
V_47 = (struct V_47 * ) V_48 ;
F_29 ( V_47 -> V_63 ,
V_42 -> V_64 -> V_65 ) ;
F_29 ( V_47 -> V_66 ,
V_42 -> V_64 -> V_65 ) ;
}
static void
F_30 ( struct V_41 * V_42 )
{
struct V_47 * V_47 ;
unsigned char * V_48 = V_42 -> V_11 . V_48 ;
V_47 = (struct V_47 * ) V_48 ;
V_47 -> V_57 = V_67 ;
}
static unsigned long
F_31 ( const struct V_27 * V_28 )
{
unsigned int V_68 ;
V_68 = F_32 ( & V_28 -> V_69 ) - V_70 ;
V_68 += F_33 () % ( 2 * V_70 ) ;
return V_71 + F_34 ( V_68 ) ;
}
static unsigned long F_35 ( void )
{
return V_71 + F_34 ( F_33 () % ( V_70 / 2 ) ) ;
}
static T_1 F_36 ( T_1 V_61 , const struct V_27 * V_28 )
{
int V_72 = F_32 ( & V_28 -> V_72 ) ;
int V_73 ;
V_73 = V_61 * ( V_62 - V_72 ) ;
V_73 /= V_62 ;
return V_73 ;
}
static bool F_37 ( int V_74 , int V_75 ,
T_5 V_76 )
{
int V_77 = 0 ;
V_77 += V_74 + V_52 ;
V_77 += F_38 ( V_76 ) ;
return ( V_77 <= V_75 ) &&
( V_77 <= V_78 ) ;
}
static void F_39 ( struct V_79 * V_80 ,
struct V_41 * V_42 )
{
struct V_27 * V_28 = F_40 ( V_42 -> V_81 ) ;
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
while ( F_37 ( V_74 , V_80 -> V_75 ,
V_47 -> V_76 ) ) {
if ( V_80 -> V_90 & F_41 ( V_83 ) &&
V_80 -> V_91 == V_42 )
V_47 -> V_58 |= V_92 ;
else
V_47 -> V_58 &= ~ V_92 ;
if ( V_83 > 0 || ! V_80 -> V_93 )
V_82 = L_1 ;
else
V_82 = L_2 ;
F_42 ( V_94 , V_28 ,
L_3 ,
V_82 , ( V_83 > 0 ? L_4 : L_5 ) ,
V_47 -> V_63 ,
F_43 ( V_47 -> V_95 ) ,
V_47 -> V_61 , V_47 -> V_57 ,
( ( V_47 -> V_58 & V_92 ) ?
L_6 : L_7 ) ,
V_42 -> V_64 -> V_96 ,
V_42 -> V_64 -> V_65 ) ;
V_74 += V_52 ;
V_74 += F_38 ( V_47 -> V_76 ) ;
V_83 ++ ;
V_86 = V_80 -> V_85 -> V_89 + V_74 ;
V_47 = (struct V_47 * ) V_86 ;
}
V_85 = F_44 ( V_80 -> V_85 , V_21 ) ;
if ( V_85 ) {
F_45 ( V_28 , V_97 ) ;
F_46 ( V_28 , V_98 ,
V_85 -> V_99 + V_100 ) ;
F_47 ( V_85 , V_42 ) ;
}
}
static void F_48 ( struct V_79 * V_80 )
{
struct V_101 * V_81 ;
if ( ! V_80 -> V_91 ) {
F_49 ( L_8 ) ;
return;
}
V_81 = V_80 -> V_91 -> V_81 ;
if ( F_50 ( ! V_80 -> V_102 ) )
return;
if ( F_50 ( V_80 -> V_102 -> V_81 != V_81 ) )
return;
if ( V_80 -> V_91 -> V_87 != V_88 )
return;
F_39 ( V_80 , V_80 -> V_102 ) ;
}
static bool
F_51 ( const struct V_47 * V_103 ,
struct V_27 * V_28 ,
int V_75 , unsigned long V_104 ,
bool V_105 ,
const struct V_41 * V_91 ,
const struct V_41 * V_102 ,
const struct V_79 * V_80 )
{
struct V_47 * V_47 ;
int V_106 = V_80 -> V_75 + V_75 ;
struct V_41 * V_107 = NULL ;
bool V_108 = false ;
unsigned long V_109 ;
V_47 = (struct V_47 * ) V_80 -> V_85 -> V_89 ;
V_109 = V_104 ;
V_109 += F_34 ( V_110 ) ;
if ( ! F_52 ( V_104 , V_80 -> V_104 ) ||
! F_53 ( V_109 , V_80 -> V_104 ) )
return false ;
if ( V_106 > V_78 )
return false ;
if ( V_80 -> V_102 != V_102 )
return false ;
V_107 = F_54 ( V_28 ) ;
if ( ! V_107 )
return false ;
if ( ! V_105 &&
! ( V_47 -> V_58 & V_92 ) &&
V_47 -> V_57 != 1 &&
( ! V_80 -> V_93 ||
V_80 -> V_91 == V_107 ) ) {
V_108 = true ;
goto V_46;
}
if ( V_105 &&
V_103 -> V_57 == 1 &&
V_80 -> V_91 == V_91 &&
( V_47 -> V_58 & V_92 ||
( V_80 -> V_93 &&
V_80 -> V_91 != V_107 ) ) ) {
V_108 = true ;
goto V_46;
}
V_46:
if ( V_107 )
F_55 ( V_107 ) ;
return V_108 ;
}
static void F_56 ( const unsigned char * V_111 ,
int V_75 , unsigned long V_104 ,
bool V_112 ,
struct V_41 * V_91 ,
struct V_41 * V_102 ,
int V_113 )
{
struct V_27 * V_28 = F_40 ( V_91 -> V_81 ) ;
struct V_79 * V_114 ;
unsigned char * V_115 ;
unsigned int V_116 ;
T_7 * V_117 = V_113 ? NULL : & V_28 -> V_118 ;
V_114 = F_57 ( V_91 , V_102 ,
V_117 , V_28 ) ;
if ( ! V_114 )
return;
if ( F_32 ( & V_28 -> V_119 ) &&
V_75 < V_78 )
V_116 = V_78 ;
else
V_116 = V_75 ;
V_116 += V_100 ;
V_114 -> V_85 = F_58 ( NULL , V_116 ) ;
if ( ! V_114 -> V_85 ) {
F_59 ( V_114 ) ;
return;
}
V_114 -> V_85 -> V_120 = V_121 ;
F_60 ( V_114 -> V_85 , V_100 ) ;
V_115 = F_61 ( V_114 -> V_85 , V_75 ) ;
V_114 -> V_75 = V_75 ;
memcpy ( V_115 , V_111 , V_75 ) ;
V_114 -> V_93 = V_113 ;
V_114 -> V_90 = V_59 ;
V_114 -> V_104 = V_104 ;
if ( V_112 )
V_114 -> V_90 |= 1 ;
F_6 ( & V_28 -> V_122 ) ;
F_62 ( & V_114 -> V_123 , & V_28 -> V_124 ) ;
F_8 ( & V_28 -> V_122 ) ;
F_63 ( & V_114 -> V_125 ,
V_126 ) ;
F_64 ( V_127 ,
& V_114 -> V_125 ,
V_104 - V_71 ) ;
}
static void F_65 ( struct V_79 * V_114 ,
const unsigned char * V_111 ,
int V_75 , bool V_112 )
{
unsigned char * V_115 ;
unsigned long V_128 ;
V_115 = F_61 ( V_114 -> V_85 , V_75 ) ;
memcpy ( V_115 , V_111 , V_75 ) ;
V_114 -> V_75 += V_75 ;
V_114 -> V_129 ++ ;
if ( V_112 ) {
V_128 = F_41 ( V_114 -> V_129 ) ;
V_114 -> V_90 |= V_128 ;
}
}
static void F_66 ( struct V_27 * V_28 ,
unsigned char * V_111 ,
int V_75 ,
struct V_41 * V_91 ,
struct V_41 * V_102 ,
int V_113 , unsigned long V_104 )
{
struct V_79 * V_114 = NULL ;
struct V_79 * V_130 = NULL ;
struct V_47 * V_47 ;
bool V_112 ;
unsigned long V_131 ;
V_47 = (struct V_47 * ) V_111 ;
V_112 = ! ! ( V_47 -> V_58 & V_92 ) ;
V_131 = F_34 ( V_110 ) ;
F_6 ( & V_28 -> V_122 ) ;
if ( F_32 ( & V_28 -> V_119 ) && ! V_113 ) {
F_67 (forw_packet_pos,
&bat_priv->forw_bat_list, list) {
if ( F_51 ( V_47 ,
V_28 , V_75 ,
V_104 , V_112 ,
V_91 ,
V_102 ,
V_130 ) ) {
V_114 = V_130 ;
break;
}
}
}
if ( ! V_114 ) {
F_8 ( & V_28 -> V_122 ) ;
if ( ! V_113 && F_32 ( & V_28 -> V_119 ) )
V_104 += V_131 ;
F_56 ( V_111 , V_75 ,
V_104 , V_112 ,
V_91 , V_102 ,
V_113 ) ;
} else {
F_65 ( V_114 , V_111 ,
V_75 , V_112 ) ;
F_8 ( & V_28 -> V_122 ) ;
}
}
static void F_68 ( struct V_9 * V_10 ,
const struct V_132 * V_132 ,
struct V_47 * V_47 ,
bool V_133 ,
bool V_134 ,
struct V_41 * V_91 ,
struct V_41 * V_102 )
{
struct V_27 * V_28 = F_40 ( V_91 -> V_81 ) ;
T_2 V_76 ;
if ( V_47 -> V_57 <= 1 ) {
F_42 ( V_94 , V_28 , L_9 ) ;
return;
}
if ( ! V_134 ) {
if ( V_133 )
V_47 -> V_58 |= V_135 ;
else
return;
}
V_76 = F_38 ( V_47 -> V_76 ) ;
V_47 -> V_57 -- ;
F_29 ( V_47 -> V_66 , V_132 -> V_136 ) ;
V_47 -> V_61 = F_36 ( V_47 -> V_61 ,
V_28 ) ;
F_42 ( V_94 , V_28 ,
L_10 ,
V_47 -> V_61 , V_47 -> V_57 ) ;
if ( V_133 )
V_47 -> V_58 |= V_92 ;
else
V_47 -> V_58 &= ~ V_92 ;
F_66 ( V_28 , ( unsigned char * ) V_47 ,
V_52 + V_76 ,
V_91 , V_102 , 0 ,
F_35 () ) ;
}
static void
F_69 ( struct V_41 * V_42 )
{
struct V_27 * V_28 = F_40 ( V_42 -> V_81 ) ;
struct V_137 * V_138 = V_28 -> V_35 ;
struct V_139 * V_140 ;
struct V_9 * V_10 ;
unsigned long * V_141 ;
T_4 V_7 ;
T_3 V_142 ;
T_1 * V_143 ;
int V_144 ;
for ( V_7 = 0 ; V_7 < V_138 -> V_30 ; V_7 ++ ) {
V_140 = & V_138 -> V_145 [ V_7 ] ;
F_70 () ;
F_71 (orig_node, head, hash_entry) {
F_6 ( & V_10 -> V_11 . V_19 ) ;
V_142 = V_42 -> V_144 * V_20 ;
V_141 = & V_10 -> V_11 . V_12 [ V_142 ] ;
F_72 ( V_28 , V_141 , 1 , 0 ) ;
V_144 = V_42 -> V_144 ;
V_143 = & V_10 -> V_11 . V_13 [ V_144 ] ;
* V_143 = F_73 ( V_141 , V_146 ) ;
F_8 ( & V_10 -> V_11 . V_19 ) ;
}
F_74 () ;
}
}
static void F_75 ( struct V_41 * V_42 )
{
struct V_27 * V_28 = F_40 ( V_42 -> V_81 ) ;
unsigned char * * V_48 = & V_42 -> V_11 . V_48 ;
struct V_47 * V_47 ;
struct V_41 * V_107 , * V_147 ;
int * V_51 = & V_42 -> V_11 . V_51 ;
T_4 V_95 ;
T_2 V_76 = 0 ;
unsigned long V_104 ;
if ( ( V_42 -> V_87 == V_148 ) ||
( V_42 -> V_87 == V_149 ) )
return;
if ( V_42 -> V_87 == V_150 )
V_42 -> V_87 = V_88 ;
V_107 = F_54 ( V_28 ) ;
if ( V_42 == V_107 ) {
F_76 ( V_28 ) ;
V_76 = F_77 ( V_28 , V_48 ,
V_51 ,
V_52 ) ;
}
V_47 = (struct V_47 * ) ( * V_48 ) ;
V_47 -> V_76 = F_78 ( V_76 ) ;
V_95 = ( T_4 ) F_32 ( & V_42 -> V_11 . V_50 ) ;
V_47 -> V_95 = F_79 ( V_95 ) ;
F_80 ( & V_42 -> V_11 . V_50 ) ;
F_69 ( V_42 ) ;
V_104 = F_31 ( V_28 ) ;
if ( V_42 != V_107 ) {
F_66 ( V_28 , * V_48 , * V_51 ,
V_42 , V_42 , 1 , V_104 ) ;
goto V_46;
}
F_70 () ;
F_81 (tmp_hard_iface, &batadv_hardif_list, list) {
if ( V_147 -> V_81 != V_42 -> V_81 )
continue;
if ( ! F_82 ( & V_147 -> V_34 ) )
continue;
F_66 ( V_28 , * V_48 ,
* V_51 , V_42 ,
V_147 , 1 , V_104 ) ;
F_55 ( V_147 ) ;
}
F_74 () ;
V_46:
if ( V_107 )
F_55 ( V_107 ) ;
}
static void
F_83 ( struct V_27 * V_28 ,
struct V_9 * V_10 ,
struct V_151 * V_152 ,
const struct V_132 * V_132 ,
const struct V_47 * V_47 ,
struct V_41 * V_91 ,
struct V_41 * V_102 ,
enum V_153 V_154 )
{
struct V_155 * V_156 = NULL ;
struct V_155 * V_157 = NULL ;
struct V_40 * V_45 = NULL ;
struct V_40 * V_158 = NULL ;
struct V_40 * V_159 = NULL ;
struct V_9 * V_160 ;
int V_144 ;
T_1 V_161 , V_162 ;
T_1 * V_43 ;
T_1 V_163 ;
F_42 ( V_94 , V_28 ,
L_11 ) ;
F_70 () ;
F_71 (tmp_neigh_node,
&orig_node->neigh_list, list) {
V_43 = V_158 -> V_29 ;
if ( F_84 ( V_43 , V_132 -> V_136 ) &&
V_158 -> V_91 == V_91 &&
F_82 ( & V_158 -> V_34 ) ) {
if ( F_85 ( V_45 , L_12 ) )
F_86 ( V_45 ) ;
V_45 = V_158 ;
continue;
}
if ( V_154 != V_164 )
continue;
V_156 = F_87 ( V_158 ,
V_102 ) ;
if ( ! V_156 )
continue;
F_6 ( & V_158 -> V_165 ) ;
F_1 ( V_156 -> V_11 . V_166 ,
& V_156 -> V_11 . V_167 , 0 ) ;
V_163 = F_2 ( V_156 -> V_11 . V_166 ) ;
V_156 -> V_11 . V_163 = V_163 ;
F_8 ( & V_158 -> V_165 ) ;
F_88 ( V_156 ) ;
V_156 = NULL ;
}
if ( ! V_45 ) {
struct V_9 * V_168 ;
V_168 = F_13 ( V_28 , V_132 -> V_136 ) ;
if ( ! V_168 )
goto V_22;
V_45 = F_21 ( V_91 ,
V_132 -> V_136 ,
V_10 , V_168 ) ;
F_20 ( V_168 ) ;
if ( ! V_45 )
goto V_22;
} else {
F_42 ( V_94 , V_28 ,
L_13 ) ;
}
F_74 () ;
V_156 = F_89 ( V_45 , V_102 ) ;
if ( ! V_156 )
goto V_46;
V_45 -> V_169 = V_71 ;
F_6 ( & V_45 -> V_165 ) ;
F_1 ( V_156 -> V_11 . V_166 ,
& V_156 -> V_11 . V_167 ,
V_47 -> V_61 ) ;
V_163 = F_2 ( V_156 -> V_11 . V_166 ) ;
V_156 -> V_11 . V_163 = V_163 ;
F_8 ( & V_45 -> V_165 ) ;
if ( V_154 == V_164 ) {
V_152 -> V_170 = V_47 -> V_57 ;
V_156 -> V_170 = V_47 -> V_57 ;
}
V_159 = F_90 ( V_10 , V_102 ) ;
if ( V_159 == V_45 )
goto V_46;
if ( V_159 ) {
V_157 = F_87 ( V_159 , V_102 ) ;
if ( ! V_157 )
goto V_46;
if ( V_157 -> V_11 . V_163 > V_156 -> V_11 . V_163 )
goto V_46;
}
if ( V_157 &&
V_156 -> V_11 . V_163 == V_157 -> V_11 . V_163 ) {
V_160 = V_159 -> V_10 ;
F_6 ( & V_160 -> V_11 . V_19 ) ;
V_144 = V_159 -> V_91 -> V_144 ;
V_161 = V_160 -> V_11 . V_13 [ V_144 ] ;
F_8 ( & V_160 -> V_11 . V_19 ) ;
V_160 = V_45 -> V_10 ;
F_6 ( & V_160 -> V_11 . V_19 ) ;
V_144 = V_45 -> V_91 -> V_144 ;
V_162 = V_160 -> V_11 . V_13 [ V_144 ] ;
F_8 ( & V_160 -> V_11 . V_19 ) ;
if ( V_161 >= V_162 )
goto V_46;
}
F_91 ( V_28 , V_10 , V_102 , V_45 ) ;
goto V_46;
V_22:
F_74 () ;
V_46:
if ( V_45 )
F_86 ( V_45 ) ;
if ( V_159 )
F_86 ( V_159 ) ;
if ( V_156 )
F_88 ( V_156 ) ;
if ( V_157 )
F_88 ( V_157 ) ;
}
static bool F_92 ( struct V_9 * V_10 ,
struct V_9 * V_171 ,
struct V_47 * V_47 ,
struct V_41 * V_91 ,
struct V_41 * V_102 )
{
struct V_27 * V_28 = F_40 ( V_91 -> V_81 ) ;
struct V_40 * V_45 = NULL , * V_158 ;
struct V_155 * V_156 ;
T_1 V_172 ;
T_1 V_173 , V_174 , V_175 , V_176 ;
unsigned int V_177 , V_178 ;
int V_144 ;
unsigned int V_179 , V_180 ;
unsigned int V_181 ;
unsigned int V_182 ;
bool V_17 = false ;
F_70 () ;
F_71 (tmp_neigh_node,
&orig_neigh_node->neigh_list, list) {
if ( ! F_84 ( V_158 -> V_29 ,
V_171 -> V_63 ) )
continue;
if ( V_158 -> V_91 != V_91 )
continue;
if ( ! F_82 ( & V_158 -> V_34 ) )
continue;
V_45 = V_158 ;
break;
}
F_74 () ;
if ( ! V_45 )
V_45 = F_21 ( V_91 ,
V_171 -> V_63 ,
V_171 ,
V_171 ) ;
if ( ! V_45 )
goto V_46;
if ( V_10 == V_171 )
V_45 -> V_169 = V_71 ;
V_10 -> V_169 = V_71 ;
F_6 ( & V_10 -> V_11 . V_19 ) ;
V_144 = V_91 -> V_144 ;
V_173 = V_171 -> V_11 . V_13 [ V_144 ] ;
V_156 = F_89 ( V_45 , V_102 ) ;
if ( V_156 ) {
V_174 = V_156 -> V_11 . V_183 ;
F_88 ( V_156 ) ;
} else {
V_174 = 0 ;
}
F_8 ( & V_10 -> V_11 . V_19 ) ;
if ( V_173 > V_174 )
V_172 = V_174 ;
else
V_172 = V_173 ;
if ( V_172 < V_184 ||
V_174 < V_185 )
V_176 = 0 ;
else
V_176 = ( V_62 * V_172 ) / V_174 ;
V_175 = V_146 - V_174 ;
V_177 = V_175 * V_175 * V_175 ;
V_178 = V_146 *
V_146 *
V_146 ;
V_180 = V_62 * V_177 ;
V_180 /= V_178 ;
V_179 = V_62 - V_180 ;
V_182 = V_62 ;
if ( V_102 && ( V_91 == V_102 ) &&
F_93 ( V_102 -> V_64 ) )
V_182 = F_36 ( V_62 ,
V_28 ) ;
V_181 = V_47 -> V_61 *
V_176 *
V_179 *
V_182 ;
V_181 /= V_62 *
V_62 *
V_62 ;
V_47 -> V_61 = V_181 ;
F_42 ( V_94 , V_28 ,
L_14 ,
V_10 -> V_63 , V_171 -> V_63 , V_172 ,
V_174 , V_176 , V_179 , V_182 ,
V_47 -> V_61 , V_91 -> V_64 -> V_96 ,
V_102 ? V_102 -> V_64 -> V_96 : L_15 ) ;
if ( V_47 -> V_61 >= V_186 )
V_17 = true ;
V_46:
if ( V_45 )
F_86 ( V_45 ) ;
return V_17 ;
}
static enum V_153
F_94 ( const struct V_132 * V_132 ,
const struct V_47 * V_47 ,
const struct V_41 * V_91 ,
struct V_41 * V_102 )
{
struct V_27 * V_28 = F_40 ( V_91 -> V_81 ) ;
struct V_9 * V_10 ;
struct V_151 * V_152 = NULL ;
struct V_40 * V_45 ;
struct V_155 * V_156 ;
bool V_187 ;
T_8 V_188 ;
bool V_189 = false ;
int V_190 ;
enum V_153 V_17 = V_164 ;
T_4 V_95 = F_43 ( V_47 -> V_95 ) ;
T_1 * V_43 ;
T_1 V_191 ;
unsigned long * V_192 ;
V_10 = F_13 ( V_28 , V_47 -> V_63 ) ;
if ( ! V_10 )
return V_164 ;
V_152 = F_95 ( V_10 , V_102 ) ;
if ( F_50 ( ! V_152 ) ) {
F_20 ( V_10 ) ;
return 0 ;
}
F_6 ( & V_10 -> V_11 . V_19 ) ;
V_188 = V_95 - V_152 -> V_193 ;
if ( ! F_96 ( & V_10 -> V_194 ) &&
F_97 ( V_28 , V_188 ,
V_146 ,
& V_152 -> V_195 , NULL ) ) {
V_17 = V_196 ;
goto V_46;
}
F_70 () ;
F_71 (neigh_node, &orig_node->neigh_list, list) {
V_156 = F_89 ( V_45 ,
V_102 ) ;
if ( ! V_156 )
continue;
V_43 = V_45 -> V_29 ;
V_187 = F_98 ( V_156 -> V_11 . V_197 ,
V_152 -> V_193 ,
V_95 ) ;
if ( F_84 ( V_43 , V_132 -> V_136 ) &&
V_45 -> V_91 == V_91 ) {
V_190 = 1 ;
if ( V_187 )
V_17 = V_198 ;
} else {
V_190 = 0 ;
if ( V_187 && ( V_17 != V_198 ) )
V_17 = V_199 ;
}
V_192 = V_156 -> V_11 . V_197 ;
V_189 |= F_72 ( V_28 , V_192 ,
V_188 , V_190 ) ;
V_191 = F_73 ( V_192 ,
V_146 ) ;
V_156 -> V_11 . V_183 = V_191 ;
F_88 ( V_156 ) ;
}
F_74 () ;
if ( V_189 ) {
F_42 ( V_94 , V_28 ,
L_16 ,
V_102 ? V_102 -> V_64 -> V_96 : L_15 ,
V_152 -> V_193 , V_95 ) ;
V_152 -> V_193 = V_95 ;
}
V_46:
F_8 ( & V_10 -> V_11 . V_19 ) ;
F_20 ( V_10 ) ;
F_99 ( V_152 ) ;
return V_17 ;
}
static void
F_100 ( const struct V_84 * V_85 , int V_200 ,
struct V_9 * V_10 ,
struct V_41 * V_91 ,
struct V_41 * V_102 )
{
struct V_27 * V_28 = F_40 ( V_91 -> V_81 ) ;
struct V_201 * V_202 = NULL ;
struct V_40 * V_159 = NULL ;
struct V_40 * V_203 = NULL ;
struct V_9 * V_171 ;
struct V_151 * V_152 ;
struct V_40 * V_204 = NULL ;
struct V_155 * V_157 = NULL ;
struct V_47 * V_205 ;
enum V_153 V_154 ;
bool V_134 = false ;
bool V_133 = false ;
bool V_206 , V_207 ;
struct V_84 * V_208 ;
struct V_132 * V_132 ;
T_1 * V_66 ;
bool V_209 ;
V_208 = F_101 ( V_85 , V_21 ) ;
if ( ! V_208 )
return;
V_132 = F_102 ( V_208 ) ;
V_205 = (struct V_47 * ) ( V_208 -> V_89 + V_200 ) ;
V_154 = F_94 ( V_132 , V_205 ,
V_91 , V_102 ) ;
if ( F_84 ( V_132 -> V_136 , V_205 -> V_63 ) )
V_133 = true ;
if ( V_154 == V_196 ) {
F_42 ( V_94 , V_28 ,
L_17 ,
V_132 -> V_136 ) ;
goto V_46;
}
if ( V_205 -> V_61 == 0 ) {
F_42 ( V_94 , V_28 ,
L_18 ) ;
goto V_46;
}
if ( V_133 ) {
V_202 = F_103 ( V_91 ,
V_132 -> V_136 ) ;
if ( V_202 )
V_202 -> V_169 = V_71 ;
}
V_159 = F_90 ( V_10 , V_102 ) ;
if ( V_159 ) {
V_203 = F_90 ( V_159 -> V_10 ,
V_102 ) ;
V_157 = F_87 ( V_159 , V_102 ) ;
}
if ( ( V_157 && V_157 -> V_11 . V_163 != 0 ) &&
( F_84 ( V_159 -> V_29 , V_132 -> V_136 ) ) )
V_134 = true ;
V_66 = V_205 -> V_66 ;
if ( V_159 && V_203 &&
( F_84 ( V_159 -> V_29 , V_66 ) ) &&
! ( F_84 ( V_205 -> V_63 , V_66 ) ) &&
( F_84 ( V_159 -> V_29 , V_203 -> V_29 ) ) ) {
F_42 ( V_94 , V_28 ,
L_19 ,
V_132 -> V_136 ) ;
goto V_46;
}
if ( V_102 == V_210 )
F_104 ( V_28 , V_205 , V_10 ) ;
if ( V_133 )
V_171 = V_10 ;
else
V_171 = F_13 ( V_28 ,
V_132 -> V_136 ) ;
if ( ! V_171 )
goto V_46;
F_105 ( V_28 , V_10 , V_171 ,
V_205 , V_133 ) ;
V_204 = F_90 ( V_171 ,
V_102 ) ;
if ( ! V_133 && ( ! V_204 ) ) {
F_42 ( V_94 , V_28 ,
L_20 ) ;
goto V_211;
}
V_209 = F_92 ( V_10 , V_171 ,
V_205 , V_91 ,
V_102 ) ;
V_152 = F_95 ( V_10 , V_102 ) ;
if ( ! V_152 )
goto V_211;
V_206 = V_152 -> V_193 == F_43 ( V_205 -> V_95 ) ;
V_207 = ( V_152 -> V_170 - 3 ) <= V_205 -> V_57 ;
if ( V_209 && ( ( V_154 == V_164 ) ||
( V_206 && V_207 ) ) ) {
F_83 ( V_28 , V_10 ,
V_152 , V_132 ,
V_205 , V_91 ,
V_102 , V_154 ) ;
}
F_99 ( V_152 ) ;
if ( V_102 == V_210 )
goto V_211;
if ( V_133 ) {
if ( ( V_205 -> V_57 <= 2 ) &&
( V_91 != V_102 ) ) {
F_42 ( V_94 , V_28 ,
L_21 ) ;
goto V_211;
}
F_68 ( V_10 , V_132 , V_205 ,
V_133 ,
V_134 , V_91 ,
V_102 ) ;
F_42 ( V_94 , V_28 ,
L_22 ) ;
goto V_211;
}
if ( ! V_209 ) {
F_42 ( V_94 , V_28 ,
L_23 ) ;
goto V_211;
}
if ( V_154 == V_198 ) {
F_42 ( V_94 , V_28 ,
L_24 ) ;
goto V_211;
}
F_42 ( V_94 , V_28 ,
L_25 ) ;
F_68 ( V_10 , V_132 , V_205 ,
V_133 , V_134 ,
V_91 , V_102 ) ;
V_211:
if ( ( V_171 ) && ( ! V_133 ) )
F_20 ( V_171 ) ;
V_46:
if ( V_157 )
F_88 ( V_157 ) ;
if ( V_159 )
F_86 ( V_159 ) ;
if ( V_203 )
F_86 ( V_203 ) ;
if ( V_204 )
F_86 ( V_204 ) ;
if ( V_202 )
F_106 ( V_202 ) ;
F_107 ( V_208 ) ;
}
static void F_108 ( const struct V_84 * V_85 , int V_200 ,
struct V_41 * V_91 )
{
struct V_27 * V_28 = F_40 ( V_91 -> V_81 ) ;
struct V_9 * V_171 , * V_10 ;
struct V_41 * V_42 ;
struct V_47 * V_205 ;
T_4 V_212 ;
bool V_213 ;
struct V_132 * V_132 ;
bool V_214 = false ;
bool V_215 = false ;
bool V_216 = false ;
V_205 = (struct V_47 * ) ( V_85 -> V_89 + V_200 ) ;
V_132 = F_102 ( V_85 ) ;
if ( V_205 -> V_53 != V_54 )
return;
V_212 = F_32 ( & V_91 -> V_11 . V_50 ) ;
if ( V_205 -> V_58 & V_92 )
V_213 = true ;
else
V_213 = false ;
F_42 ( V_94 , V_28 ,
L_26 ,
V_132 -> V_136 , V_91 -> V_64 -> V_96 ,
V_91 -> V_64 -> V_65 , V_205 -> V_63 ,
V_205 -> V_66 , F_43 ( V_205 -> V_95 ) ,
V_205 -> V_61 , V_205 -> V_57 ,
V_205 -> V_55 , V_213 ) ;
F_70 () ;
F_81 (hard_iface, &batadv_hardif_list, list) {
if ( V_42 -> V_87 != V_88 )
continue;
if ( V_42 -> V_81 != V_91 -> V_81 )
continue;
if ( F_84 ( V_132 -> V_136 ,
V_42 -> V_64 -> V_65 ) )
V_215 = true ;
if ( F_84 ( V_205 -> V_63 ,
V_42 -> V_64 -> V_65 ) )
V_216 = true ;
if ( F_84 ( V_205 -> V_66 ,
V_42 -> V_64 -> V_65 ) )
V_214 = true ;
}
F_74 () ;
if ( V_215 ) {
F_42 ( V_94 , V_28 ,
L_27 ,
V_132 -> V_136 ) ;
return;
}
if ( V_216 ) {
unsigned long * V_141 ;
int V_217 ;
T_8 V_218 ;
T_6 V_144 ;
T_1 * V_219 ;
V_171 = F_13 ( V_28 ,
V_132 -> V_136 ) ;
if ( ! V_171 )
return;
if ( V_213 &&
F_84 ( V_91 -> V_64 -> V_65 ,
V_205 -> V_63 ) ) {
V_144 = V_91 -> V_144 ;
V_217 = V_144 * V_20 ;
F_6 ( & V_171 -> V_11 . V_19 ) ;
V_141 = & V_171 -> V_11 . V_12 [ V_217 ] ;
V_218 = V_212 - 2 ;
V_218 -= F_43 ( V_205 -> V_95 ) ;
F_109 ( V_141 , V_218 ) ;
V_219 = & V_171 -> V_11 . V_13 [ V_144 ] ;
* V_219 = F_73 ( V_141 ,
V_146 ) ;
F_8 ( & V_171 -> V_11 . V_19 ) ;
}
F_42 ( V_94 , V_28 ,
L_28 ) ;
F_20 ( V_171 ) ;
return;
}
if ( V_214 ) {
F_42 ( V_94 , V_28 ,
L_29 ,
V_132 -> V_136 ) ;
return;
}
if ( V_205 -> V_58 & V_135 ) {
F_42 ( V_94 , V_28 ,
L_30 ,
V_132 -> V_136 ) ;
return;
}
V_10 = F_13 ( V_28 , V_205 -> V_63 ) ;
if ( ! V_10 )
return;
F_100 ( V_85 , V_200 , V_10 ,
V_91 , V_210 ) ;
F_70 () ;
F_81 (hard_iface, &batadv_hardif_list, list) {
if ( V_42 -> V_87 != V_88 )
continue;
if ( V_42 -> V_81 != V_28 -> V_81 )
continue;
if ( ! F_82 ( & V_42 -> V_34 ) )
continue;
F_100 ( V_85 , V_200 , V_10 ,
V_91 , V_42 ) ;
F_55 ( V_42 ) ;
}
F_74 () ;
F_20 ( V_10 ) ;
}
static void V_126 ( struct V_220 * V_221 )
{
struct V_125 * V_125 ;
struct V_79 * V_80 ;
struct V_27 * V_28 ;
V_125 = F_110 ( V_221 ) ;
V_80 = F_111 ( V_125 , struct V_79 ,
V_125 ) ;
V_28 = F_40 ( V_80 -> V_91 -> V_81 ) ;
F_6 ( & V_28 -> V_122 ) ;
F_112 ( & V_80 -> V_123 ) ;
F_8 ( & V_28 -> V_122 ) ;
if ( F_32 ( & V_28 -> V_222 ) == V_223 )
goto V_46;
F_48 ( V_80 ) ;
if ( V_80 -> V_93 &&
V_80 -> V_91 == V_80 -> V_102 )
F_75 ( V_80 -> V_91 ) ;
V_46:
F_59 ( V_80 ) ;
}
static int F_113 ( struct V_84 * V_85 ,
struct V_41 * V_91 )
{
struct V_27 * V_28 = F_40 ( V_91 -> V_81 ) ;
struct V_47 * V_205 ;
T_1 * V_86 ;
int V_200 ;
bool V_17 ;
V_17 = F_114 ( V_85 , V_91 , V_52 ) ;
if ( ! V_17 )
return V_224 ;
if ( V_28 -> V_225 -> V_226 . V_227 != F_23 )
return V_224 ;
F_45 ( V_28 , V_228 ) ;
F_46 ( V_28 , V_229 ,
V_85 -> V_99 + V_100 ) ;
V_200 = 0 ;
V_205 = (struct V_47 * ) V_85 -> V_89 ;
while ( F_37 ( V_200 , F_115 ( V_85 ) ,
V_205 -> V_76 ) ) {
F_108 ( V_85 , V_200 , V_91 ) ;
V_200 += V_52 ;
V_200 += F_38 ( V_205 -> V_76 ) ;
V_86 = V_85 -> V_89 + V_200 ;
V_205 = (struct V_47 * ) V_86 ;
}
F_107 ( V_85 ) ;
return V_230 ;
}
static void
F_116 ( struct V_9 * V_10 ,
struct V_41 * V_102 ,
struct V_231 * V_232 )
{
struct V_40 * V_45 ;
struct V_155 * V_233 ;
F_71 (neigh_node, &orig_node->neigh_list, list) {
V_233 = F_87 ( V_45 , V_102 ) ;
if ( ! V_233 )
continue;
F_117 ( V_232 , L_31 ,
V_45 -> V_29 ,
V_233 -> V_11 . V_163 ) ;
F_88 ( V_233 ) ;
}
}
static void F_118 ( struct V_27 * V_28 ,
struct V_231 * V_232 ,
struct V_41 * V_102 )
{
struct V_40 * V_45 ;
struct V_137 * V_138 = V_28 -> V_35 ;
int V_234 , V_235 ;
struct V_9 * V_10 ;
struct V_155 * V_233 ;
unsigned long V_236 ;
struct V_139 * V_140 ;
int V_237 = 0 ;
T_4 V_7 ;
F_119 ( V_232 ,
L_32 ) ;
for ( V_7 = 0 ; V_7 < V_138 -> V_30 ; V_7 ++ ) {
V_140 = & V_138 -> V_145 [ V_7 ] ;
F_70 () ;
F_71 (orig_node, head, hash_entry) {
V_45 = F_90 ( V_10 ,
V_102 ) ;
if ( ! V_45 )
continue;
V_233 = F_87 ( V_45 ,
V_102 ) ;
if ( ! V_233 )
goto V_238;
if ( V_233 -> V_11 . V_163 == 0 )
goto V_238;
V_236 = V_71 - V_10 -> V_169 ;
V_234 = F_120 ( V_236 ) ;
V_235 = V_234 / 1000 ;
V_234 = V_234 % 1000 ;
F_117 ( V_232 , L_33 ,
V_10 -> V_63 , V_235 ,
V_234 , V_233 -> V_11 . V_163 ,
V_45 -> V_29 ,
V_45 -> V_91 -> V_64 -> V_96 ) ;
F_116 ( V_10 , V_102 ,
V_232 ) ;
F_119 ( V_232 , L_34 ) ;
V_237 ++ ;
V_238:
F_86 ( V_45 ) ;
if ( V_233 )
F_88 ( V_233 ) ;
}
F_74 () ;
}
if ( V_237 == 0 )
F_119 ( V_232 , L_35 ) ;
}
static bool
F_121 ( struct V_40 * V_45 ,
struct V_41 * V_102 ,
T_1 * V_163 )
{
struct V_155 * V_233 ;
V_233 = F_87 ( V_45 , V_102 ) ;
if ( ! V_233 )
return false ;
* V_163 = V_233 -> V_11 . V_163 ;
F_88 ( V_233 ) ;
return true ;
}
static int
F_122 ( struct V_84 * V_239 , T_4 V_240 , T_4 V_232 ,
struct V_27 * V_28 ,
struct V_41 * V_102 ,
struct V_9 * V_10 ,
struct V_40 * V_45 ,
bool V_241 )
{
void * V_242 ;
T_1 V_163 ;
unsigned int V_234 ;
V_234 = F_120 ( V_71 - V_10 -> V_169 ) ;
if ( ! F_121 ( V_45 , V_102 , & V_163 ) )
return 0 ;
if ( V_102 != V_210 &&
V_102 != V_45 -> V_91 )
return 0 ;
V_242 = F_123 ( V_239 , V_240 , V_232 , & V_243 ,
V_244 , V_245 ) ;
if ( ! V_242 )
return - V_246 ;
if ( F_124 ( V_239 , V_247 , V_248 ,
V_10 -> V_63 ) ||
F_124 ( V_239 , V_249 , V_248 ,
V_45 -> V_29 ) ||
F_125 ( V_239 , V_250 ,
V_45 -> V_91 -> V_64 -> V_251 ) ||
F_126 ( V_239 , V_252 , V_163 ) ||
F_125 ( V_239 , V_253 ,
V_234 ) )
goto V_254;
if ( V_241 && F_127 ( V_239 , V_255 ) )
goto V_254;
F_128 ( V_239 , V_242 ) ;
return 0 ;
V_254:
F_129 ( V_239 , V_242 ) ;
return - V_256 ;
}
static int
F_130 ( struct V_84 * V_239 , T_4 V_240 , T_4 V_232 ,
struct V_27 * V_28 ,
struct V_41 * V_102 ,
struct V_9 * V_10 , int * V_257 )
{
struct V_40 * V_258 ;
struct V_40 * V_45 ;
int V_259 = 0 ;
bool V_241 ;
T_1 V_260 ;
V_258 = F_90 ( V_10 , V_102 ) ;
if ( ! V_258 )
goto V_46;
if ( ! F_121 ( V_258 , V_102 ,
& V_260 ) )
goto V_46;
if ( V_260 == 0 )
goto V_46;
F_71 (neigh_node, &orig_node->neigh_list, list) {
if ( V_259 ++ < * V_257 )
continue;
V_241 = ( V_45 == V_258 ) ;
if ( F_122 ( V_239 , V_240 , V_232 ,
V_28 , V_102 ,
V_10 , V_45 ,
V_241 ) ) {
F_86 ( V_258 ) ;
* V_257 = V_259 - 1 ;
return - V_256 ;
}
}
V_46:
if ( V_258 )
F_86 ( V_258 ) ;
* V_257 = 0 ;
return 0 ;
}
static int
F_131 ( struct V_84 * V_239 , T_4 V_240 , T_4 V_232 ,
struct V_27 * V_28 ,
struct V_41 * V_102 ,
struct V_139 * V_140 , int * V_261 , int * V_259 )
{
struct V_9 * V_10 ;
int V_262 = 0 ;
F_70 () ;
F_71 (orig_node, head, hash_entry) {
if ( V_262 ++ < * V_261 )
continue;
if ( F_130 ( V_239 , V_240 , V_232 , V_28 ,
V_102 , V_10 ,
V_259 ) ) {
F_74 () ;
* V_261 = V_262 - 1 ;
return - V_256 ;
}
}
F_74 () ;
* V_261 = 0 ;
* V_259 = 0 ;
return 0 ;
}
static void
F_132 ( struct V_84 * V_239 , struct V_263 * V_264 ,
struct V_27 * V_28 ,
struct V_41 * V_102 )
{
struct V_137 * V_138 = V_28 -> V_35 ;
struct V_139 * V_140 ;
int V_265 = V_264 -> args [ 0 ] ;
int V_262 = V_264 -> args [ 1 ] ;
int V_259 = V_264 -> args [ 2 ] ;
int V_240 = F_133 ( V_264 -> V_85 ) . V_240 ;
while ( V_265 < V_138 -> V_30 ) {
V_140 = & V_138 -> V_145 [ V_265 ] ;
if ( F_131 ( V_239 , V_240 ,
V_264 -> V_266 -> V_267 ,
V_28 , V_102 , V_140 ,
& V_262 , & V_259 ) )
break;
V_265 ++ ;
}
V_264 -> args [ 0 ] = V_265 ;
V_264 -> args [ 1 ] = V_262 ;
V_264 -> args [ 2 ] = V_259 ;
}
static void
F_134 ( struct V_231 * V_232 ,
struct V_201 * V_202 )
{
int V_268 , V_269 ;
V_268 = F_120 ( V_71 - V_202 -> V_169 ) / 1000 ;
V_269 = F_120 ( V_71 - V_202 -> V_169 ) % 1000 ;
F_117 ( V_232 , L_36 ,
V_202 -> V_91 -> V_64 -> V_96 ,
V_202 -> V_29 , V_268 , V_269 ) ;
}
static void F_135 ( struct V_27 * V_28 ,
struct V_231 * V_232 )
{
struct V_101 * V_64 = (struct V_101 * ) V_232 -> V_270 ;
struct V_201 * V_202 ;
struct V_41 * V_42 ;
int V_237 = 0 ;
F_119 ( V_232 , L_37 ) ;
F_70 () ;
F_81 (hard_iface, &batadv_hardif_list, list) {
if ( V_42 -> V_81 != V_64 )
continue;
F_71 (hardif_neigh,
&hard_iface->neigh_list, list) {
F_134 ( V_232 , V_202 ) ;
V_237 ++ ;
}
}
F_74 () ;
if ( V_237 == 0 )
F_119 ( V_232 , L_35 ) ;
}
static bool F_136 ( struct V_40 * V_271 ,
struct V_41 * V_272 ,
struct V_40 * V_273 ,
struct V_41 * V_274 ,
int * V_275 )
{
struct V_155 * V_276 , * V_277 ;
T_1 V_278 , V_279 ;
bool V_17 = true ;
V_276 = F_87 ( V_271 , V_272 ) ;
V_277 = F_87 ( V_273 , V_274 ) ;
if ( ! V_276 || ! V_277 ) {
V_17 = false ;
goto V_46;
}
V_278 = V_276 -> V_11 . V_163 ;
V_279 = V_277 -> V_11 . V_163 ;
* V_275 = ( int ) V_278 - ( int ) V_279 ;
V_46:
if ( V_276 )
F_88 ( V_276 ) ;
if ( V_277 )
F_88 ( V_277 ) ;
return V_17 ;
}
static int
F_137 ( struct V_84 * V_239 , T_4 V_240 , T_4 V_232 ,
struct V_201 * V_202 )
{
void * V_242 ;
unsigned int V_234 ;
V_234 = F_120 ( V_71 - V_202 -> V_169 ) ;
V_242 = F_123 ( V_239 , V_240 , V_232 , & V_243 ,
V_244 , V_280 ) ;
if ( ! V_242 )
return - V_246 ;
if ( F_124 ( V_239 , V_249 , V_248 ,
V_202 -> V_29 ) ||
F_125 ( V_239 , V_250 ,
V_202 -> V_91 -> V_64 -> V_251 ) ||
F_125 ( V_239 , V_253 ,
V_234 ) )
goto V_254;
F_128 ( V_239 , V_242 ) ;
return 0 ;
V_254:
F_129 ( V_239 , V_242 ) ;
return - V_256 ;
}
static int
F_138 ( struct V_84 * V_239 , T_4 V_240 , T_4 V_232 ,
struct V_27 * V_28 ,
struct V_41 * V_42 ,
int * V_261 )
{
struct V_201 * V_202 ;
int V_262 = 0 ;
F_71 (hardif_neigh,
&hard_iface->neigh_list, list) {
if ( V_262 ++ < * V_261 )
continue;
if ( F_137 ( V_239 , V_240 , V_232 ,
V_202 ) ) {
* V_261 = V_262 - 1 ;
return - V_256 ;
}
}
* V_261 = 0 ;
return 0 ;
}
static void
F_139 ( struct V_84 * V_239 , struct V_263 * V_264 ,
struct V_27 * V_28 ,
struct V_41 * V_281 )
{
struct V_41 * V_42 ;
int V_282 = 0 ;
int V_283 = V_264 -> args [ 0 ] ;
int V_262 = V_264 -> args [ 1 ] ;
int V_240 = F_133 ( V_264 -> V_85 ) . V_240 ;
F_70 () ;
if ( V_281 ) {
if ( V_283 == 0 ) {
if ( F_138 ( V_239 , V_240 ,
V_264 -> V_266 -> V_267 ,
V_28 ,
V_281 ,
& V_262 ) == 0 )
V_282 ++ ;
}
} else {
F_81 (hard_iface, &batadv_hardif_list,
list) {
if ( V_42 -> V_81 != V_28 -> V_81 )
continue;
if ( V_282 ++ < V_283 )
continue;
if ( F_138 ( V_239 , V_240 ,
V_264 -> V_266 -> V_267 ,
V_28 ,
V_42 , & V_262 ) ) {
V_282 -- ;
break;
}
}
}
F_74 () ;
V_264 -> args [ 0 ] = V_282 ;
V_264 -> args [ 1 ] = V_262 ;
}
static int F_140 ( struct V_40 * V_271 ,
struct V_41 * V_272 ,
struct V_40 * V_273 ,
struct V_41 * V_274 )
{
bool V_17 ;
int V_275 ;
V_17 = F_136 ( V_271 , V_272 , V_273 ,
V_274 , & V_275 ) ;
if ( ! V_17 )
return 0 ;
return V_275 ;
}
static bool
F_141 ( struct V_40 * V_271 ,
struct V_41 * V_272 ,
struct V_40 * V_273 ,
struct V_41 * V_274 )
{
bool V_17 ;
int V_275 ;
V_17 = F_136 ( V_271 , V_272 , V_273 ,
V_274 , & V_275 ) ;
if ( ! V_17 )
return false ;
V_17 = V_275 > - V_284 ;
return V_17 ;
}
static void F_142 ( struct V_41 * V_42 )
{
F_75 ( V_42 ) ;
}
static struct V_285 *
F_143 ( struct V_27 * V_28 )
{
struct V_40 * V_159 ;
struct V_155 * V_157 ;
struct V_285 * V_286 , * V_287 = NULL ;
T_9 V_288 = 0 ;
T_9 V_289 = 0 ;
T_1 V_290 = 0 ;
T_1 V_163 ;
struct V_9 * V_10 ;
F_70 () ;
F_71 (gw_node, &bat_priv->gw.list, list) {
V_10 = V_286 -> V_10 ;
V_159 = F_90 ( V_10 , V_210 ) ;
if ( ! V_159 )
continue;
V_157 = F_87 ( V_159 ,
V_210 ) ;
if ( ! V_157 )
goto V_238;
if ( ! F_82 ( & V_286 -> V_34 ) )
goto V_238;
V_163 = V_157 -> V_11 . V_163 ;
switch ( F_32 ( & V_28 -> V_291 . V_292 ) ) {
case 1 :
V_289 = V_163 * V_163 ;
V_289 *= V_286 -> V_293 ;
V_289 *= 100 * 100 ;
V_289 >>= 18 ;
if ( ( V_289 > V_288 ) ||
( ( V_289 == V_288 ) &&
( V_163 > V_290 ) ) ) {
if ( V_287 )
F_144 ( V_287 ) ;
V_287 = V_286 ;
F_18 ( & V_287 -> V_34 ) ;
}
break;
default:
if ( V_163 > V_290 ) {
if ( V_287 )
F_144 ( V_287 ) ;
V_287 = V_286 ;
F_18 ( & V_287 -> V_34 ) ;
}
break;
}
if ( V_163 > V_290 )
V_290 = V_163 ;
if ( V_289 > V_288 )
V_288 = V_289 ;
F_144 ( V_286 ) ;
V_238:
F_86 ( V_159 ) ;
if ( V_157 )
F_88 ( V_157 ) ;
}
F_74 () ;
return V_287 ;
}
static bool F_145 ( struct V_27 * V_28 ,
struct V_9 * V_294 ,
struct V_9 * V_10 )
{
struct V_155 * V_295 = NULL ;
struct V_155 * V_296 = NULL ;
struct V_40 * V_297 = NULL ;
struct V_40 * V_298 = NULL ;
T_1 V_299 , V_300 ;
bool V_17 = false ;
if ( F_32 ( & V_28 -> V_291 . V_292 ) <= 2 )
return false ;
V_297 = F_90 ( V_294 , V_210 ) ;
if ( ! V_297 ) {
V_17 = true ;
goto V_46;
}
V_296 = F_87 ( V_297 ,
V_210 ) ;
if ( ! V_296 ) {
V_17 = true ;
goto V_46;
}
V_298 = F_90 ( V_10 , V_210 ) ;
if ( ! V_298 )
goto V_46;
V_295 = F_87 ( V_298 ,
V_210 ) ;
if ( ! V_295 )
goto V_46;
V_299 = V_296 -> V_11 . V_163 ;
V_300 = V_295 -> V_11 . V_163 ;
if ( V_300 < V_299 )
goto V_46;
if ( ( F_32 ( & V_28 -> V_291 . V_292 ) > 3 ) &&
( V_300 - V_299 < F_32 ( & V_28 -> V_291 . V_292 ) ) )
goto V_46;
F_42 ( V_94 , V_28 ,
L_38 ,
V_299 , V_300 ) ;
V_17 = true ;
V_46:
if ( V_296 )
F_88 ( V_296 ) ;
if ( V_295 )
F_88 ( V_295 ) ;
if ( V_297 )
F_86 ( V_297 ) ;
if ( V_298 )
F_86 ( V_298 ) ;
return V_17 ;
}
static int F_146 ( struct V_27 * V_28 ,
struct V_231 * V_232 ,
const struct V_285 * V_286 )
{
struct V_285 * V_287 ;
struct V_40 * V_159 ;
struct V_155 * V_157 = NULL ;
int V_17 = - 1 ;
V_159 = F_90 ( V_286 -> V_10 , V_210 ) ;
if ( ! V_159 )
goto V_46;
V_157 = F_87 ( V_159 , V_210 ) ;
if ( ! V_157 )
goto V_46;
V_287 = F_147 ( V_28 ) ;
F_117 ( V_232 , L_39 ,
( V_287 == V_286 ? L_40 : L_41 ) ,
V_286 -> V_10 -> V_63 ,
V_157 -> V_11 . V_163 , V_159 -> V_29 ,
V_159 -> V_91 -> V_64 -> V_96 ,
V_286 -> V_293 / 10 ,
V_286 -> V_293 % 10 ,
V_286 -> V_301 / 10 ,
V_286 -> V_301 % 10 ) ;
V_17 = F_148 ( V_232 ) ? - 1 : 0 ;
if ( V_287 )
F_144 ( V_287 ) ;
V_46:
if ( V_157 )
F_88 ( V_157 ) ;
if ( V_159 )
F_86 ( V_159 ) ;
return V_17 ;
}
static void F_149 ( struct V_27 * V_28 ,
struct V_231 * V_232 )
{
struct V_285 * V_286 ;
int V_302 = 0 ;
F_119 ( V_232 ,
L_42 ) ;
F_70 () ;
F_71 (gw_node, &bat_priv->gw.list, list) {
if ( F_146 ( V_28 , V_232 , V_286 ) < 0 )
continue;
V_302 ++ ;
}
F_74 () ;
if ( V_302 == 0 )
F_119 ( V_232 , L_43 ) ;
}
static int F_150 ( struct V_84 * V_239 , T_4 V_240 , T_4 V_232 ,
struct V_27 * V_28 ,
struct V_285 * V_286 )
{
struct V_155 * V_157 = NULL ;
struct V_40 * V_159 ;
struct V_285 * V_287 ;
int V_17 = - V_303 ;
void * V_242 ;
V_159 = F_90 ( V_286 -> V_10 , V_210 ) ;
if ( ! V_159 )
goto V_46;
V_157 = F_87 ( V_159 , V_210 ) ;
if ( ! V_157 )
goto V_46;
V_287 = F_147 ( V_28 ) ;
V_242 = F_123 ( V_239 , V_240 , V_232 , & V_243 ,
V_244 , V_304 ) ;
if ( ! V_242 ) {
V_17 = - V_246 ;
goto V_46;
}
V_17 = - V_256 ;
if ( V_287 == V_286 )
if ( F_127 ( V_239 , V_255 ) ) {
F_129 ( V_239 , V_242 ) ;
goto V_46;
}
if ( F_124 ( V_239 , V_247 , V_248 ,
V_286 -> V_10 -> V_63 ) ||
F_126 ( V_239 , V_252 , V_157 -> V_11 . V_163 ) ||
F_124 ( V_239 , V_305 , V_248 ,
V_159 -> V_29 ) ||
F_151 ( V_239 , V_306 ,
V_159 -> V_91 -> V_64 -> V_96 ) ||
F_125 ( V_239 , V_307 ,
V_286 -> V_293 ) ||
F_125 ( V_239 , V_308 ,
V_286 -> V_301 ) ) {
F_129 ( V_239 , V_242 ) ;
goto V_46;
}
F_128 ( V_239 , V_242 ) ;
V_17 = 0 ;
V_46:
if ( V_157 )
F_88 ( V_157 ) ;
if ( V_159 )
F_86 ( V_159 ) ;
return V_17 ;
}
static void F_152 ( struct V_84 * V_239 , struct V_263 * V_264 ,
struct V_27 * V_28 )
{
int V_240 = F_133 ( V_264 -> V_85 ) . V_240 ;
struct V_285 * V_286 ;
int V_309 = V_264 -> args [ 0 ] ;
int V_262 = 0 ;
F_70 () ;
F_71 (gw_node, &bat_priv->gw.list, list) {
if ( V_262 ++ < V_309 )
continue;
if ( F_150 ( V_239 , V_240 , V_264 -> V_266 -> V_267 ,
V_28 , V_286 ) ) {
V_309 = V_262 - 1 ;
goto V_22;
}
}
V_309 = V_262 ;
V_22:
F_74 () ;
V_264 -> args [ 0 ] = V_309 ;
}
int T_10 F_153 ( void )
{
int V_17 ;
V_17 = F_154 ( V_54 ,
F_113 ) ;
if ( V_17 < 0 )
goto V_46;
V_17 = F_155 ( & V_310 ) ;
if ( V_17 < 0 )
goto V_311;
goto V_46;
V_311:
F_156 ( V_54 ) ;
V_46:
return V_17 ;
}

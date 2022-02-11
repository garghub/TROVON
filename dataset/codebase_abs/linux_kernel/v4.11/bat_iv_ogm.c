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
F_59 ( V_114 , true ) ;
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
F_62 ( & V_114 -> V_122 ,
V_123 ) ;
F_63 ( V_28 , V_114 , V_104 ) ;
}
static void F_64 ( struct V_79 * V_114 ,
const unsigned char * V_111 ,
int V_75 , bool V_112 )
{
unsigned char * V_115 ;
unsigned long V_124 ;
V_115 = F_61 ( V_114 -> V_85 , V_75 ) ;
memcpy ( V_115 , V_111 , V_75 ) ;
V_114 -> V_75 += V_75 ;
V_114 -> V_125 ++ ;
if ( V_112 ) {
V_124 = F_41 ( V_114 -> V_125 ) ;
V_114 -> V_90 |= V_124 ;
}
}
static void F_65 ( struct V_27 * V_28 ,
unsigned char * V_111 ,
int V_75 ,
struct V_41 * V_91 ,
struct V_41 * V_102 ,
int V_113 , unsigned long V_104 )
{
struct V_79 * V_114 = NULL ;
struct V_79 * V_126 = NULL ;
struct V_47 * V_47 ;
bool V_112 ;
unsigned long V_127 ;
V_47 = (struct V_47 * ) V_111 ;
V_112 = ! ! ( V_47 -> V_58 & V_92 ) ;
V_127 = F_34 ( V_110 ) ;
F_6 ( & V_28 -> V_128 ) ;
if ( F_32 ( & V_28 -> V_119 ) && ! V_113 ) {
F_66 (forw_packet_pos,
&bat_priv->forw_bat_list, list) {
if ( F_51 ( V_47 ,
V_28 , V_75 ,
V_104 , V_112 ,
V_91 ,
V_102 ,
V_126 ) ) {
V_114 = V_126 ;
break;
}
}
}
if ( ! V_114 ) {
F_8 ( & V_28 -> V_128 ) ;
if ( ! V_113 && F_32 ( & V_28 -> V_119 ) )
V_104 += V_127 ;
F_56 ( V_111 , V_75 ,
V_104 , V_112 ,
V_91 , V_102 ,
V_113 ) ;
} else {
F_64 ( V_114 , V_111 ,
V_75 , V_112 ) ;
F_8 ( & V_28 -> V_128 ) ;
}
}
static void F_67 ( struct V_9 * V_10 ,
const struct V_129 * V_129 ,
struct V_47 * V_47 ,
bool V_130 ,
bool V_131 ,
struct V_41 * V_91 ,
struct V_41 * V_102 )
{
struct V_27 * V_28 = F_40 ( V_91 -> V_81 ) ;
T_2 V_76 ;
if ( V_47 -> V_57 <= 1 ) {
F_42 ( V_94 , V_28 , L_9 ) ;
return;
}
if ( ! V_131 ) {
if ( V_130 )
V_47 -> V_58 |= V_132 ;
else
return;
}
V_76 = F_38 ( V_47 -> V_76 ) ;
V_47 -> V_57 -- ;
F_29 ( V_47 -> V_66 , V_129 -> V_133 ) ;
V_47 -> V_61 = F_36 ( V_47 -> V_61 ,
V_28 ) ;
F_42 ( V_94 , V_28 ,
L_10 ,
V_47 -> V_61 , V_47 -> V_57 ) ;
if ( V_130 )
V_47 -> V_58 |= V_92 ;
else
V_47 -> V_58 &= ~ V_92 ;
F_65 ( V_28 , ( unsigned char * ) V_47 ,
V_52 + V_76 ,
V_91 , V_102 , 0 ,
F_35 () ) ;
}
static void
F_68 ( struct V_41 * V_42 )
{
struct V_27 * V_28 = F_40 ( V_42 -> V_81 ) ;
struct V_134 * V_135 = V_28 -> V_35 ;
struct V_136 * V_137 ;
struct V_9 * V_10 ;
unsigned long * V_138 ;
T_4 V_7 ;
T_3 V_139 ;
T_1 * V_140 ;
int V_141 ;
for ( V_7 = 0 ; V_7 < V_135 -> V_30 ; V_7 ++ ) {
V_137 = & V_135 -> V_142 [ V_7 ] ;
F_69 () ;
F_70 (orig_node, head, hash_entry) {
F_6 ( & V_10 -> V_11 . V_19 ) ;
V_139 = V_42 -> V_141 * V_20 ;
V_138 = & V_10 -> V_11 . V_12 [ V_139 ] ;
F_71 ( V_28 , V_138 , 1 , 0 ) ;
V_141 = V_42 -> V_141 ;
V_140 = & V_10 -> V_11 . V_13 [ V_141 ] ;
* V_140 = F_72 ( V_138 , V_143 ) ;
F_8 ( & V_10 -> V_11 . V_19 ) ;
}
F_73 () ;
}
}
static void F_74 ( struct V_41 * V_42 )
{
struct V_27 * V_28 = F_40 ( V_42 -> V_81 ) ;
unsigned char * * V_48 = & V_42 -> V_11 . V_48 ;
struct V_47 * V_47 ;
struct V_41 * V_107 , * V_144 ;
int * V_51 = & V_42 -> V_11 . V_51 ;
T_4 V_95 ;
T_2 V_76 = 0 ;
unsigned long V_104 ;
if ( ( V_42 -> V_87 == V_145 ) ||
( V_42 -> V_87 == V_146 ) )
return;
if ( V_42 -> V_87 == V_147 )
V_42 -> V_87 = V_88 ;
V_107 = F_54 ( V_28 ) ;
if ( V_42 == V_107 ) {
F_75 ( V_28 ) ;
V_76 = F_76 ( V_28 , V_48 ,
V_51 ,
V_52 ) ;
}
V_47 = (struct V_47 * ) ( * V_48 ) ;
V_47 -> V_76 = F_77 ( V_76 ) ;
V_95 = ( T_4 ) F_32 ( & V_42 -> V_11 . V_50 ) ;
V_47 -> V_95 = F_78 ( V_95 ) ;
F_79 ( & V_42 -> V_11 . V_50 ) ;
F_68 ( V_42 ) ;
V_104 = F_31 ( V_28 ) ;
if ( V_42 != V_107 ) {
F_65 ( V_28 , * V_48 , * V_51 ,
V_42 , V_42 , 1 , V_104 ) ;
goto V_46;
}
F_69 () ;
F_80 (tmp_hard_iface, &batadv_hardif_list, list) {
if ( V_144 -> V_81 != V_42 -> V_81 )
continue;
if ( ! F_81 ( & V_144 -> V_34 ) )
continue;
F_65 ( V_28 , * V_48 ,
* V_51 , V_42 ,
V_144 , 1 , V_104 ) ;
F_55 ( V_144 ) ;
}
F_73 () ;
V_46:
if ( V_107 )
F_55 ( V_107 ) ;
}
static void
F_82 ( struct V_27 * V_28 ,
struct V_9 * V_10 ,
struct V_148 * V_149 ,
const struct V_129 * V_129 ,
const struct V_47 * V_47 ,
struct V_41 * V_91 ,
struct V_41 * V_102 ,
enum V_150 V_151 )
{
struct V_152 * V_153 = NULL ;
struct V_152 * V_154 = NULL ;
struct V_40 * V_45 = NULL ;
struct V_40 * V_155 = NULL ;
struct V_40 * V_156 = NULL ;
struct V_9 * V_157 ;
int V_141 ;
T_1 V_158 , V_159 ;
T_1 * V_43 ;
T_1 V_160 ;
F_42 ( V_94 , V_28 ,
L_11 ) ;
F_69 () ;
F_70 (tmp_neigh_node,
&orig_node->neigh_list, list) {
V_43 = V_155 -> V_29 ;
if ( F_83 ( V_43 , V_129 -> V_133 ) &&
V_155 -> V_91 == V_91 &&
F_81 ( & V_155 -> V_34 ) ) {
if ( F_84 ( V_45 , L_12 ) )
F_85 ( V_45 ) ;
V_45 = V_155 ;
continue;
}
if ( V_151 != V_161 )
continue;
V_153 = F_86 ( V_155 ,
V_102 ) ;
if ( ! V_153 )
continue;
F_6 ( & V_155 -> V_162 ) ;
F_1 ( V_153 -> V_11 . V_163 ,
& V_153 -> V_11 . V_164 , 0 ) ;
V_160 = F_2 ( V_153 -> V_11 . V_163 ) ;
V_153 -> V_11 . V_160 = V_160 ;
F_8 ( & V_155 -> V_162 ) ;
F_87 ( V_153 ) ;
V_153 = NULL ;
}
if ( ! V_45 ) {
struct V_9 * V_165 ;
V_165 = F_13 ( V_28 , V_129 -> V_133 ) ;
if ( ! V_165 )
goto V_22;
V_45 = F_21 ( V_91 ,
V_129 -> V_133 ,
V_10 , V_165 ) ;
F_20 ( V_165 ) ;
if ( ! V_45 )
goto V_22;
} else {
F_42 ( V_94 , V_28 ,
L_13 ) ;
}
F_73 () ;
V_153 = F_88 ( V_45 , V_102 ) ;
if ( ! V_153 )
goto V_46;
V_45 -> V_166 = V_71 ;
F_6 ( & V_45 -> V_162 ) ;
F_1 ( V_153 -> V_11 . V_163 ,
& V_153 -> V_11 . V_164 ,
V_47 -> V_61 ) ;
V_160 = F_2 ( V_153 -> V_11 . V_163 ) ;
V_153 -> V_11 . V_160 = V_160 ;
F_8 ( & V_45 -> V_162 ) ;
if ( V_151 == V_161 ) {
V_149 -> V_167 = V_47 -> V_57 ;
V_153 -> V_167 = V_47 -> V_57 ;
}
V_156 = F_89 ( V_10 , V_102 ) ;
if ( V_156 == V_45 )
goto V_46;
if ( V_156 ) {
V_154 = F_86 ( V_156 , V_102 ) ;
if ( ! V_154 )
goto V_46;
if ( V_154 -> V_11 . V_160 > V_153 -> V_11 . V_160 )
goto V_46;
}
if ( V_154 &&
V_153 -> V_11 . V_160 == V_154 -> V_11 . V_160 ) {
V_157 = V_156 -> V_10 ;
F_6 ( & V_157 -> V_11 . V_19 ) ;
V_141 = V_156 -> V_91 -> V_141 ;
V_158 = V_157 -> V_11 . V_13 [ V_141 ] ;
F_8 ( & V_157 -> V_11 . V_19 ) ;
V_157 = V_45 -> V_10 ;
F_6 ( & V_157 -> V_11 . V_19 ) ;
V_141 = V_45 -> V_91 -> V_141 ;
V_159 = V_157 -> V_11 . V_13 [ V_141 ] ;
F_8 ( & V_157 -> V_11 . V_19 ) ;
if ( V_158 >= V_159 )
goto V_46;
}
F_90 ( V_28 , V_10 , V_102 , V_45 ) ;
goto V_46;
V_22:
F_73 () ;
V_46:
if ( V_45 )
F_85 ( V_45 ) ;
if ( V_156 )
F_85 ( V_156 ) ;
if ( V_153 )
F_87 ( V_153 ) ;
if ( V_154 )
F_87 ( V_154 ) ;
}
static bool F_91 ( struct V_9 * V_10 ,
struct V_9 * V_168 ,
struct V_47 * V_47 ,
struct V_41 * V_91 ,
struct V_41 * V_102 )
{
struct V_27 * V_28 = F_40 ( V_91 -> V_81 ) ;
struct V_40 * V_45 = NULL , * V_155 ;
struct V_152 * V_153 ;
T_1 V_169 ;
T_1 V_170 , V_171 , V_172 , V_173 ;
unsigned int V_174 , V_175 ;
int V_141 ;
unsigned int V_176 , V_177 ;
unsigned int V_178 ;
unsigned int V_179 ;
bool V_17 = false ;
F_69 () ;
F_70 (tmp_neigh_node,
&orig_neigh_node->neigh_list, list) {
if ( ! F_83 ( V_155 -> V_29 ,
V_168 -> V_63 ) )
continue;
if ( V_155 -> V_91 != V_91 )
continue;
if ( ! F_81 ( & V_155 -> V_34 ) )
continue;
V_45 = V_155 ;
break;
}
F_73 () ;
if ( ! V_45 )
V_45 = F_21 ( V_91 ,
V_168 -> V_63 ,
V_168 ,
V_168 ) ;
if ( ! V_45 )
goto V_46;
if ( V_10 == V_168 )
V_45 -> V_166 = V_71 ;
V_10 -> V_166 = V_71 ;
F_6 ( & V_10 -> V_11 . V_19 ) ;
V_141 = V_91 -> V_141 ;
V_170 = V_168 -> V_11 . V_13 [ V_141 ] ;
V_153 = F_88 ( V_45 , V_102 ) ;
if ( V_153 ) {
V_171 = V_153 -> V_11 . V_180 ;
F_87 ( V_153 ) ;
} else {
V_171 = 0 ;
}
F_8 ( & V_10 -> V_11 . V_19 ) ;
if ( V_170 > V_171 )
V_169 = V_171 ;
else
V_169 = V_170 ;
if ( V_169 < V_181 ||
V_171 < V_182 )
V_173 = 0 ;
else
V_173 = ( V_62 * V_169 ) / V_171 ;
V_172 = V_143 - V_171 ;
V_174 = V_172 * V_172 * V_172 ;
V_175 = V_143 *
V_143 *
V_143 ;
V_177 = V_62 * V_174 ;
V_177 /= V_175 ;
V_176 = V_62 - V_177 ;
V_179 = V_62 ;
if ( V_102 && ( V_91 == V_102 ) &&
F_92 ( V_102 ) )
V_179 = F_36 ( V_62 ,
V_28 ) ;
V_178 = V_47 -> V_61 *
V_173 *
V_176 *
V_179 ;
V_178 /= V_62 *
V_62 *
V_62 ;
V_47 -> V_61 = V_178 ;
F_42 ( V_94 , V_28 ,
L_14 ,
V_10 -> V_63 , V_168 -> V_63 , V_169 ,
V_171 , V_173 , V_176 , V_179 ,
V_47 -> V_61 , V_91 -> V_64 -> V_96 ,
V_102 ? V_102 -> V_64 -> V_96 : L_15 ) ;
if ( V_47 -> V_61 >= V_183 )
V_17 = true ;
V_46:
if ( V_45 )
F_85 ( V_45 ) ;
return V_17 ;
}
static enum V_150
F_93 ( const struct V_129 * V_129 ,
const struct V_47 * V_47 ,
const struct V_41 * V_91 ,
struct V_41 * V_102 )
{
struct V_27 * V_28 = F_40 ( V_91 -> V_81 ) ;
struct V_9 * V_10 ;
struct V_148 * V_149 = NULL ;
struct V_40 * V_45 ;
struct V_152 * V_153 ;
bool V_184 ;
T_8 V_185 ;
bool V_186 = false ;
int V_187 ;
enum V_150 V_17 = V_161 ;
T_4 V_95 = F_43 ( V_47 -> V_95 ) ;
T_1 * V_43 ;
T_1 V_188 ;
unsigned long * V_189 ;
V_10 = F_13 ( V_28 , V_47 -> V_63 ) ;
if ( ! V_10 )
return V_161 ;
V_149 = F_94 ( V_10 , V_102 ) ;
if ( F_50 ( ! V_149 ) ) {
F_20 ( V_10 ) ;
return 0 ;
}
F_6 ( & V_10 -> V_11 . V_19 ) ;
V_185 = V_95 - V_149 -> V_190 ;
if ( ! F_95 ( & V_10 -> V_191 ) &&
F_96 ( V_28 , V_185 ,
V_143 ,
& V_149 -> V_192 , NULL ) ) {
V_17 = V_193 ;
goto V_46;
}
F_69 () ;
F_70 (neigh_node, &orig_node->neigh_list, list) {
V_153 = F_88 ( V_45 ,
V_102 ) ;
if ( ! V_153 )
continue;
V_43 = V_45 -> V_29 ;
V_184 = F_97 ( V_153 -> V_11 . V_194 ,
V_149 -> V_190 ,
V_95 ) ;
if ( F_83 ( V_43 , V_129 -> V_133 ) &&
V_45 -> V_91 == V_91 ) {
V_187 = 1 ;
if ( V_184 )
V_17 = V_195 ;
} else {
V_187 = 0 ;
if ( V_184 && ( V_17 != V_195 ) )
V_17 = V_196 ;
}
V_189 = V_153 -> V_11 . V_194 ;
V_186 |= F_71 ( V_28 , V_189 ,
V_185 , V_187 ) ;
V_188 = F_72 ( V_189 ,
V_143 ) ;
V_153 -> V_11 . V_180 = V_188 ;
F_87 ( V_153 ) ;
}
F_73 () ;
if ( V_186 ) {
F_42 ( V_94 , V_28 ,
L_16 ,
V_102 ? V_102 -> V_64 -> V_96 : L_15 ,
V_149 -> V_190 , V_95 ) ;
V_149 -> V_190 = V_95 ;
}
V_46:
F_8 ( & V_10 -> V_11 . V_19 ) ;
F_20 ( V_10 ) ;
F_98 ( V_149 ) ;
return V_17 ;
}
static void
F_99 ( const struct V_84 * V_85 , int V_197 ,
struct V_9 * V_10 ,
struct V_41 * V_91 ,
struct V_41 * V_102 )
{
struct V_27 * V_28 = F_40 ( V_91 -> V_81 ) ;
struct V_198 * V_199 = NULL ;
struct V_40 * V_156 = NULL ;
struct V_40 * V_200 = NULL ;
struct V_9 * V_168 ;
struct V_148 * V_149 ;
struct V_40 * V_201 = NULL ;
struct V_152 * V_154 = NULL ;
struct V_47 * V_202 ;
enum V_150 V_151 ;
bool V_131 = false ;
bool V_130 = false ;
bool V_203 , V_204 ;
struct V_84 * V_205 ;
struct V_129 * V_129 ;
T_1 * V_66 ;
bool V_206 ;
V_205 = F_100 ( V_85 , V_21 ) ;
if ( ! V_205 )
return;
V_129 = F_101 ( V_205 ) ;
V_202 = (struct V_47 * ) ( V_205 -> V_89 + V_197 ) ;
V_151 = F_93 ( V_129 , V_202 ,
V_91 , V_102 ) ;
if ( F_83 ( V_129 -> V_133 , V_202 -> V_63 ) )
V_130 = true ;
if ( V_151 == V_193 ) {
F_42 ( V_94 , V_28 ,
L_17 ,
V_129 -> V_133 ) ;
goto V_46;
}
if ( V_202 -> V_61 == 0 ) {
F_42 ( V_94 , V_28 ,
L_18 ) ;
goto V_46;
}
if ( V_130 ) {
V_199 = F_102 ( V_91 ,
V_129 -> V_133 ) ;
if ( V_199 )
V_199 -> V_166 = V_71 ;
}
V_156 = F_89 ( V_10 , V_102 ) ;
if ( V_156 ) {
V_200 = F_89 ( V_156 -> V_10 ,
V_102 ) ;
V_154 = F_86 ( V_156 , V_102 ) ;
}
if ( ( V_154 && V_154 -> V_11 . V_160 != 0 ) &&
( F_83 ( V_156 -> V_29 , V_129 -> V_133 ) ) )
V_131 = true ;
V_66 = V_202 -> V_66 ;
if ( V_156 && V_200 &&
( F_83 ( V_156 -> V_29 , V_66 ) ) &&
! ( F_83 ( V_202 -> V_63 , V_66 ) ) &&
( F_83 ( V_156 -> V_29 , V_200 -> V_29 ) ) ) {
F_42 ( V_94 , V_28 ,
L_19 ,
V_129 -> V_133 ) ;
goto V_46;
}
if ( V_102 == V_207 )
F_103 ( V_28 , V_202 , V_10 ) ;
if ( V_130 )
V_168 = V_10 ;
else
V_168 = F_13 ( V_28 ,
V_129 -> V_133 ) ;
if ( ! V_168 )
goto V_46;
F_104 ( V_28 , V_10 , V_168 ,
V_202 , V_130 ) ;
V_201 = F_89 ( V_168 ,
V_102 ) ;
if ( ! V_130 && ( ! V_201 ) ) {
F_42 ( V_94 , V_28 ,
L_20 ) ;
goto V_208;
}
V_206 = F_91 ( V_10 , V_168 ,
V_202 , V_91 ,
V_102 ) ;
V_149 = F_94 ( V_10 , V_102 ) ;
if ( ! V_149 )
goto V_208;
V_203 = V_149 -> V_190 == F_43 ( V_202 -> V_95 ) ;
V_204 = ( V_149 -> V_167 - 3 ) <= V_202 -> V_57 ;
if ( V_206 && ( ( V_151 == V_161 ) ||
( V_203 && V_204 ) ) ) {
F_82 ( V_28 , V_10 ,
V_149 , V_129 ,
V_202 , V_91 ,
V_102 , V_151 ) ;
}
F_98 ( V_149 ) ;
if ( V_102 == V_207 )
goto V_208;
if ( V_130 ) {
if ( ( V_202 -> V_57 <= 2 ) &&
( V_91 != V_102 ) ) {
F_42 ( V_94 , V_28 ,
L_21 ) ;
goto V_208;
}
F_67 ( V_10 , V_129 , V_202 ,
V_130 ,
V_131 , V_91 ,
V_102 ) ;
F_42 ( V_94 , V_28 ,
L_22 ) ;
goto V_208;
}
if ( ! V_206 ) {
F_42 ( V_94 , V_28 ,
L_23 ) ;
goto V_208;
}
if ( V_151 == V_195 ) {
F_42 ( V_94 , V_28 ,
L_24 ) ;
goto V_208;
}
F_42 ( V_94 , V_28 ,
L_25 ) ;
F_67 ( V_10 , V_129 , V_202 ,
V_130 , V_131 ,
V_91 , V_102 ) ;
V_208:
if ( ( V_168 ) && ( ! V_130 ) )
F_20 ( V_168 ) ;
V_46:
if ( V_154 )
F_87 ( V_154 ) ;
if ( V_156 )
F_85 ( V_156 ) ;
if ( V_200 )
F_85 ( V_200 ) ;
if ( V_201 )
F_85 ( V_201 ) ;
if ( V_199 )
F_105 ( V_199 ) ;
F_106 ( V_205 ) ;
}
static void F_107 ( const struct V_84 * V_85 , int V_197 ,
struct V_41 * V_91 )
{
struct V_27 * V_28 = F_40 ( V_91 -> V_81 ) ;
struct V_9 * V_168 , * V_10 ;
struct V_41 * V_42 ;
struct V_47 * V_202 ;
T_4 V_209 ;
bool V_210 ;
struct V_129 * V_129 ;
bool V_211 = false ;
bool V_212 = false ;
bool V_213 = false ;
V_202 = (struct V_47 * ) ( V_85 -> V_89 + V_197 ) ;
V_129 = F_101 ( V_85 ) ;
if ( V_202 -> V_53 != V_54 )
return;
V_209 = F_32 ( & V_91 -> V_11 . V_50 ) ;
if ( V_202 -> V_58 & V_92 )
V_210 = true ;
else
V_210 = false ;
F_42 ( V_94 , V_28 ,
L_26 ,
V_129 -> V_133 , V_91 -> V_64 -> V_96 ,
V_91 -> V_64 -> V_65 , V_202 -> V_63 ,
V_202 -> V_66 , F_43 ( V_202 -> V_95 ) ,
V_202 -> V_61 , V_202 -> V_57 ,
V_202 -> V_55 , V_210 ) ;
F_69 () ;
F_80 (hard_iface, &batadv_hardif_list, list) {
if ( V_42 -> V_87 != V_88 )
continue;
if ( V_42 -> V_81 != V_91 -> V_81 )
continue;
if ( F_83 ( V_129 -> V_133 ,
V_42 -> V_64 -> V_65 ) )
V_212 = true ;
if ( F_83 ( V_202 -> V_63 ,
V_42 -> V_64 -> V_65 ) )
V_213 = true ;
if ( F_83 ( V_202 -> V_66 ,
V_42 -> V_64 -> V_65 ) )
V_211 = true ;
}
F_73 () ;
if ( V_212 ) {
F_42 ( V_94 , V_28 ,
L_27 ,
V_129 -> V_133 ) ;
return;
}
if ( V_213 ) {
unsigned long * V_138 ;
int V_214 ;
T_8 V_215 ;
T_6 V_141 ;
T_1 * V_216 ;
V_168 = F_13 ( V_28 ,
V_129 -> V_133 ) ;
if ( ! V_168 )
return;
if ( V_210 &&
F_83 ( V_91 -> V_64 -> V_65 ,
V_202 -> V_63 ) ) {
V_141 = V_91 -> V_141 ;
V_214 = V_141 * V_20 ;
F_6 ( & V_168 -> V_11 . V_19 ) ;
V_138 = & V_168 -> V_11 . V_12 [ V_214 ] ;
V_215 = V_209 - 2 ;
V_215 -= F_43 ( V_202 -> V_95 ) ;
F_108 ( V_138 , V_215 ) ;
V_216 = & V_168 -> V_11 . V_13 [ V_141 ] ;
* V_216 = F_72 ( V_138 ,
V_143 ) ;
F_8 ( & V_168 -> V_11 . V_19 ) ;
}
F_42 ( V_94 , V_28 ,
L_28 ) ;
F_20 ( V_168 ) ;
return;
}
if ( V_211 ) {
F_42 ( V_94 , V_28 ,
L_29 ,
V_129 -> V_133 ) ;
return;
}
if ( V_202 -> V_58 & V_132 ) {
F_42 ( V_94 , V_28 ,
L_30 ,
V_129 -> V_133 ) ;
return;
}
V_10 = F_13 ( V_28 , V_202 -> V_63 ) ;
if ( ! V_10 )
return;
F_99 ( V_85 , V_197 , V_10 ,
V_91 , V_207 ) ;
F_69 () ;
F_80 (hard_iface, &batadv_hardif_list, list) {
if ( V_42 -> V_87 != V_88 )
continue;
if ( V_42 -> V_81 != V_28 -> V_81 )
continue;
if ( ! F_81 ( & V_42 -> V_34 ) )
continue;
F_99 ( V_85 , V_197 , V_10 ,
V_91 , V_42 ) ;
F_55 ( V_42 ) ;
}
F_73 () ;
F_20 ( V_10 ) ;
}
static void V_123 ( struct V_217 * V_218 )
{
struct V_122 * V_122 ;
struct V_79 * V_80 ;
struct V_27 * V_28 ;
bool V_219 = false ;
V_122 = F_109 ( V_218 ) ;
V_80 = F_110 ( V_122 , struct V_79 ,
V_122 ) ;
V_28 = F_40 ( V_80 -> V_91 -> V_81 ) ;
if ( F_32 ( & V_28 -> V_220 ) == V_221 ) {
V_219 = true ;
goto V_46;
}
F_48 ( V_80 ) ;
if ( V_80 -> V_93 &&
V_80 -> V_91 == V_80 -> V_102 )
F_74 ( V_80 -> V_91 ) ;
V_46:
if ( F_111 ( V_80 ,
& V_28 -> V_128 ) )
F_59 ( V_80 , V_219 ) ;
}
static int F_112 ( struct V_84 * V_85 ,
struct V_41 * V_91 )
{
struct V_27 * V_28 = F_40 ( V_91 -> V_81 ) ;
struct V_47 * V_202 ;
T_1 * V_86 ;
int V_197 ;
bool V_108 ;
int V_17 = V_222 ;
V_108 = F_113 ( V_85 , V_91 , V_52 ) ;
if ( ! V_108 )
goto V_223;
if ( V_28 -> V_224 -> V_225 . V_226 != F_23 )
goto V_223;
F_45 ( V_28 , V_227 ) ;
F_46 ( V_28 , V_228 ,
V_85 -> V_99 + V_100 ) ;
V_197 = 0 ;
V_202 = (struct V_47 * ) V_85 -> V_89 ;
while ( F_37 ( V_197 , F_114 ( V_85 ) ,
V_202 -> V_76 ) ) {
F_107 ( V_85 , V_197 , V_91 ) ;
V_197 += V_52 ;
V_197 += F_38 ( V_202 -> V_76 ) ;
V_86 = V_85 -> V_89 + V_197 ;
V_202 = (struct V_47 * ) V_86 ;
}
V_17 = V_229 ;
V_223:
if ( V_17 == V_229 )
F_106 ( V_85 ) ;
else
F_115 ( V_85 ) ;
return V_17 ;
}
static void
F_116 ( struct V_9 * V_10 ,
struct V_41 * V_102 ,
struct V_230 * V_231 )
{
struct V_40 * V_45 ;
struct V_152 * V_232 ;
F_70 (neigh_node, &orig_node->neigh_list, list) {
V_232 = F_86 ( V_45 , V_102 ) ;
if ( ! V_232 )
continue;
F_117 ( V_231 , L_31 ,
V_45 -> V_29 ,
V_232 -> V_11 . V_160 ) ;
F_87 ( V_232 ) ;
}
}
static void F_118 ( struct V_27 * V_28 ,
struct V_230 * V_231 ,
struct V_41 * V_102 )
{
struct V_40 * V_45 ;
struct V_134 * V_135 = V_28 -> V_35 ;
int V_233 , V_234 ;
struct V_9 * V_10 ;
struct V_152 * V_232 ;
unsigned long V_235 ;
struct V_136 * V_137 ;
int V_236 = 0 ;
T_4 V_7 ;
F_119 ( V_231 ,
L_32 ) ;
for ( V_7 = 0 ; V_7 < V_135 -> V_30 ; V_7 ++ ) {
V_137 = & V_135 -> V_142 [ V_7 ] ;
F_69 () ;
F_70 (orig_node, head, hash_entry) {
V_45 = F_89 ( V_10 ,
V_102 ) ;
if ( ! V_45 )
continue;
V_232 = F_86 ( V_45 ,
V_102 ) ;
if ( ! V_232 )
goto V_237;
if ( V_232 -> V_11 . V_160 == 0 )
goto V_237;
V_235 = V_71 - V_10 -> V_166 ;
V_233 = F_120 ( V_235 ) ;
V_234 = V_233 / 1000 ;
V_233 = V_233 % 1000 ;
F_117 ( V_231 , L_33 ,
V_10 -> V_63 , V_234 ,
V_233 , V_232 -> V_11 . V_160 ,
V_45 -> V_29 ,
V_45 -> V_91 -> V_64 -> V_96 ) ;
F_116 ( V_10 , V_102 ,
V_231 ) ;
F_119 ( V_231 , L_34 ) ;
V_236 ++ ;
V_237:
F_85 ( V_45 ) ;
if ( V_232 )
F_87 ( V_232 ) ;
}
F_73 () ;
}
if ( V_236 == 0 )
F_119 ( V_231 , L_35 ) ;
}
static bool
F_121 ( struct V_40 * V_45 ,
struct V_41 * V_102 ,
T_1 * V_160 )
{
struct V_152 * V_232 ;
V_232 = F_86 ( V_45 , V_102 ) ;
if ( ! V_232 )
return false ;
* V_160 = V_232 -> V_11 . V_160 ;
F_87 ( V_232 ) ;
return true ;
}
static int
F_122 ( struct V_84 * V_238 , T_4 V_239 , T_4 V_231 ,
struct V_27 * V_28 ,
struct V_41 * V_102 ,
struct V_9 * V_10 ,
struct V_40 * V_45 ,
bool V_240 )
{
void * V_241 ;
T_1 V_160 ;
unsigned int V_233 ;
V_233 = F_120 ( V_71 - V_10 -> V_166 ) ;
if ( ! F_121 ( V_45 , V_102 , & V_160 ) )
return 0 ;
if ( V_102 != V_207 &&
V_102 != V_45 -> V_91 )
return 0 ;
V_241 = F_123 ( V_238 , V_239 , V_231 , & V_242 ,
V_243 , V_244 ) ;
if ( ! V_241 )
return - V_245 ;
if ( F_124 ( V_238 , V_246 , V_247 ,
V_10 -> V_63 ) ||
F_124 ( V_238 , V_248 , V_247 ,
V_45 -> V_29 ) ||
F_125 ( V_238 , V_249 ,
V_45 -> V_91 -> V_64 -> V_250 ) ||
F_126 ( V_238 , V_251 , V_160 ) ||
F_125 ( V_238 , V_252 ,
V_233 ) )
goto V_253;
if ( V_240 && F_127 ( V_238 , V_254 ) )
goto V_253;
F_128 ( V_238 , V_241 ) ;
return 0 ;
V_253:
F_129 ( V_238 , V_241 ) ;
return - V_255 ;
}
static int
F_130 ( struct V_84 * V_238 , T_4 V_239 , T_4 V_231 ,
struct V_27 * V_28 ,
struct V_41 * V_102 ,
struct V_9 * V_10 , int * V_256 )
{
struct V_40 * V_257 ;
struct V_40 * V_45 ;
int V_258 = 0 ;
bool V_240 ;
T_1 V_259 ;
V_257 = F_89 ( V_10 , V_102 ) ;
if ( ! V_257 )
goto V_46;
if ( ! F_121 ( V_257 , V_102 ,
& V_259 ) )
goto V_46;
if ( V_259 == 0 )
goto V_46;
F_70 (neigh_node, &orig_node->neigh_list, list) {
if ( V_258 ++ < * V_256 )
continue;
V_240 = ( V_45 == V_257 ) ;
if ( F_122 ( V_238 , V_239 , V_231 ,
V_28 , V_102 ,
V_10 , V_45 ,
V_240 ) ) {
F_85 ( V_257 ) ;
* V_256 = V_258 - 1 ;
return - V_255 ;
}
}
V_46:
if ( V_257 )
F_85 ( V_257 ) ;
* V_256 = 0 ;
return 0 ;
}
static int
F_131 ( struct V_84 * V_238 , T_4 V_239 , T_4 V_231 ,
struct V_27 * V_28 ,
struct V_41 * V_102 ,
struct V_136 * V_137 , int * V_260 , int * V_258 )
{
struct V_9 * V_10 ;
int V_261 = 0 ;
F_69 () ;
F_70 (orig_node, head, hash_entry) {
if ( V_261 ++ < * V_260 )
continue;
if ( F_130 ( V_238 , V_239 , V_231 , V_28 ,
V_102 , V_10 ,
V_258 ) ) {
F_73 () ;
* V_260 = V_261 - 1 ;
return - V_255 ;
}
}
F_73 () ;
* V_260 = 0 ;
* V_258 = 0 ;
return 0 ;
}
static void
F_132 ( struct V_84 * V_238 , struct V_262 * V_263 ,
struct V_27 * V_28 ,
struct V_41 * V_102 )
{
struct V_134 * V_135 = V_28 -> V_35 ;
struct V_136 * V_137 ;
int V_264 = V_263 -> args [ 0 ] ;
int V_261 = V_263 -> args [ 1 ] ;
int V_258 = V_263 -> args [ 2 ] ;
int V_239 = F_133 ( V_263 -> V_85 ) . V_239 ;
while ( V_264 < V_135 -> V_30 ) {
V_137 = & V_135 -> V_142 [ V_264 ] ;
if ( F_131 ( V_238 , V_239 ,
V_263 -> V_265 -> V_266 ,
V_28 , V_102 , V_137 ,
& V_261 , & V_258 ) )
break;
V_264 ++ ;
}
V_263 -> args [ 0 ] = V_264 ;
V_263 -> args [ 1 ] = V_261 ;
V_263 -> args [ 2 ] = V_258 ;
}
static void
F_134 ( struct V_230 * V_231 ,
struct V_198 * V_199 )
{
int V_267 , V_268 ;
V_267 = F_120 ( V_71 - V_199 -> V_166 ) / 1000 ;
V_268 = F_120 ( V_71 - V_199 -> V_166 ) % 1000 ;
F_117 ( V_231 , L_36 ,
V_199 -> V_91 -> V_64 -> V_96 ,
V_199 -> V_29 , V_267 , V_268 ) ;
}
static void F_135 ( struct V_27 * V_28 ,
struct V_230 * V_231 )
{
struct V_101 * V_64 = (struct V_101 * ) V_231 -> V_269 ;
struct V_198 * V_199 ;
struct V_41 * V_42 ;
int V_236 = 0 ;
F_119 ( V_231 , L_37 ) ;
F_69 () ;
F_80 (hard_iface, &batadv_hardif_list, list) {
if ( V_42 -> V_81 != V_64 )
continue;
F_70 (hardif_neigh,
&hard_iface->neigh_list, list) {
F_134 ( V_231 , V_199 ) ;
V_236 ++ ;
}
}
F_73 () ;
if ( V_236 == 0 )
F_119 ( V_231 , L_35 ) ;
}
static bool F_136 ( struct V_40 * V_270 ,
struct V_41 * V_271 ,
struct V_40 * V_272 ,
struct V_41 * V_273 ,
int * V_274 )
{
struct V_152 * V_275 , * V_276 ;
T_1 V_277 , V_278 ;
bool V_17 = true ;
V_275 = F_86 ( V_270 , V_271 ) ;
V_276 = F_86 ( V_272 , V_273 ) ;
if ( ! V_275 || ! V_276 ) {
V_17 = false ;
goto V_46;
}
V_277 = V_275 -> V_11 . V_160 ;
V_278 = V_276 -> V_11 . V_160 ;
* V_274 = ( int ) V_277 - ( int ) V_278 ;
V_46:
if ( V_275 )
F_87 ( V_275 ) ;
if ( V_276 )
F_87 ( V_276 ) ;
return V_17 ;
}
static int
F_137 ( struct V_84 * V_238 , T_4 V_239 , T_4 V_231 ,
struct V_198 * V_199 )
{
void * V_241 ;
unsigned int V_233 ;
V_233 = F_120 ( V_71 - V_199 -> V_166 ) ;
V_241 = F_123 ( V_238 , V_239 , V_231 , & V_242 ,
V_243 , V_279 ) ;
if ( ! V_241 )
return - V_245 ;
if ( F_124 ( V_238 , V_248 , V_247 ,
V_199 -> V_29 ) ||
F_125 ( V_238 , V_249 ,
V_199 -> V_91 -> V_64 -> V_250 ) ||
F_125 ( V_238 , V_252 ,
V_233 ) )
goto V_253;
F_128 ( V_238 , V_241 ) ;
return 0 ;
V_253:
F_129 ( V_238 , V_241 ) ;
return - V_255 ;
}
static int
F_138 ( struct V_84 * V_238 , T_4 V_239 , T_4 V_231 ,
struct V_27 * V_28 ,
struct V_41 * V_42 ,
int * V_260 )
{
struct V_198 * V_199 ;
int V_261 = 0 ;
F_70 (hardif_neigh,
&hard_iface->neigh_list, list) {
if ( V_261 ++ < * V_260 )
continue;
if ( F_137 ( V_238 , V_239 , V_231 ,
V_199 ) ) {
* V_260 = V_261 - 1 ;
return - V_255 ;
}
}
* V_260 = 0 ;
return 0 ;
}
static void
F_139 ( struct V_84 * V_238 , struct V_262 * V_263 ,
struct V_27 * V_28 ,
struct V_41 * V_280 )
{
struct V_41 * V_42 ;
int V_281 = 0 ;
int V_282 = V_263 -> args [ 0 ] ;
int V_261 = V_263 -> args [ 1 ] ;
int V_239 = F_133 ( V_263 -> V_85 ) . V_239 ;
F_69 () ;
if ( V_280 ) {
if ( V_282 == 0 ) {
if ( F_138 ( V_238 , V_239 ,
V_263 -> V_265 -> V_266 ,
V_28 ,
V_280 ,
& V_261 ) == 0 )
V_281 ++ ;
}
} else {
F_80 (hard_iface, &batadv_hardif_list,
list) {
if ( V_42 -> V_81 != V_28 -> V_81 )
continue;
if ( V_281 ++ < V_282 )
continue;
if ( F_138 ( V_238 , V_239 ,
V_263 -> V_265 -> V_266 ,
V_28 ,
V_42 , & V_261 ) ) {
V_281 -- ;
break;
}
}
}
F_73 () ;
V_263 -> args [ 0 ] = V_281 ;
V_263 -> args [ 1 ] = V_261 ;
}
static int F_140 ( struct V_40 * V_270 ,
struct V_41 * V_271 ,
struct V_40 * V_272 ,
struct V_41 * V_273 )
{
bool V_17 ;
int V_274 ;
V_17 = F_136 ( V_270 , V_271 , V_272 ,
V_273 , & V_274 ) ;
if ( ! V_17 )
return 0 ;
return V_274 ;
}
static bool
F_141 ( struct V_40 * V_270 ,
struct V_41 * V_271 ,
struct V_40 * V_272 ,
struct V_41 * V_273 )
{
bool V_17 ;
int V_274 ;
V_17 = F_136 ( V_270 , V_271 , V_272 ,
V_273 , & V_274 ) ;
if ( ! V_17 )
return false ;
V_17 = V_274 > - V_283 ;
return V_17 ;
}
static void F_142 ( struct V_41 * V_42 )
{
F_74 ( V_42 ) ;
}
static void F_143 ( struct V_27 * V_28 )
{
F_25 ( & V_28 -> V_284 . V_285 , 20 ) ;
}
static struct V_286 *
F_144 ( struct V_27 * V_28 )
{
struct V_40 * V_156 ;
struct V_152 * V_154 ;
struct V_286 * V_287 , * V_288 = NULL ;
T_9 V_289 = 0 ;
T_9 V_290 = 0 ;
T_1 V_291 = 0 ;
T_1 V_160 ;
struct V_9 * V_10 ;
F_69 () ;
F_70 (gw_node, &bat_priv->gw.gateway_list, list) {
V_10 = V_287 -> V_10 ;
V_156 = F_89 ( V_10 , V_207 ) ;
if ( ! V_156 )
continue;
V_154 = F_86 ( V_156 ,
V_207 ) ;
if ( ! V_154 )
goto V_237;
if ( ! F_81 ( & V_287 -> V_34 ) )
goto V_237;
V_160 = V_154 -> V_11 . V_160 ;
switch ( F_32 ( & V_28 -> V_284 . V_285 ) ) {
case 1 :
V_290 = V_160 * V_160 ;
V_290 *= V_287 -> V_292 ;
V_290 *= 100 * 100 ;
V_290 >>= 18 ;
if ( ( V_290 > V_289 ) ||
( ( V_290 == V_289 ) &&
( V_160 > V_291 ) ) ) {
if ( V_288 )
F_145 ( V_288 ) ;
V_288 = V_287 ;
F_18 ( & V_288 -> V_34 ) ;
}
break;
default:
if ( V_160 > V_291 ) {
if ( V_288 )
F_145 ( V_288 ) ;
V_288 = V_287 ;
F_18 ( & V_288 -> V_34 ) ;
}
break;
}
if ( V_160 > V_291 )
V_291 = V_160 ;
if ( V_290 > V_289 )
V_289 = V_290 ;
F_145 ( V_287 ) ;
V_237:
F_85 ( V_156 ) ;
if ( V_154 )
F_87 ( V_154 ) ;
}
F_73 () ;
return V_288 ;
}
static bool F_146 ( struct V_27 * V_28 ,
struct V_9 * V_293 ,
struct V_9 * V_10 )
{
struct V_152 * V_294 = NULL ;
struct V_152 * V_295 = NULL ;
struct V_40 * V_296 = NULL ;
struct V_40 * V_297 = NULL ;
T_1 V_298 , V_299 ;
bool V_17 = false ;
if ( F_32 ( & V_28 -> V_284 . V_285 ) <= 2 )
return false ;
V_296 = F_89 ( V_293 , V_207 ) ;
if ( ! V_296 ) {
V_17 = true ;
goto V_46;
}
V_295 = F_86 ( V_296 ,
V_207 ) ;
if ( ! V_295 ) {
V_17 = true ;
goto V_46;
}
V_297 = F_89 ( V_10 , V_207 ) ;
if ( ! V_297 )
goto V_46;
V_294 = F_86 ( V_297 ,
V_207 ) ;
if ( ! V_294 )
goto V_46;
V_298 = V_295 -> V_11 . V_160 ;
V_299 = V_294 -> V_11 . V_160 ;
if ( V_299 < V_298 )
goto V_46;
if ( ( F_32 ( & V_28 -> V_284 . V_285 ) > 3 ) &&
( V_299 - V_298 < F_32 ( & V_28 -> V_284 . V_285 ) ) )
goto V_46;
F_42 ( V_94 , V_28 ,
L_38 ,
V_298 , V_299 ) ;
V_17 = true ;
V_46:
if ( V_295 )
F_87 ( V_295 ) ;
if ( V_294 )
F_87 ( V_294 ) ;
if ( V_296 )
F_85 ( V_296 ) ;
if ( V_297 )
F_85 ( V_297 ) ;
return V_17 ;
}
static int F_147 ( struct V_27 * V_28 ,
struct V_230 * V_231 ,
const struct V_286 * V_287 )
{
struct V_286 * V_288 ;
struct V_40 * V_156 ;
struct V_152 * V_154 = NULL ;
int V_17 = - 1 ;
V_156 = F_89 ( V_287 -> V_10 , V_207 ) ;
if ( ! V_156 )
goto V_46;
V_154 = F_86 ( V_156 , V_207 ) ;
if ( ! V_154 )
goto V_46;
V_288 = F_148 ( V_28 ) ;
F_117 ( V_231 , L_39 ,
( V_288 == V_287 ? L_40 : L_41 ) ,
V_287 -> V_10 -> V_63 ,
V_154 -> V_11 . V_160 , V_156 -> V_29 ,
V_156 -> V_91 -> V_64 -> V_96 ,
V_287 -> V_292 / 10 ,
V_287 -> V_292 % 10 ,
V_287 -> V_300 / 10 ,
V_287 -> V_300 % 10 ) ;
V_17 = F_149 ( V_231 ) ? - 1 : 0 ;
if ( V_288 )
F_145 ( V_288 ) ;
V_46:
if ( V_154 )
F_87 ( V_154 ) ;
if ( V_156 )
F_85 ( V_156 ) ;
return V_17 ;
}
static void F_150 ( struct V_27 * V_28 ,
struct V_230 * V_231 )
{
struct V_286 * V_287 ;
int V_301 = 0 ;
F_119 ( V_231 ,
L_42 ) ;
F_69 () ;
F_70 (gw_node, &bat_priv->gw.gateway_list, list) {
if ( F_147 ( V_28 , V_231 , V_287 ) < 0 )
continue;
V_301 ++ ;
}
F_73 () ;
if ( V_301 == 0 )
F_119 ( V_231 , L_43 ) ;
}
static int F_151 ( struct V_84 * V_238 , T_4 V_239 , T_4 V_231 ,
struct V_27 * V_28 ,
struct V_286 * V_287 )
{
struct V_152 * V_154 = NULL ;
struct V_40 * V_156 ;
struct V_286 * V_288 ;
int V_17 = - V_302 ;
void * V_241 ;
V_156 = F_89 ( V_287 -> V_10 , V_207 ) ;
if ( ! V_156 )
goto V_46;
V_154 = F_86 ( V_156 , V_207 ) ;
if ( ! V_154 )
goto V_46;
V_288 = F_148 ( V_28 ) ;
V_241 = F_123 ( V_238 , V_239 , V_231 , & V_242 ,
V_243 , V_303 ) ;
if ( ! V_241 ) {
V_17 = - V_245 ;
goto V_46;
}
V_17 = - V_255 ;
if ( V_288 == V_287 )
if ( F_127 ( V_238 , V_254 ) ) {
F_129 ( V_238 , V_241 ) ;
goto V_46;
}
if ( F_124 ( V_238 , V_246 , V_247 ,
V_287 -> V_10 -> V_63 ) ||
F_126 ( V_238 , V_251 , V_154 -> V_11 . V_160 ) ||
F_124 ( V_238 , V_304 , V_247 ,
V_156 -> V_29 ) ||
F_152 ( V_238 , V_305 ,
V_156 -> V_91 -> V_64 -> V_96 ) ||
F_125 ( V_238 , V_306 ,
V_287 -> V_292 ) ||
F_125 ( V_238 , V_307 ,
V_287 -> V_300 ) ) {
F_129 ( V_238 , V_241 ) ;
goto V_46;
}
F_128 ( V_238 , V_241 ) ;
V_17 = 0 ;
V_46:
if ( V_154 )
F_87 ( V_154 ) ;
if ( V_156 )
F_85 ( V_156 ) ;
return V_17 ;
}
static void F_153 ( struct V_84 * V_238 , struct V_262 * V_263 ,
struct V_27 * V_28 )
{
int V_239 = F_133 ( V_263 -> V_85 ) . V_239 ;
struct V_286 * V_287 ;
int V_308 = V_263 -> args [ 0 ] ;
int V_261 = 0 ;
F_69 () ;
F_70 (gw_node, &bat_priv->gw.gateway_list, list) {
if ( V_261 ++ < V_308 )
continue;
if ( F_151 ( V_238 , V_239 , V_263 -> V_265 -> V_266 ,
V_28 , V_287 ) ) {
V_308 = V_261 - 1 ;
goto V_22;
}
}
V_308 = V_261 ;
V_22:
F_73 () ;
V_263 -> args [ 0 ] = V_308 ;
}
int T_10 F_154 ( void )
{
int V_17 ;
V_17 = F_155 ( V_54 ,
F_112 ) ;
if ( V_17 < 0 )
goto V_46;
V_17 = F_156 ( & V_309 ) ;
if ( V_17 < 0 )
goto V_310;
goto V_46;
V_310:
F_157 ( V_54 ) ;
V_46:
return V_17 ;
}

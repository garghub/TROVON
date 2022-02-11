static void F_1 ( T_1 V_1 [] , T_1 * V_2 ,
T_1 V_3 )
{
V_1 [ * V_2 ] = V_3 ;
* V_2 = ( * V_2 + 1 ) % V_4 ;
}
static T_1 F_2 ( const T_1 V_1 [] )
{
const T_1 * V_5 ;
T_2 V_6 = 0 , V_7 = 0 , V_8 = 0 ;
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
T_3 V_16 , V_17 ;
int V_18 = - V_19 ;
F_6 ( & V_10 -> V_11 . V_20 ) ;
V_16 = V_14 * sizeof( unsigned long ) * V_21 ;
V_17 = ( V_14 - 1 ) * sizeof( unsigned long ) * V_21 ;
V_15 = F_7 ( V_16 , V_22 ) ;
if ( ! V_15 )
goto V_23;
memcpy ( V_15 , V_10 -> V_11 . V_12 , V_17 ) ;
F_4 ( V_10 -> V_11 . V_12 ) ;
V_10 -> V_11 . V_12 = V_15 ;
V_15 = F_7 ( V_14 * sizeof( T_1 ) , V_22 ) ;
if ( ! V_15 ) {
F_4 ( V_10 -> V_11 . V_12 ) ;
goto V_23;
}
memcpy ( V_15 , V_10 -> V_11 . V_13 ,
( V_14 - 1 ) * sizeof( T_1 ) ) ;
F_4 ( V_10 -> V_11 . V_13 ) ;
V_10 -> V_11 . V_13 = V_15 ;
V_18 = 0 ;
V_23:
F_8 ( & V_10 -> V_11 . V_20 ) ;
return V_18 ;
}
static int F_9 ( struct V_9 * V_10 ,
int V_14 , int V_24 )
{
int V_25 , V_18 = - V_19 , V_26 ;
void * V_15 = NULL ;
F_6 ( & V_10 -> V_11 . V_20 ) ;
if ( V_14 == 0 )
goto V_27;
V_25 = sizeof( unsigned long ) * V_21 ;
V_15 = F_7 ( V_14 * V_25 , V_22 ) ;
if ( ! V_15 )
goto V_23;
memcpy ( V_15 , V_10 -> V_11 . V_12 , V_24 * V_25 ) ;
memcpy ( ( char * ) V_15 + V_24 * V_25 ,
V_10 -> V_11 . V_12 + ( ( V_24 + 1 ) * V_25 ) ,
( V_14 - V_24 ) * V_25 ) ;
V_27:
F_4 ( V_10 -> V_11 . V_12 ) ;
V_10 -> V_11 . V_12 = V_15 ;
if ( V_14 == 0 )
goto V_28;
V_15 = F_7 ( V_14 * sizeof( T_1 ) , V_22 ) ;
if ( ! V_15 ) {
F_4 ( V_10 -> V_11 . V_12 ) ;
goto V_23;
}
memcpy ( V_15 , V_10 -> V_11 . V_13 ,
V_24 * sizeof( T_1 ) ) ;
V_26 = ( V_24 + 1 ) * sizeof( T_1 ) ;
memcpy ( ( char * ) V_15 + V_24 * sizeof( T_1 ) ,
V_10 -> V_11 . V_13 + V_26 ,
( V_14 - V_24 ) * sizeof( T_1 ) ) ;
V_28:
F_4 ( V_10 -> V_11 . V_13 ) ;
V_10 -> V_11 . V_13 = V_15 ;
V_18 = 0 ;
V_23:
F_8 ( & V_10 -> V_11 . V_20 ) ;
return V_18 ;
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
F_13 ( & V_10 -> V_11 . V_20 ) ;
V_32 = V_30 -> V_34 * sizeof( unsigned long ) * V_21 ;
V_10 -> V_11 . V_12 = F_14 ( V_32 , V_22 ) ;
if ( ! V_10 -> V_11 . V_12 )
goto V_35;
V_32 = V_30 -> V_34 * sizeof( T_1 ) ;
V_10 -> V_11 . V_13 = F_14 ( V_32 , V_22 ) ;
if ( ! V_10 -> V_11 . V_13 )
goto V_27;
V_33 = F_15 ( V_30 -> V_36 , V_37 ,
V_38 , V_10 ,
& V_10 -> V_39 ) ;
if ( V_33 != 0 )
goto V_27;
return V_10 ;
V_27:
F_4 ( V_10 -> V_11 . V_12 ) ;
V_35:
F_16 ( V_10 ) ;
return NULL ;
}
static struct V_40 *
F_17 ( struct V_41 * V_42 ,
const T_1 * V_43 ,
struct V_9 * V_10 ,
struct V_9 * V_44 )
{
struct V_29 * V_30 = F_18 ( V_42 -> V_45 ) ;
struct V_40 * V_46 ;
V_46 = F_19 ( V_42 , V_43 , V_10 ) ;
if ( ! V_46 )
goto V_47;
F_13 ( & V_46 -> V_11 . V_48 ) ;
F_20 ( V_49 , V_30 ,
L_1 ,
V_43 , V_10 -> V_50 , V_42 -> V_51 -> V_52 ) ;
F_6 ( & V_10 -> V_53 ) ;
F_21 ( & V_46 -> V_54 , & V_10 -> V_55 ) ;
F_8 ( & V_10 -> V_53 ) ;
V_47:
return V_46 ;
}
static int F_22 ( struct V_41 * V_42 )
{
struct V_56 * V_56 ;
unsigned char * V_57 ;
T_4 V_58 ;
int V_59 = - V_19 ;
F_23 ( & V_58 , sizeof( V_58 ) ) ;
F_24 ( & V_42 -> V_11 . V_60 , V_58 ) ;
V_42 -> V_11 . V_61 = V_62 ;
V_57 = F_7 ( V_42 -> V_11 . V_61 , V_22 ) ;
if ( ! V_57 )
goto V_47;
V_42 -> V_11 . V_57 = V_57 ;
V_56 = (struct V_56 * ) V_57 ;
V_56 -> V_63 = V_64 ;
V_56 -> V_65 = V_66 ;
V_56 -> V_67 = 2 ;
V_56 -> V_68 = V_69 ;
V_56 -> V_70 = 0 ;
V_56 -> V_71 = V_72 ;
V_59 = 0 ;
V_47:
return V_59 ;
}
static void F_25 ( struct V_41 * V_42 )
{
F_4 ( V_42 -> V_11 . V_57 ) ;
V_42 -> V_11 . V_57 = NULL ;
}
static void F_26 ( struct V_41 * V_42 )
{
struct V_56 * V_56 ;
unsigned char * V_57 = V_42 -> V_11 . V_57 ;
V_56 = (struct V_56 * ) V_57 ;
memcpy ( V_56 -> V_50 ,
V_42 -> V_51 -> V_73 , V_74 ) ;
memcpy ( V_56 -> V_75 ,
V_42 -> V_51 -> V_73 , V_74 ) ;
}
static void
F_27 ( struct V_41 * V_42 )
{
struct V_56 * V_56 ;
unsigned char * V_57 = V_42 -> V_11 . V_57 ;
V_56 = (struct V_56 * ) V_57 ;
V_56 -> V_68 = V_76 ;
V_56 -> V_67 = V_77 ;
}
static unsigned long
F_28 ( const struct V_29 * V_30 )
{
unsigned int V_78 ;
V_78 = F_29 ( & V_30 -> V_79 ) - V_80 ;
V_78 += F_30 () % ( 2 * V_80 ) ;
return V_81 + F_31 ( V_78 ) ;
}
static unsigned long F_32 ( void )
{
return V_81 + F_31 ( F_30 () % ( V_80 / 2 ) ) ;
}
static T_1 F_33 ( T_1 V_71 ,
const struct V_29 * V_30 )
{
int V_82 = F_29 ( & V_30 -> V_82 ) ;
int V_83 ;
V_83 = V_71 * ( V_72 - V_82 ) ;
V_83 /= V_72 ;
return V_83 ;
}
static int F_34 ( int V_84 , int V_85 ,
T_5 V_86 )
{
int V_87 = 0 ;
V_87 += V_84 + V_62 ;
V_87 += F_35 ( V_86 ) ;
return ( V_87 <= V_85 ) &&
( V_87 <= V_88 ) ;
}
static void F_36 ( struct V_89 * V_90 ,
struct V_41 * V_42 )
{
struct V_29 * V_30 = F_18 ( V_42 -> V_45 ) ;
char * V_91 ;
T_1 V_92 ;
T_6 V_84 ;
struct V_56 * V_56 ;
struct V_93 * V_94 ;
T_1 * V_95 ;
if ( V_42 -> V_96 != V_97 )
return;
V_92 = 0 ;
V_84 = 0 ;
V_95 = V_90 -> V_94 -> V_98 ;
V_56 = (struct V_56 * ) V_95 ;
while ( F_34 ( V_84 , V_90 -> V_85 ,
V_56 -> V_86 ) ) {
if ( V_90 -> V_99 & F_37 ( V_92 ) &&
V_90 -> V_100 == V_42 )
V_56 -> V_68 |= V_101 ;
else
V_56 -> V_68 &= ~ V_101 ;
if ( V_92 > 0 || ! V_90 -> V_102 )
V_91 = L_2 ;
else
V_91 = L_3 ;
F_20 ( V_49 , V_30 ,
L_4 ,
V_91 , ( V_92 > 0 ? L_5 : L_6 ) ,
V_56 -> V_50 ,
F_38 ( V_56 -> V_103 ) ,
V_56 -> V_71 , V_56 -> V_67 ,
( V_56 -> V_68 & V_101 ?
L_7 : L_8 ) ,
V_42 -> V_51 -> V_52 ,
V_42 -> V_51 -> V_73 ) ;
V_84 += V_62 ;
V_84 += F_35 ( V_56 -> V_86 ) ;
V_92 ++ ;
V_95 = V_90 -> V_94 -> V_98 + V_84 ;
V_56 = (struct V_56 * ) V_95 ;
}
V_94 = F_39 ( V_90 -> V_94 , V_22 ) ;
if ( V_94 ) {
F_40 ( V_30 , V_104 ) ;
F_41 ( V_30 , V_105 ,
V_94 -> V_106 + V_107 ) ;
F_42 ( V_94 , V_42 , V_108 ) ;
}
}
static void F_43 ( struct V_89 * V_90 )
{
struct V_41 * V_42 ;
struct V_109 * V_45 ;
struct V_29 * V_30 ;
struct V_41 * V_110 = NULL ;
struct V_56 * V_56 ;
unsigned char V_111 ;
T_1 * V_95 ;
V_95 = V_90 -> V_94 -> V_98 ;
V_56 = (struct V_56 * ) V_95 ;
V_111 = ( V_56 -> V_68 & V_101 ? 1 : 0 ) ;
if ( ! V_90 -> V_100 ) {
F_44 ( L_9 ) ;
goto V_47;
}
V_45 = V_90 -> V_100 -> V_45 ;
V_30 = F_18 ( V_45 ) ;
if ( V_90 -> V_100 -> V_96 != V_97 )
goto V_47;
V_110 = F_45 ( V_30 ) ;
if ( ! V_110 )
goto V_47;
if ( ( V_111 && ( V_56 -> V_67 == 1 ) ) ||
( V_90 -> V_102 && ( V_90 -> V_100 != V_110 ) ) ) {
F_20 ( V_49 , V_30 ,
L_10 ,
( V_90 -> V_102 ? L_3 : L_2 ) ,
V_56 -> V_50 ,
F_38 ( V_56 -> V_103 ) ,
V_56 -> V_67 ,
V_90 -> V_100 -> V_51 -> V_52 ,
V_90 -> V_100 -> V_51 -> V_73 ) ;
F_42 ( V_90 -> V_94 ,
V_90 -> V_100 ,
V_108 ) ;
V_90 -> V_94 = NULL ;
goto V_47;
}
F_46 () ;
F_47 (hard_iface, &batadv_hardif_list, list) {
if ( V_42 -> V_45 != V_45 )
continue;
F_36 ( V_90 , V_42 ) ;
}
F_48 () ;
V_47:
if ( V_110 )
F_49 ( V_110 ) ;
}
static bool
F_50 ( const struct V_56 * V_112 ,
struct V_29 * V_30 ,
int V_85 , unsigned long V_113 ,
bool V_111 ,
const struct V_41 * V_100 ,
const struct V_89 * V_90 )
{
struct V_56 * V_56 ;
int V_114 = V_90 -> V_85 + V_85 ;
struct V_41 * V_110 = NULL ;
bool V_59 = false ;
unsigned long V_115 ;
V_56 = (struct V_56 * ) V_90 -> V_94 -> V_98 ;
V_115 = V_113 ;
V_115 += F_31 ( V_116 ) ;
if ( F_51 ( V_113 , V_90 -> V_113 ) &&
F_52 ( V_115 , V_90 -> V_113 ) &&
( V_114 <= V_88 ) ) {
V_110 = F_45 ( V_30 ) ;
if ( ! V_110 )
goto V_47;
if ( ( ! V_111 ) &&
( ! ( V_56 -> V_68 & V_101 ) ) &&
( V_56 -> V_67 != 1 ) &&
( ( ! V_90 -> V_102 ) ||
( V_90 -> V_100 == V_110 ) ) ) {
V_59 = true ;
goto V_47;
}
if ( ( V_111 ) &&
( V_112 -> V_67 == 1 ) &&
( V_90 -> V_100 == V_100 ) &&
( V_56 -> V_68 & V_101 ||
( V_90 -> V_102 &&
V_90 -> V_100 != V_110 ) ) ) {
V_59 = true ;
goto V_47;
}
}
V_47:
if ( V_110 )
F_49 ( V_110 ) ;
return V_59 ;
}
static void F_53 ( const unsigned char * V_117 ,
int V_85 , unsigned long V_113 ,
bool V_118 ,
struct V_41 * V_100 ,
int V_119 )
{
struct V_29 * V_30 = F_18 ( V_100 -> V_45 ) ;
struct V_89 * V_120 ;
unsigned char * V_121 ;
unsigned int V_122 ;
if ( ! F_54 ( & V_100 -> V_123 ) )
return;
if ( ! V_119 ) {
if ( ! F_55 ( & V_30 -> V_124 ) ) {
F_20 ( V_49 , V_30 ,
L_11 ) ;
goto V_47;
}
}
V_120 = F_7 ( sizeof( * V_120 ) , V_22 ) ;
if ( ! V_120 ) {
if ( ! V_119 )
F_56 ( & V_30 -> V_124 ) ;
goto V_47;
}
if ( ( F_29 ( & V_30 -> V_125 ) ) &&
( V_85 < V_88 ) )
V_122 = V_88 ;
else
V_122 = V_85 ;
V_122 += V_107 ;
V_120 -> V_94 = F_57 ( NULL , V_122 ) ;
if ( ! V_120 -> V_94 ) {
if ( ! V_119 )
F_56 ( & V_30 -> V_124 ) ;
F_4 ( V_120 ) ;
goto V_47;
}
V_120 -> V_94 -> V_126 = V_127 ;
F_58 ( V_120 -> V_94 , V_107 ) ;
V_121 = F_59 ( V_120 -> V_94 , V_85 ) ;
V_120 -> V_85 = V_85 ;
memcpy ( V_121 , V_117 , V_85 ) ;
V_120 -> V_102 = V_119 ;
V_120 -> V_100 = V_100 ;
V_120 -> V_128 = 0 ;
V_120 -> V_99 = V_69 ;
V_120 -> V_113 = V_113 ;
if ( V_118 )
V_120 -> V_99 |= 1 ;
F_6 ( & V_30 -> V_129 ) ;
F_60 ( & V_120 -> V_54 , & V_30 -> V_130 ) ;
F_8 ( & V_30 -> V_129 ) ;
F_61 ( & V_120 -> V_131 ,
V_132 ) ;
F_62 ( V_133 ,
& V_120 -> V_131 ,
V_113 - V_81 ) ;
return;
V_47:
F_49 ( V_100 ) ;
}
static void F_63 ( struct V_89 * V_120 ,
const unsigned char * V_117 ,
int V_85 , bool V_118 )
{
unsigned char * V_121 ;
unsigned long V_134 ;
V_121 = F_59 ( V_120 -> V_94 , V_85 ) ;
memcpy ( V_121 , V_117 , V_85 ) ;
V_120 -> V_85 += V_85 ;
V_120 -> V_128 ++ ;
if ( V_118 ) {
V_134 = F_37 ( V_120 -> V_128 ) ;
V_120 -> V_99 |= V_134 ;
}
}
static void F_64 ( struct V_29 * V_30 ,
unsigned char * V_117 ,
int V_85 ,
struct V_41 * V_100 ,
int V_119 , unsigned long V_113 )
{
struct V_89 * V_120 = NULL ;
struct V_89 * V_135 = NULL ;
struct V_56 * V_56 ;
bool V_118 ;
unsigned long V_136 ;
V_56 = (struct V_56 * ) V_117 ;
V_118 = V_56 -> V_68 & V_101 ? 1 : 0 ;
V_136 = F_31 ( V_116 ) ;
F_6 ( & V_30 -> V_129 ) ;
if ( ( F_29 ( & V_30 -> V_125 ) ) && ( ! V_119 ) ) {
F_65 (forw_packet_pos,
&bat_priv->forw_bat_list, list) {
if ( F_50 ( V_56 ,
V_30 , V_85 ,
V_113 , V_118 ,
V_100 ,
V_135 ) ) {
V_120 = V_135 ;
break;
}
}
}
if ( ! V_120 ) {
F_8 ( & V_30 -> V_129 ) ;
if ( ! V_119 && F_29 ( & V_30 -> V_125 ) )
V_113 += V_136 ;
F_53 ( V_117 , V_85 ,
V_113 , V_118 ,
V_100 , V_119 ) ;
} else {
F_63 ( V_120 , V_117 ,
V_85 , V_118 ) ;
F_8 ( & V_30 -> V_129 ) ;
}
}
static void F_66 ( struct V_9 * V_10 ,
const struct V_137 * V_137 ,
struct V_56 * V_56 ,
bool V_138 ,
bool V_139 ,
struct V_41 * V_100 )
{
struct V_29 * V_30 = F_18 ( V_100 -> V_45 ) ;
T_2 V_86 ;
if ( V_56 -> V_67 <= 1 ) {
F_20 ( V_49 , V_30 , L_12 ) ;
return;
}
if ( ! V_139 ) {
if ( V_138 )
V_56 -> V_68 |= V_140 ;
else
return;
}
V_86 = F_35 ( V_56 -> V_86 ) ;
V_56 -> V_67 -- ;
memcpy ( V_56 -> V_75 , V_137 -> V_141 , V_74 ) ;
V_56 -> V_71 = F_33 ( V_56 -> V_71 ,
V_30 ) ;
F_20 ( V_49 , V_30 ,
L_13 ,
V_56 -> V_71 , V_56 -> V_67 ) ;
V_56 -> V_68 &= ~ V_76 ;
if ( V_138 )
V_56 -> V_68 |= V_101 ;
else
V_56 -> V_68 &= ~ V_101 ;
F_64 ( V_30 , ( unsigned char * ) V_56 ,
V_62 + V_86 ,
V_100 , 0 , F_32 () ) ;
}
static void
F_67 ( struct V_41 * V_42 )
{
struct V_29 * V_30 = F_18 ( V_42 -> V_45 ) ;
struct V_142 * V_143 = V_30 -> V_36 ;
struct V_144 * V_145 ;
struct V_9 * V_10 ;
unsigned long * V_146 ;
T_4 V_7 ;
T_3 V_147 ;
T_1 * V_148 ;
int V_149 ;
for ( V_7 = 0 ; V_7 < V_143 -> V_32 ; V_7 ++ ) {
V_145 = & V_143 -> V_150 [ V_7 ] ;
F_46 () ;
F_68 (orig_node, head, hash_entry) {
F_6 ( & V_10 -> V_11 . V_20 ) ;
V_147 = V_42 -> V_149 * V_21 ;
V_146 = & ( V_10 -> V_11 . V_12 [ V_147 ] ) ;
F_69 ( V_30 , V_146 , 1 , 0 ) ;
V_149 = V_42 -> V_149 ;
V_148 = & V_10 -> V_11 . V_13 [ V_149 ] ;
* V_148 = F_70 ( V_146 , V_151 ) ;
F_8 ( & V_10 -> V_11 . V_20 ) ;
}
F_48 () ;
}
}
static void F_71 ( struct V_41 * V_42 )
{
struct V_29 * V_30 = F_18 ( V_42 -> V_45 ) ;
unsigned char * * V_57 = & V_42 -> V_11 . V_57 ;
struct V_56 * V_56 ;
struct V_41 * V_110 ;
int * V_61 = & V_42 -> V_11 . V_61 ;
T_4 V_103 ;
T_2 V_86 = 0 ;
V_110 = F_45 ( V_30 ) ;
if ( V_42 == V_110 ) {
F_72 ( V_30 ) ;
V_86 = F_73 ( V_30 , V_57 ,
V_61 ,
V_62 ) ;
}
V_56 = (struct V_56 * ) ( * V_57 ) ;
V_56 -> V_86 = F_74 ( V_86 ) ;
V_103 = ( T_4 ) F_29 ( & V_42 -> V_11 . V_60 ) ;
V_56 -> V_103 = F_75 ( V_103 ) ;
F_56 ( & V_42 -> V_11 . V_60 ) ;
F_67 ( V_42 ) ;
F_64 ( V_30 , V_42 -> V_11 . V_57 ,
V_42 -> V_11 . V_61 , V_42 , 1 ,
F_28 ( V_30 ) ) ;
if ( V_110 )
F_49 ( V_110 ) ;
}
static void
F_76 ( struct V_29 * V_30 ,
struct V_9 * V_10 ,
const struct V_137 * V_137 ,
const struct V_56 * V_56 ,
struct V_41 * V_100 ,
const unsigned char * V_152 ,
enum V_153 V_154 )
{
struct V_40 * V_46 = NULL , * V_155 = NULL ;
struct V_40 * V_156 = NULL ;
struct V_9 * V_157 ;
int V_149 ;
T_1 V_158 , V_159 ;
T_1 * V_43 ;
T_1 V_160 ;
F_20 ( V_49 , V_30 ,
L_14 ) ;
F_46 () ;
F_68 (tmp_neigh_node,
&orig_node->neigh_list, list) {
V_43 = V_155 -> V_31 ;
if ( F_77 ( V_43 , V_137 -> V_141 ) &&
V_155 -> V_100 == V_100 &&
F_54 ( & V_155 -> V_123 ) ) {
if ( F_78 ( V_46 , L_15 ) )
F_79 ( V_46 ) ;
V_46 = V_155 ;
continue;
}
if ( V_154 != V_161 )
continue;
F_6 ( & V_155 -> V_11 . V_48 ) ;
F_1 ( V_155 -> V_11 . V_162 ,
& V_155 -> V_11 . V_163 , 0 ) ;
V_160 = F_2 ( V_155 -> V_11 . V_162 ) ;
V_155 -> V_11 . V_160 = V_160 ;
F_8 ( & V_155 -> V_11 . V_48 ) ;
}
if ( ! V_46 ) {
struct V_9 * V_164 ;
V_164 = F_10 ( V_30 , V_137 -> V_141 ) ;
if ( ! V_164 )
goto V_23;
V_46 = F_17 ( V_100 ,
V_137 -> V_141 ,
V_10 , V_164 ) ;
F_16 ( V_164 ) ;
if ( ! V_46 )
goto V_23;
} else
F_20 ( V_49 , V_30 ,
L_16 ) ;
F_48 () ;
V_46 -> V_165 = V_81 ;
F_6 ( & V_46 -> V_11 . V_48 ) ;
F_1 ( V_46 -> V_11 . V_162 ,
& V_46 -> V_11 . V_163 ,
V_56 -> V_71 ) ;
V_160 = F_2 ( V_46 -> V_11 . V_162 ) ;
V_46 -> V_11 . V_160 = V_160 ;
F_8 ( & V_46 -> V_11 . V_48 ) ;
if ( V_154 == V_161 ) {
V_10 -> V_166 = V_56 -> V_67 ;
V_46 -> V_166 = V_56 -> V_67 ;
}
F_80 ( V_30 , V_10 , V_46 ) ;
V_156 = F_81 ( V_10 ) ;
if ( V_156 == V_46 )
goto V_47;
if ( V_156 && ( V_156 -> V_11 . V_160 > V_46 -> V_11 . V_160 ) )
goto V_47;
if ( V_156 && ( V_46 -> V_11 . V_160 == V_156 -> V_11 . V_160 ) ) {
V_157 = V_156 -> V_10 ;
F_6 ( & V_157 -> V_11 . V_20 ) ;
V_149 = V_156 -> V_100 -> V_149 ;
V_158 = V_157 -> V_11 . V_13 [ V_149 ] ;
F_8 ( & V_157 -> V_11 . V_20 ) ;
V_157 = V_46 -> V_10 ;
F_6 ( & V_157 -> V_11 . V_20 ) ;
V_149 = V_46 -> V_100 -> V_149 ;
V_159 = V_157 -> V_11 . V_13 [ V_149 ] ;
F_8 ( & V_157 -> V_11 . V_20 ) ;
if ( V_158 >= V_159 )
goto V_47;
}
F_82 ( V_30 , V_10 , V_46 ) ;
goto V_47;
V_23:
F_48 () ;
V_47:
if ( V_46 )
F_79 ( V_46 ) ;
if ( V_156 )
F_79 ( V_156 ) ;
}
static int F_83 ( struct V_9 * V_10 ,
struct V_9 * V_167 ,
struct V_56 * V_56 ,
struct V_41 * V_100 )
{
struct V_29 * V_30 = F_18 ( V_100 -> V_45 ) ;
struct V_40 * V_46 = NULL , * V_155 ;
T_1 V_168 ;
T_1 V_169 , V_170 , V_171 , V_172 ;
unsigned int V_173 , V_174 ;
int V_175 , V_176 , V_149 , V_18 = 0 ;
unsigned int V_177 ;
F_46 () ;
F_68 (tmp_neigh_node,
&orig_neigh_node->neigh_list, list) {
if ( ! F_77 ( V_155 -> V_31 ,
V_167 -> V_50 ) )
continue;
if ( V_155 -> V_100 != V_100 )
continue;
if ( ! F_54 ( & V_155 -> V_123 ) )
continue;
V_46 = V_155 ;
break;
}
F_48 () ;
if ( ! V_46 )
V_46 = F_17 ( V_100 ,
V_167 -> V_50 ,
V_167 ,
V_167 ) ;
if ( ! V_46 )
goto V_47;
if ( V_10 == V_167 )
V_46 -> V_165 = V_81 ;
V_10 -> V_165 = V_81 ;
F_6 ( & V_10 -> V_11 . V_20 ) ;
V_149 = V_100 -> V_149 ;
V_169 = V_167 -> V_11 . V_13 [ V_149 ] ;
V_170 = V_46 -> V_11 . V_178 ;
F_8 ( & V_10 -> V_11 . V_20 ) ;
if ( V_169 > V_170 )
V_168 = V_170 ;
else
V_168 = V_169 ;
if ( V_168 < V_179 ||
V_170 < V_180 )
V_172 = 0 ;
else
V_172 = ( V_72 * V_168 ) / V_170 ;
V_171 = V_151 - V_170 ;
V_173 = V_171 * V_171 * V_171 ;
V_174 = V_151 *
V_151 *
V_151 ;
V_176 = V_72 * V_173 ;
V_176 /= V_174 ;
V_175 = V_72 - V_176 ;
V_177 = V_56 -> V_71 * V_172 * V_175 ;
V_177 /= V_72 * V_72 ;
V_56 -> V_71 = V_177 ;
F_20 ( V_49 , V_30 ,
L_17 ,
V_10 -> V_50 , V_167 -> V_50 , V_168 ,
V_170 , V_172 ,
V_175 , V_56 -> V_71 ) ;
if ( V_56 -> V_71 >= V_181 )
V_18 = 1 ;
V_47:
if ( V_46 )
F_79 ( V_46 ) ;
return V_18 ;
}
static enum V_153
F_84 ( const struct V_137 * V_137 ,
const struct V_56 * V_56 ,
const struct V_41 * V_100 )
{
struct V_29 * V_30 = F_18 ( V_100 -> V_45 ) ;
struct V_9 * V_10 ;
struct V_40 * V_155 ;
int V_182 ;
T_7 V_183 ;
int V_184 = 0 ;
int V_185 ;
enum V_153 V_18 = V_161 ;
T_4 V_103 = F_38 ( V_56 -> V_103 ) ;
T_1 * V_43 ;
T_1 V_186 ;
unsigned long * V_187 ;
V_10 = F_10 ( V_30 , V_56 -> V_50 ) ;
if ( ! V_10 )
return V_161 ;
F_6 ( & V_10 -> V_11 . V_20 ) ;
V_183 = V_103 - V_10 -> V_188 ;
if ( ! F_85 ( & V_10 -> V_55 ) &&
F_86 ( V_30 , V_183 ,
& V_10 -> V_189 ) ) {
V_18 = V_190 ;
goto V_47;
}
F_46 () ;
F_68 (tmp_neigh_node,
&orig_node->neigh_list, list) {
V_43 = V_155 -> V_31 ;
V_182 = F_87 ( V_155 -> V_11 . V_191 ,
V_10 -> V_188 ,
V_103 ) ;
if ( F_77 ( V_43 , V_137 -> V_141 ) &&
V_155 -> V_100 == V_100 ) {
V_185 = 1 ;
if ( V_182 )
V_18 = V_192 ;
} else {
V_185 = 0 ;
if ( V_182 && ( V_18 != V_192 ) )
V_18 = V_193 ;
}
V_187 = V_155 -> V_11 . V_191 ;
V_184 |= F_69 ( V_30 , V_187 ,
V_183 , V_185 ) ;
V_186 = F_70 ( V_155 -> V_11 . V_191 ,
V_151 ) ;
V_155 -> V_11 . V_178 = V_186 ;
}
F_48 () ;
if ( V_184 ) {
F_20 ( V_49 , V_30 ,
L_18 ,
V_10 -> V_188 , V_103 ) ;
V_10 -> V_188 = V_103 ;
}
V_47:
F_8 ( & V_10 -> V_11 . V_20 ) ;
F_16 ( V_10 ) ;
return V_18 ;
}
static void F_88 ( const struct V_137 * V_137 ,
struct V_56 * V_56 ,
const unsigned char * V_152 ,
struct V_41 * V_100 )
{
struct V_29 * V_30 = F_18 ( V_100 -> V_45 ) ;
struct V_41 * V_42 ;
struct V_9 * V_167 , * V_10 , * V_157 ;
struct V_40 * V_156 = NULL , * V_194 = NULL ;
struct V_40 * V_195 = NULL ;
int V_196 ;
int V_197 = 0 , V_198 = 0 , V_199 = 0 ;
int V_200 ;
bool V_138 = false ;
bool V_139 = false ;
int V_201 , V_202 ;
enum V_153 V_154 ;
T_4 V_203 ;
T_1 * V_75 ;
if ( V_56 -> V_63 != V_64 )
return;
V_203 = F_29 ( & V_100 -> V_11 . V_60 ) ;
if ( V_56 -> V_68 & V_101 )
V_196 = 1 ;
else
V_196 = 0 ;
if ( F_77 ( V_137 -> V_141 , V_56 -> V_50 ) )
V_138 = true ;
F_20 ( V_49 , V_30 ,
L_19 ,
V_137 -> V_141 , V_100 -> V_51 -> V_52 ,
V_100 -> V_51 -> V_73 , V_56 -> V_50 ,
V_56 -> V_75 ,
F_38 ( V_56 -> V_103 ) , V_56 -> V_71 ,
V_56 -> V_67 ,
V_56 -> V_65 , V_196 ) ;
F_46 () ;
F_47 (hard_iface, &batadv_hardif_list, list) {
if ( V_42 -> V_96 != V_97 )
continue;
if ( V_42 -> V_45 != V_100 -> V_45 )
continue;
if ( F_77 ( V_137 -> V_141 ,
V_42 -> V_51 -> V_73 ) )
V_197 = 1 ;
if ( F_77 ( V_56 -> V_50 ,
V_42 -> V_51 -> V_73 ) )
V_198 = 1 ;
if ( F_77 ( V_56 -> V_75 ,
V_42 -> V_51 -> V_73 ) )
V_199 = 1 ;
}
F_48 () ;
if ( V_197 ) {
F_20 ( V_49 , V_30 ,
L_20 ,
V_137 -> V_141 ) ;
return;
}
if ( V_198 ) {
unsigned long * V_146 ;
int V_204 ;
T_7 V_205 ;
T_6 V_149 ;
T_1 * V_206 ;
V_167 = F_10 ( V_30 ,
V_137 -> V_141 ) ;
if ( ! V_167 )
return;
if ( V_196 &&
F_77 ( V_100 -> V_51 -> V_73 ,
V_56 -> V_50 ) ) {
V_149 = V_100 -> V_149 ;
V_204 = V_149 * V_21 ;
F_6 ( & V_167 -> V_11 . V_20 ) ;
V_146 = & ( V_167 -> V_11 . V_12 [ V_204 ] ) ;
V_205 = V_203 - 2 ;
V_205 -= F_38 ( V_56 -> V_103 ) ;
F_89 ( V_146 , V_205 ) ;
V_206 = & V_167 -> V_11 . V_13 [ V_149 ] ;
* V_206 = F_70 ( V_146 ,
V_151 ) ;
F_8 ( & V_167 -> V_11 . V_20 ) ;
}
F_20 ( V_49 , V_30 ,
L_21 ) ;
F_16 ( V_167 ) ;
return;
}
if ( V_199 ) {
F_20 ( V_49 , V_30 ,
L_22 ,
V_137 -> V_141 ) ;
return;
}
if ( V_56 -> V_68 & V_140 ) {
F_20 ( V_49 , V_30 ,
L_23 ,
V_137 -> V_141 ) ;
return;
}
V_10 = F_10 ( V_30 , V_56 -> V_50 ) ;
if ( ! V_10 )
return;
V_154 = F_84 ( V_137 , V_56 ,
V_100 ) ;
if ( V_154 == V_190 ) {
F_20 ( V_49 , V_30 ,
L_24 ,
V_137 -> V_141 ) ;
goto V_47;
}
if ( V_56 -> V_71 == 0 ) {
F_20 ( V_49 , V_30 ,
L_25 ) ;
goto V_47;
}
V_156 = F_81 ( V_10 ) ;
if ( V_156 ) {
V_157 = V_156 -> V_10 ;
V_194 = F_81 ( V_157 ) ;
}
if ( ( V_156 && V_156 -> V_11 . V_160 != 0 ) &&
( F_77 ( V_156 -> V_31 , V_137 -> V_141 ) ) )
V_139 = true ;
V_75 = V_56 -> V_75 ;
if ( V_156 && V_194 &&
( F_77 ( V_156 -> V_31 , V_75 ) ) &&
! ( F_77 ( V_56 -> V_50 , V_75 ) ) &&
( F_77 ( V_156 -> V_31 , V_194 -> V_31 ) ) ) {
F_20 ( V_49 , V_30 ,
L_26 ,
V_137 -> V_141 ) ;
goto V_47;
}
F_90 ( V_30 , V_56 , V_10 ) ;
if ( V_138 )
V_167 = V_10 ;
else
V_167 = F_10 ( V_30 ,
V_137 -> V_141 ) ;
if ( ! V_167 )
goto V_47;
F_91 ( V_30 , V_10 , V_167 ,
V_56 , V_138 ) ;
V_195 = F_81 ( V_167 ) ;
if ( ! V_138 && ( ! V_195 ) ) {
F_20 ( V_49 , V_30 ,
L_27 ) ;
goto V_207;
}
V_200 = F_83 ( V_10 , V_167 ,
V_56 , V_100 ) ;
F_92 ( V_10 , V_167 ,
V_56 ) ;
V_201 = V_10 -> V_188 == F_38 ( V_56 -> V_103 ) ;
V_202 = V_10 -> V_166 - 3 <= V_56 -> V_67 ;
if ( V_200 && ( ( V_154 == V_161 ) ||
( V_201 && V_202 ) ) )
F_76 ( V_30 , V_10 , V_137 ,
V_56 , V_100 ,
V_152 , V_154 ) ;
if ( V_138 ) {
F_66 ( V_10 , V_137 , V_56 ,
V_138 ,
V_139 , V_100 ) ;
F_20 ( V_49 , V_30 ,
L_28 ) ;
goto V_207;
}
if ( ! V_200 ) {
F_20 ( V_49 , V_30 ,
L_29 ) ;
goto V_207;
}
if ( V_154 == V_192 ) {
F_20 ( V_49 , V_30 ,
L_30 ) ;
goto V_207;
}
F_20 ( V_49 , V_30 ,
L_31 ) ;
F_66 ( V_10 , V_137 , V_56 ,
V_138 , V_139 ,
V_100 ) ;
V_207:
if ( ( V_167 ) && ( ! V_138 ) )
F_16 ( V_167 ) ;
V_47:
if ( V_156 )
F_79 ( V_156 ) ;
if ( V_194 )
F_79 ( V_194 ) ;
if ( V_195 )
F_79 ( V_195 ) ;
F_16 ( V_10 ) ;
}
static int F_93 ( struct V_93 * V_94 ,
struct V_41 * V_100 )
{
struct V_29 * V_30 = F_18 ( V_100 -> V_45 ) ;
struct V_56 * V_56 ;
struct V_137 * V_137 ;
int V_84 = 0 , V_85 ;
unsigned char * V_208 , * V_117 ;
T_1 * V_95 ;
bool V_18 ;
V_18 = F_94 ( V_94 , V_100 , V_62 ) ;
if ( ! V_18 )
return V_209 ;
if ( V_30 -> V_210 -> V_211 != F_43 )
return V_209 ;
F_40 ( V_30 , V_212 ) ;
F_41 ( V_30 , V_213 ,
V_94 -> V_106 + V_107 ) ;
V_85 = F_95 ( V_94 ) ;
V_137 = F_96 ( V_94 ) ;
V_117 = V_94 -> V_98 ;
V_56 = (struct V_56 * ) V_117 ;
while ( F_34 ( V_84 , V_85 ,
V_56 -> V_86 ) ) {
V_208 = V_117 + V_84 + V_62 ;
F_88 ( V_137 , V_56 ,
V_208 , V_100 ) ;
V_84 += V_62 ;
V_84 += F_35 ( V_56 -> V_86 ) ;
V_95 = V_117 + V_84 ;
V_56 = (struct V_56 * ) V_95 ;
}
F_97 ( V_94 ) ;
return V_214 ;
}
static void F_98 ( struct V_29 * V_30 ,
struct V_215 * V_216 )
{
struct V_40 * V_46 , * V_217 ;
struct V_142 * V_143 = V_30 -> V_36 ;
int V_218 , V_219 ;
struct V_9 * V_10 ;
unsigned long V_220 ;
struct V_144 * V_145 ;
int V_221 = 0 ;
T_4 V_7 ;
F_99 ( V_216 , L_32 ,
L_33 , L_34 , L_35 , V_72 ,
L_36 , L_37 , L_38 ) ;
for ( V_7 = 0 ; V_7 < V_143 -> V_32 ; V_7 ++ ) {
V_145 = & V_143 -> V_150 [ V_7 ] ;
F_46 () ;
F_68 (orig_node, head, hash_entry) {
V_46 = F_81 ( V_10 ) ;
if ( ! V_46 )
continue;
if ( V_46 -> V_11 . V_160 == 0 )
goto V_222;
V_220 = V_81 - V_10 -> V_165 ;
V_218 = F_100 ( V_220 ) ;
V_219 = V_218 / 1000 ;
V_218 = V_218 % 1000 ;
F_99 ( V_216 , L_39 ,
V_10 -> V_50 , V_219 ,
V_218 , V_46 -> V_11 . V_160 ,
V_46 -> V_31 ,
V_46 -> V_100 -> V_51 -> V_52 ) ;
F_68 (neigh_node_tmp,
&orig_node->neigh_list, list) {
F_99 ( V_216 , L_40 ,
V_217 -> V_31 ,
V_217 -> V_11 . V_160 ) ;
}
F_101 ( V_216 , L_41 ) ;
V_221 ++ ;
V_222:
F_79 ( V_46 ) ;
}
F_48 () ;
}
if ( V_221 == 0 )
F_101 ( V_216 , L_42 ) ;
}
static int F_102 ( struct V_40 * V_223 ,
struct V_40 * V_224 )
{
T_1 V_225 , V_226 ;
V_225 = V_223 -> V_11 . V_160 ;
V_226 = V_224 -> V_11 . V_160 ;
return V_225 - V_226 ;
}
static bool F_103 ( struct V_40 * V_223 ,
struct V_40 * V_224 )
{
int V_227 = F_102 ( V_223 , V_224 ) ;
return V_227 > - V_228 ;
}
int T_8 F_104 ( void )
{
int V_18 ;
V_18 = F_105 ( V_64 ,
F_93 ) ;
if ( V_18 < 0 )
goto V_47;
V_18 = F_106 ( & V_229 ) ;
if ( V_18 < 0 )
goto V_230;
goto V_47;
V_230:
F_107 ( V_64 ) ;
V_47:
return V_18 ;
}

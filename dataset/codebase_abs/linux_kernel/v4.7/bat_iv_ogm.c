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
V_31 = F_18 ( V_28 -> V_34 , V_35 ,
V_36 , V_10 ,
& V_10 -> V_37 ) ;
if ( V_31 != 0 )
goto V_33;
return V_10 ;
V_33:
F_19 ( V_10 ) ;
F_19 ( V_10 ) ;
return NULL ;
}
static struct V_38 *
F_20 ( struct V_39 * V_40 ,
const T_1 * V_41 ,
struct V_9 * V_10 ,
struct V_9 * V_42 )
{
struct V_38 * V_43 ;
V_43 = F_21 ( V_10 , V_40 , V_41 ) ;
if ( ! V_43 )
goto V_44;
V_43 -> V_10 = V_42 ;
V_44:
return V_43 ;
}
static int F_22 ( struct V_39 * V_40 )
{
struct V_45 * V_45 ;
unsigned char * V_46 ;
T_4 V_47 ;
F_23 ( & V_47 , sizeof( V_47 ) ) ;
F_24 ( & V_40 -> V_11 . V_48 , V_47 ) ;
V_40 -> V_11 . V_49 = V_50 ;
V_46 = F_25 ( V_40 -> V_11 . V_49 , V_21 ) ;
if ( ! V_46 )
return - V_18 ;
V_40 -> V_11 . V_46 = V_46 ;
V_45 = (struct V_45 * ) V_46 ;
V_45 -> V_51 = V_52 ;
V_45 -> V_53 = V_54 ;
V_45 -> V_55 = 2 ;
V_45 -> V_56 = V_57 ;
V_45 -> V_58 = 0 ;
V_45 -> V_59 = V_60 ;
return 0 ;
}
static void F_26 ( struct V_39 * V_40 )
{
F_4 ( V_40 -> V_11 . V_46 ) ;
V_40 -> V_11 . V_46 = NULL ;
}
static void F_27 ( struct V_39 * V_40 )
{
struct V_45 * V_45 ;
unsigned char * V_46 = V_40 -> V_11 . V_46 ;
V_45 = (struct V_45 * ) V_46 ;
F_28 ( V_45 -> V_61 ,
V_40 -> V_62 -> V_63 ) ;
F_28 ( V_45 -> V_64 ,
V_40 -> V_62 -> V_63 ) ;
}
static void
F_29 ( struct V_39 * V_40 )
{
struct V_45 * V_45 ;
unsigned char * V_46 = V_40 -> V_11 . V_46 ;
V_45 = (struct V_45 * ) V_46 ;
V_45 -> V_55 = V_65 ;
}
static unsigned long
F_30 ( const struct V_27 * V_28 )
{
unsigned int V_66 ;
V_66 = F_31 ( & V_28 -> V_67 ) - V_68 ;
V_66 += F_32 () % ( 2 * V_68 ) ;
return V_69 + F_33 ( V_66 ) ;
}
static unsigned long F_34 ( void )
{
return V_69 + F_33 ( F_32 () % ( V_68 / 2 ) ) ;
}
static T_1 F_35 ( T_1 V_59 , const struct V_27 * V_28 )
{
int V_70 = F_31 ( & V_28 -> V_70 ) ;
int V_71 ;
V_71 = V_59 * ( V_60 - V_70 ) ;
V_71 /= V_60 ;
return V_71 ;
}
static bool F_36 ( int V_72 , int V_73 ,
T_5 V_74 )
{
int V_75 = 0 ;
V_75 += V_72 + V_50 ;
V_75 += F_37 ( V_74 ) ;
return ( V_75 <= V_73 ) &&
( V_75 <= V_76 ) ;
}
static void F_38 ( struct V_77 * V_78 ,
struct V_39 * V_40 )
{
struct V_27 * V_28 = F_39 ( V_40 -> V_79 ) ;
const char * V_80 ;
T_1 V_81 ;
T_6 V_72 ;
struct V_45 * V_45 ;
struct V_82 * V_83 ;
T_1 * V_84 ;
if ( V_40 -> V_85 != V_86 )
return;
V_81 = 0 ;
V_72 = 0 ;
V_84 = V_78 -> V_83 -> V_87 ;
V_45 = (struct V_45 * ) V_84 ;
while ( F_36 ( V_72 , V_78 -> V_73 ,
V_45 -> V_74 ) ) {
if ( V_78 -> V_88 & F_40 ( V_81 ) &&
V_78 -> V_89 == V_40 )
V_45 -> V_56 |= V_90 ;
else
V_45 -> V_56 &= ~ V_90 ;
if ( V_81 > 0 || ! V_78 -> V_91 )
V_80 = L_1 ;
else
V_80 = L_2 ;
F_41 ( V_92 , V_28 ,
L_3 ,
V_80 , ( V_81 > 0 ? L_4 : L_5 ) ,
V_45 -> V_61 ,
F_42 ( V_45 -> V_93 ) ,
V_45 -> V_59 , V_45 -> V_55 ,
( ( V_45 -> V_56 & V_90 ) ?
L_6 : L_7 ) ,
V_40 -> V_62 -> V_94 ,
V_40 -> V_62 -> V_63 ) ;
V_72 += V_50 ;
V_72 += F_37 ( V_45 -> V_74 ) ;
V_81 ++ ;
V_84 = V_78 -> V_83 -> V_87 + V_72 ;
V_45 = (struct V_45 * ) V_84 ;
}
V_83 = F_43 ( V_78 -> V_83 , V_21 ) ;
if ( V_83 ) {
F_44 ( V_28 , V_95 ) ;
F_45 ( V_28 , V_96 ,
V_83 -> V_97 + V_98 ) ;
F_46 ( V_83 , V_40 ) ;
}
}
static void F_47 ( struct V_77 * V_78 )
{
struct V_99 * V_79 ;
struct V_27 * V_28 ;
struct V_39 * V_100 = NULL ;
if ( ! V_78 -> V_89 ) {
F_48 ( L_8 ) ;
goto V_44;
}
V_79 = V_78 -> V_89 -> V_79 ;
V_28 = F_39 ( V_79 ) ;
if ( F_49 ( ! V_78 -> V_101 ) )
goto V_44;
if ( F_49 ( V_78 -> V_101 -> V_79 != V_79 ) )
goto V_44;
if ( V_78 -> V_89 -> V_85 != V_86 )
goto V_44;
V_100 = F_50 ( V_28 ) ;
if ( ! V_100 )
goto V_44;
F_38 ( V_78 , V_78 -> V_101 ) ;
V_44:
if ( V_100 )
F_51 ( V_100 ) ;
}
static bool
F_52 ( const struct V_45 * V_102 ,
struct V_27 * V_28 ,
int V_73 , unsigned long V_103 ,
bool V_104 ,
const struct V_39 * V_89 ,
const struct V_39 * V_101 ,
const struct V_77 * V_78 )
{
struct V_45 * V_45 ;
int V_105 = V_78 -> V_73 + V_73 ;
struct V_39 * V_100 = NULL ;
bool V_106 = false ;
unsigned long V_107 ;
V_45 = (struct V_45 * ) V_78 -> V_83 -> V_87 ;
V_107 = V_103 ;
V_107 += F_33 ( V_108 ) ;
if ( ! F_53 ( V_103 , V_78 -> V_103 ) ||
! F_54 ( V_107 , V_78 -> V_103 ) )
return false ;
if ( V_105 > V_76 )
return false ;
if ( V_78 -> V_101 != V_101 )
return false ;
V_100 = F_50 ( V_28 ) ;
if ( ! V_100 )
return false ;
if ( ! V_104 &&
! ( V_45 -> V_56 & V_90 ) &&
V_45 -> V_55 != 1 &&
( ! V_78 -> V_91 ||
V_78 -> V_89 == V_100 ) ) {
V_106 = true ;
goto V_44;
}
if ( V_104 &&
V_102 -> V_55 == 1 &&
V_78 -> V_89 == V_89 &&
( V_45 -> V_56 & V_90 ||
( V_78 -> V_91 &&
V_78 -> V_89 != V_100 ) ) ) {
V_106 = true ;
goto V_44;
}
V_44:
if ( V_100 )
F_51 ( V_100 ) ;
return V_106 ;
}
static void F_55 ( const unsigned char * V_109 ,
int V_73 , unsigned long V_103 ,
bool V_110 ,
struct V_39 * V_89 ,
struct V_39 * V_101 ,
int V_111 )
{
struct V_27 * V_28 = F_39 ( V_89 -> V_79 ) ;
struct V_77 * V_112 ;
unsigned char * V_113 ;
unsigned int V_114 ;
if ( ! V_111 ) {
if ( ! F_56 ( & V_28 -> V_115 ) ) {
F_41 ( V_92 , V_28 ,
L_9 ) ;
return;
}
}
V_112 = F_25 ( sizeof( * V_112 ) , V_21 ) ;
if ( ! V_112 )
goto V_116;
if ( F_31 ( & V_28 -> V_117 ) &&
V_73 < V_76 )
V_114 = V_76 ;
else
V_114 = V_73 ;
V_114 += V_98 ;
V_112 -> V_83 = F_57 ( NULL , V_114 ) ;
if ( ! V_112 -> V_83 )
goto V_118;
V_112 -> V_83 -> V_119 = V_120 ;
F_58 ( V_112 -> V_83 , V_98 ) ;
V_113 = F_59 ( V_112 -> V_83 , V_73 ) ;
V_112 -> V_73 = V_73 ;
memcpy ( V_113 , V_109 , V_73 ) ;
F_60 ( & V_89 -> V_121 ) ;
F_60 ( & V_101 -> V_121 ) ;
V_112 -> V_91 = V_111 ;
V_112 -> V_89 = V_89 ;
V_112 -> V_101 = V_101 ;
V_112 -> V_122 = 0 ;
V_112 -> V_88 = V_57 ;
V_112 -> V_103 = V_103 ;
if ( V_110 )
V_112 -> V_88 |= 1 ;
F_6 ( & V_28 -> V_123 ) ;
F_61 ( & V_112 -> V_124 , & V_28 -> V_125 ) ;
F_8 ( & V_28 -> V_123 ) ;
F_62 ( & V_112 -> V_126 ,
V_127 ) ;
F_63 ( V_128 ,
& V_112 -> V_126 ,
V_103 - V_69 ) ;
return;
V_118:
F_4 ( V_112 ) ;
V_116:
if ( ! V_111 )
F_64 ( & V_28 -> V_115 ) ;
}
static void F_65 ( struct V_77 * V_112 ,
const unsigned char * V_109 ,
int V_73 , bool V_110 )
{
unsigned char * V_113 ;
unsigned long V_129 ;
V_113 = F_59 ( V_112 -> V_83 , V_73 ) ;
memcpy ( V_113 , V_109 , V_73 ) ;
V_112 -> V_73 += V_73 ;
V_112 -> V_122 ++ ;
if ( V_110 ) {
V_129 = F_40 ( V_112 -> V_122 ) ;
V_112 -> V_88 |= V_129 ;
}
}
static void F_66 ( struct V_27 * V_28 ,
unsigned char * V_109 ,
int V_73 ,
struct V_39 * V_89 ,
struct V_39 * V_101 ,
int V_111 , unsigned long V_103 )
{
struct V_77 * V_112 = NULL ;
struct V_77 * V_130 = NULL ;
struct V_45 * V_45 ;
bool V_110 ;
unsigned long V_131 ;
V_45 = (struct V_45 * ) V_109 ;
V_110 = ! ! ( V_45 -> V_56 & V_90 ) ;
V_131 = F_33 ( V_108 ) ;
F_6 ( & V_28 -> V_123 ) ;
if ( F_31 ( & V_28 -> V_117 ) && ! V_111 ) {
F_67 (forw_packet_pos,
&bat_priv->forw_bat_list, list) {
if ( F_52 ( V_45 ,
V_28 , V_73 ,
V_103 , V_110 ,
V_89 ,
V_101 ,
V_130 ) ) {
V_112 = V_130 ;
break;
}
}
}
if ( ! V_112 ) {
F_8 ( & V_28 -> V_123 ) ;
if ( ! V_111 && F_31 ( & V_28 -> V_117 ) )
V_103 += V_131 ;
F_55 ( V_109 , V_73 ,
V_103 , V_110 ,
V_89 , V_101 ,
V_111 ) ;
} else {
F_65 ( V_112 , V_109 ,
V_73 , V_110 ) ;
F_8 ( & V_28 -> V_123 ) ;
}
}
static void F_68 ( struct V_9 * V_10 ,
const struct V_132 * V_132 ,
struct V_45 * V_45 ,
bool V_133 ,
bool V_134 ,
struct V_39 * V_89 ,
struct V_39 * V_101 )
{
struct V_27 * V_28 = F_39 ( V_89 -> V_79 ) ;
T_2 V_74 ;
if ( V_45 -> V_55 <= 1 ) {
F_41 ( V_92 , V_28 , L_10 ) ;
return;
}
if ( ! V_134 ) {
if ( V_133 )
V_45 -> V_56 |= V_135 ;
else
return;
}
V_74 = F_37 ( V_45 -> V_74 ) ;
V_45 -> V_55 -- ;
F_28 ( V_45 -> V_64 , V_132 -> V_136 ) ;
V_45 -> V_59 = F_35 ( V_45 -> V_59 ,
V_28 ) ;
F_41 ( V_92 , V_28 ,
L_11 ,
V_45 -> V_59 , V_45 -> V_55 ) ;
if ( V_133 )
V_45 -> V_56 |= V_90 ;
else
V_45 -> V_56 &= ~ V_90 ;
F_66 ( V_28 , ( unsigned char * ) V_45 ,
V_50 + V_74 ,
V_89 , V_101 , 0 ,
F_34 () ) ;
}
static void
F_69 ( struct V_39 * V_40 )
{
struct V_27 * V_28 = F_39 ( V_40 -> V_79 ) ;
struct V_137 * V_138 = V_28 -> V_34 ;
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
V_142 = V_40 -> V_144 * V_20 ;
V_141 = & V_10 -> V_11 . V_12 [ V_142 ] ;
F_72 ( V_28 , V_141 , 1 , 0 ) ;
V_144 = V_40 -> V_144 ;
V_143 = & V_10 -> V_11 . V_13 [ V_144 ] ;
* V_143 = F_73 ( V_141 , V_146 ) ;
F_8 ( & V_10 -> V_11 . V_19 ) ;
}
F_74 () ;
}
}
static void F_75 ( struct V_39 * V_40 )
{
struct V_27 * V_28 = F_39 ( V_40 -> V_79 ) ;
unsigned char * * V_46 = & V_40 -> V_11 . V_46 ;
struct V_45 * V_45 ;
struct V_39 * V_100 , * V_147 ;
int * V_49 = & V_40 -> V_11 . V_49 ;
T_4 V_93 ;
T_2 V_74 = 0 ;
unsigned long V_103 ;
V_100 = F_50 ( V_28 ) ;
if ( V_40 == V_100 ) {
F_76 ( V_28 ) ;
V_74 = F_77 ( V_28 , V_46 ,
V_49 ,
V_50 ) ;
}
V_45 = (struct V_45 * ) ( * V_46 ) ;
V_45 -> V_74 = F_78 ( V_74 ) ;
V_93 = ( T_4 ) F_31 ( & V_40 -> V_11 . V_48 ) ;
V_45 -> V_93 = F_79 ( V_93 ) ;
F_64 ( & V_40 -> V_11 . V_48 ) ;
F_69 ( V_40 ) ;
V_103 = F_30 ( V_28 ) ;
if ( V_40 != V_100 ) {
F_66 ( V_28 , * V_46 , * V_49 ,
V_40 , V_40 , 1 , V_103 ) ;
goto V_44;
}
F_70 () ;
F_80 (tmp_hard_iface, &batadv_hardif_list, list) {
if ( V_147 -> V_79 != V_40 -> V_79 )
continue;
if ( ! F_81 ( & V_147 -> V_121 ) )
continue;
F_66 ( V_28 , * V_46 ,
* V_49 , V_40 ,
V_147 , 1 , V_103 ) ;
F_51 ( V_147 ) ;
}
F_74 () ;
V_44:
if ( V_100 )
F_51 ( V_100 ) ;
}
static void
F_82 ( struct V_27 * V_28 ,
struct V_9 * V_10 ,
struct V_148 * V_149 ,
const struct V_132 * V_132 ,
const struct V_45 * V_45 ,
struct V_39 * V_89 ,
struct V_39 * V_101 ,
enum V_150 V_151 )
{
struct V_152 * V_153 = NULL ;
struct V_152 * V_154 = NULL ;
struct V_38 * V_43 = NULL ;
struct V_38 * V_155 = NULL ;
struct V_38 * V_156 = NULL ;
struct V_9 * V_157 ;
int V_144 ;
T_1 V_158 , V_159 ;
T_1 * V_41 ;
T_1 V_160 ;
F_41 ( V_92 , V_28 ,
L_12 ) ;
F_70 () ;
F_71 (tmp_neigh_node,
&orig_node->neigh_list, list) {
V_41 = V_155 -> V_29 ;
if ( F_83 ( V_41 , V_132 -> V_136 ) &&
V_155 -> V_89 == V_89 &&
F_81 ( & V_155 -> V_121 ) ) {
if ( F_84 ( V_43 , L_13 ) )
F_85 ( V_43 ) ;
V_43 = V_155 ;
continue;
}
if ( V_151 != V_161 )
continue;
V_153 = F_86 ( V_155 ,
V_101 ) ;
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
if ( ! V_43 ) {
struct V_9 * V_165 ;
V_165 = F_13 ( V_28 , V_132 -> V_136 ) ;
if ( ! V_165 )
goto V_22;
V_43 = F_20 ( V_89 ,
V_132 -> V_136 ,
V_10 , V_165 ) ;
F_19 ( V_165 ) ;
if ( ! V_43 )
goto V_22;
} else {
F_41 ( V_92 , V_28 ,
L_14 ) ;
}
F_74 () ;
V_153 = F_88 ( V_43 , V_101 ) ;
if ( ! V_153 )
goto V_44;
V_43 -> V_166 = V_69 ;
F_6 ( & V_43 -> V_162 ) ;
F_1 ( V_153 -> V_11 . V_163 ,
& V_153 -> V_11 . V_164 ,
V_45 -> V_59 ) ;
V_160 = F_2 ( V_153 -> V_11 . V_163 ) ;
V_153 -> V_11 . V_160 = V_160 ;
F_8 ( & V_43 -> V_162 ) ;
if ( V_151 == V_161 ) {
V_149 -> V_167 = V_45 -> V_55 ;
V_153 -> V_167 = V_45 -> V_55 ;
}
V_156 = F_89 ( V_10 , V_101 ) ;
if ( V_156 == V_43 )
goto V_44;
if ( V_156 ) {
V_154 = F_86 ( V_156 , V_101 ) ;
if ( ! V_154 )
goto V_44;
if ( V_154 -> V_11 . V_160 > V_153 -> V_11 . V_160 )
goto V_44;
}
if ( V_154 &&
V_153 -> V_11 . V_160 == V_154 -> V_11 . V_160 ) {
V_157 = V_156 -> V_10 ;
F_6 ( & V_157 -> V_11 . V_19 ) ;
V_144 = V_156 -> V_89 -> V_144 ;
V_158 = V_157 -> V_11 . V_13 [ V_144 ] ;
F_8 ( & V_157 -> V_11 . V_19 ) ;
V_157 = V_43 -> V_10 ;
F_6 ( & V_157 -> V_11 . V_19 ) ;
V_144 = V_43 -> V_89 -> V_144 ;
V_159 = V_157 -> V_11 . V_13 [ V_144 ] ;
F_8 ( & V_157 -> V_11 . V_19 ) ;
if ( V_158 >= V_159 )
goto V_44;
}
F_90 ( V_28 , V_10 , V_101 , V_43 ) ;
goto V_44;
V_22:
F_74 () ;
V_44:
if ( V_43 )
F_85 ( V_43 ) ;
if ( V_156 )
F_85 ( V_156 ) ;
if ( V_153 )
F_87 ( V_153 ) ;
if ( V_154 )
F_87 ( V_154 ) ;
}
static bool F_91 ( struct V_9 * V_10 ,
struct V_9 * V_168 ,
struct V_45 * V_45 ,
struct V_39 * V_89 ,
struct V_39 * V_101 )
{
struct V_27 * V_28 = F_39 ( V_89 -> V_79 ) ;
struct V_38 * V_43 = NULL , * V_155 ;
struct V_152 * V_153 ;
T_1 V_169 ;
T_1 V_170 , V_171 , V_172 , V_173 ;
unsigned int V_174 , V_175 ;
int V_144 ;
unsigned int V_176 , V_177 ;
unsigned int V_178 ;
unsigned int V_179 ;
bool V_17 = false ;
F_70 () ;
F_71 (tmp_neigh_node,
&orig_neigh_node->neigh_list, list) {
if ( ! F_83 ( V_155 -> V_29 ,
V_168 -> V_61 ) )
continue;
if ( V_155 -> V_89 != V_89 )
continue;
if ( ! F_81 ( & V_155 -> V_121 ) )
continue;
V_43 = V_155 ;
break;
}
F_74 () ;
if ( ! V_43 )
V_43 = F_20 ( V_89 ,
V_168 -> V_61 ,
V_168 ,
V_168 ) ;
if ( ! V_43 )
goto V_44;
if ( V_10 == V_168 )
V_43 -> V_166 = V_69 ;
V_10 -> V_166 = V_69 ;
F_6 ( & V_10 -> V_11 . V_19 ) ;
V_144 = V_89 -> V_144 ;
V_170 = V_168 -> V_11 . V_13 [ V_144 ] ;
V_153 = F_88 ( V_43 , V_101 ) ;
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
V_173 = ( V_60 * V_169 ) / V_171 ;
V_172 = V_146 - V_171 ;
V_174 = V_172 * V_172 * V_172 ;
V_175 = V_146 *
V_146 *
V_146 ;
V_177 = V_60 * V_174 ;
V_177 /= V_175 ;
V_176 = V_60 - V_177 ;
V_179 = V_60 ;
if ( V_101 && ( V_89 == V_101 ) &&
F_92 ( V_101 -> V_62 ) )
V_179 = F_35 ( V_60 ,
V_28 ) ;
V_178 = V_45 -> V_59 *
V_173 *
V_176 *
V_179 ;
V_178 /= V_60 *
V_60 *
V_60 ;
V_45 -> V_59 = V_178 ;
F_41 ( V_92 , V_28 ,
L_15 ,
V_10 -> V_61 , V_168 -> V_61 , V_169 ,
V_171 , V_173 , V_176 , V_179 ,
V_45 -> V_59 , V_89 -> V_62 -> V_94 ,
V_101 ? V_101 -> V_62 -> V_94 : L_16 ) ;
if ( V_45 -> V_59 >= V_183 )
V_17 = true ;
V_44:
if ( V_43 )
F_85 ( V_43 ) ;
return V_17 ;
}
static enum V_150
F_93 ( const struct V_132 * V_132 ,
const struct V_45 * V_45 ,
const struct V_39 * V_89 ,
struct V_39 * V_101 )
{
struct V_27 * V_28 = F_39 ( V_89 -> V_79 ) ;
struct V_9 * V_10 ;
struct V_148 * V_149 = NULL ;
struct V_38 * V_43 ;
struct V_152 * V_153 ;
bool V_184 ;
T_7 V_185 ;
bool V_186 = false ;
int V_187 ;
enum V_150 V_17 = V_161 ;
T_4 V_93 = F_42 ( V_45 -> V_93 ) ;
T_1 * V_41 ;
T_1 V_188 ;
unsigned long * V_189 ;
V_10 = F_13 ( V_28 , V_45 -> V_61 ) ;
if ( ! V_10 )
return V_161 ;
V_149 = F_94 ( V_10 , V_101 ) ;
if ( F_49 ( ! V_149 ) ) {
F_19 ( V_10 ) ;
return 0 ;
}
F_6 ( & V_10 -> V_11 . V_19 ) ;
V_185 = V_93 - V_149 -> V_190 ;
if ( ! F_95 ( & V_10 -> V_191 ) &&
F_96 ( V_28 , V_185 ,
V_146 ,
& V_149 -> V_192 , NULL ) ) {
V_17 = V_193 ;
goto V_44;
}
F_70 () ;
F_71 (neigh_node, &orig_node->neigh_list, list) {
V_153 = F_88 ( V_43 ,
V_101 ) ;
if ( ! V_153 )
continue;
V_41 = V_43 -> V_29 ;
V_184 = F_97 ( V_153 -> V_11 . V_194 ,
V_149 -> V_190 ,
V_93 ) ;
if ( F_83 ( V_41 , V_132 -> V_136 ) &&
V_43 -> V_89 == V_89 ) {
V_187 = 1 ;
if ( V_184 )
V_17 = V_195 ;
} else {
V_187 = 0 ;
if ( V_184 && ( V_17 != V_195 ) )
V_17 = V_196 ;
}
V_189 = V_153 -> V_11 . V_194 ;
V_186 |= F_72 ( V_28 , V_189 ,
V_185 , V_187 ) ;
V_188 = F_73 ( V_189 ,
V_146 ) ;
V_153 -> V_11 . V_180 = V_188 ;
F_87 ( V_153 ) ;
}
F_74 () ;
if ( V_186 ) {
F_41 ( V_92 , V_28 ,
L_17 ,
V_101 ? V_101 -> V_62 -> V_94 : L_16 ,
V_149 -> V_190 , V_93 ) ;
V_149 -> V_190 = V_93 ;
}
V_44:
F_8 ( & V_10 -> V_11 . V_19 ) ;
F_19 ( V_10 ) ;
F_98 ( V_149 ) ;
return V_17 ;
}
static void
F_99 ( const struct V_82 * V_83 , int V_197 ,
struct V_9 * V_10 ,
struct V_39 * V_89 ,
struct V_39 * V_101 )
{
struct V_27 * V_28 = F_39 ( V_89 -> V_79 ) ;
struct V_198 * V_199 = NULL ;
struct V_38 * V_156 = NULL ;
struct V_38 * V_200 = NULL ;
struct V_9 * V_168 ;
struct V_148 * V_149 ;
struct V_38 * V_201 = NULL ;
struct V_152 * V_154 = NULL ;
struct V_45 * V_202 ;
enum V_150 V_151 ;
bool V_134 = false ;
bool V_133 = false ;
bool V_203 , V_204 ;
struct V_82 * V_205 ;
struct V_132 * V_132 ;
T_1 * V_64 ;
bool V_206 ;
V_205 = F_100 ( V_83 , V_21 ) ;
if ( ! V_205 )
return;
V_132 = F_101 ( V_205 ) ;
V_202 = (struct V_45 * ) ( V_205 -> V_87 + V_197 ) ;
V_151 = F_93 ( V_132 , V_202 ,
V_89 , V_101 ) ;
if ( F_83 ( V_132 -> V_136 , V_202 -> V_61 ) )
V_133 = true ;
if ( V_151 == V_193 ) {
F_41 ( V_92 , V_28 ,
L_18 ,
V_132 -> V_136 ) ;
goto V_44;
}
if ( V_202 -> V_59 == 0 ) {
F_41 ( V_92 , V_28 ,
L_19 ) ;
goto V_44;
}
if ( V_133 ) {
V_199 = F_102 ( V_89 ,
V_132 -> V_136 ) ;
if ( V_199 )
V_199 -> V_166 = V_69 ;
}
V_156 = F_89 ( V_10 , V_101 ) ;
if ( V_156 ) {
V_200 = F_89 ( V_156 -> V_10 ,
V_101 ) ;
V_154 = F_86 ( V_156 , V_101 ) ;
}
if ( ( V_154 && V_154 -> V_11 . V_160 != 0 ) &&
( F_83 ( V_156 -> V_29 , V_132 -> V_136 ) ) )
V_134 = true ;
V_64 = V_202 -> V_64 ;
if ( V_156 && V_200 &&
( F_83 ( V_156 -> V_29 , V_64 ) ) &&
! ( F_83 ( V_202 -> V_61 , V_64 ) ) &&
( F_83 ( V_156 -> V_29 , V_200 -> V_29 ) ) ) {
F_41 ( V_92 , V_28 ,
L_20 ,
V_132 -> V_136 ) ;
goto V_44;
}
if ( V_101 == V_207 )
F_103 ( V_28 , V_202 , V_10 ) ;
if ( V_133 )
V_168 = V_10 ;
else
V_168 = F_13 ( V_28 ,
V_132 -> V_136 ) ;
if ( ! V_168 )
goto V_44;
F_104 ( V_28 , V_10 , V_168 ,
V_202 , V_133 ) ;
V_201 = F_89 ( V_168 ,
V_101 ) ;
if ( ! V_133 && ( ! V_201 ) ) {
F_41 ( V_92 , V_28 ,
L_21 ) ;
goto V_208;
}
V_206 = F_91 ( V_10 , V_168 ,
V_202 , V_89 ,
V_101 ) ;
V_149 = F_94 ( V_10 , V_101 ) ;
if ( ! V_149 )
goto V_208;
V_203 = V_149 -> V_190 == F_42 ( V_202 -> V_93 ) ;
V_204 = ( V_149 -> V_167 - 3 ) <= V_202 -> V_55 ;
if ( V_206 && ( ( V_151 == V_161 ) ||
( V_203 && V_204 ) ) ) {
F_82 ( V_28 , V_10 ,
V_149 , V_132 ,
V_202 , V_89 ,
V_101 , V_151 ) ;
}
F_98 ( V_149 ) ;
if ( V_101 == V_207 )
goto V_208;
if ( V_133 ) {
if ( ( V_202 -> V_55 <= 2 ) &&
( V_89 != V_101 ) ) {
F_41 ( V_92 , V_28 ,
L_22 ) ;
goto V_208;
}
F_68 ( V_10 , V_132 , V_202 ,
V_133 ,
V_134 , V_89 ,
V_101 ) ;
F_41 ( V_92 , V_28 ,
L_23 ) ;
goto V_208;
}
if ( ! V_206 ) {
F_41 ( V_92 , V_28 ,
L_24 ) ;
goto V_208;
}
if ( V_151 == V_195 ) {
F_41 ( V_92 , V_28 ,
L_25 ) ;
goto V_208;
}
F_41 ( V_92 , V_28 ,
L_26 ) ;
F_68 ( V_10 , V_132 , V_202 ,
V_133 , V_134 ,
V_89 , V_101 ) ;
V_208:
if ( ( V_168 ) && ( ! V_133 ) )
F_19 ( V_168 ) ;
V_44:
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
static void F_107 ( const struct V_82 * V_83 , int V_197 ,
struct V_39 * V_89 )
{
struct V_27 * V_28 = F_39 ( V_89 -> V_79 ) ;
struct V_9 * V_168 , * V_10 ;
struct V_39 * V_40 ;
struct V_45 * V_202 ;
T_4 V_209 ;
bool V_210 ;
struct V_132 * V_132 ;
bool V_211 = false ;
bool V_212 = false ;
bool V_213 = false ;
V_202 = (struct V_45 * ) ( V_83 -> V_87 + V_197 ) ;
V_132 = F_101 ( V_83 ) ;
if ( V_202 -> V_51 != V_52 )
return;
V_209 = F_31 ( & V_89 -> V_11 . V_48 ) ;
if ( V_202 -> V_56 & V_90 )
V_210 = true ;
else
V_210 = false ;
F_41 ( V_92 , V_28 ,
L_27 ,
V_132 -> V_136 , V_89 -> V_62 -> V_94 ,
V_89 -> V_62 -> V_63 , V_202 -> V_61 ,
V_202 -> V_64 , F_42 ( V_202 -> V_93 ) ,
V_202 -> V_59 , V_202 -> V_55 ,
V_202 -> V_53 , V_210 ) ;
F_70 () ;
F_80 (hard_iface, &batadv_hardif_list, list) {
if ( V_40 -> V_85 != V_86 )
continue;
if ( V_40 -> V_79 != V_89 -> V_79 )
continue;
if ( F_83 ( V_132 -> V_136 ,
V_40 -> V_62 -> V_63 ) )
V_212 = true ;
if ( F_83 ( V_202 -> V_61 ,
V_40 -> V_62 -> V_63 ) )
V_213 = true ;
if ( F_83 ( V_202 -> V_64 ,
V_40 -> V_62 -> V_63 ) )
V_211 = true ;
}
F_74 () ;
if ( V_212 ) {
F_41 ( V_92 , V_28 ,
L_28 ,
V_132 -> V_136 ) ;
return;
}
if ( V_213 ) {
unsigned long * V_141 ;
int V_214 ;
T_7 V_215 ;
T_6 V_144 ;
T_1 * V_216 ;
V_168 = F_13 ( V_28 ,
V_132 -> V_136 ) ;
if ( ! V_168 )
return;
if ( V_210 &&
F_83 ( V_89 -> V_62 -> V_63 ,
V_202 -> V_61 ) ) {
V_144 = V_89 -> V_144 ;
V_214 = V_144 * V_20 ;
F_6 ( & V_168 -> V_11 . V_19 ) ;
V_141 = & V_168 -> V_11 . V_12 [ V_214 ] ;
V_215 = V_209 - 2 ;
V_215 -= F_42 ( V_202 -> V_93 ) ;
F_108 ( V_141 , V_215 ) ;
V_216 = & V_168 -> V_11 . V_13 [ V_144 ] ;
* V_216 = F_73 ( V_141 ,
V_146 ) ;
F_8 ( & V_168 -> V_11 . V_19 ) ;
}
F_41 ( V_92 , V_28 ,
L_29 ) ;
F_19 ( V_168 ) ;
return;
}
if ( V_211 ) {
F_41 ( V_92 , V_28 ,
L_30 ,
V_132 -> V_136 ) ;
return;
}
if ( V_202 -> V_56 & V_135 ) {
F_41 ( V_92 , V_28 ,
L_31 ,
V_132 -> V_136 ) ;
return;
}
V_10 = F_13 ( V_28 , V_202 -> V_61 ) ;
if ( ! V_10 )
return;
F_99 ( V_83 , V_197 , V_10 ,
V_89 , V_207 ) ;
F_70 () ;
F_80 (hard_iface, &batadv_hardif_list, list) {
if ( V_40 -> V_85 != V_86 )
continue;
if ( V_40 -> V_79 != V_28 -> V_79 )
continue;
if ( ! F_81 ( & V_40 -> V_121 ) )
continue;
F_99 ( V_83 , V_197 , V_10 ,
V_89 , V_40 ) ;
F_51 ( V_40 ) ;
}
F_74 () ;
F_19 ( V_10 ) ;
}
static int F_109 ( struct V_82 * V_83 ,
struct V_39 * V_89 )
{
struct V_27 * V_28 = F_39 ( V_89 -> V_79 ) ;
struct V_45 * V_202 ;
T_1 * V_84 ;
int V_197 ;
bool V_17 ;
V_17 = F_110 ( V_83 , V_89 , V_50 ) ;
if ( ! V_17 )
return V_217 ;
if ( V_28 -> V_218 -> V_219 != F_47 )
return V_217 ;
F_44 ( V_28 , V_220 ) ;
F_45 ( V_28 , V_221 ,
V_83 -> V_97 + V_98 ) ;
V_197 = 0 ;
V_202 = (struct V_45 * ) V_83 -> V_87 ;
while ( F_36 ( V_197 , F_111 ( V_83 ) ,
V_202 -> V_74 ) ) {
F_107 ( V_83 , V_197 , V_89 ) ;
V_197 += V_50 ;
V_197 += F_37 ( V_202 -> V_74 ) ;
V_84 = V_83 -> V_87 + V_197 ;
V_202 = (struct V_45 * ) V_84 ;
}
F_106 ( V_83 ) ;
return V_222 ;
}
static void
F_112 ( struct V_9 * V_10 ,
struct V_39 * V_101 ,
struct V_223 * V_224 )
{
struct V_38 * V_43 ;
struct V_152 * V_225 ;
F_71 (neigh_node, &orig_node->neigh_list, list) {
V_225 = F_86 ( V_43 , V_101 ) ;
if ( ! V_225 )
continue;
F_113 ( V_224 , L_32 ,
V_43 -> V_29 ,
V_225 -> V_11 . V_160 ) ;
F_87 ( V_225 ) ;
}
}
static void F_114 ( struct V_27 * V_28 ,
struct V_223 * V_224 ,
struct V_39 * V_101 )
{
struct V_38 * V_43 ;
struct V_137 * V_138 = V_28 -> V_34 ;
int V_226 , V_227 ;
struct V_9 * V_10 ;
struct V_152 * V_225 ;
unsigned long V_228 ;
struct V_139 * V_140 ;
int V_229 = 0 ;
T_4 V_7 ;
F_115 ( V_224 ,
L_33 ) ;
for ( V_7 = 0 ; V_7 < V_138 -> V_30 ; V_7 ++ ) {
V_140 = & V_138 -> V_145 [ V_7 ] ;
F_70 () ;
F_71 (orig_node, head, hash_entry) {
V_43 = F_89 ( V_10 ,
V_101 ) ;
if ( ! V_43 )
continue;
V_225 = F_86 ( V_43 ,
V_101 ) ;
if ( ! V_225 )
goto V_230;
if ( V_225 -> V_11 . V_160 == 0 )
goto V_230;
V_228 = V_69 - V_10 -> V_166 ;
V_226 = F_116 ( V_228 ) ;
V_227 = V_226 / 1000 ;
V_226 = V_226 % 1000 ;
F_113 ( V_224 , L_34 ,
V_10 -> V_61 , V_227 ,
V_226 , V_225 -> V_11 . V_160 ,
V_43 -> V_29 ,
V_43 -> V_89 -> V_62 -> V_94 ) ;
F_112 ( V_10 , V_101 ,
V_224 ) ;
F_115 ( V_224 , L_35 ) ;
V_229 ++ ;
V_230:
F_85 ( V_43 ) ;
if ( V_225 )
F_87 ( V_225 ) ;
}
F_74 () ;
}
if ( V_229 == 0 )
F_115 ( V_224 , L_36 ) ;
}
static void
F_117 ( struct V_223 * V_224 ,
struct V_198 * V_199 )
{
int V_231 , V_232 ;
V_231 = F_116 ( V_69 - V_199 -> V_166 ) / 1000 ;
V_232 = F_116 ( V_69 - V_199 -> V_166 ) % 1000 ;
F_113 ( V_224 , L_37 ,
V_199 -> V_89 -> V_62 -> V_94 ,
V_199 -> V_29 , V_231 , V_232 ) ;
}
static void F_118 ( struct V_27 * V_28 ,
struct V_223 * V_224 )
{
struct V_99 * V_62 = (struct V_99 * ) V_224 -> V_233 ;
struct V_198 * V_199 ;
struct V_39 * V_40 ;
int V_229 = 0 ;
F_115 ( V_224 , L_38 ) ;
F_70 () ;
F_80 (hard_iface, &batadv_hardif_list, list) {
if ( V_40 -> V_79 != V_62 )
continue;
F_71 (hardif_neigh,
&hard_iface->neigh_list, list) {
F_117 ( V_224 , V_199 ) ;
V_229 ++ ;
}
}
F_74 () ;
if ( V_229 == 0 )
F_115 ( V_224 , L_36 ) ;
}
static int F_119 ( struct V_38 * V_234 ,
struct V_39 * V_235 ,
struct V_38 * V_236 ,
struct V_39 * V_237 )
{
struct V_152 * V_238 , * V_239 ;
T_1 V_240 , V_241 ;
int V_242 ;
V_238 = F_86 ( V_234 , V_235 ) ;
V_239 = F_86 ( V_236 , V_237 ) ;
if ( ! V_238 || ! V_239 ) {
V_242 = 0 ;
goto V_44;
}
V_240 = V_238 -> V_11 . V_160 ;
V_241 = V_239 -> V_11 . V_160 ;
V_242 = V_240 - V_241 ;
V_44:
if ( V_238 )
F_87 ( V_238 ) ;
if ( V_239 )
F_87 ( V_239 ) ;
return V_242 ;
}
static bool
F_120 ( struct V_38 * V_234 ,
struct V_39 * V_235 ,
struct V_38 * V_236 ,
struct V_39 * V_237 )
{
struct V_152 * V_238 , * V_239 ;
T_1 V_240 , V_241 ;
bool V_17 ;
V_238 = F_86 ( V_234 , V_235 ) ;
V_239 = F_86 ( V_236 , V_237 ) ;
if ( ! V_238 || ! V_239 ) {
V_17 = false ;
goto V_44;
}
V_240 = V_238 -> V_11 . V_160 ;
V_241 = V_239 -> V_11 . V_160 ;
V_17 = ( V_240 - V_241 ) > - V_243 ;
V_44:
if ( V_238 )
F_87 ( V_238 ) ;
if ( V_239 )
F_87 ( V_239 ) ;
return V_17 ;
}
int T_8 F_121 ( void )
{
int V_17 ;
V_17 = F_122 ( V_52 ,
F_109 ) ;
if ( V_17 < 0 )
goto V_44;
V_17 = F_123 ( & V_244 ) ;
if ( V_17 < 0 )
goto V_245;
goto V_44;
V_245:
F_124 ( V_52 ) ;
V_44:
return V_17 ;
}

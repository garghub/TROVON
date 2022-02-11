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
F_43 ( V_85 , V_42 , V_101 ) ;
}
}
static void F_44 ( struct V_79 * V_80 )
{
struct V_102 * V_81 ;
struct V_29 * V_30 ;
struct V_41 * V_103 = NULL ;
if ( ! V_80 -> V_91 ) {
F_45 ( L_8 ) ;
goto V_46;
}
V_81 = V_80 -> V_91 -> V_81 ;
V_30 = F_36 ( V_81 ) ;
if ( F_46 ( ! V_80 -> V_104 ) )
goto V_46;
if ( F_46 ( V_80 -> V_104 -> V_81 != V_81 ) )
goto V_46;
if ( V_80 -> V_91 -> V_87 != V_88 )
goto V_46;
V_103 = F_47 ( V_30 ) ;
if ( ! V_103 )
goto V_46;
F_35 ( V_80 , V_80 -> V_104 ) ;
V_46:
if ( V_103 )
F_48 ( V_103 ) ;
}
static bool
F_49 ( const struct V_47 * V_105 ,
struct V_29 * V_30 ,
int V_75 , unsigned long V_106 ,
bool V_107 ,
const struct V_41 * V_91 ,
const struct V_41 * V_104 ,
const struct V_79 * V_80 )
{
struct V_47 * V_47 ;
int V_108 = V_80 -> V_75 + V_75 ;
struct V_41 * V_103 = NULL ;
bool V_109 = false ;
unsigned long V_110 ;
V_47 = (struct V_47 * ) V_80 -> V_85 -> V_89 ;
V_110 = V_106 ;
V_110 += F_30 ( V_111 ) ;
if ( ! F_50 ( V_106 , V_80 -> V_106 ) ||
! F_51 ( V_110 , V_80 -> V_106 ) )
return false ;
if ( V_108 > V_78 )
return false ;
if ( V_80 -> V_104 != V_104 )
return false ;
V_103 = F_47 ( V_30 ) ;
if ( ! V_103 )
return false ;
if ( ! V_107 &&
! ( V_47 -> V_58 & V_92 ) &&
V_47 -> V_57 != 1 &&
( ! V_80 -> V_93 ||
V_80 -> V_91 == V_103 ) ) {
V_109 = true ;
goto V_46;
}
if ( V_107 &&
V_105 -> V_57 == 1 &&
V_80 -> V_91 == V_91 &&
( V_47 -> V_58 & V_92 ||
( V_80 -> V_93 &&
V_80 -> V_91 != V_103 ) ) ) {
V_109 = true ;
goto V_46;
}
V_46:
if ( V_103 )
F_48 ( V_103 ) ;
return V_109 ;
}
static void F_52 ( const unsigned char * V_112 ,
int V_75 , unsigned long V_106 ,
bool V_113 ,
struct V_41 * V_91 ,
struct V_41 * V_104 ,
int V_114 )
{
struct V_29 * V_30 = F_36 ( V_91 -> V_81 ) ;
struct V_79 * V_115 ;
unsigned char * V_116 ;
unsigned int V_117 ;
if ( ! F_53 ( & V_91 -> V_118 ) )
return;
if ( ! F_53 ( & V_104 -> V_118 ) )
goto V_119;
if ( ! V_114 ) {
if ( ! F_54 ( & V_30 -> V_120 ) ) {
F_38 ( V_94 , V_30 ,
L_9 ) ;
goto V_121;
}
}
V_115 = F_22 ( sizeof( * V_115 ) , V_21 ) ;
if ( ! V_115 )
goto V_122;
if ( F_28 ( & V_30 -> V_123 ) &&
V_75 < V_78 )
V_117 = V_78 ;
else
V_117 = V_75 ;
V_117 += V_100 ;
V_115 -> V_85 = F_55 ( NULL , V_117 ) ;
if ( ! V_115 -> V_85 )
goto V_124;
V_115 -> V_85 -> V_125 = V_126 ;
F_56 ( V_115 -> V_85 , V_100 ) ;
V_116 = F_57 ( V_115 -> V_85 , V_75 ) ;
V_115 -> V_75 = V_75 ;
memcpy ( V_116 , V_112 , V_75 ) ;
V_115 -> V_93 = V_114 ;
V_115 -> V_91 = V_91 ;
V_115 -> V_104 = V_104 ;
V_115 -> V_127 = 0 ;
V_115 -> V_90 = V_59 ;
V_115 -> V_106 = V_106 ;
if ( V_113 )
V_115 -> V_90 |= 1 ;
F_6 ( & V_30 -> V_128 ) ;
F_58 ( & V_115 -> V_129 , & V_30 -> V_130 ) ;
F_8 ( & V_30 -> V_128 ) ;
F_59 ( & V_115 -> V_131 ,
V_132 ) ;
F_60 ( V_133 ,
& V_115 -> V_131 ,
V_106 - V_71 ) ;
return;
V_124:
F_4 ( V_115 ) ;
V_122:
if ( ! V_114 )
F_61 ( & V_30 -> V_120 ) ;
V_121:
F_48 ( V_104 ) ;
V_119:
F_48 ( V_91 ) ;
}
static void F_62 ( struct V_79 * V_115 ,
const unsigned char * V_112 ,
int V_75 , bool V_113 )
{
unsigned char * V_116 ;
unsigned long V_134 ;
V_116 = F_57 ( V_115 -> V_85 , V_75 ) ;
memcpy ( V_116 , V_112 , V_75 ) ;
V_115 -> V_75 += V_75 ;
V_115 -> V_127 ++ ;
if ( V_113 ) {
V_134 = F_37 ( V_115 -> V_127 ) ;
V_115 -> V_90 |= V_134 ;
}
}
static void F_63 ( struct V_29 * V_30 ,
unsigned char * V_112 ,
int V_75 ,
struct V_41 * V_91 ,
struct V_41 * V_104 ,
int V_114 , unsigned long V_106 )
{
struct V_79 * V_115 = NULL ;
struct V_79 * V_135 = NULL ;
struct V_47 * V_47 ;
bool V_113 ;
unsigned long V_136 ;
V_47 = (struct V_47 * ) V_112 ;
V_113 = ! ! ( V_47 -> V_58 & V_92 ) ;
V_136 = F_30 ( V_111 ) ;
F_6 ( & V_30 -> V_128 ) ;
if ( F_28 ( & V_30 -> V_123 ) && ! V_114 ) {
F_64 (forw_packet_pos,
&bat_priv->forw_bat_list, list) {
if ( F_49 ( V_47 ,
V_30 , V_75 ,
V_106 , V_113 ,
V_91 ,
V_104 ,
V_135 ) ) {
V_115 = V_135 ;
break;
}
}
}
if ( ! V_115 ) {
F_8 ( & V_30 -> V_128 ) ;
if ( ! V_114 && F_28 ( & V_30 -> V_123 ) )
V_106 += V_136 ;
F_52 ( V_112 , V_75 ,
V_106 , V_113 ,
V_91 , V_104 ,
V_114 ) ;
} else {
F_62 ( V_115 , V_112 ,
V_75 , V_113 ) ;
F_8 ( & V_30 -> V_128 ) ;
}
}
static void F_65 ( struct V_9 * V_10 ,
const struct V_137 * V_137 ,
struct V_47 * V_47 ,
bool V_138 ,
bool V_139 ,
struct V_41 * V_91 ,
struct V_41 * V_104 )
{
struct V_29 * V_30 = F_36 ( V_91 -> V_81 ) ;
T_2 V_76 ;
if ( V_47 -> V_57 <= 1 ) {
F_38 ( V_94 , V_30 , L_10 ) ;
return;
}
if ( ! V_139 ) {
if ( V_138 )
V_47 -> V_58 |= V_140 ;
else
return;
}
V_76 = F_34 ( V_47 -> V_76 ) ;
V_47 -> V_57 -- ;
F_25 ( V_47 -> V_66 , V_137 -> V_141 ) ;
V_47 -> V_61 = F_32 ( V_47 -> V_61 ,
V_30 ) ;
F_38 ( V_94 , V_30 ,
L_11 ,
V_47 -> V_61 , V_47 -> V_57 ) ;
if ( V_138 )
V_47 -> V_58 |= V_92 ;
else
V_47 -> V_58 &= ~ V_92 ;
F_63 ( V_30 , ( unsigned char * ) V_47 ,
V_52 + V_76 ,
V_91 , V_104 , 0 ,
F_31 () ) ;
}
static void
F_66 ( struct V_41 * V_42 )
{
struct V_29 * V_30 = F_36 ( V_42 -> V_81 ) ;
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
F_67 () ;
F_68 (orig_node, head, hash_entry) {
F_6 ( & V_10 -> V_11 . V_19 ) ;
V_147 = V_42 -> V_149 * V_20 ;
V_146 = & V_10 -> V_11 . V_12 [ V_147 ] ;
F_69 ( V_30 , V_146 , 1 , 0 ) ;
V_149 = V_42 -> V_149 ;
V_148 = & V_10 -> V_11 . V_13 [ V_149 ] ;
* V_148 = F_70 ( V_146 , V_151 ) ;
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
struct V_41 * V_103 , * V_152 ;
int * V_51 = & V_42 -> V_11 . V_51 ;
T_4 V_95 ;
T_2 V_76 = 0 ;
unsigned long V_106 ;
V_103 = F_47 ( V_30 ) ;
if ( V_42 == V_103 ) {
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
V_106 = F_27 ( V_30 ) ;
if ( V_42 != V_103 ) {
F_63 ( V_30 , * V_48 , * V_51 ,
V_42 , V_42 , 1 , V_106 ) ;
goto V_46;
}
F_67 () ;
F_77 (tmp_hard_iface, &batadv_hardif_list, list) {
if ( V_152 -> V_81 != V_42 -> V_81 )
continue;
F_63 ( V_30 , * V_48 ,
* V_51 , V_42 ,
V_152 , 1 , V_106 ) ;
}
F_71 () ;
V_46:
if ( V_103 )
F_48 ( V_103 ) ;
}
static void
F_78 ( struct V_29 * V_30 ,
struct V_9 * V_10 ,
struct V_153 * V_154 ,
const struct V_137 * V_137 ,
const struct V_47 * V_47 ,
struct V_41 * V_91 ,
struct V_41 * V_104 ,
enum V_155 V_156 )
{
struct V_157 * V_158 = NULL ;
struct V_157 * V_159 = NULL ;
struct V_40 * V_45 = NULL ;
struct V_40 * V_160 = NULL ;
struct V_40 * V_161 = NULL ;
struct V_9 * V_162 ;
int V_149 ;
T_1 V_163 , V_164 ;
T_1 * V_43 ;
T_1 V_165 ;
F_38 ( V_94 , V_30 ,
L_12 ) ;
F_67 () ;
F_68 (tmp_neigh_node,
&orig_node->neigh_list, list) {
V_43 = V_160 -> V_31 ;
if ( F_79 ( V_43 , V_137 -> V_141 ) &&
V_160 -> V_91 == V_91 &&
F_53 ( & V_160 -> V_118 ) ) {
if ( F_80 ( V_45 , L_13 ) )
F_81 ( V_45 ) ;
V_45 = V_160 ;
continue;
}
if ( V_156 != V_166 )
continue;
V_158 = F_82 ( V_160 ,
V_104 ) ;
if ( ! V_158 )
continue;
F_6 ( & V_160 -> V_167 ) ;
F_1 ( V_158 -> V_11 . V_168 ,
& V_158 -> V_11 . V_169 , 0 ) ;
V_165 = F_2 ( V_158 -> V_11 . V_168 ) ;
V_158 -> V_11 . V_165 = V_165 ;
F_8 ( & V_160 -> V_167 ) ;
F_83 ( V_158 ) ;
V_158 = NULL ;
}
if ( ! V_45 ) {
struct V_9 * V_170 ;
V_170 = F_10 ( V_30 , V_137 -> V_141 ) ;
if ( ! V_170 )
goto V_22;
V_45 = F_17 ( V_91 ,
V_137 -> V_141 ,
V_10 , V_170 ) ;
F_16 ( V_170 ) ;
if ( ! V_45 )
goto V_22;
} else {
F_38 ( V_94 , V_30 ,
L_14 ) ;
}
F_71 () ;
V_158 = F_84 ( V_45 , V_104 ) ;
if ( ! V_158 )
goto V_46;
V_45 -> V_171 = V_71 ;
F_6 ( & V_45 -> V_167 ) ;
F_1 ( V_158 -> V_11 . V_168 ,
& V_158 -> V_11 . V_169 ,
V_47 -> V_61 ) ;
V_165 = F_2 ( V_158 -> V_11 . V_168 ) ;
V_158 -> V_11 . V_165 = V_165 ;
F_8 ( & V_45 -> V_167 ) ;
if ( V_156 == V_166 ) {
V_154 -> V_172 = V_47 -> V_57 ;
V_158 -> V_172 = V_47 -> V_57 ;
}
V_161 = F_85 ( V_10 , V_104 ) ;
if ( V_161 == V_45 )
goto V_46;
if ( V_161 ) {
V_159 = F_82 ( V_161 , V_104 ) ;
if ( ! V_159 )
goto V_46;
if ( V_159 -> V_11 . V_165 > V_158 -> V_11 . V_165 )
goto V_46;
}
if ( V_159 &&
V_158 -> V_11 . V_165 == V_159 -> V_11 . V_165 ) {
V_162 = V_161 -> V_10 ;
F_6 ( & V_162 -> V_11 . V_19 ) ;
V_149 = V_161 -> V_91 -> V_149 ;
V_163 = V_162 -> V_11 . V_13 [ V_149 ] ;
F_8 ( & V_162 -> V_11 . V_19 ) ;
V_162 = V_45 -> V_10 ;
F_6 ( & V_162 -> V_11 . V_19 ) ;
V_149 = V_45 -> V_91 -> V_149 ;
V_164 = V_162 -> V_11 . V_13 [ V_149 ] ;
F_8 ( & V_162 -> V_11 . V_19 ) ;
if ( V_163 >= V_164 )
goto V_46;
}
F_86 ( V_30 , V_10 , V_104 , V_45 ) ;
goto V_46;
V_22:
F_71 () ;
V_46:
if ( V_45 )
F_81 ( V_45 ) ;
if ( V_161 )
F_81 ( V_161 ) ;
if ( V_158 )
F_83 ( V_158 ) ;
if ( V_159 )
F_83 ( V_159 ) ;
}
static int F_87 ( struct V_9 * V_10 ,
struct V_9 * V_173 ,
struct V_47 * V_47 ,
struct V_41 * V_91 ,
struct V_41 * V_104 )
{
struct V_29 * V_30 = F_36 ( V_91 -> V_81 ) ;
struct V_40 * V_45 = NULL , * V_160 ;
struct V_157 * V_158 ;
T_1 V_174 ;
T_1 V_175 , V_176 , V_177 , V_178 ;
unsigned int V_179 , V_180 ;
int V_181 , V_182 , V_149 , V_17 = 0 ;
unsigned int V_183 ;
int V_184 ;
F_67 () ;
F_68 (tmp_neigh_node,
&orig_neigh_node->neigh_list, list) {
if ( ! F_79 ( V_160 -> V_31 ,
V_173 -> V_63 ) )
continue;
if ( V_160 -> V_91 != V_91 )
continue;
if ( ! F_53 ( & V_160 -> V_118 ) )
continue;
V_45 = V_160 ;
break;
}
F_71 () ;
if ( ! V_45 )
V_45 = F_17 ( V_91 ,
V_173 -> V_63 ,
V_173 ,
V_173 ) ;
if ( ! V_45 )
goto V_46;
if ( V_10 == V_173 )
V_45 -> V_171 = V_71 ;
V_10 -> V_171 = V_71 ;
F_6 ( & V_10 -> V_11 . V_19 ) ;
V_149 = V_91 -> V_149 ;
V_175 = V_173 -> V_11 . V_13 [ V_149 ] ;
V_158 = F_84 ( V_45 , V_104 ) ;
if ( V_158 ) {
V_176 = V_158 -> V_11 . V_185 ;
F_83 ( V_158 ) ;
} else {
V_176 = 0 ;
}
F_8 ( & V_10 -> V_11 . V_19 ) ;
if ( V_175 > V_176 )
V_174 = V_176 ;
else
V_174 = V_175 ;
if ( V_174 < V_186 ||
V_176 < V_187 )
V_178 = 0 ;
else
V_178 = ( V_62 * V_174 ) / V_176 ;
V_177 = V_151 - V_176 ;
V_179 = V_177 * V_177 * V_177 ;
V_180 = V_151 *
V_151 *
V_151 ;
V_182 = V_62 * V_179 ;
V_182 /= V_180 ;
V_181 = V_62 - V_182 ;
V_184 = V_62 ;
if ( V_104 && ( V_91 == V_104 ) &&
F_88 ( V_104 -> V_64 ) )
V_184 = F_32 ( V_62 ,
V_30 ) ;
V_183 = V_47 -> V_61 *
V_178 *
V_181 *
V_184 ;
V_183 /= V_62 *
V_62 *
V_62 ;
V_47 -> V_61 = V_183 ;
F_38 ( V_94 , V_30 ,
L_15 ,
V_10 -> V_63 , V_173 -> V_63 , V_174 ,
V_176 , V_178 , V_181 , V_184 ,
V_47 -> V_61 , V_91 -> V_64 -> V_96 ,
V_104 ? V_104 -> V_64 -> V_96 : L_16 ) ;
if ( V_47 -> V_61 >= V_188 )
V_17 = 1 ;
V_46:
if ( V_45 )
F_81 ( V_45 ) ;
return V_17 ;
}
static enum V_155
F_89 ( const struct V_137 * V_137 ,
const struct V_47 * V_47 ,
const struct V_41 * V_91 ,
struct V_41 * V_104 )
{
struct V_29 * V_30 = F_36 ( V_91 -> V_81 ) ;
struct V_9 * V_10 ;
struct V_153 * V_154 = NULL ;
struct V_40 * V_45 ;
struct V_157 * V_158 ;
int V_189 ;
T_7 V_190 ;
int V_191 = 0 ;
int V_192 ;
enum V_155 V_17 = V_166 ;
T_4 V_95 = F_39 ( V_47 -> V_95 ) ;
T_1 * V_43 ;
T_1 V_193 ;
unsigned long * V_194 ;
V_10 = F_10 ( V_30 , V_47 -> V_63 ) ;
if ( ! V_10 )
return V_166 ;
V_154 = F_90 ( V_10 , V_104 ) ;
if ( F_46 ( ! V_154 ) ) {
F_16 ( V_10 ) ;
return 0 ;
}
F_6 ( & V_10 -> V_11 . V_19 ) ;
V_190 = V_95 - V_154 -> V_195 ;
if ( ! F_91 ( & V_10 -> V_196 ) &&
F_92 ( V_30 , V_190 ,
& V_154 -> V_197 ) ) {
V_17 = V_198 ;
goto V_46;
}
F_67 () ;
F_68 (neigh_node, &orig_node->neigh_list, list) {
V_158 = F_84 ( V_45 ,
V_104 ) ;
if ( ! V_158 )
continue;
V_43 = V_45 -> V_31 ;
V_189 = F_93 ( V_158 -> V_11 . V_199 ,
V_154 -> V_195 ,
V_95 ) ;
if ( F_79 ( V_43 , V_137 -> V_141 ) &&
V_45 -> V_91 == V_91 ) {
V_192 = 1 ;
if ( V_189 )
V_17 = V_200 ;
} else {
V_192 = 0 ;
if ( V_189 && ( V_17 != V_200 ) )
V_17 = V_201 ;
}
V_194 = V_158 -> V_11 . V_199 ;
V_191 |= F_69 ( V_30 , V_194 ,
V_190 , V_192 ) ;
V_193 = F_70 ( V_194 ,
V_151 ) ;
V_158 -> V_11 . V_185 = V_193 ;
F_83 ( V_158 ) ;
}
F_71 () ;
if ( V_191 ) {
F_38 ( V_94 , V_30 ,
L_17 ,
V_104 ? V_104 -> V_64 -> V_96 : L_16 ,
V_154 -> V_195 , V_95 ) ;
V_154 -> V_195 = V_95 ;
}
V_46:
F_8 ( & V_10 -> V_11 . V_19 ) ;
F_16 ( V_10 ) ;
F_94 ( V_154 ) ;
return V_17 ;
}
static void
F_95 ( const struct V_84 * V_85 , int V_202 ,
struct V_9 * V_10 ,
struct V_41 * V_91 ,
struct V_41 * V_104 )
{
struct V_29 * V_30 = F_36 ( V_91 -> V_81 ) ;
struct V_203 * V_204 = NULL ;
struct V_40 * V_161 = NULL ;
struct V_40 * V_205 = NULL ;
struct V_9 * V_173 ;
struct V_153 * V_154 ;
struct V_40 * V_206 = NULL ;
struct V_157 * V_159 = NULL ;
struct V_47 * V_207 ;
enum V_155 V_156 ;
bool V_139 = false ;
bool V_138 = false ;
bool V_208 , V_209 ;
struct V_84 * V_210 ;
struct V_137 * V_137 ;
T_1 * V_66 ;
int V_211 ;
V_210 = F_96 ( V_85 , V_21 ) ;
if ( ! V_210 )
return;
V_137 = F_97 ( V_210 ) ;
V_207 = (struct V_47 * ) ( V_210 -> V_89 + V_202 ) ;
V_156 = F_89 ( V_137 , V_207 ,
V_91 , V_104 ) ;
if ( F_79 ( V_137 -> V_141 , V_207 -> V_63 ) )
V_138 = true ;
if ( V_156 == V_198 ) {
F_38 ( V_94 , V_30 ,
L_18 ,
V_137 -> V_141 ) ;
goto V_46;
}
if ( V_207 -> V_61 == 0 ) {
F_38 ( V_94 , V_30 ,
L_19 ) ;
goto V_46;
}
if ( V_138 ) {
V_204 = F_98 ( V_91 ,
V_137 -> V_141 ) ;
if ( V_204 )
V_204 -> V_171 = V_71 ;
}
V_161 = F_85 ( V_10 , V_104 ) ;
if ( V_161 ) {
V_205 = F_85 ( V_161 -> V_10 ,
V_104 ) ;
V_159 = F_82 ( V_161 , V_104 ) ;
}
if ( ( V_159 && V_159 -> V_11 . V_165 != 0 ) &&
( F_79 ( V_161 -> V_31 , V_137 -> V_141 ) ) )
V_139 = true ;
V_66 = V_207 -> V_66 ;
if ( V_161 && V_205 &&
( F_79 ( V_161 -> V_31 , V_66 ) ) &&
! ( F_79 ( V_207 -> V_63 , V_66 ) ) &&
( F_79 ( V_161 -> V_31 , V_205 -> V_31 ) ) ) {
F_38 ( V_94 , V_30 ,
L_20 ,
V_137 -> V_141 ) ;
goto V_46;
}
if ( V_104 == V_212 )
F_99 ( V_30 , V_207 , V_10 ) ;
if ( V_138 )
V_173 = V_10 ;
else
V_173 = F_10 ( V_30 ,
V_137 -> V_141 ) ;
if ( ! V_173 )
goto V_46;
F_100 ( V_30 , V_10 , V_173 ,
V_207 , V_138 ) ;
V_206 = F_85 ( V_173 ,
V_104 ) ;
if ( ! V_138 && ( ! V_206 ) ) {
F_38 ( V_94 , V_30 ,
L_21 ) ;
goto V_213;
}
V_211 = F_87 ( V_10 , V_173 ,
V_207 , V_91 ,
V_104 ) ;
V_154 = F_90 ( V_10 , V_104 ) ;
if ( ! V_154 )
goto V_213;
V_208 = V_154 -> V_195 == F_39 ( V_207 -> V_95 ) ;
V_209 = ( V_154 -> V_172 - 3 ) <= V_207 -> V_57 ;
if ( V_211 && ( ( V_156 == V_166 ) ||
( V_208 && V_209 ) ) ) {
F_78 ( V_30 , V_10 ,
V_154 , V_137 ,
V_207 , V_91 ,
V_104 , V_156 ) ;
}
F_94 ( V_154 ) ;
if ( V_104 == V_212 )
goto V_213;
if ( V_138 ) {
if ( ( V_207 -> V_57 <= 2 ) &&
( V_91 != V_104 ) ) {
F_38 ( V_94 , V_30 ,
L_22 ) ;
goto V_213;
}
F_65 ( V_10 , V_137 , V_207 ,
V_138 ,
V_139 , V_91 ,
V_104 ) ;
F_38 ( V_94 , V_30 ,
L_23 ) ;
goto V_213;
}
if ( ! V_211 ) {
F_38 ( V_94 , V_30 ,
L_24 ) ;
goto V_213;
}
if ( V_156 == V_200 ) {
F_38 ( V_94 , V_30 ,
L_25 ) ;
goto V_213;
}
F_38 ( V_94 , V_30 ,
L_26 ) ;
F_65 ( V_10 , V_137 , V_207 ,
V_138 , V_139 ,
V_91 , V_104 ) ;
V_213:
if ( ( V_173 ) && ( ! V_138 ) )
F_16 ( V_173 ) ;
V_46:
if ( V_159 )
F_83 ( V_159 ) ;
if ( V_161 )
F_81 ( V_161 ) ;
if ( V_205 )
F_81 ( V_205 ) ;
if ( V_206 )
F_81 ( V_206 ) ;
if ( V_204 )
F_101 ( V_204 ) ;
F_102 ( V_210 ) ;
}
static void F_103 ( const struct V_84 * V_85 , int V_202 ,
struct V_41 * V_91 )
{
struct V_29 * V_30 = F_36 ( V_91 -> V_81 ) ;
struct V_9 * V_173 , * V_10 ;
struct V_41 * V_42 ;
struct V_47 * V_207 ;
T_4 V_214 ;
bool V_215 ;
struct V_137 * V_137 ;
bool V_216 = false ;
bool V_217 = false ;
bool V_218 = false ;
V_207 = (struct V_47 * ) ( V_85 -> V_89 + V_202 ) ;
V_137 = F_97 ( V_85 ) ;
if ( V_207 -> V_53 != V_54 )
return;
V_214 = F_28 ( & V_91 -> V_11 . V_50 ) ;
if ( V_207 -> V_58 & V_92 )
V_215 = true ;
else
V_215 = false ;
F_38 ( V_94 , V_30 ,
L_27 ,
V_137 -> V_141 , V_91 -> V_64 -> V_96 ,
V_91 -> V_64 -> V_65 , V_207 -> V_63 ,
V_207 -> V_66 , F_39 ( V_207 -> V_95 ) ,
V_207 -> V_61 , V_207 -> V_57 ,
V_207 -> V_55 , V_215 ) ;
F_67 () ;
F_77 (hard_iface, &batadv_hardif_list, list) {
if ( V_42 -> V_87 != V_88 )
continue;
if ( V_42 -> V_81 != V_91 -> V_81 )
continue;
if ( F_79 ( V_137 -> V_141 ,
V_42 -> V_64 -> V_65 ) )
V_217 = true ;
if ( F_79 ( V_207 -> V_63 ,
V_42 -> V_64 -> V_65 ) )
V_218 = true ;
if ( F_79 ( V_207 -> V_66 ,
V_42 -> V_64 -> V_65 ) )
V_216 = true ;
}
F_71 () ;
if ( V_217 ) {
F_38 ( V_94 , V_30 ,
L_28 ,
V_137 -> V_141 ) ;
return;
}
if ( V_218 ) {
unsigned long * V_146 ;
int V_219 ;
T_7 V_220 ;
T_6 V_149 ;
T_1 * V_221 ;
V_173 = F_10 ( V_30 ,
V_137 -> V_141 ) ;
if ( ! V_173 )
return;
if ( V_215 &&
F_79 ( V_91 -> V_64 -> V_65 ,
V_207 -> V_63 ) ) {
V_149 = V_91 -> V_149 ;
V_219 = V_149 * V_20 ;
F_6 ( & V_173 -> V_11 . V_19 ) ;
V_146 = & V_173 -> V_11 . V_12 [ V_219 ] ;
V_220 = V_214 - 2 ;
V_220 -= F_39 ( V_207 -> V_95 ) ;
F_104 ( V_146 , V_220 ) ;
V_221 = & V_173 -> V_11 . V_13 [ V_149 ] ;
* V_221 = F_70 ( V_146 ,
V_151 ) ;
F_8 ( & V_173 -> V_11 . V_19 ) ;
}
F_38 ( V_94 , V_30 ,
L_29 ) ;
F_16 ( V_173 ) ;
return;
}
if ( V_216 ) {
F_38 ( V_94 , V_30 ,
L_30 ,
V_137 -> V_141 ) ;
return;
}
if ( V_207 -> V_58 & V_140 ) {
F_38 ( V_94 , V_30 ,
L_31 ,
V_137 -> V_141 ) ;
return;
}
V_10 = F_10 ( V_30 , V_207 -> V_63 ) ;
if ( ! V_10 )
return;
F_95 ( V_85 , V_202 , V_10 ,
V_91 , V_212 ) ;
F_67 () ;
F_77 (hard_iface, &batadv_hardif_list, list) {
if ( V_42 -> V_87 != V_88 )
continue;
if ( V_42 -> V_81 != V_30 -> V_81 )
continue;
F_95 ( V_85 , V_202 , V_10 ,
V_91 , V_42 ) ;
}
F_71 () ;
F_16 ( V_10 ) ;
}
static int F_105 ( struct V_84 * V_85 ,
struct V_41 * V_91 )
{
struct V_29 * V_30 = F_36 ( V_91 -> V_81 ) ;
struct V_47 * V_207 ;
T_1 * V_86 ;
int V_202 ;
bool V_17 ;
V_17 = F_106 ( V_85 , V_91 , V_52 ) ;
if ( ! V_17 )
return V_222 ;
if ( V_30 -> V_223 -> V_224 != F_44 )
return V_222 ;
F_41 ( V_30 , V_225 ) ;
F_42 ( V_30 , V_226 ,
V_85 -> V_99 + V_100 ) ;
V_202 = 0 ;
V_207 = (struct V_47 * ) V_85 -> V_89 ;
while ( F_33 ( V_202 , F_107 ( V_85 ) ,
V_207 -> V_76 ) ) {
F_103 ( V_85 , V_202 , V_91 ) ;
V_202 += V_52 ;
V_202 += F_34 ( V_207 -> V_76 ) ;
V_86 = V_85 -> V_89 + V_202 ;
V_207 = (struct V_47 * ) V_86 ;
}
F_102 ( V_85 ) ;
return V_227 ;
}
static void
F_108 ( struct V_9 * V_10 ,
struct V_41 * V_104 ,
struct V_228 * V_229 )
{
struct V_40 * V_45 ;
struct V_157 * V_230 ;
F_68 (neigh_node, &orig_node->neigh_list, list) {
V_230 = F_82 ( V_45 , V_104 ) ;
if ( ! V_230 )
continue;
F_109 ( V_229 , L_32 ,
V_45 -> V_31 ,
V_230 -> V_11 . V_165 ) ;
F_83 ( V_230 ) ;
}
}
static void F_110 ( struct V_29 * V_30 ,
struct V_228 * V_229 ,
struct V_41 * V_104 )
{
struct V_40 * V_45 ;
struct V_142 * V_143 = V_30 -> V_36 ;
int V_231 , V_232 ;
struct V_9 * V_10 ;
struct V_157 * V_230 ;
unsigned long V_233 ;
struct V_144 * V_145 ;
int V_234 = 0 ;
T_4 V_7 ;
F_109 ( V_229 , L_33 ,
L_34 , L_35 , L_36 , V_62 ,
L_37 , L_38 , L_39 ) ;
for ( V_7 = 0 ; V_7 < V_143 -> V_32 ; V_7 ++ ) {
V_145 = & V_143 -> V_150 [ V_7 ] ;
F_67 () ;
F_68 (orig_node, head, hash_entry) {
V_45 = F_85 ( V_10 ,
V_104 ) ;
if ( ! V_45 )
continue;
V_230 = F_82 ( V_45 ,
V_104 ) ;
if ( ! V_230 )
goto V_235;
if ( V_230 -> V_11 . V_165 == 0 )
goto V_235;
V_233 = V_71 - V_10 -> V_171 ;
V_231 = F_111 ( V_233 ) ;
V_232 = V_231 / 1000 ;
V_231 = V_231 % 1000 ;
F_109 ( V_229 , L_40 ,
V_10 -> V_63 , V_232 ,
V_231 , V_230 -> V_11 . V_165 ,
V_45 -> V_31 ,
V_45 -> V_91 -> V_64 -> V_96 ) ;
F_108 ( V_10 , V_104 ,
V_229 ) ;
F_112 ( V_229 , L_41 ) ;
V_234 ++ ;
V_235:
F_81 ( V_45 ) ;
if ( V_230 )
F_83 ( V_230 ) ;
}
F_71 () ;
}
if ( V_234 == 0 )
F_112 ( V_229 , L_42 ) ;
}
static void
F_113 ( struct V_228 * V_229 ,
struct V_203 * V_204 )
{
int V_236 , V_237 ;
V_236 = F_111 ( V_71 - V_204 -> V_171 ) / 1000 ;
V_237 = F_111 ( V_71 - V_204 -> V_171 ) % 1000 ;
F_109 ( V_229 , L_43 ,
V_204 -> V_91 -> V_64 -> V_96 ,
V_204 -> V_31 , V_236 , V_237 ) ;
}
static void F_114 ( struct V_29 * V_30 ,
struct V_228 * V_229 )
{
struct V_102 * V_64 = (struct V_102 * ) V_229 -> V_238 ;
struct V_203 * V_204 ;
struct V_41 * V_42 ;
int V_234 = 0 ;
F_109 ( V_229 , L_44 ,
L_45 , L_46 , L_35 ) ;
F_67 () ;
F_77 (hard_iface, &batadv_hardif_list, list) {
if ( V_42 -> V_81 != V_64 )
continue;
F_68 (hardif_neigh,
&hard_iface->neigh_list, list) {
F_113 ( V_229 , V_204 ) ;
V_234 ++ ;
}
}
F_71 () ;
if ( V_234 == 0 )
F_112 ( V_229 , L_42 ) ;
}
static int F_115 ( struct V_40 * V_239 ,
struct V_41 * V_240 ,
struct V_40 * V_241 ,
struct V_41 * V_242 )
{
struct V_157 * V_243 , * V_244 ;
T_1 V_245 , V_246 ;
int V_247 ;
V_243 = F_82 ( V_239 , V_240 ) ;
V_244 = F_82 ( V_241 , V_242 ) ;
if ( ! V_243 || ! V_244 ) {
V_247 = 0 ;
goto V_46;
}
V_245 = V_243 -> V_11 . V_165 ;
V_246 = V_244 -> V_11 . V_165 ;
V_247 = V_245 - V_246 ;
V_46:
if ( V_243 )
F_83 ( V_243 ) ;
if ( V_244 )
F_83 ( V_244 ) ;
return V_247 ;
}
static bool
F_116 ( struct V_40 * V_239 ,
struct V_41 * V_240 ,
struct V_40 * V_241 ,
struct V_41 * V_242 )
{
struct V_157 * V_243 , * V_244 ;
T_1 V_245 , V_246 ;
bool V_17 ;
V_243 = F_82 ( V_239 , V_240 ) ;
V_244 = F_82 ( V_241 , V_242 ) ;
if ( ! V_243 || ! V_244 ) {
V_17 = false ;
goto V_46;
}
V_245 = V_243 -> V_11 . V_165 ;
V_246 = V_244 -> V_11 . V_165 ;
V_17 = ( V_245 - V_246 ) > - V_248 ;
V_46:
if ( V_243 )
F_83 ( V_243 ) ;
if ( V_244 )
F_83 ( V_244 ) ;
return V_17 ;
}
int T_8 F_117 ( void )
{
int V_17 ;
V_17 = F_118 ( V_54 ,
F_105 ) ;
if ( V_17 < 0 )
goto V_46;
V_17 = F_119 ( & V_249 ) ;
if ( V_17 < 0 )
goto V_250;
goto V_46;
V_250:
F_120 ( V_54 ) ;
V_46:
return V_17 ;
}

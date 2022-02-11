static void F_1 ( T_1 V_1 [] , T_1 * V_2 ,
T_1 V_3 )
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
int V_24 , V_17 = - V_18 , V_25 ;
void * V_15 = NULL ;
F_6 ( & V_10 -> V_11 . V_19 ) ;
if ( V_14 == 0 )
goto V_26;
V_24 = sizeof( unsigned long ) * V_20 ;
V_15 = F_7 ( V_14 , V_24 , V_21 ) ;
if ( ! V_15 )
goto V_22;
memcpy ( V_15 , V_10 -> V_11 . V_12 , V_23 * V_24 ) ;
memcpy ( ( char * ) V_15 + V_23 * V_24 ,
V_10 -> V_11 . V_12 + ( ( V_23 + 1 ) * V_24 ) ,
( V_14 - V_23 ) * V_24 ) ;
V_26:
F_4 ( V_10 -> V_11 . V_12 ) ;
V_10 -> V_11 . V_12 = V_15 ;
if ( V_14 == 0 )
goto V_27;
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
V_27:
F_4 ( V_10 -> V_11 . V_13 ) ;
V_10 -> V_11 . V_13 = V_15 ;
V_17 = 0 ;
V_22:
F_8 ( & V_10 -> V_11 . V_19 ) ;
return V_17 ;
}
static struct V_9 *
F_10 ( struct V_28 * V_29 , const T_1 * V_30 )
{
struct V_9 * V_10 ;
int V_31 , V_32 ;
V_10 = F_11 ( V_29 , V_30 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_12 ( V_29 , V_30 ) ;
if ( ! V_10 )
return NULL ;
F_13 ( & V_10 -> V_11 . V_19 ) ;
V_31 = V_29 -> V_33 * sizeof( unsigned long ) * V_20 ;
V_10 -> V_11 . V_12 = F_14 ( V_31 , V_21 ) ;
if ( ! V_10 -> V_11 . V_12 )
goto V_34;
V_31 = V_29 -> V_33 * sizeof( T_1 ) ;
V_10 -> V_11 . V_13 = F_14 ( V_31 , V_21 ) ;
if ( ! V_10 -> V_11 . V_13 )
goto V_34;
V_32 = F_15 ( V_29 -> V_35 , V_36 ,
V_37 , V_10 ,
& V_10 -> V_38 ) ;
if ( V_32 != 0 )
goto V_34;
return V_10 ;
V_34:
F_16 ( V_10 ) ;
F_16 ( V_10 ) ;
return NULL ;
}
static struct V_39 *
F_17 ( struct V_40 * V_41 ,
const T_1 * V_42 ,
struct V_9 * V_10 ,
struct V_9 * V_43 )
{
struct V_28 * V_29 = F_18 ( V_41 -> V_44 ) ;
struct V_39 * V_45 , * V_46 ;
V_45 = F_19 ( V_41 , V_42 , V_10 ) ;
if ( ! V_45 )
goto V_47;
if ( ! F_20 ( & V_41 -> V_48 ) ) {
F_4 ( V_45 ) ;
V_45 = NULL ;
goto V_47;
}
V_45 -> V_10 = V_43 ;
V_45 -> V_49 = V_41 ;
F_6 ( & V_10 -> V_50 ) ;
V_46 = F_21 ( V_10 , V_41 ,
V_42 ) ;
if ( ! V_46 ) {
F_22 ( & V_45 -> V_51 , & V_10 -> V_52 ) ;
} else {
F_4 ( V_45 ) ;
F_23 ( V_41 ) ;
V_45 = V_46 ;
}
F_8 ( & V_10 -> V_50 ) ;
if ( ! V_46 )
F_24 ( V_53 , V_29 ,
L_1 ,
V_42 , V_10 -> V_54 ,
V_41 -> V_55 -> V_56 ) ;
V_47:
return V_45 ;
}
static int F_25 ( struct V_40 * V_41 )
{
struct V_57 * V_57 ;
unsigned char * V_58 ;
T_4 V_59 ;
F_26 ( & V_59 , sizeof( V_59 ) ) ;
F_27 ( & V_41 -> V_11 . V_60 , V_59 ) ;
V_41 -> V_11 . V_61 = V_62 ;
V_58 = F_28 ( V_41 -> V_11 . V_61 , V_21 ) ;
if ( ! V_58 )
return - V_18 ;
V_41 -> V_11 . V_58 = V_58 ;
V_57 = (struct V_57 * ) V_58 ;
V_57 -> V_63 = V_64 ;
V_57 -> V_65 = V_66 ;
V_57 -> V_67 = 2 ;
V_57 -> V_68 = V_69 ;
V_57 -> V_70 = 0 ;
V_57 -> V_71 = V_72 ;
return 0 ;
}
static void F_29 ( struct V_40 * V_41 )
{
F_4 ( V_41 -> V_11 . V_58 ) ;
V_41 -> V_11 . V_58 = NULL ;
}
static void F_30 ( struct V_40 * V_41 )
{
struct V_57 * V_57 ;
unsigned char * V_58 = V_41 -> V_11 . V_58 ;
V_57 = (struct V_57 * ) V_58 ;
F_31 ( V_57 -> V_54 ,
V_41 -> V_55 -> V_73 ) ;
F_31 ( V_57 -> V_74 ,
V_41 -> V_55 -> V_73 ) ;
}
static void
F_32 ( struct V_40 * V_41 )
{
struct V_57 * V_57 ;
unsigned char * V_58 = V_41 -> V_11 . V_58 ;
V_57 = (struct V_57 * ) V_58 ;
V_57 -> V_68 = V_75 ;
V_57 -> V_67 = V_76 ;
}
static unsigned long
F_33 ( const struct V_28 * V_29 )
{
unsigned int V_77 ;
V_77 = F_34 ( & V_29 -> V_78 ) - V_79 ;
V_77 += F_35 () % ( 2 * V_79 ) ;
return V_80 + F_36 ( V_77 ) ;
}
static unsigned long F_37 ( void )
{
return V_80 + F_36 ( F_35 () % ( V_79 / 2 ) ) ;
}
static T_1 F_38 ( T_1 V_71 ,
const struct V_28 * V_29 )
{
int V_81 = F_34 ( & V_29 -> V_81 ) ;
int V_82 ;
V_82 = V_71 * ( V_72 - V_81 ) ;
V_82 /= V_72 ;
return V_82 ;
}
static bool F_39 ( int V_83 , int V_84 ,
T_5 V_85 )
{
int V_86 = 0 ;
V_86 += V_83 + V_62 ;
V_86 += F_40 ( V_85 ) ;
return ( V_86 <= V_84 ) &&
( V_86 <= V_87 ) ;
}
static void F_41 ( struct V_88 * V_89 ,
struct V_40 * V_41 )
{
struct V_28 * V_29 = F_18 ( V_41 -> V_44 ) ;
const char * V_90 ;
T_1 V_91 ;
T_6 V_83 ;
struct V_57 * V_57 ;
struct V_92 * V_93 ;
T_1 * V_94 ;
if ( V_41 -> V_95 != V_96 )
return;
V_91 = 0 ;
V_83 = 0 ;
V_94 = V_89 -> V_93 -> V_97 ;
V_57 = (struct V_57 * ) V_94 ;
while ( F_39 ( V_83 , V_89 -> V_84 ,
V_57 -> V_85 ) ) {
if ( V_89 -> V_98 & F_42 ( V_91 ) &&
V_89 -> V_49 == V_41 )
V_57 -> V_68 |= V_99 ;
else
V_57 -> V_68 &= ~ V_99 ;
if ( V_91 > 0 || ! V_89 -> V_100 )
V_90 = L_2 ;
else
V_90 = L_3 ;
F_24 ( V_53 , V_29 ,
L_4 ,
V_90 , ( V_91 > 0 ? L_5 : L_6 ) ,
V_57 -> V_54 ,
F_43 ( V_57 -> V_101 ) ,
V_57 -> V_71 , V_57 -> V_67 ,
( ( V_57 -> V_68 & V_99 ) ?
L_7 : L_8 ) ,
V_41 -> V_55 -> V_56 ,
V_41 -> V_55 -> V_73 ) ;
V_83 += V_62 ;
V_83 += F_40 ( V_57 -> V_85 ) ;
V_91 ++ ;
V_94 = V_89 -> V_93 -> V_97 + V_83 ;
V_57 = (struct V_57 * ) V_94 ;
}
V_93 = F_44 ( V_89 -> V_93 , V_21 ) ;
if ( V_93 ) {
F_45 ( V_29 , V_102 ) ;
F_46 ( V_29 , V_103 ,
V_93 -> V_104 + V_105 ) ;
F_47 ( V_93 , V_41 , V_106 ) ;
}
}
static void F_48 ( struct V_88 * V_89 )
{
struct V_107 * V_44 ;
struct V_28 * V_29 ;
struct V_40 * V_108 = NULL ;
if ( ! V_89 -> V_49 ) {
F_49 ( L_9 ) ;
goto V_47;
}
V_44 = V_89 -> V_49 -> V_44 ;
V_29 = F_18 ( V_44 ) ;
if ( F_50 ( ! V_89 -> V_109 ) )
goto V_47;
if ( F_50 ( V_89 -> V_109 -> V_44 != V_44 ) )
goto V_47;
if ( V_89 -> V_49 -> V_95 != V_96 )
goto V_47;
V_108 = F_51 ( V_29 ) ;
if ( ! V_108 )
goto V_47;
F_41 ( V_89 , V_89 -> V_109 ) ;
V_47:
if ( V_108 )
F_23 ( V_108 ) ;
}
static bool
F_52 ( const struct V_57 * V_110 ,
struct V_28 * V_29 ,
int V_84 , unsigned long V_111 ,
bool V_112 ,
const struct V_40 * V_49 ,
const struct V_40 * V_109 ,
const struct V_88 * V_89 )
{
struct V_57 * V_57 ;
int V_113 = V_89 -> V_84 + V_84 ;
struct V_40 * V_108 = NULL ;
bool V_114 = false ;
unsigned long V_115 ;
V_57 = (struct V_57 * ) V_89 -> V_93 -> V_97 ;
V_115 = V_111 ;
V_115 += F_36 ( V_116 ) ;
if ( ! F_53 ( V_111 , V_89 -> V_111 ) ||
! F_54 ( V_115 , V_89 -> V_111 ) )
return false ;
if ( V_113 > V_87 )
return false ;
if ( V_89 -> V_109 != V_109 )
return false ;
V_108 = F_51 ( V_29 ) ;
if ( ! V_108 )
return false ;
if ( ! V_112 &&
! ( V_57 -> V_68 & V_99 ) &&
V_57 -> V_67 != 1 &&
( ! V_89 -> V_100 ||
V_89 -> V_49 == V_108 ) ) {
V_114 = true ;
goto V_47;
}
if ( V_112 &&
V_110 -> V_67 == 1 &&
V_89 -> V_49 == V_49 &&
( V_57 -> V_68 & V_99 ||
( V_89 -> V_100 &&
V_89 -> V_49 != V_108 ) ) ) {
V_114 = true ;
goto V_47;
}
V_47:
if ( V_108 )
F_23 ( V_108 ) ;
return V_114 ;
}
static void F_55 ( const unsigned char * V_117 ,
int V_84 , unsigned long V_111 ,
bool V_118 ,
struct V_40 * V_49 ,
struct V_40 * V_109 ,
int V_119 )
{
struct V_28 * V_29 = F_18 ( V_49 -> V_44 ) ;
struct V_88 * V_120 ;
unsigned char * V_121 ;
unsigned int V_122 ;
if ( ! F_20 ( & V_49 -> V_48 ) )
return;
if ( ! F_20 ( & V_109 -> V_48 ) )
goto V_123;
if ( ! V_119 ) {
if ( ! F_56 ( & V_29 -> V_124 ) ) {
F_24 ( V_53 , V_29 ,
L_10 ) ;
goto V_125;
}
}
V_120 = F_28 ( sizeof( * V_120 ) , V_21 ) ;
if ( ! V_120 )
goto V_126;
if ( F_34 ( & V_29 -> V_127 ) &&
V_84 < V_87 )
V_122 = V_87 ;
else
V_122 = V_84 ;
V_122 += V_105 ;
V_120 -> V_93 = F_57 ( NULL , V_122 ) ;
if ( ! V_120 -> V_93 )
goto V_128;
V_120 -> V_93 -> V_129 = V_130 ;
F_58 ( V_120 -> V_93 , V_105 ) ;
V_121 = F_59 ( V_120 -> V_93 , V_84 ) ;
V_120 -> V_84 = V_84 ;
memcpy ( V_121 , V_117 , V_84 ) ;
V_120 -> V_100 = V_119 ;
V_120 -> V_49 = V_49 ;
V_120 -> V_109 = V_109 ;
V_120 -> V_131 = 0 ;
V_120 -> V_98 = V_69 ;
V_120 -> V_111 = V_111 ;
if ( V_118 )
V_120 -> V_98 |= 1 ;
F_6 ( & V_29 -> V_132 ) ;
F_60 ( & V_120 -> V_51 , & V_29 -> V_133 ) ;
F_8 ( & V_29 -> V_132 ) ;
F_61 ( & V_120 -> V_134 ,
V_135 ) ;
F_62 ( V_136 ,
& V_120 -> V_134 ,
V_111 - V_80 ) ;
return;
V_128:
F_4 ( V_120 ) ;
V_126:
if ( ! V_119 )
F_63 ( & V_29 -> V_124 ) ;
V_125:
F_23 ( V_109 ) ;
V_123:
F_23 ( V_49 ) ;
}
static void F_64 ( struct V_88 * V_120 ,
const unsigned char * V_117 ,
int V_84 , bool V_118 )
{
unsigned char * V_121 ;
unsigned long V_137 ;
V_121 = F_59 ( V_120 -> V_93 , V_84 ) ;
memcpy ( V_121 , V_117 , V_84 ) ;
V_120 -> V_84 += V_84 ;
V_120 -> V_131 ++ ;
if ( V_118 ) {
V_137 = F_42 ( V_120 -> V_131 ) ;
V_120 -> V_98 |= V_137 ;
}
}
static void F_65 ( struct V_28 * V_29 ,
unsigned char * V_117 ,
int V_84 ,
struct V_40 * V_49 ,
struct V_40 * V_109 ,
int V_119 , unsigned long V_111 )
{
struct V_88 * V_120 = NULL ;
struct V_88 * V_138 = NULL ;
struct V_57 * V_57 ;
bool V_118 ;
unsigned long V_139 ;
V_57 = (struct V_57 * ) V_117 ;
V_118 = ! ! ( V_57 -> V_68 & V_99 ) ;
V_139 = F_36 ( V_116 ) ;
F_6 ( & V_29 -> V_132 ) ;
if ( F_34 ( & V_29 -> V_127 ) && ! V_119 ) {
F_66 (forw_packet_pos,
&bat_priv->forw_bat_list, list) {
if ( F_52 ( V_57 ,
V_29 , V_84 ,
V_111 , V_118 ,
V_49 ,
V_109 ,
V_138 ) ) {
V_120 = V_138 ;
break;
}
}
}
if ( ! V_120 ) {
F_8 ( & V_29 -> V_132 ) ;
if ( ! V_119 && F_34 ( & V_29 -> V_127 ) )
V_111 += V_139 ;
F_55 ( V_117 , V_84 ,
V_111 , V_118 ,
V_49 , V_109 ,
V_119 ) ;
} else {
F_64 ( V_120 , V_117 ,
V_84 , V_118 ) ;
F_8 ( & V_29 -> V_132 ) ;
}
}
static void F_67 ( struct V_9 * V_10 ,
const struct V_140 * V_140 ,
struct V_57 * V_57 ,
bool V_141 ,
bool V_142 ,
struct V_40 * V_49 ,
struct V_40 * V_109 )
{
struct V_28 * V_29 = F_18 ( V_49 -> V_44 ) ;
T_2 V_85 ;
if ( V_57 -> V_67 <= 1 ) {
F_24 ( V_53 , V_29 , L_11 ) ;
return;
}
if ( ! V_142 ) {
if ( V_141 )
V_57 -> V_68 |= V_143 ;
else
return;
}
V_85 = F_40 ( V_57 -> V_85 ) ;
V_57 -> V_67 -- ;
F_31 ( V_57 -> V_74 , V_140 -> V_144 ) ;
V_57 -> V_71 = F_38 ( V_57 -> V_71 ,
V_29 ) ;
F_24 ( V_53 , V_29 ,
L_12 ,
V_57 -> V_71 , V_57 -> V_67 ) ;
V_57 -> V_68 &= ~ V_75 ;
if ( V_141 )
V_57 -> V_68 |= V_99 ;
else
V_57 -> V_68 &= ~ V_99 ;
F_65 ( V_29 , ( unsigned char * ) V_57 ,
V_62 + V_85 ,
V_49 , V_109 , 0 ,
F_37 () ) ;
}
static void
F_68 ( struct V_40 * V_41 )
{
struct V_28 * V_29 = F_18 ( V_41 -> V_44 ) ;
struct V_145 * V_146 = V_29 -> V_35 ;
struct V_147 * V_148 ;
struct V_9 * V_10 ;
unsigned long * V_149 ;
T_4 V_7 ;
T_3 V_150 ;
T_1 * V_151 ;
int V_152 ;
for ( V_7 = 0 ; V_7 < V_146 -> V_31 ; V_7 ++ ) {
V_148 = & V_146 -> V_153 [ V_7 ] ;
F_69 () ;
F_70 (orig_node, head, hash_entry) {
F_6 ( & V_10 -> V_11 . V_19 ) ;
V_150 = V_41 -> V_152 * V_20 ;
V_149 = & V_10 -> V_11 . V_12 [ V_150 ] ;
F_71 ( V_29 , V_149 , 1 , 0 ) ;
V_152 = V_41 -> V_152 ;
V_151 = & V_10 -> V_11 . V_13 [ V_152 ] ;
* V_151 = F_72 ( V_149 , V_154 ) ;
F_8 ( & V_10 -> V_11 . V_19 ) ;
}
F_73 () ;
}
}
static void F_74 ( struct V_40 * V_41 )
{
struct V_28 * V_29 = F_18 ( V_41 -> V_44 ) ;
unsigned char * * V_58 = & V_41 -> V_11 . V_58 ;
struct V_57 * V_57 ;
struct V_40 * V_108 , * V_155 ;
int * V_61 = & V_41 -> V_11 . V_61 ;
T_4 V_101 ;
T_2 V_85 = 0 ;
unsigned long V_111 ;
V_108 = F_51 ( V_29 ) ;
if ( V_41 == V_108 ) {
F_75 ( V_29 ) ;
V_85 = F_76 ( V_29 , V_58 ,
V_61 ,
V_62 ) ;
}
V_57 = (struct V_57 * ) ( * V_58 ) ;
V_57 -> V_85 = F_77 ( V_85 ) ;
V_101 = ( T_4 ) F_34 ( & V_41 -> V_11 . V_60 ) ;
V_57 -> V_101 = F_78 ( V_101 ) ;
F_63 ( & V_41 -> V_11 . V_60 ) ;
F_68 ( V_41 ) ;
V_111 = F_33 ( V_29 ) ;
if ( V_41 != V_108 ) {
F_65 ( V_29 , * V_58 , * V_61 ,
V_41 , V_41 , 1 , V_111 ) ;
goto V_47;
}
F_69 () ;
F_79 (tmp_hard_iface, &batadv_hardif_list, list) {
if ( V_155 -> V_44 != V_41 -> V_44 )
continue;
F_65 ( V_29 , * V_58 ,
* V_61 , V_41 ,
V_155 , 1 , V_111 ) ;
}
F_73 () ;
V_47:
if ( V_108 )
F_23 ( V_108 ) ;
}
static void
F_80 ( struct V_28 * V_29 ,
struct V_9 * V_10 ,
struct V_156 * V_157 ,
const struct V_140 * V_140 ,
const struct V_57 * V_57 ,
struct V_40 * V_49 ,
struct V_40 * V_109 ,
enum V_158 V_159 )
{
struct V_160 * V_161 = NULL ;
struct V_160 * V_162 = NULL ;
struct V_39 * V_45 = NULL , * V_46 = NULL ;
struct V_39 * V_163 = NULL ;
struct V_9 * V_164 ;
int V_152 ;
T_1 V_165 , V_166 ;
T_1 * V_42 ;
T_1 V_167 ;
F_24 ( V_53 , V_29 ,
L_13 ) ;
F_69 () ;
F_70 (tmp_neigh_node,
&orig_node->neigh_list, list) {
V_42 = V_46 -> V_30 ;
if ( F_81 ( V_42 , V_140 -> V_144 ) &&
V_46 -> V_49 == V_49 &&
F_20 ( & V_46 -> V_48 ) ) {
if ( F_82 ( V_45 , L_14 ) )
F_83 ( V_45 ) ;
V_45 = V_46 ;
continue;
}
if ( V_159 != V_168 )
continue;
V_161 = F_84 ( V_46 ,
V_109 ) ;
if ( ! V_161 )
continue;
F_6 ( & V_46 -> V_169 ) ;
F_1 ( V_161 -> V_11 . V_170 ,
& V_161 -> V_11 . V_171 , 0 ) ;
V_167 = F_2 ( V_161 -> V_11 . V_170 ) ;
V_161 -> V_11 . V_167 = V_167 ;
F_8 ( & V_46 -> V_169 ) ;
F_85 ( V_161 ) ;
V_161 = NULL ;
}
if ( ! V_45 ) {
struct V_9 * V_172 ;
V_172 = F_10 ( V_29 , V_140 -> V_144 ) ;
if ( ! V_172 )
goto V_22;
V_45 = F_17 ( V_49 ,
V_140 -> V_144 ,
V_10 , V_172 ) ;
F_16 ( V_172 ) ;
if ( ! V_45 )
goto V_22;
} else {
F_24 ( V_53 , V_29 ,
L_15 ) ;
}
F_73 () ;
V_161 = F_86 ( V_45 , V_109 ) ;
if ( ! V_161 )
goto V_47;
V_45 -> V_173 = V_80 ;
F_6 ( & V_45 -> V_169 ) ;
F_1 ( V_161 -> V_11 . V_170 ,
& V_161 -> V_11 . V_171 ,
V_57 -> V_71 ) ;
V_167 = F_2 ( V_161 -> V_11 . V_170 ) ;
V_161 -> V_11 . V_167 = V_167 ;
F_8 ( & V_45 -> V_169 ) ;
if ( V_159 == V_168 ) {
V_157 -> V_174 = V_57 -> V_67 ;
V_161 -> V_174 = V_57 -> V_67 ;
}
V_163 = F_87 ( V_10 , V_109 ) ;
if ( V_163 == V_45 )
goto V_47;
if ( V_163 ) {
V_162 = F_84 ( V_163 , V_109 ) ;
if ( ! V_162 )
goto V_47;
if ( V_162 -> V_11 . V_167 > V_161 -> V_11 . V_167 )
goto V_47;
}
if ( V_162 &&
V_161 -> V_11 . V_167 == V_162 -> V_11 . V_167 ) {
V_164 = V_163 -> V_10 ;
F_6 ( & V_164 -> V_11 . V_19 ) ;
V_152 = V_163 -> V_49 -> V_152 ;
V_165 = V_164 -> V_11 . V_13 [ V_152 ] ;
F_8 ( & V_164 -> V_11 . V_19 ) ;
V_164 = V_45 -> V_10 ;
F_6 ( & V_164 -> V_11 . V_19 ) ;
V_152 = V_45 -> V_49 -> V_152 ;
V_166 = V_164 -> V_11 . V_13 [ V_152 ] ;
F_8 ( & V_164 -> V_11 . V_19 ) ;
if ( V_165 >= V_166 )
goto V_47;
}
F_88 ( V_29 , V_10 , V_109 , V_45 ) ;
goto V_47;
V_22:
F_73 () ;
V_47:
if ( V_45 )
F_83 ( V_45 ) ;
if ( V_163 )
F_83 ( V_163 ) ;
if ( V_161 )
F_85 ( V_161 ) ;
if ( V_162 )
F_85 ( V_162 ) ;
}
static int F_89 ( struct V_9 * V_10 ,
struct V_9 * V_175 ,
struct V_57 * V_57 ,
struct V_40 * V_49 ,
struct V_40 * V_109 )
{
struct V_28 * V_29 = F_18 ( V_49 -> V_44 ) ;
struct V_39 * V_45 = NULL , * V_46 ;
struct V_160 * V_161 ;
T_1 V_176 ;
T_1 V_177 , V_178 , V_179 , V_180 ;
unsigned int V_181 , V_182 ;
int V_183 , V_184 , V_152 , V_17 = 0 ;
unsigned int V_185 ;
int V_186 ;
F_69 () ;
F_70 (tmp_neigh_node,
&orig_neigh_node->neigh_list, list) {
if ( ! F_81 ( V_46 -> V_30 ,
V_175 -> V_54 ) )
continue;
if ( V_46 -> V_49 != V_49 )
continue;
if ( ! F_20 ( & V_46 -> V_48 ) )
continue;
V_45 = V_46 ;
break;
}
F_73 () ;
if ( ! V_45 )
V_45 = F_17 ( V_49 ,
V_175 -> V_54 ,
V_175 ,
V_175 ) ;
if ( ! V_45 )
goto V_47;
if ( V_10 == V_175 )
V_45 -> V_173 = V_80 ;
V_10 -> V_173 = V_80 ;
F_6 ( & V_10 -> V_11 . V_19 ) ;
V_152 = V_49 -> V_152 ;
V_177 = V_175 -> V_11 . V_13 [ V_152 ] ;
V_161 = F_86 ( V_45 , V_109 ) ;
if ( V_161 ) {
V_178 = V_161 -> V_11 . V_187 ;
F_85 ( V_161 ) ;
} else {
V_178 = 0 ;
}
F_8 ( & V_10 -> V_11 . V_19 ) ;
if ( V_177 > V_178 )
V_176 = V_178 ;
else
V_176 = V_177 ;
if ( V_176 < V_188 ||
V_178 < V_189 )
V_180 = 0 ;
else
V_180 = ( V_72 * V_176 ) / V_178 ;
V_179 = V_154 - V_178 ;
V_181 = V_179 * V_179 * V_179 ;
V_182 = V_154 *
V_154 *
V_154 ;
V_184 = V_72 * V_181 ;
V_184 /= V_182 ;
V_183 = V_72 - V_184 ;
V_186 = V_72 ;
if ( V_109 && ( V_49 == V_109 ) &&
F_90 ( V_109 -> V_55 ) )
V_186 = F_38 ( V_72 ,
V_29 ) ;
V_185 = V_57 -> V_71 *
V_180 *
V_183 *
V_186 ;
V_185 /= V_72 *
V_72 *
V_72 ;
V_57 -> V_71 = V_185 ;
F_24 ( V_53 , V_29 ,
L_16 ,
V_10 -> V_54 , V_175 -> V_54 , V_176 ,
V_178 , V_180 , V_183 , V_186 ,
V_57 -> V_71 , V_49 -> V_55 -> V_56 ,
V_109 ? V_109 -> V_55 -> V_56 : L_17 ) ;
if ( V_57 -> V_71 >= V_190 )
V_17 = 1 ;
V_47:
if ( V_45 )
F_83 ( V_45 ) ;
return V_17 ;
}
static enum V_158
F_91 ( const struct V_140 * V_140 ,
const struct V_57 * V_57 ,
const struct V_40 * V_49 ,
struct V_40 * V_109 )
{
struct V_28 * V_29 = F_18 ( V_49 -> V_44 ) ;
struct V_9 * V_10 ;
struct V_156 * V_157 = NULL ;
struct V_39 * V_45 ;
struct V_160 * V_161 ;
int V_191 ;
T_7 V_192 ;
int V_193 = 0 ;
int V_194 ;
enum V_158 V_17 = V_168 ;
T_4 V_101 = F_43 ( V_57 -> V_101 ) ;
T_1 * V_42 ;
T_1 V_195 ;
unsigned long * V_196 ;
V_10 = F_10 ( V_29 , V_57 -> V_54 ) ;
if ( ! V_10 )
return V_168 ;
V_157 = F_92 ( V_10 , V_109 ) ;
if ( F_50 ( ! V_157 ) ) {
F_16 ( V_10 ) ;
return 0 ;
}
F_6 ( & V_10 -> V_11 . V_19 ) ;
V_192 = V_101 - V_157 -> V_197 ;
if ( ! F_93 ( & V_10 -> V_52 ) &&
F_94 ( V_29 , V_192 ,
& V_157 -> V_198 ) ) {
V_17 = V_199 ;
goto V_47;
}
F_69 () ;
F_70 (neigh_node, &orig_node->neigh_list, list) {
V_161 = F_86 ( V_45 ,
V_109 ) ;
if ( ! V_161 )
continue;
V_42 = V_45 -> V_30 ;
V_191 = F_95 ( V_161 -> V_11 . V_200 ,
V_157 -> V_197 ,
V_101 ) ;
if ( F_81 ( V_42 , V_140 -> V_144 ) &&
V_45 -> V_49 == V_49 ) {
V_194 = 1 ;
if ( V_191 )
V_17 = V_201 ;
} else {
V_194 = 0 ;
if ( V_191 && ( V_17 != V_201 ) )
V_17 = V_202 ;
}
V_196 = V_161 -> V_11 . V_200 ;
V_193 |= F_71 ( V_29 , V_196 ,
V_192 , V_194 ) ;
V_195 = F_72 ( V_196 ,
V_154 ) ;
V_161 -> V_11 . V_187 = V_195 ;
F_85 ( V_161 ) ;
}
F_73 () ;
if ( V_193 ) {
F_24 ( V_53 , V_29 ,
L_18 ,
V_109 ? V_109 -> V_55 -> V_56 : L_17 ,
V_157 -> V_197 , V_101 ) ;
V_157 -> V_197 = V_101 ;
}
V_47:
F_8 ( & V_10 -> V_11 . V_19 ) ;
F_16 ( V_10 ) ;
F_96 ( V_157 ) ;
return V_17 ;
}
static void
F_97 ( const struct V_92 * V_93 , int V_203 ,
struct V_9 * V_10 ,
struct V_40 * V_49 ,
struct V_40 * V_109 )
{
struct V_28 * V_29 = F_18 ( V_49 -> V_44 ) ;
struct V_39 * V_163 = NULL , * V_204 = NULL ;
struct V_9 * V_175 ;
struct V_156 * V_157 ;
struct V_39 * V_205 = NULL ;
struct V_160 * V_162 = NULL ;
struct V_57 * V_206 ;
enum V_158 V_159 ;
bool V_142 = false ;
bool V_141 = false ;
bool V_207 , V_208 ;
struct V_92 * V_209 ;
struct V_140 * V_140 ;
T_1 * V_74 ;
int V_210 ;
V_209 = F_98 ( V_93 , V_21 ) ;
if ( ! V_209 )
return;
V_140 = F_99 ( V_209 ) ;
V_206 = (struct V_57 * ) ( V_209 -> V_97 + V_203 ) ;
V_159 = F_91 ( V_140 , V_206 ,
V_49 , V_109 ) ;
if ( F_81 ( V_140 -> V_144 , V_206 -> V_54 ) )
V_141 = true ;
if ( V_159 == V_199 ) {
F_24 ( V_53 , V_29 ,
L_19 ,
V_140 -> V_144 ) ;
goto V_47;
}
if ( V_206 -> V_71 == 0 ) {
F_24 ( V_53 , V_29 ,
L_20 ) ;
goto V_47;
}
V_163 = F_87 ( V_10 , V_109 ) ;
if ( V_163 ) {
V_204 = F_87 ( V_163 -> V_10 ,
V_109 ) ;
V_162 = F_84 ( V_163 , V_109 ) ;
}
if ( ( V_162 && V_162 -> V_11 . V_167 != 0 ) &&
( F_81 ( V_163 -> V_30 , V_140 -> V_144 ) ) )
V_142 = true ;
V_74 = V_206 -> V_74 ;
if ( V_163 && V_204 &&
( F_81 ( V_163 -> V_30 , V_74 ) ) &&
! ( F_81 ( V_206 -> V_54 , V_74 ) ) &&
( F_81 ( V_163 -> V_30 , V_204 -> V_30 ) ) ) {
F_24 ( V_53 , V_29 ,
L_21 ,
V_140 -> V_144 ) ;
goto V_47;
}
if ( V_109 == V_211 )
F_100 ( V_29 , V_206 , V_10 ) ;
if ( V_141 )
V_175 = V_10 ;
else
V_175 = F_10 ( V_29 ,
V_140 -> V_144 ) ;
if ( ! V_175 )
goto V_47;
F_101 ( V_29 , V_10 , V_175 ,
V_206 , V_141 ) ;
V_205 = F_87 ( V_175 ,
V_109 ) ;
if ( ! V_141 && ( ! V_205 ) ) {
F_24 ( V_53 , V_29 ,
L_22 ) ;
goto V_212;
}
V_210 = F_89 ( V_10 , V_175 ,
V_206 , V_49 ,
V_109 ) ;
V_157 = F_92 ( V_10 , V_109 ) ;
if ( ! V_157 )
goto V_212;
V_207 = V_157 -> V_197 == F_43 ( V_206 -> V_101 ) ;
V_208 = ( V_157 -> V_174 - 3 ) <= V_206 -> V_67 ;
if ( V_210 && ( ( V_159 == V_168 ) ||
( V_207 && V_208 ) ) ) {
F_80 ( V_29 , V_10 ,
V_157 , V_140 ,
V_206 , V_49 ,
V_109 , V_159 ) ;
}
F_96 ( V_157 ) ;
if ( V_109 == V_211 )
goto V_212;
if ( V_141 ) {
if ( ( V_206 -> V_67 <= 2 ) &&
( V_49 != V_109 ) ) {
F_24 ( V_53 , V_29 ,
L_23 ) ;
goto V_212;
}
F_67 ( V_10 , V_140 , V_206 ,
V_141 ,
V_142 , V_49 ,
V_109 ) ;
F_24 ( V_53 , V_29 ,
L_24 ) ;
goto V_212;
}
if ( ! V_210 ) {
F_24 ( V_53 , V_29 ,
L_25 ) ;
goto V_212;
}
if ( V_159 == V_201 ) {
F_24 ( V_53 , V_29 ,
L_26 ) ;
goto V_212;
}
F_24 ( V_53 , V_29 ,
L_27 ) ;
F_67 ( V_10 , V_140 , V_206 ,
V_141 , V_142 ,
V_49 , V_109 ) ;
V_212:
if ( ( V_175 ) && ( ! V_141 ) )
F_16 ( V_175 ) ;
V_47:
if ( V_162 )
F_85 ( V_162 ) ;
if ( V_163 )
F_83 ( V_163 ) ;
if ( V_204 )
F_83 ( V_204 ) ;
if ( V_205 )
F_83 ( V_205 ) ;
F_102 ( V_209 ) ;
}
static void F_103 ( const struct V_92 * V_93 , int V_203 ,
struct V_40 * V_49 )
{
struct V_28 * V_29 = F_18 ( V_49 -> V_44 ) ;
struct V_9 * V_175 , * V_10 ;
struct V_40 * V_41 ;
struct V_57 * V_206 ;
T_4 V_213 ;
bool V_214 ;
struct V_140 * V_140 ;
bool V_215 = false ;
bool V_216 = false ;
bool V_217 = false ;
V_206 = (struct V_57 * ) ( V_93 -> V_97 + V_203 ) ;
V_140 = F_99 ( V_93 ) ;
if ( V_206 -> V_63 != V_64 )
return;
V_213 = F_34 ( & V_49 -> V_11 . V_60 ) ;
if ( V_206 -> V_68 & V_99 )
V_214 = true ;
else
V_214 = false ;
F_24 ( V_53 , V_29 ,
L_28 ,
V_140 -> V_144 , V_49 -> V_55 -> V_56 ,
V_49 -> V_55 -> V_73 , V_206 -> V_54 ,
V_206 -> V_74 , F_43 ( V_206 -> V_101 ) ,
V_206 -> V_71 , V_206 -> V_67 ,
V_206 -> V_65 , V_214 ) ;
F_69 () ;
F_79 (hard_iface, &batadv_hardif_list, list) {
if ( V_41 -> V_95 != V_96 )
continue;
if ( V_41 -> V_44 != V_49 -> V_44 )
continue;
if ( F_81 ( V_140 -> V_144 ,
V_41 -> V_55 -> V_73 ) )
V_216 = true ;
if ( F_81 ( V_206 -> V_54 ,
V_41 -> V_55 -> V_73 ) )
V_217 = true ;
if ( F_81 ( V_206 -> V_74 ,
V_41 -> V_55 -> V_73 ) )
V_215 = true ;
}
F_73 () ;
if ( V_216 ) {
F_24 ( V_53 , V_29 ,
L_29 ,
V_140 -> V_144 ) ;
return;
}
if ( V_217 ) {
unsigned long * V_149 ;
int V_218 ;
T_7 V_219 ;
T_6 V_152 ;
T_1 * V_220 ;
V_175 = F_10 ( V_29 ,
V_140 -> V_144 ) ;
if ( ! V_175 )
return;
if ( V_214 &&
F_81 ( V_49 -> V_55 -> V_73 ,
V_206 -> V_54 ) ) {
V_152 = V_49 -> V_152 ;
V_218 = V_152 * V_20 ;
F_6 ( & V_175 -> V_11 . V_19 ) ;
V_149 = & V_175 -> V_11 . V_12 [ V_218 ] ;
V_219 = V_213 - 2 ;
V_219 -= F_43 ( V_206 -> V_101 ) ;
F_104 ( V_149 , V_219 ) ;
V_220 = & V_175 -> V_11 . V_13 [ V_152 ] ;
* V_220 = F_72 ( V_149 ,
V_154 ) ;
F_8 ( & V_175 -> V_11 . V_19 ) ;
}
F_24 ( V_53 , V_29 ,
L_30 ) ;
F_16 ( V_175 ) ;
return;
}
if ( V_215 ) {
F_24 ( V_53 , V_29 ,
L_31 ,
V_140 -> V_144 ) ;
return;
}
if ( V_206 -> V_68 & V_143 ) {
F_24 ( V_53 , V_29 ,
L_32 ,
V_140 -> V_144 ) ;
return;
}
V_10 = F_10 ( V_29 , V_206 -> V_54 ) ;
if ( ! V_10 )
return;
F_97 ( V_93 , V_203 , V_10 ,
V_49 , V_211 ) ;
F_69 () ;
F_79 (hard_iface, &batadv_hardif_list, list) {
if ( V_41 -> V_95 != V_96 )
continue;
if ( V_41 -> V_44 != V_29 -> V_44 )
continue;
F_97 ( V_93 , V_203 , V_10 ,
V_49 , V_41 ) ;
}
F_73 () ;
F_16 ( V_10 ) ;
}
static int F_105 ( struct V_92 * V_93 ,
struct V_40 * V_49 )
{
struct V_28 * V_29 = F_18 ( V_49 -> V_44 ) ;
struct V_57 * V_206 ;
T_1 * V_94 ;
int V_203 ;
bool V_17 ;
V_17 = F_106 ( V_93 , V_49 , V_62 ) ;
if ( ! V_17 )
return V_221 ;
if ( V_29 -> V_222 -> V_223 != F_48 )
return V_221 ;
F_45 ( V_29 , V_224 ) ;
F_46 ( V_29 , V_225 ,
V_93 -> V_104 + V_105 ) ;
V_203 = 0 ;
V_206 = (struct V_57 * ) V_93 -> V_97 ;
while ( F_39 ( V_203 , F_107 ( V_93 ) ,
V_206 -> V_85 ) ) {
F_103 ( V_93 , V_203 , V_49 ) ;
V_203 += V_62 ;
V_203 += F_40 ( V_206 -> V_85 ) ;
V_94 = V_93 -> V_97 + V_203 ;
V_206 = (struct V_57 * ) V_94 ;
}
F_102 ( V_93 ) ;
return V_226 ;
}
static void
F_108 ( struct V_9 * V_10 ,
struct V_40 * V_109 ,
struct V_227 * V_228 )
{
struct V_39 * V_45 ;
struct V_160 * V_229 ;
F_70 (neigh_node, &orig_node->neigh_list, list) {
V_229 = F_84 ( V_45 , V_109 ) ;
if ( ! V_229 )
continue;
F_109 ( V_228 , L_33 ,
V_45 -> V_30 ,
V_229 -> V_11 . V_167 ) ;
F_85 ( V_229 ) ;
}
}
static void F_110 ( struct V_28 * V_29 ,
struct V_227 * V_228 ,
struct V_40 * V_109 )
{
struct V_39 * V_45 ;
struct V_145 * V_146 = V_29 -> V_35 ;
int V_230 , V_231 ;
struct V_9 * V_10 ;
struct V_160 * V_229 ;
unsigned long V_232 ;
struct V_147 * V_148 ;
int V_233 = 0 ;
T_4 V_7 ;
F_109 ( V_228 , L_34 ,
L_35 , L_36 , L_37 , V_72 ,
L_38 , L_39 , L_40 ) ;
for ( V_7 = 0 ; V_7 < V_146 -> V_31 ; V_7 ++ ) {
V_148 = & V_146 -> V_153 [ V_7 ] ;
F_69 () ;
F_70 (orig_node, head, hash_entry) {
V_45 = F_87 ( V_10 ,
V_109 ) ;
if ( ! V_45 )
continue;
V_229 = F_84 ( V_45 ,
V_109 ) ;
if ( ! V_229 )
goto V_234;
if ( V_229 -> V_11 . V_167 == 0 )
goto V_234;
V_232 = V_80 - V_10 -> V_173 ;
V_230 = F_111 ( V_232 ) ;
V_231 = V_230 / 1000 ;
V_230 = V_230 % 1000 ;
F_109 ( V_228 , L_41 ,
V_10 -> V_54 , V_231 ,
V_230 , V_229 -> V_11 . V_167 ,
V_45 -> V_30 ,
V_45 -> V_49 -> V_55 -> V_56 ) ;
F_108 ( V_10 , V_109 ,
V_228 ) ;
F_112 ( V_228 , L_42 ) ;
V_233 ++ ;
V_234:
F_83 ( V_45 ) ;
if ( V_229 )
F_85 ( V_229 ) ;
}
F_73 () ;
}
if ( V_233 == 0 )
F_112 ( V_228 , L_43 ) ;
}
static int F_113 ( struct V_39 * V_235 ,
struct V_40 * V_236 ,
struct V_39 * V_237 ,
struct V_40 * V_238 )
{
struct V_160 * V_239 , * V_240 ;
T_1 V_241 , V_242 ;
int V_243 ;
V_239 = F_84 ( V_235 , V_236 ) ;
V_240 = F_84 ( V_237 , V_238 ) ;
if ( ! V_239 || ! V_240 ) {
V_243 = 0 ;
goto V_47;
}
V_241 = V_239 -> V_11 . V_167 ;
V_242 = V_240 -> V_11 . V_167 ;
V_243 = V_241 - V_242 ;
V_47:
if ( V_239 )
F_85 ( V_239 ) ;
if ( V_240 )
F_85 ( V_240 ) ;
return V_243 ;
}
static bool
F_114 ( struct V_39 * V_235 ,
struct V_40 * V_236 ,
struct V_39 * V_237 ,
struct V_40 * V_238 )
{
struct V_160 * V_239 , * V_240 ;
T_1 V_241 , V_242 ;
bool V_17 ;
V_239 = F_84 ( V_235 , V_236 ) ;
V_240 = F_84 ( V_237 , V_238 ) ;
if ( ! V_239 || ! V_240 ) {
V_17 = false ;
goto V_47;
}
V_241 = V_239 -> V_11 . V_167 ;
V_242 = V_240 -> V_11 . V_167 ;
V_17 = ( V_241 - V_242 ) > - V_244 ;
V_47:
if ( V_239 )
F_85 ( V_239 ) ;
if ( V_240 )
F_85 ( V_240 ) ;
return V_17 ;
}
int T_8 F_115 ( void )
{
int V_17 ;
V_17 = F_116 ( V_64 ,
F_105 ) ;
if ( V_17 < 0 )
goto V_47;
V_17 = F_117 ( & V_245 ) ;
if ( V_17 < 0 )
goto V_246;
goto V_47;
V_246:
F_118 ( V_64 ) ;
V_47:
return V_17 ;
}

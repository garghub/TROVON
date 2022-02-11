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
int V_60 = - V_18 ;
F_26 ( & V_59 , sizeof( V_59 ) ) ;
F_27 ( & V_41 -> V_11 . V_61 , V_59 ) ;
V_41 -> V_11 . V_62 = V_63 ;
V_58 = F_28 ( V_41 -> V_11 . V_62 , V_21 ) ;
if ( ! V_58 )
goto V_47;
V_41 -> V_11 . V_58 = V_58 ;
V_57 = (struct V_57 * ) V_58 ;
V_57 -> V_64 = V_65 ;
V_57 -> V_66 = V_67 ;
V_57 -> V_68 = 2 ;
V_57 -> V_69 = V_70 ;
V_57 -> V_71 = 0 ;
V_57 -> V_72 = V_73 ;
V_60 = 0 ;
V_47:
return V_60 ;
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
V_41 -> V_55 -> V_74 ) ;
F_31 ( V_57 -> V_75 ,
V_41 -> V_55 -> V_74 ) ;
}
static void
F_32 ( struct V_40 * V_41 )
{
struct V_57 * V_57 ;
unsigned char * V_58 = V_41 -> V_11 . V_58 ;
V_57 = (struct V_57 * ) V_58 ;
V_57 -> V_69 = V_76 ;
V_57 -> V_68 = V_77 ;
}
static unsigned long
F_33 ( const struct V_28 * V_29 )
{
unsigned int V_78 ;
V_78 = F_34 ( & V_29 -> V_79 ) - V_80 ;
V_78 += F_35 () % ( 2 * V_80 ) ;
return V_81 + F_36 ( V_78 ) ;
}
static unsigned long F_37 ( void )
{
return V_81 + F_36 ( F_35 () % ( V_80 / 2 ) ) ;
}
static T_1 F_38 ( T_1 V_72 ,
const struct V_28 * V_29 )
{
int V_82 = F_34 ( & V_29 -> V_82 ) ;
int V_83 ;
V_83 = V_72 * ( V_73 - V_82 ) ;
V_83 /= V_73 ;
return V_83 ;
}
static int F_39 ( int V_84 , int V_85 ,
T_5 V_86 )
{
int V_87 = 0 ;
V_87 += V_84 + V_63 ;
V_87 += F_40 ( V_86 ) ;
return ( V_87 <= V_85 ) &&
( V_87 <= V_88 ) ;
}
static void F_41 ( struct V_89 * V_90 ,
struct V_40 * V_41 )
{
struct V_28 * V_29 = F_18 ( V_41 -> V_44 ) ;
char * V_91 ;
T_1 V_92 ;
T_6 V_84 ;
struct V_57 * V_57 ;
struct V_93 * V_94 ;
T_1 * V_95 ;
if ( V_41 -> V_96 != V_97 )
return;
V_92 = 0 ;
V_84 = 0 ;
V_95 = V_90 -> V_94 -> V_98 ;
V_57 = (struct V_57 * ) V_95 ;
while ( F_39 ( V_84 , V_90 -> V_85 ,
V_57 -> V_86 ) ) {
if ( V_90 -> V_99 & F_42 ( V_92 ) &&
V_90 -> V_49 == V_41 )
V_57 -> V_69 |= V_100 ;
else
V_57 -> V_69 &= ~ V_100 ;
if ( V_92 > 0 || ! V_90 -> V_101 )
V_91 = L_2 ;
else
V_91 = L_3 ;
F_24 ( V_53 , V_29 ,
L_4 ,
V_91 , ( V_92 > 0 ? L_5 : L_6 ) ,
V_57 -> V_54 ,
F_43 ( V_57 -> V_102 ) ,
V_57 -> V_72 , V_57 -> V_68 ,
( V_57 -> V_69 & V_100 ?
L_7 : L_8 ) ,
V_41 -> V_55 -> V_56 ,
V_41 -> V_55 -> V_74 ) ;
V_84 += V_63 ;
V_84 += F_40 ( V_57 -> V_86 ) ;
V_92 ++ ;
V_95 = V_90 -> V_94 -> V_98 + V_84 ;
V_57 = (struct V_57 * ) V_95 ;
}
V_94 = F_44 ( V_90 -> V_94 , V_21 ) ;
if ( V_94 ) {
F_45 ( V_29 , V_103 ) ;
F_46 ( V_29 , V_104 ,
V_94 -> V_105 + V_106 ) ;
F_47 ( V_94 , V_41 , V_107 ) ;
}
}
static void F_48 ( struct V_89 * V_90 )
{
struct V_108 * V_44 ;
struct V_28 * V_29 ;
struct V_40 * V_109 = NULL ;
if ( ! V_90 -> V_49 ) {
F_49 ( L_9 ) ;
goto V_47;
}
V_44 = V_90 -> V_49 -> V_44 ;
V_29 = F_18 ( V_44 ) ;
if ( F_50 ( ! V_90 -> V_110 ) )
goto V_47;
if ( F_50 ( V_90 -> V_110 -> V_44 != V_44 ) )
goto V_47;
if ( V_90 -> V_49 -> V_96 != V_97 )
goto V_47;
V_109 = F_51 ( V_29 ) ;
if ( ! V_109 )
goto V_47;
F_41 ( V_90 , V_90 -> V_110 ) ;
V_47:
if ( V_109 )
F_23 ( V_109 ) ;
}
static bool
F_52 ( const struct V_57 * V_111 ,
struct V_28 * V_29 ,
int V_85 , unsigned long V_112 ,
bool V_113 ,
const struct V_40 * V_49 ,
const struct V_40 * V_110 ,
const struct V_89 * V_90 )
{
struct V_57 * V_57 ;
int V_114 = V_90 -> V_85 + V_85 ;
struct V_40 * V_109 = NULL ;
bool V_60 = false ;
unsigned long V_115 ;
V_57 = (struct V_57 * ) V_90 -> V_94 -> V_98 ;
V_115 = V_112 ;
V_115 += F_36 ( V_116 ) ;
if ( F_53 ( V_112 , V_90 -> V_112 ) &&
F_54 ( V_115 , V_90 -> V_112 ) &&
( V_114 <= V_88 ) ) {
V_109 = F_51 ( V_29 ) ;
if ( ! V_109 )
goto V_47;
if ( V_90 -> V_110 != V_110 )
goto V_47;
if ( ( ! V_113 ) &&
( ! ( V_57 -> V_69 & V_100 ) ) &&
( V_57 -> V_68 != 1 ) &&
( ( ! V_90 -> V_101 ) ||
( V_90 -> V_49 == V_109 ) ) ) {
V_60 = true ;
goto V_47;
}
if ( ( V_113 ) &&
( V_111 -> V_68 == 1 ) &&
( V_90 -> V_49 == V_49 ) &&
( V_57 -> V_69 & V_100 ||
( V_90 -> V_101 &&
V_90 -> V_49 != V_109 ) ) ) {
V_60 = true ;
goto V_47;
}
}
V_47:
if ( V_109 )
F_23 ( V_109 ) ;
return V_60 ;
}
static void F_55 ( const unsigned char * V_117 ,
int V_85 , unsigned long V_112 ,
bool V_118 ,
struct V_40 * V_49 ,
struct V_40 * V_110 ,
int V_119 )
{
struct V_28 * V_29 = F_18 ( V_49 -> V_44 ) ;
struct V_89 * V_120 ;
unsigned char * V_121 ;
unsigned int V_122 ;
if ( ! F_20 ( & V_49 -> V_48 ) )
return;
if ( ! F_20 ( & V_110 -> V_48 ) )
goto V_123;
if ( ! V_119 ) {
if ( ! F_56 ( & V_29 -> V_124 ) ) {
F_24 ( V_53 , V_29 ,
L_10 ) ;
goto V_47;
}
}
V_120 = F_28 ( sizeof( * V_120 ) , V_21 ) ;
if ( ! V_120 ) {
if ( ! V_119 )
F_57 ( & V_29 -> V_124 ) ;
goto V_47;
}
if ( ( F_34 ( & V_29 -> V_125 ) ) &&
( V_85 < V_88 ) )
V_122 = V_88 ;
else
V_122 = V_85 ;
V_122 += V_106 ;
V_120 -> V_94 = F_58 ( NULL , V_122 ) ;
if ( ! V_120 -> V_94 ) {
if ( ! V_119 )
F_57 ( & V_29 -> V_124 ) ;
F_4 ( V_120 ) ;
goto V_47;
}
V_120 -> V_94 -> V_126 = V_127 ;
F_59 ( V_120 -> V_94 , V_106 ) ;
V_121 = F_60 ( V_120 -> V_94 , V_85 ) ;
V_120 -> V_85 = V_85 ;
memcpy ( V_121 , V_117 , V_85 ) ;
V_120 -> V_101 = V_119 ;
V_120 -> V_49 = V_49 ;
V_120 -> V_110 = V_110 ;
V_120 -> V_128 = 0 ;
V_120 -> V_99 = V_70 ;
V_120 -> V_112 = V_112 ;
if ( V_118 )
V_120 -> V_99 |= 1 ;
F_6 ( & V_29 -> V_129 ) ;
F_61 ( & V_120 -> V_51 , & V_29 -> V_130 ) ;
F_8 ( & V_29 -> V_129 ) ;
F_62 ( & V_120 -> V_131 ,
V_132 ) ;
F_63 ( V_133 ,
& V_120 -> V_131 ,
V_112 - V_81 ) ;
return;
V_47:
F_23 ( V_110 ) ;
V_123:
F_23 ( V_49 ) ;
}
static void F_64 ( struct V_89 * V_120 ,
const unsigned char * V_117 ,
int V_85 , bool V_118 )
{
unsigned char * V_121 ;
unsigned long V_134 ;
V_121 = F_60 ( V_120 -> V_94 , V_85 ) ;
memcpy ( V_121 , V_117 , V_85 ) ;
V_120 -> V_85 += V_85 ;
V_120 -> V_128 ++ ;
if ( V_118 ) {
V_134 = F_42 ( V_120 -> V_128 ) ;
V_120 -> V_99 |= V_134 ;
}
}
static void F_65 ( struct V_28 * V_29 ,
unsigned char * V_117 ,
int V_85 ,
struct V_40 * V_49 ,
struct V_40 * V_110 ,
int V_119 , unsigned long V_112 )
{
struct V_89 * V_120 = NULL ;
struct V_89 * V_135 = NULL ;
struct V_57 * V_57 ;
bool V_118 ;
unsigned long V_136 ;
V_57 = (struct V_57 * ) V_117 ;
V_118 = V_57 -> V_69 & V_100 ? 1 : 0 ;
V_136 = F_36 ( V_116 ) ;
F_6 ( & V_29 -> V_129 ) ;
if ( ( F_34 ( & V_29 -> V_125 ) ) && ( ! V_119 ) ) {
F_66 (forw_packet_pos,
&bat_priv->forw_bat_list, list) {
if ( F_52 ( V_57 ,
V_29 , V_85 ,
V_112 , V_118 ,
V_49 ,
V_110 ,
V_135 ) ) {
V_120 = V_135 ;
break;
}
}
}
if ( ! V_120 ) {
F_8 ( & V_29 -> V_129 ) ;
if ( ! V_119 && F_34 ( & V_29 -> V_125 ) )
V_112 += V_136 ;
F_55 ( V_117 , V_85 ,
V_112 , V_118 ,
V_49 , V_110 ,
V_119 ) ;
} else {
F_64 ( V_120 , V_117 ,
V_85 , V_118 ) ;
F_8 ( & V_29 -> V_129 ) ;
}
}
static void F_67 ( struct V_9 * V_10 ,
const struct V_137 * V_137 ,
struct V_57 * V_57 ,
bool V_138 ,
bool V_139 ,
struct V_40 * V_49 ,
struct V_40 * V_110 )
{
struct V_28 * V_29 = F_18 ( V_49 -> V_44 ) ;
T_2 V_86 ;
if ( V_57 -> V_68 <= 1 ) {
F_24 ( V_53 , V_29 , L_11 ) ;
return;
}
if ( ! V_139 ) {
if ( V_138 )
V_57 -> V_69 |= V_140 ;
else
return;
}
V_86 = F_40 ( V_57 -> V_86 ) ;
V_57 -> V_68 -- ;
F_31 ( V_57 -> V_75 , V_137 -> V_141 ) ;
V_57 -> V_72 = F_38 ( V_57 -> V_72 ,
V_29 ) ;
F_24 ( V_53 , V_29 ,
L_12 ,
V_57 -> V_72 , V_57 -> V_68 ) ;
V_57 -> V_69 &= ~ V_76 ;
if ( V_138 )
V_57 -> V_69 |= V_100 ;
else
V_57 -> V_69 &= ~ V_100 ;
F_65 ( V_29 , ( unsigned char * ) V_57 ,
V_63 + V_86 ,
V_49 , V_110 , 0 ,
F_37 () ) ;
}
static void
F_68 ( struct V_40 * V_41 )
{
struct V_28 * V_29 = F_18 ( V_41 -> V_44 ) ;
struct V_142 * V_143 = V_29 -> V_35 ;
struct V_144 * V_145 ;
struct V_9 * V_10 ;
unsigned long * V_146 ;
T_4 V_7 ;
T_3 V_147 ;
T_1 * V_148 ;
int V_149 ;
for ( V_7 = 0 ; V_7 < V_143 -> V_31 ; V_7 ++ ) {
V_145 = & V_143 -> V_150 [ V_7 ] ;
F_69 () ;
F_70 (orig_node, head, hash_entry) {
F_6 ( & V_10 -> V_11 . V_19 ) ;
V_147 = V_41 -> V_149 * V_20 ;
V_146 = & ( V_10 -> V_11 . V_12 [ V_147 ] ) ;
F_71 ( V_29 , V_146 , 1 , 0 ) ;
V_149 = V_41 -> V_149 ;
V_148 = & V_10 -> V_11 . V_13 [ V_149 ] ;
* V_148 = F_72 ( V_146 , V_151 ) ;
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
struct V_40 * V_109 , * V_152 ;
int * V_62 = & V_41 -> V_11 . V_62 ;
T_4 V_102 ;
T_2 V_86 = 0 ;
unsigned long V_112 ;
V_109 = F_51 ( V_29 ) ;
if ( V_41 == V_109 ) {
F_75 ( V_29 ) ;
V_86 = F_76 ( V_29 , V_58 ,
V_62 ,
V_63 ) ;
}
V_57 = (struct V_57 * ) ( * V_58 ) ;
V_57 -> V_86 = F_77 ( V_86 ) ;
V_102 = ( T_4 ) F_34 ( & V_41 -> V_11 . V_61 ) ;
V_57 -> V_102 = F_78 ( V_102 ) ;
F_57 ( & V_41 -> V_11 . V_61 ) ;
F_68 ( V_41 ) ;
V_112 = F_33 ( V_29 ) ;
if ( V_41 != V_109 ) {
F_65 ( V_29 , * V_58 , * V_62 ,
V_41 , V_41 , 1 , V_112 ) ;
goto V_47;
}
F_69 () ;
F_79 (tmp_hard_iface, &batadv_hardif_list, list) {
if ( V_152 -> V_44 != V_41 -> V_44 )
continue;
F_65 ( V_29 , * V_58 ,
* V_62 , V_41 ,
V_152 , 1 , V_112 ) ;
}
F_73 () ;
V_47:
if ( V_109 )
F_23 ( V_109 ) ;
}
static void
F_80 ( struct V_28 * V_29 ,
struct V_9 * V_10 ,
struct V_153 * V_154 ,
const struct V_137 * V_137 ,
const struct V_57 * V_57 ,
struct V_40 * V_49 ,
struct V_40 * V_110 ,
enum V_155 V_156 )
{
struct V_157 * V_158 = NULL ;
struct V_157 * V_159 = NULL ;
struct V_39 * V_45 = NULL , * V_46 = NULL ;
struct V_39 * V_160 = NULL ;
struct V_9 * V_161 ;
int V_149 ;
T_1 V_162 , V_163 ;
T_1 * V_42 ;
T_1 V_164 ;
F_24 ( V_53 , V_29 ,
L_13 ) ;
F_69 () ;
F_70 (tmp_neigh_node,
&orig_node->neigh_list, list) {
V_42 = V_46 -> V_30 ;
if ( F_81 ( V_42 , V_137 -> V_141 ) &&
V_46 -> V_49 == V_49 &&
F_20 ( & V_46 -> V_48 ) ) {
if ( F_82 ( V_45 , L_14 ) )
F_83 ( V_45 ) ;
V_45 = V_46 ;
continue;
}
if ( V_156 != V_165 )
continue;
V_158 = F_84 ( V_46 ,
V_110 ) ;
if ( ! V_158 )
continue;
F_6 ( & V_46 -> V_166 ) ;
F_1 ( V_158 -> V_11 . V_167 ,
& V_158 -> V_11 . V_168 , 0 ) ;
V_164 = F_2 ( V_158 -> V_11 . V_167 ) ;
V_158 -> V_11 . V_164 = V_164 ;
F_8 ( & V_46 -> V_166 ) ;
F_85 ( V_158 ) ;
V_158 = NULL ;
}
if ( ! V_45 ) {
struct V_9 * V_169 ;
V_169 = F_10 ( V_29 , V_137 -> V_141 ) ;
if ( ! V_169 )
goto V_22;
V_45 = F_17 ( V_49 ,
V_137 -> V_141 ,
V_10 , V_169 ) ;
F_16 ( V_169 ) ;
if ( ! V_45 )
goto V_22;
} else
F_24 ( V_53 , V_29 ,
L_15 ) ;
F_73 () ;
V_158 = F_86 ( V_45 , V_110 ) ;
if ( ! V_158 )
goto V_47;
V_45 -> V_170 = V_81 ;
F_6 ( & V_45 -> V_166 ) ;
F_1 ( V_158 -> V_11 . V_167 ,
& V_158 -> V_11 . V_168 ,
V_57 -> V_72 ) ;
V_164 = F_2 ( V_158 -> V_11 . V_167 ) ;
V_158 -> V_11 . V_164 = V_164 ;
F_8 ( & V_45 -> V_166 ) ;
if ( V_156 == V_165 ) {
V_154 -> V_171 = V_57 -> V_68 ;
V_158 -> V_171 = V_57 -> V_68 ;
}
V_160 = F_87 ( V_10 , V_110 ) ;
if ( V_160 == V_45 )
goto V_47;
if ( V_160 ) {
V_159 = F_84 ( V_160 , V_110 ) ;
if ( ! V_159 )
goto V_47;
if ( V_159 -> V_11 . V_164 > V_158 -> V_11 . V_164 )
goto V_47;
}
if ( V_159 &&
( V_158 -> V_11 . V_164 == V_159 -> V_11 . V_164 ) ) {
V_161 = V_160 -> V_10 ;
F_6 ( & V_161 -> V_11 . V_19 ) ;
V_149 = V_160 -> V_49 -> V_149 ;
V_162 = V_161 -> V_11 . V_13 [ V_149 ] ;
F_8 ( & V_161 -> V_11 . V_19 ) ;
V_161 = V_45 -> V_10 ;
F_6 ( & V_161 -> V_11 . V_19 ) ;
V_149 = V_45 -> V_49 -> V_149 ;
V_163 = V_161 -> V_11 . V_13 [ V_149 ] ;
F_8 ( & V_161 -> V_11 . V_19 ) ;
if ( V_162 >= V_163 )
goto V_47;
}
F_88 ( V_29 , V_10 , V_110 , V_45 ) ;
goto V_47;
V_22:
F_73 () ;
V_47:
if ( V_45 )
F_83 ( V_45 ) ;
if ( V_160 )
F_83 ( V_160 ) ;
if ( V_158 )
F_85 ( V_158 ) ;
if ( V_159 )
F_85 ( V_159 ) ;
}
static int F_89 ( struct V_9 * V_10 ,
struct V_9 * V_172 ,
struct V_57 * V_57 ,
struct V_40 * V_49 ,
struct V_40 * V_110 )
{
struct V_28 * V_29 = F_18 ( V_49 -> V_44 ) ;
struct V_39 * V_45 = NULL , * V_46 ;
struct V_157 * V_158 ;
T_1 V_173 ;
T_1 V_174 , V_175 , V_176 , V_177 ;
unsigned int V_178 , V_179 ;
int V_180 , V_181 , V_149 , V_17 = 0 ;
unsigned int V_182 ;
int V_183 ;
F_69 () ;
F_70 (tmp_neigh_node,
&orig_neigh_node->neigh_list, list) {
if ( ! F_81 ( V_46 -> V_30 ,
V_172 -> V_54 ) )
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
V_172 -> V_54 ,
V_172 ,
V_172 ) ;
if ( ! V_45 )
goto V_47;
if ( V_10 == V_172 )
V_45 -> V_170 = V_81 ;
V_10 -> V_170 = V_81 ;
F_6 ( & V_10 -> V_11 . V_19 ) ;
V_149 = V_49 -> V_149 ;
V_174 = V_172 -> V_11 . V_13 [ V_149 ] ;
V_158 = F_86 ( V_45 , V_110 ) ;
if ( V_158 ) {
V_175 = V_158 -> V_11 . V_184 ;
F_85 ( V_158 ) ;
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
V_177 = ( V_73 * V_173 ) / V_175 ;
V_176 = V_151 - V_175 ;
V_178 = V_176 * V_176 * V_176 ;
V_179 = V_151 *
V_151 *
V_151 ;
V_181 = V_73 * V_178 ;
V_181 /= V_179 ;
V_180 = V_73 - V_181 ;
V_183 = V_73 ;
if ( V_110 && ( V_49 == V_110 ) &&
F_90 ( V_110 -> V_55 ) )
V_183 = F_38 ( V_73 ,
V_29 ) ;
V_182 = V_57 -> V_72 *
V_177 *
V_180 *
V_183 ;
V_182 /= V_73 *
V_73 *
V_73 ;
V_57 -> V_72 = V_182 ;
F_24 ( V_53 , V_29 ,
L_16 ,
V_10 -> V_54 , V_172 -> V_54 , V_173 ,
V_175 , V_177 , V_180 , V_183 ,
V_57 -> V_72 , V_49 -> V_55 -> V_56 ,
V_110 ? V_110 -> V_55 -> V_56 : L_17 ) ;
if ( V_57 -> V_72 >= V_187 )
V_17 = 1 ;
V_47:
if ( V_45 )
F_83 ( V_45 ) ;
return V_17 ;
}
static enum V_155
F_91 ( const struct V_137 * V_137 ,
const struct V_57 * V_57 ,
const struct V_40 * V_49 ,
struct V_40 * V_110 )
{
struct V_28 * V_29 = F_18 ( V_49 -> V_44 ) ;
struct V_9 * V_10 ;
struct V_153 * V_154 = NULL ;
struct V_39 * V_45 ;
struct V_157 * V_158 ;
int V_188 ;
T_7 V_189 ;
int V_190 = 0 ;
int V_191 ;
enum V_155 V_17 = V_165 ;
T_4 V_102 = F_43 ( V_57 -> V_102 ) ;
T_1 * V_42 ;
T_1 V_192 ;
unsigned long * V_193 ;
V_10 = F_10 ( V_29 , V_57 -> V_54 ) ;
if ( ! V_10 )
return V_165 ;
V_154 = F_92 ( V_10 , V_110 ) ;
if ( F_50 ( ! V_154 ) ) {
F_16 ( V_10 ) ;
return 0 ;
}
F_6 ( & V_10 -> V_11 . V_19 ) ;
V_189 = V_102 - V_154 -> V_194 ;
if ( ! F_93 ( & V_10 -> V_52 ) &&
F_94 ( V_29 , V_189 ,
& V_154 -> V_195 ) ) {
V_17 = V_196 ;
goto V_47;
}
F_69 () ;
F_70 (neigh_node, &orig_node->neigh_list, list) {
V_158 = F_86 ( V_45 ,
V_110 ) ;
if ( ! V_158 )
continue;
V_42 = V_45 -> V_30 ;
V_188 = F_95 ( V_158 -> V_11 . V_197 ,
V_154 -> V_194 ,
V_102 ) ;
if ( F_81 ( V_42 , V_137 -> V_141 ) &&
V_45 -> V_49 == V_49 ) {
V_191 = 1 ;
if ( V_188 )
V_17 = V_198 ;
} else {
V_191 = 0 ;
if ( V_188 && ( V_17 != V_198 ) )
V_17 = V_199 ;
}
V_193 = V_158 -> V_11 . V_197 ;
V_190 |= F_71 ( V_29 , V_193 ,
V_189 , V_191 ) ;
V_192 = F_72 ( V_193 ,
V_151 ) ;
V_158 -> V_11 . V_184 = V_192 ;
F_85 ( V_158 ) ;
}
F_73 () ;
if ( V_190 ) {
F_24 ( V_53 , V_29 ,
L_18 ,
V_110 ? V_110 -> V_55 -> V_56 : L_17 ,
V_154 -> V_194 , V_102 ) ;
V_154 -> V_194 = V_102 ;
}
V_47:
F_8 ( & V_10 -> V_11 . V_19 ) ;
F_16 ( V_10 ) ;
if ( V_154 )
F_96 ( V_154 ) ;
return V_17 ;
}
static void
F_97 ( const struct V_93 * V_94 , int V_200 ,
struct V_9 * V_10 ,
struct V_40 * V_49 ,
struct V_40 * V_110 )
{
struct V_28 * V_29 = F_18 ( V_49 -> V_44 ) ;
struct V_39 * V_160 = NULL , * V_201 = NULL ;
struct V_9 * V_172 ;
struct V_153 * V_154 ;
struct V_39 * V_202 = NULL ;
struct V_157 * V_159 = NULL ;
struct V_57 * V_203 ;
enum V_155 V_156 ;
bool V_139 = false ;
bool V_138 = false ;
bool V_204 , V_205 ;
struct V_93 * V_206 ;
struct V_137 * V_137 ;
T_1 * V_75 ;
int V_207 ;
V_206 = F_98 ( V_94 , V_21 ) ;
if ( ! V_206 )
return;
V_137 = F_99 ( V_206 ) ;
V_203 = (struct V_57 * ) ( V_206 -> V_98 + V_200 ) ;
V_156 = F_91 ( V_137 , V_203 ,
V_49 , V_110 ) ;
if ( F_81 ( V_137 -> V_141 , V_203 -> V_54 ) )
V_138 = true ;
if ( V_156 == V_196 ) {
F_24 ( V_53 , V_29 ,
L_19 ,
V_137 -> V_141 ) ;
goto V_47;
}
if ( V_203 -> V_72 == 0 ) {
F_24 ( V_53 , V_29 ,
L_20 ) ;
goto V_47;
}
V_160 = F_87 ( V_10 , V_110 ) ;
if ( V_160 ) {
V_201 = F_87 ( V_160 -> V_10 ,
V_110 ) ;
V_159 = F_84 ( V_160 , V_110 ) ;
}
if ( ( V_159 && V_159 -> V_11 . V_164 != 0 ) &&
( F_81 ( V_160 -> V_30 , V_137 -> V_141 ) ) )
V_139 = true ;
V_75 = V_203 -> V_75 ;
if ( V_160 && V_201 &&
( F_81 ( V_160 -> V_30 , V_75 ) ) &&
! ( F_81 ( V_203 -> V_54 , V_75 ) ) &&
( F_81 ( V_160 -> V_30 , V_201 -> V_30 ) ) ) {
F_24 ( V_53 , V_29 ,
L_21 ,
V_137 -> V_141 ) ;
goto V_47;
}
if ( V_110 == V_208 )
F_100 ( V_29 , V_203 , V_10 ) ;
if ( V_138 )
V_172 = V_10 ;
else
V_172 = F_10 ( V_29 ,
V_137 -> V_141 ) ;
if ( ! V_172 )
goto V_47;
F_101 ( V_29 , V_10 , V_172 ,
V_203 , V_138 ) ;
V_202 = F_87 ( V_172 ,
V_110 ) ;
if ( ! V_138 && ( ! V_202 ) ) {
F_24 ( V_53 , V_29 ,
L_22 ) ;
goto V_209;
}
V_207 = F_89 ( V_10 , V_172 ,
V_203 , V_49 ,
V_110 ) ;
V_154 = F_92 ( V_10 , V_110 ) ;
if ( ! V_154 )
goto V_209;
V_204 = V_154 -> V_194 == F_43 ( V_203 -> V_102 ) ;
V_205 = ( V_154 -> V_171 - 3 ) <= V_203 -> V_68 ;
if ( V_207 && ( ( V_156 == V_165 ) ||
( V_204 && V_205 ) ) ) {
F_80 ( V_29 , V_10 ,
V_154 , V_137 ,
V_203 , V_49 ,
V_110 , V_156 ) ;
}
F_96 ( V_154 ) ;
if ( V_110 == V_208 )
goto V_209;
if ( V_138 ) {
if ( ( V_203 -> V_68 <= 2 ) &&
( V_49 != V_110 ) ) {
F_24 ( V_53 , V_29 ,
L_23 ) ;
goto V_209;
}
F_67 ( V_10 , V_137 , V_203 ,
V_138 ,
V_139 , V_49 ,
V_110 ) ;
F_24 ( V_53 , V_29 ,
L_24 ) ;
goto V_209;
}
if ( ! V_207 ) {
F_24 ( V_53 , V_29 ,
L_25 ) ;
goto V_209;
}
if ( V_156 == V_198 ) {
F_24 ( V_53 , V_29 ,
L_26 ) ;
goto V_209;
}
F_24 ( V_53 , V_29 ,
L_27 ) ;
F_67 ( V_10 , V_137 , V_203 ,
V_138 , V_139 ,
V_49 , V_110 ) ;
V_209:
if ( ( V_172 ) && ( ! V_138 ) )
F_16 ( V_172 ) ;
V_47:
if ( V_159 )
F_85 ( V_159 ) ;
if ( V_160 )
F_83 ( V_160 ) ;
if ( V_201 )
F_83 ( V_201 ) ;
if ( V_202 )
F_83 ( V_202 ) ;
F_102 ( V_206 ) ;
}
static void F_103 ( const struct V_93 * V_94 , int V_200 ,
struct V_40 * V_49 )
{
struct V_28 * V_29 = F_18 ( V_49 -> V_44 ) ;
struct V_9 * V_172 , * V_10 ;
struct V_40 * V_41 ;
struct V_57 * V_203 ;
T_4 V_210 ;
bool V_211 ;
struct V_137 * V_137 ;
bool V_212 = false ;
bool V_213 = false ;
bool V_214 = false ;
V_203 = (struct V_57 * ) ( V_94 -> V_98 + V_200 ) ;
V_137 = F_99 ( V_94 ) ;
if ( V_203 -> V_64 != V_65 )
return;
V_210 = F_34 ( & V_49 -> V_11 . V_61 ) ;
if ( V_203 -> V_69 & V_100 )
V_211 = true ;
else
V_211 = false ;
F_24 ( V_53 , V_29 ,
L_28 ,
V_137 -> V_141 , V_49 -> V_55 -> V_56 ,
V_49 -> V_55 -> V_74 , V_203 -> V_54 ,
V_203 -> V_75 , F_43 ( V_203 -> V_102 ) ,
V_203 -> V_72 , V_203 -> V_68 ,
V_203 -> V_66 , V_211 ) ;
F_69 () ;
F_79 (hard_iface, &batadv_hardif_list, list) {
if ( V_41 -> V_96 != V_97 )
continue;
if ( V_41 -> V_44 != V_49 -> V_44 )
continue;
if ( F_81 ( V_137 -> V_141 ,
V_41 -> V_55 -> V_74 ) )
V_213 = true ;
if ( F_81 ( V_203 -> V_54 ,
V_41 -> V_55 -> V_74 ) )
V_214 = true ;
if ( F_81 ( V_203 -> V_75 ,
V_41 -> V_55 -> V_74 ) )
V_212 = true ;
}
F_73 () ;
if ( V_213 ) {
F_24 ( V_53 , V_29 ,
L_29 ,
V_137 -> V_141 ) ;
return;
}
if ( V_214 ) {
unsigned long * V_146 ;
int V_215 ;
T_7 V_216 ;
T_6 V_149 ;
T_1 * V_217 ;
V_172 = F_10 ( V_29 ,
V_137 -> V_141 ) ;
if ( ! V_172 )
return;
if ( V_211 &&
F_81 ( V_49 -> V_55 -> V_74 ,
V_203 -> V_54 ) ) {
V_149 = V_49 -> V_149 ;
V_215 = V_149 * V_20 ;
F_6 ( & V_172 -> V_11 . V_19 ) ;
V_146 = & ( V_172 -> V_11 . V_12 [ V_215 ] ) ;
V_216 = V_210 - 2 ;
V_216 -= F_43 ( V_203 -> V_102 ) ;
F_104 ( V_146 , V_216 ) ;
V_217 = & V_172 -> V_11 . V_13 [ V_149 ] ;
* V_217 = F_72 ( V_146 ,
V_151 ) ;
F_8 ( & V_172 -> V_11 . V_19 ) ;
}
F_24 ( V_53 , V_29 ,
L_30 ) ;
F_16 ( V_172 ) ;
return;
}
if ( V_212 ) {
F_24 ( V_53 , V_29 ,
L_31 ,
V_137 -> V_141 ) ;
return;
}
if ( V_203 -> V_69 & V_140 ) {
F_24 ( V_53 , V_29 ,
L_32 ,
V_137 -> V_141 ) ;
return;
}
V_10 = F_10 ( V_29 , V_203 -> V_54 ) ;
if ( ! V_10 )
return;
F_97 ( V_94 , V_200 , V_10 ,
V_49 , V_208 ) ;
F_69 () ;
F_79 (hard_iface, &batadv_hardif_list, list) {
if ( V_41 -> V_96 != V_97 )
continue;
if ( V_41 -> V_44 != V_29 -> V_44 )
continue;
F_97 ( V_94 , V_200 , V_10 ,
V_49 , V_41 ) ;
}
F_73 () ;
F_16 ( V_10 ) ;
}
static int F_105 ( struct V_93 * V_94 ,
struct V_40 * V_49 )
{
struct V_28 * V_29 = F_18 ( V_49 -> V_44 ) ;
struct V_57 * V_203 ;
T_1 * V_95 ;
int V_200 ;
bool V_17 ;
V_17 = F_106 ( V_94 , V_49 , V_63 ) ;
if ( ! V_17 )
return V_218 ;
if ( V_29 -> V_219 -> V_220 != F_48 )
return V_218 ;
F_45 ( V_29 , V_221 ) ;
F_46 ( V_29 , V_222 ,
V_94 -> V_105 + V_106 ) ;
V_200 = 0 ;
V_203 = (struct V_57 * ) V_94 -> V_98 ;
while ( F_39 ( V_200 , F_107 ( V_94 ) ,
V_203 -> V_86 ) ) {
F_103 ( V_94 , V_200 , V_49 ) ;
V_200 += V_63 ;
V_200 += F_40 ( V_203 -> V_86 ) ;
V_95 = V_94 -> V_98 + V_200 ;
V_203 = (struct V_57 * ) V_95 ;
}
F_102 ( V_94 ) ;
return V_223 ;
}
static void
F_108 ( struct V_9 * V_10 ,
struct V_40 * V_110 ,
struct V_224 * V_225 )
{
struct V_39 * V_45 ;
struct V_157 * V_226 ;
F_70 (neigh_node, &orig_node->neigh_list, list) {
V_226 = F_84 ( V_45 , V_110 ) ;
if ( ! V_226 )
continue;
F_109 ( V_225 , L_33 ,
V_45 -> V_30 ,
V_226 -> V_11 . V_164 ) ;
F_85 ( V_226 ) ;
}
}
static void F_110 ( struct V_28 * V_29 ,
struct V_224 * V_225 ,
struct V_40 * V_110 )
{
struct V_39 * V_45 ;
struct V_142 * V_143 = V_29 -> V_35 ;
int V_227 , V_228 ;
struct V_9 * V_10 ;
struct V_157 * V_226 ;
unsigned long V_229 ;
struct V_144 * V_145 ;
int V_230 = 0 ;
T_4 V_7 ;
F_109 ( V_225 , L_34 ,
L_35 , L_36 , L_37 , V_73 ,
L_38 , L_39 , L_40 ) ;
for ( V_7 = 0 ; V_7 < V_143 -> V_31 ; V_7 ++ ) {
V_145 = & V_143 -> V_150 [ V_7 ] ;
F_69 () ;
F_70 (orig_node, head, hash_entry) {
V_45 = F_87 ( V_10 ,
V_110 ) ;
if ( ! V_45 )
continue;
V_226 = F_84 ( V_45 ,
V_110 ) ;
if ( ! V_226 )
goto V_231;
if ( V_226 -> V_11 . V_164 == 0 )
goto V_231;
V_229 = V_81 - V_10 -> V_170 ;
V_227 = F_111 ( V_229 ) ;
V_228 = V_227 / 1000 ;
V_227 = V_227 % 1000 ;
F_109 ( V_225 , L_41 ,
V_10 -> V_54 , V_228 ,
V_227 , V_226 -> V_11 . V_164 ,
V_45 -> V_30 ,
V_45 -> V_49 -> V_55 -> V_56 ) ;
F_108 ( V_10 , V_110 ,
V_225 ) ;
F_112 ( V_225 , L_42 ) ;
V_230 ++ ;
V_231:
F_83 ( V_45 ) ;
if ( V_226 )
F_85 ( V_226 ) ;
}
F_73 () ;
}
if ( V_230 == 0 )
F_112 ( V_225 , L_43 ) ;
}
static int F_113 ( struct V_39 * V_232 ,
struct V_40 * V_233 ,
struct V_39 * V_234 ,
struct V_40 * V_235 )
{
struct V_157 * V_236 , * V_237 ;
T_1 V_238 , V_239 ;
int V_240 ;
V_236 = F_84 ( V_232 , V_233 ) ;
V_237 = F_84 ( V_234 , V_235 ) ;
if ( ! V_236 || ! V_237 ) {
V_240 = 0 ;
goto V_47;
}
V_238 = V_236 -> V_11 . V_164 ;
V_239 = V_237 -> V_11 . V_164 ;
V_240 = V_238 - V_239 ;
V_47:
if ( V_236 )
F_85 ( V_236 ) ;
if ( V_237 )
F_85 ( V_237 ) ;
return V_240 ;
}
static bool
F_114 ( struct V_39 * V_232 ,
struct V_40 * V_233 ,
struct V_39 * V_234 ,
struct V_40 * V_235 )
{
struct V_157 * V_236 , * V_237 ;
T_1 V_238 , V_239 ;
bool V_17 ;
V_236 = F_84 ( V_232 , V_233 ) ;
V_237 = F_84 ( V_234 , V_235 ) ;
if ( ! V_236 || ! V_237 ) {
V_17 = false ;
goto V_47;
}
V_238 = V_236 -> V_11 . V_164 ;
V_239 = V_237 -> V_11 . V_164 ;
V_17 = ( V_238 - V_239 ) > - V_241 ;
V_47:
if ( V_236 )
F_85 ( V_236 ) ;
if ( V_237 )
F_85 ( V_237 ) ;
return V_17 ;
}
int T_8 F_115 ( void )
{
int V_17 ;
V_17 = F_116 ( V_65 ,
F_105 ) ;
if ( V_17 < 0 )
goto V_47;
V_17 = F_117 ( & V_242 ) ;
if ( V_17 < 0 )
goto V_243;
goto V_47;
V_243:
F_118 ( V_65 ) ;
V_47:
return V_17 ;
}

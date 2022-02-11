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
struct V_29 * V_30 = F_18 ( V_42 -> V_45 ) ;
struct V_40 * V_46 , * V_47 ;
V_46 = F_19 ( V_42 , V_43 , V_10 ) ;
if ( ! V_46 )
goto V_48;
if ( ! F_20 ( & V_42 -> V_49 ) ) {
F_4 ( V_46 ) ;
V_46 = NULL ;
goto V_48;
}
V_46 -> V_10 = V_44 ;
V_46 -> V_50 = V_42 ;
F_6 ( & V_10 -> V_51 ) ;
V_47 = F_21 ( V_10 , V_42 ,
V_43 ) ;
if ( ! V_47 ) {
F_22 ( & V_46 -> V_52 , & V_10 -> V_53 ) ;
} else {
F_4 ( V_46 ) ;
F_23 ( V_42 ) ;
V_46 = V_47 ;
}
F_8 ( & V_10 -> V_51 ) ;
if ( ! V_47 )
F_24 ( V_54 , V_30 ,
L_1 ,
V_43 , V_10 -> V_55 ,
V_42 -> V_56 -> V_57 ) ;
V_48:
return V_46 ;
}
static int F_25 ( struct V_41 * V_42 )
{
struct V_58 * V_58 ;
unsigned char * V_59 ;
T_4 V_60 ;
int V_61 = - V_19 ;
F_26 ( & V_60 , sizeof( V_60 ) ) ;
F_27 ( & V_42 -> V_11 . V_62 , V_60 ) ;
V_42 -> V_11 . V_63 = V_64 ;
V_59 = F_7 ( V_42 -> V_11 . V_63 , V_22 ) ;
if ( ! V_59 )
goto V_48;
V_42 -> V_11 . V_59 = V_59 ;
V_58 = (struct V_58 * ) V_59 ;
V_58 -> V_65 = V_66 ;
V_58 -> V_67 = V_68 ;
V_58 -> V_69 = 2 ;
V_58 -> V_70 = V_71 ;
V_58 -> V_72 = 0 ;
V_58 -> V_73 = V_74 ;
V_61 = 0 ;
V_48:
return V_61 ;
}
static void F_28 ( struct V_41 * V_42 )
{
F_4 ( V_42 -> V_11 . V_59 ) ;
V_42 -> V_11 . V_59 = NULL ;
}
static void F_29 ( struct V_41 * V_42 )
{
struct V_58 * V_58 ;
unsigned char * V_59 = V_42 -> V_11 . V_59 ;
V_58 = (struct V_58 * ) V_59 ;
F_30 ( V_58 -> V_55 ,
V_42 -> V_56 -> V_75 ) ;
F_30 ( V_58 -> V_76 ,
V_42 -> V_56 -> V_75 ) ;
}
static void
F_31 ( struct V_41 * V_42 )
{
struct V_58 * V_58 ;
unsigned char * V_59 = V_42 -> V_11 . V_59 ;
V_58 = (struct V_58 * ) V_59 ;
V_58 -> V_70 = V_77 ;
V_58 -> V_69 = V_78 ;
}
static unsigned long
F_32 ( const struct V_29 * V_30 )
{
unsigned int V_79 ;
V_79 = F_33 ( & V_30 -> V_80 ) - V_81 ;
V_79 += F_34 () % ( 2 * V_81 ) ;
return V_82 + F_35 ( V_79 ) ;
}
static unsigned long F_36 ( void )
{
return V_82 + F_35 ( F_34 () % ( V_81 / 2 ) ) ;
}
static T_1 F_37 ( T_1 V_73 ,
const struct V_29 * V_30 )
{
int V_83 = F_33 ( & V_30 -> V_83 ) ;
int V_84 ;
V_84 = V_73 * ( V_74 - V_83 ) ;
V_84 /= V_74 ;
return V_84 ;
}
static int F_38 ( int V_85 , int V_86 ,
T_5 V_87 )
{
int V_88 = 0 ;
V_88 += V_85 + V_64 ;
V_88 += F_39 ( V_87 ) ;
return ( V_88 <= V_86 ) &&
( V_88 <= V_89 ) ;
}
static void F_40 ( struct V_90 * V_91 ,
struct V_41 * V_42 )
{
struct V_29 * V_30 = F_18 ( V_42 -> V_45 ) ;
char * V_92 ;
T_1 V_93 ;
T_6 V_85 ;
struct V_58 * V_58 ;
struct V_94 * V_95 ;
T_1 * V_96 ;
if ( V_42 -> V_97 != V_98 )
return;
V_93 = 0 ;
V_85 = 0 ;
V_96 = V_91 -> V_95 -> V_99 ;
V_58 = (struct V_58 * ) V_96 ;
while ( F_38 ( V_85 , V_91 -> V_86 ,
V_58 -> V_87 ) ) {
if ( V_91 -> V_100 & F_41 ( V_93 ) &&
V_91 -> V_50 == V_42 )
V_58 -> V_70 |= V_101 ;
else
V_58 -> V_70 &= ~ V_101 ;
if ( V_93 > 0 || ! V_91 -> V_102 )
V_92 = L_2 ;
else
V_92 = L_3 ;
F_24 ( V_54 , V_30 ,
L_4 ,
V_92 , ( V_93 > 0 ? L_5 : L_6 ) ,
V_58 -> V_55 ,
F_42 ( V_58 -> V_103 ) ,
V_58 -> V_73 , V_58 -> V_69 ,
( V_58 -> V_70 & V_101 ?
L_7 : L_8 ) ,
V_42 -> V_56 -> V_57 ,
V_42 -> V_56 -> V_75 ) ;
V_85 += V_64 ;
V_85 += F_39 ( V_58 -> V_87 ) ;
V_93 ++ ;
V_96 = V_91 -> V_95 -> V_99 + V_85 ;
V_58 = (struct V_58 * ) V_96 ;
}
V_95 = F_43 ( V_91 -> V_95 , V_22 ) ;
if ( V_95 ) {
F_44 ( V_30 , V_104 ) ;
F_45 ( V_30 , V_105 ,
V_95 -> V_106 + V_107 ) ;
F_46 ( V_95 , V_42 , V_108 ) ;
}
}
static void F_47 ( struct V_90 * V_91 )
{
struct V_109 * V_45 ;
struct V_29 * V_30 ;
struct V_41 * V_110 = NULL ;
if ( ! V_91 -> V_50 ) {
F_48 ( L_9 ) ;
goto V_48;
}
V_45 = V_91 -> V_50 -> V_45 ;
V_30 = F_18 ( V_45 ) ;
if ( F_49 ( ! V_91 -> V_111 ) )
goto V_48;
if ( F_49 ( V_91 -> V_111 -> V_45 != V_45 ) )
goto V_48;
if ( V_91 -> V_50 -> V_97 != V_98 )
goto V_48;
V_110 = F_50 ( V_30 ) ;
if ( ! V_110 )
goto V_48;
F_40 ( V_91 , V_91 -> V_111 ) ;
V_48:
if ( V_110 )
F_23 ( V_110 ) ;
}
static bool
F_51 ( const struct V_58 * V_112 ,
struct V_29 * V_30 ,
int V_86 , unsigned long V_113 ,
bool V_114 ,
const struct V_41 * V_50 ,
const struct V_41 * V_111 ,
const struct V_90 * V_91 )
{
struct V_58 * V_58 ;
int V_115 = V_91 -> V_86 + V_86 ;
struct V_41 * V_110 = NULL ;
bool V_61 = false ;
unsigned long V_116 ;
V_58 = (struct V_58 * ) V_91 -> V_95 -> V_99 ;
V_116 = V_113 ;
V_116 += F_35 ( V_117 ) ;
if ( F_52 ( V_113 , V_91 -> V_113 ) &&
F_53 ( V_116 , V_91 -> V_113 ) &&
( V_115 <= V_89 ) ) {
V_110 = F_50 ( V_30 ) ;
if ( ! V_110 )
goto V_48;
if ( V_91 -> V_111 != V_111 )
goto V_48;
if ( ( ! V_114 ) &&
( ! ( V_58 -> V_70 & V_101 ) ) &&
( V_58 -> V_69 != 1 ) &&
( ( ! V_91 -> V_102 ) ||
( V_91 -> V_50 == V_110 ) ) ) {
V_61 = true ;
goto V_48;
}
if ( ( V_114 ) &&
( V_112 -> V_69 == 1 ) &&
( V_91 -> V_50 == V_50 ) &&
( V_58 -> V_70 & V_101 ||
( V_91 -> V_102 &&
V_91 -> V_50 != V_110 ) ) ) {
V_61 = true ;
goto V_48;
}
}
V_48:
if ( V_110 )
F_23 ( V_110 ) ;
return V_61 ;
}
static void F_54 ( const unsigned char * V_118 ,
int V_86 , unsigned long V_113 ,
bool V_119 ,
struct V_41 * V_50 ,
struct V_41 * V_111 ,
int V_120 )
{
struct V_29 * V_30 = F_18 ( V_50 -> V_45 ) ;
struct V_90 * V_121 ;
unsigned char * V_122 ;
unsigned int V_123 ;
if ( ! F_20 ( & V_50 -> V_49 ) )
return;
if ( ! F_20 ( & V_111 -> V_49 ) )
goto V_124;
if ( ! V_120 ) {
if ( ! F_55 ( & V_30 -> V_125 ) ) {
F_24 ( V_54 , V_30 ,
L_10 ) ;
goto V_48;
}
}
V_121 = F_7 ( sizeof( * V_121 ) , V_22 ) ;
if ( ! V_121 ) {
if ( ! V_120 )
F_56 ( & V_30 -> V_125 ) ;
goto V_48;
}
if ( ( F_33 ( & V_30 -> V_126 ) ) &&
( V_86 < V_89 ) )
V_123 = V_89 ;
else
V_123 = V_86 ;
V_123 += V_107 ;
V_121 -> V_95 = F_57 ( NULL , V_123 ) ;
if ( ! V_121 -> V_95 ) {
if ( ! V_120 )
F_56 ( & V_30 -> V_125 ) ;
F_4 ( V_121 ) ;
goto V_48;
}
V_121 -> V_95 -> V_127 = V_128 ;
F_58 ( V_121 -> V_95 , V_107 ) ;
V_122 = F_59 ( V_121 -> V_95 , V_86 ) ;
V_121 -> V_86 = V_86 ;
memcpy ( V_122 , V_118 , V_86 ) ;
V_121 -> V_102 = V_120 ;
V_121 -> V_50 = V_50 ;
V_121 -> V_111 = V_111 ;
V_121 -> V_129 = 0 ;
V_121 -> V_100 = V_71 ;
V_121 -> V_113 = V_113 ;
if ( V_119 )
V_121 -> V_100 |= 1 ;
F_6 ( & V_30 -> V_130 ) ;
F_60 ( & V_121 -> V_52 , & V_30 -> V_131 ) ;
F_8 ( & V_30 -> V_130 ) ;
F_61 ( & V_121 -> V_132 ,
V_133 ) ;
F_62 ( V_134 ,
& V_121 -> V_132 ,
V_113 - V_82 ) ;
return;
V_48:
F_23 ( V_111 ) ;
V_124:
F_23 ( V_50 ) ;
}
static void F_63 ( struct V_90 * V_121 ,
const unsigned char * V_118 ,
int V_86 , bool V_119 )
{
unsigned char * V_122 ;
unsigned long V_135 ;
V_122 = F_59 ( V_121 -> V_95 , V_86 ) ;
memcpy ( V_122 , V_118 , V_86 ) ;
V_121 -> V_86 += V_86 ;
V_121 -> V_129 ++ ;
if ( V_119 ) {
V_135 = F_41 ( V_121 -> V_129 ) ;
V_121 -> V_100 |= V_135 ;
}
}
static void F_64 ( struct V_29 * V_30 ,
unsigned char * V_118 ,
int V_86 ,
struct V_41 * V_50 ,
struct V_41 * V_111 ,
int V_120 , unsigned long V_113 )
{
struct V_90 * V_121 = NULL ;
struct V_90 * V_136 = NULL ;
struct V_58 * V_58 ;
bool V_119 ;
unsigned long V_137 ;
V_58 = (struct V_58 * ) V_118 ;
V_119 = V_58 -> V_70 & V_101 ? 1 : 0 ;
V_137 = F_35 ( V_117 ) ;
F_6 ( & V_30 -> V_130 ) ;
if ( ( F_33 ( & V_30 -> V_126 ) ) && ( ! V_120 ) ) {
F_65 (forw_packet_pos,
&bat_priv->forw_bat_list, list) {
if ( F_51 ( V_58 ,
V_30 , V_86 ,
V_113 , V_119 ,
V_50 ,
V_111 ,
V_136 ) ) {
V_121 = V_136 ;
break;
}
}
}
if ( ! V_121 ) {
F_8 ( & V_30 -> V_130 ) ;
if ( ! V_120 && F_33 ( & V_30 -> V_126 ) )
V_113 += V_137 ;
F_54 ( V_118 , V_86 ,
V_113 , V_119 ,
V_50 , V_111 ,
V_120 ) ;
} else {
F_63 ( V_121 , V_118 ,
V_86 , V_119 ) ;
F_8 ( & V_30 -> V_130 ) ;
}
}
static void F_66 ( struct V_9 * V_10 ,
const struct V_138 * V_138 ,
struct V_58 * V_58 ,
bool V_139 ,
bool V_140 ,
struct V_41 * V_50 ,
struct V_41 * V_111 )
{
struct V_29 * V_30 = F_18 ( V_50 -> V_45 ) ;
T_2 V_87 ;
if ( V_58 -> V_69 <= 1 ) {
F_24 ( V_54 , V_30 , L_11 ) ;
return;
}
if ( ! V_140 ) {
if ( V_139 )
V_58 -> V_70 |= V_141 ;
else
return;
}
V_87 = F_39 ( V_58 -> V_87 ) ;
V_58 -> V_69 -- ;
F_30 ( V_58 -> V_76 , V_138 -> V_142 ) ;
V_58 -> V_73 = F_37 ( V_58 -> V_73 ,
V_30 ) ;
F_24 ( V_54 , V_30 ,
L_12 ,
V_58 -> V_73 , V_58 -> V_69 ) ;
V_58 -> V_70 &= ~ V_77 ;
if ( V_139 )
V_58 -> V_70 |= V_101 ;
else
V_58 -> V_70 &= ~ V_101 ;
F_64 ( V_30 , ( unsigned char * ) V_58 ,
V_64 + V_87 ,
V_50 , V_111 , 0 ,
F_36 () ) ;
}
static void
F_67 ( struct V_41 * V_42 )
{
struct V_29 * V_30 = F_18 ( V_42 -> V_45 ) ;
struct V_143 * V_144 = V_30 -> V_36 ;
struct V_145 * V_146 ;
struct V_9 * V_10 ;
unsigned long * V_147 ;
T_4 V_7 ;
T_3 V_148 ;
T_1 * V_149 ;
int V_150 ;
for ( V_7 = 0 ; V_7 < V_144 -> V_32 ; V_7 ++ ) {
V_146 = & V_144 -> V_151 [ V_7 ] ;
F_68 () ;
F_69 (orig_node, head, hash_entry) {
F_6 ( & V_10 -> V_11 . V_20 ) ;
V_148 = V_42 -> V_150 * V_21 ;
V_147 = & ( V_10 -> V_11 . V_12 [ V_148 ] ) ;
F_70 ( V_30 , V_147 , 1 , 0 ) ;
V_150 = V_42 -> V_150 ;
V_149 = & V_10 -> V_11 . V_13 [ V_150 ] ;
* V_149 = F_71 ( V_147 , V_152 ) ;
F_8 ( & V_10 -> V_11 . V_20 ) ;
}
F_72 () ;
}
}
static void F_73 ( struct V_41 * V_42 )
{
struct V_29 * V_30 = F_18 ( V_42 -> V_45 ) ;
unsigned char * * V_59 = & V_42 -> V_11 . V_59 ;
struct V_58 * V_58 ;
struct V_41 * V_110 , * V_153 ;
int * V_63 = & V_42 -> V_11 . V_63 ;
T_4 V_103 ;
T_2 V_87 = 0 ;
unsigned long V_113 ;
V_110 = F_50 ( V_30 ) ;
if ( V_42 == V_110 ) {
F_74 ( V_30 ) ;
V_87 = F_75 ( V_30 , V_59 ,
V_63 ,
V_64 ) ;
}
V_58 = (struct V_58 * ) ( * V_59 ) ;
V_58 -> V_87 = F_76 ( V_87 ) ;
V_103 = ( T_4 ) F_33 ( & V_42 -> V_11 . V_62 ) ;
V_58 -> V_103 = F_77 ( V_103 ) ;
F_56 ( & V_42 -> V_11 . V_62 ) ;
F_67 ( V_42 ) ;
V_113 = F_32 ( V_30 ) ;
if ( V_42 != V_110 ) {
F_64 ( V_30 , * V_59 , * V_63 ,
V_42 , V_42 , 1 , V_113 ) ;
goto V_48;
}
F_68 () ;
F_78 (tmp_hard_iface, &batadv_hardif_list, list) {
if ( V_153 -> V_45 != V_42 -> V_45 )
continue;
F_64 ( V_30 , * V_59 ,
* V_63 , V_42 ,
V_153 , 1 , V_113 ) ;
}
F_72 () ;
V_48:
if ( V_110 )
F_23 ( V_110 ) ;
}
static void
F_79 ( struct V_29 * V_30 ,
struct V_9 * V_10 ,
struct V_154 * V_155 ,
const struct V_138 * V_138 ,
const struct V_58 * V_58 ,
struct V_41 * V_50 ,
struct V_41 * V_111 ,
enum V_156 V_157 )
{
struct V_158 * V_159 = NULL ;
struct V_158 * V_160 = NULL ;
struct V_40 * V_46 = NULL , * V_47 = NULL ;
struct V_40 * V_161 = NULL ;
struct V_9 * V_162 ;
int V_150 ;
T_1 V_163 , V_164 ;
T_1 * V_43 ;
T_1 V_165 ;
F_24 ( V_54 , V_30 ,
L_13 ) ;
F_68 () ;
F_69 (tmp_neigh_node,
&orig_node->neigh_list, list) {
V_43 = V_47 -> V_31 ;
if ( F_80 ( V_43 , V_138 -> V_142 ) &&
V_47 -> V_50 == V_50 &&
F_20 ( & V_47 -> V_49 ) ) {
if ( F_81 ( V_46 , L_14 ) )
F_82 ( V_46 ) ;
V_46 = V_47 ;
continue;
}
if ( V_157 != V_166 )
continue;
V_159 = F_83 ( V_47 ,
V_111 ) ;
if ( ! V_159 )
continue;
F_6 ( & V_47 -> V_167 ) ;
F_1 ( V_159 -> V_11 . V_168 ,
& V_159 -> V_11 . V_169 , 0 ) ;
V_165 = F_2 ( V_159 -> V_11 . V_168 ) ;
V_159 -> V_11 . V_165 = V_165 ;
F_8 ( & V_47 -> V_167 ) ;
F_84 ( V_159 ) ;
V_159 = NULL ;
}
if ( ! V_46 ) {
struct V_9 * V_170 ;
V_170 = F_10 ( V_30 , V_138 -> V_142 ) ;
if ( ! V_170 )
goto V_23;
V_46 = F_17 ( V_50 ,
V_138 -> V_142 ,
V_10 , V_170 ) ;
F_16 ( V_170 ) ;
if ( ! V_46 )
goto V_23;
} else
F_24 ( V_54 , V_30 ,
L_15 ) ;
F_72 () ;
V_159 = F_85 ( V_46 , V_111 ) ;
if ( ! V_159 )
goto V_48;
V_46 -> V_171 = V_82 ;
F_6 ( & V_46 -> V_167 ) ;
F_1 ( V_159 -> V_11 . V_168 ,
& V_159 -> V_11 . V_169 ,
V_58 -> V_73 ) ;
V_165 = F_2 ( V_159 -> V_11 . V_168 ) ;
V_159 -> V_11 . V_165 = V_165 ;
F_8 ( & V_46 -> V_167 ) ;
if ( V_157 == V_166 ) {
V_155 -> V_172 = V_58 -> V_69 ;
V_159 -> V_172 = V_58 -> V_69 ;
}
V_161 = F_86 ( V_10 , V_111 ) ;
if ( V_161 == V_46 )
goto V_48;
if ( V_161 ) {
V_160 = F_83 ( V_161 , V_111 ) ;
if ( ! V_160 )
goto V_48;
if ( V_160 -> V_11 . V_165 > V_159 -> V_11 . V_165 )
goto V_48;
}
if ( V_160 &&
( V_159 -> V_11 . V_165 == V_160 -> V_11 . V_165 ) ) {
V_162 = V_161 -> V_10 ;
F_6 ( & V_162 -> V_11 . V_20 ) ;
V_150 = V_161 -> V_50 -> V_150 ;
V_163 = V_162 -> V_11 . V_13 [ V_150 ] ;
F_8 ( & V_162 -> V_11 . V_20 ) ;
V_162 = V_46 -> V_10 ;
F_6 ( & V_162 -> V_11 . V_20 ) ;
V_150 = V_46 -> V_50 -> V_150 ;
V_164 = V_162 -> V_11 . V_13 [ V_150 ] ;
F_8 ( & V_162 -> V_11 . V_20 ) ;
if ( V_163 >= V_164 )
goto V_48;
}
F_87 ( V_30 , V_10 , V_111 , V_46 ) ;
goto V_48;
V_23:
F_72 () ;
V_48:
if ( V_46 )
F_82 ( V_46 ) ;
if ( V_161 )
F_82 ( V_161 ) ;
if ( V_159 )
F_84 ( V_159 ) ;
if ( V_160 )
F_84 ( V_160 ) ;
}
static int F_88 ( struct V_9 * V_10 ,
struct V_9 * V_173 ,
struct V_58 * V_58 ,
struct V_41 * V_50 ,
struct V_41 * V_111 )
{
struct V_29 * V_30 = F_18 ( V_50 -> V_45 ) ;
struct V_40 * V_46 = NULL , * V_47 ;
struct V_158 * V_159 ;
T_1 V_174 ;
T_1 V_175 , V_176 , V_177 , V_178 ;
unsigned int V_179 , V_180 ;
int V_181 , V_182 , V_150 , V_18 = 0 ;
unsigned int V_183 ;
int V_184 ;
F_68 () ;
F_69 (tmp_neigh_node,
&orig_neigh_node->neigh_list, list) {
if ( ! F_80 ( V_47 -> V_31 ,
V_173 -> V_55 ) )
continue;
if ( V_47 -> V_50 != V_50 )
continue;
if ( ! F_20 ( & V_47 -> V_49 ) )
continue;
V_46 = V_47 ;
break;
}
F_72 () ;
if ( ! V_46 )
V_46 = F_17 ( V_50 ,
V_173 -> V_55 ,
V_173 ,
V_173 ) ;
if ( ! V_46 )
goto V_48;
if ( V_10 == V_173 )
V_46 -> V_171 = V_82 ;
V_10 -> V_171 = V_82 ;
F_6 ( & V_10 -> V_11 . V_20 ) ;
V_150 = V_50 -> V_150 ;
V_175 = V_173 -> V_11 . V_13 [ V_150 ] ;
V_159 = F_85 ( V_46 , V_111 ) ;
if ( V_159 ) {
V_176 = V_159 -> V_11 . V_185 ;
F_84 ( V_159 ) ;
} else {
V_176 = 0 ;
}
F_8 ( & V_10 -> V_11 . V_20 ) ;
if ( V_175 > V_176 )
V_174 = V_176 ;
else
V_174 = V_175 ;
if ( V_174 < V_186 ||
V_176 < V_187 )
V_178 = 0 ;
else
V_178 = ( V_74 * V_174 ) / V_176 ;
V_177 = V_152 - V_176 ;
V_179 = V_177 * V_177 * V_177 ;
V_180 = V_152 *
V_152 *
V_152 ;
V_182 = V_74 * V_179 ;
V_182 /= V_180 ;
V_181 = V_74 - V_182 ;
V_184 = V_74 ;
if ( V_111 && ( V_50 == V_111 ) &&
F_89 ( V_111 -> V_56 ) )
V_184 = F_37 ( V_74 ,
V_30 ) ;
V_183 = V_58 -> V_73 *
V_178 *
V_181 *
V_184 ;
V_183 /= V_74 *
V_74 *
V_74 ;
V_58 -> V_73 = V_183 ;
F_24 ( V_54 , V_30 ,
L_16 ,
V_10 -> V_55 , V_173 -> V_55 , V_174 ,
V_176 , V_178 , V_181 , V_184 ,
V_58 -> V_73 , V_50 -> V_56 -> V_57 ,
V_111 ? V_111 -> V_56 -> V_57 : L_17 ) ;
if ( V_58 -> V_73 >= V_188 )
V_18 = 1 ;
V_48:
if ( V_46 )
F_82 ( V_46 ) ;
return V_18 ;
}
static enum V_156
F_90 ( const struct V_138 * V_138 ,
const struct V_58 * V_58 ,
const struct V_41 * V_50 ,
struct V_41 * V_111 )
{
struct V_29 * V_30 = F_18 ( V_50 -> V_45 ) ;
struct V_9 * V_10 ;
struct V_154 * V_155 = NULL ;
struct V_40 * V_46 ;
struct V_158 * V_159 ;
int V_189 ;
T_7 V_190 ;
int V_191 = 0 ;
int V_192 ;
enum V_156 V_18 = V_166 ;
T_4 V_103 = F_42 ( V_58 -> V_103 ) ;
T_1 * V_43 ;
T_1 V_193 ;
unsigned long * V_194 ;
V_10 = F_10 ( V_30 , V_58 -> V_55 ) ;
if ( ! V_10 )
return V_166 ;
V_155 = F_91 ( V_10 , V_111 ) ;
if ( F_49 ( ! V_155 ) ) {
F_16 ( V_10 ) ;
return 0 ;
}
F_6 ( & V_10 -> V_11 . V_20 ) ;
V_190 = V_103 - V_155 -> V_195 ;
if ( ! F_92 ( & V_10 -> V_53 ) &&
F_93 ( V_30 , V_190 ,
& V_155 -> V_196 ) ) {
V_18 = V_197 ;
goto V_48;
}
F_68 () ;
F_69 (neigh_node, &orig_node->neigh_list, list) {
V_159 = F_85 ( V_46 ,
V_111 ) ;
if ( ! V_159 )
continue;
V_43 = V_46 -> V_31 ;
V_189 = F_94 ( V_159 -> V_11 . V_198 ,
V_155 -> V_195 ,
V_103 ) ;
if ( F_80 ( V_43 , V_138 -> V_142 ) &&
V_46 -> V_50 == V_50 ) {
V_192 = 1 ;
if ( V_189 )
V_18 = V_199 ;
} else {
V_192 = 0 ;
if ( V_189 && ( V_18 != V_199 ) )
V_18 = V_200 ;
}
V_194 = V_159 -> V_11 . V_198 ;
V_191 |= F_70 ( V_30 , V_194 ,
V_190 , V_192 ) ;
V_193 = F_71 ( V_194 ,
V_152 ) ;
V_159 -> V_11 . V_185 = V_193 ;
F_84 ( V_159 ) ;
}
F_72 () ;
if ( V_191 ) {
F_24 ( V_54 , V_30 ,
L_18 ,
V_111 ? V_111 -> V_56 -> V_57 : L_17 ,
V_155 -> V_195 , V_103 ) ;
V_155 -> V_195 = V_103 ;
}
V_48:
F_8 ( & V_10 -> V_11 . V_20 ) ;
F_16 ( V_10 ) ;
if ( V_155 )
F_95 ( V_155 ) ;
return V_18 ;
}
static void
F_96 ( const struct V_94 * V_95 , int V_201 ,
struct V_9 * V_10 ,
struct V_41 * V_50 ,
struct V_41 * V_111 )
{
struct V_29 * V_30 = F_18 ( V_50 -> V_45 ) ;
struct V_40 * V_161 = NULL , * V_202 = NULL ;
struct V_9 * V_173 ;
struct V_154 * V_155 ;
struct V_40 * V_203 = NULL ;
struct V_158 * V_160 = NULL ;
struct V_58 * V_204 ;
enum V_156 V_157 ;
bool V_140 = false ;
bool V_139 = false ;
bool V_205 , V_206 ;
struct V_94 * V_207 ;
struct V_138 * V_138 ;
T_1 * V_76 ;
int V_208 ;
V_207 = F_97 ( V_95 , V_22 ) ;
if ( ! V_207 )
return;
V_138 = F_98 ( V_207 ) ;
V_204 = (struct V_58 * ) ( V_207 -> V_99 + V_201 ) ;
V_157 = F_90 ( V_138 , V_204 ,
V_50 , V_111 ) ;
if ( F_80 ( V_138 -> V_142 , V_204 -> V_55 ) )
V_139 = true ;
if ( V_157 == V_197 ) {
F_24 ( V_54 , V_30 ,
L_19 ,
V_138 -> V_142 ) ;
goto V_48;
}
if ( V_204 -> V_73 == 0 ) {
F_24 ( V_54 , V_30 ,
L_20 ) ;
goto V_48;
}
V_161 = F_86 ( V_10 , V_111 ) ;
if ( V_161 ) {
V_202 = F_86 ( V_161 -> V_10 ,
V_111 ) ;
V_160 = F_83 ( V_161 , V_111 ) ;
}
if ( ( V_160 && V_160 -> V_11 . V_165 != 0 ) &&
( F_80 ( V_161 -> V_31 , V_138 -> V_142 ) ) )
V_140 = true ;
V_76 = V_204 -> V_76 ;
if ( V_161 && V_202 &&
( F_80 ( V_161 -> V_31 , V_76 ) ) &&
! ( F_80 ( V_204 -> V_55 , V_76 ) ) &&
( F_80 ( V_161 -> V_31 , V_202 -> V_31 ) ) ) {
F_24 ( V_54 , V_30 ,
L_21 ,
V_138 -> V_142 ) ;
goto V_48;
}
if ( V_111 == V_209 )
F_99 ( V_30 , V_204 , V_10 ) ;
if ( V_139 )
V_173 = V_10 ;
else
V_173 = F_10 ( V_30 ,
V_138 -> V_142 ) ;
if ( ! V_173 )
goto V_48;
F_100 ( V_30 , V_10 , V_173 ,
V_204 , V_139 ) ;
V_203 = F_86 ( V_173 ,
V_111 ) ;
if ( ! V_139 && ( ! V_203 ) ) {
F_24 ( V_54 , V_30 ,
L_22 ) ;
goto V_210;
}
V_208 = F_88 ( V_10 , V_173 ,
V_204 , V_50 ,
V_111 ) ;
V_155 = F_91 ( V_10 , V_111 ) ;
if ( ! V_155 )
goto V_210;
V_205 = V_155 -> V_195 == F_42 ( V_204 -> V_103 ) ;
V_206 = ( V_155 -> V_172 - 3 ) <= V_204 -> V_69 ;
if ( V_208 && ( ( V_157 == V_166 ) ||
( V_205 && V_206 ) ) ) {
F_79 ( V_30 , V_10 ,
V_155 , V_138 ,
V_204 , V_50 ,
V_111 , V_157 ) ;
}
F_95 ( V_155 ) ;
if ( V_111 == V_209 )
goto V_210;
if ( V_139 ) {
if ( ( V_204 -> V_69 <= 2 ) &&
( V_50 != V_111 ) ) {
F_24 ( V_54 , V_30 ,
L_23 ) ;
goto V_210;
}
F_66 ( V_10 , V_138 , V_204 ,
V_139 ,
V_140 , V_50 ,
V_111 ) ;
F_24 ( V_54 , V_30 ,
L_24 ) ;
goto V_210;
}
if ( ! V_208 ) {
F_24 ( V_54 , V_30 ,
L_25 ) ;
goto V_210;
}
if ( V_157 == V_199 ) {
F_24 ( V_54 , V_30 ,
L_26 ) ;
goto V_210;
}
F_24 ( V_54 , V_30 ,
L_27 ) ;
F_66 ( V_10 , V_138 , V_204 ,
V_139 , V_140 ,
V_50 , V_111 ) ;
V_210:
if ( ( V_173 ) && ( ! V_139 ) )
F_16 ( V_173 ) ;
V_48:
if ( V_160 )
F_84 ( V_160 ) ;
if ( V_161 )
F_82 ( V_161 ) ;
if ( V_202 )
F_82 ( V_202 ) ;
if ( V_203 )
F_82 ( V_203 ) ;
F_101 ( V_207 ) ;
}
static void F_102 ( const struct V_94 * V_95 , int V_201 ,
struct V_41 * V_50 )
{
struct V_29 * V_30 = F_18 ( V_50 -> V_45 ) ;
struct V_9 * V_173 , * V_10 ;
struct V_41 * V_42 ;
struct V_58 * V_204 ;
T_4 V_211 ;
bool V_212 ;
struct V_138 * V_138 ;
bool V_213 = false ;
bool V_214 = false ;
bool V_215 = false ;
V_204 = (struct V_58 * ) ( V_95 -> V_99 + V_201 ) ;
V_138 = F_98 ( V_95 ) ;
if ( V_204 -> V_65 != V_66 )
return;
V_211 = F_33 ( & V_50 -> V_11 . V_62 ) ;
if ( V_204 -> V_70 & V_101 )
V_212 = true ;
else
V_212 = false ;
F_24 ( V_54 , V_30 ,
L_28 ,
V_138 -> V_142 , V_50 -> V_56 -> V_57 ,
V_50 -> V_56 -> V_75 , V_204 -> V_55 ,
V_204 -> V_76 , F_42 ( V_204 -> V_103 ) ,
V_204 -> V_73 , V_204 -> V_69 ,
V_204 -> V_67 , V_212 ) ;
F_68 () ;
F_78 (hard_iface, &batadv_hardif_list, list) {
if ( V_42 -> V_97 != V_98 )
continue;
if ( V_42 -> V_45 != V_50 -> V_45 )
continue;
if ( F_80 ( V_138 -> V_142 ,
V_42 -> V_56 -> V_75 ) )
V_214 = true ;
if ( F_80 ( V_204 -> V_55 ,
V_42 -> V_56 -> V_75 ) )
V_215 = true ;
if ( F_80 ( V_204 -> V_76 ,
V_42 -> V_56 -> V_75 ) )
V_213 = true ;
}
F_72 () ;
if ( V_214 ) {
F_24 ( V_54 , V_30 ,
L_29 ,
V_138 -> V_142 ) ;
return;
}
if ( V_215 ) {
unsigned long * V_147 ;
int V_216 ;
T_7 V_217 ;
T_6 V_150 ;
T_1 * V_218 ;
V_173 = F_10 ( V_30 ,
V_138 -> V_142 ) ;
if ( ! V_173 )
return;
if ( V_212 &&
F_80 ( V_50 -> V_56 -> V_75 ,
V_204 -> V_55 ) ) {
V_150 = V_50 -> V_150 ;
V_216 = V_150 * V_21 ;
F_6 ( & V_173 -> V_11 . V_20 ) ;
V_147 = & ( V_173 -> V_11 . V_12 [ V_216 ] ) ;
V_217 = V_211 - 2 ;
V_217 -= F_42 ( V_204 -> V_103 ) ;
F_103 ( V_147 , V_217 ) ;
V_218 = & V_173 -> V_11 . V_13 [ V_150 ] ;
* V_218 = F_71 ( V_147 ,
V_152 ) ;
F_8 ( & V_173 -> V_11 . V_20 ) ;
}
F_24 ( V_54 , V_30 ,
L_30 ) ;
F_16 ( V_173 ) ;
return;
}
if ( V_213 ) {
F_24 ( V_54 , V_30 ,
L_31 ,
V_138 -> V_142 ) ;
return;
}
if ( V_204 -> V_70 & V_141 ) {
F_24 ( V_54 , V_30 ,
L_32 ,
V_138 -> V_142 ) ;
return;
}
V_10 = F_10 ( V_30 , V_204 -> V_55 ) ;
if ( ! V_10 )
return;
F_96 ( V_95 , V_201 , V_10 ,
V_50 , V_209 ) ;
F_68 () ;
F_78 (hard_iface, &batadv_hardif_list, list) {
if ( V_42 -> V_97 != V_98 )
continue;
if ( V_42 -> V_45 != V_30 -> V_45 )
continue;
F_96 ( V_95 , V_201 , V_10 ,
V_50 , V_42 ) ;
}
F_72 () ;
F_16 ( V_10 ) ;
}
static int F_104 ( struct V_94 * V_95 ,
struct V_41 * V_50 )
{
struct V_29 * V_30 = F_18 ( V_50 -> V_45 ) ;
struct V_58 * V_204 ;
T_1 * V_96 ;
int V_201 ;
bool V_18 ;
V_18 = F_105 ( V_95 , V_50 , V_64 ) ;
if ( ! V_18 )
return V_219 ;
if ( V_30 -> V_220 -> V_221 != F_47 )
return V_219 ;
F_44 ( V_30 , V_222 ) ;
F_45 ( V_30 , V_223 ,
V_95 -> V_106 + V_107 ) ;
V_201 = 0 ;
V_204 = (struct V_58 * ) V_95 -> V_99 ;
while ( F_38 ( V_201 , F_106 ( V_95 ) ,
V_204 -> V_87 ) ) {
F_102 ( V_95 , V_201 , V_50 ) ;
V_201 += V_64 ;
V_201 += F_39 ( V_204 -> V_87 ) ;
V_96 = V_95 -> V_99 + V_201 ;
V_204 = (struct V_58 * ) V_96 ;
}
F_101 ( V_95 ) ;
return V_224 ;
}
static void
F_107 ( struct V_9 * V_10 ,
struct V_41 * V_111 ,
struct V_225 * V_226 )
{
struct V_40 * V_46 ;
struct V_158 * V_227 ;
F_69 (neigh_node, &orig_node->neigh_list, list) {
V_227 = F_83 ( V_46 , V_111 ) ;
if ( ! V_227 )
continue;
F_108 ( V_226 , L_33 ,
V_46 -> V_31 ,
V_227 -> V_11 . V_165 ) ;
F_84 ( V_227 ) ;
}
}
static void F_109 ( struct V_29 * V_30 ,
struct V_225 * V_226 ,
struct V_41 * V_111 )
{
struct V_40 * V_46 ;
struct V_143 * V_144 = V_30 -> V_36 ;
int V_228 , V_229 ;
struct V_9 * V_10 ;
struct V_158 * V_227 ;
unsigned long V_230 ;
struct V_145 * V_146 ;
int V_231 = 0 ;
T_4 V_7 ;
F_108 ( V_226 , L_34 ,
L_35 , L_36 , L_37 , V_74 ,
L_38 , L_39 , L_40 ) ;
for ( V_7 = 0 ; V_7 < V_144 -> V_32 ; V_7 ++ ) {
V_146 = & V_144 -> V_151 [ V_7 ] ;
F_68 () ;
F_69 (orig_node, head, hash_entry) {
V_46 = F_86 ( V_10 ,
V_111 ) ;
if ( ! V_46 )
continue;
V_227 = F_83 ( V_46 ,
V_111 ) ;
if ( ! V_227 )
goto V_232;
if ( V_227 -> V_11 . V_165 == 0 )
goto V_232;
V_230 = V_82 - V_10 -> V_171 ;
V_228 = F_110 ( V_230 ) ;
V_229 = V_228 / 1000 ;
V_228 = V_228 % 1000 ;
F_108 ( V_226 , L_41 ,
V_10 -> V_55 , V_229 ,
V_228 , V_227 -> V_11 . V_165 ,
V_46 -> V_31 ,
V_46 -> V_50 -> V_56 -> V_57 ) ;
F_107 ( V_10 , V_111 ,
V_226 ) ;
F_111 ( V_226 , L_42 ) ;
V_231 ++ ;
V_232:
F_82 ( V_46 ) ;
if ( V_227 )
F_84 ( V_227 ) ;
}
F_72 () ;
}
if ( V_231 == 0 )
F_111 ( V_226 , L_43 ) ;
}
static int F_112 ( struct V_40 * V_233 ,
struct V_41 * V_234 ,
struct V_40 * V_235 ,
struct V_41 * V_236 )
{
struct V_158 * V_237 , * V_238 ;
T_1 V_239 , V_240 ;
int V_241 ;
V_237 = F_83 ( V_233 , V_234 ) ;
V_238 = F_83 ( V_235 , V_236 ) ;
if ( ! V_237 || ! V_238 ) {
V_241 = 0 ;
goto V_48;
}
V_239 = V_237 -> V_11 . V_165 ;
V_240 = V_238 -> V_11 . V_165 ;
V_241 = V_239 - V_240 ;
V_48:
if ( V_237 )
F_84 ( V_237 ) ;
if ( V_238 )
F_84 ( V_238 ) ;
return V_241 ;
}
static bool
F_113 ( struct V_40 * V_233 ,
struct V_41 * V_234 ,
struct V_40 * V_235 ,
struct V_41 * V_236 )
{
struct V_158 * V_237 , * V_238 ;
T_1 V_239 , V_240 ;
bool V_18 ;
V_237 = F_83 ( V_233 , V_234 ) ;
V_238 = F_83 ( V_235 , V_236 ) ;
if ( ! V_237 || ! V_238 ) {
V_18 = false ;
goto V_48;
}
V_239 = V_237 -> V_11 . V_165 ;
V_240 = V_238 -> V_11 . V_165 ;
V_18 = ( V_239 - V_240 ) > - V_242 ;
V_48:
if ( V_237 )
F_84 ( V_237 ) ;
if ( V_238 )
F_84 ( V_238 ) ;
return V_18 ;
}
int T_8 F_114 ( void )
{
int V_18 ;
V_18 = F_115 ( V_66 ,
F_104 ) ;
if ( V_18 < 0 )
goto V_48;
V_18 = F_116 ( & V_243 ) ;
if ( V_18 < 0 )
goto V_244;
goto V_48;
V_244:
F_117 ( V_66 ) ;
V_48:
return V_18 ;
}

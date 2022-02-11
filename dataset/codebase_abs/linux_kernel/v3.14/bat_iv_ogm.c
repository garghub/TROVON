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
memcpy ( V_58 -> V_55 ,
V_42 -> V_56 -> V_75 , V_76 ) ;
memcpy ( V_58 -> V_77 ,
V_42 -> V_56 -> V_75 , V_76 ) ;
}
static void
F_30 ( struct V_41 * V_42 )
{
struct V_58 * V_58 ;
unsigned char * V_59 = V_42 -> V_11 . V_59 ;
V_58 = (struct V_58 * ) V_59 ;
V_58 -> V_70 = V_78 ;
V_58 -> V_69 = V_79 ;
}
static unsigned long
F_31 ( const struct V_29 * V_30 )
{
unsigned int V_80 ;
V_80 = F_32 ( & V_30 -> V_81 ) - V_82 ;
V_80 += F_33 () % ( 2 * V_82 ) ;
return V_83 + F_34 ( V_80 ) ;
}
static unsigned long F_35 ( void )
{
return V_83 + F_34 ( F_33 () % ( V_82 / 2 ) ) ;
}
static T_1 F_36 ( T_1 V_73 ,
const struct V_29 * V_30 )
{
int V_84 = F_32 ( & V_30 -> V_84 ) ;
int V_85 ;
V_85 = V_73 * ( V_74 - V_84 ) ;
V_85 /= V_74 ;
return V_85 ;
}
static int F_37 ( int V_86 , int V_87 ,
T_5 V_88 )
{
int V_89 = 0 ;
V_89 += V_86 + V_64 ;
V_89 += F_38 ( V_88 ) ;
return ( V_89 <= V_87 ) &&
( V_89 <= V_90 ) ;
}
static void F_39 ( struct V_91 * V_92 ,
struct V_41 * V_42 )
{
struct V_29 * V_30 = F_18 ( V_42 -> V_45 ) ;
char * V_93 ;
T_1 V_94 ;
T_6 V_86 ;
struct V_58 * V_58 ;
struct V_95 * V_96 ;
T_1 * V_97 ;
if ( V_42 -> V_98 != V_99 )
return;
V_94 = 0 ;
V_86 = 0 ;
V_97 = V_92 -> V_96 -> V_100 ;
V_58 = (struct V_58 * ) V_97 ;
while ( F_37 ( V_86 , V_92 -> V_87 ,
V_58 -> V_88 ) ) {
if ( V_92 -> V_101 & F_40 ( V_94 ) &&
V_92 -> V_50 == V_42 )
V_58 -> V_70 |= V_102 ;
else
V_58 -> V_70 &= ~ V_102 ;
if ( V_94 > 0 || ! V_92 -> V_103 )
V_93 = L_2 ;
else
V_93 = L_3 ;
F_24 ( V_54 , V_30 ,
L_4 ,
V_93 , ( V_94 > 0 ? L_5 : L_6 ) ,
V_58 -> V_55 ,
F_41 ( V_58 -> V_104 ) ,
V_58 -> V_73 , V_58 -> V_69 ,
( V_58 -> V_70 & V_102 ?
L_7 : L_8 ) ,
V_42 -> V_56 -> V_57 ,
V_42 -> V_56 -> V_75 ) ;
V_86 += V_64 ;
V_86 += F_38 ( V_58 -> V_88 ) ;
V_94 ++ ;
V_97 = V_92 -> V_96 -> V_100 + V_86 ;
V_58 = (struct V_58 * ) V_97 ;
}
V_96 = F_42 ( V_92 -> V_96 , V_22 ) ;
if ( V_96 ) {
F_43 ( V_30 , V_105 ) ;
F_44 ( V_30 , V_106 ,
V_96 -> V_107 + V_108 ) ;
F_45 ( V_96 , V_42 , V_109 ) ;
}
}
static void F_46 ( struct V_91 * V_92 )
{
struct V_110 * V_45 ;
struct V_29 * V_30 ;
struct V_41 * V_111 = NULL ;
if ( ! V_92 -> V_50 ) {
F_47 ( L_9 ) ;
goto V_48;
}
V_45 = V_92 -> V_50 -> V_45 ;
V_30 = F_18 ( V_45 ) ;
if ( F_48 ( ! V_92 -> V_112 ) )
goto V_48;
if ( F_48 ( V_92 -> V_112 -> V_45 != V_45 ) )
goto V_48;
if ( V_92 -> V_50 -> V_98 != V_99 )
goto V_48;
V_111 = F_49 ( V_30 ) ;
if ( ! V_111 )
goto V_48;
F_39 ( V_92 , V_92 -> V_112 ) ;
V_48:
if ( V_111 )
F_23 ( V_111 ) ;
}
static bool
F_50 ( const struct V_58 * V_113 ,
struct V_29 * V_30 ,
int V_87 , unsigned long V_114 ,
bool V_115 ,
const struct V_41 * V_50 ,
const struct V_41 * V_112 ,
const struct V_91 * V_92 )
{
struct V_58 * V_58 ;
int V_116 = V_92 -> V_87 + V_87 ;
struct V_41 * V_111 = NULL ;
bool V_61 = false ;
unsigned long V_117 ;
V_58 = (struct V_58 * ) V_92 -> V_96 -> V_100 ;
V_117 = V_114 ;
V_117 += F_34 ( V_118 ) ;
if ( F_51 ( V_114 , V_92 -> V_114 ) &&
F_52 ( V_117 , V_92 -> V_114 ) &&
( V_116 <= V_90 ) ) {
V_111 = F_49 ( V_30 ) ;
if ( ! V_111 )
goto V_48;
if ( V_92 -> V_112 != V_112 )
goto V_48;
if ( ( ! V_115 ) &&
( ! ( V_58 -> V_70 & V_102 ) ) &&
( V_58 -> V_69 != 1 ) &&
( ( ! V_92 -> V_103 ) ||
( V_92 -> V_50 == V_111 ) ) ) {
V_61 = true ;
goto V_48;
}
if ( ( V_115 ) &&
( V_113 -> V_69 == 1 ) &&
( V_92 -> V_50 == V_50 ) &&
( V_58 -> V_70 & V_102 ||
( V_92 -> V_103 &&
V_92 -> V_50 != V_111 ) ) ) {
V_61 = true ;
goto V_48;
}
}
V_48:
if ( V_111 )
F_23 ( V_111 ) ;
return V_61 ;
}
static void F_53 ( const unsigned char * V_119 ,
int V_87 , unsigned long V_114 ,
bool V_120 ,
struct V_41 * V_50 ,
struct V_41 * V_112 ,
int V_121 )
{
struct V_29 * V_30 = F_18 ( V_50 -> V_45 ) ;
struct V_91 * V_122 ;
unsigned char * V_123 ;
unsigned int V_124 ;
if ( ! F_20 ( & V_50 -> V_49 ) )
return;
if ( ! F_20 ( & V_112 -> V_49 ) )
goto V_125;
if ( ! V_121 ) {
if ( ! F_54 ( & V_30 -> V_126 ) ) {
F_24 ( V_54 , V_30 ,
L_10 ) ;
goto V_48;
}
}
V_122 = F_7 ( sizeof( * V_122 ) , V_22 ) ;
if ( ! V_122 ) {
if ( ! V_121 )
F_55 ( & V_30 -> V_126 ) ;
goto V_48;
}
if ( ( F_32 ( & V_30 -> V_127 ) ) &&
( V_87 < V_90 ) )
V_124 = V_90 ;
else
V_124 = V_87 ;
V_124 += V_108 ;
V_122 -> V_96 = F_56 ( NULL , V_124 ) ;
if ( ! V_122 -> V_96 ) {
if ( ! V_121 )
F_55 ( & V_30 -> V_126 ) ;
F_4 ( V_122 ) ;
goto V_48;
}
V_122 -> V_96 -> V_128 = V_129 ;
F_57 ( V_122 -> V_96 , V_108 ) ;
V_123 = F_58 ( V_122 -> V_96 , V_87 ) ;
V_122 -> V_87 = V_87 ;
memcpy ( V_123 , V_119 , V_87 ) ;
V_122 -> V_103 = V_121 ;
V_122 -> V_50 = V_50 ;
V_122 -> V_112 = V_112 ;
V_122 -> V_130 = 0 ;
V_122 -> V_101 = V_71 ;
V_122 -> V_114 = V_114 ;
if ( V_120 )
V_122 -> V_101 |= 1 ;
F_6 ( & V_30 -> V_131 ) ;
F_59 ( & V_122 -> V_52 , & V_30 -> V_132 ) ;
F_8 ( & V_30 -> V_131 ) ;
F_60 ( & V_122 -> V_133 ,
V_134 ) ;
F_61 ( V_135 ,
& V_122 -> V_133 ,
V_114 - V_83 ) ;
return;
V_48:
F_23 ( V_112 ) ;
V_125:
F_23 ( V_50 ) ;
}
static void F_62 ( struct V_91 * V_122 ,
const unsigned char * V_119 ,
int V_87 , bool V_120 )
{
unsigned char * V_123 ;
unsigned long V_136 ;
V_123 = F_58 ( V_122 -> V_96 , V_87 ) ;
memcpy ( V_123 , V_119 , V_87 ) ;
V_122 -> V_87 += V_87 ;
V_122 -> V_130 ++ ;
if ( V_120 ) {
V_136 = F_40 ( V_122 -> V_130 ) ;
V_122 -> V_101 |= V_136 ;
}
}
static void F_63 ( struct V_29 * V_30 ,
unsigned char * V_119 ,
int V_87 ,
struct V_41 * V_50 ,
struct V_41 * V_112 ,
int V_121 , unsigned long V_114 )
{
struct V_91 * V_122 = NULL ;
struct V_91 * V_137 = NULL ;
struct V_58 * V_58 ;
bool V_120 ;
unsigned long V_138 ;
V_58 = (struct V_58 * ) V_119 ;
V_120 = V_58 -> V_70 & V_102 ? 1 : 0 ;
V_138 = F_34 ( V_118 ) ;
F_6 ( & V_30 -> V_131 ) ;
if ( ( F_32 ( & V_30 -> V_127 ) ) && ( ! V_121 ) ) {
F_64 (forw_packet_pos,
&bat_priv->forw_bat_list, list) {
if ( F_50 ( V_58 ,
V_30 , V_87 ,
V_114 , V_120 ,
V_50 ,
V_112 ,
V_137 ) ) {
V_122 = V_137 ;
break;
}
}
}
if ( ! V_122 ) {
F_8 ( & V_30 -> V_131 ) ;
if ( ! V_121 && F_32 ( & V_30 -> V_127 ) )
V_114 += V_138 ;
F_53 ( V_119 , V_87 ,
V_114 , V_120 ,
V_50 , V_112 ,
V_121 ) ;
} else {
F_62 ( V_122 , V_119 ,
V_87 , V_120 ) ;
F_8 ( & V_30 -> V_131 ) ;
}
}
static void F_65 ( struct V_9 * V_10 ,
const struct V_139 * V_139 ,
struct V_58 * V_58 ,
bool V_140 ,
bool V_141 ,
struct V_41 * V_50 ,
struct V_41 * V_112 )
{
struct V_29 * V_30 = F_18 ( V_50 -> V_45 ) ;
T_2 V_88 ;
if ( V_58 -> V_69 <= 1 ) {
F_24 ( V_54 , V_30 , L_11 ) ;
return;
}
if ( ! V_141 ) {
if ( V_140 )
V_58 -> V_70 |= V_142 ;
else
return;
}
V_88 = F_38 ( V_58 -> V_88 ) ;
V_58 -> V_69 -- ;
memcpy ( V_58 -> V_77 , V_139 -> V_143 , V_76 ) ;
V_58 -> V_73 = F_36 ( V_58 -> V_73 ,
V_30 ) ;
F_24 ( V_54 , V_30 ,
L_12 ,
V_58 -> V_73 , V_58 -> V_69 ) ;
V_58 -> V_70 &= ~ V_78 ;
if ( V_140 )
V_58 -> V_70 |= V_102 ;
else
V_58 -> V_70 &= ~ V_102 ;
F_63 ( V_30 , ( unsigned char * ) V_58 ,
V_64 + V_88 ,
V_50 , V_112 , 0 ,
F_35 () ) ;
}
static void
F_66 ( struct V_41 * V_42 )
{
struct V_29 * V_30 = F_18 ( V_42 -> V_45 ) ;
struct V_144 * V_145 = V_30 -> V_36 ;
struct V_146 * V_147 ;
struct V_9 * V_10 ;
unsigned long * V_148 ;
T_4 V_7 ;
T_3 V_149 ;
T_1 * V_150 ;
int V_151 ;
for ( V_7 = 0 ; V_7 < V_145 -> V_32 ; V_7 ++ ) {
V_147 = & V_145 -> V_152 [ V_7 ] ;
F_67 () ;
F_68 (orig_node, head, hash_entry) {
F_6 ( & V_10 -> V_11 . V_20 ) ;
V_149 = V_42 -> V_151 * V_21 ;
V_148 = & ( V_10 -> V_11 . V_12 [ V_149 ] ) ;
F_69 ( V_30 , V_148 , 1 , 0 ) ;
V_151 = V_42 -> V_151 ;
V_150 = & V_10 -> V_11 . V_13 [ V_151 ] ;
* V_150 = F_70 ( V_148 , V_153 ) ;
F_8 ( & V_10 -> V_11 . V_20 ) ;
}
F_71 () ;
}
}
static void F_72 ( struct V_41 * V_42 )
{
struct V_29 * V_30 = F_18 ( V_42 -> V_45 ) ;
unsigned char * * V_59 = & V_42 -> V_11 . V_59 ;
struct V_58 * V_58 ;
struct V_41 * V_111 , * V_154 ;
int * V_63 = & V_42 -> V_11 . V_63 ;
T_4 V_104 ;
T_2 V_88 = 0 ;
unsigned long V_114 ;
V_111 = F_49 ( V_30 ) ;
if ( V_42 == V_111 ) {
F_73 ( V_30 ) ;
V_88 = F_74 ( V_30 , V_59 ,
V_63 ,
V_64 ) ;
}
V_58 = (struct V_58 * ) ( * V_59 ) ;
V_58 -> V_88 = F_75 ( V_88 ) ;
V_104 = ( T_4 ) F_32 ( & V_42 -> V_11 . V_62 ) ;
V_58 -> V_104 = F_76 ( V_104 ) ;
F_55 ( & V_42 -> V_11 . V_62 ) ;
F_66 ( V_42 ) ;
V_114 = F_31 ( V_30 ) ;
if ( V_42 != V_111 ) {
F_63 ( V_30 , * V_59 , * V_63 ,
V_42 , V_42 , 1 , V_114 ) ;
goto V_48;
}
F_67 () ;
F_77 (tmp_hard_iface, &batadv_hardif_list, list) {
if ( V_154 -> V_45 != V_42 -> V_45 )
continue;
F_63 ( V_30 , * V_59 ,
* V_63 , V_42 ,
V_154 , 1 , V_114 ) ;
}
F_71 () ;
V_48:
if ( V_111 )
F_23 ( V_111 ) ;
}
static void
F_78 ( struct V_29 * V_30 ,
struct V_9 * V_10 ,
struct V_155 * V_156 ,
const struct V_139 * V_139 ,
const struct V_58 * V_58 ,
struct V_41 * V_50 ,
struct V_41 * V_112 ,
enum V_157 V_158 )
{
struct V_159 * V_160 = NULL ;
struct V_159 * V_161 = NULL ;
struct V_40 * V_46 = NULL , * V_47 = NULL ;
struct V_40 * V_162 = NULL ;
struct V_9 * V_163 ;
int V_151 ;
T_1 V_164 , V_165 ;
T_1 * V_43 ;
T_1 V_166 ;
F_24 ( V_54 , V_30 ,
L_13 ) ;
F_67 () ;
F_68 (tmp_neigh_node,
&orig_node->neigh_list, list) {
V_43 = V_47 -> V_31 ;
if ( F_79 ( V_43 , V_139 -> V_143 ) &&
V_47 -> V_50 == V_50 &&
F_20 ( & V_47 -> V_49 ) ) {
if ( F_80 ( V_46 , L_14 ) )
F_81 ( V_46 ) ;
V_46 = V_47 ;
continue;
}
if ( V_158 != V_167 )
continue;
V_160 = F_82 ( V_47 ,
V_112 ) ;
if ( ! V_160 )
continue;
F_6 ( & V_47 -> V_168 ) ;
F_1 ( V_160 -> V_11 . V_169 ,
& V_160 -> V_11 . V_170 , 0 ) ;
V_166 = F_2 ( V_160 -> V_11 . V_169 ) ;
V_160 -> V_11 . V_166 = V_166 ;
F_8 ( & V_47 -> V_168 ) ;
F_83 ( V_160 ) ;
V_160 = NULL ;
}
if ( ! V_46 ) {
struct V_9 * V_171 ;
V_171 = F_10 ( V_30 , V_139 -> V_143 ) ;
if ( ! V_171 )
goto V_23;
V_46 = F_17 ( V_50 ,
V_139 -> V_143 ,
V_10 , V_171 ) ;
F_16 ( V_171 ) ;
if ( ! V_46 )
goto V_23;
} else
F_24 ( V_54 , V_30 ,
L_15 ) ;
F_71 () ;
V_160 = F_84 ( V_46 , V_112 ) ;
if ( ! V_160 )
goto V_48;
V_46 -> V_172 = V_83 ;
F_6 ( & V_46 -> V_168 ) ;
F_1 ( V_160 -> V_11 . V_169 ,
& V_160 -> V_11 . V_170 ,
V_58 -> V_73 ) ;
V_166 = F_2 ( V_160 -> V_11 . V_169 ) ;
V_160 -> V_11 . V_166 = V_166 ;
F_8 ( & V_46 -> V_168 ) ;
if ( V_158 == V_167 ) {
V_156 -> V_173 = V_58 -> V_69 ;
V_160 -> V_173 = V_58 -> V_69 ;
}
V_162 = F_85 ( V_10 , V_112 ) ;
if ( V_162 == V_46 )
goto V_48;
if ( V_162 ) {
V_161 = F_82 ( V_162 , V_112 ) ;
if ( ! V_161 )
goto V_48;
if ( V_161 -> V_11 . V_166 > V_160 -> V_11 . V_166 )
goto V_48;
}
if ( V_161 &&
( V_160 -> V_11 . V_166 == V_161 -> V_11 . V_166 ) ) {
V_163 = V_162 -> V_10 ;
F_6 ( & V_163 -> V_11 . V_20 ) ;
V_151 = V_162 -> V_50 -> V_151 ;
V_164 = V_163 -> V_11 . V_13 [ V_151 ] ;
F_8 ( & V_163 -> V_11 . V_20 ) ;
V_163 = V_46 -> V_10 ;
F_6 ( & V_163 -> V_11 . V_20 ) ;
V_151 = V_46 -> V_50 -> V_151 ;
V_165 = V_163 -> V_11 . V_13 [ V_151 ] ;
F_8 ( & V_163 -> V_11 . V_20 ) ;
if ( V_164 >= V_165 )
goto V_48;
}
F_86 ( V_30 , V_10 , V_112 , V_46 ) ;
goto V_48;
V_23:
F_71 () ;
V_48:
if ( V_46 )
F_81 ( V_46 ) ;
if ( V_162 )
F_81 ( V_162 ) ;
if ( V_160 )
F_83 ( V_160 ) ;
if ( V_161 )
F_83 ( V_161 ) ;
}
static int F_87 ( struct V_9 * V_10 ,
struct V_9 * V_174 ,
struct V_58 * V_58 ,
struct V_41 * V_50 ,
struct V_41 * V_112 )
{
struct V_29 * V_30 = F_18 ( V_50 -> V_45 ) ;
struct V_40 * V_46 = NULL , * V_47 ;
struct V_159 * V_160 ;
T_1 V_175 ;
T_1 V_176 , V_177 , V_178 , V_179 ;
unsigned int V_180 , V_181 ;
int V_182 , V_183 , V_151 , V_18 = 0 ;
unsigned int V_184 ;
int V_185 ;
F_67 () ;
F_68 (tmp_neigh_node,
&orig_neigh_node->neigh_list, list) {
if ( ! F_79 ( V_47 -> V_31 ,
V_174 -> V_55 ) )
continue;
if ( V_47 -> V_50 != V_50 )
continue;
if ( ! F_20 ( & V_47 -> V_49 ) )
continue;
V_46 = V_47 ;
break;
}
F_71 () ;
if ( ! V_46 )
V_46 = F_17 ( V_50 ,
V_174 -> V_55 ,
V_174 ,
V_174 ) ;
if ( ! V_46 )
goto V_48;
if ( V_10 == V_174 )
V_46 -> V_172 = V_83 ;
V_10 -> V_172 = V_83 ;
F_6 ( & V_10 -> V_11 . V_20 ) ;
V_151 = V_50 -> V_151 ;
V_176 = V_174 -> V_11 . V_13 [ V_151 ] ;
V_160 = F_84 ( V_46 , V_112 ) ;
if ( V_160 ) {
V_177 = V_160 -> V_11 . V_186 ;
F_83 ( V_160 ) ;
} else {
V_177 = 0 ;
}
F_8 ( & V_10 -> V_11 . V_20 ) ;
if ( V_176 > V_177 )
V_175 = V_177 ;
else
V_175 = V_176 ;
if ( V_175 < V_187 ||
V_177 < V_188 )
V_179 = 0 ;
else
V_179 = ( V_74 * V_175 ) / V_177 ;
V_178 = V_153 - V_177 ;
V_180 = V_178 * V_178 * V_178 ;
V_181 = V_153 *
V_153 *
V_153 ;
V_183 = V_74 * V_180 ;
V_183 /= V_181 ;
V_182 = V_74 - V_183 ;
V_185 = V_74 ;
if ( V_112 && ( V_50 == V_112 ) &&
F_88 ( V_112 -> V_56 ) )
V_185 = F_36 ( V_74 ,
V_30 ) ;
V_184 = V_58 -> V_73 *
V_179 *
V_182 *
V_185 ;
V_184 /= V_74 *
V_74 *
V_74 ;
V_58 -> V_73 = V_184 ;
F_24 ( V_54 , V_30 ,
L_16 ,
V_10 -> V_55 , V_174 -> V_55 , V_175 ,
V_177 , V_179 , V_182 , V_185 ,
V_58 -> V_73 , V_50 -> V_56 -> V_57 ,
V_112 ? V_112 -> V_56 -> V_57 : L_17 ) ;
if ( V_58 -> V_73 >= V_189 )
V_18 = 1 ;
V_48:
if ( V_46 )
F_81 ( V_46 ) ;
return V_18 ;
}
static enum V_157
F_89 ( const struct V_139 * V_139 ,
const struct V_58 * V_58 ,
const struct V_41 * V_50 ,
struct V_41 * V_112 )
{
struct V_29 * V_30 = F_18 ( V_50 -> V_45 ) ;
struct V_9 * V_10 ;
struct V_155 * V_156 = NULL ;
struct V_40 * V_46 ;
struct V_159 * V_160 ;
int V_190 ;
T_7 V_191 ;
int V_192 = 0 ;
int V_193 ;
enum V_157 V_18 = V_167 ;
T_4 V_104 = F_41 ( V_58 -> V_104 ) ;
T_1 * V_43 ;
T_1 V_194 ;
unsigned long * V_195 ;
V_10 = F_10 ( V_30 , V_58 -> V_55 ) ;
if ( ! V_10 )
return V_167 ;
V_156 = F_90 ( V_10 , V_112 ) ;
if ( F_48 ( ! V_156 ) ) {
F_16 ( V_10 ) ;
return 0 ;
}
F_6 ( & V_10 -> V_11 . V_20 ) ;
V_191 = V_104 - V_156 -> V_196 ;
if ( ! F_91 ( & V_10 -> V_53 ) &&
F_92 ( V_30 , V_191 ,
& V_156 -> V_197 ) ) {
V_18 = V_198 ;
goto V_48;
}
F_67 () ;
F_68 (neigh_node, &orig_node->neigh_list, list) {
V_160 = F_84 ( V_46 ,
V_112 ) ;
if ( ! V_160 )
continue;
V_43 = V_46 -> V_31 ;
V_190 = F_93 ( V_160 -> V_11 . V_199 ,
V_156 -> V_196 ,
V_104 ) ;
if ( F_79 ( V_43 , V_139 -> V_143 ) &&
V_46 -> V_50 == V_50 ) {
V_193 = 1 ;
if ( V_190 )
V_18 = V_200 ;
} else {
V_193 = 0 ;
if ( V_190 && ( V_18 != V_200 ) )
V_18 = V_201 ;
}
V_195 = V_160 -> V_11 . V_199 ;
V_192 |= F_69 ( V_30 , V_195 ,
V_191 , V_193 ) ;
V_194 = F_70 ( V_195 ,
V_153 ) ;
V_160 -> V_11 . V_186 = V_194 ;
F_83 ( V_160 ) ;
}
F_71 () ;
if ( V_192 ) {
F_24 ( V_54 , V_30 ,
L_18 ,
V_112 ? V_112 -> V_56 -> V_57 : L_17 ,
V_156 -> V_196 , V_104 ) ;
V_156 -> V_196 = V_104 ;
}
V_48:
F_8 ( & V_10 -> V_11 . V_20 ) ;
F_16 ( V_10 ) ;
if ( V_156 )
F_94 ( V_156 ) ;
return V_18 ;
}
static void
F_95 ( const struct V_95 * V_96 , int V_202 ,
struct V_9 * V_10 ,
struct V_41 * V_50 ,
struct V_41 * V_112 )
{
struct V_29 * V_30 = F_18 ( V_50 -> V_45 ) ;
struct V_40 * V_162 = NULL , * V_203 = NULL ;
struct V_9 * V_174 ;
struct V_155 * V_156 ;
struct V_40 * V_204 = NULL ;
struct V_159 * V_161 = NULL ;
struct V_58 * V_205 ;
enum V_157 V_158 ;
bool V_141 = false ;
bool V_140 = false ;
bool V_206 , V_207 ;
struct V_95 * V_208 ;
struct V_139 * V_139 ;
T_1 * V_77 ;
int V_209 ;
V_208 = F_96 ( V_96 , V_22 ) ;
if ( ! V_208 )
return;
V_139 = F_97 ( V_208 ) ;
V_205 = (struct V_58 * ) ( V_208 -> V_100 + V_202 ) ;
V_158 = F_89 ( V_139 , V_205 ,
V_50 , V_112 ) ;
if ( F_79 ( V_139 -> V_143 , V_205 -> V_55 ) )
V_140 = true ;
if ( V_158 == V_198 ) {
F_24 ( V_54 , V_30 ,
L_19 ,
V_139 -> V_143 ) ;
goto V_48;
}
if ( V_205 -> V_73 == 0 ) {
F_24 ( V_54 , V_30 ,
L_20 ) ;
goto V_48;
}
V_162 = F_85 ( V_10 , V_112 ) ;
if ( V_162 ) {
V_203 = F_85 ( V_162 -> V_10 ,
V_112 ) ;
V_161 = F_82 ( V_162 , V_112 ) ;
}
if ( ( V_161 && V_161 -> V_11 . V_166 != 0 ) &&
( F_79 ( V_162 -> V_31 , V_139 -> V_143 ) ) )
V_141 = true ;
V_77 = V_205 -> V_77 ;
if ( V_162 && V_203 &&
( F_79 ( V_162 -> V_31 , V_77 ) ) &&
! ( F_79 ( V_205 -> V_55 , V_77 ) ) &&
( F_79 ( V_162 -> V_31 , V_203 -> V_31 ) ) ) {
F_24 ( V_54 , V_30 ,
L_21 ,
V_139 -> V_143 ) ;
goto V_48;
}
if ( V_112 == V_210 )
F_98 ( V_30 , V_205 , V_10 ) ;
if ( V_140 )
V_174 = V_10 ;
else
V_174 = F_10 ( V_30 ,
V_139 -> V_143 ) ;
if ( ! V_174 )
goto V_48;
F_99 ( V_30 , V_10 , V_174 ,
V_205 , V_140 ) ;
V_204 = F_85 ( V_174 ,
V_112 ) ;
if ( ! V_140 && ( ! V_204 ) ) {
F_24 ( V_54 , V_30 ,
L_22 ) ;
goto V_211;
}
V_209 = F_87 ( V_10 , V_174 ,
V_205 , V_50 ,
V_112 ) ;
V_156 = F_90 ( V_10 , V_112 ) ;
if ( ! V_156 )
goto V_211;
V_206 = V_156 -> V_196 == F_41 ( V_205 -> V_104 ) ;
V_207 = ( V_156 -> V_173 - 3 ) <= V_205 -> V_69 ;
if ( V_209 && ( ( V_158 == V_167 ) ||
( V_206 && V_207 ) ) ) {
F_78 ( V_30 , V_10 ,
V_156 , V_139 ,
V_205 , V_50 ,
V_112 , V_158 ) ;
}
F_94 ( V_156 ) ;
if ( V_112 == V_210 )
goto V_211;
if ( V_140 ) {
if ( ( V_205 -> V_69 <= 2 ) &&
( V_50 != V_112 ) ) {
F_24 ( V_54 , V_30 ,
L_23 ) ;
goto V_211;
}
F_65 ( V_10 , V_139 , V_205 ,
V_140 ,
V_141 , V_50 ,
V_112 ) ;
F_24 ( V_54 , V_30 ,
L_24 ) ;
goto V_211;
}
if ( ! V_209 ) {
F_24 ( V_54 , V_30 ,
L_25 ) ;
goto V_211;
}
if ( V_158 == V_200 ) {
F_24 ( V_54 , V_30 ,
L_26 ) ;
goto V_211;
}
F_24 ( V_54 , V_30 ,
L_27 ) ;
F_65 ( V_10 , V_139 , V_205 ,
V_140 , V_141 ,
V_50 , V_112 ) ;
V_211:
if ( ( V_174 ) && ( ! V_140 ) )
F_16 ( V_174 ) ;
V_48:
if ( V_162 )
F_81 ( V_162 ) ;
if ( V_203 )
F_81 ( V_203 ) ;
if ( V_204 )
F_81 ( V_204 ) ;
F_100 ( V_208 ) ;
}
static void F_101 ( const struct V_95 * V_96 , int V_202 ,
struct V_41 * V_50 )
{
struct V_29 * V_30 = F_18 ( V_50 -> V_45 ) ;
struct V_9 * V_174 , * V_10 ;
struct V_41 * V_42 ;
struct V_58 * V_205 ;
T_4 V_212 ;
bool V_213 ;
struct V_139 * V_139 ;
bool V_214 = false ;
bool V_215 = false ;
bool V_216 = false ;
V_205 = (struct V_58 * ) ( V_96 -> V_100 + V_202 ) ;
V_139 = F_97 ( V_96 ) ;
if ( V_205 -> V_65 != V_66 )
return;
V_212 = F_32 ( & V_50 -> V_11 . V_62 ) ;
if ( V_205 -> V_70 & V_102 )
V_213 = true ;
else
V_213 = false ;
F_24 ( V_54 , V_30 ,
L_28 ,
V_139 -> V_143 , V_50 -> V_56 -> V_57 ,
V_50 -> V_56 -> V_75 , V_205 -> V_55 ,
V_205 -> V_77 , F_41 ( V_205 -> V_104 ) ,
V_205 -> V_73 , V_205 -> V_69 ,
V_205 -> V_67 , V_213 ) ;
F_67 () ;
F_77 (hard_iface, &batadv_hardif_list, list) {
if ( V_42 -> V_98 != V_99 )
continue;
if ( V_42 -> V_45 != V_50 -> V_45 )
continue;
if ( F_79 ( V_139 -> V_143 ,
V_42 -> V_56 -> V_75 ) )
V_215 = true ;
if ( F_79 ( V_205 -> V_55 ,
V_42 -> V_56 -> V_75 ) )
V_216 = true ;
if ( F_79 ( V_205 -> V_77 ,
V_42 -> V_56 -> V_75 ) )
V_214 = true ;
}
F_71 () ;
if ( V_215 ) {
F_24 ( V_54 , V_30 ,
L_29 ,
V_139 -> V_143 ) ;
return;
}
if ( V_216 ) {
unsigned long * V_148 ;
int V_217 ;
T_7 V_218 ;
T_6 V_151 ;
T_1 * V_219 ;
V_174 = F_10 ( V_30 ,
V_139 -> V_143 ) ;
if ( ! V_174 )
return;
if ( V_213 &&
F_79 ( V_50 -> V_56 -> V_75 ,
V_205 -> V_55 ) ) {
V_151 = V_50 -> V_151 ;
V_217 = V_151 * V_21 ;
F_6 ( & V_174 -> V_11 . V_20 ) ;
V_148 = & ( V_174 -> V_11 . V_12 [ V_217 ] ) ;
V_218 = V_212 - 2 ;
V_218 -= F_41 ( V_205 -> V_104 ) ;
F_102 ( V_148 , V_218 ) ;
V_219 = & V_174 -> V_11 . V_13 [ V_151 ] ;
* V_219 = F_70 ( V_148 ,
V_153 ) ;
F_8 ( & V_174 -> V_11 . V_20 ) ;
}
F_24 ( V_54 , V_30 ,
L_30 ) ;
F_16 ( V_174 ) ;
return;
}
if ( V_214 ) {
F_24 ( V_54 , V_30 ,
L_31 ,
V_139 -> V_143 ) ;
return;
}
if ( V_205 -> V_70 & V_142 ) {
F_24 ( V_54 , V_30 ,
L_32 ,
V_139 -> V_143 ) ;
return;
}
V_10 = F_10 ( V_30 , V_205 -> V_55 ) ;
if ( ! V_10 )
return;
F_95 ( V_96 , V_202 , V_10 ,
V_50 , V_210 ) ;
F_67 () ;
F_77 (hard_iface, &batadv_hardif_list, list) {
if ( V_42 -> V_98 != V_99 )
continue;
if ( V_42 -> V_45 != V_30 -> V_45 )
continue;
F_95 ( V_96 , V_202 , V_10 ,
V_50 , V_42 ) ;
}
F_71 () ;
F_16 ( V_10 ) ;
}
static int F_103 ( struct V_95 * V_96 ,
struct V_41 * V_50 )
{
struct V_29 * V_30 = F_18 ( V_50 -> V_45 ) ;
struct V_58 * V_205 ;
T_1 * V_97 ;
int V_202 ;
bool V_18 ;
V_18 = F_104 ( V_96 , V_50 , V_64 ) ;
if ( ! V_18 )
return V_220 ;
if ( V_30 -> V_221 -> V_222 != F_46 )
return V_220 ;
F_43 ( V_30 , V_223 ) ;
F_44 ( V_30 , V_224 ,
V_96 -> V_107 + V_108 ) ;
V_202 = 0 ;
V_205 = (struct V_58 * ) V_96 -> V_100 ;
while ( F_37 ( V_202 , F_105 ( V_96 ) ,
V_205 -> V_88 ) ) {
F_101 ( V_96 , V_202 , V_50 ) ;
V_202 += V_64 ;
V_202 += F_38 ( V_205 -> V_88 ) ;
V_97 = V_96 -> V_100 + V_202 ;
V_205 = (struct V_58 * ) V_97 ;
}
F_100 ( V_96 ) ;
return V_225 ;
}
static void
F_106 ( struct V_9 * V_10 ,
struct V_41 * V_112 ,
struct V_226 * V_227 )
{
struct V_40 * V_46 ;
struct V_159 * V_228 ;
F_68 (neigh_node, &orig_node->neigh_list, list) {
V_228 = F_82 ( V_46 , V_112 ) ;
if ( ! V_228 )
continue;
F_107 ( V_227 , L_33 ,
V_46 -> V_31 ,
V_228 -> V_11 . V_166 ) ;
F_83 ( V_228 ) ;
}
}
static void F_108 ( struct V_29 * V_30 ,
struct V_226 * V_227 ,
struct V_41 * V_112 )
{
struct V_40 * V_46 ;
struct V_144 * V_145 = V_30 -> V_36 ;
int V_229 , V_230 ;
struct V_9 * V_10 ;
struct V_159 * V_228 ;
unsigned long V_231 ;
struct V_146 * V_147 ;
int V_232 = 0 ;
T_4 V_7 ;
F_107 ( V_227 , L_34 ,
L_35 , L_36 , L_37 , V_74 ,
L_38 , L_39 , L_40 ) ;
for ( V_7 = 0 ; V_7 < V_145 -> V_32 ; V_7 ++ ) {
V_147 = & V_145 -> V_152 [ V_7 ] ;
F_67 () ;
F_68 (orig_node, head, hash_entry) {
V_46 = F_85 ( V_10 ,
V_112 ) ;
if ( ! V_46 )
continue;
V_228 = F_82 ( V_46 ,
V_112 ) ;
if ( ! V_228 )
goto V_233;
if ( V_228 -> V_11 . V_166 == 0 )
goto V_233;
V_231 = V_83 - V_10 -> V_172 ;
V_229 = F_109 ( V_231 ) ;
V_230 = V_229 / 1000 ;
V_229 = V_229 % 1000 ;
F_107 ( V_227 , L_41 ,
V_10 -> V_55 , V_230 ,
V_229 , V_228 -> V_11 . V_166 ,
V_46 -> V_31 ,
V_46 -> V_50 -> V_56 -> V_57 ) ;
F_106 ( V_10 , V_112 ,
V_227 ) ;
F_110 ( V_227 , L_42 ) ;
V_232 ++ ;
V_233:
F_81 ( V_46 ) ;
if ( V_228 )
F_83 ( V_228 ) ;
}
F_71 () ;
}
if ( V_232 == 0 )
F_110 ( V_227 , L_43 ) ;
}
static int F_111 ( struct V_40 * V_234 ,
struct V_41 * V_235 ,
struct V_40 * V_236 ,
struct V_41 * V_237 )
{
struct V_159 * V_238 , * V_239 ;
T_1 V_240 , V_241 ;
int V_242 ;
V_238 = F_82 ( V_234 , V_235 ) ;
V_239 = F_82 ( V_236 , V_237 ) ;
if ( ! V_238 || ! V_239 ) {
V_242 = 0 ;
goto V_48;
}
V_240 = V_238 -> V_11 . V_166 ;
V_241 = V_239 -> V_11 . V_166 ;
V_242 = V_240 - V_241 ;
V_48:
if ( V_238 )
F_83 ( V_238 ) ;
if ( V_239 )
F_83 ( V_239 ) ;
return V_242 ;
}
static bool
F_112 ( struct V_40 * V_234 ,
struct V_41 * V_235 ,
struct V_40 * V_236 ,
struct V_41 * V_237 )
{
struct V_159 * V_238 , * V_239 ;
T_1 V_240 , V_241 ;
bool V_18 ;
V_238 = F_82 ( V_234 , V_235 ) ;
V_239 = F_82 ( V_236 , V_237 ) ;
if ( ! V_238 || ! V_239 ) {
V_18 = false ;
goto V_48;
}
V_240 = V_238 -> V_11 . V_166 ;
V_241 = V_239 -> V_11 . V_166 ;
V_18 = ( V_240 - V_241 ) > - V_243 ;
V_48:
if ( V_238 )
F_83 ( V_238 ) ;
if ( V_239 )
F_83 ( V_239 ) ;
return V_18 ;
}
int T_8 F_113 ( void )
{
int V_18 ;
V_18 = F_114 ( V_66 ,
F_103 ) ;
if ( V_18 < 0 )
goto V_48;
V_18 = F_115 ( & V_244 ) ;
if ( V_18 < 0 )
goto V_245;
goto V_48;
V_245:
F_116 ( V_66 ) ;
V_48:
return V_18 ;
}

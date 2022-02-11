static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 == V_4 || V_2 -> V_3 == V_5 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_1 ) ;
return - V_8 ;
}
return 0 ;
}
static int F_3 ( struct V_9 * V_10 , int V_11 )
{
struct V_12 * V_13 ;
int V_14 ;
if ( F_4 ( ! V_10 -> V_15 ) )
return 0 ;
F_5 (tx_queue, channel) {
V_13 -> V_16 = 0 ;
V_13 -> V_17 = 0 ;
}
V_14 = F_6 ( V_10 , V_11 ) ;
if ( V_14 && F_7 ( V_10 ) ) {
struct V_18 * V_19 =
F_8 ( V_10 ) ;
F_9 ( V_10 ) ;
F_10 ( V_19 , true ) ;
}
F_5 (tx_queue, channel) {
if ( V_13 -> V_17 ) {
F_11 ( V_13 -> V_20 ,
V_13 -> V_16 , V_13 -> V_17 ) ;
}
}
return V_14 ;
}
static void F_12 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
int V_21 = V_2 -> V_22 ;
if ( V_10 -> V_23 < V_24 ) {
if ( V_10 -> V_25 > V_21 ) {
V_10 -> V_25 -= V_21 ;
V_2 -> type -> V_26 ( V_10 ) ;
}
} else if ( V_10 -> V_23 > V_27 ) {
if ( V_10 -> V_25 <
V_2 -> V_28 ) {
V_10 -> V_25 += V_21 ;
V_2 -> type -> V_26 ( V_10 ) ;
}
}
V_10 -> V_29 = 0 ;
V_10 -> V_23 = 0 ;
}
static int F_13 ( struct V_30 * V_31 , int V_11 )
{
struct V_9 * V_10 =
F_14 ( V_31 , struct V_9 , V_32 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_14 ;
F_15 ( V_2 , V_33 , V_2 -> V_7 ,
L_2 ,
V_10 -> V_10 , F_16 () ) ;
V_14 = F_3 ( V_10 , V_11 ) ;
if ( V_14 < V_11 ) {
if ( F_7 ( V_10 ) &&
V_2 -> V_34 &&
F_4 ( ++ V_10 -> V_29 == 1000 ) ) {
F_12 ( V_2 , V_10 ) ;
}
F_17 ( V_10 ) ;
F_18 ( V_31 , V_14 ) ;
F_19 ( V_10 ) ;
}
return V_14 ;
}
static int F_20 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned long V_35 ;
F_21 ( V_2 , V_36 , V_2 -> V_7 ,
L_3 , V_10 -> V_10 ) ;
V_35 = F_22 ( V_2 -> V_37 + V_2 -> V_38 + 128 ) ;
F_23 ( V_35 > V_39 ) ;
V_10 -> V_40 = F_24 ( V_35 , V_41 ) - 1 ;
return F_25 ( V_10 ) ;
}
static int F_26 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_42 ;
F_27 ( V_10 -> V_43 ) ;
F_21 ( V_2 , V_6 , V_2 -> V_7 ,
L_4 , V_10 -> V_10 ) ;
V_42 = F_28 ( V_10 ) ;
if ( V_42 == 0 ) {
V_2 -> type -> V_26 ( V_10 ) ;
V_10 -> V_44 = 0 ;
V_10 -> V_43 = true ;
}
return V_42 ;
}
void F_29 ( struct V_9 * V_10 )
{
F_21 ( V_10 -> V_2 , V_45 , V_10 -> V_2 -> V_7 ,
L_5 , V_10 -> V_10 ) ;
V_10 -> V_15 = true ;
F_30 () ;
F_31 ( & V_10 -> V_32 ) ;
F_19 ( V_10 ) ;
}
void F_32 ( struct V_9 * V_10 )
{
if ( ! V_10 -> V_15 )
return;
F_33 ( & V_10 -> V_32 ) ;
V_10 -> V_15 = false ;
}
static void F_34 ( struct V_9 * V_10 )
{
if ( ! V_10 -> V_43 )
return;
F_21 ( V_10 -> V_2 , V_6 , V_10 -> V_2 -> V_7 ,
L_6 , V_10 -> V_10 ) ;
F_35 ( V_10 ) ;
V_10 -> V_43 = false ;
}
static void F_36 ( struct V_9 * V_10 )
{
F_21 ( V_10 -> V_2 , V_6 , V_10 -> V_2 -> V_7 ,
L_7 , V_10 -> V_10 ) ;
F_37 ( V_10 ) ;
}
static struct V_9 *
F_38 ( struct V_1 * V_2 , int V_46 , struct V_9 * V_47 )
{
struct V_9 * V_10 ;
struct V_18 * V_19 ;
struct V_12 * V_13 ;
int V_48 ;
V_10 = F_39 ( sizeof( * V_10 ) , V_49 ) ;
if ( ! V_10 )
return NULL ;
V_10 -> V_2 = V_2 ;
V_10 -> V_10 = V_46 ;
V_10 -> type = & V_50 ;
for ( V_48 = 0 ; V_48 < V_51 ; V_48 ++ ) {
V_13 = & V_10 -> V_13 [ V_48 ] ;
V_13 -> V_2 = V_2 ;
V_13 -> V_52 = V_46 * V_51 + V_48 ;
V_13 -> V_10 = V_10 ;
}
V_19 = & V_10 -> V_19 ;
V_19 -> V_2 = V_2 ;
F_40 ( & V_19 -> V_53 , V_54 ,
( unsigned long ) V_19 ) ;
return V_10 ;
}
static struct V_9 *
F_41 ( const struct V_9 * V_47 )
{
struct V_9 * V_10 ;
struct V_18 * V_19 ;
struct V_12 * V_13 ;
int V_48 ;
V_10 = F_42 ( sizeof( * V_10 ) , V_49 ) ;
if ( ! V_10 )
return NULL ;
* V_10 = * V_47 ;
V_10 -> V_55 = NULL ;
F_43 ( & V_10 -> V_32 . V_56 ) ;
V_10 -> V_32 . V_57 = 0 ;
V_10 -> V_32 . V_3 = 0 ;
memset ( & V_10 -> V_58 , 0 , sizeof( V_10 -> V_58 ) ) ;
for ( V_48 = 0 ; V_48 < V_51 ; V_48 ++ ) {
V_13 = & V_10 -> V_13 [ V_48 ] ;
if ( V_13 -> V_10 )
V_13 -> V_10 = V_10 ;
V_13 -> V_59 = NULL ;
memset ( & V_13 -> V_60 , 0 , sizeof( V_13 -> V_60 ) ) ;
}
V_19 = & V_10 -> V_19 ;
V_19 -> V_59 = NULL ;
memset ( & V_19 -> V_61 , 0 , sizeof( V_19 -> V_61 ) ) ;
F_40 ( & V_19 -> V_53 , V_54 ,
( unsigned long ) V_19 ) ;
return V_10 ;
}
static int F_44 ( struct V_9 * V_10 )
{
struct V_12 * V_13 ;
struct V_18 * V_19 ;
int V_42 ;
F_21 ( V_10 -> V_2 , V_36 , V_10 -> V_2 -> V_7 ,
L_8 , V_10 -> V_10 ) ;
V_42 = V_10 -> type -> V_62 ( V_10 ) ;
if ( V_42 )
goto V_63;
V_42 = F_20 ( V_10 ) ;
if ( V_42 )
goto V_63;
F_5 (tx_queue, channel) {
V_42 = F_45 ( V_13 ) ;
if ( V_42 )
goto V_63;
}
F_46 (rx_queue, channel) {
V_42 = F_47 ( V_19 ) ;
if ( V_42 )
goto V_63;
}
return 0 ;
V_63:
F_48 ( V_10 ) ;
return V_42 ;
}
static void
F_49 ( struct V_9 * V_10 , char * V_64 , T_1 V_65 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
const char * type ;
int V_66 ;
V_66 = V_10 -> V_10 ;
if ( V_2 -> V_67 == 0 ) {
type = L_9 ;
} else if ( V_10 -> V_10 < V_2 -> V_67 ) {
type = L_10 ;
} else {
type = L_11 ;
V_66 -= V_2 -> V_67 ;
}
snprintf ( V_64 , V_65 , L_12 , V_2 -> V_68 , type , V_66 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_51 (channel, efx)
V_10 -> type -> V_69 ( V_10 ,
V_2 -> V_70 [ V_10 -> V_10 ] . V_68 ,
sizeof( V_2 -> V_70 [ 0 ] . V_68 ) ) ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
int V_42 ;
V_2 -> V_71 = 0 ;
F_53 (channel, efx) {
V_42 = F_44 ( V_10 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 ,
L_13 ,
V_10 -> V_10 ) ;
goto V_63;
}
}
F_50 ( V_2 ) ;
return 0 ;
V_63:
F_54 ( V_2 ) ;
return V_42 ;
}
static void F_55 ( struct V_1 * V_2 )
{
T_2 V_72 = V_2 -> V_7 -> V_73 ;
bool V_74 = V_2 -> V_75 ;
struct V_12 * V_13 ;
struct V_18 * V_19 ;
struct V_9 * V_10 ;
T_1 V_76 ;
V_2 -> V_77 = ( V_2 -> V_78 +
F_56 ( V_2 -> V_7 -> V_79 ) +
V_2 -> type -> V_80 ) ;
V_76 = ( sizeof( struct V_81 ) +
V_2 -> V_82 + V_2 -> V_77 ) ;
if ( V_76 <= V_83 ) {
V_2 -> V_75 = V_2 -> type -> V_84 ;
V_2 -> V_85 = 0 ;
} else if ( V_2 -> type -> V_86 ) {
F_57 ( V_87 % V_88 ) ;
F_57 ( sizeof( struct V_81 ) +
2 * F_58 ( V_89 + V_87 ,
V_90 ) >
V_83 ) ;
V_2 -> V_75 = true ;
V_2 -> V_77 = V_87 ;
V_2 -> V_85 = 0 ;
} else {
V_2 -> V_75 = false ;
V_2 -> V_85 = F_59 ( V_76 ) ;
}
F_60 ( V_2 ) ;
if ( V_2 -> V_85 )
F_21 ( V_2 , V_6 , V_2 -> V_7 ,
L_14 ,
V_2 -> V_77 , V_2 -> V_85 ,
V_2 -> V_91 ) ;
else
F_21 ( V_2 , V_6 , V_2 -> V_7 ,
L_15 ,
V_2 -> V_77 , V_2 -> V_92 ,
V_2 -> V_93 , V_2 -> V_91 ) ;
V_2 -> V_7 -> V_94 |= V_2 -> V_7 -> V_73 ;
V_2 -> V_7 -> V_94 &= ~ V_2 -> V_95 ;
V_2 -> V_7 -> V_73 |= V_2 -> V_95 ;
if ( V_2 -> V_7 -> V_73 != V_72 )
F_61 ( V_2 -> V_7 ) ;
if ( V_2 -> V_75 != V_74 )
V_2 -> type -> V_96 ( V_2 ) ;
V_2 -> V_97 = V_2 -> V_38 - F_62 ( V_2 ) ;
V_2 -> V_98 = V_2 -> V_97 / 2 ;
F_51 (channel, efx) {
F_5 (tx_queue, channel) {
F_63 ( V_13 ) ;
F_64 ( & V_2 -> V_99 ) ;
}
F_46 (rx_queue, channel) {
F_65 ( V_19 ) ;
F_64 ( & V_2 -> V_99 ) ;
F_32 ( V_10 ) ;
F_10 ( V_19 , false ) ;
F_29 ( V_10 ) ;
}
F_66 ( V_10 -> V_100 ) ;
}
if ( F_67 ( V_2 -> V_7 ) )
F_68 ( V_2 -> V_7 ) ;
}
static void F_69 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_12 * V_13 ;
struct V_18 * V_19 ;
int V_42 ;
F_70 ( V_2 ) ;
F_71 ( V_2 -> V_101 ) ;
F_51 (channel, efx) {
F_46 (rx_queue, channel)
V_19 -> V_102 = false ;
}
F_51 (channel, efx) {
if ( F_7 ( V_10 ) ) {
F_32 ( V_10 ) ;
F_29 ( V_10 ) ;
}
}
V_42 = V_2 -> type -> V_103 ( V_2 ) ;
if ( V_42 && F_72 ( V_2 ) ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_16 ) ;
F_73 ( V_2 , V_104 ) ;
} else if ( V_42 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_17 ) ;
} else {
F_21 ( V_2 , V_6 , V_2 -> V_7 ,
L_18 ) ;
}
F_51 (channel, efx) {
F_46 (rx_queue, channel)
F_74 ( V_19 ) ;
F_75 (tx_queue, channel)
F_76 ( V_13 ) ;
}
}
static void F_48 ( struct V_9 * V_10 )
{
struct V_12 * V_13 ;
struct V_18 * V_19 ;
F_21 ( V_10 -> V_2 , V_6 , V_10 -> V_2 -> V_7 ,
L_19 , V_10 -> V_10 ) ;
F_46 (rx_queue, channel)
F_77 ( V_19 ) ;
F_75 (tx_queue, channel)
F_78 ( V_13 ) ;
F_36 ( V_10 ) ;
V_10 -> type -> V_105 ( V_10 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_51 (channel, efx)
F_48 ( V_10 ) ;
}
int
F_79 ( struct V_1 * V_2 , T_3 V_37 , T_3 V_38 )
{
struct V_9 * V_106 [ V_107 ] , * V_10 ;
T_3 V_108 , V_109 ;
unsigned V_46 , V_71 = 0 ;
int V_42 , V_110 ;
V_42 = F_1 ( V_2 ) ;
if ( V_42 )
return V_42 ;
F_51 (channel, efx) {
struct V_18 * V_19 ;
struct V_12 * V_13 ;
if ( V_10 -> type -> V_111 )
continue;
V_71 = F_24 ( V_71 ,
V_10 -> V_58 . V_112 +
V_10 -> V_58 . V_35 ) ;
F_46 (rx_queue, channel)
V_71 = F_24 ( V_71 ,
V_19 -> V_61 . V_112 +
V_19 -> V_61 . V_35 ) ;
F_5 (tx_queue, channel)
V_71 = F_24 ( V_71 ,
V_13 -> V_60 . V_112 +
V_13 -> V_60 . V_35 ) ;
}
F_80 ( V_2 ) ;
F_81 ( V_2 ) ;
F_82 ( V_2 ) ;
memset ( V_106 , 0 , sizeof( V_106 ) ) ;
for ( V_46 = 0 ; V_46 < V_2 -> V_113 ; V_46 ++ ) {
V_10 = V_2 -> V_10 [ V_46 ] ;
if ( V_10 -> type -> V_111 )
V_10 = V_10 -> type -> V_111 ( V_10 ) ;
if ( ! V_10 ) {
V_42 = - V_114 ;
goto V_115;
}
V_106 [ V_46 ] = V_10 ;
}
V_108 = V_2 -> V_37 ;
V_109 = V_2 -> V_38 ;
V_2 -> V_37 = V_37 ;
V_2 -> V_38 = V_38 ;
for ( V_46 = 0 ; V_46 < V_2 -> V_113 ; V_46 ++ ) {
V_10 = V_2 -> V_10 [ V_46 ] ;
V_2 -> V_10 [ V_46 ] = V_106 [ V_46 ] ;
V_106 [ V_46 ] = V_10 ;
}
V_2 -> V_71 = V_71 ;
for ( V_46 = 0 ; V_46 < V_2 -> V_113 ; V_46 ++ ) {
V_10 = V_2 -> V_10 [ V_46 ] ;
if ( ! V_10 -> type -> V_111 )
continue;
V_42 = F_44 ( V_10 ) ;
if ( V_42 )
goto V_116;
F_83 ( V_2 -> V_10 [ V_46 ] ) ;
}
V_115:
for ( V_46 = 0 ; V_46 < V_2 -> V_113 ; V_46 ++ ) {
V_10 = V_106 [ V_46 ] ;
if ( V_10 && V_10 -> type -> V_111 ) {
F_84 ( V_10 ) ;
F_48 ( V_10 ) ;
F_85 ( V_10 ) ;
}
}
V_110 = F_86 ( V_2 ) ;
if ( V_110 ) {
V_42 = V_42 ? V_42 : V_110 ;
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_20 ) ;
F_73 ( V_2 , V_117 ) ;
} else {
F_87 ( V_2 ) ;
F_88 ( V_2 -> V_7 ) ;
}
return V_42 ;
V_116:
V_2 -> V_37 = V_108 ;
V_2 -> V_38 = V_109 ;
for ( V_46 = 0 ; V_46 < V_2 -> V_113 ; V_46 ++ ) {
V_10 = V_2 -> V_10 [ V_46 ] ;
V_2 -> V_10 [ V_46 ] = V_106 [ V_46 ] ;
V_106 [ V_46 ] = V_10 ;
}
goto V_115;
}
void F_89 ( struct V_18 * V_19 )
{
F_90 ( & V_19 -> V_53 , V_118 + F_91 ( 100 ) ) ;
}
int F_92 ( struct V_9 * V_10 )
{
return 0 ;
}
void F_93 ( struct V_9 * V_10 )
{
}
void F_94 ( struct V_1 * V_2 )
{
struct V_119 * V_120 = & V_2 -> V_120 ;
if ( ! F_95 ( V_2 -> V_7 ) )
return;
if ( V_120 -> V_121 != F_96 ( V_2 -> V_7 ) ) {
V_2 -> V_122 ++ ;
if ( V_120 -> V_121 )
F_97 ( V_2 -> V_7 ) ;
else
F_98 ( V_2 -> V_7 ) ;
}
if ( V_120 -> V_121 )
F_99 ( V_2 , V_123 , V_2 -> V_7 ,
L_21 ,
V_120 -> V_124 , V_120 -> V_125 ? L_22 : L_23 ,
V_2 -> V_7 -> V_79 ) ;
else
F_99 ( V_2 , V_123 , V_2 -> V_7 , L_24 ) ;
}
void F_100 ( struct V_1 * V_2 , T_3 V_126 )
{
V_2 -> V_127 = V_126 ;
if ( V_126 ) {
if ( V_126 & V_128 )
V_2 -> V_129 |= ( V_130 | V_131 ) ;
else
V_2 -> V_129 &= ~ ( V_130 | V_131 ) ;
if ( V_126 & V_132 )
V_2 -> V_129 ^= V_130 ;
}
}
void F_101 ( struct V_1 * V_2 , T_4 V_129 )
{
V_2 -> V_129 = V_129 ;
if ( V_2 -> V_127 ) {
if ( V_129 & V_131 )
V_2 -> V_127 |= ( V_128 |
V_132 ) ;
else
V_2 -> V_127 &= ~ ( V_128 |
V_132 ) ;
if ( V_129 & V_130 )
V_2 -> V_127 ^= V_132 ;
}
}
void F_102 ( struct V_1 * V_2 )
{
F_103 ( & V_2 -> V_133 ) ;
V_2 -> type -> V_134 ( V_2 ) ;
F_104 ( & V_2 -> V_133 ) ;
}
int F_105 ( struct V_1 * V_2 )
{
enum V_135 V_136 ;
int V_42 ;
F_66 ( ! F_106 ( & V_2 -> V_137 ) ) ;
V_136 = V_2 -> V_136 ;
if ( F_107 ( V_2 ) )
V_2 -> V_136 |= V_138 ;
else
V_2 -> V_136 &= ~ V_138 ;
V_42 = V_2 -> type -> V_139 ( V_2 ) ;
if ( V_42 )
V_2 -> V_136 = V_136 ;
return V_42 ;
}
int F_108 ( struct V_1 * V_2 )
{
int V_42 ;
F_70 ( V_2 ) ;
F_109 ( & V_2 -> V_137 ) ;
V_42 = F_105 ( V_2 ) ;
F_110 ( & V_2 -> V_137 ) ;
return V_42 ;
}
static void F_111 ( struct V_140 * V_141 )
{
struct V_1 * V_2 = F_14 ( V_141 , struct V_1 , V_142 ) ;
F_109 ( & V_2 -> V_137 ) ;
if ( V_2 -> V_101 )
F_102 ( V_2 ) ;
F_110 ( & V_2 -> V_137 ) ;
}
static int F_112 ( struct V_1 * V_2 )
{
int V_42 ;
F_21 ( V_2 , V_36 , V_2 -> V_7 , L_25 ) ;
if ( V_143 )
V_2 -> V_136 = V_144 ;
V_42 = V_2 -> type -> V_145 ( V_2 ) ;
if ( V_42 )
return V_42 ;
F_113 ( V_2 -> V_7 -> V_146 , V_2 -> V_7 -> V_147 ) ;
return 0 ;
}
static int F_114 ( struct V_1 * V_2 )
{
int V_42 ;
F_21 ( V_2 , V_6 , V_2 -> V_7 , L_26 ) ;
F_109 ( & V_2 -> V_137 ) ;
V_42 = V_2 -> V_148 -> V_149 ( V_2 ) ;
if ( V_42 )
goto V_150;
V_2 -> V_151 = true ;
F_102 ( V_2 ) ;
V_42 = V_2 -> V_148 -> V_152 ( V_2 ) ;
if ( V_42 && V_42 != - V_153 )
goto V_154;
F_110 ( & V_2 -> V_137 ) ;
return 0 ;
V_154:
V_2 -> V_148 -> V_155 ( V_2 ) ;
V_150:
F_110 ( & V_2 -> V_137 ) ;
return V_42 ;
}
static void F_115 ( struct V_1 * V_2 )
{
F_21 ( V_2 , V_45 , V_2 -> V_7 , L_27 ) ;
F_71 ( V_2 -> V_101 ) ;
F_109 ( & V_2 -> V_137 ) ;
V_2 -> V_101 = true ;
F_102 ( V_2 ) ;
F_110 ( & V_2 -> V_137 ) ;
}
static void F_116 ( struct V_1 * V_2 )
{
F_21 ( V_2 , V_156 , V_2 -> V_7 , L_28 ) ;
F_70 ( V_2 ) ;
F_109 ( & V_2 -> V_137 ) ;
V_2 -> V_101 = false ;
F_110 ( & V_2 -> V_137 ) ;
F_117 ( V_2 -> V_7 ) ;
F_118 ( V_2 -> V_7 ) ;
F_119 ( & V_2 -> V_157 ) ;
F_120 ( V_2 ) ;
F_121 ( & V_2 -> V_142 ) ;
}
static void F_122 ( struct V_1 * V_2 )
{
F_21 ( V_2 , V_6 , V_2 -> V_7 , L_29 ) ;
if ( ! V_2 -> V_151 )
return;
V_2 -> V_148 -> V_155 ( V_2 ) ;
V_2 -> V_151 = false ;
V_2 -> V_120 . V_121 = false ;
F_94 ( V_2 ) ;
}
static void F_123 ( struct V_1 * V_2 )
{
F_21 ( V_2 , V_6 , V_2 -> V_7 , L_30 ) ;
V_2 -> type -> V_158 ( V_2 ) ;
}
static bool F_124 ( struct V_1 * V_159 , struct V_1 * V_160 )
{
return V_159 -> type == V_160 -> type &&
V_159 -> V_161 && V_160 -> V_161 &&
! strcmp ( V_159 -> V_161 , V_160 -> V_161 ) ;
}
static void F_125 ( struct V_1 * V_2 )
{
struct V_1 * V_162 , * V_163 ;
if ( V_2 -> V_164 == V_2 ) {
F_21 ( V_2 , V_36 , V_2 -> V_7 , L_31 ) ;
F_126 ( & V_2 -> V_165 , & V_166 ) ;
F_127 (other, next, &ef4_unassociated_list,
node) {
if ( F_124 ( V_2 , V_162 ) ) {
F_128 ( & V_162 -> V_165 ) ;
F_21 ( V_162 , V_36 , V_162 -> V_7 ,
L_32 ,
F_129 ( V_2 -> V_167 ) ,
V_2 -> V_7 -> V_68 ) ;
F_126 ( & V_162 -> V_165 ,
& V_2 -> V_168 ) ;
V_162 -> V_164 = V_2 ;
}
}
} else {
F_130 (other, &ef4_primary_list, node) {
if ( F_124 ( V_2 , V_162 ) ) {
F_21 ( V_2 , V_36 , V_2 -> V_7 ,
L_33 ,
F_129 ( V_162 -> V_167 ) ,
V_162 -> V_7 -> V_68 ) ;
F_126 ( & V_2 -> V_165 ,
& V_162 -> V_168 ) ;
V_2 -> V_164 = V_162 ;
return;
}
}
F_21 ( V_2 , V_36 , V_2 -> V_7 ,
L_34 ) ;
F_126 ( & V_2 -> V_165 , & V_169 ) ;
}
}
static void F_131 ( struct V_1 * V_2 )
{
struct V_1 * V_162 , * V_163 ;
F_128 ( & V_2 -> V_165 ) ;
V_2 -> V_164 = NULL ;
F_127 (other, next, &efx->secondary_list, node) {
F_128 ( & V_162 -> V_165 ) ;
F_21 ( V_162 , V_36 , V_162 -> V_7 ,
L_35 ) ;
F_126 ( & V_162 -> V_165 , & V_169 ) ;
V_162 -> V_164 = NULL ;
}
}
static int F_132 ( struct V_1 * V_2 )
{
struct V_167 * V_167 = V_2 -> V_167 ;
T_5 V_170 = V_2 -> type -> V_171 ;
unsigned int V_172 = V_2 -> type -> V_172 ( V_2 ) ;
int V_42 , V_173 ;
F_21 ( V_2 , V_36 , V_2 -> V_7 , L_36 ) ;
V_173 = V_2 -> type -> V_174 ;
V_42 = F_133 ( V_167 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 ,
L_37 ) ;
goto V_150;
}
F_134 ( V_167 ) ;
while ( V_170 > 0x7fffffffUL ) {
V_42 = F_135 ( & V_167 -> V_175 , V_170 ) ;
if ( V_42 == 0 )
break;
V_170 >>= 1 ;
}
if ( V_42 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 ,
L_38 ) ;
goto V_154;
}
F_21 ( V_2 , V_36 , V_2 -> V_7 ,
L_39 , ( unsigned long long ) V_170 ) ;
V_2 -> V_176 = F_136 ( V_2 -> V_167 , V_173 ) ;
V_42 = F_137 ( V_167 , V_173 , L_40 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 ,
L_41 ) ;
V_42 = - V_8 ;
goto V_177;
}
V_2 -> V_178 = F_138 ( V_2 -> V_176 , V_172 ) ;
if ( ! V_2 -> V_178 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 ,
L_42 ,
( unsigned long long ) V_2 -> V_176 , V_172 ) ;
V_42 = - V_114 ;
goto V_179;
}
F_21 ( V_2 , V_36 , V_2 -> V_7 ,
L_43 ,
( unsigned long long ) V_2 -> V_176 , V_172 ,
V_2 -> V_178 ) ;
return 0 ;
V_179:
F_139 ( V_2 -> V_167 , V_173 ) ;
V_177:
V_2 -> V_176 = 0 ;
V_154:
F_140 ( V_2 -> V_167 ) ;
V_150:
return V_42 ;
}
static void F_141 ( struct V_1 * V_2 )
{
int V_173 ;
F_21 ( V_2 , V_6 , V_2 -> V_7 , L_44 ) ;
if ( V_2 -> V_178 ) {
F_142 ( V_2 -> V_178 ) ;
V_2 -> V_178 = NULL ;
}
if ( V_2 -> V_176 ) {
V_173 = V_2 -> type -> V_174 ;
F_139 ( V_2 -> V_167 , V_173 ) ;
V_2 -> V_176 = 0 ;
}
if ( ! F_143 ( V_2 -> V_167 ) )
F_140 ( V_2 -> V_167 ) ;
}
void F_144 ( struct V_1 * V_2 )
{
T_1 V_46 ;
for ( V_46 = 0 ; V_46 < F_145 ( V_2 -> V_180 ) ; V_46 ++ )
V_2 -> V_180 [ V_46 ] =
F_146 ( V_46 , V_2 -> V_181 ) ;
}
static unsigned int F_147 ( struct V_1 * V_2 )
{
T_6 V_182 ;
unsigned int V_183 ;
int V_184 ;
if ( V_185 ) {
V_183 = V_185 ;
} else {
if ( F_4 ( ! F_148 ( & V_182 , V_49 ) ) ) {
F_149 ( V_2 , V_36 , V_2 -> V_7 ,
L_45 ) ;
return 1 ;
}
V_183 = 0 ;
F_150 (cpu) {
if ( ! F_151 ( V_184 , V_182 ) ) {
++ V_183 ;
F_152 ( V_182 , V_182 ,
F_153 ( V_184 ) ) ;
}
}
F_154 ( V_182 ) ;
}
if ( V_183 > V_186 ) {
F_155 ( V_2 , V_36 , V_2 -> V_7 , ! V_185 , V_187 ,
L_46 ,
V_183 , V_186 ) ;
V_183 = V_186 ;
}
return V_183 ;
}
static int F_156 ( struct V_1 * V_2 )
{
unsigned int V_188 = 0 ;
unsigned int V_46 , V_48 ;
int V_42 ;
for ( V_46 = 0 ; V_46 < V_189 ; V_46 ++ )
if ( V_2 -> V_190 [ V_46 ] )
++ V_188 ;
if ( V_2 -> V_191 == V_192 ) {
struct V_193 V_194 [ V_107 ] ;
unsigned int V_113 ;
V_113 = F_147 ( V_2 ) ;
if ( V_195 )
V_113 *= 2 ;
V_113 += V_188 ;
V_113 = F_157 ( V_113 , V_2 -> V_196 ) ;
for ( V_46 = 0 ; V_46 < V_113 ; V_46 ++ )
V_194 [ V_46 ] . V_197 = V_46 ;
V_42 = F_158 ( V_2 -> V_167 ,
V_194 , 1 , V_113 ) ;
if ( V_42 < 0 ) {
V_2 -> V_191 = V_198 ;
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_47 ) ;
} else if ( V_42 < V_113 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_48
L_49 , V_42 , V_113 ) ;
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_50 ) ;
V_113 = V_42 ;
}
if ( V_42 > 0 ) {
V_2 -> V_113 = V_113 ;
if ( V_113 > V_188 )
V_113 -= V_188 ;
if ( V_195 ) {
V_2 -> V_199 = F_157 ( F_24 ( V_113 / 2 ,
1U ) ,
V_2 -> V_200 ) ;
V_2 -> V_201 = F_24 ( V_113 -
V_2 -> V_199 ,
1U ) ;
} else {
V_2 -> V_199 = F_157 ( V_113 ,
V_2 -> V_200 ) ;
V_2 -> V_201 = V_113 ;
}
for ( V_46 = 0 ; V_46 < V_2 -> V_113 ; V_46 ++ )
F_159 ( V_2 , V_46 ) -> V_202 =
V_194 [ V_46 ] . V_203 ;
}
}
if ( V_2 -> V_191 == V_198 ) {
V_2 -> V_113 = 1 ;
V_2 -> V_201 = 1 ;
V_2 -> V_199 = 1 ;
V_42 = F_160 ( V_2 -> V_167 ) ;
if ( V_42 == 0 ) {
F_159 ( V_2 , 0 ) -> V_202 = V_2 -> V_167 -> V_202 ;
} else {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_51 ) ;
V_2 -> V_191 = V_204 ;
}
}
if ( V_2 -> V_191 == V_204 ) {
V_2 -> V_113 = 1 + ( V_195 ? 1 : 0 ) ;
V_2 -> V_201 = 1 ;
V_2 -> V_199 = 1 ;
V_2 -> V_205 = V_2 -> V_167 -> V_202 ;
}
V_48 = V_2 -> V_113 ;
for ( V_46 = 0 ; V_46 < V_189 ; V_46 ++ ) {
if ( ! V_2 -> V_190 [ V_46 ] )
continue;
if ( V_2 -> V_191 != V_192 ||
V_2 -> V_113 <= V_188 ) {
V_2 -> V_190 [ V_46 ] -> F_161 ( V_2 ) ;
} else {
-- V_48 ;
F_159 ( V_2 , V_48 ) -> type =
V_2 -> V_190 [ V_46 ] ;
}
}
V_2 -> V_181 = V_2 -> V_201 ;
return 0 ;
}
static int F_86 ( struct V_1 * V_2 )
{
struct V_9 * V_10 , * V_206 ;
int V_42 ;
F_71 ( V_2 -> V_3 == V_4 ) ;
V_2 -> V_207 = true ;
F_30 () ;
F_51 (channel, efx) {
if ( ! V_10 -> type -> V_208 ) {
V_42 = F_26 ( V_10 ) ;
if ( V_42 )
goto V_63;
}
F_29 ( V_10 ) ;
}
return 0 ;
V_63:
V_206 = V_10 ;
F_51 (channel, efx) {
if ( V_10 == V_206 )
break;
F_32 ( V_10 ) ;
if ( ! V_10 -> type -> V_208 )
F_34 ( V_10 ) ;
}
return V_42 ;
}
static void F_82 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
if ( V_2 -> V_3 == V_4 )
return;
V_2 -> V_207 = false ;
F_30 () ;
if ( V_2 -> V_205 )
F_162 ( V_2 -> V_205 ) ;
F_51 (channel, efx) {
if ( V_10 -> V_202 )
F_162 ( V_10 -> V_202 ) ;
F_32 ( V_10 ) ;
if ( ! V_10 -> type -> V_208 )
F_34 ( V_10 ) ;
}
}
static int F_163 ( struct V_1 * V_2 )
{
struct V_9 * V_10 , * V_206 ;
int V_42 ;
F_71 ( V_2 -> V_3 == V_4 ) ;
if ( V_2 -> V_209 ) {
F_164 ( V_2 -> V_205 ) ;
V_2 -> V_209 = false ;
}
V_2 -> type -> V_210 ( V_2 ) ;
F_51 (channel, efx) {
if ( V_10 -> type -> V_208 ) {
V_42 = F_26 ( V_10 ) ;
if ( V_42 )
goto V_63;
}
}
V_42 = F_86 ( V_2 ) ;
if ( V_42 )
goto V_63;
return 0 ;
V_63:
V_206 = V_10 ;
F_51 (channel, efx) {
if ( V_10 == V_206 )
break;
if ( V_10 -> type -> V_208 )
F_34 ( V_10 ) ;
}
V_2 -> type -> V_211 ( V_2 ) ;
return V_42 ;
}
static void F_165 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_82 ( V_2 ) ;
F_51 (channel, efx) {
if ( V_10 -> type -> V_208 )
F_34 ( V_10 ) ;
}
V_2 -> type -> V_211 ( V_2 ) ;
}
static void F_166 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_51 (channel, efx)
V_10 -> V_202 = 0 ;
F_167 ( V_2 -> V_167 ) ;
F_168 ( V_2 -> V_167 ) ;
V_2 -> V_205 = 0 ;
}
static void F_169 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_12 * V_13 ;
V_2 -> V_67 =
V_195 ?
V_2 -> V_113 - V_2 -> V_199 : 0 ;
F_51 (channel, efx) {
if ( V_10 -> V_10 < V_2 -> V_201 )
V_10 -> V_19 . V_212 = V_10 -> V_10 ;
else
V_10 -> V_19 . V_212 = - 1 ;
F_5 (tx_queue, channel)
V_13 -> V_52 -= ( V_2 -> V_67 *
V_51 ) ;
}
}
static int F_170 ( struct V_1 * V_2 )
{
int V_42 ;
F_21 ( V_2 , V_36 , V_2 -> V_7 , L_52 ) ;
V_42 = V_2 -> type -> V_36 ( V_2 ) ;
if ( V_42 )
return V_42 ;
do {
if ( ! V_2 -> V_196 || ! V_2 -> V_200 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_53
L_54 ) ;
V_42 = - V_213 ;
goto V_150;
}
V_42 = F_156 ( V_2 ) ;
if ( V_42 )
goto V_150;
F_169 ( V_2 ) ;
V_42 = V_2 -> type -> V_214 ( V_2 ) ;
if ( V_42 != 0 && V_42 != - V_215 )
goto V_154;
if ( V_42 == - V_215 )
F_166 ( V_2 ) ;
} while ( V_42 == - V_215 );
if ( V_2 -> V_113 > 1 )
F_171 ( & V_2 -> V_216 ,
sizeof( V_2 -> V_216 ) ) ;
F_144 ( V_2 ) ;
F_172 ( V_2 -> V_7 , V_2 -> V_199 ) ;
F_173 ( V_2 -> V_7 , V_2 -> V_201 ) ;
V_2 -> V_22 = F_174 ( V_2 -> V_217 , 1000 ) ;
F_175 ( V_2 , V_218 , V_219 , true ,
true ) ;
return 0 ;
V_154:
F_166 ( V_2 ) ;
V_150:
V_2 -> type -> remove ( V_2 ) ;
return V_42 ;
}
static void F_176 ( struct V_1 * V_2 )
{
F_21 ( V_2 , V_6 , V_2 -> V_7 , L_55 ) ;
F_166 ( V_2 ) ;
V_2 -> type -> remove ( V_2 ) ;
}
static int F_177 ( struct V_1 * V_2 )
{
int V_42 ;
F_178 ( & V_2 -> V_220 ) ;
F_179 ( & V_2 -> V_133 ) ;
F_109 ( & V_2 -> V_137 ) ;
F_180 ( & V_2 -> V_133 ) ;
V_42 = V_2 -> type -> V_221 ( V_2 ) ;
if ( V_42 )
goto V_222;
#ifdef F_181
if ( V_2 -> type -> V_223 & V_224 ) {
struct V_9 * V_10 ;
int V_46 , V_225 = 1 ;
F_51 (channel, efx) {
V_10 -> V_226 =
F_182 ( V_2 -> type -> V_227 ,
sizeof( * V_10 -> V_226 ) ,
V_49 ) ;
if ( ! V_10 -> V_226 )
V_225 = 0 ;
else
for ( V_46 = 0 ;
V_46 < V_2 -> type -> V_227 ;
++ V_46 )
V_10 -> V_226 [ V_46 ] =
V_228 ;
}
if ( ! V_225 ) {
F_51 (channel, efx)
F_85 ( V_10 -> V_226 ) ;
V_2 -> type -> V_229 ( V_2 ) ;
V_42 = - V_114 ;
goto V_222;
}
V_2 -> V_230 = V_2 -> V_231 = 0 ;
}
#endif
V_222:
F_183 ( & V_2 -> V_133 ) ;
F_110 ( & V_2 -> V_137 ) ;
return V_42 ;
}
static void F_184 ( struct V_1 * V_2 )
{
#ifdef F_181
struct V_9 * V_10 ;
F_51 (channel, efx)
F_85 ( V_10 -> V_226 ) ;
#endif
F_180 ( & V_2 -> V_133 ) ;
V_2 -> type -> V_229 ( V_2 ) ;
F_183 ( & V_2 -> V_133 ) ;
}
static void F_185 ( struct V_1 * V_2 )
{
F_103 ( & V_2 -> V_133 ) ;
V_2 -> type -> V_232 ( V_2 ) ;
F_104 ( & V_2 -> V_133 ) ;
}
static int F_186 ( struct V_1 * V_2 )
{
int V_42 ;
V_42 = F_170 ( V_2 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 , L_56 ) ;
goto V_150;
}
V_42 = F_112 ( V_2 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 , L_57 ) ;
goto V_154;
}
F_57 ( V_233 < V_234 ) ;
if ( F_66 ( V_233 < F_187 ( V_2 ) ) ) {
V_42 = - V_235 ;
goto V_177;
}
V_2 -> V_37 = V_2 -> V_38 = V_233 ;
V_42 = F_177 ( V_2 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 ,
L_58 ) ;
goto V_179;
}
V_42 = F_52 ( V_2 ) ;
if ( V_42 )
goto V_236;
return 0 ;
V_236:
F_184 ( V_2 ) ;
V_179:
V_177:
F_123 ( V_2 ) ;
V_154:
F_176 ( V_2 ) ;
V_150:
return V_42 ;
}
static void F_87 ( struct V_1 * V_2 )
{
F_70 ( V_2 ) ;
F_71 ( V_2 -> V_3 == V_4 ) ;
if ( V_2 -> V_101 || ! F_95 ( V_2 -> V_7 ) ||
V_2 -> V_237 )
return;
F_115 ( V_2 ) ;
F_55 ( V_2 ) ;
if ( V_2 -> type -> V_238 != NULL )
F_188 ( V_2 -> V_239 , & V_2 -> V_157 ,
V_240 ) ;
V_2 -> type -> V_241 ( V_2 ) ;
V_2 -> type -> V_242 ( V_2 ) ;
F_189 ( & V_2 -> V_243 ) ;
V_2 -> type -> V_244 ( V_2 , NULL , NULL ) ;
F_190 ( & V_2 -> V_243 ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
F_70 ( V_2 ) ;
if ( ! V_2 -> V_101 )
return;
V_2 -> type -> V_242 ( V_2 ) ;
F_189 ( & V_2 -> V_243 ) ;
V_2 -> type -> V_244 ( V_2 , NULL , NULL ) ;
F_190 ( & V_2 -> V_243 ) ;
V_2 -> type -> V_245 ( V_2 ) ;
F_116 ( V_2 ) ;
F_66 ( F_95 ( V_2 -> V_7 ) &&
F_67 ( V_2 -> V_7 ) ) ;
F_191 ( V_2 -> V_7 ) ;
F_69 ( V_2 ) ;
}
static void F_192 ( struct V_1 * V_2 )
{
F_54 ( V_2 ) ;
F_184 ( V_2 ) ;
F_123 ( V_2 ) ;
F_176 ( V_2 ) ;
}
unsigned int F_193 ( struct V_1 * V_2 , unsigned int V_246 )
{
if ( V_246 == 0 )
return 0 ;
if ( V_246 * 1000 < V_2 -> V_217 )
return 1 ;
return V_246 * 1000 / V_2 -> V_217 ;
}
unsigned int F_194 ( struct V_1 * V_2 , unsigned int V_247 )
{
return F_174 ( V_247 * V_2 -> V_217 , 1000 ) ;
}
int F_175 ( struct V_1 * V_2 , unsigned int V_248 ,
unsigned int V_249 , bool V_250 ,
bool V_251 )
{
struct V_9 * V_10 ;
unsigned int V_252 ;
F_70 ( V_2 ) ;
V_252 = V_2 -> V_253 / 1000 ;
if ( V_248 > V_252 || V_249 > V_252 )
return - V_235 ;
if ( V_248 != V_249 && V_2 -> V_67 == 0 &&
! V_251 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_59
L_60 ) ;
return - V_235 ;
}
V_2 -> V_34 = V_250 ;
V_2 -> V_28 = V_249 ;
F_51 (channel, efx) {
if ( F_7 ( V_10 ) )
V_10 -> V_25 = V_249 ;
else if ( F_195 ( V_10 ) )
V_10 -> V_25 = V_248 ;
}
return 0 ;
}
void F_196 ( struct V_1 * V_2 , unsigned int * V_248 ,
unsigned int * V_249 , bool * V_250 )
{
* V_250 = V_2 -> V_34 ;
* V_249 = V_2 -> V_28 ;
if ( V_2 -> V_67 == 0 ) {
* V_248 = * V_249 ;
} else {
struct V_9 * V_254 ;
V_254 = V_2 -> V_10 [ V_2 -> V_67 ] ;
* V_248 = V_254 -> V_25 ;
}
}
static void F_197 ( struct V_140 * V_141 )
{
struct V_1 * V_2 = F_14 ( V_141 , struct V_1 ,
V_157 . V_255 ) ;
F_15 ( V_2 , V_256 , V_2 -> V_7 ,
L_61 ,
F_16 () ) ;
F_71 ( V_2 -> type -> V_238 == NULL ) ;
if ( F_198 ( & V_2 -> V_137 ) ) {
if ( V_2 -> V_101 )
V_2 -> type -> V_238 ( V_2 ) ;
F_110 ( & V_2 -> V_137 ) ;
}
F_188 ( V_2 -> V_239 , & V_2 -> V_157 ,
V_240 ) ;
}
static int F_199 ( struct V_257 * V_7 , struct V_258 * V_259 , int V_260 )
{
struct V_1 * V_2 = F_200 ( V_7 ) ;
struct V_261 * V_141 = F_201 ( V_259 ) ;
if ( ( V_260 == V_262 || V_260 == V_263 ) &&
( V_141 -> V_264 & 0xfc00 ) == 0x0400 )
V_141 -> V_264 ^= V_265 | 0x0400 ;
return F_202 ( & V_2 -> V_266 , V_141 , V_260 ) ;
}
static void F_83 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
V_10 -> V_55 = V_2 -> V_7 ;
F_203 ( V_10 -> V_55 , & V_10 -> V_32 ,
F_13 , V_267 ) ;
}
static void F_204 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_51 (channel, efx)
F_83 ( V_10 ) ;
}
static void F_84 ( struct V_9 * V_10 )
{
if ( V_10 -> V_55 )
F_205 ( & V_10 -> V_32 ) ;
V_10 -> V_55 = NULL ;
}
static void F_206 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_51 (channel, efx)
F_84 ( V_10 ) ;
}
static void F_207 ( struct V_257 * V_7 )
{
struct V_1 * V_2 = F_200 ( V_7 ) ;
struct V_9 * V_10 ;
F_51 (channel, efx)
F_208 ( V_10 ) ;
}
int F_209 ( struct V_257 * V_7 )
{
struct V_1 * V_2 = F_200 ( V_7 ) ;
int V_42 ;
F_21 ( V_2 , V_45 , V_2 -> V_7 , L_62 ,
F_16 () ) ;
V_42 = F_1 ( V_2 ) ;
if ( V_42 )
return V_42 ;
if ( V_2 -> V_136 & V_144 )
return - V_268 ;
F_94 ( V_2 ) ;
F_87 ( V_2 ) ;
F_210 ( V_2 ) ;
return 0 ;
}
int F_211 ( struct V_257 * V_7 )
{
struct V_1 * V_2 = F_200 ( V_7 ) ;
F_21 ( V_2 , V_156 , V_2 -> V_7 , L_63 ,
F_16 () ) ;
F_81 ( V_2 ) ;
return 0 ;
}
static void F_212 ( struct V_257 * V_7 ,
struct V_269 * V_270 )
{
struct V_1 * V_2 = F_200 ( V_7 ) ;
F_189 ( & V_2 -> V_243 ) ;
V_2 -> type -> V_244 ( V_2 , NULL , V_270 ) ;
F_190 ( & V_2 -> V_243 ) ;
}
static void F_213 ( struct V_257 * V_7 )
{
struct V_1 * V_2 = F_200 ( V_7 ) ;
F_2 ( V_2 , V_271 , V_2 -> V_7 ,
L_64 ,
V_2 -> V_101 ) ;
F_73 ( V_2 , V_272 ) ;
}
static int F_214 ( struct V_257 * V_7 , int V_273 )
{
struct V_1 * V_2 = F_200 ( V_7 ) ;
int V_42 ;
V_42 = F_1 ( V_2 ) ;
if ( V_42 )
return V_42 ;
F_21 ( V_2 , V_6 , V_2 -> V_7 , L_65 , V_273 ) ;
F_80 ( V_2 ) ;
F_81 ( V_2 ) ;
F_109 ( & V_2 -> V_137 ) ;
V_7 -> V_79 = V_273 ;
F_102 ( V_2 ) ;
F_110 ( & V_2 -> V_137 ) ;
F_87 ( V_2 ) ;
F_88 ( V_2 -> V_7 ) ;
return 0 ;
}
static int F_215 ( struct V_257 * V_7 , void * V_141 )
{
struct V_1 * V_2 = F_200 ( V_7 ) ;
struct V_274 * V_275 = V_141 ;
T_4 * V_276 = V_275 -> V_277 ;
T_4 V_278 [ 6 ] ;
int V_42 ;
if ( ! F_216 ( V_276 ) ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_66 ,
V_276 ) ;
return - V_279 ;
}
F_113 ( V_278 , V_7 -> V_146 ) ;
F_113 ( V_7 -> V_146 , V_276 ) ;
if ( V_2 -> type -> V_280 ) {
V_42 = V_2 -> type -> V_280 ( V_2 ) ;
if ( V_42 ) {
F_113 ( V_7 -> V_146 , V_278 ) ;
return V_42 ;
}
}
F_109 ( & V_2 -> V_137 ) ;
F_102 ( V_2 ) ;
F_110 ( & V_2 -> V_137 ) ;
return 0 ;
}
static void F_217 ( struct V_257 * V_7 )
{
struct V_1 * V_2 = F_200 ( V_7 ) ;
if ( V_2 -> V_101 )
F_218 ( V_2 -> V_239 , & V_2 -> V_142 ) ;
}
static int F_219 ( struct V_257 * V_7 , T_2 V_141 )
{
struct V_1 * V_2 = F_200 ( V_7 ) ;
int V_42 ;
if ( V_7 -> V_73 & ~ V_141 & V_224 ) {
V_42 = V_2 -> type -> V_281 ( V_2 , V_282 ) ;
if ( V_42 )
return V_42 ;
}
if ( ( V_7 -> V_73 ^ V_141 ) & V_283 ) {
F_217 ( V_7 ) ;
}
return 0 ;
}
static void F_220 ( struct V_1 * V_2 )
{
strcpy ( V_2 -> V_68 , V_2 -> V_7 -> V_68 ) ;
F_221 ( V_2 ) ;
F_50 ( V_2 ) ;
}
static int F_222 ( struct V_284 * V_285 ,
unsigned long V_286 , void * V_287 )
{
struct V_257 * V_7 = F_223 ( V_287 ) ;
if ( ( V_7 -> V_288 == & V_289 ) &&
V_286 == V_290 )
F_220 ( F_200 ( V_7 ) ) ;
return V_291 ;
}
static T_7
F_224 ( struct V_292 * V_175 , struct V_293 * V_294 , char * V_64 )
{
struct V_1 * V_2 = F_225 ( F_226 ( V_175 ) ) ;
return sprintf ( V_64 , L_67 , V_2 -> V_295 ) ;
}
static int F_227 ( struct V_1 * V_2 )
{
struct V_257 * V_7 = V_2 -> V_7 ;
struct V_9 * V_10 ;
int V_42 ;
V_7 -> V_296 = 5 * V_297 ;
V_7 -> V_202 = V_2 -> V_167 -> V_202 ;
V_7 -> V_288 = & V_289 ;
V_7 -> V_298 = & V_299 ;
V_7 -> V_300 = V_301 ;
V_7 -> V_302 = V_303 ;
V_7 -> V_304 = V_305 ;
F_228 () ;
V_2 -> V_3 = V_306 ;
F_229 () ;
if ( V_2 -> V_237 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 ,
L_68 ) ;
V_42 = - V_8 ;
goto V_307;
}
V_42 = F_230 ( V_7 , V_7 -> V_68 ) ;
if ( V_42 < 0 )
goto V_307;
F_220 ( V_2 ) ;
F_98 ( V_7 ) ;
V_42 = F_231 ( V_7 ) ;
if ( V_42 )
goto V_307;
F_51 (channel, efx) {
struct V_12 * V_13 ;
F_5 (tx_queue, channel)
F_232 ( V_13 ) ;
}
F_125 ( V_2 ) ;
F_233 () ;
V_42 = F_234 ( & V_2 -> V_167 -> V_175 , & V_308 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_69 ) ;
goto V_309;
}
return 0 ;
V_309:
F_228 () ;
F_131 ( V_2 ) ;
F_235 ( V_7 ) ;
V_307:
V_2 -> V_3 = V_310 ;
F_233 () ;
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_70 ) ;
return V_42 ;
}
static void F_236 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_7 )
return;
F_71 ( F_200 ( V_2 -> V_7 ) != V_2 ) ;
if ( F_237 ( V_2 ) ) {
F_238 ( V_2 -> V_68 , F_129 ( V_2 -> V_167 ) , sizeof( V_2 -> V_68 ) ) ;
F_239 ( & V_2 -> V_167 -> V_175 , & V_308 ) ;
F_240 ( V_2 -> V_7 ) ;
}
}
void F_241 ( struct V_1 * V_2 , enum V_311 V_312 )
{
F_70 ( V_2 ) ;
F_81 ( V_2 ) ;
F_165 ( V_2 ) ;
F_109 ( & V_2 -> V_137 ) ;
if ( V_2 -> V_151 && V_312 != V_313 &&
V_312 != V_314 )
V_2 -> V_148 -> V_155 ( V_2 ) ;
V_2 -> type -> V_155 ( V_2 ) ;
}
int F_242 ( struct V_1 * V_2 , enum V_311 V_312 , bool V_315 )
{
int V_42 ;
F_70 ( V_2 ) ;
V_42 = V_2 -> type -> V_149 ( V_2 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_71 ) ;
goto V_63;
}
if ( ! V_315 )
goto V_63;
if ( V_2 -> V_151 && V_312 != V_313 &&
V_312 != V_314 ) {
V_42 = V_2 -> V_148 -> V_149 ( V_2 ) ;
if ( V_42 )
goto V_63;
V_42 = V_2 -> V_148 -> V_152 ( V_2 ) ;
if ( V_42 && V_42 != - V_153 )
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_72 ) ;
}
V_42 = F_163 ( V_2 ) ;
if ( V_42 )
goto V_63;
F_103 ( & V_2 -> V_133 ) ;
F_185 ( V_2 ) ;
F_104 ( & V_2 -> V_133 ) ;
F_110 ( & V_2 -> V_137 ) ;
F_87 ( V_2 ) ;
return 0 ;
V_63:
V_2 -> V_151 = false ;
F_110 ( & V_2 -> V_137 ) ;
return V_42 ;
}
int F_243 ( struct V_1 * V_2 , enum V_311 V_312 )
{
int V_42 , V_110 ;
bool V_316 ;
F_99 ( V_2 , V_6 , V_2 -> V_7 , L_73 ,
F_244 ( V_312 ) ) ;
F_80 ( V_2 ) ;
F_241 ( V_2 , V_312 ) ;
V_42 = V_2 -> type -> V_317 ( V_2 , V_312 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_74 ) ;
goto V_115;
}
if ( V_312 < V_318 )
V_2 -> V_237 &= - ( 1 << ( V_312 + 1 ) ) ;
else
F_245 ( V_312 , & V_2 -> V_237 ) ;
F_134 ( V_2 -> V_167 ) ;
V_115:
V_316 = V_42 ||
V_312 == V_117 ||
V_312 == V_319 ;
V_110 = F_242 ( V_2 , V_312 , ! V_316 ) ;
if ( V_110 ) {
V_316 = true ;
if ( ! V_42 )
V_42 = V_110 ;
}
if ( V_316 ) {
F_246 ( V_2 -> V_7 ) ;
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_75 ) ;
V_2 -> V_3 = V_4 ;
} else {
F_21 ( V_2 , V_6 , V_2 -> V_7 , L_76 ) ;
F_88 ( V_2 -> V_7 ) ;
}
return V_42 ;
}
int F_247 ( struct V_1 * V_2 )
{
#ifdef F_248
struct V_320 * V_321 = F_249 ( V_2 -> V_167 ) ;
if ( F_250 ( V_321 ) ) {
return 1 ;
}
#endif
return 0 ;
}
static void F_251 ( struct V_140 * V_141 )
{
struct V_1 * V_2 = F_14 ( V_141 , struct V_1 , V_322 ) ;
unsigned long V_323 ;
enum V_311 V_312 ;
V_323 = F_252 ( V_2 -> V_237 ) ;
V_312 = F_253 ( V_323 ) - 1 ;
if ( ( V_312 == V_319 ||
V_312 == V_324 ) &&
F_247 ( V_2 ) )
return;
if ( ! V_323 )
return;
F_228 () ;
if ( V_2 -> V_3 == V_306 )
( void ) F_243 ( V_2 , V_312 ) ;
F_233 () ;
}
void F_73 ( struct V_1 * V_2 , enum V_311 type )
{
enum V_311 V_312 ;
if ( V_2 -> V_3 == V_5 ) {
F_21 ( V_2 , V_6 , V_2 -> V_7 ,
L_77 ,
F_244 ( type ) ) ;
return;
}
switch ( type ) {
case V_313 :
case V_104 :
case V_324 :
case V_325 :
case V_117 :
case V_319 :
case V_314 :
V_312 = type ;
F_21 ( V_2 , V_6 , V_2 -> V_7 , L_78 ,
F_244 ( V_312 ) ) ;
break;
default:
V_312 = V_2 -> type -> V_326 ( type ) ;
F_21 ( V_2 , V_6 , V_2 -> V_7 ,
L_79 ,
F_244 ( V_312 ) , F_244 ( type ) ) ;
break;
}
F_254 ( V_312 , & V_2 -> V_237 ) ;
F_229 () ;
if ( F_252 ( V_2 -> V_3 ) != V_306 )
return;
F_218 ( V_327 , & V_2 -> V_322 ) ;
}
int F_255 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_256 ( struct V_1 * V_2 ) {}
static bool F_257 ( struct V_1 * V_2 )
{
return false ;
}
static int F_258 ( struct V_1 * V_2 ,
struct V_167 * V_167 , struct V_257 * V_7 )
{
int V_46 ;
F_259 ( & V_2 -> V_165 ) ;
F_259 ( & V_2 -> V_168 ) ;
F_178 ( & V_2 -> V_328 ) ;
#ifdef F_260
F_259 ( & V_2 -> V_329 ) ;
#endif
F_261 ( & V_2 -> V_322 , F_251 ) ;
F_262 ( & V_2 -> V_157 , F_197 ) ;
F_262 ( & V_2 -> V_330 , V_331 ) ;
V_2 -> V_167 = V_167 ;
V_2 -> V_332 = V_333 ;
V_2 -> V_3 = V_310 ;
F_238 ( V_2 -> V_68 , F_129 ( V_167 ) , sizeof( V_2 -> V_68 ) ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_78 = V_2 -> type -> V_78 ;
V_2 -> V_82 =
V_89 ? ( V_2 -> V_78 + V_89 ) % 4 : 0 ;
V_2 -> V_334 =
V_2 -> type -> V_335 - V_2 -> type -> V_78 ;
V_2 -> V_336 =
V_2 -> type -> V_337 - V_2 -> type -> V_78 ;
F_178 ( & V_2 -> V_243 ) ;
F_263 ( & V_2 -> V_137 ) ;
V_2 -> V_148 = & V_338 ;
V_2 -> V_266 . V_175 = V_7 ;
F_261 ( & V_2 -> V_142 , F_111 ) ;
F_264 ( & V_2 -> V_339 ) ;
for ( V_46 = 0 ; V_46 < V_107 ; V_46 ++ ) {
V_2 -> V_10 [ V_46 ] = F_38 ( V_2 , V_46 , NULL ) ;
if ( ! V_2 -> V_10 [ V_46 ] )
goto V_63;
V_2 -> V_70 [ V_46 ] . V_2 = V_2 ;
V_2 -> V_70 [ V_46 ] . V_112 = V_46 ;
}
V_2 -> V_191 = F_24 ( V_2 -> type -> V_340 ,
V_191 ) ;
snprintf ( V_2 -> V_341 , sizeof( V_2 -> V_341 ) , L_80 ,
F_129 ( V_167 ) ) ;
V_2 -> V_239 = F_265 ( V_2 -> V_341 ) ;
if ( ! V_2 -> V_239 )
goto V_63;
return 0 ;
V_63:
F_266 ( V_2 ) ;
return - V_114 ;
}
static void F_266 ( struct V_1 * V_2 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_107 ; V_46 ++ )
F_85 ( V_2 -> V_10 [ V_46 ] ) ;
F_85 ( V_2 -> V_161 ) ;
if ( V_2 -> V_239 ) {
F_267 ( V_2 -> V_239 ) ;
V_2 -> V_239 = NULL ;
}
}
void F_268 ( struct V_1 * V_2 , T_8 * V_270 )
{
T_8 V_342 = 0 ;
struct V_9 * V_10 ;
F_51 (channel, efx)
V_342 += V_10 -> V_342 ;
V_270 [ V_343 ] = V_342 ;
V_270 [ V_344 ] = F_269 ( & V_2 -> V_345 ) ;
}
static void F_270 ( struct V_1 * V_2 )
{
F_71 ( V_2 -> V_3 == V_306 ) ;
F_121 ( & V_2 -> V_322 ) ;
F_165 ( V_2 ) ;
F_271 ( V_2 ) ;
F_122 ( V_2 ) ;
V_2 -> type -> V_155 ( V_2 ) ;
F_206 ( V_2 ) ;
F_192 ( V_2 ) ;
}
static void F_272 ( struct V_167 * V_167 )
{
struct V_1 * V_2 ;
V_2 = F_225 ( V_167 ) ;
if ( ! V_2 )
return;
F_228 () ;
F_131 ( V_2 ) ;
F_246 ( V_2 -> V_7 ) ;
F_165 ( V_2 ) ;
V_2 -> V_3 = V_310 ;
F_233 () ;
F_236 ( V_2 ) ;
F_273 ( V_2 ) ;
F_270 ( V_2 ) ;
F_141 ( V_2 ) ;
F_21 ( V_2 , V_6 , V_2 -> V_7 , L_81 ) ;
F_266 ( V_2 ) ;
F_274 ( V_2 -> V_7 ) ;
F_275 ( V_167 ) ;
}
static void F_276 ( struct V_1 * V_2 )
{
struct V_167 * V_175 = V_2 -> V_167 ;
char V_346 [ V_347 ] ;
T_7 V_348 ;
int V_349 , V_350 , V_46 , V_48 ;
V_348 = F_277 ( V_175 , 0 , sizeof( V_346 ) , V_346 ) ;
if ( V_348 <= 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_82 ) ;
return;
}
V_349 = F_278 ( V_346 , 0 , V_348 , V_351 ) ;
if ( V_349 < 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_83 ) ;
return;
}
V_350 = F_279 ( & V_346 [ V_349 ] ) ;
V_48 = V_350 ;
V_46 = V_349 + V_352 ;
if ( V_46 + V_48 > V_348 )
V_48 = V_348 - V_46 ;
V_46 = F_280 ( V_346 , V_46 , V_48 , L_84 ) ;
if ( V_46 < 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_85 ) ;
return;
}
V_48 = F_281 ( & V_346 [ V_46 ] ) ;
V_46 += V_353 ;
if ( V_46 + V_48 > V_348 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_86 ) ;
return;
}
F_99 ( V_2 , V_6 , V_2 -> V_7 ,
L_87 , V_48 , & V_346 [ V_46 ] ) ;
V_46 = V_349 + V_352 ;
V_48 = V_350 ;
V_46 = F_280 ( V_346 , V_46 , V_48 , L_88 ) ;
if ( V_46 < 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_89 ) ;
return;
}
V_48 = F_281 ( & V_346 [ V_46 ] ) ;
V_46 += V_353 ;
if ( V_46 + V_48 > V_348 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_90 ) ;
return;
}
V_2 -> V_161 = F_42 ( V_48 + 1 , V_49 ) ;
if ( ! V_2 -> V_161 )
return;
snprintf ( V_2 -> V_161 , V_48 + 1 , L_91 , & V_346 [ V_46 ] ) ;
}
static int F_282 ( struct V_1 * V_2 )
{
int V_42 ;
V_42 = F_186 ( V_2 ) ;
if ( V_42 )
goto V_150;
F_204 ( V_2 ) ;
V_42 = V_2 -> type -> V_149 ( V_2 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 ,
L_71 ) ;
goto V_177;
}
V_42 = F_114 ( V_2 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 ,
L_92 ) ;
goto V_179;
}
V_42 = F_283 ( V_2 ) ;
if ( V_42 )
goto V_236;
V_42 = F_163 ( V_2 ) ;
if ( V_42 )
goto V_354;
return 0 ;
V_354:
F_271 ( V_2 ) ;
V_236:
F_122 ( V_2 ) ;
V_179:
V_2 -> type -> V_155 ( V_2 ) ;
V_177:
F_206 ( V_2 ) ;
F_192 ( V_2 ) ;
V_150:
return V_42 ;
}
static int F_284 ( struct V_167 * V_167 ,
const struct V_355 * V_197 )
{
struct V_257 * V_7 ;
struct V_1 * V_2 ;
int V_42 ;
V_7 = F_285 ( sizeof( * V_2 ) , V_356 ,
V_186 ) ;
if ( ! V_7 )
return - V_114 ;
V_2 = F_200 ( V_7 ) ;
V_2 -> type = ( const struct V_357 * ) V_197 -> V_358 ;
V_2 -> V_95 |= V_359 ;
F_286 ( V_167 , V_2 ) ;
F_287 ( V_7 , & V_167 -> V_175 ) ;
V_42 = F_258 ( V_2 , V_167 , V_7 ) ;
if ( V_42 )
goto V_150;
F_99 ( V_2 , V_36 , V_2 -> V_7 ,
L_93 ) ;
F_276 ( V_2 ) ;
V_42 = F_132 ( V_2 ) ;
if ( V_42 )
goto V_154;
V_42 = F_282 ( V_2 ) ;
if ( V_42 )
goto V_177;
V_7 -> V_73 |= ( V_2 -> type -> V_223 | V_360 |
V_361 ) ;
V_7 -> V_362 |= ( V_363 | V_360 |
V_359 | V_361 ) ;
V_7 -> V_94 = V_7 -> V_73 & ~ V_2 -> V_95 ;
V_7 -> V_73 &= ~ V_283 ;
V_7 -> V_73 |= V_2 -> V_95 ;
V_42 = F_227 ( V_2 ) ;
if ( V_42 )
goto V_179;
F_21 ( V_2 , V_36 , V_2 -> V_7 , L_94 ) ;
F_228 () ;
V_42 = F_288 ( V_2 ) ;
F_233 () ;
if ( V_42 && V_42 != - V_153 )
F_149 ( V_2 , V_36 , V_2 -> V_7 ,
L_95 , V_42 ) ;
V_42 = F_289 ( V_167 ) ;
if ( V_42 && V_42 != - V_235 )
F_290 ( V_2 , V_36 , V_2 -> V_7 ,
L_96 ,
V_42 ) ;
return 0 ;
V_179:
F_270 ( V_2 ) ;
V_177:
F_141 ( V_2 ) ;
V_154:
F_266 ( V_2 ) ;
V_150:
F_66 ( V_42 > 0 ) ;
F_21 ( V_2 , V_6 , V_2 -> V_7 , L_97 , V_42 ) ;
F_274 ( V_7 ) ;
return V_42 ;
}
static int F_291 ( struct V_292 * V_175 )
{
struct V_1 * V_2 = F_225 ( F_226 ( V_175 ) ) ;
F_228 () ;
if ( V_2 -> V_3 != V_4 ) {
V_2 -> V_3 = V_310 ;
F_80 ( V_2 ) ;
F_81 ( V_2 ) ;
F_165 ( V_2 ) ;
}
F_233 () ;
return 0 ;
}
static int F_292 ( struct V_292 * V_175 )
{
int V_42 ;
struct V_1 * V_2 = F_225 ( F_226 ( V_175 ) ) ;
F_228 () ;
if ( V_2 -> V_3 != V_4 ) {
V_42 = F_163 ( V_2 ) ;
if ( V_42 )
goto V_63;
F_109 ( & V_2 -> V_137 ) ;
V_2 -> V_148 -> V_152 ( V_2 ) ;
F_110 ( & V_2 -> V_137 ) ;
F_87 ( V_2 ) ;
F_88 ( V_2 -> V_7 ) ;
V_2 -> V_3 = V_306 ;
V_2 -> type -> V_364 ( V_2 ) ;
}
F_233 () ;
F_218 ( V_327 , & V_2 -> V_322 ) ;
return 0 ;
V_63:
F_233 () ;
return V_42 ;
}
static int F_293 ( struct V_292 * V_175 )
{
struct V_167 * V_167 = F_226 ( V_175 ) ;
struct V_1 * V_2 = F_225 ( V_167 ) ;
V_2 -> type -> V_155 ( V_2 ) ;
V_2 -> V_237 = 0 ;
F_294 ( V_167 ) ;
return F_295 ( V_167 , V_365 ) ;
}
static int F_296 ( struct V_292 * V_175 )
{
struct V_167 * V_167 = F_226 ( V_175 ) ;
struct V_1 * V_2 = F_225 ( V_167 ) ;
int V_42 ;
V_42 = F_295 ( V_167 , V_366 ) ;
if ( V_42 )
return V_42 ;
F_297 ( V_167 ) ;
V_42 = F_133 ( V_167 ) ;
if ( V_42 )
return V_42 ;
F_134 ( V_2 -> V_167 ) ;
V_42 = V_2 -> type -> V_317 ( V_2 , V_104 ) ;
if ( V_42 )
return V_42 ;
V_42 = V_2 -> type -> V_149 ( V_2 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_292 ( V_175 ) ;
return V_42 ;
}
static int F_298 ( struct V_292 * V_175 )
{
int V_42 ;
F_291 ( V_175 ) ;
V_42 = F_293 ( V_175 ) ;
if ( V_42 )
F_296 ( V_175 ) ;
return V_42 ;
}
static T_9 F_299 ( struct V_167 * V_367 ,
enum V_368 V_3 )
{
T_9 V_369 = V_370 ;
struct V_1 * V_2 = F_225 ( V_367 ) ;
if ( V_3 == V_371 )
return V_372 ;
F_228 () ;
if ( V_2 -> V_3 != V_4 ) {
V_2 -> V_3 = V_5 ;
V_2 -> V_237 = 0 ;
F_80 ( V_2 ) ;
F_81 ( V_2 ) ;
F_165 ( V_2 ) ;
V_369 = V_373 ;
} else {
V_369 = V_370 ;
}
F_233 () ;
F_140 ( V_367 ) ;
return V_369 ;
}
static T_9 F_300 ( struct V_167 * V_367 )
{
struct V_1 * V_2 = F_225 ( V_367 ) ;
T_9 V_369 = V_370 ;
int V_42 ;
if ( F_133 ( V_367 ) ) {
F_2 ( V_2 , V_374 , V_2 -> V_7 ,
L_98 ) ;
V_369 = V_372 ;
}
V_42 = F_301 ( V_367 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_374 , V_2 -> V_7 ,
L_99 , V_42 ) ;
}
return V_369 ;
}
static void F_302 ( struct V_167 * V_367 )
{
struct V_1 * V_2 = F_225 ( V_367 ) ;
int V_42 ;
F_228 () ;
if ( V_2 -> V_3 == V_4 )
goto V_115;
V_42 = F_243 ( V_2 , V_104 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_374 , V_2 -> V_7 ,
L_100 , V_42 ) ;
} else {
V_2 -> V_3 = V_306 ;
F_21 ( V_2 , V_374 , V_2 -> V_7 ,
L_101 ) ;
}
V_115:
F_233 () ;
}
static int T_10 F_303 ( void )
{
int V_42 ;
F_304 ( V_375 L_102 V_376 L_103 ) ;
V_42 = F_305 ( & V_377 ) ;
if ( V_42 )
goto V_378;
V_327 = F_265 ( L_104 ) ;
if ( ! V_327 ) {
V_42 = - V_114 ;
goto V_379;
}
V_42 = F_306 ( & V_380 ) ;
if ( V_42 < 0 )
goto V_381;
return 0 ;
V_381:
F_267 ( V_327 ) ;
V_379:
F_307 ( & V_377 ) ;
V_378:
return V_42 ;
}
static void T_11 F_308 ( void )
{
F_304 ( V_375 L_105 ) ;
F_309 ( & V_380 ) ;
F_267 ( V_327 ) ;
F_307 ( & V_377 ) ;
}

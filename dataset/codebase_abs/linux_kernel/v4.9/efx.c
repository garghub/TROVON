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
if ( ! F_15 ( V_10 ) )
return V_11 ;
F_16 ( V_2 , V_33 , V_2 -> V_7 ,
L_2 ,
V_10 -> V_10 , F_17 () ) ;
V_14 = F_3 ( V_10 , V_11 ) ;
if ( V_14 < V_11 ) {
if ( F_7 ( V_10 ) &&
V_2 -> V_34 &&
F_4 ( ++ V_10 -> V_29 == 1000 ) ) {
F_12 ( V_2 , V_10 ) ;
}
F_18 ( V_10 ) ;
F_19 ( V_31 ) ;
F_20 ( V_10 ) ;
}
F_21 ( V_10 ) ;
return V_14 ;
}
static int F_22 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned long V_35 ;
F_23 ( V_2 , V_36 , V_2 -> V_7 ,
L_3 , V_10 -> V_10 ) ;
V_35 = F_24 ( V_2 -> V_37 + V_2 -> V_38 + 128 ) ;
F_25 ( V_35 > V_39 ) ;
V_10 -> V_40 = F_26 ( V_35 , V_41 ) - 1 ;
return F_27 ( V_10 ) ;
}
static int F_28 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_42 ;
F_29 ( V_10 -> V_43 ) ;
F_23 ( V_2 , V_6 , V_2 -> V_7 ,
L_4 , V_10 -> V_10 ) ;
V_42 = F_30 ( V_10 ) ;
if ( V_42 == 0 ) {
V_2 -> type -> V_26 ( V_10 ) ;
V_10 -> V_44 = 0 ;
V_10 -> V_43 = true ;
}
return V_42 ;
}
void F_31 ( struct V_9 * V_10 )
{
F_23 ( V_10 -> V_2 , V_45 , V_10 -> V_2 -> V_7 ,
L_5 , V_10 -> V_10 ) ;
V_10 -> V_15 = true ;
F_32 () ;
F_33 ( V_10 ) ;
F_34 ( & V_10 -> V_32 ) ;
F_20 ( V_10 ) ;
}
void F_35 ( struct V_9 * V_10 )
{
if ( ! V_10 -> V_15 )
return;
F_36 ( & V_10 -> V_32 ) ;
while ( ! F_37 ( V_10 ) )
F_38 ( 1000 , 20000 ) ;
V_10 -> V_15 = false ;
}
static void F_39 ( struct V_9 * V_10 )
{
if ( ! V_10 -> V_43 )
return;
F_23 ( V_10 -> V_2 , V_6 , V_10 -> V_2 -> V_7 ,
L_6 , V_10 -> V_10 ) ;
F_40 ( V_10 ) ;
V_10 -> V_43 = false ;
}
static void F_41 ( struct V_9 * V_10 )
{
F_23 ( V_10 -> V_2 , V_6 , V_10 -> V_2 -> V_7 ,
L_7 , V_10 -> V_10 ) ;
F_42 ( V_10 ) ;
}
static struct V_9 *
F_43 ( struct V_1 * V_2 , int V_46 , struct V_9 * V_47 )
{
struct V_9 * V_10 ;
struct V_18 * V_19 ;
struct V_12 * V_13 ;
int V_48 ;
V_10 = F_44 ( sizeof( * V_10 ) , V_49 ) ;
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
F_45 ( & V_19 -> V_53 , V_54 ,
( unsigned long ) V_19 ) ;
return V_10 ;
}
static struct V_9 *
F_46 ( const struct V_9 * V_47 )
{
struct V_9 * V_10 ;
struct V_18 * V_19 ;
struct V_12 * V_13 ;
int V_48 ;
V_10 = F_47 ( sizeof( * V_10 ) , V_49 ) ;
if ( ! V_10 )
return NULL ;
* V_10 = * V_47 ;
V_10 -> V_55 = NULL ;
F_48 ( & V_10 -> V_32 . V_56 ) ;
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
F_45 ( & V_19 -> V_53 , V_54 ,
( unsigned long ) V_19 ) ;
return V_10 ;
}
static int F_49 ( struct V_9 * V_10 )
{
struct V_12 * V_13 ;
struct V_18 * V_19 ;
int V_42 ;
F_23 ( V_10 -> V_2 , V_36 , V_10 -> V_2 -> V_7 ,
L_8 , V_10 -> V_10 ) ;
V_42 = V_10 -> type -> V_62 ( V_10 ) ;
if ( V_42 )
goto V_63;
V_42 = F_22 ( V_10 ) ;
if ( V_42 )
goto V_63;
F_5 (tx_queue, channel) {
V_42 = F_50 ( V_13 ) ;
if ( V_42 )
goto V_63;
}
F_51 (rx_queue, channel) {
V_42 = F_52 ( V_19 ) ;
if ( V_42 )
goto V_63;
}
return 0 ;
V_63:
F_53 ( V_10 ) ;
return V_42 ;
}
static void
F_54 ( struct V_9 * V_10 , char * V_64 , T_1 V_65 )
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
static void F_55 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_56 (channel, efx)
V_10 -> type -> V_69 ( V_10 ,
V_2 -> V_70 [ V_10 -> V_10 ] . V_68 ,
sizeof( V_2 -> V_70 [ 0 ] . V_68 ) ) ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
int V_42 ;
V_2 -> V_71 = 0 ;
F_58 (channel, efx) {
V_42 = F_49 ( V_10 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 ,
L_13 ,
V_10 -> V_10 ) ;
goto V_63;
}
}
F_55 ( V_2 ) ;
return 0 ;
V_63:
F_59 ( V_2 ) ;
return V_42 ;
}
static void F_60 ( struct V_1 * V_2 )
{
T_2 V_72 = V_2 -> V_7 -> V_73 ;
bool V_74 = V_2 -> V_75 ;
struct V_12 * V_13 ;
struct V_18 * V_19 ;
struct V_9 * V_10 ;
T_1 V_76 ;
V_2 -> V_77 = ( V_2 -> V_78 +
F_61 ( V_2 -> V_7 -> V_79 ) +
V_2 -> type -> V_80 ) ;
V_76 = ( sizeof( struct V_81 ) +
V_2 -> V_82 + V_2 -> V_77 ) ;
if ( V_76 <= V_83 ) {
V_2 -> V_75 = V_2 -> type -> V_84 ;
V_2 -> V_85 = 0 ;
} else if ( V_2 -> type -> V_86 ) {
F_62 ( V_87 % V_88 ) ;
F_62 ( sizeof( struct V_81 ) +
2 * F_63 ( V_89 + V_87 ,
V_90 ) >
V_83 ) ;
V_2 -> V_75 = true ;
V_2 -> V_77 = V_87 ;
V_2 -> V_85 = 0 ;
} else {
V_2 -> V_75 = false ;
V_2 -> V_85 = F_64 ( V_76 ) ;
}
F_65 ( V_2 ) ;
if ( V_2 -> V_85 )
F_23 ( V_2 , V_6 , V_2 -> V_7 ,
L_14 ,
V_2 -> V_77 , V_2 -> V_85 ,
V_2 -> V_91 ) ;
else
F_23 ( V_2 , V_6 , V_2 -> V_7 ,
L_15 ,
V_2 -> V_77 , V_2 -> V_92 ,
V_2 -> V_93 , V_2 -> V_91 ) ;
V_2 -> V_7 -> V_94 |= V_2 -> V_7 -> V_73 ;
V_2 -> V_7 -> V_94 &= ~ V_2 -> V_95 ;
V_2 -> V_7 -> V_73 |= V_2 -> V_95 ;
if ( V_2 -> V_7 -> V_73 != V_72 )
F_66 ( V_2 -> V_7 ) ;
if ( V_2 -> V_75 != V_74 )
V_2 -> type -> V_96 ( V_2 ) ;
V_2 -> V_97 = V_2 -> V_38 - F_67 ( V_2 ) ;
V_2 -> V_98 = V_2 -> V_97 / 2 ;
F_56 (channel, efx) {
F_5 (tx_queue, channel) {
F_68 ( V_13 ) ;
F_69 ( & V_2 -> V_99 ) ;
}
F_51 (rx_queue, channel) {
F_70 ( V_19 ) ;
F_69 ( & V_2 -> V_99 ) ;
F_35 ( V_10 ) ;
F_10 ( V_19 , false ) ;
F_31 ( V_10 ) ;
}
F_71 ( V_10 -> V_100 ) ;
}
F_72 ( V_2 ) ;
if ( F_73 ( V_2 -> V_7 ) )
F_74 ( V_2 -> V_7 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_12 * V_13 ;
struct V_18 * V_19 ;
int V_42 ;
F_76 ( V_2 ) ;
F_77 ( V_2 -> V_101 ) ;
F_78 ( V_2 ) ;
F_56 (channel, efx) {
F_51 (rx_queue, channel)
V_19 -> V_102 = false ;
}
F_56 (channel, efx) {
if ( F_7 ( V_10 ) ) {
F_35 ( V_10 ) ;
F_31 ( V_10 ) ;
}
}
V_42 = V_2 -> type -> V_103 ( V_2 ) ;
if ( V_42 && F_79 ( V_2 ) ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_16 ) ;
F_80 ( V_2 , V_104 ) ;
} else if ( V_42 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_17 ) ;
} else {
F_23 ( V_2 , V_6 , V_2 -> V_7 ,
L_18 ) ;
}
F_56 (channel, efx) {
F_51 (rx_queue, channel)
F_81 ( V_19 ) ;
F_82 (tx_queue, channel)
F_83 ( V_13 ) ;
}
}
static void F_53 ( struct V_9 * V_10 )
{
struct V_12 * V_13 ;
struct V_18 * V_19 ;
F_23 ( V_10 -> V_2 , V_6 , V_10 -> V_2 -> V_7 ,
L_19 , V_10 -> V_10 ) ;
F_51 (rx_queue, channel)
F_84 ( V_19 ) ;
F_82 (tx_queue, channel)
F_85 ( V_13 ) ;
F_41 ( V_10 ) ;
V_10 -> type -> V_105 ( V_10 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_56 (channel, efx)
F_53 ( V_10 ) ;
}
int
F_86 ( struct V_1 * V_2 , T_3 V_37 , T_3 V_38 )
{
struct V_9 * V_106 [ V_107 ] , * V_10 ;
T_3 V_108 , V_109 ;
unsigned V_46 , V_71 = 0 ;
int V_42 , V_110 ;
V_42 = F_1 ( V_2 ) ;
if ( V_42 )
return V_42 ;
F_56 (channel, efx) {
struct V_18 * V_19 ;
struct V_12 * V_13 ;
if ( V_10 -> type -> V_111 )
continue;
V_71 = F_26 ( V_71 ,
V_10 -> V_58 . V_112 +
V_10 -> V_58 . V_35 ) ;
F_51 (rx_queue, channel)
V_71 = F_26 ( V_71 ,
V_19 -> V_61 . V_112 +
V_19 -> V_61 . V_35 ) ;
F_5 (tx_queue, channel)
V_71 = F_26 ( V_71 ,
V_13 -> V_60 . V_112 +
V_13 -> V_60 . V_35 ) ;
}
F_87 ( V_2 ) ;
F_88 ( V_2 ) ;
F_89 ( V_2 ) ;
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
V_42 = F_49 ( V_10 ) ;
if ( V_42 )
goto V_116;
F_90 ( V_2 -> V_10 [ V_46 ] ) ;
}
V_115:
for ( V_46 = 0 ; V_46 < V_2 -> V_113 ; V_46 ++ ) {
V_10 = V_106 [ V_46 ] ;
if ( V_10 && V_10 -> type -> V_111 ) {
F_91 ( V_10 ) ;
F_53 ( V_10 ) ;
F_92 ( V_10 ) ;
}
}
V_110 = F_93 ( V_2 ) ;
if ( V_110 ) {
V_42 = V_42 ? V_42 : V_110 ;
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_20 ) ;
F_80 ( V_2 , V_117 ) ;
} else {
F_94 ( V_2 ) ;
F_95 ( V_2 -> V_7 ) ;
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
void F_96 ( struct V_18 * V_19 )
{
F_97 ( & V_19 -> V_53 , V_118 + F_98 ( 100 ) ) ;
}
int F_99 ( struct V_9 * V_10 )
{
return 0 ;
}
void F_100 ( struct V_9 * V_10 )
{
}
void F_101 ( struct V_1 * V_2 )
{
struct V_119 * V_120 = & V_2 -> V_120 ;
if ( ! F_102 ( V_2 -> V_7 ) )
return;
if ( V_120 -> V_121 != F_103 ( V_2 -> V_7 ) ) {
V_2 -> V_122 ++ ;
if ( V_120 -> V_121 )
F_104 ( V_2 -> V_7 ) ;
else
F_105 ( V_2 -> V_7 ) ;
}
if ( V_120 -> V_121 )
F_106 ( V_2 , V_123 , V_2 -> V_7 ,
L_21 ,
V_120 -> V_124 , V_120 -> V_125 ? L_22 : L_23 ,
V_2 -> V_7 -> V_79 ) ;
else
F_106 ( V_2 , V_123 , V_2 -> V_7 , L_24 ) ;
}
void F_107 ( struct V_1 * V_2 , T_3 V_126 )
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
void F_108 ( struct V_1 * V_2 , T_4 V_129 )
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
void F_109 ( struct V_1 * V_2 )
{
F_110 ( & V_2 -> V_133 ) ;
V_2 -> type -> V_134 ( V_2 ) ;
F_111 ( & V_2 -> V_133 ) ;
}
int F_112 ( struct V_1 * V_2 )
{
enum V_135 V_136 ;
int V_42 ;
F_71 ( ! F_113 ( & V_2 -> V_137 ) ) ;
V_136 = V_2 -> V_136 ;
if ( F_114 ( V_2 ) )
V_2 -> V_136 |= V_138 ;
else
V_2 -> V_136 &= ~ V_138 ;
V_42 = V_2 -> type -> V_139 ( V_2 ) ;
if ( V_42 )
V_2 -> V_136 = V_136 ;
return V_42 ;
}
int F_115 ( struct V_1 * V_2 )
{
int V_42 ;
F_76 ( V_2 ) ;
F_116 ( & V_2 -> V_137 ) ;
V_42 = F_112 ( V_2 ) ;
F_117 ( & V_2 -> V_137 ) ;
return V_42 ;
}
static void F_118 ( struct V_140 * V_141 )
{
struct V_1 * V_2 = F_14 ( V_141 , struct V_1 , V_142 ) ;
F_116 ( & V_2 -> V_137 ) ;
if ( V_2 -> V_101 )
F_109 ( V_2 ) ;
F_117 ( & V_2 -> V_137 ) ;
}
static int F_119 ( struct V_1 * V_2 )
{
int V_42 ;
F_23 ( V_2 , V_36 , V_2 -> V_7 , L_25 ) ;
if ( V_143 )
V_2 -> V_136 = V_144 ;
V_42 = V_2 -> type -> V_145 ( V_2 ) ;
if ( V_42 )
return V_42 ;
F_120 ( V_2 -> V_7 -> V_146 , V_2 -> V_7 -> V_147 ) ;
return 0 ;
}
static int F_121 ( struct V_1 * V_2 )
{
int V_42 ;
F_23 ( V_2 , V_6 , V_2 -> V_7 , L_26 ) ;
F_116 ( & V_2 -> V_137 ) ;
V_42 = V_2 -> V_148 -> V_149 ( V_2 ) ;
if ( V_42 )
goto V_150;
V_2 -> V_151 = true ;
F_109 ( V_2 ) ;
V_42 = V_2 -> V_148 -> V_152 ( V_2 ) ;
if ( V_42 && V_42 != - V_153 )
goto V_154;
F_117 ( & V_2 -> V_137 ) ;
return 0 ;
V_154:
V_2 -> V_148 -> V_155 ( V_2 ) ;
V_150:
F_117 ( & V_2 -> V_137 ) ;
return V_42 ;
}
static void F_122 ( struct V_1 * V_2 )
{
F_23 ( V_2 , V_45 , V_2 -> V_7 , L_27 ) ;
F_77 ( V_2 -> V_101 ) ;
F_116 ( & V_2 -> V_137 ) ;
V_2 -> V_101 = true ;
F_109 ( V_2 ) ;
F_117 ( & V_2 -> V_137 ) ;
}
static void F_123 ( struct V_1 * V_2 )
{
F_23 ( V_2 , V_156 , V_2 -> V_7 , L_28 ) ;
F_76 ( V_2 ) ;
F_116 ( & V_2 -> V_137 ) ;
V_2 -> V_101 = false ;
F_117 ( & V_2 -> V_137 ) ;
F_124 ( V_2 -> V_7 ) ;
F_125 ( V_2 -> V_7 ) ;
F_126 ( & V_2 -> V_157 ) ;
F_127 ( V_2 ) ;
F_128 ( & V_2 -> V_142 ) ;
}
static void F_129 ( struct V_1 * V_2 )
{
F_23 ( V_2 , V_6 , V_2 -> V_7 , L_29 ) ;
if ( ! V_2 -> V_151 )
return;
V_2 -> V_148 -> V_155 ( V_2 ) ;
V_2 -> V_151 = false ;
V_2 -> V_120 . V_121 = false ;
F_101 ( V_2 ) ;
}
static void F_130 ( struct V_1 * V_2 )
{
F_23 ( V_2 , V_6 , V_2 -> V_7 , L_30 ) ;
V_2 -> type -> V_158 ( V_2 ) ;
}
static bool F_131 ( struct V_1 * V_159 , struct V_1 * V_160 )
{
return V_159 -> type == V_160 -> type &&
V_159 -> V_161 && V_160 -> V_161 &&
! strcmp ( V_159 -> V_161 , V_160 -> V_161 ) ;
}
static void F_132 ( struct V_1 * V_2 )
{
struct V_1 * V_162 , * V_163 ;
if ( V_2 -> V_164 == V_2 ) {
F_23 ( V_2 , V_36 , V_2 -> V_7 , L_31 ) ;
F_133 ( & V_2 -> V_165 , & V_166 ) ;
F_134 (other, next, &efx_unassociated_list,
node) {
if ( F_131 ( V_2 , V_162 ) ) {
F_135 ( & V_162 -> V_165 ) ;
F_23 ( V_162 , V_36 , V_162 -> V_7 ,
L_32 ,
F_136 ( V_2 -> V_167 ) ,
V_2 -> V_7 -> V_68 ) ;
F_133 ( & V_162 -> V_165 ,
& V_2 -> V_168 ) ;
V_162 -> V_164 = V_2 ;
}
}
} else {
F_137 (other, &efx_primary_list, node) {
if ( F_131 ( V_2 , V_162 ) ) {
F_23 ( V_2 , V_36 , V_2 -> V_7 ,
L_33 ,
F_136 ( V_162 -> V_167 ) ,
V_162 -> V_7 -> V_68 ) ;
F_133 ( & V_2 -> V_165 ,
& V_162 -> V_168 ) ;
V_2 -> V_164 = V_162 ;
return;
}
}
F_23 ( V_2 , V_36 , V_2 -> V_7 ,
L_34 ) ;
F_133 ( & V_2 -> V_165 , & V_169 ) ;
}
}
static void F_138 ( struct V_1 * V_2 )
{
struct V_1 * V_162 , * V_163 ;
F_135 ( & V_2 -> V_165 ) ;
V_2 -> V_164 = NULL ;
F_134 (other, next, &efx->secondary_list, node) {
F_135 ( & V_162 -> V_165 ) ;
F_23 ( V_162 , V_36 , V_162 -> V_7 ,
L_35 ) ;
F_133 ( & V_162 -> V_165 , & V_169 ) ;
V_162 -> V_164 = NULL ;
}
}
static int F_139 ( struct V_1 * V_2 )
{
struct V_167 * V_167 = V_2 -> V_167 ;
T_5 V_170 = V_2 -> type -> V_171 ;
unsigned int V_172 = V_2 -> type -> V_172 ( V_2 ) ;
int V_42 , V_173 ;
F_23 ( V_2 , V_36 , V_2 -> V_7 , L_36 ) ;
V_173 = V_2 -> type -> V_174 ;
V_42 = F_140 ( V_167 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 ,
L_37 ) ;
goto V_150;
}
F_141 ( V_167 ) ;
while ( V_170 > 0x7fffffffUL ) {
V_42 = F_142 ( & V_167 -> V_175 , V_170 ) ;
if ( V_42 == 0 )
break;
V_170 >>= 1 ;
}
if ( V_42 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 ,
L_38 ) ;
goto V_154;
}
F_23 ( V_2 , V_36 , V_2 -> V_7 ,
L_39 , ( unsigned long long ) V_170 ) ;
V_2 -> V_176 = F_143 ( V_2 -> V_167 , V_173 ) ;
V_42 = F_144 ( V_167 , V_173 , L_40 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 ,
L_41 ) ;
V_42 = - V_8 ;
goto V_177;
}
V_2 -> V_178 = F_145 ( V_2 -> V_176 , V_172 ) ;
if ( ! V_2 -> V_178 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 ,
L_42 ,
( unsigned long long ) V_2 -> V_176 , V_172 ) ;
V_42 = - V_114 ;
goto V_179;
}
F_23 ( V_2 , V_36 , V_2 -> V_7 ,
L_43 ,
( unsigned long long ) V_2 -> V_176 , V_172 ,
V_2 -> V_178 ) ;
return 0 ;
V_179:
F_146 ( V_2 -> V_167 , V_173 ) ;
V_177:
V_2 -> V_176 = 0 ;
V_154:
F_147 ( V_2 -> V_167 ) ;
V_150:
return V_42 ;
}
static void F_148 ( struct V_1 * V_2 )
{
int V_173 ;
F_23 ( V_2 , V_6 , V_2 -> V_7 , L_44 ) ;
if ( V_2 -> V_178 ) {
F_149 ( V_2 -> V_178 ) ;
V_2 -> V_178 = NULL ;
}
if ( V_2 -> V_176 ) {
V_173 = V_2 -> type -> V_174 ;
F_146 ( V_2 -> V_167 , V_173 ) ;
V_2 -> V_176 = 0 ;
}
if ( ! F_150 ( V_2 -> V_167 ) )
F_147 ( V_2 -> V_167 ) ;
}
void F_151 ( struct V_1 * V_2 )
{
T_1 V_46 ;
for ( V_46 = 0 ; V_46 < F_152 ( V_2 -> V_180 ) ; V_46 ++ )
V_2 -> V_180 [ V_46 ] =
F_153 ( V_46 , V_2 -> V_181 ) ;
}
static unsigned int F_154 ( struct V_1 * V_2 )
{
T_6 V_182 ;
unsigned int V_183 ;
int V_184 ;
if ( V_185 ) {
V_183 = V_185 ;
} else {
if ( F_4 ( ! F_155 ( & V_182 , V_49 ) ) ) {
F_156 ( V_2 , V_36 , V_2 -> V_7 ,
L_45 ) ;
return 1 ;
}
V_183 = 0 ;
F_157 (cpu) {
if ( ! F_158 ( V_184 , V_182 ) ) {
++ V_183 ;
F_159 ( V_182 , V_182 ,
F_160 ( V_184 ) ) ;
}
}
F_161 ( V_182 ) ;
}
#ifdef F_162
if ( V_2 -> type -> V_186 ) {
if ( V_2 -> type -> V_186 ( V_2 ) && F_163 ( V_2 ) > 1 &&
V_183 > F_163 ( V_2 ) ) {
F_156 ( V_2 , V_36 , V_2 -> V_7 ,
L_46
L_47
L_48 ,
V_183 , F_163 ( V_2 ) ) ;
V_183 = F_163 ( V_2 ) ;
}
}
#endif
return V_183 ;
}
static int F_164 ( struct V_1 * V_2 )
{
unsigned int V_187 = 0 ;
unsigned int V_46 , V_48 ;
int V_42 ;
for ( V_46 = 0 ; V_46 < V_188 ; V_46 ++ )
if ( V_2 -> V_189 [ V_46 ] )
++ V_187 ;
if ( V_2 -> V_190 == V_191 ) {
struct V_192 V_193 [ V_107 ] ;
unsigned int V_113 ;
V_113 = F_154 ( V_2 ) ;
if ( V_194 )
V_113 *= 2 ;
V_113 += V_187 ;
V_113 = F_165 ( V_113 , V_2 -> V_195 ) ;
for ( V_46 = 0 ; V_46 < V_113 ; V_46 ++ )
V_193 [ V_46 ] . V_196 = V_46 ;
V_42 = F_166 ( V_2 -> V_167 ,
V_193 , 1 , V_113 ) ;
if ( V_42 < 0 ) {
V_2 -> V_190 = V_197 ;
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_49 ) ;
} else if ( V_42 < V_113 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_50
L_51 , V_42 , V_113 ) ;
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_52 ) ;
V_113 = V_42 ;
}
if ( V_42 > 0 ) {
V_2 -> V_113 = V_113 ;
if ( V_113 > V_187 )
V_113 -= V_187 ;
if ( V_194 ) {
V_2 -> V_198 = F_165 ( F_26 ( V_113 / 2 ,
1U ) ,
V_2 -> V_199 ) ;
V_2 -> V_200 = F_26 ( V_113 -
V_2 -> V_198 ,
1U ) ;
} else {
V_2 -> V_198 = F_165 ( V_113 ,
V_2 -> V_199 ) ;
V_2 -> V_200 = V_113 ;
}
for ( V_46 = 0 ; V_46 < V_2 -> V_113 ; V_46 ++ )
F_167 ( V_2 , V_46 ) -> V_201 =
V_193 [ V_46 ] . V_202 ;
}
}
if ( V_2 -> V_190 == V_197 ) {
V_2 -> V_113 = 1 ;
V_2 -> V_200 = 1 ;
V_2 -> V_198 = 1 ;
V_42 = F_168 ( V_2 -> V_167 ) ;
if ( V_42 == 0 ) {
F_167 ( V_2 , 0 ) -> V_201 = V_2 -> V_167 -> V_201 ;
} else {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_53 ) ;
V_2 -> V_190 = V_203 ;
}
}
if ( V_2 -> V_190 == V_203 ) {
V_2 -> V_113 = 1 + ( V_194 ? 1 : 0 ) ;
V_2 -> V_200 = 1 ;
V_2 -> V_198 = 1 ;
V_2 -> V_204 = V_2 -> V_167 -> V_201 ;
}
V_48 = V_2 -> V_113 ;
for ( V_46 = 0 ; V_46 < V_188 ; V_46 ++ ) {
if ( ! V_2 -> V_189 [ V_46 ] )
continue;
if ( V_2 -> V_190 != V_191 ||
V_2 -> V_113 <= V_187 ) {
V_2 -> V_189 [ V_46 ] -> F_169 ( V_2 ) ;
} else {
-- V_48 ;
F_167 ( V_2 , V_48 ) -> type =
V_2 -> V_189 [ V_46 ] ;
}
}
#ifdef F_162
if ( V_2 -> type -> V_186 ) {
V_2 -> V_181 = ( ( V_2 -> V_200 > 1 ||
! V_2 -> type -> V_186 ( V_2 ) ) ?
V_2 -> V_200 : F_163 ( V_2 ) ) ;
return 0 ;
}
#endif
V_2 -> V_181 = V_2 -> V_200 ;
return 0 ;
}
static int F_93 ( struct V_1 * V_2 )
{
struct V_9 * V_10 , * V_205 ;
int V_42 ;
F_77 ( V_2 -> V_3 == V_4 ) ;
V_2 -> V_206 = true ;
F_32 () ;
F_56 (channel, efx) {
if ( ! V_10 -> type -> V_207 ) {
V_42 = F_28 ( V_10 ) ;
if ( V_42 )
goto V_63;
}
F_31 ( V_10 ) ;
}
F_170 ( V_2 ) ;
return 0 ;
V_63:
V_205 = V_10 ;
F_56 (channel, efx) {
if ( V_10 == V_205 )
break;
F_35 ( V_10 ) ;
if ( ! V_10 -> type -> V_207 )
F_39 ( V_10 ) ;
}
return V_42 ;
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
if ( V_2 -> V_3 == V_4 )
return;
F_171 ( V_2 ) ;
V_2 -> V_206 = false ;
F_32 () ;
if ( V_2 -> V_204 )
F_172 ( V_2 -> V_204 ) ;
F_56 (channel, efx) {
if ( V_10 -> V_201 )
F_172 ( V_10 -> V_201 ) ;
F_35 ( V_10 ) ;
if ( ! V_10 -> type -> V_207 )
F_39 ( V_10 ) ;
}
F_173 ( V_2 ) ;
}
static int F_174 ( struct V_1 * V_2 )
{
struct V_9 * V_10 , * V_205 ;
int V_42 ;
F_77 ( V_2 -> V_3 == V_4 ) ;
if ( V_2 -> V_208 ) {
F_175 ( V_2 -> V_204 ) ;
V_2 -> V_208 = false ;
}
V_2 -> type -> V_209 ( V_2 ) ;
F_56 (channel, efx) {
if ( V_10 -> type -> V_207 ) {
V_42 = F_28 ( V_10 ) ;
if ( V_42 )
goto V_63;
}
}
V_42 = F_93 ( V_2 ) ;
if ( V_42 )
goto V_63;
return 0 ;
V_63:
V_205 = V_10 ;
F_56 (channel, efx) {
if ( V_10 == V_205 )
break;
if ( V_10 -> type -> V_207 )
F_39 ( V_10 ) ;
}
V_2 -> type -> V_210 ( V_2 ) ;
return V_42 ;
}
static void F_176 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_89 ( V_2 ) ;
F_56 (channel, efx) {
if ( V_10 -> type -> V_207 )
F_39 ( V_10 ) ;
}
V_2 -> type -> V_210 ( V_2 ) ;
}
static void F_177 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_56 (channel, efx)
V_10 -> V_201 = 0 ;
F_178 ( V_2 -> V_167 ) ;
F_179 ( V_2 -> V_167 ) ;
V_2 -> V_204 = 0 ;
}
static void F_180 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_12 * V_13 ;
V_2 -> V_67 =
V_194 ?
V_2 -> V_113 - V_2 -> V_198 : 0 ;
F_56 (channel, efx) {
if ( V_10 -> V_10 < V_2 -> V_200 )
V_10 -> V_19 . V_211 = V_10 -> V_10 ;
else
V_10 -> V_19 . V_211 = - 1 ;
F_5 (tx_queue, channel)
V_13 -> V_52 -= ( V_2 -> V_67 *
V_51 ) ;
}
}
static int F_181 ( struct V_1 * V_2 )
{
int V_42 ;
F_23 ( V_2 , V_36 , V_2 -> V_7 , L_54 ) ;
V_42 = V_2 -> type -> V_36 ( V_2 ) ;
if ( V_42 )
return V_42 ;
do {
if ( ! V_2 -> V_195 || ! V_2 -> V_199 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_55
L_56 ) ;
V_42 = - V_212 ;
goto V_150;
}
V_42 = F_164 ( V_2 ) ;
if ( V_42 )
goto V_150;
F_180 ( V_2 ) ;
V_42 = V_2 -> type -> V_213 ( V_2 ) ;
if ( V_42 != 0 && V_42 != - V_214 )
goto V_154;
if ( V_42 == - V_214 )
F_177 ( V_2 ) ;
} while ( V_42 == - V_214 );
if ( V_2 -> V_113 > 1 )
F_182 ( & V_2 -> V_215 ,
sizeof( V_2 -> V_215 ) ) ;
F_151 ( V_2 ) ;
F_183 ( V_2 -> V_7 , V_2 -> V_198 ) ;
F_184 ( V_2 -> V_7 , V_2 -> V_200 ) ;
V_2 -> V_22 = F_185 ( V_2 -> V_216 , 1000 ) ;
F_186 ( V_2 , V_217 , V_218 , true ,
true ) ;
return 0 ;
V_154:
F_177 ( V_2 ) ;
V_150:
V_2 -> type -> remove ( V_2 ) ;
return V_42 ;
}
static void F_187 ( struct V_1 * V_2 )
{
F_23 ( V_2 , V_6 , V_2 -> V_7 , L_57 ) ;
F_177 ( V_2 ) ;
V_2 -> type -> remove ( V_2 ) ;
}
static int F_188 ( struct V_1 * V_2 )
{
int V_42 ;
F_189 ( & V_2 -> V_219 ) ;
F_190 ( & V_2 -> V_133 ) ;
F_116 ( & V_2 -> V_137 ) ;
F_191 ( & V_2 -> V_133 ) ;
V_42 = V_2 -> type -> V_220 ( V_2 ) ;
if ( V_42 )
goto V_221;
#ifdef F_192
if ( V_2 -> type -> V_222 & V_223 ) {
struct V_9 * V_10 ;
int V_46 , V_224 = 1 ;
F_56 (channel, efx) {
V_10 -> V_225 =
F_193 ( V_2 -> type -> V_226 ,
sizeof( * V_10 -> V_225 ) ,
V_49 ) ;
if ( ! V_10 -> V_225 )
V_224 = 0 ;
else
for ( V_46 = 0 ;
V_46 < V_2 -> type -> V_226 ;
++ V_46 )
V_10 -> V_225 [ V_46 ] =
V_227 ;
}
if ( ! V_224 ) {
F_56 (channel, efx)
F_92 ( V_10 -> V_225 ) ;
V_2 -> type -> V_228 ( V_2 ) ;
V_42 = - V_114 ;
goto V_221;
}
V_2 -> V_229 = V_2 -> V_230 = 0 ;
}
#endif
V_221:
F_194 ( & V_2 -> V_133 ) ;
F_117 ( & V_2 -> V_137 ) ;
return V_42 ;
}
static void F_195 ( struct V_1 * V_2 )
{
#ifdef F_192
struct V_9 * V_10 ;
F_56 (channel, efx)
F_92 ( V_10 -> V_225 ) ;
#endif
F_191 ( & V_2 -> V_133 ) ;
V_2 -> type -> V_228 ( V_2 ) ;
F_194 ( & V_2 -> V_133 ) ;
}
static void F_196 ( struct V_1 * V_2 )
{
F_110 ( & V_2 -> V_133 ) ;
V_2 -> type -> V_231 ( V_2 ) ;
F_111 ( & V_2 -> V_133 ) ;
}
static int F_197 ( struct V_1 * V_2 )
{
int V_42 ;
V_42 = F_181 ( V_2 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 , L_58 ) ;
goto V_150;
}
V_42 = F_119 ( V_2 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 , L_59 ) ;
goto V_154;
}
F_62 ( V_232 < V_233 ) ;
if ( F_71 ( V_232 < F_198 ( V_2 ) ) ) {
V_42 = - V_234 ;
goto V_177;
}
V_2 -> V_37 = V_2 -> V_38 = V_232 ;
#ifdef F_162
V_42 = V_2 -> type -> V_235 ( V_2 ) ;
if ( V_42 )
F_156 ( V_2 , V_36 , V_2 -> V_7 ,
L_60
L_61 , V_42 ) ;
#endif
V_42 = F_188 ( V_2 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 ,
L_62 ) ;
goto V_179;
}
V_42 = F_57 ( V_2 ) ;
if ( V_42 )
goto V_236;
return 0 ;
V_236:
F_195 ( V_2 ) ;
V_179:
#ifdef F_162
V_2 -> type -> V_237 ( V_2 ) ;
#endif
V_177:
F_130 ( V_2 ) ;
V_154:
F_187 ( V_2 ) ;
V_150:
return V_42 ;
}
static void F_94 ( struct V_1 * V_2 )
{
F_76 ( V_2 ) ;
F_77 ( V_2 -> V_3 == V_4 ) ;
if ( V_2 -> V_101 || ! F_102 ( V_2 -> V_7 ) ||
V_2 -> V_238 )
return;
F_122 ( V_2 ) ;
F_60 ( V_2 ) ;
if ( V_2 -> type -> V_239 != NULL )
F_199 ( V_2 -> V_240 , & V_2 -> V_157 ,
V_241 ) ;
if ( F_200 ( V_2 ) >= V_242 ) {
F_116 ( & V_2 -> V_137 ) ;
if ( V_2 -> V_148 -> V_243 ( V_2 ) )
F_101 ( V_2 ) ;
F_117 ( & V_2 -> V_137 ) ;
}
V_2 -> type -> V_244 ( V_2 ) ;
V_2 -> type -> V_245 ( V_2 ) ;
F_201 ( & V_2 -> V_246 ) ;
V_2 -> type -> V_247 ( V_2 , NULL , NULL ) ;
F_202 ( & V_2 -> V_246 ) ;
}
static void F_88 ( struct V_1 * V_2 )
{
F_76 ( V_2 ) ;
if ( ! V_2 -> V_101 )
return;
V_2 -> type -> V_245 ( V_2 ) ;
F_201 ( & V_2 -> V_246 ) ;
V_2 -> type -> V_247 ( V_2 , NULL , NULL ) ;
F_202 ( & V_2 -> V_246 ) ;
V_2 -> type -> V_248 ( V_2 ) ;
F_123 ( V_2 ) ;
F_71 ( F_102 ( V_2 -> V_7 ) &&
F_73 ( V_2 -> V_7 ) ) ;
F_203 ( V_2 -> V_7 ) ;
F_75 ( V_2 ) ;
}
static void F_204 ( struct V_1 * V_2 )
{
F_59 ( V_2 ) ;
F_195 ( V_2 ) ;
#ifdef F_162
V_2 -> type -> V_237 ( V_2 ) ;
#endif
F_130 ( V_2 ) ;
F_187 ( V_2 ) ;
}
unsigned int F_205 ( struct V_1 * V_2 , unsigned int V_249 )
{
if ( V_249 == 0 )
return 0 ;
if ( V_249 * 1000 < V_2 -> V_216 )
return 1 ;
return V_249 * 1000 / V_2 -> V_216 ;
}
unsigned int F_206 ( struct V_1 * V_2 , unsigned int V_250 )
{
return F_185 ( V_250 * V_2 -> V_216 , 1000 ) ;
}
int F_186 ( struct V_1 * V_2 , unsigned int V_251 ,
unsigned int V_252 , bool V_253 ,
bool V_254 )
{
struct V_9 * V_10 ;
unsigned int V_255 ;
F_76 ( V_2 ) ;
V_255 = V_2 -> V_256 / 1000 ;
if ( V_251 > V_255 || V_252 > V_255 )
return - V_234 ;
if ( V_251 != V_252 && V_2 -> V_67 == 0 &&
! V_254 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_63
L_64 ) ;
return - V_234 ;
}
V_2 -> V_34 = V_253 ;
V_2 -> V_28 = V_252 ;
F_56 (channel, efx) {
if ( F_7 ( V_10 ) )
V_10 -> V_25 = V_252 ;
else if ( F_207 ( V_10 ) )
V_10 -> V_25 = V_251 ;
}
return 0 ;
}
void F_208 ( struct V_1 * V_2 , unsigned int * V_251 ,
unsigned int * V_252 , bool * V_253 )
{
* V_253 = V_2 -> V_34 ;
* V_252 = V_2 -> V_28 ;
if ( V_2 -> V_67 == 0 ) {
* V_251 = * V_252 ;
} else {
struct V_9 * V_257 ;
V_257 = V_2 -> V_10 [ V_2 -> V_67 ] ;
* V_251 = V_257 -> V_25 ;
}
}
static void F_209 ( struct V_140 * V_141 )
{
struct V_1 * V_2 = F_14 ( V_141 , struct V_1 ,
V_157 . V_258 ) ;
F_16 ( V_2 , V_259 , V_2 -> V_7 ,
L_65 ,
F_17 () ) ;
F_77 ( V_2 -> type -> V_239 == NULL ) ;
if ( F_210 ( & V_2 -> V_137 ) ) {
if ( V_2 -> V_101 )
V_2 -> type -> V_239 ( V_2 ) ;
F_117 ( & V_2 -> V_137 ) ;
}
F_199 ( V_2 -> V_240 , & V_2 -> V_157 ,
V_241 ) ;
}
static int F_211 ( struct V_260 * V_7 , struct V_261 * V_262 , int V_263 )
{
struct V_1 * V_2 = F_212 ( V_7 ) ;
struct V_264 * V_141 = F_213 ( V_262 ) ;
if ( V_263 == V_265 )
return F_214 ( V_2 , V_262 ) ;
if ( V_263 == V_266 )
return F_215 ( V_2 , V_262 ) ;
if ( ( V_263 == V_267 || V_263 == V_268 ) &&
( V_141 -> V_269 & 0xfc00 ) == 0x0400 )
V_141 -> V_269 ^= V_270 | 0x0400 ;
return F_216 ( & V_2 -> V_271 , V_141 , V_263 ) ;
}
static void F_90 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
V_10 -> V_55 = V_2 -> V_7 ;
F_217 ( V_10 -> V_55 , & V_10 -> V_32 ,
F_13 , V_272 ) ;
F_218 ( V_10 ) ;
}
static void F_219 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_56 (channel, efx)
F_90 ( V_10 ) ;
}
static void F_91 ( struct V_9 * V_10 )
{
if ( V_10 -> V_55 ) {
F_220 ( & V_10 -> V_32 ) ;
F_221 ( & V_10 -> V_32 ) ;
}
V_10 -> V_55 = NULL ;
}
static void F_222 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_56 (channel, efx)
F_91 ( V_10 ) ;
}
static void F_223 ( struct V_260 * V_7 )
{
struct V_1 * V_2 = F_212 ( V_7 ) ;
struct V_9 * V_10 ;
F_56 (channel, efx)
F_224 ( V_10 ) ;
}
static int F_225 ( struct V_30 * V_31 )
{
struct V_9 * V_10 =
F_14 ( V_31 , struct V_9 , V_32 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_11 = 4 ;
int V_273 , V_274 ;
if ( ! F_102 ( V_2 -> V_7 ) )
return V_275 ;
if ( ! F_226 ( V_10 ) )
return V_276 ;
V_273 = V_10 -> V_19 . V_274 ;
F_3 ( V_10 , V_11 ) ;
V_274 = V_10 -> V_19 . V_274 - V_273 ;
F_227 ( V_10 ) ;
return V_274 ;
}
int F_228 ( struct V_260 * V_7 )
{
struct V_1 * V_2 = F_212 ( V_7 ) ;
int V_42 ;
F_23 ( V_2 , V_45 , V_2 -> V_7 , L_66 ,
F_17 () ) ;
V_42 = F_1 ( V_2 ) ;
if ( V_42 )
return V_42 ;
if ( V_2 -> V_136 & V_144 )
return - V_277 ;
if ( F_229 ( V_2 ) && F_230 ( V_2 , V_104 ) )
return - V_8 ;
F_101 ( V_2 ) ;
F_94 ( V_2 ) ;
F_231 ( V_2 ) ;
return 0 ;
}
int F_232 ( struct V_260 * V_7 )
{
struct V_1 * V_2 = F_212 ( V_7 ) ;
F_23 ( V_2 , V_156 , V_2 -> V_7 , L_67 ,
F_17 () ) ;
F_88 ( V_2 ) ;
return 0 ;
}
static struct V_278 * F_233 ( struct V_260 * V_7 ,
struct V_278 * V_279 )
{
struct V_1 * V_2 = F_212 ( V_7 ) ;
F_201 ( & V_2 -> V_246 ) ;
V_2 -> type -> V_247 ( V_2 , NULL , V_279 ) ;
F_202 ( & V_2 -> V_246 ) ;
return V_279 ;
}
static void F_234 ( struct V_260 * V_7 )
{
struct V_1 * V_2 = F_212 ( V_7 ) ;
F_2 ( V_2 , V_280 , V_2 -> V_7 ,
L_68 ,
V_2 -> V_101 ) ;
F_80 ( V_2 , V_281 ) ;
}
static int F_235 ( struct V_260 * V_7 , int V_282 )
{
struct V_1 * V_2 = F_212 ( V_7 ) ;
int V_42 ;
V_42 = F_1 ( V_2 ) ;
if ( V_42 )
return V_42 ;
if ( V_282 > V_283 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_69 ,
V_282 , V_283 ) ;
return - V_234 ;
}
if ( V_282 < V_284 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_70 ,
V_282 , V_284 ) ;
return - V_234 ;
}
F_23 ( V_2 , V_6 , V_2 -> V_7 , L_71 , V_282 ) ;
F_87 ( V_2 ) ;
F_88 ( V_2 ) ;
F_116 ( & V_2 -> V_137 ) ;
V_7 -> V_79 = V_282 ;
F_109 ( V_2 ) ;
F_117 ( & V_2 -> V_137 ) ;
F_94 ( V_2 ) ;
F_95 ( V_2 -> V_7 ) ;
return 0 ;
}
static int F_236 ( struct V_260 * V_7 , void * V_141 )
{
struct V_1 * V_2 = F_212 ( V_7 ) ;
struct V_285 * V_286 = V_141 ;
T_4 * V_287 = V_286 -> V_288 ;
T_4 V_289 [ 6 ] ;
int V_42 ;
if ( ! F_237 ( V_287 ) ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_72 ,
V_287 ) ;
return - V_290 ;
}
F_120 ( V_289 , V_7 -> V_146 ) ;
F_120 ( V_7 -> V_146 , V_287 ) ;
if ( V_2 -> type -> V_291 ) {
V_42 = V_2 -> type -> V_291 ( V_2 ) ;
if ( V_42 ) {
F_120 ( V_7 -> V_146 , V_289 ) ;
return V_42 ;
}
}
F_116 ( & V_2 -> V_137 ) ;
F_109 ( V_2 ) ;
F_117 ( & V_2 -> V_137 ) ;
return 0 ;
}
static void F_238 ( struct V_260 * V_7 )
{
struct V_1 * V_2 = F_212 ( V_7 ) ;
if ( V_2 -> V_101 )
F_239 ( V_2 -> V_240 , & V_2 -> V_142 ) ;
}
static int F_240 ( struct V_260 * V_7 , T_2 V_141 )
{
struct V_1 * V_2 = F_212 ( V_7 ) ;
int V_42 ;
if ( V_7 -> V_73 & ~ V_141 & V_223 ) {
V_42 = V_2 -> type -> V_292 ( V_2 , V_293 ) ;
if ( V_42 )
return V_42 ;
}
if ( ( V_7 -> V_73 ^ V_141 ) & V_294 ) {
F_238 ( V_7 ) ;
}
return 0 ;
}
static int F_241 ( struct V_260 * V_7 , T_7 V_295 , T_8 V_296 )
{
struct V_1 * V_2 = F_212 ( V_7 ) ;
if ( V_2 -> type -> V_297 )
return V_2 -> type -> V_297 ( V_2 , V_295 , V_296 ) ;
else
return - V_298 ;
}
static int F_242 ( struct V_260 * V_7 , T_7 V_295 , T_8 V_296 )
{
struct V_1 * V_2 = F_212 ( V_7 ) ;
if ( V_2 -> type -> V_299 )
return V_2 -> type -> V_299 ( V_2 , V_295 , V_296 ) ;
else
return - V_298 ;
}
static void F_243 ( struct V_1 * V_2 )
{
strcpy ( V_2 -> V_68 , V_2 -> V_7 -> V_68 ) ;
F_244 ( V_2 ) ;
F_55 ( V_2 ) ;
}
static int F_245 ( struct V_300 * V_301 ,
unsigned long V_302 , void * V_303 )
{
struct V_260 * V_7 = F_246 ( V_303 ) ;
if ( ( V_7 -> V_304 == & V_305 ) &&
V_302 == V_306 )
F_243 ( F_212 ( V_7 ) ) ;
return V_307 ;
}
static T_9
F_247 ( struct V_308 * V_175 , struct V_309 * V_310 , char * V_64 )
{
struct V_1 * V_2 = F_248 ( F_249 ( V_175 ) ) ;
return sprintf ( V_64 , L_73 , V_2 -> V_311 ) ;
}
static T_9 F_250 ( struct V_308 * V_175 , struct V_309 * V_310 ,
char * V_64 )
{
struct V_1 * V_2 = F_248 ( F_249 ( V_175 ) ) ;
struct V_312 * V_313 = F_251 ( V_2 ) ;
return F_252 ( V_64 , V_83 , L_73 , V_313 -> V_314 ) ;
}
static T_9 F_253 ( struct V_308 * V_175 , struct V_309 * V_310 ,
const char * V_64 , T_1 V_183 )
{
struct V_1 * V_2 = F_248 ( F_249 ( V_175 ) ) ;
struct V_312 * V_313 = F_251 ( V_2 ) ;
bool V_315 = V_183 > 0 && * V_64 != '0' ;
V_313 -> V_314 = V_315 ;
return V_183 ;
}
static int F_254 ( struct V_1 * V_2 )
{
struct V_260 * V_7 = V_2 -> V_7 ;
struct V_9 * V_10 ;
int V_42 ;
V_7 -> V_316 = 5 * V_317 ;
V_7 -> V_201 = V_2 -> V_167 -> V_201 ;
V_7 -> V_304 = & V_305 ;
if ( F_200 ( V_2 ) >= V_318 )
V_7 -> V_319 |= V_320 ;
V_7 -> V_321 = & V_322 ;
V_7 -> V_323 = V_324 ;
F_255 () ;
V_2 -> V_3 = V_325 ;
F_256 () ;
if ( V_2 -> V_238 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 ,
L_74 ) ;
V_42 = - V_8 ;
goto V_326;
}
V_42 = F_257 ( V_7 , V_7 -> V_68 ) ;
if ( V_42 < 0 )
goto V_326;
F_243 ( V_2 ) ;
F_105 ( V_7 ) ;
V_42 = F_258 ( V_7 ) ;
if ( V_42 )
goto V_326;
F_56 (channel, efx) {
struct V_12 * V_13 ;
F_5 (tx_queue, channel)
F_259 ( V_13 ) ;
}
F_132 ( V_2 ) ;
F_260 () ;
V_42 = F_261 ( & V_2 -> V_167 -> V_175 , & V_327 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_75 ) ;
goto V_328;
}
#ifdef F_262
V_42 = F_261 ( & V_2 -> V_167 -> V_175 , & V_329 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_75 ) ;
goto V_330;
}
#endif
return 0 ;
#ifdef F_262
V_330:
F_263 ( & V_2 -> V_167 -> V_175 , & V_327 ) ;
#endif
V_328:
F_255 () ;
F_138 ( V_2 ) ;
F_264 ( V_7 ) ;
V_326:
V_2 -> V_3 = V_331 ;
F_260 () ;
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_76 ) ;
return V_42 ;
}
static void F_265 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_7 )
return;
F_77 ( F_212 ( V_2 -> V_7 ) != V_2 ) ;
if ( F_266 ( V_2 ) ) {
F_267 ( V_2 -> V_68 , F_136 ( V_2 -> V_167 ) , sizeof( V_2 -> V_68 ) ) ;
#ifdef F_262
F_263 ( & V_2 -> V_167 -> V_175 , & V_329 ) ;
#endif
F_263 ( & V_2 -> V_167 -> V_175 , & V_327 ) ;
F_268 ( V_2 -> V_7 ) ;
}
}
void F_269 ( struct V_1 * V_2 , enum V_332 V_333 )
{
F_76 ( V_2 ) ;
if ( V_333 == V_334 )
V_2 -> type -> V_335 ( V_2 ) ;
F_88 ( V_2 ) ;
F_176 ( V_2 ) ;
F_116 ( & V_2 -> V_137 ) ;
if ( V_2 -> V_151 && V_333 != V_336 &&
V_333 != V_337 )
V_2 -> V_148 -> V_155 ( V_2 ) ;
V_2 -> type -> V_155 ( V_2 ) ;
}
int F_270 ( struct V_1 * V_2 , enum V_332 V_333 , bool V_338 )
{
int V_42 ;
F_76 ( V_2 ) ;
if ( V_333 == V_334 )
V_2 -> type -> V_339 ( V_2 ) ;
V_42 = V_2 -> type -> V_149 ( V_2 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_77 ) ;
goto V_63;
}
if ( ! V_338 )
goto V_63;
if ( V_2 -> V_151 && V_333 != V_336 &&
V_333 != V_337 ) {
V_42 = V_2 -> V_148 -> V_149 ( V_2 ) ;
if ( V_42 )
goto V_63;
V_42 = V_2 -> V_148 -> V_152 ( V_2 ) ;
if ( V_42 && V_42 != - V_153 )
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_78 ) ;
}
V_42 = F_174 ( V_2 ) ;
if ( V_42 )
goto V_63;
#ifdef F_162
V_42 = V_2 -> type -> V_340 ( V_2 ) ;
if ( V_42 )
F_156 ( V_2 , V_36 , V_2 -> V_7 ,
L_79
L_61 , V_42 ) ;
#endif
F_110 ( & V_2 -> V_133 ) ;
F_196 ( V_2 ) ;
F_111 ( & V_2 -> V_133 ) ;
if ( V_2 -> type -> V_341 )
V_2 -> type -> V_341 ( V_2 ) ;
F_117 ( & V_2 -> V_137 ) ;
F_94 ( V_2 ) ;
return 0 ;
V_63:
V_2 -> V_151 = false ;
F_117 ( & V_2 -> V_137 ) ;
return V_42 ;
}
int F_230 ( struct V_1 * V_2 , enum V_332 V_333 )
{
int V_42 , V_110 ;
bool V_342 ;
F_106 ( V_2 , V_6 , V_2 -> V_7 , L_80 ,
F_271 ( V_333 ) ) ;
F_87 ( V_2 ) ;
F_269 ( V_2 , V_333 ) ;
V_42 = V_2 -> type -> V_343 ( V_2 , V_333 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_81 ) ;
goto V_115;
}
if ( V_333 < V_344 )
V_2 -> V_238 &= - ( 1 << ( V_333 + 1 ) ) ;
else
F_272 ( V_333 , & V_2 -> V_238 ) ;
F_141 ( V_2 -> V_167 ) ;
V_115:
V_342 = V_42 ||
V_333 == V_117 ||
V_333 == V_345 ;
V_110 = F_270 ( V_2 , V_333 , ! V_342 ) ;
if ( V_110 ) {
V_342 = true ;
if ( ! V_42 )
V_42 = V_110 ;
}
if ( V_342 ) {
F_273 ( V_2 -> V_7 ) ;
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_82 ) ;
V_2 -> V_3 = V_4 ;
} else {
F_23 ( V_2 , V_6 , V_2 -> V_7 , L_83 ) ;
F_95 ( V_2 -> V_7 ) ;
}
return V_42 ;
}
int F_274 ( struct V_1 * V_2 )
{
#ifdef F_275
struct V_346 * V_347 = F_276 ( V_2 -> V_167 ) ;
if ( F_277 ( V_347 ) ) {
return 1 ;
}
#endif
return 0 ;
}
static void F_278 ( struct V_1 * V_2 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_348 ; ++ V_46 ) {
if ( F_229 ( V_2 ) )
goto V_115;
F_279 ( V_349 ) ;
}
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_84 ) ;
V_115:
V_2 -> V_350 = false ;
}
static void F_280 ( struct V_140 * V_141 )
{
struct V_1 * V_2 = F_14 ( V_141 , struct V_1 , V_351 ) ;
unsigned long V_352 ;
enum V_332 V_333 ;
V_352 = F_281 ( V_2 -> V_238 ) ;
V_333 = F_282 ( V_352 ) - 1 ;
if ( V_333 == V_353 )
F_278 ( V_2 ) ;
if ( ( V_333 == V_345 ||
V_333 == V_354 ) &&
F_274 ( V_2 ) )
return;
if ( ! V_352 )
return;
F_255 () ;
if ( V_2 -> V_3 == V_325 )
( void ) F_230 ( V_2 , V_333 ) ;
F_260 () ;
}
void F_80 ( struct V_1 * V_2 , enum V_332 type )
{
enum V_332 V_333 ;
if ( V_2 -> V_3 == V_5 ) {
F_23 ( V_2 , V_6 , V_2 -> V_7 ,
L_85 ,
F_271 ( type ) ) ;
return;
}
switch ( type ) {
case V_336 :
case V_104 :
case V_354 :
case V_355 :
case V_117 :
case V_345 :
case V_337 :
case V_353 :
case V_334 :
V_333 = type ;
F_23 ( V_2 , V_6 , V_2 -> V_7 , L_86 ,
F_271 ( V_333 ) ) ;
break;
default:
V_333 = V_2 -> type -> V_356 ( type ) ;
F_23 ( V_2 , V_6 , V_2 -> V_7 ,
L_87 ,
F_271 ( V_333 ) , F_271 ( type ) ) ;
break;
}
F_283 ( V_333 , & V_2 -> V_238 ) ;
F_256 () ;
if ( F_281 ( V_2 -> V_3 ) != V_325 )
return;
F_171 ( V_2 ) ;
F_239 ( V_357 , & V_2 -> V_351 ) ;
}
int F_284 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_285 ( struct V_1 * V_2 ) {}
static bool F_286 ( struct V_1 * V_2 )
{
return false ;
}
static int F_287 ( struct V_1 * V_2 ,
struct V_167 * V_167 , struct V_260 * V_7 )
{
int V_46 ;
F_288 ( & V_2 -> V_165 ) ;
F_288 ( & V_2 -> V_168 ) ;
F_189 ( & V_2 -> V_358 ) ;
#ifdef F_289
F_288 ( & V_2 -> V_359 ) ;
#endif
F_290 ( & V_2 -> V_351 , F_280 ) ;
F_291 ( & V_2 -> V_157 , F_209 ) ;
F_291 ( & V_2 -> V_360 , V_361 ) ;
V_2 -> V_167 = V_167 ;
V_2 -> V_362 = V_363 ;
V_2 -> V_3 = V_331 ;
F_267 ( V_2 -> V_68 , F_136 ( V_167 ) , sizeof( V_2 -> V_68 ) ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_78 = V_2 -> type -> V_78 ;
V_2 -> V_82 =
V_89 ? ( V_2 -> V_78 + V_89 ) % 4 : 0 ;
V_2 -> V_364 =
V_2 -> type -> V_365 - V_2 -> type -> V_78 ;
V_2 -> V_366 =
V_2 -> type -> V_367 - V_2 -> type -> V_78 ;
F_189 ( & V_2 -> V_246 ) ;
F_292 ( & V_2 -> V_137 ) ;
V_2 -> V_148 = & V_368 ;
V_2 -> V_271 . V_175 = V_7 ;
F_290 ( & V_2 -> V_142 , F_118 ) ;
F_293 ( & V_2 -> V_369 ) ;
for ( V_46 = 0 ; V_46 < V_107 ; V_46 ++ ) {
V_2 -> V_10 [ V_46 ] = F_43 ( V_2 , V_46 , NULL ) ;
if ( ! V_2 -> V_10 [ V_46 ] )
goto V_63;
V_2 -> V_70 [ V_46 ] . V_2 = V_2 ;
V_2 -> V_70 [ V_46 ] . V_112 = V_46 ;
}
V_2 -> V_190 = F_26 ( V_2 -> type -> V_370 ,
V_190 ) ;
snprintf ( V_2 -> V_371 , sizeof( V_2 -> V_371 ) , L_88 ,
F_136 ( V_167 ) ) ;
V_2 -> V_240 = F_294 ( V_2 -> V_371 ) ;
if ( ! V_2 -> V_240 )
goto V_63;
return 0 ;
V_63:
F_295 ( V_2 ) ;
return - V_114 ;
}
static void F_295 ( struct V_1 * V_2 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_107 ; V_46 ++ )
F_92 ( V_2 -> V_10 [ V_46 ] ) ;
F_92 ( V_2 -> V_161 ) ;
if ( V_2 -> V_240 ) {
F_296 ( V_2 -> V_240 ) ;
V_2 -> V_240 = NULL ;
}
}
void F_297 ( struct V_1 * V_2 , T_10 * V_279 )
{
T_10 V_372 = 0 ;
struct V_9 * V_10 ;
F_56 (channel, efx)
V_372 += V_10 -> V_372 ;
V_279 [ V_373 ] = V_372 ;
V_279 [ V_374 ] = F_298 ( & V_2 -> V_375 ) ;
}
static void F_299 ( struct V_1 * V_2 )
{
F_77 ( V_2 -> V_3 == V_325 ) ;
F_128 ( & V_2 -> V_351 ) ;
F_176 ( V_2 ) ;
F_300 ( V_2 ) ;
F_129 ( V_2 ) ;
V_2 -> type -> V_155 ( V_2 ) ;
F_222 ( V_2 ) ;
F_204 ( V_2 ) ;
}
static void F_301 ( struct V_167 * V_167 )
{
struct V_1 * V_2 ;
V_2 = F_248 ( V_167 ) ;
if ( ! V_2 )
return;
F_255 () ;
F_138 ( V_2 ) ;
F_273 ( V_2 -> V_7 ) ;
F_176 ( V_2 ) ;
V_2 -> V_3 = V_331 ;
F_260 () ;
if ( V_2 -> type -> V_376 )
V_2 -> type -> V_376 ( V_2 ) ;
F_265 ( V_2 ) ;
F_302 ( V_2 ) ;
F_299 ( V_2 ) ;
F_148 ( V_2 ) ;
F_23 ( V_2 , V_6 , V_2 -> V_7 , L_89 ) ;
F_295 ( V_2 ) ;
F_303 ( V_2 -> V_7 ) ;
F_304 ( V_167 ) ;
}
static void F_305 ( struct V_1 * V_2 )
{
struct V_167 * V_175 = V_2 -> V_167 ;
char V_377 [ V_378 ] ;
T_9 V_379 ;
int V_380 , V_381 , V_46 , V_48 ;
V_379 = F_306 ( V_175 , 0 , sizeof( V_377 ) , V_377 ) ;
if ( V_379 <= 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_90 ) ;
return;
}
V_380 = F_307 ( V_377 , 0 , V_379 , V_382 ) ;
if ( V_380 < 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_91 ) ;
return;
}
V_381 = F_308 ( & V_377 [ V_380 ] ) ;
V_48 = V_381 ;
V_46 = V_380 + V_383 ;
if ( V_46 + V_48 > V_379 )
V_48 = V_379 - V_46 ;
V_46 = F_309 ( V_377 , V_46 , V_48 , L_92 ) ;
if ( V_46 < 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_93 ) ;
return;
}
V_48 = F_310 ( & V_377 [ V_46 ] ) ;
V_46 += V_384 ;
if ( V_46 + V_48 > V_379 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_94 ) ;
return;
}
F_106 ( V_2 , V_6 , V_2 -> V_7 ,
L_95 , V_48 , & V_377 [ V_46 ] ) ;
V_46 = V_380 + V_383 ;
V_48 = V_381 ;
V_46 = F_309 ( V_377 , V_46 , V_48 , L_96 ) ;
if ( V_46 < 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_97 ) ;
return;
}
V_48 = F_310 ( & V_377 [ V_46 ] ) ;
V_46 += V_384 ;
if ( V_46 + V_48 > V_379 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_98 ) ;
return;
}
V_2 -> V_161 = F_47 ( V_48 + 1 , V_49 ) ;
if ( ! V_2 -> V_161 )
return;
snprintf ( V_2 -> V_161 , V_48 + 1 , L_99 , & V_377 [ V_46 ] ) ;
}
static int F_311 ( struct V_1 * V_2 )
{
int V_42 ;
V_42 = F_197 ( V_2 ) ;
if ( V_42 )
goto V_150;
F_219 ( V_2 ) ;
V_42 = V_2 -> type -> V_149 ( V_2 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 ,
L_77 ) ;
goto V_177;
}
V_42 = F_121 ( V_2 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 ,
L_100 ) ;
goto V_179;
}
V_42 = F_312 ( V_2 ) ;
if ( V_42 )
goto V_236;
V_42 = F_174 ( V_2 ) ;
if ( V_42 )
goto V_385;
return 0 ;
V_385:
F_300 ( V_2 ) ;
V_236:
F_129 ( V_2 ) ;
V_179:
V_2 -> type -> V_155 ( V_2 ) ;
V_177:
F_222 ( V_2 ) ;
F_204 ( V_2 ) ;
V_150:
return V_42 ;
}
static int F_313 ( struct V_167 * V_167 ,
const struct V_386 * V_196 )
{
struct V_260 * V_7 ;
struct V_1 * V_2 ;
int V_42 ;
V_7 = F_314 ( sizeof( * V_2 ) , V_387 ,
V_388 ) ;
if ( ! V_7 )
return - V_114 ;
V_2 = F_212 ( V_7 ) ;
V_2 -> type = ( const struct V_389 * ) V_196 -> V_390 ;
V_2 -> V_95 |= V_391 ;
V_7 -> V_73 |= ( V_2 -> type -> V_222 | V_392 |
V_393 | V_394 ) ;
if ( V_2 -> type -> V_222 & ( V_395 | V_396 ) )
V_7 -> V_73 |= V_397 ;
V_7 -> V_398 |= ( V_396 | V_392 |
V_391 | V_399 |
V_394 ) ;
V_7 -> V_94 = V_7 -> V_73 & ~ V_2 -> V_95 ;
V_7 -> V_73 &= ~ V_294 ;
V_7 -> V_73 |= V_2 -> V_95 ;
F_315 ( V_167 , V_2 ) ;
F_316 ( V_7 , & V_167 -> V_175 ) ;
V_42 = F_287 ( V_2 , V_167 , V_7 ) ;
if ( V_42 )
goto V_150;
F_106 ( V_2 , V_36 , V_2 -> V_7 ,
L_101 ) ;
if ( ! V_2 -> type -> V_400 )
F_305 ( V_2 ) ;
V_42 = F_139 ( V_2 ) ;
if ( V_42 )
goto V_154;
V_42 = F_311 ( V_2 ) ;
if ( V_42 )
goto V_177;
V_42 = F_254 ( V_2 ) ;
if ( V_42 )
goto V_179;
if ( V_2 -> type -> V_401 ) {
V_42 = V_2 -> type -> V_401 ( V_2 ) ;
if ( V_42 )
F_2 ( V_2 , V_36 , V_2 -> V_7 ,
L_102 , V_42 ) ;
}
F_23 ( V_2 , V_36 , V_2 -> V_7 , L_103 ) ;
F_255 () ;
V_42 = F_317 ( V_2 ) ;
F_260 () ;
if ( V_42 && V_42 != - V_153 )
F_156 ( V_2 , V_36 , V_2 -> V_7 ,
L_104 , V_42 ) ;
V_42 = F_318 ( V_167 ) ;
if ( V_42 && V_42 != - V_234 )
F_319 ( V_2 , V_36 , V_2 -> V_7 ,
L_105 ,
V_42 ) ;
return 0 ;
V_179:
F_299 ( V_2 ) ;
V_177:
F_148 ( V_2 ) ;
V_154:
F_295 ( V_2 ) ;
V_150:
F_71 ( V_42 > 0 ) ;
F_23 ( V_2 , V_6 , V_2 -> V_7 , L_106 , V_42 ) ;
F_303 ( V_7 ) ;
return V_42 ;
}
static int F_320 ( struct V_167 * V_175 , int V_402 )
{
int V_42 ;
struct V_1 * V_2 = F_248 ( V_175 ) ;
if ( V_2 -> type -> V_403 ) {
V_42 = V_2 -> type -> V_403 ( V_2 , V_402 ) ;
if ( V_42 )
return V_42 ;
else
return V_402 ;
} else
return - V_298 ;
}
static int F_321 ( struct V_308 * V_175 )
{
struct V_1 * V_2 = F_248 ( F_249 ( V_175 ) ) ;
F_255 () ;
if ( V_2 -> V_3 != V_4 ) {
V_2 -> V_3 = V_331 ;
F_87 ( V_2 ) ;
F_88 ( V_2 ) ;
F_176 ( V_2 ) ;
}
F_260 () ;
return 0 ;
}
static int F_322 ( struct V_308 * V_175 )
{
int V_42 ;
struct V_1 * V_2 = F_248 ( F_249 ( V_175 ) ) ;
F_255 () ;
if ( V_2 -> V_3 != V_4 ) {
V_42 = F_174 ( V_2 ) ;
if ( V_42 )
goto V_63;
F_116 ( & V_2 -> V_137 ) ;
V_2 -> V_148 -> V_152 ( V_2 ) ;
F_117 ( & V_2 -> V_137 ) ;
F_94 ( V_2 ) ;
F_95 ( V_2 -> V_7 ) ;
V_2 -> V_3 = V_325 ;
V_2 -> type -> V_404 ( V_2 ) ;
}
F_260 () ;
F_239 ( V_357 , & V_2 -> V_351 ) ;
return 0 ;
V_63:
F_260 () ;
return V_42 ;
}
static int F_323 ( struct V_308 * V_175 )
{
struct V_167 * V_167 = F_249 ( V_175 ) ;
struct V_1 * V_2 = F_248 ( V_167 ) ;
V_2 -> type -> V_155 ( V_2 ) ;
V_2 -> V_238 = 0 ;
F_324 ( V_167 ) ;
return F_325 ( V_167 , V_405 ) ;
}
static int F_326 ( struct V_308 * V_175 )
{
struct V_167 * V_167 = F_249 ( V_175 ) ;
struct V_1 * V_2 = F_248 ( V_167 ) ;
int V_42 ;
V_42 = F_325 ( V_167 , V_406 ) ;
if ( V_42 )
return V_42 ;
F_327 ( V_167 ) ;
V_42 = F_140 ( V_167 ) ;
if ( V_42 )
return V_42 ;
F_141 ( V_2 -> V_167 ) ;
V_42 = V_2 -> type -> V_343 ( V_2 , V_104 ) ;
if ( V_42 )
return V_42 ;
V_42 = V_2 -> type -> V_149 ( V_2 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_322 ( V_175 ) ;
return V_42 ;
}
static int F_328 ( struct V_308 * V_175 )
{
int V_42 ;
F_321 ( V_175 ) ;
V_42 = F_323 ( V_175 ) ;
if ( V_42 )
F_326 ( V_175 ) ;
return V_42 ;
}
static T_11 F_329 ( struct V_167 * V_407 ,
enum V_408 V_3 )
{
T_11 V_409 = V_410 ;
struct V_1 * V_2 = F_248 ( V_407 ) ;
if ( V_3 == V_411 )
return V_412 ;
F_255 () ;
if ( V_2 -> V_3 != V_4 ) {
V_2 -> V_3 = V_5 ;
V_2 -> V_238 = 0 ;
F_87 ( V_2 ) ;
F_88 ( V_2 ) ;
F_176 ( V_2 ) ;
V_409 = V_413 ;
} else {
V_409 = V_410 ;
}
F_260 () ;
F_147 ( V_407 ) ;
return V_409 ;
}
static T_11 F_330 ( struct V_167 * V_407 )
{
struct V_1 * V_2 = F_248 ( V_407 ) ;
T_11 V_409 = V_410 ;
int V_42 ;
if ( F_140 ( V_407 ) ) {
F_2 ( V_2 , V_414 , V_2 -> V_7 ,
L_107 ) ;
V_409 = V_412 ;
}
V_42 = F_331 ( V_407 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_414 , V_2 -> V_7 ,
L_108 , V_42 ) ;
}
return V_409 ;
}
static void F_332 ( struct V_167 * V_407 )
{
struct V_1 * V_2 = F_248 ( V_407 ) ;
int V_42 ;
F_255 () ;
if ( V_2 -> V_3 == V_4 )
goto V_115;
V_42 = F_230 ( V_2 , V_104 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_414 , V_2 -> V_7 ,
L_109 , V_42 ) ;
} else {
V_2 -> V_3 = V_325 ;
F_23 ( V_2 , V_414 , V_2 -> V_7 ,
L_110 ) ;
}
V_115:
F_260 () ;
}
static int T_12 F_333 ( void )
{
int V_42 ;
F_334 ( V_415 L_111 V_416 L_112 ) ;
V_42 = F_335 ( & V_417 ) ;
if ( V_42 )
goto V_418;
#ifdef F_162
V_42 = F_336 () ;
if ( V_42 )
goto V_419;
#endif
V_357 = F_294 ( L_113 ) ;
if ( ! V_357 ) {
V_42 = - V_114 ;
goto V_420;
}
V_42 = F_337 ( & V_421 ) ;
if ( V_42 < 0 )
goto V_422;
return 0 ;
V_422:
F_296 ( V_357 ) ;
V_420:
#ifdef F_162
F_338 () ;
V_419:
#endif
F_339 ( & V_417 ) ;
V_418:
return V_42 ;
}
static void T_13 F_340 ( void )
{
F_334 ( V_415 L_114 ) ;
F_341 ( & V_421 ) ;
F_296 ( V_357 ) ;
#ifdef F_162
F_338 () ;
#endif
F_339 ( & V_417 ) ;
}

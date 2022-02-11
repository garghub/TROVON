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
if ( F_72 ( V_2 -> V_7 ) )
F_73 ( V_2 -> V_7 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_12 * V_13 ;
struct V_18 * V_19 ;
int V_42 ;
F_75 ( V_2 ) ;
F_76 ( V_2 -> V_101 ) ;
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
if ( V_42 && F_77 ( V_2 ) ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_16 ) ;
F_78 ( V_2 , V_104 ) ;
} else if ( V_42 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_17 ) ;
} else {
F_23 ( V_2 , V_6 , V_2 -> V_7 ,
L_18 ) ;
}
F_56 (channel, efx) {
F_51 (rx_queue, channel)
F_79 ( V_19 ) ;
F_80 (tx_queue, channel)
F_81 ( V_13 ) ;
}
}
static void F_53 ( struct V_9 * V_10 )
{
struct V_12 * V_13 ;
struct V_18 * V_19 ;
F_23 ( V_10 -> V_2 , V_6 , V_10 -> V_2 -> V_7 ,
L_19 , V_10 -> V_10 ) ;
F_51 (rx_queue, channel)
F_82 ( V_19 ) ;
F_80 (tx_queue, channel)
F_83 ( V_13 ) ;
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
F_84 ( struct V_1 * V_2 , T_3 V_37 , T_3 V_38 )
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
F_85 ( V_2 ) ;
F_86 ( V_2 ) ;
F_87 ( V_2 ) ;
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
F_88 ( V_2 -> V_10 [ V_46 ] ) ;
}
V_115:
for ( V_46 = 0 ; V_46 < V_2 -> V_113 ; V_46 ++ ) {
V_10 = V_106 [ V_46 ] ;
if ( V_10 && V_10 -> type -> V_111 ) {
F_89 ( V_10 ) ;
F_53 ( V_10 ) ;
F_90 ( V_10 ) ;
}
}
V_110 = F_91 ( V_2 ) ;
if ( V_110 ) {
V_42 = V_42 ? V_42 : V_110 ;
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_20 ) ;
F_78 ( V_2 , V_117 ) ;
} else {
F_92 ( V_2 ) ;
F_93 ( V_2 -> V_7 ) ;
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
void F_94 ( struct V_18 * V_19 )
{
F_95 ( & V_19 -> V_53 , V_118 + F_96 ( 100 ) ) ;
}
int F_97 ( struct V_9 * V_10 )
{
return 0 ;
}
void F_98 ( struct V_9 * V_10 )
{
}
void F_99 ( struct V_1 * V_2 )
{
struct V_119 * V_120 = & V_2 -> V_120 ;
if ( ! F_100 ( V_2 -> V_7 ) )
return;
if ( V_120 -> V_121 != F_101 ( V_2 -> V_7 ) ) {
V_2 -> V_122 ++ ;
if ( V_120 -> V_121 )
F_102 ( V_2 -> V_7 ) ;
else
F_103 ( V_2 -> V_7 ) ;
}
if ( V_120 -> V_121 )
F_104 ( V_2 , V_123 , V_2 -> V_7 ,
L_21 ,
V_120 -> V_124 , V_120 -> V_125 ? L_22 : L_23 ,
V_2 -> V_7 -> V_79 ) ;
else
F_104 ( V_2 , V_123 , V_2 -> V_7 , L_24 ) ;
}
void F_105 ( struct V_1 * V_2 , T_3 V_126 )
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
void F_106 ( struct V_1 * V_2 , T_4 V_129 )
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
void F_107 ( struct V_1 * V_2 )
{
F_108 ( & V_2 -> V_133 ) ;
V_2 -> type -> V_134 ( V_2 ) ;
F_109 ( & V_2 -> V_133 ) ;
}
int F_110 ( struct V_1 * V_2 )
{
enum V_135 V_136 ;
int V_42 ;
F_71 ( ! F_111 ( & V_2 -> V_137 ) ) ;
V_136 = V_2 -> V_136 ;
if ( F_112 ( V_2 ) )
V_2 -> V_136 |= V_138 ;
else
V_2 -> V_136 &= ~ V_138 ;
V_42 = V_2 -> type -> V_139 ( V_2 ) ;
if ( V_42 )
V_2 -> V_136 = V_136 ;
return V_42 ;
}
int F_113 ( struct V_1 * V_2 )
{
int V_42 ;
F_75 ( V_2 ) ;
F_114 ( & V_2 -> V_137 ) ;
V_42 = F_110 ( V_2 ) ;
F_115 ( & V_2 -> V_137 ) ;
return V_42 ;
}
static void F_116 ( struct V_140 * V_141 )
{
struct V_1 * V_2 = F_14 ( V_141 , struct V_1 , V_142 ) ;
F_114 ( & V_2 -> V_137 ) ;
if ( V_2 -> V_101 )
F_107 ( V_2 ) ;
F_115 ( & V_2 -> V_137 ) ;
}
static int F_117 ( struct V_1 * V_2 )
{
int V_42 ;
F_23 ( V_2 , V_36 , V_2 -> V_7 , L_25 ) ;
if ( V_143 )
V_2 -> V_136 = V_144 ;
V_42 = V_2 -> type -> V_145 ( V_2 ) ;
if ( V_42 )
return V_42 ;
F_118 ( V_2 -> V_7 -> V_146 , V_2 -> V_7 -> V_147 ) ;
return 0 ;
}
static int F_119 ( struct V_1 * V_2 )
{
int V_42 ;
F_23 ( V_2 , V_6 , V_2 -> V_7 , L_26 ) ;
F_114 ( & V_2 -> V_137 ) ;
V_42 = V_2 -> V_148 -> V_149 ( V_2 ) ;
if ( V_42 )
goto V_150;
V_2 -> V_151 = true ;
F_107 ( V_2 ) ;
V_42 = V_2 -> V_148 -> V_152 ( V_2 ) ;
if ( V_42 && V_42 != - V_153 )
goto V_154;
F_115 ( & V_2 -> V_137 ) ;
return 0 ;
V_154:
V_2 -> V_148 -> V_155 ( V_2 ) ;
V_150:
F_115 ( & V_2 -> V_137 ) ;
return V_42 ;
}
static void F_120 ( struct V_1 * V_2 )
{
F_23 ( V_2 , V_45 , V_2 -> V_7 , L_27 ) ;
F_76 ( V_2 -> V_101 ) ;
F_114 ( & V_2 -> V_137 ) ;
V_2 -> V_101 = true ;
F_107 ( V_2 ) ;
F_115 ( & V_2 -> V_137 ) ;
}
static void F_121 ( struct V_1 * V_2 )
{
F_23 ( V_2 , V_156 , V_2 -> V_7 , L_28 ) ;
F_75 ( V_2 ) ;
F_114 ( & V_2 -> V_137 ) ;
V_2 -> V_101 = false ;
F_115 ( & V_2 -> V_137 ) ;
F_122 ( V_2 -> V_7 ) ;
F_123 ( V_2 -> V_7 ) ;
F_124 ( & V_2 -> V_157 ) ;
F_125 ( V_2 ) ;
F_126 ( & V_2 -> V_142 ) ;
}
static void F_127 ( struct V_1 * V_2 )
{
F_23 ( V_2 , V_6 , V_2 -> V_7 , L_29 ) ;
if ( ! V_2 -> V_151 )
return;
V_2 -> V_148 -> V_155 ( V_2 ) ;
V_2 -> V_151 = false ;
V_2 -> V_120 . V_121 = false ;
F_99 ( V_2 ) ;
}
static void F_128 ( struct V_1 * V_2 )
{
F_23 ( V_2 , V_6 , V_2 -> V_7 , L_30 ) ;
V_2 -> type -> V_158 ( V_2 ) ;
}
static bool F_129 ( struct V_1 * V_159 , struct V_1 * V_160 )
{
return V_159 -> type == V_160 -> type &&
V_159 -> V_161 && V_160 -> V_161 &&
! strcmp ( V_159 -> V_161 , V_160 -> V_161 ) ;
}
static void F_130 ( struct V_1 * V_2 )
{
struct V_1 * V_162 , * V_163 ;
if ( V_2 -> V_164 == V_2 ) {
F_23 ( V_2 , V_36 , V_2 -> V_7 , L_31 ) ;
F_131 ( & V_2 -> V_165 , & V_166 ) ;
F_132 (other, next, &ef4_unassociated_list,
node) {
if ( F_129 ( V_2 , V_162 ) ) {
F_133 ( & V_162 -> V_165 ) ;
F_23 ( V_162 , V_36 , V_162 -> V_7 ,
L_32 ,
F_134 ( V_2 -> V_167 ) ,
V_2 -> V_7 -> V_68 ) ;
F_131 ( & V_162 -> V_165 ,
& V_2 -> V_168 ) ;
V_162 -> V_164 = V_2 ;
}
}
} else {
F_135 (other, &ef4_primary_list, node) {
if ( F_129 ( V_2 , V_162 ) ) {
F_23 ( V_2 , V_36 , V_2 -> V_7 ,
L_33 ,
F_134 ( V_162 -> V_167 ) ,
V_162 -> V_7 -> V_68 ) ;
F_131 ( & V_2 -> V_165 ,
& V_162 -> V_168 ) ;
V_2 -> V_164 = V_162 ;
return;
}
}
F_23 ( V_2 , V_36 , V_2 -> V_7 ,
L_34 ) ;
F_131 ( & V_2 -> V_165 , & V_169 ) ;
}
}
static void F_136 ( struct V_1 * V_2 )
{
struct V_1 * V_162 , * V_163 ;
F_133 ( & V_2 -> V_165 ) ;
V_2 -> V_164 = NULL ;
F_132 (other, next, &efx->secondary_list, node) {
F_133 ( & V_162 -> V_165 ) ;
F_23 ( V_162 , V_36 , V_162 -> V_7 ,
L_35 ) ;
F_131 ( & V_162 -> V_165 , & V_169 ) ;
V_162 -> V_164 = NULL ;
}
}
static int F_137 ( struct V_1 * V_2 )
{
struct V_167 * V_167 = V_2 -> V_167 ;
T_5 V_170 = V_2 -> type -> V_171 ;
unsigned int V_172 = V_2 -> type -> V_172 ( V_2 ) ;
int V_42 , V_173 ;
F_23 ( V_2 , V_36 , V_2 -> V_7 , L_36 ) ;
V_173 = V_2 -> type -> V_174 ;
V_42 = F_138 ( V_167 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 ,
L_37 ) ;
goto V_150;
}
F_139 ( V_167 ) ;
while ( V_170 > 0x7fffffffUL ) {
V_42 = F_140 ( & V_167 -> V_175 , V_170 ) ;
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
V_2 -> V_176 = F_141 ( V_2 -> V_167 , V_173 ) ;
V_42 = F_142 ( V_167 , V_173 , L_40 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 ,
L_41 ) ;
V_42 = - V_8 ;
goto V_177;
}
V_2 -> V_178 = F_143 ( V_2 -> V_176 , V_172 ) ;
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
F_144 ( V_2 -> V_167 , V_173 ) ;
V_177:
V_2 -> V_176 = 0 ;
V_154:
F_145 ( V_2 -> V_167 ) ;
V_150:
return V_42 ;
}
static void F_146 ( struct V_1 * V_2 )
{
int V_173 ;
F_23 ( V_2 , V_6 , V_2 -> V_7 , L_44 ) ;
if ( V_2 -> V_178 ) {
F_147 ( V_2 -> V_178 ) ;
V_2 -> V_178 = NULL ;
}
if ( V_2 -> V_176 ) {
V_173 = V_2 -> type -> V_174 ;
F_144 ( V_2 -> V_167 , V_173 ) ;
V_2 -> V_176 = 0 ;
}
if ( ! F_148 ( V_2 -> V_167 ) )
F_145 ( V_2 -> V_167 ) ;
}
void F_149 ( struct V_1 * V_2 )
{
T_1 V_46 ;
for ( V_46 = 0 ; V_46 < F_150 ( V_2 -> V_180 ) ; V_46 ++ )
V_2 -> V_180 [ V_46 ] =
F_151 ( V_46 , V_2 -> V_181 ) ;
}
static unsigned int F_152 ( struct V_1 * V_2 )
{
T_6 V_182 ;
unsigned int V_183 ;
int V_184 ;
if ( V_185 ) {
V_183 = V_185 ;
} else {
if ( F_4 ( ! F_153 ( & V_182 , V_49 ) ) ) {
F_154 ( V_2 , V_36 , V_2 -> V_7 ,
L_45 ) ;
return 1 ;
}
V_183 = 0 ;
F_155 (cpu) {
if ( ! F_156 ( V_184 , V_182 ) ) {
++ V_183 ;
F_157 ( V_182 , V_182 ,
F_158 ( V_184 ) ) ;
}
}
F_159 ( V_182 ) ;
}
return V_183 ;
}
static int F_160 ( struct V_1 * V_2 )
{
unsigned int V_186 = 0 ;
unsigned int V_46 , V_48 ;
int V_42 ;
for ( V_46 = 0 ; V_46 < V_187 ; V_46 ++ )
if ( V_2 -> V_188 [ V_46 ] )
++ V_186 ;
if ( V_2 -> V_189 == V_190 ) {
struct V_191 V_192 [ V_107 ] ;
unsigned int V_113 ;
V_113 = F_152 ( V_2 ) ;
if ( V_193 )
V_113 *= 2 ;
V_113 += V_186 ;
V_113 = F_161 ( V_113 , V_2 -> V_194 ) ;
for ( V_46 = 0 ; V_46 < V_113 ; V_46 ++ )
V_192 [ V_46 ] . V_195 = V_46 ;
V_42 = F_162 ( V_2 -> V_167 ,
V_192 , 1 , V_113 ) ;
if ( V_42 < 0 ) {
V_2 -> V_189 = V_196 ;
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_46 ) ;
} else if ( V_42 < V_113 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_47
L_48 , V_42 , V_113 ) ;
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_49 ) ;
V_113 = V_42 ;
}
if ( V_42 > 0 ) {
V_2 -> V_113 = V_113 ;
if ( V_113 > V_186 )
V_113 -= V_186 ;
if ( V_193 ) {
V_2 -> V_197 = F_161 ( F_26 ( V_113 / 2 ,
1U ) ,
V_2 -> V_198 ) ;
V_2 -> V_199 = F_26 ( V_113 -
V_2 -> V_197 ,
1U ) ;
} else {
V_2 -> V_197 = F_161 ( V_113 ,
V_2 -> V_198 ) ;
V_2 -> V_199 = V_113 ;
}
for ( V_46 = 0 ; V_46 < V_2 -> V_113 ; V_46 ++ )
F_163 ( V_2 , V_46 ) -> V_200 =
V_192 [ V_46 ] . V_201 ;
}
}
if ( V_2 -> V_189 == V_196 ) {
V_2 -> V_113 = 1 ;
V_2 -> V_199 = 1 ;
V_2 -> V_197 = 1 ;
V_42 = F_164 ( V_2 -> V_167 ) ;
if ( V_42 == 0 ) {
F_163 ( V_2 , 0 ) -> V_200 = V_2 -> V_167 -> V_200 ;
} else {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_50 ) ;
V_2 -> V_189 = V_202 ;
}
}
if ( V_2 -> V_189 == V_202 ) {
V_2 -> V_113 = 1 + ( V_193 ? 1 : 0 ) ;
V_2 -> V_199 = 1 ;
V_2 -> V_197 = 1 ;
V_2 -> V_203 = V_2 -> V_167 -> V_200 ;
}
V_48 = V_2 -> V_113 ;
for ( V_46 = 0 ; V_46 < V_187 ; V_46 ++ ) {
if ( ! V_2 -> V_188 [ V_46 ] )
continue;
if ( V_2 -> V_189 != V_190 ||
V_2 -> V_113 <= V_186 ) {
V_2 -> V_188 [ V_46 ] -> F_165 ( V_2 ) ;
} else {
-- V_48 ;
F_163 ( V_2 , V_48 ) -> type =
V_2 -> V_188 [ V_46 ] ;
}
}
V_2 -> V_181 = V_2 -> V_199 ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 )
{
struct V_9 * V_10 , * V_204 ;
int V_42 ;
F_76 ( V_2 -> V_3 == V_4 ) ;
V_2 -> V_205 = true ;
F_32 () ;
F_56 (channel, efx) {
if ( ! V_10 -> type -> V_206 ) {
V_42 = F_28 ( V_10 ) ;
if ( V_42 )
goto V_63;
}
F_31 ( V_10 ) ;
}
return 0 ;
V_63:
V_204 = V_10 ;
F_56 (channel, efx) {
if ( V_10 == V_204 )
break;
F_35 ( V_10 ) ;
if ( ! V_10 -> type -> V_206 )
F_39 ( V_10 ) ;
}
return V_42 ;
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
if ( V_2 -> V_3 == V_4 )
return;
V_2 -> V_205 = false ;
F_32 () ;
if ( V_2 -> V_203 )
F_166 ( V_2 -> V_203 ) ;
F_56 (channel, efx) {
if ( V_10 -> V_200 )
F_166 ( V_10 -> V_200 ) ;
F_35 ( V_10 ) ;
if ( ! V_10 -> type -> V_206 )
F_39 ( V_10 ) ;
}
}
static int F_167 ( struct V_1 * V_2 )
{
struct V_9 * V_10 , * V_204 ;
int V_42 ;
F_76 ( V_2 -> V_3 == V_4 ) ;
if ( V_2 -> V_207 ) {
F_168 ( V_2 -> V_203 ) ;
V_2 -> V_207 = false ;
}
V_2 -> type -> V_208 ( V_2 ) ;
F_56 (channel, efx) {
if ( V_10 -> type -> V_206 ) {
V_42 = F_28 ( V_10 ) ;
if ( V_42 )
goto V_63;
}
}
V_42 = F_91 ( V_2 ) ;
if ( V_42 )
goto V_63;
return 0 ;
V_63:
V_204 = V_10 ;
F_56 (channel, efx) {
if ( V_10 == V_204 )
break;
if ( V_10 -> type -> V_206 )
F_39 ( V_10 ) ;
}
V_2 -> type -> V_209 ( V_2 ) ;
return V_42 ;
}
static void F_169 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_87 ( V_2 ) ;
F_56 (channel, efx) {
if ( V_10 -> type -> V_206 )
F_39 ( V_10 ) ;
}
V_2 -> type -> V_209 ( V_2 ) ;
}
static void F_170 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_56 (channel, efx)
V_10 -> V_200 = 0 ;
F_171 ( V_2 -> V_167 ) ;
F_172 ( V_2 -> V_167 ) ;
V_2 -> V_203 = 0 ;
}
static void F_173 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_12 * V_13 ;
V_2 -> V_67 =
V_193 ?
V_2 -> V_113 - V_2 -> V_197 : 0 ;
F_56 (channel, efx) {
if ( V_10 -> V_10 < V_2 -> V_199 )
V_10 -> V_19 . V_210 = V_10 -> V_10 ;
else
V_10 -> V_19 . V_210 = - 1 ;
F_5 (tx_queue, channel)
V_13 -> V_52 -= ( V_2 -> V_67 *
V_51 ) ;
}
}
static int F_174 ( struct V_1 * V_2 )
{
int V_42 ;
F_23 ( V_2 , V_36 , V_2 -> V_7 , L_51 ) ;
V_42 = V_2 -> type -> V_36 ( V_2 ) ;
if ( V_42 )
return V_42 ;
do {
if ( ! V_2 -> V_194 || ! V_2 -> V_198 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_52
L_53 ) ;
V_42 = - V_211 ;
goto V_150;
}
V_42 = F_160 ( V_2 ) ;
if ( V_42 )
goto V_150;
F_173 ( V_2 ) ;
V_42 = V_2 -> type -> V_212 ( V_2 ) ;
if ( V_42 != 0 && V_42 != - V_213 )
goto V_154;
if ( V_42 == - V_213 )
F_170 ( V_2 ) ;
} while ( V_42 == - V_213 );
if ( V_2 -> V_113 > 1 )
F_175 ( & V_2 -> V_214 ,
sizeof( V_2 -> V_214 ) ) ;
F_149 ( V_2 ) ;
F_176 ( V_2 -> V_7 , V_2 -> V_197 ) ;
F_177 ( V_2 -> V_7 , V_2 -> V_199 ) ;
V_2 -> V_22 = F_178 ( V_2 -> V_215 , 1000 ) ;
F_179 ( V_2 , V_216 , V_217 , true ,
true ) ;
return 0 ;
V_154:
F_170 ( V_2 ) ;
V_150:
V_2 -> type -> remove ( V_2 ) ;
return V_42 ;
}
static void F_180 ( struct V_1 * V_2 )
{
F_23 ( V_2 , V_6 , V_2 -> V_7 , L_54 ) ;
F_170 ( V_2 ) ;
V_2 -> type -> remove ( V_2 ) ;
}
static int F_181 ( struct V_1 * V_2 )
{
int V_42 ;
F_182 ( & V_2 -> V_218 ) ;
F_183 ( & V_2 -> V_133 ) ;
F_114 ( & V_2 -> V_137 ) ;
F_184 ( & V_2 -> V_133 ) ;
V_42 = V_2 -> type -> V_219 ( V_2 ) ;
if ( V_42 )
goto V_220;
#ifdef F_185
if ( V_2 -> type -> V_221 & V_222 ) {
struct V_9 * V_10 ;
int V_46 , V_223 = 1 ;
F_56 (channel, efx) {
V_10 -> V_224 =
F_186 ( V_2 -> type -> V_225 ,
sizeof( * V_10 -> V_224 ) ,
V_49 ) ;
if ( ! V_10 -> V_224 )
V_223 = 0 ;
else
for ( V_46 = 0 ;
V_46 < V_2 -> type -> V_225 ;
++ V_46 )
V_10 -> V_224 [ V_46 ] =
V_226 ;
}
if ( ! V_223 ) {
F_56 (channel, efx)
F_90 ( V_10 -> V_224 ) ;
V_2 -> type -> V_227 ( V_2 ) ;
V_42 = - V_114 ;
goto V_220;
}
V_2 -> V_228 = V_2 -> V_229 = 0 ;
}
#endif
V_220:
F_187 ( & V_2 -> V_133 ) ;
F_115 ( & V_2 -> V_137 ) ;
return V_42 ;
}
static void F_188 ( struct V_1 * V_2 )
{
#ifdef F_185
struct V_9 * V_10 ;
F_56 (channel, efx)
F_90 ( V_10 -> V_224 ) ;
#endif
F_184 ( & V_2 -> V_133 ) ;
V_2 -> type -> V_227 ( V_2 ) ;
F_187 ( & V_2 -> V_133 ) ;
}
static void F_189 ( struct V_1 * V_2 )
{
F_108 ( & V_2 -> V_133 ) ;
V_2 -> type -> V_230 ( V_2 ) ;
F_109 ( & V_2 -> V_133 ) ;
}
static int F_190 ( struct V_1 * V_2 )
{
int V_42 ;
V_42 = F_174 ( V_2 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 , L_55 ) ;
goto V_150;
}
V_42 = F_117 ( V_2 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 , L_56 ) ;
goto V_154;
}
F_62 ( V_231 < V_232 ) ;
if ( F_71 ( V_231 < F_191 ( V_2 ) ) ) {
V_42 = - V_233 ;
goto V_177;
}
V_2 -> V_37 = V_2 -> V_38 = V_231 ;
V_42 = F_181 ( V_2 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 ,
L_57 ) ;
goto V_179;
}
V_42 = F_57 ( V_2 ) ;
if ( V_42 )
goto V_234;
return 0 ;
V_234:
F_188 ( V_2 ) ;
V_179:
V_177:
F_128 ( V_2 ) ;
V_154:
F_180 ( V_2 ) ;
V_150:
return V_42 ;
}
static void F_92 ( struct V_1 * V_2 )
{
F_75 ( V_2 ) ;
F_76 ( V_2 -> V_3 == V_4 ) ;
if ( V_2 -> V_101 || ! F_100 ( V_2 -> V_7 ) ||
V_2 -> V_235 )
return;
F_120 ( V_2 ) ;
F_60 ( V_2 ) ;
if ( V_2 -> type -> V_236 != NULL )
F_192 ( V_2 -> V_237 , & V_2 -> V_157 ,
V_238 ) ;
V_2 -> type -> V_239 ( V_2 ) ;
V_2 -> type -> V_240 ( V_2 ) ;
F_193 ( & V_2 -> V_241 ) ;
V_2 -> type -> V_242 ( V_2 , NULL , NULL ) ;
F_194 ( & V_2 -> V_241 ) ;
}
static void F_86 ( struct V_1 * V_2 )
{
F_75 ( V_2 ) ;
if ( ! V_2 -> V_101 )
return;
V_2 -> type -> V_240 ( V_2 ) ;
F_193 ( & V_2 -> V_241 ) ;
V_2 -> type -> V_242 ( V_2 , NULL , NULL ) ;
F_194 ( & V_2 -> V_241 ) ;
V_2 -> type -> V_243 ( V_2 ) ;
F_121 ( V_2 ) ;
F_71 ( F_100 ( V_2 -> V_7 ) &&
F_72 ( V_2 -> V_7 ) ) ;
F_195 ( V_2 -> V_7 ) ;
F_74 ( V_2 ) ;
}
static void F_196 ( struct V_1 * V_2 )
{
F_59 ( V_2 ) ;
F_188 ( V_2 ) ;
F_128 ( V_2 ) ;
F_180 ( V_2 ) ;
}
unsigned int F_197 ( struct V_1 * V_2 , unsigned int V_244 )
{
if ( V_244 == 0 )
return 0 ;
if ( V_244 * 1000 < V_2 -> V_215 )
return 1 ;
return V_244 * 1000 / V_2 -> V_215 ;
}
unsigned int F_198 ( struct V_1 * V_2 , unsigned int V_245 )
{
return F_178 ( V_245 * V_2 -> V_215 , 1000 ) ;
}
int F_179 ( struct V_1 * V_2 , unsigned int V_246 ,
unsigned int V_247 , bool V_248 ,
bool V_249 )
{
struct V_9 * V_10 ;
unsigned int V_250 ;
F_75 ( V_2 ) ;
V_250 = V_2 -> V_251 / 1000 ;
if ( V_246 > V_250 || V_247 > V_250 )
return - V_233 ;
if ( V_246 != V_247 && V_2 -> V_67 == 0 &&
! V_249 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_58
L_59 ) ;
return - V_233 ;
}
V_2 -> V_34 = V_248 ;
V_2 -> V_28 = V_247 ;
F_56 (channel, efx) {
if ( F_7 ( V_10 ) )
V_10 -> V_25 = V_247 ;
else if ( F_199 ( V_10 ) )
V_10 -> V_25 = V_246 ;
}
return 0 ;
}
void F_200 ( struct V_1 * V_2 , unsigned int * V_246 ,
unsigned int * V_247 , bool * V_248 )
{
* V_248 = V_2 -> V_34 ;
* V_247 = V_2 -> V_28 ;
if ( V_2 -> V_67 == 0 ) {
* V_246 = * V_247 ;
} else {
struct V_9 * V_252 ;
V_252 = V_2 -> V_10 [ V_2 -> V_67 ] ;
* V_246 = V_252 -> V_25 ;
}
}
static void F_201 ( struct V_140 * V_141 )
{
struct V_1 * V_2 = F_14 ( V_141 , struct V_1 ,
V_157 . V_253 ) ;
F_16 ( V_2 , V_254 , V_2 -> V_7 ,
L_60 ,
F_17 () ) ;
F_76 ( V_2 -> type -> V_236 == NULL ) ;
if ( F_202 ( & V_2 -> V_137 ) ) {
if ( V_2 -> V_101 )
V_2 -> type -> V_236 ( V_2 ) ;
F_115 ( & V_2 -> V_137 ) ;
}
F_192 ( V_2 -> V_237 , & V_2 -> V_157 ,
V_238 ) ;
}
static int F_203 ( struct V_255 * V_7 , struct V_256 * V_257 , int V_258 )
{
struct V_1 * V_2 = F_204 ( V_7 ) ;
struct V_259 * V_141 = F_205 ( V_257 ) ;
if ( ( V_258 == V_260 || V_258 == V_261 ) &&
( V_141 -> V_262 & 0xfc00 ) == 0x0400 )
V_141 -> V_262 ^= V_263 | 0x0400 ;
return F_206 ( & V_2 -> V_264 , V_141 , V_258 ) ;
}
static void F_88 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
V_10 -> V_55 = V_2 -> V_7 ;
F_207 ( V_10 -> V_55 , & V_10 -> V_32 ,
F_13 , V_265 ) ;
F_208 ( V_10 ) ;
}
static void F_209 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_56 (channel, efx)
F_88 ( V_10 ) ;
}
static void F_89 ( struct V_9 * V_10 )
{
if ( V_10 -> V_55 )
F_210 ( & V_10 -> V_32 ) ;
V_10 -> V_55 = NULL ;
}
static void F_211 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_56 (channel, efx)
F_89 ( V_10 ) ;
}
static void F_212 ( struct V_255 * V_7 )
{
struct V_1 * V_2 = F_204 ( V_7 ) ;
struct V_9 * V_10 ;
F_56 (channel, efx)
F_213 ( V_10 ) ;
}
static int F_214 ( struct V_30 * V_31 )
{
struct V_9 * V_10 =
F_14 ( V_31 , struct V_9 , V_32 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_11 = 4 ;
int V_266 , V_267 ;
if ( ! F_100 ( V_2 -> V_7 ) )
return V_268 ;
if ( ! F_215 ( V_10 ) )
return V_269 ;
V_266 = V_10 -> V_19 . V_267 ;
F_3 ( V_10 , V_11 ) ;
V_267 = V_10 -> V_19 . V_267 - V_266 ;
F_216 ( V_10 ) ;
return V_267 ;
}
int F_217 ( struct V_255 * V_7 )
{
struct V_1 * V_2 = F_204 ( V_7 ) ;
int V_42 ;
F_23 ( V_2 , V_45 , V_2 -> V_7 , L_61 ,
F_17 () ) ;
V_42 = F_1 ( V_2 ) ;
if ( V_42 )
return V_42 ;
if ( V_2 -> V_136 & V_144 )
return - V_270 ;
F_99 ( V_2 ) ;
F_92 ( V_2 ) ;
F_218 ( V_2 ) ;
return 0 ;
}
int F_219 ( struct V_255 * V_7 )
{
struct V_1 * V_2 = F_204 ( V_7 ) ;
F_23 ( V_2 , V_156 , V_2 -> V_7 , L_62 ,
F_17 () ) ;
F_86 ( V_2 ) ;
return 0 ;
}
static struct V_271 * F_220 ( struct V_255 * V_7 ,
struct V_271 * V_272 )
{
struct V_1 * V_2 = F_204 ( V_7 ) ;
F_193 ( & V_2 -> V_241 ) ;
V_2 -> type -> V_242 ( V_2 , NULL , V_272 ) ;
F_194 ( & V_2 -> V_241 ) ;
return V_272 ;
}
static void F_221 ( struct V_255 * V_7 )
{
struct V_1 * V_2 = F_204 ( V_7 ) ;
F_2 ( V_2 , V_273 , V_2 -> V_7 ,
L_63 ,
V_2 -> V_101 ) ;
F_78 ( V_2 , V_274 ) ;
}
static int F_222 ( struct V_255 * V_7 , int V_275 )
{
struct V_1 * V_2 = F_204 ( V_7 ) ;
int V_42 ;
V_42 = F_1 ( V_2 ) ;
if ( V_42 )
return V_42 ;
F_23 ( V_2 , V_6 , V_2 -> V_7 , L_64 , V_275 ) ;
F_85 ( V_2 ) ;
F_86 ( V_2 ) ;
F_114 ( & V_2 -> V_137 ) ;
V_7 -> V_79 = V_275 ;
F_107 ( V_2 ) ;
F_115 ( & V_2 -> V_137 ) ;
F_92 ( V_2 ) ;
F_93 ( V_2 -> V_7 ) ;
return 0 ;
}
static int F_223 ( struct V_255 * V_7 , void * V_141 )
{
struct V_1 * V_2 = F_204 ( V_7 ) ;
struct V_276 * V_277 = V_141 ;
T_4 * V_278 = V_277 -> V_279 ;
T_4 V_280 [ 6 ] ;
int V_42 ;
if ( ! F_224 ( V_278 ) ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_65 ,
V_278 ) ;
return - V_281 ;
}
F_118 ( V_280 , V_7 -> V_146 ) ;
F_118 ( V_7 -> V_146 , V_278 ) ;
if ( V_2 -> type -> V_282 ) {
V_42 = V_2 -> type -> V_282 ( V_2 ) ;
if ( V_42 ) {
F_118 ( V_7 -> V_146 , V_280 ) ;
return V_42 ;
}
}
F_114 ( & V_2 -> V_137 ) ;
F_107 ( V_2 ) ;
F_115 ( & V_2 -> V_137 ) ;
return 0 ;
}
static void F_225 ( struct V_255 * V_7 )
{
struct V_1 * V_2 = F_204 ( V_7 ) ;
if ( V_2 -> V_101 )
F_226 ( V_2 -> V_237 , & V_2 -> V_142 ) ;
}
static int F_227 ( struct V_255 * V_7 , T_2 V_141 )
{
struct V_1 * V_2 = F_204 ( V_7 ) ;
int V_42 ;
if ( V_7 -> V_73 & ~ V_141 & V_222 ) {
V_42 = V_2 -> type -> V_283 ( V_2 , V_284 ) ;
if ( V_42 )
return V_42 ;
}
if ( ( V_7 -> V_73 ^ V_141 ) & V_285 ) {
F_225 ( V_7 ) ;
}
return 0 ;
}
static void F_228 ( struct V_1 * V_2 )
{
strcpy ( V_2 -> V_68 , V_2 -> V_7 -> V_68 ) ;
F_229 ( V_2 ) ;
F_55 ( V_2 ) ;
}
static int F_230 ( struct V_286 * V_287 ,
unsigned long V_288 , void * V_289 )
{
struct V_255 * V_7 = F_231 ( V_289 ) ;
if ( ( V_7 -> V_290 == & V_291 ) &&
V_288 == V_292 )
F_228 ( F_204 ( V_7 ) ) ;
return V_293 ;
}
static T_7
F_232 ( struct V_294 * V_175 , struct V_295 * V_296 , char * V_64 )
{
struct V_1 * V_2 = F_233 ( F_234 ( V_175 ) ) ;
return sprintf ( V_64 , L_66 , V_2 -> V_297 ) ;
}
static int F_235 ( struct V_1 * V_2 )
{
struct V_255 * V_7 = V_2 -> V_7 ;
struct V_9 * V_10 ;
int V_42 ;
V_7 -> V_298 = 5 * V_299 ;
V_7 -> V_200 = V_2 -> V_167 -> V_200 ;
V_7 -> V_290 = & V_291 ;
V_7 -> V_300 = & V_301 ;
V_7 -> V_302 = V_303 ;
V_7 -> V_304 = V_305 ;
V_7 -> V_306 = V_307 ;
F_236 () ;
V_2 -> V_3 = V_308 ;
F_237 () ;
if ( V_2 -> V_235 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 ,
L_67 ) ;
V_42 = - V_8 ;
goto V_309;
}
V_42 = F_238 ( V_7 , V_7 -> V_68 ) ;
if ( V_42 < 0 )
goto V_309;
F_228 ( V_2 ) ;
F_103 ( V_7 ) ;
V_42 = F_239 ( V_7 ) ;
if ( V_42 )
goto V_309;
F_56 (channel, efx) {
struct V_12 * V_13 ;
F_5 (tx_queue, channel)
F_240 ( V_13 ) ;
}
F_130 ( V_2 ) ;
F_241 () ;
V_42 = F_242 ( & V_2 -> V_167 -> V_175 , & V_310 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_68 ) ;
goto V_311;
}
return 0 ;
V_311:
F_236 () ;
F_136 ( V_2 ) ;
F_243 ( V_7 ) ;
V_309:
V_2 -> V_3 = V_312 ;
F_241 () ;
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_69 ) ;
return V_42 ;
}
static void F_244 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_7 )
return;
F_76 ( F_204 ( V_2 -> V_7 ) != V_2 ) ;
if ( F_245 ( V_2 ) ) {
F_246 ( V_2 -> V_68 , F_134 ( V_2 -> V_167 ) , sizeof( V_2 -> V_68 ) ) ;
F_247 ( & V_2 -> V_167 -> V_175 , & V_310 ) ;
F_248 ( V_2 -> V_7 ) ;
}
}
void F_249 ( struct V_1 * V_2 , enum V_313 V_314 )
{
F_75 ( V_2 ) ;
F_86 ( V_2 ) ;
F_169 ( V_2 ) ;
F_114 ( & V_2 -> V_137 ) ;
if ( V_2 -> V_151 && V_314 != V_315 &&
V_314 != V_316 )
V_2 -> V_148 -> V_155 ( V_2 ) ;
V_2 -> type -> V_155 ( V_2 ) ;
}
int F_250 ( struct V_1 * V_2 , enum V_313 V_314 , bool V_317 )
{
int V_42 ;
F_75 ( V_2 ) ;
V_42 = V_2 -> type -> V_149 ( V_2 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_70 ) ;
goto V_63;
}
if ( ! V_317 )
goto V_63;
if ( V_2 -> V_151 && V_314 != V_315 &&
V_314 != V_316 ) {
V_42 = V_2 -> V_148 -> V_149 ( V_2 ) ;
if ( V_42 )
goto V_63;
V_42 = V_2 -> V_148 -> V_152 ( V_2 ) ;
if ( V_42 && V_42 != - V_153 )
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_71 ) ;
}
V_42 = F_167 ( V_2 ) ;
if ( V_42 )
goto V_63;
F_108 ( & V_2 -> V_133 ) ;
F_189 ( V_2 ) ;
F_109 ( & V_2 -> V_133 ) ;
F_115 ( & V_2 -> V_137 ) ;
F_92 ( V_2 ) ;
return 0 ;
V_63:
V_2 -> V_151 = false ;
F_115 ( & V_2 -> V_137 ) ;
return V_42 ;
}
int F_251 ( struct V_1 * V_2 , enum V_313 V_314 )
{
int V_42 , V_110 ;
bool V_318 ;
F_104 ( V_2 , V_6 , V_2 -> V_7 , L_72 ,
F_252 ( V_314 ) ) ;
F_85 ( V_2 ) ;
F_249 ( V_2 , V_314 ) ;
V_42 = V_2 -> type -> V_319 ( V_2 , V_314 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_73 ) ;
goto V_115;
}
if ( V_314 < V_320 )
V_2 -> V_235 &= - ( 1 << ( V_314 + 1 ) ) ;
else
F_253 ( V_314 , & V_2 -> V_235 ) ;
F_139 ( V_2 -> V_167 ) ;
V_115:
V_318 = V_42 ||
V_314 == V_117 ||
V_314 == V_321 ;
V_110 = F_250 ( V_2 , V_314 , ! V_318 ) ;
if ( V_110 ) {
V_318 = true ;
if ( ! V_42 )
V_42 = V_110 ;
}
if ( V_318 ) {
F_254 ( V_2 -> V_7 ) ;
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_74 ) ;
V_2 -> V_3 = V_4 ;
} else {
F_23 ( V_2 , V_6 , V_2 -> V_7 , L_75 ) ;
F_93 ( V_2 -> V_7 ) ;
}
return V_42 ;
}
int F_255 ( struct V_1 * V_2 )
{
#ifdef F_256
struct V_322 * V_323 = F_257 ( V_2 -> V_167 ) ;
if ( F_258 ( V_323 ) ) {
return 1 ;
}
#endif
return 0 ;
}
static void F_259 ( struct V_140 * V_141 )
{
struct V_1 * V_2 = F_14 ( V_141 , struct V_1 , V_324 ) ;
unsigned long V_325 ;
enum V_313 V_314 ;
V_325 = F_260 ( V_2 -> V_235 ) ;
V_314 = F_261 ( V_325 ) - 1 ;
if ( ( V_314 == V_321 ||
V_314 == V_326 ) &&
F_255 ( V_2 ) )
return;
if ( ! V_325 )
return;
F_236 () ;
if ( V_2 -> V_3 == V_308 )
( void ) F_251 ( V_2 , V_314 ) ;
F_241 () ;
}
void F_78 ( struct V_1 * V_2 , enum V_313 type )
{
enum V_313 V_314 ;
if ( V_2 -> V_3 == V_5 ) {
F_23 ( V_2 , V_6 , V_2 -> V_7 ,
L_76 ,
F_252 ( type ) ) ;
return;
}
switch ( type ) {
case V_315 :
case V_104 :
case V_326 :
case V_327 :
case V_117 :
case V_321 :
case V_316 :
V_314 = type ;
F_23 ( V_2 , V_6 , V_2 -> V_7 , L_77 ,
F_252 ( V_314 ) ) ;
break;
default:
V_314 = V_2 -> type -> V_328 ( type ) ;
F_23 ( V_2 , V_6 , V_2 -> V_7 ,
L_78 ,
F_252 ( V_314 ) , F_252 ( type ) ) ;
break;
}
F_262 ( V_314 , & V_2 -> V_235 ) ;
F_237 () ;
if ( F_260 ( V_2 -> V_3 ) != V_308 )
return;
F_226 ( V_329 , & V_2 -> V_324 ) ;
}
int F_263 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_264 ( struct V_1 * V_2 ) {}
static bool F_265 ( struct V_1 * V_2 )
{
return false ;
}
static int F_266 ( struct V_1 * V_2 ,
struct V_167 * V_167 , struct V_255 * V_7 )
{
int V_46 ;
F_267 ( & V_2 -> V_165 ) ;
F_267 ( & V_2 -> V_168 ) ;
F_182 ( & V_2 -> V_330 ) ;
#ifdef F_268
F_267 ( & V_2 -> V_331 ) ;
#endif
F_269 ( & V_2 -> V_324 , F_259 ) ;
F_270 ( & V_2 -> V_157 , F_201 ) ;
F_270 ( & V_2 -> V_332 , V_333 ) ;
V_2 -> V_167 = V_167 ;
V_2 -> V_334 = V_335 ;
V_2 -> V_3 = V_312 ;
F_246 ( V_2 -> V_68 , F_134 ( V_167 ) , sizeof( V_2 -> V_68 ) ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_78 = V_2 -> type -> V_78 ;
V_2 -> V_82 =
V_89 ? ( V_2 -> V_78 + V_89 ) % 4 : 0 ;
V_2 -> V_336 =
V_2 -> type -> V_337 - V_2 -> type -> V_78 ;
V_2 -> V_338 =
V_2 -> type -> V_339 - V_2 -> type -> V_78 ;
F_182 ( & V_2 -> V_241 ) ;
F_271 ( & V_2 -> V_137 ) ;
V_2 -> V_148 = & V_340 ;
V_2 -> V_264 . V_175 = V_7 ;
F_269 ( & V_2 -> V_142 , F_116 ) ;
F_272 ( & V_2 -> V_341 ) ;
for ( V_46 = 0 ; V_46 < V_107 ; V_46 ++ ) {
V_2 -> V_10 [ V_46 ] = F_43 ( V_2 , V_46 , NULL ) ;
if ( ! V_2 -> V_10 [ V_46 ] )
goto V_63;
V_2 -> V_70 [ V_46 ] . V_2 = V_2 ;
V_2 -> V_70 [ V_46 ] . V_112 = V_46 ;
}
V_2 -> V_189 = F_26 ( V_2 -> type -> V_342 ,
V_189 ) ;
snprintf ( V_2 -> V_343 , sizeof( V_2 -> V_343 ) , L_79 ,
F_134 ( V_167 ) ) ;
V_2 -> V_237 = F_273 ( V_2 -> V_343 ) ;
if ( ! V_2 -> V_237 )
goto V_63;
return 0 ;
V_63:
F_274 ( V_2 ) ;
return - V_114 ;
}
static void F_274 ( struct V_1 * V_2 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_107 ; V_46 ++ )
F_90 ( V_2 -> V_10 [ V_46 ] ) ;
F_90 ( V_2 -> V_161 ) ;
if ( V_2 -> V_237 ) {
F_275 ( V_2 -> V_237 ) ;
V_2 -> V_237 = NULL ;
}
}
void F_276 ( struct V_1 * V_2 , T_8 * V_272 )
{
T_8 V_344 = 0 ;
struct V_9 * V_10 ;
F_56 (channel, efx)
V_344 += V_10 -> V_344 ;
V_272 [ V_345 ] = V_344 ;
V_272 [ V_346 ] = F_277 ( & V_2 -> V_347 ) ;
}
static void F_278 ( struct V_1 * V_2 )
{
F_76 ( V_2 -> V_3 == V_308 ) ;
F_126 ( & V_2 -> V_324 ) ;
F_169 ( V_2 ) ;
F_279 ( V_2 ) ;
F_127 ( V_2 ) ;
V_2 -> type -> V_155 ( V_2 ) ;
F_211 ( V_2 ) ;
F_196 ( V_2 ) ;
}
static void F_280 ( struct V_167 * V_167 )
{
struct V_1 * V_2 ;
V_2 = F_233 ( V_167 ) ;
if ( ! V_2 )
return;
F_236 () ;
F_136 ( V_2 ) ;
F_254 ( V_2 -> V_7 ) ;
F_169 ( V_2 ) ;
V_2 -> V_3 = V_312 ;
F_241 () ;
F_244 ( V_2 ) ;
F_281 ( V_2 ) ;
F_278 ( V_2 ) ;
F_146 ( V_2 ) ;
F_23 ( V_2 , V_6 , V_2 -> V_7 , L_80 ) ;
F_274 ( V_2 ) ;
F_282 ( V_2 -> V_7 ) ;
F_283 ( V_167 ) ;
}
static void F_284 ( struct V_1 * V_2 )
{
struct V_167 * V_175 = V_2 -> V_167 ;
char V_348 [ V_349 ] ;
T_7 V_350 ;
int V_351 , V_352 , V_46 , V_48 ;
V_350 = F_285 ( V_175 , 0 , sizeof( V_348 ) , V_348 ) ;
if ( V_350 <= 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_81 ) ;
return;
}
V_351 = F_286 ( V_348 , 0 , V_350 , V_353 ) ;
if ( V_351 < 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_82 ) ;
return;
}
V_352 = F_287 ( & V_348 [ V_351 ] ) ;
V_48 = V_352 ;
V_46 = V_351 + V_354 ;
if ( V_46 + V_48 > V_350 )
V_48 = V_350 - V_46 ;
V_46 = F_288 ( V_348 , V_46 , V_48 , L_83 ) ;
if ( V_46 < 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_84 ) ;
return;
}
V_48 = F_289 ( & V_348 [ V_46 ] ) ;
V_46 += V_355 ;
if ( V_46 + V_48 > V_350 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_85 ) ;
return;
}
F_104 ( V_2 , V_6 , V_2 -> V_7 ,
L_86 , V_48 , & V_348 [ V_46 ] ) ;
V_46 = V_351 + V_354 ;
V_48 = V_352 ;
V_46 = F_288 ( V_348 , V_46 , V_48 , L_87 ) ;
if ( V_46 < 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_88 ) ;
return;
}
V_48 = F_289 ( & V_348 [ V_46 ] ) ;
V_46 += V_355 ;
if ( V_46 + V_48 > V_350 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_89 ) ;
return;
}
V_2 -> V_161 = F_47 ( V_48 + 1 , V_49 ) ;
if ( ! V_2 -> V_161 )
return;
snprintf ( V_2 -> V_161 , V_48 + 1 , L_90 , & V_348 [ V_46 ] ) ;
}
static int F_290 ( struct V_1 * V_2 )
{
int V_42 ;
V_42 = F_190 ( V_2 ) ;
if ( V_42 )
goto V_150;
F_209 ( V_2 ) ;
V_42 = V_2 -> type -> V_149 ( V_2 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 ,
L_70 ) ;
goto V_177;
}
V_42 = F_119 ( V_2 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 ,
L_91 ) ;
goto V_179;
}
V_42 = F_291 ( V_2 ) ;
if ( V_42 )
goto V_234;
V_42 = F_167 ( V_2 ) ;
if ( V_42 )
goto V_356;
return 0 ;
V_356:
F_279 ( V_2 ) ;
V_234:
F_127 ( V_2 ) ;
V_179:
V_2 -> type -> V_155 ( V_2 ) ;
V_177:
F_211 ( V_2 ) ;
F_196 ( V_2 ) ;
V_150:
return V_42 ;
}
static int F_292 ( struct V_167 * V_167 ,
const struct V_357 * V_195 )
{
struct V_255 * V_7 ;
struct V_1 * V_2 ;
int V_42 ;
V_7 = F_293 ( sizeof( * V_2 ) , V_358 ,
V_359 ) ;
if ( ! V_7 )
return - V_114 ;
V_2 = F_204 ( V_7 ) ;
V_2 -> type = ( const struct V_360 * ) V_195 -> V_361 ;
V_2 -> V_95 |= V_362 ;
F_294 ( V_167 , V_2 ) ;
F_295 ( V_7 , & V_167 -> V_175 ) ;
V_42 = F_266 ( V_2 , V_167 , V_7 ) ;
if ( V_42 )
goto V_150;
F_104 ( V_2 , V_36 , V_2 -> V_7 ,
L_92 ) ;
F_284 ( V_2 ) ;
V_42 = F_137 ( V_2 ) ;
if ( V_42 )
goto V_154;
V_42 = F_290 ( V_2 ) ;
if ( V_42 )
goto V_177;
V_7 -> V_73 |= ( V_2 -> type -> V_221 | V_363 |
V_364 ) ;
V_7 -> V_365 |= ( V_366 | V_363 |
V_362 | V_364 ) ;
V_7 -> V_94 = V_7 -> V_73 & ~ V_2 -> V_95 ;
V_7 -> V_73 &= ~ V_285 ;
V_7 -> V_73 |= V_2 -> V_95 ;
V_42 = F_235 ( V_2 ) ;
if ( V_42 )
goto V_179;
F_23 ( V_2 , V_36 , V_2 -> V_7 , L_93 ) ;
F_236 () ;
V_42 = F_296 ( V_2 ) ;
F_241 () ;
if ( V_42 && V_42 != - V_153 )
F_154 ( V_2 , V_36 , V_2 -> V_7 ,
L_94 , V_42 ) ;
V_42 = F_297 ( V_167 ) ;
if ( V_42 && V_42 != - V_233 )
F_298 ( V_2 , V_36 , V_2 -> V_7 ,
L_95 ,
V_42 ) ;
return 0 ;
V_179:
F_278 ( V_2 ) ;
V_177:
F_146 ( V_2 ) ;
V_154:
F_274 ( V_2 ) ;
V_150:
F_71 ( V_42 > 0 ) ;
F_23 ( V_2 , V_6 , V_2 -> V_7 , L_96 , V_42 ) ;
F_282 ( V_7 ) ;
return V_42 ;
}
static int F_299 ( struct V_294 * V_175 )
{
struct V_1 * V_2 = F_233 ( F_234 ( V_175 ) ) ;
F_236 () ;
if ( V_2 -> V_3 != V_4 ) {
V_2 -> V_3 = V_312 ;
F_85 ( V_2 ) ;
F_86 ( V_2 ) ;
F_169 ( V_2 ) ;
}
F_241 () ;
return 0 ;
}
static int F_300 ( struct V_294 * V_175 )
{
int V_42 ;
struct V_1 * V_2 = F_233 ( F_234 ( V_175 ) ) ;
F_236 () ;
if ( V_2 -> V_3 != V_4 ) {
V_42 = F_167 ( V_2 ) ;
if ( V_42 )
goto V_63;
F_114 ( & V_2 -> V_137 ) ;
V_2 -> V_148 -> V_152 ( V_2 ) ;
F_115 ( & V_2 -> V_137 ) ;
F_92 ( V_2 ) ;
F_93 ( V_2 -> V_7 ) ;
V_2 -> V_3 = V_308 ;
V_2 -> type -> V_367 ( V_2 ) ;
}
F_241 () ;
F_226 ( V_329 , & V_2 -> V_324 ) ;
return 0 ;
V_63:
F_241 () ;
return V_42 ;
}
static int F_301 ( struct V_294 * V_175 )
{
struct V_167 * V_167 = F_234 ( V_175 ) ;
struct V_1 * V_2 = F_233 ( V_167 ) ;
V_2 -> type -> V_155 ( V_2 ) ;
V_2 -> V_235 = 0 ;
F_302 ( V_167 ) ;
return F_303 ( V_167 , V_368 ) ;
}
static int F_304 ( struct V_294 * V_175 )
{
struct V_167 * V_167 = F_234 ( V_175 ) ;
struct V_1 * V_2 = F_233 ( V_167 ) ;
int V_42 ;
V_42 = F_303 ( V_167 , V_369 ) ;
if ( V_42 )
return V_42 ;
F_305 ( V_167 ) ;
V_42 = F_138 ( V_167 ) ;
if ( V_42 )
return V_42 ;
F_139 ( V_2 -> V_167 ) ;
V_42 = V_2 -> type -> V_319 ( V_2 , V_104 ) ;
if ( V_42 )
return V_42 ;
V_42 = V_2 -> type -> V_149 ( V_2 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_300 ( V_175 ) ;
return V_42 ;
}
static int F_306 ( struct V_294 * V_175 )
{
int V_42 ;
F_299 ( V_175 ) ;
V_42 = F_301 ( V_175 ) ;
if ( V_42 )
F_304 ( V_175 ) ;
return V_42 ;
}
static T_9 F_307 ( struct V_167 * V_370 ,
enum V_371 V_3 )
{
T_9 V_372 = V_373 ;
struct V_1 * V_2 = F_233 ( V_370 ) ;
if ( V_3 == V_374 )
return V_375 ;
F_236 () ;
if ( V_2 -> V_3 != V_4 ) {
V_2 -> V_3 = V_5 ;
V_2 -> V_235 = 0 ;
F_85 ( V_2 ) ;
F_86 ( V_2 ) ;
F_169 ( V_2 ) ;
V_372 = V_376 ;
} else {
V_372 = V_373 ;
}
F_241 () ;
F_145 ( V_370 ) ;
return V_372 ;
}
static T_9 F_308 ( struct V_167 * V_370 )
{
struct V_1 * V_2 = F_233 ( V_370 ) ;
T_9 V_372 = V_373 ;
int V_42 ;
if ( F_138 ( V_370 ) ) {
F_2 ( V_2 , V_377 , V_2 -> V_7 ,
L_97 ) ;
V_372 = V_375 ;
}
V_42 = F_309 ( V_370 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_377 , V_2 -> V_7 ,
L_98 , V_42 ) ;
}
return V_372 ;
}
static void F_310 ( struct V_167 * V_370 )
{
struct V_1 * V_2 = F_233 ( V_370 ) ;
int V_42 ;
F_236 () ;
if ( V_2 -> V_3 == V_4 )
goto V_115;
V_42 = F_251 ( V_2 , V_104 ) ;
if ( V_42 ) {
F_2 ( V_2 , V_377 , V_2 -> V_7 ,
L_99 , V_42 ) ;
} else {
V_2 -> V_3 = V_308 ;
F_23 ( V_2 , V_377 , V_2 -> V_7 ,
L_100 ) ;
}
V_115:
F_241 () ;
}
static int T_10 F_311 ( void )
{
int V_42 ;
F_312 ( V_378 L_101 V_379 L_102 ) ;
V_42 = F_313 ( & V_380 ) ;
if ( V_42 )
goto V_381;
V_329 = F_273 ( L_103 ) ;
if ( ! V_329 ) {
V_42 = - V_114 ;
goto V_382;
}
V_42 = F_314 ( & V_383 ) ;
if ( V_42 < 0 )
goto V_384;
return 0 ;
V_384:
F_275 ( V_329 ) ;
V_382:
F_315 ( & V_380 ) ;
V_381:
return V_42 ;
}
static void T_11 F_316 ( void )
{
F_312 ( V_378 L_104 ) ;
F_317 ( & V_383 ) ;
F_275 ( V_329 ) ;
F_315 ( & V_380 ) ;
}

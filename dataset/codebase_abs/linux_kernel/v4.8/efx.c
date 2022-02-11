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
static int F_12 ( struct V_21 * V_22 , int V_11 )
{
struct V_9 * V_10 =
F_13 ( V_22 , struct V_9 , V_23 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_14 ;
if ( ! F_14 ( V_10 ) )
return V_11 ;
F_15 ( V_2 , V_24 , V_2 -> V_7 ,
L_2 ,
V_10 -> V_10 , F_16 () ) ;
V_14 = F_3 ( V_10 , V_11 ) ;
if ( V_14 < V_11 ) {
if ( F_7 ( V_10 ) &&
V_2 -> V_25 &&
F_4 ( ++ V_10 -> V_26 == 1000 ) ) {
if ( F_4 ( V_10 -> V_27 <
V_28 ) ) {
if ( V_10 -> V_29 > 1 ) {
V_10 -> V_29 -= 1 ;
V_2 -> type -> V_30 ( V_10 ) ;
}
} else if ( F_4 ( V_10 -> V_27 >
V_31 ) ) {
if ( V_10 -> V_29 <
V_2 -> V_32 ) {
V_10 -> V_29 += 1 ;
V_2 -> type -> V_30 ( V_10 ) ;
}
}
V_10 -> V_26 = 0 ;
V_10 -> V_27 = 0 ;
}
F_17 ( V_10 ) ;
F_18 ( V_22 ) ;
F_19 ( V_10 ) ;
}
F_20 ( V_10 ) ;
return V_14 ;
}
static int F_21 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned long V_33 ;
F_22 ( V_2 , V_34 , V_2 -> V_7 ,
L_3 , V_10 -> V_10 ) ;
V_33 = F_23 ( V_2 -> V_35 + V_2 -> V_36 + 128 ) ;
F_24 ( V_33 > V_37 ) ;
V_10 -> V_38 = F_25 ( V_33 , V_39 ) - 1 ;
return F_26 ( V_10 ) ;
}
static int F_27 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_40 ;
F_28 ( V_10 -> V_41 ) ;
F_22 ( V_2 , V_6 , V_2 -> V_7 ,
L_4 , V_10 -> V_10 ) ;
V_40 = F_29 ( V_10 ) ;
if ( V_40 == 0 ) {
V_2 -> type -> V_30 ( V_10 ) ;
V_10 -> V_42 = 0 ;
V_10 -> V_41 = true ;
}
return V_40 ;
}
void F_30 ( struct V_9 * V_10 )
{
F_22 ( V_10 -> V_2 , V_43 , V_10 -> V_2 -> V_7 ,
L_5 , V_10 -> V_10 ) ;
V_10 -> V_15 = true ;
F_31 () ;
F_32 ( V_10 ) ;
F_33 ( & V_10 -> V_23 ) ;
F_19 ( V_10 ) ;
}
void F_34 ( struct V_9 * V_10 )
{
if ( ! V_10 -> V_15 )
return;
F_35 ( & V_10 -> V_23 ) ;
while ( ! F_36 ( V_10 ) )
F_37 ( 1000 , 20000 ) ;
V_10 -> V_15 = false ;
}
static void F_38 ( struct V_9 * V_10 )
{
if ( ! V_10 -> V_41 )
return;
F_22 ( V_10 -> V_2 , V_6 , V_10 -> V_2 -> V_7 ,
L_6 , V_10 -> V_10 ) ;
F_39 ( V_10 ) ;
V_10 -> V_41 = false ;
}
static void F_40 ( struct V_9 * V_10 )
{
F_22 ( V_10 -> V_2 , V_6 , V_10 -> V_2 -> V_7 ,
L_7 , V_10 -> V_10 ) ;
F_41 ( V_10 ) ;
}
static struct V_9 *
F_42 ( struct V_1 * V_2 , int V_44 , struct V_9 * V_45 )
{
struct V_9 * V_10 ;
struct V_18 * V_19 ;
struct V_12 * V_13 ;
int V_46 ;
V_10 = F_43 ( sizeof( * V_10 ) , V_47 ) ;
if ( ! V_10 )
return NULL ;
V_10 -> V_2 = V_2 ;
V_10 -> V_10 = V_44 ;
V_10 -> type = & V_48 ;
for ( V_46 = 0 ; V_46 < V_49 ; V_46 ++ ) {
V_13 = & V_10 -> V_13 [ V_46 ] ;
V_13 -> V_2 = V_2 ;
V_13 -> V_50 = V_44 * V_49 + V_46 ;
V_13 -> V_10 = V_10 ;
}
V_19 = & V_10 -> V_19 ;
V_19 -> V_2 = V_2 ;
F_44 ( & V_19 -> V_51 , V_52 ,
( unsigned long ) V_19 ) ;
return V_10 ;
}
static struct V_9 *
F_45 ( const struct V_9 * V_45 )
{
struct V_9 * V_10 ;
struct V_18 * V_19 ;
struct V_12 * V_13 ;
int V_46 ;
V_10 = F_46 ( sizeof( * V_10 ) , V_47 ) ;
if ( ! V_10 )
return NULL ;
* V_10 = * V_45 ;
V_10 -> V_53 = NULL ;
memset ( & V_10 -> V_54 , 0 , sizeof( V_10 -> V_54 ) ) ;
for ( V_46 = 0 ; V_46 < V_49 ; V_46 ++ ) {
V_13 = & V_10 -> V_13 [ V_46 ] ;
if ( V_13 -> V_10 )
V_13 -> V_10 = V_10 ;
V_13 -> V_55 = NULL ;
memset ( & V_13 -> V_56 , 0 , sizeof( V_13 -> V_56 ) ) ;
}
V_19 = & V_10 -> V_19 ;
V_19 -> V_55 = NULL ;
memset ( & V_19 -> V_57 , 0 , sizeof( V_19 -> V_57 ) ) ;
F_44 ( & V_19 -> V_51 , V_52 ,
( unsigned long ) V_19 ) ;
return V_10 ;
}
static int F_47 ( struct V_9 * V_10 )
{
struct V_12 * V_13 ;
struct V_18 * V_19 ;
int V_40 ;
F_22 ( V_10 -> V_2 , V_34 , V_10 -> V_2 -> V_7 ,
L_8 , V_10 -> V_10 ) ;
V_40 = V_10 -> type -> V_58 ( V_10 ) ;
if ( V_40 )
goto V_59;
V_40 = F_21 ( V_10 ) ;
if ( V_40 )
goto V_59;
F_5 (tx_queue, channel) {
V_40 = F_48 ( V_13 ) ;
if ( V_40 )
goto V_59;
}
F_49 (rx_queue, channel) {
V_40 = F_50 ( V_19 ) ;
if ( V_40 )
goto V_59;
}
return 0 ;
V_59:
F_51 ( V_10 ) ;
return V_40 ;
}
static void
F_52 ( struct V_9 * V_10 , char * V_60 , T_1 V_61 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
const char * type ;
int V_62 ;
V_62 = V_10 -> V_10 ;
if ( V_2 -> V_63 == 0 ) {
type = L_9 ;
} else if ( V_10 -> V_10 < V_2 -> V_63 ) {
type = L_10 ;
} else {
type = L_11 ;
V_62 -= V_2 -> V_63 ;
}
snprintf ( V_60 , V_61 , L_12 , V_2 -> V_64 , type , V_62 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_54 (channel, efx)
V_10 -> type -> V_65 ( V_10 ,
V_2 -> V_66 [ V_10 -> V_10 ] . V_64 ,
sizeof( V_2 -> V_66 [ 0 ] . V_64 ) ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
int V_40 ;
V_2 -> V_67 = 0 ;
F_56 (channel, efx) {
V_40 = F_47 ( V_10 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_34 , V_2 -> V_7 ,
L_13 ,
V_10 -> V_10 ) ;
goto V_59;
}
}
F_53 ( V_2 ) ;
return 0 ;
V_59:
F_57 ( V_2 ) ;
return V_40 ;
}
static void F_58 ( struct V_1 * V_2 )
{
T_2 V_68 = V_2 -> V_7 -> V_69 ;
bool V_70 = V_2 -> V_71 ;
struct V_12 * V_13 ;
struct V_18 * V_19 ;
struct V_9 * V_10 ;
T_1 V_72 ;
V_2 -> V_73 = ( V_2 -> V_74 +
F_59 ( V_2 -> V_7 -> V_75 ) +
V_2 -> type -> V_76 ) ;
V_72 = ( sizeof( struct V_77 ) +
V_2 -> V_78 + V_2 -> V_73 ) ;
if ( V_72 <= V_79 ) {
V_2 -> V_71 = V_2 -> type -> V_80 ;
V_2 -> V_81 = 0 ;
} else if ( V_2 -> type -> V_82 ) {
F_60 ( V_83 % V_84 ) ;
F_60 ( sizeof( struct V_77 ) +
2 * F_61 ( V_85 + V_83 ,
V_86 ) >
V_79 ) ;
V_2 -> V_71 = true ;
V_2 -> V_73 = V_83 ;
V_2 -> V_81 = 0 ;
} else {
V_2 -> V_71 = false ;
V_2 -> V_81 = F_62 ( V_72 ) ;
}
F_63 ( V_2 ) ;
if ( V_2 -> V_81 )
F_22 ( V_2 , V_6 , V_2 -> V_7 ,
L_14 ,
V_2 -> V_73 , V_2 -> V_81 ,
V_2 -> V_87 ) ;
else
F_22 ( V_2 , V_6 , V_2 -> V_7 ,
L_15 ,
V_2 -> V_73 , V_2 -> V_88 ,
V_2 -> V_89 , V_2 -> V_87 ) ;
V_2 -> V_7 -> V_90 |= V_2 -> V_7 -> V_69 ;
V_2 -> V_7 -> V_90 &= ~ V_2 -> V_91 ;
V_2 -> V_7 -> V_69 |= V_2 -> V_91 ;
if ( V_2 -> V_7 -> V_69 != V_68 )
F_64 ( V_2 -> V_7 ) ;
if ( V_2 -> V_71 != V_70 )
V_2 -> type -> V_92 ( V_2 ) ;
V_2 -> V_93 = V_2 -> V_36 - F_65 ( V_2 ) ;
V_2 -> V_94 = V_2 -> V_93 / 2 ;
F_54 (channel, efx) {
F_5 (tx_queue, channel) {
F_66 ( V_13 ) ;
F_67 ( & V_2 -> V_95 ) ;
}
F_49 (rx_queue, channel) {
F_68 ( V_19 ) ;
F_67 ( & V_2 -> V_95 ) ;
F_34 ( V_10 ) ;
F_10 ( V_19 , false ) ;
F_30 ( V_10 ) ;
}
F_69 ( V_10 -> V_96 ) ;
}
F_70 ( V_2 ) ;
if ( F_71 ( V_2 -> V_7 ) )
F_72 ( V_2 -> V_7 ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_12 * V_13 ;
struct V_18 * V_19 ;
int V_40 ;
F_74 ( V_2 ) ;
F_75 ( V_2 -> V_97 ) ;
F_76 ( V_2 ) ;
F_54 (channel, efx) {
F_49 (rx_queue, channel)
V_19 -> V_98 = false ;
}
F_54 (channel, efx) {
if ( F_7 ( V_10 ) ) {
F_34 ( V_10 ) ;
F_30 ( V_10 ) ;
}
}
V_40 = V_2 -> type -> V_99 ( V_2 ) ;
if ( V_40 && F_77 ( V_2 ) ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_16 ) ;
F_78 ( V_2 , V_100 ) ;
} else if ( V_40 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_17 ) ;
} else {
F_22 ( V_2 , V_6 , V_2 -> V_7 ,
L_18 ) ;
}
F_54 (channel, efx) {
F_49 (rx_queue, channel)
F_79 ( V_19 ) ;
F_80 (tx_queue, channel)
F_81 ( V_13 ) ;
}
}
static void F_51 ( struct V_9 * V_10 )
{
struct V_12 * V_13 ;
struct V_18 * V_19 ;
F_22 ( V_10 -> V_2 , V_6 , V_10 -> V_2 -> V_7 ,
L_19 , V_10 -> V_10 ) ;
F_49 (rx_queue, channel)
F_82 ( V_19 ) ;
F_80 (tx_queue, channel)
F_83 ( V_13 ) ;
F_40 ( V_10 ) ;
V_10 -> type -> V_101 ( V_10 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_54 (channel, efx)
F_51 ( V_10 ) ;
}
int
F_84 ( struct V_1 * V_2 , T_3 V_35 , T_3 V_36 )
{
struct V_9 * V_102 [ V_103 ] , * V_10 ;
T_3 V_104 , V_105 ;
unsigned V_44 , V_67 = 0 ;
int V_40 , V_106 ;
V_40 = F_1 ( V_2 ) ;
if ( V_40 )
return V_40 ;
F_54 (channel, efx) {
struct V_18 * V_19 ;
struct V_12 * V_13 ;
if ( V_10 -> type -> V_107 )
continue;
V_67 = F_25 ( V_67 ,
V_10 -> V_54 . V_108 +
V_10 -> V_54 . V_33 ) ;
F_49 (rx_queue, channel)
V_67 = F_25 ( V_67 ,
V_19 -> V_57 . V_108 +
V_19 -> V_57 . V_33 ) ;
F_5 (tx_queue, channel)
V_67 = F_25 ( V_67 ,
V_13 -> V_56 . V_108 +
V_13 -> V_56 . V_33 ) ;
}
F_85 ( V_2 ) ;
F_86 ( V_2 ) ;
F_87 ( V_2 ) ;
memset ( V_102 , 0 , sizeof( V_102 ) ) ;
for ( V_44 = 0 ; V_44 < V_2 -> V_109 ; V_44 ++ ) {
V_10 = V_2 -> V_10 [ V_44 ] ;
if ( V_10 -> type -> V_107 )
V_10 = V_10 -> type -> V_107 ( V_10 ) ;
if ( ! V_10 ) {
V_40 = - V_110 ;
goto V_111;
}
V_102 [ V_44 ] = V_10 ;
}
V_104 = V_2 -> V_35 ;
V_105 = V_2 -> V_36 ;
V_2 -> V_35 = V_35 ;
V_2 -> V_36 = V_36 ;
for ( V_44 = 0 ; V_44 < V_2 -> V_109 ; V_44 ++ ) {
V_10 = V_2 -> V_10 [ V_44 ] ;
V_2 -> V_10 [ V_44 ] = V_102 [ V_44 ] ;
V_102 [ V_44 ] = V_10 ;
}
V_2 -> V_67 = V_67 ;
for ( V_44 = 0 ; V_44 < V_2 -> V_109 ; V_44 ++ ) {
V_10 = V_2 -> V_10 [ V_44 ] ;
if ( ! V_10 -> type -> V_107 )
continue;
V_40 = F_47 ( V_10 ) ;
if ( V_40 )
goto V_112;
F_88 ( V_2 -> V_10 [ V_44 ] ) ;
}
V_111:
for ( V_44 = 0 ; V_44 < V_2 -> V_109 ; V_44 ++ ) {
V_10 = V_102 [ V_44 ] ;
if ( V_10 && V_10 -> type -> V_107 ) {
F_89 ( V_10 ) ;
F_51 ( V_10 ) ;
F_90 ( V_10 ) ;
}
}
V_106 = F_91 ( V_2 ) ;
if ( V_106 ) {
V_40 = V_40 ? V_40 : V_106 ;
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_20 ) ;
F_78 ( V_2 , V_113 ) ;
} else {
F_92 ( V_2 ) ;
F_93 ( V_2 -> V_7 ) ;
}
return V_40 ;
V_112:
V_2 -> V_35 = V_104 ;
V_2 -> V_36 = V_105 ;
for ( V_44 = 0 ; V_44 < V_2 -> V_109 ; V_44 ++ ) {
V_10 = V_2 -> V_10 [ V_44 ] ;
V_2 -> V_10 [ V_44 ] = V_102 [ V_44 ] ;
V_102 [ V_44 ] = V_10 ;
}
goto V_111;
}
void F_94 ( struct V_18 * V_19 )
{
F_95 ( & V_19 -> V_51 , V_114 + F_96 ( 100 ) ) ;
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
struct V_115 * V_116 = & V_2 -> V_116 ;
if ( ! F_100 ( V_2 -> V_7 ) )
return;
if ( V_116 -> V_117 != F_101 ( V_2 -> V_7 ) ) {
V_2 -> V_118 ++ ;
if ( V_116 -> V_117 )
F_102 ( V_2 -> V_7 ) ;
else
F_103 ( V_2 -> V_7 ) ;
}
if ( V_116 -> V_117 )
F_104 ( V_2 , V_119 , V_2 -> V_7 ,
L_21 ,
V_116 -> V_120 , V_116 -> V_121 ? L_22 : L_23 ,
V_2 -> V_7 -> V_75 ) ;
else
F_104 ( V_2 , V_119 , V_2 -> V_7 , L_24 ) ;
}
void F_105 ( struct V_1 * V_2 , T_3 V_122 )
{
V_2 -> V_123 = V_122 ;
if ( V_122 ) {
if ( V_122 & V_124 )
V_2 -> V_125 |= ( V_126 | V_127 ) ;
else
V_2 -> V_125 &= ~ ( V_126 | V_127 ) ;
if ( V_122 & V_128 )
V_2 -> V_125 ^= V_126 ;
}
}
void F_106 ( struct V_1 * V_2 , T_4 V_125 )
{
V_2 -> V_125 = V_125 ;
if ( V_2 -> V_123 ) {
if ( V_125 & V_127 )
V_2 -> V_123 |= ( V_124 |
V_128 ) ;
else
V_2 -> V_123 &= ~ ( V_124 |
V_128 ) ;
if ( V_125 & V_126 )
V_2 -> V_123 ^= V_128 ;
}
}
void F_107 ( struct V_1 * V_2 )
{
F_108 ( & V_2 -> V_129 ) ;
V_2 -> type -> V_130 ( V_2 ) ;
F_109 ( & V_2 -> V_129 ) ;
}
int F_110 ( struct V_1 * V_2 )
{
enum V_131 V_132 ;
int V_40 ;
F_69 ( ! F_111 ( & V_2 -> V_133 ) ) ;
V_132 = V_2 -> V_132 ;
if ( F_112 ( V_2 ) )
V_2 -> V_132 |= V_134 ;
else
V_2 -> V_132 &= ~ V_134 ;
V_40 = V_2 -> type -> V_135 ( V_2 ) ;
if ( V_40 )
V_2 -> V_132 = V_132 ;
return V_40 ;
}
int F_113 ( struct V_1 * V_2 )
{
int V_40 ;
F_74 ( V_2 ) ;
F_114 ( & V_2 -> V_133 ) ;
V_40 = F_110 ( V_2 ) ;
F_115 ( & V_2 -> V_133 ) ;
return V_40 ;
}
static void F_116 ( struct V_136 * V_137 )
{
struct V_1 * V_2 = F_13 ( V_137 , struct V_1 , V_138 ) ;
F_114 ( & V_2 -> V_133 ) ;
if ( V_2 -> V_97 )
F_107 ( V_2 ) ;
F_115 ( & V_2 -> V_133 ) ;
}
static int F_117 ( struct V_1 * V_2 )
{
int V_40 ;
F_22 ( V_2 , V_34 , V_2 -> V_7 , L_25 ) ;
if ( V_139 )
V_2 -> V_132 = V_140 ;
V_40 = V_2 -> type -> V_141 ( V_2 ) ;
if ( V_40 )
return V_40 ;
F_118 ( V_2 -> V_7 -> V_142 , V_2 -> V_7 -> V_143 ) ;
return 0 ;
}
static int F_119 ( struct V_1 * V_2 )
{
int V_40 ;
F_22 ( V_2 , V_6 , V_2 -> V_7 , L_26 ) ;
F_114 ( & V_2 -> V_133 ) ;
V_40 = V_2 -> V_144 -> V_145 ( V_2 ) ;
if ( V_40 )
goto V_146;
V_2 -> V_147 = true ;
F_107 ( V_2 ) ;
V_40 = V_2 -> V_144 -> V_148 ( V_2 ) ;
if ( V_40 && V_40 != - V_149 )
goto V_150;
F_115 ( & V_2 -> V_133 ) ;
return 0 ;
V_150:
V_2 -> V_144 -> V_151 ( V_2 ) ;
V_146:
F_115 ( & V_2 -> V_133 ) ;
return V_40 ;
}
static void F_120 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_43 , V_2 -> V_7 , L_27 ) ;
F_75 ( V_2 -> V_97 ) ;
F_114 ( & V_2 -> V_133 ) ;
V_2 -> V_97 = true ;
F_107 ( V_2 ) ;
F_115 ( & V_2 -> V_133 ) ;
}
static void F_121 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_152 , V_2 -> V_7 , L_28 ) ;
F_74 ( V_2 ) ;
F_114 ( & V_2 -> V_133 ) ;
V_2 -> V_97 = false ;
F_115 ( & V_2 -> V_133 ) ;
F_122 ( V_2 -> V_7 ) ;
F_123 ( V_2 -> V_7 ) ;
F_124 ( & V_2 -> V_153 ) ;
F_125 ( V_2 ) ;
F_126 ( & V_2 -> V_138 ) ;
}
static void F_127 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_6 , V_2 -> V_7 , L_29 ) ;
if ( ! V_2 -> V_147 )
return;
V_2 -> V_144 -> V_151 ( V_2 ) ;
V_2 -> V_147 = false ;
V_2 -> V_116 . V_117 = false ;
F_99 ( V_2 ) ;
}
static void F_128 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_6 , V_2 -> V_7 , L_30 ) ;
V_2 -> type -> V_154 ( V_2 ) ;
}
static bool F_129 ( struct V_1 * V_155 , struct V_1 * V_156 )
{
return V_155 -> type == V_156 -> type &&
V_155 -> V_157 && V_156 -> V_157 &&
! strcmp ( V_155 -> V_157 , V_156 -> V_157 ) ;
}
static void F_130 ( struct V_1 * V_2 )
{
struct V_1 * V_158 , * V_159 ;
if ( V_2 -> V_160 == V_2 ) {
F_22 ( V_2 , V_34 , V_2 -> V_7 , L_31 ) ;
F_131 ( & V_2 -> V_161 , & V_162 ) ;
F_132 (other, next, &efx_unassociated_list,
node) {
if ( F_129 ( V_2 , V_158 ) ) {
F_133 ( & V_158 -> V_161 ) ;
F_22 ( V_158 , V_34 , V_158 -> V_7 ,
L_32 ,
F_134 ( V_2 -> V_163 ) ,
V_2 -> V_7 -> V_64 ) ;
F_131 ( & V_158 -> V_161 ,
& V_2 -> V_164 ) ;
V_158 -> V_160 = V_2 ;
}
}
} else {
F_135 (other, &efx_primary_list, node) {
if ( F_129 ( V_2 , V_158 ) ) {
F_22 ( V_2 , V_34 , V_2 -> V_7 ,
L_33 ,
F_134 ( V_158 -> V_163 ) ,
V_158 -> V_7 -> V_64 ) ;
F_131 ( & V_2 -> V_161 ,
& V_158 -> V_164 ) ;
V_2 -> V_160 = V_158 ;
return;
}
}
F_22 ( V_2 , V_34 , V_2 -> V_7 ,
L_34 ) ;
F_131 ( & V_2 -> V_161 , & V_165 ) ;
}
}
static void F_136 ( struct V_1 * V_2 )
{
struct V_1 * V_158 , * V_159 ;
F_133 ( & V_2 -> V_161 ) ;
V_2 -> V_160 = NULL ;
F_132 (other, next, &efx->secondary_list, node) {
F_133 ( & V_158 -> V_161 ) ;
F_22 ( V_158 , V_34 , V_158 -> V_7 ,
L_35 ) ;
F_131 ( & V_158 -> V_161 , & V_165 ) ;
V_158 -> V_160 = NULL ;
}
}
static int F_137 ( struct V_1 * V_2 )
{
struct V_163 * V_163 = V_2 -> V_163 ;
T_5 V_166 = V_2 -> type -> V_167 ;
unsigned int V_168 = V_2 -> type -> V_168 ( V_2 ) ;
int V_40 , V_169 ;
F_22 ( V_2 , V_34 , V_2 -> V_7 , L_36 ) ;
V_169 = V_2 -> type -> V_170 ;
V_40 = F_138 ( V_163 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_34 , V_2 -> V_7 ,
L_37 ) ;
goto V_146;
}
F_139 ( V_163 ) ;
while ( V_166 > 0x7fffffffUL ) {
V_40 = F_140 ( & V_163 -> V_171 , V_166 ) ;
if ( V_40 == 0 )
break;
V_166 >>= 1 ;
}
if ( V_40 ) {
F_2 ( V_2 , V_34 , V_2 -> V_7 ,
L_38 ) ;
goto V_150;
}
F_22 ( V_2 , V_34 , V_2 -> V_7 ,
L_39 , ( unsigned long long ) V_166 ) ;
V_2 -> V_172 = F_141 ( V_2 -> V_163 , V_169 ) ;
V_40 = F_142 ( V_163 , V_169 , L_40 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_34 , V_2 -> V_7 ,
L_41 ) ;
V_40 = - V_8 ;
goto V_173;
}
V_2 -> V_174 = F_143 ( V_2 -> V_172 , V_168 ) ;
if ( ! V_2 -> V_174 ) {
F_2 ( V_2 , V_34 , V_2 -> V_7 ,
L_42 ,
( unsigned long long ) V_2 -> V_172 , V_168 ) ;
V_40 = - V_110 ;
goto V_175;
}
F_22 ( V_2 , V_34 , V_2 -> V_7 ,
L_43 ,
( unsigned long long ) V_2 -> V_172 , V_168 ,
V_2 -> V_174 ) ;
return 0 ;
V_175:
F_144 ( V_2 -> V_163 , V_169 ) ;
V_173:
V_2 -> V_172 = 0 ;
V_150:
F_145 ( V_2 -> V_163 ) ;
V_146:
return V_40 ;
}
static void F_146 ( struct V_1 * V_2 )
{
int V_169 ;
F_22 ( V_2 , V_6 , V_2 -> V_7 , L_44 ) ;
if ( V_2 -> V_174 ) {
F_147 ( V_2 -> V_174 ) ;
V_2 -> V_174 = NULL ;
}
if ( V_2 -> V_172 ) {
V_169 = V_2 -> type -> V_170 ;
F_144 ( V_2 -> V_163 , V_169 ) ;
V_2 -> V_172 = 0 ;
}
if ( ! F_148 ( V_2 -> V_163 ) )
F_145 ( V_2 -> V_163 ) ;
}
void F_149 ( struct V_1 * V_2 )
{
T_1 V_44 ;
for ( V_44 = 0 ; V_44 < F_150 ( V_2 -> V_176 ) ; V_44 ++ )
V_2 -> V_176 [ V_44 ] =
F_151 ( V_44 , V_2 -> V_177 ) ;
}
static unsigned int F_152 ( struct V_1 * V_2 )
{
T_6 V_178 ;
unsigned int V_179 ;
int V_180 ;
if ( V_181 ) {
V_179 = V_181 ;
} else {
if ( F_4 ( ! F_153 ( & V_178 , V_47 ) ) ) {
F_154 ( V_2 , V_34 , V_2 -> V_7 ,
L_45 ) ;
return 1 ;
}
V_179 = 0 ;
F_155 (cpu) {
if ( ! F_156 ( V_180 , V_178 ) ) {
++ V_179 ;
F_157 ( V_178 , V_178 ,
F_158 ( V_180 ) ) ;
}
}
F_159 ( V_178 ) ;
}
#ifdef F_160
if ( V_2 -> type -> V_182 ) {
if ( V_2 -> type -> V_182 ( V_2 ) && F_161 ( V_2 ) > 1 &&
V_179 > F_161 ( V_2 ) ) {
F_154 ( V_2 , V_34 , V_2 -> V_7 ,
L_46
L_47
L_48 ,
V_179 , F_161 ( V_2 ) ) ;
V_179 = F_161 ( V_2 ) ;
}
}
#endif
return V_179 ;
}
static int F_162 ( struct V_1 * V_2 )
{
unsigned int V_183 = 0 ;
unsigned int V_44 , V_46 ;
int V_40 ;
for ( V_44 = 0 ; V_44 < V_184 ; V_44 ++ )
if ( V_2 -> V_185 [ V_44 ] )
++ V_183 ;
if ( V_2 -> V_186 == V_187 ) {
struct V_188 V_189 [ V_103 ] ;
unsigned int V_109 ;
V_109 = F_152 ( V_2 ) ;
if ( V_190 )
V_109 *= 2 ;
V_109 += V_183 ;
V_109 = F_163 ( V_109 , V_2 -> V_191 ) ;
for ( V_44 = 0 ; V_44 < V_109 ; V_44 ++ )
V_189 [ V_44 ] . V_192 = V_44 ;
V_40 = F_164 ( V_2 -> V_163 ,
V_189 , 1 , V_109 ) ;
if ( V_40 < 0 ) {
V_2 -> V_186 = V_193 ;
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_49 ) ;
} else if ( V_40 < V_109 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_50
L_51 , V_40 , V_109 ) ;
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_52 ) ;
V_109 = V_40 ;
}
if ( V_40 > 0 ) {
V_2 -> V_109 = V_109 ;
if ( V_109 > V_183 )
V_109 -= V_183 ;
if ( V_190 ) {
V_2 -> V_194 = F_163 ( F_25 ( V_109 / 2 ,
1U ) ,
V_2 -> V_195 ) ;
V_2 -> V_196 = F_25 ( V_109 -
V_2 -> V_194 ,
1U ) ;
} else {
V_2 -> V_194 = F_163 ( V_109 ,
V_2 -> V_195 ) ;
V_2 -> V_196 = V_109 ;
}
for ( V_44 = 0 ; V_44 < V_2 -> V_109 ; V_44 ++ )
F_165 ( V_2 , V_44 ) -> V_197 =
V_189 [ V_44 ] . V_198 ;
}
}
if ( V_2 -> V_186 == V_193 ) {
V_2 -> V_109 = 1 ;
V_2 -> V_196 = 1 ;
V_2 -> V_194 = 1 ;
V_40 = F_166 ( V_2 -> V_163 ) ;
if ( V_40 == 0 ) {
F_165 ( V_2 , 0 ) -> V_197 = V_2 -> V_163 -> V_197 ;
} else {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_53 ) ;
V_2 -> V_186 = V_199 ;
}
}
if ( V_2 -> V_186 == V_199 ) {
V_2 -> V_109 = 1 + ( V_190 ? 1 : 0 ) ;
V_2 -> V_196 = 1 ;
V_2 -> V_194 = 1 ;
V_2 -> V_200 = V_2 -> V_163 -> V_197 ;
}
V_46 = V_2 -> V_109 ;
for ( V_44 = 0 ; V_44 < V_184 ; V_44 ++ ) {
if ( ! V_2 -> V_185 [ V_44 ] )
continue;
if ( V_2 -> V_186 != V_187 ||
V_2 -> V_109 <= V_183 ) {
V_2 -> V_185 [ V_44 ] -> F_167 ( V_2 ) ;
} else {
-- V_46 ;
F_165 ( V_2 , V_46 ) -> type =
V_2 -> V_185 [ V_44 ] ;
}
}
#ifdef F_160
if ( V_2 -> type -> V_182 ) {
V_2 -> V_177 = ( ( V_2 -> V_196 > 1 ||
! V_2 -> type -> V_182 ( V_2 ) ) ?
V_2 -> V_196 : F_161 ( V_2 ) ) ;
return 0 ;
}
#endif
V_2 -> V_177 = V_2 -> V_196 ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 )
{
struct V_9 * V_10 , * V_201 ;
int V_40 ;
F_75 ( V_2 -> V_3 == V_4 ) ;
V_2 -> V_202 = true ;
F_31 () ;
F_54 (channel, efx) {
if ( ! V_10 -> type -> V_203 ) {
V_40 = F_27 ( V_10 ) ;
if ( V_40 )
goto V_59;
}
F_30 ( V_10 ) ;
}
F_168 ( V_2 ) ;
return 0 ;
V_59:
V_201 = V_10 ;
F_54 (channel, efx) {
if ( V_10 == V_201 )
break;
F_34 ( V_10 ) ;
if ( ! V_10 -> type -> V_203 )
F_38 ( V_10 ) ;
}
return V_40 ;
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
if ( V_2 -> V_3 == V_4 )
return;
F_169 ( V_2 ) ;
V_2 -> V_202 = false ;
F_31 () ;
if ( V_2 -> V_200 )
F_170 ( V_2 -> V_200 ) ;
F_54 (channel, efx) {
if ( V_10 -> V_197 )
F_170 ( V_10 -> V_197 ) ;
F_34 ( V_10 ) ;
if ( ! V_10 -> type -> V_203 )
F_38 ( V_10 ) ;
}
F_171 ( V_2 ) ;
}
static int F_172 ( struct V_1 * V_2 )
{
struct V_9 * V_10 , * V_201 ;
int V_40 ;
F_75 ( V_2 -> V_3 == V_4 ) ;
if ( V_2 -> V_204 ) {
F_173 ( V_2 -> V_200 ) ;
V_2 -> V_204 = false ;
}
V_2 -> type -> V_205 ( V_2 ) ;
F_54 (channel, efx) {
if ( V_10 -> type -> V_203 ) {
V_40 = F_27 ( V_10 ) ;
if ( V_40 )
goto V_59;
}
}
V_40 = F_91 ( V_2 ) ;
if ( V_40 )
goto V_59;
return 0 ;
V_59:
V_201 = V_10 ;
F_54 (channel, efx) {
if ( V_10 == V_201 )
break;
if ( V_10 -> type -> V_203 )
F_38 ( V_10 ) ;
}
V_2 -> type -> V_206 ( V_2 ) ;
return V_40 ;
}
static void F_174 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_87 ( V_2 ) ;
F_54 (channel, efx) {
if ( V_10 -> type -> V_203 )
F_38 ( V_10 ) ;
}
V_2 -> type -> V_206 ( V_2 ) ;
}
static void F_175 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_54 (channel, efx)
V_10 -> V_197 = 0 ;
F_176 ( V_2 -> V_163 ) ;
F_177 ( V_2 -> V_163 ) ;
V_2 -> V_200 = 0 ;
}
static void F_178 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_12 * V_13 ;
V_2 -> V_63 =
V_190 ?
V_2 -> V_109 - V_2 -> V_194 : 0 ;
F_54 (channel, efx) {
if ( V_10 -> V_10 < V_2 -> V_196 )
V_10 -> V_19 . V_207 = V_10 -> V_10 ;
else
V_10 -> V_19 . V_207 = - 1 ;
F_5 (tx_queue, channel)
V_13 -> V_50 -= ( V_2 -> V_63 *
V_49 ) ;
}
}
static int F_179 ( struct V_1 * V_2 )
{
int V_40 ;
F_22 ( V_2 , V_34 , V_2 -> V_7 , L_54 ) ;
V_40 = V_2 -> type -> V_34 ( V_2 ) ;
if ( V_40 )
return V_40 ;
do {
if ( ! V_2 -> V_191 || ! V_2 -> V_195 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_55
L_56 ) ;
V_40 = - V_208 ;
goto V_146;
}
V_40 = F_162 ( V_2 ) ;
if ( V_40 )
goto V_146;
F_178 ( V_2 ) ;
V_40 = V_2 -> type -> V_209 ( V_2 ) ;
if ( V_40 != 0 && V_40 != - V_210 )
goto V_150;
if ( V_40 == - V_210 )
F_175 ( V_2 ) ;
} while ( V_40 == - V_210 );
if ( V_2 -> V_109 > 1 )
F_180 ( & V_2 -> V_211 ,
sizeof( V_2 -> V_211 ) ) ;
F_149 ( V_2 ) ;
F_181 ( V_2 -> V_7 , V_2 -> V_194 ) ;
F_182 ( V_2 -> V_7 , V_2 -> V_196 ) ;
F_183 ( V_2 , V_212 , V_213 , true ,
true ) ;
return 0 ;
V_150:
F_175 ( V_2 ) ;
V_146:
V_2 -> type -> remove ( V_2 ) ;
return V_40 ;
}
static void F_184 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_6 , V_2 -> V_7 , L_57 ) ;
F_175 ( V_2 ) ;
V_2 -> type -> remove ( V_2 ) ;
}
static int F_185 ( struct V_1 * V_2 )
{
int V_40 ;
F_186 ( & V_2 -> V_214 ) ;
F_187 ( & V_2 -> V_129 ) ;
F_114 ( & V_2 -> V_133 ) ;
F_188 ( & V_2 -> V_129 ) ;
V_40 = V_2 -> type -> V_215 ( V_2 ) ;
if ( V_40 )
goto V_216;
#ifdef F_189
if ( V_2 -> type -> V_217 & V_218 ) {
struct V_9 * V_10 ;
int V_44 , V_219 = 1 ;
F_54 (channel, efx) {
V_10 -> V_220 =
F_190 ( V_2 -> type -> V_221 ,
sizeof( * V_10 -> V_220 ) ,
V_47 ) ;
if ( ! V_10 -> V_220 )
V_219 = 0 ;
else
for ( V_44 = 0 ;
V_44 < V_2 -> type -> V_221 ;
++ V_44 )
V_10 -> V_220 [ V_44 ] =
V_222 ;
}
if ( ! V_219 ) {
F_54 (channel, efx)
F_90 ( V_10 -> V_220 ) ;
V_2 -> type -> V_223 ( V_2 ) ;
V_40 = - V_110 ;
goto V_216;
}
V_2 -> V_224 = V_2 -> V_225 = 0 ;
}
#endif
V_216:
F_191 ( & V_2 -> V_129 ) ;
F_115 ( & V_2 -> V_133 ) ;
return V_40 ;
}
static void F_192 ( struct V_1 * V_2 )
{
#ifdef F_189
struct V_9 * V_10 ;
F_54 (channel, efx)
F_90 ( V_10 -> V_220 ) ;
#endif
F_188 ( & V_2 -> V_129 ) ;
V_2 -> type -> V_223 ( V_2 ) ;
F_191 ( & V_2 -> V_129 ) ;
}
static void F_193 ( struct V_1 * V_2 )
{
F_108 ( & V_2 -> V_129 ) ;
V_2 -> type -> V_226 ( V_2 ) ;
F_109 ( & V_2 -> V_129 ) ;
}
static int F_194 ( struct V_1 * V_2 )
{
int V_40 ;
V_40 = F_179 ( V_2 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_34 , V_2 -> V_7 , L_58 ) ;
goto V_146;
}
V_40 = F_117 ( V_2 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_34 , V_2 -> V_7 , L_59 ) ;
goto V_150;
}
F_60 ( V_227 < V_228 ) ;
if ( F_69 ( V_227 < F_195 ( V_2 ) ) ) {
V_40 = - V_229 ;
goto V_173;
}
V_2 -> V_35 = V_2 -> V_36 = V_227 ;
#ifdef F_160
V_40 = V_2 -> type -> V_230 ( V_2 ) ;
if ( V_40 )
F_154 ( V_2 , V_34 , V_2 -> V_7 ,
L_60
L_61 , V_40 ) ;
#endif
V_40 = F_185 ( V_2 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_34 , V_2 -> V_7 ,
L_62 ) ;
goto V_175;
}
V_40 = F_55 ( V_2 ) ;
if ( V_40 )
goto V_231;
return 0 ;
V_231:
F_192 ( V_2 ) ;
V_175:
#ifdef F_160
V_2 -> type -> V_232 ( V_2 ) ;
#endif
V_173:
F_128 ( V_2 ) ;
V_150:
F_184 ( V_2 ) ;
V_146:
return V_40 ;
}
static void F_92 ( struct V_1 * V_2 )
{
F_74 ( V_2 ) ;
F_75 ( V_2 -> V_3 == V_4 ) ;
if ( V_2 -> V_97 || ! F_100 ( V_2 -> V_7 ) ||
V_2 -> V_233 )
return;
F_120 ( V_2 ) ;
F_58 ( V_2 ) ;
if ( V_2 -> type -> V_234 != NULL )
F_196 ( V_2 -> V_235 , & V_2 -> V_153 ,
V_236 ) ;
if ( F_197 ( V_2 ) >= V_237 ) {
F_114 ( & V_2 -> V_133 ) ;
if ( V_2 -> V_144 -> V_238 ( V_2 ) )
F_99 ( V_2 ) ;
F_115 ( & V_2 -> V_133 ) ;
}
V_2 -> type -> V_239 ( V_2 ) ;
V_2 -> type -> V_240 ( V_2 ) ;
F_198 ( & V_2 -> V_241 ) ;
V_2 -> type -> V_242 ( V_2 , NULL , NULL ) ;
F_199 ( & V_2 -> V_241 ) ;
}
static void F_86 ( struct V_1 * V_2 )
{
F_74 ( V_2 ) ;
if ( ! V_2 -> V_97 )
return;
V_2 -> type -> V_240 ( V_2 ) ;
F_198 ( & V_2 -> V_241 ) ;
V_2 -> type -> V_242 ( V_2 , NULL , NULL ) ;
F_199 ( & V_2 -> V_241 ) ;
V_2 -> type -> V_243 ( V_2 ) ;
F_121 ( V_2 ) ;
F_69 ( F_100 ( V_2 -> V_7 ) &&
F_71 ( V_2 -> V_7 ) ) ;
F_200 ( V_2 -> V_7 ) ;
F_73 ( V_2 ) ;
}
static void F_201 ( struct V_1 * V_2 )
{
F_57 ( V_2 ) ;
F_192 ( V_2 ) ;
#ifdef F_160
V_2 -> type -> V_232 ( V_2 ) ;
#endif
F_128 ( V_2 ) ;
F_184 ( V_2 ) ;
}
static unsigned int F_202 ( unsigned int V_244 , unsigned int V_245 )
{
if ( V_244 == 0 )
return 0 ;
if ( V_244 * 1000 < V_245 )
return 1 ;
return V_244 * 1000 / V_245 ;
}
int F_183 ( struct V_1 * V_2 , unsigned int V_246 ,
unsigned int V_247 , bool V_248 ,
bool V_249 )
{
struct V_9 * V_10 ;
unsigned int V_250 = F_203 ( V_2 -> type -> V_251 *
V_2 -> V_252 ,
1000 ) ;
unsigned int V_253 ;
unsigned int V_254 ;
F_74 ( V_2 ) ;
if ( V_246 > V_250 || V_247 > V_250 )
return - V_229 ;
V_253 = F_202 ( V_246 , V_2 -> V_252 ) ;
V_254 = F_202 ( V_247 , V_2 -> V_252 ) ;
if ( V_253 != V_254 && V_2 -> V_63 == 0 &&
! V_249 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_63
L_64 ) ;
return - V_229 ;
}
V_2 -> V_25 = V_248 ;
V_2 -> V_32 = V_254 ;
F_54 (channel, efx) {
if ( F_7 ( V_10 ) )
V_10 -> V_29 = V_254 ;
else if ( F_204 ( V_10 ) )
V_10 -> V_29 = V_253 ;
}
return 0 ;
}
void F_205 ( struct V_1 * V_2 , unsigned int * V_246 ,
unsigned int * V_247 , bool * V_248 )
{
* V_248 = V_2 -> V_25 ;
* V_247 = F_203 ( V_2 -> V_32 *
V_2 -> V_252 ,
1000 ) ;
if ( V_2 -> V_63 == 0 )
* V_246 = * V_247 ;
else
* V_246 = F_203 (
V_2 -> V_10 [ V_2 -> V_63 ] -> V_29 *
V_2 -> V_252 ,
1000 ) ;
}
static void F_206 ( struct V_136 * V_137 )
{
struct V_1 * V_2 = F_13 ( V_137 , struct V_1 ,
V_153 . V_255 ) ;
F_15 ( V_2 , V_256 , V_2 -> V_7 ,
L_65 ,
F_16 () ) ;
F_75 ( V_2 -> type -> V_234 == NULL ) ;
if ( F_207 ( & V_2 -> V_133 ) ) {
if ( V_2 -> V_97 )
V_2 -> type -> V_234 ( V_2 ) ;
F_115 ( & V_2 -> V_133 ) ;
}
F_196 ( V_2 -> V_235 , & V_2 -> V_153 ,
V_236 ) ;
}
static int F_208 ( struct V_257 * V_7 , struct V_258 * V_259 , int V_260 )
{
struct V_1 * V_2 = F_209 ( V_7 ) ;
struct V_261 * V_137 = F_210 ( V_259 ) ;
if ( V_260 == V_262 )
return F_211 ( V_2 , V_259 ) ;
if ( V_260 == V_263 )
return F_212 ( V_2 , V_259 ) ;
if ( ( V_260 == V_264 || V_260 == V_265 ) &&
( V_137 -> V_266 & 0xfc00 ) == 0x0400 )
V_137 -> V_266 ^= V_267 | 0x0400 ;
return F_213 ( & V_2 -> V_268 , V_137 , V_260 ) ;
}
static void F_88 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
V_10 -> V_53 = V_2 -> V_7 ;
F_214 ( V_10 -> V_53 , & V_10 -> V_23 ,
F_12 , V_269 ) ;
F_215 ( V_10 ) ;
}
static void F_216 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_54 (channel, efx)
F_88 ( V_10 ) ;
}
static void F_89 ( struct V_9 * V_10 )
{
if ( V_10 -> V_53 ) {
F_217 ( & V_10 -> V_23 ) ;
F_218 ( & V_10 -> V_23 ) ;
}
V_10 -> V_53 = NULL ;
}
static void F_219 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_54 (channel, efx)
F_89 ( V_10 ) ;
}
static void F_220 ( struct V_257 * V_7 )
{
struct V_1 * V_2 = F_209 ( V_7 ) ;
struct V_9 * V_10 ;
F_54 (channel, efx)
F_221 ( V_10 ) ;
}
static int F_222 ( struct V_21 * V_22 )
{
struct V_9 * V_10 =
F_13 ( V_22 , struct V_9 , V_23 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_11 = 4 ;
int V_270 , V_271 ;
if ( ! F_100 ( V_2 -> V_7 ) )
return V_272 ;
if ( ! F_223 ( V_10 ) )
return V_273 ;
V_270 = V_10 -> V_19 . V_271 ;
F_3 ( V_10 , V_11 ) ;
V_271 = V_10 -> V_19 . V_271 - V_270 ;
F_224 ( V_10 ) ;
return V_271 ;
}
int F_225 ( struct V_257 * V_7 )
{
struct V_1 * V_2 = F_209 ( V_7 ) ;
int V_40 ;
F_22 ( V_2 , V_43 , V_2 -> V_7 , L_66 ,
F_16 () ) ;
V_40 = F_1 ( V_2 ) ;
if ( V_40 )
return V_40 ;
if ( V_2 -> V_132 & V_140 )
return - V_274 ;
if ( F_226 ( V_2 ) && F_227 ( V_2 , V_100 ) )
return - V_8 ;
F_99 ( V_2 ) ;
F_92 ( V_2 ) ;
F_228 ( V_2 ) ;
return 0 ;
}
int F_229 ( struct V_257 * V_7 )
{
struct V_1 * V_2 = F_209 ( V_7 ) ;
F_22 ( V_2 , V_152 , V_2 -> V_7 , L_67 ,
F_16 () ) ;
F_86 ( V_2 ) ;
return 0 ;
}
static struct V_275 * F_230 ( struct V_257 * V_7 ,
struct V_275 * V_276 )
{
struct V_1 * V_2 = F_209 ( V_7 ) ;
F_198 ( & V_2 -> V_241 ) ;
V_2 -> type -> V_242 ( V_2 , NULL , V_276 ) ;
F_199 ( & V_2 -> V_241 ) ;
return V_276 ;
}
static void F_231 ( struct V_257 * V_7 )
{
struct V_1 * V_2 = F_209 ( V_7 ) ;
F_2 ( V_2 , V_277 , V_2 -> V_7 ,
L_68 ,
V_2 -> V_97 ) ;
F_78 ( V_2 , V_278 ) ;
}
static int F_232 ( struct V_257 * V_7 , int V_279 )
{
struct V_1 * V_2 = F_209 ( V_7 ) ;
int V_40 ;
V_40 = F_1 ( V_2 ) ;
if ( V_40 )
return V_40 ;
if ( V_279 > V_280 )
return - V_229 ;
F_22 ( V_2 , V_6 , V_2 -> V_7 , L_69 , V_279 ) ;
F_85 ( V_2 ) ;
F_86 ( V_2 ) ;
F_114 ( & V_2 -> V_133 ) ;
V_7 -> V_75 = V_279 ;
F_107 ( V_2 ) ;
F_115 ( & V_2 -> V_133 ) ;
F_92 ( V_2 ) ;
F_93 ( V_2 -> V_7 ) ;
return 0 ;
}
static int F_233 ( struct V_257 * V_7 , void * V_137 )
{
struct V_1 * V_2 = F_209 ( V_7 ) ;
struct V_281 * V_282 = V_137 ;
T_4 * V_283 = V_282 -> V_284 ;
T_4 V_285 [ 6 ] ;
int V_40 ;
if ( ! F_234 ( V_283 ) ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_70 ,
V_283 ) ;
return - V_286 ;
}
F_118 ( V_285 , V_7 -> V_142 ) ;
F_118 ( V_7 -> V_142 , V_283 ) ;
if ( V_2 -> type -> V_287 ) {
V_40 = V_2 -> type -> V_287 ( V_2 ) ;
if ( V_40 ) {
F_118 ( V_7 -> V_142 , V_285 ) ;
return V_40 ;
}
}
F_114 ( & V_2 -> V_133 ) ;
F_107 ( V_2 ) ;
F_115 ( & V_2 -> V_133 ) ;
return 0 ;
}
static void F_235 ( struct V_257 * V_7 )
{
struct V_1 * V_2 = F_209 ( V_7 ) ;
if ( V_2 -> V_97 )
F_236 ( V_2 -> V_235 , & V_2 -> V_138 ) ;
}
static int F_237 ( struct V_257 * V_7 , T_2 V_137 )
{
struct V_1 * V_2 = F_209 ( V_7 ) ;
int V_40 ;
if ( V_7 -> V_69 & ~ V_137 & V_218 ) {
V_40 = V_2 -> type -> V_288 ( V_2 , V_289 ) ;
if ( V_40 )
return V_40 ;
}
if ( ( V_7 -> V_69 ^ V_137 ) & V_290 ) {
F_235 ( V_7 ) ;
}
return 0 ;
}
static int F_238 ( struct V_257 * V_7 , T_7 V_291 , T_8 V_292 )
{
struct V_1 * V_2 = F_209 ( V_7 ) ;
if ( V_2 -> type -> V_293 )
return V_2 -> type -> V_293 ( V_2 , V_291 , V_292 ) ;
else
return - V_294 ;
}
static int F_239 ( struct V_257 * V_7 , T_7 V_291 , T_8 V_292 )
{
struct V_1 * V_2 = F_209 ( V_7 ) ;
if ( V_2 -> type -> V_295 )
return V_2 -> type -> V_295 ( V_2 , V_291 , V_292 ) ;
else
return - V_294 ;
}
static void F_240 ( struct V_1 * V_2 )
{
strcpy ( V_2 -> V_64 , V_2 -> V_7 -> V_64 ) ;
F_241 ( V_2 ) ;
F_53 ( V_2 ) ;
}
static int F_242 ( struct V_296 * V_297 ,
unsigned long V_298 , void * V_299 )
{
struct V_257 * V_7 = F_243 ( V_299 ) ;
if ( ( V_7 -> V_300 == & V_301 ) &&
V_298 == V_302 )
F_240 ( F_209 ( V_7 ) ) ;
return V_303 ;
}
static T_9
F_244 ( struct V_304 * V_171 , struct V_305 * V_306 , char * V_60 )
{
struct V_1 * V_2 = F_245 ( F_246 ( V_171 ) ) ;
return sprintf ( V_60 , L_71 , V_2 -> V_307 ) ;
}
static T_9 F_247 ( struct V_304 * V_171 , struct V_305 * V_306 ,
char * V_60 )
{
struct V_1 * V_2 = F_245 ( F_246 ( V_171 ) ) ;
struct V_308 * V_309 = F_248 ( V_2 ) ;
return F_249 ( V_60 , V_79 , L_71 , V_309 -> V_310 ) ;
}
static T_9 F_250 ( struct V_304 * V_171 , struct V_305 * V_306 ,
const char * V_60 , T_1 V_179 )
{
struct V_1 * V_2 = F_245 ( F_246 ( V_171 ) ) ;
struct V_308 * V_309 = F_248 ( V_2 ) ;
bool V_311 = V_179 > 0 && * V_60 != '0' ;
V_309 -> V_310 = V_311 ;
return V_179 ;
}
static int F_251 ( struct V_1 * V_2 )
{
struct V_257 * V_7 = V_2 -> V_7 ;
struct V_9 * V_10 ;
int V_40 ;
V_7 -> V_312 = 5 * V_313 ;
V_7 -> V_197 = V_2 -> V_163 -> V_197 ;
V_7 -> V_300 = & V_301 ;
if ( F_197 ( V_2 ) >= V_314 )
V_7 -> V_315 |= V_316 ;
V_7 -> V_317 = & V_318 ;
V_7 -> V_319 = V_320 ;
F_252 () ;
V_2 -> V_3 = V_321 ;
F_253 () ;
if ( V_2 -> V_233 ) {
F_2 ( V_2 , V_34 , V_2 -> V_7 ,
L_72 ) ;
V_40 = - V_8 ;
goto V_322;
}
V_40 = F_254 ( V_7 , V_7 -> V_64 ) ;
if ( V_40 < 0 )
goto V_322;
F_240 ( V_2 ) ;
F_103 ( V_7 ) ;
V_40 = F_255 ( V_7 ) ;
if ( V_40 )
goto V_322;
F_54 (channel, efx) {
struct V_12 * V_13 ;
F_5 (tx_queue, channel)
F_256 ( V_13 ) ;
}
F_130 ( V_2 ) ;
F_257 () ;
V_40 = F_258 ( & V_2 -> V_163 -> V_171 , & V_323 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_73 ) ;
goto V_324;
}
#ifdef F_259
V_40 = F_258 ( & V_2 -> V_163 -> V_171 , & V_325 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_73 ) ;
goto V_326;
}
#endif
return 0 ;
#ifdef F_259
V_326:
F_260 ( & V_2 -> V_163 -> V_171 , & V_323 ) ;
#endif
V_324:
F_252 () ;
F_136 ( V_2 ) ;
F_261 ( V_7 ) ;
V_322:
V_2 -> V_3 = V_327 ;
F_257 () ;
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_74 ) ;
return V_40 ;
}
static void F_262 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_7 )
return;
F_75 ( F_209 ( V_2 -> V_7 ) != V_2 ) ;
if ( F_263 ( V_2 ) ) {
F_264 ( V_2 -> V_64 , F_134 ( V_2 -> V_163 ) , sizeof( V_2 -> V_64 ) ) ;
#ifdef F_259
F_260 ( & V_2 -> V_163 -> V_171 , & V_325 ) ;
#endif
F_260 ( & V_2 -> V_163 -> V_171 , & V_323 ) ;
F_265 ( V_2 -> V_7 ) ;
}
}
void F_266 ( struct V_1 * V_2 , enum V_328 V_329 )
{
F_74 ( V_2 ) ;
if ( V_329 == V_330 )
V_2 -> type -> V_331 ( V_2 ) ;
F_86 ( V_2 ) ;
F_174 ( V_2 ) ;
F_114 ( & V_2 -> V_133 ) ;
if ( V_2 -> V_147 && V_329 != V_332 &&
V_329 != V_333 )
V_2 -> V_144 -> V_151 ( V_2 ) ;
V_2 -> type -> V_151 ( V_2 ) ;
}
int F_267 ( struct V_1 * V_2 , enum V_328 V_329 , bool V_334 )
{
int V_40 ;
F_74 ( V_2 ) ;
if ( V_329 == V_330 )
V_2 -> type -> V_335 ( V_2 ) ;
V_40 = V_2 -> type -> V_145 ( V_2 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_75 ) ;
goto V_59;
}
if ( ! V_334 )
goto V_59;
if ( V_2 -> V_147 && V_329 != V_332 &&
V_329 != V_333 ) {
V_40 = V_2 -> V_144 -> V_145 ( V_2 ) ;
if ( V_40 )
goto V_59;
V_40 = V_2 -> V_144 -> V_148 ( V_2 ) ;
if ( V_40 && V_40 != - V_149 )
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_76 ) ;
}
V_40 = F_172 ( V_2 ) ;
if ( V_40 )
goto V_59;
#ifdef F_160
V_40 = V_2 -> type -> V_336 ( V_2 ) ;
if ( V_40 )
F_154 ( V_2 , V_34 , V_2 -> V_7 ,
L_77
L_61 , V_40 ) ;
#endif
F_108 ( & V_2 -> V_129 ) ;
F_193 ( V_2 ) ;
F_109 ( & V_2 -> V_129 ) ;
if ( V_2 -> type -> V_337 )
V_2 -> type -> V_337 ( V_2 ) ;
F_115 ( & V_2 -> V_133 ) ;
F_92 ( V_2 ) ;
return 0 ;
V_59:
V_2 -> V_147 = false ;
F_115 ( & V_2 -> V_133 ) ;
return V_40 ;
}
int F_227 ( struct V_1 * V_2 , enum V_328 V_329 )
{
int V_40 , V_106 ;
bool V_338 ;
F_104 ( V_2 , V_6 , V_2 -> V_7 , L_78 ,
F_268 ( V_329 ) ) ;
F_85 ( V_2 ) ;
F_266 ( V_2 , V_329 ) ;
V_40 = V_2 -> type -> V_339 ( V_2 , V_329 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_79 ) ;
goto V_111;
}
if ( V_329 < V_340 )
V_2 -> V_233 &= - ( 1 << ( V_329 + 1 ) ) ;
else
F_269 ( V_329 , & V_2 -> V_233 ) ;
F_139 ( V_2 -> V_163 ) ;
V_111:
V_338 = V_40 ||
V_329 == V_113 ||
V_329 == V_341 ;
V_106 = F_267 ( V_2 , V_329 , ! V_338 ) ;
if ( V_106 ) {
V_338 = true ;
if ( ! V_40 )
V_40 = V_106 ;
}
if ( V_338 ) {
F_270 ( V_2 -> V_7 ) ;
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_80 ) ;
V_2 -> V_3 = V_4 ;
} else {
F_22 ( V_2 , V_6 , V_2 -> V_7 , L_81 ) ;
F_93 ( V_2 -> V_7 ) ;
}
return V_40 ;
}
int F_271 ( struct V_1 * V_2 )
{
#ifdef F_272
struct V_342 * V_343 = F_273 ( V_2 -> V_163 ) ;
if ( F_274 ( V_343 ) ) {
return 1 ;
}
#endif
return 0 ;
}
static void F_275 ( struct V_1 * V_2 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_344 ; ++ V_44 ) {
if ( F_226 ( V_2 ) )
goto V_111;
F_276 ( V_345 ) ;
}
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_82 ) ;
V_111:
V_2 -> V_346 = false ;
}
static void F_277 ( struct V_136 * V_137 )
{
struct V_1 * V_2 = F_13 ( V_137 , struct V_1 , V_347 ) ;
unsigned long V_348 ;
enum V_328 V_329 ;
V_348 = F_278 ( V_2 -> V_233 ) ;
V_329 = F_279 ( V_348 ) - 1 ;
if ( V_329 == V_349 )
F_275 ( V_2 ) ;
if ( ( V_329 == V_341 ||
V_329 == V_350 ) &&
F_271 ( V_2 ) )
return;
if ( ! V_348 )
return;
F_252 () ;
if ( V_2 -> V_3 == V_321 )
( void ) F_227 ( V_2 , V_329 ) ;
F_257 () ;
}
void F_78 ( struct V_1 * V_2 , enum V_328 type )
{
enum V_328 V_329 ;
if ( V_2 -> V_3 == V_5 ) {
F_22 ( V_2 , V_6 , V_2 -> V_7 ,
L_83 ,
F_268 ( type ) ) ;
return;
}
switch ( type ) {
case V_332 :
case V_100 :
case V_350 :
case V_351 :
case V_113 :
case V_341 :
case V_333 :
case V_349 :
case V_330 :
V_329 = type ;
F_22 ( V_2 , V_6 , V_2 -> V_7 , L_84 ,
F_268 ( V_329 ) ) ;
break;
default:
V_329 = V_2 -> type -> V_352 ( type ) ;
F_22 ( V_2 , V_6 , V_2 -> V_7 ,
L_85 ,
F_268 ( V_329 ) , F_268 ( type ) ) ;
break;
}
F_280 ( V_329 , & V_2 -> V_233 ) ;
F_253 () ;
if ( F_278 ( V_2 -> V_3 ) != V_321 )
return;
F_169 ( V_2 ) ;
F_236 ( V_353 , & V_2 -> V_347 ) ;
}
int F_281 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_282 ( struct V_1 * V_2 ) {}
static bool F_283 ( struct V_1 * V_2 )
{
return false ;
}
static int F_284 ( struct V_1 * V_2 ,
struct V_163 * V_163 , struct V_257 * V_7 )
{
int V_44 ;
F_285 ( & V_2 -> V_161 ) ;
F_285 ( & V_2 -> V_164 ) ;
F_186 ( & V_2 -> V_354 ) ;
#ifdef F_286
F_285 ( & V_2 -> V_355 ) ;
#endif
F_287 ( & V_2 -> V_347 , F_277 ) ;
F_288 ( & V_2 -> V_153 , F_206 ) ;
F_288 ( & V_2 -> V_356 , V_357 ) ;
V_2 -> V_163 = V_163 ;
V_2 -> V_358 = V_359 ;
V_2 -> V_3 = V_327 ;
F_264 ( V_2 -> V_64 , F_134 ( V_163 ) , sizeof( V_2 -> V_64 ) ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_74 = V_2 -> type -> V_74 ;
V_2 -> V_78 =
V_85 ? ( V_2 -> V_74 + V_85 ) % 4 : 0 ;
V_2 -> V_360 =
V_2 -> type -> V_361 - V_2 -> type -> V_74 ;
V_2 -> V_362 =
V_2 -> type -> V_363 - V_2 -> type -> V_74 ;
F_186 ( & V_2 -> V_241 ) ;
F_289 ( & V_2 -> V_133 ) ;
V_2 -> V_144 = & V_364 ;
V_2 -> V_268 . V_171 = V_7 ;
F_287 ( & V_2 -> V_138 , F_116 ) ;
F_290 ( & V_2 -> V_365 ) ;
for ( V_44 = 0 ; V_44 < V_103 ; V_44 ++ ) {
V_2 -> V_10 [ V_44 ] = F_42 ( V_2 , V_44 , NULL ) ;
if ( ! V_2 -> V_10 [ V_44 ] )
goto V_59;
V_2 -> V_66 [ V_44 ] . V_2 = V_2 ;
V_2 -> V_66 [ V_44 ] . V_108 = V_44 ;
}
V_2 -> V_186 = F_25 ( V_2 -> type -> V_366 ,
V_186 ) ;
snprintf ( V_2 -> V_367 , sizeof( V_2 -> V_367 ) , L_86 ,
F_134 ( V_163 ) ) ;
V_2 -> V_235 = F_291 ( V_2 -> V_367 ) ;
if ( ! V_2 -> V_235 )
goto V_59;
return 0 ;
V_59:
F_292 ( V_2 ) ;
return - V_110 ;
}
static void F_292 ( struct V_1 * V_2 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_103 ; V_44 ++ )
F_90 ( V_2 -> V_10 [ V_44 ] ) ;
F_90 ( V_2 -> V_157 ) ;
if ( V_2 -> V_235 ) {
F_293 ( V_2 -> V_235 ) ;
V_2 -> V_235 = NULL ;
}
}
void F_294 ( struct V_1 * V_2 , T_10 * V_276 )
{
T_10 V_368 = 0 ;
struct V_9 * V_10 ;
F_54 (channel, efx)
V_368 += V_10 -> V_368 ;
V_276 [ V_369 ] = V_368 ;
V_276 [ V_370 ] = F_295 ( & V_2 -> V_371 ) ;
}
static void F_296 ( struct V_1 * V_2 )
{
F_75 ( V_2 -> V_3 == V_321 ) ;
F_126 ( & V_2 -> V_347 ) ;
F_174 ( V_2 ) ;
F_297 ( V_2 ) ;
F_127 ( V_2 ) ;
V_2 -> type -> V_151 ( V_2 ) ;
F_219 ( V_2 ) ;
F_201 ( V_2 ) ;
}
static void F_298 ( struct V_163 * V_163 )
{
struct V_1 * V_2 ;
V_2 = F_245 ( V_163 ) ;
if ( ! V_2 )
return;
F_252 () ;
F_136 ( V_2 ) ;
F_270 ( V_2 -> V_7 ) ;
F_174 ( V_2 ) ;
V_2 -> V_3 = V_327 ;
F_257 () ;
if ( V_2 -> type -> V_372 )
V_2 -> type -> V_372 ( V_2 ) ;
F_262 ( V_2 ) ;
F_299 ( V_2 ) ;
F_296 ( V_2 ) ;
F_146 ( V_2 ) ;
F_22 ( V_2 , V_6 , V_2 -> V_7 , L_87 ) ;
F_292 ( V_2 ) ;
F_300 ( V_2 -> V_7 ) ;
F_301 ( V_163 ) ;
}
static void F_302 ( struct V_1 * V_2 )
{
struct V_163 * V_171 = V_2 -> V_163 ;
char V_373 [ V_374 ] ;
T_9 V_375 ;
int V_376 , V_377 , V_44 , V_46 ;
V_375 = F_303 ( V_171 , 0 , sizeof( V_373 ) , V_373 ) ;
if ( V_375 <= 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_88 ) ;
return;
}
V_376 = F_304 ( V_373 , 0 , V_375 , V_378 ) ;
if ( V_376 < 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_89 ) ;
return;
}
V_377 = F_305 ( & V_373 [ V_376 ] ) ;
V_46 = V_377 ;
V_44 = V_376 + V_379 ;
if ( V_44 + V_46 > V_375 )
V_46 = V_375 - V_44 ;
V_44 = F_306 ( V_373 , V_44 , V_46 , L_90 ) ;
if ( V_44 < 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_91 ) ;
return;
}
V_46 = F_307 ( & V_373 [ V_44 ] ) ;
V_44 += V_380 ;
if ( V_44 + V_46 > V_375 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_92 ) ;
return;
}
F_104 ( V_2 , V_6 , V_2 -> V_7 ,
L_93 , V_46 , & V_373 [ V_44 ] ) ;
V_44 = V_376 + V_379 ;
V_46 = V_377 ;
V_44 = F_306 ( V_373 , V_44 , V_46 , L_94 ) ;
if ( V_44 < 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_95 ) ;
return;
}
V_46 = F_307 ( & V_373 [ V_44 ] ) ;
V_44 += V_380 ;
if ( V_44 + V_46 > V_375 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_96 ) ;
return;
}
V_2 -> V_157 = F_46 ( V_46 + 1 , V_47 ) ;
if ( ! V_2 -> V_157 )
return;
snprintf ( V_2 -> V_157 , V_46 + 1 , L_97 , & V_373 [ V_44 ] ) ;
}
static int F_308 ( struct V_1 * V_2 )
{
int V_40 ;
V_40 = F_194 ( V_2 ) ;
if ( V_40 )
goto V_146;
F_216 ( V_2 ) ;
V_40 = V_2 -> type -> V_145 ( V_2 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_34 , V_2 -> V_7 ,
L_75 ) ;
goto V_173;
}
V_40 = F_119 ( V_2 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_34 , V_2 -> V_7 ,
L_98 ) ;
goto V_175;
}
V_40 = F_309 ( V_2 ) ;
if ( V_40 )
goto V_231;
V_40 = F_172 ( V_2 ) ;
if ( V_40 )
goto V_381;
return 0 ;
V_381:
F_297 ( V_2 ) ;
V_231:
F_127 ( V_2 ) ;
V_175:
V_2 -> type -> V_151 ( V_2 ) ;
V_173:
F_219 ( V_2 ) ;
F_201 ( V_2 ) ;
V_146:
return V_40 ;
}
static int F_310 ( struct V_163 * V_163 ,
const struct V_382 * V_192 )
{
struct V_257 * V_7 ;
struct V_1 * V_2 ;
int V_40 ;
V_7 = F_311 ( sizeof( * V_2 ) , V_383 ,
V_384 ) ;
if ( ! V_7 )
return - V_110 ;
V_2 = F_209 ( V_7 ) ;
V_2 -> type = ( const struct V_385 * ) V_192 -> V_386 ;
V_2 -> V_91 |= V_387 ;
V_7 -> V_69 |= ( V_2 -> type -> V_217 | V_388 |
V_389 | V_390 ) ;
if ( V_2 -> type -> V_217 & ( V_391 | V_392 ) )
V_7 -> V_69 |= V_393 ;
V_7 -> V_394 |= ( V_392 | V_388 |
V_387 | V_395 |
V_390 ) ;
V_7 -> V_90 = V_7 -> V_69 & ~ V_2 -> V_91 ;
V_7 -> V_69 &= ~ V_290 ;
V_7 -> V_69 |= V_2 -> V_91 ;
F_312 ( V_163 , V_2 ) ;
F_313 ( V_7 , & V_163 -> V_171 ) ;
V_40 = F_284 ( V_2 , V_163 , V_7 ) ;
if ( V_40 )
goto V_146;
F_104 ( V_2 , V_34 , V_2 -> V_7 ,
L_99 ) ;
if ( ! V_2 -> type -> V_396 )
F_302 ( V_2 ) ;
V_40 = F_137 ( V_2 ) ;
if ( V_40 )
goto V_150;
V_40 = F_308 ( V_2 ) ;
if ( V_40 )
goto V_173;
V_40 = F_251 ( V_2 ) ;
if ( V_40 )
goto V_175;
if ( V_2 -> type -> V_397 ) {
V_40 = V_2 -> type -> V_397 ( V_2 ) ;
if ( V_40 )
F_2 ( V_2 , V_34 , V_2 -> V_7 ,
L_100 , V_40 ) ;
}
F_22 ( V_2 , V_34 , V_2 -> V_7 , L_101 ) ;
F_252 () ;
V_40 = F_314 ( V_2 ) ;
F_257 () ;
if ( V_40 && V_40 != - V_149 )
F_154 ( V_2 , V_34 , V_2 -> V_7 ,
L_102 , V_40 ) ;
V_40 = F_315 ( V_163 ) ;
if ( V_40 && V_40 != - V_229 )
F_316 ( V_2 , V_34 , V_2 -> V_7 ,
L_103 ,
V_40 ) ;
return 0 ;
V_175:
F_296 ( V_2 ) ;
V_173:
F_146 ( V_2 ) ;
V_150:
F_292 ( V_2 ) ;
V_146:
F_69 ( V_40 > 0 ) ;
F_22 ( V_2 , V_6 , V_2 -> V_7 , L_104 , V_40 ) ;
F_300 ( V_7 ) ;
return V_40 ;
}
static int F_317 ( struct V_163 * V_171 , int V_398 )
{
int V_40 ;
struct V_1 * V_2 = F_245 ( V_171 ) ;
if ( V_2 -> type -> V_399 ) {
V_40 = V_2 -> type -> V_399 ( V_2 , V_398 ) ;
if ( V_40 )
return V_40 ;
else
return V_398 ;
} else
return - V_294 ;
}
static int F_318 ( struct V_304 * V_171 )
{
struct V_1 * V_2 = F_245 ( F_246 ( V_171 ) ) ;
F_252 () ;
if ( V_2 -> V_3 != V_4 ) {
V_2 -> V_3 = V_327 ;
F_85 ( V_2 ) ;
F_86 ( V_2 ) ;
F_174 ( V_2 ) ;
}
F_257 () ;
return 0 ;
}
static int F_319 ( struct V_304 * V_171 )
{
int V_40 ;
struct V_1 * V_2 = F_245 ( F_246 ( V_171 ) ) ;
F_252 () ;
if ( V_2 -> V_3 != V_4 ) {
V_40 = F_172 ( V_2 ) ;
if ( V_40 )
goto V_59;
F_114 ( & V_2 -> V_133 ) ;
V_2 -> V_144 -> V_148 ( V_2 ) ;
F_115 ( & V_2 -> V_133 ) ;
F_92 ( V_2 ) ;
F_93 ( V_2 -> V_7 ) ;
V_2 -> V_3 = V_321 ;
V_2 -> type -> V_400 ( V_2 ) ;
}
F_257 () ;
F_236 ( V_353 , & V_2 -> V_347 ) ;
return 0 ;
V_59:
F_257 () ;
return V_40 ;
}
static int F_320 ( struct V_304 * V_171 )
{
struct V_163 * V_163 = F_246 ( V_171 ) ;
struct V_1 * V_2 = F_245 ( V_163 ) ;
V_2 -> type -> V_151 ( V_2 ) ;
V_2 -> V_233 = 0 ;
F_321 ( V_163 ) ;
return F_322 ( V_163 , V_401 ) ;
}
static int F_323 ( struct V_304 * V_171 )
{
struct V_163 * V_163 = F_246 ( V_171 ) ;
struct V_1 * V_2 = F_245 ( V_163 ) ;
int V_40 ;
V_40 = F_322 ( V_163 , V_402 ) ;
if ( V_40 )
return V_40 ;
F_324 ( V_163 ) ;
V_40 = F_138 ( V_163 ) ;
if ( V_40 )
return V_40 ;
F_139 ( V_2 -> V_163 ) ;
V_40 = V_2 -> type -> V_339 ( V_2 , V_100 ) ;
if ( V_40 )
return V_40 ;
V_40 = V_2 -> type -> V_145 ( V_2 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_319 ( V_171 ) ;
return V_40 ;
}
static int F_325 ( struct V_304 * V_171 )
{
int V_40 ;
F_318 ( V_171 ) ;
V_40 = F_320 ( V_171 ) ;
if ( V_40 )
F_323 ( V_171 ) ;
return V_40 ;
}
static T_11 F_326 ( struct V_163 * V_403 ,
enum V_404 V_3 )
{
T_11 V_405 = V_406 ;
struct V_1 * V_2 = F_245 ( V_403 ) ;
if ( V_3 == V_407 )
return V_408 ;
F_252 () ;
if ( V_2 -> V_3 != V_4 ) {
V_2 -> V_3 = V_5 ;
V_2 -> V_233 = 0 ;
F_85 ( V_2 ) ;
F_86 ( V_2 ) ;
F_174 ( V_2 ) ;
V_405 = V_409 ;
} else {
V_405 = V_406 ;
}
F_257 () ;
F_145 ( V_403 ) ;
return V_405 ;
}
static T_11 F_327 ( struct V_163 * V_403 )
{
struct V_1 * V_2 = F_245 ( V_403 ) ;
T_11 V_405 = V_406 ;
int V_40 ;
if ( F_138 ( V_403 ) ) {
F_2 ( V_2 , V_410 , V_2 -> V_7 ,
L_105 ) ;
V_405 = V_408 ;
}
V_40 = F_328 ( V_403 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_410 , V_2 -> V_7 ,
L_106 , V_40 ) ;
}
return V_405 ;
}
static void F_329 ( struct V_163 * V_403 )
{
struct V_1 * V_2 = F_245 ( V_403 ) ;
int V_40 ;
F_252 () ;
if ( V_2 -> V_3 == V_4 )
goto V_111;
V_40 = F_227 ( V_2 , V_100 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_410 , V_2 -> V_7 ,
L_107 , V_40 ) ;
} else {
V_2 -> V_3 = V_321 ;
F_22 ( V_2 , V_410 , V_2 -> V_7 ,
L_108 ) ;
}
V_111:
F_257 () ;
}
static int T_12 F_330 ( void )
{
int V_40 ;
F_331 ( V_411 L_109 V_412 L_110 ) ;
V_40 = F_332 ( & V_413 ) ;
if ( V_40 )
goto V_414;
#ifdef F_160
V_40 = F_333 () ;
if ( V_40 )
goto V_415;
#endif
V_353 = F_291 ( L_111 ) ;
if ( ! V_353 ) {
V_40 = - V_110 ;
goto V_416;
}
V_40 = F_334 ( & V_417 ) ;
if ( V_40 < 0 )
goto V_418;
return 0 ;
V_418:
F_293 ( V_353 ) ;
V_416:
#ifdef F_160
F_335 () ;
V_415:
#endif
F_336 ( & V_413 ) ;
V_414:
return V_40 ;
}
static void T_13 F_337 ( void )
{
F_331 ( V_411 L_112 ) ;
F_338 ( & V_417 ) ;
F_293 ( V_353 ) ;
#ifdef F_160
F_335 () ;
#endif
F_336 ( & V_413 ) ;
}

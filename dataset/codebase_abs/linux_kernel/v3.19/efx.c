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
int V_12 ;
if ( F_4 ( ! V_10 -> V_13 ) )
return 0 ;
V_12 = F_5 ( V_10 , V_11 ) ;
if ( V_12 && F_6 ( V_10 ) ) {
struct V_14 * V_15 =
F_7 ( V_10 ) ;
F_8 ( V_10 ) ;
F_9 ( V_15 , true ) ;
}
return V_12 ;
}
static int F_10 ( struct V_16 * V_17 , int V_11 )
{
struct V_9 * V_10 =
F_11 ( V_17 , struct V_9 , V_18 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_12 ;
if ( ! F_12 ( V_10 ) )
return V_11 ;
F_13 ( V_2 , V_19 , V_2 -> V_7 ,
L_2 ,
V_10 -> V_10 , F_14 () ) ;
V_12 = F_3 ( V_10 , V_11 ) ;
if ( V_12 < V_11 ) {
if ( F_6 ( V_10 ) &&
V_2 -> V_20 &&
F_4 ( ++ V_10 -> V_21 == 1000 ) ) {
if ( F_4 ( V_10 -> V_22 <
V_23 ) ) {
if ( V_10 -> V_24 > 1 ) {
V_10 -> V_24 -= 1 ;
V_2 -> type -> V_25 ( V_10 ) ;
}
} else if ( F_4 ( V_10 -> V_22 >
V_26 ) ) {
if ( V_10 -> V_24 <
V_2 -> V_27 ) {
V_10 -> V_24 += 1 ;
V_2 -> type -> V_25 ( V_10 ) ;
}
}
V_10 -> V_21 = 0 ;
V_10 -> V_22 = 0 ;
}
F_15 ( V_10 ) ;
F_16 ( V_17 ) ;
F_17 ( V_10 ) ;
}
F_18 ( V_10 ) ;
return V_12 ;
}
static int F_19 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned long V_28 ;
F_20 ( V_2 , V_29 , V_2 -> V_7 ,
L_3 , V_10 -> V_10 ) ;
V_28 = F_21 ( V_2 -> V_30 + V_2 -> V_31 + 128 ) ;
F_22 ( V_28 > V_32 ) ;
V_10 -> V_33 = F_23 ( V_28 , V_34 ) - 1 ;
return F_24 ( V_10 ) ;
}
static int F_25 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_35 ;
F_26 ( V_10 -> V_36 ) ;
F_20 ( V_2 , V_6 , V_2 -> V_7 ,
L_4 , V_10 -> V_10 ) ;
V_35 = F_27 ( V_10 ) ;
if ( V_35 == 0 ) {
V_2 -> type -> V_25 ( V_10 ) ;
V_10 -> V_37 = 0 ;
V_10 -> V_36 = true ;
}
return V_35 ;
}
void F_28 ( struct V_9 * V_10 )
{
F_20 ( V_10 -> V_2 , V_38 , V_10 -> V_2 -> V_7 ,
L_5 , V_10 -> V_10 ) ;
V_10 -> V_13 = true ;
F_29 () ;
F_30 ( V_10 ) ;
F_31 ( & V_10 -> V_18 ) ;
F_17 ( V_10 ) ;
}
void F_32 ( struct V_9 * V_10 )
{
if ( ! V_10 -> V_13 )
return;
F_33 ( & V_10 -> V_18 ) ;
while ( ! F_34 ( V_10 ) )
F_35 ( 1000 , 20000 ) ;
V_10 -> V_13 = false ;
}
static void F_36 ( struct V_9 * V_10 )
{
if ( ! V_10 -> V_36 )
return;
F_20 ( V_10 -> V_2 , V_6 , V_10 -> V_2 -> V_7 ,
L_6 , V_10 -> V_10 ) ;
F_37 ( V_10 ) ;
V_10 -> V_36 = false ;
}
static void F_38 ( struct V_9 * V_10 )
{
F_20 ( V_10 -> V_2 , V_6 , V_10 -> V_2 -> V_7 ,
L_7 , V_10 -> V_10 ) ;
F_39 ( V_10 ) ;
}
static struct V_9 *
F_40 ( struct V_1 * V_2 , int V_39 , struct V_9 * V_40 )
{
struct V_9 * V_10 ;
struct V_14 * V_15 ;
struct V_41 * V_42 ;
int V_43 ;
V_10 = F_41 ( sizeof( * V_10 ) , V_44 ) ;
if ( ! V_10 )
return NULL ;
V_10 -> V_2 = V_2 ;
V_10 -> V_10 = V_39 ;
V_10 -> type = & V_45 ;
for ( V_43 = 0 ; V_43 < V_46 ; V_43 ++ ) {
V_42 = & V_10 -> V_42 [ V_43 ] ;
V_42 -> V_2 = V_2 ;
V_42 -> V_47 = V_39 * V_46 + V_43 ;
V_42 -> V_10 = V_10 ;
}
V_15 = & V_10 -> V_15 ;
V_15 -> V_2 = V_2 ;
F_42 ( & V_15 -> V_48 , V_49 ,
( unsigned long ) V_15 ) ;
return V_10 ;
}
static struct V_9 *
F_43 ( const struct V_9 * V_40 )
{
struct V_9 * V_10 ;
struct V_14 * V_15 ;
struct V_41 * V_42 ;
int V_43 ;
V_10 = F_44 ( sizeof( * V_10 ) , V_44 ) ;
if ( ! V_10 )
return NULL ;
* V_10 = * V_40 ;
V_10 -> V_50 = NULL ;
memset ( & V_10 -> V_51 , 0 , sizeof( V_10 -> V_51 ) ) ;
for ( V_43 = 0 ; V_43 < V_46 ; V_43 ++ ) {
V_42 = & V_10 -> V_42 [ V_43 ] ;
if ( V_42 -> V_10 )
V_42 -> V_10 = V_10 ;
V_42 -> V_52 = NULL ;
memset ( & V_42 -> V_53 , 0 , sizeof( V_42 -> V_53 ) ) ;
}
V_15 = & V_10 -> V_15 ;
V_15 -> V_52 = NULL ;
memset ( & V_15 -> V_54 , 0 , sizeof( V_15 -> V_54 ) ) ;
F_42 ( & V_15 -> V_48 , V_49 ,
( unsigned long ) V_15 ) ;
return V_10 ;
}
static int F_45 ( struct V_9 * V_10 )
{
struct V_41 * V_42 ;
struct V_14 * V_15 ;
int V_35 ;
F_20 ( V_10 -> V_2 , V_29 , V_10 -> V_2 -> V_7 ,
L_8 , V_10 -> V_10 ) ;
V_35 = V_10 -> type -> V_55 ( V_10 ) ;
if ( V_35 )
goto V_56;
V_35 = F_19 ( V_10 ) ;
if ( V_35 )
goto V_56;
F_46 (tx_queue, channel) {
V_35 = F_47 ( V_42 ) ;
if ( V_35 )
goto V_56;
}
F_48 (rx_queue, channel) {
V_35 = F_49 ( V_15 ) ;
if ( V_35 )
goto V_56;
}
return 0 ;
V_56:
F_50 ( V_10 ) ;
return V_35 ;
}
static void
F_51 ( struct V_9 * V_10 , char * V_57 , T_1 V_58 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
const char * type ;
int V_59 ;
V_59 = V_10 -> V_10 ;
if ( V_2 -> V_60 == 0 ) {
type = L_9 ;
} else if ( V_10 -> V_10 < V_2 -> V_60 ) {
type = L_10 ;
} else {
type = L_11 ;
V_59 -= V_2 -> V_60 ;
}
snprintf ( V_57 , V_58 , L_12 , V_2 -> V_61 , type , V_59 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_53 (channel, efx)
V_10 -> type -> V_62 ( V_10 ,
V_2 -> V_63 [ V_10 -> V_10 ] . V_61 ,
sizeof( V_2 -> V_63 [ 0 ] . V_61 ) ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
int V_35 ;
V_2 -> V_64 = 0 ;
F_55 (channel, efx) {
V_35 = F_45 ( V_10 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_13 ,
V_10 -> V_10 ) ;
goto V_56;
}
}
F_52 ( V_2 ) ;
return 0 ;
V_56:
F_56 ( V_2 ) ;
return V_35 ;
}
static void F_57 ( struct V_1 * V_2 )
{
bool V_65 = V_2 -> V_66 ;
struct V_41 * V_42 ;
struct V_14 * V_15 ;
struct V_9 * V_10 ;
T_1 V_67 ;
V_2 -> V_68 = ( V_2 -> V_69 +
F_58 ( V_2 -> V_7 -> V_70 ) +
V_2 -> type -> V_71 ) ;
V_67 = ( sizeof( struct V_72 ) +
V_2 -> V_73 + V_2 -> V_68 ) ;
if ( V_67 <= V_74 ) {
V_2 -> V_66 = V_2 -> type -> V_75 ;
V_2 -> V_76 = 0 ;
} else if ( V_2 -> type -> V_77 ) {
F_59 ( V_78 % V_79 ) ;
F_59 ( sizeof( struct V_72 ) +
2 * F_60 ( V_80 + V_78 ,
V_81 ) >
V_74 ) ;
V_2 -> V_66 = true ;
V_2 -> V_68 = V_78 ;
V_2 -> V_76 = 0 ;
} else {
V_2 -> V_66 = false ;
V_2 -> V_76 = F_61 ( V_67 ) ;
}
F_62 ( V_2 ) ;
if ( V_2 -> V_76 )
F_20 ( V_2 , V_6 , V_2 -> V_7 ,
L_14 ,
V_2 -> V_68 , V_2 -> V_76 ,
V_2 -> V_82 ) ;
else
F_20 ( V_2 , V_6 , V_2 -> V_7 ,
L_15 ,
V_2 -> V_68 , V_2 -> V_83 ,
V_2 -> V_84 , V_2 -> V_82 ) ;
if ( V_2 -> V_66 != V_65 )
V_2 -> type -> V_85 ( V_2 ) ;
V_2 -> V_86 = V_2 -> V_31 - F_63 ( V_2 ) ;
V_2 -> V_87 = V_2 -> V_86 / 2 ;
F_53 (channel, efx) {
F_46 (tx_queue, channel) {
F_64 ( V_42 ) ;
F_65 ( & V_2 -> V_88 ) ;
}
F_48 (rx_queue, channel) {
F_66 ( V_15 ) ;
F_65 ( & V_2 -> V_88 ) ;
F_32 ( V_10 ) ;
F_9 ( V_15 , false ) ;
F_28 ( V_10 ) ;
}
F_67 ( V_10 -> V_89 ) ;
}
F_68 ( V_2 ) ;
if ( F_69 ( V_2 -> V_7 ) )
F_70 ( V_2 -> V_7 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_41 * V_42 ;
struct V_14 * V_15 ;
int V_35 ;
F_72 ( V_2 ) ;
F_73 ( V_2 -> V_90 ) ;
F_74 ( V_2 ) ;
F_53 (channel, efx) {
F_48 (rx_queue, channel)
V_15 -> V_91 = false ;
}
F_53 (channel, efx) {
if ( F_6 ( V_10 ) ) {
F_32 ( V_10 ) ;
F_28 ( V_10 ) ;
}
}
V_35 = V_2 -> type -> V_92 ( V_2 ) ;
if ( V_35 && F_75 ( V_2 ) ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_16 ) ;
F_76 ( V_2 , V_93 ) ;
} else if ( V_35 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_17 ) ;
} else {
F_20 ( V_2 , V_6 , V_2 -> V_7 ,
L_18 ) ;
}
F_53 (channel, efx) {
F_48 (rx_queue, channel)
F_77 ( V_15 ) ;
F_78 (tx_queue, channel)
F_79 ( V_42 ) ;
}
}
static void F_50 ( struct V_9 * V_10 )
{
struct V_41 * V_42 ;
struct V_14 * V_15 ;
F_20 ( V_10 -> V_2 , V_6 , V_10 -> V_2 -> V_7 ,
L_19 , V_10 -> V_10 ) ;
F_48 (rx_queue, channel)
F_80 ( V_15 ) ;
F_78 (tx_queue, channel)
F_81 ( V_42 ) ;
F_38 ( V_10 ) ;
V_10 -> type -> V_94 ( V_10 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_53 (channel, efx)
F_50 ( V_10 ) ;
}
int
F_82 ( struct V_1 * V_2 , T_2 V_30 , T_2 V_31 )
{
struct V_9 * V_95 [ V_96 ] , * V_10 ;
T_2 V_97 , V_98 ;
unsigned V_39 , V_64 = 0 ;
int V_35 , V_99 ;
V_35 = F_1 ( V_2 ) ;
if ( V_35 )
return V_35 ;
F_53 (channel, efx) {
struct V_14 * V_15 ;
struct V_41 * V_42 ;
if ( V_10 -> type -> V_100 )
continue;
V_64 = F_23 ( V_64 ,
V_10 -> V_51 . V_101 +
V_10 -> V_51 . V_28 ) ;
F_48 (rx_queue, channel)
V_64 = F_23 ( V_64 ,
V_15 -> V_54 . V_101 +
V_15 -> V_54 . V_28 ) ;
F_46 (tx_queue, channel)
V_64 = F_23 ( V_64 ,
V_42 -> V_53 . V_101 +
V_42 -> V_53 . V_28 ) ;
}
F_83 ( V_2 ) ;
F_84 ( V_2 ) ;
F_85 ( V_2 ) ;
memset ( V_95 , 0 , sizeof( V_95 ) ) ;
for ( V_39 = 0 ; V_39 < V_2 -> V_102 ; V_39 ++ ) {
V_10 = V_2 -> V_10 [ V_39 ] ;
if ( V_10 -> type -> V_100 )
V_10 = V_10 -> type -> V_100 ( V_10 ) ;
if ( ! V_10 ) {
V_35 = - V_103 ;
goto V_104;
}
V_95 [ V_39 ] = V_10 ;
}
V_97 = V_2 -> V_30 ;
V_98 = V_2 -> V_31 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_31 = V_31 ;
for ( V_39 = 0 ; V_39 < V_2 -> V_102 ; V_39 ++ ) {
V_10 = V_2 -> V_10 [ V_39 ] ;
V_2 -> V_10 [ V_39 ] = V_95 [ V_39 ] ;
V_95 [ V_39 ] = V_10 ;
}
V_2 -> V_64 = V_64 ;
for ( V_39 = 0 ; V_39 < V_2 -> V_102 ; V_39 ++ ) {
V_10 = V_2 -> V_10 [ V_39 ] ;
if ( ! V_10 -> type -> V_100 )
continue;
V_35 = F_45 ( V_10 ) ;
if ( V_35 )
goto V_105;
F_86 ( V_2 -> V_10 [ V_39 ] ) ;
}
V_104:
for ( V_39 = 0 ; V_39 < V_2 -> V_102 ; V_39 ++ ) {
V_10 = V_95 [ V_39 ] ;
if ( V_10 && V_10 -> type -> V_100 ) {
F_87 ( V_10 ) ;
F_50 ( V_10 ) ;
F_88 ( V_10 ) ;
}
}
V_99 = F_89 ( V_2 ) ;
if ( V_99 ) {
V_35 = V_35 ? V_35 : V_99 ;
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_20 ) ;
F_76 ( V_2 , V_106 ) ;
} else {
F_90 ( V_2 ) ;
F_91 ( V_2 -> V_7 ) ;
}
return V_35 ;
V_105:
V_2 -> V_30 = V_97 ;
V_2 -> V_31 = V_98 ;
for ( V_39 = 0 ; V_39 < V_2 -> V_102 ; V_39 ++ ) {
V_10 = V_2 -> V_10 [ V_39 ] ;
V_2 -> V_10 [ V_39 ] = V_95 [ V_39 ] ;
V_95 [ V_39 ] = V_10 ;
}
goto V_104;
}
void F_92 ( struct V_14 * V_15 )
{
F_93 ( & V_15 -> V_48 , V_107 + F_94 ( 100 ) ) ;
}
int F_95 ( struct V_9 * V_10 )
{
return 0 ;
}
void F_96 ( struct V_9 * V_10 )
{
}
void F_97 ( struct V_1 * V_2 )
{
struct V_108 * V_109 = & V_2 -> V_109 ;
if ( ! F_98 ( V_2 -> V_7 ) )
return;
if ( V_109 -> V_110 != F_99 ( V_2 -> V_7 ) ) {
V_2 -> V_111 ++ ;
if ( V_109 -> V_110 )
F_100 ( V_2 -> V_7 ) ;
else
F_101 ( V_2 -> V_7 ) ;
}
if ( V_109 -> V_110 )
F_102 ( V_2 , V_112 , V_2 -> V_7 ,
L_21 ,
V_109 -> V_113 , V_109 -> V_114 ? L_22 : L_23 ,
V_2 -> V_7 -> V_70 ) ;
else
F_102 ( V_2 , V_112 , V_2 -> V_7 , L_24 ) ;
}
void F_103 ( struct V_1 * V_2 , T_2 V_115 )
{
V_2 -> V_116 = V_115 ;
if ( V_115 ) {
if ( V_115 & V_117 )
V_2 -> V_118 |= ( V_119 | V_120 ) ;
else
V_2 -> V_118 &= ~ ( V_119 | V_120 ) ;
if ( V_115 & V_121 )
V_2 -> V_118 ^= V_119 ;
}
}
void F_104 ( struct V_1 * V_2 , T_3 V_118 )
{
V_2 -> V_118 = V_118 ;
if ( V_2 -> V_116 ) {
if ( V_118 & V_120 )
V_2 -> V_116 |= ( V_117 |
V_121 ) ;
else
V_2 -> V_116 &= ~ ( V_117 |
V_121 ) ;
if ( V_118 & V_119 )
V_2 -> V_116 ^= V_121 ;
}
}
int F_105 ( struct V_1 * V_2 )
{
enum V_122 V_123 ;
int V_35 ;
F_67 ( ! F_106 ( & V_2 -> V_124 ) ) ;
V_123 = V_2 -> V_123 ;
if ( F_107 ( V_2 ) )
V_2 -> V_123 |= V_125 ;
else
V_2 -> V_123 &= ~ V_125 ;
V_35 = V_2 -> type -> V_126 ( V_2 ) ;
if ( V_35 )
V_2 -> V_123 = V_123 ;
return V_35 ;
}
int F_108 ( struct V_1 * V_2 )
{
int V_35 ;
F_72 ( V_2 ) ;
F_109 ( & V_2 -> V_124 ) ;
V_35 = F_105 ( V_2 ) ;
F_110 ( & V_2 -> V_124 ) ;
return V_35 ;
}
static void F_111 ( struct V_127 * V_128 )
{
struct V_1 * V_2 = F_11 ( V_128 , struct V_1 , V_129 ) ;
F_109 ( & V_2 -> V_124 ) ;
if ( V_2 -> V_90 )
V_2 -> type -> V_130 ( V_2 ) ;
F_110 ( & V_2 -> V_124 ) ;
}
static int F_112 ( struct V_1 * V_2 )
{
int V_35 ;
F_20 ( V_2 , V_29 , V_2 -> V_7 , L_25 ) ;
if ( V_131 )
V_2 -> V_123 = V_132 ;
V_35 = V_2 -> type -> V_133 ( V_2 ) ;
if ( V_35 )
return V_35 ;
F_113 ( V_2 -> V_7 -> V_134 , V_2 -> V_7 -> V_135 ) ;
return 0 ;
}
static int F_114 ( struct V_1 * V_2 )
{
int V_35 ;
F_20 ( V_2 , V_6 , V_2 -> V_7 , L_26 ) ;
F_109 ( & V_2 -> V_124 ) ;
V_35 = V_2 -> V_136 -> V_137 ( V_2 ) ;
if ( V_35 )
goto V_138;
V_2 -> V_139 = true ;
V_2 -> type -> V_130 ( V_2 ) ;
V_35 = V_2 -> V_136 -> V_140 ( V_2 ) ;
if ( V_35 )
goto V_141;
F_110 ( & V_2 -> V_124 ) ;
return 0 ;
V_141:
V_2 -> V_136 -> V_142 ( V_2 ) ;
V_138:
F_110 ( & V_2 -> V_124 ) ;
return V_35 ;
}
static void F_115 ( struct V_1 * V_2 )
{
F_20 ( V_2 , V_38 , V_2 -> V_7 , L_27 ) ;
F_73 ( V_2 -> V_90 ) ;
F_109 ( & V_2 -> V_124 ) ;
V_2 -> V_90 = true ;
V_2 -> type -> V_130 ( V_2 ) ;
F_110 ( & V_2 -> V_124 ) ;
}
static void F_116 ( struct V_1 * V_2 )
{
F_20 ( V_2 , V_143 , V_2 -> V_7 , L_28 ) ;
F_72 ( V_2 ) ;
F_109 ( & V_2 -> V_124 ) ;
V_2 -> V_90 = false ;
F_110 ( & V_2 -> V_124 ) ;
F_117 ( V_2 -> V_7 ) ;
F_118 ( V_2 -> V_7 ) ;
F_119 ( & V_2 -> V_144 ) ;
F_120 ( V_2 ) ;
F_121 ( & V_2 -> V_129 ) ;
}
static void F_122 ( struct V_1 * V_2 )
{
F_20 ( V_2 , V_6 , V_2 -> V_7 , L_29 ) ;
if ( ! V_2 -> V_139 )
return;
V_2 -> V_136 -> V_142 ( V_2 ) ;
V_2 -> V_139 = false ;
V_2 -> V_109 . V_110 = false ;
F_97 ( V_2 ) ;
}
static void F_123 ( struct V_1 * V_2 )
{
F_20 ( V_2 , V_6 , V_2 -> V_7 , L_30 ) ;
V_2 -> type -> V_145 ( V_2 ) ;
}
static bool F_124 ( struct V_1 * V_146 , struct V_1 * V_147 )
{
return V_146 -> type == V_147 -> type &&
V_146 -> V_148 && V_147 -> V_148 &&
! strcmp ( V_146 -> V_148 , V_147 -> V_148 ) ;
}
static void F_125 ( struct V_1 * V_2 )
{
struct V_1 * V_149 , * V_150 ;
if ( V_2 -> V_151 == V_2 ) {
F_20 ( V_2 , V_29 , V_2 -> V_7 , L_31 ) ;
F_126 ( & V_2 -> V_152 , & V_153 ) ;
F_127 (other, next, &efx_unassociated_list,
node) {
if ( F_124 ( V_2 , V_149 ) ) {
F_128 ( & V_149 -> V_152 ) ;
F_20 ( V_149 , V_29 , V_149 -> V_7 ,
L_32 ,
F_129 ( V_2 -> V_154 ) ,
V_2 -> V_7 -> V_61 ) ;
F_126 ( & V_149 -> V_152 ,
& V_2 -> V_155 ) ;
V_149 -> V_151 = V_2 ;
}
}
} else {
F_130 (other, &efx_primary_list, node) {
if ( F_124 ( V_2 , V_149 ) ) {
F_20 ( V_2 , V_29 , V_2 -> V_7 ,
L_33 ,
F_129 ( V_149 -> V_154 ) ,
V_149 -> V_7 -> V_61 ) ;
F_126 ( & V_2 -> V_152 ,
& V_149 -> V_155 ) ;
V_2 -> V_151 = V_149 ;
return;
}
}
F_20 ( V_2 , V_29 , V_2 -> V_7 ,
L_34 ) ;
F_126 ( & V_2 -> V_152 , & V_156 ) ;
}
}
static void F_131 ( struct V_1 * V_2 )
{
struct V_1 * V_149 , * V_150 ;
F_128 ( & V_2 -> V_152 ) ;
V_2 -> V_151 = NULL ;
F_127 (other, next, &efx->secondary_list, node) {
F_128 ( & V_149 -> V_152 ) ;
F_20 ( V_149 , V_29 , V_149 -> V_7 ,
L_35 ) ;
F_126 ( & V_149 -> V_152 , & V_156 ) ;
V_149 -> V_151 = NULL ;
}
}
static int F_132 ( struct V_1 * V_2 )
{
struct V_154 * V_154 = V_2 -> V_154 ;
T_4 V_157 = V_2 -> type -> V_158 ;
unsigned int V_159 = V_2 -> type -> V_159 ( V_2 ) ;
int V_35 ;
F_20 ( V_2 , V_29 , V_2 -> V_7 , L_36 ) ;
V_35 = F_133 ( V_154 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_37 ) ;
goto V_138;
}
F_134 ( V_154 ) ;
while ( V_157 > 0x7fffffffUL ) {
if ( F_135 ( & V_154 -> V_160 , V_157 ) ) {
V_35 = F_136 ( & V_154 -> V_160 , V_157 ) ;
if ( V_35 == 0 )
break;
}
V_157 >>= 1 ;
}
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_38 ) ;
goto V_141;
}
F_20 ( V_2 , V_29 , V_2 -> V_7 ,
L_39 , ( unsigned long long ) V_157 ) ;
V_2 -> V_161 = F_137 ( V_2 -> V_154 , V_162 ) ;
V_35 = F_138 ( V_154 , V_162 , L_40 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_41 ) ;
V_35 = - V_8 ;
goto V_163;
}
V_2 -> V_164 = F_139 ( V_2 -> V_161 , V_159 ) ;
if ( ! V_2 -> V_164 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_42 ,
( unsigned long long ) V_2 -> V_161 , V_159 ) ;
V_35 = - V_103 ;
goto V_165;
}
F_20 ( V_2 , V_29 , V_2 -> V_7 ,
L_43 ,
( unsigned long long ) V_2 -> V_161 , V_159 ,
V_2 -> V_164 ) ;
return 0 ;
V_165:
F_140 ( V_2 -> V_154 , V_162 ) ;
V_163:
V_2 -> V_161 = 0 ;
V_141:
F_141 ( V_2 -> V_154 ) ;
V_138:
return V_35 ;
}
static void F_142 ( struct V_1 * V_2 )
{
F_20 ( V_2 , V_6 , V_2 -> V_7 , L_44 ) ;
if ( V_2 -> V_164 ) {
F_143 ( V_2 -> V_164 ) ;
V_2 -> V_164 = NULL ;
}
if ( V_2 -> V_161 ) {
F_140 ( V_2 -> V_154 , V_162 ) ;
V_2 -> V_161 = 0 ;
}
F_141 ( V_2 -> V_154 ) ;
}
static unsigned int F_144 ( struct V_1 * V_2 )
{
T_5 V_166 ;
unsigned int V_167 ;
int V_168 ;
if ( V_169 ) {
V_167 = V_169 ;
} else {
if ( F_4 ( ! F_145 ( & V_166 , V_44 ) ) ) {
F_146 ( V_2 , V_29 , V_2 -> V_7 ,
L_45 ) ;
return 1 ;
}
V_167 = 0 ;
F_147 (cpu) {
if ( ! F_148 ( V_168 , V_166 ) ) {
++ V_167 ;
F_149 ( V_166 , V_166 ,
F_150 ( V_168 ) ) ;
}
}
F_151 ( V_166 ) ;
}
if ( V_2 -> type -> V_170 ( V_2 ) && F_152 ( V_2 ) > 1 &&
V_167 > F_152 ( V_2 ) ) {
F_146 ( V_2 , V_29 , V_2 -> V_7 ,
L_46
L_47
L_48 ,
V_167 , F_152 ( V_2 ) ) ;
V_167 = F_152 ( V_2 ) ;
}
return V_167 ;
}
static int F_153 ( struct V_1 * V_2 )
{
unsigned int V_171 = 0 ;
unsigned int V_39 , V_43 ;
int V_35 ;
for ( V_39 = 0 ; V_39 < V_172 ; V_39 ++ )
if ( V_2 -> V_173 [ V_39 ] )
++ V_171 ;
if ( V_2 -> V_174 == V_175 ) {
struct V_176 V_177 [ V_96 ] ;
unsigned int V_102 ;
V_102 = F_144 ( V_2 ) ;
if ( V_178 )
V_102 *= 2 ;
V_102 += V_171 ;
V_102 = F_154 ( V_102 , V_2 -> V_179 ) ;
for ( V_39 = 0 ; V_39 < V_102 ; V_39 ++ )
V_177 [ V_39 ] . V_180 = V_39 ;
V_35 = F_155 ( V_2 -> V_154 ,
V_177 , 1 , V_102 ) ;
if ( V_35 < 0 ) {
V_2 -> V_174 = V_181 ;
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_49 ) ;
} else if ( V_35 < V_102 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_50
L_51 , V_35 , V_102 ) ;
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_52 ) ;
V_102 = V_35 ;
}
if ( V_35 > 0 ) {
V_2 -> V_102 = V_102 ;
if ( V_102 > V_171 )
V_102 -= V_171 ;
if ( V_178 ) {
V_2 -> V_182 = F_23 ( V_102 / 2 , 1U ) ;
V_2 -> V_183 = F_23 ( V_102 -
V_2 -> V_182 ,
1U ) ;
} else {
V_2 -> V_182 = V_102 ;
V_2 -> V_183 = V_102 ;
}
for ( V_39 = 0 ; V_39 < V_2 -> V_102 ; V_39 ++ )
F_156 ( V_2 , V_39 ) -> V_184 =
V_177 [ V_39 ] . V_185 ;
}
}
if ( V_2 -> V_174 == V_181 ) {
V_2 -> V_102 = 1 ;
V_2 -> V_183 = 1 ;
V_2 -> V_182 = 1 ;
V_35 = F_157 ( V_2 -> V_154 ) ;
if ( V_35 == 0 ) {
F_156 ( V_2 , 0 ) -> V_184 = V_2 -> V_154 -> V_184 ;
} else {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_53 ) ;
V_2 -> V_174 = V_186 ;
}
}
if ( V_2 -> V_174 == V_186 ) {
V_2 -> V_102 = 1 + ( V_178 ? 1 : 0 ) ;
V_2 -> V_183 = 1 ;
V_2 -> V_182 = 1 ;
V_2 -> V_187 = V_2 -> V_154 -> V_184 ;
}
V_43 = V_2 -> V_102 ;
for ( V_39 = 0 ; V_39 < V_172 ; V_39 ++ ) {
if ( ! V_2 -> V_173 [ V_39 ] )
continue;
if ( V_2 -> V_174 != V_175 ||
V_2 -> V_102 <= V_171 ) {
V_2 -> V_173 [ V_39 ] -> F_158 ( V_2 ) ;
} else {
-- V_43 ;
F_156 ( V_2 , V_43 ) -> type =
V_2 -> V_173 [ V_39 ] ;
}
}
V_2 -> V_188 = ( ( V_2 -> V_183 > 1 ||
! V_2 -> type -> V_170 ( V_2 ) ) ?
V_2 -> V_183 : F_152 ( V_2 ) ) ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 )
{
struct V_9 * V_10 , * V_189 ;
int V_35 ;
F_73 ( V_2 -> V_3 == V_4 ) ;
V_2 -> V_190 = true ;
F_29 () ;
F_53 (channel, efx) {
if ( ! V_10 -> type -> V_191 ) {
V_35 = F_25 ( V_10 ) ;
if ( V_35 )
goto V_56;
}
F_28 ( V_10 ) ;
}
F_159 ( V_2 ) ;
return 0 ;
V_56:
V_189 = V_10 ;
F_53 (channel, efx) {
if ( V_10 == V_189 )
break;
F_32 ( V_10 ) ;
if ( ! V_10 -> type -> V_191 )
F_36 ( V_10 ) ;
}
return V_35 ;
}
static void F_85 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
if ( V_2 -> V_3 == V_4 )
return;
F_160 ( V_2 ) ;
V_2 -> V_190 = false ;
F_29 () ;
if ( V_2 -> V_187 )
F_161 ( V_2 -> V_187 ) ;
F_53 (channel, efx) {
if ( V_10 -> V_184 )
F_161 ( V_10 -> V_184 ) ;
F_32 ( V_10 ) ;
if ( ! V_10 -> type -> V_191 )
F_36 ( V_10 ) ;
}
F_162 ( V_2 ) ;
}
static int F_163 ( struct V_1 * V_2 )
{
struct V_9 * V_10 , * V_189 ;
int V_35 ;
F_73 ( V_2 -> V_3 == V_4 ) ;
if ( V_2 -> V_192 ) {
F_164 ( V_2 -> V_187 ) ;
V_2 -> V_192 = false ;
}
V_2 -> type -> V_193 ( V_2 ) ;
F_53 (channel, efx) {
if ( V_10 -> type -> V_191 ) {
V_35 = F_25 ( V_10 ) ;
if ( V_35 )
goto V_56;
}
}
V_35 = F_89 ( V_2 ) ;
if ( V_35 )
goto V_56;
return 0 ;
V_56:
V_189 = V_10 ;
F_53 (channel, efx) {
if ( V_10 == V_189 )
break;
if ( V_10 -> type -> V_191 )
F_36 ( V_10 ) ;
}
V_2 -> type -> V_194 ( V_2 ) ;
return V_35 ;
}
static void F_165 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_85 ( V_2 ) ;
F_53 (channel, efx) {
if ( V_10 -> type -> V_191 )
F_36 ( V_10 ) ;
}
V_2 -> type -> V_194 ( V_2 ) ;
}
static void F_166 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_53 (channel, efx)
V_10 -> V_184 = 0 ;
F_167 ( V_2 -> V_154 ) ;
F_168 ( V_2 -> V_154 ) ;
V_2 -> V_187 = 0 ;
}
static void F_169 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_41 * V_42 ;
V_2 -> V_60 =
V_178 ? V_2 -> V_102 - V_2 -> V_182 : 0 ;
F_53 (channel, efx) {
if ( V_10 -> V_10 < V_2 -> V_183 )
V_10 -> V_15 . V_195 = V_10 -> V_10 ;
else
V_10 -> V_15 . V_195 = - 1 ;
F_46 (tx_queue, channel)
V_42 -> V_47 -= ( V_2 -> V_60 *
V_46 ) ;
}
}
static int F_170 ( struct V_1 * V_2 )
{
T_1 V_39 ;
int V_35 ;
F_20 ( V_2 , V_29 , V_2 -> V_7 , L_54 ) ;
V_35 = V_2 -> type -> V_29 ( V_2 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_153 ( V_2 ) ;
if ( V_35 )
goto V_138;
F_169 ( V_2 ) ;
V_35 = V_2 -> type -> V_196 ( V_2 ) ;
if ( V_35 )
goto V_141;
if ( V_2 -> V_102 > 1 )
F_171 ( & V_2 -> V_197 , sizeof( V_2 -> V_197 ) ) ;
for ( V_39 = 0 ; V_39 < F_172 ( V_2 -> V_198 ) ; V_39 ++ )
V_2 -> V_198 [ V_39 ] =
F_173 ( V_39 , V_2 -> V_188 ) ;
F_174 ( V_2 -> V_7 , V_2 -> V_182 ) ;
F_175 ( V_2 -> V_7 , V_2 -> V_183 ) ;
F_176 ( V_2 , V_199 , V_200 , true ,
true ) ;
return 0 ;
V_141:
F_166 ( V_2 ) ;
V_138:
V_2 -> type -> remove ( V_2 ) ;
return V_35 ;
}
static void F_177 ( struct V_1 * V_2 )
{
F_20 ( V_2 , V_6 , V_2 -> V_7 , L_55 ) ;
F_166 ( V_2 ) ;
V_2 -> type -> remove ( V_2 ) ;
}
static int F_178 ( struct V_1 * V_2 )
{
int V_35 ;
F_179 ( & V_2 -> V_201 ) ;
V_35 = V_2 -> type -> V_202 ( V_2 ) ;
if ( V_35 )
return V_35 ;
#ifdef F_180
if ( V_2 -> type -> V_203 & V_204 ) {
V_2 -> V_205 = F_181 ( V_2 -> type -> V_206 ,
sizeof( * V_2 -> V_205 ) ,
V_44 ) ;
if ( ! V_2 -> V_205 ) {
V_2 -> type -> V_207 ( V_2 ) ;
return - V_103 ;
}
}
#endif
return 0 ;
}
static void F_182 ( struct V_1 * V_2 )
{
#ifdef F_180
F_88 ( V_2 -> V_205 ) ;
#endif
V_2 -> type -> V_207 ( V_2 ) ;
}
static void F_183 ( struct V_1 * V_2 )
{
V_2 -> type -> V_208 ( V_2 ) ;
}
static int F_184 ( struct V_1 * V_2 )
{
int V_35 ;
V_35 = F_170 ( V_2 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 , L_56 ) ;
goto V_138;
}
V_35 = F_112 ( V_2 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 , L_57 ) ;
goto V_141;
}
F_59 ( V_209 < V_210 ) ;
if ( F_67 ( V_209 < F_185 ( V_2 ) ) ) {
V_35 = - V_211 ;
goto V_163;
}
V_2 -> V_30 = V_2 -> V_31 = V_209 ;
V_35 = F_178 ( V_2 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_58 ) ;
goto V_163;
}
V_35 = F_54 ( V_2 ) ;
if ( V_35 )
goto V_165;
return 0 ;
V_165:
F_182 ( V_2 ) ;
V_163:
F_123 ( V_2 ) ;
V_141:
F_177 ( V_2 ) ;
V_138:
return V_35 ;
}
static void F_90 ( struct V_1 * V_2 )
{
F_72 ( V_2 ) ;
F_73 ( V_2 -> V_3 == V_4 ) ;
if ( V_2 -> V_90 || ! F_98 ( V_2 -> V_7 ) ||
V_2 -> V_212 )
return;
F_115 ( V_2 ) ;
F_57 ( V_2 ) ;
if ( V_2 -> type -> V_213 != NULL )
F_186 ( V_2 -> V_214 , & V_2 -> V_144 ,
V_215 ) ;
if ( F_187 ( V_2 ) >= V_216 ) {
F_109 ( & V_2 -> V_124 ) ;
if ( V_2 -> V_136 -> V_217 ( V_2 ) )
F_97 ( V_2 ) ;
F_110 ( & V_2 -> V_124 ) ;
}
V_2 -> type -> V_218 ( V_2 ) ;
V_2 -> type -> V_219 ( V_2 ) ;
F_188 ( & V_2 -> V_220 ) ;
V_2 -> type -> V_221 ( V_2 , NULL , NULL ) ;
F_189 ( & V_2 -> V_220 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
F_72 ( V_2 ) ;
if ( ! V_2 -> V_90 )
return;
V_2 -> type -> V_219 ( V_2 ) ;
F_188 ( & V_2 -> V_220 ) ;
V_2 -> type -> V_221 ( V_2 , NULL , NULL ) ;
F_189 ( & V_2 -> V_220 ) ;
V_2 -> type -> V_222 ( V_2 ) ;
F_116 ( V_2 ) ;
F_67 ( F_98 ( V_2 -> V_7 ) &&
F_69 ( V_2 -> V_7 ) ) ;
F_190 ( V_2 -> V_7 ) ;
F_71 ( V_2 ) ;
}
static void F_191 ( struct V_1 * V_2 )
{
F_56 ( V_2 ) ;
F_182 ( V_2 ) ;
F_123 ( V_2 ) ;
F_177 ( V_2 ) ;
}
static unsigned int F_192 ( unsigned int V_223 , unsigned int V_224 )
{
if ( V_223 == 0 )
return 0 ;
if ( V_223 * 1000 < V_224 )
return 1 ;
return V_223 * 1000 / V_224 ;
}
int F_176 ( struct V_1 * V_2 , unsigned int V_225 ,
unsigned int V_226 , bool V_227 ,
bool V_228 )
{
struct V_9 * V_10 ;
unsigned int V_229 = F_193 ( V_2 -> type -> V_230 *
V_2 -> V_231 ,
1000 ) ;
unsigned int V_232 ;
unsigned int V_233 ;
F_72 ( V_2 ) ;
if ( V_225 > V_229 || V_226 > V_229 )
return - V_211 ;
V_232 = F_192 ( V_225 , V_2 -> V_231 ) ;
V_233 = F_192 ( V_226 , V_2 -> V_231 ) ;
if ( V_232 != V_233 && V_2 -> V_60 == 0 &&
! V_228 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_59
L_60 ) ;
return - V_211 ;
}
V_2 -> V_20 = V_227 ;
V_2 -> V_27 = V_233 ;
F_53 (channel, efx) {
if ( F_6 ( V_10 ) )
V_10 -> V_24 = V_233 ;
else if ( F_194 ( V_10 ) )
V_10 -> V_24 = V_232 ;
}
return 0 ;
}
void F_195 ( struct V_1 * V_2 , unsigned int * V_225 ,
unsigned int * V_226 , bool * V_227 )
{
* V_227 = V_2 -> V_20 ;
* V_226 = F_193 ( V_2 -> V_27 *
V_2 -> V_231 ,
1000 ) ;
if ( V_2 -> V_60 == 0 )
* V_225 = * V_226 ;
else
* V_225 = F_193 (
V_2 -> V_10 [ V_2 -> V_60 ] -> V_24 *
V_2 -> V_231 ,
1000 ) ;
}
static void F_196 ( struct V_127 * V_128 )
{
struct V_1 * V_2 = F_11 ( V_128 , struct V_1 ,
V_144 . V_234 ) ;
F_13 ( V_2 , V_235 , V_2 -> V_7 ,
L_61 ,
F_14 () ) ;
F_73 ( V_2 -> type -> V_213 == NULL ) ;
if ( F_197 ( & V_2 -> V_124 ) ) {
if ( V_2 -> V_90 )
V_2 -> type -> V_213 ( V_2 ) ;
F_110 ( & V_2 -> V_124 ) ;
}
F_186 ( V_2 -> V_214 , & V_2 -> V_144 ,
V_215 ) ;
}
static int F_198 ( struct V_236 * V_7 , struct V_237 * V_238 , int V_239 )
{
struct V_1 * V_2 = F_199 ( V_7 ) ;
struct V_240 * V_128 = F_200 ( V_238 ) ;
if ( V_239 == V_241 )
return F_201 ( V_2 , V_238 ) ;
if ( V_239 == V_242 )
return F_202 ( V_2 , V_238 ) ;
if ( ( V_239 == V_243 || V_239 == V_244 ) &&
( V_128 -> V_245 & 0xfc00 ) == 0x0400 )
V_128 -> V_245 ^= V_246 | 0x0400 ;
return F_203 ( & V_2 -> V_247 , V_128 , V_239 ) ;
}
static void F_86 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
V_10 -> V_50 = V_2 -> V_7 ;
F_204 ( V_10 -> V_50 , & V_10 -> V_18 ,
F_10 , V_248 ) ;
F_205 ( & V_10 -> V_18 ) ;
F_206 ( V_10 ) ;
}
static void F_207 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_53 (channel, efx)
F_86 ( V_10 ) ;
}
static void F_87 ( struct V_9 * V_10 )
{
if ( V_10 -> V_50 ) {
F_208 ( & V_10 -> V_18 ) ;
F_209 ( & V_10 -> V_18 ) ;
}
V_10 -> V_50 = NULL ;
}
static void F_210 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_53 (channel, efx)
F_87 ( V_10 ) ;
}
static void F_211 ( struct V_236 * V_7 )
{
struct V_1 * V_2 = F_199 ( V_7 ) ;
struct V_9 * V_10 ;
F_53 (channel, efx)
F_212 ( V_10 ) ;
}
static int F_213 ( struct V_16 * V_17 )
{
struct V_9 * V_10 =
F_11 ( V_17 , struct V_9 , V_18 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_11 = 4 ;
int V_249 , V_250 ;
if ( ! F_98 ( V_2 -> V_7 ) )
return V_251 ;
if ( ! F_214 ( V_10 ) )
return V_252 ;
V_249 = V_10 -> V_15 . V_250 ;
F_3 ( V_10 , V_11 ) ;
V_250 = V_10 -> V_15 . V_250 - V_249 ;
F_215 ( V_10 ) ;
return V_250 ;
}
static int F_216 ( struct V_236 * V_7 )
{
struct V_1 * V_2 = F_199 ( V_7 ) ;
int V_35 ;
F_20 ( V_2 , V_38 , V_2 -> V_7 , L_62 ,
F_14 () ) ;
V_35 = F_1 ( V_2 ) ;
if ( V_35 )
return V_35 ;
if ( V_2 -> V_123 & V_132 )
return - V_253 ;
if ( F_217 ( V_2 ) && F_218 ( V_2 , V_93 ) )
return - V_8 ;
F_97 ( V_2 ) ;
F_90 ( V_2 ) ;
F_219 ( V_2 ) ;
return 0 ;
}
static int F_220 ( struct V_236 * V_7 )
{
struct V_1 * V_2 = F_199 ( V_7 ) ;
F_20 ( V_2 , V_143 , V_2 -> V_7 , L_63 ,
F_14 () ) ;
F_84 ( V_2 ) ;
return 0 ;
}
static struct V_254 * F_221 ( struct V_236 * V_7 ,
struct V_254 * V_255 )
{
struct V_1 * V_2 = F_199 ( V_7 ) ;
F_188 ( & V_2 -> V_220 ) ;
V_2 -> type -> V_221 ( V_2 , NULL , V_255 ) ;
F_189 ( & V_2 -> V_220 ) ;
return V_255 ;
}
static void F_222 ( struct V_236 * V_7 )
{
struct V_1 * V_2 = F_199 ( V_7 ) ;
F_2 ( V_2 , V_256 , V_2 -> V_7 ,
L_64 ,
V_2 -> V_90 ) ;
F_76 ( V_2 , V_257 ) ;
}
static int F_223 ( struct V_236 * V_7 , int V_258 )
{
struct V_1 * V_2 = F_199 ( V_7 ) ;
int V_35 ;
V_35 = F_1 ( V_2 ) ;
if ( V_35 )
return V_35 ;
if ( V_258 > V_259 )
return - V_211 ;
F_20 ( V_2 , V_6 , V_2 -> V_7 , L_65 , V_258 ) ;
F_83 ( V_2 ) ;
F_84 ( V_2 ) ;
F_109 ( & V_2 -> V_124 ) ;
V_7 -> V_70 = V_258 ;
V_2 -> type -> V_130 ( V_2 ) ;
F_110 ( & V_2 -> V_124 ) ;
F_90 ( V_2 ) ;
F_91 ( V_2 -> V_7 ) ;
return 0 ;
}
static int F_224 ( struct V_236 * V_7 , void * V_128 )
{
struct V_1 * V_2 = F_199 ( V_7 ) ;
struct V_260 * V_261 = V_128 ;
T_3 * V_262 = V_261 -> V_263 ;
if ( ! F_225 ( V_262 ) ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_66 ,
V_262 ) ;
return - V_264 ;
}
F_113 ( V_7 -> V_134 , V_262 ) ;
V_2 -> type -> V_265 ( V_2 ) ;
F_109 ( & V_2 -> V_124 ) ;
V_2 -> type -> V_130 ( V_2 ) ;
F_110 ( & V_2 -> V_124 ) ;
return 0 ;
}
static void F_226 ( struct V_236 * V_7 )
{
struct V_1 * V_2 = F_199 ( V_7 ) ;
if ( V_2 -> V_90 )
F_227 ( V_2 -> V_214 , & V_2 -> V_129 ) ;
}
static int F_228 ( struct V_236 * V_7 , T_6 V_128 )
{
struct V_1 * V_2 = F_199 ( V_7 ) ;
if ( V_7 -> V_266 & ~ V_128 & V_204 )
return V_2 -> type -> V_267 ( V_2 , V_268 ) ;
return 0 ;
}
static void F_229 ( struct V_1 * V_2 )
{
strcpy ( V_2 -> V_61 , V_2 -> V_7 -> V_61 ) ;
F_230 ( V_2 ) ;
F_52 ( V_2 ) ;
}
static int F_231 ( struct V_269 * V_270 ,
unsigned long V_271 , void * V_272 )
{
struct V_236 * V_7 = F_232 ( V_272 ) ;
if ( ( V_7 -> V_273 == & V_274 ||
V_7 -> V_273 == & V_275 ) &&
V_271 == V_276 )
F_229 ( F_199 ( V_7 ) ) ;
return V_277 ;
}
static T_7
F_233 ( struct V_278 * V_160 , struct V_279 * V_280 , char * V_57 )
{
struct V_1 * V_2 = F_234 ( F_235 ( V_160 ) ) ;
return sprintf ( V_57 , L_67 , V_2 -> V_281 ) ;
}
static int F_236 ( struct V_1 * V_2 )
{
struct V_236 * V_7 = V_2 -> V_7 ;
struct V_9 * V_10 ;
int V_35 ;
V_7 -> V_282 = 5 * V_283 ;
V_7 -> V_184 = V_2 -> V_154 -> V_184 ;
if ( F_187 ( V_2 ) >= V_284 ) {
V_7 -> V_273 = & V_275 ;
V_7 -> V_285 |= V_286 ;
} else {
V_7 -> V_273 = & V_274 ;
}
V_7 -> V_287 = & V_288 ;
V_7 -> V_289 = V_290 ;
F_237 () ;
V_2 -> V_3 = V_291 ;
F_238 () ;
if ( V_2 -> V_212 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_68 ) ;
V_35 = - V_8 ;
goto V_292;
}
V_35 = F_239 ( V_7 , V_7 -> V_61 ) ;
if ( V_35 < 0 )
goto V_292;
F_229 ( V_2 ) ;
F_101 ( V_7 ) ;
V_35 = F_240 ( V_7 ) ;
if ( V_35 )
goto V_292;
F_53 (channel, efx) {
struct V_41 * V_42 ;
F_46 (tx_queue, channel)
F_241 ( V_42 ) ;
}
F_125 ( V_2 ) ;
F_242 () ;
V_35 = F_243 ( & V_2 -> V_154 -> V_160 , & V_293 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_69 ) ;
goto V_294;
}
return 0 ;
V_294:
F_237 () ;
F_131 ( V_2 ) ;
F_244 ( V_7 ) ;
V_292:
V_2 -> V_3 = V_295 ;
F_242 () ;
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_70 ) ;
return V_35 ;
}
static void F_245 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_7 )
return;
F_73 ( F_199 ( V_2 -> V_7 ) != V_2 ) ;
F_246 ( V_2 -> V_61 , F_129 ( V_2 -> V_154 ) , sizeof( V_2 -> V_61 ) ) ;
F_247 ( & V_2 -> V_154 -> V_160 , & V_293 ) ;
F_237 () ;
F_244 ( V_2 -> V_7 ) ;
V_2 -> V_3 = V_295 ;
F_242 () ;
}
void F_248 ( struct V_1 * V_2 , enum V_296 V_297 )
{
F_72 ( V_2 ) ;
if ( V_297 == V_298 )
V_2 -> type -> V_299 ( V_2 ) ;
F_84 ( V_2 ) ;
F_165 ( V_2 ) ;
F_109 ( & V_2 -> V_124 ) ;
if ( V_2 -> V_139 && V_297 != V_300 )
V_2 -> V_136 -> V_142 ( V_2 ) ;
V_2 -> type -> V_142 ( V_2 ) ;
}
int F_249 ( struct V_1 * V_2 , enum V_296 V_297 , bool V_301 )
{
int V_35 ;
F_72 ( V_2 ) ;
if ( V_297 == V_298 )
V_2 -> type -> V_302 ( V_2 ) ;
V_35 = V_2 -> type -> V_137 ( V_2 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_71 ) ;
goto V_56;
}
if ( ! V_301 )
goto V_56;
if ( V_2 -> V_139 && V_297 != V_300 ) {
V_35 = V_2 -> V_136 -> V_137 ( V_2 ) ;
if ( V_35 )
goto V_56;
if ( V_2 -> V_136 -> V_140 ( V_2 ) )
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_72 ) ;
}
V_35 = F_163 ( V_2 ) ;
if ( V_35 )
goto V_56;
F_183 ( V_2 ) ;
V_2 -> type -> V_303 ( V_2 ) ;
F_110 ( & V_2 -> V_124 ) ;
F_90 ( V_2 ) ;
return 0 ;
V_56:
V_2 -> V_139 = false ;
F_110 ( & V_2 -> V_124 ) ;
return V_35 ;
}
int F_218 ( struct V_1 * V_2 , enum V_296 V_297 )
{
int V_35 , V_99 ;
bool V_304 ;
F_102 ( V_2 , V_6 , V_2 -> V_7 , L_73 ,
F_250 ( V_297 ) ) ;
F_83 ( V_2 ) ;
F_248 ( V_2 , V_297 ) ;
V_35 = V_2 -> type -> V_305 ( V_2 , V_297 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_74 ) ;
goto V_104;
}
if ( V_297 < V_306 )
V_2 -> V_212 &= - ( 1 << ( V_297 + 1 ) ) ;
else
F_251 ( V_297 , & V_2 -> V_212 ) ;
F_134 ( V_2 -> V_154 ) ;
V_104:
V_304 = V_35 ||
V_297 == V_106 ||
V_297 == V_307 ;
V_99 = F_249 ( V_2 , V_297 , ! V_304 ) ;
if ( V_99 ) {
V_304 = true ;
if ( ! V_35 )
V_35 = V_99 ;
}
if ( V_304 ) {
F_252 ( V_2 -> V_7 ) ;
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_75 ) ;
V_2 -> V_3 = V_4 ;
} else {
F_20 ( V_2 , V_6 , V_2 -> V_7 , L_76 ) ;
F_91 ( V_2 -> V_7 ) ;
}
return V_35 ;
}
int F_253 ( struct V_1 * V_2 )
{
#ifdef F_254
struct V_308 * V_309 =
F_255 ( F_256 ( V_2 -> V_154 ) ) ;
if ( F_257 ( V_309 ) ) {
return 1 ;
}
#endif
return 0 ;
}
static void F_258 ( struct V_1 * V_2 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_310 ; ++ V_39 ) {
if ( F_217 ( V_2 ) )
goto V_104;
F_259 ( V_311 ) ;
}
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_77 ) ;
V_104:
V_2 -> V_312 = false ;
}
static void F_260 ( struct V_127 * V_128 )
{
struct V_1 * V_2 = F_11 ( V_128 , struct V_1 , V_313 ) ;
unsigned long V_314 ;
enum V_296 V_297 ;
V_314 = F_261 ( V_2 -> V_212 ) ;
V_297 = F_262 ( V_314 ) - 1 ;
if ( V_297 == V_315 )
F_258 ( V_2 ) ;
if ( ( V_297 == V_307 ||
V_297 == V_316 ) &&
F_253 ( V_2 ) )
return;
if ( ! V_314 )
return;
F_237 () ;
if ( V_2 -> V_3 == V_291 )
( void ) F_218 ( V_2 , V_297 ) ;
F_242 () ;
}
void F_76 ( struct V_1 * V_2 , enum V_296 type )
{
enum V_296 V_297 ;
if ( V_2 -> V_3 == V_5 ) {
F_20 ( V_2 , V_6 , V_2 -> V_7 ,
L_78 ,
F_250 ( type ) ) ;
return;
}
switch ( type ) {
case V_300 :
case V_93 :
case V_316 :
case V_317 :
case V_106 :
case V_307 :
case V_315 :
case V_298 :
V_297 = type ;
F_20 ( V_2 , V_6 , V_2 -> V_7 , L_79 ,
F_250 ( V_297 ) ) ;
break;
default:
V_297 = V_2 -> type -> V_318 ( type ) ;
F_20 ( V_2 , V_6 , V_2 -> V_7 ,
L_80 ,
F_250 ( V_297 ) , F_250 ( type ) ) ;
break;
}
F_263 ( V_297 , & V_2 -> V_212 ) ;
F_238 () ;
if ( F_261 ( V_2 -> V_3 ) != V_291 )
return;
F_160 ( V_2 ) ;
F_227 ( V_319 , & V_2 -> V_313 ) ;
}
int F_264 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_265 ( struct V_1 * V_2 ) {}
static bool F_266 ( struct V_1 * V_2 )
{
return false ;
}
static int F_267 ( struct V_1 * V_2 ,
struct V_154 * V_154 , struct V_236 * V_7 )
{
int V_39 ;
F_268 ( & V_2 -> V_152 ) ;
F_268 ( & V_2 -> V_155 ) ;
F_179 ( & V_2 -> V_320 ) ;
#ifdef F_269
F_268 ( & V_2 -> V_321 ) ;
#endif
F_270 ( & V_2 -> V_313 , F_260 ) ;
F_271 ( & V_2 -> V_144 , F_196 ) ;
F_271 ( & V_2 -> V_322 , V_323 ) ;
V_2 -> V_154 = V_154 ;
V_2 -> V_324 = V_325 ;
V_2 -> V_3 = V_295 ;
F_246 ( V_2 -> V_61 , F_129 ( V_154 ) , sizeof( V_2 -> V_61 ) ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_69 = V_2 -> type -> V_69 ;
V_2 -> V_73 =
V_80 ? ( V_2 -> V_69 + V_80 ) % 4 : 0 ;
V_2 -> V_326 =
V_2 -> type -> V_327 - V_2 -> type -> V_69 ;
V_2 -> V_328 =
V_2 -> type -> V_329 - V_2 -> type -> V_69 ;
F_179 ( & V_2 -> V_220 ) ;
F_272 ( & V_2 -> V_124 ) ;
V_2 -> V_136 = & V_330 ;
V_2 -> V_247 . V_160 = V_7 ;
F_270 ( & V_2 -> V_129 , F_111 ) ;
F_273 ( & V_2 -> V_331 ) ;
for ( V_39 = 0 ; V_39 < V_96 ; V_39 ++ ) {
V_2 -> V_10 [ V_39 ] = F_40 ( V_2 , V_39 , NULL ) ;
if ( ! V_2 -> V_10 [ V_39 ] )
goto V_56;
V_2 -> V_63 [ V_39 ] . V_2 = V_2 ;
V_2 -> V_63 [ V_39 ] . V_101 = V_39 ;
}
V_2 -> V_174 = F_23 ( V_2 -> type -> V_332 ,
V_174 ) ;
snprintf ( V_2 -> V_333 , sizeof( V_2 -> V_333 ) , L_81 ,
F_129 ( V_154 ) ) ;
V_2 -> V_214 = F_274 ( V_2 -> V_333 ) ;
if ( ! V_2 -> V_214 )
goto V_56;
return 0 ;
V_56:
F_275 ( V_2 ) ;
return - V_103 ;
}
static void F_275 ( struct V_1 * V_2 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_96 ; V_39 ++ )
F_88 ( V_2 -> V_10 [ V_39 ] ) ;
F_88 ( V_2 -> V_148 ) ;
if ( V_2 -> V_214 ) {
F_276 ( V_2 -> V_214 ) ;
V_2 -> V_214 = NULL ;
}
}
void F_277 ( struct V_1 * V_2 , T_8 * V_255 )
{
T_8 V_334 = 0 ;
struct V_9 * V_10 ;
F_53 (channel, efx)
V_334 += V_10 -> V_334 ;
V_255 [ V_335 ] = V_334 ;
V_255 [ V_336 ] = F_278 ( & V_2 -> V_337 ) ;
}
static void F_279 ( struct V_1 * V_2 )
{
F_73 ( V_2 -> V_3 == V_291 ) ;
F_121 ( & V_2 -> V_313 ) ;
F_165 ( V_2 ) ;
F_280 ( V_2 ) ;
F_122 ( V_2 ) ;
V_2 -> type -> V_142 ( V_2 ) ;
F_210 ( V_2 ) ;
F_191 ( V_2 ) ;
}
static void F_281 ( struct V_154 * V_154 )
{
struct V_1 * V_2 ;
V_2 = F_234 ( V_154 ) ;
if ( ! V_2 )
return;
F_237 () ;
F_131 ( V_2 ) ;
F_252 ( V_2 -> V_7 ) ;
F_165 ( V_2 ) ;
F_242 () ;
V_2 -> type -> V_338 ( V_2 ) ;
F_245 ( V_2 ) ;
F_282 ( V_2 ) ;
F_279 ( V_2 ) ;
F_142 ( V_2 ) ;
F_20 ( V_2 , V_6 , V_2 -> V_7 , L_82 ) ;
F_275 ( V_2 ) ;
F_283 ( V_2 -> V_7 ) ;
F_284 ( V_154 ) ;
}
static void F_285 ( struct V_1 * V_2 )
{
struct V_154 * V_160 = V_2 -> V_154 ;
char V_339 [ V_340 ] ;
T_7 V_341 ;
int V_342 , V_343 , V_39 , V_43 ;
V_341 = F_286 ( V_160 , 0 , sizeof( V_339 ) , V_339 ) ;
if ( V_341 <= 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_83 ) ;
return;
}
V_342 = F_287 ( V_339 , 0 , V_341 , V_344 ) ;
if ( V_342 < 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_84 ) ;
return;
}
V_343 = F_288 ( & V_339 [ V_342 ] ) ;
V_43 = V_343 ;
V_39 = V_342 + V_345 ;
if ( V_39 + V_43 > V_341 )
V_43 = V_341 - V_39 ;
V_39 = F_289 ( V_339 , V_39 , V_43 , L_85 ) ;
if ( V_39 < 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_86 ) ;
return;
}
V_43 = F_290 ( & V_339 [ V_39 ] ) ;
V_39 += V_346 ;
if ( V_39 + V_43 > V_341 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_87 ) ;
return;
}
F_102 ( V_2 , V_6 , V_2 -> V_7 ,
L_88 , V_43 , & V_339 [ V_39 ] ) ;
V_39 = V_342 + V_345 ;
V_43 = V_343 ;
V_39 = F_289 ( V_339 , V_39 , V_43 , L_89 ) ;
if ( V_39 < 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_90 ) ;
return;
}
V_43 = F_290 ( & V_339 [ V_39 ] ) ;
V_39 += V_346 ;
if ( V_39 + V_43 > V_341 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_91 ) ;
return;
}
V_2 -> V_148 = F_44 ( V_43 + 1 , V_44 ) ;
if ( ! V_2 -> V_148 )
return;
snprintf ( V_2 -> V_148 , V_43 + 1 , L_92 , & V_339 [ V_39 ] ) ;
}
static int F_291 ( struct V_1 * V_2 )
{
int V_35 ;
V_35 = F_184 ( V_2 ) ;
if ( V_35 )
goto V_138;
F_207 ( V_2 ) ;
V_35 = V_2 -> type -> V_137 ( V_2 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_71 ) ;
goto V_163;
}
V_35 = F_114 ( V_2 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_93 ) ;
goto V_165;
}
V_35 = F_292 ( V_2 ) ;
if ( V_35 )
goto V_347;
V_35 = F_163 ( V_2 ) ;
if ( V_35 )
goto V_348;
return 0 ;
V_348:
F_280 ( V_2 ) ;
V_347:
F_122 ( V_2 ) ;
V_165:
V_2 -> type -> V_142 ( V_2 ) ;
V_163:
F_210 ( V_2 ) ;
F_191 ( V_2 ) ;
V_138:
return V_35 ;
}
static int F_293 ( struct V_154 * V_154 ,
const struct V_349 * V_180 )
{
struct V_236 * V_7 ;
struct V_1 * V_2 ;
int V_35 ;
V_7 = F_294 ( sizeof( * V_2 ) , V_350 ,
V_351 ) ;
if ( ! V_7 )
return - V_103 ;
V_2 = F_199 ( V_7 ) ;
V_2 -> type = ( const struct V_352 * ) V_180 -> V_353 ;
V_7 -> V_266 |= ( V_2 -> type -> V_203 | V_354 |
V_355 | V_356 |
V_357 ) ;
if ( V_2 -> type -> V_203 & V_358 )
V_7 -> V_266 |= V_359 ;
V_7 -> V_360 |= ( V_361 | V_354 |
V_355 | V_362 |
V_357 ) ;
V_7 -> V_363 = V_7 -> V_266 & ~ V_355 ;
F_295 ( V_154 , V_2 ) ;
F_296 ( V_7 , & V_154 -> V_160 ) ;
V_35 = F_267 ( V_2 , V_154 , V_7 ) ;
if ( V_35 )
goto V_138;
F_102 ( V_2 , V_29 , V_2 -> V_7 ,
L_94 ) ;
F_285 ( V_2 ) ;
V_35 = F_132 ( V_2 ) ;
if ( V_35 )
goto V_141;
V_35 = F_291 ( V_2 ) ;
if ( V_35 )
goto V_163;
V_35 = F_236 ( V_2 ) ;
if ( V_35 )
goto V_165;
V_35 = V_2 -> type -> V_364 ( V_2 ) ;
if ( V_35 )
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_95 , V_35 ) ;
F_20 ( V_2 , V_29 , V_2 -> V_7 , L_96 ) ;
F_237 () ;
V_35 = F_297 ( V_2 ) ;
F_242 () ;
if ( V_35 )
F_146 ( V_2 , V_29 , V_2 -> V_7 ,
L_97 , V_35 ) ;
V_35 = F_298 ( V_154 ) ;
if ( V_35 && V_35 != - V_211 )
F_146 ( V_2 , V_29 , V_2 -> V_7 ,
L_98 , V_35 ) ;
return 0 ;
V_165:
F_279 ( V_2 ) ;
V_163:
F_142 ( V_2 ) ;
V_141:
F_275 ( V_2 ) ;
V_138:
F_67 ( V_35 > 0 ) ;
F_20 ( V_2 , V_6 , V_2 -> V_7 , L_99 , V_35 ) ;
F_283 ( V_7 ) ;
return V_35 ;
}
static int F_299 ( struct V_278 * V_160 )
{
struct V_1 * V_2 = F_234 ( F_235 ( V_160 ) ) ;
F_237 () ;
if ( V_2 -> V_3 != V_4 ) {
V_2 -> V_3 = V_295 ;
F_83 ( V_2 ) ;
F_84 ( V_2 ) ;
F_165 ( V_2 ) ;
}
F_242 () ;
return 0 ;
}
static int F_300 ( struct V_278 * V_160 )
{
int V_35 ;
struct V_1 * V_2 = F_234 ( F_235 ( V_160 ) ) ;
F_237 () ;
if ( V_2 -> V_3 != V_4 ) {
V_35 = F_163 ( V_2 ) ;
if ( V_35 )
goto V_56;
F_109 ( & V_2 -> V_124 ) ;
V_2 -> V_136 -> V_140 ( V_2 ) ;
F_110 ( & V_2 -> V_124 ) ;
F_90 ( V_2 ) ;
F_91 ( V_2 -> V_7 ) ;
V_2 -> V_3 = V_291 ;
V_2 -> type -> V_365 ( V_2 ) ;
}
F_242 () ;
F_227 ( V_319 , & V_2 -> V_313 ) ;
return 0 ;
V_56:
F_242 () ;
return V_35 ;
}
static int F_301 ( struct V_278 * V_160 )
{
struct V_154 * V_154 = F_235 ( V_160 ) ;
struct V_1 * V_2 = F_234 ( V_154 ) ;
V_2 -> type -> V_142 ( V_2 ) ;
V_2 -> V_212 = 0 ;
F_302 ( V_154 ) ;
return F_303 ( V_154 , V_366 ) ;
}
static int F_304 ( struct V_278 * V_160 )
{
struct V_154 * V_154 = F_235 ( V_160 ) ;
struct V_1 * V_2 = F_234 ( V_154 ) ;
int V_35 ;
V_35 = F_303 ( V_154 , V_367 ) ;
if ( V_35 )
return V_35 ;
F_305 ( V_154 ) ;
V_35 = F_133 ( V_154 ) ;
if ( V_35 )
return V_35 ;
F_134 ( V_2 -> V_154 ) ;
V_35 = V_2 -> type -> V_305 ( V_2 , V_93 ) ;
if ( V_35 )
return V_35 ;
V_35 = V_2 -> type -> V_137 ( V_2 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_300 ( V_160 ) ;
return V_35 ;
}
static int F_306 ( struct V_278 * V_160 )
{
int V_35 ;
F_299 ( V_160 ) ;
V_35 = F_301 ( V_160 ) ;
if ( V_35 )
F_304 ( V_160 ) ;
return V_35 ;
}
static T_9 F_307 ( struct V_154 * V_368 ,
enum V_369 V_3 )
{
T_9 V_370 = V_371 ;
struct V_1 * V_2 = F_234 ( V_368 ) ;
if ( V_3 == V_372 )
return V_373 ;
F_237 () ;
if ( V_2 -> V_3 != V_4 ) {
V_2 -> V_3 = V_5 ;
V_2 -> V_212 = 0 ;
F_83 ( V_2 ) ;
F_84 ( V_2 ) ;
F_165 ( V_2 ) ;
V_370 = V_374 ;
} else {
V_370 = V_371 ;
}
F_242 () ;
F_141 ( V_368 ) ;
return V_370 ;
}
static T_9 F_308 ( struct V_154 * V_368 )
{
struct V_1 * V_2 = F_234 ( V_368 ) ;
T_9 V_370 = V_371 ;
int V_35 ;
if ( F_133 ( V_368 ) ) {
F_2 ( V_2 , V_375 , V_2 -> V_7 ,
L_100 ) ;
V_370 = V_373 ;
}
V_35 = F_309 ( V_368 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_375 , V_2 -> V_7 ,
L_101 , V_35 ) ;
}
return V_370 ;
}
static void F_310 ( struct V_154 * V_368 )
{
struct V_1 * V_2 = F_234 ( V_368 ) ;
int V_35 ;
F_237 () ;
if ( V_2 -> V_3 == V_4 )
goto V_104;
V_35 = F_218 ( V_2 , V_93 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_375 , V_2 -> V_7 ,
L_102 , V_35 ) ;
} else {
V_2 -> V_3 = V_291 ;
F_20 ( V_2 , V_375 , V_2 -> V_7 ,
L_103 ) ;
}
V_104:
F_242 () ;
}
static int T_10 F_311 ( void )
{
int V_35 ;
F_312 ( V_376 L_104 V_377 L_105 ) ;
V_35 = F_313 ( & V_378 ) ;
if ( V_35 )
goto V_379;
V_35 = F_314 () ;
if ( V_35 )
goto V_380;
V_319 = F_274 ( L_106 ) ;
if ( ! V_319 ) {
V_35 = - V_103 ;
goto V_381;
}
V_35 = F_315 ( & V_382 ) ;
if ( V_35 < 0 )
goto V_383;
return 0 ;
V_383:
F_276 ( V_319 ) ;
V_381:
F_316 () ;
V_380:
F_317 ( & V_378 ) ;
V_379:
return V_35 ;
}
static void T_11 F_318 ( void )
{
F_312 ( V_376 L_107 ) ;
F_319 ( & V_382 ) ;
F_276 ( V_319 ) ;
F_316 () ;
F_317 ( & V_378 ) ;
}

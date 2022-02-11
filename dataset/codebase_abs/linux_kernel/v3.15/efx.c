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
F_12 ( V_2 , V_19 , V_2 -> V_7 ,
L_2 ,
V_10 -> V_10 , F_13 () ) ;
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
F_14 ( V_10 ) ;
F_15 ( V_17 ) ;
F_16 ( V_10 ) ;
}
return V_12 ;
}
static int F_17 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned long V_28 ;
F_18 ( V_2 , V_29 , V_2 -> V_7 ,
L_3 , V_10 -> V_10 ) ;
V_28 = F_19 ( V_2 -> V_30 + V_2 -> V_31 + 128 ) ;
F_20 ( V_28 > V_32 ) ;
V_10 -> V_33 = F_21 ( V_28 , V_34 ) - 1 ;
return F_22 ( V_10 ) ;
}
static int F_23 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_35 ;
F_24 ( V_10 -> V_36 ) ;
F_18 ( V_2 , V_6 , V_2 -> V_7 ,
L_4 , V_10 -> V_10 ) ;
V_35 = F_25 ( V_10 ) ;
if ( V_35 == 0 ) {
V_2 -> type -> V_25 ( V_10 ) ;
V_10 -> V_37 = 0 ;
V_10 -> V_36 = true ;
}
return V_35 ;
}
static void F_26 ( struct V_9 * V_10 )
{
F_18 ( V_10 -> V_2 , V_38 , V_10 -> V_2 -> V_7 ,
L_5 , V_10 -> V_10 ) ;
V_10 -> V_13 = true ;
F_27 () ;
F_28 ( & V_10 -> V_18 ) ;
F_16 ( V_10 ) ;
}
static void F_29 ( struct V_9 * V_10 )
{
if ( ! V_10 -> V_13 )
return;
F_30 ( & V_10 -> V_18 ) ;
V_10 -> V_13 = false ;
}
static void F_31 ( struct V_9 * V_10 )
{
if ( ! V_10 -> V_36 )
return;
F_18 ( V_10 -> V_2 , V_6 , V_10 -> V_2 -> V_7 ,
L_6 , V_10 -> V_10 ) ;
F_32 ( V_10 ) ;
V_10 -> V_36 = false ;
}
static void F_33 ( struct V_9 * V_10 )
{
F_18 ( V_10 -> V_2 , V_6 , V_10 -> V_2 -> V_7 ,
L_7 , V_10 -> V_10 ) ;
F_34 ( V_10 ) ;
}
static struct V_9 *
F_35 ( struct V_1 * V_2 , int V_39 , struct V_9 * V_40 )
{
struct V_9 * V_10 ;
struct V_14 * V_15 ;
struct V_41 * V_42 ;
int V_43 ;
V_10 = F_36 ( sizeof( * V_10 ) , V_44 ) ;
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
F_37 ( & V_15 -> V_48 , V_49 ,
( unsigned long ) V_15 ) ;
return V_10 ;
}
static struct V_9 *
F_38 ( const struct V_9 * V_40 )
{
struct V_9 * V_10 ;
struct V_14 * V_15 ;
struct V_41 * V_42 ;
int V_43 ;
V_10 = F_39 ( sizeof( * V_10 ) , V_44 ) ;
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
F_37 ( & V_15 -> V_48 , V_49 ,
( unsigned long ) V_15 ) ;
return V_10 ;
}
static int F_40 ( struct V_9 * V_10 )
{
struct V_41 * V_42 ;
struct V_14 * V_15 ;
int V_35 ;
F_18 ( V_10 -> V_2 , V_29 , V_10 -> V_2 -> V_7 ,
L_8 , V_10 -> V_10 ) ;
V_35 = V_10 -> type -> V_55 ( V_10 ) ;
if ( V_35 )
goto V_56;
V_35 = F_17 ( V_10 ) ;
if ( V_35 )
goto V_56;
F_41 (tx_queue, channel) {
V_35 = F_42 ( V_42 ) ;
if ( V_35 )
goto V_56;
}
F_43 (rx_queue, channel) {
V_35 = F_44 ( V_15 ) ;
if ( V_35 )
goto V_56;
}
return 0 ;
V_56:
F_45 ( V_10 ) ;
return V_35 ;
}
static void
F_46 ( struct V_9 * V_10 , char * V_57 , T_1 V_58 )
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
static void F_47 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_48 (channel, efx)
V_10 -> type -> V_62 ( V_10 ,
V_2 -> V_63 [ V_10 -> V_10 ] . V_61 ,
sizeof( V_2 -> V_63 [ 0 ] . V_61 ) ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
int V_35 ;
V_2 -> V_64 = 0 ;
F_50 (channel, efx) {
V_35 = F_40 ( V_10 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_13 ,
V_10 -> V_10 ) ;
goto V_56;
}
}
F_47 ( V_2 ) ;
return 0 ;
V_56:
F_51 ( V_2 ) ;
return V_35 ;
}
static void F_52 ( struct V_1 * V_2 )
{
bool V_65 = V_2 -> V_66 ;
struct V_41 * V_42 ;
struct V_14 * V_15 ;
struct V_9 * V_10 ;
T_1 V_67 ;
V_2 -> V_68 = ( V_2 -> V_69 +
F_53 ( V_2 -> V_7 -> V_70 ) +
V_2 -> type -> V_71 ) ;
V_67 = ( sizeof( struct V_72 ) +
V_2 -> V_73 + V_2 -> V_68 ) ;
if ( V_67 <= V_74 ) {
V_2 -> V_66 = V_2 -> type -> V_75 ;
V_2 -> V_76 = 0 ;
} else if ( V_2 -> type -> V_77 ) {
F_54 ( V_78 % V_79 ) ;
F_54 ( sizeof( struct V_72 ) +
2 * F_55 ( V_80 + V_78 ,
V_81 ) >
V_74 ) ;
V_2 -> V_66 = true ;
V_2 -> V_68 = V_78 ;
V_2 -> V_76 = 0 ;
} else {
V_2 -> V_66 = false ;
V_2 -> V_76 = F_56 ( V_67 ) ;
}
F_57 ( V_2 ) ;
if ( V_2 -> V_76 )
F_18 ( V_2 , V_6 , V_2 -> V_7 ,
L_14 ,
V_2 -> V_68 , V_2 -> V_76 ,
V_2 -> V_82 ) ;
else
F_18 ( V_2 , V_6 , V_2 -> V_7 ,
L_15 ,
V_2 -> V_68 , V_2 -> V_83 ,
V_2 -> V_84 , V_2 -> V_82 ) ;
if ( V_2 -> V_66 != V_65 )
V_2 -> type -> V_85 ( V_2 ) ;
V_2 -> V_86 = V_2 -> V_31 - F_58 ( V_2 ) ;
V_2 -> V_87 = V_2 -> V_86 / 2 ;
F_48 (channel, efx) {
F_41 (tx_queue, channel) {
F_59 ( V_42 ) ;
F_60 ( & V_2 -> V_88 ) ;
}
F_43 (rx_queue, channel) {
F_61 ( V_15 ) ;
F_60 ( & V_2 -> V_88 ) ;
F_29 ( V_10 ) ;
F_9 ( V_15 , false ) ;
F_26 ( V_10 ) ;
}
F_62 ( V_10 -> V_89 ) ;
}
F_63 ( V_2 ) ;
if ( F_64 ( V_2 -> V_7 ) )
F_65 ( V_2 -> V_7 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_41 * V_42 ;
struct V_14 * V_15 ;
int V_35 ;
F_67 ( V_2 ) ;
F_68 ( V_2 -> V_90 ) ;
F_69 ( V_2 ) ;
F_48 (channel, efx) {
F_43 (rx_queue, channel)
V_15 -> V_91 = false ;
}
F_48 (channel, efx) {
if ( F_6 ( V_10 ) ) {
F_29 ( V_10 ) ;
F_26 ( V_10 ) ;
}
}
V_35 = V_2 -> type -> V_92 ( V_2 ) ;
if ( V_35 && F_70 ( V_2 ) ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_16 ) ;
F_71 ( V_2 , V_93 ) ;
} else if ( V_35 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_17 ) ;
} else {
F_18 ( V_2 , V_6 , V_2 -> V_7 ,
L_18 ) ;
}
F_48 (channel, efx) {
F_43 (rx_queue, channel)
F_72 ( V_15 ) ;
F_73 (tx_queue, channel)
F_74 ( V_42 ) ;
}
}
static void F_45 ( struct V_9 * V_10 )
{
struct V_41 * V_42 ;
struct V_14 * V_15 ;
F_18 ( V_10 -> V_2 , V_6 , V_10 -> V_2 -> V_7 ,
L_19 , V_10 -> V_10 ) ;
F_43 (rx_queue, channel)
F_75 ( V_15 ) ;
F_73 (tx_queue, channel)
F_76 ( V_42 ) ;
F_33 ( V_10 ) ;
V_10 -> type -> V_94 ( V_10 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_48 (channel, efx)
F_45 ( V_10 ) ;
}
int
F_77 ( struct V_1 * V_2 , T_2 V_30 , T_2 V_31 )
{
struct V_9 * V_95 [ V_96 ] , * V_10 ;
T_2 V_97 , V_98 ;
unsigned V_39 , V_64 = 0 ;
int V_35 , V_99 ;
V_35 = F_1 ( V_2 ) ;
if ( V_35 )
return V_35 ;
F_48 (channel, efx) {
struct V_14 * V_15 ;
struct V_41 * V_42 ;
if ( V_10 -> type -> V_100 )
continue;
V_64 = F_21 ( V_64 ,
V_10 -> V_51 . V_101 +
V_10 -> V_51 . V_28 ) ;
F_43 (rx_queue, channel)
V_64 = F_21 ( V_64 ,
V_15 -> V_54 . V_101 +
V_15 -> V_54 . V_28 ) ;
F_41 (tx_queue, channel)
V_64 = F_21 ( V_64 ,
V_42 -> V_53 . V_101 +
V_42 -> V_53 . V_28 ) ;
}
F_78 ( V_2 ) ;
F_79 ( V_2 ) ;
F_80 ( V_2 ) ;
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
V_35 = F_40 ( V_10 ) ;
if ( V_35 )
goto V_105;
F_81 ( V_2 -> V_10 [ V_39 ] ) ;
}
V_104:
for ( V_39 = 0 ; V_39 < V_2 -> V_102 ; V_39 ++ ) {
V_10 = V_95 [ V_39 ] ;
if ( V_10 && V_10 -> type -> V_100 ) {
F_82 ( V_10 ) ;
F_45 ( V_10 ) ;
F_83 ( V_10 ) ;
}
}
V_99 = F_84 ( V_2 ) ;
if ( V_99 ) {
V_35 = V_35 ? V_35 : V_99 ;
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_20 ) ;
F_71 ( V_2 , V_106 ) ;
} else {
F_85 ( V_2 ) ;
F_86 ( V_2 -> V_7 ) ;
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
void F_87 ( struct V_14 * V_15 )
{
F_88 ( & V_15 -> V_48 , V_107 + F_89 ( 100 ) ) ;
}
int F_90 ( struct V_9 * V_10 )
{
return 0 ;
}
void F_91 ( struct V_9 * V_10 )
{
}
void F_92 ( struct V_1 * V_2 )
{
struct V_108 * V_109 = & V_2 -> V_109 ;
if ( ! F_93 ( V_2 -> V_7 ) )
return;
if ( V_109 -> V_110 != F_94 ( V_2 -> V_7 ) ) {
V_2 -> V_111 ++ ;
if ( V_109 -> V_110 )
F_95 ( V_2 -> V_7 ) ;
else
F_96 ( V_2 -> V_7 ) ;
}
if ( V_109 -> V_110 )
F_97 ( V_2 , V_112 , V_2 -> V_7 ,
L_21 ,
V_109 -> V_113 , V_109 -> V_114 ? L_22 : L_23 ,
V_2 -> V_7 -> V_70 ) ;
else
F_97 ( V_2 , V_112 , V_2 -> V_7 , L_24 ) ;
}
void F_98 ( struct V_1 * V_2 , T_2 V_115 )
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
void F_99 ( struct V_1 * V_2 , T_3 V_118 )
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
int F_100 ( struct V_1 * V_2 )
{
enum V_122 V_123 ;
int V_35 ;
F_62 ( ! F_101 ( & V_2 -> V_124 ) ) ;
V_123 = V_2 -> V_123 ;
if ( F_102 ( V_2 ) )
V_2 -> V_123 |= V_125 ;
else
V_2 -> V_123 &= ~ V_125 ;
V_35 = V_2 -> type -> V_126 ( V_2 ) ;
if ( V_35 )
V_2 -> V_123 = V_123 ;
return V_35 ;
}
int F_103 ( struct V_1 * V_2 )
{
int V_35 ;
F_67 ( V_2 ) ;
F_104 ( & V_2 -> V_124 ) ;
V_35 = F_100 ( V_2 ) ;
F_105 ( & V_2 -> V_124 ) ;
return V_35 ;
}
static void F_106 ( struct V_127 * V_128 )
{
struct V_1 * V_2 = F_11 ( V_128 , struct V_1 , V_129 ) ;
F_104 ( & V_2 -> V_124 ) ;
if ( V_2 -> V_90 )
V_2 -> type -> V_130 ( V_2 ) ;
F_105 ( & V_2 -> V_124 ) ;
}
static int F_107 ( struct V_1 * V_2 )
{
int V_35 ;
F_18 ( V_2 , V_29 , V_2 -> V_7 , L_25 ) ;
if ( V_131 )
V_2 -> V_123 = V_132 ;
V_35 = V_2 -> type -> V_133 ( V_2 ) ;
if ( V_35 )
return V_35 ;
F_108 ( V_2 -> V_7 -> V_134 , V_2 -> V_7 -> V_135 ) ;
return 0 ;
}
static int F_109 ( struct V_1 * V_2 )
{
int V_35 ;
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_26 ) ;
F_104 ( & V_2 -> V_124 ) ;
V_35 = V_2 -> V_136 -> V_137 ( V_2 ) ;
if ( V_35 )
goto V_138;
V_2 -> V_139 = true ;
V_2 -> type -> V_130 ( V_2 ) ;
V_35 = V_2 -> V_136 -> V_140 ( V_2 ) ;
if ( V_35 )
goto V_141;
F_105 ( & V_2 -> V_124 ) ;
return 0 ;
V_141:
V_2 -> V_136 -> V_142 ( V_2 ) ;
V_138:
F_105 ( & V_2 -> V_124 ) ;
return V_35 ;
}
static void F_110 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_38 , V_2 -> V_7 , L_27 ) ;
F_68 ( V_2 -> V_90 ) ;
F_104 ( & V_2 -> V_124 ) ;
V_2 -> V_90 = true ;
V_2 -> type -> V_130 ( V_2 ) ;
F_105 ( & V_2 -> V_124 ) ;
}
static void F_111 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_143 , V_2 -> V_7 , L_28 ) ;
F_67 ( V_2 ) ;
F_104 ( & V_2 -> V_124 ) ;
V_2 -> V_90 = false ;
F_105 ( & V_2 -> V_124 ) ;
F_112 ( V_2 -> V_7 ) ;
F_113 ( V_2 -> V_7 ) ;
F_114 ( & V_2 -> V_144 ) ;
F_115 ( V_2 ) ;
F_116 ( & V_2 -> V_129 ) ;
}
static void F_117 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_29 ) ;
if ( ! V_2 -> V_139 )
return;
V_2 -> V_136 -> V_142 ( V_2 ) ;
V_2 -> V_139 = false ;
V_2 -> V_109 . V_110 = false ;
F_92 ( V_2 ) ;
}
static void F_118 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_30 ) ;
V_2 -> type -> V_145 ( V_2 ) ;
}
static bool F_119 ( struct V_1 * V_146 , struct V_1 * V_147 )
{
return V_146 -> type == V_147 -> type &&
V_146 -> V_148 && V_147 -> V_148 &&
! strcmp ( V_146 -> V_148 , V_147 -> V_148 ) ;
}
static void F_120 ( struct V_1 * V_2 )
{
struct V_1 * V_149 , * V_150 ;
if ( V_2 -> V_151 == V_2 ) {
F_18 ( V_2 , V_29 , V_2 -> V_7 , L_31 ) ;
F_121 ( & V_2 -> V_152 , & V_153 ) ;
F_122 (other, next, &efx_unassociated_list,
node) {
if ( F_119 ( V_2 , V_149 ) ) {
F_123 ( & V_149 -> V_152 ) ;
F_18 ( V_149 , V_29 , V_149 -> V_7 ,
L_32 ,
F_124 ( V_2 -> V_154 ) ,
V_2 -> V_7 -> V_61 ) ;
F_121 ( & V_149 -> V_152 ,
& V_2 -> V_155 ) ;
V_149 -> V_151 = V_2 ;
}
}
} else {
F_125 (other, &efx_primary_list, node) {
if ( F_119 ( V_2 , V_149 ) ) {
F_18 ( V_2 , V_29 , V_2 -> V_7 ,
L_33 ,
F_124 ( V_149 -> V_154 ) ,
V_149 -> V_7 -> V_61 ) ;
F_121 ( & V_2 -> V_152 ,
& V_149 -> V_155 ) ;
V_2 -> V_151 = V_149 ;
return;
}
}
F_18 ( V_2 , V_29 , V_2 -> V_7 ,
L_34 ) ;
F_121 ( & V_2 -> V_152 , & V_156 ) ;
}
}
static void F_126 ( struct V_1 * V_2 )
{
struct V_1 * V_149 , * V_150 ;
F_123 ( & V_2 -> V_152 ) ;
V_2 -> V_151 = NULL ;
F_122 (other, next, &efx->secondary_list, node) {
F_123 ( & V_149 -> V_152 ) ;
F_18 ( V_149 , V_29 , V_149 -> V_7 ,
L_35 ) ;
F_121 ( & V_149 -> V_152 , & V_156 ) ;
V_149 -> V_151 = NULL ;
}
}
static int F_127 ( struct V_1 * V_2 )
{
struct V_154 * V_154 = V_2 -> V_154 ;
T_4 V_157 = V_2 -> type -> V_158 ;
unsigned int V_159 = V_2 -> type -> V_159 ( V_2 ) ;
int V_35 ;
F_18 ( V_2 , V_29 , V_2 -> V_7 , L_36 ) ;
V_35 = F_128 ( V_154 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_37 ) ;
goto V_138;
}
F_129 ( V_154 ) ;
while ( V_157 > 0x7fffffffUL ) {
if ( F_130 ( & V_154 -> V_160 , V_157 ) ) {
V_35 = F_131 ( & V_154 -> V_160 , V_157 ) ;
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
F_18 ( V_2 , V_29 , V_2 -> V_7 ,
L_39 , ( unsigned long long ) V_157 ) ;
V_2 -> V_161 = F_132 ( V_2 -> V_154 , V_162 ) ;
V_35 = F_133 ( V_154 , V_162 , L_40 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_41 ) ;
V_35 = - V_8 ;
goto V_163;
}
V_2 -> V_164 = F_134 ( V_2 -> V_161 , V_159 ) ;
if ( ! V_2 -> V_164 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_42 ,
( unsigned long long ) V_2 -> V_161 , V_159 ) ;
V_35 = - V_103 ;
goto V_165;
}
F_18 ( V_2 , V_29 , V_2 -> V_7 ,
L_43 ,
( unsigned long long ) V_2 -> V_161 , V_159 ,
V_2 -> V_164 ) ;
return 0 ;
V_165:
F_135 ( V_2 -> V_154 , V_162 ) ;
V_163:
V_2 -> V_161 = 0 ;
V_141:
F_136 ( V_2 -> V_154 ) ;
V_138:
return V_35 ;
}
static void F_137 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_44 ) ;
if ( V_2 -> V_164 ) {
F_138 ( V_2 -> V_164 ) ;
V_2 -> V_164 = NULL ;
}
if ( V_2 -> V_161 ) {
F_135 ( V_2 -> V_154 , V_162 ) ;
V_2 -> V_161 = 0 ;
}
F_136 ( V_2 -> V_154 ) ;
}
static unsigned int F_139 ( struct V_1 * V_2 )
{
T_5 V_166 ;
unsigned int V_167 ;
int V_168 ;
if ( V_169 ) {
V_167 = V_169 ;
} else {
if ( F_4 ( ! F_140 ( & V_166 , V_44 ) ) ) {
F_141 ( V_2 , V_29 , V_2 -> V_7 ,
L_45 ) ;
return 1 ;
}
V_167 = 0 ;
F_142 (cpu) {
if ( ! F_143 ( V_168 , V_166 ) ) {
++ V_167 ;
F_144 ( V_166 , V_166 ,
F_145 ( V_168 ) ) ;
}
}
F_146 ( V_166 ) ;
}
if ( F_147 ( V_2 ) && F_148 ( V_2 ) > 1 &&
V_167 > F_148 ( V_2 ) ) {
F_141 ( V_2 , V_29 , V_2 -> V_7 ,
L_46
L_47
L_48 ,
V_167 , F_148 ( V_2 ) ) ;
V_167 = F_148 ( V_2 ) ;
}
return V_167 ;
}
static int F_149 ( struct V_1 * V_2 )
{
unsigned int V_170 = 0 ;
unsigned int V_39 , V_43 ;
int V_35 ;
for ( V_39 = 0 ; V_39 < V_171 ; V_39 ++ )
if ( V_2 -> V_172 [ V_39 ] )
++ V_170 ;
if ( V_2 -> V_173 == V_174 ) {
struct V_175 V_176 [ V_96 ] ;
unsigned int V_102 ;
V_102 = F_139 ( V_2 ) ;
if ( V_177 )
V_102 *= 2 ;
V_102 += V_170 ;
V_102 = F_150 ( V_102 , V_2 -> V_178 ) ;
for ( V_39 = 0 ; V_39 < V_102 ; V_39 ++ )
V_176 [ V_39 ] . V_179 = V_39 ;
V_35 = F_151 ( V_2 -> V_154 ,
V_176 , 1 , V_102 ) ;
if ( V_35 < 0 ) {
V_2 -> V_173 = V_180 ;
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
if ( V_102 > V_170 )
V_102 -= V_170 ;
if ( V_177 ) {
V_2 -> V_181 = F_21 ( V_102 / 2 , 1U ) ;
V_2 -> V_182 = F_21 ( V_102 -
V_2 -> V_181 ,
1U ) ;
} else {
V_2 -> V_181 = V_102 ;
V_2 -> V_182 = V_102 ;
}
for ( V_39 = 0 ; V_39 < V_2 -> V_102 ; V_39 ++ )
F_152 ( V_2 , V_39 ) -> V_183 =
V_176 [ V_39 ] . V_184 ;
}
}
if ( V_2 -> V_173 == V_180 ) {
V_2 -> V_102 = 1 ;
V_2 -> V_182 = 1 ;
V_2 -> V_181 = 1 ;
V_35 = F_153 ( V_2 -> V_154 ) ;
if ( V_35 == 0 ) {
F_152 ( V_2 , 0 ) -> V_183 = V_2 -> V_154 -> V_183 ;
} else {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_53 ) ;
V_2 -> V_173 = V_185 ;
}
}
if ( V_2 -> V_173 == V_185 ) {
V_2 -> V_102 = 1 + ( V_177 ? 1 : 0 ) ;
V_2 -> V_182 = 1 ;
V_2 -> V_181 = 1 ;
V_2 -> V_186 = V_2 -> V_154 -> V_183 ;
}
V_43 = V_2 -> V_102 ;
for ( V_39 = 0 ; V_39 < V_171 ; V_39 ++ ) {
if ( ! V_2 -> V_172 [ V_39 ] )
continue;
if ( V_2 -> V_173 != V_174 ||
V_2 -> V_102 <= V_170 ) {
V_2 -> V_172 [ V_39 ] -> F_154 ( V_2 ) ;
} else {
-- V_43 ;
F_152 ( V_2 , V_43 ) -> type =
V_2 -> V_172 [ V_39 ] ;
}
}
V_2 -> V_187 = ( ( V_2 -> V_182 > 1 || ! F_147 ( V_2 ) ) ?
V_2 -> V_182 : F_148 ( V_2 ) ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 )
{
struct V_9 * V_10 , * V_188 ;
int V_35 ;
F_68 ( V_2 -> V_3 == V_4 ) ;
V_2 -> V_189 = true ;
F_27 () ;
F_48 (channel, efx) {
if ( ! V_10 -> type -> V_190 ) {
V_35 = F_23 ( V_10 ) ;
if ( V_35 )
goto V_56;
}
F_26 ( V_10 ) ;
}
F_155 ( V_2 ) ;
return 0 ;
V_56:
V_188 = V_10 ;
F_48 (channel, efx) {
if ( V_10 == V_188 )
break;
F_29 ( V_10 ) ;
if ( ! V_10 -> type -> V_190 )
F_31 ( V_10 ) ;
}
return V_35 ;
}
static void F_80 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
if ( V_2 -> V_3 == V_4 )
return;
F_156 ( V_2 ) ;
V_2 -> V_189 = false ;
F_27 () ;
if ( V_2 -> V_186 )
F_157 ( V_2 -> V_186 ) ;
F_48 (channel, efx) {
if ( V_10 -> V_183 )
F_157 ( V_10 -> V_183 ) ;
F_29 ( V_10 ) ;
if ( ! V_10 -> type -> V_190 )
F_31 ( V_10 ) ;
}
F_158 ( V_2 ) ;
}
static int F_159 ( struct V_1 * V_2 )
{
struct V_9 * V_10 , * V_188 ;
int V_35 ;
F_68 ( V_2 -> V_3 == V_4 ) ;
if ( V_2 -> V_191 ) {
F_160 ( V_2 -> V_186 ) ;
V_2 -> V_191 = false ;
}
V_2 -> type -> V_192 ( V_2 ) ;
F_48 (channel, efx) {
if ( V_10 -> type -> V_190 ) {
V_35 = F_23 ( V_10 ) ;
if ( V_35 )
goto V_56;
}
}
V_35 = F_84 ( V_2 ) ;
if ( V_35 )
goto V_56;
return 0 ;
V_56:
V_188 = V_10 ;
F_48 (channel, efx) {
if ( V_10 == V_188 )
break;
if ( V_10 -> type -> V_190 )
F_31 ( V_10 ) ;
}
V_2 -> type -> V_193 ( V_2 ) ;
return V_35 ;
}
static void F_161 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_80 ( V_2 ) ;
F_48 (channel, efx) {
if ( V_10 -> type -> V_190 )
F_31 ( V_10 ) ;
}
V_2 -> type -> V_193 ( V_2 ) ;
}
static void F_162 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_48 (channel, efx)
V_10 -> V_183 = 0 ;
F_163 ( V_2 -> V_154 ) ;
F_164 ( V_2 -> V_154 ) ;
V_2 -> V_186 = 0 ;
}
static void F_165 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_41 * V_42 ;
V_2 -> V_60 =
V_177 ? V_2 -> V_102 - V_2 -> V_181 : 0 ;
F_48 (channel, efx) {
if ( V_10 -> V_10 < V_2 -> V_182 )
V_10 -> V_15 . V_194 = V_10 -> V_10 ;
else
V_10 -> V_15 . V_194 = - 1 ;
F_41 (tx_queue, channel)
V_42 -> V_47 -= ( V_2 -> V_60 *
V_46 ) ;
}
}
static int F_166 ( struct V_1 * V_2 )
{
T_1 V_39 ;
int V_35 ;
F_18 ( V_2 , V_29 , V_2 -> V_7 , L_54 ) ;
V_35 = V_2 -> type -> V_29 ( V_2 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_149 ( V_2 ) ;
if ( V_35 )
goto V_138;
F_165 ( V_2 ) ;
V_35 = V_2 -> type -> V_195 ( V_2 ) ;
if ( V_35 )
goto V_141;
if ( V_2 -> V_102 > 1 )
F_167 ( & V_2 -> V_196 , sizeof( V_2 -> V_196 ) ) ;
for ( V_39 = 0 ; V_39 < F_168 ( V_2 -> V_197 ) ; V_39 ++ )
V_2 -> V_197 [ V_39 ] =
F_169 ( V_39 , V_2 -> V_187 ) ;
F_170 ( V_2 -> V_7 , V_2 -> V_181 ) ;
F_171 ( V_2 -> V_7 , V_2 -> V_182 ) ;
F_172 ( V_2 , V_198 , V_199 , true ,
true ) ;
return 0 ;
V_141:
F_162 ( V_2 ) ;
V_138:
V_2 -> type -> remove ( V_2 ) ;
return V_35 ;
}
static void F_173 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_55 ) ;
F_162 ( V_2 ) ;
V_2 -> type -> remove ( V_2 ) ;
}
static int F_174 ( struct V_1 * V_2 )
{
int V_35 ;
F_175 ( & V_2 -> V_200 ) ;
V_35 = V_2 -> type -> V_201 ( V_2 ) ;
if ( V_35 )
return V_35 ;
#ifdef F_176
if ( V_2 -> type -> V_202 & V_203 ) {
V_2 -> V_204 = F_177 ( V_2 -> type -> V_205 ,
sizeof( * V_2 -> V_204 ) ,
V_44 ) ;
if ( ! V_2 -> V_204 ) {
V_2 -> type -> V_206 ( V_2 ) ;
return - V_103 ;
}
}
#endif
return 0 ;
}
static void F_178 ( struct V_1 * V_2 )
{
#ifdef F_176
F_83 ( V_2 -> V_204 ) ;
#endif
V_2 -> type -> V_206 ( V_2 ) ;
}
static void F_179 ( struct V_1 * V_2 )
{
V_2 -> type -> V_207 ( V_2 ) ;
}
static int F_180 ( struct V_1 * V_2 )
{
int V_35 ;
V_35 = F_166 ( V_2 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 , L_56 ) ;
goto V_138;
}
V_35 = F_107 ( V_2 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 , L_57 ) ;
goto V_141;
}
F_54 ( V_208 < V_209 ) ;
if ( F_62 ( V_208 < F_181 ( V_2 ) ) ) {
V_35 = - V_210 ;
goto V_163;
}
V_2 -> V_30 = V_2 -> V_31 = V_208 ;
V_35 = F_174 ( V_2 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_58 ) ;
goto V_163;
}
V_35 = F_49 ( V_2 ) ;
if ( V_35 )
goto V_165;
return 0 ;
V_165:
F_178 ( V_2 ) ;
V_163:
F_118 ( V_2 ) ;
V_141:
F_173 ( V_2 ) ;
V_138:
return V_35 ;
}
static void F_85 ( struct V_1 * V_2 )
{
F_67 ( V_2 ) ;
F_68 ( V_2 -> V_3 == V_4 ) ;
if ( V_2 -> V_90 || ! F_93 ( V_2 -> V_7 ) ||
V_2 -> V_211 )
return;
F_110 ( V_2 ) ;
F_52 ( V_2 ) ;
if ( V_2 -> type -> V_212 != NULL )
F_182 ( V_2 -> V_213 , & V_2 -> V_144 ,
V_214 ) ;
if ( F_183 ( V_2 ) >= V_215 ) {
F_104 ( & V_2 -> V_124 ) ;
if ( V_2 -> V_136 -> V_216 ( V_2 ) )
F_92 ( V_2 ) ;
F_105 ( & V_2 -> V_124 ) ;
}
V_2 -> type -> V_217 ( V_2 ) ;
V_2 -> type -> V_218 ( V_2 ) ;
F_184 ( & V_2 -> V_219 ) ;
V_2 -> type -> V_220 ( V_2 , NULL , NULL ) ;
F_185 ( & V_2 -> V_219 ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
F_67 ( V_2 ) ;
if ( ! V_2 -> V_90 )
return;
V_2 -> type -> V_218 ( V_2 ) ;
F_184 ( & V_2 -> V_219 ) ;
V_2 -> type -> V_220 ( V_2 , NULL , NULL ) ;
F_185 ( & V_2 -> V_219 ) ;
V_2 -> type -> V_221 ( V_2 ) ;
F_111 ( V_2 ) ;
F_62 ( F_93 ( V_2 -> V_7 ) &&
F_64 ( V_2 -> V_7 ) ) ;
F_186 ( V_2 -> V_7 ) ;
F_66 ( V_2 ) ;
}
static void F_187 ( struct V_1 * V_2 )
{
F_51 ( V_2 ) ;
F_178 ( V_2 ) ;
F_118 ( V_2 ) ;
F_173 ( V_2 ) ;
}
static unsigned int F_188 ( unsigned int V_222 , unsigned int V_223 )
{
if ( V_222 == 0 )
return 0 ;
if ( V_222 * 1000 < V_223 )
return 1 ;
return V_222 * 1000 / V_223 ;
}
int F_172 ( struct V_1 * V_2 , unsigned int V_224 ,
unsigned int V_225 , bool V_226 ,
bool V_227 )
{
struct V_9 * V_10 ;
unsigned int V_228 = F_189 ( V_2 -> type -> V_229 *
V_2 -> V_230 ,
1000 ) ;
unsigned int V_231 ;
unsigned int V_232 ;
F_67 ( V_2 ) ;
if ( V_224 > V_228 || V_225 > V_228 )
return - V_210 ;
V_231 = F_188 ( V_224 , V_2 -> V_230 ) ;
V_232 = F_188 ( V_225 , V_2 -> V_230 ) ;
if ( V_231 != V_232 && V_2 -> V_60 == 0 &&
! V_227 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_59
L_60 ) ;
return - V_210 ;
}
V_2 -> V_20 = V_226 ;
V_2 -> V_27 = V_232 ;
F_48 (channel, efx) {
if ( F_6 ( V_10 ) )
V_10 -> V_24 = V_232 ;
else if ( F_190 ( V_10 ) )
V_10 -> V_24 = V_231 ;
}
return 0 ;
}
void F_191 ( struct V_1 * V_2 , unsigned int * V_224 ,
unsigned int * V_225 , bool * V_226 )
{
* V_226 = V_2 -> V_20 ;
* V_225 = F_189 ( V_2 -> V_27 *
V_2 -> V_230 ,
1000 ) ;
if ( V_2 -> V_60 == 0 )
* V_224 = * V_225 ;
else
* V_224 = F_189 (
V_2 -> V_10 [ V_2 -> V_60 ] -> V_24 *
V_2 -> V_230 ,
1000 ) ;
}
static void F_192 ( struct V_127 * V_128 )
{
struct V_1 * V_2 = F_11 ( V_128 , struct V_1 ,
V_144 . V_233 ) ;
F_12 ( V_2 , V_234 , V_2 -> V_7 ,
L_61 ,
F_13 () ) ;
F_68 ( V_2 -> type -> V_212 == NULL ) ;
if ( F_193 ( & V_2 -> V_124 ) ) {
if ( V_2 -> V_90 )
V_2 -> type -> V_212 ( V_2 ) ;
F_105 ( & V_2 -> V_124 ) ;
}
F_182 ( V_2 -> V_213 , & V_2 -> V_144 ,
V_214 ) ;
}
static int F_194 ( struct V_235 * V_7 , struct V_236 * V_237 , int V_238 )
{
struct V_1 * V_2 = F_195 ( V_7 ) ;
struct V_239 * V_128 = F_196 ( V_237 ) ;
if ( V_238 == V_240 )
return F_197 ( V_2 , V_237 ) ;
if ( V_238 == V_241 )
return F_198 ( V_2 , V_237 ) ;
if ( ( V_238 == V_242 || V_238 == V_243 ) &&
( V_128 -> V_244 & 0xfc00 ) == 0x0400 )
V_128 -> V_244 ^= V_245 | 0x0400 ;
return F_199 ( & V_2 -> V_246 , V_128 , V_238 ) ;
}
static void F_81 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
V_10 -> V_50 = V_2 -> V_7 ;
F_200 ( V_10 -> V_50 , & V_10 -> V_18 ,
F_10 , V_247 ) ;
}
static void F_201 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_48 (channel, efx)
F_81 ( V_10 ) ;
}
static void F_82 ( struct V_9 * V_10 )
{
if ( V_10 -> V_50 )
F_202 ( & V_10 -> V_18 ) ;
V_10 -> V_50 = NULL ;
}
static void F_203 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_48 (channel, efx)
F_82 ( V_10 ) ;
}
static void F_204 ( struct V_235 * V_7 )
{
struct V_1 * V_2 = F_195 ( V_7 ) ;
struct V_9 * V_10 ;
F_48 (channel, efx)
F_205 ( V_10 ) ;
}
static int F_206 ( struct V_235 * V_7 )
{
struct V_1 * V_2 = F_195 ( V_7 ) ;
int V_35 ;
F_18 ( V_2 , V_38 , V_2 -> V_7 , L_62 ,
F_13 () ) ;
V_35 = F_1 ( V_2 ) ;
if ( V_35 )
return V_35 ;
if ( V_2 -> V_123 & V_132 )
return - V_248 ;
if ( F_207 ( V_2 ) && F_208 ( V_2 , V_93 ) )
return - V_8 ;
F_92 ( V_2 ) ;
F_85 ( V_2 ) ;
F_209 ( V_2 ) ;
return 0 ;
}
static int F_210 ( struct V_235 * V_7 )
{
struct V_1 * V_2 = F_195 ( V_7 ) ;
F_18 ( V_2 , V_143 , V_2 -> V_7 , L_63 ,
F_13 () ) ;
F_79 ( V_2 ) ;
return 0 ;
}
static struct V_249 * F_211 ( struct V_235 * V_7 ,
struct V_249 * V_250 )
{
struct V_1 * V_2 = F_195 ( V_7 ) ;
F_184 ( & V_2 -> V_219 ) ;
V_2 -> type -> V_220 ( V_2 , NULL , V_250 ) ;
F_185 ( & V_2 -> V_219 ) ;
return V_250 ;
}
static void F_212 ( struct V_235 * V_7 )
{
struct V_1 * V_2 = F_195 ( V_7 ) ;
F_2 ( V_2 , V_251 , V_2 -> V_7 ,
L_64 ,
V_2 -> V_90 ) ;
F_71 ( V_2 , V_252 ) ;
}
static int F_213 ( struct V_235 * V_7 , int V_253 )
{
struct V_1 * V_2 = F_195 ( V_7 ) ;
int V_35 ;
V_35 = F_1 ( V_2 ) ;
if ( V_35 )
return V_35 ;
if ( V_253 > V_254 )
return - V_210 ;
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_65 , V_253 ) ;
F_78 ( V_2 ) ;
F_79 ( V_2 ) ;
F_104 ( & V_2 -> V_124 ) ;
V_7 -> V_70 = V_253 ;
V_2 -> type -> V_130 ( V_2 ) ;
F_105 ( & V_2 -> V_124 ) ;
F_85 ( V_2 ) ;
F_86 ( V_2 -> V_7 ) ;
return 0 ;
}
static int F_214 ( struct V_235 * V_7 , void * V_128 )
{
struct V_1 * V_2 = F_195 ( V_7 ) ;
struct V_255 * V_256 = V_128 ;
T_3 * V_257 = V_256 -> V_258 ;
if ( ! F_215 ( V_257 ) ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_66 ,
V_257 ) ;
return - V_259 ;
}
F_108 ( V_7 -> V_134 , V_257 ) ;
F_216 ( V_2 ) ;
F_104 ( & V_2 -> V_124 ) ;
V_2 -> type -> V_130 ( V_2 ) ;
F_105 ( & V_2 -> V_124 ) ;
return 0 ;
}
static void F_217 ( struct V_235 * V_7 )
{
struct V_1 * V_2 = F_195 ( V_7 ) ;
if ( V_2 -> V_90 )
F_218 ( V_2 -> V_213 , & V_2 -> V_129 ) ;
}
static int F_219 ( struct V_235 * V_7 , T_6 V_128 )
{
struct V_1 * V_2 = F_195 ( V_7 ) ;
if ( V_7 -> V_260 & ~ V_128 & V_203 )
return V_2 -> type -> V_261 ( V_2 , V_262 ) ;
return 0 ;
}
static void F_220 ( struct V_1 * V_2 )
{
strcpy ( V_2 -> V_61 , V_2 -> V_7 -> V_61 ) ;
F_221 ( V_2 ) ;
F_47 ( V_2 ) ;
}
static int F_222 ( struct V_263 * V_264 ,
unsigned long V_265 , void * V_266 )
{
struct V_235 * V_7 = F_223 ( V_266 ) ;
if ( ( V_7 -> V_267 == & V_268 ||
V_7 -> V_267 == & V_269 ) &&
V_265 == V_270 )
F_220 ( F_195 ( V_7 ) ) ;
return V_271 ;
}
static T_7
F_224 ( struct V_272 * V_160 , struct V_273 * V_274 , char * V_57 )
{
struct V_1 * V_2 = F_225 ( F_226 ( V_160 ) ) ;
return sprintf ( V_57 , L_67 , V_2 -> V_275 ) ;
}
static int F_227 ( struct V_1 * V_2 )
{
struct V_235 * V_7 = V_2 -> V_7 ;
struct V_9 * V_10 ;
int V_35 ;
V_7 -> V_276 = 5 * V_277 ;
V_7 -> V_183 = V_2 -> V_154 -> V_183 ;
if ( F_183 ( V_2 ) >= V_278 ) {
V_7 -> V_267 = & V_269 ;
V_7 -> V_279 |= V_280 ;
} else {
V_7 -> V_267 = & V_268 ;
}
F_228 ( V_7 , & V_281 ) ;
V_7 -> V_282 = V_283 ;
F_229 () ;
V_2 -> V_3 = V_284 ;
F_230 () ;
if ( V_2 -> V_211 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_68 ) ;
V_35 = - V_8 ;
goto V_285;
}
V_35 = F_231 ( V_7 , V_7 -> V_61 ) ;
if ( V_35 < 0 )
goto V_285;
F_220 ( V_2 ) ;
F_96 ( V_7 ) ;
V_35 = F_232 ( V_7 ) ;
if ( V_35 )
goto V_285;
F_48 (channel, efx) {
struct V_41 * V_42 ;
F_41 (tx_queue, channel)
F_233 ( V_42 ) ;
}
F_120 ( V_2 ) ;
F_234 () ;
V_35 = F_235 ( & V_2 -> V_154 -> V_160 , & V_286 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_69 ) ;
goto V_287;
}
return 0 ;
V_287:
F_229 () ;
F_126 ( V_2 ) ;
F_236 ( V_7 ) ;
V_285:
V_2 -> V_3 = V_288 ;
F_234 () ;
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_70 ) ;
return V_35 ;
}
static void F_237 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_7 )
return;
F_68 ( F_195 ( V_2 -> V_7 ) != V_2 ) ;
F_238 ( V_2 -> V_61 , F_124 ( V_2 -> V_154 ) , sizeof( V_2 -> V_61 ) ) ;
F_239 ( & V_2 -> V_154 -> V_160 , & V_286 ) ;
F_229 () ;
F_236 ( V_2 -> V_7 ) ;
V_2 -> V_3 = V_288 ;
F_234 () ;
}
void F_240 ( struct V_1 * V_2 , enum V_289 V_290 )
{
F_67 ( V_2 ) ;
if ( V_290 == V_291 )
V_2 -> type -> V_292 ( V_2 ) ;
F_79 ( V_2 ) ;
F_161 ( V_2 ) ;
F_104 ( & V_2 -> V_124 ) ;
if ( V_2 -> V_139 && V_290 != V_293 )
V_2 -> V_136 -> V_142 ( V_2 ) ;
V_2 -> type -> V_142 ( V_2 ) ;
}
int F_241 ( struct V_1 * V_2 , enum V_289 V_290 , bool V_294 )
{
int V_35 ;
F_67 ( V_2 ) ;
if ( V_290 == V_291 )
V_2 -> type -> V_295 ( V_2 ) ;
V_35 = V_2 -> type -> V_137 ( V_2 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_71 ) ;
goto V_56;
}
if ( ! V_294 )
goto V_56;
if ( V_2 -> V_139 && V_290 != V_293 ) {
V_35 = V_2 -> V_136 -> V_137 ( V_2 ) ;
if ( V_35 )
goto V_56;
if ( V_2 -> V_136 -> V_140 ( V_2 ) )
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_72 ) ;
}
V_35 = F_159 ( V_2 ) ;
if ( V_35 )
goto V_56;
F_179 ( V_2 ) ;
F_242 ( V_2 ) ;
F_105 ( & V_2 -> V_124 ) ;
F_85 ( V_2 ) ;
return 0 ;
V_56:
V_2 -> V_139 = false ;
F_105 ( & V_2 -> V_124 ) ;
return V_35 ;
}
int F_208 ( struct V_1 * V_2 , enum V_289 V_290 )
{
int V_35 , V_99 ;
bool V_296 ;
F_97 ( V_2 , V_6 , V_2 -> V_7 , L_73 ,
F_243 ( V_290 ) ) ;
F_78 ( V_2 ) ;
F_240 ( V_2 , V_290 ) ;
V_35 = V_2 -> type -> V_297 ( V_2 , V_290 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_74 ) ;
goto V_104;
}
if ( V_290 < V_298 )
V_2 -> V_211 &= - ( 1 << ( V_290 + 1 ) ) ;
else
F_244 ( V_290 , & V_2 -> V_211 ) ;
F_129 ( V_2 -> V_154 ) ;
V_104:
V_296 = V_35 ||
V_290 == V_106 ||
V_290 == V_299 ;
V_99 = F_241 ( V_2 , V_290 , ! V_296 ) ;
if ( V_99 ) {
V_296 = true ;
if ( ! V_35 )
V_35 = V_99 ;
}
if ( V_296 ) {
F_245 ( V_2 -> V_7 ) ;
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_75 ) ;
V_2 -> V_3 = V_4 ;
} else {
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_76 ) ;
F_86 ( V_2 -> V_7 ) ;
}
return V_35 ;
}
int F_246 ( struct V_1 * V_2 )
{
#ifdef F_247
struct V_300 * V_301 =
F_248 ( F_249 ( V_2 -> V_154 ) ) ;
if ( F_250 ( V_301 ) ) {
return 1 ;
}
#endif
return 0 ;
}
static void F_251 ( struct V_1 * V_2 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_302 ; ++ V_39 ) {
if ( F_207 ( V_2 ) )
goto V_104;
F_252 ( V_303 ) ;
}
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_77 ) ;
V_104:
V_2 -> V_304 = false ;
}
static void F_253 ( struct V_127 * V_128 )
{
struct V_1 * V_2 = F_11 ( V_128 , struct V_1 , V_305 ) ;
unsigned long V_306 ;
enum V_289 V_290 ;
V_306 = F_254 ( V_2 -> V_211 ) ;
V_290 = F_255 ( V_306 ) - 1 ;
if ( V_290 == V_307 )
F_251 ( V_2 ) ;
if ( ( V_290 == V_299 ||
V_290 == V_308 ) &&
F_246 ( V_2 ) )
return;
if ( ! V_306 )
return;
F_229 () ;
if ( V_2 -> V_3 == V_284 )
( void ) F_208 ( V_2 , V_290 ) ;
F_234 () ;
}
void F_71 ( struct V_1 * V_2 , enum V_289 type )
{
enum V_289 V_290 ;
if ( V_2 -> V_3 == V_5 ) {
F_18 ( V_2 , V_6 , V_2 -> V_7 ,
L_78 ,
F_243 ( type ) ) ;
return;
}
switch ( type ) {
case V_293 :
case V_93 :
case V_308 :
case V_309 :
case V_106 :
case V_299 :
case V_307 :
case V_291 :
V_290 = type ;
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_79 ,
F_243 ( V_290 ) ) ;
break;
default:
V_290 = V_2 -> type -> V_310 ( type ) ;
F_18 ( V_2 , V_6 , V_2 -> V_7 ,
L_80 ,
F_243 ( V_290 ) , F_243 ( type ) ) ;
break;
}
F_256 ( V_290 , & V_2 -> V_211 ) ;
F_230 () ;
if ( F_254 ( V_2 -> V_3 ) != V_284 )
return;
F_156 ( V_2 ) ;
F_218 ( V_311 , & V_2 -> V_305 ) ;
}
int F_257 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_258 ( struct V_1 * V_2 ) {}
static bool F_259 ( struct V_1 * V_2 )
{
return false ;
}
static int F_260 ( struct V_1 * V_2 ,
struct V_154 * V_154 , struct V_235 * V_7 )
{
int V_39 ;
F_261 ( & V_2 -> V_152 ) ;
F_261 ( & V_2 -> V_155 ) ;
F_175 ( & V_2 -> V_312 ) ;
#ifdef F_262
F_261 ( & V_2 -> V_313 ) ;
#endif
F_263 ( & V_2 -> V_305 , F_253 ) ;
F_264 ( & V_2 -> V_144 , F_192 ) ;
F_264 ( & V_2 -> V_314 , V_315 ) ;
V_2 -> V_154 = V_154 ;
V_2 -> V_316 = V_317 ;
V_2 -> V_3 = V_288 ;
F_238 ( V_2 -> V_61 , F_124 ( V_154 ) , sizeof( V_2 -> V_61 ) ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_69 = V_2 -> type -> V_69 ;
V_2 -> V_73 =
V_80 ? ( V_2 -> V_69 + V_80 ) % 4 : 0 ;
V_2 -> V_318 =
V_2 -> type -> V_319 - V_2 -> type -> V_69 ;
V_2 -> V_320 =
V_2 -> type -> V_321 - V_2 -> type -> V_69 ;
F_175 ( & V_2 -> V_219 ) ;
F_265 ( & V_2 -> V_124 ) ;
V_2 -> V_136 = & V_322 ;
V_2 -> V_246 . V_160 = V_7 ;
F_263 ( & V_2 -> V_129 , F_106 ) ;
F_266 ( & V_2 -> V_323 ) ;
for ( V_39 = 0 ; V_39 < V_96 ; V_39 ++ ) {
V_2 -> V_10 [ V_39 ] = F_35 ( V_2 , V_39 , NULL ) ;
if ( ! V_2 -> V_10 [ V_39 ] )
goto V_56;
V_2 -> V_63 [ V_39 ] . V_2 = V_2 ;
V_2 -> V_63 [ V_39 ] . V_101 = V_39 ;
}
V_2 -> V_173 = F_21 ( V_2 -> type -> V_324 ,
V_173 ) ;
snprintf ( V_2 -> V_325 , sizeof( V_2 -> V_325 ) , L_81 ,
F_124 ( V_154 ) ) ;
V_2 -> V_213 = F_267 ( V_2 -> V_325 ) ;
if ( ! V_2 -> V_213 )
goto V_56;
return 0 ;
V_56:
F_268 ( V_2 ) ;
return - V_103 ;
}
static void F_268 ( struct V_1 * V_2 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_96 ; V_39 ++ )
F_83 ( V_2 -> V_10 [ V_39 ] ) ;
F_83 ( V_2 -> V_148 ) ;
if ( V_2 -> V_213 ) {
F_269 ( V_2 -> V_213 ) ;
V_2 -> V_213 = NULL ;
}
}
static void F_270 ( struct V_1 * V_2 )
{
F_68 ( V_2 -> V_3 == V_284 ) ;
F_116 ( & V_2 -> V_305 ) ;
F_161 ( V_2 ) ;
F_271 ( V_2 ) ;
F_117 ( V_2 ) ;
V_2 -> type -> V_142 ( V_2 ) ;
F_203 ( V_2 ) ;
F_187 ( V_2 ) ;
}
static void F_272 ( struct V_154 * V_154 )
{
struct V_1 * V_2 ;
V_2 = F_225 ( V_154 ) ;
if ( ! V_2 )
return;
F_229 () ;
F_126 ( V_2 ) ;
F_245 ( V_2 -> V_7 ) ;
F_161 ( V_2 ) ;
F_234 () ;
F_273 ( V_2 ) ;
F_237 ( V_2 ) ;
F_274 ( V_2 ) ;
F_270 ( V_2 ) ;
F_137 ( V_2 ) ;
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_82 ) ;
F_268 ( V_2 ) ;
F_275 ( V_2 -> V_7 ) ;
F_276 ( V_154 ) ;
}
static void F_277 ( struct V_1 * V_2 )
{
struct V_154 * V_160 = V_2 -> V_154 ;
char V_326 [ V_327 ] ;
T_7 V_328 ;
int V_329 , V_330 , V_39 , V_43 ;
V_328 = F_278 ( V_160 , 0 , sizeof( V_326 ) , V_326 ) ;
if ( V_328 <= 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_83 ) ;
return;
}
V_329 = F_279 ( V_326 , 0 , V_328 , V_331 ) ;
if ( V_329 < 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_84 ) ;
return;
}
V_330 = F_280 ( & V_326 [ V_329 ] ) ;
V_43 = V_330 ;
V_39 = V_329 + V_332 ;
if ( V_39 + V_43 > V_328 )
V_43 = V_328 - V_39 ;
V_39 = F_281 ( V_326 , V_39 , V_43 , L_85 ) ;
if ( V_39 < 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_86 ) ;
return;
}
V_43 = F_282 ( & V_326 [ V_39 ] ) ;
V_39 += V_333 ;
if ( V_39 + V_43 > V_328 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_87 ) ;
return;
}
F_97 ( V_2 , V_6 , V_2 -> V_7 ,
L_88 , V_43 , & V_326 [ V_39 ] ) ;
V_39 = V_329 + V_332 ;
V_43 = V_330 ;
V_39 = F_281 ( V_326 , V_39 , V_43 , L_89 ) ;
if ( V_39 < 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_90 ) ;
return;
}
V_43 = F_282 ( & V_326 [ V_39 ] ) ;
V_39 += V_333 ;
if ( V_39 + V_43 > V_328 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_91 ) ;
return;
}
V_2 -> V_148 = F_39 ( V_43 + 1 , V_44 ) ;
if ( ! V_2 -> V_148 )
return;
snprintf ( V_2 -> V_148 , V_43 + 1 , L_92 , & V_326 [ V_39 ] ) ;
}
static int F_283 ( struct V_1 * V_2 )
{
int V_35 ;
V_35 = F_180 ( V_2 ) ;
if ( V_35 )
goto V_138;
F_201 ( V_2 ) ;
V_35 = V_2 -> type -> V_137 ( V_2 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_71 ) ;
goto V_163;
}
V_35 = F_109 ( V_2 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_93 ) ;
goto V_165;
}
V_35 = F_284 ( V_2 ) ;
if ( V_35 )
goto V_334;
V_35 = F_159 ( V_2 ) ;
if ( V_35 )
goto V_335;
return 0 ;
V_335:
F_271 ( V_2 ) ;
V_334:
F_117 ( V_2 ) ;
V_165:
V_2 -> type -> V_142 ( V_2 ) ;
V_163:
F_203 ( V_2 ) ;
F_187 ( V_2 ) ;
V_138:
return V_35 ;
}
static int F_285 ( struct V_154 * V_154 ,
const struct V_336 * V_179 )
{
struct V_235 * V_7 ;
struct V_1 * V_2 ;
int V_35 ;
V_7 = F_286 ( sizeof( * V_2 ) , V_337 ,
V_338 ) ;
if ( ! V_7 )
return - V_103 ;
V_2 = F_195 ( V_7 ) ;
V_2 -> type = ( const struct V_339 * ) V_179 -> V_340 ;
V_7 -> V_260 |= ( V_2 -> type -> V_202 | V_341 |
V_342 | V_343 |
V_344 ) ;
if ( V_2 -> type -> V_202 & V_345 )
V_7 -> V_260 |= V_346 ;
V_7 -> V_347 |= ( V_348 | V_341 |
V_342 | V_349 |
V_344 ) ;
V_7 -> V_350 = V_7 -> V_260 & ~ V_342 ;
F_287 ( V_154 , V_2 ) ;
F_288 ( V_7 , & V_154 -> V_160 ) ;
V_35 = F_260 ( V_2 , V_154 , V_7 ) ;
if ( V_35 )
goto V_138;
F_97 ( V_2 , V_29 , V_2 -> V_7 ,
L_94 ) ;
F_277 ( V_2 ) ;
V_35 = F_127 ( V_2 ) ;
if ( V_35 )
goto V_141;
V_35 = F_283 ( V_2 ) ;
if ( V_35 )
goto V_163;
V_35 = F_227 ( V_2 ) ;
if ( V_35 )
goto V_165;
V_35 = F_289 ( V_2 ) ;
if ( V_35 )
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_95 , V_35 ) ;
F_18 ( V_2 , V_29 , V_2 -> V_7 , L_96 ) ;
F_229 () ;
V_35 = F_290 ( V_2 ) ;
F_234 () ;
if ( V_35 )
F_141 ( V_2 , V_29 , V_2 -> V_7 ,
L_97 , V_35 ) ;
V_35 = F_291 ( V_154 ) ;
if ( V_35 && V_35 != - V_210 )
F_141 ( V_2 , V_29 , V_2 -> V_7 ,
L_98 , V_35 ) ;
return 0 ;
V_165:
F_270 ( V_2 ) ;
V_163:
F_137 ( V_2 ) ;
V_141:
F_268 ( V_2 ) ;
V_138:
F_62 ( V_35 > 0 ) ;
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_99 , V_35 ) ;
F_275 ( V_7 ) ;
return V_35 ;
}
static int F_292 ( struct V_272 * V_160 )
{
struct V_1 * V_2 = F_225 ( F_226 ( V_160 ) ) ;
F_229 () ;
if ( V_2 -> V_3 != V_4 ) {
V_2 -> V_3 = V_288 ;
F_78 ( V_2 ) ;
F_79 ( V_2 ) ;
F_161 ( V_2 ) ;
}
F_234 () ;
return 0 ;
}
static int F_293 ( struct V_272 * V_160 )
{
int V_35 ;
struct V_1 * V_2 = F_225 ( F_226 ( V_160 ) ) ;
F_229 () ;
if ( V_2 -> V_3 != V_4 ) {
V_35 = F_159 ( V_2 ) ;
if ( V_35 )
goto V_56;
F_104 ( & V_2 -> V_124 ) ;
V_2 -> V_136 -> V_140 ( V_2 ) ;
F_105 ( & V_2 -> V_124 ) ;
F_85 ( V_2 ) ;
F_86 ( V_2 -> V_7 ) ;
V_2 -> V_3 = V_284 ;
V_2 -> type -> V_351 ( V_2 ) ;
}
F_234 () ;
F_218 ( V_311 , & V_2 -> V_305 ) ;
return 0 ;
V_56:
F_234 () ;
return V_35 ;
}
static int F_294 ( struct V_272 * V_160 )
{
struct V_154 * V_154 = F_226 ( V_160 ) ;
struct V_1 * V_2 = F_225 ( V_154 ) ;
V_2 -> type -> V_142 ( V_2 ) ;
V_2 -> V_211 = 0 ;
F_295 ( V_154 ) ;
return F_296 ( V_154 , V_352 ) ;
}
static int F_297 ( struct V_272 * V_160 )
{
struct V_154 * V_154 = F_226 ( V_160 ) ;
struct V_1 * V_2 = F_225 ( V_154 ) ;
int V_35 ;
V_35 = F_296 ( V_154 , V_353 ) ;
if ( V_35 )
return V_35 ;
F_298 ( V_154 ) ;
V_35 = F_128 ( V_154 ) ;
if ( V_35 )
return V_35 ;
F_129 ( V_2 -> V_154 ) ;
V_35 = V_2 -> type -> V_297 ( V_2 , V_93 ) ;
if ( V_35 )
return V_35 ;
V_35 = V_2 -> type -> V_137 ( V_2 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_293 ( V_160 ) ;
return V_35 ;
}
static int F_299 ( struct V_272 * V_160 )
{
int V_35 ;
F_292 ( V_160 ) ;
V_35 = F_294 ( V_160 ) ;
if ( V_35 )
F_297 ( V_160 ) ;
return V_35 ;
}
static T_8 F_300 ( struct V_154 * V_354 ,
enum V_355 V_3 )
{
T_8 V_356 = V_357 ;
struct V_1 * V_2 = F_225 ( V_354 ) ;
if ( V_3 == V_358 )
return V_359 ;
F_229 () ;
if ( V_2 -> V_3 != V_4 ) {
V_2 -> V_3 = V_5 ;
V_2 -> V_211 = 0 ;
F_78 ( V_2 ) ;
F_79 ( V_2 ) ;
F_161 ( V_2 ) ;
V_356 = V_360 ;
} else {
V_356 = V_357 ;
}
F_234 () ;
F_136 ( V_354 ) ;
return V_356 ;
}
static T_8 F_301 ( struct V_154 * V_354 )
{
struct V_1 * V_2 = F_225 ( V_354 ) ;
T_8 V_356 = V_357 ;
int V_35 ;
if ( F_128 ( V_354 ) ) {
F_2 ( V_2 , V_361 , V_2 -> V_7 ,
L_100 ) ;
V_356 = V_359 ;
}
V_35 = F_302 ( V_354 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_361 , V_2 -> V_7 ,
L_101 , V_35 ) ;
}
return V_356 ;
}
static void F_303 ( struct V_154 * V_354 )
{
struct V_1 * V_2 = F_225 ( V_354 ) ;
int V_35 ;
F_229 () ;
if ( V_2 -> V_3 == V_4 )
goto V_104;
V_35 = F_208 ( V_2 , V_93 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_361 , V_2 -> V_7 ,
L_102 , V_35 ) ;
} else {
V_2 -> V_3 = V_284 ;
F_18 ( V_2 , V_361 , V_2 -> V_7 ,
L_103 ) ;
}
V_104:
F_234 () ;
}
static int T_9 F_304 ( void )
{
int V_35 ;
F_305 ( V_362 L_104 V_363 L_105 ) ;
V_35 = F_306 ( & V_364 ) ;
if ( V_35 )
goto V_365;
V_35 = F_307 () ;
if ( V_35 )
goto V_366;
V_311 = F_267 ( L_106 ) ;
if ( ! V_311 ) {
V_35 = - V_103 ;
goto V_367;
}
V_35 = F_308 ( & V_368 ) ;
if ( V_35 < 0 )
goto V_369;
return 0 ;
V_369:
F_269 ( V_311 ) ;
V_367:
F_309 () ;
V_366:
F_310 ( & V_364 ) ;
V_365:
return V_35 ;
}
static void T_10 F_311 ( void )
{
F_305 ( V_362 L_107 ) ;
F_312 ( & V_368 ) ;
F_269 ( V_311 ) ;
F_309 () ;
F_310 ( & V_364 ) ;
}

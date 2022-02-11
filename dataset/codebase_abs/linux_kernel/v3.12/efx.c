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
F_9 ( V_15 ) ;
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
V_10 -> V_57 = 0 ;
return 0 ;
V_56:
F_45 ( V_10 ) ;
return V_35 ;
}
static void
F_46 ( struct V_9 * V_10 , char * V_58 , T_1 V_59 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
const char * type ;
int V_60 ;
V_60 = V_10 -> V_10 ;
if ( V_2 -> V_61 == 0 ) {
type = L_9 ;
} else if ( V_10 -> V_10 < V_2 -> V_61 ) {
type = L_10 ;
} else {
type = L_11 ;
V_60 -= V_2 -> V_61 ;
}
snprintf ( V_58 , V_59 , L_12 , V_2 -> V_62 , type , V_60 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_48 (channel, efx)
V_10 -> type -> V_63 ( V_10 ,
V_2 -> V_64 [ V_10 -> V_10 ] . V_62 ,
sizeof( V_2 -> V_64 [ 0 ] . V_62 ) ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
int V_35 ;
V_2 -> V_65 = 0 ;
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
bool V_66 = V_2 -> V_67 ;
struct V_41 * V_42 ;
struct V_14 * V_15 ;
struct V_9 * V_10 ;
T_1 V_68 ;
V_2 -> V_69 = ( V_2 -> V_70 +
F_53 ( V_2 -> V_7 -> V_71 ) +
V_2 -> type -> V_72 ) ;
V_68 = ( sizeof( struct V_73 ) +
V_74 + V_2 -> V_69 ) ;
if ( V_68 <= V_75 ) {
V_2 -> V_67 = V_2 -> type -> V_76 ;
V_2 -> V_77 = 0 ;
} else if ( V_2 -> type -> V_78 ) {
F_54 ( V_79 % V_80 ) ;
F_54 ( sizeof( struct V_73 ) +
2 * F_55 ( V_74 + V_79 ,
V_81 ) >
V_75 ) ;
V_2 -> V_67 = true ;
V_2 -> V_69 = V_79 ;
V_2 -> V_77 = 0 ;
} else {
V_2 -> V_67 = false ;
V_2 -> V_77 = F_56 ( V_68 ) ;
}
F_57 ( V_2 ) ;
if ( V_2 -> V_77 )
F_18 ( V_2 , V_6 , V_2 -> V_7 ,
L_14 ,
V_2 -> V_69 , V_2 -> V_77 ,
V_2 -> V_82 ) ;
else
F_18 ( V_2 , V_6 , V_2 -> V_7 ,
L_15 ,
V_2 -> V_69 , V_2 -> V_83 ,
V_2 -> V_84 , V_2 -> V_82 ) ;
if ( V_2 -> V_67 != V_66 )
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
F_62 ( V_15 ) ;
}
F_63 ( V_10 -> V_89 ) ;
}
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
if ( V_35 && F_69 ( V_2 ) ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_16 ) ;
F_70 ( V_2 , V_93 ) ;
} else if ( V_35 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_17 ) ;
} else {
F_18 ( V_2 , V_6 , V_2 -> V_7 ,
L_18 ) ;
}
F_48 (channel, efx) {
F_43 (rx_queue, channel)
F_71 ( V_15 ) ;
F_72 (tx_queue, channel)
F_73 ( V_42 ) ;
}
}
static void F_45 ( struct V_9 * V_10 )
{
struct V_41 * V_42 ;
struct V_14 * V_15 ;
F_18 ( V_10 -> V_2 , V_6 , V_10 -> V_2 -> V_7 ,
L_19 , V_10 -> V_10 ) ;
F_43 (rx_queue, channel)
F_74 ( V_15 ) ;
F_72 (tx_queue, channel)
F_75 ( V_42 ) ;
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
F_76 ( struct V_1 * V_2 , T_2 V_30 , T_2 V_31 )
{
struct V_9 * V_95 [ V_96 ] , * V_10 ;
T_2 V_97 , V_98 ;
unsigned V_39 , V_65 = 0 ;
int V_35 , V_99 ;
V_35 = F_1 ( V_2 ) ;
if ( V_35 )
return V_35 ;
F_48 (channel, efx) {
struct V_14 * V_15 ;
struct V_41 * V_42 ;
if ( V_10 -> type -> V_100 )
continue;
V_65 = F_21 ( V_65 ,
V_10 -> V_51 . V_101 +
V_10 -> V_51 . V_28 ) ;
F_43 (rx_queue, channel)
V_65 = F_21 ( V_65 ,
V_15 -> V_54 . V_101 +
V_15 -> V_54 . V_28 ) ;
F_41 (tx_queue, channel)
V_65 = F_21 ( V_65 ,
V_42 -> V_53 . V_101 +
V_42 -> V_53 . V_28 ) ;
}
F_77 ( V_2 ) ;
F_78 ( V_2 ) ;
F_79 ( V_2 ) ;
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
V_2 -> V_65 = V_65 ;
for ( V_39 = 0 ; V_39 < V_2 -> V_102 ; V_39 ++ ) {
V_10 = V_2 -> V_10 [ V_39 ] ;
if ( ! V_10 -> type -> V_100 )
continue;
V_35 = F_40 ( V_10 ) ;
if ( V_35 )
goto V_105;
F_80 ( V_2 -> V_10 [ V_39 ] ) ;
}
V_104:
for ( V_39 = 0 ; V_39 < V_2 -> V_102 ; V_39 ++ ) {
V_10 = V_95 [ V_39 ] ;
if ( V_10 && V_10 -> type -> V_100 ) {
F_81 ( V_10 ) ;
F_45 ( V_10 ) ;
F_82 ( V_10 ) ;
}
}
V_99 = F_83 ( V_2 ) ;
if ( V_99 ) {
V_35 = V_35 ? V_35 : V_99 ;
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_20 ) ;
F_70 ( V_2 , V_106 ) ;
} else {
F_84 ( V_2 ) ;
F_85 ( V_2 -> V_7 ) ;
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
void F_86 ( struct V_14 * V_15 )
{
F_87 ( & V_15 -> V_48 , V_107 + F_88 ( 100 ) ) ;
}
int F_89 ( struct V_9 * V_10 )
{
return 0 ;
}
void F_90 ( struct V_9 * V_10 )
{
}
void F_91 ( struct V_1 * V_2 )
{
struct V_108 * V_109 = & V_2 -> V_109 ;
if ( ! F_92 ( V_2 -> V_7 ) )
return;
if ( V_109 -> V_110 != F_93 ( V_2 -> V_7 ) ) {
V_2 -> V_111 ++ ;
if ( V_109 -> V_110 )
F_94 ( V_2 -> V_7 ) ;
else
F_95 ( V_2 -> V_7 ) ;
}
if ( V_109 -> V_110 )
F_96 ( V_2 , V_112 , V_2 -> V_7 ,
L_21 ,
V_109 -> V_113 , V_109 -> V_114 ? L_22 : L_23 ,
V_2 -> V_7 -> V_71 ) ;
else
F_96 ( V_2 , V_112 , V_2 -> V_7 , L_24 ) ;
}
void F_97 ( struct V_1 * V_2 , T_2 V_115 )
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
void F_98 ( struct V_1 * V_2 , T_3 V_118 )
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
int F_99 ( struct V_1 * V_2 )
{
enum V_122 V_123 ;
int V_35 ;
F_63 ( ! F_100 ( & V_2 -> V_124 ) ) ;
V_123 = V_2 -> V_123 ;
if ( F_101 ( V_2 ) )
V_2 -> V_123 |= V_125 ;
else
V_2 -> V_123 &= ~ V_125 ;
V_35 = V_2 -> type -> V_126 ( V_2 ) ;
if ( V_35 )
V_2 -> V_123 = V_123 ;
return V_35 ;
}
int F_102 ( struct V_1 * V_2 )
{
int V_35 ;
F_67 ( V_2 ) ;
F_103 ( & V_2 -> V_124 ) ;
V_35 = F_99 ( V_2 ) ;
F_104 ( & V_2 -> V_124 ) ;
return V_35 ;
}
static void F_105 ( struct V_127 * V_128 )
{
struct V_1 * V_2 = F_11 ( V_128 , struct V_1 , V_129 ) ;
F_103 ( & V_2 -> V_124 ) ;
if ( V_2 -> V_90 )
V_2 -> type -> V_130 ( V_2 ) ;
F_104 ( & V_2 -> V_124 ) ;
}
static int F_106 ( struct V_1 * V_2 )
{
int V_35 ;
F_18 ( V_2 , V_29 , V_2 -> V_7 , L_25 ) ;
if ( V_131 )
V_2 -> V_123 = V_132 ;
V_35 = V_2 -> type -> V_133 ( V_2 ) ;
if ( V_35 )
return V_35 ;
memcpy ( V_2 -> V_7 -> V_134 , V_2 -> V_7 -> V_135 , V_136 ) ;
return 0 ;
}
static int F_107 ( struct V_1 * V_2 )
{
int V_35 ;
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_26 ) ;
F_103 ( & V_2 -> V_124 ) ;
V_35 = V_2 -> V_137 -> V_138 ( V_2 ) ;
if ( V_35 )
goto V_139;
V_2 -> V_140 = true ;
V_2 -> type -> V_130 ( V_2 ) ;
V_35 = V_2 -> V_137 -> V_141 ( V_2 ) ;
if ( V_35 )
goto V_142;
F_104 ( & V_2 -> V_124 ) ;
return 0 ;
V_142:
V_2 -> V_137 -> V_143 ( V_2 ) ;
V_139:
F_104 ( & V_2 -> V_124 ) ;
return V_35 ;
}
static void F_108 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_38 , V_2 -> V_7 , L_27 ) ;
F_68 ( V_2 -> V_90 ) ;
F_103 ( & V_2 -> V_124 ) ;
V_2 -> V_90 = true ;
V_2 -> type -> V_130 ( V_2 ) ;
F_104 ( & V_2 -> V_124 ) ;
}
static void F_109 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_144 , V_2 -> V_7 , L_28 ) ;
F_103 ( & V_2 -> V_124 ) ;
V_2 -> V_90 = false ;
F_104 ( & V_2 -> V_124 ) ;
F_110 ( V_2 -> V_7 ) ;
F_111 ( V_2 -> V_7 ) ;
}
static void F_112 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_29 ) ;
if ( ! V_2 -> V_140 )
return;
V_2 -> V_137 -> V_143 ( V_2 ) ;
V_2 -> V_140 = false ;
V_2 -> V_109 . V_110 = false ;
F_91 ( V_2 ) ;
}
static void F_113 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_30 ) ;
V_2 -> type -> V_145 ( V_2 ) ;
}
static int F_114 ( struct V_1 * V_2 )
{
struct V_146 * V_146 = V_2 -> V_146 ;
T_4 V_147 = V_2 -> type -> V_148 ;
unsigned int V_149 = V_2 -> type -> V_149 ( V_2 ) ;
int V_35 ;
F_18 ( V_2 , V_29 , V_2 -> V_7 , L_31 ) ;
V_35 = F_115 ( V_146 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_32 ) ;
goto V_139;
}
F_116 ( V_146 ) ;
while ( V_147 > 0x7fffffffUL ) {
if ( F_117 ( & V_146 -> V_150 , V_147 ) ) {
V_35 = F_118 ( & V_146 -> V_150 , V_147 ) ;
if ( V_35 == 0 )
break;
}
V_147 >>= 1 ;
}
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_33 ) ;
goto V_142;
}
F_18 ( V_2 , V_29 , V_2 -> V_7 ,
L_34 , ( unsigned long long ) V_147 ) ;
V_35 = F_119 ( & V_146 -> V_150 , V_147 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_35 ) ;
goto V_142;
}
V_2 -> V_151 = F_120 ( V_2 -> V_146 , V_152 ) ;
V_35 = F_121 ( V_146 , V_152 , L_36 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_37 ) ;
V_35 = - V_8 ;
goto V_153;
}
V_2 -> V_154 = F_122 ( V_2 -> V_151 , V_149 ) ;
if ( ! V_2 -> V_154 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_38 ,
( unsigned long long ) V_2 -> V_151 , V_149 ) ;
V_35 = - V_103 ;
goto V_155;
}
F_18 ( V_2 , V_29 , V_2 -> V_7 ,
L_39 ,
( unsigned long long ) V_2 -> V_151 , V_149 ,
V_2 -> V_154 ) ;
return 0 ;
V_155:
F_123 ( V_2 -> V_146 , V_152 ) ;
V_153:
V_2 -> V_151 = 0 ;
V_142:
F_124 ( V_2 -> V_146 ) ;
V_139:
return V_35 ;
}
static void F_125 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_40 ) ;
if ( V_2 -> V_154 ) {
F_126 ( V_2 -> V_154 ) ;
V_2 -> V_154 = NULL ;
}
if ( V_2 -> V_151 ) {
F_123 ( V_2 -> V_146 , V_152 ) ;
V_2 -> V_151 = 0 ;
}
F_124 ( V_2 -> V_146 ) ;
}
static unsigned int F_127 ( struct V_1 * V_2 )
{
T_5 V_156 ;
unsigned int V_157 ;
int V_158 ;
if ( V_159 ) {
V_157 = V_159 ;
} else {
if ( F_4 ( ! F_128 ( & V_156 , V_44 ) ) ) {
F_129 ( V_2 , V_29 , V_2 -> V_7 ,
L_41 ) ;
return 1 ;
}
V_157 = 0 ;
F_130 (cpu) {
if ( ! F_131 ( V_158 , V_156 ) ) {
++ V_157 ;
F_132 ( V_156 , V_156 ,
F_133 ( V_158 ) ) ;
}
}
F_134 ( V_156 ) ;
}
if ( F_135 ( V_2 ) && F_136 ( V_2 ) > 1 &&
V_157 > F_136 ( V_2 ) ) {
F_129 ( V_2 , V_29 , V_2 -> V_7 ,
L_42
L_43
L_44 ,
V_157 , F_136 ( V_2 ) ) ;
V_157 = F_136 ( V_2 ) ;
}
return V_157 ;
}
static int F_137 ( struct V_1 * V_2 )
{
unsigned int V_160 = 0 ;
unsigned int V_39 , V_43 ;
int V_35 ;
for ( V_39 = 0 ; V_39 < V_161 ; V_39 ++ )
if ( V_2 -> V_162 [ V_39 ] )
++ V_160 ;
if ( V_2 -> V_163 == V_164 ) {
struct V_165 V_166 [ V_96 ] ;
unsigned int V_102 ;
V_102 = F_127 ( V_2 ) ;
if ( V_167 )
V_102 *= 2 ;
V_102 += V_160 ;
V_102 = F_138 ( V_102 , V_2 -> V_168 ) ;
for ( V_39 = 0 ; V_39 < V_102 ; V_39 ++ )
V_166 [ V_39 ] . V_169 = V_39 ;
V_35 = F_139 ( V_2 -> V_146 , V_166 , V_102 ) ;
if ( V_35 > 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_45
L_46 , V_35 , V_102 ) ;
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_47 ) ;
F_20 ( V_35 >= V_102 ) ;
V_102 = V_35 ;
V_35 = F_139 ( V_2 -> V_146 , V_166 ,
V_102 ) ;
}
if ( V_35 == 0 ) {
V_2 -> V_102 = V_102 ;
if ( V_102 > V_160 )
V_102 -= V_160 ;
if ( V_167 ) {
V_2 -> V_170 = F_21 ( V_102 / 2 , 1U ) ;
V_2 -> V_171 = F_21 ( V_102 -
V_2 -> V_170 ,
1U ) ;
} else {
V_2 -> V_170 = V_102 ;
V_2 -> V_171 = V_102 ;
}
for ( V_39 = 0 ; V_39 < V_2 -> V_102 ; V_39 ++ )
F_140 ( V_2 , V_39 ) -> V_172 =
V_166 [ V_39 ] . V_173 ;
} else {
V_2 -> V_163 = V_174 ;
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_48 ) ;
}
}
if ( V_2 -> V_163 == V_174 ) {
V_2 -> V_102 = 1 ;
V_2 -> V_171 = 1 ;
V_2 -> V_170 = 1 ;
V_35 = F_141 ( V_2 -> V_146 ) ;
if ( V_35 == 0 ) {
F_140 ( V_2 , 0 ) -> V_172 = V_2 -> V_146 -> V_172 ;
} else {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_49 ) ;
V_2 -> V_163 = V_175 ;
}
}
if ( V_2 -> V_163 == V_175 ) {
V_2 -> V_102 = 1 + ( V_167 ? 1 : 0 ) ;
V_2 -> V_171 = 1 ;
V_2 -> V_170 = 1 ;
V_2 -> V_176 = V_2 -> V_146 -> V_172 ;
}
V_43 = V_2 -> V_102 ;
for ( V_39 = 0 ; V_39 < V_161 ; V_39 ++ ) {
if ( ! V_2 -> V_162 [ V_39 ] )
continue;
if ( V_2 -> V_163 != V_164 ||
V_2 -> V_102 <= V_160 ) {
V_2 -> V_162 [ V_39 ] -> F_142 ( V_2 ) ;
} else {
-- V_43 ;
F_140 ( V_2 , V_43 ) -> type =
V_2 -> V_162 [ V_39 ] ;
}
}
V_2 -> V_177 = ( ( V_2 -> V_171 > 1 || ! F_135 ( V_2 ) ) ?
V_2 -> V_171 : F_136 ( V_2 ) ) ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 )
{
struct V_9 * V_10 , * V_178 ;
int V_35 ;
F_68 ( V_2 -> V_3 == V_4 ) ;
V_2 -> V_179 = true ;
F_27 () ;
F_48 (channel, efx) {
if ( ! V_10 -> type -> V_180 ) {
V_35 = F_23 ( V_10 ) ;
if ( V_35 )
goto V_56;
}
F_26 ( V_10 ) ;
}
F_143 ( V_2 ) ;
return 0 ;
V_56:
V_178 = V_10 ;
F_48 (channel, efx) {
if ( V_10 == V_178 )
break;
F_29 ( V_10 ) ;
if ( ! V_10 -> type -> V_180 )
F_31 ( V_10 ) ;
}
return V_35 ;
}
static void F_79 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
if ( V_2 -> V_3 == V_4 )
return;
F_144 ( V_2 ) ;
V_2 -> V_179 = false ;
F_27 () ;
if ( V_2 -> V_176 )
F_145 ( V_2 -> V_176 ) ;
F_48 (channel, efx) {
if ( V_10 -> V_172 )
F_145 ( V_10 -> V_172 ) ;
F_29 ( V_10 ) ;
if ( ! V_10 -> type -> V_180 )
F_31 ( V_10 ) ;
}
F_146 ( V_2 ) ;
}
static int F_147 ( struct V_1 * V_2 )
{
struct V_9 * V_10 , * V_178 ;
int V_35 ;
F_68 ( V_2 -> V_3 == V_4 ) ;
if ( V_2 -> V_181 ) {
F_148 ( V_2 -> V_176 ) ;
V_2 -> V_181 = false ;
}
V_2 -> type -> V_182 ( V_2 ) ;
F_48 (channel, efx) {
if ( V_10 -> type -> V_180 ) {
V_35 = F_23 ( V_10 ) ;
if ( V_35 )
goto V_56;
}
}
V_35 = F_83 ( V_2 ) ;
if ( V_35 )
goto V_56;
return 0 ;
V_56:
V_178 = V_10 ;
F_48 (channel, efx) {
if ( V_10 == V_178 )
break;
if ( V_10 -> type -> V_180 )
F_31 ( V_10 ) ;
}
V_2 -> type -> V_183 ( V_2 ) ;
return V_35 ;
}
static void F_149 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_79 ( V_2 ) ;
F_48 (channel, efx) {
if ( V_10 -> type -> V_180 )
F_31 ( V_10 ) ;
}
V_2 -> type -> V_183 ( V_2 ) ;
}
static void F_150 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_48 (channel, efx)
V_10 -> V_172 = 0 ;
F_151 ( V_2 -> V_146 ) ;
F_152 ( V_2 -> V_146 ) ;
V_2 -> V_176 = 0 ;
}
static void F_153 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_41 * V_42 ;
V_2 -> V_61 =
V_167 ? V_2 -> V_102 - V_2 -> V_170 : 0 ;
F_48 (channel, efx) {
if ( V_10 -> V_10 < V_2 -> V_171 )
V_10 -> V_15 . V_184 = V_10 -> V_10 ;
else
V_10 -> V_15 . V_184 = - 1 ;
F_41 (tx_queue, channel)
V_42 -> V_47 -= ( V_2 -> V_61 *
V_46 ) ;
}
}
static int F_154 ( struct V_1 * V_2 )
{
T_1 V_39 ;
int V_35 ;
F_18 ( V_2 , V_29 , V_2 -> V_7 , L_50 ) ;
V_35 = V_2 -> type -> V_29 ( V_2 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_137 ( V_2 ) ;
if ( V_35 )
goto V_139;
V_35 = V_2 -> type -> V_185 ( V_2 ) ;
if ( V_35 )
goto V_142;
if ( V_2 -> V_102 > 1 )
F_155 ( & V_2 -> V_186 , sizeof( V_2 -> V_186 ) ) ;
for ( V_39 = 0 ; V_39 < F_156 ( V_2 -> V_187 ) ; V_39 ++ )
V_2 -> V_187 [ V_39 ] =
F_157 ( V_39 , V_2 -> V_177 ) ;
F_153 ( V_2 ) ;
F_158 ( V_2 -> V_7 , V_2 -> V_170 ) ;
F_159 ( V_2 -> V_7 , V_2 -> V_171 ) ;
F_160 ( V_2 , V_188 , V_189 , true ,
true ) ;
return 0 ;
V_142:
F_150 ( V_2 ) ;
V_139:
V_2 -> type -> remove ( V_2 ) ;
return V_35 ;
}
static void F_161 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_51 ) ;
F_150 ( V_2 ) ;
V_2 -> type -> remove ( V_2 ) ;
}
static int F_162 ( struct V_1 * V_2 )
{
int V_35 ;
F_163 ( & V_2 -> V_190 ) ;
V_35 = V_2 -> type -> V_191 ( V_2 ) ;
if ( V_35 )
return V_35 ;
#ifdef F_164
if ( V_2 -> type -> V_192 & V_193 ) {
V_2 -> V_194 = F_165 ( V_2 -> type -> V_195 ,
sizeof( * V_2 -> V_194 ) ,
V_44 ) ;
if ( ! V_2 -> V_194 ) {
V_2 -> type -> V_196 ( V_2 ) ;
return - V_103 ;
}
}
#endif
return 0 ;
}
static void F_166 ( struct V_1 * V_2 )
{
#ifdef F_164
F_82 ( V_2 -> V_194 ) ;
#endif
V_2 -> type -> V_196 ( V_2 ) ;
}
static void F_167 ( struct V_1 * V_2 )
{
V_2 -> type -> V_197 ( V_2 ) ;
}
static int F_168 ( struct V_1 * V_2 )
{
int V_35 ;
V_35 = F_154 ( V_2 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 , L_52 ) ;
goto V_139;
}
V_35 = F_106 ( V_2 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 , L_53 ) ;
goto V_142;
}
F_54 ( V_198 < V_199 ) ;
if ( F_63 ( V_198 < F_169 ( V_2 ) ) ) {
V_35 = - V_200 ;
goto V_153;
}
V_2 -> V_30 = V_2 -> V_31 = V_198 ;
V_35 = F_162 ( V_2 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_54 ) ;
goto V_153;
}
V_35 = F_49 ( V_2 ) ;
if ( V_35 )
goto V_155;
return 0 ;
V_155:
F_166 ( V_2 ) ;
V_153:
F_113 ( V_2 ) ;
V_142:
F_161 ( V_2 ) ;
V_139:
return V_35 ;
}
static void F_84 ( struct V_1 * V_2 )
{
F_67 ( V_2 ) ;
F_68 ( V_2 -> V_3 == V_4 ) ;
if ( V_2 -> V_90 || ! F_92 ( V_2 -> V_7 ) )
return;
F_108 ( V_2 ) ;
F_52 ( V_2 ) ;
if ( V_2 -> type -> V_201 != NULL )
F_170 ( V_2 -> V_202 , & V_2 -> V_203 ,
V_204 ) ;
if ( F_171 ( V_2 ) >= V_205 ) {
F_103 ( & V_2 -> V_124 ) ;
if ( V_2 -> V_137 -> V_206 ( V_2 ) )
F_91 ( V_2 ) ;
F_104 ( & V_2 -> V_124 ) ;
}
V_2 -> type -> V_207 ( V_2 ) ;
}
static void F_172 ( struct V_1 * V_2 )
{
F_173 ( & V_2 -> V_203 ) ;
F_174 ( V_2 ) ;
F_175 ( & V_2 -> V_129 ) ;
}
static void F_78 ( struct V_1 * V_2 )
{
F_67 ( V_2 ) ;
if ( ! V_2 -> V_90 )
return;
V_2 -> type -> V_208 ( V_2 ) ;
F_109 ( V_2 ) ;
F_172 ( V_2 ) ;
F_63 ( F_92 ( V_2 -> V_7 ) &&
F_64 ( V_2 -> V_7 ) ) ;
F_176 ( V_2 -> V_7 ) ;
F_66 ( V_2 ) ;
}
static void F_177 ( struct V_1 * V_2 )
{
F_51 ( V_2 ) ;
F_166 ( V_2 ) ;
F_113 ( V_2 ) ;
F_161 ( V_2 ) ;
}
static unsigned int F_178 ( unsigned int V_209 , unsigned int V_210 )
{
if ( V_209 == 0 )
return 0 ;
if ( V_209 * 1000 < V_210 )
return 1 ;
return V_209 * 1000 / V_210 ;
}
int F_160 ( struct V_1 * V_2 , unsigned int V_211 ,
unsigned int V_212 , bool V_213 ,
bool V_214 )
{
struct V_9 * V_10 ;
unsigned int V_215 = F_179 ( V_2 -> type -> V_216 *
V_2 -> V_217 ,
1000 ) ;
unsigned int V_218 ;
unsigned int V_219 ;
F_67 ( V_2 ) ;
if ( V_211 > V_215 || V_212 > V_215 )
return - V_200 ;
V_218 = F_178 ( V_211 , V_2 -> V_217 ) ;
V_219 = F_178 ( V_212 , V_2 -> V_217 ) ;
if ( V_218 != V_219 && V_2 -> V_61 == 0 &&
! V_214 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_55
L_56 ) ;
return - V_200 ;
}
V_2 -> V_20 = V_213 ;
V_2 -> V_27 = V_219 ;
F_48 (channel, efx) {
if ( F_6 ( V_10 ) )
V_10 -> V_24 = V_219 ;
else if ( F_180 ( V_10 ) )
V_10 -> V_24 = V_218 ;
}
return 0 ;
}
void F_181 ( struct V_1 * V_2 , unsigned int * V_211 ,
unsigned int * V_212 , bool * V_213 )
{
* V_213 = V_2 -> V_20 ;
* V_212 = F_179 ( V_2 -> V_27 *
V_2 -> V_217 ,
1000 ) ;
if ( V_2 -> V_61 == 0 )
* V_211 = * V_212 ;
else
* V_211 = F_179 (
V_2 -> V_10 [ V_2 -> V_61 ] -> V_24 *
V_2 -> V_217 ,
1000 ) ;
}
static void F_182 ( struct V_127 * V_128 )
{
struct V_1 * V_2 = F_11 ( V_128 , struct V_1 ,
V_203 . V_220 ) ;
F_12 ( V_2 , V_221 , V_2 -> V_7 ,
L_57 ,
F_13 () ) ;
F_68 ( V_2 -> type -> V_201 == NULL ) ;
if ( F_183 ( & V_2 -> V_124 ) ) {
if ( V_2 -> V_90 )
V_2 -> type -> V_201 ( V_2 ) ;
F_104 ( & V_2 -> V_124 ) ;
}
F_170 ( V_2 -> V_202 , & V_2 -> V_203 ,
V_204 ) ;
}
static int F_184 ( struct V_222 * V_7 , struct V_223 * V_224 , int V_225 )
{
struct V_1 * V_2 = F_185 ( V_7 ) ;
struct V_226 * V_128 = F_186 ( V_224 ) ;
if ( V_225 == V_227 )
return F_187 ( V_2 , V_224 , V_225 ) ;
if ( ( V_225 == V_228 || V_225 == V_229 ) &&
( V_128 -> V_230 & 0xfc00 ) == 0x0400 )
V_128 -> V_230 ^= V_231 | 0x0400 ;
return F_188 ( & V_2 -> V_232 , V_128 , V_225 ) ;
}
static void F_80 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
V_10 -> V_50 = V_2 -> V_7 ;
F_189 ( V_10 -> V_50 , & V_10 -> V_18 ,
F_10 , V_233 ) ;
}
static void F_190 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_48 (channel, efx)
F_80 ( V_10 ) ;
}
static void F_81 ( struct V_9 * V_10 )
{
if ( V_10 -> V_50 )
F_191 ( & V_10 -> V_18 ) ;
V_10 -> V_50 = NULL ;
}
static void F_192 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_48 (channel, efx)
F_81 ( V_10 ) ;
}
static void F_193 ( struct V_222 * V_7 )
{
struct V_1 * V_2 = F_185 ( V_7 ) ;
struct V_9 * V_10 ;
F_48 (channel, efx)
F_194 ( V_10 ) ;
}
static int F_195 ( struct V_222 * V_7 )
{
struct V_1 * V_2 = F_185 ( V_7 ) ;
int V_35 ;
F_18 ( V_2 , V_38 , V_2 -> V_7 , L_58 ,
F_13 () ) ;
V_35 = F_1 ( V_2 ) ;
if ( V_35 )
return V_35 ;
if ( V_2 -> V_123 & V_132 )
return - V_234 ;
if ( F_196 ( V_2 ) && F_197 ( V_2 , V_93 ) )
return - V_8 ;
F_91 ( V_2 ) ;
F_84 ( V_2 ) ;
F_198 ( V_2 ) ;
return 0 ;
}
static int F_199 ( struct V_222 * V_7 )
{
struct V_1 * V_2 = F_185 ( V_7 ) ;
F_18 ( V_2 , V_144 , V_2 -> V_7 , L_59 ,
F_13 () ) ;
F_78 ( V_2 ) ;
return 0 ;
}
static struct V_235 * F_200 ( struct V_222 * V_7 ,
struct V_235 * V_236 )
{
struct V_1 * V_2 = F_185 ( V_7 ) ;
F_201 ( & V_2 -> V_237 ) ;
V_2 -> type -> V_238 ( V_2 , NULL , V_236 ) ;
F_202 ( & V_2 -> V_237 ) ;
return V_236 ;
}
static void F_203 ( struct V_222 * V_7 )
{
struct V_1 * V_2 = F_185 ( V_7 ) ;
F_2 ( V_2 , V_239 , V_2 -> V_7 ,
L_60 ,
V_2 -> V_90 ) ;
F_70 ( V_2 , V_240 ) ;
}
static int F_204 ( struct V_222 * V_7 , int V_241 )
{
struct V_1 * V_2 = F_185 ( V_7 ) ;
int V_35 ;
V_35 = F_1 ( V_2 ) ;
if ( V_35 )
return V_35 ;
if ( V_241 > V_242 )
return - V_200 ;
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_61 , V_241 ) ;
F_77 ( V_2 ) ;
F_78 ( V_2 ) ;
F_103 ( & V_2 -> V_124 ) ;
V_7 -> V_71 = V_241 ;
V_2 -> type -> V_130 ( V_2 ) ;
F_104 ( & V_2 -> V_124 ) ;
F_84 ( V_2 ) ;
F_85 ( V_2 -> V_7 ) ;
return 0 ;
}
static int F_205 ( struct V_222 * V_7 , void * V_128 )
{
struct V_1 * V_2 = F_185 ( V_7 ) ;
struct V_243 * V_244 = V_128 ;
char * V_245 = V_244 -> V_246 ;
if ( ! F_206 ( V_245 ) ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_62 ,
V_245 ) ;
return - V_247 ;
}
memcpy ( V_7 -> V_134 , V_245 , V_7 -> V_248 ) ;
F_207 ( V_2 ) ;
F_103 ( & V_2 -> V_124 ) ;
V_2 -> type -> V_130 ( V_2 ) ;
F_104 ( & V_2 -> V_124 ) ;
return 0 ;
}
static void F_208 ( struct V_222 * V_7 )
{
struct V_1 * V_2 = F_185 ( V_7 ) ;
if ( V_2 -> V_90 )
F_209 ( V_2 -> V_202 , & V_2 -> V_129 ) ;
}
static int F_210 ( struct V_222 * V_7 , T_6 V_128 )
{
struct V_1 * V_2 = F_185 ( V_7 ) ;
if ( V_7 -> V_249 & ~ V_128 & V_193 )
F_211 ( V_2 , V_250 ) ;
return 0 ;
}
static void F_212 ( struct V_1 * V_2 )
{
strcpy ( V_2 -> V_62 , V_2 -> V_7 -> V_62 ) ;
F_213 ( V_2 ) ;
F_47 ( V_2 ) ;
}
static int F_214 ( struct V_251 * V_252 ,
unsigned long V_253 , void * V_254 )
{
struct V_222 * V_7 = F_215 ( V_254 ) ;
if ( ( V_7 -> V_255 == & V_256 ||
V_7 -> V_255 == & V_257 ) &&
V_253 == V_258 )
F_212 ( F_185 ( V_7 ) ) ;
return V_259 ;
}
static T_7
F_216 ( struct V_260 * V_150 , struct V_261 * V_262 , char * V_58 )
{
struct V_1 * V_2 = F_217 ( F_218 ( V_150 ) ) ;
return sprintf ( V_58 , L_63 , V_2 -> V_263 ) ;
}
static int F_219 ( struct V_1 * V_2 )
{
struct V_222 * V_7 = V_2 -> V_7 ;
struct V_9 * V_10 ;
int V_35 ;
V_7 -> V_264 = 5 * V_265 ;
V_7 -> V_172 = V_2 -> V_146 -> V_172 ;
if ( F_171 ( V_2 ) >= V_266 ) {
V_7 -> V_255 = & V_257 ;
V_7 -> V_267 |= V_268 ;
} else {
V_7 -> V_255 = & V_256 ;
}
F_220 ( V_7 , & V_269 ) ;
V_7 -> V_270 = V_271 ;
F_221 () ;
V_2 -> V_3 = V_272 ;
F_222 () ;
if ( V_2 -> V_273 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_64 ) ;
V_35 = - V_8 ;
goto V_274;
}
V_35 = F_223 ( V_7 , V_7 -> V_62 ) ;
if ( V_35 < 0 )
goto V_274;
F_212 ( V_2 ) ;
F_95 ( V_7 ) ;
V_35 = F_224 ( V_7 ) ;
if ( V_35 )
goto V_274;
F_48 (channel, efx) {
struct V_41 * V_42 ;
F_41 (tx_queue, channel)
F_225 ( V_42 ) ;
}
F_226 () ;
V_35 = F_227 ( & V_2 -> V_146 -> V_150 , & V_275 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_65 ) ;
goto V_276;
}
return 0 ;
V_276:
F_221 () ;
F_228 ( V_7 ) ;
V_274:
V_2 -> V_3 = V_277 ;
F_226 () ;
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_66 ) ;
return V_35 ;
}
static void F_229 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_7 )
return;
F_68 ( F_185 ( V_2 -> V_7 ) != V_2 ) ;
F_230 ( V_2 -> V_62 , F_231 ( V_2 -> V_146 ) , sizeof( V_2 -> V_62 ) ) ;
F_232 ( & V_2 -> V_146 -> V_150 , & V_275 ) ;
F_221 () ;
F_228 ( V_2 -> V_7 ) ;
V_2 -> V_3 = V_277 ;
F_226 () ;
}
void F_233 ( struct V_1 * V_2 , enum V_278 V_279 )
{
F_67 ( V_2 ) ;
F_78 ( V_2 ) ;
F_149 ( V_2 ) ;
F_103 ( & V_2 -> V_124 ) ;
if ( V_2 -> V_140 && V_279 != V_280 )
V_2 -> V_137 -> V_143 ( V_2 ) ;
V_2 -> type -> V_143 ( V_2 ) ;
}
int F_234 ( struct V_1 * V_2 , enum V_278 V_279 , bool V_281 )
{
int V_35 ;
F_67 ( V_2 ) ;
V_35 = V_2 -> type -> V_138 ( V_2 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_67 ) ;
goto V_56;
}
if ( ! V_281 )
goto V_56;
if ( V_2 -> V_140 && V_279 != V_280 ) {
V_35 = V_2 -> V_137 -> V_138 ( V_2 ) ;
if ( V_35 )
goto V_56;
if ( V_2 -> V_137 -> V_141 ( V_2 ) )
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_68 ) ;
}
V_35 = F_147 ( V_2 ) ;
if ( V_35 )
goto V_56;
F_167 ( V_2 ) ;
F_235 ( V_2 ) ;
F_104 ( & V_2 -> V_124 ) ;
F_84 ( V_2 ) ;
return 0 ;
V_56:
V_2 -> V_140 = false ;
F_104 ( & V_2 -> V_124 ) ;
return V_35 ;
}
int F_197 ( struct V_1 * V_2 , enum V_278 V_279 )
{
int V_35 , V_99 ;
bool V_282 ;
F_96 ( V_2 , V_6 , V_2 -> V_7 , L_69 ,
F_236 ( V_279 ) ) ;
F_77 ( V_2 ) ;
F_233 ( V_2 , V_279 ) ;
V_35 = V_2 -> type -> V_283 ( V_2 , V_279 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_70 ) ;
goto V_104;
}
V_2 -> V_273 &= - ( 1 << ( V_279 + 1 ) ) ;
F_116 ( V_2 -> V_146 ) ;
V_104:
V_282 = V_35 ||
V_279 == V_106 ||
V_279 == V_284 ;
V_99 = F_234 ( V_2 , V_279 , ! V_282 ) ;
if ( V_99 ) {
V_282 = true ;
if ( ! V_35 )
V_35 = V_99 ;
}
if ( V_282 ) {
F_237 ( V_2 -> V_7 ) ;
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_71 ) ;
V_2 -> V_3 = V_4 ;
} else {
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_72 ) ;
F_85 ( V_2 -> V_7 ) ;
}
return V_35 ;
}
int F_238 ( struct V_1 * V_2 )
{
#ifdef F_239
struct V_285 * V_286 =
F_240 ( F_241 ( V_2 -> V_146 ) ) ;
if ( F_242 ( V_286 ) ) {
return 1 ;
}
#endif
return 0 ;
}
static void F_243 ( struct V_127 * V_128 )
{
struct V_1 * V_2 = F_11 ( V_128 , struct V_1 , V_287 ) ;
unsigned long V_288 ;
enum V_278 V_279 ;
V_288 = F_244 ( V_2 -> V_273 ) ;
V_279 = F_245 ( V_288 ) - 1 ;
if ( ( V_279 == V_284 ||
V_279 == V_289 ) &&
F_238 ( V_2 ) )
return;
if ( ! V_288 )
return;
F_221 () ;
if ( V_2 -> V_3 == V_272 )
( void ) F_197 ( V_2 , V_279 ) ;
F_226 () ;
}
void F_70 ( struct V_1 * V_2 , enum V_278 type )
{
enum V_278 V_279 ;
if ( V_2 -> V_3 == V_5 ) {
F_18 ( V_2 , V_6 , V_2 -> V_7 ,
L_73 ,
F_236 ( type ) ) ;
return;
}
switch ( type ) {
case V_280 :
case V_93 :
case V_289 :
case V_290 :
case V_106 :
case V_284 :
V_279 = type ;
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_74 ,
F_236 ( V_279 ) ) ;
break;
default:
V_279 = V_2 -> type -> V_291 ( type ) ;
F_18 ( V_2 , V_6 , V_2 -> V_7 ,
L_75 ,
F_236 ( V_279 ) , F_236 ( type ) ) ;
break;
}
F_246 ( V_279 , & V_2 -> V_273 ) ;
F_222 () ;
if ( F_244 ( V_2 -> V_3 ) != V_272 )
return;
F_144 ( V_2 ) ;
F_209 ( V_292 , & V_2 -> V_287 ) ;
}
int F_247 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_248 ( struct V_1 * V_2 ) {}
static bool F_249 ( struct V_1 * V_2 )
{
return false ;
}
static int F_250 ( struct V_1 * V_2 ,
struct V_146 * V_146 , struct V_222 * V_7 )
{
int V_39 ;
F_163 ( & V_2 -> V_293 ) ;
#ifdef F_251
F_252 ( & V_2 -> V_294 ) ;
#endif
F_253 ( & V_2 -> V_287 , F_243 ) ;
F_254 ( & V_2 -> V_203 , F_182 ) ;
F_254 ( & V_2 -> V_295 , V_296 ) ;
V_2 -> V_146 = V_146 ;
V_2 -> V_297 = V_298 ;
V_2 -> V_3 = V_277 ;
F_230 ( V_2 -> V_62 , F_231 ( V_146 ) , sizeof( V_2 -> V_62 ) ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_70 = V_2 -> type -> V_70 ;
V_2 -> V_299 =
V_2 -> type -> V_300 - V_2 -> type -> V_70 ;
F_163 ( & V_2 -> V_237 ) ;
F_255 ( & V_2 -> V_124 ) ;
V_2 -> V_137 = & V_301 ;
V_2 -> V_232 . V_150 = V_7 ;
F_253 ( & V_2 -> V_129 , F_105 ) ;
F_256 ( & V_2 -> V_302 ) ;
for ( V_39 = 0 ; V_39 < V_96 ; V_39 ++ ) {
V_2 -> V_10 [ V_39 ] = F_35 ( V_2 , V_39 , NULL ) ;
if ( ! V_2 -> V_10 [ V_39 ] )
goto V_56;
V_2 -> V_64 [ V_39 ] . V_2 = V_2 ;
V_2 -> V_64 [ V_39 ] . V_101 = V_39 ;
}
V_2 -> V_163 = F_21 ( V_2 -> type -> V_303 ,
V_163 ) ;
snprintf ( V_2 -> V_304 , sizeof( V_2 -> V_304 ) , L_76 ,
F_231 ( V_146 ) ) ;
V_2 -> V_202 = F_257 ( V_2 -> V_304 ) ;
if ( ! V_2 -> V_202 )
goto V_56;
return 0 ;
V_56:
F_258 ( V_2 ) ;
return - V_103 ;
}
static void F_258 ( struct V_1 * V_2 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_96 ; V_39 ++ )
F_82 ( V_2 -> V_10 [ V_39 ] ) ;
if ( V_2 -> V_202 ) {
F_259 ( V_2 -> V_202 ) ;
V_2 -> V_202 = NULL ;
}
}
static void F_260 ( struct V_1 * V_2 )
{
F_68 ( V_2 -> V_3 == V_272 ) ;
F_175 ( & V_2 -> V_287 ) ;
F_149 ( V_2 ) ;
F_261 ( V_2 ) ;
F_112 ( V_2 ) ;
V_2 -> type -> V_143 ( V_2 ) ;
F_192 ( V_2 ) ;
F_177 ( V_2 ) ;
}
static void F_262 ( struct V_146 * V_146 )
{
struct V_1 * V_2 ;
V_2 = F_217 ( V_146 ) ;
if ( ! V_2 )
return;
F_221 () ;
F_237 ( V_2 -> V_7 ) ;
F_149 ( V_2 ) ;
F_226 () ;
F_263 ( V_2 ) ;
F_229 ( V_2 ) ;
F_264 ( V_2 ) ;
F_260 ( V_2 ) ;
F_125 ( V_2 ) ;
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_77 ) ;
F_258 ( V_2 ) ;
F_265 ( V_146 , NULL ) ;
F_266 ( V_2 -> V_7 ) ;
F_267 ( V_146 ) ;
}
static void F_268 ( struct V_1 * V_2 )
{
struct V_146 * V_150 = V_2 -> V_146 ;
char V_305 [ V_306 ] ;
T_7 V_307 ;
int V_39 , V_43 ;
V_307 = F_269 ( V_150 , 0 , sizeof( V_305 ) , V_305 ) ;
if ( V_307 <= 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_78 ) ;
return;
}
V_39 = F_270 ( V_305 , 0 , V_307 , V_308 ) ;
if ( V_39 < 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_79 ) ;
return;
}
V_43 = F_271 ( & V_305 [ V_39 ] ) ;
V_39 += V_309 ;
if ( V_39 + V_43 > V_307 )
V_43 = V_307 - V_39 ;
V_39 = F_272 ( V_305 , V_39 , V_43 , L_80 ) ;
if ( V_39 < 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_81 ) ;
return;
}
V_43 = F_273 ( & V_305 [ V_39 ] ) ;
V_39 += V_310 ;
if ( V_39 + V_43 > V_307 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_82 ) ;
return;
}
F_96 ( V_2 , V_6 , V_2 -> V_7 ,
L_83 , V_43 , & V_305 [ V_39 ] ) ;
}
static int F_274 ( struct V_1 * V_2 )
{
int V_35 ;
V_35 = F_168 ( V_2 ) ;
if ( V_35 )
goto V_139;
F_190 ( V_2 ) ;
V_35 = V_2 -> type -> V_138 ( V_2 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_67 ) ;
goto V_153;
}
V_35 = F_107 ( V_2 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_84 ) ;
goto V_155;
}
V_35 = F_275 ( V_2 ) ;
if ( V_35 )
goto V_311;
V_35 = F_147 ( V_2 ) ;
if ( V_35 )
goto V_312;
return 0 ;
V_312:
F_261 ( V_2 ) ;
V_311:
F_112 ( V_2 ) ;
V_155:
V_2 -> type -> V_143 ( V_2 ) ;
V_153:
F_192 ( V_2 ) ;
F_177 ( V_2 ) ;
V_139:
return V_35 ;
}
static int F_276 ( struct V_146 * V_146 ,
const struct V_313 * V_169 )
{
struct V_222 * V_7 ;
struct V_1 * V_2 ;
int V_35 ;
V_7 = F_277 ( sizeof( * V_2 ) , V_314 ,
V_315 ) ;
if ( ! V_7 )
return - V_103 ;
V_2 = F_185 ( V_7 ) ;
V_2 -> type = ( const struct V_316 * ) V_169 -> V_317 ;
V_7 -> V_249 |= ( V_2 -> type -> V_192 | V_318 |
V_319 | V_320 |
V_321 ) ;
if ( V_2 -> type -> V_192 & V_322 )
V_7 -> V_249 |= V_323 ;
V_7 -> V_324 |= ( V_325 | V_318 |
V_319 | V_326 |
V_321 ) ;
V_7 -> V_327 = V_7 -> V_249 & ~ V_319 ;
F_265 ( V_146 , V_2 ) ;
F_278 ( V_7 , & V_146 -> V_150 ) ;
V_35 = F_250 ( V_2 , V_146 , V_7 ) ;
if ( V_35 )
goto V_139;
F_96 ( V_2 , V_29 , V_2 -> V_7 ,
L_85 ) ;
F_268 ( V_2 ) ;
V_35 = F_114 ( V_2 ) ;
if ( V_35 )
goto V_142;
V_35 = F_274 ( V_2 ) ;
if ( V_35 )
goto V_153;
V_35 = F_219 ( V_2 ) ;
if ( V_35 )
goto V_155;
V_35 = F_279 ( V_2 ) ;
if ( V_35 )
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_86 , V_35 ) ;
F_18 ( V_2 , V_29 , V_2 -> V_7 , L_87 ) ;
F_221 () ;
V_35 = F_280 ( V_2 ) ;
F_226 () ;
if ( V_35 )
F_129 ( V_2 , V_29 , V_2 -> V_7 ,
L_88 , V_35 ) ;
V_35 = F_281 ( V_146 ) ;
if ( V_35 && V_35 != - V_200 )
F_129 ( V_2 , V_29 , V_2 -> V_7 ,
L_89 , V_35 ) ;
return 0 ;
V_155:
F_260 ( V_2 ) ;
V_153:
F_125 ( V_2 ) ;
V_142:
F_258 ( V_2 ) ;
V_139:
F_265 ( V_146 , NULL ) ;
F_63 ( V_35 > 0 ) ;
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_90 , V_35 ) ;
F_266 ( V_7 ) ;
return V_35 ;
}
static int F_282 ( struct V_260 * V_150 )
{
struct V_1 * V_2 = F_217 ( F_218 ( V_150 ) ) ;
F_221 () ;
if ( V_2 -> V_3 != V_4 ) {
V_2 -> V_3 = V_277 ;
F_77 ( V_2 ) ;
F_78 ( V_2 ) ;
F_149 ( V_2 ) ;
}
F_226 () ;
return 0 ;
}
static int F_283 ( struct V_260 * V_150 )
{
int V_35 ;
struct V_1 * V_2 = F_217 ( F_218 ( V_150 ) ) ;
F_221 () ;
if ( V_2 -> V_3 != V_4 ) {
V_35 = F_147 ( V_2 ) ;
if ( V_35 )
goto V_56;
F_103 ( & V_2 -> V_124 ) ;
V_2 -> V_137 -> V_141 ( V_2 ) ;
F_104 ( & V_2 -> V_124 ) ;
F_84 ( V_2 ) ;
F_85 ( V_2 -> V_7 ) ;
V_2 -> V_3 = V_272 ;
V_2 -> type -> V_328 ( V_2 ) ;
}
F_226 () ;
F_209 ( V_292 , & V_2 -> V_287 ) ;
return 0 ;
V_56:
F_226 () ;
return V_35 ;
}
static int F_284 ( struct V_260 * V_150 )
{
struct V_146 * V_146 = F_218 ( V_150 ) ;
struct V_1 * V_2 = F_217 ( V_146 ) ;
V_2 -> type -> V_143 ( V_2 ) ;
V_2 -> V_273 = 0 ;
F_285 ( V_146 ) ;
return F_286 ( V_146 , V_329 ) ;
}
static int F_287 ( struct V_260 * V_150 )
{
struct V_146 * V_146 = F_218 ( V_150 ) ;
struct V_1 * V_2 = F_217 ( V_146 ) ;
int V_35 ;
V_35 = F_286 ( V_146 , V_330 ) ;
if ( V_35 )
return V_35 ;
F_288 ( V_146 ) ;
V_35 = F_115 ( V_146 ) ;
if ( V_35 )
return V_35 ;
F_116 ( V_2 -> V_146 ) ;
V_35 = V_2 -> type -> V_283 ( V_2 , V_93 ) ;
if ( V_35 )
return V_35 ;
V_35 = V_2 -> type -> V_138 ( V_2 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_283 ( V_150 ) ;
return V_35 ;
}
static int F_289 ( struct V_260 * V_150 )
{
int V_35 ;
F_282 ( V_150 ) ;
V_35 = F_284 ( V_150 ) ;
if ( V_35 )
F_287 ( V_150 ) ;
return V_35 ;
}
static T_8 F_290 ( struct V_146 * V_331 ,
enum V_332 V_3 )
{
T_8 V_333 = V_334 ;
struct V_1 * V_2 = F_217 ( V_331 ) ;
if ( V_3 == V_335 )
return V_336 ;
F_221 () ;
if ( V_2 -> V_3 != V_4 ) {
V_2 -> V_3 = V_5 ;
V_2 -> V_273 = 0 ;
F_77 ( V_2 ) ;
F_78 ( V_2 ) ;
F_149 ( V_2 ) ;
V_333 = V_337 ;
} else {
V_333 = V_334 ;
}
F_226 () ;
F_124 ( V_331 ) ;
return V_333 ;
}
static T_8 F_291 ( struct V_146 * V_331 )
{
struct V_1 * V_2 = F_217 ( V_331 ) ;
T_8 V_333 = V_334 ;
int V_35 ;
if ( F_115 ( V_331 ) ) {
F_2 ( V_2 , V_338 , V_2 -> V_7 ,
L_91 ) ;
V_333 = V_336 ;
}
V_35 = F_292 ( V_331 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_338 , V_2 -> V_7 ,
L_92 , V_35 ) ;
}
return V_333 ;
}
static void F_293 ( struct V_146 * V_331 )
{
struct V_1 * V_2 = F_217 ( V_331 ) ;
int V_35 ;
F_221 () ;
if ( V_2 -> V_3 == V_4 )
goto V_104;
V_35 = F_197 ( V_2 , V_93 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_338 , V_2 -> V_7 ,
L_93 , V_35 ) ;
} else {
V_2 -> V_3 = V_272 ;
F_18 ( V_2 , V_338 , V_2 -> V_7 ,
L_94 ) ;
}
V_104:
F_226 () ;
}
static int T_9 F_294 ( void )
{
int V_35 ;
F_295 ( V_339 L_95 V_340 L_96 ) ;
V_35 = F_296 ( & V_341 ) ;
if ( V_35 )
goto V_342;
V_35 = F_297 () ;
if ( V_35 )
goto V_343;
V_292 = F_257 ( L_97 ) ;
if ( ! V_292 ) {
V_35 = - V_103 ;
goto V_344;
}
V_35 = F_298 ( & V_345 ) ;
if ( V_35 < 0 )
goto V_346;
return 0 ;
V_346:
F_259 ( V_292 ) ;
V_344:
F_299 () ;
V_343:
F_300 ( & V_341 ) ;
V_342:
return V_35 ;
}
static void T_10 F_301 ( void )
{
F_295 ( V_339 L_98 ) ;
F_302 ( & V_345 ) ;
F_259 ( V_292 ) ;
F_299 () ;
F_300 ( & V_341 ) ;
}

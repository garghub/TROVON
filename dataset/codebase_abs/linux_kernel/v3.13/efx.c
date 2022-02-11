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
V_2 -> V_74 + V_2 -> V_69 ) ;
if ( V_68 <= V_75 ) {
V_2 -> V_67 = V_2 -> type -> V_76 ;
V_2 -> V_77 = 0 ;
} else if ( V_2 -> type -> V_78 ) {
F_54 ( V_79 % V_80 ) ;
F_54 ( sizeof( struct V_73 ) +
2 * F_55 ( V_81 + V_79 ,
V_82 ) >
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
V_2 -> V_83 ) ;
else
F_18 ( V_2 , V_6 , V_2 -> V_7 ,
L_15 ,
V_2 -> V_69 , V_2 -> V_84 ,
V_2 -> V_85 , V_2 -> V_83 ) ;
if ( V_2 -> V_67 != V_66 )
V_2 -> type -> V_86 ( V_2 ) ;
V_2 -> V_87 = V_2 -> V_31 - F_58 ( V_2 ) ;
V_2 -> V_88 = V_2 -> V_87 / 2 ;
F_48 (channel, efx) {
F_41 (tx_queue, channel) {
F_59 ( V_42 ) ;
F_60 ( & V_2 -> V_89 ) ;
}
F_43 (rx_queue, channel) {
F_61 ( V_15 ) ;
F_60 ( & V_2 -> V_89 ) ;
F_62 ( V_15 ) ;
}
F_63 ( V_10 -> V_90 ) ;
}
F_64 ( V_2 ) ;
if ( F_65 ( V_2 -> V_7 ) )
F_66 ( V_2 -> V_7 ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_41 * V_42 ;
struct V_14 * V_15 ;
int V_35 ;
F_68 ( V_2 ) ;
F_69 ( V_2 -> V_91 ) ;
F_70 ( V_2 ) ;
F_48 (channel, efx) {
F_43 (rx_queue, channel)
V_15 -> V_92 = false ;
}
F_48 (channel, efx) {
if ( F_6 ( V_10 ) ) {
F_29 ( V_10 ) ;
F_26 ( V_10 ) ;
}
}
V_35 = V_2 -> type -> V_93 ( V_2 ) ;
if ( V_35 && F_71 ( V_2 ) ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_16 ) ;
F_72 ( V_2 , V_94 ) ;
} else if ( V_35 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_17 ) ;
} else {
F_18 ( V_2 , V_6 , V_2 -> V_7 ,
L_18 ) ;
}
F_48 (channel, efx) {
F_43 (rx_queue, channel)
F_73 ( V_15 ) ;
F_74 (tx_queue, channel)
F_75 ( V_42 ) ;
}
}
static void F_45 ( struct V_9 * V_10 )
{
struct V_41 * V_42 ;
struct V_14 * V_15 ;
F_18 ( V_10 -> V_2 , V_6 , V_10 -> V_2 -> V_7 ,
L_19 , V_10 -> V_10 ) ;
F_43 (rx_queue, channel)
F_76 ( V_15 ) ;
F_74 (tx_queue, channel)
F_77 ( V_42 ) ;
F_33 ( V_10 ) ;
V_10 -> type -> V_95 ( V_10 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_48 (channel, efx)
F_45 ( V_10 ) ;
}
int
F_78 ( struct V_1 * V_2 , T_2 V_30 , T_2 V_31 )
{
struct V_9 * V_96 [ V_97 ] , * V_10 ;
T_2 V_98 , V_99 ;
unsigned V_39 , V_65 = 0 ;
int V_35 , V_100 ;
V_35 = F_1 ( V_2 ) ;
if ( V_35 )
return V_35 ;
F_48 (channel, efx) {
struct V_14 * V_15 ;
struct V_41 * V_42 ;
if ( V_10 -> type -> V_101 )
continue;
V_65 = F_21 ( V_65 ,
V_10 -> V_51 . V_102 +
V_10 -> V_51 . V_28 ) ;
F_43 (rx_queue, channel)
V_65 = F_21 ( V_65 ,
V_15 -> V_54 . V_102 +
V_15 -> V_54 . V_28 ) ;
F_41 (tx_queue, channel)
V_65 = F_21 ( V_65 ,
V_42 -> V_53 . V_102 +
V_42 -> V_53 . V_28 ) ;
}
F_79 ( V_2 ) ;
F_80 ( V_2 ) ;
F_81 ( V_2 ) ;
memset ( V_96 , 0 , sizeof( V_96 ) ) ;
for ( V_39 = 0 ; V_39 < V_2 -> V_103 ; V_39 ++ ) {
V_10 = V_2 -> V_10 [ V_39 ] ;
if ( V_10 -> type -> V_101 )
V_10 = V_10 -> type -> V_101 ( V_10 ) ;
if ( ! V_10 ) {
V_35 = - V_104 ;
goto V_105;
}
V_96 [ V_39 ] = V_10 ;
}
V_98 = V_2 -> V_30 ;
V_99 = V_2 -> V_31 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_31 = V_31 ;
for ( V_39 = 0 ; V_39 < V_2 -> V_103 ; V_39 ++ ) {
V_10 = V_2 -> V_10 [ V_39 ] ;
V_2 -> V_10 [ V_39 ] = V_96 [ V_39 ] ;
V_96 [ V_39 ] = V_10 ;
}
V_2 -> V_65 = V_65 ;
for ( V_39 = 0 ; V_39 < V_2 -> V_103 ; V_39 ++ ) {
V_10 = V_2 -> V_10 [ V_39 ] ;
if ( ! V_10 -> type -> V_101 )
continue;
V_35 = F_40 ( V_10 ) ;
if ( V_35 )
goto V_106;
F_82 ( V_2 -> V_10 [ V_39 ] ) ;
}
V_105:
for ( V_39 = 0 ; V_39 < V_2 -> V_103 ; V_39 ++ ) {
V_10 = V_96 [ V_39 ] ;
if ( V_10 && V_10 -> type -> V_101 ) {
F_83 ( V_10 ) ;
F_45 ( V_10 ) ;
F_84 ( V_10 ) ;
}
}
V_100 = F_85 ( V_2 ) ;
if ( V_100 ) {
V_35 = V_35 ? V_35 : V_100 ;
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_20 ) ;
F_72 ( V_2 , V_107 ) ;
} else {
F_86 ( V_2 ) ;
F_87 ( V_2 -> V_7 ) ;
}
return V_35 ;
V_106:
V_2 -> V_30 = V_98 ;
V_2 -> V_31 = V_99 ;
for ( V_39 = 0 ; V_39 < V_2 -> V_103 ; V_39 ++ ) {
V_10 = V_2 -> V_10 [ V_39 ] ;
V_2 -> V_10 [ V_39 ] = V_96 [ V_39 ] ;
V_96 [ V_39 ] = V_10 ;
}
goto V_105;
}
void F_88 ( struct V_14 * V_15 )
{
F_89 ( & V_15 -> V_48 , V_108 + F_90 ( 100 ) ) ;
}
int F_91 ( struct V_9 * V_10 )
{
return 0 ;
}
void F_92 ( struct V_9 * V_10 )
{
}
void F_93 ( struct V_1 * V_2 )
{
struct V_109 * V_110 = & V_2 -> V_110 ;
if ( ! F_94 ( V_2 -> V_7 ) )
return;
if ( V_110 -> V_111 != F_95 ( V_2 -> V_7 ) ) {
V_2 -> V_112 ++ ;
if ( V_110 -> V_111 )
F_96 ( V_2 -> V_7 ) ;
else
F_97 ( V_2 -> V_7 ) ;
}
if ( V_110 -> V_111 )
F_98 ( V_2 , V_113 , V_2 -> V_7 ,
L_21 ,
V_110 -> V_114 , V_110 -> V_115 ? L_22 : L_23 ,
V_2 -> V_7 -> V_71 ) ;
else
F_98 ( V_2 , V_113 , V_2 -> V_7 , L_24 ) ;
}
void F_99 ( struct V_1 * V_2 , T_2 V_116 )
{
V_2 -> V_117 = V_116 ;
if ( V_116 ) {
if ( V_116 & V_118 )
V_2 -> V_119 |= ( V_120 | V_121 ) ;
else
V_2 -> V_119 &= ~ ( V_120 | V_121 ) ;
if ( V_116 & V_122 )
V_2 -> V_119 ^= V_120 ;
}
}
void F_100 ( struct V_1 * V_2 , T_3 V_119 )
{
V_2 -> V_119 = V_119 ;
if ( V_2 -> V_117 ) {
if ( V_119 & V_121 )
V_2 -> V_117 |= ( V_118 |
V_122 ) ;
else
V_2 -> V_117 &= ~ ( V_118 |
V_122 ) ;
if ( V_119 & V_120 )
V_2 -> V_117 ^= V_122 ;
}
}
int F_101 ( struct V_1 * V_2 )
{
enum V_123 V_124 ;
int V_35 ;
F_63 ( ! F_102 ( & V_2 -> V_125 ) ) ;
V_124 = V_2 -> V_124 ;
if ( F_103 ( V_2 ) )
V_2 -> V_124 |= V_126 ;
else
V_2 -> V_124 &= ~ V_126 ;
V_35 = V_2 -> type -> V_127 ( V_2 ) ;
if ( V_35 )
V_2 -> V_124 = V_124 ;
return V_35 ;
}
int F_104 ( struct V_1 * V_2 )
{
int V_35 ;
F_68 ( V_2 ) ;
F_105 ( & V_2 -> V_125 ) ;
V_35 = F_101 ( V_2 ) ;
F_106 ( & V_2 -> V_125 ) ;
return V_35 ;
}
static void F_107 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = F_11 ( V_129 , struct V_1 , V_130 ) ;
F_105 ( & V_2 -> V_125 ) ;
if ( V_2 -> V_91 )
V_2 -> type -> V_131 ( V_2 ) ;
F_106 ( & V_2 -> V_125 ) ;
}
static int F_108 ( struct V_1 * V_2 )
{
int V_35 ;
F_18 ( V_2 , V_29 , V_2 -> V_7 , L_25 ) ;
if ( V_132 )
V_2 -> V_124 = V_133 ;
V_35 = V_2 -> type -> V_134 ( V_2 ) ;
if ( V_35 )
return V_35 ;
memcpy ( V_2 -> V_7 -> V_135 , V_2 -> V_7 -> V_136 , V_137 ) ;
return 0 ;
}
static int F_109 ( struct V_1 * V_2 )
{
int V_35 ;
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_26 ) ;
F_105 ( & V_2 -> V_125 ) ;
V_35 = V_2 -> V_138 -> V_139 ( V_2 ) ;
if ( V_35 )
goto V_140;
V_2 -> V_141 = true ;
V_2 -> type -> V_131 ( V_2 ) ;
V_35 = V_2 -> V_138 -> V_142 ( V_2 ) ;
if ( V_35 )
goto V_143;
F_106 ( & V_2 -> V_125 ) ;
return 0 ;
V_143:
V_2 -> V_138 -> V_144 ( V_2 ) ;
V_140:
F_106 ( & V_2 -> V_125 ) ;
return V_35 ;
}
static void F_110 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_38 , V_2 -> V_7 , L_27 ) ;
F_69 ( V_2 -> V_91 ) ;
F_105 ( & V_2 -> V_125 ) ;
V_2 -> V_91 = true ;
V_2 -> type -> V_131 ( V_2 ) ;
F_106 ( & V_2 -> V_125 ) ;
}
static void F_111 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_145 , V_2 -> V_7 , L_28 ) ;
F_105 ( & V_2 -> V_125 ) ;
V_2 -> V_91 = false ;
F_106 ( & V_2 -> V_125 ) ;
F_112 ( V_2 -> V_7 ) ;
F_113 ( V_2 -> V_7 ) ;
}
static void F_114 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_29 ) ;
if ( ! V_2 -> V_141 )
return;
V_2 -> V_138 -> V_144 ( V_2 ) ;
V_2 -> V_141 = false ;
V_2 -> V_110 . V_111 = false ;
F_93 ( V_2 ) ;
}
static void F_115 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_30 ) ;
V_2 -> type -> V_146 ( V_2 ) ;
}
static int F_116 ( struct V_1 * V_2 )
{
struct V_147 * V_147 = V_2 -> V_147 ;
T_4 V_148 = V_2 -> type -> V_149 ;
unsigned int V_150 = V_2 -> type -> V_150 ( V_2 ) ;
int V_35 ;
F_18 ( V_2 , V_29 , V_2 -> V_7 , L_31 ) ;
V_35 = F_117 ( V_147 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_32 ) ;
goto V_140;
}
F_118 ( V_147 ) ;
while ( V_148 > 0x7fffffffUL ) {
if ( F_119 ( & V_147 -> V_151 , V_148 ) ) {
V_35 = F_120 ( & V_147 -> V_151 , V_148 ) ;
if ( V_35 == 0 )
break;
}
V_148 >>= 1 ;
}
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_33 ) ;
goto V_143;
}
F_18 ( V_2 , V_29 , V_2 -> V_7 ,
L_34 , ( unsigned long long ) V_148 ) ;
V_2 -> V_152 = F_121 ( V_2 -> V_147 , V_153 ) ;
V_35 = F_122 ( V_147 , V_153 , L_35 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_36 ) ;
V_35 = - V_8 ;
goto V_154;
}
V_2 -> V_155 = F_123 ( V_2 -> V_152 , V_150 ) ;
if ( ! V_2 -> V_155 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_37 ,
( unsigned long long ) V_2 -> V_152 , V_150 ) ;
V_35 = - V_104 ;
goto V_156;
}
F_18 ( V_2 , V_29 , V_2 -> V_7 ,
L_38 ,
( unsigned long long ) V_2 -> V_152 , V_150 ,
V_2 -> V_155 ) ;
return 0 ;
V_156:
F_124 ( V_2 -> V_147 , V_153 ) ;
V_154:
V_2 -> V_152 = 0 ;
V_143:
F_125 ( V_2 -> V_147 ) ;
V_140:
return V_35 ;
}
static void F_126 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_39 ) ;
if ( V_2 -> V_155 ) {
F_127 ( V_2 -> V_155 ) ;
V_2 -> V_155 = NULL ;
}
if ( V_2 -> V_152 ) {
F_124 ( V_2 -> V_147 , V_153 ) ;
V_2 -> V_152 = 0 ;
}
F_125 ( V_2 -> V_147 ) ;
}
static unsigned int F_128 ( struct V_1 * V_2 )
{
T_5 V_157 ;
unsigned int V_158 ;
int V_159 ;
if ( V_160 ) {
V_158 = V_160 ;
} else {
if ( F_4 ( ! F_129 ( & V_157 , V_44 ) ) ) {
F_130 ( V_2 , V_29 , V_2 -> V_7 ,
L_40 ) ;
return 1 ;
}
V_158 = 0 ;
F_131 (cpu) {
if ( ! F_132 ( V_159 , V_157 ) ) {
++ V_158 ;
F_133 ( V_157 , V_157 ,
F_134 ( V_159 ) ) ;
}
}
F_135 ( V_157 ) ;
}
if ( F_136 ( V_2 ) && F_137 ( V_2 ) > 1 &&
V_158 > F_137 ( V_2 ) ) {
F_130 ( V_2 , V_29 , V_2 -> V_7 ,
L_41
L_42
L_43 ,
V_158 , F_137 ( V_2 ) ) ;
V_158 = F_137 ( V_2 ) ;
}
return V_158 ;
}
static int F_138 ( struct V_1 * V_2 )
{
unsigned int V_161 = 0 ;
unsigned int V_39 , V_43 ;
int V_35 ;
for ( V_39 = 0 ; V_39 < V_162 ; V_39 ++ )
if ( V_2 -> V_163 [ V_39 ] )
++ V_161 ;
if ( V_2 -> V_164 == V_165 ) {
struct V_166 V_167 [ V_97 ] ;
unsigned int V_103 ;
V_103 = F_128 ( V_2 ) ;
if ( V_168 )
V_103 *= 2 ;
V_103 += V_161 ;
V_103 = F_139 ( V_103 , V_2 -> V_169 ) ;
for ( V_39 = 0 ; V_39 < V_103 ; V_39 ++ )
V_167 [ V_39 ] . V_170 = V_39 ;
V_35 = F_140 ( V_2 -> V_147 , V_167 , V_103 ) ;
if ( V_35 > 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_44
L_45 , V_35 , V_103 ) ;
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_46 ) ;
F_20 ( V_35 >= V_103 ) ;
V_103 = V_35 ;
V_35 = F_140 ( V_2 -> V_147 , V_167 ,
V_103 ) ;
}
if ( V_35 == 0 ) {
V_2 -> V_103 = V_103 ;
if ( V_103 > V_161 )
V_103 -= V_161 ;
if ( V_168 ) {
V_2 -> V_171 = F_21 ( V_103 / 2 , 1U ) ;
V_2 -> V_172 = F_21 ( V_103 -
V_2 -> V_171 ,
1U ) ;
} else {
V_2 -> V_171 = V_103 ;
V_2 -> V_172 = V_103 ;
}
for ( V_39 = 0 ; V_39 < V_2 -> V_103 ; V_39 ++ )
F_141 ( V_2 , V_39 ) -> V_173 =
V_167 [ V_39 ] . V_174 ;
} else {
V_2 -> V_164 = V_175 ;
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_47 ) ;
}
}
if ( V_2 -> V_164 == V_175 ) {
V_2 -> V_103 = 1 ;
V_2 -> V_172 = 1 ;
V_2 -> V_171 = 1 ;
V_35 = F_142 ( V_2 -> V_147 ) ;
if ( V_35 == 0 ) {
F_141 ( V_2 , 0 ) -> V_173 = V_2 -> V_147 -> V_173 ;
} else {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_48 ) ;
V_2 -> V_164 = V_176 ;
}
}
if ( V_2 -> V_164 == V_176 ) {
V_2 -> V_103 = 1 + ( V_168 ? 1 : 0 ) ;
V_2 -> V_172 = 1 ;
V_2 -> V_171 = 1 ;
V_2 -> V_177 = V_2 -> V_147 -> V_173 ;
}
V_43 = V_2 -> V_103 ;
for ( V_39 = 0 ; V_39 < V_162 ; V_39 ++ ) {
if ( ! V_2 -> V_163 [ V_39 ] )
continue;
if ( V_2 -> V_164 != V_165 ||
V_2 -> V_103 <= V_161 ) {
V_2 -> V_163 [ V_39 ] -> F_143 ( V_2 ) ;
} else {
-- V_43 ;
F_141 ( V_2 , V_43 ) -> type =
V_2 -> V_163 [ V_39 ] ;
}
}
V_2 -> V_178 = ( ( V_2 -> V_172 > 1 || ! F_136 ( V_2 ) ) ?
V_2 -> V_172 : F_137 ( V_2 ) ) ;
return 0 ;
}
static int F_85 ( struct V_1 * V_2 )
{
struct V_9 * V_10 , * V_179 ;
int V_35 ;
F_69 ( V_2 -> V_3 == V_4 ) ;
V_2 -> V_180 = true ;
F_27 () ;
F_48 (channel, efx) {
if ( ! V_10 -> type -> V_181 ) {
V_35 = F_23 ( V_10 ) ;
if ( V_35 )
goto V_56;
}
F_26 ( V_10 ) ;
}
F_144 ( V_2 ) ;
return 0 ;
V_56:
V_179 = V_10 ;
F_48 (channel, efx) {
if ( V_10 == V_179 )
break;
F_29 ( V_10 ) ;
if ( ! V_10 -> type -> V_181 )
F_31 ( V_10 ) ;
}
return V_35 ;
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
if ( V_2 -> V_3 == V_4 )
return;
F_145 ( V_2 ) ;
V_2 -> V_180 = false ;
F_27 () ;
if ( V_2 -> V_177 )
F_146 ( V_2 -> V_177 ) ;
F_48 (channel, efx) {
if ( V_10 -> V_173 )
F_146 ( V_10 -> V_173 ) ;
F_29 ( V_10 ) ;
if ( ! V_10 -> type -> V_181 )
F_31 ( V_10 ) ;
}
F_147 ( V_2 ) ;
}
static int F_148 ( struct V_1 * V_2 )
{
struct V_9 * V_10 , * V_179 ;
int V_35 ;
F_69 ( V_2 -> V_3 == V_4 ) ;
if ( V_2 -> V_182 ) {
F_149 ( V_2 -> V_177 ) ;
V_2 -> V_182 = false ;
}
V_2 -> type -> V_183 ( V_2 ) ;
F_48 (channel, efx) {
if ( V_10 -> type -> V_181 ) {
V_35 = F_23 ( V_10 ) ;
if ( V_35 )
goto V_56;
}
}
V_35 = F_85 ( V_2 ) ;
if ( V_35 )
goto V_56;
return 0 ;
V_56:
V_179 = V_10 ;
F_48 (channel, efx) {
if ( V_10 == V_179 )
break;
if ( V_10 -> type -> V_181 )
F_31 ( V_10 ) ;
}
V_2 -> type -> V_184 ( V_2 ) ;
return V_35 ;
}
static void F_150 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_81 ( V_2 ) ;
F_48 (channel, efx) {
if ( V_10 -> type -> V_181 )
F_31 ( V_10 ) ;
}
V_2 -> type -> V_184 ( V_2 ) ;
}
static void F_151 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_48 (channel, efx)
V_10 -> V_173 = 0 ;
F_152 ( V_2 -> V_147 ) ;
F_153 ( V_2 -> V_147 ) ;
V_2 -> V_177 = 0 ;
}
static void F_154 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_41 * V_42 ;
V_2 -> V_61 =
V_168 ? V_2 -> V_103 - V_2 -> V_171 : 0 ;
F_48 (channel, efx) {
if ( V_10 -> V_10 < V_2 -> V_172 )
V_10 -> V_15 . V_185 = V_10 -> V_10 ;
else
V_10 -> V_15 . V_185 = - 1 ;
F_41 (tx_queue, channel)
V_42 -> V_47 -= ( V_2 -> V_61 *
V_46 ) ;
}
}
static int F_155 ( struct V_1 * V_2 )
{
T_1 V_39 ;
int V_35 ;
F_18 ( V_2 , V_29 , V_2 -> V_7 , L_49 ) ;
V_35 = V_2 -> type -> V_29 ( V_2 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_138 ( V_2 ) ;
if ( V_35 )
goto V_140;
V_35 = V_2 -> type -> V_186 ( V_2 ) ;
if ( V_35 )
goto V_143;
if ( V_2 -> V_103 > 1 )
F_156 ( & V_2 -> V_187 , sizeof( V_2 -> V_187 ) ) ;
for ( V_39 = 0 ; V_39 < F_157 ( V_2 -> V_188 ) ; V_39 ++ )
V_2 -> V_188 [ V_39 ] =
F_158 ( V_39 , V_2 -> V_178 ) ;
F_154 ( V_2 ) ;
F_159 ( V_2 -> V_7 , V_2 -> V_171 ) ;
F_160 ( V_2 -> V_7 , V_2 -> V_172 ) ;
F_161 ( V_2 , V_189 , V_190 , true ,
true ) ;
return 0 ;
V_143:
F_151 ( V_2 ) ;
V_140:
V_2 -> type -> remove ( V_2 ) ;
return V_35 ;
}
static void F_162 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_50 ) ;
F_151 ( V_2 ) ;
V_2 -> type -> remove ( V_2 ) ;
}
static int F_163 ( struct V_1 * V_2 )
{
int V_35 ;
F_164 ( & V_2 -> V_191 ) ;
V_35 = V_2 -> type -> V_192 ( V_2 ) ;
if ( V_35 )
return V_35 ;
#ifdef F_165
if ( V_2 -> type -> V_193 & V_194 ) {
V_2 -> V_195 = F_166 ( V_2 -> type -> V_196 ,
sizeof( * V_2 -> V_195 ) ,
V_44 ) ;
if ( ! V_2 -> V_195 ) {
V_2 -> type -> V_197 ( V_2 ) ;
return - V_104 ;
}
}
#endif
return 0 ;
}
static void F_167 ( struct V_1 * V_2 )
{
#ifdef F_165
F_84 ( V_2 -> V_195 ) ;
#endif
V_2 -> type -> V_197 ( V_2 ) ;
}
static void F_168 ( struct V_1 * V_2 )
{
V_2 -> type -> V_198 ( V_2 ) ;
}
static int F_169 ( struct V_1 * V_2 )
{
int V_35 ;
V_35 = F_155 ( V_2 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 , L_51 ) ;
goto V_140;
}
V_35 = F_108 ( V_2 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 , L_52 ) ;
goto V_143;
}
F_54 ( V_199 < V_200 ) ;
if ( F_63 ( V_199 < F_170 ( V_2 ) ) ) {
V_35 = - V_201 ;
goto V_154;
}
V_2 -> V_30 = V_2 -> V_31 = V_199 ;
V_35 = F_163 ( V_2 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_53 ) ;
goto V_154;
}
V_35 = F_49 ( V_2 ) ;
if ( V_35 )
goto V_156;
return 0 ;
V_156:
F_167 ( V_2 ) ;
V_154:
F_115 ( V_2 ) ;
V_143:
F_162 ( V_2 ) ;
V_140:
return V_35 ;
}
static void F_86 ( struct V_1 * V_2 )
{
F_68 ( V_2 ) ;
F_69 ( V_2 -> V_3 == V_4 ) ;
if ( V_2 -> V_91 || ! F_94 ( V_2 -> V_7 ) )
return;
F_110 ( V_2 ) ;
F_52 ( V_2 ) ;
if ( V_2 -> type -> V_202 != NULL )
F_171 ( V_2 -> V_203 , & V_2 -> V_204 ,
V_205 ) ;
if ( F_172 ( V_2 ) >= V_206 ) {
F_105 ( & V_2 -> V_125 ) ;
if ( V_2 -> V_138 -> V_207 ( V_2 ) )
F_93 ( V_2 ) ;
F_106 ( & V_2 -> V_125 ) ;
}
V_2 -> type -> V_208 ( V_2 ) ;
}
static void F_173 ( struct V_1 * V_2 )
{
F_174 ( & V_2 -> V_204 ) ;
F_175 ( V_2 ) ;
F_176 ( & V_2 -> V_130 ) ;
}
static void F_80 ( struct V_1 * V_2 )
{
F_68 ( V_2 ) ;
if ( ! V_2 -> V_91 )
return;
V_2 -> type -> V_209 ( V_2 ) ;
F_111 ( V_2 ) ;
F_173 ( V_2 ) ;
F_63 ( F_94 ( V_2 -> V_7 ) &&
F_65 ( V_2 -> V_7 ) ) ;
F_177 ( V_2 -> V_7 ) ;
F_67 ( V_2 ) ;
}
static void F_178 ( struct V_1 * V_2 )
{
F_51 ( V_2 ) ;
F_167 ( V_2 ) ;
F_115 ( V_2 ) ;
F_162 ( V_2 ) ;
}
static unsigned int F_179 ( unsigned int V_210 , unsigned int V_211 )
{
if ( V_210 == 0 )
return 0 ;
if ( V_210 * 1000 < V_211 )
return 1 ;
return V_210 * 1000 / V_211 ;
}
int F_161 ( struct V_1 * V_2 , unsigned int V_212 ,
unsigned int V_213 , bool V_214 ,
bool V_215 )
{
struct V_9 * V_10 ;
unsigned int V_216 = F_180 ( V_2 -> type -> V_217 *
V_2 -> V_218 ,
1000 ) ;
unsigned int V_219 ;
unsigned int V_220 ;
F_68 ( V_2 ) ;
if ( V_212 > V_216 || V_213 > V_216 )
return - V_201 ;
V_219 = F_179 ( V_212 , V_2 -> V_218 ) ;
V_220 = F_179 ( V_213 , V_2 -> V_218 ) ;
if ( V_219 != V_220 && V_2 -> V_61 == 0 &&
! V_215 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_54
L_55 ) ;
return - V_201 ;
}
V_2 -> V_20 = V_214 ;
V_2 -> V_27 = V_220 ;
F_48 (channel, efx) {
if ( F_6 ( V_10 ) )
V_10 -> V_24 = V_220 ;
else if ( F_181 ( V_10 ) )
V_10 -> V_24 = V_219 ;
}
return 0 ;
}
void F_182 ( struct V_1 * V_2 , unsigned int * V_212 ,
unsigned int * V_213 , bool * V_214 )
{
* V_214 = V_2 -> V_20 ;
* V_213 = F_180 ( V_2 -> V_27 *
V_2 -> V_218 ,
1000 ) ;
if ( V_2 -> V_61 == 0 )
* V_212 = * V_213 ;
else
* V_212 = F_180 (
V_2 -> V_10 [ V_2 -> V_61 ] -> V_24 *
V_2 -> V_218 ,
1000 ) ;
}
static void F_183 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = F_11 ( V_129 , struct V_1 ,
V_204 . V_221 ) ;
F_12 ( V_2 , V_222 , V_2 -> V_7 ,
L_56 ,
F_13 () ) ;
F_69 ( V_2 -> type -> V_202 == NULL ) ;
if ( F_184 ( & V_2 -> V_125 ) ) {
if ( V_2 -> V_91 )
V_2 -> type -> V_202 ( V_2 ) ;
F_106 ( & V_2 -> V_125 ) ;
}
F_171 ( V_2 -> V_203 , & V_2 -> V_204 ,
V_205 ) ;
}
static int F_185 ( struct V_223 * V_7 , struct V_224 * V_225 , int V_226 )
{
struct V_1 * V_2 = F_186 ( V_7 ) ;
struct V_227 * V_129 = F_187 ( V_225 ) ;
if ( V_226 == V_228 )
return F_188 ( V_2 , V_225 , V_226 ) ;
if ( ( V_226 == V_229 || V_226 == V_230 ) &&
( V_129 -> V_231 & 0xfc00 ) == 0x0400 )
V_129 -> V_231 ^= V_232 | 0x0400 ;
return F_189 ( & V_2 -> V_233 , V_129 , V_226 ) ;
}
static void F_82 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
V_10 -> V_50 = V_2 -> V_7 ;
F_190 ( V_10 -> V_50 , & V_10 -> V_18 ,
F_10 , V_234 ) ;
}
static void F_191 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_48 (channel, efx)
F_82 ( V_10 ) ;
}
static void F_83 ( struct V_9 * V_10 )
{
if ( V_10 -> V_50 )
F_192 ( & V_10 -> V_18 ) ;
V_10 -> V_50 = NULL ;
}
static void F_193 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_48 (channel, efx)
F_83 ( V_10 ) ;
}
static void F_194 ( struct V_223 * V_7 )
{
struct V_1 * V_2 = F_186 ( V_7 ) ;
struct V_9 * V_10 ;
F_48 (channel, efx)
F_195 ( V_10 ) ;
}
static int F_196 ( struct V_223 * V_7 )
{
struct V_1 * V_2 = F_186 ( V_7 ) ;
int V_35 ;
F_18 ( V_2 , V_38 , V_2 -> V_7 , L_57 ,
F_13 () ) ;
V_35 = F_1 ( V_2 ) ;
if ( V_35 )
return V_35 ;
if ( V_2 -> V_124 & V_133 )
return - V_235 ;
if ( F_197 ( V_2 ) && F_198 ( V_2 , V_94 ) )
return - V_8 ;
F_93 ( V_2 ) ;
F_86 ( V_2 ) ;
F_199 ( V_2 ) ;
return 0 ;
}
static int F_200 ( struct V_223 * V_7 )
{
struct V_1 * V_2 = F_186 ( V_7 ) ;
F_18 ( V_2 , V_145 , V_2 -> V_7 , L_58 ,
F_13 () ) ;
F_80 ( V_2 ) ;
return 0 ;
}
static struct V_236 * F_201 ( struct V_223 * V_7 ,
struct V_236 * V_237 )
{
struct V_1 * V_2 = F_186 ( V_7 ) ;
F_202 ( & V_2 -> V_238 ) ;
V_2 -> type -> V_239 ( V_2 , NULL , V_237 ) ;
F_203 ( & V_2 -> V_238 ) ;
return V_237 ;
}
static void F_204 ( struct V_223 * V_7 )
{
struct V_1 * V_2 = F_186 ( V_7 ) ;
F_2 ( V_2 , V_240 , V_2 -> V_7 ,
L_59 ,
V_2 -> V_91 ) ;
F_72 ( V_2 , V_241 ) ;
}
static int F_205 ( struct V_223 * V_7 , int V_242 )
{
struct V_1 * V_2 = F_186 ( V_7 ) ;
int V_35 ;
V_35 = F_1 ( V_2 ) ;
if ( V_35 )
return V_35 ;
if ( V_242 > V_243 )
return - V_201 ;
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_60 , V_242 ) ;
F_79 ( V_2 ) ;
F_80 ( V_2 ) ;
F_105 ( & V_2 -> V_125 ) ;
V_7 -> V_71 = V_242 ;
V_2 -> type -> V_131 ( V_2 ) ;
F_106 ( & V_2 -> V_125 ) ;
F_86 ( V_2 ) ;
F_87 ( V_2 -> V_7 ) ;
return 0 ;
}
static int F_206 ( struct V_223 * V_7 , void * V_129 )
{
struct V_1 * V_2 = F_186 ( V_7 ) ;
struct V_244 * V_245 = V_129 ;
char * V_246 = V_245 -> V_247 ;
if ( ! F_207 ( V_246 ) ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_61 ,
V_246 ) ;
return - V_248 ;
}
memcpy ( V_7 -> V_135 , V_246 , V_7 -> V_249 ) ;
F_208 ( V_2 ) ;
F_105 ( & V_2 -> V_125 ) ;
V_2 -> type -> V_131 ( V_2 ) ;
F_106 ( & V_2 -> V_125 ) ;
return 0 ;
}
static void F_209 ( struct V_223 * V_7 )
{
struct V_1 * V_2 = F_186 ( V_7 ) ;
if ( V_2 -> V_91 )
F_210 ( V_2 -> V_203 , & V_2 -> V_130 ) ;
}
static int F_211 ( struct V_223 * V_7 , T_6 V_129 )
{
struct V_1 * V_2 = F_186 ( V_7 ) ;
if ( V_7 -> V_250 & ~ V_129 & V_194 )
F_212 ( V_2 , V_251 ) ;
return 0 ;
}
static void F_213 ( struct V_1 * V_2 )
{
strcpy ( V_2 -> V_62 , V_2 -> V_7 -> V_62 ) ;
F_214 ( V_2 ) ;
F_47 ( V_2 ) ;
}
static int F_215 ( struct V_252 * V_253 ,
unsigned long V_254 , void * V_255 )
{
struct V_223 * V_7 = F_216 ( V_255 ) ;
if ( ( V_7 -> V_256 == & V_257 ||
V_7 -> V_256 == & V_258 ) &&
V_254 == V_259 )
F_213 ( F_186 ( V_7 ) ) ;
return V_260 ;
}
static T_7
F_217 ( struct V_261 * V_151 , struct V_262 * V_263 , char * V_58 )
{
struct V_1 * V_2 = F_218 ( F_219 ( V_151 ) ) ;
return sprintf ( V_58 , L_62 , V_2 -> V_264 ) ;
}
static int F_220 ( struct V_1 * V_2 )
{
struct V_223 * V_7 = V_2 -> V_7 ;
struct V_9 * V_10 ;
int V_35 ;
V_7 -> V_265 = 5 * V_266 ;
V_7 -> V_173 = V_2 -> V_147 -> V_173 ;
if ( F_172 ( V_2 ) >= V_267 ) {
V_7 -> V_256 = & V_258 ;
V_7 -> V_268 |= V_269 ;
} else {
V_7 -> V_256 = & V_257 ;
}
F_221 ( V_7 , & V_270 ) ;
V_7 -> V_271 = V_272 ;
F_222 () ;
V_2 -> V_3 = V_273 ;
F_223 () ;
if ( V_2 -> V_274 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_63 ) ;
V_35 = - V_8 ;
goto V_275;
}
V_35 = F_224 ( V_7 , V_7 -> V_62 ) ;
if ( V_35 < 0 )
goto V_275;
F_213 ( V_2 ) ;
F_97 ( V_7 ) ;
V_35 = F_225 ( V_7 ) ;
if ( V_35 )
goto V_275;
F_48 (channel, efx) {
struct V_41 * V_42 ;
F_41 (tx_queue, channel)
F_226 ( V_42 ) ;
}
F_227 () ;
V_35 = F_228 ( & V_2 -> V_147 -> V_151 , & V_276 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_64 ) ;
goto V_277;
}
return 0 ;
V_277:
F_222 () ;
F_229 ( V_7 ) ;
V_275:
V_2 -> V_3 = V_278 ;
F_227 () ;
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_65 ) ;
return V_35 ;
}
static void F_230 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_7 )
return;
F_69 ( F_186 ( V_2 -> V_7 ) != V_2 ) ;
F_231 ( V_2 -> V_62 , F_232 ( V_2 -> V_147 ) , sizeof( V_2 -> V_62 ) ) ;
F_233 ( & V_2 -> V_147 -> V_151 , & V_276 ) ;
F_222 () ;
F_229 ( V_2 -> V_7 ) ;
V_2 -> V_3 = V_278 ;
F_227 () ;
}
void F_234 ( struct V_1 * V_2 , enum V_279 V_280 )
{
F_68 ( V_2 ) ;
F_80 ( V_2 ) ;
F_150 ( V_2 ) ;
F_105 ( & V_2 -> V_125 ) ;
if ( V_2 -> V_141 && V_280 != V_281 )
V_2 -> V_138 -> V_144 ( V_2 ) ;
V_2 -> type -> V_144 ( V_2 ) ;
}
int F_235 ( struct V_1 * V_2 , enum V_279 V_280 , bool V_282 )
{
int V_35 ;
F_68 ( V_2 ) ;
V_35 = V_2 -> type -> V_139 ( V_2 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_66 ) ;
goto V_56;
}
if ( ! V_282 )
goto V_56;
if ( V_2 -> V_141 && V_280 != V_281 ) {
V_35 = V_2 -> V_138 -> V_139 ( V_2 ) ;
if ( V_35 )
goto V_56;
if ( V_2 -> V_138 -> V_142 ( V_2 ) )
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_67 ) ;
}
V_35 = F_148 ( V_2 ) ;
if ( V_35 )
goto V_56;
F_168 ( V_2 ) ;
F_236 ( V_2 ) ;
F_106 ( & V_2 -> V_125 ) ;
F_86 ( V_2 ) ;
return 0 ;
V_56:
V_2 -> V_141 = false ;
F_106 ( & V_2 -> V_125 ) ;
return V_35 ;
}
int F_198 ( struct V_1 * V_2 , enum V_279 V_280 )
{
int V_35 , V_100 ;
bool V_283 ;
F_98 ( V_2 , V_6 , V_2 -> V_7 , L_68 ,
F_237 ( V_280 ) ) ;
F_79 ( V_2 ) ;
F_234 ( V_2 , V_280 ) ;
V_35 = V_2 -> type -> V_284 ( V_2 , V_280 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_69 ) ;
goto V_105;
}
V_2 -> V_274 &= - ( 1 << ( V_280 + 1 ) ) ;
F_118 ( V_2 -> V_147 ) ;
V_105:
V_283 = V_35 ||
V_280 == V_107 ||
V_280 == V_285 ;
V_100 = F_235 ( V_2 , V_280 , ! V_283 ) ;
if ( V_100 ) {
V_283 = true ;
if ( ! V_35 )
V_35 = V_100 ;
}
if ( V_283 ) {
F_238 ( V_2 -> V_7 ) ;
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_70 ) ;
V_2 -> V_3 = V_4 ;
} else {
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_71 ) ;
F_87 ( V_2 -> V_7 ) ;
}
return V_35 ;
}
int F_239 ( struct V_1 * V_2 )
{
#ifdef F_240
struct V_286 * V_287 =
F_241 ( F_242 ( V_2 -> V_147 ) ) ;
if ( F_243 ( V_287 ) ) {
return 1 ;
}
#endif
return 0 ;
}
static void F_244 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = F_11 ( V_129 , struct V_1 , V_288 ) ;
unsigned long V_289 ;
enum V_279 V_280 ;
V_289 = F_245 ( V_2 -> V_274 ) ;
V_280 = F_246 ( V_289 ) - 1 ;
if ( ( V_280 == V_285 ||
V_280 == V_290 ) &&
F_239 ( V_2 ) )
return;
if ( ! V_289 )
return;
F_222 () ;
if ( V_2 -> V_3 == V_273 )
( void ) F_198 ( V_2 , V_280 ) ;
F_227 () ;
}
void F_72 ( struct V_1 * V_2 , enum V_279 type )
{
enum V_279 V_280 ;
if ( V_2 -> V_3 == V_5 ) {
F_18 ( V_2 , V_6 , V_2 -> V_7 ,
L_72 ,
F_237 ( type ) ) ;
return;
}
switch ( type ) {
case V_281 :
case V_94 :
case V_290 :
case V_291 :
case V_107 :
case V_285 :
V_280 = type ;
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_73 ,
F_237 ( V_280 ) ) ;
break;
default:
V_280 = V_2 -> type -> V_292 ( type ) ;
F_18 ( V_2 , V_6 , V_2 -> V_7 ,
L_74 ,
F_237 ( V_280 ) , F_237 ( type ) ) ;
break;
}
F_247 ( V_280 , & V_2 -> V_274 ) ;
F_223 () ;
if ( F_245 ( V_2 -> V_3 ) != V_273 )
return;
F_145 ( V_2 ) ;
F_210 ( V_293 , & V_2 -> V_288 ) ;
}
int F_248 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_249 ( struct V_1 * V_2 ) {}
static bool F_250 ( struct V_1 * V_2 )
{
return false ;
}
static int F_251 ( struct V_1 * V_2 ,
struct V_147 * V_147 , struct V_223 * V_7 )
{
int V_39 ;
F_164 ( & V_2 -> V_294 ) ;
#ifdef F_252
F_253 ( & V_2 -> V_295 ) ;
#endif
F_254 ( & V_2 -> V_288 , F_244 ) ;
F_255 ( & V_2 -> V_204 , F_183 ) ;
F_255 ( & V_2 -> V_296 , V_297 ) ;
V_2 -> V_147 = V_147 ;
V_2 -> V_298 = V_299 ;
V_2 -> V_3 = V_278 ;
F_231 ( V_2 -> V_62 , F_232 ( V_147 ) , sizeof( V_2 -> V_62 ) ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_70 = V_2 -> type -> V_70 ;
V_2 -> V_74 =
V_81 ? ( V_2 -> V_70 + V_81 ) % 4 : 0 ;
V_2 -> V_300 =
V_2 -> type -> V_301 - V_2 -> type -> V_70 ;
F_164 ( & V_2 -> V_238 ) ;
F_256 ( & V_2 -> V_125 ) ;
V_2 -> V_138 = & V_302 ;
V_2 -> V_233 . V_151 = V_7 ;
F_254 ( & V_2 -> V_130 , F_107 ) ;
F_257 ( & V_2 -> V_303 ) ;
for ( V_39 = 0 ; V_39 < V_97 ; V_39 ++ ) {
V_2 -> V_10 [ V_39 ] = F_35 ( V_2 , V_39 , NULL ) ;
if ( ! V_2 -> V_10 [ V_39 ] )
goto V_56;
V_2 -> V_64 [ V_39 ] . V_2 = V_2 ;
V_2 -> V_64 [ V_39 ] . V_102 = V_39 ;
}
V_2 -> V_164 = F_21 ( V_2 -> type -> V_304 ,
V_164 ) ;
snprintf ( V_2 -> V_305 , sizeof( V_2 -> V_305 ) , L_75 ,
F_232 ( V_147 ) ) ;
V_2 -> V_203 = F_258 ( V_2 -> V_305 ) ;
if ( ! V_2 -> V_203 )
goto V_56;
return 0 ;
V_56:
F_259 ( V_2 ) ;
return - V_104 ;
}
static void F_259 ( struct V_1 * V_2 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_97 ; V_39 ++ )
F_84 ( V_2 -> V_10 [ V_39 ] ) ;
if ( V_2 -> V_203 ) {
F_260 ( V_2 -> V_203 ) ;
V_2 -> V_203 = NULL ;
}
}
static void F_261 ( struct V_1 * V_2 )
{
F_69 ( V_2 -> V_3 == V_273 ) ;
F_176 ( & V_2 -> V_288 ) ;
F_150 ( V_2 ) ;
F_262 ( V_2 ) ;
F_114 ( V_2 ) ;
V_2 -> type -> V_144 ( V_2 ) ;
F_193 ( V_2 ) ;
F_178 ( V_2 ) ;
}
static void F_263 ( struct V_147 * V_147 )
{
struct V_1 * V_2 ;
V_2 = F_218 ( V_147 ) ;
if ( ! V_2 )
return;
F_222 () ;
F_238 ( V_2 -> V_7 ) ;
F_150 ( V_2 ) ;
F_227 () ;
F_264 ( V_2 ) ;
F_230 ( V_2 ) ;
F_265 ( V_2 ) ;
F_261 ( V_2 ) ;
F_126 ( V_2 ) ;
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_76 ) ;
F_259 ( V_2 ) ;
F_266 ( V_147 , NULL ) ;
F_267 ( V_2 -> V_7 ) ;
F_268 ( V_147 ) ;
}
static void F_269 ( struct V_1 * V_2 )
{
struct V_147 * V_151 = V_2 -> V_147 ;
char V_306 [ V_307 ] ;
T_7 V_308 ;
int V_39 , V_43 ;
V_308 = F_270 ( V_151 , 0 , sizeof( V_306 ) , V_306 ) ;
if ( V_308 <= 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_77 ) ;
return;
}
V_39 = F_271 ( V_306 , 0 , V_308 , V_309 ) ;
if ( V_39 < 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_78 ) ;
return;
}
V_43 = F_272 ( & V_306 [ V_39 ] ) ;
V_39 += V_310 ;
if ( V_39 + V_43 > V_308 )
V_43 = V_308 - V_39 ;
V_39 = F_273 ( V_306 , V_39 , V_43 , L_79 ) ;
if ( V_39 < 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_80 ) ;
return;
}
V_43 = F_274 ( & V_306 [ V_39 ] ) ;
V_39 += V_311 ;
if ( V_39 + V_43 > V_308 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_81 ) ;
return;
}
F_98 ( V_2 , V_6 , V_2 -> V_7 ,
L_82 , V_43 , & V_306 [ V_39 ] ) ;
}
static int F_275 ( struct V_1 * V_2 )
{
int V_35 ;
V_35 = F_169 ( V_2 ) ;
if ( V_35 )
goto V_140;
F_191 ( V_2 ) ;
V_35 = V_2 -> type -> V_139 ( V_2 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_66 ) ;
goto V_154;
}
V_35 = F_109 ( V_2 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_83 ) ;
goto V_156;
}
V_35 = F_276 ( V_2 ) ;
if ( V_35 )
goto V_312;
V_35 = F_148 ( V_2 ) ;
if ( V_35 )
goto V_313;
return 0 ;
V_313:
F_262 ( V_2 ) ;
V_312:
F_114 ( V_2 ) ;
V_156:
V_2 -> type -> V_144 ( V_2 ) ;
V_154:
F_193 ( V_2 ) ;
F_178 ( V_2 ) ;
V_140:
return V_35 ;
}
static int F_277 ( struct V_147 * V_147 ,
const struct V_314 * V_170 )
{
struct V_223 * V_7 ;
struct V_1 * V_2 ;
int V_35 ;
V_7 = F_278 ( sizeof( * V_2 ) , V_315 ,
V_316 ) ;
if ( ! V_7 )
return - V_104 ;
V_2 = F_186 ( V_7 ) ;
V_2 -> type = ( const struct V_317 * ) V_170 -> V_318 ;
V_7 -> V_250 |= ( V_2 -> type -> V_193 | V_319 |
V_320 | V_321 |
V_322 ) ;
if ( V_2 -> type -> V_193 & V_323 )
V_7 -> V_250 |= V_324 ;
V_7 -> V_325 |= ( V_326 | V_319 |
V_320 | V_327 |
V_322 ) ;
V_7 -> V_328 = V_7 -> V_250 & ~ V_320 ;
F_266 ( V_147 , V_2 ) ;
F_279 ( V_7 , & V_147 -> V_151 ) ;
V_35 = F_251 ( V_2 , V_147 , V_7 ) ;
if ( V_35 )
goto V_140;
F_98 ( V_2 , V_29 , V_2 -> V_7 ,
L_84 ) ;
F_269 ( V_2 ) ;
V_35 = F_116 ( V_2 ) ;
if ( V_35 )
goto V_143;
V_35 = F_275 ( V_2 ) ;
if ( V_35 )
goto V_154;
V_35 = F_220 ( V_2 ) ;
if ( V_35 )
goto V_156;
V_35 = F_280 ( V_2 ) ;
if ( V_35 )
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_85 , V_35 ) ;
F_18 ( V_2 , V_29 , V_2 -> V_7 , L_86 ) ;
F_222 () ;
V_35 = F_281 ( V_2 ) ;
F_227 () ;
if ( V_35 )
F_130 ( V_2 , V_29 , V_2 -> V_7 ,
L_87 , V_35 ) ;
V_35 = F_282 ( V_147 ) ;
if ( V_35 && V_35 != - V_201 )
F_130 ( V_2 , V_29 , V_2 -> V_7 ,
L_88 , V_35 ) ;
return 0 ;
V_156:
F_261 ( V_2 ) ;
V_154:
F_126 ( V_2 ) ;
V_143:
F_259 ( V_2 ) ;
V_140:
F_266 ( V_147 , NULL ) ;
F_63 ( V_35 > 0 ) ;
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_89 , V_35 ) ;
F_267 ( V_7 ) ;
return V_35 ;
}
static int F_283 ( struct V_261 * V_151 )
{
struct V_1 * V_2 = F_218 ( F_219 ( V_151 ) ) ;
F_222 () ;
if ( V_2 -> V_3 != V_4 ) {
V_2 -> V_3 = V_278 ;
F_79 ( V_2 ) ;
F_80 ( V_2 ) ;
F_150 ( V_2 ) ;
}
F_227 () ;
return 0 ;
}
static int F_284 ( struct V_261 * V_151 )
{
int V_35 ;
struct V_1 * V_2 = F_218 ( F_219 ( V_151 ) ) ;
F_222 () ;
if ( V_2 -> V_3 != V_4 ) {
V_35 = F_148 ( V_2 ) ;
if ( V_35 )
goto V_56;
F_105 ( & V_2 -> V_125 ) ;
V_2 -> V_138 -> V_142 ( V_2 ) ;
F_106 ( & V_2 -> V_125 ) ;
F_86 ( V_2 ) ;
F_87 ( V_2 -> V_7 ) ;
V_2 -> V_3 = V_273 ;
V_2 -> type -> V_329 ( V_2 ) ;
}
F_227 () ;
F_210 ( V_293 , & V_2 -> V_288 ) ;
return 0 ;
V_56:
F_227 () ;
return V_35 ;
}
static int F_285 ( struct V_261 * V_151 )
{
struct V_147 * V_147 = F_219 ( V_151 ) ;
struct V_1 * V_2 = F_218 ( V_147 ) ;
V_2 -> type -> V_144 ( V_2 ) ;
V_2 -> V_274 = 0 ;
F_286 ( V_147 ) ;
return F_287 ( V_147 , V_330 ) ;
}
static int F_288 ( struct V_261 * V_151 )
{
struct V_147 * V_147 = F_219 ( V_151 ) ;
struct V_1 * V_2 = F_218 ( V_147 ) ;
int V_35 ;
V_35 = F_287 ( V_147 , V_331 ) ;
if ( V_35 )
return V_35 ;
F_289 ( V_147 ) ;
V_35 = F_117 ( V_147 ) ;
if ( V_35 )
return V_35 ;
F_118 ( V_2 -> V_147 ) ;
V_35 = V_2 -> type -> V_284 ( V_2 , V_94 ) ;
if ( V_35 )
return V_35 ;
V_35 = V_2 -> type -> V_139 ( V_2 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_284 ( V_151 ) ;
return V_35 ;
}
static int F_290 ( struct V_261 * V_151 )
{
int V_35 ;
F_283 ( V_151 ) ;
V_35 = F_285 ( V_151 ) ;
if ( V_35 )
F_288 ( V_151 ) ;
return V_35 ;
}
static T_8 F_291 ( struct V_147 * V_332 ,
enum V_333 V_3 )
{
T_8 V_334 = V_335 ;
struct V_1 * V_2 = F_218 ( V_332 ) ;
if ( V_3 == V_336 )
return V_337 ;
F_222 () ;
if ( V_2 -> V_3 != V_4 ) {
V_2 -> V_3 = V_5 ;
V_2 -> V_274 = 0 ;
F_79 ( V_2 ) ;
F_80 ( V_2 ) ;
F_150 ( V_2 ) ;
V_334 = V_338 ;
} else {
V_334 = V_335 ;
}
F_227 () ;
F_125 ( V_332 ) ;
return V_334 ;
}
static T_8 F_292 ( struct V_147 * V_332 )
{
struct V_1 * V_2 = F_218 ( V_332 ) ;
T_8 V_334 = V_335 ;
int V_35 ;
if ( F_117 ( V_332 ) ) {
F_2 ( V_2 , V_339 , V_2 -> V_7 ,
L_90 ) ;
V_334 = V_337 ;
}
V_35 = F_293 ( V_332 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_339 , V_2 -> V_7 ,
L_91 , V_35 ) ;
}
return V_334 ;
}
static void F_294 ( struct V_147 * V_332 )
{
struct V_1 * V_2 = F_218 ( V_332 ) ;
int V_35 ;
F_222 () ;
if ( V_2 -> V_3 == V_4 )
goto V_105;
V_35 = F_198 ( V_2 , V_94 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_339 , V_2 -> V_7 ,
L_92 , V_35 ) ;
} else {
V_2 -> V_3 = V_273 ;
F_18 ( V_2 , V_339 , V_2 -> V_7 ,
L_93 ) ;
}
V_105:
F_227 () ;
}
static int T_9 F_295 ( void )
{
int V_35 ;
F_296 ( V_340 L_94 V_341 L_95 ) ;
V_35 = F_297 ( & V_342 ) ;
if ( V_35 )
goto V_343;
V_35 = F_298 () ;
if ( V_35 )
goto V_344;
V_293 = F_258 ( L_96 ) ;
if ( ! V_293 ) {
V_35 = - V_104 ;
goto V_345;
}
V_35 = F_299 ( & V_346 ) ;
if ( V_35 < 0 )
goto V_347;
return 0 ;
V_347:
F_260 ( V_293 ) ;
V_345:
F_300 () ;
V_344:
F_301 ( & V_342 ) ;
V_343:
return V_35 ;
}
static void T_10 F_302 ( void )
{
F_296 ( V_340 L_97 ) ;
F_303 ( & V_346 ) ;
F_260 ( V_293 ) ;
F_300 () ;
F_301 ( & V_342 ) ;
}

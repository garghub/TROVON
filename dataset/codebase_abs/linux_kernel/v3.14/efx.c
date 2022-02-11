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
F_29 ( V_10 ) ;
F_9 ( V_15 , false ) ;
F_26 ( V_10 ) ;
}
F_62 ( V_10 -> V_90 ) ;
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
F_68 ( V_2 -> V_91 ) ;
F_69 ( V_2 ) ;
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
if ( V_35 && F_70 ( V_2 ) ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_16 ) ;
F_71 ( V_2 , V_94 ) ;
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
V_10 -> type -> V_95 ( V_10 ) ;
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
F_78 ( V_2 ) ;
F_79 ( V_2 ) ;
F_80 ( V_2 ) ;
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
F_81 ( V_2 -> V_10 [ V_39 ] ) ;
}
V_105:
for ( V_39 = 0 ; V_39 < V_2 -> V_103 ; V_39 ++ ) {
V_10 = V_96 [ V_39 ] ;
if ( V_10 && V_10 -> type -> V_101 ) {
F_82 ( V_10 ) ;
F_45 ( V_10 ) ;
F_83 ( V_10 ) ;
}
}
V_100 = F_84 ( V_2 ) ;
if ( V_100 ) {
V_35 = V_35 ? V_35 : V_100 ;
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_20 ) ;
F_71 ( V_2 , V_107 ) ;
} else {
F_85 ( V_2 ) ;
F_86 ( V_2 -> V_7 ) ;
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
void F_87 ( struct V_14 * V_15 )
{
F_88 ( & V_15 -> V_48 , V_108 + F_89 ( 100 ) ) ;
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
struct V_109 * V_110 = & V_2 -> V_110 ;
if ( ! F_93 ( V_2 -> V_7 ) )
return;
if ( V_110 -> V_111 != F_94 ( V_2 -> V_7 ) ) {
V_2 -> V_112 ++ ;
if ( V_110 -> V_111 )
F_95 ( V_2 -> V_7 ) ;
else
F_96 ( V_2 -> V_7 ) ;
}
if ( V_110 -> V_111 )
F_97 ( V_2 , V_113 , V_2 -> V_7 ,
L_21 ,
V_110 -> V_114 , V_110 -> V_115 ? L_22 : L_23 ,
V_2 -> V_7 -> V_71 ) ;
else
F_97 ( V_2 , V_113 , V_2 -> V_7 , L_24 ) ;
}
void F_98 ( struct V_1 * V_2 , T_2 V_116 )
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
void F_99 ( struct V_1 * V_2 , T_3 V_119 )
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
int F_100 ( struct V_1 * V_2 )
{
enum V_123 V_124 ;
int V_35 ;
F_62 ( ! F_101 ( & V_2 -> V_125 ) ) ;
V_124 = V_2 -> V_124 ;
if ( F_102 ( V_2 ) )
V_2 -> V_124 |= V_126 ;
else
V_2 -> V_124 &= ~ V_126 ;
V_35 = V_2 -> type -> V_127 ( V_2 ) ;
if ( V_35 )
V_2 -> V_124 = V_124 ;
return V_35 ;
}
int F_103 ( struct V_1 * V_2 )
{
int V_35 ;
F_67 ( V_2 ) ;
F_104 ( & V_2 -> V_125 ) ;
V_35 = F_100 ( V_2 ) ;
F_105 ( & V_2 -> V_125 ) ;
return V_35 ;
}
static void F_106 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = F_11 ( V_129 , struct V_1 , V_130 ) ;
F_104 ( & V_2 -> V_125 ) ;
if ( V_2 -> V_91 )
V_2 -> type -> V_131 ( V_2 ) ;
F_105 ( & V_2 -> V_125 ) ;
}
static int F_107 ( struct V_1 * V_2 )
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
static int F_108 ( struct V_1 * V_2 )
{
int V_35 ;
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_26 ) ;
F_104 ( & V_2 -> V_125 ) ;
V_35 = V_2 -> V_138 -> V_139 ( V_2 ) ;
if ( V_35 )
goto V_140;
V_2 -> V_141 = true ;
V_2 -> type -> V_131 ( V_2 ) ;
V_35 = V_2 -> V_138 -> V_142 ( V_2 ) ;
if ( V_35 )
goto V_143;
F_105 ( & V_2 -> V_125 ) ;
return 0 ;
V_143:
V_2 -> V_138 -> V_144 ( V_2 ) ;
V_140:
F_105 ( & V_2 -> V_125 ) ;
return V_35 ;
}
static void F_109 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_38 , V_2 -> V_7 , L_27 ) ;
F_68 ( V_2 -> V_91 ) ;
F_104 ( & V_2 -> V_125 ) ;
V_2 -> V_91 = true ;
V_2 -> type -> V_131 ( V_2 ) ;
F_105 ( & V_2 -> V_125 ) ;
}
static void F_110 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_145 , V_2 -> V_7 , L_28 ) ;
F_67 ( V_2 ) ;
F_104 ( & V_2 -> V_125 ) ;
V_2 -> V_91 = false ;
F_105 ( & V_2 -> V_125 ) ;
F_111 ( V_2 -> V_7 ) ;
F_112 ( V_2 -> V_7 ) ;
F_113 ( & V_2 -> V_146 ) ;
F_114 ( V_2 ) ;
F_115 ( & V_2 -> V_130 ) ;
}
static void F_116 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_29 ) ;
if ( ! V_2 -> V_141 )
return;
V_2 -> V_138 -> V_144 ( V_2 ) ;
V_2 -> V_141 = false ;
V_2 -> V_110 . V_111 = false ;
F_92 ( V_2 ) ;
}
static void F_117 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_30 ) ;
V_2 -> type -> V_147 ( V_2 ) ;
}
static bool F_118 ( struct V_1 * V_148 , struct V_1 * V_149 )
{
return V_148 -> type == V_149 -> type &&
V_148 -> V_150 && V_149 -> V_150 &&
! strcmp ( V_148 -> V_150 , V_149 -> V_150 ) ;
}
static void F_119 ( struct V_1 * V_2 )
{
struct V_1 * V_151 , * V_152 ;
if ( V_2 -> V_153 == V_2 ) {
F_18 ( V_2 , V_29 , V_2 -> V_7 , L_31 ) ;
F_120 ( & V_2 -> V_154 , & V_155 ) ;
F_121 (other, next, &efx_unassociated_list,
node) {
if ( F_118 ( V_2 , V_151 ) ) {
F_122 ( & V_151 -> V_154 ) ;
F_18 ( V_151 , V_29 , V_151 -> V_7 ,
L_32 ,
F_123 ( V_2 -> V_156 ) ,
V_2 -> V_7 -> V_62 ) ;
F_120 ( & V_151 -> V_154 ,
& V_2 -> V_157 ) ;
V_151 -> V_153 = V_2 ;
}
}
} else {
F_124 (other, &efx_primary_list, node) {
if ( F_118 ( V_2 , V_151 ) ) {
F_18 ( V_2 , V_29 , V_2 -> V_7 ,
L_33 ,
F_123 ( V_151 -> V_156 ) ,
V_151 -> V_7 -> V_62 ) ;
F_120 ( & V_2 -> V_154 ,
& V_151 -> V_157 ) ;
V_2 -> V_153 = V_151 ;
return;
}
}
F_18 ( V_2 , V_29 , V_2 -> V_7 ,
L_34 ) ;
F_120 ( & V_2 -> V_154 , & V_158 ) ;
}
}
static void F_125 ( struct V_1 * V_2 )
{
struct V_1 * V_151 , * V_152 ;
F_122 ( & V_2 -> V_154 ) ;
V_2 -> V_153 = NULL ;
F_121 (other, next, &efx->secondary_list, node) {
F_122 ( & V_151 -> V_154 ) ;
F_18 ( V_151 , V_29 , V_151 -> V_7 ,
L_35 ) ;
F_120 ( & V_151 -> V_154 , & V_158 ) ;
V_151 -> V_153 = NULL ;
}
}
static int F_126 ( struct V_1 * V_2 )
{
struct V_156 * V_156 = V_2 -> V_156 ;
T_4 V_159 = V_2 -> type -> V_160 ;
unsigned int V_161 = V_2 -> type -> V_161 ( V_2 ) ;
int V_35 ;
F_18 ( V_2 , V_29 , V_2 -> V_7 , L_36 ) ;
V_35 = F_127 ( V_156 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_37 ) ;
goto V_140;
}
F_128 ( V_156 ) ;
while ( V_159 > 0x7fffffffUL ) {
if ( F_129 ( & V_156 -> V_162 , V_159 ) ) {
V_35 = F_130 ( & V_156 -> V_162 , V_159 ) ;
if ( V_35 == 0 )
break;
}
V_159 >>= 1 ;
}
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_38 ) ;
goto V_143;
}
F_18 ( V_2 , V_29 , V_2 -> V_7 ,
L_39 , ( unsigned long long ) V_159 ) ;
V_2 -> V_163 = F_131 ( V_2 -> V_156 , V_164 ) ;
V_35 = F_132 ( V_156 , V_164 , L_40 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_41 ) ;
V_35 = - V_8 ;
goto V_165;
}
V_2 -> V_166 = F_133 ( V_2 -> V_163 , V_161 ) ;
if ( ! V_2 -> V_166 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_42 ,
( unsigned long long ) V_2 -> V_163 , V_161 ) ;
V_35 = - V_104 ;
goto V_167;
}
F_18 ( V_2 , V_29 , V_2 -> V_7 ,
L_43 ,
( unsigned long long ) V_2 -> V_163 , V_161 ,
V_2 -> V_166 ) ;
return 0 ;
V_167:
F_134 ( V_2 -> V_156 , V_164 ) ;
V_165:
V_2 -> V_163 = 0 ;
V_143:
F_135 ( V_2 -> V_156 ) ;
V_140:
return V_35 ;
}
static void F_136 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_44 ) ;
if ( V_2 -> V_166 ) {
F_137 ( V_2 -> V_166 ) ;
V_2 -> V_166 = NULL ;
}
if ( V_2 -> V_163 ) {
F_134 ( V_2 -> V_156 , V_164 ) ;
V_2 -> V_163 = 0 ;
}
F_135 ( V_2 -> V_156 ) ;
}
static unsigned int F_138 ( struct V_1 * V_2 )
{
T_5 V_168 ;
unsigned int V_169 ;
int V_170 ;
if ( V_171 ) {
V_169 = V_171 ;
} else {
if ( F_4 ( ! F_139 ( & V_168 , V_44 ) ) ) {
F_140 ( V_2 , V_29 , V_2 -> V_7 ,
L_45 ) ;
return 1 ;
}
V_169 = 0 ;
F_141 (cpu) {
if ( ! F_142 ( V_170 , V_168 ) ) {
++ V_169 ;
F_143 ( V_168 , V_168 ,
F_144 ( V_170 ) ) ;
}
}
F_145 ( V_168 ) ;
}
if ( F_146 ( V_2 ) && F_147 ( V_2 ) > 1 &&
V_169 > F_147 ( V_2 ) ) {
F_140 ( V_2 , V_29 , V_2 -> V_7 ,
L_46
L_47
L_48 ,
V_169 , F_147 ( V_2 ) ) ;
V_169 = F_147 ( V_2 ) ;
}
return V_169 ;
}
static int F_148 ( struct V_1 * V_2 )
{
unsigned int V_172 = 0 ;
unsigned int V_39 , V_43 ;
int V_35 ;
for ( V_39 = 0 ; V_39 < V_173 ; V_39 ++ )
if ( V_2 -> V_174 [ V_39 ] )
++ V_172 ;
if ( V_2 -> V_175 == V_176 ) {
struct V_177 V_178 [ V_97 ] ;
unsigned int V_103 ;
V_103 = F_138 ( V_2 ) ;
if ( V_179 )
V_103 *= 2 ;
V_103 += V_172 ;
V_103 = F_149 ( V_103 , V_2 -> V_180 ) ;
for ( V_39 = 0 ; V_39 < V_103 ; V_39 ++ )
V_178 [ V_39 ] . V_181 = V_39 ;
V_35 = F_150 ( V_2 -> V_156 , V_178 , V_103 ) ;
if ( V_35 > 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_49
L_50 , V_35 , V_103 ) ;
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_51 ) ;
F_20 ( V_35 >= V_103 ) ;
V_103 = V_35 ;
V_35 = F_150 ( V_2 -> V_156 , V_178 ,
V_103 ) ;
}
if ( V_35 == 0 ) {
V_2 -> V_103 = V_103 ;
if ( V_103 > V_172 )
V_103 -= V_172 ;
if ( V_179 ) {
V_2 -> V_182 = F_21 ( V_103 / 2 , 1U ) ;
V_2 -> V_183 = F_21 ( V_103 -
V_2 -> V_182 ,
1U ) ;
} else {
V_2 -> V_182 = V_103 ;
V_2 -> V_183 = V_103 ;
}
for ( V_39 = 0 ; V_39 < V_2 -> V_103 ; V_39 ++ )
F_151 ( V_2 , V_39 ) -> V_184 =
V_178 [ V_39 ] . V_185 ;
} else {
V_2 -> V_175 = V_186 ;
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_52 ) ;
}
}
if ( V_2 -> V_175 == V_186 ) {
V_2 -> V_103 = 1 ;
V_2 -> V_183 = 1 ;
V_2 -> V_182 = 1 ;
V_35 = F_152 ( V_2 -> V_156 ) ;
if ( V_35 == 0 ) {
F_151 ( V_2 , 0 ) -> V_184 = V_2 -> V_156 -> V_184 ;
} else {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_53 ) ;
V_2 -> V_175 = V_187 ;
}
}
if ( V_2 -> V_175 == V_187 ) {
V_2 -> V_103 = 1 + ( V_179 ? 1 : 0 ) ;
V_2 -> V_183 = 1 ;
V_2 -> V_182 = 1 ;
V_2 -> V_188 = V_2 -> V_156 -> V_184 ;
}
V_43 = V_2 -> V_103 ;
for ( V_39 = 0 ; V_39 < V_173 ; V_39 ++ ) {
if ( ! V_2 -> V_174 [ V_39 ] )
continue;
if ( V_2 -> V_175 != V_176 ||
V_2 -> V_103 <= V_172 ) {
V_2 -> V_174 [ V_39 ] -> F_153 ( V_2 ) ;
} else {
-- V_43 ;
F_151 ( V_2 , V_43 ) -> type =
V_2 -> V_174 [ V_39 ] ;
}
}
V_2 -> V_189 = ( ( V_2 -> V_183 > 1 || ! F_146 ( V_2 ) ) ?
V_2 -> V_183 : F_147 ( V_2 ) ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 )
{
struct V_9 * V_10 , * V_190 ;
int V_35 ;
F_68 ( V_2 -> V_3 == V_4 ) ;
V_2 -> V_191 = true ;
F_27 () ;
F_48 (channel, efx) {
if ( ! V_10 -> type -> V_192 ) {
V_35 = F_23 ( V_10 ) ;
if ( V_35 )
goto V_56;
}
F_26 ( V_10 ) ;
}
F_154 ( V_2 ) ;
return 0 ;
V_56:
V_190 = V_10 ;
F_48 (channel, efx) {
if ( V_10 == V_190 )
break;
F_29 ( V_10 ) ;
if ( ! V_10 -> type -> V_192 )
F_31 ( V_10 ) ;
}
return V_35 ;
}
static void F_80 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
if ( V_2 -> V_3 == V_4 )
return;
F_155 ( V_2 ) ;
V_2 -> V_191 = false ;
F_27 () ;
if ( V_2 -> V_188 )
F_156 ( V_2 -> V_188 ) ;
F_48 (channel, efx) {
if ( V_10 -> V_184 )
F_156 ( V_10 -> V_184 ) ;
F_29 ( V_10 ) ;
if ( ! V_10 -> type -> V_192 )
F_31 ( V_10 ) ;
}
F_157 ( V_2 ) ;
}
static int F_158 ( struct V_1 * V_2 )
{
struct V_9 * V_10 , * V_190 ;
int V_35 ;
F_68 ( V_2 -> V_3 == V_4 ) ;
if ( V_2 -> V_193 ) {
F_159 ( V_2 -> V_188 ) ;
V_2 -> V_193 = false ;
}
V_2 -> type -> V_194 ( V_2 ) ;
F_48 (channel, efx) {
if ( V_10 -> type -> V_192 ) {
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
V_190 = V_10 ;
F_48 (channel, efx) {
if ( V_10 == V_190 )
break;
if ( V_10 -> type -> V_192 )
F_31 ( V_10 ) ;
}
V_2 -> type -> V_195 ( V_2 ) ;
return V_35 ;
}
static void F_160 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_80 ( V_2 ) ;
F_48 (channel, efx) {
if ( V_10 -> type -> V_192 )
F_31 ( V_10 ) ;
}
V_2 -> type -> V_195 ( V_2 ) ;
}
static void F_161 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_48 (channel, efx)
V_10 -> V_184 = 0 ;
F_162 ( V_2 -> V_156 ) ;
F_163 ( V_2 -> V_156 ) ;
V_2 -> V_188 = 0 ;
}
static void F_164 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_41 * V_42 ;
V_2 -> V_61 =
V_179 ? V_2 -> V_103 - V_2 -> V_182 : 0 ;
F_48 (channel, efx) {
if ( V_10 -> V_10 < V_2 -> V_183 )
V_10 -> V_15 . V_196 = V_10 -> V_10 ;
else
V_10 -> V_15 . V_196 = - 1 ;
F_41 (tx_queue, channel)
V_42 -> V_47 -= ( V_2 -> V_61 *
V_46 ) ;
}
}
static int F_165 ( struct V_1 * V_2 )
{
T_1 V_39 ;
int V_35 ;
F_18 ( V_2 , V_29 , V_2 -> V_7 , L_54 ) ;
V_35 = V_2 -> type -> V_29 ( V_2 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_148 ( V_2 ) ;
if ( V_35 )
goto V_140;
V_35 = V_2 -> type -> V_197 ( V_2 ) ;
if ( V_35 )
goto V_143;
if ( V_2 -> V_103 > 1 )
F_166 ( & V_2 -> V_198 , sizeof( V_2 -> V_198 ) ) ;
for ( V_39 = 0 ; V_39 < F_167 ( V_2 -> V_199 ) ; V_39 ++ )
V_2 -> V_199 [ V_39 ] =
F_168 ( V_39 , V_2 -> V_189 ) ;
F_164 ( V_2 ) ;
F_169 ( V_2 -> V_7 , V_2 -> V_182 ) ;
F_170 ( V_2 -> V_7 , V_2 -> V_183 ) ;
F_171 ( V_2 , V_200 , V_201 , true ,
true ) ;
return 0 ;
V_143:
F_161 ( V_2 ) ;
V_140:
V_2 -> type -> remove ( V_2 ) ;
return V_35 ;
}
static void F_172 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_55 ) ;
F_161 ( V_2 ) ;
V_2 -> type -> remove ( V_2 ) ;
}
static int F_173 ( struct V_1 * V_2 )
{
int V_35 ;
F_174 ( & V_2 -> V_202 ) ;
V_35 = V_2 -> type -> V_203 ( V_2 ) ;
if ( V_35 )
return V_35 ;
#ifdef F_175
if ( V_2 -> type -> V_204 & V_205 ) {
V_2 -> V_206 = F_176 ( V_2 -> type -> V_207 ,
sizeof( * V_2 -> V_206 ) ,
V_44 ) ;
if ( ! V_2 -> V_206 ) {
V_2 -> type -> V_208 ( V_2 ) ;
return - V_104 ;
}
}
#endif
return 0 ;
}
static void F_177 ( struct V_1 * V_2 )
{
#ifdef F_175
F_83 ( V_2 -> V_206 ) ;
#endif
V_2 -> type -> V_208 ( V_2 ) ;
}
static void F_178 ( struct V_1 * V_2 )
{
V_2 -> type -> V_209 ( V_2 ) ;
}
static int F_179 ( struct V_1 * V_2 )
{
int V_35 ;
V_35 = F_165 ( V_2 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 , L_56 ) ;
goto V_140;
}
V_35 = F_107 ( V_2 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 , L_57 ) ;
goto V_143;
}
F_54 ( V_210 < V_211 ) ;
if ( F_62 ( V_210 < F_180 ( V_2 ) ) ) {
V_35 = - V_212 ;
goto V_165;
}
V_2 -> V_30 = V_2 -> V_31 = V_210 ;
V_35 = F_173 ( V_2 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_58 ) ;
goto V_165;
}
V_35 = F_49 ( V_2 ) ;
if ( V_35 )
goto V_167;
return 0 ;
V_167:
F_177 ( V_2 ) ;
V_165:
F_117 ( V_2 ) ;
V_143:
F_172 ( V_2 ) ;
V_140:
return V_35 ;
}
static void F_85 ( struct V_1 * V_2 )
{
F_67 ( V_2 ) ;
F_68 ( V_2 -> V_3 == V_4 ) ;
if ( V_2 -> V_91 || ! F_93 ( V_2 -> V_7 ) )
return;
F_109 ( V_2 ) ;
F_52 ( V_2 ) ;
if ( V_2 -> type -> V_213 != NULL )
F_181 ( V_2 -> V_214 , & V_2 -> V_146 ,
V_215 ) ;
if ( F_182 ( V_2 ) >= V_216 ) {
F_104 ( & V_2 -> V_125 ) ;
if ( V_2 -> V_138 -> V_217 ( V_2 ) )
F_92 ( V_2 ) ;
F_105 ( & V_2 -> V_125 ) ;
}
V_2 -> type -> V_218 ( V_2 ) ;
V_2 -> type -> V_219 ( V_2 ) ;
F_183 ( & V_2 -> V_220 ) ;
V_2 -> type -> V_221 ( V_2 , NULL , NULL ) ;
F_184 ( & V_2 -> V_220 ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
F_67 ( V_2 ) ;
if ( ! V_2 -> V_91 )
return;
V_2 -> type -> V_219 ( V_2 ) ;
F_183 ( & V_2 -> V_220 ) ;
V_2 -> type -> V_221 ( V_2 , NULL , NULL ) ;
F_184 ( & V_2 -> V_220 ) ;
V_2 -> type -> V_222 ( V_2 ) ;
F_110 ( V_2 ) ;
F_62 ( F_93 ( V_2 -> V_7 ) &&
F_64 ( V_2 -> V_7 ) ) ;
F_185 ( V_2 -> V_7 ) ;
F_66 ( V_2 ) ;
}
static void F_186 ( struct V_1 * V_2 )
{
F_51 ( V_2 ) ;
F_177 ( V_2 ) ;
F_117 ( V_2 ) ;
F_172 ( V_2 ) ;
}
static unsigned int F_187 ( unsigned int V_223 , unsigned int V_224 )
{
if ( V_223 == 0 )
return 0 ;
if ( V_223 * 1000 < V_224 )
return 1 ;
return V_223 * 1000 / V_224 ;
}
int F_171 ( struct V_1 * V_2 , unsigned int V_225 ,
unsigned int V_226 , bool V_227 ,
bool V_228 )
{
struct V_9 * V_10 ;
unsigned int V_229 = F_188 ( V_2 -> type -> V_230 *
V_2 -> V_231 ,
1000 ) ;
unsigned int V_232 ;
unsigned int V_233 ;
F_67 ( V_2 ) ;
if ( V_225 > V_229 || V_226 > V_229 )
return - V_212 ;
V_232 = F_187 ( V_225 , V_2 -> V_231 ) ;
V_233 = F_187 ( V_226 , V_2 -> V_231 ) ;
if ( V_232 != V_233 && V_2 -> V_61 == 0 &&
! V_228 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_59
L_60 ) ;
return - V_212 ;
}
V_2 -> V_20 = V_227 ;
V_2 -> V_27 = V_233 ;
F_48 (channel, efx) {
if ( F_6 ( V_10 ) )
V_10 -> V_24 = V_233 ;
else if ( F_189 ( V_10 ) )
V_10 -> V_24 = V_232 ;
}
return 0 ;
}
void F_190 ( struct V_1 * V_2 , unsigned int * V_225 ,
unsigned int * V_226 , bool * V_227 )
{
* V_227 = V_2 -> V_20 ;
* V_226 = F_188 ( V_2 -> V_27 *
V_2 -> V_231 ,
1000 ) ;
if ( V_2 -> V_61 == 0 )
* V_225 = * V_226 ;
else
* V_225 = F_188 (
V_2 -> V_10 [ V_2 -> V_61 ] -> V_24 *
V_2 -> V_231 ,
1000 ) ;
}
static void F_191 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = F_11 ( V_129 , struct V_1 ,
V_146 . V_234 ) ;
F_12 ( V_2 , V_235 , V_2 -> V_7 ,
L_61 ,
F_13 () ) ;
F_68 ( V_2 -> type -> V_213 == NULL ) ;
if ( F_192 ( & V_2 -> V_125 ) ) {
if ( V_2 -> V_91 )
V_2 -> type -> V_213 ( V_2 ) ;
F_105 ( & V_2 -> V_125 ) ;
}
F_181 ( V_2 -> V_214 , & V_2 -> V_146 ,
V_215 ) ;
}
static int F_193 ( struct V_236 * V_7 , struct V_237 * V_238 , int V_239 )
{
struct V_1 * V_2 = F_194 ( V_7 ) ;
struct V_240 * V_129 = F_195 ( V_238 ) ;
if ( V_239 == V_241 )
return F_196 ( V_2 , V_238 ) ;
if ( V_239 == V_242 )
return F_197 ( V_2 , V_238 ) ;
if ( ( V_239 == V_243 || V_239 == V_244 ) &&
( V_129 -> V_245 & 0xfc00 ) == 0x0400 )
V_129 -> V_245 ^= V_246 | 0x0400 ;
return F_198 ( & V_2 -> V_247 , V_129 , V_239 ) ;
}
static void F_81 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
V_10 -> V_50 = V_2 -> V_7 ;
F_199 ( V_10 -> V_50 , & V_10 -> V_18 ,
F_10 , V_248 ) ;
}
static void F_200 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_48 (channel, efx)
F_81 ( V_10 ) ;
}
static void F_82 ( struct V_9 * V_10 )
{
if ( V_10 -> V_50 )
F_201 ( & V_10 -> V_18 ) ;
V_10 -> V_50 = NULL ;
}
static void F_202 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_48 (channel, efx)
F_82 ( V_10 ) ;
}
static void F_203 ( struct V_236 * V_7 )
{
struct V_1 * V_2 = F_194 ( V_7 ) ;
struct V_9 * V_10 ;
F_48 (channel, efx)
F_204 ( V_10 ) ;
}
static int F_205 ( struct V_236 * V_7 )
{
struct V_1 * V_2 = F_194 ( V_7 ) ;
int V_35 ;
F_18 ( V_2 , V_38 , V_2 -> V_7 , L_62 ,
F_13 () ) ;
V_35 = F_1 ( V_2 ) ;
if ( V_35 )
return V_35 ;
if ( V_2 -> V_124 & V_133 )
return - V_249 ;
if ( F_206 ( V_2 ) && F_207 ( V_2 , V_94 ) )
return - V_8 ;
F_92 ( V_2 ) ;
F_85 ( V_2 ) ;
F_208 ( V_2 ) ;
return 0 ;
}
static int F_209 ( struct V_236 * V_7 )
{
struct V_1 * V_2 = F_194 ( V_7 ) ;
F_18 ( V_2 , V_145 , V_2 -> V_7 , L_63 ,
F_13 () ) ;
F_79 ( V_2 ) ;
return 0 ;
}
static struct V_250 * F_210 ( struct V_236 * V_7 ,
struct V_250 * V_251 )
{
struct V_1 * V_2 = F_194 ( V_7 ) ;
F_183 ( & V_2 -> V_220 ) ;
V_2 -> type -> V_221 ( V_2 , NULL , V_251 ) ;
F_184 ( & V_2 -> V_220 ) ;
return V_251 ;
}
static void F_211 ( struct V_236 * V_7 )
{
struct V_1 * V_2 = F_194 ( V_7 ) ;
F_2 ( V_2 , V_252 , V_2 -> V_7 ,
L_64 ,
V_2 -> V_91 ) ;
F_71 ( V_2 , V_253 ) ;
}
static int F_212 ( struct V_236 * V_7 , int V_254 )
{
struct V_1 * V_2 = F_194 ( V_7 ) ;
int V_35 ;
V_35 = F_1 ( V_2 ) ;
if ( V_35 )
return V_35 ;
if ( V_254 > V_255 )
return - V_212 ;
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_65 , V_254 ) ;
F_78 ( V_2 ) ;
F_79 ( V_2 ) ;
F_104 ( & V_2 -> V_125 ) ;
V_7 -> V_71 = V_254 ;
V_2 -> type -> V_131 ( V_2 ) ;
F_105 ( & V_2 -> V_125 ) ;
F_85 ( V_2 ) ;
F_86 ( V_2 -> V_7 ) ;
return 0 ;
}
static int F_213 ( struct V_236 * V_7 , void * V_129 )
{
struct V_1 * V_2 = F_194 ( V_7 ) ;
struct V_256 * V_257 = V_129 ;
char * V_258 = V_257 -> V_259 ;
if ( ! F_214 ( V_258 ) ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_66 ,
V_258 ) ;
return - V_260 ;
}
memcpy ( V_7 -> V_135 , V_258 , V_7 -> V_261 ) ;
F_215 ( V_2 ) ;
F_104 ( & V_2 -> V_125 ) ;
V_2 -> type -> V_131 ( V_2 ) ;
F_105 ( & V_2 -> V_125 ) ;
return 0 ;
}
static void F_216 ( struct V_236 * V_7 )
{
struct V_1 * V_2 = F_194 ( V_7 ) ;
if ( V_2 -> V_91 )
F_217 ( V_2 -> V_214 , & V_2 -> V_130 ) ;
}
static int F_218 ( struct V_236 * V_7 , T_6 V_129 )
{
struct V_1 * V_2 = F_194 ( V_7 ) ;
if ( V_7 -> V_262 & ~ V_129 & V_205 )
return V_2 -> type -> V_263 ( V_2 , V_264 ) ;
return 0 ;
}
static void F_219 ( struct V_1 * V_2 )
{
strcpy ( V_2 -> V_62 , V_2 -> V_7 -> V_62 ) ;
F_220 ( V_2 ) ;
F_47 ( V_2 ) ;
}
static int F_221 ( struct V_265 * V_266 ,
unsigned long V_267 , void * V_268 )
{
struct V_236 * V_7 = F_222 ( V_268 ) ;
if ( ( V_7 -> V_269 == & V_270 ||
V_7 -> V_269 == & V_271 ) &&
V_267 == V_272 )
F_219 ( F_194 ( V_7 ) ) ;
return V_273 ;
}
static T_7
F_223 ( struct V_274 * V_162 , struct V_275 * V_276 , char * V_58 )
{
struct V_1 * V_2 = F_224 ( F_225 ( V_162 ) ) ;
return sprintf ( V_58 , L_67 , V_2 -> V_277 ) ;
}
static int F_226 ( struct V_1 * V_2 )
{
struct V_236 * V_7 = V_2 -> V_7 ;
struct V_9 * V_10 ;
int V_35 ;
V_7 -> V_278 = 5 * V_279 ;
V_7 -> V_184 = V_2 -> V_156 -> V_184 ;
if ( F_182 ( V_2 ) >= V_280 ) {
V_7 -> V_269 = & V_271 ;
V_7 -> V_281 |= V_282 ;
} else {
V_7 -> V_269 = & V_270 ;
}
F_227 ( V_7 , & V_283 ) ;
V_7 -> V_284 = V_285 ;
F_228 () ;
V_2 -> V_3 = V_286 ;
F_229 () ;
if ( V_2 -> V_287 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_68 ) ;
V_35 = - V_8 ;
goto V_288;
}
V_35 = F_230 ( V_7 , V_7 -> V_62 ) ;
if ( V_35 < 0 )
goto V_288;
F_219 ( V_2 ) ;
F_96 ( V_7 ) ;
V_35 = F_231 ( V_7 ) ;
if ( V_35 )
goto V_288;
F_48 (channel, efx) {
struct V_41 * V_42 ;
F_41 (tx_queue, channel)
F_232 ( V_42 ) ;
}
F_119 ( V_2 ) ;
F_233 () ;
V_35 = F_234 ( & V_2 -> V_156 -> V_162 , & V_289 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_69 ) ;
goto V_290;
}
return 0 ;
V_290:
F_228 () ;
F_125 ( V_2 ) ;
F_235 ( V_7 ) ;
V_288:
V_2 -> V_3 = V_291 ;
F_233 () ;
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_70 ) ;
return V_35 ;
}
static void F_236 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_7 )
return;
F_68 ( F_194 ( V_2 -> V_7 ) != V_2 ) ;
F_237 ( V_2 -> V_62 , F_123 ( V_2 -> V_156 ) , sizeof( V_2 -> V_62 ) ) ;
F_238 ( & V_2 -> V_156 -> V_162 , & V_289 ) ;
F_228 () ;
F_235 ( V_2 -> V_7 ) ;
V_2 -> V_3 = V_291 ;
F_233 () ;
}
void F_239 ( struct V_1 * V_2 , enum V_292 V_293 )
{
F_67 ( V_2 ) ;
F_79 ( V_2 ) ;
F_160 ( V_2 ) ;
F_104 ( & V_2 -> V_125 ) ;
if ( V_2 -> V_141 && V_293 != V_294 )
V_2 -> V_138 -> V_144 ( V_2 ) ;
V_2 -> type -> V_144 ( V_2 ) ;
}
int F_240 ( struct V_1 * V_2 , enum V_292 V_293 , bool V_295 )
{
int V_35 ;
F_67 ( V_2 ) ;
V_35 = V_2 -> type -> V_139 ( V_2 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_71 ) ;
goto V_56;
}
if ( ! V_295 )
goto V_56;
if ( V_2 -> V_141 && V_293 != V_294 ) {
V_35 = V_2 -> V_138 -> V_139 ( V_2 ) ;
if ( V_35 )
goto V_56;
if ( V_2 -> V_138 -> V_142 ( V_2 ) )
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_72 ) ;
}
V_35 = F_158 ( V_2 ) ;
if ( V_35 )
goto V_56;
F_178 ( V_2 ) ;
F_241 ( V_2 ) ;
F_105 ( & V_2 -> V_125 ) ;
F_85 ( V_2 ) ;
return 0 ;
V_56:
V_2 -> V_141 = false ;
F_105 ( & V_2 -> V_125 ) ;
return V_35 ;
}
int F_207 ( struct V_1 * V_2 , enum V_292 V_293 )
{
int V_35 , V_100 ;
bool V_296 ;
F_97 ( V_2 , V_6 , V_2 -> V_7 , L_73 ,
F_242 ( V_293 ) ) ;
F_78 ( V_2 ) ;
F_239 ( V_2 , V_293 ) ;
V_35 = V_2 -> type -> V_297 ( V_2 , V_293 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_74 ) ;
goto V_105;
}
V_2 -> V_287 &= - ( 1 << ( V_293 + 1 ) ) ;
F_128 ( V_2 -> V_156 ) ;
V_105:
V_296 = V_35 ||
V_293 == V_107 ||
V_293 == V_298 ;
V_100 = F_240 ( V_2 , V_293 , ! V_296 ) ;
if ( V_100 ) {
V_296 = true ;
if ( ! V_35 )
V_35 = V_100 ;
}
if ( V_296 ) {
F_243 ( V_2 -> V_7 ) ;
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_75 ) ;
V_2 -> V_3 = V_4 ;
} else {
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_76 ) ;
F_86 ( V_2 -> V_7 ) ;
}
return V_35 ;
}
int F_244 ( struct V_1 * V_2 )
{
#ifdef F_245
struct V_299 * V_300 =
F_246 ( F_247 ( V_2 -> V_156 ) ) ;
if ( F_248 ( V_300 ) ) {
return 1 ;
}
#endif
return 0 ;
}
static void F_249 ( struct V_1 * V_2 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_301 ; ++ V_39 ) {
if ( F_206 ( V_2 ) )
goto V_105;
F_250 ( V_302 ) ;
}
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_77 ) ;
V_105:
V_2 -> V_303 = false ;
}
static void F_251 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = F_11 ( V_129 , struct V_1 , V_304 ) ;
unsigned long V_305 ;
enum V_292 V_293 ;
V_305 = F_252 ( V_2 -> V_287 ) ;
V_293 = F_253 ( V_305 ) - 1 ;
if ( V_293 == V_306 )
F_249 ( V_2 ) ;
if ( ( V_293 == V_298 ||
V_293 == V_307 ) &&
F_244 ( V_2 ) )
return;
if ( ! V_305 )
return;
F_228 () ;
if ( V_2 -> V_3 == V_286 )
( void ) F_207 ( V_2 , V_293 ) ;
F_233 () ;
}
void F_71 ( struct V_1 * V_2 , enum V_292 type )
{
enum V_292 V_293 ;
if ( V_2 -> V_3 == V_5 ) {
F_18 ( V_2 , V_6 , V_2 -> V_7 ,
L_78 ,
F_242 ( type ) ) ;
return;
}
switch ( type ) {
case V_294 :
case V_94 :
case V_307 :
case V_308 :
case V_107 :
case V_298 :
case V_306 :
V_293 = type ;
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_79 ,
F_242 ( V_293 ) ) ;
break;
default:
V_293 = V_2 -> type -> V_309 ( type ) ;
F_18 ( V_2 , V_6 , V_2 -> V_7 ,
L_80 ,
F_242 ( V_293 ) , F_242 ( type ) ) ;
break;
}
F_254 ( V_293 , & V_2 -> V_287 ) ;
F_229 () ;
if ( F_252 ( V_2 -> V_3 ) != V_286 )
return;
F_155 ( V_2 ) ;
F_217 ( V_310 , & V_2 -> V_304 ) ;
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
struct V_156 * V_156 , struct V_236 * V_7 )
{
int V_39 ;
F_259 ( & V_2 -> V_154 ) ;
F_259 ( & V_2 -> V_157 ) ;
F_174 ( & V_2 -> V_311 ) ;
#ifdef F_260
F_259 ( & V_2 -> V_312 ) ;
#endif
F_261 ( & V_2 -> V_304 , F_251 ) ;
F_262 ( & V_2 -> V_146 , F_191 ) ;
F_262 ( & V_2 -> V_313 , V_314 ) ;
V_2 -> V_156 = V_156 ;
V_2 -> V_315 = V_316 ;
V_2 -> V_3 = V_291 ;
F_237 ( V_2 -> V_62 , F_123 ( V_156 ) , sizeof( V_2 -> V_62 ) ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_70 = V_2 -> type -> V_70 ;
V_2 -> V_74 =
V_81 ? ( V_2 -> V_70 + V_81 ) % 4 : 0 ;
V_2 -> V_317 =
V_2 -> type -> V_318 - V_2 -> type -> V_70 ;
V_2 -> V_319 =
V_2 -> type -> V_320 - V_2 -> type -> V_70 ;
F_174 ( & V_2 -> V_220 ) ;
F_263 ( & V_2 -> V_125 ) ;
V_2 -> V_138 = & V_321 ;
V_2 -> V_247 . V_162 = V_7 ;
F_261 ( & V_2 -> V_130 , F_106 ) ;
F_264 ( & V_2 -> V_322 ) ;
for ( V_39 = 0 ; V_39 < V_97 ; V_39 ++ ) {
V_2 -> V_10 [ V_39 ] = F_35 ( V_2 , V_39 , NULL ) ;
if ( ! V_2 -> V_10 [ V_39 ] )
goto V_56;
V_2 -> V_64 [ V_39 ] . V_2 = V_2 ;
V_2 -> V_64 [ V_39 ] . V_102 = V_39 ;
}
V_2 -> V_175 = F_21 ( V_2 -> type -> V_323 ,
V_175 ) ;
snprintf ( V_2 -> V_324 , sizeof( V_2 -> V_324 ) , L_81 ,
F_123 ( V_156 ) ) ;
V_2 -> V_214 = F_265 ( V_2 -> V_324 ) ;
if ( ! V_2 -> V_214 )
goto V_56;
return 0 ;
V_56:
F_266 ( V_2 ) ;
return - V_104 ;
}
static void F_266 ( struct V_1 * V_2 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_97 ; V_39 ++ )
F_83 ( V_2 -> V_10 [ V_39 ] ) ;
F_83 ( V_2 -> V_150 ) ;
if ( V_2 -> V_214 ) {
F_267 ( V_2 -> V_214 ) ;
V_2 -> V_214 = NULL ;
}
}
static void F_268 ( struct V_1 * V_2 )
{
F_68 ( V_2 -> V_3 == V_286 ) ;
F_115 ( & V_2 -> V_304 ) ;
F_160 ( V_2 ) ;
F_269 ( V_2 ) ;
F_116 ( V_2 ) ;
V_2 -> type -> V_144 ( V_2 ) ;
F_202 ( V_2 ) ;
F_186 ( V_2 ) ;
}
static void F_270 ( struct V_156 * V_156 )
{
struct V_1 * V_2 ;
V_2 = F_224 ( V_156 ) ;
if ( ! V_2 )
return;
F_228 () ;
F_125 ( V_2 ) ;
F_243 ( V_2 -> V_7 ) ;
F_160 ( V_2 ) ;
F_233 () ;
F_271 ( V_2 ) ;
F_236 ( V_2 ) ;
F_272 ( V_2 ) ;
F_268 ( V_2 ) ;
F_136 ( V_2 ) ;
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_82 ) ;
F_266 ( V_2 ) ;
F_273 ( V_2 -> V_7 ) ;
F_274 ( V_156 ) ;
}
static void F_275 ( struct V_1 * V_2 )
{
struct V_156 * V_162 = V_2 -> V_156 ;
char V_325 [ V_326 ] ;
T_7 V_327 ;
int V_328 , V_329 , V_39 , V_43 ;
V_327 = F_276 ( V_162 , 0 , sizeof( V_325 ) , V_325 ) ;
if ( V_327 <= 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_83 ) ;
return;
}
V_328 = F_277 ( V_325 , 0 , V_327 , V_330 ) ;
if ( V_328 < 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_84 ) ;
return;
}
V_329 = F_278 ( & V_325 [ V_328 ] ) ;
V_43 = V_329 ;
V_39 = V_328 + V_331 ;
if ( V_39 + V_43 > V_327 )
V_43 = V_327 - V_39 ;
V_39 = F_279 ( V_325 , V_39 , V_43 , L_85 ) ;
if ( V_39 < 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_86 ) ;
return;
}
V_43 = F_280 ( & V_325 [ V_39 ] ) ;
V_39 += V_332 ;
if ( V_39 + V_43 > V_327 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_87 ) ;
return;
}
F_97 ( V_2 , V_6 , V_2 -> V_7 ,
L_88 , V_43 , & V_325 [ V_39 ] ) ;
V_39 = V_328 + V_331 ;
V_43 = V_329 ;
V_39 = F_279 ( V_325 , V_39 , V_43 , L_89 ) ;
if ( V_39 < 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_90 ) ;
return;
}
V_43 = F_280 ( & V_325 [ V_39 ] ) ;
V_39 += V_332 ;
if ( V_39 + V_43 > V_327 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_91 ) ;
return;
}
V_2 -> V_150 = F_39 ( V_43 + 1 , V_44 ) ;
if ( ! V_2 -> V_150 )
return;
snprintf ( V_2 -> V_150 , V_43 + 1 , L_92 , & V_325 [ V_39 ] ) ;
}
static int F_281 ( struct V_1 * V_2 )
{
int V_35 ;
V_35 = F_179 ( V_2 ) ;
if ( V_35 )
goto V_140;
F_200 ( V_2 ) ;
V_35 = V_2 -> type -> V_139 ( V_2 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_71 ) ;
goto V_165;
}
V_35 = F_108 ( V_2 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_93 ) ;
goto V_167;
}
V_35 = F_282 ( V_2 ) ;
if ( V_35 )
goto V_333;
V_35 = F_158 ( V_2 ) ;
if ( V_35 )
goto V_334;
return 0 ;
V_334:
F_269 ( V_2 ) ;
V_333:
F_116 ( V_2 ) ;
V_167:
V_2 -> type -> V_144 ( V_2 ) ;
V_165:
F_202 ( V_2 ) ;
F_186 ( V_2 ) ;
V_140:
return V_35 ;
}
static int F_283 ( struct V_156 * V_156 ,
const struct V_335 * V_181 )
{
struct V_236 * V_7 ;
struct V_1 * V_2 ;
int V_35 ;
V_7 = F_284 ( sizeof( * V_2 ) , V_336 ,
V_337 ) ;
if ( ! V_7 )
return - V_104 ;
V_2 = F_194 ( V_7 ) ;
V_2 -> type = ( const struct V_338 * ) V_181 -> V_339 ;
V_7 -> V_262 |= ( V_2 -> type -> V_204 | V_340 |
V_341 | V_342 |
V_343 ) ;
if ( V_2 -> type -> V_204 & V_344 )
V_7 -> V_262 |= V_345 ;
V_7 -> V_346 |= ( V_347 | V_340 |
V_341 | V_348 |
V_343 ) ;
V_7 -> V_349 = V_7 -> V_262 & ~ V_341 ;
F_285 ( V_156 , V_2 ) ;
F_286 ( V_7 , & V_156 -> V_162 ) ;
V_35 = F_258 ( V_2 , V_156 , V_7 ) ;
if ( V_35 )
goto V_140;
F_97 ( V_2 , V_29 , V_2 -> V_7 ,
L_94 ) ;
F_275 ( V_2 ) ;
V_35 = F_126 ( V_2 ) ;
if ( V_35 )
goto V_143;
V_35 = F_281 ( V_2 ) ;
if ( V_35 )
goto V_165;
V_35 = F_226 ( V_2 ) ;
if ( V_35 )
goto V_167;
V_35 = F_287 ( V_2 ) ;
if ( V_35 )
F_2 ( V_2 , V_29 , V_2 -> V_7 ,
L_95 , V_35 ) ;
F_18 ( V_2 , V_29 , V_2 -> V_7 , L_96 ) ;
F_228 () ;
V_35 = F_288 ( V_2 ) ;
F_233 () ;
if ( V_35 )
F_140 ( V_2 , V_29 , V_2 -> V_7 ,
L_97 , V_35 ) ;
V_35 = F_289 ( V_156 ) ;
if ( V_35 && V_35 != - V_212 )
F_140 ( V_2 , V_29 , V_2 -> V_7 ,
L_98 , V_35 ) ;
return 0 ;
V_167:
F_268 ( V_2 ) ;
V_165:
F_136 ( V_2 ) ;
V_143:
F_266 ( V_2 ) ;
V_140:
F_62 ( V_35 > 0 ) ;
F_18 ( V_2 , V_6 , V_2 -> V_7 , L_99 , V_35 ) ;
F_273 ( V_7 ) ;
return V_35 ;
}
static int F_290 ( struct V_274 * V_162 )
{
struct V_1 * V_2 = F_224 ( F_225 ( V_162 ) ) ;
F_228 () ;
if ( V_2 -> V_3 != V_4 ) {
V_2 -> V_3 = V_291 ;
F_78 ( V_2 ) ;
F_79 ( V_2 ) ;
F_160 ( V_2 ) ;
}
F_233 () ;
return 0 ;
}
static int F_291 ( struct V_274 * V_162 )
{
int V_35 ;
struct V_1 * V_2 = F_224 ( F_225 ( V_162 ) ) ;
F_228 () ;
if ( V_2 -> V_3 != V_4 ) {
V_35 = F_158 ( V_2 ) ;
if ( V_35 )
goto V_56;
F_104 ( & V_2 -> V_125 ) ;
V_2 -> V_138 -> V_142 ( V_2 ) ;
F_105 ( & V_2 -> V_125 ) ;
F_85 ( V_2 ) ;
F_86 ( V_2 -> V_7 ) ;
V_2 -> V_3 = V_286 ;
V_2 -> type -> V_350 ( V_2 ) ;
}
F_233 () ;
F_217 ( V_310 , & V_2 -> V_304 ) ;
return 0 ;
V_56:
F_233 () ;
return V_35 ;
}
static int F_292 ( struct V_274 * V_162 )
{
struct V_156 * V_156 = F_225 ( V_162 ) ;
struct V_1 * V_2 = F_224 ( V_156 ) ;
V_2 -> type -> V_144 ( V_2 ) ;
V_2 -> V_287 = 0 ;
F_293 ( V_156 ) ;
return F_294 ( V_156 , V_351 ) ;
}
static int F_295 ( struct V_274 * V_162 )
{
struct V_156 * V_156 = F_225 ( V_162 ) ;
struct V_1 * V_2 = F_224 ( V_156 ) ;
int V_35 ;
V_35 = F_294 ( V_156 , V_352 ) ;
if ( V_35 )
return V_35 ;
F_296 ( V_156 ) ;
V_35 = F_127 ( V_156 ) ;
if ( V_35 )
return V_35 ;
F_128 ( V_2 -> V_156 ) ;
V_35 = V_2 -> type -> V_297 ( V_2 , V_94 ) ;
if ( V_35 )
return V_35 ;
V_35 = V_2 -> type -> V_139 ( V_2 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_291 ( V_162 ) ;
return V_35 ;
}
static int F_297 ( struct V_274 * V_162 )
{
int V_35 ;
F_290 ( V_162 ) ;
V_35 = F_292 ( V_162 ) ;
if ( V_35 )
F_295 ( V_162 ) ;
return V_35 ;
}
static T_8 F_298 ( struct V_156 * V_353 ,
enum V_354 V_3 )
{
T_8 V_355 = V_356 ;
struct V_1 * V_2 = F_224 ( V_353 ) ;
if ( V_3 == V_357 )
return V_358 ;
F_228 () ;
if ( V_2 -> V_3 != V_4 ) {
V_2 -> V_3 = V_5 ;
V_2 -> V_287 = 0 ;
F_78 ( V_2 ) ;
F_79 ( V_2 ) ;
F_160 ( V_2 ) ;
V_355 = V_359 ;
} else {
V_355 = V_356 ;
}
F_233 () ;
F_135 ( V_353 ) ;
return V_355 ;
}
static T_8 F_299 ( struct V_156 * V_353 )
{
struct V_1 * V_2 = F_224 ( V_353 ) ;
T_8 V_355 = V_356 ;
int V_35 ;
if ( F_127 ( V_353 ) ) {
F_2 ( V_2 , V_360 , V_2 -> V_7 ,
L_100 ) ;
V_355 = V_358 ;
}
V_35 = F_300 ( V_353 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_360 , V_2 -> V_7 ,
L_101 , V_35 ) ;
}
return V_355 ;
}
static void F_301 ( struct V_156 * V_353 )
{
struct V_1 * V_2 = F_224 ( V_353 ) ;
int V_35 ;
F_228 () ;
if ( V_2 -> V_3 == V_4 )
goto V_105;
V_35 = F_207 ( V_2 , V_94 ) ;
if ( V_35 ) {
F_2 ( V_2 , V_360 , V_2 -> V_7 ,
L_102 , V_35 ) ;
} else {
V_2 -> V_3 = V_286 ;
F_18 ( V_2 , V_360 , V_2 -> V_7 ,
L_103 ) ;
}
V_105:
F_233 () ;
}
static int T_9 F_302 ( void )
{
int V_35 ;
F_303 ( V_361 L_104 V_362 L_105 ) ;
V_35 = F_304 ( & V_363 ) ;
if ( V_35 )
goto V_364;
V_35 = F_305 () ;
if ( V_35 )
goto V_365;
V_310 = F_265 ( L_106 ) ;
if ( ! V_310 ) {
V_35 = - V_104 ;
goto V_366;
}
V_35 = F_306 ( & V_367 ) ;
if ( V_35 < 0 )
goto V_368;
return 0 ;
V_368:
F_267 ( V_310 ) ;
V_366:
F_307 () ;
V_365:
F_308 ( & V_363 ) ;
V_364:
return V_35 ;
}
static void T_10 F_309 ( void )
{
F_303 ( V_361 L_107 ) ;
F_310 ( & V_367 ) ;
F_267 ( V_310 ) ;
F_307 () ;
F_308 ( & V_363 ) ;
}

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
bool V_68 = V_2 -> V_69 ;
struct V_12 * V_13 ;
struct V_18 * V_19 ;
struct V_9 * V_10 ;
T_1 V_70 ;
V_2 -> V_71 = ( V_2 -> V_72 +
F_59 ( V_2 -> V_7 -> V_73 ) +
V_2 -> type -> V_74 ) ;
V_70 = ( sizeof( struct V_75 ) +
V_2 -> V_76 + V_2 -> V_71 ) ;
if ( V_70 <= V_77 ) {
V_2 -> V_69 = V_2 -> type -> V_78 ;
V_2 -> V_79 = 0 ;
} else if ( V_2 -> type -> V_80 ) {
F_60 ( V_81 % V_82 ) ;
F_60 ( sizeof( struct V_75 ) +
2 * F_61 ( V_83 + V_81 ,
V_84 ) >
V_77 ) ;
V_2 -> V_69 = true ;
V_2 -> V_71 = V_81 ;
V_2 -> V_79 = 0 ;
} else {
V_2 -> V_69 = false ;
V_2 -> V_79 = F_62 ( V_70 ) ;
}
F_63 ( V_2 ) ;
if ( V_2 -> V_79 )
F_22 ( V_2 , V_6 , V_2 -> V_7 ,
L_14 ,
V_2 -> V_71 , V_2 -> V_79 ,
V_2 -> V_85 ) ;
else
F_22 ( V_2 , V_6 , V_2 -> V_7 ,
L_15 ,
V_2 -> V_71 , V_2 -> V_86 ,
V_2 -> V_87 , V_2 -> V_85 ) ;
if ( V_2 -> V_69 != V_68 )
V_2 -> type -> V_88 ( V_2 ) ;
V_2 -> V_89 = V_2 -> V_36 - F_64 ( V_2 ) ;
V_2 -> V_90 = V_2 -> V_89 / 2 ;
F_54 (channel, efx) {
F_5 (tx_queue, channel) {
F_65 ( V_13 ) ;
F_66 ( & V_2 -> V_91 ) ;
}
F_49 (rx_queue, channel) {
F_67 ( V_19 ) ;
F_66 ( & V_2 -> V_91 ) ;
F_34 ( V_10 ) ;
F_10 ( V_19 , false ) ;
F_30 ( V_10 ) ;
}
F_68 ( V_10 -> V_92 ) ;
}
F_69 ( V_2 ) ;
if ( F_70 ( V_2 -> V_7 ) )
F_71 ( V_2 -> V_7 ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_12 * V_13 ;
struct V_18 * V_19 ;
int V_40 ;
F_73 ( V_2 ) ;
F_74 ( V_2 -> V_93 ) ;
F_75 ( V_2 ) ;
F_54 (channel, efx) {
F_49 (rx_queue, channel)
V_19 -> V_94 = false ;
}
F_54 (channel, efx) {
if ( F_7 ( V_10 ) ) {
F_34 ( V_10 ) ;
F_30 ( V_10 ) ;
}
}
V_40 = V_2 -> type -> V_95 ( V_2 ) ;
if ( V_40 && F_76 ( V_2 ) ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_16 ) ;
F_77 ( V_2 , V_96 ) ;
} else if ( V_40 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_17 ) ;
} else {
F_22 ( V_2 , V_6 , V_2 -> V_7 ,
L_18 ) ;
}
F_54 (channel, efx) {
F_49 (rx_queue, channel)
F_78 ( V_19 ) ;
F_79 (tx_queue, channel)
F_80 ( V_13 ) ;
}
}
static void F_51 ( struct V_9 * V_10 )
{
struct V_12 * V_13 ;
struct V_18 * V_19 ;
F_22 ( V_10 -> V_2 , V_6 , V_10 -> V_2 -> V_7 ,
L_19 , V_10 -> V_10 ) ;
F_49 (rx_queue, channel)
F_81 ( V_19 ) ;
F_79 (tx_queue, channel)
F_82 ( V_13 ) ;
F_40 ( V_10 ) ;
V_10 -> type -> V_97 ( V_10 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_54 (channel, efx)
F_51 ( V_10 ) ;
}
int
F_83 ( struct V_1 * V_2 , T_2 V_35 , T_2 V_36 )
{
struct V_9 * V_98 [ V_99 ] , * V_10 ;
T_2 V_100 , V_101 ;
unsigned V_44 , V_67 = 0 ;
int V_40 , V_102 ;
V_40 = F_1 ( V_2 ) ;
if ( V_40 )
return V_40 ;
F_54 (channel, efx) {
struct V_18 * V_19 ;
struct V_12 * V_13 ;
if ( V_10 -> type -> V_103 )
continue;
V_67 = F_25 ( V_67 ,
V_10 -> V_54 . V_104 +
V_10 -> V_54 . V_33 ) ;
F_49 (rx_queue, channel)
V_67 = F_25 ( V_67 ,
V_19 -> V_57 . V_104 +
V_19 -> V_57 . V_33 ) ;
F_5 (tx_queue, channel)
V_67 = F_25 ( V_67 ,
V_13 -> V_56 . V_104 +
V_13 -> V_56 . V_33 ) ;
}
F_84 ( V_2 ) ;
F_85 ( V_2 ) ;
F_86 ( V_2 ) ;
memset ( V_98 , 0 , sizeof( V_98 ) ) ;
for ( V_44 = 0 ; V_44 < V_2 -> V_105 ; V_44 ++ ) {
V_10 = V_2 -> V_10 [ V_44 ] ;
if ( V_10 -> type -> V_103 )
V_10 = V_10 -> type -> V_103 ( V_10 ) ;
if ( ! V_10 ) {
V_40 = - V_106 ;
goto V_107;
}
V_98 [ V_44 ] = V_10 ;
}
V_100 = V_2 -> V_35 ;
V_101 = V_2 -> V_36 ;
V_2 -> V_35 = V_35 ;
V_2 -> V_36 = V_36 ;
for ( V_44 = 0 ; V_44 < V_2 -> V_105 ; V_44 ++ ) {
V_10 = V_2 -> V_10 [ V_44 ] ;
V_2 -> V_10 [ V_44 ] = V_98 [ V_44 ] ;
V_98 [ V_44 ] = V_10 ;
}
V_2 -> V_67 = V_67 ;
for ( V_44 = 0 ; V_44 < V_2 -> V_105 ; V_44 ++ ) {
V_10 = V_2 -> V_10 [ V_44 ] ;
if ( ! V_10 -> type -> V_103 )
continue;
V_40 = F_47 ( V_10 ) ;
if ( V_40 )
goto V_108;
F_87 ( V_2 -> V_10 [ V_44 ] ) ;
}
V_107:
for ( V_44 = 0 ; V_44 < V_2 -> V_105 ; V_44 ++ ) {
V_10 = V_98 [ V_44 ] ;
if ( V_10 && V_10 -> type -> V_103 ) {
F_88 ( V_10 ) ;
F_51 ( V_10 ) ;
F_89 ( V_10 ) ;
}
}
V_102 = F_90 ( V_2 ) ;
if ( V_102 ) {
V_40 = V_40 ? V_40 : V_102 ;
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_20 ) ;
F_77 ( V_2 , V_109 ) ;
} else {
F_91 ( V_2 ) ;
F_92 ( V_2 -> V_7 ) ;
}
return V_40 ;
V_108:
V_2 -> V_35 = V_100 ;
V_2 -> V_36 = V_101 ;
for ( V_44 = 0 ; V_44 < V_2 -> V_105 ; V_44 ++ ) {
V_10 = V_2 -> V_10 [ V_44 ] ;
V_2 -> V_10 [ V_44 ] = V_98 [ V_44 ] ;
V_98 [ V_44 ] = V_10 ;
}
goto V_107;
}
void F_93 ( struct V_18 * V_19 )
{
F_94 ( & V_19 -> V_51 , V_110 + F_95 ( 100 ) ) ;
}
int F_96 ( struct V_9 * V_10 )
{
return 0 ;
}
void F_97 ( struct V_9 * V_10 )
{
}
void F_98 ( struct V_1 * V_2 )
{
struct V_111 * V_112 = & V_2 -> V_112 ;
if ( ! F_99 ( V_2 -> V_7 ) )
return;
if ( V_112 -> V_113 != F_100 ( V_2 -> V_7 ) ) {
V_2 -> V_114 ++ ;
if ( V_112 -> V_113 )
F_101 ( V_2 -> V_7 ) ;
else
F_102 ( V_2 -> V_7 ) ;
}
if ( V_112 -> V_113 )
F_103 ( V_2 , V_115 , V_2 -> V_7 ,
L_21 ,
V_112 -> V_116 , V_112 -> V_117 ? L_22 : L_23 ,
V_2 -> V_7 -> V_73 ) ;
else
F_103 ( V_2 , V_115 , V_2 -> V_7 , L_24 ) ;
}
void F_104 ( struct V_1 * V_2 , T_2 V_118 )
{
V_2 -> V_119 = V_118 ;
if ( V_118 ) {
if ( V_118 & V_120 )
V_2 -> V_121 |= ( V_122 | V_123 ) ;
else
V_2 -> V_121 &= ~ ( V_122 | V_123 ) ;
if ( V_118 & V_124 )
V_2 -> V_121 ^= V_122 ;
}
}
void F_105 ( struct V_1 * V_2 , T_3 V_121 )
{
V_2 -> V_121 = V_121 ;
if ( V_2 -> V_119 ) {
if ( V_121 & V_123 )
V_2 -> V_119 |= ( V_120 |
V_124 ) ;
else
V_2 -> V_119 &= ~ ( V_120 |
V_124 ) ;
if ( V_121 & V_122 )
V_2 -> V_119 ^= V_124 ;
}
}
void F_106 ( struct V_1 * V_2 )
{
F_107 ( & V_2 -> V_125 ) ;
V_2 -> type -> V_126 ( V_2 ) ;
F_108 ( & V_2 -> V_125 ) ;
}
int F_109 ( struct V_1 * V_2 )
{
enum V_127 V_128 ;
int V_40 ;
F_68 ( ! F_110 ( & V_2 -> V_129 ) ) ;
V_128 = V_2 -> V_128 ;
if ( F_111 ( V_2 ) )
V_2 -> V_128 |= V_130 ;
else
V_2 -> V_128 &= ~ V_130 ;
V_40 = V_2 -> type -> V_131 ( V_2 ) ;
if ( V_40 )
V_2 -> V_128 = V_128 ;
return V_40 ;
}
int F_112 ( struct V_1 * V_2 )
{
int V_40 ;
F_73 ( V_2 ) ;
F_113 ( & V_2 -> V_129 ) ;
V_40 = F_109 ( V_2 ) ;
F_114 ( & V_2 -> V_129 ) ;
return V_40 ;
}
static void F_115 ( struct V_132 * V_133 )
{
struct V_1 * V_2 = F_13 ( V_133 , struct V_1 , V_134 ) ;
F_113 ( & V_2 -> V_129 ) ;
if ( V_2 -> V_93 )
F_106 ( V_2 ) ;
F_114 ( & V_2 -> V_129 ) ;
}
static int F_116 ( struct V_1 * V_2 )
{
int V_40 ;
F_22 ( V_2 , V_34 , V_2 -> V_7 , L_25 ) ;
if ( V_135 )
V_2 -> V_128 = V_136 ;
V_40 = V_2 -> type -> V_137 ( V_2 ) ;
if ( V_40 )
return V_40 ;
F_117 ( V_2 -> V_7 -> V_138 , V_2 -> V_7 -> V_139 ) ;
return 0 ;
}
static int F_118 ( struct V_1 * V_2 )
{
int V_40 ;
F_22 ( V_2 , V_6 , V_2 -> V_7 , L_26 ) ;
F_113 ( & V_2 -> V_129 ) ;
V_40 = V_2 -> V_140 -> V_141 ( V_2 ) ;
if ( V_40 )
goto V_142;
V_2 -> V_143 = true ;
F_106 ( V_2 ) ;
V_40 = V_2 -> V_140 -> V_144 ( V_2 ) ;
if ( V_40 && V_40 != - V_145 )
goto V_146;
F_114 ( & V_2 -> V_129 ) ;
return 0 ;
V_146:
V_2 -> V_140 -> V_147 ( V_2 ) ;
V_142:
F_114 ( & V_2 -> V_129 ) ;
return V_40 ;
}
static void F_119 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_43 , V_2 -> V_7 , L_27 ) ;
F_74 ( V_2 -> V_93 ) ;
F_113 ( & V_2 -> V_129 ) ;
V_2 -> V_93 = true ;
F_106 ( V_2 ) ;
F_114 ( & V_2 -> V_129 ) ;
}
static void F_120 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_148 , V_2 -> V_7 , L_28 ) ;
F_73 ( V_2 ) ;
F_113 ( & V_2 -> V_129 ) ;
V_2 -> V_93 = false ;
F_114 ( & V_2 -> V_129 ) ;
F_121 ( V_2 -> V_7 ) ;
F_122 ( V_2 -> V_7 ) ;
F_123 ( & V_2 -> V_149 ) ;
F_124 ( V_2 ) ;
F_125 ( & V_2 -> V_134 ) ;
}
static void F_126 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_6 , V_2 -> V_7 , L_29 ) ;
if ( ! V_2 -> V_143 )
return;
V_2 -> V_140 -> V_147 ( V_2 ) ;
V_2 -> V_143 = false ;
V_2 -> V_112 . V_113 = false ;
F_98 ( V_2 ) ;
}
static void F_127 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_6 , V_2 -> V_7 , L_30 ) ;
V_2 -> type -> V_150 ( V_2 ) ;
}
static bool F_128 ( struct V_1 * V_151 , struct V_1 * V_152 )
{
return V_151 -> type == V_152 -> type &&
V_151 -> V_153 && V_152 -> V_153 &&
! strcmp ( V_151 -> V_153 , V_152 -> V_153 ) ;
}
static void F_129 ( struct V_1 * V_2 )
{
struct V_1 * V_154 , * V_155 ;
if ( V_2 -> V_156 == V_2 ) {
F_22 ( V_2 , V_34 , V_2 -> V_7 , L_31 ) ;
F_130 ( & V_2 -> V_157 , & V_158 ) ;
F_131 (other, next, &efx_unassociated_list,
node) {
if ( F_128 ( V_2 , V_154 ) ) {
F_132 ( & V_154 -> V_157 ) ;
F_22 ( V_154 , V_34 , V_154 -> V_7 ,
L_32 ,
F_133 ( V_2 -> V_159 ) ,
V_2 -> V_7 -> V_64 ) ;
F_130 ( & V_154 -> V_157 ,
& V_2 -> V_160 ) ;
V_154 -> V_156 = V_2 ;
}
}
} else {
F_134 (other, &efx_primary_list, node) {
if ( F_128 ( V_2 , V_154 ) ) {
F_22 ( V_2 , V_34 , V_2 -> V_7 ,
L_33 ,
F_133 ( V_154 -> V_159 ) ,
V_154 -> V_7 -> V_64 ) ;
F_130 ( & V_2 -> V_157 ,
& V_154 -> V_160 ) ;
V_2 -> V_156 = V_154 ;
return;
}
}
F_22 ( V_2 , V_34 , V_2 -> V_7 ,
L_34 ) ;
F_130 ( & V_2 -> V_157 , & V_161 ) ;
}
}
static void F_135 ( struct V_1 * V_2 )
{
struct V_1 * V_154 , * V_155 ;
F_132 ( & V_2 -> V_157 ) ;
V_2 -> V_156 = NULL ;
F_131 (other, next, &efx->secondary_list, node) {
F_132 ( & V_154 -> V_157 ) ;
F_22 ( V_154 , V_34 , V_154 -> V_7 ,
L_35 ) ;
F_130 ( & V_154 -> V_157 , & V_161 ) ;
V_154 -> V_156 = NULL ;
}
}
static int F_136 ( struct V_1 * V_2 )
{
struct V_159 * V_159 = V_2 -> V_159 ;
T_4 V_162 = V_2 -> type -> V_163 ;
unsigned int V_164 = V_2 -> type -> V_164 ( V_2 ) ;
int V_40 , V_165 ;
F_22 ( V_2 , V_34 , V_2 -> V_7 , L_36 ) ;
V_165 = V_2 -> type -> V_166 ;
V_40 = F_137 ( V_159 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_34 , V_2 -> V_7 ,
L_37 ) ;
goto V_142;
}
F_138 ( V_159 ) ;
while ( V_162 > 0x7fffffffUL ) {
if ( F_139 ( & V_159 -> V_167 , V_162 ) ) {
V_40 = F_140 ( & V_159 -> V_167 , V_162 ) ;
if ( V_40 == 0 )
break;
}
V_162 >>= 1 ;
}
if ( V_40 ) {
F_2 ( V_2 , V_34 , V_2 -> V_7 ,
L_38 ) ;
goto V_146;
}
F_22 ( V_2 , V_34 , V_2 -> V_7 ,
L_39 , ( unsigned long long ) V_162 ) ;
V_2 -> V_168 = F_141 ( V_2 -> V_159 , V_165 ) ;
V_40 = F_142 ( V_159 , V_165 , L_40 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_34 , V_2 -> V_7 ,
L_41 ) ;
V_40 = - V_8 ;
goto V_169;
}
V_2 -> V_170 = F_143 ( V_2 -> V_168 , V_164 ) ;
if ( ! V_2 -> V_170 ) {
F_2 ( V_2 , V_34 , V_2 -> V_7 ,
L_42 ,
( unsigned long long ) V_2 -> V_168 , V_164 ) ;
V_40 = - V_106 ;
goto V_171;
}
F_22 ( V_2 , V_34 , V_2 -> V_7 ,
L_43 ,
( unsigned long long ) V_2 -> V_168 , V_164 ,
V_2 -> V_170 ) ;
return 0 ;
V_171:
F_144 ( V_2 -> V_159 , V_165 ) ;
V_169:
V_2 -> V_168 = 0 ;
V_146:
F_145 ( V_2 -> V_159 ) ;
V_142:
return V_40 ;
}
static void F_146 ( struct V_1 * V_2 )
{
int V_165 ;
F_22 ( V_2 , V_6 , V_2 -> V_7 , L_44 ) ;
if ( V_2 -> V_170 ) {
F_147 ( V_2 -> V_170 ) ;
V_2 -> V_170 = NULL ;
}
if ( V_2 -> V_168 ) {
V_165 = V_2 -> type -> V_166 ;
F_144 ( V_2 -> V_159 , V_165 ) ;
V_2 -> V_168 = 0 ;
}
if ( ! F_148 ( V_2 -> V_159 ) )
F_145 ( V_2 -> V_159 ) ;
}
void F_149 ( struct V_1 * V_2 )
{
T_1 V_44 ;
for ( V_44 = 0 ; V_44 < F_150 ( V_2 -> V_172 ) ; V_44 ++ )
V_2 -> V_172 [ V_44 ] =
F_151 ( V_44 , V_2 -> V_173 ) ;
}
static unsigned int F_152 ( struct V_1 * V_2 )
{
T_5 V_174 ;
unsigned int V_175 ;
int V_176 ;
if ( V_177 ) {
V_175 = V_177 ;
} else {
if ( F_4 ( ! F_153 ( & V_174 , V_47 ) ) ) {
F_154 ( V_2 , V_34 , V_2 -> V_7 ,
L_45 ) ;
return 1 ;
}
V_175 = 0 ;
F_155 (cpu) {
if ( ! F_156 ( V_176 , V_174 ) ) {
++ V_175 ;
F_157 ( V_174 , V_174 ,
F_158 ( V_176 ) ) ;
}
}
F_159 ( V_174 ) ;
}
#ifdef F_160
if ( V_2 -> type -> V_178 ) {
if ( V_2 -> type -> V_178 ( V_2 ) && F_161 ( V_2 ) > 1 &&
V_175 > F_161 ( V_2 ) ) {
F_154 ( V_2 , V_34 , V_2 -> V_7 ,
L_46
L_47
L_48 ,
V_175 , F_161 ( V_2 ) ) ;
V_175 = F_161 ( V_2 ) ;
}
}
#endif
return V_175 ;
}
static int F_162 ( struct V_1 * V_2 )
{
unsigned int V_179 = 0 ;
unsigned int V_44 , V_46 ;
int V_40 ;
for ( V_44 = 0 ; V_44 < V_180 ; V_44 ++ )
if ( V_2 -> V_181 [ V_44 ] )
++ V_179 ;
if ( V_2 -> V_182 == V_183 ) {
struct V_184 V_185 [ V_99 ] ;
unsigned int V_105 ;
V_105 = F_152 ( V_2 ) ;
if ( V_186 )
V_105 *= 2 ;
V_105 += V_179 ;
V_105 = F_163 ( V_105 , V_2 -> V_187 ) ;
for ( V_44 = 0 ; V_44 < V_105 ; V_44 ++ )
V_185 [ V_44 ] . V_188 = V_44 ;
V_40 = F_164 ( V_2 -> V_159 ,
V_185 , 1 , V_105 ) ;
if ( V_40 < 0 ) {
V_2 -> V_182 = V_189 ;
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_49 ) ;
} else if ( V_40 < V_105 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_50
L_51 , V_40 , V_105 ) ;
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_52 ) ;
V_105 = V_40 ;
}
if ( V_40 > 0 ) {
V_2 -> V_105 = V_105 ;
if ( V_105 > V_179 )
V_105 -= V_179 ;
if ( V_186 ) {
V_2 -> V_190 = F_25 ( V_105 / 2 , 1U ) ;
V_2 -> V_191 = F_25 ( V_105 -
V_2 -> V_190 ,
1U ) ;
} else {
V_2 -> V_190 = V_105 ;
V_2 -> V_191 = V_105 ;
}
for ( V_44 = 0 ; V_44 < V_2 -> V_105 ; V_44 ++ )
F_165 ( V_2 , V_44 ) -> V_192 =
V_185 [ V_44 ] . V_193 ;
}
}
if ( V_2 -> V_182 == V_189 ) {
V_2 -> V_105 = 1 ;
V_2 -> V_191 = 1 ;
V_2 -> V_190 = 1 ;
V_40 = F_166 ( V_2 -> V_159 ) ;
if ( V_40 == 0 ) {
F_165 ( V_2 , 0 ) -> V_192 = V_2 -> V_159 -> V_192 ;
} else {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_53 ) ;
V_2 -> V_182 = V_194 ;
}
}
if ( V_2 -> V_182 == V_194 ) {
V_2 -> V_105 = 1 + ( V_186 ? 1 : 0 ) ;
V_2 -> V_191 = 1 ;
V_2 -> V_190 = 1 ;
V_2 -> V_195 = V_2 -> V_159 -> V_192 ;
}
V_46 = V_2 -> V_105 ;
for ( V_44 = 0 ; V_44 < V_180 ; V_44 ++ ) {
if ( ! V_2 -> V_181 [ V_44 ] )
continue;
if ( V_2 -> V_182 != V_183 ||
V_2 -> V_105 <= V_179 ) {
V_2 -> V_181 [ V_44 ] -> F_167 ( V_2 ) ;
} else {
-- V_46 ;
F_165 ( V_2 , V_46 ) -> type =
V_2 -> V_181 [ V_44 ] ;
}
}
#ifdef F_160
if ( V_2 -> type -> V_178 ) {
V_2 -> V_173 = ( ( V_2 -> V_191 > 1 ||
! V_2 -> type -> V_178 ( V_2 ) ) ?
V_2 -> V_191 : F_161 ( V_2 ) ) ;
return 0 ;
}
#endif
V_2 -> V_173 = V_2 -> V_191 ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 )
{
struct V_9 * V_10 , * V_196 ;
int V_40 ;
F_74 ( V_2 -> V_3 == V_4 ) ;
V_2 -> V_197 = true ;
F_31 () ;
F_54 (channel, efx) {
if ( ! V_10 -> type -> V_198 ) {
V_40 = F_27 ( V_10 ) ;
if ( V_40 )
goto V_59;
}
F_30 ( V_10 ) ;
}
F_168 ( V_2 ) ;
return 0 ;
V_59:
V_196 = V_10 ;
F_54 (channel, efx) {
if ( V_10 == V_196 )
break;
F_34 ( V_10 ) ;
if ( ! V_10 -> type -> V_198 )
F_38 ( V_10 ) ;
}
return V_40 ;
}
static void F_86 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
if ( V_2 -> V_3 == V_4 )
return;
F_169 ( V_2 ) ;
V_2 -> V_197 = false ;
F_31 () ;
if ( V_2 -> V_195 )
F_170 ( V_2 -> V_195 ) ;
F_54 (channel, efx) {
if ( V_10 -> V_192 )
F_170 ( V_10 -> V_192 ) ;
F_34 ( V_10 ) ;
if ( ! V_10 -> type -> V_198 )
F_38 ( V_10 ) ;
}
F_171 ( V_2 ) ;
}
static int F_172 ( struct V_1 * V_2 )
{
struct V_9 * V_10 , * V_196 ;
int V_40 ;
F_74 ( V_2 -> V_3 == V_4 ) ;
if ( V_2 -> V_199 ) {
F_173 ( V_2 -> V_195 ) ;
V_2 -> V_199 = false ;
}
V_2 -> type -> V_200 ( V_2 ) ;
F_54 (channel, efx) {
if ( V_10 -> type -> V_198 ) {
V_40 = F_27 ( V_10 ) ;
if ( V_40 )
goto V_59;
}
}
V_40 = F_90 ( V_2 ) ;
if ( V_40 )
goto V_59;
return 0 ;
V_59:
V_196 = V_10 ;
F_54 (channel, efx) {
if ( V_10 == V_196 )
break;
if ( V_10 -> type -> V_198 )
F_38 ( V_10 ) ;
}
V_2 -> type -> V_201 ( V_2 ) ;
return V_40 ;
}
static void F_174 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_86 ( V_2 ) ;
F_54 (channel, efx) {
if ( V_10 -> type -> V_198 )
F_38 ( V_10 ) ;
}
V_2 -> type -> V_201 ( V_2 ) ;
}
static void F_175 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_54 (channel, efx)
V_10 -> V_192 = 0 ;
F_176 ( V_2 -> V_159 ) ;
F_177 ( V_2 -> V_159 ) ;
V_2 -> V_195 = 0 ;
}
static void F_178 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_12 * V_13 ;
V_2 -> V_63 =
V_186 ? V_2 -> V_105 - V_2 -> V_190 : 0 ;
F_54 (channel, efx) {
if ( V_10 -> V_10 < V_2 -> V_191 )
V_10 -> V_19 . V_202 = V_10 -> V_10 ;
else
V_10 -> V_19 . V_202 = - 1 ;
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
V_40 = F_162 ( V_2 ) ;
if ( V_40 )
goto V_142;
F_178 ( V_2 ) ;
V_40 = V_2 -> type -> V_203 ( V_2 ) ;
if ( V_40 )
goto V_146;
if ( V_2 -> V_105 > 1 )
F_180 ( & V_2 -> V_204 ,
sizeof( V_2 -> V_204 ) ) ;
F_149 ( V_2 ) ;
F_181 ( V_2 -> V_7 , V_2 -> V_190 ) ;
F_182 ( V_2 -> V_7 , V_2 -> V_191 ) ;
F_183 ( V_2 , V_205 , V_206 , true ,
true ) ;
return 0 ;
V_146:
F_175 ( V_2 ) ;
V_142:
V_2 -> type -> remove ( V_2 ) ;
return V_40 ;
}
static void F_184 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_6 , V_2 -> V_7 , L_55 ) ;
F_175 ( V_2 ) ;
V_2 -> type -> remove ( V_2 ) ;
}
static int F_185 ( struct V_1 * V_2 )
{
int V_40 ;
F_186 ( & V_2 -> V_207 ) ;
F_187 ( & V_2 -> V_125 ) ;
F_188 ( & V_2 -> V_125 ) ;
V_40 = V_2 -> type -> V_208 ( V_2 ) ;
if ( V_40 )
goto V_209;
#ifdef F_189
if ( V_2 -> type -> V_210 & V_211 ) {
V_2 -> V_212 = F_190 ( V_2 -> type -> V_213 ,
sizeof( * V_2 -> V_212 ) ,
V_47 ) ;
if ( ! V_2 -> V_212 ) {
V_2 -> type -> V_214 ( V_2 ) ;
V_40 = - V_106 ;
goto V_209;
}
}
#endif
V_209:
F_191 ( & V_2 -> V_125 ) ;
return V_40 ;
}
static void F_192 ( struct V_1 * V_2 )
{
#ifdef F_189
F_89 ( V_2 -> V_212 ) ;
#endif
F_188 ( & V_2 -> V_125 ) ;
V_2 -> type -> V_214 ( V_2 ) ;
F_191 ( & V_2 -> V_125 ) ;
}
static void F_193 ( struct V_1 * V_2 )
{
F_107 ( & V_2 -> V_125 ) ;
V_2 -> type -> V_215 ( V_2 ) ;
F_108 ( & V_2 -> V_125 ) ;
}
static int F_194 ( struct V_1 * V_2 )
{
int V_40 ;
V_40 = F_179 ( V_2 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_34 , V_2 -> V_7 , L_56 ) ;
goto V_142;
}
V_40 = F_116 ( V_2 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_34 , V_2 -> V_7 , L_57 ) ;
goto V_146;
}
F_60 ( V_216 < V_217 ) ;
if ( F_68 ( V_216 < F_195 ( V_2 ) ) ) {
V_40 = - V_218 ;
goto V_169;
}
V_2 -> V_35 = V_2 -> V_36 = V_216 ;
#ifdef F_160
V_40 = V_2 -> type -> V_219 ( V_2 ) ;
if ( V_40 )
F_154 ( V_2 , V_34 , V_2 -> V_7 ,
L_58
L_59 , V_40 ) ;
#endif
V_40 = F_185 ( V_2 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_34 , V_2 -> V_7 ,
L_60 ) ;
goto V_171;
}
V_40 = F_55 ( V_2 ) ;
if ( V_40 )
goto V_220;
return 0 ;
V_220:
F_192 ( V_2 ) ;
V_171:
#ifdef F_160
V_2 -> type -> V_221 ( V_2 ) ;
#endif
V_169:
F_127 ( V_2 ) ;
V_146:
F_184 ( V_2 ) ;
V_142:
return V_40 ;
}
static void F_91 ( struct V_1 * V_2 )
{
F_73 ( V_2 ) ;
F_74 ( V_2 -> V_3 == V_4 ) ;
if ( V_2 -> V_93 || ! F_99 ( V_2 -> V_7 ) ||
V_2 -> V_222 )
return;
F_119 ( V_2 ) ;
F_58 ( V_2 ) ;
if ( V_2 -> type -> V_223 != NULL )
F_196 ( V_2 -> V_224 , & V_2 -> V_149 ,
V_225 ) ;
if ( F_197 ( V_2 ) >= V_226 ) {
F_113 ( & V_2 -> V_129 ) ;
if ( V_2 -> V_140 -> V_227 ( V_2 ) )
F_98 ( V_2 ) ;
F_114 ( & V_2 -> V_129 ) ;
}
V_2 -> type -> V_228 ( V_2 ) ;
V_2 -> type -> V_229 ( V_2 ) ;
F_198 ( & V_2 -> V_230 ) ;
V_2 -> type -> V_231 ( V_2 , NULL , NULL ) ;
F_199 ( & V_2 -> V_230 ) ;
}
static void F_85 ( struct V_1 * V_2 )
{
F_73 ( V_2 ) ;
if ( ! V_2 -> V_93 )
return;
V_2 -> type -> V_229 ( V_2 ) ;
F_198 ( & V_2 -> V_230 ) ;
V_2 -> type -> V_231 ( V_2 , NULL , NULL ) ;
F_199 ( & V_2 -> V_230 ) ;
V_2 -> type -> V_232 ( V_2 ) ;
F_120 ( V_2 ) ;
F_68 ( F_99 ( V_2 -> V_7 ) &&
F_70 ( V_2 -> V_7 ) ) ;
F_200 ( V_2 -> V_7 ) ;
F_72 ( V_2 ) ;
}
static void F_201 ( struct V_1 * V_2 )
{
F_57 ( V_2 ) ;
F_192 ( V_2 ) ;
#ifdef F_160
V_2 -> type -> V_221 ( V_2 ) ;
#endif
F_127 ( V_2 ) ;
F_184 ( V_2 ) ;
}
static unsigned int F_202 ( unsigned int V_233 , unsigned int V_234 )
{
if ( V_233 == 0 )
return 0 ;
if ( V_233 * 1000 < V_234 )
return 1 ;
return V_233 * 1000 / V_234 ;
}
int F_183 ( struct V_1 * V_2 , unsigned int V_235 ,
unsigned int V_236 , bool V_237 ,
bool V_238 )
{
struct V_9 * V_10 ;
unsigned int V_239 = F_203 ( V_2 -> type -> V_240 *
V_2 -> V_241 ,
1000 ) ;
unsigned int V_242 ;
unsigned int V_243 ;
F_73 ( V_2 ) ;
if ( V_235 > V_239 || V_236 > V_239 )
return - V_218 ;
V_242 = F_202 ( V_235 , V_2 -> V_241 ) ;
V_243 = F_202 ( V_236 , V_2 -> V_241 ) ;
if ( V_242 != V_243 && V_2 -> V_63 == 0 &&
! V_238 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_61
L_62 ) ;
return - V_218 ;
}
V_2 -> V_25 = V_237 ;
V_2 -> V_32 = V_243 ;
F_54 (channel, efx) {
if ( F_7 ( V_10 ) )
V_10 -> V_29 = V_243 ;
else if ( F_204 ( V_10 ) )
V_10 -> V_29 = V_242 ;
}
return 0 ;
}
void F_205 ( struct V_1 * V_2 , unsigned int * V_235 ,
unsigned int * V_236 , bool * V_237 )
{
* V_237 = V_2 -> V_25 ;
* V_236 = F_203 ( V_2 -> V_32 *
V_2 -> V_241 ,
1000 ) ;
if ( V_2 -> V_63 == 0 )
* V_235 = * V_236 ;
else
* V_235 = F_203 (
V_2 -> V_10 [ V_2 -> V_63 ] -> V_29 *
V_2 -> V_241 ,
1000 ) ;
}
static void F_206 ( struct V_132 * V_133 )
{
struct V_1 * V_2 = F_13 ( V_133 , struct V_1 ,
V_149 . V_244 ) ;
F_15 ( V_2 , V_245 , V_2 -> V_7 ,
L_63 ,
F_16 () ) ;
F_74 ( V_2 -> type -> V_223 == NULL ) ;
if ( F_207 ( & V_2 -> V_129 ) ) {
if ( V_2 -> V_93 )
V_2 -> type -> V_223 ( V_2 ) ;
F_114 ( & V_2 -> V_129 ) ;
}
F_196 ( V_2 -> V_224 , & V_2 -> V_149 ,
V_225 ) ;
}
static int F_208 ( struct V_246 * V_7 , struct V_247 * V_248 , int V_249 )
{
struct V_1 * V_2 = F_209 ( V_7 ) ;
struct V_250 * V_133 = F_210 ( V_248 ) ;
if ( V_249 == V_251 )
return F_211 ( V_2 , V_248 ) ;
if ( V_249 == V_252 )
return F_212 ( V_2 , V_248 ) ;
if ( ( V_249 == V_253 || V_249 == V_254 ) &&
( V_133 -> V_255 & 0xfc00 ) == 0x0400 )
V_133 -> V_255 ^= V_256 | 0x0400 ;
return F_213 ( & V_2 -> V_257 , V_133 , V_249 ) ;
}
static void F_87 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
V_10 -> V_53 = V_2 -> V_7 ;
F_214 ( V_10 -> V_53 , & V_10 -> V_23 ,
F_12 , V_258 ) ;
F_215 ( & V_10 -> V_23 ) ;
F_216 ( V_10 ) ;
}
static void F_217 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_54 (channel, efx)
F_87 ( V_10 ) ;
}
static void F_88 ( struct V_9 * V_10 )
{
if ( V_10 -> V_53 ) {
F_218 ( & V_10 -> V_23 ) ;
F_219 ( & V_10 -> V_23 ) ;
}
V_10 -> V_53 = NULL ;
}
static void F_220 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_54 (channel, efx)
F_88 ( V_10 ) ;
}
static void F_221 ( struct V_246 * V_7 )
{
struct V_1 * V_2 = F_209 ( V_7 ) ;
struct V_9 * V_10 ;
F_54 (channel, efx)
F_222 ( V_10 ) ;
}
static int F_223 ( struct V_21 * V_22 )
{
struct V_9 * V_10 =
F_13 ( V_22 , struct V_9 , V_23 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_11 = 4 ;
int V_259 , V_260 ;
if ( ! F_99 ( V_2 -> V_7 ) )
return V_261 ;
if ( ! F_224 ( V_10 ) )
return V_262 ;
V_259 = V_10 -> V_19 . V_260 ;
F_3 ( V_10 , V_11 ) ;
V_260 = V_10 -> V_19 . V_260 - V_259 ;
F_225 ( V_10 ) ;
return V_260 ;
}
int F_226 ( struct V_246 * V_7 )
{
struct V_1 * V_2 = F_209 ( V_7 ) ;
int V_40 ;
F_22 ( V_2 , V_43 , V_2 -> V_7 , L_64 ,
F_16 () ) ;
V_40 = F_1 ( V_2 ) ;
if ( V_40 )
return V_40 ;
if ( V_2 -> V_128 & V_136 )
return - V_263 ;
if ( F_227 ( V_2 ) && F_228 ( V_2 , V_96 ) )
return - V_8 ;
F_98 ( V_2 ) ;
F_91 ( V_2 ) ;
F_229 ( V_2 ) ;
return 0 ;
}
int F_230 ( struct V_246 * V_7 )
{
struct V_1 * V_2 = F_209 ( V_7 ) ;
F_22 ( V_2 , V_148 , V_2 -> V_7 , L_65 ,
F_16 () ) ;
F_85 ( V_2 ) ;
return 0 ;
}
static struct V_264 * F_231 ( struct V_246 * V_7 ,
struct V_264 * V_265 )
{
struct V_1 * V_2 = F_209 ( V_7 ) ;
F_198 ( & V_2 -> V_230 ) ;
V_2 -> type -> V_231 ( V_2 , NULL , V_265 ) ;
F_199 ( & V_2 -> V_230 ) ;
return V_265 ;
}
static void F_232 ( struct V_246 * V_7 )
{
struct V_1 * V_2 = F_209 ( V_7 ) ;
F_2 ( V_2 , V_266 , V_2 -> V_7 ,
L_66 ,
V_2 -> V_93 ) ;
F_77 ( V_2 , V_267 ) ;
}
static int F_233 ( struct V_246 * V_7 , int V_268 )
{
struct V_1 * V_2 = F_209 ( V_7 ) ;
int V_40 ;
V_40 = F_1 ( V_2 ) ;
if ( V_40 )
return V_40 ;
if ( V_268 > V_269 )
return - V_218 ;
F_22 ( V_2 , V_6 , V_2 -> V_7 , L_67 , V_268 ) ;
F_84 ( V_2 ) ;
F_85 ( V_2 ) ;
F_113 ( & V_2 -> V_129 ) ;
V_7 -> V_73 = V_268 ;
F_106 ( V_2 ) ;
F_114 ( & V_2 -> V_129 ) ;
F_91 ( V_2 ) ;
F_92 ( V_2 -> V_7 ) ;
return 0 ;
}
static int F_234 ( struct V_246 * V_7 , void * V_133 )
{
struct V_1 * V_2 = F_209 ( V_7 ) ;
struct V_270 * V_271 = V_133 ;
T_3 * V_272 = V_271 -> V_273 ;
T_3 V_274 [ 6 ] ;
int V_40 ;
if ( ! F_235 ( V_272 ) ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_68 ,
V_272 ) ;
return - V_275 ;
}
F_117 ( V_274 , V_7 -> V_138 ) ;
F_117 ( V_7 -> V_138 , V_272 ) ;
if ( V_2 -> type -> V_276 ) {
V_40 = V_2 -> type -> V_276 ( V_2 ) ;
if ( V_40 ) {
F_117 ( V_7 -> V_138 , V_274 ) ;
return V_40 ;
}
}
F_113 ( & V_2 -> V_129 ) ;
F_106 ( V_2 ) ;
F_114 ( & V_2 -> V_129 ) ;
return 0 ;
}
static void F_236 ( struct V_246 * V_7 )
{
struct V_1 * V_2 = F_209 ( V_7 ) ;
if ( V_2 -> V_93 )
F_237 ( V_2 -> V_224 , & V_2 -> V_134 ) ;
}
static int F_238 ( struct V_246 * V_7 , T_6 V_133 )
{
struct V_1 * V_2 = F_209 ( V_7 ) ;
if ( V_7 -> V_277 & ~ V_133 & V_211 )
return V_2 -> type -> V_278 ( V_2 , V_279 ) ;
return 0 ;
}
static void F_239 ( struct V_1 * V_2 )
{
strcpy ( V_2 -> V_64 , V_2 -> V_7 -> V_64 ) ;
F_240 ( V_2 ) ;
F_53 ( V_2 ) ;
}
static int F_241 ( struct V_280 * V_281 ,
unsigned long V_282 , void * V_283 )
{
struct V_246 * V_7 = F_242 ( V_283 ) ;
if ( ( V_7 -> V_284 == & V_285 ) &&
V_282 == V_286 )
F_239 ( F_209 ( V_7 ) ) ;
return V_287 ;
}
static T_7
F_243 ( struct V_288 * V_167 , struct V_289 * V_290 , char * V_60 )
{
struct V_1 * V_2 = F_244 ( F_245 ( V_167 ) ) ;
return sprintf ( V_60 , L_69 , V_2 -> V_291 ) ;
}
static T_7 F_246 ( struct V_288 * V_167 , struct V_289 * V_290 ,
char * V_60 )
{
struct V_1 * V_2 = F_244 ( F_245 ( V_167 ) ) ;
struct V_292 * V_293 = F_247 ( V_2 ) ;
return F_248 ( V_60 , V_77 , L_69 , V_293 -> V_294 ) ;
}
static T_7 F_249 ( struct V_288 * V_167 , struct V_289 * V_290 ,
const char * V_60 , T_1 V_175 )
{
struct V_1 * V_2 = F_244 ( F_245 ( V_167 ) ) ;
struct V_292 * V_293 = F_247 ( V_2 ) ;
bool V_295 = V_175 > 0 && * V_60 != '0' ;
V_293 -> V_294 = V_295 ;
return V_175 ;
}
static int F_250 ( struct V_1 * V_2 )
{
struct V_246 * V_7 = V_2 -> V_7 ;
struct V_9 * V_10 ;
int V_40 ;
V_7 -> V_296 = 5 * V_297 ;
V_7 -> V_192 = V_2 -> V_159 -> V_192 ;
V_7 -> V_284 = & V_285 ;
if ( F_197 ( V_2 ) >= V_298 )
V_7 -> V_299 |= V_300 ;
V_7 -> V_301 = & V_302 ;
V_7 -> V_303 = V_304 ;
F_251 () ;
V_2 -> V_3 = V_305 ;
F_252 () ;
if ( V_2 -> V_222 ) {
F_2 ( V_2 , V_34 , V_2 -> V_7 ,
L_70 ) ;
V_40 = - V_8 ;
goto V_306;
}
V_40 = F_253 ( V_7 , V_7 -> V_64 ) ;
if ( V_40 < 0 )
goto V_306;
F_239 ( V_2 ) ;
F_102 ( V_7 ) ;
V_40 = F_254 ( V_7 ) ;
if ( V_40 )
goto V_306;
F_54 (channel, efx) {
struct V_12 * V_13 ;
F_5 (tx_queue, channel)
F_255 ( V_13 ) ;
}
F_129 ( V_2 ) ;
F_256 () ;
V_40 = F_257 ( & V_2 -> V_159 -> V_167 , & V_307 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_71 ) ;
goto V_308;
}
#ifdef F_258
V_40 = F_257 ( & V_2 -> V_159 -> V_167 , & V_309 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_71 ) ;
goto V_310;
}
#endif
return 0 ;
#ifdef F_258
V_310:
F_259 ( & V_2 -> V_159 -> V_167 , & V_307 ) ;
#endif
V_308:
F_251 () ;
F_135 ( V_2 ) ;
F_260 ( V_7 ) ;
V_306:
V_2 -> V_3 = V_311 ;
F_256 () ;
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_72 ) ;
return V_40 ;
}
static void F_261 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_7 )
return;
F_74 ( F_209 ( V_2 -> V_7 ) != V_2 ) ;
if ( F_262 ( V_2 ) ) {
F_263 ( V_2 -> V_64 , F_133 ( V_2 -> V_159 ) , sizeof( V_2 -> V_64 ) ) ;
#ifdef F_258
F_259 ( & V_2 -> V_159 -> V_167 , & V_309 ) ;
#endif
F_259 ( & V_2 -> V_159 -> V_167 , & V_307 ) ;
F_264 ( V_2 -> V_7 ) ;
}
}
void F_265 ( struct V_1 * V_2 , enum V_312 V_313 )
{
F_73 ( V_2 ) ;
if ( V_313 == V_314 )
V_2 -> type -> V_315 ( V_2 ) ;
F_85 ( V_2 ) ;
F_174 ( V_2 ) ;
F_113 ( & V_2 -> V_129 ) ;
if ( V_2 -> V_143 && V_313 != V_316 &&
V_313 != V_317 )
V_2 -> V_140 -> V_147 ( V_2 ) ;
V_2 -> type -> V_147 ( V_2 ) ;
}
int F_266 ( struct V_1 * V_2 , enum V_312 V_313 , bool V_318 )
{
int V_40 ;
F_73 ( V_2 ) ;
if ( V_313 == V_314 )
V_2 -> type -> V_319 ( V_2 ) ;
V_40 = V_2 -> type -> V_141 ( V_2 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_73 ) ;
goto V_59;
}
if ( ! V_318 )
goto V_59;
if ( V_2 -> V_143 && V_313 != V_316 &&
V_313 != V_317 ) {
V_40 = V_2 -> V_140 -> V_141 ( V_2 ) ;
if ( V_40 )
goto V_59;
V_40 = V_2 -> V_140 -> V_144 ( V_2 ) ;
if ( V_40 && V_40 != - V_145 )
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_74 ) ;
}
V_40 = F_172 ( V_2 ) ;
if ( V_40 )
goto V_59;
#ifdef F_160
V_40 = V_2 -> type -> V_320 ( V_2 ) ;
if ( V_40 )
F_154 ( V_2 , V_34 , V_2 -> V_7 ,
L_75
L_59 , V_40 ) ;
#endif
F_107 ( & V_2 -> V_125 ) ;
F_193 ( V_2 ) ;
F_108 ( & V_2 -> V_125 ) ;
if ( V_2 -> type -> V_321 )
V_2 -> type -> V_321 ( V_2 ) ;
F_114 ( & V_2 -> V_129 ) ;
F_91 ( V_2 ) ;
return 0 ;
V_59:
V_2 -> V_143 = false ;
F_114 ( & V_2 -> V_129 ) ;
return V_40 ;
}
int F_228 ( struct V_1 * V_2 , enum V_312 V_313 )
{
int V_40 , V_102 ;
bool V_322 ;
F_103 ( V_2 , V_6 , V_2 -> V_7 , L_76 ,
F_267 ( V_313 ) ) ;
F_84 ( V_2 ) ;
F_265 ( V_2 , V_313 ) ;
V_40 = V_2 -> type -> V_323 ( V_2 , V_313 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_77 ) ;
goto V_107;
}
if ( V_313 < V_324 )
V_2 -> V_222 &= - ( 1 << ( V_313 + 1 ) ) ;
else
F_268 ( V_313 , & V_2 -> V_222 ) ;
F_138 ( V_2 -> V_159 ) ;
V_107:
V_322 = V_40 ||
V_313 == V_109 ||
V_313 == V_325 ;
V_102 = F_266 ( V_2 , V_313 , ! V_322 ) ;
if ( V_102 ) {
V_322 = true ;
if ( ! V_40 )
V_40 = V_102 ;
}
if ( V_322 ) {
F_269 ( V_2 -> V_7 ) ;
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_78 ) ;
V_2 -> V_3 = V_4 ;
} else {
F_22 ( V_2 , V_6 , V_2 -> V_7 , L_79 ) ;
F_92 ( V_2 -> V_7 ) ;
}
return V_40 ;
}
int F_270 ( struct V_1 * V_2 )
{
#ifdef F_271
struct V_326 * V_327 = F_272 ( V_2 -> V_159 ) ;
if ( F_273 ( V_327 ) ) {
return 1 ;
}
#endif
return 0 ;
}
static void F_274 ( struct V_1 * V_2 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_328 ; ++ V_44 ) {
if ( F_227 ( V_2 ) )
goto V_107;
F_275 ( V_329 ) ;
}
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_80 ) ;
V_107:
V_2 -> V_330 = false ;
}
static void F_276 ( struct V_132 * V_133 )
{
struct V_1 * V_2 = F_13 ( V_133 , struct V_1 , V_331 ) ;
unsigned long V_332 ;
enum V_312 V_313 ;
V_332 = F_277 ( V_2 -> V_222 ) ;
V_313 = F_278 ( V_332 ) - 1 ;
if ( V_313 == V_333 )
F_274 ( V_2 ) ;
if ( ( V_313 == V_325 ||
V_313 == V_334 ) &&
F_270 ( V_2 ) )
return;
if ( ! V_332 )
return;
F_251 () ;
if ( V_2 -> V_3 == V_305 )
( void ) F_228 ( V_2 , V_313 ) ;
F_256 () ;
}
void F_77 ( struct V_1 * V_2 , enum V_312 type )
{
enum V_312 V_313 ;
if ( V_2 -> V_3 == V_5 ) {
F_22 ( V_2 , V_6 , V_2 -> V_7 ,
L_81 ,
F_267 ( type ) ) ;
return;
}
switch ( type ) {
case V_316 :
case V_96 :
case V_334 :
case V_335 :
case V_109 :
case V_325 :
case V_317 :
case V_333 :
case V_314 :
V_313 = type ;
F_22 ( V_2 , V_6 , V_2 -> V_7 , L_82 ,
F_267 ( V_313 ) ) ;
break;
default:
V_313 = V_2 -> type -> V_336 ( type ) ;
F_22 ( V_2 , V_6 , V_2 -> V_7 ,
L_83 ,
F_267 ( V_313 ) , F_267 ( type ) ) ;
break;
}
F_279 ( V_313 , & V_2 -> V_222 ) ;
F_252 () ;
if ( F_277 ( V_2 -> V_3 ) != V_305 )
return;
F_169 ( V_2 ) ;
F_237 ( V_337 , & V_2 -> V_331 ) ;
}
int F_280 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_281 ( struct V_1 * V_2 ) {}
static bool F_282 ( struct V_1 * V_2 )
{
return false ;
}
static int F_283 ( struct V_1 * V_2 ,
struct V_159 * V_159 , struct V_246 * V_7 )
{
int V_44 ;
F_284 ( & V_2 -> V_157 ) ;
F_284 ( & V_2 -> V_160 ) ;
F_186 ( & V_2 -> V_338 ) ;
#ifdef F_285
F_284 ( & V_2 -> V_339 ) ;
#endif
F_286 ( & V_2 -> V_331 , F_276 ) ;
F_287 ( & V_2 -> V_149 , F_206 ) ;
F_287 ( & V_2 -> V_340 , V_341 ) ;
V_2 -> V_159 = V_159 ;
V_2 -> V_342 = V_343 ;
V_2 -> V_3 = V_311 ;
F_263 ( V_2 -> V_64 , F_133 ( V_159 ) , sizeof( V_2 -> V_64 ) ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_72 = V_2 -> type -> V_72 ;
V_2 -> V_76 =
V_83 ? ( V_2 -> V_72 + V_83 ) % 4 : 0 ;
V_2 -> V_344 =
V_2 -> type -> V_345 - V_2 -> type -> V_72 ;
V_2 -> V_346 =
V_2 -> type -> V_347 - V_2 -> type -> V_72 ;
F_186 ( & V_2 -> V_230 ) ;
F_288 ( & V_2 -> V_129 ) ;
V_2 -> V_140 = & V_348 ;
V_2 -> V_257 . V_167 = V_7 ;
F_286 ( & V_2 -> V_134 , F_115 ) ;
F_289 ( & V_2 -> V_349 ) ;
for ( V_44 = 0 ; V_44 < V_99 ; V_44 ++ ) {
V_2 -> V_10 [ V_44 ] = F_42 ( V_2 , V_44 , NULL ) ;
if ( ! V_2 -> V_10 [ V_44 ] )
goto V_59;
V_2 -> V_66 [ V_44 ] . V_2 = V_2 ;
V_2 -> V_66 [ V_44 ] . V_104 = V_44 ;
}
V_2 -> V_182 = F_25 ( V_2 -> type -> V_350 ,
V_182 ) ;
snprintf ( V_2 -> V_351 , sizeof( V_2 -> V_351 ) , L_84 ,
F_133 ( V_159 ) ) ;
V_2 -> V_224 = F_290 ( V_2 -> V_351 ) ;
if ( ! V_2 -> V_224 )
goto V_59;
return 0 ;
V_59:
F_291 ( V_2 ) ;
return - V_106 ;
}
static void F_291 ( struct V_1 * V_2 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_99 ; V_44 ++ )
F_89 ( V_2 -> V_10 [ V_44 ] ) ;
F_89 ( V_2 -> V_153 ) ;
if ( V_2 -> V_224 ) {
F_292 ( V_2 -> V_224 ) ;
V_2 -> V_224 = NULL ;
}
}
void F_293 ( struct V_1 * V_2 , T_8 * V_265 )
{
T_8 V_352 = 0 ;
struct V_9 * V_10 ;
F_54 (channel, efx)
V_352 += V_10 -> V_352 ;
V_265 [ V_353 ] = V_352 ;
V_265 [ V_354 ] = F_294 ( & V_2 -> V_355 ) ;
}
static void F_295 ( struct V_1 * V_2 )
{
F_74 ( V_2 -> V_3 == V_305 ) ;
F_125 ( & V_2 -> V_331 ) ;
F_174 ( V_2 ) ;
F_296 ( V_2 ) ;
F_126 ( V_2 ) ;
V_2 -> type -> V_147 ( V_2 ) ;
F_220 ( V_2 ) ;
F_201 ( V_2 ) ;
}
static void F_297 ( struct V_159 * V_159 )
{
struct V_1 * V_2 ;
V_2 = F_244 ( V_159 ) ;
if ( ! V_2 )
return;
F_251 () ;
F_135 ( V_2 ) ;
F_269 ( V_2 -> V_7 ) ;
F_174 ( V_2 ) ;
V_2 -> V_3 = V_311 ;
F_256 () ;
if ( V_2 -> type -> V_356 )
V_2 -> type -> V_356 ( V_2 ) ;
F_261 ( V_2 ) ;
F_298 ( V_2 ) ;
F_295 ( V_2 ) ;
F_146 ( V_2 ) ;
F_22 ( V_2 , V_6 , V_2 -> V_7 , L_85 ) ;
F_291 ( V_2 ) ;
F_299 ( V_2 -> V_7 ) ;
F_300 ( V_159 ) ;
}
static void F_301 ( struct V_1 * V_2 )
{
struct V_159 * V_167 = V_2 -> V_159 ;
char V_357 [ V_358 ] ;
T_7 V_359 ;
int V_360 , V_361 , V_44 , V_46 ;
V_359 = F_302 ( V_167 , 0 , sizeof( V_357 ) , V_357 ) ;
if ( V_359 <= 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_86 ) ;
return;
}
V_360 = F_303 ( V_357 , 0 , V_359 , V_362 ) ;
if ( V_360 < 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_87 ) ;
return;
}
V_361 = F_304 ( & V_357 [ V_360 ] ) ;
V_46 = V_361 ;
V_44 = V_360 + V_363 ;
if ( V_44 + V_46 > V_359 )
V_46 = V_359 - V_44 ;
V_44 = F_305 ( V_357 , V_44 , V_46 , L_88 ) ;
if ( V_44 < 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_89 ) ;
return;
}
V_46 = F_306 ( & V_357 [ V_44 ] ) ;
V_44 += V_364 ;
if ( V_44 + V_46 > V_359 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_90 ) ;
return;
}
F_103 ( V_2 , V_6 , V_2 -> V_7 ,
L_91 , V_46 , & V_357 [ V_44 ] ) ;
V_44 = V_360 + V_363 ;
V_46 = V_361 ;
V_44 = F_305 ( V_357 , V_44 , V_46 , L_92 ) ;
if ( V_44 < 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_93 ) ;
return;
}
V_46 = F_306 ( & V_357 [ V_44 ] ) ;
V_44 += V_364 ;
if ( V_44 + V_46 > V_359 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_94 ) ;
return;
}
V_2 -> V_153 = F_46 ( V_46 + 1 , V_47 ) ;
if ( ! V_2 -> V_153 )
return;
snprintf ( V_2 -> V_153 , V_46 + 1 , L_95 , & V_357 [ V_44 ] ) ;
}
static int F_307 ( struct V_1 * V_2 )
{
int V_40 ;
V_40 = F_194 ( V_2 ) ;
if ( V_40 )
goto V_142;
F_217 ( V_2 ) ;
V_40 = V_2 -> type -> V_141 ( V_2 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_34 , V_2 -> V_7 ,
L_73 ) ;
goto V_169;
}
V_40 = F_118 ( V_2 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_34 , V_2 -> V_7 ,
L_96 ) ;
goto V_171;
}
V_40 = F_308 ( V_2 ) ;
if ( V_40 )
goto V_220;
V_40 = F_172 ( V_2 ) ;
if ( V_40 )
goto V_365;
return 0 ;
V_365:
F_296 ( V_2 ) ;
V_220:
F_126 ( V_2 ) ;
V_171:
V_2 -> type -> V_147 ( V_2 ) ;
V_169:
F_220 ( V_2 ) ;
F_201 ( V_2 ) ;
V_142:
return V_40 ;
}
static int F_309 ( struct V_159 * V_159 ,
const struct V_366 * V_188 )
{
struct V_246 * V_7 ;
struct V_1 * V_2 ;
int V_40 ;
V_7 = F_310 ( sizeof( * V_2 ) , V_367 ,
V_368 ) ;
if ( ! V_7 )
return - V_106 ;
V_2 = F_209 ( V_7 ) ;
V_2 -> type = ( const struct V_369 * ) V_188 -> V_370 ;
V_7 -> V_277 |= ( V_2 -> type -> V_210 | V_371 |
V_372 | V_373 |
V_374 ) ;
if ( V_2 -> type -> V_210 & V_375 )
V_7 -> V_277 |= V_376 ;
V_7 -> V_377 |= ( V_378 | V_371 |
V_372 | V_379 |
V_374 ) ;
V_7 -> V_380 = V_7 -> V_277 & ~ V_372 ;
F_311 ( V_159 , V_2 ) ;
F_312 ( V_7 , & V_159 -> V_167 ) ;
V_40 = F_283 ( V_2 , V_159 , V_7 ) ;
if ( V_40 )
goto V_142;
F_103 ( V_2 , V_34 , V_2 -> V_7 ,
L_97 ) ;
if ( ! V_2 -> type -> V_381 )
F_301 ( V_2 ) ;
V_40 = F_136 ( V_2 ) ;
if ( V_40 )
goto V_146;
V_40 = F_307 ( V_2 ) ;
if ( V_40 )
goto V_169;
V_40 = F_250 ( V_2 ) ;
if ( V_40 )
goto V_171;
if ( V_2 -> type -> V_382 ) {
V_40 = V_2 -> type -> V_382 ( V_2 ) ;
if ( V_40 )
F_2 ( V_2 , V_34 , V_2 -> V_7 ,
L_98 , V_40 ) ;
}
F_22 ( V_2 , V_34 , V_2 -> V_7 , L_99 ) ;
F_251 () ;
V_40 = F_313 ( V_2 ) ;
F_256 () ;
if ( V_40 )
F_154 ( V_2 , V_34 , V_2 -> V_7 ,
L_100 , V_40 ) ;
V_40 = F_314 ( V_159 ) ;
if ( V_40 && V_40 != - V_218 )
F_154 ( V_2 , V_34 , V_2 -> V_7 ,
L_101 , V_40 ) ;
return 0 ;
V_171:
F_295 ( V_2 ) ;
V_169:
F_146 ( V_2 ) ;
V_146:
F_291 ( V_2 ) ;
V_142:
F_68 ( V_40 > 0 ) ;
F_22 ( V_2 , V_6 , V_2 -> V_7 , L_102 , V_40 ) ;
F_299 ( V_7 ) ;
return V_40 ;
}
static int F_315 ( struct V_159 * V_167 , int V_383 )
{
int V_40 ;
struct V_1 * V_2 = F_244 ( V_167 ) ;
if ( V_2 -> type -> V_384 ) {
V_40 = V_2 -> type -> V_384 ( V_2 , V_383 ) ;
if ( V_40 )
return V_40 ;
else
return V_383 ;
} else
return - V_385 ;
}
static int F_316 ( struct V_288 * V_167 )
{
struct V_1 * V_2 = F_244 ( F_245 ( V_167 ) ) ;
F_251 () ;
if ( V_2 -> V_3 != V_4 ) {
V_2 -> V_3 = V_311 ;
F_84 ( V_2 ) ;
F_85 ( V_2 ) ;
F_174 ( V_2 ) ;
}
F_256 () ;
return 0 ;
}
static int F_317 ( struct V_288 * V_167 )
{
int V_40 ;
struct V_1 * V_2 = F_244 ( F_245 ( V_167 ) ) ;
F_251 () ;
if ( V_2 -> V_3 != V_4 ) {
V_40 = F_172 ( V_2 ) ;
if ( V_40 )
goto V_59;
F_113 ( & V_2 -> V_129 ) ;
V_2 -> V_140 -> V_144 ( V_2 ) ;
F_114 ( & V_2 -> V_129 ) ;
F_91 ( V_2 ) ;
F_92 ( V_2 -> V_7 ) ;
V_2 -> V_3 = V_305 ;
V_2 -> type -> V_386 ( V_2 ) ;
}
F_256 () ;
F_237 ( V_337 , & V_2 -> V_331 ) ;
return 0 ;
V_59:
F_256 () ;
return V_40 ;
}
static int F_318 ( struct V_288 * V_167 )
{
struct V_159 * V_159 = F_245 ( V_167 ) ;
struct V_1 * V_2 = F_244 ( V_159 ) ;
V_2 -> type -> V_147 ( V_2 ) ;
V_2 -> V_222 = 0 ;
F_319 ( V_159 ) ;
return F_320 ( V_159 , V_387 ) ;
}
static int F_321 ( struct V_288 * V_167 )
{
struct V_159 * V_159 = F_245 ( V_167 ) ;
struct V_1 * V_2 = F_244 ( V_159 ) ;
int V_40 ;
V_40 = F_320 ( V_159 , V_388 ) ;
if ( V_40 )
return V_40 ;
F_322 ( V_159 ) ;
V_40 = F_137 ( V_159 ) ;
if ( V_40 )
return V_40 ;
F_138 ( V_2 -> V_159 ) ;
V_40 = V_2 -> type -> V_323 ( V_2 , V_96 ) ;
if ( V_40 )
return V_40 ;
V_40 = V_2 -> type -> V_141 ( V_2 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_317 ( V_167 ) ;
return V_40 ;
}
static int F_323 ( struct V_288 * V_167 )
{
int V_40 ;
F_316 ( V_167 ) ;
V_40 = F_318 ( V_167 ) ;
if ( V_40 )
F_321 ( V_167 ) ;
return V_40 ;
}
static T_9 F_324 ( struct V_159 * V_389 ,
enum V_390 V_3 )
{
T_9 V_391 = V_392 ;
struct V_1 * V_2 = F_244 ( V_389 ) ;
if ( V_3 == V_393 )
return V_394 ;
F_251 () ;
if ( V_2 -> V_3 != V_4 ) {
V_2 -> V_3 = V_5 ;
V_2 -> V_222 = 0 ;
F_84 ( V_2 ) ;
F_85 ( V_2 ) ;
F_174 ( V_2 ) ;
V_391 = V_395 ;
} else {
V_391 = V_392 ;
}
F_256 () ;
F_145 ( V_389 ) ;
return V_391 ;
}
static T_9 F_325 ( struct V_159 * V_389 )
{
struct V_1 * V_2 = F_244 ( V_389 ) ;
T_9 V_391 = V_392 ;
int V_40 ;
if ( F_137 ( V_389 ) ) {
F_2 ( V_2 , V_396 , V_2 -> V_7 ,
L_103 ) ;
V_391 = V_394 ;
}
V_40 = F_326 ( V_389 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_396 , V_2 -> V_7 ,
L_104 , V_40 ) ;
}
return V_391 ;
}
static void F_327 ( struct V_159 * V_389 )
{
struct V_1 * V_2 = F_244 ( V_389 ) ;
int V_40 ;
F_251 () ;
if ( V_2 -> V_3 == V_4 )
goto V_107;
V_40 = F_228 ( V_2 , V_96 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_396 , V_2 -> V_7 ,
L_105 , V_40 ) ;
} else {
V_2 -> V_3 = V_305 ;
F_22 ( V_2 , V_396 , V_2 -> V_7 ,
L_106 ) ;
}
V_107:
F_256 () ;
}
static int T_10 F_328 ( void )
{
int V_40 ;
F_329 ( V_397 L_107 V_398 L_108 ) ;
V_40 = F_330 ( & V_399 ) ;
if ( V_40 )
goto V_400;
#ifdef F_160
V_40 = F_331 () ;
if ( V_40 )
goto V_401;
#endif
V_337 = F_290 ( L_109 ) ;
if ( ! V_337 ) {
V_40 = - V_106 ;
goto V_402;
}
V_40 = F_332 ( & V_403 ) ;
if ( V_40 < 0 )
goto V_404;
return 0 ;
V_404:
F_292 ( V_337 ) ;
V_402:
#ifdef F_160
F_333 () ;
V_401:
#endif
F_334 ( & V_399 ) ;
V_400:
return V_40 ;
}
static void T_11 F_335 ( void )
{
F_329 ( V_397 L_110 ) ;
F_336 ( & V_403 ) ;
F_292 ( V_337 ) ;
#ifdef F_160
F_333 () ;
#endif
F_334 ( & V_399 ) ;
}

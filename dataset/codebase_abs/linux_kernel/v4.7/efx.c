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
V_40 = F_139 ( & V_159 -> V_167 , V_162 ) ;
if ( V_40 == 0 )
break;
V_162 >>= 1 ;
}
if ( V_40 ) {
F_2 ( V_2 , V_34 , V_2 -> V_7 ,
L_38 ) ;
goto V_146;
}
F_22 ( V_2 , V_34 , V_2 -> V_7 ,
L_39 , ( unsigned long long ) V_162 ) ;
V_2 -> V_168 = F_140 ( V_2 -> V_159 , V_165 ) ;
V_40 = F_141 ( V_159 , V_165 , L_40 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_34 , V_2 -> V_7 ,
L_41 ) ;
V_40 = - V_8 ;
goto V_169;
}
V_2 -> V_170 = F_142 ( V_2 -> V_168 , V_164 ) ;
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
F_143 ( V_2 -> V_159 , V_165 ) ;
V_169:
V_2 -> V_168 = 0 ;
V_146:
F_144 ( V_2 -> V_159 ) ;
V_142:
return V_40 ;
}
static void F_145 ( struct V_1 * V_2 )
{
int V_165 ;
F_22 ( V_2 , V_6 , V_2 -> V_7 , L_44 ) ;
if ( V_2 -> V_170 ) {
F_146 ( V_2 -> V_170 ) ;
V_2 -> V_170 = NULL ;
}
if ( V_2 -> V_168 ) {
V_165 = V_2 -> type -> V_166 ;
F_143 ( V_2 -> V_159 , V_165 ) ;
V_2 -> V_168 = 0 ;
}
if ( ! F_147 ( V_2 -> V_159 ) )
F_144 ( V_2 -> V_159 ) ;
}
void F_148 ( struct V_1 * V_2 )
{
T_1 V_44 ;
for ( V_44 = 0 ; V_44 < F_149 ( V_2 -> V_172 ) ; V_44 ++ )
V_2 -> V_172 [ V_44 ] =
F_150 ( V_44 , V_2 -> V_173 ) ;
}
static unsigned int F_151 ( struct V_1 * V_2 )
{
T_5 V_174 ;
unsigned int V_175 ;
int V_176 ;
if ( V_177 ) {
V_175 = V_177 ;
} else {
if ( F_4 ( ! F_152 ( & V_174 , V_47 ) ) ) {
F_153 ( V_2 , V_34 , V_2 -> V_7 ,
L_45 ) ;
return 1 ;
}
V_175 = 0 ;
F_154 (cpu) {
if ( ! F_155 ( V_176 , V_174 ) ) {
++ V_175 ;
F_156 ( V_174 , V_174 ,
F_157 ( V_176 ) ) ;
}
}
F_158 ( V_174 ) ;
}
#ifdef F_159
if ( V_2 -> type -> V_178 ) {
if ( V_2 -> type -> V_178 ( V_2 ) && F_160 ( V_2 ) > 1 &&
V_175 > F_160 ( V_2 ) ) {
F_153 ( V_2 , V_34 , V_2 -> V_7 ,
L_46
L_47
L_48 ,
V_175 , F_160 ( V_2 ) ) ;
V_175 = F_160 ( V_2 ) ;
}
}
#endif
return V_175 ;
}
static int F_161 ( struct V_1 * V_2 )
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
V_105 = F_151 ( V_2 ) ;
if ( V_186 )
V_105 *= 2 ;
V_105 += V_179 ;
V_105 = F_162 ( V_105 , V_2 -> V_187 ) ;
for ( V_44 = 0 ; V_44 < V_105 ; V_44 ++ )
V_185 [ V_44 ] . V_188 = V_44 ;
V_40 = F_163 ( V_2 -> V_159 ,
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
V_2 -> V_190 = F_162 ( F_25 ( V_105 / 2 ,
1U ) ,
V_2 -> V_191 ) ;
V_2 -> V_192 = F_25 ( V_105 -
V_2 -> V_190 ,
1U ) ;
} else {
V_2 -> V_190 = F_162 ( V_105 ,
V_2 -> V_191 ) ;
V_2 -> V_192 = V_105 ;
}
for ( V_44 = 0 ; V_44 < V_2 -> V_105 ; V_44 ++ )
F_164 ( V_2 , V_44 ) -> V_193 =
V_185 [ V_44 ] . V_194 ;
}
}
if ( V_2 -> V_182 == V_189 ) {
V_2 -> V_105 = 1 ;
V_2 -> V_192 = 1 ;
V_2 -> V_190 = 1 ;
V_40 = F_165 ( V_2 -> V_159 ) ;
if ( V_40 == 0 ) {
F_164 ( V_2 , 0 ) -> V_193 = V_2 -> V_159 -> V_193 ;
} else {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_53 ) ;
V_2 -> V_182 = V_195 ;
}
}
if ( V_2 -> V_182 == V_195 ) {
V_2 -> V_105 = 1 + ( V_186 ? 1 : 0 ) ;
V_2 -> V_192 = 1 ;
V_2 -> V_190 = 1 ;
V_2 -> V_196 = V_2 -> V_159 -> V_193 ;
}
V_46 = V_2 -> V_105 ;
for ( V_44 = 0 ; V_44 < V_180 ; V_44 ++ ) {
if ( ! V_2 -> V_181 [ V_44 ] )
continue;
if ( V_2 -> V_182 != V_183 ||
V_2 -> V_105 <= V_179 ) {
V_2 -> V_181 [ V_44 ] -> F_166 ( V_2 ) ;
} else {
-- V_46 ;
F_164 ( V_2 , V_46 ) -> type =
V_2 -> V_181 [ V_44 ] ;
}
}
#ifdef F_159
if ( V_2 -> type -> V_178 ) {
V_2 -> V_173 = ( ( V_2 -> V_192 > 1 ||
! V_2 -> type -> V_178 ( V_2 ) ) ?
V_2 -> V_192 : F_160 ( V_2 ) ) ;
return 0 ;
}
#endif
V_2 -> V_173 = V_2 -> V_192 ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 )
{
struct V_9 * V_10 , * V_197 ;
int V_40 ;
F_74 ( V_2 -> V_3 == V_4 ) ;
V_2 -> V_198 = true ;
F_31 () ;
F_54 (channel, efx) {
if ( ! V_10 -> type -> V_199 ) {
V_40 = F_27 ( V_10 ) ;
if ( V_40 )
goto V_59;
}
F_30 ( V_10 ) ;
}
F_167 ( V_2 ) ;
return 0 ;
V_59:
V_197 = V_10 ;
F_54 (channel, efx) {
if ( V_10 == V_197 )
break;
F_34 ( V_10 ) ;
if ( ! V_10 -> type -> V_199 )
F_38 ( V_10 ) ;
}
return V_40 ;
}
static void F_86 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
if ( V_2 -> V_3 == V_4 )
return;
F_168 ( V_2 ) ;
V_2 -> V_198 = false ;
F_31 () ;
if ( V_2 -> V_196 )
F_169 ( V_2 -> V_196 ) ;
F_54 (channel, efx) {
if ( V_10 -> V_193 )
F_169 ( V_10 -> V_193 ) ;
F_34 ( V_10 ) ;
if ( ! V_10 -> type -> V_199 )
F_38 ( V_10 ) ;
}
F_170 ( V_2 ) ;
}
static int F_171 ( struct V_1 * V_2 )
{
struct V_9 * V_10 , * V_197 ;
int V_40 ;
F_74 ( V_2 -> V_3 == V_4 ) ;
if ( V_2 -> V_200 ) {
F_172 ( V_2 -> V_196 ) ;
V_2 -> V_200 = false ;
}
V_2 -> type -> V_201 ( V_2 ) ;
F_54 (channel, efx) {
if ( V_10 -> type -> V_199 ) {
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
V_197 = V_10 ;
F_54 (channel, efx) {
if ( V_10 == V_197 )
break;
if ( V_10 -> type -> V_199 )
F_38 ( V_10 ) ;
}
V_2 -> type -> V_202 ( V_2 ) ;
return V_40 ;
}
static void F_173 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_86 ( V_2 ) ;
F_54 (channel, efx) {
if ( V_10 -> type -> V_199 )
F_38 ( V_10 ) ;
}
V_2 -> type -> V_202 ( V_2 ) ;
}
static void F_174 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_54 (channel, efx)
V_10 -> V_193 = 0 ;
F_175 ( V_2 -> V_159 ) ;
F_176 ( V_2 -> V_159 ) ;
V_2 -> V_196 = 0 ;
}
static void F_177 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_12 * V_13 ;
V_2 -> V_63 =
V_186 ?
V_2 -> V_105 - V_2 -> V_190 : 0 ;
F_54 (channel, efx) {
if ( V_10 -> V_10 < V_2 -> V_192 )
V_10 -> V_19 . V_203 = V_10 -> V_10 ;
else
V_10 -> V_19 . V_203 = - 1 ;
F_5 (tx_queue, channel)
V_13 -> V_50 -= ( V_2 -> V_63 *
V_49 ) ;
}
}
static int F_178 ( struct V_1 * V_2 )
{
int V_40 ;
F_22 ( V_2 , V_34 , V_2 -> V_7 , L_54 ) ;
V_40 = V_2 -> type -> V_34 ( V_2 ) ;
if ( V_40 )
return V_40 ;
do {
if ( ! V_2 -> V_187 || ! V_2 -> V_191 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_55
L_56 ) ;
V_40 = - V_204 ;
goto V_142;
}
V_40 = F_161 ( V_2 ) ;
if ( V_40 )
goto V_142;
F_177 ( V_2 ) ;
V_40 = V_2 -> type -> V_205 ( V_2 ) ;
if ( V_40 != 0 && V_40 != - V_206 )
goto V_146;
if ( V_40 == - V_206 )
F_174 ( V_2 ) ;
} while ( V_40 == - V_206 );
if ( V_2 -> V_105 > 1 )
F_179 ( & V_2 -> V_207 ,
sizeof( V_2 -> V_207 ) ) ;
F_148 ( V_2 ) ;
F_180 ( V_2 -> V_7 , V_2 -> V_190 ) ;
F_181 ( V_2 -> V_7 , V_2 -> V_192 ) ;
F_182 ( V_2 , V_208 , V_209 , true ,
true ) ;
return 0 ;
V_146:
F_174 ( V_2 ) ;
V_142:
V_2 -> type -> remove ( V_2 ) ;
return V_40 ;
}
static void F_183 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_6 , V_2 -> V_7 , L_57 ) ;
F_174 ( V_2 ) ;
V_2 -> type -> remove ( V_2 ) ;
}
static int F_184 ( struct V_1 * V_2 )
{
int V_40 ;
F_185 ( & V_2 -> V_210 ) ;
F_186 ( & V_2 -> V_125 ) ;
F_187 ( & V_2 -> V_125 ) ;
V_40 = V_2 -> type -> V_211 ( V_2 ) ;
if ( V_40 )
goto V_212;
#ifdef F_188
if ( V_2 -> type -> V_213 & V_214 ) {
struct V_9 * V_10 ;
int V_44 , V_215 = 1 ;
F_54 (channel, efx) {
V_10 -> V_216 =
F_189 ( V_2 -> type -> V_217 ,
sizeof( * V_10 -> V_216 ) ,
V_47 ) ;
if ( ! V_10 -> V_216 )
V_215 = 0 ;
else
for ( V_44 = 0 ;
V_44 < V_2 -> type -> V_217 ;
++ V_44 )
V_10 -> V_216 [ V_44 ] =
V_218 ;
}
if ( ! V_215 ) {
F_54 (channel, efx)
F_89 ( V_10 -> V_216 ) ;
V_2 -> type -> V_219 ( V_2 ) ;
V_40 = - V_106 ;
goto V_212;
}
V_2 -> V_220 = V_2 -> V_221 = 0 ;
}
#endif
V_212:
F_190 ( & V_2 -> V_125 ) ;
return V_40 ;
}
static void F_191 ( struct V_1 * V_2 )
{
#ifdef F_188
struct V_9 * V_10 ;
F_54 (channel, efx)
F_89 ( V_10 -> V_216 ) ;
#endif
F_187 ( & V_2 -> V_125 ) ;
V_2 -> type -> V_219 ( V_2 ) ;
F_190 ( & V_2 -> V_125 ) ;
}
static void F_192 ( struct V_1 * V_2 )
{
F_107 ( & V_2 -> V_125 ) ;
V_2 -> type -> V_222 ( V_2 ) ;
F_108 ( & V_2 -> V_125 ) ;
}
static int F_193 ( struct V_1 * V_2 )
{
int V_40 ;
V_40 = F_178 ( V_2 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_34 , V_2 -> V_7 , L_58 ) ;
goto V_142;
}
V_40 = F_116 ( V_2 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_34 , V_2 -> V_7 , L_59 ) ;
goto V_146;
}
F_60 ( V_223 < V_224 ) ;
if ( F_68 ( V_223 < F_194 ( V_2 ) ) ) {
V_40 = - V_225 ;
goto V_169;
}
V_2 -> V_35 = V_2 -> V_36 = V_223 ;
#ifdef F_159
V_40 = V_2 -> type -> V_226 ( V_2 ) ;
if ( V_40 )
F_153 ( V_2 , V_34 , V_2 -> V_7 ,
L_60
L_61 , V_40 ) ;
#endif
V_40 = F_184 ( V_2 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_34 , V_2 -> V_7 ,
L_62 ) ;
goto V_171;
}
V_40 = F_55 ( V_2 ) ;
if ( V_40 )
goto V_227;
return 0 ;
V_227:
F_191 ( V_2 ) ;
V_171:
#ifdef F_159
V_2 -> type -> V_228 ( V_2 ) ;
#endif
V_169:
F_127 ( V_2 ) ;
V_146:
F_183 ( V_2 ) ;
V_142:
return V_40 ;
}
static void F_91 ( struct V_1 * V_2 )
{
F_73 ( V_2 ) ;
F_74 ( V_2 -> V_3 == V_4 ) ;
if ( V_2 -> V_93 || ! F_99 ( V_2 -> V_7 ) ||
V_2 -> V_229 )
return;
F_119 ( V_2 ) ;
F_58 ( V_2 ) ;
if ( V_2 -> type -> V_230 != NULL )
F_195 ( V_2 -> V_231 , & V_2 -> V_149 ,
V_232 ) ;
if ( F_196 ( V_2 ) >= V_233 ) {
F_113 ( & V_2 -> V_129 ) ;
if ( V_2 -> V_140 -> V_234 ( V_2 ) )
F_98 ( V_2 ) ;
F_114 ( & V_2 -> V_129 ) ;
}
V_2 -> type -> V_235 ( V_2 ) ;
V_2 -> type -> V_236 ( V_2 ) ;
F_197 ( & V_2 -> V_237 ) ;
V_2 -> type -> V_238 ( V_2 , NULL , NULL ) ;
F_198 ( & V_2 -> V_237 ) ;
}
static void F_85 ( struct V_1 * V_2 )
{
F_73 ( V_2 ) ;
if ( ! V_2 -> V_93 )
return;
V_2 -> type -> V_236 ( V_2 ) ;
F_197 ( & V_2 -> V_237 ) ;
V_2 -> type -> V_238 ( V_2 , NULL , NULL ) ;
F_198 ( & V_2 -> V_237 ) ;
V_2 -> type -> V_239 ( V_2 ) ;
F_120 ( V_2 ) ;
F_68 ( F_99 ( V_2 -> V_7 ) &&
F_70 ( V_2 -> V_7 ) ) ;
F_199 ( V_2 -> V_7 ) ;
F_72 ( V_2 ) ;
}
static void F_200 ( struct V_1 * V_2 )
{
F_57 ( V_2 ) ;
F_191 ( V_2 ) ;
#ifdef F_159
V_2 -> type -> V_228 ( V_2 ) ;
#endif
F_127 ( V_2 ) ;
F_183 ( V_2 ) ;
}
static unsigned int F_201 ( unsigned int V_240 , unsigned int V_241 )
{
if ( V_240 == 0 )
return 0 ;
if ( V_240 * 1000 < V_241 )
return 1 ;
return V_240 * 1000 / V_241 ;
}
int F_182 ( struct V_1 * V_2 , unsigned int V_242 ,
unsigned int V_243 , bool V_244 ,
bool V_245 )
{
struct V_9 * V_10 ;
unsigned int V_246 = F_202 ( V_2 -> type -> V_247 *
V_2 -> V_248 ,
1000 ) ;
unsigned int V_249 ;
unsigned int V_250 ;
F_73 ( V_2 ) ;
if ( V_242 > V_246 || V_243 > V_246 )
return - V_225 ;
V_249 = F_201 ( V_242 , V_2 -> V_248 ) ;
V_250 = F_201 ( V_243 , V_2 -> V_248 ) ;
if ( V_249 != V_250 && V_2 -> V_63 == 0 &&
! V_245 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_63
L_64 ) ;
return - V_225 ;
}
V_2 -> V_25 = V_244 ;
V_2 -> V_32 = V_250 ;
F_54 (channel, efx) {
if ( F_7 ( V_10 ) )
V_10 -> V_29 = V_250 ;
else if ( F_203 ( V_10 ) )
V_10 -> V_29 = V_249 ;
}
return 0 ;
}
void F_204 ( struct V_1 * V_2 , unsigned int * V_242 ,
unsigned int * V_243 , bool * V_244 )
{
* V_244 = V_2 -> V_25 ;
* V_243 = F_202 ( V_2 -> V_32 *
V_2 -> V_248 ,
1000 ) ;
if ( V_2 -> V_63 == 0 )
* V_242 = * V_243 ;
else
* V_242 = F_202 (
V_2 -> V_10 [ V_2 -> V_63 ] -> V_29 *
V_2 -> V_248 ,
1000 ) ;
}
static void F_205 ( struct V_132 * V_133 )
{
struct V_1 * V_2 = F_13 ( V_133 , struct V_1 ,
V_149 . V_251 ) ;
F_15 ( V_2 , V_252 , V_2 -> V_7 ,
L_65 ,
F_16 () ) ;
F_74 ( V_2 -> type -> V_230 == NULL ) ;
if ( F_206 ( & V_2 -> V_129 ) ) {
if ( V_2 -> V_93 )
V_2 -> type -> V_230 ( V_2 ) ;
F_114 ( & V_2 -> V_129 ) ;
}
F_195 ( V_2 -> V_231 , & V_2 -> V_149 ,
V_232 ) ;
}
static int F_207 ( struct V_253 * V_7 , struct V_254 * V_255 , int V_256 )
{
struct V_1 * V_2 = F_208 ( V_7 ) ;
struct V_257 * V_133 = F_209 ( V_255 ) ;
if ( V_256 == V_258 )
return F_210 ( V_2 , V_255 ) ;
if ( V_256 == V_259 )
return F_211 ( V_2 , V_255 ) ;
if ( ( V_256 == V_260 || V_256 == V_261 ) &&
( V_133 -> V_262 & 0xfc00 ) == 0x0400 )
V_133 -> V_262 ^= V_263 | 0x0400 ;
return F_212 ( & V_2 -> V_264 , V_133 , V_256 ) ;
}
static void F_87 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
V_10 -> V_53 = V_2 -> V_7 ;
F_213 ( V_10 -> V_53 , & V_10 -> V_23 ,
F_12 , V_265 ) ;
F_214 ( V_10 ) ;
}
static void F_215 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_54 (channel, efx)
F_87 ( V_10 ) ;
}
static void F_88 ( struct V_9 * V_10 )
{
if ( V_10 -> V_53 ) {
F_216 ( & V_10 -> V_23 ) ;
F_217 ( & V_10 -> V_23 ) ;
}
V_10 -> V_53 = NULL ;
}
static void F_218 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_54 (channel, efx)
F_88 ( V_10 ) ;
}
static void F_219 ( struct V_253 * V_7 )
{
struct V_1 * V_2 = F_208 ( V_7 ) ;
struct V_9 * V_10 ;
F_54 (channel, efx)
F_220 ( V_10 ) ;
}
static int F_221 ( struct V_21 * V_22 )
{
struct V_9 * V_10 =
F_13 ( V_22 , struct V_9 , V_23 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_11 = 4 ;
int V_266 , V_267 ;
if ( ! F_99 ( V_2 -> V_7 ) )
return V_268 ;
if ( ! F_222 ( V_10 ) )
return V_269 ;
V_266 = V_10 -> V_19 . V_267 ;
F_3 ( V_10 , V_11 ) ;
V_267 = V_10 -> V_19 . V_267 - V_266 ;
F_223 ( V_10 ) ;
return V_267 ;
}
int F_224 ( struct V_253 * V_7 )
{
struct V_1 * V_2 = F_208 ( V_7 ) ;
int V_40 ;
F_22 ( V_2 , V_43 , V_2 -> V_7 , L_66 ,
F_16 () ) ;
V_40 = F_1 ( V_2 ) ;
if ( V_40 )
return V_40 ;
if ( V_2 -> V_128 & V_136 )
return - V_270 ;
if ( F_225 ( V_2 ) && F_226 ( V_2 , V_96 ) )
return - V_8 ;
F_98 ( V_2 ) ;
F_91 ( V_2 ) ;
F_227 ( V_2 ) ;
return 0 ;
}
int F_228 ( struct V_253 * V_7 )
{
struct V_1 * V_2 = F_208 ( V_7 ) ;
F_22 ( V_2 , V_148 , V_2 -> V_7 , L_67 ,
F_16 () ) ;
F_85 ( V_2 ) ;
return 0 ;
}
static struct V_271 * F_229 ( struct V_253 * V_7 ,
struct V_271 * V_272 )
{
struct V_1 * V_2 = F_208 ( V_7 ) ;
F_197 ( & V_2 -> V_237 ) ;
V_2 -> type -> V_238 ( V_2 , NULL , V_272 ) ;
F_198 ( & V_2 -> V_237 ) ;
return V_272 ;
}
static void F_230 ( struct V_253 * V_7 )
{
struct V_1 * V_2 = F_208 ( V_7 ) ;
F_2 ( V_2 , V_273 , V_2 -> V_7 ,
L_68 ,
V_2 -> V_93 ) ;
F_77 ( V_2 , V_274 ) ;
}
static int F_231 ( struct V_253 * V_7 , int V_275 )
{
struct V_1 * V_2 = F_208 ( V_7 ) ;
int V_40 ;
V_40 = F_1 ( V_2 ) ;
if ( V_40 )
return V_40 ;
if ( V_275 > V_276 )
return - V_225 ;
F_22 ( V_2 , V_6 , V_2 -> V_7 , L_69 , V_275 ) ;
F_84 ( V_2 ) ;
F_85 ( V_2 ) ;
F_113 ( & V_2 -> V_129 ) ;
V_7 -> V_73 = V_275 ;
F_106 ( V_2 ) ;
F_114 ( & V_2 -> V_129 ) ;
F_91 ( V_2 ) ;
F_92 ( V_2 -> V_7 ) ;
return 0 ;
}
static int F_232 ( struct V_253 * V_7 , void * V_133 )
{
struct V_1 * V_2 = F_208 ( V_7 ) ;
struct V_277 * V_278 = V_133 ;
T_3 * V_279 = V_278 -> V_280 ;
T_3 V_281 [ 6 ] ;
int V_40 ;
if ( ! F_233 ( V_279 ) ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_70 ,
V_279 ) ;
return - V_282 ;
}
F_117 ( V_281 , V_7 -> V_138 ) ;
F_117 ( V_7 -> V_138 , V_279 ) ;
if ( V_2 -> type -> V_283 ) {
V_40 = V_2 -> type -> V_283 ( V_2 ) ;
if ( V_40 ) {
F_117 ( V_7 -> V_138 , V_281 ) ;
return V_40 ;
}
}
F_113 ( & V_2 -> V_129 ) ;
F_106 ( V_2 ) ;
F_114 ( & V_2 -> V_129 ) ;
return 0 ;
}
static void F_234 ( struct V_253 * V_7 )
{
struct V_1 * V_2 = F_208 ( V_7 ) ;
if ( V_2 -> V_93 )
F_235 ( V_2 -> V_231 , & V_2 -> V_134 ) ;
}
static int F_236 ( struct V_253 * V_7 , T_6 V_133 )
{
struct V_1 * V_2 = F_208 ( V_7 ) ;
if ( V_7 -> V_284 & ~ V_133 & V_214 )
return V_2 -> type -> V_285 ( V_2 , V_286 ) ;
return 0 ;
}
static void F_237 ( struct V_1 * V_2 )
{
strcpy ( V_2 -> V_64 , V_2 -> V_7 -> V_64 ) ;
F_238 ( V_2 ) ;
F_53 ( V_2 ) ;
}
static int F_239 ( struct V_287 * V_288 ,
unsigned long V_289 , void * V_290 )
{
struct V_253 * V_7 = F_240 ( V_290 ) ;
if ( ( V_7 -> V_291 == & V_292 ) &&
V_289 == V_293 )
F_237 ( F_208 ( V_7 ) ) ;
return V_294 ;
}
static T_7
F_241 ( struct V_295 * V_167 , struct V_296 * V_297 , char * V_60 )
{
struct V_1 * V_2 = F_242 ( F_243 ( V_167 ) ) ;
return sprintf ( V_60 , L_71 , V_2 -> V_298 ) ;
}
static T_7 F_244 ( struct V_295 * V_167 , struct V_296 * V_297 ,
char * V_60 )
{
struct V_1 * V_2 = F_242 ( F_243 ( V_167 ) ) ;
struct V_299 * V_300 = F_245 ( V_2 ) ;
return F_246 ( V_60 , V_77 , L_71 , V_300 -> V_301 ) ;
}
static T_7 F_247 ( struct V_295 * V_167 , struct V_296 * V_297 ,
const char * V_60 , T_1 V_175 )
{
struct V_1 * V_2 = F_242 ( F_243 ( V_167 ) ) ;
struct V_299 * V_300 = F_245 ( V_2 ) ;
bool V_302 = V_175 > 0 && * V_60 != '0' ;
V_300 -> V_301 = V_302 ;
return V_175 ;
}
static int F_248 ( struct V_1 * V_2 )
{
struct V_253 * V_7 = V_2 -> V_7 ;
struct V_9 * V_10 ;
int V_40 ;
V_7 -> V_303 = 5 * V_304 ;
V_7 -> V_193 = V_2 -> V_159 -> V_193 ;
V_7 -> V_291 = & V_292 ;
if ( F_196 ( V_2 ) >= V_305 )
V_7 -> V_306 |= V_307 ;
V_7 -> V_308 = & V_309 ;
V_7 -> V_310 = V_311 ;
F_249 () ;
V_2 -> V_3 = V_312 ;
F_250 () ;
if ( V_2 -> V_229 ) {
F_2 ( V_2 , V_34 , V_2 -> V_7 ,
L_72 ) ;
V_40 = - V_8 ;
goto V_313;
}
V_40 = F_251 ( V_7 , V_7 -> V_64 ) ;
if ( V_40 < 0 )
goto V_313;
F_237 ( V_2 ) ;
F_102 ( V_7 ) ;
V_40 = F_252 ( V_7 ) ;
if ( V_40 )
goto V_313;
F_54 (channel, efx) {
struct V_12 * V_13 ;
F_5 (tx_queue, channel)
F_253 ( V_13 ) ;
}
F_129 ( V_2 ) ;
F_254 () ;
V_40 = F_255 ( & V_2 -> V_159 -> V_167 , & V_314 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_73 ) ;
goto V_315;
}
#ifdef F_256
V_40 = F_255 ( & V_2 -> V_159 -> V_167 , & V_316 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_73 ) ;
goto V_317;
}
#endif
return 0 ;
#ifdef F_256
V_317:
F_257 ( & V_2 -> V_159 -> V_167 , & V_314 ) ;
#endif
V_315:
F_249 () ;
F_135 ( V_2 ) ;
F_258 ( V_7 ) ;
V_313:
V_2 -> V_3 = V_318 ;
F_254 () ;
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_74 ) ;
return V_40 ;
}
static void F_259 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_7 )
return;
F_74 ( F_208 ( V_2 -> V_7 ) != V_2 ) ;
if ( F_260 ( V_2 ) ) {
F_261 ( V_2 -> V_64 , F_133 ( V_2 -> V_159 ) , sizeof( V_2 -> V_64 ) ) ;
#ifdef F_256
F_257 ( & V_2 -> V_159 -> V_167 , & V_316 ) ;
#endif
F_257 ( & V_2 -> V_159 -> V_167 , & V_314 ) ;
F_262 ( V_2 -> V_7 ) ;
}
}
void F_263 ( struct V_1 * V_2 , enum V_319 V_320 )
{
F_73 ( V_2 ) ;
if ( V_320 == V_321 )
V_2 -> type -> V_322 ( V_2 ) ;
F_85 ( V_2 ) ;
F_173 ( V_2 ) ;
F_113 ( & V_2 -> V_129 ) ;
if ( V_2 -> V_143 && V_320 != V_323 &&
V_320 != V_324 )
V_2 -> V_140 -> V_147 ( V_2 ) ;
V_2 -> type -> V_147 ( V_2 ) ;
}
int F_264 ( struct V_1 * V_2 , enum V_319 V_320 , bool V_325 )
{
int V_40 ;
F_73 ( V_2 ) ;
if ( V_320 == V_321 )
V_2 -> type -> V_326 ( V_2 ) ;
V_40 = V_2 -> type -> V_141 ( V_2 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_75 ) ;
goto V_59;
}
if ( ! V_325 )
goto V_59;
if ( V_2 -> V_143 && V_320 != V_323 &&
V_320 != V_324 ) {
V_40 = V_2 -> V_140 -> V_141 ( V_2 ) ;
if ( V_40 )
goto V_59;
V_40 = V_2 -> V_140 -> V_144 ( V_2 ) ;
if ( V_40 && V_40 != - V_145 )
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_76 ) ;
}
V_40 = F_171 ( V_2 ) ;
if ( V_40 )
goto V_59;
#ifdef F_159
V_40 = V_2 -> type -> V_327 ( V_2 ) ;
if ( V_40 )
F_153 ( V_2 , V_34 , V_2 -> V_7 ,
L_77
L_61 , V_40 ) ;
#endif
F_107 ( & V_2 -> V_125 ) ;
F_192 ( V_2 ) ;
F_108 ( & V_2 -> V_125 ) ;
if ( V_2 -> type -> V_328 )
V_2 -> type -> V_328 ( V_2 ) ;
F_114 ( & V_2 -> V_129 ) ;
F_91 ( V_2 ) ;
return 0 ;
V_59:
V_2 -> V_143 = false ;
F_114 ( & V_2 -> V_129 ) ;
return V_40 ;
}
int F_226 ( struct V_1 * V_2 , enum V_319 V_320 )
{
int V_40 , V_102 ;
bool V_329 ;
F_103 ( V_2 , V_6 , V_2 -> V_7 , L_78 ,
F_265 ( V_320 ) ) ;
F_84 ( V_2 ) ;
F_263 ( V_2 , V_320 ) ;
V_40 = V_2 -> type -> V_330 ( V_2 , V_320 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_79 ) ;
goto V_107;
}
if ( V_320 < V_331 )
V_2 -> V_229 &= - ( 1 << ( V_320 + 1 ) ) ;
else
F_266 ( V_320 , & V_2 -> V_229 ) ;
F_138 ( V_2 -> V_159 ) ;
V_107:
V_329 = V_40 ||
V_320 == V_109 ||
V_320 == V_332 ;
V_102 = F_264 ( V_2 , V_320 , ! V_329 ) ;
if ( V_102 ) {
V_329 = true ;
if ( ! V_40 )
V_40 = V_102 ;
}
if ( V_329 ) {
F_267 ( V_2 -> V_7 ) ;
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_80 ) ;
V_2 -> V_3 = V_4 ;
} else {
F_22 ( V_2 , V_6 , V_2 -> V_7 , L_81 ) ;
F_92 ( V_2 -> V_7 ) ;
}
return V_40 ;
}
int F_268 ( struct V_1 * V_2 )
{
#ifdef F_269
struct V_333 * V_334 = F_270 ( V_2 -> V_159 ) ;
if ( F_271 ( V_334 ) ) {
return 1 ;
}
#endif
return 0 ;
}
static void F_272 ( struct V_1 * V_2 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_335 ; ++ V_44 ) {
if ( F_225 ( V_2 ) )
goto V_107;
F_273 ( V_336 ) ;
}
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_82 ) ;
V_107:
V_2 -> V_337 = false ;
}
static void F_274 ( struct V_132 * V_133 )
{
struct V_1 * V_2 = F_13 ( V_133 , struct V_1 , V_338 ) ;
unsigned long V_339 ;
enum V_319 V_320 ;
V_339 = F_275 ( V_2 -> V_229 ) ;
V_320 = F_276 ( V_339 ) - 1 ;
if ( V_320 == V_340 )
F_272 ( V_2 ) ;
if ( ( V_320 == V_332 ||
V_320 == V_341 ) &&
F_268 ( V_2 ) )
return;
if ( ! V_339 )
return;
F_249 () ;
if ( V_2 -> V_3 == V_312 )
( void ) F_226 ( V_2 , V_320 ) ;
F_254 () ;
}
void F_77 ( struct V_1 * V_2 , enum V_319 type )
{
enum V_319 V_320 ;
if ( V_2 -> V_3 == V_5 ) {
F_22 ( V_2 , V_6 , V_2 -> V_7 ,
L_83 ,
F_265 ( type ) ) ;
return;
}
switch ( type ) {
case V_323 :
case V_96 :
case V_341 :
case V_342 :
case V_109 :
case V_332 :
case V_324 :
case V_340 :
case V_321 :
V_320 = type ;
F_22 ( V_2 , V_6 , V_2 -> V_7 , L_84 ,
F_265 ( V_320 ) ) ;
break;
default:
V_320 = V_2 -> type -> V_343 ( type ) ;
F_22 ( V_2 , V_6 , V_2 -> V_7 ,
L_85 ,
F_265 ( V_320 ) , F_265 ( type ) ) ;
break;
}
F_277 ( V_320 , & V_2 -> V_229 ) ;
F_250 () ;
if ( F_275 ( V_2 -> V_3 ) != V_312 )
return;
F_168 ( V_2 ) ;
F_235 ( V_344 , & V_2 -> V_338 ) ;
}
int F_278 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_279 ( struct V_1 * V_2 ) {}
static bool F_280 ( struct V_1 * V_2 )
{
return false ;
}
static int F_281 ( struct V_1 * V_2 ,
struct V_159 * V_159 , struct V_253 * V_7 )
{
int V_44 ;
F_282 ( & V_2 -> V_157 ) ;
F_282 ( & V_2 -> V_160 ) ;
F_185 ( & V_2 -> V_345 ) ;
#ifdef F_283
F_282 ( & V_2 -> V_346 ) ;
#endif
F_284 ( & V_2 -> V_338 , F_274 ) ;
F_285 ( & V_2 -> V_149 , F_205 ) ;
F_285 ( & V_2 -> V_347 , V_348 ) ;
V_2 -> V_159 = V_159 ;
V_2 -> V_349 = V_350 ;
V_2 -> V_3 = V_318 ;
F_261 ( V_2 -> V_64 , F_133 ( V_159 ) , sizeof( V_2 -> V_64 ) ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_72 = V_2 -> type -> V_72 ;
V_2 -> V_76 =
V_83 ? ( V_2 -> V_72 + V_83 ) % 4 : 0 ;
V_2 -> V_351 =
V_2 -> type -> V_352 - V_2 -> type -> V_72 ;
V_2 -> V_353 =
V_2 -> type -> V_354 - V_2 -> type -> V_72 ;
F_185 ( & V_2 -> V_237 ) ;
F_286 ( & V_2 -> V_129 ) ;
V_2 -> V_140 = & V_355 ;
V_2 -> V_264 . V_167 = V_7 ;
F_284 ( & V_2 -> V_134 , F_115 ) ;
F_287 ( & V_2 -> V_356 ) ;
for ( V_44 = 0 ; V_44 < V_99 ; V_44 ++ ) {
V_2 -> V_10 [ V_44 ] = F_42 ( V_2 , V_44 , NULL ) ;
if ( ! V_2 -> V_10 [ V_44 ] )
goto V_59;
V_2 -> V_66 [ V_44 ] . V_2 = V_2 ;
V_2 -> V_66 [ V_44 ] . V_104 = V_44 ;
}
V_2 -> V_182 = F_25 ( V_2 -> type -> V_357 ,
V_182 ) ;
snprintf ( V_2 -> V_358 , sizeof( V_2 -> V_358 ) , L_86 ,
F_133 ( V_159 ) ) ;
V_2 -> V_231 = F_288 ( V_2 -> V_358 ) ;
if ( ! V_2 -> V_231 )
goto V_59;
return 0 ;
V_59:
F_289 ( V_2 ) ;
return - V_106 ;
}
static void F_289 ( struct V_1 * V_2 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_99 ; V_44 ++ )
F_89 ( V_2 -> V_10 [ V_44 ] ) ;
F_89 ( V_2 -> V_153 ) ;
if ( V_2 -> V_231 ) {
F_290 ( V_2 -> V_231 ) ;
V_2 -> V_231 = NULL ;
}
}
void F_291 ( struct V_1 * V_2 , T_8 * V_272 )
{
T_8 V_359 = 0 ;
struct V_9 * V_10 ;
F_54 (channel, efx)
V_359 += V_10 -> V_359 ;
V_272 [ V_360 ] = V_359 ;
V_272 [ V_361 ] = F_292 ( & V_2 -> V_362 ) ;
}
static void F_293 ( struct V_1 * V_2 )
{
F_74 ( V_2 -> V_3 == V_312 ) ;
F_125 ( & V_2 -> V_338 ) ;
F_173 ( V_2 ) ;
F_294 ( V_2 ) ;
F_126 ( V_2 ) ;
V_2 -> type -> V_147 ( V_2 ) ;
F_218 ( V_2 ) ;
F_200 ( V_2 ) ;
}
static void F_295 ( struct V_159 * V_159 )
{
struct V_1 * V_2 ;
V_2 = F_242 ( V_159 ) ;
if ( ! V_2 )
return;
F_249 () ;
F_135 ( V_2 ) ;
F_267 ( V_2 -> V_7 ) ;
F_173 ( V_2 ) ;
V_2 -> V_3 = V_318 ;
F_254 () ;
if ( V_2 -> type -> V_363 )
V_2 -> type -> V_363 ( V_2 ) ;
F_259 ( V_2 ) ;
F_296 ( V_2 ) ;
F_293 ( V_2 ) ;
F_145 ( V_2 ) ;
F_22 ( V_2 , V_6 , V_2 -> V_7 , L_87 ) ;
F_289 ( V_2 ) ;
F_297 ( V_2 -> V_7 ) ;
F_298 ( V_159 ) ;
}
static void F_299 ( struct V_1 * V_2 )
{
struct V_159 * V_167 = V_2 -> V_159 ;
char V_364 [ V_365 ] ;
T_7 V_366 ;
int V_367 , V_368 , V_44 , V_46 ;
V_366 = F_300 ( V_167 , 0 , sizeof( V_364 ) , V_364 ) ;
if ( V_366 <= 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_88 ) ;
return;
}
V_367 = F_301 ( V_364 , 0 , V_366 , V_369 ) ;
if ( V_367 < 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_89 ) ;
return;
}
V_368 = F_302 ( & V_364 [ V_367 ] ) ;
V_46 = V_368 ;
V_44 = V_367 + V_370 ;
if ( V_44 + V_46 > V_366 )
V_46 = V_366 - V_44 ;
V_44 = F_303 ( V_364 , V_44 , V_46 , L_90 ) ;
if ( V_44 < 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_91 ) ;
return;
}
V_46 = F_304 ( & V_364 [ V_44 ] ) ;
V_44 += V_371 ;
if ( V_44 + V_46 > V_366 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_92 ) ;
return;
}
F_103 ( V_2 , V_6 , V_2 -> V_7 ,
L_93 , V_46 , & V_364 [ V_44 ] ) ;
V_44 = V_367 + V_370 ;
V_46 = V_368 ;
V_44 = F_303 ( V_364 , V_44 , V_46 , L_94 ) ;
if ( V_44 < 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_95 ) ;
return;
}
V_46 = F_304 ( & V_364 [ V_44 ] ) ;
V_44 += V_371 ;
if ( V_44 + V_46 > V_366 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_96 ) ;
return;
}
V_2 -> V_153 = F_46 ( V_46 + 1 , V_47 ) ;
if ( ! V_2 -> V_153 )
return;
snprintf ( V_2 -> V_153 , V_46 + 1 , L_97 , & V_364 [ V_44 ] ) ;
}
static int F_305 ( struct V_1 * V_2 )
{
int V_40 ;
V_40 = F_193 ( V_2 ) ;
if ( V_40 )
goto V_142;
F_215 ( V_2 ) ;
V_40 = V_2 -> type -> V_141 ( V_2 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_34 , V_2 -> V_7 ,
L_75 ) ;
goto V_169;
}
V_40 = F_118 ( V_2 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_34 , V_2 -> V_7 ,
L_98 ) ;
goto V_171;
}
V_40 = F_306 ( V_2 ) ;
if ( V_40 )
goto V_227;
V_40 = F_171 ( V_2 ) ;
if ( V_40 )
goto V_372;
return 0 ;
V_372:
F_294 ( V_2 ) ;
V_227:
F_126 ( V_2 ) ;
V_171:
V_2 -> type -> V_147 ( V_2 ) ;
V_169:
F_218 ( V_2 ) ;
F_200 ( V_2 ) ;
V_142:
return V_40 ;
}
static int F_307 ( struct V_159 * V_159 ,
const struct V_373 * V_188 )
{
struct V_253 * V_7 ;
struct V_1 * V_2 ;
int V_40 ;
V_7 = F_308 ( sizeof( * V_2 ) , V_374 ,
V_375 ) ;
if ( ! V_7 )
return - V_106 ;
V_2 = F_208 ( V_7 ) ;
V_2 -> type = ( const struct V_376 * ) V_188 -> V_377 ;
V_7 -> V_284 |= ( V_2 -> type -> V_213 | V_378 |
V_379 | V_380 |
V_381 ) ;
if ( V_2 -> type -> V_213 & ( V_382 | V_383 ) )
V_7 -> V_284 |= V_384 ;
V_7 -> V_385 |= ( V_383 | V_378 |
V_379 | V_386 |
V_381 ) ;
V_7 -> V_387 = V_7 -> V_284 & ~ V_379 ;
F_309 ( V_159 , V_2 ) ;
F_310 ( V_7 , & V_159 -> V_167 ) ;
V_40 = F_281 ( V_2 , V_159 , V_7 ) ;
if ( V_40 )
goto V_142;
F_103 ( V_2 , V_34 , V_2 -> V_7 ,
L_99 ) ;
if ( ! V_2 -> type -> V_388 )
F_299 ( V_2 ) ;
V_40 = F_136 ( V_2 ) ;
if ( V_40 )
goto V_146;
V_40 = F_305 ( V_2 ) ;
if ( V_40 )
goto V_169;
V_40 = F_248 ( V_2 ) ;
if ( V_40 )
goto V_171;
if ( V_2 -> type -> V_389 ) {
V_40 = V_2 -> type -> V_389 ( V_2 ) ;
if ( V_40 )
F_2 ( V_2 , V_34 , V_2 -> V_7 ,
L_100 , V_40 ) ;
}
F_22 ( V_2 , V_34 , V_2 -> V_7 , L_101 ) ;
F_249 () ;
V_40 = F_311 ( V_2 ) ;
F_254 () ;
if ( V_40 && V_40 != - V_145 )
F_153 ( V_2 , V_34 , V_2 -> V_7 ,
L_102 , V_40 ) ;
V_40 = F_312 ( V_159 ) ;
if ( V_40 && V_40 != - V_225 )
F_313 ( V_2 , V_34 , V_2 -> V_7 ,
L_103 ,
V_40 ) ;
return 0 ;
V_171:
F_293 ( V_2 ) ;
V_169:
F_145 ( V_2 ) ;
V_146:
F_289 ( V_2 ) ;
V_142:
F_68 ( V_40 > 0 ) ;
F_22 ( V_2 , V_6 , V_2 -> V_7 , L_104 , V_40 ) ;
F_297 ( V_7 ) ;
return V_40 ;
}
static int F_314 ( struct V_159 * V_167 , int V_390 )
{
int V_40 ;
struct V_1 * V_2 = F_242 ( V_167 ) ;
if ( V_2 -> type -> V_391 ) {
V_40 = V_2 -> type -> V_391 ( V_2 , V_390 ) ;
if ( V_40 )
return V_40 ;
else
return V_390 ;
} else
return - V_392 ;
}
static int F_315 ( struct V_295 * V_167 )
{
struct V_1 * V_2 = F_242 ( F_243 ( V_167 ) ) ;
F_249 () ;
if ( V_2 -> V_3 != V_4 ) {
V_2 -> V_3 = V_318 ;
F_84 ( V_2 ) ;
F_85 ( V_2 ) ;
F_173 ( V_2 ) ;
}
F_254 () ;
return 0 ;
}
static int F_316 ( struct V_295 * V_167 )
{
int V_40 ;
struct V_1 * V_2 = F_242 ( F_243 ( V_167 ) ) ;
F_249 () ;
if ( V_2 -> V_3 != V_4 ) {
V_40 = F_171 ( V_2 ) ;
if ( V_40 )
goto V_59;
F_113 ( & V_2 -> V_129 ) ;
V_2 -> V_140 -> V_144 ( V_2 ) ;
F_114 ( & V_2 -> V_129 ) ;
F_91 ( V_2 ) ;
F_92 ( V_2 -> V_7 ) ;
V_2 -> V_3 = V_312 ;
V_2 -> type -> V_393 ( V_2 ) ;
}
F_254 () ;
F_235 ( V_344 , & V_2 -> V_338 ) ;
return 0 ;
V_59:
F_254 () ;
return V_40 ;
}
static int F_317 ( struct V_295 * V_167 )
{
struct V_159 * V_159 = F_243 ( V_167 ) ;
struct V_1 * V_2 = F_242 ( V_159 ) ;
V_2 -> type -> V_147 ( V_2 ) ;
V_2 -> V_229 = 0 ;
F_318 ( V_159 ) ;
return F_319 ( V_159 , V_394 ) ;
}
static int F_320 ( struct V_295 * V_167 )
{
struct V_159 * V_159 = F_243 ( V_167 ) ;
struct V_1 * V_2 = F_242 ( V_159 ) ;
int V_40 ;
V_40 = F_319 ( V_159 , V_395 ) ;
if ( V_40 )
return V_40 ;
F_321 ( V_159 ) ;
V_40 = F_137 ( V_159 ) ;
if ( V_40 )
return V_40 ;
F_138 ( V_2 -> V_159 ) ;
V_40 = V_2 -> type -> V_330 ( V_2 , V_96 ) ;
if ( V_40 )
return V_40 ;
V_40 = V_2 -> type -> V_141 ( V_2 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_316 ( V_167 ) ;
return V_40 ;
}
static int F_322 ( struct V_295 * V_167 )
{
int V_40 ;
F_315 ( V_167 ) ;
V_40 = F_317 ( V_167 ) ;
if ( V_40 )
F_320 ( V_167 ) ;
return V_40 ;
}
static T_9 F_323 ( struct V_159 * V_396 ,
enum V_397 V_3 )
{
T_9 V_398 = V_399 ;
struct V_1 * V_2 = F_242 ( V_396 ) ;
if ( V_3 == V_400 )
return V_401 ;
F_249 () ;
if ( V_2 -> V_3 != V_4 ) {
V_2 -> V_3 = V_5 ;
V_2 -> V_229 = 0 ;
F_84 ( V_2 ) ;
F_85 ( V_2 ) ;
F_173 ( V_2 ) ;
V_398 = V_402 ;
} else {
V_398 = V_399 ;
}
F_254 () ;
F_144 ( V_396 ) ;
return V_398 ;
}
static T_9 F_324 ( struct V_159 * V_396 )
{
struct V_1 * V_2 = F_242 ( V_396 ) ;
T_9 V_398 = V_399 ;
int V_40 ;
if ( F_137 ( V_396 ) ) {
F_2 ( V_2 , V_403 , V_2 -> V_7 ,
L_105 ) ;
V_398 = V_401 ;
}
V_40 = F_325 ( V_396 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_403 , V_2 -> V_7 ,
L_106 , V_40 ) ;
}
return V_398 ;
}
static void F_326 ( struct V_159 * V_396 )
{
struct V_1 * V_2 = F_242 ( V_396 ) ;
int V_40 ;
F_249 () ;
if ( V_2 -> V_3 == V_4 )
goto V_107;
V_40 = F_226 ( V_2 , V_96 ) ;
if ( V_40 ) {
F_2 ( V_2 , V_403 , V_2 -> V_7 ,
L_107 , V_40 ) ;
} else {
V_2 -> V_3 = V_312 ;
F_22 ( V_2 , V_403 , V_2 -> V_7 ,
L_108 ) ;
}
V_107:
F_254 () ;
}
static int T_10 F_327 ( void )
{
int V_40 ;
F_328 ( V_404 L_109 V_405 L_110 ) ;
V_40 = F_329 ( & V_406 ) ;
if ( V_40 )
goto V_407;
#ifdef F_159
V_40 = F_330 () ;
if ( V_40 )
goto V_408;
#endif
V_344 = F_288 ( L_111 ) ;
if ( ! V_344 ) {
V_40 = - V_106 ;
goto V_409;
}
V_40 = F_331 ( & V_410 ) ;
if ( V_40 < 0 )
goto V_411;
return 0 ;
V_411:
F_290 ( V_344 ) ;
V_409:
#ifdef F_159
F_332 () ;
V_408:
#endif
F_333 ( & V_406 ) ;
V_407:
return V_40 ;
}
static void T_11 F_334 ( void )
{
F_328 ( V_404 L_112 ) ;
F_335 ( & V_410 ) ;
F_290 ( V_344 ) ;
#ifdef F_159
F_332 () ;
#endif
F_333 ( & V_406 ) ;
}

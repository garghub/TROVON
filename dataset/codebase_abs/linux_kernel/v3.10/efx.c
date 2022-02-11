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
if ( V_15 -> V_13 )
F_9 ( V_15 ) ;
}
return V_12 ;
}
static inline void F_10 ( struct V_9 * V_10 )
{
V_10 -> V_16 = false ;
F_11 () ;
F_12 ( V_10 ) ;
}
static int F_13 ( struct V_17 * V_18 , int V_11 )
{
struct V_9 * V_10 =
F_14 ( V_18 , struct V_9 , V_19 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_12 ;
F_15 ( V_2 , V_20 , V_2 -> V_7 ,
L_2 ,
V_10 -> V_10 , F_16 () ) ;
V_12 = F_3 ( V_10 , V_11 ) ;
if ( V_12 < V_11 ) {
if ( F_6 ( V_10 ) &&
V_2 -> V_21 &&
F_4 ( ++ V_10 -> V_22 == 1000 ) ) {
if ( F_4 ( V_10 -> V_23 <
V_24 ) ) {
if ( V_10 -> V_25 > 1 ) {
V_10 -> V_25 -= 1 ;
V_2 -> type -> V_26 ( V_10 ) ;
}
} else if ( F_4 ( V_10 -> V_23 >
V_27 ) ) {
if ( V_10 -> V_25 <
V_2 -> V_28 ) {
V_10 -> V_25 += 1 ;
V_2 -> type -> V_26 ( V_10 ) ;
}
}
V_10 -> V_22 = 0 ;
V_10 -> V_23 = 0 ;
}
F_17 ( V_10 ) ;
F_18 ( V_18 ) ;
F_10 ( V_10 ) ;
}
return V_12 ;
}
void F_19 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
F_20 ( V_10 -> V_10 >= V_2 -> V_29 ) ;
F_20 ( ! V_10 -> V_13 ) ;
F_20 ( ! V_2 -> V_30 ) ;
F_21 ( V_2 ) ;
if ( V_2 -> V_31 ) {
F_22 ( V_2 -> V_31 ) ;
V_2 -> V_32 = false ;
}
if ( V_10 -> V_33 )
F_22 ( V_10 -> V_33 ) ;
F_23 ( & V_10 -> V_19 ) ;
F_3 ( V_10 , V_10 -> V_34 + 1 ) ;
F_10 ( V_10 ) ;
F_24 ( & V_10 -> V_19 ) ;
if ( V_2 -> V_31 )
V_2 -> V_32 = true ;
F_25 ( V_2 ) ;
}
static int F_26 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned long V_35 ;
F_27 ( V_2 , V_36 , V_2 -> V_7 ,
L_3 , V_10 -> V_10 ) ;
V_35 = F_28 ( V_2 -> V_37 + V_2 -> V_38 + 128 ) ;
F_29 ( V_35 > V_39 ) ;
V_10 -> V_34 = F_30 ( V_35 , V_40 ) - 1 ;
return F_31 ( V_10 ) ;
}
static void F_32 ( struct V_9 * V_10 )
{
F_27 ( V_10 -> V_2 , V_6 , V_10 -> V_2 -> V_7 ,
L_4 , V_10 -> V_10 ) ;
V_10 -> V_41 = 0 ;
F_33 ( V_10 ) ;
}
static void F_34 ( struct V_9 * V_10 )
{
F_27 ( V_10 -> V_2 , V_42 , V_10 -> V_2 -> V_7 ,
L_5 , V_10 -> V_10 ) ;
V_10 -> V_16 = false ;
V_10 -> V_13 = true ;
F_11 () ;
F_24 ( & V_10 -> V_19 ) ;
F_12 ( V_10 ) ;
}
static void F_35 ( struct V_9 * V_10 )
{
if ( ! V_10 -> V_13 )
return;
F_23 ( & V_10 -> V_19 ) ;
V_10 -> V_13 = false ;
}
static void F_36 ( struct V_9 * V_10 )
{
F_27 ( V_10 -> V_2 , V_6 , V_10 -> V_2 -> V_7 ,
L_6 , V_10 -> V_10 ) ;
F_37 ( V_10 ) ;
}
static void F_38 ( struct V_9 * V_10 )
{
F_27 ( V_10 -> V_2 , V_6 , V_10 -> V_2 -> V_7 ,
L_7 , V_10 -> V_10 ) ;
F_39 ( V_10 ) ;
}
static struct V_9 *
F_40 ( struct V_1 * V_2 , int V_43 , struct V_9 * V_44 )
{
struct V_9 * V_10 ;
struct V_14 * V_15 ;
struct V_45 * V_46 ;
int V_47 ;
V_10 = F_41 ( sizeof( * V_10 ) , V_48 ) ;
if ( ! V_10 )
return NULL ;
V_10 -> V_2 = V_2 ;
V_10 -> V_10 = V_43 ;
V_10 -> type = & V_49 ;
for ( V_47 = 0 ; V_47 < V_50 ; V_47 ++ ) {
V_46 = & V_10 -> V_46 [ V_47 ] ;
V_46 -> V_2 = V_2 ;
V_46 -> V_51 = V_43 * V_50 + V_47 ;
V_46 -> V_10 = V_10 ;
}
V_15 = & V_10 -> V_15 ;
V_15 -> V_2 = V_2 ;
F_42 ( & V_15 -> V_52 , V_53 ,
( unsigned long ) V_15 ) ;
return V_10 ;
}
static struct V_9 *
F_43 ( const struct V_9 * V_44 )
{
struct V_9 * V_10 ;
struct V_14 * V_15 ;
struct V_45 * V_46 ;
int V_47 ;
V_10 = F_44 ( sizeof( * V_10 ) , V_48 ) ;
if ( ! V_10 )
return NULL ;
* V_10 = * V_44 ;
V_10 -> V_54 = NULL ;
memset ( & V_10 -> V_55 , 0 , sizeof( V_10 -> V_55 ) ) ;
for ( V_47 = 0 ; V_47 < V_50 ; V_47 ++ ) {
V_46 = & V_10 -> V_46 [ V_47 ] ;
if ( V_46 -> V_10 )
V_46 -> V_10 = V_10 ;
V_46 -> V_56 = NULL ;
memset ( & V_46 -> V_57 , 0 , sizeof( V_46 -> V_57 ) ) ;
}
V_15 = & V_10 -> V_15 ;
V_15 -> V_56 = NULL ;
memset ( & V_15 -> V_58 , 0 , sizeof( V_15 -> V_58 ) ) ;
F_42 ( & V_15 -> V_52 , V_53 ,
( unsigned long ) V_15 ) ;
return V_10 ;
}
static int F_45 ( struct V_9 * V_10 )
{
struct V_45 * V_46 ;
struct V_14 * V_15 ;
int V_59 ;
F_27 ( V_10 -> V_2 , V_36 , V_10 -> V_2 -> V_7 ,
L_8 , V_10 -> V_10 ) ;
V_59 = V_10 -> type -> V_60 ( V_10 ) ;
if ( V_59 )
goto V_61;
V_59 = F_26 ( V_10 ) ;
if ( V_59 )
goto V_61;
F_46 (tx_queue, channel) {
V_59 = F_47 ( V_46 ) ;
if ( V_59 )
goto V_61;
}
F_48 (rx_queue, channel) {
V_59 = F_49 ( V_15 ) ;
if ( V_59 )
goto V_61;
}
V_10 -> V_62 = 0 ;
return 0 ;
V_61:
F_50 ( V_10 ) ;
return V_59 ;
}
static void
F_51 ( struct V_9 * V_10 , char * V_63 , T_1 V_64 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
const char * type ;
int V_65 ;
V_65 = V_10 -> V_10 ;
if ( V_2 -> V_66 == 0 ) {
type = L_9 ;
} else if ( V_10 -> V_10 < V_2 -> V_66 ) {
type = L_10 ;
} else {
type = L_11 ;
V_65 -= V_2 -> V_66 ;
}
snprintf ( V_63 , V_64 , L_12 , V_2 -> V_67 , type , V_65 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_53 (channel, efx)
V_10 -> type -> V_68 ( V_10 ,
V_2 -> V_69 [ V_10 -> V_10 ] ,
sizeof( V_2 -> V_69 [ 0 ] ) ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
int V_59 ;
V_2 -> V_70 = 0 ;
F_55 (channel, efx) {
V_59 = F_45 ( V_10 ) ;
if ( V_59 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 ,
L_13 ,
V_10 -> V_10 ) ;
goto V_61;
}
}
F_52 ( V_2 ) ;
return 0 ;
V_61:
F_56 ( V_2 ) ;
return V_59 ;
}
static void F_57 ( struct V_1 * V_2 )
{
bool V_71 = V_2 -> V_72 ;
struct V_45 * V_46 ;
struct V_14 * V_15 ;
struct V_9 * V_10 ;
T_1 V_73 ;
V_2 -> V_74 = ( V_2 -> type -> V_75 +
F_58 ( V_2 -> V_7 -> V_76 ) +
V_2 -> type -> V_77 ) ;
V_73 = ( sizeof( struct V_78 ) +
V_79 + V_2 -> V_74 ) ;
if ( V_73 <= V_80 ) {
V_2 -> V_72 = false ;
V_2 -> V_81 = 0 ;
} else if ( V_2 -> type -> V_82 ) {
F_59 ( V_83 % V_84 ) ;
F_59 ( sizeof( struct V_78 ) +
2 * F_60 ( V_79 + V_83 ,
V_85 ) >
V_80 ) ;
V_2 -> V_72 = true ;
V_2 -> V_74 = V_83 ;
V_2 -> V_81 = 0 ;
} else {
V_2 -> V_72 = false ;
V_2 -> V_81 = F_61 ( V_73 ) ;
}
F_62 ( V_2 ) ;
if ( V_2 -> V_81 )
F_27 ( V_2 , V_6 , V_2 -> V_7 ,
L_14 ,
V_2 -> V_74 , V_2 -> V_81 ,
V_2 -> V_86 ) ;
else
F_27 ( V_2 , V_6 , V_2 -> V_7 ,
L_15 ,
V_2 -> V_74 , V_2 -> V_87 ,
V_2 -> V_88 , V_2 -> V_86 ) ;
if ( V_2 -> V_72 != V_71 )
F_63 ( V_2 ) ;
V_2 -> V_89 = V_2 -> V_38 - F_64 ( V_2 ) ;
V_2 -> V_90 = V_2 -> V_89 / 2 ;
F_53 (channel, efx) {
F_46 (tx_queue, channel)
F_65 ( V_46 ) ;
F_48 (rx_queue, channel) {
F_66 ( V_15 ) ;
F_67 ( V_15 ) ;
}
F_68 ( V_10 -> V_91 ) ;
}
if ( F_69 ( V_2 -> V_7 ) )
F_70 ( V_2 -> V_7 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_45 * V_46 ;
struct V_14 * V_15 ;
struct V_92 * V_93 = V_2 -> V_92 ;
int V_59 ;
F_72 ( V_2 ) ;
F_20 ( V_2 -> V_94 ) ;
if ( V_93 -> V_95 && V_2 -> V_3 != V_5 ) {
V_59 = F_73 ( V_2 ) ;
if ( V_59 && F_74 ( V_2 ) ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_16 ) ;
F_75 ( V_2 , V_96 ) ;
} else if ( V_59 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_17 ) ;
} else {
F_27 ( V_2 , V_6 , V_2 -> V_7 ,
L_18 ) ;
}
}
F_53 (channel, efx) {
if ( F_6 ( V_10 ) ) {
F_35 ( V_10 ) ;
F_34 ( V_10 ) ;
}
F_48 (rx_queue, channel)
F_76 ( V_15 ) ;
F_77 (tx_queue, channel)
F_78 ( V_46 ) ;
}
}
static void F_50 ( struct V_9 * V_10 )
{
struct V_45 * V_46 ;
struct V_14 * V_15 ;
F_27 ( V_10 -> V_2 , V_6 , V_10 -> V_2 -> V_7 ,
L_19 , V_10 -> V_10 ) ;
F_48 (rx_queue, channel)
F_79 ( V_15 ) ;
F_77 (tx_queue, channel)
F_80 ( V_46 ) ;
F_38 ( V_10 ) ;
V_10 -> type -> V_97 ( V_10 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_53 (channel, efx)
F_50 ( V_10 ) ;
}
int
F_81 ( struct V_1 * V_2 , T_2 V_37 , T_2 V_38 )
{
struct V_9 * V_98 [ V_99 ] , * V_10 ;
T_2 V_100 , V_101 ;
unsigned V_43 , V_70 = 0 ;
int V_59 ;
V_59 = F_1 ( V_2 ) ;
if ( V_59 )
return V_59 ;
F_53 (channel, efx) {
struct V_14 * V_15 ;
struct V_45 * V_46 ;
if ( V_10 -> type -> V_102 )
continue;
V_70 = F_30 ( V_70 ,
V_10 -> V_55 . V_103 +
V_10 -> V_55 . V_35 ) ;
F_48 (rx_queue, channel)
V_70 = F_30 ( V_70 ,
V_15 -> V_58 . V_103 +
V_15 -> V_58 . V_35 ) ;
F_46 (tx_queue, channel)
V_70 = F_30 ( V_70 ,
V_46 -> V_57 . V_103 +
V_46 -> V_57 . V_35 ) ;
}
F_82 ( V_2 ) ;
F_83 ( V_2 ) ;
F_84 ( V_2 , true ) ;
memset ( V_98 , 0 , sizeof( V_98 ) ) ;
for ( V_43 = 0 ; V_43 < V_2 -> V_29 ; V_43 ++ ) {
V_10 = V_2 -> V_10 [ V_43 ] ;
if ( V_10 -> type -> V_102 )
V_10 = V_10 -> type -> V_102 ( V_10 ) ;
if ( ! V_10 ) {
V_59 = - V_104 ;
goto V_105;
}
V_98 [ V_43 ] = V_10 ;
}
V_100 = V_2 -> V_37 ;
V_101 = V_2 -> V_38 ;
V_2 -> V_37 = V_37 ;
V_2 -> V_38 = V_38 ;
for ( V_43 = 0 ; V_43 < V_2 -> V_29 ; V_43 ++ ) {
V_10 = V_2 -> V_10 [ V_43 ] ;
V_2 -> V_10 [ V_43 ] = V_98 [ V_43 ] ;
V_98 [ V_43 ] = V_10 ;
}
V_2 -> V_70 = V_70 ;
for ( V_43 = 0 ; V_43 < V_2 -> V_29 ; V_43 ++ ) {
V_10 = V_2 -> V_10 [ V_43 ] ;
if ( ! V_10 -> type -> V_102 )
continue;
V_59 = F_45 ( V_10 ) ;
if ( V_59 )
goto V_106;
F_85 ( V_2 -> V_10 [ V_43 ] ) ;
}
V_105:
for ( V_43 = 0 ; V_43 < V_2 -> V_29 ; V_43 ++ ) {
V_10 = V_98 [ V_43 ] ;
if ( V_10 && V_10 -> type -> V_102 ) {
F_86 ( V_10 ) ;
F_50 ( V_10 ) ;
F_87 ( V_10 ) ;
}
}
F_88 ( V_2 , true ) ;
F_89 ( V_2 ) ;
F_90 ( V_2 -> V_7 ) ;
return V_59 ;
V_106:
V_2 -> V_37 = V_100 ;
V_2 -> V_38 = V_101 ;
for ( V_43 = 0 ; V_43 < V_2 -> V_29 ; V_43 ++ ) {
V_10 = V_2 -> V_10 [ V_43 ] ;
V_2 -> V_10 [ V_43 ] = V_98 [ V_43 ] ;
V_98 [ V_43 ] = V_10 ;
}
goto V_105;
}
void F_91 ( struct V_14 * V_15 )
{
F_92 ( & V_15 -> V_52 , V_107 + F_93 ( 100 ) ) ;
}
int F_94 ( struct V_9 * V_10 )
{
return 0 ;
}
void F_95 ( struct V_9 * V_10 )
{
}
void F_96 ( struct V_1 * V_2 )
{
struct V_108 * V_109 = & V_2 -> V_109 ;
if ( ! F_97 ( V_2 -> V_7 ) )
return;
if ( V_109 -> V_110 != F_98 ( V_2 -> V_7 ) ) {
V_2 -> V_111 ++ ;
if ( V_109 -> V_110 )
F_99 ( V_2 -> V_7 ) ;
else
F_100 ( V_2 -> V_7 ) ;
}
if ( V_109 -> V_110 )
F_101 ( V_2 , V_112 , V_2 -> V_7 ,
L_20 ,
V_109 -> V_113 , V_109 -> V_114 ? L_21 : L_22 ,
V_2 -> V_7 -> V_76 ,
( V_2 -> V_115 ? L_23 : L_9 ) ) ;
else
F_101 ( V_2 , V_112 , V_2 -> V_7 , L_24 ) ;
}
void F_102 ( struct V_1 * V_2 , T_2 V_116 )
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
void F_103 ( struct V_1 * V_2 , T_3 V_119 )
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
int F_104 ( struct V_1 * V_2 )
{
enum V_123 V_124 ;
int V_59 ;
F_68 ( ! F_105 ( & V_2 -> V_125 ) ) ;
F_106 ( V_2 -> V_7 ) ;
F_107 ( V_2 -> V_7 ) ;
V_124 = V_2 -> V_124 ;
if ( F_108 ( V_2 ) )
V_2 -> V_124 |= V_126 ;
else
V_2 -> V_124 &= ~ V_126 ;
V_59 = V_2 -> type -> V_127 ( V_2 ) ;
if ( V_59 )
V_2 -> V_124 = V_124 ;
return V_59 ;
}
int F_109 ( struct V_1 * V_2 )
{
int V_59 ;
F_72 ( V_2 ) ;
F_110 ( & V_2 -> V_125 ) ;
V_59 = F_104 ( V_2 ) ;
F_111 ( & V_2 -> V_125 ) ;
return V_59 ;
}
static void F_112 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = F_14 ( V_129 , struct V_1 , V_130 ) ;
F_110 ( & V_2 -> V_125 ) ;
if ( V_2 -> V_94 )
V_2 -> type -> V_131 ( V_2 ) ;
F_111 ( & V_2 -> V_125 ) ;
}
static int F_113 ( struct V_1 * V_2 )
{
int V_59 ;
F_27 ( V_2 , V_36 , V_2 -> V_7 , L_25 ) ;
if ( V_132 )
V_2 -> V_124 = V_133 ;
V_59 = V_2 -> type -> V_134 ( V_2 ) ;
if ( V_59 )
return V_59 ;
memcpy ( V_2 -> V_7 -> V_135 , V_2 -> V_7 -> V_136 , V_137 ) ;
return 0 ;
}
static int F_114 ( struct V_1 * V_2 )
{
int V_59 ;
F_27 ( V_2 , V_6 , V_2 -> V_7 , L_26 ) ;
F_110 ( & V_2 -> V_125 ) ;
V_59 = V_2 -> V_138 -> V_139 ( V_2 ) ;
if ( V_59 )
goto V_140;
V_2 -> V_141 = true ;
V_2 -> type -> V_131 ( V_2 ) ;
V_59 = V_2 -> V_138 -> V_142 ( V_2 ) ;
if ( V_59 )
goto V_143;
F_111 ( & V_2 -> V_125 ) ;
return 0 ;
V_143:
V_2 -> V_138 -> V_144 ( V_2 ) ;
V_140:
F_111 ( & V_2 -> V_125 ) ;
return V_59 ;
}
static void F_115 ( struct V_1 * V_2 )
{
F_27 ( V_2 , V_42 , V_2 -> V_7 , L_27 ) ;
F_20 ( V_2 -> V_94 ) ;
F_110 ( & V_2 -> V_125 ) ;
V_2 -> V_94 = true ;
V_2 -> type -> V_131 ( V_2 ) ;
F_111 ( & V_2 -> V_125 ) ;
}
static void F_116 ( struct V_1 * V_2 )
{
F_27 ( V_2 , V_145 , V_2 -> V_7 , L_28 ) ;
F_110 ( & V_2 -> V_125 ) ;
V_2 -> V_94 = false ;
F_111 ( & V_2 -> V_125 ) ;
F_106 ( V_2 -> V_7 ) ;
F_107 ( V_2 -> V_7 ) ;
}
static void F_117 ( struct V_1 * V_2 )
{
F_27 ( V_2 , V_6 , V_2 -> V_7 , L_29 ) ;
if ( ! V_2 -> V_141 )
return;
V_2 -> V_138 -> V_144 ( V_2 ) ;
V_2 -> V_141 = false ;
V_2 -> V_109 . V_110 = false ;
F_96 ( V_2 ) ;
}
static void F_118 ( struct V_1 * V_2 )
{
F_27 ( V_2 , V_6 , V_2 -> V_7 , L_30 ) ;
V_2 -> type -> V_146 ( V_2 ) ;
}
static int F_119 ( struct V_1 * V_2 )
{
struct V_92 * V_92 = V_2 -> V_92 ;
T_4 V_147 = V_2 -> type -> V_148 ;
int V_59 ;
F_27 ( V_2 , V_36 , V_2 -> V_7 , L_31 ) ;
V_59 = F_120 ( V_92 ) ;
if ( V_59 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 ,
L_32 ) ;
goto V_140;
}
F_121 ( V_92 ) ;
while ( V_147 > 0x7fffffffUL ) {
if ( F_122 ( & V_92 -> V_93 , V_147 ) ) {
V_59 = F_123 ( & V_92 -> V_93 , V_147 ) ;
if ( V_59 == 0 )
break;
}
V_147 >>= 1 ;
}
if ( V_59 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 ,
L_33 ) ;
goto V_143;
}
F_27 ( V_2 , V_36 , V_2 -> V_7 ,
L_34 , ( unsigned long long ) V_147 ) ;
V_59 = F_124 ( & V_92 -> V_93 , V_147 ) ;
if ( V_59 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 ,
L_35 ) ;
goto V_143;
}
V_2 -> V_149 = F_125 ( V_2 -> V_92 , V_150 ) ;
V_59 = F_126 ( V_92 , V_150 , L_36 ) ;
if ( V_59 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 ,
L_37 ) ;
V_59 = - V_8 ;
goto V_151;
}
V_2 -> V_152 = F_127 ( V_2 -> V_149 ,
V_2 -> type -> V_153 ) ;
if ( ! V_2 -> V_152 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 ,
L_38 ,
( unsigned long long ) V_2 -> V_149 ,
V_2 -> type -> V_153 ) ;
V_59 = - V_104 ;
goto V_154;
}
F_27 ( V_2 , V_36 , V_2 -> V_7 ,
L_39 ,
( unsigned long long ) V_2 -> V_149 ,
V_2 -> type -> V_153 , V_2 -> V_152 ) ;
return 0 ;
V_154:
F_128 ( V_2 -> V_92 , V_150 ) ;
V_151:
V_2 -> V_149 = 0 ;
V_143:
F_129 ( V_2 -> V_92 ) ;
V_140:
return V_59 ;
}
static void F_130 ( struct V_1 * V_2 )
{
F_27 ( V_2 , V_6 , V_2 -> V_7 , L_40 ) ;
if ( V_2 -> V_152 ) {
F_131 ( V_2 -> V_152 ) ;
V_2 -> V_152 = NULL ;
}
if ( V_2 -> V_149 ) {
F_128 ( V_2 -> V_92 , V_150 ) ;
V_2 -> V_149 = 0 ;
}
F_129 ( V_2 -> V_92 ) ;
}
static unsigned int F_132 ( struct V_1 * V_2 )
{
T_5 V_155 ;
unsigned int V_156 ;
int V_157 ;
if ( V_158 ) {
V_156 = V_158 ;
} else {
if ( F_4 ( ! F_133 ( & V_155 , V_48 ) ) ) {
F_134 ( V_2 , V_36 , V_2 -> V_7 ,
L_41 ) ;
return 1 ;
}
V_156 = 0 ;
F_135 (cpu) {
if ( ! F_136 ( V_157 , V_155 ) ) {
++ V_156 ;
F_137 ( V_155 , V_155 ,
F_138 ( V_157 ) ) ;
}
}
F_139 ( V_155 ) ;
}
if ( F_140 ( V_2 ) && F_141 ( V_2 ) > 1 &&
V_156 > F_141 ( V_2 ) ) {
F_134 ( V_2 , V_36 , V_2 -> V_7 ,
L_42
L_43
L_44 ,
V_156 , F_141 ( V_2 ) ) ;
V_156 = F_141 ( V_2 ) ;
}
return V_156 ;
}
static int
F_142 ( struct V_1 * V_2 , struct V_159 * V_160 )
{
#ifdef F_143
unsigned int V_43 ;
int V_59 ;
V_2 -> V_7 -> V_161 = F_144 ( V_2 -> V_162 ) ;
if ( ! V_2 -> V_7 -> V_161 )
return - V_104 ;
for ( V_43 = 0 ; V_43 < V_2 -> V_162 ; V_43 ++ ) {
V_59 = F_145 ( V_2 -> V_7 -> V_161 ,
V_160 [ V_43 ] . V_163 ) ;
if ( V_59 ) {
F_146 ( V_2 -> V_7 -> V_161 ) ;
V_2 -> V_7 -> V_161 = NULL ;
return V_59 ;
}
}
#endif
return 0 ;
}
static int F_147 ( struct V_1 * V_2 )
{
unsigned int V_164 =
F_148 ( V_2 -> type -> V_165 , V_99 ) ;
unsigned int V_166 = 0 ;
unsigned int V_43 , V_47 ;
int V_59 ;
for ( V_43 = 0 ; V_43 < V_167 ; V_43 ++ )
if ( V_2 -> V_168 [ V_43 ] )
++ V_166 ;
if ( V_2 -> V_169 == V_170 ) {
struct V_159 V_160 [ V_99 ] ;
unsigned int V_29 ;
V_29 = F_132 ( V_2 ) ;
if ( V_171 )
V_29 *= 2 ;
V_29 += V_166 ;
V_29 = F_148 ( V_29 , V_164 ) ;
for ( V_43 = 0 ; V_43 < V_29 ; V_43 ++ )
V_160 [ V_43 ] . V_172 = V_43 ;
V_59 = F_149 ( V_2 -> V_92 , V_160 , V_29 ) ;
if ( V_59 > 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_45
L_46 , V_59 , V_29 ) ;
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_47 ) ;
F_29 ( V_59 >= V_29 ) ;
V_29 = V_59 ;
V_59 = F_149 ( V_2 -> V_92 , V_160 ,
V_29 ) ;
}
if ( V_59 == 0 ) {
V_2 -> V_29 = V_29 ;
if ( V_29 > V_166 )
V_29 -= V_166 ;
if ( V_171 ) {
V_2 -> V_173 = F_30 ( V_29 / 2 , 1U ) ;
V_2 -> V_162 = F_30 ( V_29 -
V_2 -> V_173 ,
1U ) ;
} else {
V_2 -> V_173 = V_29 ;
V_2 -> V_162 = V_29 ;
}
V_59 = F_142 ( V_2 , V_160 ) ;
if ( V_59 ) {
F_150 ( V_2 -> V_92 ) ;
return V_59 ;
}
for ( V_43 = 0 ; V_43 < V_2 -> V_29 ; V_43 ++ )
F_151 ( V_2 , V_43 ) -> V_33 =
V_160 [ V_43 ] . V_163 ;
} else {
V_2 -> V_169 = V_174 ;
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_48 ) ;
}
}
if ( V_2 -> V_169 == V_174 ) {
V_2 -> V_29 = 1 ;
V_2 -> V_162 = 1 ;
V_2 -> V_173 = 1 ;
V_59 = F_152 ( V_2 -> V_92 ) ;
if ( V_59 == 0 ) {
F_151 ( V_2 , 0 ) -> V_33 = V_2 -> V_92 -> V_33 ;
} else {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_49 ) ;
V_2 -> V_169 = V_175 ;
}
}
if ( V_2 -> V_169 == V_175 ) {
V_2 -> V_29 = 1 + ( V_171 ? 1 : 0 ) ;
V_2 -> V_162 = 1 ;
V_2 -> V_173 = 1 ;
V_2 -> V_31 = V_2 -> V_92 -> V_33 ;
}
V_47 = V_2 -> V_29 ;
for ( V_43 = 0 ; V_43 < V_167 ; V_43 ++ ) {
if ( ! V_2 -> V_168 [ V_43 ] )
continue;
if ( V_2 -> V_169 != V_170 ||
V_2 -> V_29 <= V_166 ) {
V_2 -> V_168 [ V_43 ] -> F_153 ( V_2 ) ;
} else {
-- V_47 ;
F_151 ( V_2 , V_47 ) -> type =
V_2 -> V_168 [ V_43 ] ;
}
}
V_2 -> V_176 = ( ( V_2 -> V_162 > 1 || ! F_140 ( V_2 ) ) ?
V_2 -> V_162 : F_141 ( V_2 ) ) ;
return 0 ;
}
static void F_88 ( struct V_1 * V_2 , bool V_177 )
{
struct V_9 * V_10 ;
F_20 ( V_2 -> V_3 == V_4 ) ;
if ( V_2 -> V_31 )
V_2 -> V_32 = true ;
F_25 ( V_2 ) ;
F_53 (channel, efx) {
if ( ! V_10 -> type -> V_178 || ! V_177 )
F_32 ( V_10 ) ;
F_34 ( V_10 ) ;
}
F_154 ( V_2 ) ;
}
static void F_84 ( struct V_1 * V_2 , bool V_177 )
{
struct V_9 * V_10 ;
if ( V_2 -> V_3 == V_4 )
return;
F_155 ( V_2 ) ;
F_21 ( V_2 ) ;
if ( V_2 -> V_31 ) {
F_22 ( V_2 -> V_31 ) ;
V_2 -> V_32 = false ;
}
F_53 (channel, efx) {
if ( V_10 -> V_33 )
F_22 ( V_10 -> V_33 ) ;
F_35 ( V_10 ) ;
if ( ! V_10 -> type -> V_178 || ! V_177 )
F_36 ( V_10 ) ;
}
}
static void F_156 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_53 (channel, efx)
V_10 -> V_33 = 0 ;
F_157 ( V_2 -> V_92 ) ;
F_150 ( V_2 -> V_92 ) ;
V_2 -> V_31 = 0 ;
}
static void F_158 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_45 * V_46 ;
V_2 -> V_66 =
V_171 ? V_2 -> V_29 - V_2 -> V_173 : 0 ;
F_53 (channel, efx) {
if ( V_10 -> V_10 < V_2 -> V_162 )
V_10 -> V_15 . V_179 = V_10 -> V_10 ;
else
V_10 -> V_15 . V_179 = - 1 ;
F_46 (tx_queue, channel)
V_46 -> V_51 -= ( V_2 -> V_66 *
V_50 ) ;
}
}
static int F_159 ( struct V_1 * V_2 )
{
T_1 V_43 ;
int V_59 ;
F_27 ( V_2 , V_36 , V_2 -> V_7 , L_50 ) ;
V_59 = V_2 -> type -> V_36 ( V_2 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_147 ( V_2 ) ;
if ( V_59 )
goto V_61;
V_2 -> type -> V_180 ( V_2 ) ;
if ( V_2 -> V_29 > 1 )
F_160 ( & V_2 -> V_181 , sizeof( V_2 -> V_181 ) ) ;
for ( V_43 = 0 ; V_43 < F_161 ( V_2 -> V_182 ) ; V_43 ++ )
V_2 -> V_182 [ V_43 ] =
F_162 ( V_43 , V_2 -> V_176 ) ;
F_158 ( V_2 ) ;
F_163 ( V_2 -> V_7 , V_2 -> V_173 ) ;
F_164 ( V_2 -> V_7 , V_2 -> V_162 ) ;
F_165 ( V_2 , V_183 , V_184 , true ,
true ) ;
return 0 ;
V_61:
V_2 -> type -> remove ( V_2 ) ;
return V_59 ;
}
static void F_166 ( struct V_1 * V_2 )
{
F_27 ( V_2 , V_6 , V_2 -> V_7 , L_51 ) ;
F_156 ( V_2 ) ;
V_2 -> type -> remove ( V_2 ) ;
}
static int F_167 ( struct V_1 * V_2 )
{
int V_59 ;
V_59 = F_159 ( V_2 ) ;
if ( V_59 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 , L_52 ) ;
goto V_140;
}
V_59 = F_113 ( V_2 ) ;
if ( V_59 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 , L_53 ) ;
goto V_143;
}
F_59 ( V_185 < V_186 ) ;
if ( F_68 ( V_185 < F_168 ( V_2 ) ) ) {
V_59 = - V_187 ;
goto V_151;
}
V_2 -> V_37 = V_2 -> V_38 = V_185 ;
V_59 = F_169 ( V_2 ) ;
if ( V_59 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 ,
L_54 ) ;
goto V_151;
}
V_59 = F_54 ( V_2 ) ;
if ( V_59 )
goto V_154;
return 0 ;
V_154:
F_170 ( V_2 ) ;
V_151:
F_118 ( V_2 ) ;
V_143:
F_166 ( V_2 ) ;
V_140:
return V_59 ;
}
static void F_89 ( struct V_1 * V_2 )
{
F_72 ( V_2 ) ;
F_20 ( V_2 -> V_3 == V_4 ) ;
if ( V_2 -> V_94 || ! F_97 ( V_2 -> V_7 ) )
return;
F_115 ( V_2 ) ;
F_57 ( V_2 ) ;
if ( V_2 -> type -> V_188 != NULL )
F_171 ( V_2 -> V_189 , & V_2 -> V_190 ,
V_191 ) ;
if ( F_172 ( V_2 ) >= V_192 ) {
F_110 ( & V_2 -> V_125 ) ;
if ( V_2 -> V_138 -> V_193 ( V_2 ) )
F_96 ( V_2 ) ;
F_111 ( & V_2 -> V_125 ) ;
}
V_2 -> type -> V_194 ( V_2 ) ;
}
static void F_173 ( struct V_1 * V_2 )
{
F_174 ( & V_2 -> V_190 ) ;
F_175 ( V_2 ) ;
F_176 ( & V_2 -> V_130 ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
F_72 ( V_2 ) ;
if ( ! V_2 -> V_94 )
return;
V_2 -> type -> V_195 ( V_2 ) ;
F_116 ( V_2 ) ;
F_173 ( V_2 ) ;
F_68 ( F_97 ( V_2 -> V_7 ) &&
F_69 ( V_2 -> V_7 ) ) ;
F_177 ( V_2 -> V_7 ) ;
F_71 ( V_2 ) ;
}
static void F_178 ( struct V_1 * V_2 )
{
F_56 ( V_2 ) ;
F_170 ( V_2 ) ;
F_118 ( V_2 ) ;
F_166 ( V_2 ) ;
}
static unsigned int F_179 ( unsigned int V_196 , unsigned int V_197 )
{
if ( V_196 == 0 )
return 0 ;
if ( V_196 * 1000 < V_197 )
return 1 ;
return V_196 * 1000 / V_197 ;
}
int F_165 ( struct V_1 * V_2 , unsigned int V_198 ,
unsigned int V_199 , bool V_200 ,
bool V_201 )
{
struct V_9 * V_10 ;
unsigned int V_202 = F_180 ( V_2 -> type -> V_203 *
V_2 -> V_204 ,
1000 ) ;
unsigned int V_205 ;
unsigned int V_206 ;
F_72 ( V_2 ) ;
if ( V_198 > V_202 || V_199 > V_202 )
return - V_187 ;
V_205 = F_179 ( V_198 , V_2 -> V_204 ) ;
V_206 = F_179 ( V_199 , V_2 -> V_204 ) ;
if ( V_205 != V_206 && V_2 -> V_66 == 0 &&
! V_201 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_55
L_56 ) ;
return - V_187 ;
}
V_2 -> V_21 = V_200 ;
V_2 -> V_28 = V_206 ;
F_53 (channel, efx) {
if ( F_6 ( V_10 ) )
V_10 -> V_25 = V_206 ;
else if ( F_181 ( V_10 ) )
V_10 -> V_25 = V_205 ;
}
return 0 ;
}
void F_182 ( struct V_1 * V_2 , unsigned int * V_198 ,
unsigned int * V_199 , bool * V_200 )
{
* V_200 = V_2 -> V_21 ;
* V_199 = F_180 ( V_2 -> V_28 *
V_2 -> V_204 ,
1000 ) ;
if ( V_2 -> V_66 == 0 )
* V_198 = * V_199 ;
else
* V_198 = F_180 (
V_2 -> V_10 [ V_2 -> V_66 ] -> V_25 *
V_2 -> V_204 ,
1000 ) ;
}
static void F_183 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = F_14 ( V_129 , struct V_1 ,
V_190 . V_207 ) ;
F_15 ( V_2 , V_208 , V_2 -> V_7 ,
L_57 ,
F_16 () ) ;
F_20 ( V_2 -> type -> V_188 == NULL ) ;
if ( F_184 ( & V_2 -> V_125 ) ) {
if ( V_2 -> V_94 )
V_2 -> type -> V_188 ( V_2 ) ;
F_111 ( & V_2 -> V_125 ) ;
}
F_171 ( V_2 -> V_189 , & V_2 -> V_190 ,
V_191 ) ;
}
static int F_185 ( struct V_209 * V_7 , struct V_210 * V_211 , int V_212 )
{
struct V_1 * V_2 = F_186 ( V_7 ) ;
struct V_213 * V_129 = F_187 ( V_211 ) ;
if ( V_212 == V_214 )
return F_188 ( V_2 , V_211 , V_212 ) ;
if ( ( V_212 == V_215 || V_212 == V_216 ) &&
( V_129 -> V_217 & 0xfc00 ) == 0x0400 )
V_129 -> V_217 ^= V_218 | 0x0400 ;
return F_189 ( & V_2 -> V_219 , V_129 , V_212 ) ;
}
static void F_85 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
V_10 -> V_54 = V_2 -> V_7 ;
F_190 ( V_10 -> V_54 , & V_10 -> V_19 ,
F_13 , V_220 ) ;
}
static void F_191 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_53 (channel, efx)
F_85 ( V_10 ) ;
}
static void F_86 ( struct V_9 * V_10 )
{
if ( V_10 -> V_54 )
F_192 ( & V_10 -> V_19 ) ;
V_10 -> V_54 = NULL ;
}
static void F_193 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_53 (channel, efx)
F_86 ( V_10 ) ;
}
static void F_194 ( struct V_209 * V_7 )
{
struct V_1 * V_2 = F_186 ( V_7 ) ;
struct V_9 * V_10 ;
F_53 (channel, efx)
F_195 ( V_10 ) ;
}
static int F_196 ( struct V_209 * V_7 )
{
struct V_1 * V_2 = F_186 ( V_7 ) ;
int V_59 ;
F_27 ( V_2 , V_42 , V_2 -> V_7 , L_58 ,
F_16 () ) ;
V_59 = F_1 ( V_2 ) ;
if ( V_59 )
return V_59 ;
if ( V_2 -> V_124 & V_133 )
return - V_221 ;
if ( F_197 ( V_2 ) && F_198 ( V_2 , V_96 ) )
return - V_8 ;
F_96 ( V_2 ) ;
F_89 ( V_2 ) ;
F_199 ( V_2 ) ;
return 0 ;
}
static int F_200 ( struct V_209 * V_7 )
{
struct V_1 * V_2 = F_186 ( V_7 ) ;
F_27 ( V_2 , V_145 , V_2 -> V_7 , L_59 ,
F_16 () ) ;
F_83 ( V_2 ) ;
return 0 ;
}
static struct V_222 * F_201 ( struct V_209 * V_7 ,
struct V_222 * V_223 )
{
struct V_1 * V_2 = F_186 ( V_7 ) ;
struct V_224 * V_225 = & V_2 -> V_225 ;
F_202 ( & V_2 -> V_226 ) ;
V_2 -> type -> V_227 ( V_2 ) ;
V_223 -> V_228 = V_225 -> V_228 ;
V_223 -> V_229 = V_225 -> V_229 ;
V_223 -> V_230 = V_225 -> V_230 ;
V_223 -> V_231 = V_225 -> V_231 ;
V_223 -> V_232 = V_2 -> V_233 ;
V_223 -> V_234 = V_225 -> V_235 ;
V_223 -> V_236 = V_225 -> V_237 ;
V_223 -> V_238 = ( V_225 -> V_239 +
V_225 -> V_240 ) ;
V_223 -> V_241 = V_225 -> V_242 ;
V_223 -> V_243 = V_225 -> V_244 ;
V_223 -> V_245 = V_225 -> V_246 ;
V_223 -> V_247 = V_225 -> V_248 ;
V_223 -> V_249 = V_225 -> V_250 ;
V_223 -> V_251 = ( V_223 -> V_238 +
V_223 -> V_241 +
V_223 -> V_243 +
V_225 -> V_252 ) ;
V_223 -> V_253 = ( V_223 -> V_249 +
V_225 -> V_254 ) ;
F_203 ( & V_2 -> V_226 ) ;
return V_223 ;
}
static void F_204 ( struct V_209 * V_7 )
{
struct V_1 * V_2 = F_186 ( V_7 ) ;
F_2 ( V_2 , V_255 , V_2 -> V_7 ,
L_60 ,
V_2 -> V_94 ) ;
F_75 ( V_2 , V_256 ) ;
}
static int F_205 ( struct V_209 * V_7 , int V_257 )
{
struct V_1 * V_2 = F_186 ( V_7 ) ;
int V_59 ;
V_59 = F_1 ( V_2 ) ;
if ( V_59 )
return V_59 ;
if ( V_257 > V_258 )
return - V_187 ;
F_27 ( V_2 , V_6 , V_2 -> V_7 , L_61 , V_257 ) ;
F_82 ( V_2 ) ;
F_83 ( V_2 ) ;
F_110 ( & V_2 -> V_125 ) ;
V_7 -> V_76 = V_257 ;
V_2 -> type -> V_131 ( V_2 ) ;
F_111 ( & V_2 -> V_125 ) ;
F_89 ( V_2 ) ;
F_90 ( V_2 -> V_7 ) ;
return 0 ;
}
static int F_206 ( struct V_209 * V_7 , void * V_129 )
{
struct V_1 * V_2 = F_186 ( V_7 ) ;
struct V_259 * V_260 = V_129 ;
char * V_261 = V_260 -> V_262 ;
if ( ! F_207 ( V_261 ) ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_62 ,
V_261 ) ;
return - V_263 ;
}
memcpy ( V_7 -> V_135 , V_261 , V_7 -> V_264 ) ;
F_208 ( V_2 ) ;
F_110 ( & V_2 -> V_125 ) ;
V_2 -> type -> V_131 ( V_2 ) ;
F_111 ( & V_2 -> V_125 ) ;
return 0 ;
}
static void F_209 ( struct V_209 * V_7 )
{
struct V_1 * V_2 = F_186 ( V_7 ) ;
struct V_265 * V_266 ;
union V_267 * V_268 = & V_2 -> V_269 ;
T_2 V_270 ;
int V_271 ;
V_2 -> V_115 = ! ! ( V_7 -> V_272 & V_273 ) ;
if ( V_2 -> V_115 || ( V_7 -> V_272 & V_274 ) ) {
memset ( V_268 , 0xff , sizeof( * V_268 ) ) ;
} else {
memset ( V_268 , 0x00 , sizeof( * V_268 ) ) ;
F_210 (ha, net_dev) {
V_270 = F_211 ( V_137 , V_266 -> V_260 ) ;
V_271 = V_270 & ( V_275 - 1 ) ;
F_212 ( V_271 , V_268 ) ;
}
F_212 ( 0xff , V_268 ) ;
}
if ( V_2 -> V_94 )
F_213 ( V_2 -> V_189 , & V_2 -> V_130 ) ;
}
static int F_214 ( struct V_209 * V_7 , T_6 V_129 )
{
struct V_1 * V_2 = F_186 ( V_7 ) ;
if ( V_7 -> V_276 & ~ V_129 & V_277 )
F_215 ( V_2 , V_278 ) ;
return 0 ;
}
static void F_216 ( struct V_1 * V_2 )
{
strcpy ( V_2 -> V_67 , V_2 -> V_7 -> V_67 ) ;
F_217 ( V_2 ) ;
F_52 ( V_2 ) ;
}
static int F_218 ( struct V_279 * V_280 ,
unsigned long V_281 , void * V_282 )
{
struct V_209 * V_7 = V_282 ;
if ( V_7 -> V_283 == & V_284 &&
V_281 == V_285 )
F_216 ( F_186 ( V_7 ) ) ;
return V_286 ;
}
static T_7
F_219 ( struct V_287 * V_93 , struct V_288 * V_289 , char * V_63 )
{
struct V_1 * V_2 = F_220 ( F_221 ( V_93 ) ) ;
return sprintf ( V_63 , L_63 , V_2 -> V_290 ) ;
}
static int F_222 ( struct V_1 * V_2 )
{
struct V_209 * V_7 = V_2 -> V_7 ;
struct V_9 * V_10 ;
int V_59 ;
V_7 -> V_291 = 5 * V_292 ;
V_7 -> V_33 = V_2 -> V_92 -> V_33 ;
V_7 -> V_283 = & V_284 ;
F_223 ( V_7 , & V_293 ) ;
V_7 -> V_294 = V_295 ;
F_224 () ;
V_2 -> V_3 = V_296 ;
F_225 () ;
if ( V_2 -> V_297 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 ,
L_64 ) ;
V_59 = - V_8 ;
goto V_298;
}
V_59 = F_226 ( V_7 , V_7 -> V_67 ) ;
if ( V_59 < 0 )
goto V_298;
F_216 ( V_2 ) ;
F_100 ( V_7 ) ;
V_59 = F_227 ( V_7 ) ;
if ( V_59 )
goto V_298;
F_53 (channel, efx) {
struct V_45 * V_46 ;
F_46 (tx_queue, channel)
F_228 ( V_46 ) ;
}
F_229 () ;
V_59 = F_230 ( & V_2 -> V_92 -> V_93 , & V_299 ) ;
if ( V_59 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_65 ) ;
goto V_300;
}
return 0 ;
V_300:
F_224 () ;
F_231 ( V_7 ) ;
V_298:
V_2 -> V_3 = V_301 ;
F_229 () ;
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_66 ) ;
return V_59 ;
}
static void F_232 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_45 * V_46 ;
if ( ! V_2 -> V_7 )
return;
F_20 ( F_186 ( V_2 -> V_7 ) != V_2 ) ;
F_53 (channel, efx) {
F_46 (tx_queue, channel)
F_233 ( V_46 ) ;
}
F_234 ( V_2 -> V_67 , F_235 ( V_2 -> V_92 ) , sizeof( V_2 -> V_67 ) ) ;
F_236 ( & V_2 -> V_92 -> V_93 , & V_299 ) ;
F_224 () ;
F_231 ( V_2 -> V_7 ) ;
V_2 -> V_3 = V_301 ;
F_229 () ;
}
void F_237 ( struct V_1 * V_2 , enum V_302 V_303 )
{
F_72 ( V_2 ) ;
F_83 ( V_2 ) ;
F_84 ( V_2 , false ) ;
F_110 ( & V_2 -> V_125 ) ;
if ( V_2 -> V_141 && V_303 != V_304 )
V_2 -> V_138 -> V_144 ( V_2 ) ;
V_2 -> type -> V_144 ( V_2 ) ;
}
int F_238 ( struct V_1 * V_2 , enum V_302 V_303 , bool V_305 )
{
int V_59 ;
F_72 ( V_2 ) ;
V_59 = V_2 -> type -> V_139 ( V_2 ) ;
if ( V_59 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_67 ) ;
goto V_61;
}
if ( ! V_305 )
goto V_61;
if ( V_2 -> V_141 && V_303 != V_304 ) {
V_59 = V_2 -> V_138 -> V_139 ( V_2 ) ;
if ( V_59 )
goto V_61;
if ( V_2 -> V_138 -> V_142 ( V_2 ) )
F_2 ( V_2 , V_6 , V_2 -> V_7 ,
L_68 ) ;
}
V_2 -> type -> V_131 ( V_2 ) ;
F_88 ( V_2 , false ) ;
F_239 ( V_2 ) ;
F_240 ( V_2 ) ;
F_111 ( & V_2 -> V_125 ) ;
F_89 ( V_2 ) ;
return 0 ;
V_61:
V_2 -> V_141 = false ;
F_111 ( & V_2 -> V_125 ) ;
return V_59 ;
}
int F_198 ( struct V_1 * V_2 , enum V_302 V_303 )
{
int V_59 , V_306 ;
bool V_307 ;
F_101 ( V_2 , V_6 , V_2 -> V_7 , L_69 ,
F_241 ( V_303 ) ) ;
F_82 ( V_2 ) ;
F_237 ( V_2 , V_303 ) ;
V_59 = V_2 -> type -> V_308 ( V_2 , V_303 ) ;
if ( V_59 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_70 ) ;
goto V_105;
}
V_2 -> V_297 &= - ( 1 << ( V_303 + 1 ) ) ;
F_121 ( V_2 -> V_92 ) ;
V_105:
V_307 = V_59 ||
V_303 == V_309 ||
V_303 == V_310 ;
V_306 = F_238 ( V_2 , V_303 , ! V_307 ) ;
if ( V_306 ) {
V_307 = true ;
if ( ! V_59 )
V_59 = V_306 ;
}
if ( V_307 ) {
F_242 ( V_2 -> V_7 ) ;
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_71 ) ;
V_2 -> V_3 = V_4 ;
} else {
F_27 ( V_2 , V_6 , V_2 -> V_7 , L_72 ) ;
F_90 ( V_2 -> V_7 ) ;
}
return V_59 ;
}
static int F_243 ( struct V_1 * V_2 )
{
#ifdef F_244
struct V_311 * V_312 =
F_245 ( F_246 ( V_2 -> V_92 ) ) ;
if ( F_247 ( V_312 ) ) {
return 1 ;
}
#endif
return 0 ;
}
static void F_248 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = F_14 ( V_129 , struct V_1 , V_313 ) ;
unsigned long V_314 ;
enum V_302 V_303 ;
V_314 = F_249 ( V_2 -> V_297 ) ;
V_303 = F_250 ( V_314 ) - 1 ;
if ( ( V_303 == V_310 ||
V_303 == V_315 ) &&
F_243 ( V_2 ) )
return;
if ( ! V_314 )
return;
F_224 () ;
if ( V_2 -> V_3 == V_296 )
( void ) F_198 ( V_2 , V_303 ) ;
F_229 () ;
}
void F_75 ( struct V_1 * V_2 , enum V_302 type )
{
enum V_302 V_303 ;
if ( V_2 -> V_3 == V_5 ) {
F_27 ( V_2 , V_6 , V_2 -> V_7 ,
L_73 ,
F_241 ( type ) ) ;
return;
}
switch ( type ) {
case V_304 :
case V_96 :
case V_315 :
case V_316 :
case V_309 :
case V_310 :
V_303 = type ;
F_27 ( V_2 , V_6 , V_2 -> V_7 , L_74 ,
F_241 ( V_303 ) ) ;
break;
default:
V_303 = V_2 -> type -> V_317 ( type ) ;
F_27 ( V_2 , V_6 , V_2 -> V_7 ,
L_75 ,
F_241 ( V_303 ) , F_241 ( type ) ) ;
break;
}
F_251 ( V_303 , & V_2 -> V_297 ) ;
F_225 () ;
if ( F_249 ( V_2 -> V_3 ) != V_296 )
return;
F_155 ( V_2 ) ;
F_213 ( V_318 , & V_2 -> V_313 ) ;
}
int F_252 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_253 ( struct V_1 * V_2 ) {}
static bool F_254 ( struct V_1 * V_2 )
{
return false ;
}
static int F_255 ( struct V_1 * V_2 ,
struct V_92 * V_92 , struct V_209 * V_7 )
{
int V_43 ;
F_256 ( & V_2 -> V_319 ) ;
#ifdef F_257
F_258 ( & V_2 -> V_320 ) ;
#endif
F_259 ( & V_2 -> V_313 , F_248 ) ;
F_260 ( & V_2 -> V_190 , F_183 ) ;
F_260 ( & V_2 -> V_321 , V_322 ) ;
V_2 -> V_92 = V_92 ;
V_2 -> V_323 = V_324 ;
V_2 -> V_3 = V_301 ;
F_234 ( V_2 -> V_67 , F_235 ( V_92 ) , sizeof( V_2 -> V_67 ) ) ;
V_2 -> V_7 = V_7 ;
F_256 ( & V_2 -> V_226 ) ;
F_261 ( & V_2 -> V_125 ) ;
V_2 -> V_138 = & V_325 ;
V_2 -> V_219 . V_93 = V_7 ;
F_259 ( & V_2 -> V_130 , F_112 ) ;
F_262 ( & V_2 -> V_326 ) ;
for ( V_43 = 0 ; V_43 < V_99 ; V_43 ++ ) {
V_2 -> V_10 [ V_43 ] = F_40 ( V_2 , V_43 , NULL ) ;
if ( ! V_2 -> V_10 [ V_43 ] )
goto V_61;
}
F_29 ( V_2 -> type -> V_165 > V_99 ) ;
V_2 -> V_169 = F_30 ( V_2 -> type -> V_327 ,
V_169 ) ;
snprintf ( V_2 -> V_328 , sizeof( V_2 -> V_328 ) , L_76 ,
F_235 ( V_92 ) ) ;
V_2 -> V_189 = F_263 ( V_2 -> V_328 ) ;
if ( ! V_2 -> V_189 )
goto V_61;
return 0 ;
V_61:
F_264 ( V_2 ) ;
return - V_104 ;
}
static void F_264 ( struct V_1 * V_2 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_99 ; V_43 ++ )
F_87 ( V_2 -> V_10 [ V_43 ] ) ;
if ( V_2 -> V_189 ) {
F_265 ( V_2 -> V_189 ) ;
V_2 -> V_189 = NULL ;
}
}
static void F_266 ( struct V_1 * V_2 )
{
F_20 ( V_2 -> V_3 == V_296 ) ;
F_176 ( & V_2 -> V_313 ) ;
#ifdef F_143
F_146 ( V_2 -> V_7 -> V_161 ) ;
V_2 -> V_7 -> V_161 = NULL ;
#endif
F_84 ( V_2 , false ) ;
F_267 ( V_2 ) ;
F_117 ( V_2 ) ;
V_2 -> type -> V_144 ( V_2 ) ;
F_193 ( V_2 ) ;
F_178 ( V_2 ) ;
}
static void F_268 ( struct V_92 * V_92 )
{
struct V_1 * V_2 ;
V_2 = F_220 ( V_92 ) ;
if ( ! V_2 )
return;
F_224 () ;
F_242 ( V_2 -> V_7 ) ;
F_84 ( V_2 , false ) ;
F_229 () ;
F_269 ( V_2 ) ;
F_232 ( V_2 ) ;
F_270 ( V_2 ) ;
F_266 ( V_2 ) ;
F_130 ( V_2 ) ;
F_27 ( V_2 , V_6 , V_2 -> V_7 , L_77 ) ;
F_264 ( V_2 ) ;
F_271 ( V_92 , NULL ) ;
F_272 ( V_2 -> V_7 ) ;
F_273 ( V_92 ) ;
}
static void F_274 ( struct V_1 * V_2 )
{
struct V_92 * V_93 = V_2 -> V_92 ;
char V_329 [ V_330 ] ;
T_7 V_331 ;
int V_43 , V_47 ;
V_331 = F_275 ( V_93 , 0 , sizeof( V_329 ) , V_329 ) ;
if ( V_331 <= 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_78 ) ;
return;
}
V_43 = F_276 ( V_329 , 0 , V_331 , V_332 ) ;
if ( V_43 < 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_79 ) ;
return;
}
V_47 = F_277 ( & V_329 [ V_43 ] ) ;
V_43 += V_333 ;
if ( V_43 + V_47 > V_331 )
V_47 = V_331 - V_43 ;
V_43 = F_278 ( V_329 , V_43 , V_47 , L_80 ) ;
if ( V_43 < 0 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_81 ) ;
return;
}
V_47 = F_279 ( & V_329 [ V_43 ] ) ;
V_43 += V_334 ;
if ( V_43 + V_47 > V_331 ) {
F_2 ( V_2 , V_6 , V_2 -> V_7 , L_82 ) ;
return;
}
F_101 ( V_2 , V_6 , V_2 -> V_7 ,
L_83 , V_47 , & V_329 [ V_43 ] ) ;
}
static int F_280 ( struct V_1 * V_2 )
{
int V_59 ;
V_59 = F_167 ( V_2 ) ;
if ( V_59 )
goto V_140;
F_191 ( V_2 ) ;
V_59 = V_2 -> type -> V_139 ( V_2 ) ;
if ( V_59 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 ,
L_67 ) ;
goto V_151;
}
V_59 = F_114 ( V_2 ) ;
if ( V_59 ) {
F_2 ( V_2 , V_36 , V_2 -> V_7 ,
L_84 ) ;
goto V_154;
}
V_59 = F_281 ( V_2 ) ;
if ( V_59 )
goto V_335;
F_88 ( V_2 , false ) ;
return 0 ;
V_335:
F_117 ( V_2 ) ;
V_154:
V_2 -> type -> V_144 ( V_2 ) ;
V_151:
F_193 ( V_2 ) ;
F_178 ( V_2 ) ;
V_140:
return V_59 ;
}
static int F_282 ( struct V_92 * V_92 ,
const struct V_336 * V_172 )
{
struct V_209 * V_7 ;
struct V_1 * V_2 ;
int V_59 ;
V_7 = F_283 ( sizeof( * V_2 ) , V_337 ,
V_338 ) ;
if ( ! V_7 )
return - V_104 ;
V_2 = F_186 ( V_7 ) ;
V_2 -> type = ( const struct V_339 * ) V_172 -> V_340 ;
V_7 -> V_276 |= ( V_2 -> type -> V_341 | V_342 |
V_343 | V_344 |
V_345 ) ;
if ( V_2 -> type -> V_341 & V_346 )
V_7 -> V_276 |= V_347 ;
V_7 -> V_348 |= ( V_349 | V_342 |
V_343 | V_350 |
V_345 ) ;
V_7 -> V_351 = V_7 -> V_276 & ~ V_343 ;
F_271 ( V_92 , V_2 ) ;
F_284 ( V_7 , & V_92 -> V_93 ) ;
V_59 = F_255 ( V_2 , V_92 , V_7 ) ;
if ( V_59 )
goto V_140;
F_101 ( V_2 , V_36 , V_2 -> V_7 ,
L_85 ) ;
F_274 ( V_2 ) ;
V_59 = F_119 ( V_2 ) ;
if ( V_59 )
goto V_143;
V_59 = F_280 ( V_2 ) ;
if ( V_59 )
goto V_151;
V_59 = F_222 ( V_2 ) ;
if ( V_59 )
goto V_154;
V_59 = F_285 ( V_2 ) ;
if ( V_59 )
F_2 ( V_2 , V_36 , V_2 -> V_7 ,
L_86 , V_59 ) ;
F_27 ( V_2 , V_36 , V_2 -> V_7 , L_87 ) ;
F_224 () ;
V_59 = F_286 ( V_2 ) ;
F_229 () ;
if ( V_59 )
F_134 ( V_2 , V_36 , V_2 -> V_7 ,
L_88 , V_59 ) ;
V_59 = F_287 ( V_92 ) ;
if ( V_59 && V_59 != - V_187 )
F_134 ( V_2 , V_36 , V_2 -> V_7 ,
L_89 , V_59 ) ;
return 0 ;
V_154:
F_266 ( V_2 ) ;
V_151:
F_130 ( V_2 ) ;
V_143:
F_264 ( V_2 ) ;
V_140:
F_271 ( V_92 , NULL ) ;
F_68 ( V_59 > 0 ) ;
F_27 ( V_2 , V_6 , V_2 -> V_7 , L_90 , V_59 ) ;
F_272 ( V_7 ) ;
return V_59 ;
}
static int F_288 ( struct V_287 * V_93 )
{
struct V_1 * V_2 = F_220 ( F_221 ( V_93 ) ) ;
F_224 () ;
if ( V_2 -> V_3 != V_4 ) {
V_2 -> V_3 = V_301 ;
F_82 ( V_2 ) ;
F_83 ( V_2 ) ;
F_84 ( V_2 , false ) ;
}
F_229 () ;
return 0 ;
}
static int F_289 ( struct V_287 * V_93 )
{
struct V_1 * V_2 = F_220 ( F_221 ( V_93 ) ) ;
F_224 () ;
if ( V_2 -> V_3 != V_4 ) {
F_88 ( V_2 , false ) ;
F_110 ( & V_2 -> V_125 ) ;
V_2 -> V_138 -> V_142 ( V_2 ) ;
F_111 ( & V_2 -> V_125 ) ;
F_89 ( V_2 ) ;
F_90 ( V_2 -> V_7 ) ;
V_2 -> V_3 = V_296 ;
V_2 -> type -> V_352 ( V_2 ) ;
}
F_229 () ;
F_213 ( V_318 , & V_2 -> V_313 ) ;
return 0 ;
}
static int F_290 ( struct V_287 * V_93 )
{
struct V_92 * V_92 = F_221 ( V_93 ) ;
struct V_1 * V_2 = F_220 ( V_92 ) ;
V_2 -> type -> V_144 ( V_2 ) ;
V_2 -> V_297 = 0 ;
F_291 ( V_92 ) ;
return F_292 ( V_92 , V_353 ) ;
}
static int F_293 ( struct V_287 * V_93 )
{
struct V_92 * V_92 = F_221 ( V_93 ) ;
struct V_1 * V_2 = F_220 ( V_92 ) ;
int V_59 ;
V_59 = F_292 ( V_92 , V_354 ) ;
if ( V_59 )
return V_59 ;
F_294 ( V_92 ) ;
V_59 = F_120 ( V_92 ) ;
if ( V_59 )
return V_59 ;
F_121 ( V_2 -> V_92 ) ;
V_59 = V_2 -> type -> V_308 ( V_2 , V_96 ) ;
if ( V_59 )
return V_59 ;
V_59 = V_2 -> type -> V_139 ( V_2 ) ;
if ( V_59 )
return V_59 ;
F_289 ( V_93 ) ;
return 0 ;
}
static int F_295 ( struct V_287 * V_93 )
{
int V_59 ;
F_288 ( V_93 ) ;
V_59 = F_290 ( V_93 ) ;
if ( V_59 )
F_293 ( V_93 ) ;
return V_59 ;
}
static T_8 F_296 ( struct V_92 * V_355 ,
enum V_356 V_3 )
{
T_8 V_357 = V_358 ;
struct V_1 * V_2 = F_220 ( V_355 ) ;
if ( V_3 == V_359 )
return V_360 ;
F_224 () ;
if ( V_2 -> V_3 != V_4 ) {
V_2 -> V_3 = V_5 ;
V_2 -> V_297 = 0 ;
F_82 ( V_2 ) ;
F_83 ( V_2 ) ;
F_84 ( V_2 , false ) ;
V_357 = V_361 ;
} else {
V_357 = V_358 ;
}
F_229 () ;
F_129 ( V_355 ) ;
return V_357 ;
}
static T_8 F_297 ( struct V_92 * V_355 )
{
struct V_1 * V_2 = F_220 ( V_355 ) ;
T_8 V_357 = V_358 ;
int V_59 ;
if ( F_120 ( V_355 ) ) {
F_2 ( V_2 , V_362 , V_2 -> V_7 ,
L_91 ) ;
V_357 = V_360 ;
}
V_59 = F_298 ( V_355 ) ;
if ( V_59 ) {
F_2 ( V_2 , V_362 , V_2 -> V_7 ,
L_92 , V_59 ) ;
}
return V_357 ;
}
static void F_299 ( struct V_92 * V_355 )
{
struct V_1 * V_2 = F_220 ( V_355 ) ;
int V_59 ;
F_224 () ;
if ( V_2 -> V_3 == V_4 )
goto V_105;
V_59 = F_198 ( V_2 , V_96 ) ;
if ( V_59 ) {
F_2 ( V_2 , V_362 , V_2 -> V_7 ,
L_93 , V_59 ) ;
} else {
V_2 -> V_3 = V_296 ;
F_27 ( V_2 , V_362 , V_2 -> V_7 ,
L_94 ) ;
}
V_105:
F_229 () ;
}
static int T_9 F_300 ( void )
{
int V_59 ;
F_301 ( V_363 L_95 V_364 L_96 ) ;
V_59 = F_302 ( & V_365 ) ;
if ( V_59 )
goto V_366;
V_59 = F_303 () ;
if ( V_59 )
goto V_367;
V_318 = F_263 ( L_97 ) ;
if ( ! V_318 ) {
V_59 = - V_104 ;
goto V_368;
}
V_59 = F_304 ( & V_369 ) ;
if ( V_59 < 0 )
goto V_370;
return 0 ;
V_370:
F_265 ( V_318 ) ;
V_368:
F_305 () ;
V_367:
F_306 ( & V_365 ) ;
V_366:
return V_59 ;
}
static void T_10 F_307 ( void )
{
F_301 ( V_363 L_98 ) ;
F_308 ( & V_369 ) ;
F_265 ( V_318 ) ;
F_305 () ;
F_306 ( & V_365 ) ;
}

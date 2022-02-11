static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return V_5 ? V_5 -> V_6 : NULL ;
}
static inline T_1 F_3 ( unsigned int V_7 )
{
if ( V_7 > V_8 + 1 )
V_7 = V_8 ;
else if ( V_7 < 2 )
V_7 = 1 ;
else
V_7 -- ;
return ( T_1 ) V_7 ;
}
static inline T_1 F_4 ( unsigned int V_9 )
{
return F_3 (
F_5 ( V_10 / 1000000 * V_9 , 1000 ) ) ;
}
static inline unsigned int F_6 ( unsigned int V_11 )
{
return F_5 ( ( V_11 + 1 ) * 1000 ,
V_10 / 1000000 ) ;
}
static inline T_1 F_7 ( unsigned int V_12 )
{
return F_3 (
F_5 ( V_10 , V_12 * 16 ) ) ;
}
static inline unsigned int F_8 ( unsigned int V_11 )
{
return F_5 ( V_10 , ( V_11 + 1 ) * 16 ) ;
}
static inline T_1 F_9 ( unsigned int V_12 ,
unsigned int V_13 )
{
return F_3 (
F_5 ( V_10 , V_12 * V_13 ) ) ;
}
static inline unsigned int F_10 ( unsigned int V_11 ,
unsigned int V_13 )
{
return F_5 ( V_10 ,
( V_11 + 1 ) * V_13 ) ;
}
static inline T_1 F_11 ( unsigned int V_7 )
{
if ( V_7 > V_14 )
V_7 = V_14 ;
else if ( V_7 < 4 )
V_7 = 0 ;
return ( T_1 ) V_7 ;
}
static inline T_1 F_12 ( unsigned int V_9 )
{
return F_11 (
F_5 ( V_10 / 1000000 * V_9 , 1000 ) ) ;
}
static inline unsigned int F_13 ( unsigned int V_15 )
{
return F_5 ( V_15 * 1000 ,
V_10 / 1000000 ) ;
}
static inline unsigned int F_14 ( unsigned int V_15 )
{
return F_5 ( V_15 , V_10 / 1000000 ) ;
}
static T_2 F_15 ( T_1 V_11 )
{
return F_5 ( ( 1 << 2 ) * ( ( T_2 ) V_11 + 1 ) * 1000 ,
V_10 / 1000000 ) ;
}
static T_3 F_16 ( T_1 V_15 , T_1 V_11 )
{
T_3 V_16 ;
T_2 V_17 ;
V_16 = ( ( ( T_3 ) V_15 << 2 ) | 0x3 ) * ( V_11 + 1 ) * 1000 ;
V_17 = F_17 ( V_16 , V_10 / 1000000 ) ;
if ( V_17 >= V_10 / 1000000 / 2 )
V_16 ++ ;
return V_16 ;
}
static unsigned int F_18 ( T_1 V_15 , T_1 V_11 )
{
T_3 V_16 ;
T_2 V_17 ;
V_16 = ( ( ( T_3 ) V_15 << 2 ) | 0x3 ) * ( V_11 + 1 ) ;
V_17 = F_17 ( V_16 , V_10 / 1000000 ) ;
if ( V_17 >= V_10 / 1000000 / 2 )
V_16 ++ ;
return ( unsigned int ) V_16 ;
}
static T_3 F_19 ( T_2 V_9 )
{
T_3 V_18 ;
T_2 V_17 ;
V_18 = V_10 / 1000000 * ( T_3 ) V_9 ;
V_17 = F_17 ( V_18 , 1000 ) ;
if ( V_17 >= 1000 / 2 )
V_18 ++ ;
return V_18 ;
}
static T_1 F_20 ( T_3 V_15 )
{
F_17 ( V_15 , ( V_19 << 2 ) | 0x3 ) ;
if ( V_15 > V_8 + 1 )
V_15 = V_8 ;
else if ( V_15 < 2 )
V_15 = 1 ;
else
V_15 -- ;
return ( T_1 ) V_15 ;
}
static inline void F_21 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
F_22 ( V_21 , V_24 , ~ V_25 , V_23 ) ;
}
static inline void F_23 ( struct V_20 * V_21 ,
enum V_26 V_23 )
{
F_22 ( V_21 , V_24 , ~ V_27 , V_23 ) ;
}
static inline void F_24 ( struct V_20 * V_21 , bool V_28 )
{
F_22 ( V_21 , V_24 , ~ ( V_29 | V_30 ) ,
V_28 ? ( V_29 | V_30 ) : 0 ) ;
}
static inline void F_25 ( struct V_20 * V_21 , bool V_28 )
{
F_22 ( V_21 , V_24 , ~ ( V_31 | V_32 ) ,
V_28 ? ( V_31 | V_32 ) : 0 ) ;
}
static inline void F_26 ( struct V_20 * V_21 ,
bool V_28 )
{
F_22 ( V_21 , V_24 , ~ V_33 ,
V_28 ? V_33 : 0 ) ;
}
static inline void F_27 ( struct V_20 * V_21 ,
bool V_28 )
{
F_22 ( V_21 , V_24 , ~ V_34 ,
V_28 ? V_34 : 0 ) ;
}
static inline void F_28 ( struct V_20 * V_21 ,
T_2 V_35 )
{
F_22 ( V_21 , V_24 , ~ V_36 ,
V_35 & V_36 ) ;
}
static void F_29 ( struct V_20 * V_21 ,
unsigned int V_37 ,
unsigned int * V_38 ,
unsigned int * V_39 )
{
T_2 V_40 ;
unsigned int V_41 = V_37 * 16 ;
if ( * V_38 < F_5 ( V_41 , 16 + 3 ) ) {
V_40 = V_42 ;
* V_38 = F_5 ( V_41 , 16 + 4 ) ;
} else {
V_40 = V_43 ;
* V_38 = F_5 ( V_41 , 16 + 3 ) ;
}
if ( * V_39 > F_5 ( V_41 , 16 - 3 ) ) {
V_40 |= V_44 ;
* V_39 = F_5 ( V_41 , 16 - 4 ) ;
} else {
V_40 |= V_43 ;
* V_39 = F_5 ( V_41 , 16 - 3 ) ;
}
F_22 ( V_21 , V_24 , ~ V_45 , V_40 ) ;
}
static inline void F_30 ( struct V_20 * V_21 ,
bool V_46 )
{
F_22 ( V_21 , V_24 , ~ V_47 ,
V_46 ? V_47 : 0 ) ;
}
static unsigned int F_31 ( struct V_20 * V_21 ,
unsigned int V_12 ,
T_1 * V_11 )
{
* V_11 = F_7 ( V_12 ) ;
F_32 ( V_21 , V_48 , * V_11 ) ;
return F_8 ( * V_11 ) ;
}
static unsigned int F_33 ( struct V_20 * V_21 ,
unsigned int V_12 ,
T_1 * V_11 )
{
* V_11 = F_7 ( V_12 ) ;
F_32 ( V_21 , V_49 , * V_11 ) ;
return F_8 ( * V_11 ) ;
}
static T_2 F_34 ( struct V_20 * V_21 , T_2 V_9 ,
T_1 * V_11 )
{
T_3 V_50 ;
if ( V_9 > V_51 )
V_9 = V_51 ;
V_50 = F_19 ( V_9 ) ;
* V_11 = F_20 ( V_50 ) ;
F_32 ( V_21 , V_48 , * V_11 ) ;
return ( T_2 ) F_16 ( V_19 , * V_11 ) ;
}
static T_2 F_35 ( struct V_20 * V_21 , T_2 V_9 ,
T_1 * V_11 )
{
T_3 V_50 ;
if ( V_9 > V_51 )
V_9 = V_51 ;
V_50 = F_19 ( V_9 ) ;
* V_11 = F_20 ( V_50 ) ;
F_32 ( V_21 , V_49 , * V_11 ) ;
return ( T_2 ) F_16 ( V_19 , * V_11 ) ;
}
static unsigned int F_36 ( struct V_20 * V_21 ,
unsigned int V_52 )
{
T_2 V_16 ;
V_16 = F_5 ( V_52 * 100 , 625 ) ;
if ( V_16 != 0 )
V_16 -- ;
if ( V_16 > 15 )
V_16 = 15 ;
F_32 ( V_21 , V_53 , V_16 ) ;
return F_5 ( ( V_16 + 1 ) * 100 , 16 ) ;
}
static T_2 F_37 ( struct V_20 * V_21 , T_2 V_54 )
{
T_2 V_15 = F_12 ( V_54 ) ;
F_32 ( V_21 , V_55 , V_15 ) ;
return F_13 ( V_15 ) ;
}
static inline void F_38 ( struct V_2 * V_3 , T_2 V_56 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
if ( F_39 ( V_5 ) || F_40 ( V_5 ) )
V_56 ^= V_57 ;
V_56 &= ( V_58 | V_59 | V_60 ) ;
F_22 ( V_5 -> V_21 , V_61 ,
~ ( V_58 | V_59 | V_60 ) , V_56 ) ;
}
static inline void F_41 ( struct V_2 * V_3 , T_2 V_56 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
if ( F_39 ( V_5 ) || F_40 ( V_5 ) )
V_56 ^= V_57 ;
V_56 &= V_62 ;
F_22 ( V_5 -> V_21 , V_61 , ~ V_62 , V_56 ) ;
}
int F_42 ( struct V_2 * V_3 , T_2 V_63 , bool * V_64 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_20 * V_21 = NULL ;
unsigned long V_65 ;
union V_66 V_67 [ V_68 ] ;
unsigned int V_69 , V_70 , V_71 ;
T_2 V_72 , V_40 ;
int V_73 , V_74 , V_75 , V_76 , V_77 , V_78 , V_79 , V_80 , V_81 ;
T_2 V_82 , V_83 , V_84 ;
* V_64 = false ;
if ( V_6 == NULL )
return - V_85 ;
V_21 = V_6 -> V_21 ;
if ( ! ( F_39 ( V_5 ) || F_40 ( V_5 ) ) )
return - V_85 ;
V_82 = F_43 ( V_21 , V_24 ) ;
V_83 = F_43 ( V_21 , V_61 ) ;
if ( F_39 ( V_5 ) || F_40 ( V_5 ) )
V_83 ^= V_57 ;
V_84 = F_43 ( V_21 , V_86 ) ;
V_73 = V_84 & V_87 ;
V_74 = V_84 & V_88 ;
V_75 = V_84 & V_89 ;
V_76 = V_84 & V_90 ;
V_77 = V_83 & V_62 ;
V_78 = V_83 & V_60 ;
V_79 = V_83 & V_58 ;
V_80 = V_83 & V_59 ;
F_44 ( 2 , V_91 , V_3 , L_1 ,
V_73 ? L_2 : L_3 , V_74 ? L_4 : L_3 ,
V_75 ? L_5 : L_3 , V_76 ? L_6 : L_3 ,
V_84 & V_92 ? L_7 : L_3 ,
V_84 & V_93 ? L_8 : L_3 ) ;
F_44 ( 2 , V_91 , V_3 , L_9 ,
V_77 ? L_10 : L_3 , V_78 ? L_11 : L_3 ,
V_79 ? L_12 : L_3 , V_80 ? L_13 : L_3 ) ;
if ( V_77 && V_73 ) {
F_41 ( V_3 , 0 ) ;
V_72 = V_94 ;
F_45 ( V_3 , V_95 , & V_72 ) ;
* V_64 = true ;
}
V_81 = 0 ;
if ( ( V_78 && V_74 ) || ( V_79 && V_75 ) ) {
for ( V_69 = 0 , V_40 = V_96 ;
( V_40 & V_96 ) && ! V_81 ; V_69 = 0 ) {
for ( V_70 = 0 ;
( V_40 & V_96 ) && V_70 < V_68 ; V_70 ++ ) {
V_40 = F_43 ( V_21 , V_97 ) ;
V_67 [ V_69 ] . V_98 = V_40 & ~ V_96 ;
V_69 ++ ;
}
if ( V_69 == 0 )
break;
V_70 = V_69 * sizeof( union V_66 ) ;
V_71 = F_46 ( & V_6 -> V_99 ,
( unsigned char * ) V_67 , V_70 ,
& V_6 -> V_100 ) ;
if ( V_71 != V_70 )
V_81 ++ ;
}
* V_64 = true ;
}
V_72 = 0 ;
V_40 = 0 ;
if ( V_81 ) {
V_72 |= V_101 ;
F_47 ( V_3 , L_14 ) ;
}
if ( V_80 && V_76 ) {
V_40 |= V_32 ;
V_72 |= V_102 ;
F_47 ( V_3 , L_15 ) ;
}
if ( V_79 && V_75 ) {
V_40 |= V_31 ;
V_72 |= V_103 ;
}
if ( V_40 ) {
F_32 ( V_21 , V_24 , V_82 & ~ V_40 ) ;
F_32 ( V_21 , V_24 , V_82 ) ;
* V_64 = true ;
}
F_48 ( & V_6 -> V_100 , V_65 ) ;
if ( F_49 ( & V_6 -> V_99 ) >= V_104 / 2 )
V_72 |= V_105 ;
F_50 ( & V_6 -> V_100 , V_65 ) ;
if ( V_72 )
F_45 ( V_3 , V_106 , & V_72 ) ;
return 0 ;
}
static int F_51 ( struct V_2 * V_3 , T_4 * V_107 , T_5 V_15 ,
T_6 * V_108 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
bool V_46 ;
T_1 V_11 ;
unsigned int V_69 , V_16 ;
union V_66 * V_109 ;
unsigned V_110 , V_40 , V_111 ;
if ( V_6 == NULL )
return - V_85 ;
V_46 = ( bool ) F_52 ( & V_6 -> V_112 ) ;
V_11 = ( T_1 ) F_52 ( & V_6 -> V_113 ) ;
V_16 = V_15 / sizeof( union V_66 )
* sizeof( union V_66 ) ;
if ( V_16 == 0 ) {
* V_108 = 0 ;
return 0 ;
}
V_16 = F_53 ( & V_6 -> V_99 , V_107 , V_16 ,
& V_6 -> V_100 ) ;
V_16 /= sizeof( union V_66 ) ;
* V_108 = V_16 * sizeof( union V_66 ) ;
for ( V_109 = (union V_66 * ) V_107 , V_69 = 0 ; V_69 < V_16 ; V_109 ++ , V_69 ++ ) {
if ( ( V_109 -> V_98 & V_114 ) == V_114 ) {
V_110 = 0 ;
V_111 = 1 ;
} else {
V_110 = ( V_109 -> V_98 & V_115 ) ? 1 : 0 ;
if ( V_46 )
V_110 = V_110 ? 0 : 1 ;
V_111 = 0 ;
}
V_40 = ( unsigned ) F_16 (
( T_1 ) ( V_109 -> V_98 & V_19 ) , V_11 ) ;
if ( V_40 > V_51 )
V_40 = V_51 ;
F_54 ( & V_109 -> V_116 ) ;
V_109 -> V_116 . V_117 = V_110 ;
V_109 -> V_116 . V_118 = V_40 ;
V_109 -> V_116 . V_119 = V_111 ;
F_44 ( 2 , V_91 , V_3 , L_16 ,
V_40 , V_110 ? L_17 : L_18 , V_111 ? L_19 : L_20 ) ;
if ( V_111 )
F_44 ( 2 , V_91 , V_3 , L_21 ) ;
}
return 0 ;
}
static int F_55 ( struct V_2 * V_3 ,
struct V_120 * V_109 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( V_6 == NULL )
return - V_85 ;
F_56 ( & V_6 -> V_121 ) ;
memcpy ( V_109 , & V_6 -> V_122 ,
sizeof( struct V_120 ) ) ;
F_57 ( & V_6 -> V_121 ) ;
return 0 ;
}
static int F_58 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_20 * V_21 ;
if ( V_6 == NULL )
return - V_85 ;
V_21 = V_6 -> V_21 ;
F_56 ( & V_6 -> V_121 ) ;
F_38 ( V_3 , 0 ) ;
F_25 ( V_21 , false ) ;
F_27 ( V_21 , false ) ;
F_28 ( V_21 , V_123 ) ;
F_37 ( V_21 , 0 ) ;
F_32 ( V_21 , V_49 , V_8 ) ;
V_6 -> V_122 . V_124 = true ;
F_57 ( & V_6 -> V_121 ) ;
return 0 ;
}
static int F_59 ( struct V_2 * V_3 ,
struct V_120 * V_109 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_20 * V_21 ;
struct V_120 * V_125 ;
T_1 V_113 ;
if ( V_6 == NULL )
return - V_85 ;
if ( V_109 -> V_124 )
return F_58 ( V_3 ) ;
if ( V_109 -> V_126 != V_127 )
return - V_128 ;
V_21 = V_6 -> V_21 ;
V_125 = & V_6 -> V_122 ;
F_56 ( & V_6 -> V_121 ) ;
V_125 -> V_124 = V_109 -> V_124 ;
V_109 -> V_126 = V_127 ;
V_125 -> V_126 = V_109 -> V_126 ;
V_109 -> V_129 = sizeof( union V_66 ) ;
V_125 -> V_129 = V_109 -> V_129 ;
F_38 ( V_3 , 0 ) ;
F_25 ( V_21 , false ) ;
F_27 ( V_21 , V_109 -> V_130 ) ;
V_125 -> V_130 = V_109 -> V_130 ;
if ( V_109 -> V_130 ) {
V_109 -> V_131 = F_33 ( V_21 , V_109 -> V_131 ,
& V_113 ) ;
V_125 -> V_131 = V_109 -> V_131 ;
V_109 -> V_52 = 50 ;
V_125 -> V_52 = V_109 -> V_52 ;
F_29 ( V_21 , V_109 -> V_131 ,
& V_109 -> V_132 ,
& V_109 -> V_133 ) ;
V_125 -> V_132 = V_109 -> V_132 ;
V_125 -> V_133 = V_109 -> V_133 ;
V_109 -> V_134 =
( T_2 ) F_16 ( V_19 , V_113 ) ;
} else {
V_109 -> V_134 =
F_35 ( V_21 , V_109 -> V_134 ,
& V_113 ) ;
}
V_125 -> V_134 = V_109 -> V_134 ;
F_60 ( & V_6 -> V_113 , V_113 ) ;
V_109 -> V_135 =
F_37 ( V_21 , V_109 -> V_135 ) ;
V_125 -> V_135 = V_109 -> V_135 ;
V_109 -> V_136 = F_15 ( V_113 ) ;
V_125 -> V_136 = V_109 -> V_136 ;
F_23 ( V_21 , V_137 ) ;
F_28 ( V_21 , V_36 ) ;
V_125 -> V_138 = V_109 -> V_138 ;
F_60 ( & V_6 -> V_112 , V_109 -> V_138 ) ;
V_125 -> V_139 = V_109 -> V_139 ;
V_125 -> V_28 = V_109 -> V_28 ;
if ( V_109 -> V_28 ) {
unsigned long V_65 ;
F_48 ( & V_6 -> V_100 , V_65 ) ;
F_61 ( & V_6 -> V_99 ) ;
F_50 ( & V_6 -> V_100 , V_65 ) ;
if ( V_109 -> V_139 )
F_38 ( V_3 , V_60 | V_58 | V_59 ) ;
F_25 ( V_21 , V_109 -> V_28 ) ;
}
F_57 ( & V_6 -> V_121 ) ;
return 0 ;
}
static int F_62 ( struct V_2 * V_3 , T_4 * V_107 , T_5 V_15 ,
T_6 * V_108 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( V_6 == NULL )
return - V_85 ;
#if 0
u32 *ns_pulse = (u32 *) buf;
unsigned int n;
u32 fifo_pulse[FIFO_TX_DEPTH];
u32 mark;
n = CX25840_IR_TX_KFIFO_SIZE - kfifo_len(ir_state->tx_kfifo);
n = min(n, (unsigned int) count);
n /= sizeof(u32);
for (i = 0; i < n; ) {
for (j = 0; j < FIFO_TX_DEPTH / 2 && i < n; j++) {
mark = ns_pulse[i] & LEVEL_MASK;
fifo_pulse[j] = ns_to_pulse_width_count(
ns_pulse[i] &
~LEVEL_MASK,
ir_state->txclk_divider);
if (mark)
fifo_pulse[j] &= FIFO_RXTX_LVL;
i++;
}
kfifo_put(ir_state->tx_kfifo, (u8 *) fifo_pulse,
j * sizeof(u32));
}
*num = n * sizeof(u32);
#else
F_41 ( V_3 , V_62 ) ;
* V_108 = V_15 ;
#endif
return 0 ;
}
static int F_63 ( struct V_2 * V_3 ,
struct V_120 * V_109 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( V_6 == NULL )
return - V_85 ;
F_56 ( & V_6 -> V_140 ) ;
memcpy ( V_109 , & V_6 -> V_141 ,
sizeof( struct V_120 ) ) ;
F_57 ( & V_6 -> V_140 ) ;
return 0 ;
}
static int F_64 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_20 * V_21 ;
if ( V_6 == NULL )
return - V_85 ;
V_21 = V_6 -> V_21 ;
F_56 ( & V_6 -> V_140 ) ;
F_41 ( V_3 , 0 ) ;
F_24 ( V_21 , false ) ;
F_26 ( V_21 , false ) ;
F_32 ( V_21 , V_48 , V_142 ) ;
V_6 -> V_141 . V_124 = true ;
F_57 ( & V_6 -> V_140 ) ;
return 0 ;
}
static int F_65 ( struct V_2 * V_3 ,
struct V_120 * V_109 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_20 * V_21 ;
struct V_120 * V_125 ;
T_1 V_143 ;
if ( V_6 == NULL )
return - V_85 ;
if ( V_109 -> V_124 )
return F_64 ( V_3 ) ;
if ( V_109 -> V_126 != V_127 )
return - V_128 ;
V_21 = V_6 -> V_21 ;
V_125 = & V_6 -> V_141 ;
F_56 ( & V_6 -> V_140 ) ;
V_125 -> V_124 = V_109 -> V_124 ;
V_109 -> V_126 = V_127 ;
V_125 -> V_126 = V_109 -> V_126 ;
V_109 -> V_129 = sizeof( union V_66 ) ;
V_125 -> V_129 = V_109 -> V_129 ;
F_41 ( V_3 , 0 ) ;
F_24 ( V_21 , false ) ;
F_26 ( V_21 , V_109 -> V_130 ) ;
V_125 -> V_130 = V_109 -> V_130 ;
if ( V_109 -> V_130 ) {
V_109 -> V_131 = F_31 ( V_21 , V_109 -> V_131 ,
& V_143 ) ;
V_125 -> V_131 = V_109 -> V_131 ;
V_109 -> V_52 = F_36 ( V_21 , V_109 -> V_52 ) ;
V_125 -> V_52 = V_109 -> V_52 ;
V_109 -> V_134 =
( T_2 ) F_16 ( V_19 , V_143 ) ;
} else {
V_109 -> V_134 =
F_34 ( V_21 , V_109 -> V_134 ,
& V_143 ) ;
}
V_125 -> V_134 = V_109 -> V_134 ;
F_60 ( & V_6 -> V_143 , V_143 ) ;
V_109 -> V_136 = F_15 ( V_143 ) ;
V_125 -> V_136 = V_109 -> V_136 ;
F_21 ( V_21 , V_144 ) ;
F_30 ( V_21 , V_109 -> V_145 ) ;
V_125 -> V_145 = V_109 -> V_145 ;
V_125 -> V_138 = V_109 -> V_138 ;
V_125 -> V_139 = V_109 -> V_139 ;
V_125 -> V_28 = V_109 -> V_28 ;
if ( V_109 -> V_28 ) {
if ( V_109 -> V_139 )
F_41 ( V_3 , V_62 ) ;
F_24 ( V_21 , V_109 -> V_28 ) ;
}
F_57 ( & V_6 -> V_140 ) ;
return 0 ;
}
int F_66 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_20 * V_21 = V_5 -> V_21 ;
char * V_146 ;
int V_69 , V_70 ;
T_2 V_82 , V_147 , V_148 , V_149 , V_84 , V_83 , V_150 ;
if ( F_67 ( V_5 ) )
return 0 ;
V_82 = F_43 ( V_21 , V_24 ) ;
V_147 = F_43 ( V_21 , V_48 ) & V_142 ;
V_148 = F_43 ( V_21 , V_49 ) & V_8 ;
V_149 = F_43 ( V_21 , V_53 ) & V_151 ;
V_84 = F_43 ( V_21 , V_86 ) ;
V_83 = F_43 ( V_21 , V_61 ) ;
if ( F_39 ( V_5 ) || F_40 ( V_5 ) )
V_83 ^= V_57 ;
V_150 = F_43 ( V_21 , V_55 ) & V_14 ;
F_68 ( V_3 , L_22 ) ;
F_68 ( V_3 , L_23 ,
V_82 & V_31 ? L_24 : L_25 ) ;
F_68 ( V_3 , L_26 ,
V_82 & V_34 ? L_27 : L_28 ) ;
F_68 ( V_3 , L_29 ,
V_82 & V_32 ? L_27 : L_28 ) ;
switch ( V_82 & V_152 ) {
case V_123 :
V_146 = L_28 ;
break;
case V_153 :
V_146 = L_30 ;
break;
case V_154 :
V_146 = L_31 ;
break;
case V_36 :
V_146 = L_32 ;
break;
default:
V_146 = L_33 ;
break;
}
F_68 ( V_3 , L_34 , V_146 ) ;
F_68 ( V_3 , L_35 ,
V_82 & V_155 ? L_36 : L_37 ) ;
F_68 ( V_3 , L_38 ,
V_82 & V_27 ? L_39 : L_40 ) ;
F_68 ( V_3 , L_41 ,
V_82 & V_156 ? L_42 : L_43 ) ;
if ( V_82 & V_34 ) {
F_68 ( V_3 , L_44 ,
F_8 ( V_148 ) ) ;
switch ( V_82 & V_45 ) {
case V_43 :
V_69 = 3 ;
V_70 = 3 ;
break;
case V_44 :
V_69 = 4 ;
V_70 = 3 ;
break;
case V_42 :
V_69 = 3 ;
V_70 = 4 ;
break;
case V_157 :
V_69 = 4 ;
V_70 = 4 ;
break;
default:
V_69 = 0 ;
V_70 = 0 ;
break;
}
F_68 ( V_3 , L_45 ,
V_69 , V_70 ,
F_10 ( V_148 , 16 + V_70 ) ,
F_10 ( V_148 , 16 - V_69 ) ) ;
}
F_68 ( V_3 , L_46 ,
F_18 ( V_19 , V_148 ) ,
F_16 ( V_19 , V_148 ) ) ;
F_68 ( V_3 , L_47 ,
V_150 ? L_27 : L_28 ) ;
if ( V_150 )
F_68 ( V_3 , L_48 ,
F_14 ( V_150 ) ,
F_13 ( V_150 ) ) ;
F_68 ( V_3 , L_49 ,
V_84 & V_89 ? L_24 : L_25 ) ;
F_68 ( V_3 , L_50 ,
V_83 & V_58 ? L_27 : L_28 ) ;
F_68 ( V_3 , L_51 ,
V_84 & V_90 ? L_24 : L_25 ) ;
F_68 ( V_3 , L_52 ,
V_83 & V_59 ? L_27 : L_28 ) ;
F_68 ( V_3 , L_53 ,
V_84 & V_93 ? L_24 : L_25 ) ;
F_68 ( V_3 , L_54 ,
V_84 & V_88 ? L_24 : L_25 ) ;
F_68 ( V_3 , L_55 ,
V_83 & V_60 ? L_27 : L_28 ) ;
F_68 ( V_3 , L_56 ) ;
F_68 ( V_3 , L_23 ,
V_82 & V_29 ? L_24 : L_25 ) ;
F_68 ( V_3 , L_57 ,
V_82 & V_33 ? L_27 : L_28 ) ;
F_68 ( V_3 , L_29 ,
V_82 & V_30 ? L_27 : L_28 ) ;
F_68 ( V_3 , L_38 ,
V_82 & V_25 ? L_39 : L_58 ) ;
F_68 ( V_3 , L_59 ,
V_82 & V_47 ? L_60
: L_61 ) ;
if ( V_82 & V_33 ) {
F_68 ( V_3 , L_62 ,
F_8 ( V_147 ) ) ;
F_68 ( V_3 , L_63 ,
V_149 + 1 ) ;
}
F_68 ( V_3 , L_64 ,
F_18 ( V_19 , V_147 ) ,
F_16 ( V_19 , V_147 ) ) ;
F_68 ( V_3 , L_53 ,
V_84 & V_92 ? L_24 : L_25 ) ;
F_68 ( V_3 , L_54 ,
V_84 & V_87 ? L_24 : L_25 ) ;
F_68 ( V_3 , L_55 ,
V_83 & V_62 ? L_27 : L_28 ) ;
return 0 ;
}
int F_69 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 ;
struct V_120 V_158 ;
if ( ! ( F_39 ( V_5 ) || F_40 ( V_5 ) ) )
return 0 ;
V_6 = F_70 ( & V_5 -> V_21 -> V_159 , sizeof( * V_6 ) , V_160 ) ;
if ( V_6 == NULL )
return - V_161 ;
F_71 ( & V_6 -> V_100 ) ;
if ( F_72 ( & V_6 -> V_99 ,
V_104 , V_160 ) )
return - V_161 ;
V_6 -> V_21 = V_5 -> V_21 ;
V_5 -> V_6 = V_6 ;
if ( F_39 ( V_5 ) || F_40 ( V_5 ) )
F_32 ( V_6 -> V_21 , V_61 , V_57 ) ;
else
F_32 ( V_6 -> V_21 , V_61 , 0 ) ;
F_73 ( & V_6 -> V_121 ) ;
V_158 = V_162 ;
F_74 ( V_3 , V_163 , V_164 , & V_158 ) ;
F_73 ( & V_6 -> V_140 ) ;
V_158 = V_165 ;
F_74 ( V_3 , V_163 , V_166 , & V_158 ) ;
return 0 ;
}
int F_75 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( V_6 == NULL )
return - V_85 ;
F_58 ( V_3 ) ;
F_64 ( V_3 ) ;
F_76 ( & V_6 -> V_99 ) ;
V_5 -> V_6 = NULL ;
return 0 ;
}

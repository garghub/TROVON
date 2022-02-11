static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
if ( F_2 ( V_5 -> V_7 || ! V_2 -> V_8 ) )
return 0 ;
V_6 = F_3 ( V_2 , V_3 ) ;
if ( V_6 == 0 )
return 0 ;
if ( V_2 -> V_9 ) {
F_4 ( V_2 , V_2 -> V_9 ,
V_2 -> V_10 ) ;
V_2 -> V_9 = NULL ;
}
F_5 ( V_2 ) ;
F_6 ( F_7 ( V_2 ) ) ;
return V_6 ;
}
static inline void F_8 ( struct V_1 * V_2 )
{
V_2 -> V_11 = false ;
F_9 () ;
F_10 ( V_2 ) ;
}
static int F_11 ( struct V_12 * V_13 , int V_3 )
{
struct V_1 * V_2 =
F_12 ( V_13 , struct V_1 , V_14 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
F_13 ( V_5 , V_15 , V_5 -> V_16 ,
L_1 ,
V_2 -> V_2 , F_14 () ) ;
V_6 = F_1 ( V_2 , V_3 ) ;
if ( V_6 < V_3 ) {
if ( V_2 -> V_2 < V_5 -> V_17 &&
V_5 -> V_18 &&
F_2 ( ++ V_2 -> V_19 == 1000 ) ) {
if ( F_2 ( V_2 -> V_20 <
V_21 ) ) {
if ( V_2 -> V_22 > 1 ) {
V_2 -> V_22 -= 1 ;
V_5 -> type -> V_23 ( V_2 ) ;
}
} else if ( F_2 ( V_2 -> V_20 >
V_24 ) ) {
if ( V_2 -> V_22 <
V_5 -> V_25 ) {
V_2 -> V_22 += 1 ;
V_5 -> type -> V_23 ( V_2 ) ;
}
}
V_2 -> V_19 = 0 ;
V_2 -> V_20 = 0 ;
}
F_15 ( V_2 ) ;
F_16 ( V_13 ) ;
F_8 ( V_2 ) ;
}
return V_6 ;
}
void F_17 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
F_18 ( V_2 -> V_2 >= V_5 -> V_26 ) ;
F_18 ( ! V_2 -> V_8 ) ;
F_18 ( ! V_5 -> V_27 ) ;
F_19 ( V_5 ) ;
if ( V_5 -> V_28 ) {
F_20 ( V_5 -> V_28 ) ;
V_5 -> V_29 = false ;
}
if ( V_2 -> V_30 )
F_20 ( V_2 -> V_30 ) ;
F_21 ( & V_2 -> V_14 ) ;
F_1 ( V_2 , V_2 -> V_31 + 1 ) ;
F_8 ( V_2 ) ;
F_22 ( & V_2 -> V_14 ) ;
if ( V_5 -> V_28 )
V_5 -> V_29 = true ;
F_23 ( V_5 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned long V_32 ;
F_25 ( V_2 -> V_5 , V_33 , V_2 -> V_5 -> V_16 ,
L_2 , V_2 -> V_2 ) ;
V_32 = F_26 ( V_5 -> V_34 + V_5 -> V_35 + 128 ) ;
F_27 ( V_32 > V_36 ) ;
V_2 -> V_31 = F_28 ( V_32 , V_37 ) - 1 ;
return F_29 ( V_2 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_25 ( V_2 -> V_5 , V_38 , V_2 -> V_5 -> V_16 ,
L_3 , V_2 -> V_2 ) ;
V_2 -> V_39 = 0 ;
F_31 ( V_2 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_25 ( V_2 -> V_5 , V_38 , V_2 -> V_5 -> V_16 ,
L_4 , V_2 -> V_2 ) ;
F_33 ( V_2 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_25 ( V_2 -> V_5 , V_38 , V_2 -> V_5 -> V_16 ,
L_5 , V_2 -> V_2 ) ;
F_35 ( V_2 ) ;
}
static struct V_1 *
F_36 ( struct V_4 * V_5 , int V_40 , struct V_1 * V_41 )
{
struct V_1 * V_2 ;
struct V_42 * V_43 ;
struct V_44 * V_45 ;
int V_46 ;
if ( V_41 ) {
V_2 = F_37 ( sizeof( * V_2 ) , V_47 ) ;
if ( ! V_2 )
return NULL ;
* V_2 = * V_41 ;
V_2 -> V_48 = NULL ;
memset ( & V_2 -> V_49 , 0 , sizeof( V_2 -> V_49 ) ) ;
V_43 = & V_2 -> V_43 ;
V_43 -> V_50 = NULL ;
memset ( & V_43 -> V_51 , 0 , sizeof( V_43 -> V_51 ) ) ;
for ( V_46 = 0 ; V_46 < V_52 ; V_46 ++ ) {
V_45 = & V_2 -> V_45 [ V_46 ] ;
if ( V_45 -> V_2 )
V_45 -> V_2 = V_2 ;
V_45 -> V_50 = NULL ;
memset ( & V_45 -> V_53 , 0 , sizeof( V_45 -> V_53 ) ) ;
}
} else {
V_2 = F_38 ( sizeof( * V_2 ) , V_47 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_5 = V_5 ;
V_2 -> V_2 = V_40 ;
for ( V_46 = 0 ; V_46 < V_52 ; V_46 ++ ) {
V_45 = & V_2 -> V_45 [ V_46 ] ;
V_45 -> V_5 = V_5 ;
V_45 -> V_54 = V_40 * V_52 + V_46 ;
V_45 -> V_2 = V_2 ;
}
}
V_43 = & V_2 -> V_43 ;
V_43 -> V_5 = V_5 ;
F_39 ( & V_43 -> V_55 , V_56 ,
( unsigned long ) V_43 ) ;
return V_2 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_44 * V_45 ;
struct V_42 * V_43 ;
int V_57 ;
F_25 ( V_2 -> V_5 , V_33 , V_2 -> V_5 -> V_16 ,
L_6 , V_2 -> V_2 ) ;
V_57 = F_24 ( V_2 ) ;
if ( V_57 )
goto V_58;
F_41 (tx_queue, channel) {
V_57 = F_42 ( V_45 ) ;
if ( V_57 )
goto V_59;
}
F_43 (rx_queue, channel) {
V_57 = F_44 ( V_43 ) ;
if ( V_57 )
goto V_60;
}
V_2 -> V_61 = 0 ;
return 0 ;
V_60:
F_43 (rx_queue, channel)
F_45 ( V_43 ) ;
V_59:
F_41 (tx_queue, channel)
F_46 ( V_45 ) ;
V_58:
return V_57 ;
}
static void F_47 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
const char * type = L_7 ;
int V_62 ;
F_48 (channel, efx) {
V_62 = V_2 -> V_2 ;
if ( V_5 -> V_26 > V_5 -> V_17 ) {
if ( V_2 -> V_2 < V_5 -> V_17 ) {
type = L_8 ;
} else {
type = L_9 ;
V_62 -= V_5 -> V_17 ;
}
}
snprintf ( V_5 -> V_63 [ V_2 -> V_2 ] ,
sizeof( V_5 -> V_63 [ 0 ] ) ,
L_10 , V_5 -> V_64 , type , V_62 ) ;
}
}
static int F_49 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
int V_57 ;
V_5 -> V_65 = 0 ;
F_48 (channel, efx) {
V_57 = F_40 ( V_2 ) ;
if ( V_57 ) {
F_50 ( V_5 , V_33 , V_5 -> V_16 ,
L_11 ,
V_2 -> V_2 ) ;
goto V_66;
}
}
F_47 ( V_5 ) ;
return 0 ;
V_66:
F_51 ( V_5 ) ;
return V_57 ;
}
static void F_52 ( struct V_4 * V_5 )
{
struct V_44 * V_45 ;
struct V_42 * V_43 ;
struct V_1 * V_2 ;
V_5 -> V_67 = ( F_28 ( V_68 , V_69 ) +
F_53 ( V_5 -> V_16 -> V_70 ) +
V_5 -> type -> V_71 +
V_5 -> type -> V_72 ) ;
V_5 -> V_73 = F_54 ( V_5 -> V_67 +
sizeof( struct V_74 ) ) ;
F_48 (channel, efx) {
F_25 ( V_2 -> V_5 , V_38 , V_2 -> V_5 -> V_16 ,
L_12 , V_2 -> V_2 ) ;
F_30 ( V_2 ) ;
F_41 (tx_queue, channel)
F_55 ( V_45 ) ;
F_5 ( V_2 ) ;
F_43 (rx_queue, channel)
F_56 ( V_43 ) ;
F_57 ( V_2 -> V_9 != NULL ) ;
F_5 ( V_2 ) ;
}
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_42 * V_43 ;
F_25 ( V_2 -> V_5 , V_75 , V_2 -> V_5 -> V_16 ,
L_13 , V_2 -> V_2 ) ;
V_2 -> V_11 = false ;
V_2 -> V_8 = true ;
F_9 () ;
F_43 (rx_queue, channel)
F_6 ( V_43 ) ;
F_22 ( & V_2 -> V_14 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_8 )
return;
F_25 ( V_2 -> V_5 , V_76 , V_2 -> V_5 -> V_16 ,
L_14 , V_2 -> V_2 ) ;
V_2 -> V_8 = false ;
F_21 ( & V_2 -> V_14 ) ;
}
static void F_60 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_44 * V_45 ;
struct V_42 * V_43 ;
int V_57 ;
F_61 ( V_5 ) ;
F_18 ( V_5 -> V_77 ) ;
V_57 = F_62 ( V_5 ) ;
if ( V_57 && F_63 ( V_5 ) ) {
F_50 ( V_5 , V_38 , V_5 -> V_16 ,
L_15 ) ;
F_64 ( V_5 , V_78 ) ;
} else if ( V_57 ) {
F_50 ( V_5 , V_38 , V_5 -> V_16 , L_16 ) ;
} else {
F_25 ( V_5 , V_38 , V_5 -> V_16 ,
L_17 ) ;
}
F_48 (channel, efx) {
F_25 ( V_2 -> V_5 , V_38 , V_2 -> V_5 -> V_16 ,
L_18 , V_2 -> V_2 ) ;
F_43 (rx_queue, channel)
F_65 ( V_43 ) ;
F_66 (tx_queue, channel)
F_67 ( V_45 ) ;
F_32 ( V_2 ) ;
}
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_44 * V_45 ;
struct V_42 * V_43 ;
F_25 ( V_2 -> V_5 , V_38 , V_2 -> V_5 -> V_16 ,
L_19 , V_2 -> V_2 ) ;
F_43 (rx_queue, channel)
F_45 ( V_43 ) ;
F_66 (tx_queue, channel)
F_46 ( V_45 ) ;
F_34 ( V_2 ) ;
}
static void F_51 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
F_48 (channel, efx)
F_68 ( V_2 ) ;
}
int
F_69 ( struct V_4 * V_5 , T_1 V_34 , T_1 V_35 )
{
struct V_1 * V_79 [ V_80 ] , * V_2 ;
T_1 V_81 , V_82 ;
unsigned V_40 ;
int V_57 ;
F_70 ( V_5 ) ;
F_60 ( V_5 ) ;
memset ( V_79 , 0 , sizeof( V_79 ) ) ;
for ( V_40 = 0 ; V_40 < V_5 -> V_26 ; V_40 ++ ) {
V_2 = F_36 ( V_5 , V_40 , V_5 -> V_2 [ V_40 ] ) ;
if ( ! V_2 ) {
V_57 = - V_83 ;
goto V_84;
}
V_79 [ V_40 ] = V_2 ;
}
V_81 = V_5 -> V_34 ;
V_82 = V_5 -> V_35 ;
V_5 -> V_34 = V_34 ;
V_5 -> V_35 = V_35 ;
for ( V_40 = 0 ; V_40 < V_5 -> V_26 ; V_40 ++ ) {
V_2 = V_5 -> V_2 [ V_40 ] ;
V_5 -> V_2 [ V_40 ] = V_79 [ V_40 ] ;
V_79 [ V_40 ] = V_2 ;
}
V_57 = F_49 ( V_5 ) ;
if ( V_57 )
goto V_85;
F_71 ( V_5 ) ;
for ( V_40 = 0 ; V_40 < V_5 -> V_26 ; V_40 ++ ) {
F_72 ( V_79 [ V_40 ] ) ;
F_68 ( V_79 [ V_40 ] ) ;
}
V_84:
for ( V_40 = 0 ; V_40 < V_5 -> V_26 ; V_40 ++ )
F_73 ( V_79 [ V_40 ] ) ;
F_52 ( V_5 ) ;
F_74 ( V_5 ) ;
return V_57 ;
V_85:
V_5 -> V_34 = V_81 ;
V_5 -> V_35 = V_82 ;
for ( V_40 = 0 ; V_40 < V_5 -> V_26 ; V_40 ++ ) {
V_2 = V_5 -> V_2 [ V_40 ] ;
V_5 -> V_2 [ V_40 ] = V_79 [ V_40 ] ;
V_79 [ V_40 ] = V_2 ;
}
goto V_84;
}
void F_75 ( struct V_42 * V_43 )
{
F_76 ( & V_43 -> V_55 , V_86 + F_77 ( 100 ) ) ;
}
void F_78 ( struct V_4 * V_5 )
{
struct V_87 * V_88 = & V_5 -> V_88 ;
if ( ! F_79 ( V_5 -> V_16 ) )
return;
if ( V_88 -> V_89 != F_80 ( V_5 -> V_16 ) ) {
V_5 -> V_90 ++ ;
if ( V_88 -> V_89 )
F_81 ( V_5 -> V_16 ) ;
else
F_82 ( V_5 -> V_16 ) ;
}
if ( V_88 -> V_89 ) {
F_83 ( V_5 , V_91 , V_5 -> V_16 ,
L_20 ,
V_88 -> V_92 , V_88 -> V_93 ? L_21 : L_22 ,
V_5 -> V_16 -> V_70 ,
( V_5 -> V_94 ? L_23 : L_7 ) ) ;
} else {
F_83 ( V_5 , V_91 , V_5 -> V_16 , L_24 ) ;
}
}
void F_84 ( struct V_4 * V_5 , T_1 V_95 )
{
V_5 -> V_96 = V_95 ;
if ( V_95 ) {
if ( V_95 & V_97 )
V_5 -> V_98 |= ( V_99 | V_100 ) ;
else
V_5 -> V_98 &= ~ ( V_99 | V_100 ) ;
if ( V_95 & V_101 )
V_5 -> V_98 ^= V_99 ;
}
}
void F_85 ( struct V_4 * V_5 , T_2 V_98 )
{
V_5 -> V_98 = V_98 ;
if ( V_5 -> V_96 ) {
if ( V_98 & V_100 )
V_5 -> V_96 |= ( V_97 |
V_101 ) ;
else
V_5 -> V_96 &= ~ ( V_97 |
V_101 ) ;
if ( V_98 & V_99 )
V_5 -> V_96 ^= V_101 ;
}
}
int F_86 ( struct V_4 * V_5 )
{
enum V_102 V_103 ;
int V_57 ;
F_57 ( ! F_87 ( & V_5 -> V_104 ) ) ;
if ( F_88 ( V_5 ) ) {
F_89 ( V_5 -> V_16 ) ;
F_90 ( V_5 -> V_16 ) ;
}
V_103 = V_5 -> V_103 ;
if ( F_91 ( V_5 ) )
V_5 -> V_103 |= V_105 ;
else
V_5 -> V_103 &= ~ V_105 ;
V_57 = V_5 -> type -> V_106 ( V_5 ) ;
if ( V_57 )
V_5 -> V_103 = V_103 ;
return V_57 ;
}
int F_92 ( struct V_4 * V_5 )
{
int V_57 ;
F_61 ( V_5 ) ;
F_93 ( & V_5 -> V_104 ) ;
V_57 = F_86 ( V_5 ) ;
F_94 ( & V_5 -> V_104 ) ;
return V_57 ;
}
static void F_95 ( struct V_107 * V_108 )
{
struct V_4 * V_5 = F_12 ( V_108 , struct V_4 , V_109 ) ;
F_93 ( & V_5 -> V_104 ) ;
if ( V_5 -> V_77 ) {
V_5 -> type -> V_110 ( V_5 ) ;
V_5 -> V_111 -> V_112 ( V_5 ) ;
}
F_94 ( & V_5 -> V_104 ) ;
}
static int F_96 ( struct V_4 * V_5 )
{
unsigned char * V_113 ;
int V_57 ;
F_25 ( V_5 , V_33 , V_5 -> V_16 , L_25 ) ;
if ( V_114 )
V_5 -> V_103 = V_115 ;
V_57 = V_5 -> type -> V_116 ( V_5 ) ;
if ( V_57 )
return V_57 ;
V_113 = V_5 -> V_16 -> V_113 ;
if ( F_97 ( V_113 ) ) {
memcpy ( V_5 -> V_16 -> V_117 , V_113 , V_118 ) ;
} else {
F_50 ( V_5 , V_33 , V_5 -> V_16 , L_26 ,
V_113 ) ;
if ( ! V_119 ) {
V_57 = - V_120 ;
goto V_121;
}
F_98 ( V_5 -> V_16 -> V_117 ) ;
F_83 ( V_5 , V_33 , V_5 -> V_16 ,
L_27 ,
V_5 -> V_16 -> V_117 ) ;
}
return 0 ;
V_121:
V_5 -> type -> V_122 ( V_5 ) ;
return V_57 ;
}
static int F_99 ( struct V_4 * V_5 )
{
int V_57 ;
F_25 ( V_5 , V_38 , V_5 -> V_16 , L_28 ) ;
F_93 ( & V_5 -> V_104 ) ;
V_57 = V_5 -> V_123 -> V_124 ( V_5 ) ;
if ( V_57 )
goto V_58;
V_5 -> V_125 = true ;
V_5 -> V_111 -> V_112 ( V_5 ) ;
V_57 = V_5 -> V_123 -> V_112 ( V_5 ) ;
if ( V_57 )
goto V_59;
F_94 ( & V_5 -> V_104 ) ;
return 0 ;
V_59:
V_5 -> V_123 -> V_126 ( V_5 ) ;
V_58:
F_94 ( & V_5 -> V_104 ) ;
return V_57 ;
}
static void F_100 ( struct V_4 * V_5 )
{
F_25 ( V_5 , V_75 , V_5 -> V_16 , L_29 ) ;
F_18 ( V_5 -> V_77 ) ;
F_93 ( & V_5 -> V_104 ) ;
V_5 -> V_77 = true ;
V_5 -> type -> V_110 ( V_5 ) ;
V_5 -> V_111 -> V_112 ( V_5 ) ;
F_94 ( & V_5 -> V_104 ) ;
}
static void F_101 ( struct V_4 * V_5 )
{
F_25 ( V_5 , V_76 , V_5 -> V_16 , L_30 ) ;
F_93 ( & V_5 -> V_104 ) ;
V_5 -> V_77 = false ;
F_94 ( & V_5 -> V_104 ) ;
if ( F_88 ( V_5 ) ) {
F_89 ( V_5 -> V_16 ) ;
F_90 ( V_5 -> V_16 ) ;
}
}
static void F_102 ( struct V_4 * V_5 )
{
F_25 ( V_5 , V_38 , V_5 -> V_16 , L_31 ) ;
if ( ! V_5 -> V_125 )
return;
V_5 -> V_123 -> V_126 ( V_5 ) ;
V_5 -> V_125 = false ;
V_5 -> V_88 . V_89 = false ;
F_78 ( V_5 ) ;
}
static void F_103 ( struct V_4 * V_5 )
{
F_25 ( V_5 , V_38 , V_5 -> V_16 , L_32 ) ;
V_5 -> type -> V_122 ( V_5 ) ;
}
static int F_104 ( struct V_4 * V_5 )
{
struct V_127 * V_127 = V_5 -> V_127 ;
T_3 V_128 = V_5 -> type -> V_129 ;
int V_57 ;
F_25 ( V_5 , V_33 , V_5 -> V_16 , L_33 ) ;
V_57 = F_105 ( V_127 ) ;
if ( V_57 ) {
F_50 ( V_5 , V_33 , V_5 -> V_16 ,
L_34 ) ;
goto V_58;
}
F_106 ( V_127 ) ;
while ( V_128 > 0x7fffffffUL ) {
if ( F_107 ( V_127 , V_128 ) &&
( ( V_57 = F_108 ( V_127 , V_128 ) ) == 0 ) )
break;
V_128 >>= 1 ;
}
if ( V_57 ) {
F_50 ( V_5 , V_33 , V_5 -> V_16 ,
L_35 ) ;
goto V_59;
}
F_25 ( V_5 , V_33 , V_5 -> V_16 ,
L_36 , ( unsigned long long ) V_128 ) ;
V_57 = F_109 ( V_127 , V_128 ) ;
if ( V_57 ) {
F_50 ( V_5 , V_33 , V_5 -> V_16 ,
L_37 ) ;
goto V_59;
}
V_5 -> V_130 = F_110 ( V_5 -> V_127 , V_131 ) ;
V_57 = F_111 ( V_127 , V_131 , L_38 ) ;
if ( V_57 ) {
F_50 ( V_5 , V_33 , V_5 -> V_16 ,
L_39 ) ;
V_57 = - V_132 ;
goto V_60;
}
V_5 -> V_133 = F_112 ( V_5 -> V_130 ,
V_5 -> type -> V_134 ) ;
if ( ! V_5 -> V_133 ) {
F_50 ( V_5 , V_33 , V_5 -> V_16 ,
L_40 ,
( unsigned long long ) V_5 -> V_130 ,
V_5 -> type -> V_134 ) ;
V_57 = - V_83 ;
goto V_135;
}
F_25 ( V_5 , V_33 , V_5 -> V_16 ,
L_41 ,
( unsigned long long ) V_5 -> V_130 ,
V_5 -> type -> V_134 , V_5 -> V_133 ) ;
return 0 ;
V_135:
F_113 ( V_5 -> V_127 , V_131 ) ;
V_60:
V_5 -> V_130 = 0 ;
V_59:
F_114 ( V_5 -> V_127 ) ;
V_58:
return V_57 ;
}
static void F_115 ( struct V_4 * V_5 )
{
F_25 ( V_5 , V_38 , V_5 -> V_16 , L_42 ) ;
if ( V_5 -> V_133 ) {
F_116 ( V_5 -> V_133 ) ;
V_5 -> V_133 = NULL ;
}
if ( V_5 -> V_130 ) {
F_113 ( V_5 -> V_127 , V_131 ) ;
V_5 -> V_130 = 0 ;
}
F_114 ( V_5 -> V_127 ) ;
}
static int F_117 ( void )
{
T_4 V_136 ;
int V_137 ;
int V_138 ;
if ( V_139 )
return V_139 ;
if ( F_2 ( ! F_118 ( & V_136 , V_47 ) ) ) {
F_119 ( V_140
L_43 ) ;
return 1 ;
}
V_137 = 0 ;
F_120 (cpu) {
if ( ! F_121 ( V_138 , V_136 ) ) {
++ V_137 ;
F_122 ( V_136 , V_136 ,
F_123 ( V_138 ) ) ;
}
}
F_124 ( V_136 ) ;
return V_137 ;
}
static int
F_125 ( struct V_4 * V_5 , struct V_141 * V_142 )
{
#ifdef F_126
int V_40 , V_57 ;
V_5 -> V_16 -> V_143 = F_127 ( V_5 -> V_17 ) ;
if ( ! V_5 -> V_16 -> V_143 )
return - V_83 ;
for ( V_40 = 0 ; V_40 < V_5 -> V_17 ; V_40 ++ ) {
V_57 = F_128 ( V_5 -> V_16 -> V_143 ,
V_142 [ V_40 ] . V_144 ) ;
if ( V_57 ) {
F_129 ( V_5 -> V_16 -> V_143 ) ;
V_5 -> V_16 -> V_143 = NULL ;
return V_57 ;
}
}
#endif
return 0 ;
}
static int F_130 ( struct V_4 * V_5 )
{
int V_145 =
F_131 ( int , V_5 -> type -> V_146 , V_80 ) ;
int V_57 , V_40 ;
if ( V_5 -> V_147 == V_148 ) {
struct V_141 V_142 [ V_80 ] ;
int V_26 ;
V_26 = F_117 () ;
if ( V_149 )
V_26 *= 2 ;
V_26 = F_132 ( V_26 , V_145 ) ;
for ( V_40 = 0 ; V_40 < V_26 ; V_40 ++ )
V_142 [ V_40 ] . V_150 = V_40 ;
V_57 = F_133 ( V_5 -> V_127 , V_142 , V_26 ) ;
if ( V_57 > 0 ) {
F_50 ( V_5 , V_38 , V_5 -> V_16 ,
L_44
L_45 , V_57 , V_26 ) ;
F_50 ( V_5 , V_38 , V_5 -> V_16 ,
L_46 ) ;
F_27 ( V_57 >= V_26 ) ;
V_26 = V_57 ;
V_57 = F_133 ( V_5 -> V_127 , V_142 ,
V_26 ) ;
}
if ( V_57 == 0 ) {
V_5 -> V_26 = V_26 ;
if ( V_149 ) {
V_5 -> V_151 =
F_28 ( V_5 -> V_26 / 2 , 1U ) ;
V_5 -> V_17 =
F_28 ( V_5 -> V_26 -
V_5 -> V_151 , 1U ) ;
} else {
V_5 -> V_151 = V_5 -> V_26 ;
V_5 -> V_17 = V_5 -> V_26 ;
}
V_57 = F_125 ( V_5 , V_142 ) ;
if ( V_57 ) {
F_134 ( V_5 -> V_127 ) ;
return V_57 ;
}
for ( V_40 = 0 ; V_40 < V_26 ; V_40 ++ )
F_135 ( V_5 , V_40 ) -> V_30 =
V_142 [ V_40 ] . V_144 ;
} else {
V_5 -> V_147 = V_152 ;
F_50 ( V_5 , V_38 , V_5 -> V_16 ,
L_47 ) ;
}
}
if ( V_5 -> V_147 == V_152 ) {
V_5 -> V_26 = 1 ;
V_5 -> V_17 = 1 ;
V_5 -> V_151 = 1 ;
V_57 = F_136 ( V_5 -> V_127 ) ;
if ( V_57 == 0 ) {
F_135 ( V_5 , 0 ) -> V_30 = V_5 -> V_127 -> V_30 ;
} else {
F_50 ( V_5 , V_38 , V_5 -> V_16 ,
L_48 ) ;
V_5 -> V_147 = V_153 ;
}
}
if ( V_5 -> V_147 == V_153 ) {
V_5 -> V_26 = 1 + ( V_149 ? 1 : 0 ) ;
V_5 -> V_17 = 1 ;
V_5 -> V_151 = 1 ;
V_5 -> V_28 = V_5 -> V_127 -> V_30 ;
}
return 0 ;
}
static void F_137 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
F_48 (channel, efx)
V_2 -> V_30 = 0 ;
F_138 ( V_5 -> V_127 ) ;
F_134 ( V_5 -> V_127 ) ;
V_5 -> V_28 = 0 ;
}
static void F_139 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_44 * V_45 ;
V_5 -> V_154 =
V_149 ? V_5 -> V_26 - V_5 -> V_151 : 0 ;
F_48 (channel, efx) {
F_41 (tx_queue, channel)
V_45 -> V_54 -= ( V_5 -> V_154 *
V_52 ) ;
}
}
static int F_140 ( struct V_4 * V_5 )
{
T_5 V_40 ;
int V_57 ;
F_25 ( V_5 , V_33 , V_5 -> V_16 , L_49 ) ;
V_57 = V_5 -> type -> V_33 ( V_5 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_130 ( V_5 ) ;
if ( V_57 )
goto V_66;
if ( V_5 -> V_26 > 1 )
F_141 ( & V_5 -> V_155 , sizeof( V_5 -> V_155 ) ) ;
for ( V_40 = 0 ; V_40 < F_142 ( V_5 -> V_156 ) ; V_40 ++ )
V_5 -> V_156 [ V_40 ] = V_40 % V_5 -> V_17 ;
F_139 ( V_5 ) ;
F_143 ( V_5 -> V_16 , V_5 -> V_151 ) ;
F_144 ( V_5 -> V_16 , V_5 -> V_17 ) ;
F_145 ( V_5 , V_157 , V_158 , true ) ;
return 0 ;
V_66:
V_5 -> type -> remove ( V_5 ) ;
return V_57 ;
}
static void F_146 ( struct V_4 * V_5 )
{
F_25 ( V_5 , V_38 , V_5 -> V_16 , L_50 ) ;
F_137 ( V_5 ) ;
V_5 -> type -> remove ( V_5 ) ;
}
static int F_147 ( struct V_4 * V_5 )
{
int V_57 ;
V_57 = F_140 ( V_5 ) ;
if ( V_57 ) {
F_50 ( V_5 , V_33 , V_5 -> V_16 , L_51 ) ;
goto V_58;
}
V_57 = F_96 ( V_5 ) ;
if ( V_57 ) {
F_50 ( V_5 , V_33 , V_5 -> V_16 , L_52 ) ;
goto V_59;
}
V_5 -> V_34 = V_5 -> V_35 = V_159 ;
V_57 = F_49 ( V_5 ) ;
if ( V_57 )
goto V_60;
V_57 = F_148 ( V_5 ) ;
if ( V_57 ) {
F_50 ( V_5 , V_33 , V_5 -> V_16 ,
L_53 ) ;
goto V_135;
}
return 0 ;
V_135:
F_51 ( V_5 ) ;
V_60:
F_103 ( V_5 ) ;
V_59:
F_146 ( V_5 ) ;
V_58:
return V_57 ;
}
static void F_74 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
F_61 ( V_5 ) ;
if ( V_5 -> V_77 )
return;
if ( ( V_5 -> V_160 != V_161 ) && ( V_5 -> V_160 != V_162 ) )
return;
if ( F_88 ( V_5 ) && ! F_79 ( V_5 -> V_16 ) )
return;
F_100 ( V_5 ) ;
if ( F_88 ( V_5 ) && F_149 ( V_5 -> V_16 ) )
F_150 ( V_5 -> V_16 ) ;
F_48 (channel, efx)
F_58 ( V_2 ) ;
if ( V_5 -> V_28 )
V_5 -> V_29 = true ;
F_23 ( V_5 ) ;
F_151 ( V_5 ) ;
if ( V_5 -> V_7 )
F_152 ( V_5 ) ;
if ( V_5 -> type -> V_163 != NULL ) {
F_153 ( V_5 -> V_164 , & V_5 -> V_165 ,
V_166 ) ;
} else {
F_93 ( & V_5 -> V_104 ) ;
if ( V_5 -> V_123 -> V_167 ( V_5 ) )
F_78 ( V_5 ) ;
F_94 ( & V_5 -> V_104 ) ;
}
V_5 -> type -> V_168 ( V_5 ) ;
}
static void F_154 ( struct V_4 * V_5 )
{
F_155 ( & V_5 -> V_165 ) ;
F_156 ( & V_5 -> V_109 ) ;
}
static void F_70 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
F_61 ( V_5 ) ;
if ( ! V_5 -> V_77 )
return;
V_5 -> type -> V_169 ( V_5 ) ;
F_152 ( V_5 ) ;
F_19 ( V_5 ) ;
if ( V_5 -> V_28 ) {
F_20 ( V_5 -> V_28 ) ;
V_5 -> V_29 = false ;
}
F_48 (channel, efx) {
if ( V_2 -> V_30 )
F_20 ( V_2 -> V_30 ) ;
}
F_48 (channel, efx)
F_59 ( V_2 ) ;
F_101 ( V_5 ) ;
F_154 ( V_5 ) ;
if ( F_88 ( V_5 ) ) {
F_157 ( V_5 -> V_16 ) ;
F_158 ( V_5 -> V_16 ) ;
F_159 ( V_5 -> V_16 ) ;
}
}
static void F_160 ( struct V_4 * V_5 )
{
F_161 ( V_5 ) ;
F_51 ( V_5 ) ;
F_103 ( V_5 ) ;
F_146 ( V_5 ) ;
}
static unsigned F_162 ( int V_170 , int V_171 )
{
if ( V_170 <= 0 )
return 0 ;
if ( V_170 < V_171 )
return 1 ;
return V_170 / V_171 ;
}
void F_145 ( struct V_4 * V_5 , int V_172 , int V_173 ,
bool V_174 )
{
struct V_1 * V_2 ;
unsigned V_175 = F_162 ( V_172 , V_176 ) ;
unsigned V_177 = F_162 ( V_173 , V_176 ) ;
F_61 ( V_5 ) ;
V_5 -> V_18 = V_174 ;
V_5 -> V_25 = V_177 ;
F_48 (channel, efx) {
if ( F_163 ( V_2 ) )
V_2 -> V_22 = V_177 ;
else if ( F_164 ( V_2 ) )
V_2 -> V_22 = V_175 ;
}
}
static void F_165 ( struct V_107 * V_108 )
{
struct V_4 * V_5 = F_12 ( V_108 , struct V_4 ,
V_165 . V_178 ) ;
F_13 ( V_5 , V_179 , V_5 -> V_16 ,
L_54 ,
F_14 () ) ;
F_18 ( V_5 -> type -> V_163 == NULL ) ;
if ( F_166 ( & V_5 -> V_104 ) ) {
if ( V_5 -> V_77 )
V_5 -> type -> V_163 ( V_5 ) ;
F_94 ( & V_5 -> V_104 ) ;
}
F_153 ( V_5 -> V_164 , & V_5 -> V_165 ,
V_166 ) ;
}
static int F_167 ( struct V_180 * V_16 , struct V_181 * V_182 , int V_183 )
{
struct V_4 * V_5 = F_168 ( V_16 ) ;
struct V_184 * V_108 = F_169 ( V_182 ) ;
F_61 ( V_5 ) ;
if ( ( V_183 == V_185 || V_183 == V_186 ) &&
( V_108 -> V_187 & 0xfc00 ) == 0x0400 )
V_108 -> V_187 ^= V_188 | 0x0400 ;
return F_170 ( & V_5 -> V_189 , V_108 , V_183 ) ;
}
static void F_71 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
F_48 (channel, efx) {
V_2 -> V_48 = V_5 -> V_16 ;
F_171 ( V_2 -> V_48 , & V_2 -> V_14 ,
F_11 , V_190 ) ;
}
}
static void F_72 ( struct V_1 * V_2 )
{
if ( V_2 -> V_48 )
F_172 ( & V_2 -> V_14 ) ;
V_2 -> V_48 = NULL ;
}
static void F_173 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
F_48 (channel, efx)
F_72 ( V_2 ) ;
}
static void F_174 ( struct V_180 * V_16 )
{
struct V_4 * V_5 = F_168 ( V_16 ) ;
struct V_1 * V_2 ;
F_48 (channel, efx)
F_175 ( V_2 ) ;
}
static int F_176 ( struct V_180 * V_16 )
{
struct V_4 * V_5 = F_168 ( V_16 ) ;
F_61 ( V_5 ) ;
F_25 ( V_5 , V_75 , V_5 -> V_16 , L_55 ,
F_14 () ) ;
if ( V_5 -> V_160 == V_191 )
return - V_132 ;
if ( V_5 -> V_103 & V_115 )
return - V_192 ;
if ( F_177 ( V_5 ) && F_178 ( V_5 , V_78 ) )
return - V_132 ;
F_78 ( V_5 ) ;
F_74 ( V_5 ) ;
return 0 ;
}
static int F_179 ( struct V_180 * V_16 )
{
struct V_4 * V_5 = F_168 ( V_16 ) ;
F_25 ( V_5 , V_76 , V_5 -> V_16 , L_56 ,
F_14 () ) ;
if ( V_5 -> V_160 != V_191 ) {
F_70 ( V_5 ) ;
F_60 ( V_5 ) ;
F_52 ( V_5 ) ;
}
return 0 ;
}
static struct V_193 * F_180 ( struct V_180 * V_16 , struct V_193 * V_194 )
{
struct V_4 * V_5 = F_168 ( V_16 ) ;
struct V_195 * V_196 = & V_5 -> V_196 ;
F_181 ( & V_5 -> V_197 ) ;
V_5 -> type -> V_198 ( V_5 ) ;
F_182 ( & V_5 -> V_197 ) ;
V_194 -> V_199 = V_196 -> V_199 ;
V_194 -> V_200 = V_196 -> V_200 ;
V_194 -> V_201 = V_196 -> V_201 ;
V_194 -> V_202 = V_196 -> V_202 ;
V_194 -> V_203 = V_5 -> V_204 ;
V_194 -> V_205 = V_196 -> V_206 ;
V_194 -> V_207 = V_196 -> V_208 ;
V_194 -> V_209 = ( V_196 -> V_210 +
V_196 -> V_211 ) ;
V_194 -> V_212 = V_196 -> V_213 ;
V_194 -> V_214 = V_196 -> V_215 ;
V_194 -> V_216 = V_196 -> V_217 ;
V_194 -> V_218 = V_196 -> V_219 ;
V_194 -> V_220 = V_196 -> V_221 ;
V_194 -> V_222 = ( V_194 -> V_209 +
V_194 -> V_212 +
V_194 -> V_214 +
V_196 -> V_223 ) ;
V_194 -> V_224 = ( V_194 -> V_220 +
V_196 -> V_225 ) ;
return V_194 ;
}
static void F_183 ( struct V_180 * V_16 )
{
struct V_4 * V_5 = F_168 ( V_16 ) ;
F_50 ( V_5 , V_226 , V_5 -> V_16 ,
L_57 ,
V_5 -> V_77 ) ;
F_64 ( V_5 , V_227 ) ;
}
static int F_184 ( struct V_180 * V_16 , int V_228 )
{
struct V_4 * V_5 = F_168 ( V_16 ) ;
int V_57 = 0 ;
F_61 ( V_5 ) ;
if ( V_228 > V_229 )
return - V_120 ;
F_70 ( V_5 ) ;
F_25 ( V_5 , V_38 , V_5 -> V_16 , L_58 , V_228 ) ;
F_60 ( V_5 ) ;
F_93 ( & V_5 -> V_104 ) ;
V_16 -> V_70 = V_228 ;
V_5 -> V_111 -> V_112 ( V_5 ) ;
F_94 ( & V_5 -> V_104 ) ;
F_52 ( V_5 ) ;
F_74 ( V_5 ) ;
return V_57 ;
}
static int F_185 ( struct V_180 * V_16 , void * V_108 )
{
struct V_4 * V_5 = F_168 ( V_16 ) ;
struct V_230 * V_231 = V_108 ;
char * V_232 = V_231 -> V_233 ;
F_61 ( V_5 ) ;
if ( ! F_97 ( V_232 ) ) {
F_50 ( V_5 , V_38 , V_5 -> V_16 ,
L_59 ,
V_232 ) ;
return - V_120 ;
}
memcpy ( V_16 -> V_117 , V_232 , V_16 -> V_234 ) ;
F_93 ( & V_5 -> V_104 ) ;
V_5 -> V_111 -> V_112 ( V_5 ) ;
F_94 ( & V_5 -> V_104 ) ;
return 0 ;
}
static void F_186 ( struct V_180 * V_16 )
{
struct V_4 * V_5 = F_168 ( V_16 ) ;
struct V_235 * V_236 ;
union V_237 * V_238 = & V_5 -> V_239 ;
T_1 V_240 ;
int V_241 ;
V_5 -> V_94 = ! ! ( V_16 -> V_242 & V_243 ) ;
if ( V_5 -> V_94 || ( V_16 -> V_242 & V_244 ) ) {
memset ( V_238 , 0xff , sizeof( * V_238 ) ) ;
} else {
memset ( V_238 , 0x00 , sizeof( * V_238 ) ) ;
F_187 (ha, net_dev) {
V_240 = F_188 ( V_118 , V_236 -> V_231 ) ;
V_241 = V_240 & ( V_245 - 1 ) ;
F_189 ( V_241 , V_238 -> V_246 ) ;
}
F_189 ( 0xff , V_238 -> V_246 ) ;
}
if ( V_5 -> V_77 )
F_190 ( V_5 -> V_164 , & V_5 -> V_109 ) ;
}
static int F_191 ( struct V_180 * V_16 , T_1 V_108 )
{
struct V_4 * V_5 = F_168 ( V_16 ) ;
if ( V_16 -> V_247 & ~ V_108 & V_248 )
F_192 ( V_5 , V_249 ) ;
return 0 ;
}
static void F_193 ( struct V_4 * V_5 )
{
strcpy ( V_5 -> V_64 , V_5 -> V_16 -> V_64 ) ;
F_194 ( V_5 ) ;
F_47 ( V_5 ) ;
}
static int F_195 ( struct V_250 * V_251 ,
unsigned long V_252 , void * V_253 )
{
struct V_180 * V_16 = V_253 ;
if ( V_16 -> V_254 == & V_255 &&
V_252 == V_256 )
F_193 ( F_168 ( V_16 ) ) ;
return V_257 ;
}
static T_6
F_196 ( struct V_258 * V_259 , struct V_260 * V_261 , char * V_262 )
{
struct V_4 * V_5 = F_197 ( F_198 ( V_259 ) ) ;
return sprintf ( V_262 , L_60 , V_5 -> V_263 ) ;
}
static int F_199 ( struct V_4 * V_5 )
{
struct V_180 * V_16 = V_5 -> V_16 ;
struct V_1 * V_2 ;
int V_57 ;
V_16 -> V_264 = 5 * V_265 ;
V_16 -> V_30 = V_5 -> V_127 -> V_30 ;
V_16 -> V_254 = & V_255 ;
F_200 ( V_16 , & V_266 ) ;
V_5 -> V_111 -> V_198 ( V_5 ) ;
memset ( & V_5 -> V_196 , 0 , sizeof( V_5 -> V_196 ) ) ;
F_201 () ;
V_57 = F_202 ( V_16 , V_16 -> V_64 ) ;
if ( V_57 < 0 )
goto V_267;
F_193 ( V_5 ) ;
V_57 = F_203 ( V_16 ) ;
if ( V_57 )
goto V_267;
F_48 (channel, efx) {
struct V_44 * V_45 ;
F_41 (tx_queue, channel)
F_204 ( V_45 ) ;
}
F_82 ( V_5 -> V_16 ) ;
F_205 () ;
V_57 = F_206 ( & V_5 -> V_127 -> V_259 , & V_268 ) ;
if ( V_57 ) {
F_50 ( V_5 , V_38 , V_5 -> V_16 ,
L_61 ) ;
goto V_269;
}
return 0 ;
V_267:
F_205 () ;
F_50 ( V_5 , V_38 , V_5 -> V_16 , L_62 ) ;
return V_57 ;
V_269:
F_207 ( V_16 ) ;
return V_57 ;
}
static void F_208 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_44 * V_45 ;
if ( ! V_5 -> V_16 )
return;
F_18 ( F_168 ( V_5 -> V_16 ) != V_5 ) ;
F_48 (channel, efx) {
F_41 (tx_queue, channel)
F_209 ( V_45 ) ;
}
if ( F_88 ( V_5 ) ) {
F_210 ( V_5 -> V_64 , F_211 ( V_5 -> V_127 ) , sizeof( V_5 -> V_64 ) ) ;
F_212 ( & V_5 -> V_127 -> V_259 , & V_268 ) ;
F_207 ( V_5 -> V_16 ) ;
}
}
void F_213 ( struct V_4 * V_5 , enum V_270 V_271 )
{
F_61 ( V_5 ) ;
F_70 ( V_5 ) ;
F_93 ( & V_5 -> V_104 ) ;
F_60 ( V_5 ) ;
if ( V_5 -> V_125 && V_271 != V_272 )
V_5 -> V_123 -> V_126 ( V_5 ) ;
V_5 -> type -> V_126 ( V_5 ) ;
}
int F_214 ( struct V_4 * V_5 , enum V_270 V_271 , bool V_273 )
{
int V_57 ;
F_61 ( V_5 ) ;
V_57 = V_5 -> type -> V_124 ( V_5 ) ;
if ( V_57 ) {
F_50 ( V_5 , V_38 , V_5 -> V_16 , L_63 ) ;
goto V_66;
}
if ( ! V_273 )
goto V_66;
if ( V_5 -> V_125 && V_271 != V_272 ) {
V_57 = V_5 -> V_123 -> V_124 ( V_5 ) ;
if ( V_57 )
goto V_66;
if ( V_5 -> V_123 -> V_112 ( V_5 ) )
F_50 ( V_5 , V_38 , V_5 -> V_16 ,
L_64 ) ;
}
V_5 -> V_111 -> V_112 ( V_5 ) ;
F_52 ( V_5 ) ;
F_215 ( V_5 ) ;
F_94 ( & V_5 -> V_104 ) ;
F_74 ( V_5 ) ;
return 0 ;
V_66:
V_5 -> V_125 = false ;
F_94 ( & V_5 -> V_104 ) ;
return V_57 ;
}
int F_178 ( struct V_4 * V_5 , enum V_270 V_271 )
{
int V_57 , V_274 ;
bool V_275 ;
F_83 ( V_5 , V_38 , V_5 -> V_16 , L_65 ,
F_216 ( V_271 ) ) ;
F_217 ( V_5 -> V_16 ) ;
F_213 ( V_5 , V_271 ) ;
V_57 = V_5 -> type -> V_276 ( V_5 , V_271 ) ;
if ( V_57 ) {
F_50 ( V_5 , V_38 , V_5 -> V_16 , L_66 ) ;
goto V_84;
}
V_5 -> V_7 &= - ( 1 << ( V_271 + 1 ) ) ;
F_106 ( V_5 -> V_127 ) ;
V_84:
V_275 = V_57 || V_271 == V_277 ;
V_274 = F_214 ( V_5 , V_271 , ! V_275 ) ;
if ( V_274 ) {
V_275 = true ;
if ( ! V_57 )
V_57 = V_274 ;
}
if ( V_275 ) {
F_218 ( V_5 -> V_16 ) ;
F_50 ( V_5 , V_38 , V_5 -> V_16 , L_67 ) ;
V_5 -> V_160 = V_191 ;
} else {
F_25 ( V_5 , V_38 , V_5 -> V_16 , L_68 ) ;
F_219 ( V_5 -> V_16 ) ;
}
return V_57 ;
}
static void F_220 ( struct V_107 * V_108 )
{
struct V_4 * V_5 = F_12 ( V_108 , struct V_4 , V_278 ) ;
unsigned long V_279 = F_221 ( V_5 -> V_7 ) ;
if ( ! V_279 )
return;
if ( V_5 -> V_160 != V_161 ) {
F_83 ( V_5 , V_38 , V_5 -> V_16 ,
L_69 ) ;
return;
}
F_201 () ;
( void ) F_178 ( V_5 , F_222 ( V_279 ) - 1 ) ;
F_205 () ;
}
void F_64 ( struct V_4 * V_5 , enum V_270 type )
{
enum V_270 V_271 ;
switch ( type ) {
case V_272 :
case V_78 :
case V_280 :
case V_277 :
V_271 = type ;
F_25 ( V_5 , V_38 , V_5 -> V_16 , L_70 ,
F_216 ( V_271 ) ) ;
break;
default:
V_271 = V_5 -> type -> V_281 ( type ) ;
F_25 ( V_5 , V_38 , V_5 -> V_16 ,
L_71 ,
F_216 ( V_271 ) , F_216 ( type ) ) ;
break;
}
F_223 ( V_271 , & V_5 -> V_7 ) ;
F_152 ( V_5 ) ;
F_190 ( V_282 , & V_5 -> V_278 ) ;
}
int F_224 ( struct V_4 * V_5 )
{
return 0 ;
}
void F_225 ( struct V_4 * V_5 ) {}
static bool F_226 ( struct V_4 * V_5 )
{
return false ;
}
static int F_227 ( struct V_4 * V_5 , const struct V_283 * type ,
struct V_127 * V_127 , struct V_180 * V_16 )
{
int V_40 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
F_228 ( & V_5 -> V_284 ) ;
#ifdef F_229
F_230 ( & V_5 -> V_285 ) ;
#endif
F_231 ( & V_5 -> V_278 , F_220 ) ;
F_232 ( & V_5 -> V_165 , F_165 ) ;
V_5 -> V_127 = V_127 ;
V_5 -> V_286 = V_287 ;
V_5 -> V_160 = V_162 ;
F_210 ( V_5 -> V_64 , F_211 ( V_127 ) , sizeof( V_5 -> V_64 ) ) ;
V_5 -> V_16 = V_16 ;
F_228 ( & V_5 -> V_197 ) ;
F_233 ( & V_5 -> V_104 ) ;
V_5 -> V_111 = type -> V_288 ;
V_5 -> V_123 = & V_289 ;
V_5 -> V_189 . V_259 = V_16 ;
F_231 ( & V_5 -> V_109 , F_95 ) ;
for ( V_40 = 0 ; V_40 < V_80 ; V_40 ++ ) {
V_5 -> V_2 [ V_40 ] = F_36 ( V_5 , V_40 , NULL ) ;
if ( ! V_5 -> V_2 [ V_40 ] )
goto V_66;
}
V_5 -> type = type ;
F_27 ( V_5 -> type -> V_146 > V_80 ) ;
V_5 -> V_147 = F_28 ( V_5 -> type -> V_290 ,
V_147 ) ;
snprintf ( V_5 -> V_291 , sizeof( V_5 -> V_291 ) , L_72 ,
F_211 ( V_127 ) ) ;
V_5 -> V_164 = F_234 ( V_5 -> V_291 ) ;
if ( ! V_5 -> V_164 )
goto V_66;
return 0 ;
V_66:
F_235 ( V_5 ) ;
return - V_83 ;
}
static void F_235 ( struct V_4 * V_5 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_80 ; V_40 ++ )
F_73 ( V_5 -> V_2 [ V_40 ] ) ;
if ( V_5 -> V_164 ) {
F_236 ( V_5 -> V_164 ) ;
V_5 -> V_164 = NULL ;
}
}
static void F_237 ( struct V_4 * V_5 )
{
#ifdef F_126
F_129 ( V_5 -> V_16 -> V_143 ) ;
V_5 -> V_16 -> V_143 = NULL ;
#endif
F_238 ( V_5 ) ;
F_60 ( V_5 ) ;
F_102 ( V_5 ) ;
V_5 -> type -> V_126 ( V_5 ) ;
F_173 ( V_5 ) ;
F_160 ( V_5 ) ;
}
static void F_239 ( struct V_127 * V_127 )
{
struct V_4 * V_5 ;
V_5 = F_197 ( V_127 ) ;
if ( ! V_5 )
return;
F_201 () ;
V_5 -> V_160 = V_292 ;
F_218 ( V_5 -> V_16 ) ;
F_205 () ;
F_208 ( V_5 ) ;
F_240 ( V_5 ) ;
F_156 ( & V_5 -> V_278 ) ;
F_237 ( V_5 ) ;
F_115 ( V_5 ) ;
F_25 ( V_5 , V_38 , V_5 -> V_16 , L_73 ) ;
F_241 ( V_127 , NULL ) ;
F_235 ( V_5 ) ;
F_242 ( V_5 -> V_16 ) ;
}
static int F_243 ( struct V_4 * V_5 )
{
int V_57 ;
V_57 = F_147 ( V_5 ) ;
if ( V_57 )
goto V_58;
F_71 ( V_5 ) ;
V_57 = V_5 -> type -> V_124 ( V_5 ) ;
if ( V_57 ) {
F_50 ( V_5 , V_33 , V_5 -> V_16 ,
L_63 ) ;
goto V_60;
}
V_57 = F_99 ( V_5 ) ;
if ( V_57 ) {
F_50 ( V_5 , V_33 , V_5 -> V_16 ,
L_74 ) ;
goto V_135;
}
F_52 ( V_5 ) ;
V_57 = F_244 ( V_5 ) ;
if ( V_57 )
goto V_293;
return 0 ;
V_293:
F_60 ( V_5 ) ;
F_102 ( V_5 ) ;
V_135:
V_5 -> type -> V_126 ( V_5 ) ;
V_60:
F_173 ( V_5 ) ;
F_160 ( V_5 ) ;
V_58:
return V_57 ;
}
static int T_7 F_245 ( struct V_127 * V_127 ,
const struct V_294 * V_150 )
{
const struct V_283 * type = ( const struct V_283 * ) V_150 -> V_295 ;
struct V_180 * V_16 ;
struct V_4 * V_5 ;
int V_40 , V_57 ;
V_16 = F_246 ( sizeof( * V_5 ) , V_296 ,
V_297 ) ;
if ( ! V_16 )
return - V_83 ;
V_16 -> V_247 |= ( type -> V_298 | V_299 |
V_300 | V_301 |
V_302 ) ;
if ( type -> V_298 & V_303 )
V_16 -> V_247 |= V_304 ;
V_16 -> V_305 |= ( V_306 | V_299 |
V_300 | V_307 |
V_302 ) ;
V_16 -> V_308 = V_16 -> V_247 & ~ V_300 ;
V_5 = F_168 ( V_16 ) ;
F_241 ( V_127 , V_5 ) ;
F_247 ( V_16 , & V_127 -> V_259 ) ;
V_57 = F_227 ( V_5 , type , V_127 , V_16 ) ;
if ( V_57 )
goto V_58;
F_83 ( V_5 , V_33 , V_5 -> V_16 ,
L_75 ) ;
V_57 = F_104 ( V_5 ) ;
if ( V_57 )
goto V_59;
for ( V_40 = 0 ; V_40 < 5 ; V_40 ++ ) {
V_57 = F_243 ( V_5 ) ;
F_156 ( & V_5 -> V_278 ) ;
if ( V_57 == 0 ) {
if ( V_5 -> V_7 ) {
F_237 ( V_5 ) ;
V_57 = - V_132 ;
} else {
break;
}
}
if ( V_5 -> V_7 &
~ ( 1 << V_272 | 1 << V_78 ) ||
! V_5 -> V_7 )
goto V_60;
V_5 -> V_7 = 0 ;
}
if ( V_57 ) {
F_50 ( V_5 , V_33 , V_5 -> V_16 , L_76 ) ;
goto V_135;
}
V_5 -> V_160 = V_161 ;
V_57 = F_199 ( V_5 ) ;
if ( V_57 )
goto V_293;
F_25 ( V_5 , V_33 , V_5 -> V_16 , L_77 ) ;
F_201 () ;
F_248 ( V_5 ) ;
F_205 () ;
return 0 ;
V_293:
F_237 ( V_5 ) ;
V_135:
V_60:
F_115 ( V_5 ) ;
V_59:
F_235 ( V_5 ) ;
V_58:
F_57 ( V_57 > 0 ) ;
F_25 ( V_5 , V_38 , V_5 -> V_16 , L_78 , V_57 ) ;
F_242 ( V_16 ) ;
return V_57 ;
}
static int F_249 ( struct V_258 * V_259 )
{
struct V_4 * V_5 = F_197 ( F_198 ( V_259 ) ) ;
V_5 -> V_160 = V_292 ;
F_217 ( V_5 -> V_16 ) ;
F_70 ( V_5 ) ;
F_60 ( V_5 ) ;
return 0 ;
}
static int F_250 ( struct V_258 * V_259 )
{
struct V_4 * V_5 = F_197 ( F_198 ( V_259 ) ) ;
V_5 -> V_160 = V_162 ;
F_52 ( V_5 ) ;
F_93 ( & V_5 -> V_104 ) ;
V_5 -> V_123 -> V_112 ( V_5 ) ;
F_94 ( & V_5 -> V_104 ) ;
F_74 ( V_5 ) ;
F_219 ( V_5 -> V_16 ) ;
V_5 -> V_160 = V_161 ;
V_5 -> type -> V_309 ( V_5 ) ;
F_190 ( V_282 , & V_5 -> V_278 ) ;
return 0 ;
}
static int F_251 ( struct V_258 * V_259 )
{
struct V_127 * V_127 = F_198 ( V_259 ) ;
struct V_4 * V_5 = F_197 ( V_127 ) ;
V_5 -> type -> V_126 ( V_5 ) ;
V_5 -> V_7 = 0 ;
F_252 ( V_127 ) ;
return F_253 ( V_127 , V_310 ) ;
}
static int F_254 ( struct V_258 * V_259 )
{
struct V_127 * V_127 = F_198 ( V_259 ) ;
struct V_4 * V_5 = F_197 ( V_127 ) ;
int V_57 ;
V_57 = F_253 ( V_127 , V_311 ) ;
if ( V_57 )
return V_57 ;
F_255 ( V_127 ) ;
V_57 = F_105 ( V_127 ) ;
if ( V_57 )
return V_57 ;
F_106 ( V_5 -> V_127 ) ;
V_57 = V_5 -> type -> V_276 ( V_5 , V_78 ) ;
if ( V_57 )
return V_57 ;
V_57 = V_5 -> type -> V_124 ( V_5 ) ;
if ( V_57 )
return V_57 ;
F_250 ( V_259 ) ;
return 0 ;
}
static int F_256 ( struct V_258 * V_259 )
{
int V_57 ;
F_249 ( V_259 ) ;
V_57 = F_251 ( V_259 ) ;
if ( V_57 )
F_254 ( V_259 ) ;
return V_57 ;
}
static int T_8 F_257 ( void )
{
int V_57 ;
F_119 ( V_312 L_79 V_313 L_80 ) ;
V_57 = F_258 ( & V_314 ) ;
if ( V_57 )
goto V_315;
V_282 = F_234 ( L_81 ) ;
if ( ! V_282 ) {
V_57 = - V_83 ;
goto V_316;
}
V_57 = F_259 ( & V_317 ) ;
if ( V_57 < 0 )
goto V_318;
return 0 ;
V_318:
F_236 ( V_282 ) ;
V_316:
F_260 ( & V_314 ) ;
V_315:
return V_57 ;
}
static void T_9 F_261 ( void )
{
F_119 ( V_312 L_82 ) ;
F_262 ( & V_317 ) ;
F_236 ( V_282 ) ;
F_260 ( & V_314 ) ;
}

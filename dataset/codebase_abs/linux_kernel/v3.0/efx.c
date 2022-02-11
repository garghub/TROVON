static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
if ( F_2 ( V_5 -> V_7 != V_8 ||
! V_2 -> V_9 ) )
return 0 ;
V_6 = F_3 ( V_2 , V_3 ) ;
if ( V_6 == 0 )
return 0 ;
if ( V_2 -> V_10 ) {
F_4 ( V_2 , V_2 -> V_10 ,
V_2 -> V_11 ) ;
V_2 -> V_10 = NULL ;
}
F_5 ( V_2 ) ;
F_6 ( F_7 ( V_2 ) ) ;
return V_6 ;
}
static inline void F_8 ( struct V_1 * V_2 )
{
V_2 -> V_12 = false ;
F_9 () ;
F_10 ( V_2 ) ;
}
static int F_11 ( struct V_13 * V_14 , int V_3 )
{
struct V_1 * V_2 =
F_12 ( V_14 , struct V_1 , V_15 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
F_13 ( V_5 , V_16 , V_5 -> V_17 ,
L_1 ,
V_2 -> V_2 , F_14 () ) ;
V_6 = F_1 ( V_2 , V_3 ) ;
if ( V_6 < V_3 ) {
if ( V_2 -> V_2 < V_5 -> V_18 &&
V_5 -> V_19 &&
F_2 ( ++ V_2 -> V_20 == 1000 ) ) {
if ( F_2 ( V_2 -> V_21 <
V_22 ) ) {
if ( V_2 -> V_23 > 1 ) {
V_2 -> V_23 -= 1 ;
V_5 -> type -> V_24 ( V_2 ) ;
}
} else if ( F_2 ( V_2 -> V_21 >
V_25 ) ) {
if ( V_2 -> V_23 <
V_5 -> V_26 ) {
V_2 -> V_23 += 1 ;
V_5 -> type -> V_24 ( V_2 ) ;
}
}
V_2 -> V_20 = 0 ;
V_2 -> V_21 = 0 ;
}
F_15 ( V_2 ) ;
F_16 ( V_14 ) ;
F_8 ( V_2 ) ;
}
return V_6 ;
}
void F_17 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
F_18 ( V_2 -> V_2 >= V_5 -> V_27 ) ;
F_18 ( ! V_2 -> V_9 ) ;
F_18 ( ! V_5 -> V_28 ) ;
F_19 ( V_5 ) ;
if ( V_5 -> V_29 ) {
F_20 ( V_5 -> V_29 ) ;
V_5 -> V_30 = false ;
}
if ( V_2 -> V_31 )
F_20 ( V_2 -> V_31 ) ;
F_21 ( & V_2 -> V_15 ) ;
F_1 ( V_2 , V_2 -> V_32 + 1 ) ;
F_8 ( V_2 ) ;
F_22 ( & V_2 -> V_15 ) ;
if ( V_5 -> V_29 )
V_5 -> V_30 = true ;
F_23 ( V_5 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned long V_33 ;
F_25 ( V_2 -> V_5 , V_34 , V_2 -> V_5 -> V_17 ,
L_2 , V_2 -> V_2 ) ;
V_33 = F_26 ( V_5 -> V_35 + V_5 -> V_36 + 128 ) ;
F_27 ( V_33 > V_37 ) ;
V_2 -> V_32 = F_28 ( V_33 , V_38 ) - 1 ;
return F_29 ( V_2 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_25 ( V_2 -> V_5 , V_39 , V_2 -> V_5 -> V_17 ,
L_3 , V_2 -> V_2 ) ;
V_2 -> V_40 = 0 ;
F_31 ( V_2 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_25 ( V_2 -> V_5 , V_39 , V_2 -> V_5 -> V_17 ,
L_4 , V_2 -> V_2 ) ;
F_33 ( V_2 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_25 ( V_2 -> V_5 , V_39 , V_2 -> V_5 -> V_17 ,
L_5 , V_2 -> V_2 ) ;
F_35 ( V_2 ) ;
}
static struct V_1 *
F_36 ( struct V_4 * V_5 , int V_41 , struct V_1 * V_42 )
{
struct V_1 * V_2 ;
struct V_43 * V_44 ;
struct V_45 * V_46 ;
int V_47 ;
if ( V_42 ) {
V_2 = F_37 ( sizeof( * V_2 ) , V_48 ) ;
if ( ! V_2 )
return NULL ;
* V_2 = * V_42 ;
V_2 -> V_49 = NULL ;
memset ( & V_2 -> V_50 , 0 , sizeof( V_2 -> V_50 ) ) ;
V_44 = & V_2 -> V_44 ;
V_44 -> V_51 = NULL ;
memset ( & V_44 -> V_52 , 0 , sizeof( V_44 -> V_52 ) ) ;
for ( V_47 = 0 ; V_47 < V_53 ; V_47 ++ ) {
V_46 = & V_2 -> V_46 [ V_47 ] ;
if ( V_46 -> V_2 )
V_46 -> V_2 = V_2 ;
V_46 -> V_51 = NULL ;
memset ( & V_46 -> V_54 , 0 , sizeof( V_46 -> V_54 ) ) ;
}
} else {
V_2 = F_38 ( sizeof( * V_2 ) , V_48 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_5 = V_5 ;
V_2 -> V_2 = V_41 ;
for ( V_47 = 0 ; V_47 < V_53 ; V_47 ++ ) {
V_46 = & V_2 -> V_46 [ V_47 ] ;
V_46 -> V_5 = V_5 ;
V_46 -> V_55 = V_41 * V_53 + V_47 ;
V_46 -> V_2 = V_2 ;
}
}
V_44 = & V_2 -> V_44 ;
V_44 -> V_5 = V_5 ;
F_39 ( & V_44 -> V_56 , V_57 ,
( unsigned long ) V_44 ) ;
return V_2 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_45 * V_46 ;
struct V_43 * V_44 ;
int V_58 ;
F_25 ( V_2 -> V_5 , V_34 , V_2 -> V_5 -> V_17 ,
L_6 , V_2 -> V_2 ) ;
V_58 = F_24 ( V_2 ) ;
if ( V_58 )
goto V_59;
F_41 (tx_queue, channel) {
V_58 = F_42 ( V_46 ) ;
if ( V_58 )
goto V_60;
}
F_43 (rx_queue, channel) {
V_58 = F_44 ( V_44 ) ;
if ( V_58 )
goto V_61;
}
V_2 -> V_62 = 0 ;
return 0 ;
V_61:
F_43 (rx_queue, channel)
F_45 ( V_44 ) ;
V_60:
F_41 (tx_queue, channel)
F_46 ( V_46 ) ;
V_59:
return V_58 ;
}
static void F_47 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
const char * type = L_7 ;
int V_63 ;
F_48 (channel, efx) {
V_63 = V_2 -> V_2 ;
if ( V_5 -> V_27 > V_5 -> V_18 ) {
if ( V_2 -> V_2 < V_5 -> V_18 ) {
type = L_8 ;
} else {
type = L_9 ;
V_63 -= V_5 -> V_18 ;
}
}
snprintf ( V_5 -> V_64 [ V_2 -> V_2 ] ,
sizeof( V_5 -> V_64 [ 0 ] ) ,
L_10 , V_5 -> V_65 , type , V_63 ) ;
}
}
static int F_49 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
int V_58 ;
V_5 -> V_66 = 0 ;
F_48 (channel, efx) {
V_58 = F_40 ( V_2 ) ;
if ( V_58 ) {
F_50 ( V_5 , V_34 , V_5 -> V_17 ,
L_11 ,
V_2 -> V_2 ) ;
goto V_67;
}
}
F_47 ( V_5 ) ;
return 0 ;
V_67:
F_51 ( V_5 ) ;
return V_58 ;
}
static void F_52 ( struct V_4 * V_5 )
{
struct V_45 * V_46 ;
struct V_43 * V_44 ;
struct V_1 * V_2 ;
V_5 -> V_68 = ( F_28 ( V_69 , V_70 ) +
F_53 ( V_5 -> V_17 -> V_71 ) +
V_5 -> type -> V_72 +
V_5 -> type -> V_73 ) ;
V_5 -> V_74 = F_54 ( V_5 -> V_68 +
sizeof( struct V_75 ) ) ;
F_48 (channel, efx) {
F_25 ( V_2 -> V_5 , V_39 , V_2 -> V_5 -> V_17 ,
L_12 , V_2 -> V_2 ) ;
F_30 ( V_2 ) ;
F_41 (tx_queue, channel)
F_55 ( V_46 ) ;
F_5 ( V_2 ) ;
F_43 (rx_queue, channel)
F_56 ( V_44 ) ;
F_57 ( V_2 -> V_10 != NULL ) ;
F_5 ( V_2 ) ;
}
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_43 * V_44 ;
F_25 ( V_2 -> V_5 , V_76 , V_2 -> V_5 -> V_17 ,
L_13 , V_2 -> V_2 ) ;
V_2 -> V_12 = false ;
V_2 -> V_9 = true ;
F_9 () ;
F_43 (rx_queue, channel)
F_6 ( V_44 ) ;
F_22 ( & V_2 -> V_15 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_9 )
return;
F_25 ( V_2 -> V_5 , V_77 , V_2 -> V_5 -> V_17 ,
L_14 , V_2 -> V_2 ) ;
V_2 -> V_9 = false ;
F_21 ( & V_2 -> V_15 ) ;
}
static void F_60 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_45 * V_46 ;
struct V_43 * V_44 ;
int V_58 ;
F_61 ( V_5 ) ;
F_18 ( V_5 -> V_78 ) ;
V_58 = F_62 ( V_5 ) ;
if ( V_58 && F_63 ( V_5 ) ) {
F_50 ( V_5 , V_39 , V_5 -> V_17 ,
L_15 ) ;
F_64 ( V_5 , V_79 ) ;
} else if ( V_58 ) {
F_50 ( V_5 , V_39 , V_5 -> V_17 , L_16 ) ;
} else {
F_25 ( V_5 , V_39 , V_5 -> V_17 ,
L_17 ) ;
}
F_48 (channel, efx) {
F_25 ( V_2 -> V_5 , V_39 , V_2 -> V_5 -> V_17 ,
L_18 , V_2 -> V_2 ) ;
F_43 (rx_queue, channel)
F_65 ( V_44 ) ;
F_66 (tx_queue, channel)
F_67 ( V_46 ) ;
F_32 ( V_2 ) ;
}
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_45 * V_46 ;
struct V_43 * V_44 ;
F_25 ( V_2 -> V_5 , V_39 , V_2 -> V_5 -> V_17 ,
L_19 , V_2 -> V_2 ) ;
F_43 (rx_queue, channel)
F_45 ( V_44 ) ;
F_66 (tx_queue, channel)
F_46 ( V_46 ) ;
F_34 ( V_2 ) ;
}
static void F_51 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
F_48 (channel, efx)
F_68 ( V_2 ) ;
}
int
F_69 ( struct V_4 * V_5 , T_1 V_35 , T_1 V_36 )
{
struct V_1 * V_80 [ V_81 ] , * V_2 ;
T_1 V_82 , V_83 ;
unsigned V_41 ;
int V_58 ;
F_70 ( V_5 ) ;
F_60 ( V_5 ) ;
memset ( V_80 , 0 , sizeof( V_80 ) ) ;
for ( V_41 = 0 ; V_41 < V_5 -> V_27 ; V_41 ++ ) {
V_2 = F_36 ( V_5 , V_41 , V_5 -> V_2 [ V_41 ] ) ;
if ( ! V_2 ) {
V_58 = - V_84 ;
goto V_85;
}
V_80 [ V_41 ] = V_2 ;
}
V_82 = V_5 -> V_35 ;
V_83 = V_5 -> V_36 ;
V_5 -> V_35 = V_35 ;
V_5 -> V_36 = V_36 ;
for ( V_41 = 0 ; V_41 < V_5 -> V_27 ; V_41 ++ ) {
V_2 = V_5 -> V_2 [ V_41 ] ;
V_5 -> V_2 [ V_41 ] = V_80 [ V_41 ] ;
V_80 [ V_41 ] = V_2 ;
}
V_58 = F_49 ( V_5 ) ;
if ( V_58 )
goto V_86;
F_71 ( V_5 ) ;
for ( V_41 = 0 ; V_41 < V_5 -> V_27 ; V_41 ++ ) {
F_72 ( V_80 [ V_41 ] ) ;
F_68 ( V_80 [ V_41 ] ) ;
}
V_85:
for ( V_41 = 0 ; V_41 < V_5 -> V_27 ; V_41 ++ )
F_73 ( V_80 [ V_41 ] ) ;
F_52 ( V_5 ) ;
F_74 ( V_5 ) ;
return V_58 ;
V_86:
V_5 -> V_35 = V_82 ;
V_5 -> V_36 = V_83 ;
for ( V_41 = 0 ; V_41 < V_5 -> V_27 ; V_41 ++ ) {
V_2 = V_5 -> V_2 [ V_41 ] ;
V_5 -> V_2 [ V_41 ] = V_80 [ V_41 ] ;
V_80 [ V_41 ] = V_2 ;
}
goto V_85;
}
void F_75 ( struct V_43 * V_44 )
{
F_76 ( & V_44 -> V_56 , V_87 + F_77 ( 100 ) ) ;
}
void F_78 ( struct V_4 * V_5 )
{
struct V_88 * V_89 = & V_5 -> V_89 ;
if ( ! F_79 ( V_5 -> V_17 ) )
return;
if ( V_89 -> V_90 != F_80 ( V_5 -> V_17 ) ) {
V_5 -> V_91 ++ ;
if ( V_89 -> V_90 )
F_81 ( V_5 -> V_17 ) ;
else
F_82 ( V_5 -> V_17 ) ;
}
if ( V_89 -> V_90 ) {
F_83 ( V_5 , V_92 , V_5 -> V_17 ,
L_20 ,
V_89 -> V_93 , V_89 -> V_94 ? L_21 : L_22 ,
V_5 -> V_17 -> V_71 ,
( V_5 -> V_95 ? L_23 : L_7 ) ) ;
} else {
F_83 ( V_5 , V_92 , V_5 -> V_17 , L_24 ) ;
}
}
void F_84 ( struct V_4 * V_5 , T_1 V_96 )
{
V_5 -> V_97 = V_96 ;
if ( V_96 ) {
if ( V_96 & V_98 )
V_5 -> V_99 |= ( V_100 | V_101 ) ;
else
V_5 -> V_99 &= ~ ( V_100 | V_101 ) ;
if ( V_96 & V_102 )
V_5 -> V_99 ^= V_100 ;
}
}
void F_85 ( struct V_4 * V_5 , T_2 V_99 )
{
V_5 -> V_99 = V_99 ;
if ( V_5 -> V_97 ) {
if ( V_99 & V_101 )
V_5 -> V_97 |= ( V_98 |
V_102 ) ;
else
V_5 -> V_97 &= ~ ( V_98 |
V_102 ) ;
if ( V_99 & V_100 )
V_5 -> V_97 ^= V_102 ;
}
}
int F_86 ( struct V_4 * V_5 )
{
enum V_103 V_104 ;
int V_58 ;
F_57 ( ! F_87 ( & V_5 -> V_105 ) ) ;
if ( F_88 ( V_5 ) ) {
F_89 ( V_5 -> V_17 ) ;
F_90 ( V_5 -> V_17 ) ;
}
V_104 = V_5 -> V_104 ;
if ( F_91 ( V_5 ) )
V_5 -> V_104 |= V_106 ;
else
V_5 -> V_104 &= ~ V_106 ;
V_58 = V_5 -> type -> V_107 ( V_5 ) ;
if ( V_58 )
V_5 -> V_104 = V_104 ;
return V_58 ;
}
int F_92 ( struct V_4 * V_5 )
{
int V_58 ;
F_61 ( V_5 ) ;
F_93 ( & V_5 -> V_105 ) ;
V_58 = F_86 ( V_5 ) ;
F_94 ( & V_5 -> V_105 ) ;
return V_58 ;
}
static void F_95 ( struct V_108 * V_109 )
{
struct V_4 * V_5 = F_12 ( V_109 , struct V_4 , V_110 ) ;
F_93 ( & V_5 -> V_105 ) ;
if ( V_5 -> V_78 ) {
V_5 -> type -> V_111 ( V_5 ) ;
V_5 -> V_112 -> V_113 ( V_5 ) ;
}
F_94 ( & V_5 -> V_105 ) ;
}
static int F_96 ( struct V_4 * V_5 )
{
unsigned char * V_114 ;
int V_58 ;
F_25 ( V_5 , V_34 , V_5 -> V_17 , L_25 ) ;
if ( V_115 )
V_5 -> V_104 = V_116 ;
V_58 = V_5 -> type -> V_117 ( V_5 ) ;
if ( V_58 )
return V_58 ;
V_114 = V_5 -> V_17 -> V_114 ;
if ( F_97 ( V_114 ) ) {
memcpy ( V_5 -> V_17 -> V_118 , V_114 , V_119 ) ;
} else {
F_50 ( V_5 , V_34 , V_5 -> V_17 , L_26 ,
V_114 ) ;
if ( ! V_120 ) {
V_58 = - V_121 ;
goto V_122;
}
F_98 ( V_5 -> V_17 -> V_118 ) ;
F_83 ( V_5 , V_34 , V_5 -> V_17 ,
L_27 ,
V_5 -> V_17 -> V_118 ) ;
}
return 0 ;
V_122:
V_5 -> type -> V_123 ( V_5 ) ;
return V_58 ;
}
static int F_99 ( struct V_4 * V_5 )
{
int V_58 ;
F_25 ( V_5 , V_39 , V_5 -> V_17 , L_28 ) ;
F_93 ( & V_5 -> V_105 ) ;
V_58 = V_5 -> V_124 -> V_125 ( V_5 ) ;
if ( V_58 )
goto V_59;
V_5 -> V_126 = true ;
V_5 -> V_112 -> V_113 ( V_5 ) ;
V_58 = V_5 -> V_124 -> V_113 ( V_5 ) ;
if ( V_58 )
goto V_60;
F_94 ( & V_5 -> V_105 ) ;
return 0 ;
V_60:
V_5 -> V_124 -> V_127 ( V_5 ) ;
V_59:
F_94 ( & V_5 -> V_105 ) ;
return V_58 ;
}
static void F_100 ( struct V_4 * V_5 )
{
F_25 ( V_5 , V_76 , V_5 -> V_17 , L_29 ) ;
F_18 ( V_5 -> V_78 ) ;
F_93 ( & V_5 -> V_105 ) ;
V_5 -> V_78 = true ;
V_5 -> type -> V_111 ( V_5 ) ;
V_5 -> V_112 -> V_113 ( V_5 ) ;
F_94 ( & V_5 -> V_105 ) ;
}
static void F_101 ( struct V_4 * V_5 )
{
F_25 ( V_5 , V_77 , V_5 -> V_17 , L_30 ) ;
F_93 ( & V_5 -> V_105 ) ;
V_5 -> V_78 = false ;
F_94 ( & V_5 -> V_105 ) ;
if ( F_88 ( V_5 ) ) {
F_89 ( V_5 -> V_17 ) ;
F_90 ( V_5 -> V_17 ) ;
}
}
static void F_102 ( struct V_4 * V_5 )
{
F_25 ( V_5 , V_39 , V_5 -> V_17 , L_31 ) ;
if ( ! V_5 -> V_126 )
return;
V_5 -> V_124 -> V_127 ( V_5 ) ;
V_5 -> V_126 = false ;
V_5 -> V_89 . V_90 = false ;
F_78 ( V_5 ) ;
}
static void F_103 ( struct V_4 * V_5 )
{
F_25 ( V_5 , V_39 , V_5 -> V_17 , L_32 ) ;
V_5 -> type -> V_123 ( V_5 ) ;
}
static int F_104 ( struct V_4 * V_5 )
{
struct V_128 * V_128 = V_5 -> V_128 ;
T_3 V_129 = V_5 -> type -> V_130 ;
bool V_131 ;
int V_58 ;
F_25 ( V_5 , V_34 , V_5 -> V_17 , L_33 ) ;
V_58 = F_105 ( V_128 ) ;
if ( V_58 ) {
F_50 ( V_5 , V_34 , V_5 -> V_17 ,
L_34 ) ;
goto V_59;
}
F_106 ( V_128 ) ;
while ( V_129 > 0x7fffffffUL ) {
if ( F_107 ( V_128 , V_129 ) &&
( ( V_58 = F_108 ( V_128 , V_129 ) ) == 0 ) )
break;
V_129 >>= 1 ;
}
if ( V_58 ) {
F_50 ( V_5 , V_34 , V_5 -> V_17 ,
L_35 ) ;
goto V_60;
}
F_25 ( V_5 , V_34 , V_5 -> V_17 ,
L_36 , ( unsigned long long ) V_129 ) ;
V_58 = F_109 ( V_128 , V_129 ) ;
if ( V_58 ) {
F_50 ( V_5 , V_34 , V_5 -> V_17 ,
L_37 ) ;
goto V_60;
}
V_5 -> V_132 = F_110 ( V_5 -> V_128 , V_133 ) ;
V_58 = F_111 ( V_128 , V_133 , L_38 ) ;
if ( V_58 ) {
F_50 ( V_5 , V_34 , V_5 -> V_17 ,
L_39 ) ;
V_58 = - V_134 ;
goto V_61;
}
V_131 = ( ! F_112 ( V_5 ) ||
F_113 ( V_128 , V_135 ) ) ;
if ( V_131 )
V_5 -> V_136 = F_114 ( V_5 -> V_132 ,
V_5 -> type -> V_137 ) ;
else
V_5 -> V_136 = F_115 ( V_5 -> V_132 ,
V_5 -> type -> V_137 ) ;
if ( ! V_5 -> V_136 ) {
F_50 ( V_5 , V_34 , V_5 -> V_17 ,
L_40 ,
( unsigned long long ) V_5 -> V_132 ,
V_5 -> type -> V_137 ) ;
V_58 = - V_84 ;
goto V_138;
}
F_25 ( V_5 , V_34 , V_5 -> V_17 ,
L_41 ,
( unsigned long long ) V_5 -> V_132 ,
V_5 -> type -> V_137 , V_5 -> V_136 ) ;
return 0 ;
V_138:
F_116 ( V_5 -> V_128 , V_133 ) ;
V_61:
V_5 -> V_132 = 0 ;
V_60:
F_117 ( V_5 -> V_128 ) ;
V_59:
return V_58 ;
}
static void F_118 ( struct V_4 * V_5 )
{
F_25 ( V_5 , V_39 , V_5 -> V_17 , L_42 ) ;
if ( V_5 -> V_136 ) {
F_119 ( V_5 -> V_136 ) ;
V_5 -> V_136 = NULL ;
}
if ( V_5 -> V_132 ) {
F_116 ( V_5 -> V_128 , V_133 ) ;
V_5 -> V_132 = 0 ;
}
F_117 ( V_5 -> V_128 ) ;
}
static int F_120 ( void )
{
T_4 V_139 ;
int V_140 ;
int V_141 ;
if ( V_142 )
return V_142 ;
if ( F_2 ( ! F_121 ( & V_139 , V_48 ) ) ) {
F_122 ( V_143
L_43 ) ;
return 1 ;
}
V_140 = 0 ;
F_123 (cpu) {
if ( ! F_124 ( V_141 , V_139 ) ) {
++ V_140 ;
F_125 ( V_139 , V_139 ,
F_126 ( V_141 ) ) ;
}
}
F_127 ( V_139 ) ;
return V_140 ;
}
static int
F_128 ( struct V_4 * V_5 , struct V_144 * V_145 )
{
#ifdef F_129
int V_41 , V_58 ;
V_5 -> V_17 -> V_146 = F_130 ( V_5 -> V_18 ) ;
if ( ! V_5 -> V_17 -> V_146 )
return - V_84 ;
for ( V_41 = 0 ; V_41 < V_5 -> V_18 ; V_41 ++ ) {
V_58 = F_131 ( V_5 -> V_17 -> V_146 ,
V_145 [ V_41 ] . V_147 ) ;
if ( V_58 ) {
F_132 ( V_5 -> V_17 -> V_146 ) ;
V_5 -> V_17 -> V_146 = NULL ;
return V_58 ;
}
}
#endif
return 0 ;
}
static int F_133 ( struct V_4 * V_5 )
{
int V_148 =
F_134 ( int , V_5 -> type -> V_149 , V_81 ) ;
int V_58 , V_41 ;
if ( V_5 -> V_150 == V_151 ) {
struct V_144 V_145 [ V_81 ] ;
int V_27 ;
V_27 = F_120 () ;
if ( V_152 )
V_27 *= 2 ;
V_27 = F_135 ( V_27 , V_148 ) ;
for ( V_41 = 0 ; V_41 < V_27 ; V_41 ++ )
V_145 [ V_41 ] . V_153 = V_41 ;
V_58 = F_136 ( V_5 -> V_128 , V_145 , V_27 ) ;
if ( V_58 > 0 ) {
F_50 ( V_5 , V_39 , V_5 -> V_17 ,
L_44
L_45 , V_58 , V_27 ) ;
F_50 ( V_5 , V_39 , V_5 -> V_17 ,
L_46 ) ;
F_27 ( V_58 >= V_27 ) ;
V_27 = V_58 ;
V_58 = F_136 ( V_5 -> V_128 , V_145 ,
V_27 ) ;
}
if ( V_58 == 0 ) {
V_5 -> V_27 = V_27 ;
if ( V_152 ) {
V_5 -> V_154 =
F_28 ( V_5 -> V_27 / 2 , 1U ) ;
V_5 -> V_18 =
F_28 ( V_5 -> V_27 -
V_5 -> V_154 , 1U ) ;
} else {
V_5 -> V_154 = V_5 -> V_27 ;
V_5 -> V_18 = V_5 -> V_27 ;
}
V_58 = F_128 ( V_5 , V_145 ) ;
if ( V_58 ) {
F_137 ( V_5 -> V_128 ) ;
return V_58 ;
}
for ( V_41 = 0 ; V_41 < V_27 ; V_41 ++ )
F_138 ( V_5 , V_41 ) -> V_31 =
V_145 [ V_41 ] . V_147 ;
} else {
V_5 -> V_150 = V_155 ;
F_50 ( V_5 , V_39 , V_5 -> V_17 ,
L_47 ) ;
}
}
if ( V_5 -> V_150 == V_155 ) {
V_5 -> V_27 = 1 ;
V_5 -> V_18 = 1 ;
V_5 -> V_154 = 1 ;
V_58 = F_139 ( V_5 -> V_128 ) ;
if ( V_58 == 0 ) {
F_138 ( V_5 , 0 ) -> V_31 = V_5 -> V_128 -> V_31 ;
} else {
F_50 ( V_5 , V_39 , V_5 -> V_17 ,
L_48 ) ;
V_5 -> V_150 = V_156 ;
}
}
if ( V_5 -> V_150 == V_156 ) {
V_5 -> V_27 = 1 + ( V_152 ? 1 : 0 ) ;
V_5 -> V_18 = 1 ;
V_5 -> V_154 = 1 ;
V_5 -> V_29 = V_5 -> V_128 -> V_31 ;
}
return 0 ;
}
static void F_140 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
F_48 (channel, efx)
V_2 -> V_31 = 0 ;
F_141 ( V_5 -> V_128 ) ;
F_137 ( V_5 -> V_128 ) ;
V_5 -> V_29 = 0 ;
}
static void F_142 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_45 * V_46 ;
V_5 -> V_157 =
V_152 ? V_5 -> V_27 - V_5 -> V_154 : 0 ;
F_48 (channel, efx) {
F_41 (tx_queue, channel)
V_46 -> V_55 -= ( V_5 -> V_157 *
V_53 ) ;
}
}
static int F_143 ( struct V_4 * V_5 )
{
T_5 V_41 ;
int V_58 ;
F_25 ( V_5 , V_34 , V_5 -> V_17 , L_49 ) ;
V_58 = V_5 -> type -> V_34 ( V_5 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_133 ( V_5 ) ;
if ( V_58 )
goto V_67;
if ( V_5 -> V_27 > 1 )
F_144 ( & V_5 -> V_158 , sizeof( V_5 -> V_158 ) ) ;
for ( V_41 = 0 ; V_41 < F_145 ( V_5 -> V_159 ) ; V_41 ++ )
V_5 -> V_159 [ V_41 ] = V_41 % V_5 -> V_18 ;
F_142 ( V_5 ) ;
F_146 ( V_5 -> V_17 , V_5 -> V_154 ) ;
F_147 ( V_5 -> V_17 , V_5 -> V_18 ) ;
F_148 ( V_5 , V_160 , V_161 , true ) ;
return 0 ;
V_67:
V_5 -> type -> remove ( V_5 ) ;
return V_58 ;
}
static void F_149 ( struct V_4 * V_5 )
{
F_25 ( V_5 , V_39 , V_5 -> V_17 , L_50 ) ;
F_140 ( V_5 ) ;
V_5 -> type -> remove ( V_5 ) ;
}
static int F_150 ( struct V_4 * V_5 )
{
int V_58 ;
V_58 = F_143 ( V_5 ) ;
if ( V_58 ) {
F_50 ( V_5 , V_34 , V_5 -> V_17 , L_51 ) ;
goto V_59;
}
V_58 = F_96 ( V_5 ) ;
if ( V_58 ) {
F_50 ( V_5 , V_34 , V_5 -> V_17 , L_52 ) ;
goto V_60;
}
V_5 -> V_35 = V_5 -> V_36 = V_162 ;
V_58 = F_49 ( V_5 ) ;
if ( V_58 )
goto V_61;
V_58 = F_151 ( V_5 ) ;
if ( V_58 ) {
F_50 ( V_5 , V_34 , V_5 -> V_17 ,
L_53 ) ;
goto V_138;
}
return 0 ;
V_138:
F_51 ( V_5 ) ;
V_61:
F_103 ( V_5 ) ;
V_60:
F_149 ( V_5 ) ;
V_59:
return V_58 ;
}
static void F_74 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
F_61 ( V_5 ) ;
if ( V_5 -> V_78 )
return;
if ( ( V_5 -> V_163 != V_164 ) && ( V_5 -> V_163 != V_165 ) )
return;
if ( F_88 ( V_5 ) && ! F_79 ( V_5 -> V_17 ) )
return;
F_100 ( V_5 ) ;
if ( F_88 ( V_5 ) && F_152 ( V_5 -> V_17 ) )
F_153 ( V_5 -> V_17 ) ;
F_48 (channel, efx)
F_58 ( V_2 ) ;
if ( V_5 -> V_29 )
V_5 -> V_30 = true ;
F_23 ( V_5 ) ;
F_154 ( V_5 ) ;
if ( V_5 -> V_7 != V_8 )
F_155 ( V_5 ) ;
if ( V_5 -> type -> V_166 != NULL ) {
F_156 ( V_5 -> V_167 , & V_5 -> V_168 ,
V_169 ) ;
} else {
F_93 ( & V_5 -> V_105 ) ;
if ( V_5 -> V_124 -> V_170 ( V_5 ) )
F_78 ( V_5 ) ;
F_94 ( & V_5 -> V_105 ) ;
}
V_5 -> type -> V_171 ( V_5 ) ;
}
static void F_157 ( struct V_4 * V_5 )
{
F_158 ( & V_5 -> V_168 ) ;
F_159 ( & V_5 -> V_110 ) ;
}
static void F_70 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
F_61 ( V_5 ) ;
if ( ! V_5 -> V_78 )
return;
V_5 -> type -> V_172 ( V_5 ) ;
F_155 ( V_5 ) ;
F_19 ( V_5 ) ;
if ( V_5 -> V_29 ) {
F_20 ( V_5 -> V_29 ) ;
V_5 -> V_30 = false ;
}
F_48 (channel, efx) {
if ( V_2 -> V_31 )
F_20 ( V_2 -> V_31 ) ;
}
F_48 (channel, efx)
F_59 ( V_2 ) ;
F_101 ( V_5 ) ;
F_157 ( V_5 ) ;
if ( F_88 ( V_5 ) ) {
F_160 ( V_5 -> V_17 ) ;
F_161 ( V_5 -> V_17 ) ;
F_162 ( V_5 -> V_17 ) ;
}
}
static void F_163 ( struct V_4 * V_5 )
{
F_164 ( V_5 ) ;
F_51 ( V_5 ) ;
F_103 ( V_5 ) ;
F_149 ( V_5 ) ;
}
static unsigned F_165 ( int V_173 , int V_174 )
{
if ( V_173 <= 0 )
return 0 ;
if ( V_173 < V_174 )
return 1 ;
return V_173 / V_174 ;
}
void F_148 ( struct V_4 * V_5 , int V_175 , int V_176 ,
bool V_177 )
{
struct V_1 * V_2 ;
unsigned V_178 = F_165 ( V_175 , V_179 ) ;
unsigned V_180 = F_165 ( V_176 , V_179 ) ;
F_61 ( V_5 ) ;
V_5 -> V_19 = V_177 ;
V_5 -> V_26 = V_180 ;
F_48 (channel, efx) {
if ( F_166 ( V_2 ) )
V_2 -> V_23 = V_180 ;
else if ( F_167 ( V_2 ) )
V_2 -> V_23 = V_178 ;
}
}
static void F_168 ( struct V_108 * V_109 )
{
struct V_4 * V_5 = F_12 ( V_109 , struct V_4 ,
V_168 . V_181 ) ;
F_13 ( V_5 , V_182 , V_5 -> V_17 ,
L_54 ,
F_14 () ) ;
F_18 ( V_5 -> type -> V_166 == NULL ) ;
if ( F_169 ( & V_5 -> V_105 ) ) {
if ( V_5 -> V_78 )
V_5 -> type -> V_166 ( V_5 ) ;
F_94 ( & V_5 -> V_105 ) ;
}
F_156 ( V_5 -> V_167 , & V_5 -> V_168 ,
V_169 ) ;
}
static int F_170 ( struct V_183 * V_17 , struct V_184 * V_185 , int V_186 )
{
struct V_4 * V_5 = F_171 ( V_17 ) ;
struct V_187 * V_109 = F_172 ( V_185 ) ;
F_61 ( V_5 ) ;
if ( ( V_186 == V_188 || V_186 == V_189 ) &&
( V_109 -> V_190 & 0xfc00 ) == 0x0400 )
V_109 -> V_190 ^= V_191 | 0x0400 ;
return F_173 ( & V_5 -> V_192 , V_109 , V_186 ) ;
}
static void F_71 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
F_48 (channel, efx) {
V_2 -> V_49 = V_5 -> V_17 ;
F_174 ( V_2 -> V_49 , & V_2 -> V_15 ,
F_11 , V_193 ) ;
}
}
static void F_72 ( struct V_1 * V_2 )
{
if ( V_2 -> V_49 )
F_175 ( & V_2 -> V_15 ) ;
V_2 -> V_49 = NULL ;
}
static void F_176 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
F_48 (channel, efx)
F_72 ( V_2 ) ;
}
static void F_177 ( struct V_183 * V_17 )
{
struct V_4 * V_5 = F_171 ( V_17 ) ;
struct V_1 * V_2 ;
F_48 (channel, efx)
F_178 ( V_2 ) ;
}
static int F_179 ( struct V_183 * V_17 )
{
struct V_4 * V_5 = F_171 ( V_17 ) ;
F_61 ( V_5 ) ;
F_25 ( V_5 , V_76 , V_5 -> V_17 , L_55 ,
F_14 () ) ;
if ( V_5 -> V_163 == V_194 )
return - V_134 ;
if ( V_5 -> V_104 & V_116 )
return - V_195 ;
if ( F_180 ( V_5 ) && F_181 ( V_5 , V_79 ) )
return - V_134 ;
F_78 ( V_5 ) ;
F_74 ( V_5 ) ;
return 0 ;
}
static int F_182 ( struct V_183 * V_17 )
{
struct V_4 * V_5 = F_171 ( V_17 ) ;
F_25 ( V_5 , V_77 , V_5 -> V_17 , L_56 ,
F_14 () ) ;
if ( V_5 -> V_163 != V_194 ) {
F_70 ( V_5 ) ;
F_60 ( V_5 ) ;
F_52 ( V_5 ) ;
}
return 0 ;
}
static struct V_196 * F_183 ( struct V_183 * V_17 , struct V_196 * V_197 )
{
struct V_4 * V_5 = F_171 ( V_17 ) ;
struct V_198 * V_199 = & V_5 -> V_199 ;
F_184 ( & V_5 -> V_200 ) ;
V_5 -> type -> V_201 ( V_5 ) ;
F_185 ( & V_5 -> V_200 ) ;
V_197 -> V_202 = V_199 -> V_202 ;
V_197 -> V_203 = V_199 -> V_203 ;
V_197 -> V_204 = V_199 -> V_204 ;
V_197 -> V_205 = V_199 -> V_205 ;
V_197 -> V_206 = V_5 -> V_207 ;
V_197 -> V_208 = V_199 -> V_209 ;
V_197 -> V_210 = V_199 -> V_211 ;
V_197 -> V_212 = ( V_199 -> V_213 +
V_199 -> V_214 ) ;
V_197 -> V_215 = V_199 -> V_216 ;
V_197 -> V_217 = V_199 -> V_218 ;
V_197 -> V_219 = V_199 -> V_220 ;
V_197 -> V_221 = V_199 -> V_222 ;
V_197 -> V_223 = V_199 -> V_224 ;
V_197 -> V_225 = ( V_197 -> V_212 +
V_197 -> V_215 +
V_197 -> V_217 +
V_199 -> V_226 ) ;
V_197 -> V_227 = ( V_197 -> V_223 +
V_199 -> V_228 ) ;
return V_197 ;
}
static void F_186 ( struct V_183 * V_17 )
{
struct V_4 * V_5 = F_171 ( V_17 ) ;
F_50 ( V_5 , V_229 , V_5 -> V_17 ,
L_57 ,
V_5 -> V_78 ) ;
F_64 ( V_5 , V_230 ) ;
}
static int F_187 ( struct V_183 * V_17 , int V_231 )
{
struct V_4 * V_5 = F_171 ( V_17 ) ;
int V_58 = 0 ;
F_61 ( V_5 ) ;
if ( V_231 > V_232 )
return - V_121 ;
F_70 ( V_5 ) ;
F_25 ( V_5 , V_39 , V_5 -> V_17 , L_58 , V_231 ) ;
F_60 ( V_5 ) ;
F_93 ( & V_5 -> V_105 ) ;
V_17 -> V_71 = V_231 ;
V_5 -> V_112 -> V_113 ( V_5 ) ;
F_94 ( & V_5 -> V_105 ) ;
F_52 ( V_5 ) ;
F_74 ( V_5 ) ;
return V_58 ;
}
static int F_188 ( struct V_183 * V_17 , void * V_109 )
{
struct V_4 * V_5 = F_171 ( V_17 ) ;
struct V_233 * V_234 = V_109 ;
char * V_235 = V_234 -> V_236 ;
F_61 ( V_5 ) ;
if ( ! F_97 ( V_235 ) ) {
F_50 ( V_5 , V_39 , V_5 -> V_17 ,
L_59 ,
V_235 ) ;
return - V_121 ;
}
memcpy ( V_17 -> V_118 , V_235 , V_17 -> V_237 ) ;
F_93 ( & V_5 -> V_105 ) ;
V_5 -> V_112 -> V_113 ( V_5 ) ;
F_94 ( & V_5 -> V_105 ) ;
return 0 ;
}
static void F_189 ( struct V_183 * V_17 )
{
struct V_4 * V_5 = F_171 ( V_17 ) ;
struct V_238 * V_239 ;
union V_240 * V_241 = & V_5 -> V_242 ;
T_1 V_243 ;
int V_244 ;
V_5 -> V_95 = ! ! ( V_17 -> V_245 & V_246 ) ;
if ( V_5 -> V_95 || ( V_17 -> V_245 & V_247 ) ) {
memset ( V_241 , 0xff , sizeof( * V_241 ) ) ;
} else {
memset ( V_241 , 0x00 , sizeof( * V_241 ) ) ;
F_190 (ha, net_dev) {
V_243 = F_191 ( V_119 , V_239 -> V_234 ) ;
V_244 = V_243 & ( V_248 - 1 ) ;
F_192 ( V_244 , V_241 -> V_249 ) ;
}
F_192 ( 0xff , V_241 -> V_249 ) ;
}
if ( V_5 -> V_78 )
F_193 ( V_5 -> V_167 , & V_5 -> V_110 ) ;
}
static int F_194 ( struct V_183 * V_17 , T_1 V_109 )
{
struct V_4 * V_5 = F_171 ( V_17 ) ;
if ( V_17 -> V_250 & ~ V_109 & V_251 )
F_195 ( V_5 , V_252 ) ;
return 0 ;
}
static void F_196 ( struct V_4 * V_5 )
{
strcpy ( V_5 -> V_65 , V_5 -> V_17 -> V_65 ) ;
F_197 ( V_5 ) ;
F_47 ( V_5 ) ;
}
static int F_198 ( struct V_253 * V_254 ,
unsigned long V_255 , void * V_256 )
{
struct V_183 * V_17 = V_256 ;
if ( V_17 -> V_257 == & V_258 &&
V_255 == V_259 )
F_196 ( F_171 ( V_17 ) ) ;
return V_260 ;
}
static T_6
F_199 ( struct V_261 * V_262 , struct V_263 * V_264 , char * V_265 )
{
struct V_4 * V_5 = F_200 ( F_201 ( V_262 ) ) ;
return sprintf ( V_265 , L_60 , V_5 -> V_266 ) ;
}
static int F_202 ( struct V_4 * V_5 )
{
struct V_183 * V_17 = V_5 -> V_17 ;
struct V_1 * V_2 ;
int V_58 ;
V_17 -> V_267 = 5 * V_268 ;
V_17 -> V_31 = V_5 -> V_128 -> V_31 ;
V_17 -> V_257 = & V_258 ;
F_203 ( V_17 , & V_269 ) ;
V_5 -> V_112 -> V_201 ( V_5 ) ;
memset ( & V_5 -> V_199 , 0 , sizeof( V_5 -> V_199 ) ) ;
F_204 () ;
V_58 = F_205 ( V_17 , V_17 -> V_65 ) ;
if ( V_58 < 0 )
goto V_270;
F_196 ( V_5 ) ;
V_58 = F_206 ( V_17 ) ;
if ( V_58 )
goto V_270;
F_48 (channel, efx) {
struct V_45 * V_46 ;
F_41 (tx_queue, channel)
F_207 ( V_46 ) ;
}
F_82 ( V_5 -> V_17 ) ;
F_208 () ;
V_58 = F_209 ( & V_5 -> V_128 -> V_262 , & V_271 ) ;
if ( V_58 ) {
F_50 ( V_5 , V_39 , V_5 -> V_17 ,
L_61 ) ;
goto V_272;
}
return 0 ;
V_270:
F_208 () ;
F_50 ( V_5 , V_39 , V_5 -> V_17 , L_62 ) ;
return V_58 ;
V_272:
F_210 ( V_17 ) ;
return V_58 ;
}
static void F_211 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_45 * V_46 ;
if ( ! V_5 -> V_17 )
return;
F_18 ( F_171 ( V_5 -> V_17 ) != V_5 ) ;
F_48 (channel, efx) {
F_41 (tx_queue, channel)
F_212 ( V_46 ) ;
}
if ( F_88 ( V_5 ) ) {
F_213 ( V_5 -> V_65 , F_214 ( V_5 -> V_128 ) , sizeof( V_5 -> V_65 ) ) ;
F_215 ( & V_5 -> V_128 -> V_262 , & V_271 ) ;
F_210 ( V_5 -> V_17 ) ;
}
}
void F_216 ( struct V_4 * V_5 , enum V_273 V_274 )
{
F_61 ( V_5 ) ;
F_70 ( V_5 ) ;
F_93 ( & V_5 -> V_105 ) ;
F_60 ( V_5 ) ;
if ( V_5 -> V_126 && V_274 != V_275 )
V_5 -> V_124 -> V_127 ( V_5 ) ;
V_5 -> type -> V_127 ( V_5 ) ;
}
int F_217 ( struct V_4 * V_5 , enum V_273 V_274 , bool V_276 )
{
int V_58 ;
F_61 ( V_5 ) ;
V_58 = V_5 -> type -> V_125 ( V_5 ) ;
if ( V_58 ) {
F_50 ( V_5 , V_39 , V_5 -> V_17 , L_63 ) ;
goto V_67;
}
if ( ! V_276 )
goto V_67;
if ( V_5 -> V_126 && V_274 != V_275 ) {
V_58 = V_5 -> V_124 -> V_125 ( V_5 ) ;
if ( V_58 )
goto V_67;
if ( V_5 -> V_124 -> V_113 ( V_5 ) )
F_50 ( V_5 , V_39 , V_5 -> V_17 ,
L_64 ) ;
}
V_5 -> V_112 -> V_113 ( V_5 ) ;
F_52 ( V_5 ) ;
F_218 ( V_5 ) ;
F_94 ( & V_5 -> V_105 ) ;
F_74 ( V_5 ) ;
return 0 ;
V_67:
V_5 -> V_126 = false ;
F_94 ( & V_5 -> V_105 ) ;
return V_58 ;
}
int F_181 ( struct V_4 * V_5 , enum V_273 V_274 )
{
int V_58 , V_277 ;
bool V_278 ;
F_83 ( V_5 , V_39 , V_5 -> V_17 , L_65 ,
F_219 ( V_274 ) ) ;
F_220 ( V_5 -> V_17 ) ;
F_216 ( V_5 , V_274 ) ;
V_58 = V_5 -> type -> V_279 ( V_5 , V_274 ) ;
if ( V_58 ) {
F_50 ( V_5 , V_39 , V_5 -> V_17 , L_66 ) ;
goto V_85;
}
V_5 -> V_7 = V_8 ;
F_106 ( V_5 -> V_128 ) ;
V_85:
V_278 = V_58 || V_274 == V_280 ;
V_277 = F_217 ( V_5 , V_274 , ! V_278 ) ;
if ( V_277 ) {
V_278 = true ;
if ( ! V_58 )
V_58 = V_277 ;
}
if ( V_278 ) {
F_221 ( V_5 -> V_17 ) ;
F_50 ( V_5 , V_39 , V_5 -> V_17 , L_67 ) ;
V_5 -> V_163 = V_194 ;
} else {
F_25 ( V_5 , V_39 , V_5 -> V_17 , L_68 ) ;
F_222 ( V_5 -> V_17 ) ;
}
return V_58 ;
}
static void F_223 ( struct V_108 * V_109 )
{
struct V_4 * V_5 = F_12 ( V_109 , struct V_4 , V_281 ) ;
if ( V_5 -> V_7 == V_8 )
return;
if ( V_5 -> V_163 != V_164 ) {
F_83 ( V_5 , V_39 , V_5 -> V_17 ,
L_69 ) ;
return;
}
F_204 () ;
( void ) F_181 ( V_5 , V_5 -> V_7 ) ;
F_208 () ;
}
void F_64 ( struct V_4 * V_5 , enum V_273 type )
{
enum V_273 V_274 ;
if ( V_5 -> V_7 != V_8 ) {
F_83 ( V_5 , V_39 , V_5 -> V_17 ,
L_70 ) ;
return;
}
switch ( type ) {
case V_275 :
case V_79 :
case V_282 :
case V_280 :
V_274 = type ;
break;
case V_283 :
case V_284 :
case V_285 :
case V_286 :
V_274 = V_275 ;
break;
case V_287 :
default:
V_274 = V_79 ;
break;
}
if ( V_274 != type )
F_25 ( V_5 , V_39 , V_5 -> V_17 ,
L_71 ,
F_219 ( V_274 ) , F_219 ( type ) ) ;
else
F_25 ( V_5 , V_39 , V_5 -> V_17 , L_72 ,
F_219 ( V_274 ) ) ;
V_5 -> V_7 = V_274 ;
F_155 ( V_5 ) ;
F_193 ( V_288 , & V_5 -> V_281 ) ;
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
static int F_227 ( struct V_4 * V_5 , const struct V_289 * type ,
struct V_128 * V_128 , struct V_183 * V_17 )
{
int V_41 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
F_228 ( & V_5 -> V_290 ) ;
#ifdef F_229
F_230 ( & V_5 -> V_291 ) ;
#endif
F_231 ( & V_5 -> V_281 , F_223 ) ;
F_232 ( & V_5 -> V_168 , F_168 ) ;
V_5 -> V_128 = V_128 ;
V_5 -> V_292 = V_293 ;
V_5 -> V_163 = V_165 ;
V_5 -> V_7 = V_8 ;
F_213 ( V_5 -> V_65 , F_214 ( V_128 ) , sizeof( V_5 -> V_65 ) ) ;
V_5 -> V_17 = V_17 ;
F_228 ( & V_5 -> V_200 ) ;
F_233 ( & V_5 -> V_105 ) ;
V_5 -> V_112 = type -> V_294 ;
V_5 -> V_124 = & V_295 ;
V_5 -> V_192 . V_262 = V_17 ;
F_231 ( & V_5 -> V_110 , F_95 ) ;
for ( V_41 = 0 ; V_41 < V_81 ; V_41 ++ ) {
V_5 -> V_2 [ V_41 ] = F_36 ( V_5 , V_41 , NULL ) ;
if ( ! V_5 -> V_2 [ V_41 ] )
goto V_67;
}
V_5 -> type = type ;
F_27 ( V_5 -> type -> V_149 > V_81 ) ;
V_5 -> V_150 = F_28 ( V_5 -> type -> V_296 ,
V_150 ) ;
snprintf ( V_5 -> V_297 , sizeof( V_5 -> V_297 ) , L_73 ,
F_214 ( V_128 ) ) ;
V_5 -> V_167 = F_234 ( V_5 -> V_297 ) ;
if ( ! V_5 -> V_167 )
goto V_67;
return 0 ;
V_67:
F_235 ( V_5 ) ;
return - V_84 ;
}
static void F_235 ( struct V_4 * V_5 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_81 ; V_41 ++ )
F_73 ( V_5 -> V_2 [ V_41 ] ) ;
if ( V_5 -> V_167 ) {
F_236 ( V_5 -> V_167 ) ;
V_5 -> V_167 = NULL ;
}
}
static void F_237 ( struct V_4 * V_5 )
{
#ifdef F_129
F_132 ( V_5 -> V_17 -> V_146 ) ;
V_5 -> V_17 -> V_146 = NULL ;
#endif
F_238 ( V_5 ) ;
F_60 ( V_5 ) ;
F_102 ( V_5 ) ;
V_5 -> type -> V_127 ( V_5 ) ;
F_176 ( V_5 ) ;
F_163 ( V_5 ) ;
}
static void F_239 ( struct V_128 * V_128 )
{
struct V_4 * V_5 ;
V_5 = F_200 ( V_128 ) ;
if ( ! V_5 )
return;
F_204 () ;
V_5 -> V_163 = V_298 ;
F_221 ( V_5 -> V_17 ) ;
F_208 () ;
F_211 ( V_5 ) ;
F_240 ( V_5 ) ;
F_159 ( & V_5 -> V_281 ) ;
F_237 ( V_5 ) ;
F_118 ( V_5 ) ;
F_25 ( V_5 , V_39 , V_5 -> V_17 , L_74 ) ;
F_241 ( V_128 , NULL ) ;
F_235 ( V_5 ) ;
F_242 ( V_5 -> V_17 ) ;
}
static int F_243 ( struct V_4 * V_5 )
{
int V_58 ;
V_58 = F_150 ( V_5 ) ;
if ( V_58 )
goto V_59;
F_71 ( V_5 ) ;
V_58 = V_5 -> type -> V_125 ( V_5 ) ;
if ( V_58 ) {
F_50 ( V_5 , V_34 , V_5 -> V_17 ,
L_63 ) ;
goto V_61;
}
V_58 = F_99 ( V_5 ) ;
if ( V_58 ) {
F_50 ( V_5 , V_34 , V_5 -> V_17 ,
L_75 ) ;
goto V_138;
}
F_52 ( V_5 ) ;
V_58 = F_244 ( V_5 ) ;
if ( V_58 )
goto V_299;
return 0 ;
V_299:
F_60 ( V_5 ) ;
F_102 ( V_5 ) ;
V_138:
V_5 -> type -> V_127 ( V_5 ) ;
V_61:
F_176 ( V_5 ) ;
F_163 ( V_5 ) ;
V_59:
return V_58 ;
}
static int T_7 F_245 ( struct V_128 * V_128 ,
const struct V_300 * V_153 )
{
const struct V_289 * type = ( const struct V_289 * ) V_153 -> V_301 ;
struct V_183 * V_17 ;
struct V_4 * V_5 ;
int V_41 , V_58 ;
V_17 = F_246 ( sizeof( * V_5 ) , V_302 ,
V_303 ) ;
if ( ! V_17 )
return - V_84 ;
V_17 -> V_250 |= ( type -> V_304 | V_305 |
V_306 | V_307 |
V_308 ) ;
if ( type -> V_304 & V_309 )
V_17 -> V_250 |= V_310 ;
V_17 -> V_311 |= ( V_312 | V_305 |
V_306 | V_313 |
V_308 ) ;
V_17 -> V_314 = V_17 -> V_250 & ~ V_306 ;
V_5 = F_171 ( V_17 ) ;
F_241 ( V_128 , V_5 ) ;
F_247 ( V_17 , & V_128 -> V_262 ) ;
V_58 = F_227 ( V_5 , type , V_128 , V_17 ) ;
if ( V_58 )
goto V_59;
F_83 ( V_5 , V_34 , V_5 -> V_17 ,
L_76 ) ;
V_58 = F_104 ( V_5 ) ;
if ( V_58 )
goto V_60;
for ( V_41 = 0 ; V_41 < 5 ; V_41 ++ ) {
V_58 = F_243 ( V_5 ) ;
F_159 ( & V_5 -> V_281 ) ;
if ( V_58 == 0 ) {
if ( V_5 -> V_7 != V_8 ) {
F_237 ( V_5 ) ;
V_58 = - V_134 ;
} else {
break;
}
}
if ( ( V_5 -> V_7 != V_275 ) &&
( V_5 -> V_7 != V_79 ) )
goto V_61;
V_5 -> V_7 = V_8 ;
}
if ( V_58 ) {
F_50 ( V_5 , V_34 , V_5 -> V_17 , L_77 ) ;
goto V_138;
}
V_5 -> V_163 = V_164 ;
V_58 = F_202 ( V_5 ) ;
if ( V_58 )
goto V_299;
F_25 ( V_5 , V_34 , V_5 -> V_17 , L_78 ) ;
F_204 () ;
F_248 ( V_5 ) ;
F_208 () ;
return 0 ;
V_299:
F_237 ( V_5 ) ;
V_138:
V_61:
F_118 ( V_5 ) ;
V_60:
F_235 ( V_5 ) ;
V_59:
F_57 ( V_58 > 0 ) ;
F_25 ( V_5 , V_39 , V_5 -> V_17 , L_79 , V_58 ) ;
F_242 ( V_17 ) ;
return V_58 ;
}
static int F_249 ( struct V_261 * V_262 )
{
struct V_4 * V_5 = F_200 ( F_201 ( V_262 ) ) ;
V_5 -> V_163 = V_298 ;
F_220 ( V_5 -> V_17 ) ;
F_70 ( V_5 ) ;
F_60 ( V_5 ) ;
return 0 ;
}
static int F_250 ( struct V_261 * V_262 )
{
struct V_4 * V_5 = F_200 ( F_201 ( V_262 ) ) ;
V_5 -> V_163 = V_165 ;
F_52 ( V_5 ) ;
F_93 ( & V_5 -> V_105 ) ;
V_5 -> V_124 -> V_113 ( V_5 ) ;
F_94 ( & V_5 -> V_105 ) ;
F_74 ( V_5 ) ;
F_222 ( V_5 -> V_17 ) ;
V_5 -> V_163 = V_164 ;
V_5 -> type -> V_315 ( V_5 ) ;
F_193 ( V_288 , & V_5 -> V_281 ) ;
return 0 ;
}
static int F_251 ( struct V_261 * V_262 )
{
struct V_128 * V_128 = F_201 ( V_262 ) ;
struct V_4 * V_5 = F_200 ( V_128 ) ;
V_5 -> type -> V_127 ( V_5 ) ;
V_5 -> V_7 = V_8 ;
F_252 ( V_128 ) ;
return F_253 ( V_128 , V_316 ) ;
}
static int F_254 ( struct V_261 * V_262 )
{
struct V_128 * V_128 = F_201 ( V_262 ) ;
struct V_4 * V_5 = F_200 ( V_128 ) ;
int V_58 ;
V_58 = F_253 ( V_128 , V_317 ) ;
if ( V_58 )
return V_58 ;
F_255 ( V_128 ) ;
V_58 = F_105 ( V_128 ) ;
if ( V_58 )
return V_58 ;
F_106 ( V_5 -> V_128 ) ;
V_58 = V_5 -> type -> V_279 ( V_5 , V_79 ) ;
if ( V_58 )
return V_58 ;
V_58 = V_5 -> type -> V_125 ( V_5 ) ;
if ( V_58 )
return V_58 ;
F_250 ( V_262 ) ;
return 0 ;
}
static int F_256 ( struct V_261 * V_262 )
{
int V_58 ;
F_249 ( V_262 ) ;
V_58 = F_251 ( V_262 ) ;
if ( V_58 )
F_254 ( V_262 ) ;
return V_58 ;
}
static int T_8 F_257 ( void )
{
int V_58 ;
F_122 ( V_318 L_80 V_319 L_81 ) ;
V_58 = F_258 ( & V_320 ) ;
if ( V_58 )
goto V_321;
V_288 = F_234 ( L_82 ) ;
if ( ! V_288 ) {
V_58 = - V_84 ;
goto V_322;
}
V_58 = F_259 ( & V_323 ) ;
if ( V_58 < 0 )
goto V_324;
return 0 ;
V_324:
F_236 ( V_288 ) ;
V_322:
F_260 ( & V_320 ) ;
V_321:
return V_58 ;
}
static void T_9 F_261 ( void )
{
F_122 ( V_318 L_83 ) ;
F_262 ( & V_323 ) ;
F_236 ( V_288 ) ;
F_260 ( & V_320 ) ;
}

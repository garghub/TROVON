static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
if ( F_2 ( ! V_2 -> V_5 ) )
return 0 ;
V_4 = F_3 ( V_2 , V_3 ) ;
if ( V_4 && F_4 ( V_2 ) ) {
struct V_6 * V_7 =
F_5 ( V_2 ) ;
if ( V_2 -> V_8 ) {
F_6 ( V_2 , V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
}
if ( V_7 -> V_5 ) {
F_7 ( V_2 ) ;
F_8 ( V_7 ) ;
}
}
return V_4 ;
}
static inline void F_9 ( struct V_1 * V_2 )
{
V_2 -> V_9 = false ;
F_10 () ;
F_11 ( V_2 ) ;
}
static int F_12 ( struct V_10 * V_11 , int V_3 )
{
struct V_1 * V_2 =
F_13 ( V_11 , struct V_1 , V_12 ) ;
struct V_13 * V_14 = V_2 -> V_14 ;
int V_4 ;
F_14 ( V_14 , V_15 , V_14 -> V_16 ,
L_1 ,
V_2 -> V_2 , F_15 () ) ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 < V_3 ) {
if ( F_4 ( V_2 ) &&
V_14 -> V_17 &&
F_2 ( ++ V_2 -> V_18 == 1000 ) ) {
if ( F_2 ( V_2 -> V_19 <
V_20 ) ) {
if ( V_2 -> V_21 > 1 ) {
V_2 -> V_21 -= 1 ;
V_14 -> type -> V_22 ( V_2 ) ;
}
} else if ( F_2 ( V_2 -> V_19 >
V_23 ) ) {
if ( V_2 -> V_21 <
V_14 -> V_24 ) {
V_2 -> V_21 += 1 ;
V_14 -> type -> V_22 ( V_2 ) ;
}
}
V_2 -> V_18 = 0 ;
V_2 -> V_19 = 0 ;
}
F_16 ( V_2 ) ;
F_17 ( V_11 ) ;
F_9 ( V_2 ) ;
}
return V_4 ;
}
void F_18 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_19 ( V_2 -> V_2 >= V_14 -> V_25 ) ;
F_19 ( ! V_2 -> V_5 ) ;
F_19 ( ! V_14 -> V_26 ) ;
F_20 ( V_14 ) ;
if ( V_14 -> V_27 ) {
F_21 ( V_14 -> V_27 ) ;
V_14 -> V_28 = false ;
}
if ( V_2 -> V_29 )
F_21 ( V_2 -> V_29 ) ;
F_22 ( & V_2 -> V_12 ) ;
F_1 ( V_2 , V_2 -> V_30 + 1 ) ;
F_9 ( V_2 ) ;
F_23 ( & V_2 -> V_12 ) ;
if ( V_14 -> V_27 )
V_14 -> V_28 = true ;
F_24 ( V_14 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
unsigned long V_31 ;
F_26 ( V_14 , V_32 , V_14 -> V_16 ,
L_2 , V_2 -> V_2 ) ;
V_31 = F_27 ( V_14 -> V_33 + V_14 -> V_34 + 128 ) ;
F_28 ( V_31 > V_35 ) ;
V_2 -> V_30 = F_29 ( V_31 , V_36 ) - 1 ;
return F_30 ( V_2 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_26 ( V_2 -> V_14 , V_37 , V_2 -> V_14 -> V_16 ,
L_3 , V_2 -> V_2 ) ;
V_2 -> V_38 = 0 ;
F_32 ( V_2 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_26 ( V_2 -> V_14 , V_39 , V_2 -> V_14 -> V_16 ,
L_4 , V_2 -> V_2 ) ;
V_2 -> V_9 = false ;
V_2 -> V_5 = true ;
F_10 () ;
F_23 ( & V_2 -> V_12 ) ;
F_11 ( V_2 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 )
return;
F_22 ( & V_2 -> V_12 ) ;
V_2 -> V_5 = false ;
}
static void F_35 ( struct V_1 * V_2 )
{
F_26 ( V_2 -> V_14 , V_37 , V_2 -> V_14 -> V_16 ,
L_5 , V_2 -> V_2 ) ;
F_36 ( V_2 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_26 ( V_2 -> V_14 , V_37 , V_2 -> V_14 -> V_16 ,
L_6 , V_2 -> V_2 ) ;
F_38 ( V_2 ) ;
}
static struct V_1 *
F_39 ( struct V_13 * V_14 , int V_40 , struct V_1 * V_41 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
struct V_42 * V_43 ;
int V_44 ;
V_2 = F_40 ( sizeof( * V_2 ) , V_45 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_14 = V_14 ;
V_2 -> V_2 = V_40 ;
V_2 -> type = & V_46 ;
for ( V_44 = 0 ; V_44 < V_47 ; V_44 ++ ) {
V_43 = & V_2 -> V_43 [ V_44 ] ;
V_43 -> V_14 = V_14 ;
V_43 -> V_48 = V_40 * V_47 + V_44 ;
V_43 -> V_2 = V_2 ;
}
V_7 = & V_2 -> V_7 ;
V_7 -> V_14 = V_14 ;
F_41 ( & V_7 -> V_49 , V_50 ,
( unsigned long ) V_7 ) ;
return V_2 ;
}
static struct V_1 *
F_42 ( const struct V_1 * V_41 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
struct V_42 * V_43 ;
int V_44 ;
V_2 = F_43 ( sizeof( * V_2 ) , V_45 ) ;
if ( ! V_2 )
return NULL ;
* V_2 = * V_41 ;
V_2 -> V_51 = NULL ;
memset ( & V_2 -> V_52 , 0 , sizeof( V_2 -> V_52 ) ) ;
for ( V_44 = 0 ; V_44 < V_47 ; V_44 ++ ) {
V_43 = & V_2 -> V_43 [ V_44 ] ;
if ( V_43 -> V_2 )
V_43 -> V_2 = V_2 ;
V_43 -> V_53 = NULL ;
memset ( & V_43 -> V_54 , 0 , sizeof( V_43 -> V_54 ) ) ;
}
V_7 = & V_2 -> V_7 ;
V_7 -> V_53 = NULL ;
memset ( & V_7 -> V_55 , 0 , sizeof( V_7 -> V_55 ) ) ;
F_41 ( & V_7 -> V_49 , V_50 ,
( unsigned long ) V_7 ) ;
return V_2 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_42 * V_43 ;
struct V_6 * V_7 ;
int V_56 ;
F_26 ( V_2 -> V_14 , V_32 , V_2 -> V_14 -> V_16 ,
L_7 , V_2 -> V_2 ) ;
V_56 = V_2 -> type -> V_57 ( V_2 ) ;
if ( V_56 )
goto V_58;
V_56 = F_25 ( V_2 ) ;
if ( V_56 )
goto V_58;
F_45 (tx_queue, channel) {
V_56 = F_46 ( V_43 ) ;
if ( V_56 )
goto V_58;
}
F_47 (rx_queue, channel) {
V_56 = F_48 ( V_7 ) ;
if ( V_56 )
goto V_58;
}
V_2 -> V_59 = 0 ;
return 0 ;
V_58:
F_49 ( V_2 ) ;
return V_56 ;
}
static void
F_50 ( struct V_1 * V_2 , char * V_60 , T_1 V_61 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
const char * type ;
int V_62 ;
V_62 = V_2 -> V_2 ;
if ( V_14 -> V_63 == 0 ) {
type = L_8 ;
} else if ( V_2 -> V_2 < V_14 -> V_63 ) {
type = L_9 ;
} else {
type = L_10 ;
V_62 -= V_14 -> V_63 ;
}
snprintf ( V_60 , V_61 , L_11 , V_14 -> V_64 , type , V_62 ) ;
}
static void F_51 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
F_52 (channel, efx)
V_2 -> type -> V_65 ( V_2 ,
V_14 -> V_66 [ V_2 -> V_2 ] ,
sizeof( V_14 -> V_66 [ 0 ] ) ) ;
}
static int F_53 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
int V_56 ;
V_14 -> V_67 = 0 ;
F_54 (channel, efx) {
V_56 = F_44 ( V_2 ) ;
if ( V_56 ) {
F_55 ( V_14 , V_32 , V_14 -> V_16 ,
L_12 ,
V_2 -> V_2 ) ;
goto V_58;
}
}
F_51 ( V_14 ) ;
return 0 ;
V_58:
F_56 ( V_14 ) ;
return V_56 ;
}
static void F_57 ( struct V_13 * V_14 )
{
struct V_42 * V_43 ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
V_14 -> V_68 = ( F_29 ( V_69 , V_70 ) +
F_58 ( V_14 -> V_16 -> V_71 ) +
V_14 -> type -> V_72 +
V_14 -> type -> V_73 ) ;
V_14 -> V_74 = F_59 ( V_14 -> V_68 +
sizeof( struct V_75 ) ) ;
F_52 (channel, efx) {
F_45 (tx_queue, channel)
F_60 ( V_43 ) ;
F_7 ( V_2 ) ;
F_47 (rx_queue, channel) {
F_61 ( V_7 ) ;
F_62 ( V_7 ) ;
}
F_63 ( V_2 -> V_8 != NULL ) ;
F_7 ( V_2 ) ;
}
if ( F_64 ( V_14 -> V_16 ) )
F_65 ( V_14 -> V_16 ) ;
}
static void F_66 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
struct V_42 * V_43 ;
struct V_6 * V_7 ;
int V_56 ;
F_67 ( V_14 ) ;
F_19 ( V_14 -> V_76 ) ;
V_56 = F_68 ( V_14 ) ;
if ( V_56 && F_69 ( V_14 ) ) {
F_55 ( V_14 , V_37 , V_14 -> V_16 ,
L_13 ) ;
F_70 ( V_14 , V_77 ) ;
} else if ( V_56 ) {
F_55 ( V_14 , V_37 , V_14 -> V_16 , L_14 ) ;
} else {
F_26 ( V_14 , V_37 , V_14 -> V_16 ,
L_15 ) ;
}
F_52 (channel, efx) {
if ( F_4 ( V_2 ) ) {
F_34 ( V_2 ) ;
F_33 ( V_2 ) ;
}
F_47 (rx_queue, channel)
F_71 ( V_7 ) ;
F_72 (tx_queue, channel)
F_73 ( V_43 ) ;
}
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_42 * V_43 ;
struct V_6 * V_7 ;
F_26 ( V_2 -> V_14 , V_37 , V_2 -> V_14 -> V_16 ,
L_16 , V_2 -> V_2 ) ;
F_47 (rx_queue, channel)
F_74 ( V_7 ) ;
F_72 (tx_queue, channel)
F_75 ( V_43 ) ;
F_37 ( V_2 ) ;
}
static void F_56 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
F_52 (channel, efx)
F_49 ( V_2 ) ;
}
int
F_76 ( struct V_13 * V_14 , T_2 V_33 , T_2 V_34 )
{
struct V_1 * V_78 [ V_79 ] , * V_2 ;
T_2 V_80 , V_81 ;
unsigned V_40 , V_67 = 0 ;
int V_56 = 0 ;
F_52 (channel, efx) {
struct V_6 * V_7 ;
struct V_42 * V_43 ;
if ( V_2 -> type -> V_82 )
continue;
V_67 = F_29 ( V_67 ,
V_2 -> V_52 . V_83 +
V_2 -> V_52 . V_31 ) ;
F_47 (rx_queue, channel)
V_67 = F_29 ( V_67 ,
V_7 -> V_55 . V_83 +
V_7 -> V_55 . V_31 ) ;
F_45 (tx_queue, channel)
V_67 = F_29 ( V_67 ,
V_43 -> V_54 . V_83 +
V_43 -> V_54 . V_31 ) ;
}
F_77 ( V_14 ) ;
F_78 ( V_14 , true ) ;
memset ( V_78 , 0 , sizeof( V_78 ) ) ;
for ( V_40 = 0 ; V_40 < V_14 -> V_25 ; V_40 ++ ) {
V_2 = V_14 -> V_2 [ V_40 ] ;
if ( V_2 -> type -> V_82 )
V_2 = V_2 -> type -> V_82 ( V_2 ) ;
if ( ! V_2 ) {
V_56 = - V_84 ;
goto V_85;
}
V_78 [ V_40 ] = V_2 ;
}
V_80 = V_14 -> V_33 ;
V_81 = V_14 -> V_34 ;
V_14 -> V_33 = V_33 ;
V_14 -> V_34 = V_34 ;
for ( V_40 = 0 ; V_40 < V_14 -> V_25 ; V_40 ++ ) {
V_2 = V_14 -> V_2 [ V_40 ] ;
V_14 -> V_2 [ V_40 ] = V_78 [ V_40 ] ;
V_78 [ V_40 ] = V_2 ;
}
V_14 -> V_67 = V_67 ;
for ( V_40 = 0 ; V_40 < V_14 -> V_25 ; V_40 ++ ) {
V_2 = V_14 -> V_2 [ V_40 ] ;
if ( ! V_2 -> type -> V_82 )
continue;
V_56 = F_44 ( V_2 ) ;
if ( V_56 )
goto V_86;
F_79 ( V_14 -> V_2 [ V_40 ] ) ;
}
V_85:
for ( V_40 = 0 ; V_40 < V_14 -> V_25 ; V_40 ++ ) {
V_2 = V_78 [ V_40 ] ;
if ( V_2 && V_2 -> type -> V_82 ) {
F_80 ( V_2 ) ;
F_49 ( V_2 ) ;
F_81 ( V_2 ) ;
}
}
F_82 ( V_14 , true ) ;
F_83 ( V_14 ) ;
return V_56 ;
V_86:
V_14 -> V_33 = V_80 ;
V_14 -> V_34 = V_81 ;
for ( V_40 = 0 ; V_40 < V_14 -> V_25 ; V_40 ++ ) {
V_2 = V_14 -> V_2 [ V_40 ] ;
V_14 -> V_2 [ V_40 ] = V_78 [ V_40 ] ;
V_78 [ V_40 ] = V_2 ;
}
goto V_85;
}
void F_84 ( struct V_6 * V_7 )
{
F_85 ( & V_7 -> V_49 , V_87 + F_86 ( 100 ) ) ;
}
int F_87 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_88 ( struct V_13 * V_14 )
{
struct V_88 * V_89 = & V_14 -> V_89 ;
if ( ! F_89 ( V_14 -> V_16 ) )
return;
if ( V_89 -> V_90 != F_90 ( V_14 -> V_16 ) ) {
V_14 -> V_91 ++ ;
if ( V_89 -> V_90 )
F_91 ( V_14 -> V_16 ) ;
else
F_92 ( V_14 -> V_16 ) ;
}
if ( V_89 -> V_90 )
F_93 ( V_14 , V_92 , V_14 -> V_16 ,
L_17 ,
V_89 -> V_93 , V_89 -> V_94 ? L_18 : L_19 ,
V_14 -> V_16 -> V_71 ,
( V_14 -> V_95 ? L_20 : L_8 ) ) ;
else
F_93 ( V_14 , V_92 , V_14 -> V_16 , L_21 ) ;
}
void F_94 ( struct V_13 * V_14 , T_2 V_96 )
{
V_14 -> V_97 = V_96 ;
if ( V_96 ) {
if ( V_96 & V_98 )
V_14 -> V_99 |= ( V_100 | V_101 ) ;
else
V_14 -> V_99 &= ~ ( V_100 | V_101 ) ;
if ( V_96 & V_102 )
V_14 -> V_99 ^= V_100 ;
}
}
void F_95 ( struct V_13 * V_14 , T_3 V_99 )
{
V_14 -> V_99 = V_99 ;
if ( V_14 -> V_97 ) {
if ( V_99 & V_101 )
V_14 -> V_97 |= ( V_98 |
V_102 ) ;
else
V_14 -> V_97 &= ~ ( V_98 |
V_102 ) ;
if ( V_99 & V_100 )
V_14 -> V_97 ^= V_102 ;
}
}
int F_96 ( struct V_13 * V_14 )
{
enum V_103 V_104 ;
int V_56 ;
F_63 ( ! F_97 ( & V_14 -> V_105 ) ) ;
F_98 ( V_14 -> V_16 ) ;
F_99 ( V_14 -> V_16 ) ;
V_104 = V_14 -> V_104 ;
if ( F_100 ( V_14 ) )
V_14 -> V_104 |= V_106 ;
else
V_14 -> V_104 &= ~ V_106 ;
V_56 = V_14 -> type -> V_107 ( V_14 ) ;
if ( V_56 )
V_14 -> V_104 = V_104 ;
return V_56 ;
}
int F_101 ( struct V_13 * V_14 )
{
int V_56 ;
F_67 ( V_14 ) ;
F_102 ( & V_14 -> V_105 ) ;
V_56 = F_96 ( V_14 ) ;
F_103 ( & V_14 -> V_105 ) ;
return V_56 ;
}
static void F_104 ( struct V_108 * V_109 )
{
struct V_13 * V_14 = F_13 ( V_109 , struct V_13 , V_110 ) ;
F_102 ( & V_14 -> V_105 ) ;
if ( V_14 -> V_76 )
V_14 -> type -> V_111 ( V_14 ) ;
F_103 ( & V_14 -> V_105 ) ;
}
static int F_105 ( struct V_13 * V_14 )
{
int V_56 ;
F_26 ( V_14 , V_32 , V_14 -> V_16 , L_22 ) ;
if ( V_112 )
V_14 -> V_104 = V_113 ;
V_56 = V_14 -> type -> V_114 ( V_14 ) ;
if ( V_56 )
return V_56 ;
memcpy ( V_14 -> V_16 -> V_115 , V_14 -> V_16 -> V_116 , V_117 ) ;
return 0 ;
}
static int F_106 ( struct V_13 * V_14 )
{
int V_56 ;
F_26 ( V_14 , V_37 , V_14 -> V_16 , L_23 ) ;
F_102 ( & V_14 -> V_105 ) ;
V_56 = V_14 -> V_118 -> V_119 ( V_14 ) ;
if ( V_56 )
goto V_120;
V_14 -> V_121 = true ;
V_14 -> type -> V_111 ( V_14 ) ;
V_56 = V_14 -> V_118 -> V_122 ( V_14 ) ;
if ( V_56 )
goto V_123;
F_103 ( & V_14 -> V_105 ) ;
return 0 ;
V_123:
V_14 -> V_118 -> V_124 ( V_14 ) ;
V_120:
F_103 ( & V_14 -> V_105 ) ;
return V_56 ;
}
static void F_107 ( struct V_13 * V_14 )
{
F_26 ( V_14 , V_39 , V_14 -> V_16 , L_24 ) ;
F_19 ( V_14 -> V_76 ) ;
F_102 ( & V_14 -> V_105 ) ;
V_14 -> V_76 = true ;
V_14 -> type -> V_111 ( V_14 ) ;
F_103 ( & V_14 -> V_105 ) ;
}
static void F_108 ( struct V_13 * V_14 )
{
F_26 ( V_14 , V_125 , V_14 -> V_16 , L_25 ) ;
F_102 ( & V_14 -> V_105 ) ;
V_14 -> V_76 = false ;
F_103 ( & V_14 -> V_105 ) ;
F_98 ( V_14 -> V_16 ) ;
F_99 ( V_14 -> V_16 ) ;
}
static void F_109 ( struct V_13 * V_14 )
{
F_26 ( V_14 , V_37 , V_14 -> V_16 , L_26 ) ;
if ( ! V_14 -> V_121 )
return;
V_14 -> V_118 -> V_124 ( V_14 ) ;
V_14 -> V_121 = false ;
V_14 -> V_89 . V_90 = false ;
F_88 ( V_14 ) ;
}
static void F_110 ( struct V_13 * V_14 )
{
F_26 ( V_14 , V_37 , V_14 -> V_16 , L_27 ) ;
V_14 -> type -> V_126 ( V_14 ) ;
}
static int F_111 ( struct V_13 * V_14 )
{
struct V_127 * V_127 = V_14 -> V_127 ;
T_4 V_128 = V_14 -> type -> V_129 ;
int V_56 ;
F_26 ( V_14 , V_32 , V_14 -> V_16 , L_28 ) ;
V_56 = F_112 ( V_127 ) ;
if ( V_56 ) {
F_55 ( V_14 , V_32 , V_14 -> V_16 ,
L_29 ) ;
goto V_120;
}
F_113 ( V_127 ) ;
while ( V_128 > 0x7fffffffUL ) {
if ( F_114 ( V_127 , V_128 ) ) {
V_56 = F_115 ( V_127 , V_128 ) ;
if ( V_56 == 0 )
break;
}
V_128 >>= 1 ;
}
if ( V_56 ) {
F_55 ( V_14 , V_32 , V_14 -> V_16 ,
L_30 ) ;
goto V_123;
}
F_26 ( V_14 , V_32 , V_14 -> V_16 ,
L_31 , ( unsigned long long ) V_128 ) ;
V_56 = F_116 ( V_127 , V_128 ) ;
if ( V_56 ) {
F_55 ( V_14 , V_32 , V_14 -> V_16 ,
L_32 ) ;
goto V_123;
}
V_14 -> V_130 = F_117 ( V_14 -> V_127 , V_131 ) ;
V_56 = F_118 ( V_127 , V_131 , L_33 ) ;
if ( V_56 ) {
F_55 ( V_14 , V_32 , V_14 -> V_16 ,
L_34 ) ;
V_56 = - V_132 ;
goto V_133;
}
V_14 -> V_134 = F_119 ( V_14 -> V_130 ,
V_14 -> type -> V_135 ) ;
if ( ! V_14 -> V_134 ) {
F_55 ( V_14 , V_32 , V_14 -> V_16 ,
L_35 ,
( unsigned long long ) V_14 -> V_130 ,
V_14 -> type -> V_135 ) ;
V_56 = - V_84 ;
goto V_136;
}
F_26 ( V_14 , V_32 , V_14 -> V_16 ,
L_36 ,
( unsigned long long ) V_14 -> V_130 ,
V_14 -> type -> V_135 , V_14 -> V_134 ) ;
return 0 ;
V_136:
F_120 ( V_14 -> V_127 , V_131 ) ;
V_133:
V_14 -> V_130 = 0 ;
V_123:
F_121 ( V_14 -> V_127 ) ;
V_120:
return V_56 ;
}
static void F_122 ( struct V_13 * V_14 )
{
F_26 ( V_14 , V_37 , V_14 -> V_16 , L_37 ) ;
if ( V_14 -> V_134 ) {
F_123 ( V_14 -> V_134 ) ;
V_14 -> V_134 = NULL ;
}
if ( V_14 -> V_130 ) {
F_120 ( V_14 -> V_127 , V_131 ) ;
V_14 -> V_130 = 0 ;
}
F_121 ( V_14 -> V_127 ) ;
}
static unsigned int F_124 ( struct V_13 * V_14 )
{
T_5 V_137 ;
unsigned int V_138 ;
int V_139 ;
if ( V_140 ) {
V_138 = V_140 ;
} else {
if ( F_2 ( ! F_125 ( & V_137 , V_45 ) ) ) {
F_126 ( V_14 , V_32 , V_14 -> V_16 ,
L_38 ) ;
return 1 ;
}
V_138 = 0 ;
F_127 (cpu) {
if ( ! F_128 ( V_139 , V_137 ) ) {
++ V_138 ;
F_129 ( V_137 , V_137 ,
F_130 ( V_139 ) ) ;
}
}
F_131 ( V_137 ) ;
}
if ( F_132 ( V_14 ) && F_133 ( V_14 ) > 1 &&
V_138 > F_133 ( V_14 ) ) {
F_126 ( V_14 , V_32 , V_14 -> V_16 ,
L_39
L_40
L_41 ,
V_138 , F_133 ( V_14 ) ) ;
V_138 = F_133 ( V_14 ) ;
}
return V_138 ;
}
static int
F_134 ( struct V_13 * V_14 , struct V_141 * V_142 )
{
#ifdef F_135
unsigned int V_40 ;
int V_56 ;
V_14 -> V_16 -> V_143 = F_136 ( V_14 -> V_144 ) ;
if ( ! V_14 -> V_16 -> V_143 )
return - V_84 ;
for ( V_40 = 0 ; V_40 < V_14 -> V_144 ; V_40 ++ ) {
V_56 = F_137 ( V_14 -> V_16 -> V_143 ,
V_142 [ V_40 ] . V_145 ) ;
if ( V_56 ) {
F_138 ( V_14 -> V_16 -> V_143 ) ;
V_14 -> V_16 -> V_143 = NULL ;
return V_56 ;
}
}
#endif
return 0 ;
}
static int F_139 ( struct V_13 * V_14 )
{
unsigned int V_146 =
F_140 ( V_14 -> type -> V_147 , V_79 ) ;
unsigned int V_148 = 0 ;
unsigned int V_40 , V_44 ;
int V_56 ;
for ( V_40 = 0 ; V_40 < V_149 ; V_40 ++ )
if ( V_14 -> V_150 [ V_40 ] )
++ V_148 ;
if ( V_14 -> V_151 == V_152 ) {
struct V_141 V_142 [ V_79 ] ;
unsigned int V_25 ;
V_25 = F_124 ( V_14 ) ;
if ( V_153 )
V_25 *= 2 ;
V_25 += V_148 ;
V_25 = F_140 ( V_25 , V_146 ) ;
for ( V_40 = 0 ; V_40 < V_25 ; V_40 ++ )
V_142 [ V_40 ] . V_154 = V_40 ;
V_56 = F_141 ( V_14 -> V_127 , V_142 , V_25 ) ;
if ( V_56 > 0 ) {
F_55 ( V_14 , V_37 , V_14 -> V_16 ,
L_42
L_43 , V_56 , V_25 ) ;
F_55 ( V_14 , V_37 , V_14 -> V_16 ,
L_44 ) ;
F_28 ( V_56 >= V_25 ) ;
V_25 = V_56 ;
V_56 = F_141 ( V_14 -> V_127 , V_142 ,
V_25 ) ;
}
if ( V_56 == 0 ) {
V_14 -> V_25 = V_25 ;
if ( V_25 > V_148 )
V_25 -= V_148 ;
if ( V_153 ) {
V_14 -> V_155 = F_29 ( V_25 / 2 , 1U ) ;
V_14 -> V_144 = F_29 ( V_25 -
V_14 -> V_155 ,
1U ) ;
} else {
V_14 -> V_155 = V_25 ;
V_14 -> V_144 = V_25 ;
}
V_56 = F_134 ( V_14 , V_142 ) ;
if ( V_56 ) {
F_142 ( V_14 -> V_127 ) ;
return V_56 ;
}
for ( V_40 = 0 ; V_40 < V_14 -> V_25 ; V_40 ++ )
F_143 ( V_14 , V_40 ) -> V_29 =
V_142 [ V_40 ] . V_145 ;
} else {
V_14 -> V_151 = V_156 ;
F_55 ( V_14 , V_37 , V_14 -> V_16 ,
L_45 ) ;
}
}
if ( V_14 -> V_151 == V_156 ) {
V_14 -> V_25 = 1 ;
V_14 -> V_144 = 1 ;
V_14 -> V_155 = 1 ;
V_56 = F_144 ( V_14 -> V_127 ) ;
if ( V_56 == 0 ) {
F_143 ( V_14 , 0 ) -> V_29 = V_14 -> V_127 -> V_29 ;
} else {
F_55 ( V_14 , V_37 , V_14 -> V_16 ,
L_46 ) ;
V_14 -> V_151 = V_157 ;
}
}
if ( V_14 -> V_151 == V_157 ) {
V_14 -> V_25 = 1 + ( V_153 ? 1 : 0 ) ;
V_14 -> V_144 = 1 ;
V_14 -> V_155 = 1 ;
V_14 -> V_27 = V_14 -> V_127 -> V_29 ;
}
V_44 = V_14 -> V_25 ;
for ( V_40 = 0 ; V_40 < V_149 ; V_40 ++ ) {
if ( ! V_14 -> V_150 [ V_40 ] )
continue;
if ( V_14 -> V_151 != V_152 ||
V_14 -> V_25 <= V_148 ) {
V_14 -> V_150 [ V_40 ] -> F_145 ( V_14 ) ;
} else {
-- V_44 ;
F_143 ( V_14 , V_44 ) -> type =
V_14 -> V_150 [ V_40 ] ;
}
}
V_14 -> V_158 = ( ( V_14 -> V_144 > 1 || ! F_132 ( V_14 ) ) ?
V_14 -> V_144 : F_133 ( V_14 ) ) ;
return 0 ;
}
static void F_82 ( struct V_13 * V_14 , bool V_159 )
{
struct V_1 * V_2 ;
if ( V_14 -> V_27 )
V_14 -> V_28 = true ;
F_24 ( V_14 ) ;
F_52 (channel, efx) {
if ( ! V_2 -> type -> V_160 || ! V_159 )
F_31 ( V_2 ) ;
F_33 ( V_2 ) ;
}
F_146 ( V_14 ) ;
}
static void F_78 ( struct V_13 * V_14 , bool V_159 )
{
struct V_1 * V_2 ;
F_147 ( V_14 ) ;
F_20 ( V_14 ) ;
if ( V_14 -> V_27 ) {
F_21 ( V_14 -> V_27 ) ;
V_14 -> V_28 = false ;
}
F_52 (channel, efx) {
if ( V_2 -> V_29 )
F_21 ( V_2 -> V_29 ) ;
F_34 ( V_2 ) ;
if ( ! V_2 -> type -> V_160 || ! V_159 )
F_35 ( V_2 ) ;
}
}
static void F_148 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
F_52 (channel, efx)
V_2 -> V_29 = 0 ;
F_149 ( V_14 -> V_127 ) ;
F_142 ( V_14 -> V_127 ) ;
V_14 -> V_27 = 0 ;
}
static void F_150 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
struct V_42 * V_43 ;
V_14 -> V_63 =
V_153 ? V_14 -> V_25 - V_14 -> V_155 : 0 ;
F_52 (channel, efx) {
F_45 (tx_queue, channel)
V_43 -> V_48 -= ( V_14 -> V_63 *
V_47 ) ;
}
}
static int F_151 ( struct V_13 * V_14 )
{
T_1 V_40 ;
int V_56 ;
F_26 ( V_14 , V_32 , V_14 -> V_16 , L_47 ) ;
V_56 = V_14 -> type -> V_32 ( V_14 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_139 ( V_14 ) ;
if ( V_56 )
goto V_58;
V_14 -> type -> V_161 ( V_14 ) ;
if ( V_14 -> V_25 > 1 )
F_152 ( & V_14 -> V_162 , sizeof( V_14 -> V_162 ) ) ;
for ( V_40 = 0 ; V_40 < F_153 ( V_14 -> V_163 ) ; V_40 ++ )
V_14 -> V_163 [ V_40 ] =
F_154 ( V_40 , V_14 -> V_158 ) ;
F_150 ( V_14 ) ;
F_155 ( V_14 -> V_16 , V_14 -> V_155 ) ;
F_156 ( V_14 -> V_16 , V_14 -> V_144 ) ;
F_157 ( V_14 , V_164 , V_165 , true ,
true ) ;
return 0 ;
V_58:
V_14 -> type -> remove ( V_14 ) ;
return V_56 ;
}
static void F_158 ( struct V_13 * V_14 )
{
F_26 ( V_14 , V_37 , V_14 -> V_16 , L_48 ) ;
F_148 ( V_14 ) ;
V_14 -> type -> remove ( V_14 ) ;
}
static int F_159 ( struct V_13 * V_14 )
{
int V_56 ;
V_56 = F_151 ( V_14 ) ;
if ( V_56 ) {
F_55 ( V_14 , V_32 , V_14 -> V_16 , L_49 ) ;
goto V_120;
}
V_56 = F_105 ( V_14 ) ;
if ( V_56 ) {
F_55 ( V_14 , V_32 , V_14 -> V_16 , L_50 ) ;
goto V_123;
}
V_14 -> V_33 = V_14 -> V_34 = V_166 ;
V_56 = F_160 ( V_14 ) ;
if ( V_56 ) {
F_55 ( V_14 , V_32 , V_14 -> V_16 ,
L_51 ) ;
goto V_133;
}
V_56 = F_53 ( V_14 ) ;
if ( V_56 )
goto V_136;
return 0 ;
V_136:
F_161 ( V_14 ) ;
V_133:
F_110 ( V_14 ) ;
V_123:
F_158 ( V_14 ) ;
V_120:
return V_56 ;
}
static void F_83 ( struct V_13 * V_14 )
{
F_67 ( V_14 ) ;
if ( V_14 -> V_76 )
return;
if ( ( V_14 -> V_167 != V_168 ) && ( V_14 -> V_167 != V_169 ) )
return;
if ( ! F_89 ( V_14 -> V_16 ) )
return;
F_107 ( V_14 ) ;
F_57 ( V_14 ) ;
if ( V_14 -> type -> V_170 != NULL ) {
F_162 ( V_14 -> V_171 , & V_14 -> V_172 ,
V_173 ) ;
} else {
F_102 ( & V_14 -> V_105 ) ;
if ( V_14 -> V_118 -> V_174 ( V_14 ) )
F_88 ( V_14 ) ;
F_103 ( & V_14 -> V_105 ) ;
}
V_14 -> type -> V_175 ( V_14 ) ;
}
static void F_163 ( struct V_13 * V_14 )
{
F_164 ( & V_14 -> V_172 ) ;
F_165 ( V_14 ) ;
F_166 ( & V_14 -> V_110 ) ;
}
static void F_77 ( struct V_13 * V_14 )
{
F_67 ( V_14 ) ;
if ( ! V_14 -> V_76 )
return;
V_14 -> type -> V_176 ( V_14 ) ;
F_108 ( V_14 ) ;
F_163 ( V_14 ) ;
F_167 ( V_14 -> V_16 ) ;
F_66 ( V_14 ) ;
}
static void F_168 ( struct V_13 * V_14 )
{
F_56 ( V_14 ) ;
F_161 ( V_14 ) ;
F_110 ( V_14 ) ;
F_158 ( V_14 ) ;
}
static unsigned int F_169 ( unsigned int V_177 , unsigned int V_178 )
{
if ( V_177 == 0 )
return 0 ;
if ( V_177 * 1000 < V_178 )
return 1 ;
return V_177 * 1000 / V_178 ;
}
int F_157 ( struct V_13 * V_14 , unsigned int V_179 ,
unsigned int V_180 , bool V_181 ,
bool V_182 )
{
struct V_1 * V_2 ;
unsigned int V_183 = F_170 ( V_14 -> type -> V_184 *
V_14 -> V_185 ,
1000 ) ;
unsigned int V_186 ;
unsigned int V_187 ;
F_67 ( V_14 ) ;
if ( V_179 > V_183 || V_180 > V_183 )
return - V_188 ;
V_186 = F_169 ( V_179 , V_14 -> V_185 ) ;
V_187 = F_169 ( V_180 , V_14 -> V_185 ) ;
if ( V_186 != V_187 && V_14 -> V_63 == 0 &&
! V_182 ) {
F_55 ( V_14 , V_37 , V_14 -> V_16 , L_52
L_53 ) ;
return - V_188 ;
}
V_14 -> V_17 = V_181 ;
V_14 -> V_24 = V_187 ;
F_52 (channel, efx) {
if ( F_4 ( V_2 ) )
V_2 -> V_21 = V_187 ;
else if ( F_171 ( V_2 ) )
V_2 -> V_21 = V_186 ;
}
return 0 ;
}
void F_172 ( struct V_13 * V_14 , unsigned int * V_179 ,
unsigned int * V_180 , bool * V_181 )
{
* V_181 = V_14 -> V_17 ;
* V_180 = F_170 ( V_14 -> V_24 *
V_14 -> V_185 ,
1000 ) ;
if ( V_14 -> V_63 == 0 )
* V_179 = * V_180 ;
else
* V_179 = F_170 (
V_14 -> V_2 [ V_14 -> V_63 ] -> V_21 *
V_14 -> V_185 ,
1000 ) ;
}
static void F_173 ( struct V_108 * V_109 )
{
struct V_13 * V_14 = F_13 ( V_109 , struct V_13 ,
V_172 . V_189 ) ;
F_14 ( V_14 , V_190 , V_14 -> V_16 ,
L_54 ,
F_15 () ) ;
F_19 ( V_14 -> type -> V_170 == NULL ) ;
if ( F_174 ( & V_14 -> V_105 ) ) {
if ( V_14 -> V_76 )
V_14 -> type -> V_170 ( V_14 ) ;
F_103 ( & V_14 -> V_105 ) ;
}
F_162 ( V_14 -> V_171 , & V_14 -> V_172 ,
V_173 ) ;
}
static int F_175 ( struct V_191 * V_16 , struct V_192 * V_193 , int V_194 )
{
struct V_13 * V_14 = F_176 ( V_16 ) ;
struct V_195 * V_109 = F_177 ( V_193 ) ;
F_67 ( V_14 ) ;
if ( ( V_194 == V_196 || V_194 == V_197 ) &&
( V_109 -> V_198 & 0xfc00 ) == 0x0400 )
V_109 -> V_198 ^= V_199 | 0x0400 ;
return F_178 ( & V_14 -> V_200 , V_109 , V_194 ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
V_2 -> V_51 = V_14 -> V_16 ;
F_179 ( V_2 -> V_51 , & V_2 -> V_12 ,
F_12 , V_201 ) ;
}
static void F_180 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
F_52 (channel, efx)
F_79 ( V_2 ) ;
}
static void F_80 ( struct V_1 * V_2 )
{
if ( V_2 -> V_51 )
F_181 ( & V_2 -> V_12 ) ;
V_2 -> V_51 = NULL ;
}
static void F_182 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
F_52 (channel, efx)
F_80 ( V_2 ) ;
}
static void F_183 ( struct V_191 * V_16 )
{
struct V_13 * V_14 = F_176 ( V_16 ) ;
struct V_1 * V_2 ;
F_52 (channel, efx)
F_184 ( V_2 ) ;
}
static int F_185 ( struct V_191 * V_16 )
{
struct V_13 * V_14 = F_176 ( V_16 ) ;
F_67 ( V_14 ) ;
F_26 ( V_14 , V_39 , V_14 -> V_16 , L_55 ,
F_15 () ) ;
if ( V_14 -> V_167 == V_202 )
return - V_132 ;
if ( V_14 -> V_104 & V_113 )
return - V_203 ;
if ( F_186 ( V_14 ) && F_187 ( V_14 , V_77 ) )
return - V_132 ;
F_88 ( V_14 ) ;
F_83 ( V_14 ) ;
F_188 ( V_14 ) ;
return 0 ;
}
static int F_189 ( struct V_191 * V_16 )
{
struct V_13 * V_14 = F_176 ( V_16 ) ;
F_26 ( V_14 , V_125 , V_14 -> V_16 , L_56 ,
F_15 () ) ;
if ( V_14 -> V_167 != V_202 ) {
F_77 ( V_14 ) ;
}
return 0 ;
}
static struct V_204 * F_190 ( struct V_191 * V_16 ,
struct V_204 * V_205 )
{
struct V_13 * V_14 = F_176 ( V_16 ) ;
struct V_206 * V_207 = & V_14 -> V_207 ;
F_191 ( & V_14 -> V_208 ) ;
V_14 -> type -> V_209 ( V_14 ) ;
V_205 -> V_210 = V_207 -> V_210 ;
V_205 -> V_211 = V_207 -> V_211 ;
V_205 -> V_212 = V_207 -> V_212 ;
V_205 -> V_213 = V_207 -> V_213 ;
V_205 -> V_214 = V_14 -> V_215 ;
V_205 -> V_216 = V_207 -> V_217 ;
V_205 -> V_218 = V_207 -> V_219 ;
V_205 -> V_220 = ( V_207 -> V_221 +
V_207 -> V_222 ) ;
V_205 -> V_223 = V_207 -> V_224 ;
V_205 -> V_225 = V_207 -> V_226 ;
V_205 -> V_227 = V_207 -> V_228 ;
V_205 -> V_229 = V_207 -> V_230 ;
V_205 -> V_231 = V_207 -> V_232 ;
V_205 -> V_233 = ( V_205 -> V_220 +
V_205 -> V_223 +
V_205 -> V_225 +
V_207 -> V_234 ) ;
V_205 -> V_235 = ( V_205 -> V_231 +
V_207 -> V_236 ) ;
F_192 ( & V_14 -> V_208 ) ;
return V_205 ;
}
static void F_193 ( struct V_191 * V_16 )
{
struct V_13 * V_14 = F_176 ( V_16 ) ;
F_55 ( V_14 , V_237 , V_14 -> V_16 ,
L_57 ,
V_14 -> V_76 ) ;
F_70 ( V_14 , V_238 ) ;
}
static int F_194 ( struct V_191 * V_16 , int V_239 )
{
struct V_13 * V_14 = F_176 ( V_16 ) ;
F_67 ( V_14 ) ;
if ( V_239 > V_240 )
return - V_188 ;
F_77 ( V_14 ) ;
F_26 ( V_14 , V_37 , V_14 -> V_16 , L_58 , V_239 ) ;
F_102 ( & V_14 -> V_105 ) ;
V_16 -> V_71 = V_239 ;
V_14 -> type -> V_111 ( V_14 ) ;
F_103 ( & V_14 -> V_105 ) ;
F_83 ( V_14 ) ;
return 0 ;
}
static int F_195 ( struct V_191 * V_16 , void * V_109 )
{
struct V_13 * V_14 = F_176 ( V_16 ) ;
struct V_241 * V_242 = V_109 ;
char * V_243 = V_242 -> V_244 ;
F_67 ( V_14 ) ;
if ( ! F_196 ( V_243 ) ) {
F_55 ( V_14 , V_37 , V_14 -> V_16 ,
L_59 ,
V_243 ) ;
return - V_245 ;
}
memcpy ( V_16 -> V_115 , V_243 , V_16 -> V_246 ) ;
F_197 ( V_14 ) ;
F_102 ( & V_14 -> V_105 ) ;
V_14 -> type -> V_111 ( V_14 ) ;
F_103 ( & V_14 -> V_105 ) ;
return 0 ;
}
static void F_198 ( struct V_191 * V_16 )
{
struct V_13 * V_14 = F_176 ( V_16 ) ;
struct V_247 * V_248 ;
union V_249 * V_250 = & V_14 -> V_251 ;
T_2 V_252 ;
int V_253 ;
V_14 -> V_95 = ! ! ( V_16 -> V_254 & V_255 ) ;
if ( V_14 -> V_95 || ( V_16 -> V_254 & V_256 ) ) {
memset ( V_250 , 0xff , sizeof( * V_250 ) ) ;
} else {
memset ( V_250 , 0x00 , sizeof( * V_250 ) ) ;
F_199 (ha, net_dev) {
V_252 = F_200 ( V_117 , V_248 -> V_242 ) ;
V_253 = V_252 & ( V_257 - 1 ) ;
F_201 ( V_253 , V_250 -> V_258 ) ;
}
F_201 ( 0xff , V_250 -> V_258 ) ;
}
if ( V_14 -> V_76 )
F_202 ( V_14 -> V_171 , & V_14 -> V_110 ) ;
}
static int F_203 ( struct V_191 * V_16 , T_6 V_109 )
{
struct V_13 * V_14 = F_176 ( V_16 ) ;
if ( V_16 -> V_259 & ~ V_109 & V_260 )
F_204 ( V_14 , V_261 ) ;
return 0 ;
}
static void F_205 ( struct V_13 * V_14 )
{
strcpy ( V_14 -> V_64 , V_14 -> V_16 -> V_64 ) ;
F_206 ( V_14 ) ;
F_51 ( V_14 ) ;
}
static int F_207 ( struct V_262 * V_263 ,
unsigned long V_264 , void * V_265 )
{
struct V_191 * V_16 = V_265 ;
if ( V_16 -> V_266 == & V_267 &&
V_264 == V_268 )
F_205 ( F_176 ( V_16 ) ) ;
return V_269 ;
}
static T_7
F_208 ( struct V_270 * V_271 , struct V_272 * V_273 , char * V_60 )
{
struct V_13 * V_14 = F_209 ( F_210 ( V_271 ) ) ;
return sprintf ( V_60 , L_60 , V_14 -> V_274 ) ;
}
static int F_211 ( struct V_13 * V_14 )
{
struct V_191 * V_16 = V_14 -> V_16 ;
struct V_1 * V_2 ;
int V_56 ;
V_16 -> V_275 = 5 * V_276 ;
V_16 -> V_29 = V_14 -> V_127 -> V_29 ;
V_16 -> V_266 = & V_267 ;
F_212 ( V_16 , & V_277 ) ;
F_213 () ;
V_56 = F_214 ( V_16 , V_16 -> V_64 ) ;
if ( V_56 < 0 )
goto V_278;
F_205 ( V_14 ) ;
V_56 = F_215 ( V_16 ) ;
if ( V_56 )
goto V_278;
F_52 (channel, efx) {
struct V_42 * V_43 ;
F_45 (tx_queue, channel)
F_216 ( V_43 ) ;
}
F_92 ( V_16 ) ;
F_217 () ;
V_56 = F_218 ( & V_14 -> V_127 -> V_271 , & V_279 ) ;
if ( V_56 ) {
F_55 ( V_14 , V_37 , V_14 -> V_16 ,
L_61 ) ;
goto V_280;
}
return 0 ;
V_278:
F_217 () ;
F_55 ( V_14 , V_37 , V_14 -> V_16 , L_62 ) ;
return V_56 ;
V_280:
F_219 ( V_16 ) ;
return V_56 ;
}
static void F_220 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
struct V_42 * V_43 ;
if ( ! V_14 -> V_16 )
return;
F_19 ( F_176 ( V_14 -> V_16 ) != V_14 ) ;
F_52 (channel, efx) {
F_45 (tx_queue, channel)
F_221 ( V_43 ) ;
}
F_222 ( V_14 -> V_64 , F_223 ( V_14 -> V_127 ) , sizeof( V_14 -> V_64 ) ) ;
F_224 ( & V_14 -> V_127 -> V_271 , & V_279 ) ;
F_219 ( V_14 -> V_16 ) ;
}
void F_225 ( struct V_13 * V_14 , enum V_281 V_282 )
{
F_67 ( V_14 ) ;
F_77 ( V_14 ) ;
F_102 ( & V_14 -> V_105 ) ;
F_78 ( V_14 , false ) ;
if ( V_14 -> V_121 && V_282 != V_283 )
V_14 -> V_118 -> V_124 ( V_14 ) ;
V_14 -> type -> V_124 ( V_14 ) ;
}
int F_226 ( struct V_13 * V_14 , enum V_281 V_282 , bool V_284 )
{
int V_56 ;
F_67 ( V_14 ) ;
V_56 = V_14 -> type -> V_119 ( V_14 ) ;
if ( V_56 ) {
F_55 ( V_14 , V_37 , V_14 -> V_16 , L_63 ) ;
goto V_58;
}
if ( ! V_284 )
goto V_58;
if ( V_14 -> V_121 && V_282 != V_283 ) {
V_56 = V_14 -> V_118 -> V_119 ( V_14 ) ;
if ( V_56 )
goto V_58;
if ( V_14 -> V_118 -> V_122 ( V_14 ) )
F_55 ( V_14 , V_37 , V_14 -> V_16 ,
L_64 ) ;
}
V_14 -> type -> V_111 ( V_14 ) ;
F_82 ( V_14 , false ) ;
F_227 ( V_14 ) ;
F_228 ( V_14 ) ;
F_103 ( & V_14 -> V_105 ) ;
F_83 ( V_14 ) ;
return 0 ;
V_58:
V_14 -> V_121 = false ;
F_103 ( & V_14 -> V_105 ) ;
return V_56 ;
}
int F_187 ( struct V_13 * V_14 , enum V_281 V_282 )
{
int V_56 , V_285 ;
bool V_286 ;
F_93 ( V_14 , V_37 , V_14 -> V_16 , L_65 ,
F_229 ( V_282 ) ) ;
F_230 ( V_14 -> V_16 ) ;
F_225 ( V_14 , V_282 ) ;
V_56 = V_14 -> type -> V_287 ( V_14 , V_282 ) ;
if ( V_56 ) {
F_55 ( V_14 , V_37 , V_14 -> V_16 , L_66 ) ;
goto V_85;
}
V_14 -> V_288 &= - ( 1 << ( V_282 + 1 ) ) ;
F_113 ( V_14 -> V_127 ) ;
V_85:
V_286 = V_56 || V_282 == V_289 ;
V_285 = F_226 ( V_14 , V_282 , ! V_286 ) ;
if ( V_285 ) {
V_286 = true ;
if ( ! V_56 )
V_56 = V_285 ;
}
if ( V_286 ) {
F_231 ( V_14 -> V_16 ) ;
F_55 ( V_14 , V_37 , V_14 -> V_16 , L_67 ) ;
V_14 -> V_167 = V_202 ;
} else {
F_26 ( V_14 , V_37 , V_14 -> V_16 , L_68 ) ;
F_232 ( V_14 -> V_16 ) ;
}
return V_56 ;
}
static void F_233 ( struct V_108 * V_109 )
{
struct V_13 * V_14 = F_13 ( V_109 , struct V_13 , V_290 ) ;
unsigned long V_291 = F_234 ( V_14 -> V_288 ) ;
if ( ! V_291 )
return;
if ( V_14 -> V_167 != V_168 ) {
F_93 ( V_14 , V_37 , V_14 -> V_16 ,
L_69 ) ;
return;
}
F_213 () ;
( void ) F_187 ( V_14 , F_235 ( V_291 ) - 1 ) ;
F_217 () ;
}
void F_70 ( struct V_13 * V_14 , enum V_281 type )
{
enum V_281 V_282 ;
switch ( type ) {
case V_283 :
case V_77 :
case V_292 :
case V_289 :
V_282 = type ;
F_26 ( V_14 , V_37 , V_14 -> V_16 , L_70 ,
F_229 ( V_282 ) ) ;
break;
default:
V_282 = V_14 -> type -> V_293 ( type ) ;
F_26 ( V_14 , V_37 , V_14 -> V_16 ,
L_71 ,
F_229 ( V_282 ) , F_229 ( type ) ) ;
break;
}
F_236 ( V_282 , & V_14 -> V_288 ) ;
F_147 ( V_14 ) ;
F_202 ( V_294 , & V_14 -> V_290 ) ;
}
int F_237 ( struct V_13 * V_14 )
{
return 0 ;
}
void F_238 ( struct V_13 * V_14 ) {}
static bool F_239 ( struct V_13 * V_14 )
{
return false ;
}
static int F_240 ( struct V_13 * V_14 , const struct V_295 * type ,
struct V_127 * V_127 , struct V_191 * V_16 )
{
int V_40 ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
F_241 ( & V_14 -> V_296 ) ;
#ifdef F_242
F_243 ( & V_14 -> V_297 ) ;
#endif
F_244 ( & V_14 -> V_290 , F_233 ) ;
F_245 ( & V_14 -> V_172 , F_173 ) ;
F_245 ( & V_14 -> V_298 , V_299 ) ;
V_14 -> V_127 = V_127 ;
V_14 -> V_300 = V_301 ;
V_14 -> V_167 = V_169 ;
F_222 ( V_14 -> V_64 , F_223 ( V_127 ) , sizeof( V_14 -> V_64 ) ) ;
V_14 -> V_16 = V_16 ;
F_241 ( & V_14 -> V_208 ) ;
F_246 ( & V_14 -> V_105 ) ;
V_14 -> V_118 = & V_302 ;
V_14 -> V_200 . V_271 = V_16 ;
F_244 ( & V_14 -> V_110 , F_104 ) ;
F_247 ( & V_14 -> V_303 ) ;
for ( V_40 = 0 ; V_40 < V_79 ; V_40 ++ ) {
V_14 -> V_2 [ V_40 ] = F_39 ( V_14 , V_40 , NULL ) ;
if ( ! V_14 -> V_2 [ V_40 ] )
goto V_58;
}
V_14 -> type = type ;
F_28 ( V_14 -> type -> V_147 > V_79 ) ;
V_14 -> V_151 = F_29 ( V_14 -> type -> V_304 ,
V_151 ) ;
snprintf ( V_14 -> V_305 , sizeof( V_14 -> V_305 ) , L_72 ,
F_223 ( V_127 ) ) ;
V_14 -> V_171 = F_248 ( V_14 -> V_305 ) ;
if ( ! V_14 -> V_171 )
goto V_58;
return 0 ;
V_58:
F_249 ( V_14 ) ;
return - V_84 ;
}
static void F_249 ( struct V_13 * V_14 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_79 ; V_40 ++ )
F_81 ( V_14 -> V_2 [ V_40 ] ) ;
if ( V_14 -> V_171 ) {
F_250 ( V_14 -> V_171 ) ;
V_14 -> V_171 = NULL ;
}
}
static void F_251 ( struct V_13 * V_14 )
{
#ifdef F_135
F_138 ( V_14 -> V_16 -> V_143 ) ;
V_14 -> V_16 -> V_143 = NULL ;
#endif
F_78 ( V_14 , false ) ;
F_252 ( V_14 ) ;
F_109 ( V_14 ) ;
V_14 -> type -> V_124 ( V_14 ) ;
F_182 ( V_14 ) ;
F_168 ( V_14 ) ;
}
static void F_253 ( struct V_127 * V_127 )
{
struct V_13 * V_14 ;
V_14 = F_209 ( V_127 ) ;
if ( ! V_14 )
return;
F_213 () ;
V_14 -> V_167 = V_306 ;
F_231 ( V_14 -> V_16 ) ;
F_217 () ;
F_78 ( V_14 , false ) ;
F_254 ( V_14 ) ;
F_220 ( V_14 ) ;
F_255 ( V_14 ) ;
F_166 ( & V_14 -> V_290 ) ;
F_251 ( V_14 ) ;
F_122 ( V_14 ) ;
F_26 ( V_14 , V_37 , V_14 -> V_16 , L_73 ) ;
F_256 ( V_127 , NULL ) ;
F_249 ( V_14 ) ;
F_257 ( V_14 -> V_16 ) ;
}
static void F_258 ( struct V_13 * V_14 )
{
struct V_127 * V_271 = V_14 -> V_127 ;
char V_307 [ V_308 ] ;
T_7 V_309 ;
int V_40 , V_44 ;
V_309 = F_259 ( V_271 , 0 , sizeof( V_307 ) , V_307 ) ;
if ( V_309 <= 0 ) {
F_55 ( V_14 , V_37 , V_14 -> V_16 , L_74 ) ;
return;
}
V_40 = F_260 ( V_307 , 0 , V_309 , V_310 ) ;
if ( V_40 < 0 ) {
F_55 ( V_14 , V_37 , V_14 -> V_16 , L_75 ) ;
return;
}
V_44 = F_261 ( & V_307 [ V_40 ] ) ;
V_40 += V_311 ;
if ( V_40 + V_44 > V_309 )
V_44 = V_309 - V_40 ;
V_40 = F_262 ( V_307 , V_40 , V_44 , L_76 ) ;
if ( V_40 < 0 ) {
F_55 ( V_14 , V_37 , V_14 -> V_16 , L_77 ) ;
return;
}
V_44 = F_263 ( & V_307 [ V_40 ] ) ;
V_40 += V_312 ;
if ( V_40 + V_44 > V_309 ) {
F_55 ( V_14 , V_37 , V_14 -> V_16 , L_78 ) ;
return;
}
F_93 ( V_14 , V_37 , V_14 -> V_16 ,
L_79 , V_44 , & V_307 [ V_40 ] ) ;
}
static int F_264 ( struct V_13 * V_14 )
{
int V_56 ;
V_56 = F_159 ( V_14 ) ;
if ( V_56 )
goto V_120;
F_180 ( V_14 ) ;
V_56 = V_14 -> type -> V_119 ( V_14 ) ;
if ( V_56 ) {
F_55 ( V_14 , V_32 , V_14 -> V_16 ,
L_63 ) ;
goto V_133;
}
V_56 = F_106 ( V_14 ) ;
if ( V_56 ) {
F_55 ( V_14 , V_32 , V_14 -> V_16 ,
L_80 ) ;
goto V_136;
}
V_56 = F_265 ( V_14 ) ;
if ( V_56 )
goto V_313;
F_82 ( V_14 , false ) ;
return 0 ;
V_313:
F_109 ( V_14 ) ;
V_136:
V_14 -> type -> V_124 ( V_14 ) ;
V_133:
F_182 ( V_14 ) ;
F_168 ( V_14 ) ;
V_120:
return V_56 ;
}
static int T_8 F_266 ( struct V_127 * V_127 ,
const struct V_314 * V_154 )
{
const struct V_295 * type = ( const struct V_295 * ) V_154 -> V_315 ;
struct V_191 * V_16 ;
struct V_13 * V_14 ;
int V_56 ;
V_16 = F_267 ( sizeof( * V_14 ) , V_316 ,
V_317 ) ;
if ( ! V_16 )
return - V_84 ;
V_16 -> V_259 |= ( type -> V_318 | V_319 |
V_320 | V_321 |
V_322 ) ;
if ( type -> V_318 & V_323 )
V_16 -> V_259 |= V_324 ;
V_16 -> V_325 |= ( V_326 | V_319 |
V_320 | V_327 |
V_322 ) ;
V_16 -> V_328 = V_16 -> V_259 & ~ V_320 ;
V_14 = F_176 ( V_16 ) ;
F_256 ( V_127 , V_14 ) ;
F_268 ( V_16 , & V_127 -> V_271 ) ;
V_56 = F_240 ( V_14 , type , V_127 , V_16 ) ;
if ( V_56 )
goto V_120;
F_93 ( V_14 , V_32 , V_14 -> V_16 ,
L_81 ) ;
F_258 ( V_14 ) ;
V_56 = F_111 ( V_14 ) ;
if ( V_56 )
goto V_123;
V_56 = F_264 ( V_14 ) ;
F_166 ( & V_14 -> V_290 ) ;
if ( V_56 )
goto V_133;
if ( V_14 -> V_288 ) {
V_56 = - V_132 ;
goto V_136;
}
V_14 -> V_167 = V_168 ;
V_56 = F_211 ( V_14 ) ;
if ( V_56 )
goto V_136;
V_56 = F_269 ( V_14 ) ;
if ( V_56 )
F_55 ( V_14 , V_32 , V_14 -> V_16 ,
L_82 , V_56 ) ;
F_26 ( V_14 , V_32 , V_14 -> V_16 , L_83 ) ;
F_213 () ;
V_56 = F_270 ( V_14 ) ;
F_217 () ;
if ( V_56 )
F_126 ( V_14 , V_32 , V_14 -> V_16 ,
L_84 , V_56 ) ;
return 0 ;
V_136:
F_251 ( V_14 ) ;
V_133:
F_122 ( V_14 ) ;
V_123:
F_249 ( V_14 ) ;
V_120:
F_63 ( V_56 > 0 ) ;
F_26 ( V_14 , V_37 , V_14 -> V_16 , L_85 , V_56 ) ;
F_257 ( V_16 ) ;
return V_56 ;
}
static int F_271 ( struct V_270 * V_271 )
{
struct V_13 * V_14 = F_209 ( F_210 ( V_271 ) ) ;
V_14 -> V_167 = V_306 ;
F_230 ( V_14 -> V_16 ) ;
F_77 ( V_14 ) ;
F_78 ( V_14 , false ) ;
return 0 ;
}
static int F_272 ( struct V_270 * V_271 )
{
struct V_13 * V_14 = F_209 ( F_210 ( V_271 ) ) ;
V_14 -> V_167 = V_169 ;
F_82 ( V_14 , false ) ;
F_102 ( & V_14 -> V_105 ) ;
V_14 -> V_118 -> V_122 ( V_14 ) ;
F_103 ( & V_14 -> V_105 ) ;
F_83 ( V_14 ) ;
F_232 ( V_14 -> V_16 ) ;
V_14 -> V_167 = V_168 ;
V_14 -> type -> V_329 ( V_14 ) ;
F_202 ( V_294 , & V_14 -> V_290 ) ;
return 0 ;
}
static int F_273 ( struct V_270 * V_271 )
{
struct V_127 * V_127 = F_210 ( V_271 ) ;
struct V_13 * V_14 = F_209 ( V_127 ) ;
V_14 -> type -> V_124 ( V_14 ) ;
V_14 -> V_288 = 0 ;
F_274 ( V_127 ) ;
return F_275 ( V_127 , V_330 ) ;
}
static int F_276 ( struct V_270 * V_271 )
{
struct V_127 * V_127 = F_210 ( V_271 ) ;
struct V_13 * V_14 = F_209 ( V_127 ) ;
int V_56 ;
V_56 = F_275 ( V_127 , V_331 ) ;
if ( V_56 )
return V_56 ;
F_277 ( V_127 ) ;
V_56 = F_112 ( V_127 ) ;
if ( V_56 )
return V_56 ;
F_113 ( V_14 -> V_127 ) ;
V_56 = V_14 -> type -> V_287 ( V_14 , V_77 ) ;
if ( V_56 )
return V_56 ;
V_56 = V_14 -> type -> V_119 ( V_14 ) ;
if ( V_56 )
return V_56 ;
F_272 ( V_271 ) ;
return 0 ;
}
static int F_278 ( struct V_270 * V_271 )
{
int V_56 ;
F_271 ( V_271 ) ;
V_56 = F_273 ( V_271 ) ;
if ( V_56 )
F_276 ( V_271 ) ;
return V_56 ;
}
static int T_9 F_279 ( void )
{
int V_56 ;
F_280 ( V_332 L_86 V_333 L_87 ) ;
V_56 = F_281 ( & V_334 ) ;
if ( V_56 )
goto V_335;
V_56 = F_282 () ;
if ( V_56 )
goto V_336;
V_294 = F_248 ( L_88 ) ;
if ( ! V_294 ) {
V_56 = - V_84 ;
goto V_337;
}
V_56 = F_283 ( & V_338 ) ;
if ( V_56 < 0 )
goto V_339;
return 0 ;
V_339:
F_250 ( V_294 ) ;
V_337:
F_284 () ;
V_336:
F_285 ( & V_334 ) ;
V_335:
return V_56 ;
}
static void T_10 F_286 ( void )
{
F_280 ( V_332 L_89 ) ;
F_287 ( & V_338 ) ;
F_250 ( V_294 ) ;
F_284 () ;
F_285 ( & V_334 ) ;
}

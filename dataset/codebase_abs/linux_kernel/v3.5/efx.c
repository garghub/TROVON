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
struct V_76 * V_77 = V_14 -> V_76 ;
int V_56 ;
F_67 ( V_14 ) ;
F_19 ( V_14 -> V_78 ) ;
if ( V_77 -> V_79 ) {
V_56 = F_68 ( V_14 ) ;
if ( V_56 && F_69 ( V_14 ) ) {
F_55 ( V_14 , V_37 , V_14 -> V_16 ,
L_13 ) ;
F_70 ( V_14 , V_80 ) ;
} else if ( V_56 ) {
F_55 ( V_14 , V_37 , V_14 -> V_16 , L_14 ) ;
} else {
F_26 ( V_14 , V_37 , V_14 -> V_16 ,
L_15 ) ;
}
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
struct V_1 * V_81 [ V_82 ] , * V_2 ;
T_2 V_83 , V_84 ;
unsigned V_40 , V_67 = 0 ;
int V_56 = 0 ;
F_52 (channel, efx) {
struct V_6 * V_7 ;
struct V_42 * V_43 ;
if ( V_2 -> type -> V_85 )
continue;
V_67 = F_29 ( V_67 ,
V_2 -> V_52 . V_86 +
V_2 -> V_52 . V_31 ) ;
F_47 (rx_queue, channel)
V_67 = F_29 ( V_67 ,
V_7 -> V_55 . V_86 +
V_7 -> V_55 . V_31 ) ;
F_45 (tx_queue, channel)
V_67 = F_29 ( V_67 ,
V_43 -> V_54 . V_86 +
V_43 -> V_54 . V_31 ) ;
}
F_77 ( V_14 ) ;
F_78 ( V_14 , true ) ;
memset ( V_81 , 0 , sizeof( V_81 ) ) ;
for ( V_40 = 0 ; V_40 < V_14 -> V_25 ; V_40 ++ ) {
V_2 = V_14 -> V_2 [ V_40 ] ;
if ( V_2 -> type -> V_85 )
V_2 = V_2 -> type -> V_85 ( V_2 ) ;
if ( ! V_2 ) {
V_56 = - V_87 ;
goto V_88;
}
V_81 [ V_40 ] = V_2 ;
}
V_83 = V_14 -> V_33 ;
V_84 = V_14 -> V_34 ;
V_14 -> V_33 = V_33 ;
V_14 -> V_34 = V_34 ;
for ( V_40 = 0 ; V_40 < V_14 -> V_25 ; V_40 ++ ) {
V_2 = V_14 -> V_2 [ V_40 ] ;
V_14 -> V_2 [ V_40 ] = V_81 [ V_40 ] ;
V_81 [ V_40 ] = V_2 ;
}
V_14 -> V_67 = V_67 ;
for ( V_40 = 0 ; V_40 < V_14 -> V_25 ; V_40 ++ ) {
V_2 = V_14 -> V_2 [ V_40 ] ;
if ( ! V_2 -> type -> V_85 )
continue;
V_56 = F_44 ( V_2 ) ;
if ( V_56 )
goto V_89;
F_79 ( V_14 -> V_2 [ V_40 ] ) ;
}
V_88:
for ( V_40 = 0 ; V_40 < V_14 -> V_25 ; V_40 ++ ) {
V_2 = V_81 [ V_40 ] ;
if ( V_2 && V_2 -> type -> V_85 ) {
F_80 ( V_2 ) ;
F_49 ( V_2 ) ;
F_81 ( V_2 ) ;
}
}
F_82 ( V_14 , true ) ;
F_83 ( V_14 ) ;
return V_56 ;
V_89:
V_14 -> V_33 = V_83 ;
V_14 -> V_34 = V_84 ;
for ( V_40 = 0 ; V_40 < V_14 -> V_25 ; V_40 ++ ) {
V_2 = V_14 -> V_2 [ V_40 ] ;
V_14 -> V_2 [ V_40 ] = V_81 [ V_40 ] ;
V_81 [ V_40 ] = V_2 ;
}
goto V_88;
}
void F_84 ( struct V_6 * V_7 )
{
F_85 ( & V_7 -> V_49 , V_90 + F_86 ( 100 ) ) ;
}
int F_87 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_88 ( struct V_13 * V_14 )
{
struct V_91 * V_92 = & V_14 -> V_92 ;
if ( ! F_89 ( V_14 -> V_16 ) )
return;
if ( V_92 -> V_93 != F_90 ( V_14 -> V_16 ) ) {
V_14 -> V_94 ++ ;
if ( V_92 -> V_93 )
F_91 ( V_14 -> V_16 ) ;
else
F_92 ( V_14 -> V_16 ) ;
}
if ( V_92 -> V_93 )
F_93 ( V_14 , V_95 , V_14 -> V_16 ,
L_17 ,
V_92 -> V_96 , V_92 -> V_97 ? L_18 : L_19 ,
V_14 -> V_16 -> V_71 ,
( V_14 -> V_98 ? L_20 : L_8 ) ) ;
else
F_93 ( V_14 , V_95 , V_14 -> V_16 , L_21 ) ;
}
void F_94 ( struct V_13 * V_14 , T_2 V_99 )
{
V_14 -> V_100 = V_99 ;
if ( V_99 ) {
if ( V_99 & V_101 )
V_14 -> V_102 |= ( V_103 | V_104 ) ;
else
V_14 -> V_102 &= ~ ( V_103 | V_104 ) ;
if ( V_99 & V_105 )
V_14 -> V_102 ^= V_103 ;
}
}
void F_95 ( struct V_13 * V_14 , T_3 V_102 )
{
V_14 -> V_102 = V_102 ;
if ( V_14 -> V_100 ) {
if ( V_102 & V_104 )
V_14 -> V_100 |= ( V_101 |
V_105 ) ;
else
V_14 -> V_100 &= ~ ( V_101 |
V_105 ) ;
if ( V_102 & V_103 )
V_14 -> V_100 ^= V_105 ;
}
}
int F_96 ( struct V_13 * V_14 )
{
enum V_106 V_107 ;
int V_56 ;
F_63 ( ! F_97 ( & V_14 -> V_108 ) ) ;
F_98 ( V_14 -> V_16 ) ;
F_99 ( V_14 -> V_16 ) ;
V_107 = V_14 -> V_107 ;
if ( F_100 ( V_14 ) )
V_14 -> V_107 |= V_109 ;
else
V_14 -> V_107 &= ~ V_109 ;
V_56 = V_14 -> type -> V_110 ( V_14 ) ;
if ( V_56 )
V_14 -> V_107 = V_107 ;
return V_56 ;
}
int F_101 ( struct V_13 * V_14 )
{
int V_56 ;
F_67 ( V_14 ) ;
F_102 ( & V_14 -> V_108 ) ;
V_56 = F_96 ( V_14 ) ;
F_103 ( & V_14 -> V_108 ) ;
return V_56 ;
}
static void F_104 ( struct V_111 * V_112 )
{
struct V_13 * V_14 = F_13 ( V_112 , struct V_13 , V_113 ) ;
F_102 ( & V_14 -> V_108 ) ;
if ( V_14 -> V_78 )
V_14 -> type -> V_114 ( V_14 ) ;
F_103 ( & V_14 -> V_108 ) ;
}
static int F_105 ( struct V_13 * V_14 )
{
int V_56 ;
F_26 ( V_14 , V_32 , V_14 -> V_16 , L_22 ) ;
if ( V_115 )
V_14 -> V_107 = V_116 ;
V_56 = V_14 -> type -> V_117 ( V_14 ) ;
if ( V_56 )
return V_56 ;
memcpy ( V_14 -> V_16 -> V_118 , V_14 -> V_16 -> V_119 , V_120 ) ;
return 0 ;
}
static int F_106 ( struct V_13 * V_14 )
{
int V_56 ;
F_26 ( V_14 , V_37 , V_14 -> V_16 , L_23 ) ;
F_102 ( & V_14 -> V_108 ) ;
V_56 = V_14 -> V_121 -> V_122 ( V_14 ) ;
if ( V_56 )
goto V_123;
V_14 -> V_124 = true ;
V_14 -> type -> V_114 ( V_14 ) ;
V_56 = V_14 -> V_121 -> V_125 ( V_14 ) ;
if ( V_56 )
goto V_126;
F_103 ( & V_14 -> V_108 ) ;
return 0 ;
V_126:
V_14 -> V_121 -> V_127 ( V_14 ) ;
V_123:
F_103 ( & V_14 -> V_108 ) ;
return V_56 ;
}
static void F_107 ( struct V_13 * V_14 )
{
F_26 ( V_14 , V_39 , V_14 -> V_16 , L_24 ) ;
F_19 ( V_14 -> V_78 ) ;
F_102 ( & V_14 -> V_108 ) ;
V_14 -> V_78 = true ;
V_14 -> type -> V_114 ( V_14 ) ;
F_103 ( & V_14 -> V_108 ) ;
}
static void F_108 ( struct V_13 * V_14 )
{
F_26 ( V_14 , V_128 , V_14 -> V_16 , L_25 ) ;
F_102 ( & V_14 -> V_108 ) ;
V_14 -> V_78 = false ;
F_103 ( & V_14 -> V_108 ) ;
F_98 ( V_14 -> V_16 ) ;
F_99 ( V_14 -> V_16 ) ;
}
static void F_109 ( struct V_13 * V_14 )
{
F_26 ( V_14 , V_37 , V_14 -> V_16 , L_26 ) ;
if ( ! V_14 -> V_124 )
return;
V_14 -> V_121 -> V_127 ( V_14 ) ;
V_14 -> V_124 = false ;
V_14 -> V_92 . V_93 = false ;
F_88 ( V_14 ) ;
}
static void F_110 ( struct V_13 * V_14 )
{
F_26 ( V_14 , V_37 , V_14 -> V_16 , L_27 ) ;
V_14 -> type -> V_129 ( V_14 ) ;
}
static int F_111 ( struct V_13 * V_14 )
{
struct V_76 * V_76 = V_14 -> V_76 ;
T_4 V_130 = V_14 -> type -> V_131 ;
int V_56 ;
F_26 ( V_14 , V_32 , V_14 -> V_16 , L_28 ) ;
V_56 = F_112 ( V_76 ) ;
if ( V_56 ) {
F_55 ( V_14 , V_32 , V_14 -> V_16 ,
L_29 ) ;
goto V_123;
}
F_113 ( V_76 ) ;
while ( V_130 > 0x7fffffffUL ) {
if ( F_114 ( V_76 , V_130 ) ) {
V_56 = F_115 ( V_76 , V_130 ) ;
if ( V_56 == 0 )
break;
}
V_130 >>= 1 ;
}
if ( V_56 ) {
F_55 ( V_14 , V_32 , V_14 -> V_16 ,
L_30 ) ;
goto V_126;
}
F_26 ( V_14 , V_32 , V_14 -> V_16 ,
L_31 , ( unsigned long long ) V_130 ) ;
V_56 = F_116 ( V_76 , V_130 ) ;
if ( V_56 ) {
F_55 ( V_14 , V_32 , V_14 -> V_16 ,
L_32 ) ;
goto V_126;
}
V_14 -> V_132 = F_117 ( V_14 -> V_76 , V_133 ) ;
V_56 = F_118 ( V_76 , V_133 , L_33 ) ;
if ( V_56 ) {
F_55 ( V_14 , V_32 , V_14 -> V_16 ,
L_34 ) ;
V_56 = - V_134 ;
goto V_135;
}
V_14 -> V_136 = F_119 ( V_14 -> V_132 ,
V_14 -> type -> V_137 ) ;
if ( ! V_14 -> V_136 ) {
F_55 ( V_14 , V_32 , V_14 -> V_16 ,
L_35 ,
( unsigned long long ) V_14 -> V_132 ,
V_14 -> type -> V_137 ) ;
V_56 = - V_87 ;
goto V_138;
}
F_26 ( V_14 , V_32 , V_14 -> V_16 ,
L_36 ,
( unsigned long long ) V_14 -> V_132 ,
V_14 -> type -> V_137 , V_14 -> V_136 ) ;
return 0 ;
V_138:
F_120 ( V_14 -> V_76 , V_133 ) ;
V_135:
V_14 -> V_132 = 0 ;
V_126:
F_121 ( V_14 -> V_76 ) ;
V_123:
return V_56 ;
}
static void F_122 ( struct V_13 * V_14 )
{
F_26 ( V_14 , V_37 , V_14 -> V_16 , L_37 ) ;
if ( V_14 -> V_136 ) {
F_123 ( V_14 -> V_136 ) ;
V_14 -> V_136 = NULL ;
}
if ( V_14 -> V_132 ) {
F_120 ( V_14 -> V_76 , V_133 ) ;
V_14 -> V_132 = 0 ;
}
F_121 ( V_14 -> V_76 ) ;
}
static unsigned int F_124 ( struct V_13 * V_14 )
{
T_5 V_139 ;
unsigned int V_140 ;
int V_141 ;
if ( V_142 ) {
V_140 = V_142 ;
} else {
if ( F_2 ( ! F_125 ( & V_139 , V_45 ) ) ) {
F_126 ( V_14 , V_32 , V_14 -> V_16 ,
L_38 ) ;
return 1 ;
}
V_140 = 0 ;
F_127 (cpu) {
if ( ! F_128 ( V_141 , V_139 ) ) {
++ V_140 ;
F_129 ( V_139 , V_139 ,
F_130 ( V_141 ) ) ;
}
}
F_131 ( V_139 ) ;
}
if ( F_132 ( V_14 ) && F_133 ( V_14 ) > 1 &&
V_140 > F_133 ( V_14 ) ) {
F_126 ( V_14 , V_32 , V_14 -> V_16 ,
L_39
L_40
L_41 ,
V_140 , F_133 ( V_14 ) ) ;
V_140 = F_133 ( V_14 ) ;
}
return V_140 ;
}
static int
F_134 ( struct V_13 * V_14 , struct V_143 * V_144 )
{
#ifdef F_135
unsigned int V_40 ;
int V_56 ;
V_14 -> V_16 -> V_145 = F_136 ( V_14 -> V_146 ) ;
if ( ! V_14 -> V_16 -> V_145 )
return - V_87 ;
for ( V_40 = 0 ; V_40 < V_14 -> V_146 ; V_40 ++ ) {
V_56 = F_137 ( V_14 -> V_16 -> V_145 ,
V_144 [ V_40 ] . V_147 ) ;
if ( V_56 ) {
F_138 ( V_14 -> V_16 -> V_145 ) ;
V_14 -> V_16 -> V_145 = NULL ;
return V_56 ;
}
}
#endif
return 0 ;
}
static int F_139 ( struct V_13 * V_14 )
{
unsigned int V_148 =
F_140 ( V_14 -> type -> V_149 , V_82 ) ;
unsigned int V_150 = 0 ;
unsigned int V_40 , V_44 ;
int V_56 ;
for ( V_40 = 0 ; V_40 < V_151 ; V_40 ++ )
if ( V_14 -> V_152 [ V_40 ] )
++ V_150 ;
if ( V_14 -> V_153 == V_154 ) {
struct V_143 V_144 [ V_82 ] ;
unsigned int V_25 ;
V_25 = F_124 ( V_14 ) ;
if ( V_155 )
V_25 *= 2 ;
V_25 += V_150 ;
V_25 = F_140 ( V_25 , V_148 ) ;
for ( V_40 = 0 ; V_40 < V_25 ; V_40 ++ )
V_144 [ V_40 ] . V_156 = V_40 ;
V_56 = F_141 ( V_14 -> V_76 , V_144 , V_25 ) ;
if ( V_56 > 0 ) {
F_55 ( V_14 , V_37 , V_14 -> V_16 ,
L_42
L_43 , V_56 , V_25 ) ;
F_55 ( V_14 , V_37 , V_14 -> V_16 ,
L_44 ) ;
F_28 ( V_56 >= V_25 ) ;
V_25 = V_56 ;
V_56 = F_141 ( V_14 -> V_76 , V_144 ,
V_25 ) ;
}
if ( V_56 == 0 ) {
V_14 -> V_25 = V_25 ;
if ( V_25 > V_150 )
V_25 -= V_150 ;
if ( V_155 ) {
V_14 -> V_157 = F_29 ( V_25 / 2 , 1U ) ;
V_14 -> V_146 = F_29 ( V_25 -
V_14 -> V_157 ,
1U ) ;
} else {
V_14 -> V_157 = V_25 ;
V_14 -> V_146 = V_25 ;
}
V_56 = F_134 ( V_14 , V_144 ) ;
if ( V_56 ) {
F_142 ( V_14 -> V_76 ) ;
return V_56 ;
}
for ( V_40 = 0 ; V_40 < V_14 -> V_25 ; V_40 ++ )
F_143 ( V_14 , V_40 ) -> V_29 =
V_144 [ V_40 ] . V_147 ;
} else {
V_14 -> V_153 = V_158 ;
F_55 ( V_14 , V_37 , V_14 -> V_16 ,
L_45 ) ;
}
}
if ( V_14 -> V_153 == V_158 ) {
V_14 -> V_25 = 1 ;
V_14 -> V_146 = 1 ;
V_14 -> V_157 = 1 ;
V_56 = F_144 ( V_14 -> V_76 ) ;
if ( V_56 == 0 ) {
F_143 ( V_14 , 0 ) -> V_29 = V_14 -> V_76 -> V_29 ;
} else {
F_55 ( V_14 , V_37 , V_14 -> V_16 ,
L_46 ) ;
V_14 -> V_153 = V_159 ;
}
}
if ( V_14 -> V_153 == V_159 ) {
V_14 -> V_25 = 1 + ( V_155 ? 1 : 0 ) ;
V_14 -> V_146 = 1 ;
V_14 -> V_157 = 1 ;
V_14 -> V_27 = V_14 -> V_76 -> V_29 ;
}
V_44 = V_14 -> V_25 ;
for ( V_40 = 0 ; V_40 < V_151 ; V_40 ++ ) {
if ( ! V_14 -> V_152 [ V_40 ] )
continue;
if ( V_14 -> V_153 != V_154 ||
V_14 -> V_25 <= V_150 ) {
V_14 -> V_152 [ V_40 ] -> F_145 ( V_14 ) ;
} else {
-- V_44 ;
F_143 ( V_14 , V_44 ) -> type =
V_14 -> V_152 [ V_40 ] ;
}
}
V_14 -> V_160 = ( ( V_14 -> V_146 > 1 || ! F_132 ( V_14 ) ) ?
V_14 -> V_146 : F_133 ( V_14 ) ) ;
return 0 ;
}
static void F_82 ( struct V_13 * V_14 , bool V_161 )
{
struct V_1 * V_2 ;
if ( V_14 -> V_27 )
V_14 -> V_28 = true ;
F_24 ( V_14 ) ;
F_52 (channel, efx) {
if ( ! V_2 -> type -> V_162 || ! V_161 )
F_31 ( V_2 ) ;
F_33 ( V_2 ) ;
}
F_146 ( V_14 ) ;
}
static void F_78 ( struct V_13 * V_14 , bool V_161 )
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
if ( ! V_2 -> type -> V_162 || ! V_161 )
F_35 ( V_2 ) ;
}
}
static void F_148 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
F_52 (channel, efx)
V_2 -> V_29 = 0 ;
F_149 ( V_14 -> V_76 ) ;
F_142 ( V_14 -> V_76 ) ;
V_14 -> V_27 = 0 ;
}
static void F_150 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
struct V_42 * V_43 ;
V_14 -> V_63 =
V_155 ? V_14 -> V_25 - V_14 -> V_157 : 0 ;
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
V_14 -> type -> V_163 ( V_14 ) ;
if ( V_14 -> V_25 > 1 )
F_152 ( & V_14 -> V_164 , sizeof( V_14 -> V_164 ) ) ;
for ( V_40 = 0 ; V_40 < F_153 ( V_14 -> V_165 ) ; V_40 ++ )
V_14 -> V_165 [ V_40 ] =
F_154 ( V_40 , V_14 -> V_160 ) ;
F_150 ( V_14 ) ;
F_155 ( V_14 -> V_16 , V_14 -> V_157 ) ;
F_156 ( V_14 -> V_16 , V_14 -> V_146 ) ;
F_157 ( V_14 , V_166 , V_167 , true ,
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
goto V_123;
}
V_56 = F_105 ( V_14 ) ;
if ( V_56 ) {
F_55 ( V_14 , V_32 , V_14 -> V_16 , L_50 ) ;
goto V_126;
}
V_14 -> V_33 = V_14 -> V_34 = V_168 ;
V_56 = F_160 ( V_14 ) ;
if ( V_56 ) {
F_55 ( V_14 , V_32 , V_14 -> V_16 ,
L_51 ) ;
goto V_135;
}
V_56 = F_53 ( V_14 ) ;
if ( V_56 )
goto V_138;
return 0 ;
V_138:
F_161 ( V_14 ) ;
V_135:
F_110 ( V_14 ) ;
V_126:
F_158 ( V_14 ) ;
V_123:
return V_56 ;
}
static void F_83 ( struct V_13 * V_14 )
{
F_67 ( V_14 ) ;
if ( V_14 -> V_78 )
return;
if ( ( V_14 -> V_169 != V_170 ) && ( V_14 -> V_169 != V_171 ) )
return;
if ( ! F_89 ( V_14 -> V_16 ) )
return;
F_107 ( V_14 ) ;
F_57 ( V_14 ) ;
if ( V_14 -> type -> V_172 != NULL ) {
F_162 ( V_14 -> V_173 , & V_14 -> V_174 ,
V_175 ) ;
} else {
F_102 ( & V_14 -> V_108 ) ;
if ( V_14 -> V_121 -> V_176 ( V_14 ) )
F_88 ( V_14 ) ;
F_103 ( & V_14 -> V_108 ) ;
}
V_14 -> type -> V_177 ( V_14 ) ;
}
static void F_163 ( struct V_13 * V_14 )
{
F_164 ( & V_14 -> V_174 ) ;
F_165 ( V_14 ) ;
F_166 ( & V_14 -> V_113 ) ;
}
static void F_77 ( struct V_13 * V_14 )
{
F_67 ( V_14 ) ;
if ( ! V_14 -> V_78 )
return;
V_14 -> type -> V_178 ( V_14 ) ;
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
static unsigned int F_169 ( unsigned int V_179 , unsigned int V_180 )
{
if ( V_179 == 0 )
return 0 ;
if ( V_179 * 1000 < V_180 )
return 1 ;
return V_179 * 1000 / V_180 ;
}
int F_157 ( struct V_13 * V_14 , unsigned int V_181 ,
unsigned int V_182 , bool V_183 ,
bool V_184 )
{
struct V_1 * V_2 ;
unsigned int V_185 = F_170 ( V_14 -> type -> V_186 *
V_14 -> V_187 ,
1000 ) ;
unsigned int V_188 ;
unsigned int V_189 ;
F_67 ( V_14 ) ;
if ( V_181 > V_185 || V_182 > V_185 )
return - V_190 ;
V_188 = F_169 ( V_181 , V_14 -> V_187 ) ;
V_189 = F_169 ( V_182 , V_14 -> V_187 ) ;
if ( V_188 != V_189 && V_14 -> V_63 == 0 &&
! V_184 ) {
F_55 ( V_14 , V_37 , V_14 -> V_16 , L_52
L_53 ) ;
return - V_190 ;
}
V_14 -> V_17 = V_183 ;
V_14 -> V_24 = V_189 ;
F_52 (channel, efx) {
if ( F_4 ( V_2 ) )
V_2 -> V_21 = V_189 ;
else if ( F_171 ( V_2 ) )
V_2 -> V_21 = V_188 ;
}
return 0 ;
}
void F_172 ( struct V_13 * V_14 , unsigned int * V_181 ,
unsigned int * V_182 , bool * V_183 )
{
* V_183 = V_14 -> V_17 ;
* V_182 = F_170 ( V_14 -> V_24 *
V_14 -> V_187 ,
1000 ) ;
if ( V_14 -> V_63 == 0 )
* V_181 = * V_182 ;
else
* V_181 = F_170 (
V_14 -> V_2 [ V_14 -> V_63 ] -> V_21 *
V_14 -> V_187 ,
1000 ) ;
}
static void F_173 ( struct V_111 * V_112 )
{
struct V_13 * V_14 = F_13 ( V_112 , struct V_13 ,
V_174 . V_191 ) ;
F_14 ( V_14 , V_192 , V_14 -> V_16 ,
L_54 ,
F_15 () ) ;
F_19 ( V_14 -> type -> V_172 == NULL ) ;
if ( F_174 ( & V_14 -> V_108 ) ) {
if ( V_14 -> V_78 )
V_14 -> type -> V_172 ( V_14 ) ;
F_103 ( & V_14 -> V_108 ) ;
}
F_162 ( V_14 -> V_173 , & V_14 -> V_174 ,
V_175 ) ;
}
static int F_175 ( struct V_193 * V_16 , struct V_194 * V_195 , int V_196 )
{
struct V_13 * V_14 = F_176 ( V_16 ) ;
struct V_197 * V_112 = F_177 ( V_195 ) ;
F_67 ( V_14 ) ;
if ( ( V_196 == V_198 || V_196 == V_199 ) &&
( V_112 -> V_200 & 0xfc00 ) == 0x0400 )
V_112 -> V_200 ^= V_201 | 0x0400 ;
return F_178 ( & V_14 -> V_202 , V_112 , V_196 ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
V_2 -> V_51 = V_14 -> V_16 ;
F_179 ( V_2 -> V_51 , & V_2 -> V_12 ,
F_12 , V_203 ) ;
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
static void F_183 ( struct V_193 * V_16 )
{
struct V_13 * V_14 = F_176 ( V_16 ) ;
struct V_1 * V_2 ;
F_52 (channel, efx)
F_184 ( V_2 ) ;
}
static int F_185 ( struct V_193 * V_16 )
{
struct V_13 * V_14 = F_176 ( V_16 ) ;
F_67 ( V_14 ) ;
F_26 ( V_14 , V_39 , V_14 -> V_16 , L_55 ,
F_15 () ) ;
if ( V_14 -> V_169 == V_204 )
return - V_134 ;
if ( V_14 -> V_107 & V_116 )
return - V_205 ;
if ( F_186 ( V_14 ) && F_187 ( V_14 , V_80 ) )
return - V_134 ;
F_88 ( V_14 ) ;
F_83 ( V_14 ) ;
F_188 ( V_14 ) ;
return 0 ;
}
static int F_189 ( struct V_193 * V_16 )
{
struct V_13 * V_14 = F_176 ( V_16 ) ;
F_26 ( V_14 , V_128 , V_14 -> V_16 , L_56 ,
F_15 () ) ;
if ( V_14 -> V_169 != V_204 ) {
F_77 ( V_14 ) ;
}
return 0 ;
}
static struct V_206 * F_190 ( struct V_193 * V_16 ,
struct V_206 * V_207 )
{
struct V_13 * V_14 = F_176 ( V_16 ) ;
struct V_208 * V_209 = & V_14 -> V_209 ;
F_191 ( & V_14 -> V_210 ) ;
V_14 -> type -> V_211 ( V_14 ) ;
V_207 -> V_212 = V_209 -> V_212 ;
V_207 -> V_213 = V_209 -> V_213 ;
V_207 -> V_214 = V_209 -> V_214 ;
V_207 -> V_215 = V_209 -> V_215 ;
V_207 -> V_216 = V_14 -> V_217 ;
V_207 -> V_218 = V_209 -> V_219 ;
V_207 -> V_220 = V_209 -> V_221 ;
V_207 -> V_222 = ( V_209 -> V_223 +
V_209 -> V_224 ) ;
V_207 -> V_225 = V_209 -> V_226 ;
V_207 -> V_227 = V_209 -> V_228 ;
V_207 -> V_229 = V_209 -> V_230 ;
V_207 -> V_231 = V_209 -> V_232 ;
V_207 -> V_233 = V_209 -> V_234 ;
V_207 -> V_235 = ( V_207 -> V_222 +
V_207 -> V_225 +
V_207 -> V_227 +
V_209 -> V_236 ) ;
V_207 -> V_237 = ( V_207 -> V_233 +
V_209 -> V_238 ) ;
F_192 ( & V_14 -> V_210 ) ;
return V_207 ;
}
static void F_193 ( struct V_193 * V_16 )
{
struct V_13 * V_14 = F_176 ( V_16 ) ;
F_55 ( V_14 , V_239 , V_14 -> V_16 ,
L_57 ,
V_14 -> V_78 ) ;
F_70 ( V_14 , V_240 ) ;
}
static int F_194 ( struct V_193 * V_16 , int V_241 )
{
struct V_13 * V_14 = F_176 ( V_16 ) ;
F_67 ( V_14 ) ;
if ( V_241 > V_242 )
return - V_190 ;
F_77 ( V_14 ) ;
F_26 ( V_14 , V_37 , V_14 -> V_16 , L_58 , V_241 ) ;
F_102 ( & V_14 -> V_108 ) ;
V_16 -> V_71 = V_241 ;
V_14 -> type -> V_114 ( V_14 ) ;
F_103 ( & V_14 -> V_108 ) ;
F_83 ( V_14 ) ;
return 0 ;
}
static int F_195 ( struct V_193 * V_16 , void * V_112 )
{
struct V_13 * V_14 = F_176 ( V_16 ) ;
struct V_243 * V_244 = V_112 ;
char * V_245 = V_244 -> V_246 ;
F_67 ( V_14 ) ;
if ( ! F_196 ( V_245 ) ) {
F_55 ( V_14 , V_37 , V_14 -> V_16 ,
L_59 ,
V_245 ) ;
return - V_247 ;
}
memcpy ( V_16 -> V_118 , V_245 , V_16 -> V_248 ) ;
F_197 ( V_14 ) ;
F_102 ( & V_14 -> V_108 ) ;
V_14 -> type -> V_114 ( V_14 ) ;
F_103 ( & V_14 -> V_108 ) ;
return 0 ;
}
static void F_198 ( struct V_193 * V_16 )
{
struct V_13 * V_14 = F_176 ( V_16 ) ;
struct V_249 * V_250 ;
union V_251 * V_252 = & V_14 -> V_253 ;
T_2 V_254 ;
int V_255 ;
V_14 -> V_98 = ! ! ( V_16 -> V_256 & V_257 ) ;
if ( V_14 -> V_98 || ( V_16 -> V_256 & V_258 ) ) {
memset ( V_252 , 0xff , sizeof( * V_252 ) ) ;
} else {
memset ( V_252 , 0x00 , sizeof( * V_252 ) ) ;
F_199 (ha, net_dev) {
V_254 = F_200 ( V_120 , V_250 -> V_244 ) ;
V_255 = V_254 & ( V_259 - 1 ) ;
F_201 ( V_255 , V_252 -> V_260 ) ;
}
F_201 ( 0xff , V_252 -> V_260 ) ;
}
if ( V_14 -> V_78 )
F_202 ( V_14 -> V_173 , & V_14 -> V_113 ) ;
}
static int F_203 ( struct V_193 * V_16 , T_6 V_112 )
{
struct V_13 * V_14 = F_176 ( V_16 ) ;
if ( V_16 -> V_261 & ~ V_112 & V_262 )
F_204 ( V_14 , V_263 ) ;
return 0 ;
}
static void F_205 ( struct V_13 * V_14 )
{
strcpy ( V_14 -> V_64 , V_14 -> V_16 -> V_64 ) ;
F_206 ( V_14 ) ;
F_51 ( V_14 ) ;
}
static int F_207 ( struct V_264 * V_265 ,
unsigned long V_266 , void * V_267 )
{
struct V_193 * V_16 = V_267 ;
if ( V_16 -> V_268 == & V_269 &&
V_266 == V_270 )
F_205 ( F_176 ( V_16 ) ) ;
return V_271 ;
}
static T_7
F_208 ( struct V_272 * V_77 , struct V_273 * V_274 , char * V_60 )
{
struct V_13 * V_14 = F_209 ( F_210 ( V_77 ) ) ;
return sprintf ( V_60 , L_60 , V_14 -> V_275 ) ;
}
static int F_211 ( struct V_13 * V_14 )
{
struct V_193 * V_16 = V_14 -> V_16 ;
struct V_1 * V_2 ;
int V_56 ;
V_16 -> V_276 = 5 * V_277 ;
V_16 -> V_29 = V_14 -> V_76 -> V_29 ;
V_16 -> V_268 = & V_269 ;
F_212 ( V_16 , & V_278 ) ;
F_213 () ;
V_56 = F_214 ( V_16 , V_16 -> V_64 ) ;
if ( V_56 < 0 )
goto V_279;
F_205 ( V_14 ) ;
V_56 = F_215 ( V_16 ) ;
if ( V_56 )
goto V_279;
F_52 (channel, efx) {
struct V_42 * V_43 ;
F_45 (tx_queue, channel)
F_216 ( V_43 ) ;
}
F_92 ( V_16 ) ;
F_217 () ;
V_56 = F_218 ( & V_14 -> V_76 -> V_77 , & V_280 ) ;
if ( V_56 ) {
F_55 ( V_14 , V_37 , V_14 -> V_16 ,
L_61 ) ;
goto V_281;
}
return 0 ;
V_279:
F_217 () ;
F_55 ( V_14 , V_37 , V_14 -> V_16 , L_62 ) ;
return V_56 ;
V_281:
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
F_222 ( V_14 -> V_64 , F_223 ( V_14 -> V_76 ) , sizeof( V_14 -> V_64 ) ) ;
F_224 ( & V_14 -> V_76 -> V_77 , & V_280 ) ;
F_219 ( V_14 -> V_16 ) ;
}
void F_225 ( struct V_13 * V_14 , enum V_282 V_283 )
{
F_67 ( V_14 ) ;
F_77 ( V_14 ) ;
F_102 ( & V_14 -> V_108 ) ;
F_78 ( V_14 , false ) ;
if ( V_14 -> V_124 && V_283 != V_284 )
V_14 -> V_121 -> V_127 ( V_14 ) ;
V_14 -> type -> V_127 ( V_14 ) ;
}
int F_226 ( struct V_13 * V_14 , enum V_282 V_283 , bool V_285 )
{
int V_56 ;
F_67 ( V_14 ) ;
V_56 = V_14 -> type -> V_122 ( V_14 ) ;
if ( V_56 ) {
F_55 ( V_14 , V_37 , V_14 -> V_16 , L_63 ) ;
goto V_58;
}
if ( ! V_285 )
goto V_58;
if ( V_14 -> V_124 && V_283 != V_284 ) {
V_56 = V_14 -> V_121 -> V_122 ( V_14 ) ;
if ( V_56 )
goto V_58;
if ( V_14 -> V_121 -> V_125 ( V_14 ) )
F_55 ( V_14 , V_37 , V_14 -> V_16 ,
L_64 ) ;
}
V_14 -> type -> V_114 ( V_14 ) ;
F_82 ( V_14 , false ) ;
F_227 ( V_14 ) ;
F_228 ( V_14 ) ;
F_103 ( & V_14 -> V_108 ) ;
F_83 ( V_14 ) ;
return 0 ;
V_58:
V_14 -> V_124 = false ;
F_103 ( & V_14 -> V_108 ) ;
return V_56 ;
}
int F_187 ( struct V_13 * V_14 , enum V_282 V_283 )
{
int V_56 , V_286 ;
bool V_287 ;
F_93 ( V_14 , V_37 , V_14 -> V_16 , L_65 ,
F_229 ( V_283 ) ) ;
F_230 ( V_14 -> V_16 ) ;
F_225 ( V_14 , V_283 ) ;
V_56 = V_14 -> type -> V_288 ( V_14 , V_283 ) ;
if ( V_56 ) {
F_55 ( V_14 , V_37 , V_14 -> V_16 , L_66 ) ;
goto V_88;
}
V_14 -> V_289 &= - ( 1 << ( V_283 + 1 ) ) ;
F_113 ( V_14 -> V_76 ) ;
V_88:
V_287 = V_56 || V_283 == V_290 ;
V_286 = F_226 ( V_14 , V_283 , ! V_287 ) ;
if ( V_286 ) {
V_287 = true ;
if ( ! V_56 )
V_56 = V_286 ;
}
if ( V_287 ) {
F_231 ( V_14 -> V_16 ) ;
F_55 ( V_14 , V_37 , V_14 -> V_16 , L_67 ) ;
V_14 -> V_169 = V_204 ;
} else {
F_26 ( V_14 , V_37 , V_14 -> V_16 , L_68 ) ;
F_232 ( V_14 -> V_16 ) ;
}
return V_56 ;
}
static void F_233 ( struct V_111 * V_112 )
{
struct V_13 * V_14 = F_13 ( V_112 , struct V_13 , V_291 ) ;
unsigned long V_292 = F_234 ( V_14 -> V_289 ) ;
if ( ! V_292 )
return;
if ( V_14 -> V_169 != V_170 ) {
F_93 ( V_14 , V_37 , V_14 -> V_16 ,
L_69 ) ;
return;
}
F_213 () ;
( void ) F_187 ( V_14 , F_235 ( V_292 ) - 1 ) ;
F_217 () ;
}
void F_70 ( struct V_13 * V_14 , enum V_282 type )
{
enum V_282 V_283 ;
switch ( type ) {
case V_284 :
case V_80 :
case V_293 :
case V_290 :
V_283 = type ;
F_26 ( V_14 , V_37 , V_14 -> V_16 , L_70 ,
F_229 ( V_283 ) ) ;
break;
default:
V_283 = V_14 -> type -> V_294 ( type ) ;
F_26 ( V_14 , V_37 , V_14 -> V_16 ,
L_71 ,
F_229 ( V_283 ) , F_229 ( type ) ) ;
break;
}
F_236 ( V_283 , & V_14 -> V_289 ) ;
F_147 ( V_14 ) ;
F_202 ( V_295 , & V_14 -> V_291 ) ;
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
static int F_240 ( struct V_13 * V_14 , const struct V_296 * type ,
struct V_76 * V_76 , struct V_193 * V_16 )
{
int V_40 ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
F_241 ( & V_14 -> V_297 ) ;
#ifdef F_242
F_243 ( & V_14 -> V_298 ) ;
#endif
F_244 ( & V_14 -> V_291 , F_233 ) ;
F_245 ( & V_14 -> V_174 , F_173 ) ;
F_245 ( & V_14 -> V_299 , V_300 ) ;
V_14 -> V_76 = V_76 ;
V_14 -> V_301 = V_302 ;
V_14 -> V_169 = V_171 ;
F_222 ( V_14 -> V_64 , F_223 ( V_76 ) , sizeof( V_14 -> V_64 ) ) ;
V_14 -> V_16 = V_16 ;
F_241 ( & V_14 -> V_210 ) ;
F_246 ( & V_14 -> V_108 ) ;
V_14 -> V_121 = & V_303 ;
V_14 -> V_202 . V_77 = V_16 ;
F_244 ( & V_14 -> V_113 , F_104 ) ;
F_247 ( & V_14 -> V_304 ) ;
for ( V_40 = 0 ; V_40 < V_82 ; V_40 ++ ) {
V_14 -> V_2 [ V_40 ] = F_39 ( V_14 , V_40 , NULL ) ;
if ( ! V_14 -> V_2 [ V_40 ] )
goto V_58;
}
V_14 -> type = type ;
F_28 ( V_14 -> type -> V_149 > V_82 ) ;
V_14 -> V_153 = F_29 ( V_14 -> type -> V_305 ,
V_153 ) ;
snprintf ( V_14 -> V_306 , sizeof( V_14 -> V_306 ) , L_72 ,
F_223 ( V_76 ) ) ;
V_14 -> V_173 = F_248 ( V_14 -> V_306 ) ;
if ( ! V_14 -> V_173 )
goto V_58;
return 0 ;
V_58:
F_249 ( V_14 ) ;
return - V_87 ;
}
static void F_249 ( struct V_13 * V_14 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_82 ; V_40 ++ )
F_81 ( V_14 -> V_2 [ V_40 ] ) ;
if ( V_14 -> V_173 ) {
F_250 ( V_14 -> V_173 ) ;
V_14 -> V_173 = NULL ;
}
}
static void F_251 ( struct V_13 * V_14 )
{
#ifdef F_135
F_138 ( V_14 -> V_16 -> V_145 ) ;
V_14 -> V_16 -> V_145 = NULL ;
#endif
F_78 ( V_14 , false ) ;
F_252 ( V_14 ) ;
F_109 ( V_14 ) ;
V_14 -> type -> V_127 ( V_14 ) ;
F_182 ( V_14 ) ;
F_168 ( V_14 ) ;
}
static void F_253 ( struct V_76 * V_76 )
{
struct V_13 * V_14 ;
V_14 = F_209 ( V_76 ) ;
if ( ! V_14 )
return;
F_213 () ;
V_14 -> V_169 = V_307 ;
F_231 ( V_14 -> V_16 ) ;
F_217 () ;
F_78 ( V_14 , false ) ;
F_254 ( V_14 ) ;
F_220 ( V_14 ) ;
F_255 ( V_14 ) ;
F_166 ( & V_14 -> V_291 ) ;
F_251 ( V_14 ) ;
F_122 ( V_14 ) ;
F_26 ( V_14 , V_37 , V_14 -> V_16 , L_73 ) ;
F_249 ( V_14 ) ;
F_256 ( V_76 , NULL ) ;
F_257 ( V_14 -> V_16 ) ;
}
static void F_258 ( struct V_13 * V_14 )
{
struct V_76 * V_77 = V_14 -> V_76 ;
char V_308 [ V_309 ] ;
T_7 V_310 ;
int V_40 , V_44 ;
V_310 = F_259 ( V_77 , 0 , sizeof( V_308 ) , V_308 ) ;
if ( V_310 <= 0 ) {
F_55 ( V_14 , V_37 , V_14 -> V_16 , L_74 ) ;
return;
}
V_40 = F_260 ( V_308 , 0 , V_310 , V_311 ) ;
if ( V_40 < 0 ) {
F_55 ( V_14 , V_37 , V_14 -> V_16 , L_75 ) ;
return;
}
V_44 = F_261 ( & V_308 [ V_40 ] ) ;
V_40 += V_312 ;
if ( V_40 + V_44 > V_310 )
V_44 = V_310 - V_40 ;
V_40 = F_262 ( V_308 , V_40 , V_44 , L_76 ) ;
if ( V_40 < 0 ) {
F_55 ( V_14 , V_37 , V_14 -> V_16 , L_77 ) ;
return;
}
V_44 = F_263 ( & V_308 [ V_40 ] ) ;
V_40 += V_313 ;
if ( V_40 + V_44 > V_310 ) {
F_55 ( V_14 , V_37 , V_14 -> V_16 , L_78 ) ;
return;
}
F_93 ( V_14 , V_37 , V_14 -> V_16 ,
L_79 , V_44 , & V_308 [ V_40 ] ) ;
}
static int F_264 ( struct V_13 * V_14 )
{
int V_56 ;
V_56 = F_159 ( V_14 ) ;
if ( V_56 )
goto V_123;
F_180 ( V_14 ) ;
V_56 = V_14 -> type -> V_122 ( V_14 ) ;
if ( V_56 ) {
F_55 ( V_14 , V_32 , V_14 -> V_16 ,
L_63 ) ;
goto V_135;
}
V_56 = F_106 ( V_14 ) ;
if ( V_56 ) {
F_55 ( V_14 , V_32 , V_14 -> V_16 ,
L_80 ) ;
goto V_138;
}
V_56 = F_265 ( V_14 ) ;
if ( V_56 )
goto V_314;
F_82 ( V_14 , false ) ;
return 0 ;
V_314:
F_109 ( V_14 ) ;
V_138:
V_14 -> type -> V_127 ( V_14 ) ;
V_135:
F_182 ( V_14 ) ;
F_168 ( V_14 ) ;
V_123:
return V_56 ;
}
static int T_8 F_266 ( struct V_76 * V_76 ,
const struct V_315 * V_156 )
{
const struct V_296 * type = ( const struct V_296 * ) V_156 -> V_316 ;
struct V_193 * V_16 ;
struct V_13 * V_14 ;
int V_56 ;
V_16 = F_267 ( sizeof( * V_14 ) , V_317 ,
V_318 ) ;
if ( ! V_16 )
return - V_87 ;
V_16 -> V_261 |= ( type -> V_319 | V_320 |
V_321 | V_322 |
V_323 ) ;
if ( type -> V_319 & V_324 )
V_16 -> V_261 |= V_325 ;
V_16 -> V_326 |= ( V_327 | V_320 |
V_321 | V_328 |
V_323 ) ;
V_16 -> V_329 = V_16 -> V_261 & ~ V_321 ;
V_14 = F_176 ( V_16 ) ;
F_256 ( V_76 , V_14 ) ;
F_268 ( V_16 , & V_76 -> V_77 ) ;
V_56 = F_240 ( V_14 , type , V_76 , V_16 ) ;
if ( V_56 )
goto V_123;
F_93 ( V_14 , V_32 , V_14 -> V_16 ,
L_81 ) ;
F_258 ( V_14 ) ;
V_56 = F_111 ( V_14 ) ;
if ( V_56 )
goto V_126;
V_56 = F_264 ( V_14 ) ;
F_166 ( & V_14 -> V_291 ) ;
if ( V_56 )
goto V_135;
if ( V_14 -> V_289 ) {
V_56 = - V_134 ;
goto V_138;
}
V_14 -> V_169 = V_170 ;
V_56 = F_211 ( V_14 ) ;
if ( V_56 )
goto V_138;
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
V_138:
F_251 ( V_14 ) ;
V_135:
F_122 ( V_14 ) ;
V_126:
F_249 ( V_14 ) ;
V_123:
F_256 ( V_76 , NULL ) ;
F_63 ( V_56 > 0 ) ;
F_26 ( V_14 , V_37 , V_14 -> V_16 , L_85 , V_56 ) ;
F_257 ( V_16 ) ;
return V_56 ;
}
static int F_271 ( struct V_272 * V_77 )
{
struct V_13 * V_14 = F_209 ( F_210 ( V_77 ) ) ;
V_14 -> V_169 = V_307 ;
F_230 ( V_14 -> V_16 ) ;
F_77 ( V_14 ) ;
F_78 ( V_14 , false ) ;
return 0 ;
}
static int F_272 ( struct V_272 * V_77 )
{
struct V_13 * V_14 = F_209 ( F_210 ( V_77 ) ) ;
V_14 -> V_169 = V_171 ;
F_82 ( V_14 , false ) ;
F_102 ( & V_14 -> V_108 ) ;
V_14 -> V_121 -> V_125 ( V_14 ) ;
F_103 ( & V_14 -> V_108 ) ;
F_83 ( V_14 ) ;
F_232 ( V_14 -> V_16 ) ;
V_14 -> V_169 = V_170 ;
V_14 -> type -> V_330 ( V_14 ) ;
F_202 ( V_295 , & V_14 -> V_291 ) ;
return 0 ;
}
static int F_273 ( struct V_272 * V_77 )
{
struct V_76 * V_76 = F_210 ( V_77 ) ;
struct V_13 * V_14 = F_209 ( V_76 ) ;
V_14 -> type -> V_127 ( V_14 ) ;
V_14 -> V_289 = 0 ;
F_274 ( V_76 ) ;
return F_275 ( V_76 , V_331 ) ;
}
static int F_276 ( struct V_272 * V_77 )
{
struct V_76 * V_76 = F_210 ( V_77 ) ;
struct V_13 * V_14 = F_209 ( V_76 ) ;
int V_56 ;
V_56 = F_275 ( V_76 , V_332 ) ;
if ( V_56 )
return V_56 ;
F_277 ( V_76 ) ;
V_56 = F_112 ( V_76 ) ;
if ( V_56 )
return V_56 ;
F_113 ( V_14 -> V_76 ) ;
V_56 = V_14 -> type -> V_288 ( V_14 , V_80 ) ;
if ( V_56 )
return V_56 ;
V_56 = V_14 -> type -> V_122 ( V_14 ) ;
if ( V_56 )
return V_56 ;
F_272 ( V_77 ) ;
return 0 ;
}
static int F_278 ( struct V_272 * V_77 )
{
int V_56 ;
F_271 ( V_77 ) ;
V_56 = F_273 ( V_77 ) ;
if ( V_56 )
F_276 ( V_77 ) ;
return V_56 ;
}
static int T_9 F_279 ( void )
{
int V_56 ;
F_280 ( V_333 L_86 V_334 L_87 ) ;
V_56 = F_281 ( & V_335 ) ;
if ( V_56 )
goto V_336;
V_56 = F_282 () ;
if ( V_56 )
goto V_337;
V_295 = F_248 ( L_88 ) ;
if ( ! V_295 ) {
V_56 = - V_87 ;
goto V_338;
}
V_56 = F_283 ( & V_339 ) ;
if ( V_56 < 0 )
goto V_340;
return 0 ;
V_340:
F_250 ( V_295 ) ;
V_338:
F_284 () ;
V_337:
F_285 ( & V_335 ) ;
V_336:
return V_56 ;
}
static void T_10 F_286 ( void )
{
F_280 ( V_333 L_89 ) ;
F_287 ( & V_339 ) ;
F_250 ( V_295 ) ;
F_284 () ;
F_285 ( & V_335 ) ;
}

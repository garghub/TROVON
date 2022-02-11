static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 == V_4 ) {
F_2 ( V_2 , V_5 , V_2 -> V_6 ,
L_1 ) ;
return - V_7 ;
}
return 0 ;
}
static int F_3 ( struct V_8 * V_9 , int V_10 )
{
int V_11 ;
if ( F_4 ( ! V_9 -> V_12 ) )
return 0 ;
V_11 = F_5 ( V_9 , V_10 ) ;
if ( V_11 && F_6 ( V_9 ) ) {
struct V_13 * V_14 =
F_7 ( V_9 ) ;
if ( V_9 -> V_15 ) {
F_8 ( V_9 , V_9 -> V_15 ) ;
V_9 -> V_15 = NULL ;
}
if ( V_14 -> V_12 ) {
F_9 ( V_9 ) ;
F_10 ( V_14 ) ;
}
}
return V_11 ;
}
static inline void F_11 ( struct V_8 * V_9 )
{
V_9 -> V_16 = false ;
F_12 () ;
F_13 ( V_9 ) ;
}
static int F_14 ( struct V_17 * V_18 , int V_10 )
{
struct V_8 * V_9 =
F_15 ( V_18 , struct V_8 , V_19 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
int V_11 ;
F_16 ( V_2 , V_20 , V_2 -> V_6 ,
L_2 ,
V_9 -> V_9 , F_17 () ) ;
V_11 = F_3 ( V_9 , V_10 ) ;
if ( V_11 < V_10 ) {
if ( F_6 ( V_9 ) &&
V_2 -> V_21 &&
F_4 ( ++ V_9 -> V_22 == 1000 ) ) {
if ( F_4 ( V_9 -> V_23 <
V_24 ) ) {
if ( V_9 -> V_25 > 1 ) {
V_9 -> V_25 -= 1 ;
V_2 -> type -> V_26 ( V_9 ) ;
}
} else if ( F_4 ( V_9 -> V_23 >
V_27 ) ) {
if ( V_9 -> V_25 <
V_2 -> V_28 ) {
V_9 -> V_25 += 1 ;
V_2 -> type -> V_26 ( V_9 ) ;
}
}
V_9 -> V_22 = 0 ;
V_9 -> V_23 = 0 ;
}
F_18 ( V_9 ) ;
F_19 ( V_18 ) ;
F_11 ( V_9 ) ;
}
return V_11 ;
}
void F_20 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
F_21 ( V_9 -> V_9 >= V_2 -> V_29 ) ;
F_21 ( ! V_9 -> V_12 ) ;
F_21 ( ! V_2 -> V_30 ) ;
F_22 ( V_2 ) ;
if ( V_2 -> V_31 ) {
F_23 ( V_2 -> V_31 ) ;
V_2 -> V_32 = false ;
}
if ( V_9 -> V_33 )
F_23 ( V_9 -> V_33 ) ;
F_24 ( & V_9 -> V_19 ) ;
F_3 ( V_9 , V_9 -> V_34 + 1 ) ;
F_11 ( V_9 ) ;
F_25 ( & V_9 -> V_19 ) ;
if ( V_2 -> V_31 )
V_2 -> V_32 = true ;
F_26 ( V_2 ) ;
}
static int F_27 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
unsigned long V_35 ;
F_28 ( V_2 , V_36 , V_2 -> V_6 ,
L_3 , V_9 -> V_9 ) ;
V_35 = F_29 ( V_2 -> V_37 + V_2 -> V_38 + 128 ) ;
F_30 ( V_35 > V_39 ) ;
V_9 -> V_34 = F_31 ( V_35 , V_40 ) - 1 ;
return F_32 ( V_9 ) ;
}
static void F_33 ( struct V_8 * V_9 )
{
F_28 ( V_9 -> V_2 , V_5 , V_9 -> V_2 -> V_6 ,
L_4 , V_9 -> V_9 ) ;
V_9 -> V_41 = 0 ;
F_34 ( V_9 ) ;
}
static void F_35 ( struct V_8 * V_9 )
{
F_28 ( V_9 -> V_2 , V_42 , V_9 -> V_2 -> V_6 ,
L_5 , V_9 -> V_9 ) ;
V_9 -> V_16 = false ;
V_9 -> V_12 = true ;
F_12 () ;
F_25 ( & V_9 -> V_19 ) ;
F_13 ( V_9 ) ;
}
static void F_36 ( struct V_8 * V_9 )
{
if ( ! V_9 -> V_12 )
return;
F_24 ( & V_9 -> V_19 ) ;
V_9 -> V_12 = false ;
}
static void F_37 ( struct V_8 * V_9 )
{
F_28 ( V_9 -> V_2 , V_5 , V_9 -> V_2 -> V_6 ,
L_6 , V_9 -> V_9 ) ;
F_38 ( V_9 ) ;
}
static void F_39 ( struct V_8 * V_9 )
{
F_28 ( V_9 -> V_2 , V_5 , V_9 -> V_2 -> V_6 ,
L_7 , V_9 -> V_9 ) ;
F_40 ( V_9 ) ;
}
static struct V_8 *
F_41 ( struct V_1 * V_2 , int V_43 , struct V_8 * V_44 )
{
struct V_8 * V_9 ;
struct V_13 * V_14 ;
struct V_45 * V_46 ;
int V_47 ;
V_9 = F_42 ( sizeof( * V_9 ) , V_48 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_2 = V_2 ;
V_9 -> V_9 = V_43 ;
V_9 -> type = & V_49 ;
for ( V_47 = 0 ; V_47 < V_50 ; V_47 ++ ) {
V_46 = & V_9 -> V_46 [ V_47 ] ;
V_46 -> V_2 = V_2 ;
V_46 -> V_51 = V_43 * V_50 + V_47 ;
V_46 -> V_9 = V_9 ;
}
V_14 = & V_9 -> V_14 ;
V_14 -> V_2 = V_2 ;
F_43 ( & V_14 -> V_52 , V_53 ,
( unsigned long ) V_14 ) ;
return V_9 ;
}
static struct V_8 *
F_44 ( const struct V_8 * V_44 )
{
struct V_8 * V_9 ;
struct V_13 * V_14 ;
struct V_45 * V_46 ;
int V_47 ;
V_9 = F_45 ( sizeof( * V_9 ) , V_48 ) ;
if ( ! V_9 )
return NULL ;
* V_9 = * V_44 ;
V_9 -> V_54 = NULL ;
memset ( & V_9 -> V_55 , 0 , sizeof( V_9 -> V_55 ) ) ;
for ( V_47 = 0 ; V_47 < V_50 ; V_47 ++ ) {
V_46 = & V_9 -> V_46 [ V_47 ] ;
if ( V_46 -> V_9 )
V_46 -> V_9 = V_9 ;
V_46 -> V_56 = NULL ;
memset ( & V_46 -> V_57 , 0 , sizeof( V_46 -> V_57 ) ) ;
}
V_14 = & V_9 -> V_14 ;
V_14 -> V_56 = NULL ;
memset ( & V_14 -> V_58 , 0 , sizeof( V_14 -> V_58 ) ) ;
F_43 ( & V_14 -> V_52 , V_53 ,
( unsigned long ) V_14 ) ;
return V_9 ;
}
static int F_46 ( struct V_8 * V_9 )
{
struct V_45 * V_46 ;
struct V_13 * V_14 ;
int V_59 ;
F_28 ( V_9 -> V_2 , V_36 , V_9 -> V_2 -> V_6 ,
L_8 , V_9 -> V_9 ) ;
V_59 = V_9 -> type -> V_60 ( V_9 ) ;
if ( V_59 )
goto V_61;
V_59 = F_27 ( V_9 ) ;
if ( V_59 )
goto V_61;
F_47 (tx_queue, channel) {
V_59 = F_48 ( V_46 ) ;
if ( V_59 )
goto V_61;
}
F_49 (rx_queue, channel) {
V_59 = F_50 ( V_14 ) ;
if ( V_59 )
goto V_61;
}
V_9 -> V_62 = 0 ;
return 0 ;
V_61:
F_51 ( V_9 ) ;
return V_59 ;
}
static void
F_52 ( struct V_8 * V_9 , char * V_63 , T_1 V_64 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
const char * type ;
int V_65 ;
V_65 = V_9 -> V_9 ;
if ( V_2 -> V_66 == 0 ) {
type = L_9 ;
} else if ( V_9 -> V_9 < V_2 -> V_66 ) {
type = L_10 ;
} else {
type = L_11 ;
V_65 -= V_2 -> V_66 ;
}
snprintf ( V_63 , V_64 , L_12 , V_2 -> V_67 , type , V_65 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
F_54 (channel, efx)
V_9 -> type -> V_68 ( V_9 ,
V_2 -> V_69 [ V_9 -> V_9 ] ,
sizeof( V_2 -> V_69 [ 0 ] ) ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
int V_59 ;
V_2 -> V_70 = 0 ;
F_56 (channel, efx) {
V_59 = F_46 ( V_9 ) ;
if ( V_59 ) {
F_2 ( V_2 , V_36 , V_2 -> V_6 ,
L_13 ,
V_9 -> V_9 ) ;
goto V_61;
}
}
F_53 ( V_2 ) ;
return 0 ;
V_61:
F_57 ( V_2 ) ;
return V_59 ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_45 * V_46 ;
struct V_13 * V_14 ;
struct V_8 * V_9 ;
V_2 -> V_71 = ( F_31 ( V_72 , V_73 ) +
F_59 ( V_2 -> V_6 -> V_74 ) +
V_2 -> type -> V_75 +
V_2 -> type -> V_76 ) ;
V_2 -> V_77 = F_60 ( V_2 -> V_71 +
sizeof( struct V_78 ) ) ;
V_2 -> V_79 = V_2 -> V_38 - F_61 ( V_2 ) ;
V_2 -> V_80 = V_2 -> V_79 / 2 ;
F_54 (channel, efx) {
F_47 (tx_queue, channel)
F_62 ( V_46 ) ;
F_9 ( V_9 ) ;
F_49 (rx_queue, channel) {
F_63 ( V_14 ) ;
F_64 ( V_14 ) ;
}
F_65 ( V_9 -> V_15 != NULL ) ;
F_9 ( V_9 ) ;
}
if ( F_66 ( V_2 -> V_6 ) )
F_67 ( V_2 -> V_6 ) ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
struct V_45 * V_46 ;
struct V_13 * V_14 ;
struct V_81 * V_82 = V_2 -> V_81 ;
int V_59 ;
F_69 ( V_2 ) ;
F_21 ( V_2 -> V_83 ) ;
if ( V_82 -> V_84 ) {
V_59 = F_70 ( V_2 ) ;
if ( V_59 && F_71 ( V_2 ) ) {
F_2 ( V_2 , V_5 , V_2 -> V_6 ,
L_14 ) ;
F_72 ( V_2 , V_85 ) ;
} else if ( V_59 ) {
F_2 ( V_2 , V_5 , V_2 -> V_6 , L_15 ) ;
} else {
F_28 ( V_2 , V_5 , V_2 -> V_6 ,
L_16 ) ;
}
}
F_54 (channel, efx) {
if ( F_6 ( V_9 ) ) {
F_36 ( V_9 ) ;
F_35 ( V_9 ) ;
}
F_49 (rx_queue, channel)
F_73 ( V_14 ) ;
F_74 (tx_queue, channel)
F_75 ( V_46 ) ;
}
}
static void F_51 ( struct V_8 * V_9 )
{
struct V_45 * V_46 ;
struct V_13 * V_14 ;
F_28 ( V_9 -> V_2 , V_5 , V_9 -> V_2 -> V_6 ,
L_17 , V_9 -> V_9 ) ;
F_49 (rx_queue, channel)
F_76 ( V_14 ) ;
F_74 (tx_queue, channel)
F_77 ( V_46 ) ;
F_39 ( V_9 ) ;
V_9 -> type -> V_86 ( V_9 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
F_54 (channel, efx)
F_51 ( V_9 ) ;
}
int
F_78 ( struct V_1 * V_2 , T_2 V_37 , T_2 V_38 )
{
struct V_8 * V_87 [ V_88 ] , * V_9 ;
T_2 V_89 , V_90 ;
unsigned V_43 , V_70 = 0 ;
int V_59 ;
V_59 = F_1 ( V_2 ) ;
if ( V_59 )
return V_59 ;
F_54 (channel, efx) {
struct V_13 * V_14 ;
struct V_45 * V_46 ;
if ( V_9 -> type -> V_91 )
continue;
V_70 = F_31 ( V_70 ,
V_9 -> V_55 . V_92 +
V_9 -> V_55 . V_35 ) ;
F_49 (rx_queue, channel)
V_70 = F_31 ( V_70 ,
V_14 -> V_58 . V_92 +
V_14 -> V_58 . V_35 ) ;
F_47 (tx_queue, channel)
V_70 = F_31 ( V_70 ,
V_46 -> V_57 . V_92 +
V_46 -> V_57 . V_35 ) ;
}
F_79 ( V_2 ) ;
F_80 ( V_2 , true ) ;
memset ( V_87 , 0 , sizeof( V_87 ) ) ;
for ( V_43 = 0 ; V_43 < V_2 -> V_29 ; V_43 ++ ) {
V_9 = V_2 -> V_9 [ V_43 ] ;
if ( V_9 -> type -> V_91 )
V_9 = V_9 -> type -> V_91 ( V_9 ) ;
if ( ! V_9 ) {
V_59 = - V_93 ;
goto V_94;
}
V_87 [ V_43 ] = V_9 ;
}
V_89 = V_2 -> V_37 ;
V_90 = V_2 -> V_38 ;
V_2 -> V_37 = V_37 ;
V_2 -> V_38 = V_38 ;
for ( V_43 = 0 ; V_43 < V_2 -> V_29 ; V_43 ++ ) {
V_9 = V_2 -> V_9 [ V_43 ] ;
V_2 -> V_9 [ V_43 ] = V_87 [ V_43 ] ;
V_87 [ V_43 ] = V_9 ;
}
V_2 -> V_70 = V_70 ;
for ( V_43 = 0 ; V_43 < V_2 -> V_29 ; V_43 ++ ) {
V_9 = V_2 -> V_9 [ V_43 ] ;
if ( ! V_9 -> type -> V_91 )
continue;
V_59 = F_46 ( V_9 ) ;
if ( V_59 )
goto V_95;
F_81 ( V_2 -> V_9 [ V_43 ] ) ;
}
V_94:
for ( V_43 = 0 ; V_43 < V_2 -> V_29 ; V_43 ++ ) {
V_9 = V_87 [ V_43 ] ;
if ( V_9 && V_9 -> type -> V_91 ) {
F_82 ( V_9 ) ;
F_51 ( V_9 ) ;
F_83 ( V_9 ) ;
}
}
F_84 ( V_2 , true ) ;
F_85 ( V_2 ) ;
return V_59 ;
V_95:
V_2 -> V_37 = V_89 ;
V_2 -> V_38 = V_90 ;
for ( V_43 = 0 ; V_43 < V_2 -> V_29 ; V_43 ++ ) {
V_9 = V_2 -> V_9 [ V_43 ] ;
V_2 -> V_9 [ V_43 ] = V_87 [ V_43 ] ;
V_87 [ V_43 ] = V_9 ;
}
goto V_94;
}
void F_86 ( struct V_13 * V_14 )
{
F_87 ( & V_14 -> V_52 , V_96 + F_88 ( 100 ) ) ;
}
int F_89 ( struct V_8 * V_9 )
{
return 0 ;
}
void F_90 ( struct V_8 * V_9 )
{
}
void F_91 ( struct V_1 * V_2 )
{
struct V_97 * V_98 = & V_2 -> V_98 ;
if ( ! F_92 ( V_2 -> V_6 ) )
return;
if ( V_98 -> V_99 != F_93 ( V_2 -> V_6 ) ) {
V_2 -> V_100 ++ ;
if ( V_98 -> V_99 )
F_94 ( V_2 -> V_6 ) ;
else
F_95 ( V_2 -> V_6 ) ;
}
if ( V_98 -> V_99 )
F_96 ( V_2 , V_101 , V_2 -> V_6 ,
L_18 ,
V_98 -> V_102 , V_98 -> V_103 ? L_19 : L_20 ,
V_2 -> V_6 -> V_74 ,
( V_2 -> V_104 ? L_21 : L_9 ) ) ;
else
F_96 ( V_2 , V_101 , V_2 -> V_6 , L_22 ) ;
}
void F_97 ( struct V_1 * V_2 , T_2 V_105 )
{
V_2 -> V_106 = V_105 ;
if ( V_105 ) {
if ( V_105 & V_107 )
V_2 -> V_108 |= ( V_109 | V_110 ) ;
else
V_2 -> V_108 &= ~ ( V_109 | V_110 ) ;
if ( V_105 & V_111 )
V_2 -> V_108 ^= V_109 ;
}
}
void F_98 ( struct V_1 * V_2 , T_3 V_108 )
{
V_2 -> V_108 = V_108 ;
if ( V_2 -> V_106 ) {
if ( V_108 & V_110 )
V_2 -> V_106 |= ( V_107 |
V_111 ) ;
else
V_2 -> V_106 &= ~ ( V_107 |
V_111 ) ;
if ( V_108 & V_109 )
V_2 -> V_106 ^= V_111 ;
}
}
int F_99 ( struct V_1 * V_2 )
{
enum V_112 V_113 ;
int V_59 ;
F_65 ( ! F_100 ( & V_2 -> V_114 ) ) ;
F_101 ( V_2 -> V_6 ) ;
F_102 ( V_2 -> V_6 ) ;
V_113 = V_2 -> V_113 ;
if ( F_103 ( V_2 ) )
V_2 -> V_113 |= V_115 ;
else
V_2 -> V_113 &= ~ V_115 ;
V_59 = V_2 -> type -> V_116 ( V_2 ) ;
if ( V_59 )
V_2 -> V_113 = V_113 ;
return V_59 ;
}
int F_104 ( struct V_1 * V_2 )
{
int V_59 ;
F_69 ( V_2 ) ;
F_105 ( & V_2 -> V_114 ) ;
V_59 = F_99 ( V_2 ) ;
F_106 ( & V_2 -> V_114 ) ;
return V_59 ;
}
static void F_107 ( struct V_117 * V_118 )
{
struct V_1 * V_2 = F_15 ( V_118 , struct V_1 , V_119 ) ;
F_105 ( & V_2 -> V_114 ) ;
if ( V_2 -> V_83 )
V_2 -> type -> V_120 ( V_2 ) ;
F_106 ( & V_2 -> V_114 ) ;
}
static int F_108 ( struct V_1 * V_2 )
{
int V_59 ;
F_28 ( V_2 , V_36 , V_2 -> V_6 , L_23 ) ;
if ( V_121 )
V_2 -> V_113 = V_122 ;
V_59 = V_2 -> type -> V_123 ( V_2 ) ;
if ( V_59 )
return V_59 ;
memcpy ( V_2 -> V_6 -> V_124 , V_2 -> V_6 -> V_125 , V_126 ) ;
return 0 ;
}
static int F_109 ( struct V_1 * V_2 )
{
int V_59 ;
F_28 ( V_2 , V_5 , V_2 -> V_6 , L_24 ) ;
F_105 ( & V_2 -> V_114 ) ;
V_59 = V_2 -> V_127 -> V_128 ( V_2 ) ;
if ( V_59 )
goto V_129;
V_2 -> V_130 = true ;
V_2 -> type -> V_120 ( V_2 ) ;
V_59 = V_2 -> V_127 -> V_131 ( V_2 ) ;
if ( V_59 )
goto V_132;
F_106 ( & V_2 -> V_114 ) ;
return 0 ;
V_132:
V_2 -> V_127 -> V_133 ( V_2 ) ;
V_129:
F_106 ( & V_2 -> V_114 ) ;
return V_59 ;
}
static void F_110 ( struct V_1 * V_2 )
{
F_28 ( V_2 , V_42 , V_2 -> V_6 , L_25 ) ;
F_21 ( V_2 -> V_83 ) ;
F_105 ( & V_2 -> V_114 ) ;
V_2 -> V_83 = true ;
V_2 -> type -> V_120 ( V_2 ) ;
F_106 ( & V_2 -> V_114 ) ;
}
static void F_111 ( struct V_1 * V_2 )
{
F_28 ( V_2 , V_134 , V_2 -> V_6 , L_26 ) ;
F_105 ( & V_2 -> V_114 ) ;
V_2 -> V_83 = false ;
F_106 ( & V_2 -> V_114 ) ;
F_101 ( V_2 -> V_6 ) ;
F_102 ( V_2 -> V_6 ) ;
}
static void F_112 ( struct V_1 * V_2 )
{
F_28 ( V_2 , V_5 , V_2 -> V_6 , L_27 ) ;
if ( ! V_2 -> V_130 )
return;
V_2 -> V_127 -> V_133 ( V_2 ) ;
V_2 -> V_130 = false ;
V_2 -> V_98 . V_99 = false ;
F_91 ( V_2 ) ;
}
static void F_113 ( struct V_1 * V_2 )
{
F_28 ( V_2 , V_5 , V_2 -> V_6 , L_28 ) ;
V_2 -> type -> V_135 ( V_2 ) ;
}
static int F_114 ( struct V_1 * V_2 )
{
struct V_81 * V_81 = V_2 -> V_81 ;
T_4 V_136 = V_2 -> type -> V_137 ;
int V_59 ;
F_28 ( V_2 , V_36 , V_2 -> V_6 , L_29 ) ;
V_59 = F_115 ( V_81 ) ;
if ( V_59 ) {
F_2 ( V_2 , V_36 , V_2 -> V_6 ,
L_30 ) ;
goto V_129;
}
F_116 ( V_81 ) ;
while ( V_136 > 0x7fffffffUL ) {
if ( F_117 ( & V_81 -> V_82 , V_136 ) ) {
V_59 = F_118 ( & V_81 -> V_82 , V_136 ) ;
if ( V_59 == 0 )
break;
}
V_136 >>= 1 ;
}
if ( V_59 ) {
F_2 ( V_2 , V_36 , V_2 -> V_6 ,
L_31 ) ;
goto V_132;
}
F_28 ( V_2 , V_36 , V_2 -> V_6 ,
L_32 , ( unsigned long long ) V_136 ) ;
V_59 = F_119 ( & V_81 -> V_82 , V_136 ) ;
if ( V_59 ) {
F_2 ( V_2 , V_36 , V_2 -> V_6 ,
L_33 ) ;
goto V_132;
}
V_2 -> V_138 = F_120 ( V_2 -> V_81 , V_139 ) ;
V_59 = F_121 ( V_81 , V_139 , L_34 ) ;
if ( V_59 ) {
F_2 ( V_2 , V_36 , V_2 -> V_6 ,
L_35 ) ;
V_59 = - V_7 ;
goto V_140;
}
V_2 -> V_141 = F_122 ( V_2 -> V_138 ,
V_2 -> type -> V_142 ) ;
if ( ! V_2 -> V_141 ) {
F_2 ( V_2 , V_36 , V_2 -> V_6 ,
L_36 ,
( unsigned long long ) V_2 -> V_138 ,
V_2 -> type -> V_142 ) ;
V_59 = - V_93 ;
goto V_143;
}
F_28 ( V_2 , V_36 , V_2 -> V_6 ,
L_37 ,
( unsigned long long ) V_2 -> V_138 ,
V_2 -> type -> V_142 , V_2 -> V_141 ) ;
return 0 ;
V_143:
F_123 ( V_2 -> V_81 , V_139 ) ;
V_140:
V_2 -> V_138 = 0 ;
V_132:
F_124 ( V_2 -> V_81 ) ;
V_129:
return V_59 ;
}
static void F_125 ( struct V_1 * V_2 )
{
F_28 ( V_2 , V_5 , V_2 -> V_6 , L_38 ) ;
if ( V_2 -> V_141 ) {
F_126 ( V_2 -> V_141 ) ;
V_2 -> V_141 = NULL ;
}
if ( V_2 -> V_138 ) {
F_123 ( V_2 -> V_81 , V_139 ) ;
V_2 -> V_138 = 0 ;
}
F_124 ( V_2 -> V_81 ) ;
}
static unsigned int F_127 ( struct V_1 * V_2 )
{
T_5 V_144 ;
unsigned int V_145 ;
int V_146 ;
if ( V_147 ) {
V_145 = V_147 ;
} else {
if ( F_4 ( ! F_128 ( & V_144 , V_48 ) ) ) {
F_129 ( V_2 , V_36 , V_2 -> V_6 ,
L_39 ) ;
return 1 ;
}
V_145 = 0 ;
F_130 (cpu) {
if ( ! F_131 ( V_146 , V_144 ) ) {
++ V_145 ;
F_132 ( V_144 , V_144 ,
F_133 ( V_146 ) ) ;
}
}
F_134 ( V_144 ) ;
}
if ( F_135 ( V_2 ) && F_136 ( V_2 ) > 1 &&
V_145 > F_136 ( V_2 ) ) {
F_129 ( V_2 , V_36 , V_2 -> V_6 ,
L_40
L_41
L_42 ,
V_145 , F_136 ( V_2 ) ) ;
V_145 = F_136 ( V_2 ) ;
}
return V_145 ;
}
static int
F_137 ( struct V_1 * V_2 , struct V_148 * V_149 )
{
#ifdef F_138
unsigned int V_43 ;
int V_59 ;
V_2 -> V_6 -> V_150 = F_139 ( V_2 -> V_151 ) ;
if ( ! V_2 -> V_6 -> V_150 )
return - V_93 ;
for ( V_43 = 0 ; V_43 < V_2 -> V_151 ; V_43 ++ ) {
V_59 = F_140 ( V_2 -> V_6 -> V_150 ,
V_149 [ V_43 ] . V_152 ) ;
if ( V_59 ) {
F_141 ( V_2 -> V_6 -> V_150 ) ;
V_2 -> V_6 -> V_150 = NULL ;
return V_59 ;
}
}
#endif
return 0 ;
}
static int F_142 ( struct V_1 * V_2 )
{
unsigned int V_153 =
F_143 ( V_2 -> type -> V_154 , V_88 ) ;
unsigned int V_155 = 0 ;
unsigned int V_43 , V_47 ;
int V_59 ;
for ( V_43 = 0 ; V_43 < V_156 ; V_43 ++ )
if ( V_2 -> V_157 [ V_43 ] )
++ V_155 ;
if ( V_2 -> V_158 == V_159 ) {
struct V_148 V_149 [ V_88 ] ;
unsigned int V_29 ;
V_29 = F_127 ( V_2 ) ;
if ( V_160 )
V_29 *= 2 ;
V_29 += V_155 ;
V_29 = F_143 ( V_29 , V_153 ) ;
for ( V_43 = 0 ; V_43 < V_29 ; V_43 ++ )
V_149 [ V_43 ] . V_161 = V_43 ;
V_59 = F_144 ( V_2 -> V_81 , V_149 , V_29 ) ;
if ( V_59 > 0 ) {
F_2 ( V_2 , V_5 , V_2 -> V_6 ,
L_43
L_44 , V_59 , V_29 ) ;
F_2 ( V_2 , V_5 , V_2 -> V_6 ,
L_45 ) ;
F_30 ( V_59 >= V_29 ) ;
V_29 = V_59 ;
V_59 = F_144 ( V_2 -> V_81 , V_149 ,
V_29 ) ;
}
if ( V_59 == 0 ) {
V_2 -> V_29 = V_29 ;
if ( V_29 > V_155 )
V_29 -= V_155 ;
if ( V_160 ) {
V_2 -> V_162 = F_31 ( V_29 / 2 , 1U ) ;
V_2 -> V_151 = F_31 ( V_29 -
V_2 -> V_162 ,
1U ) ;
} else {
V_2 -> V_162 = V_29 ;
V_2 -> V_151 = V_29 ;
}
V_59 = F_137 ( V_2 , V_149 ) ;
if ( V_59 ) {
F_145 ( V_2 -> V_81 ) ;
return V_59 ;
}
for ( V_43 = 0 ; V_43 < V_2 -> V_29 ; V_43 ++ )
F_146 ( V_2 , V_43 ) -> V_33 =
V_149 [ V_43 ] . V_152 ;
} else {
V_2 -> V_158 = V_163 ;
F_2 ( V_2 , V_5 , V_2 -> V_6 ,
L_46 ) ;
}
}
if ( V_2 -> V_158 == V_163 ) {
V_2 -> V_29 = 1 ;
V_2 -> V_151 = 1 ;
V_2 -> V_162 = 1 ;
V_59 = F_147 ( V_2 -> V_81 ) ;
if ( V_59 == 0 ) {
F_146 ( V_2 , 0 ) -> V_33 = V_2 -> V_81 -> V_33 ;
} else {
F_2 ( V_2 , V_5 , V_2 -> V_6 ,
L_47 ) ;
V_2 -> V_158 = V_164 ;
}
}
if ( V_2 -> V_158 == V_164 ) {
V_2 -> V_29 = 1 + ( V_160 ? 1 : 0 ) ;
V_2 -> V_151 = 1 ;
V_2 -> V_162 = 1 ;
V_2 -> V_31 = V_2 -> V_81 -> V_33 ;
}
V_47 = V_2 -> V_29 ;
for ( V_43 = 0 ; V_43 < V_156 ; V_43 ++ ) {
if ( ! V_2 -> V_157 [ V_43 ] )
continue;
if ( V_2 -> V_158 != V_159 ||
V_2 -> V_29 <= V_155 ) {
V_2 -> V_157 [ V_43 ] -> F_148 ( V_2 ) ;
} else {
-- V_47 ;
F_146 ( V_2 , V_47 ) -> type =
V_2 -> V_157 [ V_43 ] ;
}
}
V_2 -> V_165 = ( ( V_2 -> V_151 > 1 || ! F_135 ( V_2 ) ) ?
V_2 -> V_151 : F_136 ( V_2 ) ) ;
return 0 ;
}
static void F_84 ( struct V_1 * V_2 , bool V_166 )
{
struct V_8 * V_9 ;
F_21 ( V_2 -> V_3 == V_4 ) ;
if ( V_2 -> V_31 )
V_2 -> V_32 = true ;
F_26 ( V_2 ) ;
F_54 (channel, efx) {
if ( ! V_9 -> type -> V_167 || ! V_166 )
F_33 ( V_9 ) ;
F_35 ( V_9 ) ;
}
F_149 ( V_2 ) ;
}
static void F_80 ( struct V_1 * V_2 , bool V_166 )
{
struct V_8 * V_9 ;
if ( V_2 -> V_3 == V_4 )
return;
F_150 ( V_2 ) ;
F_22 ( V_2 ) ;
if ( V_2 -> V_31 ) {
F_23 ( V_2 -> V_31 ) ;
V_2 -> V_32 = false ;
}
F_54 (channel, efx) {
if ( V_9 -> V_33 )
F_23 ( V_9 -> V_33 ) ;
F_36 ( V_9 ) ;
if ( ! V_9 -> type -> V_167 || ! V_166 )
F_37 ( V_9 ) ;
}
}
static void F_151 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
F_54 (channel, efx)
V_9 -> V_33 = 0 ;
F_152 ( V_2 -> V_81 ) ;
F_145 ( V_2 -> V_81 ) ;
V_2 -> V_31 = 0 ;
}
static void F_153 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
struct V_45 * V_46 ;
V_2 -> V_66 =
V_160 ? V_2 -> V_29 - V_2 -> V_162 : 0 ;
F_54 (channel, efx) {
if ( V_9 -> V_9 < V_2 -> V_151 )
V_9 -> V_14 . V_168 = V_9 -> V_9 ;
else
V_9 -> V_14 . V_168 = - 1 ;
F_47 (tx_queue, channel)
V_46 -> V_51 -= ( V_2 -> V_66 *
V_50 ) ;
}
}
static int F_154 ( struct V_1 * V_2 )
{
T_1 V_43 ;
int V_59 ;
F_28 ( V_2 , V_36 , V_2 -> V_6 , L_48 ) ;
V_59 = V_2 -> type -> V_36 ( V_2 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_142 ( V_2 ) ;
if ( V_59 )
goto V_61;
V_2 -> type -> V_169 ( V_2 ) ;
if ( V_2 -> V_29 > 1 )
F_155 ( & V_2 -> V_170 , sizeof( V_2 -> V_170 ) ) ;
for ( V_43 = 0 ; V_43 < F_156 ( V_2 -> V_171 ) ; V_43 ++ )
V_2 -> V_171 [ V_43 ] =
F_157 ( V_43 , V_2 -> V_165 ) ;
F_153 ( V_2 ) ;
F_158 ( V_2 -> V_6 , V_2 -> V_162 ) ;
F_159 ( V_2 -> V_6 , V_2 -> V_151 ) ;
F_160 ( V_2 , V_172 , V_173 , true ,
true ) ;
return 0 ;
V_61:
V_2 -> type -> remove ( V_2 ) ;
return V_59 ;
}
static void F_161 ( struct V_1 * V_2 )
{
F_28 ( V_2 , V_5 , V_2 -> V_6 , L_49 ) ;
F_151 ( V_2 ) ;
V_2 -> type -> remove ( V_2 ) ;
}
static int F_162 ( struct V_1 * V_2 )
{
int V_59 ;
V_59 = F_154 ( V_2 ) ;
if ( V_59 ) {
F_2 ( V_2 , V_36 , V_2 -> V_6 , L_50 ) ;
goto V_129;
}
V_59 = F_108 ( V_2 ) ;
if ( V_59 ) {
F_2 ( V_2 , V_36 , V_2 -> V_6 , L_51 ) ;
goto V_132;
}
F_163 ( V_174 < V_175 ) ;
if ( F_65 ( V_174 < F_164 ( V_2 ) ) ) {
V_59 = - V_176 ;
goto V_140;
}
V_2 -> V_37 = V_2 -> V_38 = V_174 ;
V_59 = F_165 ( V_2 ) ;
if ( V_59 ) {
F_2 ( V_2 , V_36 , V_2 -> V_6 ,
L_52 ) ;
goto V_140;
}
V_59 = F_55 ( V_2 ) ;
if ( V_59 )
goto V_143;
return 0 ;
V_143:
F_166 ( V_2 ) ;
V_140:
F_113 ( V_2 ) ;
V_132:
F_161 ( V_2 ) ;
V_129:
return V_59 ;
}
static void F_85 ( struct V_1 * V_2 )
{
F_69 ( V_2 ) ;
F_21 ( V_2 -> V_3 == V_4 ) ;
if ( V_2 -> V_83 || ! F_92 ( V_2 -> V_6 ) )
return;
F_110 ( V_2 ) ;
F_58 ( V_2 ) ;
if ( V_2 -> type -> V_177 != NULL ) {
F_167 ( V_2 -> V_178 , & V_2 -> V_179 ,
V_180 ) ;
} else {
F_105 ( & V_2 -> V_114 ) ;
if ( V_2 -> V_127 -> V_181 ( V_2 ) )
F_91 ( V_2 ) ;
F_106 ( & V_2 -> V_114 ) ;
}
V_2 -> type -> V_182 ( V_2 ) ;
}
static void F_168 ( struct V_1 * V_2 )
{
F_169 ( & V_2 -> V_179 ) ;
F_170 ( V_2 ) ;
F_171 ( & V_2 -> V_119 ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
F_69 ( V_2 ) ;
if ( ! V_2 -> V_83 )
return;
V_2 -> type -> V_183 ( V_2 ) ;
F_111 ( V_2 ) ;
F_168 ( V_2 ) ;
F_172 ( V_2 -> V_6 ) ;
F_68 ( V_2 ) ;
}
static void F_173 ( struct V_1 * V_2 )
{
F_57 ( V_2 ) ;
F_166 ( V_2 ) ;
F_113 ( V_2 ) ;
F_161 ( V_2 ) ;
}
static unsigned int F_174 ( unsigned int V_184 , unsigned int V_185 )
{
if ( V_184 == 0 )
return 0 ;
if ( V_184 * 1000 < V_185 )
return 1 ;
return V_184 * 1000 / V_185 ;
}
int F_160 ( struct V_1 * V_2 , unsigned int V_186 ,
unsigned int V_187 , bool V_188 ,
bool V_189 )
{
struct V_8 * V_9 ;
unsigned int V_190 = F_175 ( V_2 -> type -> V_191 *
V_2 -> V_192 ,
1000 ) ;
unsigned int V_193 ;
unsigned int V_194 ;
F_69 ( V_2 ) ;
if ( V_186 > V_190 || V_187 > V_190 )
return - V_176 ;
V_193 = F_174 ( V_186 , V_2 -> V_192 ) ;
V_194 = F_174 ( V_187 , V_2 -> V_192 ) ;
if ( V_193 != V_194 && V_2 -> V_66 == 0 &&
! V_189 ) {
F_2 ( V_2 , V_5 , V_2 -> V_6 , L_53
L_54 ) ;
return - V_176 ;
}
V_2 -> V_21 = V_188 ;
V_2 -> V_28 = V_194 ;
F_54 (channel, efx) {
if ( F_6 ( V_9 ) )
V_9 -> V_25 = V_194 ;
else if ( F_176 ( V_9 ) )
V_9 -> V_25 = V_193 ;
}
return 0 ;
}
void F_177 ( struct V_1 * V_2 , unsigned int * V_186 ,
unsigned int * V_187 , bool * V_188 )
{
* V_188 = V_2 -> V_21 ;
* V_187 = F_175 ( V_2 -> V_28 *
V_2 -> V_192 ,
1000 ) ;
if ( V_2 -> V_66 == 0 )
* V_186 = * V_187 ;
else
* V_186 = F_175 (
V_2 -> V_9 [ V_2 -> V_66 ] -> V_25 *
V_2 -> V_192 ,
1000 ) ;
}
static void F_178 ( struct V_117 * V_118 )
{
struct V_1 * V_2 = F_15 ( V_118 , struct V_1 ,
V_179 . V_195 ) ;
F_16 ( V_2 , V_196 , V_2 -> V_6 ,
L_55 ,
F_17 () ) ;
F_21 ( V_2 -> type -> V_177 == NULL ) ;
if ( F_179 ( & V_2 -> V_114 ) ) {
if ( V_2 -> V_83 )
V_2 -> type -> V_177 ( V_2 ) ;
F_106 ( & V_2 -> V_114 ) ;
}
F_167 ( V_2 -> V_178 , & V_2 -> V_179 ,
V_180 ) ;
}
static int F_180 ( struct V_197 * V_6 , struct V_198 * V_199 , int V_200 )
{
struct V_1 * V_2 = F_181 ( V_6 ) ;
struct V_201 * V_118 = F_182 ( V_199 ) ;
if ( V_200 == V_202 )
return F_183 ( V_2 , V_199 , V_200 ) ;
if ( ( V_200 == V_203 || V_200 == V_204 ) &&
( V_118 -> V_205 & 0xfc00 ) == 0x0400 )
V_118 -> V_205 ^= V_206 | 0x0400 ;
return F_184 ( & V_2 -> V_207 , V_118 , V_200 ) ;
}
static void F_81 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
V_9 -> V_54 = V_2 -> V_6 ;
F_185 ( V_9 -> V_54 , & V_9 -> V_19 ,
F_14 , V_208 ) ;
}
static void F_186 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
F_54 (channel, efx)
F_81 ( V_9 ) ;
}
static void F_82 ( struct V_8 * V_9 )
{
if ( V_9 -> V_54 )
F_187 ( & V_9 -> V_19 ) ;
V_9 -> V_54 = NULL ;
}
static void F_188 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
F_54 (channel, efx)
F_82 ( V_9 ) ;
}
static void F_189 ( struct V_197 * V_6 )
{
struct V_1 * V_2 = F_181 ( V_6 ) ;
struct V_8 * V_9 ;
F_54 (channel, efx)
F_190 ( V_9 ) ;
}
static int F_191 ( struct V_197 * V_6 )
{
struct V_1 * V_2 = F_181 ( V_6 ) ;
int V_59 ;
F_28 ( V_2 , V_42 , V_2 -> V_6 , L_56 ,
F_17 () ) ;
V_59 = F_1 ( V_2 ) ;
if ( V_59 )
return V_59 ;
if ( V_2 -> V_113 & V_122 )
return - V_209 ;
if ( F_192 ( V_2 ) && F_193 ( V_2 , V_85 ) )
return - V_7 ;
F_91 ( V_2 ) ;
F_85 ( V_2 ) ;
F_194 ( V_2 ) ;
return 0 ;
}
static int F_195 ( struct V_197 * V_6 )
{
struct V_1 * V_2 = F_181 ( V_6 ) ;
F_28 ( V_2 , V_134 , V_2 -> V_6 , L_57 ,
F_17 () ) ;
F_79 ( V_2 ) ;
return 0 ;
}
static struct V_210 * F_196 ( struct V_197 * V_6 ,
struct V_210 * V_211 )
{
struct V_1 * V_2 = F_181 ( V_6 ) ;
struct V_212 * V_213 = & V_2 -> V_213 ;
F_197 ( & V_2 -> V_214 ) ;
V_2 -> type -> V_215 ( V_2 ) ;
V_211 -> V_216 = V_213 -> V_216 ;
V_211 -> V_217 = V_213 -> V_217 ;
V_211 -> V_218 = V_213 -> V_218 ;
V_211 -> V_219 = V_213 -> V_219 ;
V_211 -> V_220 = V_2 -> V_221 ;
V_211 -> V_222 = V_213 -> V_223 ;
V_211 -> V_224 = V_213 -> V_225 ;
V_211 -> V_226 = ( V_213 -> V_227 +
V_213 -> V_228 ) ;
V_211 -> V_229 = V_213 -> V_230 ;
V_211 -> V_231 = V_213 -> V_232 ;
V_211 -> V_233 = V_213 -> V_234 ;
V_211 -> V_235 = V_213 -> V_236 ;
V_211 -> V_237 = V_213 -> V_238 ;
V_211 -> V_239 = ( V_211 -> V_226 +
V_211 -> V_229 +
V_211 -> V_231 +
V_213 -> V_240 ) ;
V_211 -> V_241 = ( V_211 -> V_237 +
V_213 -> V_242 ) ;
F_198 ( & V_2 -> V_214 ) ;
return V_211 ;
}
static void F_199 ( struct V_197 * V_6 )
{
struct V_1 * V_2 = F_181 ( V_6 ) ;
F_2 ( V_2 , V_243 , V_2 -> V_6 ,
L_58 ,
V_2 -> V_83 ) ;
F_72 ( V_2 , V_244 ) ;
}
static int F_200 ( struct V_197 * V_6 , int V_245 )
{
struct V_1 * V_2 = F_181 ( V_6 ) ;
int V_59 ;
V_59 = F_1 ( V_2 ) ;
if ( V_59 )
return V_59 ;
if ( V_245 > V_246 )
return - V_176 ;
F_79 ( V_2 ) ;
F_28 ( V_2 , V_5 , V_2 -> V_6 , L_59 , V_245 ) ;
F_105 ( & V_2 -> V_114 ) ;
V_6 -> V_74 = V_245 ;
V_2 -> type -> V_120 ( V_2 ) ;
F_106 ( & V_2 -> V_114 ) ;
F_85 ( V_2 ) ;
return 0 ;
}
static int F_201 ( struct V_197 * V_6 , void * V_118 )
{
struct V_1 * V_2 = F_181 ( V_6 ) ;
struct V_247 * V_248 = V_118 ;
char * V_249 = V_248 -> V_250 ;
if ( ! F_202 ( V_249 ) ) {
F_2 ( V_2 , V_5 , V_2 -> V_6 ,
L_60 ,
V_249 ) ;
return - V_251 ;
}
memcpy ( V_6 -> V_124 , V_249 , V_6 -> V_252 ) ;
F_203 ( V_2 ) ;
F_105 ( & V_2 -> V_114 ) ;
V_2 -> type -> V_120 ( V_2 ) ;
F_106 ( & V_2 -> V_114 ) ;
return 0 ;
}
static void F_204 ( struct V_197 * V_6 )
{
struct V_1 * V_2 = F_181 ( V_6 ) ;
struct V_253 * V_254 ;
union V_255 * V_256 = & V_2 -> V_257 ;
T_2 V_258 ;
int V_259 ;
V_2 -> V_104 = ! ! ( V_6 -> V_260 & V_261 ) ;
if ( V_2 -> V_104 || ( V_6 -> V_260 & V_262 ) ) {
memset ( V_256 , 0xff , sizeof( * V_256 ) ) ;
} else {
memset ( V_256 , 0x00 , sizeof( * V_256 ) ) ;
F_205 (ha, net_dev) {
V_258 = F_206 ( V_126 , V_254 -> V_248 ) ;
V_259 = V_258 & ( V_263 - 1 ) ;
F_207 ( V_259 , V_256 ) ;
}
F_207 ( 0xff , V_256 ) ;
}
if ( V_2 -> V_83 )
F_208 ( V_2 -> V_178 , & V_2 -> V_119 ) ;
}
static int F_209 ( struct V_197 * V_6 , T_6 V_118 )
{
struct V_1 * V_2 = F_181 ( V_6 ) ;
if ( V_6 -> V_264 & ~ V_118 & V_265 )
F_210 ( V_2 , V_266 ) ;
return 0 ;
}
static void F_211 ( struct V_1 * V_2 )
{
strcpy ( V_2 -> V_67 , V_2 -> V_6 -> V_67 ) ;
F_212 ( V_2 ) ;
F_53 ( V_2 ) ;
}
static int F_213 ( struct V_267 * V_268 ,
unsigned long V_269 , void * V_270 )
{
struct V_197 * V_6 = V_270 ;
if ( V_6 -> V_271 == & V_272 &&
V_269 == V_273 )
F_211 ( F_181 ( V_6 ) ) ;
return V_274 ;
}
static T_7
F_214 ( struct V_275 * V_82 , struct V_276 * V_277 , char * V_63 )
{
struct V_1 * V_2 = F_215 ( F_216 ( V_82 ) ) ;
return sprintf ( V_63 , L_61 , V_2 -> V_278 ) ;
}
static int F_217 ( struct V_1 * V_2 )
{
struct V_197 * V_6 = V_2 -> V_6 ;
struct V_8 * V_9 ;
int V_59 ;
V_6 -> V_279 = 5 * V_280 ;
V_6 -> V_33 = V_2 -> V_81 -> V_33 ;
V_6 -> V_271 = & V_272 ;
F_218 ( V_6 , & V_281 ) ;
V_6 -> V_282 = V_283 ;
F_219 () ;
V_2 -> V_3 = V_284 ;
F_220 () ;
if ( V_2 -> V_285 ) {
F_2 ( V_2 , V_36 , V_2 -> V_6 ,
L_62 ) ;
V_59 = - V_7 ;
goto V_286;
}
V_59 = F_221 ( V_6 , V_6 -> V_67 ) ;
if ( V_59 < 0 )
goto V_286;
F_211 ( V_2 ) ;
F_95 ( V_6 ) ;
V_59 = F_222 ( V_6 ) ;
if ( V_59 )
goto V_286;
F_54 (channel, efx) {
struct V_45 * V_46 ;
F_47 (tx_queue, channel)
F_223 ( V_46 ) ;
}
F_224 () ;
V_59 = F_225 ( & V_2 -> V_81 -> V_82 , & V_287 ) ;
if ( V_59 ) {
F_2 ( V_2 , V_5 , V_2 -> V_6 ,
L_63 ) ;
goto V_288;
}
return 0 ;
V_288:
F_219 () ;
F_226 ( V_6 ) ;
V_286:
V_2 -> V_3 = V_289 ;
F_224 () ;
F_2 ( V_2 , V_5 , V_2 -> V_6 , L_64 ) ;
return V_59 ;
}
static void F_227 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
struct V_45 * V_46 ;
if ( ! V_2 -> V_6 )
return;
F_21 ( F_181 ( V_2 -> V_6 ) != V_2 ) ;
F_54 (channel, efx) {
F_47 (tx_queue, channel)
F_228 ( V_46 ) ;
}
F_229 ( V_2 -> V_67 , F_230 ( V_2 -> V_81 ) , sizeof( V_2 -> V_67 ) ) ;
F_231 ( & V_2 -> V_81 -> V_82 , & V_287 ) ;
F_219 () ;
F_226 ( V_2 -> V_6 ) ;
V_2 -> V_3 = V_289 ;
F_224 () ;
}
void F_232 ( struct V_1 * V_2 , enum V_290 V_291 )
{
F_69 ( V_2 ) ;
F_79 ( V_2 ) ;
F_80 ( V_2 , false ) ;
F_105 ( & V_2 -> V_114 ) ;
if ( V_2 -> V_130 && V_291 != V_292 )
V_2 -> V_127 -> V_133 ( V_2 ) ;
V_2 -> type -> V_133 ( V_2 ) ;
}
int F_233 ( struct V_1 * V_2 , enum V_290 V_291 , bool V_293 )
{
int V_59 ;
F_69 ( V_2 ) ;
V_59 = V_2 -> type -> V_128 ( V_2 ) ;
if ( V_59 ) {
F_2 ( V_2 , V_5 , V_2 -> V_6 , L_65 ) ;
goto V_61;
}
if ( ! V_293 )
goto V_61;
if ( V_2 -> V_130 && V_291 != V_292 ) {
V_59 = V_2 -> V_127 -> V_128 ( V_2 ) ;
if ( V_59 )
goto V_61;
if ( V_2 -> V_127 -> V_131 ( V_2 ) )
F_2 ( V_2 , V_5 , V_2 -> V_6 ,
L_66 ) ;
}
V_2 -> type -> V_120 ( V_2 ) ;
F_84 ( V_2 , false ) ;
F_234 ( V_2 ) ;
F_235 ( V_2 ) ;
F_106 ( & V_2 -> V_114 ) ;
F_85 ( V_2 ) ;
return 0 ;
V_61:
V_2 -> V_130 = false ;
F_106 ( & V_2 -> V_114 ) ;
return V_59 ;
}
int F_193 ( struct V_1 * V_2 , enum V_290 V_291 )
{
int V_59 , V_294 ;
bool V_295 ;
F_96 ( V_2 , V_5 , V_2 -> V_6 , L_67 ,
F_236 ( V_291 ) ) ;
F_237 ( V_2 -> V_6 ) ;
F_232 ( V_2 , V_291 ) ;
V_59 = V_2 -> type -> V_296 ( V_2 , V_291 ) ;
if ( V_59 ) {
F_2 ( V_2 , V_5 , V_2 -> V_6 , L_68 ) ;
goto V_94;
}
V_2 -> V_285 &= - ( 1 << ( V_291 + 1 ) ) ;
F_116 ( V_2 -> V_81 ) ;
V_94:
V_295 = V_59 || V_291 == V_297 ;
V_294 = F_233 ( V_2 , V_291 , ! V_295 ) ;
if ( V_294 ) {
V_295 = true ;
if ( ! V_59 )
V_59 = V_294 ;
}
if ( V_295 ) {
F_238 ( V_2 -> V_6 ) ;
F_2 ( V_2 , V_5 , V_2 -> V_6 , L_69 ) ;
V_2 -> V_3 = V_4 ;
} else {
F_28 ( V_2 , V_5 , V_2 -> V_6 , L_70 ) ;
F_239 ( V_2 -> V_6 ) ;
}
return V_59 ;
}
static void F_240 ( struct V_117 * V_118 )
{
struct V_1 * V_2 = F_15 ( V_118 , struct V_1 , V_298 ) ;
unsigned long V_299 = F_241 ( V_2 -> V_285 ) ;
if ( ! V_299 )
return;
F_219 () ;
if ( V_2 -> V_3 == V_284 )
( void ) F_193 ( V_2 , F_242 ( V_299 ) - 1 ) ;
F_224 () ;
}
void F_72 ( struct V_1 * V_2 , enum V_290 type )
{
enum V_290 V_291 ;
switch ( type ) {
case V_292 :
case V_85 :
case V_300 :
case V_297 :
V_291 = type ;
F_28 ( V_2 , V_5 , V_2 -> V_6 , L_71 ,
F_236 ( V_291 ) ) ;
break;
default:
V_291 = V_2 -> type -> V_301 ( type ) ;
F_28 ( V_2 , V_5 , V_2 -> V_6 ,
L_72 ,
F_236 ( V_291 ) , F_236 ( type ) ) ;
break;
}
F_243 ( V_291 , & V_2 -> V_285 ) ;
F_220 () ;
if ( F_241 ( V_2 -> V_3 ) != V_284 )
return;
F_150 ( V_2 ) ;
F_208 ( V_302 , & V_2 -> V_298 ) ;
}
int F_244 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_245 ( struct V_1 * V_2 ) {}
static bool F_246 ( struct V_1 * V_2 )
{
return false ;
}
static int F_247 ( struct V_1 * V_2 ,
struct V_81 * V_81 , struct V_197 * V_6 )
{
int V_43 ;
F_248 ( & V_2 -> V_303 ) ;
#ifdef F_249
F_250 ( & V_2 -> V_304 ) ;
#endif
F_251 ( & V_2 -> V_298 , F_240 ) ;
F_252 ( & V_2 -> V_179 , F_178 ) ;
F_252 ( & V_2 -> V_305 , V_306 ) ;
V_2 -> V_81 = V_81 ;
V_2 -> V_307 = V_308 ;
V_2 -> V_3 = V_289 ;
F_229 ( V_2 -> V_67 , F_230 ( V_81 ) , sizeof( V_2 -> V_67 ) ) ;
V_2 -> V_6 = V_6 ;
F_248 ( & V_2 -> V_214 ) ;
F_253 ( & V_2 -> V_114 ) ;
V_2 -> V_127 = & V_309 ;
V_2 -> V_207 . V_82 = V_6 ;
F_251 ( & V_2 -> V_119 , F_107 ) ;
F_254 ( & V_2 -> V_310 ) ;
for ( V_43 = 0 ; V_43 < V_88 ; V_43 ++ ) {
V_2 -> V_9 [ V_43 ] = F_41 ( V_2 , V_43 , NULL ) ;
if ( ! V_2 -> V_9 [ V_43 ] )
goto V_61;
}
F_30 ( V_2 -> type -> V_154 > V_88 ) ;
V_2 -> V_158 = F_31 ( V_2 -> type -> V_311 ,
V_158 ) ;
snprintf ( V_2 -> V_312 , sizeof( V_2 -> V_312 ) , L_73 ,
F_230 ( V_81 ) ) ;
V_2 -> V_178 = F_255 ( V_2 -> V_312 ) ;
if ( ! V_2 -> V_178 )
goto V_61;
return 0 ;
V_61:
F_256 ( V_2 ) ;
return - V_93 ;
}
static void F_256 ( struct V_1 * V_2 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_88 ; V_43 ++ )
F_83 ( V_2 -> V_9 [ V_43 ] ) ;
if ( V_2 -> V_178 ) {
F_257 ( V_2 -> V_178 ) ;
V_2 -> V_178 = NULL ;
}
}
static void F_258 ( struct V_1 * V_2 )
{
F_21 ( V_2 -> V_3 == V_284 ) ;
F_171 ( & V_2 -> V_298 ) ;
#ifdef F_138
F_141 ( V_2 -> V_6 -> V_150 ) ;
V_2 -> V_6 -> V_150 = NULL ;
#endif
F_80 ( V_2 , false ) ;
F_259 ( V_2 ) ;
F_112 ( V_2 ) ;
V_2 -> type -> V_133 ( V_2 ) ;
F_188 ( V_2 ) ;
F_173 ( V_2 ) ;
}
static void F_260 ( struct V_81 * V_81 )
{
struct V_1 * V_2 ;
V_2 = F_215 ( V_81 ) ;
if ( ! V_2 )
return;
F_219 () ;
F_238 ( V_2 -> V_6 ) ;
F_80 ( V_2 , false ) ;
F_224 () ;
F_261 ( V_2 ) ;
F_227 ( V_2 ) ;
F_262 ( V_2 ) ;
F_258 ( V_2 ) ;
F_125 ( V_2 ) ;
F_28 ( V_2 , V_5 , V_2 -> V_6 , L_74 ) ;
F_256 ( V_2 ) ;
F_263 ( V_81 , NULL ) ;
F_264 ( V_2 -> V_6 ) ;
}
static void F_265 ( struct V_1 * V_2 )
{
struct V_81 * V_82 = V_2 -> V_81 ;
char V_313 [ V_314 ] ;
T_7 V_315 ;
int V_43 , V_47 ;
V_315 = F_266 ( V_82 , 0 , sizeof( V_313 ) , V_313 ) ;
if ( V_315 <= 0 ) {
F_2 ( V_2 , V_5 , V_2 -> V_6 , L_75 ) ;
return;
}
V_43 = F_267 ( V_313 , 0 , V_315 , V_316 ) ;
if ( V_43 < 0 ) {
F_2 ( V_2 , V_5 , V_2 -> V_6 , L_76 ) ;
return;
}
V_47 = F_268 ( & V_313 [ V_43 ] ) ;
V_43 += V_317 ;
if ( V_43 + V_47 > V_315 )
V_47 = V_315 - V_43 ;
V_43 = F_269 ( V_313 , V_43 , V_47 , L_77 ) ;
if ( V_43 < 0 ) {
F_2 ( V_2 , V_5 , V_2 -> V_6 , L_78 ) ;
return;
}
V_47 = F_270 ( & V_313 [ V_43 ] ) ;
V_43 += V_318 ;
if ( V_43 + V_47 > V_315 ) {
F_2 ( V_2 , V_5 , V_2 -> V_6 , L_79 ) ;
return;
}
F_96 ( V_2 , V_5 , V_2 -> V_6 ,
L_80 , V_47 , & V_313 [ V_43 ] ) ;
}
static int F_271 ( struct V_1 * V_2 )
{
int V_59 ;
V_59 = F_162 ( V_2 ) ;
if ( V_59 )
goto V_129;
F_186 ( V_2 ) ;
V_59 = V_2 -> type -> V_128 ( V_2 ) ;
if ( V_59 ) {
F_2 ( V_2 , V_36 , V_2 -> V_6 ,
L_65 ) ;
goto V_140;
}
V_59 = F_109 ( V_2 ) ;
if ( V_59 ) {
F_2 ( V_2 , V_36 , V_2 -> V_6 ,
L_81 ) ;
goto V_143;
}
V_59 = F_272 ( V_2 ) ;
if ( V_59 )
goto V_319;
F_84 ( V_2 , false ) ;
return 0 ;
V_319:
F_112 ( V_2 ) ;
V_143:
V_2 -> type -> V_133 ( V_2 ) ;
V_140:
F_188 ( V_2 ) ;
F_173 ( V_2 ) ;
V_129:
return V_59 ;
}
static int T_8 F_273 ( struct V_81 * V_81 ,
const struct V_320 * V_161 )
{
struct V_197 * V_6 ;
struct V_1 * V_2 ;
int V_59 ;
V_6 = F_274 ( sizeof( * V_2 ) , V_321 ,
V_322 ) ;
if ( ! V_6 )
return - V_93 ;
V_2 = F_181 ( V_6 ) ;
V_2 -> type = ( const struct V_323 * ) V_161 -> V_324 ;
V_6 -> V_264 |= ( V_2 -> type -> V_325 | V_326 |
V_327 | V_328 |
V_329 ) ;
if ( V_2 -> type -> V_325 & V_330 )
V_6 -> V_264 |= V_331 ;
V_6 -> V_332 |= ( V_333 | V_326 |
V_327 | V_334 |
V_329 ) ;
V_6 -> V_335 = V_6 -> V_264 & ~ V_327 ;
F_263 ( V_81 , V_2 ) ;
F_275 ( V_6 , & V_81 -> V_82 ) ;
V_59 = F_247 ( V_2 , V_81 , V_6 ) ;
if ( V_59 )
goto V_129;
F_96 ( V_2 , V_36 , V_2 -> V_6 ,
L_82 ) ;
F_265 ( V_2 ) ;
V_59 = F_114 ( V_2 ) ;
if ( V_59 )
goto V_132;
V_59 = F_271 ( V_2 ) ;
if ( V_59 )
goto V_140;
V_59 = F_217 ( V_2 ) ;
if ( V_59 )
goto V_143;
V_59 = F_276 ( V_2 ) ;
if ( V_59 )
F_2 ( V_2 , V_36 , V_2 -> V_6 ,
L_83 , V_59 ) ;
F_28 ( V_2 , V_36 , V_2 -> V_6 , L_84 ) ;
F_219 () ;
V_59 = F_277 ( V_2 ) ;
F_224 () ;
if ( V_59 )
F_129 ( V_2 , V_36 , V_2 -> V_6 ,
L_85 , V_59 ) ;
return 0 ;
V_143:
F_258 ( V_2 ) ;
V_140:
F_125 ( V_2 ) ;
V_132:
F_256 ( V_2 ) ;
V_129:
F_263 ( V_81 , NULL ) ;
F_65 ( V_59 > 0 ) ;
F_28 ( V_2 , V_5 , V_2 -> V_6 , L_86 , V_59 ) ;
F_264 ( V_6 ) ;
return V_59 ;
}
static int F_278 ( struct V_275 * V_82 )
{
struct V_1 * V_2 = F_215 ( F_216 ( V_82 ) ) ;
F_219 () ;
if ( V_2 -> V_3 != V_4 ) {
V_2 -> V_3 = V_289 ;
F_237 ( V_2 -> V_6 ) ;
F_79 ( V_2 ) ;
F_80 ( V_2 , false ) ;
}
F_224 () ;
return 0 ;
}
static int F_279 ( struct V_275 * V_82 )
{
struct V_1 * V_2 = F_215 ( F_216 ( V_82 ) ) ;
F_219 () ;
if ( V_2 -> V_3 != V_4 ) {
F_84 ( V_2 , false ) ;
F_105 ( & V_2 -> V_114 ) ;
V_2 -> V_127 -> V_131 ( V_2 ) ;
F_106 ( & V_2 -> V_114 ) ;
F_85 ( V_2 ) ;
F_239 ( V_2 -> V_6 ) ;
V_2 -> V_3 = V_284 ;
V_2 -> type -> V_336 ( V_2 ) ;
}
F_224 () ;
F_208 ( V_302 , & V_2 -> V_298 ) ;
return 0 ;
}
static int F_280 ( struct V_275 * V_82 )
{
struct V_81 * V_81 = F_216 ( V_82 ) ;
struct V_1 * V_2 = F_215 ( V_81 ) ;
V_2 -> type -> V_133 ( V_2 ) ;
V_2 -> V_285 = 0 ;
F_281 ( V_81 ) ;
return F_282 ( V_81 , V_337 ) ;
}
static int F_283 ( struct V_275 * V_82 )
{
struct V_81 * V_81 = F_216 ( V_82 ) ;
struct V_1 * V_2 = F_215 ( V_81 ) ;
int V_59 ;
V_59 = F_282 ( V_81 , V_338 ) ;
if ( V_59 )
return V_59 ;
F_284 ( V_81 ) ;
V_59 = F_115 ( V_81 ) ;
if ( V_59 )
return V_59 ;
F_116 ( V_2 -> V_81 ) ;
V_59 = V_2 -> type -> V_296 ( V_2 , V_85 ) ;
if ( V_59 )
return V_59 ;
V_59 = V_2 -> type -> V_128 ( V_2 ) ;
if ( V_59 )
return V_59 ;
F_279 ( V_82 ) ;
return 0 ;
}
static int F_285 ( struct V_275 * V_82 )
{
int V_59 ;
F_278 ( V_82 ) ;
V_59 = F_280 ( V_82 ) ;
if ( V_59 )
F_283 ( V_82 ) ;
return V_59 ;
}
static int T_9 F_286 ( void )
{
int V_59 ;
F_287 ( V_339 L_87 V_340 L_88 ) ;
V_59 = F_288 ( & V_341 ) ;
if ( V_59 )
goto V_342;
V_59 = F_289 () ;
if ( V_59 )
goto V_343;
V_302 = F_255 ( L_89 ) ;
if ( ! V_302 ) {
V_59 = - V_93 ;
goto V_344;
}
V_59 = F_290 ( & V_345 ) ;
if ( V_59 < 0 )
goto V_346;
return 0 ;
V_346:
F_257 ( V_302 ) ;
V_344:
F_291 () ;
V_343:
F_292 ( & V_341 ) ;
V_342:
return V_59 ;
}
static void T_10 F_293 ( void )
{
F_287 ( V_339 L_90 ) ;
F_294 ( & V_345 ) ;
F_257 ( V_302 ) ;
F_291 () ;
F_292 ( & V_341 ) ;
}

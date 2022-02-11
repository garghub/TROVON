static void T_1 * F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 [ V_4 ] ;
}
static int F_2 ( struct V_5 * V_6 )
{
return 1 ;
}
static inline void F_3 ( struct V_7 * V_8 )
{
T_2 T_1 * V_9 = F_1 ( V_8 -> V_2 ) + ( V_8 -> V_10 * 0x4000 ) ;
struct V_11 * V_12 = V_8 -> V_13 ;
V_12 -> V_14 = V_15 ;
F_4 ( V_16 , V_9 + V_17 ) ;
F_5 ( V_9 + V_17 ) ;
}
static inline void F_6 ( struct V_7 * V_8 )
{
T_2 T_1 * V_9 = F_1 ( V_8 -> V_2 ) + ( V_8 -> V_10 * 0x4000 ) ;
F_4 ( V_18 , V_9 + V_19 ) ;
F_5 ( V_9 + V_17 ) ;
F_3 ( V_8 ) ;
}
static void F_7 ( struct V_7 * V_8 )
{
T_2 T_1 * V_20 = F_1 ( V_8 -> V_2 ) ;
F_4 ( 0 , V_20 + V_21 ) ;
F_3 ( V_8 ) ;
}
static void F_8 ( struct V_7 * V_8 )
{
T_2 T_1 * V_20 = F_1 ( V_8 -> V_2 ) ;
F_3 ( V_8 ) ;
F_4 ( 1 , V_20 + V_21 ) ;
}
static int F_9 ( struct V_22 * V_23 , unsigned long V_24 )
{
struct V_7 * V_8 = V_23 -> V_8 ;
F_6 ( V_8 ) ;
return F_10 ( V_23 , V_24 ) ;
}
static int F_11 ( struct V_22 * V_23 , unsigned int V_25 , T_3 * V_26 )
{
if ( V_25 > V_27 )
return - V_28 ;
* V_26 = F_12 ( V_23 -> V_8 -> V_29 . V_30 + ( V_25 * 8 ) ) ;
return 0 ;
}
static void F_13 ( struct V_7 * V_8 )
{
F_3 ( V_8 ) ;
F_14 ( V_8 ) ;
}
static int F_15 ( struct V_22 * V_23 , unsigned int V_25 , T_3 V_26 )
{
if ( V_25 > V_27 )
return - V_28 ;
F_16 ( V_26 , V_23 -> V_8 -> V_29 . V_30 + ( V_25 * 8 ) ) ;
return 0 ;
}
static unsigned int F_17 ( struct V_5 * V_6 )
{
struct V_31 * V_32 ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_11 * V_12 = V_8 -> V_13 ;
T_2 * V_33 = V_12 -> V_34 + V_35 ;
unsigned int V_36 ;
F_18 (qc->sg, sg, qc->n_elem, si) {
T_4 V_37 ;
T_3 V_38 ;
V_37 = F_19 ( V_32 ) ;
* ( V_39 * ) V_33 = F_20 ( V_37 ) ;
V_33 += sizeof( T_4 ) ;
V_38 = F_21 ( V_32 ) ;
* ( V_40 * ) V_33 = F_22 ( V_38 ) ;
V_33 += sizeof( T_4 ) ;
F_23 ( L_1 , V_36 ,
( unsigned long long ) V_37 , V_38 ) ;
}
return V_36 ;
}
static void F_24 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = V_6 -> V_8 -> V_13 ;
T_2 V_41 = V_42 , * V_43 = V_12 -> V_34 ;
T_2 V_44 = V_45 | V_46 | V_47 ;
T_4 V_37 ;
unsigned int V_48 ;
F_23 ( L_2 ) ;
F_3 ( V_6 -> V_8 ) ;
if ( V_6 -> V_49 . V_50 != V_51 )
return;
V_48 = F_17 ( V_6 ) ;
if ( ( V_6 -> V_49 . V_52 & V_53 ) )
V_44 |= V_54 ;
if ( ( V_6 -> V_49 . V_52 & V_55 ) )
V_41 |= V_56 ;
V_43 [ 0 ] = V_57 ;
V_43 [ 1 ] = V_44 ;
* ( V_40 * ) ( & V_43 [ 4 ] ) = F_22 ( V_6 -> V_58 ) ;
* ( V_40 * ) ( & V_43 [ 8 ] ) = F_22 ( V_48 ) ;
V_37 = ( ( T_4 ) V_12 -> V_59 ) + V_35 ;
* ( V_39 * ) ( & V_43 [ 16 ] ) = F_20 ( V_37 ) ;
V_43 [ 24 ] = V_60 ;
V_43 [ 28 ] = V_41 ;
F_25 ( & V_6 -> V_49 , 0 , 1 , & V_43 [ 32 ] ) ;
}
static inline void F_26 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_2 T_1 * V_9 = F_1 ( V_8 -> V_2 ) + ( V_8 -> V_10 * 0x4000 ) ;
F_23 ( L_3 , V_8 ) ;
F_4 ( V_61 , V_9 + V_17 ) ;
F_27 () ;
F_16 ( V_62 , V_9 + V_63 ) ;
F_12 ( V_9 + V_63 ) ;
}
static unsigned int F_28 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = V_6 -> V_8 -> V_13 ;
switch ( V_6 -> V_49 . V_50 ) {
case V_51 :
V_12 -> V_14 = V_64 ;
F_26 ( V_6 ) ;
return 0 ;
case V_65 :
F_29 () ;
break;
default:
break;
}
V_12 -> V_14 = V_15 ;
return F_30 ( V_6 ) ;
}
static void F_31 ( struct V_5 * V_6 , T_2 V_66 )
{
V_6 -> V_67 |= F_32 ( V_66 ) ;
if ( ! V_6 -> V_67 ) {
F_33 ( V_6 ) ;
} else {
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_68 * V_69 = & V_8 -> V_23 . V_70 ;
F_34 ( V_69 ) ;
F_35 ( V_69 , L_4 , V_66 ) ;
if ( V_6 -> V_67 == V_71 )
F_36 ( V_8 ) ;
else
F_37 ( V_8 ) ;
}
}
static inline unsigned int F_38 ( struct V_1 * V_2 )
{
unsigned int V_72 = 0 ;
T_2 V_73 ;
T_2 T_1 * V_20 = F_1 ( V_2 ) ;
do {
T_3 V_74 = F_12 ( V_20 + V_75 ) ;
T_3 V_76 = F_12 ( V_20 + V_75 + 4 ) ;
T_2 V_77 = ( V_76 >> 30 ) & 0x01 ;
V_73 = V_76 >> 31 ;
if ( V_77 ) {
T_2 V_78 = V_74 >> 16 ;
T_2 V_79 = V_76 & 0x3f ;
unsigned int V_10 = ( V_76 >> 8 ) & 0x03 ;
struct V_7 * V_8 = V_2 -> V_80 [ V_10 ] ;
struct V_11 * V_12 = V_8 -> V_13 ;
struct V_5 * V_6 ;
F_39 ( L_5 ,
V_76 , V_74 , V_10 , V_79 , V_78 ) ;
V_72 = 1 ;
if ( ! V_12 || V_12 -> V_14 != V_64 )
continue;
V_6 = F_40 ( V_8 , V_8 -> V_23 . V_81 ) ;
if ( V_6 && ( ! ( V_6 -> V_49 . V_52 & V_82 ) ) ) {
switch ( V_79 ) {
case 0 :
case 3 :
F_3 ( V_6 -> V_8 ) ;
F_31 ( V_6 , V_78 ) ;
break;
default:
break;
}
}
}
} while ( ! V_73 );
return V_72 ;
}
static inline unsigned int F_41 ( struct V_1 * V_2 )
{
unsigned int V_72 = 0 , V_10 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_83 ; ++ V_10 ) {
struct V_7 * V_8 = V_2 -> V_80 [ V_10 ] ;
struct V_11 * V_12 = V_8 -> V_13 ;
struct V_5 * V_6 ;
V_6 = F_40 ( V_8 , V_8 -> V_23 . V_81 ) ;
if ( ! V_6 ) {
F_42 ( V_8 ) ;
V_72 = 1 ;
continue;
}
if ( ! V_12 || V_12 -> V_14 != V_15 )
continue;
if ( ! ( V_6 -> V_49 . V_52 & V_82 ) )
V_72 |= F_43 ( V_8 , V_6 ) ;
}
return V_72 ;
}
static T_5 F_44 ( int V_84 , void * V_85 )
{
struct V_1 * V_2 = V_85 ;
unsigned int V_72 = 0 ;
unsigned long V_52 ;
F_23 ( L_2 ) ;
F_45 ( & V_2 -> V_86 , V_52 ) ;
V_72 = F_38 ( V_2 ) | F_41 ( V_2 ) ;
F_46 ( & V_2 -> V_86 , V_52 ) ;
F_23 ( L_6 ) ;
return F_47 ( V_72 ) ;
}
static void F_48 ( struct V_87 * V_88 , void T_1 * V_89 )
{
V_88 -> V_90 =
V_88 -> V_91 = V_89 + 0x400 ;
V_88 -> V_92 =
V_88 -> V_93 = V_89 + 0x408 ;
V_88 -> V_94 = V_89 + 0x410 ;
V_88 -> V_95 = V_89 + 0x418 ;
V_88 -> V_96 = V_89 + 0x420 ;
V_88 -> V_97 = V_89 + 0x428 ;
V_88 -> V_98 = V_89 + 0x430 ;
V_88 -> V_99 =
V_88 -> V_100 = V_89 + 0x438 ;
V_88 -> V_101 =
V_88 -> V_102 = V_89 + 0x440 ;
V_88 -> V_30 = V_89 + 0xc00 ;
}
static int F_49 ( struct V_7 * V_8 )
{
struct V_103 * V_104 = V_8 -> V_2 -> V_104 ;
struct V_11 * V_12 ;
void T_1 * V_20 = F_1 ( V_8 -> V_2 ) ;
void T_1 * V_9 = V_20 + ( V_8 -> V_10 * 0x4000 ) ;
T_4 V_37 ;
V_12 = F_50 ( V_104 , sizeof( * V_12 ) , V_105 ) ;
if ( ! V_12 )
return - V_106 ;
V_12 -> V_34 = F_51 ( V_104 , V_107 , & V_12 -> V_59 ,
V_105 ) ;
if ( ! V_12 -> V_34 )
return - V_106 ;
memset ( V_12 -> V_34 , 0 , V_107 ) ;
V_8 -> V_13 = V_12 ;
F_3 ( V_8 ) ;
V_37 = ( T_4 ) V_12 -> V_59 ;
F_16 ( ( T_3 ) V_37 , V_9 + V_108 ) ;
F_16 ( ( T_3 ) ( V_37 >> 32 ) , V_9 + V_108 + 4 ) ;
return 0 ;
}
static void F_52 ( struct V_1 * V_2 )
{
void T_1 * V_20 = F_1 ( V_2 ) ;
F_4 ( 0 , V_20 + V_21 ) ;
F_4 ( V_109 , V_20 + V_110 ) ;
}
static void F_53 ( struct V_1 * V_2 , unsigned int V_111 )
{
void T_1 * V_20 = V_2 -> V_3 [ V_4 ] ;
unsigned int V_10 ;
F_4 ( 0 , V_20 + V_21 ) ;
F_4 ( V_109 , V_20 + V_110 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_83 ; ++ V_10 ) {
T_2 T_1 * V_9 = V_20 + ( V_10 * 0x4000 ) ;
F_4 ( V_112 | V_18 , V_9 + V_19 ) ;
F_4 ( V_16 , V_9 + V_17 ) ;
F_5 ( V_9 + V_17 ) ;
}
F_4 ( V_113 , V_20 + V_114 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_83 ; ++ V_10 ) {
T_2 T_1 * V_9 = V_20 + ( V_10 * 0x4000 ) ;
F_54 ( 32 , V_9 + V_115 ) ;
F_54 ( 32 , V_9 + V_116 ) ;
F_54 ( 10 , V_9 + V_117 ) ;
F_54 ( 8 , V_9 + V_118 ) ;
F_4 ( V_119 , V_9 + V_120 ) ;
}
F_4 ( 1 , V_20 + V_21 ) ;
}
static int F_55 ( struct V_121 * V_122 , void T_1 * V_20 )
{
T_3 V_123 = F_12 ( V_20 + V_124 ) ;
int V_125 , V_126 = ( V_123 & V_127 ) ;
if ( V_126 &&
! F_56 ( V_122 , F_57 ( 64 ) ) ) {
V_125 = F_58 ( V_122 , F_57 ( 64 ) ) ;
if ( V_125 ) {
V_125 = F_58 ( V_122 , F_57 ( 32 ) ) ;
if ( V_125 ) {
F_59 ( & V_122 -> V_104 ,
L_7 ) ;
return V_125 ;
}
}
} else {
V_125 = F_56 ( V_122 , F_57 ( 32 ) ) ;
if ( V_125 ) {
F_59 ( & V_122 -> V_104 , L_8 ) ;
return V_125 ;
}
V_125 = F_58 ( V_122 , F_57 ( 32 ) ) ;
if ( V_125 ) {
F_59 ( & V_122 -> V_104 ,
L_9 ) ;
return V_125 ;
}
}
return 0 ;
}
static int F_60 ( struct V_121 * V_122 ,
const struct V_128 * V_129 )
{
unsigned int V_130 = ( unsigned int ) V_129 -> V_131 ;
const struct V_132 * V_133 [] = { & V_134 [ V_130 ] , NULL } ;
struct V_1 * V_2 ;
int V_125 , V_10 ;
F_61 ( & V_122 -> V_104 , V_135 ) ;
V_2 = F_62 ( & V_122 -> V_104 , V_133 , V_136 ) ;
if ( ! V_2 )
return - V_106 ;
V_125 = F_63 ( V_122 ) ;
if ( V_125 )
return V_125 ;
if ( ( F_64 ( V_122 , V_4 ) & V_137 ) == 0 )
return - V_138 ;
V_125 = F_65 ( V_122 , 1 << V_4 , V_139 ) ;
if ( V_125 )
return V_125 ;
V_2 -> V_3 = F_66 ( V_122 ) ;
V_125 = F_55 ( V_122 , V_2 -> V_3 [ V_4 ] ) ;
if ( V_125 )
return V_125 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_83 ; ++ V_10 ) {
struct V_7 * V_8 = V_2 -> V_80 [ V_10 ] ;
unsigned int V_140 = V_10 * 0x4000 ;
void T_1 * V_9 = V_2 -> V_3 [ V_4 ] + V_140 ;
F_48 ( & V_8 -> V_29 , V_9 ) ;
F_67 ( V_8 , V_4 , - 1 , L_10 ) ;
F_67 ( V_8 , V_4 , V_140 , L_11 ) ;
}
F_53 ( V_2 , V_130 ) ;
F_68 ( V_122 ) ;
return F_69 ( V_2 , V_122 -> V_84 , F_44 , V_141 ,
& V_142 ) ;
}
static int T_6 F_70 ( void )
{
return F_71 ( & V_143 ) ;
}
static void T_7 F_72 ( void )
{
F_73 ( & V_143 ) ;
}

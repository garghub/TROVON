static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 = 0 ;
T_1 V_6 = 0 ;
F_3 ( V_2 , V_7 , & V_5 ) ;
F_3 ( V_2 , V_8 , & V_6 ) ;
F_4 ( L_1 , V_9 ,
V_4 -> V_10 == 1 ? L_2 : L_3 ) ;
F_4 ( L_4 ,
F_5 ( V_4 -> V_11 + V_12 ) , F_5 ( V_4 -> V_11 + V_13 ) & 0xFFF ,
F_5 ( V_4 -> V_11 + V_14 ) ,
F_6 ( V_5 ) ,
F_7 ( V_6 ) , F_8 ( V_6 ) ) ;
}
static void F_9 ( struct V_3 * V_4 )
{
F_4 ( L_5 , F_5 ( V_4 -> V_11 + V_15 ) ) ;
}
static void F_10 ( struct V_16 * V_17 )
{
F_11 ( V_17 , L_6 ,
V_9 , ( V_17 -> V_18 == 0 ) ? 'A' : 'B' ) ;
}
static int
F_12 ( struct V_19 * V_20 , struct V_21 * V_22 , int V_23 ,
T_1 V_24 , T_1 V_25 , T_1 V_26 , T_1 V_27 )
{
T_1 V_28 = V_29 * ( 1 << V_23 ) ;
memset ( V_22 , 0 , sizeof( struct V_21 ) ) ;
V_22 -> V_30 = F_13 ( V_20 -> V_2 ,
V_28 + V_31 , & V_22 -> V_32 ) ;
if ( ! V_22 -> V_30 ) {
F_14 ( L_7 ) ;
F_15 ( - V_33 ) ;
}
V_22 -> V_24 = V_24 ;
V_22 -> V_25 = V_25 ;
V_22 -> V_26 = V_26 ;
V_22 -> V_27 = V_27 ;
V_22 -> V_34 = 0 ;
V_22 -> V_35 = 0 ;
V_22 -> V_28 = V_28 ;
V_22 -> V_36 = V_28 - 1 ;
F_16 ( V_20 , V_24 , ( V_37 ) ( ( V_22 -> V_32 & V_38 ) | V_23 ) ) ;
F_16 ( V_20 , V_25 , F_17 ( V_22 -> V_32 ) ) ;
F_15 ( 0 ) ;
}
static void F_18 ( struct V_19 * V_20 , struct V_21 * V_22 )
{
V_39 ;
if ( V_22 -> V_30 ) {
F_19 ( V_20 -> V_2 ,
V_22 -> V_28 + V_31 , V_22 -> V_30 , V_22 -> V_32 ) ;
V_22 -> V_30 = NULL ;
}
F_15 () ;
}
static void F_20 ( struct V_19 * V_20 )
{
V_37 V_40 = F_21 ( V_20 , V_41 ) & V_42 ;
if ( ! V_40 ) {
if ( F_22 ( V_20 -> V_17 ) ) {
F_23 ( V_20 -> V_17 ) ;
F_24 ( V_20 -> V_17 ) ;
F_25 ( V_20 -> V_17 , L_8 ) ;
}
} else {
if ( ! F_22 ( V_20 -> V_17 ) ) {
F_26 ( V_20 -> V_17 ) ;
F_27 ( V_20 -> V_17 ) ;
F_25 ( V_20 -> V_17 , L_9 ) ;
}
}
}
static void F_28 ( struct V_19 * V_20 , V_37 V_43 )
{
if ( V_43 & V_44 ) {
F_29 ( V_20 , & V_20 -> V_45 ) ;
F_30 ( L_10 ) ;
}
if ( V_43 & V_46 )
F_20 ( V_20 ) ;
if ( V_43 & V_47 )
F_25 ( V_20 -> V_17 , L_11 ) ;
if ( V_43 & V_48 )
F_25 ( V_20 -> V_17 , L_12 ) ;
}
static T_2 F_31 ( int V_49 , void * V_50 )
{
struct V_16 * V_17 = V_50 ;
struct V_19 * V_20 = F_32 ( V_17 ) ;
V_37 V_43 ;
V_39 ;
V_43 = ( F_21 ( V_20 , V_51 ) & V_52 ) ;
if ( F_33 ( ! V_43 ) ) {
F_34 ( V_20 ) ;
return V_53 ;
}
if ( V_43 & V_54 )
F_28 ( V_20 , V_43 ) ;
if ( V_43 & ( V_55 | V_56 ) ) {
if ( F_35 ( F_36 ( & V_20 -> V_57 ) ) ) {
F_37 ( & V_20 -> V_57 ) ;
F_15 ( V_58 ) ;
} else {
F_21 ( V_20 , V_59 ) ;
F_21 ( V_20 , V_60 ) ;
}
}
F_34 ( V_20 ) ;
F_15 ( V_58 ) ;
}
static int F_38 ( struct V_61 * V_57 , int V_62 )
{
struct V_19 * V_20 = F_39 ( V_57 , struct V_19 , V_57 ) ;
int V_63 ;
V_39 ;
F_40 ( V_20 ) ;
V_63 = F_41 ( V_20 , & V_20 -> V_64 , V_62 ) ;
if ( ( V_63 < V_62 ) ||
( V_20 -> V_65 ++ >= 30 ) ) {
F_30 ( L_13 ) ;
V_20 -> V_65 = 0 ;
F_42 ( V_57 ) ;
F_34 ( V_20 ) ;
}
return V_63 ;
}
static int F_43 ( struct V_19 * V_20 )
{
const struct V_66 * V_67 = NULL ;
int V_68 , V_69 ;
int V_70 ;
V_39 ;
V_68 = F_21 ( V_20 , V_71 ) ;
if ( ! F_21 ( V_20 , V_72 ) && V_68 ) {
V_70 = F_44 ( & V_67 , L_14 , & V_20 -> V_2 -> V_50 ) ;
if ( V_70 )
goto V_73;
F_45 ( V_20 , ( char * ) V_67 -> V_74 , V_67 -> V_75 ) ;
F_46 ( 100 ) ;
}
for ( V_69 = 0 ; V_69 < 200 ; V_69 ++ ) {
if ( F_21 ( V_20 , V_72 ) ) {
V_70 = 0 ;
goto V_73;
}
F_46 ( 2 ) ;
}
V_70 = - V_76 ;
V_73:
if ( V_68 )
F_16 ( V_20 , V_71 , 1 ) ;
if ( V_67 )
F_47 ( V_67 ) ;
if ( V_70 ) {
F_25 ( V_20 -> V_17 , L_15 ) ;
if ( V_70 == - V_76 )
F_30 ( L_16 ,
F_21 ( V_20 , V_77 ) ,
F_21 ( V_20 , V_78 ) ,
F_21 ( V_20 , V_72 ) , V_69 ) ;
F_15 ( V_70 ) ;
} else {
F_30 ( L_17 , V_20 -> V_17 -> V_79 ) ;
F_15 ( 0 ) ;
}
}
static void F_48 ( struct V_16 * V_17 , struct V_19 * V_20 )
{
V_37 V_80 ;
V_39 ;
F_30 ( L_18 ,
F_21 ( V_20 , V_81 ) ,
F_21 ( V_20 , V_82 ) , F_21 ( V_20 , V_83 ) ) ;
V_80 = ( V_17 -> V_84 [ 0 ] << 8 ) | ( V_17 -> V_84 [ 1 ] ) ;
F_16 ( V_20 , V_83 , V_80 ) ;
V_80 = ( V_17 -> V_84 [ 2 ] << 8 ) | ( V_17 -> V_84 [ 3 ] ) ;
F_16 ( V_20 , V_82 , V_80 ) ;
V_80 = ( V_17 -> V_84 [ 4 ] << 8 ) | ( V_17 -> V_84 [ 5 ] ) ;
F_16 ( V_20 , V_81 , V_80 ) ;
F_30 ( L_18 ,
F_21 ( V_20 , V_81 ) ,
F_21 ( V_20 , V_82 ) , F_21 ( V_20 , V_83 ) ) ;
F_15 () ;
}
static int F_49 ( struct V_19 * V_20 )
{
int V_70 = - V_76 ;
struct V_16 * V_17 = V_20 -> V_17 ;
V_39 ;
F_20 ( V_20 ) ;
F_16 ( V_20 , V_85 , 0X3FE0 ) ;
F_16 ( V_20 , V_86 , 0x96 ) ;
F_16 ( V_20 , V_87 , 0x800010 ) ;
F_16 ( V_20 , V_88 , 0xE00010 ) ;
F_16 ( V_20 , V_89 , 0 ) ;
F_16 ( V_20 , V_90 , 0 ) ;
F_16 ( V_20 , V_91 ,
V_92 | V_93 | V_94 ) ;
F_16 ( V_20 , V_95 , 0 ) ;
F_16 ( V_20 , V_96 ,
V_20 -> V_45 . V_97 . V_98 & V_99 ) ;
F_30 ( L_19 , V_20 -> V_100 ) ;
F_16 ( V_20 , V_101 , V_20 -> V_100 ) ;
F_16 ( V_20 , V_102 , 0 ) ;
F_30 ( L_20 , V_20 -> V_103 ) ;
F_16 ( V_20 , V_104 , V_20 -> V_103 ) ;
F_48 ( V_20 -> V_17 , V_20 ) ;
F_16 ( V_20 , V_105 , V_106 |
V_107 | V_108 ) ;
#define F_50 ((priv->nic->irq_type == IRQ_MSI) ? 0 : IRQF_SHARED)
V_70 = F_51 ( V_20 -> V_2 -> V_49 , F_31 , F_50 ,
V_17 -> V_79 , V_17 ) ;
if ( V_70 )
goto V_109;
F_34 ( V_20 ) ;
F_15 ( 0 ) ;
V_109:
F_15 ( V_70 ) ;
}
static void F_52 ( struct V_19 * V_20 )
{
V_39 ;
F_53 ( V_20 ) ;
F_54 ( V_20 -> V_2 -> V_49 , V_20 -> V_17 ) ;
F_24 ( V_20 -> V_17 ) ;
F_23 ( V_20 -> V_17 ) ;
F_15 () ;
}
static int F_55 ( void T_3 * V_11 )
{
V_37 V_80 , V_69 ;
V_39 ;
V_80 = F_5 ( V_11 + V_110 ) ;
F_56 ( ( V_80 | V_111 ) + 0x8 , V_11 + V_110 ) ;
F_57 ( 50 ) ;
V_80 = F_5 ( V_11 + V_110 ) ;
F_56 ( V_80 & ~ V_111 , V_11 + V_110 ) ;
for ( V_69 = 0 ; V_69 < 70 ; V_69 ++ , F_46 ( 10 ) )
if ( ( F_5 ( V_11 + V_110 ) & V_112 ) == V_112 ) {
F_5 ( V_11 + V_113 ) ;
return 0 ;
}
F_14 ( L_21 ) ;
return 1 ;
}
static int F_58 ( struct V_19 * V_20 )
{
V_37 V_80 , V_69 ;
V_39 ;
if ( V_20 -> V_114 == 0 ) {
V_80 = F_21 ( V_20 , V_110 ) ;
F_16 ( V_20 , V_110 , ( V_80 | V_111 ) + 0x8 ) ;
F_57 ( 50 ) ;
V_80 = F_21 ( V_20 , V_110 ) ;
F_16 ( V_20 , V_110 , V_80 & ~ V_111 ) ;
}
for ( V_69 = 0 ; V_69 < 70 ; V_69 ++ , F_46 ( 10 ) )
if ( ( F_21 ( V_20 , V_110 ) & V_112 ) == V_112 ) {
F_21 ( V_20 , V_113 ) ;
return 0 ;
}
F_14 ( L_21 ) ;
return 1 ;
}
static int F_59 ( struct V_19 * V_20 )
{
int V_69 ;
V_39 ;
F_16 ( V_20 , V_105 , 0 ) ;
F_46 ( 100 ) ;
F_16 ( V_20 , V_115 , 1 ) ;
F_16 ( V_20 , V_116 , 1 ) ;
for ( V_69 = 0 ; V_69 < 50 ; V_69 ++ ) {
if ( F_21 ( V_20 , V_117 ) & 1 )
break;
F_46 ( 10 ) ;
}
if ( V_69 == 50 )
F_25 ( V_20 -> V_17 , L_22 ) ;
F_16 ( V_20 , V_101 , 0 ) ;
F_16 ( V_20 , V_104 , 0 ) ;
F_16 ( V_20 , V_118 , 0 ) ;
F_21 ( V_20 , V_51 ) ;
F_16 ( V_20 , V_119 , 1 ) ;
F_16 ( V_20 , V_117 , 1 ) ;
for ( V_69 = V_120 ; V_69 <= V_121 ; V_69 += 0x10 )
F_30 ( L_23 , V_69 , F_21 ( V_20 , V_69 ) & V_122 ) ;
for ( V_69 = V_120 ; V_69 <= V_121 ; V_69 += 0x10 )
F_16 ( V_20 , V_69 , 0 ) ;
F_16 ( V_20 , V_115 , 0 ) ;
F_16 ( V_20 , V_116 , 0 ) ;
F_16 ( V_20 , V_119 , 0 ) ;
F_16 ( V_20 , V_117 , 0 ) ;
for ( V_69 = V_120 ; V_69 <= V_121 ; V_69 += 0x10 )
F_30 ( L_23 , V_69 , F_21 ( V_20 , V_69 ) & V_122 ) ;
F_15 ( 0 ) ;
}
static int F_60 ( struct V_19 * V_20 )
{
V_39 ;
F_15 ( ( V_20 -> V_2 -> V_123 == 0x3009 )
? F_58 ( V_20 )
: F_59 ( V_20 ) ) ;
}
static int F_61 ( struct V_16 * V_17 )
{
struct V_19 * V_20 = NULL ;
V_39 ;
V_20 = F_32 ( V_17 ) ;
F_62 ( & V_20 -> V_57 ) ;
F_60 ( V_20 ) ;
F_52 ( V_20 ) ;
F_63 ( V_20 ) ;
F_64 ( V_20 ) ;
F_15 ( 0 ) ;
}
static int F_65 ( struct V_16 * V_17 )
{
struct V_19 * V_20 ;
int V_70 ;
V_39 ;
V_20 = F_32 ( V_17 ) ;
F_60 ( V_20 ) ;
if ( F_66 ( V_17 ) )
F_23 ( V_20 -> V_17 ) ;
if ( ( V_70 = F_67 ( V_20 ) ) ||
( V_70 = F_68 ( V_20 ) ) ||
( V_70 = F_43 ( V_20 ) ) )
goto V_124;
F_29 ( V_20 , & V_20 -> V_45 ) ;
V_70 = F_49 ( V_20 ) ;
if ( V_70 )
goto V_124;
F_69 ( & V_20 -> V_57 ) ;
F_9 ( V_20 -> V_4 ) ;
F_15 ( 0 ) ;
V_124:
F_61 ( V_17 ) ;
F_15 ( V_70 ) ;
}
static int F_70 ( struct V_19 * V_20 , V_37 V_125 )
{
return ( V_125 > ( V_37 ) ( V_126 / V_20 -> V_4 -> V_10 ) ) ?
- V_127 : 0 ;
}
static int F_71 ( struct V_16 * V_17 , struct V_128 * V_129 , int V_130 )
{
struct V_19 * V_20 = F_32 ( V_17 ) ;
V_37 V_74 [ 3 ] ;
int error ;
V_39 ;
F_30 ( L_24 , V_131 , V_130 ) ;
if ( V_130 != V_132 ) {
error = F_72 ( V_74 , V_129 -> V_133 , sizeof( V_74 ) ) ;
if ( error ) {
F_14 ( L_25 ) ;
F_15 ( - V_134 ) ;
}
F_30 ( L_26 , V_74 [ 0 ] , V_74 [ 1 ] , V_74 [ 2 ] ) ;
}
if ( ! F_73 ( V_135 ) )
return - V_136 ;
switch ( V_74 [ 0 ] ) {
case V_137 :
error = F_70 ( V_20 , V_74 [ 1 ] ) ;
if ( error < 0 )
return error ;
V_74 [ 2 ] = F_21 ( V_20 , V_74 [ 1 ] ) ;
F_30 ( L_27 , V_74 [ 1 ] , V_74 [ 2 ] ,
V_74 [ 2 ] ) ;
error = F_74 ( V_129 -> V_133 , V_74 , sizeof( V_74 ) ) ;
if ( error )
F_15 ( - V_134 ) ;
break;
case V_138 :
error = F_70 ( V_20 , V_74 [ 1 ] ) ;
if ( error < 0 )
return error ;
F_16 ( V_20 , V_74 [ 1 ] , V_74 [ 2 ] ) ;
F_30 ( L_28 , V_74 [ 1 ] , V_74 [ 2 ] ) ;
break;
default:
F_15 ( - V_139 ) ;
}
return 0 ;
}
static int F_75 ( struct V_16 * V_17 , struct V_128 * V_129 , int V_130 )
{
V_39 ;
if ( V_130 >= V_132 && V_130 <= ( V_132 + 15 ) )
F_15 ( F_71 ( V_17 , V_129 , V_130 ) ) ;
else
F_15 ( - V_139 ) ;
}
static void F_76 ( struct V_16 * V_17 , T_4 V_140 , int V_141 )
{
struct V_19 * V_20 = F_32 ( V_17 ) ;
V_37 V_142 , V_143 , V_80 ;
V_39 ;
F_77 ( L_29 , ( int ) V_140 , V_141 ) ;
if ( F_33 ( V_140 >= 4096 ) ) {
F_14 ( L_30 , V_140 ) ;
F_15 () ;
}
V_142 = V_144 + ( V_140 / 32 ) * 4 ;
V_143 = 1 << V_140 % 32 ;
V_80 = F_21 ( V_20 , V_142 ) ;
F_77 ( L_31 , V_142 , V_80 , V_143 ) ;
if ( V_141 )
V_80 |= V_143 ;
else
V_80 &= ~ V_143 ;
F_77 ( L_32 , V_80 ) ;
F_16 ( V_20 , V_142 , V_80 ) ;
F_15 () ;
}
static void F_78 ( struct V_16 * V_17 , T_4 V_140 )
{
F_76 ( V_17 , V_140 , 1 ) ;
}
static void F_79 ( struct V_16 * V_17 , unsigned short V_140 )
{
F_76 ( V_17 , V_140 , 0 ) ;
}
static void
F_80 ( struct V_16 * V_17 , struct V_145 * V_146 )
{
struct V_19 * V_20 = F_32 ( V_17 ) ;
V_39 ;
F_30 ( L_33 , V_17 -> V_79 , V_146 ) ;
V_20 -> V_147 = V_146 ;
F_15 () ;
}
static int F_81 ( struct V_16 * V_17 , int V_148 )
{
V_39 ;
if ( V_148 == V_17 -> V_149 )
F_15 ( 0 ) ;
if ( V_148 < V_150 ) {
F_25 ( V_17 , L_34 ,
V_148 , V_150 ) ;
F_15 ( - V_127 ) ;
}
V_17 -> V_149 = V_148 ;
if ( F_66 ( V_17 ) ) {
F_61 ( V_17 ) ;
F_65 ( V_17 ) ;
}
F_15 ( 0 ) ;
}
static void F_82 ( struct V_16 * V_17 )
{
struct V_19 * V_20 = F_32 ( V_17 ) ;
V_37 V_151 =
V_107 | V_108 | V_106 ;
int V_69 ;
V_39 ;
if ( V_17 -> V_152 & V_153 ) {
V_151 |= V_154 ;
} else if ( V_17 -> V_152 & V_155 ) {
for ( V_69 = 0 ; V_69 < V_156 ; V_69 ++ )
F_16 ( V_20 , V_157 + V_69 * 4 , ~ 0 ) ;
} else if ( ! F_83 ( V_17 ) ) {
T_5 V_158 ;
struct V_159 * V_160 ;
V_37 V_142 , V_80 ;
for ( V_69 = 0 ; V_69 < V_156 ; V_69 ++ )
F_16 ( V_20 , V_157 + V_69 * 4 , 0 ) ;
for ( V_69 = 0 ; V_69 < V_161 ; V_69 ++ ) {
F_16 ( V_20 , V_162 + V_69 * 8 , 0 ) ;
F_16 ( V_20 , V_163 + V_69 * 8 , 0 ) ;
}
F_84 (ha, ndev) {
V_158 = 0 ;
for ( V_69 = 0 ; V_69 < V_164 ; V_69 ++ )
V_158 ^= V_160 -> V_165 [ V_69 ] ;
V_142 = V_157 + ( ( V_158 >> 5 ) << 2 ) ;
V_80 = F_21 ( V_20 , V_142 ) ;
V_80 |= ( 1 << ( V_158 % 32 ) ) ;
F_16 ( V_20 , V_142 , V_80 ) ;
}
} else {
F_30 ( L_35 , F_85 ( V_17 ) ) ;
V_151 |= V_108 ;
}
F_16 ( V_20 , V_105 , V_151 ) ;
F_15 () ;
}
static int F_86 ( struct V_16 * V_17 , void * V_166 )
{
struct V_19 * V_20 = F_32 ( V_17 ) ;
struct V_167 * V_165 = V_166 ;
V_39 ;
memcpy ( V_17 -> V_84 , V_165 -> V_168 , V_17 -> V_169 ) ;
F_48 ( V_17 , V_20 ) ;
F_15 ( 0 ) ;
}
static int F_87 ( struct V_19 * V_20 )
{
T_1 V_170 [ 3 ] , V_69 ;
V_39 ;
V_170 [ 2 ] = F_21 ( V_20 , V_81 ) ;
V_170 [ 2 ] = F_21 ( V_20 , V_81 ) ;
V_170 [ 1 ] = F_21 ( V_20 , V_82 ) ;
V_170 [ 1 ] = F_21 ( V_20 , V_82 ) ;
V_170 [ 0 ] = F_21 ( V_20 , V_83 ) ;
V_170 [ 0 ] = F_21 ( V_20 , V_83 ) ;
for ( V_69 = 0 ; V_69 < 3 ; V_69 ++ ) {
V_20 -> V_17 -> V_84 [ V_69 * 2 + 1 ] = V_170 [ V_69 ] ;
V_20 -> V_17 -> V_84 [ V_69 * 2 ] = V_170 [ V_69 ] >> 8 ;
}
F_15 ( 0 ) ;
}
static T_6 F_88 ( struct V_19 * V_20 , int V_142 )
{
T_6 V_80 ;
V_80 = F_21 ( V_20 , V_142 ) ;
V_80 |= ( ( T_6 ) F_21 ( V_20 , V_142 + 8 ) ) << 32 ;
return V_80 ;
}
static void F_89 ( struct V_19 * V_20 )
{
struct V_171 * V_172 = & V_20 -> V_173 ;
T_6 * V_174 = ( T_6 * ) V_172 ;
int V_69 ;
int V_165 ;
V_165 = 0x7200 ;
for ( V_69 = 0 ; V_69 < 12 ; V_69 ++ ) {
V_174 [ V_69 ] = F_88 ( V_20 , V_165 ) ;
V_165 += 0x10 ;
}
F_90 ( V_165 != 0x72C0 ) ;
V_165 = 0x72F0 ;
for (; V_69 < 16 ; V_69 ++ ) {
V_174 [ V_69 ] = F_88 ( V_20 , V_165 ) ;
V_165 += 0x10 ;
}
F_90 ( V_165 != 0x7330 ) ;
V_165 = 0x7370 ;
for (; V_69 < 19 ; V_69 ++ ) {
V_174 [ V_69 ] = F_88 ( V_20 , V_165 ) ;
V_165 += 0x10 ;
}
F_90 ( V_165 != 0x73A0 ) ;
V_165 = 0x73C0 ;
for (; V_69 < 23 ; V_69 ++ ) {
V_174 [ V_69 ] = F_88 ( V_20 , V_165 ) ;
V_165 += 0x10 ;
}
F_90 ( V_165 != 0x7400 ) ;
F_90 ( ( sizeof( struct V_171 ) / sizeof( T_6 ) ) != V_69 ) ;
}
static void F_91 ( struct V_175 * V_176 )
{
F_92 ( V_176 ) ;
}
static struct V_175 * F_93 ( int V_177 )
{
struct V_175 * V_176 ;
int V_69 ;
V_176 = F_94 ( sizeof( struct V_175 )
+ ( V_177 * sizeof( int ) )
+ ( V_177 * sizeof( struct V_178 ) ) ) ;
if ( F_35 ( V_176 != NULL ) ) {
V_176 -> V_179 = ( int * ) ( V_176 + 1 ) ;
V_176 -> V_180 = ( void * ) ( V_176 -> V_179 + V_177 ) ;
V_176 -> V_177 = V_177 ;
V_176 -> V_181 = V_177 ;
for ( V_69 = 0 ; V_69 < V_177 ; V_69 ++ )
V_176 -> V_179 [ V_69 ] = V_177 - V_69 - 1 ;
}
return V_176 ;
}
static inline int F_95 ( struct V_175 * V_176 )
{
F_90 ( V_176 -> V_181 <= 0 ) ;
return V_176 -> V_179 [ -- ( V_176 -> V_181 ) ] ;
}
static inline void * F_96 ( struct V_175 * V_176 , int V_182 )
{
F_90 ( ( V_182 < 0 ) || ( V_182 >= V_176 -> V_177 ) ) ;
return V_176 -> V_180 + V_182 ;
}
static inline int F_97 ( struct V_175 * V_176 )
{
return V_176 -> V_181 ;
}
static inline void F_98 ( struct V_175 * V_176 , int V_182 )
{
F_90 ( ( V_182 >= V_176 -> V_177 ) || ( V_182 < 0 ) ) ;
V_176 -> V_179 [ ( V_176 -> V_181 ) ++ ] = V_182 ;
}
static int F_68 ( struct V_19 * V_20 )
{
V_39 ;
if ( F_12 ( V_20 , & V_20 -> V_64 . V_97 , V_20 -> V_183 ,
V_113 , V_184 ,
V_185 , V_60 ) )
goto V_186;
if ( F_12 ( V_20 , & V_20 -> V_45 . V_97 , V_20 -> V_187 ,
V_188 , V_189 ,
V_190 , V_191 ) )
goto V_186;
V_20 -> V_175 = F_93 ( V_20 -> V_45 . V_97 . V_28 /
sizeof( struct V_192 ) ) ;
if ( ! V_20 -> V_175 )
goto V_186;
V_20 -> V_45 . V_97 . V_98 = V_20 -> V_17 -> V_149 + V_193 ;
return 0 ;
V_186:
F_25 ( V_20 -> V_17 , L_36 ) ;
return - V_33 ;
}
static void F_99 ( struct V_19 * V_20 , struct V_194 * V_22 )
{
struct V_178 * V_195 ;
struct V_175 * V_176 = V_20 -> V_175 ;
T_1 V_69 ;
V_39 ;
F_30 ( L_37 , V_176 -> V_177 , F_97 ( V_176 ) ,
V_176 -> V_177 - F_97 ( V_176 ) ) ;
while ( F_97 ( V_176 ) > 0 ) {
V_69 = F_95 ( V_176 ) ;
V_195 = F_96 ( V_176 , V_69 ) ;
V_195 -> V_196 = 0 ;
}
for ( V_69 = 0 ; V_69 < V_176 -> V_177 ; V_69 ++ ) {
V_195 = F_96 ( V_176 , V_69 ) ;
if ( V_195 -> V_196 ) {
F_100 ( V_20 -> V_2 ,
V_195 -> V_196 , V_22 -> V_97 . V_98 ,
V_197 ) ;
F_101 ( V_195 -> V_198 ) ;
}
}
}
static void F_63 ( struct V_19 * V_20 )
{
V_39 ;
if ( V_20 -> V_175 ) {
F_99 ( V_20 , & V_20 -> V_45 ) ;
F_91 ( V_20 -> V_175 ) ;
V_20 -> V_175 = NULL ;
}
F_18 ( V_20 , & V_20 -> V_45 . V_97 ) ;
F_18 ( V_20 , & V_20 -> V_64 . V_97 ) ;
F_15 () ;
}
static void F_29 ( struct V_19 * V_20 , struct V_194 * V_22 )
{
struct V_199 * V_198 ;
struct V_192 * V_200 ;
struct V_178 * V_195 ;
int V_201 , V_202 , V_203 ;
struct V_175 * V_176 = V_20 -> V_175 ;
V_39 ;
V_201 = F_97 ( V_176 ) - 1 ;
while ( V_201 > 0 ) {
V_198 = F_102 ( V_22 -> V_97 . V_98 + V_204 ) ;
if ( ! V_198 ) {
F_14 ( L_38 ) ;
break;
}
V_198 -> V_50 = V_20 -> V_17 ;
F_103 ( V_198 , V_204 ) ;
V_203 = F_95 ( V_176 ) ;
V_195 = F_96 ( V_176 , V_203 ) ;
V_195 -> V_196 = F_104 ( V_20 -> V_2 ,
V_198 -> V_74 , V_22 -> V_97 . V_98 ,
V_197 ) ;
V_195 -> V_198 = V_198 ;
V_200 = (struct V_192 * ) ( V_22 -> V_97 . V_30 + V_22 -> V_97 . V_35 ) ;
V_200 -> V_205 = F_105 ( 0x10003 ) ;
V_200 -> V_206 = V_203 ;
V_200 -> V_207 = F_105 ( F_106 ( V_195 -> V_196 ) ) ;
V_200 -> V_208 = F_105 ( F_17 ( V_195 -> V_196 ) ) ;
V_200 -> V_209 = F_105 ( V_22 -> V_97 . V_98 ) ;
F_107 ( V_200 ) ;
V_22 -> V_97 . V_35 += sizeof( struct V_192 ) ;
V_202 = V_22 -> V_97 . V_35 - V_22 -> V_97 . V_28 ;
if ( F_33 ( V_202 >= 0 ) ) {
V_22 -> V_97 . V_35 = V_202 ;
if ( V_202 > 0 ) {
memcpy ( V_22 -> V_97 . V_30 , V_22 -> V_97 . V_30 + V_22 -> V_97 . V_28 , V_202 ) ;
F_30 ( L_39 ) ;
}
}
V_201 -- ;
}
F_16 ( V_20 , V_22 -> V_97 . V_27 , V_22 -> V_97 . V_35 & V_122 ) ;
F_15 () ;
}
static inline void
F_108 ( struct V_19 * V_20 , V_37 V_210 , T_1 V_211 ,
struct V_199 * V_198 )
{
V_39 ;
F_30 ( L_40 , F_109 ( V_210 ) ,
V_20 -> V_147 ) ;
if ( V_20 -> V_147 && F_109 ( V_210 ) ) {
F_30 ( L_41 ,
V_20 -> V_17 -> V_79 ,
F_110 ( V_211 ) ,
F_109 ( V_210 ) ,
F_111 ( V_20 -> V_147 ,
F_110 ( V_211 ) ) -> V_79 ) ;
F_112 ( V_198 , V_20 -> V_147 ,
F_113 ( V_211 ) ) ;
} else {
F_114 ( V_198 ) ;
}
}
static void F_115 ( struct V_19 * V_20 , struct V_212 * V_213 )
{
struct V_192 * V_200 ;
struct V_178 * V_195 ;
struct V_194 * V_22 ;
struct V_175 * V_176 ;
struct V_199 * V_198 ;
int V_202 ;
V_39 ;
F_30 ( L_42 , V_20 , V_213 ) ;
V_22 = & V_20 -> V_45 ;
V_176 = V_20 -> V_175 ;
F_30 ( L_43 , V_176 , V_22 ) ;
V_195 = F_96 ( V_176 , V_213 -> V_206 ) ;
F_30 ( L_44 , V_195 ) ;
V_198 = V_195 -> V_198 ;
V_200 = (struct V_192 * ) ( V_22 -> V_97 . V_30 + V_22 -> V_97 . V_35 ) ;
V_200 -> V_205 = F_105 ( 0x10003 ) ;
V_200 -> V_206 = V_213 -> V_206 ;
V_200 -> V_207 = F_105 ( F_106 ( V_195 -> V_196 ) ) ;
V_200 -> V_208 = F_105 ( F_17 ( V_195 -> V_196 ) ) ;
V_200 -> V_209 = F_105 ( V_22 -> V_97 . V_98 ) ;
F_107 ( V_200 ) ;
V_22 -> V_97 . V_35 += sizeof( struct V_192 ) ;
V_202 = V_22 -> V_97 . V_35 - V_22 -> V_97 . V_28 ;
if ( F_33 ( V_202 >= 0 ) ) {
V_22 -> V_97 . V_35 = V_202 ;
if ( V_202 > 0 ) {
memcpy ( V_22 -> V_97 . V_30 , V_22 -> V_97 . V_30 + V_22 -> V_97 . V_28 , V_202 ) ;
F_30 ( L_39 ) ;
}
}
F_15 () ;
}
static int F_41 ( struct V_19 * V_20 , struct V_214 * V_22 , int V_62 )
{
struct V_16 * V_17 = V_20 -> V_17 ;
struct V_199 * V_198 , * V_215 ;
struct V_212 * V_213 ;
struct V_178 * V_195 ;
struct V_194 * V_194 ;
int V_216 , V_75 ;
int V_217 = 0 ;
int V_218 = V_219 ;
struct V_175 * V_176 = NULL ;
V_37 V_210 ;
T_1 V_209 ;
T_1 V_211 ;
V_39 ;
V_218 = V_62 ;
V_22 -> V_97 . V_35 = F_21 ( V_20 , V_22 -> V_97 . V_27 ) & V_122 ;
V_75 = V_22 -> V_97 . V_35 - V_22 -> V_97 . V_34 ;
if ( V_75 < 0 )
V_75 = V_22 -> V_97 . V_28 + V_75 ;
while ( V_75 > 0 ) {
V_213 = (struct V_212 * ) ( V_22 -> V_97 . V_30 + V_22 -> V_97 . V_34 ) ;
V_210 = F_105 ( V_213 -> V_210 ) ;
V_209 = F_116 ( V_213 -> V_209 ) ;
V_211 = F_116 ( V_213 -> V_211 ) ;
F_117 ( V_213 , V_210 , V_209 , V_211 ) ;
V_216 = F_118 ( V_210 ) << 3 ;
F_90 ( V_216 <= 0 ) ;
V_75 -= V_216 ;
if ( V_75 < 0 )
break;
V_22 -> V_97 . V_34 += V_216 ;
V_216 = V_22 -> V_97 . V_34 - V_22 -> V_97 . V_28 ;
if ( F_33 ( V_216 >= 0 ) ) {
V_22 -> V_97 . V_34 = V_216 ;
if ( V_216 > 0 ) {
F_30 ( L_45 ,
V_22 -> V_97 . V_34 , V_216 ) ;
memcpy ( V_22 -> V_97 . V_30 + V_22 -> V_97 . V_28 , V_22 -> V_97 . V_30 , V_216 ) ;
}
}
if ( F_33 ( F_119 ( V_210 ) ) ) {
F_30 ( L_46 , F_119 ( V_210 ) ) ;
V_17 -> V_172 . V_220 ++ ;
F_115 ( V_20 , V_213 ) ;
continue;
}
V_194 = & V_20 -> V_45 ;
V_176 = V_20 -> V_175 ;
V_195 = F_96 ( V_176 , V_213 -> V_206 ) ;
V_198 = V_195 -> V_198 ;
if ( V_209 < V_221 &&
( V_215 = F_102 ( V_209 + V_204 ) ) ) {
F_103 ( V_215 , V_204 ) ;
F_120 ( V_20 -> V_2 ,
V_195 -> V_196 , V_194 -> V_97 . V_98 ,
V_197 ) ;
memcpy ( V_215 -> V_74 , V_198 -> V_74 , V_209 ) ;
F_115 ( V_20 , V_213 ) ;
V_198 = V_215 ;
} else {
F_100 ( V_20 -> V_2 ,
V_195 -> V_196 , V_194 -> V_97 . V_98 ,
V_197 ) ;
F_98 ( V_176 , V_213 -> V_206 ) ;
}
V_17 -> V_172 . V_222 += V_209 ;
F_121 ( V_198 , V_209 ) ;
V_198 -> V_223 = F_122 ( V_198 , V_17 ) ;
if ( F_123 ( V_210 ) == 0 )
F_124 ( V_198 ) ;
else
V_198 -> V_224 = V_225 ;
F_108 ( V_20 , V_210 , V_211 , V_198 ) ;
if ( ++ V_217 >= V_218 )
break;
}
V_17 -> V_172 . V_226 += V_217 ;
F_16 ( V_20 , V_22 -> V_97 . V_26 , V_22 -> V_97 . V_34 & V_122 ) ;
F_29 ( V_20 , & V_20 -> V_45 ) ;
F_15 ( V_217 ) ;
}
static void F_117 ( struct V_212 * V_213 , V_37 V_210 , T_1 V_209 ,
T_1 V_211 )
{
F_30 ( L_47 ,
F_118 ( V_210 ) , F_125 ( V_210 ) , F_126 ( V_210 ) ,
F_127 ( V_210 ) , F_119 ( V_210 ) ,
F_128 ( V_210 ) , F_123 ( V_210 ) ,
F_109 ( V_210 ) , V_209 , F_110 ( V_211 ) ,
F_129 ( V_211 ) , F_130 ( V_211 ) , V_213 -> V_206 ,
V_213 -> V_227 ) ;
}
static void F_107 ( struct V_192 * V_200 )
{
F_30 ( L_48
L_49 ,
V_200 -> V_205 , V_200 -> V_206 , V_200 -> V_207 , V_200 -> V_208 , V_200 -> V_209 ) ;
}
static inline int F_131 ( struct V_228 * V_176 )
{
int V_229 = V_176 -> V_35 - V_176 -> V_34 ;
if ( V_229 < 0 )
V_229 = V_176 -> V_75 + 1 + V_229 ;
return V_176 -> V_75 - V_229 ;
}
static inline void F_132 ( struct V_228 * V_176 , struct V_230 * * V_231 )
{
F_90 ( V_176 == NULL || V_231 == NULL ) ;
F_90 ( * V_231 != V_176 -> V_34 &&
* V_231 != V_176 -> V_35 ) ;
F_90 ( * V_231 < V_176 -> V_232 ||
* V_231 >= V_176 -> V_233 ) ;
++ * V_231 ;
if ( F_33 ( * V_231 == V_176 -> V_233 ) )
* V_231 = V_176 -> V_232 ;
}
static inline void F_133 ( struct V_228 * V_176 )
{
F_90 ( V_176 -> V_34 == V_176 -> V_35 ) ;
F_132 ( V_176 , & V_176 -> V_34 ) ;
}
static inline void F_134 ( struct V_228 * V_176 )
{
F_132 ( V_176 , & V_176 -> V_35 ) ;
F_90 ( V_176 -> V_34 == V_176 -> V_35 ) ;
}
static int F_135 ( struct V_228 * V_234 , int V_235 )
{
int V_28 = V_29 * ( 1 << ( V_235 + 1 ) ) ;
V_234 -> V_232 = F_94 ( V_28 ) ;
if ( ! V_234 -> V_232 )
return - V_33 ;
V_234 -> V_75 = V_28 / sizeof( struct V_230 ) - 1 ;
V_234 -> V_233 = V_234 -> V_232 + V_234 -> V_75 + 1 ;
V_234 -> V_34 = V_234 -> V_232 ;
V_234 -> V_35 = V_234 -> V_232 ;
return 0 ;
}
static void F_136 ( struct V_228 * V_234 )
{
F_90 ( V_234 == NULL ) ;
F_92 ( V_234 -> V_232 ) ;
V_234 -> V_232 = NULL ;
}
static inline void
F_137 ( struct V_19 * V_20 , struct V_199 * V_198 ,
struct V_236 * V_237 )
{
struct V_228 * V_176 = & V_20 -> V_228 ;
struct V_238 * V_238 = & V_237 -> V_238 [ 0 ] ;
int V_239 = F_138 ( V_198 ) -> V_239 ;
int V_69 ;
V_176 -> V_35 -> V_209 = F_139 ( V_198 ) ;
V_176 -> V_35 -> V_165 . V_196 = F_104 ( V_20 -> V_2 , V_198 -> V_74 ,
V_176 -> V_35 -> V_209 , V_240 ) ;
V_238 -> V_209 = F_105 ( V_176 -> V_35 -> V_209 ) ;
V_238 -> V_207 = F_105 ( F_106 ( V_176 -> V_35 -> V_165 . V_196 ) ) ;
V_238 -> V_208 = F_105 ( F_17 ( V_176 -> V_35 -> V_165 . V_196 ) ) ;
F_30 ( L_50 , V_238 -> V_209 ) ;
F_30 ( L_51 , V_238 -> V_207 ) ;
F_30 ( L_52 , V_238 -> V_208 ) ;
F_134 ( V_176 ) ;
for ( V_69 = 0 ; V_69 < V_239 ; V_69 ++ ) {
struct V_241 * V_242 ;
V_242 = & F_138 ( V_198 ) -> V_243 [ V_69 ] ;
V_176 -> V_35 -> V_209 = V_242 -> V_75 ;
V_176 -> V_35 -> V_165 . V_196 =
F_140 ( V_20 -> V_2 , V_242 -> V_244 , V_242 -> V_245 ,
V_242 -> V_75 , V_240 ) ;
V_238 ++ ;
V_238 -> V_209 = F_105 ( V_176 -> V_35 -> V_209 ) ;
V_238 -> V_207 = F_105 ( F_106 ( V_176 -> V_35 -> V_165 . V_196 ) ) ;
V_238 -> V_208 = F_105 ( F_17 ( V_176 -> V_35 -> V_165 . V_196 ) ) ;
F_134 ( V_176 ) ;
}
V_176 -> V_35 -> V_209 = - V_246 [ V_239 ] . V_247 ;
V_176 -> V_35 -> V_165 . V_198 = V_198 ;
F_134 ( V_176 ) ;
}
static void T_7 F_141 ( void )
{
int V_69 , V_248 ;
for ( V_69 = 0 ; V_69 < V_249 + 1 ; V_69 ++ ) {
V_248 = 7 + ( V_69 * 3 ) ;
if ( V_248 & 1 )
V_248 ++ ;
V_246 [ V_69 ] . V_250 = V_248 >> 1 ;
V_246 [ V_69 ] . V_247 = V_248 << 2 ;
}
}
static int F_67 ( struct V_19 * V_20 )
{
if ( F_12 ( V_20 , & V_20 -> V_251 . V_97 , V_20 -> V_252 ,
V_253 ,
V_254 , V_255 , V_120 ) )
goto V_186;
if ( F_12 ( V_20 , & V_20 -> V_256 . V_97 , V_20 -> V_257 ,
V_258 ,
V_259 , V_260 , V_59 ) )
goto V_186;
if ( F_135 ( & V_20 -> V_228 , F_142 ( V_20 -> V_252 , V_20 -> V_257 ) ) )
goto V_186;
V_20 -> V_261 = V_262 ;
#ifdef F_143
V_20 -> V_263 = V_20 -> V_261 - 1024 ;
#endif
return 0 ;
V_186:
F_25 ( V_20 -> V_17 , L_53 ) ;
return - V_33 ;
}
static inline int F_144 ( struct V_19 * V_20 )
{
struct V_264 * V_22 = & V_20 -> V_251 ;
int V_265 ;
V_22 -> V_97 . V_34 = F_21 ( V_20 , V_22 -> V_97 . V_26 ) & V_122 ;
V_265 = V_22 -> V_97 . V_34 - V_22 -> V_97 . V_35 ;
if ( V_265 <= 0 )
V_265 = V_22 -> V_97 . V_28 + V_265 ;
return V_265 ;
}
static T_8 F_145 ( struct V_199 * V_198 ,
struct V_16 * V_17 )
{
struct V_19 * V_20 = F_32 ( V_17 ) ;
struct V_264 * V_22 = & V_20 -> V_251 ;
int V_266 = 7 ;
int V_267 = 0 ;
int V_268 = 0 ;
int V_269 = 0 ;
int V_270 = 0 ;
int V_239 = F_138 ( V_198 ) -> V_239 ;
struct V_236 * V_237 ;
int V_209 ;
unsigned long V_152 ;
V_39 ;
F_146 ( V_152 ) ;
if ( ! F_147 ( & V_20 -> V_271 ) ) {
F_148 ( V_152 ) ;
F_30 ( L_54 ,
V_272 , V_17 -> V_79 ) ;
return V_273 ;
}
F_90 ( V_22 -> V_97 . V_35 >= V_22 -> V_97 . V_28 ) ;
V_237 = (struct V_236 * ) ( V_22 -> V_97 . V_30 + V_22 -> V_97 . V_35 ) ;
if ( F_33 ( V_198 -> V_224 != V_274 ) )
V_266 = 0 ;
if ( F_138 ( V_198 ) -> V_275 ) {
V_270 = F_138 ( V_198 ) -> V_275 ;
V_267 = 1 ;
F_30 ( L_55 , V_198 , V_198 -> V_209 ,
V_270 ) ;
}
if ( F_149 ( V_198 ) ) {
V_268 = F_150 ( V_198 ) & F_151 ( 12 ) ;
V_269 = 1 ;
}
V_237 -> V_276 = F_116 ( V_198 -> V_209 ) ;
V_237 -> V_277 = F_116 ( V_270 ) ;
V_237 -> V_278 =
F_105 ( F_152
( V_246 [ V_239 ] . V_250 , V_266 , V_269 ,
V_267 , V_268 ) ) ;
F_30 ( L_56 ) ;
F_30 ( L_57 , V_237 -> V_278 ) ;
F_30 ( L_58 , V_237 -> V_277 , V_237 -> V_276 ) ;
F_137 ( V_20 , V_198 , V_237 ) ;
V_22 -> V_97 . V_35 += V_246 [ V_239 ] . V_247 ;
V_209 = V_22 -> V_97 . V_35 - V_22 -> V_97 . V_28 ;
if ( F_33 ( V_209 >= 0 ) ) {
V_22 -> V_97 . V_35 = V_209 ;
if ( V_209 > 0 ) {
F_90 ( V_209 > V_22 -> V_97 . V_28 ) ;
memcpy ( V_22 -> V_97 . V_30 , V_22 -> V_97 . V_30 + V_22 -> V_97 . V_28 , V_209 ) ;
}
}
F_90 ( V_22 -> V_97 . V_35 >= V_22 -> V_97 . V_28 ) ;
V_20 -> V_261 -= V_246 [ V_239 ] . V_247 ;
F_90 ( V_20 -> V_261 <= 0 || V_20 -> V_261 > V_262 ) ;
#ifdef F_143
if ( V_20 -> V_261 > V_20 -> V_263 ) {
F_16 ( V_20 , V_22 -> V_97 . V_27 , V_22 -> V_97 . V_35 & V_122 ) ;
} else {
if ( V_20 -> V_279 ++ > V_280 ) {
V_20 -> V_279 = 0 ;
F_16 ( V_20 , V_22 -> V_97 . V_27 ,
V_22 -> V_97 . V_35 & V_122 ) ;
}
}
#else
F_16 ( V_20 , V_22 -> V_97 . V_27 , V_22 -> V_97 . V_35 & V_122 ) ;
#endif
#ifdef F_153
V_17 -> V_281 = V_131 ;
#endif
V_17 -> V_172 . V_282 ++ ;
V_17 -> V_172 . V_283 += V_198 -> V_209 ;
if ( V_20 -> V_261 < V_284 ) {
F_30 ( L_59 ,
V_272 , V_17 -> V_79 , V_20 -> V_261 ) ;
F_23 ( V_17 ) ;
}
F_154 ( & V_20 -> V_271 , V_152 ) ;
return V_285 ;
}
static void F_40 ( struct V_19 * V_20 )
{
struct V_286 * V_22 = & V_20 -> V_256 ;
struct V_228 * V_176 = & V_20 -> V_228 ;
int V_261 = 0 ;
V_39 ;
V_22 -> V_97 . V_35 = F_21 ( V_20 , V_22 -> V_97 . V_27 ) & V_287 ;
F_90 ( V_22 -> V_97 . V_34 >= V_22 -> V_97 . V_28 ) ;
while ( V_22 -> V_97 . V_35 != V_22 -> V_97 . V_34 ) {
V_22 -> V_97 . V_34 += V_288 ;
V_22 -> V_97 . V_34 &= V_22 -> V_97 . V_36 ;
F_90 ( V_176 -> V_34 -> V_209 == 0 ) ;
do {
F_90 ( V_176 -> V_34 -> V_165 . V_196 == 0 ) ;
F_155 ( V_20 -> V_2 , V_176 -> V_34 -> V_165 . V_196 ,
V_176 -> V_34 -> V_209 , V_240 ) ;
F_133 ( V_176 ) ;
} while ( V_176 -> V_34 -> V_209 > 0 );
V_261 -= V_176 -> V_34 -> V_209 ;
F_156 ( V_176 -> V_34 -> V_165 . V_198 ) ;
F_133 ( V_176 ) ;
}
F_90 ( ( V_22 -> V_97 . V_35 & V_122 ) >= V_22 -> V_97 . V_28 ) ;
F_16 ( V_20 , V_22 -> V_97 . V_26 , V_22 -> V_97 . V_34 & V_122 ) ;
F_157 ( & V_20 -> V_271 ) ;
V_20 -> V_261 += V_261 ;
F_90 ( V_20 -> V_261 <= 0 || V_20 -> V_261 > V_262 ) ;
#ifdef F_143
if ( V_20 -> V_279 ) {
V_20 -> V_279 = 0 ;
F_16 ( V_20 , V_20 -> V_251 . V_97 . V_27 ,
V_20 -> V_251 . V_97 . V_35 & V_122 ) ;
}
#endif
if ( F_33 ( F_158 ( V_20 -> V_17 ) &&
F_22 ( V_20 -> V_17 ) &&
( V_20 -> V_261 >= V_284 ) ) ) {
F_30 ( L_60 ,
V_272 , V_20 -> V_17 -> V_79 , V_20 -> V_261 ) ;
F_26 ( V_20 -> V_17 ) ;
}
F_159 ( & V_20 -> V_271 ) ;
}
static void F_160 ( struct V_19 * V_20 )
{
struct V_228 * V_176 = & V_20 -> V_228 ;
V_39 ;
while ( V_176 -> V_34 != V_176 -> V_35 ) {
if ( F_35 ( V_176 -> V_34 -> V_209 ) )
F_155 ( V_20 -> V_2 , V_176 -> V_34 -> V_165 . V_196 ,
V_176 -> V_34 -> V_209 , V_240 ) ;
else
F_101 ( V_176 -> V_34 -> V_165 . V_198 ) ;
F_133 ( V_176 ) ;
}
F_15 () ;
}
static void F_64 ( struct V_19 * V_20 )
{
V_39 ;
F_160 ( V_20 ) ;
F_18 ( V_20 , & V_20 -> V_251 . V_97 ) ;
F_18 ( V_20 , & V_20 -> V_256 . V_97 ) ;
F_136 ( & V_20 -> V_228 ) ;
}
static void F_161 ( struct V_19 * V_20 , void * V_74 , int V_75 )
{
struct V_264 * V_22 = & V_20 -> V_251 ;
int V_69 = V_22 -> V_97 . V_28 - V_22 -> V_97 . V_35 ;
if ( V_75 == 0 )
return;
if ( V_69 > V_75 ) {
memcpy ( V_22 -> V_97 . V_30 + V_22 -> V_97 . V_35 , V_74 , V_75 ) ;
V_22 -> V_97 . V_35 += V_75 ;
} else {
memcpy ( V_22 -> V_97 . V_30 + V_22 -> V_97 . V_35 , V_74 , V_69 ) ;
V_22 -> V_97 . V_35 = V_75 - V_69 ;
memcpy ( V_22 -> V_97 . V_30 , V_74 + V_69 , V_22 -> V_97 . V_35 ) ;
}
F_16 ( V_20 , V_22 -> V_97 . V_27 , V_22 -> V_97 . V_35 & V_122 ) ;
}
static void F_45 ( struct V_19 * V_20 , void * V_74 , int V_75 )
{
int V_289 = 0 ;
V_39 ;
while ( V_75 > 0 ) {
int V_290 = F_144 ( V_20 ) - 8 ;
if ( V_290 <= 0 ) {
if ( V_289 ++ > 300 ) {
F_30 ( L_61 ) ;
break;
}
F_57 ( 50 ) ;
continue;
}
V_290 = F_162 ( V_290 , V_75 ) ;
F_30 ( L_62 , V_290 ,
V_74 , V_75 ) ;
F_161 ( V_20 , V_74 , V_290 ) ;
V_75 -= V_290 ;
V_74 += V_290 ;
}
F_15 () ;
}
static int T_9
F_163 ( struct V_1 * V_2 , const struct V_291 * V_292 )
{
struct V_16 * V_17 ;
struct V_19 * V_20 ;
int V_124 , V_293 , V_114 ;
unsigned long V_294 ;
V_37 V_295 ;
struct V_3 * V_4 ;
V_39 ;
V_4 = F_94 ( sizeof( * V_4 ) ) ;
if ( ! V_4 )
F_15 ( - V_33 ) ;
V_124 = F_164 ( V_2 ) ;
if ( V_124 )
goto V_296;
if ( ! ( V_124 = F_165 ( V_2 , F_166 ( 64 ) ) ) &&
! ( V_124 = F_167 ( V_2 , F_166 ( 64 ) ) ) ) {
V_293 = 1 ;
} else {
if ( ( V_124 = F_165 ( V_2 , F_166 ( 32 ) ) ) ||
( V_124 = F_167 ( V_2 , F_166 ( 32 ) ) ) ) {
F_14 ( L_63 ) ;
goto V_297;
}
V_293 = 0 ;
}
V_124 = F_168 ( V_2 , V_272 ) ;
if ( V_124 )
goto V_297;
F_169 ( V_2 ) ;
V_294 = F_170 ( V_2 , 0 ) ;
if ( ! V_294 ) {
V_124 = - V_76 ;
F_14 ( L_64 ) ;
goto V_298;
}
V_295 = F_171 ( V_2 , 0 ) ;
if ( V_295 < V_126 ) {
V_124 = - V_76 ;
F_14 ( L_65 , V_295 ) ;
goto V_298;
}
V_4 -> V_11 = F_172 ( V_294 , V_295 ) ;
if ( ! V_4 -> V_11 ) {
V_124 = - V_76 ;
F_14 ( L_66 ) ;
goto V_298;
}
if ( V_2 -> V_49 < 2 ) {
V_124 = - V_76 ;
F_14 ( L_67 , V_2 -> V_49 ) ;
goto V_299;
}
F_173 ( V_2 , V_4 ) ;
if ( V_2 -> V_123 == 0x3014 )
V_4 -> V_10 = 2 ;
else
V_4 -> V_10 = 1 ;
F_1 ( V_2 ) ;
F_55 ( V_4 -> V_11 ) ;
V_4 -> V_300 = V_301 ;
#ifdef F_174
if ( ( F_5 ( V_4 -> V_11 + V_13 ) & 0xFFF ) >= 378 ) {
V_124 = F_175 ( V_2 ) ;
if ( V_124 )
F_14 ( L_68 , V_124 ) ;
else
V_4 -> V_300 = V_302 ;
} else
F_30 ( L_69 ) ;
#endif
for ( V_114 = 0 ; V_114 < V_4 -> V_10 ; V_114 ++ ) {
V_17 = F_176 ( sizeof( struct V_19 ) ) ;
if ( ! V_17 ) {
V_124 = - V_33 ;
F_14 ( L_70 ) ;
goto V_299;
}
V_17 -> V_303 = & V_304 ;
V_17 -> V_305 = V_306 ;
F_177 ( V_17 ) ;
V_17 -> V_18 = V_114 ;
V_17 -> V_307 = V_294 ;
V_17 -> V_308 = V_294 ;
V_17 -> V_309 = V_294 + V_295 ;
V_17 -> V_49 = V_2 -> V_49 ;
V_17 -> V_310 = V_311 | V_312 | V_313
| V_314 | V_315 |
V_316 | V_317
;
V_17 -> V_318 = V_311 | V_312 |
V_313 | V_314 ;
if ( V_293 )
V_17 -> V_310 |= V_319 ;
V_20 = V_4 -> V_20 [ V_114 ] = F_32 ( V_17 ) ;
V_20 -> V_320 = V_4 -> V_11 + V_114 * 0x8000 ;
V_20 -> V_114 = V_114 ;
V_20 -> V_2 = V_2 ;
V_20 -> V_17 = V_17 ;
V_20 -> V_4 = V_4 ;
V_20 -> V_321 = V_322 ;
F_178 ( V_17 , & V_20 -> V_57 , F_38 , 64 ) ;
if ( ( F_5 ( V_4 -> V_11 + V_13 ) & 0xFFF ) == 308 ) {
F_30 ( L_71 ) ;
V_20 -> V_323 = 0 ;
} else {
V_20 -> V_323 = 1 ;
}
V_20 -> V_252 = 2 ;
V_20 -> V_257 = 2 ;
V_20 -> V_183 = 2 ;
V_20 -> V_187 = 3 ;
V_20 -> V_100 = F_179 ( 0x20 , 1 , 4 , 12 ) ;
V_20 -> V_103 = F_179 ( 0x20 , 1 , 0 , 12 ) ;
#ifdef F_153
V_17 -> V_310 |= V_324 ;
#endif
F_180 ( & V_20 -> V_271 ) ;
if ( F_87 ( V_20 ) ) {
F_14 ( L_72 ) ;
goto V_299;
}
F_181 ( V_17 , & V_2 -> V_50 ) ;
V_124 = F_182 ( V_17 ) ;
if ( V_124 ) {
F_14 ( L_73 ) ;
goto V_325;
}
F_24 ( V_17 ) ;
F_23 ( V_17 ) ;
F_10 ( V_17 ) ;
}
F_15 ( 0 ) ;
V_325:
F_183 ( V_17 ) ;
V_299:
F_184 ( V_4 -> V_11 ) ;
V_298:
F_185 ( V_2 ) ;
V_297:
F_186 ( V_2 ) ;
V_296:
F_92 ( V_4 ) ;
F_15 ( V_124 ) ;
}
static int F_187 ( struct V_16 * V_326 , struct V_327 * V_328 )
{
V_37 V_100 ;
V_37 V_103 ;
struct V_19 * V_20 = F_32 ( V_326 ) ;
V_100 = V_20 -> V_100 ;
V_103 = V_20 -> V_103 ;
V_328 -> V_329 = ( V_330 | V_331 ) ;
V_328 -> V_332 = ( V_333 | V_334 ) ;
F_188 ( V_328 , V_335 ) ;
V_328 -> V_336 = V_337 ;
V_328 -> V_114 = V_338 ;
V_328 -> V_339 = V_340 ;
V_328 -> V_341 = V_342 ;
V_328 -> V_343 =
( ( F_189 ( V_103 ) * V_344 ) / V_288 ) ;
V_328 -> V_345 =
( ( F_189 ( V_100 ) * V_344 ) / sizeof( struct V_192 ) ) ;
return 0 ;
}
static void
F_190 ( struct V_16 * V_326 , struct V_346 * V_347 )
{
struct V_19 * V_20 = F_32 ( V_326 ) ;
F_191 ( V_347 -> V_348 , V_272 , sizeof( V_347 -> V_348 ) ) ;
F_191 ( V_347 -> V_349 , V_350 , sizeof( V_347 -> V_349 ) ) ;
F_191 ( V_347 -> V_351 , L_74 , sizeof( V_347 -> V_351 ) ) ;
F_191 ( V_347 -> V_352 , F_192 ( V_20 -> V_2 ) ,
sizeof( V_347 -> V_352 ) ) ;
V_347 -> V_353 = ( ( V_20 -> V_323 ) ? F_193 ( V_354 ) : 0 ) ;
V_347 -> V_355 = 0 ;
V_347 -> V_356 = 0 ;
V_347 -> V_357 = 0 ;
}
static int
F_194 ( struct V_16 * V_326 , struct V_358 * V_359 )
{
V_37 V_100 ;
V_37 V_103 ;
struct V_19 * V_20 = F_32 ( V_326 ) ;
V_100 = V_20 -> V_100 ;
V_103 = V_20 -> V_103 ;
V_359 -> V_360 = F_195 ( V_100 ) * V_361 ;
V_359 -> V_362 =
( ( F_189 ( V_100 ) * V_344 ) / sizeof( struct V_192 ) ) ;
V_359 -> V_363 = F_195 ( V_103 ) * V_361 ;
V_359 -> V_364 =
( ( F_189 ( V_103 ) * V_344 ) / V_288 ) ;
return 0 ;
}
static int
F_196 ( struct V_16 * V_326 , struct V_358 * V_359 )
{
V_37 V_100 ;
V_37 V_103 ;
struct V_19 * V_20 = F_32 ( V_326 ) ;
int V_365 ;
int V_366 ;
int V_367 ;
int V_368 ;
V_365 = V_359 -> V_360 / V_361 ;
V_366 = V_359 -> V_363 / V_361 ;
V_367 = V_359 -> V_362 ;
V_368 = V_359 -> V_364 ;
V_367 =
( ( ( V_367 * sizeof( struct V_192 ) ) + V_344 - 1 )
/ V_344 ) ;
V_368 =
( ( ( V_368 * V_288 ) + V_344 - 1 )
/ V_344 ) ;
if ( ( V_365 > 0x7FFF ) || ( V_366 > 0x7FFF ) ||
( V_367 > 0xF ) || ( V_368 > 0xF ) )
return - V_127 ;
V_100 = F_179 ( V_365 , F_197 ( V_20 -> V_100 ) ,
F_198 ( V_20 -> V_100 ) , V_367 ) ;
V_103 = F_179 ( V_366 , F_197 ( V_20 -> V_103 ) , 0 ,
V_368 ) ;
V_20 -> V_100 = V_100 ;
V_20 -> V_103 = V_103 ;
F_16 ( V_20 , V_101 , V_100 ) ;
F_16 ( V_20 , V_104 , V_103 ) ;
return 0 ;
}
static inline int F_199 ( int V_369 )
{
return ( V_29 * ( 1 << V_369 ) ) / sizeof( struct V_192 ) ;
}
static inline int F_200 ( int V_370 )
{
return ( V_29 * ( 1 << V_370 ) ) / V_288 ;
}
static void
F_201 ( struct V_16 * V_326 , struct V_371 * V_372 )
{
struct V_19 * V_20 = F_32 ( V_326 ) ;
V_372 -> V_373 = F_199 ( 3 ) ;
V_372 -> V_374 = F_200 ( 3 ) ;
V_372 -> V_375 = F_199 ( V_20 -> V_187 ) ;
V_372 -> V_376 = F_200 ( V_20 -> V_252 ) ;
}
static int
F_202 ( struct V_16 * V_326 , struct V_371 * V_372 )
{
struct V_19 * V_20 = F_32 ( V_326 ) ;
int V_369 = 0 ;
int V_370 = 0 ;
for (; V_369 < 4 ; V_369 ++ ) {
if ( F_199 ( V_369 ) >= V_372 -> V_375 )
break;
}
if ( V_369 == 4 )
V_369 = 3 ;
for (; V_370 < 4 ; V_370 ++ ) {
if ( F_200 ( V_370 ) >= V_372 -> V_376 )
break;
}
if ( V_370 == 4 )
V_370 = 3 ;
if ( ( V_369 == V_20 -> V_187 ) &&
( V_370 == V_20 -> V_252 ) )
return 0 ;
V_20 -> V_187 = V_369 ;
if ( V_369 > 1 )
V_20 -> V_183 = V_369 - 1 ;
else
V_20 -> V_183 = V_369 ;
V_20 -> V_257 = V_20 -> V_252 = V_370 ;
if ( F_66 ( V_326 ) ) {
F_61 ( V_326 ) ;
F_65 ( V_326 ) ;
}
return 0 ;
}
static void F_203 ( struct V_16 * V_326 , V_37 V_377 , T_5 * V_74 )
{
switch ( V_377 ) {
case V_378 :
memcpy ( V_74 , * V_354 , sizeof( V_354 ) ) ;
break;
}
}
static int F_204 ( struct V_16 * V_326 , int V_377 )
{
struct V_19 * V_20 = F_32 ( V_326 ) ;
switch ( V_377 ) {
case V_378 :
F_90 ( F_193 ( V_354 )
!= sizeof( struct V_171 ) / sizeof( T_6 ) ) ;
return ( V_20 -> V_323 ) ? F_193 ( V_354 ) : 0 ;
}
return - V_127 ;
}
static void F_205 ( struct V_16 * V_326 ,
struct V_379 * V_172 , T_6 * V_74 )
{
struct V_19 * V_20 = F_32 ( V_326 ) ;
if ( V_20 -> V_323 ) {
F_89 ( V_20 ) ;
memcpy ( V_74 , & V_20 -> V_173 , sizeof( V_20 -> V_173 ) ) ;
}
}
static void F_177 ( struct V_16 * V_326 )
{
static const struct V_380 V_381 = {
. V_382 = F_187 ,
. V_383 = F_190 ,
. V_384 = V_385 ,
. V_386 = F_194 ,
. V_387 = F_196 ,
. V_388 = F_201 ,
. V_389 = F_202 ,
. V_390 = F_203 ,
. V_391 = F_204 ,
. V_392 = F_205 ,
} ;
F_206 ( V_326 , & V_381 ) ;
}
static void T_10 F_207 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_16 * V_17 ;
int V_114 ;
for ( V_114 = 0 ; V_114 < V_4 -> V_10 ; V_114 ++ ) {
V_17 = V_4 -> V_20 [ V_114 ] -> V_17 ;
F_208 ( V_17 ) ;
F_183 ( V_17 ) ;
}
#ifdef F_174
if ( V_4 -> V_300 == V_302 )
F_209 ( V_2 ) ;
#endif
F_184 ( V_4 -> V_11 ) ;
F_185 ( V_2 ) ;
F_186 ( V_2 ) ;
F_173 ( V_2 , NULL ) ;
F_92 ( V_4 ) ;
F_15 () ;
}
static void T_7 F_210 ( void )
{
F_4 ( L_75 , V_393 , V_350 ) ;
F_4 ( L_76 , V_394 ) ;
}
static int T_7 F_211 ( void )
{
V_39 ;
F_141 () ;
F_210 () ;
F_15 ( F_212 ( & V_395 ) ) ;
}
static void T_11 F_213 ( void )
{
V_39 ;
F_214 ( & V_395 ) ;
F_15 () ;
}

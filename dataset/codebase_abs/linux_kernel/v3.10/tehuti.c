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
static int F_78 ( struct V_16 * V_17 , T_5 V_145 , T_1 V_140 )
{
F_76 ( V_17 , V_140 , 1 ) ;
return 0 ;
}
static int F_79 ( struct V_16 * V_17 , T_5 V_145 , T_1 V_140 )
{
F_76 ( V_17 , V_140 , 0 ) ;
return 0 ;
}
static int F_80 ( struct V_16 * V_17 , int V_146 )
{
V_39 ;
if ( V_146 == V_17 -> V_147 )
F_15 ( 0 ) ;
if ( V_146 < V_148 ) {
F_25 ( V_17 , L_33 ,
V_146 , V_148 ) ;
F_15 ( - V_127 ) ;
}
V_17 -> V_147 = V_146 ;
if ( F_66 ( V_17 ) ) {
F_61 ( V_17 ) ;
F_65 ( V_17 ) ;
}
F_15 ( 0 ) ;
}
static void F_81 ( struct V_16 * V_17 )
{
struct V_19 * V_20 = F_32 ( V_17 ) ;
V_37 V_149 =
V_107 | V_108 | V_106 ;
int V_69 ;
V_39 ;
if ( V_17 -> V_150 & V_151 ) {
V_149 |= V_152 ;
} else if ( V_17 -> V_150 & V_153 ) {
for ( V_69 = 0 ; V_69 < V_154 ; V_69 ++ )
F_16 ( V_20 , V_155 + V_69 * 4 , ~ 0 ) ;
} else if ( ! F_82 ( V_17 ) ) {
T_6 V_156 ;
struct V_157 * V_158 ;
V_37 V_142 , V_80 ;
for ( V_69 = 0 ; V_69 < V_154 ; V_69 ++ )
F_16 ( V_20 , V_155 + V_69 * 4 , 0 ) ;
for ( V_69 = 0 ; V_69 < V_159 ; V_69 ++ ) {
F_16 ( V_20 , V_160 + V_69 * 8 , 0 ) ;
F_16 ( V_20 , V_161 + V_69 * 8 , 0 ) ;
}
F_83 (ha, ndev) {
V_156 = 0 ;
for ( V_69 = 0 ; V_69 < V_162 ; V_69 ++ )
V_156 ^= V_158 -> V_163 [ V_69 ] ;
V_142 = V_155 + ( ( V_156 >> 5 ) << 2 ) ;
V_80 = F_21 ( V_20 , V_142 ) ;
V_80 |= ( 1 << ( V_156 % 32 ) ) ;
F_16 ( V_20 , V_142 , V_80 ) ;
}
} else {
F_30 ( L_34 , F_84 ( V_17 ) ) ;
V_149 |= V_108 ;
}
F_16 ( V_20 , V_105 , V_149 ) ;
F_15 () ;
}
static int F_85 ( struct V_16 * V_17 , void * V_164 )
{
struct V_19 * V_20 = F_32 ( V_17 ) ;
struct V_165 * V_163 = V_164 ;
V_39 ;
memcpy ( V_17 -> V_84 , V_163 -> V_166 , V_17 -> V_167 ) ;
F_48 ( V_17 , V_20 ) ;
F_15 ( 0 ) ;
}
static int F_86 ( struct V_19 * V_20 )
{
T_1 V_168 [ 3 ] , V_69 ;
V_39 ;
V_168 [ 2 ] = F_21 ( V_20 , V_81 ) ;
V_168 [ 2 ] = F_21 ( V_20 , V_81 ) ;
V_168 [ 1 ] = F_21 ( V_20 , V_82 ) ;
V_168 [ 1 ] = F_21 ( V_20 , V_82 ) ;
V_168 [ 0 ] = F_21 ( V_20 , V_83 ) ;
V_168 [ 0 ] = F_21 ( V_20 , V_83 ) ;
for ( V_69 = 0 ; V_69 < 3 ; V_69 ++ ) {
V_20 -> V_17 -> V_84 [ V_69 * 2 + 1 ] = V_168 [ V_69 ] ;
V_20 -> V_17 -> V_84 [ V_69 * 2 ] = V_168 [ V_69 ] >> 8 ;
}
F_15 ( 0 ) ;
}
static T_7 F_87 ( struct V_19 * V_20 , int V_142 )
{
T_7 V_80 ;
V_80 = F_21 ( V_20 , V_142 ) ;
V_80 |= ( ( T_7 ) F_21 ( V_20 , V_142 + 8 ) ) << 32 ;
return V_80 ;
}
static void F_88 ( struct V_19 * V_20 )
{
struct V_169 * V_170 = & V_20 -> V_171 ;
T_7 * V_172 = ( T_7 * ) V_170 ;
int V_69 ;
int V_163 ;
V_163 = 0x7200 ;
for ( V_69 = 0 ; V_69 < 12 ; V_69 ++ ) {
V_172 [ V_69 ] = F_87 ( V_20 , V_163 ) ;
V_163 += 0x10 ;
}
F_89 ( V_163 != 0x72C0 ) ;
V_163 = 0x72F0 ;
for (; V_69 < 16 ; V_69 ++ ) {
V_172 [ V_69 ] = F_87 ( V_20 , V_163 ) ;
V_163 += 0x10 ;
}
F_89 ( V_163 != 0x7330 ) ;
V_163 = 0x7370 ;
for (; V_69 < 19 ; V_69 ++ ) {
V_172 [ V_69 ] = F_87 ( V_20 , V_163 ) ;
V_163 += 0x10 ;
}
F_89 ( V_163 != 0x73A0 ) ;
V_163 = 0x73C0 ;
for (; V_69 < 23 ; V_69 ++ ) {
V_172 [ V_69 ] = F_87 ( V_20 , V_163 ) ;
V_163 += 0x10 ;
}
F_89 ( V_163 != 0x7400 ) ;
F_89 ( ( sizeof( struct V_169 ) / sizeof( T_7 ) ) != V_69 ) ;
}
static void F_90 ( struct V_173 * V_174 )
{
F_91 ( V_174 ) ;
}
static struct V_173 * F_92 ( int V_175 )
{
struct V_173 * V_174 ;
int V_69 ;
V_174 = F_93 ( sizeof( struct V_173 )
+ ( V_175 * sizeof( int ) )
+ ( V_175 * sizeof( struct V_176 ) ) ) ;
if ( F_35 ( V_174 != NULL ) ) {
V_174 -> V_177 = ( int * ) ( V_174 + 1 ) ;
V_174 -> V_178 = ( void * ) ( V_174 -> V_177 + V_175 ) ;
V_174 -> V_175 = V_175 ;
V_174 -> V_179 = V_175 ;
for ( V_69 = 0 ; V_69 < V_175 ; V_69 ++ )
V_174 -> V_177 [ V_69 ] = V_175 - V_69 - 1 ;
}
return V_174 ;
}
static inline int F_94 ( struct V_173 * V_174 )
{
F_89 ( V_174 -> V_179 <= 0 ) ;
return V_174 -> V_177 [ -- ( V_174 -> V_179 ) ] ;
}
static inline void * F_95 ( struct V_173 * V_174 , int V_180 )
{
F_89 ( ( V_180 < 0 ) || ( V_180 >= V_174 -> V_175 ) ) ;
return V_174 -> V_178 + V_180 ;
}
static inline int F_96 ( struct V_173 * V_174 )
{
return V_174 -> V_179 ;
}
static inline void F_97 ( struct V_173 * V_174 , int V_180 )
{
F_89 ( ( V_180 >= V_174 -> V_175 ) || ( V_180 < 0 ) ) ;
V_174 -> V_177 [ ( V_174 -> V_179 ) ++ ] = V_180 ;
}
static int F_68 ( struct V_19 * V_20 )
{
V_39 ;
if ( F_12 ( V_20 , & V_20 -> V_64 . V_97 , V_20 -> V_181 ,
V_113 , V_182 ,
V_183 , V_60 ) )
goto V_184;
if ( F_12 ( V_20 , & V_20 -> V_45 . V_97 , V_20 -> V_185 ,
V_186 , V_187 ,
V_188 , V_189 ) )
goto V_184;
V_20 -> V_173 = F_92 ( V_20 -> V_45 . V_97 . V_28 /
sizeof( struct V_190 ) ) ;
if ( ! V_20 -> V_173 )
goto V_184;
V_20 -> V_45 . V_97 . V_98 = V_20 -> V_17 -> V_147 + V_191 ;
return 0 ;
V_184:
F_25 ( V_20 -> V_17 , L_35 ) ;
return - V_33 ;
}
static void F_98 ( struct V_19 * V_20 , struct V_192 * V_22 )
{
struct V_176 * V_193 ;
struct V_173 * V_174 = V_20 -> V_173 ;
T_1 V_69 ;
V_39 ;
F_30 ( L_36 , V_174 -> V_175 , F_96 ( V_174 ) ,
V_174 -> V_175 - F_96 ( V_174 ) ) ;
while ( F_96 ( V_174 ) > 0 ) {
V_69 = F_94 ( V_174 ) ;
V_193 = F_95 ( V_174 , V_69 ) ;
V_193 -> V_194 = 0 ;
}
for ( V_69 = 0 ; V_69 < V_174 -> V_175 ; V_69 ++ ) {
V_193 = F_95 ( V_174 , V_69 ) ;
if ( V_193 -> V_194 ) {
F_99 ( V_20 -> V_2 ,
V_193 -> V_194 , V_22 -> V_97 . V_98 ,
V_195 ) ;
F_100 ( V_193 -> V_196 ) ;
}
}
}
static void F_63 ( struct V_19 * V_20 )
{
V_39 ;
if ( V_20 -> V_173 ) {
F_98 ( V_20 , & V_20 -> V_45 ) ;
F_90 ( V_20 -> V_173 ) ;
V_20 -> V_173 = NULL ;
}
F_18 ( V_20 , & V_20 -> V_45 . V_97 ) ;
F_18 ( V_20 , & V_20 -> V_64 . V_97 ) ;
F_15 () ;
}
static void F_29 ( struct V_19 * V_20 , struct V_192 * V_22 )
{
struct V_197 * V_196 ;
struct V_190 * V_198 ;
struct V_176 * V_193 ;
int V_199 , V_200 , V_201 ;
struct V_173 * V_174 = V_20 -> V_173 ;
V_39 ;
V_199 = F_96 ( V_174 ) - 1 ;
while ( V_199 > 0 ) {
V_196 = F_101 ( V_20 -> V_17 , V_22 -> V_97 . V_98 + V_202 ) ;
if ( ! V_196 )
break;
F_102 ( V_196 , V_202 ) ;
V_201 = F_94 ( V_174 ) ;
V_193 = F_95 ( V_174 , V_201 ) ;
V_193 -> V_194 = F_103 ( V_20 -> V_2 ,
V_196 -> V_74 , V_22 -> V_97 . V_98 ,
V_195 ) ;
V_193 -> V_196 = V_196 ;
V_198 = (struct V_190 * ) ( V_22 -> V_97 . V_30 + V_22 -> V_97 . V_35 ) ;
V_198 -> V_203 = F_104 ( 0x10003 ) ;
V_198 -> V_204 = V_201 ;
V_198 -> V_205 = F_104 ( F_105 ( V_193 -> V_194 ) ) ;
V_198 -> V_206 = F_104 ( F_17 ( V_193 -> V_194 ) ) ;
V_198 -> V_207 = F_104 ( V_22 -> V_97 . V_98 ) ;
F_106 ( V_198 ) ;
V_22 -> V_97 . V_35 += sizeof( struct V_190 ) ;
V_200 = V_22 -> V_97 . V_35 - V_22 -> V_97 . V_28 ;
if ( F_33 ( V_200 >= 0 ) ) {
V_22 -> V_97 . V_35 = V_200 ;
if ( V_200 > 0 ) {
memcpy ( V_22 -> V_97 . V_30 , V_22 -> V_97 . V_30 + V_22 -> V_97 . V_28 , V_200 ) ;
F_30 ( L_37 ) ;
}
}
V_199 -- ;
}
F_16 ( V_20 , V_22 -> V_97 . V_27 , V_22 -> V_97 . V_35 & V_122 ) ;
F_15 () ;
}
static inline void
F_107 ( struct V_19 * V_20 , V_37 V_208 , T_1 V_209 ,
struct V_197 * V_196 )
{
V_39 ;
F_30 ( L_38 , F_108 ( V_208 ) ) ;
if ( F_108 ( V_208 ) ) {
F_30 ( L_39 ,
V_20 -> V_17 -> V_79 ,
F_109 ( V_209 ) ,
F_108 ( V_208 ) ) ;
F_110 ( V_196 , F_111 ( V_210 ) , F_112 ( V_209 ) ) ;
}
F_113 ( V_196 ) ;
}
static void F_114 ( struct V_19 * V_20 , struct V_211 * V_212 )
{
struct V_190 * V_198 ;
struct V_176 * V_193 ;
struct V_192 * V_22 ;
struct V_173 * V_174 ;
struct V_197 * V_196 ;
int V_200 ;
V_39 ;
F_30 ( L_40 , V_20 , V_212 ) ;
V_22 = & V_20 -> V_45 ;
V_174 = V_20 -> V_173 ;
F_30 ( L_41 , V_174 , V_22 ) ;
V_193 = F_95 ( V_174 , V_212 -> V_204 ) ;
F_30 ( L_42 , V_193 ) ;
V_196 = V_193 -> V_196 ;
V_198 = (struct V_190 * ) ( V_22 -> V_97 . V_30 + V_22 -> V_97 . V_35 ) ;
V_198 -> V_203 = F_104 ( 0x10003 ) ;
V_198 -> V_204 = V_212 -> V_204 ;
V_198 -> V_205 = F_104 ( F_105 ( V_193 -> V_194 ) ) ;
V_198 -> V_206 = F_104 ( F_17 ( V_193 -> V_194 ) ) ;
V_198 -> V_207 = F_104 ( V_22 -> V_97 . V_98 ) ;
F_106 ( V_198 ) ;
V_22 -> V_97 . V_35 += sizeof( struct V_190 ) ;
V_200 = V_22 -> V_97 . V_35 - V_22 -> V_97 . V_28 ;
if ( F_33 ( V_200 >= 0 ) ) {
V_22 -> V_97 . V_35 = V_200 ;
if ( V_200 > 0 ) {
memcpy ( V_22 -> V_97 . V_30 , V_22 -> V_97 . V_30 + V_22 -> V_97 . V_28 , V_200 ) ;
F_30 ( L_37 ) ;
}
}
F_15 () ;
}
static int F_41 ( struct V_19 * V_20 , struct V_213 * V_22 , int V_62 )
{
struct V_16 * V_17 = V_20 -> V_17 ;
struct V_197 * V_196 , * V_214 ;
struct V_211 * V_212 ;
struct V_176 * V_193 ;
struct V_192 * V_192 ;
int V_215 , V_75 ;
int V_216 = 0 ;
int V_217 = V_218 ;
struct V_173 * V_174 = NULL ;
V_37 V_208 ;
T_1 V_207 ;
T_1 V_209 ;
V_39 ;
V_217 = V_62 ;
V_22 -> V_97 . V_35 = F_21 ( V_20 , V_22 -> V_97 . V_27 ) & V_122 ;
V_75 = V_22 -> V_97 . V_35 - V_22 -> V_97 . V_34 ;
if ( V_75 < 0 )
V_75 = V_22 -> V_97 . V_28 + V_75 ;
while ( V_75 > 0 ) {
V_212 = (struct V_211 * ) ( V_22 -> V_97 . V_30 + V_22 -> V_97 . V_34 ) ;
V_208 = F_104 ( V_212 -> V_208 ) ;
V_207 = F_115 ( V_212 -> V_207 ) ;
V_209 = F_115 ( V_212 -> V_209 ) ;
F_116 ( V_212 , V_208 , V_207 , V_209 ) ;
V_215 = F_117 ( V_208 ) << 3 ;
F_89 ( V_215 <= 0 ) ;
V_75 -= V_215 ;
if ( V_75 < 0 )
break;
V_22 -> V_97 . V_34 += V_215 ;
V_215 = V_22 -> V_97 . V_34 - V_22 -> V_97 . V_28 ;
if ( F_33 ( V_215 >= 0 ) ) {
V_22 -> V_97 . V_34 = V_215 ;
if ( V_215 > 0 ) {
F_30 ( L_43 ,
V_22 -> V_97 . V_34 , V_215 ) ;
memcpy ( V_22 -> V_97 . V_30 + V_22 -> V_97 . V_28 , V_22 -> V_97 . V_30 , V_215 ) ;
}
}
if ( F_33 ( F_118 ( V_208 ) ) ) {
F_30 ( L_44 , F_118 ( V_208 ) ) ;
V_17 -> V_170 . V_219 ++ ;
F_114 ( V_20 , V_212 ) ;
continue;
}
V_192 = & V_20 -> V_45 ;
V_174 = V_20 -> V_173 ;
V_193 = F_95 ( V_174 , V_212 -> V_204 ) ;
V_196 = V_193 -> V_196 ;
if ( V_207 < V_220 &&
( V_214 = F_101 ( V_20 -> V_17 , V_207 + V_202 ) ) ) {
F_102 ( V_214 , V_202 ) ;
F_119 ( V_20 -> V_2 ,
V_193 -> V_194 , V_192 -> V_97 . V_98 ,
V_195 ) ;
memcpy ( V_214 -> V_74 , V_196 -> V_74 , V_207 ) ;
F_114 ( V_20 , V_212 ) ;
V_196 = V_214 ;
} else {
F_99 ( V_20 -> V_2 ,
V_193 -> V_194 , V_192 -> V_97 . V_98 ,
V_195 ) ;
F_97 ( V_174 , V_212 -> V_204 ) ;
}
V_17 -> V_170 . V_221 += V_207 ;
F_120 ( V_196 , V_207 ) ;
V_196 -> V_222 = F_121 ( V_196 , V_17 ) ;
if ( F_122 ( V_208 ) == 0 )
F_123 ( V_196 ) ;
else
V_196 -> V_223 = V_224 ;
F_107 ( V_20 , V_208 , V_209 , V_196 ) ;
if ( ++ V_216 >= V_217 )
break;
}
V_17 -> V_170 . V_225 += V_216 ;
F_16 ( V_20 , V_22 -> V_97 . V_26 , V_22 -> V_97 . V_34 & V_122 ) ;
F_29 ( V_20 , & V_20 -> V_45 ) ;
F_15 ( V_216 ) ;
}
static void F_116 ( struct V_211 * V_212 , V_37 V_208 , T_1 V_207 ,
T_1 V_209 )
{
F_30 ( L_45 ,
F_117 ( V_208 ) , F_124 ( V_208 ) , F_125 ( V_208 ) ,
F_126 ( V_208 ) , F_118 ( V_208 ) ,
F_127 ( V_208 ) , F_122 ( V_208 ) ,
F_108 ( V_208 ) , V_207 , F_109 ( V_209 ) ,
F_128 ( V_209 ) , F_129 ( V_209 ) , V_212 -> V_204 ,
V_212 -> V_226 ) ;
}
static void F_106 ( struct V_190 * V_198 )
{
F_30 ( L_46
L_47 ,
V_198 -> V_203 , V_198 -> V_204 , V_198 -> V_205 , V_198 -> V_206 , V_198 -> V_207 ) ;
}
static inline int F_130 ( struct V_227 * V_174 )
{
int V_228 = V_174 -> V_35 - V_174 -> V_34 ;
if ( V_228 < 0 )
V_228 = V_174 -> V_75 + 1 + V_228 ;
return V_174 -> V_75 - V_228 ;
}
static inline void F_131 ( struct V_227 * V_174 , struct V_229 * * V_230 )
{
F_89 ( V_174 == NULL || V_230 == NULL ) ;
F_89 ( * V_230 != V_174 -> V_34 &&
* V_230 != V_174 -> V_35 ) ;
F_89 ( * V_230 < V_174 -> V_231 ||
* V_230 >= V_174 -> V_232 ) ;
++ * V_230 ;
if ( F_33 ( * V_230 == V_174 -> V_232 ) )
* V_230 = V_174 -> V_231 ;
}
static inline void F_132 ( struct V_227 * V_174 )
{
F_89 ( V_174 -> V_34 == V_174 -> V_35 ) ;
F_131 ( V_174 , & V_174 -> V_34 ) ;
}
static inline void F_133 ( struct V_227 * V_174 )
{
F_131 ( V_174 , & V_174 -> V_35 ) ;
F_89 ( V_174 -> V_34 == V_174 -> V_35 ) ;
}
static int F_134 ( struct V_227 * V_233 , int V_234 )
{
int V_28 = V_29 * ( 1 << ( V_234 + 1 ) ) ;
V_233 -> V_231 = F_93 ( V_28 ) ;
if ( ! V_233 -> V_231 )
return - V_33 ;
V_233 -> V_75 = V_28 / sizeof( struct V_229 ) - 1 ;
V_233 -> V_232 = V_233 -> V_231 + V_233 -> V_75 + 1 ;
V_233 -> V_34 = V_233 -> V_231 ;
V_233 -> V_35 = V_233 -> V_231 ;
return 0 ;
}
static void F_135 ( struct V_227 * V_233 )
{
F_89 ( V_233 == NULL ) ;
F_91 ( V_233 -> V_231 ) ;
V_233 -> V_231 = NULL ;
}
static inline void
F_136 ( struct V_19 * V_20 , struct V_197 * V_196 ,
struct V_235 * V_236 )
{
struct V_227 * V_174 = & V_20 -> V_227 ;
struct V_237 * V_237 = & V_236 -> V_237 [ 0 ] ;
int V_238 = F_137 ( V_196 ) -> V_238 ;
int V_69 ;
V_174 -> V_35 -> V_207 = F_138 ( V_196 ) ;
V_174 -> V_35 -> V_163 . V_194 = F_103 ( V_20 -> V_2 , V_196 -> V_74 ,
V_174 -> V_35 -> V_207 , V_239 ) ;
V_237 -> V_207 = F_104 ( V_174 -> V_35 -> V_207 ) ;
V_237 -> V_205 = F_104 ( F_105 ( V_174 -> V_35 -> V_163 . V_194 ) ) ;
V_237 -> V_206 = F_104 ( F_17 ( V_174 -> V_35 -> V_163 . V_194 ) ) ;
F_30 ( L_48 , V_237 -> V_207 ) ;
F_30 ( L_49 , V_237 -> V_205 ) ;
F_30 ( L_50 , V_237 -> V_206 ) ;
F_133 ( V_174 ) ;
for ( V_69 = 0 ; V_69 < V_238 ; V_69 ++ ) {
const struct V_240 * V_241 ;
V_241 = & F_137 ( V_196 ) -> V_242 [ V_69 ] ;
V_174 -> V_35 -> V_207 = F_139 ( V_241 ) ;
V_174 -> V_35 -> V_163 . V_194 = F_140 ( & V_20 -> V_2 -> V_50 , V_241 ,
0 , F_139 ( V_241 ) ,
V_243 ) ;
V_237 ++ ;
V_237 -> V_207 = F_104 ( V_174 -> V_35 -> V_207 ) ;
V_237 -> V_205 = F_104 ( F_105 ( V_174 -> V_35 -> V_163 . V_194 ) ) ;
V_237 -> V_206 = F_104 ( F_17 ( V_174 -> V_35 -> V_163 . V_194 ) ) ;
F_133 ( V_174 ) ;
}
V_174 -> V_35 -> V_207 = - V_244 [ V_238 ] . V_245 ;
V_174 -> V_35 -> V_163 . V_196 = V_196 ;
F_133 ( V_174 ) ;
}
static void T_8 F_141 ( void )
{
int V_69 , V_246 ;
for ( V_69 = 0 ; V_69 < V_247 + 1 ; V_69 ++ ) {
V_246 = 7 + ( V_69 * 3 ) ;
if ( V_246 & 1 )
V_246 ++ ;
V_244 [ V_69 ] . V_248 = V_246 >> 1 ;
V_244 [ V_69 ] . V_245 = V_246 << 2 ;
}
}
static int F_67 ( struct V_19 * V_20 )
{
if ( F_12 ( V_20 , & V_20 -> V_249 . V_97 , V_20 -> V_250 ,
V_251 ,
V_252 , V_253 , V_120 ) )
goto V_184;
if ( F_12 ( V_20 , & V_20 -> V_254 . V_97 , V_20 -> V_255 ,
V_256 ,
V_257 , V_258 , V_59 ) )
goto V_184;
if ( F_134 ( & V_20 -> V_227 , F_142 ( V_20 -> V_250 , V_20 -> V_255 ) ) )
goto V_184;
V_20 -> V_259 = V_260 ;
#ifdef F_143
V_20 -> V_261 = V_20 -> V_259 - 1024 ;
#endif
return 0 ;
V_184:
F_25 ( V_20 -> V_17 , L_51 ) ;
return - V_33 ;
}
static inline int F_144 ( struct V_19 * V_20 )
{
struct V_262 * V_22 = & V_20 -> V_249 ;
int V_263 ;
V_22 -> V_97 . V_34 = F_21 ( V_20 , V_22 -> V_97 . V_26 ) & V_122 ;
V_263 = V_22 -> V_97 . V_34 - V_22 -> V_97 . V_35 ;
if ( V_263 <= 0 )
V_263 = V_22 -> V_97 . V_28 + V_263 ;
return V_263 ;
}
static T_9 F_145 ( struct V_197 * V_196 ,
struct V_16 * V_17 )
{
struct V_19 * V_20 = F_32 ( V_17 ) ;
struct V_262 * V_22 = & V_20 -> V_249 ;
int V_264 = 7 ;
int V_265 = 0 ;
int V_266 = 0 ;
int V_267 = 0 ;
int V_268 = 0 ;
int V_238 = F_137 ( V_196 ) -> V_238 ;
struct V_235 * V_236 ;
int V_207 ;
unsigned long V_150 ;
V_39 ;
F_146 ( V_150 ) ;
if ( ! F_147 ( & V_20 -> V_269 ) ) {
F_148 ( V_150 ) ;
F_30 ( L_52 ,
V_270 , V_17 -> V_79 ) ;
return V_271 ;
}
F_89 ( V_22 -> V_97 . V_35 >= V_22 -> V_97 . V_28 ) ;
V_236 = (struct V_235 * ) ( V_22 -> V_97 . V_30 + V_22 -> V_97 . V_35 ) ;
if ( F_33 ( V_196 -> V_223 != V_272 ) )
V_264 = 0 ;
if ( F_137 ( V_196 ) -> V_273 ) {
V_268 = F_137 ( V_196 ) -> V_273 ;
V_265 = 1 ;
F_30 ( L_53 , V_196 , V_196 -> V_207 ,
V_268 ) ;
}
if ( F_149 ( V_196 ) ) {
V_266 = F_150 ( V_196 ) & F_151 ( 12 ) ;
V_267 = 1 ;
}
V_236 -> V_274 = F_115 ( V_196 -> V_207 ) ;
V_236 -> V_275 = F_115 ( V_268 ) ;
V_236 -> V_276 =
F_104 ( F_152
( V_244 [ V_238 ] . V_248 , V_264 , V_267 ,
V_265 , V_266 ) ) ;
F_30 ( L_54 ) ;
F_30 ( L_55 , V_236 -> V_276 ) ;
F_30 ( L_56 , V_236 -> V_275 , V_236 -> V_274 ) ;
F_136 ( V_20 , V_196 , V_236 ) ;
V_22 -> V_97 . V_35 += V_244 [ V_238 ] . V_245 ;
V_207 = V_22 -> V_97 . V_35 - V_22 -> V_97 . V_28 ;
if ( F_33 ( V_207 >= 0 ) ) {
V_22 -> V_97 . V_35 = V_207 ;
if ( V_207 > 0 ) {
F_89 ( V_207 > V_22 -> V_97 . V_28 ) ;
memcpy ( V_22 -> V_97 . V_30 , V_22 -> V_97 . V_30 + V_22 -> V_97 . V_28 , V_207 ) ;
}
}
F_89 ( V_22 -> V_97 . V_35 >= V_22 -> V_97 . V_28 ) ;
V_20 -> V_259 -= V_244 [ V_238 ] . V_245 ;
F_89 ( V_20 -> V_259 <= 0 || V_20 -> V_259 > V_260 ) ;
#ifdef F_143
if ( V_20 -> V_259 > V_20 -> V_261 ) {
F_16 ( V_20 , V_22 -> V_97 . V_27 , V_22 -> V_97 . V_35 & V_122 ) ;
} else {
if ( V_20 -> V_277 ++ > V_278 ) {
V_20 -> V_277 = 0 ;
F_16 ( V_20 , V_22 -> V_97 . V_27 ,
V_22 -> V_97 . V_35 & V_122 ) ;
}
}
#else
F_16 ( V_20 , V_22 -> V_97 . V_27 , V_22 -> V_97 . V_35 & V_122 ) ;
#endif
#ifdef F_153
V_17 -> V_279 = V_131 ;
#endif
V_17 -> V_170 . V_280 ++ ;
V_17 -> V_170 . V_281 += V_196 -> V_207 ;
if ( V_20 -> V_259 < V_282 ) {
F_30 ( L_57 ,
V_270 , V_17 -> V_79 , V_20 -> V_259 ) ;
F_23 ( V_17 ) ;
}
F_154 ( & V_20 -> V_269 , V_150 ) ;
return V_283 ;
}
static void F_40 ( struct V_19 * V_20 )
{
struct V_284 * V_22 = & V_20 -> V_254 ;
struct V_227 * V_174 = & V_20 -> V_227 ;
int V_259 = 0 ;
V_39 ;
V_22 -> V_97 . V_35 = F_21 ( V_20 , V_22 -> V_97 . V_27 ) & V_285 ;
F_89 ( V_22 -> V_97 . V_34 >= V_22 -> V_97 . V_28 ) ;
while ( V_22 -> V_97 . V_35 != V_22 -> V_97 . V_34 ) {
V_22 -> V_97 . V_34 += V_286 ;
V_22 -> V_97 . V_34 &= V_22 -> V_97 . V_36 ;
F_89 ( V_174 -> V_34 -> V_207 == 0 ) ;
do {
F_89 ( V_174 -> V_34 -> V_163 . V_194 == 0 ) ;
F_155 ( V_20 -> V_2 , V_174 -> V_34 -> V_163 . V_194 ,
V_174 -> V_34 -> V_207 , V_239 ) ;
F_132 ( V_174 ) ;
} while ( V_174 -> V_34 -> V_207 > 0 );
V_259 -= V_174 -> V_34 -> V_207 ;
F_156 ( V_174 -> V_34 -> V_163 . V_196 ) ;
F_132 ( V_174 ) ;
}
F_89 ( ( V_22 -> V_97 . V_35 & V_122 ) >= V_22 -> V_97 . V_28 ) ;
F_16 ( V_20 , V_22 -> V_97 . V_26 , V_22 -> V_97 . V_34 & V_122 ) ;
F_157 ( & V_20 -> V_269 ) ;
V_20 -> V_259 += V_259 ;
F_89 ( V_20 -> V_259 <= 0 || V_20 -> V_259 > V_260 ) ;
#ifdef F_143
if ( V_20 -> V_277 ) {
V_20 -> V_277 = 0 ;
F_16 ( V_20 , V_20 -> V_249 . V_97 . V_27 ,
V_20 -> V_249 . V_97 . V_35 & V_122 ) ;
}
#endif
if ( F_33 ( F_158 ( V_20 -> V_17 ) &&
F_22 ( V_20 -> V_17 ) &&
( V_20 -> V_259 >= V_282 ) ) ) {
F_30 ( L_58 ,
V_270 , V_20 -> V_17 -> V_79 , V_20 -> V_259 ) ;
F_26 ( V_20 -> V_17 ) ;
}
F_159 ( & V_20 -> V_269 ) ;
}
static void F_160 ( struct V_19 * V_20 )
{
struct V_227 * V_174 = & V_20 -> V_227 ;
V_39 ;
while ( V_174 -> V_34 != V_174 -> V_35 ) {
if ( F_35 ( V_174 -> V_34 -> V_207 ) )
F_155 ( V_20 -> V_2 , V_174 -> V_34 -> V_163 . V_194 ,
V_174 -> V_34 -> V_207 , V_239 ) ;
else
F_100 ( V_174 -> V_34 -> V_163 . V_196 ) ;
F_132 ( V_174 ) ;
}
F_15 () ;
}
static void F_64 ( struct V_19 * V_20 )
{
V_39 ;
F_160 ( V_20 ) ;
F_18 ( V_20 , & V_20 -> V_249 . V_97 ) ;
F_18 ( V_20 , & V_20 -> V_254 . V_97 ) ;
F_135 ( & V_20 -> V_227 ) ;
}
static void F_161 ( struct V_19 * V_20 , void * V_74 , int V_75 )
{
struct V_262 * V_22 = & V_20 -> V_249 ;
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
int V_287 = 0 ;
V_39 ;
while ( V_75 > 0 ) {
int V_288 = F_144 ( V_20 ) - 8 ;
if ( V_288 <= 0 ) {
if ( V_287 ++ > 300 ) {
F_30 ( L_59 ) ;
break;
}
F_57 ( 50 ) ;
continue;
}
V_288 = F_162 ( V_288 , V_75 ) ;
F_30 ( L_60 , V_288 ,
V_74 , V_75 ) ;
F_161 ( V_20 , V_74 , V_288 ) ;
V_75 -= V_288 ;
V_74 += V_288 ;
}
F_15 () ;
}
static int
F_163 ( struct V_1 * V_2 , const struct V_289 * V_290 )
{
struct V_16 * V_17 ;
struct V_19 * V_20 ;
int V_124 , V_291 , V_114 ;
unsigned long V_292 ;
V_37 V_293 ;
struct V_3 * V_4 ;
V_39 ;
V_4 = F_93 ( sizeof( * V_4 ) ) ;
if ( ! V_4 )
F_15 ( - V_33 ) ;
V_124 = F_164 ( V_2 ) ;
if ( V_124 )
goto V_294;
if ( ! ( V_124 = F_165 ( V_2 , F_166 ( 64 ) ) ) &&
! ( V_124 = F_167 ( V_2 , F_166 ( 64 ) ) ) ) {
V_291 = 1 ;
} else {
if ( ( V_124 = F_165 ( V_2 , F_166 ( 32 ) ) ) ||
( V_124 = F_167 ( V_2 , F_166 ( 32 ) ) ) ) {
F_14 ( L_61 ) ;
goto V_295;
}
V_291 = 0 ;
}
V_124 = F_168 ( V_2 , V_270 ) ;
if ( V_124 )
goto V_295;
F_169 ( V_2 ) ;
V_292 = F_170 ( V_2 , 0 ) ;
if ( ! V_292 ) {
V_124 = - V_76 ;
F_14 ( L_62 ) ;
goto V_296;
}
V_293 = F_171 ( V_2 , 0 ) ;
if ( V_293 < V_126 ) {
V_124 = - V_76 ;
F_14 ( L_63 , V_293 ) ;
goto V_296;
}
V_4 -> V_11 = F_172 ( V_292 , V_293 ) ;
if ( ! V_4 -> V_11 ) {
V_124 = - V_76 ;
F_14 ( L_64 ) ;
goto V_296;
}
if ( V_2 -> V_49 < 2 ) {
V_124 = - V_76 ;
F_14 ( L_65 , V_2 -> V_49 ) ;
goto V_297;
}
F_173 ( V_2 , V_4 ) ;
if ( V_2 -> V_123 == 0x3014 )
V_4 -> V_10 = 2 ;
else
V_4 -> V_10 = 1 ;
F_1 ( V_2 ) ;
F_55 ( V_4 -> V_11 ) ;
V_4 -> V_298 = V_299 ;
#ifdef F_174
if ( ( F_5 ( V_4 -> V_11 + V_13 ) & 0xFFF ) >= 378 ) {
V_124 = F_175 ( V_2 ) ;
if ( V_124 )
F_14 ( L_66 , V_124 ) ;
else
V_4 -> V_298 = V_300 ;
} else
F_30 ( L_67 ) ;
#endif
for ( V_114 = 0 ; V_114 < V_4 -> V_10 ; V_114 ++ ) {
V_17 = F_176 ( sizeof( struct V_19 ) ) ;
if ( ! V_17 ) {
V_124 = - V_33 ;
goto V_297;
}
V_17 -> V_301 = & V_302 ;
V_17 -> V_303 = V_304 ;
F_177 ( V_17 ) ;
V_17 -> V_18 = V_114 ;
V_17 -> V_305 = V_306 | V_307 | V_308
| V_309 | V_310 |
V_311 | V_312
;
V_17 -> V_313 = V_306 | V_307 |
V_308 | V_309 ;
if ( V_291 )
V_17 -> V_305 |= V_314 ;
V_20 = V_4 -> V_20 [ V_114 ] = F_32 ( V_17 ) ;
V_20 -> V_315 = V_4 -> V_11 + V_114 * 0x8000 ;
V_20 -> V_114 = V_114 ;
V_20 -> V_2 = V_2 ;
V_20 -> V_17 = V_17 ;
V_20 -> V_4 = V_4 ;
V_20 -> V_316 = V_317 ;
F_178 ( V_17 , & V_20 -> V_57 , F_38 , 64 ) ;
if ( ( F_5 ( V_4 -> V_11 + V_13 ) & 0xFFF ) == 308 ) {
F_30 ( L_68 ) ;
V_20 -> V_318 = 0 ;
} else {
V_20 -> V_318 = 1 ;
}
V_20 -> V_250 = 2 ;
V_20 -> V_255 = 2 ;
V_20 -> V_181 = 2 ;
V_20 -> V_185 = 3 ;
V_20 -> V_100 = F_179 ( 0x20 , 1 , 4 , 12 ) ;
V_20 -> V_103 = F_179 ( 0x20 , 1 , 0 , 12 ) ;
#ifdef F_153
V_17 -> V_305 |= V_319 ;
#endif
F_180 ( & V_20 -> V_269 ) ;
if ( F_86 ( V_20 ) ) {
F_14 ( L_69 ) ;
goto V_297;
}
F_181 ( V_17 , & V_2 -> V_50 ) ;
V_124 = F_182 ( V_17 ) ;
if ( V_124 ) {
F_14 ( L_70 ) ;
goto V_320;
}
F_24 ( V_17 ) ;
F_23 ( V_17 ) ;
F_10 ( V_17 ) ;
}
F_15 ( 0 ) ;
V_320:
F_183 ( V_17 ) ;
V_297:
F_184 ( V_4 -> V_11 ) ;
V_296:
F_185 ( V_2 ) ;
V_295:
F_186 ( V_2 ) ;
V_294:
F_91 ( V_4 ) ;
F_15 ( V_124 ) ;
}
static int F_187 ( struct V_16 * V_321 , struct V_322 * V_323 )
{
V_37 V_100 ;
V_37 V_103 ;
struct V_19 * V_20 = F_32 ( V_321 ) ;
V_100 = V_20 -> V_100 ;
V_103 = V_20 -> V_103 ;
V_323 -> V_324 = ( V_325 | V_326 ) ;
V_323 -> V_327 = ( V_328 | V_329 ) ;
F_188 ( V_323 , V_330 ) ;
V_323 -> V_331 = V_332 ;
V_323 -> V_114 = V_333 ;
V_323 -> V_334 = V_335 ;
V_323 -> V_336 = V_337 ;
V_323 -> V_338 =
( ( F_189 ( V_103 ) * V_339 ) / V_286 ) ;
V_323 -> V_340 =
( ( F_189 ( V_100 ) * V_339 ) / sizeof( struct V_190 ) ) ;
return 0 ;
}
static void
F_190 ( struct V_16 * V_321 , struct V_341 * V_342 )
{
struct V_19 * V_20 = F_32 ( V_321 ) ;
F_191 ( V_342 -> V_343 , V_270 , sizeof( V_342 -> V_343 ) ) ;
F_191 ( V_342 -> V_344 , V_345 , sizeof( V_342 -> V_344 ) ) ;
F_191 ( V_342 -> V_346 , L_71 , sizeof( V_342 -> V_346 ) ) ;
F_191 ( V_342 -> V_347 , F_192 ( V_20 -> V_2 ) ,
sizeof( V_342 -> V_347 ) ) ;
V_342 -> V_348 = ( ( V_20 -> V_318 ) ? F_193 ( V_349 ) : 0 ) ;
V_342 -> V_350 = 0 ;
V_342 -> V_351 = 0 ;
V_342 -> V_352 = 0 ;
}
static int
F_194 ( struct V_16 * V_321 , struct V_353 * V_354 )
{
V_37 V_100 ;
V_37 V_103 ;
struct V_19 * V_20 = F_32 ( V_321 ) ;
V_100 = V_20 -> V_100 ;
V_103 = V_20 -> V_103 ;
V_354 -> V_355 = F_195 ( V_100 ) * V_356 ;
V_354 -> V_357 =
( ( F_189 ( V_100 ) * V_339 ) / sizeof( struct V_190 ) ) ;
V_354 -> V_358 = F_195 ( V_103 ) * V_356 ;
V_354 -> V_359 =
( ( F_189 ( V_103 ) * V_339 ) / V_286 ) ;
return 0 ;
}
static int
F_196 ( struct V_16 * V_321 , struct V_353 * V_354 )
{
V_37 V_100 ;
V_37 V_103 ;
struct V_19 * V_20 = F_32 ( V_321 ) ;
int V_360 ;
int V_361 ;
int V_362 ;
int V_363 ;
V_360 = V_354 -> V_355 / V_356 ;
V_361 = V_354 -> V_358 / V_356 ;
V_362 = V_354 -> V_357 ;
V_363 = V_354 -> V_359 ;
V_362 =
( ( ( V_362 * sizeof( struct V_190 ) ) + V_339 - 1 )
/ V_339 ) ;
V_363 =
( ( ( V_363 * V_286 ) + V_339 - 1 )
/ V_339 ) ;
if ( ( V_360 > 0x7FFF ) || ( V_361 > 0x7FFF ) ||
( V_362 > 0xF ) || ( V_363 > 0xF ) )
return - V_127 ;
V_100 = F_179 ( V_360 , F_197 ( V_20 -> V_100 ) ,
F_198 ( V_20 -> V_100 ) , V_362 ) ;
V_103 = F_179 ( V_361 , F_197 ( V_20 -> V_103 ) , 0 ,
V_363 ) ;
V_20 -> V_100 = V_100 ;
V_20 -> V_103 = V_103 ;
F_16 ( V_20 , V_101 , V_100 ) ;
F_16 ( V_20 , V_104 , V_103 ) ;
return 0 ;
}
static inline int F_199 ( int V_364 )
{
return ( V_29 * ( 1 << V_364 ) ) / sizeof( struct V_190 ) ;
}
static inline int F_200 ( int V_365 )
{
return ( V_29 * ( 1 << V_365 ) ) / V_286 ;
}
static void
F_201 ( struct V_16 * V_321 , struct V_366 * V_367 )
{
struct V_19 * V_20 = F_32 ( V_321 ) ;
V_367 -> V_368 = F_199 ( 3 ) ;
V_367 -> V_369 = F_200 ( 3 ) ;
V_367 -> V_370 = F_199 ( V_20 -> V_185 ) ;
V_367 -> V_371 = F_200 ( V_20 -> V_250 ) ;
}
static int
F_202 ( struct V_16 * V_321 , struct V_366 * V_367 )
{
struct V_19 * V_20 = F_32 ( V_321 ) ;
int V_364 = 0 ;
int V_365 = 0 ;
for (; V_364 < 4 ; V_364 ++ ) {
if ( F_199 ( V_364 ) >= V_367 -> V_370 )
break;
}
if ( V_364 == 4 )
V_364 = 3 ;
for (; V_365 < 4 ; V_365 ++ ) {
if ( F_200 ( V_365 ) >= V_367 -> V_371 )
break;
}
if ( V_365 == 4 )
V_365 = 3 ;
if ( ( V_364 == V_20 -> V_185 ) &&
( V_365 == V_20 -> V_250 ) )
return 0 ;
V_20 -> V_185 = V_364 ;
if ( V_364 > 1 )
V_20 -> V_181 = V_364 - 1 ;
else
V_20 -> V_181 = V_364 ;
V_20 -> V_255 = V_20 -> V_250 = V_365 ;
if ( F_66 ( V_321 ) ) {
F_61 ( V_321 ) ;
F_65 ( V_321 ) ;
}
return 0 ;
}
static void F_203 ( struct V_16 * V_321 , V_37 V_372 , T_6 * V_74 )
{
switch ( V_372 ) {
case V_373 :
memcpy ( V_74 , * V_349 , sizeof( V_349 ) ) ;
break;
}
}
static int F_204 ( struct V_16 * V_321 , int V_372 )
{
struct V_19 * V_20 = F_32 ( V_321 ) ;
switch ( V_372 ) {
case V_373 :
F_89 ( F_193 ( V_349 )
!= sizeof( struct V_169 ) / sizeof( T_7 ) ) ;
return ( V_20 -> V_318 ) ? F_193 ( V_349 ) : 0 ;
}
return - V_127 ;
}
static void F_205 ( struct V_16 * V_321 ,
struct V_374 * V_170 , T_7 * V_74 )
{
struct V_19 * V_20 = F_32 ( V_321 ) ;
if ( V_20 -> V_318 ) {
F_88 ( V_20 ) ;
memcpy ( V_74 , & V_20 -> V_171 , sizeof( V_20 -> V_171 ) ) ;
}
}
static void F_177 ( struct V_16 * V_321 )
{
static const struct V_375 V_376 = {
. V_377 = F_187 ,
. V_378 = F_190 ,
. V_379 = V_380 ,
. V_381 = F_194 ,
. V_382 = F_196 ,
. V_383 = F_201 ,
. V_384 = F_202 ,
. V_385 = F_203 ,
. V_386 = F_204 ,
. V_387 = F_205 ,
} ;
F_206 ( V_321 , & V_376 ) ;
}
static void F_207 ( struct V_1 * V_2 )
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
if ( V_4 -> V_298 == V_300 )
F_209 ( V_2 ) ;
#endif
F_184 ( V_4 -> V_11 ) ;
F_185 ( V_2 ) ;
F_186 ( V_2 ) ;
F_173 ( V_2 , NULL ) ;
F_91 ( V_4 ) ;
F_15 () ;
}
static void T_8 F_210 ( void )
{
F_4 ( L_72 , V_388 , V_345 ) ;
F_4 ( L_73 , V_389 ) ;
}
static int T_8 F_211 ( void )
{
V_39 ;
F_141 () ;
F_210 () ;
F_15 ( F_212 ( & V_390 ) ) ;
}
static void T_10 F_213 ( void )
{
V_39 ;
F_214 ( & V_390 ) ;
F_15 () ;
}

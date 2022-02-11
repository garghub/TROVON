static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( V_6 + V_3 , 0x0100 ) ;
F_4 ( V_7 + V_3 , ( V_8 ) V_5 -> V_9 ) ;
F_4 ( V_10 + V_3 , V_11 ) ;
F_3 ( V_6 + V_3 , 0x9800 ) ;
V_5 -> V_12 = 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
volatile struct V_13 * V_13 = V_5 -> V_13 ;
T_1 V_14 = V_13 -> V_14 ;
V_13 -> V_14 = V_14 & ~ V_15 ;
F_3 ( V_16 , 0x8800 ) ;
F_1 ( V_2 , 0x00 ) ;
F_3 ( V_16 , 0x0400 ) ;
F_3 ( V_16 , 0x8800 ) ;
F_1 ( V_2 , 0x10 ) ;
F_3 ( V_16 , 0x0400 ) ;
V_13 -> V_14 = V_14 ;
V_5 -> V_17 = 0 ;
F_3 ( V_6 + V_18 , 0x9800 ) ;
F_3 ( V_6 + V_19 , 0x9800 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
volatile struct V_13 * V_13 = V_5 -> V_13 ;
T_1 V_14 ;
F_3 ( V_20 , 0x8800 ) ;
V_14 = V_13 -> V_14 ;
V_13 -> V_14 = V_14 & ~ V_21 ;
V_5 -> V_22 = V_5 -> V_23 = 0 ;
V_5 -> V_24 = V_25 ;
F_3 ( V_20 , 0x0400 ) ;
V_13 -> V_14 = V_14 ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_3 ( V_16 , 0x8800 ) ;
F_3 ( V_16 , 0x1000 ) ;
F_3 ( V_6 + V_18 , 0x1100 ) ;
F_3 ( V_6 + V_19 , 0x1100 ) ;
F_3 ( V_20 , 0x8800 ) ;
F_3 ( V_20 , 0x1000 ) ;
F_3 ( V_26 + V_18 , 0x1100 ) ;
F_3 ( V_26 + V_19 , 0x1100 ) ;
}
static int F_8 ( struct V_27 * V_28 )
{
int V_29 ;
struct V_4 * V_5 ;
unsigned char * V_30 ;
struct V_1 * V_2 ;
unsigned char V_31 = 0 ;
int V_32 ;
V_2 = F_9 ( V_33 ) ;
if ( ! V_2 )
return - V_34 ;
V_5 = F_2 ( V_2 ) ;
V_5 -> V_35 = & V_28 -> V_2 ;
F_10 ( V_28 , V_2 ) ;
F_11 ( V_2 , & V_28 -> V_2 ) ;
V_2 -> V_36 = ( V_8 ) V_37 ;
V_5 -> V_13 = V_37 ;
V_2 -> V_38 = V_39 ;
V_5 -> V_40 = V_41 ;
V_5 -> V_42 = V_5 -> V_13 -> V_43 << 8 | V_5 -> V_13 -> V_44 ;
V_30 = V_45 ;
for ( V_29 = 0 ; V_29 < 6 ; ++ V_29 ) {
T_1 V_46 = F_12 ( V_30 [ V_29 << 4 ] ) ;
V_31 ^= V_46 ;
V_2 -> V_47 [ V_29 ] = V_46 ;
}
for (; V_29 < 8 ; ++ V_29 ) {
V_31 ^= F_12 ( V_30 [ V_29 << 4 ] ) ;
}
if ( V_31 != 0xFF ) {
F_13 ( V_2 ) ;
return - V_48 ;
}
V_2 -> V_49 = & V_50 ;
V_2 -> V_51 = V_52 ;
F_14 ( V_53 L_1 ,
V_2 -> V_54 , V_2 -> V_47 ) ;
V_32 = F_15 ( V_2 ) ;
if ( ! V_32 )
return 0 ;
F_13 ( V_2 ) ;
return V_32 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
volatile struct V_13 * V_55 = V_5 -> V_13 ;
int V_56 ;
V_56 = 200 ;
while ( -- V_56 ) {
V_55 -> V_57 = V_58 ;
if ( V_55 -> V_57 & V_58 ) {
F_17 ( 10 ) ;
continue;
}
break;
}
if ( ! V_56 ) {
F_14 ( V_59 L_2 ) ;
return;
}
V_55 -> V_14 = 0 ;
V_55 -> V_60 = 0xFF ;
V_56 = V_55 -> V_61 ;
V_55 -> V_57 = V_62 ;
V_55 -> V_63 = V_64 ;
V_55 -> V_65 = V_66 | V_67 | V_68 | V_69 ;
V_55 -> V_70 = V_71 ;
V_55 -> V_72 = 0 ;
F_18 ( V_2 , V_2 -> V_47 ) ;
if ( V_5 -> V_42 == V_73 )
V_55 -> V_74 = V_75 ;
else {
V_55 -> V_74 = V_76 | V_75 ;
while ( ( V_55 -> V_74 & V_76 ) != 0 )
;
}
for ( V_56 = 0 ; V_56 < 8 ; ++ V_56 )
V_55 -> V_77 = 0 ;
if ( V_5 -> V_42 != V_73 )
V_55 -> V_74 = 0 ;
V_55 -> V_78 = V_79 ;
}
static void F_18 ( struct V_1 * V_2 , void * V_30 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
volatile struct V_13 * V_55 = V_5 -> V_13 ;
unsigned char * V_80 = V_30 ;
int V_56 ;
if ( V_5 -> V_42 == V_73 )
V_55 -> V_74 = V_81 ;
else {
V_55 -> V_74 = V_76 | V_81 ;
while ( ( V_55 -> V_74 & V_76 ) != 0 )
;
}
for ( V_56 = 0 ; V_56 < 6 ; ++ V_56 )
V_55 -> V_82 = V_2 -> V_47 [ V_56 ] = V_80 [ V_56 ] ;
if ( V_5 -> V_42 != V_73 )
V_55 -> V_74 = 0 ;
}
static int F_19 ( struct V_1 * V_2 , void * V_30 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
volatile struct V_13 * V_55 = V_5 -> V_13 ;
unsigned long V_83 ;
T_1 V_14 ;
F_20 ( V_83 ) ;
V_14 = V_55 -> V_14 ;
F_18 ( V_2 , V_30 ) ;
V_55 -> V_14 = V_14 ;
F_21 ( V_83 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
volatile struct V_13 * V_55 = V_5 -> V_13 ;
F_16 ( V_2 ) ;
if ( F_23 ( V_2 -> V_38 , V_84 , 0 , V_2 -> V_54 , V_2 ) ) {
F_14 ( V_59 L_3 , V_2 -> V_54 , V_2 -> V_38 ) ;
return - V_85 ;
}
if ( F_23 ( V_5 -> V_40 , V_86 , 0 , V_2 -> V_54 , V_2 ) ) {
F_14 ( V_59 L_3 , V_2 -> V_54 , V_5 -> V_40 ) ;
F_24 ( V_2 -> V_38 , V_2 ) ;
return - V_85 ;
}
V_5 -> V_87 = F_25 ( V_5 -> V_35 ,
V_25 * V_88 ,
& V_5 -> V_89 , V_90 ) ;
if ( V_5 -> V_87 == NULL )
goto V_91;
V_5 -> V_92 = F_25 ( V_5 -> V_35 ,
V_11 * V_88 ,
& V_5 -> V_9 , V_90 ) ;
if ( V_5 -> V_92 == NULL )
goto V_93;
F_7 ( V_2 ) ;
F_3 ( V_20 , 0x9000 ) ;
F_3 ( V_16 , 0x9000 ) ;
F_3 ( V_20 , 0x0400 ) ;
F_3 ( V_16 , 0x0400 ) ;
F_5 ( V_2 ) ;
F_6 ( V_2 ) ;
V_55 -> V_14 = V_21 | V_15 ;
V_55 -> V_60 = V_94 ;
return 0 ;
V_93:
F_26 ( V_5 -> V_35 , V_25 * V_88 ,
V_5 -> V_87 , V_5 -> V_89 ) ;
V_91:
F_24 ( V_2 -> V_38 , V_2 ) ;
F_24 ( V_5 -> V_40 , V_2 ) ;
return - V_34 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
volatile struct V_13 * V_55 = V_5 -> V_13 ;
V_55 -> V_14 = 0 ;
V_55 -> V_60 = 0xFF ;
F_7 ( V_2 ) ;
return 0 ;
}
static int F_28 ( struct V_95 * V_96 , struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_83 ;
F_20 ( V_83 ) ;
F_29 ( V_2 ) ;
if ( ! V_5 -> V_24 ) {
F_14 ( V_59 L_4 ) ;
F_21 ( V_83 ) ;
return V_97 ;
}
V_5 -> V_24 -- ;
F_21 ( V_83 ) ;
V_2 -> V_98 . V_99 ++ ;
V_2 -> V_98 . V_100 += V_96 -> V_101 ;
F_30 ( V_96 , V_5 -> V_87 , V_96 -> V_101 ) ;
F_4 ( V_102 + V_5 -> V_22 , ( V_8 ) V_5 -> V_89 ) ;
F_4 ( V_103 + V_5 -> V_22 , V_96 -> V_101 ) ;
F_3 ( V_26 + V_5 -> V_22 , 0x9800 ) ;
V_5 -> V_22 ^= 0x10 ;
F_31 ( V_96 ) ;
return V_104 ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
volatile struct V_13 * V_55 = V_5 -> V_13 ;
int V_56 ;
V_8 V_105 ;
T_1 V_14 ;
unsigned long V_83 ;
F_20 ( V_83 ) ;
V_14 = V_55 -> V_14 ;
V_55 -> V_14 &= ~ V_106 ;
if ( V_2 -> V_83 & V_107 ) {
V_55 -> V_14 |= V_106 ;
} else {
unsigned char V_108 [ 8 ] ;
struct V_109 * V_110 ;
if ( V_2 -> V_83 & V_111 ) {
for ( V_56 = 0 ; V_56 < 8 ; V_56 ++ ) {
V_108 [ V_56 ] = 0xFF ;
}
} else {
for ( V_56 = 0 ; V_56 < 8 ; V_56 ++ )
V_108 [ V_56 ] = 0 ;
F_33 (ha, dev) {
V_105 = F_34 ( 6 , V_110 -> V_30 ) ;
V_56 = V_105 >> 26 ;
V_108 [ V_56 >> 3 ] |= 1 << ( V_56 & 7 ) ;
}
}
if ( V_5 -> V_42 == V_73 )
V_55 -> V_74 = V_75 ;
else {
V_55 -> V_74 = V_76 | V_75 ;
while ( ( V_55 -> V_74 & V_76 ) != 0 )
;
}
for ( V_56 = 0 ; V_56 < 8 ; ++ V_56 )
V_55 -> V_77 = V_108 [ V_56 ] ;
if ( V_5 -> V_42 != V_73 )
V_55 -> V_74 = 0 ;
}
V_55 -> V_14 = V_14 ;
F_21 ( V_83 ) ;
}
static void F_35 ( struct V_1 * V_2 , int V_112 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
volatile struct V_13 * V_55 = V_5 -> V_13 ;
static int V_113 , V_114 ;
if ( V_112 & V_115 )
V_2 -> V_98 . V_116 += 256 ;
V_2 -> V_98 . V_116 += V_55 -> V_117 ;
if ( V_112 & V_118 )
V_2 -> V_98 . V_119 += 256 ;
V_2 -> V_98 . V_119 += V_55 -> V_120 ;
if ( V_112 & V_121 )
++ V_2 -> V_98 . V_122 ;
if ( V_112 & V_123 )
if ( V_113 ++ < 4 )
F_14 ( V_124 L_5 ) ;
if ( V_112 & V_125 )
if ( V_114 ++ < 4 )
F_14 ( V_124 L_6 ) ;
}
static T_2 V_84 ( int V_38 , void * V_126 )
{
struct V_1 * V_2 = (struct V_1 * ) V_126 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
volatile struct V_13 * V_55 = V_5 -> V_13 ;
int V_112 , V_127 ;
unsigned long V_83 ;
F_20 ( V_83 ) ;
V_112 = V_55 -> V_61 ;
F_35 ( V_2 , V_112 ) ;
if ( V_112 & V_128 ) {
V_127 = V_55 -> V_129 ;
if ( ( V_127 & V_130 ) == 0 ) {
F_14 ( V_59 L_7 , V_127 ) ;
F_16 ( V_2 ) ;
}
if ( ! V_5 -> V_24 ) {
F_14 ( V_124 L_8 , V_127 ) ;
}
if ( V_127 & ( V_131 | V_132 | V_133 | V_134 ) ) {
++ V_2 -> V_98 . V_135 ;
if ( V_127 & V_133 )
++ V_2 -> V_98 . V_136 ;
else if ( V_127 & ( V_131 | V_132 | V_134 ) ) {
++ V_2 -> V_98 . V_137 ;
if ( V_55 -> V_129 & V_131 ) {
F_14 ( V_59 L_9 , V_2 -> V_54 ) ;
V_2 -> V_98 . V_138 ++ ;
F_6 ( V_2 ) ;
}
}
}
}
if ( V_5 -> V_24 )
F_36 ( V_2 ) ;
F_21 ( V_83 ) ;
return V_139 ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
volatile struct V_13 * V_55 = V_5 -> V_13 ;
unsigned long V_83 ;
F_20 ( V_83 ) ;
V_55 -> V_14 = 0 ;
F_14 ( V_59 L_10 ) ;
F_6 ( V_2 ) ;
F_16 ( V_2 ) ;
F_5 ( V_2 ) ;
V_5 -> V_24 = V_25 ;
F_36 ( V_2 ) ;
V_55 -> V_14 = V_21 | V_15 ;
V_55 -> V_60 = V_94 ;
F_21 ( V_83 ) ;
}
static void F_38 ( struct V_1 * V_2 , struct V_140 * V_141 )
{
struct V_95 * V_96 ;
unsigned int V_142 = V_141 -> V_143 ;
if ( V_142 & ( V_144 | V_145 | V_146 | V_147 ) ) {
V_2 -> V_98 . V_148 ++ ;
if ( V_142 & V_144 ) {
F_14 ( V_124 L_11 , V_2 -> V_54 ) ;
V_2 -> V_98 . V_149 ++ ;
}
if ( V_142 & V_145 )
V_2 -> V_98 . V_150 ++ ;
if ( V_142 & V_146 )
V_2 -> V_98 . V_151 ++ ;
if ( V_142 & V_147 )
V_2 -> V_98 . V_152 ++ ;
} else {
unsigned int V_153 = V_141 -> V_154 + ( ( V_142 & 0x0F ) << 8 ) ;
V_96 = F_39 ( V_2 , V_153 + 2 ) ;
if ( ! V_96 ) {
V_2 -> V_98 . V_155 ++ ;
return;
}
F_40 ( V_96 , 2 ) ;
F_41 ( V_96 , V_141 -> V_156 , V_153 ) ;
V_96 -> V_157 = F_42 ( V_96 , V_2 ) ;
F_43 ( V_96 ) ;
V_2 -> V_98 . V_158 ++ ;
V_2 -> V_98 . V_159 += V_153 ;
}
}
static T_2 V_86 ( int V_38 , void * V_126 )
{
struct V_1 * V_2 = (struct V_1 * ) V_126 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_160 , V_161 ;
T_3 V_162 ;
V_8 V_163 ;
while ( ( V_163 = F_44 ( V_164 ) ) != F_44 ( V_164 ) ) ;
if ( ! ( V_163 & 0x60000000 ) ) return V_165 ;
V_162 = F_45 ( V_16 ) ;
if ( V_162 & 0x2000 ) {
F_5 ( V_2 ) ;
} else if ( V_162 & 0x0100 ) {
F_3 ( V_6 + V_5 -> V_17 , 0x1100 ) ;
V_160 = F_44 ( V_10 + V_5 -> V_17 ) ;
V_161 = V_11 - V_160 ;
while ( V_5 -> V_12 < V_161 ) {
F_38 ( V_2 , (struct V_140 * ) ( V_5 -> V_92
+ ( V_5 -> V_12 * V_88 ) ) ) ;
V_5 -> V_12 ++ ;
}
if ( ! V_160 ) {
F_1 ( V_2 , V_5 -> V_17 ) ;
V_5 -> V_17 ^= 0x10 ;
} else {
F_3 ( V_6 + V_5 -> V_17 , 0x9800 ) ;
}
}
V_162 = F_45 ( V_20 ) ;
if ( V_162 & 0x2000 ) {
F_6 ( V_2 ) ;
} else if ( V_162 & 0x0100 ) {
F_3 ( V_26 + V_5 -> V_23 , 0x0100 ) ;
V_5 -> V_23 ^= 0x10 ;
V_5 -> V_24 ++ ;
}
return V_139 ;
}
static int F_46 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_47 ( V_28 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_48 ( V_2 ) ;
F_24 ( V_2 -> V_38 , V_2 ) ;
F_24 ( V_41 , V_2 ) ;
F_26 ( V_5 -> V_35 , V_11 * V_88 ,
V_5 -> V_92 , V_5 -> V_9 ) ;
F_26 ( V_5 -> V_35 , V_25 * V_88 ,
V_5 -> V_87 , V_5 -> V_89 ) ;
F_13 ( V_2 ) ;
return 0 ;
}
static int T_4 F_49 ( void )
{
if ( ! V_166 )
return - V_48 ;
return F_50 ( & V_167 ) ;
}
static void T_5 F_51 ( void )
{
F_52 ( & V_167 ) ;
}

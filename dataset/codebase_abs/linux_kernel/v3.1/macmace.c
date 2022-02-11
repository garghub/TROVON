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
static int T_2 F_8 ( struct V_27 * V_28 )
{
int V_29 ;
struct V_4 * V_5 ;
unsigned char * V_30 ;
struct V_1 * V_2 ;
unsigned char V_31 = 0 ;
static int V_32 = 0 ;
int V_33 ;
if ( V_32 || V_34 -> V_35 != V_36 )
return - V_37 ;
V_32 = 1 ;
V_2 = F_9 ( V_38 ) ;
if ( ! V_2 )
return - V_39 ;
V_5 = F_2 ( V_2 ) ;
V_5 -> V_40 = & V_28 -> V_2 ;
F_10 ( V_2 , & V_28 -> V_2 ) ;
V_2 -> V_41 = ( V_8 ) V_42 ;
V_5 -> V_13 = V_42 ;
V_2 -> V_43 = V_44 ;
V_5 -> V_45 = V_46 ;
V_5 -> V_47 = V_5 -> V_13 -> V_48 << 8 | V_5 -> V_13 -> V_49 ;
V_30 = ( void * ) V_50 ;
for ( V_29 = 0 ; V_29 < 6 ; ++ V_29 ) {
T_1 V_51 = F_11 ( V_30 [ V_29 << 4 ] ) ;
V_31 ^= V_51 ;
V_2 -> V_52 [ V_29 ] = V_51 ;
}
for (; V_29 < 8 ; ++ V_29 ) {
V_31 ^= F_11 ( V_30 [ V_29 << 4 ] ) ;
}
if ( V_31 != 0xFF ) {
F_12 ( V_2 ) ;
return - V_37 ;
}
V_2 -> V_53 = & V_54 ;
V_2 -> V_55 = V_56 ;
F_13 ( V_57 L_1 ,
V_2 -> V_58 , V_2 -> V_52 ) ;
V_33 = F_14 ( V_2 ) ;
if ( ! V_33 )
return 0 ;
F_12 ( V_2 ) ;
return V_33 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
volatile struct V_13 * V_59 = V_5 -> V_13 ;
int V_60 ;
V_60 = 200 ;
while ( -- V_60 ) {
V_59 -> V_61 = V_62 ;
if ( V_59 -> V_61 & V_62 ) {
F_16 ( 10 ) ;
continue;
}
break;
}
if ( ! V_60 ) {
F_13 ( V_63 L_2 ) ;
return;
}
V_59 -> V_14 = 0 ;
V_59 -> V_64 = 0xFF ;
V_60 = V_59 -> V_65 ;
V_59 -> V_61 = V_66 ;
V_59 -> V_67 = V_68 ;
V_59 -> V_69 = V_70 | V_71 | V_72 | V_73 ;
V_59 -> V_74 = V_75 ;
V_59 -> V_76 = 0 ;
F_17 ( V_2 , V_2 -> V_52 ) ;
if ( V_5 -> V_47 == V_77 )
V_59 -> V_78 = V_79 ;
else {
V_59 -> V_78 = V_80 | V_79 ;
while ( ( V_59 -> V_78 & V_80 ) != 0 )
;
}
for ( V_60 = 0 ; V_60 < 8 ; ++ V_60 )
V_59 -> V_81 = 0 ;
if ( V_5 -> V_47 != V_77 )
V_59 -> V_78 = 0 ;
V_59 -> V_82 = V_83 ;
}
static void F_17 ( struct V_1 * V_2 , void * V_30 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
volatile struct V_13 * V_59 = V_5 -> V_13 ;
unsigned char * V_84 = V_30 ;
int V_60 ;
if ( V_5 -> V_47 == V_77 )
V_59 -> V_78 = V_85 ;
else {
V_59 -> V_78 = V_80 | V_85 ;
while ( ( V_59 -> V_78 & V_80 ) != 0 )
;
}
for ( V_60 = 0 ; V_60 < 6 ; ++ V_60 )
V_59 -> V_86 = V_2 -> V_52 [ V_60 ] = V_84 [ V_60 ] ;
if ( V_5 -> V_47 != V_77 )
V_59 -> V_78 = 0 ;
}
static int F_18 ( struct V_1 * V_2 , void * V_30 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
volatile struct V_13 * V_59 = V_5 -> V_13 ;
unsigned long V_87 ;
T_1 V_14 ;
F_19 ( V_87 ) ;
V_14 = V_59 -> V_14 ;
F_17 ( V_2 , V_30 ) ;
V_59 -> V_14 = V_14 ;
F_20 ( V_87 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
volatile struct V_13 * V_59 = V_5 -> V_13 ;
F_15 ( V_2 ) ;
if ( F_22 ( V_2 -> V_43 , V_88 , 0 , V_2 -> V_58 , V_2 ) ) {
F_13 ( V_63 L_3 , V_2 -> V_58 , V_2 -> V_43 ) ;
return - V_89 ;
}
if ( F_22 ( V_5 -> V_45 , V_90 , 0 , V_2 -> V_58 , V_2 ) ) {
F_13 ( V_63 L_3 , V_2 -> V_58 , V_5 -> V_45 ) ;
F_23 ( V_2 -> V_43 , V_2 ) ;
return - V_89 ;
}
V_5 -> V_91 = F_24 ( V_5 -> V_40 ,
V_25 * V_92 ,
& V_5 -> V_93 , V_94 ) ;
if ( V_5 -> V_91 == NULL ) {
F_13 ( V_63 L_4 , V_2 -> V_58 ) ;
goto V_95;
}
V_5 -> V_96 = F_24 ( V_5 -> V_40 ,
V_11 * V_92 ,
& V_5 -> V_9 , V_94 ) ;
if ( V_5 -> V_96 == NULL ) {
F_13 ( V_63 L_5 , V_2 -> V_58 ) ;
goto V_97;
}
F_7 ( V_2 ) ;
F_3 ( V_20 , 0x9000 ) ;
F_3 ( V_16 , 0x9000 ) ;
F_3 ( V_20 , 0x0400 ) ;
F_3 ( V_16 , 0x0400 ) ;
F_5 ( V_2 ) ;
F_6 ( V_2 ) ;
V_59 -> V_14 = V_21 | V_15 ;
V_59 -> V_64 = V_98 ;
return 0 ;
V_97:
F_25 ( V_5 -> V_40 , V_25 * V_92 ,
V_5 -> V_91 , V_5 -> V_93 ) ;
V_95:
F_23 ( V_2 -> V_43 , V_2 ) ;
F_23 ( V_5 -> V_45 , V_2 ) ;
return - V_39 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
volatile struct V_13 * V_59 = V_5 -> V_13 ;
V_59 -> V_14 = 0 ;
V_59 -> V_64 = 0xFF ;
F_7 ( V_2 ) ;
return 0 ;
}
static int F_27 ( struct V_99 * V_100 , struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_87 ;
F_19 ( V_87 ) ;
F_28 ( V_2 ) ;
if ( ! V_5 -> V_24 ) {
F_13 ( V_63 L_6 ) ;
F_20 ( V_87 ) ;
return V_101 ;
}
V_5 -> V_24 -- ;
F_20 ( V_87 ) ;
V_2 -> V_102 . V_103 ++ ;
V_2 -> V_102 . V_104 += V_100 -> V_105 ;
F_29 ( V_100 , V_5 -> V_91 , V_100 -> V_105 ) ;
F_4 ( V_106 + V_5 -> V_22 , ( V_8 ) V_5 -> V_93 ) ;
F_4 ( V_107 + V_5 -> V_22 , V_100 -> V_105 ) ;
F_3 ( V_26 + V_5 -> V_22 , 0x9800 ) ;
V_5 -> V_22 ^= 0x10 ;
F_30 ( V_100 ) ;
return V_108 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
volatile struct V_13 * V_59 = V_5 -> V_13 ;
int V_60 ;
V_8 V_109 ;
T_1 V_14 ;
unsigned long V_87 ;
F_19 ( V_87 ) ;
V_14 = V_59 -> V_14 ;
V_59 -> V_14 &= ~ V_110 ;
if ( V_2 -> V_87 & V_111 ) {
V_59 -> V_14 |= V_110 ;
} else {
unsigned char V_112 [ 8 ] ;
struct V_113 * V_114 ;
if ( V_2 -> V_87 & V_115 ) {
for ( V_60 = 0 ; V_60 < 8 ; V_60 ++ ) {
V_112 [ V_60 ] = 0xFF ;
}
} else {
for ( V_60 = 0 ; V_60 < 8 ; V_60 ++ )
V_112 [ V_60 ] = 0 ;
F_32 (ha, dev) {
V_109 = F_33 ( 6 , V_114 -> V_30 ) ;
V_60 = V_109 >> 26 ;
V_112 [ V_60 >> 3 ] |= 1 << ( V_60 & 7 ) ;
}
}
if ( V_5 -> V_47 == V_77 )
V_59 -> V_78 = V_79 ;
else {
V_59 -> V_78 = V_80 | V_79 ;
while ( ( V_59 -> V_78 & V_80 ) != 0 )
;
}
for ( V_60 = 0 ; V_60 < 8 ; ++ V_60 )
V_59 -> V_81 = V_112 [ V_60 ] ;
if ( V_5 -> V_47 != V_77 )
V_59 -> V_78 = 0 ;
}
V_59 -> V_14 = V_14 ;
F_20 ( V_87 ) ;
}
static void F_34 ( struct V_1 * V_2 , int V_116 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
volatile struct V_13 * V_59 = V_5 -> V_13 ;
static int V_117 , V_118 ;
if ( V_116 & V_119 )
V_2 -> V_102 . V_120 += 256 ;
V_2 -> V_102 . V_120 += V_59 -> V_121 ;
if ( V_116 & V_122 )
V_2 -> V_102 . V_123 += 256 ;
V_2 -> V_102 . V_123 += V_59 -> V_124 ;
if ( V_116 & V_125 )
++ V_2 -> V_102 . V_126 ;
if ( V_116 & V_127 )
if ( V_117 ++ < 4 )
F_13 ( V_128 L_7 ) ;
if ( V_116 & V_129 )
if ( V_118 ++ < 4 )
F_13 ( V_128 L_8 ) ;
}
static T_3 V_88 ( int V_43 , void * V_130 )
{
struct V_1 * V_2 = (struct V_1 * ) V_130 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
volatile struct V_13 * V_59 = V_5 -> V_13 ;
int V_116 , V_131 ;
unsigned long V_87 ;
F_19 ( V_87 ) ;
V_116 = V_59 -> V_65 ;
F_34 ( V_2 , V_116 ) ;
if ( V_116 & V_132 ) {
V_131 = V_59 -> V_133 ;
if ( ( V_131 & V_134 ) == 0 ) {
F_13 ( V_63 L_9 , V_131 ) ;
F_15 ( V_2 ) ;
}
if ( ! V_5 -> V_24 ) {
F_13 ( V_128 L_10 , V_131 ) ;
}
if ( V_131 & ( V_135 | V_136 | V_137 | V_138 ) ) {
++ V_2 -> V_102 . V_139 ;
if ( V_131 & V_137 )
++ V_2 -> V_102 . V_140 ;
else if ( V_131 & ( V_135 | V_136 | V_138 ) ) {
++ V_2 -> V_102 . V_141 ;
if ( V_59 -> V_133 & V_135 ) {
F_13 ( V_63 L_11 , V_2 -> V_58 ) ;
V_2 -> V_102 . V_142 ++ ;
F_6 ( V_2 ) ;
}
}
}
}
if ( V_5 -> V_24 )
F_35 ( V_2 ) ;
F_20 ( V_87 ) ;
return V_143 ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
volatile struct V_13 * V_59 = V_5 -> V_13 ;
unsigned long V_87 ;
F_19 ( V_87 ) ;
V_59 -> V_14 = 0 ;
F_13 ( V_63 L_12 ) ;
F_6 ( V_2 ) ;
F_15 ( V_2 ) ;
F_5 ( V_2 ) ;
V_5 -> V_24 = V_25 ;
F_35 ( V_2 ) ;
V_59 -> V_14 = V_21 | V_15 ;
V_59 -> V_64 = V_98 ;
F_20 ( V_87 ) ;
}
static void F_37 ( struct V_1 * V_2 , struct V_144 * V_145 )
{
struct V_99 * V_100 ;
unsigned int V_146 = V_145 -> V_147 ;
if ( V_146 & ( V_148 | V_149 | V_150 | V_151 ) ) {
V_2 -> V_102 . V_152 ++ ;
if ( V_146 & V_148 ) {
F_13 ( V_128 L_13 , V_2 -> V_58 ) ;
V_2 -> V_102 . V_153 ++ ;
}
if ( V_146 & V_149 )
V_2 -> V_102 . V_154 ++ ;
if ( V_146 & V_150 )
V_2 -> V_102 . V_155 ++ ;
if ( V_146 & V_151 )
V_2 -> V_102 . V_156 ++ ;
} else {
unsigned int V_157 = V_145 -> V_158 + ( ( V_146 & 0x0F ) << 8 ) ;
V_100 = F_38 ( V_157 + 2 ) ;
if ( ! V_100 ) {
V_2 -> V_102 . V_159 ++ ;
return;
}
F_39 ( V_100 , 2 ) ;
memcpy ( F_40 ( V_100 , V_157 ) , V_145 -> V_160 , V_157 ) ;
V_100 -> V_161 = F_41 ( V_100 , V_2 ) ;
F_42 ( V_100 ) ;
V_2 -> V_102 . V_162 ++ ;
V_2 -> V_102 . V_163 += V_157 ;
}
}
static T_3 V_90 ( int V_43 , void * V_130 )
{
struct V_1 * V_2 = (struct V_1 * ) V_130 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_164 , V_165 ;
T_4 V_166 ;
V_8 V_167 ;
while ( ( V_167 = F_43 ( V_168 ) ) != F_43 ( V_168 ) ) ;
if ( ! ( V_167 & 0x60000000 ) ) return V_169 ;
V_166 = F_44 ( V_16 ) ;
if ( V_166 & 0x2000 ) {
F_5 ( V_2 ) ;
} else if ( V_166 & 0x0100 ) {
F_3 ( V_6 + V_5 -> V_17 , 0x1100 ) ;
V_164 = F_43 ( V_10 + V_5 -> V_17 ) ;
V_165 = V_11 - V_164 ;
while ( V_5 -> V_12 < V_165 ) {
F_37 ( V_2 , (struct V_144 * ) ( V_5 -> V_96
+ ( V_5 -> V_12 * V_92 ) ) ) ;
V_5 -> V_12 ++ ;
}
if ( ! V_164 ) {
F_1 ( V_2 , V_5 -> V_17 ) ;
V_5 -> V_17 ^= 0x10 ;
} else {
F_3 ( V_6 + V_5 -> V_17 , 0x9800 ) ;
}
}
V_166 = F_44 ( V_20 ) ;
if ( V_166 & 0x2000 ) {
F_6 ( V_2 ) ;
} else if ( V_166 & 0x0100 ) {
F_3 ( V_26 + V_5 -> V_23 , 0x0100 ) ;
V_5 -> V_23 ^= 0x10 ;
V_5 -> V_24 ++ ;
}
return V_143 ;
}
static int T_5 F_45 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_46 ( V_28 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_47 ( V_2 ) ;
F_23 ( V_2 -> V_43 , V_2 ) ;
F_23 ( V_46 , V_2 ) ;
F_25 ( V_5 -> V_40 , V_11 * V_92 ,
V_5 -> V_96 , V_5 -> V_9 ) ;
F_25 ( V_5 -> V_40 , V_25 * V_92 ,
V_5 -> V_91 , V_5 -> V_93 ) ;
F_12 ( V_2 ) ;
return 0 ;
}
static int T_6 F_48 ( void )
{
if ( ! V_170 )
return - V_37 ;
return F_49 ( & V_171 ) ;
}
static void T_7 F_50 ( void )
{
F_51 ( & V_171 ) ;
}

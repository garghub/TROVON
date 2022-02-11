void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_2 , V_4 , V_3 , 0 ) ;
F_2 ( V_2 , V_5 , V_3 , 0 ) ;
F_2 ( V_2 , V_6 , V_3 , 0xffff ) ;
F_2 ( V_2 , V_7 , V_3 , 0xffff ) ;
F_2 ( V_2 , V_8 , V_3 , 0 ) ;
F_2 ( V_2 , V_9 , V_3 , 0 ) ;
F_2 ( V_2 , V_10 , V_3 , 0 ) ;
F_2 ( V_2 , V_11 , V_3 , 0 ) ;
F_2 ( V_2 , V_12 , V_3 , 0x10 ) ;
F_2 ( V_2 , V_13 , V_3 , 0 ) ;
F_2 ( V_2 , V_14 , V_3 , 0 ) ;
F_2 ( V_2 , V_15 , V_3 , 0 ) ;
F_2 ( V_2 , V_16 , V_3 , 0x32100000 ) ;
F_2 ( V_2 , V_17 , V_3 , 0 ) ;
F_2 ( V_2 , V_18 , V_3 , 0 ) ;
F_2 ( V_2 , V_19 , V_3 , 0xffff ) ;
F_2 ( V_2 , V_20 , V_3 , 0 ) ;
F_2 ( V_2 , V_21 , V_3 , 0 ) ;
F_2 ( V_2 , V_22 , V_3 , 24 ) ;
F_2 ( V_2 , V_23 , V_3 , 24 ) ;
F_2 ( V_2 , V_24 , V_3 , 0 ) ;
F_2 ( V_2 , V_25 , V_3 , 0 ) ;
F_2 ( V_2 , V_26 , V_3 , 0 ) ;
F_2 ( V_2 , V_27 , V_3 , 0 ) ;
F_2 ( V_2 , V_28 , V_3 , 0 ) ;
F_2 ( V_2 , V_29 , V_3 , 0 ) ;
if ( V_2 -> V_30 ) {
F_2 ( V_2 , 0x4c , V_3 , 0 ) ;
F_2 ( V_2 , 0x4d , V_3 , 0 ) ;
F_2 ( V_2 , 0x4e , V_3 , 0 ) ;
F_2 ( V_2 , 0x4f , V_3 , 0 ) ;
F_2 ( V_2 , V_31 , V_3 , 0x03020100 ) ;
F_2 ( V_2 , V_32 , V_3 , 0x3f3f3f3f ) ;
F_2 ( V_2 , V_33 , V_3 , 0 ) ;
}
}
static int F_3 ( struct V_1 * V_2 , int V_34 , int V_35 )
{
unsigned int V_36 ;
int V_3 ;
T_1 V_37 ;
F_4 ( V_38 | V_39 |
V_40 , V_2 -> V_41 + V_42 ) ;
F_2 ( V_2 , V_43 , 0 , V_44 ) ;
F_2 ( V_2 , V_45 , 0 , 0 ) ;
F_2 ( V_2 , V_46 , 0 , V_44 ) ;
F_2 ( V_2 , V_47 , 0 , 0 ) ;
F_2 ( V_2 , V_48 , 0 , V_44 ) ;
F_2 ( V_2 , V_49 , 0 , 0 ) ;
F_4 ( 0 , V_2 -> V_41 + V_50 ) ;
F_2 ( V_2 , V_51 , 0 , 0 ) ;
F_2 ( V_2 , V_52 , 0 , 0 ) ;
F_2 ( V_2 , V_53 , 0 , 0 ) ;
F_2 ( V_2 , V_54 , 0 , 0 ) ;
if ( V_2 -> V_30 ) {
F_2 ( V_2 , V_55 , 0 , V_56 ) ;
F_2 ( V_2 , V_57 , 0 , V_58 |
V_59 ) ;
}
for ( V_3 = 0 ; V_3 < V_60 ; V_3 ++ )
F_1 ( V_2 , V_3 ) ;
F_2 ( V_2 , V_61 , 0 , V_2 -> V_62 [ 0 ] ) ;
F_2 ( V_2 , V_63 , 0 , V_2 -> V_62 [ 1 ] ) ;
F_2 ( V_2 , V_64 , 0 , V_2 -> V_62 [ 2 ] ) ;
if ( V_2 -> V_65 -> V_66 ) {
V_37 = F_5 ( V_2 , V_67 , 0 ) ;
V_37 &= 0xfffff1ff ;
V_37 |= ( 0x2 << 9 ) ;
F_2 ( V_2 , V_67 , 0 , V_37 ) ;
F_6 ( V_2 , V_68 , 0 , 0x14 ) ;
F_6 ( V_2 , V_69 , 0 , 0xFFFFFFFF ) ;
F_4 ( 0x0201 , V_2 -> V_41 + V_70 ) ;
F_6 ( V_2 , V_71 , 0 , 0x78e4 ) ;
}
if ( V_2 -> V_65 -> V_72 ) {
F_7 ( V_2 -> V_73 -> V_74 , L_1 ) ;
V_37 = F_5 ( V_2 , V_67 , 0 ) ;
V_37 &= 0xfffff1ff ;
V_37 |= ( 0x2 << 9 ) ;
F_2 ( V_2 , V_67 , 0 , V_37 ) ;
F_4 ( 0x600000 , V_2 -> V_41 + 0x20 ) ;
F_4 ( 0x14 , V_2 -> V_41 + 0x24 ) ;
F_4 ( 0x7b0000 , V_2 -> V_41 + 0x20 ) ;
F_4 ( 0xFF000000 , V_2 -> V_41 + 0x24 ) ;
F_4 ( 0x7a0000 , V_2 -> V_41 + 0x20 ) ;
F_4 ( 0xFF000000 , V_2 -> V_41 + 0x24 ) ;
V_37 = F_8 ( V_2 -> V_41 + V_75 ) & ~ 0x8 ;
F_4 ( V_37 , V_2 -> V_41 + V_75 ) ;
}
if ( V_2 -> V_65 -> V_76 ) {
int V_77 , V_78 ;
V_77 = F_9 ( V_79 ) ;
for ( V_78 = 0 ; V_78 < V_77 ; V_78 ++ )
F_10 ( V_2 , V_79 [ V_78 ] ) ;
F_6 ( V_2 , 0x60 , 0 , 0x10 ) ;
F_4 ( 0x76 , V_2 -> V_41 + V_75 ) ;
}
if ( V_2 -> V_65 -> V_80 ) {
int V_77 , V_78 ;
F_6 ( V_2 , V_81 , 0 , 0x2020205f ) ;
V_37 = F_8 ( V_2 -> V_41 + V_75 ) ;
F_4 ( V_37 | 0x4 , V_2 -> V_41 + V_75 ) ;
V_37 = F_8 ( V_2 -> V_41 + V_75 ) ;
V_77 = F_9 ( V_82 ) ;
for ( V_78 = 0 ; V_78 < V_77 ; V_78 ++ )
F_11 ( V_2 , V_82 [ V_78 ] [ 0 ] , V_82 [ V_78 ] [ 1 ] ) ;
for ( V_78 = 0 ; V_78 < 4 ; V_78 ++ ) {
V_2 -> V_83 [ V_78 ] [ 0 ] = 0xcf ;
V_2 -> V_83 [ V_78 ] [ 1 ] = 0xcf ;
}
}
F_2 ( V_2 , V_84 , 0 , V_2 -> V_85 . V_86 ) ;
F_2 ( V_2 , V_87 , 0 , 0 ) ;
F_2 ( V_2 , V_88 , 0 , 4 ) ;
V_36 = ( V_2 -> V_36 . V_86 << 1 ) | V_89 ;
for ( V_3 = 0 ; V_3 < V_60 ; V_3 ++ ) {
F_2 ( V_2 , V_90 , V_3 , V_36 ) ;
F_2 ( V_2 , V_91 , V_3 , V_36 ) ;
}
if ( V_2 -> V_65 -> V_92 ) {
F_4 ( V_93 |
V_94 |
V_95 , V_2 -> V_41 + V_42 ) ;
} else if ( V_2 -> V_30 ) {
if ( V_2 -> V_96 == 4 )
F_4 ( V_95 |
V_97 |
V_98 |
V_99 | V_100 , V_2 -> V_41 + V_42 ) ;
else
F_4 ( V_99 | V_100 , V_2 -> V_41 + V_42 ) ;
} else if ( V_2 -> V_101 == 0x20 ||
V_2 -> V_101 == 0xc400 ||
( V_2 -> V_101 == 0x21 && V_2 -> V_96 < 6 ) )
F_4 ( V_39 | V_99 , V_2 -> V_41 + V_42 ) ;
else
F_4 ( V_39 | V_99 | V_100 , V_2 -> V_41 + V_42 ) ;
if ( V_34 ) {
if ( V_2 -> V_65 -> V_92 ) {
;
} else if ( V_2 -> V_65 -> V_80 ) {
;
} else if ( V_2 -> V_30 ) {
unsigned int V_102 = F_8 ( V_2 -> V_41 + V_75 ) ;
F_4 ( V_102 | V_103 , V_2 -> V_41 + V_75 ) ;
F_12 ( 500 ) ;
F_4 ( V_102 | V_104 | V_103 , V_2 -> V_41 + V_75 ) ;
F_12 ( 100 ) ;
F_4 ( V_102 , V_2 -> V_41 + V_75 ) ;
} else {
unsigned int V_102 = F_8 ( V_2 -> V_41 + V_42 ) ;
F_4 ( V_102 | V_105 , V_2 -> V_41 + V_42 ) ;
F_12 ( 500 ) ;
F_4 ( V_102 | V_106 | V_105 , V_2 -> V_41 + V_42 ) ;
F_12 ( 100 ) ;
F_4 ( V_102 , V_2 -> V_41 + V_42 ) ;
}
}
if ( V_2 -> V_65 -> V_92 ) {
;
} else if ( V_2 -> V_65 -> V_80 ) {
;
} else if ( V_2 -> V_30 ) {
unsigned int V_102 = F_8 ( V_2 -> V_41 + V_75 ) ;
F_4 ( V_102 | V_107 , V_2 -> V_41 + V_75 ) ;
}
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_4 ( F_8 ( V_2 -> V_41 + V_42 ) | V_95 , V_2 -> V_41 + V_42 ) ;
if ( V_2 -> V_65 -> V_92 ) {
;
} else if ( V_2 -> V_65 -> V_80 ) {
;
} else if ( V_2 -> V_30 ) {
F_4 ( F_8 ( V_2 -> V_41 + V_75 ) & ~ 0x44 , V_2 -> V_41 + V_75 ) ;
if ( V_2 -> V_65 -> V_66 ) {
F_4 ( F_8 ( V_2 -> V_41 + V_75 ) | 0x0040 , V_2 -> V_41 + V_75 ) ;
} else if ( V_2 -> V_65 -> V_72 ) {
F_4 ( F_8 ( V_2 -> V_41 + V_75 ) | 0x0060 , V_2 -> V_41 + V_75 ) ;
} else {
F_4 ( F_8 ( V_2 -> V_41 + V_75 ) | 0x0080 , V_2 -> V_41 + V_75 ) ;
}
}
#if 0
{
unsigned int tmp;
emu->tos_link = 0;
tmp = inl(emu->port + HCFG);
if (tmp & (HCFG_GPINPUT0 | HCFG_GPINPUT1)) {
outl(tmp|0x800, emu->port + HCFG);
udelay(50);
if (tmp != (inl(emu->port + HCFG) & ~0x800)) {
emu->tos_link = 1;
outl(tmp, emu->port + HCFG);
}
}
}
#endif
F_14 ( V_2 , V_108 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
int V_3 ;
F_4 ( 0 , V_2 -> V_41 + V_50 ) ;
for ( V_3 = 0 ; V_3 < V_60 ; V_3 ++ )
F_2 ( V_2 , V_4 , V_3 , 0 ) ;
for ( V_3 = 0 ; V_3 < V_60 ; V_3 ++ ) {
F_2 ( V_2 , V_6 , V_3 , 0 ) ;
F_2 ( V_2 , V_7 , V_3 , 0 ) ;
F_2 ( V_2 , V_8 , V_3 , 0 ) ;
F_2 ( V_2 , V_9 , V_3 , 0 ) ;
}
F_2 ( V_2 , V_43 , 0 , 0 ) ;
F_2 ( V_2 , V_45 , 0 , 0 ) ;
F_2 ( V_2 , V_46 , 0 , 0 ) ;
F_2 ( V_2 , V_47 , 0 , 0 ) ;
F_2 ( V_2 , V_109 , 0 , 0 ) ;
F_2 ( V_2 , V_48 , 0 , V_44 ) ;
F_2 ( V_2 , V_49 , 0 , 0 ) ;
F_2 ( V_2 , V_88 , 0 , V_110 ) ;
F_2 ( V_2 , V_87 , 0 , 0 ) ;
if ( V_2 -> V_30 )
F_2 ( V_2 , V_111 , 0 , V_112 ) ;
else
F_2 ( V_2 , V_113 , 0 , V_114 ) ;
F_2 ( V_2 , V_51 , 0 , 0 ) ;
F_2 ( V_2 , V_52 , 0 , 0 ) ;
F_2 ( V_2 , V_53 , 0 , 0 ) ;
F_2 ( V_2 , V_54 , 0 , 0 ) ;
F_4 ( V_38 | V_39 | V_40 , V_2 -> V_41 + V_42 ) ;
F_2 ( V_2 , V_84 , 0 , 0 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 , unsigned int V_115 )
{
unsigned short V_116 ;
unsigned int V_117 ;
unsigned long V_118 ;
unsigned int V_119 ;
V_118 = V_2 -> V_41 + V_42 ;
V_119 = F_8 ( V_118 ) & ~ ( V_120 | V_121 | V_122 ) ;
F_4 ( V_119 , V_118 ) ;
for ( V_116 = 0 ; V_116 < V_123 ; V_116 ++ ) {
V_117 = ( ( V_115 & 0x1 ) ? V_122 : 0 ) ;
V_115 >>= 1 ;
F_4 ( V_119 | V_117 , V_118 ) ;
F_4 ( V_119 | V_117 | V_121 , V_118 ) ;
F_4 ( V_119 | V_117 , V_118 ) ;
}
F_4 ( V_119 | V_120 , V_118 ) ;
F_4 ( V_119 , V_118 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
unsigned short V_124 )
{
unsigned int V_125 ;
F_16 ( V_2 , V_2 -> V_126 & ~ V_127 ) ;
F_16 ( V_2 , V_2 -> V_126 & ~ V_127 ) ;
for ( V_125 = ( 1 << 15 ) ; V_125 ; V_125 >>= 1 ) {
unsigned int V_115 ;
V_115 = V_2 -> V_126 & ~ ( V_127 | V_128 ) ;
if ( V_124 & V_125 )
V_115 |= V_128 ;
F_16 ( V_2 , V_115 ) ;
F_16 ( V_2 , V_115 | V_129 ) ;
F_16 ( V_2 , V_115 ) ;
}
F_16 ( V_2 , V_2 -> V_126 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
unsigned int V_119 ;
V_2 -> V_126 = V_130 |
F_19 ( V_131 ) |
F_20 ( V_132 ) ;
V_119 = F_8 ( V_2 -> V_41 + V_42 ) ;
F_4 ( V_119 | V_95 | V_133 , V_2 -> V_41 + V_42 ) ;
F_8 ( V_2 -> V_41 + V_42 ) ;
F_16 ( V_2 , V_134 | V_135 | V_127 ) ;
F_16 ( V_2 , V_136 | V_135 | V_127 ) ;
F_21 ( V_2 , 48000 ) ;
F_16 ( V_2 , V_134 | V_135 | V_127 ) ;
F_16 ( V_2 , V_2 -> V_126 ) ;
F_17 ( V_2 , V_137 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
unsigned long V_138 ;
unsigned int V_115 ;
V_138 = V_2 -> V_41 + 0x38 ;
V_115 = F_8 ( V_138 ) ;
F_4 ( 0x00d00000 , V_138 ) ;
V_115 = F_8 ( V_138 ) ;
F_4 ( 0x00d00001 , V_138 ) ;
V_115 = F_8 ( V_138 ) ;
F_4 ( 0x00d0005f , V_138 ) ;
V_115 = F_8 ( V_138 ) ;
F_4 ( 0x00d0007f , V_138 ) ;
V_115 = F_8 ( V_138 ) ;
F_4 ( 0x0090007f , V_138 ) ;
V_115 = F_8 ( V_138 ) ;
F_6 ( V_2 , V_139 , 0 , 0xfefefefe ) ;
F_23 ( 200 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
const struct V_140 * V_141 )
{
int V_78 , V_142 ;
int V_102 ;
int V_115 ;
unsigned int V_143 ;
unsigned long V_144 ;
if ( ! V_141 )
return - V_145 ;
F_25 ( & V_2 -> V_146 , V_144 ) ;
F_4 ( 0x00 , V_2 -> V_41 + V_75 ) ;
V_143 = F_8 ( V_2 -> V_41 + V_75 ) ;
F_12 ( 100 ) ;
F_4 ( 0x80 , V_2 -> V_41 + V_75 ) ;
V_143 = F_8 ( V_2 -> V_41 + V_75 ) ;
F_12 ( 100 ) ;
for ( V_78 = 0 ; V_78 < V_141 -> V_77 ; V_78 ++ ) {
V_115 = V_141 -> V_117 [ V_78 ] ;
for ( V_142 = 0 ; V_142 < 8 ; V_142 ++ ) {
V_102 = 0x80 ;
if ( V_115 & 0x1 )
V_102 = V_102 | 0x20 ;
V_115 = V_115 >> 1 ;
F_4 ( V_102 , V_2 -> V_41 + V_75 ) ;
V_143 = F_8 ( V_2 -> V_41 + V_75 ) ;
F_4 ( V_102 | 0x40 , V_2 -> V_41 + V_75 ) ;
V_143 = F_8 ( V_2 -> V_41 + V_75 ) ;
}
}
F_4 ( 0x10 , V_2 -> V_41 + V_75 ) ;
V_143 = F_8 ( V_2 -> V_41 + V_75 ) ;
F_26 ( & V_2 -> V_146 , V_144 ) ;
return 0 ;
}
static int F_27 ( void * V_117 )
{
struct V_1 * V_2 = V_117 ;
T_1 V_37 , V_147 , V_102 ;
int V_148 ;
for (; ; ) {
F_28 ( 1000 ) ;
if ( F_29 () )
break;
#ifdef F_30
if ( V_2 -> V_149 )
continue;
#endif
F_31 ( V_2 , V_150 , & V_37 ) ;
F_31 ( V_2 , V_151 , & V_102 ) ;
if ( V_102 & V_152 ) {
F_7 ( V_2 -> V_73 -> V_74 ,
L_2 ) ;
F_32 ( V_2 , V_153 , V_154 ) ;
if ( ! V_2 -> V_155 ) {
const char * V_156 = NULL ;
switch ( V_2 -> V_65 -> V_92 ) {
case V_157 :
V_156 = V_158 ;
break;
case V_159 :
V_156 = V_160 ;
break;
case V_161 :
V_156 = V_160 ;
break;
}
if ( V_156 ) {
V_148 = F_33 ( & V_2 -> V_155 ,
V_156 ,
& V_2 -> V_162 -> V_74 ) ;
if ( V_148 )
continue;
}
}
if ( V_2 -> V_155 ) {
V_148 = F_24 ( V_2 , V_2 -> V_155 ) ;
if ( V_148 )
continue;
}
F_32 ( V_2 , V_153 , 0 ) ;
F_31 ( V_2 , V_150 , & V_102 ) ;
F_7 ( V_2 -> V_73 -> V_74 ,
L_3 ,
V_102 ) ;
F_31 ( V_2 , V_163 , & V_102 ) ;
F_7 ( V_2 -> V_73 -> V_74 ,
L_4 , V_102 ) ;
if ( ( V_102 & 0x1f ) != 0x15 ) {
F_7 ( V_2 -> V_73 -> V_74 ,
L_5 ,
V_102 ) ;
continue;
}
F_7 ( V_2 -> V_73 -> V_74 ,
L_6 ) ;
F_31 ( V_2 , V_164 , & V_37 ) ;
F_31 ( V_2 , V_165 , & V_147 ) ;
F_7 ( V_2 -> V_73 -> V_74 , L_7 ,
V_37 , V_147 ) ;
F_23 ( 10 ) ;
F_32 ( V_2 , V_166 , V_167 ) ;
}
}
F_7 ( V_2 -> V_73 -> V_74 , L_8 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
unsigned int V_142 ;
T_1 V_37 , V_147 , V_102 ;
int V_148 ;
F_7 ( V_2 -> V_73 -> V_74 , L_9 ) ;
F_4 ( 0x0005a00c , V_2 -> V_41 + V_42 ) ;
F_4 ( 0x0005a004 , V_2 -> V_41 + V_42 ) ;
F_4 ( 0x0005a000 , V_2 -> V_41 + V_42 ) ;
F_4 ( 0x0005a000 , V_2 -> V_41 + V_42 ) ;
F_32 ( V_2 , V_168 , 0 ) ;
F_31 ( V_2 , V_163 , & V_102 ) ;
F_35 ( V_2 -> V_73 -> V_74 , L_10 , V_102 ) ;
if ( ( V_102 & 0x3f ) == 0x15 ) {
F_32 ( V_2 , V_153 , 0x02 ) ;
}
F_31 ( V_2 , V_163 , & V_102 ) ;
F_35 ( V_2 -> V_73 -> V_74 , L_11 , V_102 ) ;
if ( ( V_102 & 0x3f ) == 0x15 ) {
F_7 ( V_2 -> V_73 -> V_74 ,
L_12 ) ;
return - V_169 ;
}
F_7 ( V_2 -> V_73 -> V_74 , L_13 , V_102 ) ;
if ( ! V_2 -> V_140 ) {
const char * V_156 ;
switch ( V_2 -> V_65 -> V_92 ) {
case V_157 :
V_156 = V_170 ;
break;
case V_159 :
V_156 = V_171 ;
break;
case V_161 :
V_156 = V_172 ;
break;
case V_173 :
V_156 = V_174 ;
break;
default:
return - V_169 ;
}
V_148 = F_33 ( & V_2 -> V_140 , V_156 , & V_2 -> V_162 -> V_74 ) ;
if ( V_148 != 0 ) {
F_7 ( V_2 -> V_73 -> V_74 ,
L_14 ,
V_156 , V_148 ) ;
return V_148 ;
}
F_7 ( V_2 -> V_73 -> V_74 ,
L_15 ,
V_156 , V_2 -> V_140 -> V_77 ) ;
}
V_148 = F_24 ( V_2 , V_2 -> V_140 ) ;
if ( V_148 != 0 ) {
F_7 ( V_2 -> V_73 -> V_74 , L_16 ) ;
return V_148 ;
}
F_31 ( V_2 , V_163 , & V_102 ) ;
if ( ( V_102 & 0x3f ) != 0x15 ) {
F_7 ( V_2 -> V_73 -> V_74 ,
L_17 ,
V_102 ) ;
return - V_169 ;
}
F_7 ( V_2 -> V_73 -> V_74 , L_18 ) ;
F_31 ( V_2 , V_175 , & V_37 ) ;
F_31 ( V_2 , V_176 , & V_147 ) ;
F_7 ( V_2 -> V_73 -> V_74 , L_19 , V_37 , V_147 ) ;
F_32 ( V_2 , V_168 , V_177 ) ;
F_31 ( V_2 , V_151 , & V_102 ) ;
F_7 ( V_2 -> V_73 -> V_74 , L_20 , V_102 ) ;
F_31 ( V_2 , V_151 , & V_102 ) ;
F_7 ( V_2 -> V_73 -> V_74 , L_20 , V_102 ) ;
F_31 ( V_2 , V_178 , & V_37 ) ;
V_2 -> V_179 . V_180 = 1 ;
V_2 -> V_179 . V_181 = 1 ;
V_37 = 0 ;
V_37 = ( V_2 -> V_179 . V_180 ? V_182 : 0 ) |
( V_2 -> V_179 . V_181 ? V_183 : 0 ) ;
F_32 ( V_2 , V_178 , V_37 ) ;
F_31 ( V_2 , V_184 , & V_37 ) ;
F_32 ( V_2 , V_184 , 0x00 ) ;
V_2 -> V_179 . V_185 = 0x00 ;
F_31 ( V_2 , V_186 , & V_37 ) ;
F_32 ( V_2 , V_186 , 0x30 ) ;
F_32 ( V_2 , V_187 , 0x12 ) ;
F_31 ( V_2 , V_188 , & V_37 ) ;
F_32 ( V_2 , V_188 , 0x0f ) ;
V_2 -> V_179 . V_189 = 0x0f ;
F_31 ( V_2 , V_186 , & V_37 ) ;
F_32 ( V_2 , V_186 , 0x30 ) ;
F_31 ( V_2 , V_190 , & V_37 ) ;
F_32 ( V_2 , V_190 , 0x10 ) ;
F_32 ( V_2 , V_191 , 0x19 ) ;
F_32 ( V_2 , V_192 , 0x0c ) ;
F_32 ( V_2 , V_193 , 0x00 ) ;
F_31 ( V_2 , V_151 , & V_102 ) ;
F_7 ( V_2 -> V_73 -> V_74 , L_21 , V_102 ) ;
F_32 ( V_2 , V_194 , 0x00 ) ;
F_32 ( V_2 , V_195 , V_196 ) ;
F_32 ( V_2 , V_187 , 0x12 ) ;
#if 0
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_0, EMU_SRC_HAMOA_ADC_LEFT1);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_1, EMU_SRC_HAMOA_ADC_RIGHT1);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_4, EMU_SRC_HAMOA_ADC_LEFT2);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_5, EMU_SRC_HAMOA_ADC_RIGHT2);
#endif
#if 0
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_0, EMU_SRC_HAMOA_ADC_LEFT1);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_1, EMU_SRC_HAMOA_ADC_RIGHT1);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_2, EMU_SRC_HAMOA_ADC_LEFT2);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_3, EMU_SRC_HAMOA_ADC_RIGHT2);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_4, EMU_SRC_HAMOA_ADC_LEFT3);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_5, EMU_SRC_HAMOA_ADC_RIGHT3);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_6, EMU_SRC_HAMOA_ADC_LEFT4);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_7, EMU_SRC_HAMOA_ADC_RIGHT4);
#endif
#if 1
F_36 ( V_2 ,
V_197 , V_198 ) ;
F_36 ( V_2 ,
V_199 , V_200 ) ;
F_36 ( V_2 ,
V_201 , V_202 ) ;
F_36 ( V_2 ,
V_203 , V_202 ) ;
F_36 ( V_2 ,
V_204 , V_205 ) ;
F_36 ( V_2 ,
V_206 , V_207 ) ;
F_36 ( V_2 ,
V_208 , V_209 ) ;
F_36 ( V_2 ,
V_210 , V_211 ) ;
F_36 ( V_2 ,
V_212 , V_198 ) ;
F_36 ( V_2 ,
V_213 , V_200 ) ;
F_36 ( V_2 ,
V_214 , V_202 ) ;
F_36 ( V_2 ,
V_215 , V_202 ) ;
F_36 ( V_2 ,
V_216 , V_205 ) ;
F_36 ( V_2 ,
V_217 , V_207 ) ;
F_36 ( V_2 ,
V_218 , V_209 ) ;
F_36 ( V_2 ,
V_219 , V_211 ) ;
#endif
#if 0
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_4, EMU_SRC_HANA_ADAT);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_5, EMU_SRC_HANA_ADAT + 1);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_6, EMU_SRC_HANA_ADAT + 2);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_7, EMU_SRC_HANA_ADAT + 3);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_8, EMU_SRC_HANA_ADAT + 4);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_9, EMU_SRC_HANA_ADAT + 5);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_A, EMU_SRC_HANA_ADAT + 6);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_B, EMU_SRC_HANA_ADAT + 7);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_C, EMU_SRC_DOCK_MIC_A1);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_D, EMU_SRC_DOCK_MIC_B1);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_E, EMU_SRC_HAMOA_ADC_LEFT2);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_F, EMU_SRC_HAMOA_ADC_LEFT2);
#endif
for ( V_142 = 0 ; V_142 < 0x20 ; V_142 ++ ) {
F_36 ( V_2 , 0x0100 + V_142 , V_220 ) ;
}
for ( V_142 = 0 ; V_142 < 4 ; V_142 ++ ) {
F_36 ( V_2 , 0x0200 + V_142 , V_220 ) ;
}
for ( V_142 = 0 ; V_142 < 7 ; V_142 ++ ) {
F_36 ( V_2 , 0x0300 + V_142 , V_220 ) ;
}
for ( V_142 = 0 ; V_142 < 7 ; V_142 ++ ) {
F_36 ( V_2 , V_221 + V_142 , V_220 ) ;
}
F_36 ( V_2 ,
V_222 , V_205 ) ;
F_36 ( V_2 ,
V_223 , V_207 ) ;
F_36 ( V_2 ,
V_224 , V_209 ) ;
F_36 ( V_2 ,
V_225 , V_211 ) ;
F_36 ( V_2 ,
V_226 , V_227 ) ;
F_36 ( V_2 ,
V_228 , V_229 ) ;
F_32 ( V_2 , V_166 , 0x01 ) ;
F_31 ( V_2 , V_151 , & V_37 ) ;
F_4 ( 0x0000a000 , V_2 -> V_41 + V_42 ) ;
F_4 ( 0x0000a001 , V_2 -> V_41 + V_42 ) ;
F_31 ( V_2 , V_151 , & V_37 ) ;
F_32 ( V_2 , V_191 , 0x19 ) ;
F_32 ( V_2 , V_192 , 0x0c ) ;
F_32 ( V_2 , V_191 , 0x19 ) ;
F_32 ( V_2 , V_192 , 0x0c ) ;
F_31 ( V_2 , V_190 , & V_37 ) ;
F_32 ( V_2 , V_190 , 0x10 ) ;
if ( ! V_2 -> V_179 . V_230 ) {
V_2 -> V_179 . V_230 =
F_37 ( F_27 , V_2 ,
L_22 ) ;
F_38 ( V_2 -> V_179 . V_230 ) ;
}
#if 0
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_HAMOA_DAC_LEFT1, EMU_SRC_ALICE_EMU32B + 2);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_HAMOA_DAC_RIGHT1, EMU_SRC_ALICE_EMU32B + 3);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_HANA_SPDIF_LEFT1, EMU_SRC_ALICE_EMU32A + 2);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_HANA_SPDIF_RIGHT1, EMU_SRC_ALICE_EMU32A + 3);
#endif
if ( V_2 -> V_65 -> V_92 == V_161 ) {
F_36 ( V_2 ,
V_231 , V_232 + 0 ) ;
V_2 -> V_179 . V_233 [ 0 ] = 17 ;
F_36 ( V_2 ,
V_234 , V_232 + 1 ) ;
V_2 -> V_179 . V_233 [ 1 ] = 18 ;
F_36 ( V_2 ,
V_235 , V_232 + 2 ) ;
V_2 -> V_179 . V_233 [ 2 ] = 19 ;
F_36 ( V_2 ,
V_236 , V_232 + 3 ) ;
V_2 -> V_179 . V_233 [ 3 ] = 20 ;
F_36 ( V_2 ,
V_237 , V_232 + 4 ) ;
V_2 -> V_179 . V_233 [ 4 ] = 21 ;
F_36 ( V_2 ,
V_238 , V_232 + 5 ) ;
V_2 -> V_179 . V_233 [ 5 ] = 22 ;
F_36 ( V_2 ,
V_239 , V_232 + 0 ) ;
V_2 -> V_179 . V_233 [ 16 ] = 17 ;
F_36 ( V_2 ,
V_240 , V_232 + 1 ) ;
V_2 -> V_179 . V_233 [ 17 ] = 18 ;
} else {
F_36 ( V_2 ,
V_231 , V_232 + 0 ) ;
V_2 -> V_179 . V_233 [ 0 ] = 21 ;
F_36 ( V_2 ,
V_234 , V_232 + 1 ) ;
V_2 -> V_179 . V_233 [ 1 ] = 22 ;
F_36 ( V_2 ,
V_235 , V_232 + 2 ) ;
V_2 -> V_179 . V_233 [ 2 ] = 23 ;
F_36 ( V_2 ,
V_236 , V_232 + 3 ) ;
V_2 -> V_179 . V_233 [ 3 ] = 24 ;
F_36 ( V_2 ,
V_237 , V_232 + 4 ) ;
V_2 -> V_179 . V_233 [ 4 ] = 25 ;
F_36 ( V_2 ,
V_238 , V_232 + 5 ) ;
V_2 -> V_179 . V_233 [ 5 ] = 26 ;
F_36 ( V_2 ,
V_241 , V_232 + 6 ) ;
V_2 -> V_179 . V_233 [ 6 ] = 27 ;
F_36 ( V_2 ,
V_242 , V_232 + 7 ) ;
V_2 -> V_179 . V_233 [ 7 ] = 28 ;
F_36 ( V_2 ,
V_243 , V_232 + 0 ) ;
V_2 -> V_179 . V_233 [ 8 ] = 21 ;
F_36 ( V_2 ,
V_244 , V_232 + 1 ) ;
V_2 -> V_179 . V_233 [ 9 ] = 22 ;
F_36 ( V_2 ,
V_245 , V_232 + 0 ) ;
V_2 -> V_179 . V_233 [ 10 ] = 21 ;
F_36 ( V_2 ,
V_246 , V_232 + 1 ) ;
V_2 -> V_179 . V_233 [ 11 ] = 22 ;
F_36 ( V_2 ,
V_247 , V_232 + 0 ) ;
V_2 -> V_179 . V_233 [ 12 ] = 21 ;
F_36 ( V_2 ,
V_248 , V_232 + 1 ) ;
V_2 -> V_179 . V_233 [ 13 ] = 22 ;
F_36 ( V_2 ,
V_249 , V_232 + 0 ) ;
V_2 -> V_179 . V_233 [ 14 ] = 21 ;
F_36 ( V_2 ,
V_250 , V_232 + 1 ) ;
V_2 -> V_179 . V_233 [ 15 ] = 22 ;
F_36 ( V_2 ,
V_221 , V_232 + 0 ) ;
V_2 -> V_179 . V_233 [ 16 ] = 21 ;
F_36 ( V_2 ,
V_221 + 1 , V_232 + 1 ) ;
V_2 -> V_179 . V_233 [ 17 ] = 22 ;
F_36 ( V_2 ,
V_221 + 2 , V_232 + 2 ) ;
V_2 -> V_179 . V_233 [ 18 ] = 23 ;
F_36 ( V_2 ,
V_221 + 3 , V_232 + 3 ) ;
V_2 -> V_179 . V_233 [ 19 ] = 24 ;
F_36 ( V_2 ,
V_221 + 4 , V_232 + 4 ) ;
V_2 -> V_179 . V_233 [ 20 ] = 25 ;
F_36 ( V_2 ,
V_221 + 5 , V_232 + 5 ) ;
V_2 -> V_179 . V_233 [ 21 ] = 26 ;
F_36 ( V_2 ,
V_221 + 6 , V_232 + 6 ) ;
V_2 -> V_179 . V_233 [ 22 ] = 27 ;
F_36 ( V_2 ,
V_221 + 7 , V_232 + 7 ) ;
V_2 -> V_179 . V_233 [ 23 ] = 28 ;
}
F_32 ( V_2 , V_166 , 0x0 ) ;
F_32 ( V_2 , V_194 , 0x0 ) ;
F_32 ( V_2 , V_195 , V_196 ) ;
V_2 -> V_179 . V_251 = 1 ;
F_32 ( V_2 , V_187 , 0x12 ) ;
F_32 ( V_2 , V_166 , 0x1 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
if ( V_2 -> V_41 ) {
F_40 ( V_2 , 0 ) ;
F_15 ( V_2 ) ;
F_41 ( V_2 ) ;
}
if ( V_2 -> V_65 -> V_92 == V_157 ) {
F_32 ( V_2 , V_168 , 0 ) ;
}
if ( V_2 -> V_179 . V_230 )
F_42 ( V_2 -> V_179 . V_230 ) ;
if ( V_2 -> V_140 )
F_43 ( V_2 -> V_140 ) ;
if ( V_2 -> V_155 )
F_43 ( V_2 -> V_155 ) ;
if ( V_2 -> V_252 >= 0 )
F_44 ( V_2 -> V_252 , V_2 ) ;
if ( V_2 -> V_253 ) {
F_45 ( V_2 ,
(struct V_254 * ) V_2 -> V_253 ) ;
V_2 -> V_253 = NULL ;
}
if ( V_2 -> V_255 )
F_46 ( V_2 -> V_255 ) ;
if ( V_2 -> V_36 . V_256 )
F_47 ( & V_2 -> V_36 ) ;
if ( V_2 -> V_85 . V_256 )
F_47 ( & V_2 -> V_85 ) ;
F_48 ( V_2 -> V_257 ) ;
F_48 ( V_2 -> V_258 ) ;
#ifdef F_30
F_49 ( V_2 ) ;
#endif
if ( V_2 -> V_41 )
F_50 ( V_2 -> V_162 ) ;
if ( V_2 -> V_65 -> V_66 )
F_51 ( V_2 ) ;
F_52 ( V_2 -> V_162 ) ;
F_53 ( V_2 ) ;
return 0 ;
}
static int F_54 ( struct V_259 * V_260 )
{
struct V_1 * V_2 = V_260 -> V_261 ;
return F_39 ( V_2 ) ;
}
int F_55 ( struct V_262 * V_73 ,
struct V_263 * V_162 ,
unsigned short V_264 ,
unsigned short V_265 ,
long V_266 ,
int V_34 ,
T_2 V_267 ,
struct V_1 * * V_268 )
{
struct V_1 * V_2 ;
int V_269 , V_148 ;
int V_270 ;
unsigned int V_36 ;
const struct V_271 * V_272 ;
static struct V_273 V_274 = {
. V_275 = F_54 ,
} ;
* V_268 = NULL ;
V_148 = F_56 ( V_162 ) ;
if ( V_148 < 0 )
return V_148 ;
V_2 = F_57 ( sizeof( * V_2 ) , V_276 ) ;
if ( V_2 == NULL ) {
F_52 ( V_162 ) ;
return - V_277 ;
}
V_2 -> V_73 = V_73 ;
F_58 ( & V_2 -> V_278 ) ;
F_58 ( & V_2 -> V_146 ) ;
F_58 ( & V_2 -> V_279 ) ;
F_58 ( & V_2 -> V_280 ) ;
F_58 ( & V_2 -> V_281 ) ;
F_58 ( & V_2 -> V_282 ) ;
F_58 ( & V_2 -> V_283 ) ;
F_59 ( & V_2 -> V_284 . V_285 ) ;
F_60 ( & V_2 -> V_286 ) ;
F_60 ( & V_2 -> V_287 ) ;
V_2 -> V_162 = V_162 ;
V_2 -> V_252 = - 1 ;
V_2 -> V_288 = NULL ;
V_2 -> V_289 = NULL ;
V_2 -> V_96 = V_162 -> V_96 ;
F_61 ( V_162 , V_290 , & V_2 -> V_291 ) ;
F_62 ( V_162 , V_292 , & V_2 -> V_101 ) ;
F_35 ( V_73 -> V_74 ,
L_23 ,
V_162 -> V_293 , V_162 -> V_260 , V_2 -> V_291 , V_2 -> V_101 ) ;
for ( V_272 = V_294 ; V_272 -> V_293 ; V_272 ++ ) {
if ( V_272 -> V_293 == V_162 -> V_293 && V_272 -> V_260 == V_162 -> V_260 ) {
if ( V_267 ) {
if ( V_272 -> V_267 && ( V_272 -> V_267 == V_267 ) )
break;
else
continue;
} else {
if ( V_272 -> V_267 && ( V_272 -> V_267 != V_2 -> V_291 ) )
continue;
if ( V_272 -> V_96 && V_272 -> V_96 != V_2 -> V_96 )
continue;
}
break;
}
}
if ( V_272 -> V_293 == 0 ) {
F_63 ( V_73 -> V_74 , L_24 ) ;
F_53 ( V_2 ) ;
F_52 ( V_162 ) ;
return - V_295 ;
}
V_2 -> V_65 = V_272 ;
if ( V_272 -> V_267 && ! V_267 )
F_35 ( V_73 -> V_74 , L_25 , V_272 -> V_296 ) ;
else if ( V_267 )
F_35 ( V_73 -> V_74 , L_26
L_27
L_28 , V_272 -> V_296 ,
V_162 -> V_293 , V_162 -> V_260 , V_2 -> V_291 , V_272 -> V_267 ) ;
else
F_35 ( V_73 -> V_74 , L_26
L_29 ,
V_272 -> V_296 , V_162 -> V_293 , V_162 -> V_260 ,
V_2 -> V_291 ) ;
if ( ! * V_73 -> V_297 && V_272 -> V_297 ) {
int V_142 , V_78 = 0 ;
F_64 ( V_73 -> V_297 , V_272 -> V_297 , sizeof( V_73 -> V_297 ) ) ;
for (; ; ) {
for ( V_142 = 0 ; V_142 < V_298 ; V_142 ++ ) {
if ( V_299 [ V_142 ] && ! strcmp ( V_299 [ V_142 ] -> V_297 , V_73 -> V_297 ) )
break;
}
if ( V_142 >= V_298 )
break;
V_78 ++ ;
if ( V_78 >= V_300 )
break;
snprintf ( V_73 -> V_297 , sizeof( V_73 -> V_297 ) , L_30 , V_272 -> V_297 , V_78 ) ;
}
}
V_270 = V_2 -> V_30 = V_272 -> V_301 ;
V_2 -> V_302 = V_270 ? V_303 : V_304 ;
if ( F_65 ( V_162 , V_2 -> V_302 ) < 0 ||
F_66 ( V_162 , V_2 -> V_302 ) < 0 ) {
F_63 ( V_73 -> V_74 ,
L_31 ,
V_2 -> V_302 ) ;
F_53 ( V_2 ) ;
F_52 ( V_162 ) ;
return - V_305 ;
}
if ( V_270 )
V_2 -> V_306 = V_307 ;
else
V_2 -> V_306 = V_308 ;
V_148 = F_67 ( V_162 , L_32 ) ;
if ( V_148 < 0 ) {
F_53 ( V_2 ) ;
F_52 ( V_162 ) ;
return V_148 ;
}
V_2 -> V_41 = F_68 ( V_162 , 0 ) ;
V_2 -> V_309 = V_266 >> V_310 ;
if ( F_69 ( V_311 , F_70 ( V_162 ) ,
32 * 1024 , & V_2 -> V_85 ) < 0 ) {
V_148 = - V_277 ;
goto error;
}
V_2 -> V_257 = F_71 ( V_2 -> V_309 * sizeof( void * ) ) ;
V_2 -> V_258 = F_71 ( V_2 -> V_309 *
sizeof( unsigned long ) ) ;
if ( V_2 -> V_257 == NULL || V_2 -> V_258 == NULL ) {
V_148 = - V_277 ;
goto error;
}
if ( F_69 ( V_311 , F_70 ( V_162 ) ,
V_312 , & V_2 -> V_36 ) < 0 ) {
V_148 = - V_277 ;
goto error;
}
V_2 -> V_255 = F_72 ( V_2 -> V_309 * V_313 ) ;
if ( V_2 -> V_255 == NULL ) {
V_148 = - V_277 ;
goto error;
}
V_2 -> V_255 -> V_314 = sizeof( struct V_315 ) -
sizeof( struct V_254 ) ;
F_73 ( V_162 ) ;
V_2 -> V_284 . V_316 = 0x303f ;
if ( V_264 == 0 )
V_264 = 0x3fcf ;
if ( V_265 == 0 )
V_265 = 0x7fff ;
V_2 -> V_284 . V_264 = V_264 ;
V_2 -> V_284 . V_265 = V_265 ;
V_2 -> V_34 = V_34 ;
if ( V_2 -> V_65 -> V_317 ) {
V_148 = F_22 ( V_2 ) ;
if ( V_148 < 0 )
goto error;
}
if ( V_2 -> V_65 -> V_318 ) {
V_148 = F_18 ( V_2 ) ;
if ( V_148 < 0 )
goto error;
} else if ( V_2 -> V_65 -> V_92 ) {
V_148 = F_34 ( V_2 ) ;
if ( V_148 < 0 ) {
F_39 ( V_2 ) ;
return V_148 ;
}
} else {
F_2 ( V_2 , V_57 , 0 ,
V_319 | V_320 ) ;
}
V_2 -> V_284 . V_321 = ( 16 * 1024 ) / 2 ;
V_2 -> V_284 . V_322 . V_256 = NULL ;
V_2 -> V_284 . V_322 . V_323 = 0 ;
if ( F_74 ( V_162 -> V_252 , V_324 , V_325 ,
V_326 , V_2 ) ) {
V_148 = - V_327 ;
goto error;
}
V_2 -> V_252 = V_162 -> V_252 ;
V_2 -> V_62 [ 0 ] = V_2 -> V_62 [ 1 ] =
V_2 -> V_62 [ 2 ] = V_328 | V_329 |
V_330 | V_331 |
V_332 | 0x00001200 |
0x00000000 | V_333 | V_334 ;
V_2 -> V_253 = (struct V_315 * )
F_75 ( V_2 , 4096 ) ;
if ( V_2 -> V_253 )
V_2 -> V_253 -> V_335 = 1 ;
memset ( V_2 -> V_36 . V_256 , 0 , V_313 ) ;
V_36 = V_2 -> V_36 . V_86 << 1 ;
for ( V_269 = 0 ; V_269 < V_336 ; V_269 ++ )
( ( T_1 * ) V_2 -> V_85 . V_256 ) [ V_269 ] = F_76 ( V_36 | V_269 ) ;
for ( V_269 = 0 ; V_269 < V_60 ; V_269 ++ ) {
V_2 -> V_337 [ V_269 ] . V_2 = V_2 ;
V_2 -> V_337 [ V_269 ] . V_338 = V_269 ;
}
V_148 = F_3 ( V_2 , V_34 , 0 ) ;
if ( V_148 < 0 )
goto error;
#ifdef F_30
V_148 = F_77 ( V_2 ) ;
if ( V_148 < 0 )
goto error;
#endif
V_148 = F_78 ( V_2 ) ;
if ( V_148 < 0 )
goto error;
F_13 ( V_2 ) ;
V_148 = F_79 ( V_73 , V_339 , V_2 , & V_274 ) ;
if ( V_148 < 0 )
goto error;
#ifdef F_80
F_81 ( V_2 ) ;
#endif
* V_268 = V_2 ;
return 0 ;
error:
F_39 ( V_2 ) ;
return V_148 ;
}
static int F_77 ( struct V_1 * V_2 )
{
int V_77 ;
V_77 = F_9 ( V_340 ) ;
if ( V_2 -> V_30 )
V_77 += F_9 ( V_341 ) ;
V_2 -> V_342 = F_71 ( 4 * V_60 * V_77 ) ;
if ( ! V_2 -> V_342 )
return - V_277 ;
if ( F_82 ( V_2 ) < 0 )
return - V_277 ;
if ( V_2 -> V_65 -> V_66 &&
F_83 ( V_2 ) < 0 )
return - V_277 ;
return 0 ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_48 ( V_2 -> V_342 ) ;
F_84 ( V_2 ) ;
if ( V_2 -> V_65 -> V_66 )
F_85 ( V_2 ) ;
}
void F_86 ( struct V_1 * V_2 )
{
int V_142 ;
unsigned char * V_102 ;
unsigned int * V_343 ;
V_343 = V_2 -> V_342 ;
for ( V_102 = V_340 ; * V_102 != 0xff ; V_102 ++ )
for ( V_142 = 0 ; V_142 < V_60 ; V_142 ++ , V_343 ++ )
* V_343 = F_5 ( V_2 , * V_102 , V_142 ) ;
if ( V_2 -> V_30 ) {
for ( V_102 = V_341 ; * V_102 != 0xff ; V_102 ++ )
for ( V_142 = 0 ; V_142 < V_60 ; V_142 ++ , V_343 ++ )
* V_343 = F_5 ( V_2 , * V_102 , V_142 ) ;
}
if ( V_2 -> V_30 )
V_2 -> V_344 = F_8 ( V_2 -> V_41 + V_75 ) ;
V_2 -> V_345 = F_8 ( V_2 -> V_41 + V_42 ) ;
}
void F_87 ( struct V_1 * V_2 )
{
if ( V_2 -> V_65 -> V_317 )
F_22 ( V_2 ) ;
if ( V_2 -> V_65 -> V_318 )
F_18 ( V_2 ) ;
else if ( V_2 -> V_65 -> V_92 )
F_34 ( V_2 ) ;
else
F_2 ( V_2 , V_57 , 0 , V_319 | V_320 ) ;
F_3 ( V_2 , V_2 -> V_34 , 1 ) ;
}
void F_88 ( struct V_1 * V_2 )
{
int V_142 ;
unsigned char * V_102 ;
unsigned int * V_343 ;
F_13 ( V_2 ) ;
if ( V_2 -> V_30 )
F_4 ( V_2 -> V_344 , V_2 -> V_41 + V_75 ) ;
F_4 ( V_2 -> V_345 , V_2 -> V_41 + V_42 ) ;
V_343 = V_2 -> V_342 ;
for ( V_102 = V_340 ; * V_102 != 0xff ; V_102 ++ )
for ( V_142 = 0 ; V_142 < V_60 ; V_142 ++ , V_343 ++ )
F_2 ( V_2 , * V_102 , V_142 , * V_343 ) ;
if ( V_2 -> V_30 ) {
for ( V_102 = V_341 ; * V_102 != 0xff ; V_102 ++ )
for ( V_142 = 0 ; V_142 < V_60 ; V_142 ++ , V_343 ++ )
F_2 ( V_2 , * V_102 , V_142 , * V_343 ) ;
}
}

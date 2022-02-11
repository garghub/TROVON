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
V_36 = ( V_2 -> V_36 . V_86 << V_2 -> V_89 ) | ( V_2 -> V_89 ? V_90 : V_91 ) ;
for ( V_3 = 0 ; V_3 < V_60 ; V_3 ++ ) {
F_2 ( V_2 , V_92 , V_3 , V_36 ) ;
F_2 ( V_2 , V_93 , V_3 , V_36 ) ;
}
if ( V_2 -> V_65 -> V_94 ) {
F_4 ( V_95 |
V_96 |
V_97 , V_2 -> V_41 + V_42 ) ;
} else if ( V_2 -> V_30 ) {
if ( V_2 -> V_98 == 4 )
F_4 ( V_97 |
V_99 |
V_100 |
V_101 | V_102 , V_2 -> V_41 + V_42 ) ;
else
F_4 ( V_101 | V_102 , V_2 -> V_41 + V_42 ) ;
} else if ( V_2 -> V_103 == 0x20 ||
V_2 -> V_103 == 0xc400 ||
( V_2 -> V_103 == 0x21 && V_2 -> V_98 < 6 ) )
F_4 ( V_39 | V_101 , V_2 -> V_41 + V_42 ) ;
else
F_4 ( V_39 | V_101 | V_102 , V_2 -> V_41 + V_42 ) ;
if ( V_34 ) {
if ( V_2 -> V_65 -> V_94 ) {
;
} else if ( V_2 -> V_65 -> V_80 ) {
;
} else if ( V_2 -> V_30 ) {
unsigned int V_104 = F_8 ( V_2 -> V_41 + V_75 ) ;
F_4 ( V_104 | V_105 , V_2 -> V_41 + V_75 ) ;
F_12 ( 500 ) ;
F_4 ( V_104 | V_106 | V_105 , V_2 -> V_41 + V_75 ) ;
F_12 ( 100 ) ;
F_4 ( V_104 , V_2 -> V_41 + V_75 ) ;
} else {
unsigned int V_104 = F_8 ( V_2 -> V_41 + V_42 ) ;
F_4 ( V_104 | V_107 , V_2 -> V_41 + V_42 ) ;
F_12 ( 500 ) ;
F_4 ( V_104 | V_108 | V_107 , V_2 -> V_41 + V_42 ) ;
F_12 ( 100 ) ;
F_4 ( V_104 , V_2 -> V_41 + V_42 ) ;
}
}
if ( V_2 -> V_65 -> V_94 ) {
;
} else if ( V_2 -> V_65 -> V_80 ) {
;
} else if ( V_2 -> V_30 ) {
unsigned int V_104 = F_8 ( V_2 -> V_41 + V_75 ) ;
F_4 ( V_104 | V_109 , V_2 -> V_41 + V_75 ) ;
}
if ( V_2 -> V_89 == 0 ) {
F_4 ( F_8 ( V_2 -> V_41 + V_42 ) | V_110 , V_2 -> V_41 + V_42 ) ;
}
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_4 ( F_8 ( V_2 -> V_41 + V_42 ) | V_97 , V_2 -> V_41 + V_42 ) ;
if ( V_2 -> V_65 -> V_94 ) {
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
F_14 ( V_2 , V_111 ) ;
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
F_2 ( V_2 , V_112 , 0 , 0 ) ;
F_2 ( V_2 , V_48 , 0 , V_44 ) ;
F_2 ( V_2 , V_49 , 0 , 0 ) ;
F_2 ( V_2 , V_88 , 0 , V_113 ) ;
F_2 ( V_2 , V_87 , 0 , 0 ) ;
if ( V_2 -> V_30 )
F_2 ( V_2 , V_114 , 0 , V_115 ) ;
else
F_2 ( V_2 , V_116 , 0 , V_117 ) ;
F_2 ( V_2 , V_51 , 0 , 0 ) ;
F_2 ( V_2 , V_52 , 0 , 0 ) ;
F_2 ( V_2 , V_53 , 0 , 0 ) ;
F_2 ( V_2 , V_54 , 0 , 0 ) ;
F_4 ( V_38 | V_39 | V_40 , V_2 -> V_41 + V_42 ) ;
F_2 ( V_2 , V_84 , 0 , 0 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 , unsigned int V_118 )
{
unsigned short V_119 ;
unsigned int V_120 ;
unsigned long V_121 ;
unsigned int V_122 ;
V_121 = V_2 -> V_41 + V_42 ;
V_122 = F_8 ( V_121 ) & ~ ( V_123 | V_124 | V_125 ) ;
F_4 ( V_122 , V_121 ) ;
for ( V_119 = 0 ; V_119 < V_126 ; V_119 ++ ) {
V_120 = ( ( V_118 & 0x1 ) ? V_125 : 0 ) ;
V_118 >>= 1 ;
F_4 ( V_122 | V_120 , V_121 ) ;
F_4 ( V_122 | V_120 | V_124 , V_121 ) ;
F_4 ( V_122 | V_120 , V_121 ) ;
}
F_4 ( V_122 | V_123 , V_121 ) ;
F_4 ( V_122 , V_121 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
unsigned short V_127 )
{
unsigned int V_128 ;
F_16 ( V_2 , V_2 -> V_129 & ~ V_130 ) ;
F_16 ( V_2 , V_2 -> V_129 & ~ V_130 ) ;
for ( V_128 = ( 1 << 15 ) ; V_128 ; V_128 >>= 1 ) {
unsigned int V_118 ;
V_118 = V_2 -> V_129 & ~ ( V_130 | V_131 ) ;
if ( V_127 & V_128 )
V_118 |= V_131 ;
F_16 ( V_2 , V_118 ) ;
F_16 ( V_2 , V_118 | V_132 ) ;
F_16 ( V_2 , V_118 ) ;
}
F_16 ( V_2 , V_2 -> V_129 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
unsigned int V_122 ;
V_2 -> V_129 = V_133 |
F_19 ( V_134 ) |
F_20 ( V_135 ) ;
V_122 = F_8 ( V_2 -> V_41 + V_42 ) ;
F_4 ( V_122 | V_97 | V_136 , V_2 -> V_41 + V_42 ) ;
F_8 ( V_2 -> V_41 + V_42 ) ;
F_16 ( V_2 , V_137 | V_138 | V_130 ) ;
F_16 ( V_2 , V_139 | V_138 | V_130 ) ;
F_21 ( V_2 , 48000 ) ;
F_16 ( V_2 , V_137 | V_138 | V_130 ) ;
F_16 ( V_2 , V_2 -> V_129 ) ;
F_17 ( V_2 , V_140 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
unsigned long V_141 ;
unsigned int V_118 ;
V_141 = V_2 -> V_41 + 0x38 ;
V_118 = F_8 ( V_141 ) ;
F_4 ( 0x00d00000 , V_141 ) ;
V_118 = F_8 ( V_141 ) ;
F_4 ( 0x00d00001 , V_141 ) ;
V_118 = F_8 ( V_141 ) ;
F_4 ( 0x00d0005f , V_141 ) ;
V_118 = F_8 ( V_141 ) ;
F_4 ( 0x00d0007f , V_141 ) ;
V_118 = F_8 ( V_141 ) ;
F_4 ( 0x0090007f , V_141 ) ;
V_118 = F_8 ( V_141 ) ;
F_6 ( V_2 , V_142 , 0 , 0xfefefefe ) ;
F_23 ( 200 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
const struct V_143 * V_144 )
{
int V_78 , V_145 ;
int V_104 ;
int V_118 ;
unsigned int V_146 ;
unsigned long V_147 ;
if ( ! V_144 )
return - V_148 ;
F_25 ( & V_2 -> V_149 , V_147 ) ;
F_4 ( 0x00 , V_2 -> V_41 + V_75 ) ;
V_146 = F_8 ( V_2 -> V_41 + V_75 ) ;
F_12 ( 100 ) ;
F_4 ( 0x80 , V_2 -> V_41 + V_75 ) ;
V_146 = F_8 ( V_2 -> V_41 + V_75 ) ;
F_12 ( 100 ) ;
for ( V_78 = 0 ; V_78 < V_144 -> V_77 ; V_78 ++ ) {
V_118 = V_144 -> V_120 [ V_78 ] ;
for ( V_145 = 0 ; V_145 < 8 ; V_145 ++ ) {
V_104 = 0x80 ;
if ( V_118 & 0x1 )
V_104 = V_104 | 0x20 ;
V_118 = V_118 >> 1 ;
F_4 ( V_104 , V_2 -> V_41 + V_75 ) ;
V_146 = F_8 ( V_2 -> V_41 + V_75 ) ;
F_4 ( V_104 | 0x40 , V_2 -> V_41 + V_75 ) ;
V_146 = F_8 ( V_2 -> V_41 + V_75 ) ;
}
}
F_4 ( 0x10 , V_2 -> V_41 + V_75 ) ;
V_146 = F_8 ( V_2 -> V_41 + V_75 ) ;
F_26 ( & V_2 -> V_149 , V_147 ) ;
return 0 ;
}
static int F_27 ( void * V_120 )
{
struct V_1 * V_2 = V_120 ;
T_1 V_37 , V_150 , V_104 ;
T_1 V_151 = 0 ;
int V_152 ;
for (; ; ) {
F_28 ( 1000 ) ;
if ( F_29 () )
break;
#ifdef F_30
if ( V_2 -> V_153 )
continue;
#endif
F_31 ( V_2 , V_154 , & V_37 ) ;
F_31 ( V_2 , V_155 , & V_104 ) ;
if ( V_104 & V_156 ) {
F_7 ( V_2 -> V_73 -> V_74 ,
L_2 ) ;
F_32 ( V_2 , V_157 , V_158 ) ;
if ( ! V_2 -> V_159 ) {
const char * V_160 = NULL ;
switch ( V_2 -> V_65 -> V_94 ) {
case V_161 :
V_160 = V_162 ;
break;
case V_163 :
V_160 = V_164 ;
break;
case V_165 :
V_160 = V_164 ;
break;
}
if ( V_160 ) {
V_152 = F_33 ( & V_2 -> V_159 ,
V_160 ,
& V_2 -> V_166 -> V_74 ) ;
if ( V_152 )
continue;
}
}
if ( V_2 -> V_159 ) {
V_152 = F_24 ( V_2 , V_2 -> V_159 ) ;
if ( V_152 )
continue;
}
F_32 ( V_2 , V_157 , 0 ) ;
F_31 ( V_2 , V_154 , & V_104 ) ;
F_7 ( V_2 -> V_73 -> V_74 ,
L_3 ,
V_104 ) ;
F_31 ( V_2 , V_167 , & V_104 ) ;
F_7 ( V_2 -> V_73 -> V_74 ,
L_4 , V_104 ) ;
if ( ( V_104 & 0x1f ) != 0x15 ) {
F_7 ( V_2 -> V_73 -> V_74 ,
L_5 ,
V_104 ) ;
continue;
}
F_7 ( V_2 -> V_73 -> V_74 ,
L_6 ) ;
F_31 ( V_2 , V_168 , & V_37 ) ;
F_31 ( V_2 , V_169 , & V_150 ) ;
F_7 ( V_2 -> V_73 -> V_74 , L_7 ,
V_37 , V_150 ) ;
F_23 ( 10 ) ;
F_32 ( V_2 , V_170 , V_171 ) ;
} else if ( ! V_104 && V_151 ) {
F_7 ( V_2 -> V_73 -> V_74 ,
L_8 ) ;
F_32 ( V_2 , V_170 , V_171 ) ;
}
V_151 = V_104 ;
}
F_7 ( V_2 -> V_73 -> V_74 , L_9 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
unsigned int V_145 ;
T_1 V_37 , V_150 , V_104 ;
int V_152 ;
F_7 ( V_2 -> V_73 -> V_74 , L_10 ) ;
F_4 ( 0x0005a00c , V_2 -> V_41 + V_42 ) ;
F_4 ( 0x0005a004 , V_2 -> V_41 + V_42 ) ;
F_4 ( 0x0005a000 , V_2 -> V_41 + V_42 ) ;
F_4 ( 0x0005a000 , V_2 -> V_41 + V_42 ) ;
F_32 ( V_2 , V_172 , 0 ) ;
F_31 ( V_2 , V_167 , & V_104 ) ;
F_35 ( V_2 -> V_73 -> V_74 , L_11 , V_104 ) ;
if ( ( V_104 & 0x3f ) == 0x15 ) {
F_32 ( V_2 , V_157 , 0x02 ) ;
}
F_31 ( V_2 , V_167 , & V_104 ) ;
F_35 ( V_2 -> V_73 -> V_74 , L_12 , V_104 ) ;
if ( ( V_104 & 0x3f ) == 0x15 ) {
F_7 ( V_2 -> V_73 -> V_74 ,
L_13 ) ;
return - V_173 ;
}
F_7 ( V_2 -> V_73 -> V_74 , L_14 , V_104 ) ;
if ( ! V_2 -> V_143 ) {
const char * V_160 ;
switch ( V_2 -> V_65 -> V_94 ) {
case V_161 :
V_160 = V_174 ;
break;
case V_163 :
V_160 = V_175 ;
break;
case V_165 :
V_160 = V_176 ;
break;
case V_177 :
V_160 = V_178 ;
break;
default:
return - V_173 ;
}
V_152 = F_33 ( & V_2 -> V_143 , V_160 , & V_2 -> V_166 -> V_74 ) ;
if ( V_152 != 0 ) {
F_7 ( V_2 -> V_73 -> V_74 ,
L_15 ,
V_160 , V_152 ) ;
return V_152 ;
}
F_7 ( V_2 -> V_73 -> V_74 ,
L_16 ,
V_160 , V_2 -> V_143 -> V_77 ) ;
}
V_152 = F_24 ( V_2 , V_2 -> V_143 ) ;
if ( V_152 != 0 ) {
F_7 ( V_2 -> V_73 -> V_74 , L_17 ) ;
return V_152 ;
}
F_31 ( V_2 , V_167 , & V_104 ) ;
if ( ( V_104 & 0x3f ) != 0x15 ) {
F_7 ( V_2 -> V_73 -> V_74 ,
L_18 ,
V_104 ) ;
return - V_173 ;
}
F_7 ( V_2 -> V_73 -> V_74 , L_19 ) ;
F_31 ( V_2 , V_179 , & V_37 ) ;
F_31 ( V_2 , V_180 , & V_150 ) ;
F_7 ( V_2 -> V_73 -> V_74 , L_20 , V_37 , V_150 ) ;
F_32 ( V_2 , V_172 , V_181 ) ;
F_31 ( V_2 , V_155 , & V_104 ) ;
F_7 ( V_2 -> V_73 -> V_74 , L_21 , V_104 ) ;
F_31 ( V_2 , V_155 , & V_104 ) ;
F_7 ( V_2 -> V_73 -> V_74 , L_21 , V_104 ) ;
F_31 ( V_2 , V_182 , & V_37 ) ;
V_2 -> V_183 . V_184 = 1 ;
V_2 -> V_183 . V_185 = 1 ;
V_37 = 0 ;
V_37 = ( V_2 -> V_183 . V_184 ? V_186 : 0 ) |
( V_2 -> V_183 . V_185 ? V_187 : 0 ) ;
F_32 ( V_2 , V_182 , V_37 ) ;
F_31 ( V_2 , V_188 , & V_37 ) ;
F_32 ( V_2 , V_188 , 0x00 ) ;
V_2 -> V_183 . V_189 = 0x00 ;
F_31 ( V_2 , V_190 , & V_37 ) ;
F_32 ( V_2 , V_190 , 0x30 ) ;
F_32 ( V_2 , V_191 , 0x12 ) ;
F_31 ( V_2 , V_192 , & V_37 ) ;
F_32 ( V_2 , V_192 , 0x0f ) ;
V_2 -> V_183 . V_193 = 0x0f ;
F_31 ( V_2 , V_190 , & V_37 ) ;
F_32 ( V_2 , V_190 , 0x30 ) ;
F_31 ( V_2 , V_194 , & V_37 ) ;
F_32 ( V_2 , V_194 , 0x10 ) ;
F_32 ( V_2 , V_195 , 0x19 ) ;
F_32 ( V_2 , V_196 , 0x0c ) ;
F_32 ( V_2 , V_197 , 0x00 ) ;
F_31 ( V_2 , V_155 , & V_104 ) ;
F_7 ( V_2 -> V_73 -> V_74 , L_22 , V_104 ) ;
F_32 ( V_2 , V_198 , 0x00 ) ;
F_32 ( V_2 , V_199 , V_200 ) ;
F_32 ( V_2 , V_191 , 0x12 ) ;
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
V_201 , V_202 ) ;
F_36 ( V_2 ,
V_203 , V_204 ) ;
F_36 ( V_2 ,
V_205 , V_206 ) ;
F_36 ( V_2 ,
V_207 , V_206 ) ;
F_36 ( V_2 ,
V_208 , V_209 ) ;
F_36 ( V_2 ,
V_210 , V_211 ) ;
F_36 ( V_2 ,
V_212 , V_213 ) ;
F_36 ( V_2 ,
V_214 , V_215 ) ;
F_36 ( V_2 ,
V_216 , V_202 ) ;
F_36 ( V_2 ,
V_217 , V_204 ) ;
F_36 ( V_2 ,
V_218 , V_206 ) ;
F_36 ( V_2 ,
V_219 , V_206 ) ;
F_36 ( V_2 ,
V_220 , V_209 ) ;
F_36 ( V_2 ,
V_221 , V_211 ) ;
F_36 ( V_2 ,
V_222 , V_213 ) ;
F_36 ( V_2 ,
V_223 , V_215 ) ;
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
for ( V_145 = 0 ; V_145 < 0x20 ; V_145 ++ ) {
F_36 ( V_2 , 0x0100 + V_145 , V_224 ) ;
}
for ( V_145 = 0 ; V_145 < 4 ; V_145 ++ ) {
F_36 ( V_2 , 0x0200 + V_145 , V_224 ) ;
}
for ( V_145 = 0 ; V_145 < 7 ; V_145 ++ ) {
F_36 ( V_2 , 0x0300 + V_145 , V_224 ) ;
}
for ( V_145 = 0 ; V_145 < 7 ; V_145 ++ ) {
F_36 ( V_2 , V_225 + V_145 , V_224 ) ;
}
F_36 ( V_2 ,
V_226 , V_209 ) ;
F_36 ( V_2 ,
V_227 , V_211 ) ;
F_36 ( V_2 ,
V_228 , V_213 ) ;
F_36 ( V_2 ,
V_229 , V_215 ) ;
F_36 ( V_2 ,
V_230 , V_231 ) ;
F_36 ( V_2 ,
V_232 , V_233 ) ;
F_32 ( V_2 , V_170 , 0x01 ) ;
F_31 ( V_2 , V_155 , & V_37 ) ;
F_4 ( 0x0000a000 , V_2 -> V_41 + V_42 ) ;
F_4 ( 0x0000a001 , V_2 -> V_41 + V_42 ) ;
F_31 ( V_2 , V_155 , & V_37 ) ;
F_32 ( V_2 , V_195 , 0x19 ) ;
F_32 ( V_2 , V_196 , 0x0c ) ;
F_32 ( V_2 , V_195 , 0x19 ) ;
F_32 ( V_2 , V_196 , 0x0c ) ;
F_31 ( V_2 , V_194 , & V_37 ) ;
F_32 ( V_2 , V_194 , 0x10 ) ;
if ( ! V_2 -> V_183 . V_234 ) {
V_2 -> V_183 . V_234 =
F_37 ( F_27 , V_2 ,
L_23 ) ;
F_38 ( V_2 -> V_183 . V_234 ) ;
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
if ( V_2 -> V_65 -> V_94 == V_165 ) {
F_36 ( V_2 ,
V_235 , V_236 + 0 ) ;
V_2 -> V_183 . V_237 [ 0 ] = 17 ;
F_36 ( V_2 ,
V_238 , V_236 + 1 ) ;
V_2 -> V_183 . V_237 [ 1 ] = 18 ;
F_36 ( V_2 ,
V_239 , V_236 + 2 ) ;
V_2 -> V_183 . V_237 [ 2 ] = 19 ;
F_36 ( V_2 ,
V_240 , V_236 + 3 ) ;
V_2 -> V_183 . V_237 [ 3 ] = 20 ;
F_36 ( V_2 ,
V_241 , V_236 + 4 ) ;
V_2 -> V_183 . V_237 [ 4 ] = 21 ;
F_36 ( V_2 ,
V_242 , V_236 + 5 ) ;
V_2 -> V_183 . V_237 [ 5 ] = 22 ;
F_36 ( V_2 ,
V_243 , V_236 + 0 ) ;
V_2 -> V_183 . V_237 [ 16 ] = 17 ;
F_36 ( V_2 ,
V_244 , V_236 + 1 ) ;
V_2 -> V_183 . V_237 [ 17 ] = 18 ;
} else {
F_36 ( V_2 ,
V_235 , V_236 + 0 ) ;
V_2 -> V_183 . V_237 [ 0 ] = 21 ;
F_36 ( V_2 ,
V_238 , V_236 + 1 ) ;
V_2 -> V_183 . V_237 [ 1 ] = 22 ;
F_36 ( V_2 ,
V_239 , V_236 + 2 ) ;
V_2 -> V_183 . V_237 [ 2 ] = 23 ;
F_36 ( V_2 ,
V_240 , V_236 + 3 ) ;
V_2 -> V_183 . V_237 [ 3 ] = 24 ;
F_36 ( V_2 ,
V_241 , V_236 + 4 ) ;
V_2 -> V_183 . V_237 [ 4 ] = 25 ;
F_36 ( V_2 ,
V_242 , V_236 + 5 ) ;
V_2 -> V_183 . V_237 [ 5 ] = 26 ;
F_36 ( V_2 ,
V_245 , V_236 + 6 ) ;
V_2 -> V_183 . V_237 [ 6 ] = 27 ;
F_36 ( V_2 ,
V_246 , V_236 + 7 ) ;
V_2 -> V_183 . V_237 [ 7 ] = 28 ;
F_36 ( V_2 ,
V_247 , V_236 + 0 ) ;
V_2 -> V_183 . V_237 [ 8 ] = 21 ;
F_36 ( V_2 ,
V_248 , V_236 + 1 ) ;
V_2 -> V_183 . V_237 [ 9 ] = 22 ;
F_36 ( V_2 ,
V_249 , V_236 + 0 ) ;
V_2 -> V_183 . V_237 [ 10 ] = 21 ;
F_36 ( V_2 ,
V_250 , V_236 + 1 ) ;
V_2 -> V_183 . V_237 [ 11 ] = 22 ;
F_36 ( V_2 ,
V_251 , V_236 + 0 ) ;
V_2 -> V_183 . V_237 [ 12 ] = 21 ;
F_36 ( V_2 ,
V_252 , V_236 + 1 ) ;
V_2 -> V_183 . V_237 [ 13 ] = 22 ;
F_36 ( V_2 ,
V_253 , V_236 + 0 ) ;
V_2 -> V_183 . V_237 [ 14 ] = 21 ;
F_36 ( V_2 ,
V_254 , V_236 + 1 ) ;
V_2 -> V_183 . V_237 [ 15 ] = 22 ;
F_36 ( V_2 ,
V_225 , V_236 + 0 ) ;
V_2 -> V_183 . V_237 [ 16 ] = 21 ;
F_36 ( V_2 ,
V_225 + 1 , V_236 + 1 ) ;
V_2 -> V_183 . V_237 [ 17 ] = 22 ;
F_36 ( V_2 ,
V_225 + 2 , V_236 + 2 ) ;
V_2 -> V_183 . V_237 [ 18 ] = 23 ;
F_36 ( V_2 ,
V_225 + 3 , V_236 + 3 ) ;
V_2 -> V_183 . V_237 [ 19 ] = 24 ;
F_36 ( V_2 ,
V_225 + 4 , V_236 + 4 ) ;
V_2 -> V_183 . V_237 [ 20 ] = 25 ;
F_36 ( V_2 ,
V_225 + 5 , V_236 + 5 ) ;
V_2 -> V_183 . V_237 [ 21 ] = 26 ;
F_36 ( V_2 ,
V_225 + 6 , V_236 + 6 ) ;
V_2 -> V_183 . V_237 [ 22 ] = 27 ;
F_36 ( V_2 ,
V_225 + 7 , V_236 + 7 ) ;
V_2 -> V_183 . V_237 [ 23 ] = 28 ;
}
F_32 ( V_2 , V_170 , 0x0 ) ;
F_32 ( V_2 , V_198 , 0x0 ) ;
F_32 ( V_2 , V_199 , V_200 ) ;
V_2 -> V_183 . V_255 = 1 ;
F_32 ( V_2 , V_191 , 0x12 ) ;
F_32 ( V_2 , V_170 , 0x1 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
if ( V_2 -> V_41 ) {
F_40 ( V_2 , 0 ) ;
F_15 ( V_2 ) ;
F_41 ( V_2 ) ;
}
if ( V_2 -> V_65 -> V_94 == V_161 ) {
F_32 ( V_2 , V_172 , 0 ) ;
}
if ( V_2 -> V_183 . V_234 )
F_42 ( V_2 -> V_183 . V_234 ) ;
F_43 ( V_2 -> V_143 ) ;
F_43 ( V_2 -> V_159 ) ;
if ( V_2 -> V_256 >= 0 )
F_44 ( V_2 -> V_256 , V_2 ) ;
if ( V_2 -> V_257 ) {
F_45 ( V_2 ,
(struct V_258 * ) V_2 -> V_257 ) ;
V_2 -> V_257 = NULL ;
}
F_46 ( V_2 -> V_259 ) ;
if ( V_2 -> V_36 . V_260 )
F_47 ( & V_2 -> V_36 ) ;
if ( V_2 -> V_85 . V_260 )
F_47 ( & V_2 -> V_85 ) ;
F_48 ( V_2 -> V_261 ) ;
F_48 ( V_2 -> V_262 ) ;
#ifdef F_30
F_49 ( V_2 ) ;
#endif
if ( V_2 -> V_41 )
F_50 ( V_2 -> V_166 ) ;
if ( V_2 -> V_65 -> V_66 )
F_51 ( V_2 ) ;
F_52 ( V_2 -> V_166 ) ;
F_53 ( V_2 ) ;
return 0 ;
}
static int F_54 ( struct V_263 * V_264 )
{
struct V_1 * V_2 = V_264 -> V_265 ;
return F_39 ( V_2 ) ;
}
int F_55 ( struct V_266 * V_73 ,
struct V_267 * V_166 ,
unsigned short V_268 ,
unsigned short V_269 ,
long V_270 ,
int V_34 ,
T_2 V_271 ,
struct V_1 * * V_272 )
{
struct V_1 * V_2 ;
int V_273 , V_152 ;
int V_274 ;
unsigned int V_36 ;
const struct V_275 * V_276 ;
static struct V_277 V_278 = {
. V_279 = F_54 ,
} ;
* V_272 = NULL ;
V_152 = F_56 ( V_166 ) ;
if ( V_152 < 0 )
return V_152 ;
V_2 = F_57 ( sizeof( * V_2 ) , V_280 ) ;
if ( V_2 == NULL ) {
F_52 ( V_166 ) ;
return - V_281 ;
}
V_2 -> V_73 = V_73 ;
F_58 ( & V_2 -> V_282 ) ;
F_58 ( & V_2 -> V_149 ) ;
F_58 ( & V_2 -> V_283 ) ;
F_58 ( & V_2 -> V_284 ) ;
F_58 ( & V_2 -> V_285 ) ;
F_58 ( & V_2 -> V_286 ) ;
F_58 ( & V_2 -> V_287 ) ;
F_59 ( & V_2 -> V_288 . V_289 ) ;
F_60 ( & V_2 -> V_290 ) ;
F_60 ( & V_2 -> V_291 ) ;
V_2 -> V_166 = V_166 ;
V_2 -> V_256 = - 1 ;
V_2 -> V_292 = NULL ;
V_2 -> V_293 = NULL ;
V_2 -> V_98 = V_166 -> V_98 ;
F_61 ( V_166 , V_294 , & V_2 -> V_295 ) ;
F_62 ( V_166 , V_296 , & V_2 -> V_103 ) ;
F_35 ( V_73 -> V_74 ,
L_24 ,
V_166 -> V_297 , V_166 -> V_264 , V_2 -> V_295 , V_2 -> V_103 ) ;
for ( V_276 = V_298 ; V_276 -> V_297 ; V_276 ++ ) {
if ( V_276 -> V_297 == V_166 -> V_297 && V_276 -> V_264 == V_166 -> V_264 ) {
if ( V_271 ) {
if ( V_276 -> V_271 && ( V_276 -> V_271 == V_271 ) )
break;
else
continue;
} else {
if ( V_276 -> V_271 && ( V_276 -> V_271 != V_2 -> V_295 ) )
continue;
if ( V_276 -> V_98 && V_276 -> V_98 != V_2 -> V_98 )
continue;
}
break;
}
}
if ( V_276 -> V_297 == 0 ) {
F_63 ( V_73 -> V_74 , L_25 ) ;
F_53 ( V_2 ) ;
F_52 ( V_166 ) ;
return - V_299 ;
}
V_2 -> V_65 = V_276 ;
if ( V_276 -> V_271 && ! V_271 )
F_35 ( V_73 -> V_74 , L_26 , V_276 -> V_300 ) ;
else if ( V_271 )
F_35 ( V_73 -> V_74 , L_27
L_28
L_29 , V_276 -> V_300 ,
V_166 -> V_297 , V_166 -> V_264 , V_2 -> V_295 , V_276 -> V_271 ) ;
else
F_35 ( V_73 -> V_74 , L_27
L_30 ,
V_276 -> V_300 , V_166 -> V_297 , V_166 -> V_264 ,
V_2 -> V_295 ) ;
if ( ! * V_73 -> V_301 && V_276 -> V_301 ) {
int V_145 , V_78 = 0 ;
F_64 ( V_73 -> V_301 , V_276 -> V_301 , sizeof( V_73 -> V_301 ) ) ;
for (; ; ) {
for ( V_145 = 0 ; V_145 < V_302 ; V_145 ++ ) {
if ( V_303 [ V_145 ] && ! strcmp ( V_303 [ V_145 ] -> V_301 , V_73 -> V_301 ) )
break;
}
if ( V_145 >= V_302 )
break;
V_78 ++ ;
if ( V_78 >= V_304 )
break;
snprintf ( V_73 -> V_301 , sizeof( V_73 -> V_301 ) , L_31 , V_276 -> V_301 , V_78 ) ;
}
}
V_274 = V_2 -> V_30 = V_276 -> V_305 ;
V_2 -> V_89 = V_274 ? 0 : 1 ;
V_2 -> V_306 = V_2 -> V_89 ? V_307 : V_308 ;
if ( F_65 ( & V_166 -> V_74 , V_2 -> V_306 ) < 0 ||
F_66 ( & V_166 -> V_74 , V_2 -> V_306 ) < 0 ) {
F_63 ( V_73 -> V_74 ,
L_32 ,
V_2 -> V_306 ) ;
F_53 ( V_2 ) ;
F_52 ( V_166 ) ;
return - V_309 ;
}
if ( V_274 )
V_2 -> V_310 = V_311 ;
else
V_2 -> V_310 = V_312 ;
V_152 = F_67 ( V_166 , L_33 ) ;
if ( V_152 < 0 ) {
F_53 ( V_2 ) ;
F_52 ( V_166 ) ;
return V_152 ;
}
V_2 -> V_41 = F_68 ( V_166 , 0 ) ;
V_2 -> V_313 = V_270 >> V_314 ;
if ( F_69 ( V_315 , F_70 ( V_166 ) ,
( V_2 -> V_89 ? 32 : 16 ) * 1024 , & V_2 -> V_85 ) < 0 ) {
V_152 = - V_281 ;
goto error;
}
V_2 -> V_261 = F_71 ( V_2 -> V_313 * sizeof( void * ) ) ;
V_2 -> V_262 = F_71 ( V_2 -> V_313 *
sizeof( unsigned long ) ) ;
if ( V_2 -> V_261 == NULL || V_2 -> V_262 == NULL ) {
V_152 = - V_281 ;
goto error;
}
if ( F_69 ( V_315 , F_70 ( V_166 ) ,
V_316 , & V_2 -> V_36 ) < 0 ) {
V_152 = - V_281 ;
goto error;
}
V_2 -> V_259 = F_72 ( V_2 -> V_313 * V_317 ) ;
if ( V_2 -> V_259 == NULL ) {
V_152 = - V_281 ;
goto error;
}
V_2 -> V_259 -> V_318 = sizeof( struct V_319 ) -
sizeof( struct V_258 ) ;
F_73 ( V_166 ) ;
V_2 -> V_288 . V_320 = 0x303f ;
if ( V_268 == 0 )
V_268 = 0x3fcf ;
if ( V_269 == 0 )
V_269 = 0x7fff ;
V_2 -> V_288 . V_268 = V_268 ;
V_2 -> V_288 . V_269 = V_269 ;
V_2 -> V_34 = V_34 ;
if ( V_2 -> V_65 -> V_321 ) {
V_152 = F_22 ( V_2 ) ;
if ( V_152 < 0 )
goto error;
}
if ( V_2 -> V_65 -> V_322 ) {
V_152 = F_18 ( V_2 ) ;
if ( V_152 < 0 )
goto error;
} else if ( V_2 -> V_65 -> V_94 ) {
V_152 = F_34 ( V_2 ) ;
if ( V_152 < 0 ) {
F_39 ( V_2 ) ;
return V_152 ;
}
} else {
F_2 ( V_2 , V_57 , 0 ,
V_323 | V_324 ) ;
}
V_2 -> V_288 . V_325 = ( 16 * 1024 ) / 2 ;
V_2 -> V_288 . V_326 . V_260 = NULL ;
V_2 -> V_288 . V_326 . V_327 = 0 ;
if ( F_74 ( V_166 -> V_256 , V_328 , V_329 ,
V_330 , V_2 ) ) {
V_152 = - V_331 ;
goto error;
}
V_2 -> V_256 = V_166 -> V_256 ;
V_2 -> V_62 [ 0 ] = V_2 -> V_62 [ 1 ] =
V_2 -> V_62 [ 2 ] = V_332 | V_333 |
V_334 | V_335 |
V_336 | 0x00001200 |
0x00000000 | V_337 | V_338 ;
V_2 -> V_257 = (struct V_319 * )
F_75 ( V_2 , 4096 ) ;
if ( V_2 -> V_257 )
V_2 -> V_257 -> V_339 = 1 ;
memset ( V_2 -> V_36 . V_260 , 0 , V_317 ) ;
V_36 = V_2 -> V_36 . V_86 << V_2 -> V_89 ;
for ( V_273 = 0 ; V_273 < ( V_2 -> V_89 ? V_340 : V_341 ) ; V_273 ++ )
( ( T_1 * ) V_2 -> V_85 . V_260 ) [ V_273 ] = F_76 ( V_36 | V_273 ) ;
for ( V_273 = 0 ; V_273 < V_60 ; V_273 ++ ) {
V_2 -> V_342 [ V_273 ] . V_2 = V_2 ;
V_2 -> V_342 [ V_273 ] . V_343 = V_273 ;
}
V_152 = F_3 ( V_2 , V_34 , 0 ) ;
if ( V_152 < 0 )
goto error;
#ifdef F_30
V_152 = F_77 ( V_2 ) ;
if ( V_152 < 0 )
goto error;
#endif
V_152 = F_78 ( V_2 ) ;
if ( V_152 < 0 )
goto error;
F_13 ( V_2 ) ;
V_152 = F_79 ( V_73 , V_344 , V_2 , & V_278 ) ;
if ( V_152 < 0 )
goto error;
#ifdef F_80
F_81 ( V_2 ) ;
#endif
* V_272 = V_2 ;
return 0 ;
error:
F_39 ( V_2 ) ;
return V_152 ;
}
static int F_77 ( struct V_1 * V_2 )
{
int V_77 ;
V_77 = F_9 ( V_345 ) ;
if ( V_2 -> V_30 )
V_77 += F_9 ( V_346 ) ;
V_2 -> V_347 = F_71 ( 4 * V_60 * V_77 ) ;
if ( ! V_2 -> V_347 )
return - V_281 ;
if ( F_82 ( V_2 ) < 0 )
return - V_281 ;
if ( V_2 -> V_65 -> V_66 &&
F_83 ( V_2 ) < 0 )
return - V_281 ;
return 0 ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_48 ( V_2 -> V_347 ) ;
F_84 ( V_2 ) ;
if ( V_2 -> V_65 -> V_66 )
F_85 ( V_2 ) ;
}
void F_86 ( struct V_1 * V_2 )
{
int V_145 ;
unsigned char * V_104 ;
unsigned int * V_348 ;
V_348 = V_2 -> V_347 ;
for ( V_104 = V_345 ; * V_104 != 0xff ; V_104 ++ )
for ( V_145 = 0 ; V_145 < V_60 ; V_145 ++ , V_348 ++ )
* V_348 = F_5 ( V_2 , * V_104 , V_145 ) ;
if ( V_2 -> V_30 ) {
for ( V_104 = V_346 ; * V_104 != 0xff ; V_104 ++ )
for ( V_145 = 0 ; V_145 < V_60 ; V_145 ++ , V_348 ++ )
* V_348 = F_5 ( V_2 , * V_104 , V_145 ) ;
}
if ( V_2 -> V_30 )
V_2 -> V_349 = F_8 ( V_2 -> V_41 + V_75 ) ;
V_2 -> V_350 = F_8 ( V_2 -> V_41 + V_42 ) ;
}
void F_87 ( struct V_1 * V_2 )
{
if ( V_2 -> V_65 -> V_321 )
F_22 ( V_2 ) ;
if ( V_2 -> V_65 -> V_322 )
F_18 ( V_2 ) ;
else if ( V_2 -> V_65 -> V_94 )
F_34 ( V_2 ) ;
else
F_2 ( V_2 , V_57 , 0 , V_323 | V_324 ) ;
F_3 ( V_2 , V_2 -> V_34 , 1 ) ;
}
void F_88 ( struct V_1 * V_2 )
{
int V_145 ;
unsigned char * V_104 ;
unsigned int * V_348 ;
F_13 ( V_2 ) ;
if ( V_2 -> V_30 )
F_4 ( V_2 -> V_349 , V_2 -> V_41 + V_75 ) ;
F_4 ( V_2 -> V_350 , V_2 -> V_41 + V_42 ) ;
V_348 = V_2 -> V_347 ;
for ( V_104 = V_345 ; * V_104 != 0xff ; V_104 ++ )
for ( V_145 = 0 ; V_145 < V_60 ; V_145 ++ , V_348 ++ )
F_2 ( V_2 , * V_104 , V_145 , * V_348 ) ;
if ( V_2 -> V_30 ) {
for ( V_104 = V_346 ; * V_104 != 0xff ; V_104 ++ )
for ( V_145 = 0 ; V_145 < V_60 ; V_145 ++ , V_348 ++ )
F_2 ( V_2 , * V_104 , V_145 , * V_348 ) ;
}
}

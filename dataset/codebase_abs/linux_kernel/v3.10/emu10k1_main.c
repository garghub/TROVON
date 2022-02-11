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
F_7 ( V_73 L_1 ) ;
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
V_37 = F_8 ( V_2 -> V_41 + V_74 ) & ~ 0x8 ;
F_4 ( V_37 , V_2 -> V_41 + V_74 ) ;
}
if ( V_2 -> V_65 -> V_75 ) {
int V_76 , V_77 ;
V_76 = F_9 ( V_78 ) ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ )
F_10 ( V_2 , V_78 [ V_77 ] ) ;
F_6 ( V_2 , 0x60 , 0 , 0x10 ) ;
F_4 ( 0x76 , V_2 -> V_41 + V_74 ) ;
}
if ( V_2 -> V_65 -> V_79 ) {
int V_76 , V_77 ;
F_6 ( V_2 , V_80 , 0 , 0x2020205f ) ;
V_37 = F_8 ( V_2 -> V_41 + V_74 ) ;
F_4 ( V_37 | 0x4 , V_2 -> V_41 + V_74 ) ;
V_37 = F_8 ( V_2 -> V_41 + V_74 ) ;
V_76 = F_9 ( V_81 ) ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ )
F_11 ( V_2 , V_81 [ V_77 ] [ 0 ] , V_81 [ V_77 ] [ 1 ] ) ;
for ( V_77 = 0 ; V_77 < 4 ; V_77 ++ ) {
V_2 -> V_82 [ V_77 ] [ 0 ] = 0xcf ;
V_2 -> V_82 [ V_77 ] [ 1 ] = 0xcf ;
}
}
F_2 ( V_2 , V_83 , 0 , V_2 -> V_84 . V_85 ) ;
F_2 ( V_2 , V_86 , 0 , 0 ) ;
F_2 ( V_2 , V_87 , 0 , 4 ) ;
V_36 = ( V_2 -> V_36 . V_85 << 1 ) | V_88 ;
for ( V_3 = 0 ; V_3 < V_60 ; V_3 ++ ) {
F_2 ( V_2 , V_89 , V_3 , V_36 ) ;
F_2 ( V_2 , V_90 , V_3 , V_36 ) ;
}
if ( V_2 -> V_65 -> V_91 ) {
F_4 ( V_92 |
V_93 |
V_94 , V_2 -> V_41 + V_42 ) ;
} else if ( V_2 -> V_30 ) {
if ( V_2 -> V_95 == 4 )
F_4 ( V_94 |
V_96 |
V_97 |
V_98 | V_99 , V_2 -> V_41 + V_42 ) ;
else
F_4 ( V_98 | V_99 , V_2 -> V_41 + V_42 ) ;
} else if ( V_2 -> V_100 == 0x20 ||
V_2 -> V_100 == 0xc400 ||
( V_2 -> V_100 == 0x21 && V_2 -> V_95 < 6 ) )
F_4 ( V_39 | V_98 , V_2 -> V_41 + V_42 ) ;
else
F_4 ( V_39 | V_98 | V_99 , V_2 -> V_41 + V_42 ) ;
if ( V_34 ) {
if ( V_2 -> V_65 -> V_91 ) {
;
} else if ( V_2 -> V_65 -> V_79 ) {
;
} else if ( V_2 -> V_30 ) {
unsigned int V_101 = F_8 ( V_2 -> V_41 + V_74 ) ;
F_4 ( V_101 | V_102 , V_2 -> V_41 + V_74 ) ;
F_12 ( 500 ) ;
F_4 ( V_101 | V_103 | V_102 , V_2 -> V_41 + V_74 ) ;
F_12 ( 100 ) ;
F_4 ( V_101 , V_2 -> V_41 + V_74 ) ;
} else {
unsigned int V_101 = F_8 ( V_2 -> V_41 + V_42 ) ;
F_4 ( V_101 | V_104 , V_2 -> V_41 + V_42 ) ;
F_12 ( 500 ) ;
F_4 ( V_101 | V_105 | V_104 , V_2 -> V_41 + V_42 ) ;
F_12 ( 100 ) ;
F_4 ( V_101 , V_2 -> V_41 + V_42 ) ;
}
}
if ( V_2 -> V_65 -> V_91 ) {
;
} else if ( V_2 -> V_65 -> V_79 ) {
;
} else if ( V_2 -> V_30 ) {
unsigned int V_101 = F_8 ( V_2 -> V_41 + V_74 ) ;
F_4 ( V_101 | V_106 , V_2 -> V_41 + V_74 ) ;
}
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_4 ( F_8 ( V_2 -> V_41 + V_42 ) | V_94 , V_2 -> V_41 + V_42 ) ;
if ( V_2 -> V_65 -> V_91 ) {
;
} else if ( V_2 -> V_65 -> V_79 ) {
;
} else if ( V_2 -> V_30 ) {
F_4 ( F_8 ( V_2 -> V_41 + V_74 ) & ~ 0x44 , V_2 -> V_41 + V_74 ) ;
if ( V_2 -> V_65 -> V_66 ) {
F_4 ( F_8 ( V_2 -> V_41 + V_74 ) | 0x0040 , V_2 -> V_41 + V_74 ) ;
} else if ( V_2 -> V_65 -> V_72 ) {
F_4 ( F_8 ( V_2 -> V_41 + V_74 ) | 0x0060 , V_2 -> V_41 + V_74 ) ;
} else {
F_4 ( F_8 ( V_2 -> V_41 + V_74 ) | 0x0080 , V_2 -> V_41 + V_74 ) ;
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
F_14 ( V_2 , V_107 ) ;
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
F_2 ( V_2 , V_108 , 0 , 0 ) ;
F_2 ( V_2 , V_48 , 0 , V_44 ) ;
F_2 ( V_2 , V_49 , 0 , 0 ) ;
F_2 ( V_2 , V_87 , 0 , V_109 ) ;
F_2 ( V_2 , V_86 , 0 , 0 ) ;
if ( V_2 -> V_30 )
F_2 ( V_2 , V_110 , 0 , V_111 ) ;
else
F_2 ( V_2 , V_112 , 0 , V_113 ) ;
F_2 ( V_2 , V_51 , 0 , 0 ) ;
F_2 ( V_2 , V_52 , 0 , 0 ) ;
F_2 ( V_2 , V_53 , 0 , 0 ) ;
F_2 ( V_2 , V_54 , 0 , 0 ) ;
F_4 ( V_38 | V_39 | V_40 , V_2 -> V_41 + V_42 ) ;
F_2 ( V_2 , V_83 , 0 , 0 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 , unsigned int V_114 )
{
unsigned short V_115 ;
unsigned int V_116 ;
unsigned long V_117 ;
unsigned int V_118 ;
V_117 = V_2 -> V_41 + V_42 ;
V_118 = F_8 ( V_117 ) & ~ ( V_119 | V_120 | V_121 ) ;
F_4 ( V_118 , V_117 ) ;
for ( V_115 = 0 ; V_115 < V_122 ; V_115 ++ ) {
V_116 = ( ( V_114 & 0x1 ) ? V_121 : 0 ) ;
V_114 >>= 1 ;
F_4 ( V_118 | V_116 , V_117 ) ;
F_4 ( V_118 | V_116 | V_120 , V_117 ) ;
F_4 ( V_118 | V_116 , V_117 ) ;
}
F_4 ( V_118 | V_119 , V_117 ) ;
F_4 ( V_118 , V_117 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
unsigned short V_123 )
{
unsigned int V_124 ;
F_16 ( V_2 , V_2 -> V_125 & ~ V_126 ) ;
F_16 ( V_2 , V_2 -> V_125 & ~ V_126 ) ;
for ( V_124 = ( 1 << 15 ) ; V_124 ; V_124 >>= 1 ) {
unsigned int V_114 ;
V_114 = V_2 -> V_125 & ~ ( V_126 | V_127 ) ;
if ( V_123 & V_124 )
V_114 |= V_127 ;
F_16 ( V_2 , V_114 ) ;
F_16 ( V_2 , V_114 | V_128 ) ;
F_16 ( V_2 , V_114 ) ;
}
F_16 ( V_2 , V_2 -> V_125 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
unsigned int V_118 ;
V_2 -> V_125 = V_129 |
F_19 ( V_130 ) |
F_20 ( V_131 ) ;
V_118 = F_8 ( V_2 -> V_41 + V_42 ) ;
F_4 ( V_118 | V_94 | V_132 , V_2 -> V_41 + V_42 ) ;
F_8 ( V_2 -> V_41 + V_42 ) ;
F_16 ( V_2 , V_133 | V_134 | V_126 ) ;
F_16 ( V_2 , V_135 | V_134 | V_126 ) ;
F_21 ( V_2 , 48000 ) ;
F_16 ( V_2 , V_133 | V_134 | V_126 ) ;
F_16 ( V_2 , V_2 -> V_125 ) ;
F_17 ( V_2 , V_136 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
unsigned long V_137 ;
unsigned int V_114 ;
V_137 = V_2 -> V_41 + 0x38 ;
V_114 = F_8 ( V_137 ) ;
F_4 ( 0x00d00000 , V_137 ) ;
V_114 = F_8 ( V_137 ) ;
F_4 ( 0x00d00001 , V_137 ) ;
V_114 = F_8 ( V_137 ) ;
F_4 ( 0x00d0005f , V_137 ) ;
V_114 = F_8 ( V_137 ) ;
F_4 ( 0x00d0007f , V_137 ) ;
V_114 = F_8 ( V_137 ) ;
F_4 ( 0x0090007f , V_137 ) ;
V_114 = F_8 ( V_137 ) ;
F_6 ( V_2 , V_138 , 0 , 0xfefefefe ) ;
F_23 ( 200 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
const struct V_139 * V_140 )
{
int V_77 , V_141 ;
int V_101 ;
int V_114 ;
unsigned int V_142 ;
unsigned long V_143 ;
if ( ! V_140 )
return - V_144 ;
F_25 ( & V_2 -> V_145 , V_143 ) ;
F_4 ( 0x00 , V_2 -> V_41 + V_74 ) ;
V_142 = F_8 ( V_2 -> V_41 + V_74 ) ;
F_12 ( 100 ) ;
F_4 ( 0x80 , V_2 -> V_41 + V_74 ) ;
V_142 = F_8 ( V_2 -> V_41 + V_74 ) ;
F_12 ( 100 ) ;
for ( V_77 = 0 ; V_77 < V_140 -> V_76 ; V_77 ++ ) {
V_114 = V_140 -> V_116 [ V_77 ] ;
for ( V_141 = 0 ; V_141 < 8 ; V_141 ++ ) {
V_101 = 0x80 ;
if ( V_114 & 0x1 )
V_101 = V_101 | 0x20 ;
V_114 = V_114 >> 1 ;
F_4 ( V_101 , V_2 -> V_41 + V_74 ) ;
V_142 = F_8 ( V_2 -> V_41 + V_74 ) ;
F_4 ( V_101 | 0x40 , V_2 -> V_41 + V_74 ) ;
V_142 = F_8 ( V_2 -> V_41 + V_74 ) ;
}
}
F_4 ( 0x10 , V_2 -> V_41 + V_74 ) ;
V_142 = F_8 ( V_2 -> V_41 + V_74 ) ;
F_26 ( & V_2 -> V_145 , V_143 ) ;
return 0 ;
}
static int F_27 ( void * V_116 )
{
struct V_1 * V_2 = V_116 ;
T_1 V_37 , V_146 , V_101 ;
int V_147 ;
for (; ; ) {
F_28 ( 1000 ) ;
if ( F_29 () )
break;
#ifdef F_30
if ( V_2 -> V_148 )
continue;
#endif
F_31 ( V_2 , V_149 , & V_37 ) ;
F_31 ( V_2 , V_150 , & V_101 ) ;
if ( V_101 & V_151 ) {
F_7 ( V_73 L_2 ) ;
F_32 ( V_2 , V_152 , V_153 ) ;
if ( ! V_2 -> V_154 ) {
const char * V_155 = NULL ;
switch ( V_2 -> V_65 -> V_91 ) {
case V_156 :
V_155 = V_157 ;
break;
case V_158 :
V_155 = V_159 ;
break;
case V_160 :
V_155 = V_159 ;
break;
}
if ( V_155 ) {
V_147 = F_33 ( & V_2 -> V_154 ,
V_155 ,
& V_2 -> V_161 -> V_162 ) ;
if ( V_147 )
continue;
}
}
if ( V_2 -> V_154 ) {
V_147 = F_24 ( V_2 , V_2 -> V_154 ) ;
if ( V_147 )
continue;
}
F_32 ( V_2 , V_152 , 0 ) ;
F_31 ( V_2 , V_149 , & V_101 ) ;
F_7 ( V_73 L_3 , V_101 ) ;
F_31 ( V_2 , V_163 , & V_101 ) ;
F_7 ( V_73 L_4 , V_101 ) ;
if ( ( V_101 & 0x1f ) != 0x15 ) {
F_7 ( V_73 L_5 , V_101 ) ;
continue;
}
F_7 ( V_73 L_6 ) ;
F_31 ( V_2 , V_164 , & V_37 ) ;
F_31 ( V_2 , V_165 , & V_146 ) ;
F_7 ( V_73 L_7 ,
V_37 , V_146 ) ;
F_23 ( 10 ) ;
F_32 ( V_2 , V_166 , V_167 ) ;
}
}
F_7 ( V_73 L_8 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
unsigned int V_141 ;
T_1 V_37 , V_146 , V_101 ;
int V_147 ;
F_7 ( V_73 L_9 ) ;
F_4 ( 0x0005a00c , V_2 -> V_41 + V_42 ) ;
F_4 ( 0x0005a004 , V_2 -> V_41 + V_42 ) ;
F_4 ( 0x0005a000 , V_2 -> V_41 + V_42 ) ;
F_4 ( 0x0005a000 , V_2 -> V_41 + V_42 ) ;
F_32 ( V_2 , V_168 , 0 ) ;
F_31 ( V_2 , V_163 , & V_101 ) ;
F_35 ( L_10 , V_101 ) ;
if ( ( V_101 & 0x3f ) == 0x15 ) {
F_32 ( V_2 , V_152 , 0x02 ) ;
}
F_31 ( V_2 , V_163 , & V_101 ) ;
F_35 ( L_11 , V_101 ) ;
if ( ( V_101 & 0x3f ) == 0x15 ) {
F_7 ( V_73 L_12 ) ;
return - V_169 ;
}
F_7 ( V_73 L_13 , V_101 ) ;
if ( ! V_2 -> V_139 ) {
const char * V_155 ;
switch ( V_2 -> V_65 -> V_91 ) {
case V_156 :
V_155 = V_170 ;
break;
case V_158 :
V_155 = V_171 ;
break;
case V_160 :
V_155 = V_172 ;
break;
case V_173 :
V_155 = V_174 ;
break;
default:
return - V_169 ;
}
V_147 = F_33 ( & V_2 -> V_139 , V_155 , & V_2 -> V_161 -> V_162 ) ;
if ( V_147 != 0 ) {
F_7 ( V_175 L_14 , V_155 , V_147 ) ;
return V_147 ;
}
F_7 ( V_73 L_15 ,
V_155 , V_2 -> V_139 -> V_76 ) ;
}
V_147 = F_24 ( V_2 , V_2 -> V_139 ) ;
if ( V_147 != 0 ) {
F_7 ( V_73 L_16 ) ;
return V_147 ;
}
F_31 ( V_2 , V_163 , & V_101 ) ;
if ( ( V_101 & 0x3f ) != 0x15 ) {
F_7 ( V_73 L_17 , V_101 ) ;
return - V_169 ;
}
F_7 ( V_73 L_18 ) ;
F_31 ( V_2 , V_176 , & V_37 ) ;
F_31 ( V_2 , V_177 , & V_146 ) ;
F_7 ( V_73 L_19 , V_37 , V_146 ) ;
F_32 ( V_2 , V_168 , V_178 ) ;
F_31 ( V_2 , V_150 , & V_101 ) ;
F_7 ( V_73 L_20 , V_101 ) ;
F_31 ( V_2 , V_150 , & V_101 ) ;
F_7 ( V_73 L_20 , V_101 ) ;
F_31 ( V_2 , V_179 , & V_37 ) ;
V_2 -> V_180 . V_181 = 1 ;
V_2 -> V_180 . V_182 = 1 ;
V_37 = 0 ;
V_37 = ( V_2 -> V_180 . V_181 ? V_183 : 0 ) |
( V_2 -> V_180 . V_182 ? V_184 : 0 ) ;
F_32 ( V_2 , V_179 , V_37 ) ;
F_31 ( V_2 , V_185 , & V_37 ) ;
F_32 ( V_2 , V_185 , 0x00 ) ;
V_2 -> V_180 . V_186 = 0x00 ;
F_31 ( V_2 , V_187 , & V_37 ) ;
F_32 ( V_2 , V_187 , 0x30 ) ;
F_32 ( V_2 , V_188 , 0x12 ) ;
F_31 ( V_2 , V_189 , & V_37 ) ;
F_32 ( V_2 , V_189 , 0x0f ) ;
V_2 -> V_180 . V_190 = 0x0f ;
F_31 ( V_2 , V_187 , & V_37 ) ;
F_32 ( V_2 , V_187 , 0x30 ) ;
F_31 ( V_2 , V_191 , & V_37 ) ;
F_32 ( V_2 , V_191 , 0x10 ) ;
F_32 ( V_2 , V_192 , 0x19 ) ;
F_32 ( V_2 , V_193 , 0x0c ) ;
F_32 ( V_2 , V_194 , 0x00 ) ;
F_31 ( V_2 , V_150 , & V_101 ) ;
F_7 ( V_73 L_21 , V_101 ) ;
F_32 ( V_2 , V_195 , 0x00 ) ;
F_32 ( V_2 , V_196 , V_197 ) ;
F_32 ( V_2 , V_188 , 0x12 ) ;
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
V_198 , V_199 ) ;
F_36 ( V_2 ,
V_200 , V_201 ) ;
F_36 ( V_2 ,
V_202 , V_203 ) ;
F_36 ( V_2 ,
V_204 , V_203 ) ;
F_36 ( V_2 ,
V_205 , V_206 ) ;
F_36 ( V_2 ,
V_207 , V_208 ) ;
F_36 ( V_2 ,
V_209 , V_210 ) ;
F_36 ( V_2 ,
V_211 , V_212 ) ;
F_36 ( V_2 ,
V_213 , V_199 ) ;
F_36 ( V_2 ,
V_214 , V_201 ) ;
F_36 ( V_2 ,
V_215 , V_203 ) ;
F_36 ( V_2 ,
V_216 , V_203 ) ;
F_36 ( V_2 ,
V_217 , V_206 ) ;
F_36 ( V_2 ,
V_218 , V_208 ) ;
F_36 ( V_2 ,
V_219 , V_210 ) ;
F_36 ( V_2 ,
V_220 , V_212 ) ;
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
for ( V_141 = 0 ; V_141 < 0x20 ; V_141 ++ ) {
F_36 ( V_2 , 0x0100 + V_141 , V_221 ) ;
}
for ( V_141 = 0 ; V_141 < 4 ; V_141 ++ ) {
F_36 ( V_2 , 0x0200 + V_141 , V_221 ) ;
}
for ( V_141 = 0 ; V_141 < 7 ; V_141 ++ ) {
F_36 ( V_2 , 0x0300 + V_141 , V_221 ) ;
}
for ( V_141 = 0 ; V_141 < 7 ; V_141 ++ ) {
F_36 ( V_2 , V_222 + V_141 , V_221 ) ;
}
F_36 ( V_2 ,
V_223 , V_206 ) ;
F_36 ( V_2 ,
V_224 , V_208 ) ;
F_36 ( V_2 ,
V_225 , V_210 ) ;
F_36 ( V_2 ,
V_226 , V_212 ) ;
F_36 ( V_2 ,
V_227 , V_228 ) ;
F_36 ( V_2 ,
V_229 , V_230 ) ;
F_32 ( V_2 , V_166 , 0x01 ) ;
F_31 ( V_2 , V_150 , & V_37 ) ;
F_4 ( 0x0000a000 , V_2 -> V_41 + V_42 ) ;
F_4 ( 0x0000a001 , V_2 -> V_41 + V_42 ) ;
F_31 ( V_2 , V_150 , & V_37 ) ;
F_32 ( V_2 , V_192 , 0x19 ) ;
F_32 ( V_2 , V_193 , 0x0c ) ;
F_32 ( V_2 , V_192 , 0x19 ) ;
F_32 ( V_2 , V_193 , 0x0c ) ;
F_31 ( V_2 , V_191 , & V_37 ) ;
F_32 ( V_2 , V_191 , 0x10 ) ;
if ( ! V_2 -> V_180 . V_231 ) {
V_2 -> V_180 . V_231 =
F_37 ( F_27 , V_2 ,
L_22 ) ;
F_38 ( V_2 -> V_180 . V_231 ) ;
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
if ( V_2 -> V_65 -> V_91 == V_160 ) {
F_36 ( V_2 ,
V_232 , V_233 + 0 ) ;
V_2 -> V_180 . V_234 [ 0 ] = 17 ;
F_36 ( V_2 ,
V_235 , V_233 + 1 ) ;
V_2 -> V_180 . V_234 [ 1 ] = 18 ;
F_36 ( V_2 ,
V_236 , V_233 + 2 ) ;
V_2 -> V_180 . V_234 [ 2 ] = 19 ;
F_36 ( V_2 ,
V_237 , V_233 + 3 ) ;
V_2 -> V_180 . V_234 [ 3 ] = 20 ;
F_36 ( V_2 ,
V_238 , V_233 + 4 ) ;
V_2 -> V_180 . V_234 [ 4 ] = 21 ;
F_36 ( V_2 ,
V_239 , V_233 + 5 ) ;
V_2 -> V_180 . V_234 [ 5 ] = 22 ;
F_36 ( V_2 ,
V_240 , V_233 + 0 ) ;
V_2 -> V_180 . V_234 [ 16 ] = 17 ;
F_36 ( V_2 ,
V_241 , V_233 + 1 ) ;
V_2 -> V_180 . V_234 [ 17 ] = 18 ;
} else {
F_36 ( V_2 ,
V_232 , V_233 + 0 ) ;
V_2 -> V_180 . V_234 [ 0 ] = 21 ;
F_36 ( V_2 ,
V_235 , V_233 + 1 ) ;
V_2 -> V_180 . V_234 [ 1 ] = 22 ;
F_36 ( V_2 ,
V_236 , V_233 + 2 ) ;
V_2 -> V_180 . V_234 [ 2 ] = 23 ;
F_36 ( V_2 ,
V_237 , V_233 + 3 ) ;
V_2 -> V_180 . V_234 [ 3 ] = 24 ;
F_36 ( V_2 ,
V_238 , V_233 + 4 ) ;
V_2 -> V_180 . V_234 [ 4 ] = 25 ;
F_36 ( V_2 ,
V_239 , V_233 + 5 ) ;
V_2 -> V_180 . V_234 [ 5 ] = 26 ;
F_36 ( V_2 ,
V_242 , V_233 + 6 ) ;
V_2 -> V_180 . V_234 [ 6 ] = 27 ;
F_36 ( V_2 ,
V_243 , V_233 + 7 ) ;
V_2 -> V_180 . V_234 [ 7 ] = 28 ;
F_36 ( V_2 ,
V_244 , V_233 + 0 ) ;
V_2 -> V_180 . V_234 [ 8 ] = 21 ;
F_36 ( V_2 ,
V_245 , V_233 + 1 ) ;
V_2 -> V_180 . V_234 [ 9 ] = 22 ;
F_36 ( V_2 ,
V_246 , V_233 + 0 ) ;
V_2 -> V_180 . V_234 [ 10 ] = 21 ;
F_36 ( V_2 ,
V_247 , V_233 + 1 ) ;
V_2 -> V_180 . V_234 [ 11 ] = 22 ;
F_36 ( V_2 ,
V_248 , V_233 + 0 ) ;
V_2 -> V_180 . V_234 [ 12 ] = 21 ;
F_36 ( V_2 ,
V_249 , V_233 + 1 ) ;
V_2 -> V_180 . V_234 [ 13 ] = 22 ;
F_36 ( V_2 ,
V_250 , V_233 + 0 ) ;
V_2 -> V_180 . V_234 [ 14 ] = 21 ;
F_36 ( V_2 ,
V_251 , V_233 + 1 ) ;
V_2 -> V_180 . V_234 [ 15 ] = 22 ;
F_36 ( V_2 ,
V_222 , V_233 + 0 ) ;
V_2 -> V_180 . V_234 [ 16 ] = 21 ;
F_36 ( V_2 ,
V_222 + 1 , V_233 + 1 ) ;
V_2 -> V_180 . V_234 [ 17 ] = 22 ;
F_36 ( V_2 ,
V_222 + 2 , V_233 + 2 ) ;
V_2 -> V_180 . V_234 [ 18 ] = 23 ;
F_36 ( V_2 ,
V_222 + 3 , V_233 + 3 ) ;
V_2 -> V_180 . V_234 [ 19 ] = 24 ;
F_36 ( V_2 ,
V_222 + 4 , V_233 + 4 ) ;
V_2 -> V_180 . V_234 [ 20 ] = 25 ;
F_36 ( V_2 ,
V_222 + 5 , V_233 + 5 ) ;
V_2 -> V_180 . V_234 [ 21 ] = 26 ;
F_36 ( V_2 ,
V_222 + 6 , V_233 + 6 ) ;
V_2 -> V_180 . V_234 [ 22 ] = 27 ;
F_36 ( V_2 ,
V_222 + 7 , V_233 + 7 ) ;
V_2 -> V_180 . V_234 [ 23 ] = 28 ;
}
F_32 ( V_2 , V_166 , 0x0 ) ;
F_32 ( V_2 , V_195 , 0x0 ) ;
F_32 ( V_2 , V_196 , V_197 ) ;
V_2 -> V_180 . V_252 = 1 ;
F_32 ( V_2 , V_188 , 0x12 ) ;
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
if ( V_2 -> V_65 -> V_91 == V_156 ) {
F_32 ( V_2 , V_168 , 0 ) ;
}
if ( V_2 -> V_180 . V_231 )
F_42 ( V_2 -> V_180 . V_231 ) ;
if ( V_2 -> V_139 )
F_43 ( V_2 -> V_139 ) ;
if ( V_2 -> V_154 )
F_43 ( V_2 -> V_154 ) ;
if ( V_2 -> V_253 >= 0 )
F_44 ( V_2 -> V_253 , V_2 ) ;
if ( V_2 -> V_254 ) {
F_45 ( V_2 ,
(struct V_255 * ) V_2 -> V_254 ) ;
V_2 -> V_254 = NULL ;
}
if ( V_2 -> V_256 )
F_46 ( V_2 -> V_256 ) ;
if ( V_2 -> V_36 . V_257 )
F_47 ( & V_2 -> V_36 ) ;
if ( V_2 -> V_84 . V_257 )
F_47 ( & V_2 -> V_84 ) ;
F_48 ( V_2 -> V_258 ) ;
F_48 ( V_2 -> V_259 ) ;
#ifdef F_30
F_49 ( V_2 ) ;
#endif
if ( V_2 -> V_41 )
F_50 ( V_2 -> V_161 ) ;
if ( V_2 -> V_65 -> V_66 )
F_51 ( V_2 ) ;
F_52 ( V_2 -> V_161 ) ;
F_53 ( V_2 ) ;
return 0 ;
}
static int F_54 ( struct V_260 * V_261 )
{
struct V_1 * V_2 = V_261 -> V_262 ;
return F_39 ( V_2 ) ;
}
int F_55 ( struct V_263 * V_264 ,
struct V_265 * V_161 ,
unsigned short V_266 ,
unsigned short V_267 ,
long V_268 ,
int V_34 ,
T_2 V_269 ,
struct V_1 * * V_270 )
{
struct V_1 * V_2 ;
int V_271 , V_147 ;
int V_272 ;
unsigned int V_36 ;
const struct V_273 * V_274 ;
static struct V_275 V_276 = {
. V_277 = F_54 ,
} ;
* V_270 = NULL ;
V_147 = F_56 ( V_161 ) ;
if ( V_147 < 0 )
return V_147 ;
V_2 = F_57 ( sizeof( * V_2 ) , V_278 ) ;
if ( V_2 == NULL ) {
F_52 ( V_161 ) ;
return - V_279 ;
}
V_2 -> V_264 = V_264 ;
F_58 ( & V_2 -> V_280 ) ;
F_58 ( & V_2 -> V_145 ) ;
F_58 ( & V_2 -> V_281 ) ;
F_58 ( & V_2 -> V_282 ) ;
F_58 ( & V_2 -> V_283 ) ;
F_58 ( & V_2 -> V_284 ) ;
F_58 ( & V_2 -> V_285 ) ;
F_59 ( & V_2 -> V_286 . V_287 ) ;
F_60 ( & V_2 -> V_288 ) ;
F_60 ( & V_2 -> V_289 ) ;
V_2 -> V_161 = V_161 ;
V_2 -> V_253 = - 1 ;
V_2 -> V_290 = NULL ;
V_2 -> V_291 = NULL ;
V_2 -> V_95 = V_161 -> V_95 ;
F_61 ( V_161 , V_292 , & V_2 -> V_293 ) ;
F_62 ( V_161 , V_294 , & V_2 -> V_100 ) ;
F_35 ( L_23 , V_161 -> V_295 , V_161 -> V_261 , V_2 -> V_293 , V_2 -> V_100 ) ;
for ( V_274 = V_296 ; V_274 -> V_295 ; V_274 ++ ) {
if ( V_274 -> V_295 == V_161 -> V_295 && V_274 -> V_261 == V_161 -> V_261 ) {
if ( V_269 ) {
if ( V_274 -> V_269 && ( V_274 -> V_269 == V_269 ) )
break;
else
continue;
} else {
if ( V_274 -> V_269 && ( V_274 -> V_269 != V_2 -> V_293 ) )
continue;
if ( V_274 -> V_95 && V_274 -> V_95 != V_2 -> V_95 )
continue;
}
break;
}
}
if ( V_274 -> V_295 == 0 ) {
F_7 ( V_175 L_24 ) ;
F_53 ( V_2 ) ;
F_52 ( V_161 ) ;
return - V_297 ;
}
V_2 -> V_65 = V_274 ;
if ( V_274 -> V_269 && ! V_269 )
F_35 ( L_25 , V_274 -> V_298 ) ;
else if ( V_269 )
F_35 ( L_26
L_27
L_28 , V_274 -> V_298 ,
V_161 -> V_295 , V_161 -> V_261 , V_2 -> V_293 , V_274 -> V_269 ) ;
else
F_35 ( L_26
L_29 ,
V_274 -> V_298 , V_161 -> V_295 , V_161 -> V_261 ,
V_2 -> V_293 ) ;
if ( ! * V_264 -> V_299 && V_274 -> V_299 ) {
int V_141 , V_77 = 0 ;
F_63 ( V_264 -> V_299 , V_274 -> V_299 , sizeof( V_264 -> V_299 ) ) ;
for (; ; ) {
for ( V_141 = 0 ; V_141 < V_300 ; V_141 ++ ) {
if ( V_301 [ V_141 ] && ! strcmp ( V_301 [ V_141 ] -> V_299 , V_264 -> V_299 ) )
break;
}
if ( V_141 >= V_300 )
break;
V_77 ++ ;
if ( V_77 >= V_302 )
break;
snprintf ( V_264 -> V_299 , sizeof( V_264 -> V_299 ) , L_30 , V_274 -> V_299 , V_77 ) ;
}
}
V_272 = V_2 -> V_30 = V_274 -> V_303 ;
V_2 -> V_304 = V_272 ? V_305 : V_306 ;
if ( F_64 ( V_161 , V_2 -> V_304 ) < 0 ||
F_65 ( V_161 , V_2 -> V_304 ) < 0 ) {
F_7 ( V_175 L_31 , V_2 -> V_304 ) ;
F_53 ( V_2 ) ;
F_52 ( V_161 ) ;
return - V_307 ;
}
if ( V_272 )
V_2 -> V_308 = V_309 ;
else
V_2 -> V_308 = V_310 ;
V_147 = F_66 ( V_161 , L_32 ) ;
if ( V_147 < 0 ) {
F_53 ( V_2 ) ;
F_52 ( V_161 ) ;
return V_147 ;
}
V_2 -> V_41 = F_67 ( V_161 , 0 ) ;
V_2 -> V_311 = V_268 >> V_312 ;
if ( F_68 ( V_313 , F_69 ( V_161 ) ,
32 * 1024 , & V_2 -> V_84 ) < 0 ) {
V_147 = - V_279 ;
goto error;
}
V_2 -> V_258 = F_70 ( V_2 -> V_311 * sizeof( void * ) ) ;
V_2 -> V_259 = F_70 ( V_2 -> V_311 *
sizeof( unsigned long ) ) ;
if ( V_2 -> V_258 == NULL || V_2 -> V_259 == NULL ) {
V_147 = - V_279 ;
goto error;
}
if ( F_68 ( V_313 , F_69 ( V_161 ) ,
V_314 , & V_2 -> V_36 ) < 0 ) {
V_147 = - V_279 ;
goto error;
}
V_2 -> V_256 = F_71 ( V_2 -> V_311 * V_315 ) ;
if ( V_2 -> V_256 == NULL ) {
V_147 = - V_279 ;
goto error;
}
V_2 -> V_256 -> V_316 = sizeof( struct V_317 ) -
sizeof( struct V_255 ) ;
F_72 ( V_161 ) ;
V_2 -> V_286 . V_318 = 0x303f ;
if ( V_266 == 0 )
V_266 = 0x3fcf ;
if ( V_267 == 0 )
V_267 = 0x7fff ;
V_2 -> V_286 . V_266 = V_266 ;
V_2 -> V_286 . V_267 = V_267 ;
V_2 -> V_34 = V_34 ;
if ( V_2 -> V_65 -> V_319 ) {
V_147 = F_22 ( V_2 ) ;
if ( V_147 < 0 )
goto error;
}
if ( V_2 -> V_65 -> V_320 ) {
V_147 = F_18 ( V_2 ) ;
if ( V_147 < 0 )
goto error;
} else if ( V_2 -> V_65 -> V_91 ) {
V_147 = F_34 ( V_2 ) ;
if ( V_147 < 0 ) {
F_39 ( V_2 ) ;
return V_147 ;
}
} else {
F_2 ( V_2 , V_57 , 0 ,
V_321 | V_322 ) ;
}
V_2 -> V_286 . V_323 = ( 16 * 1024 ) / 2 ;
V_2 -> V_286 . V_324 . V_257 = NULL ;
V_2 -> V_286 . V_324 . V_325 = 0 ;
if ( F_73 ( V_161 -> V_253 , V_326 , V_327 ,
V_328 , V_2 ) ) {
V_147 = - V_329 ;
goto error;
}
V_2 -> V_253 = V_161 -> V_253 ;
V_2 -> V_62 [ 0 ] = V_2 -> V_62 [ 1 ] =
V_2 -> V_62 [ 2 ] = V_330 | V_331 |
V_332 | V_333 |
V_334 | 0x00001200 |
0x00000000 | V_335 | V_336 ;
V_2 -> V_254 = (struct V_317 * )
F_74 ( V_2 , 4096 ) ;
if ( V_2 -> V_254 )
V_2 -> V_254 -> V_337 = 1 ;
memset ( V_2 -> V_36 . V_257 , 0 , V_315 ) ;
V_36 = V_2 -> V_36 . V_85 << 1 ;
for ( V_271 = 0 ; V_271 < V_338 ; V_271 ++ )
( ( T_1 * ) V_2 -> V_84 . V_257 ) [ V_271 ] = F_75 ( V_36 | V_271 ) ;
for ( V_271 = 0 ; V_271 < V_60 ; V_271 ++ ) {
V_2 -> V_339 [ V_271 ] . V_2 = V_2 ;
V_2 -> V_339 [ V_271 ] . V_340 = V_271 ;
}
V_147 = F_3 ( V_2 , V_34 , 0 ) ;
if ( V_147 < 0 )
goto error;
#ifdef F_30
V_147 = F_76 ( V_2 ) ;
if ( V_147 < 0 )
goto error;
#endif
V_147 = F_77 ( V_2 ) ;
if ( V_147 < 0 )
goto error;
F_13 ( V_2 ) ;
V_147 = F_78 ( V_264 , V_341 , V_2 , & V_276 ) ;
if ( V_147 < 0 )
goto error;
#ifdef F_79
F_80 ( V_2 ) ;
#endif
F_81 ( V_264 , & V_161 -> V_162 ) ;
* V_270 = V_2 ;
return 0 ;
error:
F_39 ( V_2 ) ;
return V_147 ;
}
static int F_76 ( struct V_1 * V_2 )
{
int V_76 ;
V_76 = F_9 ( V_342 ) ;
if ( V_2 -> V_30 )
V_76 += F_9 ( V_343 ) ;
V_2 -> V_344 = F_70 ( 4 * V_60 * V_76 ) ;
if ( ! V_2 -> V_344 )
return - V_279 ;
if ( F_82 ( V_2 ) < 0 )
return - V_279 ;
if ( V_2 -> V_65 -> V_66 &&
F_83 ( V_2 ) < 0 )
return - V_279 ;
return 0 ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_48 ( V_2 -> V_344 ) ;
F_84 ( V_2 ) ;
if ( V_2 -> V_65 -> V_66 )
F_85 ( V_2 ) ;
}
void F_86 ( struct V_1 * V_2 )
{
int V_141 ;
unsigned char * V_101 ;
unsigned int * V_345 ;
V_345 = V_2 -> V_344 ;
for ( V_101 = V_342 ; * V_101 != 0xff ; V_101 ++ )
for ( V_141 = 0 ; V_141 < V_60 ; V_141 ++ , V_345 ++ )
* V_345 = F_5 ( V_2 , * V_101 , V_141 ) ;
if ( V_2 -> V_30 ) {
for ( V_101 = V_343 ; * V_101 != 0xff ; V_101 ++ )
for ( V_141 = 0 ; V_141 < V_60 ; V_141 ++ , V_345 ++ )
* V_345 = F_5 ( V_2 , * V_101 , V_141 ) ;
}
if ( V_2 -> V_30 )
V_2 -> V_346 = F_8 ( V_2 -> V_41 + V_74 ) ;
V_2 -> V_347 = F_8 ( V_2 -> V_41 + V_42 ) ;
}
void F_87 ( struct V_1 * V_2 )
{
if ( V_2 -> V_65 -> V_319 )
F_22 ( V_2 ) ;
if ( V_2 -> V_65 -> V_320 )
F_18 ( V_2 ) ;
else if ( V_2 -> V_65 -> V_91 )
F_34 ( V_2 ) ;
else
F_2 ( V_2 , V_57 , 0 , V_321 | V_322 ) ;
F_3 ( V_2 , V_2 -> V_34 , 1 ) ;
}
void F_88 ( struct V_1 * V_2 )
{
int V_141 ;
unsigned char * V_101 ;
unsigned int * V_345 ;
F_13 ( V_2 ) ;
if ( V_2 -> V_30 )
F_4 ( V_2 -> V_346 , V_2 -> V_41 + V_74 ) ;
F_4 ( V_2 -> V_347 , V_2 -> V_41 + V_42 ) ;
V_345 = V_2 -> V_344 ;
for ( V_101 = V_342 ; * V_101 != 0xff ; V_101 ++ )
for ( V_141 = 0 ; V_141 < V_60 ; V_141 ++ , V_345 ++ )
F_2 ( V_2 , * V_101 , V_141 , * V_345 ) ;
if ( V_2 -> V_30 ) {
for ( V_101 = V_343 ; * V_101 != 0xff ; V_101 ++ )
for ( V_141 = 0 ; V_141 < V_60 ; V_141 ++ , V_345 ++ )
F_2 ( V_2 , * V_101 , V_141 , * V_345 ) ;
}
}

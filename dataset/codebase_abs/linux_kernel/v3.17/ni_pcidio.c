static inline unsigned F_1 ( unsigned V_1 )
{
return V_1 & 0x3 ;
}
static inline unsigned F_2 ( unsigned V_1 )
{
return ( V_1 << 2 ) & 0xc ;
}
static int F_3 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
unsigned long V_7 ;
F_4 ( & V_5 -> V_8 , V_7 ) ;
F_5 ( V_5 -> V_9 ) ;
V_5 -> V_9 =
F_6 ( V_5 -> V_10 ,
V_5 -> V_11 , 1 , 2 ) ;
if ( V_5 -> V_9 == NULL ) {
F_7 ( & V_5 -> V_8 , V_7 ) ;
F_8 ( V_3 -> V_12 , L_1 ) ;
return - V_13 ;
}
V_5 -> V_9 -> V_14 = V_15 ;
F_9 ( F_1 ( V_5 -> V_9 -> V_1 ) |
F_2 ( V_5 -> V_9 -> V_1 ) ,
V_3 -> V_16 + V_17 ) ;
F_10 () ;
F_7 ( & V_5 -> V_8 , V_7 ) ;
return 0 ;
}
static void F_11 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
unsigned long V_7 ;
F_4 ( & V_5 -> V_8 , V_7 ) ;
if ( V_5 -> V_9 ) {
F_12 ( V_5 -> V_9 ) ;
F_13 ( V_5 -> V_9 ) ;
F_14 ( V_5 -> V_9 ) ;
V_5 -> V_9 = NULL ;
F_9 ( F_1 ( 0 ) |
F_2 ( 0 ) ,
V_3 -> V_16 + V_17 ) ;
F_10 () ;
}
F_7 ( & V_5 -> V_8 , V_7 ) ;
}
static int F_15 ( struct V_2 * V_3 , struct V_18 * V_19 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
int V_20 ;
unsigned long V_7 ;
V_20 = F_3 ( V_3 ) ;
if ( V_20 )
return V_20 ;
F_16 ( V_19 , V_19 -> V_21 -> V_22 ) ;
F_4 ( & V_5 -> V_8 , V_7 ) ;
if ( V_5 -> V_9 ) {
F_17 ( V_5 -> V_9 , 32 , 32 ) ;
F_18 ( V_5 -> V_9 ) ;
} else
V_20 = - V_23 ;
F_7 ( & V_5 -> V_8 , V_7 ) ;
return V_20 ;
}
static int F_19 ( struct V_2 * V_3 , struct V_18 * V_19 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
unsigned long V_24 ;
int V_25 ;
F_4 ( & V_3 -> V_26 , V_24 ) ;
F_20 ( & V_5 -> V_8 ) ;
if ( V_5 -> V_9 )
F_21 ( V_5 -> V_9 , V_19 ) ;
F_22 ( & V_5 -> V_8 ) ;
V_25 = F_23 ( V_19 ) ;
F_7 ( & V_3 -> V_26 , V_24 ) ;
return V_25 ;
}
static T_1 F_24 ( int V_27 , void * V_28 )
{
struct V_2 * V_3 = V_28 ;
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_18 * V_19 = V_3 -> V_29 ;
struct V_30 * V_21 = V_19 -> V_21 ;
struct V_31 * V_10 = V_5 -> V_10 ;
unsigned int V_32 = 0 ;
unsigned short V_33 = 0 ;
unsigned short V_34 = 0 ;
int V_7 ;
int V_35 ;
int V_36 = 0 ;
unsigned int V_37 = 0 ;
if ( ! V_3 -> V_38 ) {
return V_39 ;
}
F_20 ( & V_3 -> V_26 ) ;
V_35 = F_25 ( V_3 -> V_16 + V_40 ) ;
V_7 = F_25 ( V_3 -> V_16 + V_41 ) ;
F_20 ( & V_5 -> V_8 ) ;
if ( V_5 -> V_9 )
V_37 = F_26 ( V_5 -> V_9 ) ;
if ( V_37 & V_42 ) {
if ( V_37 & V_43 ) {
F_27 ( V_44 ,
V_10 -> V_45 +
F_28 ( V_5 -> V_9 -> V_1 ) ) ;
F_21 ( V_5 -> V_9 , V_19 ) ;
}
if ( V_37 & ~ ( V_42 | V_43 | V_46 | V_47 |
V_48 | V_49 ) ) {
F_29 ( V_3 -> V_12 ,
L_2 ) ;
V_21 -> V_50 |= V_51 | V_52 ;
F_30 ( V_3 -> V_27 ) ;
}
}
F_22 ( & V_5 -> V_8 ) ;
while ( V_35 & V_53 ) {
V_36 ++ ;
if ( V_36 > 20 ) {
F_29 ( V_3 -> V_12 , L_3 ) ;
F_9 ( 0x00 ,
V_3 -> V_16 + V_54 ) ;
break;
}
V_7 &= V_55 ;
if ( V_7 & V_56 ) {
while ( V_7 & V_56 ) {
V_36 ++ ;
if ( V_36 > 100 ) {
F_29 ( V_3 -> V_12 ,
L_3 ) ;
F_9 ( 0x00 , V_3 -> V_16 +
V_54
) ;
goto V_57;
}
V_32 = F_31 ( V_3 -> V_16 + V_58 ) ;
V_33 = V_32 & 0xffff ;
V_34 = ( V_32 & 0xffff0000 ) >> 16 ;
F_32 ( V_19 , V_33 ) ;
F_32 ( V_19 , V_34 ) ;
V_7 = F_25 ( V_3 -> V_16 + V_41 ) ;
}
V_21 -> V_50 |= V_59 ;
}
if ( V_7 & V_60 ) {
F_9 ( V_61 , V_3 -> V_16 + V_62 ) ;
V_21 -> V_50 |= V_51 ;
F_9 ( 0x00 , V_3 -> V_16 + V_63 ) ;
break;
} else if ( V_7 & V_64 ) {
F_9 ( V_65 , V_3 -> V_16 + V_66 ) ;
V_21 -> V_50 |= V_51 | V_52 ;
break;
} else if ( V_7 & V_67 ) {
F_9 ( V_68 ,
V_3 -> V_16 + V_66 ) ;
V_21 -> V_50 |= V_51 ;
} else if ( V_7 & V_69 ) {
F_9 ( V_70 ,
V_3 -> V_16 + V_66 ) ;
V_21 -> V_50 |= V_51 ;
}
V_7 = F_25 ( V_3 -> V_16 + V_41 ) ;
V_35 = F_25 ( V_3 -> V_16 + V_40 ) ;
}
V_57:
F_33 ( V_3 , V_19 ) ;
#if 0
if (!tag)
writeb(0x03, dev->mmio + Master_DMA_And_Interrupt_Control);
#endif
F_22 ( & V_3 -> V_26 ) ;
return V_71 ;
}
static int F_34 ( struct V_2 * V_3 ,
struct V_18 * V_19 ,
struct V_72 * V_73 ,
unsigned int * V_74 )
{
int V_75 ;
V_75 = F_35 ( V_3 , V_19 , V_73 , V_74 , 0 ) ;
if ( V_75 )
return V_75 ;
F_27 ( V_19 -> V_76 , V_3 -> V_16 + F_36 ( 0 ) ) ;
return V_73 -> V_77 ;
}
static int F_37 ( struct V_2 * V_3 ,
struct V_18 * V_19 ,
struct V_72 * V_73 ,
unsigned int * V_74 )
{
if ( F_38 ( V_19 , V_74 ) )
F_27 ( V_19 -> V_78 , V_3 -> V_16 + F_39 ( 0 ) ) ;
V_74 [ 1 ] = F_31 ( V_3 -> V_16 + F_39 ( 0 ) ) ;
return V_73 -> V_77 ;
}
static int F_40 ( int * V_79 , unsigned int V_7 )
{
int V_80 , V_81 ;
V_81 = V_82 ;
switch ( V_7 & V_83 ) {
case V_84 :
default:
V_80 = ( * V_79 + V_81 / 2 ) / V_81 ;
break;
case V_85 :
V_80 = ( * V_79 ) / V_81 ;
break;
case V_86 :
V_80 = ( * V_79 + V_81 - 1 ) / V_81 ;
break;
}
* V_79 = V_81 * V_80 ;
return V_80 ;
}
static int F_41 ( struct V_2 * V_3 ,
struct V_18 * V_19 , struct V_87 * V_88 )
{
int V_89 = 0 ;
unsigned int V_90 ;
V_89 |= F_42 ( & V_88 -> V_91 , V_92 | V_93 ) ;
V_89 |= F_42 ( & V_88 -> V_94 ,
V_95 | V_96 ) ;
V_89 |= F_42 ( & V_88 -> V_97 , V_92 ) ;
V_89 |= F_42 ( & V_88 -> V_98 , V_99 ) ;
V_89 |= F_42 ( & V_88 -> V_100 , V_99 | V_101 ) ;
if ( V_89 )
return 1 ;
V_89 |= F_43 ( V_88 -> V_91 ) ;
V_89 |= F_43 ( V_88 -> V_94 ) ;
V_89 |= F_43 ( V_88 -> V_100 ) ;
if ( V_89 )
return 2 ;
V_89 |= F_44 ( & V_88 -> V_102 , 0 ) ;
#define F_45 (TIMER_BASE)
if ( V_88 -> V_94 == V_95 ) {
V_89 |= F_46 ( & V_88 -> V_103 ,
F_45 ) ;
} else {
if ( ( V_88 -> V_103 & ~ ( V_104 | V_105 ) ) != 0 ) {
V_88 -> V_103 &= ( V_104 | V_105 ) ;
V_89 |= - V_106 ;
}
}
V_89 |= F_44 ( & V_88 -> V_107 , 0 ) ;
V_89 |= F_44 ( & V_88 -> V_108 , V_88 -> V_109 ) ;
if ( V_88 -> V_100 == V_99 ) {
} else {
V_89 |= F_44 ( & V_88 -> V_110 , 0 ) ;
}
if ( V_89 )
return 3 ;
if ( V_88 -> V_94 == V_95 ) {
V_90 = V_88 -> V_103 ;
F_40 ( & V_90 , V_88 -> V_7 ) ;
V_89 |= F_44 ( & V_88 -> V_103 , V_90 ) ;
}
if ( V_89 )
return 4 ;
return 0 ;
}
static int F_47 ( struct V_2 * V_3 ,
struct V_18 * V_19 ,
unsigned int V_111 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_87 * V_88 = & V_19 -> V_21 -> V_88 ;
if ( V_111 != V_88 -> V_102 )
return - V_106 ;
F_9 ( V_5 -> V_112 , V_3 -> V_16 + V_63 ) ;
V_19 -> V_21 -> V_113 = NULL ;
return 1 ;
}
static int F_48 ( struct V_2 * V_3 , struct V_18 * V_19 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_87 * V_88 = & V_19 -> V_21 -> V_88 ;
F_27 ( 0x0000 , V_3 -> V_16 + F_36 ( 0 ) ) ;
if ( 1 ) {
F_9 ( 0x0f , V_3 -> V_16 + V_114 ) ;
F_9 ( F_49 ( 0 ) | F_50 ( 0 ) ,
V_3 -> V_16 + V_115 ) ;
} else {
F_9 ( 0x03 , V_3 -> V_16 + V_114 ) ;
F_9 ( F_49 ( 3 ) | F_50 ( 0 ) ,
V_3 -> V_16 + V_115 ) ;
}
if ( V_88 -> V_94 == V_95 ) {
F_9 ( 0 , V_3 -> V_16 + V_63 ) ;
F_9 ( 0x00 , V_3 -> V_16 + V_116 ) ;
F_9 ( 1 , V_3 -> V_16 + V_117 ) ;
F_9 ( 0x04 , V_3 -> V_16 + V_118 ) ;
F_9 ( 4 , V_3 -> V_16 + V_119 ) ;
F_9 ( 3 , V_3 -> V_16 + V_120 ) ;
F_9 ( 0xc0 , V_3 -> V_16 + V_121 ) ;
F_27 ( F_40 ( & V_88 -> V_103 ,
V_84 ) ,
V_3 -> V_16 + V_122 ) ;
F_9 ( 1 , V_3 -> V_16 + V_123 ) ;
F_9 ( 1 , V_3 -> V_16 + V_124 ) ;
F_9 ( 1 , V_3 -> V_16 + V_125 ) ;
F_9 ( 0x0b , V_3 -> V_16 + V_126 ) ;
F_9 ( 0x01 , V_3 -> V_16 + V_127 ) ;
F_51 ( 0 , V_3 -> V_16 + V_128 ) ;
F_9 ( 0 , V_3 -> V_16 + V_129 ) ;
} else {
F_9 ( 0 , V_3 -> V_16 + V_63 ) ;
F_9 ( 0x00 , V_3 -> V_16 + V_116 ) ;
F_9 ( 0 , V_3 -> V_16 + V_117 ) ;
F_9 ( 0x00 , V_3 -> V_16 + V_118 ) ;
F_9 ( 4 , V_3 -> V_16 + V_119 ) ;
if ( ! ( V_88 -> V_103 & V_105 ) )
F_9 ( 0 , V_3 -> V_16 + V_120 ) ;
else
F_9 ( 2 , V_3 -> V_16 + V_120 ) ;
F_9 ( 0x00 , V_3 -> V_16 + V_121 ) ;
F_27 ( 1 , V_3 -> V_16 + V_122 ) ;
F_9 ( 1 , V_3 -> V_16 + V_123 ) ;
F_9 ( 1 , V_3 -> V_16 + V_124 ) ;
F_9 ( 1 , V_3 -> V_16 + V_125 ) ;
F_9 ( 0x0C , V_3 -> V_16 + V_126 ) ;
F_9 ( 0x10 , V_3 -> V_16 + V_127 ) ;
F_51 ( 0 , V_3 -> V_16 + V_128 ) ;
F_9 ( 0x60 , V_3 -> V_16 + V_129 ) ;
}
if ( V_88 -> V_100 == V_99 ) {
F_27 ( V_88 -> V_110 ,
V_3 -> V_16 + V_130 ) ;
} else {
}
#ifdef F_52
F_9 ( V_68 | V_70 ,
V_3 -> V_16 + V_66 ) ;
{
int V_20 = F_15 ( V_3 , V_19 ) ;
if ( V_20 )
return V_20 ;
}
#else
F_9 ( 0x00 , V_3 -> V_16 + V_17 ) ;
#endif
F_9 ( 0x00 , V_3 -> V_16 + V_131 ) ;
F_9 ( 0xff , V_3 -> V_16 + V_66 ) ;
F_9 ( V_55 , V_3 -> V_16 + V_132 ) ;
F_9 ( 0x03 , V_3 -> V_16 + V_54 ) ;
if ( V_88 -> V_100 == V_101 ) {
V_5 -> V_112 = F_53 ( 0 ) | F_54 ( 7 ) ;
} else {
V_5 -> V_112 = V_133 | F_54 ( 7 ) ;
}
if ( V_88 -> V_91 == V_92 ) {
F_9 ( V_5 -> V_112 , V_3 -> V_16 + V_63 ) ;
V_19 -> V_21 -> V_113 = NULL ;
} else {
V_19 -> V_21 -> V_113 = F_47 ;
}
return 0 ;
}
static int F_55 ( struct V_2 * V_3 ,
struct V_18 * V_19 )
{
F_9 ( 0x00 , V_3 -> V_16 + V_54 ) ;
F_11 ( V_3 ) ;
return 0 ;
}
static int F_56 ( struct V_2 * V_3 ,
struct V_18 * V_19 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
int V_75 ;
V_75 = F_57 ( V_5 -> V_11 , V_19 ) ;
if ( V_75 < 0 )
return V_75 ;
memset ( V_19 -> V_21 -> V_134 , 0xaa , V_19 -> V_21 -> V_22 ) ;
return 0 ;
}
static int F_58 ( struct V_2 * V_3 ,
const T_2 * V_74 , T_3 V_135 ,
unsigned long V_136 )
{
static const int V_137 = 1000 ;
int V_138 = V_136 ;
int V_139 ;
T_3 V_140 ;
F_51 ( 0x80 | V_138 , V_3 -> V_16 + V_141 ) ;
F_51 ( 0xc0 | V_138 , V_3 -> V_16 + V_141 ) ;
for ( V_139 = 0 ;
( F_59 ( V_3 -> V_16 + V_142 ) & 0x2 ) == 0 &&
V_139 < V_137 ; ++ V_139 ) {
F_60 ( 1 ) ;
}
if ( V_139 == V_137 ) {
F_61 ( V_3 -> V_12 ,
L_4 ,
V_138 ) ;
return - V_23 ;
}
F_51 ( 0x80 | V_138 , V_3 -> V_16 + V_141 ) ;
for ( V_139 = 0 ;
F_59 ( V_3 -> V_16 + V_142 ) != 0x3 &&
V_139 < V_137 ; ++ V_139 ) {
F_60 ( 1 ) ;
}
if ( V_139 == V_137 ) {
F_61 ( V_3 -> V_12 ,
L_5 ,
V_138 ) ;
return - V_23 ;
}
for ( V_140 = 0 ; V_140 + 1 < V_135 ; ) {
unsigned int V_143 = V_74 [ V_140 ++ ] ;
V_143 |= V_74 [ V_140 ++ ] << 8 ;
F_51 ( V_143 , V_3 -> V_16 + V_144 ) ;
for ( V_139 = 0 ;
( F_59 ( V_3 -> V_16 + V_142 ) & 0x2 ) == 0
&& V_139 < V_137 ; ++ V_139 ) {
F_60 ( 1 ) ;
}
if ( V_139 == V_137 ) {
F_61 ( V_3 -> V_12 ,
L_6 ,
V_138 ) ;
return - V_23 ;
}
if ( F_62 () )
F_63 () ;
}
F_51 ( 0x0 , V_3 -> V_16 + V_141 ) ;
return 0 ;
}
static int F_64 ( struct V_2 * V_3 , int V_138 )
{
return F_58 ( V_3 , NULL , 0 , V_138 ) ;
}
static int F_65 ( struct V_2 * V_3 )
{
int V_75 ;
int V_139 ;
F_51 ( 0x0 , V_3 -> V_16 + V_141 ) ;
for ( V_139 = 0 ; V_139 < 3 ; ++ V_139 ) {
V_75 = F_64 ( V_3 , V_139 ) ;
if ( V_75 < 0 )
break;
}
F_51 ( 0x0 , V_3 -> V_16 + V_145 ) ;
return V_75 ;
}
static void F_66 ( struct V_2 * V_3 )
{
F_27 ( 0 , V_3 -> V_16 + V_146 ) ;
F_27 ( 0 , V_3 -> V_16 + V_147 ) ;
F_27 ( 0 , V_3 -> V_16 + V_148 ) ;
F_27 ( 0 , V_3 -> V_16 + V_149 ) ;
F_27 ( 0 , V_3 -> V_16 + V_150 ) ;
F_27 ( 0 , V_3 -> V_16 + V_151 ) ;
}
static int F_67 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
static const char * const V_152 [ 3 ] = {
V_153 ,
V_154 ,
V_155 ,
} ;
int V_75 ;
int V_77 ;
V_75 = F_65 ( V_3 ) ;
if ( V_75 < 0 )
return V_75 ;
for ( V_77 = 2 ; V_77 >= 0 ; V_77 -- ) {
V_75 = F_68 ( V_3 , & V_5 -> V_10 -> V_156 -> V_3 ,
V_152 [ V_77 ] ,
F_58 , V_77 ) ;
if ( V_75 == 0 && V_77 == 2 )
F_66 ( V_3 ) ;
if ( V_75 < 0 )
break;
}
return V_75 ;
}
static void F_69 ( struct V_2 * V_3 )
{
F_27 ( 0 , V_3 -> V_16 + F_39 ( 0 ) ) ;
F_27 ( 0 , V_3 -> V_16 + F_36 ( 0 ) ) ;
F_27 ( 0 , V_3 -> V_16 + F_70 ( 0 ) ) ;
F_9 ( 0 , V_3 -> V_16 + V_54 ) ;
}
static int F_71 ( struct V_2 * V_3 ,
unsigned long V_136 )
{
struct V_157 * V_156 = F_72 ( V_3 ) ;
const struct V_158 * V_159 = NULL ;
struct V_4 * V_5 ;
struct V_18 * V_19 ;
int V_75 ;
unsigned int V_27 ;
if ( V_136 < F_73 ( V_160 ) )
V_159 = & V_160 [ V_136 ] ;
if ( ! V_159 )
return - V_161 ;
V_3 -> V_162 = V_159 ;
V_3 -> V_163 = V_159 -> V_164 ;
V_75 = F_74 ( V_3 ) ;
if ( V_75 )
return V_75 ;
V_5 = F_75 ( V_3 , sizeof( * V_5 ) ) ;
if ( ! V_5 )
return - V_165 ;
F_76 ( & V_5 -> V_8 ) ;
V_5 -> V_10 = F_77 ( V_156 ) ;
if ( ! V_5 -> V_10 )
return - V_165 ;
V_75 = F_78 ( V_3 , V_5 -> V_10 ) ;
if ( V_75 < 0 )
return V_75 ;
V_5 -> V_11 = F_79 ( V_5 -> V_10 ) ;
if ( V_5 -> V_11 == NULL )
return - V_165 ;
if ( V_159 -> V_166 ) {
V_75 = F_67 ( V_3 ) ;
if ( V_75 < 0 )
return V_75 ;
}
F_69 ( V_3 ) ;
V_75 = F_80 ( V_3 , 1 ) ;
if ( V_75 )
return V_75 ;
F_81 ( V_3 -> V_12 , L_7 , V_3 -> V_163 ,
F_25 ( V_3 -> V_16 + V_167 ) ) ;
V_19 = & V_3 -> V_168 [ 0 ] ;
V_3 -> V_29 = V_19 ;
V_19 -> type = V_169 ;
V_19 -> V_170 =
V_171 | V_172 | V_173 | V_174 |
V_175 ;
V_19 -> V_176 = 32 ;
V_19 -> V_177 = & V_178 ;
V_19 -> V_179 = 1 ;
V_19 -> V_180 = & F_34 ;
V_19 -> V_181 = & F_37 ;
V_19 -> V_182 = & F_48 ;
V_19 -> V_183 = & F_41 ;
V_19 -> V_184 = & F_55 ;
V_19 -> V_185 = 32 ;
V_19 -> V_186 = & F_56 ;
V_19 -> V_187 = V_188 ;
V_19 -> V_189 = & F_19 ;
V_27 = V_156 -> V_27 ;
if ( V_27 ) {
V_75 = F_82 ( V_27 , F_24 , V_190 ,
V_3 -> V_163 , V_3 ) ;
if ( V_75 == 0 )
V_3 -> V_27 = V_27 ;
}
return 0 ;
}
static void F_83 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
if ( V_3 -> V_27 )
F_84 ( V_3 -> V_27 , V_3 ) ;
if ( V_5 ) {
if ( V_5 -> V_11 ) {
F_85 ( V_5 -> V_11 ) ;
V_5 -> V_11 = NULL ;
}
F_86 ( V_5 -> V_10 ) ;
}
if ( V_3 -> V_16 )
F_87 ( V_3 -> V_16 ) ;
F_88 ( V_3 ) ;
}
static int F_89 ( struct V_157 * V_3 ,
const struct V_191 * V_192 )
{
return F_90 ( V_3 , & V_193 , V_192 -> V_194 ) ;
}

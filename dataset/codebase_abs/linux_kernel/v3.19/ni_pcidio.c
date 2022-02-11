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
unsigned int V_32 ;
int V_7 ;
int V_33 ;
int V_34 = 0 ;
unsigned int V_35 = 0 ;
if ( ! V_3 -> V_36 ) {
return V_37 ;
}
F_20 ( & V_3 -> V_26 ) ;
V_33 = F_25 ( V_3 -> V_16 + V_38 ) ;
V_7 = F_25 ( V_3 -> V_16 + V_39 ) ;
F_20 ( & V_5 -> V_8 ) ;
if ( V_5 -> V_9 )
V_35 = F_26 ( V_5 -> V_9 ) ;
if ( V_35 & V_40 ) {
if ( V_35 & V_41 ) {
F_27 ( V_42 ,
V_10 -> V_43 +
F_28 ( V_5 -> V_9 -> V_1 ) ) ;
F_21 ( V_5 -> V_9 , V_19 ) ;
}
if ( V_35 & ~ ( V_40 | V_41 | V_44 | V_45 |
V_46 | V_47 ) ) {
F_29 ( V_3 -> V_12 ,
L_2 ) ;
V_21 -> V_48 |= V_49 | V_50 ;
F_30 ( V_3 -> V_27 ) ;
}
}
F_22 ( & V_5 -> V_8 ) ;
while ( V_33 & V_51 ) {
V_34 ++ ;
if ( V_34 > 20 ) {
F_29 ( V_3 -> V_12 , L_3 ) ;
F_9 ( 0x00 ,
V_3 -> V_16 + V_52 ) ;
break;
}
V_7 &= V_53 ;
if ( V_7 & V_54 ) {
while ( V_7 & V_54 ) {
V_34 ++ ;
if ( V_34 > 100 ) {
F_29 ( V_3 -> V_12 ,
L_3 ) ;
F_9 ( 0x00 , V_3 -> V_16 +
V_52
) ;
goto V_55;
}
V_32 = F_31 ( V_3 -> V_16 + V_56 ) ;
F_32 ( V_19 , & V_32 , 1 ) ;
V_7 = F_25 ( V_3 -> V_16 + V_39 ) ;
}
}
if ( V_7 & V_57 ) {
F_9 ( V_58 , V_3 -> V_16 + V_59 ) ;
V_21 -> V_48 |= V_49 ;
F_9 ( 0x00 , V_3 -> V_16 + V_60 ) ;
break;
} else if ( V_7 & V_61 ) {
F_9 ( V_62 , V_3 -> V_16 + V_63 ) ;
V_21 -> V_48 |= V_49 | V_50 ;
break;
} else if ( V_7 & V_64 ) {
F_9 ( V_65 ,
V_3 -> V_16 + V_63 ) ;
V_21 -> V_48 |= V_49 ;
} else if ( V_7 & V_66 ) {
F_9 ( V_67 ,
V_3 -> V_16 + V_63 ) ;
V_21 -> V_48 |= V_49 ;
}
V_7 = F_25 ( V_3 -> V_16 + V_39 ) ;
V_33 = F_25 ( V_3 -> V_16 + V_38 ) ;
}
V_55:
F_33 ( V_3 , V_19 ) ;
#if 0
if (!tag)
writeb(0x03, dev->mmio + Master_DMA_And_Interrupt_Control);
#endif
F_22 ( & V_3 -> V_26 ) ;
return V_68 ;
}
static int F_34 ( struct V_2 * V_3 ,
struct V_18 * V_19 ,
struct V_69 * V_70 ,
unsigned int * V_71 )
{
int V_72 ;
V_72 = F_35 ( V_3 , V_19 , V_70 , V_71 , 0 ) ;
if ( V_72 )
return V_72 ;
F_27 ( V_19 -> V_73 , V_3 -> V_16 + F_36 ( 0 ) ) ;
return V_70 -> V_74 ;
}
static int F_37 ( struct V_2 * V_3 ,
struct V_18 * V_19 ,
struct V_69 * V_70 ,
unsigned int * V_71 )
{
if ( F_38 ( V_19 , V_71 ) )
F_27 ( V_19 -> V_75 , V_3 -> V_16 + F_39 ( 0 ) ) ;
V_71 [ 1 ] = F_31 ( V_3 -> V_16 + F_39 ( 0 ) ) ;
return V_70 -> V_74 ;
}
static int F_40 ( int * V_76 , unsigned int V_7 )
{
int V_77 , V_78 ;
V_78 = V_79 ;
switch ( V_7 & V_80 ) {
case V_81 :
default:
V_77 = ( * V_76 + V_78 / 2 ) / V_78 ;
break;
case V_82 :
V_77 = ( * V_76 ) / V_78 ;
break;
case V_83 :
V_77 = ( * V_76 + V_78 - 1 ) / V_78 ;
break;
}
* V_76 = V_78 * V_77 ;
return V_77 ;
}
static int F_41 ( struct V_2 * V_3 ,
struct V_18 * V_19 , struct V_84 * V_85 )
{
int V_86 = 0 ;
unsigned int V_87 ;
V_86 |= F_42 ( & V_85 -> V_88 , V_89 | V_90 ) ;
V_86 |= F_42 ( & V_85 -> V_91 ,
V_92 | V_93 ) ;
V_86 |= F_42 ( & V_85 -> V_94 , V_89 ) ;
V_86 |= F_42 ( & V_85 -> V_95 , V_96 ) ;
V_86 |= F_42 ( & V_85 -> V_97 , V_96 | V_98 ) ;
if ( V_86 )
return 1 ;
V_86 |= F_43 ( V_85 -> V_88 ) ;
V_86 |= F_43 ( V_85 -> V_91 ) ;
V_86 |= F_43 ( V_85 -> V_97 ) ;
if ( V_86 )
return 2 ;
V_86 |= F_44 ( & V_85 -> V_99 , 0 ) ;
#define F_45 (TIMER_BASE)
if ( V_85 -> V_91 == V_92 ) {
V_86 |= F_46 ( & V_85 -> V_100 ,
F_45 ) ;
} else {
if ( ( V_85 -> V_100 & ~ ( V_101 | V_102 ) ) != 0 ) {
V_85 -> V_100 &= ( V_101 | V_102 ) ;
V_86 |= - V_103 ;
}
}
V_86 |= F_44 ( & V_85 -> V_104 , 0 ) ;
V_86 |= F_44 ( & V_85 -> V_105 , V_85 -> V_106 ) ;
if ( V_85 -> V_97 == V_96 )
V_86 |= F_46 ( & V_85 -> V_107 , 1 ) ;
else
V_86 |= F_44 ( & V_85 -> V_107 , 0 ) ;
if ( V_86 )
return 3 ;
if ( V_85 -> V_91 == V_92 ) {
V_87 = V_85 -> V_100 ;
F_40 ( & V_87 , V_85 -> V_7 ) ;
V_86 |= F_44 ( & V_85 -> V_100 , V_87 ) ;
}
if ( V_86 )
return 4 ;
return 0 ;
}
static int F_47 ( struct V_2 * V_3 ,
struct V_18 * V_19 ,
unsigned int V_108 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_84 * V_85 = & V_19 -> V_21 -> V_85 ;
if ( V_108 != V_85 -> V_99 )
return - V_103 ;
F_9 ( V_5 -> V_109 , V_3 -> V_16 + V_60 ) ;
V_19 -> V_21 -> V_110 = NULL ;
return 1 ;
}
static int F_48 ( struct V_2 * V_3 , struct V_18 * V_19 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_84 * V_85 = & V_19 -> V_21 -> V_85 ;
F_27 ( 0x0000 , V_3 -> V_16 + F_36 ( 0 ) ) ;
if ( 1 ) {
F_9 ( 0x0f , V_3 -> V_16 + V_111 ) ;
F_9 ( F_49 ( 0 ) | F_50 ( 0 ) ,
V_3 -> V_16 + V_112 ) ;
} else {
F_9 ( 0x03 , V_3 -> V_16 + V_111 ) ;
F_9 ( F_49 ( 3 ) | F_50 ( 0 ) ,
V_3 -> V_16 + V_112 ) ;
}
if ( V_85 -> V_91 == V_92 ) {
F_9 ( 0 , V_3 -> V_16 + V_60 ) ;
F_9 ( 0x00 , V_3 -> V_16 + V_113 ) ;
F_9 ( 1 , V_3 -> V_16 + V_114 ) ;
F_9 ( 0x04 , V_3 -> V_16 + V_115 ) ;
F_9 ( 4 , V_3 -> V_16 + V_116 ) ;
F_9 ( 3 , V_3 -> V_16 + V_117 ) ;
F_9 ( 0xc0 , V_3 -> V_16 + V_118 ) ;
F_27 ( F_40 ( & V_85 -> V_100 ,
V_81 ) ,
V_3 -> V_16 + V_119 ) ;
F_9 ( 1 , V_3 -> V_16 + V_120 ) ;
F_9 ( 1 , V_3 -> V_16 + V_121 ) ;
F_9 ( 1 , V_3 -> V_16 + V_122 ) ;
F_9 ( 0x0b , V_3 -> V_16 + V_123 ) ;
F_9 ( 0x01 , V_3 -> V_16 + V_124 ) ;
F_51 ( 0 , V_3 -> V_16 + V_125 ) ;
F_9 ( 0 , V_3 -> V_16 + V_126 ) ;
} else {
F_9 ( 0 , V_3 -> V_16 + V_60 ) ;
F_9 ( 0x00 , V_3 -> V_16 + V_113 ) ;
F_9 ( 0 , V_3 -> V_16 + V_114 ) ;
F_9 ( 0x00 , V_3 -> V_16 + V_115 ) ;
F_9 ( 4 , V_3 -> V_16 + V_116 ) ;
if ( ! ( V_85 -> V_100 & V_102 ) )
F_9 ( 0 , V_3 -> V_16 + V_117 ) ;
else
F_9 ( 2 , V_3 -> V_16 + V_117 ) ;
F_9 ( 0x00 , V_3 -> V_16 + V_118 ) ;
F_27 ( 1 , V_3 -> V_16 + V_119 ) ;
F_9 ( 1 , V_3 -> V_16 + V_120 ) ;
F_9 ( 1 , V_3 -> V_16 + V_121 ) ;
F_9 ( 1 , V_3 -> V_16 + V_122 ) ;
F_9 ( 0x0C , V_3 -> V_16 + V_123 ) ;
F_9 ( 0x10 , V_3 -> V_16 + V_124 ) ;
F_51 ( 0 , V_3 -> V_16 + V_125 ) ;
F_9 ( 0x60 , V_3 -> V_16 + V_126 ) ;
}
if ( V_85 -> V_97 == V_96 ) {
F_27 ( V_85 -> V_107 ,
V_3 -> V_16 + V_127 ) ;
} else {
}
#ifdef F_52
F_9 ( V_65 | V_67 ,
V_3 -> V_16 + V_63 ) ;
{
int V_20 = F_15 ( V_3 , V_19 ) ;
if ( V_20 )
return V_20 ;
}
#else
F_9 ( 0x00 , V_3 -> V_16 + V_17 ) ;
#endif
F_9 ( 0x00 , V_3 -> V_16 + V_128 ) ;
F_9 ( 0xff , V_3 -> V_16 + V_63 ) ;
F_9 ( V_53 , V_3 -> V_16 + V_129 ) ;
F_9 ( 0x03 , V_3 -> V_16 + V_52 ) ;
if ( V_85 -> V_97 == V_98 ) {
V_5 -> V_109 = F_53 ( 0 ) | F_54 ( 7 ) ;
} else {
V_5 -> V_109 = V_130 | F_54 ( 7 ) ;
}
if ( V_85 -> V_88 == V_89 ) {
F_9 ( V_5 -> V_109 , V_3 -> V_16 + V_60 ) ;
V_19 -> V_21 -> V_110 = NULL ;
} else {
V_19 -> V_21 -> V_110 = F_47 ;
}
return 0 ;
}
static int F_55 ( struct V_2 * V_3 ,
struct V_18 * V_19 )
{
F_9 ( 0x00 , V_3 -> V_16 + V_52 ) ;
F_11 ( V_3 ) ;
return 0 ;
}
static int F_56 ( struct V_2 * V_3 ,
struct V_18 * V_19 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
int V_72 ;
V_72 = F_57 ( V_5 -> V_11 , V_19 ) ;
if ( V_72 < 0 )
return V_72 ;
memset ( V_19 -> V_21 -> V_131 , 0xaa , V_19 -> V_21 -> V_22 ) ;
return 0 ;
}
static int F_58 ( struct V_2 * V_3 ,
const T_2 * V_71 , T_3 V_132 ,
unsigned long V_133 )
{
static const int V_134 = 1000 ;
int V_135 = V_133 ;
int V_136 ;
T_3 V_137 ;
F_51 ( 0x80 | V_135 , V_3 -> V_16 + V_138 ) ;
F_51 ( 0xc0 | V_135 , V_3 -> V_16 + V_138 ) ;
for ( V_136 = 0 ;
( F_59 ( V_3 -> V_16 + V_139 ) & 0x2 ) == 0 &&
V_136 < V_134 ; ++ V_136 ) {
F_60 ( 1 ) ;
}
if ( V_136 == V_134 ) {
F_61 ( V_3 -> V_12 ,
L_4 ,
V_135 ) ;
return - V_23 ;
}
F_51 ( 0x80 | V_135 , V_3 -> V_16 + V_138 ) ;
for ( V_136 = 0 ;
F_59 ( V_3 -> V_16 + V_139 ) != 0x3 &&
V_136 < V_134 ; ++ V_136 ) {
F_60 ( 1 ) ;
}
if ( V_136 == V_134 ) {
F_61 ( V_3 -> V_12 ,
L_5 ,
V_135 ) ;
return - V_23 ;
}
for ( V_137 = 0 ; V_137 + 1 < V_132 ; ) {
unsigned int V_140 = V_71 [ V_137 ++ ] ;
V_140 |= V_71 [ V_137 ++ ] << 8 ;
F_51 ( V_140 , V_3 -> V_16 + V_141 ) ;
for ( V_136 = 0 ;
( F_59 ( V_3 -> V_16 + V_139 ) & 0x2 ) == 0
&& V_136 < V_134 ; ++ V_136 ) {
F_60 ( 1 ) ;
}
if ( V_136 == V_134 ) {
F_61 ( V_3 -> V_12 ,
L_6 ,
V_135 ) ;
return - V_23 ;
}
if ( F_62 () )
F_63 () ;
}
F_51 ( 0x0 , V_3 -> V_16 + V_138 ) ;
return 0 ;
}
static int F_64 ( struct V_2 * V_3 , int V_135 )
{
return F_58 ( V_3 , NULL , 0 , V_135 ) ;
}
static int F_65 ( struct V_2 * V_3 )
{
int V_72 ;
int V_136 ;
F_51 ( 0x0 , V_3 -> V_16 + V_138 ) ;
for ( V_136 = 0 ; V_136 < 3 ; ++ V_136 ) {
V_72 = F_64 ( V_3 , V_136 ) ;
if ( V_72 < 0 )
break;
}
F_51 ( 0x0 , V_3 -> V_16 + V_142 ) ;
return V_72 ;
}
static void F_66 ( struct V_2 * V_3 )
{
F_27 ( 0 , V_3 -> V_16 + V_143 ) ;
F_27 ( 0 , V_3 -> V_16 + V_144 ) ;
F_27 ( 0 , V_3 -> V_16 + V_145 ) ;
F_27 ( 0 , V_3 -> V_16 + V_146 ) ;
F_27 ( 0 , V_3 -> V_16 + V_147 ) ;
F_27 ( 0 , V_3 -> V_16 + V_148 ) ;
}
static int F_67 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
static const char * const V_149 [ 3 ] = {
V_150 ,
V_151 ,
V_152 ,
} ;
int V_72 ;
int V_74 ;
V_72 = F_65 ( V_3 ) ;
if ( V_72 < 0 )
return V_72 ;
for ( V_74 = 2 ; V_74 >= 0 ; V_74 -- ) {
V_72 = F_68 ( V_3 , & V_5 -> V_10 -> V_153 -> V_3 ,
V_149 [ V_74 ] ,
F_58 , V_74 ) ;
if ( V_72 == 0 && V_74 == 2 )
F_66 ( V_3 ) ;
if ( V_72 < 0 )
break;
}
return V_72 ;
}
static void F_69 ( struct V_2 * V_3 )
{
F_27 ( 0 , V_3 -> V_16 + F_39 ( 0 ) ) ;
F_27 ( 0 , V_3 -> V_16 + F_36 ( 0 ) ) ;
F_27 ( 0 , V_3 -> V_16 + F_70 ( 0 ) ) ;
F_9 ( 0 , V_3 -> V_16 + V_52 ) ;
}
static int F_71 ( struct V_2 * V_3 ,
unsigned long V_133 )
{
struct V_154 * V_153 = F_72 ( V_3 ) ;
const struct V_155 * V_156 = NULL ;
struct V_4 * V_5 ;
struct V_18 * V_19 ;
int V_72 ;
unsigned int V_27 ;
if ( V_133 < F_73 ( V_157 ) )
V_156 = & V_157 [ V_133 ] ;
if ( ! V_156 )
return - V_158 ;
V_3 -> V_159 = V_156 ;
V_3 -> V_160 = V_156 -> V_161 ;
V_72 = F_74 ( V_3 ) ;
if ( V_72 )
return V_72 ;
V_5 = F_75 ( V_3 , sizeof( * V_5 ) ) ;
if ( ! V_5 )
return - V_162 ;
F_76 ( & V_5 -> V_8 ) ;
V_5 -> V_10 = F_77 ( V_153 ) ;
if ( ! V_5 -> V_10 )
return - V_162 ;
V_72 = F_78 ( V_3 , V_5 -> V_10 ) ;
if ( V_72 < 0 )
return V_72 ;
V_5 -> V_11 = F_79 ( V_5 -> V_10 ) ;
if ( V_5 -> V_11 == NULL )
return - V_162 ;
if ( V_156 -> V_163 ) {
V_72 = F_67 ( V_3 ) ;
if ( V_72 < 0 )
return V_72 ;
}
F_69 ( V_3 ) ;
V_72 = F_80 ( V_3 , 1 ) ;
if ( V_72 )
return V_72 ;
F_81 ( V_3 -> V_12 , L_7 , V_3 -> V_160 ,
F_25 ( V_3 -> V_16 + V_164 ) ) ;
V_19 = & V_3 -> V_165 [ 0 ] ;
V_3 -> V_29 = V_19 ;
V_19 -> type = V_166 ;
V_19 -> V_167 =
V_168 | V_169 | V_170 | V_171 |
V_172 ;
V_19 -> V_173 = 32 ;
V_19 -> V_174 = & V_175 ;
V_19 -> V_176 = 1 ;
V_19 -> V_177 = & F_34 ;
V_19 -> V_178 = & F_37 ;
V_19 -> V_179 = & F_48 ;
V_19 -> V_180 = & F_41 ;
V_19 -> V_181 = & F_55 ;
V_19 -> V_182 = 32 ;
V_19 -> V_183 = & F_56 ;
V_19 -> V_184 = V_185 ;
V_19 -> V_186 = & F_19 ;
V_27 = V_153 -> V_27 ;
if ( V_27 ) {
V_72 = F_82 ( V_27 , F_24 , V_187 ,
V_3 -> V_160 , V_3 ) ;
if ( V_72 == 0 )
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
static int F_89 ( struct V_154 * V_3 ,
const struct V_188 * V_189 )
{
return F_90 ( V_3 , & V_190 , V_189 -> V_191 ) ;
}

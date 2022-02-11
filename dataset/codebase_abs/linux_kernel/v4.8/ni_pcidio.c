static inline unsigned int F_1 ( unsigned int V_1 )
{
return V_1 & 0x3 ;
}
static inline unsigned int F_2 ( unsigned int V_1 )
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
if ( ! V_5 -> V_9 ) {
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
V_5 -> V_9 = NULL ;
F_9 ( F_1 ( 0 ) |
F_2 ( 0 ) ,
V_3 -> V_16 + V_17 ) ;
F_10 () ;
}
F_7 ( & V_5 -> V_8 , V_7 ) ;
}
static int F_13 ( struct V_2 * V_3 , struct V_18 * V_19 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
int V_20 ;
unsigned long V_7 ;
V_20 = F_3 ( V_3 ) ;
if ( V_20 )
return V_20 ;
F_14 ( V_19 , V_19 -> V_21 -> V_22 ) ;
F_4 ( & V_5 -> V_8 , V_7 ) ;
if ( V_5 -> V_9 ) {
F_15 ( V_5 -> V_9 , 32 , 32 ) ;
F_16 ( V_5 -> V_9 ) ;
} else {
V_20 = - V_23 ;
}
F_7 ( & V_5 -> V_8 , V_7 ) ;
return V_20 ;
}
static int F_17 ( struct V_2 * V_3 , struct V_18 * V_19 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
unsigned long V_24 ;
int V_25 ;
F_4 ( & V_3 -> V_26 , V_24 ) ;
F_18 ( & V_5 -> V_8 ) ;
if ( V_5 -> V_9 )
F_19 ( V_5 -> V_9 , V_19 ) ;
F_20 ( & V_5 -> V_8 ) ;
V_25 = F_21 ( V_19 ) ;
F_7 ( & V_3 -> V_26 , V_24 ) ;
return V_25 ;
}
static T_1 F_22 ( int V_27 , void * V_28 )
{
struct V_2 * V_3 = V_28 ;
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_18 * V_19 = V_3 -> V_29 ;
struct V_30 * V_21 = V_19 -> V_21 ;
unsigned int V_31 ;
int V_7 ;
int V_32 ;
int V_33 = 0 ;
if ( ! V_3 -> V_34 ) {
return V_35 ;
}
F_18 ( & V_3 -> V_26 ) ;
V_32 = F_23 ( V_3 -> V_16 + V_36 ) ;
V_7 = F_23 ( V_3 -> V_16 + V_37 ) ;
F_18 ( & V_5 -> V_8 ) ;
if ( V_5 -> V_9 ) {
F_24 ( V_5 -> V_9 , V_19 , false ) ;
}
F_20 ( & V_5 -> V_8 ) ;
while ( V_32 & V_38 ) {
V_33 ++ ;
if ( V_33 > 20 ) {
F_25 ( V_3 -> V_12 , L_2 ) ;
F_9 ( 0x00 ,
V_3 -> V_16 + V_39 ) ;
break;
}
V_7 &= V_40 ;
if ( V_7 & V_41 ) {
while ( V_7 & V_41 ) {
V_33 ++ ;
if ( V_33 > 100 ) {
F_25 ( V_3 -> V_12 ,
L_2 ) ;
F_9 ( 0x00 , V_3 -> V_16 +
V_39
) ;
goto V_42;
}
V_31 = F_26 ( V_3 -> V_16 + V_43 ) ;
F_27 ( V_19 , & V_31 , 1 ) ;
V_7 = F_23 ( V_3 -> V_16 + V_37 ) ;
}
}
if ( V_7 & V_44 ) {
F_9 ( V_45 , V_3 -> V_16 + V_46 ) ;
V_21 -> V_47 |= V_48 ;
F_9 ( 0x00 , V_3 -> V_16 + V_49 ) ;
break;
} else if ( V_7 & V_50 ) {
F_9 ( V_51 , V_3 -> V_16 + V_52 ) ;
V_21 -> V_47 |= V_53 ;
break;
} else if ( V_7 & V_54 ) {
F_9 ( V_55 ,
V_3 -> V_16 + V_52 ) ;
V_21 -> V_47 |= V_48 ;
} else if ( V_7 & V_56 ) {
F_9 ( V_57 ,
V_3 -> V_16 + V_52 ) ;
V_21 -> V_47 |= V_48 ;
}
V_7 = F_23 ( V_3 -> V_16 + V_37 ) ;
V_32 = F_23 ( V_3 -> V_16 + V_36 ) ;
}
V_42:
F_28 ( V_3 , V_19 ) ;
#if 0
if (!tag)
writeb(0x03, dev->mmio + Master_DMA_And_Interrupt_Control);
#endif
F_20 ( & V_3 -> V_26 ) ;
return V_58 ;
}
static int F_29 ( struct V_2 * V_3 ,
struct V_18 * V_19 ,
struct V_59 * V_60 ,
unsigned int * V_61 )
{
int V_62 ;
V_62 = F_30 ( V_3 , V_19 , V_60 , V_61 , 0 ) ;
if ( V_62 )
return V_62 ;
F_31 ( V_19 -> V_63 , V_3 -> V_16 + F_32 ( 0 ) ) ;
return V_60 -> V_64 ;
}
static int F_33 ( struct V_2 * V_3 ,
struct V_18 * V_19 ,
struct V_59 * V_60 ,
unsigned int * V_61 )
{
if ( F_34 ( V_19 , V_61 ) )
F_31 ( V_19 -> V_65 , V_3 -> V_16 + F_35 ( 0 ) ) ;
V_61 [ 1 ] = F_26 ( V_3 -> V_16 + F_35 ( 0 ) ) ;
return V_60 -> V_64 ;
}
static int F_36 ( int * V_66 , unsigned int V_7 )
{
int V_67 , V_68 ;
V_68 = V_69 ;
switch ( V_7 & V_70 ) {
case V_71 :
default:
V_67 = F_37 ( * V_66 , V_68 ) ;
break;
case V_72 :
V_67 = ( * V_66 ) / V_68 ;
break;
case V_73 :
V_67 = F_38 ( * V_66 , V_68 ) ;
break;
}
* V_66 = V_68 * V_67 ;
return V_67 ;
}
static int F_39 ( struct V_2 * V_3 ,
struct V_18 * V_19 , struct V_74 * V_75 )
{
int V_76 = 0 ;
unsigned int V_77 ;
V_76 |= F_40 ( & V_75 -> V_78 , V_79 | V_80 ) ;
V_76 |= F_40 ( & V_75 -> V_81 ,
V_82 | V_83 ) ;
V_76 |= F_40 ( & V_75 -> V_84 , V_79 ) ;
V_76 |= F_40 ( & V_75 -> V_85 , V_86 ) ;
V_76 |= F_40 ( & V_75 -> V_87 , V_86 | V_88 ) ;
if ( V_76 )
return 1 ;
V_76 |= F_41 ( V_75 -> V_78 ) ;
V_76 |= F_41 ( V_75 -> V_81 ) ;
V_76 |= F_41 ( V_75 -> V_87 ) ;
if ( V_76 )
return 2 ;
V_76 |= F_42 ( & V_75 -> V_89 , 0 ) ;
#define F_43 (TIMER_BASE)
if ( V_75 -> V_81 == V_82 ) {
V_76 |= F_44 ( & V_75 -> V_90 ,
F_43 ) ;
} else {
if ( ( V_75 -> V_90 & ~ ( V_91 | V_92 ) ) != 0 ) {
V_75 -> V_90 &= ( V_91 | V_92 ) ;
V_76 |= - V_93 ;
}
}
V_76 |= F_42 ( & V_75 -> V_94 , 0 ) ;
V_76 |= F_42 ( & V_75 -> V_95 ,
V_75 -> V_96 ) ;
if ( V_75 -> V_87 == V_86 )
V_76 |= F_44 ( & V_75 -> V_97 , 1 ) ;
else
V_76 |= F_42 ( & V_75 -> V_97 , 0 ) ;
if ( V_76 )
return 3 ;
if ( V_75 -> V_81 == V_82 ) {
V_77 = V_75 -> V_90 ;
F_36 ( & V_77 , V_75 -> V_7 ) ;
V_76 |= F_42 ( & V_75 -> V_90 , V_77 ) ;
}
if ( V_76 )
return 4 ;
return 0 ;
}
static int F_45 ( struct V_2 * V_3 ,
struct V_18 * V_19 ,
unsigned int V_98 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_74 * V_75 = & V_19 -> V_21 -> V_75 ;
if ( V_98 != V_75 -> V_89 )
return - V_93 ;
F_9 ( V_5 -> V_99 , V_3 -> V_16 + V_49 ) ;
V_19 -> V_21 -> V_100 = NULL ;
return 1 ;
}
static int F_46 ( struct V_2 * V_3 , struct V_18 * V_19 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_74 * V_75 = & V_19 -> V_21 -> V_75 ;
F_31 ( 0x0000 , V_3 -> V_16 + F_32 ( 0 ) ) ;
if ( 1 ) {
F_9 ( 0x0f , V_3 -> V_16 + V_101 ) ;
F_9 ( F_47 ( 0 ) | F_48 ( 0 ) ,
V_3 -> V_16 + V_102 ) ;
} else {
F_9 ( 0x03 , V_3 -> V_16 + V_101 ) ;
F_9 ( F_47 ( 3 ) | F_48 ( 0 ) ,
V_3 -> V_16 + V_102 ) ;
}
if ( V_75 -> V_81 == V_82 ) {
F_9 ( 0 , V_3 -> V_16 + V_49 ) ;
F_9 ( 0x00 , V_3 -> V_16 + V_103 ) ;
F_9 ( 1 , V_3 -> V_16 + V_104 ) ;
F_9 ( 0x04 , V_3 -> V_16 + V_105 ) ;
F_9 ( 4 , V_3 -> V_16 + V_106 ) ;
F_9 ( 3 , V_3 -> V_16 + V_107 ) ;
F_9 ( 0xc0 , V_3 -> V_16 + V_108 ) ;
F_31 ( F_36 ( & V_75 -> V_90 ,
V_71 ) ,
V_3 -> V_16 + V_109 ) ;
F_9 ( 1 , V_3 -> V_16 + V_110 ) ;
F_9 ( 1 , V_3 -> V_16 + V_111 ) ;
F_9 ( 1 , V_3 -> V_16 + V_112 ) ;
F_9 ( 0x0b , V_3 -> V_16 + V_113 ) ;
F_9 ( 0x01 , V_3 -> V_16 + V_114 ) ;
F_49 ( 0 , V_3 -> V_16 + V_115 ) ;
F_9 ( 0 , V_3 -> V_16 + V_116 ) ;
} else {
F_9 ( 0 , V_3 -> V_16 + V_49 ) ;
F_9 ( 0x00 , V_3 -> V_16 + V_103 ) ;
F_9 ( 0 , V_3 -> V_16 + V_104 ) ;
F_9 ( 0x00 , V_3 -> V_16 + V_105 ) ;
F_9 ( 4 , V_3 -> V_16 + V_106 ) ;
if ( ! ( V_75 -> V_90 & V_92 ) )
F_9 ( 0 , V_3 -> V_16 + V_107 ) ;
else
F_9 ( 2 , V_3 -> V_16 + V_107 ) ;
F_9 ( 0x00 , V_3 -> V_16 + V_108 ) ;
F_31 ( 1 , V_3 -> V_16 + V_109 ) ;
F_9 ( 1 , V_3 -> V_16 + V_110 ) ;
F_9 ( 1 , V_3 -> V_16 + V_111 ) ;
F_9 ( 1 , V_3 -> V_16 + V_112 ) ;
F_9 ( 0x0C , V_3 -> V_16 + V_113 ) ;
F_9 ( 0x10 , V_3 -> V_16 + V_114 ) ;
F_49 ( 0 , V_3 -> V_16 + V_115 ) ;
F_9 ( 0x60 , V_3 -> V_16 + V_116 ) ;
}
if ( V_75 -> V_87 == V_86 ) {
F_31 ( V_75 -> V_97 ,
V_3 -> V_16 + V_117 ) ;
} else {
}
#ifdef F_50
F_9 ( V_55 | V_57 ,
V_3 -> V_16 + V_52 ) ;
{
int V_20 = F_13 ( V_3 , V_19 ) ;
if ( V_20 )
return V_20 ;
}
#else
F_9 ( 0x00 , V_3 -> V_16 + V_17 ) ;
#endif
F_9 ( 0x00 , V_3 -> V_16 + V_118 ) ;
F_9 ( 0xff , V_3 -> V_16 + V_52 ) ;
F_9 ( V_40 , V_3 -> V_16 + V_119 ) ;
F_9 ( 0x03 , V_3 -> V_16 + V_39 ) ;
if ( V_75 -> V_87 == V_88 ) {
V_5 -> V_99 = F_51 ( 0 ) | F_52 ( 7 ) ;
} else {
V_5 -> V_99 = V_120 | F_52 ( 7 ) ;
}
if ( V_75 -> V_78 == V_79 ) {
F_9 ( V_5 -> V_99 , V_3 -> V_16 + V_49 ) ;
V_19 -> V_21 -> V_100 = NULL ;
} else {
V_19 -> V_21 -> V_100 = F_45 ;
}
return 0 ;
}
static int F_53 ( struct V_2 * V_3 ,
struct V_18 * V_19 )
{
F_9 ( 0x00 , V_3 -> V_16 + V_39 ) ;
F_11 ( V_3 ) ;
return 0 ;
}
static int F_54 ( struct V_2 * V_3 ,
struct V_18 * V_19 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
int V_62 ;
V_62 = F_55 ( V_5 -> V_11 , V_19 ) ;
if ( V_62 < 0 )
return V_62 ;
memset ( V_19 -> V_21 -> V_121 , 0xaa , V_19 -> V_21 -> V_22 ) ;
return 0 ;
}
static int F_56 ( struct V_2 * V_3 ,
const T_2 * V_61 , T_3 V_122 ,
unsigned long V_123 )
{
static const int V_124 = 1000 ;
int V_125 = V_123 ;
int V_126 ;
T_3 V_127 ;
F_49 ( 0x80 | V_125 , V_3 -> V_16 + V_128 ) ;
F_49 ( 0xc0 | V_125 , V_3 -> V_16 + V_128 ) ;
for ( V_126 = 0 ;
( F_57 ( V_3 -> V_16 + V_129 ) & 0x2 ) == 0 &&
V_126 < V_124 ; ++ V_126 ) {
F_58 ( 1 ) ;
}
if ( V_126 == V_124 ) {
F_59 ( V_3 -> V_12 ,
L_3 ,
V_125 ) ;
return - V_23 ;
}
F_49 ( 0x80 | V_125 , V_3 -> V_16 + V_128 ) ;
for ( V_126 = 0 ;
F_57 ( V_3 -> V_16 + V_129 ) != 0x3 &&
V_126 < V_124 ; ++ V_126 ) {
F_58 ( 1 ) ;
}
if ( V_126 == V_124 ) {
F_59 ( V_3 -> V_12 ,
L_4 ,
V_125 ) ;
return - V_23 ;
}
for ( V_127 = 0 ; V_127 + 1 < V_122 ; ) {
unsigned int V_130 = V_61 [ V_127 ++ ] ;
V_130 |= V_61 [ V_127 ++ ] << 8 ;
F_49 ( V_130 , V_3 -> V_16 + V_131 ) ;
for ( V_126 = 0 ;
( F_57 ( V_3 -> V_16 + V_129 ) & 0x2 ) == 0
&& V_126 < V_124 ; ++ V_126 ) {
F_58 ( 1 ) ;
}
if ( V_126 == V_124 ) {
F_59 ( V_3 -> V_12 ,
L_5 ,
V_125 ) ;
return - V_23 ;
}
if ( F_60 () )
F_61 () ;
}
F_49 ( 0x0 , V_3 -> V_16 + V_128 ) ;
return 0 ;
}
static int F_62 ( struct V_2 * V_3 , int V_125 )
{
return F_56 ( V_3 , NULL , 0 , V_125 ) ;
}
static int F_63 ( struct V_2 * V_3 )
{
int V_62 ;
int V_126 ;
F_49 ( 0x0 , V_3 -> V_16 + V_128 ) ;
for ( V_126 = 0 ; V_126 < 3 ; ++ V_126 ) {
V_62 = F_62 ( V_3 , V_126 ) ;
if ( V_62 < 0 )
break;
}
F_49 ( 0x0 , V_3 -> V_16 + V_132 ) ;
return V_62 ;
}
static void F_64 ( struct V_2 * V_3 )
{
F_31 ( 0 , V_3 -> V_16 + V_133 ) ;
F_31 ( 0 , V_3 -> V_16 + V_134 ) ;
F_31 ( 0 , V_3 -> V_16 + V_135 ) ;
F_31 ( 0 , V_3 -> V_16 + V_136 ) ;
F_31 ( 0 , V_3 -> V_16 + V_137 ) ;
F_31 ( 0 , V_3 -> V_16 + V_138 ) ;
}
static int F_65 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
static const char * const V_139 [ 3 ] = {
V_140 ,
V_141 ,
V_142 ,
} ;
int V_62 ;
int V_64 ;
V_62 = F_63 ( V_3 ) ;
if ( V_62 < 0 )
return V_62 ;
for ( V_64 = 2 ; V_64 >= 0 ; V_64 -- ) {
V_62 = F_66 ( V_3 , & V_5 -> V_10 -> V_143 -> V_3 ,
V_139 [ V_64 ] ,
F_56 , V_64 ) ;
if ( V_62 == 0 && V_64 == 2 )
F_64 ( V_3 ) ;
if ( V_62 < 0 )
break;
}
return V_62 ;
}
static void F_67 ( struct V_2 * V_3 )
{
F_31 ( 0 , V_3 -> V_16 + F_35 ( 0 ) ) ;
F_31 ( 0 , V_3 -> V_16 + F_32 ( 0 ) ) ;
F_31 ( 0 , V_3 -> V_16 + F_68 ( 0 ) ) ;
F_9 ( 0 , V_3 -> V_16 + V_39 ) ;
}
static int F_69 ( struct V_2 * V_3 ,
unsigned long V_123 )
{
struct V_144 * V_143 = F_70 ( V_3 ) ;
const struct V_145 * V_146 = NULL ;
struct V_4 * V_5 ;
struct V_18 * V_19 ;
int V_62 ;
unsigned int V_27 ;
if ( V_123 < F_71 ( V_147 ) )
V_146 = & V_147 [ V_123 ] ;
if ( ! V_146 )
return - V_148 ;
V_3 -> V_149 = V_146 ;
V_3 -> V_150 = V_146 -> V_151 ;
V_62 = F_72 ( V_3 ) ;
if ( V_62 )
return V_62 ;
V_5 = F_73 ( V_3 , sizeof( * V_5 ) ) ;
if ( ! V_5 )
return - V_152 ;
F_74 ( & V_5 -> V_8 ) ;
V_5 -> V_10 = F_75 ( V_3 , false ) ;
if ( ! V_5 -> V_10 )
return - V_152 ;
V_5 -> V_11 = F_76 ( V_5 -> V_10 ) ;
if ( ! V_5 -> V_11 )
return - V_152 ;
if ( V_146 -> V_153 ) {
V_62 = F_65 ( V_3 ) ;
if ( V_62 < 0 )
return V_62 ;
}
F_67 ( V_3 ) ;
V_62 = F_77 ( V_3 , 1 ) ;
if ( V_62 )
return V_62 ;
F_78 ( V_3 -> V_12 , L_6 , V_3 -> V_150 ,
F_23 ( V_3 -> V_16 + V_154 ) ) ;
V_19 = & V_3 -> V_155 [ 0 ] ;
V_3 -> V_29 = V_19 ;
V_19 -> type = V_156 ;
V_19 -> V_157 =
V_158 | V_159 | V_160 | V_161 |
V_162 ;
V_19 -> V_163 = 32 ;
V_19 -> V_164 = & V_165 ;
V_19 -> V_166 = 1 ;
V_19 -> V_167 = & F_29 ;
V_19 -> V_168 = & F_33 ;
V_19 -> V_169 = & F_46 ;
V_19 -> V_170 = & F_39 ;
V_19 -> V_171 = & F_53 ;
V_19 -> V_172 = 32 ;
V_19 -> V_173 = & F_54 ;
V_19 -> V_174 = V_175 ;
V_19 -> V_176 = & F_17 ;
V_27 = V_143 -> V_27 ;
if ( V_27 ) {
V_62 = F_79 ( V_27 , F_22 , V_177 ,
V_3 -> V_150 , V_3 ) ;
if ( V_62 == 0 )
V_3 -> V_27 = V_27 ;
}
return 0 ;
}
static void F_80 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
if ( V_3 -> V_27 )
F_81 ( V_3 -> V_27 , V_3 ) ;
if ( V_5 ) {
if ( V_5 -> V_11 ) {
F_82 ( V_5 -> V_11 ) ;
V_5 -> V_11 = NULL ;
}
F_83 ( V_5 -> V_10 ) ;
}
if ( V_3 -> V_16 )
F_84 ( V_3 -> V_16 ) ;
F_85 ( V_3 ) ;
}
static int F_86 ( struct V_144 * V_3 ,
const struct V_178 * V_179 )
{
return F_87 ( V_3 , & V_180 , V_179 -> V_181 ) ;
}

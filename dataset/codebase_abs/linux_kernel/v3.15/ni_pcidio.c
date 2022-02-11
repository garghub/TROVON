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
F_8 ( V_3 , L_1 ) ;
return - V_12 ;
}
V_5 -> V_9 -> V_13 = V_14 ;
F_9 ( F_1 ( V_5 -> V_9 -> V_1 ) |
F_2 ( V_5 -> V_9 -> V_1 ) ,
V_5 -> V_10 -> V_15 + V_16 ) ;
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
V_5 -> V_10 -> V_15 + V_16 ) ;
F_10 () ;
}
F_7 ( & V_5 -> V_8 , V_7 ) ;
}
static int F_15 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
unsigned long V_19 ;
int V_20 ;
F_4 ( & V_3 -> V_21 , V_19 ) ;
F_16 ( & V_5 -> V_8 ) ;
if ( V_5 -> V_9 )
F_17 ( V_5 -> V_9 , V_18 -> V_22 ) ;
F_18 ( & V_5 -> V_8 ) ;
V_20 = V_18 -> V_22 -> V_23 - V_18 -> V_22 -> V_24 ;
F_7 ( & V_3 -> V_21 , V_19 ) ;
return V_20 ;
}
static T_1 F_19 ( int V_25 , void * V_26 )
{
struct V_2 * V_3 = V_26 ;
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_17 * V_18 = V_3 -> V_27 ;
struct V_28 * V_22 = V_18 -> V_22 ;
struct V_29 * V_10 = V_5 -> V_10 ;
unsigned int V_30 = 0 ;
unsigned short V_31 = 0 ;
unsigned short V_32 = 0 ;
int V_7 ;
int V_33 ;
int V_34 = 0 ;
unsigned int V_35 = 0 ;
if ( ! V_3 -> V_36 ) {
return V_37 ;
}
F_16 ( & V_3 -> V_21 ) ;
V_33 = F_20 ( V_5 -> V_10 -> V_15 +
V_38 ) ;
V_7 = F_20 ( V_5 -> V_10 -> V_15 + V_39 ) ;
F_16 ( & V_5 -> V_8 ) ;
if ( V_5 -> V_9 )
V_35 = F_21 ( V_5 -> V_9 ) ;
if ( V_35 & V_40 ) {
if ( V_35 & V_41 ) {
F_22 ( V_42 ,
V_10 -> V_43 +
F_23 ( V_5 -> V_9 -> V_1 ) ) ;
F_17 ( V_5 -> V_9 , V_18 -> V_22 ) ;
}
if ( V_35 & ~ ( V_40 | V_41 | V_44 | V_45 |
V_46 | V_47 ) ) {
F_24 ( V_3 -> V_48 ,
L_2 ) ;
V_22 -> V_49 |= V_50 | V_51 ;
F_25 ( V_3 -> V_25 ) ;
}
}
F_18 ( & V_5 -> V_8 ) ;
while ( V_33 & V_52 ) {
V_34 ++ ;
if ( V_34 > 20 ) {
F_24 ( V_3 -> V_48 , L_3 ) ;
F_9 ( 0x00 ,
V_5 -> V_10 -> V_15 +
V_53 ) ;
break;
}
V_7 &= V_54 ;
if ( V_7 & V_55 ) {
while ( V_7 & V_55 ) {
V_34 ++ ;
if ( V_34 > 100 ) {
F_24 ( V_3 -> V_48 ,
L_3 ) ;
F_9 ( 0x00 ,
V_5 -> V_10 -> V_15 +
V_53
) ;
goto V_56;
}
V_30 =
F_26 ( V_5 -> V_10 -> V_15 +
V_57 ) ;
V_31 = V_30 & 0xffff ;
V_32 = ( V_30 & 0xffff0000 ) >> 16 ;
F_27 ( V_22 , V_31 ) ;
F_27 ( V_22 , V_32 ) ;
V_7 = F_20 ( V_5 -> V_10 -> V_15 +
V_39 ) ;
}
V_22 -> V_49 |= V_58 ;
}
if ( V_7 & V_59 ) {
F_9 ( V_60 ,
V_5 -> V_10 -> V_15 +
V_61 ) ;
V_22 -> V_49 |= V_50 ;
F_9 ( 0x00 , V_5 -> V_10 -> V_15 + V_62 ) ;
break;
} else if ( V_7 & V_63 ) {
F_9 ( V_64 ,
V_5 -> V_10 -> V_15 +
V_65 ) ;
V_22 -> V_49 |= V_50 | V_51 ;
break;
} else if ( V_7 & V_66 ) {
F_9 ( V_67 ,
V_5 -> V_10 -> V_15 +
V_65 ) ;
V_22 -> V_49 |= V_50 ;
} else if ( V_7 & V_68 ) {
F_9 ( V_69 ,
V_5 -> V_10 -> V_15 +
V_65 ) ;
V_22 -> V_49 |= V_50 ;
}
V_7 = F_20 ( V_5 -> V_10 -> V_15 + V_39 ) ;
V_33 = F_20 ( V_5 -> V_10 -> V_15 +
V_38 ) ;
}
V_56:
F_28 ( V_3 , V_18 ) ;
#if 0
if (!tag) {
writeb(0x03,
devpriv->mite->daq_io_addr +
Master_DMA_And_Interrupt_Control);
}
#endif
F_18 ( & V_3 -> V_21 ) ;
return V_70 ;
}
static int F_29 ( struct V_2 * V_3 ,
struct V_17 * V_18 ,
struct V_71 * V_72 ,
unsigned int * V_73 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
int V_74 ;
V_74 = F_30 ( V_3 , V_18 , V_72 , V_73 , 0 ) ;
if ( V_74 )
return V_74 ;
F_22 ( V_18 -> V_75 , V_5 -> V_10 -> V_15 + F_31 ( 0 ) ) ;
return V_72 -> V_76 ;
}
static int F_32 ( struct V_2 * V_3 ,
struct V_17 * V_18 ,
struct V_71 * V_72 ,
unsigned int * V_73 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
if ( F_33 ( V_18 , V_73 ) )
F_22 ( V_18 -> V_77 , V_5 -> V_10 -> V_15 + F_34 ( 0 ) ) ;
V_73 [ 1 ] = F_26 ( V_5 -> V_10 -> V_15 + F_34 ( 0 ) ) ;
return V_72 -> V_76 ;
}
static int F_35 ( struct V_2 * V_3 ,
struct V_17 * V_18 , struct V_78 * V_79 )
{
int V_80 = 0 ;
int V_81 ;
V_80 |= F_36 ( & V_79 -> V_82 , V_83 | V_84 ) ;
V_80 |= F_36 ( & V_79 -> V_85 ,
V_86 | V_87 ) ;
V_80 |= F_36 ( & V_79 -> V_88 , V_83 ) ;
V_80 |= F_36 ( & V_79 -> V_89 , V_90 ) ;
V_80 |= F_36 ( & V_79 -> V_91 , V_90 | V_92 ) ;
if ( V_80 )
return 1 ;
V_80 |= F_37 ( V_79 -> V_82 ) ;
V_80 |= F_37 ( V_79 -> V_85 ) ;
V_80 |= F_37 ( V_79 -> V_91 ) ;
if ( V_80 )
return 2 ;
V_80 |= F_38 ( & V_79 -> V_93 , 0 ) ;
#define F_39 (TIMER_BASE)
if ( V_79 -> V_85 == V_86 ) {
V_80 |= F_40 ( & V_79 -> V_94 ,
F_39 ) ;
} else {
if ( ( V_79 -> V_94 & ~ ( V_95 | V_96 ) ) != 0 ) {
V_79 -> V_94 &= ( V_95 | V_96 ) ;
V_80 |= - V_97 ;
}
}
V_80 |= F_38 ( & V_79 -> V_98 , 0 ) ;
V_80 |= F_38 ( & V_79 -> V_99 , V_79 -> V_100 ) ;
if ( V_79 -> V_91 == V_90 ) {
} else {
V_80 |= F_38 ( & V_79 -> V_101 , 0 ) ;
}
if ( V_80 )
return 3 ;
if ( V_79 -> V_85 == V_86 ) {
V_81 = V_79 -> V_94 ;
F_41 ( & V_79 -> V_94 ,
V_79 -> V_7 & V_102 ) ;
if ( V_81 != V_79 -> V_94 )
V_80 ++ ;
}
if ( V_80 )
return 4 ;
return 0 ;
}
static int F_41 ( int * V_103 , int V_104 )
{
int V_105 , V_106 ;
V_106 = V_107 ;
switch ( V_104 ) {
case V_108 :
default:
V_105 = ( * V_103 + V_106 / 2 ) / V_106 ;
break;
case V_109 :
V_105 = ( * V_103 ) / V_106 ;
break;
case V_110 :
V_105 = ( * V_103 + V_106 - 1 ) / V_106 ;
break;
}
* V_103 = V_106 * V_105 ;
return V_105 ;
}
static int F_42 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_78 * V_79 = & V_18 -> V_22 -> V_79 ;
F_22 ( 0x0000 , V_5 -> V_10 -> V_15 + F_31 ( 0 ) ) ;
if ( 1 ) {
F_9 ( 0x0f , V_5 -> V_10 -> V_15 + V_111 ) ;
F_9 ( F_43 ( 0 ) | F_44 ( 0 ) ,
V_5 -> V_10 -> V_15 + V_112 ) ;
} else {
F_9 ( 0x03 , V_5 -> V_10 -> V_15 + V_111 ) ;
F_9 ( F_43 ( 3 ) | F_44 ( 0 ) ,
V_5 -> V_10 -> V_15 + V_112 ) ;
}
if ( V_79 -> V_85 == V_86 ) {
F_9 ( 0 , V_5 -> V_10 -> V_15 + V_62 ) ;
F_9 ( 0x00 , V_5 -> V_10 -> V_15 + V_113 ) ;
F_9 ( 1 , V_5 -> V_10 -> V_15 + V_114 ) ;
F_9 ( 0x04 , V_5 -> V_10 -> V_15 + V_115 ) ;
F_9 ( 4 , V_5 -> V_10 -> V_15 + V_116 ) ;
F_9 ( 3 , V_5 -> V_10 -> V_15 + V_117 ) ;
F_9 ( 0xc0 , V_5 -> V_10 -> V_15 + V_118 ) ;
F_22 ( F_41 ( & V_79 -> V_94 ,
V_108 ) ,
V_5 -> V_10 -> V_15 + V_119 ) ;
F_9 ( 1 , V_5 -> V_10 -> V_15 + V_120 ) ;
F_9 ( 1 , V_5 -> V_10 -> V_15 + V_121 ) ;
F_9 ( 1 , V_5 -> V_10 -> V_15 + V_122 ) ;
F_9 ( 0x0b , V_5 -> V_10 -> V_15 + V_123 ) ;
F_9 ( 0x01 , V_5 -> V_10 -> V_15 + V_124 ) ;
F_45 ( 0 , V_5 -> V_10 -> V_15 + V_125 ) ;
F_9 ( 0 , V_5 -> V_10 -> V_15 + V_126 ) ;
} else {
F_9 ( 0 , V_5 -> V_10 -> V_15 + V_62 ) ;
F_9 ( 0x00 , V_5 -> V_10 -> V_15 + V_113 ) ;
F_9 ( 0 , V_5 -> V_10 -> V_15 + V_114 ) ;
F_9 ( 0x00 , V_5 -> V_10 -> V_15 + V_115 ) ;
F_9 ( 4 , V_5 -> V_10 -> V_15 + V_116 ) ;
if ( ! ( V_79 -> V_94 & V_96 ) ) {
F_9 ( 0 , V_5 -> V_10 -> V_15 + V_117 ) ;
} else {
F_9 ( 2 , V_5 -> V_10 -> V_15 + V_117 ) ;
}
F_9 ( 0x00 , V_5 -> V_10 -> V_15 + V_118 ) ;
F_22 ( 1 , V_5 -> V_10 -> V_15 + V_119 ) ;
F_9 ( 1 , V_5 -> V_10 -> V_15 + V_120 ) ;
F_9 ( 1 , V_5 -> V_10 -> V_15 + V_121 ) ;
F_9 ( 1 , V_5 -> V_10 -> V_15 + V_122 ) ;
F_9 ( 0x0C , V_5 -> V_10 -> V_15 + V_123 ) ;
F_9 ( 0x10 , V_5 -> V_10 -> V_15 + V_124 ) ;
F_45 ( 0 , V_5 -> V_10 -> V_15 + V_125 ) ;
F_9 ( 0x60 , V_5 -> V_10 -> V_15 + V_126 ) ;
}
if ( V_79 -> V_91 == V_90 ) {
F_22 ( V_79 -> V_101 ,
V_5 -> V_10 -> V_15 + V_127 ) ;
} else {
}
#ifdef F_46
F_9 ( V_67 | V_69 ,
V_5 -> V_10 -> V_15 + V_65 ) ;
{
int V_128 = F_47 ( V_3 , V_18 ) ;
if ( V_128 )
return V_128 ;
}
#else
F_9 ( 0x00 , V_5 -> V_10 -> V_15 + V_16 ) ;
#endif
F_9 ( 0x00 , V_5 -> V_10 -> V_15 + V_129 ) ;
F_9 ( 0xff , V_5 -> V_10 -> V_15 + V_65 ) ;
F_9 ( V_54 , V_5 -> V_10 -> V_15 + V_130 ) ;
F_9 ( 0x03 ,
V_5 -> V_10 -> V_15 + V_53 ) ;
if ( V_79 -> V_91 == V_92 ) {
V_5 -> V_131 = F_48 ( 0 ) | F_49 ( 7 ) ;
} else {
V_5 -> V_131 = V_132 | F_49 ( 7 ) ;
}
if ( V_79 -> V_82 == V_83 ) {
F_9 ( V_5 -> V_131 ,
V_5 -> V_10 -> V_15 + V_62 ) ;
V_18 -> V_22 -> V_133 = NULL ;
} else {
V_18 -> V_22 -> V_133 = V_134 ;
}
return 0 ;
}
static int F_47 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
int V_128 ;
unsigned long V_7 ;
V_128 = F_3 ( V_3 ) ;
if ( V_128 )
return V_128 ;
F_50 ( V_18 -> V_22 , V_18 -> V_22 -> V_135 ) ;
F_4 ( & V_5 -> V_8 , V_7 ) ;
if ( V_5 -> V_9 ) {
F_51 ( V_5 -> V_9 , 32 , 32 ) ;
F_52 ( V_5 -> V_9 ) ;
} else
V_128 = - V_136 ;
F_7 ( & V_5 -> V_8 , V_7 ) ;
return V_128 ;
}
static int V_134 ( struct V_2 * V_3 ,
struct V_17 * V_18 , unsigned int V_137 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
if ( V_137 != 0 )
return - V_97 ;
F_9 ( V_5 -> V_131 , V_5 -> V_10 -> V_15 + V_62 ) ;
V_18 -> V_22 -> V_133 = NULL ;
return 1 ;
}
static int F_53 ( struct V_2 * V_3 ,
struct V_17 * V_18 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
F_9 ( 0x00 ,
V_5 -> V_10 -> V_15 + V_53 ) ;
F_11 ( V_3 ) ;
return 0 ;
}
static int F_54 ( struct V_2 * V_3 ,
struct V_17 * V_18 , unsigned long V_138 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
int V_74 ;
V_74 = F_55 ( V_5 -> V_11 , V_18 -> V_22 ) ;
if ( V_74 < 0 )
return V_74 ;
memset ( V_18 -> V_22 -> V_139 , 0xaa , V_18 -> V_22 -> V_135 ) ;
return 0 ;
}
static int F_56 ( struct V_2 * V_3 ,
const T_2 * V_73 , T_3 V_140 ,
unsigned long V_141 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
static const int V_142 = 1000 ;
int V_143 = V_141 ;
int V_144 ;
T_3 V_145 ;
F_45 ( 0x80 | V_143 ,
V_5 -> V_10 -> V_15 + V_146 ) ;
F_45 ( 0xc0 | V_143 ,
V_5 -> V_10 -> V_15 + V_146 ) ;
for ( V_144 = 0 ;
( F_57 ( V_5 -> V_10 -> V_15 +
V_147 ) & 0x2 ) == 0 && V_144 < V_142 ; ++ V_144 ) {
F_58 ( 1 ) ;
}
if ( V_144 == V_142 ) {
F_59 ( V_3 -> V_48 ,
L_4 ,
V_143 ) ;
return - V_136 ;
}
F_45 ( 0x80 | V_143 ,
V_5 -> V_10 -> V_15 + V_146 ) ;
for ( V_144 = 0 ;
F_57 ( V_5 -> V_10 -> V_15 + V_147 ) !=
0x3 && V_144 < V_142 ; ++ V_144 ) {
F_58 ( 1 ) ;
}
if ( V_144 == V_142 ) {
F_59 ( V_3 -> V_48 ,
L_5 ,
V_143 ) ;
return - V_136 ;
}
for ( V_145 = 0 ; V_145 + 1 < V_140 ; ) {
unsigned int V_148 = V_73 [ V_145 ++ ] ;
V_148 |= V_73 [ V_145 ++ ] << 8 ;
F_45 ( V_148 ,
V_5 -> V_10 -> V_15 + V_149 ) ;
for ( V_144 = 0 ;
( F_57 ( V_5 -> V_10 -> V_15 +
V_147 ) & 0x2 ) == 0
&& V_144 < V_142 ; ++ V_144 ) {
F_58 ( 1 ) ;
}
if ( V_144 == V_142 ) {
F_59 ( V_3 -> V_48 ,
L_6 ,
V_143 ) ;
return - V_136 ;
}
if ( F_60 () )
F_61 () ;
}
F_45 ( 0x0 , V_5 -> V_10 -> V_15 + V_146 ) ;
return 0 ;
}
static int F_62 ( struct V_2 * V_3 , int V_143 )
{
return F_56 ( V_3 , NULL , 0 , V_143 ) ;
}
static int F_63 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
int V_74 ;
int V_144 ;
F_45 ( 0x0 , V_5 -> V_10 -> V_15 + V_146 ) ;
for ( V_144 = 0 ; V_144 < 3 ; ++ V_144 ) {
V_74 = F_62 ( V_3 , V_144 ) ;
if ( V_74 < 0 )
break;
}
F_45 ( 0x0 , V_5 -> V_10 -> V_15 + V_150 ) ;
return V_74 ;
}
static void F_64 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
F_22 ( 0 , V_5 -> V_10 -> V_15 + V_151 ) ;
F_22 ( 0 , V_5 -> V_10 -> V_15 + V_152 ) ;
F_22 ( 0 , V_5 -> V_10 -> V_15 + V_153 ) ;
F_22 ( 0 , V_5 -> V_10 -> V_15 + V_154 ) ;
F_22 ( 0 , V_5 -> V_10 -> V_15 + V_155 ) ;
F_22 ( 0 , V_5 -> V_10 -> V_15 + V_156 ) ;
}
static int F_65 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
static const char * const V_157 [ 3 ] = {
V_158 ,
V_159 ,
V_160 ,
} ;
int V_74 ;
int V_76 ;
V_74 = F_63 ( V_3 ) ;
if ( V_74 < 0 )
return V_74 ;
for ( V_76 = 2 ; V_76 >= 0 ; V_76 -- ) {
V_74 = F_66 ( V_3 , & V_5 -> V_10 -> V_161 -> V_3 ,
V_157 [ V_76 ] ,
F_56 , V_76 ) ;
if ( V_74 == 0 && V_76 == 2 )
F_64 ( V_3 ) ;
if ( V_74 < 0 )
break;
}
return V_74 ;
}
static void F_67 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
void T_4 * V_162 = V_5 -> V_10 -> V_15 ;
F_22 ( 0 , V_162 + F_34 ( 0 ) ) ;
F_22 ( 0 , V_162 + F_31 ( 0 ) ) ;
F_22 ( 0 , V_162 + F_68 ( 0 ) ) ;
F_9 ( 0 , V_162 + V_53 ) ;
}
static int F_69 ( struct V_2 * V_3 ,
unsigned long V_141 )
{
struct V_163 * V_161 = F_70 ( V_3 ) ;
const struct V_164 * V_165 = NULL ;
struct V_4 * V_5 ;
struct V_17 * V_18 ;
int V_74 ;
unsigned int V_25 ;
if ( V_141 < F_71 ( V_166 ) )
V_165 = & V_166 [ V_141 ] ;
if ( ! V_165 )
return - V_167 ;
V_3 -> V_168 = V_165 ;
V_3 -> V_169 = V_165 -> V_170 ;
V_74 = F_72 ( V_3 ) ;
if ( V_74 )
return V_74 ;
V_5 = F_73 ( V_3 , sizeof( * V_5 ) ) ;
if ( ! V_5 )
return - V_171 ;
F_74 ( & V_5 -> V_8 ) ;
V_5 -> V_10 = F_75 ( V_161 ) ;
if ( ! V_5 -> V_10 )
return - V_171 ;
V_74 = F_76 ( V_5 -> V_10 ) ;
if ( V_74 < 0 ) {
F_59 ( V_3 -> V_48 , L_7 ) ;
return V_74 ;
}
V_5 -> V_11 = F_77 ( V_5 -> V_10 ) ;
if ( V_5 -> V_11 == NULL )
return - V_171 ;
if ( V_165 -> V_172 ) {
V_74 = F_65 ( V_3 ) ;
if ( V_74 < 0 )
return V_74 ;
}
F_67 ( V_3 ) ;
V_74 = F_78 ( V_3 , 1 ) ;
if ( V_74 )
return V_74 ;
F_79 ( V_3 -> V_48 , L_8 , V_3 -> V_169 ,
F_20 ( V_5 -> V_10 -> V_15 + V_173 ) ) ;
V_18 = & V_3 -> V_174 [ 0 ] ;
V_3 -> V_27 = V_18 ;
V_18 -> type = V_175 ;
V_18 -> V_176 =
V_177 | V_178 | V_179 | V_180 |
V_181 ;
V_18 -> V_182 = 32 ;
V_18 -> V_183 = & V_184 ;
V_18 -> V_185 = 1 ;
V_18 -> V_186 = & F_29 ;
V_18 -> V_187 = & F_32 ;
V_18 -> V_188 = & F_42 ;
V_18 -> V_189 = & F_35 ;
V_18 -> V_190 = & F_53 ;
V_18 -> V_191 = 32 ;
V_18 -> V_192 = & F_54 ;
V_18 -> V_193 = V_194 ;
V_18 -> V_195 = & F_15 ;
V_25 = F_80 ( V_5 -> V_10 ) ;
if ( V_25 ) {
V_74 = F_81 ( V_25 , F_19 , V_196 ,
V_3 -> V_169 , V_3 ) ;
if ( V_74 == 0 )
V_3 -> V_25 = V_25 ;
}
return 0 ;
}
static void F_82 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
if ( V_3 -> V_25 )
F_83 ( V_3 -> V_25 , V_3 ) ;
if ( V_5 ) {
if ( V_5 -> V_11 ) {
F_84 ( V_5 -> V_11 ) ;
V_5 -> V_11 = NULL ;
}
if ( V_5 -> V_10 ) {
F_85 ( V_5 -> V_10 ) ;
F_86 ( V_5 -> V_10 ) ;
}
}
F_87 ( V_3 ) ;
}
static int F_88 ( struct V_163 * V_3 ,
const struct V_197 * V_198 )
{
return F_89 ( V_3 , & V_199 , V_198 -> V_200 ) ;
}

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
static void F_15 ( struct V_2 * V_3 ,
struct V_17 * V_18 )
{
if ( V_18 ->
V_19 -> V_20 & ( V_21 | V_22 |
V_23 ) ) {
F_16 ( V_3 , V_18 ) ;
}
F_17 ( V_3 , V_18 ) ;
}
static int F_18 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
unsigned long V_24 ;
int V_25 ;
F_4 ( & V_3 -> V_26 , V_24 ) ;
F_19 ( & V_5 -> V_8 ) ;
if ( V_5 -> V_9 )
F_20 ( V_5 -> V_9 , V_18 -> V_19 ) ;
F_21 ( & V_5 -> V_8 ) ;
V_25 = V_18 -> V_19 -> V_27 - V_18 -> V_19 -> V_28 ;
F_7 ( & V_3 -> V_26 , V_24 ) ;
return V_25 ;
}
static T_1 F_22 ( int V_29 , void * V_30 )
{
struct V_2 * V_3 = V_30 ;
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_17 * V_18 = & V_3 -> V_31 [ 0 ] ;
struct V_32 * V_19 = V_18 -> V_19 ;
struct V_33 * V_10 = V_5 -> V_10 ;
long int V_34 = 0 ;
short V_35 = 0 ;
short V_36 = 0 ;
int V_7 ;
int V_37 ;
int V_38 = 0 ;
unsigned int V_39 = 0 ;
if ( ! V_3 -> V_40 ) {
return V_41 ;
}
F_19 ( & V_3 -> V_26 ) ;
V_37 = F_23 ( V_5 -> V_10 -> V_15 +
V_42 ) ;
V_7 = F_23 ( V_5 -> V_10 -> V_15 + V_43 ) ;
F_24 ( L_2 ,
V_37 , V_7 ) ;
F_25 ( V_7 ) ;
F_26 ( V_37 ) ;
F_19 ( & V_5 -> V_8 ) ;
if ( V_5 -> V_9 )
V_39 = F_27 ( V_5 -> V_9 ) ;
#ifdef F_28
F_29 ( V_39 ) ;
#endif
if ( V_39 & V_44 ) {
if ( V_39 & V_45 ) {
F_30 ( V_46 ,
V_10 -> V_47 +
F_31 ( V_5 -> V_9 -> V_1 ) ) ;
F_20 ( V_5 -> V_9 , V_18 -> V_19 ) ;
}
if ( V_39 & ~ ( V_44 | V_45 | V_48 | V_49 |
V_50 | V_51 ) ) {
F_24 ( L_3 ) ;
V_19 -> V_20 |= V_21 | V_22 ;
F_32 ( V_3 -> V_29 ) ;
}
}
F_21 ( & V_5 -> V_8 ) ;
while ( V_37 & V_52 ) {
V_38 ++ ;
if ( V_38 > 20 ) {
F_24 ( L_4 ) ;
F_9 ( 0x00 ,
V_5 -> V_10 -> V_15 +
V_53 ) ;
break;
}
V_7 &= V_54 ;
if ( V_7 & V_55 ) {
while ( V_7 & V_55 ) {
V_38 ++ ;
if ( V_38 > 100 ) {
F_24 ( L_4 ) ;
F_9 ( 0x00 ,
V_5 -> V_10 -> V_15 +
V_53
) ;
goto V_56;
}
V_34 =
F_33 ( V_5 -> V_10 -> V_15 +
V_57 ) ;
V_35 = V_34 & 0xffff ;
V_36 = ( V_34 & 0xffff0000 ) >> 16 ;
F_34 ( V_19 , V_35 ) ;
F_34 ( V_19 , V_36 ) ;
V_7 = F_23 ( V_5 -> V_10 -> V_15 +
V_43 ) ;
}
V_19 -> V_20 |= V_58 ;
}
if ( V_7 & V_59 ) {
F_24 ( L_5 ) ;
F_9 ( V_60 ,
V_5 -> V_10 -> V_15 +
V_61 ) ;
V_19 -> V_20 |= V_21 ;
F_9 ( 0x00 , V_5 -> V_10 -> V_15 + V_62 ) ;
break;
} else if ( V_7 & V_63 ) {
F_24 ( L_6 ) ;
F_9 ( V_64 ,
V_5 -> V_10 -> V_15 +
V_65 ) ;
V_19 -> V_20 |= V_21 | V_22 ;
break;
} else if ( V_7 & V_66 ) {
F_24 ( L_7 ) ;
F_9 ( V_67 ,
V_5 -> V_10 -> V_15 +
V_65 ) ;
V_19 -> V_20 |= V_21 ;
} else if ( V_7 & V_68 ) {
F_24 ( L_8 ) ;
F_9 ( V_69 ,
V_5 -> V_10 -> V_15 +
V_65 ) ;
V_19 -> V_20 |= V_21 ;
}
#if 0
else {
DPRINTK("ni_pcidio: unknown interrupt\n");
async->events |= COMEDI_CB_ERROR | COMEDI_CB_EOA;
writeb(0x00,
devpriv->mite->daq_io_addr +
Master_DMA_And_Interrupt_Control);
}
#endif
V_7 = F_23 ( V_5 -> V_10 -> V_15 + V_43 ) ;
V_37 = F_23 ( V_5 -> V_10 -> V_15 +
V_42 ) ;
}
V_56:
F_15 ( V_3 , V_18 ) ;
#if 0
if (!tag) {
writeb(0x03,
devpriv->mite->daq_io_addr +
Master_DMA_And_Interrupt_Control);
}
#endif
F_21 ( & V_3 -> V_26 ) ;
return V_70 ;
}
static const char * F_35 ( unsigned int V_71 , unsigned int V_72 ,
const char * const V_73 [] )
{
return ( V_71 & ( 1U << V_72 ) ) ? V_73 [ V_72 ] : L_9 ;
}
static void F_25 ( unsigned int V_7 )
{
F_36 ( L_10 ,
F_35 ( V_7 , 7 , V_74 ) ,
F_35 ( V_7 , 6 , V_74 ) ,
F_35 ( V_7 , 5 , V_74 ) ,
F_35 ( V_7 , 4 , V_74 ) ,
F_35 ( V_7 , 3 , V_74 ) ,
F_35 ( V_7 , 2 , V_74 ) ,
F_35 ( V_7 , 1 , V_74 ) ,
F_35 ( V_7 , 0 , V_74 ) ) ;
}
static void F_26 ( unsigned int V_7 )
{
F_36 ( L_11 ,
F_35 ( V_7 , 7 , V_75 ) ,
F_35 ( V_7 , 6 , V_75 ) ,
F_35 ( V_7 , 5 , V_75 ) ,
F_35 ( V_7 , 4 , V_75 ) ,
F_35 ( V_7 , 3 , V_75 ) ,
F_35 ( V_7 , 2 , V_75 ) ,
F_35 ( V_7 , 1 , V_75 ) ,
F_35 ( V_7 , 0 , V_75 ) ) ;
}
static void F_37 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
int V_76 , V_77 ;
static int V_78 ;
struct V_79 V_80 ;
F_38 ( & V_80 ) ;
V_76 = F_23 ( V_5 -> V_10 -> V_15 + V_81 ) ;
V_77 = F_23 ( V_5 -> V_10 -> V_15 + V_43 ) ;
if ( V_78 < 10 ) {
F_24 ( L_12 , V_76 , V_77 ,
( int ) V_80 . V_82 ) ;
}
while ( V_77 & 1 ) {
F_39 ( 0xff , V_5 -> V_10 -> V_15 + V_57 ) ;
V_77 = F_23 ( V_5 -> V_10 -> V_15 + V_43 ) ;
}
V_77 = F_23 ( V_5 -> V_10 -> V_15 + V_43 ) ;
if ( V_78 < 10 ) {
F_24 ( L_13 , V_77 ) ;
V_78 ++ ;
}
}
static int F_40 ( struct V_2 * V_3 ,
struct V_17 * V_18 ,
struct V_83 * V_84 , unsigned int * V_85 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
if ( V_84 -> V_86 != 1 )
return - V_87 ;
switch ( V_85 [ 0 ] ) {
case V_88 :
V_18 -> V_89 |= 1 << F_41 ( V_84 -> V_90 ) ;
break;
case V_91 :
V_18 -> V_89 &= ~ ( 1 << F_41 ( V_84 -> V_90 ) ) ;
break;
case V_92 :
V_85 [ 1 ] =
( V_18 ->
V_89 & ( 1 << F_41 ( V_84 -> V_90 ) ) ) ? V_93 :
V_14 ;
return V_84 -> V_86 ;
break;
default:
return - V_87 ;
}
F_30 ( V_18 -> V_89 , V_5 -> V_10 -> V_15 + F_42 ( 0 ) ) ;
return 1 ;
}
static int F_43 ( struct V_2 * V_3 ,
struct V_17 * V_18 ,
struct V_83 * V_84 , unsigned int * V_85 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
if ( V_85 [ 0 ] ) {
V_18 -> V_94 &= ~ V_85 [ 0 ] ;
V_18 -> V_94 |= ( V_85 [ 0 ] & V_85 [ 1 ] ) ;
F_30 ( V_18 -> V_94 , V_5 -> V_10 -> V_15 + F_44 ( 0 ) ) ;
}
V_85 [ 1 ] = F_33 ( V_5 -> V_10 -> V_15 + F_44 ( 0 ) ) ;
return V_84 -> V_86 ;
}
static int F_45 ( struct V_2 * V_3 ,
struct V_17 * V_18 , struct V_95 * V_96 )
{
int V_97 = 0 ;
int V_98 ;
V_97 |= F_46 ( & V_96 -> V_99 , V_100 | V_101 ) ;
V_97 |= F_46 ( & V_96 -> V_102 ,
V_103 | V_104 ) ;
V_97 |= F_46 ( & V_96 -> V_105 , V_100 ) ;
V_97 |= F_46 ( & V_96 -> V_106 , V_107 ) ;
V_97 |= F_46 ( & V_96 -> V_108 , V_107 | V_109 ) ;
if ( V_97 )
return 1 ;
V_97 |= F_47 ( V_96 -> V_99 ) ;
V_97 |= F_47 ( V_96 -> V_102 ) ;
V_97 |= F_47 ( V_96 -> V_108 ) ;
if ( V_97 )
return 2 ;
V_97 |= F_48 ( & V_96 -> V_110 , 0 ) ;
#define F_49 (TIMER_BASE)
if ( V_96 -> V_102 == V_103 ) {
V_97 |= F_50 ( & V_96 -> V_111 ,
F_49 ) ;
} else {
if ( ( V_96 -> V_111 & ~ ( V_112 | V_113 ) ) != 0 ) {
V_96 -> V_111 &= ( V_112 | V_113 ) ;
V_97 |= - V_87 ;
}
}
V_97 |= F_48 ( & V_96 -> V_114 , 0 ) ;
V_97 |= F_48 ( & V_96 -> V_115 , V_96 -> V_116 ) ;
if ( V_96 -> V_108 == V_107 ) {
} else {
V_97 |= F_48 ( & V_96 -> V_117 , 0 ) ;
}
if ( V_97 )
return 3 ;
if ( V_96 -> V_102 == V_103 ) {
V_98 = V_96 -> V_111 ;
F_51 ( & V_96 -> V_111 ,
V_96 -> V_7 & V_118 ) ;
if ( V_98 != V_96 -> V_111 )
V_97 ++ ;
}
if ( V_97 )
return 4 ;
return 0 ;
}
static int F_51 ( int * V_119 , int V_120 )
{
int V_121 , V_122 ;
V_122 = V_123 ;
switch ( V_120 ) {
case V_124 :
default:
V_121 = ( * V_119 + V_122 / 2 ) / V_122 ;
break;
case V_125 :
V_121 = ( * V_119 ) / V_122 ;
break;
case V_126 :
V_121 = ( * V_119 + V_122 - 1 ) / V_122 ;
break;
}
* V_119 = V_122 * V_121 ;
return V_121 ;
}
static int F_52 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_95 * V_96 = & V_18 -> V_19 -> V_96 ;
F_30 ( 0x0000 , V_5 -> V_10 -> V_15 + F_42 ( 0 ) ) ;
if ( 1 ) {
F_9 ( 0x0f , V_5 -> V_10 -> V_15 + V_127 ) ;
F_9 ( F_53 ( 0 ) | F_54 ( 0 ) ,
V_5 -> V_10 -> V_15 + V_128 ) ;
} else {
F_9 ( 0x03 , V_5 -> V_10 -> V_15 + V_127 ) ;
F_9 ( F_53 ( 3 ) | F_54 ( 0 ) ,
V_5 -> V_10 -> V_15 + V_128 ) ;
}
if ( V_96 -> V_102 == V_103 ) {
F_9 ( 0 , V_5 -> V_10 -> V_15 + V_62 ) ;
F_9 ( 0x00 , V_5 -> V_10 -> V_15 + V_129 ) ;
F_9 ( 1 , V_5 -> V_10 -> V_15 + V_130 ) ;
F_9 ( 0x04 , V_5 -> V_10 -> V_15 + V_131 ) ;
F_9 ( 4 , V_5 -> V_10 -> V_15 + V_132 ) ;
F_9 ( 3 , V_5 -> V_10 -> V_15 + V_133 ) ;
F_9 ( 0xc0 , V_5 -> V_10 -> V_15 + V_134 ) ;
F_30 ( F_51 ( & V_96 -> V_111 ,
V_124 ) ,
V_5 -> V_10 -> V_15 + V_135 ) ;
F_9 ( 1 , V_5 -> V_10 -> V_15 + V_136 ) ;
F_9 ( 1 , V_5 -> V_10 -> V_15 + V_137 ) ;
F_9 ( 1 , V_5 -> V_10 -> V_15 + V_138 ) ;
F_9 ( 0x0b , V_5 -> V_10 -> V_15 + V_139 ) ;
F_9 ( 0x01 , V_5 -> V_10 -> V_15 + V_140 ) ;
F_39 ( 0 , V_5 -> V_10 -> V_15 + V_141 ) ;
F_9 ( 0 , V_5 -> V_10 -> V_15 + V_142 ) ;
} else {
F_9 ( 0 , V_5 -> V_10 -> V_15 + V_62 ) ;
F_9 ( 0x00 , V_5 -> V_10 -> V_15 + V_129 ) ;
F_9 ( 0 , V_5 -> V_10 -> V_15 + V_130 ) ;
F_9 ( 0x00 , V_5 -> V_10 -> V_15 + V_131 ) ;
F_9 ( 4 , V_5 -> V_10 -> V_15 + V_132 ) ;
if ( ! ( V_96 -> V_111 & V_113 ) ) {
F_9 ( 0 , V_5 -> V_10 -> V_15 + V_133 ) ;
} else {
F_9 ( 2 , V_5 -> V_10 -> V_15 + V_133 ) ;
}
F_9 ( 0x00 , V_5 -> V_10 -> V_15 + V_134 ) ;
F_30 ( 1 , V_5 -> V_10 -> V_15 + V_135 ) ;
F_9 ( 1 , V_5 -> V_10 -> V_15 + V_136 ) ;
F_9 ( 1 , V_5 -> V_10 -> V_15 + V_137 ) ;
F_9 ( 1 , V_5 -> V_10 -> V_15 + V_138 ) ;
F_9 ( 0x0C , V_5 -> V_10 -> V_15 + V_139 ) ;
F_9 ( 0x10 , V_5 -> V_10 -> V_15 + V_140 ) ;
F_39 ( 0 , V_5 -> V_10 -> V_15 + V_141 ) ;
F_9 ( 0x60 , V_5 -> V_10 -> V_15 + V_142 ) ;
}
if ( V_96 -> V_108 == V_107 ) {
F_30 ( V_96 -> V_117 ,
V_5 -> V_10 -> V_15 + V_143 ) ;
} else {
}
#ifdef F_55
F_9 ( V_67 | V_69 ,
V_5 -> V_10 -> V_15 + V_65 ) ;
{
int V_144 = F_56 ( V_3 , V_18 ) ;
if ( V_144 )
return V_144 ;
}
#else
F_9 ( 0x00 , V_5 -> V_10 -> V_15 + V_16 ) ;
#endif
F_9 ( 0x00 , V_5 -> V_10 -> V_15 + V_145 ) ;
F_9 ( 0xff , V_5 -> V_10 -> V_15 + V_65 ) ;
F_9 ( V_54 , V_5 -> V_10 -> V_15 + V_146 ) ;
F_9 ( 0x03 ,
V_5 -> V_10 -> V_15 + V_53 ) ;
if ( V_96 -> V_108 == V_109 ) {
V_5 -> V_147 = F_57 ( 0 ) | F_58 ( 7 ) ;
} else {
V_5 -> V_147 = V_148 | F_58 ( 7 ) ;
}
if ( V_96 -> V_99 == V_100 ) {
F_9 ( V_5 -> V_147 ,
V_5 -> V_10 -> V_15 + V_62 ) ;
V_18 -> V_19 -> V_149 = NULL ;
} else {
V_18 -> V_19 -> V_149 = V_150 ;
}
F_24 ( L_14 ) ;
return 0 ;
}
static int F_56 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
int V_144 ;
unsigned long V_7 ;
V_144 = F_3 ( V_3 ) ;
if ( V_144 )
return V_144 ;
F_59 ( V_18 -> V_19 , V_18 -> V_19 -> V_151 ) ;
F_4 ( & V_5 -> V_8 , V_7 ) ;
if ( V_5 -> V_9 ) {
F_60 ( V_5 -> V_9 , 32 , 32 ) ;
F_61 ( V_5 -> V_9 ) ;
} else
V_144 = - V_152 ;
F_7 ( & V_5 -> V_8 , V_7 ) ;
return V_144 ;
}
static int V_150 ( struct V_2 * V_3 ,
struct V_17 * V_18 , unsigned int V_153 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
if ( V_153 != 0 )
return - V_87 ;
F_9 ( V_5 -> V_147 , V_5 -> V_10 -> V_15 + V_62 ) ;
V_18 -> V_19 -> V_149 = NULL ;
return 1 ;
}
static int F_16 ( struct V_2 * V_3 ,
struct V_17 * V_18 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
F_9 ( 0x00 ,
V_5 -> V_10 -> V_15 + V_53 ) ;
F_11 ( V_3 ) ;
return 0 ;
}
static int F_62 ( struct V_2 * V_3 ,
struct V_17 * V_18 , unsigned long V_154 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
int V_155 ;
V_155 = F_63 ( V_5 -> V_11 , V_18 -> V_19 ) ;
if ( V_155 < 0 )
return V_155 ;
memset ( V_18 -> V_19 -> V_156 , 0xaa , V_18 -> V_19 -> V_151 ) ;
return 0 ;
}
static int F_64 ( struct V_2 * V_3 ,
const T_2 * V_85 , T_3 V_157 ,
unsigned long V_158 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
static const int V_159 = 1000 ;
int V_160 = V_158 ;
int V_161 ;
T_3 V_162 ;
F_39 ( 0x80 | V_160 ,
V_5 -> V_10 -> V_15 + V_163 ) ;
F_39 ( 0xc0 | V_160 ,
V_5 -> V_10 -> V_15 + V_163 ) ;
for ( V_161 = 0 ;
( F_65 ( V_5 -> V_10 -> V_15 +
V_164 ) & 0x2 ) == 0 && V_161 < V_159 ; ++ V_161 ) {
F_66 ( 1 ) ;
}
if ( V_161 == V_159 ) {
F_67 ( V_3 -> V_165 ,
L_15 ,
V_160 ) ;
return - V_152 ;
}
F_39 ( 0x80 | V_160 ,
V_5 -> V_10 -> V_15 + V_163 ) ;
for ( V_161 = 0 ;
F_65 ( V_5 -> V_10 -> V_15 + V_164 ) !=
0x3 && V_161 < V_159 ; ++ V_161 ) {
F_66 ( 1 ) ;
}
if ( V_161 == V_159 ) {
F_67 ( V_3 -> V_165 ,
L_16 ,
V_160 ) ;
return - V_152 ;
}
for ( V_162 = 0 ; V_162 + 1 < V_157 ; ) {
unsigned int V_166 = V_85 [ V_162 ++ ] ;
V_166 |= V_85 [ V_162 ++ ] << 8 ;
F_39 ( V_166 ,
V_5 -> V_10 -> V_15 + V_167 ) ;
for ( V_161 = 0 ;
( F_65 ( V_5 -> V_10 -> V_15 +
V_164 ) & 0x2 ) == 0
&& V_161 < V_159 ; ++ V_161 ) {
F_66 ( 1 ) ;
}
if ( V_161 == V_159 ) {
F_67 ( V_3 -> V_165 ,
L_17 ,
V_160 ) ;
return - V_152 ;
}
if ( F_68 () )
F_69 () ;
}
F_39 ( 0x0 , V_5 -> V_10 -> V_15 + V_163 ) ;
return 0 ;
}
static int F_70 ( struct V_2 * V_3 , int V_160 )
{
return F_64 ( V_3 , NULL , 0 , V_160 ) ;
}
static int F_71 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
int V_155 ;
int V_161 ;
F_39 ( 0x0 , V_5 -> V_10 -> V_15 + V_163 ) ;
for ( V_161 = 0 ; V_161 < 3 ; ++ V_161 ) {
V_155 = F_70 ( V_3 , V_161 ) ;
if ( V_155 < 0 )
break;
}
F_39 ( 0x0 , V_5 -> V_10 -> V_15 + V_168 ) ;
return V_155 ;
}
static void F_72 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
F_30 ( 0 , V_5 -> V_10 -> V_15 + V_169 ) ;
F_30 ( 0 , V_5 -> V_10 -> V_15 + V_170 ) ;
F_30 ( 0 , V_5 -> V_10 -> V_15 + V_171 ) ;
F_30 ( 0 , V_5 -> V_10 -> V_15 + V_172 ) ;
F_30 ( 0 , V_5 -> V_10 -> V_15 + V_173 ) ;
F_30 ( 0 , V_5 -> V_10 -> V_15 + V_174 ) ;
}
static int F_73 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
static const char * const V_175 [ 3 ] = {
V_176 ,
V_177 ,
V_178 ,
} ;
int V_155 ;
int V_86 ;
V_155 = F_71 ( V_3 ) ;
if ( V_155 < 0 )
return V_155 ;
for ( V_86 = 2 ; V_86 >= 0 ; V_86 -- ) {
V_155 = F_74 ( V_3 , & V_5 -> V_10 -> V_179 -> V_3 ,
V_175 [ V_86 ] ,
F_64 , V_86 ) ;
if ( V_155 == 0 && V_86 == 2 )
F_72 ( V_3 ) ;
if ( V_155 < 0 )
break;
}
return V_155 ;
}
static int F_75 ( struct V_2 * V_3 ,
unsigned long V_158 )
{
struct V_180 * V_179 = F_76 ( V_3 ) ;
const struct V_181 * V_182 = NULL ;
struct V_4 * V_5 ;
struct V_17 * V_18 ;
int V_155 ;
unsigned int V_29 ;
if ( V_158 < F_77 ( V_183 ) )
V_182 = & V_183 [ V_158 ] ;
if ( ! V_182 )
return - V_184 ;
V_3 -> V_185 = V_182 ;
V_3 -> V_186 = V_182 -> V_187 ;
V_155 = F_78 ( V_3 ) ;
if ( V_155 )
return V_155 ;
V_5 = F_79 ( sizeof( * V_5 ) , V_188 ) ;
if ( ! V_5 )
return - V_189 ;
V_3 -> V_6 = V_5 ;
F_80 ( & V_5 -> V_8 ) ;
V_5 -> V_10 = F_81 ( V_179 ) ;
if ( ! V_5 -> V_10 )
return - V_189 ;
V_155 = F_82 ( V_5 -> V_10 ) ;
if ( V_155 < 0 ) {
F_67 ( V_3 -> V_165 , L_18 ) ;
return V_155 ;
}
V_5 -> V_11 = F_83 ( V_5 -> V_10 ) ;
if ( V_5 -> V_11 == NULL )
return - V_189 ;
V_29 = F_84 ( V_5 -> V_10 ) ;
if ( V_182 -> V_190 ) {
V_155 = F_73 ( V_3 ) ;
if ( V_155 < 0 )
return V_155 ;
}
V_155 = F_85 ( V_3 , 1 ) ;
if ( V_155 )
return V_155 ;
F_86 ( V_3 -> V_165 , L_19 , V_3 -> V_186 ,
F_23 ( V_5 -> V_10 -> V_15 + V_191 ) ) ;
V_18 = & V_3 -> V_31 [ 0 ] ;
V_3 -> V_192 = V_18 ;
V_18 -> type = V_193 ;
V_18 -> V_194 =
V_195 | V_196 | V_197 | V_198 |
V_199 ;
V_18 -> V_200 = 32 ;
V_18 -> V_201 = & V_202 ;
V_18 -> V_203 = 1 ;
V_18 -> V_204 = & F_40 ;
V_18 -> V_205 = & F_43 ;
V_18 -> V_206 = & F_52 ;
V_18 -> V_207 = & F_45 ;
V_18 -> V_208 = & F_16 ;
V_18 -> V_209 = 32 ;
V_18 -> V_210 = & F_62 ;
V_18 -> V_211 = V_212 ;
V_18 -> V_213 = & F_18 ;
F_30 ( 0 , V_5 -> V_10 -> V_15 + F_44 ( 0 ) ) ;
F_30 ( 0 , V_5 -> V_10 -> V_15 + F_42 ( 0 ) ) ;
F_30 ( 0 , V_5 -> V_10 -> V_15 + F_87 ( 0 ) ) ;
F_9 ( 0x00 ,
V_5 -> V_10 -> V_15 +
V_53 ) ;
V_155 = F_88 ( V_29 , F_22 , V_214 ,
L_20 , V_3 ) ;
if ( V_155 < 0 )
F_67 ( V_3 -> V_165 , L_21 ) ;
V_3 -> V_29 = V_29 ;
return 0 ;
}
static void F_89 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
if ( V_3 -> V_29 )
F_90 ( V_3 -> V_29 , V_3 ) ;
if ( V_5 ) {
if ( V_5 -> V_11 ) {
F_91 ( V_5 -> V_11 ) ;
V_5 -> V_11 = NULL ;
}
if ( V_5 -> V_10 ) {
F_92 ( V_5 -> V_10 ) ;
F_93 ( V_5 -> V_10 ) ;
}
}
F_94 ( V_3 ) ;
}
static int F_95 ( struct V_180 * V_3 ,
const struct V_215 * V_216 )
{
return F_96 ( V_3 , & V_217 , V_216 -> V_218 ) ;
}

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
unsigned long V_4 ;
F_4 ( & V_5 -> V_6 , V_4 ) ;
F_5 ( V_5 -> V_7 ) ;
V_5 -> V_7 =
F_6 ( V_5 -> V_8 ,
V_5 -> V_9 , 1 , 2 ) ;
if ( V_5 -> V_7 == NULL ) {
F_7 ( & V_5 -> V_6 , V_4 ) ;
F_8 ( V_3 , L_1 ) ;
return - V_10 ;
}
V_5 -> V_7 -> V_11 = V_12 ;
F_9 ( F_1 ( V_5 -> V_7 -> V_1 ) |
F_2 ( V_5 -> V_7 -> V_1 ) ,
V_5 -> V_8 -> V_13 + V_14 ) ;
F_10 () ;
F_7 ( & V_5 -> V_6 , V_4 ) ;
return 0 ;
}
static void F_11 ( struct V_2 * V_3 )
{
unsigned long V_4 ;
F_4 ( & V_5 -> V_6 , V_4 ) ;
if ( V_5 -> V_7 ) {
F_12 ( V_5 -> V_7 ) ;
F_13 ( V_5 -> V_7 ) ;
F_14 ( V_5 -> V_7 ) ;
V_5 -> V_7 = NULL ;
F_9 ( F_1 ( 0 ) |
F_2 ( 0 ) ,
V_5 -> V_8 -> V_13 + V_14 ) ;
F_10 () ;
}
F_7 ( & V_5 -> V_6 , V_4 ) ;
}
static void F_15 ( struct V_2 * V_3 ,
struct V_15 * V_16 )
{
if ( V_16 ->
V_17 -> V_18 & ( V_19 | V_20 |
V_21 ) ) {
F_16 ( V_3 , V_16 ) ;
}
F_17 ( V_3 , V_16 ) ;
}
static int F_18 ( struct V_2 * V_3 , struct V_15 * V_16 )
{
unsigned long V_22 ;
int V_23 ;
F_4 ( & V_3 -> V_24 , V_22 ) ;
F_19 ( & V_5 -> V_6 ) ;
if ( V_5 -> V_7 )
F_20 ( V_5 -> V_7 , V_16 -> V_17 ) ;
F_21 ( & V_5 -> V_6 ) ;
V_23 = V_16 -> V_17 -> V_25 - V_16 -> V_17 -> V_26 ;
F_7 ( & V_3 -> V_24 , V_22 ) ;
return V_23 ;
}
static T_1 F_22 ( int V_27 , void * V_28 )
{
struct V_2 * V_3 = V_28 ;
struct V_15 * V_16 = & V_3 -> V_29 [ 0 ] ;
struct V_30 * V_17 = V_16 -> V_17 ;
struct V_31 * V_8 = V_5 -> V_8 ;
long int V_32 = 0 ;
short V_33 = 0 ;
short V_34 = 0 ;
int V_4 ;
int V_35 ;
int V_36 = 0 ;
unsigned int V_37 = 0 ;
if ( V_3 -> V_38 == 0 ) {
return V_39 ;
}
F_19 ( & V_3 -> V_24 ) ;
V_35 = F_23 ( V_5 -> V_8 -> V_13 +
V_40 ) ;
V_4 = F_23 ( V_5 -> V_8 -> V_13 + V_41 ) ;
F_24 ( L_2 ,
V_35 , V_4 ) ;
F_25 ( V_4 ) ;
F_26 ( V_35 ) ;
F_19 ( & V_5 -> V_6 ) ;
if ( V_5 -> V_7 )
V_37 = F_27 ( V_5 -> V_7 ) ;
#ifdef F_28
F_29 ( V_37 ) ;
#endif
if ( V_37 & V_42 ) {
if ( V_37 & V_43 ) {
F_30 ( V_44 ,
V_8 -> V_45 +
F_31 ( V_5 -> V_7 -> V_1 ) ) ;
F_20 ( V_5 -> V_7 , V_16 -> V_17 ) ;
}
if ( V_37 & ~ ( V_42 | V_43 | V_46 | V_47 |
V_48 | V_49 ) ) {
F_24 ( L_3 ) ;
V_17 -> V_18 |= V_19 | V_20 ;
F_32 ( V_3 -> V_27 ) ;
}
}
F_21 ( & V_5 -> V_6 ) ;
while ( V_35 & V_50 ) {
V_36 ++ ;
if ( V_36 > 20 ) {
F_24 ( L_4 ) ;
F_9 ( 0x00 ,
V_5 -> V_8 -> V_13 +
V_51 ) ;
break;
}
V_4 &= V_52 ;
if ( V_4 & V_53 ) {
while ( V_4 & V_53 ) {
V_36 ++ ;
if ( V_36 > 100 ) {
F_24 ( L_4 ) ;
F_9 ( 0x00 ,
V_5 -> V_8 -> V_13 +
V_51
) ;
goto V_54;
}
V_32 =
F_33 ( V_5 -> V_8 -> V_13 +
V_55 ) ;
V_33 = V_32 & 0xffff ;
V_34 = ( V_32 & 0xffff0000 ) >> 16 ;
F_34 ( V_17 , V_33 ) ;
F_34 ( V_17 , V_34 ) ;
V_4 = F_23 ( V_5 -> V_8 -> V_13 +
V_41 ) ;
}
V_17 -> V_18 |= V_56 ;
}
if ( V_4 & V_57 ) {
F_24 ( L_5 ) ;
F_9 ( V_58 ,
V_5 -> V_8 -> V_13 +
V_59 ) ;
V_17 -> V_18 |= V_19 ;
F_9 ( 0x00 , V_5 -> V_8 -> V_13 + V_60 ) ;
break;
} else if ( V_4 & V_61 ) {
F_24 ( L_6 ) ;
F_9 ( V_62 ,
V_5 -> V_8 -> V_13 +
V_63 ) ;
V_17 -> V_18 |= V_19 | V_20 ;
break;
} else if ( V_4 & V_64 ) {
F_24 ( L_7 ) ;
F_9 ( V_65 ,
V_5 -> V_8 -> V_13 +
V_63 ) ;
V_17 -> V_18 |= V_19 ;
} else if ( V_4 & V_66 ) {
F_24 ( L_8 ) ;
F_9 ( V_67 ,
V_5 -> V_8 -> V_13 +
V_63 ) ;
V_17 -> V_18 |= V_19 ;
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
V_4 = F_23 ( V_5 -> V_8 -> V_13 + V_41 ) ;
V_35 = F_23 ( V_5 -> V_8 -> V_13 +
V_40 ) ;
}
V_54:
F_15 ( V_3 , V_16 ) ;
#if 0
if (!tag) {
writeb(0x03,
devpriv->mite->daq_io_addr +
Master_DMA_And_Interrupt_Control);
}
#endif
F_21 ( & V_3 -> V_24 ) ;
return V_68 ;
}
static const char * F_35 ( unsigned int V_69 , unsigned int V_70 ,
const char * const V_71 [] )
{
return ( V_69 & ( 1U << V_70 ) ) ? V_71 [ V_70 ] : L_9 ;
}
static void F_25 ( unsigned int V_4 )
{
F_36 ( L_10 ,
F_35 ( V_4 , 7 , V_72 ) ,
F_35 ( V_4 , 6 , V_72 ) ,
F_35 ( V_4 , 5 , V_72 ) ,
F_35 ( V_4 , 4 , V_72 ) ,
F_35 ( V_4 , 3 , V_72 ) ,
F_35 ( V_4 , 2 , V_72 ) ,
F_35 ( V_4 , 1 , V_72 ) ,
F_35 ( V_4 , 0 , V_72 ) ) ;
}
static void F_26 ( unsigned int V_4 )
{
F_36 ( L_11 ,
F_35 ( V_4 , 7 , V_73 ) ,
F_35 ( V_4 , 6 , V_73 ) ,
F_35 ( V_4 , 5 , V_73 ) ,
F_35 ( V_4 , 4 , V_73 ) ,
F_35 ( V_4 , 3 , V_73 ) ,
F_35 ( V_4 , 2 , V_73 ) ,
F_35 ( V_4 , 1 , V_73 ) ,
F_35 ( V_4 , 0 , V_73 ) ) ;
}
static void F_37 ( struct V_2 * V_3 )
{
int V_74 , V_75 ;
static int V_76 ;
struct V_77 V_78 ;
F_38 ( & V_78 ) ;
V_74 = F_23 ( V_5 -> V_8 -> V_13 + V_79 ) ;
V_75 = F_23 ( V_5 -> V_8 -> V_13 + V_41 ) ;
if ( V_76 < 10 ) {
F_24 ( L_12 , V_74 , V_75 ,
( int ) V_78 . V_80 ) ;
}
while ( V_75 & 1 ) {
F_39 ( 0xff , V_5 -> V_8 -> V_13 + V_55 ) ;
V_75 = F_23 ( V_5 -> V_8 -> V_13 + V_41 ) ;
}
V_75 = F_23 ( V_5 -> V_8 -> V_13 + V_41 ) ;
if ( V_76 < 10 ) {
F_24 ( L_13 , V_75 ) ;
V_76 ++ ;
}
}
static int F_40 ( struct V_2 * V_3 ,
struct V_15 * V_16 ,
struct V_81 * V_82 , unsigned int * V_83 )
{
if ( V_82 -> V_84 != 1 )
return - V_85 ;
switch ( V_83 [ 0 ] ) {
case V_86 :
V_16 -> V_87 |= 1 << F_41 ( V_82 -> V_88 ) ;
break;
case V_89 :
V_16 -> V_87 &= ~ ( 1 << F_41 ( V_82 -> V_88 ) ) ;
break;
case V_90 :
V_83 [ 1 ] =
( V_16 ->
V_87 & ( 1 << F_41 ( V_82 -> V_88 ) ) ) ? V_91 :
V_12 ;
return V_82 -> V_84 ;
break;
default:
return - V_85 ;
}
F_30 ( V_16 -> V_87 , V_5 -> V_8 -> V_13 + F_42 ( 0 ) ) ;
return 1 ;
}
static int F_43 ( struct V_2 * V_3 ,
struct V_15 * V_16 ,
struct V_81 * V_82 , unsigned int * V_83 )
{
if ( V_83 [ 0 ] ) {
V_16 -> V_92 &= ~ V_83 [ 0 ] ;
V_16 -> V_92 |= ( V_83 [ 0 ] & V_83 [ 1 ] ) ;
F_30 ( V_16 -> V_92 , V_5 -> V_8 -> V_13 + F_44 ( 0 ) ) ;
}
V_83 [ 1 ] = F_33 ( V_5 -> V_8 -> V_13 + F_44 ( 0 ) ) ;
return V_82 -> V_84 ;
}
static int F_45 ( struct V_2 * V_3 ,
struct V_15 * V_16 , struct V_93 * V_94 )
{
int V_95 = 0 ;
int V_96 ;
V_95 |= F_46 ( & V_94 -> V_97 , V_98 | V_99 ) ;
V_95 |= F_46 ( & V_94 -> V_100 ,
V_101 | V_102 ) ;
V_95 |= F_46 ( & V_94 -> V_103 , V_98 ) ;
V_95 |= F_46 ( & V_94 -> V_104 , V_105 ) ;
V_95 |= F_46 ( & V_94 -> V_106 , V_105 | V_107 ) ;
if ( V_95 )
return 1 ;
V_95 |= F_47 ( V_94 -> V_97 ) ;
V_95 |= F_47 ( V_94 -> V_100 ) ;
V_95 |= F_47 ( V_94 -> V_106 ) ;
if ( V_95 )
return 2 ;
if ( V_94 -> V_108 != 0 ) {
V_94 -> V_108 = 0 ;
V_95 ++ ;
}
#define F_48 (TIMER_BASE)
if ( V_94 -> V_100 == V_101 ) {
if ( V_94 -> V_109 < F_48 ) {
V_94 -> V_109 = F_48 ;
V_95 ++ ;
}
} else {
if ( ( V_94 -> V_109 & ~ ( V_110 | V_111 ) ) != 0 ) {
V_94 -> V_109 &= ( V_110 | V_111 ) ;
V_95 ++ ;
}
}
if ( V_94 -> V_112 != 0 ) {
V_94 -> V_112 = 0 ;
V_95 ++ ;
}
if ( V_94 -> V_113 != V_94 -> V_114 ) {
V_94 -> V_113 = V_94 -> V_114 ;
V_95 ++ ;
}
if ( V_94 -> V_106 == V_105 ) {
} else {
if ( V_94 -> V_115 != 0 ) {
V_94 -> V_115 = 0 ;
V_95 ++ ;
}
}
if ( V_95 )
return 3 ;
if ( V_94 -> V_100 == V_101 ) {
V_96 = V_94 -> V_109 ;
F_49 ( & V_94 -> V_109 ,
V_94 -> V_4 & V_116 ) ;
if ( V_96 != V_94 -> V_109 )
V_95 ++ ;
}
if ( V_95 )
return 4 ;
return 0 ;
}
static int F_49 ( int * V_117 , int V_118 )
{
int V_119 , V_120 ;
V_120 = V_121 ;
switch ( V_118 ) {
case V_122 :
default:
V_119 = ( * V_117 + V_120 / 2 ) / V_120 ;
break;
case V_123 :
V_119 = ( * V_117 ) / V_120 ;
break;
case V_124 :
V_119 = ( * V_117 + V_120 - 1 ) / V_120 ;
break;
}
* V_117 = V_120 * V_119 ;
return V_119 ;
}
static int F_50 ( struct V_2 * V_3 , struct V_15 * V_16 )
{
struct V_93 * V_94 = & V_16 -> V_17 -> V_94 ;
F_30 ( 0x0000 , V_5 -> V_8 -> V_13 + F_42 ( 0 ) ) ;
if ( 1 ) {
F_9 ( 0x0f , V_5 -> V_8 -> V_13 + V_125 ) ;
F_9 ( F_51 ( 0 ) | F_52 ( 0 ) ,
V_5 -> V_8 -> V_13 + V_126 ) ;
} else {
F_9 ( 0x03 , V_5 -> V_8 -> V_13 + V_125 ) ;
F_9 ( F_51 ( 3 ) | F_52 ( 0 ) ,
V_5 -> V_8 -> V_13 + V_126 ) ;
}
if ( V_94 -> V_100 == V_101 ) {
F_9 ( 0 , V_5 -> V_8 -> V_13 + V_60 ) ;
F_9 ( 0x00 , V_5 -> V_8 -> V_13 + V_127 ) ;
F_9 ( 1 , V_5 -> V_8 -> V_13 + V_128 ) ;
F_9 ( 0x04 , V_5 -> V_8 -> V_13 + V_129 ) ;
F_9 ( 4 , V_5 -> V_8 -> V_13 + V_130 ) ;
F_9 ( 3 , V_5 -> V_8 -> V_13 + V_131 ) ;
F_9 ( 0xc0 , V_5 -> V_8 -> V_13 + V_132 ) ;
F_30 ( F_49 ( & V_94 -> V_109 ,
V_122 ) ,
V_5 -> V_8 -> V_13 + V_133 ) ;
F_9 ( 1 , V_5 -> V_8 -> V_13 + V_134 ) ;
F_9 ( 1 , V_5 -> V_8 -> V_13 + V_135 ) ;
F_9 ( 1 , V_5 -> V_8 -> V_13 + V_136 ) ;
F_9 ( 0x0b , V_5 -> V_8 -> V_13 + V_137 ) ;
F_9 ( 0x01 , V_5 -> V_8 -> V_13 + V_138 ) ;
F_39 ( 0 , V_5 -> V_8 -> V_13 + V_139 ) ;
F_9 ( 0 , V_5 -> V_8 -> V_13 + V_140 ) ;
} else {
F_9 ( 0 , V_5 -> V_8 -> V_13 + V_60 ) ;
F_9 ( 0x00 , V_5 -> V_8 -> V_13 + V_127 ) ;
F_9 ( 0 , V_5 -> V_8 -> V_13 + V_128 ) ;
F_9 ( 0x00 , V_5 -> V_8 -> V_13 + V_129 ) ;
F_9 ( 4 , V_5 -> V_8 -> V_13 + V_130 ) ;
if ( ! ( V_94 -> V_109 & V_111 ) ) {
F_9 ( 0 , V_5 -> V_8 -> V_13 + V_131 ) ;
} else {
F_9 ( 2 , V_5 -> V_8 -> V_13 + V_131 ) ;
}
F_9 ( 0x00 , V_5 -> V_8 -> V_13 + V_132 ) ;
F_30 ( 1 , V_5 -> V_8 -> V_13 + V_133 ) ;
F_9 ( 1 , V_5 -> V_8 -> V_13 + V_134 ) ;
F_9 ( 1 , V_5 -> V_8 -> V_13 + V_135 ) ;
F_9 ( 1 , V_5 -> V_8 -> V_13 + V_136 ) ;
F_9 ( 0x0C , V_5 -> V_8 -> V_13 + V_137 ) ;
F_9 ( 0x10 , V_5 -> V_8 -> V_13 + V_138 ) ;
F_39 ( 0 , V_5 -> V_8 -> V_13 + V_139 ) ;
F_9 ( 0x60 , V_5 -> V_8 -> V_13 + V_140 ) ;
}
if ( V_94 -> V_106 == V_105 ) {
F_30 ( V_94 -> V_115 ,
V_5 -> V_8 -> V_13 + V_141 ) ;
} else {
}
#ifdef F_53
F_9 ( V_65 | V_67 ,
V_5 -> V_8 -> V_13 + V_63 ) ;
{
int V_142 = F_54 ( V_3 , V_16 ) ;
if ( V_142 )
return V_142 ;
}
#else
F_9 ( 0x00 , V_5 -> V_8 -> V_13 + V_14 ) ;
#endif
F_9 ( 0x00 , V_5 -> V_8 -> V_13 + V_143 ) ;
F_9 ( 0xff , V_5 -> V_8 -> V_13 + V_63 ) ;
F_9 ( V_52 , V_5 -> V_8 -> V_13 + V_144 ) ;
F_9 ( 0x03 ,
V_5 -> V_8 -> V_13 + V_51 ) ;
if ( V_94 -> V_106 == V_107 ) {
V_5 -> V_145 = F_55 ( 0 ) | F_56 ( 7 ) ;
} else {
V_5 -> V_145 = V_146 | F_56 ( 7 ) ;
}
if ( V_94 -> V_97 == V_98 ) {
F_9 ( V_5 -> V_145 ,
V_5 -> V_8 -> V_13 + V_60 ) ;
V_16 -> V_17 -> V_147 = NULL ;
} else {
V_16 -> V_17 -> V_147 = V_148 ;
}
F_24 ( L_14 ) ;
return 0 ;
}
static int F_54 ( struct V_2 * V_3 , struct V_15 * V_16 )
{
int V_142 ;
unsigned long V_4 ;
V_142 = F_3 ( V_3 ) ;
if ( V_142 )
return V_142 ;
F_57 ( V_16 -> V_17 , V_16 -> V_17 -> V_149 ) ;
F_4 ( & V_5 -> V_6 , V_4 ) ;
if ( V_5 -> V_7 ) {
F_58 ( V_5 -> V_7 , 32 , 32 ) ;
F_59 ( V_5 -> V_7 ) ;
} else
V_142 = - V_150 ;
F_7 ( & V_5 -> V_6 , V_4 ) ;
return V_142 ;
}
static int V_148 ( struct V_2 * V_3 ,
struct V_15 * V_16 , unsigned int V_151 )
{
if ( V_151 != 0 )
return - V_85 ;
F_9 ( V_5 -> V_145 , V_5 -> V_8 -> V_13 + V_60 ) ;
V_16 -> V_17 -> V_147 = NULL ;
return 1 ;
}
static int F_16 ( struct V_2 * V_3 ,
struct V_15 * V_16 )
{
F_9 ( 0x00 ,
V_5 -> V_8 -> V_13 + V_51 ) ;
F_11 ( V_3 ) ;
return 0 ;
}
static int F_60 ( struct V_2 * V_3 ,
struct V_15 * V_16 , unsigned long V_152 )
{
int V_153 ;
V_153 = F_61 ( V_5 -> V_9 , V_16 -> V_17 ) ;
if ( V_153 < 0 )
return V_153 ;
memset ( V_16 -> V_17 -> V_154 , 0xaa , V_16 -> V_17 -> V_149 ) ;
return 0 ;
}
static int F_62 ( struct V_2 * V_3 , int V_155 ,
const T_2 * V_83 , T_3 V_156 )
{
static const int V_157 = 1000 ;
int V_158 ;
T_3 V_159 ;
F_39 ( 0x80 | V_155 ,
V_5 -> V_8 -> V_13 + V_160 ) ;
F_39 ( 0xc0 | V_155 ,
V_5 -> V_8 -> V_13 + V_160 ) ;
for ( V_158 = 0 ;
( F_63 ( V_5 -> V_8 -> V_13 +
V_161 ) & 0x2 ) == 0 && V_158 < V_157 ; ++ V_158 ) {
F_64 ( 1 ) ;
}
if ( V_158 == V_157 ) {
F_65 ( V_3 -> V_162 ,
L_15 ,
V_155 ) ;
return - V_150 ;
}
F_39 ( 0x80 | V_155 ,
V_5 -> V_8 -> V_13 + V_160 ) ;
for ( V_158 = 0 ;
F_63 ( V_5 -> V_8 -> V_13 + V_161 ) !=
0x3 && V_158 < V_157 ; ++ V_158 ) {
F_64 ( 1 ) ;
}
if ( V_158 == V_157 ) {
F_65 ( V_3 -> V_162 ,
L_16 ,
V_155 ) ;
return - V_150 ;
}
for ( V_159 = 0 ; V_159 + 1 < V_156 ; ) {
unsigned int V_163 = V_83 [ V_159 ++ ] ;
V_163 |= V_83 [ V_159 ++ ] << 8 ;
F_39 ( V_163 ,
V_5 -> V_8 -> V_13 + V_164 ) ;
for ( V_158 = 0 ;
( F_63 ( V_5 -> V_8 -> V_13 +
V_161 ) & 0x2 ) == 0
&& V_158 < V_157 ; ++ V_158 ) {
F_64 ( 1 ) ;
}
if ( V_158 == V_157 ) {
F_65 ( V_3 -> V_162 ,
L_17 ,
V_155 ) ;
return - V_150 ;
}
if ( F_66 () )
F_67 () ;
}
F_39 ( 0x0 , V_5 -> V_8 -> V_13 + V_160 ) ;
return 0 ;
}
static int F_68 ( struct V_2 * V_3 , int V_155 )
{
return F_62 ( V_3 , V_155 , NULL , 0 ) ;
}
static int F_69 ( struct V_2 * V_3 )
{
int V_153 ;
int V_158 ;
F_39 ( 0x0 , V_5 -> V_8 -> V_13 + V_160 ) ;
for ( V_158 = 0 ; V_158 < 3 ; ++ V_158 ) {
V_153 = F_68 ( V_3 , V_158 ) ;
if ( V_153 < 0 )
break;
}
F_39 ( 0x0 , V_5 -> V_8 -> V_13 + V_165 ) ;
return V_153 ;
}
static void F_70 ( struct V_2 * V_3 )
{
F_30 ( 0 , V_5 -> V_8 -> V_13 + V_166 ) ;
F_30 ( 0 , V_5 -> V_8 -> V_13 + V_167 ) ;
F_30 ( 0 , V_5 -> V_8 -> V_13 + V_168 ) ;
F_30 ( 0 , V_5 -> V_8 -> V_13 + V_169 ) ;
F_30 ( 0 , V_5 -> V_8 -> V_13 + V_170 ) ;
F_30 ( 0 , V_5 -> V_8 -> V_13 + V_171 ) ;
}
static int F_71 ( struct V_2 * V_3 )
{
int V_153 ;
const struct V_172 * V_173 ;
static const char * const V_174 [ 3 ] = {
V_175 ,
V_176 ,
V_177 ,
} ;
int V_84 ;
V_153 = F_69 ( V_3 ) ;
if ( V_153 < 0 )
return V_153 ;
for ( V_84 = 2 ; V_84 >= 0 ; V_84 -- ) {
V_153 = F_72 ( & V_173 , V_174 [ V_84 ] ,
& V_5 -> V_8 -> V_178 -> V_3 ) ;
if ( V_153 == 0 ) {
V_153 = F_62 ( V_3 , V_84 , V_173 -> V_83 , V_173 -> V_179 ) ;
if ( V_153 == 0 && V_84 == 2 )
F_70 ( V_3 ) ;
F_73 ( V_173 ) ;
}
if ( V_153 < 0 )
break;
}
return V_153 ;
}
static const struct V_180 *
F_74 ( struct V_181 * V_178 )
{
unsigned int V_182 = V_178 -> V_183 ;
unsigned int V_84 ;
for ( V_84 = 0 ; V_84 < F_75 ( V_184 ) ; V_84 ++ ) {
const struct V_180 * V_185 = & V_184 [ V_84 ] ;
if ( V_185 -> V_182 == V_182 )
return V_185 ;
}
return NULL ;
}
static int T_4 F_76 ( struct V_2 * V_3 ,
struct V_181 * V_178 )
{
struct V_15 * V_16 ;
int V_153 ;
unsigned int V_27 ;
V_153 = F_77 ( V_3 , sizeof( struct V_186 ) ) ;
if ( V_153 < 0 )
return V_153 ;
F_78 ( & V_5 -> V_6 ) ;
V_3 -> V_187 = F_74 ( V_178 ) ;
if ( ! V_3 -> V_187 )
return - V_188 ;
V_5 -> V_8 = F_79 ( V_178 ) ;
if ( ! V_5 -> V_8 )
return - V_189 ;
V_153 = F_80 ( V_5 -> V_8 ) ;
if ( V_153 < 0 ) {
F_65 ( V_3 -> V_162 , L_18 ) ;
return V_153 ;
}
F_81 ( V_3 , & V_5 -> V_8 -> V_178 -> V_3 ) ;
V_5 -> V_9 = F_82 ( V_5 -> V_8 ) ;
if ( V_5 -> V_9 == NULL )
return - V_189 ;
V_3 -> V_190 = V_191 -> V_192 ;
V_27 = F_83 ( V_5 -> V_8 ) ;
if ( V_191 -> V_193 ) {
V_153 = F_71 ( V_3 ) ;
if ( V_153 < 0 )
return V_153 ;
}
V_153 = F_84 ( V_3 , 1 ) ;
if ( V_153 )
return V_153 ;
F_85 ( V_3 -> V_162 , L_19 , V_3 -> V_190 ,
F_23 ( V_5 -> V_8 -> V_13 + V_194 ) ) ;
V_16 = & V_3 -> V_29 [ 0 ] ;
V_3 -> V_195 = V_16 ;
V_16 -> type = V_196 ;
V_16 -> V_197 =
V_198 | V_199 | V_200 | V_201 |
V_202 ;
V_16 -> V_203 = 32 ;
V_16 -> V_204 = & V_205 ;
V_16 -> V_206 = 1 ;
V_16 -> V_207 = & F_40 ;
V_16 -> V_208 = & F_43 ;
V_16 -> V_209 = & F_50 ;
V_16 -> V_210 = & F_45 ;
V_16 -> V_211 = & F_16 ;
V_16 -> V_212 = 32 ;
V_16 -> V_213 = & F_60 ;
V_16 -> V_214 = V_215 ;
V_16 -> V_216 = & F_18 ;
F_30 ( 0 , V_5 -> V_8 -> V_13 + F_44 ( 0 ) ) ;
F_30 ( 0 , V_5 -> V_8 -> V_13 + F_42 ( 0 ) ) ;
F_30 ( 0 , V_5 -> V_8 -> V_13 + F_86 ( 0 ) ) ;
F_9 ( 0x00 ,
V_5 -> V_8 -> V_13 +
V_51 ) ;
V_153 = F_87 ( V_27 , F_22 , V_217 ,
L_20 , V_3 ) ;
if ( V_153 < 0 )
F_65 ( V_3 -> V_162 , L_21 ) ;
V_3 -> V_27 = V_27 ;
return 0 ;
}
static void F_88 ( struct V_2 * V_3 )
{
if ( V_3 -> V_27 )
F_89 ( V_3 -> V_27 , V_3 ) ;
if ( V_5 ) {
if ( V_5 -> V_9 ) {
F_90 ( V_5 -> V_9 ) ;
V_5 -> V_9 = NULL ;
}
if ( V_5 -> V_8 ) {
F_91 ( V_5 -> V_8 ) ;
F_92 ( V_5 -> V_8 ) ;
}
}
}
static int T_4 F_93 ( struct V_181 * V_3 ,
const struct V_218 * V_219 )
{
return F_94 ( V_3 , & V_220 ) ;
}
static void T_5 F_95 ( struct V_181 * V_3 )
{
F_96 ( V_3 ) ;
}

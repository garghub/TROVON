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
static int F_15 ( int V_11 , int V_15 , int V_16 , unsigned long V_17 )
{
if ( V_11 ) {
F_9 ( V_16 , ( void * ) ( V_17 + V_15 ) ) ;
return 0 ;
} else {
return F_16 ( ( void * ) ( V_17 + V_15 ) ) ;
}
}
void F_17 ( struct V_2 * V_3 , struct V_18 * V_19 )
{
if ( V_19 ->
V_20 -> V_21 & ( V_22 | V_23 |
V_24 ) ) {
F_18 ( V_3 , V_19 ) ;
}
F_19 ( V_3 , V_19 ) ;
}
static int F_20 ( struct V_2 * V_3 , struct V_18 * V_19 )
{
unsigned long V_25 ;
int V_26 ;
F_4 ( & V_3 -> V_27 , V_25 ) ;
F_21 ( & V_5 -> V_6 ) ;
if ( V_5 -> V_7 )
F_22 ( V_5 -> V_7 , V_19 -> V_20 ) ;
F_23 ( & V_5 -> V_6 ) ;
V_26 = V_19 -> V_20 -> V_28 - V_19 -> V_20 -> V_29 ;
F_7 ( & V_3 -> V_27 , V_25 ) ;
return V_26 ;
}
static T_1 F_24 ( int V_30 , void * V_31 )
{
struct V_2 * V_3 = V_31 ;
struct V_18 * V_19 = V_3 -> V_32 ;
struct V_33 * V_20 = V_19 -> V_20 ;
struct V_34 * V_8 = V_5 -> V_8 ;
long int V_35 = 0 ;
short V_36 = 0 ;
short V_37 = 0 ;
int V_4 ;
int V_38 ;
int V_39 = 0 ;
unsigned int V_40 = 0 ;
if ( V_3 -> V_41 == 0 ) {
return V_42 ;
}
F_21 ( & V_3 -> V_27 ) ;
V_38 = F_16 ( V_5 -> V_8 -> V_13 +
V_43 ) ;
V_4 = F_16 ( V_5 -> V_8 -> V_13 + V_44 ) ;
F_25 ( L_2 ,
V_38 , V_4 ) ;
F_26 ( V_4 ) ;
F_27 ( V_38 ) ;
F_21 ( & V_5 -> V_6 ) ;
if ( V_5 -> V_7 )
V_40 = F_28 ( V_5 -> V_7 ) ;
#ifdef F_29
F_30 ( V_40 ) ;
#endif
if ( V_40 & V_45 ) {
if ( V_40 & V_46 ) {
F_31 ( V_47 ,
V_8 -> V_48 +
F_32 ( V_5 -> V_7 -> V_1 ) ) ;
F_22 ( V_5 -> V_7 , V_19 -> V_20 ) ;
}
if ( V_40 & ~ ( V_45 | V_46 | V_49 | V_50 |
V_51 | V_52 ) ) {
F_25 ( L_3 ) ;
V_20 -> V_21 |= V_22 | V_23 ;
F_33 ( V_3 -> V_30 ) ;
}
}
F_23 ( & V_5 -> V_6 ) ;
while ( V_38 & V_53 ) {
V_39 ++ ;
if ( V_39 > 20 ) {
F_25 ( L_4 ) ;
F_9 ( 0x00 ,
V_5 -> V_8 -> V_13 +
V_54 ) ;
break;
}
V_4 &= V_55 ;
if ( V_4 & V_56 ) {
while ( V_4 & V_56 ) {
V_39 ++ ;
if ( V_39 > 100 ) {
F_25 ( L_4 ) ;
F_9 ( 0x00 ,
V_5 -> V_8 -> V_13 +
V_54
) ;
goto V_57;
}
V_35 =
F_34 ( V_5 -> V_8 -> V_13 +
V_58 ) ;
V_36 = V_35 & 0xffff ;
V_37 = ( V_35 & 0xffff0000 ) >> 16 ;
F_35 ( V_20 , V_36 ) ;
F_35 ( V_20 , V_37 ) ;
V_4 = F_16 ( V_5 -> V_8 -> V_13 +
V_44 ) ;
}
V_20 -> V_21 |= V_59 ;
}
if ( V_4 & V_60 ) {
F_25 ( L_5 ) ;
F_9 ( V_61 ,
V_5 -> V_8 -> V_13 +
V_62 ) ;
V_20 -> V_21 |= V_22 ;
F_9 ( 0x00 , V_5 -> V_8 -> V_13 + V_63 ) ;
break;
} else if ( V_4 & V_64 ) {
F_25 ( L_6 ) ;
F_9 ( V_65 ,
V_5 -> V_8 -> V_13 +
V_66 ) ;
V_20 -> V_21 |= V_22 | V_23 ;
break;
} else if ( V_4 & V_67 ) {
F_25 ( L_7 ) ;
F_9 ( V_68 ,
V_5 -> V_8 -> V_13 +
V_66 ) ;
V_20 -> V_21 |= V_22 ;
} else if ( V_4 & V_69 ) {
F_25 ( L_8 ) ;
F_9 ( V_70 ,
V_5 -> V_8 -> V_13 +
V_66 ) ;
V_20 -> V_21 |= V_22 ;
}
#if 0
else {
printk("ni_pcidio: unknown interrupt\n");
async->events |= COMEDI_CB_ERROR | COMEDI_CB_EOA;
writeb(0x00,
devpriv->mite->daq_io_addr +
Master_DMA_And_Interrupt_Control);
}
#endif
V_4 = F_16 ( V_5 -> V_8 -> V_13 + V_44 ) ;
V_38 = F_16 ( V_5 -> V_8 -> V_13 +
V_43 ) ;
}
V_57:
F_17 ( V_3 , V_19 ) ;
#if 0
if (!tag) {
writeb(0x03,
devpriv->mite->daq_io_addr +
Master_DMA_And_Interrupt_Control);
}
#endif
F_23 ( & V_3 -> V_27 ) ;
return V_71 ;
}
static void F_26 ( unsigned int V_4 )
{
int V_72 ;
F_36 ( V_73 L_9 ) ;
for ( V_72 = 7 ; V_72 >= 0 ; V_72 -- ) {
if ( V_4 & ( 1 << V_72 ) )
F_36 ( L_10 , V_74 [ V_72 ] ) ;
}
F_36 ( L_11 ) ;
}
static void F_27 ( unsigned int V_4 )
{
int V_72 ;
F_36 ( V_73 L_12 ) ;
for ( V_72 = 7 ; V_72 >= 0 ; V_72 -- ) {
if ( V_4 & ( 1 << V_72 ) )
F_36 ( L_10 , V_75 [ V_72 ] ) ;
}
F_36 ( L_11 ) ;
}
static void F_37 ( struct V_2 * V_3 )
{
int V_76 , V_77 ;
static int V_78 ;
struct V_79 V_80 ;
F_38 ( & V_80 ) ;
V_76 = F_16 ( V_5 -> V_8 -> V_13 + V_81 ) ;
V_77 = F_16 ( V_5 -> V_8 -> V_13 + V_44 ) ;
if ( V_78 < 10 ) {
F_25 ( L_13 , V_76 , V_77 ,
( int ) V_80 . V_82 ) ;
}
while ( V_77 & 1 ) {
F_39 ( 0xff , V_5 -> V_8 -> V_13 + V_58 ) ;
V_77 = F_16 ( V_5 -> V_8 -> V_13 + V_44 ) ;
}
V_77 = F_16 ( V_5 -> V_8 -> V_13 + V_44 ) ;
if ( V_78 < 10 ) {
F_25 ( L_14 , V_77 ) ;
V_78 ++ ;
}
}
static int F_40 ( struct V_2 * V_3 ,
struct V_18 * V_19 ,
struct V_83 * V_84 , unsigned int * V_16 )
{
if ( V_84 -> V_85 != 1 )
return - V_86 ;
switch ( V_16 [ 0 ] ) {
case V_87 :
V_19 -> V_88 |= 1 << F_41 ( V_84 -> V_89 ) ;
break;
case V_90 :
V_19 -> V_88 &= ~ ( 1 << F_41 ( V_84 -> V_89 ) ) ;
break;
case V_91 :
V_16 [ 1 ] =
( V_19 ->
V_88 & ( 1 << F_41 ( V_84 -> V_89 ) ) ) ? V_92 :
V_12 ;
return V_84 -> V_85 ;
break;
default:
return - V_86 ;
}
F_31 ( V_19 -> V_88 , V_5 -> V_8 -> V_13 + F_42 ( 0 ) ) ;
return 1 ;
}
static int F_43 ( struct V_2 * V_3 ,
struct V_18 * V_19 ,
struct V_83 * V_84 , unsigned int * V_16 )
{
if ( V_84 -> V_85 != 2 )
return - V_86 ;
if ( V_16 [ 0 ] ) {
V_19 -> V_93 &= ~ V_16 [ 0 ] ;
V_19 -> V_93 |= ( V_16 [ 0 ] & V_16 [ 1 ] ) ;
F_31 ( V_19 -> V_93 , V_5 -> V_8 -> V_13 + F_44 ( 0 ) ) ;
}
V_16 [ 1 ] = F_34 ( V_5 -> V_8 -> V_13 + F_44 ( 0 ) ) ;
return 2 ;
}
static int F_45 ( struct V_2 * V_3 ,
struct V_18 * V_19 , struct V_94 * V_95 )
{
int V_96 = 0 ;
int V_97 ;
V_97 = V_95 -> V_98 ;
V_95 -> V_98 &= V_99 | V_100 ;
if ( ! V_95 -> V_98 || V_97 != V_95 -> V_98 )
V_96 ++ ;
V_97 = V_95 -> V_101 ;
V_95 -> V_101 &= V_102 | V_103 ;
if ( ! V_95 -> V_101 || V_97 != V_95 -> V_101 )
V_96 ++ ;
V_97 = V_95 -> V_104 ;
V_95 -> V_104 &= V_99 ;
if ( ! V_95 -> V_104 || V_97 != V_95 -> V_104 )
V_96 ++ ;
V_97 = V_95 -> V_105 ;
V_95 -> V_105 &= V_106 ;
if ( ! V_95 -> V_105 || V_97 != V_95 -> V_105 )
V_96 ++ ;
V_97 = V_95 -> V_107 ;
V_95 -> V_107 &= V_106 | V_108 ;
if ( ! V_95 -> V_107 || V_97 != V_95 -> V_107 )
V_96 ++ ;
if ( V_96 )
return 1 ;
if ( V_95 -> V_98 != V_99 && V_95 -> V_98 != V_100 )
V_96 ++ ;
if ( V_95 -> V_101 != V_102 &&
V_95 -> V_101 != V_103 )
V_96 ++ ;
if ( V_96 )
return 2 ;
if ( V_95 -> V_109 != 0 ) {
V_95 -> V_109 = 0 ;
V_96 ++ ;
}
#define F_46 (TIMER_BASE)
if ( V_95 -> V_101 == V_102 ) {
if ( V_95 -> V_110 < F_46 ) {
V_95 -> V_110 = F_46 ;
V_96 ++ ;
}
} else {
if ( ( V_95 -> V_110 & ~ ( V_111 | V_112 ) ) != 0 ) {
V_95 -> V_110 &= ( V_111 | V_112 ) ;
V_96 ++ ;
}
}
if ( V_95 -> V_113 != 0 ) {
V_95 -> V_113 = 0 ;
V_96 ++ ;
}
if ( V_95 -> V_114 != V_95 -> V_115 ) {
V_95 -> V_114 = V_95 -> V_115 ;
V_96 ++ ;
}
if ( V_95 -> V_107 == V_106 ) {
} else {
if ( V_95 -> V_116 != 0 ) {
V_95 -> V_116 = 0 ;
V_96 ++ ;
}
}
if ( V_96 )
return 3 ;
if ( V_95 -> V_101 == V_102 ) {
V_97 = V_95 -> V_110 ;
F_47 ( & V_95 -> V_110 ,
V_95 -> V_4 & V_117 ) ;
if ( V_97 != V_95 -> V_110 )
V_96 ++ ;
}
if ( V_96 )
return 4 ;
return 0 ;
}
static int F_47 ( int * V_118 , int V_119 )
{
int V_120 , V_121 ;
V_121 = V_122 ;
switch ( V_119 ) {
case V_123 :
default:
V_120 = ( * V_118 + V_121 / 2 ) / V_121 ;
break;
case V_124 :
V_120 = ( * V_118 ) / V_121 ;
break;
case V_125 :
V_120 = ( * V_118 + V_121 - 1 ) / V_121 ;
break;
}
* V_118 = V_121 * V_120 ;
return V_120 ;
}
static int F_48 ( struct V_2 * V_3 , struct V_18 * V_19 )
{
struct V_94 * V_95 = & V_19 -> V_20 -> V_95 ;
F_31 ( 0x0000 , V_5 -> V_8 -> V_13 + F_42 ( 0 ) ) ;
if ( 1 ) {
F_9 ( 0x0f , V_5 -> V_8 -> V_13 + V_126 ) ;
F_9 ( F_49 ( 0 ) | F_50 ( 0 ) ,
V_5 -> V_8 -> V_13 + V_127 ) ;
} else {
F_9 ( 0x03 , V_5 -> V_8 -> V_13 + V_126 ) ;
F_9 ( F_49 ( 3 ) | F_50 ( 0 ) ,
V_5 -> V_8 -> V_13 + V_127 ) ;
}
if ( V_95 -> V_101 == V_102 ) {
F_9 ( 0 , V_5 -> V_8 -> V_13 + V_63 ) ;
F_9 ( 0x00 , V_5 -> V_8 -> V_13 + V_128 ) ;
F_9 ( 1 , V_5 -> V_8 -> V_13 + V_129 ) ;
F_9 ( 0x04 , V_5 -> V_8 -> V_13 + V_130 ) ;
F_9 ( 4 , V_5 -> V_8 -> V_13 + V_131 ) ;
F_9 ( 3 , V_5 -> V_8 -> V_13 + V_132 ) ;
F_9 ( 0xc0 , V_5 -> V_8 -> V_13 + V_133 ) ;
F_31 ( F_47 ( & V_95 -> V_110 ,
V_123 ) ,
V_5 -> V_8 -> V_13 + V_134 ) ;
F_9 ( 1 , V_5 -> V_8 -> V_13 + V_135 ) ;
F_9 ( 1 , V_5 -> V_8 -> V_13 + V_136 ) ;
F_9 ( 1 , V_5 -> V_8 -> V_13 + V_137 ) ;
F_9 ( 0x0b , V_5 -> V_8 -> V_13 + V_138 ) ;
F_9 ( 0x01 , V_5 -> V_8 -> V_13 + V_139 ) ;
F_39 ( 0 , V_5 -> V_8 -> V_13 + V_140 ) ;
F_9 ( 0 , V_5 -> V_8 -> V_13 + V_141 ) ;
} else {
F_9 ( 0 , V_5 -> V_8 -> V_13 + V_63 ) ;
F_9 ( 0x00 , V_5 -> V_8 -> V_13 + V_128 ) ;
F_9 ( 0 , V_5 -> V_8 -> V_13 + V_129 ) ;
F_9 ( 0x00 , V_5 -> V_8 -> V_13 + V_130 ) ;
F_9 ( 4 , V_5 -> V_8 -> V_13 + V_131 ) ;
if ( ! ( V_95 -> V_110 & V_112 ) ) {
F_9 ( 0 , V_5 -> V_8 -> V_13 + V_132 ) ;
} else {
F_9 ( 2 , V_5 -> V_8 -> V_13 + V_132 ) ;
}
F_9 ( 0x00 , V_5 -> V_8 -> V_13 + V_133 ) ;
F_31 ( 1 , V_5 -> V_8 -> V_13 + V_134 ) ;
F_9 ( 1 , V_5 -> V_8 -> V_13 + V_135 ) ;
F_9 ( 1 , V_5 -> V_8 -> V_13 + V_136 ) ;
F_9 ( 1 , V_5 -> V_8 -> V_13 + V_137 ) ;
F_9 ( 0x0C , V_5 -> V_8 -> V_13 + V_138 ) ;
F_9 ( 0x10 , V_5 -> V_8 -> V_13 + V_139 ) ;
F_39 ( 0 , V_5 -> V_8 -> V_13 + V_140 ) ;
F_9 ( 0x60 , V_5 -> V_8 -> V_13 + V_141 ) ;
}
if ( V_95 -> V_107 == V_106 ) {
F_31 ( V_95 -> V_116 ,
V_5 -> V_8 -> V_13 + V_142 ) ;
} else {
}
#ifdef F_51
F_9 ( V_68 | V_70 ,
V_5 -> V_8 -> V_13 + V_66 ) ;
{
int V_143 = F_52 ( V_3 , V_19 ) ;
if ( V_143 )
return V_143 ;
}
#else
F_9 ( 0x00 , V_5 -> V_8 -> V_13 + V_14 ) ;
#endif
F_9 ( 0x00 , V_5 -> V_8 -> V_13 + V_144 ) ;
F_9 ( 0xff , V_5 -> V_8 -> V_13 + V_66 ) ;
F_9 ( V_55 , V_5 -> V_8 -> V_13 + V_145 ) ;
F_9 ( 0x03 ,
V_5 -> V_8 -> V_13 + V_54 ) ;
if ( V_95 -> V_107 == V_108 ) {
V_5 -> V_146 = F_53 ( 0 ) | F_54 ( 7 ) ;
} else {
V_5 -> V_146 = V_147 | F_54 ( 7 ) ;
}
if ( V_95 -> V_98 == V_99 ) {
F_9 ( V_5 -> V_146 ,
V_5 -> V_8 -> V_13 + V_63 ) ;
V_19 -> V_20 -> V_148 = NULL ;
} else {
V_19 -> V_20 -> V_148 = V_149 ;
}
F_25 ( L_15 ) ;
return 0 ;
}
static int F_52 ( struct V_2 * V_3 , struct V_18 * V_19 )
{
int V_143 ;
unsigned long V_4 ;
V_143 = F_3 ( V_3 ) ;
if ( V_143 )
return V_143 ;
F_55 ( V_19 -> V_20 , V_19 -> V_20 -> V_150 ) ;
F_4 ( & V_5 -> V_6 , V_4 ) ;
if ( V_5 -> V_7 ) {
F_56 ( V_5 -> V_7 , 32 , 32 ) ;
F_57 ( V_5 -> V_7 ) ;
} else
V_143 = - V_151 ;
F_7 ( & V_5 -> V_6 , V_4 ) ;
return V_143 ;
}
static int V_149 ( struct V_2 * V_3 ,
struct V_18 * V_19 , unsigned int V_152 )
{
if ( V_152 != 0 )
return - V_86 ;
F_9 ( V_5 -> V_146 , V_5 -> V_8 -> V_13 + V_63 ) ;
V_19 -> V_20 -> V_148 = NULL ;
return 1 ;
}
static int F_18 ( struct V_2 * V_3 ,
struct V_18 * V_19 )
{
F_9 ( 0x00 ,
V_5 -> V_8 -> V_13 + V_54 ) ;
F_11 ( V_3 ) ;
return 0 ;
}
static int F_58 ( struct V_2 * V_3 ,
struct V_18 * V_19 , unsigned long V_153 )
{
int V_154 ;
V_154 = F_59 ( V_5 -> V_9 , V_19 -> V_20 ) ;
if ( V_154 < 0 )
return V_154 ;
memset ( V_19 -> V_20 -> V_155 , 0xaa , V_19 -> V_20 -> V_150 ) ;
return 0 ;
}
static int F_60 ( struct V_2 * V_3 , int V_156 ,
T_2 * V_16 , int V_157 )
{
static const int V_158 = 1000 ;
int V_72 , V_159 ;
F_39 ( 0x80 | V_156 ,
V_5 -> V_8 -> V_13 + V_160 ) ;
F_39 ( 0xc0 | V_156 ,
V_5 -> V_8 -> V_13 + V_160 ) ;
for ( V_72 = 0 ;
( F_61 ( V_5 -> V_8 -> V_13 +
V_161 ) & 0x2 ) == 0 && V_72 < V_158 ; ++ V_72 ) {
F_62 ( 1 ) ;
}
if ( V_72 == V_158 ) {
F_36 ( V_162 L_16
L_17 , V_156 ) ;
return - V_151 ;
}
F_39 ( 0x80 | V_156 ,
V_5 -> V_8 -> V_13 + V_160 ) ;
for ( V_72 = 0 ;
F_61 ( V_5 -> V_8 -> V_13 + V_161 ) !=
0x3 && V_72 < V_158 ; ++ V_72 ) {
F_62 ( 1 ) ;
}
if ( V_72 == V_158 ) {
F_36 ( V_162 L_16
L_18 , V_156 ) ;
return - V_151 ;
}
for ( V_159 = 0 ; V_159 + 1 < V_157 ; ) {
unsigned int V_163 = V_16 [ V_159 ++ ] ;
V_163 |= V_16 [ V_159 ++ ] << 8 ;
F_39 ( V_163 ,
V_5 -> V_8 -> V_13 + V_164 ) ;
for ( V_72 = 0 ;
( F_61 ( V_5 -> V_8 -> V_13 +
V_161 ) & 0x2 ) == 0
&& V_72 < V_158 ; ++ V_72 ) {
F_62 ( 1 ) ;
}
if ( V_72 == V_158 ) {
F_36 ( L_19 ,
V_156 ) ;
return - V_151 ;
}
if ( F_63 () )
F_64 () ;
}
F_39 ( 0x0 , V_5 -> V_8 -> V_13 + V_160 ) ;
return 0 ;
}
static int F_65 ( struct V_2 * V_3 , int V_156 )
{
return F_60 ( V_3 , V_156 , NULL , 0 ) ;
}
static int F_66 ( struct V_2 * V_3 )
{
int V_154 ;
int V_72 ;
F_39 ( 0x0 , V_5 -> V_8 -> V_13 + V_160 ) ;
for ( V_72 = 0 ; V_72 < 3 ; ++ V_72 ) {
V_154 = F_65 ( V_3 , V_72 ) ;
if ( V_154 < 0 )
break;
}
F_39 ( 0x0 , V_5 -> V_8 -> V_13 + V_165 ) ;
return V_154 ;
}
static void F_67 ( struct V_2 * V_3 )
{
F_31 ( 0 , V_5 -> V_8 -> V_13 + V_166 ) ;
F_31 ( 0 , V_5 -> V_8 -> V_13 + V_167 ) ;
F_31 ( 0 , V_5 -> V_8 -> V_13 + V_168 ) ;
F_31 ( 0 , V_5 -> V_8 -> V_13 + V_169 ) ;
F_31 ( 0 , V_5 -> V_8 -> V_13 + V_170 ) ;
F_31 ( 0 , V_5 -> V_8 -> V_13 + V_171 ) ;
}
static int F_68 ( struct V_2 * V_3 , int V_172 [] )
{
int V_154 ;
void * V_173 , * V_174 , * V_175 ;
int V_176 , V_177 , V_178 ;
if ( V_172 [ V_179 ] == 0 )
return 0 ;
V_154 = F_66 ( V_3 ) ;
if ( V_154 < 0 )
return V_154 ;
V_173 = F_69 ( V_172 , 0 ) ;
V_176 = V_172 [ V_180 ] ;
V_154 = F_60 ( V_3 , 2 , V_173 , V_176 ) ;
if ( V_154 < 0 )
return V_154 ;
F_67 ( V_3 ) ;
V_174 = F_69 ( V_172 , 1 ) ;
V_177 = V_172 [ V_181 ] ;
V_154 = F_60 ( V_3 , 0 , V_174 , V_177 ) ;
if ( V_154 < 0 )
return V_154 ;
V_175 = F_69 ( V_172 , 2 ) ;
V_178 = V_172 [ V_182 ] ;
V_154 = F_60 ( V_3 , 1 , V_175 , V_178 ) ;
if ( V_154 < 0 )
return V_154 ;
return 0 ;
}
static int F_70 ( struct V_2 * V_3 , int V_183 , int V_184 )
{
struct V_34 * V_8 ;
int V_72 ;
for ( V_8 = V_185 ; V_8 ; V_8 = V_8 -> V_186 ) {
if ( V_8 -> V_187 )
continue;
if ( V_183 || V_184 ) {
if ( V_183 != V_8 -> V_188 -> V_183 -> V_189 ||
V_184 != F_71 ( V_8 -> V_188 -> V_190 ) )
continue;
}
for ( V_72 = 0 ; V_72 < V_191 ; V_72 ++ ) {
if ( F_72 ( V_8 ) == V_192 [ V_72 ] . V_193 ) {
V_3 -> V_194 = V_192 + V_72 ;
V_5 -> V_8 = V_8 ;
return 0 ;
}
}
}
F_36 ( V_162 L_20 ) ;
F_73 () ;
return - V_151 ;
}
static int F_74 ( struct V_2 * V_3 , struct V_195 * V_196 )
{
struct V_18 * V_19 ;
int V_72 ;
int V_154 ;
int V_197 ;
unsigned int V_30 ;
F_36 ( V_73 L_21 , V_3 -> V_198 ) ;
V_154 = F_75 ( V_3 , sizeof( struct V_199 ) ) ;
if ( V_154 < 0 )
return V_154 ;
F_76 ( & V_5 -> V_6 ) ;
V_154 = F_70 ( V_3 , V_196 -> V_172 [ 0 ] , V_196 -> V_172 [ 1 ] ) ;
if ( V_154 < 0 )
return V_154 ;
V_154 = F_77 ( V_5 -> V_8 ) ;
if ( V_154 < 0 ) {
F_36 ( V_162 L_22 ) ;
return V_154 ;
}
F_78 ( V_3 , & V_5 -> V_8 -> V_188 -> V_3 ) ;
V_5 -> V_9 = F_79 ( V_5 -> V_8 ) ;
if ( V_5 -> V_9 == NULL )
return - V_200 ;
V_3 -> V_201 = V_202 -> V_203 ;
V_30 = F_80 ( V_5 -> V_8 ) ;
F_36 ( V_73 L_10 , V_3 -> V_201 ) ;
if ( V_202 -> V_204 ) {
V_154 = F_68 ( V_3 , V_196 -> V_172 ) ;
if ( V_154 < 0 )
return V_154 ;
}
if ( ! V_202 -> V_205 )
V_197 = V_202 -> V_206 ;
else
V_197 = 1 ;
V_154 = F_81 ( V_3 , V_197 ) ;
if ( V_154 < 0 )
return V_154 ;
if ( ! V_202 -> V_205 ) {
for ( V_72 = 0 ; V_72 < V_202 -> V_206 ; V_72 ++ ) {
F_82 ( V_3 , V_3 -> V_32 + V_72 ,
F_15 ,
( unsigned long ) ( V_5 -> V_8 ->
V_13 +
F_83 ( V_72 ) ) ) ;
}
} else {
F_36 ( V_73 L_23 ,
F_16 ( V_5 -> V_8 -> V_13 + V_207 ) ) ;
V_19 = V_3 -> V_32 + 0 ;
V_3 -> V_208 = V_19 ;
V_19 -> type = V_209 ;
V_19 -> V_210 =
V_211 | V_212 | V_213 | V_214 |
V_215 ;
V_19 -> V_216 = 32 ;
V_19 -> V_217 = & V_218 ;
V_19 -> V_219 = 1 ;
V_19 -> V_220 = & F_40 ;
V_19 -> V_221 = & F_43 ;
V_19 -> V_222 = & F_48 ;
V_19 -> V_223 = & F_45 ;
V_19 -> V_224 = & F_18 ;
V_19 -> V_225 = 32 ;
V_19 -> V_226 = & F_58 ;
V_19 -> V_227 = V_228 ;
V_19 -> V_229 = & F_20 ;
F_31 ( 0 , V_5 -> V_8 -> V_13 + F_44 ( 0 ) ) ;
F_31 ( 0 , V_5 -> V_8 -> V_13 + F_42 ( 0 ) ) ;
F_31 ( 0 , V_5 -> V_8 -> V_13 + F_84 ( 0 ) ) ;
F_9 ( 0x00 ,
V_5 -> V_8 -> V_13 +
V_54 ) ;
V_154 = F_85 ( V_30 , F_24 , V_230 ,
L_24 , V_3 ) ;
if ( V_154 < 0 )
F_36 ( V_162 L_25 ) ;
V_3 -> V_30 = V_30 ;
}
F_36 ( L_11 ) ;
return 0 ;
}
static void F_86 ( struct V_2 * V_3 )
{
int V_72 ;
if ( V_202 && ! V_202 -> V_205 ) {
for ( V_72 = 0 ; V_72 < V_202 -> V_206 ; V_72 ++ )
F_87 ( V_3 , V_3 -> V_32 + V_72 ) ;
}
if ( V_3 -> V_30 )
F_88 ( V_3 -> V_30 , V_3 ) ;
if ( V_5 ) {
if ( V_5 -> V_9 ) {
F_89 ( V_5 -> V_9 ) ;
V_5 -> V_9 = NULL ;
}
if ( V_5 -> V_8 )
F_90 ( V_5 -> V_8 ) ;
}
}
static int T_3 F_91 ( struct V_231 * V_3 ,
const struct V_232 * V_233 )
{
return F_92 ( V_3 , & V_234 ) ;
}
static void T_4 F_93 ( struct V_231 * V_3 )
{
F_94 ( V_3 ) ;
}

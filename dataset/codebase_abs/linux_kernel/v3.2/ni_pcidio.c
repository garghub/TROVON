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
F_9 ( F_1 ( V_5 -> V_7 -> V_1 ) |
F_2 ( V_5 -> V_7 -> V_1 ) ,
V_5 -> V_8 -> V_11 + V_12 ) ;
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
V_5 -> V_8 -> V_11 + V_12 ) ;
F_10 () ;
}
F_7 ( & V_5 -> V_6 , V_4 ) ;
}
static int F_15 ( int V_13 , int V_14 , int V_15 , unsigned long V_16 )
{
if ( V_13 ) {
F_9 ( V_15 , ( void * ) ( V_16 + V_14 ) ) ;
return 0 ;
} else {
return F_16 ( ( void * ) ( V_16 + V_14 ) ) ;
}
}
void F_17 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
if ( V_18 ->
V_19 -> V_20 & ( V_21 | V_22 |
V_23 ) ) {
F_18 ( V_3 , V_18 ) ;
}
F_19 ( V_3 , V_18 ) ;
}
static T_1 F_20 ( int V_24 , void * V_25 )
{
struct V_2 * V_3 = V_25 ;
struct V_17 * V_18 = V_3 -> V_26 ;
struct V_27 * V_19 = V_18 -> V_19 ;
struct V_28 * V_8 = V_5 -> V_8 ;
long int V_29 = 0 ;
short V_30 = 0 ;
short V_31 = 0 ;
int V_4 ;
int V_32 ;
int V_33 = 0 ;
unsigned int V_34 = 0 ;
unsigned long V_35 ;
if ( V_3 -> V_36 == 0 ) {
return V_37 ;
}
V_32 = F_16 ( V_5 -> V_8 -> V_11 +
V_38 ) ;
V_4 = F_16 ( V_5 -> V_8 -> V_11 + V_39 ) ;
F_21 ( L_2 ,
V_32 , V_4 ) ;
F_22 ( V_4 ) ;
F_23 ( V_32 ) ;
F_4 ( & V_5 -> V_6 , V_35 ) ;
if ( V_5 -> V_7 )
V_34 = F_24 ( V_5 -> V_7 ) ;
#ifdef F_25
F_26 ( V_34 ) ;
#endif
if ( V_34 & V_40 ) {
if ( V_34 & V_41 ) {
F_27 ( V_42 ,
V_8 -> V_43 +
F_28 ( V_5 -> V_7 -> V_1 ) ) ;
F_29 ( V_5 -> V_7 , V_18 -> V_19 ) ;
}
if ( V_34 & ~ ( V_40 | V_41 | V_44 | V_45 |
V_46 | V_47 ) ) {
F_21 ( L_3 ) ;
V_19 -> V_20 |= V_21 | V_22 ;
F_30 ( V_3 -> V_24 ) ;
}
}
F_7 ( & V_5 -> V_6 , V_35 ) ;
while ( V_32 & V_48 ) {
V_33 ++ ;
if ( V_33 > 20 ) {
F_21 ( L_4 ) ;
F_9 ( 0x00 ,
V_5 -> V_8 -> V_11 +
V_49 ) ;
break;
}
V_4 &= V_50 ;
if ( V_4 & V_51 ) {
while ( V_4 & V_51 ) {
V_33 ++ ;
if ( V_33 > 100 ) {
F_21 ( L_4 ) ;
F_9 ( 0x00 ,
V_5 -> V_8 -> V_11 +
V_49
) ;
goto V_52;
}
V_29 =
F_31 ( V_5 -> V_8 -> V_11 +
V_53 ) ;
V_30 = V_29 & 0xffff ;
V_31 = ( V_29 & 0xffff0000 ) >> 16 ;
F_32 ( V_19 , V_30 ) ;
F_32 ( V_19 , V_31 ) ;
V_4 = F_16 ( V_5 -> V_8 -> V_11 +
V_39 ) ;
}
V_19 -> V_20 |= V_54 ;
}
if ( V_4 & V_55 ) {
F_21 ( L_5 ) ;
F_9 ( V_56 ,
V_5 -> V_8 -> V_11 +
V_57 ) ;
V_19 -> V_20 |= V_21 ;
F_9 ( 0x00 , V_5 -> V_8 -> V_11 + V_58 ) ;
break;
} else if ( V_4 & V_59 ) {
F_21 ( L_6 ) ;
F_9 ( V_60 ,
V_5 -> V_8 -> V_11 +
V_61 ) ;
V_19 -> V_20 |= V_21 | V_22 ;
break;
} else if ( V_4 & V_62 ) {
F_21 ( L_7 ) ;
F_9 ( V_63 ,
V_5 -> V_8 -> V_11 +
V_61 ) ;
V_19 -> V_20 |= V_21 ;
} else if ( V_4 & V_64 ) {
F_21 ( L_8 ) ;
F_9 ( V_65 ,
V_5 -> V_8 -> V_11 +
V_61 ) ;
V_19 -> V_20 |= V_21 ;
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
V_4 = F_16 ( V_5 -> V_8 -> V_11 + V_39 ) ;
V_32 = F_16 ( V_5 -> V_8 -> V_11 +
V_38 ) ;
}
V_52:
F_17 ( V_3 , V_18 ) ;
#if 0
if (!tag) {
writeb(0x03,
devpriv->mite->daq_io_addr +
Master_DMA_And_Interrupt_Control);
}
#endif
return V_66 ;
}
static void F_22 ( unsigned int V_4 )
{
int V_67 ;
F_33 ( V_68 L_9 ) ;
for ( V_67 = 7 ; V_67 >= 0 ; V_67 -- ) {
if ( V_4 & ( 1 << V_67 ) )
F_33 ( L_10 , V_69 [ V_67 ] ) ;
}
F_33 ( L_11 ) ;
}
static void F_23 ( unsigned int V_4 )
{
int V_67 ;
F_33 ( V_68 L_12 ) ;
for ( V_67 = 7 ; V_67 >= 0 ; V_67 -- ) {
if ( V_4 & ( 1 << V_67 ) )
F_33 ( L_10 , V_70 [ V_67 ] ) ;
}
F_33 ( L_11 ) ;
}
static void F_34 ( struct V_2 * V_3 )
{
int V_71 , V_72 ;
static int V_73 ;
struct V_74 V_75 ;
F_35 ( & V_75 ) ;
V_71 = F_16 ( V_5 -> V_8 -> V_11 + V_76 ) ;
V_72 = F_16 ( V_5 -> V_8 -> V_11 + V_39 ) ;
if ( V_73 < 10 ) {
F_21 ( L_13 , V_71 , V_72 ,
( int ) V_75 . V_77 ) ;
}
while ( V_72 & 1 ) {
F_36 ( 0xff , V_5 -> V_8 -> V_11 + V_53 ) ;
V_72 = F_16 ( V_5 -> V_8 -> V_11 + V_39 ) ;
}
V_72 = F_16 ( V_5 -> V_8 -> V_11 + V_39 ) ;
if ( V_73 < 10 ) {
F_21 ( L_14 , V_72 ) ;
V_73 ++ ;
}
}
static int F_37 ( struct V_2 * V_3 ,
struct V_17 * V_18 ,
struct V_78 * V_79 , unsigned int * V_15 )
{
if ( V_79 -> V_80 != 1 )
return - V_81 ;
switch ( V_15 [ 0 ] ) {
case V_82 :
V_18 -> V_83 |= 1 << F_38 ( V_79 -> V_84 ) ;
break;
case V_85 :
V_18 -> V_83 &= ~ ( 1 << F_38 ( V_79 -> V_84 ) ) ;
break;
case V_86 :
V_15 [ 1 ] =
( V_18 ->
V_83 & ( 1 << F_38 ( V_79 -> V_84 ) ) ) ? V_87 :
V_88 ;
return V_79 -> V_80 ;
break;
default:
return - V_81 ;
}
F_27 ( V_18 -> V_83 , V_5 -> V_8 -> V_11 + F_39 ( 0 ) ) ;
return 1 ;
}
static int F_40 ( struct V_2 * V_3 ,
struct V_17 * V_18 ,
struct V_78 * V_79 , unsigned int * V_15 )
{
if ( V_79 -> V_80 != 2 )
return - V_81 ;
if ( V_15 [ 0 ] ) {
V_18 -> V_89 &= ~ V_15 [ 0 ] ;
V_18 -> V_89 |= ( V_15 [ 0 ] & V_15 [ 1 ] ) ;
F_27 ( V_18 -> V_89 , V_5 -> V_8 -> V_11 + F_41 ( 0 ) ) ;
}
V_15 [ 1 ] = F_31 ( V_5 -> V_8 -> V_11 + F_41 ( 0 ) ) ;
return 2 ;
}
static int F_42 ( struct V_2 * V_3 ,
struct V_17 * V_18 , struct V_90 * V_91 )
{
int V_92 = 0 ;
int V_93 ;
V_93 = V_91 -> V_94 ;
V_91 -> V_94 &= V_95 | V_96 ;
if ( ! V_91 -> V_94 || V_93 != V_91 -> V_94 )
V_92 ++ ;
V_93 = V_91 -> V_97 ;
V_91 -> V_97 &= V_98 | V_99 ;
if ( ! V_91 -> V_97 || V_93 != V_91 -> V_97 )
V_92 ++ ;
V_93 = V_91 -> V_100 ;
V_91 -> V_100 &= V_95 ;
if ( ! V_91 -> V_100 || V_93 != V_91 -> V_100 )
V_92 ++ ;
V_93 = V_91 -> V_101 ;
V_91 -> V_101 &= V_102 ;
if ( ! V_91 -> V_101 || V_93 != V_91 -> V_101 )
V_92 ++ ;
V_93 = V_91 -> V_103 ;
V_91 -> V_103 &= V_102 | V_104 ;
if ( ! V_91 -> V_103 || V_93 != V_91 -> V_103 )
V_92 ++ ;
if ( V_92 )
return 1 ;
if ( V_91 -> V_94 != V_95 && V_91 -> V_94 != V_96 )
V_92 ++ ;
if ( V_91 -> V_97 != V_98 &&
V_91 -> V_97 != V_99 )
V_92 ++ ;
if ( V_92 )
return 2 ;
if ( V_91 -> V_105 != 0 ) {
V_91 -> V_105 = 0 ;
V_92 ++ ;
}
#define F_43 (TIMER_BASE)
if ( V_91 -> V_97 == V_98 ) {
if ( V_91 -> V_106 < F_43 ) {
V_91 -> V_106 = F_43 ;
V_92 ++ ;
}
} else {
if ( V_91 -> V_106 != 0 ) {
V_91 -> V_106 = 0 ;
V_92 ++ ;
}
}
if ( V_91 -> V_107 != 0 ) {
V_91 -> V_107 = 0 ;
V_92 ++ ;
}
if ( V_91 -> V_108 != V_91 -> V_109 ) {
V_91 -> V_108 = V_91 -> V_109 ;
V_92 ++ ;
}
if ( V_91 -> V_103 == V_102 ) {
} else {
if ( V_91 -> V_110 != 0 ) {
V_91 -> V_110 = 0 ;
V_92 ++ ;
}
}
if ( V_92 )
return 3 ;
if ( V_91 -> V_97 == V_98 ) {
V_93 = V_91 -> V_106 ;
F_44 ( & V_91 -> V_106 ,
V_91 -> V_4 & V_111 ) ;
if ( V_93 != V_91 -> V_106 )
V_92 ++ ;
}
if ( V_92 )
return 4 ;
return 0 ;
}
static int F_44 ( int * V_112 , int V_113 )
{
int V_114 , V_115 ;
V_115 = V_116 ;
switch ( V_113 ) {
case V_117 :
default:
V_114 = ( * V_112 + V_115 / 2 ) / V_115 ;
break;
case V_118 :
V_114 = ( * V_112 ) / V_115 ;
break;
case V_119 :
V_114 = ( * V_112 + V_115 - 1 ) / V_115 ;
break;
}
* V_112 = V_115 * V_114 ;
return V_114 ;
}
static int F_45 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
struct V_90 * V_91 = & V_18 -> V_19 -> V_91 ;
F_27 ( 0x0000 , V_5 -> V_8 -> V_11 + F_39 ( 0 ) ) ;
if ( 1 ) {
F_9 ( 0x0f , V_5 -> V_8 -> V_11 + V_120 ) ;
F_9 ( F_46 ( 0 ) | F_47 ( 0 ) ,
V_5 -> V_8 -> V_11 + V_121 ) ;
} else {
F_9 ( 0x03 , V_5 -> V_8 -> V_11 + V_120 ) ;
F_9 ( F_46 ( 3 ) | F_47 ( 0 ) ,
V_5 -> V_8 -> V_11 + V_121 ) ;
}
if ( V_91 -> V_97 == V_98 ) {
F_9 ( 0 , V_5 -> V_8 -> V_11 + V_58 ) ;
F_9 ( 0x00 , V_5 -> V_8 -> V_11 + V_122 ) ;
F_9 ( 1 , V_5 -> V_8 -> V_11 + V_123 ) ;
F_9 ( 0x04 , V_5 -> V_8 -> V_11 + V_124 ) ;
F_9 ( 4 , V_5 -> V_8 -> V_11 + V_125 ) ;
F_9 ( 3 , V_5 -> V_8 -> V_11 + V_126 ) ;
F_9 ( 0xc0 , V_5 -> V_8 -> V_11 + V_127 ) ;
F_27 ( F_44 ( & V_91 -> V_106 ,
V_117 ) ,
V_5 -> V_8 -> V_11 + V_128 ) ;
F_9 ( 1 , V_5 -> V_8 -> V_11 + V_129 ) ;
F_9 ( 1 , V_5 -> V_8 -> V_11 + V_130 ) ;
F_9 ( 1 , V_5 -> V_8 -> V_11 + V_131 ) ;
F_9 ( 0x0b , V_5 -> V_8 -> V_11 + V_132 ) ;
F_9 ( 0x01 , V_5 -> V_8 -> V_11 + V_133 ) ;
F_36 ( 0 , V_5 -> V_8 -> V_11 + V_134 ) ;
F_9 ( 0 , V_5 -> V_8 -> V_11 + V_135 ) ;
} else {
F_9 ( 0 , V_5 -> V_8 -> V_11 + V_58 ) ;
F_9 ( 0x00 , V_5 -> V_8 -> V_11 + V_122 ) ;
F_9 ( 0 , V_5 -> V_8 -> V_11 + V_123 ) ;
F_9 ( 0x00 , V_5 -> V_8 -> V_11 + V_124 ) ;
F_9 ( 4 , V_5 -> V_8 -> V_11 + V_125 ) ;
F_9 ( 0 , V_5 -> V_8 -> V_11 + V_126 ) ;
F_9 ( 0x00 , V_5 -> V_8 -> V_11 + V_127 ) ;
F_27 ( 1 , V_5 -> V_8 -> V_11 + V_128 ) ;
F_9 ( 1 , V_5 -> V_8 -> V_11 + V_129 ) ;
F_9 ( 1 , V_5 -> V_8 -> V_11 + V_130 ) ;
F_9 ( 1 , V_5 -> V_8 -> V_11 + V_131 ) ;
F_9 ( 0x0C , V_5 -> V_8 -> V_11 + V_132 ) ;
F_9 ( 0x10 , V_5 -> V_8 -> V_11 + V_133 ) ;
F_36 ( 0 , V_5 -> V_8 -> V_11 + V_134 ) ;
F_9 ( 0x60 , V_5 -> V_8 -> V_11 + V_135 ) ;
}
if ( V_91 -> V_103 == V_102 ) {
F_27 ( V_91 -> V_110 ,
V_5 -> V_8 -> V_11 + V_136 ) ;
} else {
}
#ifdef F_48
F_9 ( V_63 | V_65 ,
V_5 -> V_8 -> V_11 + V_61 ) ;
{
int V_137 = F_49 ( V_3 , V_18 ) ;
if ( V_137 )
return V_137 ;
}
#else
F_9 ( 0x00 , V_5 -> V_8 -> V_11 + V_12 ) ;
#endif
F_9 ( 0x00 , V_5 -> V_8 -> V_11 + V_138 ) ;
F_9 ( 0xff , V_5 -> V_8 -> V_11 + V_61 ) ;
F_9 ( V_50 , V_5 -> V_8 -> V_11 + V_139 ) ;
F_9 ( 0x03 ,
V_5 -> V_8 -> V_11 + V_49 ) ;
if ( V_91 -> V_103 == V_104 ) {
V_5 -> V_140 = F_50 ( 0 ) | F_51 ( 7 ) ;
} else {
V_5 -> V_140 = V_141 | F_51 ( 7 ) ;
}
if ( V_91 -> V_94 == V_95 ) {
F_9 ( V_5 -> V_140 ,
V_5 -> V_8 -> V_11 + V_58 ) ;
V_18 -> V_19 -> V_142 = NULL ;
} else {
V_18 -> V_19 -> V_142 = V_143 ;
}
F_21 ( L_15 ) ;
return 0 ;
}
static int F_49 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
int V_137 ;
V_137 = F_3 ( V_3 ) ;
if ( V_137 )
return V_137 ;
V_5 -> V_7 -> V_13 = V_88 ;
F_52 ( V_5 -> V_7 , 32 , 32 ) ;
F_53 ( V_5 -> V_7 ) ;
return 0 ;
}
static int V_143 ( struct V_2 * V_3 ,
struct V_17 * V_18 , unsigned int V_144 )
{
if ( V_144 != 0 )
return - V_81 ;
F_9 ( V_5 -> V_140 , V_5 -> V_8 -> V_11 + V_58 ) ;
V_18 -> V_19 -> V_142 = NULL ;
return 1 ;
}
static int F_18 ( struct V_2 * V_3 ,
struct V_17 * V_18 )
{
F_9 ( 0x00 ,
V_5 -> V_8 -> V_11 + V_49 ) ;
F_11 ( V_3 ) ;
return 0 ;
}
static int F_54 ( struct V_2 * V_3 ,
struct V_17 * V_18 , unsigned long V_145 )
{
int V_146 ;
V_146 = F_55 ( V_5 -> V_9 , V_18 -> V_19 ) ;
if ( V_146 < 0 )
return V_146 ;
memset ( V_18 -> V_19 -> V_147 , 0xaa , V_18 -> V_19 -> V_148 ) ;
return 0 ;
}
static int F_56 ( struct V_2 * V_3 , int V_149 ,
T_2 * V_15 , int V_150 )
{
static const int V_151 = 1000 ;
int V_67 , V_152 ;
F_36 ( 0x80 | V_149 ,
V_5 -> V_8 -> V_11 + V_153 ) ;
F_36 ( 0xc0 | V_149 ,
V_5 -> V_8 -> V_11 + V_153 ) ;
for ( V_67 = 0 ;
( F_57 ( V_5 -> V_8 -> V_11 +
V_154 ) & 0x2 ) == 0 && V_67 < V_151 ; ++ V_67 ) {
F_58 ( 1 ) ;
}
if ( V_67 == V_151 ) {
F_33 ( V_155 L_16
L_17 , V_149 ) ;
return - V_156 ;
}
F_36 ( 0x80 | V_149 ,
V_5 -> V_8 -> V_11 + V_153 ) ;
for ( V_67 = 0 ;
F_57 ( V_5 -> V_8 -> V_11 + V_154 ) !=
0x3 && V_67 < V_151 ; ++ V_67 ) {
F_58 ( 1 ) ;
}
if ( V_67 == V_151 ) {
F_33 ( V_155 L_16
L_18 , V_149 ) ;
return - V_156 ;
}
for ( V_152 = 0 ; V_152 + 1 < V_150 ; ) {
unsigned int V_157 = V_15 [ V_152 ++ ] ;
V_157 |= V_15 [ V_152 ++ ] << 8 ;
F_36 ( V_157 ,
V_5 -> V_8 -> V_11 + V_158 ) ;
for ( V_67 = 0 ;
( F_57 ( V_5 -> V_8 -> V_11 +
V_154 ) & 0x2 ) == 0
&& V_67 < V_151 ; ++ V_67 ) {
F_58 ( 1 ) ;
}
if ( V_67 == V_151 ) {
F_33 ( L_19 ,
V_149 ) ;
return - V_156 ;
}
if ( F_59 () )
F_60 () ;
}
F_36 ( 0x0 , V_5 -> V_8 -> V_11 + V_153 ) ;
return 0 ;
}
static int F_61 ( struct V_2 * V_3 , int V_149 )
{
return F_56 ( V_3 , V_149 , NULL , 0 ) ;
}
static int F_62 ( struct V_2 * V_3 )
{
int V_146 ;
int V_67 ;
F_36 ( 0x0 , V_5 -> V_8 -> V_11 + V_153 ) ;
for ( V_67 = 0 ; V_67 < 3 ; ++ V_67 ) {
V_146 = F_61 ( V_3 , V_67 ) ;
if ( V_146 < 0 )
break;
}
F_36 ( 0x0 , V_5 -> V_8 -> V_11 + V_159 ) ;
return V_146 ;
}
static void F_63 ( struct V_2 * V_3 )
{
F_27 ( 0 , V_5 -> V_8 -> V_11 + V_160 ) ;
F_27 ( 0 , V_5 -> V_8 -> V_11 + V_161 ) ;
F_27 ( 0 , V_5 -> V_8 -> V_11 + V_162 ) ;
F_27 ( 0 , V_5 -> V_8 -> V_11 + V_163 ) ;
F_27 ( 0 , V_5 -> V_8 -> V_11 + V_164 ) ;
F_27 ( 0 , V_5 -> V_8 -> V_11 + V_165 ) ;
}
static int F_64 ( struct V_2 * V_3 , int V_166 [] )
{
int V_146 ;
void * V_167 , * V_168 , * V_169 ;
int V_170 , V_171 , V_172 ;
if ( V_166 [ V_173 ] == 0 )
return 0 ;
V_146 = F_62 ( V_3 ) ;
if ( V_146 < 0 )
return V_146 ;
V_167 = F_65 ( V_166 , 0 ) ;
V_170 = V_166 [ V_174 ] ;
V_146 = F_56 ( V_3 , 2 , V_167 , V_170 ) ;
if ( V_146 < 0 )
return V_146 ;
F_63 ( V_3 ) ;
V_168 = F_65 ( V_166 , 1 ) ;
V_171 = V_166 [ V_175 ] ;
V_146 = F_56 ( V_3 , 0 , V_168 , V_171 ) ;
if ( V_146 < 0 )
return V_146 ;
V_169 = F_65 ( V_166 , 2 ) ;
V_172 = V_166 [ V_176 ] ;
V_146 = F_56 ( V_3 , 1 , V_169 , V_172 ) ;
if ( V_146 < 0 )
return V_146 ;
return 0 ;
}
static int F_66 ( struct V_2 * V_3 , struct V_177 * V_178 )
{
struct V_17 * V_18 ;
int V_67 ;
int V_146 ;
int V_179 ;
unsigned int V_24 ;
F_33 ( V_68 L_20 , V_3 -> V_180 ) ;
V_146 = F_67 ( V_3 , sizeof( struct V_181 ) ) ;
if ( V_146 < 0 )
return V_146 ;
F_68 ( & V_5 -> V_6 ) ;
V_146 = F_69 ( V_3 , V_178 -> V_166 [ 0 ] , V_178 -> V_166 [ 1 ] ) ;
if ( V_146 < 0 )
return V_146 ;
V_146 = F_70 ( V_5 -> V_8 ) ;
if ( V_146 < 0 ) {
F_33 ( V_155 L_21 ) ;
return V_146 ;
}
F_71 ( V_3 , & V_5 -> V_8 -> V_182 -> V_3 ) ;
V_5 -> V_9 = F_72 ( V_5 -> V_8 ) ;
if ( V_5 -> V_9 == NULL )
return - V_183 ;
V_3 -> V_184 = V_185 -> V_186 ;
V_24 = F_73 ( V_5 -> V_8 ) ;
F_33 ( V_68 L_10 , V_3 -> V_184 ) ;
if ( V_185 -> V_187 ) {
V_146 = F_64 ( V_3 , V_178 -> V_166 ) ;
if ( V_146 < 0 )
return V_146 ;
}
if ( ! V_185 -> V_188 )
V_179 = V_185 -> V_189 ;
else
V_179 = 1 ;
V_146 = F_74 ( V_3 , V_179 ) ;
if ( V_146 < 0 )
return V_146 ;
if ( ! V_185 -> V_188 ) {
for ( V_67 = 0 ; V_67 < V_185 -> V_189 ; V_67 ++ ) {
F_75 ( V_3 , V_3 -> V_26 + V_67 ,
F_15 ,
( unsigned long ) ( V_5 -> V_8 ->
V_11 +
F_76 ( V_67 ) ) ) ;
}
} else {
F_33 ( V_68 L_22 ,
F_16 ( V_5 -> V_8 -> V_11 + V_190 ) ) ;
V_18 = V_3 -> V_26 + 0 ;
V_3 -> V_191 = V_18 ;
V_18 -> type = V_192 ;
V_18 -> V_193 =
V_194 | V_195 | V_196 | V_197 |
V_198 ;
V_18 -> V_199 = 32 ;
V_18 -> V_200 = & V_201 ;
V_18 -> V_202 = 1 ;
V_18 -> V_203 = & F_37 ;
V_18 -> V_204 = & F_40 ;
V_18 -> V_205 = & F_45 ;
V_18 -> V_206 = & F_42 ;
V_18 -> V_207 = & F_18 ;
V_18 -> V_208 = 32 ;
V_18 -> V_209 = & F_54 ;
V_18 -> V_210 = V_211 ;
F_27 ( 0 , V_5 -> V_8 -> V_11 + F_41 ( 0 ) ) ;
F_27 ( 0 , V_5 -> V_8 -> V_11 + F_39 ( 0 ) ) ;
F_27 ( 0 , V_5 -> V_8 -> V_11 + F_77 ( 0 ) ) ;
F_9 ( 0x00 ,
V_5 -> V_8 -> V_11 +
V_49 ) ;
V_146 = F_78 ( V_24 , F_20 , V_212 ,
L_23 , V_3 ) ;
if ( V_146 < 0 )
F_33 ( V_155 L_24 ) ;
V_3 -> V_24 = V_24 ;
}
F_33 ( L_11 ) ;
return 0 ;
}
static int F_79 ( struct V_2 * V_3 )
{
int V_67 ;
if ( V_185 && ! V_185 -> V_188 ) {
for ( V_67 = 0 ; V_67 < V_185 -> V_189 ; V_67 ++ )
F_80 ( V_3 , V_3 -> V_26 + V_67 ) ;
}
if ( V_3 -> V_24 )
F_81 ( V_3 -> V_24 , V_3 ) ;
if ( V_5 ) {
if ( V_5 -> V_9 ) {
F_82 ( V_5 -> V_9 ) ;
V_5 -> V_9 = NULL ;
}
if ( V_5 -> V_8 )
F_83 ( V_5 -> V_8 ) ;
}
return 0 ;
}
static int F_69 ( struct V_2 * V_3 , int V_213 , int V_214 )
{
struct V_28 * V_8 ;
int V_67 ;
for ( V_8 = V_215 ; V_8 ; V_8 = V_8 -> V_216 ) {
if ( V_8 -> V_217 )
continue;
if ( V_213 || V_214 ) {
if ( V_213 != V_8 -> V_182 -> V_213 -> V_218 ||
V_214 != F_84 ( V_8 -> V_182 -> V_219 ) )
continue;
}
for ( V_67 = 0 ; V_67 < V_220 ; V_67 ++ ) {
if ( F_85 ( V_8 ) == V_221 [ V_67 ] . V_222 ) {
V_3 -> V_223 = V_221 + V_67 ;
V_5 -> V_8 = V_8 ;
return 0 ;
}
}
}
F_33 ( V_155 L_25 ) ;
F_86 () ;
return - V_156 ;
}
static int T_3 F_87 ( struct V_224 * V_3 ,
const struct V_225 * V_226 )
{
return F_88 ( V_3 , V_227 . V_228 ) ;
}
static void T_4 F_89 ( struct V_224 * V_3 )
{
F_90 ( V_3 ) ;
}
static int T_5 F_91 ( void )
{
int V_137 ;
V_137 = F_92 ( & V_227 ) ;
if ( V_137 < 0 )
return V_137 ;
V_229 . V_186 = ( char * ) V_227 . V_228 ;
return F_93 ( & V_229 ) ;
}
static void T_6 F_94 ( void )
{
F_95 ( & V_229 ) ;
F_96 ( & V_227 ) ;
}

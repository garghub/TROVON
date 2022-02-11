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
struct V_17 * V_18 = V_3 -> V_31 ;
struct V_32 * V_19 = V_18 -> V_19 ;
struct V_33 * V_10 = V_5 -> V_10 ;
unsigned int V_34 = 0 ;
unsigned short V_35 = 0 ;
unsigned short V_36 = 0 ;
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
F_19 ( & V_5 -> V_8 ) ;
if ( V_5 -> V_9 )
V_39 = F_24 ( V_5 -> V_9 ) ;
if ( V_39 & V_44 ) {
if ( V_39 & V_45 ) {
F_25 ( V_46 ,
V_10 -> V_47 +
F_26 ( V_5 -> V_9 -> V_1 ) ) ;
F_20 ( V_5 -> V_9 , V_18 -> V_19 ) ;
}
if ( V_39 & ~ ( V_44 | V_45 | V_48 | V_49 |
V_50 | V_51 ) ) {
F_27 ( V_3 -> V_52 ,
L_2 ) ;
V_19 -> V_20 |= V_21 | V_22 ;
F_28 ( V_3 -> V_29 ) ;
}
}
F_21 ( & V_5 -> V_8 ) ;
while ( V_37 & V_53 ) {
V_38 ++ ;
if ( V_38 > 20 ) {
F_27 ( V_3 -> V_52 , L_3 ) ;
F_9 ( 0x00 ,
V_5 -> V_10 -> V_15 +
V_54 ) ;
break;
}
V_7 &= V_55 ;
if ( V_7 & V_56 ) {
while ( V_7 & V_56 ) {
V_38 ++ ;
if ( V_38 > 100 ) {
F_27 ( V_3 -> V_52 ,
L_3 ) ;
F_9 ( 0x00 ,
V_5 -> V_10 -> V_15 +
V_54
) ;
goto V_57;
}
V_34 =
F_29 ( V_5 -> V_10 -> V_15 +
V_58 ) ;
V_35 = V_34 & 0xffff ;
V_36 = ( V_34 & 0xffff0000 ) >> 16 ;
F_30 ( V_19 , V_35 ) ;
F_30 ( V_19 , V_36 ) ;
V_7 = F_23 ( V_5 -> V_10 -> V_15 +
V_43 ) ;
}
V_19 -> V_20 |= V_59 ;
}
if ( V_7 & V_60 ) {
F_9 ( V_61 ,
V_5 -> V_10 -> V_15 +
V_62 ) ;
V_19 -> V_20 |= V_21 ;
F_9 ( 0x00 , V_5 -> V_10 -> V_15 + V_63 ) ;
break;
} else if ( V_7 & V_64 ) {
F_9 ( V_65 ,
V_5 -> V_10 -> V_15 +
V_66 ) ;
V_19 -> V_20 |= V_21 | V_22 ;
break;
} else if ( V_7 & V_67 ) {
F_9 ( V_68 ,
V_5 -> V_10 -> V_15 +
V_66 ) ;
V_19 -> V_20 |= V_21 ;
} else if ( V_7 & V_69 ) {
F_9 ( V_70 ,
V_5 -> V_10 -> V_15 +
V_66 ) ;
V_19 -> V_20 |= V_21 ;
}
V_7 = F_23 ( V_5 -> V_10 -> V_15 + V_43 ) ;
V_37 = F_23 ( V_5 -> V_10 -> V_15 +
V_42 ) ;
}
V_57:
F_15 ( V_3 , V_18 ) ;
#if 0
if (!tag) {
writeb(0x03,
devpriv->mite->daq_io_addr +
Master_DMA_And_Interrupt_Control);
}
#endif
F_21 ( & V_3 -> V_26 ) ;
return V_71 ;
}
static int F_31 ( struct V_2 * V_3 ,
struct V_17 * V_18 ,
struct V_72 * V_73 ,
unsigned int * V_74 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
int V_75 ;
V_75 = F_32 ( V_3 , V_18 , V_73 , V_74 , 0 ) ;
if ( V_75 )
return V_75 ;
F_25 ( V_18 -> V_76 , V_5 -> V_10 -> V_15 + F_33 ( 0 ) ) ;
return V_73 -> V_77 ;
}
static int F_34 ( struct V_2 * V_3 ,
struct V_17 * V_18 ,
struct V_72 * V_73 ,
unsigned int * V_74 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
if ( F_35 ( V_18 , V_74 ) )
F_25 ( V_18 -> V_78 , V_5 -> V_10 -> V_15 + F_36 ( 0 ) ) ;
V_74 [ 1 ] = F_29 ( V_5 -> V_10 -> V_15 + F_36 ( 0 ) ) ;
return V_73 -> V_77 ;
}
static int F_37 ( struct V_2 * V_3 ,
struct V_17 * V_18 , struct V_79 * V_80 )
{
int V_81 = 0 ;
int V_82 ;
V_81 |= F_38 ( & V_80 -> V_83 , V_84 | V_85 ) ;
V_81 |= F_38 ( & V_80 -> V_86 ,
V_87 | V_88 ) ;
V_81 |= F_38 ( & V_80 -> V_89 , V_84 ) ;
V_81 |= F_38 ( & V_80 -> V_90 , V_91 ) ;
V_81 |= F_38 ( & V_80 -> V_92 , V_91 | V_93 ) ;
if ( V_81 )
return 1 ;
V_81 |= F_39 ( V_80 -> V_83 ) ;
V_81 |= F_39 ( V_80 -> V_86 ) ;
V_81 |= F_39 ( V_80 -> V_92 ) ;
if ( V_81 )
return 2 ;
V_81 |= F_40 ( & V_80 -> V_94 , 0 ) ;
#define F_41 (TIMER_BASE)
if ( V_80 -> V_86 == V_87 ) {
V_81 |= F_42 ( & V_80 -> V_95 ,
F_41 ) ;
} else {
if ( ( V_80 -> V_95 & ~ ( V_96 | V_97 ) ) != 0 ) {
V_80 -> V_95 &= ( V_96 | V_97 ) ;
V_81 |= - V_98 ;
}
}
V_81 |= F_40 ( & V_80 -> V_99 , 0 ) ;
V_81 |= F_40 ( & V_80 -> V_100 , V_80 -> V_101 ) ;
if ( V_80 -> V_92 == V_91 ) {
} else {
V_81 |= F_40 ( & V_80 -> V_102 , 0 ) ;
}
if ( V_81 )
return 3 ;
if ( V_80 -> V_86 == V_87 ) {
V_82 = V_80 -> V_95 ;
F_43 ( & V_80 -> V_95 ,
V_80 -> V_7 & V_103 ) ;
if ( V_82 != V_80 -> V_95 )
V_81 ++ ;
}
if ( V_81 )
return 4 ;
return 0 ;
}
static int F_43 ( int * V_104 , int V_105 )
{
int V_106 , V_107 ;
V_107 = V_108 ;
switch ( V_105 ) {
case V_109 :
default:
V_106 = ( * V_104 + V_107 / 2 ) / V_107 ;
break;
case V_110 :
V_106 = ( * V_104 ) / V_107 ;
break;
case V_111 :
V_106 = ( * V_104 + V_107 - 1 ) / V_107 ;
break;
}
* V_104 = V_107 * V_106 ;
return V_106 ;
}
static int F_44 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_79 * V_80 = & V_18 -> V_19 -> V_80 ;
F_25 ( 0x0000 , V_5 -> V_10 -> V_15 + F_33 ( 0 ) ) ;
if ( 1 ) {
F_9 ( 0x0f , V_5 -> V_10 -> V_15 + V_112 ) ;
F_9 ( F_45 ( 0 ) | F_46 ( 0 ) ,
V_5 -> V_10 -> V_15 + V_113 ) ;
} else {
F_9 ( 0x03 , V_5 -> V_10 -> V_15 + V_112 ) ;
F_9 ( F_45 ( 3 ) | F_46 ( 0 ) ,
V_5 -> V_10 -> V_15 + V_113 ) ;
}
if ( V_80 -> V_86 == V_87 ) {
F_9 ( 0 , V_5 -> V_10 -> V_15 + V_63 ) ;
F_9 ( 0x00 , V_5 -> V_10 -> V_15 + V_114 ) ;
F_9 ( 1 , V_5 -> V_10 -> V_15 + V_115 ) ;
F_9 ( 0x04 , V_5 -> V_10 -> V_15 + V_116 ) ;
F_9 ( 4 , V_5 -> V_10 -> V_15 + V_117 ) ;
F_9 ( 3 , V_5 -> V_10 -> V_15 + V_118 ) ;
F_9 ( 0xc0 , V_5 -> V_10 -> V_15 + V_119 ) ;
F_25 ( F_43 ( & V_80 -> V_95 ,
V_109 ) ,
V_5 -> V_10 -> V_15 + V_120 ) ;
F_9 ( 1 , V_5 -> V_10 -> V_15 + V_121 ) ;
F_9 ( 1 , V_5 -> V_10 -> V_15 + V_122 ) ;
F_9 ( 1 , V_5 -> V_10 -> V_15 + V_123 ) ;
F_9 ( 0x0b , V_5 -> V_10 -> V_15 + V_124 ) ;
F_9 ( 0x01 , V_5 -> V_10 -> V_15 + V_125 ) ;
F_47 ( 0 , V_5 -> V_10 -> V_15 + V_126 ) ;
F_9 ( 0 , V_5 -> V_10 -> V_15 + V_127 ) ;
} else {
F_9 ( 0 , V_5 -> V_10 -> V_15 + V_63 ) ;
F_9 ( 0x00 , V_5 -> V_10 -> V_15 + V_114 ) ;
F_9 ( 0 , V_5 -> V_10 -> V_15 + V_115 ) ;
F_9 ( 0x00 , V_5 -> V_10 -> V_15 + V_116 ) ;
F_9 ( 4 , V_5 -> V_10 -> V_15 + V_117 ) ;
if ( ! ( V_80 -> V_95 & V_97 ) ) {
F_9 ( 0 , V_5 -> V_10 -> V_15 + V_118 ) ;
} else {
F_9 ( 2 , V_5 -> V_10 -> V_15 + V_118 ) ;
}
F_9 ( 0x00 , V_5 -> V_10 -> V_15 + V_119 ) ;
F_25 ( 1 , V_5 -> V_10 -> V_15 + V_120 ) ;
F_9 ( 1 , V_5 -> V_10 -> V_15 + V_121 ) ;
F_9 ( 1 , V_5 -> V_10 -> V_15 + V_122 ) ;
F_9 ( 1 , V_5 -> V_10 -> V_15 + V_123 ) ;
F_9 ( 0x0C , V_5 -> V_10 -> V_15 + V_124 ) ;
F_9 ( 0x10 , V_5 -> V_10 -> V_15 + V_125 ) ;
F_47 ( 0 , V_5 -> V_10 -> V_15 + V_126 ) ;
F_9 ( 0x60 , V_5 -> V_10 -> V_15 + V_127 ) ;
}
if ( V_80 -> V_92 == V_91 ) {
F_25 ( V_80 -> V_102 ,
V_5 -> V_10 -> V_15 + V_128 ) ;
} else {
}
#ifdef F_48
F_9 ( V_68 | V_70 ,
V_5 -> V_10 -> V_15 + V_66 ) ;
{
int V_129 = F_49 ( V_3 , V_18 ) ;
if ( V_129 )
return V_129 ;
}
#else
F_9 ( 0x00 , V_5 -> V_10 -> V_15 + V_16 ) ;
#endif
F_9 ( 0x00 , V_5 -> V_10 -> V_15 + V_130 ) ;
F_9 ( 0xff , V_5 -> V_10 -> V_15 + V_66 ) ;
F_9 ( V_55 , V_5 -> V_10 -> V_15 + V_131 ) ;
F_9 ( 0x03 ,
V_5 -> V_10 -> V_15 + V_54 ) ;
if ( V_80 -> V_92 == V_93 ) {
V_5 -> V_132 = F_50 ( 0 ) | F_51 ( 7 ) ;
} else {
V_5 -> V_132 = V_133 | F_51 ( 7 ) ;
}
if ( V_80 -> V_83 == V_84 ) {
F_9 ( V_5 -> V_132 ,
V_5 -> V_10 -> V_15 + V_63 ) ;
V_18 -> V_19 -> V_134 = NULL ;
} else {
V_18 -> V_19 -> V_134 = V_135 ;
}
return 0 ;
}
static int F_49 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
int V_129 ;
unsigned long V_7 ;
V_129 = F_3 ( V_3 ) ;
if ( V_129 )
return V_129 ;
F_52 ( V_18 -> V_19 , V_18 -> V_19 -> V_136 ) ;
F_4 ( & V_5 -> V_8 , V_7 ) ;
if ( V_5 -> V_9 ) {
F_53 ( V_5 -> V_9 , 32 , 32 ) ;
F_54 ( V_5 -> V_9 ) ;
} else
V_129 = - V_137 ;
F_7 ( & V_5 -> V_8 , V_7 ) ;
return V_129 ;
}
static int V_135 ( struct V_2 * V_3 ,
struct V_17 * V_18 , unsigned int V_138 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
if ( V_138 != 0 )
return - V_98 ;
F_9 ( V_5 -> V_132 , V_5 -> V_10 -> V_15 + V_63 ) ;
V_18 -> V_19 -> V_134 = NULL ;
return 1 ;
}
static int F_16 ( struct V_2 * V_3 ,
struct V_17 * V_18 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
F_9 ( 0x00 ,
V_5 -> V_10 -> V_15 + V_54 ) ;
F_11 ( V_3 ) ;
return 0 ;
}
static int F_55 ( struct V_2 * V_3 ,
struct V_17 * V_18 , unsigned long V_139 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
int V_75 ;
V_75 = F_56 ( V_5 -> V_11 , V_18 -> V_19 ) ;
if ( V_75 < 0 )
return V_75 ;
memset ( V_18 -> V_19 -> V_140 , 0xaa , V_18 -> V_19 -> V_136 ) ;
return 0 ;
}
static int F_57 ( struct V_2 * V_3 ,
const T_2 * V_74 , T_3 V_141 ,
unsigned long V_142 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
static const int V_143 = 1000 ;
int V_144 = V_142 ;
int V_145 ;
T_3 V_146 ;
F_47 ( 0x80 | V_144 ,
V_5 -> V_10 -> V_15 + V_147 ) ;
F_47 ( 0xc0 | V_144 ,
V_5 -> V_10 -> V_15 + V_147 ) ;
for ( V_145 = 0 ;
( F_58 ( V_5 -> V_10 -> V_15 +
V_148 ) & 0x2 ) == 0 && V_145 < V_143 ; ++ V_145 ) {
F_59 ( 1 ) ;
}
if ( V_145 == V_143 ) {
F_60 ( V_3 -> V_52 ,
L_4 ,
V_144 ) ;
return - V_137 ;
}
F_47 ( 0x80 | V_144 ,
V_5 -> V_10 -> V_15 + V_147 ) ;
for ( V_145 = 0 ;
F_58 ( V_5 -> V_10 -> V_15 + V_148 ) !=
0x3 && V_145 < V_143 ; ++ V_145 ) {
F_59 ( 1 ) ;
}
if ( V_145 == V_143 ) {
F_60 ( V_3 -> V_52 ,
L_5 ,
V_144 ) ;
return - V_137 ;
}
for ( V_146 = 0 ; V_146 + 1 < V_141 ; ) {
unsigned int V_149 = V_74 [ V_146 ++ ] ;
V_149 |= V_74 [ V_146 ++ ] << 8 ;
F_47 ( V_149 ,
V_5 -> V_10 -> V_15 + V_150 ) ;
for ( V_145 = 0 ;
( F_58 ( V_5 -> V_10 -> V_15 +
V_148 ) & 0x2 ) == 0
&& V_145 < V_143 ; ++ V_145 ) {
F_59 ( 1 ) ;
}
if ( V_145 == V_143 ) {
F_60 ( V_3 -> V_52 ,
L_6 ,
V_144 ) ;
return - V_137 ;
}
if ( F_61 () )
F_62 () ;
}
F_47 ( 0x0 , V_5 -> V_10 -> V_15 + V_147 ) ;
return 0 ;
}
static int F_63 ( struct V_2 * V_3 , int V_144 )
{
return F_57 ( V_3 , NULL , 0 , V_144 ) ;
}
static int F_64 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
int V_75 ;
int V_145 ;
F_47 ( 0x0 , V_5 -> V_10 -> V_15 + V_147 ) ;
for ( V_145 = 0 ; V_145 < 3 ; ++ V_145 ) {
V_75 = F_63 ( V_3 , V_145 ) ;
if ( V_75 < 0 )
break;
}
F_47 ( 0x0 , V_5 -> V_10 -> V_15 + V_151 ) ;
return V_75 ;
}
static void F_65 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
F_25 ( 0 , V_5 -> V_10 -> V_15 + V_152 ) ;
F_25 ( 0 , V_5 -> V_10 -> V_15 + V_153 ) ;
F_25 ( 0 , V_5 -> V_10 -> V_15 + V_154 ) ;
F_25 ( 0 , V_5 -> V_10 -> V_15 + V_155 ) ;
F_25 ( 0 , V_5 -> V_10 -> V_15 + V_156 ) ;
F_25 ( 0 , V_5 -> V_10 -> V_15 + V_157 ) ;
}
static int F_66 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
static const char * const V_158 [ 3 ] = {
V_159 ,
V_160 ,
V_161 ,
} ;
int V_75 ;
int V_77 ;
V_75 = F_64 ( V_3 ) ;
if ( V_75 < 0 )
return V_75 ;
for ( V_77 = 2 ; V_77 >= 0 ; V_77 -- ) {
V_75 = F_67 ( V_3 , & V_5 -> V_10 -> V_162 -> V_3 ,
V_158 [ V_77 ] ,
F_57 , V_77 ) ;
if ( V_75 == 0 && V_77 == 2 )
F_65 ( V_3 ) ;
if ( V_75 < 0 )
break;
}
return V_75 ;
}
static void F_68 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
void T_4 * V_163 = V_5 -> V_10 -> V_15 ;
F_25 ( 0 , V_163 + F_36 ( 0 ) ) ;
F_25 ( 0 , V_163 + F_33 ( 0 ) ) ;
F_25 ( 0 , V_163 + F_69 ( 0 ) ) ;
F_9 ( 0 , V_163 + V_54 ) ;
}
static int F_70 ( struct V_2 * V_3 ,
unsigned long V_142 )
{
struct V_164 * V_162 = F_71 ( V_3 ) ;
const struct V_165 * V_166 = NULL ;
struct V_4 * V_5 ;
struct V_17 * V_18 ;
int V_75 ;
unsigned int V_29 ;
if ( V_142 < F_72 ( V_167 ) )
V_166 = & V_167 [ V_142 ] ;
if ( ! V_166 )
return - V_168 ;
V_3 -> V_169 = V_166 ;
V_3 -> V_170 = V_166 -> V_171 ;
V_75 = F_73 ( V_3 ) ;
if ( V_75 )
return V_75 ;
V_5 = F_74 ( V_3 , sizeof( * V_5 ) ) ;
if ( ! V_5 )
return - V_172 ;
F_75 ( & V_5 -> V_8 ) ;
V_5 -> V_10 = F_76 ( V_162 ) ;
if ( ! V_5 -> V_10 )
return - V_172 ;
V_75 = F_77 ( V_5 -> V_10 ) ;
if ( V_75 < 0 ) {
F_60 ( V_3 -> V_52 , L_7 ) ;
return V_75 ;
}
V_5 -> V_11 = F_78 ( V_5 -> V_10 ) ;
if ( V_5 -> V_11 == NULL )
return - V_172 ;
if ( V_166 -> V_173 ) {
V_75 = F_66 ( V_3 ) ;
if ( V_75 < 0 )
return V_75 ;
}
F_68 ( V_3 ) ;
V_75 = F_79 ( V_3 , 1 ) ;
if ( V_75 )
return V_75 ;
F_80 ( V_3 -> V_52 , L_8 , V_3 -> V_170 ,
F_23 ( V_5 -> V_10 -> V_15 + V_174 ) ) ;
V_18 = & V_3 -> V_175 [ 0 ] ;
V_3 -> V_31 = V_18 ;
V_18 -> type = V_176 ;
V_18 -> V_177 =
V_178 | V_179 | V_180 | V_181 |
V_182 ;
V_18 -> V_183 = 32 ;
V_18 -> V_184 = & V_185 ;
V_18 -> V_186 = 1 ;
V_18 -> V_187 = & F_31 ;
V_18 -> V_188 = & F_34 ;
V_18 -> V_189 = & F_44 ;
V_18 -> V_190 = & F_37 ;
V_18 -> V_191 = & F_16 ;
V_18 -> V_192 = 32 ;
V_18 -> V_193 = & F_55 ;
V_18 -> V_194 = V_195 ;
V_18 -> V_196 = & F_18 ;
V_29 = F_81 ( V_5 -> V_10 ) ;
if ( V_29 ) {
V_75 = F_82 ( V_29 , F_22 , V_197 ,
V_3 -> V_170 , V_3 ) ;
if ( V_75 == 0 )
V_3 -> V_29 = V_29 ;
}
return 0 ;
}
static void F_83 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
if ( V_3 -> V_29 )
F_84 ( V_3 -> V_29 , V_3 ) ;
if ( V_5 ) {
if ( V_5 -> V_11 ) {
F_85 ( V_5 -> V_11 ) ;
V_5 -> V_11 = NULL ;
}
if ( V_5 -> V_10 ) {
F_86 ( V_5 -> V_10 ) ;
F_87 ( V_5 -> V_10 ) ;
}
}
F_88 ( V_3 ) ;
}
static int F_89 ( struct V_164 * V_3 ,
const struct V_198 * V_199 )
{
return F_90 ( V_3 , & V_200 , V_199 -> V_201 ) ;
}

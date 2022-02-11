static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , unsigned long V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , unsigned long V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_2 V_3 , unsigned long V_4 )
{
F_6 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static inline T_2 F_7 ( struct V_1 * V_2 , unsigned long V_4 )
{
return F_8 ( V_2 -> V_5 + V_4 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 , T_1 V_6 , T_1 V_7 )
{
F_1 ( V_2 , V_6 & V_8 , V_9 ) ;
F_1 ( V_2 , V_7 , V_10 ) ;
return F_3 ( V_2 , V_11 ) ;
}
static void F_10 ( struct V_1 * V_2 , T_1 V_6 , T_1 V_7 , T_1 V_12 )
{
F_1 ( V_2 , V_6 & V_8 , V_9 ) ;
F_1 ( V_2 , V_7 , V_10 ) ;
F_1 ( V_2 , V_12 , V_11 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
V_2 -> V_13 = F_7 ( V_2 , V_14 ) & ~ V_15 ;
F_12 ( 10 ) ;
F_5 ( V_2 , V_2 -> V_13 & ~ V_16 , V_14 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_2 -> V_13 | V_16 , V_14 ) ;
}
static int F_14 ( struct V_1 * V_2 , struct V_17 * V_18 , T_1 V_19 )
{
F_10 ( V_2 , V_20 ,
V_18 -> V_21 + V_18 -> V_22 ,
V_19 ) ;
return V_18 -> V_22 ++ ;
}
static void F_15 ( struct V_1 * V_2 , struct V_17 * V_18 , int V_7 )
{
T_1 V_19 ;
int V_23 = V_18 -> V_22 - 1 ;
if ( V_7 != V_23 ) {
V_19 = F_9 ( V_2 , V_20 ,
V_18 -> V_21 + V_23 ) ;
F_10 ( V_2 , V_20 ,
V_18 -> V_21 + V_7 ,
V_19 ) ;
}
F_10 ( V_2 , V_20 ,
V_18 -> V_21 + V_23 ,
0 ) ;
V_18 -> V_22 -- ;
}
static void F_16 ( struct V_1 * V_2 )
{
V_2 -> V_24 ++ ;
if ( V_2 -> V_24 != 1 )
return;
F_10 ( V_2 , V_20 ,
V_25 ,
240 ) ;
F_10 ( V_2 , V_20 ,
V_26 ,
240 ) ;
F_1 ( V_2 ,
F_3 ( V_2 , V_27 ) | V_28 ,
V_27 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
V_2 -> V_24 -- ;
if ( V_2 -> V_24 > 0 )
return;
F_10 ( V_2 , V_20 ,
V_25 ,
0 ) ;
F_10 ( V_2 , V_20 ,
V_26 ,
0 ) ;
F_1 ( V_2 ,
F_3 ( V_2 , V_27 ) & ~ V_28 ,
V_27 ) ;
}
static int F_18 ( struct V_1 * V_2 , struct V_29 * V_30 ,
struct V_31 * V_32 )
{
if ( ! V_30 || ! V_32 )
return - V_33 ;
F_16 ( V_2 ) ;
switch ( V_32 -> V_34 ) {
case V_35 :
V_2 -> V_36 ++ ;
F_10 ( V_2 , V_20 ,
V_30 -> V_37 . V_12 + V_38 , 1 ) ;
F_10 ( V_2 , V_20 ,
V_39 ,
V_2 -> V_36 ) ;
break;
case V_40 :
F_10 ( V_2 , V_20 ,
V_41 , 1 ) ;
F_10 ( V_2 , V_20 ,
V_30 -> V_37 . V_12 + V_38 , 1 ) ;
break;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_29 * V_30 ,
struct V_31 * V_32 )
{
if ( ! V_30 || ! V_32 )
return - V_33 ;
F_10 ( V_2 , V_20 ,
V_30 -> V_37 . V_12 + V_38 , 0 ) ;
F_17 ( V_2 ) ;
switch ( V_32 -> V_34 ) {
case V_35 :
V_2 -> V_36 -- ;
F_10 ( V_2 , V_20 ,
V_39 ,
V_2 -> V_36 ) ;
break;
case V_40 :
F_10 ( V_2 , V_20 ,
V_41 , 0 ) ;
break;
}
return 0 ;
}
static int
F_20 ( struct V_31 * V_32 , int V_42 )
{
struct V_1 * V_2 = F_21 ( V_32 ) ;
struct V_29 * V_30 = V_32 -> V_43 -> V_44 ;
int V_45 = - V_33 ;
if ( F_22 ( ! V_30 ) )
return - V_46 ;
F_23 ( & V_2 -> V_47 ) ;
switch ( V_42 ) {
case V_48 :
case V_49 :
if ( V_30 -> V_50 )
V_45 = - V_51 ;
else {
V_30 -> V_50 = 1 ;
V_45 = F_18 ( V_2 , V_30 , V_32 ) ;
}
break;
case V_52 :
case V_53 :
if ( ! V_30 -> V_50 )
V_45 = 0 ;
else {
V_30 -> V_50 = 0 ;
V_45 = F_19 ( V_2 , V_30 , V_32 ) ;
}
break;
}
F_24 ( & V_2 -> V_47 ) ;
return V_45 ;
}
static void
F_25 ( struct V_1 * V_2 , struct V_29 * V_30 , struct V_31 * V_32 )
{
int V_54 , V_55 , V_56 , V_57 ;
struct V_58 * V_43 = V_32 -> V_43 ;
if ( V_32 -> V_34 == V_35 ) {
V_54 = V_59 - ( 0x20 * 2 ) ;
V_55 = V_60 - ( 0x20 * 2 ) ;
} else {
V_54 = V_59 - ( 0x10 * 2 ) ;
V_55 = V_60 - ( 0x10 * 2 ) ;
}
V_56 = V_30 -> V_37 . V_12 + ( V_61 / 2 ) ;
V_57 = V_56 + ( V_54 / 2 ) + 1 ;
V_30 -> V_62 = F_26 ( V_43 , V_43 -> V_63 ) ;
V_30 -> V_64 = F_26 ( V_43 , V_43 -> V_64 ) ;
V_30 -> V_65 = 0 ;
V_30 -> V_66 = 0 ;
#define F_27 ( T_3 ) ((x) & 0xffff)
#define F_28 ( T_3 ) LO((x) >> 16)
F_10 ( V_2 , V_20 ,
V_30 -> V_37 . V_12 + V_67 ,
F_27 ( V_30 -> V_68 ) ) ;
F_10 ( V_2 , V_20 ,
V_30 -> V_37 . V_12 + V_69 ,
F_28 ( V_30 -> V_68 ) ) ;
F_10 ( V_2 , V_20 ,
V_30 -> V_37 . V_12 + V_70 ,
F_27 ( V_30 -> V_68 + V_30 -> V_62 ) ) ;
F_10 ( V_2 , V_20 ,
V_30 -> V_37 . V_12 + V_71 ,
F_28 ( V_30 -> V_68 + V_30 -> V_62 ) ) ;
F_10 ( V_2 , V_20 ,
V_30 -> V_37 . V_12 + V_72 ,
F_27 ( V_30 -> V_68 ) ) ;
F_10 ( V_2 , V_20 ,
V_30 -> V_37 . V_12 + V_73 ,
F_28 ( V_30 -> V_68 ) ) ;
#undef F_27
#undef F_28
F_10 ( V_2 , V_20 ,
V_30 -> V_37 . V_12 + V_74 ,
V_56 ) ;
F_10 ( V_2 , V_20 ,
V_30 -> V_37 . V_12 + V_75 ,
V_56 + ( V_54 / 2 ) ) ;
F_10 ( V_2 , V_20 ,
V_30 -> V_37 . V_12 + V_76 ,
V_56 ) ;
F_10 ( V_2 , V_20 ,
V_30 -> V_37 . V_12 + V_77 ,
V_56 ) ;
F_10 ( V_2 , V_20 ,
V_30 -> V_37 . V_12 + V_78 ,
V_57 ) ;
F_10 ( V_2 , V_20 ,
V_30 -> V_37 . V_12 + V_79 ,
V_57 + ( V_55 / 2 ) ) ;
F_10 ( V_2 , V_20 ,
V_30 -> V_37 . V_12 + V_80 ,
V_57 ) ;
F_10 ( V_2 , V_20 ,
V_30 -> V_37 . V_12 + V_81 ,
V_57 ) ;
}
static void F_29 ( struct V_1 * V_2 , struct V_29 * V_30 ,
struct V_58 * V_43 )
{
T_4 V_82 ;
if ( ! V_30 -> V_83 ) {
V_30 -> V_7 [ 0 ] = F_14 ( V_2 , V_30 -> V_84 [ 0 ] ,
V_30 -> V_37 . V_12 >> V_85 ) ;
V_30 -> V_7 [ 1 ] = F_14 ( V_2 , V_30 -> V_84 [ 1 ] ,
V_30 -> V_37 . V_12 >> V_85 ) ;
V_30 -> V_7 [ 2 ] = F_14 ( V_2 , V_30 -> V_84 [ 2 ] ,
V_30 -> V_37 . V_12 >> V_85 ) ;
V_30 -> V_83 = 1 ;
}
F_10 ( V_2 , V_20 ,
V_30 -> V_37 . V_12 + V_86 + 1 ,
V_43 -> V_87 == 2 ? 0 : 1 ) ;
F_10 ( V_2 , V_20 ,
V_30 -> V_37 . V_12 + V_86 + 2 ,
F_30 ( V_43 -> V_88 ) == 16 ? 0 : 1 ) ;
V_82 = ( ( V_43 -> V_89 << 15 ) + 24000 ) / 48000 ;
if ( V_82 )
V_82 -- ;
F_10 ( V_2 , V_20 ,
V_30 -> V_37 . V_12 + V_90 ,
V_82 ) ;
}
static void
F_31 ( struct V_1 * V_2 , struct V_29 * V_30 ,
struct V_31 * V_32 )
{
unsigned int V_91 ;
F_10 ( V_2 , V_20 ,
V_30 -> V_37 . V_12 + V_86 + 12 ,
V_30 -> V_37 . V_12 + 40 + 8 ) ;
F_10 ( V_2 , V_20 ,
V_30 -> V_37 . V_12 + V_86 + 19 ,
V_30 -> V_37 . V_92 + V_93 ) ;
F_10 ( V_2 , V_20 ,
V_30 -> V_37 . V_12 + V_86 + 22 ,
V_32 -> V_43 -> V_89 > 45000 ? 0xff : 0 ) ;
F_10 ( V_2 , V_20 ,
V_30 -> V_37 . V_12 + V_94 ,
V_95 + V_96 + V_97 ) ;
for ( V_91 = 0 ; V_91 < F_32 ( V_98 ) ; V_91 ++ )
F_10 ( V_2 , V_20 ,
V_30 -> V_37 . V_12 + V_98 [ V_91 ] . V_99 , V_98 [ V_91 ] . V_19 ) ;
}
static void
F_33 ( struct V_1 * V_2 , struct V_29 * V_30 , struct V_31 * V_32 )
{
unsigned int V_91 ;
F_10 ( V_2 , V_20 ,
V_30 -> V_37 . V_12 + V_86 + 12 ,
V_30 -> V_37 . V_12 + 40 + 8 ) ;
F_10 ( V_2 , V_20 ,
V_30 -> V_37 . V_12 + V_94 ,
V_100 + V_95 +
V_96 + V_97 ) ;
for ( V_91 = 0 ; V_91 < F_32 ( V_101 ) ; V_91 ++ )
F_10 ( V_2 , V_20 ,
V_30 -> V_37 . V_12 + V_101 [ V_91 ] . V_99 , V_101 [ V_91 ] . V_19 ) ;
}
static int F_34 ( struct V_31 * V_102 ,
struct V_103 * V_104 )
{
struct V_29 * V_30 = V_102 -> V_43 -> V_44 ;
int V_45 ;
if ( ( V_45 = F_35 ( V_102 , F_36 ( V_104 ) ) ) < 0 )
return V_45 ;
V_30 -> V_68 = V_102 -> V_43 -> V_105 ;
if ( V_30 -> V_68 & 0x3 ) {
F_37 ( V_106 L_1 ) ;
V_30 -> V_68 = V_30 -> V_68 & ~ 0x3 ;
}
return 0 ;
}
static int F_38 ( struct V_31 * V_102 )
{
struct V_29 * V_30 ;
if ( V_102 -> V_43 -> V_44 == NULL )
return 0 ;
V_30 = V_102 -> V_43 -> V_44 ;
F_39 ( V_102 ) ;
V_30 -> V_68 = 0 ;
return 0 ;
}
static int
F_40 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_21 ( V_32 ) ;
struct V_58 * V_43 = V_32 -> V_43 ;
struct V_29 * V_30 = V_43 -> V_44 ;
if ( F_22 ( ! V_30 ) )
return - V_46 ;
if ( V_43 -> V_88 != V_107 &&
V_43 -> V_88 != V_108 )
return - V_33 ;
if ( V_43 -> V_89 > 48000 ||
V_43 -> V_89 < 8000 )
return - V_33 ;
F_41 ( & V_2 -> V_47 ) ;
F_25 ( V_2 , V_30 , V_32 ) ;
if ( V_32 -> V_34 == V_35 )
F_31 ( V_2 , V_30 , V_32 ) ;
else
F_33 ( V_2 , V_30 , V_32 ) ;
F_29 ( V_2 , V_30 , V_43 ) ;
F_42 ( & V_2 -> V_47 ) ;
return 0 ;
}
static unsigned int
F_43 ( struct V_1 * V_2 , struct V_29 * V_30 , struct V_31 * V_32 )
{
T_1 V_109 = 0 , V_110 = 0 ;
int V_111 = 10 ;
T_4 V_99 ;
while ( V_111 -- ) {
V_109 = F_9 ( V_2 , V_20 ,
V_30 -> V_37 . V_12 + V_73 ) ;
V_110 = F_9 ( V_2 , V_20 ,
V_30 -> V_37 . V_12 + V_72 ) ;
if ( V_109 == F_9 ( V_2 , V_20 ,
V_30 -> V_37 . V_12 + V_73 ) )
break;
}
V_99 = V_110 | ( ( T_4 ) V_109 << 16 ) ;
return ( unsigned int ) ( V_99 - V_30 -> V_68 ) ;
}
static T_5
F_44 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_21 ( V_32 ) ;
unsigned int V_112 ;
struct V_29 * V_30 = V_32 -> V_43 -> V_44 ;
if ( F_22 ( ! V_30 ) )
return 0 ;
F_23 ( & V_2 -> V_47 ) ;
V_112 = F_43 ( V_2 , V_30 , V_32 ) ;
F_24 ( & V_2 -> V_47 ) ;
return F_45 ( V_32 -> V_43 , V_112 ) ;
}
static void F_46 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
struct V_31 * V_32 = V_30 -> V_102 ;
unsigned int V_65 ;
int V_113 ;
if ( ! V_30 -> V_50 )
return;
V_65 = F_43 ( V_2 , V_30 , V_32 ) ;
if ( V_65 >= V_30 -> V_62 )
V_65 %= V_30 -> V_62 ;
V_113 = V_30 -> V_62 + V_65 - V_30 -> V_65 ;
if ( V_113 >= V_30 -> V_62 )
V_113 %= V_30 -> V_62 ;
V_30 -> V_65 = V_65 ;
V_30 -> V_66 += V_113 ;
if ( V_30 -> V_66 >= ( signed ) V_30 -> V_64 ) {
if ( V_30 -> V_66 < 2 * ( signed ) V_30 -> V_64 )
V_30 -> V_66 -= ( signed ) V_30 -> V_64 ;
else
V_30 -> V_66 %= V_30 -> V_64 ;
F_24 ( & V_2 -> V_47 ) ;
F_47 ( V_32 ) ;
F_23 ( & V_2 -> V_47 ) ;
}
}
static void F_48 ( unsigned long V_44 )
{
struct V_1 * V_2 = (struct V_1 * ) V_44 ;
int T_3 , V_19 ;
#ifndef F_49
unsigned long V_114 ;
#endif
T_3 = F_8 ( V_2 -> V_5 + V_115 ) & 0xee ;
F_6 ( 0x88 , V_2 -> V_5 + V_115 ) ;
F_6 ( 0x88 , V_2 -> V_5 + V_116 ) ;
F_6 ( 0x88 , V_2 -> V_5 + V_117 ) ;
F_6 ( 0x88 , V_2 -> V_5 + V_118 ) ;
if ( V_2 -> V_119 )
return;
#ifndef F_49
if ( ! V_2 -> V_120 || ! V_2 -> V_121 )
return;
F_50 ( & V_2 -> V_122 , V_114 ) ;
V_19 = V_2 -> V_123 -> V_124 [ V_125 ] ;
switch ( T_3 ) {
case 0x88 :
V_19 ^= 0x8000 ;
V_2 -> V_123 -> V_124 [ V_125 ] = V_19 ;
F_2 ( V_19 , V_2 -> V_5 + V_126 ) ;
F_6 ( V_125 , V_2 -> V_5 + V_127 ) ;
F_51 ( V_2 -> V_128 , V_129 ,
& V_2 -> V_120 -> V_130 ) ;
break;
case 0xaa :
if ( ( V_19 & 0x7f ) > 0 )
V_19 -- ;
if ( ( V_19 & 0x7f00 ) > 0 )
V_19 -= 0x0100 ;
V_2 -> V_123 -> V_124 [ V_125 ] = V_19 ;
F_2 ( V_19 , V_2 -> V_5 + V_126 ) ;
F_6 ( V_125 , V_2 -> V_5 + V_127 ) ;
F_51 ( V_2 -> V_128 , V_129 ,
& V_2 -> V_121 -> V_130 ) ;
break;
case 0x66 :
if ( ( V_19 & 0x7f ) < 0x1f )
V_19 ++ ;
if ( ( V_19 & 0x7f00 ) < 0x1f00 )
V_19 += 0x0100 ;
V_2 -> V_123 -> V_124 [ V_125 ] = V_19 ;
F_2 ( V_19 , V_2 -> V_5 + V_126 ) ;
F_6 ( V_125 , V_2 -> V_5 + V_127 ) ;
F_51 ( V_2 -> V_128 , V_129 ,
& V_2 -> V_121 -> V_130 ) ;
break;
}
F_52 ( & V_2 -> V_122 , V_114 ) ;
#else
if ( ! V_2 -> V_131 )
return;
V_19 = 0 ;
switch ( T_3 ) {
case 0x88 :
V_19 = V_132 ;
break;
case 0xaa :
V_19 = V_133 ;
break;
case 0x66 :
V_19 = V_134 ;
break;
}
if ( V_19 ) {
F_53 ( V_2 -> V_131 , V_19 , 1 ) ;
F_54 ( V_2 -> V_131 ) ;
F_53 ( V_2 -> V_131 , V_19 , 0 ) ;
F_54 ( V_2 -> V_131 ) ;
}
#endif
}
static T_6 F_55 ( int V_135 , void * V_136 )
{
struct V_1 * V_2 = V_136 ;
T_2 V_137 ;
int V_91 ;
V_137 = F_8 ( V_2 -> V_5 + V_138 ) ;
if ( V_137 == 0xff )
return V_139 ;
if ( V_137 & V_140 )
#ifdef F_49
F_48 ( ( unsigned long ) V_2 ) ;
#else
F_56 ( & V_2 -> V_141 ) ;
#endif
if ( V_137 & V_142 ) {
T_2 V_143 = F_8 ( V_2 -> V_5 + V_144 ) ;
if ( ! ( V_143 & V_145 ) ) {
V_143 = F_8 ( V_2 -> V_5 + V_146 ) ;
if ( V_143 & V_147 ) {
F_6 ( V_147 , V_2 -> V_5 + V_146 ) ;
F_23 ( & V_2 -> V_47 ) ;
for ( V_91 = 0 ; V_91 < V_2 -> V_148 ; V_91 ++ ) {
struct V_29 * V_30 = & V_2 -> V_149 [ V_91 ] ;
if ( V_30 -> V_50 )
F_46 ( V_2 , V_30 ) ;
}
F_24 ( & V_2 -> V_47 ) ;
}
}
}
#if 0
if ((status & MPU401_INT_PENDING) && chip->rmidi)
snd_mpu401_uart_interrupt(irq, chip->rmidi->private_data, regs);
#endif
F_6 ( V_137 , V_2 -> V_5 + V_138 ) ;
return V_150 ;
}
static int
F_57 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
int V_91 ;
struct V_29 * V_30 ;
F_41 ( & V_2 -> V_47 ) ;
for ( V_91 = 0 ; V_91 < V_2 -> V_148 ; V_91 ++ ) {
V_30 = & V_2 -> V_149 [ V_91 ] ;
if ( ! V_30 -> V_151 )
goto V_152;
}
F_42 ( & V_2 -> V_47 ) ;
return - V_153 ;
V_152:
V_30 -> V_151 = 1 ;
V_30 -> V_50 = 0 ;
F_42 ( & V_2 -> V_47 ) ;
V_32 -> V_43 -> V_44 = V_30 ;
V_30 -> V_102 = V_32 ;
if ( V_32 -> V_34 == V_35 ) {
V_30 -> V_84 [ 0 ] = & V_2 -> V_154 ;
} else
V_30 -> V_84 [ 0 ] = & V_2 -> V_155 ;
V_30 -> V_84 [ 1 ] = & V_2 -> V_156 ;
V_30 -> V_84 [ 2 ] = & V_2 -> V_157 ;
return 0 ;
}
static void
F_58 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
struct V_29 * V_30 = V_32 -> V_43 -> V_44 ;
if ( V_30 == NULL )
return;
F_41 ( & V_2 -> V_47 ) ;
if ( V_30 -> V_102 && V_30 -> V_50 )
F_19 ( V_2 , V_30 , V_30 -> V_102 ) ;
if ( V_30 -> V_83 ) {
F_15 ( V_2 , V_30 -> V_84 [ 0 ] , V_30 -> V_7 [ 0 ] ) ;
F_15 ( V_2 , V_30 -> V_84 [ 1 ] , V_30 -> V_7 [ 1 ] ) ;
F_15 ( V_2 , V_30 -> V_84 [ 2 ] , V_30 -> V_7 [ 2 ] ) ;
V_30 -> V_83 = 0 ;
}
V_30 -> V_50 = 0 ;
V_30 -> V_151 = 0 ;
F_42 ( & V_2 -> V_47 ) ;
}
static int
F_59 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_21 ( V_32 ) ;
struct V_58 * V_43 = V_32 -> V_43 ;
int V_45 ;
if ( ( V_45 = F_57 ( V_2 , V_32 ) ) < 0 )
return V_45 ;
V_43 -> V_158 = V_159 ;
return 0 ;
}
static int
F_60 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_21 ( V_32 ) ;
F_58 ( V_2 , V_32 ) ;
return 0 ;
}
static int
F_61 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_21 ( V_32 ) ;
struct V_58 * V_43 = V_32 -> V_43 ;
int V_45 ;
if ( ( V_45 = F_57 ( V_2 , V_32 ) ) < 0 )
return V_45 ;
V_43 -> V_158 = V_160 ;
return 0 ;
}
static int
F_62 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_21 ( V_32 ) ;
F_58 ( V_2 , V_32 ) ;
return 0 ;
}
static int T_7
F_63 ( struct V_1 * V_2 , int V_161 )
{
struct V_162 * V_163 ;
int V_45 ;
V_45 = F_64 ( V_2 -> V_128 , V_2 -> V_128 -> V_164 , V_161 ,
V_165 , V_166 , & V_163 ) ;
if ( V_45 < 0 )
return V_45 ;
F_65 ( V_163 , V_35 , & V_167 ) ;
F_65 ( V_163 , V_40 , & V_168 ) ;
V_163 -> V_44 = V_2 ;
V_163 -> V_169 = 0 ;
strcpy ( V_163 -> V_170 , V_2 -> V_128 -> V_164 ) ;
V_2 -> V_163 = V_163 ;
F_66 ( V_163 , V_171 ,
F_67 ( V_2 -> V_172 ) , 64 * 1024 , 64 * 1024 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 )
{
int V_91 = 10000 ;
do {
if ( ! ( F_7 ( V_2 , 0x30 ) & 1 ) )
return 0 ;
F_69 () ;
} while ( V_91 -- > 0 );
F_37 ( V_106 L_2 ) ;
return 1 ;
}
static unsigned short
F_70 ( struct V_173 * V_123 , unsigned short V_4 )
{
struct V_1 * V_2 = V_123 -> V_44 ;
#ifndef F_49
unsigned long V_114 ;
#endif
unsigned short V_12 = 0xffff ;
if ( F_68 ( V_2 ) )
goto V_174;
#ifndef F_49
F_50 ( & V_2 -> V_122 , V_114 ) ;
#endif
F_5 ( V_2 , 0x80 | ( V_4 & 0x7f ) , V_127 ) ;
if ( F_68 ( V_2 ) )
goto V_175;
V_12 = F_3 ( V_2 , V_126 ) ;
V_175:
#ifndef F_49
F_52 ( & V_2 -> V_122 , V_114 ) ;
#endif
V_174:
return V_12 ;
}
static void
F_71 ( struct V_173 * V_123 , unsigned short V_4 , unsigned short V_19 )
{
struct V_1 * V_2 = V_123 -> V_44 ;
#ifndef F_49
unsigned long V_114 ;
#endif
if ( F_68 ( V_2 ) )
return;
#ifndef F_49
F_50 ( & V_2 -> V_122 , V_114 ) ;
#endif
F_1 ( V_2 , V_19 , V_126 ) ;
F_5 ( V_2 , V_4 & 0x7f , V_127 ) ;
#ifndef F_49
F_52 ( & V_2 -> V_122 , V_114 ) ;
#endif
}
static void F_72 ( int V_176 , int V_177 )
{
V_177 = V_177 ? 1 : 0 ;
F_2 ( ( F_4 ( V_176 + V_178 ) & ~ V_179 ) | V_177 ,
V_176 + V_178 ) ;
F_2 ( ( F_4 ( V_176 + V_180 ) & ~ V_181 ) | V_177 ,
V_176 + V_180 ) ;
F_2 ( ( F_4 ( V_176 + V_182 ) & ~ V_183 ) | V_177 ,
V_176 + V_182 ) ;
}
static int F_73 ( struct V_1 * V_2 )
{
T_1 V_184 ;
if ( F_68 ( V_2 ) )
return 1 ;
F_5 ( V_2 , 0x80 | ( V_185 & 0x7f ) , 0x30 ) ;
if ( F_68 ( V_2 ) )
return 1 ;
V_184 = F_3 ( V_2 , 0x32 ) ;
return ( V_184 == 0 ) || ( V_184 == 0xffff ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
T_1 V_186 ;
int V_187 = 0 , V_188 = 0 , V_91 ;
int V_176 = V_2 -> V_5 ;
if ( V_2 -> V_189 ) {
V_187 = 50 ;
V_188 = 800 ;
} else {
V_187 = 20 ;
V_188 = 500 ;
}
for ( V_91 = 0 ; V_91 < 5 ; V_91 ++ ) {
V_186 = F_4 ( V_176 + V_190 ) ;
if ( ! V_2 -> V_191 )
V_186 |= 0x10 ;
F_72 ( V_176 , 0 ) ;
F_2 ( V_192 , V_176 + V_193 ) ;
F_75 ( 20 ) ;
F_2 ( V_186 & ~ V_194 , V_176 + V_190 ) ;
F_2 ( ~ V_194 , V_176 + V_195 ) ;
F_2 ( 0 , V_176 + V_196 ) ;
F_2 ( V_186 | V_194 , V_176 + V_190 ) ;
F_76 ( F_77 ( V_187 ) ) ;
F_2 ( V_194 , V_176 + V_196 ) ;
F_75 ( 5 ) ;
F_2 ( V_192 | V_197 , V_176 + V_193 ) ;
F_2 ( ~ 0 , V_176 + V_195 ) ;
F_76 ( F_77 ( V_188 ) ) ;
if ( ! F_73 ( V_2 ) )
break;
V_187 += 10 ;
V_188 += 100 ;
F_78 ( L_3 ,
V_187 , V_188 ) ;
}
#if 0
tmp = inw(io + RING_BUS_CTRL_A);
outw(RAC_SDFS_ENABLE|LAC_SDFS_ENABLE, io + RING_BUS_CTRL_A);
msleep(20);
outw(tmp, io + RING_BUS_CTRL_A);
msleep(50);
#endif
}
static int T_7 F_79 ( struct V_1 * V_2 )
{
struct V_198 * V_199 ;
struct V_200 V_123 ;
#ifndef F_49
struct V_201 V_202 ;
#endif
int V_45 ;
static struct V_203 V_204 = {
. V_205 = F_71 ,
. V_206 = F_70 ,
} ;
if ( ( V_45 = V_198 ( V_2 -> V_128 , 0 , & V_204 , NULL , & V_199 ) ) < 0 )
return V_45 ;
memset ( & V_123 , 0 , sizeof( V_123 ) ) ;
V_123 . V_44 = V_2 ;
if ( ( V_45 = F_80 ( V_199 , & V_123 , & V_2 -> V_123 ) ) < 0 )
return V_45 ;
F_81 ( V_2 -> V_123 , V_207 , 0x8000 | ( 15 << 8 ) | 15 ) ;
F_76 ( F_77 ( 100 ) ) ;
F_81 ( V_2 -> V_123 , V_207 , 0 ) ;
#ifndef F_49
memset ( & V_202 , 0 , sizeof( V_202 ) ) ;
V_202 . V_208 = V_209 ;
strcpy ( V_202 . V_170 , L_4 ) ;
V_2 -> V_120 = F_82 ( V_2 -> V_128 , & V_202 ) ;
memset ( & V_202 , 0 , sizeof( V_202 ) ) ;
V_202 . V_208 = V_209 ;
strcpy ( V_202 . V_170 , L_5 ) ;
V_2 -> V_121 = F_82 ( V_2 -> V_128 , & V_202 ) ;
#endif
return 0 ;
}
static void F_83 ( struct V_1 * V_2 )
{
unsigned int V_91 ;
const T_1 * V_12 ;
for ( V_91 = 0 ; V_91 < ( V_210 * V_211 ) / 2 ; V_91 ++ )
F_10 ( V_2 , V_20 ,
V_212 + V_91 , 0 ) ;
for ( V_91 = 0 ; V_91 < ( V_210 * V_211 ) / 2 ; V_91 ++ )
F_10 ( V_2 , V_20 ,
V_213 + V_91 , 0 ) ;
F_10 ( V_2 , V_20 ,
V_214 ,
V_215 ) ;
V_12 = ( const T_1 * ) V_2 -> V_216 -> V_12 ;
for ( V_91 = 0 ; V_91 * 2 < V_2 -> V_216 -> V_217 ; V_91 ++ ) {
F_10 ( V_2 , V_218 ,
V_219 + V_91 ,
F_84 ( V_12 [ V_91 ] ) ) ;
}
V_12 = ( const T_1 * ) V_2 -> V_220 -> V_12 ;
for ( V_91 = 0 ; V_91 * 2 < V_2 -> V_220 -> V_217 ; V_91 ++ ) {
F_10 ( V_2 , V_218 ,
0x400 + V_91 , F_84 ( V_12 [ V_91 ] ) ) ;
}
for ( V_91 = 0 ; V_91 < V_221 ; V_91 ++ ) {
F_10 ( V_2 , V_218 ,
0x400 + V_93 + V_91 ,
V_222 [ V_91 ] ) ;
}
F_10 ( V_2 , V_218 ,
0x400 + V_93 + V_221 ,
0x8000 ) ;
F_10 ( V_2 , V_20 ,
V_223 ,
0x400 ) ;
F_10 ( V_2 , V_20 ,
V_39 , 0 ) ;
F_10 ( V_2 , V_20 ,
V_224 , V_225 ) ;
F_10 ( V_2 , V_20 ,
V_226 , V_225 ) ;
V_2 -> V_154 . V_22 = 0 ;
V_2 -> V_154 . V_21 = V_227 ;
V_2 -> V_154 . V_228 = V_229 ;
V_2 -> V_155 . V_22 = 0 ;
V_2 -> V_155 . V_21 = V_230 ;
V_2 -> V_155 . V_228 = V_231 ;
V_2 -> V_157 . V_22 = 0 ;
V_2 -> V_157 . V_21 = V_215 ;
V_2 -> V_157 . V_228 = V_232 ;
V_2 -> V_156 . V_22 = 0 ;
V_2 -> V_156 . V_21 = V_233 ;
V_2 -> V_156 . V_228 = V_234 ;
}
static int T_7 F_85 ( struct V_1 * V_2 , struct V_29 * V_30 , int V_7 )
{
int V_235 = 2 * ( V_61 / 2 +
V_59 / 2 +
1 + V_60 / 2 + 1 ) ;
int V_236 , V_91 ;
V_235 = F_86 ( V_235 , 256 ) ;
V_236 = 0x1100 + ( ( V_235 / 2 ) * V_7 ) ;
if ( ( V_236 + ( V_235 / 2 ) ) >= 0x1c00 ) {
F_37 ( V_106 L_6 ,
V_235 , V_7 , V_236 ) ;
return - V_153 ;
}
V_30 -> V_237 = V_7 ;
V_30 -> V_37 . V_92 = 0x400 ;
V_30 -> V_37 . V_12 = V_236 ;
for ( V_91 = V_235 / 2 ; V_91 > 0 ; V_236 ++ , V_91 -- ) {
F_10 ( V_2 , V_20 ,
V_236 , 0 ) ;
}
return 0 ;
}
static void
F_87 ( struct V_1 * V_2 , int V_238 )
{
int V_176 = V_2 -> V_5 ;
T_1 V_239 , V_240 ;
if ( ! V_2 -> V_241 )
return;
V_240 = V_238 ? 0 : 1 ;
V_240 = V_240 << V_2 -> V_242 ;
V_239 = 1 << V_2 -> V_242 ;
F_2 ( ~ V_239 , V_176 + V_195 ) ;
F_2 ( F_4 ( V_176 + V_190 ) | V_239 ,
V_176 + V_190 ) ;
F_2 ( ( V_243 | V_194 | V_240 ) ,
V_176 + V_196 ) ;
F_2 ( 0xffff , V_176 + V_195 ) ;
}
static void
F_88 ( struct V_1 * V_2 )
{
unsigned long V_176 = V_2 -> V_5 ;
T_1 V_19 = V_244 | V_245 ;
if ( ! V_2 -> V_246 )
return;
F_2 ( 0xffff , V_176 + V_195 ) ;
F_2 ( 0x0000 , V_176 + V_196 ) ;
F_2 ( ~ V_19 , V_176 + V_195 ) ;
F_2 ( F_4 ( V_176 + V_190 ) & ~ V_19 , V_176 + V_190 ) ;
F_2 ( V_19 , V_176 + V_195 ) ;
F_2 ( 0xffff , V_176 + V_195 ) ;
}
static int
F_89 ( struct V_1 * V_2 )
{
struct V_247 * V_248 = V_2 -> V_172 ;
unsigned long V_176 = V_2 -> V_5 ;
T_4 V_249 ;
T_1 V_250 ;
T_2 V_251 ;
F_90 ( V_248 , V_252 , & V_250 ) ;
V_250 &= ~ ( V_253 | V_254 |
V_255 | V_256 | V_257 |
V_258 ) ;
F_91 ( V_248 , V_252 , V_250 ) ;
F_92 ( V_248 , V_259 , & V_249 ) ;
V_249 &= ~ ( V_260 | V_261 | V_262 ) ;
V_249 |= V_2 -> V_263 ;
V_249 |= V_261 ;
V_249 |= V_264 | V_265 | V_266 ;
F_93 ( V_248 , V_259 , V_249 ) ;
F_6 ( V_267 , V_2 -> V_5 + V_144 ) ;
F_92 ( V_248 , V_259 , & V_249 ) ;
V_249 &= ~ V_268 ;
if ( ! V_2 -> V_189 ) {
V_249 &= ~ V_269 ;
V_249 |= V_270 ;
}
V_249 &= ~ ( V_271 | V_272 ) ;
F_93 ( V_248 , V_259 , V_249 ) ;
if ( V_2 -> V_189 ) {
F_92 ( V_248 , V_273 , & V_249 ) ;
V_249 |= V_274 ;
F_93 ( V_248 , V_273 , V_249 ) ;
}
V_251 = F_8 ( V_2 -> V_5 + V_275 ) ;
V_251 &= ~ ( V_276 | V_277 ) ;
V_251 |= V_277 ;
V_251 |= V_278 ;
F_6 ( V_251 , V_2 -> V_5 + V_275 ) ;
F_83 ( V_2 ) ;
F_6 ( V_279 , V_2 -> V_5 + V_144 ) ;
F_6 ( 0x00 , V_176 + V_280 ) ;
F_6 ( 0x88 , V_176 + V_115 ) ;
F_6 ( 0x88 , V_176 + V_116 ) ;
F_6 ( 0x88 , V_176 + V_117 ) ;
F_6 ( 0x88 , V_176 + V_118 ) ;
return 0 ;
}
static void
F_94 ( struct V_1 * V_2 )
{
unsigned long V_176 = V_2 -> V_5 ;
unsigned short V_19 ;
V_19 = V_281 ;
if ( V_2 -> V_263 & V_260 )
V_19 |= V_282 ;
F_6 ( V_19 , V_2 -> V_5 + V_138 ) ;
F_2 ( V_19 , V_176 + V_27 ) ;
F_6 ( F_8 ( V_176 + V_283 ) | V_284 ,
V_176 + V_283 ) ;
}
static int F_95 ( struct V_1 * V_2 )
{
struct V_29 * V_30 ;
int V_91 ;
#ifdef F_49
if ( V_2 -> V_131 )
F_96 ( V_2 -> V_131 ) ;
#endif
if ( V_2 -> V_149 ) {
F_41 ( & V_2 -> V_47 ) ;
for ( V_91 = 0 ; V_91 < V_2 -> V_148 ; V_91 ++ ) {
V_30 = & V_2 -> V_149 [ V_91 ] ;
if ( V_30 -> V_102 && V_30 -> V_50 )
F_19 ( V_2 , V_30 , V_30 -> V_102 ) ;
}
F_42 ( & V_2 -> V_47 ) ;
F_97 ( V_2 -> V_149 ) ;
}
if ( V_2 -> V_5 ) {
F_2 ( 0 , V_2 -> V_5 + V_27 ) ;
}
#ifdef F_98
F_99 ( V_2 -> V_285 ) ;
#endif
if ( V_2 -> V_135 >= 0 )
F_100 ( V_2 -> V_135 , V_2 ) ;
if ( V_2 -> V_5 )
F_101 ( V_2 -> V_172 ) ;
F_102 ( V_2 -> V_216 ) ;
F_102 ( V_2 -> V_220 ) ;
F_103 ( V_2 -> V_172 ) ;
F_97 ( V_2 ) ;
return 0 ;
}
static int F_104 ( struct V_247 * V_172 , T_8 V_286 )
{
struct V_287 * V_128 = F_105 ( V_172 ) ;
struct V_1 * V_2 = V_128 -> V_44 ;
int V_91 , V_288 ;
if ( V_2 -> V_285 == NULL )
return 0 ;
V_2 -> V_119 = 1 ;
F_106 ( V_128 , V_289 ) ;
F_107 ( V_2 -> V_163 ) ;
F_108 ( V_2 -> V_123 ) ;
F_12 ( 10 ) ;
F_11 ( V_2 ) ;
V_288 = 0 ;
for ( V_91 = V_219 ; V_91 <= V_290 ; V_91 ++ )
V_2 -> V_285 [ V_288 ++ ] =
F_9 ( V_2 , V_218 , V_91 ) ;
for ( V_91 = V_291 ; V_91 <= V_292 ; V_91 ++ )
V_2 -> V_285 [ V_288 ++ ] =
F_9 ( V_2 , V_20 , V_91 ) ;
F_103 ( V_172 ) ;
F_109 ( V_172 ) ;
F_110 ( V_172 , F_111 ( V_172 , V_286 ) ) ;
return 0 ;
}
static int F_112 ( struct V_247 * V_172 )
{
struct V_287 * V_128 = F_105 ( V_172 ) ;
struct V_1 * V_2 = V_128 -> V_44 ;
int V_91 , V_288 ;
if ( V_2 -> V_285 == NULL )
return 0 ;
F_110 ( V_172 , V_293 ) ;
F_113 ( V_172 ) ;
if ( F_114 ( V_172 ) < 0 ) {
F_115 ( V_106 L_7
L_8 ) ;
F_116 ( V_128 ) ;
return - V_294 ;
}
F_117 ( V_172 ) ;
F_1 ( V_2 , 0 , 0x54 ) ;
F_1 ( V_2 , 0 , 0x56 ) ;
F_89 ( V_2 ) ;
F_11 ( V_2 ) ;
F_74 ( V_2 ) ;
V_288 = 0 ;
for ( V_91 = V_219 ; V_91 <= V_290 ; V_91 ++ )
F_10 ( V_2 , V_218 , V_91 ,
V_2 -> V_285 [ V_288 ++ ] ) ;
for ( V_91 = V_291 ; V_91 <= V_292 ; V_91 ++ )
F_10 ( V_2 , V_20 , V_91 ,
V_2 -> V_285 [ V_288 ++ ] ) ;
F_10 ( V_2 , V_20 ,
V_295 , 0 ) ;
F_118 ( V_2 -> V_123 ) ;
F_13 ( V_2 ) ;
F_94 ( V_2 ) ;
F_87 ( V_2 , 1 ) ;
F_88 ( V_2 ) ;
F_106 ( V_128 , V_296 ) ;
V_2 -> V_119 = 0 ;
return 0 ;
}
static int T_7 F_119 ( struct V_1 * V_2 )
{
struct V_131 * V_131 ;
int V_45 ;
V_131 = F_120 () ;
if ( ! V_131 )
return - V_153 ;
snprintf ( V_2 -> V_297 , sizeof( V_2 -> V_297 ) , L_9 ,
F_121 ( V_2 -> V_172 ) ) ;
V_131 -> V_170 = V_2 -> V_128 -> V_164 ;
V_131 -> V_297 = V_2 -> V_297 ;
V_131 -> V_130 . V_298 = V_299 ;
V_131 -> V_130 . V_300 = V_2 -> V_172 -> V_300 ;
V_131 -> V_130 . V_301 = V_2 -> V_172 -> V_161 ;
V_131 -> V_302 . V_303 = & V_2 -> V_172 -> V_302 ;
F_122 ( V_304 , V_131 -> V_305 ) ;
F_122 ( V_132 , V_131 -> V_306 ) ;
F_122 ( V_134 , V_131 -> V_306 ) ;
F_122 ( V_133 , V_131 -> V_306 ) ;
V_45 = F_123 ( V_131 ) ;
if ( V_45 ) {
F_124 ( V_131 ) ;
return V_45 ;
}
V_2 -> V_131 = V_131 ;
return 0 ;
}
static int F_125 ( struct V_307 * V_161 )
{
struct V_1 * V_2 = V_161 -> V_308 ;
return F_95 ( V_2 ) ;
}
static int T_7
F_126 ( struct V_287 * V_128 , struct V_247 * V_172 ,
int V_309 ,
int V_242 ,
struct V_1 * * V_310 )
{
struct V_1 * V_2 ;
int V_91 , V_45 ;
const struct V_311 * V_312 ;
static struct V_313 V_204 = {
. V_314 = F_125 ,
} ;
* V_310 = NULL ;
if ( F_114 ( V_172 ) )
return - V_294 ;
if ( F_127 ( V_172 , F_128 ( 28 ) ) < 0 ||
F_129 ( V_172 , F_128 ( 28 ) ) < 0 ) {
F_37 ( V_106 L_10 ) ;
F_103 ( V_172 ) ;
return - V_46 ;
}
V_2 = F_130 ( sizeof( * V_2 ) , V_315 ) ;
if ( V_2 == NULL ) {
F_103 ( V_172 ) ;
return - V_153 ;
}
F_131 ( & V_2 -> V_47 ) ;
#ifndef F_49
F_131 ( & V_2 -> V_122 ) ;
#endif
switch ( V_172 -> V_161 ) {
case V_316 :
case V_317 :
case V_318 :
case V_319 :
V_2 -> V_189 = 1 ;
break;
}
V_2 -> V_128 = V_128 ;
V_2 -> V_172 = V_172 ;
V_2 -> V_135 = - 1 ;
V_2 -> V_241 = V_309 ;
if ( V_242 >= 0 && V_242 <= 0x0f )
V_2 -> V_242 = V_242 ;
else {
V_312 = F_132 ( V_172 , V_320 ) ;
if ( V_312 ) {
F_133 ( V_321 L_11
L_12 , V_312 -> V_170 ) ;
V_2 -> V_242 = V_312 -> V_3 ;
} else if ( V_2 -> V_189 )
V_2 -> V_242 = V_322 ;
else
V_2 -> V_242 = V_323 ;
}
V_312 = F_132 ( V_172 , V_324 ) ;
if ( V_312 ) {
F_133 ( V_321 L_13
L_12 , V_312 -> V_170 ) ;
V_2 -> V_191 = 1 ;
}
V_312 = F_132 ( V_172 , V_325 ) ;
if ( V_312 )
V_2 -> V_263 = V_312 -> V_3 ;
if ( F_132 ( V_172 , V_326 ) )
V_2 -> V_246 = 1 ;
V_2 -> V_148 = V_327 ;
V_2 -> V_149 = F_134 ( V_2 -> V_148 , sizeof( struct V_29 ) ,
V_315 ) ;
if ( V_2 -> V_149 == NULL ) {
F_97 ( V_2 ) ;
F_103 ( V_172 ) ;
return - V_153 ;
}
V_45 = F_135 ( & V_2 -> V_216 ,
L_14 , & V_172 -> V_302 ) ;
if ( V_45 < 0 ) {
F_95 ( V_2 ) ;
return V_45 ;
}
V_45 = F_135 ( & V_2 -> V_220 ,
L_15 , & V_172 -> V_302 ) ;
if ( V_45 < 0 ) {
F_95 ( V_2 ) ;
return V_45 ;
}
if ( ( V_45 = F_136 ( V_172 , V_128 -> V_164 ) ) < 0 ) {
F_95 ( V_2 ) ;
return V_45 ;
}
V_2 -> V_5 = F_137 ( V_172 , 0 ) ;
F_117 ( V_172 ) ;
F_89 ( V_2 ) ;
F_11 ( V_2 ) ;
F_74 ( V_2 ) ;
F_87 ( V_2 , 1 ) ;
F_88 ( V_2 ) ;
#ifndef F_49
F_138 ( & V_2 -> V_141 , F_48 , ( unsigned long ) V_2 ) ;
#endif
if ( F_139 ( V_172 -> V_135 , F_55 , V_328 ,
V_128 -> V_164 , V_2 ) ) {
F_37 ( V_106 L_16 , V_172 -> V_135 ) ;
F_95 ( V_2 ) ;
return - V_153 ;
}
V_2 -> V_135 = V_172 -> V_135 ;
#ifdef F_98
V_2 -> V_285 = F_140 ( sizeof( T_1 ) * ( V_329 + V_330 ) ) ;
if ( V_2 -> V_285 == NULL )
F_37 ( V_331 L_17 ) ;
#endif
if ( ( V_45 = F_141 ( V_128 , V_332 , V_2 , & V_204 ) ) < 0 ) {
F_95 ( V_2 ) ;
return V_45 ;
}
if ( ( V_45 = F_79 ( V_2 ) ) < 0 )
return V_45 ;
for ( V_91 = 0 ; V_91 < V_2 -> V_148 ; V_91 ++ ) {
struct V_29 * V_30 = & V_2 -> V_149 [ V_91 ] ;
if ( ( V_45 = F_85 ( V_2 , V_30 , V_91 ) ) < 0 )
return V_45 ;
}
if ( ( V_45 = F_63 ( V_2 , 0 ) ) < 0 )
return V_45 ;
#ifdef F_49
if ( V_2 -> V_263 & V_260 ) {
V_45 = F_119 ( V_2 ) ;
if ( V_45 )
F_37 ( V_331 L_18
L_19 , V_45 ) ;
}
#endif
F_94 ( V_2 ) ;
F_13 ( V_2 ) ;
F_142 ( V_128 , & V_172 -> V_302 ) ;
* V_310 = V_2 ;
return 0 ;
}
static int T_7
F_143 ( struct V_247 * V_172 , const struct V_333 * V_334 )
{
static int V_302 ;
struct V_287 * V_128 ;
struct V_1 * V_2 ;
int V_45 ;
if ( ( ( V_172 -> V_335 >> 8 ) & 0xffff ) != V_336 )
return - V_337 ;
if ( V_302 >= V_338 )
return - V_337 ;
if ( ! V_238 [ V_302 ] ) {
V_302 ++ ;
return - V_339 ;
}
V_45 = F_144 ( V_7 [ V_302 ] , V_130 [ V_302 ] , V_340 , 0 , & V_128 ) ;
if ( V_45 < 0 )
return V_45 ;
switch ( V_172 -> V_161 ) {
case V_316 :
case V_317 :
strcpy ( V_128 -> V_164 , L_20 ) ;
break;
case V_318 :
case V_319 :
strcpy ( V_128 -> V_164 , L_21 ) ;
break;
default:
strcpy ( V_128 -> V_164 , L_22 ) ;
break;
}
if ( ( V_45 = F_126 ( V_128 , V_172 ,
V_241 [ V_302 ] ,
V_242 [ V_302 ] ,
& V_2 ) ) < 0 ) {
F_145 ( V_128 ) ;
return V_45 ;
}
V_128 -> V_44 = V_2 ;
sprintf ( V_128 -> V_341 , L_23 , V_128 -> V_164 ) ;
sprintf ( V_128 -> V_342 , L_24 ,
V_128 -> V_341 , V_2 -> V_5 , V_2 -> V_135 ) ;
if ( ( V_45 = F_146 ( V_128 ) ) < 0 ) {
F_145 ( V_128 ) ;
return V_45 ;
}
#if 0
err = snd_mpu401_uart_new(chip->card, 0, MPU401_HW_MPU401,
chip->iobase + MPU401_DATA_PORT,
MPU401_INFO_INTEGRATED,
chip->irq, 0, &chip->rmidi);
if (err < 0)
printk(KERN_WARNING "maestro3: no MIDI support.\n");
#endif
F_147 ( V_172 , V_128 ) ;
V_302 ++ ;
return 0 ;
}
static void T_9 F_148 ( struct V_247 * V_172 )
{
F_145 ( F_105 ( V_172 ) ) ;
F_147 ( V_172 , NULL ) ;
}
static int T_10 F_149 ( void )
{
return F_150 ( & V_164 ) ;
}
static void T_11 F_151 ( void )
{
F_152 ( & V_164 ) ;
}

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
static void F_48 ( struct V_114 * V_115 )
{
struct V_1 * V_2 = F_49 ( V_115 , struct V_1 , V_116 ) ;
int T_3 , V_19 ;
T_3 = F_8 ( V_2 -> V_5 + V_117 ) & 0xee ;
F_6 ( 0x88 , V_2 -> V_5 + V_117 ) ;
F_6 ( 0x88 , V_2 -> V_5 + V_118 ) ;
F_6 ( 0x88 , V_2 -> V_5 + V_119 ) ;
F_6 ( 0x88 , V_2 -> V_5 + V_120 ) ;
if ( V_2 -> V_121 )
return;
#ifndef F_50
if ( ! V_2 -> V_122 || ! V_2 -> V_123 )
return;
V_19 = F_51 ( V_2 -> V_124 , V_125 ) ;
switch ( T_3 ) {
case 0x88 :
V_19 ^= 0x8000 ;
break;
case 0xaa :
if ( ( V_19 & 0x7f ) > 0 )
V_19 -- ;
if ( ( V_19 & 0x7f00 ) > 0 )
V_19 -= 0x0100 ;
break;
case 0x66 :
if ( ( V_19 & 0x7f ) < 0x1f )
V_19 ++ ;
if ( ( V_19 & 0x7f00 ) < 0x1f00 )
V_19 += 0x0100 ;
break;
}
if ( F_52 ( V_2 -> V_124 , V_125 , V_19 ) )
F_53 ( V_2 -> V_126 , V_127 ,
& V_2 -> V_122 -> V_128 ) ;
#else
if ( ! V_2 -> V_129 )
return;
V_19 = 0 ;
switch ( T_3 ) {
case 0x88 :
V_19 = V_130 ;
break;
case 0xaa :
V_19 = V_131 ;
break;
case 0x66 :
V_19 = V_132 ;
break;
}
if ( V_19 ) {
F_54 ( V_2 -> V_129 , V_19 , 1 ) ;
F_55 ( V_2 -> V_129 ) ;
F_54 ( V_2 -> V_129 , V_19 , 0 ) ;
F_55 ( V_2 -> V_129 ) ;
}
#endif
}
static T_6 F_56 ( int V_133 , void * V_134 )
{
struct V_1 * V_2 = V_134 ;
T_2 V_135 ;
int V_91 ;
V_135 = F_8 ( V_2 -> V_5 + V_136 ) ;
if ( V_135 == 0xff )
return V_137 ;
if ( V_135 & V_138 )
F_57 ( & V_2 -> V_116 ) ;
if ( V_135 & V_139 ) {
T_2 V_140 = F_8 ( V_2 -> V_5 + V_141 ) ;
if ( ! ( V_140 & V_142 ) ) {
V_140 = F_8 ( V_2 -> V_5 + V_143 ) ;
if ( V_140 & V_144 ) {
F_6 ( V_144 , V_2 -> V_5 + V_143 ) ;
F_23 ( & V_2 -> V_47 ) ;
for ( V_91 = 0 ; V_91 < V_2 -> V_145 ; V_91 ++ ) {
struct V_29 * V_30 = & V_2 -> V_146 [ V_91 ] ;
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
F_6 ( V_135 , V_2 -> V_5 + V_136 ) ;
return V_147 ;
}
static int
F_58 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
int V_91 ;
struct V_29 * V_30 ;
F_41 ( & V_2 -> V_47 ) ;
for ( V_91 = 0 ; V_91 < V_2 -> V_145 ; V_91 ++ ) {
V_30 = & V_2 -> V_146 [ V_91 ] ;
if ( ! V_30 -> V_148 )
goto V_149;
}
F_42 ( & V_2 -> V_47 ) ;
return - V_150 ;
V_149:
V_30 -> V_148 = 1 ;
V_30 -> V_50 = 0 ;
F_42 ( & V_2 -> V_47 ) ;
V_32 -> V_43 -> V_44 = V_30 ;
V_30 -> V_102 = V_32 ;
if ( V_32 -> V_34 == V_35 ) {
V_30 -> V_84 [ 0 ] = & V_2 -> V_151 ;
} else
V_30 -> V_84 [ 0 ] = & V_2 -> V_152 ;
V_30 -> V_84 [ 1 ] = & V_2 -> V_153 ;
V_30 -> V_84 [ 2 ] = & V_2 -> V_154 ;
return 0 ;
}
static void
F_59 ( struct V_1 * V_2 , struct V_31 * V_32 )
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
V_30 -> V_148 = 0 ;
F_42 ( & V_2 -> V_47 ) ;
}
static int
F_60 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_21 ( V_32 ) ;
struct V_58 * V_43 = V_32 -> V_43 ;
int V_45 ;
if ( ( V_45 = F_58 ( V_2 , V_32 ) ) < 0 )
return V_45 ;
V_43 -> V_155 = V_156 ;
return 0 ;
}
static int
F_61 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_21 ( V_32 ) ;
F_59 ( V_2 , V_32 ) ;
return 0 ;
}
static int
F_62 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_21 ( V_32 ) ;
struct V_58 * V_43 = V_32 -> V_43 ;
int V_45 ;
if ( ( V_45 = F_58 ( V_2 , V_32 ) ) < 0 )
return V_45 ;
V_43 -> V_155 = V_157 ;
return 0 ;
}
static int
F_63 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_21 ( V_32 ) ;
F_59 ( V_2 , V_32 ) ;
return 0 ;
}
static int
F_64 ( struct V_1 * V_2 , int V_158 )
{
struct V_159 * V_160 ;
int V_45 ;
V_45 = F_65 ( V_2 -> V_126 , V_2 -> V_126 -> V_161 , V_158 ,
V_162 , V_163 , & V_160 ) ;
if ( V_45 < 0 )
return V_45 ;
F_66 ( V_160 , V_35 , & V_164 ) ;
F_66 ( V_160 , V_40 , & V_165 ) ;
V_160 -> V_44 = V_2 ;
V_160 -> V_166 = 0 ;
strcpy ( V_160 -> V_167 , V_2 -> V_126 -> V_161 ) ;
V_2 -> V_160 = V_160 ;
F_67 ( V_160 , V_168 ,
F_68 ( V_2 -> V_169 ) , 64 * 1024 , 64 * 1024 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 )
{
int V_91 = 10000 ;
do {
if ( ! ( F_7 ( V_2 , 0x30 ) & 1 ) )
return 0 ;
F_70 () ;
} while ( V_91 -- > 0 );
F_37 ( V_106 L_2 ) ;
return 1 ;
}
static unsigned short
F_71 ( struct V_170 * V_124 , unsigned short V_4 )
{
struct V_1 * V_2 = V_124 -> V_44 ;
unsigned short V_12 = 0xffff ;
if ( F_69 ( V_2 ) )
goto V_171;
F_5 ( V_2 , 0x80 | ( V_4 & 0x7f ) , V_172 ) ;
if ( F_69 ( V_2 ) )
goto V_171;
V_12 = F_3 ( V_2 , V_173 ) ;
V_171:
return V_12 ;
}
static void
F_72 ( struct V_170 * V_124 , unsigned short V_4 , unsigned short V_19 )
{
struct V_1 * V_2 = V_124 -> V_44 ;
if ( F_69 ( V_2 ) )
return;
F_1 ( V_2 , V_19 , V_173 ) ;
F_5 ( V_2 , V_4 & 0x7f , V_172 ) ;
}
static void F_73 ( int V_174 , int V_175 )
{
V_175 = V_175 ? 1 : 0 ;
F_2 ( ( F_4 ( V_174 + V_176 ) & ~ V_177 ) | V_175 ,
V_174 + V_176 ) ;
F_2 ( ( F_4 ( V_174 + V_178 ) & ~ V_179 ) | V_175 ,
V_174 + V_178 ) ;
F_2 ( ( F_4 ( V_174 + V_180 ) & ~ V_181 ) | V_175 ,
V_174 + V_180 ) ;
}
static int F_74 ( struct V_1 * V_2 )
{
T_1 V_182 ;
if ( F_69 ( V_2 ) )
return 1 ;
F_5 ( V_2 , 0x80 | ( V_183 & 0x7f ) , 0x30 ) ;
if ( F_69 ( V_2 ) )
return 1 ;
V_182 = F_3 ( V_2 , 0x32 ) ;
return ( V_182 == 0 ) || ( V_182 == 0xffff ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
T_1 V_184 ;
int V_185 = 0 , V_186 = 0 , V_91 ;
int V_174 = V_2 -> V_5 ;
if ( V_2 -> V_187 ) {
V_185 = 50 ;
V_186 = 800 ;
} else {
V_185 = 20 ;
V_186 = 500 ;
}
for ( V_91 = 0 ; V_91 < 5 ; V_91 ++ ) {
V_184 = F_4 ( V_174 + V_188 ) ;
if ( ! V_2 -> V_189 )
V_184 |= 0x10 ;
F_73 ( V_174 , 0 ) ;
F_2 ( V_190 , V_174 + V_191 ) ;
F_76 ( 20 ) ;
F_2 ( V_184 & ~ V_192 , V_174 + V_188 ) ;
F_2 ( ~ V_192 , V_174 + V_193 ) ;
F_2 ( 0 , V_174 + V_194 ) ;
F_2 ( V_184 | V_192 , V_174 + V_188 ) ;
F_77 ( F_78 ( V_185 ) ) ;
F_2 ( V_192 , V_174 + V_194 ) ;
F_76 ( 5 ) ;
F_2 ( V_190 | V_195 , V_174 + V_191 ) ;
F_2 ( ~ 0 , V_174 + V_193 ) ;
F_77 ( F_78 ( V_186 ) ) ;
if ( ! F_74 ( V_2 ) )
break;
V_185 += 10 ;
V_186 += 100 ;
F_79 ( L_3 ,
V_185 , V_186 ) ;
}
#if 0
tmp = inw(io + RING_BUS_CTRL_A);
outw(RAC_SDFS_ENABLE|LAC_SDFS_ENABLE, io + RING_BUS_CTRL_A);
msleep(20);
outw(tmp, io + RING_BUS_CTRL_A);
msleep(50);
#endif
}
static int F_80 ( struct V_1 * V_2 )
{
struct V_196 * V_197 ;
struct V_198 V_124 ;
#ifndef F_50
struct V_199 V_200 ;
#endif
int V_45 ;
static struct V_201 V_202 = {
. V_203 = F_72 ,
. V_204 = F_71 ,
} ;
if ( ( V_45 = V_196 ( V_2 -> V_126 , 0 , & V_202 , NULL , & V_197 ) ) < 0 )
return V_45 ;
memset ( & V_124 , 0 , sizeof( V_124 ) ) ;
V_124 . V_44 = V_2 ;
if ( ( V_45 = F_81 ( V_197 , & V_124 , & V_2 -> V_124 ) ) < 0 )
return V_45 ;
F_82 ( V_2 -> V_124 , V_205 , 0x8000 | ( 15 << 8 ) | 15 ) ;
F_77 ( F_78 ( 100 ) ) ;
F_82 ( V_2 -> V_124 , V_205 , 0 ) ;
#ifndef F_50
memset ( & V_200 , 0 , sizeof( V_200 ) ) ;
V_200 . V_206 = V_207 ;
strcpy ( V_200 . V_167 , L_4 ) ;
V_2 -> V_122 = F_83 ( V_2 -> V_126 , & V_200 ) ;
memset ( & V_200 , 0 , sizeof( V_200 ) ) ;
V_200 . V_206 = V_207 ;
strcpy ( V_200 . V_167 , L_5 ) ;
V_2 -> V_123 = F_83 ( V_2 -> V_126 , & V_200 ) ;
#endif
return 0 ;
}
static void F_84 ( struct V_1 * V_2 )
{
unsigned int V_91 ;
const T_1 * V_12 ;
for ( V_91 = 0 ; V_91 < ( V_208 * V_209 ) / 2 ; V_91 ++ )
F_10 ( V_2 , V_20 ,
V_210 + V_91 , 0 ) ;
for ( V_91 = 0 ; V_91 < ( V_208 * V_209 ) / 2 ; V_91 ++ )
F_10 ( V_2 , V_20 ,
V_211 + V_91 , 0 ) ;
F_10 ( V_2 , V_20 ,
V_212 ,
V_213 ) ;
V_12 = ( const T_1 * ) V_2 -> V_214 -> V_12 ;
for ( V_91 = 0 ; V_91 * 2 < V_2 -> V_214 -> V_215 ; V_91 ++ ) {
F_10 ( V_2 , V_216 ,
V_217 + V_91 ,
F_85 ( V_12 [ V_91 ] ) ) ;
}
V_12 = ( const T_1 * ) V_2 -> V_218 -> V_12 ;
for ( V_91 = 0 ; V_91 * 2 < V_2 -> V_218 -> V_215 ; V_91 ++ ) {
F_10 ( V_2 , V_216 ,
0x400 + V_91 , F_85 ( V_12 [ V_91 ] ) ) ;
}
for ( V_91 = 0 ; V_91 < V_219 ; V_91 ++ ) {
F_10 ( V_2 , V_216 ,
0x400 + V_93 + V_91 ,
V_220 [ V_91 ] ) ;
}
F_10 ( V_2 , V_216 ,
0x400 + V_93 + V_219 ,
0x8000 ) ;
F_10 ( V_2 , V_20 ,
V_221 ,
0x400 ) ;
F_10 ( V_2 , V_20 ,
V_39 , 0 ) ;
F_10 ( V_2 , V_20 ,
V_222 , V_223 ) ;
F_10 ( V_2 , V_20 ,
V_224 , V_223 ) ;
V_2 -> V_151 . V_22 = 0 ;
V_2 -> V_151 . V_21 = V_225 ;
V_2 -> V_151 . V_226 = V_227 ;
V_2 -> V_152 . V_22 = 0 ;
V_2 -> V_152 . V_21 = V_228 ;
V_2 -> V_152 . V_226 = V_229 ;
V_2 -> V_154 . V_22 = 0 ;
V_2 -> V_154 . V_21 = V_213 ;
V_2 -> V_154 . V_226 = V_230 ;
V_2 -> V_153 . V_22 = 0 ;
V_2 -> V_153 . V_21 = V_231 ;
V_2 -> V_153 . V_226 = V_232 ;
}
static int F_86 ( struct V_1 * V_2 , struct V_29 * V_30 , int V_7 )
{
int V_233 = 2 * ( V_61 / 2 +
V_59 / 2 +
1 + V_60 / 2 + 1 ) ;
int V_234 , V_91 ;
V_233 = F_87 ( V_233 , 256 ) ;
V_234 = 0x1100 + ( ( V_233 / 2 ) * V_7 ) ;
if ( ( V_234 + ( V_233 / 2 ) ) >= 0x1c00 ) {
F_37 ( V_106 L_6 ,
V_233 , V_7 , V_234 ) ;
return - V_150 ;
}
V_30 -> V_235 = V_7 ;
V_30 -> V_37 . V_92 = 0x400 ;
V_30 -> V_37 . V_12 = V_234 ;
for ( V_91 = V_233 / 2 ; V_91 > 0 ; V_234 ++ , V_91 -- ) {
F_10 ( V_2 , V_20 ,
V_234 , 0 ) ;
}
return 0 ;
}
static void
F_88 ( struct V_1 * V_2 , int V_236 )
{
int V_174 = V_2 -> V_5 ;
T_1 V_237 , V_238 ;
if ( ! V_2 -> V_239 )
return;
V_238 = V_236 ? 0 : 1 ;
V_238 = V_238 << V_2 -> V_240 ;
V_237 = 1 << V_2 -> V_240 ;
F_2 ( ~ V_237 , V_174 + V_193 ) ;
F_2 ( F_4 ( V_174 + V_188 ) | V_237 ,
V_174 + V_188 ) ;
F_2 ( ( V_241 | V_192 | V_238 ) ,
V_174 + V_194 ) ;
F_2 ( 0xffff , V_174 + V_193 ) ;
}
static void
F_89 ( struct V_1 * V_2 )
{
unsigned long V_174 = V_2 -> V_5 ;
T_1 V_19 = V_242 | V_243 ;
if ( ! V_2 -> V_244 )
return;
F_2 ( 0xffff , V_174 + V_193 ) ;
F_2 ( 0x0000 , V_174 + V_194 ) ;
F_2 ( ~ V_19 , V_174 + V_193 ) ;
F_2 ( F_4 ( V_174 + V_188 ) & ~ V_19 , V_174 + V_188 ) ;
F_2 ( V_19 , V_174 + V_193 ) ;
F_2 ( 0xffff , V_174 + V_193 ) ;
}
static int
F_90 ( struct V_1 * V_2 )
{
struct V_245 * V_246 = V_2 -> V_169 ;
unsigned long V_174 = V_2 -> V_5 ;
T_4 V_247 ;
T_1 V_248 ;
T_2 V_249 ;
F_91 ( V_246 , V_250 , & V_248 ) ;
V_248 &= ~ ( V_251 | V_252 |
V_253 | V_254 | V_255 |
V_256 ) ;
F_92 ( V_246 , V_250 , V_248 ) ;
F_93 ( V_246 , V_257 , & V_247 ) ;
V_247 &= ~ ( V_258 | V_259 | V_260 ) ;
V_247 |= V_2 -> V_261 ;
V_247 |= V_259 ;
V_247 |= V_262 | V_263 | V_264 ;
F_94 ( V_246 , V_257 , V_247 ) ;
F_6 ( V_265 , V_2 -> V_5 + V_141 ) ;
F_93 ( V_246 , V_257 , & V_247 ) ;
V_247 &= ~ V_266 ;
if ( ! V_2 -> V_187 ) {
V_247 &= ~ V_267 ;
V_247 |= V_268 ;
}
V_247 &= ~ ( V_269 | V_270 ) ;
F_94 ( V_246 , V_257 , V_247 ) ;
if ( V_2 -> V_187 ) {
F_93 ( V_246 , V_271 , & V_247 ) ;
V_247 |= V_272 ;
F_94 ( V_246 , V_271 , V_247 ) ;
}
V_249 = F_8 ( V_2 -> V_5 + V_273 ) ;
V_249 &= ~ ( V_274 | V_275 ) ;
V_249 |= V_275 ;
V_249 |= V_276 ;
F_6 ( V_249 , V_2 -> V_5 + V_273 ) ;
F_84 ( V_2 ) ;
F_6 ( V_277 , V_2 -> V_5 + V_141 ) ;
F_6 ( 0x00 , V_174 + V_278 ) ;
F_6 ( 0x88 , V_174 + V_117 ) ;
F_6 ( 0x88 , V_174 + V_118 ) ;
F_6 ( 0x88 , V_174 + V_119 ) ;
F_6 ( 0x88 , V_174 + V_120 ) ;
return 0 ;
}
static void
F_95 ( struct V_1 * V_2 )
{
unsigned long V_174 = V_2 -> V_5 ;
unsigned short V_19 ;
V_19 = V_279 ;
if ( V_2 -> V_261 & V_258 )
V_19 |= V_280 ;
F_6 ( V_19 , V_2 -> V_5 + V_136 ) ;
F_2 ( V_19 , V_174 + V_27 ) ;
F_6 ( F_8 ( V_174 + V_281 ) | V_282 ,
V_174 + V_281 ) ;
}
static int F_96 ( struct V_1 * V_2 )
{
struct V_29 * V_30 ;
int V_91 ;
F_97 ( & V_2 -> V_116 ) ;
#ifdef F_50
if ( V_2 -> V_129 )
F_98 ( V_2 -> V_129 ) ;
#endif
if ( V_2 -> V_146 ) {
F_41 ( & V_2 -> V_47 ) ;
for ( V_91 = 0 ; V_91 < V_2 -> V_145 ; V_91 ++ ) {
V_30 = & V_2 -> V_146 [ V_91 ] ;
if ( V_30 -> V_102 && V_30 -> V_50 )
F_19 ( V_2 , V_30 , V_30 -> V_102 ) ;
}
F_42 ( & V_2 -> V_47 ) ;
F_99 ( V_2 -> V_146 ) ;
}
if ( V_2 -> V_5 ) {
F_2 ( 0 , V_2 -> V_5 + V_27 ) ;
}
#ifdef F_100
F_101 ( V_2 -> V_283 ) ;
#endif
if ( V_2 -> V_133 >= 0 )
F_102 ( V_2 -> V_133 , V_2 ) ;
if ( V_2 -> V_5 )
F_103 ( V_2 -> V_169 ) ;
F_104 ( V_2 -> V_214 ) ;
F_104 ( V_2 -> V_218 ) ;
F_105 ( V_2 -> V_169 ) ;
F_99 ( V_2 ) ;
return 0 ;
}
static int F_106 ( struct V_158 * V_284 )
{
struct V_245 * V_169 = F_107 ( V_284 ) ;
struct V_285 * V_126 = F_108 ( V_284 ) ;
struct V_1 * V_2 = V_126 -> V_44 ;
int V_91 , V_286 ;
if ( V_2 -> V_283 == NULL )
return 0 ;
V_2 -> V_121 = 1 ;
F_97 ( & V_2 -> V_116 ) ;
F_109 ( V_126 , V_287 ) ;
F_110 ( V_2 -> V_160 ) ;
F_111 ( V_2 -> V_124 ) ;
F_12 ( 10 ) ;
F_11 ( V_2 ) ;
V_286 = 0 ;
for ( V_91 = V_217 ; V_91 <= V_288 ; V_91 ++ )
V_2 -> V_283 [ V_286 ++ ] =
F_9 ( V_2 , V_216 , V_91 ) ;
for ( V_91 = V_289 ; V_91 <= V_290 ; V_91 ++ )
V_2 -> V_283 [ V_286 ++ ] =
F_9 ( V_2 , V_20 , V_91 ) ;
F_105 ( V_169 ) ;
F_112 ( V_169 ) ;
F_113 ( V_169 , V_291 ) ;
return 0 ;
}
static int F_114 ( struct V_158 * V_284 )
{
struct V_245 * V_169 = F_107 ( V_284 ) ;
struct V_285 * V_126 = F_108 ( V_284 ) ;
struct V_1 * V_2 = V_126 -> V_44 ;
int V_91 , V_286 ;
if ( V_2 -> V_283 == NULL )
return 0 ;
F_113 ( V_169 , V_292 ) ;
F_115 ( V_169 ) ;
if ( F_116 ( V_169 ) < 0 ) {
F_117 ( V_106 L_7
L_8 ) ;
F_118 ( V_126 ) ;
return - V_293 ;
}
F_119 ( V_169 ) ;
F_1 ( V_2 , 0 , 0x54 ) ;
F_1 ( V_2 , 0 , 0x56 ) ;
F_90 ( V_2 ) ;
F_11 ( V_2 ) ;
F_75 ( V_2 ) ;
V_286 = 0 ;
for ( V_91 = V_217 ; V_91 <= V_288 ; V_91 ++ )
F_10 ( V_2 , V_216 , V_91 ,
V_2 -> V_283 [ V_286 ++ ] ) ;
for ( V_91 = V_289 ; V_91 <= V_290 ; V_91 ++ )
F_10 ( V_2 , V_20 , V_91 ,
V_2 -> V_283 [ V_286 ++ ] ) ;
F_10 ( V_2 , V_20 ,
V_294 , 0 ) ;
F_120 ( V_2 -> V_124 ) ;
F_13 ( V_2 ) ;
F_95 ( V_2 ) ;
F_88 ( V_2 , 1 ) ;
F_89 ( V_2 ) ;
F_109 ( V_126 , V_295 ) ;
V_2 -> V_121 = 0 ;
return 0 ;
}
static int F_121 ( struct V_1 * V_2 )
{
struct V_129 * V_129 ;
int V_45 ;
V_129 = F_122 () ;
if ( ! V_129 )
return - V_150 ;
snprintf ( V_2 -> V_296 , sizeof( V_2 -> V_296 ) , L_9 ,
F_123 ( V_2 -> V_169 ) ) ;
V_129 -> V_167 = V_2 -> V_126 -> V_161 ;
V_129 -> V_296 = V_2 -> V_296 ;
V_129 -> V_128 . V_297 = V_298 ;
V_129 -> V_128 . V_299 = V_2 -> V_169 -> V_299 ;
V_129 -> V_128 . V_300 = V_2 -> V_169 -> V_158 ;
V_129 -> V_284 . V_301 = & V_2 -> V_169 -> V_284 ;
F_124 ( V_302 , V_129 -> V_303 ) ;
F_124 ( V_130 , V_129 -> V_304 ) ;
F_124 ( V_132 , V_129 -> V_304 ) ;
F_124 ( V_131 , V_129 -> V_304 ) ;
V_45 = F_125 ( V_129 ) ;
if ( V_45 ) {
F_126 ( V_129 ) ;
return V_45 ;
}
V_2 -> V_129 = V_129 ;
return 0 ;
}
static int F_127 ( struct V_305 * V_158 )
{
struct V_1 * V_2 = V_158 -> V_306 ;
return F_96 ( V_2 ) ;
}
static int
F_128 ( struct V_285 * V_126 , struct V_245 * V_169 ,
int V_307 ,
int V_240 ,
struct V_1 * * V_308 )
{
struct V_1 * V_2 ;
int V_91 , V_45 ;
const struct V_309 * V_310 ;
static struct V_311 V_202 = {
. V_312 = F_127 ,
} ;
* V_308 = NULL ;
if ( F_116 ( V_169 ) )
return - V_293 ;
if ( F_129 ( V_169 , F_130 ( 28 ) ) < 0 ||
F_131 ( V_169 , F_130 ( 28 ) ) < 0 ) {
F_37 ( V_106 L_10 ) ;
F_105 ( V_169 ) ;
return - V_46 ;
}
V_2 = F_132 ( sizeof( * V_2 ) , V_313 ) ;
if ( V_2 == NULL ) {
F_105 ( V_169 ) ;
return - V_150 ;
}
F_133 ( & V_2 -> V_47 ) ;
switch ( V_169 -> V_158 ) {
case V_314 :
case V_315 :
case V_316 :
case V_317 :
V_2 -> V_187 = 1 ;
break;
}
V_2 -> V_126 = V_126 ;
V_2 -> V_169 = V_169 ;
V_2 -> V_133 = - 1 ;
F_134 ( & V_2 -> V_116 , F_48 ) ;
V_2 -> V_239 = V_307 ;
if ( V_240 >= 0 && V_240 <= 0x0f )
V_2 -> V_240 = V_240 ;
else {
V_310 = F_135 ( V_169 , V_318 ) ;
if ( V_310 ) {
F_136 ( V_319
L_11 ,
F_137 ( V_310 ) ) ;
V_2 -> V_240 = V_310 -> V_3 ;
} else if ( V_2 -> V_187 )
V_2 -> V_240 = V_320 ;
else
V_2 -> V_240 = V_321 ;
}
V_310 = F_135 ( V_169 , V_322 ) ;
if ( V_310 ) {
F_136 ( V_319
L_12 ,
F_137 ( V_310 ) ) ;
V_2 -> V_189 = 1 ;
}
V_310 = F_135 ( V_169 , V_323 ) ;
if ( V_310 )
V_2 -> V_261 = V_310 -> V_3 ;
if ( F_135 ( V_169 , V_324 ) )
V_2 -> V_244 = 1 ;
V_2 -> V_145 = V_325 ;
V_2 -> V_146 = F_138 ( V_2 -> V_145 , sizeof( struct V_29 ) ,
V_313 ) ;
if ( V_2 -> V_146 == NULL ) {
F_99 ( V_2 ) ;
F_105 ( V_169 ) ;
return - V_150 ;
}
V_45 = F_139 ( & V_2 -> V_214 ,
L_13 , & V_169 -> V_284 ) ;
if ( V_45 < 0 ) {
F_96 ( V_2 ) ;
return V_45 ;
}
V_45 = F_139 ( & V_2 -> V_218 ,
L_14 , & V_169 -> V_284 ) ;
if ( V_45 < 0 ) {
F_96 ( V_2 ) ;
return V_45 ;
}
if ( ( V_45 = F_140 ( V_169 , V_126 -> V_161 ) ) < 0 ) {
F_96 ( V_2 ) ;
return V_45 ;
}
V_2 -> V_5 = F_141 ( V_169 , 0 ) ;
F_119 ( V_169 ) ;
F_90 ( V_2 ) ;
F_11 ( V_2 ) ;
F_75 ( V_2 ) ;
F_88 ( V_2 , 1 ) ;
F_89 ( V_2 ) ;
if ( F_142 ( V_169 -> V_133 , F_56 , V_326 ,
V_327 , V_2 ) ) {
F_37 ( V_106 L_15 , V_169 -> V_133 ) ;
F_96 ( V_2 ) ;
return - V_150 ;
}
V_2 -> V_133 = V_169 -> V_133 ;
#ifdef F_100
V_2 -> V_283 = F_143 ( sizeof( T_1 ) * ( V_328 + V_329 ) ) ;
if ( V_2 -> V_283 == NULL )
F_37 ( V_330 L_16 ) ;
#endif
if ( ( V_45 = F_144 ( V_126 , V_331 , V_2 , & V_202 ) ) < 0 ) {
F_96 ( V_2 ) ;
return V_45 ;
}
if ( ( V_45 = F_80 ( V_2 ) ) < 0 )
return V_45 ;
for ( V_91 = 0 ; V_91 < V_2 -> V_145 ; V_91 ++ ) {
struct V_29 * V_30 = & V_2 -> V_146 [ V_91 ] ;
if ( ( V_45 = F_86 ( V_2 , V_30 , V_91 ) ) < 0 )
return V_45 ;
}
if ( ( V_45 = F_64 ( V_2 , 0 ) ) < 0 )
return V_45 ;
#ifdef F_50
if ( V_2 -> V_261 & V_258 ) {
V_45 = F_121 ( V_2 ) ;
if ( V_45 )
F_37 ( V_330 L_17
L_18 , V_45 ) ;
}
#endif
F_95 ( V_2 ) ;
F_13 ( V_2 ) ;
F_145 ( V_126 , & V_169 -> V_284 ) ;
* V_308 = V_2 ;
return 0 ;
}
static int
F_146 ( struct V_245 * V_169 , const struct V_332 * V_333 )
{
static int V_284 ;
struct V_285 * V_126 ;
struct V_1 * V_2 ;
int V_45 ;
if ( ( ( V_169 -> V_334 >> 8 ) & 0xffff ) != V_335 )
return - V_336 ;
if ( V_284 >= V_337 )
return - V_336 ;
if ( ! V_236 [ V_284 ] ) {
V_284 ++ ;
return - V_338 ;
}
V_45 = F_147 ( V_7 [ V_284 ] , V_128 [ V_284 ] , V_339 , 0 , & V_126 ) ;
if ( V_45 < 0 )
return V_45 ;
switch ( V_169 -> V_158 ) {
case V_314 :
case V_315 :
strcpy ( V_126 -> V_161 , L_19 ) ;
break;
case V_316 :
case V_317 :
strcpy ( V_126 -> V_161 , L_20 ) ;
break;
default:
strcpy ( V_126 -> V_161 , L_21 ) ;
break;
}
if ( ( V_45 = F_128 ( V_126 , V_169 ,
V_239 [ V_284 ] ,
V_240 [ V_284 ] ,
& V_2 ) ) < 0 ) {
F_148 ( V_126 ) ;
return V_45 ;
}
V_126 -> V_44 = V_2 ;
sprintf ( V_126 -> V_340 , L_22 , V_126 -> V_161 ) ;
sprintf ( V_126 -> V_341 , L_23 ,
V_126 -> V_340 , V_2 -> V_5 , V_2 -> V_133 ) ;
if ( ( V_45 = F_149 ( V_126 ) ) < 0 ) {
F_148 ( V_126 ) ;
return V_45 ;
}
#if 0
err = snd_mpu401_uart_new(chip->card, 0, MPU401_HW_MPU401,
chip->iobase + MPU401_DATA_PORT,
MPU401_INFO_INTEGRATED | MPU401_INFO_IRQ_HOOK,
-1, &chip->rmidi);
if (err < 0)
printk(KERN_WARNING "maestro3: no MIDI support.\n");
#endif
F_150 ( V_169 , V_126 ) ;
V_284 ++ ;
return 0 ;
}
static void F_151 ( struct V_245 * V_169 )
{
F_148 ( F_152 ( V_169 ) ) ;
F_150 ( V_169 , NULL ) ;
}

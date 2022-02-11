int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 , int V_5 , int time )
{
unsigned long V_6 = V_7 + ( time * V_8 + 999 ) / 1000 ;
#ifdef F_2
static char * V_9 [ V_10 ] = {
L_1 , L_2 , L_3 , L_4 , L_5 , L_6 , L_7 ,
L_8 , L_9 , L_10 , L_11 , L_12 , L_13 ,
L_14 , L_15 , L_16 , L_17 , L_18 , L_19 ,
L_20 , L_21 , L_22 , L_23 ,
L_24 , L_25 , L_26 , L_27
} ;
#endif
do {
if ( ( F_3 ( V_2 , V_3 ) & V_4 ) == V_5 )
return 0 ;
} while ( F_4 ( V_6 , V_7 ) );
F_5 ( V_11 L_28 , V_9 [ V_3 ] , V_4 , F_3 ( V_2 , V_3 ) ) ;
return - V_12 ;
}
static int F_6 ( struct V_1 * V_2 , int V_13 )
{
int V_14 ;
if ( F_1 ( V_2 , V_15 , V_16 , 0 , 200 ) < 0 )
return - V_12 ;
V_14 = V_13 ;
if ( F_7 ( V_2 ) )
V_14 += V_17 ;
F_8 ( V_2 , V_18 , ( V_14 >> 1 ) | V_16 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
if ( F_6 ( V_2 , V_19 ) < 0 )
return - V_12 ;
if ( F_10 ( V_2 , V_20 , 0 , 200 ) < 0 )
return - V_12 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , int V_21 )
{
int V_22 ;
if ( ( V_22 = F_9 ( V_2 ) ) < 0 )
return V_22 ;
if ( ( V_22 = F_6 ( V_2 , V_21 ) ) < 0 )
return V_22 ;
if ( ( V_22 = F_12 ( V_2 , V_20 ) ) < 0 )
return V_22 ;
if ( ( V_22 = F_13 ( V_2 , V_23 ) ) & V_24 ) {
if ( ( V_22 = F_14 ( V_2 ) ) < 0 ) {
F_5 ( V_11 L_29 ) ;
return V_22 ;
}
V_22 = F_13 ( V_2 , V_25 ) << 16 ;
V_22 |= F_13 ( V_2 , V_26 ) << 8 ;
V_22 |= F_13 ( V_2 , V_27 ) ;
F_5 ( V_11 L_30 , V_22 ) ;
return - ( V_28 | V_22 ) ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
int V_31 , V_22 , V_32 , V_33 ;
if ( V_30 -> V_34 == V_35 && V_30 -> V_36 == 0 )
return 0 ;
V_22 = F_14 ( V_2 ) ;
if ( V_22 < 0 )
return V_22 ;
V_32 = F_13 ( V_2 , V_25 ) << 16 ;
V_32 |= F_13 ( V_2 , V_26 ) << 8 ;
V_32 |= F_13 ( V_2 , V_27 ) ;
switch ( V_30 -> V_34 ) {
case V_37 :
V_33 = V_32 & 0xff ;
V_30 -> V_38 [ 0 ] = V_32 & 0xffff00 ;
V_30 -> V_36 = V_33 + 1 ;
break;
case V_39 :
V_30 -> V_38 [ 0 ] = V_32 ;
V_33 = 0 ;
while ( V_32 ) {
if ( V_32 & 0x01 )
V_33 ++ ;
V_32 >>= 1 ;
}
V_30 -> V_36 = V_33 + 1 ;
break;
default:
V_33 = V_30 -> V_36 ;
V_30 -> V_38 [ 0 ] = V_32 ;
V_33 -- ;
break;
}
if ( V_33 < 1 )
return 0 ;
if ( F_16 ( V_33 > V_40 ) )
return - V_41 ;
for ( V_31 = 1 ; V_31 <= V_33 ; V_31 ++ ) {
V_22 = F_6 ( V_2 , V_42 ) ;
if ( V_22 < 0 )
return V_22 ;
V_22 = F_14 ( V_2 ) ;
if ( V_22 < 0 )
return V_22 ;
V_30 -> V_38 [ V_31 ] = F_13 ( V_2 , V_25 ) << 16 ;
V_30 -> V_38 [ V_31 ] |= F_13 ( V_2 , V_26 ) << 8 ;
V_30 -> V_38 [ V_31 ] |= F_13 ( V_2 , V_27 ) ;
}
return F_11 ( V_2 , V_43 ) ;
}
int F_17 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
int V_31 , V_22 ;
if ( V_2 -> V_44 & V_45 )
return - V_46 ;
if ( ( V_22 = F_9 ( V_2 ) ) < 0 ) {
F_5 ( V_11 L_31 ) ;
return V_22 ;
}
#if 0
printk(KERN_DEBUG "rmh: cmd = 0x%06x, length = %d, stype = %d\n",
rmh->Cmd[0], rmh->LgCmd, rmh->DspStat);
if (rmh->LgCmd > 1) {
printk(KERN_DEBUG " ");
for (i = 1; i < rmh->LgCmd; i++)
printk("0x%06x ", rmh->Cmd[i]);
printk("\n");
}
#endif
if ( V_30 -> V_47 > 1 )
V_30 -> V_48 [ 0 ] |= V_49 ;
else
V_30 -> V_48 [ 0 ] &= V_50 ;
if ( ( V_22 = F_12 ( V_2 , V_51 ) ) < 0 ) {
F_5 ( V_11 L_32 ) ;
return V_22 ;
}
F_8 ( V_2 , V_52 , ( V_30 -> V_48 [ 0 ] >> 16 ) & 0xff ) ;
F_8 ( V_2 , V_53 , ( V_30 -> V_48 [ 0 ] >> 8 ) & 0xff ) ;
F_8 ( V_2 , V_54 , V_30 -> V_48 [ 0 ] & 0xff ) ;
if ( ( V_22 = F_6 ( V_2 , V_55 ) ) < 0 ) {
F_5 ( V_11 L_33 ) ;
return V_22 ;
}
if ( ( V_22 = F_12 ( V_2 , V_20 ) ) < 0 )
return V_22 ;
if ( F_13 ( V_2 , V_23 ) & V_24 ) {
if ( ( V_22 = F_14 ( V_2 ) ) < 0 ) {
F_5 ( V_11 L_34 ) ;
return V_22 ;
}
V_22 = F_13 ( V_2 , V_25 ) << 16 ;
V_22 |= F_13 ( V_2 , V_26 ) << 8 ;
V_22 |= F_13 ( V_2 , V_27 ) ;
F_5 ( V_11 L_35 , V_22 ) ;
V_22 = - ( V_28 | V_22 ) ;
return V_22 ;
}
if ( V_30 -> V_47 > 1 ) {
for ( V_31 = 1 ; V_31 < V_30 -> V_47 ; V_31 ++ ) {
if ( ( V_22 = F_12 ( V_2 , V_56 ) ) < 0 ) {
F_5 ( V_11 L_36 ) ;
return V_22 ;
}
F_8 ( V_2 , V_52 , ( V_30 -> V_48 [ V_31 ] >> 16 ) & 0xff ) ;
F_8 ( V_2 , V_53 , ( V_30 -> V_48 [ V_31 ] >> 8 ) & 0xff ) ;
F_8 ( V_2 , V_54 , V_30 -> V_48 [ V_31 ] & 0xff ) ;
if ( ( V_22 = F_6 ( V_2 , V_57 ) ) < 0 ) {
F_5 ( V_11 L_37 ) ;
return V_22 ;
}
}
if ( ( V_22 = F_12 ( V_2 , V_56 ) ) < 0 ) {
F_5 ( V_11 L_38 ) ;
return V_22 ;
}
V_22 = F_11 ( V_2 , V_58 ) ;
if ( V_22 < 0 )
return V_22 ;
}
return F_15 ( V_2 , V_30 ) ;
}
int F_18 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
unsigned long V_59 ;
int V_22 ;
F_19 ( & V_2 -> V_60 , V_59 ) ;
V_22 = F_17 ( V_2 , V_30 ) ;
F_20 ( & V_2 -> V_60 , V_59 ) ;
return V_22 ;
}
int F_21 ( struct V_1 * V_2 , int V_21 )
{
int V_22 ;
if ( V_2 -> V_44 & V_45 )
return - V_46 ;
#if 0
printk(KERN_DEBUG "send_rih: cmd = 0x%x\n", cmd);
#endif
if ( ( V_22 = F_9 ( V_2 ) ) < 0 )
return V_22 ;
if ( ( V_22 = F_6 ( V_2 , V_21 ) ) < 0 )
return V_22 ;
if ( ( V_22 = F_12 ( V_2 , V_20 ) ) < 0 )
return V_22 ;
if ( F_13 ( V_2 , V_23 ) & V_24 ) {
if ( ( V_22 = F_14 ( V_2 ) ) < 0 )
return V_22 ;
V_22 = F_13 ( V_2 , V_25 ) << 16 ;
V_22 |= F_13 ( V_2 , V_26 ) << 8 ;
V_22 |= F_13 ( V_2 , V_27 ) ;
return - ( V_28 | V_22 ) ;
}
return 0 ;
}
int F_22 ( struct V_1 * V_2 , int V_21 )
{
unsigned long V_59 ;
int V_22 ;
F_19 ( & V_2 -> V_60 , V_59 ) ;
V_22 = F_21 ( V_2 , V_21 ) ;
F_20 ( & V_2 -> V_60 , V_59 ) ;
return V_22 ;
}
int F_23 ( struct V_1 * V_2 , const struct V_61 * V_62 )
{
unsigned int V_31 ;
int V_63 = F_7 ( V_2 ) ;
if ( V_62 -> V_33 <= 0 )
return - V_41 ;
if ( V_62 -> V_33 % 3 )
return - V_41 ;
#if 0
{
unsigned int c = ((u32)boot->data[0] << 16) | ((u32)boot->data[1] << 8) | boot->data[2];
if (boot->size != (c + 2) * 3)
return -EINVAL;
}
#endif
F_24 ( V_2 ) ;
F_25 ( V_64 ) ;
for ( V_31 = 0 ; V_31 < 0x600 ; V_31 += 3 ) {
if ( V_31 >= V_62 -> V_33 ) {
if ( V_63 )
break;
if ( F_12 ( V_2 , V_51 ) < 0 ) {
F_26 ( V_65 L_39 , V_31 ) ;
return - V_12 ;
}
F_8 ( V_2 , V_52 , 0 ) ;
F_8 ( V_2 , V_53 , 0 ) ;
F_8 ( V_2 , V_54 , 0 ) ;
} else {
const unsigned char * V_66 = V_62 -> V_67 + V_31 ;
if ( F_12 ( V_2 , V_51 ) < 0 ) {
F_26 ( V_65 L_39 , V_31 ) ;
return - V_12 ;
}
F_8 ( V_2 , V_52 , V_66 [ 0 ] ) ;
F_8 ( V_2 , V_53 , V_66 [ 1 ] ) ;
F_8 ( V_2 , V_54 , V_66 [ 2 ] ) ;
}
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , unsigned int * V_68 )
{
int V_22 ;
F_28 ( & V_2 -> V_69 , V_70 ) ;
F_29 ( & V_2 -> V_60 ) ;
V_22 = F_17 ( V_2 , & V_2 -> V_69 ) ;
if ( V_22 < 0 )
* V_68 = 0 ;
else
* V_68 = V_2 -> V_69 . V_38 [ 0 ] ;
F_30 ( & V_2 -> V_60 ) ;
return V_22 ;
}
static void F_31 ( unsigned long V_71 )
{
struct V_1 * V_2 = (struct V_1 * ) V_71 ;
unsigned int V_72 ;
if ( V_2 -> V_44 & V_45 )
return;
if ( F_27 ( V_2 , & V_72 ) < 0 )
return;
#if 0
if (events & 0x000800)
printk(KERN_ERR "DSP Stream underrun ! IRQ events = 0x%x\n", events);
#endif
if ( V_72 & V_73 ) {
F_26 ( V_65 L_40 ) ;
return;
}
if ( V_72 & V_74 )
;
if ( V_72 & V_75 )
F_32 ( V_2 ) ;
F_33 ( V_2 , V_72 ) ;
}
T_1 F_34 ( int V_76 , void * V_77 )
{
struct V_1 * V_2 = V_77 ;
if ( ! ( V_2 -> V_44 & V_78 ) ||
( V_2 -> V_44 & V_45 ) )
return V_79 ;
if ( ! F_35 ( V_2 ) )
F_36 ( & V_2 -> V_80 ) ;
return V_81 ;
}
static void F_37 ( struct V_1 * V_2 , int V_82 )
{
if ( F_16 ( ! V_2 -> V_83 -> V_84 ) )
return;
V_2 -> V_85 = V_86 ;
if ( V_82 ) {
V_2 -> V_87 = V_2 -> V_85 ;
V_2 -> V_88 = V_89 ;
V_2 -> V_90 = V_91 ;
V_2 -> V_92 = 48000 ;
V_2 -> V_93 = V_94 ;
V_2 -> V_95 = V_96 ;
}
V_2 -> V_83 -> V_84 ( V_2 , V_82 ) ;
F_38 ( V_2 , V_82 ) ;
F_39 ( V_2 , V_2 -> V_92 ) ;
F_24 ( V_2 ) ;
if ( F_40 ( V_2 ) ) {
F_35 ( V_2 ) ;
F_41 ( V_2 , 1 ) ;
}
F_42 ( V_2 , V_2 -> V_95 ) ;
}
static void F_43 ( struct V_97 * V_98 , struct V_99 * V_100 )
{
struct V_1 * V_2 = V_98 -> V_71 ;
static char * V_101 [] = { L_41 , L_42 , L_43 } ;
static char * V_102 [] = { L_44 , L_44 , L_43 } ;
static char * V_90 [] = { L_45 , L_46 , L_47 } ;
static char * V_103 [] = { L_46 , L_47 } ;
static char * V_104 [] = { L_48 , L_49 , L_50 } ;
F_44 ( V_100 , L_51 , V_2 -> V_105 -> V_106 ) ;
F_44 ( V_100 , L_52 ,
V_2 -> V_44 & V_107 ? L_53 : L_54 ) ;
F_44 ( V_100 , L_55 ,
V_2 -> V_44 & V_108 ? L_56 : L_54 ) ;
F_44 ( V_100 , L_57 ) ;
if ( V_2 -> V_109 & V_110 )
F_44 ( V_100 , L_58 ) ;
if ( V_2 -> V_109 & V_111 )
F_44 ( V_100 , L_59 ) ;
if ( V_2 -> V_109 & V_112 )
F_44 ( V_100 , L_60 ) ;
if ( V_2 -> V_109 & V_113 )
F_44 ( V_100 , L_61 ) ;
if ( V_2 -> V_109 & V_114 )
F_44 ( V_100 , L_62 ) ;
if ( V_2 -> V_109 & V_115 )
F_44 ( V_100 , L_63 ) ;
if ( V_2 -> V_109 & V_116 )
F_44 ( V_100 , L_64 ) ;
F_44 ( V_100 , L_65 ) ;
F_44 ( V_100 , L_66 , F_40 ( V_2 ) ?
V_101 [ V_2 -> V_85 ] :
V_102 [ V_2 -> V_85 ] ) ;
F_44 ( V_100 , L_67 , V_90 [ V_2 -> V_90 ] ) ;
F_44 ( V_100 , L_68 , V_103 [ V_2 -> V_88 ] ) ;
F_44 ( V_100 , L_69 , V_2 -> V_92 ) ;
F_44 ( V_100 , L_70 , V_2 -> V_117 ) ;
F_44 ( V_100 , L_71 , V_104 [ V_2 -> V_93 ] ) ;
F_44 ( V_100 , L_72 ,
V_2 -> V_118 . V_119 , V_2 -> V_118 . V_120 , V_2 -> V_118 . V_33 ,
V_2 -> V_118 . V_121 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_97 * V_98 ;
if ( ! F_46 ( V_2 -> V_105 , L_73 , & V_98 ) )
F_47 ( V_98 , V_2 , F_43 ) ;
}
int F_48 ( struct V_1 * V_2 , const struct V_61 * V_62 )
{
int V_22 ;
int V_82 = ! ( V_2 -> V_44 & V_108 ) ;
F_37 ( V_2 , V_82 ) ;
F_41 ( V_2 , 0 ) ;
if ( ( V_22 = F_23 ( V_2 , V_62 ) ) < 0 )
return V_22 ;
F_49 ( 10 ) ;
return 0 ;
}
int F_50 ( struct V_1 * V_2 , const struct V_61 * V_122 )
{
unsigned int V_31 ;
int V_22 ;
unsigned int V_123 = 0 ;
const unsigned char * V_66 , * V_124 ;
if ( V_122 -> V_33 % 3 )
return - V_41 ;
F_51 ( V_2 , 1 ) ;
for ( V_31 = 0 ; V_31 < V_122 -> V_33 ; V_31 += 3 ) {
V_66 = V_122 -> V_67 + V_31 ;
if ( ( V_22 = F_12 ( V_2 , V_51 ) ) < 0 ) {
F_52 ( V_65
L_74 , V_31 ) ;
return V_22 ;
}
V_124 = V_66 ;
V_123 ^= * V_124 ;
V_123 = ( V_123 >> 24 ) | ( V_123 << 8 ) ;
F_8 ( V_2 , V_52 , * V_124 ++ ) ;
V_123 ^= * V_124 ;
V_123 = ( V_123 >> 24 ) | ( V_123 << 8 ) ;
F_8 ( V_2 , V_53 , * V_124 ++ ) ;
V_123 ^= * V_124 ;
V_123 = ( V_123 >> 24 ) | ( V_123 << 8 ) ;
F_8 ( V_2 , V_54 , * V_124 ++ ) ;
}
F_53 ( V_11 L_75 , V_123 ) ;
F_49 ( 200 ) ;
if ( ( V_22 = F_12 ( V_2 , V_20 ) ) < 0 )
return V_22 ;
F_51 ( V_2 , 0 ) ;
F_35 ( V_2 ) ;
F_41 ( V_2 , 1 ) ;
return 0 ;
}
int F_54 ( struct V_1 * V_2 )
{
unsigned int V_31 ;
F_55 ( V_2 -> V_105 , V_125 ) ;
V_2 -> V_44 |= V_126 ;
for ( V_31 = 0 ; V_31 < V_2 -> V_127 -> V_128 ; V_31 ++ )
F_56 ( V_2 -> V_129 [ V_31 ] ) ;
return 0 ;
}
int F_57 ( struct V_1 * V_2 )
{
int V_31 , V_22 ;
V_2 -> V_44 &= ~ V_78 ;
for ( V_31 = 0 ; V_31 < 4 ; V_31 ++ ) {
if ( ! V_2 -> V_61 [ V_31 ] )
continue;
V_22 = V_2 -> V_83 -> V_130 ( V_2 , V_31 , V_2 -> V_61 [ V_31 ] ) ;
if ( V_22 < 0 ) {
F_26 ( V_65 L_76 , V_31 ) ;
return - V_12 ;
}
}
V_2 -> V_44 |= V_78 ;
V_2 -> V_44 &= ~ V_126 ;
F_55 ( V_2 -> V_105 , V_131 ) ;
return 0 ;
}
struct V_1 * F_58 ( struct V_132 * V_105 , struct V_133 * V_127 ,
struct V_134 * V_83 ,
int V_135 )
{
struct V_1 * V_2 ;
if ( F_16 ( ! V_105 || ! V_127 || ! V_83 ) )
return NULL ;
V_2 = F_59 ( sizeof( * V_2 ) + V_135 , V_136 ) ;
if ( ! V_2 ) {
F_26 ( V_65 L_77 ) ;
return NULL ;
}
F_60 ( & V_2 -> V_60 ) ;
F_60 ( & V_2 -> V_137 ) ;
V_2 -> V_76 = - 1 ;
V_2 -> V_127 = V_127 ;
V_2 -> type = V_127 -> type ;
V_2 -> V_83 = V_83 ;
F_61 ( & V_2 -> V_80 , F_31 , ( unsigned long ) V_2 ) ;
F_62 ( & V_2 -> V_138 ) ;
V_2 -> V_105 = V_105 ;
V_105 -> V_71 = V_2 ;
strcpy ( V_105 -> V_139 , V_127 -> V_140 ) ;
sprintf ( V_105 -> V_141 , L_78 , V_127 -> V_140 ) ;
F_45 ( V_2 ) ;
return V_2 ;
}
static int T_2 F_63 ( void )
{
return 0 ;
}
static void T_3 F_64 ( void )
{
}

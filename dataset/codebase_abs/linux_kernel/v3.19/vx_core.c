int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 , int V_5 , int time )
{
unsigned long V_6 = V_7 + ( time * V_8 + 999 ) / 1000 ;
static char * V_9 [ V_10 ] = {
L_1 , L_2 , L_3 , L_4 , L_5 , L_6 , L_7 ,
L_8 , L_9 , L_10 , L_11 , L_12 , L_13 ,
L_14 , L_15 , L_16 , L_17 , L_18 , L_19 ,
L_20 , L_21 , L_22 , L_23 ,
L_24 , L_25 , L_26 , L_27
} ;
do {
if ( ( F_2 ( V_2 , V_3 ) & V_4 ) == V_5 )
return 0 ;
} while ( F_3 ( V_6 , V_7 ) );
F_4 ( V_11 L_28 , V_9 [ V_3 ] , V_4 , F_2 ( V_2 , V_3 ) ) ;
return - V_12 ;
}
static int F_5 ( struct V_1 * V_2 , int V_13 )
{
int V_14 ;
if ( F_1 ( V_2 , V_15 , V_16 , 0 , 200 ) < 0 )
return - V_12 ;
V_14 = V_13 ;
if ( F_6 ( V_2 ) )
V_14 += V_17 ;
F_7 ( V_2 , V_18 , ( V_14 >> 1 ) | V_16 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
if ( F_5 ( V_2 , V_19 ) < 0 )
return - V_12 ;
if ( F_9 ( V_2 , V_20 , 0 , 200 ) < 0 )
return - V_12 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , int V_21 )
{
int V_22 ;
if ( ( V_22 = F_8 ( V_2 ) ) < 0 )
return V_22 ;
if ( ( V_22 = F_5 ( V_2 , V_21 ) ) < 0 )
return V_22 ;
if ( ( V_22 = F_11 ( V_2 , V_20 ) ) < 0 )
return V_22 ;
if ( ( V_22 = F_12 ( V_2 , V_23 ) ) & V_24 ) {
if ( ( V_22 = F_13 ( V_2 ) ) < 0 ) {
F_4 ( V_11 L_29 ) ;
return V_22 ;
}
V_22 = F_12 ( V_2 , V_25 ) << 16 ;
V_22 |= F_12 ( V_2 , V_26 ) << 8 ;
V_22 |= F_12 ( V_2 , V_27 ) ;
F_4 ( V_11 L_30 , V_22 ) ;
return - ( V_28 | V_22 ) ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
int V_31 , V_22 , V_32 , V_33 ;
if ( V_30 -> V_34 == V_35 && V_30 -> V_36 == 0 )
return 0 ;
V_22 = F_13 ( V_2 ) ;
if ( V_22 < 0 )
return V_22 ;
V_32 = F_12 ( V_2 , V_25 ) << 16 ;
V_32 |= F_12 ( V_2 , V_26 ) << 8 ;
V_32 |= F_12 ( V_2 , V_27 ) ;
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
if ( F_15 ( V_33 >= V_40 ) )
return - V_41 ;
for ( V_31 = 1 ; V_31 <= V_33 ; V_31 ++ ) {
V_22 = F_5 ( V_2 , V_42 ) ;
if ( V_22 < 0 )
return V_22 ;
V_22 = F_13 ( V_2 ) ;
if ( V_22 < 0 )
return V_22 ;
V_30 -> V_38 [ V_31 ] = F_12 ( V_2 , V_25 ) << 16 ;
V_30 -> V_38 [ V_31 ] |= F_12 ( V_2 , V_26 ) << 8 ;
V_30 -> V_38 [ V_31 ] |= F_12 ( V_2 , V_27 ) ;
}
return F_10 ( V_2 , V_43 ) ;
}
int F_16 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
int V_31 , V_22 ;
if ( V_2 -> V_44 & V_45 )
return - V_46 ;
if ( ( V_22 = F_8 ( V_2 ) ) < 0 ) {
F_4 ( V_11 L_31 ) ;
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
if ( ( V_22 = F_11 ( V_2 , V_51 ) ) < 0 ) {
F_4 ( V_11 L_32 ) ;
return V_22 ;
}
F_7 ( V_2 , V_52 , ( V_30 -> V_48 [ 0 ] >> 16 ) & 0xff ) ;
F_7 ( V_2 , V_53 , ( V_30 -> V_48 [ 0 ] >> 8 ) & 0xff ) ;
F_7 ( V_2 , V_54 , V_30 -> V_48 [ 0 ] & 0xff ) ;
if ( ( V_22 = F_5 ( V_2 , V_55 ) ) < 0 ) {
F_4 ( V_11 L_33 ) ;
return V_22 ;
}
if ( ( V_22 = F_11 ( V_2 , V_20 ) ) < 0 )
return V_22 ;
if ( F_12 ( V_2 , V_23 ) & V_24 ) {
if ( ( V_22 = F_13 ( V_2 ) ) < 0 ) {
F_4 ( V_11 L_34 ) ;
return V_22 ;
}
V_22 = F_12 ( V_2 , V_25 ) << 16 ;
V_22 |= F_12 ( V_2 , V_26 ) << 8 ;
V_22 |= F_12 ( V_2 , V_27 ) ;
F_4 ( V_11 L_35 , V_22 ) ;
V_22 = - ( V_28 | V_22 ) ;
return V_22 ;
}
if ( V_30 -> V_47 > 1 ) {
for ( V_31 = 1 ; V_31 < V_30 -> V_47 ; V_31 ++ ) {
if ( ( V_22 = F_11 ( V_2 , V_56 ) ) < 0 ) {
F_4 ( V_11 L_36 ) ;
return V_22 ;
}
F_7 ( V_2 , V_52 , ( V_30 -> V_48 [ V_31 ] >> 16 ) & 0xff ) ;
F_7 ( V_2 , V_53 , ( V_30 -> V_48 [ V_31 ] >> 8 ) & 0xff ) ;
F_7 ( V_2 , V_54 , V_30 -> V_48 [ V_31 ] & 0xff ) ;
if ( ( V_22 = F_5 ( V_2 , V_57 ) ) < 0 ) {
F_4 ( V_11 L_37 ) ;
return V_22 ;
}
}
if ( ( V_22 = F_11 ( V_2 , V_56 ) ) < 0 ) {
F_4 ( V_11 L_38 ) ;
return V_22 ;
}
V_22 = F_10 ( V_2 , V_58 ) ;
if ( V_22 < 0 )
return V_22 ;
}
return F_14 ( V_2 , V_30 ) ;
}
int F_17 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
int V_22 ;
F_18 ( & V_2 -> V_59 ) ;
V_22 = F_16 ( V_2 , V_30 ) ;
F_19 ( & V_2 -> V_59 ) ;
return V_22 ;
}
int F_20 ( struct V_1 * V_2 , int V_21 )
{
int V_22 ;
if ( V_2 -> V_44 & V_45 )
return - V_46 ;
#if 0
printk(KERN_DEBUG "send_rih: cmd = 0x%x\n", cmd);
#endif
if ( ( V_22 = F_8 ( V_2 ) ) < 0 )
return V_22 ;
if ( ( V_22 = F_5 ( V_2 , V_21 ) ) < 0 )
return V_22 ;
if ( ( V_22 = F_11 ( V_2 , V_20 ) ) < 0 )
return V_22 ;
if ( F_12 ( V_2 , V_23 ) & V_24 ) {
if ( ( V_22 = F_13 ( V_2 ) ) < 0 )
return V_22 ;
V_22 = F_12 ( V_2 , V_25 ) << 16 ;
V_22 |= F_12 ( V_2 , V_26 ) << 8 ;
V_22 |= F_12 ( V_2 , V_27 ) ;
return - ( V_28 | V_22 ) ;
}
return 0 ;
}
int F_21 ( struct V_1 * V_2 , int V_21 )
{
int V_22 ;
F_18 ( & V_2 -> V_59 ) ;
V_22 = F_20 ( V_2 , V_21 ) ;
F_19 ( & V_2 -> V_59 ) ;
return V_22 ;
}
int F_22 ( struct V_1 * V_2 , const struct V_60 * V_61 )
{
unsigned int V_31 ;
int V_62 = F_6 ( V_2 ) ;
if ( V_61 -> V_33 <= 0 )
return - V_41 ;
if ( V_61 -> V_33 % 3 )
return - V_41 ;
#if 0
{
unsigned int c = ((u32)boot->data[0] << 16) | ((u32)boot->data[1] << 8) | boot->data[2];
if (boot->size != (c + 2) * 3)
return -EINVAL;
}
#endif
F_23 ( V_2 ) ;
F_24 ( V_63 ) ;
for ( V_31 = 0 ; V_31 < 0x600 ; V_31 += 3 ) {
if ( V_31 >= V_61 -> V_33 ) {
if ( V_62 )
break;
if ( F_11 ( V_2 , V_51 ) < 0 ) {
F_25 ( V_64 L_39 , V_31 ) ;
return - V_12 ;
}
F_7 ( V_2 , V_52 , 0 ) ;
F_7 ( V_2 , V_53 , 0 ) ;
F_7 ( V_2 , V_54 , 0 ) ;
} else {
const unsigned char * V_65 = V_61 -> V_66 + V_31 ;
if ( F_11 ( V_2 , V_51 ) < 0 ) {
F_25 ( V_64 L_39 , V_31 ) ;
return - V_12 ;
}
F_7 ( V_2 , V_52 , V_65 [ 0 ] ) ;
F_7 ( V_2 , V_53 , V_65 [ 1 ] ) ;
F_7 ( V_2 , V_54 , V_65 [ 2 ] ) ;
}
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , unsigned int * V_67 )
{
int V_22 ;
F_27 ( & V_2 -> V_68 , V_69 ) ;
F_18 ( & V_2 -> V_59 ) ;
V_22 = F_16 ( V_2 , & V_2 -> V_68 ) ;
if ( V_22 < 0 )
* V_67 = 0 ;
else
* V_67 = V_2 -> V_68 . V_38 [ 0 ] ;
F_19 ( & V_2 -> V_59 ) ;
return V_22 ;
}
T_1 F_28 ( int V_70 , void * V_71 )
{
struct V_1 * V_2 = V_71 ;
unsigned int V_72 ;
if ( V_2 -> V_44 & V_45 )
return V_73 ;
if ( F_26 ( V_2 , & V_72 ) < 0 )
return V_73 ;
#if 0
if (events & 0x000800)
printk(KERN_ERR "DSP Stream underrun ! IRQ events = 0x%x\n", events);
#endif
if ( V_72 & V_74 ) {
F_25 ( V_64 L_40 ) ;
return V_73 ;
}
if ( V_72 & V_75 )
;
if ( V_72 & V_76 )
F_29 ( V_2 ) ;
F_30 ( V_2 , V_72 ) ;
return V_73 ;
}
T_1 F_31 ( int V_70 , void * V_71 )
{
struct V_1 * V_2 = V_71 ;
if ( ! ( V_2 -> V_44 & V_77 ) ||
( V_2 -> V_44 & V_45 ) )
return V_78 ;
if ( ! F_32 ( V_2 ) )
return V_79 ;
return V_78 ;
}
static void F_33 ( struct V_1 * V_2 , int V_80 )
{
if ( F_15 ( ! V_2 -> V_81 -> V_82 ) )
return;
V_2 -> V_83 = V_84 ;
if ( V_80 ) {
V_2 -> V_85 = V_2 -> V_83 ;
V_2 -> V_86 = V_87 ;
V_2 -> V_88 = V_89 ;
V_2 -> V_90 = 48000 ;
V_2 -> V_91 = V_92 ;
V_2 -> V_93 = V_94 ;
}
V_2 -> V_81 -> V_82 ( V_2 , V_80 ) ;
F_34 ( V_2 , V_80 ) ;
F_35 ( V_2 , V_2 -> V_90 ) ;
F_23 ( V_2 ) ;
if ( F_36 ( V_2 ) ) {
F_32 ( V_2 ) ;
F_37 ( V_2 , 1 ) ;
}
F_38 ( V_2 , V_2 -> V_93 ) ;
}
static void F_39 ( struct V_95 * V_96 , struct V_97 * V_98 )
{
struct V_1 * V_2 = V_96 -> V_99 ;
static char * V_100 [] = { L_41 , L_42 , L_43 } ;
static char * V_101 [] = { L_44 , L_44 , L_43 } ;
static char * V_88 [] = { L_45 , L_46 , L_47 } ;
static char * V_102 [] = { L_46 , L_47 } ;
static char * V_103 [] = { L_48 , L_49 , L_50 } ;
F_40 ( V_98 , L_51 , V_2 -> V_104 -> V_105 ) ;
F_40 ( V_98 , L_52 ,
V_2 -> V_44 & V_106 ? L_53 : L_54 ) ;
F_40 ( V_98 , L_55 ,
V_2 -> V_44 & V_107 ? L_56 : L_54 ) ;
F_40 ( V_98 , L_57 ) ;
if ( V_2 -> V_108 & V_109 )
F_40 ( V_98 , L_58 ) ;
if ( V_2 -> V_108 & V_110 )
F_40 ( V_98 , L_59 ) ;
if ( V_2 -> V_108 & V_111 )
F_40 ( V_98 , L_60 ) ;
if ( V_2 -> V_108 & V_112 )
F_40 ( V_98 , L_61 ) ;
if ( V_2 -> V_108 & V_113 )
F_40 ( V_98 , L_62 ) ;
if ( V_2 -> V_108 & V_114 )
F_40 ( V_98 , L_63 ) ;
if ( V_2 -> V_108 & V_115 )
F_40 ( V_98 , L_64 ) ;
F_40 ( V_98 , L_65 ) ;
F_40 ( V_98 , L_66 , F_36 ( V_2 ) ?
V_100 [ V_2 -> V_83 ] :
V_101 [ V_2 -> V_83 ] ) ;
F_40 ( V_98 , L_67 , V_88 [ V_2 -> V_88 ] ) ;
F_40 ( V_98 , L_68 , V_102 [ V_2 -> V_86 ] ) ;
F_40 ( V_98 , L_69 , V_2 -> V_90 ) ;
F_40 ( V_98 , L_70 , V_2 -> V_116 ) ;
F_40 ( V_98 , L_71 , V_103 [ V_2 -> V_91 ] ) ;
F_40 ( V_98 , L_72 ,
V_2 -> V_117 . V_118 , V_2 -> V_117 . V_119 , V_2 -> V_117 . V_33 ,
V_2 -> V_117 . V_120 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_95 * V_96 ;
if ( ! F_42 ( V_2 -> V_104 , L_73 , & V_96 ) )
F_43 ( V_96 , V_2 , F_39 ) ;
}
int F_44 ( struct V_1 * V_2 , const struct V_60 * V_61 )
{
int V_22 ;
int V_80 = ! ( V_2 -> V_44 & V_107 ) ;
F_33 ( V_2 , V_80 ) ;
F_37 ( V_2 , 0 ) ;
if ( ( V_22 = F_22 ( V_2 , V_61 ) ) < 0 )
return V_22 ;
F_45 ( 10 ) ;
return 0 ;
}
int F_46 ( struct V_1 * V_2 , const struct V_60 * V_121 )
{
unsigned int V_31 ;
int V_22 ;
unsigned int V_122 = 0 ;
const unsigned char * V_65 , * V_123 ;
if ( V_121 -> V_33 % 3 )
return - V_41 ;
F_47 ( V_2 , 1 ) ;
for ( V_31 = 0 ; V_31 < V_121 -> V_33 ; V_31 += 3 ) {
V_65 = V_121 -> V_66 + V_31 ;
if ( ( V_22 = F_11 ( V_2 , V_51 ) ) < 0 ) {
F_48 ( V_64
L_74 , V_31 ) ;
return V_22 ;
}
V_123 = V_65 ;
V_122 ^= * V_123 ;
V_122 = ( V_122 >> 24 ) | ( V_122 << 8 ) ;
F_7 ( V_2 , V_52 , * V_123 ++ ) ;
V_122 ^= * V_123 ;
V_122 = ( V_122 >> 24 ) | ( V_122 << 8 ) ;
F_7 ( V_2 , V_53 , * V_123 ++ ) ;
V_122 ^= * V_123 ;
V_122 = ( V_122 >> 24 ) | ( V_122 << 8 ) ;
F_7 ( V_2 , V_54 , * V_123 ++ ) ;
}
F_49 ( V_11 L_75 , V_122 ) ;
F_45 ( 200 ) ;
if ( ( V_22 = F_11 ( V_2 , V_20 ) ) < 0 )
return V_22 ;
F_47 ( V_2 , 0 ) ;
F_32 ( V_2 ) ;
F_37 ( V_2 , 1 ) ;
return 0 ;
}
int F_50 ( struct V_1 * V_2 )
{
unsigned int V_31 ;
F_51 ( V_2 -> V_104 , V_124 ) ;
V_2 -> V_44 |= V_125 ;
for ( V_31 = 0 ; V_31 < V_2 -> V_126 -> V_127 ; V_31 ++ )
F_52 ( V_2 -> V_128 [ V_31 ] ) ;
return 0 ;
}
int F_53 ( struct V_1 * V_2 )
{
int V_31 , V_22 ;
V_2 -> V_44 &= ~ V_77 ;
for ( V_31 = 0 ; V_31 < 4 ; V_31 ++ ) {
if ( ! V_2 -> V_60 [ V_31 ] )
continue;
V_22 = V_2 -> V_81 -> V_129 ( V_2 , V_31 , V_2 -> V_60 [ V_31 ] ) ;
if ( V_22 < 0 ) {
F_25 ( V_64 L_76 , V_31 ) ;
return - V_12 ;
}
}
V_2 -> V_44 |= V_77 ;
V_2 -> V_44 &= ~ V_125 ;
F_51 ( V_2 -> V_104 , V_130 ) ;
return 0 ;
}
struct V_1 * F_54 ( struct V_131 * V_104 , struct V_132 * V_126 ,
struct V_133 * V_81 ,
int V_134 )
{
struct V_1 * V_2 ;
if ( F_15 ( ! V_104 || ! V_126 || ! V_81 ) )
return NULL ;
V_2 = F_55 ( sizeof( * V_2 ) + V_134 , V_135 ) ;
if ( ! V_2 ) {
F_25 ( V_64 L_77 ) ;
return NULL ;
}
F_56 ( & V_2 -> V_59 ) ;
V_2 -> V_70 = - 1 ;
V_2 -> V_126 = V_126 ;
V_2 -> type = V_126 -> type ;
V_2 -> V_81 = V_81 ;
F_56 ( & V_2 -> V_136 ) ;
V_2 -> V_104 = V_104 ;
V_104 -> V_99 = V_2 ;
strcpy ( V_104 -> V_137 , V_126 -> V_138 ) ;
sprintf ( V_104 -> V_139 , L_78 , V_126 -> V_138 ) ;
F_41 ( V_2 ) ;
return V_2 ;
}
static int T_2 F_57 ( void )
{
return 0 ;
}
static void T_3 F_58 ( void )
{
}

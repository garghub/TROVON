static inline void F_1 ( int V_1 , int V_2 )
{
F_2 ( ( ( F_3 ( V_1 + V_3 ) & 0xf0 ) | ( V_2 & 0x07 ) ) ,
V_1 + V_3 ) ;
}
static int T_1 F_4 ( struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
unsigned int V_8 , V_9 ;
T_2 V_10 , V_11 ;
if ( ! ( F_5 ( V_5 , 0 ) && F_5 ( V_5 , 1 ) &&
F_6 ( V_5 , 0 ) && F_7 ( V_5 , 0 ) ) )
return - V_12 ;
V_9 = F_8 ( V_5 , 0 ) ;
V_8 = F_8 ( V_5 , 1 ) ;
V_10 = F_9 ( V_5 , 0 ) ;
V_11 = F_10 ( V_5 , 0 ) ;
if ( F_11 ( V_8 , V_9 , V_10 , V_11 ) )
return - V_13 ;
return 0 ;
}
static int T_3 F_12 ( void )
{
int V_14 = 0 ;
#ifdef F_13
if ( F_14 ( V_15 , V_16 , V_17 , V_18 , V_19 ) < 0 ) {
F_15 ( L_1 , V_20 ) ;
}
#endif
if ( V_16 > 0 && V_17 > 0 ) {
F_16 ( L_2 , V_16 ) ;
F_16 ( L_3 , V_17 ) ;
if ( F_11 ( V_16 , V_17 , V_18 , V_19 ) )
V_14 = - V_13 ;
} else {
V_14 = - V_13 ;
if ( V_15 > 0 ) {
F_16 ( L_4
L_5 , V_15 ) ;
if ( ! F_17 ( V_15 ) )
V_14 = 0 ;
if ( ! F_18 ( V_15 ) )
V_14 = 0 ;
}
if ( F_19 () > 0 )
V_14 = 0 ;
}
return V_14 ;
}
static int T_3 F_20 ( void )
{
int V_14 ;
F_21 ( 1 , L_6 , V_21 ) ;
V_14 = F_22 ( & V_22 ) ;
if ( V_14 ) {
F_15 ( L_7 , V_20 ) ;
return V_14 ;
}
V_23 = 0 ;
if ( V_24 || ! V_25 ||
V_15 || V_16 || V_17 ||
V_18 != V_26 || V_19 != V_27 ) {
V_14 = F_12 () ;
} else {
if ( F_23 ( & V_28 ) == 0 )
V_29 = 1 ;
}
if ( V_14 ) {
if ( V_29 )
F_24 ( & V_28 ) ;
F_25 ( & V_22 ) ;
}
return V_14 ;
}
static T_4 F_26 ( struct V_30 * V_31 ,
struct V_32 * V_5 )
{
struct V_33 * V_34 = F_27 ( V_5 ) ;
if ( V_34 -> V_35 . V_36 > 115200 )
return F_28 ( V_31 , V_5 ) ;
else
return F_29 ( V_31 , V_5 ) ;
}
static int T_1 F_11 ( unsigned int V_37 , unsigned int V_38 , T_2 V_10 , T_2 V_11 )
{
struct V_33 * V_34 ;
struct V_32 * V_5 ;
int V_39 ;
F_21 ( 1 , L_6 , V_21 ) ;
V_39 = F_30 ( V_37 , V_38 ) ;
if ( V_39 )
goto V_40;
V_39 = - V_41 ;
if ( V_23 >= F_31 ( V_42 ) ) {
F_32 ( L_8 , V_21 ) ;
goto V_43;
}
V_5 = F_33 ( sizeof( struct V_33 ) ) ;
if ( ! V_5 ) {
F_32 ( L_9 , V_21 ) ;
goto V_43;
}
#if V_44
V_5 -> V_45 = V_46 * 2 ;
#endif
V_5 -> V_47 = & V_48 ;
V_34 = F_27 ( V_5 ) ;
V_34 -> V_49 = V_5 ;
V_5 -> V_50 = V_34 -> V_35 . V_37 = V_37 ;
V_5 -> V_11 = V_34 -> V_35 . V_11 = V_11 ;
V_42 [ V_23 ] = V_34 ;
F_34 ( & V_34 -> V_51 ) ;
V_34 -> V_52 . V_53 = V_54 ;
V_34 -> V_55 . V_53 = V_56 ;
V_34 -> V_52 . V_57 =
F_35 ( NULL , V_34 -> V_52 . V_53 ,
& V_34 -> V_58 , V_59 ) ;
if ( V_34 -> V_52 . V_57 == NULL ) {
F_15 ( L_10 ,
V_20 ) ;
goto V_60;
}
V_34 -> V_55 . V_57 =
F_35 ( NULL , V_34 -> V_55 . V_53 ,
& V_34 -> V_61 , V_59 ) ;
if ( V_34 -> V_55 . V_57 == NULL ) {
F_15 ( L_11 ,
V_20 ) ;
goto V_62;
}
memset ( V_34 -> V_52 . V_57 , 0 , V_34 -> V_52 . V_53 ) ;
memset ( V_34 -> V_55 . V_57 , 0 , V_34 -> V_55 . V_53 ) ;
V_34 -> V_52 . V_63 = FALSE ;
V_34 -> V_52 . V_64 = V_65 ;
V_34 -> V_55 . V_66 = V_34 -> V_55 . V_57 ;
V_34 -> V_52 . V_66 = V_34 -> V_52 . V_57 ;
F_36 ( V_34 , V_37 , V_38 , V_10 , V_11 ) ;
F_37 ( V_34 ) ;
F_38 ( V_34 ) ;
if ( V_67 > 0 &&
V_67 < V_68 )
V_34 -> V_69 = V_67 ;
else
F_39 ( V_34 ) ;
V_39 = F_40 ( V_34 -> V_49 ) ;
if ( V_39 ) {
F_15 ( L_12 ,
V_20 ) ;
goto V_70;
}
V_34 -> V_71 = F_41 ( V_72 ,
V_23 , NULL , 0 ) ;
if ( F_42 ( V_34 -> V_71 ) ) {
V_39 = F_43 ( V_34 -> V_71 ) ;
goto V_73;
}
F_44 ( V_34 -> V_71 , V_34 ) ;
F_16 ( L_13 , V_5 -> V_74 ) ;
V_23 ++ ;
return 0 ;
V_73:
F_45 ( V_34 -> V_49 ) ;
V_70:
F_46 ( NULL , V_34 -> V_55 . V_53 ,
V_34 -> V_55 . V_57 , V_34 -> V_61 ) ;
V_62:
F_46 ( NULL , V_34 -> V_52 . V_53 ,
V_34 -> V_52 . V_57 , V_34 -> V_58 ) ;
V_60:
F_47 ( V_34 -> V_49 ) ;
V_42 [ V_23 ] = NULL ;
V_43:
F_48 ( V_37 , V_75 ) ;
F_48 ( V_38 , V_76 ) ;
V_40:
return V_39 ;
}
static int F_30 ( unsigned int V_37 , unsigned int V_38 )
{
unsigned char V_77 , V_78 , V_79 , V_80 , V_10 , V_11 , V_81 ;
if ( ! F_49 ( V_37 , V_75 ,
V_20 ) ) {
F_32 ( L_14 ,
V_21 , V_37 ) ;
goto V_82;
}
if ( ! F_49 ( V_38 , V_76 ,
V_20 ) ) {
F_32 ( L_15 ,
V_21 , V_38 ) ;
goto V_83;
}
F_1 ( V_37 , 3 ) ;
V_78 = F_3 ( V_37 + V_84 ) ;
V_77 = F_3 ( V_37 + V_85 ) ;
V_79 = F_3 ( V_37 + V_86 ) ;
V_81 = F_3 ( V_37 + V_87 ) ;
V_80 = F_3 ( V_37 + V_88 ) ;
V_10 = V_80 & V_89 ;
V_11 = ( V_80 & V_90 ) >> 4 ;
if ( V_78 != 0x10 || V_77 != 0xb8 || ( V_79 != 0xf1 && V_79 != 0xf2 ) ) {
F_32 ( L_16 ,
V_21 , V_37 ) ;
goto V_91;
}
F_16 ( L_17
L_18 ,
V_79 & 0x0f , V_81 , V_37 , V_38 , V_10 , V_11 ) ;
return 0 ;
V_91:
F_48 ( V_38 , V_76 ) ;
V_83:
F_48 ( V_37 , V_75 ) ;
V_82:
return - V_13 ;
}
static void F_36 ( struct V_33 * V_34 ,
unsigned int V_37 , unsigned int V_38 ,
T_2 V_10 , T_2 V_11 )
{
unsigned char V_80 , V_92 , V_93 ;
F_1 ( V_37 , 3 ) ;
V_80 = F_3 ( V_37 + V_88 ) ;
V_92 = V_80 & V_89 ;
V_93 = ( V_80 & V_90 ) >> 4 ;
V_34 -> V_35 . V_37 = V_37 ;
V_34 -> V_35 . V_38 = V_38 ;
V_34 -> V_35 . V_94 = V_75 ;
V_34 -> V_35 . V_95 = V_76 ;
V_34 -> V_35 . V_96 = V_97 ;
V_34 -> V_35 . V_36 = V_98 ;
if ( V_11 != V_27 ) {
if ( V_11 != V_93 )
F_16 ( L_19 ,
V_20 , V_93 , V_11 ) ;
V_34 -> V_35 . V_11 = V_11 ;
} else
V_34 -> V_35 . V_11 = V_93 ;
if ( V_10 != V_26 ) {
if ( V_10 != V_92 )
F_16 ( L_20 ,
V_20 , V_92 , V_10 ) ;
V_34 -> V_35 . V_10 = V_10 ;
} else
V_34 -> V_35 . V_10 = V_92 ;
}
static void F_37 ( struct V_33 * V_34 )
{
F_50 ( & V_34 -> V_99 ) ;
V_34 -> V_99 . V_100 . V_101 = V_102 | V_103 | V_104 | V_105 |
V_106 | V_107 | V_108 | ( V_109 << 8 ) ;
V_34 -> V_99 . V_110 . V_101 = V_111 ;
V_34 -> V_99 . V_112 . V_101 = V_113 ;
F_51 ( & V_34 -> V_99 ) ;
}
static void F_38 ( struct V_33 * V_34 )
{
int V_1 = V_34 -> V_35 . V_37 ;
F_1 ( V_1 , 0 ) ;
F_2 ( V_114 , V_1 + V_3 ) ;
F_2 ( 0x00 , V_1 + V_3 ) ;
F_1 ( V_1 , 1 ) ;
F_2 ( ( ( F_3 ( V_1 + V_115 ) & 0x87 ) | V_116 ) ,
V_1 + V_115 ) ;
#ifdef F_52
F_2 ( ( ( F_3 ( V_1 + V_117 ) & 0x3f ) | V_118 ) ,
V_1 + V_117 ) ;
#else
F_2 ( ( ( F_3 ( V_1 + V_117 ) & 0x3f ) | V_119 ) ,
V_1 + V_117 ) ;
#endif
( void ) F_3 ( V_1 + V_120 ) ;
F_2 ( V_121 , V_1 + V_120 ) ;
F_1 ( V_1 , 4 ) ;
F_2 ( ( F_3 ( V_1 + V_122 ) & 0x30 ) , V_1 + V_122 ) ;
F_1 ( V_1 , 0 ) ;
F_2 ( 0 , V_1 + V_123 ) ;
F_53 ( V_34 , V_98 ) ;
F_2 ( 0x00 , V_1 + V_3 ) ;
}
static int F_54 ( struct V_32 * V_5 , struct V_124 * V_125 , int V_126 )
{
struct V_127 * V_11 = (struct V_127 * ) V_125 ;
struct V_33 * V_34 ;
unsigned long V_128 ;
int V_14 = 0 ;
F_55 (dev != NULL, return -1;) ;
V_34 = F_27 ( V_5 ) ;
F_55 (self != NULL, return -1;) ;
F_21 ( 2 , L_21 , V_21 , V_5 -> V_74 , V_126 ) ;
switch ( V_126 ) {
case V_129 :
if ( ! F_56 ( V_130 ) )
V_14 = - V_131 ;
else {
F_57 ( & V_34 -> V_51 , V_128 ) ;
F_58 ( V_34 , V_11 -> V_132 ) ;
F_59 ( & V_34 -> V_51 , V_128 ) ;
}
break;
case V_133 :
if ( ! F_56 ( V_130 ) ) {
V_14 = - V_131 ;
break;
}
F_60 ( V_34 -> V_49 , TRUE ) ;
break;
case V_134 :
V_11 -> V_135 = F_61 ( V_34 ) ;
break;
#if 0
case SIOCSDTRRTS:
if (!capable(CAP_NET_ADMIN)) {
ret = -EPERM;
break;
}
smsc_ircc_sir_set_dtr_rts(dev, irq->ifr_dtr, irq->ifr_rts);
break;
#endif
default:
V_14 = - V_136 ;
}
return V_14 ;
}
static void F_62 ( struct V_32 * V_5 )
{
struct V_33 * V_34 = F_27 ( V_5 ) ;
unsigned long V_128 ;
F_32 ( L_22 ,
V_5 -> V_74 , V_34 -> V_35 . V_36 ) ;
F_57 ( & V_34 -> V_51 , V_128 ) ;
F_63 ( V_34 ) ;
F_58 ( V_34 , V_34 -> V_35 . V_36 ) ;
V_5 -> V_137 = V_138 ;
F_64 ( V_5 ) ;
F_59 ( & V_34 -> V_51 , V_128 ) ;
}
static T_4 F_29 ( struct V_30 * V_31 ,
struct V_32 * V_5 )
{
struct V_33 * V_34 ;
unsigned long V_128 ;
T_5 V_36 ;
F_21 ( 1 , L_6 , V_21 ) ;
F_55 (dev != NULL, return NETDEV_TX_OK;) ;
V_34 = F_27 ( V_5 ) ;
F_55 (self != NULL, return NETDEV_TX_OK;) ;
F_65 ( V_5 ) ;
F_57 ( & V_34 -> V_51 , V_128 ) ;
V_36 = F_66 ( V_31 ) ;
if ( V_36 != V_34 -> V_35 . V_36 && V_36 != - 1 ) {
if ( ! V_31 -> V_139 ) {
F_67 ( V_34 ) ;
F_58 ( V_34 , V_36 ) ;
F_59 ( & V_34 -> V_51 , V_128 ) ;
F_68 ( V_31 ) ;
return V_140 ;
}
V_34 -> V_141 = V_36 ;
}
V_34 -> V_55 . V_66 = V_34 -> V_55 . V_57 ;
V_34 -> V_55 . V_139 = F_69 ( V_31 , V_34 -> V_55 . V_66 ,
V_34 -> V_55 . V_53 ) ;
V_5 -> V_142 . V_143 += V_34 -> V_55 . V_139 ;
F_2 ( V_144 , V_34 -> V_35 . V_38 + V_145 ) ;
F_59 ( & V_34 -> V_51 , V_128 ) ;
F_68 ( V_31 ) ;
return V_140 ;
}
static void F_70 ( struct V_33 * V_34 , T_6 V_36 )
{
int V_37 , V_146 , V_147 , V_148 ;
F_55 (self != NULL, return;) ;
V_37 = V_34 -> V_35 . V_37 ;
V_34 -> V_35 . V_36 = V_36 ;
switch ( V_36 ) {
default:
case 576000 :
V_146 = V_149 ;
V_147 = V_150 ;
V_148 = 0 ;
F_21 ( 0 , L_23 , V_21 ) ;
break;
case 1152000 :
V_146 = V_149 ;
V_147 = V_151 | V_150 ;
V_148 = V_152 | V_153 ;
F_21 ( 0 , L_24 ,
V_21 ) ;
break;
case 4000000 :
V_146 = V_154 ;
V_147 = V_150 ;
V_148 = V_152 ;
F_21 ( 0 , L_25 ,
V_21 ) ;
break;
}
#if 0
Now in tranceiver!
register_bank(fir_base, 0);
outb((inb(fir_base + IRCC_LCR_A) & 0xbf) | fast, fir_base + IRCC_LCR_A);
#endif
F_1 ( V_37 , 1 ) ;
F_2 ( ( ( F_3 ( V_37 + V_115 ) & V_155 ) | V_146 ) , V_37 + V_115 ) ;
F_1 ( V_37 , 4 ) ;
F_2 ( ( F_3 ( V_37 + V_122 ) & 0x30 ) | V_147 , V_37 + V_122 ) ;
}
static void F_71 ( struct V_33 * V_34 )
{
struct V_32 * V_5 ;
int V_37 ;
F_21 ( 1 , L_6 , V_21 ) ;
F_55 (self != NULL, return;) ;
V_5 = V_34 -> V_49 ;
F_55 (dev != NULL, return;) ;
V_37 = V_34 -> V_35 . V_37 ;
F_2 ( F_3 ( V_37 + V_123 ) | V_156 , V_37 + V_123 ) ;
F_1 ( V_37 , 1 ) ;
#ifdef F_72
F_2 ( ( ( F_3 ( V_37 + V_117 ) & 0x3f ) | V_118 ) ,
V_37 + V_117 ) ;
#else
F_2 ( ( ( F_3 ( V_37 + V_117 ) & 0x3f ) | V_119 ) ,
V_37 + V_117 ) ;
#endif
( void ) F_3 ( V_37 + V_120 ) ;
F_2 ( 0 , V_37 + V_3 ) ;
F_1 ( V_37 , 0 ) ;
F_2 ( V_157 | V_158 , V_37 + V_159 ) ;
F_2 ( V_160 , V_37 + V_3 ) ;
}
static void F_73 ( struct V_33 * V_34 )
{
int V_37 ;
F_21 ( 1 , L_6 , V_21 ) ;
F_55 (self != NULL, return;) ;
V_37 = V_34 -> V_35 . V_37 ;
F_1 ( V_37 , 0 ) ;
F_2 ( F_3 ( V_37 + V_161 ) & V_162 , V_37 + V_161 ) ;
}
static void F_58 ( struct V_33 * V_34 , T_6 V_36 )
{
struct V_32 * V_5 ;
int V_163 ;
F_21 ( 0 , L_26 , V_21 , V_36 ) ;
F_55 (self != NULL, return;) ;
V_5 = V_34 -> V_49 ;
V_163 = V_34 -> V_35 . V_36 <= V_164 ;
#if 0
speed= 1152000;
self->io.speed = speed;
last_speed_was_sir = 0;
smsc_ircc_fir_start(self);
#endif
if ( V_34 -> V_35 . V_36 == 0 )
F_63 ( V_34 ) ;
#if 0
if (!last_speed_was_sir) speed = self->io.speed;
#endif
if ( V_34 -> V_35 . V_36 != V_36 )
F_74 ( V_34 , V_36 ) ;
V_34 -> V_35 . V_36 = V_36 ;
if ( V_36 <= V_164 ) {
if ( ! V_163 ) {
F_73 ( V_34 ) ;
F_63 ( V_34 ) ;
}
F_53 ( V_34 , V_36 ) ;
} else {
if ( V_163 ) {
#if V_165
F_75 ( V_34 ) ;
#endif
F_71 ( V_34 ) ;
}
F_70 ( V_34 , V_36 ) ;
#if 0
self->tx_buff.len = 10;
self->tx_buff.data = self->tx_buff.head;
smsc_ircc_dma_xmit(self, 4000);
#endif
F_76 ( V_34 ) ;
}
F_64 ( V_5 ) ;
}
static void F_53 ( struct V_33 * V_34 , T_7 V_36 )
{
int V_1 ;
int V_166 ;
int V_167 ;
int V_168 ;
F_21 ( 0 , L_27 , V_21 , V_36 ) ;
F_55 (self != NULL, return;) ;
V_1 = V_34 -> V_35 . V_38 ;
V_34 -> V_35 . V_36 = V_36 ;
F_2 ( 0 , V_1 + V_145 ) ;
V_168 = V_164 / V_36 ;
V_166 = V_169 ;
V_166 |= V_34 -> V_35 . V_36 < 38400 ?
V_170 : V_171 ;
V_167 = V_172 ;
F_2 ( V_173 | V_167 , V_1 + V_174 ) ;
F_2 ( V_168 & 0xff , V_1 + V_175 ) ;
F_2 ( V_168 >> 8 , V_1 + V_176 ) ;
F_2 ( V_167 , V_1 + V_174 ) ;
F_2 ( V_166 , V_1 + V_177 ) ;
F_2 ( V_178 | V_179 | V_144 , V_1 + V_145 ) ;
F_21 ( 2 , L_28 , V_21 , V_36 ) ;
}
static T_4 F_28 ( struct V_30 * V_31 ,
struct V_32 * V_5 )
{
struct V_33 * V_34 ;
unsigned long V_128 ;
T_5 V_36 ;
int V_180 ;
F_55 (dev != NULL, return NETDEV_TX_OK;) ;
V_34 = F_27 ( V_5 ) ;
F_55 (self != NULL, return NETDEV_TX_OK;) ;
F_65 ( V_5 ) ;
F_57 ( & V_34 -> V_51 , V_128 ) ;
V_36 = F_66 ( V_31 ) ;
if ( V_36 != V_34 -> V_35 . V_36 && V_36 != - 1 ) {
if ( ! V_31 -> V_139 ) {
F_58 ( V_34 , V_36 ) ;
F_59 ( & V_34 -> V_51 , V_128 ) ;
F_68 ( V_31 ) ;
return V_140 ;
}
V_34 -> V_141 = V_36 ;
}
F_77 ( V_31 , V_34 -> V_55 . V_57 , V_31 -> V_139 ) ;
V_34 -> V_55 . V_139 = V_31 -> V_139 ;
V_34 -> V_55 . V_66 = V_34 -> V_55 . V_57 ;
V_180 = F_78 ( V_31 ) ;
if ( V_180 ) {
int V_181 ;
V_181 = V_180 * ( V_34 -> V_35 . V_36 / 1000 ) / 8000 ;
if ( V_181 > 4095 )
V_181 = 4095 ;
F_79 ( V_34 , V_181 ) ;
} else {
F_79 ( V_34 , 0 ) ;
}
F_59 ( & V_34 -> V_51 , V_128 ) ;
F_68 ( V_31 ) ;
return V_140 ;
}
static void F_79 ( struct V_33 * V_34 , int V_181 )
{
int V_1 = V_34 -> V_35 . V_37 ;
T_2 V_147 ;
F_21 ( 3 , L_6 , V_21 ) ;
#if 1
F_1 ( V_1 , 0 ) ;
F_2 ( 0x00 , V_1 + V_161 ) ;
#endif
F_1 ( V_1 , 1 ) ;
F_2 ( F_3 ( V_1 + V_117 ) & ~ V_182 ,
V_1 + V_117 ) ;
V_34 -> V_35 . V_183 = V_184 ;
F_1 ( V_1 , 4 ) ;
F_2 ( V_181 & 0xff , V_1 + V_185 ) ;
V_147 = F_3 ( V_1 + V_122 ) & 0xf0 ;
F_2 ( V_147 | ( ( V_181 >> 8 ) & 0x0f ) , V_1 + V_186 ) ;
F_2 ( V_34 -> V_55 . V_139 >> 8 , V_1 + V_187 ) ;
F_2 ( V_34 -> V_55 . V_139 & 0xff , V_1 + V_188 ) ;
F_1 ( V_1 , 1 ) ;
F_2 ( F_3 ( V_1 + V_117 ) | V_182 |
V_189 , V_1 + V_117 ) ;
F_80 ( V_34 -> V_35 . V_10 , V_34 -> V_61 , V_34 -> V_55 . V_139 ,
V_190 ) ;
F_1 ( V_1 , 0 ) ;
F_2 ( V_157 | V_158 , V_1 + V_159 ) ;
F_2 ( V_160 , V_1 + V_3 ) ;
F_2 ( V_191 | V_162 , V_1 + V_161 ) ;
}
static void F_81 ( struct V_33 * V_34 )
{
int V_1 = V_34 -> V_35 . V_37 ;
F_21 ( 3 , L_6 , V_21 ) ;
#if 0
register_bank(iobase, 0);
outb(0x00, iobase + IRCC_LCR_B);
#endif
F_1 ( V_1 , 1 ) ;
F_2 ( F_3 ( V_1 + V_117 ) & ~ V_182 ,
V_1 + V_117 ) ;
F_1 ( V_1 , 0 ) ;
if ( F_3 ( V_1 + V_192 ) & V_193 ) {
V_34 -> V_49 -> V_142 . V_194 ++ ;
V_34 -> V_49 -> V_142 . V_195 ++ ;
F_1 ( V_1 , 0 ) ;
F_2 ( V_196 , V_1 + V_3 ) ;
F_2 ( 0x00 , V_1 + V_3 ) ;
} else {
V_34 -> V_49 -> V_142 . V_197 ++ ;
V_34 -> V_49 -> V_142 . V_143 += V_34 -> V_55 . V_139 ;
}
if ( V_34 -> V_141 ) {
F_58 ( V_34 , V_34 -> V_141 ) ;
V_34 -> V_141 = 0 ;
}
F_64 ( V_34 -> V_49 ) ;
}
static int F_76 ( struct V_33 * V_34 )
{
int V_1 = V_34 -> V_35 . V_37 ;
#if 0
register_bank(iobase, 1);
outb(inb(iobase + IRCC_SCE_CFGB) & ~IRCC_CFGB_DMA_ENABLE,
iobase + IRCC_SCE_CFGB);
#endif
F_1 ( V_1 , 0 ) ;
F_2 ( 0x00 , V_1 + V_161 ) ;
F_1 ( V_1 , 1 ) ;
F_2 ( F_3 ( V_1 + V_117 ) & ~ V_182 ,
V_1 + V_117 ) ;
V_34 -> V_35 . V_183 = V_198 ;
V_34 -> V_52 . V_66 = V_34 -> V_52 . V_57 ;
F_1 ( V_1 , 4 ) ;
F_2 ( ( 2050 >> 8 ) & 0x0f , V_1 + V_199 ) ;
F_2 ( 2050 & 0xff , V_1 + V_200 ) ;
F_80 ( V_34 -> V_35 . V_10 , V_34 -> V_58 , V_34 -> V_52 . V_53 ,
V_201 ) ;
F_1 ( V_1 , 1 ) ;
F_2 ( F_3 ( V_1 + V_117 ) | V_182 |
V_189 , V_1 + V_117 ) ;
F_1 ( V_1 , 0 ) ;
F_2 ( V_157 | V_158 , V_1 + V_159 ) ;
F_2 ( V_160 , V_1 + V_3 ) ;
F_1 ( V_1 , 0 ) ;
F_2 ( V_202 | V_162 ,
V_1 + V_161 ) ;
return 0 ;
}
static void F_82 ( struct V_33 * V_34 )
{
struct V_30 * V_31 ;
int V_139 , V_203 , V_204 ;
int V_1 = V_34 -> V_35 . V_37 ;
F_1 ( V_1 , 0 ) ;
F_21 ( 3 , L_6 , V_21 ) ;
#if 0
register_bank(iobase, 0);
outb(0x00, iobase + IRCC_LCR_B);
#endif
F_1 ( V_1 , 0 ) ;
F_2 ( F_3 ( V_1 + V_205 ) & ~ V_206 , V_1 + V_205 ) ;
V_204 = F_3 ( V_1 + V_192 ) ;
V_203 = F_3 ( V_1 + V_161 ) & 0x08 ;
F_21 ( 2 , L_29 , V_21 ,
F_83 ( V_34 -> V_35 . V_10 ) ) ;
V_139 = V_34 -> V_52 . V_53 - F_83 ( V_34 -> V_35 . V_10 ) ;
if ( V_204 & ( V_207 | V_208 | V_209 ) ) {
V_34 -> V_49 -> V_142 . V_210 ++ ;
if ( V_204 & V_207 )
V_34 -> V_49 -> V_142 . V_211 ++ ;
if ( V_204 & V_208 )
V_34 -> V_49 -> V_142 . V_212 ++ ;
if ( V_204 & V_209 )
V_34 -> V_49 -> V_142 . V_213 ++ ;
if ( V_204 & ( V_193 | V_214 ) )
V_34 -> V_49 -> V_142 . V_213 ++ ;
return;
}
V_139 -= V_34 -> V_35 . V_36 < 4000000 ? 2 : 4 ;
if ( V_139 < 2 || V_139 > 2050 ) {
F_32 ( L_30 , V_21 , V_139 ) ;
return;
}
F_21 ( 2 , L_31 , V_21 , V_203 , V_139 ) ;
V_31 = F_84 ( V_139 + 1 ) ;
if ( ! V_31 ) {
F_32 ( L_32 ,
V_21 ) ;
return;
}
F_85 ( V_31 , 1 ) ;
memcpy ( F_86 ( V_31 , V_139 ) , V_34 -> V_52 . V_66 , V_139 ) ;
V_34 -> V_49 -> V_142 . V_215 ++ ;
V_34 -> V_49 -> V_142 . V_216 += V_139 ;
V_31 -> V_5 = V_34 -> V_49 ;
F_87 ( V_31 ) ;
V_31 -> V_217 = F_88 ( V_218 ) ;
F_89 ( V_31 ) ;
}
static void F_90 ( struct V_33 * V_34 )
{
int V_219 = 0 ;
int V_1 ;
F_55 (self != NULL, return;) ;
V_1 = V_34 -> V_35 . V_38 ;
do {
F_91 ( V_34 -> V_49 , & V_34 -> V_49 -> V_142 , & V_34 -> V_52 ,
F_3 ( V_1 + V_220 ) ) ;
if ( V_219 ++ > 32 ) {
F_21 ( 2 , L_33 , V_21 ) ;
break;
}
} while ( F_3 ( V_1 + V_221 ) & V_222 );
}
static T_8 F_92 ( int V_223 , void * V_7 )
{
struct V_32 * V_5 = V_7 ;
struct V_33 * V_34 = F_27 ( V_5 ) ;
int V_1 , V_224 , V_225 , V_204 ;
T_8 V_14 = V_226 ;
F_93 ( & V_34 -> V_51 ) ;
if ( V_34 -> V_35 . V_36 <= V_164 ) {
V_14 = F_94 ( V_5 ) ;
goto V_227;
}
V_1 = V_34 -> V_35 . V_37 ;
F_1 ( V_1 , 0 ) ;
V_224 = F_3 ( V_1 + V_228 ) ;
if ( V_224 == 0 )
goto V_227;
V_14 = V_229 ;
F_2 ( 0 , V_1 + V_159 ) ;
V_225 = F_3 ( V_1 + V_123 ) ;
V_204 = F_3 ( V_1 + V_192 ) ;
F_21 ( 2 , L_34 , V_21 , V_224 ) ;
if ( V_224 & V_230 ) {
if ( V_34 -> V_35 . V_183 == V_198 )
F_82 ( V_34 ) ;
else
F_81 ( V_34 ) ;
F_76 ( V_34 ) ;
}
if ( V_224 & V_231 ) {
}
F_1 ( V_1 , 0 ) ;
F_2 ( V_157 | V_158 , V_1 + V_159 ) ;
V_227:
F_95 ( & V_34 -> V_51 ) ;
return V_14 ;
}
static T_8 F_94 ( struct V_32 * V_5 )
{
struct V_33 * V_34 = F_27 ( V_5 ) ;
int V_219 = 0 ;
int V_1 ;
int V_224 , V_204 ;
V_1 = V_34 -> V_35 . V_38 ;
V_224 = F_3 ( V_1 + V_232 ) & V_233 ;
if ( V_224 == 0 )
return V_226 ;
while ( V_224 ) {
V_204 = F_3 ( V_1 + V_221 ) ;
F_21 ( 4 , L_35 ,
V_21 , V_224 , V_204 , V_1 ) ;
switch ( V_224 ) {
case V_234 :
F_21 ( 2 , L_36 , V_21 ) ;
break;
case V_235 :
F_90 ( V_34 ) ;
break;
case V_236 :
if ( V_204 & V_237 )
F_96 ( V_34 ) ;
break;
default:
F_21 ( 0 , L_37 ,
V_21 , V_224 ) ;
break;
}
if ( V_219 ++ > 100 )
break;
V_224 = F_3 ( V_1 + V_232 ) & V_233 ;
}
return V_229 ;
}
static int F_97 ( struct V_33 * V_34 )
{
int error ;
error = F_98 ( V_34 -> V_35 . V_11 , F_92 , 0 ,
V_34 -> V_49 -> V_74 , V_34 -> V_49 ) ;
if ( error )
F_21 ( 0 , L_38 ,
V_21 , V_34 -> V_35 . V_11 , error ) ;
return error ;
}
static void F_99 ( struct V_33 * V_34 )
{
unsigned long V_128 ;
F_57 ( & V_34 -> V_51 , V_128 ) ;
V_34 -> V_35 . V_36 = 0 ;
F_58 ( V_34 , V_98 ) ;
F_59 ( & V_34 -> V_51 , V_128 ) ;
}
static void F_100 ( struct V_33 * V_34 )
{
int V_1 = V_34 -> V_35 . V_37 ;
unsigned long V_128 ;
F_57 ( & V_34 -> V_51 , V_128 ) ;
F_1 ( V_1 , 0 ) ;
F_2 ( 0 , V_1 + V_159 ) ;
F_2 ( V_114 , V_1 + V_3 ) ;
F_2 ( 0x00 , V_1 + V_3 ) ;
F_59 ( & V_34 -> V_51 , V_128 ) ;
}
static int F_101 ( struct V_32 * V_5 )
{
struct V_33 * V_34 ;
char V_238 [ 16 ] ;
F_21 ( 1 , L_6 , V_21 ) ;
F_55 (dev != NULL, return -1;) ;
V_34 = F_27 ( V_5 ) ;
F_55 (self != NULL, return 0;) ;
if ( V_34 -> V_35 . V_239 ) {
F_21 ( 0 , L_39 , V_21 ) ;
return - V_240 ;
}
if ( F_98 ( V_34 -> V_35 . V_11 , F_92 , 0 , V_5 -> V_74 ,
( void * ) V_5 ) ) {
F_21 ( 0 , L_40 ,
V_21 , V_34 -> V_35 . V_11 ) ;
return - V_240 ;
}
F_99 ( V_34 ) ;
sprintf ( V_238 , L_41 , V_34 -> V_35 . V_37 ) ;
V_34 -> V_241 = F_102 ( V_5 , & V_34 -> V_99 , V_238 ) ;
if ( F_103 ( V_34 -> V_35 . V_10 , V_5 -> V_74 ) ) {
F_104 ( V_5 ) ;
F_32 ( L_42 ,
V_21 , V_34 -> V_35 . V_10 ) ;
return - V_240 ;
}
F_105 ( V_5 ) ;
return 0 ;
}
static int F_104 ( struct V_32 * V_5 )
{
struct V_33 * V_34 ;
F_21 ( 1 , L_6 , V_21 ) ;
F_55 (dev != NULL, return -1;) ;
V_34 = F_27 ( V_5 ) ;
F_55 (self != NULL, return 0;) ;
F_65 ( V_5 ) ;
if ( V_34 -> V_241 )
F_106 ( V_34 -> V_241 ) ;
V_34 -> V_241 = NULL ;
F_100 ( V_34 ) ;
if ( ! V_34 -> V_35 . V_239 )
F_107 ( V_34 -> V_35 . V_11 , V_5 ) ;
F_108 ( V_34 -> V_35 . V_10 ) ;
F_109 ( V_34 -> V_35 . V_10 ) ;
return 0 ;
}
static int F_110 ( struct V_242 * V_5 , T_9 V_64 )
{
struct V_33 * V_34 = F_111 ( V_5 ) ;
if ( ! V_34 -> V_35 . V_239 ) {
F_21 ( 1 , L_43 , V_20 ) ;
F_112 () ;
if ( F_113 ( V_34 -> V_49 ) ) {
F_114 ( V_34 -> V_49 ) ;
F_100 ( V_34 ) ;
F_107 ( V_34 -> V_35 . V_11 , V_34 -> V_49 ) ;
F_108 ( V_34 -> V_35 . V_10 ) ;
}
V_34 -> V_35 . V_239 = 1 ;
F_115 () ;
}
return 0 ;
}
static int F_116 ( struct V_242 * V_5 )
{
struct V_33 * V_34 = F_111 ( V_5 ) ;
if ( V_34 -> V_35 . V_239 ) {
F_21 ( 1 , L_44 , V_20 ) ;
F_112 () ;
F_38 ( V_34 ) ;
if ( F_113 ( V_34 -> V_49 ) ) {
if ( F_97 ( V_34 ) ) {
F_117 ( V_34 -> V_49 ) ;
} else {
F_118 ( V_34 -> V_35 . V_10 ) ;
F_99 ( V_34 ) ;
F_119 ( V_34 -> V_49 ) ;
}
}
V_34 -> V_35 . V_239 = 0 ;
F_115 () ;
}
return 0 ;
}
static int T_10 F_120 ( struct V_33 * V_34 )
{
F_21 ( 1 , L_6 , V_21 ) ;
F_55 (self != NULL, return -1;) ;
F_121 ( V_34 -> V_71 ) ;
F_45 ( V_34 -> V_49 ) ;
F_100 ( V_34 ) ;
F_21 ( 0 , L_45 , V_21 ,
V_34 -> V_35 . V_37 ) ;
F_48 ( V_34 -> V_35 . V_37 , V_34 -> V_35 . V_94 ) ;
F_21 ( 0 , L_45 , V_21 ,
V_34 -> V_35 . V_38 ) ;
F_48 ( V_34 -> V_35 . V_38 , V_34 -> V_35 . V_95 ) ;
if ( V_34 -> V_55 . V_57 )
F_46 ( NULL , V_34 -> V_55 . V_53 ,
V_34 -> V_55 . V_57 , V_34 -> V_61 ) ;
if ( V_34 -> V_52 . V_57 )
F_46 ( NULL , V_34 -> V_52 . V_53 ,
V_34 -> V_52 . V_57 , V_34 -> V_58 ) ;
F_47 ( V_34 -> V_49 ) ;
return 0 ;
}
static void T_10 F_122 ( void )
{
int V_243 ;
F_21 ( 1 , L_6 , V_21 ) ;
for ( V_243 = 0 ; V_243 < 2 ; V_243 ++ ) {
if ( V_42 [ V_243 ] )
F_120 ( V_42 [ V_243 ] ) ;
}
if ( V_29 )
F_24 ( & V_28 ) ;
F_25 ( & V_22 ) ;
}
static void F_63 ( struct V_33 * V_34 )
{
struct V_32 * V_5 ;
int V_37 , V_38 ;
F_21 ( 3 , L_6 , V_21 ) ;
F_55 (self != NULL, return;) ;
V_5 = V_34 -> V_49 ;
F_55 (dev != NULL, return;) ;
V_37 = V_34 -> V_35 . V_37 ;
V_38 = V_34 -> V_35 . V_38 ;
F_2 ( V_114 , V_37 + V_3 ) ;
#if V_165
#endif
F_1 ( V_37 , 1 ) ;
F_2 ( ( ( F_3 ( V_37 + V_115 ) & V_155 ) | V_116 ) , V_37 + V_115 ) ;
F_2 ( V_172 , V_38 + V_174 ) ;
F_2 ( ( V_244 | V_245 | V_246 ) , V_38 + V_247 ) ;
F_2 ( V_178 | V_179 | V_144 , V_38 + V_145 ) ;
F_21 ( 3 , L_46 , V_21 ) ;
F_2 ( 0x00 , V_37 + V_3 ) ;
}
void F_75 ( struct V_33 * V_34 )
{
int V_1 ;
F_21 ( 3 , L_6 , V_21 ) ;
V_1 = V_34 -> V_35 . V_38 ;
F_2 ( 0 , V_1 + V_247 ) ;
F_2 ( 0 , V_1 + V_145 ) ;
}
static void F_96 ( struct V_33 * V_34 )
{
int V_248 = 0 ;
int V_1 ;
int V_166 ;
F_55 (self != NULL, return;) ;
F_21 ( 4 , L_6 , V_21 ) ;
V_1 = V_34 -> V_35 . V_38 ;
if ( V_34 -> V_55 . V_139 > 0 ) {
V_248 = F_123 ( V_1 , V_34 -> V_35 . V_96 ,
V_34 -> V_55 . V_66 , V_34 -> V_55 . V_139 ) ;
V_34 -> V_55 . V_66 += V_248 ;
V_34 -> V_55 . V_139 -= V_248 ;
} else {
if ( V_34 -> V_141 ) {
F_21 ( 5 , L_47 ,
V_21 , V_34 -> V_141 ) ;
F_67 ( V_34 ) ;
F_58 ( V_34 , V_34 -> V_141 ) ;
V_34 -> V_141 = 0 ;
} else {
F_64 ( V_34 -> V_49 ) ;
}
V_34 -> V_49 -> V_142 . V_197 ++ ;
if ( V_34 -> V_35 . V_36 <= 115200 ) {
V_166 = V_169 | V_249 ;
V_166 |= V_34 -> V_35 . V_36 < 38400 ?
V_170 : V_171 ;
F_2 ( V_166 , V_1 + V_177 ) ;
F_2 ( V_179 , V_1 + V_145 ) ;
}
}
}
static int F_123 ( int V_1 , int V_96 , T_11 * V_250 , int V_139 )
{
int V_248 = 0 ;
if ( ! ( F_3 ( V_1 + V_221 ) & V_237 ) ) {
F_32 ( L_48 , V_21 ) ;
return 0 ;
}
while ( V_96 -- > 0 && V_248 < V_139 ) {
F_2 ( V_250 [ V_248 ] , V_1 + V_251 ) ;
V_248 ++ ;
}
return V_248 ;
}
static int F_61 ( struct V_33 * V_34 )
{
return V_34 -> V_52 . V_64 != V_65 ;
}
static void F_39 ( struct V_33 * V_34 )
{
unsigned int V_243 ;
F_55 (self != NULL, return;) ;
for ( V_243 = 0 ; V_252 [ V_243 ] . V_74 != NULL ; V_243 ++ )
if ( V_252 [ V_243 ] . F_124 ( V_34 -> V_35 . V_37 ) ) {
F_16 ( L_49 ,
V_252 [ V_243 ] . V_74 ) ;
V_34 -> V_69 = V_243 + 1 ;
return;
}
F_16 ( L_50 ,
V_252 [ V_253 ] . V_74 ) ;
V_34 -> V_69 = V_253 ;
}
static void F_74 ( struct V_33 * V_34 , T_6 V_36 )
{
unsigned int V_254 ;
V_254 = V_34 -> V_69 ;
if ( V_254 > 0 )
V_252 [ V_254 - 1 ] . F_125 ( V_34 -> V_35 . V_37 , V_36 ) ;
}
static void F_67 ( struct V_33 * V_34 )
{
int V_1 = V_34 -> V_35 . V_38 ;
int V_255 = V_256 ;
while ( V_255 -- > 0 && ! ( F_3 ( V_1 + V_221 ) & V_257 ) )
F_126 ( 1 ) ;
if ( V_255 < 0 )
F_21 ( 0 , L_51 , V_21 ) ;
}
static int T_3 F_19 ( void )
{
struct V_258 * V_259 ;
char * type ;
unsigned int V_260 , V_261 ;
V_261 = 0 ;
V_259 = V_262 ;
while ( V_259 -> V_260 ) {
V_260 = V_259 -> V_260 ;
if ( V_259 -> type & V_263 ) {
type = L_52 ;
if ( V_259 -> type & V_264 )
if ( ! F_127 ( V_265 , V_260 , type ) )
V_261 ++ ;
if ( V_259 -> type & V_266 )
if ( ! F_128 ( V_267 , V_260 , type ) )
V_261 ++ ;
}
if ( V_259 -> type & V_268 ) {
type = L_53 ;
if ( V_259 -> type & V_264 )
if ( ! F_127 ( V_269 , V_260 , type ) )
V_261 ++ ;
if ( V_259 -> type & V_266 )
if ( ! F_128 ( V_270 , V_260 , type ) )
V_261 ++ ;
}
V_259 ++ ;
}
return V_261 ;
}
static int T_3 F_127 ( const struct V_271 * V_272 , unsigned short V_273 , char * type )
{
unsigned short V_8 , V_9 ;
T_2 V_274 , V_10 , V_11 ;
int V_14 = - V_13 ;
F_21 ( 1 , L_6 , V_21 ) ;
if ( F_129 ( V_273 , V_275 , V_272 , type ) == NULL )
return V_14 ;
F_2 ( V_276 , V_273 ) ;
V_274 = F_3 ( V_273 + 1 ) ;
if ( ! ( V_274 & V_277 ) )
F_32 ( L_54 , V_21 ) ;
F_2 ( V_278 , V_273 ) ;
V_9 = F_3 ( V_273 + 1 ) << 2 ;
F_2 ( V_279 , V_273 ) ;
V_8 = F_3 ( V_273 + 1 ) << 3 ;
F_2 ( V_280 , V_273 ) ;
V_10 = F_3 ( V_273 + 1 ) & V_281 ;
F_2 ( V_282 , V_273 ) ;
V_11 = F_3 ( V_273 + 1 ) & V_283 ;
F_16 ( L_55 , V_21 , V_8 , V_9 , V_10 , V_11 , V_274 ) ;
if ( V_8 && F_11 ( V_8 , V_9 , V_10 , V_11 ) == 0 )
V_14 = 0 ;
F_2 ( V_284 , V_273 ) ;
return V_14 ;
}
static int T_3 F_128 ( const struct V_271 * V_272 , unsigned short V_260 , char * type )
{
unsigned short V_285 , V_286 ;
int V_14 = - V_13 ;
F_21 ( 1 , L_6 , V_21 ) ;
if ( F_129 ( V_260 , 0x20 , V_272 , type ) == NULL )
return V_14 ;
F_2 ( 0x07 , V_260 ) ;
F_2 ( 0x05 , V_260 + 1 ) ;
F_2 ( 0x60 , V_260 ) ;
V_286 = F_3 ( V_260 + 1 ) << 8 ;
F_2 ( 0x61 , V_260 ) ;
V_286 |= F_3 ( V_260 + 1 ) ;
F_2 ( 0x62 , V_260 ) ;
V_285 = F_3 ( V_260 + 1 ) << 8 ;
F_2 ( 0x63 , V_260 ) ;
V_285 |= F_3 ( V_260 + 1 ) ;
F_2 ( 0x2b , V_260 ) ;
if ( V_285 && F_11 ( V_285 , V_286 , V_18 , V_19 ) == 0 )
V_14 = 0 ;
F_2 ( V_284 , V_260 ) ;
return V_14 ;
}
static int T_3 F_130 ( unsigned short V_260 , unsigned char V_287 )
{
F_21 ( 1 , L_6 , V_21 ) ;
F_2 ( V_287 , V_260 ) ;
return F_3 ( V_260 ) != V_287 ? - 1 : 0 ;
}
static const struct V_271 * T_3 F_129 ( unsigned short V_260 , T_2 V_287 , const struct V_271 * V_79 , char * type )
{
T_2 V_288 , V_289 , V_290 ;
F_21 ( 1 , L_6 , V_21 ) ;
F_2 ( V_284 , V_260 ) ;
if ( F_3 ( V_260 ) == V_284 )
return NULL ;
F_2 ( V_287 , V_260 ) ;
V_289 = F_3 ( V_260 + 1 ) ;
F_2 ( V_291 , V_260 ) ;
#if 0
if (smsc_access(cfg_base,0x55))
return NULL;
#endif
if ( F_130 ( V_260 , V_287 ) )
return NULL ;
V_288 = F_3 ( V_260 + 1 ) ;
if ( V_288 == 0 || V_288 == 0xff )
return NULL ;
if ( F_130 ( V_260 , V_287 + 1 ) )
return NULL ;
V_290 = F_3 ( V_260 + 1 ) ;
if ( V_290 >= 128 )
return NULL ;
if ( V_288 == V_289 )
return NULL ;
while ( V_79 -> V_288 != V_288 ) {
V_79 ++ ;
if ( V_79 -> V_74 == NULL )
return NULL ;
}
F_16 ( L_56 ,
V_288 , V_290 , V_260 , type , V_79 -> V_74 ) ;
if ( V_79 -> V_290 > V_290 ) {
F_16 ( L_57 ) ;
return NULL ;
}
if ( V_79 -> V_128 & V_292 )
F_16 ( L_58 ) ;
return V_79 ;
}
static int T_3 F_17 ( unsigned short V_260 )
{
int V_14 = - 1 ;
if ( ! F_49 ( V_260 , 2 , V_20 ) ) {
F_32 ( L_59 ,
V_21 , V_260 ) ;
} else {
if ( ! F_127 ( V_265 , V_260 , L_52 ) ||
! F_128 ( V_267 , V_260 , L_52 ) )
V_14 = 0 ;
F_48 ( V_260 , 2 ) ;
}
return V_14 ;
}
static int T_3 F_18 ( unsigned short V_260 )
{
int V_14 = - 1 ;
if ( ! F_49 ( V_260 , 2 , V_20 ) ) {
F_32 ( L_59 ,
V_21 , V_260 ) ;
} else {
if ( ! F_127 ( V_269 , V_260 , L_53 ) ||
! F_128 ( V_270 , V_260 , L_53 ) )
V_14 = 0 ;
F_48 ( V_260 , 2 ) ;
}
return V_14 ;
}
static int T_3 F_131 ( struct
V_293
* V_294 )
{
unsigned short V_1 = V_294 -> V_260 ;
unsigned char V_295 ;
F_2 ( V_296 , V_1 ) ;
F_2 ( V_275 , V_1 ) ;
V_295 = F_3 ( V_1 + 1 ) ;
F_21 ( 0 ,
L_60 ,
V_295 ) ;
F_2 ( 0x24 , V_1 ) ;
F_2 ( 0x00 , V_1 + 1 ) ;
F_2 ( V_278 , V_1 ) ;
F_2 ( ( V_294 -> V_286 >> 2 ) , V_1 + 1 ) ;
V_295 = F_3 ( V_1 + 1 ) ;
if ( V_295 != ( V_294 -> V_286 >> 2 ) ) {
F_32 ( L_61 ) ;
F_32 ( L_62 ) ;
return - V_297 ;
}
F_2 ( V_282 , V_1 ) ;
V_295 = F_3 ( V_1 + 1 ) ;
V_295 &= V_298 ;
V_295 |= ( V_294 -> V_299 & V_283 ) ;
F_2 ( V_295 , V_1 + 1 ) ;
V_295 = F_3 ( V_1 + 1 ) & V_283 ;
if ( V_295 != V_294 -> V_299 ) {
F_32 ( L_63 ) ;
return - V_297 ;
}
F_2 ( V_279 , V_1 ) ;
F_2 ( ( V_294 -> V_285 >> 3 ) , V_1 + 1 ) ;
V_295 = F_3 ( V_1 + 1 ) ;
if ( V_295 != ( V_294 -> V_285 >> 3 ) ) {
F_32 ( L_64 ) ;
return - V_297 ;
}
F_2 ( V_280 , V_1 ) ;
F_2 ( ( V_294 -> V_300 & V_301 ) , V_1 + 1 ) ;
V_295 = F_3 ( V_1 + 1 ) & V_301 ;
if ( V_295 != ( V_294 -> V_300 & V_301 ) ) {
F_32 ( L_65 ) ;
return - V_297 ;
}
F_2 ( V_276 , V_1 ) ;
V_295 = F_3 ( V_1 + 1 ) ;
V_295 &= ~ V_302 |
V_277 ;
F_2 ( V_295 , V_1 + 1 ) ;
F_2 ( V_303 , V_1 ) ;
V_295 = F_3 ( V_1 + 1 ) ;
F_2 ( V_295 | V_304 , V_1 + 1 ) ;
F_2 ( 0x0a , V_1 ) ;
V_295 = F_3 ( V_1 + 1 ) ;
F_2 ( V_295 | 0x40 , V_1 + 1 ) ;
F_2 ( V_305 , V_1 ) ;
V_295 = F_3 ( V_1 + 1 ) ;
F_2 ( V_295 | V_306 , V_1 + 1 ) ;
F_2 ( V_307 , V_1 ) ;
V_295 = F_3 ( V_1 + 1 ) ;
F_2 ( V_295 | V_308 , V_1 + 1 ) ;
F_2 ( V_309 , V_1 ) ;
return 0 ;
}
static int T_3 F_132 ( struct V_310 * V_5 ,
struct
V_293
* V_294 )
{
unsigned short V_311 ;
unsigned char V_295 ;
F_16 ( L_66 ) ;
F_133 ( V_5 , V_312 , & V_295 ) ;
V_295 &= 0xf8 ;
switch( V_294 -> V_286 ) {
case 0x3f8 :
V_295 |= 0x00 ;
break;
case 0x2f8 :
V_295 |= 0x01 ;
break;
case 0x220 :
V_295 |= 0x02 ;
break;
case 0x228 :
V_295 |= 0x03 ;
break;
case 0x238 :
V_295 |= 0x04 ;
break;
case 0x2e8 :
V_295 |= 0x05 ;
break;
case 0x338 :
V_295 |= 0x06 ;
break;
case 0x3e8 :
V_295 |= 0x07 ;
break;
default:
V_295 |= 0x01 ;
}
F_21 ( 1 , L_67 , V_295 ) ;
F_134 ( V_5 , V_312 , V_295 ) ;
F_135 ( V_5 , V_313 , & V_311 ) ;
switch( V_294 -> V_260 ) {
case 0x04e :
V_311 |= 0x2000 ;
break;
case 0x02e :
V_311 |= 0x1000 ;
break;
case 0x062 :
V_311 |= 0x0800 ;
break;
case 0x060 :
V_311 |= 0x0400 ;
break;
default:
F_32 ( L_68 ,
V_294 -> V_260 ) ;
break;
}
V_311 &= 0xfffd ;
V_311 |= 0x0001 ;
F_21 ( 1 , L_69 , V_311 ) ;
F_136 ( V_5 , V_313 , V_311 ) ;
F_135 ( V_5 , V_314 , & V_311 ) ;
switch( V_294 -> V_300 ) {
case 0x07 :
V_311 |= 0xc000 ;
break;
case 0x06 :
V_311 |= 0x3000 ;
break;
case 0x05 :
V_311 |= 0x0c00 ;
break;
case 0x03 :
V_311 |= 0x00c0 ;
break;
case 0x02 :
V_311 |= 0x0030 ;
break;
case 0x01 :
V_311 |= 0x000c ;
break;
case 0x00 :
V_311 |= 0x0003 ;
break;
default:
break;
}
F_21 ( 1 , L_70 , V_311 ) ;
F_136 ( V_5 , V_314 , V_311 ) ;
V_311 = V_294 -> V_285 & 0xfff8 ;
V_311 |= 0x0001 ;
F_21 ( 1 , L_71 , V_311 ) ;
F_136 ( V_5 , V_315 , V_311 ) ;
return F_131 ( V_294 ) ;
}
static void T_3 F_137 ( struct V_310 * V_5 ,
unsigned short V_316 )
{
unsigned char V_287 ;
unsigned char V_317 ;
unsigned char V_295 ;
switch( V_316 ) {
case 0x0130 :
case 0x0178 :
V_287 = 0xb0 ;
V_317 = 0x80 ;
break;
case 0x03f8 :
V_287 = 0xb4 ;
V_317 = 0x80 ;
break;
case 0x02f8 :
V_287 = 0xb4 ;
V_317 = 0x30 ;
break;
case 0x02e8 :
V_287 = 0xb4 ;
V_317 = 0x08 ;
break;
default:
F_15 ( L_72 , V_316 ) ;
return;
}
F_133 ( V_5 , V_287 , & V_295 ) ;
V_295 |= V_317 ;
F_134 ( V_5 , V_287 , V_295 ) ;
F_16 ( L_73 , V_316 ) ;
}
static int T_3 F_138 ( struct V_310 * V_5 ,
struct
V_293
* V_294 )
{
F_137 ( V_5 , V_294 -> V_286 ) ;
F_137 ( V_5 , V_294 -> V_285 ) ;
return F_131 ( V_294 ) ;
}
static int T_3 F_14 ( unsigned short V_15 ,
unsigned short V_16 ,
unsigned short V_17 ,
unsigned char V_18 ,
unsigned char V_19 )
{
struct V_310 * V_5 = NULL ;
unsigned short V_318 = 0x0000 ;
unsigned short V_319 = 0x0000 ;
int V_14 = 0 ;
F_139 (dev) {
struct V_293 * V_294 ;
if ( V_5 -> V_320 != 0x0000U ) {
V_318 = V_5 -> V_320 ;
V_319 = V_5 -> V_321 ;
}
V_294 = V_322 ;
for( ; V_294 -> V_323 ; V_294 ++ ) {
if( V_294 -> V_324 == V_5 -> V_324 &&
V_294 -> V_325 == V_5 -> V_325 &&
V_294 -> V_323 == V_318 &&
( V_294 -> V_326 == V_319 ||
V_294 -> V_326 == 0xffff ) ) {
struct V_293
V_327 ;
memcpy ( & V_327 , V_294 ,
sizeof( struct V_293 ) ) ;
if ( V_15 != 0 )
V_327 . V_260 = V_15 ;
if ( V_16 != 0 )
V_327 . V_285 = V_16 ;
if ( V_17 != 0 )
V_327 . V_286 = V_17 ;
if ( V_18 != V_26 )
V_327 . V_300 = V_18 ;
if ( V_19 != V_27 )
V_327 . V_299 = V_19 ;
F_16 ( L_74 , V_294 -> V_74 ) ;
if ( V_294 -> V_328 )
V_14 = V_294 -> V_328 ( V_5 , & V_327 ) ;
else
V_14 = - V_13 ;
}
}
}
return V_14 ;
}
static void F_140 ( int V_37 , T_6 V_36 )
{
unsigned long V_329 , V_330 ;
T_2 V_331 ;
V_329 = V_138 ;
V_330 = V_138 + V_332 ;
F_1 ( V_37 , 4 ) ;
F_2 ( ( F_3 ( V_37 + V_333 ) & V_334 ) | V_335 | V_336 ,
V_37 + V_333 ) ;
while ( ( V_331 = ( F_3 ( V_37 + V_333 ) & V_335 ) ) &&
! F_141 ( V_138 , V_330 ) )
;
if ( V_331 )
F_32 ( L_75 , V_21 ,
F_3 ( V_37 + V_333 ) ) ;
}
static int F_142 ( int V_37 )
{
return 0 ;
}
static void F_143 ( int V_37 , T_6 V_36 )
{
T_2 V_337 ;
switch ( V_36 ) {
default:
case 576000 :
V_337 = 0 ;
break;
case 1152000 :
case 4000000 :
V_337 = V_152 ;
break;
}
F_1 ( V_37 , 0 ) ;
F_2 ( ( F_3 ( V_37 + V_123 ) & 0xbf ) | V_337 , V_37 + V_123 ) ;
}
static int F_144 ( int V_37 )
{
return 0 ;
}
static void F_145 ( int V_37 , T_6 V_36 )
{
T_2 V_337 ;
switch ( V_36 ) {
default:
case 576000 :
V_337 = 0 ;
break;
case 1152000 :
case 4000000 :
V_337 = V_153 ;
break;
}
F_1 ( V_37 , 0 ) ;
F_2 ( ( F_3 ( V_37 + V_123 ) & 0xbf ) | V_337 , V_37 + V_123 ) ;
}
static int F_146 ( int V_37 )
{
return 0 ;
}

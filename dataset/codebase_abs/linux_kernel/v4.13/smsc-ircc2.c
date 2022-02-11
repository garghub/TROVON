static inline void F_1 ( int V_1 , int V_2 )
{
F_2 ( ( ( F_3 ( V_1 + V_3 ) & 0xf0 ) | ( V_2 & 0x07 ) ) ,
V_1 + V_3 ) ;
}
static int F_4 ( struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
unsigned int V_8 , V_9 ;
T_1 V_10 , V_11 ;
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
static int T_2 F_12 ( void )
{
int V_14 = 0 ;
#ifdef F_13
if ( F_14 ( V_15 , V_16 , V_17 , V_18 , V_19 ) < 0 ) {
F_15 ( L_1 ,
V_20 ) ;
}
#endif
if ( V_16 > 0 && V_17 > 0 ) {
F_16 ( L_2 ,
V_16 ) ;
F_16 ( L_3 ,
V_17 ) ;
if ( F_11 ( V_16 , V_17 , V_18 , V_19 ) )
V_14 = - V_13 ;
} else {
V_14 = - V_13 ;
if ( V_15 > 0 ) {
F_16 ( L_4 ,
V_15 ) ;
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
static int T_2 F_20 ( void )
{
int V_14 ;
F_21 ( L_5 , V_21 ) ;
V_14 = F_22 ( & V_22 ) ;
if ( V_14 ) {
F_15 ( L_6 ,
V_20 ) ;
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
static T_3 F_26 ( struct V_30 * V_31 ,
struct V_32 * V_5 )
{
struct V_33 * V_34 = F_27 ( V_5 ) ;
if ( V_34 -> V_35 . V_36 > 115200 )
return F_28 ( V_31 , V_5 ) ;
else
return F_29 ( V_31 , V_5 ) ;
}
static int F_11 ( unsigned int V_37 , unsigned int V_38 , T_1 V_10 , T_1 V_11 )
{
struct V_33 * V_34 ;
struct V_32 * V_5 ;
int V_39 ;
F_21 ( L_5 , V_21 ) ;
V_39 = F_30 ( V_37 , V_38 ) ;
if ( V_39 )
goto V_40;
V_39 = - V_41 ;
if ( V_23 >= F_31 ( V_42 ) ) {
F_32 ( L_7 , V_21 ) ;
goto V_43;
}
V_5 = F_33 ( sizeof( struct V_33 ) ) ;
if ( ! V_5 ) {
F_32 ( L_8 ,
V_21 ) ;
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
if ( V_34 -> V_52 . V_57 == NULL )
goto V_60;
V_34 -> V_55 . V_57 =
F_35 ( NULL , V_34 -> V_55 . V_53 ,
& V_34 -> V_61 , V_59 ) ;
if ( V_34 -> V_55 . V_57 == NULL )
goto V_62;
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
F_15 ( L_9 ,
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
F_16 ( L_10 , V_5 -> V_74 ) ;
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
F_32 ( L_11 ,
V_21 , V_37 ) ;
goto V_82;
}
if ( ! F_49 ( V_38 , V_76 ,
V_20 ) ) {
F_32 ( L_12 ,
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
F_32 ( L_13 ,
V_21 , V_37 ) ;
goto V_91;
}
F_16 ( L_14 ,
V_79 & 0x0f , V_81 ,
V_37 , V_38 , V_10 , V_11 ) ;
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
T_1 V_10 , T_1 V_11 )
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
F_16 ( L_15 ,
V_20 , V_93 , V_11 ) ;
V_34 -> V_35 . V_11 = V_11 ;
} else
V_34 -> V_35 . V_11 = V_93 ;
if ( V_10 != V_26 ) {
if ( V_10 != V_92 )
F_16 ( L_16 ,
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
F_21 ( L_17 , V_21 , V_5 -> V_74 , V_126 ) ;
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
F_32 ( L_18 ,
V_5 -> V_74 , V_34 -> V_35 . V_36 ) ;
F_57 ( & V_34 -> V_51 , V_128 ) ;
F_63 ( V_34 ) ;
F_58 ( V_34 , V_34 -> V_35 . V_36 ) ;
F_64 ( V_5 ) ;
F_65 ( V_5 ) ;
F_59 ( & V_34 -> V_51 , V_128 ) ;
}
static T_3 F_29 ( struct V_30 * V_31 ,
struct V_32 * V_5 )
{
struct V_33 * V_34 ;
unsigned long V_128 ;
T_4 V_36 ;
F_21 ( L_5 , V_21 ) ;
F_55 (dev != NULL, return NETDEV_TX_OK;) ;
V_34 = F_27 ( V_5 ) ;
F_55 (self != NULL, return NETDEV_TX_OK;) ;
F_66 ( V_5 ) ;
F_57 ( & V_34 -> V_51 , V_128 ) ;
V_36 = F_67 ( V_31 ) ;
if ( V_36 != V_34 -> V_35 . V_36 && V_36 != - 1 ) {
if ( ! V_31 -> V_137 ) {
F_68 ( V_34 ) ;
F_58 ( V_34 , V_36 ) ;
F_59 ( & V_34 -> V_51 , V_128 ) ;
F_69 ( V_31 ) ;
return V_138 ;
}
V_34 -> V_139 = V_36 ;
}
V_34 -> V_55 . V_66 = V_34 -> V_55 . V_57 ;
V_34 -> V_55 . V_137 = F_70 ( V_31 , V_34 -> V_55 . V_66 ,
V_34 -> V_55 . V_53 ) ;
V_5 -> V_140 . V_141 += V_34 -> V_55 . V_137 ;
F_2 ( V_142 , V_34 -> V_35 . V_38 + V_143 ) ;
F_59 ( & V_34 -> V_51 , V_128 ) ;
F_69 ( V_31 ) ;
return V_138 ;
}
static void F_71 ( struct V_33 * V_34 , T_5 V_36 )
{
int V_37 , V_144 , V_145 , V_146 ;
F_55 (self != NULL, return;) ;
V_37 = V_34 -> V_35 . V_37 ;
V_34 -> V_35 . V_36 = V_36 ;
switch ( V_36 ) {
default:
case 576000 :
V_144 = V_147 ;
V_145 = V_148 ;
V_146 = 0 ;
F_21 ( L_19 , V_21 ) ;
break;
case 1152000 :
V_144 = V_147 ;
V_145 = V_149 | V_148 ;
V_146 = V_150 | V_151 ;
F_21 ( L_20 ,
V_21 ) ;
break;
case 4000000 :
V_144 = V_152 ;
V_145 = V_148 ;
V_146 = V_150 ;
F_21 ( L_21 ,
V_21 ) ;
break;
}
#if 0
Now in tranceiver!
register_bank(fir_base, 0);
outb((inb(fir_base + IRCC_LCR_A) & 0xbf) | fast, fir_base + IRCC_LCR_A);
#endif
F_1 ( V_37 , 1 ) ;
F_2 ( ( ( F_3 ( V_37 + V_115 ) & V_153 ) | V_144 ) , V_37 + V_115 ) ;
F_1 ( V_37 , 4 ) ;
F_2 ( ( F_3 ( V_37 + V_122 ) & 0x30 ) | V_145 , V_37 + V_122 ) ;
}
static void F_72 ( struct V_33 * V_34 )
{
struct V_32 * V_5 ;
int V_37 ;
F_21 ( L_5 , V_21 ) ;
F_55 (self != NULL, return;) ;
V_5 = V_34 -> V_49 ;
F_55 (dev != NULL, return;) ;
V_37 = V_34 -> V_35 . V_37 ;
F_2 ( F_3 ( V_37 + V_123 ) | V_154 , V_37 + V_123 ) ;
F_1 ( V_37 , 1 ) ;
#ifdef F_73
F_2 ( ( ( F_3 ( V_37 + V_117 ) & 0x3f ) | V_118 ) ,
V_37 + V_117 ) ;
#else
F_2 ( ( ( F_3 ( V_37 + V_117 ) & 0x3f ) | V_119 ) ,
V_37 + V_117 ) ;
#endif
( void ) F_3 ( V_37 + V_120 ) ;
F_2 ( 0 , V_37 + V_3 ) ;
F_1 ( V_37 , 0 ) ;
F_2 ( V_155 | V_156 , V_37 + V_157 ) ;
F_2 ( V_158 , V_37 + V_3 ) ;
}
static void F_74 ( struct V_33 * V_34 )
{
int V_37 ;
F_21 ( L_5 , V_21 ) ;
F_55 (self != NULL, return;) ;
V_37 = V_34 -> V_35 . V_37 ;
F_1 ( V_37 , 0 ) ;
F_2 ( F_3 ( V_37 + V_159 ) & V_160 , V_37 + V_159 ) ;
}
static void F_58 ( struct V_33 * V_34 , T_5 V_36 )
{
struct V_32 * V_5 ;
int V_161 ;
F_21 ( L_22 , V_21 , V_36 ) ;
F_55 (self != NULL, return;) ;
V_5 = V_34 -> V_49 ;
V_161 = V_34 -> V_35 . V_36 <= V_162 ;
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
F_75 ( V_34 , V_36 ) ;
V_34 -> V_35 . V_36 = V_36 ;
if ( V_36 <= V_162 ) {
if ( ! V_161 ) {
F_74 ( V_34 ) ;
F_63 ( V_34 ) ;
}
F_53 ( V_34 , V_36 ) ;
} else {
if ( V_161 ) {
#if V_163
F_76 ( V_34 ) ;
#endif
F_72 ( V_34 ) ;
}
F_71 ( V_34 , V_36 ) ;
#if 0
self->tx_buff.len = 10;
self->tx_buff.data = self->tx_buff.head;
smsc_ircc_dma_xmit(self, 4000);
#endif
F_77 ( V_34 ) ;
}
F_65 ( V_5 ) ;
}
static void F_53 ( struct V_33 * V_34 , T_6 V_36 )
{
int V_1 ;
int V_164 ;
int V_165 ;
int V_166 ;
F_21 ( L_23 , V_21 , V_36 ) ;
F_55 (self != NULL, return;) ;
V_1 = V_34 -> V_35 . V_38 ;
V_34 -> V_35 . V_36 = V_36 ;
F_2 ( 0 , V_1 + V_143 ) ;
V_166 = V_162 / V_36 ;
V_164 = V_167 ;
V_164 |= V_34 -> V_35 . V_36 < 38400 ?
V_168 : V_169 ;
V_165 = V_170 ;
F_2 ( V_171 | V_165 , V_1 + V_172 ) ;
F_2 ( V_166 & 0xff , V_1 + V_173 ) ;
F_2 ( V_166 >> 8 , V_1 + V_174 ) ;
F_2 ( V_165 , V_1 + V_172 ) ;
F_2 ( V_164 , V_1 + V_175 ) ;
F_2 ( V_176 | V_177 | V_142 , V_1 + V_143 ) ;
F_21 ( L_24 , V_21 , V_36 ) ;
}
static T_3 F_28 ( struct V_30 * V_31 ,
struct V_32 * V_5 )
{
struct V_33 * V_34 ;
unsigned long V_128 ;
T_4 V_36 ;
int V_178 ;
F_55 (dev != NULL, return NETDEV_TX_OK;) ;
V_34 = F_27 ( V_5 ) ;
F_55 (self != NULL, return NETDEV_TX_OK;) ;
F_66 ( V_5 ) ;
F_57 ( & V_34 -> V_51 , V_128 ) ;
V_36 = F_67 ( V_31 ) ;
if ( V_36 != V_34 -> V_35 . V_36 && V_36 != - 1 ) {
if ( ! V_31 -> V_137 ) {
F_58 ( V_34 , V_36 ) ;
F_59 ( & V_34 -> V_51 , V_128 ) ;
F_69 ( V_31 ) ;
return V_138 ;
}
V_34 -> V_139 = V_36 ;
}
F_78 ( V_31 , V_34 -> V_55 . V_57 , V_31 -> V_137 ) ;
V_34 -> V_55 . V_137 = V_31 -> V_137 ;
V_34 -> V_55 . V_66 = V_34 -> V_55 . V_57 ;
V_178 = F_79 ( V_31 ) ;
if ( V_178 ) {
int V_179 ;
V_179 = V_178 * ( V_34 -> V_35 . V_36 / 1000 ) / 8000 ;
if ( V_179 > 4095 )
V_179 = 4095 ;
F_80 ( V_34 , V_179 ) ;
} else {
F_80 ( V_34 , 0 ) ;
}
F_59 ( & V_34 -> V_51 , V_128 ) ;
F_69 ( V_31 ) ;
return V_138 ;
}
static void F_80 ( struct V_33 * V_34 , int V_179 )
{
int V_1 = V_34 -> V_35 . V_37 ;
T_1 V_145 ;
F_21 ( L_5 , V_21 ) ;
#if 1
F_1 ( V_1 , 0 ) ;
F_2 ( 0x00 , V_1 + V_159 ) ;
#endif
F_1 ( V_1 , 1 ) ;
F_2 ( F_3 ( V_1 + V_117 ) & ~ V_180 ,
V_1 + V_117 ) ;
V_34 -> V_35 . V_181 = V_182 ;
F_1 ( V_1 , 4 ) ;
F_2 ( V_179 & 0xff , V_1 + V_183 ) ;
V_145 = F_3 ( V_1 + V_122 ) & 0xf0 ;
F_2 ( V_145 | ( ( V_179 >> 8 ) & 0x0f ) , V_1 + V_184 ) ;
F_2 ( V_34 -> V_55 . V_137 >> 8 , V_1 + V_185 ) ;
F_2 ( V_34 -> V_55 . V_137 & 0xff , V_1 + V_186 ) ;
F_1 ( V_1 , 1 ) ;
F_2 ( F_3 ( V_1 + V_117 ) | V_180 |
V_187 , V_1 + V_117 ) ;
F_81 ( V_34 -> V_35 . V_10 , V_34 -> V_61 , V_34 -> V_55 . V_137 ,
V_188 ) ;
F_1 ( V_1 , 0 ) ;
F_2 ( V_155 | V_156 , V_1 + V_157 ) ;
F_2 ( V_158 , V_1 + V_3 ) ;
F_2 ( V_189 | V_160 , V_1 + V_159 ) ;
}
static void F_82 ( struct V_33 * V_34 )
{
int V_1 = V_34 -> V_35 . V_37 ;
F_21 ( L_5 , V_21 ) ;
#if 0
register_bank(iobase, 0);
outb(0x00, iobase + IRCC_LCR_B);
#endif
F_1 ( V_1 , 1 ) ;
F_2 ( F_3 ( V_1 + V_117 ) & ~ V_180 ,
V_1 + V_117 ) ;
F_1 ( V_1 , 0 ) ;
if ( F_3 ( V_1 + V_190 ) & V_191 ) {
V_34 -> V_49 -> V_140 . V_192 ++ ;
V_34 -> V_49 -> V_140 . V_193 ++ ;
F_1 ( V_1 , 0 ) ;
F_2 ( V_194 , V_1 + V_3 ) ;
F_2 ( 0x00 , V_1 + V_3 ) ;
} else {
V_34 -> V_49 -> V_140 . V_195 ++ ;
V_34 -> V_49 -> V_140 . V_141 += V_34 -> V_55 . V_137 ;
}
if ( V_34 -> V_139 ) {
F_58 ( V_34 , V_34 -> V_139 ) ;
V_34 -> V_139 = 0 ;
}
F_65 ( V_34 -> V_49 ) ;
}
static int F_77 ( struct V_33 * V_34 )
{
int V_1 = V_34 -> V_35 . V_37 ;
#if 0
register_bank(iobase, 1);
outb(inb(iobase + IRCC_SCE_CFGB) & ~IRCC_CFGB_DMA_ENABLE,
iobase + IRCC_SCE_CFGB);
#endif
F_1 ( V_1 , 0 ) ;
F_2 ( 0x00 , V_1 + V_159 ) ;
F_1 ( V_1 , 1 ) ;
F_2 ( F_3 ( V_1 + V_117 ) & ~ V_180 ,
V_1 + V_117 ) ;
V_34 -> V_35 . V_181 = V_196 ;
V_34 -> V_52 . V_66 = V_34 -> V_52 . V_57 ;
F_1 ( V_1 , 4 ) ;
F_2 ( ( 2050 >> 8 ) & 0x0f , V_1 + V_197 ) ;
F_2 ( 2050 & 0xff , V_1 + V_198 ) ;
F_81 ( V_34 -> V_35 . V_10 , V_34 -> V_58 , V_34 -> V_52 . V_53 ,
V_199 ) ;
F_1 ( V_1 , 1 ) ;
F_2 ( F_3 ( V_1 + V_117 ) | V_180 |
V_187 , V_1 + V_117 ) ;
F_1 ( V_1 , 0 ) ;
F_2 ( V_155 | V_156 , V_1 + V_157 ) ;
F_2 ( V_158 , V_1 + V_3 ) ;
F_1 ( V_1 , 0 ) ;
F_2 ( V_200 | V_160 ,
V_1 + V_159 ) ;
return 0 ;
}
static void F_83 ( struct V_33 * V_34 )
{
struct V_30 * V_31 ;
int V_137 , V_201 , V_202 ;
int V_1 = V_34 -> V_35 . V_37 ;
F_1 ( V_1 , 0 ) ;
F_21 ( L_5 , V_21 ) ;
#if 0
register_bank(iobase, 0);
outb(0x00, iobase + IRCC_LCR_B);
#endif
F_1 ( V_1 , 0 ) ;
F_2 ( F_3 ( V_1 + V_203 ) & ~ V_204 , V_1 + V_203 ) ;
V_202 = F_3 ( V_1 + V_190 ) ;
V_201 = F_3 ( V_1 + V_159 ) & 0x08 ;
F_21 ( L_25 , V_21 ,
F_84 ( V_34 -> V_35 . V_10 ) ) ;
V_137 = V_34 -> V_52 . V_53 - F_84 ( V_34 -> V_35 . V_10 ) ;
if ( V_202 & ( V_205 | V_206 | V_207 ) ) {
V_34 -> V_49 -> V_140 . V_208 ++ ;
if ( V_202 & V_205 )
V_34 -> V_49 -> V_140 . V_209 ++ ;
if ( V_202 & V_206 )
V_34 -> V_49 -> V_140 . V_210 ++ ;
if ( V_202 & V_207 )
V_34 -> V_49 -> V_140 . V_211 ++ ;
if ( V_202 & ( V_191 | V_212 ) )
V_34 -> V_49 -> V_140 . V_211 ++ ;
return;
}
V_137 -= V_34 -> V_35 . V_36 < 4000000 ? 2 : 4 ;
if ( V_137 < 2 || V_137 > 2050 ) {
F_32 ( L_26 , V_21 , V_137 ) ;
return;
}
F_21 ( L_27 , V_21 , V_201 , V_137 ) ;
V_31 = F_85 ( V_137 + 1 ) ;
if ( ! V_31 )
return;
F_86 ( V_31 , 1 ) ;
F_87 ( V_31 , V_34 -> V_52 . V_66 , V_137 ) ;
V_34 -> V_49 -> V_140 . V_213 ++ ;
V_34 -> V_49 -> V_140 . V_214 += V_137 ;
V_31 -> V_5 = V_34 -> V_49 ;
F_88 ( V_31 ) ;
V_31 -> V_215 = F_89 ( V_216 ) ;
F_90 ( V_31 ) ;
}
static void F_91 ( struct V_33 * V_34 )
{
int V_217 = 0 ;
int V_1 ;
F_55 (self != NULL, return;) ;
V_1 = V_34 -> V_35 . V_38 ;
do {
F_92 ( V_34 -> V_49 , & V_34 -> V_49 -> V_140 , & V_34 -> V_52 ,
F_3 ( V_1 + V_218 ) ) ;
if ( V_217 ++ > 32 ) {
F_21 ( L_28 , V_21 ) ;
break;
}
} while ( F_3 ( V_1 + V_219 ) & V_220 );
}
static T_7 F_93 ( int V_221 , void * V_7 )
{
struct V_32 * V_5 = V_7 ;
struct V_33 * V_34 = F_27 ( V_5 ) ;
int V_1 , V_222 , V_223 , V_202 ;
T_7 V_14 = V_224 ;
F_94 ( & V_34 -> V_51 ) ;
if ( V_34 -> V_35 . V_36 <= V_162 ) {
V_14 = F_95 ( V_5 ) ;
goto V_225;
}
V_1 = V_34 -> V_35 . V_37 ;
F_1 ( V_1 , 0 ) ;
V_222 = F_3 ( V_1 + V_226 ) ;
if ( V_222 == 0 )
goto V_225;
V_14 = V_227 ;
F_2 ( 0 , V_1 + V_157 ) ;
V_223 = F_3 ( V_1 + V_123 ) ;
V_202 = F_3 ( V_1 + V_190 ) ;
F_21 ( L_29 , V_21 , V_222 ) ;
if ( V_222 & V_228 ) {
if ( V_34 -> V_35 . V_181 == V_196 )
F_83 ( V_34 ) ;
else
F_82 ( V_34 ) ;
F_77 ( V_34 ) ;
}
if ( V_222 & V_229 ) {
}
F_1 ( V_1 , 0 ) ;
F_2 ( V_155 | V_156 , V_1 + V_157 ) ;
V_225:
F_96 ( & V_34 -> V_51 ) ;
return V_14 ;
}
static T_7 F_95 ( struct V_32 * V_5 )
{
struct V_33 * V_34 = F_27 ( V_5 ) ;
int V_217 = 0 ;
int V_1 ;
int V_222 , V_202 ;
V_1 = V_34 -> V_35 . V_38 ;
V_222 = F_3 ( V_1 + V_230 ) & V_231 ;
if ( V_222 == 0 )
return V_224 ;
while ( V_222 ) {
V_202 = F_3 ( V_1 + V_219 ) ;
F_21 ( L_30 ,
V_21 , V_222 , V_202 , V_1 ) ;
switch ( V_222 ) {
case V_232 :
F_21 ( L_31 , V_21 ) ;
break;
case V_233 :
F_91 ( V_34 ) ;
break;
case V_234 :
if ( V_202 & V_235 )
F_97 ( V_34 ) ;
break;
default:
F_21 ( L_32 ,
V_21 , V_222 ) ;
break;
}
if ( V_217 ++ > 100 )
break;
V_222 = F_3 ( V_1 + V_230 ) & V_231 ;
}
return V_227 ;
}
static int F_98 ( struct V_33 * V_34 )
{
int error ;
error = F_99 ( V_34 -> V_35 . V_11 , F_93 , 0 ,
V_34 -> V_49 -> V_74 , V_34 -> V_49 ) ;
if ( error )
F_21 ( L_33 ,
V_21 , V_34 -> V_35 . V_11 , error ) ;
return error ;
}
static void F_100 ( struct V_33 * V_34 )
{
unsigned long V_128 ;
F_57 ( & V_34 -> V_51 , V_128 ) ;
V_34 -> V_35 . V_36 = 0 ;
F_58 ( V_34 , V_98 ) ;
F_59 ( & V_34 -> V_51 , V_128 ) ;
}
static void F_101 ( struct V_33 * V_34 )
{
int V_1 = V_34 -> V_35 . V_37 ;
unsigned long V_128 ;
F_57 ( & V_34 -> V_51 , V_128 ) ;
F_1 ( V_1 , 0 ) ;
F_2 ( 0 , V_1 + V_157 ) ;
F_2 ( V_114 , V_1 + V_3 ) ;
F_2 ( 0x00 , V_1 + V_3 ) ;
F_59 ( & V_34 -> V_51 , V_128 ) ;
}
static int F_102 ( struct V_32 * V_5 )
{
struct V_33 * V_34 ;
char V_236 [ 16 ] ;
F_21 ( L_5 , V_21 ) ;
F_55 (dev != NULL, return -1;) ;
V_34 = F_27 ( V_5 ) ;
F_55 (self != NULL, return 0;) ;
if ( V_34 -> V_35 . V_237 ) {
F_21 ( L_34 , V_21 ) ;
return - V_238 ;
}
if ( F_99 ( V_34 -> V_35 . V_11 , F_93 , 0 , V_5 -> V_74 ,
( void * ) V_5 ) ) {
F_21 ( L_35 ,
V_21 , V_34 -> V_35 . V_11 ) ;
return - V_238 ;
}
F_100 ( V_34 ) ;
sprintf ( V_236 , L_36 , V_34 -> V_35 . V_37 ) ;
V_34 -> V_239 = F_103 ( V_5 , & V_34 -> V_99 , V_236 ) ;
if ( F_104 ( V_34 -> V_35 . V_10 , V_5 -> V_74 ) ) {
F_105 ( V_5 ) ;
F_32 ( L_37 ,
V_21 , V_34 -> V_35 . V_10 ) ;
return - V_238 ;
}
F_106 ( V_5 ) ;
return 0 ;
}
static int F_105 ( struct V_32 * V_5 )
{
struct V_33 * V_34 ;
F_21 ( L_5 , V_21 ) ;
F_55 (dev != NULL, return -1;) ;
V_34 = F_27 ( V_5 ) ;
F_55 (self != NULL, return 0;) ;
F_66 ( V_5 ) ;
if ( V_34 -> V_239 )
F_107 ( V_34 -> V_239 ) ;
V_34 -> V_239 = NULL ;
F_101 ( V_34 ) ;
if ( ! V_34 -> V_35 . V_237 )
F_108 ( V_34 -> V_35 . V_11 , V_5 ) ;
F_109 ( V_34 -> V_35 . V_10 ) ;
F_110 ( V_34 -> V_35 . V_10 ) ;
return 0 ;
}
static int F_111 ( struct V_240 * V_5 , T_8 V_64 )
{
struct V_33 * V_34 = F_112 ( V_5 ) ;
if ( ! V_34 -> V_35 . V_237 ) {
F_21 ( L_38 , V_20 ) ;
F_113 () ;
if ( F_114 ( V_34 -> V_49 ) ) {
F_115 ( V_34 -> V_49 ) ;
F_101 ( V_34 ) ;
F_108 ( V_34 -> V_35 . V_11 , V_34 -> V_49 ) ;
F_109 ( V_34 -> V_35 . V_10 ) ;
}
V_34 -> V_35 . V_237 = 1 ;
F_116 () ;
}
return 0 ;
}
static int F_117 ( struct V_240 * V_5 )
{
struct V_33 * V_34 = F_112 ( V_5 ) ;
if ( V_34 -> V_35 . V_237 ) {
F_21 ( L_39 , V_20 ) ;
F_113 () ;
F_38 ( V_34 ) ;
if ( F_114 ( V_34 -> V_49 ) ) {
if ( F_98 ( V_34 ) ) {
F_118 ( V_34 -> V_49 ) ;
} else {
F_119 ( V_34 -> V_35 . V_10 ) ;
F_100 ( V_34 ) ;
F_120 ( V_34 -> V_49 ) ;
}
}
V_34 -> V_35 . V_237 = 0 ;
F_116 () ;
}
return 0 ;
}
static int T_9 F_121 ( struct V_33 * V_34 )
{
F_21 ( L_5 , V_21 ) ;
F_55 (self != NULL, return -1;) ;
F_122 ( V_34 -> V_71 ) ;
F_45 ( V_34 -> V_49 ) ;
F_101 ( V_34 ) ;
F_21 ( L_40 , V_21 ,
V_34 -> V_35 . V_37 ) ;
F_48 ( V_34 -> V_35 . V_37 , V_34 -> V_35 . V_94 ) ;
F_21 ( L_40 , V_21 ,
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
static void T_9 F_123 ( void )
{
int V_241 ;
F_21 ( L_5 , V_21 ) ;
for ( V_241 = 0 ; V_241 < 2 ; V_241 ++ ) {
if ( V_42 [ V_241 ] )
F_121 ( V_42 [ V_241 ] ) ;
}
if ( V_29 )
F_24 ( & V_28 ) ;
F_25 ( & V_22 ) ;
}
static void F_63 ( struct V_33 * V_34 )
{
struct V_32 * V_5 ;
int V_37 , V_38 ;
F_21 ( L_5 , V_21 ) ;
F_55 (self != NULL, return;) ;
V_5 = V_34 -> V_49 ;
F_55 (dev != NULL, return;) ;
V_37 = V_34 -> V_35 . V_37 ;
V_38 = V_34 -> V_35 . V_38 ;
F_2 ( V_114 , V_37 + V_3 ) ;
#if V_163
#endif
F_1 ( V_37 , 1 ) ;
F_2 ( ( ( F_3 ( V_37 + V_115 ) & V_153 ) | V_116 ) , V_37 + V_115 ) ;
F_2 ( V_170 , V_38 + V_172 ) ;
F_2 ( ( V_242 | V_243 | V_244 ) , V_38 + V_245 ) ;
F_2 ( V_176 | V_177 | V_142 , V_38 + V_143 ) ;
F_21 ( L_41 , V_21 ) ;
F_2 ( 0x00 , V_37 + V_3 ) ;
}
void F_76 ( struct V_33 * V_34 )
{
int V_1 ;
F_21 ( L_5 , V_21 ) ;
V_1 = V_34 -> V_35 . V_38 ;
F_2 ( 0 , V_1 + V_245 ) ;
F_2 ( 0 , V_1 + V_143 ) ;
}
static void F_97 ( struct V_33 * V_34 )
{
int V_246 = 0 ;
int V_1 ;
int V_164 ;
F_55 (self != NULL, return;) ;
F_21 ( L_5 , V_21 ) ;
V_1 = V_34 -> V_35 . V_38 ;
if ( V_34 -> V_55 . V_137 > 0 ) {
V_246 = F_124 ( V_1 , V_34 -> V_35 . V_96 ,
V_34 -> V_55 . V_66 , V_34 -> V_55 . V_137 ) ;
V_34 -> V_55 . V_66 += V_246 ;
V_34 -> V_55 . V_137 -= V_246 ;
} else {
if ( V_34 -> V_139 ) {
F_21 ( L_42 ,
V_21 , V_34 -> V_139 ) ;
F_68 ( V_34 ) ;
F_58 ( V_34 , V_34 -> V_139 ) ;
V_34 -> V_139 = 0 ;
} else {
F_65 ( V_34 -> V_49 ) ;
}
V_34 -> V_49 -> V_140 . V_195 ++ ;
if ( V_34 -> V_35 . V_36 <= 115200 ) {
V_164 = V_167 | V_247 ;
V_164 |= V_34 -> V_35 . V_36 < 38400 ?
V_168 : V_169 ;
F_2 ( V_164 , V_1 + V_175 ) ;
F_2 ( V_177 , V_1 + V_143 ) ;
}
}
}
static int F_124 ( int V_1 , int V_96 , T_10 * V_248 , int V_137 )
{
int V_246 = 0 ;
if ( ! ( F_3 ( V_1 + V_219 ) & V_235 ) ) {
F_32 ( L_43 ,
V_21 ) ;
return 0 ;
}
while ( V_96 -- > 0 && V_246 < V_137 ) {
F_2 ( V_248 [ V_246 ] , V_1 + V_249 ) ;
V_246 ++ ;
}
return V_246 ;
}
static int F_61 ( struct V_33 * V_34 )
{
return V_34 -> V_52 . V_64 != V_65 ;
}
static void F_39 ( struct V_33 * V_34 )
{
unsigned int V_241 ;
F_55 (self != NULL, return;) ;
for ( V_241 = 0 ; V_250 [ V_241 ] . V_74 != NULL ; V_241 ++ )
if ( V_250 [ V_241 ] . F_125 ( V_34 -> V_35 . V_37 ) ) {
F_16 ( L_44 ,
V_250 [ V_241 ] . V_74 ) ;
V_34 -> V_69 = V_241 + 1 ;
return;
}
F_16 ( L_45 ,
V_250 [ V_251 ] . V_74 ) ;
V_34 -> V_69 = V_251 ;
}
static void F_75 ( struct V_33 * V_34 , T_5 V_36 )
{
unsigned int V_252 ;
V_252 = V_34 -> V_69 ;
if ( V_252 > 0 )
V_250 [ V_252 - 1 ] . F_126 ( V_34 -> V_35 . V_37 , V_36 ) ;
}
static void F_68 ( struct V_33 * V_34 )
{
int V_1 = V_34 -> V_35 . V_38 ;
int V_253 = V_254 ;
while ( V_253 -- > 0 && ! ( F_3 ( V_1 + V_219 ) & V_255 ) )
F_127 ( 1 ) ;
if ( V_253 < 0 )
F_21 ( L_46 , V_21 ) ;
}
static int T_2 F_19 ( void )
{
struct V_256 * V_257 ;
char * type ;
unsigned int V_258 , V_259 ;
V_259 = 0 ;
V_257 = V_260 ;
while ( V_257 -> V_258 ) {
V_258 = V_257 -> V_258 ;
if ( V_257 -> type & V_261 ) {
type = L_47 ;
if ( V_257 -> type & V_262 )
if ( ! F_128 ( V_263 , V_258 , type ) )
V_259 ++ ;
if ( V_257 -> type & V_264 )
if ( ! F_129 ( V_265 , V_258 , type ) )
V_259 ++ ;
}
if ( V_257 -> type & V_266 ) {
type = L_48 ;
if ( V_257 -> type & V_262 )
if ( ! F_128 ( V_267 , V_258 , type ) )
V_259 ++ ;
if ( V_257 -> type & V_264 )
if ( ! F_129 ( V_268 , V_258 , type ) )
V_259 ++ ;
}
V_257 ++ ;
}
return V_259 ;
}
static int T_2 F_128 ( const struct V_269 * V_270 , unsigned short V_271 , char * type )
{
unsigned short V_8 , V_9 ;
T_1 V_272 , V_10 , V_11 ;
int V_14 = - V_13 ;
F_21 ( L_5 , V_21 ) ;
if ( F_130 ( V_271 , V_273 , V_270 , type ) == NULL )
return V_14 ;
F_2 ( V_274 , V_271 ) ;
V_272 = F_3 ( V_271 + 1 ) ;
if ( ! ( V_272 & V_275 ) )
F_32 ( L_49 , V_21 ) ;
F_2 ( V_276 , V_271 ) ;
V_9 = F_3 ( V_271 + 1 ) << 2 ;
F_2 ( V_277 , V_271 ) ;
V_8 = F_3 ( V_271 + 1 ) << 3 ;
F_2 ( V_278 , V_271 ) ;
V_10 = F_3 ( V_271 + 1 ) & V_279 ;
F_2 ( V_280 , V_271 ) ;
V_11 = F_3 ( V_271 + 1 ) & V_281 ;
F_16 ( L_50 ,
V_21 , V_8 , V_9 , V_10 , V_11 , V_272 ) ;
if ( V_8 && F_11 ( V_8 , V_9 , V_10 , V_11 ) == 0 )
V_14 = 0 ;
F_2 ( V_282 , V_271 ) ;
return V_14 ;
}
static int T_2 F_129 ( const struct V_269 * V_270 , unsigned short V_258 , char * type )
{
unsigned short V_283 , V_284 ;
int V_14 = - V_13 ;
F_21 ( L_5 , V_21 ) ;
if ( F_130 ( V_258 , 0x20 , V_270 , type ) == NULL )
return V_14 ;
F_2 ( 0x07 , V_258 ) ;
F_2 ( 0x05 , V_258 + 1 ) ;
F_2 ( 0x60 , V_258 ) ;
V_284 = F_3 ( V_258 + 1 ) << 8 ;
F_2 ( 0x61 , V_258 ) ;
V_284 |= F_3 ( V_258 + 1 ) ;
F_2 ( 0x62 , V_258 ) ;
V_283 = F_3 ( V_258 + 1 ) << 8 ;
F_2 ( 0x63 , V_258 ) ;
V_283 |= F_3 ( V_258 + 1 ) ;
F_2 ( 0x2b , V_258 ) ;
if ( V_283 && F_11 ( V_283 , V_284 , V_18 , V_19 ) == 0 )
V_14 = 0 ;
F_2 ( V_282 , V_258 ) ;
return V_14 ;
}
static int T_2 F_131 ( unsigned short V_258 , unsigned char V_285 )
{
F_21 ( L_5 , V_21 ) ;
F_2 ( V_285 , V_258 ) ;
return F_3 ( V_258 ) != V_285 ? - 1 : 0 ;
}
static const struct V_269 * T_2 F_130 ( unsigned short V_258 , T_1 V_285 , const struct V_269 * V_79 , char * type )
{
T_1 V_286 , V_287 , V_288 ;
F_21 ( L_5 , V_21 ) ;
F_2 ( V_282 , V_258 ) ;
if ( F_3 ( V_258 ) == V_282 )
return NULL ;
F_2 ( V_285 , V_258 ) ;
V_287 = F_3 ( V_258 + 1 ) ;
F_2 ( V_289 , V_258 ) ;
#if 0
if (smsc_access(cfg_base,0x55))
return NULL;
#endif
if ( F_131 ( V_258 , V_285 ) )
return NULL ;
V_286 = F_3 ( V_258 + 1 ) ;
if ( V_286 == 0 || V_286 == 0xff )
return NULL ;
if ( F_131 ( V_258 , V_285 + 1 ) )
return NULL ;
V_288 = F_3 ( V_258 + 1 ) ;
if ( V_288 >= 128 )
return NULL ;
if ( V_286 == V_287 )
return NULL ;
while ( V_79 -> V_286 != V_286 ) {
V_79 ++ ;
if ( V_79 -> V_74 == NULL )
return NULL ;
}
F_16 ( L_51 ,
V_286 , V_288 , V_258 , type , V_79 -> V_74 ) ;
if ( V_79 -> V_288 > V_288 ) {
F_16 ( L_52 ) ;
return NULL ;
}
if ( V_79 -> V_128 & V_290 )
F_16 ( L_53 ) ;
return V_79 ;
}
static int T_2 F_17 ( unsigned short V_258 )
{
int V_14 = - 1 ;
if ( ! F_49 ( V_258 , 2 , V_20 ) ) {
F_32 ( L_54 ,
V_21 , V_258 ) ;
} else {
if ( ! F_128 ( V_263 , V_258 , L_47 ) ||
! F_129 ( V_265 , V_258 , L_47 ) )
V_14 = 0 ;
F_48 ( V_258 , 2 ) ;
}
return V_14 ;
}
static int T_2 F_18 ( unsigned short V_258 )
{
int V_14 = - 1 ;
if ( ! F_49 ( V_258 , 2 , V_20 ) ) {
F_32 ( L_54 ,
V_21 , V_258 ) ;
} else {
if ( ! F_128 ( V_267 , V_258 , L_48 ) ||
! F_129 ( V_268 , V_258 , L_48 ) )
V_14 = 0 ;
F_48 ( V_258 , 2 ) ;
}
return V_14 ;
}
static int T_2 F_132 ( struct
V_291
* V_292 )
{
unsigned short V_1 = V_292 -> V_258 ;
unsigned char V_293 ;
F_2 ( V_294 , V_1 ) ;
F_2 ( V_273 , V_1 ) ;
V_293 = F_3 ( V_1 + 1 ) ;
F_21 ( L_55 ,
V_293 ) ;
F_2 ( 0x24 , V_1 ) ;
F_2 ( 0x00 , V_1 + 1 ) ;
F_2 ( V_276 , V_1 ) ;
F_2 ( ( V_292 -> V_284 >> 2 ) , V_1 + 1 ) ;
V_293 = F_3 ( V_1 + 1 ) ;
if ( V_293 != ( V_292 -> V_284 >> 2 ) ) {
F_32 ( L_56 ) ;
F_32 ( L_57 ) ;
return - V_295 ;
}
F_2 ( V_280 , V_1 ) ;
V_293 = F_3 ( V_1 + 1 ) ;
V_293 &= V_296 ;
V_293 |= ( V_292 -> V_297 & V_281 ) ;
F_2 ( V_293 , V_1 + 1 ) ;
V_293 = F_3 ( V_1 + 1 ) & V_281 ;
if ( V_293 != V_292 -> V_297 ) {
F_32 ( L_58 ) ;
return - V_295 ;
}
F_2 ( V_277 , V_1 ) ;
F_2 ( ( V_292 -> V_283 >> 3 ) , V_1 + 1 ) ;
V_293 = F_3 ( V_1 + 1 ) ;
if ( V_293 != ( V_292 -> V_283 >> 3 ) ) {
F_32 ( L_59 ) ;
return - V_295 ;
}
F_2 ( V_278 , V_1 ) ;
F_2 ( ( V_292 -> V_298 & V_299 ) , V_1 + 1 ) ;
V_293 = F_3 ( V_1 + 1 ) & V_299 ;
if ( V_293 != ( V_292 -> V_298 & V_299 ) ) {
F_32 ( L_60 ) ;
return - V_295 ;
}
F_2 ( V_274 , V_1 ) ;
V_293 = F_3 ( V_1 + 1 ) ;
V_293 &= ~ V_300 |
V_275 ;
F_2 ( V_293 , V_1 + 1 ) ;
F_2 ( V_301 , V_1 ) ;
V_293 = F_3 ( V_1 + 1 ) ;
F_2 ( V_293 | V_302 , V_1 + 1 ) ;
F_2 ( 0x0a , V_1 ) ;
V_293 = F_3 ( V_1 + 1 ) ;
F_2 ( V_293 | 0x40 , V_1 + 1 ) ;
F_2 ( V_303 , V_1 ) ;
V_293 = F_3 ( V_1 + 1 ) ;
F_2 ( V_293 | V_304 , V_1 + 1 ) ;
F_2 ( V_305 , V_1 ) ;
V_293 = F_3 ( V_1 + 1 ) ;
F_2 ( V_293 | V_306 , V_1 + 1 ) ;
F_2 ( V_307 , V_1 ) ;
return 0 ;
}
static int T_2 F_133 ( struct V_308 * V_5 ,
struct
V_291
* V_292 )
{
unsigned short V_309 ;
unsigned char V_293 ;
F_16 ( L_61 ) ;
F_134 ( V_5 , V_310 , & V_293 ) ;
V_293 &= 0xf8 ;
switch( V_292 -> V_284 ) {
case 0x3f8 :
V_293 |= 0x00 ;
break;
case 0x2f8 :
V_293 |= 0x01 ;
break;
case 0x220 :
V_293 |= 0x02 ;
break;
case 0x228 :
V_293 |= 0x03 ;
break;
case 0x238 :
V_293 |= 0x04 ;
break;
case 0x2e8 :
V_293 |= 0x05 ;
break;
case 0x338 :
V_293 |= 0x06 ;
break;
case 0x3e8 :
V_293 |= 0x07 ;
break;
default:
V_293 |= 0x01 ;
}
F_21 ( L_62 , V_293 ) ;
F_135 ( V_5 , V_310 , V_293 ) ;
F_136 ( V_5 , V_311 , & V_309 ) ;
switch( V_292 -> V_258 ) {
case 0x04e :
V_309 |= 0x2000 ;
break;
case 0x02e :
V_309 |= 0x1000 ;
break;
case 0x062 :
V_309 |= 0x0800 ;
break;
case 0x060 :
V_309 |= 0x0400 ;
break;
default:
F_32 ( L_63 ,
V_292 -> V_258 ) ;
break;
}
V_309 &= 0xfffd ;
V_309 |= 0x0001 ;
F_21 ( L_64 , V_309 ) ;
F_137 ( V_5 , V_311 , V_309 ) ;
F_136 ( V_5 , V_312 , & V_309 ) ;
switch( V_292 -> V_298 ) {
case 0x07 :
V_309 |= 0xc000 ;
break;
case 0x06 :
V_309 |= 0x3000 ;
break;
case 0x05 :
V_309 |= 0x0c00 ;
break;
case 0x03 :
V_309 |= 0x00c0 ;
break;
case 0x02 :
V_309 |= 0x0030 ;
break;
case 0x01 :
V_309 |= 0x000c ;
break;
case 0x00 :
V_309 |= 0x0003 ;
break;
default:
break;
}
F_21 ( L_65 , V_309 ) ;
F_137 ( V_5 , V_312 , V_309 ) ;
V_309 = V_292 -> V_283 & 0xfff8 ;
V_309 |= 0x0001 ;
F_21 ( L_66 , V_309 ) ;
F_137 ( V_5 , V_313 , V_309 ) ;
return F_132 ( V_292 ) ;
}
static void T_2 F_138 ( struct V_308 * V_5 ,
unsigned short V_314 )
{
unsigned char V_285 ;
unsigned char V_315 ;
unsigned char V_293 ;
switch( V_314 ) {
case 0x0130 :
case 0x0178 :
V_285 = 0xb0 ;
V_315 = 0x80 ;
break;
case 0x03f8 :
V_285 = 0xb4 ;
V_315 = 0x80 ;
break;
case 0x02f8 :
V_285 = 0xb4 ;
V_315 = 0x30 ;
break;
case 0x02e8 :
V_285 = 0xb4 ;
V_315 = 0x08 ;
break;
default:
F_15 ( L_67 ,
V_314 ) ;
return;
}
F_134 ( V_5 , V_285 , & V_293 ) ;
V_293 |= V_315 ;
F_135 ( V_5 , V_285 , V_293 ) ;
F_16 ( L_68 ,
V_314 ) ;
}
static int T_2 F_139 ( struct V_308 * V_5 ,
struct
V_291
* V_292 )
{
F_138 ( V_5 , V_292 -> V_284 ) ;
F_138 ( V_5 , V_292 -> V_283 ) ;
return F_132 ( V_292 ) ;
}
static int T_2 F_14 ( unsigned short V_15 ,
unsigned short V_16 ,
unsigned short V_17 ,
unsigned char V_18 ,
unsigned char V_19 )
{
struct V_308 * V_5 = NULL ;
unsigned short V_316 = 0x0000 ;
unsigned short V_317 = 0x0000 ;
int V_14 = 0 ;
F_140 (dev) {
struct V_291 * V_292 ;
if ( V_5 -> V_318 != 0x0000U ) {
V_316 = V_5 -> V_318 ;
V_317 = V_5 -> V_319 ;
}
V_292 = V_320 ;
for( ; V_292 -> V_321 ; V_292 ++ ) {
if( V_292 -> V_322 == V_5 -> V_322 &&
V_292 -> V_323 == V_5 -> V_323 &&
V_292 -> V_321 == V_316 &&
( V_292 -> V_324 == V_317 ||
V_292 -> V_324 == 0xffff ) ) {
struct V_291
V_325 ;
memcpy ( & V_325 , V_292 ,
sizeof( struct V_291 ) ) ;
if ( V_15 != 0 )
V_325 . V_258 = V_15 ;
if ( V_16 != 0 )
V_325 . V_283 = V_16 ;
if ( V_17 != 0 )
V_325 . V_284 = V_17 ;
if ( V_18 != V_26 )
V_325 . V_298 = V_18 ;
if ( V_19 != V_27 )
V_325 . V_297 = V_19 ;
F_16 ( L_69 ,
V_292 -> V_74 ) ;
if ( V_292 -> V_326 )
V_14 = V_292 -> V_326 ( V_5 , & V_325 ) ;
else
V_14 = - V_13 ;
}
}
}
return V_14 ;
}
static void F_141 ( int V_37 , T_5 V_36 )
{
unsigned long V_327 , V_328 ;
T_1 V_329 ;
V_327 = V_330 ;
V_328 = V_330 + V_331 ;
F_1 ( V_37 , 4 ) ;
F_2 ( ( F_3 ( V_37 + V_332 ) & V_333 ) | V_334 | V_335 ,
V_37 + V_332 ) ;
while ( ( V_329 = ( F_3 ( V_37 + V_332 ) & V_334 ) ) &&
! F_142 ( V_330 , V_328 ) )
;
if ( V_329 )
F_32 ( L_70 ,
V_21 , F_3 ( V_37 + V_332 ) ) ;
}
static int F_143 ( int V_37 )
{
return 0 ;
}
static void F_144 ( int V_37 , T_5 V_36 )
{
T_1 V_336 ;
switch ( V_36 ) {
default:
case 576000 :
V_336 = 0 ;
break;
case 1152000 :
case 4000000 :
V_336 = V_150 ;
break;
}
F_1 ( V_37 , 0 ) ;
F_2 ( ( F_3 ( V_37 + V_123 ) & 0xbf ) | V_336 , V_37 + V_123 ) ;
}
static int F_145 ( int V_37 )
{
return 0 ;
}
static void F_146 ( int V_37 , T_5 V_36 )
{
T_1 V_336 ;
switch ( V_36 ) {
default:
case 576000 :
V_336 = 0 ;
break;
case 1152000 :
case 4000000 :
V_336 = V_151 ;
break;
}
F_1 ( V_37 , 0 ) ;
F_2 ( ( F_3 ( V_37 + V_123 ) & 0xbf ) | V_336 , V_37 + V_123 ) ;
}
static int F_147 ( int V_37 )
{
return 0 ;
}

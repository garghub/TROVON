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
static int T_2 F_20 ( void )
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
& V_34 -> V_58 , V_59 | V_60 ) ;
if ( V_34 -> V_52 . V_57 == NULL )
goto V_61;
V_34 -> V_55 . V_57 =
F_35 ( NULL , V_34 -> V_55 . V_53 ,
& V_34 -> V_62 , V_59 | V_60 ) ;
if ( V_34 -> V_55 . V_57 == NULL )
goto V_63;
V_34 -> V_52 . V_64 = FALSE ;
V_34 -> V_52 . V_65 = V_66 ;
V_34 -> V_55 . V_67 = V_34 -> V_55 . V_57 ;
V_34 -> V_52 . V_67 = V_34 -> V_52 . V_57 ;
F_36 ( V_34 , V_37 , V_38 , V_10 , V_11 ) ;
F_37 ( V_34 ) ;
F_38 ( V_34 ) ;
if ( V_68 > 0 &&
V_68 < V_69 )
V_34 -> V_70 = V_68 ;
else
F_39 ( V_34 ) ;
V_39 = F_40 ( V_34 -> V_49 ) ;
if ( V_39 ) {
F_15 ( L_10 ,
V_20 ) ;
goto V_71;
}
V_34 -> V_72 = F_41 ( V_73 ,
V_23 , NULL , 0 ) ;
if ( F_42 ( V_34 -> V_72 ) ) {
V_39 = F_43 ( V_34 -> V_72 ) ;
goto V_74;
}
F_44 ( V_34 -> V_72 , V_34 ) ;
F_16 ( L_11 , V_5 -> V_75 ) ;
V_23 ++ ;
return 0 ;
V_74:
F_45 ( V_34 -> V_49 ) ;
V_71:
F_46 ( NULL , V_34 -> V_55 . V_53 ,
V_34 -> V_55 . V_57 , V_34 -> V_62 ) ;
V_63:
F_46 ( NULL , V_34 -> V_52 . V_53 ,
V_34 -> V_52 . V_57 , V_34 -> V_58 ) ;
V_61:
F_47 ( V_34 -> V_49 ) ;
V_42 [ V_23 ] = NULL ;
V_43:
F_48 ( V_37 , V_76 ) ;
F_48 ( V_38 , V_77 ) ;
V_40:
return V_39 ;
}
static int F_30 ( unsigned int V_37 , unsigned int V_38 )
{
unsigned char V_78 , V_79 , V_80 , V_81 , V_10 , V_11 , V_82 ;
if ( ! F_49 ( V_37 , V_76 ,
V_20 ) ) {
F_32 ( L_12 ,
V_21 , V_37 ) ;
goto V_83;
}
if ( ! F_49 ( V_38 , V_77 ,
V_20 ) ) {
F_32 ( L_13 ,
V_21 , V_38 ) ;
goto V_84;
}
F_1 ( V_37 , 3 ) ;
V_79 = F_3 ( V_37 + V_85 ) ;
V_78 = F_3 ( V_37 + V_86 ) ;
V_80 = F_3 ( V_37 + V_87 ) ;
V_82 = F_3 ( V_37 + V_88 ) ;
V_81 = F_3 ( V_37 + V_89 ) ;
V_10 = V_81 & V_90 ;
V_11 = ( V_81 & V_91 ) >> 4 ;
if ( V_79 != 0x10 || V_78 != 0xb8 || ( V_80 != 0xf1 && V_80 != 0xf2 ) ) {
F_32 ( L_14 ,
V_21 , V_37 ) ;
goto V_92;
}
F_16 ( L_15
L_16 ,
V_80 & 0x0f , V_82 , V_37 , V_38 , V_10 , V_11 ) ;
return 0 ;
V_92:
F_48 ( V_38 , V_77 ) ;
V_84:
F_48 ( V_37 , V_76 ) ;
V_83:
return - V_13 ;
}
static void F_36 ( struct V_33 * V_34 ,
unsigned int V_37 , unsigned int V_38 ,
T_1 V_10 , T_1 V_11 )
{
unsigned char V_81 , V_93 , V_94 ;
F_1 ( V_37 , 3 ) ;
V_81 = F_3 ( V_37 + V_89 ) ;
V_93 = V_81 & V_90 ;
V_94 = ( V_81 & V_91 ) >> 4 ;
V_34 -> V_35 . V_37 = V_37 ;
V_34 -> V_35 . V_38 = V_38 ;
V_34 -> V_35 . V_95 = V_76 ;
V_34 -> V_35 . V_96 = V_77 ;
V_34 -> V_35 . V_97 = V_98 ;
V_34 -> V_35 . V_36 = V_99 ;
if ( V_11 != V_27 ) {
if ( V_11 != V_94 )
F_16 ( L_17 ,
V_20 , V_94 , V_11 ) ;
V_34 -> V_35 . V_11 = V_11 ;
} else
V_34 -> V_35 . V_11 = V_94 ;
if ( V_10 != V_26 ) {
if ( V_10 != V_93 )
F_16 ( L_18 ,
V_20 , V_93 , V_10 ) ;
V_34 -> V_35 . V_10 = V_10 ;
} else
V_34 -> V_35 . V_10 = V_93 ;
}
static void F_37 ( struct V_33 * V_34 )
{
F_50 ( & V_34 -> V_100 ) ;
V_34 -> V_100 . V_101 . V_102 = V_103 | V_104 | V_105 | V_106 |
V_107 | V_108 | V_109 | ( V_110 << 8 ) ;
V_34 -> V_100 . V_111 . V_102 = V_112 ;
V_34 -> V_100 . V_113 . V_102 = V_114 ;
F_51 ( & V_34 -> V_100 ) ;
}
static void F_38 ( struct V_33 * V_34 )
{
int V_1 = V_34 -> V_35 . V_37 ;
F_1 ( V_1 , 0 ) ;
F_2 ( V_115 , V_1 + V_3 ) ;
F_2 ( 0x00 , V_1 + V_3 ) ;
F_1 ( V_1 , 1 ) ;
F_2 ( ( ( F_3 ( V_1 + V_116 ) & 0x87 ) | V_117 ) ,
V_1 + V_116 ) ;
#ifdef F_52
F_2 ( ( ( F_3 ( V_1 + V_118 ) & 0x3f ) | V_119 ) ,
V_1 + V_118 ) ;
#else
F_2 ( ( ( F_3 ( V_1 + V_118 ) & 0x3f ) | V_120 ) ,
V_1 + V_118 ) ;
#endif
( void ) F_3 ( V_1 + V_121 ) ;
F_2 ( V_122 , V_1 + V_121 ) ;
F_1 ( V_1 , 4 ) ;
F_2 ( ( F_3 ( V_1 + V_123 ) & 0x30 ) , V_1 + V_123 ) ;
F_1 ( V_1 , 0 ) ;
F_2 ( 0 , V_1 + V_124 ) ;
F_53 ( V_34 , V_99 ) ;
F_2 ( 0x00 , V_1 + V_3 ) ;
}
static int F_54 ( struct V_32 * V_5 , struct V_125 * V_126 , int V_127 )
{
struct V_128 * V_11 = (struct V_128 * ) V_126 ;
struct V_33 * V_34 ;
unsigned long V_129 ;
int V_14 = 0 ;
F_55 (dev != NULL, return -1;) ;
V_34 = F_27 ( V_5 ) ;
F_55 (self != NULL, return -1;) ;
F_21 ( 2 , L_19 , V_21 , V_5 -> V_75 , V_127 ) ;
switch ( V_127 ) {
case V_130 :
if ( ! F_56 ( V_131 ) )
V_14 = - V_132 ;
else {
F_57 ( & V_34 -> V_51 , V_129 ) ;
F_58 ( V_34 , V_11 -> V_133 ) ;
F_59 ( & V_34 -> V_51 , V_129 ) ;
}
break;
case V_134 :
if ( ! F_56 ( V_131 ) ) {
V_14 = - V_132 ;
break;
}
F_60 ( V_34 -> V_49 , TRUE ) ;
break;
case V_135 :
V_11 -> V_136 = F_61 ( V_34 ) ;
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
V_14 = - V_137 ;
}
return V_14 ;
}
static void F_62 ( struct V_32 * V_5 )
{
struct V_33 * V_34 = F_27 ( V_5 ) ;
unsigned long V_129 ;
F_32 ( L_20 ,
V_5 -> V_75 , V_34 -> V_35 . V_36 ) ;
F_57 ( & V_34 -> V_51 , V_129 ) ;
F_63 ( V_34 ) ;
F_58 ( V_34 , V_34 -> V_35 . V_36 ) ;
V_5 -> V_138 = V_139 ;
F_64 ( V_5 ) ;
F_59 ( & V_34 -> V_51 , V_129 ) ;
}
static T_3 F_29 ( struct V_30 * V_31 ,
struct V_32 * V_5 )
{
struct V_33 * V_34 ;
unsigned long V_129 ;
T_4 V_36 ;
F_21 ( 1 , L_6 , V_21 ) ;
F_55 (dev != NULL, return NETDEV_TX_OK;) ;
V_34 = F_27 ( V_5 ) ;
F_55 (self != NULL, return NETDEV_TX_OK;) ;
F_65 ( V_5 ) ;
F_57 ( & V_34 -> V_51 , V_129 ) ;
V_36 = F_66 ( V_31 ) ;
if ( V_36 != V_34 -> V_35 . V_36 && V_36 != - 1 ) {
if ( ! V_31 -> V_140 ) {
F_67 ( V_34 ) ;
F_58 ( V_34 , V_36 ) ;
F_59 ( & V_34 -> V_51 , V_129 ) ;
F_68 ( V_31 ) ;
return V_141 ;
}
V_34 -> V_142 = V_36 ;
}
V_34 -> V_55 . V_67 = V_34 -> V_55 . V_57 ;
V_34 -> V_55 . V_140 = F_69 ( V_31 , V_34 -> V_55 . V_67 ,
V_34 -> V_55 . V_53 ) ;
V_5 -> V_143 . V_144 += V_34 -> V_55 . V_140 ;
F_2 ( V_145 , V_34 -> V_35 . V_38 + V_146 ) ;
F_59 ( & V_34 -> V_51 , V_129 ) ;
F_68 ( V_31 ) ;
return V_141 ;
}
static void F_70 ( struct V_33 * V_34 , T_5 V_36 )
{
int V_37 , V_147 , V_148 , V_149 ;
F_55 (self != NULL, return;) ;
V_37 = V_34 -> V_35 . V_37 ;
V_34 -> V_35 . V_36 = V_36 ;
switch ( V_36 ) {
default:
case 576000 :
V_147 = V_150 ;
V_148 = V_151 ;
V_149 = 0 ;
F_21 ( 0 , L_21 , V_21 ) ;
break;
case 1152000 :
V_147 = V_150 ;
V_148 = V_152 | V_151 ;
V_149 = V_153 | V_154 ;
F_21 ( 0 , L_22 ,
V_21 ) ;
break;
case 4000000 :
V_147 = V_155 ;
V_148 = V_151 ;
V_149 = V_153 ;
F_21 ( 0 , L_23 ,
V_21 ) ;
break;
}
#if 0
Now in tranceiver!
register_bank(fir_base, 0);
outb((inb(fir_base + IRCC_LCR_A) & 0xbf) | fast, fir_base + IRCC_LCR_A);
#endif
F_1 ( V_37 , 1 ) ;
F_2 ( ( ( F_3 ( V_37 + V_116 ) & V_156 ) | V_147 ) , V_37 + V_116 ) ;
F_1 ( V_37 , 4 ) ;
F_2 ( ( F_3 ( V_37 + V_123 ) & 0x30 ) | V_148 , V_37 + V_123 ) ;
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
F_2 ( F_3 ( V_37 + V_124 ) | V_157 , V_37 + V_124 ) ;
F_1 ( V_37 , 1 ) ;
#ifdef F_72
F_2 ( ( ( F_3 ( V_37 + V_118 ) & 0x3f ) | V_119 ) ,
V_37 + V_118 ) ;
#else
F_2 ( ( ( F_3 ( V_37 + V_118 ) & 0x3f ) | V_120 ) ,
V_37 + V_118 ) ;
#endif
( void ) F_3 ( V_37 + V_121 ) ;
F_2 ( 0 , V_37 + V_3 ) ;
F_1 ( V_37 , 0 ) ;
F_2 ( V_158 | V_159 , V_37 + V_160 ) ;
F_2 ( V_161 , V_37 + V_3 ) ;
}
static void F_73 ( struct V_33 * V_34 )
{
int V_37 ;
F_21 ( 1 , L_6 , V_21 ) ;
F_55 (self != NULL, return;) ;
V_37 = V_34 -> V_35 . V_37 ;
F_1 ( V_37 , 0 ) ;
F_2 ( F_3 ( V_37 + V_162 ) & V_163 , V_37 + V_162 ) ;
}
static void F_58 ( struct V_33 * V_34 , T_5 V_36 )
{
struct V_32 * V_5 ;
int V_164 ;
F_21 ( 0 , L_24 , V_21 , V_36 ) ;
F_55 (self != NULL, return;) ;
V_5 = V_34 -> V_49 ;
V_164 = V_34 -> V_35 . V_36 <= V_165 ;
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
if ( V_36 <= V_165 ) {
if ( ! V_164 ) {
F_73 ( V_34 ) ;
F_63 ( V_34 ) ;
}
F_53 ( V_34 , V_36 ) ;
} else {
if ( V_164 ) {
#if V_166
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
static void F_53 ( struct V_33 * V_34 , T_6 V_36 )
{
int V_1 ;
int V_167 ;
int V_168 ;
int V_169 ;
F_21 ( 0 , L_25 , V_21 , V_36 ) ;
F_55 (self != NULL, return;) ;
V_1 = V_34 -> V_35 . V_38 ;
V_34 -> V_35 . V_36 = V_36 ;
F_2 ( 0 , V_1 + V_146 ) ;
V_169 = V_165 / V_36 ;
V_167 = V_170 ;
V_167 |= V_34 -> V_35 . V_36 < 38400 ?
V_171 : V_172 ;
V_168 = V_173 ;
F_2 ( V_174 | V_168 , V_1 + V_175 ) ;
F_2 ( V_169 & 0xff , V_1 + V_176 ) ;
F_2 ( V_169 >> 8 , V_1 + V_177 ) ;
F_2 ( V_168 , V_1 + V_175 ) ;
F_2 ( V_167 , V_1 + V_178 ) ;
F_2 ( V_179 | V_180 | V_145 , V_1 + V_146 ) ;
F_21 ( 2 , L_26 , V_21 , V_36 ) ;
}
static T_3 F_28 ( struct V_30 * V_31 ,
struct V_32 * V_5 )
{
struct V_33 * V_34 ;
unsigned long V_129 ;
T_4 V_36 ;
int V_181 ;
F_55 (dev != NULL, return NETDEV_TX_OK;) ;
V_34 = F_27 ( V_5 ) ;
F_55 (self != NULL, return NETDEV_TX_OK;) ;
F_65 ( V_5 ) ;
F_57 ( & V_34 -> V_51 , V_129 ) ;
V_36 = F_66 ( V_31 ) ;
if ( V_36 != V_34 -> V_35 . V_36 && V_36 != - 1 ) {
if ( ! V_31 -> V_140 ) {
F_58 ( V_34 , V_36 ) ;
F_59 ( & V_34 -> V_51 , V_129 ) ;
F_68 ( V_31 ) ;
return V_141 ;
}
V_34 -> V_142 = V_36 ;
}
F_77 ( V_31 , V_34 -> V_55 . V_57 , V_31 -> V_140 ) ;
V_34 -> V_55 . V_140 = V_31 -> V_140 ;
V_34 -> V_55 . V_67 = V_34 -> V_55 . V_57 ;
V_181 = F_78 ( V_31 ) ;
if ( V_181 ) {
int V_182 ;
V_182 = V_181 * ( V_34 -> V_35 . V_36 / 1000 ) / 8000 ;
if ( V_182 > 4095 )
V_182 = 4095 ;
F_79 ( V_34 , V_182 ) ;
} else {
F_79 ( V_34 , 0 ) ;
}
F_59 ( & V_34 -> V_51 , V_129 ) ;
F_68 ( V_31 ) ;
return V_141 ;
}
static void F_79 ( struct V_33 * V_34 , int V_182 )
{
int V_1 = V_34 -> V_35 . V_37 ;
T_1 V_148 ;
F_21 ( 3 , L_6 , V_21 ) ;
#if 1
F_1 ( V_1 , 0 ) ;
F_2 ( 0x00 , V_1 + V_162 ) ;
#endif
F_1 ( V_1 , 1 ) ;
F_2 ( F_3 ( V_1 + V_118 ) & ~ V_183 ,
V_1 + V_118 ) ;
V_34 -> V_35 . V_184 = V_185 ;
F_1 ( V_1 , 4 ) ;
F_2 ( V_182 & 0xff , V_1 + V_186 ) ;
V_148 = F_3 ( V_1 + V_123 ) & 0xf0 ;
F_2 ( V_148 | ( ( V_182 >> 8 ) & 0x0f ) , V_1 + V_187 ) ;
F_2 ( V_34 -> V_55 . V_140 >> 8 , V_1 + V_188 ) ;
F_2 ( V_34 -> V_55 . V_140 & 0xff , V_1 + V_189 ) ;
F_1 ( V_1 , 1 ) ;
F_2 ( F_3 ( V_1 + V_118 ) | V_183 |
V_190 , V_1 + V_118 ) ;
F_80 ( V_34 -> V_35 . V_10 , V_34 -> V_62 , V_34 -> V_55 . V_140 ,
V_191 ) ;
F_1 ( V_1 , 0 ) ;
F_2 ( V_158 | V_159 , V_1 + V_160 ) ;
F_2 ( V_161 , V_1 + V_3 ) ;
F_2 ( V_192 | V_163 , V_1 + V_162 ) ;
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
F_2 ( F_3 ( V_1 + V_118 ) & ~ V_183 ,
V_1 + V_118 ) ;
F_1 ( V_1 , 0 ) ;
if ( F_3 ( V_1 + V_193 ) & V_194 ) {
V_34 -> V_49 -> V_143 . V_195 ++ ;
V_34 -> V_49 -> V_143 . V_196 ++ ;
F_1 ( V_1 , 0 ) ;
F_2 ( V_197 , V_1 + V_3 ) ;
F_2 ( 0x00 , V_1 + V_3 ) ;
} else {
V_34 -> V_49 -> V_143 . V_198 ++ ;
V_34 -> V_49 -> V_143 . V_144 += V_34 -> V_55 . V_140 ;
}
if ( V_34 -> V_142 ) {
F_58 ( V_34 , V_34 -> V_142 ) ;
V_34 -> V_142 = 0 ;
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
F_2 ( 0x00 , V_1 + V_162 ) ;
F_1 ( V_1 , 1 ) ;
F_2 ( F_3 ( V_1 + V_118 ) & ~ V_183 ,
V_1 + V_118 ) ;
V_34 -> V_35 . V_184 = V_199 ;
V_34 -> V_52 . V_67 = V_34 -> V_52 . V_57 ;
F_1 ( V_1 , 4 ) ;
F_2 ( ( 2050 >> 8 ) & 0x0f , V_1 + V_200 ) ;
F_2 ( 2050 & 0xff , V_1 + V_201 ) ;
F_80 ( V_34 -> V_35 . V_10 , V_34 -> V_58 , V_34 -> V_52 . V_53 ,
V_202 ) ;
F_1 ( V_1 , 1 ) ;
F_2 ( F_3 ( V_1 + V_118 ) | V_183 |
V_190 , V_1 + V_118 ) ;
F_1 ( V_1 , 0 ) ;
F_2 ( V_158 | V_159 , V_1 + V_160 ) ;
F_2 ( V_161 , V_1 + V_3 ) ;
F_1 ( V_1 , 0 ) ;
F_2 ( V_203 | V_163 ,
V_1 + V_162 ) ;
return 0 ;
}
static void F_82 ( struct V_33 * V_34 )
{
struct V_30 * V_31 ;
int V_140 , V_204 , V_205 ;
int V_1 = V_34 -> V_35 . V_37 ;
F_1 ( V_1 , 0 ) ;
F_21 ( 3 , L_6 , V_21 ) ;
#if 0
register_bank(iobase, 0);
outb(0x00, iobase + IRCC_LCR_B);
#endif
F_1 ( V_1 , 0 ) ;
F_2 ( F_3 ( V_1 + V_206 ) & ~ V_207 , V_1 + V_206 ) ;
V_205 = F_3 ( V_1 + V_193 ) ;
V_204 = F_3 ( V_1 + V_162 ) & 0x08 ;
F_21 ( 2 , L_27 , V_21 ,
F_83 ( V_34 -> V_35 . V_10 ) ) ;
V_140 = V_34 -> V_52 . V_53 - F_83 ( V_34 -> V_35 . V_10 ) ;
if ( V_205 & ( V_208 | V_209 | V_210 ) ) {
V_34 -> V_49 -> V_143 . V_211 ++ ;
if ( V_205 & V_208 )
V_34 -> V_49 -> V_143 . V_212 ++ ;
if ( V_205 & V_209 )
V_34 -> V_49 -> V_143 . V_213 ++ ;
if ( V_205 & V_210 )
V_34 -> V_49 -> V_143 . V_214 ++ ;
if ( V_205 & ( V_194 | V_215 ) )
V_34 -> V_49 -> V_143 . V_214 ++ ;
return;
}
V_140 -= V_34 -> V_35 . V_36 < 4000000 ? 2 : 4 ;
if ( V_140 < 2 || V_140 > 2050 ) {
F_32 ( L_28 , V_21 , V_140 ) ;
return;
}
F_21 ( 2 , L_29 , V_21 , V_204 , V_140 ) ;
V_31 = F_84 ( V_140 + 1 ) ;
if ( ! V_31 ) {
F_32 ( L_30 ,
V_21 ) ;
return;
}
F_85 ( V_31 , 1 ) ;
memcpy ( F_86 ( V_31 , V_140 ) , V_34 -> V_52 . V_67 , V_140 ) ;
V_34 -> V_49 -> V_143 . V_216 ++ ;
V_34 -> V_49 -> V_143 . V_217 += V_140 ;
V_31 -> V_5 = V_34 -> V_49 ;
F_87 ( V_31 ) ;
V_31 -> V_218 = F_88 ( V_219 ) ;
F_89 ( V_31 ) ;
}
static void F_90 ( struct V_33 * V_34 )
{
int V_220 = 0 ;
int V_1 ;
F_55 (self != NULL, return;) ;
V_1 = V_34 -> V_35 . V_38 ;
do {
F_91 ( V_34 -> V_49 , & V_34 -> V_49 -> V_143 , & V_34 -> V_52 ,
F_3 ( V_1 + V_221 ) ) ;
if ( V_220 ++ > 32 ) {
F_21 ( 2 , L_31 , V_21 ) ;
break;
}
} while ( F_3 ( V_1 + V_222 ) & V_223 );
}
static T_7 F_92 ( int V_224 , void * V_7 )
{
struct V_32 * V_5 = V_7 ;
struct V_33 * V_34 = F_27 ( V_5 ) ;
int V_1 , V_225 , V_226 , V_205 ;
T_7 V_14 = V_227 ;
F_93 ( & V_34 -> V_51 ) ;
if ( V_34 -> V_35 . V_36 <= V_165 ) {
V_14 = F_94 ( V_5 ) ;
goto V_228;
}
V_1 = V_34 -> V_35 . V_37 ;
F_1 ( V_1 , 0 ) ;
V_225 = F_3 ( V_1 + V_229 ) ;
if ( V_225 == 0 )
goto V_228;
V_14 = V_230 ;
F_2 ( 0 , V_1 + V_160 ) ;
V_226 = F_3 ( V_1 + V_124 ) ;
V_205 = F_3 ( V_1 + V_193 ) ;
F_21 ( 2 , L_32 , V_21 , V_225 ) ;
if ( V_225 & V_231 ) {
if ( V_34 -> V_35 . V_184 == V_199 )
F_82 ( V_34 ) ;
else
F_81 ( V_34 ) ;
F_76 ( V_34 ) ;
}
if ( V_225 & V_232 ) {
}
F_1 ( V_1 , 0 ) ;
F_2 ( V_158 | V_159 , V_1 + V_160 ) ;
V_228:
F_95 ( & V_34 -> V_51 ) ;
return V_14 ;
}
static T_7 F_94 ( struct V_32 * V_5 )
{
struct V_33 * V_34 = F_27 ( V_5 ) ;
int V_220 = 0 ;
int V_1 ;
int V_225 , V_205 ;
V_1 = V_34 -> V_35 . V_38 ;
V_225 = F_3 ( V_1 + V_233 ) & V_234 ;
if ( V_225 == 0 )
return V_227 ;
while ( V_225 ) {
V_205 = F_3 ( V_1 + V_222 ) ;
F_21 ( 4 , L_33 ,
V_21 , V_225 , V_205 , V_1 ) ;
switch ( V_225 ) {
case V_235 :
F_21 ( 2 , L_34 , V_21 ) ;
break;
case V_236 :
F_90 ( V_34 ) ;
break;
case V_237 :
if ( V_205 & V_238 )
F_96 ( V_34 ) ;
break;
default:
F_21 ( 0 , L_35 ,
V_21 , V_225 ) ;
break;
}
if ( V_220 ++ > 100 )
break;
V_225 = F_3 ( V_1 + V_233 ) & V_234 ;
}
return V_230 ;
}
static int F_97 ( struct V_33 * V_34 )
{
int error ;
error = F_98 ( V_34 -> V_35 . V_11 , F_92 , 0 ,
V_34 -> V_49 -> V_75 , V_34 -> V_49 ) ;
if ( error )
F_21 ( 0 , L_36 ,
V_21 , V_34 -> V_35 . V_11 , error ) ;
return error ;
}
static void F_99 ( struct V_33 * V_34 )
{
unsigned long V_129 ;
F_57 ( & V_34 -> V_51 , V_129 ) ;
V_34 -> V_35 . V_36 = 0 ;
F_58 ( V_34 , V_99 ) ;
F_59 ( & V_34 -> V_51 , V_129 ) ;
}
static void F_100 ( struct V_33 * V_34 )
{
int V_1 = V_34 -> V_35 . V_37 ;
unsigned long V_129 ;
F_57 ( & V_34 -> V_51 , V_129 ) ;
F_1 ( V_1 , 0 ) ;
F_2 ( 0 , V_1 + V_160 ) ;
F_2 ( V_115 , V_1 + V_3 ) ;
F_2 ( 0x00 , V_1 + V_3 ) ;
F_59 ( & V_34 -> V_51 , V_129 ) ;
}
static int F_101 ( struct V_32 * V_5 )
{
struct V_33 * V_34 ;
char V_239 [ 16 ] ;
F_21 ( 1 , L_6 , V_21 ) ;
F_55 (dev != NULL, return -1;) ;
V_34 = F_27 ( V_5 ) ;
F_55 (self != NULL, return 0;) ;
if ( V_34 -> V_35 . V_240 ) {
F_21 ( 0 , L_37 , V_21 ) ;
return - V_241 ;
}
if ( F_98 ( V_34 -> V_35 . V_11 , F_92 , 0 , V_5 -> V_75 ,
( void * ) V_5 ) ) {
F_21 ( 0 , L_38 ,
V_21 , V_34 -> V_35 . V_11 ) ;
return - V_241 ;
}
F_99 ( V_34 ) ;
sprintf ( V_239 , L_39 , V_34 -> V_35 . V_37 ) ;
V_34 -> V_242 = F_102 ( V_5 , & V_34 -> V_100 , V_239 ) ;
if ( F_103 ( V_34 -> V_35 . V_10 , V_5 -> V_75 ) ) {
F_104 ( V_5 ) ;
F_32 ( L_40 ,
V_21 , V_34 -> V_35 . V_10 ) ;
return - V_241 ;
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
if ( V_34 -> V_242 )
F_106 ( V_34 -> V_242 ) ;
V_34 -> V_242 = NULL ;
F_100 ( V_34 ) ;
if ( ! V_34 -> V_35 . V_240 )
F_107 ( V_34 -> V_35 . V_11 , V_5 ) ;
F_108 ( V_34 -> V_35 . V_10 ) ;
F_109 ( V_34 -> V_35 . V_10 ) ;
return 0 ;
}
static int F_110 ( struct V_243 * V_5 , T_8 V_65 )
{
struct V_33 * V_34 = F_111 ( V_5 ) ;
if ( ! V_34 -> V_35 . V_240 ) {
F_21 ( 1 , L_41 , V_20 ) ;
F_112 () ;
if ( F_113 ( V_34 -> V_49 ) ) {
F_114 ( V_34 -> V_49 ) ;
F_100 ( V_34 ) ;
F_107 ( V_34 -> V_35 . V_11 , V_34 -> V_49 ) ;
F_108 ( V_34 -> V_35 . V_10 ) ;
}
V_34 -> V_35 . V_240 = 1 ;
F_115 () ;
}
return 0 ;
}
static int F_116 ( struct V_243 * V_5 )
{
struct V_33 * V_34 = F_111 ( V_5 ) ;
if ( V_34 -> V_35 . V_240 ) {
F_21 ( 1 , L_42 , V_20 ) ;
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
V_34 -> V_35 . V_240 = 0 ;
F_115 () ;
}
return 0 ;
}
static int T_9 F_120 ( struct V_33 * V_34 )
{
F_21 ( 1 , L_6 , V_21 ) ;
F_55 (self != NULL, return -1;) ;
F_121 ( V_34 -> V_72 ) ;
F_45 ( V_34 -> V_49 ) ;
F_100 ( V_34 ) ;
F_21 ( 0 , L_43 , V_21 ,
V_34 -> V_35 . V_37 ) ;
F_48 ( V_34 -> V_35 . V_37 , V_34 -> V_35 . V_95 ) ;
F_21 ( 0 , L_43 , V_21 ,
V_34 -> V_35 . V_38 ) ;
F_48 ( V_34 -> V_35 . V_38 , V_34 -> V_35 . V_96 ) ;
if ( V_34 -> V_55 . V_57 )
F_46 ( NULL , V_34 -> V_55 . V_53 ,
V_34 -> V_55 . V_57 , V_34 -> V_62 ) ;
if ( V_34 -> V_52 . V_57 )
F_46 ( NULL , V_34 -> V_52 . V_53 ,
V_34 -> V_52 . V_57 , V_34 -> V_58 ) ;
F_47 ( V_34 -> V_49 ) ;
return 0 ;
}
static void T_9 F_122 ( void )
{
int V_244 ;
F_21 ( 1 , L_6 , V_21 ) ;
for ( V_244 = 0 ; V_244 < 2 ; V_244 ++ ) {
if ( V_42 [ V_244 ] )
F_120 ( V_42 [ V_244 ] ) ;
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
F_2 ( V_115 , V_37 + V_3 ) ;
#if V_166
#endif
F_1 ( V_37 , 1 ) ;
F_2 ( ( ( F_3 ( V_37 + V_116 ) & V_156 ) | V_117 ) , V_37 + V_116 ) ;
F_2 ( V_173 , V_38 + V_175 ) ;
F_2 ( ( V_245 | V_246 | V_247 ) , V_38 + V_248 ) ;
F_2 ( V_179 | V_180 | V_145 , V_38 + V_146 ) ;
F_21 ( 3 , L_44 , V_21 ) ;
F_2 ( 0x00 , V_37 + V_3 ) ;
}
void F_75 ( struct V_33 * V_34 )
{
int V_1 ;
F_21 ( 3 , L_6 , V_21 ) ;
V_1 = V_34 -> V_35 . V_38 ;
F_2 ( 0 , V_1 + V_248 ) ;
F_2 ( 0 , V_1 + V_146 ) ;
}
static void F_96 ( struct V_33 * V_34 )
{
int V_249 = 0 ;
int V_1 ;
int V_167 ;
F_55 (self != NULL, return;) ;
F_21 ( 4 , L_6 , V_21 ) ;
V_1 = V_34 -> V_35 . V_38 ;
if ( V_34 -> V_55 . V_140 > 0 ) {
V_249 = F_123 ( V_1 , V_34 -> V_35 . V_97 ,
V_34 -> V_55 . V_67 , V_34 -> V_55 . V_140 ) ;
V_34 -> V_55 . V_67 += V_249 ;
V_34 -> V_55 . V_140 -= V_249 ;
} else {
if ( V_34 -> V_142 ) {
F_21 ( 5 , L_45 ,
V_21 , V_34 -> V_142 ) ;
F_67 ( V_34 ) ;
F_58 ( V_34 , V_34 -> V_142 ) ;
V_34 -> V_142 = 0 ;
} else {
F_64 ( V_34 -> V_49 ) ;
}
V_34 -> V_49 -> V_143 . V_198 ++ ;
if ( V_34 -> V_35 . V_36 <= 115200 ) {
V_167 = V_170 | V_250 ;
V_167 |= V_34 -> V_35 . V_36 < 38400 ?
V_171 : V_172 ;
F_2 ( V_167 , V_1 + V_178 ) ;
F_2 ( V_180 , V_1 + V_146 ) ;
}
}
}
static int F_123 ( int V_1 , int V_97 , T_10 * V_251 , int V_140 )
{
int V_249 = 0 ;
if ( ! ( F_3 ( V_1 + V_222 ) & V_238 ) ) {
F_32 ( L_46 , V_21 ) ;
return 0 ;
}
while ( V_97 -- > 0 && V_249 < V_140 ) {
F_2 ( V_251 [ V_249 ] , V_1 + V_252 ) ;
V_249 ++ ;
}
return V_249 ;
}
static int F_61 ( struct V_33 * V_34 )
{
return V_34 -> V_52 . V_65 != V_66 ;
}
static void F_39 ( struct V_33 * V_34 )
{
unsigned int V_244 ;
F_55 (self != NULL, return;) ;
for ( V_244 = 0 ; V_253 [ V_244 ] . V_75 != NULL ; V_244 ++ )
if ( V_253 [ V_244 ] . F_124 ( V_34 -> V_35 . V_37 ) ) {
F_16 ( L_47 ,
V_253 [ V_244 ] . V_75 ) ;
V_34 -> V_70 = V_244 + 1 ;
return;
}
F_16 ( L_48 ,
V_253 [ V_254 ] . V_75 ) ;
V_34 -> V_70 = V_254 ;
}
static void F_74 ( struct V_33 * V_34 , T_5 V_36 )
{
unsigned int V_255 ;
V_255 = V_34 -> V_70 ;
if ( V_255 > 0 )
V_253 [ V_255 - 1 ] . F_125 ( V_34 -> V_35 . V_37 , V_36 ) ;
}
static void F_67 ( struct V_33 * V_34 )
{
int V_1 = V_34 -> V_35 . V_38 ;
int V_256 = V_257 ;
while ( V_256 -- > 0 && ! ( F_3 ( V_1 + V_222 ) & V_258 ) )
F_126 ( 1 ) ;
if ( V_256 < 0 )
F_21 ( 0 , L_49 , V_21 ) ;
}
static int T_2 F_19 ( void )
{
struct V_259 * V_260 ;
char * type ;
unsigned int V_261 , V_262 ;
V_262 = 0 ;
V_260 = V_263 ;
while ( V_260 -> V_261 ) {
V_261 = V_260 -> V_261 ;
if ( V_260 -> type & V_264 ) {
type = L_50 ;
if ( V_260 -> type & V_265 )
if ( ! F_127 ( V_266 , V_261 , type ) )
V_262 ++ ;
if ( V_260 -> type & V_267 )
if ( ! F_128 ( V_268 , V_261 , type ) )
V_262 ++ ;
}
if ( V_260 -> type & V_269 ) {
type = L_51 ;
if ( V_260 -> type & V_265 )
if ( ! F_127 ( V_270 , V_261 , type ) )
V_262 ++ ;
if ( V_260 -> type & V_267 )
if ( ! F_128 ( V_271 , V_261 , type ) )
V_262 ++ ;
}
V_260 ++ ;
}
return V_262 ;
}
static int T_2 F_127 ( const struct V_272 * V_273 , unsigned short V_274 , char * type )
{
unsigned short V_8 , V_9 ;
T_1 V_275 , V_10 , V_11 ;
int V_14 = - V_13 ;
F_21 ( 1 , L_6 , V_21 ) ;
if ( F_129 ( V_274 , V_276 , V_273 , type ) == NULL )
return V_14 ;
F_2 ( V_277 , V_274 ) ;
V_275 = F_3 ( V_274 + 1 ) ;
if ( ! ( V_275 & V_278 ) )
F_32 ( L_52 , V_21 ) ;
F_2 ( V_279 , V_274 ) ;
V_9 = F_3 ( V_274 + 1 ) << 2 ;
F_2 ( V_280 , V_274 ) ;
V_8 = F_3 ( V_274 + 1 ) << 3 ;
F_2 ( V_281 , V_274 ) ;
V_10 = F_3 ( V_274 + 1 ) & V_282 ;
F_2 ( V_283 , V_274 ) ;
V_11 = F_3 ( V_274 + 1 ) & V_284 ;
F_16 ( L_53 , V_21 , V_8 , V_9 , V_10 , V_11 , V_275 ) ;
if ( V_8 && F_11 ( V_8 , V_9 , V_10 , V_11 ) == 0 )
V_14 = 0 ;
F_2 ( V_285 , V_274 ) ;
return V_14 ;
}
static int T_2 F_128 ( const struct V_272 * V_273 , unsigned short V_261 , char * type )
{
unsigned short V_286 , V_287 ;
int V_14 = - V_13 ;
F_21 ( 1 , L_6 , V_21 ) ;
if ( F_129 ( V_261 , 0x20 , V_273 , type ) == NULL )
return V_14 ;
F_2 ( 0x07 , V_261 ) ;
F_2 ( 0x05 , V_261 + 1 ) ;
F_2 ( 0x60 , V_261 ) ;
V_287 = F_3 ( V_261 + 1 ) << 8 ;
F_2 ( 0x61 , V_261 ) ;
V_287 |= F_3 ( V_261 + 1 ) ;
F_2 ( 0x62 , V_261 ) ;
V_286 = F_3 ( V_261 + 1 ) << 8 ;
F_2 ( 0x63 , V_261 ) ;
V_286 |= F_3 ( V_261 + 1 ) ;
F_2 ( 0x2b , V_261 ) ;
if ( V_286 && F_11 ( V_286 , V_287 , V_18 , V_19 ) == 0 )
V_14 = 0 ;
F_2 ( V_285 , V_261 ) ;
return V_14 ;
}
static int T_2 F_130 ( unsigned short V_261 , unsigned char V_288 )
{
F_21 ( 1 , L_6 , V_21 ) ;
F_2 ( V_288 , V_261 ) ;
return F_3 ( V_261 ) != V_288 ? - 1 : 0 ;
}
static const struct V_272 * T_2 F_129 ( unsigned short V_261 , T_1 V_288 , const struct V_272 * V_80 , char * type )
{
T_1 V_289 , V_290 , V_291 ;
F_21 ( 1 , L_6 , V_21 ) ;
F_2 ( V_285 , V_261 ) ;
if ( F_3 ( V_261 ) == V_285 )
return NULL ;
F_2 ( V_288 , V_261 ) ;
V_290 = F_3 ( V_261 + 1 ) ;
F_2 ( V_292 , V_261 ) ;
#if 0
if (smsc_access(cfg_base,0x55))
return NULL;
#endif
if ( F_130 ( V_261 , V_288 ) )
return NULL ;
V_289 = F_3 ( V_261 + 1 ) ;
if ( V_289 == 0 || V_289 == 0xff )
return NULL ;
if ( F_130 ( V_261 , V_288 + 1 ) )
return NULL ;
V_291 = F_3 ( V_261 + 1 ) ;
if ( V_291 >= 128 )
return NULL ;
if ( V_289 == V_290 )
return NULL ;
while ( V_80 -> V_289 != V_289 ) {
V_80 ++ ;
if ( V_80 -> V_75 == NULL )
return NULL ;
}
F_16 ( L_54 ,
V_289 , V_291 , V_261 , type , V_80 -> V_75 ) ;
if ( V_80 -> V_291 > V_291 ) {
F_16 ( L_55 ) ;
return NULL ;
}
if ( V_80 -> V_129 & V_293 )
F_16 ( L_56 ) ;
return V_80 ;
}
static int T_2 F_17 ( unsigned short V_261 )
{
int V_14 = - 1 ;
if ( ! F_49 ( V_261 , 2 , V_20 ) ) {
F_32 ( L_57 ,
V_21 , V_261 ) ;
} else {
if ( ! F_127 ( V_266 , V_261 , L_50 ) ||
! F_128 ( V_268 , V_261 , L_50 ) )
V_14 = 0 ;
F_48 ( V_261 , 2 ) ;
}
return V_14 ;
}
static int T_2 F_18 ( unsigned short V_261 )
{
int V_14 = - 1 ;
if ( ! F_49 ( V_261 , 2 , V_20 ) ) {
F_32 ( L_57 ,
V_21 , V_261 ) ;
} else {
if ( ! F_127 ( V_270 , V_261 , L_51 ) ||
! F_128 ( V_271 , V_261 , L_51 ) )
V_14 = 0 ;
F_48 ( V_261 , 2 ) ;
}
return V_14 ;
}
static int T_2 F_131 ( struct
V_294
* V_295 )
{
unsigned short V_1 = V_295 -> V_261 ;
unsigned char V_296 ;
F_2 ( V_297 , V_1 ) ;
F_2 ( V_276 , V_1 ) ;
V_296 = F_3 ( V_1 + 1 ) ;
F_21 ( 0 ,
L_58 ,
V_296 ) ;
F_2 ( 0x24 , V_1 ) ;
F_2 ( 0x00 , V_1 + 1 ) ;
F_2 ( V_279 , V_1 ) ;
F_2 ( ( V_295 -> V_287 >> 2 ) , V_1 + 1 ) ;
V_296 = F_3 ( V_1 + 1 ) ;
if ( V_296 != ( V_295 -> V_287 >> 2 ) ) {
F_32 ( L_59 ) ;
F_32 ( L_60 ) ;
return - V_298 ;
}
F_2 ( V_283 , V_1 ) ;
V_296 = F_3 ( V_1 + 1 ) ;
V_296 &= V_299 ;
V_296 |= ( V_295 -> V_300 & V_284 ) ;
F_2 ( V_296 , V_1 + 1 ) ;
V_296 = F_3 ( V_1 + 1 ) & V_284 ;
if ( V_296 != V_295 -> V_300 ) {
F_32 ( L_61 ) ;
return - V_298 ;
}
F_2 ( V_280 , V_1 ) ;
F_2 ( ( V_295 -> V_286 >> 3 ) , V_1 + 1 ) ;
V_296 = F_3 ( V_1 + 1 ) ;
if ( V_296 != ( V_295 -> V_286 >> 3 ) ) {
F_32 ( L_62 ) ;
return - V_298 ;
}
F_2 ( V_281 , V_1 ) ;
F_2 ( ( V_295 -> V_301 & V_302 ) , V_1 + 1 ) ;
V_296 = F_3 ( V_1 + 1 ) & V_302 ;
if ( V_296 != ( V_295 -> V_301 & V_302 ) ) {
F_32 ( L_63 ) ;
return - V_298 ;
}
F_2 ( V_277 , V_1 ) ;
V_296 = F_3 ( V_1 + 1 ) ;
V_296 &= ~ V_303 |
V_278 ;
F_2 ( V_296 , V_1 + 1 ) ;
F_2 ( V_304 , V_1 ) ;
V_296 = F_3 ( V_1 + 1 ) ;
F_2 ( V_296 | V_305 , V_1 + 1 ) ;
F_2 ( 0x0a , V_1 ) ;
V_296 = F_3 ( V_1 + 1 ) ;
F_2 ( V_296 | 0x40 , V_1 + 1 ) ;
F_2 ( V_306 , V_1 ) ;
V_296 = F_3 ( V_1 + 1 ) ;
F_2 ( V_296 | V_307 , V_1 + 1 ) ;
F_2 ( V_308 , V_1 ) ;
V_296 = F_3 ( V_1 + 1 ) ;
F_2 ( V_296 | V_309 , V_1 + 1 ) ;
F_2 ( V_310 , V_1 ) ;
return 0 ;
}
static int T_2 F_132 ( struct V_311 * V_5 ,
struct
V_294
* V_295 )
{
unsigned short V_312 ;
unsigned char V_296 ;
F_16 ( L_64 ) ;
F_133 ( V_5 , V_313 , & V_296 ) ;
V_296 &= 0xf8 ;
switch( V_295 -> V_287 ) {
case 0x3f8 :
V_296 |= 0x00 ;
break;
case 0x2f8 :
V_296 |= 0x01 ;
break;
case 0x220 :
V_296 |= 0x02 ;
break;
case 0x228 :
V_296 |= 0x03 ;
break;
case 0x238 :
V_296 |= 0x04 ;
break;
case 0x2e8 :
V_296 |= 0x05 ;
break;
case 0x338 :
V_296 |= 0x06 ;
break;
case 0x3e8 :
V_296 |= 0x07 ;
break;
default:
V_296 |= 0x01 ;
}
F_21 ( 1 , L_65 , V_296 ) ;
F_134 ( V_5 , V_313 , V_296 ) ;
F_135 ( V_5 , V_314 , & V_312 ) ;
switch( V_295 -> V_261 ) {
case 0x04e :
V_312 |= 0x2000 ;
break;
case 0x02e :
V_312 |= 0x1000 ;
break;
case 0x062 :
V_312 |= 0x0800 ;
break;
case 0x060 :
V_312 |= 0x0400 ;
break;
default:
F_32 ( L_66 ,
V_295 -> V_261 ) ;
break;
}
V_312 &= 0xfffd ;
V_312 |= 0x0001 ;
F_21 ( 1 , L_67 , V_312 ) ;
F_136 ( V_5 , V_314 , V_312 ) ;
F_135 ( V_5 , V_315 , & V_312 ) ;
switch( V_295 -> V_301 ) {
case 0x07 :
V_312 |= 0xc000 ;
break;
case 0x06 :
V_312 |= 0x3000 ;
break;
case 0x05 :
V_312 |= 0x0c00 ;
break;
case 0x03 :
V_312 |= 0x00c0 ;
break;
case 0x02 :
V_312 |= 0x0030 ;
break;
case 0x01 :
V_312 |= 0x000c ;
break;
case 0x00 :
V_312 |= 0x0003 ;
break;
default:
break;
}
F_21 ( 1 , L_68 , V_312 ) ;
F_136 ( V_5 , V_315 , V_312 ) ;
V_312 = V_295 -> V_286 & 0xfff8 ;
V_312 |= 0x0001 ;
F_21 ( 1 , L_69 , V_312 ) ;
F_136 ( V_5 , V_316 , V_312 ) ;
return F_131 ( V_295 ) ;
}
static void T_2 F_137 ( struct V_311 * V_5 ,
unsigned short V_317 )
{
unsigned char V_288 ;
unsigned char V_318 ;
unsigned char V_296 ;
switch( V_317 ) {
case 0x0130 :
case 0x0178 :
V_288 = 0xb0 ;
V_318 = 0x80 ;
break;
case 0x03f8 :
V_288 = 0xb4 ;
V_318 = 0x80 ;
break;
case 0x02f8 :
V_288 = 0xb4 ;
V_318 = 0x30 ;
break;
case 0x02e8 :
V_288 = 0xb4 ;
V_318 = 0x08 ;
break;
default:
F_15 ( L_70 , V_317 ) ;
return;
}
F_133 ( V_5 , V_288 , & V_296 ) ;
V_296 |= V_318 ;
F_134 ( V_5 , V_288 , V_296 ) ;
F_16 ( L_71 , V_317 ) ;
}
static int T_2 F_138 ( struct V_311 * V_5 ,
struct
V_294
* V_295 )
{
F_137 ( V_5 , V_295 -> V_287 ) ;
F_137 ( V_5 , V_295 -> V_286 ) ;
return F_131 ( V_295 ) ;
}
static int T_2 F_14 ( unsigned short V_15 ,
unsigned short V_16 ,
unsigned short V_17 ,
unsigned char V_18 ,
unsigned char V_19 )
{
struct V_311 * V_5 = NULL ;
unsigned short V_319 = 0x0000 ;
unsigned short V_320 = 0x0000 ;
int V_14 = 0 ;
F_139 (dev) {
struct V_294 * V_295 ;
if ( V_5 -> V_321 != 0x0000U ) {
V_319 = V_5 -> V_321 ;
V_320 = V_5 -> V_322 ;
}
V_295 = V_323 ;
for( ; V_295 -> V_324 ; V_295 ++ ) {
if( V_295 -> V_325 == V_5 -> V_325 &&
V_295 -> V_326 == V_5 -> V_326 &&
V_295 -> V_324 == V_319 &&
( V_295 -> V_327 == V_320 ||
V_295 -> V_327 == 0xffff ) ) {
struct V_294
V_328 ;
memcpy ( & V_328 , V_295 ,
sizeof( struct V_294 ) ) ;
if ( V_15 != 0 )
V_328 . V_261 = V_15 ;
if ( V_16 != 0 )
V_328 . V_286 = V_16 ;
if ( V_17 != 0 )
V_328 . V_287 = V_17 ;
if ( V_18 != V_26 )
V_328 . V_301 = V_18 ;
if ( V_19 != V_27 )
V_328 . V_300 = V_19 ;
F_16 ( L_72 , V_295 -> V_75 ) ;
if ( V_295 -> V_329 )
V_14 = V_295 -> V_329 ( V_5 , & V_328 ) ;
else
V_14 = - V_13 ;
}
}
}
return V_14 ;
}
static void F_140 ( int V_37 , T_5 V_36 )
{
unsigned long V_330 , V_331 ;
T_1 V_332 ;
V_330 = V_139 ;
V_331 = V_139 + V_333 ;
F_1 ( V_37 , 4 ) ;
F_2 ( ( F_3 ( V_37 + V_334 ) & V_335 ) | V_336 | V_337 ,
V_37 + V_334 ) ;
while ( ( V_332 = ( F_3 ( V_37 + V_334 ) & V_336 ) ) &&
! F_141 ( V_139 , V_331 ) )
;
if ( V_332 )
F_32 ( L_73 , V_21 ,
F_3 ( V_37 + V_334 ) ) ;
}
static int F_142 ( int V_37 )
{
return 0 ;
}
static void F_143 ( int V_37 , T_5 V_36 )
{
T_1 V_338 ;
switch ( V_36 ) {
default:
case 576000 :
V_338 = 0 ;
break;
case 1152000 :
case 4000000 :
V_338 = V_153 ;
break;
}
F_1 ( V_37 , 0 ) ;
F_2 ( ( F_3 ( V_37 + V_124 ) & 0xbf ) | V_338 , V_37 + V_124 ) ;
}
static int F_144 ( int V_37 )
{
return 0 ;
}
static void F_145 ( int V_37 , T_5 V_36 )
{
T_1 V_338 ;
switch ( V_36 ) {
default:
case 576000 :
V_338 = 0 ;
break;
case 1152000 :
case 4000000 :
V_338 = V_154 ;
break;
}
F_1 ( V_37 , 0 ) ;
F_2 ( ( F_3 ( V_37 + V_124 ) & 0xbf ) | V_338 , V_37 + V_124 ) ;
}
static int F_146 ( int V_37 )
{
return 0 ;
}

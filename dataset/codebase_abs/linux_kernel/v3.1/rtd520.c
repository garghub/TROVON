static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 ;
T_1 V_10 ;
T_1 V_11 ;
T_1 V_12 ;
#ifdef F_2
int V_13 ;
#endif
F_3 ( V_14 L_1 , V_2 -> V_15 ) ;
#if F_4 ( V_16 ) && F_4 ( F_2 )
if ( 0 == V_17 )
V_17 = 1 ;
#endif
if ( F_5 ( V_2 , sizeof( struct V_18 ) ) < 0 )
return - V_19 ;
for ( V_8 = F_6 ( V_20 , V_21 , NULL ) ;
V_8 != NULL ;
V_8 = F_6 ( V_20 , V_21 , V_8 ) ) {
int V_22 ;
if ( V_4 -> V_23 [ 0 ] || V_4 -> V_23 [ 1 ] ) {
if ( V_8 -> V_24 -> V_25 != V_4 -> V_23 [ 0 ]
|| F_7 ( V_8 -> V_26 ) != V_4 -> V_23 [ 1 ] ) {
continue;
}
}
for ( V_22 = 0 ; V_22 < F_8 ( V_27 ) ; ++ V_22 ) {
if ( V_8 -> V_28 == V_27 [ V_22 ] . V_29 ) {
V_2 -> V_30 = & V_27 [ V_22 ] ;
break;
}
}
if ( V_2 -> V_30 )
break;
}
if ( ! V_8 ) {
if ( V_4 -> V_23 [ 0 ] && V_4 -> V_23 [ 1 ] ) {
F_3 ( V_14 L_2 ,
V_4 -> V_23 [ 0 ] , V_4 -> V_23 [ 1 ] ) ;
} else {
F_3 ( V_14 L_3 ) ;
}
return - V_31 ;
}
V_32 -> V_7 = V_8 ;
V_2 -> V_33 = V_34 -> V_35 ;
V_9 = F_9 ( V_8 , V_36 ) ;
if ( V_9 < 0 ) {
F_3 ( V_14 L_4 ) ;
return V_9 ;
}
V_32 -> V_37 = 1 ;
V_10 = F_10 ( V_32 -> V_7 , V_38 ) ;
V_11 = F_10 ( V_32 -> V_7 , V_39 ) ;
V_12 = F_10 ( V_32 -> V_7 , V_40 ) ;
V_32 -> V_41 = F_11 ( V_10 , V_42 ) ;
V_32 -> V_43 = F_11 ( V_11 , V_44 ) ;
V_32 -> V_45 = F_11 ( V_12 , V_46 ) ;
if ( ! V_32 -> V_41 || ! V_32 -> V_43 || ! V_32 -> V_45 )
return - V_19 ;
F_12 ( L_5 , V_2 -> V_33 ,
( unsigned long long ) V_10 , ( unsigned long long ) V_11 ,
( unsigned long long ) V_12 ) ;
{
unsigned char V_47 ;
T_2 V_48 ;
F_13 ( V_32 -> V_7 , V_49 ,
& V_48 ) ;
F_12 ( L_6 , V_2 -> V_33 , V_48 ) ;
F_14 ( V_32 -> V_7 ,
V_50 , & V_47 ) ;
if ( V_47 < 32 ) {
F_3 ( V_14 L_7 ,
V_2 -> V_33 , V_47 , 32 ) ;
F_15 ( V_32 -> V_7 ,
V_50 , 32 ) ;
} else {
F_12 ( L_8 , V_47 ) ;
}
}
F_3 ( V_14 L_9 , V_2 -> V_33 ) ;
if ( F_16 ( V_2 , 4 ) < 0 )
return - V_19 ;
V_6 = V_2 -> V_51 + 0 ;
V_2 -> V_52 = V_6 ;
V_6 -> type = V_53 ;
V_6 -> V_54 =
V_55 | V_56 | V_57 | V_58 | V_59 ;
V_6 -> V_60 = V_34 -> V_61 ;
V_6 -> V_62 = ( 1 << V_34 -> V_63 ) - 1 ;
if ( V_34 -> V_64 <= 32 )
V_6 -> V_65 = & V_66 ;
else
V_6 -> V_65 = & V_67 ;
V_6 -> V_68 = V_69 ;
V_6 -> V_70 = V_71 ;
V_6 -> V_72 = V_73 ;
V_6 -> V_74 = V_75 ;
V_6 -> V_76 = V_77 ;
V_6 = V_2 -> V_51 + 1 ;
V_6 -> type = V_78 ;
V_6 -> V_54 = V_79 ;
V_6 -> V_60 = 2 ;
V_6 -> V_62 = ( 1 << V_34 -> V_63 ) - 1 ;
V_6 -> V_65 = & V_80 ;
V_6 -> V_81 = V_82 ;
V_6 -> V_70 = V_83 ;
V_6 = V_2 -> V_51 + 2 ;
V_6 -> type = V_84 ;
V_6 -> V_54 = V_55 | V_79 ;
V_6 -> V_60 = 8 ;
V_6 -> V_62 = 1 ;
V_6 -> V_65 = & V_85 ;
V_6 -> V_86 = V_87 ;
V_6 -> V_88 = V_89 ;
V_6 = V_2 -> V_51 + 3 ;
V_6 -> type = V_90 ;
V_6 -> V_54 = V_55 | V_79 ;
V_6 -> V_60 = 3 ;
V_6 -> V_62 = 0xffff ;
F_17 ( V_2 ) ;
F_18 ( 100 ) ;
F_19 ( V_2 , 0 ) ;
F_20 ( V_2 , 0 ) ;
F_21 ( V_2 , ~ 0 ) ;
F_22 ( V_2 ) ;
F_23 ( V_2 ) ;
F_24 ( V_2 ) ;
F_25 ( V_2 ) ;
F_26 ( V_2 , 0 ) ;
F_26 ( V_2 , 1 ) ;
F_27 ( V_2 , 0 ) ;
F_28 ( V_2 , 0 , 0x30 ) ;
F_28 ( V_2 , 1 , 0x30 ) ;
F_28 ( V_2 , 2 , 0x30 ) ;
F_28 ( V_2 , 3 , 0 ) ;
V_9 = F_29 ( V_32 -> V_7 -> V_91 , V_92 ,
V_93 , V_36 , V_2 ) ;
if ( V_9 < 0 ) {
F_3 ( L_10 ,
V_32 -> V_7 -> V_91 ) ;
return V_9 ;
}
V_2 -> V_91 = V_32 -> V_7 -> V_91 ;
F_3 ( V_14 L_11 , V_2 -> V_91 ) ;
V_9 = F_30 ( V_2 ) ;
if ( V_9 < 0 )
return V_9 ;
V_32 -> V_94 = V_9 ;
F_3 ( L_12 , V_32 -> V_94 ) ;
#ifdef F_2
if ( V_2 -> V_91 > 0 ) {
F_3 ( L_13 , V_95 ) ;
V_32 -> V_96 = 0 ;
for ( V_13 = 0 ; V_13 < V_95 ; V_13 ++ ) {
V_32 -> V_97 [ V_13 ] =
F_31 ( V_32 -> V_7 ,
sizeof( T_2 ) *
V_32 -> V_94 / 2 ,
& V_32 ->
V_98 [ V_13 ] ) ;
if ( V_32 -> V_97 [ V_13 ] == NULL ) {
V_9 = - V_19 ;
goto V_99;
}
}
V_32 -> V_100 =
F_31 ( V_32 -> V_7 ,
sizeof( struct V_101 ) *
V_95 ,
& V_32 -> V_102 ) ;
for ( V_13 = 0 ; V_13 < V_95 ; V_13 ++ ) {
V_32 -> V_100 [ V_13 ] . V_103 =
V_32 -> V_98 [ V_13 ] ;
V_32 -> V_100 [ V_13 ] . V_104 =
V_105 ;
V_32 -> V_100 [ V_13 ] . V_106 =
sizeof( T_2 ) * V_32 -> V_94 / 2 ;
V_32 -> V_100 [ V_13 ] . V_107 =
( V_32 -> V_102 + ( ( V_13 +
1 ) %
( V_95 ) )
* sizeof( V_32 -> V_100 [ 0 ] ) )
| V_108 ;
}
if ( V_32 -> V_100 == NULL ) {
V_9 = - V_19 ;
goto V_99;
}
F_32 ( V_2 , V_109 ) ;
F_33 ( V_2 , V_110 ) ;
} else {
F_3 ( V_14 L_14 ) ;
}
#endif
if ( V_2 -> V_91 ) {
F_19 ( V_2 , V_111 | V_112 ) ;
}
F_3 ( L_15 , V_2 -> V_15 ) ;
return 1 ;
#if 0
#ifdef F_2
for (index = 0; index < DMA_CHAIN_COUNT; index++) {
if (NULL != devpriv->dma0Buff[index]) {
pci_free_consistent(devpriv->pci_dev,
sizeof(u16) * devpriv->fifoLen / 2,
devpriv->dma0Buff[index],
devpriv->dma0BuffPhysAddr[index]);
devpriv->dma0Buff[index] = NULL;
}
}
if (NULL != devpriv->dma0Chain) {
pci_free_consistent(devpriv->pci_dev,
sizeof(struct plx_dma_desc)
* DMA_CHAIN_COUNT,
devpriv->dma0Chain,
devpriv->dma0ChainPhysAddr);
devpriv->dma0Chain = NULL;
}
#endif
if (dev->irq) {
RtdPlxInterruptWrite(dev, RtdPlxInterruptRead(dev)
& ~(ICS_PLIE | ICS_DMA0_E | ICS_DMA1_E));
free_irq(dev->irq, dev);
}
if (devpriv->las0)
iounmap(devpriv->las0);
if (devpriv->las1)
iounmap(devpriv->las1);
if (devpriv->lcfg)
iounmap(devpriv->lcfg);
if (devpriv->pci_dev)
pci_dev_put(devpriv->pci_dev);
return ret;
#endif
}
static int F_34 ( struct V_1 * V_2 )
{
#ifdef F_2
int V_13 ;
#endif
F_12 ( L_16 ,
V_2 -> V_15 , ( V_32 ? V_32 -> V_113 : 0L ) ) ;
if ( V_32 && V_32 -> V_45 ) {
F_12
( L_17 ,
0xffff & F_35 ( V_2 ) ,
0xffff & F_36 ( V_2 ) ,
( 0xffff & F_37 ( V_2 ) ) ^ 0x6666 ) ;
}
if ( V_32 ) {
#ifdef F_2
if ( V_32 -> V_45 ) {
F_38 ( V_2 , 0 ) ;
F_39 ( V_2 , 0 ) ;
F_19 ( V_2 , V_111 | V_112 ) ;
}
#endif
if ( V_32 -> V_41 ) {
F_17 ( V_2 ) ;
F_20 ( V_2 , 0 ) ;
F_21 ( V_2 , ~ 0 ) ;
F_22 ( V_2 ) ;
}
#ifdef F_2
for ( V_13 = 0 ; V_13 < V_95 ; V_13 ++ ) {
if ( NULL != V_32 -> V_97 [ V_13 ] ) {
F_40 ( V_32 -> V_7 ,
sizeof( T_2 ) *
V_32 -> V_94 / 2 ,
V_32 -> V_97 [ V_13 ] ,
V_32 ->
V_98 [ V_13 ] ) ;
V_32 -> V_97 [ V_13 ] = NULL ;
}
}
if ( NULL != V_32 -> V_100 ) {
F_40 ( V_32 -> V_7 ,
sizeof( struct V_101 ) *
V_95 , V_32 -> V_100 ,
V_32 -> V_102 ) ;
V_32 -> V_100 = NULL ;
}
#endif
if ( V_2 -> V_91 ) {
F_19 ( V_2 , F_41 ( V_2 )
& ~ ( V_112 | V_114 |
V_115 ) ) ;
F_42 ( V_2 -> V_91 , V_2 ) ;
}
if ( V_32 -> V_41 )
F_43 ( V_32 -> V_41 ) ;
if ( V_32 -> V_43 )
F_43 ( V_32 -> V_43 ) ;
if ( V_32 -> V_45 )
F_43 ( V_32 -> V_45 ) ;
if ( V_32 -> V_7 ) {
if ( V_32 -> V_37 )
F_44 ( V_32 -> V_7 ) ;
F_45 ( V_32 -> V_7 ) ;
}
}
F_3 ( V_14 L_18 , V_2 -> V_15 ) ;
return 0 ;
}
static unsigned short F_46 ( struct V_1 * V_2 ,
unsigned int V_116 , int V_117 )
{
unsigned int V_118 , V_119 , V_120 ;
unsigned short V_121 = 0 ;
V_118 = F_47 ( V_116 ) ;
V_119 = F_48 ( V_116 ) ;
V_120 = F_49 ( V_116 ) ;
V_121 |= V_118 & 0xf ;
if ( V_119 < V_34 -> V_122 ) {
V_121 |= 0x000 ;
V_121 |= ( V_119 & 0x7 ) << 4 ;
F_50 ( V_32 -> V_123 , V_117 ) ;
} else if ( V_119 < V_34 -> V_124 ) {
V_121 |= 0x100 ;
V_121 |= ( ( V_119 - V_34 -> V_122 ) & 0x7 ) << 4 ;
F_50 ( V_32 -> V_123 , V_117 ) ;
} else {
V_121 |= 0x200 ;
V_121 |= ( ( V_119 - V_34 -> V_124 ) & 0x7 ) << 4 ;
F_51 ( V_32 -> V_123 , V_117 ) ;
}
switch ( V_120 ) {
case V_125 :
break;
case V_126 :
V_121 |= 0x80 ;
break;
case V_127 :
V_121 |= 0x400 ;
break;
case V_128 :
break;
}
return V_121 ;
}
static void F_52 ( struct V_1 * V_2 ,
unsigned int V_60 , unsigned int * V_129 )
{
if ( V_60 > 1 ) {
int V_130 ;
F_24 ( V_2 ) ;
F_53 ( V_2 , 1 ) ;
for ( V_130 = 0 ; V_130 < V_60 ; V_130 ++ ) {
F_54 ( V_2 , F_46 ( V_2 , V_129 [ V_130 ] ,
V_130 ) ) ;
}
} else {
F_53 ( V_2 , 0 ) ;
F_55 ( V_2 , F_46 ( V_2 , V_129 [ 0 ] , 0 ) ) ;
}
}
static int F_30 ( struct V_1 * V_2 )
{
unsigned int V_131 = F_56 ( 0 , 0 , V_125 ) ;
unsigned V_22 ;
static const unsigned V_132 = 0x2000 ;
unsigned V_133 = 0 ;
F_25 ( V_2 ) ;
F_52 ( V_2 , 1 , & V_131 ) ;
F_57 ( V_2 , 0 ) ;
for ( V_22 = 0 ; V_22 < V_132 ; ++ V_22 ) {
unsigned V_134 ;
F_58 ( V_2 ) ;
F_18 ( 1 ) ;
V_134 = F_37 ( V_2 ) ;
if ( ( V_134 & V_135 ) == 0 ) {
V_133 = 2 * V_22 ;
break;
}
}
if ( V_22 == V_132 ) {
F_3 ( V_14 L_19 , V_36 ) ;
return - V_31 ;
}
F_25 ( V_2 ) ;
if ( V_133 != 0x400 && V_133 != 0x2000 ) {
F_3
( V_14 L_20 ,
V_36 , V_133 ) ;
return - V_31 ;
}
return V_133 ;
}
static int V_71 ( struct V_1 * V_2 ,
struct V_5 * V_6 , struct V_136 * V_137 ,
unsigned int * V_138 )
{
int V_139 , V_130 ;
int V_140 ;
F_25 ( V_2 ) ;
F_52 ( V_2 , 1 , & V_137 -> V_131 ) ;
F_57 ( V_2 , 0 ) ;
for ( V_139 = 0 ; V_139 < V_137 -> V_139 ; V_139 ++ ) {
T_3 V_141 ;
F_58 ( V_2 ) ;
for ( V_130 = 0 ; V_130 < V_142 ; ++ V_130 ) {
V_140 = F_37 ( V_2 ) ;
if ( V_140 & V_143 )
break;
V_144 ;
}
if ( V_130 >= V_142 ) {
F_12
( L_21 ,
V_140 ^ 0x6666 ) ;
return - V_145 ;
}
V_141 = F_59 ( V_2 ) ;
V_141 = V_141 >> 3 ;
if ( F_60 ( V_32 -> V_123 , 0 ) )
V_138 [ V_139 ] = V_141 + 2048 ;
else
V_138 [ V_139 ] = V_141 ;
}
return V_139 ;
}
static int F_61 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_146 )
{
int V_130 ;
for ( V_130 = 0 ; V_130 < V_146 ; V_130 ++ ) {
short V_147 ;
T_3 V_141 ;
if ( 0 == V_32 -> V_148 ) {
V_141 = F_59 ( V_2 ) ;
continue;
}
#if 0
if (0 == (RtdFifoStatus(dev) & FS_ADC_NOT_EMPTY)) {
DPRINTK("comedi: READ OOPS on %d of %d\n", ii + 1,
count);
break;
}
#endif
V_141 = F_59 ( V_2 ) ;
V_141 = V_141 >> 3 ;
if ( F_60 ( V_32 -> V_123 , V_6 -> V_149 -> V_150 ) )
V_147 = V_141 + 2048 ;
else
V_147 = V_141 ;
if ( ! F_62 ( V_6 -> V_149 , V_147 ) )
return - 1 ;
if ( V_32 -> V_148 > 0 )
V_32 -> V_148 -- ;
}
return 0 ;
}
static int F_63 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
while ( F_37 ( V_2 ) & V_143 ) {
short V_147 ;
T_3 V_141 = F_59 ( V_2 ) ;
if ( 0 == V_32 -> V_148 ) {
continue;
}
V_141 = V_141 >> 3 ;
if ( F_60 ( V_32 -> V_123 , V_6 -> V_149 -> V_150 ) )
V_147 = V_141 + 2048 ;
else
V_147 = V_141 ;
if ( ! F_62 ( V_6 -> V_149 , V_147 ) )
return - 1 ;
if ( V_32 -> V_148 > 0 )
V_32 -> V_148 -- ;
}
return 0 ;
}
void F_64 ( struct V_1 * V_2 , unsigned int V_151 )
{
unsigned long V_152 ;
T_4 V_153 ;
unsigned int V_130 ;
V_152 = ( unsigned long ) V_32 -> V_45
+ ( ( V_151 == 0 ) ? V_154 : V_155 ) ;
V_153 = F_65 ( V_152 ) ;
if ( ( V_153 & V_156 ) == 0 ) {
F_12 ( L_22 ,
V_151 , V_153 ) ;
goto V_157;
}
for ( V_130 = 0 ; ( V_153 & V_158 ) && V_130 < V_159 ; V_130 ++ ) {
V_144 ;
V_153 = F_65 ( V_152 ) ;
}
if ( V_153 & V_158 ) {
F_3 ( L_23 ,
V_151 ) ;
goto V_157;
}
F_66 ( 0 , V_152 ) ;
F_18 ( 1 ) ;
F_66 ( V_160 , V_152 ) ;
V_153 = F_65 ( V_152 ) ;
for ( V_130 = 0 ;
( V_153 & V_158 ) == 0 && V_130 < V_159 ; V_130 ++ ) {
V_153 = F_65 ( V_152 ) ;
V_144 ;
}
if ( ( V_153 & V_158 ) == 0 ) {
F_3 ( L_24 ,
V_151 ) ;
}
V_157:
}
static T_5 V_92 ( int V_91 ,
void * V_141 )
{
struct V_1 * V_2 = V_141 ;
T_2 V_153 ;
T_2 V_161 ;
struct V_5 * V_6 = V_2 -> V_51 + 0 ;
if ( ! V_2 -> V_162 )
return V_163 ;
V_32 -> V_113 ++ ;
V_161 = F_37 ( V_2 ) ;
if ( ! ( V_161 & V_164 ) ) {
F_12 ( L_25 , ( V_161 ^ 0x6666 ) & 0x7777 ) ;
goto V_165;
}
#ifdef F_2
if ( V_32 -> V_166 & V_167 ) {
T_6 V_168 = F_41 ( V_2 ) ;
if ( V_168 & V_169 ) {
if ( F_67 ( V_2 , V_6 ) < 0 ) {
F_12
( L_26 ,
V_32 -> V_148 ) ;
F_38 ( V_2 ,
( V_32 -> V_170 &
~ V_171 )
| V_172 ) ;
goto V_165;
}
F_38 ( V_2 ,
( V_32 ->
V_170 & ~ V_171 )
| V_172 ) ;
if ( 0 == V_32 -> V_148 ) {
F_12 ( L_27 ) ;
goto V_173;
}
F_68 ( V_2 , V_6 ) ;
} else {
}
}
#endif
V_153 = F_35 ( V_2 ) ;
if ( 0 == V_153 )
return V_174 ;
if ( V_153 & V_175 ) {
if ( ! ( V_161 & V_135 ) ) {
if ( F_61 ( V_2 , V_6 , V_32 -> V_94 / 2 ) < 0 ) {
F_12
( L_28 ,
V_32 -> V_148 ) ;
goto V_165;
}
if ( 0 == V_32 -> V_148 ) {
F_12 ( L_29 , ( V_161 ^ 0x6666 ) & 0x7777 ) ;
goto V_173;
}
F_68 ( V_2 , V_6 ) ;
} else if ( V_32 -> V_176 > 0 ) {
if ( V_161 & V_143 ) {
if ( F_61 ( V_2 , V_6 , V_32 -> V_176 ) < 0 ) {
F_12
( L_30 ,
V_32 -> V_148 ) ;
goto V_165;
}
if ( 0 == V_32 -> V_148 ) {
F_12
( L_31 ,
( V_161 ^ 0x6666 ) & 0x7777 ) ;
goto V_173;
}
F_68 ( V_2 , V_6 ) ;
}
} else {
F_12
( L_32 ,
( V_161 ^ 0x6666 ) & 0x7777 ) ;
}
} else {
F_12 ( L_33 ) ;
}
if ( 0xffff & F_36 ( V_2 ) ) {
F_12
( L_34 ,
V_32 -> V_148 , 0xffff & F_36 ( V_2 ) ) ;
goto V_165;
}
F_21 ( V_2 , V_153 ) ;
F_22 ( V_2 ) ;
return V_174 ;
V_165:
F_25 ( V_2 ) ;
V_6 -> V_149 -> V_177 |= V_178 ;
V_32 -> V_148 = 0 ;
V_173:
F_69 ( V_2 , 0 ) ;
F_70 ( V_2 ) ;
F_57 ( V_2 , 0 ) ;
F_20 ( V_2 , 0 ) ;
#ifdef F_2
if ( V_32 -> V_166 & V_167 ) {
F_19 ( V_2 ,
F_41 ( V_2 ) & ~ V_114 ) ;
F_64 ( V_2 , 0 ) ;
V_32 -> V_166 &= ~ V_167 ;
if ( V_32 -> V_148 > 0 ) {
F_12 ( L_35 ,
V_32 -> V_148 ) ;
}
}
#endif
if ( V_32 -> V_148 > 0 ) {
V_161 = F_37 ( V_2 ) ;
F_12 ( L_36 , V_32 -> V_148 , ( V_161 ^ 0x6666 ) & 0x7777 ) ;
F_63 ( V_2 , V_6 ) ;
}
V_6 -> V_149 -> V_177 |= V_179 ;
F_68 ( V_2 , V_6 ) ;
V_153 = F_35 ( V_2 ) ;
F_21 ( V_2 , V_153 ) ;
F_22 ( V_2 ) ;
V_161 = F_37 ( V_2 ) ;
F_12
( L_37 ,
V_32 -> V_113 , V_153 ,
0xffff & F_36 ( V_2 ) ) ;
return V_174 ;
}
static int V_75 ( struct V_1 * V_2 ,
struct V_5 * V_6 , struct V_180 * V_181 )
{
int V_182 = 0 ;
int V_183 ;
V_183 = V_181 -> V_184 ;
V_181 -> V_184 &= V_185 ;
if ( ! V_181 -> V_184 || V_183 != V_181 -> V_184 )
V_182 ++ ;
V_183 = V_181 -> V_186 ;
V_181 -> V_186 &= V_187 | V_188 ;
if ( ! V_181 -> V_186 || V_183 != V_181 -> V_186 )
V_182 ++ ;
V_183 = V_181 -> V_189 ;
V_181 -> V_189 &= V_187 | V_188 ;
if ( ! V_181 -> V_189 || V_183 != V_181 -> V_189 )
V_182 ++ ;
V_183 = V_181 -> V_190 ;
V_181 -> V_190 &= V_191 ;
if ( ! V_181 -> V_190 || V_183 != V_181 -> V_190 )
V_182 ++ ;
V_183 = V_181 -> V_192 ;
V_181 -> V_192 &= V_191 | V_193 ;
if ( ! V_181 -> V_192 || V_183 != V_181 -> V_192 )
V_182 ++ ;
if ( V_182 )
return 1 ;
if ( V_181 -> V_186 != V_187 &&
V_181 -> V_186 != V_188 ) {
V_182 ++ ;
}
if ( V_181 -> V_189 != V_187 && V_181 -> V_189 != V_188 )
V_182 ++ ;
if ( V_181 -> V_192 != V_191 && V_181 -> V_192 != V_193 )
V_182 ++ ;
if ( V_182 )
return 2 ;
if ( V_181 -> V_194 != 0 ) {
V_181 -> V_194 = 0 ;
V_182 ++ ;
}
if ( V_181 -> V_186 == V_187 ) {
if ( 1 == V_181 -> V_195 ) {
if ( V_181 -> V_196 < V_197 ) {
V_181 -> V_196 = V_197 ;
F_71 ( & V_181 -> V_196 ,
V_198 ) ;
V_182 ++ ;
}
if ( V_181 -> V_196 > V_199 ) {
V_181 -> V_196 = V_199 ;
F_71 ( & V_181 -> V_196 ,
V_200 ) ;
V_182 ++ ;
}
} else {
if ( V_181 -> V_196 < V_201 ) {
V_181 -> V_196 = V_201 ;
F_71 ( & V_181 -> V_196 ,
V_198 ) ;
V_182 ++ ;
}
if ( V_181 -> V_196 > V_202 ) {
V_181 -> V_196 = V_202 ;
F_71 ( & V_181 -> V_196 ,
V_200 ) ;
V_182 ++ ;
}
}
} else {
if ( V_181 -> V_196 > 9 ) {
V_181 -> V_196 = 9 ;
V_182 ++ ;
}
}
if ( V_181 -> V_189 == V_187 ) {
if ( 1 == V_181 -> V_195 ) {
if ( V_181 -> V_203 < V_197 ) {
V_181 -> V_203 = V_197 ;
F_71 ( & V_181 -> V_203 ,
V_198 ) ;
V_182 ++ ;
}
if ( V_181 -> V_203 > V_199 ) {
V_181 -> V_203 = V_199 ;
F_71 ( & V_181 -> V_203 ,
V_200 ) ;
V_182 ++ ;
}
} else {
if ( V_181 -> V_203 < V_201 ) {
V_181 -> V_203 = V_201 ;
F_71 ( & V_181 -> V_203 ,
V_198 ) ;
V_182 ++ ;
}
if ( V_181 -> V_203 > V_202 ) {
V_181 -> V_203 = V_202 ;
F_71 ( & V_181 -> V_203 ,
V_200 ) ;
V_182 ++ ;
}
}
} else {
if ( V_181 -> V_203 > 9 ) {
V_181 -> V_203 = 9 ;
V_182 ++ ;
}
}
#if 0
if (cmd->scan_end_arg != cmd->chanlist_len) {
cmd->scan_end_arg = cmd->chanlist_len;
err++;
}
#endif
if ( V_181 -> V_192 == V_191 ) {
} else {
if ( V_181 -> V_204 != 0 ) {
V_181 -> V_204 = 0 ;
V_182 ++ ;
}
}
if ( V_182 )
return 3 ;
if ( V_181 -> V_195 > V_69 ) {
V_181 -> V_195 = V_69 ;
V_182 ++ ;
}
if ( V_181 -> V_186 == V_187 ) {
V_183 = V_181 -> V_196 ;
F_71 ( & V_181 -> V_196 ,
V_181 -> V_166 & V_205 ) ;
if ( V_183 != V_181 -> V_196 )
V_182 ++ ;
}
if ( V_181 -> V_189 == V_187 ) {
V_183 = V_181 -> V_203 ;
F_71 ( & V_181 -> V_203 ,
V_181 -> V_166 & V_205 ) ;
if ( V_183 != V_181 -> V_203 )
V_182 ++ ;
if ( V_181 -> V_186 == V_187
&& ( V_181 -> V_196
< ( V_181 -> V_203 * V_181 -> V_206 ) ) ) {
V_181 -> V_196 =
V_181 -> V_203 * V_181 -> V_206 ;
V_182 ++ ;
}
}
if ( V_182 )
return 4 ;
return 0 ;
}
static int V_73 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_180 * V_181 = & V_6 -> V_149 -> V_181 ;
int V_207 ;
F_69 ( V_2 , 0 ) ;
F_70 ( V_2 ) ;
F_57 ( V_2 , 0 ) ;
F_20 ( V_2 , 0 ) ;
#ifdef F_2
if ( V_32 -> V_166 & V_167 ) {
F_19 ( V_2 ,
F_41 ( V_2 ) & ~ V_114 ) ;
F_64 ( V_2 , 0 ) ;
V_32 -> V_166 &= ~ V_167 ;
if ( F_41 ( V_2 ) & V_169 ) {
F_38 ( V_2 , V_172 ) ;
}
}
F_72 ( V_2 ) ;
#endif
F_25 ( V_2 ) ;
F_23 ( V_2 ) ;
V_32 -> V_113 = 0 ;
if ( ! V_2 -> V_91 ) {
F_12 ( L_38 ) ;
return - V_208 ;
}
F_52 ( V_2 , V_181 -> V_195 , V_181 -> V_209 ) ;
if ( V_181 -> V_195 > 1 ) {
F_73 ( V_2 , 0 ) ;
F_74 ( V_2 , 1 ) ;
F_57 ( V_2 , 2 ) ;
} else {
F_73 ( V_2 , 0 ) ;
F_57 ( V_2 , 1 ) ;
}
F_75 ( V_2 , V_32 -> V_94 / 2 - 1 ) ;
if ( V_187 == V_181 -> V_186 ) {
if ( V_181 -> V_166 & V_210 ) {
V_32 -> V_176 = V_181 -> V_195 ;
V_32 -> V_166 |= V_211 ;
} else {
V_32 -> V_176
=
( V_212 * V_181 -> V_195 ) /
V_181 -> V_196 ;
if ( V_32 -> V_176 < V_181 -> V_195 ) {
V_32 -> V_176 = V_181 -> V_195 ;
} else {
V_32 -> V_176 =
( V_32 -> V_176 +
V_181 -> V_195 - 1 )
/ V_181 -> V_195 ;
V_32 -> V_176 *= V_181 -> V_195 ;
}
V_32 -> V_166 |= V_211 ;
}
if ( V_32 -> V_176 >= ( V_32 -> V_94 / 2 ) ) {
V_32 -> V_176 = 0 ;
V_32 -> V_166 &= ~ V_211 ;
} else {
F_75 ( V_2 , V_32 -> V_176 - 1 ) ;
}
F_12
( L_39 ,
V_181 -> V_195 , V_32 -> V_176 , V_32 -> V_94 ,
V_181 -> V_196 , V_32 -> V_166 ) ;
} else {
V_32 -> V_176 = 0 ;
V_32 -> V_166 &= ~ V_211 ;
}
F_76 ( V_2 , 1 ) ;
F_77 ( V_2 , 1 ) ;
switch ( V_181 -> V_192 ) {
case V_191 :
V_32 -> V_148 = V_181 -> V_204 * V_181 -> V_195 ;
if ( ( V_32 -> V_176 > 0 )
&& ( V_32 -> V_176 > V_32 -> V_148 ) ) {
V_32 -> V_176 = V_32 -> V_148 ;
}
break;
case V_193 :
V_32 -> V_148 = - 1 ;
break;
default:
F_12 ( L_40 ,
V_181 -> V_192 ) ;
}
switch ( V_181 -> V_186 ) {
case V_187 :
V_207 = F_71 ( & V_181 -> V_196 ,
V_213 ) ;
F_78 ( V_2 , V_207 ) ;
break;
case V_188 :
F_73 ( V_2 , 1 ) ;
break;
default:
F_12 ( L_41 ,
V_181 -> V_186 ) ;
}
switch ( V_181 -> V_189 ) {
case V_187 :
if ( V_181 -> V_195 > 1 ) {
V_207 = F_71 ( & V_181 -> V_203 ,
V_213 ) ;
F_79 ( V_2 , V_207 ) ;
}
break;
case V_188 :
F_74 ( V_2 , 2 ) ;
break;
default:
F_12 ( L_42 ,
V_181 -> V_189 ) ;
}
F_21 ( V_2 , ~ 0 ) ;
F_22 ( V_2 ) ;
if ( V_32 -> V_176 > 0 ) {
F_20 ( V_2 , V_175 ) ;
F_12 ( L_43 , V_32 -> V_176 ) ;
} else {
#ifdef F_2
V_32 -> V_166 |= V_167 ;
V_32 -> V_96 = 0 ;
F_32 ( V_2 , V_109 ) ;
F_80 ( V_2 ,
V_32 -> V_100 [ V_95 - 1 ] . V_107 ) ;
F_33 ( V_2 , V_110 ) ;
F_19 ( V_2 ,
F_41 ( V_2 ) | V_114 ) ;
F_38 ( V_2 , V_156 ) ;
F_38 ( V_2 , V_156 | V_171 ) ;
F_12 ( L_44 ,
F_41 ( V_2 ) , V_32 -> V_214 ) ;
#else
F_20 ( V_2 , V_175 ) ;
F_12 ( L_45 ) ;
#endif
}
F_81 ( V_2 ) ;
return 0 ;
}
static int V_77 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_2 V_153 ;
F_69 ( V_2 , 0 ) ;
F_70 ( V_2 ) ;
F_57 ( V_2 , 0 ) ;
F_20 ( V_2 , 0 ) ;
V_32 -> V_148 = 0 ;
#ifdef F_2
if ( V_32 -> V_166 & V_167 ) {
F_19 ( V_2 ,
F_41 ( V_2 ) & ~ V_114 ) ;
F_64 ( V_2 , 0 ) ;
V_32 -> V_166 &= ~ V_167 ;
}
#endif
V_153 = F_35 ( V_2 ) ;
F_12
( L_46 ,
V_32 -> V_113 , V_153 ,
0xffff & F_36 ( V_2 ) ) ;
return 0 ;
}
static int F_82 ( unsigned int * V_215 ,
int V_216 , int V_217 )
{
int V_218 ;
switch ( V_216 ) {
case V_213 :
default:
V_218 = ( * V_215 + V_217 / 2 ) / V_217 ;
break;
case V_200 :
V_218 = ( * V_215 ) / V_217 ;
break;
case V_198 :
V_218 = ( * V_215 + V_217 - 1 ) / V_217 ;
break;
}
if ( V_218 < 2 )
V_218 = 2 ;
* V_215 = V_217 * V_218 ;
return V_218 - 1 ;
}
static int F_71 ( unsigned int * V_219 , int V_216 )
{
return F_82 ( V_219 , V_216 , V_220 ) ;
}
static int V_82 ( struct V_1 * V_2 ,
struct V_5 * V_6 , struct V_136 * V_137 ,
unsigned int * V_138 )
{
int V_22 ;
int V_118 = F_47 ( V_137 -> V_131 ) ;
int V_119 = F_48 ( V_137 -> V_131 ) ;
F_83 ( V_2 , V_118 , V_119 ) ;
for ( V_22 = 0 ; V_22 < V_137 -> V_139 ; ++ V_22 ) {
int V_221 = V_138 [ V_22 ] << 3 ;
int V_140 = 0 ;
int V_130 ;
if ( ( V_119 > 1 )
&& ( V_138 [ V_22 ] < 2048 ) ) {
V_221 = ( ( ( int ) V_138 [ V_22 ] ) - 2048 ) << 3 ;
} else {
V_221 = V_138 [ V_22 ] << 3 ;
}
F_12
( L_47 ,
V_118 , V_119 , V_138 [ V_22 ] , V_221 ) ;
F_84 ( V_2 , V_118 , V_221 ) ;
F_85 ( V_2 , V_118 ) ;
V_32 -> V_222 [ V_118 ] = V_138 [ V_22 ] ;
for ( V_130 = 0 ; V_130 < V_223 ; ++ V_130 ) {
V_140 = F_37 ( V_2 ) ;
if ( V_140 & ( ( 0 == V_118 ) ? V_224 :
V_225 ) )
break;
V_144 ;
}
if ( V_130 >= V_223 ) {
F_12
( L_48 ,
V_140 ^ 0x6666 ) ;
return - V_145 ;
}
}
return V_22 ;
}
static int V_83 ( struct V_1 * V_2 ,
struct V_5 * V_6 , struct V_136 * V_137 ,
unsigned int * V_138 )
{
int V_22 ;
int V_118 = F_47 ( V_137 -> V_131 ) ;
for ( V_22 = 0 ; V_22 < V_137 -> V_139 ; V_22 ++ )
V_138 [ V_22 ] = V_32 -> V_222 [ V_118 ] ;
return V_22 ;
}
static int V_87 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_136 * V_137 , unsigned int * V_138 )
{
if ( V_137 -> V_139 != 2 )
return - V_226 ;
if ( V_138 [ 0 ] ) {
V_6 -> V_227 &= ~ V_138 [ 0 ] ;
V_6 -> V_227 |= V_138 [ 0 ] & V_138 [ 1 ] ;
F_86 ( V_2 , V_6 -> V_227 ) ;
}
V_138 [ 1 ] = F_87 ( V_2 ) ;
return 2 ;
}
static int V_89 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_136 * V_137 , unsigned int * V_138 )
{
int V_118 = F_47 ( V_137 -> V_131 ) ;
switch ( V_138 [ 0 ] ) {
case V_228 :
V_6 -> V_229 |= 1 << V_118 ;
break;
case V_230 :
V_6 -> V_229 &= ~ ( 1 << V_118 ) ;
break;
case V_231 :
V_138 [ 1 ] =
( V_6 -> V_229 & ( 1 << V_118 ) ) ? V_232 : V_233 ;
return V_137 -> V_139 ;
break;
default:
return - V_226 ;
}
F_12 ( L_49 , V_6 -> V_229 ) ;
F_27 ( V_2 , 0x01 ) ;
F_88 ( V_2 , V_6 -> V_229 ) ;
F_27 ( V_2 , 0 ) ;
return 1 ;
}
static int T_7 F_89 ( struct V_7 * V_2 ,
const struct V_234 * V_235 )
{
return F_90 ( V_2 , V_236 . V_237 ) ;
}
static void T_8 F_91 ( struct V_7 * V_2 )
{
F_92 ( V_2 ) ;
}
static int T_9 F_93 ( void )
{
int V_238 ;
V_238 = F_94 ( & V_236 ) ;
if ( V_238 < 0 )
return V_238 ;
V_239 . V_35 = ( char * ) V_236 . V_237 ;
return F_95 ( & V_239 ) ;
}
static void T_10 F_96 ( void )
{
F_97 ( & V_239 ) ;
F_98 ( & V_236 ) ;
}

static void F_1 ( struct V_1 * V_2 )
{
F_2 (KERN_DEBUG DRIVER_NAME L_1 ,
mmc_hostname(host->mmc)) ;
F_2 (KERN_DEBUG DRIVER_NAME L_2 ,
sdhci_readl(host, SDHCI_DMA_ADDRESS),
sdhci_readw(host, SDHCI_HOST_VERSION)) ;
F_2 (KERN_DEBUG DRIVER_NAME L_3 ,
sdhci_readw(host, SDHCI_BLOCK_SIZE),
sdhci_readw(host, SDHCI_BLOCK_COUNT)) ;
F_2 (KERN_DEBUG DRIVER_NAME L_4 ,
sdhci_readl(host, SDHCI_ARGUMENT),
sdhci_readw(host, SDHCI_TRANSFER_MODE)) ;
F_2 (KERN_DEBUG DRIVER_NAME L_5 ,
sdhci_readl(host, SDHCI_PRESENT_STATE),
sdhci_readb(host, SDHCI_HOST_CONTROL)) ;
F_2 (KERN_DEBUG DRIVER_NAME L_6 ,
sdhci_readb(host, SDHCI_POWER_CONTROL),
sdhci_readb(host, SDHCI_BLOCK_GAP_CONTROL)) ;
F_2 (KERN_DEBUG DRIVER_NAME L_7 ,
sdhci_readb(host, SDHCI_WAKE_UP_CONTROL),
sdhci_readw(host, SDHCI_CLOCK_CONTROL)) ;
F_2 (KERN_DEBUG DRIVER_NAME L_8 ,
sdhci_readb(host, SDHCI_TIMEOUT_CONTROL),
sdhci_readl(host, SDHCI_INT_STATUS)) ;
F_2 (KERN_DEBUG DRIVER_NAME L_9 ,
sdhci_readl(host, SDHCI_INT_ENABLE),
sdhci_readl(host, SDHCI_SIGNAL_ENABLE)) ;
F_2 (KERN_DEBUG DRIVER_NAME L_10 ,
sdhci_readw(host, SDHCI_ACMD12_ERR),
sdhci_readw(host, SDHCI_SLOT_INT_STATUS)) ;
F_2 (KERN_DEBUG DRIVER_NAME L_11 ,
sdhci_readl(host, SDHCI_CAPABILITIES),
sdhci_readl(host, SDHCI_CAPABILITIES_1)) ;
F_2 (KERN_DEBUG DRIVER_NAME L_12 ,
sdhci_readw(host, SDHCI_COMMAND),
sdhci_readl(host, SDHCI_MAX_CURRENT)) ;
F_2 (KERN_DEBUG DRIVER_NAME L_13 ,
sdhci_readw(host, SDHCI_HOST_CONTROL2)) ;
if ( V_2 -> V_3 & V_4 )
F_2 (KERN_DEBUG DRIVER_NAME L_14 ,
readl(host->ioaddr + SDHCI_ADMA_ERROR),
readl(host->ioaddr + SDHCI_ADMA_ADDRESS)) ;
F_2 (KERN_DEBUG DRIVER_NAME L_15 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_5 , T_1 V_6 )
{
T_1 V_7 ;
V_7 = F_4 ( V_2 , V_8 ) ;
V_7 &= ~ V_5 ;
V_7 |= V_6 ;
F_5 ( V_2 , V_7 , V_8 ) ;
F_5 ( V_2 , V_7 , V_9 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_10 )
{
F_3 ( V_2 , 0 , V_10 ) ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_10 )
{
F_3 ( V_2 , V_10 , 0 ) ;
}
static void F_8 ( struct V_1 * V_2 , bool V_11 )
{
T_1 V_10 = V_12 | V_13 ;
if ( V_2 -> V_14 & V_15 )
return;
if ( V_11 )
F_6 ( V_2 , V_10 ) ;
else
F_7 ( V_2 , V_10 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_8 ( V_2 , true ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_8 ( V_2 , false ) ;
}
static void F_11 ( struct V_1 * V_2 , T_2 V_16 )
{
unsigned long V_17 ;
T_1 V_18 ( V_7 ) ;
if ( V_2 -> V_14 & V_19 ) {
if ( ! ( F_4 ( V_2 , V_20 ) &
V_21 ) )
return;
}
if ( V_2 -> V_14 & V_22 )
V_7 = F_4 ( V_2 , V_8 ) ;
if ( V_2 -> V_23 -> V_24 )
V_2 -> V_23 -> V_24 ( V_2 , V_16 ) ;
F_12 ( V_2 , V_16 , V_25 ) ;
if ( V_16 & V_26 )
V_2 -> clock = 0 ;
V_17 = 100 ;
while ( F_13 ( V_2 , V_25 ) & V_16 ) {
if ( V_17 == 0 ) {
F_2 ( V_27 L_16 ,
F_14 ( V_2 -> V_28 ) , ( int ) V_16 ) ;
F_1 ( V_2 ) ;
return;
}
V_17 -- ;
F_15 ( 1 ) ;
}
if ( V_2 -> V_23 -> V_29 )
V_2 -> V_23 -> V_29 ( V_2 , V_16 ) ;
if ( V_2 -> V_14 & V_22 )
F_3 ( V_2 , V_30 , V_7 ) ;
}
static void F_16 ( struct V_1 * V_2 , int V_31 )
{
if ( V_31 )
F_11 ( V_2 , V_32 | V_33 ) ;
else
F_11 ( V_2 , V_26 ) ;
F_3 ( V_2 , V_30 ,
V_34 | V_35 |
V_36 | V_37 | V_38 |
V_39 | V_40 | V_41 |
V_42 | V_43 ) ;
if ( V_31 ) {
V_2 -> clock = 0 ;
F_17 ( V_2 -> V_28 , & V_2 -> V_28 -> V_44 ) ;
}
}
static void F_18 ( struct V_1 * V_2 )
{
F_16 ( V_2 , 0 ) ;
F_9 ( V_2 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
T_2 V_45 ;
V_45 = F_13 ( V_2 , V_46 ) ;
V_45 |= V_47 ;
F_12 ( V_2 , V_45 , V_46 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
T_2 V_45 ;
V_45 = F_13 ( V_2 , V_46 ) ;
V_45 &= ~ V_47 ;
F_12 ( V_2 , V_45 , V_46 ) ;
}
static void F_21 ( struct V_48 * V_49 ,
enum V_50 V_51 )
{
struct V_1 * V_2 = F_22 ( V_49 , struct V_1 , V_49 ) ;
unsigned long V_3 ;
F_23 ( & V_2 -> V_52 , V_3 ) ;
if ( V_51 == V_53 )
F_20 ( V_2 ) ;
else
F_19 ( V_2 ) ;
F_24 ( & V_2 -> V_52 , V_3 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
T_3 V_54 , V_55 , V_56 ;
T_1 V_18 ( V_57 ) ;
T_2 * V_58 ;
F_26 ( L_17 ) ;
V_54 = V_2 -> V_59 -> V_60 ;
V_56 = 0 ;
F_27 ( V_3 ) ;
while ( V_54 ) {
if ( ! F_28 ( & V_2 -> V_61 ) )
F_29 () ;
V_55 = F_30 ( V_2 -> V_61 . V_62 , V_54 ) ;
V_54 -= V_55 ;
V_2 -> V_61 . V_63 = V_55 ;
V_58 = V_2 -> V_61 . V_64 ;
while ( V_55 ) {
if ( V_56 == 0 ) {
V_57 = F_4 ( V_2 , V_65 ) ;
V_56 = 4 ;
}
* V_58 = V_57 & 0xFF ;
V_58 ++ ;
V_57 >>= 8 ;
V_56 -- ;
V_55 -- ;
}
}
F_31 ( & V_2 -> V_61 ) ;
F_32 ( V_3 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
T_3 V_54 , V_55 , V_56 ;
T_1 V_57 ;
T_2 * V_58 ;
F_26 ( L_18 ) ;
V_54 = V_2 -> V_59 -> V_60 ;
V_56 = 0 ;
V_57 = 0 ;
F_27 ( V_3 ) ;
while ( V_54 ) {
if ( ! F_28 ( & V_2 -> V_61 ) )
F_29 () ;
V_55 = F_30 ( V_2 -> V_61 . V_62 , V_54 ) ;
V_54 -= V_55 ;
V_2 -> V_61 . V_63 = V_55 ;
V_58 = V_2 -> V_61 . V_64 ;
while ( V_55 ) {
V_57 |= ( T_1 ) * V_58 << ( V_56 * 8 ) ;
V_58 ++ ;
V_56 ++ ;
V_55 -- ;
if ( ( V_56 == 4 ) || ( ( V_55 == 0 ) && ( V_54 == 0 ) ) ) {
F_5 ( V_2 , V_57 , V_65 ) ;
V_56 = 0 ;
V_57 = 0 ;
}
}
}
F_31 ( & V_2 -> V_61 ) ;
F_32 ( V_3 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
T_1 V_16 ;
F_35 ( ! V_2 -> V_59 ) ;
if ( V_2 -> V_66 == 0 )
return;
if ( V_2 -> V_59 -> V_3 & V_67 )
V_16 = V_68 ;
else
V_16 = V_69 ;
if ( ( V_2 -> V_14 & V_70 ) &&
( V_2 -> V_59 -> V_66 == 1 ) )
V_16 = ~ 0 ;
while ( F_4 ( V_2 , V_20 ) & V_16 ) {
if ( V_2 -> V_14 & V_71 )
F_36 ( 100 ) ;
if ( V_2 -> V_59 -> V_3 & V_67 )
F_25 ( V_2 ) ;
else
F_33 ( V_2 ) ;
V_2 -> V_66 -- ;
if ( V_2 -> V_66 == 0 )
break;
}
F_26 ( L_19 ) ;
}
static char * F_37 ( struct V_72 * V_73 , unsigned long * V_3 )
{
F_27 ( * V_3 ) ;
return F_38 ( F_39 ( V_73 ) , V_74 ) + V_73 -> V_75 ;
}
static void F_40 ( void * V_76 , unsigned long * V_3 )
{
F_41 ( V_76 , V_74 ) ;
F_32 ( * V_3 ) ;
}
static void F_42 ( T_2 * V_77 , T_1 V_64 , int V_55 , unsigned V_78 )
{
T_4 * V_79 = ( T_4 V_80 * ) ( V_77 + 4 ) ;
T_5 * V_81 = ( T_5 V_80 * ) V_77 ;
V_81 [ 0 ] = F_43 ( V_78 ) ;
V_81 [ 1 ] = F_43 ( V_55 ) ;
V_79 [ 0 ] = F_44 ( V_64 ) ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_82 * V_59 )
{
int V_83 ;
T_2 * V_77 ;
T_2 * V_84 ;
T_6 V_64 ;
T_6 V_85 ;
int V_55 , V_75 ;
struct V_72 * V_73 ;
int V_86 ;
char * V_76 ;
unsigned long V_3 ;
if ( V_59 -> V_3 & V_67 )
V_83 = V_87 ;
else
V_83 = V_88 ;
V_2 -> V_85 = F_46 ( F_47 ( V_2 -> V_28 ) ,
V_2 -> V_89 , 128 * 4 , V_83 ) ;
if ( F_48 ( F_47 ( V_2 -> V_28 ) , V_2 -> V_85 ) )
goto V_90;
F_35 ( V_2 -> V_85 & 0x3 ) ;
V_2 -> V_91 = F_49 ( F_47 ( V_2 -> V_28 ) ,
V_59 -> V_73 , V_59 -> V_92 , V_83 ) ;
if ( V_2 -> V_91 == 0 )
goto V_93;
V_77 = V_2 -> V_94 ;
V_84 = V_2 -> V_89 ;
V_85 = V_2 -> V_85 ;
F_50 (data->sg, sg, host->sg_count, i) {
V_64 = F_51 ( V_73 ) ;
V_55 = F_52 ( V_73 ) ;
V_75 = ( 4 - ( V_64 & 0x3 ) ) & 0x3 ;
if ( V_75 ) {
if ( V_59 -> V_3 & V_95 ) {
V_76 = F_37 ( V_73 , & V_3 ) ;
F_53 ( ( ( long ) V_76 & V_96 ) > ( V_97 - 3 ) ) ;
memcpy ( V_84 , V_76 , V_75 ) ;
F_40 ( V_76 , & V_3 ) ;
}
F_42 ( V_77 , V_85 , V_75 , 0x21 ) ;
F_35 ( V_75 > 65536 ) ;
V_84 += 4 ;
V_85 += 4 ;
V_77 += 8 ;
V_64 += V_75 ;
V_55 -= V_75 ;
}
F_35 ( V_55 > 65536 ) ;
F_42 ( V_77 , V_64 , V_55 , 0x21 ) ;
V_77 += 8 ;
F_53 ( ( V_77 - V_2 -> V_94 ) > ( 128 * 2 + 1 ) * 4 ) ;
}
if ( V_2 -> V_14 & V_98 ) {
if ( V_77 != V_2 -> V_94 ) {
V_77 -= 8 ;
V_77 [ 0 ] |= 0x2 ;
}
} else {
F_42 ( V_77 , 0 , 0 , 0x3 ) ;
}
if ( V_59 -> V_3 & V_95 ) {
F_54 ( F_47 ( V_2 -> V_28 ) ,
V_2 -> V_85 , 128 * 4 , V_83 ) ;
}
V_2 -> V_99 = F_46 ( F_47 ( V_2 -> V_28 ) ,
V_2 -> V_94 , ( 128 * 2 + 1 ) * 4 , V_88 ) ;
if ( F_48 ( F_47 ( V_2 -> V_28 ) , V_2 -> V_99 ) )
goto V_100;
F_35 ( V_2 -> V_99 & 0x3 ) ;
return 0 ;
V_100:
F_55 ( F_47 ( V_2 -> V_28 ) , V_59 -> V_73 ,
V_59 -> V_92 , V_83 ) ;
V_93:
F_56 ( F_47 ( V_2 -> V_28 ) , V_2 -> V_85 ,
128 * 4 , V_83 ) ;
V_90:
return - V_101 ;
}
static void F_57 ( struct V_1 * V_2 ,
struct V_82 * V_59 )
{
int V_83 ;
struct V_72 * V_73 ;
int V_86 , V_102 ;
T_2 * V_84 ;
char * V_76 ;
unsigned long V_3 ;
if ( V_59 -> V_3 & V_67 )
V_83 = V_87 ;
else
V_83 = V_88 ;
F_56 ( F_47 ( V_2 -> V_28 ) , V_2 -> V_99 ,
( 128 * 2 + 1 ) * 4 , V_88 ) ;
F_56 ( F_47 ( V_2 -> V_28 ) , V_2 -> V_85 ,
128 * 4 , V_83 ) ;
if ( V_59 -> V_3 & V_67 ) {
F_58 ( F_47 ( V_2 -> V_28 ) , V_59 -> V_73 ,
V_59 -> V_92 , V_83 ) ;
V_84 = V_2 -> V_89 ;
F_50 (data->sg, sg, host->sg_count, i) {
if ( F_51 ( V_73 ) & 0x3 ) {
V_102 = 4 - ( F_51 ( V_73 ) & 0x3 ) ;
V_76 = F_37 ( V_73 , & V_3 ) ;
F_53 ( ( ( long ) V_76 & V_96 ) > ( V_97 - 3 ) ) ;
memcpy ( V_76 , V_84 , V_102 ) ;
F_40 ( V_76 , & V_3 ) ;
V_84 += 4 ;
}
}
}
F_55 ( F_47 ( V_2 -> V_28 ) , V_59 -> V_73 ,
V_59 -> V_92 , V_83 ) ;
}
static T_2 F_59 ( struct V_1 * V_2 , struct V_103 * V_78 )
{
T_2 V_104 ;
struct V_82 * V_59 = V_78 -> V_59 ;
unsigned V_105 , V_106 ;
if ( V_2 -> V_14 & V_107 )
return 0xE ;
if ( ! V_59 && ! V_78 -> V_108 )
return 0xE ;
if ( ! V_59 )
V_105 = V_78 -> V_108 * 1000 ;
else
V_105 = V_59 -> V_109 / 1000 +
V_59 -> V_110 / V_2 -> clock ;
if ( V_2 -> V_14 & V_111 )
V_2 -> V_112 = V_2 -> clock / 1000 ;
F_35 ( ! V_2 -> V_112 ) ;
V_104 = 0 ;
V_106 = ( 1 << 13 ) * 1000 / V_2 -> V_112 ;
while ( V_106 < V_105 ) {
V_104 ++ ;
V_106 <<= 1 ;
if ( V_104 >= 0xF )
break;
}
if ( V_104 >= 0xF ) {
F_2 ( V_113 L_20 ,
F_14 ( V_2 -> V_28 ) , V_78 -> V_114 ) ;
V_104 = 0xE ;
}
return V_104 ;
}
static void F_60 ( struct V_1 * V_2 )
{
T_1 V_115 = V_116 | V_117 ;
T_1 V_118 = V_119 | V_120 ;
if ( V_2 -> V_3 & V_121 )
F_3 ( V_2 , V_115 , V_118 ) ;
else
F_3 ( V_2 , V_118 , V_115 ) ;
}
static void F_61 ( struct V_1 * V_2 , struct V_103 * V_78 )
{
T_2 V_104 ;
T_2 V_45 ;
struct V_82 * V_59 = V_78 -> V_59 ;
int V_122 ;
F_53 ( V_2 -> V_59 ) ;
if ( V_59 || ( V_78 -> V_3 & V_123 ) ) {
V_104 = F_59 ( V_2 , V_78 ) ;
F_12 ( V_2 , V_104 , V_124 ) ;
}
if ( ! V_59 )
return;
F_35 ( V_59 -> V_60 * V_59 -> V_66 > 524288 ) ;
F_35 ( V_59 -> V_60 > V_2 -> V_28 -> V_125 ) ;
F_35 ( V_59 -> V_66 > 65535 ) ;
V_2 -> V_59 = V_59 ;
V_2 -> V_126 = 0 ;
V_2 -> V_59 -> V_127 = 0 ;
if ( V_2 -> V_3 & ( V_128 | V_4 ) )
V_2 -> V_3 |= V_121 ;
if ( V_2 -> V_3 & V_121 ) {
int V_129 , V_86 ;
struct V_72 * V_73 ;
V_129 = 0 ;
if ( V_2 -> V_3 & V_4 ) {
if ( V_2 -> V_14 & V_130 )
V_129 = 1 ;
} else {
if ( V_2 -> V_14 & V_131 )
V_129 = 1 ;
}
if ( F_62 ( V_129 ) ) {
F_50 (data->sg, sg, data->sg_len, i) {
if ( V_73 -> V_62 & 0x3 ) {
F_26 ( L_21
L_22 ,
V_73 -> V_62 ) ;
V_2 -> V_3 &= ~ V_121 ;
break;
}
}
}
}
if ( V_2 -> V_3 & V_121 ) {
int V_129 , V_86 ;
struct V_72 * V_73 ;
V_129 = 0 ;
if ( V_2 -> V_3 & V_4 ) {
if ( V_2 -> V_14 & V_130 )
V_129 = 1 ;
} else {
if ( V_2 -> V_14 & V_132 )
V_129 = 1 ;
}
if ( F_62 ( V_129 ) ) {
F_50 (data->sg, sg, data->sg_len, i) {
if ( V_73 -> V_75 & 0x3 ) {
F_26 ( L_21
L_23 ) ;
V_2 -> V_3 &= ~ V_121 ;
break;
}
}
}
}
if ( V_2 -> V_3 & V_121 ) {
if ( V_2 -> V_3 & V_4 ) {
V_122 = F_45 ( V_2 , V_59 ) ;
if ( V_122 ) {
F_53 ( 1 ) ;
V_2 -> V_3 &= ~ V_121 ;
} else {
F_5 ( V_2 , V_2 -> V_99 ,
V_133 ) ;
}
} else {
int V_134 ;
V_134 = F_49 ( F_47 ( V_2 -> V_28 ) ,
V_59 -> V_73 , V_59 -> V_92 ,
( V_59 -> V_3 & V_67 ) ?
V_87 :
V_88 ) ;
if ( V_134 == 0 ) {
F_53 ( 1 ) ;
V_2 -> V_3 &= ~ V_121 ;
} else {
F_53 ( V_134 != 1 ) ;
F_5 ( V_2 , F_51 ( V_59 -> V_73 ) ,
V_135 ) ;
}
}
}
if ( V_2 -> V_136 >= V_137 ) {
V_45 = F_13 ( V_2 , V_46 ) ;
V_45 &= ~ V_138 ;
if ( ( V_2 -> V_3 & V_121 ) &&
( V_2 -> V_3 & V_4 ) )
V_45 |= V_139 ;
else
V_45 |= V_140 ;
F_12 ( V_2 , V_45 , V_46 ) ;
}
if ( ! ( V_2 -> V_3 & V_121 ) ) {
int V_3 ;
V_3 = V_141 ;
if ( V_2 -> V_59 -> V_3 & V_67 )
V_3 |= V_142 ;
else
V_3 |= V_143 ;
F_63 ( & V_2 -> V_61 , V_59 -> V_73 , V_59 -> V_92 , V_3 ) ;
V_2 -> V_66 = V_59 -> V_66 ;
}
F_60 ( V_2 ) ;
F_64 ( V_2 , F_65 ( V_144 ,
V_59 -> V_60 ) , V_145 ) ;
F_64 ( V_2 , V_59 -> V_66 , V_146 ) ;
}
static void F_66 ( struct V_1 * V_2 ,
struct V_103 * V_78 )
{
T_7 V_147 ;
struct V_82 * V_59 = V_78 -> V_59 ;
if ( V_59 == NULL )
return;
F_53 ( ! V_2 -> V_59 ) ;
V_147 = V_148 ;
if ( F_67 ( V_78 -> V_114 ) || V_59 -> V_66 > 1 ) {
V_147 |= V_149 ;
if ( ! V_2 -> V_150 -> V_151 && ( V_2 -> V_3 & V_152 ) )
V_147 |= V_153 ;
else if ( V_2 -> V_150 -> V_151 && ( V_2 -> V_3 & V_154 ) ) {
V_147 |= V_155 ;
F_5 ( V_2 , V_2 -> V_150 -> V_151 -> V_156 , V_157 ) ;
}
}
if ( V_59 -> V_3 & V_67 )
V_147 |= V_158 ;
if ( V_2 -> V_3 & V_121 )
V_147 |= V_159 ;
F_64 ( V_2 , V_147 , V_160 ) ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_82 * V_59 ;
F_35 ( ! V_2 -> V_59 ) ;
V_59 = V_2 -> V_59 ;
V_2 -> V_59 = NULL ;
if ( V_2 -> V_3 & V_121 ) {
if ( V_2 -> V_3 & V_4 )
F_57 ( V_2 , V_59 ) ;
else {
F_55 ( F_47 ( V_2 -> V_28 ) , V_59 -> V_73 ,
V_59 -> V_92 , ( V_59 -> V_3 & V_67 ) ?
V_87 : V_88 ) ;
}
}
if ( V_59 -> error )
V_59 -> V_127 = 0 ;
else
V_59 -> V_127 = V_59 -> V_60 * V_59 -> V_66 ;
if ( V_59 -> V_161 &&
( V_59 -> error ||
! V_2 -> V_150 -> V_151 ) ) {
if ( V_59 -> error ) {
F_11 ( V_2 , V_32 ) ;
F_11 ( V_2 , V_33 ) ;
}
F_69 ( V_2 , V_59 -> V_161 ) ;
} else
F_70 ( & V_2 -> V_162 ) ;
}
static void F_69 ( struct V_1 * V_2 , struct V_103 * V_78 )
{
int V_3 ;
T_1 V_16 ;
unsigned long V_17 ;
F_53 ( V_2 -> V_78 ) ;
V_17 = 10 ;
V_16 = V_163 ;
if ( ( V_78 -> V_59 != NULL ) || ( V_78 -> V_3 & V_123 ) )
V_16 |= V_164 ;
if ( V_2 -> V_150 -> V_59 && ( V_78 == V_2 -> V_150 -> V_59 -> V_161 ) )
V_16 &= ~ V_164 ;
while ( F_4 ( V_2 , V_20 ) & V_16 ) {
if ( V_17 == 0 ) {
F_2 ( V_27 L_24
L_25 , F_14 ( V_2 -> V_28 ) ) ;
F_1 ( V_2 ) ;
V_78 -> error = - V_165 ;
F_70 ( & V_2 -> V_162 ) ;
return;
}
V_17 -- ;
F_15 ( 1 ) ;
}
F_71 ( & V_2 -> V_166 , V_167 + 10 * V_168 ) ;
V_2 -> V_78 = V_78 ;
F_61 ( V_2 , V_78 ) ;
F_5 ( V_2 , V_78 -> V_156 , V_169 ) ;
F_66 ( V_2 , V_78 ) ;
if ( ( V_78 -> V_3 & V_170 ) && ( V_78 -> V_3 & V_123 ) ) {
F_2 ( V_27 L_26 ,
F_14 ( V_2 -> V_28 ) ) ;
V_78 -> error = - V_101 ;
F_70 ( & V_2 -> V_162 ) ;
return;
}
if ( ! ( V_78 -> V_3 & V_171 ) )
V_3 = V_172 ;
else if ( V_78 -> V_3 & V_170 )
V_3 = V_173 ;
else if ( V_78 -> V_3 & V_123 )
V_3 = V_174 ;
else
V_3 = V_175 ;
if ( V_78 -> V_3 & V_176 )
V_3 |= V_177 ;
if ( V_78 -> V_3 & V_178 )
V_3 |= V_179 ;
if ( V_78 -> V_59 || ( V_78 -> V_114 == V_180 ) )
V_3 |= V_181 ;
F_64 ( V_2 , F_72 ( V_78 -> V_114 , V_3 ) , V_182 ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
int V_86 ;
F_35 ( V_2 -> V_78 == NULL ) ;
if ( V_2 -> V_78 -> V_3 & V_171 ) {
if ( V_2 -> V_78 -> V_3 & V_170 ) {
for ( V_86 = 0 ; V_86 < 4 ; V_86 ++ ) {
V_2 -> V_78 -> V_183 [ V_86 ] = F_4 ( V_2 ,
V_184 + ( 3 - V_86 ) * 4 ) << 8 ;
if ( V_86 != 3 )
V_2 -> V_78 -> V_183 [ V_86 ] |=
F_13 ( V_2 ,
V_184 + ( 3 - V_86 ) * 4 - 1 ) ;
}
} else {
V_2 -> V_78 -> V_183 [ 0 ] = F_4 ( V_2 , V_184 ) ;
}
}
V_2 -> V_78 -> error = 0 ;
if ( V_2 -> V_78 == V_2 -> V_150 -> V_151 ) {
V_2 -> V_78 = NULL ;
F_69 ( V_2 , V_2 -> V_150 -> V_78 ) ;
} else {
if ( V_2 -> V_59 && V_2 -> V_126 )
F_68 ( V_2 ) ;
if ( ! V_2 -> V_78 -> V_59 )
F_70 ( & V_2 -> V_162 ) ;
V_2 -> V_78 = NULL ;
}
}
static void F_74 ( struct V_1 * V_2 , unsigned int clock )
{
int div = 0 ;
T_7 V_185 = 0 ;
unsigned long V_17 ;
if ( clock == V_2 -> clock )
return;
if ( V_2 -> V_23 -> V_186 ) {
V_2 -> V_23 -> V_186 ( V_2 , clock ) ;
if ( V_2 -> V_14 & V_187 )
return;
}
F_64 ( V_2 , 0 , V_188 ) ;
if ( clock == 0 )
goto V_189;
if ( V_2 -> V_136 >= V_190 ) {
if ( V_2 -> V_191 ) {
T_7 V_45 ;
V_45 = F_75 ( V_2 , V_192 ) ;
if ( ! ( V_45 & V_193 ) ) {
for ( div = 1 ; div <= 1024 ; div ++ ) {
if ( ( ( V_2 -> V_194 * V_2 -> V_191 ) /
div ) <= clock )
break;
}
V_185 = V_195 ;
div -- ;
}
} else {
if ( V_2 -> V_194 <= clock )
div = 1 ;
else {
for ( div = 2 ; div < V_196 ;
div += 2 ) {
if ( ( V_2 -> V_194 / div ) <= clock )
break;
}
}
div >>= 1 ;
}
} else {
for ( div = 1 ; div < V_197 ; div *= 2 ) {
if ( ( V_2 -> V_194 / div ) <= clock )
break;
}
div >>= 1 ;
}
V_185 |= ( div & V_198 ) << V_199 ;
V_185 |= ( ( div & V_200 ) >> V_201 )
<< V_202 ;
V_185 |= V_203 ;
F_64 ( V_2 , V_185 , V_188 ) ;
V_17 = 20 ;
while ( ! ( ( V_185 = F_75 ( V_2 , V_188 ) )
& V_204 ) ) {
if ( V_17 == 0 ) {
F_2 ( V_27 L_27
L_28 , F_14 ( V_2 -> V_28 ) ) ;
F_1 ( V_2 ) ;
return;
}
V_17 -- ;
F_15 ( 1 ) ;
}
V_185 |= V_205 ;
F_64 ( V_2 , V_185 , V_188 ) ;
V_189:
V_2 -> clock = clock ;
}
static void F_76 ( struct V_1 * V_2 , unsigned short V_206 )
{
T_2 V_207 = 0 ;
if ( V_206 != ( unsigned short ) - 1 ) {
switch ( 1 << V_206 ) {
case V_208 :
V_207 = V_209 ;
break;
case V_210 :
case V_211 :
V_207 = V_212 ;
break;
case V_213 :
case V_214 :
V_207 = V_215 ;
break;
default:
F_29 () ;
}
}
if ( V_2 -> V_207 == V_207 )
return;
V_2 -> V_207 = V_207 ;
if ( V_207 == 0 ) {
F_12 ( V_2 , 0 , V_216 ) ;
return;
}
if ( ! ( V_2 -> V_14 & V_217 ) )
F_12 ( V_2 , 0 , V_216 ) ;
if ( V_2 -> V_14 & V_218 )
F_12 ( V_2 , V_207 , V_216 ) ;
V_207 |= V_219 ;
F_12 ( V_2 , V_207 , V_216 ) ;
if ( V_2 -> V_14 & V_220 )
F_15 ( 10 ) ;
}
static void F_77 ( struct V_221 * V_28 , struct V_222 * V_150 )
{
struct V_1 * V_2 ;
bool V_223 ;
unsigned long V_3 ;
V_2 = F_78 ( V_28 ) ;
F_23 ( & V_2 -> V_52 , V_3 ) ;
F_53 ( V_2 -> V_150 != NULL ) ;
#ifndef F_79
F_19 ( V_2 ) ;
#endif
if ( ! V_150 -> V_151 && ( V_2 -> V_3 & V_152 ) ) {
if ( V_150 -> V_161 ) {
V_150 -> V_59 -> V_161 = NULL ;
V_150 -> V_161 = NULL ;
}
}
V_2 -> V_150 = V_150 ;
if ( V_2 -> V_14 & V_15 )
V_223 = true ;
else
V_223 = F_4 ( V_2 , V_20 ) &
V_21 ;
if ( ! V_223 || V_2 -> V_3 & V_224 ) {
V_2 -> V_150 -> V_78 -> error = - V_225 ;
F_70 ( & V_2 -> V_162 ) ;
} else {
T_1 V_226 ;
V_226 = F_4 ( V_2 , V_20 ) ;
if ( ( V_2 -> V_3 & V_227 ) &&
! ( V_226 & ( V_228 | V_229 ) ) ) {
F_24 ( & V_2 -> V_52 , V_3 ) ;
F_80 ( V_28 ) ;
F_23 ( & V_2 -> V_52 , V_3 ) ;
V_2 -> V_150 = V_150 ;
}
if ( V_150 -> V_151 && ! ( V_2 -> V_3 & V_154 ) )
F_69 ( V_2 , V_150 -> V_151 ) ;
else
F_69 ( V_2 , V_150 -> V_78 ) ;
}
F_81 () ;
F_24 ( & V_2 -> V_52 , V_3 ) ;
}
static void F_17 ( struct V_221 * V_28 , struct V_230 * V_44 )
{
struct V_1 * V_2 ;
unsigned long V_3 ;
T_2 V_45 ;
V_2 = F_78 ( V_28 ) ;
F_23 ( & V_2 -> V_52 , V_3 ) ;
if ( V_2 -> V_3 & V_224 )
goto V_189;
if ( V_44 -> V_231 == V_232 ) {
F_5 ( V_2 , 0 , V_9 ) ;
F_18 ( V_2 ) ;
}
F_74 ( V_2 , V_44 -> clock ) ;
if ( V_44 -> V_231 == V_232 )
F_76 ( V_2 , - 1 ) ;
else
F_76 ( V_2 , V_44 -> V_233 ) ;
if ( V_2 -> V_23 -> V_234 )
V_2 -> V_23 -> V_234 ( V_2 , V_44 -> V_231 ) ;
if ( V_2 -> V_23 -> V_235 )
V_2 -> V_23 -> V_235 ( V_2 , V_44 -> V_236 ) ;
else {
V_45 = F_13 ( V_2 , V_46 ) ;
if ( V_44 -> V_236 == V_237 ) {
V_45 &= ~ V_238 ;
if ( V_2 -> V_136 >= V_190 )
V_45 |= V_239 ;
} else {
if ( V_2 -> V_136 >= V_190 )
V_45 &= ~ V_239 ;
if ( V_44 -> V_236 == V_240 )
V_45 |= V_238 ;
else
V_45 &= ~ V_238 ;
}
F_12 ( V_2 , V_45 , V_46 ) ;
}
V_45 = F_13 ( V_2 , V_46 ) ;
if ( ( V_44 -> V_241 == V_242 ||
V_44 -> V_241 == V_243 )
&& ! ( V_2 -> V_14 & V_244 ) )
V_45 |= V_245 ;
else
V_45 &= ~ V_245 ;
if ( V_2 -> V_136 >= V_190 ) {
T_7 V_185 , V_246 ;
unsigned int clock ;
if ( ( V_44 -> V_241 == V_247 ) ||
( V_44 -> V_241 == V_248 ) ||
( V_44 -> V_241 == V_249 ) ||
( V_44 -> V_241 == V_250 ) ||
( V_44 -> V_241 == V_251 ) )
V_45 |= V_245 ;
V_246 = F_75 ( V_2 , V_192 ) ;
if ( ! ( V_246 & V_193 ) ) {
F_12 ( V_2 , V_45 , V_46 ) ;
V_246 &= ~ V_252 ;
if ( V_44 -> V_253 == V_254 )
V_246 |= V_255 ;
else if ( V_44 -> V_253 == V_256 )
V_246 |= V_257 ;
F_64 ( V_2 , V_246 , V_192 ) ;
} else {
V_185 = F_75 ( V_2 , V_188 ) ;
V_185 &= ~ V_205 ;
F_64 ( V_2 , V_185 , V_188 ) ;
F_12 ( V_2 , V_45 , V_46 ) ;
clock = V_2 -> clock ;
V_2 -> clock = 0 ;
F_74 ( V_2 , clock ) ;
}
V_185 = F_75 ( V_2 , V_188 ) ;
V_185 &= ~ V_205 ;
F_64 ( V_2 , V_185 , V_188 ) ;
if ( V_2 -> V_23 -> V_258 )
V_2 -> V_23 -> V_258 ( V_2 , V_44 -> V_241 ) ;
else {
V_246 = F_75 ( V_2 , V_192 ) ;
V_246 &= ~ V_259 ;
if ( V_44 -> V_241 == V_251 )
V_246 |= V_260 ;
else if ( V_44 -> V_241 == V_250 )
V_246 |= V_261 ;
else if ( V_44 -> V_241 == V_247 )
V_246 |= V_262 ;
else if ( V_44 -> V_241 == V_248 )
V_246 |= V_263 ;
else if ( V_44 -> V_241 == V_249 )
V_246 |= V_264 ;
F_64 ( V_2 , V_246 , V_192 ) ;
}
clock = V_2 -> clock ;
V_2 -> clock = 0 ;
F_74 ( V_2 , clock ) ;
} else
F_12 ( V_2 , V_45 , V_46 ) ;
if( V_2 -> V_14 & V_265 )
F_11 ( V_2 , V_32 | V_33 ) ;
V_189:
F_81 () ;
F_24 ( & V_2 -> V_52 , V_3 ) ;
}
static int F_82 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
int V_266 ;
F_23 ( & V_2 -> V_52 , V_3 ) ;
if ( V_2 -> V_3 & V_224 )
V_266 = 0 ;
else if ( V_2 -> V_23 -> V_267 )
V_266 = V_2 -> V_23 -> V_267 ( V_2 ) ;
else
V_266 = ! ( F_4 ( V_2 , V_20 )
& V_268 ) ;
F_24 ( & V_2 -> V_52 , V_3 ) ;
return V_2 -> V_14 & V_269 ?
! V_266 : V_266 ;
}
static int F_83 ( struct V_221 * V_28 )
{
struct V_1 * V_2 ;
int V_86 , V_270 ;
V_2 = F_78 ( V_28 ) ;
if ( ! ( V_2 -> V_14 & V_271 ) )
return F_82 ( V_2 ) ;
V_270 = 0 ;
for ( V_86 = 0 ; V_86 < V_272 ; V_86 ++ ) {
if ( F_82 ( V_2 ) ) {
if ( ++ V_270 > V_272 / 2 )
return 1 ;
}
F_84 ( 30 ) ;
}
return 0 ;
}
static void F_85 ( struct V_221 * V_28 , int V_11 )
{
struct V_1 * V_2 ;
unsigned long V_3 ;
V_2 = F_78 ( V_28 ) ;
F_23 ( & V_2 -> V_52 , V_3 ) ;
if ( V_2 -> V_3 & V_224 )
goto V_189;
if ( V_11 )
F_6 ( V_2 , V_273 ) ;
else
F_7 ( V_2 , V_273 ) ;
V_189:
F_81 () ;
F_24 ( & V_2 -> V_52 , V_3 ) ;
}
static int F_86 ( struct V_221 * V_28 ,
struct V_230 * V_44 )
{
struct V_1 * V_2 ;
T_2 V_207 ;
T_7 V_185 , V_45 ;
T_1 V_226 ;
V_2 = F_78 ( V_28 ) ;
if ( V_2 -> V_136 < V_190 )
return 0 ;
V_45 = F_75 ( V_2 , V_192 ) ;
if ( V_44 -> V_274 == V_275 ) {
V_45 &= ~ V_276 ;
F_64 ( V_2 , V_45 , V_192 ) ;
F_87 ( 5000 , 5500 ) ;
V_45 = F_75 ( V_2 , V_192 ) ;
if ( ! ( V_45 & V_276 ) )
return 0 ;
else {
F_2 (KERN_INFO DRIVER_NAME L_29
L_30 ) ;
return - V_165 ;
}
} else if ( ! ( V_45 & V_276 ) &&
( V_44 -> V_274 == V_277 ) ) {
V_185 = F_75 ( V_2 , V_188 ) ;
V_185 &= ~ V_205 ;
F_64 ( V_2 , V_185 , V_188 ) ;
V_226 = F_4 ( V_2 , V_20 ) ;
if ( ! ( ( V_226 & V_278 ) >>
V_279 ) ) {
V_45 |= V_276 ;
F_64 ( V_2 , V_45 , V_192 ) ;
F_87 ( 5000 , 5500 ) ;
V_45 = F_75 ( V_2 , V_192 ) ;
if ( V_45 & V_276 ) {
V_185 = F_75 ( V_2 , V_188 ) ;
V_185 |= V_205 ;
F_64 ( V_2 , V_185 , V_188 ) ;
F_87 ( 1000 , 1500 ) ;
V_226 = F_4 ( V_2 ,
V_20 ) ;
if ( ( V_226 & V_278 ) ==
V_278 )
return 0 ;
}
}
V_207 = F_13 ( V_2 , V_216 ) ;
V_207 &= ~ V_219 ;
F_12 ( V_2 , V_207 , V_216 ) ;
F_87 ( 1000 , 1500 ) ;
V_207 |= V_219 ;
F_12 ( V_2 , V_207 , V_216 ) ;
F_2 (KERN_INFO DRIVER_NAME L_31
L_32 ) ;
return - V_280 ;
} else
return 0 ;
}
static int F_80 ( struct V_221 * V_28 )
{
struct V_1 * V_2 ;
T_7 V_45 ;
T_1 V_7 ;
int V_281 = V_282 ;
unsigned long V_17 ;
int V_283 = 0 ;
V_2 = F_78 ( V_28 ) ;
F_88 ( V_2 -> V_284 ) ;
F_89 ( & V_2 -> V_52 ) ;
V_45 = F_75 ( V_2 , V_192 ) ;
if ( ( ( V_45 & V_259 ) == V_263 ) ||
( ( ( V_45 & V_259 ) == V_262 ) &&
( V_2 -> V_3 & V_285 ) ) )
V_45 |= V_286 ;
else {
F_90 ( & V_2 -> V_52 ) ;
F_91 ( V_2 -> V_284 ) ;
return 0 ;
}
F_64 ( V_2 , V_45 , V_192 ) ;
V_7 = F_4 ( V_2 , V_8 ) ;
F_3 ( V_2 , V_7 , V_116 ) ;
V_17 = 150 ;
do {
struct V_103 V_78 = { 0 } ;
struct V_222 V_150 = { 0 } ;
if ( ! V_281 && ! V_17 )
break;
V_78 . V_114 = V_180 ;
V_78 . V_156 = 0 ;
V_78 . V_3 = V_287 | V_288 ;
V_78 . V_289 = 0 ;
V_78 . V_59 = NULL ;
V_78 . error = 0 ;
V_150 . V_78 = & V_78 ;
V_2 -> V_150 = & V_150 ;
F_64 ( V_2 , F_65 ( 7 , 64 ) , V_145 ) ;
F_64 ( V_2 , V_158 , V_160 ) ;
F_69 ( V_2 , & V_78 ) ;
V_2 -> V_78 = NULL ;
V_2 -> V_150 = NULL ;
F_90 ( & V_2 -> V_52 ) ;
F_91 ( V_2 -> V_284 ) ;
F_92 ( V_2 -> V_290 ,
( V_2 -> V_291 == 1 ) ,
F_93 ( 50 ) ) ;
F_88 ( V_2 -> V_284 ) ;
F_89 ( & V_2 -> V_52 ) ;
if ( ! V_2 -> V_291 ) {
F_2 (KERN_INFO DRIVER_NAME L_33
L_34
L_35
L_36 ) ;
V_45 = F_75 ( V_2 , V_192 ) ;
V_45 &= ~ V_292 ;
V_45 &= ~ V_286 ;
F_64 ( V_2 , V_45 , V_192 ) ;
V_283 = - V_165 ;
goto V_189;
}
V_2 -> V_291 = 0 ;
V_45 = F_75 ( V_2 , V_192 ) ;
V_281 -- ;
V_17 -- ;
F_15 ( 1 ) ;
} while ( V_45 & V_286 );
if ( ! V_281 || ! V_17 ) {
V_45 &= ~ V_292 ;
F_64 ( V_2 , V_45 , V_192 ) ;
} else {
if ( ! ( V_45 & V_292 ) ) {
F_2 (KERN_INFO DRIVER_NAME L_37
L_38
L_39 ) ;
V_283 = - V_165 ;
}
}
V_189:
if ( ! ( V_2 -> V_3 & V_227 ) && V_2 -> V_293 &&
( V_2 -> V_294 == V_295 ) ) {
F_71 ( & V_2 -> V_296 , V_167 +
V_2 -> V_293 * V_168 ) ;
V_28 -> V_297 = ( 4 * 1024 * 1024 ) / V_28 -> V_125 ;
} else {
V_2 -> V_3 &= ~ V_227 ;
if ( V_2 -> V_294 == V_295 )
F_71 ( & V_2 -> V_296 , V_167 +
V_2 -> V_293 * V_168 ) ;
}
if ( V_283 && V_2 -> V_293 &&
V_2 -> V_294 == V_295 )
V_283 = 0 ;
F_3 ( V_2 , V_116 , V_7 ) ;
F_90 ( & V_2 -> V_52 ) ;
F_91 ( V_2 -> V_284 ) ;
return V_283 ;
}
static void F_94 ( struct V_221 * V_28 , bool V_11 )
{
struct V_1 * V_2 ;
T_7 V_45 ;
unsigned long V_3 ;
V_2 = F_78 ( V_28 ) ;
if ( V_2 -> V_136 < V_190 )
return;
F_23 ( & V_2 -> V_52 , V_3 ) ;
V_45 = F_75 ( V_2 , V_192 ) ;
if ( V_11 && ! ( V_45 & V_193 ) ) {
V_45 |= V_193 ;
F_64 ( V_2 , V_45 , V_192 ) ;
} else if ( ! V_11 && ( V_45 & V_193 ) ) {
V_45 &= ~ V_193 ;
F_64 ( V_2 , V_45 , V_192 ) ;
}
F_24 ( & V_2 -> V_52 , V_3 ) ;
}
static void F_95 ( unsigned long V_298 )
{
struct V_1 * V_2 ;
unsigned long V_3 ;
V_2 = (struct V_1 * ) V_298 ;
F_23 ( & V_2 -> V_52 , V_3 ) ;
if ( ! ( F_4 ( V_2 , V_20 ) & V_21 ) ) {
if ( V_2 -> V_150 ) {
F_2 ( V_27 L_40 ,
F_14 ( V_2 -> V_28 ) ) ;
F_2 ( V_27 L_41 ,
F_14 ( V_2 -> V_28 ) ) ;
F_11 ( V_2 , V_32 ) ;
F_11 ( V_2 , V_33 ) ;
V_2 -> V_150 -> V_78 -> error = - V_225 ;
F_70 ( & V_2 -> V_162 ) ;
}
}
F_24 ( & V_2 -> V_52 , V_3 ) ;
F_96 ( V_2 -> V_28 , F_93 ( 200 ) ) ;
}
static void F_97 ( unsigned long V_298 )
{
struct V_1 * V_2 ;
unsigned long V_3 ;
struct V_222 * V_150 ;
V_2 = (struct V_1 * ) V_298 ;
if ( ! V_2 -> V_150 )
return;
F_23 ( & V_2 -> V_52 , V_3 ) ;
F_98 ( & V_2 -> V_166 ) ;
if ( V_2 -> V_136 >= V_190 )
F_98 ( & V_2 -> V_296 ) ;
V_150 = V_2 -> V_150 ;
if ( ! ( V_2 -> V_3 & V_224 ) &&
( ( V_150 -> V_78 && V_150 -> V_78 -> error ) ||
( V_150 -> V_59 && ( V_150 -> V_59 -> error ||
( V_150 -> V_59 -> V_161 && V_150 -> V_59 -> V_161 -> error ) ) ) ||
( V_2 -> V_14 & V_299 ) ) ) {
if ( V_2 -> V_14 & V_300 ) {
unsigned int clock ;
clock = V_2 -> clock ;
V_2 -> clock = 0 ;
F_74 ( V_2 , clock ) ;
}
F_11 ( V_2 , V_32 ) ;
F_11 ( V_2 , V_33 ) ;
}
V_2 -> V_150 = NULL ;
V_2 -> V_78 = NULL ;
V_2 -> V_59 = NULL ;
#ifndef F_79
F_20 ( V_2 ) ;
#endif
F_81 () ;
F_24 ( & V_2 -> V_52 , V_3 ) ;
F_99 ( V_2 -> V_28 , V_150 ) ;
}
static void F_100 ( unsigned long V_59 )
{
struct V_1 * V_2 ;
unsigned long V_3 ;
V_2 = (struct V_1 * ) V_59 ;
F_23 ( & V_2 -> V_52 , V_3 ) ;
if ( V_2 -> V_150 ) {
F_2 ( V_27 L_42
L_43 , F_14 ( V_2 -> V_28 ) ) ;
F_1 ( V_2 ) ;
if ( V_2 -> V_59 ) {
V_2 -> V_59 -> error = - V_301 ;
F_68 ( V_2 ) ;
} else {
if ( V_2 -> V_78 )
V_2 -> V_78 -> error = - V_301 ;
else
V_2 -> V_150 -> V_78 -> error = - V_301 ;
F_70 ( & V_2 -> V_162 ) ;
}
}
F_81 () ;
F_24 ( & V_2 -> V_52 , V_3 ) ;
}
static void F_101 ( unsigned long V_59 )
{
struct V_1 * V_2 ;
unsigned long V_3 ;
V_2 = (struct V_1 * ) V_59 ;
F_23 ( & V_2 -> V_52 , V_3 ) ;
V_2 -> V_3 |= V_227 ;
F_24 ( & V_2 -> V_52 , V_3 ) ;
}
static void F_102 ( struct V_1 * V_2 , T_1 V_302 )
{
F_35 ( V_302 == 0 ) ;
if ( ! V_2 -> V_78 ) {
F_2 ( V_27 L_44
L_45 ,
F_14 ( V_2 -> V_28 ) , ( unsigned ) V_302 ) ;
F_1 ( V_2 ) ;
return;
}
if ( V_302 & V_41 )
V_2 -> V_78 -> error = - V_301 ;
else if ( V_302 & ( V_40 | V_39 |
V_38 ) )
V_2 -> V_78 -> error = - V_303 ;
if ( V_2 -> V_78 -> error ) {
F_70 ( & V_2 -> V_162 ) ;
return;
}
if ( V_2 -> V_78 -> V_3 & V_123 ) {
if ( V_2 -> V_78 -> V_59 )
F_26 ( L_46
L_47 ) ;
else if ( ! ( V_2 -> V_14 & V_304 ) )
return;
}
if ( V_302 & V_43 )
F_73 ( V_2 ) ;
}
static void F_103 ( struct V_1 * V_2 )
{
const char * V_305 = F_14 ( V_2 -> V_28 ) ;
T_2 * V_77 = V_2 -> V_94 ;
T_4 * V_306 ;
T_5 * V_55 ;
T_2 V_307 ;
F_1 ( V_2 ) ;
while ( true ) {
V_306 = ( T_4 * ) ( V_77 + 4 ) ;
V_55 = ( T_5 * ) ( V_77 + 2 ) ;
V_307 = * V_77 ;
F_26 ( L_48 ,
V_305 , V_77 , F_104 ( * V_306 ) , F_105 ( * V_55 ) , V_307 ) ;
V_77 += 8 ;
if ( V_307 & 2 )
break;
}
}
static void F_103 ( struct V_1 * V_2 ) { }
static void F_106 ( struct V_1 * V_2 , T_1 V_302 )
{
F_35 ( V_302 == 0 ) ;
if ( V_302 & V_116 ) {
if ( F_107 ( F_75 ( V_2 , V_182 ) ) ==
V_180 ) {
V_2 -> V_291 = 1 ;
F_108 ( & V_2 -> V_290 ) ;
return;
}
}
if ( ! V_2 -> V_59 ) {
if ( V_2 -> V_78 && ( V_2 -> V_78 -> V_3 & V_123 ) ) {
if ( V_302 & V_42 ) {
F_73 ( V_2 ) ;
return;
}
}
F_2 ( V_27 L_49
L_50 ,
F_14 ( V_2 -> V_28 ) , ( unsigned ) V_302 ) ;
F_1 ( V_2 ) ;
return;
}
if ( V_302 & V_37 )
V_2 -> V_59 -> error = - V_301 ;
else if ( V_302 & V_35 )
V_2 -> V_59 -> error = - V_303 ;
else if ( ( V_302 & V_36 ) &&
F_107 ( F_75 ( V_2 , V_182 ) )
!= V_308 )
V_2 -> V_59 -> error = - V_303 ;
else if ( V_302 & V_120 ) {
F_2 ( V_27 L_51 , F_14 ( V_2 -> V_28 ) ) ;
F_103 ( V_2 ) ;
V_2 -> V_59 -> error = - V_165 ;
}
if ( V_2 -> V_59 -> error )
F_68 ( V_2 ) ;
else {
if ( V_302 & ( V_116 | V_117 ) )
F_34 ( V_2 ) ;
if ( V_302 & V_119 ) {
T_1 V_309 , V_310 ;
V_309 = F_51 ( V_2 -> V_59 -> V_73 ) ;
V_310 = V_309 + V_2 -> V_59 -> V_127 ;
V_310 = ( V_310 &
~ ( V_311 - 1 ) ) +
V_311 ;
V_2 -> V_59 -> V_127 = V_310 - V_309 ;
F_26 ( L_52
L_53 ,
F_14 ( V_2 -> V_28 ) , V_309 ,
V_2 -> V_59 -> V_127 , V_310 ) ;
F_5 ( V_2 , V_310 , V_135 ) ;
}
if ( V_302 & V_42 ) {
if ( V_2 -> V_78 ) {
V_2 -> V_126 = 1 ;
} else {
F_68 ( V_2 ) ;
}
}
}
}
static T_8 F_109 ( int V_284 , void * V_312 )
{
T_8 V_313 ;
struct V_1 * V_2 = V_312 ;
T_1 V_302 ;
int V_314 = 0 ;
F_89 ( & V_2 -> V_52 ) ;
V_302 = F_4 ( V_2 , V_315 ) ;
if ( ! V_302 || V_302 == 0xffffffff ) {
V_313 = V_316 ;
goto V_189;
}
F_26 ( L_54 ,
F_14 ( V_2 -> V_28 ) , V_302 ) ;
if ( V_302 & ( V_13 | V_12 ) ) {
F_5 ( V_2 , V_302 & ( V_13 |
V_12 ) , V_315 ) ;
F_70 ( & V_2 -> V_317 ) ;
}
V_302 &= ~ ( V_13 | V_12 ) ;
if ( V_302 & V_318 ) {
F_5 ( V_2 , V_302 & V_318 ,
V_315 ) ;
F_102 ( V_2 , V_302 & V_318 ) ;
}
if ( V_302 & V_319 ) {
F_5 ( V_2 , V_302 & V_319 ,
V_315 ) ;
F_106 ( V_2 , V_302 & V_319 ) ;
}
V_302 &= ~ ( V_318 | V_319 ) ;
V_302 &= ~ V_320 ;
if ( V_302 & V_34 ) {
F_2 ( V_27 L_55 ,
F_14 ( V_2 -> V_28 ) ) ;
F_5 ( V_2 , V_34 , V_315 ) ;
}
V_302 &= ~ V_34 ;
if ( V_302 & V_273 )
V_314 = 1 ;
V_302 &= ~ V_273 ;
if ( V_302 ) {
F_2 ( V_27 L_56 ,
F_14 ( V_2 -> V_28 ) , V_302 ) ;
F_1 ( V_2 ) ;
F_5 ( V_2 , V_302 , V_315 ) ;
}
V_313 = V_321 ;
F_81 () ;
V_189:
F_90 ( & V_2 -> V_52 ) ;
if ( V_314 )
F_110 ( V_2 -> V_28 ) ;
return V_313 ;
}
int F_111 ( struct V_1 * V_2 , T_9 V_322 )
{
int V_122 ;
F_10 ( V_2 ) ;
if ( V_2 -> V_136 >= V_190 && V_2 -> V_293 &&
V_2 -> V_294 == V_295 ) {
V_2 -> V_3 &= ~ V_227 ;
F_71 ( & V_2 -> V_296 , V_167 +
V_2 -> V_293 * V_168 ) ;
}
V_122 = F_112 ( V_2 -> V_28 ) ;
if ( V_122 )
return V_122 ;
F_113 ( V_2 -> V_284 , V_2 ) ;
if ( V_2 -> V_323 )
V_122 = F_114 ( V_2 -> V_323 ) ;
return V_122 ;
}
int F_115 ( struct V_1 * V_2 )
{
int V_122 ;
if ( V_2 -> V_323 ) {
int V_122 = F_116 ( V_2 -> V_323 ) ;
if ( V_122 )
return V_122 ;
}
if ( V_2 -> V_3 & ( V_128 | V_4 ) ) {
if ( V_2 -> V_23 -> V_324 )
V_2 -> V_23 -> V_324 ( V_2 ) ;
}
V_122 = F_117 ( V_2 -> V_284 , F_109 , V_325 ,
F_14 ( V_2 -> V_28 ) , V_2 ) ;
if ( V_122 )
return V_122 ;
F_16 ( V_2 , ( V_2 -> V_28 -> V_326 & V_327 ) ) ;
F_81 () ;
V_122 = F_118 ( V_2 -> V_28 ) ;
F_9 ( V_2 ) ;
if ( ( V_2 -> V_136 >= V_190 ) && V_2 -> V_293 &&
( V_2 -> V_294 == V_295 ) )
V_2 -> V_3 |= V_227 ;
return V_122 ;
}
void F_119 ( struct V_1 * V_2 )
{
T_2 V_328 ;
V_328 = F_13 ( V_2 , V_329 ) ;
V_328 |= V_330 ;
F_12 ( V_2 , V_328 , V_329 ) ;
}
struct V_1 * F_120 ( struct V_331 * V_332 ,
T_3 V_333 )
{
struct V_221 * V_28 ;
struct V_1 * V_2 ;
F_53 ( V_332 == NULL ) ;
V_28 = F_121 ( sizeof( struct V_1 ) + V_333 , V_332 ) ;
if ( ! V_28 )
return F_122 ( - V_334 ) ;
V_2 = F_78 ( V_28 ) ;
V_2 -> V_28 = V_28 ;
return V_2 ;
}
int F_123 ( struct V_1 * V_2 )
{
struct V_221 * V_28 ;
T_1 V_335 [ 2 ] ;
T_1 V_336 ;
unsigned int V_337 ;
int V_122 ;
F_53 ( V_2 == NULL ) ;
if ( V_2 == NULL )
return - V_101 ;
V_28 = V_2 -> V_28 ;
if ( V_338 )
V_2 -> V_14 = V_338 ;
F_11 ( V_2 , V_26 ) ;
V_2 -> V_136 = F_75 ( V_2 , V_339 ) ;
V_2 -> V_136 = ( V_2 -> V_136 & V_340 )
>> V_341 ;
if ( V_2 -> V_136 > V_190 ) {
F_2 ( V_27 L_57
L_58 , F_14 ( V_28 ) ,
V_2 -> V_136 ) ;
}
V_335 [ 0 ] = ( V_2 -> V_14 & V_342 ) ? V_2 -> V_335 :
F_4 ( V_2 , V_343 ) ;
V_335 [ 1 ] = ( V_2 -> V_136 >= V_190 ) ?
F_4 ( V_2 , V_344 ) : 0 ;
if ( V_2 -> V_14 & V_345 )
V_2 -> V_3 |= V_128 ;
else if ( ! ( V_335 [ 0 ] & V_346 ) )
F_26 ( L_59 ) ;
else
V_2 -> V_3 |= V_128 ;
if ( ( V_2 -> V_14 & V_347 ) &&
( V_2 -> V_3 & V_128 ) ) {
F_26 ( L_60 ) ;
V_2 -> V_3 &= ~ V_128 ;
}
if ( ( V_2 -> V_136 >= V_137 ) &&
( V_335 [ 0 ] & V_348 ) )
V_2 -> V_3 |= V_4 ;
if ( ( V_2 -> V_14 & V_349 ) &&
( V_2 -> V_3 & V_4 ) ) {
F_26 ( L_61 ) ;
V_2 -> V_3 &= ~ V_4 ;
}
if ( V_2 -> V_3 & ( V_128 | V_4 ) ) {
if ( V_2 -> V_23 -> V_324 ) {
if ( V_2 -> V_23 -> V_324 ( V_2 ) ) {
F_2 ( V_113 L_62
L_63 ,
F_14 ( V_28 ) ) ;
V_2 -> V_3 &=
~ ( V_128 | V_4 ) ;
}
}
}
if ( V_2 -> V_3 & V_4 ) {
V_2 -> V_94 = F_124 ( ( 128 * 2 + 1 ) * 4 , V_350 ) ;
V_2 -> V_89 = F_124 ( 128 * 4 , V_350 ) ;
if ( ! V_2 -> V_94 || ! V_2 -> V_89 ) {
F_125 ( V_2 -> V_94 ) ;
F_125 ( V_2 -> V_89 ) ;
F_2 ( V_113 L_64
L_65 ,
F_14 ( V_28 ) ) ;
V_2 -> V_3 &= ~ V_4 ;
}
}
if ( ! ( V_2 -> V_3 & ( V_128 | V_4 ) ) ) {
V_2 -> V_351 = F_126 ( 64 ) ;
F_47 ( V_2 -> V_28 ) -> V_351 = & V_2 -> V_351 ;
}
if ( V_2 -> V_136 >= V_190 )
V_2 -> V_194 = ( V_335 [ 0 ] & V_352 )
>> V_353 ;
else
V_2 -> V_194 = ( V_335 [ 0 ] & V_354 )
>> V_353 ;
V_2 -> V_194 *= 1000000 ;
if ( V_2 -> V_194 == 0 || V_2 -> V_14 &
V_355 ) {
if ( ! V_2 -> V_23 -> V_356 ) {
F_2 ( V_27
L_66
L_67 , F_14 ( V_28 ) ) ;
return - V_357 ;
}
V_2 -> V_194 = V_2 -> V_23 -> V_356 ( V_2 ) ;
}
V_2 -> V_112 =
( V_335 [ 0 ] & V_358 ) >> V_359 ;
if ( V_2 -> V_112 == 0 ) {
if ( V_2 -> V_23 -> V_360 ) {
V_2 -> V_112 = V_2 -> V_23 -> V_360 ( V_2 ) ;
} else if ( ! ( V_2 -> V_14 &
V_111 ) ) {
F_2 ( V_27
L_68
L_67 , F_14 ( V_28 ) ) ;
return - V_357 ;
}
}
if ( V_335 [ 0 ] & V_361 )
V_2 -> V_112 *= 1000 ;
V_2 -> V_191 = ( V_335 [ 1 ] & V_362 ) >>
V_363 ;
if ( V_2 -> V_191 )
V_2 -> V_191 += 1 ;
V_28 -> V_23 = & V_364 ;
V_28 -> V_365 = V_2 -> V_194 ;
if ( V_2 -> V_23 -> V_366 )
V_28 -> V_367 = V_2 -> V_23 -> V_366 ( V_2 ) ;
else if ( V_2 -> V_136 >= V_190 ) {
if ( V_2 -> V_191 ) {
V_28 -> V_367 = ( V_2 -> V_194 * V_2 -> V_191 ) / 1024 ;
V_28 -> V_365 = V_2 -> V_194 * V_2 -> V_191 ;
} else
V_28 -> V_367 = V_2 -> V_194 / V_196 ;
} else
V_28 -> V_367 = V_2 -> V_194 / V_197 ;
V_28 -> V_335 |= V_368 | V_369 | V_370 ;
if ( V_2 -> V_14 & V_371 )
V_2 -> V_3 |= V_152 ;
if ( ( V_2 -> V_136 >= V_190 ) &&
( ( V_2 -> V_3 & V_4 ) ||
! ( V_2 -> V_3 & V_128 ) ) ) {
V_2 -> V_3 |= V_154 ;
F_26 ( L_69 , F_14 ( V_28 ) ) ;
} else {
F_26 ( L_70 , F_14 ( V_28 ) ) ;
}
if ( ! ( V_2 -> V_14 & V_372 ) )
V_28 -> V_335 |= V_373 ;
if ( V_335 [ 0 ] & V_374 )
V_28 -> V_335 |= V_375 | V_376 ;
if ( ( V_2 -> V_14 & V_15 ) &&
F_127 ( V_28 ) )
V_28 -> V_335 |= V_377 ;
if ( V_2 -> V_136 >= V_190 )
V_28 -> V_335 |= V_378 | V_379 ;
if ( V_335 [ 1 ] & V_380 )
V_28 -> V_335 |= V_381 | V_382 ;
else if ( V_335 [ 1 ] & V_383 )
V_28 -> V_335 |= V_382 ;
if ( V_335 [ 1 ] & V_384 )
V_28 -> V_335 |= V_385 ;
if ( V_335 [ 1 ] & V_386 )
V_2 -> V_3 |= V_285 ;
if ( V_335 [ 1 ] & V_387 )
V_28 -> V_335 |= V_388 ;
if ( V_335 [ 1 ] & V_389 )
V_28 -> V_335 |= V_390 ;
if ( V_335 [ 1 ] & V_391 )
V_28 -> V_335 |= V_392 ;
V_2 -> V_293 = ( V_335 [ 1 ] & V_393 ) >>
V_394 ;
if ( V_2 -> V_293 )
V_2 -> V_293 = 1 << ( V_2 -> V_293 - 1 ) ;
V_2 -> V_294 = ( V_335 [ 1 ] & V_395 ) >>
V_396 ;
V_337 = 0 ;
V_336 = F_4 ( V_2 , V_397 ) ;
if ( V_335 [ 0 ] & V_398 ) {
int V_399 ;
V_337 |= V_213 | V_214 ;
V_399 = ( ( V_336 &
V_400 ) >>
V_401 ) *
V_402 ;
if ( V_399 > 150 )
V_28 -> V_335 |= V_403 ;
}
if ( V_335 [ 0 ] & V_404 ) {
int V_405 ;
V_337 |= V_210 | V_211 ;
V_405 = ( ( V_336 &
V_406 ) >>
V_407 ) *
V_402 ;
if ( V_405 > 150 )
V_28 -> V_335 |= V_408 ;
}
if ( V_335 [ 0 ] & V_409 ) {
int V_410 ;
V_337 |= V_208 ;
V_410 = ( ( V_336 &
V_411 ) >>
V_412 ) *
V_402 ;
if ( V_410 > 150 )
V_28 -> V_335 |= V_413 ;
if ( V_410 >= 800 )
V_28 -> V_335 |= V_414 ;
else if ( V_410 >= 600 )
V_28 -> V_335 |= V_415 ;
else if ( V_410 >= 400 )
V_28 -> V_335 |= V_416 ;
else
V_28 -> V_335 |= V_417 ;
}
V_28 -> V_337 = V_337 ;
V_28 -> V_418 = V_337 ;
if ( V_2 -> V_418 )
V_28 -> V_418 &= V_2 -> V_418 ;
V_28 -> V_419 = V_337 ;
if ( V_2 -> V_419 )
V_28 -> V_419 &= V_2 -> V_419 ;
else
V_28 -> V_419 &= ~ V_208 ;
V_28 -> V_420 = V_337 ;
if ( V_2 -> V_420 )
V_28 -> V_420 &= V_2 -> V_420 ;
if ( V_28 -> V_337 == 0 ) {
F_2 ( V_27 L_71
L_72 , F_14 ( V_28 ) ) ;
return - V_357 ;
}
F_128 ( & V_2 -> V_52 ) ;
if ( V_2 -> V_3 & V_4 )
V_28 -> V_421 = 128 ;
else if ( V_2 -> V_3 & V_128 )
V_28 -> V_421 = 1 ;
else
V_28 -> V_421 = 128 ;
V_28 -> V_422 = 524288 ;
if ( V_2 -> V_3 & V_4 ) {
if ( V_2 -> V_14 & V_423 )
V_28 -> V_424 = 65535 ;
else
V_28 -> V_424 = 65536 ;
} else {
V_28 -> V_424 = V_28 -> V_422 ;
}
if ( V_2 -> V_14 & V_425 ) {
V_28 -> V_125 = 2 ;
} else {
V_28 -> V_125 = ( V_335 [ 0 ] & V_426 ) >>
V_427 ;
if ( V_28 -> V_125 >= 3 ) {
F_2 ( V_113 L_73
L_74 , F_14 ( V_28 ) ) ;
V_28 -> V_125 = 0 ;
}
}
V_28 -> V_125 = 512 << V_28 -> V_125 ;
V_28 -> V_297 = ( V_2 -> V_14 & V_428 ) ? 1 : 65535 ;
F_129 ( & V_2 -> V_317 ,
F_95 , ( unsigned long ) V_2 ) ;
F_129 ( & V_2 -> V_162 ,
F_97 , ( unsigned long ) V_2 ) ;
F_130 ( & V_2 -> V_166 , F_100 , ( unsigned long ) V_2 ) ;
if ( V_2 -> V_136 >= V_190 ) {
F_131 ( & V_2 -> V_290 ) ;
F_132 ( & V_2 -> V_296 ) ;
V_2 -> V_296 . V_59 = ( unsigned long ) V_2 ;
V_2 -> V_296 . V_429 = F_101 ;
}
V_122 = F_117 ( V_2 -> V_284 , F_109 , V_325 ,
F_14 ( V_28 ) , V_2 ) ;
if ( V_122 )
goto V_430;
V_2 -> V_323 = F_133 ( F_47 ( V_28 ) , L_75 ) ;
if ( F_134 ( V_2 -> V_323 ) ) {
F_2 ( V_431 L_76 , F_14 ( V_28 ) ) ;
V_2 -> V_323 = NULL ;
} else {
F_116 ( V_2 -> V_323 ) ;
}
F_16 ( V_2 , 0 ) ;
#ifdef F_135
F_1 ( V_2 ) ;
#endif
#ifdef F_79
snprintf ( V_2 -> V_432 , sizeof( V_2 -> V_432 ) ,
L_77 , F_14 ( V_28 ) ) ;
V_2 -> V_49 . V_305 = V_2 -> V_432 ;
V_2 -> V_49 . V_51 = V_53 ;
V_2 -> V_49 . V_433 = F_14 ( V_28 ) ;
V_2 -> V_49 . V_434 = F_21 ;
V_122 = F_136 ( F_47 ( V_28 ) , & V_2 -> V_49 ) ;
if ( V_122 )
goto V_435;
#endif
F_81 () ;
F_137 ( V_28 ) ;
F_2 ( V_431 L_78 ,
F_14 ( V_28 ) , V_2 -> V_436 , F_138 ( F_47 ( V_28 ) ) ,
( V_2 -> V_3 & V_4 ) ? L_79 :
( V_2 -> V_3 & V_128 ) ? L_80 : L_81 ) ;
F_9 ( V_2 ) ;
return 0 ;
#ifdef F_79
V_435:
F_11 ( V_2 , V_26 ) ;
F_113 ( V_2 -> V_284 , V_2 ) ;
#endif
V_430:
F_139 ( & V_2 -> V_317 ) ;
F_139 ( & V_2 -> V_162 ) ;
return V_122 ;
}
void F_140 ( struct V_1 * V_2 , int V_437 )
{
unsigned long V_3 ;
if ( V_437 ) {
F_23 ( & V_2 -> V_52 , V_3 ) ;
V_2 -> V_3 |= V_224 ;
if ( V_2 -> V_150 ) {
F_2 ( V_27 L_82
L_83 , F_14 ( V_2 -> V_28 ) ) ;
V_2 -> V_150 -> V_78 -> error = - V_225 ;
F_70 ( & V_2 -> V_162 ) ;
}
F_24 ( & V_2 -> V_52 , V_3 ) ;
}
F_10 ( V_2 ) ;
F_141 ( V_2 -> V_28 ) ;
#ifdef F_79
F_142 ( & V_2 -> V_49 ) ;
#endif
if ( ! V_437 )
F_11 ( V_2 , V_26 ) ;
F_113 ( V_2 -> V_284 , V_2 ) ;
F_143 ( & V_2 -> V_166 ) ;
if ( V_2 -> V_136 >= V_190 )
F_143 ( & V_2 -> V_296 ) ;
F_139 ( & V_2 -> V_317 ) ;
F_139 ( & V_2 -> V_162 ) ;
if ( V_2 -> V_323 ) {
F_114 ( V_2 -> V_323 ) ;
F_144 ( V_2 -> V_323 ) ;
}
F_125 ( V_2 -> V_94 ) ;
F_125 ( V_2 -> V_89 ) ;
V_2 -> V_94 = NULL ;
V_2 -> V_89 = NULL ;
}
void F_145 ( struct V_1 * V_2 )
{
F_146 ( V_2 -> V_28 ) ;
}
static int T_10 F_147 ( void )
{
F_2 (KERN_INFO DRIVER_NAME
L_84 ) ;
F_2 (KERN_INFO DRIVER_NAME L_85 ) ;
return 0 ;
}
static void T_11 F_148 ( void )
{
}

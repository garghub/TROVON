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
T_1 V_12 , V_10 ;
if ( V_2 -> V_13 & V_14 )
return;
V_12 = F_4 ( V_2 , V_15 ) &
V_16 ;
V_10 = V_12 ? V_17 : V_18 ;
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
static void F_11 ( struct V_1 * V_2 , T_2 V_19 )
{
unsigned long V_20 ;
T_1 V_21 ( V_7 ) ;
if ( V_2 -> V_13 & V_22 ) {
if ( ! ( F_4 ( V_2 , V_15 ) &
V_16 ) )
return;
}
if ( V_2 -> V_13 & V_23 )
V_7 = F_4 ( V_2 , V_8 ) ;
if ( V_2 -> V_24 -> V_25 )
V_2 -> V_24 -> V_25 ( V_2 , V_19 ) ;
F_12 ( V_2 , V_19 , V_26 ) ;
if ( V_19 & V_27 )
V_2 -> clock = 0 ;
V_20 = 100 ;
while ( F_13 ( V_2 , V_26 ) & V_19 ) {
if ( V_20 == 0 ) {
F_2 ( V_28 L_16 ,
F_14 ( V_2 -> V_29 ) , ( int ) V_19 ) ;
F_1 ( V_2 ) ;
return;
}
V_20 -- ;
F_15 ( 1 ) ;
}
if ( V_2 -> V_24 -> V_30 )
V_2 -> V_24 -> V_30 ( V_2 , V_19 ) ;
if ( V_2 -> V_13 & V_23 )
F_3 ( V_2 , V_31 , V_7 ) ;
}
static void F_16 ( struct V_1 * V_2 , int V_32 )
{
if ( V_32 )
F_11 ( V_2 , V_33 | V_34 ) ;
else
F_11 ( V_2 , V_27 ) ;
F_3 ( V_2 , V_31 ,
V_35 | V_36 |
V_37 | V_38 | V_39 |
V_40 | V_41 | V_42 |
V_43 | V_44 ) ;
if ( V_32 ) {
V_2 -> clock = 0 ;
F_17 ( V_2 -> V_29 , & V_2 -> V_29 -> V_45 ) ;
}
}
static void F_18 ( struct V_1 * V_2 )
{
F_16 ( V_2 , 0 ) ;
F_9 ( V_2 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
T_2 V_46 ;
V_46 = F_13 ( V_2 , V_47 ) ;
V_46 |= V_48 ;
F_12 ( V_2 , V_46 , V_47 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
T_2 V_46 ;
V_46 = F_13 ( V_2 , V_47 ) ;
V_46 &= ~ V_48 ;
F_12 ( V_2 , V_46 , V_47 ) ;
}
static void F_21 ( struct V_49 * V_50 ,
enum V_51 V_52 )
{
struct V_1 * V_2 = F_22 ( V_50 , struct V_1 , V_50 ) ;
unsigned long V_3 ;
F_23 ( & V_2 -> V_53 , V_3 ) ;
if ( V_52 == V_54 )
F_20 ( V_2 ) ;
else
F_19 ( V_2 ) ;
F_24 ( & V_2 -> V_53 , V_3 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
T_3 V_55 , V_56 , V_57 ;
T_1 V_21 ( V_58 ) ;
T_2 * V_59 ;
F_26 ( L_17 ) ;
V_55 = V_2 -> V_60 -> V_61 ;
V_57 = 0 ;
F_27 ( V_3 ) ;
while ( V_55 ) {
if ( ! F_28 ( & V_2 -> V_62 ) )
F_29 () ;
V_56 = F_30 ( V_2 -> V_62 . V_63 , V_55 ) ;
V_55 -= V_56 ;
V_2 -> V_62 . V_64 = V_56 ;
V_59 = V_2 -> V_62 . V_65 ;
while ( V_56 ) {
if ( V_57 == 0 ) {
V_58 = F_4 ( V_2 , V_66 ) ;
V_57 = 4 ;
}
* V_59 = V_58 & 0xFF ;
V_59 ++ ;
V_58 >>= 8 ;
V_57 -- ;
V_56 -- ;
}
}
F_31 ( & V_2 -> V_62 ) ;
F_32 ( V_3 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
T_3 V_55 , V_56 , V_57 ;
T_1 V_58 ;
T_2 * V_59 ;
F_26 ( L_18 ) ;
V_55 = V_2 -> V_60 -> V_61 ;
V_57 = 0 ;
V_58 = 0 ;
F_27 ( V_3 ) ;
while ( V_55 ) {
if ( ! F_28 ( & V_2 -> V_62 ) )
F_29 () ;
V_56 = F_30 ( V_2 -> V_62 . V_63 , V_55 ) ;
V_55 -= V_56 ;
V_2 -> V_62 . V_64 = V_56 ;
V_59 = V_2 -> V_62 . V_65 ;
while ( V_56 ) {
V_58 |= ( T_1 ) * V_59 << ( V_57 * 8 ) ;
V_59 ++ ;
V_57 ++ ;
V_56 -- ;
if ( ( V_57 == 4 ) || ( ( V_56 == 0 ) && ( V_55 == 0 ) ) ) {
F_5 ( V_2 , V_58 , V_66 ) ;
V_57 = 0 ;
V_58 = 0 ;
}
}
}
F_31 ( & V_2 -> V_62 ) ;
F_32 ( V_3 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
T_1 V_19 ;
F_35 ( ! V_2 -> V_60 ) ;
if ( V_2 -> V_67 == 0 )
return;
if ( V_2 -> V_60 -> V_3 & V_68 )
V_19 = V_69 ;
else
V_19 = V_70 ;
if ( ( V_2 -> V_13 & V_71 ) &&
( V_2 -> V_60 -> V_67 == 1 ) )
V_19 = ~ 0 ;
while ( F_4 ( V_2 , V_15 ) & V_19 ) {
if ( V_2 -> V_13 & V_72 )
F_36 ( 100 ) ;
if ( V_2 -> V_60 -> V_3 & V_68 )
F_25 ( V_2 ) ;
else
F_33 ( V_2 ) ;
V_2 -> V_67 -- ;
if ( V_2 -> V_67 == 0 )
break;
}
F_26 ( L_19 ) ;
}
static char * F_37 ( struct V_73 * V_74 , unsigned long * V_3 )
{
F_27 ( * V_3 ) ;
return F_38 ( F_39 ( V_74 ) , V_75 ) + V_74 -> V_76 ;
}
static void F_40 ( void * V_77 , unsigned long * V_3 )
{
F_41 ( V_77 , V_75 ) ;
F_32 ( * V_3 ) ;
}
static void F_42 ( T_2 * V_78 , T_1 V_65 , int V_56 , unsigned V_79 )
{
T_4 * V_80 = ( T_4 V_81 * ) ( V_78 + 4 ) ;
T_5 * V_82 = ( T_5 V_81 * ) V_78 ;
V_82 [ 0 ] = F_43 ( V_79 ) ;
V_82 [ 1 ] = F_43 ( V_56 ) ;
V_80 [ 0 ] = F_44 ( V_65 ) ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_83 * V_60 )
{
int V_84 ;
T_2 * V_78 ;
T_2 * V_85 ;
T_6 V_65 ;
T_6 V_86 ;
int V_56 , V_76 ;
struct V_73 * V_74 ;
int V_87 ;
char * V_77 ;
unsigned long V_3 ;
if ( V_60 -> V_3 & V_68 )
V_84 = V_88 ;
else
V_84 = V_89 ;
V_2 -> V_86 = F_46 ( F_47 ( V_2 -> V_29 ) ,
V_2 -> V_90 , 128 * 4 , V_84 ) ;
if ( F_48 ( F_47 ( V_2 -> V_29 ) , V_2 -> V_86 ) )
goto V_91;
F_35 ( V_2 -> V_86 & 0x3 ) ;
V_2 -> V_92 = F_49 ( F_47 ( V_2 -> V_29 ) ,
V_60 -> V_74 , V_60 -> V_93 , V_84 ) ;
if ( V_2 -> V_92 == 0 )
goto V_94;
V_78 = V_2 -> V_95 ;
V_85 = V_2 -> V_90 ;
V_86 = V_2 -> V_86 ;
F_50 (data->sg, sg, host->sg_count, i) {
V_65 = F_51 ( V_74 ) ;
V_56 = F_52 ( V_74 ) ;
V_76 = ( 4 - ( V_65 & 0x3 ) ) & 0x3 ;
if ( V_76 ) {
if ( V_60 -> V_3 & V_96 ) {
V_77 = F_37 ( V_74 , & V_3 ) ;
F_53 ( ( ( long ) V_77 & V_97 ) > ( V_98 - 3 ) ) ;
memcpy ( V_85 , V_77 , V_76 ) ;
F_40 ( V_77 , & V_3 ) ;
}
F_42 ( V_78 , V_86 , V_76 , 0x21 ) ;
F_35 ( V_76 > 65536 ) ;
V_85 += 4 ;
V_86 += 4 ;
V_78 += 8 ;
V_65 += V_76 ;
V_56 -= V_76 ;
}
F_35 ( V_56 > 65536 ) ;
F_42 ( V_78 , V_65 , V_56 , 0x21 ) ;
V_78 += 8 ;
F_53 ( ( V_78 - V_2 -> V_95 ) > ( 128 * 2 + 1 ) * 4 ) ;
}
if ( V_2 -> V_13 & V_99 ) {
if ( V_78 != V_2 -> V_95 ) {
V_78 -= 8 ;
V_78 [ 0 ] |= 0x2 ;
}
} else {
F_42 ( V_78 , 0 , 0 , 0x3 ) ;
}
if ( V_60 -> V_3 & V_96 ) {
F_54 ( F_47 ( V_2 -> V_29 ) ,
V_2 -> V_86 , 128 * 4 , V_84 ) ;
}
V_2 -> V_100 = F_46 ( F_47 ( V_2 -> V_29 ) ,
V_2 -> V_95 , ( 128 * 2 + 1 ) * 4 , V_89 ) ;
if ( F_48 ( F_47 ( V_2 -> V_29 ) , V_2 -> V_100 ) )
goto V_101;
F_35 ( V_2 -> V_100 & 0x3 ) ;
return 0 ;
V_101:
F_55 ( F_47 ( V_2 -> V_29 ) , V_60 -> V_74 ,
V_60 -> V_93 , V_84 ) ;
V_94:
F_56 ( F_47 ( V_2 -> V_29 ) , V_2 -> V_86 ,
128 * 4 , V_84 ) ;
V_91:
return - V_102 ;
}
static void F_57 ( struct V_1 * V_2 ,
struct V_83 * V_60 )
{
int V_84 ;
struct V_73 * V_74 ;
int V_87 , V_103 ;
T_2 * V_85 ;
char * V_77 ;
unsigned long V_3 ;
if ( V_60 -> V_3 & V_68 )
V_84 = V_88 ;
else
V_84 = V_89 ;
F_56 ( F_47 ( V_2 -> V_29 ) , V_2 -> V_100 ,
( 128 * 2 + 1 ) * 4 , V_89 ) ;
F_56 ( F_47 ( V_2 -> V_29 ) , V_2 -> V_86 ,
128 * 4 , V_84 ) ;
if ( V_60 -> V_3 & V_68 ) {
F_58 ( F_47 ( V_2 -> V_29 ) , V_60 -> V_74 ,
V_60 -> V_93 , V_84 ) ;
V_85 = V_2 -> V_90 ;
F_50 (data->sg, sg, host->sg_count, i) {
if ( F_51 ( V_74 ) & 0x3 ) {
V_103 = 4 - ( F_51 ( V_74 ) & 0x3 ) ;
V_77 = F_37 ( V_74 , & V_3 ) ;
F_53 ( ( ( long ) V_77 & V_97 ) > ( V_98 - 3 ) ) ;
memcpy ( V_77 , V_85 , V_103 ) ;
F_40 ( V_77 , & V_3 ) ;
V_85 += 4 ;
}
}
}
F_55 ( F_47 ( V_2 -> V_29 ) , V_60 -> V_74 ,
V_60 -> V_93 , V_84 ) ;
}
static T_2 F_59 ( struct V_1 * V_2 , struct V_104 * V_79 )
{
T_2 V_105 ;
struct V_83 * V_60 = V_79 -> V_60 ;
unsigned V_106 , V_107 ;
if ( V_2 -> V_13 & V_108 )
return 0xE ;
if ( ! V_60 && ! V_79 -> V_109 )
return 0xE ;
if ( ! V_60 )
V_106 = V_79 -> V_109 * 1000 ;
else {
V_106 = V_60 -> V_110 / 1000 ;
if ( V_2 -> clock )
V_106 += V_60 -> V_111 / V_2 -> clock ;
}
V_105 = 0 ;
V_107 = ( 1 << 13 ) * 1000 / V_2 -> V_112 ;
while ( V_107 < V_106 ) {
V_105 ++ ;
V_107 <<= 1 ;
if ( V_105 >= 0xF )
break;
}
if ( V_105 >= 0xF ) {
F_2 ( V_113 L_20 ,
F_14 ( V_2 -> V_29 ) , V_79 -> V_114 ) ;
V_105 = 0xE ;
}
return V_105 ;
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
static void F_61 ( struct V_1 * V_2 , struct V_104 * V_79 )
{
T_2 V_105 ;
T_2 V_46 ;
struct V_83 * V_60 = V_79 -> V_60 ;
int V_122 ;
F_53 ( V_2 -> V_60 ) ;
if ( V_60 || ( V_79 -> V_3 & V_123 ) ) {
V_105 = F_59 ( V_2 , V_79 ) ;
F_12 ( V_2 , V_105 , V_124 ) ;
}
if ( ! V_60 )
return;
F_35 ( V_60 -> V_61 * V_60 -> V_67 > 524288 ) ;
F_35 ( V_60 -> V_61 > V_2 -> V_29 -> V_125 ) ;
F_35 ( V_60 -> V_67 > 65535 ) ;
V_2 -> V_60 = V_60 ;
V_2 -> V_126 = 0 ;
V_2 -> V_60 -> V_127 = 0 ;
if ( V_2 -> V_3 & ( V_128 | V_4 ) )
V_2 -> V_3 |= V_121 ;
if ( V_2 -> V_3 & V_121 ) {
int V_129 , V_87 ;
struct V_73 * V_74 ;
V_129 = 0 ;
if ( V_2 -> V_3 & V_4 ) {
if ( V_2 -> V_13 & V_130 )
V_129 = 1 ;
} else {
if ( V_2 -> V_13 & V_131 )
V_129 = 1 ;
}
if ( F_62 ( V_129 ) ) {
F_50 (data->sg, sg, data->sg_len, i) {
if ( V_74 -> V_63 & 0x3 ) {
F_26 ( L_21
L_22 ,
V_74 -> V_63 ) ;
V_2 -> V_3 &= ~ V_121 ;
break;
}
}
}
}
if ( V_2 -> V_3 & V_121 ) {
int V_129 , V_87 ;
struct V_73 * V_74 ;
V_129 = 0 ;
if ( V_2 -> V_3 & V_4 ) {
if ( V_2 -> V_13 & V_130 )
V_129 = 1 ;
} else {
if ( V_2 -> V_13 & V_132 )
V_129 = 1 ;
}
if ( F_62 ( V_129 ) ) {
F_50 (data->sg, sg, data->sg_len, i) {
if ( V_74 -> V_76 & 0x3 ) {
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
V_122 = F_45 ( V_2 , V_60 ) ;
if ( V_122 ) {
F_53 ( 1 ) ;
V_2 -> V_3 &= ~ V_121 ;
} else {
F_5 ( V_2 , V_2 -> V_100 ,
V_133 ) ;
}
} else {
int V_134 ;
V_134 = F_49 ( F_47 ( V_2 -> V_29 ) ,
V_60 -> V_74 , V_60 -> V_93 ,
( V_60 -> V_3 & V_68 ) ?
V_88 :
V_89 ) ;
if ( V_134 == 0 ) {
F_53 ( 1 ) ;
V_2 -> V_3 &= ~ V_121 ;
} else {
F_53 ( V_134 != 1 ) ;
F_5 ( V_2 , F_51 ( V_60 -> V_74 ) ,
V_135 ) ;
}
}
}
if ( V_2 -> V_136 >= V_137 ) {
V_46 = F_13 ( V_2 , V_47 ) ;
V_46 &= ~ V_138 ;
if ( ( V_2 -> V_3 & V_121 ) &&
( V_2 -> V_3 & V_4 ) )
V_46 |= V_139 ;
else
V_46 |= V_140 ;
F_12 ( V_2 , V_46 , V_47 ) ;
}
if ( ! ( V_2 -> V_3 & V_121 ) ) {
int V_3 ;
V_3 = V_141 ;
if ( V_2 -> V_60 -> V_3 & V_68 )
V_3 |= V_142 ;
else
V_3 |= V_143 ;
F_63 ( & V_2 -> V_62 , V_60 -> V_74 , V_60 -> V_93 , V_3 ) ;
V_2 -> V_67 = V_60 -> V_67 ;
}
F_60 ( V_2 ) ;
F_64 ( V_2 , F_65 ( V_144 ,
V_60 -> V_61 ) , V_145 ) ;
F_64 ( V_2 , V_60 -> V_67 , V_146 ) ;
}
static void F_66 ( struct V_1 * V_2 ,
struct V_104 * V_79 )
{
T_7 V_147 ;
struct V_83 * V_60 = V_79 -> V_60 ;
if ( V_60 == NULL )
return;
F_53 ( ! V_2 -> V_60 ) ;
V_147 = V_148 ;
if ( F_67 ( V_79 -> V_114 ) || V_60 -> V_67 > 1 ) {
V_147 |= V_149 ;
if ( ! V_2 -> V_150 -> V_151 && ( V_2 -> V_3 & V_152 ) )
V_147 |= V_153 ;
else if ( V_2 -> V_150 -> V_151 && ( V_2 -> V_3 & V_154 ) ) {
V_147 |= V_155 ;
F_5 ( V_2 , V_2 -> V_150 -> V_151 -> V_156 , V_157 ) ;
}
}
if ( V_60 -> V_3 & V_68 )
V_147 |= V_158 ;
if ( V_2 -> V_3 & V_121 )
V_147 |= V_159 ;
F_64 ( V_2 , V_147 , V_160 ) ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_83 * V_60 ;
F_35 ( ! V_2 -> V_60 ) ;
V_60 = V_2 -> V_60 ;
V_2 -> V_60 = NULL ;
if ( V_2 -> V_3 & V_121 ) {
if ( V_2 -> V_3 & V_4 )
F_57 ( V_2 , V_60 ) ;
else {
F_55 ( F_47 ( V_2 -> V_29 ) , V_60 -> V_74 ,
V_60 -> V_93 , ( V_60 -> V_3 & V_68 ) ?
V_88 : V_89 ) ;
}
}
if ( V_60 -> error )
V_60 -> V_127 = 0 ;
else
V_60 -> V_127 = V_60 -> V_61 * V_60 -> V_67 ;
if ( V_60 -> V_161 &&
( V_60 -> error ||
! V_2 -> V_150 -> V_151 ) ) {
if ( V_60 -> error ) {
F_11 ( V_2 , V_33 ) ;
F_11 ( V_2 , V_34 ) ;
}
F_69 ( V_2 , V_60 -> V_161 ) ;
} else
F_70 ( & V_2 -> V_162 ) ;
}
static void F_69 ( struct V_1 * V_2 , struct V_104 * V_79 )
{
int V_3 ;
T_1 V_19 ;
unsigned long V_20 ;
F_53 ( V_2 -> V_79 ) ;
V_20 = 10 ;
V_19 = V_163 ;
if ( ( V_79 -> V_60 != NULL ) || ( V_79 -> V_3 & V_123 ) )
V_19 |= V_164 ;
if ( V_2 -> V_150 -> V_60 && ( V_79 == V_2 -> V_150 -> V_60 -> V_161 ) )
V_19 &= ~ V_164 ;
while ( F_4 ( V_2 , V_15 ) & V_19 ) {
if ( V_20 == 0 ) {
F_2 ( V_28 L_24
L_25 , F_14 ( V_2 -> V_29 ) ) ;
F_1 ( V_2 ) ;
V_79 -> error = - V_165 ;
F_70 ( & V_2 -> V_162 ) ;
return;
}
V_20 -- ;
F_15 ( 1 ) ;
}
F_71 ( & V_2 -> V_166 , V_167 + 10 * V_168 ) ;
V_2 -> V_79 = V_79 ;
F_61 ( V_2 , V_79 ) ;
F_5 ( V_2 , V_79 -> V_156 , V_169 ) ;
F_66 ( V_2 , V_79 ) ;
if ( ( V_79 -> V_3 & V_170 ) && ( V_79 -> V_3 & V_123 ) ) {
F_2 ( V_28 L_26 ,
F_14 ( V_2 -> V_29 ) ) ;
V_79 -> error = - V_102 ;
F_70 ( & V_2 -> V_162 ) ;
return;
}
if ( ! ( V_79 -> V_3 & V_171 ) )
V_3 = V_172 ;
else if ( V_79 -> V_3 & V_170 )
V_3 = V_173 ;
else if ( V_79 -> V_3 & V_123 )
V_3 = V_174 ;
else
V_3 = V_175 ;
if ( V_79 -> V_3 & V_176 )
V_3 |= V_177 ;
if ( V_79 -> V_3 & V_178 )
V_3 |= V_179 ;
if ( V_79 -> V_60 || ( V_79 -> V_114 == V_180 ) )
V_3 |= V_181 ;
F_64 ( V_2 , F_72 ( V_79 -> V_114 , V_3 ) , V_182 ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
int V_87 ;
F_35 ( V_2 -> V_79 == NULL ) ;
if ( V_2 -> V_79 -> V_3 & V_171 ) {
if ( V_2 -> V_79 -> V_3 & V_170 ) {
for ( V_87 = 0 ; V_87 < 4 ; V_87 ++ ) {
V_2 -> V_79 -> V_183 [ V_87 ] = F_4 ( V_2 ,
V_184 + ( 3 - V_87 ) * 4 ) << 8 ;
if ( V_87 != 3 )
V_2 -> V_79 -> V_183 [ V_87 ] |=
F_13 ( V_2 ,
V_184 + ( 3 - V_87 ) * 4 - 1 ) ;
}
} else {
V_2 -> V_79 -> V_183 [ 0 ] = F_4 ( V_2 , V_184 ) ;
}
}
V_2 -> V_79 -> error = 0 ;
if ( V_2 -> V_79 == V_2 -> V_150 -> V_151 ) {
V_2 -> V_79 = NULL ;
F_69 ( V_2 , V_2 -> V_150 -> V_79 ) ;
} else {
if ( V_2 -> V_60 && V_2 -> V_126 )
F_68 ( V_2 ) ;
if ( ! V_2 -> V_79 -> V_60 )
F_70 ( & V_2 -> V_162 ) ;
V_2 -> V_79 = NULL ;
}
}
static void F_74 ( struct V_1 * V_2 , unsigned int clock )
{
int div = 0 ;
T_7 V_185 = 0 ;
unsigned long V_20 ;
if ( clock == V_2 -> clock )
return;
if ( V_2 -> V_24 -> V_186 ) {
V_2 -> V_24 -> V_186 ( V_2 , clock ) ;
if ( V_2 -> V_13 & V_187 )
return;
}
F_64 ( V_2 , 0 , V_188 ) ;
if ( clock == 0 )
goto V_189;
if ( V_2 -> V_136 >= V_190 ) {
if ( V_2 -> V_191 ) {
T_7 V_46 ;
V_46 = F_75 ( V_2 , V_192 ) ;
if ( ! ( V_46 & V_193 ) ) {
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
V_20 = 20 ;
while ( ! ( ( V_185 = F_75 ( V_2 , V_188 ) )
& V_204 ) ) {
if ( V_20 == 0 ) {
F_2 ( V_28 L_27
L_28 , F_14 ( V_2 -> V_29 ) ) ;
F_1 ( V_2 ) ;
return;
}
V_20 -- ;
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
if ( ! ( V_2 -> V_13 & V_217 ) )
F_12 ( V_2 , 0 , V_216 ) ;
if ( V_2 -> V_13 & V_218 )
F_12 ( V_2 , V_207 , V_216 ) ;
V_207 |= V_219 ;
F_12 ( V_2 , V_207 , V_216 ) ;
if ( V_2 -> V_13 & V_220 )
F_15 ( 10 ) ;
}
static void F_77 ( struct V_221 * V_29 , struct V_222 * V_150 )
{
struct V_1 * V_2 ;
bool V_12 ;
unsigned long V_3 ;
V_2 = F_78 ( V_29 ) ;
F_23 ( & V_2 -> V_53 , V_3 ) ;
F_53 ( V_2 -> V_150 != NULL ) ;
#ifndef F_79
F_19 ( V_2 ) ;
#endif
if ( ! V_150 -> V_151 && ( V_2 -> V_3 & V_152 ) ) {
if ( V_150 -> V_161 ) {
V_150 -> V_60 -> V_161 = NULL ;
V_150 -> V_161 = NULL ;
}
}
V_2 -> V_150 = V_150 ;
if ( V_2 -> V_13 & V_14 )
V_12 = true ;
else
V_12 = F_4 ( V_2 , V_15 ) &
V_16 ;
if ( ! V_12 || V_2 -> V_3 & V_223 ) {
V_2 -> V_150 -> V_79 -> error = - V_224 ;
F_70 ( & V_2 -> V_162 ) ;
} else {
T_1 V_225 ;
V_225 = F_4 ( V_2 , V_15 ) ;
if ( ( V_2 -> V_3 & V_226 ) &&
! ( V_225 & ( V_227 | V_228 ) ) ) {
F_24 ( & V_2 -> V_53 , V_3 ) ;
F_80 ( V_29 ) ;
F_23 ( & V_2 -> V_53 , V_3 ) ;
V_2 -> V_150 = V_150 ;
}
if ( V_150 -> V_151 && ! ( V_2 -> V_3 & V_154 ) )
F_69 ( V_2 , V_150 -> V_151 ) ;
else
F_69 ( V_2 , V_150 -> V_79 ) ;
}
F_81 () ;
F_24 ( & V_2 -> V_53 , V_3 ) ;
}
static void F_17 ( struct V_221 * V_29 , struct V_229 * V_45 )
{
struct V_1 * V_2 ;
unsigned long V_3 ;
T_2 V_46 ;
V_2 = F_78 ( V_29 ) ;
F_23 ( & V_2 -> V_53 , V_3 ) ;
if ( V_2 -> V_3 & V_223 )
goto V_189;
if ( V_45 -> V_230 == V_231 ) {
F_5 ( V_2 , 0 , V_9 ) ;
F_18 ( V_2 ) ;
}
F_74 ( V_2 , V_45 -> clock ) ;
if ( V_45 -> V_230 == V_231 )
F_76 ( V_2 , - 1 ) ;
else
F_76 ( V_2 , V_45 -> V_232 ) ;
if ( V_2 -> V_24 -> V_233 )
V_2 -> V_24 -> V_233 ( V_2 , V_45 -> V_230 ) ;
if ( V_2 -> V_24 -> V_234 )
V_2 -> V_24 -> V_234 ( V_2 , V_45 -> V_235 ) ;
else {
V_46 = F_13 ( V_2 , V_47 ) ;
if ( V_45 -> V_235 == V_236 ) {
V_46 &= ~ V_237 ;
if ( V_2 -> V_136 >= V_190 )
V_46 |= V_238 ;
} else {
if ( V_2 -> V_136 >= V_190 )
V_46 &= ~ V_238 ;
if ( V_45 -> V_235 == V_239 )
V_46 |= V_237 ;
else
V_46 &= ~ V_237 ;
}
F_12 ( V_2 , V_46 , V_47 ) ;
}
V_46 = F_13 ( V_2 , V_47 ) ;
if ( ( V_45 -> V_240 == V_241 ||
V_45 -> V_240 == V_242 )
&& ! ( V_2 -> V_13 & V_243 ) )
V_46 |= V_244 ;
else
V_46 &= ~ V_244 ;
if ( V_2 -> V_136 >= V_190 ) {
T_7 V_185 , V_245 ;
unsigned int clock ;
if ( ( V_45 -> V_240 == V_246 ) ||
( V_45 -> V_240 == V_247 ) ||
( V_45 -> V_240 == V_248 ) ||
( V_45 -> V_240 == V_249 ) ||
( V_45 -> V_240 == V_250 ) )
V_46 |= V_244 ;
V_245 = F_75 ( V_2 , V_192 ) ;
if ( ! ( V_245 & V_193 ) ) {
F_12 ( V_2 , V_46 , V_47 ) ;
V_245 &= ~ V_251 ;
if ( V_45 -> V_252 == V_253 )
V_245 |= V_254 ;
else if ( V_45 -> V_252 == V_255 )
V_245 |= V_256 ;
F_64 ( V_2 , V_245 , V_192 ) ;
} else {
V_185 = F_75 ( V_2 , V_188 ) ;
V_185 &= ~ V_205 ;
F_64 ( V_2 , V_185 , V_188 ) ;
F_12 ( V_2 , V_46 , V_47 ) ;
clock = V_2 -> clock ;
V_2 -> clock = 0 ;
F_74 ( V_2 , clock ) ;
}
V_185 = F_75 ( V_2 , V_188 ) ;
V_185 &= ~ V_205 ;
F_64 ( V_2 , V_185 , V_188 ) ;
if ( V_2 -> V_24 -> V_257 )
V_2 -> V_24 -> V_257 ( V_2 , V_45 -> V_240 ) ;
else {
V_245 = F_75 ( V_2 , V_192 ) ;
V_245 &= ~ V_258 ;
if ( V_45 -> V_240 == V_250 )
V_245 |= V_259 ;
else if ( V_45 -> V_240 == V_249 )
V_245 |= V_260 ;
else if ( V_45 -> V_240 == V_246 )
V_245 |= V_261 ;
else if ( V_45 -> V_240 == V_247 )
V_245 |= V_262 ;
else if ( V_45 -> V_240 == V_248 )
V_245 |= V_263 ;
F_64 ( V_2 , V_245 , V_192 ) ;
}
clock = V_2 -> clock ;
V_2 -> clock = 0 ;
F_74 ( V_2 , clock ) ;
} else
F_12 ( V_2 , V_46 , V_47 ) ;
if( V_2 -> V_13 & V_264 )
F_11 ( V_2 , V_33 | V_34 ) ;
V_189:
F_81 () ;
F_24 ( & V_2 -> V_53 , V_3 ) ;
}
static int F_82 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
int V_265 ;
F_23 ( & V_2 -> V_53 , V_3 ) ;
if ( V_2 -> V_3 & V_223 )
V_265 = 0 ;
else if ( V_2 -> V_24 -> V_266 )
V_265 = V_2 -> V_24 -> V_266 ( V_2 ) ;
else
V_265 = ! ( F_4 ( V_2 , V_15 )
& V_267 ) ;
F_24 ( & V_2 -> V_53 , V_3 ) ;
return V_2 -> V_13 & V_268 ?
! V_265 : V_265 ;
}
static int F_83 ( struct V_221 * V_29 )
{
struct V_1 * V_2 ;
int V_87 , V_269 ;
V_2 = F_78 ( V_29 ) ;
if ( ! ( V_2 -> V_13 & V_270 ) )
return F_82 ( V_2 ) ;
V_269 = 0 ;
for ( V_87 = 0 ; V_87 < V_271 ; V_87 ++ ) {
if ( F_82 ( V_2 ) ) {
if ( ++ V_269 > V_271 / 2 )
return 1 ;
}
F_84 ( 30 ) ;
}
return 0 ;
}
static void F_85 ( struct V_221 * V_29 , int V_11 )
{
struct V_1 * V_2 ;
unsigned long V_3 ;
V_2 = F_78 ( V_29 ) ;
F_23 ( & V_2 -> V_53 , V_3 ) ;
if ( V_2 -> V_3 & V_223 )
goto V_189;
if ( V_11 )
F_6 ( V_2 , V_272 ) ;
else
F_7 ( V_2 , V_272 ) ;
V_189:
F_81 () ;
F_24 ( & V_2 -> V_53 , V_3 ) ;
}
static int F_86 ( struct V_221 * V_29 ,
struct V_229 * V_45 )
{
struct V_1 * V_2 ;
T_2 V_207 ;
T_7 V_185 , V_46 ;
T_1 V_225 ;
V_2 = F_78 ( V_29 ) ;
if ( V_2 -> V_136 < V_190 )
return 0 ;
V_46 = F_75 ( V_2 , V_192 ) ;
if ( V_45 -> V_273 == V_274 ) {
V_46 &= ~ V_275 ;
F_64 ( V_2 , V_46 , V_192 ) ;
F_87 ( 5000 , 5500 ) ;
V_46 = F_75 ( V_2 , V_192 ) ;
if ( ! ( V_46 & V_275 ) )
return 0 ;
else {
F_2 (KERN_INFO DRIVER_NAME L_29
L_30 ) ;
return - V_165 ;
}
} else if ( ! ( V_46 & V_275 ) &&
( V_45 -> V_273 == V_276 ) ) {
V_185 = F_75 ( V_2 , V_188 ) ;
V_185 &= ~ V_205 ;
F_64 ( V_2 , V_185 , V_188 ) ;
V_225 = F_4 ( V_2 , V_15 ) ;
if ( ! ( ( V_225 & V_277 ) >>
V_278 ) ) {
V_46 |= V_275 ;
F_64 ( V_2 , V_46 , V_192 ) ;
F_87 ( 5000 , 5500 ) ;
V_46 = F_75 ( V_2 , V_192 ) ;
if ( V_46 & V_275 ) {
V_185 = F_75 ( V_2 , V_188 ) ;
V_185 |= V_205 ;
F_64 ( V_2 , V_185 , V_188 ) ;
F_87 ( 1000 , 1500 ) ;
V_225 = F_4 ( V_2 ,
V_15 ) ;
if ( ( V_225 & V_277 ) ==
V_277 )
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
return - V_279 ;
} else
return 0 ;
}
static int F_80 ( struct V_221 * V_29 )
{
struct V_1 * V_2 ;
T_7 V_46 ;
T_1 V_7 ;
int V_280 = V_281 ;
unsigned long V_20 ;
int V_282 = 0 ;
V_2 = F_78 ( V_29 ) ;
F_88 ( V_2 -> V_283 ) ;
F_89 ( & V_2 -> V_53 ) ;
V_46 = F_75 ( V_2 , V_192 ) ;
if ( ( ( V_46 & V_258 ) == V_262 ) ||
( ( ( V_46 & V_258 ) == V_261 ) &&
( V_2 -> V_3 & V_284 ) ) )
V_46 |= V_285 ;
else {
F_90 ( & V_2 -> V_53 ) ;
F_91 ( V_2 -> V_283 ) ;
return 0 ;
}
F_64 ( V_2 , V_46 , V_192 ) ;
V_7 = F_4 ( V_2 , V_8 ) ;
F_3 ( V_2 , V_7 , V_116 ) ;
V_20 = 150 ;
do {
struct V_104 V_79 = { 0 } ;
struct V_222 V_150 = { 0 } ;
if ( ! V_280 && ! V_20 )
break;
V_79 . V_114 = V_180 ;
V_79 . V_156 = 0 ;
V_79 . V_3 = V_286 | V_287 ;
V_79 . V_288 = 0 ;
V_79 . V_60 = NULL ;
V_79 . error = 0 ;
V_150 . V_79 = & V_79 ;
V_2 -> V_150 = & V_150 ;
F_64 ( V_2 , F_65 ( 7 , 64 ) , V_145 ) ;
F_64 ( V_2 , V_158 , V_160 ) ;
F_69 ( V_2 , & V_79 ) ;
V_2 -> V_79 = NULL ;
V_2 -> V_150 = NULL ;
F_90 ( & V_2 -> V_53 ) ;
F_91 ( V_2 -> V_283 ) ;
F_92 ( V_2 -> V_289 ,
( V_2 -> V_290 == 1 ) ,
F_93 ( 50 ) ) ;
F_88 ( V_2 -> V_283 ) ;
F_89 ( & V_2 -> V_53 ) ;
if ( ! V_2 -> V_290 ) {
F_2 (KERN_INFO DRIVER_NAME L_33
L_34
L_35
L_36 ) ;
V_46 = F_75 ( V_2 , V_192 ) ;
V_46 &= ~ V_291 ;
V_46 &= ~ V_285 ;
F_64 ( V_2 , V_46 , V_192 ) ;
V_282 = - V_165 ;
goto V_189;
}
V_2 -> V_290 = 0 ;
V_46 = F_75 ( V_2 , V_192 ) ;
V_280 -- ;
V_20 -- ;
F_15 ( 1 ) ;
} while ( V_46 & V_285 );
if ( ! V_280 || ! V_20 ) {
V_46 &= ~ V_291 ;
F_64 ( V_2 , V_46 , V_192 ) ;
} else {
if ( ! ( V_46 & V_291 ) ) {
F_2 (KERN_INFO DRIVER_NAME L_37
L_38
L_39 ) ;
V_282 = - V_165 ;
}
}
V_189:
if ( ! ( V_2 -> V_3 & V_226 ) && V_2 -> V_292 &&
( V_2 -> V_293 == V_294 ) ) {
F_71 ( & V_2 -> V_295 , V_167 +
V_2 -> V_292 * V_168 ) ;
V_29 -> V_296 = ( 4 * 1024 * 1024 ) / V_29 -> V_125 ;
} else {
V_2 -> V_3 &= ~ V_226 ;
if ( V_2 -> V_293 == V_294 )
F_71 ( & V_2 -> V_295 , V_167 +
V_2 -> V_292 * V_168 ) ;
}
if ( V_282 && V_2 -> V_292 &&
V_2 -> V_293 == V_294 )
V_282 = 0 ;
F_3 ( V_2 , V_116 , V_7 ) ;
F_90 ( & V_2 -> V_53 ) ;
F_91 ( V_2 -> V_283 ) ;
return V_282 ;
}
static void F_94 ( struct V_221 * V_29 , bool V_11 )
{
struct V_1 * V_2 ;
T_7 V_46 ;
unsigned long V_3 ;
V_2 = F_78 ( V_29 ) ;
if ( V_2 -> V_136 < V_190 )
return;
F_23 ( & V_2 -> V_53 , V_3 ) ;
V_46 = F_75 ( V_2 , V_192 ) ;
if ( V_11 && ! ( V_46 & V_193 ) ) {
V_46 |= V_193 ;
F_64 ( V_2 , V_46 , V_192 ) ;
} else if ( ! V_11 && ( V_46 & V_193 ) ) {
V_46 &= ~ V_193 ;
F_64 ( V_2 , V_46 , V_192 ) ;
}
F_24 ( & V_2 -> V_53 , V_3 ) ;
}
static void F_95 ( unsigned long V_297 )
{
struct V_1 * V_2 ;
unsigned long V_3 ;
V_2 = (struct V_1 * ) V_297 ;
F_23 ( & V_2 -> V_53 , V_3 ) ;
if ( ! ( F_4 ( V_2 , V_15 ) & V_16 ) ) {
if ( V_2 -> V_150 ) {
F_2 ( V_28 L_40 ,
F_14 ( V_2 -> V_29 ) ) ;
F_2 ( V_28 L_41 ,
F_14 ( V_2 -> V_29 ) ) ;
F_11 ( V_2 , V_33 ) ;
F_11 ( V_2 , V_34 ) ;
V_2 -> V_150 -> V_79 -> error = - V_224 ;
F_70 ( & V_2 -> V_162 ) ;
}
}
F_24 ( & V_2 -> V_53 , V_3 ) ;
F_96 ( V_2 -> V_29 , F_93 ( 200 ) ) ;
}
static void F_97 ( unsigned long V_297 )
{
struct V_1 * V_2 ;
unsigned long V_3 ;
struct V_222 * V_150 ;
V_2 = (struct V_1 * ) V_297 ;
if ( ! V_2 -> V_150 )
return;
F_23 ( & V_2 -> V_53 , V_3 ) ;
F_98 ( & V_2 -> V_166 ) ;
V_150 = V_2 -> V_150 ;
if ( ! ( V_2 -> V_3 & V_223 ) &&
( ( V_150 -> V_79 && V_150 -> V_79 -> error ) ||
( V_150 -> V_60 && ( V_150 -> V_60 -> error ||
( V_150 -> V_60 -> V_161 && V_150 -> V_60 -> V_161 -> error ) ) ) ||
( V_2 -> V_13 & V_298 ) ) ) {
if ( V_2 -> V_13 & V_299 ) {
unsigned int clock ;
clock = V_2 -> clock ;
V_2 -> clock = 0 ;
F_74 ( V_2 , clock ) ;
}
F_11 ( V_2 , V_33 ) ;
F_11 ( V_2 , V_34 ) ;
}
V_2 -> V_150 = NULL ;
V_2 -> V_79 = NULL ;
V_2 -> V_60 = NULL ;
#ifndef F_79
F_20 ( V_2 ) ;
#endif
F_81 () ;
F_24 ( & V_2 -> V_53 , V_3 ) ;
F_99 ( V_2 -> V_29 , V_150 ) ;
}
static void F_100 ( unsigned long V_60 )
{
struct V_1 * V_2 ;
unsigned long V_3 ;
V_2 = (struct V_1 * ) V_60 ;
F_23 ( & V_2 -> V_53 , V_3 ) ;
if ( V_2 -> V_150 ) {
F_2 ( V_28 L_42
L_43 , F_14 ( V_2 -> V_29 ) ) ;
F_1 ( V_2 ) ;
if ( V_2 -> V_60 ) {
V_2 -> V_60 -> error = - V_300 ;
F_68 ( V_2 ) ;
} else {
if ( V_2 -> V_79 )
V_2 -> V_79 -> error = - V_300 ;
else
V_2 -> V_150 -> V_79 -> error = - V_300 ;
F_70 ( & V_2 -> V_162 ) ;
}
}
F_81 () ;
F_24 ( & V_2 -> V_53 , V_3 ) ;
}
static void F_101 ( unsigned long V_60 )
{
struct V_1 * V_2 ;
unsigned long V_3 ;
V_2 = (struct V_1 * ) V_60 ;
F_23 ( & V_2 -> V_53 , V_3 ) ;
V_2 -> V_3 |= V_226 ;
F_24 ( & V_2 -> V_53 , V_3 ) ;
}
static void F_102 ( struct V_1 * V_2 , T_1 V_301 )
{
F_35 ( V_301 == 0 ) ;
if ( ! V_2 -> V_79 ) {
F_2 ( V_28 L_44
L_45 ,
F_14 ( V_2 -> V_29 ) , ( unsigned ) V_301 ) ;
F_1 ( V_2 ) ;
return;
}
if ( V_301 & V_42 )
V_2 -> V_79 -> error = - V_300 ;
else if ( V_301 & ( V_41 | V_40 |
V_39 ) )
V_2 -> V_79 -> error = - V_302 ;
if ( V_2 -> V_79 -> error ) {
F_70 ( & V_2 -> V_162 ) ;
return;
}
if ( V_2 -> V_79 -> V_3 & V_123 ) {
if ( V_2 -> V_79 -> V_60 )
F_26 ( L_46
L_47 ) ;
else if ( ! ( V_2 -> V_13 & V_303 ) )
return;
}
if ( V_301 & V_44 )
F_73 ( V_2 ) ;
}
static void F_103 ( struct V_1 * V_2 )
{
const char * V_304 = F_14 ( V_2 -> V_29 ) ;
T_2 * V_78 = V_2 -> V_95 ;
T_4 * V_305 ;
T_5 * V_56 ;
T_2 V_306 ;
F_1 ( V_2 ) ;
while ( true ) {
V_305 = ( T_4 * ) ( V_78 + 4 ) ;
V_56 = ( T_5 * ) ( V_78 + 2 ) ;
V_306 = * V_78 ;
F_26 ( L_48 ,
V_304 , V_78 , F_104 ( * V_305 ) , F_105 ( * V_56 ) , V_306 ) ;
V_78 += 8 ;
if ( V_306 & 2 )
break;
}
}
static void F_103 ( struct V_1 * V_2 ) { }
static void F_106 ( struct V_1 * V_2 , T_1 V_301 )
{
F_35 ( V_301 == 0 ) ;
if ( V_301 & V_116 ) {
if ( F_107 ( F_75 ( V_2 , V_182 ) ) ==
V_180 ) {
V_2 -> V_290 = 1 ;
F_108 ( & V_2 -> V_289 ) ;
return;
}
}
if ( ! V_2 -> V_60 ) {
if ( V_2 -> V_79 && ( V_2 -> V_79 -> V_3 & V_123 ) ) {
if ( V_301 & V_43 ) {
F_73 ( V_2 ) ;
return;
}
}
F_2 ( V_28 L_49
L_50 ,
F_14 ( V_2 -> V_29 ) , ( unsigned ) V_301 ) ;
F_1 ( V_2 ) ;
return;
}
if ( V_301 & V_38 )
V_2 -> V_60 -> error = - V_300 ;
else if ( V_301 & V_36 )
V_2 -> V_60 -> error = - V_302 ;
else if ( ( V_301 & V_37 ) &&
F_107 ( F_75 ( V_2 , V_182 ) )
!= V_307 )
V_2 -> V_60 -> error = - V_302 ;
else if ( V_301 & V_120 ) {
F_2 ( V_28 L_51 , F_14 ( V_2 -> V_29 ) ) ;
F_103 ( V_2 ) ;
V_2 -> V_60 -> error = - V_165 ;
}
if ( V_2 -> V_60 -> error )
F_68 ( V_2 ) ;
else {
if ( V_301 & ( V_116 | V_117 ) )
F_34 ( V_2 ) ;
if ( V_301 & V_119 ) {
T_1 V_308 , V_309 ;
V_308 = F_51 ( V_2 -> V_60 -> V_74 ) ;
V_309 = V_308 + V_2 -> V_60 -> V_127 ;
V_309 = ( V_309 &
~ ( V_310 - 1 ) ) +
V_310 ;
V_2 -> V_60 -> V_127 = V_309 - V_308 ;
F_26 ( L_52
L_53 ,
F_14 ( V_2 -> V_29 ) , V_308 ,
V_2 -> V_60 -> V_127 , V_309 ) ;
F_5 ( V_2 , V_309 , V_135 ) ;
}
if ( V_301 & V_43 ) {
if ( V_2 -> V_79 ) {
V_2 -> V_126 = 1 ;
} else {
F_68 ( V_2 ) ;
}
}
}
}
static T_8 F_109 ( int V_283 , void * V_311 )
{
T_8 V_312 ;
struct V_1 * V_2 = V_311 ;
T_1 V_301 ;
int V_313 = 0 ;
F_89 ( & V_2 -> V_53 ) ;
V_301 = F_4 ( V_2 , V_314 ) ;
if ( ! V_301 || V_301 == 0xffffffff ) {
V_312 = V_315 ;
goto V_189;
}
F_26 ( L_54 ,
F_14 ( V_2 -> V_29 ) , V_301 ) ;
if ( V_301 & ( V_18 | V_17 ) ) {
T_1 V_12 = F_4 ( V_2 , V_15 ) &
V_16 ;
F_7 ( V_2 , V_12 ? V_18 :
V_17 ) ;
F_6 ( V_2 , V_12 ? V_17 :
V_18 ) ;
F_5 ( V_2 , V_301 & ( V_18 |
V_17 ) , V_314 ) ;
V_301 &= ~ ( V_18 | V_17 ) ;
F_70 ( & V_2 -> V_316 ) ;
}
if ( V_301 & V_317 ) {
F_5 ( V_2 , V_301 & V_317 ,
V_314 ) ;
F_102 ( V_2 , V_301 & V_317 ) ;
}
if ( V_301 & V_318 ) {
F_5 ( V_2 , V_301 & V_318 ,
V_314 ) ;
F_106 ( V_2 , V_301 & V_318 ) ;
}
V_301 &= ~ ( V_317 | V_318 ) ;
V_301 &= ~ V_319 ;
if ( V_301 & V_35 ) {
F_2 ( V_28 L_55 ,
F_14 ( V_2 -> V_29 ) ) ;
F_5 ( V_2 , V_35 , V_314 ) ;
}
V_301 &= ~ V_35 ;
if ( V_301 & V_272 )
V_313 = 1 ;
V_301 &= ~ V_272 ;
if ( V_301 ) {
F_2 ( V_28 L_56 ,
F_14 ( V_2 -> V_29 ) , V_301 ) ;
F_1 ( V_2 ) ;
F_5 ( V_2 , V_301 , V_314 ) ;
}
V_312 = V_320 ;
F_81 () ;
V_189:
F_90 ( & V_2 -> V_53 ) ;
if ( V_313 )
F_110 ( V_2 -> V_29 ) ;
return V_312 ;
}
int F_111 ( struct V_1 * V_2 , T_9 V_321 )
{
int V_122 ;
F_10 ( V_2 ) ;
if ( V_2 -> V_136 >= V_190 && V_2 -> V_292 &&
V_2 -> V_293 == V_294 ) {
V_2 -> V_3 &= ~ V_226 ;
F_71 ( & V_2 -> V_295 , V_167 +
V_2 -> V_292 * V_168 ) ;
}
V_122 = F_112 ( V_2 -> V_29 ) ;
if ( V_122 )
return V_122 ;
F_113 ( V_2 -> V_283 , V_2 ) ;
if ( V_2 -> V_322 )
V_122 = F_114 ( V_2 -> V_322 ) ;
return V_122 ;
}
int F_115 ( struct V_1 * V_2 )
{
int V_122 ;
if ( V_2 -> V_322 ) {
int V_122 = F_116 ( V_2 -> V_322 ) ;
if ( V_122 )
return V_122 ;
}
if ( V_2 -> V_3 & ( V_128 | V_4 ) ) {
if ( V_2 -> V_24 -> V_323 )
V_2 -> V_24 -> V_323 ( V_2 ) ;
}
V_122 = F_117 ( V_2 -> V_283 , F_109 , V_324 ,
F_14 ( V_2 -> V_29 ) , V_2 ) ;
if ( V_122 )
return V_122 ;
F_16 ( V_2 , ( V_2 -> V_29 -> V_325 & V_326 ) ) ;
F_81 () ;
V_122 = F_118 ( V_2 -> V_29 ) ;
F_9 ( V_2 ) ;
if ( ( V_2 -> V_136 >= V_190 ) && V_2 -> V_292 &&
( V_2 -> V_293 == V_294 ) )
V_2 -> V_3 |= V_226 ;
return V_122 ;
}
void F_119 ( struct V_1 * V_2 )
{
T_2 V_327 ;
V_327 = F_13 ( V_2 , V_328 ) ;
V_327 |= V_329 ;
F_12 ( V_2 , V_327 , V_328 ) ;
}
struct V_1 * F_120 ( struct V_330 * V_331 ,
T_3 V_332 )
{
struct V_221 * V_29 ;
struct V_1 * V_2 ;
F_53 ( V_331 == NULL ) ;
V_29 = F_121 ( sizeof( struct V_1 ) + V_332 , V_331 ) ;
if ( ! V_29 )
return F_122 ( - V_333 ) ;
V_2 = F_78 ( V_29 ) ;
V_2 -> V_29 = V_29 ;
return V_2 ;
}
int F_123 ( struct V_1 * V_2 )
{
struct V_221 * V_29 ;
T_1 V_334 [ 2 ] ;
T_1 V_335 ;
unsigned int V_336 ;
int V_122 ;
F_53 ( V_2 == NULL ) ;
if ( V_2 == NULL )
return - V_102 ;
V_29 = V_2 -> V_29 ;
if ( V_337 )
V_2 -> V_13 = V_337 ;
F_11 ( V_2 , V_27 ) ;
V_2 -> V_136 = F_75 ( V_2 , V_338 ) ;
V_2 -> V_136 = ( V_2 -> V_136 & V_339 )
>> V_340 ;
if ( V_2 -> V_136 > V_190 ) {
F_2 ( V_28 L_57
L_58 , F_14 ( V_29 ) ,
V_2 -> V_136 ) ;
}
V_334 [ 0 ] = ( V_2 -> V_13 & V_341 ) ? V_2 -> V_334 :
F_4 ( V_2 , V_342 ) ;
V_334 [ 1 ] = ( V_2 -> V_136 >= V_190 ) ?
F_4 ( V_2 , V_343 ) : 0 ;
if ( V_2 -> V_13 & V_344 )
V_2 -> V_3 |= V_128 ;
else if ( ! ( V_334 [ 0 ] & V_345 ) )
F_26 ( L_59 ) ;
else
V_2 -> V_3 |= V_128 ;
if ( ( V_2 -> V_13 & V_346 ) &&
( V_2 -> V_3 & V_128 ) ) {
F_26 ( L_60 ) ;
V_2 -> V_3 &= ~ V_128 ;
}
if ( ( V_2 -> V_136 >= V_137 ) &&
( V_334 [ 0 ] & V_347 ) )
V_2 -> V_3 |= V_4 ;
if ( ( V_2 -> V_13 & V_348 ) &&
( V_2 -> V_3 & V_4 ) ) {
F_26 ( L_61 ) ;
V_2 -> V_3 &= ~ V_4 ;
}
if ( V_2 -> V_3 & ( V_128 | V_4 ) ) {
if ( V_2 -> V_24 -> V_323 ) {
if ( V_2 -> V_24 -> V_323 ( V_2 ) ) {
F_2 ( V_113 L_62
L_63 ,
F_14 ( V_29 ) ) ;
V_2 -> V_3 &=
~ ( V_128 | V_4 ) ;
}
}
}
if ( V_2 -> V_3 & V_4 ) {
V_2 -> V_95 = F_124 ( ( 128 * 2 + 1 ) * 4 , V_349 ) ;
V_2 -> V_90 = F_124 ( 128 * 4 , V_349 ) ;
if ( ! V_2 -> V_95 || ! V_2 -> V_90 ) {
F_125 ( V_2 -> V_95 ) ;
F_125 ( V_2 -> V_90 ) ;
F_2 ( V_113 L_64
L_65 ,
F_14 ( V_29 ) ) ;
V_2 -> V_3 &= ~ V_4 ;
}
}
if ( ! ( V_2 -> V_3 & ( V_128 | V_4 ) ) ) {
V_2 -> V_350 = F_126 ( 64 ) ;
F_47 ( V_2 -> V_29 ) -> V_350 = & V_2 -> V_350 ;
}
if ( V_2 -> V_136 >= V_190 )
V_2 -> V_194 = ( V_334 [ 0 ] & V_351 )
>> V_352 ;
else
V_2 -> V_194 = ( V_334 [ 0 ] & V_353 )
>> V_352 ;
V_2 -> V_194 *= 1000000 ;
if ( V_2 -> V_194 == 0 || V_2 -> V_13 &
V_354 ) {
if ( ! V_2 -> V_24 -> V_355 ) {
F_2 ( V_28
L_66
L_67 , F_14 ( V_29 ) ) ;
return - V_356 ;
}
V_2 -> V_194 = V_2 -> V_24 -> V_355 ( V_2 ) ;
}
V_2 -> V_191 = ( V_334 [ 1 ] & V_357 ) >>
V_358 ;
if ( V_2 -> V_191 )
V_2 -> V_191 += 1 ;
V_29 -> V_24 = & V_359 ;
V_29 -> V_360 = V_2 -> V_194 ;
if ( V_2 -> V_24 -> V_361 )
V_29 -> V_362 = V_2 -> V_24 -> V_361 ( V_2 ) ;
else if ( V_2 -> V_136 >= V_190 ) {
if ( V_2 -> V_191 ) {
V_29 -> V_362 = ( V_2 -> V_194 * V_2 -> V_191 ) / 1024 ;
V_29 -> V_360 = V_2 -> V_194 * V_2 -> V_191 ;
} else
V_29 -> V_362 = V_2 -> V_194 / V_196 ;
} else
V_29 -> V_362 = V_2 -> V_194 / V_197 ;
V_2 -> V_112 =
( V_334 [ 0 ] & V_363 ) >> V_364 ;
if ( V_2 -> V_112 == 0 ) {
if ( V_2 -> V_24 -> V_365 ) {
V_2 -> V_112 = V_2 -> V_24 -> V_365 ( V_2 ) ;
} else if ( ! ( V_2 -> V_13 &
V_366 ) ) {
F_2 ( V_28
L_68
L_67 , F_14 ( V_29 ) ) ;
return - V_356 ;
}
}
if ( V_334 [ 0 ] & V_367 )
V_2 -> V_112 *= 1000 ;
if ( V_2 -> V_13 & V_366 )
V_2 -> V_112 = V_29 -> V_360 / 1000 ;
V_29 -> V_368 = ( 1 << 27 ) / V_2 -> V_112 ;
V_29 -> V_334 |= V_369 | V_370 | V_371 ;
if ( V_2 -> V_13 & V_372 )
V_2 -> V_3 |= V_152 ;
if ( ( V_2 -> V_136 >= V_190 ) &&
( ( V_2 -> V_3 & V_4 ) ||
! ( V_2 -> V_3 & V_128 ) ) ) {
V_2 -> V_3 |= V_154 ;
F_26 ( L_69 , F_14 ( V_29 ) ) ;
} else {
F_26 ( L_70 , F_14 ( V_29 ) ) ;
}
if ( ! ( V_2 -> V_13 & V_373 ) )
V_29 -> V_334 |= V_374 ;
if ( V_334 [ 0 ] & V_375 )
V_29 -> V_334 |= V_376 | V_377 ;
if ( ( V_2 -> V_13 & V_14 ) &&
F_127 ( V_29 ) )
V_29 -> V_334 |= V_378 ;
if ( V_2 -> V_136 >= V_190 )
V_29 -> V_334 |= V_379 | V_380 ;
if ( V_334 [ 1 ] & V_381 )
V_29 -> V_334 |= V_382 | V_383 ;
else if ( V_334 [ 1 ] & V_384 )
V_29 -> V_334 |= V_383 ;
if ( V_334 [ 1 ] & V_385 )
V_29 -> V_334 |= V_386 ;
if ( V_334 [ 1 ] & V_387 )
V_2 -> V_3 |= V_284 ;
if ( V_334 [ 1 ] & V_388 )
V_29 -> V_334 |= V_389 ;
if ( V_334 [ 1 ] & V_390 )
V_29 -> V_334 |= V_391 ;
if ( V_334 [ 1 ] & V_392 )
V_29 -> V_334 |= V_393 ;
V_2 -> V_292 = ( V_334 [ 1 ] & V_394 ) >>
V_395 ;
if ( V_2 -> V_292 )
V_2 -> V_292 = 1 << ( V_2 -> V_292 - 1 ) ;
V_2 -> V_293 = ( V_334 [ 1 ] & V_396 ) >>
V_397 ;
V_336 = 0 ;
V_335 = F_4 ( V_2 , V_398 ) ;
if ( V_334 [ 0 ] & V_399 ) {
int V_400 ;
V_336 |= V_213 | V_214 ;
V_400 = ( ( V_335 &
V_401 ) >>
V_402 ) *
V_403 ;
if ( V_400 > 150 )
V_29 -> V_334 |= V_404 ;
}
if ( V_334 [ 0 ] & V_405 ) {
int V_406 ;
V_336 |= V_210 | V_211 ;
V_406 = ( ( V_335 &
V_407 ) >>
V_408 ) *
V_403 ;
if ( V_406 > 150 )
V_29 -> V_334 |= V_409 ;
}
if ( V_334 [ 0 ] & V_410 ) {
int V_411 ;
V_336 |= V_208 ;
V_411 = ( ( V_335 &
V_412 ) >>
V_413 ) *
V_403 ;
if ( V_411 > 150 )
V_29 -> V_334 |= V_414 ;
if ( V_411 >= 800 )
V_29 -> V_334 |= V_415 ;
else if ( V_411 >= 600 )
V_29 -> V_334 |= V_416 ;
else if ( V_411 >= 400 )
V_29 -> V_334 |= V_417 ;
else
V_29 -> V_334 |= V_418 ;
}
V_29 -> V_336 = V_336 ;
V_29 -> V_419 = V_336 ;
if ( V_2 -> V_419 )
V_29 -> V_419 &= V_2 -> V_419 ;
V_29 -> V_420 = V_336 ;
if ( V_2 -> V_420 )
V_29 -> V_420 &= V_2 -> V_420 ;
else
V_29 -> V_420 &= ~ V_208 ;
V_29 -> V_421 = V_336 ;
if ( V_2 -> V_421 )
V_29 -> V_421 &= V_2 -> V_421 ;
if ( V_29 -> V_336 == 0 ) {
F_2 ( V_28 L_71
L_72 , F_14 ( V_29 ) ) ;
return - V_356 ;
}
F_128 ( & V_2 -> V_53 ) ;
if ( V_2 -> V_3 & V_4 )
V_29 -> V_422 = 128 ;
else if ( V_2 -> V_3 & V_128 )
V_29 -> V_422 = 1 ;
else
V_29 -> V_422 = 128 ;
V_29 -> V_423 = 524288 ;
if ( V_2 -> V_3 & V_4 ) {
if ( V_2 -> V_13 & V_424 )
V_29 -> V_425 = 65535 ;
else
V_29 -> V_425 = 65536 ;
} else {
V_29 -> V_425 = V_29 -> V_423 ;
}
if ( V_2 -> V_13 & V_426 ) {
V_29 -> V_125 = 2 ;
} else {
V_29 -> V_125 = ( V_334 [ 0 ] & V_427 ) >>
V_428 ;
if ( V_29 -> V_125 >= 3 ) {
F_2 ( V_113 L_73
L_74 , F_14 ( V_29 ) ) ;
V_29 -> V_125 = 0 ;
}
}
V_29 -> V_125 = 512 << V_29 -> V_125 ;
V_29 -> V_296 = ( V_2 -> V_13 & V_429 ) ? 1 : 65535 ;
F_129 ( & V_2 -> V_316 ,
F_95 , ( unsigned long ) V_2 ) ;
F_129 ( & V_2 -> V_162 ,
F_97 , ( unsigned long ) V_2 ) ;
F_130 ( & V_2 -> V_166 , F_100 , ( unsigned long ) V_2 ) ;
if ( V_2 -> V_136 >= V_190 ) {
F_131 ( & V_2 -> V_289 ) ;
F_132 ( & V_2 -> V_295 ) ;
V_2 -> V_295 . V_60 = ( unsigned long ) V_2 ;
V_2 -> V_295 . V_430 = F_101 ;
}
V_122 = F_117 ( V_2 -> V_283 , F_109 , V_324 ,
F_14 ( V_29 ) , V_2 ) ;
if ( V_122 )
goto V_431;
V_2 -> V_322 = F_133 ( F_47 ( V_29 ) , L_75 ) ;
if ( F_134 ( V_2 -> V_322 ) ) {
F_2 ( V_432 L_76 , F_14 ( V_29 ) ) ;
V_2 -> V_322 = NULL ;
} else {
F_116 ( V_2 -> V_322 ) ;
}
F_16 ( V_2 , 0 ) ;
#ifdef F_135
F_1 ( V_2 ) ;
#endif
#ifdef F_79
snprintf ( V_2 -> V_433 , sizeof( V_2 -> V_433 ) ,
L_77 , F_14 ( V_29 ) ) ;
V_2 -> V_50 . V_304 = V_2 -> V_433 ;
V_2 -> V_50 . V_52 = V_54 ;
V_2 -> V_50 . V_434 = F_14 ( V_29 ) ;
V_2 -> V_50 . V_435 = F_21 ;
V_122 = F_136 ( F_47 ( V_29 ) , & V_2 -> V_50 ) ;
if ( V_122 )
goto V_436;
#endif
F_81 () ;
F_137 ( V_29 ) ;
F_2 ( V_432 L_78 ,
F_14 ( V_29 ) , V_2 -> V_437 , F_138 ( F_47 ( V_29 ) ) ,
( V_2 -> V_3 & V_4 ) ? L_79 :
( V_2 -> V_3 & V_128 ) ? L_80 : L_81 ) ;
F_9 ( V_2 ) ;
return 0 ;
#ifdef F_79
V_436:
F_11 ( V_2 , V_27 ) ;
F_113 ( V_2 -> V_283 , V_2 ) ;
#endif
V_431:
F_139 ( & V_2 -> V_316 ) ;
F_139 ( & V_2 -> V_162 ) ;
return V_122 ;
}
void F_140 ( struct V_1 * V_2 , int V_438 )
{
unsigned long V_3 ;
if ( V_438 ) {
F_23 ( & V_2 -> V_53 , V_3 ) ;
V_2 -> V_3 |= V_223 ;
if ( V_2 -> V_150 ) {
F_2 ( V_28 L_82
L_83 , F_14 ( V_2 -> V_29 ) ) ;
V_2 -> V_150 -> V_79 -> error = - V_224 ;
F_70 ( & V_2 -> V_162 ) ;
}
F_24 ( & V_2 -> V_53 , V_3 ) ;
}
F_10 ( V_2 ) ;
F_141 ( V_2 -> V_29 ) ;
#ifdef F_79
F_142 ( & V_2 -> V_50 ) ;
#endif
if ( ! V_438 )
F_11 ( V_2 , V_27 ) ;
F_113 ( V_2 -> V_283 , V_2 ) ;
F_143 ( & V_2 -> V_166 ) ;
if ( V_2 -> V_136 >= V_190 )
F_143 ( & V_2 -> V_295 ) ;
F_139 ( & V_2 -> V_316 ) ;
F_139 ( & V_2 -> V_162 ) ;
if ( V_2 -> V_322 ) {
F_114 ( V_2 -> V_322 ) ;
F_144 ( V_2 -> V_322 ) ;
}
F_125 ( V_2 -> V_95 ) ;
F_125 ( V_2 -> V_90 ) ;
V_2 -> V_95 = NULL ;
V_2 -> V_90 = NULL ;
}
void F_145 ( struct V_1 * V_2 )
{
F_146 ( V_2 -> V_29 ) ;
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

static int
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
void * V_5 , T_1 V_6 , struct V_7 * V_8 )
{
struct V_1 * V_9 = F_2 ( V_2 , V_10 ) ;
const T_1 V_11 = F_3 ( V_3 , V_2 ) ;
const T_1 V_12 = F_4 ( V_3 , V_4 ) ;
int V_13 ;
V_13 = F_5 ( V_9 , V_14 , V_12 ,
V_11 , V_5 , V_6 , & V_8 -> V_15 ) ;
if ( V_13 )
return V_13 ;
V_8 -> V_12 = V_12 ;
return 0 ;
}
static void
F_6 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_1 * V_9 = F_2 ( V_2 , V_10 ) ;
if ( V_8 -> V_12 )
F_7 ( V_9 , V_14 , V_8 -> V_12 ) ;
}
static void
F_8 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
F_6 ( V_2 , & V_17 -> V_18 ) ;
}
static int
F_9 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
void * V_5 , T_1 V_6 , struct V_16 * V_17 )
{
return F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , & V_17 -> V_18 ) ;
}
static void
F_10 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
if ( V_20 -> V_21 ) {
struct V_22 * V_23 = F_11 ( V_2 ) -> V_23 ;
F_12 ( V_23 , V_24 , V_20 -> V_21 , V_20 -> V_12 ) ;
}
F_6 ( V_2 , & V_20 -> V_18 ) ;
}
static int
F_13 ( struct V_1 * V_2 , T_1 V_25 )
{
struct V_26 * V_27 = V_26 ( V_2 ) ;
struct V_1 * V_9 = F_2 ( V_2 , V_10 ) ;
struct V_1 * V_28 ;
int V_13 = F_5 (client, parent, NvEvoVRAM_LP,
NV_DMA_IN_MEMORY_CLASS,
&(struct nv_dma_class) {
.flags = NV_DMA_TARGET_VRAM |
NV_DMA_ACCESS_RDWR,
.start = 0 ,
.limit = pfb->ram.size - 1 ,
.conf0 = NV50_DMA_CONF0_ENABLE |
NV50_DMA_CONF0_PART_256,
}, sizeof(struct nv_dma_class), &object) ;
if ( V_13 )
return V_13 ;
V_13 = F_5 (client, parent, NvEvoFB16,
NV_DMA_IN_MEMORY_CLASS,
&(struct nv_dma_class) {
.flags = NV_DMA_TARGET_VRAM |
NV_DMA_ACCESS_RDWR,
.start = 0 ,
.limit = pfb->ram.size - 1 ,
.conf0 = NV50_DMA_CONF0_ENABLE | 0x70 |
NV50_DMA_CONF0_PART_256,
}, sizeof(struct nv_dma_class), &object) ;
if ( V_13 )
return V_13 ;
V_13 = F_5 (client, parent, NvEvoFB32,
NV_DMA_IN_MEMORY_CLASS,
&(struct nv_dma_class) {
.flags = NV_DMA_TARGET_VRAM |
NV_DMA_ACCESS_RDWR,
.start = 0 ,
.limit = pfb->ram.size - 1 ,
.conf0 = NV50_DMA_CONF0_ENABLE | 0x7a |
NV50_DMA_CONF0_PART_256,
}, sizeof(struct nv_dma_class), &object) ;
return V_13 ;
}
static int
F_14 ( struct V_1 * V_2 , T_1 V_25 )
{
struct V_26 * V_27 = V_26 ( V_2 ) ;
struct V_1 * V_9 = F_2 ( V_2 , V_10 ) ;
struct V_1 * V_28 ;
int V_13 = F_5 (client, parent, NvEvoVRAM_LP,
NV_DMA_IN_MEMORY_CLASS,
&(struct nv_dma_class) {
.flags = NV_DMA_TARGET_VRAM |
NV_DMA_ACCESS_RDWR,
.start = 0 ,
.limit = pfb->ram.size - 1 ,
.conf0 = NVC0_DMA_CONF0_ENABLE,
}, sizeof(struct nv_dma_class), &object) ;
if ( V_13 )
return V_13 ;
V_13 = F_5 (client, parent, NvEvoFB16,
NV_DMA_IN_MEMORY_CLASS,
&(struct nv_dma_class) {
.flags = NV_DMA_TARGET_VRAM |
NV_DMA_ACCESS_RDWR,
.start = 0 ,
.limit = pfb->ram.size - 1 ,
.conf0 = NVC0_DMA_CONF0_ENABLE | 0xfe ,
}, sizeof(struct nv_dma_class), &object) ;
if ( V_13 )
return V_13 ;
V_13 = F_5 (client, parent, NvEvoFB32,
NV_DMA_IN_MEMORY_CLASS,
&(struct nv_dma_class) {
.flags = NV_DMA_TARGET_VRAM |
NV_DMA_ACCESS_RDWR,
.start = 0 ,
.limit = pfb->ram.size - 1 ,
.conf0 = NVC0_DMA_CONF0_ENABLE | 0xfe ,
}, sizeof(struct nv_dma_class), &object) ;
return V_13 ;
}
static int
F_15 ( struct V_1 * V_2 , T_1 V_25 )
{
struct V_26 * V_27 = V_26 ( V_2 ) ;
struct V_1 * V_9 = F_2 ( V_2 , V_10 ) ;
struct V_1 * V_28 ;
int V_13 = F_5 (client, parent, NvEvoVRAM_LP,
NV_DMA_IN_MEMORY_CLASS,
&(struct nv_dma_class) {
.flags = NV_DMA_TARGET_VRAM |
NV_DMA_ACCESS_RDWR,
.start = 0 ,
.limit = pfb->ram.size - 1 ,
.conf0 = NVD0_DMA_CONF0_ENABLE |
NVD0_DMA_CONF0_PAGE_LP,
}, sizeof(struct nv_dma_class), &object) ;
if ( V_13 )
return V_13 ;
V_13 = F_5 (client, parent, NvEvoFB32,
NV_DMA_IN_MEMORY_CLASS,
&(struct nv_dma_class) {
.flags = NV_DMA_TARGET_VRAM |
NV_DMA_ACCESS_RDWR,
.start = 0 ,
.limit = pfb->ram.size - 1 ,
.conf0 = NVD0_DMA_CONF0_ENABLE | 0xfe |
NVD0_DMA_CONF0_PAGE_LP,
}, sizeof(struct nv_dma_class), &object) ;
return V_13 ;
}
static int
F_16 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
void * V_5 , T_1 V_6 , T_3 V_29 ,
struct V_19 * V_20 )
{
struct V_26 * V_27 = V_26 ( V_2 ) ;
struct V_1 * V_9 = F_2 ( V_2 , V_10 ) ;
struct V_1 * V_28 ;
T_1 V_30 = * ( T_1 * ) V_5 ;
int V_13 ;
V_20 -> V_21 = F_17 ( F_11 ( V_2 ) -> V_23 , V_24 ,
& V_20 -> V_12 ) ;
if ( ! V_20 -> V_21 )
return - V_31 ;
V_13 = F_5 (client, NVDRM_DEVICE, pushbuf,
NV_DMA_FROM_MEMORY_CLASS,
&(struct nv_dma_class) {
.flags = NV_DMA_TARGET_PCI_US |
NV_DMA_ACCESS_RD,
.start = dmac->handle + 0x0000 ,
.limit = dmac->handle + 0x0fff ,
}, sizeof(struct nv_dma_class), &object) ;
if ( V_13 )
return V_13 ;
V_13 = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , & V_20 -> V_18 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_5 (client, dmac->base.handle, NvEvoSync,
NV_DMA_IN_MEMORY_CLASS,
&(struct nv_dma_class) {
.flags = NV_DMA_TARGET_VRAM |
NV_DMA_ACCESS_RDWR,
.start = syncbuf + 0x0000 ,
.limit = syncbuf + 0x0fff ,
}, sizeof(struct nv_dma_class), &object) ;
if ( V_13 )
return V_13 ;
V_13 = F_5 (client, dmac->base.handle, NvEvoVRAM,
NV_DMA_IN_MEMORY_CLASS,
&(struct nv_dma_class) {
.flags = NV_DMA_TARGET_VRAM |
NV_DMA_ACCESS_RDWR,
.start = 0 ,
.limit = pfb->ram.size - 1 ,
}, sizeof(struct nv_dma_class), &object) ;
if ( V_13 )
return V_13 ;
if ( F_11 ( V_2 ) -> V_32 < V_33 )
V_13 = F_13 ( V_2 , V_20 -> V_18 . V_12 ) ;
else
if ( F_11 ( V_2 ) -> V_32 < V_34 )
V_13 = F_14 ( V_2 , V_20 -> V_18 . V_12 ) ;
else
V_13 = F_15 ( V_2 , V_20 -> V_18 . V_12 ) ;
return V_13 ;
}
static struct V_35 *
V_35 ( struct V_36 * V_37 )
{
return F_18 ( V_37 ) -> V_38 ;
}
static struct V_39 *
F_19 ( struct V_40 * V_41 )
{
return F_20 ( V_41 ) -> V_42 ;
}
static T_1 *
F_21 ( void * V_43 , int V_44 )
{
struct V_19 * V_20 = V_43 ;
T_1 V_45 = F_22 ( V_20 -> V_18 . V_15 , 0x0000 ) / 4 ;
if ( V_45 + V_44 >= ( V_24 / 4 ) - 8 ) {
V_20 -> V_21 [ V_45 ] = 0x20000000 ;
F_23 ( V_20 -> V_18 . V_15 , 0x0000 , 0x00000000 ) ;
if ( ! F_24 ( V_20 -> V_18 . V_15 , 0x0004 , ~ 0 , 0x00000000 ) ) {
F_25 ( V_20 -> V_18 . V_15 , L_1 ) ;
return NULL ;
}
V_45 = 0 ;
}
return V_20 -> V_21 + V_45 ;
}
static void
F_26 ( T_1 * V_46 , void * V_43 )
{
struct V_19 * V_20 = V_43 ;
F_23 ( V_20 -> V_18 . V_15 , 0x0000 , ( V_46 - V_20 -> V_21 ) << 2 ) ;
}
static bool
F_27 ( void * V_5 )
{
return F_28 ( V_5 , V_47 ) != 0x00000000 ;
}
static int
F_29 ( struct V_36 * V_37 )
{
struct V_48 * V_49 = F_30 ( V_37 ) ;
struct V_35 * V_50 = V_35 ( V_37 ) ;
struct V_51 * V_52 = V_51 ( V_37 ) ;
T_1 * V_46 = F_21 ( V_52 , 8 ) ;
if ( V_46 ) {
F_31 ( V_50 -> V_53 , V_47 , 0x00000000 ) ;
F_32 ( V_46 , 0x0084 , 1 ) ;
F_33 ( V_46 , 0x80000000 | V_47 ) ;
F_32 ( V_46 , 0x0080 , 2 ) ;
F_33 ( V_46 , 0x00000000 ) ;
F_33 ( V_46 , 0x00000000 ) ;
F_26 ( V_46 , V_52 ) ;
if ( F_34 ( V_49 , F_27 , V_50 -> V_53 ) )
return 0 ;
}
return - V_54 ;
}
struct V_55 *
F_35 ( struct V_36 * V_37 , int V_42 )
{
return V_35 ( V_37 ) -> V_53 ;
}
void
F_36 ( struct V_39 * V_42 )
{
struct V_56 * V_53 = V_56 ( V_42 ) ;
T_1 * V_46 ;
V_46 = F_21 ( V_53 , 8 ) ;
if ( V_46 ) {
F_32 ( V_46 , 0x0084 , 1 ) ;
F_33 ( V_46 , 0x00000000 ) ;
F_32 ( V_46 , 0x0094 , 1 ) ;
F_33 ( V_46 , 0x00000000 ) ;
F_32 ( V_46 , 0x00c0 , 1 ) ;
F_33 ( V_46 , 0x00000000 ) ;
F_32 ( V_46 , 0x0080 , 1 ) ;
F_33 ( V_46 , 0x00000000 ) ;
F_26 ( V_46 , V_53 ) ;
}
}
int
F_37 ( struct V_39 * V_42 , struct V_57 * V_58 ,
struct V_59 * V_8 , T_1 V_60 )
{
struct V_61 * V_62 = V_61 ( V_58 ) ;
struct V_35 * V_50 = V_35 ( V_42 -> V_37 ) ;
struct V_63 * V_64 = V_63 ( V_42 ) ;
struct V_56 * V_53 = V_56 ( V_42 ) ;
T_1 * V_46 ;
int V_13 ;
V_60 <<= 4 ;
if ( V_60 == 0 )
V_60 |= 0x100 ;
V_46 = F_21 ( V_53 , 128 ) ;
if ( F_38 ( V_46 == NULL ) )
return - V_54 ;
if ( F_39 ( V_8 ) ) {
V_13 = F_40 ( V_8 , 10 ) ;
if ( V_13 )
return V_13 ;
if ( F_41 ( V_8 -> V_28 ) < V_65 ) {
F_42 ( V_8 , 0 , V_66 , 2 ) ;
F_43 ( V_8 , V_67 + V_64 -> V_68 ) ;
F_43 ( V_8 , V_53 -> V_69 . V_70 ) ;
F_42 ( V_8 , 0 , V_71 , 1 ) ;
F_43 ( V_8 , 0xf00d0000 | V_53 -> V_69 . V_72 ) ;
F_42 ( V_8 , 0 , V_73 , 2 ) ;
F_43 ( V_8 , V_53 -> V_69 . V_70 ^ 0x10 ) ;
F_43 ( V_8 , 0x74b1e000 ) ;
F_42 ( V_8 , 0 , V_66 , 1 ) ;
if ( F_41 ( V_8 -> V_28 ) < V_74 )
F_43 ( V_8 , V_75 ) ;
else
F_43 ( V_8 , V_8 -> V_76 ) ;
} else {
T_3 V_70 = F_44 ( V_8 , V_64 -> V_68 ) ;
V_70 += V_53 -> V_69 . V_70 ;
F_45 ( V_8 , 0 , V_77 , 4 ) ;
F_43 ( V_8 , F_46 ( V_70 ) ) ;
F_43 ( V_8 , F_47 ( V_70 ) ) ;
F_43 ( V_8 , 0xf00d0000 | V_53 -> V_69 . V_72 ) ;
F_43 ( V_8 , 0x1002 ) ;
F_45 ( V_8 , 0 , V_77 , 4 ) ;
F_43 ( V_8 , F_46 ( V_70 ) ) ;
F_43 ( V_8 , F_47 ( V_70 ^ 0x10 ) ) ;
F_43 ( V_8 , 0x74b1e000 ) ;
F_43 ( V_8 , 0x1001 ) ;
}
F_48 ( V_8 ) ;
} else {
F_31 ( V_50 -> V_53 , V_53 -> V_69 . V_70 / 4 ,
0xf00d0000 | V_53 -> V_69 . V_72 ) ;
F_29 ( V_42 -> V_37 ) ;
}
F_32 ( V_46 , 0x0100 , 1 ) ;
F_33 ( V_46 , 0xfffe0000 ) ;
F_32 ( V_46 , 0x0084 , 1 ) ;
F_33 ( V_46 , V_60 ) ;
if ( ! ( V_60 & 0x00000100 ) ) {
F_32 ( V_46 , 0x00e0 , 1 ) ;
F_33 ( V_46 , 0x40000000 ) ;
}
F_32 ( V_46 , 0x0088 , 4 ) ;
F_33 ( V_46 , V_53 -> V_69 . V_70 ) ;
F_33 ( V_46 , 0xf00d0000 | V_53 -> V_69 . V_72 ) ;
F_33 ( V_46 , 0x74b1e000 ) ;
F_33 ( V_46 , V_78 ) ;
F_32 ( V_46 , 0x00a0 , 2 ) ;
F_33 ( V_46 , 0x00000000 ) ;
F_33 ( V_46 , 0x00000000 ) ;
F_32 ( V_46 , 0x00c0 , 1 ) ;
F_33 ( V_46 , V_62 -> V_79 ) ;
F_32 ( V_46 , 0x0110 , 2 ) ;
F_33 ( V_46 , 0x00000000 ) ;
F_33 ( V_46 , 0x00000000 ) ;
if ( F_49 ( V_53 ) < V_80 ) {
F_32 ( V_46 , 0x0800 , 5 ) ;
F_33 ( V_46 , V_62 -> V_81 -> V_82 . V_70 >> 8 ) ;
F_33 ( V_46 , 0 ) ;
F_33 ( V_46 , ( V_58 -> V_83 << 16 ) | V_58 -> V_84 ) ;
F_33 ( V_46 , V_62 -> V_85 ) ;
F_33 ( V_46 , V_62 -> V_86 ) ;
} else {
F_32 ( V_46 , 0x0400 , 5 ) ;
F_33 ( V_46 , V_62 -> V_81 -> V_82 . V_70 >> 8 ) ;
F_33 ( V_46 , 0 ) ;
F_33 ( V_46 , ( V_58 -> V_83 << 16 ) | V_58 -> V_84 ) ;
F_33 ( V_46 , V_62 -> V_85 ) ;
F_33 ( V_46 , V_62 -> V_86 ) ;
}
F_32 ( V_46 , 0x0080 , 1 ) ;
F_33 ( V_46 , 0x00000000 ) ;
F_26 ( V_46 , V_53 ) ;
V_53 -> V_69 . V_70 ^= 0x10 ;
V_53 -> V_69 . V_72 ++ ;
return 0 ;
}
static int
F_50 ( struct V_63 * V_64 , bool V_87 )
{
struct V_51 * V_52 = V_51 ( V_64 -> V_18 . V_37 ) ;
struct V_88 * V_89 ;
struct V_90 * V_91 ;
T_1 * V_46 , V_92 = 0x00 ;
V_89 = F_51 ( V_64 ) ;
V_91 = & V_89 -> V_18 ;
if ( V_89 -> V_93 == V_94 ) {
if ( V_64 -> V_18 . V_58 -> V_95 > V_91 -> V_96 . V_97 * 3 )
V_92 = V_98 ;
} else {
V_92 = V_89 -> V_93 ;
}
if ( V_89 -> V_99 == V_100 ) {
if ( V_91 -> V_96 . V_97 >= 8 )
V_92 |= V_101 ;
} else {
V_92 |= V_89 -> V_99 ;
}
V_46 = F_21 ( V_52 , 4 ) ;
if ( V_46 ) {
if ( F_49 ( V_52 ) < V_102 ) {
F_32 ( V_46 , 0x08a0 + ( V_64 -> V_68 * 0x0400 ) , 1 ) ;
F_33 ( V_46 , V_92 ) ;
} else
if ( F_49 ( V_52 ) < V_103 ) {
F_32 ( V_46 , 0x0490 + ( V_64 -> V_68 * 0x0300 ) , 1 ) ;
F_33 ( V_46 , V_92 ) ;
} else {
F_32 ( V_46 , 0x04a0 + ( V_64 -> V_68 * 0x0300 ) , 1 ) ;
F_33 ( V_46 , V_92 ) ;
}
if ( V_87 ) {
F_32 ( V_46 , 0x0080 , 1 ) ;
F_33 ( V_46 , 0x00000000 ) ;
}
F_26 ( V_46 , V_52 ) ;
}
return 0 ;
}
static int
F_52 ( struct V_63 * V_64 , bool V_87 )
{
struct V_51 * V_52 = V_51 ( V_64 -> V_18 . V_37 ) ;
struct V_104 * V_105 , * V_106 = & V_64 -> V_18 . V_92 ;
struct V_39 * V_42 = & V_64 -> V_18 ;
struct V_88 * V_89 ;
int V_92 = V_107 ;
T_1 V_108 , V_109 , * V_46 ;
V_89 = F_51 ( V_64 ) ;
if ( V_89 && V_89 -> V_110 )
V_92 = V_89 -> V_111 ;
if ( V_92 != V_107 )
V_105 = V_89 -> V_110 ;
else
V_105 = V_106 ;
V_108 = V_105 -> V_112 ;
V_109 = V_105 -> V_113 ;
if ( V_105 -> V_114 & V_115 )
V_109 *= 2 ;
if ( V_89 && ( V_89 -> V_116 == V_117 ||
( V_89 -> V_116 == V_118 &&
V_89 -> V_119 &&
F_53 ( V_89 -> V_119 ) ) ) ) {
T_1 V_120 = V_89 -> V_121 ;
T_1 V_122 = V_89 -> V_123 ;
T_1 V_124 = ( V_109 << 19 ) / V_108 ;
if ( V_120 ) {
V_108 -= ( V_120 * 2 ) ;
if ( V_122 ) V_109 -= ( V_122 * 2 ) ;
else V_109 = ( ( V_108 * V_124 ) + ( V_124 / 2 ) ) >> 19 ;
} else {
V_108 -= ( V_108 >> 4 ) + 32 ;
if ( V_122 ) V_109 -= ( V_122 * 2 ) ;
else V_109 = ( ( V_108 * V_124 ) + ( V_124 / 2 ) ) >> 19 ;
}
}
switch ( V_92 ) {
case V_125 :
V_108 = F_54 ( ( T_1 ) V_106 -> V_112 , V_108 ) ;
V_109 = F_54 ( ( T_1 ) V_106 -> V_113 , V_109 ) ;
case V_126 :
if ( V_109 < V_108 ) {
T_1 V_124 = ( V_106 -> V_112 << 19 ) / V_106 -> V_113 ;
V_108 = ( ( V_109 * V_124 ) + ( V_124 / 2 ) ) >> 19 ;
} else {
T_1 V_124 = ( V_106 -> V_113 << 19 ) / V_106 -> V_112 ;
V_109 = ( ( V_108 * V_124 ) + ( V_124 / 2 ) ) >> 19 ;
}
break;
default:
break;
}
V_46 = F_21 ( V_52 , 8 ) ;
if ( V_46 ) {
if ( F_49 ( V_52 ) < V_102 ) {
F_32 ( V_46 , 0x08d8 + ( V_64 -> V_68 * 0x400 ) , 2 ) ;
F_33 ( V_46 , ( V_109 << 16 ) | V_108 ) ;
F_33 ( V_46 , ( V_109 << 16 ) | V_108 ) ;
F_32 ( V_46 , 0x08a4 + ( V_64 -> V_68 * 0x400 ) , 1 ) ;
F_33 ( V_46 , 0x00000000 ) ;
F_32 ( V_46 , 0x08c8 + ( V_64 -> V_68 * 0x400 ) , 1 ) ;
F_33 ( V_46 , V_106 -> V_113 << 16 | V_106 -> V_112 ) ;
} else {
F_32 ( V_46 , 0x04c0 + ( V_64 -> V_68 * 0x300 ) , 3 ) ;
F_33 ( V_46 , ( V_109 << 16 ) | V_108 ) ;
F_33 ( V_46 , ( V_109 << 16 ) | V_108 ) ;
F_33 ( V_46 , ( V_109 << 16 ) | V_108 ) ;
F_32 ( V_46 , 0x0494 + ( V_64 -> V_68 * 0x300 ) , 1 ) ;
F_33 ( V_46 , 0x00000000 ) ;
F_32 ( V_46 , 0x04b8 + ( V_64 -> V_68 * 0x300 ) , 1 ) ;
F_33 ( V_46 , V_106 -> V_113 << 16 | V_106 -> V_112 ) ;
}
F_26 ( V_46 , V_52 ) ;
if ( V_87 ) {
F_36 ( V_42 ) ;
F_37 ( V_42 , V_42 -> V_58 , NULL , 1 ) ;
}
}
return 0 ;
}
static int
F_55 ( struct V_63 * V_64 , bool V_87 )
{
struct V_51 * V_52 = V_51 ( V_64 -> V_18 . V_37 ) ;
T_1 * V_46 , V_127 , V_128 ;
int V_129 ;
V_129 = ( V_64 -> V_130 > 0 ) ? 50 : 0 ;
V_128 = ( ( V_64 -> V_130 * 2047 + V_129 ) / 100 ) & 0xfff ;
V_127 = ( ( V_64 -> V_131 * 2047 ) / 100 ) & 0xfff ;
V_46 = F_21 ( V_52 , 16 ) ;
if ( V_46 ) {
if ( F_49 ( V_52 ) < V_102 ) {
F_32 ( V_46 , 0x08a8 + ( V_64 -> V_68 * 0x400 ) , 1 ) ;
F_33 ( V_46 , ( V_127 << 20 ) | ( V_128 << 8 ) ) ;
} else {
F_32 ( V_46 , 0x0498 + ( V_64 -> V_68 * 0x300 ) , 1 ) ;
F_33 ( V_46 , ( V_127 << 20 ) | ( V_128 << 8 ) ) ;
}
if ( V_87 ) {
F_32 ( V_46 , 0x0080 , 1 ) ;
F_33 ( V_46 , 0x00000000 ) ;
}
F_26 ( V_46 , V_52 ) ;
}
return 0 ;
}
static int
F_56 ( struct V_63 * V_64 , struct V_57 * V_58 ,
int V_132 , int V_133 , bool V_87 )
{
struct V_61 * V_134 = V_61 ( V_58 ) ;
struct V_51 * V_52 = V_51 ( V_64 -> V_18 . V_37 ) ;
T_1 * V_46 ;
V_46 = F_21 ( V_52 , 16 ) ;
if ( V_46 ) {
if ( F_49 ( V_52 ) < V_102 ) {
F_32 ( V_46 , 0x0860 + ( V_64 -> V_68 * 0x400 ) , 1 ) ;
F_33 ( V_46 , V_134 -> V_81 -> V_82 . V_70 >> 8 ) ;
F_32 ( V_46 , 0x0868 + ( V_64 -> V_68 * 0x400 ) , 3 ) ;
F_33 ( V_46 , ( V_58 -> V_83 << 16 ) | V_58 -> V_84 ) ;
F_33 ( V_46 , V_134 -> V_85 ) ;
F_33 ( V_46 , V_134 -> V_86 ) ;
F_32 ( V_46 , 0x08c0 + ( V_64 -> V_68 * 0x400 ) , 1 ) ;
F_33 ( V_46 , ( V_133 << 16 ) | V_132 ) ;
if ( F_49 ( V_52 ) > V_135 ) {
F_32 ( V_46 , 0x0874 + ( V_64 -> V_68 * 0x400 ) , 1 ) ;
F_33 ( V_46 , V_134 -> V_79 ) ;
}
} else {
F_32 ( V_46 , 0x0460 + ( V_64 -> V_68 * 0x300 ) , 1 ) ;
F_33 ( V_46 , V_134 -> V_81 -> V_82 . V_70 >> 8 ) ;
F_32 ( V_46 , 0x0468 + ( V_64 -> V_68 * 0x300 ) , 4 ) ;
F_33 ( V_46 , ( V_58 -> V_83 << 16 ) | V_58 -> V_84 ) ;
F_33 ( V_46 , V_134 -> V_85 ) ;
F_33 ( V_46 , V_134 -> V_86 ) ;
F_33 ( V_46 , V_134 -> V_79 ) ;
F_32 ( V_46 , 0x04b0 + ( V_64 -> V_68 * 0x300 ) , 1 ) ;
F_33 ( V_46 , ( V_133 << 16 ) | V_132 ) ;
}
if ( V_87 ) {
F_32 ( V_46 , 0x0080 , 1 ) ;
F_33 ( V_46 , 0x00000000 ) ;
}
F_26 ( V_46 , V_52 ) ;
}
V_64 -> V_58 . V_136 = V_134 -> V_79 ;
return 0 ;
}
static void
F_57 ( struct V_63 * V_64 )
{
struct V_51 * V_52 = V_51 ( V_64 -> V_18 . V_37 ) ;
T_1 * V_46 = F_21 ( V_52 , 16 ) ;
if ( V_46 ) {
if ( F_49 ( V_52 ) < V_137 ) {
F_32 ( V_46 , 0x0880 + ( V_64 -> V_68 * 0x400 ) , 2 ) ;
F_33 ( V_46 , 0x85000000 ) ;
F_33 ( V_46 , V_64 -> V_138 . V_81 -> V_82 . V_70 >> 8 ) ;
} else
if ( F_49 ( V_52 ) < V_102 ) {
F_32 ( V_46 , 0x0880 + ( V_64 -> V_68 * 0x400 ) , 2 ) ;
F_33 ( V_46 , 0x85000000 ) ;
F_33 ( V_46 , V_64 -> V_138 . V_81 -> V_82 . V_70 >> 8 ) ;
F_32 ( V_46 , 0x089c + ( V_64 -> V_68 * 0x400 ) , 1 ) ;
F_33 ( V_46 , V_139 ) ;
} else {
F_32 ( V_46 , 0x0480 + ( V_64 -> V_68 * 0x300 ) , 2 ) ;
F_33 ( V_46 , 0x85000000 ) ;
F_33 ( V_46 , V_64 -> V_138 . V_81 -> V_82 . V_70 >> 8 ) ;
F_32 ( V_46 , 0x048c + ( V_64 -> V_68 * 0x300 ) , 1 ) ;
F_33 ( V_46 , V_139 ) ;
}
F_26 ( V_46 , V_52 ) ;
}
}
static void
F_58 ( struct V_63 * V_64 )
{
struct V_51 * V_52 = V_51 ( V_64 -> V_18 . V_37 ) ;
T_1 * V_46 = F_21 ( V_52 , 16 ) ;
if ( V_46 ) {
if ( F_49 ( V_52 ) < V_137 ) {
F_32 ( V_46 , 0x0880 + ( V_64 -> V_68 * 0x400 ) , 1 ) ;
F_33 ( V_46 , 0x05000000 ) ;
} else
if ( F_49 ( V_52 ) < V_102 ) {
F_32 ( V_46 , 0x0880 + ( V_64 -> V_68 * 0x400 ) , 1 ) ;
F_33 ( V_46 , 0x05000000 ) ;
F_32 ( V_46 , 0x089c + ( V_64 -> V_68 * 0x400 ) , 1 ) ;
F_33 ( V_46 , 0x00000000 ) ;
} else {
F_32 ( V_46 , 0x0480 + ( V_64 -> V_68 * 0x300 ) , 1 ) ;
F_33 ( V_46 , 0x05000000 ) ;
F_32 ( V_46 , 0x048c + ( V_64 -> V_68 * 0x300 ) , 1 ) ;
F_33 ( V_46 , 0x00000000 ) ;
}
F_26 ( V_46 , V_52 ) ;
}
}
static void
F_59 ( struct V_63 * V_64 , bool V_140 , bool V_87 )
{
struct V_51 * V_52 = V_51 ( V_64 -> V_18 . V_37 ) ;
if ( V_140 )
F_57 ( V_64 ) ;
else
F_58 ( V_64 ) ;
if ( V_87 ) {
T_1 * V_46 = F_21 ( V_52 , 2 ) ;
if ( V_46 ) {
F_32 ( V_46 , 0x0080 , 1 ) ;
F_33 ( V_46 , 0x00000000 ) ;
F_26 ( V_46 , V_52 ) ;
}
}
}
static void
F_60 ( struct V_39 * V_42 , int V_92 )
{
}
static void
F_61 ( struct V_39 * V_42 )
{
struct V_63 * V_64 = V_63 ( V_42 ) ;
struct V_51 * V_52 = V_51 ( V_42 -> V_37 ) ;
T_1 * V_46 ;
F_36 ( V_42 ) ;
V_46 = F_21 ( V_52 , 2 ) ;
if ( V_46 ) {
if ( F_49 ( V_52 ) < V_137 ) {
F_32 ( V_46 , 0x0874 + ( V_64 -> V_68 * 0x400 ) , 1 ) ;
F_33 ( V_46 , 0x00000000 ) ;
F_32 ( V_46 , 0x0840 + ( V_64 -> V_68 * 0x400 ) , 1 ) ;
F_33 ( V_46 , 0x40000000 ) ;
} else
if ( F_49 ( V_52 ) < V_102 ) {
F_32 ( V_46 , 0x0874 + ( V_64 -> V_68 * 0x400 ) , 1 ) ;
F_33 ( V_46 , 0x00000000 ) ;
F_32 ( V_46 , 0x0840 + ( V_64 -> V_68 * 0x400 ) , 1 ) ;
F_33 ( V_46 , 0x40000000 ) ;
F_32 ( V_46 , 0x085c + ( V_64 -> V_68 * 0x400 ) , 1 ) ;
F_33 ( V_46 , 0x00000000 ) ;
} else {
F_32 ( V_46 , 0x0474 + ( V_64 -> V_68 * 0x300 ) , 1 ) ;
F_33 ( V_46 , 0x00000000 ) ;
F_32 ( V_46 , 0x0440 + ( V_64 -> V_68 * 0x300 ) , 1 ) ;
F_33 ( V_46 , 0x03000000 ) ;
F_32 ( V_46 , 0x045c + ( V_64 -> V_68 * 0x300 ) , 1 ) ;
F_33 ( V_46 , 0x00000000 ) ;
}
F_26 ( V_46 , V_52 ) ;
}
F_59 ( V_64 , false , false ) ;
}
static void
F_62 ( struct V_39 * V_42 )
{
struct V_63 * V_64 = V_63 ( V_42 ) ;
struct V_51 * V_52 = V_51 ( V_42 -> V_37 ) ;
T_1 * V_46 ;
V_46 = F_21 ( V_52 , 32 ) ;
if ( V_46 ) {
if ( F_49 ( V_52 ) < V_137 ) {
F_32 ( V_46 , 0x0874 + ( V_64 -> V_68 * 0x400 ) , 1 ) ;
F_33 ( V_46 , V_141 ) ;
F_32 ( V_46 , 0x0840 + ( V_64 -> V_68 * 0x400 ) , 2 ) ;
F_33 ( V_46 , 0xc0000000 ) ;
F_33 ( V_46 , V_64 -> V_142 . V_81 -> V_82 . V_70 >> 8 ) ;
} else
if ( F_49 ( V_52 ) < V_102 ) {
F_32 ( V_46 , 0x0874 + ( V_64 -> V_68 * 0x400 ) , 1 ) ;
F_33 ( V_46 , V_64 -> V_58 . V_136 ) ;
F_32 ( V_46 , 0x0840 + ( V_64 -> V_68 * 0x400 ) , 2 ) ;
F_33 ( V_46 , 0xc0000000 ) ;
F_33 ( V_46 , V_64 -> V_142 . V_81 -> V_82 . V_70 >> 8 ) ;
F_32 ( V_46 , 0x085c + ( V_64 -> V_68 * 0x400 ) , 1 ) ;
F_33 ( V_46 , V_139 ) ;
} else {
F_32 ( V_46 , 0x0474 + ( V_64 -> V_68 * 0x300 ) , 1 ) ;
F_33 ( V_46 , V_64 -> V_58 . V_136 ) ;
F_32 ( V_46 , 0x0440 + ( V_64 -> V_68 * 0x300 ) , 4 ) ;
F_33 ( V_46 , 0x83000000 ) ;
F_33 ( V_46 , V_64 -> V_142 . V_81 -> V_82 . V_70 >> 8 ) ;
F_33 ( V_46 , 0x00000000 ) ;
F_33 ( V_46 , 0x00000000 ) ;
F_32 ( V_46 , 0x045c + ( V_64 -> V_68 * 0x300 ) , 1 ) ;
F_33 ( V_46 , V_139 ) ;
F_32 ( V_46 , 0x0430 + ( V_64 -> V_68 * 0x300 ) , 1 ) ;
F_33 ( V_46 , 0xffffff00 ) ;
}
F_26 ( V_46 , V_52 ) ;
}
F_59 ( V_64 , V_64 -> V_138 . V_143 , true ) ;
F_37 ( V_42 , V_42 -> V_58 , NULL , 1 ) ;
}
static bool
F_63 ( struct V_39 * V_42 , const struct V_104 * V_92 ,
struct V_104 * V_144 )
{
return true ;
}
static int
F_64 ( struct V_39 * V_42 , struct V_57 * V_145 )
{
struct V_61 * V_134 = V_61 ( V_42 -> V_58 ) ;
int V_13 ;
V_13 = F_65 ( V_134 -> V_81 , V_146 ) ;
if ( V_13 )
return V_13 ;
if ( V_145 ) {
V_134 = V_61 ( V_145 ) ;
F_66 ( V_134 -> V_81 ) ;
}
return 0 ;
}
static int
F_67 ( struct V_39 * V_42 , struct V_104 * V_106 ,
struct V_104 * V_92 , int V_132 , int V_133 ,
struct V_57 * V_145 )
{
struct V_51 * V_52 = V_51 ( V_42 -> V_37 ) ;
struct V_63 * V_64 = V_63 ( V_42 ) ;
struct V_88 * V_89 ;
T_1 V_147 = ( V_92 -> V_114 & V_148 ) ? 2 : 1 ;
T_1 V_149 = ( V_92 -> V_114 & V_115 ) ? 2 : 1 ;
T_1 V_150 , V_151 , V_152 , V_153 , V_154 , V_155 ;
T_1 V_156 , V_157 , V_158 , V_159 , V_160 , V_161 ;
T_1 V_162 = 0 , V_163 = 1 ;
T_1 * V_46 ;
int V_13 ;
V_150 = V_92 -> V_164 ;
V_151 = V_92 -> V_165 - V_92 -> V_166 - 1 ;
V_152 = V_92 -> V_164 - V_92 -> V_165 ;
V_154 = V_151 + V_152 ;
V_153 = V_92 -> V_166 - V_92 -> V_112 ;
V_155 = V_92 -> V_164 - V_153 - 1 ;
V_156 = V_92 -> V_167 * V_149 / V_147 ;
V_157 = ( ( V_92 -> V_168 - V_92 -> V_169 ) * V_149 / V_147 ) - 1 ;
V_158 = ( V_92 -> V_167 - V_92 -> V_168 ) * V_149 / V_147 ;
V_160 = V_157 + V_158 ;
V_159 = ( V_92 -> V_169 - V_92 -> V_113 ) * V_149 / V_147 ;
V_161 = V_156 - V_159 - 1 ;
if ( V_92 -> V_114 & V_148 ) {
V_162 = V_156 + V_157 + V_158 ;
V_163 = V_162 + ( V_92 -> V_113 * V_149 / V_147 ) ;
V_156 = ( V_156 * 2 ) + 1 ;
}
V_13 = F_64 ( V_42 , V_145 ) ;
if ( V_13 )
return V_13 ;
V_46 = F_21 ( V_52 , 64 ) ;
if ( V_46 ) {
if ( F_49 ( V_52 ) < V_102 ) {
F_32 ( V_46 , 0x0804 + ( V_64 -> V_68 * 0x400 ) , 2 ) ;
F_33 ( V_46 , 0x00800000 | V_92 -> clock ) ;
F_33 ( V_46 , ( V_147 == 2 ) ? 2 : 0 ) ;
F_32 ( V_46 , 0x0810 + ( V_64 -> V_68 * 0x400 ) , 6 ) ;
F_33 ( V_46 , 0x00000000 ) ;
F_33 ( V_46 , ( V_156 << 16 ) | V_150 ) ;
F_33 ( V_46 , ( V_157 << 16 ) | V_151 ) ;
F_33 ( V_46 , ( V_160 << 16 ) | V_154 ) ;
F_33 ( V_46 , ( V_161 << 16 ) | V_155 ) ;
F_33 ( V_46 , ( V_162 << 16 ) | V_163 ) ;
F_32 ( V_46 , 0x082c + ( V_64 -> V_68 * 0x400 ) , 1 ) ;
F_33 ( V_46 , 0x00000000 ) ;
F_32 ( V_46 , 0x0900 + ( V_64 -> V_68 * 0x400 ) , 2 ) ;
F_33 ( V_46 , 0x00000311 ) ;
F_33 ( V_46 , 0x00000100 ) ;
} else {
F_32 ( V_46 , 0x0410 + ( V_64 -> V_68 * 0x300 ) , 6 ) ;
F_33 ( V_46 , 0x00000000 ) ;
F_33 ( V_46 , ( V_156 << 16 ) | V_150 ) ;
F_33 ( V_46 , ( V_157 << 16 ) | V_151 ) ;
F_33 ( V_46 , ( V_160 << 16 ) | V_154 ) ;
F_33 ( V_46 , ( V_161 << 16 ) | V_155 ) ;
F_33 ( V_46 , ( V_162 << 16 ) | V_163 ) ;
F_32 ( V_46 , 0x042c + ( V_64 -> V_68 * 0x300 ) , 1 ) ;
F_33 ( V_46 , 0x00000000 ) ;
F_32 ( V_46 , 0x0450 + ( V_64 -> V_68 * 0x300 ) , 3 ) ;
F_33 ( V_46 , V_92 -> clock * 1000 ) ;
F_33 ( V_46 , 0x00200000 ) ;
F_33 ( V_46 , V_92 -> clock * 1000 ) ;
F_32 ( V_46 , 0x04d0 + ( V_64 -> V_68 * 0x300 ) , 2 ) ;
F_33 ( V_46 , 0x00000311 ) ;
F_33 ( V_46 , 0x00000100 ) ;
}
F_26 ( V_46 , V_52 ) ;
}
V_89 = F_51 ( V_64 ) ;
F_50 ( V_64 , false ) ;
F_52 ( V_64 , false ) ;
F_55 ( V_64 , false ) ;
F_56 ( V_64 , V_42 -> V_58 , V_132 , V_133 , false ) ;
return 0 ;
}
static int
F_68 ( struct V_39 * V_42 , int V_132 , int V_133 ,
struct V_57 * V_145 )
{
struct V_170 * V_171 = V_170 ( V_42 -> V_37 ) ;
struct V_63 * V_64 = V_63 ( V_42 ) ;
int V_13 ;
if ( ! V_42 -> V_58 ) {
F_69 ( V_171 , L_2 ) ;
return 0 ;
}
V_13 = F_64 ( V_42 , V_145 ) ;
if ( V_13 )
return V_13 ;
F_36 ( V_42 ) ;
F_56 ( V_64 , V_42 -> V_58 , V_132 , V_133 , true ) ;
F_37 ( V_42 , V_42 -> V_58 , NULL , 1 ) ;
return 0 ;
}
static int
F_70 ( struct V_39 * V_42 ,
struct V_57 * V_58 , int V_132 , int V_133 ,
enum V_172 V_173 )
{
struct V_63 * V_64 = V_63 ( V_42 ) ;
F_36 ( V_42 ) ;
F_56 ( V_64 , V_58 , V_132 , V_133 , true ) ;
return 0 ;
}
static void
F_71 ( struct V_39 * V_42 )
{
struct V_35 * V_50 = V_35 ( V_42 -> V_37 ) ;
struct V_63 * V_64 = V_63 ( V_42 ) ;
void T_4 * V_142 = F_72 ( V_64 -> V_142 . V_81 ) ;
int V_174 ;
for ( V_174 = 0 ; V_174 < 256 ; V_174 ++ ) {
T_5 V_175 = V_64 -> V_142 . V_175 [ V_174 ] >> 2 ;
T_5 V_176 = V_64 -> V_142 . V_176 [ V_174 ] >> 2 ;
T_5 V_177 = V_64 -> V_142 . V_177 [ V_174 ] >> 2 ;
if ( F_41 ( V_50 -> V_2 ) < V_178 ) {
F_73 ( V_175 + 0x0000 , V_142 + ( V_174 * 0x08 ) + 0 ) ;
F_73 ( V_176 + 0x0000 , V_142 + ( V_174 * 0x08 ) + 2 ) ;
F_73 ( V_177 + 0x0000 , V_142 + ( V_174 * 0x08 ) + 4 ) ;
} else {
F_73 ( V_175 + 0x6000 , V_142 + ( V_174 * 0x20 ) + 0 ) ;
F_73 ( V_176 + 0x6000 , V_142 + ( V_174 * 0x20 ) + 2 ) ;
F_73 ( V_177 + 0x6000 , V_142 + ( V_174 * 0x20 ) + 4 ) ;
}
}
}
static int
F_74 ( struct V_39 * V_42 , struct V_179 * V_180 ,
T_6 V_12 , T_6 V_84 , T_6 V_83 )
{
struct V_63 * V_64 = V_63 ( V_42 ) ;
struct V_36 * V_37 = V_42 -> V_37 ;
struct V_181 * V_182 ;
struct V_55 * V_81 ;
bool V_143 = ( V_12 != 0 ) ;
int V_174 , V_13 = 0 ;
if ( V_143 ) {
if ( V_84 != 64 || V_83 != 64 )
return - V_183 ;
V_182 = F_75 ( V_37 , V_180 , V_12 ) ;
if ( F_38 ( ! V_182 ) )
return - V_184 ;
V_81 = F_76 ( V_182 ) ;
V_13 = F_77 ( V_81 ) ;
if ( V_13 == 0 ) {
for ( V_174 = 0 ; V_174 < 64 * 64 ; V_174 ++ ) {
T_1 V_185 = F_28 ( V_81 , V_174 ) ;
F_31 ( V_64 -> V_138 . V_81 , V_174 , V_185 ) ;
}
F_78 ( V_81 ) ;
}
F_79 ( V_182 ) ;
}
if ( V_143 != V_64 -> V_138 . V_143 ) {
F_59 ( V_64 , V_143 , true ) ;
V_64 -> V_138 . V_143 = V_143 ;
}
return V_13 ;
}
static int
F_80 ( struct V_39 * V_42 , int V_132 , int V_133 )
{
struct V_186 * V_187 = V_186 ( V_42 ) ;
struct V_7 * V_8 = V_7 ( V_187 ) ;
F_23 ( V_8 -> V_15 , 0x0084 , ( V_133 << 16 ) | ( V_132 & 0xffff ) ) ;
F_23 ( V_8 -> V_15 , 0x0080 , 0x00000000 ) ;
return 0 ;
}
static void
F_81 ( struct V_39 * V_42 , T_5 * V_175 , T_5 * V_176 , T_5 * V_177 ,
T_6 V_188 , T_6 V_6 )
{
struct V_63 * V_64 = V_63 ( V_42 ) ;
T_1 V_189 = F_82 ( V_188 + V_6 , ( T_1 ) 256 ) ;
T_1 V_174 ;
for ( V_174 = V_188 ; V_174 < V_189 ; V_174 ++ ) {
V_64 -> V_142 . V_175 [ V_174 ] = V_175 [ V_174 ] ;
V_64 -> V_142 . V_176 [ V_174 ] = V_176 [ V_174 ] ;
V_64 -> V_142 . V_177 [ V_174 ] = V_177 [ V_174 ] ;
}
F_71 ( V_42 ) ;
}
static void
F_83 ( struct V_39 * V_42 )
{
struct V_63 * V_64 = V_63 ( V_42 ) ;
struct V_35 * V_50 = V_35 ( V_42 -> V_37 ) ;
struct V_190 * V_4 = V_190 ( V_42 ) ;
F_10 ( V_50 -> V_2 , & V_4 -> V_191 . V_18 ) ;
F_8 ( V_50 -> V_2 , & V_4 -> V_192 . V_18 ) ;
F_10 ( V_50 -> V_2 , & V_4 -> V_53 . V_18 ) ;
F_8 ( V_50 -> V_2 , & V_4 -> V_187 . V_18 ) ;
F_78 ( V_64 -> V_138 . V_81 ) ;
if ( V_64 -> V_138 . V_81 )
F_66 ( V_64 -> V_138 . V_81 ) ;
F_84 ( NULL , & V_64 -> V_138 . V_81 ) ;
F_78 ( V_64 -> V_142 . V_81 ) ;
if ( V_64 -> V_142 . V_81 )
F_66 ( V_64 -> V_142 . V_81 ) ;
F_84 ( NULL , & V_64 -> V_142 . V_81 ) ;
F_85 ( V_42 ) ;
F_86 ( V_42 ) ;
}
static void
F_87 ( struct V_63 * V_64 , int V_132 , int V_133 )
{
}
static void
F_88 ( struct V_63 * V_64 , T_6 V_70 )
{
}
static int
F_89 ( struct V_36 * V_37 , struct V_1 * V_2 , int V_68 )
{
struct V_35 * V_50 = V_35 ( V_37 ) ;
struct V_190 * V_4 ;
struct V_39 * V_42 ;
int V_13 , V_174 ;
V_4 = F_90 ( sizeof( * V_4 ) , V_193 ) ;
if ( ! V_4 )
return - V_31 ;
V_4 -> V_18 . V_68 = V_68 ;
V_4 -> V_18 . V_194 = F_50 ;
V_4 -> V_18 . V_195 = F_52 ;
V_4 -> V_18 . V_196 = F_55 ;
V_4 -> V_18 . V_130 = 50 ;
V_4 -> V_18 . V_131 = 0 ;
V_4 -> V_18 . V_138 . V_197 = F_88 ;
V_4 -> V_18 . V_138 . V_198 = F_87 ;
for ( V_174 = 0 ; V_174 < 256 ; V_174 ++ ) {
V_4 -> V_18 . V_142 . V_175 [ V_174 ] = V_174 << 8 ;
V_4 -> V_18 . V_142 . V_176 [ V_174 ] = V_174 << 8 ;
V_4 -> V_18 . V_142 . V_177 [ V_174 ] = V_174 << 8 ;
}
V_42 = & V_4 -> V_18 . V_18 ;
F_91 ( V_37 , V_42 , & V_199 ) ;
F_92 ( V_42 , & V_200 ) ;
F_93 ( V_42 , 256 ) ;
V_13 = F_94 ( V_37 , 8192 , 0x100 , V_146 ,
0 , 0x0000 , NULL , & V_4 -> V_18 . V_142 . V_81 ) ;
if ( ! V_13 ) {
V_13 = F_65 ( V_4 -> V_18 . V_142 . V_81 , V_146 ) ;
if ( ! V_13 ) {
V_13 = F_77 ( V_4 -> V_18 . V_142 . V_81 ) ;
if ( V_13 )
F_66 ( V_4 -> V_18 . V_142 . V_81 ) ;
}
if ( V_13 )
F_84 ( NULL , & V_4 -> V_18 . V_142 . V_81 ) ;
}
if ( V_13 )
goto V_201;
F_71 ( V_42 ) ;
V_13 = F_9 (disp->core, NV50_DISP_CURS_CLASS, index,
&(struct nv50_display_curs_class) {
.head = index,
}, sizeof(struct nv50_display_curs_class),
&head->curs.base) ;
if ( V_13 )
goto V_201;
V_13 = F_94 ( V_37 , 64 * 64 * 4 , 0x100 , V_146 ,
0 , 0x0000 , NULL , & V_4 -> V_18 . V_138 . V_81 ) ;
if ( ! V_13 ) {
V_13 = F_65 ( V_4 -> V_18 . V_138 . V_81 , V_146 ) ;
if ( ! V_13 ) {
V_13 = F_77 ( V_4 -> V_18 . V_138 . V_81 ) ;
if ( V_13 )
F_66 ( V_4 -> V_18 . V_142 . V_81 ) ;
}
if ( V_13 )
F_84 ( NULL , & V_4 -> V_18 . V_138 . V_81 ) ;
}
if ( V_13 )
goto V_201;
V_13 = F_16 (disp->core, NV50_DISP_SYNC_CLASS, index,
&(struct nv50_display_sync_class) {
.pushbuf = EVO_PUSH_HANDLE(SYNC, index),
.head = index,
}, sizeof(struct nv50_display_sync_class),
disp->sync->bo.offset, &head->sync.base) ;
if ( V_13 )
goto V_201;
V_4 -> V_53 . V_69 . V_70 = F_95 ( 1 + V_68 , 0x00 ) ;
V_13 = F_9 (disp->core, NV50_DISP_OIMM_CLASS, index,
&(struct nv50_display_oimm_class) {
.head = index,
}, sizeof(struct nv50_display_oimm_class),
&head->oimm.base) ;
if ( V_13 )
goto V_201;
V_13 = F_16 (disp->core, NV50_DISP_OVLY_CLASS, index,
&(struct nv50_display_ovly_class) {
.pushbuf = EVO_PUSH_HANDLE(OVLY, index),
.head = index,
}, sizeof(struct nv50_display_ovly_class),
disp->sync->bo.offset, &head->ovly.base) ;
if ( V_13 )
goto V_201;
V_201:
if ( V_13 )
F_83 ( V_42 ) ;
return V_13 ;
}
static void
F_96 ( struct V_40 * V_41 , int V_92 )
{
struct F_20 * V_202 = F_20 ( V_41 ) ;
struct V_35 * V_50 = V_35 ( V_41 -> V_37 ) ;
int V_203 = V_202 -> V_203 ;
T_1 V_204 ;
V_204 = 0x00000000 ;
if ( V_92 == V_205 || V_92 == V_206 )
V_204 |= 0x00000001 ;
if ( V_92 == V_207 || V_92 == V_206 )
V_204 |= 0x00000004 ;
F_97 ( V_50 -> V_2 , V_208 + V_203 , V_204 ) ;
}
static bool
F_98 ( struct V_40 * V_41 ,
const struct V_104 * V_92 ,
struct V_104 * V_144 )
{
struct F_20 * V_202 = F_20 ( V_41 ) ;
struct V_88 * V_89 ;
V_89 = F_99 ( V_202 ) ;
if ( V_89 && V_89 -> V_110 ) {
if ( V_89 -> V_111 != V_107 ) {
int V_209 = V_144 -> V_18 . V_209 ;
* V_144 = * V_89 -> V_110 ;
V_144 -> V_18 . V_209 = V_209 ;
}
}
return true ;
}
static void
F_100 ( struct V_40 * V_41 )
{
}
static void
F_101 ( struct V_40 * V_41 , struct V_104 * V_92 ,
struct V_104 * V_144 )
{
struct V_51 * V_52 = V_51 ( V_41 -> V_37 ) ;
struct F_20 * V_202 = F_20 ( V_41 ) ;
struct V_63 * V_64 = V_63 ( V_41 -> V_42 ) ;
T_1 * V_46 ;
F_96 ( V_41 , V_210 ) ;
V_46 = F_21 ( V_52 , 8 ) ;
if ( V_46 ) {
if ( F_49 ( V_52 ) < V_102 ) {
T_1 V_211 = 0x00000000 ;
if ( V_92 -> V_114 & V_212 )
V_211 |= 0x00000001 ;
if ( V_92 -> V_114 & V_213 )
V_211 |= 0x00000002 ;
F_32 ( V_46 , 0x0400 + ( V_202 -> V_203 * 0x080 ) , 2 ) ;
F_33 ( V_46 , 1 << V_64 -> V_68 ) ;
F_33 ( V_46 , V_211 ) ;
} else {
T_1 V_214 = 0x31ec6000 | ( V_64 -> V_68 << 25 ) ;
T_1 V_211 = 0x00000001 ;
if ( V_92 -> V_114 & V_212 )
V_211 |= 0x00000008 ;
if ( V_92 -> V_114 & V_213 )
V_211 |= 0x00000010 ;
if ( V_92 -> V_114 & V_148 )
V_214 |= 0x00000001 ;
F_32 ( V_46 , 0x0404 + ( V_64 -> V_68 * 0x300 ) , 2 ) ;
F_33 ( V_46 , V_211 ) ;
F_33 ( V_46 , V_214 ) ;
F_32 ( V_46 , 0x0180 + ( V_202 -> V_203 * 0x020 ) , 1 ) ;
F_33 ( V_46 , 1 << V_64 -> V_68 ) ;
}
F_26 ( V_46 , V_52 ) ;
}
V_202 -> V_42 = V_41 -> V_42 ;
}
static void
F_102 ( struct V_40 * V_41 )
{
struct F_20 * V_202 = F_20 ( V_41 ) ;
struct V_51 * V_52 = V_51 ( V_41 -> V_37 ) ;
const int V_203 = V_202 -> V_203 ;
T_1 * V_46 ;
if ( V_202 -> V_42 ) {
F_61 ( V_202 -> V_42 ) ;
V_46 = F_21 ( V_52 , 4 ) ;
if ( V_46 ) {
if ( F_49 ( V_52 ) < V_102 ) {
F_32 ( V_46 , 0x0400 + ( V_203 * 0x080 ) , 1 ) ;
F_33 ( V_46 , 0x00000000 ) ;
} else {
F_32 ( V_46 , 0x0180 + ( V_203 * 0x020 ) , 1 ) ;
F_33 ( V_46 , 0x00000000 ) ;
}
F_32 ( V_46 , 0x0080 , 1 ) ;
F_33 ( V_46 , 0x00000000 ) ;
F_26 ( V_46 , V_52 ) ;
}
}
V_202 -> V_42 = NULL ;
}
static enum V_215
F_103 ( struct V_40 * V_41 , struct V_90 * V_91 )
{
struct V_35 * V_50 = V_35 ( V_41 -> V_37 ) ;
int V_13 , V_203 = F_20 ( V_41 ) -> V_203 ;
T_1 V_216 = 0 ;
V_13 = F_104 ( V_50 -> V_2 , V_217 + V_203 , & V_216 , sizeof( V_216 ) ) ;
if ( V_13 || V_216 != 7 )
return V_218 ;
return V_219 ;
}
static void
F_105 ( struct V_40 * V_41 )
{
F_106 ( V_41 ) ;
F_86 ( V_41 ) ;
}
static int
F_107 ( struct V_90 * V_91 , struct V_220 * V_221 )
{
struct V_36 * V_37 = V_91 -> V_37 ;
struct F_20 * V_202 ;
struct V_40 * V_41 ;
V_202 = F_90 ( sizeof( * V_202 ) , V_193 ) ;
if ( ! V_202 )
return - V_31 ;
V_202 -> V_222 = V_221 ;
V_202 -> V_203 = F_108 ( V_221 -> V_203 ) - 1 ;
V_41 = F_109 ( V_202 ) ;
V_41 -> V_223 = V_221 -> V_224 ;
V_41 -> V_225 = 0 ;
F_110 ( V_37 , V_41 , & V_226 , V_227 ) ;
F_111 ( V_41 , & V_228 ) ;
F_112 ( V_91 , V_41 ) ;
return 0 ;
}
static void
F_113 ( struct V_40 * V_41 , struct V_104 * V_92 )
{
struct F_20 * V_202 = F_20 ( V_41 ) ;
struct V_88 * V_89 ;
struct V_35 * V_50 = V_35 ( V_41 -> V_37 ) ;
V_89 = F_99 ( V_202 ) ;
if ( ! F_114 ( V_89 -> V_119 ) )
return;
F_115 ( & V_89 -> V_18 , V_89 -> V_119 ) ;
F_104 ( V_50 -> V_2 , V_229 + V_202 -> V_203 ,
V_89 -> V_18 . V_230 ,
V_89 -> V_18 . V_230 [ 2 ] * 4 ) ;
}
static void
F_116 ( struct V_40 * V_41 )
{
struct F_20 * V_202 = F_20 ( V_41 ) ;
struct V_35 * V_50 = V_35 ( V_41 -> V_37 ) ;
F_104 ( V_50 -> V_2 , V_229 + V_202 -> V_203 , NULL , 0 ) ;
}
static void
F_117 ( struct V_40 * V_41 , struct V_104 * V_92 )
{
struct F_20 * V_202 = F_20 ( V_41 ) ;
struct V_63 * V_64 = V_63 ( V_41 -> V_42 ) ;
struct V_88 * V_89 ;
struct V_35 * V_50 = V_35 ( V_41 -> V_37 ) ;
const T_1 V_231 = ( V_64 -> V_68 << 3 ) | V_202 -> V_203 ;
T_1 V_232 = 56 ;
T_1 V_233 ;
V_89 = F_99 ( V_202 ) ;
if ( ! F_53 ( V_89 -> V_119 ) )
return;
V_233 = V_92 -> V_164 - V_92 -> V_112 ;
V_233 -= V_232 ;
V_233 -= 18 ;
V_233 /= 32 ;
F_97 ( V_50 -> V_2 , V_234 + V_231 ,
V_235 |
( V_233 << 16 ) | V_232 ) ;
F_113 ( V_41 , V_92 ) ;
}
static void
F_118 ( struct V_40 * V_41 )
{
struct F_20 * V_202 = F_20 ( V_41 ) ;
struct V_63 * V_64 = V_63 ( V_202 -> V_42 ) ;
struct V_35 * V_50 = V_35 ( V_41 -> V_37 ) ;
const T_1 V_231 = ( V_64 -> V_68 << 3 ) | V_202 -> V_203 ;
F_116 ( V_41 ) ;
F_97 ( V_50 -> V_2 , V_234 + V_231 , 0x00000000 ) ;
}
static void
F_119 ( struct V_40 * V_41 , int V_92 )
{
struct F_20 * V_202 = F_20 ( V_41 ) ;
struct V_36 * V_37 = V_41 -> V_37 ;
struct V_35 * V_50 = V_35 ( V_37 ) ;
struct V_40 * V_236 ;
int V_203 = V_202 -> V_203 ;
V_202 -> V_237 = V_92 ;
F_120 (partner, &dev->mode_config.encoder_list, head) {
struct F_20 * V_238 = F_20 ( V_236 ) ;
if ( V_236 -> V_239 != V_240 )
continue;
if ( V_238 != V_202 &&
V_238 -> V_222 -> V_203 == V_202 -> V_222 -> V_203 ) {
if ( V_238 -> V_237 == V_210 )
return;
break;
}
}
F_97 ( V_50 -> V_2 , V_241 + V_203 , ( V_92 == V_210 ) ) ;
if ( V_202 -> V_222 -> type == V_242 )
F_121 ( V_41 , V_92 , V_202 -> V_243 . V_244 , V_50 -> V_2 ) ;
}
static bool
F_122 ( struct V_40 * V_41 ,
const struct V_104 * V_92 ,
struct V_104 * V_144 )
{
struct F_20 * V_202 = F_20 ( V_41 ) ;
struct V_88 * V_89 ;
V_89 = F_99 ( V_202 ) ;
if ( V_89 && V_89 -> V_110 ) {
if ( V_89 -> V_111 != V_107 ) {
int V_209 = V_144 -> V_18 . V_209 ;
* V_144 = * V_89 -> V_110 ;
V_144 -> V_18 . V_209 = V_209 ;
}
}
return true ;
}
static void
F_123 ( struct V_40 * V_41 )
{
struct F_20 * V_202 = F_20 ( V_41 ) ;
struct V_51 * V_52 = V_51 ( V_41 -> V_37 ) ;
const int V_203 = V_202 -> V_203 ;
T_1 * V_46 ;
if ( V_202 -> V_42 ) {
F_61 ( V_202 -> V_42 ) ;
V_46 = F_21 ( V_52 , 4 ) ;
if ( V_46 ) {
if ( F_49 ( V_52 ) < V_102 ) {
F_32 ( V_46 , 0x0600 + ( V_203 * 0x40 ) , 1 ) ;
F_33 ( V_46 , 0x00000000 ) ;
} else {
F_32 ( V_46 , 0x0200 + ( V_203 * 0x20 ) , 1 ) ;
F_33 ( V_46 , 0x00000000 ) ;
}
F_32 ( V_46 , 0x0080 , 1 ) ;
F_33 ( V_46 , 0x00000000 ) ;
F_26 ( V_46 , V_52 ) ;
}
F_118 ( V_41 ) ;
}
V_202 -> V_237 = V_206 ;
V_202 -> V_42 = NULL ;
}
static void
F_124 ( struct V_40 * V_41 )
{
F_123 ( V_41 ) ;
if ( F_20 ( V_41 ) -> V_222 -> type == V_242 )
F_29 ( V_41 -> V_37 ) ;
}
static void
F_125 ( struct V_40 * V_41 )
{
}
static void
F_126 ( struct V_40 * V_41 , struct V_104 * V_106 ,
struct V_104 * V_92 )
{
struct V_35 * V_50 = V_35 ( V_41 -> V_37 ) ;
struct V_51 * V_52 = V_51 ( V_41 -> V_37 ) ;
struct V_36 * V_37 = V_41 -> V_37 ;
struct V_170 * V_171 = V_170 ( V_37 ) ;
struct F_20 * V_202 = F_20 ( V_41 ) ;
struct V_63 * V_64 = V_63 ( V_41 -> V_42 ) ;
struct V_88 * V_89 ;
struct V_245 * V_246 = & V_171 -> V_247 ;
T_1 * V_46 , V_248 = 0 ;
T_2 V_249 = 1 << V_64 -> V_68 ;
T_2 V_250 = 0xf ;
T_2 V_95 = 0x0 ;
V_89 = F_99 ( V_202 ) ;
switch ( V_202 -> V_222 -> type ) {
case V_251 :
if ( V_202 -> V_222 -> V_252 . V_253 & 1 ) {
if ( V_92 -> clock < 165000 )
V_250 = 0x1 ;
else
V_250 = 0x5 ;
} else {
V_250 = 0x2 ;
}
F_117 ( V_41 , V_92 ) ;
break;
case V_254 :
V_250 = 0x0 ;
if ( V_246 -> V_255 ) {
if ( V_246 -> V_256 . V_257 )
V_248 |= 0x0100 ;
if ( V_246 -> V_256 . V_258 )
V_248 |= 0x0200 ;
} else {
if ( V_89 -> type == V_259 ) {
if ( ( ( T_2 * ) V_89 -> V_119 ) [ 121 ] == 2 )
V_248 |= 0x0100 ;
} else
if ( V_92 -> clock >= V_246 -> V_256 . V_260 ) {
V_248 |= 0x0100 ;
}
if ( V_248 & 0x0100 ) {
if ( V_246 -> V_256 . V_261 & 2 )
V_248 |= 0x0200 ;
} else {
if ( V_246 -> V_256 . V_261 & 1 )
V_248 |= 0x0200 ;
}
if ( V_89 -> V_18 . V_96 . V_97 == 8 )
V_248 |= 0x0200 ;
}
F_97 ( V_50 -> V_2 , V_262 + V_202 -> V_203 , V_248 ) ;
break;
case V_242 :
if ( V_89 -> V_18 . V_96 . V_97 == 6 ) {
V_202 -> V_243 . V_244 = V_92 -> clock * 18 / 8 ;
V_95 = 0x2 ;
} else
if ( V_89 -> V_18 . V_96 . V_97 == 8 ) {
V_202 -> V_243 . V_244 = V_92 -> clock * 24 / 8 ;
V_95 = 0x5 ;
} else {
V_202 -> V_243 . V_244 = V_92 -> clock * 30 / 8 ;
V_95 = 0x6 ;
}
if ( V_202 -> V_222 -> V_252 . V_253 & 1 )
V_250 = 0x8 ;
else
V_250 = 0x9 ;
break;
default:
F_127 ( 1 ) ;
break;
}
F_119 ( V_41 , V_210 ) ;
V_46 = F_21 ( V_51 ( V_37 ) , 8 ) ;
if ( V_46 ) {
if ( F_49 ( V_52 ) < V_178 ) {
F_32 ( V_46 , 0x0600 + ( V_202 -> V_203 * 0x040 ) , 1 ) ;
F_33 ( V_46 , ( V_95 << 16 ) | ( V_250 << 8 ) | V_249 ) ;
} else {
T_1 V_214 = 0x31ec6000 | ( V_64 -> V_68 << 25 ) ;
T_1 V_211 = 0x00000001 ;
if ( V_92 -> V_114 & V_212 )
V_211 |= 0x00000008 ;
if ( V_92 -> V_114 & V_213 )
V_211 |= 0x00000010 ;
if ( V_92 -> V_114 & V_148 )
V_214 |= 0x00000001 ;
F_32 ( V_46 , 0x0404 + ( V_64 -> V_68 * 0x300 ) , 2 ) ;
F_33 ( V_46 , V_211 | ( V_95 << 6 ) ) ;
F_33 ( V_46 , V_214 ) ;
F_32 ( V_46 , 0x0200 + ( V_202 -> V_203 * 0x020 ) , 1 ) ;
F_33 ( V_46 , V_249 | ( V_250 << 8 ) ) ;
}
F_26 ( V_46 , V_52 ) ;
}
V_202 -> V_42 = V_41 -> V_42 ;
}
static void
F_128 ( struct V_40 * V_41 )
{
F_106 ( V_41 ) ;
F_86 ( V_41 ) ;
}
static int
F_129 ( struct V_90 * V_91 , struct V_220 * V_221 )
{
struct V_36 * V_37 = V_91 -> V_37 ;
struct F_20 * V_202 ;
struct V_40 * V_41 ;
V_202 = F_90 ( sizeof( * V_202 ) , V_193 ) ;
if ( ! V_202 )
return - V_31 ;
V_202 -> V_222 = V_221 ;
V_202 -> V_203 = F_108 ( V_221 -> V_203 ) - 1 ;
V_202 -> V_237 = V_206 ;
V_41 = F_109 ( V_202 ) ;
V_41 -> V_223 = V_221 -> V_224 ;
V_41 -> V_225 = 0 ;
F_110 ( V_37 , V_41 , & V_263 , V_240 ) ;
F_111 ( V_41 , & V_264 ) ;
F_112 ( V_91 , V_41 ) ;
return 0 ;
}
void
F_130 ( struct V_36 * V_37 )
{
}
int
F_131 ( struct V_36 * V_37 )
{
T_1 * V_46 = F_21 ( V_51 ( V_37 ) , 32 ) ;
if ( V_46 ) {
F_32 ( V_46 , 0x0088 , 1 ) ;
F_33 ( V_46 , V_78 ) ;
F_26 ( V_46 , V_51 ( V_37 ) ) ;
return F_29 ( V_37 ) ;
}
return - V_54 ;
}
void
F_132 ( struct V_36 * V_37 )
{
struct V_35 * V_50 = V_35 ( V_37 ) ;
F_10 ( V_50 -> V_2 , & V_50 -> V_52 . V_18 ) ;
F_78 ( V_50 -> V_53 ) ;
if ( V_50 -> V_53 )
F_66 ( V_50 -> V_53 ) ;
F_84 ( NULL , & V_50 -> V_53 ) ;
F_18 ( V_37 ) -> V_38 = NULL ;
F_86 ( V_50 ) ;
}
int
F_133 ( struct V_36 * V_37 )
{
static const T_5 V_11 [] = {
V_265 ,
V_178 ,
V_266 ,
V_267 ,
V_268 ,
V_269 ,
V_270 ,
} ;
struct V_48 * V_49 = F_30 ( V_37 ) ;
struct V_170 * V_171 = V_170 ( V_37 ) ;
struct V_271 * V_222 = & V_171 -> V_247 . V_222 ;
struct V_90 * V_91 , * V_272 ;
struct V_35 * V_50 ;
struct V_220 * V_221 ;
int V_273 , V_13 , V_174 ;
V_50 = F_90 ( sizeof( * V_50 ) , V_193 ) ;
if ( ! V_50 )
return - V_31 ;
F_18 ( V_37 ) -> V_38 = V_50 ;
F_18 ( V_37 ) -> V_274 = F_132 ;
F_18 ( V_37 ) -> V_275 = F_131 ;
F_18 ( V_37 ) -> V_276 = F_130 ;
V_13 = F_94 ( V_37 , 4096 , 0x1000 , V_146 ,
0 , 0x0000 , NULL , & V_50 -> V_53 ) ;
if ( ! V_13 ) {
V_13 = F_65 ( V_50 -> V_53 , V_146 ) ;
if ( ! V_13 ) {
V_13 = F_77 ( V_50 -> V_53 ) ;
if ( V_13 )
F_66 ( V_50 -> V_53 ) ;
}
if ( V_13 )
F_84 ( NULL , & V_50 -> V_53 ) ;
}
if ( V_13 )
goto V_201;
V_13 = - V_277 ;
for ( V_174 = 0 ; V_13 && V_174 < F_134 ( V_11 ) ; V_174 ++ ) {
V_13 = F_5 ( F_135 ( V_171 ) , V_278 ,
0xd1500000 , V_11 [ V_174 ] , NULL , 0 ,
& V_50 -> V_2 ) ;
}
if ( V_13 )
goto V_201;
V_13 = F_16 (disp->core, NV50_DISP_MAST_CLASS, 0 ,
&(struct nv50_display_mast_class) {
.pushbuf = EVO_PUSH_HANDLE(MAST, 0),
}, sizeof(struct nv50_display_mast_class),
disp->sync->bo.offset, &disp->mast.base) ;
if ( V_13 )
goto V_201;
if ( F_41 ( V_50 -> V_2 ) >= V_178 )
V_273 = F_136 ( V_49 , 0x022448 ) ;
else
V_273 = 2 ;
for ( V_174 = 0 ; V_174 < V_273 ; V_174 ++ ) {
V_13 = F_89 ( V_37 , V_50 -> V_2 , V_174 ) ;
if ( V_13 )
goto V_201;
}
for ( V_174 = 0 , V_221 = & V_222 -> V_279 [ 0 ] ; V_174 < V_222 -> V_280 ; V_174 ++ , V_221 ++ ) {
V_91 = F_137 ( V_37 , V_221 -> V_91 ) ;
if ( F_138 ( V_91 ) )
continue;
if ( V_221 -> V_281 != V_282 ) {
F_139 ( V_171 , L_3 ,
V_221 -> type , F_108 ( V_221 -> V_203 ) - 1 ) ;
continue;
}
switch ( V_221 -> type ) {
case V_251 :
case V_254 :
case V_242 :
F_129 ( V_91 , V_221 ) ;
break;
case V_283 :
F_107 ( V_91 , V_221 ) ;
break;
default:
F_139 ( V_171 , L_4 ,
V_221 -> type , F_108 ( V_221 -> V_203 ) - 1 ) ;
continue;
}
}
F_140 (connector, tmp, &dev->mode_config.connector_list, head) {
if ( V_91 -> V_284 [ 0 ] )
continue;
F_139 ( V_171 , L_5 ,
F_141 ( V_91 ) ) ;
V_91 -> V_285 -> V_286 ( V_91 ) ;
}
V_201:
if ( V_13 )
F_132 ( V_37 ) ;
return V_13 ;
}

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
.limit = pfb->ram->size - 1 ,
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
.limit = pfb->ram->size - 1 ,
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
.limit = pfb->ram->size - 1 ,
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
.limit = pfb->ram->size - 1 ,
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
.limit = pfb->ram->size - 1 ,
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
.limit = pfb->ram->size - 1 ,
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
.limit = pfb->ram->size - 1 ,
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
.limit = pfb->ram->size - 1 ,
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
F_17 ( & V_20 -> V_31 ) ;
V_20 -> V_21 = F_18 ( F_11 ( V_2 ) -> V_23 , V_24 ,
& V_20 -> V_12 ) ;
if ( ! V_20 -> V_21 )
return - V_32 ;
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
.limit = pfb->ram->size - 1 ,
}, sizeof(struct nv_dma_class), &object) ;
if ( V_13 )
return V_13 ;
if ( F_11 ( V_2 ) -> V_33 < V_34 )
V_13 = F_13 ( V_2 , V_20 -> V_18 . V_12 ) ;
else
if ( F_11 ( V_2 ) -> V_33 < V_35 )
V_13 = F_14 ( V_2 , V_20 -> V_18 . V_12 ) ;
else
V_13 = F_15 ( V_2 , V_20 -> V_18 . V_12 ) ;
return V_13 ;
}
static struct V_36 *
V_36 ( struct V_37 * V_38 )
{
return F_19 ( V_38 ) -> V_39 ;
}
static struct V_40 *
F_20 ( struct V_41 * V_42 )
{
return F_21 ( V_42 ) -> V_43 ;
}
static T_1 *
F_22 ( void * V_44 , int V_45 )
{
struct V_19 * V_20 = V_44 ;
T_1 V_46 = F_23 ( V_20 -> V_18 . V_15 , 0x0000 ) / 4 ;
F_24 ( & V_20 -> V_31 ) ;
if ( V_46 + V_45 >= ( V_24 / 4 ) - 8 ) {
V_20 -> V_21 [ V_46 ] = 0x20000000 ;
F_25 ( V_20 -> V_18 . V_15 , 0x0000 , 0x00000000 ) ;
if ( ! F_26 ( V_20 -> V_18 . V_15 , 0x0004 , ~ 0 , 0x00000000 ) ) {
F_27 ( & V_20 -> V_31 ) ;
F_28 ( V_20 -> V_18 . V_15 , L_1 ) ;
return NULL ;
}
V_46 = 0 ;
}
return V_20 -> V_21 + V_46 ;
}
static void
F_29 ( T_1 * V_47 , void * V_44 )
{
struct V_19 * V_20 = V_44 ;
F_25 ( V_20 -> V_18 . V_15 , 0x0000 , ( V_47 - V_20 -> V_21 ) << 2 ) ;
F_27 ( & V_20 -> V_31 ) ;
}
static bool
F_30 ( void * V_5 )
{
if ( F_31 ( V_5 , V_48 ) != 0x00000000 )
return true ;
F_32 ( 1 , 2 ) ;
return false ;
}
static int
F_33 ( struct V_37 * V_38 )
{
struct V_49 * V_50 = F_34 ( V_38 ) ;
struct V_36 * V_51 = V_36 ( V_38 ) ;
struct V_52 * V_53 = V_52 ( V_38 ) ;
T_1 * V_47 = F_22 ( V_53 , 8 ) ;
if ( V_47 ) {
F_35 ( V_51 -> V_54 , V_48 , 0x00000000 ) ;
F_36 ( V_47 , 0x0084 , 1 ) ;
F_37 ( V_47 , 0x80000000 | V_48 ) ;
F_36 ( V_47 , 0x0080 , 2 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_29 ( V_47 , V_53 ) ;
if ( F_38 ( V_50 , F_30 , V_51 -> V_54 ) )
return 0 ;
}
return - V_55 ;
}
struct V_56 *
F_39 ( struct V_37 * V_38 , int V_43 )
{
return V_36 ( V_38 ) -> V_54 ;
}
static bool
F_40 ( void * V_5 )
{
struct V_57 * V_58 = V_5 ;
if ( F_31 ( V_58 -> V_51 -> V_54 , V_58 -> V_8 -> V_59 / 4 ) ==
V_58 -> V_8 -> V_5 )
return true ;
F_32 ( 1 , 2 ) ;
return false ;
}
void
F_41 ( struct V_40 * V_43 )
{
struct V_49 * V_50 = F_34 ( V_43 -> V_38 ) ;
struct V_57 V_58 = {
. V_51 = V_36 ( V_43 -> V_38 ) ,
. V_8 = F_42 ( V_43 ) ,
} ;
T_1 * V_47 ;
V_47 = F_22 ( V_58 . V_8 , 8 ) ;
if ( V_47 ) {
F_36 ( V_47 , 0x0084 , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_36 ( V_47 , 0x0094 , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_36 ( V_47 , 0x00c0 , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_36 ( V_47 , 0x0080 , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_29 ( V_47 , V_58 . V_8 ) ;
}
F_38 ( V_50 , F_40 , & V_58 ) ;
}
int
F_43 ( struct V_40 * V_43 , struct V_60 * V_61 ,
struct V_62 * V_8 , T_1 V_63 )
{
struct V_64 * V_65 = V_64 ( V_61 ) ;
struct V_66 * V_67 = V_66 ( V_43 ) ;
struct V_68 * V_4 = V_68 ( V_43 ) ;
struct F_42 * V_54 = F_42 ( V_43 ) ;
T_1 * V_47 ;
int V_13 ;
V_63 <<= 4 ;
if ( V_63 == 0 )
V_63 |= 0x100 ;
if ( V_8 == NULL )
F_33 ( V_43 -> V_38 ) ;
V_47 = F_22 ( V_54 , 128 ) ;
if ( F_44 ( V_47 == NULL ) )
return - V_55 ;
if ( V_8 && F_45 ( V_8 -> V_28 ) < V_69 ) {
V_13 = F_46 ( V_8 , 8 ) ;
if ( V_13 )
return V_13 ;
F_47 ( V_8 , 0 , V_70 , 2 ) ;
F_48 ( V_8 , V_71 + V_67 -> V_72 ) ;
F_48 ( V_8 , V_54 -> V_59 ^ 0x10 ) ;
F_47 ( V_8 , 0 , V_73 , 1 ) ;
F_48 ( V_8 , V_54 -> V_5 + 1 ) ;
F_47 ( V_8 , 0 , V_74 , 2 ) ;
F_48 ( V_8 , V_54 -> V_59 ) ;
F_48 ( V_8 , V_54 -> V_5 ) ;
} else
if ( V_8 && F_45 ( V_8 -> V_28 ) < V_75 ) {
T_3 V_59 = F_49 ( V_8 , V_67 -> V_72 ) + V_54 -> V_59 ;
V_13 = F_46 ( V_8 , 12 ) ;
if ( V_13 )
return V_13 ;
F_47 ( V_8 , 0 , V_70 , 1 ) ;
F_48 ( V_8 , V_8 -> V_76 ) ;
F_47 ( V_8 , 0 , V_77 , 4 ) ;
F_48 ( V_8 , F_50 ( V_59 ^ 0x10 ) ) ;
F_48 ( V_8 , F_51 ( V_59 ^ 0x10 ) ) ;
F_48 ( V_8 , V_54 -> V_5 + 1 ) ;
F_48 ( V_8 , V_78 ) ;
F_47 ( V_8 , 0 , V_77 , 4 ) ;
F_48 ( V_8 , F_50 ( V_59 ) ) ;
F_48 ( V_8 , F_51 ( V_59 ) ) ;
F_48 ( V_8 , V_54 -> V_5 ) ;
F_48 ( V_8 , V_79 ) ;
} else
if ( V_8 ) {
T_3 V_59 = F_49 ( V_8 , V_67 -> V_72 ) + V_54 -> V_59 ;
V_13 = F_46 ( V_8 , 10 ) ;
if ( V_13 )
return V_13 ;
F_52 ( V_8 , 0 , V_77 , 4 ) ;
F_48 ( V_8 , F_50 ( V_59 ^ 0x10 ) ) ;
F_48 ( V_8 , F_51 ( V_59 ^ 0x10 ) ) ;
F_48 ( V_8 , V_54 -> V_5 + 1 ) ;
F_48 ( V_8 , V_78 |
V_80 ) ;
F_52 ( V_8 , 0 , V_77 , 4 ) ;
F_48 ( V_8 , F_50 ( V_59 ) ) ;
F_48 ( V_8 , F_51 ( V_59 ) ) ;
F_48 ( V_8 , V_54 -> V_5 ) ;
F_48 ( V_8 , V_79 |
V_80 ) ;
}
if ( V_8 ) {
V_54 -> V_59 ^= 0x10 ;
V_54 -> V_5 ++ ;
F_53 ( V_8 ) ;
}
F_36 ( V_47 , 0x0100 , 1 ) ;
F_37 ( V_47 , 0xfffe0000 ) ;
F_36 ( V_47 , 0x0084 , 1 ) ;
F_37 ( V_47 , V_63 ) ;
if ( ! ( V_63 & 0x00000100 ) ) {
F_36 ( V_47 , 0x00e0 , 1 ) ;
F_37 ( V_47 , 0x40000000 ) ;
}
F_36 ( V_47 , 0x0088 , 4 ) ;
F_37 ( V_47 , V_54 -> V_59 ) ;
F_37 ( V_47 , V_54 -> V_5 ++ ) ;
F_37 ( V_47 , V_54 -> V_5 ) ;
F_37 ( V_47 , V_81 ) ;
F_36 ( V_47 , 0x00a0 , 2 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_36 ( V_47 , 0x00c0 , 1 ) ;
F_37 ( V_47 , V_65 -> V_82 ) ;
F_36 ( V_47 , 0x0110 , 2 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_37 ( V_47 , 0x00000000 ) ;
if ( F_54 ( V_54 ) < V_83 ) {
F_36 ( V_47 , 0x0800 , 5 ) ;
F_37 ( V_47 , V_65 -> V_84 -> V_85 . V_86 >> 8 ) ;
F_37 ( V_47 , 0 ) ;
F_37 ( V_47 , ( V_61 -> V_87 << 16 ) | V_61 -> V_88 ) ;
F_37 ( V_47 , V_65 -> V_89 ) ;
F_37 ( V_47 , V_65 -> V_90 ) ;
} else {
F_36 ( V_47 , 0x0400 , 5 ) ;
F_37 ( V_47 , V_65 -> V_84 -> V_85 . V_86 >> 8 ) ;
F_37 ( V_47 , 0 ) ;
F_37 ( V_47 , ( V_61 -> V_87 << 16 ) | V_61 -> V_88 ) ;
F_37 ( V_47 , V_65 -> V_89 ) ;
F_37 ( V_47 , V_65 -> V_90 ) ;
}
F_36 ( V_47 , 0x0080 , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_29 ( V_47 , V_54 ) ;
F_55 ( V_65 -> V_84 , & V_4 -> V_91 ) ;
return 0 ;
}
static int
F_56 ( struct V_66 * V_67 , bool V_92 )
{
struct V_52 * V_53 = V_52 ( V_67 -> V_18 . V_38 ) ;
struct V_93 * V_94 ;
struct V_95 * V_96 ;
T_1 * V_47 , V_97 = 0x00 ;
V_94 = F_57 ( V_67 ) ;
V_96 = & V_94 -> V_18 ;
if ( V_94 -> V_98 == V_99 ) {
if ( V_67 -> V_18 . V_100 -> V_61 -> V_101 > V_96 -> V_102 . V_103 * 3 )
V_97 = V_104 ;
} else {
V_97 = V_94 -> V_98 ;
}
if ( V_94 -> V_105 == V_106 ) {
if ( V_96 -> V_102 . V_103 >= 8 )
V_97 |= V_107 ;
} else {
V_97 |= V_94 -> V_105 ;
}
V_47 = F_22 ( V_53 , 4 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_108 ) {
F_36 ( V_47 , 0x08a0 + ( V_67 -> V_72 * 0x0400 ) , 1 ) ;
F_37 ( V_47 , V_97 ) ;
} else
if ( F_54 ( V_53 ) < V_109 ) {
F_36 ( V_47 , 0x0490 + ( V_67 -> V_72 * 0x0300 ) , 1 ) ;
F_37 ( V_47 , V_97 ) ;
} else {
F_36 ( V_47 , 0x04a0 + ( V_67 -> V_72 * 0x0300 ) , 1 ) ;
F_37 ( V_47 , V_97 ) ;
}
if ( V_92 ) {
F_36 ( V_47 , 0x0080 , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
}
F_29 ( V_47 , V_53 ) ;
}
return 0 ;
}
static int
F_58 ( struct V_66 * V_67 , bool V_92 )
{
struct V_52 * V_53 = V_52 ( V_67 -> V_18 . V_38 ) ;
struct V_110 * V_111 , * V_112 = & V_67 -> V_18 . V_97 ;
struct V_40 * V_43 = & V_67 -> V_18 ;
struct V_93 * V_94 ;
int V_97 = V_113 ;
T_1 V_114 , V_115 , * V_47 ;
V_94 = F_57 ( V_67 ) ;
if ( V_94 && V_94 -> V_116 )
V_97 = V_94 -> V_117 ;
if ( V_97 != V_113 )
V_111 = V_94 -> V_116 ;
else
V_111 = V_112 ;
V_114 = V_111 -> V_118 ;
V_115 = V_111 -> V_119 ;
if ( V_111 -> V_120 & V_121 )
V_115 *= 2 ;
if ( V_94 && ( V_94 -> V_122 == V_123 ||
( V_94 -> V_122 == V_124 &&
V_94 -> V_125 &&
F_59 ( V_94 -> V_125 ) ) ) ) {
T_1 V_126 = V_94 -> V_127 ;
T_1 V_128 = V_94 -> V_129 ;
T_1 V_130 = ( V_115 << 19 ) / V_114 ;
if ( V_126 ) {
V_114 -= ( V_126 * 2 ) ;
if ( V_128 ) V_115 -= ( V_128 * 2 ) ;
else V_115 = ( ( V_114 * V_130 ) + ( V_130 / 2 ) ) >> 19 ;
} else {
V_114 -= ( V_114 >> 4 ) + 32 ;
if ( V_128 ) V_115 -= ( V_128 * 2 ) ;
else V_115 = ( ( V_114 * V_130 ) + ( V_130 / 2 ) ) >> 19 ;
}
}
switch ( V_97 ) {
case V_131 :
V_114 = F_60 ( ( T_1 ) V_112 -> V_118 , V_114 ) ;
V_115 = F_60 ( ( T_1 ) V_112 -> V_119 , V_115 ) ;
case V_132 :
if ( V_115 < V_114 ) {
T_1 V_130 = ( V_112 -> V_118 << 19 ) / V_112 -> V_119 ;
V_114 = ( ( V_115 * V_130 ) + ( V_130 / 2 ) ) >> 19 ;
} else {
T_1 V_130 = ( V_112 -> V_119 << 19 ) / V_112 -> V_118 ;
V_115 = ( ( V_114 * V_130 ) + ( V_130 / 2 ) ) >> 19 ;
}
break;
default:
break;
}
V_47 = F_22 ( V_53 , 8 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_108 ) {
F_36 ( V_47 , 0x08d8 + ( V_67 -> V_72 * 0x400 ) , 2 ) ;
F_37 ( V_47 , ( V_115 << 16 ) | V_114 ) ;
F_37 ( V_47 , ( V_115 << 16 ) | V_114 ) ;
F_36 ( V_47 , 0x08a4 + ( V_67 -> V_72 * 0x400 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_36 ( V_47 , 0x08c8 + ( V_67 -> V_72 * 0x400 ) , 1 ) ;
F_37 ( V_47 , V_112 -> V_119 << 16 | V_112 -> V_118 ) ;
} else {
F_36 ( V_47 , 0x04c0 + ( V_67 -> V_72 * 0x300 ) , 3 ) ;
F_37 ( V_47 , ( V_115 << 16 ) | V_114 ) ;
F_37 ( V_47 , ( V_115 << 16 ) | V_114 ) ;
F_37 ( V_47 , ( V_115 << 16 ) | V_114 ) ;
F_36 ( V_47 , 0x0494 + ( V_67 -> V_72 * 0x300 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_36 ( V_47 , 0x04b8 + ( V_67 -> V_72 * 0x300 ) , 1 ) ;
F_37 ( V_47 , V_112 -> V_119 << 16 | V_112 -> V_118 ) ;
}
F_29 ( V_47 , V_53 ) ;
if ( V_92 ) {
F_41 ( V_43 ) ;
F_43 ( V_43 , V_43 -> V_100 -> V_61 ,
NULL , 1 ) ;
}
}
return 0 ;
}
static int
F_61 ( struct V_66 * V_67 , bool V_92 )
{
struct V_52 * V_53 = V_52 ( V_67 -> V_18 . V_38 ) ;
T_1 * V_47 , V_133 , V_134 ;
int V_135 ;
V_135 = ( V_67 -> V_136 > 0 ) ? 50 : 0 ;
V_134 = ( ( V_67 -> V_136 * 2047 + V_135 ) / 100 ) & 0xfff ;
V_133 = ( ( V_67 -> V_137 * 2047 ) / 100 ) & 0xfff ;
V_47 = F_22 ( V_53 , 16 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_108 ) {
F_36 ( V_47 , 0x08a8 + ( V_67 -> V_72 * 0x400 ) , 1 ) ;
F_37 ( V_47 , ( V_133 << 20 ) | ( V_134 << 8 ) ) ;
} else {
F_36 ( V_47 , 0x0498 + ( V_67 -> V_72 * 0x300 ) , 1 ) ;
F_37 ( V_47 , ( V_133 << 20 ) | ( V_134 << 8 ) ) ;
}
if ( V_92 ) {
F_36 ( V_47 , 0x0080 , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
}
F_29 ( V_47 , V_53 ) ;
}
return 0 ;
}
static int
F_62 ( struct V_66 * V_67 , struct V_60 * V_61 ,
int V_138 , int V_139 , bool V_92 )
{
struct V_64 * V_140 = V_64 ( V_61 ) ;
struct V_52 * V_53 = V_52 ( V_67 -> V_18 . V_38 ) ;
T_1 * V_47 ;
V_47 = F_22 ( V_53 , 16 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_108 ) {
F_36 ( V_47 , 0x0860 + ( V_67 -> V_72 * 0x400 ) , 1 ) ;
F_37 ( V_47 , V_140 -> V_84 -> V_85 . V_86 >> 8 ) ;
F_36 ( V_47 , 0x0868 + ( V_67 -> V_72 * 0x400 ) , 3 ) ;
F_37 ( V_47 , ( V_61 -> V_87 << 16 ) | V_61 -> V_88 ) ;
F_37 ( V_47 , V_140 -> V_89 ) ;
F_37 ( V_47 , V_140 -> V_90 ) ;
F_36 ( V_47 , 0x08c0 + ( V_67 -> V_72 * 0x400 ) , 1 ) ;
F_37 ( V_47 , ( V_139 << 16 ) | V_138 ) ;
if ( F_54 ( V_53 ) > V_141 ) {
F_36 ( V_47 , 0x0874 + ( V_67 -> V_72 * 0x400 ) , 1 ) ;
F_37 ( V_47 , V_140 -> V_82 ) ;
}
} else {
F_36 ( V_47 , 0x0460 + ( V_67 -> V_72 * 0x300 ) , 1 ) ;
F_37 ( V_47 , V_140 -> V_84 -> V_85 . V_86 >> 8 ) ;
F_36 ( V_47 , 0x0468 + ( V_67 -> V_72 * 0x300 ) , 4 ) ;
F_37 ( V_47 , ( V_61 -> V_87 << 16 ) | V_61 -> V_88 ) ;
F_37 ( V_47 , V_140 -> V_89 ) ;
F_37 ( V_47 , V_140 -> V_90 ) ;
F_37 ( V_47 , V_140 -> V_82 ) ;
F_36 ( V_47 , 0x04b0 + ( V_67 -> V_72 * 0x300 ) , 1 ) ;
F_37 ( V_47 , ( V_139 << 16 ) | V_138 ) ;
}
if ( V_92 ) {
F_36 ( V_47 , 0x0080 , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
}
F_29 ( V_47 , V_53 ) ;
}
V_67 -> V_61 . V_142 = V_140 -> V_82 ;
return 0 ;
}
static void
F_63 ( struct V_66 * V_67 )
{
struct V_52 * V_53 = V_52 ( V_67 -> V_18 . V_38 ) ;
T_1 * V_47 = F_22 ( V_53 , 16 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_143 ) {
F_36 ( V_47 , 0x0880 + ( V_67 -> V_72 * 0x400 ) , 2 ) ;
F_37 ( V_47 , 0x85000000 ) ;
F_37 ( V_47 , V_67 -> V_144 . V_84 -> V_85 . V_86 >> 8 ) ;
} else
if ( F_54 ( V_53 ) < V_108 ) {
F_36 ( V_47 , 0x0880 + ( V_67 -> V_72 * 0x400 ) , 2 ) ;
F_37 ( V_47 , 0x85000000 ) ;
F_37 ( V_47 , V_67 -> V_144 . V_84 -> V_85 . V_86 >> 8 ) ;
F_36 ( V_47 , 0x089c + ( V_67 -> V_72 * 0x400 ) , 1 ) ;
F_37 ( V_47 , V_145 ) ;
} else {
F_36 ( V_47 , 0x0480 + ( V_67 -> V_72 * 0x300 ) , 2 ) ;
F_37 ( V_47 , 0x85000000 ) ;
F_37 ( V_47 , V_67 -> V_144 . V_84 -> V_85 . V_86 >> 8 ) ;
F_36 ( V_47 , 0x048c + ( V_67 -> V_72 * 0x300 ) , 1 ) ;
F_37 ( V_47 , V_145 ) ;
}
F_29 ( V_47 , V_53 ) ;
}
}
static void
F_64 ( struct V_66 * V_67 )
{
struct V_52 * V_53 = V_52 ( V_67 -> V_18 . V_38 ) ;
T_1 * V_47 = F_22 ( V_53 , 16 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_143 ) {
F_36 ( V_47 , 0x0880 + ( V_67 -> V_72 * 0x400 ) , 1 ) ;
F_37 ( V_47 , 0x05000000 ) ;
} else
if ( F_54 ( V_53 ) < V_108 ) {
F_36 ( V_47 , 0x0880 + ( V_67 -> V_72 * 0x400 ) , 1 ) ;
F_37 ( V_47 , 0x05000000 ) ;
F_36 ( V_47 , 0x089c + ( V_67 -> V_72 * 0x400 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
} else {
F_36 ( V_47 , 0x0480 + ( V_67 -> V_72 * 0x300 ) , 1 ) ;
F_37 ( V_47 , 0x05000000 ) ;
F_36 ( V_47 , 0x048c + ( V_67 -> V_72 * 0x300 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
}
F_29 ( V_47 , V_53 ) ;
}
}
static void
F_65 ( struct V_66 * V_67 , bool V_146 , bool V_92 )
{
struct V_52 * V_53 = V_52 ( V_67 -> V_18 . V_38 ) ;
if ( V_146 )
F_63 ( V_67 ) ;
else
F_64 ( V_67 ) ;
if ( V_92 ) {
T_1 * V_47 = F_22 ( V_53 , 2 ) ;
if ( V_47 ) {
F_36 ( V_47 , 0x0080 , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_29 ( V_47 , V_53 ) ;
}
}
}
static void
F_66 ( struct V_40 * V_43 , int V_97 )
{
}
static void
F_67 ( struct V_40 * V_43 )
{
struct V_66 * V_67 = V_66 ( V_43 ) ;
struct V_52 * V_53 = V_52 ( V_43 -> V_38 ) ;
T_1 * V_47 ;
F_41 ( V_43 ) ;
V_47 = F_22 ( V_53 , 2 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_143 ) {
F_36 ( V_47 , 0x0874 + ( V_67 -> V_72 * 0x400 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_36 ( V_47 , 0x0840 + ( V_67 -> V_72 * 0x400 ) , 1 ) ;
F_37 ( V_47 , 0x40000000 ) ;
} else
if ( F_54 ( V_53 ) < V_108 ) {
F_36 ( V_47 , 0x0874 + ( V_67 -> V_72 * 0x400 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_36 ( V_47 , 0x0840 + ( V_67 -> V_72 * 0x400 ) , 1 ) ;
F_37 ( V_47 , 0x40000000 ) ;
F_36 ( V_47 , 0x085c + ( V_67 -> V_72 * 0x400 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
} else {
F_36 ( V_47 , 0x0474 + ( V_67 -> V_72 * 0x300 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_36 ( V_47 , 0x0440 + ( V_67 -> V_72 * 0x300 ) , 1 ) ;
F_37 ( V_47 , 0x03000000 ) ;
F_36 ( V_47 , 0x045c + ( V_67 -> V_72 * 0x300 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
}
F_29 ( V_47 , V_53 ) ;
}
F_65 ( V_67 , false , false ) ;
}
static void
F_68 ( struct V_40 * V_43 )
{
struct V_66 * V_67 = V_66 ( V_43 ) ;
struct V_52 * V_53 = V_52 ( V_43 -> V_38 ) ;
T_1 * V_47 ;
V_47 = F_22 ( V_53 , 32 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_143 ) {
F_36 ( V_47 , 0x0874 + ( V_67 -> V_72 * 0x400 ) , 1 ) ;
F_37 ( V_47 , V_147 ) ;
F_36 ( V_47 , 0x0840 + ( V_67 -> V_72 * 0x400 ) , 2 ) ;
F_37 ( V_47 , 0xc0000000 ) ;
F_37 ( V_47 , V_67 -> V_148 . V_84 -> V_85 . V_86 >> 8 ) ;
} else
if ( F_54 ( V_53 ) < V_108 ) {
F_36 ( V_47 , 0x0874 + ( V_67 -> V_72 * 0x400 ) , 1 ) ;
F_37 ( V_47 , V_67 -> V_61 . V_142 ) ;
F_36 ( V_47 , 0x0840 + ( V_67 -> V_72 * 0x400 ) , 2 ) ;
F_37 ( V_47 , 0xc0000000 ) ;
F_37 ( V_47 , V_67 -> V_148 . V_84 -> V_85 . V_86 >> 8 ) ;
F_36 ( V_47 , 0x085c + ( V_67 -> V_72 * 0x400 ) , 1 ) ;
F_37 ( V_47 , V_145 ) ;
} else {
F_36 ( V_47 , 0x0474 + ( V_67 -> V_72 * 0x300 ) , 1 ) ;
F_37 ( V_47 , V_67 -> V_61 . V_142 ) ;
F_36 ( V_47 , 0x0440 + ( V_67 -> V_72 * 0x300 ) , 4 ) ;
F_37 ( V_47 , 0x83000000 ) ;
F_37 ( V_47 , V_67 -> V_148 . V_84 -> V_85 . V_86 >> 8 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_36 ( V_47 , 0x045c + ( V_67 -> V_72 * 0x300 ) , 1 ) ;
F_37 ( V_47 , V_145 ) ;
F_36 ( V_47 , 0x0430 + ( V_67 -> V_72 * 0x300 ) , 1 ) ;
F_37 ( V_47 , 0xffffff00 ) ;
}
F_29 ( V_47 , V_53 ) ;
}
F_65 ( V_67 , V_67 -> V_144 . V_149 , true ) ;
F_43 ( V_43 , V_43 -> V_100 -> V_61 , NULL , 1 ) ;
}
static bool
F_69 ( struct V_40 * V_43 , const struct V_110 * V_97 ,
struct V_110 * V_150 )
{
F_70 ( V_150 , V_151 ) ;
return true ;
}
static int
F_71 ( struct V_40 * V_43 , struct V_60 * V_152 )
{
struct V_64 * V_140 = V_64 ( V_43 -> V_100 -> V_61 ) ;
struct V_68 * V_4 = V_68 ( V_43 ) ;
int V_13 ;
V_13 = F_72 ( V_140 -> V_84 , V_153 ) ;
if ( V_13 == 0 ) {
if ( V_4 -> V_91 )
F_73 ( V_4 -> V_91 ) ;
F_55 ( V_140 -> V_84 , & V_4 -> V_91 ) ;
}
return V_13 ;
}
static int
F_74 ( struct V_40 * V_43 , struct V_110 * V_112 ,
struct V_110 * V_97 , int V_138 , int V_139 ,
struct V_60 * V_152 )
{
struct V_52 * V_53 = V_52 ( V_43 -> V_38 ) ;
struct V_66 * V_67 = V_66 ( V_43 ) ;
struct V_93 * V_94 ;
T_1 V_154 = ( V_97 -> V_120 & V_155 ) ? 2 : 1 ;
T_1 V_156 = ( V_97 -> V_120 & V_121 ) ? 2 : 1 ;
T_1 V_157 , V_158 , V_159 , V_160 , V_161 , V_162 ;
T_1 V_163 , V_164 , V_165 , V_166 , V_167 , V_168 ;
T_1 V_169 = 0 , V_170 = 1 ;
T_1 * V_47 ;
int V_13 ;
V_157 = V_97 -> V_171 ;
V_158 = V_97 -> V_172 - V_97 -> V_173 - 1 ;
V_159 = V_97 -> V_171 - V_97 -> V_172 ;
V_161 = V_158 + V_159 ;
V_160 = V_97 -> V_173 - V_97 -> V_118 ;
V_162 = V_97 -> V_171 - V_160 - 1 ;
V_163 = V_97 -> V_174 * V_156 / V_154 ;
V_164 = ( ( V_97 -> V_175 - V_97 -> V_176 ) * V_156 / V_154 ) - 1 ;
V_165 = ( V_97 -> V_174 - V_97 -> V_175 ) * V_156 / V_154 ;
V_167 = V_164 + V_165 ;
V_166 = ( V_97 -> V_176 - V_97 -> V_119 ) * V_156 / V_154 ;
V_168 = V_163 - V_166 - 1 ;
if ( V_97 -> V_120 & V_155 ) {
V_169 = V_163 + V_164 + V_165 ;
V_170 = V_169 + ( V_97 -> V_119 * V_156 / V_154 ) ;
V_163 = ( V_163 * 2 ) + 1 ;
}
V_13 = F_71 ( V_43 , V_152 ) ;
if ( V_13 )
return V_13 ;
V_47 = F_22 ( V_53 , 64 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_108 ) {
F_36 ( V_47 , 0x0804 + ( V_67 -> V_72 * 0x400 ) , 2 ) ;
F_37 ( V_47 , 0x00800000 | V_97 -> clock ) ;
F_37 ( V_47 , ( V_154 == 2 ) ? 2 : 0 ) ;
F_36 ( V_47 , 0x0810 + ( V_67 -> V_72 * 0x400 ) , 6 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_37 ( V_47 , ( V_163 << 16 ) | V_157 ) ;
F_37 ( V_47 , ( V_164 << 16 ) | V_158 ) ;
F_37 ( V_47 , ( V_167 << 16 ) | V_161 ) ;
F_37 ( V_47 , ( V_168 << 16 ) | V_162 ) ;
F_37 ( V_47 , ( V_169 << 16 ) | V_170 ) ;
F_36 ( V_47 , 0x082c + ( V_67 -> V_72 * 0x400 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_36 ( V_47 , 0x0900 + ( V_67 -> V_72 * 0x400 ) , 2 ) ;
F_37 ( V_47 , 0x00000311 ) ;
F_37 ( V_47 , 0x00000100 ) ;
} else {
F_36 ( V_47 , 0x0410 + ( V_67 -> V_72 * 0x300 ) , 6 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_37 ( V_47 , ( V_163 << 16 ) | V_157 ) ;
F_37 ( V_47 , ( V_164 << 16 ) | V_158 ) ;
F_37 ( V_47 , ( V_167 << 16 ) | V_161 ) ;
F_37 ( V_47 , ( V_168 << 16 ) | V_162 ) ;
F_37 ( V_47 , ( V_169 << 16 ) | V_170 ) ;
F_36 ( V_47 , 0x042c + ( V_67 -> V_72 * 0x300 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_36 ( V_47 , 0x0450 + ( V_67 -> V_72 * 0x300 ) , 3 ) ;
F_37 ( V_47 , V_97 -> clock * 1000 ) ;
F_37 ( V_47 , 0x00200000 ) ;
F_37 ( V_47 , V_97 -> clock * 1000 ) ;
F_36 ( V_47 , 0x04d0 + ( V_67 -> V_72 * 0x300 ) , 2 ) ;
F_37 ( V_47 , 0x00000311 ) ;
F_37 ( V_47 , 0x00000100 ) ;
}
F_29 ( V_47 , V_53 ) ;
}
V_94 = F_57 ( V_67 ) ;
F_56 ( V_67 , false ) ;
F_58 ( V_67 , false ) ;
F_61 ( V_67 , false ) ;
F_62 ( V_67 , V_43 -> V_100 -> V_61 , V_138 , V_139 , false ) ;
return 0 ;
}
static int
F_75 ( struct V_40 * V_43 , int V_138 , int V_139 ,
struct V_60 * V_152 )
{
struct V_177 * V_178 = V_177 ( V_43 -> V_38 ) ;
struct V_66 * V_67 = V_66 ( V_43 ) ;
int V_13 ;
if ( ! V_43 -> V_100 -> V_61 ) {
F_76 ( V_178 , L_2 ) ;
return 0 ;
}
V_13 = F_71 ( V_43 , V_152 ) ;
if ( V_13 )
return V_13 ;
F_41 ( V_43 ) ;
F_62 ( V_67 , V_43 -> V_100 -> V_61 , V_138 , V_139 , true ) ;
F_43 ( V_43 , V_43 -> V_100 -> V_61 , NULL , 1 ) ;
return 0 ;
}
static int
F_77 ( struct V_40 * V_43 ,
struct V_60 * V_61 , int V_138 , int V_139 ,
enum V_179 V_180 )
{
struct V_66 * V_67 = V_66 ( V_43 ) ;
F_41 ( V_43 ) ;
F_62 ( V_67 , V_61 , V_138 , V_139 , true ) ;
return 0 ;
}
static void
F_78 ( struct V_40 * V_43 )
{
struct V_36 * V_51 = V_36 ( V_43 -> V_38 ) ;
struct V_66 * V_67 = V_66 ( V_43 ) ;
void T_4 * V_148 = F_79 ( V_67 -> V_148 . V_84 ) ;
int V_181 ;
for ( V_181 = 0 ; V_181 < 256 ; V_181 ++ ) {
T_5 V_182 = V_67 -> V_148 . V_182 [ V_181 ] >> 2 ;
T_5 V_183 = V_67 -> V_148 . V_183 [ V_181 ] >> 2 ;
T_5 V_184 = V_67 -> V_148 . V_184 [ V_181 ] >> 2 ;
if ( F_45 ( V_51 -> V_2 ) < V_185 ) {
F_80 ( V_182 + 0x0000 , V_148 + ( V_181 * 0x08 ) + 0 ) ;
F_80 ( V_183 + 0x0000 , V_148 + ( V_181 * 0x08 ) + 2 ) ;
F_80 ( V_184 + 0x0000 , V_148 + ( V_181 * 0x08 ) + 4 ) ;
} else {
F_80 ( V_182 + 0x6000 , V_148 + ( V_181 * 0x20 ) + 0 ) ;
F_80 ( V_183 + 0x6000 , V_148 + ( V_181 * 0x20 ) + 2 ) ;
F_80 ( V_184 + 0x6000 , V_148 + ( V_181 * 0x20 ) + 4 ) ;
}
}
}
static void
F_81 ( struct V_40 * V_43 )
{
struct V_68 * V_4 = V_68 ( V_43 ) ;
if ( V_4 -> V_91 )
F_73 ( V_4 -> V_91 ) ;
F_55 ( NULL , & V_4 -> V_91 ) ;
}
static int
F_82 ( struct V_40 * V_43 , struct V_186 * V_187 ,
T_6 V_12 , T_6 V_88 , T_6 V_87 )
{
struct V_66 * V_67 = V_66 ( V_43 ) ;
struct V_37 * V_38 = V_43 -> V_38 ;
struct V_188 * V_189 ;
struct V_56 * V_84 ;
bool V_149 = ( V_12 != 0 ) ;
int V_181 , V_13 = 0 ;
if ( V_149 ) {
if ( V_88 != 64 || V_87 != 64 )
return - V_190 ;
V_189 = F_83 ( V_38 , V_187 , V_12 ) ;
if ( F_44 ( ! V_189 ) )
return - V_191 ;
V_84 = F_84 ( V_189 ) ;
V_13 = F_85 ( V_84 ) ;
if ( V_13 == 0 ) {
for ( V_181 = 0 ; V_181 < 64 * 64 ; V_181 ++ ) {
T_1 V_192 = F_31 ( V_84 , V_181 ) ;
F_35 ( V_67 -> V_144 . V_84 , V_181 , V_192 ) ;
}
F_86 ( V_84 ) ;
}
F_87 ( V_189 ) ;
}
if ( V_149 != V_67 -> V_144 . V_149 ) {
F_65 ( V_67 , V_149 , true ) ;
V_67 -> V_144 . V_149 = V_149 ;
}
return V_13 ;
}
static int
F_88 ( struct V_40 * V_43 , int V_138 , int V_139 )
{
struct V_193 * V_194 = V_193 ( V_43 ) ;
struct V_7 * V_8 = V_7 ( V_194 ) ;
F_25 ( V_8 -> V_15 , 0x0084 , ( V_139 << 16 ) | ( V_138 & 0xffff ) ) ;
F_25 ( V_8 -> V_15 , 0x0080 , 0x00000000 ) ;
return 0 ;
}
static void
F_89 ( struct V_40 * V_43 , T_5 * V_182 , T_5 * V_183 , T_5 * V_184 ,
T_6 V_195 , T_6 V_6 )
{
struct V_66 * V_67 = V_66 ( V_43 ) ;
T_1 V_196 = F_90 ( T_1 , V_195 + V_6 , 256 ) ;
T_1 V_181 ;
for ( V_181 = V_195 ; V_181 < V_196 ; V_181 ++ ) {
V_67 -> V_148 . V_182 [ V_181 ] = V_182 [ V_181 ] ;
V_67 -> V_148 . V_183 [ V_181 ] = V_183 [ V_181 ] ;
V_67 -> V_148 . V_184 [ V_181 ] = V_184 [ V_181 ] ;
}
F_78 ( V_43 ) ;
}
static void
F_91 ( struct V_40 * V_43 )
{
struct V_66 * V_67 = V_66 ( V_43 ) ;
struct V_36 * V_51 = V_36 ( V_43 -> V_38 ) ;
struct V_68 * V_4 = V_68 ( V_43 ) ;
F_10 ( V_51 -> V_2 , & V_4 -> V_197 . V_18 ) ;
F_8 ( V_51 -> V_2 , & V_4 -> V_198 . V_18 ) ;
F_10 ( V_51 -> V_2 , & V_4 -> V_54 . V_18 ) ;
F_8 ( V_51 -> V_2 , & V_4 -> V_194 . V_18 ) ;
if ( V_4 -> V_91 )
F_73 ( V_4 -> V_91 ) ;
F_55 ( NULL , & V_4 -> V_91 ) ;
F_86 ( V_67 -> V_144 . V_84 ) ;
if ( V_67 -> V_144 . V_84 )
F_73 ( V_67 -> V_144 . V_84 ) ;
F_55 ( NULL , & V_67 -> V_144 . V_84 ) ;
F_86 ( V_67 -> V_148 . V_84 ) ;
if ( V_67 -> V_148 . V_84 )
F_73 ( V_67 -> V_148 . V_84 ) ;
F_55 ( NULL , & V_67 -> V_148 . V_84 ) ;
F_92 ( V_43 ) ;
F_93 ( V_43 ) ;
}
static void
F_94 ( struct V_66 * V_67 , int V_138 , int V_139 )
{
}
static void
F_95 ( struct V_66 * V_67 , T_6 V_86 )
{
}
static int
F_96 ( struct V_37 * V_38 , struct V_1 * V_2 , int V_72 )
{
struct V_36 * V_51 = V_36 ( V_38 ) ;
struct V_68 * V_4 ;
struct V_40 * V_43 ;
int V_13 , V_181 ;
V_4 = F_97 ( sizeof( * V_4 ) , V_199 ) ;
if ( ! V_4 )
return - V_32 ;
V_4 -> V_18 . V_72 = V_72 ;
V_4 -> V_18 . V_200 = F_56 ;
V_4 -> V_18 . V_201 = F_58 ;
V_4 -> V_18 . V_202 = F_61 ;
V_4 -> V_18 . V_136 = 50 ;
V_4 -> V_18 . V_137 = 0 ;
V_4 -> V_18 . V_144 . V_203 = F_95 ;
V_4 -> V_18 . V_144 . V_204 = F_94 ;
for ( V_181 = 0 ; V_181 < 256 ; V_181 ++ ) {
V_4 -> V_18 . V_148 . V_182 [ V_181 ] = V_181 << 8 ;
V_4 -> V_18 . V_148 . V_183 [ V_181 ] = V_181 << 8 ;
V_4 -> V_18 . V_148 . V_184 [ V_181 ] = V_181 << 8 ;
}
V_43 = & V_4 -> V_18 . V_18 ;
F_98 ( V_38 , V_43 , & V_205 ) ;
F_99 ( V_43 , & V_206 ) ;
F_100 ( V_43 , 256 ) ;
V_13 = F_101 ( V_38 , 8192 , 0x100 , V_153 ,
0 , 0x0000 , NULL , & V_4 -> V_18 . V_148 . V_84 ) ;
if ( ! V_13 ) {
V_13 = F_72 ( V_4 -> V_18 . V_148 . V_84 , V_153 ) ;
if ( ! V_13 ) {
V_13 = F_85 ( V_4 -> V_18 . V_148 . V_84 ) ;
if ( V_13 )
F_73 ( V_4 -> V_18 . V_148 . V_84 ) ;
}
if ( V_13 )
F_55 ( NULL , & V_4 -> V_18 . V_148 . V_84 ) ;
}
if ( V_13 )
goto V_207;
F_78 ( V_43 ) ;
V_13 = F_9 (disp->core, NV50_DISP_CURS_CLASS, index,
&(struct nv50_display_curs_class) {
.head = index,
}, sizeof(struct nv50_display_curs_class),
&head->curs.base) ;
if ( V_13 )
goto V_207;
V_13 = F_101 ( V_38 , 64 * 64 * 4 , 0x100 , V_153 ,
0 , 0x0000 , NULL , & V_4 -> V_18 . V_144 . V_84 ) ;
if ( ! V_13 ) {
V_13 = F_72 ( V_4 -> V_18 . V_144 . V_84 , V_153 ) ;
if ( ! V_13 ) {
V_13 = F_85 ( V_4 -> V_18 . V_144 . V_84 ) ;
if ( V_13 )
F_73 ( V_4 -> V_18 . V_148 . V_84 ) ;
}
if ( V_13 )
F_55 ( NULL , & V_4 -> V_18 . V_144 . V_84 ) ;
}
if ( V_13 )
goto V_207;
V_13 = F_16 (disp->core, NV50_DISP_SYNC_CLASS, index,
&(struct nv50_display_sync_class) {
.pushbuf = EVO_PUSH_HANDLE(SYNC, index),
.head = index,
}, sizeof(struct nv50_display_sync_class),
disp->sync->bo.offset, &head->sync.base) ;
if ( V_13 )
goto V_207;
V_4 -> V_54 . V_59 = F_102 ( V_72 ) ;
V_4 -> V_54 . V_5 = 0x00000000 ;
V_13 = F_9 (disp->core, NV50_DISP_OIMM_CLASS, index,
&(struct nv50_display_oimm_class) {
.head = index,
}, sizeof(struct nv50_display_oimm_class),
&head->oimm.base) ;
if ( V_13 )
goto V_207;
V_13 = F_16 (disp->core, NV50_DISP_OVLY_CLASS, index,
&(struct nv50_display_ovly_class) {
.pushbuf = EVO_PUSH_HANDLE(OVLY, index),
.head = index,
}, sizeof(struct nv50_display_ovly_class),
disp->sync->bo.offset, &head->ovly.base) ;
if ( V_13 )
goto V_207;
V_207:
if ( V_13 )
F_91 ( V_43 ) ;
return V_13 ;
}
static void
F_103 ( struct V_41 * V_42 , int V_97 )
{
struct F_21 * V_208 = F_21 ( V_42 ) ;
struct V_36 * V_51 = V_36 ( V_42 -> V_38 ) ;
int V_209 = V_208 -> V_209 ;
T_1 V_210 ;
V_210 = 0x00000000 ;
if ( V_97 == V_211 || V_97 == V_212 )
V_210 |= 0x00000001 ;
if ( V_97 == V_213 || V_97 == V_212 )
V_210 |= 0x00000004 ;
F_104 ( V_51 -> V_2 , V_214 + V_209 , V_210 ) ;
}
static bool
F_105 ( struct V_41 * V_42 ,
const struct V_110 * V_97 ,
struct V_110 * V_150 )
{
struct F_21 * V_208 = F_21 ( V_42 ) ;
struct V_93 * V_94 ;
V_94 = F_106 ( V_208 ) ;
if ( V_94 && V_94 -> V_116 ) {
if ( V_94 -> V_117 != V_113 ) {
int V_215 = V_150 -> V_18 . V_215 ;
* V_150 = * V_94 -> V_116 ;
V_150 -> V_18 . V_215 = V_215 ;
}
}
return true ;
}
static void
F_107 ( struct V_41 * V_42 )
{
}
static void
F_108 ( struct V_41 * V_42 , struct V_110 * V_97 ,
struct V_110 * V_150 )
{
struct V_52 * V_53 = V_52 ( V_42 -> V_38 ) ;
struct F_21 * V_208 = F_21 ( V_42 ) ;
struct V_66 * V_67 = V_66 ( V_42 -> V_43 ) ;
T_1 * V_47 ;
F_103 ( V_42 , V_216 ) ;
V_47 = F_22 ( V_53 , 8 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_108 ) {
T_1 V_217 = 0x00000000 ;
if ( V_97 -> V_120 & V_218 )
V_217 |= 0x00000001 ;
if ( V_97 -> V_120 & V_219 )
V_217 |= 0x00000002 ;
F_36 ( V_47 , 0x0400 + ( V_208 -> V_209 * 0x080 ) , 2 ) ;
F_37 ( V_47 , 1 << V_67 -> V_72 ) ;
F_37 ( V_47 , V_217 ) ;
} else {
T_1 V_220 = 0x31ec6000 | ( V_67 -> V_72 << 25 ) ;
T_1 V_217 = 0x00000001 ;
if ( V_97 -> V_120 & V_218 )
V_217 |= 0x00000008 ;
if ( V_97 -> V_120 & V_219 )
V_217 |= 0x00000010 ;
if ( V_97 -> V_120 & V_155 )
V_220 |= 0x00000001 ;
F_36 ( V_47 , 0x0404 + ( V_67 -> V_72 * 0x300 ) , 2 ) ;
F_37 ( V_47 , V_217 ) ;
F_37 ( V_47 , V_220 ) ;
F_36 ( V_47 , 0x0180 + ( V_208 -> V_209 * 0x020 ) , 1 ) ;
F_37 ( V_47 , 1 << V_67 -> V_72 ) ;
}
F_29 ( V_47 , V_53 ) ;
}
V_208 -> V_43 = V_42 -> V_43 ;
}
static void
F_109 ( struct V_41 * V_42 )
{
struct F_21 * V_208 = F_21 ( V_42 ) ;
struct V_52 * V_53 = V_52 ( V_42 -> V_38 ) ;
const int V_209 = V_208 -> V_209 ;
T_1 * V_47 ;
if ( V_208 -> V_43 ) {
F_67 ( V_208 -> V_43 ) ;
V_47 = F_22 ( V_53 , 4 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_108 ) {
F_36 ( V_47 , 0x0400 + ( V_209 * 0x080 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
} else {
F_36 ( V_47 , 0x0180 + ( V_209 * 0x020 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
}
F_29 ( V_47 , V_53 ) ;
}
}
V_208 -> V_43 = NULL ;
}
static enum V_221
F_110 ( struct V_41 * V_42 , struct V_95 * V_96 )
{
struct V_36 * V_51 = V_36 ( V_42 -> V_38 ) ;
int V_13 , V_209 = F_21 ( V_42 ) -> V_209 ;
T_1 V_222 = V_177 ( V_42 -> V_38 ) -> V_223 . V_224 ;
if ( V_222 == 0 )
V_222 = 340 ;
V_13 = F_111 ( V_51 -> V_2 , V_225 + V_209 , & V_222 , sizeof( V_222 ) ) ;
if ( V_13 || ! V_222 )
return V_226 ;
return V_227 ;
}
static void
F_112 ( struct V_41 * V_42 )
{
F_113 ( V_42 ) ;
F_93 ( V_42 ) ;
}
static int
F_114 ( struct V_95 * V_96 , struct V_228 * V_229 )
{
struct V_177 * V_178 = V_177 ( V_96 -> V_38 ) ;
struct V_230 * V_231 = V_230 ( V_178 -> V_50 ) ;
struct F_21 * V_208 ;
struct V_41 * V_42 ;
int type = V_232 ;
V_208 = F_97 ( sizeof( * V_208 ) , V_199 ) ;
if ( ! V_208 )
return - V_32 ;
V_208 -> V_233 = V_229 ;
V_208 -> V_209 = F_115 ( V_229 -> V_209 ) - 1 ;
V_208 -> V_231 = V_231 -> V_234 ( V_231 , V_229 -> V_235 ) ;
V_42 = F_116 ( V_208 ) ;
V_42 -> V_236 = V_229 -> V_237 ;
V_42 -> V_238 = 0 ;
F_117 ( V_96 -> V_38 , V_42 , & V_239 , type ) ;
F_118 ( V_42 , & V_240 ) ;
F_119 ( V_96 , V_42 ) ;
return 0 ;
}
static void
F_120 ( struct V_41 * V_42 , struct V_110 * V_97 )
{
struct F_21 * V_208 = F_21 ( V_42 ) ;
struct V_93 * V_94 ;
struct V_36 * V_51 = V_36 ( V_42 -> V_38 ) ;
V_94 = F_106 ( V_208 ) ;
if ( ! F_121 ( V_94 -> V_125 ) )
return;
F_122 ( & V_94 -> V_18 , V_94 -> V_125 ) ;
F_111 ( V_51 -> V_2 , V_241 + V_208 -> V_209 ,
V_94 -> V_18 . V_242 ,
V_94 -> V_18 . V_242 [ 2 ] * 4 ) ;
}
static void
F_123 ( struct V_41 * V_42 )
{
struct F_21 * V_208 = F_21 ( V_42 ) ;
struct V_36 * V_51 = V_36 ( V_42 -> V_38 ) ;
F_111 ( V_51 -> V_2 , V_241 + V_208 -> V_209 , NULL , 0 ) ;
}
static void
F_124 ( struct V_41 * V_42 , struct V_110 * V_97 )
{
struct F_21 * V_208 = F_21 ( V_42 ) ;
struct V_66 * V_67 = V_66 ( V_42 -> V_43 ) ;
struct V_93 * V_94 ;
struct V_36 * V_51 = V_36 ( V_42 -> V_38 ) ;
const T_1 V_243 = ( V_67 -> V_72 << 3 ) | V_208 -> V_209 ;
T_1 V_244 = 56 ;
T_1 V_245 ;
V_94 = F_106 ( V_208 ) ;
if ( ! F_59 ( V_94 -> V_125 ) )
return;
V_245 = V_97 -> V_171 - V_97 -> V_118 ;
V_245 -= V_244 ;
V_245 -= 18 ;
V_245 /= 32 ;
F_104 ( V_51 -> V_2 , V_246 + V_243 ,
V_247 |
( V_245 << 16 ) | V_244 ) ;
F_120 ( V_42 , V_97 ) ;
}
static void
F_125 ( struct V_41 * V_42 )
{
struct F_21 * V_208 = F_21 ( V_42 ) ;
struct V_66 * V_67 = V_66 ( V_208 -> V_43 ) ;
struct V_36 * V_51 = V_36 ( V_42 -> V_38 ) ;
const T_1 V_243 = ( V_67 -> V_72 << 3 ) | V_208 -> V_209 ;
F_123 ( V_42 ) ;
F_104 ( V_51 -> V_2 , V_246 + V_243 , 0x00000000 ) ;
}
static void
F_126 ( struct V_41 * V_42 , int V_97 )
{
struct F_21 * V_208 = F_21 ( V_42 ) ;
struct V_37 * V_38 = V_42 -> V_38 ;
struct V_36 * V_51 = V_36 ( V_38 ) ;
struct V_41 * V_248 ;
int V_209 = V_208 -> V_209 ;
V_208 -> V_249 = V_97 ;
F_127 (partner, &dev->mode_config.encoder_list, head) {
struct F_21 * V_250 = F_21 ( V_248 ) ;
if ( V_248 -> V_251 != V_252 )
continue;
if ( V_250 != V_208 &&
V_250 -> V_233 -> V_209 == V_208 -> V_233 -> V_209 ) {
if ( V_250 -> V_249 == V_216 )
return;
break;
}
}
F_104 ( V_51 -> V_2 , V_253 + V_209 , ( V_97 == V_216 ) ) ;
}
static bool
F_128 ( struct V_41 * V_42 ,
const struct V_110 * V_97 ,
struct V_110 * V_150 )
{
struct F_21 * V_208 = F_21 ( V_42 ) ;
struct V_93 * V_94 ;
V_94 = F_106 ( V_208 ) ;
if ( V_94 && V_94 -> V_116 ) {
if ( V_94 -> V_117 != V_113 ) {
int V_215 = V_150 -> V_18 . V_215 ;
* V_150 = * V_94 -> V_116 ;
V_150 -> V_18 . V_215 = V_215 ;
}
}
return true ;
}
static void
F_129 ( struct V_41 * V_42 )
{
struct F_21 * V_208 = F_21 ( V_42 ) ;
struct V_52 * V_53 = V_52 ( V_42 -> V_38 ) ;
const int V_209 = V_208 -> V_209 ;
T_1 * V_47 ;
if ( V_208 -> V_43 ) {
F_67 ( V_208 -> V_43 ) ;
V_47 = F_22 ( V_53 , 4 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_108 ) {
F_36 ( V_47 , 0x0600 + ( V_209 * 0x40 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
} else {
F_36 ( V_47 , 0x0200 + ( V_209 * 0x20 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
}
F_29 ( V_47 , V_53 ) ;
}
F_125 ( V_42 ) ;
}
V_208 -> V_249 = V_212 ;
V_208 -> V_43 = NULL ;
}
static void
F_130 ( struct V_41 * V_42 )
{
}
static void
F_131 ( struct V_41 * V_42 , struct V_110 * V_112 ,
struct V_110 * V_97 )
{
struct V_36 * V_51 = V_36 ( V_42 -> V_38 ) ;
struct V_52 * V_53 = V_52 ( V_42 -> V_38 ) ;
struct V_37 * V_38 = V_42 -> V_38 ;
struct V_177 * V_178 = V_177 ( V_38 ) ;
struct F_21 * V_208 = F_21 ( V_42 ) ;
struct V_66 * V_67 = V_66 ( V_42 -> V_43 ) ;
struct V_93 * V_94 ;
struct V_254 * V_255 = & V_178 -> V_223 ;
T_1 * V_47 , V_256 = 0 ;
T_2 V_257 = 1 << V_67 -> V_72 ;
T_2 V_258 = 0xf ;
T_2 V_101 = 0x0 ;
V_94 = F_106 ( V_208 ) ;
switch ( V_208 -> V_233 -> type ) {
case V_259 :
if ( V_208 -> V_233 -> V_260 . V_261 & 1 ) {
if ( V_97 -> clock < 165000 )
V_258 = 0x1 ;
else
V_258 = 0x5 ;
} else {
V_258 = 0x2 ;
}
F_124 ( V_42 , V_97 ) ;
break;
case V_262 :
V_258 = 0x0 ;
if ( V_255 -> V_263 ) {
if ( V_255 -> V_264 . V_265 )
V_256 |= 0x0100 ;
if ( V_255 -> V_264 . V_266 )
V_256 |= 0x0200 ;
} else {
if ( V_94 -> type == V_267 ) {
if ( ( ( T_2 * ) V_94 -> V_125 ) [ 121 ] == 2 )
V_256 |= 0x0100 ;
} else
if ( V_97 -> clock >= V_255 -> V_264 . V_268 ) {
V_256 |= 0x0100 ;
}
if ( V_256 & 0x0100 ) {
if ( V_255 -> V_264 . V_269 & 2 )
V_256 |= 0x0200 ;
} else {
if ( V_255 -> V_264 . V_269 & 1 )
V_256 |= 0x0200 ;
}
if ( V_94 -> V_18 . V_102 . V_103 == 8 )
V_256 |= 0x0200 ;
}
F_104 ( V_51 -> V_2 , V_270 + V_208 -> V_209 , V_256 ) ;
break;
case V_271 :
if ( V_94 -> V_18 . V_102 . V_103 == 6 ) {
V_208 -> V_272 . V_273 = V_97 -> clock * 18 / 8 ;
V_101 = 0x2 ;
} else
if ( V_94 -> V_18 . V_102 . V_103 == 8 ) {
V_208 -> V_272 . V_273 = V_97 -> clock * 24 / 8 ;
V_101 = 0x5 ;
} else {
V_208 -> V_272 . V_273 = V_97 -> clock * 30 / 8 ;
V_101 = 0x6 ;
}
if ( V_208 -> V_233 -> V_260 . V_261 & 1 )
V_258 = 0x8 ;
else
V_258 = 0x9 ;
break;
default:
F_132 ( 1 ) ;
break;
}
F_126 ( V_42 , V_216 ) ;
V_47 = F_22 ( V_52 ( V_38 ) , 8 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_185 ) {
T_1 V_274 = ( V_101 << 16 ) | ( V_258 << 8 ) | V_257 ;
if ( V_97 -> V_120 & V_218 )
V_274 |= 0x00001000 ;
if ( V_97 -> V_120 & V_219 )
V_274 |= 0x00002000 ;
F_36 ( V_47 , 0x0600 + ( V_208 -> V_209 * 0x040 ) , 1 ) ;
F_37 ( V_47 , V_274 ) ;
} else {
T_1 V_220 = 0x31ec6000 | ( V_67 -> V_72 << 25 ) ;
T_1 V_217 = 0x00000001 ;
if ( V_97 -> V_120 & V_218 )
V_217 |= 0x00000008 ;
if ( V_97 -> V_120 & V_219 )
V_217 |= 0x00000010 ;
if ( V_97 -> V_120 & V_155 )
V_220 |= 0x00000001 ;
F_36 ( V_47 , 0x0404 + ( V_67 -> V_72 * 0x300 ) , 2 ) ;
F_37 ( V_47 , V_217 | ( V_101 << 6 ) ) ;
F_37 ( V_47 , V_220 ) ;
F_36 ( V_47 , 0x0200 + ( V_208 -> V_209 * 0x020 ) , 1 ) ;
F_37 ( V_47 , V_257 | ( V_258 << 8 ) ) ;
}
F_29 ( V_47 , V_53 ) ;
}
V_208 -> V_43 = V_42 -> V_43 ;
}
static void
F_133 ( struct V_41 * V_42 )
{
F_113 ( V_42 ) ;
F_93 ( V_42 ) ;
}
static int
F_134 ( struct V_95 * V_96 , struct V_228 * V_229 )
{
struct V_177 * V_178 = V_177 ( V_96 -> V_38 ) ;
struct V_230 * V_231 = V_230 ( V_178 -> V_50 ) ;
struct F_21 * V_208 ;
struct V_41 * V_42 ;
int type ;
switch ( V_229 -> type ) {
case V_262 : type = V_275 ; break;
case V_259 :
case V_271 :
default:
type = V_252 ;
break;
}
V_208 = F_97 ( sizeof( * V_208 ) , V_199 ) ;
if ( ! V_208 )
return - V_32 ;
V_208 -> V_233 = V_229 ;
V_208 -> V_209 = F_115 ( V_229 -> V_209 ) - 1 ;
V_208 -> V_231 = V_231 -> V_234 ( V_231 , V_229 -> V_235 ) ;
V_208 -> V_249 = V_212 ;
V_42 = F_116 ( V_208 ) ;
V_42 -> V_236 = V_229 -> V_237 ;
V_42 -> V_238 = 0 ;
F_117 ( V_96 -> V_38 , V_42 , & V_276 , type ) ;
F_118 ( V_42 , & V_277 ) ;
F_119 ( V_96 , V_42 ) ;
return 0 ;
}
static void
F_135 ( struct V_41 * V_42 , int V_97 )
{
struct F_21 * V_208 = F_21 ( V_42 ) ;
struct V_36 * V_51 = V_36 ( V_42 -> V_38 ) ;
T_1 V_278 = ( V_208 -> V_233 -> type << 12 ) | V_208 -> V_209 ;
T_1 V_274 = ( V_97 == V_216 ) ;
F_104 ( V_51 -> V_2 , V_279 + V_278 , V_274 ) ;
}
static bool
F_136 ( struct V_41 * V_42 ,
const struct V_110 * V_97 ,
struct V_110 * V_150 )
{
struct F_21 * V_208 = F_21 ( V_42 ) ;
struct V_93 * V_94 ;
V_94 = F_106 ( V_208 ) ;
if ( V_94 && V_94 -> V_116 ) {
if ( V_94 -> V_117 != V_113 ) {
int V_215 = V_150 -> V_18 . V_215 ;
* V_150 = * V_94 -> V_116 ;
V_150 -> V_18 . V_215 = V_215 ;
}
}
V_150 -> clock *= 2 ;
return true ;
}
static void
F_137 ( struct V_41 * V_42 )
{
}
static void
F_138 ( struct V_41 * V_42 , struct V_110 * V_97 ,
struct V_110 * V_150 )
{
struct V_52 * V_53 = V_52 ( V_42 -> V_38 ) ;
struct F_21 * V_208 = F_21 ( V_42 ) ;
struct V_66 * V_67 = V_66 ( V_42 -> V_43 ) ;
struct V_93 * V_94 ;
T_2 V_257 = 1 << V_67 -> V_72 ;
T_2 V_258 , V_101 ;
T_1 * V_47 ;
V_94 = F_106 ( V_208 ) ;
switch ( V_94 -> V_18 . V_102 . V_103 ) {
case 10 : V_101 = 0x6 ; break;
case 8 : V_101 = 0x5 ; break;
case 6 : V_101 = 0x2 ; break;
default: V_101 = 0x0 ; break;
}
switch ( V_208 -> V_233 -> type ) {
case V_259 :
case V_271 :
V_258 = 0x0 ;
break;
default:
F_132 ( 1 ) ;
break;
}
F_135 ( V_42 , V_216 ) ;
V_47 = F_22 ( V_53 , 8 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_108 ) {
T_1 V_274 = ( V_101 << 16 ) | ( V_258 << 8 ) | V_257 ;
if ( V_97 -> V_120 & V_218 )
V_274 |= 0x00001000 ;
if ( V_97 -> V_120 & V_219 )
V_274 |= 0x00002000 ;
F_36 ( V_47 , 0x0700 + ( V_208 -> V_209 * 0x040 ) , 1 ) ;
F_37 ( V_47 , V_274 ) ;
}
F_29 ( V_47 , V_53 ) ;
}
V_208 -> V_43 = V_42 -> V_43 ;
}
static void
F_139 ( struct V_41 * V_42 )
{
struct F_21 * V_208 = F_21 ( V_42 ) ;
struct V_52 * V_53 = V_52 ( V_42 -> V_38 ) ;
const int V_209 = V_208 -> V_209 ;
T_1 * V_47 ;
if ( V_208 -> V_43 ) {
F_67 ( V_208 -> V_43 ) ;
V_47 = F_22 ( V_53 , 4 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_108 ) {
F_36 ( V_47 , 0x0700 + ( V_209 * 0x040 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
}
F_29 ( V_47 , V_53 ) ;
}
}
V_208 -> V_43 = NULL ;
}
static void
F_140 ( struct V_41 * V_42 )
{
F_113 ( V_42 ) ;
F_93 ( V_42 ) ;
}
static int
F_141 ( struct V_95 * V_96 , struct V_228 * V_229 )
{
struct V_177 * V_178 = V_177 ( V_96 -> V_38 ) ;
struct V_230 * V_231 = V_230 ( V_178 -> V_50 ) ;
struct V_280 * V_281 = NULL ;
struct F_21 * V_208 ;
struct V_41 * V_42 ;
int type ;
switch ( V_229 -> type ) {
case V_259 :
V_281 = V_231 -> V_282 ( V_231 , F_142 ( V_229 -> V_283 ) ) ;
type = V_252 ;
break;
case V_271 :
V_281 = V_231 -> V_282 ( V_231 , F_143 ( V_229 -> V_283 ) ) ;
type = V_252 ;
break;
default:
return - V_284 ;
}
V_208 = F_97 ( sizeof( * V_208 ) , V_199 ) ;
if ( ! V_208 )
return - V_32 ;
V_208 -> V_233 = V_229 ;
V_208 -> V_209 = F_115 ( V_229 -> V_209 ) - 1 ;
V_208 -> V_231 = V_281 ;
V_42 = F_116 ( V_208 ) ;
V_42 -> V_236 = V_229 -> V_237 ;
V_42 -> V_238 = 0 ;
F_117 ( V_96 -> V_38 , V_42 , & V_285 , type ) ;
F_118 ( V_42 , & V_286 ) ;
F_119 ( V_96 , V_42 ) ;
return 0 ;
}
void
F_144 ( struct V_37 * V_38 )
{
}
int
F_145 ( struct V_37 * V_38 )
{
struct V_36 * V_51 = V_36 ( V_38 ) ;
struct V_40 * V_43 ;
T_1 * V_47 ;
V_47 = F_22 ( V_52 ( V_38 ) , 32 ) ;
if ( ! V_47 )
return - V_55 ;
F_127 (crtc, &dev->mode_config.crtc_list, head) {
struct F_42 * V_54 = F_42 ( V_43 ) ;
F_35 ( V_51 -> V_54 , V_54 -> V_59 / 4 , V_54 -> V_5 ) ;
}
F_36 ( V_47 , 0x0088 , 1 ) ;
F_37 ( V_47 , V_81 ) ;
F_29 ( V_47 , V_52 ( V_38 ) ) ;
return 0 ;
}
void
F_146 ( struct V_37 * V_38 )
{
struct V_36 * V_51 = V_36 ( V_38 ) ;
F_10 ( V_51 -> V_2 , & V_51 -> V_53 . V_18 ) ;
F_86 ( V_51 -> V_54 ) ;
if ( V_51 -> V_54 )
F_73 ( V_51 -> V_54 ) ;
F_55 ( NULL , & V_51 -> V_54 ) ;
F_19 ( V_38 ) -> V_39 = NULL ;
F_93 ( V_51 ) ;
}
int
F_147 ( struct V_37 * V_38 )
{
struct V_49 * V_50 = F_34 ( V_38 ) ;
struct V_177 * V_178 = V_177 ( V_38 ) ;
struct V_287 * V_233 = & V_178 -> V_223 . V_233 ;
struct V_95 * V_96 , * V_288 ;
struct V_36 * V_51 ;
struct V_228 * V_229 ;
int V_289 , V_13 , V_181 ;
V_51 = F_97 ( sizeof( * V_51 ) , V_199 ) ;
if ( ! V_51 )
return - V_32 ;
F_19 ( V_38 ) -> V_39 = V_51 ;
F_19 ( V_38 ) -> V_290 = F_146 ;
F_19 ( V_38 ) -> V_291 = F_145 ;
F_19 ( V_38 ) -> V_292 = F_144 ;
V_51 -> V_2 = F_19 ( V_38 ) -> V_2 ;
V_13 = F_101 ( V_38 , 4096 , 0x1000 , V_153 ,
0 , 0x0000 , NULL , & V_51 -> V_54 ) ;
if ( ! V_13 ) {
V_13 = F_72 ( V_51 -> V_54 , V_153 ) ;
if ( ! V_13 ) {
V_13 = F_85 ( V_51 -> V_54 ) ;
if ( V_13 )
F_73 ( V_51 -> V_54 ) ;
}
if ( V_13 )
F_55 ( NULL , & V_51 -> V_54 ) ;
}
if ( V_13 )
goto V_207;
V_13 = F_16 (disp->core, NV50_DISP_MAST_CLASS, 0 ,
&(struct nv50_display_mast_class) {
.pushbuf = EVO_PUSH_HANDLE(MAST, 0),
}, sizeof(struct nv50_display_mast_class),
disp->sync->bo.offset, &disp->mast.base) ;
if ( V_13 )
goto V_207;
if ( F_45 ( V_51 -> V_2 ) >= V_185 )
V_289 = F_148 ( V_50 , 0x022448 ) ;
else
V_289 = 2 ;
for ( V_181 = 0 ; V_181 < V_289 ; V_181 ++ ) {
V_13 = F_96 ( V_38 , V_51 -> V_2 , V_181 ) ;
if ( V_13 )
goto V_207;
}
for ( V_181 = 0 , V_229 = & V_233 -> V_293 [ 0 ] ; V_181 < V_233 -> V_294 ; V_181 ++ , V_229 ++ ) {
V_96 = F_149 ( V_38 , V_229 -> V_96 ) ;
if ( F_150 ( V_96 ) )
continue;
if ( V_229 -> V_295 == V_296 ) {
switch ( V_229 -> type ) {
case V_259 :
case V_262 :
case V_271 :
V_13 = F_134 ( V_96 , V_229 ) ;
break;
case V_297 :
V_13 = F_114 ( V_96 , V_229 ) ;
break;
default:
V_13 = - V_284 ;
break;
}
} else {
V_13 = F_141 ( V_96 , V_229 ) ;
}
if ( V_13 ) {
F_151 ( V_178 , L_3 ,
V_229 -> V_295 , V_229 -> type ,
F_115 ( V_229 -> V_209 ) - 1 , V_13 ) ;
V_13 = 0 ;
}
}
F_152 (connector, tmp, &dev->mode_config.connector_list, head) {
if ( V_96 -> V_298 [ 0 ] )
continue;
F_151 ( V_178 , L_4 ,
F_153 ( V_96 ) ) ;
V_96 -> V_299 -> V_300 ( V_96 ) ;
}
V_207:
if ( V_13 )
F_146 ( V_38 ) ;
return V_13 ;
}

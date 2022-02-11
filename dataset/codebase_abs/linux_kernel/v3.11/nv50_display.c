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
if ( V_67 -> V_18 . V_61 -> V_100 > V_96 -> V_101 . V_102 * 3 )
V_97 = V_103 ;
} else {
V_97 = V_94 -> V_98 ;
}
if ( V_94 -> V_104 == V_105 ) {
if ( V_96 -> V_101 . V_102 >= 8 )
V_97 |= V_106 ;
} else {
V_97 |= V_94 -> V_104 ;
}
V_47 = F_22 ( V_53 , 4 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_107 ) {
F_36 ( V_47 , 0x08a0 + ( V_67 -> V_72 * 0x0400 ) , 1 ) ;
F_37 ( V_47 , V_97 ) ;
} else
if ( F_54 ( V_53 ) < V_108 ) {
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
struct V_109 * V_110 , * V_111 = & V_67 -> V_18 . V_97 ;
struct V_40 * V_43 = & V_67 -> V_18 ;
struct V_93 * V_94 ;
int V_97 = V_112 ;
T_1 V_113 , V_114 , * V_47 ;
V_94 = F_57 ( V_67 ) ;
if ( V_94 && V_94 -> V_115 )
V_97 = V_94 -> V_116 ;
if ( V_97 != V_112 )
V_110 = V_94 -> V_115 ;
else
V_110 = V_111 ;
V_113 = V_110 -> V_117 ;
V_114 = V_110 -> V_118 ;
if ( V_110 -> V_119 & V_120 )
V_114 *= 2 ;
if ( V_94 && ( V_94 -> V_121 == V_122 ||
( V_94 -> V_121 == V_123 &&
V_94 -> V_124 &&
F_59 ( V_94 -> V_124 ) ) ) ) {
T_1 V_125 = V_94 -> V_126 ;
T_1 V_127 = V_94 -> V_128 ;
T_1 V_129 = ( V_114 << 19 ) / V_113 ;
if ( V_125 ) {
V_113 -= ( V_125 * 2 ) ;
if ( V_127 ) V_114 -= ( V_127 * 2 ) ;
else V_114 = ( ( V_113 * V_129 ) + ( V_129 / 2 ) ) >> 19 ;
} else {
V_113 -= ( V_113 >> 4 ) + 32 ;
if ( V_127 ) V_114 -= ( V_127 * 2 ) ;
else V_114 = ( ( V_113 * V_129 ) + ( V_129 / 2 ) ) >> 19 ;
}
}
switch ( V_97 ) {
case V_130 :
V_113 = F_60 ( ( T_1 ) V_111 -> V_117 , V_113 ) ;
V_114 = F_60 ( ( T_1 ) V_111 -> V_118 , V_114 ) ;
case V_131 :
if ( V_114 < V_113 ) {
T_1 V_129 = ( V_111 -> V_117 << 19 ) / V_111 -> V_118 ;
V_113 = ( ( V_114 * V_129 ) + ( V_129 / 2 ) ) >> 19 ;
} else {
T_1 V_129 = ( V_111 -> V_118 << 19 ) / V_111 -> V_117 ;
V_114 = ( ( V_113 * V_129 ) + ( V_129 / 2 ) ) >> 19 ;
}
break;
default:
break;
}
V_47 = F_22 ( V_53 , 8 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_107 ) {
F_36 ( V_47 , 0x08d8 + ( V_67 -> V_72 * 0x400 ) , 2 ) ;
F_37 ( V_47 , ( V_114 << 16 ) | V_113 ) ;
F_37 ( V_47 , ( V_114 << 16 ) | V_113 ) ;
F_36 ( V_47 , 0x08a4 + ( V_67 -> V_72 * 0x400 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_36 ( V_47 , 0x08c8 + ( V_67 -> V_72 * 0x400 ) , 1 ) ;
F_37 ( V_47 , V_111 -> V_118 << 16 | V_111 -> V_117 ) ;
} else {
F_36 ( V_47 , 0x04c0 + ( V_67 -> V_72 * 0x300 ) , 3 ) ;
F_37 ( V_47 , ( V_114 << 16 ) | V_113 ) ;
F_37 ( V_47 , ( V_114 << 16 ) | V_113 ) ;
F_37 ( V_47 , ( V_114 << 16 ) | V_113 ) ;
F_36 ( V_47 , 0x0494 + ( V_67 -> V_72 * 0x300 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_36 ( V_47 , 0x04b8 + ( V_67 -> V_72 * 0x300 ) , 1 ) ;
F_37 ( V_47 , V_111 -> V_118 << 16 | V_111 -> V_117 ) ;
}
F_29 ( V_47 , V_53 ) ;
if ( V_92 ) {
F_41 ( V_43 ) ;
F_43 ( V_43 , V_43 -> V_61 , NULL , 1 ) ;
}
}
return 0 ;
}
static int
F_61 ( struct V_66 * V_67 , bool V_92 )
{
struct V_52 * V_53 = V_52 ( V_67 -> V_18 . V_38 ) ;
T_1 * V_47 , V_132 , V_133 ;
int V_134 ;
V_134 = ( V_67 -> V_135 > 0 ) ? 50 : 0 ;
V_133 = ( ( V_67 -> V_135 * 2047 + V_134 ) / 100 ) & 0xfff ;
V_132 = ( ( V_67 -> V_136 * 2047 ) / 100 ) & 0xfff ;
V_47 = F_22 ( V_53 , 16 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_107 ) {
F_36 ( V_47 , 0x08a8 + ( V_67 -> V_72 * 0x400 ) , 1 ) ;
F_37 ( V_47 , ( V_132 << 20 ) | ( V_133 << 8 ) ) ;
} else {
F_36 ( V_47 , 0x0498 + ( V_67 -> V_72 * 0x300 ) , 1 ) ;
F_37 ( V_47 , ( V_132 << 20 ) | ( V_133 << 8 ) ) ;
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
int V_137 , int V_138 , bool V_92 )
{
struct V_64 * V_139 = V_64 ( V_61 ) ;
struct V_52 * V_53 = V_52 ( V_67 -> V_18 . V_38 ) ;
T_1 * V_47 ;
V_47 = F_22 ( V_53 , 16 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_107 ) {
F_36 ( V_47 , 0x0860 + ( V_67 -> V_72 * 0x400 ) , 1 ) ;
F_37 ( V_47 , V_139 -> V_84 -> V_85 . V_86 >> 8 ) ;
F_36 ( V_47 , 0x0868 + ( V_67 -> V_72 * 0x400 ) , 3 ) ;
F_37 ( V_47 , ( V_61 -> V_87 << 16 ) | V_61 -> V_88 ) ;
F_37 ( V_47 , V_139 -> V_89 ) ;
F_37 ( V_47 , V_139 -> V_90 ) ;
F_36 ( V_47 , 0x08c0 + ( V_67 -> V_72 * 0x400 ) , 1 ) ;
F_37 ( V_47 , ( V_138 << 16 ) | V_137 ) ;
if ( F_54 ( V_53 ) > V_140 ) {
F_36 ( V_47 , 0x0874 + ( V_67 -> V_72 * 0x400 ) , 1 ) ;
F_37 ( V_47 , V_139 -> V_82 ) ;
}
} else {
F_36 ( V_47 , 0x0460 + ( V_67 -> V_72 * 0x300 ) , 1 ) ;
F_37 ( V_47 , V_139 -> V_84 -> V_85 . V_86 >> 8 ) ;
F_36 ( V_47 , 0x0468 + ( V_67 -> V_72 * 0x300 ) , 4 ) ;
F_37 ( V_47 , ( V_61 -> V_87 << 16 ) | V_61 -> V_88 ) ;
F_37 ( V_47 , V_139 -> V_89 ) ;
F_37 ( V_47 , V_139 -> V_90 ) ;
F_37 ( V_47 , V_139 -> V_82 ) ;
F_36 ( V_47 , 0x04b0 + ( V_67 -> V_72 * 0x300 ) , 1 ) ;
F_37 ( V_47 , ( V_138 << 16 ) | V_137 ) ;
}
if ( V_92 ) {
F_36 ( V_47 , 0x0080 , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
}
F_29 ( V_47 , V_53 ) ;
}
V_67 -> V_61 . V_141 = V_139 -> V_82 ;
return 0 ;
}
static void
F_63 ( struct V_66 * V_67 )
{
struct V_52 * V_53 = V_52 ( V_67 -> V_18 . V_38 ) ;
T_1 * V_47 = F_22 ( V_53 , 16 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_142 ) {
F_36 ( V_47 , 0x0880 + ( V_67 -> V_72 * 0x400 ) , 2 ) ;
F_37 ( V_47 , 0x85000000 ) ;
F_37 ( V_47 , V_67 -> V_143 . V_84 -> V_85 . V_86 >> 8 ) ;
} else
if ( F_54 ( V_53 ) < V_107 ) {
F_36 ( V_47 , 0x0880 + ( V_67 -> V_72 * 0x400 ) , 2 ) ;
F_37 ( V_47 , 0x85000000 ) ;
F_37 ( V_47 , V_67 -> V_143 . V_84 -> V_85 . V_86 >> 8 ) ;
F_36 ( V_47 , 0x089c + ( V_67 -> V_72 * 0x400 ) , 1 ) ;
F_37 ( V_47 , V_144 ) ;
} else {
F_36 ( V_47 , 0x0480 + ( V_67 -> V_72 * 0x300 ) , 2 ) ;
F_37 ( V_47 , 0x85000000 ) ;
F_37 ( V_47 , V_67 -> V_143 . V_84 -> V_85 . V_86 >> 8 ) ;
F_36 ( V_47 , 0x048c + ( V_67 -> V_72 * 0x300 ) , 1 ) ;
F_37 ( V_47 , V_144 ) ;
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
if ( F_54 ( V_53 ) < V_142 ) {
F_36 ( V_47 , 0x0880 + ( V_67 -> V_72 * 0x400 ) , 1 ) ;
F_37 ( V_47 , 0x05000000 ) ;
} else
if ( F_54 ( V_53 ) < V_107 ) {
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
F_65 ( struct V_66 * V_67 , bool V_145 , bool V_92 )
{
struct V_52 * V_53 = V_52 ( V_67 -> V_18 . V_38 ) ;
if ( V_145 )
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
if ( F_54 ( V_53 ) < V_142 ) {
F_36 ( V_47 , 0x0874 + ( V_67 -> V_72 * 0x400 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_36 ( V_47 , 0x0840 + ( V_67 -> V_72 * 0x400 ) , 1 ) ;
F_37 ( V_47 , 0x40000000 ) ;
} else
if ( F_54 ( V_53 ) < V_107 ) {
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
if ( F_54 ( V_53 ) < V_142 ) {
F_36 ( V_47 , 0x0874 + ( V_67 -> V_72 * 0x400 ) , 1 ) ;
F_37 ( V_47 , V_146 ) ;
F_36 ( V_47 , 0x0840 + ( V_67 -> V_72 * 0x400 ) , 2 ) ;
F_37 ( V_47 , 0xc0000000 ) ;
F_37 ( V_47 , V_67 -> V_147 . V_84 -> V_85 . V_86 >> 8 ) ;
} else
if ( F_54 ( V_53 ) < V_107 ) {
F_36 ( V_47 , 0x0874 + ( V_67 -> V_72 * 0x400 ) , 1 ) ;
F_37 ( V_47 , V_67 -> V_61 . V_141 ) ;
F_36 ( V_47 , 0x0840 + ( V_67 -> V_72 * 0x400 ) , 2 ) ;
F_37 ( V_47 , 0xc0000000 ) ;
F_37 ( V_47 , V_67 -> V_147 . V_84 -> V_85 . V_86 >> 8 ) ;
F_36 ( V_47 , 0x085c + ( V_67 -> V_72 * 0x400 ) , 1 ) ;
F_37 ( V_47 , V_144 ) ;
} else {
F_36 ( V_47 , 0x0474 + ( V_67 -> V_72 * 0x300 ) , 1 ) ;
F_37 ( V_47 , V_67 -> V_61 . V_141 ) ;
F_36 ( V_47 , 0x0440 + ( V_67 -> V_72 * 0x300 ) , 4 ) ;
F_37 ( V_47 , 0x83000000 ) ;
F_37 ( V_47 , V_67 -> V_147 . V_84 -> V_85 . V_86 >> 8 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_36 ( V_47 , 0x045c + ( V_67 -> V_72 * 0x300 ) , 1 ) ;
F_37 ( V_47 , V_144 ) ;
F_36 ( V_47 , 0x0430 + ( V_67 -> V_72 * 0x300 ) , 1 ) ;
F_37 ( V_47 , 0xffffff00 ) ;
}
F_29 ( V_47 , V_53 ) ;
}
F_65 ( V_67 , V_67 -> V_143 . V_148 , true ) ;
F_43 ( V_43 , V_43 -> V_61 , NULL , 1 ) ;
}
static bool
F_69 ( struct V_40 * V_43 , const struct V_109 * V_97 ,
struct V_109 * V_149 )
{
return true ;
}
static int
F_70 ( struct V_40 * V_43 , struct V_60 * V_150 )
{
struct V_64 * V_139 = V_64 ( V_43 -> V_61 ) ;
struct V_68 * V_4 = V_68 ( V_43 ) ;
int V_13 ;
V_13 = F_71 ( V_139 -> V_84 , V_151 ) ;
if ( V_13 == 0 ) {
if ( V_4 -> V_91 )
F_72 ( V_4 -> V_91 ) ;
F_55 ( V_139 -> V_84 , & V_4 -> V_91 ) ;
}
return V_13 ;
}
static int
F_73 ( struct V_40 * V_43 , struct V_109 * V_111 ,
struct V_109 * V_97 , int V_137 , int V_138 ,
struct V_60 * V_150 )
{
struct V_52 * V_53 = V_52 ( V_43 -> V_38 ) ;
struct V_66 * V_67 = V_66 ( V_43 ) ;
struct V_93 * V_94 ;
T_1 V_152 = ( V_97 -> V_119 & V_153 ) ? 2 : 1 ;
T_1 V_154 = ( V_97 -> V_119 & V_120 ) ? 2 : 1 ;
T_1 V_155 , V_156 , V_157 , V_158 , V_159 , V_160 ;
T_1 V_161 , V_162 , V_163 , V_164 , V_165 , V_166 ;
T_1 V_167 = 0 , V_168 = 1 ;
T_1 * V_47 ;
int V_13 ;
V_155 = V_97 -> V_169 ;
V_156 = V_97 -> V_170 - V_97 -> V_171 - 1 ;
V_157 = V_97 -> V_169 - V_97 -> V_170 ;
V_159 = V_156 + V_157 ;
V_158 = V_97 -> V_171 - V_97 -> V_117 ;
V_160 = V_97 -> V_169 - V_158 - 1 ;
V_161 = V_97 -> V_172 * V_154 / V_152 ;
V_162 = ( ( V_97 -> V_173 - V_97 -> V_174 ) * V_154 / V_152 ) - 1 ;
V_163 = ( V_97 -> V_172 - V_97 -> V_173 ) * V_154 / V_152 ;
V_165 = V_162 + V_163 ;
V_164 = ( V_97 -> V_174 - V_97 -> V_118 ) * V_154 / V_152 ;
V_166 = V_161 - V_164 - 1 ;
if ( V_97 -> V_119 & V_153 ) {
V_167 = V_161 + V_162 + V_163 ;
V_168 = V_167 + ( V_97 -> V_118 * V_154 / V_152 ) ;
V_161 = ( V_161 * 2 ) + 1 ;
}
V_13 = F_70 ( V_43 , V_150 ) ;
if ( V_13 )
return V_13 ;
V_47 = F_22 ( V_53 , 64 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_107 ) {
F_36 ( V_47 , 0x0804 + ( V_67 -> V_72 * 0x400 ) , 2 ) ;
F_37 ( V_47 , 0x00800000 | V_97 -> clock ) ;
F_37 ( V_47 , ( V_152 == 2 ) ? 2 : 0 ) ;
F_36 ( V_47 , 0x0810 + ( V_67 -> V_72 * 0x400 ) , 6 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_37 ( V_47 , ( V_161 << 16 ) | V_155 ) ;
F_37 ( V_47 , ( V_162 << 16 ) | V_156 ) ;
F_37 ( V_47 , ( V_165 << 16 ) | V_159 ) ;
F_37 ( V_47 , ( V_166 << 16 ) | V_160 ) ;
F_37 ( V_47 , ( V_167 << 16 ) | V_168 ) ;
F_36 ( V_47 , 0x082c + ( V_67 -> V_72 * 0x400 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_36 ( V_47 , 0x0900 + ( V_67 -> V_72 * 0x400 ) , 2 ) ;
F_37 ( V_47 , 0x00000311 ) ;
F_37 ( V_47 , 0x00000100 ) ;
} else {
F_36 ( V_47 , 0x0410 + ( V_67 -> V_72 * 0x300 ) , 6 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_37 ( V_47 , ( V_161 << 16 ) | V_155 ) ;
F_37 ( V_47 , ( V_162 << 16 ) | V_156 ) ;
F_37 ( V_47 , ( V_165 << 16 ) | V_159 ) ;
F_37 ( V_47 , ( V_166 << 16 ) | V_160 ) ;
F_37 ( V_47 , ( V_167 << 16 ) | V_168 ) ;
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
F_62 ( V_67 , V_43 -> V_61 , V_137 , V_138 , false ) ;
return 0 ;
}
static int
F_74 ( struct V_40 * V_43 , int V_137 , int V_138 ,
struct V_60 * V_150 )
{
struct V_175 * V_176 = V_175 ( V_43 -> V_38 ) ;
struct V_66 * V_67 = V_66 ( V_43 ) ;
int V_13 ;
if ( ! V_43 -> V_61 ) {
F_75 ( V_176 , L_2 ) ;
return 0 ;
}
V_13 = F_70 ( V_43 , V_150 ) ;
if ( V_13 )
return V_13 ;
F_41 ( V_43 ) ;
F_62 ( V_67 , V_43 -> V_61 , V_137 , V_138 , true ) ;
F_43 ( V_43 , V_43 -> V_61 , NULL , 1 ) ;
return 0 ;
}
static int
F_76 ( struct V_40 * V_43 ,
struct V_60 * V_61 , int V_137 , int V_138 ,
enum V_177 V_178 )
{
struct V_66 * V_67 = V_66 ( V_43 ) ;
F_41 ( V_43 ) ;
F_62 ( V_67 , V_61 , V_137 , V_138 , true ) ;
return 0 ;
}
static void
F_77 ( struct V_40 * V_43 )
{
struct V_36 * V_51 = V_36 ( V_43 -> V_38 ) ;
struct V_66 * V_67 = V_66 ( V_43 ) ;
void T_4 * V_147 = F_78 ( V_67 -> V_147 . V_84 ) ;
int V_179 ;
for ( V_179 = 0 ; V_179 < 256 ; V_179 ++ ) {
T_5 V_180 = V_67 -> V_147 . V_180 [ V_179 ] >> 2 ;
T_5 V_181 = V_67 -> V_147 . V_181 [ V_179 ] >> 2 ;
T_5 V_182 = V_67 -> V_147 . V_182 [ V_179 ] >> 2 ;
if ( F_45 ( V_51 -> V_2 ) < V_183 ) {
F_79 ( V_180 + 0x0000 , V_147 + ( V_179 * 0x08 ) + 0 ) ;
F_79 ( V_181 + 0x0000 , V_147 + ( V_179 * 0x08 ) + 2 ) ;
F_79 ( V_182 + 0x0000 , V_147 + ( V_179 * 0x08 ) + 4 ) ;
} else {
F_79 ( V_180 + 0x6000 , V_147 + ( V_179 * 0x20 ) + 0 ) ;
F_79 ( V_181 + 0x6000 , V_147 + ( V_179 * 0x20 ) + 2 ) ;
F_79 ( V_182 + 0x6000 , V_147 + ( V_179 * 0x20 ) + 4 ) ;
}
}
}
static void
F_80 ( struct V_40 * V_43 )
{
struct V_68 * V_4 = V_68 ( V_43 ) ;
if ( V_4 -> V_91 )
F_72 ( V_4 -> V_91 ) ;
F_55 ( NULL , & V_4 -> V_91 ) ;
}
static int
F_81 ( struct V_40 * V_43 , struct V_184 * V_185 ,
T_6 V_12 , T_6 V_88 , T_6 V_87 )
{
struct V_66 * V_67 = V_66 ( V_43 ) ;
struct V_37 * V_38 = V_43 -> V_38 ;
struct V_186 * V_187 ;
struct V_56 * V_84 ;
bool V_148 = ( V_12 != 0 ) ;
int V_179 , V_13 = 0 ;
if ( V_148 ) {
if ( V_88 != 64 || V_87 != 64 )
return - V_188 ;
V_187 = F_82 ( V_38 , V_185 , V_12 ) ;
if ( F_44 ( ! V_187 ) )
return - V_189 ;
V_84 = F_83 ( V_187 ) ;
V_13 = F_84 ( V_84 ) ;
if ( V_13 == 0 ) {
for ( V_179 = 0 ; V_179 < 64 * 64 ; V_179 ++ ) {
T_1 V_190 = F_31 ( V_84 , V_179 ) ;
F_35 ( V_67 -> V_143 . V_84 , V_179 , V_190 ) ;
}
F_85 ( V_84 ) ;
}
F_86 ( V_187 ) ;
}
if ( V_148 != V_67 -> V_143 . V_148 ) {
F_65 ( V_67 , V_148 , true ) ;
V_67 -> V_143 . V_148 = V_148 ;
}
return V_13 ;
}
static int
F_87 ( struct V_40 * V_43 , int V_137 , int V_138 )
{
struct V_191 * V_192 = V_191 ( V_43 ) ;
struct V_7 * V_8 = V_7 ( V_192 ) ;
F_25 ( V_8 -> V_15 , 0x0084 , ( V_138 << 16 ) | ( V_137 & 0xffff ) ) ;
F_25 ( V_8 -> V_15 , 0x0080 , 0x00000000 ) ;
return 0 ;
}
static void
F_88 ( struct V_40 * V_43 , T_5 * V_180 , T_5 * V_181 , T_5 * V_182 ,
T_6 V_193 , T_6 V_6 )
{
struct V_66 * V_67 = V_66 ( V_43 ) ;
T_1 V_194 = F_89 ( V_193 + V_6 , ( T_1 ) 256 ) ;
T_1 V_179 ;
for ( V_179 = V_193 ; V_179 < V_194 ; V_179 ++ ) {
V_67 -> V_147 . V_180 [ V_179 ] = V_180 [ V_179 ] ;
V_67 -> V_147 . V_181 [ V_179 ] = V_181 [ V_179 ] ;
V_67 -> V_147 . V_182 [ V_179 ] = V_182 [ V_179 ] ;
}
F_77 ( V_43 ) ;
}
static void
F_90 ( struct V_40 * V_43 )
{
struct V_66 * V_67 = V_66 ( V_43 ) ;
struct V_36 * V_51 = V_36 ( V_43 -> V_38 ) ;
struct V_68 * V_4 = V_68 ( V_43 ) ;
F_10 ( V_51 -> V_2 , & V_4 -> V_195 . V_18 ) ;
F_8 ( V_51 -> V_2 , & V_4 -> V_196 . V_18 ) ;
F_10 ( V_51 -> V_2 , & V_4 -> V_54 . V_18 ) ;
F_8 ( V_51 -> V_2 , & V_4 -> V_192 . V_18 ) ;
if ( V_4 -> V_91 )
F_72 ( V_4 -> V_91 ) ;
F_55 ( NULL , & V_4 -> V_91 ) ;
F_85 ( V_67 -> V_143 . V_84 ) ;
if ( V_67 -> V_143 . V_84 )
F_72 ( V_67 -> V_143 . V_84 ) ;
F_55 ( NULL , & V_67 -> V_143 . V_84 ) ;
F_85 ( V_67 -> V_147 . V_84 ) ;
if ( V_67 -> V_147 . V_84 )
F_72 ( V_67 -> V_147 . V_84 ) ;
F_55 ( NULL , & V_67 -> V_147 . V_84 ) ;
F_91 ( V_43 ) ;
F_92 ( V_43 ) ;
}
static void
F_93 ( struct V_66 * V_67 , int V_137 , int V_138 )
{
}
static void
F_94 ( struct V_66 * V_67 , T_6 V_86 )
{
}
static int
F_95 ( struct V_37 * V_38 , struct V_1 * V_2 , int V_72 )
{
struct V_36 * V_51 = V_36 ( V_38 ) ;
struct V_68 * V_4 ;
struct V_40 * V_43 ;
int V_13 , V_179 ;
V_4 = F_96 ( sizeof( * V_4 ) , V_197 ) ;
if ( ! V_4 )
return - V_32 ;
V_4 -> V_18 . V_72 = V_72 ;
V_4 -> V_18 . V_198 = F_56 ;
V_4 -> V_18 . V_199 = F_58 ;
V_4 -> V_18 . V_200 = F_61 ;
V_4 -> V_18 . V_135 = 50 ;
V_4 -> V_18 . V_136 = 0 ;
V_4 -> V_18 . V_143 . V_201 = F_94 ;
V_4 -> V_18 . V_143 . V_202 = F_93 ;
for ( V_179 = 0 ; V_179 < 256 ; V_179 ++ ) {
V_4 -> V_18 . V_147 . V_180 [ V_179 ] = V_179 << 8 ;
V_4 -> V_18 . V_147 . V_181 [ V_179 ] = V_179 << 8 ;
V_4 -> V_18 . V_147 . V_182 [ V_179 ] = V_179 << 8 ;
}
V_43 = & V_4 -> V_18 . V_18 ;
F_97 ( V_38 , V_43 , & V_203 ) ;
F_98 ( V_43 , & V_204 ) ;
F_99 ( V_43 , 256 ) ;
V_13 = F_100 ( V_38 , 8192 , 0x100 , V_151 ,
0 , 0x0000 , NULL , & V_4 -> V_18 . V_147 . V_84 ) ;
if ( ! V_13 ) {
V_13 = F_71 ( V_4 -> V_18 . V_147 . V_84 , V_151 ) ;
if ( ! V_13 ) {
V_13 = F_84 ( V_4 -> V_18 . V_147 . V_84 ) ;
if ( V_13 )
F_72 ( V_4 -> V_18 . V_147 . V_84 ) ;
}
if ( V_13 )
F_55 ( NULL , & V_4 -> V_18 . V_147 . V_84 ) ;
}
if ( V_13 )
goto V_205;
F_77 ( V_43 ) ;
V_13 = F_9 (disp->core, NV50_DISP_CURS_CLASS, index,
&(struct nv50_display_curs_class) {
.head = index,
}, sizeof(struct nv50_display_curs_class),
&head->curs.base) ;
if ( V_13 )
goto V_205;
V_13 = F_100 ( V_38 , 64 * 64 * 4 , 0x100 , V_151 ,
0 , 0x0000 , NULL , & V_4 -> V_18 . V_143 . V_84 ) ;
if ( ! V_13 ) {
V_13 = F_71 ( V_4 -> V_18 . V_143 . V_84 , V_151 ) ;
if ( ! V_13 ) {
V_13 = F_84 ( V_4 -> V_18 . V_143 . V_84 ) ;
if ( V_13 )
F_72 ( V_4 -> V_18 . V_147 . V_84 ) ;
}
if ( V_13 )
F_55 ( NULL , & V_4 -> V_18 . V_143 . V_84 ) ;
}
if ( V_13 )
goto V_205;
V_13 = F_16 (disp->core, NV50_DISP_SYNC_CLASS, index,
&(struct nv50_display_sync_class) {
.pushbuf = EVO_PUSH_HANDLE(SYNC, index),
.head = index,
}, sizeof(struct nv50_display_sync_class),
disp->sync->bo.offset, &head->sync.base) ;
if ( V_13 )
goto V_205;
V_4 -> V_54 . V_59 = F_101 ( V_72 ) ;
V_4 -> V_54 . V_5 = 0x00000000 ;
V_13 = F_9 (disp->core, NV50_DISP_OIMM_CLASS, index,
&(struct nv50_display_oimm_class) {
.head = index,
}, sizeof(struct nv50_display_oimm_class),
&head->oimm.base) ;
if ( V_13 )
goto V_205;
V_13 = F_16 (disp->core, NV50_DISP_OVLY_CLASS, index,
&(struct nv50_display_ovly_class) {
.pushbuf = EVO_PUSH_HANDLE(OVLY, index),
.head = index,
}, sizeof(struct nv50_display_ovly_class),
disp->sync->bo.offset, &head->ovly.base) ;
if ( V_13 )
goto V_205;
V_205:
if ( V_13 )
F_90 ( V_43 ) ;
return V_13 ;
}
static void
F_102 ( struct V_41 * V_42 , int V_97 )
{
struct F_21 * V_206 = F_21 ( V_42 ) ;
struct V_36 * V_51 = V_36 ( V_42 -> V_38 ) ;
int V_207 = V_206 -> V_207 ;
T_1 V_208 ;
V_208 = 0x00000000 ;
if ( V_97 == V_209 || V_97 == V_210 )
V_208 |= 0x00000001 ;
if ( V_97 == V_211 || V_97 == V_210 )
V_208 |= 0x00000004 ;
F_103 ( V_51 -> V_2 , V_212 + V_207 , V_208 ) ;
}
static bool
F_104 ( struct V_41 * V_42 ,
const struct V_109 * V_97 ,
struct V_109 * V_149 )
{
struct F_21 * V_206 = F_21 ( V_42 ) ;
struct V_93 * V_94 ;
V_94 = F_105 ( V_206 ) ;
if ( V_94 && V_94 -> V_115 ) {
if ( V_94 -> V_116 != V_112 ) {
int V_213 = V_149 -> V_18 . V_213 ;
* V_149 = * V_94 -> V_115 ;
V_149 -> V_18 . V_213 = V_213 ;
}
}
return true ;
}
static void
F_106 ( struct V_41 * V_42 )
{
}
static void
F_107 ( struct V_41 * V_42 , struct V_109 * V_97 ,
struct V_109 * V_149 )
{
struct V_52 * V_53 = V_52 ( V_42 -> V_38 ) ;
struct F_21 * V_206 = F_21 ( V_42 ) ;
struct V_66 * V_67 = V_66 ( V_42 -> V_43 ) ;
T_1 * V_47 ;
F_102 ( V_42 , V_214 ) ;
V_47 = F_22 ( V_53 , 8 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_107 ) {
T_1 V_215 = 0x00000000 ;
if ( V_97 -> V_119 & V_216 )
V_215 |= 0x00000001 ;
if ( V_97 -> V_119 & V_217 )
V_215 |= 0x00000002 ;
F_36 ( V_47 , 0x0400 + ( V_206 -> V_207 * 0x080 ) , 2 ) ;
F_37 ( V_47 , 1 << V_67 -> V_72 ) ;
F_37 ( V_47 , V_215 ) ;
} else {
T_1 V_218 = 0x31ec6000 | ( V_67 -> V_72 << 25 ) ;
T_1 V_215 = 0x00000001 ;
if ( V_97 -> V_119 & V_216 )
V_215 |= 0x00000008 ;
if ( V_97 -> V_119 & V_217 )
V_215 |= 0x00000010 ;
if ( V_97 -> V_119 & V_153 )
V_218 |= 0x00000001 ;
F_36 ( V_47 , 0x0404 + ( V_67 -> V_72 * 0x300 ) , 2 ) ;
F_37 ( V_47 , V_215 ) ;
F_37 ( V_47 , V_218 ) ;
F_36 ( V_47 , 0x0180 + ( V_206 -> V_207 * 0x020 ) , 1 ) ;
F_37 ( V_47 , 1 << V_67 -> V_72 ) ;
}
F_29 ( V_47 , V_53 ) ;
}
V_206 -> V_43 = V_42 -> V_43 ;
}
static void
F_108 ( struct V_41 * V_42 )
{
struct F_21 * V_206 = F_21 ( V_42 ) ;
struct V_52 * V_53 = V_52 ( V_42 -> V_38 ) ;
const int V_207 = V_206 -> V_207 ;
T_1 * V_47 ;
if ( V_206 -> V_43 ) {
F_67 ( V_206 -> V_43 ) ;
V_47 = F_22 ( V_53 , 4 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_107 ) {
F_36 ( V_47 , 0x0400 + ( V_207 * 0x080 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
} else {
F_36 ( V_47 , 0x0180 + ( V_207 * 0x020 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
}
F_29 ( V_47 , V_53 ) ;
}
}
V_206 -> V_43 = NULL ;
}
static enum V_219
F_109 ( struct V_41 * V_42 , struct V_95 * V_96 )
{
struct V_36 * V_51 = V_36 ( V_42 -> V_38 ) ;
int V_13 , V_207 = F_21 ( V_42 ) -> V_207 ;
T_1 V_220 = V_175 ( V_42 -> V_38 ) -> V_221 . V_222 ;
if ( V_220 == 0 )
V_220 = 340 ;
V_13 = F_110 ( V_51 -> V_2 , V_223 + V_207 , & V_220 , sizeof( V_220 ) ) ;
if ( V_13 || V_220 != 7 )
return V_224 ;
return V_225 ;
}
static void
F_111 ( struct V_41 * V_42 )
{
F_112 ( V_42 ) ;
F_92 ( V_42 ) ;
}
static int
F_113 ( struct V_95 * V_96 , struct V_226 * V_227 )
{
struct V_175 * V_176 = V_175 ( V_96 -> V_38 ) ;
struct V_228 * V_229 = V_228 ( V_176 -> V_50 ) ;
struct F_21 * V_206 ;
struct V_41 * V_42 ;
int type = V_230 ;
V_206 = F_96 ( sizeof( * V_206 ) , V_197 ) ;
if ( ! V_206 )
return - V_32 ;
V_206 -> V_231 = V_227 ;
V_206 -> V_207 = F_114 ( V_227 -> V_207 ) - 1 ;
V_206 -> V_229 = V_229 -> V_232 ( V_229 , V_227 -> V_233 ) ;
V_42 = F_115 ( V_206 ) ;
V_42 -> V_234 = V_227 -> V_235 ;
V_42 -> V_236 = 0 ;
F_116 ( V_96 -> V_38 , V_42 , & V_237 , type ) ;
F_117 ( V_42 , & V_238 ) ;
F_118 ( V_96 , V_42 ) ;
return 0 ;
}
static void
F_119 ( struct V_41 * V_42 , struct V_109 * V_97 )
{
struct F_21 * V_206 = F_21 ( V_42 ) ;
struct V_93 * V_94 ;
struct V_36 * V_51 = V_36 ( V_42 -> V_38 ) ;
V_94 = F_105 ( V_206 ) ;
if ( ! F_120 ( V_94 -> V_124 ) )
return;
F_121 ( & V_94 -> V_18 , V_94 -> V_124 ) ;
F_110 ( V_51 -> V_2 , V_239 + V_206 -> V_207 ,
V_94 -> V_18 . V_240 ,
V_94 -> V_18 . V_240 [ 2 ] * 4 ) ;
}
static void
F_122 ( struct V_41 * V_42 )
{
struct F_21 * V_206 = F_21 ( V_42 ) ;
struct V_36 * V_51 = V_36 ( V_42 -> V_38 ) ;
F_110 ( V_51 -> V_2 , V_239 + V_206 -> V_207 , NULL , 0 ) ;
}
static void
F_123 ( struct V_41 * V_42 , struct V_109 * V_97 )
{
struct F_21 * V_206 = F_21 ( V_42 ) ;
struct V_66 * V_67 = V_66 ( V_42 -> V_43 ) ;
struct V_93 * V_94 ;
struct V_36 * V_51 = V_36 ( V_42 -> V_38 ) ;
const T_1 V_241 = ( V_67 -> V_72 << 3 ) | V_206 -> V_207 ;
T_1 V_242 = 56 ;
T_1 V_243 ;
V_94 = F_105 ( V_206 ) ;
if ( ! F_59 ( V_94 -> V_124 ) )
return;
V_243 = V_97 -> V_169 - V_97 -> V_117 ;
V_243 -= V_242 ;
V_243 -= 18 ;
V_243 /= 32 ;
F_103 ( V_51 -> V_2 , V_244 + V_241 ,
V_245 |
( V_243 << 16 ) | V_242 ) ;
F_119 ( V_42 , V_97 ) ;
}
static void
F_124 ( struct V_41 * V_42 )
{
struct F_21 * V_206 = F_21 ( V_42 ) ;
struct V_66 * V_67 = V_66 ( V_206 -> V_43 ) ;
struct V_36 * V_51 = V_36 ( V_42 -> V_38 ) ;
const T_1 V_241 = ( V_67 -> V_72 << 3 ) | V_206 -> V_207 ;
F_122 ( V_42 ) ;
F_103 ( V_51 -> V_2 , V_244 + V_241 , 0x00000000 ) ;
}
static void
F_125 ( struct V_41 * V_42 , int V_97 )
{
struct F_21 * V_206 = F_21 ( V_42 ) ;
struct V_37 * V_38 = V_42 -> V_38 ;
struct V_36 * V_51 = V_36 ( V_38 ) ;
struct V_41 * V_246 ;
int V_207 = V_206 -> V_207 ;
V_206 -> V_247 = V_97 ;
F_126 (partner, &dev->mode_config.encoder_list, head) {
struct F_21 * V_248 = F_21 ( V_246 ) ;
if ( V_246 -> V_249 != V_250 )
continue;
if ( V_248 != V_206 &&
V_248 -> V_231 -> V_207 == V_206 -> V_231 -> V_207 ) {
if ( V_248 -> V_247 == V_214 )
return;
break;
}
}
F_103 ( V_51 -> V_2 , V_251 + V_207 , ( V_97 == V_214 ) ) ;
}
static bool
F_127 ( struct V_41 * V_42 ,
const struct V_109 * V_97 ,
struct V_109 * V_149 )
{
struct F_21 * V_206 = F_21 ( V_42 ) ;
struct V_93 * V_94 ;
V_94 = F_105 ( V_206 ) ;
if ( V_94 && V_94 -> V_115 ) {
if ( V_94 -> V_116 != V_112 ) {
int V_213 = V_149 -> V_18 . V_213 ;
* V_149 = * V_94 -> V_115 ;
V_149 -> V_18 . V_213 = V_213 ;
}
}
return true ;
}
static void
F_128 ( struct V_41 * V_42 )
{
struct F_21 * V_206 = F_21 ( V_42 ) ;
struct V_52 * V_53 = V_52 ( V_42 -> V_38 ) ;
const int V_207 = V_206 -> V_207 ;
T_1 * V_47 ;
if ( V_206 -> V_43 ) {
F_67 ( V_206 -> V_43 ) ;
V_47 = F_22 ( V_53 , 4 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_107 ) {
F_36 ( V_47 , 0x0600 + ( V_207 * 0x40 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
} else {
F_36 ( V_47 , 0x0200 + ( V_207 * 0x20 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
}
F_29 ( V_47 , V_53 ) ;
}
F_124 ( V_42 ) ;
}
V_206 -> V_247 = V_210 ;
V_206 -> V_43 = NULL ;
}
static void
F_129 ( struct V_41 * V_42 )
{
}
static void
F_130 ( struct V_41 * V_42 , struct V_109 * V_111 ,
struct V_109 * V_97 )
{
struct V_36 * V_51 = V_36 ( V_42 -> V_38 ) ;
struct V_52 * V_53 = V_52 ( V_42 -> V_38 ) ;
struct V_37 * V_38 = V_42 -> V_38 ;
struct V_175 * V_176 = V_175 ( V_38 ) ;
struct F_21 * V_206 = F_21 ( V_42 ) ;
struct V_66 * V_67 = V_66 ( V_42 -> V_43 ) ;
struct V_93 * V_94 ;
struct V_252 * V_253 = & V_176 -> V_221 ;
T_1 * V_47 , V_254 = 0 ;
T_2 V_255 = 1 << V_67 -> V_72 ;
T_2 V_256 = 0xf ;
T_2 V_100 = 0x0 ;
V_94 = F_105 ( V_206 ) ;
switch ( V_206 -> V_231 -> type ) {
case V_257 :
if ( V_206 -> V_231 -> V_258 . V_259 & 1 ) {
if ( V_97 -> clock < 165000 )
V_256 = 0x1 ;
else
V_256 = 0x5 ;
} else {
V_256 = 0x2 ;
}
F_123 ( V_42 , V_97 ) ;
break;
case V_260 :
V_256 = 0x0 ;
if ( V_253 -> V_261 ) {
if ( V_253 -> V_262 . V_263 )
V_254 |= 0x0100 ;
if ( V_253 -> V_262 . V_264 )
V_254 |= 0x0200 ;
} else {
if ( V_94 -> type == V_265 ) {
if ( ( ( T_2 * ) V_94 -> V_124 ) [ 121 ] == 2 )
V_254 |= 0x0100 ;
} else
if ( V_97 -> clock >= V_253 -> V_262 . V_266 ) {
V_254 |= 0x0100 ;
}
if ( V_254 & 0x0100 ) {
if ( V_253 -> V_262 . V_267 & 2 )
V_254 |= 0x0200 ;
} else {
if ( V_253 -> V_262 . V_267 & 1 )
V_254 |= 0x0200 ;
}
if ( V_94 -> V_18 . V_101 . V_102 == 8 )
V_254 |= 0x0200 ;
}
F_103 ( V_51 -> V_2 , V_268 + V_206 -> V_207 , V_254 ) ;
break;
case V_269 :
if ( V_94 -> V_18 . V_101 . V_102 == 6 ) {
V_206 -> V_270 . V_271 = V_97 -> clock * 18 / 8 ;
V_100 = 0x2 ;
} else
if ( V_94 -> V_18 . V_101 . V_102 == 8 ) {
V_206 -> V_270 . V_271 = V_97 -> clock * 24 / 8 ;
V_100 = 0x5 ;
} else {
V_206 -> V_270 . V_271 = V_97 -> clock * 30 / 8 ;
V_100 = 0x6 ;
}
if ( V_206 -> V_231 -> V_258 . V_259 & 1 )
V_256 = 0x8 ;
else
V_256 = 0x9 ;
break;
default:
F_131 ( 1 ) ;
break;
}
F_125 ( V_42 , V_214 ) ;
V_47 = F_22 ( V_52 ( V_38 ) , 8 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_183 ) {
T_1 V_272 = ( V_100 << 16 ) | ( V_256 << 8 ) | V_255 ;
if ( V_97 -> V_119 & V_216 )
V_272 |= 0x00001000 ;
if ( V_97 -> V_119 & V_217 )
V_272 |= 0x00002000 ;
F_36 ( V_47 , 0x0600 + ( V_206 -> V_207 * 0x040 ) , 1 ) ;
F_37 ( V_47 , V_272 ) ;
} else {
T_1 V_218 = 0x31ec6000 | ( V_67 -> V_72 << 25 ) ;
T_1 V_215 = 0x00000001 ;
if ( V_97 -> V_119 & V_216 )
V_215 |= 0x00000008 ;
if ( V_97 -> V_119 & V_217 )
V_215 |= 0x00000010 ;
if ( V_97 -> V_119 & V_153 )
V_218 |= 0x00000001 ;
F_36 ( V_47 , 0x0404 + ( V_67 -> V_72 * 0x300 ) , 2 ) ;
F_37 ( V_47 , V_215 | ( V_100 << 6 ) ) ;
F_37 ( V_47 , V_218 ) ;
F_36 ( V_47 , 0x0200 + ( V_206 -> V_207 * 0x020 ) , 1 ) ;
F_37 ( V_47 , V_255 | ( V_256 << 8 ) ) ;
}
F_29 ( V_47 , V_53 ) ;
}
V_206 -> V_43 = V_42 -> V_43 ;
}
static void
F_132 ( struct V_41 * V_42 )
{
F_112 ( V_42 ) ;
F_92 ( V_42 ) ;
}
static int
F_133 ( struct V_95 * V_96 , struct V_226 * V_227 )
{
struct V_175 * V_176 = V_175 ( V_96 -> V_38 ) ;
struct V_228 * V_229 = V_228 ( V_176 -> V_50 ) ;
struct F_21 * V_206 ;
struct V_41 * V_42 ;
int type ;
switch ( V_227 -> type ) {
case V_260 : type = V_273 ; break;
case V_257 :
case V_269 :
default:
type = V_250 ;
break;
}
V_206 = F_96 ( sizeof( * V_206 ) , V_197 ) ;
if ( ! V_206 )
return - V_32 ;
V_206 -> V_231 = V_227 ;
V_206 -> V_207 = F_114 ( V_227 -> V_207 ) - 1 ;
V_206 -> V_229 = V_229 -> V_232 ( V_229 , V_227 -> V_233 ) ;
V_206 -> V_247 = V_210 ;
V_42 = F_115 ( V_206 ) ;
V_42 -> V_234 = V_227 -> V_235 ;
V_42 -> V_236 = 0 ;
F_116 ( V_96 -> V_38 , V_42 , & V_274 , type ) ;
F_117 ( V_42 , & V_275 ) ;
F_118 ( V_96 , V_42 ) ;
return 0 ;
}
static void
F_134 ( struct V_41 * V_42 , int V_97 )
{
struct F_21 * V_206 = F_21 ( V_42 ) ;
struct V_36 * V_51 = V_36 ( V_42 -> V_38 ) ;
T_1 V_276 = ( V_206 -> V_231 -> type << 12 ) | V_206 -> V_207 ;
T_1 V_272 = ( V_97 == V_214 ) ;
F_103 ( V_51 -> V_2 , V_277 + V_276 , V_272 ) ;
}
static bool
F_135 ( struct V_41 * V_42 ,
const struct V_109 * V_97 ,
struct V_109 * V_149 )
{
struct F_21 * V_206 = F_21 ( V_42 ) ;
struct V_93 * V_94 ;
V_94 = F_105 ( V_206 ) ;
if ( V_94 && V_94 -> V_115 ) {
if ( V_94 -> V_116 != V_112 ) {
int V_213 = V_149 -> V_18 . V_213 ;
* V_149 = * V_94 -> V_115 ;
V_149 -> V_18 . V_213 = V_213 ;
}
}
V_149 -> clock *= 2 ;
return true ;
}
static void
F_136 ( struct V_41 * V_42 )
{
}
static void
F_137 ( struct V_41 * V_42 , struct V_109 * V_97 ,
struct V_109 * V_149 )
{
struct V_52 * V_53 = V_52 ( V_42 -> V_38 ) ;
struct F_21 * V_206 = F_21 ( V_42 ) ;
struct V_66 * V_67 = V_66 ( V_42 -> V_43 ) ;
struct V_93 * V_94 ;
T_2 V_255 = 1 << V_67 -> V_72 ;
T_2 V_256 , V_100 ;
T_1 * V_47 ;
V_94 = F_105 ( V_206 ) ;
switch ( V_94 -> V_18 . V_101 . V_102 ) {
case 10 : V_100 = 0x6 ; break;
case 8 : V_100 = 0x5 ; break;
case 6 : V_100 = 0x2 ; break;
default: V_100 = 0x0 ; break;
}
switch ( V_206 -> V_231 -> type ) {
case V_257 :
case V_269 :
V_256 = 0x0 ;
break;
default:
F_131 ( 1 ) ;
break;
}
F_134 ( V_42 , V_214 ) ;
V_47 = F_22 ( V_53 , 8 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_107 ) {
T_1 V_272 = ( V_100 << 16 ) | ( V_256 << 8 ) | V_255 ;
if ( V_97 -> V_119 & V_216 )
V_272 |= 0x00001000 ;
if ( V_97 -> V_119 & V_217 )
V_272 |= 0x00002000 ;
F_36 ( V_47 , 0x0700 + ( V_206 -> V_207 * 0x040 ) , 1 ) ;
F_37 ( V_47 , V_272 ) ;
}
F_29 ( V_47 , V_53 ) ;
}
V_206 -> V_43 = V_42 -> V_43 ;
}
static void
F_138 ( struct V_41 * V_42 )
{
struct F_21 * V_206 = F_21 ( V_42 ) ;
struct V_52 * V_53 = V_52 ( V_42 -> V_38 ) ;
const int V_207 = V_206 -> V_207 ;
T_1 * V_47 ;
if ( V_206 -> V_43 ) {
F_67 ( V_206 -> V_43 ) ;
V_47 = F_22 ( V_53 , 4 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_107 ) {
F_36 ( V_47 , 0x0700 + ( V_207 * 0x040 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
}
F_29 ( V_47 , V_53 ) ;
}
}
V_206 -> V_43 = NULL ;
}
static void
F_139 ( struct V_41 * V_42 )
{
F_112 ( V_42 ) ;
F_92 ( V_42 ) ;
}
static int
F_140 ( struct V_95 * V_96 , struct V_226 * V_227 )
{
struct V_175 * V_176 = V_175 ( V_96 -> V_38 ) ;
struct V_228 * V_229 = V_228 ( V_176 -> V_50 ) ;
struct V_278 * V_279 = NULL ;
struct F_21 * V_206 ;
struct V_41 * V_42 ;
int type ;
switch ( V_227 -> type ) {
case V_257 :
V_279 = V_229 -> V_280 ( V_229 , F_141 ( V_227 -> V_281 ) ) ;
type = V_250 ;
break;
case V_269 :
V_279 = V_229 -> V_280 ( V_229 , F_142 ( V_227 -> V_281 ) ) ;
type = V_250 ;
break;
default:
return - V_282 ;
}
V_206 = F_96 ( sizeof( * V_206 ) , V_197 ) ;
if ( ! V_206 )
return - V_32 ;
V_206 -> V_231 = V_227 ;
V_206 -> V_207 = F_114 ( V_227 -> V_207 ) - 1 ;
V_206 -> V_229 = V_279 ;
V_42 = F_115 ( V_206 ) ;
V_42 -> V_234 = V_227 -> V_235 ;
V_42 -> V_236 = 0 ;
F_116 ( V_96 -> V_38 , V_42 , & V_283 , type ) ;
F_117 ( V_42 , & V_284 ) ;
F_118 ( V_96 , V_42 ) ;
return 0 ;
}
void
F_143 ( struct V_37 * V_38 )
{
}
int
F_144 ( struct V_37 * V_38 )
{
struct V_36 * V_51 = V_36 ( V_38 ) ;
struct V_40 * V_43 ;
T_1 * V_47 ;
V_47 = F_22 ( V_52 ( V_38 ) , 32 ) ;
if ( ! V_47 )
return - V_55 ;
F_126 (crtc, &dev->mode_config.crtc_list, head) {
struct F_42 * V_54 = F_42 ( V_43 ) ;
F_35 ( V_51 -> V_54 , V_54 -> V_59 / 4 , V_54 -> V_5 ) ;
}
F_36 ( V_47 , 0x0088 , 1 ) ;
F_37 ( V_47 , V_81 ) ;
F_29 ( V_47 , V_52 ( V_38 ) ) ;
return 0 ;
}
void
F_145 ( struct V_37 * V_38 )
{
struct V_36 * V_51 = V_36 ( V_38 ) ;
F_10 ( V_51 -> V_2 , & V_51 -> V_53 . V_18 ) ;
F_85 ( V_51 -> V_54 ) ;
if ( V_51 -> V_54 )
F_72 ( V_51 -> V_54 ) ;
F_55 ( NULL , & V_51 -> V_54 ) ;
F_19 ( V_38 ) -> V_39 = NULL ;
F_92 ( V_51 ) ;
}
int
F_146 ( struct V_37 * V_38 )
{
static const T_5 V_11 [] = {
V_285 ,
V_286 ,
V_183 ,
V_287 ,
V_288 ,
V_289 ,
V_290 ,
V_291 ,
} ;
struct V_49 * V_50 = F_34 ( V_38 ) ;
struct V_175 * V_176 = V_175 ( V_38 ) ;
struct V_292 * V_231 = & V_176 -> V_221 . V_231 ;
struct V_95 * V_96 , * V_293 ;
struct V_36 * V_51 ;
struct V_226 * V_227 ;
int V_294 , V_13 , V_179 ;
V_51 = F_96 ( sizeof( * V_51 ) , V_197 ) ;
if ( ! V_51 )
return - V_32 ;
F_19 ( V_38 ) -> V_39 = V_51 ;
F_19 ( V_38 ) -> V_295 = F_145 ;
F_19 ( V_38 ) -> V_296 = F_144 ;
F_19 ( V_38 ) -> V_297 = F_143 ;
V_13 = F_100 ( V_38 , 4096 , 0x1000 , V_151 ,
0 , 0x0000 , NULL , & V_51 -> V_54 ) ;
if ( ! V_13 ) {
V_13 = F_71 ( V_51 -> V_54 , V_151 ) ;
if ( ! V_13 ) {
V_13 = F_84 ( V_51 -> V_54 ) ;
if ( V_13 )
F_72 ( V_51 -> V_54 ) ;
}
if ( V_13 )
F_55 ( NULL , & V_51 -> V_54 ) ;
}
if ( V_13 )
goto V_205;
V_13 = - V_282 ;
for ( V_179 = 0 ; V_13 && V_179 < F_147 ( V_11 ) ; V_179 ++ ) {
V_13 = F_5 ( F_148 ( V_176 ) , V_298 ,
0xd1500000 , V_11 [ V_179 ] , NULL , 0 ,
& V_51 -> V_2 ) ;
}
if ( V_13 )
goto V_205;
V_13 = F_16 (disp->core, NV50_DISP_MAST_CLASS, 0 ,
&(struct nv50_display_mast_class) {
.pushbuf = EVO_PUSH_HANDLE(MAST, 0),
}, sizeof(struct nv50_display_mast_class),
disp->sync->bo.offset, &disp->mast.base) ;
if ( V_13 )
goto V_205;
if ( F_45 ( V_51 -> V_2 ) >= V_183 )
V_294 = F_149 ( V_50 , 0x022448 ) ;
else
V_294 = 2 ;
for ( V_179 = 0 ; V_179 < V_294 ; V_179 ++ ) {
V_13 = F_95 ( V_38 , V_51 -> V_2 , V_179 ) ;
if ( V_13 )
goto V_205;
}
for ( V_179 = 0 , V_227 = & V_231 -> V_299 [ 0 ] ; V_179 < V_231 -> V_300 ; V_179 ++ , V_227 ++ ) {
V_96 = F_150 ( V_38 , V_227 -> V_96 ) ;
if ( F_151 ( V_96 ) )
continue;
if ( V_227 -> V_301 == V_302 ) {
switch ( V_227 -> type ) {
case V_257 :
case V_260 :
case V_269 :
V_13 = F_133 ( V_96 , V_227 ) ;
break;
case V_303 :
V_13 = F_113 ( V_96 , V_227 ) ;
break;
default:
V_13 = - V_282 ;
break;
}
} else {
V_13 = F_140 ( V_96 , V_227 ) ;
}
if ( V_13 ) {
F_152 ( V_176 , L_3 ,
V_227 -> V_301 , V_227 -> type ,
F_114 ( V_227 -> V_207 ) - 1 , V_13 ) ;
V_13 = 0 ;
}
}
F_153 (connector, tmp, &dev->mode_config.connector_list, head) {
if ( V_96 -> V_304 [ 0 ] )
continue;
F_152 ( V_176 , L_4 ,
F_154 ( V_96 ) ) ;
V_96 -> V_305 -> V_306 ( V_96 ) ;
}
V_205:
if ( V_13 )
F_145 ( V_38 ) ;
return V_13 ;
}

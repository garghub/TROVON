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
.limit = pfb->ram.size - 1 ,
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
struct F_42 * V_54 = F_42 ( V_43 ) ;
int V_4 = V_67 -> V_68 , V_13 ;
T_1 * V_47 ;
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
F_48 ( V_8 , V_71 + V_4 ) ;
F_48 ( V_8 , V_54 -> V_59 ^ 0x10 ) ;
F_47 ( V_8 , 0 , V_72 , 1 ) ;
F_48 ( V_8 , V_54 -> V_5 + 1 ) ;
F_47 ( V_8 , 0 , V_73 , 2 ) ;
F_48 ( V_8 , V_54 -> V_59 ) ;
F_48 ( V_8 , V_54 -> V_5 ) ;
} else
if ( V_8 && F_45 ( V_8 -> V_28 ) < V_74 ) {
T_3 V_59 = F_49 ( V_8 , V_4 ) + V_54 -> V_59 ;
V_13 = F_46 ( V_8 , 12 ) ;
if ( V_13 )
return V_13 ;
F_47 ( V_8 , 0 , V_70 , 1 ) ;
F_48 ( V_8 , V_8 -> V_75 ) ;
F_47 ( V_8 , 0 , V_76 , 4 ) ;
F_48 ( V_8 , F_50 ( V_59 ^ 0x10 ) ) ;
F_48 ( V_8 , F_51 ( V_59 ^ 0x10 ) ) ;
F_48 ( V_8 , V_54 -> V_5 + 1 ) ;
F_48 ( V_8 , V_77 ) ;
F_47 ( V_8 , 0 , V_76 , 4 ) ;
F_48 ( V_8 , F_50 ( V_59 ) ) ;
F_48 ( V_8 , F_51 ( V_59 ) ) ;
F_48 ( V_8 , V_54 -> V_5 ) ;
F_48 ( V_8 , V_78 ) ;
} else
if ( V_8 ) {
T_3 V_59 = F_49 ( V_8 , V_4 ) + V_54 -> V_59 ;
V_13 = F_46 ( V_8 , 10 ) ;
if ( V_13 )
return V_13 ;
F_52 ( V_8 , 0 , V_76 , 4 ) ;
F_48 ( V_8 , F_50 ( V_59 ^ 0x10 ) ) ;
F_48 ( V_8 , F_51 ( V_59 ^ 0x10 ) ) ;
F_48 ( V_8 , V_54 -> V_5 + 1 ) ;
F_48 ( V_8 , V_77 |
V_79 ) ;
F_52 ( V_8 , 0 , V_76 , 4 ) ;
F_48 ( V_8 , F_50 ( V_59 ) ) ;
F_48 ( V_8 , F_51 ( V_59 ) ) ;
F_48 ( V_8 , V_54 -> V_5 ) ;
F_48 ( V_8 , V_78 |
V_79 ) ;
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
F_37 ( V_47 , V_80 ) ;
F_36 ( V_47 , 0x00a0 , 2 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_36 ( V_47 , 0x00c0 , 1 ) ;
F_37 ( V_47 , V_65 -> V_81 ) ;
F_36 ( V_47 , 0x0110 , 2 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_37 ( V_47 , 0x00000000 ) ;
if ( F_54 ( V_54 ) < V_82 ) {
F_36 ( V_47 , 0x0800 , 5 ) ;
F_37 ( V_47 , V_65 -> V_83 -> V_84 . V_85 >> 8 ) ;
F_37 ( V_47 , 0 ) ;
F_37 ( V_47 , ( V_61 -> V_86 << 16 ) | V_61 -> V_87 ) ;
F_37 ( V_47 , V_65 -> V_88 ) ;
F_37 ( V_47 , V_65 -> V_89 ) ;
} else {
F_36 ( V_47 , 0x0400 , 5 ) ;
F_37 ( V_47 , V_65 -> V_83 -> V_84 . V_85 >> 8 ) ;
F_37 ( V_47 , 0 ) ;
F_37 ( V_47 , ( V_61 -> V_86 << 16 ) | V_61 -> V_87 ) ;
F_37 ( V_47 , V_65 -> V_88 ) ;
F_37 ( V_47 , V_65 -> V_89 ) ;
}
F_36 ( V_47 , 0x0080 , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_29 ( V_47 , V_54 ) ;
return 0 ;
}
static int
F_55 ( struct V_66 * V_67 , bool V_90 )
{
struct V_52 * V_53 = V_52 ( V_67 -> V_18 . V_38 ) ;
struct V_91 * V_92 ;
struct V_93 * V_94 ;
T_1 * V_47 , V_95 = 0x00 ;
V_92 = F_56 ( V_67 ) ;
V_94 = & V_92 -> V_18 ;
if ( V_92 -> V_96 == V_97 ) {
if ( V_67 -> V_18 . V_61 -> V_98 > V_94 -> V_99 . V_100 * 3 )
V_95 = V_101 ;
} else {
V_95 = V_92 -> V_96 ;
}
if ( V_92 -> V_102 == V_103 ) {
if ( V_94 -> V_99 . V_100 >= 8 )
V_95 |= V_104 ;
} else {
V_95 |= V_92 -> V_102 ;
}
V_47 = F_22 ( V_53 , 4 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_105 ) {
F_36 ( V_47 , 0x08a0 + ( V_67 -> V_68 * 0x0400 ) , 1 ) ;
F_37 ( V_47 , V_95 ) ;
} else
if ( F_54 ( V_53 ) < V_106 ) {
F_36 ( V_47 , 0x0490 + ( V_67 -> V_68 * 0x0300 ) , 1 ) ;
F_37 ( V_47 , V_95 ) ;
} else {
F_36 ( V_47 , 0x04a0 + ( V_67 -> V_68 * 0x0300 ) , 1 ) ;
F_37 ( V_47 , V_95 ) ;
}
if ( V_90 ) {
F_36 ( V_47 , 0x0080 , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
}
F_29 ( V_47 , V_53 ) ;
}
return 0 ;
}
static int
F_57 ( struct V_66 * V_67 , bool V_90 )
{
struct V_52 * V_53 = V_52 ( V_67 -> V_18 . V_38 ) ;
struct V_107 * V_108 , * V_109 = & V_67 -> V_18 . V_95 ;
struct V_40 * V_43 = & V_67 -> V_18 ;
struct V_91 * V_92 ;
int V_95 = V_110 ;
T_1 V_111 , V_112 , * V_47 ;
V_92 = F_56 ( V_67 ) ;
if ( V_92 && V_92 -> V_113 )
V_95 = V_92 -> V_114 ;
if ( V_95 != V_110 )
V_108 = V_92 -> V_113 ;
else
V_108 = V_109 ;
V_111 = V_108 -> V_115 ;
V_112 = V_108 -> V_116 ;
if ( V_108 -> V_117 & V_118 )
V_112 *= 2 ;
if ( V_92 && ( V_92 -> V_119 == V_120 ||
( V_92 -> V_119 == V_121 &&
V_92 -> V_122 &&
F_58 ( V_92 -> V_122 ) ) ) ) {
T_1 V_123 = V_92 -> V_124 ;
T_1 V_125 = V_92 -> V_126 ;
T_1 V_127 = ( V_112 << 19 ) / V_111 ;
if ( V_123 ) {
V_111 -= ( V_123 * 2 ) ;
if ( V_125 ) V_112 -= ( V_125 * 2 ) ;
else V_112 = ( ( V_111 * V_127 ) + ( V_127 / 2 ) ) >> 19 ;
} else {
V_111 -= ( V_111 >> 4 ) + 32 ;
if ( V_125 ) V_112 -= ( V_125 * 2 ) ;
else V_112 = ( ( V_111 * V_127 ) + ( V_127 / 2 ) ) >> 19 ;
}
}
switch ( V_95 ) {
case V_128 :
V_111 = F_59 ( ( T_1 ) V_109 -> V_115 , V_111 ) ;
V_112 = F_59 ( ( T_1 ) V_109 -> V_116 , V_112 ) ;
case V_129 :
if ( V_112 < V_111 ) {
T_1 V_127 = ( V_109 -> V_115 << 19 ) / V_109 -> V_116 ;
V_111 = ( ( V_112 * V_127 ) + ( V_127 / 2 ) ) >> 19 ;
} else {
T_1 V_127 = ( V_109 -> V_116 << 19 ) / V_109 -> V_115 ;
V_112 = ( ( V_111 * V_127 ) + ( V_127 / 2 ) ) >> 19 ;
}
break;
default:
break;
}
V_47 = F_22 ( V_53 , 8 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_105 ) {
F_36 ( V_47 , 0x08d8 + ( V_67 -> V_68 * 0x400 ) , 2 ) ;
F_37 ( V_47 , ( V_112 << 16 ) | V_111 ) ;
F_37 ( V_47 , ( V_112 << 16 ) | V_111 ) ;
F_36 ( V_47 , 0x08a4 + ( V_67 -> V_68 * 0x400 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_36 ( V_47 , 0x08c8 + ( V_67 -> V_68 * 0x400 ) , 1 ) ;
F_37 ( V_47 , V_109 -> V_116 << 16 | V_109 -> V_115 ) ;
} else {
F_36 ( V_47 , 0x04c0 + ( V_67 -> V_68 * 0x300 ) , 3 ) ;
F_37 ( V_47 , ( V_112 << 16 ) | V_111 ) ;
F_37 ( V_47 , ( V_112 << 16 ) | V_111 ) ;
F_37 ( V_47 , ( V_112 << 16 ) | V_111 ) ;
F_36 ( V_47 , 0x0494 + ( V_67 -> V_68 * 0x300 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_36 ( V_47 , 0x04b8 + ( V_67 -> V_68 * 0x300 ) , 1 ) ;
F_37 ( V_47 , V_109 -> V_116 << 16 | V_109 -> V_115 ) ;
}
F_29 ( V_47 , V_53 ) ;
if ( V_90 ) {
F_41 ( V_43 ) ;
F_43 ( V_43 , V_43 -> V_61 , NULL , 1 ) ;
}
}
return 0 ;
}
static int
F_60 ( struct V_66 * V_67 , bool V_90 )
{
struct V_52 * V_53 = V_52 ( V_67 -> V_18 . V_38 ) ;
T_1 * V_47 , V_130 , V_131 ;
int V_132 ;
V_132 = ( V_67 -> V_133 > 0 ) ? 50 : 0 ;
V_131 = ( ( V_67 -> V_133 * 2047 + V_132 ) / 100 ) & 0xfff ;
V_130 = ( ( V_67 -> V_134 * 2047 ) / 100 ) & 0xfff ;
V_47 = F_22 ( V_53 , 16 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_105 ) {
F_36 ( V_47 , 0x08a8 + ( V_67 -> V_68 * 0x400 ) , 1 ) ;
F_37 ( V_47 , ( V_130 << 20 ) | ( V_131 << 8 ) ) ;
} else {
F_36 ( V_47 , 0x0498 + ( V_67 -> V_68 * 0x300 ) , 1 ) ;
F_37 ( V_47 , ( V_130 << 20 ) | ( V_131 << 8 ) ) ;
}
if ( V_90 ) {
F_36 ( V_47 , 0x0080 , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
}
F_29 ( V_47 , V_53 ) ;
}
return 0 ;
}
static int
F_61 ( struct V_66 * V_67 , struct V_60 * V_61 ,
int V_135 , int V_136 , bool V_90 )
{
struct V_64 * V_137 = V_64 ( V_61 ) ;
struct V_52 * V_53 = V_52 ( V_67 -> V_18 . V_38 ) ;
T_1 * V_47 ;
V_47 = F_22 ( V_53 , 16 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_105 ) {
F_36 ( V_47 , 0x0860 + ( V_67 -> V_68 * 0x400 ) , 1 ) ;
F_37 ( V_47 , V_137 -> V_83 -> V_84 . V_85 >> 8 ) ;
F_36 ( V_47 , 0x0868 + ( V_67 -> V_68 * 0x400 ) , 3 ) ;
F_37 ( V_47 , ( V_61 -> V_86 << 16 ) | V_61 -> V_87 ) ;
F_37 ( V_47 , V_137 -> V_88 ) ;
F_37 ( V_47 , V_137 -> V_89 ) ;
F_36 ( V_47 , 0x08c0 + ( V_67 -> V_68 * 0x400 ) , 1 ) ;
F_37 ( V_47 , ( V_136 << 16 ) | V_135 ) ;
if ( F_54 ( V_53 ) > V_138 ) {
F_36 ( V_47 , 0x0874 + ( V_67 -> V_68 * 0x400 ) , 1 ) ;
F_37 ( V_47 , V_137 -> V_81 ) ;
}
} else {
F_36 ( V_47 , 0x0460 + ( V_67 -> V_68 * 0x300 ) , 1 ) ;
F_37 ( V_47 , V_137 -> V_83 -> V_84 . V_85 >> 8 ) ;
F_36 ( V_47 , 0x0468 + ( V_67 -> V_68 * 0x300 ) , 4 ) ;
F_37 ( V_47 , ( V_61 -> V_86 << 16 ) | V_61 -> V_87 ) ;
F_37 ( V_47 , V_137 -> V_88 ) ;
F_37 ( V_47 , V_137 -> V_89 ) ;
F_37 ( V_47 , V_137 -> V_81 ) ;
F_36 ( V_47 , 0x04b0 + ( V_67 -> V_68 * 0x300 ) , 1 ) ;
F_37 ( V_47 , ( V_136 << 16 ) | V_135 ) ;
}
if ( V_90 ) {
F_36 ( V_47 , 0x0080 , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
}
F_29 ( V_47 , V_53 ) ;
}
V_67 -> V_61 . V_139 = V_137 -> V_81 ;
return 0 ;
}
static void
F_62 ( struct V_66 * V_67 )
{
struct V_52 * V_53 = V_52 ( V_67 -> V_18 . V_38 ) ;
T_1 * V_47 = F_22 ( V_53 , 16 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_140 ) {
F_36 ( V_47 , 0x0880 + ( V_67 -> V_68 * 0x400 ) , 2 ) ;
F_37 ( V_47 , 0x85000000 ) ;
F_37 ( V_47 , V_67 -> V_141 . V_83 -> V_84 . V_85 >> 8 ) ;
} else
if ( F_54 ( V_53 ) < V_105 ) {
F_36 ( V_47 , 0x0880 + ( V_67 -> V_68 * 0x400 ) , 2 ) ;
F_37 ( V_47 , 0x85000000 ) ;
F_37 ( V_47 , V_67 -> V_141 . V_83 -> V_84 . V_85 >> 8 ) ;
F_36 ( V_47 , 0x089c + ( V_67 -> V_68 * 0x400 ) , 1 ) ;
F_37 ( V_47 , V_142 ) ;
} else {
F_36 ( V_47 , 0x0480 + ( V_67 -> V_68 * 0x300 ) , 2 ) ;
F_37 ( V_47 , 0x85000000 ) ;
F_37 ( V_47 , V_67 -> V_141 . V_83 -> V_84 . V_85 >> 8 ) ;
F_36 ( V_47 , 0x048c + ( V_67 -> V_68 * 0x300 ) , 1 ) ;
F_37 ( V_47 , V_142 ) ;
}
F_29 ( V_47 , V_53 ) ;
}
}
static void
F_63 ( struct V_66 * V_67 )
{
struct V_52 * V_53 = V_52 ( V_67 -> V_18 . V_38 ) ;
T_1 * V_47 = F_22 ( V_53 , 16 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_140 ) {
F_36 ( V_47 , 0x0880 + ( V_67 -> V_68 * 0x400 ) , 1 ) ;
F_37 ( V_47 , 0x05000000 ) ;
} else
if ( F_54 ( V_53 ) < V_105 ) {
F_36 ( V_47 , 0x0880 + ( V_67 -> V_68 * 0x400 ) , 1 ) ;
F_37 ( V_47 , 0x05000000 ) ;
F_36 ( V_47 , 0x089c + ( V_67 -> V_68 * 0x400 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
} else {
F_36 ( V_47 , 0x0480 + ( V_67 -> V_68 * 0x300 ) , 1 ) ;
F_37 ( V_47 , 0x05000000 ) ;
F_36 ( V_47 , 0x048c + ( V_67 -> V_68 * 0x300 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
}
F_29 ( V_47 , V_53 ) ;
}
}
static void
F_64 ( struct V_66 * V_67 , bool V_143 , bool V_90 )
{
struct V_52 * V_53 = V_52 ( V_67 -> V_18 . V_38 ) ;
if ( V_143 )
F_62 ( V_67 ) ;
else
F_63 ( V_67 ) ;
if ( V_90 ) {
T_1 * V_47 = F_22 ( V_53 , 2 ) ;
if ( V_47 ) {
F_36 ( V_47 , 0x0080 , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_29 ( V_47 , V_53 ) ;
}
}
}
static void
F_65 ( struct V_40 * V_43 , int V_95 )
{
}
static void
F_66 ( struct V_40 * V_43 )
{
struct V_66 * V_67 = V_66 ( V_43 ) ;
struct V_52 * V_53 = V_52 ( V_43 -> V_38 ) ;
T_1 * V_47 ;
F_41 ( V_43 ) ;
V_47 = F_22 ( V_53 , 2 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_140 ) {
F_36 ( V_47 , 0x0874 + ( V_67 -> V_68 * 0x400 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_36 ( V_47 , 0x0840 + ( V_67 -> V_68 * 0x400 ) , 1 ) ;
F_37 ( V_47 , 0x40000000 ) ;
} else
if ( F_54 ( V_53 ) < V_105 ) {
F_36 ( V_47 , 0x0874 + ( V_67 -> V_68 * 0x400 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_36 ( V_47 , 0x0840 + ( V_67 -> V_68 * 0x400 ) , 1 ) ;
F_37 ( V_47 , 0x40000000 ) ;
F_36 ( V_47 , 0x085c + ( V_67 -> V_68 * 0x400 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
} else {
F_36 ( V_47 , 0x0474 + ( V_67 -> V_68 * 0x300 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_36 ( V_47 , 0x0440 + ( V_67 -> V_68 * 0x300 ) , 1 ) ;
F_37 ( V_47 , 0x03000000 ) ;
F_36 ( V_47 , 0x045c + ( V_67 -> V_68 * 0x300 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
}
F_29 ( V_47 , V_53 ) ;
}
F_64 ( V_67 , false , false ) ;
}
static void
F_67 ( struct V_40 * V_43 )
{
struct V_66 * V_67 = V_66 ( V_43 ) ;
struct V_52 * V_53 = V_52 ( V_43 -> V_38 ) ;
T_1 * V_47 ;
V_47 = F_22 ( V_53 , 32 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_140 ) {
F_36 ( V_47 , 0x0874 + ( V_67 -> V_68 * 0x400 ) , 1 ) ;
F_37 ( V_47 , V_144 ) ;
F_36 ( V_47 , 0x0840 + ( V_67 -> V_68 * 0x400 ) , 2 ) ;
F_37 ( V_47 , 0xc0000000 ) ;
F_37 ( V_47 , V_67 -> V_145 . V_83 -> V_84 . V_85 >> 8 ) ;
} else
if ( F_54 ( V_53 ) < V_105 ) {
F_36 ( V_47 , 0x0874 + ( V_67 -> V_68 * 0x400 ) , 1 ) ;
F_37 ( V_47 , V_67 -> V_61 . V_139 ) ;
F_36 ( V_47 , 0x0840 + ( V_67 -> V_68 * 0x400 ) , 2 ) ;
F_37 ( V_47 , 0xc0000000 ) ;
F_37 ( V_47 , V_67 -> V_145 . V_83 -> V_84 . V_85 >> 8 ) ;
F_36 ( V_47 , 0x085c + ( V_67 -> V_68 * 0x400 ) , 1 ) ;
F_37 ( V_47 , V_142 ) ;
} else {
F_36 ( V_47 , 0x0474 + ( V_67 -> V_68 * 0x300 ) , 1 ) ;
F_37 ( V_47 , V_67 -> V_61 . V_139 ) ;
F_36 ( V_47 , 0x0440 + ( V_67 -> V_68 * 0x300 ) , 4 ) ;
F_37 ( V_47 , 0x83000000 ) ;
F_37 ( V_47 , V_67 -> V_145 . V_83 -> V_84 . V_85 >> 8 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_36 ( V_47 , 0x045c + ( V_67 -> V_68 * 0x300 ) , 1 ) ;
F_37 ( V_47 , V_142 ) ;
F_36 ( V_47 , 0x0430 + ( V_67 -> V_68 * 0x300 ) , 1 ) ;
F_37 ( V_47 , 0xffffff00 ) ;
}
F_29 ( V_47 , V_53 ) ;
}
F_64 ( V_67 , V_67 -> V_141 . V_146 , true ) ;
F_43 ( V_43 , V_43 -> V_61 , NULL , 1 ) ;
}
static bool
F_68 ( struct V_40 * V_43 , const struct V_107 * V_95 ,
struct V_107 * V_147 )
{
return true ;
}
static int
F_69 ( struct V_40 * V_43 , struct V_60 * V_148 )
{
struct V_64 * V_137 = V_64 ( V_43 -> V_61 ) ;
int V_13 ;
V_13 = F_70 ( V_137 -> V_83 , V_149 ) ;
if ( V_13 )
return V_13 ;
if ( V_148 ) {
V_137 = V_64 ( V_148 ) ;
F_71 ( V_137 -> V_83 ) ;
}
return 0 ;
}
static int
F_72 ( struct V_40 * V_43 , struct V_107 * V_109 ,
struct V_107 * V_95 , int V_135 , int V_136 ,
struct V_60 * V_148 )
{
struct V_52 * V_53 = V_52 ( V_43 -> V_38 ) ;
struct V_66 * V_67 = V_66 ( V_43 ) ;
struct V_91 * V_92 ;
T_1 V_150 = ( V_95 -> V_117 & V_151 ) ? 2 : 1 ;
T_1 V_152 = ( V_95 -> V_117 & V_118 ) ? 2 : 1 ;
T_1 V_153 , V_154 , V_155 , V_156 , V_157 , V_158 ;
T_1 V_159 , V_160 , V_161 , V_162 , V_163 , V_164 ;
T_1 V_165 = 0 , V_166 = 1 ;
T_1 * V_47 ;
int V_13 ;
V_153 = V_95 -> V_167 ;
V_154 = V_95 -> V_168 - V_95 -> V_169 - 1 ;
V_155 = V_95 -> V_167 - V_95 -> V_168 ;
V_157 = V_154 + V_155 ;
V_156 = V_95 -> V_169 - V_95 -> V_115 ;
V_158 = V_95 -> V_167 - V_156 - 1 ;
V_159 = V_95 -> V_170 * V_152 / V_150 ;
V_160 = ( ( V_95 -> V_171 - V_95 -> V_172 ) * V_152 / V_150 ) - 1 ;
V_161 = ( V_95 -> V_170 - V_95 -> V_171 ) * V_152 / V_150 ;
V_163 = V_160 + V_161 ;
V_162 = ( V_95 -> V_172 - V_95 -> V_116 ) * V_152 / V_150 ;
V_164 = V_159 - V_162 - 1 ;
if ( V_95 -> V_117 & V_151 ) {
V_165 = V_159 + V_160 + V_161 ;
V_166 = V_165 + ( V_95 -> V_116 * V_152 / V_150 ) ;
V_159 = ( V_159 * 2 ) + 1 ;
}
V_13 = F_69 ( V_43 , V_148 ) ;
if ( V_13 )
return V_13 ;
V_47 = F_22 ( V_53 , 64 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_105 ) {
F_36 ( V_47 , 0x0804 + ( V_67 -> V_68 * 0x400 ) , 2 ) ;
F_37 ( V_47 , 0x00800000 | V_95 -> clock ) ;
F_37 ( V_47 , ( V_150 == 2 ) ? 2 : 0 ) ;
F_36 ( V_47 , 0x0810 + ( V_67 -> V_68 * 0x400 ) , 6 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_37 ( V_47 , ( V_159 << 16 ) | V_153 ) ;
F_37 ( V_47 , ( V_160 << 16 ) | V_154 ) ;
F_37 ( V_47 , ( V_163 << 16 ) | V_157 ) ;
F_37 ( V_47 , ( V_164 << 16 ) | V_158 ) ;
F_37 ( V_47 , ( V_165 << 16 ) | V_166 ) ;
F_36 ( V_47 , 0x082c + ( V_67 -> V_68 * 0x400 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_36 ( V_47 , 0x0900 + ( V_67 -> V_68 * 0x400 ) , 2 ) ;
F_37 ( V_47 , 0x00000311 ) ;
F_37 ( V_47 , 0x00000100 ) ;
} else {
F_36 ( V_47 , 0x0410 + ( V_67 -> V_68 * 0x300 ) , 6 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_37 ( V_47 , ( V_159 << 16 ) | V_153 ) ;
F_37 ( V_47 , ( V_160 << 16 ) | V_154 ) ;
F_37 ( V_47 , ( V_163 << 16 ) | V_157 ) ;
F_37 ( V_47 , ( V_164 << 16 ) | V_158 ) ;
F_37 ( V_47 , ( V_165 << 16 ) | V_166 ) ;
F_36 ( V_47 , 0x042c + ( V_67 -> V_68 * 0x300 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
F_36 ( V_47 , 0x0450 + ( V_67 -> V_68 * 0x300 ) , 3 ) ;
F_37 ( V_47 , V_95 -> clock * 1000 ) ;
F_37 ( V_47 , 0x00200000 ) ;
F_37 ( V_47 , V_95 -> clock * 1000 ) ;
F_36 ( V_47 , 0x04d0 + ( V_67 -> V_68 * 0x300 ) , 2 ) ;
F_37 ( V_47 , 0x00000311 ) ;
F_37 ( V_47 , 0x00000100 ) ;
}
F_29 ( V_47 , V_53 ) ;
}
V_92 = F_56 ( V_67 ) ;
F_55 ( V_67 , false ) ;
F_57 ( V_67 , false ) ;
F_60 ( V_67 , false ) ;
F_61 ( V_67 , V_43 -> V_61 , V_135 , V_136 , false ) ;
return 0 ;
}
static int
F_73 ( struct V_40 * V_43 , int V_135 , int V_136 ,
struct V_60 * V_148 )
{
struct V_173 * V_174 = V_173 ( V_43 -> V_38 ) ;
struct V_66 * V_67 = V_66 ( V_43 ) ;
int V_13 ;
if ( ! V_43 -> V_61 ) {
F_74 ( V_174 , L_2 ) ;
return 0 ;
}
V_13 = F_69 ( V_43 , V_148 ) ;
if ( V_13 )
return V_13 ;
F_41 ( V_43 ) ;
F_61 ( V_67 , V_43 -> V_61 , V_135 , V_136 , true ) ;
F_43 ( V_43 , V_43 -> V_61 , NULL , 1 ) ;
return 0 ;
}
static int
F_75 ( struct V_40 * V_43 ,
struct V_60 * V_61 , int V_135 , int V_136 ,
enum V_175 V_176 )
{
struct V_66 * V_67 = V_66 ( V_43 ) ;
F_41 ( V_43 ) ;
F_61 ( V_67 , V_61 , V_135 , V_136 , true ) ;
return 0 ;
}
static void
F_76 ( struct V_40 * V_43 )
{
struct V_36 * V_51 = V_36 ( V_43 -> V_38 ) ;
struct V_66 * V_67 = V_66 ( V_43 ) ;
void T_4 * V_145 = F_77 ( V_67 -> V_145 . V_83 ) ;
int V_177 ;
for ( V_177 = 0 ; V_177 < 256 ; V_177 ++ ) {
T_5 V_178 = V_67 -> V_145 . V_178 [ V_177 ] >> 2 ;
T_5 V_179 = V_67 -> V_145 . V_179 [ V_177 ] >> 2 ;
T_5 V_180 = V_67 -> V_145 . V_180 [ V_177 ] >> 2 ;
if ( F_45 ( V_51 -> V_2 ) < V_181 ) {
F_78 ( V_178 + 0x0000 , V_145 + ( V_177 * 0x08 ) + 0 ) ;
F_78 ( V_179 + 0x0000 , V_145 + ( V_177 * 0x08 ) + 2 ) ;
F_78 ( V_180 + 0x0000 , V_145 + ( V_177 * 0x08 ) + 4 ) ;
} else {
F_78 ( V_178 + 0x6000 , V_145 + ( V_177 * 0x20 ) + 0 ) ;
F_78 ( V_179 + 0x6000 , V_145 + ( V_177 * 0x20 ) + 2 ) ;
F_78 ( V_180 + 0x6000 , V_145 + ( V_177 * 0x20 ) + 4 ) ;
}
}
}
static int
F_79 ( struct V_40 * V_43 , struct V_182 * V_183 ,
T_6 V_12 , T_6 V_87 , T_6 V_86 )
{
struct V_66 * V_67 = V_66 ( V_43 ) ;
struct V_37 * V_38 = V_43 -> V_38 ;
struct V_184 * V_185 ;
struct V_56 * V_83 ;
bool V_146 = ( V_12 != 0 ) ;
int V_177 , V_13 = 0 ;
if ( V_146 ) {
if ( V_87 != 64 || V_86 != 64 )
return - V_186 ;
V_185 = F_80 ( V_38 , V_183 , V_12 ) ;
if ( F_44 ( ! V_185 ) )
return - V_187 ;
V_83 = F_81 ( V_185 ) ;
V_13 = F_82 ( V_83 ) ;
if ( V_13 == 0 ) {
for ( V_177 = 0 ; V_177 < 64 * 64 ; V_177 ++ ) {
T_1 V_188 = F_31 ( V_83 , V_177 ) ;
F_35 ( V_67 -> V_141 . V_83 , V_177 , V_188 ) ;
}
F_83 ( V_83 ) ;
}
F_84 ( V_185 ) ;
}
if ( V_146 != V_67 -> V_141 . V_146 ) {
F_64 ( V_67 , V_146 , true ) ;
V_67 -> V_141 . V_146 = V_146 ;
}
return V_13 ;
}
static int
F_85 ( struct V_40 * V_43 , int V_135 , int V_136 )
{
struct V_189 * V_190 = V_189 ( V_43 ) ;
struct V_7 * V_8 = V_7 ( V_190 ) ;
F_25 ( V_8 -> V_15 , 0x0084 , ( V_136 << 16 ) | ( V_135 & 0xffff ) ) ;
F_25 ( V_8 -> V_15 , 0x0080 , 0x00000000 ) ;
return 0 ;
}
static void
F_86 ( struct V_40 * V_43 , T_5 * V_178 , T_5 * V_179 , T_5 * V_180 ,
T_6 V_191 , T_6 V_6 )
{
struct V_66 * V_67 = V_66 ( V_43 ) ;
T_1 V_192 = F_87 ( V_191 + V_6 , ( T_1 ) 256 ) ;
T_1 V_177 ;
for ( V_177 = V_191 ; V_177 < V_192 ; V_177 ++ ) {
V_67 -> V_145 . V_178 [ V_177 ] = V_178 [ V_177 ] ;
V_67 -> V_145 . V_179 [ V_177 ] = V_179 [ V_177 ] ;
V_67 -> V_145 . V_180 [ V_177 ] = V_180 [ V_177 ] ;
}
F_76 ( V_43 ) ;
}
static void
F_88 ( struct V_40 * V_43 )
{
struct V_66 * V_67 = V_66 ( V_43 ) ;
struct V_36 * V_51 = V_36 ( V_43 -> V_38 ) ;
struct V_193 * V_4 = V_193 ( V_43 ) ;
F_10 ( V_51 -> V_2 , & V_4 -> V_194 . V_18 ) ;
F_8 ( V_51 -> V_2 , & V_4 -> V_195 . V_18 ) ;
F_10 ( V_51 -> V_2 , & V_4 -> V_54 . V_18 ) ;
F_8 ( V_51 -> V_2 , & V_4 -> V_190 . V_18 ) ;
F_83 ( V_67 -> V_141 . V_83 ) ;
if ( V_67 -> V_141 . V_83 )
F_71 ( V_67 -> V_141 . V_83 ) ;
F_89 ( NULL , & V_67 -> V_141 . V_83 ) ;
F_83 ( V_67 -> V_145 . V_83 ) ;
if ( V_67 -> V_145 . V_83 )
F_71 ( V_67 -> V_145 . V_83 ) ;
F_89 ( NULL , & V_67 -> V_145 . V_83 ) ;
F_90 ( V_43 ) ;
F_91 ( V_43 ) ;
}
static void
F_92 ( struct V_66 * V_67 , int V_135 , int V_136 )
{
}
static void
F_93 ( struct V_66 * V_67 , T_6 V_85 )
{
}
static int
F_94 ( struct V_37 * V_38 , struct V_1 * V_2 , int V_68 )
{
struct V_36 * V_51 = V_36 ( V_38 ) ;
struct V_193 * V_4 ;
struct V_40 * V_43 ;
int V_13 , V_177 ;
V_4 = F_95 ( sizeof( * V_4 ) , V_196 ) ;
if ( ! V_4 )
return - V_32 ;
V_4 -> V_18 . V_68 = V_68 ;
V_4 -> V_18 . V_197 = F_55 ;
V_4 -> V_18 . V_198 = F_57 ;
V_4 -> V_18 . V_199 = F_60 ;
V_4 -> V_18 . V_133 = 50 ;
V_4 -> V_18 . V_134 = 0 ;
V_4 -> V_18 . V_141 . V_200 = F_93 ;
V_4 -> V_18 . V_141 . V_201 = F_92 ;
for ( V_177 = 0 ; V_177 < 256 ; V_177 ++ ) {
V_4 -> V_18 . V_145 . V_178 [ V_177 ] = V_177 << 8 ;
V_4 -> V_18 . V_145 . V_179 [ V_177 ] = V_177 << 8 ;
V_4 -> V_18 . V_145 . V_180 [ V_177 ] = V_177 << 8 ;
}
V_43 = & V_4 -> V_18 . V_18 ;
F_96 ( V_38 , V_43 , & V_202 ) ;
F_97 ( V_43 , & V_203 ) ;
F_98 ( V_43 , 256 ) ;
V_13 = F_99 ( V_38 , 8192 , 0x100 , V_149 ,
0 , 0x0000 , NULL , & V_4 -> V_18 . V_145 . V_83 ) ;
if ( ! V_13 ) {
V_13 = F_70 ( V_4 -> V_18 . V_145 . V_83 , V_149 ) ;
if ( ! V_13 ) {
V_13 = F_82 ( V_4 -> V_18 . V_145 . V_83 ) ;
if ( V_13 )
F_71 ( V_4 -> V_18 . V_145 . V_83 ) ;
}
if ( V_13 )
F_89 ( NULL , & V_4 -> V_18 . V_145 . V_83 ) ;
}
if ( V_13 )
goto V_204;
F_76 ( V_43 ) ;
V_13 = F_9 (disp->core, NV50_DISP_CURS_CLASS, index,
&(struct nv50_display_curs_class) {
.head = index,
}, sizeof(struct nv50_display_curs_class),
&head->curs.base) ;
if ( V_13 )
goto V_204;
V_13 = F_99 ( V_38 , 64 * 64 * 4 , 0x100 , V_149 ,
0 , 0x0000 , NULL , & V_4 -> V_18 . V_141 . V_83 ) ;
if ( ! V_13 ) {
V_13 = F_70 ( V_4 -> V_18 . V_141 . V_83 , V_149 ) ;
if ( ! V_13 ) {
V_13 = F_82 ( V_4 -> V_18 . V_141 . V_83 ) ;
if ( V_13 )
F_71 ( V_4 -> V_18 . V_145 . V_83 ) ;
}
if ( V_13 )
F_89 ( NULL , & V_4 -> V_18 . V_141 . V_83 ) ;
}
if ( V_13 )
goto V_204;
V_13 = F_16 (disp->core, NV50_DISP_SYNC_CLASS, index,
&(struct nv50_display_sync_class) {
.pushbuf = EVO_PUSH_HANDLE(SYNC, index),
.head = index,
}, sizeof(struct nv50_display_sync_class),
disp->sync->bo.offset, &head->sync.base) ;
if ( V_13 )
goto V_204;
V_4 -> V_54 . V_59 = F_100 ( V_68 ) ;
V_4 -> V_54 . V_5 = 0x00000000 ;
V_13 = F_9 (disp->core, NV50_DISP_OIMM_CLASS, index,
&(struct nv50_display_oimm_class) {
.head = index,
}, sizeof(struct nv50_display_oimm_class),
&head->oimm.base) ;
if ( V_13 )
goto V_204;
V_13 = F_16 (disp->core, NV50_DISP_OVLY_CLASS, index,
&(struct nv50_display_ovly_class) {
.pushbuf = EVO_PUSH_HANDLE(OVLY, index),
.head = index,
}, sizeof(struct nv50_display_ovly_class),
disp->sync->bo.offset, &head->ovly.base) ;
if ( V_13 )
goto V_204;
V_204:
if ( V_13 )
F_88 ( V_43 ) ;
return V_13 ;
}
static void
F_101 ( struct V_41 * V_42 , int V_95 )
{
struct F_21 * V_205 = F_21 ( V_42 ) ;
struct V_36 * V_51 = V_36 ( V_42 -> V_38 ) ;
int V_206 = V_205 -> V_206 ;
T_1 V_207 ;
V_207 = 0x00000000 ;
if ( V_95 == V_208 || V_95 == V_209 )
V_207 |= 0x00000001 ;
if ( V_95 == V_210 || V_95 == V_209 )
V_207 |= 0x00000004 ;
F_102 ( V_51 -> V_2 , V_211 + V_206 , V_207 ) ;
}
static bool
F_103 ( struct V_41 * V_42 ,
const struct V_107 * V_95 ,
struct V_107 * V_147 )
{
struct F_21 * V_205 = F_21 ( V_42 ) ;
struct V_91 * V_92 ;
V_92 = F_104 ( V_205 ) ;
if ( V_92 && V_92 -> V_113 ) {
if ( V_92 -> V_114 != V_110 ) {
int V_212 = V_147 -> V_18 . V_212 ;
* V_147 = * V_92 -> V_113 ;
V_147 -> V_18 . V_212 = V_212 ;
}
}
return true ;
}
static void
F_105 ( struct V_41 * V_42 )
{
}
static void
F_106 ( struct V_41 * V_42 , struct V_107 * V_95 ,
struct V_107 * V_147 )
{
struct V_52 * V_53 = V_52 ( V_42 -> V_38 ) ;
struct F_21 * V_205 = F_21 ( V_42 ) ;
struct V_66 * V_67 = V_66 ( V_42 -> V_43 ) ;
T_1 * V_47 ;
F_101 ( V_42 , V_213 ) ;
V_47 = F_22 ( V_53 , 8 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_105 ) {
T_1 V_214 = 0x00000000 ;
if ( V_95 -> V_117 & V_215 )
V_214 |= 0x00000001 ;
if ( V_95 -> V_117 & V_216 )
V_214 |= 0x00000002 ;
F_36 ( V_47 , 0x0400 + ( V_205 -> V_206 * 0x080 ) , 2 ) ;
F_37 ( V_47 , 1 << V_67 -> V_68 ) ;
F_37 ( V_47 , V_214 ) ;
} else {
T_1 V_217 = 0x31ec6000 | ( V_67 -> V_68 << 25 ) ;
T_1 V_214 = 0x00000001 ;
if ( V_95 -> V_117 & V_215 )
V_214 |= 0x00000008 ;
if ( V_95 -> V_117 & V_216 )
V_214 |= 0x00000010 ;
if ( V_95 -> V_117 & V_151 )
V_217 |= 0x00000001 ;
F_36 ( V_47 , 0x0404 + ( V_67 -> V_68 * 0x300 ) , 2 ) ;
F_37 ( V_47 , V_214 ) ;
F_37 ( V_47 , V_217 ) ;
F_36 ( V_47 , 0x0180 + ( V_205 -> V_206 * 0x020 ) , 1 ) ;
F_37 ( V_47 , 1 << V_67 -> V_68 ) ;
}
F_29 ( V_47 , V_53 ) ;
}
V_205 -> V_43 = V_42 -> V_43 ;
}
static void
F_107 ( struct V_41 * V_42 )
{
struct F_21 * V_205 = F_21 ( V_42 ) ;
struct V_52 * V_53 = V_52 ( V_42 -> V_38 ) ;
const int V_206 = V_205 -> V_206 ;
T_1 * V_47 ;
if ( V_205 -> V_43 ) {
F_66 ( V_205 -> V_43 ) ;
V_47 = F_22 ( V_53 , 4 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_105 ) {
F_36 ( V_47 , 0x0400 + ( V_206 * 0x080 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
} else {
F_36 ( V_47 , 0x0180 + ( V_206 * 0x020 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
}
F_29 ( V_47 , V_53 ) ;
}
}
V_205 -> V_43 = NULL ;
}
static enum V_218
F_108 ( struct V_41 * V_42 , struct V_93 * V_94 )
{
struct V_36 * V_51 = V_36 ( V_42 -> V_38 ) ;
int V_13 , V_206 = F_21 ( V_42 ) -> V_206 ;
T_1 V_219 = 0 ;
V_13 = F_109 ( V_51 -> V_2 , V_220 + V_206 , & V_219 , sizeof( V_219 ) ) ;
if ( V_13 || V_219 != 7 )
return V_221 ;
return V_222 ;
}
static void
F_110 ( struct V_41 * V_42 )
{
F_111 ( V_42 ) ;
F_91 ( V_42 ) ;
}
static int
F_112 ( struct V_93 * V_94 , struct V_223 * V_224 )
{
struct V_173 * V_174 = V_173 ( V_94 -> V_38 ) ;
struct V_225 * V_226 = V_225 ( V_174 -> V_50 ) ;
struct F_21 * V_205 ;
struct V_41 * V_42 ;
int type = V_227 ;
V_205 = F_95 ( sizeof( * V_205 ) , V_196 ) ;
if ( ! V_205 )
return - V_32 ;
V_205 -> V_228 = V_224 ;
V_205 -> V_206 = F_113 ( V_224 -> V_206 ) - 1 ;
V_205 -> V_226 = V_226 -> V_229 ( V_226 , V_224 -> V_230 ) ;
V_42 = F_114 ( V_205 ) ;
V_42 -> V_231 = V_224 -> V_232 ;
V_42 -> V_233 = 0 ;
F_115 ( V_94 -> V_38 , V_42 , & V_234 , type ) ;
F_116 ( V_42 , & V_235 ) ;
F_117 ( V_94 , V_42 ) ;
return 0 ;
}
static void
F_118 ( struct V_41 * V_42 , struct V_107 * V_95 )
{
struct F_21 * V_205 = F_21 ( V_42 ) ;
struct V_91 * V_92 ;
struct V_36 * V_51 = V_36 ( V_42 -> V_38 ) ;
V_92 = F_104 ( V_205 ) ;
if ( ! F_119 ( V_92 -> V_122 ) )
return;
F_120 ( & V_92 -> V_18 , V_92 -> V_122 ) ;
F_109 ( V_51 -> V_2 , V_236 + V_205 -> V_206 ,
V_92 -> V_18 . V_237 ,
V_92 -> V_18 . V_237 [ 2 ] * 4 ) ;
}
static void
F_121 ( struct V_41 * V_42 )
{
struct F_21 * V_205 = F_21 ( V_42 ) ;
struct V_36 * V_51 = V_36 ( V_42 -> V_38 ) ;
F_109 ( V_51 -> V_2 , V_236 + V_205 -> V_206 , NULL , 0 ) ;
}
static void
F_122 ( struct V_41 * V_42 , struct V_107 * V_95 )
{
struct F_21 * V_205 = F_21 ( V_42 ) ;
struct V_66 * V_67 = V_66 ( V_42 -> V_43 ) ;
struct V_91 * V_92 ;
struct V_36 * V_51 = V_36 ( V_42 -> V_38 ) ;
const T_1 V_238 = ( V_67 -> V_68 << 3 ) | V_205 -> V_206 ;
T_1 V_239 = 56 ;
T_1 V_240 ;
V_92 = F_104 ( V_205 ) ;
if ( ! F_58 ( V_92 -> V_122 ) )
return;
V_240 = V_95 -> V_167 - V_95 -> V_115 ;
V_240 -= V_239 ;
V_240 -= 18 ;
V_240 /= 32 ;
F_102 ( V_51 -> V_2 , V_241 + V_238 ,
V_242 |
( V_240 << 16 ) | V_239 ) ;
F_118 ( V_42 , V_95 ) ;
}
static void
F_123 ( struct V_41 * V_42 )
{
struct F_21 * V_205 = F_21 ( V_42 ) ;
struct V_66 * V_67 = V_66 ( V_205 -> V_43 ) ;
struct V_36 * V_51 = V_36 ( V_42 -> V_38 ) ;
const T_1 V_238 = ( V_67 -> V_68 << 3 ) | V_205 -> V_206 ;
F_121 ( V_42 ) ;
F_102 ( V_51 -> V_2 , V_241 + V_238 , 0x00000000 ) ;
}
static void
F_124 ( struct V_41 * V_42 , int V_95 )
{
struct F_21 * V_205 = F_21 ( V_42 ) ;
struct V_37 * V_38 = V_42 -> V_38 ;
struct V_36 * V_51 = V_36 ( V_38 ) ;
struct V_41 * V_243 ;
int V_206 = V_205 -> V_206 ;
V_205 -> V_244 = V_95 ;
F_125 (partner, &dev->mode_config.encoder_list, head) {
struct F_21 * V_245 = F_21 ( V_243 ) ;
if ( V_243 -> V_246 != V_247 )
continue;
if ( V_245 != V_205 &&
V_245 -> V_228 -> V_206 == V_205 -> V_228 -> V_206 ) {
if ( V_245 -> V_244 == V_213 )
return;
break;
}
}
F_102 ( V_51 -> V_2 , V_248 + V_206 , ( V_95 == V_213 ) ) ;
}
static bool
F_126 ( struct V_41 * V_42 ,
const struct V_107 * V_95 ,
struct V_107 * V_147 )
{
struct F_21 * V_205 = F_21 ( V_42 ) ;
struct V_91 * V_92 ;
V_92 = F_104 ( V_205 ) ;
if ( V_92 && V_92 -> V_113 ) {
if ( V_92 -> V_114 != V_110 ) {
int V_212 = V_147 -> V_18 . V_212 ;
* V_147 = * V_92 -> V_113 ;
V_147 -> V_18 . V_212 = V_212 ;
}
}
return true ;
}
static void
F_127 ( struct V_41 * V_42 )
{
struct F_21 * V_205 = F_21 ( V_42 ) ;
struct V_52 * V_53 = V_52 ( V_42 -> V_38 ) ;
const int V_206 = V_205 -> V_206 ;
T_1 * V_47 ;
if ( V_205 -> V_43 ) {
F_66 ( V_205 -> V_43 ) ;
V_47 = F_22 ( V_53 , 4 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_105 ) {
F_36 ( V_47 , 0x0600 + ( V_206 * 0x40 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
} else {
F_36 ( V_47 , 0x0200 + ( V_206 * 0x20 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
}
F_29 ( V_47 , V_53 ) ;
}
F_123 ( V_42 ) ;
}
V_205 -> V_244 = V_209 ;
V_205 -> V_43 = NULL ;
}
static void
F_128 ( struct V_41 * V_42 )
{
}
static void
F_129 ( struct V_41 * V_42 , struct V_107 * V_109 ,
struct V_107 * V_95 )
{
struct V_36 * V_51 = V_36 ( V_42 -> V_38 ) ;
struct V_52 * V_53 = V_52 ( V_42 -> V_38 ) ;
struct V_37 * V_38 = V_42 -> V_38 ;
struct V_173 * V_174 = V_173 ( V_38 ) ;
struct F_21 * V_205 = F_21 ( V_42 ) ;
struct V_66 * V_67 = V_66 ( V_42 -> V_43 ) ;
struct V_91 * V_92 ;
struct V_249 * V_250 = & V_174 -> V_251 ;
T_1 * V_47 , V_252 = 0 ;
T_2 V_253 = 1 << V_67 -> V_68 ;
T_2 V_254 = 0xf ;
T_2 V_98 = 0x0 ;
V_92 = F_104 ( V_205 ) ;
switch ( V_205 -> V_228 -> type ) {
case V_255 :
if ( V_205 -> V_228 -> V_256 . V_257 & 1 ) {
if ( V_95 -> clock < 165000 )
V_254 = 0x1 ;
else
V_254 = 0x5 ;
} else {
V_254 = 0x2 ;
}
F_122 ( V_42 , V_95 ) ;
break;
case V_258 :
V_254 = 0x0 ;
if ( V_250 -> V_259 ) {
if ( V_250 -> V_260 . V_261 )
V_252 |= 0x0100 ;
if ( V_250 -> V_260 . V_262 )
V_252 |= 0x0200 ;
} else {
if ( V_92 -> type == V_263 ) {
if ( ( ( T_2 * ) V_92 -> V_122 ) [ 121 ] == 2 )
V_252 |= 0x0100 ;
} else
if ( V_95 -> clock >= V_250 -> V_260 . V_264 ) {
V_252 |= 0x0100 ;
}
if ( V_252 & 0x0100 ) {
if ( V_250 -> V_260 . V_265 & 2 )
V_252 |= 0x0200 ;
} else {
if ( V_250 -> V_260 . V_265 & 1 )
V_252 |= 0x0200 ;
}
if ( V_92 -> V_18 . V_99 . V_100 == 8 )
V_252 |= 0x0200 ;
}
F_102 ( V_51 -> V_2 , V_266 + V_205 -> V_206 , V_252 ) ;
break;
case V_267 :
if ( V_92 -> V_18 . V_99 . V_100 == 6 ) {
V_205 -> V_268 . V_269 = V_95 -> clock * 18 / 8 ;
V_98 = 0x2 ;
} else
if ( V_92 -> V_18 . V_99 . V_100 == 8 ) {
V_205 -> V_268 . V_269 = V_95 -> clock * 24 / 8 ;
V_98 = 0x5 ;
} else {
V_205 -> V_268 . V_269 = V_95 -> clock * 30 / 8 ;
V_98 = 0x6 ;
}
if ( V_205 -> V_228 -> V_256 . V_257 & 1 )
V_254 = 0x8 ;
else
V_254 = 0x9 ;
break;
default:
F_130 ( 1 ) ;
break;
}
F_124 ( V_42 , V_213 ) ;
V_47 = F_22 ( V_52 ( V_38 ) , 8 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_181 ) {
T_1 V_270 = ( V_98 << 16 ) | ( V_254 << 8 ) | V_253 ;
if ( V_95 -> V_117 & V_215 )
V_270 |= 0x00001000 ;
if ( V_95 -> V_117 & V_216 )
V_270 |= 0x00002000 ;
F_36 ( V_47 , 0x0600 + ( V_205 -> V_206 * 0x040 ) , 1 ) ;
F_37 ( V_47 , V_270 ) ;
} else {
T_1 V_217 = 0x31ec6000 | ( V_67 -> V_68 << 25 ) ;
T_1 V_214 = 0x00000001 ;
if ( V_95 -> V_117 & V_215 )
V_214 |= 0x00000008 ;
if ( V_95 -> V_117 & V_216 )
V_214 |= 0x00000010 ;
if ( V_95 -> V_117 & V_151 )
V_217 |= 0x00000001 ;
F_36 ( V_47 , 0x0404 + ( V_67 -> V_68 * 0x300 ) , 2 ) ;
F_37 ( V_47 , V_214 | ( V_98 << 6 ) ) ;
F_37 ( V_47 , V_217 ) ;
F_36 ( V_47 , 0x0200 + ( V_205 -> V_206 * 0x020 ) , 1 ) ;
F_37 ( V_47 , V_253 | ( V_254 << 8 ) ) ;
}
F_29 ( V_47 , V_53 ) ;
}
V_205 -> V_43 = V_42 -> V_43 ;
}
static void
F_131 ( struct V_41 * V_42 )
{
F_111 ( V_42 ) ;
F_91 ( V_42 ) ;
}
static int
F_132 ( struct V_93 * V_94 , struct V_223 * V_224 )
{
struct V_173 * V_174 = V_173 ( V_94 -> V_38 ) ;
struct V_225 * V_226 = V_225 ( V_174 -> V_50 ) ;
struct F_21 * V_205 ;
struct V_41 * V_42 ;
int type ;
switch ( V_224 -> type ) {
case V_258 : type = V_271 ; break;
case V_255 :
case V_267 :
default:
type = V_247 ;
break;
}
V_205 = F_95 ( sizeof( * V_205 ) , V_196 ) ;
if ( ! V_205 )
return - V_32 ;
V_205 -> V_228 = V_224 ;
V_205 -> V_206 = F_113 ( V_224 -> V_206 ) - 1 ;
V_205 -> V_226 = V_226 -> V_229 ( V_226 , V_224 -> V_230 ) ;
V_205 -> V_244 = V_209 ;
V_42 = F_114 ( V_205 ) ;
V_42 -> V_231 = V_224 -> V_232 ;
V_42 -> V_233 = 0 ;
F_115 ( V_94 -> V_38 , V_42 , & V_272 , type ) ;
F_116 ( V_42 , & V_273 ) ;
F_117 ( V_94 , V_42 ) ;
return 0 ;
}
static void
F_133 ( struct V_41 * V_42 , int V_95 )
{
struct F_21 * V_205 = F_21 ( V_42 ) ;
struct V_36 * V_51 = V_36 ( V_42 -> V_38 ) ;
T_1 V_274 = ( V_205 -> V_228 -> type << 12 ) | V_205 -> V_206 ;
T_1 V_270 = ( V_95 == V_213 ) ;
F_102 ( V_51 -> V_2 , V_275 + V_274 , V_270 ) ;
}
static bool
F_134 ( struct V_41 * V_42 ,
const struct V_107 * V_95 ,
struct V_107 * V_147 )
{
struct F_21 * V_205 = F_21 ( V_42 ) ;
struct V_91 * V_92 ;
V_92 = F_104 ( V_205 ) ;
if ( V_92 && V_92 -> V_113 ) {
if ( V_92 -> V_114 != V_110 ) {
int V_212 = V_147 -> V_18 . V_212 ;
* V_147 = * V_92 -> V_113 ;
V_147 -> V_18 . V_212 = V_212 ;
}
}
V_147 -> clock *= 2 ;
return true ;
}
static void
F_135 ( struct V_41 * V_42 )
{
}
static void
F_136 ( struct V_41 * V_42 , struct V_107 * V_95 ,
struct V_107 * V_147 )
{
struct V_52 * V_53 = V_52 ( V_42 -> V_38 ) ;
struct F_21 * V_205 = F_21 ( V_42 ) ;
struct V_66 * V_67 = V_66 ( V_42 -> V_43 ) ;
struct V_91 * V_92 ;
T_2 V_253 = 1 << V_67 -> V_68 ;
T_2 V_254 , V_98 ;
T_1 * V_47 ;
V_92 = F_104 ( V_205 ) ;
switch ( V_92 -> V_18 . V_99 . V_100 ) {
case 10 : V_98 = 0x6 ; break;
case 8 : V_98 = 0x5 ; break;
case 6 : V_98 = 0x2 ; break;
default: V_98 = 0x0 ; break;
}
switch ( V_205 -> V_228 -> type ) {
case V_255 :
case V_267 :
V_254 = 0x0 ;
break;
default:
F_130 ( 1 ) ;
break;
}
F_133 ( V_42 , V_213 ) ;
V_47 = F_22 ( V_53 , 8 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_105 ) {
T_1 V_270 = ( V_98 << 16 ) | ( V_254 << 8 ) | V_253 ;
if ( V_95 -> V_117 & V_215 )
V_270 |= 0x00001000 ;
if ( V_95 -> V_117 & V_216 )
V_270 |= 0x00002000 ;
F_36 ( V_47 , 0x0700 + ( V_205 -> V_206 * 0x040 ) , 1 ) ;
F_37 ( V_47 , V_270 ) ;
}
F_29 ( V_47 , V_53 ) ;
}
V_205 -> V_43 = V_42 -> V_43 ;
}
static void
F_137 ( struct V_41 * V_42 )
{
struct F_21 * V_205 = F_21 ( V_42 ) ;
struct V_52 * V_53 = V_52 ( V_42 -> V_38 ) ;
const int V_206 = V_205 -> V_206 ;
T_1 * V_47 ;
if ( V_205 -> V_43 ) {
F_66 ( V_205 -> V_43 ) ;
V_47 = F_22 ( V_53 , 4 ) ;
if ( V_47 ) {
if ( F_54 ( V_53 ) < V_105 ) {
F_36 ( V_47 , 0x0700 + ( V_206 * 0x040 ) , 1 ) ;
F_37 ( V_47 , 0x00000000 ) ;
}
F_29 ( V_47 , V_53 ) ;
}
}
V_205 -> V_43 = NULL ;
}
static void
F_138 ( struct V_41 * V_42 )
{
F_111 ( V_42 ) ;
F_91 ( V_42 ) ;
}
static int
F_139 ( struct V_93 * V_94 , struct V_223 * V_224 )
{
struct V_173 * V_174 = V_173 ( V_94 -> V_38 ) ;
struct V_225 * V_226 = V_225 ( V_174 -> V_50 ) ;
struct V_276 * V_277 = NULL ;
struct F_21 * V_205 ;
struct V_41 * V_42 ;
int type ;
switch ( V_224 -> type ) {
case V_255 :
V_277 = V_226 -> V_278 ( V_226 , F_140 ( V_224 -> V_279 ) ) ;
type = V_247 ;
break;
case V_267 :
V_277 = V_226 -> V_278 ( V_226 , F_141 ( V_224 -> V_279 ) ) ;
type = V_247 ;
break;
default:
return - V_280 ;
}
V_205 = F_95 ( sizeof( * V_205 ) , V_196 ) ;
if ( ! V_205 )
return - V_32 ;
V_205 -> V_228 = V_224 ;
V_205 -> V_206 = F_113 ( V_224 -> V_206 ) - 1 ;
V_205 -> V_226 = V_277 ;
V_42 = F_114 ( V_205 ) ;
V_42 -> V_231 = V_224 -> V_232 ;
V_42 -> V_233 = 0 ;
F_115 ( V_94 -> V_38 , V_42 , & V_281 , type ) ;
F_116 ( V_42 , & V_282 ) ;
F_117 ( V_94 , V_42 ) ;
return 0 ;
}
void
F_142 ( struct V_37 * V_38 )
{
}
int
F_143 ( struct V_37 * V_38 )
{
struct V_36 * V_51 = V_36 ( V_38 ) ;
struct V_40 * V_43 ;
T_1 * V_47 ;
V_47 = F_22 ( V_52 ( V_38 ) , 32 ) ;
if ( ! V_47 )
return - V_55 ;
F_125 (crtc, &dev->mode_config.crtc_list, head) {
struct F_42 * V_54 = F_42 ( V_43 ) ;
F_35 ( V_51 -> V_54 , V_54 -> V_59 / 4 , V_54 -> V_5 ) ;
}
F_36 ( V_47 , 0x0088 , 1 ) ;
F_37 ( V_47 , V_80 ) ;
F_29 ( V_47 , V_52 ( V_38 ) ) ;
return 0 ;
}
void
F_144 ( struct V_37 * V_38 )
{
struct V_36 * V_51 = V_36 ( V_38 ) ;
F_10 ( V_51 -> V_2 , & V_51 -> V_53 . V_18 ) ;
F_83 ( V_51 -> V_54 ) ;
if ( V_51 -> V_54 )
F_71 ( V_51 -> V_54 ) ;
F_89 ( NULL , & V_51 -> V_54 ) ;
F_19 ( V_38 ) -> V_39 = NULL ;
F_91 ( V_51 ) ;
}
int
F_145 ( struct V_37 * V_38 )
{
static const T_5 V_11 [] = {
V_283 ,
V_181 ,
V_284 ,
V_285 ,
V_286 ,
V_287 ,
V_288 ,
} ;
struct V_49 * V_50 = F_34 ( V_38 ) ;
struct V_173 * V_174 = V_173 ( V_38 ) ;
struct V_289 * V_228 = & V_174 -> V_251 . V_228 ;
struct V_93 * V_94 , * V_290 ;
struct V_36 * V_51 ;
struct V_223 * V_224 ;
int V_291 , V_13 , V_177 ;
V_51 = F_95 ( sizeof( * V_51 ) , V_196 ) ;
if ( ! V_51 )
return - V_32 ;
F_19 ( V_38 ) -> V_39 = V_51 ;
F_19 ( V_38 ) -> V_292 = F_144 ;
F_19 ( V_38 ) -> V_293 = F_143 ;
F_19 ( V_38 ) -> V_294 = F_142 ;
V_13 = F_99 ( V_38 , 4096 , 0x1000 , V_149 ,
0 , 0x0000 , NULL , & V_51 -> V_54 ) ;
if ( ! V_13 ) {
V_13 = F_70 ( V_51 -> V_54 , V_149 ) ;
if ( ! V_13 ) {
V_13 = F_82 ( V_51 -> V_54 ) ;
if ( V_13 )
F_71 ( V_51 -> V_54 ) ;
}
if ( V_13 )
F_89 ( NULL , & V_51 -> V_54 ) ;
}
if ( V_13 )
goto V_204;
V_13 = - V_280 ;
for ( V_177 = 0 ; V_13 && V_177 < F_146 ( V_11 ) ; V_177 ++ ) {
V_13 = F_5 ( F_147 ( V_174 ) , V_295 ,
0xd1500000 , V_11 [ V_177 ] , NULL , 0 ,
& V_51 -> V_2 ) ;
}
if ( V_13 )
goto V_204;
V_13 = F_16 (disp->core, NV50_DISP_MAST_CLASS, 0 ,
&(struct nv50_display_mast_class) {
.pushbuf = EVO_PUSH_HANDLE(MAST, 0),
}, sizeof(struct nv50_display_mast_class),
disp->sync->bo.offset, &disp->mast.base) ;
if ( V_13 )
goto V_204;
if ( F_45 ( V_51 -> V_2 ) >= V_181 )
V_291 = F_148 ( V_50 , 0x022448 ) ;
else
V_291 = 2 ;
for ( V_177 = 0 ; V_177 < V_291 ; V_177 ++ ) {
V_13 = F_94 ( V_38 , V_51 -> V_2 , V_177 ) ;
if ( V_13 )
goto V_204;
}
for ( V_177 = 0 , V_224 = & V_228 -> V_296 [ 0 ] ; V_177 < V_228 -> V_297 ; V_177 ++ , V_224 ++ ) {
V_94 = F_149 ( V_38 , V_224 -> V_94 ) ;
if ( F_150 ( V_94 ) )
continue;
if ( V_224 -> V_298 == V_299 ) {
switch ( V_224 -> type ) {
case V_255 :
case V_258 :
case V_267 :
V_13 = F_132 ( V_94 , V_224 ) ;
break;
case V_300 :
V_13 = F_112 ( V_94 , V_224 ) ;
break;
default:
V_13 = - V_280 ;
break;
}
} else {
V_13 = F_139 ( V_94 , V_224 ) ;
}
if ( V_13 ) {
F_151 ( V_174 , L_3 ,
V_224 -> V_298 , V_224 -> type ,
F_113 ( V_224 -> V_206 ) - 1 , V_13 ) ;
V_13 = 0 ;
}
}
F_152 (connector, tmp, &dev->mode_config.connector_list, head) {
if ( V_94 -> V_301 [ 0 ] )
continue;
F_151 ( V_174 , L_4 ,
F_153 ( V_94 ) ) ;
V_94 -> V_302 -> V_303 ( V_94 ) ;
}
V_204:
if ( V_13 )
F_144 ( V_38 ) ;
return V_13 ;
}

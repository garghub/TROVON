static T_1
F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = ( T_1 ) F_2 ( V_2 -> V_4 ) << 32 ;
V_3 |= V_2 -> V_4 -> V_5 << 16 ;
V_3 |= F_3 ( V_2 -> V_6 ) << 8 ;
return V_3 | F_4 ( V_2 -> V_6 ) ;
}
static int
F_5 ( struct V_1 * V_2 , const char * V_3 ,
int V_7 , void * * V_8 )
{
struct V_9 * V_10 ;
int V_11 ;
* V_8 = NULL ;
V_11 = F_6 ( V_3 , F_1 ( V_2 ) , V_12 ,
V_13 , V_7 , V_8 ) ;
V_10 = * V_8 ;
if ( V_11 ) {
if ( V_10 )
F_7 ( & V_10 -> V_14 ) ;
* V_8 = NULL ;
return V_11 ;
}
F_8 ( & V_10 -> V_15 ) ;
return 0 ;
}
static void
F_9 ( struct V_9 * V_10 )
{
struct V_16 * V_17 = F_10 ( V_10 ) ;
F_11 ( NULL , & V_10 -> V_14 . V_18 , NULL ) ;
F_12 ( & V_10 -> V_14 , false ) ;
F_13 ( & V_17 -> V_19 , 1 ) ;
F_14 ( NULL , & V_17 ) ;
}
static void
F_15 ( struct V_20 * V_21 )
{
F_16 ( NULL , & V_21 -> V_22 ) ;
F_17 ( & V_21 -> V_23 ) ;
F_17 ( & V_21 -> V_24 ) ;
if ( V_21 -> V_25 )
F_18 ( V_21 ) -> F_19 ( V_21 ) ;
}
static void
F_20 ( struct V_20 * V_21 )
{
struct V_26 * V_27 = F_21 ( V_21 -> V_27 ) ;
struct V_16 * V_28 ;
T_2 V_29 , V_30 ;
int V_11 ;
if ( V_31 || ! F_22 ( V_27 ) )
return;
if ( V_27 -> V_32 < V_33 ) V_11 = F_23 ( V_21 ) ;
else if ( V_27 -> V_32 < V_34 ||
V_27 -> V_35 < 0x17 ) V_11 = F_24 ( V_21 ) ;
else if ( V_27 -> V_32 < V_36 ) V_11 = F_25 ( V_21 ) ;
else if ( V_27 -> V_35 < 0x84 ) V_11 = F_26 ( V_21 ) ;
else if ( V_27 -> V_32 < V_37 ) V_11 = F_27 ( V_21 ) ;
else V_11 = F_28 ( V_21 ) ;
if ( V_11 ) {
F_29 ( V_21 , L_1 , V_11 ) ;
F_15 ( V_21 ) ;
return;
}
if ( V_27 -> V_32 >= V_38 ) {
V_11 = F_30 ( V_21 , & V_21 -> V_17 , V_39 ,
V_40 + 1 ,
V_41 |
V_42 , 0 ,
& V_21 -> V_24 ) ;
if ( V_11 )
F_29 ( V_21 , L_2 , V_11 ) ;
V_29 = V_43 ;
V_30 = 1 ;
} else
if ( V_27 -> V_35 >= 0xa3 &&
V_27 -> V_35 != 0xaa &&
V_27 -> V_35 != 0xac ) {
V_11 = F_30 ( V_21 , & V_21 -> V_17 , V_39 ,
V_40 + 1 , V_44 , V_45 ,
& V_21 -> V_24 ) ;
if ( V_11 )
F_29 ( V_21 , L_2 , V_11 ) ;
V_29 = V_44 ;
V_30 = V_45 ;
} else {
V_29 = V_44 ;
V_30 = V_45 ;
}
V_11 = F_30 ( V_21 , & V_21 -> V_17 , V_39 , V_40 ,
V_29 , V_30 , & V_21 -> V_23 ) ;
if ( V_11 ) {
F_29 ( V_21 , L_3 , V_11 ) ;
F_15 ( V_21 ) ;
return;
}
V_11 = F_31 ( F_10 ( V_21 ) , V_40 , V_46 ,
F_32 ( V_21 ) , NULL , 0 , & V_28 ) ;
if ( V_11 == 0 ) {
struct V_47 * V_48 = ( void * ) V_28 -> V_49 ;
V_11 = F_33 ( V_21 -> V_23 , 2 ) ;
if ( V_11 == 0 ) {
if ( V_27 -> V_32 < V_37 ) {
F_34 ( V_21 -> V_23 , V_50 , 0 , 1 ) ;
F_35 ( V_21 -> V_23 , V_46 ) ;
} else
if ( V_27 -> V_32 < V_38 ) {
F_36 ( V_21 -> V_23 , V_51 , 0 , 1 ) ;
F_35 ( V_21 -> V_23 , 0x001f0000 ) ;
}
}
V_48 = ( void * ) V_28 -> V_49 ;
V_48 -> V_52 = V_53 ;
V_48 -> V_54 = V_21 -> V_23 ;
}
if ( V_11 ) {
F_29 ( V_21 , L_4 , V_11 ) ;
F_15 ( V_21 ) ;
return;
}
if ( V_27 -> V_32 < V_37 ) {
V_11 = F_37 ( V_21 -> V_27 , NULL , 32 , 0 , 0 ,
& V_21 -> V_22 ) ;
if ( V_11 ) {
F_29 ( V_21 , L_5 , V_11 ) ;
F_15 ( V_21 ) ;
return;
}
V_11 = F_31 (nv_object(drm),
drm->channel->handle, NvNotify0,
0x003d , &(struct nv_dma_class) {
.flags = NV_DMA_TARGET_VRAM |
NV_DMA_ACCESS_RDWR,
.start = drm->notify->addr,
.limit = drm->notify->addr + 31
}, sizeof(struct nv_dma_class),
&object) ;
if ( V_11 ) {
F_15 ( V_21 ) ;
return;
}
}
F_38 ( V_21 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
const struct V_55 * V_56 )
{
struct V_26 * V_27 ;
struct V_57 * V_58 ;
bool V_59 = false ;
int V_11 ;
V_58 = F_40 ( 3 ) ;
if ( ! V_58 )
return - V_60 ;
V_58 -> V_61 [ 0 ] . V_14 = F_41 ( V_2 , 1 ) ;
V_58 -> V_61 [ 0 ] . V_7 = F_42 ( V_2 , 1 ) ;
V_58 -> V_62 = 1 ;
if ( F_42 ( V_2 , 2 ) ) {
V_58 -> V_61 [ V_58 -> V_62 ] . V_14 = F_41 ( V_2 , 2 ) ;
V_58 -> V_61 [ V_58 -> V_62 ] . V_7 = F_42 ( V_2 , 2 ) ;
V_58 -> V_62 ++ ;
}
if ( F_42 ( V_2 , 3 ) ) {
V_58 -> V_61 [ V_58 -> V_62 ] . V_14 = F_41 ( V_2 , 3 ) ;
V_58 -> V_61 [ V_58 -> V_62 ] . V_7 = F_42 ( V_2 , 3 ) ;
V_58 -> V_62 ++ ;
}
#ifdef F_43
V_59 = V_2 -> V_63 [ V_64 ] . V_65 & V_66 ;
#endif
F_44 ( V_58 , L_6 , V_59 ) ;
F_45 ( V_58 ) ;
V_11 = F_46 ( V_2 , F_1 ( V_2 ) , F_47 ( V_2 ) ,
V_12 , V_13 , & V_27 ) ;
if ( V_11 )
return V_11 ;
F_48 ( V_2 ) ;
V_11 = F_49 ( V_2 , V_56 , & V_67 ) ;
if ( V_11 ) {
F_14 ( NULL , (struct V_16 * * ) & V_27 ) ;
return V_11 ;
}
return 0 ;
}
static void
F_50 ( struct V_68 * V_69 )
{
struct V_20 * V_21 = V_69 -> V_70 ;
struct V_1 * V_2 = V_69 -> V_2 ;
V_21 -> V_71 = F_51 ( ( unsigned int ) V_2 -> V_4 -> V_5 ,
F_52 ( F_3 ( V_2 -> V_6 ) , 1 ) ) ;
if ( ! V_21 -> V_71 ) {
F_53 ( L_7 , V_2 -> V_4 -> V_5 , F_3 ( V_2 -> V_6 ) , 1 ) ;
return;
}
if ( ( V_21 -> V_71 -> V_72 >> 8 ) != V_73 ) {
F_53 ( L_8 , V_21 -> V_71 -> V_72 ) ;
F_54 ( V_21 -> V_71 ) ;
V_21 -> V_71 = NULL ;
return;
}
}
static int
F_55 ( struct V_68 * V_69 , unsigned long V_65 )
{
struct V_1 * V_2 = V_69 -> V_2 ;
struct V_26 * V_27 ;
struct V_20 * V_21 ;
int V_11 ;
V_11 = F_5 ( V_2 , L_9 , sizeof( * V_21 ) , ( void * * ) & V_21 ) ;
if ( V_11 )
return V_11 ;
V_69 -> V_70 = V_21 ;
V_21 -> V_69 = V_69 ;
F_56 ( & V_21 -> V_74 ) ;
F_57 ( & V_21 -> V_75 . V_76 ) ;
F_50 ( V_69 ) ;
if ( F_58 ( V_69 ) && V_69 -> V_77 ) {
V_11 = F_31 (nv_object(drm), NVDRM_CLIENT,
NVDRM_DEVICE, 0x0080 ,
&(struct nv_device_class) {
.device = ~0 ,
.disable =
~(NV_DEVICE_DISABLE_MMIO |
NV_DEVICE_DISABLE_IDENTIFY),
.debug0 = ~0 ,
}, sizeof(struct nv_device_class),
&drm->device) ;
if ( V_11 )
goto V_78;
F_59 ( V_21 ) ;
F_60 ( F_10 ( V_21 ) , V_79 , V_39 ) ;
}
V_11 = F_31 (nv_object(drm), NVDRM_CLIENT, NVDRM_DEVICE,
0x0080 , &(struct nv_device_class) {
.device = ~0 ,
.disable = 0 ,
.debug0 = 0 ,
}, sizeof(struct nv_device_class),
&drm->device) ;
if ( V_11 )
goto V_78;
V_27 = F_21 ( V_21 -> V_27 ) ;
if ( F_21 ( V_21 -> V_27 ) -> V_35 == 0xc1 )
F_61 ( V_27 , 0x00088080 , 0x00000800 , 0x00000000 ) ;
F_62 ( V_21 ) ;
F_63 ( V_21 ) ;
if ( V_27 -> V_32 >= V_36 ) {
V_11 = F_64 ( F_21 ( V_21 -> V_27 ) , 0 , ( 1ULL << 40 ) ,
0x1000 , & V_21 -> V_17 . V_14 . V_18 ) ;
if ( V_11 )
goto V_78;
}
V_11 = F_65 ( V_21 ) ;
if ( V_11 )
goto V_80;
V_11 = F_66 ( V_69 ) ;
if ( V_11 )
goto V_81;
V_11 = F_67 ( V_69 ) ;
if ( V_11 )
goto V_82;
if ( V_69 -> V_83 . V_84 ) {
V_11 = F_68 ( V_69 ) ;
if ( V_11 )
goto V_85;
}
F_69 ( V_69 ) ;
F_70 ( V_69 ) ;
F_20 ( V_21 ) ;
F_71 ( V_69 ) ;
if ( V_86 != 0 ) {
F_72 ( V_69 -> V_69 ) ;
F_73 ( V_69 -> V_69 , 5000 ) ;
F_74 ( V_69 -> V_69 ) ;
F_75 ( V_69 -> V_69 ) ;
F_76 ( V_69 -> V_69 ) ;
F_77 ( V_69 -> V_69 ) ;
}
return 0 ;
V_85:
F_78 ( V_69 ) ;
V_82:
F_79 ( V_69 ) ;
V_81:
F_80 ( V_21 ) ;
V_80:
F_81 ( V_21 ) ;
F_82 ( V_21 ) ;
V_78:
F_9 ( & V_21 -> V_17 ) ;
return V_11 ;
}
static int
F_83 ( struct V_68 * V_69 )
{
struct V_20 * V_21 = V_20 ( V_69 ) ;
F_84 ( V_69 -> V_69 ) ;
F_85 ( V_69 ) ;
F_15 ( V_21 ) ;
F_86 ( V_69 ) ;
F_87 ( V_69 ) ;
if ( V_69 -> V_83 . V_84 )
F_88 ( V_69 ) ;
F_78 ( V_69 ) ;
F_79 ( V_69 ) ;
F_80 ( V_21 ) ;
F_81 ( V_21 ) ;
F_82 ( V_21 ) ;
if ( V_21 -> V_71 )
F_54 ( V_21 -> V_71 ) ;
F_9 ( & V_21 -> V_17 ) ;
return 0 ;
}
static void
F_89 ( struct V_1 * V_2 )
{
struct V_68 * V_69 = F_90 ( V_2 ) ;
struct V_20 * V_21 = V_20 ( V_69 ) ;
struct V_16 * V_27 ;
V_27 = V_21 -> V_17 . V_14 . V_27 ;
F_91 ( V_69 ) ;
F_14 ( NULL , & V_27 ) ;
F_92 () ;
}
static int
F_93 ( struct V_68 * V_69 )
{
struct V_20 * V_21 = V_20 ( V_69 ) ;
struct V_9 * V_10 ;
int V_11 ;
if ( V_69 -> V_83 . V_84 ) {
F_94 ( V_21 , L_10 ) ;
V_11 = F_95 ( V_69 ) ;
if ( V_11 )
return V_11 ;
}
F_94 ( V_21 , L_11 ) ;
F_96 ( & V_21 -> V_87 . V_88 , V_89 ) ;
F_94 ( V_21 , L_12 ) ;
if ( V_21 -> V_24 ) {
V_11 = F_97 ( V_21 -> V_24 ) ;
if ( V_11 )
return V_11 ;
}
if ( V_21 -> V_23 ) {
V_11 = F_97 ( V_21 -> V_23 ) ;
if ( V_11 )
return V_11 ;
}
F_94 ( V_21 , L_13 ) ;
if ( V_21 -> V_25 && F_18 ( V_21 ) -> V_90 ) {
if ( ! F_18 ( V_21 ) -> V_90 ( V_21 ) )
return - V_60 ;
}
F_98 (cli, &drm->clients, head) {
V_11 = F_12 ( & V_10 -> V_14 , true ) ;
if ( V_11 )
goto V_91;
}
F_94 ( V_21 , L_14 ) ;
V_11 = F_12 ( & V_21 -> V_17 . V_14 , true ) ;
if ( V_11 )
goto V_91;
F_81 ( V_21 ) ;
return 0 ;
V_91:
F_99 (cli, &drm->clients, head) {
F_100 ( & V_10 -> V_14 ) ;
}
if ( V_69 -> V_83 . V_84 ) {
F_94 ( V_21 , L_15 ) ;
F_101 ( V_69 ) ;
}
return V_11 ;
}
int F_102 ( struct V_27 * V_69 )
{
struct V_1 * V_2 = F_103 ( V_69 ) ;
struct V_68 * V_92 = F_90 ( V_2 ) ;
int V_11 ;
if ( V_92 -> V_93 == V_94 ||
V_92 -> V_93 == V_95 )
return 0 ;
if ( V_92 -> V_83 . V_84 )
F_104 ( V_92 , 1 ) ;
V_11 = F_93 ( V_92 ) ;
if ( V_11 )
return V_11 ;
F_105 ( V_2 ) ;
F_106 ( V_2 ) ;
F_107 ( V_2 , V_96 ) ;
return 0 ;
}
static int
F_108 ( struct V_68 * V_69 )
{
struct V_20 * V_21 = V_20 ( V_69 ) ;
struct V_9 * V_10 ;
F_94 ( V_21 , L_16 ) ;
F_59 ( V_21 ) ;
F_94 ( V_21 , L_17 ) ;
F_100 ( & V_21 -> V_17 . V_14 ) ;
F_63 ( V_21 ) ;
F_94 ( V_21 , L_18 ) ;
if ( V_21 -> V_25 && F_18 ( V_21 ) -> V_97 )
F_18 ( V_21 ) -> V_97 ( V_21 ) ;
F_98 (cli, &drm->clients, head) {
F_100 ( & V_10 -> V_14 ) ;
}
F_109 ( V_69 ) ;
if ( V_69 -> V_83 . V_84 ) {
F_94 ( V_21 , L_15 ) ;
F_110 ( V_69 ) ;
}
return 0 ;
}
int F_111 ( struct V_27 * V_69 )
{
struct V_1 * V_2 = F_103 ( V_69 ) ;
struct V_68 * V_92 = F_90 ( V_2 ) ;
int V_11 ;
if ( V_92 -> V_93 == V_94 ||
V_92 -> V_93 == V_95 )
return 0 ;
F_107 ( V_2 , V_98 ) ;
F_112 ( V_2 ) ;
V_11 = F_113 ( V_2 ) ;
if ( V_11 )
return V_11 ;
F_48 ( V_2 ) ;
V_11 = F_108 ( V_92 ) ;
if ( V_11 )
return V_11 ;
if ( V_92 -> V_83 . V_84 )
F_104 ( V_92 , 0 ) ;
F_114 ( V_92 ) ;
if ( V_92 -> V_83 . V_84 )
F_101 ( V_92 ) ;
return 0 ;
}
static int F_115 ( struct V_27 * V_69 )
{
struct V_1 * V_2 = F_103 ( V_69 ) ;
struct V_68 * V_92 = F_90 ( V_2 ) ;
int V_11 ;
if ( V_92 -> V_83 . V_84 )
F_104 ( V_92 , 1 ) ;
V_11 = F_93 ( V_92 ) ;
return V_11 ;
}
static int F_116 ( struct V_27 * V_69 )
{
struct V_1 * V_2 = F_103 ( V_69 ) ;
struct V_68 * V_92 = F_90 ( V_2 ) ;
int V_11 ;
V_11 = F_108 ( V_92 ) ;
if ( V_11 )
return V_11 ;
if ( V_92 -> V_83 . V_84 )
F_104 ( V_92 , 0 ) ;
F_114 ( V_92 ) ;
if ( V_92 -> V_83 . V_84 )
F_101 ( V_92 ) ;
return 0 ;
}
static int
F_117 ( struct V_68 * V_69 , struct V_99 * V_100 )
{
struct V_1 * V_2 = V_69 -> V_2 ;
struct V_20 * V_21 = V_20 ( V_69 ) ;
struct V_9 * V_10 ;
char V_3 [ 32 ] , V_101 [ V_102 ] ;
int V_11 ;
V_11 = F_84 ( V_69 -> V_69 ) ;
if ( V_11 < 0 )
return V_11 ;
F_118 ( V_101 , V_103 ) ;
snprintf ( V_3 , sizeof( V_3 ) , L_19 , V_101 , F_119 ( V_100 -> V_104 ) ) ;
V_11 = F_5 ( V_2 , V_3 , sizeof( * V_10 ) , ( void * * ) & V_10 ) ;
if ( V_11 )
goto V_105;
if ( F_21 ( V_21 -> V_27 ) -> V_32 >= V_36 ) {
V_11 = F_64 ( F_21 ( V_21 -> V_27 ) , 0 , ( 1ULL << 40 ) ,
0x1000 , & V_10 -> V_14 . V_18 ) ;
if ( V_11 ) {
F_9 ( V_10 ) ;
goto V_105;
}
}
V_100 -> V_106 = V_10 ;
F_120 ( & V_21 -> V_17 . V_15 ) ;
F_121 ( & V_10 -> V_107 , & V_21 -> V_74 ) ;
F_122 ( & V_21 -> V_17 . V_15 ) ;
V_105:
F_76 ( V_69 -> V_69 ) ;
F_123 ( V_69 -> V_69 ) ;
return V_11 ;
}
static void
F_124 ( struct V_68 * V_69 , struct V_99 * V_100 )
{
struct V_9 * V_10 = V_9 ( V_100 ) ;
struct V_20 * V_21 = V_20 ( V_69 ) ;
F_84 ( V_69 -> V_69 ) ;
if ( V_10 -> V_108 )
F_125 ( V_10 -> V_108 ) ;
F_120 ( & V_21 -> V_17 . V_15 ) ;
F_126 ( & V_10 -> V_107 ) ;
F_122 ( & V_21 -> V_17 . V_15 ) ;
}
static void
F_127 ( struct V_68 * V_69 , struct V_99 * V_100 )
{
struct V_9 * V_10 = V_9 ( V_100 ) ;
F_9 ( V_10 ) ;
F_76 ( V_69 -> V_69 ) ;
F_123 ( V_69 -> V_69 ) ;
}
long F_128 ( struct V_109 * V_110 ,
unsigned int V_111 , unsigned long V_112 )
{
struct V_99 * V_113 = V_110 -> V_114 ;
struct V_68 * V_69 ;
long V_11 ;
V_69 = V_113 -> V_115 -> V_69 ;
V_11 = F_84 ( V_69 -> V_69 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_129 ( V_110 , V_111 , V_112 ) ;
F_76 ( V_69 -> V_69 ) ;
F_123 ( V_69 -> V_69 ) ;
return V_11 ;
}
static int F_130 ( struct V_27 * V_69 )
{
struct V_1 * V_2 = F_103 ( V_69 ) ;
struct V_68 * V_92 = F_90 ( V_2 ) ;
int V_11 ;
if ( V_86 == 0 )
return - V_116 ;
if ( V_86 == - 1 && ! F_131 () && ! F_132 () ) {
F_133 ( L_20 ) ;
return - V_116 ;
}
F_134 ( V_117 ) ;
F_135 ( V_92 ) ;
F_136 ( V_2 , V_118 ) ;
F_137 () ;
V_11 = F_93 ( V_92 ) ;
F_105 ( V_2 ) ;
F_106 ( V_2 ) ;
F_107 ( V_2 , V_119 ) ;
V_92 -> V_93 = V_95 ;
return V_11 ;
}
static int F_138 ( struct V_27 * V_69 )
{
struct V_1 * V_2 = F_103 ( V_69 ) ;
struct V_68 * V_92 = F_90 ( V_2 ) ;
struct V_26 * V_27 = F_139 ( V_92 ) ;
int V_11 ;
if ( V_86 == 0 )
return - V_116 ;
F_107 ( V_2 , V_98 ) ;
F_112 ( V_2 ) ;
V_11 = F_113 ( V_2 ) ;
if ( V_11 )
return V_11 ;
F_48 ( V_2 ) ;
V_11 = F_108 ( V_92 ) ;
if ( V_92 -> V_83 . V_84 )
F_101 ( V_92 ) ;
F_140 ( V_92 ) ;
F_61 ( V_27 , 0x88488 , ( 1 << 25 ) , ( 1 << 25 ) ) ;
F_136 ( V_2 , V_120 ) ;
V_92 -> V_93 = V_121 ;
F_134 ( V_122 ) ;
return V_11 ;
}
static int F_141 ( struct V_27 * V_69 )
{
struct V_1 * V_2 = F_103 ( V_69 ) ;
struct V_68 * V_92 = F_90 ( V_2 ) ;
struct V_20 * V_21 = V_20 ( V_92 ) ;
struct V_123 * V_124 ;
if ( V_86 == 0 )
return - V_125 ;
if ( V_86 == - 1 && ! F_131 () && ! F_132 () ) {
F_133 ( L_20 ) ;
return - V_125 ;
}
if ( V_21 -> V_71 ) {
if ( ! V_21 -> V_71 -> V_67 ) {
F_133 ( L_21 ) ;
F_76 ( V_69 ) ;
return - V_125 ;
}
}
F_98 (crtc, &drm->dev->mode_config.crtc_list, head) {
if ( V_124 -> V_126 ) {
F_133 ( L_22 ) ;
return - V_125 ;
}
}
F_76 ( V_69 ) ;
F_142 ( V_69 ) ;
return 1 ;
}
static int T_3
F_143 ( void )
{
if ( V_127 == - 1 ) {
#ifdef F_144
if ( F_145 () )
V_127 = 0 ;
#endif
}
if ( ! V_127 )
return 0 ;
F_146 () ;
return F_147 ( & V_67 , & V_128 ) ;
}
static void T_4
F_148 ( void )
{
if ( ! V_127 )
return;
F_149 ( & V_67 , & V_128 ) ;
F_150 () ;
}

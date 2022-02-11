static int
F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 =
F_2 ( V_2 , struct V_4 , V_6 [ V_3 ] ) ;
F_3 ( V_5 -> V_7 , V_3 ) ;
return V_8 ;
}
static int
F_4 ( struct V_9 * V_7 , int V_3 )
{
struct V_4 * V_5 = V_4 ( V_7 ) ;
struct V_10 * V_11 = V_10 ( V_5 -> V_12 ) ;
if ( F_5 ( V_3 > F_6 ( V_5 -> V_6 ) ) )
return - V_13 ;
F_5 ( V_5 -> V_6 [ V_3 ] . V_14 ) ;
V_5 -> V_6 [ V_3 ] . V_14 = F_1 ;
F_7 ( V_11 -> V_6 , V_3 , & V_5 -> V_6 [ V_3 ] ) ;
return 0 ;
}
static void
F_8 ( struct V_9 * V_7 , int V_3 )
{
struct V_4 * V_5 = V_4 ( V_7 ) ;
struct V_10 * V_11 = V_10 ( V_5 -> V_12 ) ;
if ( V_5 -> V_6 [ V_3 ] . V_14 )
F_9 ( V_11 -> V_6 , V_3 , & V_5 -> V_6 [ V_3 ] ) ;
else
F_5 ( 1 ) ;
V_5 -> V_6 [ V_3 ] . V_14 = NULL ;
}
static T_1
F_10 ( struct V_15 * V_16 )
{
T_1 V_17 = ( T_1 ) F_11 ( V_16 -> V_18 ) << 32 ;
V_17 |= V_16 -> V_18 -> V_19 << 16 ;
V_17 |= F_12 ( V_16 -> V_20 ) << 8 ;
return V_17 | F_13 ( V_16 -> V_20 ) ;
}
static int
F_14 ( struct V_15 * V_16 , const char * V_17 ,
int V_21 , void * * V_22 )
{
struct V_23 * V_24 ;
int V_25 ;
* V_22 = NULL ;
V_25 = F_15 ( V_17 , F_10 ( V_16 ) , V_26 ,
V_27 , V_21 , V_22 ) ;
V_24 = * V_22 ;
if ( V_25 ) {
if ( V_24 )
F_16 ( & V_24 -> V_28 ) ;
* V_22 = NULL ;
return V_25 ;
}
F_17 ( & V_24 -> V_29 ) ;
return 0 ;
}
static void
F_18 ( struct V_23 * V_24 )
{
struct V_30 * V_31 = F_19 ( V_24 ) ;
F_20 ( NULL , & V_24 -> V_28 . V_32 , NULL ) ;
F_21 ( & V_24 -> V_28 , false ) ;
F_22 ( & V_31 -> V_33 , 1 ) ;
F_23 ( NULL , & V_31 ) ;
}
static void
F_24 ( struct V_4 * V_5 )
{
F_25 ( NULL , & V_5 -> V_34 ) ;
F_26 ( & V_5 -> V_35 ) ;
F_26 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_37 )
F_27 ( V_5 ) -> F_28 ( V_5 ) ;
}
static void
F_29 ( struct V_4 * V_5 )
{
struct V_38 * V_12 = F_30 ( V_5 -> V_12 ) ;
struct V_30 * V_39 ;
T_2 V_40 , V_41 ;
int V_25 ;
if ( V_42 || ! F_31 ( V_12 ) )
return;
if ( V_12 -> V_43 < V_44 ) V_25 = F_32 ( V_5 ) ;
else if ( V_12 -> V_45 < 0x17 ) V_25 = F_33 ( V_5 ) ;
else if ( V_12 -> V_43 < V_46 ) V_25 = F_34 ( V_5 ) ;
else if ( V_12 -> V_45 < 0x84 ) V_25 = F_35 ( V_5 ) ;
else if ( V_12 -> V_43 < V_47 ) V_25 = F_36 ( V_5 ) ;
else V_25 = F_37 ( V_5 ) ;
if ( V_25 ) {
F_38 ( V_5 , L_1 , V_25 ) ;
F_24 ( V_5 ) ;
return;
}
if ( V_12 -> V_43 >= V_48 ) {
V_25 = F_39 ( V_5 , & V_5 -> V_31 , V_49 ,
V_50 + 1 ,
V_51 |
V_52 , 0 ,
& V_5 -> V_36 ) ;
if ( V_25 )
F_38 ( V_5 , L_2 , V_25 ) ;
V_40 = V_53 ;
V_41 = 1 ;
} else {
V_40 = V_54 ;
V_41 = V_55 ;
}
V_25 = F_39 ( V_5 , & V_5 -> V_31 , V_49 , V_50 ,
V_40 , V_41 , & V_5 -> V_35 ) ;
if ( V_25 ) {
F_38 ( V_5 , L_3 , V_25 ) ;
F_24 ( V_5 ) ;
return;
}
if ( V_12 -> V_43 < V_47 ) {
V_25 = F_40 ( V_5 -> V_12 , NULL , 32 , 0 , 0 ,
& V_5 -> V_34 ) ;
if ( V_25 ) {
F_38 ( V_5 , L_4 , V_25 ) ;
F_24 ( V_5 ) ;
return;
}
V_25 = F_41 (nv_object(drm),
drm->channel->handle, NvNotify0,
0x003d , &(struct nv_dma_class) {
.flags = NV_DMA_TARGET_VRAM |
NV_DMA_ACCESS_RDWR,
.start = drm->notify->addr,
.limit = drm->notify->addr + 31
}, sizeof(struct nv_dma_class),
&object) ;
if ( V_25 ) {
F_24 ( V_5 ) ;
return;
}
}
F_42 ( V_5 ) ;
}
static int F_43 ( struct V_15 * V_16 ,
const struct V_56 * V_57 )
{
struct V_38 * V_12 ;
struct V_58 * V_59 ;
bool V_60 = false ;
int V_25 ;
V_59 = F_44 ( 3 ) ;
if ( ! V_59 )
return - V_61 ;
V_59 -> V_62 [ 0 ] . V_28 = F_45 ( V_16 , 1 ) ;
V_59 -> V_62 [ 0 ] . V_21 = F_46 ( V_16 , 1 ) ;
V_59 -> V_63 = 1 ;
if ( F_46 ( V_16 , 2 ) ) {
V_59 -> V_62 [ V_59 -> V_63 ] . V_28 = F_45 ( V_16 , 2 ) ;
V_59 -> V_62 [ V_59 -> V_63 ] . V_21 = F_46 ( V_16 , 2 ) ;
V_59 -> V_63 ++ ;
}
if ( F_46 ( V_16 , 3 ) ) {
V_59 -> V_62 [ V_59 -> V_63 ] . V_28 = F_45 ( V_16 , 3 ) ;
V_59 -> V_62 [ V_59 -> V_63 ] . V_21 = F_46 ( V_16 , 3 ) ;
V_59 -> V_63 ++ ;
}
#ifdef F_47
V_60 = V_16 -> V_64 [ V_65 ] . V_66 & V_67 ;
#endif
F_48 ( V_59 , L_5 , V_60 ) ;
F_49 ( V_59 ) ;
V_25 = F_50 ( V_16 , F_10 ( V_16 ) , F_51 ( V_16 ) ,
V_26 , V_27 , & V_12 ) ;
if ( V_25 )
return V_25 ;
F_52 ( V_16 ) ;
V_25 = F_53 ( V_16 , V_57 , & V_68 ) ;
if ( V_25 ) {
F_23 ( NULL , (struct V_30 * * ) & V_12 ) ;
return V_25 ;
}
return 0 ;
}
static int
F_54 ( struct V_9 * V_7 , unsigned long V_66 )
{
struct V_15 * V_16 = V_7 -> V_16 ;
struct V_38 * V_12 ;
struct V_4 * V_5 ;
int V_25 ;
V_25 = F_14 ( V_16 , L_6 , sizeof( * V_5 ) , ( void * * ) & V_5 ) ;
if ( V_25 )
return V_25 ;
F_55 ( & V_5 -> V_31 . V_29 , & V_69 ) ;
V_7 -> V_70 = V_5 ;
V_5 -> V_7 = V_7 ;
F_56 ( & V_5 -> V_71 ) ;
F_57 ( & V_5 -> V_72 . V_73 ) ;
if ( F_58 ( V_7 ) && V_7 -> V_74 ) {
V_25 = F_41 (nv_object(drm), NVDRM_CLIENT,
NVDRM_DEVICE, 0x0080 ,
&(struct nv_device_class) {
.device = ~0 ,
.disable =
~(NV_DEVICE_DISABLE_MMIO |
NV_DEVICE_DISABLE_IDENTIFY),
.debug0 = ~0 ,
}, sizeof(struct nv_device_class),
&drm->device) ;
if ( V_25 )
goto V_75;
F_59 ( V_5 ) ;
F_60 ( F_19 ( V_5 ) , V_76 , V_49 ) ;
}
V_25 = F_41 (nv_object(drm), NVDRM_CLIENT, NVDRM_DEVICE,
0x0080 , &(struct nv_device_class) {
.device = ~0 ,
.disable = 0 ,
.debug0 = 0 ,
}, sizeof(struct nv_device_class),
&drm->device) ;
if ( V_25 )
goto V_75;
V_12 = F_30 ( V_5 -> V_12 ) ;
if ( F_30 ( V_5 -> V_12 ) -> V_45 == 0xc1 )
F_61 ( V_12 , 0x00088080 , 0x00000800 , 0x00000000 ) ;
F_62 ( V_5 ) ;
F_63 ( V_5 ) ;
if ( V_12 -> V_43 >= V_46 ) {
V_25 = F_64 ( F_30 ( V_5 -> V_12 ) , 0 , ( 1ULL << 40 ) ,
0x1000 , & V_5 -> V_31 . V_28 . V_32 ) ;
if ( V_25 )
goto V_75;
}
V_25 = F_65 ( V_5 ) ;
if ( V_25 )
goto V_77;
V_25 = F_66 ( V_7 ) ;
if ( V_25 )
goto V_78;
V_25 = F_67 ( V_7 ) ;
if ( V_25 )
goto V_79;
if ( V_7 -> V_80 . V_81 ) {
V_25 = F_68 ( V_7 ) ;
if ( V_25 )
goto V_82;
}
F_69 ( V_7 ) ;
F_29 ( V_5 ) ;
F_70 ( V_7 ) ;
return 0 ;
V_82:
F_71 ( V_7 ) ;
V_79:
F_72 ( V_7 ) ;
V_78:
F_73 ( V_5 ) ;
V_77:
F_74 ( V_5 ) ;
F_75 ( V_5 ) ;
V_75:
F_18 ( & V_5 -> V_31 ) ;
return V_25 ;
}
static int
F_76 ( struct V_9 * V_7 )
{
struct V_4 * V_5 = V_4 ( V_7 ) ;
F_77 ( V_7 ) ;
F_24 ( V_5 ) ;
F_78 ( V_7 ) ;
if ( V_7 -> V_80 . V_81 )
F_79 ( V_7 ) ;
F_71 ( V_7 ) ;
F_72 ( V_7 ) ;
F_73 ( V_5 ) ;
F_74 ( V_5 ) ;
F_75 ( V_5 ) ;
F_18 ( & V_5 -> V_31 ) ;
return 0 ;
}
static void
F_80 ( struct V_15 * V_16 )
{
struct V_9 * V_7 = F_81 ( V_16 ) ;
struct V_4 * V_5 = V_4 ( V_7 ) ;
struct V_30 * V_12 ;
V_12 = V_5 -> V_31 . V_28 . V_12 ;
F_82 ( V_7 ) ;
F_23 ( NULL , & V_12 ) ;
F_83 () ;
}
static int
F_84 ( struct V_9 * V_7 )
{
struct V_4 * V_5 = V_4 ( V_7 ) ;
struct V_23 * V_24 ;
int V_25 ;
if ( V_7 -> V_80 . V_81 ) {
F_85 ( V_5 , L_7 ) ;
F_86 ( V_7 , 1 ) ;
F_85 ( V_5 , L_8 ) ;
V_25 = F_87 ( V_7 ) ;
if ( V_25 )
return V_25 ;
}
F_85 ( V_5 , L_9 ) ;
F_88 ( & V_5 -> V_83 . V_84 , V_85 ) ;
F_85 ( V_5 , L_10 ) ;
if ( V_5 -> V_36 ) {
V_25 = F_89 ( V_5 -> V_36 ) ;
if ( V_25 )
return V_25 ;
}
if ( V_5 -> V_35 ) {
V_25 = F_89 ( V_5 -> V_35 ) ;
if ( V_25 )
return V_25 ;
}
F_85 ( V_5 , L_11 ) ;
if ( V_5 -> V_37 && F_27 ( V_5 ) -> V_86 ) {
if ( ! F_27 ( V_5 ) -> V_86 ( V_5 ) )
return - V_61 ;
}
F_90 (cli, &drm->clients, head) {
V_25 = F_21 ( & V_24 -> V_28 , true ) ;
if ( V_25 )
goto V_87;
}
F_85 ( V_5 , L_12 ) ;
V_25 = F_21 ( & V_5 -> V_31 . V_28 , true ) ;
if ( V_25 )
goto V_87;
F_74 ( V_5 ) ;
return 0 ;
V_87:
F_91 (cli, &drm->clients, head) {
F_92 ( & V_24 -> V_28 ) ;
}
if ( V_7 -> V_80 . V_81 ) {
F_85 ( V_5 , L_13 ) ;
F_93 ( V_7 ) ;
}
return V_25 ;
}
int F_94 ( struct V_12 * V_7 )
{
struct V_15 * V_16 = F_95 ( V_7 ) ;
struct V_9 * V_88 = F_81 ( V_16 ) ;
int V_25 ;
if ( V_88 -> V_89 == V_90 )
return 0 ;
V_25 = F_84 ( V_88 ) ;
if ( V_25 )
return V_25 ;
F_96 ( V_16 ) ;
F_97 ( V_16 ) ;
F_98 ( V_16 , V_91 ) ;
return 0 ;
}
static int
F_99 ( struct V_9 * V_7 )
{
struct V_4 * V_5 = V_4 ( V_7 ) ;
struct V_23 * V_24 ;
F_85 ( V_5 , L_14 ) ;
F_59 ( V_5 ) ;
F_85 ( V_5 , L_15 ) ;
F_92 ( & V_5 -> V_31 . V_28 ) ;
F_63 ( V_5 ) ;
F_85 ( V_5 , L_16 ) ;
if ( V_5 -> V_37 && F_27 ( V_5 ) -> V_92 )
F_27 ( V_5 ) -> V_92 ( V_5 ) ;
F_90 (cli, &drm->clients, head) {
F_92 ( & V_24 -> V_28 ) ;
}
F_100 ( V_7 ) ;
F_101 ( V_7 ) ;
if ( V_7 -> V_80 . V_81 ) {
F_85 ( V_5 , L_13 ) ;
F_93 ( V_7 ) ;
}
return 0 ;
}
int F_102 ( struct V_12 * V_7 )
{
struct V_15 * V_16 = F_95 ( V_7 ) ;
struct V_9 * V_88 = F_81 ( V_16 ) ;
int V_25 ;
if ( V_88 -> V_89 == V_90 )
return 0 ;
F_98 ( V_16 , V_93 ) ;
F_103 ( V_16 ) ;
V_25 = F_104 ( V_16 ) ;
if ( V_25 )
return V_25 ;
F_52 ( V_16 ) ;
return F_99 ( V_88 ) ;
}
static int F_105 ( struct V_12 * V_7 )
{
struct V_15 * V_16 = F_95 ( V_7 ) ;
struct V_9 * V_88 = F_81 ( V_16 ) ;
return F_84 ( V_88 ) ;
}
static int F_106 ( struct V_12 * V_7 )
{
struct V_15 * V_16 = F_95 ( V_7 ) ;
struct V_9 * V_88 = F_81 ( V_16 ) ;
return F_99 ( V_88 ) ;
}
static int
F_107 ( struct V_9 * V_7 , struct V_94 * V_95 )
{
struct V_15 * V_16 = V_7 -> V_16 ;
struct V_4 * V_5 = V_4 ( V_7 ) ;
struct V_23 * V_24 ;
char V_17 [ 32 ] , V_96 [ V_97 ] ;
int V_25 ;
F_108 ( V_96 , V_98 ) ;
snprintf ( V_17 , sizeof( V_17 ) , L_17 , V_96 , F_109 ( V_95 -> V_99 ) ) ;
V_25 = F_14 ( V_16 , V_17 , sizeof( * V_24 ) , ( void * * ) & V_24 ) ;
if ( V_25 )
return V_25 ;
if ( F_30 ( V_5 -> V_12 ) -> V_43 >= V_46 ) {
V_25 = F_64 ( F_30 ( V_5 -> V_12 ) , 0 , ( 1ULL << 40 ) ,
0x1000 , & V_24 -> V_28 . V_32 ) ;
if ( V_25 ) {
F_18 ( V_24 ) ;
return V_25 ;
}
}
V_95 -> V_100 = V_24 ;
F_110 ( & V_5 -> V_31 . V_29 ) ;
F_111 ( & V_24 -> V_3 , & V_5 -> V_71 ) ;
F_112 ( & V_5 -> V_31 . V_29 ) ;
return 0 ;
}
static void
F_113 ( struct V_9 * V_7 , struct V_94 * V_95 )
{
struct V_23 * V_24 = V_23 ( V_95 ) ;
struct V_4 * V_5 = V_4 ( V_7 ) ;
if ( V_24 -> V_101 )
F_114 ( V_24 -> V_101 ) ;
F_110 ( & V_5 -> V_31 . V_29 ) ;
F_115 ( & V_24 -> V_3 ) ;
F_112 ( & V_5 -> V_31 . V_29 ) ;
}
static void
F_116 ( struct V_9 * V_7 , struct V_94 * V_95 )
{
struct V_23 * V_24 = V_23 ( V_95 ) ;
F_18 ( V_24 ) ;
}
static int T_3
F_117 ( void )
{
V_68 . V_102 = F_6 ( V_103 ) ;
if ( V_104 == - 1 ) {
#ifdef F_118
if ( F_119 () )
V_104 = 0 ;
#endif
}
if ( ! V_104 )
return 0 ;
F_120 () ;
return F_121 ( & V_68 , & V_105 ) ;
}
static void T_4
F_122 ( void )
{
if ( ! V_104 )
return;
F_123 ( & V_68 , & V_105 ) ;
F_124 () ;
}

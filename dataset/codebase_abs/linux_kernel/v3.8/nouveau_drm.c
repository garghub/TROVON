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
if ( V_31 )
return;
if ( V_27 -> V_32 < V_33 ) V_11 = F_22 ( V_21 ) ;
else if ( V_27 -> V_32 < V_34 ) V_11 = F_23 ( V_21 ) ;
else if ( V_27 -> V_35 < 0x84 ) V_11 = F_24 ( V_21 ) ;
else if ( V_27 -> V_32 < V_36 ) V_11 = F_25 ( V_21 ) ;
else V_11 = F_26 ( V_21 ) ;
if ( V_11 ) {
F_27 ( V_21 , L_1 , V_11 ) ;
F_15 ( V_21 ) ;
return;
}
if ( V_27 -> V_32 >= V_37 ) {
V_11 = F_28 ( V_21 , & V_21 -> V_17 , V_38 ,
V_39 + 1 ,
V_40 |
V_41 , 0 ,
& V_21 -> V_24 ) ;
if ( V_11 )
F_27 ( V_21 , L_2 , V_11 ) ;
V_29 = V_42 ;
V_30 = 1 ;
} else {
V_29 = V_43 ;
V_30 = V_44 ;
}
V_11 = F_28 ( V_21 , & V_21 -> V_17 , V_38 , V_39 ,
V_29 , V_30 , & V_21 -> V_23 ) ;
if ( V_11 ) {
F_27 ( V_21 , L_3 , V_11 ) ;
F_15 ( V_21 ) ;
return;
}
if ( V_27 -> V_32 < V_36 ) {
V_11 = F_29 ( V_21 -> V_27 , NULL , 32 , 0 , 0 ,
& V_21 -> V_22 ) ;
if ( V_11 ) {
F_27 ( V_21 , L_4 , V_11 ) ;
F_15 ( V_21 ) ;
return;
}
V_11 = F_30 (nv_object(drm),
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
F_31 ( V_21 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
const struct V_45 * V_46 )
{
struct V_26 * V_27 ;
struct V_47 * V_48 ;
bool V_49 = false ;
int V_11 ;
V_48 = F_33 ( 3 ) ;
if ( ! V_48 )
return - V_50 ;
V_48 -> V_51 [ 0 ] . V_14 = F_34 ( V_2 , 1 ) ;
V_48 -> V_51 [ 0 ] . V_7 = F_35 ( V_2 , 1 ) ;
V_48 -> V_52 = 1 ;
if ( F_35 ( V_2 , 2 ) ) {
V_48 -> V_51 [ V_48 -> V_52 ] . V_14 = F_34 ( V_2 , 2 ) ;
V_48 -> V_51 [ V_48 -> V_52 ] . V_7 = F_35 ( V_2 , 2 ) ;
V_48 -> V_52 ++ ;
}
if ( F_35 ( V_2 , 3 ) ) {
V_48 -> V_51 [ V_48 -> V_52 ] . V_14 = F_34 ( V_2 , 3 ) ;
V_48 -> V_51 [ V_48 -> V_52 ] . V_7 = F_35 ( V_2 , 3 ) ;
V_48 -> V_52 ++ ;
}
#ifdef F_36
V_49 = V_2 -> V_53 [ V_54 ] . V_55 & V_56 ;
#endif
F_37 ( V_48 , L_5 , V_49 ) ;
F_38 ( V_48 ) ;
V_11 = F_39 ( V_2 , F_1 ( V_2 ) , F_40 ( V_2 ) ,
V_12 , V_13 , & V_27 ) ;
if ( V_11 )
return V_11 ;
F_41 ( V_2 ) ;
V_11 = F_42 ( V_2 , V_46 , & V_57 ) ;
if ( V_11 ) {
F_14 ( NULL , (struct V_16 * * ) & V_27 ) ;
return V_11 ;
}
return 0 ;
}
static int
F_43 ( struct V_58 * V_59 , unsigned long V_55 )
{
struct V_1 * V_2 = V_59 -> V_2 ;
struct V_26 * V_27 ;
struct V_20 * V_21 ;
int V_11 ;
V_11 = F_5 ( V_2 , L_6 , sizeof( * V_21 ) , ( void * * ) & V_21 ) ;
if ( V_11 )
return V_11 ;
F_44 ( & V_21 -> V_17 . V_15 , & V_60 ) ;
V_59 -> V_61 = V_21 ;
V_21 -> V_59 = V_59 ;
F_45 ( & V_21 -> V_62 ) ;
F_46 ( & V_21 -> V_63 . V_64 ) ;
if ( F_47 ( V_59 ) && V_59 -> V_65 ) {
V_11 = F_30 (nv_object(drm), NVDRM_CLIENT,
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
goto V_66;
F_48 ( V_21 ) ;
F_49 ( F_10 ( V_21 ) , V_67 , V_38 ) ;
}
V_11 = F_30 (nv_object(drm), NVDRM_CLIENT, NVDRM_DEVICE,
0x0080 , &(struct nv_device_class) {
.device = ~0 ,
.disable = 0 ,
.debug0 = 0 ,
}, sizeof(struct nv_device_class),
&drm->device) ;
if ( V_11 )
goto V_66;
V_27 = F_21 ( V_21 -> V_27 ) ;
if ( F_21 ( V_21 -> V_27 ) -> V_35 == 0xc1 )
F_50 ( V_27 , 0x00088080 , 0x00000800 , 0x00000000 ) ;
F_51 ( V_21 ) ;
F_52 ( V_21 ) ;
if ( V_27 -> V_32 >= V_34 ) {
V_11 = F_53 ( F_21 ( V_21 -> V_27 ) , 0 , ( 1ULL << 40 ) ,
0x1000 , & V_21 -> V_17 . V_14 . V_18 ) ;
if ( V_11 )
goto V_66;
}
V_11 = F_54 ( V_21 ) ;
if ( V_11 )
goto V_68;
V_11 = F_55 ( V_59 ) ;
if ( V_11 )
goto V_69;
V_11 = F_56 ( V_59 ) ;
if ( V_11 )
goto V_70;
V_11 = F_57 ( V_59 ) ;
if ( V_11 )
goto V_71;
if ( V_59 -> V_72 . V_73 ) {
V_11 = F_58 ( V_59 ) ;
if ( V_11 )
goto V_74;
}
F_59 ( V_59 ) ;
F_20 ( V_21 ) ;
F_60 ( V_59 ) ;
return 0 ;
V_74:
F_61 ( V_59 ) ;
V_71:
F_62 ( V_59 ) ;
V_70:
F_63 ( V_59 ) ;
V_69:
F_64 ( V_21 ) ;
V_68:
F_65 ( V_21 ) ;
F_66 ( V_21 ) ;
V_66:
F_9 ( & V_21 -> V_17 ) ;
return V_11 ;
}
static int
F_67 ( struct V_58 * V_59 )
{
struct V_20 * V_21 = V_20 ( V_59 ) ;
F_68 ( V_59 ) ;
F_15 ( V_21 ) ;
F_69 ( V_59 ) ;
if ( V_59 -> V_72 . V_73 )
F_70 ( V_59 ) ;
F_61 ( V_59 ) ;
F_62 ( V_59 ) ;
F_63 ( V_59 ) ;
F_64 ( V_21 ) ;
F_65 ( V_21 ) ;
F_66 ( V_21 ) ;
F_9 ( & V_21 -> V_17 ) ;
return 0 ;
}
static void
F_71 ( struct V_1 * V_2 )
{
struct V_58 * V_59 = F_72 ( V_2 ) ;
struct V_20 * V_21 = V_20 ( V_59 ) ;
struct V_16 * V_27 ;
V_27 = V_21 -> V_17 . V_14 . V_27 ;
F_73 ( V_59 ) ;
F_14 ( NULL , & V_27 ) ;
F_74 () ;
}
int
F_75 ( struct V_58 * V_59 )
{
struct V_20 * V_21 = V_20 ( V_59 ) ;
struct V_9 * V_10 ;
int V_11 ;
if ( V_59 -> V_72 . V_73 ) {
F_76 ( V_21 , L_7 ) ;
F_77 ( V_59 , 1 ) ;
F_76 ( V_21 , L_8 ) ;
V_11 = F_78 ( V_59 ) ;
if ( V_11 )
return V_11 ;
}
F_76 ( V_21 , L_9 ) ;
F_79 ( & V_21 -> V_75 . V_76 , V_77 ) ;
if ( V_21 -> V_25 && F_18 ( V_21 ) -> V_78 ) {
if ( ! F_18 ( V_21 ) -> V_78 ( V_21 ) )
return - V_50 ;
}
F_76 ( V_21 , L_10 ) ;
F_80 (cli, &drm->clients, head) {
V_11 = F_12 ( & V_10 -> V_14 , true ) ;
if ( V_11 )
goto V_79;
}
V_11 = F_12 ( & V_21 -> V_17 . V_14 , true ) ;
if ( V_11 )
goto V_79;
F_65 ( V_21 ) ;
return 0 ;
V_79:
F_81 (cli, &drm->clients, head) {
F_82 ( & V_10 -> V_14 ) ;
}
if ( V_59 -> V_72 . V_73 ) {
F_76 ( V_21 , L_11 ) ;
F_83 ( V_59 ) ;
}
return V_11 ;
}
int F_84 ( struct V_27 * V_59 )
{
struct V_1 * V_2 = F_85 ( V_59 ) ;
struct V_58 * V_80 = F_72 ( V_2 ) ;
int V_11 ;
if ( V_80 -> V_81 == V_82 )
return 0 ;
V_11 = F_75 ( V_80 ) ;
if ( V_11 )
return V_11 ;
F_86 ( V_2 ) ;
F_87 ( V_2 ) ;
F_88 ( V_2 , V_83 ) ;
return 0 ;
}
int
F_89 ( struct V_58 * V_59 )
{
struct V_20 * V_21 = V_20 ( V_59 ) ;
struct V_9 * V_10 ;
F_76 ( V_21 , L_12 ) ;
F_48 ( V_21 ) ;
F_76 ( V_21 , L_13 ) ;
F_82 ( & V_21 -> V_17 . V_14 ) ;
F_52 ( V_21 ) ;
F_80 (cli, &drm->clients, head) {
F_82 ( & V_10 -> V_14 ) ;
}
if ( V_21 -> V_25 && F_18 ( V_21 ) -> V_84 )
F_18 ( V_21 ) -> V_84 ( V_21 ) ;
F_90 ( V_59 ) ;
F_91 ( V_59 ) ;
F_92 ( V_59 ) ;
if ( V_59 -> V_72 . V_73 ) {
F_76 ( V_21 , L_11 ) ;
F_83 ( V_59 ) ;
}
return 0 ;
}
int F_93 ( struct V_27 * V_59 )
{
struct V_1 * V_2 = F_85 ( V_59 ) ;
struct V_58 * V_80 = F_72 ( V_2 ) ;
int V_11 ;
if ( V_80 -> V_81 == V_82 )
return 0 ;
F_88 ( V_2 , V_85 ) ;
F_94 ( V_2 ) ;
V_11 = F_95 ( V_2 ) ;
if ( V_11 )
return V_11 ;
F_41 ( V_2 ) ;
return F_89 ( V_80 ) ;
}
static int F_96 ( struct V_27 * V_59 )
{
struct V_1 * V_2 = F_85 ( V_59 ) ;
struct V_58 * V_80 = F_72 ( V_2 ) ;
return F_75 ( V_80 ) ;
}
static int F_97 ( struct V_27 * V_59 )
{
struct V_1 * V_2 = F_85 ( V_59 ) ;
struct V_58 * V_80 = F_72 ( V_2 ) ;
return F_89 ( V_80 ) ;
}
static int
F_98 ( struct V_58 * V_59 , struct V_86 * V_87 )
{
struct V_1 * V_2 = V_59 -> V_2 ;
struct V_20 * V_21 = V_20 ( V_59 ) ;
struct V_9 * V_10 ;
char V_3 [ 16 ] ;
int V_11 ;
snprintf ( V_3 , sizeof( V_3 ) , L_14 , F_99 ( V_87 -> V_88 ) ) ;
V_11 = F_5 ( V_2 , V_3 , sizeof( * V_10 ) , ( void * * ) & V_10 ) ;
if ( V_11 )
return V_11 ;
if ( F_21 ( V_21 -> V_27 ) -> V_32 >= V_34 ) {
V_11 = F_53 ( F_21 ( V_21 -> V_27 ) , 0 , ( 1ULL << 40 ) ,
0x1000 , & V_10 -> V_14 . V_18 ) ;
if ( V_11 ) {
F_9 ( V_10 ) ;
return V_11 ;
}
}
V_87 -> V_89 = V_10 ;
F_100 ( & V_21 -> V_17 . V_15 ) ;
F_101 ( & V_10 -> V_90 , & V_21 -> V_62 ) ;
F_102 ( & V_21 -> V_17 . V_15 ) ;
return 0 ;
}
static void
F_103 ( struct V_58 * V_59 , struct V_86 * V_87 )
{
struct V_9 * V_10 = V_9 ( V_87 ) ;
struct V_20 * V_21 = V_20 ( V_59 ) ;
if ( V_10 -> V_91 )
F_104 ( V_10 -> V_91 ) ;
F_100 ( & V_21 -> V_17 . V_15 ) ;
F_105 ( & V_10 -> V_90 ) ;
F_102 ( & V_21 -> V_17 . V_15 ) ;
}
static void
F_106 ( struct V_58 * V_59 , struct V_86 * V_87 )
{
struct V_9 * V_10 = V_9 ( V_87 ) ;
F_9 ( V_10 ) ;
}
static int T_3
F_107 ( void )
{
V_57 . V_92 = F_108 ( V_93 ) ;
if ( V_94 == - 1 ) {
#ifdef F_109
if ( F_110 () )
V_94 = 0 ;
#endif
}
if ( ! V_94 )
return 0 ;
F_111 () ;
return F_112 ( & V_57 , & V_95 ) ;
}
static void T_4
F_113 ( void )
{
if ( ! V_94 )
return;
F_114 ( & V_57 , & V_95 ) ;
F_115 () ;
}

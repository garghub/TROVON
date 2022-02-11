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
V_11 = F_6 ( V_3 , F_1 ( V_2 ) , V_12 ,
V_13 , V_7 , V_8 ) ;
V_10 = * V_8 ;
if ( V_11 )
return V_11 ;
F_7 ( & V_10 -> V_14 ) ;
return 0 ;
}
static void
F_8 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = F_9 ( V_10 ) ;
F_10 ( NULL , & V_10 -> V_17 . V_18 , NULL ) ;
F_11 ( & V_10 -> V_17 , false ) ;
F_12 ( & V_16 -> V_19 , 1 ) ;
F_13 ( NULL , & V_16 ) ;
}
static void
F_14 ( struct V_20 * V_21 )
{
F_15 ( NULL , & V_21 -> V_22 ) ;
F_16 ( & V_21 -> V_23 ) ;
F_16 ( & V_21 -> V_24 ) ;
if ( V_21 -> V_25 )
F_17 ( V_21 ) -> F_18 ( V_21 ) ;
}
static void
F_19 ( struct V_20 * V_21 )
{
struct V_26 * V_27 = F_20 ( V_21 -> V_27 ) ;
struct V_15 * V_28 ;
T_2 V_29 , V_30 ;
int V_11 ;
if ( V_31 )
return;
if ( V_27 -> V_32 < V_33 ) V_11 = F_21 ( V_21 ) ;
else if ( V_27 -> V_32 < V_34 ) V_11 = F_22 ( V_21 ) ;
else if ( V_27 -> V_35 < 0x84 ) V_11 = F_23 ( V_21 ) ;
else if ( V_27 -> V_32 < V_36 ) V_11 = F_24 ( V_21 ) ;
else V_11 = F_25 ( V_21 ) ;
if ( V_11 ) {
F_26 ( V_21 , L_1 , V_11 ) ;
F_14 ( V_21 ) ;
return;
}
if ( V_27 -> V_32 >= V_37 ) {
V_11 = F_27 ( V_21 , & V_21 -> V_16 , V_38 ,
V_39 + 1 ,
V_40 |
V_41 , 0 ,
& V_21 -> V_24 ) ;
if ( V_11 )
F_26 ( V_21 , L_2 , V_11 ) ;
V_29 = V_42 ;
V_30 = 0 ;
} else {
V_29 = V_43 ;
V_30 = V_44 ;
}
V_11 = F_27 ( V_21 , & V_21 -> V_16 , V_38 , V_39 ,
V_29 , V_30 , & V_21 -> V_23 ) ;
if ( V_11 ) {
F_26 ( V_21 , L_3 , V_11 ) ;
F_14 ( V_21 ) ;
return;
}
if ( V_27 -> V_32 < V_36 ) {
V_11 = F_28 ( V_21 -> V_27 , NULL , 32 , 0 , 0 ,
& V_21 -> V_22 ) ;
if ( V_11 ) {
F_26 ( V_21 , L_4 , V_11 ) ;
F_14 ( V_21 ) ;
return;
}
V_11 = F_29 (nv_object(drm),
drm->channel->handle, NvNotify0,
0x003d , &(struct nv_dma_class) {
.flags = NV_DMA_TARGET_VRAM |
NV_DMA_ACCESS_RDWR,
.start = drm->notify->addr,
.limit = drm->notify->addr + 31
}, sizeof(struct nv_dma_class),
&object) ;
if ( V_11 ) {
F_14 ( V_21 ) ;
return;
}
}
F_30 ( V_21 ) ;
}
static int T_3
F_31 ( struct V_1 * V_2 , const struct V_45 * V_46 )
{
struct V_26 * V_27 ;
struct V_47 * V_48 ;
bool V_49 = false ;
int V_11 ;
V_48 = F_32 ( 3 ) ;
if ( ! V_48 )
return - V_50 ;
V_48 -> V_51 [ 0 ] . V_17 = F_33 ( V_2 , 1 ) ;
V_48 -> V_51 [ 0 ] . V_7 = F_34 ( V_2 , 1 ) ;
V_48 -> V_52 = 1 ;
if ( F_34 ( V_2 , 2 ) ) {
V_48 -> V_51 [ V_48 -> V_52 ] . V_17 = F_33 ( V_2 , 2 ) ;
V_48 -> V_51 [ V_48 -> V_52 ] . V_7 = F_34 ( V_2 , 2 ) ;
V_48 -> V_52 ++ ;
}
if ( F_34 ( V_2 , 3 ) ) {
V_48 -> V_51 [ V_48 -> V_52 ] . V_17 = F_33 ( V_2 , 3 ) ;
V_48 -> V_51 [ V_48 -> V_52 ] . V_7 = F_34 ( V_2 , 3 ) ;
V_48 -> V_52 ++ ;
}
#ifdef F_35
V_49 = V_2 -> V_53 [ V_54 ] . V_55 & V_56 ;
#endif
F_36 ( V_48 , L_5 , V_49 ) ;
V_11 = F_37 ( V_2 , F_1 ( V_2 ) , F_38 ( V_2 ) ,
V_12 , V_13 , & V_27 ) ;
if ( V_11 )
return V_11 ;
F_39 ( V_2 ) ;
V_11 = F_40 ( V_2 , V_46 , & V_57 ) ;
if ( V_11 ) {
F_13 ( NULL , (struct V_15 * * ) & V_27 ) ;
return V_11 ;
}
return 0 ;
}
static int
F_41 ( struct V_58 * V_59 , unsigned long V_55 )
{
struct V_1 * V_2 = V_59 -> V_2 ;
struct V_26 * V_27 ;
struct V_20 * V_21 ;
int V_11 ;
V_11 = F_5 ( V_2 , L_6 , sizeof( * V_21 ) , ( void * * ) & V_21 ) ;
if ( V_11 )
return V_11 ;
V_59 -> V_60 = V_21 ;
V_21 -> V_59 = V_59 ;
F_42 ( & V_21 -> V_61 ) ;
F_43 ( & V_21 -> V_62 . V_63 ) ;
if ( F_44 ( V_59 ) && V_59 -> V_64 ) {
V_11 = F_29 (nv_object(drm), NVDRM_CLIENT,
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
goto V_65;
F_45 ( V_21 ) ;
F_46 ( F_9 ( V_21 ) , V_66 , V_38 ) ;
}
V_11 = F_29 (nv_object(drm), NVDRM_CLIENT, NVDRM_DEVICE,
0x0080 , &(struct nv_device_class) {
.device = ~0 ,
.disable = 0 ,
.debug0 = 0 ,
}, sizeof(struct nv_device_class),
&drm->device) ;
if ( V_11 )
goto V_65;
V_27 = F_20 ( V_21 -> V_27 ) ;
if ( F_20 ( V_21 -> V_27 ) -> V_35 == 0xc1 )
F_47 ( V_27 , 0x00088080 , 0x00000800 , 0x00000000 ) ;
F_48 ( V_21 ) ;
F_49 ( V_21 ) ;
if ( V_27 -> V_32 >= V_34 ) {
V_11 = F_50 ( F_20 ( V_21 -> V_27 ) , 0 , ( 1ULL << 40 ) ,
0x1000 , & V_21 -> V_16 . V_17 . V_18 ) ;
if ( V_11 )
goto V_65;
}
V_11 = F_51 ( V_21 ) ;
if ( V_11 )
goto V_67;
V_11 = F_52 ( V_59 ) ;
if ( V_11 )
goto V_68;
V_11 = F_53 ( V_59 ) ;
if ( V_11 )
goto V_69;
V_11 = F_54 ( V_59 ) ;
if ( V_11 )
goto V_70;
if ( V_59 -> V_71 . V_72 ) {
V_11 = F_55 ( V_59 ) ;
if ( V_11 )
goto V_73;
}
F_56 ( V_59 ) ;
F_19 ( V_21 ) ;
F_57 ( V_59 ) ;
return 0 ;
V_73:
F_58 ( V_59 ) ;
V_70:
F_59 ( V_59 ) ;
V_69:
F_60 ( V_59 ) ;
V_68:
F_61 ( V_21 ) ;
V_67:
F_62 ( V_21 ) ;
F_63 ( V_21 ) ;
V_65:
F_8 ( & V_21 -> V_16 ) ;
return V_11 ;
}
static int
F_64 ( struct V_58 * V_59 )
{
struct V_20 * V_21 = V_20 ( V_59 ) ;
F_65 ( V_59 ) ;
F_14 ( V_21 ) ;
F_66 ( V_59 ) ;
if ( V_59 -> V_71 . V_72 )
F_67 ( V_59 ) ;
F_58 ( V_59 ) ;
F_59 ( V_59 ) ;
F_60 ( V_59 ) ;
F_61 ( V_21 ) ;
F_62 ( V_21 ) ;
F_63 ( V_21 ) ;
F_8 ( & V_21 -> V_16 ) ;
return 0 ;
}
static void
F_68 ( struct V_1 * V_2 )
{
struct V_58 * V_59 = F_69 ( V_2 ) ;
struct V_20 * V_21 = V_20 ( V_59 ) ;
struct V_15 * V_27 ;
V_27 = V_21 -> V_16 . V_17 . V_27 ;
F_70 ( V_59 ) ;
F_13 ( NULL , & V_27 ) ;
F_71 () ;
}
int
F_72 ( struct V_1 * V_2 , T_4 V_74 )
{
struct V_58 * V_59 = F_69 ( V_2 ) ;
struct V_20 * V_21 = V_20 ( V_59 ) ;
struct V_9 * V_10 ;
int V_11 ;
if ( V_59 -> V_75 == V_76 ||
V_74 . V_77 == V_78 )
return 0 ;
if ( V_59 -> V_71 . V_72 ) {
F_73 ( V_21 , L_7 ) ;
F_74 ( V_59 , 1 ) ;
F_73 ( V_21 , L_8 ) ;
V_11 = F_75 ( V_59 ) ;
if ( V_11 )
return V_11 ;
}
F_73 ( V_21 , L_9 ) ;
F_76 ( & V_21 -> V_79 . V_80 , V_81 ) ;
if ( V_21 -> V_25 && F_17 ( V_21 ) -> V_82 ) {
if ( ! F_17 ( V_21 ) -> V_82 ( V_21 ) )
return - V_50 ;
}
F_73 ( V_21 , L_10 ) ;
F_77 (cli, &drm->clients, head) {
V_11 = F_11 ( & V_10 -> V_17 , true ) ;
if ( V_11 )
goto V_83;
}
V_11 = F_11 ( & V_21 -> V_16 . V_17 , true ) ;
if ( V_11 )
goto V_83;
F_62 ( V_21 ) ;
F_78 ( V_2 ) ;
if ( V_74 . V_77 == V_84 ) {
F_79 ( V_2 ) ;
F_80 ( V_2 , V_85 ) ;
}
return 0 ;
V_83:
F_81 (cli, &drm->clients, head) {
F_82 ( & V_10 -> V_17 ) ;
}
if ( V_59 -> V_71 . V_72 ) {
F_73 ( V_21 , L_11 ) ;
F_83 ( V_59 ) ;
}
return V_11 ;
}
int
F_84 ( struct V_1 * V_2 )
{
struct V_58 * V_59 = F_69 ( V_2 ) ;
struct V_20 * V_21 = V_20 ( V_59 ) ;
struct V_9 * V_10 ;
int V_11 ;
if ( V_59 -> V_75 == V_76 )
return 0 ;
F_73 ( V_21 , L_12 ) ;
F_80 ( V_2 , V_86 ) ;
F_85 ( V_2 ) ;
V_11 = F_86 ( V_2 ) ;
if ( V_11 )
return V_11 ;
F_39 ( V_2 ) ;
F_45 ( V_21 ) ;
F_73 ( V_21 , L_13 ) ;
F_82 ( & V_21 -> V_16 . V_17 ) ;
F_49 ( V_21 ) ;
F_77 (cli, &drm->clients, head) {
F_82 ( & V_10 -> V_17 ) ;
}
if ( V_21 -> V_25 && F_17 ( V_21 ) -> V_87 )
F_17 ( V_21 ) -> V_87 ( V_21 ) ;
F_87 ( V_59 ) ;
F_88 ( V_59 ) ;
F_89 ( V_59 ) ;
if ( V_59 -> V_71 . V_72 ) {
F_73 ( V_21 , L_11 ) ;
F_83 ( V_59 ) ;
}
return 0 ;
}
static int
F_90 ( struct V_58 * V_59 , struct V_88 * V_89 )
{
struct V_1 * V_2 = V_59 -> V_2 ;
struct V_20 * V_21 = V_20 ( V_59 ) ;
struct V_9 * V_10 ;
char V_3 [ 16 ] ;
int V_11 ;
snprintf ( V_3 , sizeof( V_3 ) , L_14 , F_91 ( V_89 -> V_90 ) ) ;
V_11 = F_5 ( V_2 , V_3 , sizeof( * V_10 ) , ( void * * ) & V_10 ) ;
if ( V_11 )
return V_11 ;
if ( F_20 ( V_21 -> V_27 ) -> V_32 >= V_34 ) {
V_11 = F_50 ( F_20 ( V_21 -> V_27 ) , 0 , ( 1ULL << 40 ) ,
0x1000 , & V_10 -> V_17 . V_18 ) ;
if ( V_11 ) {
F_8 ( V_10 ) ;
return V_11 ;
}
}
V_89 -> V_91 = V_10 ;
F_92 ( & V_21 -> V_16 . V_14 ) ;
F_93 ( & V_10 -> V_92 , & V_21 -> V_61 ) ;
F_94 ( & V_21 -> V_16 . V_14 ) ;
return 0 ;
}
static void
F_95 ( struct V_58 * V_59 , struct V_88 * V_89 )
{
struct V_9 * V_10 = V_9 ( V_89 ) ;
struct V_20 * V_21 = V_20 ( V_59 ) ;
if ( V_10 -> V_93 )
F_96 ( V_10 -> V_93 ) ;
F_92 ( & V_21 -> V_16 . V_14 ) ;
F_97 ( & V_10 -> V_92 ) ;
F_94 ( & V_21 -> V_16 . V_14 ) ;
}
static void
F_98 ( struct V_58 * V_59 , struct V_88 * V_89 )
{
struct V_9 * V_10 = V_9 ( V_89 ) ;
F_8 ( V_10 ) ;
}
static int T_5
F_99 ( void )
{
V_57 . V_94 = F_100 ( V_95 ) ;
if ( V_96 == - 1 ) {
#ifdef F_101
if ( F_102 () )
V_96 = 0 ;
#endif
}
if ( ! V_96 )
return 0 ;
F_103 () ;
return F_104 ( & V_57 , & V_97 ) ;
}
static void T_6
F_105 ( void )
{
if ( ! V_96 )
return;
F_106 ( & V_57 , & V_97 ) ;
F_107 () ;
}

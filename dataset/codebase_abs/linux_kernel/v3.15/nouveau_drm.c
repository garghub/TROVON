static T_1
F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = ( T_1 ) F_2 ( V_2 -> V_4 ) << 32 ;
V_3 |= V_2 -> V_4 -> V_5 << 16 ;
V_3 |= F_3 ( V_2 -> V_6 ) << 8 ;
return V_3 | F_4 ( V_2 -> V_6 ) ;
}
static T_1
F_5 ( struct V_7 * V_8 )
{
return V_8 -> V_9 ;
}
static T_1
F_6 ( struct V_10 * V_11 )
{
if ( V_11 -> V_2 )
return F_1 ( V_11 -> V_2 ) ;
else
return F_5 ( V_11 -> V_8 ) ;
}
static int
F_7 ( T_1 V_3 , const char * V_12 ,
int V_13 , void * * V_14 )
{
struct V_15 * V_16 ;
int V_17 ;
* V_14 = NULL ;
V_17 = F_8 ( V_12 , V_3 , V_18 ,
V_19 , V_13 , V_14 ) ;
V_16 = * V_14 ;
if ( V_17 ) {
if ( V_16 )
F_9 ( & V_16 -> V_20 ) ;
* V_14 = NULL ;
return V_17 ;
}
F_10 ( & V_16 -> V_21 ) ;
return 0 ;
}
static void
F_11 ( struct V_15 * V_16 )
{
struct V_22 * V_23 = F_12 ( V_16 ) ;
F_13 ( NULL , & V_16 -> V_20 . V_24 , NULL ) ;
F_14 ( & V_16 -> V_20 , false ) ;
F_15 ( & V_23 -> V_25 , 1 ) ;
F_16 ( NULL , & V_23 ) ;
}
static void
F_17 ( struct V_26 * V_27 )
{
F_18 ( NULL , & V_27 -> V_28 ) ;
F_19 ( & V_27 -> V_29 ) ;
F_19 ( & V_27 -> V_30 ) ;
if ( V_27 -> V_31 )
F_20 ( V_27 ) -> F_21 ( V_27 ) ;
}
static void
F_22 ( struct V_26 * V_27 )
{
struct V_32 * V_33 = F_23 ( V_27 -> V_33 ) ;
struct V_22 * V_34 ;
T_2 V_35 , V_36 ;
int V_17 ;
if ( V_37 || ! F_24 ( V_33 ) )
return;
if ( V_33 -> V_38 < V_39 ) V_17 = F_25 ( V_27 ) ;
else if ( V_33 -> V_38 < V_40 ||
V_33 -> V_41 < 0x17 ) V_17 = F_26 ( V_27 ) ;
else if ( V_33 -> V_38 < V_42 ) V_17 = F_27 ( V_27 ) ;
else if ( V_33 -> V_41 < 0x84 ) V_17 = F_28 ( V_27 ) ;
else if ( V_33 -> V_38 < V_43 ) V_17 = F_29 ( V_27 ) ;
else V_17 = F_30 ( V_27 ) ;
if ( V_17 ) {
F_31 ( V_27 , L_1 , V_17 ) ;
F_17 ( V_27 ) ;
return;
}
if ( V_33 -> V_38 >= V_44 ) {
V_17 = F_32 ( V_27 , & V_27 -> V_23 , V_45 ,
V_46 + 1 ,
V_47 |
V_48 , 0 ,
& V_27 -> V_30 ) ;
if ( V_17 )
F_31 ( V_27 , L_2 , V_17 ) ;
V_35 = V_49 ;
V_36 = 1 ;
} else
if ( V_33 -> V_41 >= 0xa3 &&
V_33 -> V_41 != 0xaa &&
V_33 -> V_41 != 0xac ) {
V_17 = F_32 ( V_27 , & V_27 -> V_23 , V_45 ,
V_46 + 1 , V_50 , V_51 ,
& V_27 -> V_30 ) ;
if ( V_17 )
F_31 ( V_27 , L_2 , V_17 ) ;
V_35 = V_50 ;
V_36 = V_51 ;
} else {
V_35 = V_50 ;
V_36 = V_51 ;
}
V_17 = F_32 ( V_27 , & V_27 -> V_23 , V_45 , V_46 ,
V_35 , V_36 , & V_27 -> V_29 ) ;
if ( V_17 ) {
F_31 ( V_27 , L_3 , V_17 ) ;
F_17 ( V_27 ) ;
return;
}
V_17 = F_33 ( F_12 ( V_27 ) , V_46 , V_52 ,
F_34 ( V_27 ) , NULL , 0 , & V_34 ) ;
if ( V_17 == 0 ) {
struct V_53 * V_54 = ( void * ) V_34 -> V_55 ;
V_17 = F_35 ( V_27 -> V_29 , 2 ) ;
if ( V_17 == 0 ) {
if ( V_33 -> V_38 < V_43 ) {
F_36 ( V_27 -> V_29 , V_56 , 0 , 1 ) ;
F_37 ( V_27 -> V_29 , V_52 ) ;
} else
if ( V_33 -> V_38 < V_44 ) {
F_38 ( V_27 -> V_29 , V_57 , 0 , 1 ) ;
F_37 ( V_27 -> V_29 , 0x001f0000 ) ;
}
}
V_54 = ( void * ) V_34 -> V_55 ;
V_54 -> V_58 = V_59 ;
V_54 -> V_60 = V_27 -> V_29 ;
}
if ( V_17 ) {
F_31 ( V_27 , L_4 , V_17 ) ;
F_17 ( V_27 ) ;
return;
}
if ( V_33 -> V_38 < V_43 ) {
V_17 = F_39 ( V_27 -> V_33 , NULL , 32 , 0 , 0 ,
& V_27 -> V_28 ) ;
if ( V_17 ) {
F_31 ( V_27 , L_5 , V_17 ) ;
F_17 ( V_27 ) ;
return;
}
V_17 = F_33 (nv_object(drm),
drm->channel->handle, NvNotify0,
0x003d , &(struct nv_dma_class) {
.flags = NV_DMA_TARGET_VRAM |
NV_DMA_ACCESS_RDWR,
.start = drm->notify->addr,
.limit = drm->notify->addr + 31
}, sizeof(struct nv_dma_class),
&object) ;
if ( V_17 ) {
F_17 ( V_27 ) ;
return;
}
}
F_40 ( V_27 ) ;
}
static int F_41 ( struct V_1 * V_2 ,
const struct V_61 * V_62 )
{
struct V_32 * V_33 ;
struct V_63 * V_64 ;
bool V_65 = false ;
int V_17 ;
V_64 = F_42 ( 3 ) ;
if ( ! V_64 )
return - V_66 ;
V_64 -> V_67 [ 0 ] . V_20 = F_43 ( V_2 , 1 ) ;
V_64 -> V_67 [ 0 ] . V_13 = F_44 ( V_2 , 1 ) ;
V_64 -> V_68 = 1 ;
if ( F_44 ( V_2 , 2 ) ) {
V_64 -> V_67 [ V_64 -> V_68 ] . V_20 = F_43 ( V_2 , 2 ) ;
V_64 -> V_67 [ V_64 -> V_68 ] . V_13 = F_44 ( V_2 , 2 ) ;
V_64 -> V_68 ++ ;
}
if ( F_44 ( V_2 , 3 ) ) {
V_64 -> V_67 [ V_64 -> V_68 ] . V_20 = F_43 ( V_2 , 3 ) ;
V_64 -> V_67 [ V_64 -> V_68 ] . V_13 = F_44 ( V_2 , 3 ) ;
V_64 -> V_68 ++ ;
}
#ifdef F_45
V_65 = V_2 -> V_69 [ V_70 ] . V_71 & V_72 ;
#endif
F_46 ( V_64 , L_6 , V_65 ) ;
F_47 ( V_64 ) ;
V_17 = F_48 ( V_2 , V_73 ,
F_1 ( V_2 ) , F_49 ( V_2 ) ,
V_18 , V_19 , & V_33 ) ;
if ( V_17 )
return V_17 ;
F_50 ( V_2 ) ;
V_17 = F_51 ( V_2 , V_62 , & V_74 ) ;
if ( V_17 ) {
F_16 ( NULL , (struct V_22 * * ) & V_33 ) ;
return V_17 ;
}
return 0 ;
}
static void
F_52 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_11 -> V_2 ;
if ( ! V_2 ) {
F_53 ( L_7 ) ;
V_27 -> V_75 = NULL ;
return;
}
V_27 -> V_75 = F_54 ( ( unsigned int ) V_2 -> V_4 -> V_5 ,
F_55 ( F_3 ( V_2 -> V_6 ) , 1 ) ) ;
if ( ! V_27 -> V_75 ) {
F_56 ( V_27 , L_8 , V_2 -> V_4 -> V_5 , F_3 ( V_2 -> V_6 ) , 1 ) ;
return;
}
if ( ( V_27 -> V_75 -> V_76 >> 8 ) != V_77 ) {
F_56 ( V_27 , L_9 , V_27 -> V_75 -> V_76 ) ;
F_57 ( V_27 -> V_75 ) ;
V_27 -> V_75 = NULL ;
return;
}
}
static int
F_58 ( struct V_10 * V_11 , unsigned long V_71 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_32 * V_33 ;
struct V_26 * V_27 ;
int V_17 ;
V_17 = F_7 ( F_6 ( V_11 ) , L_10 , sizeof( * V_27 ) ,
( void * * ) & V_27 ) ;
if ( V_17 )
return V_17 ;
V_11 -> V_78 = V_27 ;
V_27 -> V_11 = V_11 ;
F_59 ( V_27 ) -> V_79 = F_60 ( V_19 , L_10 ) ;
F_61 ( & V_27 -> V_80 ) ;
F_62 ( & V_27 -> V_81 . V_82 ) ;
F_52 ( V_27 ) ;
if ( V_2 && F_63 ( V_11 ) && V_11 -> V_83 ) {
V_17 = F_33 (nv_object(drm), NVDRM_CLIENT,
NVDRM_DEVICE, 0x0080 ,
&(struct nv_device_class) {
.device = ~0 ,
.disable =
~(NV_DEVICE_DISABLE_MMIO |
NV_DEVICE_DISABLE_IDENTIFY),
.debug0 = ~0 ,
}, sizeof(struct nv_device_class),
&drm->device) ;
if ( V_17 )
goto V_84;
F_64 ( V_27 ) ;
F_65 ( F_12 ( V_27 ) , V_85 , V_45 ) ;
}
V_17 = F_33 (nv_object(drm), NVDRM_CLIENT, NVDRM_DEVICE,
0x0080 , &(struct nv_device_class) {
.device = ~0 ,
.disable = 0 ,
.debug0 = 0 ,
}, sizeof(struct nv_device_class),
&drm->device) ;
if ( V_17 )
goto V_84;
V_11 -> V_86 = true ;
V_33 = F_23 ( V_27 -> V_33 ) ;
if ( F_23 ( V_27 -> V_33 ) -> V_41 == 0xc1 )
F_66 ( V_33 , 0x00088080 , 0x00000800 , 0x00000000 ) ;
F_67 ( V_27 ) ;
F_68 ( V_27 ) ;
if ( V_33 -> V_38 >= V_42 ) {
V_17 = F_69 ( F_23 ( V_27 -> V_33 ) , 0 , ( 1ULL << 40 ) ,
0x1000 , & V_27 -> V_23 . V_20 . V_24 ) ;
if ( V_17 )
goto V_84;
}
V_17 = F_70 ( V_27 ) ;
if ( V_17 )
goto V_87;
V_17 = F_71 ( V_11 ) ;
if ( V_17 )
goto V_88;
V_17 = F_72 ( V_11 ) ;
if ( V_17 )
goto V_89;
if ( V_11 -> V_90 . V_91 ) {
V_17 = F_73 ( V_11 ) ;
if ( V_17 )
goto V_92;
}
F_74 ( V_11 ) ;
F_75 ( V_11 ) ;
F_22 ( V_27 ) ;
F_76 ( V_11 ) ;
if ( V_93 != 0 ) {
F_77 ( V_11 -> V_11 ) ;
F_78 ( V_11 -> V_11 , 5000 ) ;
F_79 ( V_11 -> V_11 ) ;
F_80 ( V_11 -> V_11 ) ;
F_81 ( V_11 -> V_11 ) ;
F_82 ( V_11 -> V_11 ) ;
}
return 0 ;
V_92:
F_83 ( V_11 ) ;
V_89:
F_84 ( V_11 ) ;
V_88:
F_85 ( V_27 ) ;
V_87:
F_86 ( V_27 ) ;
F_87 ( V_27 ) ;
V_84:
F_11 ( & V_27 -> V_23 ) ;
return V_17 ;
}
static int
F_88 ( struct V_10 * V_11 )
{
struct V_26 * V_27 = V_26 ( V_11 ) ;
F_89 ( V_11 -> V_11 ) ;
F_90 ( V_11 ) ;
F_17 ( V_27 ) ;
F_91 ( V_11 ) ;
F_92 ( V_11 ) ;
if ( V_11 -> V_90 . V_91 )
F_93 ( V_11 ) ;
F_83 ( V_11 ) ;
F_84 ( V_11 ) ;
F_85 ( V_27 ) ;
F_86 ( V_27 ) ;
F_87 ( V_27 ) ;
if ( V_27 -> V_75 )
F_57 ( V_27 -> V_75 ) ;
F_11 ( & V_27 -> V_23 ) ;
return 0 ;
}
static void
F_94 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_95 ( V_2 ) ;
struct V_26 * V_27 = V_26 ( V_11 ) ;
struct V_22 * V_33 ;
V_11 -> V_86 = false ;
V_33 = V_27 -> V_23 . V_20 . V_33 ;
F_96 ( V_11 ) ;
F_16 ( NULL , & V_33 ) ;
F_97 () ;
}
static int
F_98 ( struct V_10 * V_11 , bool V_94 )
{
struct V_26 * V_27 = V_26 ( V_11 ) ;
struct V_15 * V_16 ;
int V_17 ;
if ( V_11 -> V_90 . V_91 && ! V_94 ) {
F_99 ( V_27 , L_11 ) ;
V_17 = F_100 ( V_11 ) ;
if ( V_17 )
return V_17 ;
}
F_99 ( V_27 , L_12 ) ;
F_101 ( & V_27 -> V_95 . V_96 , V_97 ) ;
F_99 ( V_27 , L_13 ) ;
if ( V_27 -> V_30 ) {
V_17 = F_102 ( V_27 -> V_30 ) ;
if ( V_17 )
goto V_98;
}
if ( V_27 -> V_29 ) {
V_17 = F_102 ( V_27 -> V_29 ) ;
if ( V_17 )
goto V_98;
}
F_99 ( V_27 , L_14 ) ;
if ( V_27 -> V_31 && F_20 ( V_27 ) -> V_99 ) {
if ( ! F_20 ( V_27 ) -> V_99 ( V_27 ) ) {
V_17 = - V_66 ;
goto V_98;
}
}
F_103 (cli, &drm->clients, head) {
V_17 = F_14 ( & V_16 -> V_20 , true ) ;
if ( V_17 )
goto V_100;
}
F_99 ( V_27 , L_15 ) ;
V_17 = F_14 ( & V_27 -> V_23 . V_20 , true ) ;
if ( V_17 )
goto V_100;
F_86 ( V_27 ) ;
return 0 ;
V_100:
F_104 (cli, &drm->clients, head) {
F_105 ( & V_16 -> V_20 ) ;
}
if ( V_27 -> V_31 && F_20 ( V_27 ) -> V_101 )
F_20 ( V_27 ) -> V_101 ( V_27 ) ;
V_98:
if ( V_11 -> V_90 . V_91 ) {
F_99 ( V_27 , L_16 ) ;
F_106 ( V_11 ) ;
}
return V_17 ;
}
int F_107 ( struct V_33 * V_11 )
{
struct V_1 * V_2 = F_108 ( V_11 ) ;
struct V_10 * V_102 = F_95 ( V_2 ) ;
int V_17 ;
if ( V_102 -> V_103 == V_104 ||
V_102 -> V_103 == V_105 )
return 0 ;
if ( V_102 -> V_90 . V_91 )
F_109 ( V_102 , 1 ) ;
V_17 = F_98 ( V_102 , false ) ;
if ( V_17 )
return V_17 ;
F_110 ( V_2 ) ;
F_111 ( V_2 ) ;
F_112 ( V_2 , V_106 ) ;
return 0 ;
}
static int
F_113 ( struct V_10 * V_11 )
{
struct V_26 * V_27 = V_26 ( V_11 ) ;
struct V_15 * V_16 ;
F_99 ( V_27 , L_17 ) ;
F_64 ( V_27 ) ;
F_99 ( V_27 , L_18 ) ;
F_105 ( & V_27 -> V_23 . V_20 ) ;
F_68 ( V_27 ) ;
F_99 ( V_27 , L_19 ) ;
if ( V_27 -> V_31 && F_20 ( V_27 ) -> V_101 )
F_20 ( V_27 ) -> V_101 ( V_27 ) ;
F_103 (cli, &drm->clients, head) {
F_105 ( & V_16 -> V_20 ) ;
}
F_114 ( V_11 ) ;
if ( V_11 -> V_90 . V_91 ) {
F_99 ( V_27 , L_16 ) ;
F_115 ( V_11 ) ;
}
return 0 ;
}
int F_116 ( struct V_33 * V_11 )
{
struct V_1 * V_2 = F_108 ( V_11 ) ;
struct V_10 * V_102 = F_95 ( V_2 ) ;
int V_17 ;
if ( V_102 -> V_103 == V_104 ||
V_102 -> V_103 == V_105 )
return 0 ;
F_112 ( V_2 , V_107 ) ;
F_117 ( V_2 ) ;
V_17 = F_118 ( V_2 ) ;
if ( V_17 )
return V_17 ;
F_50 ( V_2 ) ;
V_17 = F_113 ( V_102 ) ;
if ( V_17 )
return V_17 ;
if ( V_102 -> V_90 . V_91 )
F_109 ( V_102 , 0 ) ;
F_119 ( V_102 ) ;
if ( V_102 -> V_90 . V_91 )
F_106 ( V_102 ) ;
return 0 ;
}
static int F_120 ( struct V_33 * V_11 )
{
struct V_1 * V_2 = F_108 ( V_11 ) ;
struct V_10 * V_102 = F_95 ( V_2 ) ;
int V_17 ;
if ( V_102 -> V_90 . V_91 )
F_109 ( V_102 , 1 ) ;
V_17 = F_98 ( V_102 , false ) ;
return V_17 ;
}
static int F_121 ( struct V_33 * V_11 )
{
struct V_1 * V_2 = F_108 ( V_11 ) ;
struct V_10 * V_102 = F_95 ( V_2 ) ;
int V_17 ;
V_17 = F_113 ( V_102 ) ;
if ( V_17 )
return V_17 ;
if ( V_102 -> V_90 . V_91 )
F_109 ( V_102 , 0 ) ;
F_119 ( V_102 ) ;
if ( V_102 -> V_90 . V_91 )
F_106 ( V_102 ) ;
return 0 ;
}
static int
F_122 ( struct V_10 * V_11 , struct V_108 * V_109 )
{
struct V_26 * V_27 = V_26 ( V_11 ) ;
struct V_15 * V_16 ;
char V_3 [ 32 ] , V_110 [ V_111 ] ;
int V_17 ;
V_17 = F_89 ( V_11 -> V_11 ) ;
if ( V_17 < 0 && V_17 != - V_112 )
return V_17 ;
F_123 ( V_110 , V_113 ) ;
snprintf ( V_3 , sizeof( V_3 ) , L_20 , V_110 , F_124 ( V_109 -> V_114 ) ) ;
V_17 = F_7 ( F_6 ( V_11 ) , V_3 , sizeof( * V_16 ) ,
( void * * ) & V_16 ) ;
if ( V_17 )
goto V_115;
if ( F_23 ( V_27 -> V_33 ) -> V_38 >= V_42 ) {
V_17 = F_69 ( F_23 ( V_27 -> V_33 ) , 0 , ( 1ULL << 40 ) ,
0x1000 , & V_16 -> V_20 . V_24 ) ;
if ( V_17 ) {
F_11 ( V_16 ) ;
goto V_115;
}
}
V_109 -> V_116 = V_16 ;
F_125 ( & V_27 -> V_23 . V_21 ) ;
F_126 ( & V_16 -> V_117 , & V_27 -> V_80 ) ;
F_127 ( & V_27 -> V_23 . V_21 ) ;
V_115:
F_81 ( V_11 -> V_11 ) ;
F_128 ( V_11 -> V_11 ) ;
return V_17 ;
}
static void
F_129 ( struct V_10 * V_11 , struct V_108 * V_109 )
{
struct V_15 * V_16 = V_15 ( V_109 ) ;
struct V_26 * V_27 = V_26 ( V_11 ) ;
F_89 ( V_11 -> V_11 ) ;
if ( V_16 -> V_118 )
F_130 ( V_16 -> V_118 ) ;
F_125 ( & V_27 -> V_23 . V_21 ) ;
F_131 ( & V_16 -> V_117 ) ;
F_127 ( & V_27 -> V_23 . V_21 ) ;
}
static void
F_132 ( struct V_10 * V_11 , struct V_108 * V_109 )
{
struct V_15 * V_16 = V_15 ( V_109 ) ;
F_11 ( V_16 ) ;
F_81 ( V_11 -> V_11 ) ;
F_128 ( V_11 -> V_11 ) ;
}
long F_133 ( struct V_119 * V_120 ,
unsigned int V_121 , unsigned long V_122 )
{
struct V_108 * V_123 = V_120 -> V_124 ;
struct V_10 * V_11 ;
long V_17 ;
V_11 = V_123 -> V_125 -> V_11 ;
V_17 = F_89 ( V_11 -> V_11 ) ;
if ( V_17 < 0 && V_17 != - V_112 )
return V_17 ;
V_17 = F_134 ( V_120 , V_121 , V_122 ) ;
F_81 ( V_11 -> V_11 ) ;
F_128 ( V_11 -> V_11 ) ;
return V_17 ;
}
static int F_135 ( struct V_33 * V_11 )
{
struct V_1 * V_2 = F_108 ( V_11 ) ;
struct V_10 * V_102 = F_95 ( V_2 ) ;
int V_17 ;
if ( V_93 == 0 ) {
F_136 ( V_11 ) ;
return - V_126 ;
}
if ( V_93 == - 1 && ! F_137 () && ! F_138 () ) {
F_139 ( L_21 ) ;
F_136 ( V_11 ) ;
return - V_126 ;
}
F_140 ( V_127 ) ;
F_141 ( V_102 ) ;
F_142 ( V_2 , V_128 ) ;
F_143 () ;
V_17 = F_98 ( V_102 , true ) ;
F_110 ( V_2 ) ;
F_111 ( V_2 ) ;
F_112 ( V_2 , V_129 ) ;
V_102 -> V_103 = V_105 ;
return V_17 ;
}
static int F_144 ( struct V_33 * V_11 )
{
struct V_1 * V_2 = F_108 ( V_11 ) ;
struct V_10 * V_102 = F_95 ( V_2 ) ;
struct V_32 * V_33 = F_145 ( V_102 ) ;
int V_17 ;
if ( V_93 == 0 )
return - V_130 ;
F_112 ( V_2 , V_107 ) ;
F_117 ( V_2 ) ;
V_17 = F_118 ( V_2 ) ;
if ( V_17 )
return V_17 ;
F_50 ( V_2 ) ;
V_17 = F_113 ( V_102 ) ;
F_146 ( V_102 ) ;
F_66 ( V_33 , 0x88488 , ( 1 << 25 ) , ( 1 << 25 ) ) ;
F_142 ( V_2 , V_131 ) ;
V_102 -> V_103 = V_132 ;
F_140 ( V_133 ) ;
return V_17 ;
}
static int F_147 ( struct V_33 * V_11 )
{
struct V_1 * V_2 = F_108 ( V_11 ) ;
struct V_10 * V_102 = F_95 ( V_2 ) ;
struct V_26 * V_27 = V_26 ( V_102 ) ;
struct V_134 * V_135 ;
if ( V_93 == 0 ) {
F_136 ( V_11 ) ;
return - V_126 ;
}
if ( V_93 == - 1 && ! F_137 () && ! F_138 () ) {
F_139 ( L_21 ) ;
F_136 ( V_11 ) ;
return - V_126 ;
}
if ( V_27 -> V_75 ) {
if ( ! V_27 -> V_75 -> V_74 ) {
F_139 ( L_22 ) ;
F_81 ( V_11 ) ;
return - V_126 ;
}
}
F_103 (crtc, &drm->dev->mode_config.crtc_list, head) {
if ( V_135 -> V_136 ) {
F_139 ( L_23 ) ;
return - V_126 ;
}
}
F_81 ( V_11 ) ;
F_148 ( V_11 ) ;
return 1 ;
}
int F_149 ( struct V_7 * V_2 )
{
struct V_32 * V_33 ;
int V_17 ;
V_17 = F_48 ( V_2 , V_137 ,
F_5 ( V_2 ) ,
F_150 ( & V_2 -> V_11 ) , V_18 ,
V_19 , & V_33 ) ;
V_17 = F_151 ( & V_74 , V_2 ) ;
if ( V_17 ) {
F_16 ( NULL , (struct V_22 * * ) & V_33 ) ;
return V_17 ;
}
return V_17 ;
}
static int T_3
F_152 ( void )
{
if ( V_138 == - 1 ) {
#ifdef F_153
if ( F_154 () )
V_138 = 0 ;
#endif
}
if ( ! V_138 )
return 0 ;
F_155 () ;
return F_156 ( & V_74 , & V_139 ) ;
}
static void T_4
F_157 ( void )
{
if ( ! V_138 )
return;
F_158 ( & V_74 , & V_139 ) ;
F_159 () ;
}

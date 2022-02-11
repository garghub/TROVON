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
struct V_15 * V_16 = * V_14 = F_8 ( V_13 , V_17 ) ;
if ( V_16 ) {
int V_18 = F_9 ( NULL , NULL , V_12 , V_3 ,
V_19 , V_20 ,
& V_16 -> V_21 ) ;
if ( V_18 == 0 ) {
F_10 ( & V_16 -> V_22 ) ;
F_11 ( V_16 ) ;
}
return V_18 ;
}
return - V_23 ;
}
static void
F_12 ( struct V_15 * V_16 )
{
F_13 ( NULL , & F_14 ( & V_16 -> V_21 ) -> V_24 , NULL ) ;
F_15 ( & V_16 -> V_21 ) ;
F_16 ( V_16 ) ;
F_17 ( V_16 ) ;
}
static void
F_18 ( struct V_25 * V_26 )
{
F_19 ( & V_26 -> V_27 ) ;
F_20 ( & V_26 -> V_28 ) ;
F_21 ( NULL , & V_26 -> V_29 ) ;
F_20 ( & V_26 -> V_30 ) ;
F_19 ( & V_26 -> V_31 ) ;
F_20 ( & V_26 -> V_32 . V_33 ) ;
if ( V_26 -> V_34 )
F_22 ( V_26 ) -> F_23 ( V_26 ) ;
}
static void
F_24 ( struct V_25 * V_26 )
{
struct V_35 * V_36 = & V_26 -> V_36 ;
T_2 V_37 , V_38 ;
T_2 V_39 [ 16 ] ;
int V_18 , V_40 ;
if ( V_41 )
return;
V_18 = F_25 ( & V_36 -> V_21 , V_39 , F_26 ( V_39 ) ) ;
if ( V_18 < 0 )
return;
for ( V_18 = - V_42 , V_40 = 0 ; V_18 && V_40 < F_26 ( V_39 ) ; V_40 ++ ) {
switch ( V_39 [ V_40 ] ) {
case V_43 :
V_18 = F_27 ( V_26 ) ;
break;
case V_44 :
V_18 = F_28 ( V_26 ) ;
break;
case V_45 :
case V_46 :
V_18 = F_29 ( V_26 ) ;
break;
case V_47 :
V_18 = F_30 ( V_26 ) ;
break;
case V_48 :
V_18 = F_31 ( V_26 ) ;
break;
case V_49 :
case V_50 :
case V_51 :
V_18 = F_32 ( V_26 ) ;
break;
default:
break;
}
}
if ( V_18 ) {
F_33 ( V_26 , L_1 , V_18 ) ;
F_18 ( V_26 ) ;
return;
}
if ( V_36 -> V_52 . V_53 >= V_54 ) {
V_18 = F_34 ( V_26 , & V_26 -> V_36 , V_55 + 1 ,
V_56 |
V_57 ,
0 , & V_26 -> V_31 ) ;
if ( V_18 )
F_33 ( V_26 , L_2 , V_18 ) ;
V_37 = V_58 ;
V_38 = 1 ;
} else
if ( V_36 -> V_52 . V_59 >= 0xa3 &&
V_36 -> V_52 . V_59 != 0xaa &&
V_36 -> V_52 . V_59 != 0xac ) {
V_18 = F_34 ( V_26 , & V_26 -> V_36 , V_55 + 1 ,
V_60 , V_61 , & V_26 -> V_31 ) ;
if ( V_18 )
F_33 ( V_26 , L_2 , V_18 ) ;
V_37 = V_60 ;
V_38 = V_61 ;
} else {
V_37 = V_60 ;
V_38 = V_61 ;
}
V_18 = F_34 ( V_26 , & V_26 -> V_36 , V_55 , V_37 , V_38 ,
& V_26 -> V_27 ) ;
if ( V_18 ) {
F_33 ( V_26 , L_3 , V_18 ) ;
F_18 ( V_26 ) ;
return;
}
V_18 = F_35 ( V_26 -> V_27 -> V_62 , NULL , V_63 ,
F_36 ( V_26 ) , NULL , 0 , & V_26 -> V_30 ) ;
if ( V_18 == 0 ) {
struct V_64 * V_65 ;
V_18 = F_37 ( V_26 -> V_27 , 2 ) ;
if ( V_18 == 0 ) {
if ( V_36 -> V_52 . V_53 < V_66 ) {
F_38 ( V_26 -> V_27 , V_67 , 0 , 1 ) ;
F_39 ( V_26 -> V_27 , V_63 ) ;
} else
if ( V_36 -> V_52 . V_53 < V_54 ) {
F_40 ( V_26 -> V_27 , V_68 , 0 , 1 ) ;
F_39 ( V_26 -> V_27 , 0x001f0000 ) ;
}
}
V_65 = ( void * ) F_41 ( & V_26 -> V_30 ) -> V_69 ;
V_65 -> V_70 = V_71 ;
V_65 -> V_72 = V_26 -> V_27 ;
}
if ( V_18 ) {
F_33 ( V_26 , L_4 , V_18 ) ;
F_18 ( V_26 ) ;
return;
}
if ( V_36 -> V_52 . V_53 < V_66 ) {
V_18 = F_42 ( F_41 ( & V_26 -> V_36 ) , NULL , 32 ,
0 , 0 , & V_26 -> V_29 ) ;
if ( V_18 ) {
F_33 ( V_26 , L_5 , V_18 ) ;
F_18 ( V_26 ) ;
return;
}
V_18 = F_35 (drm->channel->object, NULL, NvNotify0,
NV_DMA_IN_MEMORY,
&(struct nv_dma_v0) {
.target = NV_DMA_V0_TARGET_VRAM,
.access = NV_DMA_V0_ACCESS_RDWR,
.start = drm->notify->addr,
.limit = drm->notify->addr + 31
}, sizeof(struct nv_dma_v0),
&drm->ntfy) ;
if ( V_18 ) {
F_18 ( V_26 ) ;
return;
}
}
F_43 ( V_26 ) ;
}
static int F_44 ( struct V_1 * V_2 ,
const struct V_73 * V_74 )
{
struct V_75 * V_36 ;
struct V_76 * V_77 ;
bool V_78 = false ;
int V_18 ;
V_77 = F_45 ( 3 ) ;
if ( ! V_77 )
return - V_23 ;
V_77 -> V_79 [ 0 ] . V_21 = F_46 ( V_2 , 1 ) ;
V_77 -> V_79 [ 0 ] . V_13 = F_47 ( V_2 , 1 ) ;
V_77 -> V_80 = 1 ;
if ( F_47 ( V_2 , 2 ) ) {
V_77 -> V_79 [ V_77 -> V_80 ] . V_21 = F_46 ( V_2 , 2 ) ;
V_77 -> V_79 [ V_77 -> V_80 ] . V_13 = F_47 ( V_2 , 2 ) ;
V_77 -> V_80 ++ ;
}
if ( F_47 ( V_2 , 3 ) ) {
V_77 -> V_79 [ V_77 -> V_80 ] . V_21 = F_46 ( V_2 , 3 ) ;
V_77 -> V_79 [ V_77 -> V_80 ] . V_13 = F_47 ( V_2 , 3 ) ;
V_77 -> V_80 ++ ;
}
#ifdef F_48
V_78 = V_2 -> V_81 [ V_82 ] . V_83 & V_84 ;
#endif
if ( V_85 != 2 )
F_49 ( V_77 , L_6 , V_78 ) ;
F_17 ( V_77 ) ;
V_18 = F_50 ( V_2 , V_86 ,
F_1 ( V_2 ) , F_51 ( V_2 ) ,
V_19 , V_20 , & V_36 ) ;
if ( V_18 )
return V_18 ;
F_52 ( V_2 ) ;
V_18 = F_53 ( V_2 , V_74 , & V_87 ) ;
if ( V_18 ) {
F_54 ( NULL , (struct V_88 * * ) & V_36 ) ;
return V_18 ;
}
return 0 ;
}
static void
F_55 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_11 -> V_2 ;
if ( ! V_2 ) {
F_56 ( L_7 ) ;
V_26 -> V_89 = NULL ;
return;
}
V_26 -> V_89 = F_57 ( ( unsigned int ) V_2 -> V_4 -> V_5 ,
F_58 ( F_3 ( V_2 -> V_6 ) , 1 ) ) ;
if ( ! V_26 -> V_89 ) {
F_59 ( V_26 , L_8 , V_2 -> V_4 -> V_5 , F_3 ( V_2 -> V_6 ) , 1 ) ;
return;
}
if ( ( V_26 -> V_89 -> V_90 >> 8 ) != V_91 ) {
F_59 ( V_26 , L_9 , V_26 -> V_89 -> V_90 ) ;
F_60 ( V_26 -> V_89 ) ;
V_26 -> V_89 = NULL ;
return;
}
}
static int
F_61 ( struct V_10 * V_11 , unsigned long V_83 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_25 * V_26 ;
int V_18 ;
V_18 = F_7 ( F_6 ( V_11 ) , L_10 , sizeof( * V_26 ) ,
( void * * ) & V_26 ) ;
if ( V_18 )
return V_18 ;
V_11 -> V_92 = V_26 ;
V_26 -> V_11 = V_11 ;
F_14 ( & V_26 -> V_93 . V_21 ) -> V_94 =
F_62 ( V_20 , L_10 ) ;
F_63 ( & V_26 -> V_95 ) ;
F_64 ( & V_26 -> V_96 . V_97 ) ;
F_55 ( V_26 ) ;
if ( V_2 && F_65 ( V_11 ) && V_11 -> V_98 ) {
const T_1 V_99 = V_100 |
V_101 ;
V_18 = F_66 (&drm->client.base.base, NULL,
NVDRM_DEVICE, NV_DEVICE,
&(struct nv_device_v0) {
.device = ~0 ,
.disable = ~enables,
.debug0 = ~0 ,
}, sizeof(struct nv_device_v0),
&drm->device) ;
if ( V_18 )
goto V_102;
F_67 ( V_26 ) ;
F_68 ( & V_26 -> V_36 ) ;
}
V_18 = F_66 (&drm->client.base.base, NULL, NVDRM_DEVICE,
NV_DEVICE,
&(struct nv_device_v0) {
.device = ~0 ,
.disable = 0 ,
.debug0 = 0 ,
}, sizeof(struct nv_device_v0),
&drm->device) ;
if ( V_18 )
goto V_102;
V_11 -> V_103 = true ;
if ( V_26 -> V_36 . V_52 . V_59 == 0xc1 )
F_69 ( & V_26 -> V_36 , 0x00088080 , 0x00000800 , 0x00000000 ) ;
F_70 ( V_26 ) ;
F_71 ( V_26 ) ;
if ( V_26 -> V_36 . V_52 . V_53 >= V_104 ) {
V_18 = F_72 ( F_73 ( & V_26 -> V_36 ) , 0 , ( 1ULL << 40 ) ,
0x1000 , & V_26 -> V_93 . V_24 ) ;
if ( V_18 )
goto V_102;
F_14 ( & V_26 -> V_93 . V_21 ) -> V_24 = V_26 -> V_93 . V_24 ;
}
V_18 = F_74 ( V_26 ) ;
if ( V_18 )
goto V_105;
V_18 = F_75 ( V_11 ) ;
if ( V_18 )
goto V_106;
V_18 = F_76 ( V_11 ) ;
if ( V_18 )
goto V_107;
if ( V_11 -> V_108 . V_109 ) {
V_18 = F_77 ( V_11 ) ;
if ( V_18 )
goto V_110;
}
F_78 ( V_11 ) ;
F_79 ( V_11 ) ;
F_24 ( V_26 ) ;
F_80 ( V_11 ) ;
if ( V_111 != 0 ) {
F_81 ( V_11 -> V_11 ) ;
F_82 ( V_11 -> V_11 , 5000 ) ;
F_83 ( V_11 -> V_11 ) ;
F_84 ( V_11 -> V_11 ) ;
F_85 ( V_11 -> V_11 ) ;
F_86 ( V_11 -> V_11 ) ;
}
return 0 ;
V_110:
F_87 ( V_11 ) ;
V_107:
F_88 ( V_11 ) ;
V_106:
F_89 ( V_26 ) ;
V_105:
F_90 ( V_26 ) ;
F_91 ( V_26 ) ;
V_102:
F_68 ( & V_26 -> V_36 ) ;
F_12 ( & V_26 -> V_93 ) ;
return V_18 ;
}
static int
F_92 ( struct V_10 * V_11 )
{
struct V_25 * V_26 = V_25 ( V_11 ) ;
F_93 ( V_11 -> V_11 ) ;
F_94 ( V_11 ) ;
F_18 ( V_26 ) ;
F_95 ( V_11 ) ;
F_96 ( V_11 ) ;
if ( V_11 -> V_108 . V_109 )
F_97 ( V_11 ) ;
F_87 ( V_11 ) ;
F_88 ( V_11 ) ;
F_89 ( V_26 ) ;
F_90 ( V_26 ) ;
F_91 ( V_26 ) ;
F_68 ( & V_26 -> V_36 ) ;
if ( V_26 -> V_89 )
F_60 ( V_26 -> V_89 ) ;
F_12 ( & V_26 -> V_93 ) ;
return 0 ;
}
void
F_98 ( struct V_10 * V_11 )
{
struct V_25 * V_26 = V_25 ( V_11 ) ;
struct V_112 * V_93 ;
struct V_88 * V_36 ;
V_11 -> V_103 = false ;
V_93 = F_14 ( & V_26 -> V_93 . V_21 ) ;
V_36 = V_93 -> V_36 ;
F_99 ( V_11 ) ;
F_54 ( NULL , & V_36 ) ;
F_100 () ;
}
static void
F_101 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_102 ( V_2 ) ;
F_98 ( V_11 ) ;
}
static int
F_103 ( struct V_10 * V_11 , bool V_113 )
{
struct V_25 * V_26 = V_25 ( V_11 ) ;
struct V_15 * V_16 ;
int V_18 ;
if ( V_11 -> V_108 . V_109 ) {
F_104 ( V_26 , L_11 ) ;
F_105 ( V_11 , 1 ) ;
F_104 ( V_26 , L_12 ) ;
V_18 = F_106 ( V_11 , V_113 ) ;
if ( V_18 )
return V_18 ;
}
F_104 ( V_26 , L_13 ) ;
F_107 ( & V_26 -> V_32 . V_114 , V_115 ) ;
F_104 ( V_26 , L_14 ) ;
if ( V_26 -> V_31 ) {
V_18 = F_108 ( V_26 -> V_31 ) ;
if ( V_18 )
goto V_116;
}
if ( V_26 -> V_27 ) {
V_18 = F_108 ( V_26 -> V_27 ) ;
if ( V_18 )
goto V_116;
}
F_104 ( V_26 , L_15 ) ;
if ( V_26 -> V_34 && F_22 ( V_26 ) -> V_117 ) {
if ( ! F_22 ( V_26 ) -> V_117 ( V_26 ) ) {
V_18 = - V_23 ;
goto V_116;
}
}
F_109 (cli, &drm->clients, head) {
V_18 = F_110 ( & V_16 -> V_21 ) ;
if ( V_18 )
goto V_118;
}
F_104 ( V_26 , L_16 ) ;
V_18 = F_110 ( & V_26 -> V_93 . V_21 ) ;
if ( V_18 )
goto V_118;
F_90 ( V_26 ) ;
return 0 ;
V_118:
F_111 (cli, &drm->clients, head) {
F_112 ( & V_16 -> V_21 ) ;
}
if ( V_26 -> V_34 && F_22 ( V_26 ) -> V_119 )
F_22 ( V_26 ) -> V_119 ( V_26 ) ;
V_116:
if ( V_11 -> V_108 . V_109 ) {
F_104 ( V_26 , L_17 ) ;
F_113 ( V_11 , V_113 ) ;
}
return V_18 ;
}
static int
F_114 ( struct V_10 * V_11 , bool V_113 )
{
struct V_25 * V_26 = V_25 ( V_11 ) ;
struct V_15 * V_16 ;
F_104 ( V_26 , L_18 ) ;
F_67 ( V_26 ) ;
F_104 ( V_26 , L_19 ) ;
F_112 ( & V_26 -> V_93 . V_21 ) ;
F_71 ( V_26 ) ;
F_104 ( V_26 , L_20 ) ;
if ( V_26 -> V_34 && F_22 ( V_26 ) -> V_119 )
F_22 ( V_26 ) -> V_119 ( V_26 ) ;
F_109 (cli, &drm->clients, head) {
F_112 ( & V_16 -> V_21 ) ;
}
F_115 ( V_11 ) ;
if ( V_11 -> V_108 . V_109 ) {
F_104 ( V_26 , L_17 ) ;
F_113 ( V_11 , V_113 ) ;
F_104 ( V_26 , L_21 ) ;
F_105 ( V_11 , 0 ) ;
}
return 0 ;
}
int
F_116 ( struct V_36 * V_11 )
{
struct V_1 * V_2 = F_117 ( V_11 ) ;
struct V_10 * V_120 = F_102 ( V_2 ) ;
int V_18 ;
if ( V_120 -> V_121 == V_122 ||
V_120 -> V_121 == V_123 )
return 0 ;
V_18 = F_103 ( V_120 , false ) ;
if ( V_18 )
return V_18 ;
F_118 ( V_2 ) ;
F_119 ( V_2 ) ;
F_120 ( V_2 , V_124 ) ;
F_121 ( 200 ) ;
return 0 ;
}
int
F_122 ( struct V_36 * V_11 )
{
struct V_1 * V_2 = F_117 ( V_11 ) ;
struct V_10 * V_120 = F_102 ( V_2 ) ;
int V_18 ;
if ( V_120 -> V_121 == V_122 ||
V_120 -> V_121 == V_123 )
return 0 ;
F_120 ( V_2 , V_125 ) ;
F_123 ( V_2 ) ;
V_18 = F_124 ( V_2 ) ;
if ( V_18 )
return V_18 ;
F_52 ( V_2 ) ;
return F_114 ( V_120 , false ) ;
}
static int
F_125 ( struct V_36 * V_11 )
{
struct V_1 * V_2 = F_117 ( V_11 ) ;
struct V_10 * V_120 = F_102 ( V_2 ) ;
return F_103 ( V_120 , false ) ;
}
static int
F_126 ( struct V_36 * V_11 )
{
struct V_1 * V_2 = F_117 ( V_11 ) ;
struct V_10 * V_120 = F_102 ( V_2 ) ;
return F_114 ( V_120 , false ) ;
}
static int
F_127 ( struct V_36 * V_11 )
{
struct V_1 * V_2 = F_117 ( V_11 ) ;
struct V_10 * V_120 = F_102 ( V_2 ) ;
int V_18 ;
if ( V_111 == 0 ) {
F_128 ( V_11 ) ;
return - V_126 ;
}
if ( V_111 == - 1 && ! F_129 () && ! F_130 () ) {
F_131 ( L_22 ) ;
F_128 ( V_11 ) ;
return - V_126 ;
}
F_132 ( V_127 ) ;
F_133 ( V_120 ) ;
F_134 ( V_2 , V_128 ) ;
F_135 () ;
V_18 = F_103 ( V_120 , true ) ;
F_118 ( V_2 ) ;
F_119 ( V_2 ) ;
F_136 ( V_2 ) ;
F_120 ( V_2 , V_129 ) ;
V_120 -> V_121 = V_123 ;
return V_18 ;
}
static int
F_137 ( struct V_36 * V_11 )
{
struct V_1 * V_2 = F_117 ( V_11 ) ;
struct V_10 * V_120 = F_102 ( V_2 ) ;
struct V_35 * V_36 = & V_25 ( V_120 ) -> V_36 ;
int V_18 ;
if ( V_111 == 0 )
return - V_130 ;
F_120 ( V_2 , V_125 ) ;
F_123 ( V_2 ) ;
V_18 = F_124 ( V_2 ) ;
if ( V_18 )
return V_18 ;
F_52 ( V_2 ) ;
V_18 = F_114 ( V_120 , true ) ;
F_138 ( V_120 ) ;
F_69 ( V_36 , 0x88488 , ( 1 << 25 ) , ( 1 << 25 ) ) ;
F_134 ( V_2 , V_131 ) ;
V_120 -> V_121 = V_132 ;
F_132 ( V_133 ) ;
return V_18 ;
}
static int
F_139 ( struct V_36 * V_11 )
{
struct V_1 * V_2 = F_117 ( V_11 ) ;
struct V_10 * V_120 = F_102 ( V_2 ) ;
struct V_25 * V_26 = V_25 ( V_120 ) ;
struct V_134 * V_135 ;
if ( V_111 == 0 ) {
F_128 ( V_11 ) ;
return - V_126 ;
}
if ( V_111 == - 1 && ! F_129 () && ! F_130 () ) {
F_131 ( L_22 ) ;
F_128 ( V_11 ) ;
return - V_126 ;
}
if ( V_26 -> V_89 ) {
if ( ! V_26 -> V_89 -> V_136 ) {
F_131 ( L_23 ) ;
F_85 ( V_11 ) ;
return - V_126 ;
}
}
F_109 (crtc, &drm->dev->mode_config.crtc_list, head) {
if ( V_135 -> V_137 ) {
F_131 ( L_24 ) ;
return - V_126 ;
}
}
F_85 ( V_11 ) ;
F_140 ( V_11 ) ;
return 1 ;
}
static int
F_141 ( struct V_10 * V_11 , struct V_138 * V_139 )
{
struct V_25 * V_26 = V_25 ( V_11 ) ;
struct V_15 * V_16 ;
char V_3 [ 32 ] , V_140 [ V_141 ] ;
int V_18 ;
V_18 = F_93 ( V_11 -> V_11 ) ;
if ( V_18 < 0 && V_18 != - V_142 )
return V_18 ;
F_142 ( V_140 , V_143 ) ;
snprintf ( V_3 , sizeof( V_3 ) , L_25 , V_140 , F_143 ( V_139 -> V_144 ) ) ;
V_18 = F_7 ( F_6 ( V_11 ) , V_3 , sizeof( * V_16 ) ,
( void * * ) & V_16 ) ;
if ( V_18 )
goto V_145;
V_16 -> V_21 . V_146 = false ;
if ( V_26 -> V_36 . V_52 . V_53 >= V_104 ) {
V_18 = F_72 ( F_73 ( & V_26 -> V_36 ) , 0 , ( 1ULL << 40 ) ,
0x1000 , & V_16 -> V_24 ) ;
if ( V_18 ) {
F_12 ( V_16 ) ;
goto V_145;
}
F_14 ( & V_16 -> V_21 ) -> V_24 = V_16 -> V_24 ;
}
V_139 -> V_147 = V_16 ;
F_144 ( & V_26 -> V_93 . V_22 ) ;
F_145 ( & V_16 -> V_148 , & V_26 -> V_95 ) ;
F_146 ( & V_26 -> V_93 . V_22 ) ;
V_145:
F_85 ( V_11 -> V_11 ) ;
F_147 ( V_11 -> V_11 ) ;
return V_18 ;
}
static void
F_148 ( struct V_10 * V_11 , struct V_138 * V_139 )
{
struct V_15 * V_16 = V_15 ( V_139 ) ;
struct V_25 * V_26 = V_25 ( V_11 ) ;
F_93 ( V_11 -> V_11 ) ;
F_144 ( & V_16 -> V_22 ) ;
if ( V_16 -> V_149 )
F_149 ( V_16 -> V_149 ) ;
F_146 ( & V_16 -> V_22 ) ;
F_144 ( & V_26 -> V_93 . V_22 ) ;
F_150 ( & V_16 -> V_148 ) ;
F_146 ( & V_26 -> V_93 . V_22 ) ;
}
static void
F_151 ( struct V_10 * V_11 , struct V_138 * V_139 )
{
struct V_15 * V_16 = V_15 ( V_139 ) ;
F_12 ( V_16 ) ;
F_85 ( V_11 -> V_11 ) ;
F_147 ( V_11 -> V_11 ) ;
}
long
F_152 ( struct V_150 * V_150 , unsigned int V_151 , unsigned long V_152 )
{
struct V_138 * V_153 = V_150 -> V_154 ;
struct V_10 * V_11 = V_153 -> V_155 -> V_11 ;
long V_18 ;
V_18 = F_93 ( V_11 -> V_11 ) ;
if ( V_18 < 0 && V_18 != - V_142 )
return V_18 ;
switch ( F_153 ( V_151 ) - V_156 ) {
case V_157 :
V_18 = F_154 ( V_153 , ( void V_158 * ) V_152 , F_155 ( V_151 ) ) ;
break;
default:
V_18 = F_156 ( V_150 , V_151 , V_152 ) ;
break;
}
F_85 ( V_11 -> V_11 ) ;
F_147 ( V_11 -> V_11 ) ;
return V_18 ;
}
static void F_157 ( void )
{
F_131 ( L_26 ) ;
F_131 ( L_27 , V_159 ) ;
F_131 ( L_28 , V_160 ) ;
F_131 ( L_29 , V_161 ) ;
F_131 ( L_30 , V_162 ) ;
F_131 ( L_31 , V_19 ) ;
F_131 ( L_32 , V_20 ) ;
F_131 ( L_33 , V_41 ) ;
F_131 ( L_34 , V_85 ) ;
F_131 ( L_35 , V_111 ) ;
F_131 ( L_36 , V_163 ) ;
F_131 ( L_37 , V_164 ) ;
}
struct V_10 *
F_158 ( struct V_7 * V_2 , int V_13 ,
void * * V_165 )
{
struct V_10 * V_26 ;
int V_166 ;
V_166 = F_159 ( V_2 , V_167 ,
F_5 ( V_2 ) ,
F_160 ( & V_2 -> V_11 ) , V_19 ,
V_20 , V_13 , V_165 ) ;
if ( V_166 )
return F_161 ( V_166 ) ;
V_26 = F_162 ( & V_168 , & V_2 -> V_11 ) ;
if ( ! V_26 ) {
V_166 = - V_23 ;
goto V_169;
}
V_166 = F_163 ( V_26 , L_38 , F_160 ( & V_2 -> V_11 ) ) ;
if ( V_166 < 0 )
goto V_169;
V_26 -> V_8 = V_2 ;
F_164 ( V_2 , V_26 ) ;
return V_26 ;
V_169:
F_54 ( NULL , (struct V_88 * * ) V_165 ) ;
return F_161 ( V_166 ) ;
}
static int T_3
F_165 ( void )
{
V_87 = V_170 ;
V_87 . V_171 = V_172 ;
V_168 = V_170 ;
V_168 . V_171 = V_173 ;
F_157 () ;
if ( V_85 == - 1 ) {
#ifdef F_166
if ( F_167 () )
V_85 = 0 ;
#endif
}
if ( ! V_85 )
return 0 ;
#ifdef F_168
F_169 ( & V_174 ) ;
#endif
F_170 () ;
return F_171 ( & V_87 , & V_175 ) ;
}
static void T_4
F_172 ( void )
{
if ( ! V_85 )
return;
F_173 ( & V_87 , & V_175 ) ;
F_174 () ;
#ifdef F_168
F_175 ( & V_174 ) ;
#endif
}

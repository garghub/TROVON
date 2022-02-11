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
F_7 ( struct V_10 * V_11 , const char * V_12 ,
int V_13 , void * * V_14 )
{
struct V_15 * V_16 = * V_14 = F_8 ( V_13 , V_17 ) ;
int V_18 ;
if ( V_16 ) {
snprintf ( V_16 -> V_3 , sizeof( V_16 -> V_3 ) , L_1 , V_12 ) ;
V_16 -> V_11 = V_11 ;
V_18 = F_9 ( NULL , V_16 -> V_3 , F_6 ( V_11 ) ,
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
F_19 ( V_26 -> V_27 ) ;
F_20 ( & V_26 -> V_28 ) ;
F_21 ( & V_26 -> V_29 ) ;
F_22 ( & V_26 -> V_30 ) ;
F_20 ( & V_26 -> V_31 ) ;
F_23 ( & V_26 -> V_27 ) ;
F_19 ( V_26 -> V_32 ) ;
F_20 ( & V_26 -> V_33 . V_34 ) ;
F_23 ( & V_26 -> V_32 ) ;
if ( V_26 -> V_35 )
F_24 ( V_26 ) -> F_25 ( V_26 ) ;
}
static void
F_26 ( struct V_25 * V_26 )
{
struct V_36 * V_37 = & V_26 -> V_37 ;
struct V_38 * V_39 ;
T_2 V_40 , V_41 ;
int V_18 , V_42 , V_43 ;
if ( V_44 )
return;
V_18 = V_43 = F_27 ( & V_37 -> V_45 , & V_39 ) ;
if ( V_18 < 0 )
return;
for ( V_18 = - V_46 , V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
switch ( V_39 [ V_42 ] . V_47 ) {
case V_48 :
V_18 = F_28 ( V_26 ) ;
break;
case V_49 :
V_18 = F_29 ( V_26 ) ;
break;
case V_50 :
case V_51 :
V_18 = F_30 ( V_26 ) ;
break;
case V_52 :
V_18 = F_31 ( V_26 ) ;
break;
case V_53 :
V_18 = F_32 ( V_26 ) ;
break;
case V_54 :
case V_55 :
case V_56 :
V_18 = F_33 ( V_26 ) ;
break;
default:
break;
}
}
F_34 ( & V_39 ) ;
if ( V_18 ) {
F_35 ( V_26 , L_2 , V_18 ) ;
F_18 ( V_26 ) ;
return;
}
if ( V_37 -> V_57 . V_58 >= V_59 ) {
V_18 = F_36 ( V_26 , & V_26 -> V_37 ,
V_60 |
V_61 ,
0 , & V_26 -> V_32 ) ;
if ( V_18 )
F_35 ( V_26 , L_3 , V_18 ) ;
V_40 = V_62 ;
V_41 = 1 ;
} else
if ( V_37 -> V_57 . V_63 >= 0xa3 &&
V_37 -> V_57 . V_63 != 0xaa &&
V_37 -> V_57 . V_63 != 0xac ) {
V_18 = F_36 ( V_26 , & V_26 -> V_37 ,
V_64 , V_65 , & V_26 -> V_32 ) ;
if ( V_18 )
F_35 ( V_26 , L_3 , V_18 ) ;
V_40 = V_64 ;
V_41 = V_65 ;
} else {
V_40 = V_64 ;
V_41 = V_65 ;
}
V_18 = F_36 ( V_26 , & V_26 -> V_37 , V_40 , V_41 , & V_26 -> V_27 ) ;
if ( V_18 ) {
F_35 ( V_26 , L_4 , V_18 ) ;
F_18 ( V_26 ) ;
return;
}
V_18 = F_37 ( & V_26 -> V_27 -> V_66 , V_67 ,
F_38 ( V_26 ) , NULL , 0 , & V_26 -> V_31 ) ;
if ( V_18 == 0 ) {
V_18 = F_39 ( V_26 -> V_27 , 2 ) ;
if ( V_18 == 0 ) {
if ( V_37 -> V_57 . V_58 < V_68 ) {
F_40 ( V_26 -> V_27 , V_69 , 0 , 1 ) ;
F_41 ( V_26 -> V_27 , V_67 ) ;
} else
if ( V_37 -> V_57 . V_58 < V_59 ) {
F_42 ( V_26 -> V_27 , V_70 , 0 , 1 ) ;
F_41 ( V_26 -> V_27 , 0x001f0000 ) ;
}
}
V_18 = F_43 ( & V_26 -> V_31 , V_71 ,
false , V_72 , NULL , 0 , 0 ,
& V_26 -> V_30 ) ;
if ( V_18 == 0 )
V_18 = F_44 ( & V_26 -> V_30 ) ;
if ( V_18 ) {
F_18 ( V_26 ) ;
return;
}
}
if ( V_18 ) {
F_35 ( V_26 , L_5 , V_18 ) ;
F_18 ( V_26 ) ;
return;
}
if ( V_37 -> V_57 . V_58 < V_68 ) {
V_18 = F_45 ( F_46 ( & V_26 -> V_37 ) , 32 , 0 , false ,
NULL , & V_26 -> V_29 ) ;
if ( V_18 ) {
F_35 ( V_26 , L_6 , V_18 ) ;
F_18 ( V_26 ) ;
return;
}
V_18 = F_37 (&drm->channel->user, NvNotify0,
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
F_47 ( V_26 ) ;
}
static int F_48 ( struct V_1 * V_2 ,
const struct V_73 * V_74 )
{
struct V_75 * V_37 ;
struct V_76 * V_77 ;
bool V_78 = false ;
int V_18 ;
V_77 = F_49 ( 3 ) ;
if ( ! V_77 )
return - V_23 ;
V_77 -> V_79 [ 0 ] . V_21 = F_50 ( V_2 , 1 ) ;
V_77 -> V_79 [ 0 ] . V_13 = F_51 ( V_2 , 1 ) ;
V_77 -> V_80 = 1 ;
if ( F_51 ( V_2 , 2 ) ) {
V_77 -> V_79 [ V_77 -> V_80 ] . V_21 = F_50 ( V_2 , 2 ) ;
V_77 -> V_79 [ V_77 -> V_80 ] . V_13 = F_51 ( V_2 , 2 ) ;
V_77 -> V_80 ++ ;
}
if ( F_51 ( V_2 , 3 ) ) {
V_77 -> V_79 [ V_77 -> V_80 ] . V_21 = F_50 ( V_2 , 3 ) ;
V_77 -> V_79 [ V_77 -> V_80 ] . V_13 = F_51 ( V_2 , 3 ) ;
V_77 -> V_80 ++ ;
}
#ifdef F_52
V_78 = V_2 -> V_81 [ V_82 ] . V_83 & V_84 ;
#endif
if ( V_85 != 2 )
F_53 ( V_77 , L_7 , V_78 ) ;
F_17 ( V_77 ) ;
V_18 = F_54 ( V_2 , V_19 , V_20 ,
true , true , ~ 0ULL , & V_37 ) ;
if ( V_18 )
return V_18 ;
F_55 ( V_2 ) ;
V_18 = F_56 ( V_2 , V_74 , & V_86 ) ;
if ( V_18 ) {
F_57 ( & V_37 ) ;
return V_18 ;
}
return 0 ;
}
static void
F_58 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_11 -> V_2 ;
if ( ! V_2 ) {
F_59 ( L_8 ) ;
V_26 -> V_87 = NULL ;
return;
}
V_26 -> V_87 = F_60 ( ( unsigned int ) V_2 -> V_4 -> V_5 ,
F_61 ( F_3 ( V_2 -> V_6 ) , 1 ) ) ;
if ( ! V_26 -> V_87 ) {
F_62 ( V_26 , L_9 , V_2 -> V_4 -> V_5 , F_3 ( V_2 -> V_6 ) , 1 ) ;
return;
}
if ( ( V_26 -> V_87 -> V_88 >> 8 ) != V_89 ) {
F_62 ( V_26 , L_10 , V_26 -> V_87 -> V_88 ) ;
F_63 ( V_26 -> V_87 ) ;
V_26 -> V_87 = NULL ;
return;
}
}
static int
F_64 ( struct V_10 * V_11 , unsigned long V_83 )
{
struct V_25 * V_26 ;
int V_18 ;
V_18 = F_7 ( V_11 , L_11 , sizeof( * V_26 ) , ( void * * ) & V_26 ) ;
if ( V_18 )
return V_18 ;
V_11 -> V_90 = V_26 ;
V_26 -> V_11 = V_11 ;
F_14 ( & V_26 -> V_91 . V_21 ) -> V_92 =
F_65 ( V_20 , L_11 ) ;
F_66 ( & V_26 -> V_93 ) ;
F_67 ( & V_26 -> V_94 . V_95 ) ;
F_58 ( V_26 ) ;
V_18 = F_68 (&drm->client.base.object, 0 , NV_DEVICE,
&(struct nv_device_v0) {
.device = ~0 ,
}, sizeof(struct nv_device_v0),
&drm->device) ;
if ( V_18 )
goto V_96;
V_11 -> V_97 = true ;
if ( V_26 -> V_37 . V_57 . V_63 == 0xc1 )
F_69 ( & V_26 -> V_37 . V_45 , 0x00088080 , 0x00000800 , 0x00000000 ) ;
F_70 ( V_26 ) ;
if ( V_26 -> V_37 . V_57 . V_58 >= V_98 ) {
V_18 = F_71 ( F_46 ( & V_26 -> V_37 ) , 0 , ( 1ULL << 40 ) ,
0x1000 , NULL , & V_26 -> V_91 . V_24 ) ;
if ( V_18 )
goto V_96;
F_14 ( & V_26 -> V_91 . V_21 ) -> V_24 = V_26 -> V_91 . V_24 ;
}
V_18 = F_72 ( V_26 ) ;
if ( V_18 )
goto V_99;
V_18 = F_73 ( V_11 ) ;
if ( V_18 )
goto V_100;
V_18 = F_74 ( V_11 ) ;
if ( V_18 )
goto V_101;
if ( V_11 -> V_102 . V_103 ) {
V_18 = F_75 ( V_11 ) ;
if ( V_18 )
goto V_104;
}
F_76 ( V_11 ) ;
F_77 ( V_11 ) ;
F_26 ( V_26 ) ;
F_78 ( V_11 ) ;
if ( V_105 != 0 ) {
F_79 ( V_11 -> V_11 ) ;
F_80 ( V_11 -> V_11 , 5000 ) ;
F_81 ( V_11 -> V_11 ) ;
F_82 ( V_11 -> V_11 ) ;
F_83 ( V_11 -> V_11 ) ;
F_84 ( V_11 -> V_11 ) ;
}
return 0 ;
V_104:
F_85 ( V_11 ) ;
V_101:
F_86 ( V_11 ) ;
V_100:
F_87 ( V_26 ) ;
V_99:
F_88 ( V_26 ) ;
V_96:
F_89 ( & V_26 -> V_37 ) ;
F_12 ( & V_26 -> V_91 ) ;
return V_18 ;
}
static int
F_90 ( struct V_10 * V_11 )
{
struct V_25 * V_26 = V_25 ( V_11 ) ;
F_91 ( V_11 -> V_11 ) ;
F_92 ( V_11 ) ;
F_18 ( V_26 ) ;
F_93 ( V_11 ) ;
F_94 ( V_11 ) ;
if ( V_11 -> V_102 . V_103 )
F_95 ( V_11 ) ;
F_85 ( V_11 ) ;
F_86 ( V_11 ) ;
F_87 ( V_26 ) ;
F_88 ( V_26 ) ;
F_89 ( & V_26 -> V_37 ) ;
if ( V_26 -> V_87 )
F_63 ( V_26 -> V_87 ) ;
F_12 ( & V_26 -> V_91 ) ;
return 0 ;
}
void
F_96 ( struct V_10 * V_11 )
{
struct V_25 * V_26 = V_25 ( V_11 ) ;
struct V_106 * V_91 ;
struct V_75 * V_37 ;
V_11 -> V_97 = false ;
V_91 = F_14 ( & V_26 -> V_91 . V_21 ) ;
V_37 = F_97 ( V_91 -> V_37 ) ;
F_98 ( V_11 ) ;
F_57 ( & V_37 ) ;
}
static void
F_99 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_100 ( V_2 ) ;
F_96 ( V_11 ) ;
}
static int
F_101 ( struct V_10 * V_11 , bool V_107 )
{
struct V_25 * V_26 = V_25 ( V_11 ) ;
struct V_15 * V_16 ;
int V_18 ;
if ( V_11 -> V_102 . V_103 ) {
F_102 ( V_26 , L_12 ) ;
F_103 ( V_11 , 1 ) ;
F_102 ( V_26 , L_13 ) ;
V_18 = F_104 ( V_11 , V_107 ) ;
if ( V_18 )
return V_18 ;
}
F_102 ( V_26 , L_14 ) ;
F_105 ( & V_26 -> V_33 . V_108 , V_109 ) ;
F_102 ( V_26 , L_15 ) ;
if ( V_26 -> V_32 ) {
V_18 = F_19 ( V_26 -> V_32 ) ;
if ( V_18 )
goto V_110;
}
if ( V_26 -> V_27 ) {
V_18 = F_19 ( V_26 -> V_27 ) ;
if ( V_18 )
goto V_110;
}
F_102 ( V_26 , L_16 ) ;
if ( V_26 -> V_35 && F_24 ( V_26 ) -> V_111 ) {
if ( ! F_24 ( V_26 ) -> V_111 ( V_26 ) ) {
V_18 = - V_23 ;
goto V_110;
}
}
F_106 (cli, &drm->clients, head) {
V_18 = F_107 ( & V_16 -> V_21 ) ;
if ( V_18 )
goto V_112;
}
F_102 ( V_26 , L_17 ) ;
V_18 = F_107 ( & V_26 -> V_91 . V_21 ) ;
if ( V_18 )
goto V_112;
return 0 ;
V_112:
F_108 (cli, &drm->clients, head) {
F_109 ( & V_16 -> V_21 ) ;
}
if ( V_26 -> V_35 && F_24 ( V_26 ) -> V_113 )
F_24 ( V_26 ) -> V_113 ( V_26 ) ;
V_110:
if ( V_11 -> V_102 . V_103 ) {
F_102 ( V_26 , L_18 ) ;
F_110 ( V_11 , V_107 ) ;
}
return V_18 ;
}
static int
F_111 ( struct V_10 * V_11 , bool V_107 )
{
struct V_25 * V_26 = V_25 ( V_11 ) ;
struct V_15 * V_16 ;
F_102 ( V_26 , L_19 ) ;
F_109 ( & V_26 -> V_91 . V_21 ) ;
F_102 ( V_26 , L_20 ) ;
if ( V_26 -> V_35 && F_24 ( V_26 ) -> V_113 )
F_24 ( V_26 ) -> V_113 ( V_26 ) ;
F_106 (cli, &drm->clients, head) {
F_109 ( & V_16 -> V_21 ) ;
}
F_112 ( V_11 ) ;
if ( V_11 -> V_102 . V_103 ) {
F_102 ( V_26 , L_18 ) ;
F_110 ( V_11 , V_107 ) ;
F_102 ( V_26 , L_21 ) ;
F_103 ( V_11 , 0 ) ;
}
return 0 ;
}
int
F_113 ( struct V_37 * V_11 )
{
struct V_1 * V_2 = F_114 ( V_11 ) ;
struct V_10 * V_114 = F_100 ( V_2 ) ;
int V_18 ;
if ( V_114 -> V_115 == V_116 ||
V_114 -> V_115 == V_117 )
return 0 ;
V_18 = F_101 ( V_114 , false ) ;
if ( V_18 )
return V_18 ;
F_115 ( V_2 ) ;
F_116 ( V_2 ) ;
F_117 ( V_2 , V_118 ) ;
F_118 ( 200 ) ;
return 0 ;
}
int
F_119 ( struct V_37 * V_11 )
{
struct V_1 * V_2 = F_114 ( V_11 ) ;
struct V_10 * V_114 = F_100 ( V_2 ) ;
int V_18 ;
if ( V_114 -> V_115 == V_116 ||
V_114 -> V_115 == V_117 )
return 0 ;
F_117 ( V_2 , V_119 ) ;
F_120 ( V_2 ) ;
V_18 = F_121 ( V_2 ) ;
if ( V_18 )
return V_18 ;
F_55 ( V_2 ) ;
return F_111 ( V_114 , false ) ;
}
static int
F_122 ( struct V_37 * V_11 )
{
struct V_1 * V_2 = F_114 ( V_11 ) ;
struct V_10 * V_114 = F_100 ( V_2 ) ;
return F_101 ( V_114 , false ) ;
}
static int
F_123 ( struct V_37 * V_11 )
{
struct V_1 * V_2 = F_114 ( V_11 ) ;
struct V_10 * V_114 = F_100 ( V_2 ) ;
return F_111 ( V_114 , false ) ;
}
static int
F_124 ( struct V_37 * V_11 )
{
struct V_1 * V_2 = F_114 ( V_11 ) ;
struct V_10 * V_114 = F_100 ( V_2 ) ;
int V_18 ;
if ( V_105 == 0 ) {
F_125 ( V_11 ) ;
return - V_120 ;
}
if ( V_105 == - 1 && ! F_126 () && ! F_127 () ) {
F_128 ( L_22 ) ;
F_125 ( V_11 ) ;
return - V_120 ;
}
F_129 ( V_114 ) ;
F_130 ( V_2 , V_121 ) ;
F_131 () ;
V_18 = F_101 ( V_114 , true ) ;
F_115 ( V_2 ) ;
F_116 ( V_2 ) ;
F_132 ( V_2 ) ;
F_117 ( V_2 , V_122 ) ;
V_114 -> V_115 = V_117 ;
return V_18 ;
}
static int
F_133 ( struct V_37 * V_11 )
{
struct V_1 * V_2 = F_114 ( V_11 ) ;
struct V_10 * V_114 = F_100 ( V_2 ) ;
struct V_36 * V_37 = & V_25 ( V_114 ) -> V_37 ;
int V_18 ;
if ( V_105 == 0 )
return - V_123 ;
F_117 ( V_2 , V_119 ) ;
F_120 ( V_2 ) ;
V_18 = F_121 ( V_2 ) ;
if ( V_18 )
return V_18 ;
F_55 ( V_2 ) ;
V_18 = F_111 ( V_114 , true ) ;
F_134 ( V_114 ) ;
F_69 ( & V_37 -> V_45 , 0x088488 , ( 1 << 25 ) , ( 1 << 25 ) ) ;
F_130 ( V_2 , V_124 ) ;
V_114 -> V_115 = V_125 ;
return V_18 ;
}
static int
F_135 ( struct V_37 * V_11 )
{
struct V_1 * V_2 = F_114 ( V_11 ) ;
struct V_10 * V_114 = F_100 ( V_2 ) ;
struct V_25 * V_26 = V_25 ( V_114 ) ;
struct V_126 * V_127 ;
if ( V_105 == 0 ) {
F_125 ( V_11 ) ;
return - V_120 ;
}
if ( V_105 == - 1 && ! F_126 () && ! F_127 () ) {
F_128 ( L_22 ) ;
F_125 ( V_11 ) ;
return - V_120 ;
}
if ( V_26 -> V_87 ) {
if ( ! V_26 -> V_87 -> V_128 ) {
F_128 ( L_23 ) ;
F_83 ( V_11 ) ;
return - V_120 ;
}
}
F_106 (crtc, &drm->dev->mode_config.crtc_list, head) {
if ( V_127 -> V_129 ) {
F_128 ( L_24 ) ;
return - V_120 ;
}
}
F_83 ( V_11 ) ;
F_136 ( V_11 ) ;
return 1 ;
}
static int
F_137 ( struct V_10 * V_11 , struct V_130 * V_131 )
{
struct V_25 * V_26 = V_25 ( V_11 ) ;
struct V_15 * V_16 ;
char V_3 [ 32 ] , V_132 [ V_133 ] ;
int V_18 ;
V_18 = F_91 ( V_11 -> V_11 ) ;
if ( V_18 < 0 && V_18 != - V_134 )
return V_18 ;
F_138 ( V_132 , V_135 ) ;
snprintf ( V_3 , sizeof( V_3 ) , L_25 , V_132 , F_139 ( V_131 -> V_136 ) ) ;
V_18 = F_7 ( V_11 , V_3 , sizeof( * V_16 ) , ( void * * ) & V_16 ) ;
if ( V_18 )
goto V_137;
V_16 -> V_21 . V_138 = false ;
if ( V_26 -> V_37 . V_57 . V_58 >= V_98 ) {
V_18 = F_71 ( F_46 ( & V_26 -> V_37 ) , 0 , ( 1ULL << 40 ) ,
0x1000 , NULL , & V_16 -> V_24 ) ;
if ( V_18 ) {
F_12 ( V_16 ) ;
goto V_137;
}
F_14 ( & V_16 -> V_21 ) -> V_24 = V_16 -> V_24 ;
}
V_131 -> V_139 = V_16 ;
F_140 ( & V_26 -> V_91 . V_22 ) ;
F_141 ( & V_16 -> V_140 , & V_26 -> V_93 ) ;
F_142 ( & V_26 -> V_91 . V_22 ) ;
V_137:
F_83 ( V_11 -> V_11 ) ;
F_143 ( V_11 -> V_11 ) ;
return V_18 ;
}
static void
F_144 ( struct V_10 * V_11 , struct V_130 * V_131 )
{
struct V_15 * V_16 = V_15 ( V_131 ) ;
struct V_25 * V_26 = V_25 ( V_11 ) ;
F_91 ( V_11 -> V_11 ) ;
F_140 ( & V_16 -> V_22 ) ;
if ( V_16 -> V_141 )
F_145 ( V_16 -> V_141 ) ;
F_142 ( & V_16 -> V_22 ) ;
F_140 ( & V_26 -> V_91 . V_22 ) ;
F_146 ( & V_16 -> V_140 ) ;
F_142 ( & V_26 -> V_91 . V_22 ) ;
}
static void
F_147 ( struct V_10 * V_11 , struct V_130 * V_131 )
{
struct V_15 * V_16 = V_15 ( V_131 ) ;
F_12 ( V_16 ) ;
F_83 ( V_11 -> V_11 ) ;
F_143 ( V_11 -> V_11 ) ;
}
long
F_148 ( struct V_142 * V_142 , unsigned int V_143 , unsigned long V_144 )
{
struct V_130 * V_145 = V_142 -> V_146 ;
struct V_10 * V_11 = V_145 -> V_147 -> V_11 ;
long V_18 ;
V_18 = F_91 ( V_11 -> V_11 ) ;
if ( V_18 < 0 && V_18 != - V_134 )
return V_18 ;
switch ( F_149 ( V_143 ) - V_148 ) {
case V_149 :
V_18 = F_150 ( V_145 , ( void V_150 * ) V_144 , F_151 ( V_143 ) ) ;
break;
default:
V_18 = F_152 ( V_142 , V_143 , V_144 ) ;
break;
}
F_83 ( V_11 -> V_11 ) ;
F_143 ( V_11 -> V_11 ) ;
return V_18 ;
}
static void F_153 ( void )
{
F_128 ( L_26 ) ;
F_128 ( L_27 , V_151 ) ;
F_128 ( L_28 , V_152 ) ;
F_128 ( L_29 , V_153 ) ;
F_128 ( L_30 , V_154 ) ;
F_128 ( L_31 , V_19 ) ;
F_128 ( L_32 , V_20 ) ;
F_128 ( L_33 , V_44 ) ;
F_128 ( L_34 , V_85 ) ;
F_128 ( L_35 , V_105 ) ;
F_128 ( L_36 , V_155 ) ;
F_128 ( L_37 , V_156 ) ;
}
struct V_10 *
F_154 ( const struct V_157 * V_158 ,
struct V_7 * V_2 ,
struct V_75 * * V_159 )
{
struct V_10 * V_26 ;
int V_160 ;
V_160 = F_155 ( V_158 , V_2 , V_19 , V_20 ,
true , true , ~ 0ULL , V_159 ) ;
if ( V_160 )
goto V_161;
V_26 = F_156 ( & V_162 , & V_2 -> V_11 ) ;
if ( ! V_26 ) {
V_160 = - V_23 ;
goto V_161;
}
V_160 = F_157 ( V_26 , L_1 , F_158 ( & V_2 -> V_11 ) ) ;
if ( V_160 < 0 )
goto V_161;
V_26 -> V_8 = V_2 ;
F_159 ( V_2 , V_26 ) ;
return V_26 ;
V_161:
F_57 ( V_159 ) ;
return F_160 ( V_160 ) ;
}
static int T_3
F_161 ( void )
{
V_86 = V_163 ;
V_86 . V_164 = V_165 ;
V_162 = V_163 ;
V_162 . V_164 = V_166 ;
F_153 () ;
if ( V_85 == - 1 ) {
#ifdef F_162
if ( F_163 () )
V_85 = 0 ;
#endif
}
if ( ! V_85 )
return 0 ;
#ifdef F_164
F_165 ( & V_167 ) ;
#endif
F_166 () ;
return F_167 ( & V_86 , & V_168 ) ;
}
static void T_4
F_168 ( void )
{
if ( ! V_85 )
return;
F_169 ( & V_86 , & V_168 ) ;
F_170 () ;
#ifdef F_164
F_171 ( & V_167 ) ;
#endif
}

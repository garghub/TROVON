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
case V_57 :
case V_58 :
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
if ( V_37 -> V_59 . V_60 >= V_61 ) {
V_18 = F_36 ( V_26 , & V_26 -> V_37 ,
V_62 |
V_63 ,
0 , & V_26 -> V_32 ) ;
if ( V_18 )
F_35 ( V_26 , L_3 , V_18 ) ;
V_40 = V_64 ;
V_41 = 1 ;
} else
if ( V_37 -> V_59 . V_65 >= 0xa3 &&
V_37 -> V_59 . V_65 != 0xaa &&
V_37 -> V_59 . V_65 != 0xac ) {
V_18 = F_36 ( V_26 , & V_26 -> V_37 ,
V_66 , V_67 , & V_26 -> V_32 ) ;
if ( V_18 )
F_35 ( V_26 , L_3 , V_18 ) ;
V_40 = V_66 ;
V_41 = V_67 ;
} else {
V_40 = V_66 ;
V_41 = V_67 ;
}
V_18 = F_36 ( V_26 , & V_26 -> V_37 , V_40 , V_41 , & V_26 -> V_27 ) ;
if ( V_18 ) {
F_35 ( V_26 , L_4 , V_18 ) ;
F_18 ( V_26 ) ;
return;
}
V_18 = F_37 ( & V_26 -> V_27 -> V_68 , V_69 ,
F_38 ( V_26 ) , NULL , 0 , & V_26 -> V_31 ) ;
if ( V_18 == 0 ) {
V_18 = F_39 ( V_26 -> V_27 , 2 ) ;
if ( V_18 == 0 ) {
if ( V_37 -> V_59 . V_60 < V_70 ) {
F_40 ( V_26 -> V_27 , V_71 , 0 , 1 ) ;
F_41 ( V_26 -> V_27 , V_69 ) ;
} else
if ( V_37 -> V_59 . V_60 < V_61 ) {
F_42 ( V_26 -> V_27 , V_72 , 0 , 1 ) ;
F_41 ( V_26 -> V_27 , 0x001f0000 ) ;
}
}
V_18 = F_43 ( & V_26 -> V_31 , V_73 ,
false , V_74 ,
NULL , 0 , 0 , & V_26 -> V_30 ) ;
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
if ( V_37 -> V_59 . V_60 < V_70 ) {
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
const struct V_75 * V_76 )
{
struct V_77 * V_37 ;
struct V_78 * V_79 ;
bool V_80 = false ;
int V_18 ;
if ( F_49 ( V_2 ) )
return - V_81 ;
V_18 = F_50 ( V_2 , NULL , L_7 , true , false , 0 , & V_37 ) ;
if ( V_18 )
return V_18 ;
F_51 ( & V_37 ) ;
V_79 = F_52 ( 3 ) ;
if ( ! V_79 )
return - V_23 ;
V_79 -> V_82 [ 0 ] . V_21 = F_53 ( V_2 , 1 ) ;
V_79 -> V_82 [ 0 ] . V_13 = F_54 ( V_2 , 1 ) ;
V_79 -> V_83 = 1 ;
if ( F_54 ( V_2 , 2 ) ) {
V_79 -> V_82 [ V_79 -> V_83 ] . V_21 = F_53 ( V_2 , 2 ) ;
V_79 -> V_82 [ V_79 -> V_83 ] . V_13 = F_54 ( V_2 , 2 ) ;
V_79 -> V_83 ++ ;
}
if ( F_54 ( V_2 , 3 ) ) {
V_79 -> V_82 [ V_79 -> V_83 ] . V_21 = F_53 ( V_2 , 3 ) ;
V_79 -> V_82 [ V_79 -> V_83 ] . V_13 = F_54 ( V_2 , 3 ) ;
V_79 -> V_83 ++ ;
}
#ifdef F_55
V_80 = V_2 -> V_84 [ V_85 ] . V_86 & V_87 ;
#endif
if ( V_88 != 2 )
F_56 ( V_79 , L_8 , V_80 ) ;
F_17 ( V_79 ) ;
V_18 = F_50 ( V_2 , V_19 , V_20 ,
true , true , ~ 0ULL , & V_37 ) ;
if ( V_18 )
return V_18 ;
F_57 ( V_2 ) ;
V_18 = F_58 ( V_2 , V_76 , & V_89 ) ;
if ( V_18 ) {
F_51 ( & V_37 ) ;
return V_18 ;
}
return 0 ;
}
static void
F_59 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_11 -> V_2 ;
if ( ! V_2 ) {
F_60 ( V_26 , L_9 ) ;
V_26 -> V_90 = NULL ;
return;
}
V_26 -> V_90 = F_61 ( ( unsigned int ) V_2 -> V_4 -> V_5 ,
F_62 ( F_3 ( V_2 -> V_6 ) , 1 ) ) ;
if ( ! V_26 -> V_90 ) {
F_60 ( V_26 , L_10 , V_2 -> V_4 -> V_5 , F_3 ( V_2 -> V_6 ) , 1 ) ;
return;
}
if ( ( V_26 -> V_90 -> V_91 >> 8 ) != V_92 ) {
F_60 ( V_26 , L_11 , V_26 -> V_90 -> V_91 ) ;
F_63 ( V_26 -> V_90 ) ;
V_26 -> V_90 = NULL ;
return;
}
}
static int
F_64 ( struct V_10 * V_11 , unsigned long V_86 )
{
struct V_25 * V_26 ;
int V_18 ;
V_18 = F_7 ( V_11 , L_12 , sizeof( * V_26 ) , ( void * * ) & V_26 ) ;
if ( V_18 )
return V_18 ;
V_11 -> V_93 = V_26 ;
V_26 -> V_11 = V_11 ;
F_14 ( & V_26 -> V_94 . V_21 ) -> V_95 =
F_65 ( V_20 , L_12 ) ;
F_66 ( & V_26 -> V_96 ) ;
F_67 ( & V_26 -> V_97 . V_98 ) ;
F_59 ( V_26 ) ;
V_18 = F_68 (&drm->client.base.object, 0 , NV_DEVICE,
&(struct nv_device_v0) {
.device = ~0 ,
}, sizeof(struct nv_device_v0),
&drm->device) ;
if ( V_18 )
goto V_99;
V_11 -> V_100 = true ;
if ( V_26 -> V_37 . V_59 . V_65 == 0xc1 )
F_69 ( & V_26 -> V_37 . V_45 , 0x00088080 , 0x00000800 , 0x00000000 ) ;
F_70 ( V_26 ) ;
if ( V_26 -> V_37 . V_59 . V_60 >= V_101 ) {
if ( ! F_46 ( & V_26 -> V_37 ) -> V_102 ) {
V_18 = - V_46 ;
goto V_99;
}
V_18 = F_71 ( F_46 ( & V_26 -> V_37 ) , 0 , ( 1ULL << 40 ) ,
0x1000 , NULL , & V_26 -> V_94 . V_24 ) ;
if ( V_18 )
goto V_99;
F_14 ( & V_26 -> V_94 . V_21 ) -> V_24 = V_26 -> V_94 . V_24 ;
}
V_18 = F_72 ( V_26 ) ;
if ( V_18 )
goto V_103;
V_18 = F_73 ( V_11 ) ;
if ( V_18 )
goto V_104;
V_18 = F_74 ( V_11 ) ;
if ( V_18 )
goto V_105;
if ( V_11 -> V_106 . V_107 ) {
V_18 = F_75 ( V_11 ) ;
if ( V_18 )
goto V_108;
}
F_76 ( V_26 ) ;
F_77 ( V_11 ) ;
F_26 ( V_26 ) ;
F_78 ( V_11 ) ;
if ( V_109 != 0 ) {
F_79 ( V_11 -> V_11 ) ;
F_80 ( V_11 -> V_11 , 5000 ) ;
F_81 ( V_11 -> V_11 ) ;
F_82 ( V_11 -> V_11 ) ;
F_83 ( V_11 -> V_11 ) ;
F_84 ( V_11 -> V_11 ) ;
}
return 0 ;
V_108:
F_85 ( V_11 ) ;
V_105:
F_86 ( V_11 ) ;
V_104:
F_87 ( V_26 ) ;
V_103:
F_88 ( V_26 ) ;
V_99:
F_89 ( & V_26 -> V_37 ) ;
F_12 ( & V_26 -> V_94 ) ;
return V_18 ;
}
static int
F_90 ( struct V_10 * V_11 )
{
struct V_25 * V_26 = V_25 ( V_11 ) ;
if ( V_109 != 0 ) {
F_91 ( V_11 -> V_11 ) ;
F_92 ( V_11 -> V_11 ) ;
}
F_93 ( V_11 ) ;
F_18 ( V_26 ) ;
F_94 ( V_11 ) ;
F_95 ( V_26 ) ;
if ( V_11 -> V_106 . V_107 )
F_96 ( V_11 ) ;
F_85 ( V_11 ) ;
F_86 ( V_11 ) ;
F_87 ( V_26 ) ;
F_88 ( V_26 ) ;
F_89 ( & V_26 -> V_37 ) ;
if ( V_26 -> V_90 )
F_63 ( V_26 -> V_90 ) ;
F_12 ( & V_26 -> V_94 ) ;
return 0 ;
}
void
F_97 ( struct V_10 * V_11 )
{
struct V_25 * V_26 = V_25 ( V_11 ) ;
struct V_110 * V_94 ;
struct V_77 * V_37 ;
V_11 -> V_100 = false ;
V_94 = F_14 ( & V_26 -> V_94 . V_21 ) ;
V_37 = F_98 ( V_94 -> V_37 ) ;
F_99 ( V_11 ) ;
F_51 ( & V_37 ) ;
}
static void
F_100 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_101 ( V_2 ) ;
F_97 ( V_11 ) ;
}
static int
F_102 ( struct V_10 * V_11 , bool V_111 )
{
struct V_25 * V_26 = V_25 ( V_11 ) ;
struct V_15 * V_16 ;
int V_18 ;
if ( V_11 -> V_106 . V_107 ) {
F_103 ( V_26 , L_13 ) ;
F_104 ( V_11 , 1 ) ;
F_103 ( V_26 , L_14 ) ;
V_18 = F_105 ( V_11 , V_111 ) ;
if ( V_18 )
return V_18 ;
}
F_103 ( V_26 , L_15 ) ;
F_106 ( & V_26 -> V_33 . V_112 , V_113 ) ;
F_103 ( V_26 , L_16 ) ;
if ( V_26 -> V_32 ) {
V_18 = F_19 ( V_26 -> V_32 ) ;
if ( V_18 )
goto V_114;
}
if ( V_26 -> V_27 ) {
V_18 = F_19 ( V_26 -> V_27 ) ;
if ( V_18 )
goto V_114;
}
F_103 ( V_26 , L_17 ) ;
if ( V_26 -> V_35 && F_24 ( V_26 ) -> V_115 ) {
if ( ! F_24 ( V_26 ) -> V_115 ( V_26 ) ) {
V_18 = - V_23 ;
goto V_114;
}
}
F_107 (cli, &drm->clients, head) {
V_18 = F_108 ( & V_16 -> V_21 ) ;
if ( V_18 )
goto V_116;
}
F_103 ( V_26 , L_18 ) ;
V_18 = F_108 ( & V_26 -> V_94 . V_21 ) ;
if ( V_18 )
goto V_116;
return 0 ;
V_116:
F_109 (cli, &drm->clients, head) {
F_110 ( & V_16 -> V_21 ) ;
}
if ( V_26 -> V_35 && F_24 ( V_26 ) -> V_117 )
F_24 ( V_26 ) -> V_117 ( V_26 ) ;
V_114:
if ( V_11 -> V_106 . V_107 ) {
F_103 ( V_26 , L_19 ) ;
F_111 ( V_11 , V_111 ) ;
}
return V_18 ;
}
static int
F_112 ( struct V_10 * V_11 , bool V_111 )
{
struct V_25 * V_26 = V_25 ( V_11 ) ;
struct V_15 * V_16 ;
F_103 ( V_26 , L_20 ) ;
F_110 ( & V_26 -> V_94 . V_21 ) ;
F_103 ( V_26 , L_21 ) ;
if ( V_26 -> V_35 && F_24 ( V_26 ) -> V_117 )
F_24 ( V_26 ) -> V_117 ( V_26 ) ;
F_107 (cli, &drm->clients, head) {
F_110 ( & V_16 -> V_21 ) ;
}
F_113 ( V_11 ) ;
if ( V_11 -> V_106 . V_107 ) {
F_103 ( V_26 , L_19 ) ;
F_111 ( V_11 , V_111 ) ;
F_103 ( V_26 , L_22 ) ;
F_104 ( V_11 , 0 ) ;
}
return 0 ;
}
int
F_114 ( struct V_37 * V_11 )
{
struct V_1 * V_2 = F_115 ( V_11 ) ;
struct V_10 * V_118 = F_101 ( V_2 ) ;
int V_18 ;
if ( V_118 -> V_119 == V_120 ||
V_118 -> V_119 == V_121 )
return 0 ;
V_18 = F_102 ( V_118 , false ) ;
if ( V_18 )
return V_18 ;
F_116 ( V_2 ) ;
F_117 ( V_2 ) ;
F_118 ( V_2 , V_122 ) ;
F_119 ( 200 ) ;
return 0 ;
}
int
F_120 ( struct V_37 * V_11 )
{
struct V_1 * V_2 = F_115 ( V_11 ) ;
struct V_10 * V_118 = F_101 ( V_2 ) ;
int V_18 ;
if ( V_118 -> V_119 == V_120 ||
V_118 -> V_119 == V_121 )
return 0 ;
F_118 ( V_2 , V_123 ) ;
F_121 ( V_2 ) ;
V_18 = F_122 ( V_2 ) ;
if ( V_18 )
return V_18 ;
F_57 ( V_2 ) ;
return F_112 ( V_118 , false ) ;
}
static int
F_123 ( struct V_37 * V_11 )
{
struct V_1 * V_2 = F_115 ( V_11 ) ;
struct V_10 * V_118 = F_101 ( V_2 ) ;
return F_102 ( V_118 , false ) ;
}
static int
F_124 ( struct V_37 * V_11 )
{
struct V_1 * V_2 = F_115 ( V_11 ) ;
struct V_10 * V_118 = F_101 ( V_2 ) ;
return F_112 ( V_118 , false ) ;
}
static int
F_125 ( struct V_37 * V_11 )
{
struct V_1 * V_2 = F_115 ( V_11 ) ;
struct V_10 * V_118 = F_101 ( V_2 ) ;
int V_18 ;
if ( V_109 == 0 ) {
F_92 ( V_11 ) ;
return - V_124 ;
}
if ( V_109 == - 1 && ! F_126 () && ! F_127 () ) {
F_128 ( L_23 ) ;
F_92 ( V_11 ) ;
return - V_124 ;
}
F_129 ( V_118 ) ;
F_130 ( V_2 , V_125 ) ;
F_131 () ;
V_18 = F_102 ( V_118 , true ) ;
F_116 ( V_2 ) ;
F_117 ( V_2 ) ;
F_132 ( V_2 ) ;
F_118 ( V_2 , V_126 ) ;
V_118 -> V_119 = V_121 ;
return V_18 ;
}
static int
F_133 ( struct V_37 * V_11 )
{
struct V_1 * V_2 = F_115 ( V_11 ) ;
struct V_10 * V_118 = F_101 ( V_2 ) ;
struct V_36 * V_37 = & V_25 ( V_118 ) -> V_37 ;
int V_18 ;
if ( V_109 == 0 )
return - V_127 ;
F_118 ( V_2 , V_123 ) ;
F_121 ( V_2 ) ;
V_18 = F_122 ( V_2 ) ;
if ( V_18 )
return V_18 ;
F_57 ( V_2 ) ;
V_18 = F_112 ( V_118 , true ) ;
F_134 ( V_118 ) ;
F_69 ( & V_37 -> V_45 , 0x088488 , ( 1 << 25 ) , ( 1 << 25 ) ) ;
F_130 ( V_2 , V_128 ) ;
V_118 -> V_119 = V_129 ;
return V_18 ;
}
static int
F_135 ( struct V_37 * V_11 )
{
struct V_1 * V_2 = F_115 ( V_11 ) ;
struct V_10 * V_118 = F_101 ( V_2 ) ;
struct V_25 * V_26 = V_25 ( V_118 ) ;
struct V_130 * V_131 ;
if ( V_109 == 0 ) {
F_92 ( V_11 ) ;
return - V_124 ;
}
if ( V_109 == - 1 && ! F_126 () && ! F_127 () ) {
F_128 ( L_23 ) ;
F_92 ( V_11 ) ;
return - V_124 ;
}
if ( V_26 -> V_90 ) {
if ( ! V_26 -> V_90 -> V_132 ) {
F_128 ( L_24 ) ;
F_83 ( V_11 ) ;
return - V_124 ;
}
}
F_107 (crtc, &drm->dev->mode_config.crtc_list, head) {
if ( V_131 -> V_133 ) {
F_128 ( L_25 ) ;
return - V_124 ;
}
}
F_83 ( V_11 ) ;
F_136 ( V_11 ) ;
return 1 ;
}
static int
F_137 ( struct V_10 * V_11 , struct V_134 * V_135 )
{
struct V_25 * V_26 = V_25 ( V_11 ) ;
struct V_15 * V_16 ;
char V_3 [ 32 ] , V_136 [ V_137 ] ;
int V_18 ;
V_18 = F_91 ( V_11 -> V_11 ) ;
if ( V_18 < 0 && V_18 != - V_138 )
return V_18 ;
F_138 ( V_136 , V_139 ) ;
snprintf ( V_3 , sizeof( V_3 ) , L_26 , V_136 , F_139 ( V_135 -> V_140 ) ) ;
V_18 = F_7 ( V_11 , V_3 , sizeof( * V_16 ) , ( void * * ) & V_16 ) ;
if ( V_18 )
goto V_141;
V_16 -> V_21 . V_142 = false ;
if ( V_26 -> V_37 . V_59 . V_60 >= V_101 ) {
V_18 = F_71 ( F_46 ( & V_26 -> V_37 ) , 0 , ( 1ULL << 40 ) ,
0x1000 , NULL , & V_16 -> V_24 ) ;
if ( V_18 ) {
F_12 ( V_16 ) ;
goto V_141;
}
F_14 ( & V_16 -> V_21 ) -> V_24 = V_16 -> V_24 ;
}
V_135 -> V_143 = V_16 ;
F_140 ( & V_26 -> V_94 . V_22 ) ;
F_141 ( & V_16 -> V_144 , & V_26 -> V_96 ) ;
F_142 ( & V_26 -> V_94 . V_22 ) ;
V_141:
F_83 ( V_11 -> V_11 ) ;
F_143 ( V_11 -> V_11 ) ;
return V_18 ;
}
static void
F_144 ( struct V_10 * V_11 , struct V_134 * V_135 )
{
struct V_15 * V_16 = V_15 ( V_135 ) ;
struct V_25 * V_26 = V_25 ( V_11 ) ;
F_91 ( V_11 -> V_11 ) ;
F_140 ( & V_16 -> V_22 ) ;
if ( V_16 -> V_145 )
F_145 ( V_16 -> V_145 ) ;
F_142 ( & V_16 -> V_22 ) ;
F_140 ( & V_26 -> V_94 . V_22 ) ;
F_146 ( & V_16 -> V_144 ) ;
F_142 ( & V_26 -> V_94 . V_22 ) ;
}
static void
F_147 ( struct V_10 * V_11 , struct V_134 * V_135 )
{
struct V_15 * V_16 = V_15 ( V_135 ) ;
F_12 ( V_16 ) ;
F_83 ( V_11 -> V_11 ) ;
F_143 ( V_11 -> V_11 ) ;
}
long
F_148 ( struct V_146 * V_146 , unsigned int V_147 , unsigned long V_148 )
{
struct V_134 * V_149 = V_146 -> V_150 ;
struct V_10 * V_11 = V_149 -> V_151 -> V_11 ;
long V_18 ;
V_18 = F_91 ( V_11 -> V_11 ) ;
if ( V_18 < 0 && V_18 != - V_138 )
return V_18 ;
switch ( F_149 ( V_147 ) - V_152 ) {
case V_153 :
V_18 = F_150 ( V_149 , ( void V_154 * ) V_148 , F_151 ( V_147 ) ) ;
break;
default:
V_18 = F_152 ( V_146 , V_147 , V_148 ) ;
break;
}
F_83 ( V_11 -> V_11 ) ;
F_143 ( V_11 -> V_11 ) ;
return V_18 ;
}
static void F_153 ( void )
{
F_128 ( L_27 ) ;
F_128 ( L_28 , V_155 ) ;
F_128 ( L_29 , V_156 ) ;
F_128 ( L_30 , V_157 ) ;
F_128 ( L_31 , V_158 ) ;
F_128 ( L_32 , V_19 ) ;
F_128 ( L_33 , V_20 ) ;
F_128 ( L_34 , V_44 ) ;
F_128 ( L_35 , V_88 ) ;
F_128 ( L_36 , V_109 ) ;
F_128 ( L_37 , V_159 ) ;
}
struct V_10 *
F_154 ( const struct V_160 * V_161 ,
struct V_7 * V_2 ,
struct V_77 * * V_162 )
{
struct V_10 * V_26 ;
int V_163 ;
V_163 = F_155 ( V_161 , V_2 , V_19 , V_20 ,
true , true , ~ 0ULL , V_162 ) ;
if ( V_163 )
goto V_164;
V_26 = F_156 ( & V_165 , & V_2 -> V_11 ) ;
if ( ! V_26 ) {
V_163 = - V_23 ;
goto V_164;
}
V_26 -> V_8 = V_2 ;
F_157 ( V_2 , V_26 ) ;
return V_26 ;
V_164:
F_51 ( V_162 ) ;
return F_158 ( V_163 ) ;
}
static int T_3
F_159 ( void )
{
V_89 = V_166 ;
V_89 . V_167 = V_168 ;
V_165 = V_166 ;
F_153 () ;
if ( V_88 == - 1 ) {
if ( F_160 () )
V_88 = 0 ;
}
if ( ! V_88 )
return 0 ;
#ifdef F_161
F_162 ( & V_169 ) ;
#endif
F_163 () ;
return F_164 ( & V_89 , & V_170 ) ;
}
static void T_4
F_165 ( void )
{
if ( ! V_88 )
return;
F_166 ( & V_89 , & V_170 ) ;
F_167 () ;
#ifdef F_161
F_168 ( & V_169 ) ;
#endif
}

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
static void
F_7 ( struct V_12 * V_13 )
{
F_8 ( NULL , & F_9 ( & V_13 -> V_14 ) -> V_15 , NULL ) ;
F_10 ( V_13 ) ;
F_11 ( & V_13 -> V_16 ) ;
F_12 ( & V_13 -> V_14 ) ;
}
static int
F_13 ( struct V_17 * V_18 , const char * V_19 ,
struct V_12 * V_13 )
{
T_1 V_16 = F_6 ( V_18 -> V_11 ) ;
int V_20 ;
snprintf ( V_13 -> V_3 , sizeof( V_13 -> V_3 ) , L_1 , V_19 ) ;
V_13 -> V_11 = V_18 -> V_11 ;
F_14 ( & V_13 -> V_21 ) ;
F_15 ( V_13 ) ;
if ( V_13 == & V_18 -> V_22 ) {
V_20 = F_16 ( NULL , V_23 , V_24 ,
V_13 -> V_3 , V_16 , & V_13 -> V_14 ) ;
} else {
V_20 = F_17 ( & V_18 -> V_22 . V_14 , V_13 -> V_3 , V_16 ,
& V_13 -> V_14 ) ;
}
if ( V_20 ) {
F_18 ( V_18 , L_2 , V_20 ) ;
goto V_25;
}
V_20 = F_19 (&cli->base.object, 0 , NV_DEVICE,
&(struct nv_device_v0) {
.device = ~0 ,
}, sizeof(struct nv_device_v0),
&cli->device) ;
if ( V_20 ) {
F_18 ( V_18 , L_3 , V_20 ) ;
goto V_25;
}
V_25:
if ( V_20 )
F_7 ( V_13 ) ;
return V_20 ;
}
static void
F_20 ( struct V_17 * V_18 )
{
F_21 ( V_18 -> V_26 ) ;
F_22 ( & V_18 -> V_27 ) ;
F_23 ( & V_18 -> V_28 ) ;
F_24 ( & V_18 -> V_29 ) ;
F_22 ( & V_18 -> V_30 ) ;
F_25 ( & V_18 -> V_26 ) ;
F_21 ( V_18 -> V_31 ) ;
F_22 ( & V_18 -> V_32 . V_33 ) ;
F_25 ( & V_18 -> V_31 ) ;
if ( V_18 -> V_34 )
F_26 ( V_18 ) -> F_27 ( V_18 ) ;
}
static void
F_28 ( struct V_17 * V_18 )
{
struct V_35 * V_16 = & V_18 -> V_22 . V_16 ;
struct V_36 * V_37 ;
T_2 V_38 , V_39 ;
int V_20 , V_40 , V_41 ;
if ( V_42 )
return;
V_20 = V_41 = F_29 ( & V_16 -> V_43 , & V_37 ) ;
if ( V_20 < 0 )
return;
for ( V_20 = - V_44 , V_40 = 0 ; V_40 < V_41 ; V_40 ++ ) {
switch ( V_37 [ V_40 ] . V_45 ) {
case V_46 :
V_20 = F_30 ( V_18 ) ;
break;
case V_47 :
V_20 = F_31 ( V_18 ) ;
break;
case V_48 :
case V_49 :
V_20 = F_32 ( V_18 ) ;
break;
case V_50 :
V_20 = F_33 ( V_18 ) ;
break;
case V_51 :
V_20 = F_34 ( V_18 ) ;
break;
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
V_20 = F_35 ( V_18 ) ;
break;
default:
break;
}
}
F_36 ( & V_37 ) ;
if ( V_20 ) {
F_18 ( V_18 , L_4 , V_20 ) ;
F_20 ( V_18 ) ;
return;
}
if ( V_16 -> V_57 . V_58 >= V_59 ) {
V_20 = F_37 ( V_18 , & V_18 -> V_22 . V_16 ,
V_60 |
V_61 ,
0 , & V_18 -> V_31 ) ;
if ( V_20 )
F_18 ( V_18 , L_5 , V_20 ) ;
V_38 = V_62 ;
V_39 = 1 ;
} else
if ( V_16 -> V_57 . V_63 >= 0xa3 &&
V_16 -> V_57 . V_63 != 0xaa &&
V_16 -> V_57 . V_63 != 0xac ) {
V_20 = F_37 ( V_18 , & V_18 -> V_22 . V_16 ,
V_64 , V_65 , & V_18 -> V_31 ) ;
if ( V_20 )
F_18 ( V_18 , L_5 , V_20 ) ;
V_38 = V_64 ;
V_39 = V_65 ;
} else {
V_38 = V_64 ;
V_39 = V_65 ;
}
V_20 = F_37 ( V_18 , & V_18 -> V_22 . V_16 ,
V_38 , V_39 , & V_18 -> V_26 ) ;
if ( V_20 ) {
F_18 ( V_18 , L_6 , V_20 ) ;
F_20 ( V_18 ) ;
return;
}
V_20 = F_38 ( & V_18 -> V_26 -> V_66 , V_67 ,
F_39 ( V_18 ) , NULL , 0 , & V_18 -> V_30 ) ;
if ( V_20 == 0 ) {
V_20 = F_40 ( V_18 -> V_26 , 2 ) ;
if ( V_20 == 0 ) {
if ( V_16 -> V_57 . V_58 < V_68 ) {
F_41 ( V_18 -> V_26 , V_69 , 0 , 1 ) ;
F_42 ( V_18 -> V_26 , V_67 ) ;
} else
if ( V_16 -> V_57 . V_58 < V_59 ) {
F_43 ( V_18 -> V_26 , V_70 , 0 , 1 ) ;
F_42 ( V_18 -> V_26 , 0x001f0000 ) ;
}
}
V_20 = F_44 ( & V_18 -> V_30 , V_71 ,
false , V_72 ,
NULL , 0 , 0 , & V_18 -> V_29 ) ;
if ( V_20 == 0 )
V_20 = F_45 ( & V_18 -> V_29 ) ;
if ( V_20 ) {
F_20 ( V_18 ) ;
return;
}
}
if ( V_20 ) {
F_18 ( V_18 , L_7 , V_20 ) ;
F_20 ( V_18 ) ;
return;
}
if ( V_16 -> V_57 . V_58 < V_68 ) {
V_20 = F_46 ( F_47 ( & V_18 -> V_22 . V_16 ) , 32 , 0 ,
false , NULL , & V_18 -> V_28 ) ;
if ( V_20 ) {
F_18 ( V_18 , L_8 , V_20 ) ;
F_20 ( V_18 ) ;
return;
}
V_20 = F_38 (&drm->channel->user, NvNotify0,
NV_DMA_IN_MEMORY,
&(struct nv_dma_v0) {
.target = NV_DMA_V0_TARGET_VRAM,
.access = NV_DMA_V0_ACCESS_RDWR,
.start = drm->notify->addr,
.limit = drm->notify->addr + 31
}, sizeof(struct nv_dma_v0),
&drm->ntfy) ;
if ( V_20 ) {
F_20 ( V_18 ) ;
return;
}
}
F_48 ( V_18 ) ;
}
static int F_49 ( struct V_1 * V_2 ,
const struct V_73 * V_74 )
{
struct V_75 * V_16 ;
struct V_76 * V_77 ;
bool V_78 = false ;
int V_20 ;
if ( F_50 ( V_2 ) )
return - V_79 ;
V_20 = F_51 ( V_2 , NULL , L_9 , true , false , 0 , & V_16 ) ;
if ( V_20 )
return V_20 ;
F_52 ( & V_16 ) ;
V_77 = F_53 ( 3 ) ;
if ( ! V_77 )
return - V_80 ;
V_77 -> V_81 [ 0 ] . V_14 = F_54 ( V_2 , 1 ) ;
V_77 -> V_81 [ 0 ] . V_82 = F_55 ( V_2 , 1 ) ;
V_77 -> V_83 = 1 ;
if ( F_55 ( V_2 , 2 ) ) {
V_77 -> V_81 [ V_77 -> V_83 ] . V_14 = F_54 ( V_2 , 2 ) ;
V_77 -> V_81 [ V_77 -> V_83 ] . V_82 = F_55 ( V_2 , 2 ) ;
V_77 -> V_83 ++ ;
}
if ( F_55 ( V_2 , 3 ) ) {
V_77 -> V_81 [ V_77 -> V_83 ] . V_14 = F_54 ( V_2 , 3 ) ;
V_77 -> V_81 [ V_77 -> V_83 ] . V_82 = F_55 ( V_2 , 3 ) ;
V_77 -> V_83 ++ ;
}
#ifdef F_56
V_78 = V_2 -> V_84 [ V_85 ] . V_86 & V_87 ;
#endif
if ( V_88 != 2 )
F_57 ( V_77 , L_10 , V_78 ) ;
F_58 ( V_77 ) ;
V_20 = F_51 ( V_2 , V_23 , V_24 ,
true , true , ~ 0ULL , & V_16 ) ;
if ( V_20 )
return V_20 ;
F_59 ( V_2 ) ;
V_20 = F_60 ( V_2 , V_74 , & V_89 ) ;
if ( V_20 ) {
F_52 ( & V_16 ) ;
return V_20 ;
}
return 0 ;
}
static void
F_61 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_11 -> V_2 ;
if ( ! V_2 ) {
F_62 ( V_18 , L_11 ) ;
V_18 -> V_90 = NULL ;
return;
}
V_18 -> V_90 = F_63 ( ( unsigned int ) V_2 -> V_4 -> V_5 ,
F_64 ( F_3 ( V_2 -> V_6 ) , 1 ) ) ;
if ( ! V_18 -> V_90 ) {
F_62 ( V_18 , L_12 , V_2 -> V_4 -> V_5 , F_3 ( V_2 -> V_6 ) , 1 ) ;
return;
}
if ( ( V_18 -> V_90 -> V_91 >> 8 ) != V_92 ) {
F_62 ( V_18 , L_13 , V_18 -> V_90 -> V_91 ) ;
F_65 ( V_18 -> V_90 ) ;
V_18 -> V_90 = NULL ;
return;
}
}
static int
F_66 ( struct V_10 * V_11 , unsigned long V_86 )
{
struct V_17 * V_18 ;
int V_20 ;
if ( ! ( V_18 = F_67 ( sizeof( * V_18 ) , V_93 ) ) )
return - V_80 ;
V_11 -> V_94 = V_18 ;
V_18 -> V_11 = V_11 ;
V_20 = F_13 ( V_18 , L_14 , & V_18 -> V_22 ) ;
if ( V_20 )
return V_20 ;
V_11 -> V_95 = true ;
F_9 ( & V_18 -> V_22 . V_14 ) -> V_96 =
F_68 ( V_24 , L_14 ) ;
F_69 ( & V_18 -> V_97 ) ;
F_70 ( & V_18 -> V_98 . V_99 ) ;
F_61 ( V_18 ) ;
if ( V_18 -> V_22 . V_16 . V_57 . V_63 == 0xc1 )
F_71 ( & V_18 -> V_22 . V_16 . V_43 , 0x00088080 , 0x00000800 , 0x00000000 ) ;
F_72 ( V_18 ) ;
if ( V_18 -> V_22 . V_16 . V_57 . V_58 >= V_100 ) {
if ( ! F_47 ( & V_18 -> V_22 . V_16 ) -> V_101 ) {
V_20 = - V_44 ;
goto V_102;
}
V_20 = F_73 ( F_47 ( & V_18 -> V_22 . V_16 ) ,
0 , ( 1ULL << 40 ) , 0x1000 , NULL ,
& V_18 -> V_22 . V_15 ) ;
if ( V_20 )
goto V_102;
F_9 ( & V_18 -> V_22 . V_14 ) -> V_15 = V_18 -> V_22 . V_15 ;
}
V_20 = F_74 ( V_18 ) ;
if ( V_20 )
goto V_103;
V_20 = F_75 ( V_11 ) ;
if ( V_20 )
goto V_104;
V_20 = F_76 ( V_11 ) ;
if ( V_20 )
goto V_105;
if ( V_11 -> V_106 . V_107 ) {
V_20 = F_77 ( V_11 ) ;
if ( V_20 )
goto V_108;
}
F_78 ( V_18 ) ;
F_79 ( V_11 ) ;
F_28 ( V_18 ) ;
F_80 ( V_11 ) ;
F_81 ( V_11 ) ;
if ( V_109 != 0 ) {
F_82 ( V_11 -> V_11 ) ;
F_83 ( V_11 -> V_11 , 5000 ) ;
F_84 ( V_11 -> V_11 ) ;
F_85 ( V_11 -> V_11 ) ;
F_86 ( V_11 -> V_11 ) ;
F_87 ( V_11 -> V_11 ) ;
}
return 0 ;
V_108:
F_88 ( V_11 ) ;
V_105:
F_89 ( V_11 ) ;
V_104:
F_90 ( V_18 ) ;
V_103:
F_91 ( V_18 ) ;
V_102:
F_7 ( & V_18 -> V_22 ) ;
F_58 ( V_18 ) ;
return V_20 ;
}
static void
F_92 ( struct V_10 * V_11 )
{
struct V_17 * V_18 = V_17 ( V_11 ) ;
if ( V_109 != 0 ) {
F_93 ( V_11 -> V_11 ) ;
F_94 ( V_11 -> V_11 ) ;
}
F_95 ( V_11 ) ;
F_96 ( V_11 ) ;
F_20 ( V_18 ) ;
F_97 ( V_11 ) ;
F_98 ( V_18 ) ;
if ( V_11 -> V_106 . V_107 )
F_99 ( V_11 , false ) ;
F_88 ( V_11 ) ;
F_89 ( V_11 ) ;
F_90 ( V_18 ) ;
F_91 ( V_18 ) ;
if ( V_18 -> V_90 )
F_65 ( V_18 -> V_90 ) ;
F_7 ( & V_18 -> V_22 ) ;
F_58 ( V_18 ) ;
}
void
F_100 ( struct V_10 * V_11 )
{
struct V_17 * V_18 = V_17 ( V_11 ) ;
struct V_110 * V_22 ;
struct V_75 * V_16 ;
V_11 -> V_95 = false ;
V_22 = F_9 ( & V_18 -> V_22 . V_14 ) ;
V_16 = F_101 ( V_22 -> V_16 ) ;
F_102 ( V_11 ) ;
F_52 ( & V_16 ) ;
}
static void
F_103 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_104 ( V_2 ) ;
F_100 ( V_11 ) ;
}
static int
F_105 ( struct V_10 * V_11 , bool V_111 )
{
struct V_17 * V_18 = V_17 ( V_11 ) ;
int V_20 ;
F_106 ( V_11 ) ;
if ( V_11 -> V_106 . V_107 ) {
F_107 ( V_18 , L_15 ) ;
F_108 ( V_11 , 1 ) ;
F_107 ( V_18 , L_16 ) ;
V_20 = F_109 ( V_11 , V_111 ) ;
if ( V_20 )
return V_20 ;
}
F_107 ( V_18 , L_17 ) ;
F_110 ( & V_18 -> V_32 . V_112 , V_113 ) ;
F_107 ( V_18 , L_18 ) ;
if ( V_18 -> V_31 ) {
V_20 = F_21 ( V_18 -> V_31 ) ;
if ( V_20 )
goto V_114;
}
if ( V_18 -> V_26 ) {
V_20 = F_21 ( V_18 -> V_26 ) ;
if ( V_20 )
goto V_114;
}
F_107 ( V_18 , L_19 ) ;
if ( V_18 -> V_34 && F_26 ( V_18 ) -> V_115 ) {
if ( ! F_26 ( V_18 ) -> V_115 ( V_18 ) ) {
V_20 = - V_80 ;
goto V_114;
}
}
F_107 ( V_18 , L_20 ) ;
V_20 = F_111 ( & V_18 -> V_22 . V_14 ) ;
if ( V_20 )
goto V_116;
return 0 ;
V_116:
if ( V_18 -> V_34 && F_26 ( V_18 ) -> V_117 )
F_26 ( V_18 ) -> V_117 ( V_18 ) ;
V_114:
if ( V_11 -> V_106 . V_107 ) {
F_107 ( V_18 , L_21 ) ;
F_112 ( V_11 , V_111 ) ;
}
return V_20 ;
}
static int
F_113 ( struct V_10 * V_11 , bool V_111 )
{
struct V_17 * V_18 = V_17 ( V_11 ) ;
F_107 ( V_18 , L_22 ) ;
F_114 ( & V_18 -> V_22 . V_14 ) ;
F_107 ( V_18 , L_23 ) ;
if ( V_18 -> V_34 && F_26 ( V_18 ) -> V_117 )
F_26 ( V_18 ) -> V_117 ( V_18 ) ;
F_115 ( V_11 ) ;
if ( V_11 -> V_106 . V_107 ) {
F_107 ( V_18 , L_21 ) ;
F_112 ( V_11 , V_111 ) ;
F_107 ( V_18 , L_24 ) ;
F_108 ( V_11 , 0 ) ;
}
F_116 ( V_11 ) ;
return 0 ;
}
int
F_117 ( struct V_16 * V_11 )
{
struct V_1 * V_2 = F_118 ( V_11 ) ;
struct V_10 * V_118 = F_104 ( V_2 ) ;
int V_20 ;
if ( V_118 -> V_119 == V_120 ||
V_118 -> V_119 == V_121 )
return 0 ;
V_20 = F_105 ( V_118 , false ) ;
if ( V_20 )
return V_20 ;
F_119 ( V_2 ) ;
F_120 ( V_2 ) ;
F_121 ( V_2 , V_122 ) ;
F_122 ( 200 ) ;
return 0 ;
}
int
F_123 ( struct V_16 * V_11 )
{
struct V_1 * V_2 = F_118 ( V_11 ) ;
struct V_10 * V_118 = F_104 ( V_2 ) ;
int V_20 ;
if ( V_118 -> V_119 == V_120 ||
V_118 -> V_119 == V_121 )
return 0 ;
F_121 ( V_2 , V_123 ) ;
F_124 ( V_2 ) ;
V_20 = F_125 ( V_2 ) ;
if ( V_20 )
return V_20 ;
F_59 ( V_2 ) ;
V_20 = F_113 ( V_118 , false ) ;
F_126 ( & V_17 ( V_118 ) -> V_124 ) ;
return V_20 ;
}
static int
F_127 ( struct V_16 * V_11 )
{
struct V_1 * V_2 = F_118 ( V_11 ) ;
struct V_10 * V_118 = F_104 ( V_2 ) ;
return F_105 ( V_118 , false ) ;
}
static int
F_128 ( struct V_16 * V_11 )
{
struct V_1 * V_2 = F_118 ( V_11 ) ;
struct V_10 * V_118 = F_104 ( V_2 ) ;
return F_113 ( V_118 , false ) ;
}
static int
F_129 ( struct V_16 * V_11 )
{
struct V_1 * V_2 = F_118 ( V_11 ) ;
struct V_10 * V_118 = F_104 ( V_2 ) ;
int V_20 ;
if ( V_109 == 0 ) {
F_94 ( V_11 ) ;
return - V_125 ;
}
if ( V_109 == - 1 && ! F_130 () && ! F_131 () ) {
F_132 ( L_25 ) ;
F_94 ( V_11 ) ;
return - V_125 ;
}
F_133 ( V_118 ) ;
F_134 ( V_2 , V_126 ) ;
F_135 () ;
V_20 = F_105 ( V_118 , true ) ;
F_119 ( V_2 ) ;
F_120 ( V_2 ) ;
F_136 ( V_2 ) ;
F_121 ( V_2 , V_127 ) ;
V_118 -> V_119 = V_121 ;
return V_20 ;
}
static int
F_137 ( struct V_16 * V_11 )
{
struct V_1 * V_2 = F_118 ( V_11 ) ;
struct V_10 * V_118 = F_104 ( V_2 ) ;
struct V_35 * V_16 = & V_17 ( V_118 ) -> V_22 . V_16 ;
int V_20 ;
if ( V_109 == 0 )
return - V_128 ;
F_121 ( V_2 , V_123 ) ;
F_124 ( V_2 ) ;
V_20 = F_125 ( V_2 ) ;
if ( V_20 )
return V_20 ;
F_59 ( V_2 ) ;
V_20 = F_113 ( V_118 , true ) ;
if ( ! V_118 -> V_106 . V_129 )
F_138 ( V_118 ) ;
F_71 ( & V_16 -> V_43 , 0x088488 , ( 1 << 25 ) , ( 1 << 25 ) ) ;
F_134 ( V_2 , V_130 ) ;
V_118 -> V_119 = V_131 ;
F_126 ( & V_17 ( V_118 ) -> V_124 ) ;
return V_20 ;
}
static int
F_139 ( struct V_16 * V_11 )
{
struct V_1 * V_2 = F_118 ( V_11 ) ;
struct V_10 * V_118 = F_104 ( V_2 ) ;
struct V_17 * V_18 = V_17 ( V_118 ) ;
struct V_132 * V_133 ;
if ( V_109 == 0 ) {
F_94 ( V_11 ) ;
return - V_125 ;
}
if ( V_109 == - 1 && ! F_130 () && ! F_131 () ) {
F_132 ( L_25 ) ;
F_94 ( V_11 ) ;
return - V_125 ;
}
if ( V_18 -> V_90 ) {
if ( ! V_18 -> V_90 -> V_134 ) {
F_132 ( L_26 ) ;
F_86 ( V_11 ) ;
return - V_125 ;
}
}
F_140 (crtc, &drm->dev->mode_config.crtc_list, head) {
if ( V_133 -> V_135 ) {
F_132 ( L_27 ) ;
return - V_125 ;
}
}
F_86 ( V_11 ) ;
F_141 ( V_11 ) ;
return 1 ;
}
static int
F_142 ( struct V_10 * V_11 , struct V_136 * V_137 )
{
struct V_17 * V_18 = V_17 ( V_11 ) ;
struct V_12 * V_13 ;
char V_3 [ 32 ] , V_138 [ V_139 ] ;
int V_20 ;
V_20 = F_93 ( V_11 -> V_11 ) ;
if ( V_20 < 0 && V_20 != - V_140 )
return V_20 ;
F_143 ( V_138 , V_141 ) ;
snprintf ( V_3 , sizeof( V_3 ) , L_28 , V_138 , F_144 ( V_137 -> V_142 ) ) ;
if ( ! ( V_13 = F_67 ( sizeof( * V_13 ) , V_93 ) ) )
return V_20 ;
V_20 = F_13 ( V_18 , V_3 , V_13 ) ;
if ( V_20 )
goto V_25;
V_13 -> V_14 . V_143 = false ;
if ( V_18 -> V_22 . V_16 . V_57 . V_58 >= V_100 ) {
V_20 = F_73 ( F_47 ( & V_18 -> V_22 . V_16 ) , 0 ,
( 1ULL << 40 ) , 0x1000 , NULL , & V_13 -> V_15 ) ;
if ( V_20 )
goto V_25;
F_9 ( & V_13 -> V_14 ) -> V_15 = V_13 -> V_15 ;
}
V_137 -> V_144 = V_13 ;
F_145 ( & V_18 -> V_22 . V_21 ) ;
F_146 ( & V_13 -> V_145 , & V_18 -> V_97 ) ;
F_147 ( & V_18 -> V_22 . V_21 ) ;
V_25:
if ( V_20 && V_13 ) {
F_7 ( V_13 ) ;
F_58 ( V_13 ) ;
}
F_86 ( V_11 -> V_11 ) ;
F_148 ( V_11 -> V_11 ) ;
return V_20 ;
}
static void
F_149 ( struct V_10 * V_11 , struct V_136 * V_137 )
{
struct V_12 * V_13 = V_12 ( V_137 ) ;
struct V_17 * V_18 = V_17 ( V_11 ) ;
F_93 ( V_11 -> V_11 ) ;
F_145 ( & V_13 -> V_21 ) ;
if ( V_13 -> V_146 )
F_150 ( V_13 -> V_146 ) ;
F_147 ( & V_13 -> V_21 ) ;
F_145 ( & V_18 -> V_22 . V_21 ) ;
F_151 ( & V_13 -> V_145 ) ;
F_147 ( & V_18 -> V_22 . V_21 ) ;
}
static void
F_152 ( struct V_10 * V_11 , struct V_136 * V_137 )
{
struct V_12 * V_13 = V_12 ( V_137 ) ;
F_7 ( V_13 ) ;
F_58 ( V_13 ) ;
F_86 ( V_11 -> V_11 ) ;
F_148 ( V_11 -> V_11 ) ;
}
long
F_153 ( struct V_147 * V_147 , unsigned int V_148 , unsigned long V_149 )
{
struct V_136 * V_150 = V_147 -> V_151 ;
struct V_10 * V_11 = V_150 -> V_152 -> V_11 ;
long V_20 ;
V_20 = F_93 ( V_11 -> V_11 ) ;
if ( V_20 < 0 && V_20 != - V_140 )
return V_20 ;
switch ( F_154 ( V_148 ) - V_153 ) {
case V_154 :
V_20 = F_155 ( V_150 , ( void V_155 * ) V_149 , F_156 ( V_148 ) ) ;
break;
default:
V_20 = F_157 ( V_147 , V_148 , V_149 ) ;
break;
}
F_86 ( V_11 -> V_11 ) ;
F_148 ( V_11 -> V_11 ) ;
return V_20 ;
}
static void F_158 ( void )
{
F_132 ( L_29 ) ;
F_132 ( L_30 , V_156 ) ;
F_132 ( L_31 , V_157 ) ;
F_132 ( L_32 , V_158 ) ;
F_132 ( L_33 , V_159 ) ;
F_132 ( L_34 , V_23 ) ;
F_132 ( L_35 , V_24 ) ;
F_132 ( L_36 , V_42 ) ;
F_132 ( L_37 , V_88 ) ;
F_132 ( L_38 , V_109 ) ;
F_132 ( L_39 , V_160 ) ;
F_132 ( L_40 , V_161 ) ;
}
struct V_10 *
F_159 ( const struct V_162 * V_163 ,
struct V_7 * V_2 ,
struct V_75 * * V_164 )
{
struct V_10 * V_18 ;
int V_165 ;
V_165 = F_160 ( V_163 , V_2 , V_23 , V_24 ,
true , true , ~ 0ULL , V_164 ) ;
if ( V_165 )
goto V_166;
V_18 = F_161 ( & V_167 , & V_2 -> V_11 ) ;
if ( F_162 ( V_18 ) ) {
V_165 = F_163 ( V_18 ) ;
goto V_166;
}
V_18 -> V_8 = V_2 ;
F_164 ( V_2 , V_18 ) ;
return V_18 ;
V_166:
F_52 ( V_164 ) ;
return F_165 ( V_165 ) ;
}
static int T_3
F_166 ( void )
{
V_89 = V_168 ;
V_89 . V_169 = V_170 ;
V_167 = V_168 ;
F_158 () ;
if ( V_88 == - 1 ) {
if ( F_167 () )
V_88 = 0 ;
}
if ( ! V_88 )
return 0 ;
#ifdef F_168
F_169 ( & V_171 ) ;
#endif
F_170 () ;
F_171 () ;
return F_172 ( & V_89 , & V_172 ) ;
}
static void T_4
F_173 ( void )
{
if ( ! V_88 )
return;
F_174 ( & V_89 , & V_172 ) ;
F_175 () ;
F_176 () ;
#ifdef F_168
F_177 ( & V_171 ) ;
#endif
}

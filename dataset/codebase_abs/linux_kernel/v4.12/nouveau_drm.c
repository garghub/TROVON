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
return F_5 ( F_7 ( V_11 -> V_11 ) ) ;
}
static void
F_8 ( struct V_12 * V_13 )
{
F_9 ( NULL , & F_10 ( & V_13 -> V_14 ) -> V_15 , NULL ) ;
F_11 ( V_13 ) ;
F_12 ( & V_13 -> V_16 ) ;
F_13 ( & V_13 -> V_14 ) ;
}
static int
F_14 ( struct V_17 * V_18 , const char * V_19 ,
struct V_12 * V_13 )
{
T_1 V_16 = F_6 ( V_18 -> V_11 ) ;
int V_20 ;
snprintf ( V_13 -> V_3 , sizeof( V_13 -> V_3 ) , L_1 , V_19 ) ;
V_13 -> V_11 = V_18 -> V_11 ;
F_15 ( & V_13 -> V_21 ) ;
F_16 ( V_13 ) ;
if ( V_13 == & V_18 -> V_22 ) {
V_20 = F_17 ( NULL , V_23 , V_24 ,
V_13 -> V_3 , V_16 , & V_13 -> V_14 ) ;
} else {
V_20 = F_18 ( & V_18 -> V_22 . V_14 , V_13 -> V_3 , V_16 ,
& V_13 -> V_14 ) ;
}
if ( V_20 ) {
F_19 ( V_18 , L_2 , V_20 ) ;
goto V_25;
}
V_20 = F_20 (&cli->base.object, 0 , NV_DEVICE,
&(struct nv_device_v0) {
.device = ~0 ,
}, sizeof(struct nv_device_v0),
&cli->device) ;
if ( V_20 ) {
F_19 ( V_18 , L_3 , V_20 ) ;
goto V_25;
}
V_25:
if ( V_20 )
F_8 ( V_13 ) ;
return V_20 ;
}
static void
F_21 ( struct V_17 * V_18 )
{
F_22 ( V_18 -> V_26 ) ;
F_23 ( & V_18 -> V_27 ) ;
F_24 ( & V_18 -> V_28 ) ;
F_25 ( & V_18 -> V_29 ) ;
F_23 ( & V_18 -> V_30 ) ;
F_26 ( & V_18 -> V_26 ) ;
F_22 ( V_18 -> V_31 ) ;
F_23 ( & V_18 -> V_32 . V_33 ) ;
F_26 ( & V_18 -> V_31 ) ;
if ( V_18 -> V_34 )
F_27 ( V_18 ) -> F_28 ( V_18 ) ;
}
static void
F_29 ( struct V_17 * V_18 )
{
struct V_35 * V_16 = & V_18 -> V_22 . V_16 ;
struct V_36 * V_37 ;
T_2 V_38 , V_39 ;
int V_20 , V_40 , V_41 ;
if ( V_42 )
return;
V_20 = V_41 = F_30 ( & V_16 -> V_43 , & V_37 ) ;
if ( V_20 < 0 )
return;
for ( V_20 = - V_44 , V_40 = 0 ; V_40 < V_41 ; V_40 ++ ) {
switch ( V_37 [ V_40 ] . V_45 ) {
case V_46 :
V_20 = F_31 ( V_18 ) ;
break;
case V_47 :
V_20 = F_32 ( V_18 ) ;
break;
case V_48 :
case V_49 :
V_20 = F_33 ( V_18 ) ;
break;
case V_50 :
V_20 = F_34 ( V_18 ) ;
break;
case V_51 :
V_20 = F_35 ( V_18 ) ;
break;
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
V_20 = F_36 ( V_18 ) ;
break;
default:
break;
}
}
F_37 ( & V_37 ) ;
if ( V_20 ) {
F_19 ( V_18 , L_4 , V_20 ) ;
F_21 ( V_18 ) ;
return;
}
if ( V_16 -> V_57 . V_58 >= V_59 ) {
V_20 = F_38 ( V_18 , & V_18 -> V_22 . V_16 ,
V_60 |
V_61 ,
0 , & V_18 -> V_31 ) ;
if ( V_20 )
F_19 ( V_18 , L_5 , V_20 ) ;
V_38 = V_62 ;
V_39 = 1 ;
} else
if ( V_16 -> V_57 . V_63 >= 0xa3 &&
V_16 -> V_57 . V_63 != 0xaa &&
V_16 -> V_57 . V_63 != 0xac ) {
V_20 = F_38 ( V_18 , & V_18 -> V_22 . V_16 ,
V_64 , V_65 , & V_18 -> V_31 ) ;
if ( V_20 )
F_19 ( V_18 , L_5 , V_20 ) ;
V_38 = V_64 ;
V_39 = V_65 ;
} else {
V_38 = V_64 ;
V_39 = V_65 ;
}
V_20 = F_38 ( V_18 , & V_18 -> V_22 . V_16 ,
V_38 , V_39 , & V_18 -> V_26 ) ;
if ( V_20 ) {
F_19 ( V_18 , L_6 , V_20 ) ;
F_21 ( V_18 ) ;
return;
}
V_20 = F_39 ( & V_18 -> V_26 -> V_66 , V_67 ,
F_40 ( V_18 ) , NULL , 0 , & V_18 -> V_30 ) ;
if ( V_20 == 0 ) {
V_20 = F_41 ( V_18 -> V_26 , 2 ) ;
if ( V_20 == 0 ) {
if ( V_16 -> V_57 . V_58 < V_68 ) {
F_42 ( V_18 -> V_26 , V_69 , 0 , 1 ) ;
F_43 ( V_18 -> V_26 , V_67 ) ;
} else
if ( V_16 -> V_57 . V_58 < V_59 ) {
F_44 ( V_18 -> V_26 , V_70 , 0 , 1 ) ;
F_43 ( V_18 -> V_26 , 0x001f0000 ) ;
}
}
V_20 = F_45 ( & V_18 -> V_30 , V_71 ,
false , V_72 ,
NULL , 0 , 0 , & V_18 -> V_29 ) ;
if ( V_20 == 0 )
V_20 = F_46 ( & V_18 -> V_29 ) ;
if ( V_20 ) {
F_21 ( V_18 ) ;
return;
}
}
if ( V_20 ) {
F_19 ( V_18 , L_7 , V_20 ) ;
F_21 ( V_18 ) ;
return;
}
if ( V_16 -> V_57 . V_58 < V_68 ) {
V_20 = F_47 ( F_48 ( & V_18 -> V_22 . V_16 ) , 32 , 0 ,
false , NULL , & V_18 -> V_28 ) ;
if ( V_20 ) {
F_19 ( V_18 , L_8 , V_20 ) ;
F_21 ( V_18 ) ;
return;
}
V_20 = F_39 (&drm->channel->user, NvNotify0,
NV_DMA_IN_MEMORY,
&(struct nv_dma_v0) {
.target = NV_DMA_V0_TARGET_VRAM,
.access = NV_DMA_V0_ACCESS_RDWR,
.start = drm->notify->addr,
.limit = drm->notify->addr + 31
}, sizeof(struct nv_dma_v0),
&drm->ntfy) ;
if ( V_20 ) {
F_21 ( V_18 ) ;
return;
}
}
F_49 ( V_18 ) ;
}
static int F_50 ( struct V_1 * V_2 ,
const struct V_73 * V_74 )
{
struct V_75 * V_16 ;
struct V_76 * V_77 ;
bool V_78 = false ;
int V_20 ;
if ( F_51 ( V_2 ) )
return - V_79 ;
V_20 = F_52 ( V_2 , NULL , L_9 , true , false , 0 , & V_16 ) ;
if ( V_20 )
return V_20 ;
F_53 ( & V_16 ) ;
V_77 = F_54 ( 3 ) ;
if ( ! V_77 )
return - V_80 ;
V_77 -> V_81 [ 0 ] . V_14 = F_55 ( V_2 , 1 ) ;
V_77 -> V_81 [ 0 ] . V_82 = F_56 ( V_2 , 1 ) ;
V_77 -> V_83 = 1 ;
if ( F_56 ( V_2 , 2 ) ) {
V_77 -> V_81 [ V_77 -> V_83 ] . V_14 = F_55 ( V_2 , 2 ) ;
V_77 -> V_81 [ V_77 -> V_83 ] . V_82 = F_56 ( V_2 , 2 ) ;
V_77 -> V_83 ++ ;
}
if ( F_56 ( V_2 , 3 ) ) {
V_77 -> V_81 [ V_77 -> V_83 ] . V_14 = F_55 ( V_2 , 3 ) ;
V_77 -> V_81 [ V_77 -> V_83 ] . V_82 = F_56 ( V_2 , 3 ) ;
V_77 -> V_83 ++ ;
}
#ifdef F_57
V_78 = V_2 -> V_84 [ V_85 ] . V_86 & V_87 ;
#endif
if ( V_88 != 2 )
F_58 ( V_77 , L_10 , V_78 ) ;
F_59 ( V_77 ) ;
V_20 = F_52 ( V_2 , V_23 , V_24 ,
true , true , ~ 0ULL , & V_16 ) ;
if ( V_20 )
return V_20 ;
F_60 ( V_2 ) ;
V_20 = F_61 ( V_2 , V_74 , & V_89 ) ;
if ( V_20 ) {
F_53 ( & V_16 ) ;
return V_20 ;
}
return 0 ;
}
static void
F_62 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_11 -> V_2 ;
if ( ! V_2 ) {
F_63 ( V_18 , L_11 ) ;
V_18 -> V_90 = NULL ;
return;
}
V_18 -> V_90 = F_64 ( ( unsigned int ) V_2 -> V_4 -> V_5 ,
F_65 ( F_3 ( V_2 -> V_6 ) , 1 ) ) ;
if ( ! V_18 -> V_90 ) {
F_63 ( V_18 , L_12 , V_2 -> V_4 -> V_5 , F_3 ( V_2 -> V_6 ) , 1 ) ;
return;
}
if ( ( V_18 -> V_90 -> V_91 >> 8 ) != V_92 ) {
F_63 ( V_18 , L_13 , V_18 -> V_90 -> V_91 ) ;
F_66 ( V_18 -> V_90 ) ;
V_18 -> V_90 = NULL ;
return;
}
}
static int
F_67 ( struct V_10 * V_11 , unsigned long V_86 )
{
struct V_17 * V_18 ;
int V_20 ;
if ( ! ( V_18 = F_68 ( sizeof( * V_18 ) , V_93 ) ) )
return - V_80 ;
V_11 -> V_94 = V_18 ;
V_18 -> V_11 = V_11 ;
V_20 = F_14 ( V_18 , L_14 , & V_18 -> V_22 ) ;
if ( V_20 )
return V_20 ;
V_11 -> V_95 = true ;
F_10 ( & V_18 -> V_22 . V_14 ) -> V_96 =
F_69 ( V_24 , L_14 ) ;
F_70 ( & V_18 -> V_97 ) ;
F_71 ( & V_18 -> V_98 . V_99 ) ;
F_62 ( V_18 ) ;
if ( V_18 -> V_22 . V_16 . V_57 . V_63 == 0xc1 )
F_72 ( & V_18 -> V_22 . V_16 . V_43 , 0x00088080 , 0x00000800 , 0x00000000 ) ;
F_73 ( V_18 ) ;
if ( V_18 -> V_22 . V_16 . V_57 . V_58 >= V_100 ) {
if ( ! F_48 ( & V_18 -> V_22 . V_16 ) -> V_101 ) {
V_20 = - V_44 ;
goto V_102;
}
V_20 = F_74 ( F_48 ( & V_18 -> V_22 . V_16 ) ,
0 , ( 1ULL << 40 ) , 0x1000 , NULL ,
& V_18 -> V_22 . V_15 ) ;
if ( V_20 )
goto V_102;
F_10 ( & V_18 -> V_22 . V_14 ) -> V_15 = V_18 -> V_22 . V_15 ;
}
V_20 = F_75 ( V_18 ) ;
if ( V_20 )
goto V_103;
V_20 = F_76 ( V_11 ) ;
if ( V_20 )
goto V_104;
V_20 = F_77 ( V_11 ) ;
if ( V_20 )
goto V_105;
if ( V_11 -> V_106 . V_107 ) {
V_20 = F_78 ( V_11 ) ;
if ( V_20 )
goto V_108;
}
F_79 ( V_18 ) ;
F_80 ( V_11 ) ;
F_29 ( V_18 ) ;
F_81 ( V_11 ) ;
F_82 ( V_11 ) ;
if ( F_83 () ) {
F_84 ( V_11 -> V_11 ) ;
F_85 ( V_11 -> V_11 , 5000 ) ;
F_86 ( V_11 -> V_11 ) ;
F_87 ( V_11 -> V_11 ) ;
F_88 ( V_11 -> V_11 ) ;
F_89 ( V_11 -> V_11 ) ;
} else {
F_90 ( V_11 ) ;
}
return 0 ;
V_108:
F_91 ( V_11 ) ;
V_105:
F_92 ( V_11 ) ;
V_104:
F_93 ( V_18 ) ;
V_103:
F_94 ( V_18 ) ;
V_102:
F_8 ( & V_18 -> V_22 ) ;
F_59 ( V_18 ) ;
return V_20 ;
}
static void
F_95 ( struct V_10 * V_11 )
{
struct V_17 * V_18 = V_17 ( V_11 ) ;
if ( F_83 () ) {
F_96 ( V_11 -> V_11 ) ;
F_97 ( V_11 -> V_11 ) ;
}
F_98 ( V_11 ) ;
F_99 ( V_11 ) ;
F_21 ( V_18 ) ;
F_100 ( V_11 ) ;
F_101 ( V_18 ) ;
if ( V_11 -> V_106 . V_107 )
F_102 ( V_11 , false ) ;
F_91 ( V_11 ) ;
F_92 ( V_11 ) ;
F_93 ( V_18 ) ;
F_94 ( V_18 ) ;
if ( V_18 -> V_90 )
F_66 ( V_18 -> V_90 ) ;
F_8 ( & V_18 -> V_22 ) ;
F_59 ( V_18 ) ;
}
void
F_103 ( struct V_10 * V_11 )
{
struct V_17 * V_18 = V_17 ( V_11 ) ;
struct V_109 * V_22 ;
struct V_75 * V_16 ;
V_11 -> V_95 = false ;
V_22 = F_10 ( & V_18 -> V_22 . V_14 ) ;
V_16 = F_104 ( V_22 -> V_16 ) ;
F_105 ( V_11 ) ;
F_53 ( & V_16 ) ;
}
static void
F_106 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_107 ( V_2 ) ;
F_103 ( V_11 ) ;
}
static int
F_108 ( struct V_10 * V_11 , bool V_110 )
{
struct V_17 * V_18 = V_17 ( V_11 ) ;
int V_20 ;
F_109 ( V_11 ) ;
if ( V_11 -> V_106 . V_107 ) {
F_110 ( V_18 , L_15 ) ;
F_111 ( V_11 , 1 ) ;
F_110 ( V_18 , L_16 ) ;
V_20 = F_112 ( V_11 , V_110 ) ;
if ( V_20 )
return V_20 ;
}
F_110 ( V_18 , L_17 ) ;
F_113 ( & V_18 -> V_32 . V_111 , V_112 ) ;
F_110 ( V_18 , L_18 ) ;
if ( V_18 -> V_31 ) {
V_20 = F_22 ( V_18 -> V_31 ) ;
if ( V_20 )
goto V_113;
}
if ( V_18 -> V_26 ) {
V_20 = F_22 ( V_18 -> V_26 ) ;
if ( V_20 )
goto V_113;
}
F_110 ( V_18 , L_19 ) ;
if ( V_18 -> V_34 && F_27 ( V_18 ) -> V_114 ) {
if ( ! F_27 ( V_18 ) -> V_114 ( V_18 ) ) {
V_20 = - V_80 ;
goto V_113;
}
}
F_110 ( V_18 , L_20 ) ;
V_20 = F_114 ( & V_18 -> V_22 . V_14 ) ;
if ( V_20 )
goto V_115;
return 0 ;
V_115:
if ( V_18 -> V_34 && F_27 ( V_18 ) -> V_116 )
F_27 ( V_18 ) -> V_116 ( V_18 ) ;
V_113:
if ( V_11 -> V_106 . V_107 ) {
F_110 ( V_18 , L_21 ) ;
F_115 ( V_11 , V_110 ) ;
}
return V_20 ;
}
static int
F_116 ( struct V_10 * V_11 , bool V_110 )
{
struct V_17 * V_18 = V_17 ( V_11 ) ;
F_110 ( V_18 , L_22 ) ;
F_117 ( & V_18 -> V_22 . V_14 ) ;
F_110 ( V_18 , L_23 ) ;
if ( V_18 -> V_34 && F_27 ( V_18 ) -> V_116 )
F_27 ( V_18 ) -> V_116 ( V_18 ) ;
F_118 ( V_11 ) ;
if ( V_11 -> V_106 . V_107 ) {
F_110 ( V_18 , L_21 ) ;
F_115 ( V_11 , V_110 ) ;
F_110 ( V_18 , L_24 ) ;
F_111 ( V_11 , 0 ) ;
}
F_119 ( V_11 ) ;
return 0 ;
}
int
F_120 ( struct V_16 * V_11 )
{
struct V_1 * V_2 = F_121 ( V_11 ) ;
struct V_10 * V_117 = F_107 ( V_2 ) ;
int V_20 ;
if ( V_117 -> V_118 == V_119 ||
V_117 -> V_118 == V_120 )
return 0 ;
V_20 = F_108 ( V_117 , false ) ;
if ( V_20 )
return V_20 ;
F_122 ( V_2 ) ;
F_123 ( V_2 ) ;
F_124 ( V_2 , V_121 ) ;
F_125 ( 200 ) ;
return 0 ;
}
int
F_126 ( struct V_16 * V_11 )
{
struct V_1 * V_2 = F_121 ( V_11 ) ;
struct V_10 * V_117 = F_107 ( V_2 ) ;
int V_20 ;
if ( V_117 -> V_118 == V_119 ||
V_117 -> V_118 == V_120 )
return 0 ;
F_124 ( V_2 , V_122 ) ;
F_127 ( V_2 ) ;
V_20 = F_128 ( V_2 ) ;
if ( V_20 )
return V_20 ;
F_60 ( V_2 ) ;
V_20 = F_116 ( V_117 , false ) ;
F_129 ( & V_17 ( V_117 ) -> V_123 ) ;
return V_20 ;
}
static int
F_130 ( struct V_16 * V_11 )
{
struct V_1 * V_2 = F_121 ( V_11 ) ;
struct V_10 * V_117 = F_107 ( V_2 ) ;
return F_108 ( V_117 , false ) ;
}
static int
F_131 ( struct V_16 * V_11 )
{
struct V_1 * V_2 = F_121 ( V_11 ) ;
struct V_10 * V_117 = F_107 ( V_2 ) ;
return F_116 ( V_117 , false ) ;
}
bool
F_83 ()
{
if ( V_124 == - 1 )
return F_132 () || F_133 () ;
return V_124 == 1 ;
}
static int
F_134 ( struct V_16 * V_11 )
{
struct V_1 * V_2 = F_121 ( V_11 ) ;
struct V_10 * V_117 = F_107 ( V_2 ) ;
int V_20 ;
if ( ! F_83 () ) {
F_97 ( V_11 ) ;
return - V_125 ;
}
F_135 ( V_117 ) ;
F_136 ( V_2 , V_126 ) ;
F_137 () ;
V_20 = F_108 ( V_117 , true ) ;
F_122 ( V_2 ) ;
F_123 ( V_2 ) ;
F_138 ( V_2 ) ;
F_124 ( V_2 , V_127 ) ;
V_117 -> V_118 = V_120 ;
return V_20 ;
}
static int
F_139 ( struct V_16 * V_11 )
{
struct V_1 * V_2 = F_121 ( V_11 ) ;
struct V_10 * V_117 = F_107 ( V_2 ) ;
struct V_35 * V_16 = & V_17 ( V_117 ) -> V_22 . V_16 ;
int V_20 ;
if ( ! F_83 () ) {
F_97 ( V_11 ) ;
return - V_125 ;
}
F_124 ( V_2 , V_122 ) ;
F_127 ( V_2 ) ;
V_20 = F_128 ( V_2 ) ;
if ( V_20 )
return V_20 ;
F_60 ( V_2 ) ;
V_20 = F_116 ( V_117 , true ) ;
F_72 ( & V_16 -> V_43 , 0x088488 , ( 1 << 25 ) , ( 1 << 25 ) ) ;
F_136 ( V_2 , V_128 ) ;
V_117 -> V_118 = V_129 ;
F_129 ( & V_17 ( V_117 ) -> V_123 ) ;
return V_20 ;
}
static int
F_140 ( struct V_16 * V_11 )
{
struct V_1 * V_2 = F_121 ( V_11 ) ;
struct V_10 * V_117 = F_107 ( V_2 ) ;
struct V_17 * V_18 = V_17 ( V_117 ) ;
struct V_130 * V_131 ;
if ( ! F_83 () ) {
F_97 ( V_11 ) ;
return - V_125 ;
}
if ( V_18 -> V_90 ) {
if ( ! V_18 -> V_90 -> V_132 ) {
F_141 ( L_25 ) ;
F_88 ( V_11 ) ;
return - V_125 ;
}
}
F_142 (crtc, &drm->dev->mode_config.crtc_list, head) {
if ( V_131 -> V_133 ) {
F_141 ( L_26 ) ;
return - V_125 ;
}
}
F_88 ( V_11 ) ;
F_143 ( V_11 ) ;
return 1 ;
}
static int
F_144 ( struct V_10 * V_11 , struct V_134 * V_135 )
{
struct V_17 * V_18 = V_17 ( V_11 ) ;
struct V_12 * V_13 ;
char V_3 [ 32 ] , V_136 [ V_137 ] ;
int V_20 ;
V_20 = F_96 ( V_11 -> V_11 ) ;
if ( V_20 < 0 && V_20 != - V_138 )
return V_20 ;
F_145 ( V_136 , V_139 ) ;
snprintf ( V_3 , sizeof( V_3 ) , L_27 , V_136 , F_146 ( V_135 -> V_140 ) ) ;
if ( ! ( V_13 = F_68 ( sizeof( * V_13 ) , V_93 ) ) )
return V_20 ;
V_20 = F_14 ( V_18 , V_3 , V_13 ) ;
if ( V_20 )
goto V_25;
V_13 -> V_14 . V_141 = false ;
if ( V_18 -> V_22 . V_16 . V_57 . V_58 >= V_100 ) {
V_20 = F_74 ( F_48 ( & V_18 -> V_22 . V_16 ) , 0 ,
( 1ULL << 40 ) , 0x1000 , NULL , & V_13 -> V_15 ) ;
if ( V_20 )
goto V_25;
F_10 ( & V_13 -> V_14 ) -> V_15 = V_13 -> V_15 ;
}
V_135 -> V_142 = V_13 ;
F_147 ( & V_18 -> V_22 . V_21 ) ;
F_148 ( & V_13 -> V_143 , & V_18 -> V_97 ) ;
F_149 ( & V_18 -> V_22 . V_21 ) ;
V_25:
if ( V_20 && V_13 ) {
F_8 ( V_13 ) ;
F_59 ( V_13 ) ;
}
F_88 ( V_11 -> V_11 ) ;
F_150 ( V_11 -> V_11 ) ;
return V_20 ;
}
static void
F_151 ( struct V_10 * V_11 , struct V_134 * V_135 )
{
struct V_12 * V_13 = V_12 ( V_135 ) ;
struct V_17 * V_18 = V_17 ( V_11 ) ;
F_96 ( V_11 -> V_11 ) ;
F_147 ( & V_13 -> V_21 ) ;
if ( V_13 -> V_144 )
F_152 ( V_13 -> V_144 ) ;
F_149 ( & V_13 -> V_21 ) ;
F_147 ( & V_18 -> V_22 . V_21 ) ;
F_153 ( & V_13 -> V_143 ) ;
F_149 ( & V_18 -> V_22 . V_21 ) ;
}
static void
F_154 ( struct V_10 * V_11 , struct V_134 * V_135 )
{
struct V_12 * V_13 = V_12 ( V_135 ) ;
F_8 ( V_13 ) ;
F_59 ( V_13 ) ;
F_88 ( V_11 -> V_11 ) ;
F_150 ( V_11 -> V_11 ) ;
}
long
F_155 ( struct V_145 * V_145 , unsigned int V_146 , unsigned long V_147 )
{
struct V_134 * V_148 = V_145 -> V_149 ;
struct V_10 * V_11 = V_148 -> V_150 -> V_11 ;
long V_20 ;
V_20 = F_96 ( V_11 -> V_11 ) ;
if ( V_20 < 0 && V_20 != - V_138 )
return V_20 ;
switch ( F_156 ( V_146 ) - V_151 ) {
case V_152 :
V_20 = F_157 ( V_148 , ( void V_153 * ) V_147 , F_158 ( V_146 ) ) ;
break;
default:
V_20 = F_159 ( V_145 , V_146 , V_147 ) ;
break;
}
F_88 ( V_11 -> V_11 ) ;
F_150 ( V_11 -> V_11 ) ;
return V_20 ;
}
static void F_160 ( void )
{
F_141 ( L_28 ) ;
F_141 ( L_29 , V_154 ) ;
F_141 ( L_30 , V_155 ) ;
F_141 ( L_31 , V_156 ) ;
F_141 ( L_32 , V_157 ) ;
F_141 ( L_33 , V_23 ) ;
F_141 ( L_34 , V_24 ) ;
F_141 ( L_35 , V_42 ) ;
F_141 ( L_36 , V_88 ) ;
F_141 ( L_37 , V_124 ) ;
F_141 ( L_38 , V_158 ) ;
F_141 ( L_39 , V_159 ) ;
}
struct V_10 *
F_161 ( const struct V_160 * V_161 ,
struct V_7 * V_2 ,
struct V_75 * * V_162 )
{
struct V_10 * V_18 ;
int V_163 ;
V_163 = F_162 ( V_161 , V_2 , V_23 , V_24 ,
true , true , ~ 0ULL , V_162 ) ;
if ( V_163 )
goto V_164;
V_18 = F_163 ( & V_165 , & V_2 -> V_11 ) ;
if ( F_164 ( V_18 ) ) {
V_163 = F_165 ( V_18 ) ;
goto V_164;
}
F_166 ( V_2 , V_18 ) ;
return V_18 ;
V_164:
F_53 ( V_162 ) ;
return F_167 ( V_163 ) ;
}
static int T_3
F_168 ( void )
{
V_89 = V_166 ;
V_89 . V_167 = V_168 ;
V_165 = V_166 ;
F_160 () ;
if ( V_88 == - 1 ) {
if ( F_169 () )
V_88 = 0 ;
}
if ( ! V_88 )
return 0 ;
#ifdef F_170
F_171 ( & V_169 ) ;
#endif
F_172 () ;
F_173 () ;
return F_174 ( & V_89 , & V_170 ) ;
}
static void T_4
F_175 ( void )
{
if ( ! V_88 )
return;
F_176 ( & V_89 , & V_170 ) ;
F_177 () ;
F_178 () ;
#ifdef F_170
F_179 ( & V_169 ) ;
#endif
}

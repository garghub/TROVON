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
}
static void
F_17 ( struct V_25 * V_26 )
{
F_18 ( & V_26 -> V_27 ) ;
F_19 ( & V_26 -> V_28 ) ;
F_20 ( NULL , & V_26 -> V_29 ) ;
F_19 ( & V_26 -> V_30 ) ;
F_18 ( & V_26 -> V_31 ) ;
F_19 ( & V_26 -> V_32 . V_33 ) ;
if ( V_26 -> V_34 )
F_21 ( V_26 ) -> F_22 ( V_26 ) ;
}
static void
F_23 ( struct V_25 * V_26 )
{
struct V_35 * V_36 = & V_26 -> V_36 ;
T_2 V_37 , V_38 ;
T_2 V_39 [ 16 ] ;
int V_18 , V_40 ;
if ( V_41 )
return;
V_18 = F_24 ( & V_36 -> V_21 , V_39 , F_25 ( V_39 ) ) ;
if ( V_18 < 0 )
return;
for ( V_18 = - V_42 , V_40 = 0 ; V_18 && V_40 < F_25 ( V_39 ) ; V_40 ++ ) {
switch ( V_39 [ V_40 ] ) {
case V_43 :
V_18 = F_26 ( V_26 ) ;
break;
case V_44 :
V_18 = F_27 ( V_26 ) ;
break;
case V_45 :
case V_46 :
V_18 = F_28 ( V_26 ) ;
break;
case V_47 :
V_18 = F_29 ( V_26 ) ;
break;
case V_48 :
V_18 = F_30 ( V_26 ) ;
break;
case V_49 :
case V_50 :
V_18 = F_31 ( V_26 ) ;
break;
default:
break;
}
}
if ( V_18 ) {
F_32 ( V_26 , L_1 , V_18 ) ;
F_17 ( V_26 ) ;
return;
}
if ( V_36 -> V_51 . V_52 >= V_53 ) {
V_18 = F_33 ( V_26 , & V_26 -> V_36 , V_54 + 1 ,
V_55 |
V_56 ,
0 , & V_26 -> V_31 ) ;
if ( V_18 )
F_32 ( V_26 , L_2 , V_18 ) ;
V_37 = V_57 ;
V_38 = 1 ;
} else
if ( V_36 -> V_51 . V_58 >= 0xa3 &&
V_36 -> V_51 . V_58 != 0xaa &&
V_36 -> V_51 . V_58 != 0xac ) {
V_18 = F_33 ( V_26 , & V_26 -> V_36 , V_54 + 1 ,
V_59 , V_60 , & V_26 -> V_31 ) ;
if ( V_18 )
F_32 ( V_26 , L_2 , V_18 ) ;
V_37 = V_59 ;
V_38 = V_60 ;
} else {
V_37 = V_59 ;
V_38 = V_60 ;
}
V_18 = F_33 ( V_26 , & V_26 -> V_36 , V_54 , V_37 , V_38 ,
& V_26 -> V_27 ) ;
if ( V_18 ) {
F_32 ( V_26 , L_3 , V_18 ) ;
F_17 ( V_26 ) ;
return;
}
V_18 = F_34 ( V_26 -> V_27 -> V_61 , NULL , V_62 ,
F_35 ( V_26 ) , NULL , 0 , & V_26 -> V_30 ) ;
if ( V_18 == 0 ) {
struct V_63 * V_64 ;
V_18 = F_36 ( V_26 -> V_27 , 2 ) ;
if ( V_18 == 0 ) {
if ( V_36 -> V_51 . V_52 < V_65 ) {
F_37 ( V_26 -> V_27 , V_66 , 0 , 1 ) ;
F_38 ( V_26 -> V_27 , V_62 ) ;
} else
if ( V_36 -> V_51 . V_52 < V_53 ) {
F_39 ( V_26 -> V_27 , V_67 , 0 , 1 ) ;
F_38 ( V_26 -> V_27 , 0x001f0000 ) ;
}
}
V_64 = ( void * ) F_40 ( & V_26 -> V_30 ) -> V_68 ;
V_64 -> V_69 = V_70 ;
V_64 -> V_71 = V_26 -> V_27 ;
}
if ( V_18 ) {
F_32 ( V_26 , L_4 , V_18 ) ;
F_17 ( V_26 ) ;
return;
}
if ( V_36 -> V_51 . V_52 < V_65 ) {
V_18 = F_41 ( F_40 ( & V_26 -> V_36 ) , NULL , 32 ,
0 , 0 , & V_26 -> V_29 ) ;
if ( V_18 ) {
F_32 ( V_26 , L_5 , V_18 ) ;
F_17 ( V_26 ) ;
return;
}
V_18 = F_34 (drm->channel->object, NULL, NvNotify0,
NV_DMA_IN_MEMORY,
&(struct nv_dma_v0) {
.target = NV_DMA_V0_TARGET_VRAM,
.access = NV_DMA_V0_ACCESS_RDWR,
.start = drm->notify->addr,
.limit = drm->notify->addr + 31
}, sizeof(struct nv_dma_v0),
&drm->ntfy) ;
if ( V_18 ) {
F_17 ( V_26 ) ;
return;
}
}
F_42 ( V_26 ) ;
}
static int F_43 ( struct V_1 * V_2 ,
const struct V_72 * V_73 )
{
struct V_74 * V_36 ;
struct V_75 * V_76 ;
bool V_77 = false ;
int V_18 ;
V_76 = F_44 ( 3 ) ;
if ( ! V_76 )
return - V_23 ;
V_76 -> V_78 [ 0 ] . V_21 = F_45 ( V_2 , 1 ) ;
V_76 -> V_78 [ 0 ] . V_13 = F_46 ( V_2 , 1 ) ;
V_76 -> V_79 = 1 ;
if ( F_46 ( V_2 , 2 ) ) {
V_76 -> V_78 [ V_76 -> V_79 ] . V_21 = F_45 ( V_2 , 2 ) ;
V_76 -> V_78 [ V_76 -> V_79 ] . V_13 = F_46 ( V_2 , 2 ) ;
V_76 -> V_79 ++ ;
}
if ( F_46 ( V_2 , 3 ) ) {
V_76 -> V_78 [ V_76 -> V_79 ] . V_21 = F_45 ( V_2 , 3 ) ;
V_76 -> V_78 [ V_76 -> V_79 ] . V_13 = F_46 ( V_2 , 3 ) ;
V_76 -> V_79 ++ ;
}
#ifdef F_47
V_77 = V_2 -> V_80 [ V_81 ] . V_82 & V_83 ;
#endif
if ( V_84 != 2 )
F_48 ( V_76 , L_6 , V_77 ) ;
F_49 ( V_76 ) ;
V_18 = F_50 ( V_2 , V_85 ,
F_1 ( V_2 ) , F_51 ( V_2 ) ,
V_19 , V_20 , & V_36 ) ;
if ( V_18 )
return V_18 ;
F_52 ( V_2 ) ;
V_18 = F_53 ( V_2 , V_73 , & V_86 ) ;
if ( V_18 ) {
F_54 ( NULL , (struct V_87 * * ) & V_36 ) ;
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
V_26 -> V_88 = NULL ;
return;
}
V_26 -> V_88 = F_57 ( ( unsigned int ) V_2 -> V_4 -> V_5 ,
F_58 ( F_3 ( V_2 -> V_6 ) , 1 ) ) ;
if ( ! V_26 -> V_88 ) {
F_59 ( V_26 , L_8 , V_2 -> V_4 -> V_5 , F_3 ( V_2 -> V_6 ) , 1 ) ;
return;
}
if ( ( V_26 -> V_88 -> V_89 >> 8 ) != V_90 ) {
F_59 ( V_26 , L_9 , V_26 -> V_88 -> V_89 ) ;
F_60 ( V_26 -> V_88 ) ;
V_26 -> V_88 = NULL ;
return;
}
}
static int
F_61 ( struct V_10 * V_11 , unsigned long V_82 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_25 * V_26 ;
int V_18 ;
V_18 = F_7 ( F_6 ( V_11 ) , L_10 , sizeof( * V_26 ) ,
( void * * ) & V_26 ) ;
if ( V_18 )
return V_18 ;
V_11 -> V_91 = V_26 ;
V_26 -> V_11 = V_11 ;
F_14 ( & V_26 -> V_92 . V_21 ) -> V_93 =
F_62 ( V_20 , L_10 ) ;
F_63 ( & V_26 -> V_94 ) ;
F_64 ( & V_26 -> V_95 . V_96 ) ;
F_55 ( V_26 ) ;
if ( V_2 && F_65 ( V_11 ) && V_11 -> V_97 ) {
const T_1 V_98 = V_99 |
V_100 ;
V_18 = F_66 (&drm->client.base.base, NULL,
NVDRM_DEVICE, NV_DEVICE,
&(struct nv_device_v0) {
.device = ~0 ,
.disable = ~enables,
.debug0 = ~0 ,
}, sizeof(struct nv_device_v0),
&drm->device) ;
if ( V_18 )
goto V_101;
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
goto V_101;
V_11 -> V_102 = true ;
if ( V_26 -> V_36 . V_51 . V_58 == 0xc1 )
F_69 ( & V_26 -> V_36 , 0x00088080 , 0x00000800 , 0x00000000 ) ;
F_70 ( V_26 ) ;
F_71 ( V_26 ) ;
if ( V_26 -> V_36 . V_51 . V_52 >= V_103 ) {
V_18 = F_72 ( F_73 ( & V_26 -> V_36 ) , 0 , ( 1ULL << 40 ) ,
0x1000 , & V_26 -> V_92 . V_24 ) ;
if ( V_18 )
goto V_101;
F_14 ( & V_26 -> V_92 . V_21 ) -> V_24 = V_26 -> V_92 . V_24 ;
}
V_18 = F_74 ( V_26 ) ;
if ( V_18 )
goto V_104;
V_18 = F_75 ( V_11 ) ;
if ( V_18 )
goto V_105;
V_18 = F_76 ( V_11 ) ;
if ( V_18 )
goto V_106;
if ( V_11 -> V_107 . V_108 ) {
V_18 = F_77 ( V_11 ) ;
if ( V_18 )
goto V_109;
}
F_78 ( V_11 ) ;
F_79 ( V_11 ) ;
F_23 ( V_26 ) ;
F_80 ( V_11 ) ;
if ( V_110 != 0 ) {
F_81 ( V_11 -> V_11 ) ;
F_82 ( V_11 -> V_11 , 5000 ) ;
F_83 ( V_11 -> V_11 ) ;
F_84 ( V_11 -> V_11 ) ;
F_85 ( V_11 -> V_11 ) ;
F_86 ( V_11 -> V_11 ) ;
}
return 0 ;
V_109:
F_87 ( V_11 ) ;
V_106:
F_88 ( V_11 ) ;
V_105:
F_89 ( V_26 ) ;
V_104:
F_90 ( V_26 ) ;
F_91 ( V_26 ) ;
V_101:
F_68 ( & V_26 -> V_36 ) ;
F_12 ( & V_26 -> V_92 ) ;
return V_18 ;
}
static int
F_92 ( struct V_10 * V_11 )
{
struct V_25 * V_26 = V_25 ( V_11 ) ;
F_93 ( V_11 -> V_11 ) ;
F_94 ( V_11 ) ;
F_17 ( V_26 ) ;
F_95 ( V_11 ) ;
F_96 ( V_11 ) ;
if ( V_11 -> V_107 . V_108 )
F_97 ( V_11 ) ;
F_87 ( V_11 ) ;
F_88 ( V_11 ) ;
F_89 ( V_26 ) ;
F_90 ( V_26 ) ;
F_91 ( V_26 ) ;
F_68 ( & V_26 -> V_36 ) ;
if ( V_26 -> V_88 )
F_60 ( V_26 -> V_88 ) ;
F_12 ( & V_26 -> V_92 ) ;
return 0 ;
}
void
F_98 ( struct V_10 * V_11 )
{
struct V_25 * V_26 = V_25 ( V_11 ) ;
struct V_111 * V_92 ;
struct V_87 * V_36 ;
V_11 -> V_102 = false ;
V_92 = F_14 ( & V_26 -> V_92 . V_21 ) ;
V_36 = V_92 -> V_36 ;
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
F_103 ( struct V_10 * V_11 , bool V_112 )
{
struct V_25 * V_26 = V_25 ( V_11 ) ;
struct V_15 * V_16 ;
int V_18 ;
if ( V_11 -> V_107 . V_108 ) {
F_104 ( V_26 , L_11 ) ;
F_105 ( V_11 , 1 ) ;
F_104 ( V_26 , L_12 ) ;
V_18 = F_106 ( V_11 , V_112 ) ;
if ( V_18 )
return V_18 ;
}
F_104 ( V_26 , L_13 ) ;
F_107 ( & V_26 -> V_32 . V_113 , V_114 ) ;
F_104 ( V_26 , L_14 ) ;
if ( V_26 -> V_31 ) {
V_18 = F_108 ( V_26 -> V_31 ) ;
if ( V_18 )
goto V_115;
}
if ( V_26 -> V_27 ) {
V_18 = F_108 ( V_26 -> V_27 ) ;
if ( V_18 )
goto V_115;
}
F_104 ( V_26 , L_15 ) ;
if ( V_26 -> V_34 && F_21 ( V_26 ) -> V_116 ) {
if ( ! F_21 ( V_26 ) -> V_116 ( V_26 ) ) {
V_18 = - V_23 ;
goto V_115;
}
}
F_109 (cli, &drm->clients, head) {
V_18 = F_110 ( & V_16 -> V_21 ) ;
if ( V_18 )
goto V_117;
}
F_104 ( V_26 , L_16 ) ;
V_18 = F_110 ( & V_26 -> V_92 . V_21 ) ;
if ( V_18 )
goto V_117;
F_90 ( V_26 ) ;
return 0 ;
V_117:
F_111 (cli, &drm->clients, head) {
F_112 ( & V_16 -> V_21 ) ;
}
if ( V_26 -> V_34 && F_21 ( V_26 ) -> V_118 )
F_21 ( V_26 ) -> V_118 ( V_26 ) ;
V_115:
if ( V_11 -> V_107 . V_108 ) {
F_104 ( V_26 , L_17 ) ;
F_113 ( V_11 , V_112 ) ;
}
return V_18 ;
}
int F_114 ( struct V_36 * V_11 )
{
struct V_1 * V_2 = F_115 ( V_11 ) ;
struct V_10 * V_119 = F_102 ( V_2 ) ;
int V_18 ;
if ( V_119 -> V_120 == V_121 ||
V_119 -> V_120 == V_122 )
return 0 ;
V_18 = F_103 ( V_119 , false ) ;
if ( V_18 )
return V_18 ;
F_116 ( V_2 ) ;
F_117 ( V_2 ) ;
F_118 ( V_2 , V_123 ) ;
return 0 ;
}
static int
F_119 ( struct V_10 * V_11 , bool V_112 )
{
struct V_25 * V_26 = V_25 ( V_11 ) ;
struct V_15 * V_16 ;
F_104 ( V_26 , L_18 ) ;
F_67 ( V_26 ) ;
F_104 ( V_26 , L_19 ) ;
F_112 ( & V_26 -> V_92 . V_21 ) ;
F_71 ( V_26 ) ;
F_104 ( V_26 , L_20 ) ;
if ( V_26 -> V_34 && F_21 ( V_26 ) -> V_118 )
F_21 ( V_26 ) -> V_118 ( V_26 ) ;
F_109 (cli, &drm->clients, head) {
F_112 ( & V_16 -> V_21 ) ;
}
F_120 ( V_11 ) ;
if ( V_11 -> V_107 . V_108 ) {
F_104 ( V_26 , L_17 ) ;
F_113 ( V_11 , V_112 ) ;
F_104 ( V_26 , L_21 ) ;
F_105 ( V_11 , 0 ) ;
}
return 0 ;
}
int F_121 ( struct V_36 * V_11 )
{
struct V_1 * V_2 = F_115 ( V_11 ) ;
struct V_10 * V_119 = F_102 ( V_2 ) ;
int V_18 ;
if ( V_119 -> V_120 == V_121 ||
V_119 -> V_120 == V_122 )
return 0 ;
F_118 ( V_2 , V_124 ) ;
F_122 ( V_2 ) ;
V_18 = F_123 ( V_2 ) ;
if ( V_18 )
return V_18 ;
F_52 ( V_2 ) ;
return F_119 ( V_119 , false ) ;
}
static int F_124 ( struct V_36 * V_11 )
{
struct V_1 * V_2 = F_115 ( V_11 ) ;
struct V_10 * V_119 = F_102 ( V_2 ) ;
return F_103 ( V_119 , false ) ;
}
static int F_125 ( struct V_36 * V_11 )
{
struct V_1 * V_2 = F_115 ( V_11 ) ;
struct V_10 * V_119 = F_102 ( V_2 ) ;
return F_119 ( V_119 , false ) ;
}
static int
F_126 ( struct V_10 * V_11 , struct V_125 * V_126 )
{
struct V_25 * V_26 = V_25 ( V_11 ) ;
struct V_15 * V_16 ;
char V_3 [ 32 ] , V_127 [ V_128 ] ;
int V_18 ;
V_18 = F_93 ( V_11 -> V_11 ) ;
if ( V_18 < 0 && V_18 != - V_129 )
return V_18 ;
F_127 ( V_127 , V_130 ) ;
snprintf ( V_3 , sizeof( V_3 ) , L_22 , V_127 , F_128 ( V_126 -> V_131 ) ) ;
V_18 = F_7 ( F_6 ( V_11 ) , V_3 , sizeof( * V_16 ) ,
( void * * ) & V_16 ) ;
if ( V_18 )
goto V_132;
V_16 -> V_21 . V_133 = false ;
if ( V_26 -> V_36 . V_51 . V_52 >= V_103 ) {
V_18 = F_72 ( F_73 ( & V_26 -> V_36 ) , 0 , ( 1ULL << 40 ) ,
0x1000 , & V_16 -> V_24 ) ;
if ( V_18 ) {
F_12 ( V_16 ) ;
goto V_132;
}
F_14 ( & V_16 -> V_21 ) -> V_24 = V_16 -> V_24 ;
}
V_126 -> V_134 = V_16 ;
F_129 ( & V_26 -> V_92 . V_22 ) ;
F_130 ( & V_16 -> V_135 , & V_26 -> V_94 ) ;
F_131 ( & V_26 -> V_92 . V_22 ) ;
V_132:
F_85 ( V_11 -> V_11 ) ;
F_132 ( V_11 -> V_11 ) ;
return V_18 ;
}
static void
F_133 ( struct V_10 * V_11 , struct V_125 * V_126 )
{
struct V_15 * V_16 = V_15 ( V_126 ) ;
struct V_25 * V_26 = V_25 ( V_11 ) ;
F_93 ( V_11 -> V_11 ) ;
if ( V_16 -> V_136 )
F_134 ( V_16 -> V_136 ) ;
F_129 ( & V_26 -> V_92 . V_22 ) ;
F_135 ( & V_16 -> V_135 ) ;
F_131 ( & V_26 -> V_92 . V_22 ) ;
}
static void
F_136 ( struct V_10 * V_11 , struct V_125 * V_126 )
{
struct V_15 * V_16 = V_15 ( V_126 ) ;
F_12 ( V_16 ) ;
F_85 ( V_11 -> V_11 ) ;
F_132 ( V_11 -> V_11 ) ;
}
long
F_137 ( struct V_137 * V_137 , unsigned int V_138 , unsigned long V_139 )
{
struct V_125 * V_140 = V_137 -> V_141 ;
struct V_10 * V_11 = V_140 -> V_142 -> V_11 ;
long V_18 ;
V_18 = F_93 ( V_11 -> V_11 ) ;
if ( V_18 < 0 && V_18 != - V_129 )
return V_18 ;
switch ( F_138 ( V_138 ) - V_143 ) {
case V_144 :
V_18 = F_139 ( V_140 , ( void V_145 * ) V_139 , F_140 ( V_138 ) ) ;
break;
default:
V_18 = F_141 ( V_137 , V_138 , V_139 ) ;
break;
}
F_85 ( V_11 -> V_11 ) ;
F_132 ( V_11 -> V_11 ) ;
return V_18 ;
}
static int F_142 ( struct V_36 * V_11 )
{
struct V_1 * V_2 = F_115 ( V_11 ) ;
struct V_10 * V_119 = F_102 ( V_2 ) ;
int V_18 ;
if ( V_110 == 0 ) {
F_143 ( V_11 ) ;
return - V_146 ;
}
if ( V_110 == - 1 && ! F_144 () && ! F_145 () ) {
F_146 ( L_23 ) ;
F_143 ( V_11 ) ;
return - V_146 ;
}
F_147 ( V_147 ) ;
F_148 ( V_119 ) ;
F_149 ( V_2 , V_148 ) ;
F_150 () ;
V_18 = F_103 ( V_119 , true ) ;
F_116 ( V_2 ) ;
F_117 ( V_2 ) ;
F_151 ( V_2 ) ;
F_118 ( V_2 , V_149 ) ;
V_119 -> V_120 = V_122 ;
return V_18 ;
}
static int F_152 ( struct V_36 * V_11 )
{
struct V_1 * V_2 = F_115 ( V_11 ) ;
struct V_10 * V_119 = F_102 ( V_2 ) ;
struct V_35 * V_36 = & V_25 ( V_119 ) -> V_36 ;
int V_18 ;
if ( V_110 == 0 )
return - V_150 ;
F_118 ( V_2 , V_124 ) ;
F_122 ( V_2 ) ;
V_18 = F_123 ( V_2 ) ;
if ( V_18 )
return V_18 ;
F_52 ( V_2 ) ;
V_18 = F_119 ( V_119 , true ) ;
F_153 ( V_119 ) ;
F_69 ( V_36 , 0x88488 , ( 1 << 25 ) , ( 1 << 25 ) ) ;
F_149 ( V_2 , V_151 ) ;
V_119 -> V_120 = V_152 ;
F_147 ( V_153 ) ;
return V_18 ;
}
static int F_154 ( struct V_36 * V_11 )
{
struct V_1 * V_2 = F_115 ( V_11 ) ;
struct V_10 * V_119 = F_102 ( V_2 ) ;
struct V_25 * V_26 = V_25 ( V_119 ) ;
struct V_154 * V_155 ;
if ( V_110 == 0 ) {
F_143 ( V_11 ) ;
return - V_146 ;
}
if ( V_110 == - 1 && ! F_144 () && ! F_145 () ) {
F_146 ( L_23 ) ;
F_143 ( V_11 ) ;
return - V_146 ;
}
if ( V_26 -> V_88 ) {
if ( ! V_26 -> V_88 -> V_156 ) {
F_146 ( L_24 ) ;
F_85 ( V_11 ) ;
return - V_146 ;
}
}
F_109 (crtc, &drm->dev->mode_config.crtc_list, head) {
if ( V_155 -> V_157 ) {
F_146 ( L_25 ) ;
return - V_146 ;
}
}
F_85 ( V_11 ) ;
F_155 ( V_11 ) ;
return 1 ;
}
static void F_156 ( void )
{
F_146 ( L_26 ) ;
F_146 ( L_27 , V_158 ) ;
F_146 ( L_28 , V_159 ) ;
F_146 ( L_29 , V_160 ) ;
F_146 ( L_30 , V_161 ) ;
F_146 ( L_31 , V_19 ) ;
F_146 ( L_32 , V_20 ) ;
F_146 ( L_33 , V_41 ) ;
F_146 ( L_34 , V_84 ) ;
F_146 ( L_35 , V_110 ) ;
F_146 ( L_36 , V_162 ) ;
F_146 ( L_37 , V_163 ) ;
}
struct V_10 *
F_157 ( struct V_7 * V_2 , int V_13 ,
void * * V_164 )
{
struct V_10 * V_26 ;
int V_165 ;
V_165 = F_158 ( V_2 , V_166 ,
F_5 ( V_2 ) ,
F_159 ( & V_2 -> V_11 ) , V_19 ,
V_20 , V_13 , V_164 ) ;
if ( V_165 )
return F_160 ( V_165 ) ;
V_26 = F_161 ( & V_167 , & V_2 -> V_11 ) ;
if ( ! V_26 ) {
V_165 = - V_23 ;
goto V_168;
}
V_165 = F_162 ( V_26 , L_38 , F_159 ( & V_2 -> V_11 ) ) ;
if ( V_165 < 0 )
goto V_168;
V_26 -> V_8 = V_2 ;
F_163 ( V_2 , V_26 ) ;
return V_26 ;
V_168:
F_54 ( NULL , (struct V_87 * * ) V_164 ) ;
return F_160 ( V_165 ) ;
}
static int T_3
F_164 ( void )
{
V_86 = V_169 ;
V_86 . V_170 = V_171 ;
V_167 = V_169 ;
V_167 . V_170 = V_172 ;
F_156 () ;
if ( V_84 == - 1 ) {
#ifdef F_165
if ( F_166 () )
V_84 = 0 ;
#endif
}
if ( ! V_84 )
return 0 ;
F_167 () ;
return F_168 ( & V_86 , & V_173 ) ;
}
static void T_4
F_169 ( void )
{
if ( ! V_84 )
return;
F_170 ( & V_86 , & V_173 ) ;
F_171 () ;
}

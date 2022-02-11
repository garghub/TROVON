static T_1 void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_4 )
F_2 ( & V_2 -> V_3 ) ;
F_3 ( & V_2 -> V_5 ) ;
F_4 ( V_2 ) ;
}
static T_1 void F_5 ( void )
{
struct V_1 * V_2 , * V_6 ;
F_6 () ;
F_7 (cfg, tmp, &pci_mmcfg_list, list)
F_1 ( V_2 ) ;
}
static T_1 void F_8 ( struct V_1 * V_7 )
{
struct V_1 * V_2 ;
F_9 (cfg, &pci_mmcfg_list, list) {
if ( V_2 -> V_8 > V_7 -> V_8 ||
( V_2 -> V_8 == V_7 -> V_8 &&
V_2 -> V_9 >= V_7 -> V_9 ) ) {
F_10 ( & V_7 -> V_5 , & V_2 -> V_5 ) ;
return;
}
}
F_10 ( & V_7 -> V_5 , & V_10 ) ;
}
V_1 * F_11 ( int V_8 , int V_11 )
{
struct V_1 * V_2 ;
F_9 (cfg, &pci_mmcfg_list, list)
if ( V_2 -> V_8 == V_8 &&
V_2 -> V_9 <= V_11 && V_11 <= V_2 -> V_12 )
return V_2 ;
return NULL ;
}
static const char T_1 * F_12 ( void )
{
T_2 V_13 ;
V_14 -> V_15 ( 0 , 0 , F_13 ( 0 , 0 ) , 0xce , 2 , & V_13 ) ;
V_13 = V_13 & 0xf000 ;
if ( V_13 == 0x0000 || V_13 == 0xf000 )
return NULL ;
if ( F_14 ( 0 , 0 , 255 , V_13 << 16 ) == NULL )
return NULL ;
return L_1 ;
}
static const char T_1 * F_15 ( void )
{
T_2 V_16 , V_17 = 0 , V_18 = 0 ;
V_14 -> V_15 ( 0 , 0 , F_13 ( 0 , 0 ) , 0x48 , 4 , & V_16 ) ;
if ( ! ( V_16 & 1 ) )
return NULL ;
switch ( ( V_16 >> 1 ) & 3 ) {
case 0 :
V_17 = 0xf0000000U ;
V_18 = 0x10000000U ;
break;
case 1 :
V_17 = 0xf8000000U ;
V_18 = 0x08000000U ;
break;
case 2 :
V_17 = 0xfc000000U ;
V_18 = 0x04000000U ;
break;
default:
return NULL ;
}
if ( ( V_16 & V_17 ) & 0x0fffffffU )
return NULL ;
if ( ( V_16 & V_17 ) >= 0xf0000000U )
return NULL ;
if ( F_14 ( 0 , 0 , ( V_18 >> 20 ) - 1 , V_16 & V_17 ) == NULL )
return NULL ;
return L_2 ;
}
static const char T_1 * F_16 ( void )
{
T_2 V_19 , V_20 , V_21 ;
T_3 V_22 , V_23 ;
int V_24 ;
unsigned V_25 = 0 , V_26 , V_12 ;
if ( ! ( V_27 & V_28 ) )
return NULL ;
V_21 = V_29 ;
if ( F_17 ( V_21 , & V_19 , & V_20 ) )
return NULL ;
V_23 = V_20 ;
V_23 <<= 32 ;
V_23 |= V_19 ;
if ( ! ( V_23 & V_30 ) )
return NULL ;
V_22 = V_23 & ( V_31 << V_32 ) ;
V_26 = ( V_23 >> V_33 ) &
V_34 ;
if ( ! V_26 )
return NULL ;
if ( V_26 > 8 ) {
V_25 = V_26 - 8 ;
V_26 = 8 ;
}
V_12 = ( 1 << V_26 ) - 1 ;
for ( V_24 = 0 ; V_24 < ( 1 << V_25 ) ; V_24 ++ )
if ( F_14 ( V_24 , 0 , V_12 ,
V_22 + ( 1 << 28 ) * V_24 ) == NULL ) {
F_5 () ;
return NULL ;
}
return L_3 ;
}
static const char T_1 * F_18 ( void )
{
int V_11 ;
int V_35 = 0 ;
static const T_2 V_36 = 0x90 ;
static const T_2 V_37 = 4 ;
static const T_2 V_38 = 1 << 31 ;
static const T_2 V_39 = 0xff << 16 ;
static const int V_40 = 16 ;
static const T_2 V_41 = 0x3 << 28 ;
static const int V_42 = 28 ;
static const int V_43 [] = { 0x100 , 0x80 , 0x40 , 0x20 } ;
static const T_2 V_44 [] = { 0x7ff8 , 0x7ffc , 0x7ffe , 0x7fff } ;
static const int V_45 = 25 ;
if ( ! V_46 || ! F_19 ( & V_10 ) || V_47 )
return NULL ;
V_47 = true ;
for ( V_11 = 0 ; V_11 < 256 ; V_11 ++ ) {
T_3 V_22 ;
T_2 V_48 , V_49 ;
T_4 V_50 , V_51 ;
int V_52 , V_53 , V_54 ;
V_14 -> V_15 ( 0 , V_11 , F_13 ( 0 , 0 ) , 0 , 4 , & V_48 ) ;
V_50 = V_48 & 0xffff ;
V_51 = ( V_48 >> 16 ) & 0xffff ;
if ( V_55 != V_50 || 0x0369 != V_51 )
continue;
V_14 -> V_15 ( 0 , V_11 , F_13 ( 0 , 0 ) , V_36 ,
V_37 , & V_49 ) ;
if ( ! ( V_49 & V_38 ) )
continue;
V_53 = ( V_49 & V_41 ) >> V_42 ;
V_22 = V_49 & V_44 [ V_53 ] ;
V_22 <<= V_45 ;
V_52 = ( V_49 & V_39 ) >> V_40 ;
V_54 = V_52 + V_43 [ V_53 ] - 1 ;
if ( F_14 ( 0 , V_52 , V_54 , V_22 ) == NULL )
continue;
V_35 ++ ;
}
if ( ! V_35 )
return NULL ;
return L_4 ;
}
static void T_1 F_20 ( void )
{
struct V_1 * V_2 , * V_56 ;
F_9 (cfg, &pci_mmcfg_list, list) {
if ( V_2 -> V_12 < V_2 -> V_9 )
V_2 -> V_12 = 255 ;
if ( V_2 -> V_5 . V_57 == & V_10 )
break;
V_56 = F_21 ( V_2 -> V_5 . V_57 , F_22 ( * V_2 ) , V_5 ) ;
if ( V_2 -> V_12 >= V_56 -> V_9 )
V_2 -> V_12 = V_56 -> V_9 - 1 ;
}
}
static int T_1 F_23 ( void )
{
T_2 V_48 ;
T_2 V_11 , V_58 ;
T_4 V_50 , V_51 ;
int V_24 ;
const char * V_59 ;
if ( ! V_14 )
return 0 ;
F_5 () ;
for ( V_24 = 0 ; V_24 < F_24 ( V_60 ) ; V_24 ++ ) {
V_11 = V_60 [ V_24 ] . V_11 ;
V_58 = V_60 [ V_24 ] . V_58 ;
V_14 -> V_15 ( 0 , V_11 , V_58 , 0 , 4 , & V_48 ) ;
V_50 = V_48 & 0xffff ;
V_51 = ( V_48 >> 16 ) & 0xffff ;
V_59 = NULL ;
if ( V_60 [ V_24 ] . V_50 == V_50 &&
V_60 [ V_24 ] . V_51 == V_51 )
V_59 = V_60 [ V_24 ] . F_25 () ;
if ( V_59 )
F_26 (KERN_INFO PREFIX L_5 ,
name) ;
}
F_20 () ;
return ! F_19 ( & V_10 ) ;
}
static void T_1 F_27 ( void )
{
struct V_1 * V_2 ;
F_9 (cfg, &pci_mmcfg_list, list)
F_28 ( & V_61 , & V_2 -> V_3 ) ;
V_62 = 1 ;
}
static T_5 T_1 F_29 ( struct V_63 * V_3 ,
void * V_64 )
{
struct V_65 * V_66 = V_64 ;
struct V_67 V_21 ;
T_5 V_68 ;
if ( V_3 -> type == V_69 ) {
struct V_70 * V_71 =
& V_3 -> V_64 . V_72 ;
if ( ! V_71 )
return V_73 ;
if ( ( V_66 -> V_52 >= V_71 -> V_21 ) &&
( V_66 -> V_54 < ( V_71 -> V_21 +
V_71 -> V_74 ) ) ) {
V_66 -> V_75 = 1 ;
return V_76 ;
}
}
if ( ( V_3 -> type != V_77 ) &&
( V_3 -> type != V_78 ) )
return V_73 ;
V_68 = F_30 ( V_3 , & V_21 ) ;
if ( F_31 ( V_68 ) ||
( V_21 . V_74 <= 0 ) ||
( V_21 . V_79 != V_80 ) )
return V_73 ;
if ( ( V_66 -> V_52 >= V_21 . V_81 ) &&
( V_66 -> V_54 < ( V_21 . V_81 + V_21 . V_74 ) ) ) {
V_66 -> V_75 = 1 ;
return V_76 ;
}
return V_73 ;
}
static T_5 T_1 F_32 ( T_6 V_82 , T_2 V_83 ,
void * V_84 , void * * V_85 )
{
struct V_65 * V_66 = V_84 ;
F_33 ( V_82 , V_86 ,
F_29 , V_84 ) ;
if ( V_66 -> V_75 )
return V_76 ;
return V_73 ;
}
static int T_1 F_34 ( T_3 V_52 , T_3 V_54 , unsigned V_87 )
{
struct V_65 V_66 ;
V_66 . V_52 = V_52 ;
V_66 . V_54 = V_54 - 1 ;
V_66 . V_75 = 0 ;
F_35 ( L_6 , F_32 , & V_66 , NULL ) ;
if ( ! V_66 . V_75 )
F_35 ( L_7 , F_32 , & V_66 ,
NULL ) ;
return V_66 . V_75 ;
}
static int T_1 F_36 ( T_7 V_88 ,
struct V_1 * V_2 , int V_89 )
{
T_3 V_90 = V_2 -> V_3 . V_52 ;
T_3 V_91 = F_37 ( & V_2 -> V_3 ) ;
T_3 V_92 = V_91 ;
int V_93 = 0 , V_94 ;
while ( ! V_88 ( V_90 , V_90 + V_91 , V_95 ) ) {
V_91 >>= 1 ;
if ( V_91 < ( 16UL << 20 ) )
break;
}
if ( V_91 >= ( 16UL << 20 ) || V_91 == V_92 ) {
F_26 (KERN_INFO PREFIX L_8 ,
&cfg->res,
with_e820 ? L_9 : L_10 ) ;
V_93 = 1 ;
if ( V_92 != V_91 ) {
V_2 -> V_12 = V_2 -> V_9 + ( ( V_91 >> 20 ) - 1 ) ;
V_94 = V_2 -> V_12 - V_2 -> V_9 + 1 ;
V_2 -> V_3 . V_54 = V_2 -> V_3 . V_52 +
F_38 ( V_94 ) - 1 ;
snprintf ( V_2 -> V_59 , V_96 ,
L_11 ,
V_2 -> V_8 , V_2 -> V_9 , V_2 -> V_12 ) ;
F_26 (KERN_INFO PREFIX
L_12
L_13 ,
cfg->segment, cfg->start_bus, cfg->end_bus,
&cfg->res, (unsigned long) cfg->address) ;
}
}
return V_93 ;
}
static void T_1 F_39 ( int V_97 )
{
struct V_1 * V_2 ;
F_9 (cfg, &pci_mmcfg_list, list) {
int V_93 = 0 ;
if ( ! V_97 && ! V_46 ) {
V_93 = F_36 ( F_34 , V_2 , 0 ) ;
if ( V_93 )
continue;
else
F_26 (KERN_ERR FW_BUG PREFIX
L_14
L_15 ,
&cfg->res) ;
}
if ( V_14 )
V_93 = F_36 ( V_98 , V_2 , 1 ) ;
if ( ! V_93 )
goto V_99;
}
return;
V_99:
F_26 (KERN_INFO PREFIX L_16 ) ;
F_5 () ;
}
static int T_1 F_40 ( struct V_100 * V_101 ,
struct V_102 * V_2 )
{
int V_103 ;
if ( V_2 -> V_21 < 0xFFFFFFFF )
return 0 ;
if ( ! strcmp ( V_101 -> V_104 . V_105 , L_17 ) ||
! strcmp ( V_101 -> V_104 . V_105 , L_18 ) )
return 0 ;
if ( V_101 -> V_104 . V_106 >= 1 ) {
if ( F_41 ( V_107 , & V_103 , NULL , NULL ) &&
V_103 >= 2010 )
return 0 ;
}
F_26 (KERN_ERR PREFIX L_19
L_20 , cfg->pci_segment,
cfg->start_bus_number, cfg->end_bus_number, cfg->address) ;
return - V_108 ;
}
static int T_1 F_42 ( struct V_109 * V_104 )
{
struct V_100 * V_101 ;
struct V_102 * V_110 , * V_2 ;
unsigned long V_24 ;
int V_111 ;
if ( ! V_104 )
return - V_108 ;
V_101 = (struct V_100 * ) V_104 ;
F_5 () ;
V_111 = 0 ;
V_24 = V_104 -> V_112 - sizeof( struct V_100 ) ;
while ( V_24 >= sizeof( struct V_102 ) ) {
V_111 ++ ;
V_24 -= sizeof( struct V_102 ) ;
} ;
if ( V_111 == 0 ) {
F_26 (KERN_ERR PREFIX L_21 ) ;
return - V_113 ;
}
V_110 = (struct V_102 * ) & V_101 [ 1 ] ;
for ( V_24 = 0 ; V_24 < V_111 ; V_24 ++ ) {
V_2 = & V_110 [ V_24 ] ;
if ( F_40 ( V_101 , V_2 ) ) {
F_5 () ;
return - V_113 ;
}
if ( F_14 ( V_2 -> V_114 , V_2 -> V_115 ,
V_2 -> V_116 , V_2 -> V_21 ) == NULL ) {
F_26 (KERN_WARNING PREFIX
L_22 ) ;
F_5 () ;
return - V_117 ;
}
}
return 0 ;
}
static void T_1 F_43 ( int V_97 )
{
if ( ( V_27 & V_118 ) == 0 )
return;
if ( ! V_97 && ! ( V_27 & V_119 & ~ V_118 ) )
return;
if ( V_120 )
return;
if ( V_97 ) {
if ( F_23 () )
V_120 = 1 ;
}
if ( ! V_120 )
F_44 ( V_121 , F_42 ) ;
F_39 ( V_97 ) ;
if ( F_19 ( & V_10 ) )
return;
if ( V_122 < 0 ) {
const struct V_1 * V_2 ;
F_9 (cfg, &pci_mmcfg_list, list) {
if ( V_2 -> V_8 )
break;
V_122 = V_2 -> V_12 ;
}
}
if ( F_45 () )
V_27 = ( V_27 & ~ V_119 ) | V_118 ;
else {
V_62 = 1 ;
}
}
void T_1 F_46 ( void )
{
F_43 ( 1 ) ;
}
void T_1 F_47 ( void )
{
F_43 ( 0 ) ;
}
static int T_1 F_48 ( void )
{
if ( ( V_62 == 1 ) ||
( V_27 & V_118 ) == 0 ||
F_19 ( & V_10 ) )
return 1 ;
F_27 () ;
return 0 ;
}

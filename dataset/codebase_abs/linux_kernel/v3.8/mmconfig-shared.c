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
static void F_8 ( struct V_1 * V_7 )
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
static struct V_1 * F_11 ( int V_8 , int V_11 ,
int V_12 , T_2 V_13 )
{
struct V_1 * V_7 ;
struct V_14 * V_3 ;
if ( V_13 == 0 )
return NULL ;
V_7 = F_12 ( sizeof( * V_7 ) , V_15 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_16 = V_13 ;
V_7 -> V_8 = V_8 ;
V_7 -> V_9 = V_11 ;
V_7 -> V_17 = V_12 ;
V_3 = & V_7 -> V_3 ;
V_3 -> V_11 = V_13 + F_13 ( V_11 ) ;
V_3 -> V_12 = V_13 + F_13 ( V_12 + 1 ) - 1 ;
V_3 -> V_18 = V_19 | V_20 ;
snprintf ( V_7 -> V_21 , V_22 ,
L_1 , V_8 , V_11 , V_12 ) ;
V_3 -> V_21 = V_7 -> V_21 ;
return V_7 ;
}
V_1 * F_14 ( int V_8 , int V_23 )
{
struct V_1 * V_2 ;
F_9 (cfg, &pci_mmcfg_list, list)
if ( V_2 -> V_8 == V_8 &&
V_2 -> V_9 <= V_23 && V_23 <= V_2 -> V_17 )
return V_2 ;
return NULL ;
}
static const char T_1 * F_15 ( void )
{
T_3 V_24 ;
V_25 -> V_26 ( 0 , 0 , F_16 ( 0 , 0 ) , 0xce , 2 , & V_24 ) ;
V_24 = V_24 & 0xf000 ;
if ( V_24 == 0x0000 || V_24 == 0xf000 )
return NULL ;
if ( F_17 ( 0 , 0 , 255 , V_24 << 16 ) == NULL )
return NULL ;
return L_2 ;
}
static const char T_1 * F_18 ( void )
{
T_3 V_27 , V_28 = 0 , V_29 = 0 ;
V_25 -> V_26 ( 0 , 0 , F_16 ( 0 , 0 ) , 0x48 , 4 , & V_27 ) ;
if ( ! ( V_27 & 1 ) )
return NULL ;
switch ( ( V_27 >> 1 ) & 3 ) {
case 0 :
V_28 = 0xf0000000U ;
V_29 = 0x10000000U ;
break;
case 1 :
V_28 = 0xf8000000U ;
V_29 = 0x08000000U ;
break;
case 2 :
V_28 = 0xfc000000U ;
V_29 = 0x04000000U ;
break;
default:
return NULL ;
}
if ( ( V_27 & V_28 ) & 0x0fffffffU )
return NULL ;
if ( ( V_27 & V_28 ) >= 0xf0000000U )
return NULL ;
if ( F_17 ( 0 , 0 , ( V_29 >> 20 ) - 1 , V_27 & V_28 ) == NULL )
return NULL ;
return L_3 ;
}
static const char T_1 * F_19 ( void )
{
T_3 V_30 , V_31 , V_16 ;
T_2 V_32 , V_33 ;
int V_34 ;
unsigned V_35 = 0 , V_36 , V_17 ;
if ( ! ( V_37 & V_38 ) )
return NULL ;
V_16 = V_39 ;
if ( F_20 ( V_16 , & V_30 , & V_31 ) )
return NULL ;
V_33 = V_31 ;
V_33 <<= 32 ;
V_33 |= V_30 ;
if ( ! ( V_33 & V_40 ) )
return NULL ;
V_32 = V_33 & ( V_41 << V_42 ) ;
V_36 = ( V_33 >> V_43 ) &
V_44 ;
if ( ! V_36 )
return NULL ;
if ( V_36 > 8 ) {
V_35 = V_36 - 8 ;
V_36 = 8 ;
}
V_17 = ( 1 << V_36 ) - 1 ;
for ( V_34 = 0 ; V_34 < ( 1 << V_35 ) ; V_34 ++ )
if ( F_17 ( V_34 , 0 , V_17 ,
V_32 + ( 1 << 28 ) * V_34 ) == NULL ) {
F_5 () ;
return NULL ;
}
return L_4 ;
}
static const char T_1 * F_21 ( void )
{
int V_23 ;
int V_45 = 0 ;
static const T_3 V_46 = 0x90 ;
static const T_3 V_47 = 4 ;
static const T_3 V_48 = 1 << 31 ;
static const T_3 V_49 = 0xff << 16 ;
static const int V_50 = 16 ;
static const T_3 V_51 = 0x3 << 28 ;
static const int V_52 = 28 ;
static const int V_53 [] = { 0x100 , 0x80 , 0x40 , 0x20 } ;
static const T_3 V_54 [] = { 0x7ff8 , 0x7ffc , 0x7ffe , 0x7fff } ;
static const int V_55 = 25 ;
if ( ! V_56 || ! F_22 ( & V_10 ) || V_57 )
return NULL ;
V_57 = true ;
for ( V_23 = 0 ; V_23 < 256 ; V_23 ++ ) {
T_2 V_32 ;
T_3 V_58 , V_59 ;
T_4 V_60 , V_61 ;
int V_11 , V_62 , V_12 ;
V_25 -> V_26 ( 0 , V_23 , F_16 ( 0 , 0 ) , 0 , 4 , & V_58 ) ;
V_60 = V_58 & 0xffff ;
V_61 = ( V_58 >> 16 ) & 0xffff ;
if ( V_63 != V_60 || 0x0369 != V_61 )
continue;
V_25 -> V_26 ( 0 , V_23 , F_16 ( 0 , 0 ) , V_46 ,
V_47 , & V_59 ) ;
if ( ! ( V_59 & V_48 ) )
continue;
V_62 = ( V_59 & V_51 ) >> V_52 ;
V_32 = V_59 & V_54 [ V_62 ] ;
V_32 <<= V_55 ;
V_11 = ( V_59 & V_49 ) >> V_50 ;
V_12 = V_11 + V_53 [ V_62 ] - 1 ;
if ( F_17 ( 0 , V_11 , V_12 , V_32 ) == NULL )
continue;
V_45 ++ ;
}
if ( ! V_45 )
return NULL ;
return L_5 ;
}
static void T_1 F_23 ( void )
{
struct V_1 * V_2 , * V_64 ;
F_24 (cfg, &pci_mmcfg_list, list) {
if ( V_2 -> V_17 < V_2 -> V_9 )
V_2 -> V_17 = 255 ;
if ( V_2 -> V_5 . V_65 == & V_10 )
break;
V_64 = F_25 ( V_2 -> V_5 . V_65 , F_26 ( * V_2 ) , V_5 ) ;
if ( V_2 -> V_17 >= V_64 -> V_9 )
V_2 -> V_17 = V_64 -> V_9 - 1 ;
}
}
static int T_1 F_27 ( void )
{
T_3 V_58 ;
T_3 V_23 , V_66 ;
T_4 V_60 , V_61 ;
int V_34 ;
const char * V_21 ;
if ( ! V_25 )
return 0 ;
F_5 () ;
for ( V_34 = 0 ; V_34 < F_28 ( V_67 ) ; V_34 ++ ) {
V_23 = V_67 [ V_34 ] . V_23 ;
V_66 = V_67 [ V_34 ] . V_66 ;
V_25 -> V_26 ( 0 , V_23 , V_66 , 0 , 4 , & V_58 ) ;
V_60 = V_58 & 0xffff ;
V_61 = ( V_58 >> 16 ) & 0xffff ;
V_21 = NULL ;
if ( V_67 [ V_34 ] . V_60 == V_60 &&
V_67 [ V_34 ] . V_61 == V_61 )
V_21 = V_67 [ V_34 ] . F_29 () ;
if ( V_21 )
F_30 ( V_68 L_6 , V_21 ) ;
}
F_23 () ;
return ! F_22 ( & V_10 ) ;
}
static T_5 F_31 ( struct V_69 * V_3 , void * V_70 )
{
struct V_14 * V_71 = V_70 ;
struct V_72 V_16 ;
T_5 V_73 ;
if ( V_3 -> type == V_74 ) {
struct V_75 * V_76 =
& V_3 -> V_70 . V_77 ;
if ( ! V_76 )
return V_78 ;
if ( ( V_71 -> V_11 >= V_76 -> V_16 ) &&
( V_71 -> V_12 < ( V_76 -> V_16 +
V_76 -> V_79 ) ) ) {
V_71 -> V_18 = 1 ;
return V_80 ;
}
}
if ( ( V_3 -> type != V_81 ) &&
( V_3 -> type != V_82 ) )
return V_78 ;
V_73 = F_32 ( V_3 , & V_16 ) ;
if ( F_33 ( V_73 ) ||
( V_16 . V_79 <= 0 ) ||
( V_16 . V_83 != V_84 ) )
return V_78 ;
if ( ( V_71 -> V_11 >= V_16 . V_85 ) &&
( V_71 -> V_12 < ( V_16 . V_85 + V_16 . V_79 ) ) ) {
V_71 -> V_18 = 1 ;
return V_80 ;
}
return V_78 ;
}
static T_5 F_34 ( T_6 V_86 , T_3 V_87 ,
void * V_88 , void * * V_89 )
{
struct V_14 * V_71 = V_88 ;
F_35 ( V_86 , V_90 ,
F_31 , V_88 ) ;
if ( V_71 -> V_18 )
return V_80 ;
return V_78 ;
}
static int F_36 ( T_2 V_11 , T_2 V_12 , unsigned V_91 )
{
struct V_14 V_71 ;
V_71 . V_11 = V_11 ;
V_71 . V_12 = V_12 - 1 ;
V_71 . V_18 = 0 ;
F_37 ( L_7 , F_34 , & V_71 , NULL ) ;
if ( ! V_71 . V_18 )
F_37 ( L_8 , F_34 , & V_71 ,
NULL ) ;
return V_71 . V_18 ;
}
static int T_7 F_38 ( T_8 V_92 ,
struct V_1 * V_2 ,
struct V_61 * V_93 , int V_94 )
{
T_2 V_13 = V_2 -> V_3 . V_11 ;
T_2 V_95 = F_39 ( & V_2 -> V_3 ) ;
T_2 V_96 = V_95 ;
int V_97 ;
char * V_98 = V_94 ? L_9 : L_10 ;
while ( ! V_92 ( V_13 , V_13 + V_95 , V_99 ) ) {
V_95 >>= 1 ;
if ( V_95 < ( 16UL << 20 ) )
break;
}
if ( V_95 < ( 16UL << 20 ) && V_95 != V_96 )
return 0 ;
if ( V_93 )
F_40 ( V_93 , L_11 ,
& V_2 -> V_3 , V_98 ) ;
else
F_30 ( V_68 L_11 ,
& V_2 -> V_3 , V_98 ) ;
if ( V_96 != V_95 ) {
V_2 -> V_17 = V_2 -> V_9 + ( ( V_95 >> 20 ) - 1 ) ;
V_97 = V_2 -> V_17 - V_2 -> V_9 + 1 ;
V_2 -> V_3 . V_12 = V_2 -> V_3 . V_11 +
F_13 ( V_97 ) - 1 ;
snprintf ( V_2 -> V_21 , V_22 ,
L_1 ,
V_2 -> V_8 , V_2 -> V_9 , V_2 -> V_17 ) ;
if ( V_93 )
F_40 ( V_93 ,
L_12
L_13 ,
& V_2 -> V_3 , ( unsigned long ) V_2 -> V_16 ) ;
else
F_30 ( V_68
L_14
L_13 ,
V_2 -> V_8 , V_2 -> V_9 , V_2 -> V_17 ,
& V_2 -> V_3 , ( unsigned long ) V_2 -> V_16 ) ;
}
return 1 ;
}
static int T_7 F_41 ( struct V_61 * V_93 ,
struct V_1 * V_2 , int V_100 )
{
if ( ! V_100 && ! V_56 ) {
if ( F_38 ( F_36 , V_2 , V_93 , 0 ) )
return 1 ;
if ( V_93 )
F_40 ( V_93 , V_101
L_15
L_16 ,
& V_2 -> V_3 ) ;
else
F_30 (FW_INFO PREFIX
L_15
L_16 ,
&cfg->res) ;
}
if ( V_102 )
return 1 ;
if ( V_25 )
return F_38 ( V_103 , V_2 , V_93 , 1 ) ;
return 0 ;
}
static void T_1 F_42 ( int V_100 )
{
struct V_1 * V_2 ;
F_24 (cfg, &pci_mmcfg_list, list) {
if ( F_41 ( NULL , V_2 , V_100 ) == 0 ) {
F_30 ( V_68 L_17 ) ;
F_5 () ;
return;
}
}
}
static int T_1 F_43 ( struct V_104 * V_105 ,
struct V_106 * V_2 )
{
int V_107 ;
if ( V_2 -> V_16 < 0xFFFFFFFF )
return 0 ;
if ( ! strcmp ( V_105 -> V_108 . V_109 , L_18 ) ||
! strcmp ( V_105 -> V_108 . V_109 , L_19 ) )
return 0 ;
if ( V_105 -> V_108 . V_110 >= 1 ) {
if ( F_44 ( V_111 , & V_107 , NULL , NULL ) &&
V_107 >= 2010 )
return 0 ;
}
F_45 ( V_68 L_20
L_21 , V_2 -> V_112 ,
V_2 -> V_113 , V_2 -> V_114 , V_2 -> V_16 ) ;
return - V_115 ;
}
static int T_1 F_46 ( struct V_116 * V_108 )
{
struct V_104 * V_105 ;
struct V_106 * V_117 , * V_2 ;
unsigned long V_34 ;
int V_118 ;
if ( ! V_108 )
return - V_115 ;
V_105 = (struct V_104 * ) V_108 ;
F_5 () ;
V_118 = 0 ;
V_34 = V_108 -> V_119 - sizeof( struct V_104 ) ;
while ( V_34 >= sizeof( struct V_106 ) ) {
V_118 ++ ;
V_34 -= sizeof( struct V_106 ) ;
}
if ( V_118 == 0 ) {
F_45 ( V_68 L_22 ) ;
return - V_120 ;
}
V_117 = (struct V_106 * ) & V_105 [ 1 ] ;
for ( V_34 = 0 ; V_34 < V_118 ; V_34 ++ ) {
V_2 = & V_117 [ V_34 ] ;
if ( F_43 ( V_105 , V_2 ) ) {
F_5 () ;
return - V_120 ;
}
if ( F_17 ( V_2 -> V_112 , V_2 -> V_113 ,
V_2 -> V_114 , V_2 -> V_16 ) == NULL ) {
F_47 ( V_68 L_23 ) ;
F_5 () ;
return - V_121 ;
}
}
return 0 ;
}
static void T_1 F_48 ( int V_100 )
{
F_42 ( V_100 ) ;
if ( F_22 ( & V_10 ) )
return;
if ( V_122 < 0 ) {
const struct V_1 * V_2 ;
F_24 (cfg, &pci_mmcfg_list, list) {
if ( V_2 -> V_8 )
break;
V_122 = V_2 -> V_17 ;
}
}
if ( F_49 () )
V_37 = ( V_37 & ~ V_123 ) | V_124 ;
else {
F_5 () ;
V_125 = true ;
}
}
void T_1 F_50 ( void )
{
if ( V_37 & V_124 ) {
if ( F_27 () )
V_126 = 1 ;
else
F_51 ( V_127 , F_46 ) ;
F_48 ( 1 ) ;
}
}
void T_1 F_52 ( void )
{
if ( ( V_37 & V_124 ) == 0 )
return;
if ( V_126 )
return;
if ( V_37 & V_123 & ~ V_124 ) {
F_51 ( V_127 , F_46 ) ;
F_48 ( 0 ) ;
}
}
static int T_1 F_53 ( void )
{
struct V_1 * V_2 ;
V_102 = true ;
if ( ( V_37 & V_124 ) == 0 )
return 1 ;
F_24 (cfg, &pci_mmcfg_list, list)
if ( ! V_2 -> V_3 . V_4 )
F_54 ( & V_128 , & V_2 -> V_3 ) ;
return 0 ;
}
int F_55 ( struct V_61 * V_93 , T_4 V_129 , T_9 V_11 , T_9 V_12 ,
T_10 V_13 )
{
int V_130 ;
struct V_14 * V_6 = NULL ;
struct V_1 * V_2 ;
if ( ! ( V_37 & V_124 ) || V_125 )
return - V_120 ;
if ( V_11 > V_12 )
return - V_115 ;
F_56 ( & V_131 ) ;
V_2 = F_14 ( V_129 , V_11 ) ;
if ( V_2 ) {
if ( V_2 -> V_17 < V_12 )
F_40 ( V_93 , V_101
L_24
L_25
L_26 ,
V_2 -> V_8 , V_2 -> V_9 , V_2 -> V_17 ) ;
F_57 ( & V_131 ) ;
return - V_132 ;
}
if ( ! V_13 ) {
F_57 ( & V_131 ) ;
return - V_115 ;
}
V_130 = - V_133 ;
V_2 = F_11 ( V_129 , V_11 , V_12 , V_13 ) ;
if ( V_2 == NULL ) {
F_58 ( V_93 , L_27 ) ;
V_130 = - V_121 ;
} else if ( ! F_41 ( V_93 , V_2 , 0 ) ) {
F_58 ( V_93 , V_134 L_28 ,
& V_2 -> V_3 ) ;
} else {
if ( V_102 )
V_6 = F_59 ( & V_128 ,
& V_2 -> V_3 ) ;
if ( V_6 ) {
F_58 ( V_93 ,
L_29
L_30 ,
& V_2 -> V_3 , V_6 -> V_21 , V_6 ) ;
} else if ( F_60 ( V_2 ) ) {
F_58 ( V_93 , L_31 ,
& V_2 -> V_3 ) ;
} else {
F_8 ( V_2 ) ;
F_40 ( V_93 , L_32 ,
& V_2 -> V_3 , ( unsigned long ) V_13 ) ;
V_2 = NULL ;
V_130 = 0 ;
}
}
if ( V_2 ) {
if ( V_2 -> V_3 . V_4 )
F_2 ( & V_2 -> V_3 ) ;
F_4 ( V_2 ) ;
}
F_57 ( & V_131 ) ;
return V_130 ;
}
int F_61 ( T_4 V_129 , T_9 V_11 , T_9 V_12 )
{
struct V_1 * V_2 ;
F_56 ( & V_131 ) ;
F_9 (cfg, &pci_mmcfg_list, list)
if ( V_2 -> V_8 == V_129 && V_2 -> V_9 == V_11 &&
V_2 -> V_17 == V_12 ) {
F_62 ( & V_2 -> V_5 ) ;
F_63 () ;
F_64 ( V_2 ) ;
if ( V_2 -> V_3 . V_4 )
F_2 ( & V_2 -> V_3 ) ;
F_57 ( & V_131 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
F_57 ( & V_131 ) ;
return - V_135 ;
}

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
static T_2 void F_8 ( struct V_1 * V_7 )
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
T_1 struct V_1 * F_11 ( int V_8 , int V_11 ,
int V_12 , T_3 V_13 )
{
struct V_1 * V_7 ;
V_7 = F_12 ( V_8 , V_11 , V_12 , V_13 ) ;
if ( V_7 ) {
F_13 ( & V_14 ) ;
F_8 ( V_7 ) ;
F_14 ( & V_14 ) ;
F_15 ( V_15
L_1
L_2 ,
V_8 , V_11 , V_12 , & V_7 -> V_3 , ( unsigned long ) V_13 ) ;
}
return V_7 ;
}
struct V_1 * F_16 ( int V_8 , int V_16 )
{
struct V_1 * V_2 ;
F_9 (cfg, &pci_mmcfg_list, list)
if ( V_2 -> V_8 == V_8 &&
V_2 -> V_9 <= V_16 && V_16 <= V_2 -> V_17 )
return V_2 ;
return NULL ;
}
static const char T_1 * F_17 ( void )
{
T_4 V_18 ;
V_19 -> V_20 ( 0 , 0 , F_18 ( 0 , 0 ) , 0xce , 2 , & V_18 ) ;
V_18 = V_18 & 0xf000 ;
if ( V_18 == 0x0000 || V_18 == 0xf000 )
return NULL ;
if ( F_11 ( 0 , 0 , 255 , V_18 << 16 ) == NULL )
return NULL ;
return L_3 ;
}
static const char T_1 * F_19 ( void )
{
T_4 V_21 , V_22 = 0 , V_23 = 0 ;
V_19 -> V_20 ( 0 , 0 , F_18 ( 0 , 0 ) , 0x48 , 4 , & V_21 ) ;
if ( ! ( V_21 & 1 ) )
return NULL ;
switch ( ( V_21 >> 1 ) & 3 ) {
case 0 :
V_22 = 0xf0000000U ;
V_23 = 0x10000000U ;
break;
case 1 :
V_22 = 0xf8000000U ;
V_23 = 0x08000000U ;
break;
case 2 :
V_22 = 0xfc000000U ;
V_23 = 0x04000000U ;
break;
default:
return NULL ;
}
if ( ( V_21 & V_22 ) & 0x0fffffffU )
return NULL ;
if ( ( V_21 & V_22 ) >= 0xf0000000U )
return NULL ;
if ( F_11 ( 0 , 0 , ( V_23 >> 20 ) - 1 , V_21 & V_22 ) == NULL )
return NULL ;
return L_4 ;
}
static const char T_1 * F_20 ( void )
{
T_4 V_24 , V_25 , V_26 ;
T_3 V_27 , V_28 ;
int V_29 ;
unsigned V_30 = 0 , V_31 , V_17 ;
if ( ! ( V_32 & V_33 ) )
return NULL ;
V_26 = V_34 ;
if ( F_21 ( V_26 , & V_24 , & V_25 ) )
return NULL ;
V_28 = V_25 ;
V_28 <<= 32 ;
V_28 |= V_24 ;
if ( ! ( V_28 & V_35 ) )
return NULL ;
V_27 = V_28 & ( V_36 << V_37 ) ;
V_31 = ( V_28 >> V_38 ) &
V_39 ;
if ( ! V_31 )
return NULL ;
if ( V_31 > 8 ) {
V_30 = V_31 - 8 ;
V_31 = 8 ;
}
V_17 = ( 1 << V_31 ) - 1 ;
for ( V_29 = 0 ; V_29 < ( 1 << V_30 ) ; V_29 ++ )
if ( F_11 ( V_29 , 0 , V_17 ,
V_27 + ( 1 << 28 ) * V_29 ) == NULL ) {
F_5 () ;
return NULL ;
}
return L_5 ;
}
static const char T_1 * F_22 ( void )
{
int V_16 ;
int V_40 = 0 ;
static const T_4 V_41 = 0x90 ;
static const T_4 V_42 = 4 ;
static const T_4 V_43 = 1 << 31 ;
static const T_4 V_44 = 0xff << 16 ;
static const int V_45 = 16 ;
static const T_4 V_46 = 0x3 << 28 ;
static const int V_47 = 28 ;
static const int V_48 [] = { 0x100 , 0x80 , 0x40 , 0x20 } ;
static const T_4 V_49 [] = { 0x7ff8 , 0x7ffc , 0x7ffe , 0x7fff } ;
static const int V_50 = 25 ;
if ( ! V_51 || ! F_23 ( & V_10 ) || V_52 )
return NULL ;
V_52 = true ;
for ( V_16 = 0 ; V_16 < 256 ; V_16 ++ ) {
T_3 V_27 ;
T_4 V_53 , V_54 ;
T_5 V_55 , V_56 ;
int V_11 , V_57 , V_12 ;
V_19 -> V_20 ( 0 , V_16 , F_18 ( 0 , 0 ) , 0 , 4 , & V_53 ) ;
V_55 = V_53 & 0xffff ;
V_56 = ( V_53 >> 16 ) & 0xffff ;
if ( V_58 != V_55 || 0x0369 != V_56 )
continue;
V_19 -> V_20 ( 0 , V_16 , F_18 ( 0 , 0 ) , V_41 ,
V_42 , & V_54 ) ;
if ( ! ( V_54 & V_43 ) )
continue;
V_57 = ( V_54 & V_46 ) >> V_47 ;
V_27 = V_54 & V_49 [ V_57 ] ;
V_27 <<= V_50 ;
V_11 = ( V_54 & V_44 ) >> V_45 ;
V_12 = V_11 + V_48 [ V_57 ] - 1 ;
if ( F_11 ( 0 , V_11 , V_12 , V_27 ) == NULL )
continue;
V_40 ++ ;
}
if ( ! V_40 )
return NULL ;
return L_6 ;
}
static void T_1 F_24 ( void )
{
struct V_1 * V_2 , * V_59 ;
F_25 (cfg, &pci_mmcfg_list, list) {
if ( V_2 -> V_17 < V_2 -> V_9 )
V_2 -> V_17 = 255 ;
if ( V_2 -> V_5 . V_60 == & V_10 )
break;
V_59 = F_26 ( V_2 -> V_5 . V_60 , F_27 ( * V_2 ) , V_5 ) ;
if ( V_2 -> V_17 >= V_59 -> V_9 )
V_2 -> V_17 = V_59 -> V_9 - 1 ;
}
}
static int T_1 F_28 ( void )
{
T_4 V_53 ;
T_4 V_16 , V_61 ;
T_5 V_55 , V_56 ;
int V_29 ;
const char * V_62 ;
if ( ! V_19 )
return 0 ;
F_5 () ;
for ( V_29 = 0 ; V_29 < F_29 ( V_63 ) ; V_29 ++ ) {
V_16 = V_63 [ V_29 ] . V_16 ;
V_61 = V_63 [ V_29 ] . V_61 ;
V_19 -> V_20 ( 0 , V_16 , V_61 , 0 , 4 , & V_53 ) ;
V_55 = V_53 & 0xffff ;
V_56 = ( V_53 >> 16 ) & 0xffff ;
V_62 = NULL ;
if ( V_63 [ V_29 ] . V_55 == V_55 &&
V_63 [ V_29 ] . V_56 == V_56 )
V_62 = V_63 [ V_29 ] . F_30 () ;
if ( V_62 )
F_15 ( V_15 L_7 , V_62 ) ;
}
F_24 () ;
return ! F_23 ( & V_10 ) ;
}
static T_6 T_2 F_31 ( struct V_64 * V_3 ,
void * V_65 )
{
struct V_66 * V_67 = V_65 ;
struct V_68 V_26 ;
T_6 V_69 ;
if ( V_3 -> type == V_70 ) {
struct V_71 * V_72 =
& V_3 -> V_65 . V_73 ;
if ( ! V_72 )
return V_74 ;
if ( ( V_67 -> V_11 >= V_72 -> V_26 ) &&
( V_67 -> V_12 < ( V_72 -> V_26 +
V_72 -> V_75 ) ) ) {
V_67 -> V_76 = 1 ;
return V_77 ;
}
}
if ( ( V_3 -> type != V_78 ) &&
( V_3 -> type != V_79 ) )
return V_74 ;
V_69 = F_32 ( V_3 , & V_26 ) ;
if ( F_33 ( V_69 ) ||
( V_26 . V_75 <= 0 ) ||
( V_26 . V_80 != V_81 ) )
return V_74 ;
if ( ( V_67 -> V_11 >= V_26 . V_82 ) &&
( V_67 -> V_12 < ( V_26 . V_82 + V_26 . V_75 ) ) ) {
V_67 -> V_76 = 1 ;
return V_77 ;
}
return V_74 ;
}
static T_6 T_2 F_34 ( T_7 V_83 , T_4 V_84 ,
void * V_85 , void * * V_86 )
{
struct V_66 * V_67 = V_85 ;
F_35 ( V_83 , V_87 ,
F_31 , V_85 ) ;
if ( V_67 -> V_76 )
return V_77 ;
return V_74 ;
}
static int T_2 F_36 ( T_3 V_11 , T_3 V_12 , unsigned V_88 )
{
struct V_66 V_67 ;
V_67 . V_11 = V_11 ;
V_67 . V_12 = V_12 - 1 ;
V_67 . V_76 = 0 ;
F_37 ( L_8 , F_34 , & V_67 , NULL ) ;
if ( ! V_67 . V_76 )
F_37 ( L_9 , F_34 , & V_67 ,
NULL ) ;
return V_67 . V_76 ;
}
static int T_8 F_38 ( T_9 V_89 ,
struct V_1 * V_2 ,
struct V_56 * V_90 , int V_91 )
{
T_3 V_13 = V_2 -> V_3 . V_11 ;
T_3 V_92 = F_39 ( & V_2 -> V_3 ) ;
T_3 V_93 = V_92 ;
int V_94 ;
char * V_95 = V_91 ? L_10 : L_11 ;
while ( ! V_89 ( V_13 , V_13 + V_92 , V_96 ) ) {
V_92 >>= 1 ;
if ( V_92 < ( 16UL << 20 ) )
break;
}
if ( V_92 < ( 16UL << 20 ) && V_92 != V_93 )
return 0 ;
if ( V_90 )
F_40 ( V_90 , L_12 ,
& V_2 -> V_3 , V_95 ) ;
else
F_15 ( V_15 L_12 ,
& V_2 -> V_3 , V_95 ) ;
if ( V_93 != V_92 ) {
V_2 -> V_17 = V_2 -> V_9 + ( ( V_92 >> 20 ) - 1 ) ;
V_94 = V_2 -> V_17 - V_2 -> V_9 + 1 ;
V_2 -> V_3 . V_12 = V_2 -> V_3 . V_11 +
F_41 ( V_94 ) - 1 ;
snprintf ( V_2 -> V_62 , V_97 ,
L_13 ,
V_2 -> V_8 , V_2 -> V_9 , V_2 -> V_17 ) ;
if ( V_90 )
F_40 ( V_90 ,
L_14
L_15 ,
& V_2 -> V_3 , ( unsigned long ) V_2 -> V_26 ) ;
else
F_15 ( V_15
L_16
L_15 ,
V_2 -> V_8 , V_2 -> V_9 , V_2 -> V_17 ,
& V_2 -> V_3 , ( unsigned long ) V_2 -> V_26 ) ;
}
return 1 ;
}
static int T_8 F_42 ( struct V_56 * V_90 ,
struct V_1 * V_2 , int V_98 )
{
if ( ! V_98 && ! V_51 ) {
if ( F_38 ( F_36 , V_2 , V_90 , 0 ) )
return 1 ;
if ( V_90 )
F_40 ( V_90 , V_99
L_17
L_18 ,
& V_2 -> V_3 ) ;
else
F_15 (FW_INFO PREFIX
L_17
L_18 ,
&cfg->res) ;
}
if ( V_100 )
return 1 ;
if ( V_19 )
return F_38 ( V_101 , V_2 , V_90 , 1 ) ;
return 0 ;
}
static void T_1 F_43 ( int V_98 )
{
struct V_1 * V_2 ;
F_25 (cfg, &pci_mmcfg_list, list) {
if ( F_42 ( NULL , V_2 , V_98 ) == 0 ) {
F_15 ( V_15 L_19 ) ;
F_5 () ;
return;
}
}
}
static int T_1 F_44 ( struct V_102 * V_103 ,
struct V_104 * V_2 )
{
int V_105 ;
if ( V_2 -> V_26 < 0xFFFFFFFF )
return 0 ;
if ( ! strcmp ( V_103 -> V_106 . V_107 , L_20 ) ||
! strcmp ( V_103 -> V_106 . V_107 , L_21 ) )
return 0 ;
if ( V_103 -> V_106 . V_108 >= 1 ) {
if ( F_45 ( V_109 , & V_105 , NULL , NULL ) &&
V_105 >= 2010 )
return 0 ;
}
F_46 ( V_15 L_22
L_23 , V_2 -> V_110 ,
V_2 -> V_111 , V_2 -> V_112 , V_2 -> V_26 ) ;
return - V_113 ;
}
static int T_1 F_47 ( struct V_114 * V_106 )
{
struct V_102 * V_103 ;
struct V_104 * V_115 , * V_2 ;
unsigned long V_29 ;
int V_116 ;
if ( ! V_106 )
return - V_113 ;
V_103 = (struct V_102 * ) V_106 ;
F_5 () ;
V_116 = 0 ;
V_29 = V_106 -> V_117 - sizeof( struct V_102 ) ;
while ( V_29 >= sizeof( struct V_104 ) ) {
V_116 ++ ;
V_29 -= sizeof( struct V_104 ) ;
} ;
if ( V_116 == 0 ) {
F_46 ( V_15 L_24 ) ;
return - V_118 ;
}
V_115 = (struct V_104 * ) & V_103 [ 1 ] ;
for ( V_29 = 0 ; V_29 < V_116 ; V_29 ++ ) {
V_2 = & V_115 [ V_29 ] ;
if ( F_44 ( V_103 , V_2 ) ) {
F_5 () ;
return - V_118 ;
}
if ( F_11 ( V_2 -> V_110 , V_2 -> V_111 ,
V_2 -> V_112 , V_2 -> V_26 ) == NULL ) {
F_48 ( V_15 L_25 ) ;
F_5 () ;
return - V_119 ;
}
}
return 0 ;
}
static void T_1 F_49 ( int V_98 )
{
F_43 ( V_98 ) ;
if ( F_23 ( & V_10 ) )
return;
if ( V_120 < 0 ) {
const struct V_1 * V_2 ;
F_25 (cfg, &pci_mmcfg_list, list) {
if ( V_2 -> V_8 )
break;
V_120 = V_2 -> V_17 ;
}
}
if ( F_50 () )
V_32 = ( V_32 & ~ V_121 ) | V_122 ;
else {
F_5 () ;
V_123 = true ;
}
}
void T_1 F_51 ( void )
{
if ( V_32 & V_122 ) {
if ( F_28 () )
V_124 = 1 ;
else
F_52 ( V_125 , F_47 ) ;
F_49 ( 1 ) ;
}
}
void T_1 F_53 ( void )
{
if ( ( V_32 & V_122 ) == 0 )
return;
if ( V_124 )
return;
if ( V_32 & V_121 & ~ V_122 ) {
F_52 ( V_125 , F_47 ) ;
F_49 ( 0 ) ;
}
}
static int T_1 F_54 ( void )
{
struct V_1 * V_2 ;
V_100 = true ;
if ( ( V_32 & V_122 ) == 0 )
return 1 ;
F_25 (cfg, &pci_mmcfg_list, list)
if ( ! V_2 -> V_3 . V_4 )
F_55 ( & V_126 , & V_2 -> V_3 ) ;
return 0 ;
}
int T_2 F_56 ( struct V_56 * V_90 ,
T_5 V_127 , T_10 V_11 , T_10 V_12 ,
T_11 V_13 )
{
int V_128 ;
struct V_66 * V_6 = NULL ;
struct V_1 * V_2 ;
if ( ! ( V_32 & V_122 ) || V_123 )
return - V_118 ;
if ( V_11 > V_12 )
return - V_113 ;
F_13 ( & V_14 ) ;
V_2 = F_16 ( V_127 , V_11 ) ;
if ( V_2 ) {
if ( V_2 -> V_17 < V_12 )
F_40 ( V_90 , V_99
L_26
L_27
L_28 ,
V_2 -> V_8 , V_2 -> V_9 , V_2 -> V_17 ) ;
F_14 ( & V_14 ) ;
return - V_129 ;
}
if ( ! V_13 ) {
F_14 ( & V_14 ) ;
return - V_113 ;
}
V_128 = - V_130 ;
V_2 = F_12 ( V_127 , V_11 , V_12 , V_13 ) ;
if ( V_2 == NULL ) {
F_57 ( V_90 , L_29 ) ;
V_128 = - V_119 ;
} else if ( ! F_42 ( V_90 , V_2 , 0 ) ) {
F_57 ( V_90 , V_131 L_30 ,
& V_2 -> V_3 ) ;
} else {
if ( V_100 )
V_6 = F_58 ( & V_126 ,
& V_2 -> V_3 ) ;
if ( V_6 ) {
F_57 ( V_90 ,
L_31
L_32 ,
& V_2 -> V_3 , V_6 -> V_62 , V_6 ) ;
} else if ( F_59 ( V_2 ) ) {
F_57 ( V_90 , L_33 ,
& V_2 -> V_3 ) ;
} else {
F_8 ( V_2 ) ;
F_40 ( V_90 , L_34 ,
& V_2 -> V_3 , ( unsigned long ) V_13 ) ;
V_2 = NULL ;
V_128 = 0 ;
}
}
if ( V_2 ) {
if ( V_2 -> V_3 . V_4 )
F_2 ( & V_2 -> V_3 ) ;
F_4 ( V_2 ) ;
}
F_14 ( & V_14 ) ;
return V_128 ;
}
int F_60 ( T_5 V_127 , T_10 V_11 , T_10 V_12 )
{
struct V_1 * V_2 ;
F_13 ( & V_14 ) ;
F_9 (cfg, &pci_mmcfg_list, list)
if ( V_2 -> V_8 == V_127 && V_2 -> V_9 == V_11 &&
V_2 -> V_17 == V_12 ) {
F_61 ( & V_2 -> V_5 ) ;
F_62 () ;
F_63 ( V_2 ) ;
if ( V_2 -> V_3 . V_4 )
F_2 ( & V_2 -> V_3 ) ;
F_14 ( & V_14 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
F_14 ( & V_14 ) ;
return - V_132 ;
}

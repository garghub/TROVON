static void T_1 F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_4 )
F_2 ( & V_2 -> V_3 ) ;
F_3 ( & V_2 -> V_5 ) ;
F_4 ( V_2 ) ;
}
static void T_1 F_5 ( void )
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
static struct V_1 * T_1 F_14 ( int V_8 , int V_11 ,
int V_12 , T_2 V_13 )
{
struct V_1 * V_7 ;
V_7 = F_11 ( V_8 , V_11 , V_12 , V_13 ) ;
if ( V_7 ) {
F_15 ( & V_23 ) ;
F_8 ( V_7 ) ;
F_16 ( & V_23 ) ;
F_17 ( V_24
L_2
L_3 ,
V_8 , V_11 , V_12 , & V_7 -> V_3 , ( unsigned long ) V_13 ) ;
}
return V_7 ;
}
struct V_1 * F_18 ( int V_8 , int V_25 )
{
struct V_1 * V_2 ;
F_9 (cfg, &pci_mmcfg_list, list)
if ( V_2 -> V_8 == V_8 &&
V_2 -> V_9 <= V_25 && V_25 <= V_2 -> V_17 )
return V_2 ;
return NULL ;
}
static const char * T_1 F_19 ( void )
{
T_3 V_26 ;
V_27 -> V_28 ( 0 , 0 , F_20 ( 0 , 0 ) , 0xce , 2 , & V_26 ) ;
V_26 = V_26 & 0xf000 ;
if ( V_26 == 0x0000 || V_26 == 0xf000 )
return NULL ;
if ( F_14 ( 0 , 0 , 255 , V_26 << 16 ) == NULL )
return NULL ;
return L_4 ;
}
static const char * T_1 F_21 ( void )
{
T_3 V_29 , V_30 = 0 , V_31 = 0 ;
V_27 -> V_28 ( 0 , 0 , F_20 ( 0 , 0 ) , 0x48 , 4 , & V_29 ) ;
if ( ! ( V_29 & 1 ) )
return NULL ;
switch ( ( V_29 >> 1 ) & 3 ) {
case 0 :
V_30 = 0xf0000000U ;
V_31 = 0x10000000U ;
break;
case 1 :
V_30 = 0xf8000000U ;
V_31 = 0x08000000U ;
break;
case 2 :
V_30 = 0xfc000000U ;
V_31 = 0x04000000U ;
break;
default:
return NULL ;
}
if ( ( V_29 & V_30 ) & 0x0fffffffU )
return NULL ;
if ( ( V_29 & V_30 ) >= 0xf0000000U )
return NULL ;
if ( F_14 ( 0 , 0 , ( V_31 >> 20 ) - 1 , V_29 & V_30 ) == NULL )
return NULL ;
return L_5 ;
}
static const char * T_1 F_22 ( void )
{
T_3 V_32 , V_33 , V_16 ;
T_2 V_34 , V_35 ;
int V_36 ;
unsigned V_37 = 0 , V_38 , V_17 ;
if ( ! ( V_39 & V_40 ) )
return NULL ;
V_16 = V_41 ;
if ( F_23 ( V_16 , & V_32 , & V_33 ) )
return NULL ;
V_35 = V_33 ;
V_35 <<= 32 ;
V_35 |= V_32 ;
if ( ! ( V_35 & V_42 ) )
return NULL ;
V_34 = V_35 & ( V_43 << V_44 ) ;
V_38 = ( V_35 >> V_45 ) &
V_46 ;
if ( ! V_38 )
return NULL ;
if ( V_38 > 8 ) {
V_37 = V_38 - 8 ;
V_38 = 8 ;
}
V_17 = ( 1 << V_38 ) - 1 ;
for ( V_36 = 0 ; V_36 < ( 1 << V_37 ) ; V_36 ++ )
if ( F_14 ( V_36 , 0 , V_17 ,
V_34 + ( 1 << 28 ) * V_36 ) == NULL ) {
F_5 () ;
return NULL ;
}
return L_6 ;
}
static const char * T_1 F_24 ( void )
{
int V_25 ;
int V_47 = 0 ;
static const T_3 T_4 V_48 = 0x90 ;
static const T_3 T_5 V_48 = 4 ;
static const T_3 T_6 V_48 = 1 << 31 ;
static const T_3 T_7 V_48 = 0xff << 16 ;
static const int T_8 V_48 = 16 ;
static const T_3 T_9 V_48 = 0x3 << 28 ;
static const int T_10 V_48 = 28 ;
static const int V_49 [] V_48 = {
0x100 , 0x80 , 0x40 , 0x20
} ;
static const T_3 V_50 [] V_48 = {
0x7ff8 , 0x7ffc , 0x7ffe , 0x7fff
} ;
static const int T_11 V_48 = 25 ;
if ( ! V_51 || ! F_25 ( & V_10 ) || V_52 )
return NULL ;
V_52 = true ;
for ( V_25 = 0 ; V_25 < 256 ; V_25 ++ ) {
T_2 V_34 ;
T_3 V_53 , V_54 ;
T_12 V_55 , V_56 ;
int V_11 , V_57 , V_12 ;
V_27 -> V_28 ( 0 , V_25 , F_20 ( 0 , 0 ) , 0 , 4 , & V_53 ) ;
V_55 = V_53 & 0xffff ;
V_56 = ( V_53 >> 16 ) & 0xffff ;
if ( V_58 != V_55 || 0x0369 != V_56 )
continue;
V_27 -> V_28 ( 0 , V_25 , F_20 ( 0 , 0 ) , T_4 ,
T_5 , & V_54 ) ;
if ( ! ( V_54 & T_6 ) )
continue;
V_57 = ( V_54 & T_9 ) >> T_10 ;
V_34 = V_54 & V_50 [ V_57 ] ;
V_34 <<= T_11 ;
V_11 = ( V_54 & T_7 ) >> T_8 ;
V_12 = V_11 + V_49 [ V_57 ] - 1 ;
if ( F_14 ( 0 , V_11 , V_12 , V_34 ) == NULL )
continue;
V_47 ++ ;
}
if ( ! V_47 )
return NULL ;
return L_7 ;
}
static void T_1 F_26 ( void )
{
struct V_1 * V_2 , * V_59 ;
F_27 (cfg, &pci_mmcfg_list, list) {
if ( V_2 -> V_17 < V_2 -> V_9 )
V_2 -> V_17 = 255 ;
if ( V_2 -> V_5 . V_60 == & V_10 )
break;
V_59 = F_28 ( V_2 -> V_5 . V_60 , F_29 ( * V_2 ) , V_5 ) ;
if ( V_2 -> V_17 >= V_59 -> V_9 )
V_2 -> V_17 = V_59 -> V_9 - 1 ;
}
}
static int T_1 F_30 ( void )
{
T_3 V_53 ;
T_3 V_25 , V_61 ;
T_12 V_55 , V_56 ;
int V_36 ;
const char * V_21 ;
if ( ! V_27 )
return 0 ;
F_5 () ;
for ( V_36 = 0 ; V_36 < F_31 ( V_62 ) ; V_36 ++ ) {
V_25 = V_62 [ V_36 ] . V_25 ;
V_61 = V_62 [ V_36 ] . V_61 ;
V_27 -> V_28 ( 0 , V_25 , V_61 , 0 , 4 , & V_53 ) ;
V_55 = V_53 & 0xffff ;
V_56 = ( V_53 >> 16 ) & 0xffff ;
V_21 = NULL ;
if ( V_62 [ V_36 ] . V_55 == V_55 &&
V_62 [ V_36 ] . V_56 == V_56 )
V_21 = V_62 [ V_36 ] . F_32 () ;
if ( V_21 )
F_17 ( V_24 L_8 , V_21 ) ;
}
F_26 () ;
return ! F_25 ( & V_10 ) ;
}
static T_13 F_33 ( struct V_63 * V_3 , void * V_64 )
{
struct V_14 * V_65 = V_64 ;
struct V_66 V_16 ;
T_13 V_67 ;
if ( V_3 -> type == V_68 ) {
struct V_69 * V_70 =
& V_3 -> V_64 . V_71 ;
if ( ! V_70 )
return V_72 ;
if ( ( V_65 -> V_11 >= V_70 -> V_16 ) &&
( V_65 -> V_12 < ( V_70 -> V_16 +
V_70 -> V_73 ) ) ) {
V_65 -> V_18 = 1 ;
return V_74 ;
}
}
if ( ( V_3 -> type != V_75 ) &&
( V_3 -> type != V_76 ) )
return V_72 ;
V_67 = F_34 ( V_3 , & V_16 ) ;
if ( F_35 ( V_67 ) ||
( V_16 . V_16 . V_73 <= 0 ) ||
( V_16 . V_77 != V_78 ) )
return V_72 ;
if ( ( V_65 -> V_11 >= V_16 . V_16 . V_79 ) &&
( V_65 -> V_12 < ( V_16 . V_16 . V_79 + V_16 . V_16 . V_73 ) ) ) {
V_65 -> V_18 = 1 ;
return V_74 ;
}
return V_72 ;
}
static T_13 F_36 ( T_14 V_80 , T_3 V_81 ,
void * V_82 , void * * V_83 )
{
struct V_14 * V_65 = V_82 ;
F_37 ( V_80 , V_84 ,
F_33 , V_82 ) ;
if ( V_65 -> V_18 )
return V_74 ;
return V_72 ;
}
static int F_38 ( T_2 V_11 , T_2 V_12 , unsigned V_85 )
{
struct V_14 V_65 ;
V_65 . V_11 = V_11 ;
V_65 . V_12 = V_12 - 1 ;
V_65 . V_18 = 0 ;
F_39 ( L_9 , F_36 , & V_65 , NULL ) ;
if ( ! V_65 . V_18 )
F_39 ( L_10 , F_36 , & V_65 ,
NULL ) ;
return V_65 . V_18 ;
}
static int T_15 F_40 ( T_16 V_86 ,
struct V_1 * V_2 ,
struct V_56 * V_87 , int V_88 )
{
T_2 V_13 = V_2 -> V_3 . V_11 ;
T_2 V_89 = F_41 ( & V_2 -> V_3 ) ;
T_2 V_90 = V_89 ;
int V_91 ;
char * V_92 = V_88 ? L_11 : L_12 ;
while ( ! V_86 ( V_13 , V_13 + V_89 , V_93 ) ) {
V_89 >>= 1 ;
if ( V_89 < ( 16UL << 20 ) )
break;
}
if ( V_89 < ( 16UL << 20 ) && V_89 != V_90 )
return 0 ;
if ( V_87 )
F_42 ( V_87 , L_13 ,
& V_2 -> V_3 , V_92 ) ;
else
F_17 ( V_24 L_13 ,
& V_2 -> V_3 , V_92 ) ;
if ( V_90 != V_89 ) {
V_2 -> V_17 = V_2 -> V_9 + ( ( V_89 >> 20 ) - 1 ) ;
V_91 = V_2 -> V_17 - V_2 -> V_9 + 1 ;
V_2 -> V_3 . V_12 = V_2 -> V_3 . V_11 +
F_13 ( V_91 ) - 1 ;
snprintf ( V_2 -> V_21 , V_22 ,
L_1 ,
V_2 -> V_8 , V_2 -> V_9 , V_2 -> V_17 ) ;
if ( V_87 )
F_42 ( V_87 ,
L_14
L_15 ,
& V_2 -> V_3 , ( unsigned long ) V_2 -> V_16 ) ;
else
F_17 ( V_24
L_16
L_15 ,
V_2 -> V_8 , V_2 -> V_9 , V_2 -> V_17 ,
& V_2 -> V_3 , ( unsigned long ) V_2 -> V_16 ) ;
}
return 1 ;
}
static int T_15 F_43 ( struct V_56 * V_87 ,
struct V_1 * V_2 , int V_94 )
{
if ( ! V_94 && ! V_51 ) {
if ( F_40 ( F_38 , V_2 , V_87 , 0 ) )
return 1 ;
if ( V_87 )
F_42 ( V_87 , V_95
L_17
L_18 ,
& V_2 -> V_3 ) ;
else
F_17 (FW_INFO PREFIX
L_17
L_18 ,
&cfg->res) ;
}
if ( V_96 )
return 1 ;
if ( V_27 )
return F_40 ( V_97 , V_2 , V_87 , 1 ) ;
return 0 ;
}
static void T_1 F_44 ( int V_94 )
{
struct V_1 * V_2 ;
F_27 (cfg, &pci_mmcfg_list, list) {
if ( F_43 ( NULL , V_2 , V_94 ) == 0 ) {
F_17 ( V_24 L_19 ) ;
F_5 () ;
return;
}
}
}
static int T_1 F_45 ( struct V_98 * V_99 ,
struct V_100 * V_2 )
{
int V_101 ;
if ( V_2 -> V_16 < 0xFFFFFFFF )
return 0 ;
if ( ! strncmp ( V_99 -> V_102 . V_103 , L_20 , 3 ) )
return 0 ;
if ( V_99 -> V_102 . V_104 >= 1 ) {
if ( F_46 ( V_105 , & V_101 , NULL , NULL ) &&
V_101 >= 2010 )
return 0 ;
}
F_47 ( V_24 L_21
L_22 , V_2 -> V_106 ,
V_2 -> V_107 , V_2 -> V_108 , V_2 -> V_16 ) ;
return - V_109 ;
}
static int T_1 F_48 ( struct V_110 * V_102 )
{
struct V_98 * V_99 ;
struct V_100 * V_111 , * V_2 ;
unsigned long V_36 ;
int V_112 ;
if ( ! V_102 )
return - V_109 ;
V_99 = (struct V_98 * ) V_102 ;
F_5 () ;
V_112 = 0 ;
V_36 = V_102 -> V_113 - sizeof( struct V_98 ) ;
while ( V_36 >= sizeof( struct V_100 ) ) {
V_112 ++ ;
V_36 -= sizeof( struct V_100 ) ;
}
if ( V_112 == 0 ) {
F_47 ( V_24 L_23 ) ;
return - V_114 ;
}
V_111 = (struct V_100 * ) & V_99 [ 1 ] ;
for ( V_36 = 0 ; V_36 < V_112 ; V_36 ++ ) {
V_2 = & V_111 [ V_36 ] ;
if ( F_45 ( V_99 , V_2 ) ) {
F_5 () ;
return - V_114 ;
}
if ( F_14 ( V_2 -> V_106 , V_2 -> V_107 ,
V_2 -> V_108 , V_2 -> V_16 ) == NULL ) {
F_49 ( V_24 L_24 ) ;
F_5 () ;
return - V_115 ;
}
}
return 0 ;
}
static int F_50 ( int (* F_51)( T_17 V_11 , T_17 V_89 ,
void * V_64 ) , void * V_64 )
{
struct V_1 * V_2 ;
int V_116 ;
if ( F_25 ( & V_10 ) )
return 0 ;
F_27 (cfg, &pci_mmcfg_list, list) {
V_116 = F_51 ( V_2 -> V_3 . V_11 , F_41 ( & V_2 -> V_3 ) , V_64 ) ;
if ( V_116 )
return V_116 ;
}
return 0 ;
}
static void T_1 F_52 ( int V_94 )
{
F_44 ( V_94 ) ;
if ( F_25 ( & V_10 ) )
return;
if ( V_117 < 0 ) {
const struct V_1 * V_2 ;
F_27 (cfg, &pci_mmcfg_list, list) {
if ( V_2 -> V_8 )
break;
V_117 = V_2 -> V_17 ;
}
}
if ( F_53 () )
V_39 = ( V_39 & ~ V_118 ) | V_119 ;
else {
F_5 () ;
V_120 = true ;
}
}
void T_1 F_54 ( void )
{
if ( V_39 & V_119 ) {
if ( F_30 () )
V_121 = 1 ;
else
F_55 ( V_122 , F_48 ) ;
F_52 ( 1 ) ;
F_56 () ;
}
}
void T_1 F_57 ( void )
{
if ( ( V_39 & V_119 ) == 0 )
return;
if ( V_121 )
return;
if ( V_39 & V_118 & ~ V_119 ) {
F_55 ( V_122 , F_48 ) ;
F_52 ( 0 ) ;
}
}
static int T_1 F_58 ( void )
{
struct V_1 * V_2 ;
V_96 = true ;
if ( ( V_39 & V_119 ) == 0 )
return 1 ;
F_27 (cfg, &pci_mmcfg_list, list)
if ( ! V_2 -> V_3 . V_4 )
F_59 ( & V_123 , & V_2 -> V_3 ) ;
return 0 ;
}
int F_60 ( struct V_56 * V_87 , T_12 V_124 , T_18 V_11 , T_18 V_12 ,
T_19 V_13 )
{
int V_116 ;
struct V_14 * V_6 = NULL ;
struct V_1 * V_2 ;
if ( ! ( V_39 & V_119 ) || V_120 )
return - V_114 ;
if ( V_11 > V_12 )
return - V_109 ;
F_15 ( & V_23 ) ;
V_2 = F_18 ( V_124 , V_11 ) ;
if ( V_2 ) {
if ( V_2 -> V_17 < V_12 )
F_42 ( V_87 , V_95
L_25
L_26
L_27 ,
V_2 -> V_8 , V_2 -> V_9 , V_2 -> V_17 ) ;
F_16 ( & V_23 ) ;
return - V_125 ;
}
if ( ! V_13 ) {
F_16 ( & V_23 ) ;
return - V_109 ;
}
V_116 = - V_126 ;
V_2 = F_11 ( V_124 , V_11 , V_12 , V_13 ) ;
if ( V_2 == NULL ) {
F_61 ( V_87 , L_28 ) ;
V_116 = - V_115 ;
} else if ( ! F_43 ( V_87 , V_2 , 0 ) ) {
F_61 ( V_87 , V_127 L_29 ,
& V_2 -> V_3 ) ;
} else {
if ( V_96 )
V_6 = F_62 ( & V_123 ,
& V_2 -> V_3 ) ;
if ( V_6 ) {
F_61 ( V_87 ,
L_30
L_31 ,
& V_2 -> V_3 , V_6 -> V_21 , V_6 ) ;
} else if ( F_63 ( V_2 ) ) {
F_61 ( V_87 , L_32 ,
& V_2 -> V_3 ) ;
} else {
F_8 ( V_2 ) ;
F_42 ( V_87 , L_33 ,
& V_2 -> V_3 , ( unsigned long ) V_13 ) ;
V_2 = NULL ;
V_116 = 0 ;
}
}
if ( V_2 ) {
if ( V_2 -> V_3 . V_4 )
F_2 ( & V_2 -> V_3 ) ;
F_4 ( V_2 ) ;
}
F_16 ( & V_23 ) ;
return V_116 ;
}
int F_64 ( T_12 V_124 , T_18 V_11 , T_18 V_12 )
{
struct V_1 * V_2 ;
F_15 ( & V_23 ) ;
F_9 (cfg, &pci_mmcfg_list, list)
if ( V_2 -> V_8 == V_124 && V_2 -> V_9 == V_11 &&
V_2 -> V_17 == V_12 ) {
F_65 ( & V_2 -> V_5 ) ;
F_66 () ;
F_67 ( V_2 ) ;
if ( V_2 -> V_3 . V_4 )
F_2 ( & V_2 -> V_3 ) ;
F_16 ( & V_23 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
F_16 ( & V_23 ) ;
return - V_128 ;
}

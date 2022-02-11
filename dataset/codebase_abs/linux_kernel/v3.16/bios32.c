static void F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 )
{
struct V_5 * V_6 ;
F_2 (dev, &bus->devices, bus_list) {
T_2 V_7 ;
if ( V_6 -> V_2 -> V_8 == 0 && V_6 -> V_9 == 0 )
continue;
F_3 ( V_6 , V_10 , & V_7 ) ;
if ( V_7 == 0xffff )
continue;
if ( ( V_7 & V_3 ) == 0 )
continue;
F_4 ( V_6 , V_10 , V_7 & V_3 ) ;
if ( V_4 )
F_5 ( L_1 , F_6 ( V_6 ) , V_7 ) ;
}
F_2 (dev, &bus->devices, bus_list)
if ( V_6 -> V_11 )
F_1 ( V_6 -> V_11 , V_3 , V_4 ) ;
}
void F_7 ( T_1 V_3 , int V_4 )
{
struct V_1 * V_2 ;
F_2 (bus, &pci_root_buses, node)
F_1 ( V_2 , V_3 , V_4 ) ;
}
static void F_8 ( struct V_5 * V_6 )
{
F_9 ( V_6 , V_12 , V_13 ) ;
F_4 ( V_6 , V_14 , V_15 ) ;
V_6 -> V_16 [ 0 ] . V_17 -= V_6 -> V_16 [ 0 ] . V_18 ;
V_6 -> V_16 [ 0 ] . V_18 = 0 ;
F_10 ( V_6 , 0x48 , 0xff ) ;
F_10 ( V_6 , 0x42 , 0x01 ) ;
F_10 ( V_6 , 0x40 , 0x22 ) ;
F_10 ( V_6 , 0x83 , 0x02 ) ;
F_10 ( V_6 , 0x80 , 0x11 ) ;
F_10 ( V_6 , 0x81 , 0x00 ) ;
F_4 ( V_6 , 0x44 , 0xb000 ) ;
F_11 ( 0x08 , 0x4d1 ) ;
}
static void F_12 ( struct V_5 * V_6 )
{
V_6 -> V_16 [ 0 ] . V_17 -= V_6 -> V_16 [ 0 ] . V_18 ;
V_6 -> V_16 [ 0 ] . V_18 = 0 ;
}
static void F_13 ( struct V_5 * V_6 )
{
int V_19 ;
if ( V_6 -> V_9 == 0 ) {
V_6 -> V_20 &= 0xff ;
V_6 -> V_20 |= V_21 << 8 ;
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
V_6 -> V_16 [ V_19 ] . V_18 = 0 ;
V_6 -> V_16 [ V_19 ] . V_17 = 0 ;
V_6 -> V_16 [ V_19 ] . V_23 = 0 ;
}
}
}
static void F_14 ( struct V_5 * V_6 )
{
struct V_16 * V_24 ;
int V_19 ;
if ( ( V_6 -> V_20 >> 8 ) != V_25 )
return;
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
V_24 = V_6 -> V_16 + V_19 ;
if ( ( V_24 -> V_18 & ~ 0x80 ) == 0x374 ) {
V_24 -> V_18 |= 2 ;
V_24 -> V_17 = V_24 -> V_18 ;
}
}
}
static void F_15 ( struct V_5 * V_6 )
{
F_9 ( V_6 , 0x40 , 0x80000000 ) ;
}
static void F_16 ( struct V_5 * V_6 )
{
if ( ( V_6 -> V_20 >> 8 ) == V_25 ) {
T_3 V_26 , V_27 ;
if ( V_6 -> V_20 & 0x80 ) {
V_26 = 0x1f0 ;
V_27 = 0x3f4 ;
} else {
V_26 = 0x170 ;
V_27 = 0x374 ;
}
F_9 ( V_6 , V_12 ,
V_26 | V_28 ) ;
F_9 ( V_6 , V_29 ,
V_27 | V_28 ) ;
V_6 -> V_16 [ 0 ] . V_18 = 0 ;
V_6 -> V_16 [ 0 ] . V_17 = 0 ;
V_6 -> V_16 [ 0 ] . V_23 = 0 ;
V_6 -> V_16 [ 1 ] . V_18 = 0 ;
V_6 -> V_16 [ 1 ] . V_17 = 0 ;
V_6 -> V_16 [ 1 ] . V_23 = 0 ;
} else if ( F_17 ( V_6 -> V_9 ) == 0 ) {
F_10 ( V_6 , 0x4b , 14 ) ;
F_10 ( V_6 , 0x4c , 15 ) ;
F_10 ( V_6 , 0x4d , 0x41 ) ;
F_10 ( V_6 , 0x44 , 0x17 ) ;
F_10 ( V_6 , 0x45 , 0x03 ) ;
}
}
static void F_18 ( struct V_5 * V_6 )
{
int V_19 ;
if ( ( V_6 -> V_20 >> 8 ) == V_21 ||
V_6 -> V_20 == 0x68000 ||
V_6 -> V_20 == 0x80103 ) {
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
V_6 -> V_16 [ V_19 ] . V_18 = 0 ;
V_6 -> V_16 [ V_19 ] . V_17 = 0 ;
V_6 -> V_16 [ V_19 ] . V_23 = 0 ;
}
}
}
static inline int F_19 ( struct V_5 * V_6 )
{
return ( ( V_6 -> V_30 == V_31 &&
( V_6 -> V_32 == V_33 ||
V_6 -> V_32 == V_34 ) ) ||
( V_6 -> V_30 == V_35 &&
V_6 -> V_32 == V_36 ) ) ;
}
void F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
T_2 V_37 = V_38 | V_39 | V_40 ;
F_2 (dev, &bus->devices, bus_list) {
T_2 V_7 ;
F_3 ( V_6 , V_10 , & V_7 ) ;
if ( ! ( V_7 & V_41 ) )
V_37 &= ~ V_40 ;
if ( F_19 ( V_6 ) )
V_37 &= ~ ( V_38 | V_39 ) ;
switch ( V_6 -> V_20 >> 8 ) {
case V_42 :
F_3 ( V_6 , V_43 , & V_7 ) ;
V_7 |= V_44 | V_45 ;
V_7 &= ~ ( V_46 | V_47 ) ;
F_4 ( V_6 , V_43 , V_7 ) ;
break;
case V_48 :
F_3 ( V_6 , V_49 , & V_7 ) ;
V_7 |= V_50 | V_51 ;
F_4 ( V_6 , V_49 , V_7 ) ;
break;
}
}
F_2 (dev, &bus->devices, bus_list) {
T_2 V_52 ;
F_3 ( V_6 , V_14 , & V_52 ) ;
V_52 |= V_37 ;
F_4 ( V_6 , V_14 , V_52 ) ;
F_10 ( V_6 , V_53 ,
V_54 >> 2 ) ;
}
if ( V_2 -> V_55 && V_2 -> V_55 -> V_56 == V_57 ) {
if ( V_37 & V_40 )
V_2 -> V_58 |= V_47 ;
if ( V_37 & V_39 )
V_2 -> V_58 |= V_44 ;
}
F_5 ( V_59 L_2 ,
V_2 -> V_8 , ( V_37 & V_40 ) ? L_3 : L_4 ) ;
}
void F_21 ( struct V_1 * V_2 )
{
struct V_60 * V_61 = V_2 -> V_62 ;
if ( V_61 -> V_63 )
V_61 -> V_63 ( V_2 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_60 * V_61 = V_2 -> V_62 ;
if ( V_61 -> V_64 )
V_61 -> V_64 ( V_2 ) ;
}
static T_4 F_23 ( struct V_5 * V_6 , T_4 * V_65 )
{
struct V_60 * V_61 = V_6 -> V_62 ;
int V_66 , V_67 = * V_65 ;
if ( V_61 -> V_68 )
V_66 = V_61 -> V_68 ( V_6 , V_65 ) ;
else
V_66 = F_24 ( V_6 , V_65 ) ;
if ( V_69 )
F_5 ( L_5 ,
F_6 ( V_6 ) , V_67 , * V_65 , V_66 ) ;
return V_66 ;
}
static int F_25 ( const struct V_5 * V_6 , T_4 V_66 , T_4 V_65 )
{
struct V_60 * V_61 = V_6 -> V_62 ;
int V_70 = - 1 ;
if ( V_61 -> V_71 )
V_70 = V_61 -> V_71 ( V_6 , V_66 , V_65 ) ;
if ( V_69 )
F_5 ( L_6 ,
F_6 ( V_6 ) , V_66 , V_65 , V_70 ) ;
return V_70 ;
}
static int F_26 ( int V_72 , struct V_60 * V_61 )
{
int V_73 ;
struct V_74 * V_75 ;
if ( F_27 ( & V_61 -> V_76 ) ) {
F_28 ( & V_61 -> V_76 ,
& V_77 , V_61 -> V_78 ) ;
}
F_2 (window, &sys->resources, list) {
if ( F_29 ( V_75 -> V_79 ) == V_80 )
return 0 ;
}
V_61 -> V_81 . V_18 = ( V_72 * V_82 ) ? : V_83 ;
V_61 -> V_81 . V_17 = ( V_72 + 1 ) * V_82 - 1 ;
V_61 -> V_81 . V_23 = V_80 ;
V_61 -> V_81 . V_84 = V_61 -> V_85 ;
sprintf ( V_61 -> V_85 , L_7 , V_72 ) ;
V_73 = F_30 ( & V_86 , & V_61 -> V_81 ) ;
if ( V_73 ) {
F_31 ( L_8 , V_73 ) ;
return V_73 ;
}
F_28 ( & V_61 -> V_76 , & V_61 -> V_81 ,
V_61 -> V_87 ) ;
return 0 ;
}
static void F_32 ( struct V_32 * V_88 , struct V_89 * V_90 ,
struct V_91 * V_92 )
{
struct V_60 * V_61 = NULL ;
int V_73 ;
int V_93 , V_72 ;
for ( V_93 = V_72 = 0 ; V_93 < V_90 -> V_94 ; V_93 ++ ) {
V_61 = F_33 ( sizeof( struct V_60 ) , V_95 ) ;
if ( ! V_61 )
F_34 ( L_9 ) ;
#ifdef F_35
V_61 -> V_96 = V_90 -> V_96 ;
#endif
V_61 -> V_72 = V_72 ;
V_61 -> V_68 = V_90 -> V_68 ;
V_61 -> V_71 = V_90 -> V_71 ;
V_61 -> V_97 = V_90 -> V_97 ;
V_61 -> V_63 = V_90 -> V_63 ;
V_61 -> V_64 = V_90 -> V_64 ;
F_36 ( & V_61 -> V_76 ) ;
if ( V_90 -> V_98 )
V_61 -> V_98 = V_90 -> V_98 [ V_93 ] ;
V_73 = V_90 -> V_99 ( V_93 , V_61 ) ;
if ( V_73 > 0 ) {
V_73 = F_26 ( V_93 , V_61 ) ;
if ( V_73 ) {
F_37 ( V_61 ) ;
break;
}
if ( V_90 -> V_100 )
V_61 -> V_2 = V_90 -> V_100 ( V_93 , V_61 ) ;
else
V_61 -> V_2 = F_38 ( V_88 , V_61 -> V_72 ,
V_90 -> V_101 , V_61 , & V_61 -> V_76 ) ;
if ( ! V_61 -> V_2 )
F_34 ( L_10 ) ;
V_72 = V_61 -> V_2 -> V_102 . V_17 + 1 ;
F_39 ( & V_61 -> V_103 , V_92 ) ;
} else {
F_37 ( V_61 ) ;
if ( V_73 < 0 )
break;
}
}
}
void F_40 ( struct V_32 * V_88 , struct V_89 * V_90 )
{
struct V_60 * V_61 ;
F_41 ( V_92 ) ;
F_42 ( V_104 ) ;
if ( V_90 -> V_105 )
V_90 -> V_105 () ;
F_32 ( V_88 , V_90 , & V_92 ) ;
if ( V_90 -> V_106 )
V_90 -> V_106 () ;
F_43 ( F_23 , F_25 ) ;
F_2 (sys, &head, node) {
struct V_1 * V_2 = V_61 -> V_2 ;
if ( ! F_44 ( V_107 ) ) {
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
}
F_47 ( V_2 ) ;
}
F_2 (sys, &head, node) {
struct V_1 * V_2 = V_61 -> V_2 ;
if ( V_2 && ! F_44 ( V_107 ) ) {
struct V_1 * V_108 ;
F_2 (child, &bus->children, node)
F_48 ( V_108 ) ;
}
}
}
void F_49 ( struct V_5 * V_6 )
{
}
char * T_5 F_50 ( char * V_109 )
{
if ( ! strcmp ( V_109 , L_11 ) ) {
V_69 = 1 ;
return NULL ;
} else if ( ! strcmp ( V_109 , L_12 ) ) {
F_42 ( V_107 ) ;
return NULL ;
}
return V_109 ;
}
T_6 F_51 ( void * V_110 , const struct V_16 * V_79 ,
T_6 V_111 , T_6 V_112 )
{
struct V_5 * V_6 = V_110 ;
struct V_60 * V_61 = V_6 -> V_62 ;
T_6 V_18 = V_79 -> V_18 ;
if ( V_79 -> V_23 & V_80 && V_18 & 0x300 )
V_18 = ( V_18 + 0x3ff ) & ~ 0x3ff ;
V_18 = ( V_18 + V_112 - 1 ) & ~ ( V_112 - 1 ) ;
if ( V_61 -> V_97 )
return V_61 -> V_97 ( V_6 , V_79 , V_18 , V_111 , V_112 ) ;
return V_18 ;
}
int F_52 ( struct V_5 * V_6 , int V_113 )
{
if ( F_44 ( V_107 ) )
return 0 ;
return F_53 ( V_6 , V_113 ) ;
}
int F_54 ( struct V_5 * V_6 , struct V_114 * V_115 ,
enum V_116 V_117 , int V_118 )
{
struct V_60 * V_119 = V_6 -> V_62 ;
unsigned long V_120 ;
if ( V_117 == V_121 ) {
return - V_122 ;
} else {
V_120 = V_115 -> V_123 + ( V_119 -> V_78 >> V_124 ) ;
}
V_115 -> V_125 = F_55 ( V_115 -> V_125 ) ;
if ( F_56 ( V_115 , V_115 -> V_126 , V_120 ,
V_115 -> V_127 - V_115 -> V_126 ,
V_115 -> V_125 ) )
return - V_128 ;
return 0 ;
}
void T_5 F_57 ( unsigned long V_129 )
{
struct V_130 V_131 = {
. V_132 = V_133 ,
. type = V_134 ,
. V_135 = V_82 ,
} ;
V_131 . V_129 = V_129 ;
F_58 ( & V_131 , 1 ) ;
}

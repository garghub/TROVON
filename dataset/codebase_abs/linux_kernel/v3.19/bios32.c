struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_5 ;
return V_5 -> V_7 ;
}
static void F_2 ( struct V_8 * V_6 , T_1 V_9 , int V_10 )
{
struct V_2 * V_3 ;
F_3 (dev, &bus->devices, bus_list) {
T_2 V_11 ;
if ( V_3 -> V_6 -> V_12 == 0 && V_3 -> V_13 == 0 )
continue;
F_4 ( V_3 , V_14 , & V_11 ) ;
if ( V_11 == 0xffff )
continue;
if ( ( V_11 & V_9 ) == 0 )
continue;
F_5 ( V_3 , V_14 , V_11 & V_9 ) ;
if ( V_10 )
F_6 ( L_1 , F_7 ( V_3 ) , V_11 ) ;
}
F_3 (dev, &bus->devices, bus_list)
if ( V_3 -> V_15 )
F_2 ( V_3 -> V_15 , V_9 , V_10 ) ;
}
void F_8 ( T_1 V_9 , int V_10 )
{
struct V_8 * V_6 ;
F_3 (bus, &pci_root_buses, node)
F_2 ( V_6 , V_9 , V_10 ) ;
}
static void F_9 ( struct V_2 * V_3 )
{
F_10 ( V_3 , V_16 , V_17 ) ;
F_5 ( V_3 , V_18 , V_19 ) ;
V_3 -> V_20 [ 0 ] . V_21 -= V_3 -> V_20 [ 0 ] . V_22 ;
V_3 -> V_20 [ 0 ] . V_22 = 0 ;
F_11 ( V_3 , 0x48 , 0xff ) ;
F_11 ( V_3 , 0x42 , 0x01 ) ;
F_11 ( V_3 , 0x40 , 0x22 ) ;
F_11 ( V_3 , 0x83 , 0x02 ) ;
F_11 ( V_3 , 0x80 , 0x11 ) ;
F_11 ( V_3 , 0x81 , 0x00 ) ;
F_5 ( V_3 , 0x44 , 0xb000 ) ;
F_12 ( 0x08 , 0x4d1 ) ;
}
static void F_13 ( struct V_2 * V_3 )
{
V_3 -> V_20 [ 0 ] . V_21 -= V_3 -> V_20 [ 0 ] . V_22 ;
V_3 -> V_20 [ 0 ] . V_22 = 0 ;
}
static void F_14 ( struct V_2 * V_3 )
{
int V_23 ;
if ( V_3 -> V_13 == 0 ) {
V_3 -> V_24 &= 0xff ;
V_3 -> V_24 |= V_25 << 8 ;
for ( V_23 = 0 ; V_23 < V_26 ; V_23 ++ ) {
V_3 -> V_20 [ V_23 ] . V_22 = 0 ;
V_3 -> V_20 [ V_23 ] . V_21 = 0 ;
V_3 -> V_20 [ V_23 ] . V_27 = 0 ;
}
}
}
static void F_15 ( struct V_2 * V_3 )
{
struct V_20 * V_28 ;
int V_23 ;
if ( ( V_3 -> V_24 >> 8 ) != V_29 )
return;
for ( V_23 = 0 ; V_23 < V_26 ; V_23 ++ ) {
V_28 = V_3 -> V_20 + V_23 ;
if ( ( V_28 -> V_22 & ~ 0x80 ) == 0x374 ) {
V_28 -> V_22 |= 2 ;
V_28 -> V_21 = V_28 -> V_22 ;
}
}
}
static void F_16 ( struct V_2 * V_3 )
{
F_10 ( V_3 , 0x40 , 0x80000000 ) ;
}
static void F_17 ( struct V_2 * V_3 )
{
if ( ( V_3 -> V_24 >> 8 ) == V_29 ) {
T_3 V_30 , V_31 ;
if ( V_3 -> V_24 & 0x80 ) {
V_30 = 0x1f0 ;
V_31 = 0x3f4 ;
} else {
V_30 = 0x170 ;
V_31 = 0x374 ;
}
F_10 ( V_3 , V_16 ,
V_30 | V_32 ) ;
F_10 ( V_3 , V_33 ,
V_31 | V_32 ) ;
V_3 -> V_20 [ 0 ] . V_22 = 0 ;
V_3 -> V_20 [ 0 ] . V_21 = 0 ;
V_3 -> V_20 [ 0 ] . V_27 = 0 ;
V_3 -> V_20 [ 1 ] . V_22 = 0 ;
V_3 -> V_20 [ 1 ] . V_21 = 0 ;
V_3 -> V_20 [ 1 ] . V_27 = 0 ;
} else if ( F_18 ( V_3 -> V_13 ) == 0 ) {
F_11 ( V_3 , 0x4b , 14 ) ;
F_11 ( V_3 , 0x4c , 15 ) ;
F_11 ( V_3 , 0x4d , 0x41 ) ;
F_11 ( V_3 , 0x44 , 0x17 ) ;
F_11 ( V_3 , 0x45 , 0x03 ) ;
}
}
static void F_19 ( struct V_2 * V_3 )
{
int V_23 ;
if ( ( V_3 -> V_24 >> 8 ) == V_25 ||
V_3 -> V_24 == 0x68000 ||
V_3 -> V_24 == 0x80103 ) {
for ( V_23 = 0 ; V_23 < V_26 ; V_23 ++ ) {
V_3 -> V_20 [ V_23 ] . V_22 = 0 ;
V_3 -> V_20 [ V_23 ] . V_21 = 0 ;
V_3 -> V_20 [ V_23 ] . V_27 = 0 ;
}
}
}
static inline int F_20 ( struct V_2 * V_3 )
{
return ( ( V_3 -> V_34 == V_35 &&
( V_3 -> V_36 == V_37 ||
V_3 -> V_36 == V_38 ) ) ||
( V_3 -> V_34 == V_39 &&
V_3 -> V_36 == V_40 ) ) ;
}
void F_21 ( struct V_8 * V_6 )
{
struct V_2 * V_3 ;
T_2 V_41 = V_42 | V_43 | V_44 ;
F_3 (dev, &bus->devices, bus_list) {
T_2 V_11 ;
F_4 ( V_3 , V_14 , & V_11 ) ;
if ( ! ( V_11 & V_45 ) )
V_41 &= ~ V_44 ;
if ( F_20 ( V_3 ) )
V_41 &= ~ ( V_42 | V_43 ) ;
switch ( V_3 -> V_24 >> 8 ) {
case V_46 :
F_4 ( V_3 , V_47 , & V_11 ) ;
V_11 |= V_48 | V_49 ;
V_11 &= ~ ( V_50 | V_51 ) ;
F_5 ( V_3 , V_47 , V_11 ) ;
break;
case V_52 :
F_4 ( V_3 , V_53 , & V_11 ) ;
V_11 |= V_54 | V_55 ;
F_5 ( V_3 , V_53 , V_11 ) ;
break;
}
}
F_3 (dev, &bus->devices, bus_list) {
T_2 V_56 ;
F_4 ( V_3 , V_18 , & V_56 ) ;
V_56 |= V_41 ;
F_5 ( V_3 , V_18 , V_56 ) ;
F_11 ( V_3 , V_57 ,
V_58 >> 2 ) ;
}
if ( V_6 -> V_59 && V_6 -> V_59 -> V_60 == V_61 ) {
if ( V_41 & V_44 )
V_6 -> V_62 |= V_51 ;
if ( V_41 & V_43 )
V_6 -> V_62 |= V_48 ;
}
F_22 ( L_2 ,
V_6 -> V_12 , ( V_41 & V_44 ) ? L_3 : L_4 ) ;
}
static T_4 F_23 ( struct V_2 * V_3 , T_4 * V_63 )
{
struct V_4 * V_64 = V_3 -> V_5 ;
int V_65 , V_66 = * V_63 ;
if ( V_64 -> V_67 )
V_65 = V_64 -> V_67 ( V_3 , V_63 ) ;
else
V_65 = F_24 ( V_3 , V_63 ) ;
if ( V_68 )
F_6 ( L_5 ,
F_7 ( V_3 ) , V_66 , * V_63 , V_65 ) ;
return V_65 ;
}
static int F_25 ( const struct V_2 * V_3 , T_4 V_65 , T_4 V_63 )
{
struct V_4 * V_64 = V_3 -> V_5 ;
int V_69 = - 1 ;
if ( V_64 -> V_70 )
V_69 = V_64 -> V_70 ( V_3 , V_65 , V_63 ) ;
if ( V_68 )
F_6 ( L_6 ,
F_7 ( V_3 ) , V_65 , V_63 , V_69 ) ;
return V_69 ;
}
static int F_26 ( int V_71 , struct V_4 * V_64 )
{
int V_72 ;
struct V_73 * V_74 ;
if ( F_27 ( & V_64 -> V_75 ) ) {
F_28 ( & V_64 -> V_75 ,
& V_76 , V_64 -> V_77 ) ;
}
F_3 (window, &sys->resources, list) {
if ( F_29 ( V_74 -> V_78 ) == V_79 )
return 0 ;
}
V_64 -> V_80 . V_22 = ( V_71 * V_81 ) ? : V_82 ;
V_64 -> V_80 . V_21 = ( V_71 + 1 ) * V_81 - 1 ;
V_64 -> V_80 . V_27 = V_79 ;
V_64 -> V_80 . V_83 = V_64 -> V_84 ;
sprintf ( V_64 -> V_84 , L_7 , V_71 ) ;
V_72 = F_30 ( & V_85 , & V_64 -> V_80 ) ;
if ( V_72 ) {
F_31 ( L_8 , V_72 ) ;
return V_72 ;
}
F_28 ( & V_64 -> V_75 , & V_64 -> V_80 ,
V_64 -> V_86 ) ;
return 0 ;
}
static void F_32 ( struct V_36 * V_87 , struct V_88 * V_89 ,
struct V_90 * V_91 )
{
struct V_4 * V_64 = NULL ;
int V_72 ;
int V_92 , V_71 ;
for ( V_92 = V_71 = 0 ; V_92 < V_89 -> V_93 ; V_92 ++ ) {
V_64 = F_33 ( sizeof( struct V_4 ) , V_94 ) ;
if ( ! V_64 )
F_34 ( L_9 ) ;
#ifdef F_35
V_64 -> V_95 = V_89 -> V_95 ;
#endif
#ifdef F_36
V_64 -> V_7 = V_89 -> V_7 ;
#endif
V_64 -> V_71 = V_71 ;
V_64 -> V_67 = V_89 -> V_67 ;
V_64 -> V_70 = V_89 -> V_70 ;
V_64 -> V_96 = V_89 -> V_96 ;
F_37 ( & V_64 -> V_75 ) ;
if ( V_89 -> V_97 )
V_64 -> V_97 = V_89 -> V_97 [ V_92 ] ;
V_72 = V_89 -> V_98 ( V_92 , V_64 ) ;
if ( V_72 > 0 ) {
V_72 = F_26 ( V_92 , V_64 ) ;
if ( V_72 ) {
F_38 ( V_64 ) ;
break;
}
if ( V_89 -> V_99 )
V_64 -> V_6 = V_89 -> V_99 ( V_92 , V_64 ) ;
else
V_64 -> V_6 = F_39 ( V_87 , V_64 -> V_71 ,
V_89 -> V_100 , V_64 , & V_64 -> V_75 ) ;
if ( ! V_64 -> V_6 )
F_34 ( L_10 ) ;
V_71 = V_64 -> V_6 -> V_101 . V_21 + 1 ;
F_40 ( & V_64 -> V_102 , V_91 ) ;
} else {
F_38 ( V_64 ) ;
if ( V_72 < 0 )
break;
}
}
}
void F_41 ( struct V_36 * V_87 , struct V_88 * V_89 )
{
struct V_4 * V_64 ;
F_42 ( V_91 ) ;
F_43 ( V_103 ) ;
if ( V_89 -> V_104 )
V_89 -> V_104 () ;
F_32 ( V_87 , V_89 , & V_91 ) ;
if ( V_89 -> V_105 )
V_89 -> V_105 () ;
F_44 ( F_23 , F_25 ) ;
F_3 (sys, &head, node) {
struct V_8 * V_6 = V_64 -> V_6 ;
if ( ! F_45 ( V_106 ) ) {
F_46 ( V_6 ) ;
F_47 ( V_6 ) ;
}
F_48 ( V_6 ) ;
}
F_3 (sys, &head, node) {
struct V_8 * V_6 = V_64 -> V_6 ;
if ( V_6 && ! F_45 ( V_106 ) ) {
struct V_8 * V_107 ;
F_3 (child, &bus->children, node)
F_49 ( V_107 ) ;
}
}
}
void F_50 ( struct V_2 * V_3 )
{
}
char * T_5 F_51 ( char * V_108 )
{
if ( ! strcmp ( V_108 , L_11 ) ) {
V_68 = 1 ;
return NULL ;
} else if ( ! strcmp ( V_108 , L_12 ) ) {
F_43 ( V_106 ) ;
return NULL ;
}
return V_108 ;
}
T_6 F_52 ( void * V_109 , const struct V_20 * V_78 ,
T_6 V_110 , T_6 V_111 )
{
struct V_2 * V_3 = V_109 ;
struct V_4 * V_64 = V_3 -> V_5 ;
T_6 V_22 = V_78 -> V_22 ;
if ( V_78 -> V_27 & V_79 && V_22 & 0x300 )
V_22 = ( V_22 + 0x3ff ) & ~ 0x3ff ;
V_22 = ( V_22 + V_111 - 1 ) & ~ ( V_111 - 1 ) ;
if ( V_64 -> V_96 )
return V_64 -> V_96 ( V_3 , V_78 , V_22 , V_110 , V_111 ) ;
return V_22 ;
}
int F_53 ( struct V_2 * V_3 , int V_112 )
{
if ( F_45 ( V_106 ) )
return 0 ;
return F_54 ( V_3 , V_112 ) ;
}
int F_55 ( struct V_2 * V_3 , struct V_113 * V_114 ,
enum V_115 V_116 , int V_117 )
{
struct V_4 * V_118 = V_3 -> V_5 ;
unsigned long V_119 ;
if ( V_116 == V_120 ) {
return - V_121 ;
} else {
V_119 = V_114 -> V_122 + ( V_118 -> V_77 >> V_123 ) ;
}
V_114 -> V_124 = F_56 ( V_114 -> V_124 ) ;
if ( F_57 ( V_114 , V_114 -> V_125 , V_119 ,
V_114 -> V_126 - V_114 -> V_125 ,
V_114 -> V_124 ) )
return - V_127 ;
return 0 ;
}
void T_5 F_58 ( unsigned long V_128 )
{
struct V_129 V_130 = {
. V_131 = V_132 ,
. type = V_133 ,
. V_134 = V_81 ,
} ;
V_130 . V_128 = V_128 ;
F_59 ( & V_130 , 1 ) ;
}

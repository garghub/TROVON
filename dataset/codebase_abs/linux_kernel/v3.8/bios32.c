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
struct V_12 * V_13 ;
F_8 (l, &pci_root_buses) {
struct V_1 * V_2 = F_9 ( V_13 ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
}
}
static void F_10 ( struct V_5 * V_6 )
{
F_11 ( V_6 , V_14 , V_15 ) ;
F_4 ( V_6 , V_16 , V_17 ) ;
V_6 -> V_18 [ 0 ] . V_19 -= V_6 -> V_18 [ 0 ] . V_20 ;
V_6 -> V_18 [ 0 ] . V_20 = 0 ;
F_12 ( V_6 , 0x48 , 0xff ) ;
F_12 ( V_6 , 0x42 , 0x01 ) ;
F_12 ( V_6 , 0x40 , 0x22 ) ;
F_12 ( V_6 , 0x83 , 0x02 ) ;
F_12 ( V_6 , 0x80 , 0x11 ) ;
F_12 ( V_6 , 0x81 , 0x00 ) ;
F_4 ( V_6 , 0x44 , 0xb000 ) ;
F_13 ( 0x08 , 0x4d1 ) ;
}
static void F_14 ( struct V_5 * V_6 )
{
V_6 -> V_18 [ 0 ] . V_19 -= V_6 -> V_18 [ 0 ] . V_20 ;
V_6 -> V_18 [ 0 ] . V_20 = 0 ;
}
static void F_15 ( struct V_5 * V_6 )
{
int V_21 ;
if ( V_6 -> V_9 == 0 ) {
V_6 -> V_22 &= 0xff ;
V_6 -> V_22 |= V_23 << 8 ;
for ( V_21 = 0 ; V_21 < V_24 ; V_21 ++ ) {
V_6 -> V_18 [ V_21 ] . V_20 = 0 ;
V_6 -> V_18 [ V_21 ] . V_19 = 0 ;
V_6 -> V_18 [ V_21 ] . V_25 = 0 ;
}
}
}
static void F_16 ( struct V_5 * V_6 )
{
struct V_18 * V_26 ;
int V_21 ;
if ( ( V_6 -> V_22 >> 8 ) != V_27 )
return;
for ( V_21 = 0 ; V_21 < V_24 ; V_21 ++ ) {
V_26 = V_6 -> V_18 + V_21 ;
if ( ( V_26 -> V_20 & ~ 0x80 ) == 0x374 ) {
V_26 -> V_20 |= 2 ;
V_26 -> V_19 = V_26 -> V_20 ;
}
}
}
static void F_17 ( struct V_5 * V_6 )
{
F_11 ( V_6 , 0x40 , 0x80000000 ) ;
}
static void F_18 ( struct V_5 * V_6 )
{
if ( ( V_6 -> V_22 >> 8 ) == V_27 ) {
T_3 V_28 , V_29 ;
if ( V_6 -> V_22 & 0x80 ) {
V_28 = 0x1f0 ;
V_29 = 0x3f4 ;
} else {
V_28 = 0x170 ;
V_29 = 0x374 ;
}
F_11 ( V_6 , V_14 ,
V_28 | V_30 ) ;
F_11 ( V_6 , V_31 ,
V_29 | V_30 ) ;
V_6 -> V_18 [ 0 ] . V_20 = 0 ;
V_6 -> V_18 [ 0 ] . V_19 = 0 ;
V_6 -> V_18 [ 0 ] . V_25 = 0 ;
V_6 -> V_18 [ 1 ] . V_20 = 0 ;
V_6 -> V_18 [ 1 ] . V_19 = 0 ;
V_6 -> V_18 [ 1 ] . V_25 = 0 ;
} else if ( F_19 ( V_6 -> V_9 ) == 0 ) {
F_12 ( V_6 , 0x4b , 14 ) ;
F_12 ( V_6 , 0x4c , 15 ) ;
F_12 ( V_6 , 0x4d , 0x41 ) ;
F_12 ( V_6 , 0x44 , 0x17 ) ;
F_12 ( V_6 , 0x45 , 0x03 ) ;
}
}
static void F_20 ( struct V_5 * V_6 )
{
int V_21 ;
if ( ( V_6 -> V_22 >> 8 ) == V_23 ||
V_6 -> V_22 == 0x68000 ||
V_6 -> V_22 == 0x80103 ) {
for ( V_21 = 0 ; V_21 < V_24 ; V_21 ++ ) {
V_6 -> V_18 [ V_21 ] . V_20 = 0 ;
V_6 -> V_18 [ V_21 ] . V_19 = 0 ;
V_6 -> V_18 [ V_21 ] . V_25 = 0 ;
}
}
}
static inline int F_21 ( struct V_5 * V_6 )
{
return ( ( V_6 -> V_32 == V_33 &&
( V_6 -> V_34 == V_35 ||
V_6 -> V_34 == V_36 ) ) ||
( V_6 -> V_32 == V_37 &&
V_6 -> V_34 == V_38 ) ) ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
T_2 V_39 = V_40 | V_41 | V_42 ;
F_2 (dev, &bus->devices, bus_list) {
T_2 V_7 ;
F_3 ( V_6 , V_10 , & V_7 ) ;
if ( ! ( V_7 & V_43 ) )
V_39 &= ~ V_42 ;
if ( F_21 ( V_6 ) )
V_39 &= ~ ( V_40 | V_41 ) ;
switch ( V_6 -> V_22 >> 8 ) {
case V_44 :
F_3 ( V_6 , V_45 , & V_7 ) ;
V_7 |= V_46 | V_47 ;
V_7 &= ~ ( V_48 | V_49 ) ;
F_4 ( V_6 , V_45 , V_7 ) ;
break;
case V_50 :
F_3 ( V_6 , V_51 , & V_7 ) ;
V_7 |= V_52 | V_53 ;
F_4 ( V_6 , V_51 , V_7 ) ;
break;
}
}
F_2 (dev, &bus->devices, bus_list) {
T_2 V_54 ;
F_3 ( V_6 , V_16 , & V_54 ) ;
V_54 |= V_39 ;
F_4 ( V_6 , V_16 , V_54 ) ;
F_12 ( V_6 , V_55 ,
V_56 >> 2 ) ;
}
if ( V_2 -> V_57 && V_2 -> V_57 -> V_58 == V_59 ) {
if ( V_39 & V_42 )
V_2 -> V_60 |= V_49 ;
if ( V_39 & V_41 )
V_2 -> V_60 |= V_46 ;
}
F_5 ( V_61 L_2 ,
V_2 -> V_8 , ( V_39 & V_42 ) ? L_3 : L_4 ) ;
}
static T_4 F_23 ( struct V_5 * V_6 , T_4 * V_62 )
{
struct V_63 * V_64 = V_6 -> V_65 ;
int V_66 , V_67 = * V_62 ;
if ( V_64 -> V_68 )
V_66 = V_64 -> V_68 ( V_6 , V_62 ) ;
else
V_66 = F_24 ( V_6 , V_62 ) ;
if ( V_69 )
F_5 ( L_5 ,
F_6 ( V_6 ) , V_67 , * V_62 , V_66 ) ;
return V_66 ;
}
static int F_25 ( const struct V_5 * V_6 , T_4 V_66 , T_4 V_62 )
{
struct V_63 * V_64 = V_6 -> V_65 ;
int V_70 = - 1 ;
if ( V_64 -> V_71 )
V_70 = V_64 -> V_71 ( V_6 , V_66 , V_62 ) ;
if ( V_69 )
F_5 ( L_6 ,
F_6 ( V_6 ) , V_66 , V_62 , V_70 ) ;
return V_70 ;
}
static int T_5 F_26 ( int V_72 , struct V_63 * V_64 )
{
int V_73 ;
struct V_74 * V_75 ;
if ( F_27 ( & V_64 -> V_76 ) ) {
F_28 ( & V_64 -> V_76 ,
& V_77 , V_64 -> V_78 ) ;
}
F_2 (window, &sys->resources, list) {
if ( F_29 ( V_75 -> V_79 ) == V_80 )
return 0 ;
}
V_64 -> V_81 . V_20 = ( V_72 * V_82 ) ? : V_83 ;
V_64 -> V_81 . V_19 = ( V_72 + 1 ) * V_82 - 1 ;
V_64 -> V_81 . V_25 = V_80 ;
V_64 -> V_81 . V_84 = V_64 -> V_85 ;
sprintf ( V_64 -> V_85 , L_7 , V_72 ) ;
V_73 = F_30 ( & V_86 , & V_64 -> V_81 ) ;
if ( V_73 ) {
F_31 ( L_8 , V_73 ) ;
return V_73 ;
}
F_28 ( & V_64 -> V_76 , & V_64 -> V_81 ,
V_64 -> V_87 ) ;
return 0 ;
}
static void T_5 F_32 ( struct V_88 * V_89 , struct V_12 * V_90 )
{
struct V_63 * V_64 = NULL ;
int V_73 ;
int V_91 , V_72 ;
for ( V_91 = V_72 = 0 ; V_91 < V_89 -> V_92 ; V_91 ++ ) {
V_64 = F_33 ( sizeof( struct V_63 ) , V_93 ) ;
if ( ! V_64 )
F_34 ( L_9 ) ;
#ifdef F_35
V_64 -> V_94 = V_89 -> V_94 ;
#endif
V_64 -> V_72 = V_72 ;
V_64 -> V_68 = V_89 -> V_68 ;
V_64 -> V_71 = V_89 -> V_71 ;
F_36 ( & V_64 -> V_76 ) ;
V_73 = V_89 -> V_95 ( V_91 , V_64 ) ;
if ( V_73 > 0 ) {
V_73 = F_26 ( V_91 , V_64 ) ;
if ( V_73 ) {
F_37 ( V_64 ) ;
break;
}
if ( V_89 -> V_96 )
V_64 -> V_2 = V_89 -> V_96 ( V_91 , V_64 ) ;
else
V_64 -> V_2 = F_38 ( NULL , V_64 -> V_72 ,
V_89 -> V_97 , V_64 , & V_64 -> V_76 ) ;
if ( ! V_64 -> V_2 )
F_34 ( L_10 ) ;
V_72 = V_64 -> V_2 -> V_98 . V_19 + 1 ;
F_39 ( & V_64 -> V_99 , V_90 ) ;
} else {
F_37 ( V_64 ) ;
if ( V_73 < 0 )
break;
}
}
}
void T_5 F_40 ( struct V_88 * V_89 )
{
struct V_63 * V_64 ;
F_41 ( V_90 ) ;
F_42 ( V_100 ) ;
if ( V_89 -> V_101 )
V_89 -> V_101 () ;
F_32 ( V_89 , & V_90 ) ;
if ( V_89 -> V_102 )
V_89 -> V_102 () ;
F_43 ( F_23 , F_25 ) ;
F_2 (sys, &head, node) {
struct V_1 * V_2 = V_64 -> V_2 ;
if ( ! F_44 ( V_103 ) ) {
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
F_47 ( V_2 ) ;
}
F_48 ( V_2 ) ;
}
}
void F_49 ( struct V_5 * V_6 )
{
}
char * T_5 F_50 ( char * V_104 )
{
if ( ! strcmp ( V_104 , L_11 ) ) {
V_69 = 1 ;
return NULL ;
} else if ( ! strcmp ( V_104 , L_12 ) ) {
F_42 ( V_103 ) ;
return NULL ;
}
return V_104 ;
}
T_6 F_51 ( void * V_105 , const struct V_18 * V_79 ,
T_6 V_106 , T_6 V_107 )
{
T_6 V_20 = V_79 -> V_20 ;
if ( V_79 -> V_25 & V_80 && V_20 & 0x300 )
V_20 = ( V_20 + 0x3ff ) & ~ 0x3ff ;
V_20 = ( V_20 + V_107 - 1 ) & ~ ( V_107 - 1 ) ;
return V_20 ;
}
int F_52 ( struct V_5 * V_6 , int V_108 )
{
T_2 V_54 , V_109 ;
int V_110 ;
struct V_18 * V_26 ;
F_3 ( V_6 , V_16 , & V_54 ) ;
V_109 = V_54 ;
for ( V_110 = 0 ; V_110 < 6 ; V_110 ++ ) {
if ( ! ( V_108 & ( 1 << V_110 ) ) )
continue;
V_26 = V_6 -> V_18 + V_110 ;
if ( ! V_26 -> V_20 && V_26 -> V_19 ) {
F_5 ( V_111 L_13
L_14 , F_6 ( V_6 ) ) ;
return - V_112 ;
}
if ( V_26 -> V_25 & V_80 )
V_54 |= V_17 ;
if ( V_26 -> V_25 & V_113 )
V_54 |= V_114 ;
}
if ( ( V_6 -> V_22 >> 16 ) == V_115 )
V_54 |= V_17 | V_114 ;
if ( V_54 != V_109 ) {
F_5 ( L_15 ,
F_6 ( V_6 ) , V_109 , V_54 ) ;
F_4 ( V_6 , V_16 , V_54 ) ;
}
return 0 ;
}
int F_53 ( struct V_5 * V_6 , struct V_116 * V_117 ,
enum V_118 V_119 , int V_120 )
{
struct V_63 * V_121 = V_6 -> V_65 ;
unsigned long V_122 ;
if ( V_119 == V_123 ) {
return - V_112 ;
} else {
V_122 = V_117 -> V_124 + ( V_121 -> V_78 >> V_125 ) ;
}
V_117 -> V_126 = F_54 ( V_117 -> V_126 ) ;
if ( F_55 ( V_117 , V_117 -> V_127 , V_122 ,
V_117 -> V_128 - V_117 -> V_127 ,
V_117 -> V_126 ) )
return - V_129 ;
return 0 ;
}
void T_5 F_56 ( unsigned long V_130 )
{
struct V_131 V_132 = {
. V_133 = V_134 ,
. type = V_135 ,
. V_136 = V_82 ,
} ;
V_132 . V_130 = V_130 ;
F_57 ( & V_132 , 1 ) ;
}

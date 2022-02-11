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
void F_23 ( struct V_1 * V_2 )
{
struct V_62 * V_63 = V_2 -> V_64 ;
if ( V_63 -> V_65 )
V_63 -> V_65 ( V_2 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
struct V_62 * V_63 = V_2 -> V_64 ;
if ( V_63 -> V_66 )
V_63 -> V_66 ( V_2 ) ;
}
static T_4 F_25 ( struct V_5 * V_6 , T_4 * V_67 )
{
struct V_62 * V_63 = V_6 -> V_64 ;
int V_68 , V_69 = * V_67 ;
if ( V_63 -> V_70 )
V_68 = V_63 -> V_70 ( V_6 , V_67 ) ;
else
V_68 = F_26 ( V_6 , V_67 ) ;
if ( V_71 )
F_5 ( L_5 ,
F_6 ( V_6 ) , V_69 , * V_67 , V_68 ) ;
return V_68 ;
}
static int F_27 ( const struct V_5 * V_6 , T_4 V_68 , T_4 V_67 )
{
struct V_62 * V_63 = V_6 -> V_64 ;
int V_72 = - 1 ;
if ( V_63 -> V_73 )
V_72 = V_63 -> V_73 ( V_6 , V_68 , V_67 ) ;
if ( V_71 )
F_5 ( L_6 ,
F_6 ( V_6 ) , V_68 , V_67 , V_72 ) ;
return V_72 ;
}
static int F_28 ( int V_74 , struct V_62 * V_63 )
{
int V_75 ;
struct V_76 * V_77 ;
if ( F_29 ( & V_63 -> V_78 ) ) {
F_30 ( & V_63 -> V_78 ,
& V_79 , V_63 -> V_80 ) ;
}
F_2 (window, &sys->resources, list) {
if ( F_31 ( V_77 -> V_81 ) == V_82 )
return 0 ;
}
V_63 -> V_83 . V_20 = ( V_74 * V_84 ) ? : V_85 ;
V_63 -> V_83 . V_19 = ( V_74 + 1 ) * V_84 - 1 ;
V_63 -> V_83 . V_25 = V_82 ;
V_63 -> V_83 . V_86 = V_63 -> V_87 ;
sprintf ( V_63 -> V_87 , L_7 , V_74 ) ;
V_75 = F_32 ( & V_88 , & V_63 -> V_83 ) ;
if ( V_75 ) {
F_33 ( L_8 , V_75 ) ;
return V_75 ;
}
F_30 ( & V_63 -> V_78 , & V_63 -> V_83 ,
V_63 -> V_89 ) ;
return 0 ;
}
static void F_34 ( struct V_34 * V_90 , struct V_91 * V_92 ,
struct V_12 * V_93 )
{
struct V_62 * V_63 = NULL ;
int V_75 ;
int V_94 , V_74 ;
for ( V_94 = V_74 = 0 ; V_94 < V_92 -> V_95 ; V_94 ++ ) {
V_63 = F_35 ( sizeof( struct V_62 ) , V_96 ) ;
if ( ! V_63 )
F_36 ( L_9 ) ;
#ifdef F_37
V_63 -> V_97 = V_92 -> V_97 ;
#endif
V_63 -> V_74 = V_74 ;
V_63 -> V_70 = V_92 -> V_70 ;
V_63 -> V_73 = V_92 -> V_73 ;
V_63 -> V_98 = V_92 -> V_98 ;
V_63 -> V_65 = V_92 -> V_65 ;
V_63 -> V_66 = V_92 -> V_66 ;
F_38 ( & V_63 -> V_78 ) ;
if ( V_92 -> V_99 )
V_63 -> V_99 = V_92 -> V_99 [ V_94 ] ;
V_75 = V_92 -> V_100 ( V_94 , V_63 ) ;
if ( V_75 > 0 ) {
V_75 = F_28 ( V_94 , V_63 ) ;
if ( V_75 ) {
F_39 ( V_63 ) ;
break;
}
if ( V_92 -> V_101 )
V_63 -> V_2 = V_92 -> V_101 ( V_94 , V_63 ) ;
else
V_63 -> V_2 = F_40 ( V_90 , V_63 -> V_74 ,
V_92 -> V_102 , V_63 , & V_63 -> V_78 ) ;
if ( ! V_63 -> V_2 )
F_36 ( L_10 ) ;
V_74 = V_63 -> V_2 -> V_103 . V_19 + 1 ;
F_41 ( & V_63 -> V_104 , V_93 ) ;
} else {
F_39 ( V_63 ) ;
if ( V_75 < 0 )
break;
}
}
}
void F_42 ( struct V_34 * V_90 , struct V_91 * V_92 )
{
struct V_62 * V_63 ;
F_43 ( V_93 ) ;
F_44 ( V_105 ) ;
if ( V_92 -> V_106 )
V_92 -> V_106 () ;
F_34 ( V_90 , V_92 , & V_93 ) ;
if ( V_92 -> V_107 )
V_92 -> V_107 () ;
F_45 ( F_25 , F_27 ) ;
F_2 (sys, &head, node) {
struct V_1 * V_2 = V_63 -> V_2 ;
if ( ! F_46 ( V_108 ) ) {
F_47 ( V_2 ) ;
F_48 ( V_2 ) ;
}
F_49 ( V_2 ) ;
}
}
void F_50 ( struct V_5 * V_6 )
{
}
char * T_5 F_51 ( char * V_109 )
{
if ( ! strcmp ( V_109 , L_11 ) ) {
V_71 = 1 ;
return NULL ;
} else if ( ! strcmp ( V_109 , L_12 ) ) {
F_44 ( V_108 ) ;
return NULL ;
}
return V_109 ;
}
T_6 F_52 ( void * V_110 , const struct V_18 * V_81 ,
T_6 V_111 , T_6 V_112 )
{
struct V_5 * V_6 = V_110 ;
struct V_62 * V_63 = V_6 -> V_64 ;
T_6 V_20 = V_81 -> V_20 ;
if ( V_81 -> V_25 & V_82 && V_20 & 0x300 )
V_20 = ( V_20 + 0x3ff ) & ~ 0x3ff ;
V_20 = ( V_20 + V_112 - 1 ) & ~ ( V_112 - 1 ) ;
if ( V_63 -> V_98 )
return V_63 -> V_98 ( V_6 , V_81 , V_20 , V_111 , V_112 ) ;
return V_20 ;
}
int F_53 ( struct V_5 * V_6 , int V_113 )
{
T_2 V_54 , V_114 ;
int V_115 ;
struct V_18 * V_26 ;
F_3 ( V_6 , V_16 , & V_54 ) ;
V_114 = V_54 ;
for ( V_115 = 0 ; V_115 < 6 ; V_115 ++ ) {
if ( ! ( V_113 & ( 1 << V_115 ) ) )
continue;
V_26 = V_6 -> V_18 + V_115 ;
if ( ! V_26 -> V_20 && V_26 -> V_19 ) {
F_5 ( V_116 L_13
L_14 , F_6 ( V_6 ) ) ;
return - V_117 ;
}
if ( V_26 -> V_25 & V_82 )
V_54 |= V_17 ;
if ( V_26 -> V_25 & V_118 )
V_54 |= V_119 ;
}
if ( ( V_6 -> V_22 >> 16 ) == V_120 )
V_54 |= V_17 | V_119 ;
if ( V_54 != V_114 ) {
F_5 ( L_15 ,
F_6 ( V_6 ) , V_114 , V_54 ) ;
F_4 ( V_6 , V_16 , V_54 ) ;
}
return 0 ;
}
int F_54 ( struct V_5 * V_6 , struct V_121 * V_122 ,
enum V_123 V_124 , int V_125 )
{
struct V_62 * V_126 = V_6 -> V_64 ;
unsigned long V_127 ;
if ( V_124 == V_128 ) {
return - V_117 ;
} else {
V_127 = V_122 -> V_129 + ( V_126 -> V_80 >> V_130 ) ;
}
V_122 -> V_131 = F_55 ( V_122 -> V_131 ) ;
if ( F_56 ( V_122 , V_122 -> V_132 , V_127 ,
V_122 -> V_133 - V_122 -> V_132 ,
V_122 -> V_131 ) )
return - V_134 ;
return 0 ;
}
void T_5 F_57 ( unsigned long V_135 )
{
struct V_136 V_137 = {
. V_138 = V_139 ,
. type = V_140 ,
. V_141 = V_84 ,
} ;
V_137 . V_135 = V_135 ;
F_58 ( & V_137 , 1 ) ;
}

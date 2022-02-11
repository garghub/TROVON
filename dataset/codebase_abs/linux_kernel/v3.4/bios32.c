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
static void T_3 F_10 ( struct V_5 * V_6 )
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
static void T_3 F_14 ( struct V_5 * V_6 )
{
V_6 -> V_18 [ 0 ] . V_19 -= V_6 -> V_18 [ 0 ] . V_20 ;
V_6 -> V_18 [ 0 ] . V_20 = 0 ;
}
static void T_3 F_15 ( struct V_5 * V_6 )
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
static void T_3 F_16 ( struct V_5 * V_6 )
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
static void T_3 F_17 ( struct V_5 * V_6 )
{
F_11 ( V_6 , 0x40 , 0x80000000 ) ;
}
static void T_3 F_18 ( struct V_5 * V_6 )
{
if ( ( V_6 -> V_22 >> 8 ) == V_27 ) {
T_4 V_28 , V_29 ;
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
static void T_5 F_20 ( struct V_5 * V_6 )
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
void T_3 F_21 ( struct V_5 * V_6 , int V_32 )
{
if ( V_33 )
F_5 ( L_2 , V_32 , F_6 ( V_6 ) ) ;
F_12 ( V_6 , V_34 , V_32 ) ;
}
static inline int F_22 ( struct V_5 * V_6 )
{
return ( ( V_6 -> V_35 == V_36 &&
( V_6 -> V_37 == V_38 ||
V_6 -> V_37 == V_39 ) ) ||
( V_6 -> V_35 == V_40 &&
V_6 -> V_37 == V_41 ) ) ;
}
void F_23 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
T_2 V_42 = V_43 | V_44 | V_45 ;
F_2 (dev, &bus->devices, bus_list) {
T_2 V_7 ;
F_3 ( V_6 , V_10 , & V_7 ) ;
if ( ! ( V_7 & V_46 ) )
V_42 &= ~ V_45 ;
if ( F_22 ( V_6 ) )
V_42 &= ~ ( V_43 | V_44 ) ;
switch ( V_6 -> V_22 >> 8 ) {
case V_47 :
F_3 ( V_6 , V_48 , & V_7 ) ;
V_7 |= V_49 | V_50 ;
V_7 &= ~ ( V_51 | V_52 ) ;
F_4 ( V_6 , V_48 , V_7 ) ;
break;
case V_53 :
F_3 ( V_6 , V_54 , & V_7 ) ;
V_7 |= V_55 | V_56 ;
F_4 ( V_6 , V_54 , V_7 ) ;
break;
}
}
F_2 (dev, &bus->devices, bus_list) {
T_2 V_57 ;
F_3 ( V_6 , V_16 , & V_57 ) ;
V_57 |= V_42 ;
F_4 ( V_6 , V_16 , V_57 ) ;
F_12 ( V_6 , V_58 ,
V_59 >> 2 ) ;
}
if ( V_2 -> V_60 && V_2 -> V_60 -> V_61 == V_62 ) {
if ( V_42 & V_45 )
V_2 -> V_63 |= V_52 ;
if ( V_42 & V_44 )
V_2 -> V_63 |= V_49 ;
}
F_5 ( V_64 L_3 ,
V_2 -> V_8 , ( V_42 & V_45 ) ? L_4 : L_5 ) ;
}
static T_6 T_3 F_24 ( struct V_5 * V_6 , T_6 * V_65 )
{
struct V_66 * V_67 = V_6 -> V_68 ;
int V_69 = 0 , V_70 = * V_65 ;
if ( V_67 -> V_71 )
V_69 = V_67 -> V_71 ( V_6 , V_65 ) ;
if ( V_33 )
F_5 ( L_6 ,
F_6 ( V_6 ) , V_70 , * V_65 , V_69 ) ;
return V_69 ;
}
static int F_25 ( const struct V_5 * V_6 , T_6 V_69 , T_6 V_65 )
{
struct V_66 * V_67 = V_6 -> V_68 ;
int V_32 = - 1 ;
if ( V_67 -> V_72 )
V_32 = V_67 -> V_72 ( V_6 , V_69 , V_65 ) ;
if ( V_33 )
F_5 ( L_7 ,
F_6 ( V_6 ) , V_69 , V_65 , V_32 ) ;
return V_32 ;
}
static void T_5 F_26 ( struct V_73 * V_74 )
{
struct V_66 * V_67 = NULL ;
int V_75 ;
int V_76 , V_77 ;
for ( V_76 = V_77 = 0 ; V_76 < V_74 -> V_78 ; V_76 ++ ) {
V_67 = F_27 ( sizeof( struct V_66 ) , V_79 ) ;
if ( ! V_67 )
F_28 ( L_8 ) ;
#ifdef F_29
V_67 -> V_80 = V_74 -> V_80 ;
#endif
V_67 -> V_74 = V_74 ;
V_67 -> V_77 = V_77 ;
V_67 -> V_71 = V_74 -> V_71 ;
V_67 -> V_72 = V_74 -> V_72 ;
F_30 ( & V_67 -> V_81 ) ;
V_75 = V_74 -> V_82 ( V_76 , V_67 ) ;
if ( V_75 > 0 ) {
if ( F_31 ( & V_67 -> V_81 ) ) {
F_32 ( & V_67 -> V_81 ,
& V_83 , V_67 -> V_84 ) ;
F_32 ( & V_67 -> V_81 ,
& V_85 , V_67 -> V_86 ) ;
}
V_67 -> V_2 = V_74 -> V_87 ( V_76 , V_67 ) ;
if ( ! V_67 -> V_2 )
F_28 ( L_9 ) ;
V_77 = V_67 -> V_2 -> V_11 + 1 ;
F_33 ( & V_67 -> V_88 , & V_74 -> V_89 ) ;
} else {
F_34 ( V_67 ) ;
if ( V_75 < 0 )
break;
}
}
}
void T_5 F_35 ( struct V_73 * V_74 )
{
struct V_66 * V_67 ;
F_30 ( & V_74 -> V_89 ) ;
F_36 ( V_90 ) ;
if ( V_74 -> V_91 )
V_74 -> V_91 () ;
F_26 ( V_74 ) ;
if ( V_74 -> V_92 )
V_74 -> V_92 () ;
F_37 ( F_24 , F_25 ) ;
F_2 (sys, &hw->buses, node) {
struct V_1 * V_2 = V_67 -> V_2 ;
if ( ! F_38 ( V_93 ) ) {
F_39 ( V_2 ) ;
F_40 ( V_2 ) ;
F_41 ( V_2 ) ;
}
F_42 ( V_2 ) ;
}
}
void F_43 ( struct V_5 * V_6 )
{
}
char * T_5 F_44 ( char * V_94 )
{
if ( ! strcmp ( V_94 , L_10 ) ) {
V_33 = 1 ;
return NULL ;
} else if ( ! strcmp ( V_94 , L_11 ) ) {
F_36 ( V_93 ) ;
return NULL ;
}
return V_94 ;
}
T_7 F_45 ( void * V_95 , const struct V_18 * V_96 ,
T_7 V_97 , T_7 V_98 )
{
T_7 V_20 = V_96 -> V_20 ;
if ( V_96 -> V_25 & V_99 && V_20 & 0x300 )
V_20 = ( V_20 + 0x3ff ) & ~ 0x3ff ;
V_20 = ( V_20 + V_98 - 1 ) & ~ ( V_98 - 1 ) ;
return V_20 ;
}
int F_46 ( struct V_5 * V_6 , int V_100 )
{
T_2 V_57 , V_101 ;
int V_102 ;
struct V_18 * V_26 ;
F_3 ( V_6 , V_16 , & V_57 ) ;
V_101 = V_57 ;
for ( V_102 = 0 ; V_102 < 6 ; V_102 ++ ) {
if ( ! ( V_100 & ( 1 << V_102 ) ) )
continue;
V_26 = V_6 -> V_18 + V_102 ;
if ( ! V_26 -> V_20 && V_26 -> V_19 ) {
F_5 ( V_103 L_12
L_13 , F_6 ( V_6 ) ) ;
return - V_104 ;
}
if ( V_26 -> V_25 & V_99 )
V_57 |= V_17 ;
if ( V_26 -> V_25 & V_105 )
V_57 |= V_106 ;
}
if ( ( V_6 -> V_22 >> 16 ) == V_107 )
V_57 |= V_17 | V_106 ;
if ( V_57 != V_101 ) {
F_5 ( L_14 ,
F_6 ( V_6 ) , V_101 , V_57 ) ;
F_4 ( V_6 , V_16 , V_57 ) ;
}
return 0 ;
}
int F_47 ( struct V_5 * V_6 , struct V_108 * V_109 ,
enum V_110 V_111 , int V_112 )
{
struct V_66 * V_113 = V_6 -> V_68 ;
unsigned long V_114 ;
if ( V_111 == V_115 ) {
return - V_104 ;
} else {
V_114 = V_109 -> V_116 + ( V_113 -> V_86 >> V_117 ) ;
}
V_109 -> V_118 = F_48 ( V_109 -> V_118 ) ;
if ( F_49 ( V_109 , V_109 -> V_119 , V_114 ,
V_109 -> V_120 - V_109 -> V_119 ,
V_109 -> V_118 ) )
return - V_121 ;
return 0 ;
}

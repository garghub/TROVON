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
static void T_3
F_23 ( struct V_42 * V_43 , struct V_5 * V_6 )
{
T_6 V_44 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_24 ; V_21 ++ ) {
if ( V_6 -> V_18 [ V_21 ] . V_20 == 0 )
continue;
if ( V_6 -> V_18 [ V_21 ] . V_25 & V_45 )
V_44 = V_43 -> V_46 ;
else
V_44 = V_43 -> V_47 ;
V_6 -> V_18 [ V_21 ] . V_20 += V_44 ;
V_6 -> V_18 [ V_21 ] . V_19 += V_44 ;
}
}
static void T_3
F_24 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
struct V_5 * V_6 = V_2 -> V_48 ;
int V_21 ;
if ( ! V_6 ) {
for ( V_21 = 0 ; V_21 < 3 ; V_21 ++ )
V_2 -> V_18 [ V_21 ] = V_43 -> V_18 [ V_21 ] ;
}
}
void F_25 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_49 ;
struct V_5 * V_6 ;
T_2 V_50 = V_51 | V_52 | V_53 ;
F_24 ( V_2 , V_43 ) ;
F_2 (dev, &bus->devices, bus_list) {
T_2 V_7 ;
F_23 ( V_43 , V_6 ) ;
F_3 ( V_6 , V_10 , & V_7 ) ;
if ( ! ( V_7 & V_54 ) )
V_50 &= ~ V_53 ;
if ( F_22 ( V_6 ) )
V_50 &= ~ ( V_51 | V_52 ) ;
switch ( V_6 -> V_22 >> 8 ) {
case V_55 :
F_3 ( V_6 , V_56 , & V_7 ) ;
V_7 |= V_57 | V_58 ;
V_7 &= ~ ( V_59 | V_60 ) ;
F_4 ( V_6 , V_56 , V_7 ) ;
break;
case V_61 :
F_3 ( V_6 , V_62 , & V_7 ) ;
V_7 |= V_63 | V_64 ;
F_4 ( V_6 , V_62 , V_7 ) ;
break;
}
}
F_2 (dev, &bus->devices, bus_list) {
T_2 V_65 ;
F_3 ( V_6 , V_16 , & V_65 ) ;
V_65 |= V_50 ;
F_4 ( V_6 , V_16 , V_65 ) ;
F_12 ( V_6 , V_66 ,
V_67 >> 2 ) ;
}
if ( V_2 -> V_48 && V_2 -> V_48 -> V_68 == V_69 ) {
if ( V_50 & V_53 )
V_2 -> V_70 |= V_60 ;
if ( V_50 & V_52 )
V_2 -> V_70 |= V_57 ;
}
F_5 ( V_71 L_3 ,
V_2 -> V_8 , ( V_50 & V_53 ) ? L_4 : L_5 ) ;
}
void
F_26 ( struct V_5 * V_6 , struct V_72 * V_73 ,
struct V_18 * V_74 )
{
struct V_42 * V_43 = V_6 -> V_49 ;
unsigned long V_44 = 0 ;
if ( V_74 -> V_25 & V_75 )
V_44 = V_43 -> V_47 ;
if ( V_74 -> V_25 & V_45 )
V_44 = V_43 -> V_46 ;
V_73 -> V_20 = V_74 -> V_20 - V_44 ;
V_73 -> V_19 = V_74 -> V_19 - V_44 ;
}
void T_3
F_27 ( struct V_5 * V_6 , struct V_18 * V_74 ,
struct V_72 * V_73 )
{
struct V_42 * V_43 = V_6 -> V_49 ;
unsigned long V_44 = 0 ;
if ( V_74 -> V_25 & V_75 )
V_44 = V_43 -> V_47 ;
if ( V_74 -> V_25 & V_45 )
V_44 = V_43 -> V_46 ;
V_74 -> V_20 = V_73 -> V_20 + V_44 ;
V_74 -> V_19 = V_73 -> V_19 + V_44 ;
}
static T_7 T_3 F_28 ( struct V_5 * V_6 , T_7 * V_76 )
{
struct V_42 * V_77 = V_6 -> V_49 ;
int V_78 = 0 , V_79 = * V_76 ;
if ( V_77 -> V_80 )
V_78 = V_77 -> V_80 ( V_6 , V_76 ) ;
if ( V_33 )
F_5 ( L_6 ,
F_6 ( V_6 ) , V_79 , * V_76 , V_78 ) ;
return V_78 ;
}
static int F_29 ( const struct V_5 * V_6 , T_7 V_78 , T_7 V_76 )
{
struct V_42 * V_77 = V_6 -> V_49 ;
int V_32 = - 1 ;
if ( V_77 -> V_81 )
V_32 = V_77 -> V_81 ( V_6 , V_78 , V_76 ) ;
if ( V_33 )
F_5 ( L_7 ,
F_6 ( V_6 ) , V_78 , V_76 , V_32 ) ;
return V_32 ;
}
static void T_5 F_30 ( struct V_82 * V_83 )
{
struct V_42 * V_77 = NULL ;
int V_84 ;
int V_85 , V_86 ;
for ( V_85 = V_86 = 0 ; V_85 < V_83 -> V_87 ; V_85 ++ ) {
V_77 = F_31 ( sizeof( struct V_42 ) , V_88 ) ;
if ( ! V_77 )
F_32 ( L_8 ) ;
#ifdef F_33
V_77 -> V_89 = V_83 -> V_89 ;
#endif
V_77 -> V_83 = V_83 ;
V_77 -> V_86 = V_86 ;
V_77 -> V_80 = V_83 -> V_80 ;
V_77 -> V_81 = V_83 -> V_81 ;
V_77 -> V_18 [ 0 ] = & V_90 ;
V_77 -> V_18 [ 1 ] = & V_91 ;
V_84 = V_83 -> V_92 ( V_85 , V_77 ) ;
if ( V_84 > 0 ) {
V_77 -> V_2 = V_83 -> V_93 ( V_85 , V_77 ) ;
if ( ! V_77 -> V_2 )
F_32 ( L_9 ) ;
V_86 = V_77 -> V_2 -> V_11 + 1 ;
F_34 ( & V_77 -> V_94 , & V_83 -> V_95 ) ;
} else {
F_35 ( V_77 ) ;
if ( V_84 < 0 )
break;
}
}
}
void T_5 F_36 ( struct V_82 * V_83 )
{
struct V_42 * V_77 ;
F_37 ( & V_83 -> V_95 ) ;
if ( V_83 -> V_96 )
V_83 -> V_96 () ;
F_30 ( V_83 ) ;
if ( V_83 -> V_97 )
V_83 -> V_97 () ;
F_38 ( F_28 , F_29 ) ;
F_2 (sys, &hw->buses, node) {
struct V_1 * V_2 = V_77 -> V_2 ;
if ( ! V_98 ) {
F_39 ( V_2 ) ;
F_40 ( V_2 ) ;
F_41 ( V_2 ) ;
}
F_42 ( V_2 ) ;
}
}
char * T_5 F_43 ( char * V_99 )
{
if ( ! strcmp ( V_99 , L_10 ) ) {
V_33 = 1 ;
return NULL ;
} else if ( ! strcmp ( V_99 , L_11 ) ) {
V_98 = 1 ;
return NULL ;
}
return V_99 ;
}
T_6 F_44 ( void * V_100 , const struct V_18 * V_74 ,
T_6 V_101 , T_6 V_102 )
{
T_6 V_20 = V_74 -> V_20 ;
if ( V_74 -> V_25 & V_75 && V_20 & 0x300 )
V_20 = ( V_20 + 0x3ff ) & ~ 0x3ff ;
V_20 = ( V_20 + V_102 - 1 ) & ~ ( V_102 - 1 ) ;
return V_20 ;
}
int F_45 ( struct V_5 * V_6 , int V_103 )
{
T_2 V_65 , V_104 ;
int V_105 ;
struct V_18 * V_26 ;
F_3 ( V_6 , V_16 , & V_65 ) ;
V_104 = V_65 ;
for ( V_105 = 0 ; V_105 < 6 ; V_105 ++ ) {
if ( ! ( V_103 & ( 1 << V_105 ) ) )
continue;
V_26 = V_6 -> V_18 + V_105 ;
if ( ! V_26 -> V_20 && V_26 -> V_19 ) {
F_5 ( V_106 L_12
L_13 , F_6 ( V_6 ) ) ;
return - V_107 ;
}
if ( V_26 -> V_25 & V_75 )
V_65 |= V_17 ;
if ( V_26 -> V_25 & V_45 )
V_65 |= V_108 ;
}
if ( ( V_6 -> V_22 >> 16 ) == V_109 )
V_65 |= V_17 | V_108 ;
if ( V_65 != V_104 ) {
F_5 ( L_14 ,
F_6 ( V_6 ) , V_104 , V_65 ) ;
F_4 ( V_6 , V_16 , V_65 ) ;
}
return 0 ;
}
int F_46 ( struct V_5 * V_6 , struct V_110 * V_111 ,
enum V_112 V_113 , int V_114 )
{
struct V_42 * V_43 = V_6 -> V_49 ;
unsigned long V_115 ;
if ( V_113 == V_116 ) {
return - V_107 ;
} else {
V_115 = V_111 -> V_117 + ( V_43 -> V_46 >> V_118 ) ;
}
V_111 -> V_119 = F_47 ( V_111 -> V_119 ) ;
if ( F_48 ( V_111 , V_111 -> V_120 , V_115 ,
V_111 -> V_121 - V_111 -> V_120 ,
V_111 -> V_119 ) )
return - V_122 ;
return 0 ;
}

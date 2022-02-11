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
F_21 ( L_2 ,
V_2 -> V_8 , ( V_37 & V_40 ) ? L_3 : L_4 ) ;
}
static T_4 F_22 ( struct V_5 * V_6 , T_4 * V_59 )
{
struct V_60 * V_61 = V_6 -> V_62 ;
int V_63 , V_64 = * V_59 ;
if ( V_61 -> V_65 )
V_63 = V_61 -> V_65 ( V_6 , V_59 ) ;
else
V_63 = F_23 ( V_6 , V_59 ) ;
if ( V_66 )
F_5 ( L_5 ,
F_6 ( V_6 ) , V_64 , * V_59 , V_63 ) ;
return V_63 ;
}
static int F_24 ( const struct V_5 * V_6 , T_4 V_63 , T_4 V_59 )
{
struct V_60 * V_61 = V_6 -> V_62 ;
int V_67 = - 1 ;
if ( V_61 -> V_68 )
V_67 = V_61 -> V_68 ( V_6 , V_63 , V_59 ) ;
if ( V_66 )
F_5 ( L_6 ,
F_6 ( V_6 ) , V_63 , V_59 , V_67 ) ;
return V_67 ;
}
static int F_25 ( int V_69 , struct V_60 * V_61 )
{
int V_70 ;
struct V_71 * V_72 ;
if ( F_26 ( & V_61 -> V_73 ) ) {
F_27 ( & V_61 -> V_73 ,
& V_74 , V_61 -> V_75 ) ;
}
F_28 (window, &sys->resources)
if ( F_29 ( V_72 -> V_76 ) == V_77 )
return 0 ;
V_61 -> V_78 . V_18 = ( V_69 * V_79 ) ? : V_80 ;
V_61 -> V_78 . V_17 = ( V_69 + 1 ) * V_79 - 1 ;
V_61 -> V_78 . V_23 = V_77 ;
V_61 -> V_78 . V_81 = V_61 -> V_82 ;
sprintf ( V_61 -> V_82 , L_7 , V_69 ) ;
V_70 = F_30 ( & V_83 , & V_61 -> V_78 ) ;
if ( V_70 ) {
F_31 ( L_8 , V_70 ) ;
return V_70 ;
}
F_27 ( & V_61 -> V_73 , & V_61 -> V_78 ,
V_61 -> V_84 ) ;
return 0 ;
}
static void F_32 ( struct V_32 * V_85 , struct V_86 * V_87 ,
struct V_88 * V_89 )
{
struct V_60 * V_61 = NULL ;
int V_70 ;
int V_90 , V_69 ;
for ( V_90 = V_69 = 0 ; V_90 < V_87 -> V_91 ; V_90 ++ ) {
V_61 = F_33 ( sizeof( struct V_60 ) , V_92 ) ;
if ( F_34 ( ! V_61 , L_9 ) )
break;
V_61 -> V_69 = V_69 ;
V_61 -> V_65 = V_87 -> V_65 ;
V_61 -> V_68 = V_87 -> V_68 ;
V_61 -> V_93 = V_87 -> V_93 ;
F_35 ( & V_61 -> V_73 ) ;
if ( V_87 -> V_94 )
V_61 -> V_94 = V_87 -> V_94 [ V_90 ] ;
V_70 = V_87 -> V_95 ( V_90 , V_61 ) ;
if ( V_70 > 0 ) {
V_70 = F_25 ( V_90 , V_61 ) ;
if ( V_70 ) {
F_36 ( V_61 ) ;
break;
}
if ( V_87 -> V_96 )
V_61 -> V_2 = V_87 -> V_96 ( V_90 , V_61 ) ;
else
V_61 -> V_2 = F_37 ( V_85 ,
V_61 -> V_69 , V_87 -> V_97 , V_61 ,
& V_61 -> V_73 , V_87 -> V_98 ) ;
if ( F_34 ( ! V_61 -> V_2 , L_10 ) ) {
F_36 ( V_61 ) ;
break;
}
V_69 = V_61 -> V_2 -> V_99 . V_17 + 1 ;
F_38 ( & V_61 -> V_100 , V_89 ) ;
} else {
F_36 ( V_61 ) ;
if ( V_70 < 0 )
break;
}
}
}
void F_39 ( struct V_32 * V_85 , struct V_86 * V_87 )
{
struct V_60 * V_61 ;
F_40 ( V_89 ) ;
F_41 ( V_101 ) ;
if ( V_87 -> V_102 )
V_87 -> V_102 () ;
F_32 ( V_85 , V_87 , & V_89 ) ;
if ( V_87 -> V_103 )
V_87 -> V_103 () ;
F_42 ( F_22 , F_24 ) ;
F_2 (sys, &head, node) {
struct V_1 * V_2 = V_61 -> V_2 ;
if ( ! F_43 ( V_104 ) ) {
struct V_1 * V_105 ;
F_44 ( V_2 ) ;
F_45 ( V_2 ) ;
F_2 (child, &bus->children, node)
F_46 ( V_105 ) ;
}
F_47 ( V_2 ) ;
}
}
void F_48 ( struct V_5 * V_6 )
{
}
char * T_5 F_49 ( char * V_106 )
{
if ( ! strcmp ( V_106 , L_11 ) ) {
V_66 = 1 ;
return NULL ;
} else if ( ! strcmp ( V_106 , L_12 ) ) {
F_41 ( V_104 ) ;
return NULL ;
}
return V_106 ;
}
T_6 F_50 ( void * V_107 , const struct V_16 * V_76 ,
T_6 V_108 , T_6 V_109 )
{
struct V_5 * V_6 = V_107 ;
struct V_60 * V_61 = V_6 -> V_62 ;
T_6 V_18 = V_76 -> V_18 ;
if ( V_76 -> V_23 & V_77 && V_18 & 0x300 )
V_18 = ( V_18 + 0x3ff ) & ~ 0x3ff ;
V_18 = ( V_18 + V_109 - 1 ) & ~ ( V_109 - 1 ) ;
if ( V_61 -> V_93 )
return V_61 -> V_93 ( V_6 , V_76 , V_18 , V_108 , V_109 ) ;
return V_18 ;
}
int F_51 ( struct V_5 * V_6 , int V_110 )
{
if ( F_43 ( V_104 ) )
return 0 ;
return F_52 ( V_6 , V_110 ) ;
}
int F_53 ( struct V_5 * V_6 , struct V_111 * V_112 ,
enum V_113 V_114 , int V_115 )
{
if ( V_114 == V_116 )
return - V_117 ;
V_112 -> V_118 = F_54 ( V_112 -> V_118 ) ;
if ( F_55 ( V_112 , V_112 -> V_119 , V_112 -> V_120 ,
V_112 -> V_121 - V_112 -> V_119 ,
V_112 -> V_118 ) )
return - V_122 ;
return 0 ;
}
void T_5 F_56 ( unsigned long V_123 )
{
struct V_124 V_125 = {
. V_126 = V_127 ,
. type = V_128 ,
. V_129 = V_79 ,
} ;
V_125 . V_123 = V_123 ;
F_57 ( & V_125 , 1 ) ;
}

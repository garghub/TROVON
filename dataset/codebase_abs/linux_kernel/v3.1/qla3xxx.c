static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
T_1 V_8 ;
unsigned int V_9 = 3 ;
do {
F_2 ( ( V_3 | V_4 ) ,
& V_6 -> V_10 . V_11 ) ;
V_8 = F_3 ( & V_6 -> V_10 . V_11 ) ;
if ( ( V_8 & ( V_3 >> 16 ) ) == V_4 )
return 0 ;
F_4 ( 1 ) ;
} while ( -- V_9 );
return - 1 ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
F_2 ( V_3 , & V_6 -> V_10 . V_11 ) ;
F_3 ( & V_6 -> V_10 . V_11 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
T_1 V_8 ;
F_2 ( ( V_3 | V_4 ) , & V_6 -> V_10 . V_11 ) ;
V_8 = F_3 ( & V_6 -> V_10 . V_11 ) ;
return ( ( V_8 & ( V_3 >> 16 ) ) == V_4 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_12 = 0 ;
while ( V_12 < 10 ) {
if ( V_12 )
F_4 ( 1 ) ;
if ( F_6 ( V_2 ,
V_13 ,
( V_14 | ( V_2 -> V_15 )
* 2 ) << 1 ) ) {
F_8 ( V_16 , V_2 -> V_17 ,
L_1 ) ;
return 1 ;
}
}
F_9 ( V_2 -> V_17 , L_2 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 , T_1 V_18 )
{
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
F_2 ( ( ( V_19 << 16 ) | V_18 ) ,
& V_6 -> V_10 . V_20 ) ;
F_3 ( & V_6 -> V_10 . V_20 ) ;
V_2 -> V_21 = V_18 ;
}
static T_1 F_11 ( struct V_1 * V_2 , T_1 T_2 * V_22 )
{
T_1 V_8 ;
unsigned long V_23 ;
F_12 ( & V_2 -> V_24 , V_23 ) ;
V_8 = F_3 ( V_22 ) ;
F_13 ( & V_2 -> V_24 , V_23 ) ;
return V_8 ;
}
static T_1 F_14 ( struct V_1 * V_2 , T_1 T_2 * V_22 )
{
return F_3 ( V_22 ) ;
}
static T_1 F_15 ( struct V_1 * V_2 , T_1 T_2 * V_22 )
{
T_1 V_8 ;
unsigned long V_23 ;
F_12 ( & V_2 -> V_24 , V_23 ) ;
if ( V_2 -> V_21 != 0 )
F_10 ( V_2 , 0 ) ;
V_8 = F_3 ( V_22 ) ;
F_13 ( & V_2 -> V_24 , V_23 ) ;
return V_8 ;
}
static T_1 F_16 ( struct V_1 * V_2 , T_1 T_2 * V_22 )
{
if ( V_2 -> V_21 != 0 )
F_10 ( V_2 , 0 ) ;
return F_3 ( V_22 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
T_1 T_2 * V_22 , T_1 V_8 )
{
unsigned long V_23 ;
F_12 ( & V_2 -> V_24 , V_23 ) ;
F_2 ( V_8 , V_22 ) ;
F_3 ( V_22 ) ;
F_13 ( & V_2 -> V_24 , V_23 ) ;
}
static void F_18 ( struct V_1 * V_2 ,
T_1 T_2 * V_22 , T_1 V_8 )
{
F_2 ( V_8 , V_22 ) ;
F_3 ( V_22 ) ;
}
static void F_19 ( struct V_1 * V_2 ,
T_1 T_2 * V_22 , T_1 V_8 )
{
F_2 ( V_8 , V_22 ) ;
F_3 ( V_22 ) ;
F_20 ( 1 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
T_1 T_2 * V_22 , T_1 V_8 )
{
if ( V_2 -> V_21 != 0 )
F_10 ( V_2 , 0 ) ;
F_2 ( V_8 , V_22 ) ;
F_3 ( V_22 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
T_1 T_2 * V_22 , T_1 V_8 )
{
if ( V_2 -> V_21 != 1 )
F_10 ( V_2 , 1 ) ;
F_2 ( V_8 , V_22 ) ;
F_3 ( V_22 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
T_1 T_2 * V_22 , T_1 V_8 )
{
if ( V_2 -> V_21 != 2 )
F_10 ( V_2 , 2 ) ;
F_2 ( V_8 , V_22 ) ;
F_3 ( V_22 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
F_17 ( V_2 , & V_6 -> V_10 . V_25 ,
( V_26 << 16 ) ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
F_17 ( V_2 , & V_6 -> V_10 . V_25 ,
( ( 0xff << 16 ) | V_26 ) ) ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
T_3 V_29 ;
int V_30 ;
V_28 -> V_31 = NULL ;
if ( V_2 -> V_32 == NULL ) {
V_2 -> V_33 = V_2 -> V_32 = V_28 ;
} else {
V_2 -> V_32 -> V_31 = V_28 ;
V_2 -> V_32 = V_28 ;
}
if ( ! V_28 -> V_34 ) {
V_28 -> V_34 = F_27 ( V_2 -> V_17 ,
V_2 -> V_35 ) ;
if ( F_28 ( ! V_28 -> V_34 ) ) {
F_9 ( V_2 -> V_17 , L_3 ) ;
V_2 -> V_36 ++ ;
} else {
F_29 ( V_28 -> V_34 , V_37 ) ;
V_29 = F_30 ( V_2 -> V_38 ,
V_28 -> V_34 -> V_39 ,
V_2 -> V_35 -
V_37 ,
V_40 ) ;
V_30 = F_31 ( V_2 -> V_38 , V_29 ) ;
if ( V_30 ) {
F_9 ( V_2 -> V_17 ,
L_4 ,
V_30 ) ;
F_32 ( V_28 -> V_34 ) ;
V_28 -> V_34 = NULL ;
V_2 -> V_36 ++ ;
return;
}
V_28 -> V_41 =
F_33 ( F_34 ( V_29 ) ) ;
V_28 -> V_42 =
F_33 ( F_35 ( V_29 ) ) ;
F_36 ( V_28 , V_43 , V_29 ) ;
F_37 ( V_28 , V_44 ,
V_2 -> V_35 -
V_37 ) ;
}
}
V_2 -> V_45 ++ ;
}
static struct V_27 * F_38 ( struct V_1
* V_2 )
{
struct V_27 * V_28 = V_2 -> V_33 ;
if ( V_28 != NULL ) {
V_2 -> V_33 = V_28 -> V_31 ;
if ( V_2 -> V_33 == NULL )
V_2 -> V_32 = NULL ;
V_2 -> V_45 -- ;
}
return V_28 ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
T_2 T_1 * V_46 = & V_6 -> V_10 . V_47 ;
V_2 -> V_48 = V_49 ;
F_19 ( V_2 , V_46 , V_50 | V_2 -> V_48 ) ;
F_19 ( V_2 , V_46 ,
( ( V_50 << 16 ) | V_2 -> V_48 ) ) ;
}
static void F_40 ( struct V_1 * V_2 , T_1 V_51 , T_1 V_52 )
{
int V_12 ;
T_1 V_53 ;
T_1 V_54 ;
T_1 V_55 ;
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
T_2 T_1 * V_46 = & V_6 -> V_10 . V_47 ;
F_19 ( V_2 , V_46 ,
( V_50 | V_2 -> V_48 |
V_56 ) ) ;
F_19 ( V_2 , V_46 ,
( V_50 | V_2 -> V_48 |
V_56 | V_57 ) ) ;
F_19 ( V_2 , V_46 ,
( V_50 | V_2 -> V_48 |
V_56 | V_58 ) ) ;
V_53 = 1 << ( V_59 - 1 ) ;
V_55 = 0xffff ;
for ( V_12 = 0 ; V_12 < V_59 ; V_12 ++ ) {
V_54 = ( V_51 & V_53 )
? V_56
: V_60 ;
if ( V_55 != V_54 ) {
F_19 ( V_2 , V_46 ,
( V_50 |
V_2 -> V_48 | V_54 ) ) ;
V_55 = V_54 ;
}
F_19 ( V_2 , V_46 ,
( V_50 | V_2 -> V_48 |
V_54 | V_57 ) ) ;
F_19 ( V_2 , V_46 ,
( V_50 | V_2 -> V_48 |
V_54 | V_58 ) ) ;
V_51 = V_51 << 1 ;
}
V_53 = 1 << ( V_61 - 1 ) ;
V_55 = 0xffff ;
for ( V_12 = 0 ; V_12 < V_61 ; V_12 ++ ) {
V_54 = ( V_52 & V_53 ) ? V_56
: V_60 ;
if ( V_55 != V_54 ) {
F_19 ( V_2 , V_46 ,
( V_50 |
V_2 -> V_48 | V_54 ) ) ;
V_55 = V_54 ;
}
F_19 ( V_2 , V_46 ,
( V_50 | V_2 -> V_48 |
V_54 | V_57 ) ) ;
F_19 ( V_2 , V_46 ,
( V_50 | V_2 -> V_48 |
V_54 | V_58 ) ) ;
V_52 = V_52 << 1 ;
}
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
T_2 T_1 * V_46 = & V_6 -> V_10 . V_47 ;
V_2 -> V_48 = V_62 ;
F_19 ( V_2 , V_46 , V_50 | V_2 -> V_48 ) ;
}
static void F_42 ( struct V_1 * V_2 , unsigned short * V_8 )
{
int V_12 ;
T_1 V_39 = 0 ;
T_1 V_54 ;
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
T_2 T_1 * V_46 = & V_6 -> V_10 . V_47 ;
for ( V_12 = 0 ; V_12 < V_63 ; V_12 ++ ) {
F_19 ( V_2 , V_46 ,
V_50 | V_2 -> V_48 |
V_57 ) ;
F_19 ( V_2 , V_46 ,
V_50 | V_2 -> V_48 |
V_58 ) ;
V_54 = ( F_14 ( V_2 , V_46 ) &
V_64 ) ? 1 : 0 ;
V_39 = ( V_39 << 1 ) | V_54 ;
}
* V_8 = ( V_65 ) V_39 ;
}
static void F_43 ( struct V_1 * V_2 ,
T_1 V_52 , unsigned short * V_8 )
{
F_39 ( V_2 ) ;
F_40 ( V_2 , ( int ) V_66 , V_52 ) ;
F_42 ( V_2 , V_8 ) ;
F_41 ( V_2 ) ;
}
static void F_44 ( struct V_67 * V_17 , V_65 * V_68 )
{
T_4 * V_69 = ( T_4 * ) V_17 -> V_70 ;
V_69 [ 0 ] = F_45 ( V_68 [ 0 ] ) ;
V_69 [ 1 ] = F_45 ( V_68 [ 1 ] ) ;
V_69 [ 2 ] = F_45 ( V_68 [ 2 ] ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
V_65 * V_71 ;
V_65 V_72 = 0 ;
T_1 V_73 ;
unsigned long V_23 ;
F_12 ( & V_2 -> V_24 , V_23 ) ;
V_71 = ( V_65 * ) & V_2 -> V_74 ;
V_2 -> V_48 = 0 ;
if ( F_1 ( V_2 , V_75 ,
( V_14 | ( V_2 -> V_15 ) *
2 ) << 10 ) ) {
F_47 ( L_5 , V_76 ) ;
F_13 ( & V_2 -> V_24 , V_23 ) ;
return - 1 ;
}
for ( V_73 = 0 ; V_73 < V_77 ; V_73 ++ ) {
F_43 ( V_2 , V_73 , V_71 ) ;
V_72 += * V_71 ;
V_71 ++ ;
}
F_5 ( V_2 , V_75 ) ;
if ( V_72 != 0 ) {
F_9 ( V_2 -> V_17 , L_6 ,
V_72 ) ;
F_13 ( & V_2 -> V_24 , V_23 ) ;
return - 1 ;
}
F_13 ( & V_2 -> V_24 , V_23 ) ;
return V_72 ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
T_1 V_78 ;
int V_79 = 1000 ;
while ( V_79 ) {
V_78 = F_16 ( V_2 , & V_6 -> V_80 ) ;
if ( ! ( V_78 & V_81 ) )
return 0 ;
F_20 ( 10 ) ;
V_79 -- ;
}
return - 1 ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
T_1 V_82 ;
if ( V_2 -> V_83 > 1 ) {
V_82 = V_84 | V_85 ;
} else {
V_82 = V_85 ;
}
F_21 ( V_2 , & V_6 -> V_86 ,
V_87 [ 0 ] | V_88 ) ;
F_21 ( V_2 , & V_6 -> V_89 ,
( V_82 ) |
( ( V_85 | V_84 ) << 16 ) ) ;
}
static T_5 F_50 ( struct V_1 * V_2 )
{
T_5 V_90 ;
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
if ( F_16 ( V_2 , & V_6 -> V_89 ) &
( V_84 | V_85 ) ) {
V_90 = 1 ;
} else {
V_90 = 0 ;
}
F_21 ( V_2 , & V_6 -> V_86 ,
V_87 [ 0 ] | V_88 ) ;
F_21 ( V_2 , & V_6 -> V_89 ,
( ( V_85 | V_84 |
V_91 ) << 16 ) ) ;
return V_90 ;
}
static int F_51 ( struct V_1 * V_2 ,
V_65 V_92 , V_65 V_8 , T_1 V_93 )
{
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
T_5 V_94 ;
V_94 = F_50 ( V_2 ) ;
if ( F_48 ( V_2 ) ) {
F_52 ( V_2 , V_95 , V_2 -> V_17 , V_96 ) ;
return - 1 ;
}
F_21 ( V_2 , & V_6 -> V_86 ,
V_93 | V_92 ) ;
F_21 ( V_2 , & V_6 -> V_97 , V_8 ) ;
if ( F_48 ( V_2 ) ) {
F_52 ( V_2 , V_95 , V_2 -> V_17 , V_96 ) ;
return - 1 ;
}
if ( V_94 )
F_49 ( V_2 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 , V_65 V_92 ,
V_65 * V_8 , T_1 V_93 )
{
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
T_5 V_94 ;
T_1 V_78 ;
V_94 = F_50 ( V_2 ) ;
if ( F_48 ( V_2 ) ) {
F_52 ( V_2 , V_95 , V_2 -> V_17 , V_96 ) ;
return - 1 ;
}
F_21 ( V_2 , & V_6 -> V_86 ,
V_93 | V_92 ) ;
F_21 ( V_2 , & V_6 -> V_89 ,
( V_91 << 16 ) ) ;
F_21 ( V_2 , & V_6 -> V_89 ,
( V_91 << 16 ) | V_91 ) ;
if ( F_48 ( V_2 ) ) {
F_52 ( V_2 , V_95 , V_2 -> V_17 , V_96 ) ;
return - 1 ;
}
V_78 = F_16 ( V_2 , & V_6 -> V_97 ) ;
* V_8 = ( V_65 ) V_78 ;
if ( V_94 )
F_49 ( V_2 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 , V_65 V_92 , V_65 V_8 )
{
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
F_50 ( V_2 ) ;
if ( F_48 ( V_2 ) ) {
F_52 ( V_2 , V_95 , V_2 -> V_17 , V_96 ) ;
return - 1 ;
}
F_21 ( V_2 , & V_6 -> V_86 ,
V_2 -> V_87 | V_92 ) ;
F_21 ( V_2 , & V_6 -> V_97 , V_8 ) ;
if ( F_48 ( V_2 ) ) {
F_52 ( V_2 , V_95 , V_2 -> V_17 , V_96 ) ;
return - 1 ;
}
F_49 ( V_2 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 , V_65 V_92 , V_65 * V_8 )
{
T_1 V_78 ;
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
F_50 ( V_2 ) ;
if ( F_48 ( V_2 ) ) {
F_52 ( V_2 , V_95 , V_2 -> V_17 , V_96 ) ;
return - 1 ;
}
F_21 ( V_2 , & V_6 -> V_86 ,
V_2 -> V_87 | V_92 ) ;
F_21 ( V_2 , & V_6 -> V_89 ,
( V_91 << 16 ) ) ;
F_21 ( V_2 , & V_6 -> V_89 ,
( V_91 << 16 ) | V_91 ) ;
if ( F_48 ( V_2 ) ) {
F_52 ( V_2 , V_95 , V_2 -> V_17 , V_96 ) ;
return - 1 ;
}
V_78 = F_16 ( V_2 , & V_6 -> V_97 ) ;
* V_8 = ( V_65 ) V_78 ;
F_49 ( V_2 ) ;
return 0 ;
}
static void F_56 ( struct V_1 * V_2 )
{
F_54 ( V_2 , V_98 , V_99 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
V_65 V_22 ;
F_55 ( V_2 , V_100 , & V_22 ) ;
V_22 |= V_101 ;
F_54 ( V_2 , V_100 , V_22 ) ;
F_54 ( V_2 , V_102 ,
V_103 | V_104 ) ;
F_54 ( V_2 , V_98 ,
V_105 | V_106 |
V_107 | V_108 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
F_51 ( V_2 , V_98 , V_99 ,
V_87 [ V_2 -> V_15 ] ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
V_65 V_22 ;
F_53 ( V_2 , V_100 , & V_22 ,
V_87 [ V_2 -> V_15 ] ) ;
V_22 |= V_101 ;
F_51 ( V_2 , V_100 , V_22 ,
V_87 [ V_2 -> V_15 ] ) ;
F_51 ( V_2 , V_102 ,
V_103 | V_104 ,
V_87 [ V_2 -> V_15 ] ) ;
F_51 ( V_2 , V_98 ,
V_105 | V_106 |
V_107 | V_108 ,
V_87 [ V_2 -> V_15 ] ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
F_56 ( V_2 ) ;
F_57 ( V_2 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
F_58 ( V_2 ) ;
F_59 ( V_2 ) ;
}
static int F_62 ( struct V_1 * V_2 )
{
V_65 V_22 ;
if ( F_55 ( V_2 , V_109 , & V_22 ) < 0 )
return 0 ;
return ( V_22 & V_110 ) == V_103 ;
}
static void F_63 ( struct V_1 * V_2 , T_1 V_111 )
{
F_64 ( V_2 -> V_17 , L_7 ) ;
F_51 ( V_2 , 0x00 , 0x1940 , V_111 ) ;
F_51 ( V_2 , 0x12 , 0x840e , V_111 ) ;
F_51 ( V_2 , 0x10 , 0x8805 , V_111 ) ;
F_51 ( V_2 , 0x11 , 0xf03e , V_111 ) ;
F_51 ( V_2 , 0x10 , 0x8806 , V_111 ) ;
F_51 ( V_2 , 0x11 , 0x003e , V_111 ) ;
F_51 ( V_2 , 0x10 , 0x8807 , V_111 ) ;
F_51 ( V_2 , 0x11 , 0x1f00 , V_111 ) ;
F_51 ( V_2 , 0x10 , 0x2806 , V_111 ) ;
F_51 ( V_2 , 0x11 ,
0x0020 | ( V_87 [ V_2 -> V_15 ] >> 8 ) , V_111 ) ;
F_54 ( V_2 , 0x12 , 0x840a ) ;
F_54 ( V_2 , 0x00 , 0x1140 ) ;
F_54 ( V_2 , 0x1c , 0xfaf0 ) ;
}
static enum V_112 F_65 ( struct V_1 * V_2 ,
V_65 V_113 , V_65 V_114 )
{
enum V_112 V_115 = V_116 ;
T_1 V_117 ;
V_65 V_118 ;
int V_12 ;
if ( V_113 == 0xffff )
return V_115 ;
if ( V_114 == 0xffff )
return V_115 ;
V_117 = ( V_113 << 6 ) | ( ( V_114 & V_119 ) >> 10 ) ;
V_118 = ( V_114 & V_120 ) >> 4 ;
for ( V_12 = 0 ; V_12 < V_121 ; V_12 ++ ) {
if ( ( V_117 == V_122 [ V_12 ] . V_123 ) &&
( V_118 == V_122 [ V_12 ] . V_124 ) ) {
F_64 ( V_2 -> V_17 , L_8 ,
V_122 [ V_12 ] . V_125 ) ;
V_115 = V_122 [ V_12 ] . V_126 ;
break;
}
}
return V_115 ;
}
static int F_66 ( struct V_1 * V_2 )
{
V_65 V_22 ;
switch ( V_2 -> V_127 ) {
case V_128 : {
if ( F_55 ( V_2 , 0x1A , & V_22 ) < 0 )
return 0 ;
V_22 = ( V_22 >> 8 ) & 3 ;
break;
}
default:
if ( F_55 ( V_2 , V_129 , & V_22 ) < 0 )
return 0 ;
V_22 = ( ( ( V_22 & 0x18 ) >> 3 ) & 3 ) ;
}
switch ( V_22 ) {
case 2 :
return V_130 ;
case 1 :
return V_131 ;
case 0 :
return V_132 ;
default:
return - 1 ;
}
}
static int F_67 ( struct V_1 * V_2 )
{
V_65 V_22 ;
switch ( V_2 -> V_127 ) {
case V_128 : {
if ( F_55 ( V_2 , 0x1A , & V_22 ) )
return 0 ;
return ( ( V_22 & 0x0080 ) && ( V_22 & 0x1000 ) ) != 0 ;
}
case V_133 :
default: {
if ( F_55 ( V_2 , V_129 , & V_22 ) < 0 )
return 0 ;
return ( V_22 & V_134 ) != 0 ;
}
}
}
static int F_68 ( struct V_1 * V_2 )
{
V_65 V_22 ;
if ( F_55 ( V_2 , V_135 , & V_22 ) < 0 )
return 0 ;
return ( V_22 & V_136 ) != 0 ;
}
static int F_69 ( struct V_1 * V_2 )
{
V_65 V_137 ;
V_65 V_138 ;
bool V_139 = false ;
T_1 V_111 = 0 ;
int V_30 ;
V_30 = F_55 ( V_2 , V_140 , & V_137 ) ;
if ( V_30 != 0 ) {
F_9 ( V_2 -> V_17 , L_9 ) ;
return V_30 ;
}
V_30 = F_55 ( V_2 , V_141 , & V_138 ) ;
if ( V_30 != 0 ) {
F_9 ( V_2 -> V_17 , L_10 ) ;
return V_30 ;
}
if ( ( V_137 == 0xffff ) || ( V_138 == 0xffff ) ) {
if ( V_2 -> V_15 == 0 )
V_111 = V_142 ;
else
V_111 = V_143 ;
V_30 = F_53 ( V_2 , V_140 , & V_137 , V_111 ) ;
if ( V_30 != 0 ) {
F_9 ( V_2 -> V_17 ,
L_11 ) ;
return V_30 ;
}
V_30 = F_53 ( V_2 , V_141 , & V_138 , V_111 ) ;
if ( V_30 != 0 ) {
F_9 ( V_2 -> V_17 , L_12 ) ;
return V_30 ;
}
V_139 = true ;
}
V_2 -> V_127 = F_65 ( V_2 , V_137 , V_138 ) ;
if ( ( V_2 -> V_127 == V_128 ) && V_139 ) {
F_63 ( V_2 , V_111 ) ;
} else if ( V_2 -> V_127 == V_116 ) {
F_9 ( V_2 -> V_17 , L_13 ) ;
return - V_144 ;
}
return 0 ;
}
static void F_70 ( struct V_1 * V_2 , T_1 V_145 )
{
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
T_1 V_8 ;
if ( V_145 )
V_8 = ( V_146 | ( V_146 << 16 ) ) ;
else
V_8 = ( V_146 << 16 ) ;
if ( V_2 -> V_15 )
F_21 ( V_2 , & V_6 -> V_147 , V_8 ) ;
else
F_21 ( V_2 , & V_6 -> V_148 , V_8 ) ;
}
static void F_71 ( struct V_1 * V_2 , T_1 V_145 )
{
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
T_1 V_8 ;
if ( V_145 )
V_8 = ( V_149 | ( V_149 << 16 ) ) ;
else
V_8 = ( V_149 << 16 ) ;
if ( V_2 -> V_15 )
F_21 ( V_2 , & V_6 -> V_147 , V_8 ) ;
else
F_21 ( V_2 , & V_6 -> V_148 , V_8 ) ;
}
static void F_72 ( struct V_1 * V_2 , T_1 V_145 )
{
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
T_1 V_8 ;
if ( V_145 )
V_8 = ( V_150 | ( V_150 << 16 ) ) ;
else
V_8 = ( V_150 << 16 ) ;
if ( V_2 -> V_15 )
F_21 ( V_2 , & V_6 -> V_147 , V_8 ) ;
else
F_21 ( V_2 , & V_6 -> V_148 , V_8 ) ;
}
static void F_73 ( struct V_1 * V_2 , T_1 V_145 )
{
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
T_1 V_8 ;
if ( V_145 )
V_8 = ( V_151 | ( V_151 << 16 ) ) ;
else
V_8 = ( V_151 << 16 ) ;
if ( V_2 -> V_15 )
F_21 ( V_2 , & V_6 -> V_147 , V_8 ) ;
else
F_21 ( V_2 , & V_6 -> V_148 , V_8 ) ;
}
static void F_74 ( struct V_1 * V_2 , T_1 V_145 )
{
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
T_1 V_8 ;
if ( V_145 )
V_8 =
( ( V_152 | V_153 ) |
( ( V_152 | V_153 ) << 16 ) ) ;
else
V_8 = ( ( V_152 | V_153 ) << 16 ) ;
if ( V_2 -> V_15 )
F_21 ( V_2 , & V_6 -> V_147 , V_8 ) ;
else
F_21 ( V_2 , & V_6 -> V_148 , V_8 ) ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
T_1 V_154 = 0 ;
T_1 V_78 ;
switch ( V_2 -> V_15 ) {
case 0 :
V_154 = V_155 ;
break;
case 1 :
V_154 = V_156 ;
break;
}
V_78 = F_16 ( V_2 , & V_6 -> V_157 ) ;
return ( V_78 & V_154 ) != 0 ;
}
static int F_76 ( struct V_1 * V_2 )
{
V_65 V_22 ;
F_55 ( V_2 , 0x00 , & V_22 ) ;
return ( V_22 & 0x1000 ) != 0 ;
}
static int F_77 ( struct V_1 * V_2 )
{
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
T_1 V_154 = 0 ;
T_1 V_78 ;
switch ( V_2 -> V_15 ) {
case 0 :
V_154 = V_158 ;
break;
case 1 :
V_154 = V_159 ;
break;
}
V_78 = F_16 ( V_2 , & V_6 -> V_157 ) ;
if ( V_78 & V_154 ) {
F_78 ( V_2 , V_95 , V_2 -> V_17 , L_14 ) ;
return 1 ;
}
F_78 ( V_2 , V_95 , V_2 -> V_17 , L_15 ) ;
return 0 ;
}
static int F_79 ( struct V_1 * V_2 )
{
if ( F_75 ( V_2 ) )
return F_62 ( V_2 ) ;
else
return F_68 ( V_2 ) ;
}
static int F_80 ( struct V_1 * V_2 )
{
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
T_1 V_154 = 0 ;
T_1 V_78 ;
switch ( V_2 -> V_15 ) {
case 0 :
V_154 = V_160 ;
break;
case 1 :
V_154 = V_161 ;
break;
}
V_78 = F_16 ( V_2 , & V_6 -> V_157 ) ;
return ( V_78 & V_154 ) != 0 ;
}
static T_1 F_81 ( struct V_1 * V_2 )
{
if ( F_75 ( V_2 ) )
return V_130 ;
else
return F_66 ( V_2 ) ;
}
static int F_82 ( struct V_1 * V_2 )
{
if ( F_75 ( V_2 ) )
return 1 ;
else
return F_67 ( V_2 ) ;
}
static int F_83 ( struct V_1 * V_2 )
{
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
T_1 V_154 = 0 ;
T_1 V_78 ;
switch ( V_2 -> V_15 ) {
case 0 :
V_154 = V_162 ;
break;
case 1 :
V_154 = V_163 ;
break;
}
V_78 =
F_14 ( V_2 , & V_6 -> V_10 . V_20 ) ;
return ( V_78 & V_154 ) != 0 ;
}
static int F_84 ( struct V_1 * V_2 )
{
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
switch ( V_2 -> V_15 ) {
case 0 :
F_18 ( V_2 ,
& V_6 -> V_10 . V_20 ,
( V_162 ) |
( V_162 << 16 ) ) ;
break;
case 1 :
F_18 ( V_2 ,
& V_6 -> V_10 . V_20 ,
( V_163 ) |
( V_163 << 16 ) ) ;
break;
default:
return 1 ;
}
return 0 ;
}
static int F_85 ( struct V_1 * V_2 )
{
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
T_1 V_154 = 0 ;
T_1 V_78 ;
switch ( V_2 -> V_15 ) {
case 0 :
V_154 = V_164 ;
break;
case 1 :
V_154 = V_165 ;
break;
default:
break;
}
V_78 = F_16 ( V_2 , & V_6 -> V_157 ) ;
if ( V_78 & V_154 ) {
F_86 ( V_2 , V_95 , V_16 , V_2 -> V_17 ,
L_16 ) ;
return 0 ;
}
F_86 ( V_2 , V_95 , V_16 , V_2 -> V_17 , L_17 ) ;
return 1 ;
}
static void F_87 ( struct V_1 * V_2 )
{
F_51 ( V_2 , V_166 , V_167 ,
V_87 [ V_2 -> V_15 ] ) ;
}
static void F_88 ( struct V_1 * V_2 )
{
V_65 V_22 ;
V_65 V_168 ;
if ( V_2 -> V_127 == V_128 )
F_54 ( V_2 , 0x13 , 0x0000 ) ;
if ( V_2 -> V_15 == 0 )
V_168 =
V_2 -> V_74 . V_169 . V_168 ;
else
V_168 =
V_2 -> V_74 . V_170 . V_168 ;
if ( V_168 == 0 )
V_168 = V_171 ;
F_53 ( V_2 , V_172 , & V_22 ,
V_87 [ V_2 -> V_15 ] ) ;
V_22 &= ~ V_173 ;
if ( V_168 & V_174 ) {
if ( V_168 & V_175 )
V_22 |= V_176 ;
else
V_22 |= V_177 ;
}
F_51 ( V_2 , V_172 , V_22 ,
V_87 [ V_2 -> V_15 ] ) ;
F_53 ( V_2 , V_178 , & V_22 ,
V_87 [ V_2 -> V_15 ] ) ;
V_22 &= ~ V_179 ;
if ( V_168 & V_180 )
V_22 |= V_181 | V_182 ;
if ( V_168 & V_175 ) {
if ( V_168 & V_183 )
V_22 |= V_184 ;
if ( V_168 & V_185 )
V_22 |= V_186 ;
}
if ( V_168 & V_187 ) {
if ( V_168 & V_183 )
V_22 |= V_188 ;
if ( V_168 & V_185 )
V_22 |= V_189 ;
}
if ( V_168 & V_174 )
V_22 |= 1 ;
F_51 ( V_2 , V_178 , V_22 ,
V_87 [ V_2 -> V_15 ] ) ;
F_53 ( V_2 , V_166 , & V_22 , V_87 [ V_2 -> V_15 ] ) ;
F_51 ( V_2 , V_166 ,
V_22 | V_190 | V_191 ,
V_87 [ V_2 -> V_15 ] ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
F_87 ( V_2 ) ;
F_69 ( V_2 ) ;
F_88 ( V_2 ) ;
}
static T_1 F_90 ( struct V_1 * V_2 )
{
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
T_1 V_154 = 0 ;
T_1 V_78 , V_192 ;
switch ( V_2 -> V_15 ) {
case 0 :
V_154 = V_193 ;
break;
case 1 :
V_154 = V_194 ;
break;
}
V_78 = F_16 ( V_2 , & V_6 -> V_157 ) ;
if ( V_78 & V_154 )
V_192 = V_195 ;
else
V_192 = V_196 ;
return V_192 ;
}
static int F_91 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 , V_197 ,
( V_14 | ( V_2 -> V_15 ) *
2 ) << 7 ) ) {
F_9 ( V_2 -> V_17 , L_18 ) ;
return - 1 ;
}
if ( F_75 ( V_2 ) ) {
F_60 ( V_2 ) ;
} else {
F_89 ( V_2 ) ;
}
F_5 ( V_2 , V_197 ) ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 , V_197 ,
( V_14 | ( V_2 -> V_15 ) *
2 ) << 7 ) )
return - 1 ;
if ( ! F_80 ( V_2 ) ) {
if ( F_93 ( V_198 , & V_2 -> V_199 ) ) {
F_86 ( V_2 , V_95 , V_16 , V_2 -> V_17 ,
L_19 ) ;
F_71 ( V_2 , 1 ) ;
F_72 ( V_2 ,
( F_81
( V_2 ) ==
V_130 ) ) ;
F_73 ( V_2 ,
F_82
( V_2 ) ) ;
F_74 ( V_2 ,
F_79
( V_2 ) ) ;
F_71 ( V_2 , 0 ) ;
F_86 ( V_2 , V_95 , V_16 , V_2 -> V_17 ,
L_20 ) ;
F_70 ( V_2 , 1 ) ;
}
V_2 -> V_200 = V_195 ;
F_94 ( V_2 -> V_17 ) ;
F_95 ( V_2 -> V_17 ) ;
F_78 ( V_2 , V_95 , V_2 -> V_17 ,
L_21 ,
F_81 ( V_2 ) ,
F_82 ( V_2 ) ? L_22 : L_23 ) ;
} else {
if ( F_93 ( V_198 , & V_2 -> V_199 ) ) {
F_86 ( V_2 , V_95 , V_16 , V_2 -> V_17 ,
L_24 ) ;
F_5 ( V_2 , V_197 ) ;
if ( F_91 ( V_2 ) )
return - 1 ;
return 0 ;
}
}
F_5 ( V_2 , V_197 ) ;
return 0 ;
}
static void F_96 ( struct V_201 * V_202 )
{
struct V_1 * V_2 =
F_97 ( V_202 , struct V_1 , V_203 . V_202 ) ;
T_1 V_204 ;
unsigned long V_23 ;
F_12 ( & V_2 -> V_24 , V_23 ) ;
V_204 = F_90 ( V_2 ) ;
if ( F_93 ( V_205 , & V_2 -> V_199 ) ) {
F_78 ( V_2 , V_95 , V_2 -> V_17 ,
L_25 ) ;
F_13 ( & V_2 -> V_24 , V_23 ) ;
F_98 ( & V_2 -> V_206 , V_207 + V_208 * 1 ) ;
return;
}
switch ( V_2 -> V_200 ) {
default:
if ( F_93 ( V_198 , & V_2 -> V_199 ) )
F_91 ( V_2 ) ;
V_2 -> V_200 = V_196 ;
case V_196 :
if ( V_204 == V_195 ) {
F_78 ( V_2 , V_95 , V_2 -> V_17 , L_26 ) ;
if ( F_77 ( V_2 ) )
F_92 ( V_2 ) ;
if ( V_2 -> V_200 == V_195 )
F_84 ( V_2 ) ;
V_2 -> V_200 = V_195 ;
}
break;
case V_195 :
if ( V_204 == V_196 ) {
F_78 ( V_2 , V_95 , V_2 -> V_17 , L_27 ) ;
V_2 -> V_200 = V_196 ;
}
if ( F_83 ( V_2 ) )
V_2 -> V_200 = V_196 ;
break;
}
F_13 ( & V_2 -> V_24 , V_23 ) ;
F_98 ( & V_2 -> V_206 , V_207 + V_208 * 1 ) ;
}
static void F_99 ( struct V_1 * V_2 )
{
if ( F_85 ( V_2 ) )
F_100 ( V_198 , & V_2 -> V_199 ) ;
else
F_101 ( V_198 , & V_2 -> V_199 ) ;
}
static void F_102 ( struct V_1 * V_2 )
{
F_49 ( V_2 ) ;
if ( F_93 ( V_209 , & V_2 -> V_199 ) ) {
if ( F_85 ( V_2 ) )
F_61 ( V_2 ) ;
} else {
if ( F_85 ( V_2 ) )
F_89 ( V_2 ) ;
}
}
static int F_103 ( struct V_1 * V_2 )
{
T_1 V_22 ;
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
if ( F_1 ( V_2 , V_197 ,
( V_14 | ( V_2 -> V_15 ) *
2 ) << 7 ) )
return - 1 ;
if ( V_2 -> V_210 == V_211 )
F_21 ( V_2 ,
& V_6 -> V_89 , 0x0f00000 ) ;
V_22 = V_212 ;
F_21 ( V_2 , & V_6 -> V_89 ,
V_22 | ( ( V_213 ) << 16 ) ) ;
F_5 ( V_2 , V_197 ) ;
return 0 ;
}
static int F_104 ( struct V_1 * V_2 )
{
int V_214 ;
unsigned long V_23 ;
F_12 ( & V_2 -> V_24 , V_23 ) ;
if ( F_1 ( V_2 , V_197 ,
( V_14 |
( V_2 -> V_15 ) * 2 ) << 7 ) ) {
F_13 ( & V_2 -> V_24 , V_23 ) ;
return 0 ;
}
V_214 = F_76 ( V_2 ) ;
F_5 ( V_2 , V_197 ) ;
F_13 ( & V_2 -> V_24 , V_23 ) ;
return V_214 ;
}
static T_1 F_105 ( struct V_1 * V_2 )
{
T_1 V_214 ;
unsigned long V_23 ;
F_12 ( & V_2 -> V_24 , V_23 ) ;
if ( F_1 ( V_2 , V_197 ,
( V_14 |
( V_2 -> V_15 ) * 2 ) << 7 ) ) {
F_13 ( & V_2 -> V_24 , V_23 ) ;
return 0 ;
}
V_214 = F_81 ( V_2 ) ;
F_5 ( V_2 , V_197 ) ;
F_13 ( & V_2 -> V_24 , V_23 ) ;
return V_214 ;
}
static int F_106 ( struct V_1 * V_2 )
{
int V_214 ;
unsigned long V_23 ;
F_12 ( & V_2 -> V_24 , V_23 ) ;
if ( F_1 ( V_2 , V_197 ,
( V_14 |
( V_2 -> V_15 ) * 2 ) << 7 ) ) {
F_13 ( & V_2 -> V_24 , V_23 ) ;
return 0 ;
}
V_214 = F_82 ( V_2 ) ;
F_5 ( V_2 , V_197 ) ;
F_13 ( & V_2 -> V_24 , V_23 ) ;
return V_214 ;
}
static int F_107 ( struct V_67 * V_17 , struct V_215 * V_216 )
{
struct V_1 * V_2 = F_108 ( V_17 ) ;
V_216 -> V_217 = V_218 ;
V_216 -> V_219 = F_109 ( V_2 ) ;
if ( F_93 ( V_209 , & V_2 -> V_199 ) ) {
V_216 -> V_220 = V_221 ;
} else {
V_216 -> V_220 = V_222 ;
V_216 -> V_223 = V_2 -> V_87 ;
}
V_216 -> V_224 = F_109 ( V_2 ) ;
V_216 -> V_225 = F_104 ( V_2 ) ;
F_110 ( V_216 , F_105 ( V_2 ) ) ;
V_216 -> V_226 = F_106 ( V_2 ) ;
return 0 ;
}
static void F_111 ( struct V_67 * V_17 ,
struct V_227 * V_228 )
{
struct V_1 * V_2 = F_108 ( V_17 ) ;
strncpy ( V_228 -> V_229 , V_230 , 32 ) ;
strncpy ( V_228 -> V_231 , V_232 , 32 ) ;
strncpy ( V_228 -> V_233 , L_28 , 32 ) ;
strncpy ( V_228 -> V_234 , F_112 ( V_2 -> V_38 ) , 32 ) ;
V_228 -> V_235 = 0 ;
V_228 -> V_236 = 0 ;
}
static T_1 F_113 ( struct V_67 * V_17 )
{
struct V_1 * V_2 = F_108 ( V_17 ) ;
return V_2 -> V_237 ;
}
static void F_114 ( struct V_67 * V_17 , T_1 V_8 )
{
struct V_1 * V_2 = F_108 ( V_17 ) ;
V_2 -> V_237 = V_8 ;
}
static void F_115 ( struct V_67 * V_17 ,
struct V_238 * V_239 )
{
struct V_1 * V_2 = F_108 ( V_17 ) ;
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
T_1 V_22 ;
if ( V_2 -> V_15 == 0 )
V_22 = F_16 ( V_2 , & V_6 -> V_148 ) ;
else
V_22 = F_16 ( V_2 , & V_6 -> V_147 ) ;
V_239 -> V_225 = F_104 ( V_2 ) ;
V_239 -> V_240 = ( V_22 & V_153 ) >> 2 ;
V_239 -> V_241 = ( V_22 & V_152 ) >> 1 ;
}
static int F_116 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = V_2 -> V_33 ;
T_3 V_29 ;
int V_30 ;
while ( V_28 ) {
if ( ! V_28 -> V_34 ) {
V_28 -> V_34 =
F_27 ( V_2 -> V_17 ,
V_2 -> V_35 ) ;
if ( F_28 ( ! V_28 -> V_34 ) ) {
F_8 ( V_16 , V_2 -> V_17 ,
L_29 ) ;
break;
} else {
F_29 ( V_28 -> V_34 , V_37 ) ;
V_29 = F_30 ( V_2 -> V_38 ,
V_28 -> V_34 -> V_39 ,
V_2 -> V_35 -
V_37 ,
V_40 ) ;
V_30 = F_31 ( V_2 -> V_38 , V_29 ) ;
if ( V_30 ) {
F_9 ( V_2 -> V_17 ,
L_4 ,
V_30 ) ;
F_32 ( V_28 -> V_34 ) ;
V_28 -> V_34 = NULL ;
break;
}
V_28 -> V_41 =
F_33 ( F_34 ( V_29 ) ) ;
V_28 -> V_42 =
F_33 ( F_35 ( V_29 ) ) ;
F_36 ( V_28 , V_43 , V_29 ) ;
F_37 ( V_28 , V_44 ,
V_2 -> V_35 -
V_37 ) ;
-- V_2 -> V_36 ;
if ( ! V_2 -> V_36 )
return 1 ;
}
}
V_28 = V_28 -> V_31 ;
}
return 0 ;
}
static void F_117 ( struct V_1 * V_2 )
{
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
if ( V_2 -> V_242 >= 16 ) {
while ( V_2 -> V_242 >= 16 ) {
V_2 -> V_243 ++ ;
if ( V_2 -> V_243 ==
V_244 )
V_2 -> V_243 = 0 ;
V_2 -> V_242 -= 8 ;
}
F_118 () ;
F_2 ( V_2 -> V_243 ,
& V_6 -> V_10 . V_245 ) ;
}
}
static void F_119 ( struct V_1 * V_2 )
{
struct V_246 * V_247 ;
int V_12 ;
struct V_27 * V_28 ;
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
if ( ( V_2 -> V_45 >= 8 ) &&
( V_2 -> V_248 >= 16 ) ) {
if ( V_2 -> V_36 )
if ( ! F_116 ( V_2 ) )
return;
V_247 = V_2 -> V_249 ;
while ( ( V_2 -> V_248 >= 16 ) &&
( V_2 -> V_45 >= 8 ) ) {
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ ) {
V_28 =
F_38 ( V_2 ) ;
V_247 -> V_250 =
V_28 -> V_42 ;
V_247 -> V_251 =
V_28 -> V_41 ;
V_247 ++ ;
V_2 -> V_248 -- ;
}
V_2 -> V_252 ++ ;
if ( V_2 -> V_252 ==
V_2 -> V_253 )
V_2 -> V_252 = 0 ;
if ( V_2 -> V_252 ==
( V_2 -> V_253 - 1 ) ) {
V_247 = V_2 -> V_254 ;
}
}
F_118 () ;
V_2 -> V_249 = V_247 ;
F_2 ( V_2 -> V_252 ,
& V_6 -> V_10 . V_255 ) ;
}
}
static void F_120 ( struct V_1 * V_2 ,
struct V_256 * V_257 )
{
struct V_258 * V_259 ;
int V_12 ;
int V_260 = 0 ;
if ( V_257 -> V_199 & V_261 ) {
F_121 ( V_2 -> V_17 ,
L_30 ) ;
}
V_259 = & V_2 -> V_262 [ V_257 -> V_263 ] ;
if ( V_257 -> V_199 & V_261 ) {
F_9 ( V_2 -> V_17 ,
L_31 ) ;
V_2 -> V_17 -> V_264 . V_265 ++ ;
V_260 = - V_144 ;
goto V_266;
}
if ( V_259 -> V_267 == 0 ) {
F_9 ( V_2 -> V_17 , L_32 ,
V_257 -> V_263 ) ;
V_2 -> V_17 -> V_264 . V_265 ++ ;
V_260 = - V_144 ;
goto V_268;
}
F_122 ( V_2 -> V_38 ,
F_123 ( & V_259 -> V_29 [ 0 ] , V_43 ) ,
F_124 ( & V_259 -> V_29 [ 0 ] , V_44 ) ,
V_269 ) ;
V_259 -> V_267 -- ;
if ( V_259 -> V_267 ) {
for ( V_12 = 1 ; V_12 < V_259 -> V_267 ; V_12 ++ ) {
F_125 ( V_2 -> V_38 ,
F_123 ( & V_259 -> V_29 [ V_12 ] ,
V_43 ) ,
F_124 ( & V_259 -> V_29 [ V_12 ] , V_44 ) ,
V_269 ) ;
}
}
V_2 -> V_17 -> V_264 . V_270 ++ ;
V_2 -> V_17 -> V_264 . V_271 += V_259 -> V_34 -> V_272 ;
V_266:
F_126 ( V_259 -> V_34 ) ;
V_259 -> V_34 = NULL ;
V_268:
F_127 ( & V_2 -> V_273 ) ;
}
static void F_128 ( struct V_1 * V_2 )
{
if ( ++ V_2 -> V_274 == V_275 )
V_2 -> V_274 = 0 ;
V_2 -> V_242 ++ ;
}
static struct V_27 * F_129 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = NULL ;
V_28 = & V_2 -> V_276 [ V_2 -> V_277 ] ;
V_2 -> V_248 ++ ;
if ( ++ V_2 -> V_277 == V_2 -> V_278 )
V_2 -> V_277 = 0 ;
return V_28 ;
}
static void F_130 ( struct V_1 * V_2 ,
struct V_279 * V_280 )
{
struct V_27 * V_281 = NULL ;
struct V_27 * V_282 = NULL ;
struct V_283 * V_34 ;
V_65 V_284 = F_131 ( V_280 -> V_284 ) ;
F_128 ( V_2 ) ;
if ( V_2 -> V_210 == V_285 )
V_281 = F_129 ( V_2 ) ;
V_282 = F_129 ( V_2 ) ;
V_34 = V_282 -> V_34 ;
V_2 -> V_17 -> V_264 . V_286 ++ ;
V_2 -> V_17 -> V_264 . V_287 += V_284 ;
F_132 ( V_34 , V_284 ) ;
F_122 ( V_2 -> V_38 ,
F_123 ( V_282 , V_43 ) ,
F_124 ( V_282 , V_44 ) ,
V_40 ) ;
F_133 ( V_34 -> V_39 ) ;
F_134 ( V_34 ) ;
V_34 -> V_288 = F_135 ( V_34 , V_2 -> V_17 ) ;
F_136 ( V_34 ) ;
V_282 -> V_34 = NULL ;
if ( V_2 -> V_210 == V_285 )
F_26 ( V_2 , V_281 ) ;
F_26 ( V_2 , V_282 ) ;
}
static void F_137 ( struct V_1 * V_2 ,
struct V_289 * V_290 )
{
struct V_27 * V_281 = NULL ;
struct V_27 * V_282 = NULL ;
struct V_283 * V_291 = NULL , * V_292 ;
struct V_67 * V_17 = V_2 -> V_17 ;
V_65 V_284 = F_131 ( V_290 -> V_284 ) ;
V_65 V_293 = 0 ;
F_128 ( V_2 ) ;
if ( V_2 -> V_210 == V_285 ) {
V_281 = F_129 ( V_2 ) ;
V_291 = V_281 -> V_34 ;
V_293 = V_294 ;
if ( * ( ( V_65 * ) V_291 -> V_39 ) != 0xFFFF )
V_293 += V_295 - V_294 ;
}
V_282 = F_129 ( V_2 ) ;
V_292 = V_282 -> V_34 ;
F_132 ( V_292 , V_284 ) ;
F_122 ( V_2 -> V_38 ,
F_123 ( V_282 , V_43 ) ,
F_124 ( V_282 , V_44 ) ,
V_40 ) ;
F_133 ( V_292 -> V_39 ) ;
F_134 ( V_292 ) ;
if ( V_2 -> V_210 == V_285 ) {
F_138 ( V_291 , V_296 ,
F_139 ( V_292 , V_293 ) , V_293 ) ;
} else {
V_65 V_72 = F_131 ( V_290 -> V_72 ) ;
if ( V_72 &
( V_297 |
V_298 ) ) {
F_9 ( V_17 ,
L_33 ,
V_76 ,
( ( V_72 & V_299 ) ?
L_34 : L_35 ) , V_72 ) ;
} else if ( ( V_72 & V_299 ) ||
( V_72 & V_300 &&
! ( V_72 & V_301 ) ) ) {
V_292 -> V_302 = V_303 ;
}
}
V_292 -> V_288 = F_135 ( V_292 , V_2 -> V_17 ) ;
F_136 ( V_292 ) ;
V_17 -> V_264 . V_286 ++ ;
V_17 -> V_264 . V_287 += V_284 ;
V_282 -> V_34 = NULL ;
if ( V_2 -> V_210 == V_285 )
F_26 ( V_2 , V_281 ) ;
F_26 ( V_2 , V_282 ) ;
}
static int F_140 ( struct V_1 * V_2 ,
int * V_304 , int * V_305 , int V_306 )
{
struct V_307 * V_308 ;
struct V_67 * V_17 = V_2 -> V_17 ;
int V_309 = 0 ;
while ( ( F_141 ( * ( V_2 -> V_310 ) ) !=
V_2 -> V_311 ) && ( V_309 < V_306 ) ) {
V_308 = V_2 -> V_312 ;
F_142 () ;
if ( V_2 -> V_210 == V_211 )
V_308 -> V_313 &= 0x7f ;
switch ( V_308 -> V_313 ) {
case V_314 :
case V_315 :
F_120 ( V_2 , (struct V_256 * )
V_308 ) ;
( * V_304 ) ++ ;
break;
case V_316 :
case V_317 :
F_130 ( V_2 , (struct V_279 * )
V_308 ) ;
( * V_305 ) ++ ;
break;
case V_318 :
case V_319 :
F_137 ( V_2 , (struct V_289 * )
V_308 ) ;
( * V_305 ) ++ ;
break;
default: {
T_1 * V_320 = ( T_1 * ) V_308 ;
F_9 ( V_17 ,
L_36
L_37
L_38 ,
V_308 -> V_313 ,
( unsigned long int ) V_320 [ 0 ] ,
( unsigned long int ) V_320 [ 1 ] ,
( unsigned long int ) V_320 [ 2 ] ,
( unsigned long int ) V_320 [ 3 ] ) ;
}
}
V_2 -> V_311 ++ ;
if ( V_2 -> V_311 == V_321 ) {
V_2 -> V_311 = 0 ;
V_2 -> V_312 = V_2 -> V_322 ;
} else {
V_2 -> V_312 ++ ;
}
V_309 = * V_304 + * V_305 ;
}
return V_309 ;
}
static int F_143 ( struct V_323 * V_324 , int V_325 )
{
struct V_1 * V_2 = F_97 ( V_324 , struct V_1 , V_324 ) ;
int V_305 = 0 , V_304 = 0 ;
unsigned long V_23 ;
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
F_140 ( V_2 , & V_304 , & V_305 , V_325 ) ;
if ( V_304 + V_305 != V_325 ) {
F_12 ( & V_2 -> V_24 , V_23 ) ;
F_144 ( V_324 ) ;
F_117 ( V_2 ) ;
F_119 ( V_2 ) ;
F_2 ( V_2 -> V_311 ,
& V_6 -> V_10 . V_326 ) ;
F_13 ( & V_2 -> V_24 , V_23 ) ;
F_25 ( V_2 ) ;
}
return V_304 + V_305 ;
}
static T_6 F_145 ( int V_327 , void * V_328 )
{
struct V_67 * V_17 = V_328 ;
struct V_1 * V_2 = F_108 ( V_17 ) ;
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
T_1 V_8 ;
int V_329 = 1 ;
T_1 V_330 ;
V_8 = F_11 ( V_2 ,
& V_6 -> V_10 . V_20 ) ;
if ( V_8 & ( V_331 | V_332 ) ) {
F_146 ( & V_2 -> V_333 ) ;
F_147 ( V_2 -> V_17 ) ;
F_148 ( V_2 -> V_17 ) ;
F_24 ( V_2 ) ;
V_2 -> V_200 = V_196 ;
F_100 ( V_205 , & V_2 -> V_199 ) ;
if ( V_8 & V_331 ) {
V_330 =
F_15 ( V_2 ,
& V_6 -> V_334 ) ;
F_121 ( V_17 ,
L_39 ,
V_330 ) ;
F_100 ( V_335 , & V_2 -> V_199 ) ;
} else {
F_100 ( V_336 , & V_2 -> V_199 ) ;
F_9 ( V_17 ,
L_40 ,
V_8 ) ;
}
F_149 ( V_2 -> V_337 , & V_2 -> V_338 , 0 ) ;
F_150 ( & V_2 -> V_333 ) ;
} else if ( V_8 & V_339 ) {
F_24 ( V_2 ) ;
if ( F_151 ( F_152 ( & V_2 -> V_324 ) ) )
F_153 ( & V_2 -> V_324 ) ;
} else
return V_340 ;
return F_154 ( V_329 ) ;
}
static int F_155 ( struct V_1 * V_2 , unsigned short V_341 )
{
if ( V_2 -> V_210 == V_285 )
return 1 ;
if ( V_341 <= 2 )
return V_341 + 1 ;
else if ( V_341 <= 6 )
return V_341 + 2 ;
else if ( V_341 <= 10 )
return V_341 + 3 ;
else if ( V_341 <= 14 )
return V_341 + 4 ;
else if ( V_341 <= 18 )
return V_341 + 5 ;
return - 1 ;
}
static void F_156 ( const struct V_283 * V_34 ,
struct V_342 * V_343 )
{
const struct V_344 * V_345 = F_157 ( V_34 ) ;
V_343 -> V_346 = F_158 ( V_34 ) ;
V_343 -> V_347 = V_345 -> V_348 ;
if ( V_345 -> V_288 == V_349 ) {
V_343 -> V_350 |= V_351 |
V_352 ;
} else {
V_343 -> V_350 |= V_353 |
V_352 ;
}
}
static int F_159 ( struct V_1 * V_2 ,
struct V_342 * V_343 ,
struct V_258 * V_259 ,
struct V_283 * V_34 )
{
struct V_354 * V_354 ;
struct V_355 * V_355 ;
int V_272 = F_160 ( V_34 ) ;
T_3 V_29 ;
int V_30 ;
int V_356 , V_12 ;
int V_357 , V_358 = 0 ;
int V_359 = ( int ) F_161 ( V_34 ) -> V_360 ;
V_357 = V_259 -> V_267 ;
V_29 = F_30 ( V_2 -> V_38 , V_34 -> V_39 , V_272 , V_269 ) ;
V_30 = F_31 ( V_2 -> V_38 , V_29 ) ;
if ( V_30 ) {
F_9 ( V_2 -> V_17 , L_4 ,
V_30 ) ;
return V_361 ;
}
V_355 = (struct V_355 * ) & V_343 -> V_362 ;
V_355 -> V_363 = F_33 ( F_34 ( V_29 ) ) ;
V_355 -> V_364 = F_33 ( F_35 ( V_29 ) ) ;
V_355 -> V_272 = F_33 ( V_272 ) ;
F_36 ( & V_259 -> V_29 [ V_358 ] , V_43 , V_29 ) ;
F_37 ( & V_259 -> V_29 [ V_358 ] , V_44 , V_272 ) ;
V_358 ++ ;
if ( V_357 == 1 ) {
V_355 -> V_272 |= F_33 ( V_365 ) ;
return V_366 ;
}
V_354 = V_259 -> V_354 ;
for ( V_356 = 0 ;
V_356 < V_359 ;
V_356 ++ , V_358 ++ ) {
T_7 * V_367 = & F_161 ( V_34 ) -> V_341 [ V_356 ] ;
V_355 ++ ;
if ( ( V_358 == 2 && V_357 > 3 ) ||
( V_358 == 7 && V_357 > 8 ) ||
( V_358 == 12 && V_357 > 13 ) ||
( V_358 == 17 && V_357 > 18 ) ) {
V_29 = F_30 ( V_2 -> V_38 , V_354 ,
sizeof( struct V_354 ) ,
V_269 ) ;
V_30 = F_31 ( V_2 -> V_38 , V_29 ) ;
if ( V_30 ) {
F_9 ( V_2 -> V_17 ,
L_41 ,
V_30 ) ;
goto V_368;
}
V_355 -> V_363 = F_33 ( F_34 ( V_29 ) ) ;
V_355 -> V_364 = F_33 ( F_35 ( V_29 ) ) ;
V_355 -> V_272 = F_33 ( sizeof( struct V_354 ) |
V_369 ) ;
F_36 ( & V_259 -> V_29 [ V_358 ] , V_43 , V_29 ) ;
F_37 ( & V_259 -> V_29 [ V_358 ] , V_44 ,
sizeof( struct V_354 ) ) ;
V_355 = (struct V_355 * ) V_354 ;
V_354 ++ ;
V_358 ++ ;
}
V_29 = F_162 ( V_2 -> V_38 , V_367 -> V_18 ,
V_367 -> V_370 , V_367 -> V_293 ,
V_269 ) ;
V_30 = F_31 ( V_2 -> V_38 , V_29 ) ;
if ( V_30 ) {
F_9 ( V_2 -> V_17 ,
L_42 ,
V_30 ) ;
goto V_368;
}
V_355 -> V_363 = F_33 ( F_34 ( V_29 ) ) ;
V_355 -> V_364 = F_33 ( F_35 ( V_29 ) ) ;
V_355 -> V_272 = F_33 ( V_367 -> V_293 ) ;
F_36 ( & V_259 -> V_29 [ V_358 ] , V_43 , V_29 ) ;
F_37 ( & V_259 -> V_29 [ V_358 ] , V_44 , V_367 -> V_293 ) ;
}
V_355 -> V_272 |= F_33 ( V_365 ) ;
return V_366 ;
V_368:
V_358 = 1 ;
V_355 = (struct V_355 * ) & V_343 -> V_362 ;
V_354 = V_259 -> V_354 ;
for ( V_12 = 0 ; V_12 < V_356 ; V_12 ++ , V_358 ++ ) {
V_355 ++ ;
if ( ( V_358 == 2 && V_357 > 3 ) ||
( V_358 == 7 && V_357 > 8 ) ||
( V_358 == 12 && V_357 > 13 ) ||
( V_358 == 17 && V_357 > 18 ) ) {
F_122 ( V_2 -> V_38 ,
F_123 ( & V_259 -> V_29 [ V_358 ] , V_43 ) ,
F_124 ( & V_259 -> V_29 [ V_358 ] , V_44 ) ,
V_269 ) ;
V_354 ++ ;
V_358 ++ ;
}
F_125 ( V_2 -> V_38 ,
F_123 ( & V_259 -> V_29 [ V_358 ] , V_43 ) ,
F_124 ( & V_259 -> V_29 [ V_358 ] , V_44 ) ,
V_269 ) ;
}
F_122 ( V_2 -> V_38 ,
F_123 ( & V_259 -> V_29 [ 0 ] , V_43 ) ,
F_123 ( & V_259 -> V_29 [ 0 ] , V_44 ) ,
V_269 ) ;
return V_361 ;
}
static T_8 F_163 ( struct V_283 * V_34 ,
struct V_67 * V_17 )
{
struct V_1 * V_2 = F_108 ( V_17 ) ;
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
struct V_258 * V_259 ;
T_1 V_371 = V_34 -> V_272 ;
struct V_342 * V_343 ;
if ( F_28 ( F_164 ( & V_2 -> V_273 ) < 2 ) )
return V_361 ;
V_259 = & V_2 -> V_262 [ V_2 -> V_372 ] ;
V_259 -> V_267 = F_155 ( V_2 ,
F_161 ( V_34 ) -> V_360 ) ;
if ( V_259 -> V_267 == - 1 ) {
F_9 ( V_17 , L_43 , V_76 ) ;
return V_366 ;
}
V_343 = V_259 -> V_373 ;
memset ( ( void * ) V_343 , 0 , sizeof( struct V_342 ) ) ;
V_343 -> V_313 = V_2 -> V_374 ;
V_343 -> V_199 = V_375 ;
V_343 -> V_199 |= V_2 -> V_376 ;
V_343 -> V_263 = V_2 -> V_372 ;
V_343 -> V_377 = F_45 ( ( V_65 ) V_371 ) ;
V_259 -> V_34 = V_34 ;
if ( V_2 -> V_210 == V_211 &&
V_34 -> V_302 == V_378 )
F_156 ( V_34 , V_343 ) ;
if ( F_159 ( V_2 , V_343 , V_259 , V_34 ) != V_366 ) {
F_9 ( V_17 , L_44 , V_76 ) ;
return V_361 ;
}
F_118 () ;
V_2 -> V_372 ++ ;
if ( V_2 -> V_372 == V_379 )
V_2 -> V_372 = 0 ;
F_118 () ;
F_17 ( V_2 ,
& V_6 -> V_10 . V_380 ,
V_2 -> V_372 ) ;
F_86 ( V_2 , V_381 , V_16 , V_17 ,
L_45 ,
V_2 -> V_372 , V_34 -> V_272 ) ;
F_165 ( & V_2 -> V_273 ) ;
return V_366 ;
}
static int F_166 ( struct V_1 * V_2 )
{
V_2 -> V_382 =
( T_1 ) ( V_379 * sizeof( struct V_342 ) ) ;
V_2 -> V_383 =
F_167 ( V_2 -> V_38 ,
( V_384 ) V_2 -> V_382 ,
& V_2 -> V_385 ) ;
if ( ( V_2 -> V_383 == NULL ) ||
F_34 ( V_2 -> V_385 ) & ( V_2 -> V_382 - 1 ) ) {
F_9 ( V_2 -> V_17 , L_46 ) ;
return - V_386 ;
}
V_2 -> V_387 = V_321 * sizeof( struct V_307 ) ;
V_2 -> V_322 =
F_167 ( V_2 -> V_38 ,
( V_384 ) V_2 -> V_387 ,
& V_2 -> V_388 ) ;
if ( ( V_2 -> V_322 == NULL ) ||
F_34 ( V_2 -> V_388 ) & ( V_2 -> V_387 - 1 ) ) {
F_9 ( V_2 -> V_17 , L_47 ) ;
F_168 ( V_2 -> V_38 , ( V_384 ) V_2 -> V_382 ,
V_2 -> V_383 ,
V_2 -> V_385 ) ;
return - V_386 ;
}
F_100 ( V_389 , & V_2 -> V_199 ) ;
return 0 ;
}
static void F_169 ( struct V_1 * V_2 )
{
if ( ! F_93 ( V_389 , & V_2 -> V_199 ) ) {
F_64 ( V_2 -> V_17 , L_48 ) ;
return;
}
F_168 ( V_2 -> V_38 ,
V_2 -> V_382 ,
V_2 -> V_383 , V_2 -> V_385 ) ;
V_2 -> V_383 = NULL ;
F_168 ( V_2 -> V_38 ,
V_2 -> V_387 ,
V_2 -> V_322 , V_2 -> V_388 ) ;
V_2 -> V_322 = NULL ;
F_101 ( V_389 , & V_2 -> V_199 ) ;
}
static int F_170 ( struct V_1 * V_2 )
{
V_2 -> V_390 =
V_2 -> V_253 * sizeof( struct V_391 ) ;
if ( V_2 -> V_390 < V_392 )
V_2 -> V_393 = V_392 ;
else
V_2 -> V_393 = V_2 -> V_390 * 2 ;
V_2 -> V_276 =
F_171 ( V_2 -> V_278 * sizeof( struct V_27 ) ,
V_394 ) ;
if ( V_2 -> V_276 == NULL ) {
F_9 ( V_2 -> V_17 , L_49 ) ;
return - V_386 ;
}
V_2 -> V_395 =
F_167 ( V_2 -> V_38 ,
V_2 -> V_393 ,
& V_2 -> V_396 ) ;
if ( V_2 -> V_395 == NULL ) {
F_9 ( V_2 -> V_17 , L_50 ) ;
return - V_386 ;
}
V_2 -> V_254 = V_2 -> V_395 ;
V_2 -> V_397 = V_2 -> V_396 ;
V_2 -> V_398 =
V_244 * sizeof( struct V_391 ) ;
if ( V_2 -> V_398 < V_392 )
V_2 -> V_399 = V_392 ;
else
V_2 -> V_399 = V_2 -> V_398 * 2 ;
V_2 -> V_400 =
F_167 ( V_2 -> V_38 ,
V_2 -> V_399 ,
& V_2 -> V_401 ) ;
if ( V_2 -> V_400 == NULL ) {
F_9 ( V_2 -> V_17 , L_51 ) ;
F_168 ( V_2 -> V_38 , V_2 -> V_393 ,
V_2 -> V_395 ,
V_2 -> V_396 ) ;
return - V_386 ;
}
V_2 -> V_402 = V_2 -> V_400 ;
V_2 -> V_403 = V_2 -> V_401 ;
F_100 ( V_404 , & V_2 -> V_199 ) ;
return 0 ;
}
static void F_172 ( struct V_1 * V_2 )
{
if ( ! F_93 ( V_404 , & V_2 -> V_199 ) ) {
F_64 ( V_2 -> V_17 , L_48 ) ;
return;
}
F_173 ( V_2 -> V_276 ) ;
F_168 ( V_2 -> V_38 ,
V_2 -> V_393 ,
V_2 -> V_395 ,
V_2 -> V_396 ) ;
V_2 -> V_254 = NULL ;
F_168 ( V_2 -> V_38 ,
V_2 -> V_399 ,
V_2 -> V_400 ,
V_2 -> V_401 ) ;
V_2 -> V_402 = NULL ;
F_101 ( V_404 , & V_2 -> V_199 ) ;
}
static int F_174 ( struct V_1 * V_2 )
{
int V_12 ;
struct V_246 * V_405 ;
V_2 -> V_406 =
( V_407 * V_244 *
V_408 ) ;
V_2 -> V_409 =
F_167 ( V_2 -> V_38 ,
V_2 -> V_406 ,
& V_2 -> V_410 ) ;
if ( V_2 -> V_409 == NULL ) {
F_9 ( V_2 -> V_17 , L_52 ) ;
return - V_386 ;
}
V_2 -> V_411 = F_34 ( V_2 -> V_410 ) ;
V_2 -> V_412 = F_35 ( V_2 -> V_410 ) ;
V_405 = V_2 -> V_402 ;
for ( V_12 = 0 ; V_12 < ( V_407 * V_244 ) ; V_12 ++ ) {
V_405 -> V_250 =
F_33 ( V_2 -> V_412 ) ;
V_405 -> V_251 =
F_33 ( V_2 -> V_411 +
( V_12 * V_408 ) ) ;
V_405 ++ ;
}
V_2 -> V_274 = 0 ;
F_100 ( V_413 , & V_2 -> V_199 ) ;
return 0 ;
}
static void F_175 ( struct V_1 * V_2 )
{
if ( ! F_93 ( V_413 , & V_2 -> V_199 ) ) {
F_64 ( V_2 -> V_17 , L_48 ) ;
return;
}
if ( V_2 -> V_409 != NULL ) {
F_168 ( V_2 -> V_38 ,
V_2 -> V_406 ,
V_2 -> V_409 ,
V_2 -> V_410 ) ;
V_2 -> V_409 = NULL ;
}
}
static void F_176 ( struct V_1 * V_2 )
{
int V_12 = 0 ;
struct V_27 * V_28 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_278 ; V_12 ++ ) {
V_28 = & V_2 -> V_276 [ V_12 ] ;
if ( V_28 -> V_34 ) {
F_32 ( V_28 -> V_34 ) ;
F_122 ( V_2 -> V_38 ,
F_123 ( V_28 , V_43 ) ,
F_124 ( V_28 , V_44 ) ,
V_40 ) ;
memset ( V_28 , 0 , sizeof( struct V_27 ) ) ;
} else {
break;
}
}
}
static void F_177 ( struct V_1 * V_2 )
{
int V_12 ;
struct V_27 * V_28 ;
struct V_246 * V_414 = V_2 -> V_254 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_278 ; V_12 ++ ) {
V_28 = & V_2 -> V_276 [ V_12 ] ;
V_414 -> V_250 = V_28 -> V_42 ;
V_414 -> V_251 = V_28 -> V_41 ;
V_414 ++ ;
}
V_2 -> V_277 = 0 ;
V_2 -> V_36 = 0 ;
}
static int F_178 ( struct V_1 * V_2 )
{
int V_12 ;
struct V_27 * V_28 ;
struct V_283 * V_34 ;
T_3 V_29 ;
int V_30 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_278 ; V_12 ++ ) {
V_34 = F_27 ( V_2 -> V_17 ,
V_2 -> V_35 ) ;
if ( F_28 ( ! V_34 ) ) {
F_9 ( V_2 -> V_17 ,
L_53 ,
V_2 -> V_35 * 2 , V_12 ) ;
F_176 ( V_2 ) ;
return - V_386 ;
} else {
V_28 = & V_2 -> V_276 [ V_12 ] ;
memset ( V_28 , 0 , sizeof( struct V_27 ) ) ;
V_28 -> V_73 = V_12 ;
V_28 -> V_34 = V_34 ;
F_29 ( V_34 , V_37 ) ;
V_29 = F_30 ( V_2 -> V_38 ,
V_34 -> V_39 ,
V_2 -> V_35 -
V_37 ,
V_40 ) ;
V_30 = F_31 ( V_2 -> V_38 , V_29 ) ;
if ( V_30 ) {
F_9 ( V_2 -> V_17 ,
L_4 ,
V_30 ) ;
F_176 ( V_2 ) ;
return - V_386 ;
}
F_36 ( V_28 , V_43 , V_29 ) ;
F_37 ( V_28 , V_44 ,
V_2 -> V_35 -
V_37 ) ;
V_28 -> V_41 =
F_33 ( F_34 ( V_29 ) ) ;
V_28 -> V_42 =
F_33 ( F_35 ( V_29 ) ) ;
}
}
return 0 ;
}
static void F_179 ( struct V_1 * V_2 )
{
struct V_258 * V_259 ;
int V_12 ;
V_259 = & V_2 -> V_262 [ 0 ] ;
for ( V_12 = 0 ; V_12 < V_379 ; V_12 ++ ) {
F_173 ( V_259 -> V_354 ) ;
V_259 -> V_354 = NULL ;
V_259 ++ ;
}
}
static int F_180 ( struct V_1 * V_2 )
{
struct V_258 * V_259 ;
int V_12 ;
struct V_342 * V_415 = V_2 -> V_383 ;
for ( V_12 = 0 ; V_12 < V_379 ; V_12 ++ ) {
V_259 = & V_2 -> V_262 [ V_12 ] ;
V_259 -> V_34 = NULL ;
V_259 -> V_373 = V_415 ;
V_415 ++ ;
V_259 -> V_354 = F_171 ( 512 , V_394 ) ;
if ( V_259 -> V_354 == NULL )
return - 1 ;
}
return 0 ;
}
static int F_181 ( struct V_1 * V_2 )
{
if ( V_2 -> V_17 -> V_416 == V_417 ) {
V_2 -> V_253 = V_418 ;
V_2 -> V_35 = V_417 ;
} else if ( V_2 -> V_17 -> V_416 == V_419 ) {
V_2 -> V_253 = V_420 ;
V_2 -> V_35 = V_419 ;
} else {
F_9 ( V_2 -> V_17 , L_54 ,
V_2 -> V_17 -> V_416 , V_417 , V_419 ) ;
return - V_386 ;
}
V_2 -> V_278 =
V_2 -> V_253 * V_407 ;
V_2 -> V_35 += V_295 + V_296 + V_37 ;
V_2 -> V_421 =
( V_2 -> V_35 - V_37 ) + V_422 ;
V_2 -> V_423 =
F_167 ( V_2 -> V_38 ,
V_392 , & V_2 -> V_424 ) ;
if ( V_2 -> V_423 != NULL ) {
V_2 -> V_425 = V_2 -> V_423 ;
V_2 -> V_426 =
F_35 ( V_2 -> V_424 ) ;
V_2 -> V_427 =
F_34 ( V_2 -> V_424 ) ;
V_2 -> V_310 =
( V_428 * ) ( ( ( T_5 * ) V_2 -> V_425 ) + 8 ) ;
V_2 -> V_429 =
V_2 -> V_426 ;
V_2 -> V_430 =
V_2 -> V_427 + 8 ;
} else {
F_9 ( V_2 -> V_17 , L_55 ) ;
return - V_386 ;
}
if ( F_166 ( V_2 ) != 0 ) {
F_9 ( V_2 -> V_17 , L_56 ) ;
goto V_431;
}
if ( F_170 ( V_2 ) != 0 ) {
F_9 ( V_2 -> V_17 , L_57 ) ;
goto V_432;
}
if ( F_174 ( V_2 ) != 0 ) {
F_9 ( V_2 -> V_17 , L_58 ) ;
goto V_433;
}
if ( F_178 ( V_2 ) != 0 ) {
F_9 ( V_2 -> V_17 , L_59 ) ;
goto V_433;
}
F_177 ( V_2 ) ;
if ( F_180 ( V_2 ) )
goto V_434;
V_2 -> V_312 = V_2 -> V_322 ;
return 0 ;
V_434:
F_179 ( V_2 ) ;
V_433:
F_172 ( V_2 ) ;
V_432:
F_169 ( V_2 ) ;
V_431:
F_168 ( V_2 -> V_38 ,
V_392 ,
V_2 -> V_423 ,
V_2 -> V_424 ) ;
return - V_386 ;
}
static void F_182 ( struct V_1 * V_2 )
{
F_179 ( V_2 ) ;
F_176 ( V_2 ) ;
F_175 ( V_2 ) ;
F_172 ( V_2 ) ;
F_169 ( V_2 ) ;
if ( V_2 -> V_423 != NULL ) {
F_168 ( V_2 -> V_38 ,
V_392 ,
V_2 -> V_423 ,
V_2 -> V_424 ) ;
V_2 -> V_423 = NULL ;
}
}
static int F_183 ( struct V_1 * V_2 )
{
struct V_435 T_2 * V_436 =
( void T_2 * ) V_2 -> V_7 ;
if ( F_1 ( V_2 , V_437 ,
( V_14 | ( V_2 -> V_15 ) *
2 ) << 4 ) )
return - 1 ;
F_23 ( V_2 ,
& V_436 -> V_438 , V_2 -> V_74 . V_438 ) ;
F_23 ( V_2 ,
& V_436 -> V_439 ,
V_2 -> V_74 . V_440 ) ;
F_23 ( V_2 ,
& V_436 -> V_441 ,
( V_2 -> V_74 . V_442 << 16 ) |
( V_2 -> V_74 . V_443 ) ) ;
F_23 ( V_2 ,
& V_436 -> V_444 ,
V_2 -> V_74 . V_445 ) ;
F_23 ( V_2 ,
& V_436 -> V_446 ,
( V_2 -> V_74 . V_447 << 16 ) |
V_2 -> V_74 . V_448 ) ;
F_23 ( V_2 ,
& V_436 -> V_449 ,
V_2 -> V_74 . V_450 ) ;
F_23 ( V_2 ,
& V_436 -> V_451 ,
( V_2 -> V_74 . V_452 << 16 ) |
V_2 -> V_74 . V_453 ) ;
F_23 ( V_2 ,
& V_436 -> V_454 ,
V_2 -> V_74 . V_455 ) ;
F_23 ( V_2 ,
& V_436 -> V_456 ,
( V_2 -> V_74 . V_457 << 16 ) |
V_2 -> V_74 . V_458 ) ;
F_23 ( V_2 ,
& V_436 -> V_459 ,
V_2 -> V_74 . V_460 ) ;
F_23 ( V_2 ,
& V_436 -> V_461 ,
( V_2 -> V_74 . V_462 << 16 ) |
V_2 -> V_74 . V_463 ) ;
F_23 ( V_2 ,
& V_436 -> V_464 ,
V_2 -> V_74 . V_465 ) ;
F_5 ( V_2 , V_437 ) ;
return 0 ;
}
static int F_184 ( struct V_1 * V_2 )
{
T_1 V_8 ;
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
T_2 T_1 * V_46 = & V_6 -> V_10 . V_47 ;
struct V_466 T_2 * V_467 =
( void T_2 * ) V_6 ;
T_1 V_468 = 10 ;
int V_214 = 0 ;
unsigned long V_23 = 0 ;
if ( F_103 ( V_2 ) )
return - 1 ;
F_18 ( V_2 , V_46 ,
( V_469 |
( V_469 << 16 ) ) ) ;
F_185 ( 100 ) ;
V_2 -> V_200 = V_196 ;
F_148 ( V_2 -> V_17 ) ;
F_18 ( V_2 , V_46 ,
( V_470 |
( V_470 << 16 ) ) ) ;
* ( ( T_1 * ) ( V_2 -> V_425 ) ) = 0 ;
F_186 ( & V_2 -> V_273 , V_379 ) ;
V_2 -> V_372 = 0 ;
F_22 ( V_2 ,
& V_467 -> V_471 ,
V_2 -> V_426 ) ;
F_22 ( V_2 ,
& V_467 -> V_472 ,
V_2 -> V_427 ) ;
F_22 ( V_2 ,
& V_467 -> V_473 ,
F_35 ( V_2 -> V_385 ) ) ;
F_22 ( V_2 ,
& V_467 -> V_474 ,
F_34 ( V_2 -> V_385 ) ) ;
F_22 ( V_2 , & V_467 -> V_475 , V_379 ) ;
* ( ( T_4 * ) ( V_2 -> V_310 ) ) = 0 ;
V_2 -> V_311 = 0 ;
V_2 -> V_312 = V_2 -> V_322 ;
F_22 ( V_2 ,
& V_467 -> V_476 ,
V_2 -> V_429 ) ;
F_22 ( V_2 ,
& V_467 -> V_477 ,
V_2 -> V_430 ) ;
F_22 ( V_2 ,
& V_467 -> V_478 ,
F_35 ( V_2 -> V_388 ) ) ;
F_22 ( V_2 ,
& V_467 -> V_479 ,
F_34 ( V_2 -> V_388 ) ) ;
F_22 ( V_2 , & V_467 -> V_480 , V_321 ) ;
F_22 ( V_2 ,
& V_467 -> V_481 ,
F_35 ( V_2 -> V_397 ) ) ;
F_22 ( V_2 ,
& V_467 -> V_482 ,
F_34 ( V_2 -> V_397 ) ) ;
F_22 ( V_2 ,
& V_467 -> V_483 ,
V_2 -> V_253 ) ;
F_22 ( V_2 ,
& V_467 -> V_484 ,
V_2 -> V_35 ) ;
F_22 ( V_2 ,
& V_467 -> V_485 ,
F_35 ( V_2 -> V_403 ) ) ;
F_22 ( V_2 ,
& V_467 -> V_486 ,
F_34 ( V_2 -> V_403 ) ) ;
F_22 ( V_2 , & V_467 -> V_487 , V_244 ) ;
F_22 ( V_2 ,
& V_467 -> V_488 ,
V_408 ) ;
V_2 -> V_243 = V_244 - 1 ;
V_2 -> V_242 = 8 ;
V_2 -> V_252 = V_2 -> V_253 - 1 ;
V_2 -> V_248 = 8 ;
V_2 -> V_249 = V_2 -> V_254 ;
V_2 -> V_274 = 0 ;
V_2 -> V_277 = 0 ;
V_2 -> V_45 = 0 ;
V_2 -> V_33 = NULL ;
V_2 -> V_32 = NULL ;
F_18 ( V_2 ,
& V_6 -> V_10 .
V_245 ,
V_2 -> V_243 ) ;
F_18 ( V_2 ,
& V_6 -> V_10 .
V_255 ,
V_2 -> V_252 ) ;
F_101 ( V_198 , & V_2 -> V_199 ) ;
V_8 = F_16 ( V_2 , & V_6 -> V_157 ) ;
if ( ( V_8 & V_489 ) == 0 ) {
if ( F_183 ( V_2 ) ) {
V_214 = - 1 ;
goto V_490;
}
V_8 = V_2 -> V_74 . V_491 ;
F_21 ( V_2 , & V_6 -> V_492 , V_8 ) ;
V_8 = ( 0xFFFF << 16 ) | V_2 -> V_74 . V_493 ;
if ( F_1 ( V_2 , V_494 ,
( V_14 | ( V_2 -> V_15 )
* 2 ) << 13 ) ) {
V_214 = - 1 ;
goto V_490;
}
F_21 ( V_2 , & V_6 -> V_495 , V_8 ) ;
F_21 ( V_2 , & V_6 -> V_496 ,
( ( ( V_497 | V_498 ) <<
16 ) | ( V_497 |
V_498 ) ) ) ;
F_5 ( V_2 , V_494 ) ;
}
if ( V_2 -> V_15 )
F_21 ( V_2 ,
& V_6 -> V_499 ,
V_2 -> V_421 ) ;
else
F_21 ( V_2 ,
& V_6 -> V_500 ,
V_2 -> V_421 ) ;
if ( F_1 ( V_2 , V_197 ,
( V_14 | ( V_2 -> V_15 ) *
2 ) << 7 ) ) {
V_214 = - 1 ;
goto V_490;
}
F_69 ( V_2 ) ;
F_102 ( V_2 ) ;
F_99 ( V_2 ) ;
F_21 ( V_2 , & V_6 -> V_501 ,
( V_502 << 16 ) ) ;
F_21 ( V_2 , & V_6 -> V_503 ,
( ( V_2 -> V_17 -> V_70 [ 2 ] << 24 )
| ( V_2 -> V_17 -> V_70 [ 3 ] << 16 )
| ( V_2 -> V_17 -> V_70 [ 4 ] << 8 )
| V_2 -> V_17 -> V_70 [ 5 ] ) ) ;
F_21 ( V_2 , & V_6 -> V_501 ,
( ( V_502 << 16 ) | 1 ) ) ;
F_21 ( V_2 , & V_6 -> V_503 ,
( ( V_2 -> V_17 -> V_70 [ 0 ] << 8 )
| V_2 -> V_17 -> V_70 [ 1 ] ) ) ;
F_21 ( V_2 , & V_6 -> V_501 ,
( ( V_504 << 16 ) |
V_504 ) ) ;
F_21 ( V_2 , & V_6 -> V_505 ,
( ( V_506 << 16 ) |
( V_2 -> V_15 << 2 ) ) ) ;
F_21 ( V_2 , & V_6 -> V_507 , 0 ) ;
F_21 ( V_2 , & V_6 -> V_505 ,
( ( V_506 << 16 ) |
( ( V_2 -> V_15 << 2 ) + 1 ) ) ) ;
F_21 ( V_2 , & V_6 -> V_507 , 0 ) ;
F_5 ( V_2 , V_197 ) ;
F_21 ( V_2 ,
& V_6 -> V_508 ,
( ( V_509 << 16 ) | V_509 ) ) ;
do {
V_8 = F_16 ( V_2 , & V_6 -> V_157 ) ;
if ( V_8 & V_489 )
break;
F_13 ( & V_2 -> V_24 , V_23 ) ;
F_187 ( 500 ) ;
F_12 ( & V_2 -> V_24 , V_23 ) ;
} while ( -- V_468 );
if ( V_468 == 0 ) {
F_9 ( V_2 -> V_17 , L_60 ) ;
V_214 = - 1 ;
goto V_490;
}
if ( V_2 -> V_210 == V_211 ) {
V_8 =
( V_510 | V_511 |
V_512 | V_513 |
V_514 ) ;
F_21 ( V_2 , & V_6 -> V_515 ,
( ( V_8 << 16 ) | V_8 ) ) ;
} else {
V_8 =
( V_516 | V_517 | V_518 |
V_519 ) ;
F_21 ( V_2 , & V_6 -> V_508 ,
( ( V_8 << 16 ) | V_8 ) ) ;
}
V_490:
return V_214 ;
}
static int F_188 ( struct V_1 * V_2 )
{
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
int V_214 = 0 ;
V_65 V_8 ;
int V_520 ;
F_100 ( V_205 , & V_2 -> V_199 ) ;
F_101 ( V_521 , & V_2 -> V_199 ) ;
F_8 ( V_16 , V_2 -> V_17 , L_61 ) ;
F_18 ( V_2 ,
& V_6 -> V_10 . V_20 ,
( ( V_522 << 16 ) | V_522 ) ) ;
F_8 ( V_16 , V_2 -> V_17 ,
L_62 ) ;
V_520 = 5 ;
do {
V_8 =
F_14 ( V_2 ,
& V_6 -> V_10 . V_20 ) ;
if ( ( V_8 & V_522 ) == 0 )
break;
F_4 ( 1 ) ;
} while ( ( -- V_520 ) );
V_8 =
F_14 ( V_2 , & V_6 -> V_10 . V_20 ) ;
if ( V_8 & V_332 ) {
F_8 ( V_16 , V_2 -> V_17 ,
L_63 ) ;
F_18 ( V_2 ,
& V_6 -> V_10 .
V_20 ,
( ( V_332 << 16 ) | V_332 ) ) ;
}
if ( V_520 == 0 ) {
F_18 ( V_2 ,
& V_6 -> V_10 .
V_20 ,
( ( V_523 << 16 ) |
V_523 ) ) ;
V_520 = 5 ;
do {
V_8 = F_14 ( V_2 ,
& V_6 -> V_10 .
V_20 ) ;
if ( ( V_8 & V_523 ) == 0 )
break;
F_4 ( 1 ) ;
} while ( ( -- V_520 ) );
}
if ( V_520 == 0 )
V_214 = 1 ;
F_101 ( V_205 , & V_2 -> V_199 ) ;
F_100 ( V_521 , & V_2 -> V_199 ) ;
return V_214 ;
}
static void F_189 ( struct V_1 * V_2 )
{
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
T_1 V_8 , V_524 ;
T_5 V_525 ;
V_8 =
F_11 ( V_2 , & V_6 -> V_10 . V_20 ) ;
V_525 = ( T_5 ) ( ( V_8 >> 4 ) & V_526 ) ;
V_524 = F_16 ( V_2 , & V_6 -> V_157 ) ;
switch ( V_8 & V_527 ) {
case V_528 :
V_2 -> V_15 = 0 ;
V_2 -> V_374 = V_529 | V_525 ;
V_2 -> V_376 = V_530 ;
V_2 -> V_87 = V_531 ;
if ( V_524 & V_155 )
F_100 ( V_209 , & V_2 -> V_199 ) ;
else
F_101 ( V_209 , & V_2 -> V_199 ) ;
break;
case V_532 :
V_2 -> V_15 = 1 ;
V_2 -> V_374 = V_529 | V_525 ;
V_2 -> V_376 = V_533 ;
V_2 -> V_87 = V_534 ;
if ( V_524 & V_156 )
F_100 ( V_209 , & V_2 -> V_199 ) ;
else
F_101 ( V_209 , & V_2 -> V_199 ) ;
break;
case V_535 :
case V_536 :
default:
F_8 ( V_16 , V_2 -> V_17 ,
L_64 ,
V_8 ) ;
break;
}
V_2 -> V_83 = V_2 -> V_74 . V_537 >> 8 ;
}
static void F_190 ( struct V_67 * V_17 )
{
struct V_1 * V_2 = F_108 ( V_17 ) ;
struct V_538 * V_38 = V_2 -> V_38 ;
F_64 ( V_17 ,
L_65 ,
V_539 , V_2 -> V_73 , V_2 -> V_540 ,
V_2 -> V_210 == V_211 ? L_66 : L_67 ,
V_2 -> V_541 ) ;
F_64 ( V_17 , L_68 ,
F_93 ( V_209 , & V_2 -> V_199 ) ? L_69 : L_70 ) ;
F_64 ( V_17 , L_71 ,
( ( V_2 -> V_542 == 64 ) ? L_72 : L_73 ) ,
( ( V_2 -> V_543 ) ? L_74 : L_75 ) ) ;
F_64 ( V_17 , L_76 ,
V_2 -> V_7 ) ;
F_64 ( V_17 , L_77 , V_38 -> V_327 ) ;
F_78 ( V_2 , V_544 , V_17 , L_78 , V_17 -> V_70 ) ;
}
static int F_191 ( struct V_1 * V_2 , int V_545 )
{
struct V_67 * V_17 = V_2 -> V_17 ;
int V_260 = 0 ;
F_147 ( V_17 ) ;
F_148 ( V_17 ) ;
F_101 ( V_546 , & V_2 -> V_199 ) ;
F_101 ( V_198 , & V_2 -> V_199 ) ;
F_24 ( V_2 ) ;
F_192 ( V_2 -> V_38 -> V_327 , V_17 ) ;
if ( V_2 -> V_547 && F_93 ( V_548 , & V_2 -> V_199 ) ) {
F_64 ( V_2 -> V_17 , L_79 ) ;
F_101 ( V_548 , & V_2 -> V_199 ) ;
F_193 ( V_2 -> V_38 ) ;
}
F_194 ( & V_2 -> V_206 ) ;
F_195 ( & V_2 -> V_324 ) ;
if ( V_545 ) {
int V_549 ;
unsigned long V_23 ;
F_12 ( & V_2 -> V_24 , V_23 ) ;
if ( F_7 ( V_2 ) ) {
V_549 = F_188 ( V_2 ) ;
if ( V_549 ) {
F_9 ( V_17 , L_80 ,
V_2 -> V_73 ) ;
}
F_9 ( V_17 ,
L_81 ) ;
} else {
F_9 ( V_17 ,
L_82 ) ;
V_260 = - 1 ;
}
F_13 ( & V_2 -> V_24 , V_23 ) ;
}
F_182 ( V_2 ) ;
return V_260 ;
}
static int F_196 ( struct V_1 * V_2 )
{
struct V_67 * V_17 = V_2 -> V_17 ;
int V_30 ;
unsigned long V_550 = V_551 ;
unsigned long V_23 ;
if ( F_181 ( V_2 ) ) {
F_9 ( V_17 , L_83 ) ;
return - V_386 ;
}
if ( V_2 -> V_547 ) {
if ( F_197 ( V_2 -> V_38 ) ) {
F_9 ( V_17 ,
L_84 ) ;
V_2 -> V_547 = 0 ;
} else {
F_64 ( V_17 , L_85 ) ;
F_100 ( V_548 , & V_2 -> V_199 ) ;
V_550 &= ~ V_551 ;
}
}
V_30 = F_198 ( V_2 -> V_38 -> V_327 , F_145 ,
V_550 , V_17 -> V_125 , V_17 ) ;
if ( V_30 ) {
F_9 ( V_17 ,
L_86 ,
V_2 -> V_38 -> V_327 ) ;
goto V_552;
}
F_12 ( & V_2 -> V_24 , V_23 ) ;
V_30 = F_7 ( V_2 ) ;
if ( V_30 ) {
V_30 = F_184 ( V_2 ) ;
if ( V_30 ) {
F_9 ( V_17 , L_87 ) ;
goto V_553;
}
F_9 ( V_17 , L_88 ) ;
F_5 ( V_2 , V_13 ) ;
} else {
F_9 ( V_17 , L_89 ) ;
goto V_554;
}
F_13 ( & V_2 -> V_24 , V_23 ) ;
F_100 ( V_546 , & V_2 -> V_199 ) ;
F_98 ( & V_2 -> V_206 , V_207 + V_208 * 1 ) ;
F_199 ( & V_2 -> V_324 ) ;
F_25 ( V_2 ) ;
return 0 ;
V_553:
F_5 ( V_2 , V_13 ) ;
V_554:
F_13 ( & V_2 -> V_24 , V_23 ) ;
F_192 ( V_2 -> V_38 -> V_327 , V_17 ) ;
V_552:
if ( V_2 -> V_547 && F_93 ( V_548 , & V_2 -> V_199 ) ) {
F_64 ( V_17 , L_79 ) ;
F_101 ( V_548 , & V_2 -> V_199 ) ;
F_193 ( V_2 -> V_38 ) ;
}
return V_30 ;
}
static int F_200 ( struct V_1 * V_2 , int V_555 )
{
if ( F_191 ( V_2 , V_555 ) || F_196 ( V_2 ) ) {
F_9 ( V_2 -> V_17 ,
L_90 ) ;
F_201 () ;
F_202 ( V_2 -> V_17 ) ;
F_203 () ;
return - 1 ;
}
return 0 ;
}
static int F_204 ( struct V_67 * V_17 )
{
struct V_1 * V_2 = F_108 ( V_17 ) ;
while ( ! F_93 ( V_546 , & V_2 -> V_199 ) )
F_187 ( 50 ) ;
F_191 ( V_2 , V_556 ) ;
return 0 ;
}
static int F_205 ( struct V_67 * V_17 )
{
struct V_1 * V_2 = F_108 ( V_17 ) ;
return F_196 ( V_2 ) ;
}
static int F_206 ( struct V_67 * V_17 , void * V_69 )
{
struct V_1 * V_2 = F_108 ( V_17 ) ;
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
struct V_557 * V_68 = V_69 ;
unsigned long V_23 ;
if ( F_207 ( V_17 ) )
return - V_558 ;
if ( ! F_208 ( V_68 -> V_559 ) )
return - V_560 ;
memcpy ( V_17 -> V_70 , V_68 -> V_559 , V_17 -> V_561 ) ;
F_12 ( & V_2 -> V_24 , V_23 ) ;
F_21 ( V_2 , & V_6 -> V_501 ,
( V_502 << 16 ) ) ;
F_21 ( V_2 , & V_6 -> V_503 ,
( ( V_17 -> V_70 [ 2 ] << 24 ) | ( V_17 ->
V_70 [ 3 ] << 16 ) |
( V_17 -> V_70 [ 4 ] << 8 ) | V_17 -> V_70 [ 5 ] ) ) ;
F_21 ( V_2 , & V_6 -> V_501 ,
( ( V_502 << 16 ) | 1 ) ) ;
F_21 ( V_2 , & V_6 -> V_503 ,
( ( V_17 -> V_70 [ 0 ] << 8 ) | V_17 -> V_70 [ 1 ] ) ) ;
F_13 ( & V_2 -> V_24 , V_23 ) ;
return 0 ;
}
static void F_209 ( struct V_67 * V_17 )
{
struct V_1 * V_2 = F_108 ( V_17 ) ;
F_9 ( V_17 , L_91 ) ;
F_147 ( V_17 ) ;
F_149 ( V_2 -> V_337 , & V_2 -> V_562 , 0 ) ;
}
static void F_210 ( struct V_201 * V_202 )
{
struct V_1 * V_2 =
F_97 ( V_202 , struct V_1 , V_338 . V_202 ) ;
struct V_67 * V_17 = V_2 -> V_17 ;
T_1 V_8 ;
struct V_258 * V_259 ;
int V_520 , V_12 ;
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
unsigned long V_23 ;
if ( F_93 ( ( V_336 | V_335 ) , & V_2 -> V_199 ) ) {
F_101 ( V_198 , & V_2 -> V_199 ) ;
for ( V_12 = 0 ; V_12 < V_379 ; V_12 ++ ) {
int V_563 ;
V_259 = & V_2 -> V_262 [ V_12 ] ;
if ( V_259 -> V_34 ) {
F_8 ( V_16 , V_17 ,
L_92 ) ;
F_122 ( V_2 -> V_38 ,
F_123 ( & V_259 -> V_29 [ 0 ] ,
V_43 ) ,
F_124 ( & V_259 -> V_29 [ 0 ] , V_44 ) ,
V_269 ) ;
for ( V_563 = 1 ; V_563 < V_259 -> V_267 ; V_563 ++ ) {
F_125 ( V_2 -> V_38 ,
F_123 ( & V_259 -> V_29 [ V_563 ] ,
V_43 ) ,
F_124 ( & V_259 -> V_29 [ V_563 ] ,
V_44 ) ,
V_269 ) ;
}
F_32 ( V_259 -> V_34 ) ;
V_259 -> V_34 = NULL ;
}
}
F_9 ( V_17 , L_93 ) ;
F_12 ( & V_2 -> V_24 , V_23 ) ;
F_18 ( V_2 ,
& V_6 -> V_10 .
V_20 ,
( ( V_332 << 16 ) | V_332 ) ) ;
V_520 = 10 ;
do {
V_8 = F_14 ( V_2 ,
& V_6 -> V_10 .
V_20 ) ;
if ( ( V_8 & V_522 ) == 0 ) {
F_8 ( V_16 , V_17 ,
L_94 ) ;
break;
}
if ( V_8 & V_332 ) {
F_8 ( V_16 , V_17 ,
L_95 ) ;
F_18 ( V_2 ,
& V_6 ->
V_10 .
V_20 ,
( ( V_332 <<
16 ) | V_332 ) ) ;
}
F_13 ( & V_2 -> V_24 , V_23 ) ;
F_4 ( 1 ) ;
F_12 ( & V_2 -> V_24 , V_23 ) ;
} while ( -- V_520 );
F_13 ( & V_2 -> V_24 , V_23 ) ;
if ( V_8 & V_522 ) {
F_9 ( V_17 ,
L_96 ) ;
F_9 ( V_17 , L_97 ) ;
F_101 ( V_336 , & V_2 -> V_199 ) ;
F_101 ( V_335 , & V_2 -> V_199 ) ;
F_200 ( V_2 , V_556 ) ;
return;
}
F_101 ( V_205 , & V_2 -> V_199 ) ;
F_101 ( V_336 , & V_2 -> V_199 ) ;
F_101 ( V_335 , & V_2 -> V_199 ) ;
F_200 ( V_2 , V_564 ) ;
}
}
static void F_211 ( struct V_201 * V_202 )
{
struct V_1 * V_2 =
F_97 ( V_202 , struct V_1 , V_562 . V_202 ) ;
F_200 ( V_2 , V_556 ) ;
}
static void F_212 ( struct V_1 * V_2 )
{
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
T_1 V_8 ;
V_8 = F_15 ( V_2 , & V_6 -> V_157 ) ;
V_2 -> V_540 = ( ( V_8 & V_565 ) >> 12 ) ;
if ( V_8 & V_566 )
V_2 -> V_542 = 64 ;
else
V_2 -> V_542 = 32 ;
if ( V_8 & V_567 )
V_2 -> V_543 = 1 ;
else
V_2 -> V_543 = 0 ;
V_2 -> V_541 = ( T_5 ) F_213 ( V_2 -> V_38 -> V_568 ) ;
}
static void F_214 ( unsigned long V_569 )
{
struct V_1 * V_2 = (struct V_1 * ) V_569 ;
F_149 ( V_2 -> V_337 , & V_2 -> V_203 , 0 ) ;
}
static int T_9 F_215 ( struct V_538 * V_38 ,
const struct V_570 * V_571 )
{
struct V_67 * V_17 = NULL ;
struct V_1 * V_2 = NULL ;
static int V_572 ;
int V_573 ( V_574 ) , V_30 ;
V_30 = F_216 ( V_38 ) ;
if ( V_30 ) {
F_47 ( L_98 , F_112 ( V_38 ) ) ;
goto V_575;
}
V_30 = F_217 ( V_38 , V_539 ) ;
if ( V_30 ) {
F_47 ( L_99 , F_112 ( V_38 ) ) ;
goto V_576;
}
F_218 ( V_38 ) ;
if ( ! F_219 ( V_38 , F_220 ( 64 ) ) ) {
V_574 = 1 ;
V_30 = F_221 ( V_38 , F_220 ( 64 ) ) ;
} else if ( ! ( V_30 = F_219 ( V_38 , F_220 ( 32 ) ) ) ) {
V_574 = 0 ;
V_30 = F_221 ( V_38 , F_220 ( 32 ) ) ;
}
if ( V_30 ) {
F_47 ( L_100 , F_112 ( V_38 ) ) ;
goto V_577;
}
V_17 = F_222 ( sizeof( struct V_1 ) ) ;
if ( ! V_17 ) {
F_47 ( L_101 , F_112 ( V_38 ) ) ;
V_30 = - V_386 ;
goto V_577;
}
F_223 ( V_17 , & V_38 -> V_578 ) ;
F_224 ( V_38 , V_17 ) ;
V_2 = F_108 ( V_17 ) ;
V_2 -> V_73 = V_572 ;
V_2 -> V_17 = V_17 ;
V_2 -> V_38 = V_38 ;
V_2 -> V_210 = V_571 -> V_579 ;
V_2 -> V_200 = V_196 ;
if ( V_547 )
V_2 -> V_547 = 1 ;
V_2 -> V_237 = F_225 ( V_580 , V_581 ) ;
if ( V_574 )
V_17 -> V_582 |= V_583 ;
if ( V_2 -> V_210 == V_211 )
V_17 -> V_582 |= V_584 | V_585 ;
V_2 -> V_7 = F_226 ( V_38 , 1 ) ;
if ( ! V_2 -> V_7 ) {
F_47 ( L_102 , F_112 ( V_38 ) ) ;
V_30 = - V_144 ;
goto V_586;
}
F_227 ( & V_2 -> V_333 ) ;
F_227 ( & V_2 -> V_24 ) ;
V_17 -> V_587 = & V_588 ;
F_228 ( V_17 , & V_589 ) ;
V_17 -> V_590 = 5 * V_208 ;
F_229 ( V_17 , & V_2 -> V_324 , F_143 , 64 ) ;
V_17 -> V_327 = V_38 -> V_327 ;
if ( F_46 ( V_2 ) ) {
F_230 ( L_103 ,
V_76 , V_2 -> V_73 ) ;
V_30 = - V_144 ;
goto V_591;
}
F_189 ( V_2 ) ;
if ( V_2 -> V_15 ) {
V_17 -> V_416 = V_2 -> V_74 . V_170 . V_592 ;
F_44 ( V_17 , V_2 -> V_74 . V_593 . V_594 ) ;
} else {
V_17 -> V_416 = V_2 -> V_74 . V_169 . V_592 ;
F_44 ( V_17 , V_2 -> V_74 . V_595 . V_594 ) ;
}
memcpy ( V_17 -> V_596 , V_17 -> V_70 , V_17 -> V_561 ) ;
V_17 -> V_597 = V_379 ;
F_212 ( V_2 ) ;
if ( V_2 -> V_543 )
F_231 ( V_38 , ( int ) 0x4e , ( V_65 ) 0x0036 ) ;
V_30 = F_232 ( V_17 ) ;
if ( V_30 ) {
F_47 ( L_104 , F_112 ( V_38 ) ) ;
goto V_591;
}
F_148 ( V_17 ) ;
F_147 ( V_17 ) ;
V_2 -> V_337 = F_233 ( V_17 -> V_125 ) ;
F_234 ( & V_2 -> V_338 , F_210 ) ;
F_234 ( & V_2 -> V_562 , F_211 ) ;
F_234 ( & V_2 -> V_203 , F_96 ) ;
F_235 ( & V_2 -> V_206 ) ;
V_2 -> V_206 . V_598 = F_214 ;
V_2 -> V_206 . V_599 = V_207 + V_208 * 2 ;
V_2 -> V_206 . V_39 = ( unsigned long ) V_2 ;
if ( ! V_572 ) {
F_230 ( L_105 , V_600 ) ;
F_230 ( L_106 ,
V_539 , V_601 ) ;
}
F_190 ( V_17 ) ;
V_572 ++ ;
return 0 ;
V_591:
F_236 ( V_2 -> V_7 ) ;
V_586:
F_237 ( V_17 ) ;
V_577:
F_238 ( V_38 ) ;
V_576:
F_239 ( V_38 ) ;
F_224 ( V_38 , NULL ) ;
V_575:
return V_30 ;
}
static void T_10 F_240 ( struct V_538 * V_38 )
{
struct V_67 * V_17 = F_241 ( V_38 ) ;
struct V_1 * V_2 = F_108 ( V_17 ) ;
F_242 ( V_17 ) ;
F_24 ( V_2 ) ;
if ( V_2 -> V_337 ) {
F_243 ( & V_2 -> V_338 ) ;
F_243 ( & V_2 -> V_562 ) ;
F_244 ( V_2 -> V_337 ) ;
V_2 -> V_337 = NULL ;
}
F_236 ( V_2 -> V_7 ) ;
F_238 ( V_38 ) ;
F_224 ( V_38 , NULL ) ;
F_237 ( V_17 ) ;
}
static int T_11 F_245 ( void )
{
return F_246 ( & V_602 ) ;
}
static void T_12 F_247 ( void )
{
F_248 ( & V_602 ) ;
}

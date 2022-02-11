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
L_3 ,
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
F_47 ( L_4 , V_76 ) ;
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
F_9 ( V_2 -> V_17 , L_5 ,
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
F_64 ( V_2 -> V_17 , L_6 ) ;
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
F_64 ( V_2 -> V_17 , L_7 ,
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
F_9 ( V_2 -> V_17 , L_8 ) ;
return V_30 ;
}
V_30 = F_55 ( V_2 , V_141 , & V_138 ) ;
if ( V_30 != 0 ) {
F_9 ( V_2 -> V_17 , L_9 ) ;
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
L_10 ) ;
return V_30 ;
}
V_30 = F_53 ( V_2 , V_141 , & V_138 , V_111 ) ;
if ( V_30 != 0 ) {
F_9 ( V_2 -> V_17 , L_11 ) ;
return V_30 ;
}
V_139 = true ;
}
V_2 -> V_127 = F_65 ( V_2 , V_137 , V_138 ) ;
if ( ( V_2 -> V_127 == V_128 ) && V_139 ) {
F_63 ( V_2 , V_111 ) ;
} else if ( V_2 -> V_127 == V_116 ) {
F_9 ( V_2 -> V_17 , L_12 ) ;
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
F_78 ( V_2 , V_95 , V_2 -> V_17 , L_13 ) ;
return 1 ;
}
F_78 ( V_2 , V_95 , V_2 -> V_17 , L_14 ) ;
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
L_15 ) ;
return 0 ;
}
F_86 ( V_2 , V_95 , V_16 , V_2 -> V_17 , L_16 ) ;
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
F_9 ( V_2 -> V_17 , L_17 ) ;
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
L_18 ) ;
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
L_19 ) ;
F_70 ( V_2 , 1 ) ;
}
V_2 -> V_200 = V_195 ;
F_94 ( V_2 -> V_17 ) ;
F_95 ( V_2 -> V_17 ) ;
F_78 ( V_2 , V_95 , V_2 -> V_17 ,
L_20 ,
F_81 ( V_2 ) ,
F_82 ( V_2 ) ? L_21 : L_22 ) ;
} else {
if ( F_93 ( V_198 , & V_2 -> V_199 ) ) {
F_86 ( V_2 , V_95 , V_16 , V_2 -> V_17 ,
L_23 ) ;
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
L_24 ) ;
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
F_78 ( V_2 , V_95 , V_2 -> V_17 , L_25 ) ;
if ( F_77 ( V_2 ) )
F_92 ( V_2 ) ;
if ( V_2 -> V_200 == V_195 )
F_84 ( V_2 ) ;
V_2 -> V_200 = V_195 ;
}
break;
case V_195 :
if ( V_204 == V_196 ) {
F_78 ( V_2 , V_95 , V_2 -> V_17 , L_26 ) ;
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
F_112 ( V_228 -> V_229 , V_230 , sizeof( V_228 -> V_229 ) ) ;
F_112 ( V_228 -> V_231 , V_232 ,
sizeof( V_228 -> V_231 ) ) ;
F_112 ( V_228 -> V_233 , F_113 ( V_2 -> V_38 ) ,
sizeof( V_228 -> V_233 ) ) ;
V_228 -> V_234 = 0 ;
V_228 -> V_235 = 0 ;
}
static T_1 F_114 ( struct V_67 * V_17 )
{
struct V_1 * V_2 = F_108 ( V_17 ) ;
return V_2 -> V_236 ;
}
static void F_115 ( struct V_67 * V_17 , T_1 V_8 )
{
struct V_1 * V_2 = F_108 ( V_17 ) ;
V_2 -> V_236 = V_8 ;
}
static void F_116 ( struct V_67 * V_17 ,
struct V_237 * V_238 )
{
struct V_1 * V_2 = F_108 ( V_17 ) ;
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
T_1 V_22 ;
if ( V_2 -> V_15 == 0 )
V_22 = F_16 ( V_2 , & V_6 -> V_148 ) ;
else
V_22 = F_16 ( V_2 , & V_6 -> V_147 ) ;
V_238 -> V_225 = F_104 ( V_2 ) ;
V_238 -> V_239 = ( V_22 & V_153 ) >> 2 ;
V_238 -> V_240 = ( V_22 & V_152 ) >> 1 ;
}
static int F_117 ( struct V_1 * V_2 )
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
L_27 ) ;
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
L_3 ,
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
static void F_118 ( struct V_1 * V_2 )
{
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
if ( V_2 -> V_241 >= 16 ) {
while ( V_2 -> V_241 >= 16 ) {
V_2 -> V_242 ++ ;
if ( V_2 -> V_242 ==
V_243 )
V_2 -> V_242 = 0 ;
V_2 -> V_241 -= 8 ;
}
F_119 () ;
F_2 ( V_2 -> V_242 ,
& V_6 -> V_10 . V_244 ) ;
}
}
static void F_120 ( struct V_1 * V_2 )
{
struct V_245 * V_246 ;
int V_12 ;
struct V_27 * V_28 ;
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
if ( ( V_2 -> V_45 >= 8 ) &&
( V_2 -> V_247 >= 16 ) ) {
if ( V_2 -> V_36 )
if ( ! F_117 ( V_2 ) )
return;
V_246 = V_2 -> V_248 ;
while ( ( V_2 -> V_247 >= 16 ) &&
( V_2 -> V_45 >= 8 ) ) {
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ ) {
V_28 =
F_38 ( V_2 ) ;
V_246 -> V_249 =
V_28 -> V_42 ;
V_246 -> V_250 =
V_28 -> V_41 ;
V_246 ++ ;
V_2 -> V_247 -- ;
}
V_2 -> V_251 ++ ;
if ( V_2 -> V_251 ==
V_2 -> V_252 )
V_2 -> V_251 = 0 ;
if ( V_2 -> V_251 ==
( V_2 -> V_252 - 1 ) ) {
V_246 = V_2 -> V_253 ;
}
}
F_119 () ;
V_2 -> V_248 = V_246 ;
F_2 ( V_2 -> V_251 ,
& V_6 -> V_10 . V_254 ) ;
}
}
static void F_121 ( struct V_1 * V_2 ,
struct V_255 * V_256 )
{
struct V_257 * V_258 ;
int V_12 ;
if ( V_256 -> V_199 & V_259 ) {
F_122 ( V_2 -> V_17 ,
L_28 ) ;
}
V_258 = & V_2 -> V_260 [ V_256 -> V_261 ] ;
if ( V_256 -> V_199 & V_259 ) {
F_9 ( V_2 -> V_17 ,
L_29 ) ;
V_2 -> V_17 -> V_262 . V_263 ++ ;
goto V_264;
}
if ( V_258 -> V_265 == 0 ) {
F_9 ( V_2 -> V_17 , L_30 ,
V_256 -> V_261 ) ;
V_2 -> V_17 -> V_262 . V_263 ++ ;
goto V_266;
}
F_123 ( V_2 -> V_38 ,
F_124 ( & V_258 -> V_29 [ 0 ] , V_43 ) ,
F_125 ( & V_258 -> V_29 [ 0 ] , V_44 ) ,
V_267 ) ;
V_258 -> V_265 -- ;
if ( V_258 -> V_265 ) {
for ( V_12 = 1 ; V_12 < V_258 -> V_265 ; V_12 ++ ) {
F_126 ( V_2 -> V_38 ,
F_124 ( & V_258 -> V_29 [ V_12 ] ,
V_43 ) ,
F_125 ( & V_258 -> V_29 [ V_12 ] , V_44 ) ,
V_267 ) ;
}
}
V_2 -> V_17 -> V_262 . V_268 ++ ;
V_2 -> V_17 -> V_262 . V_269 += V_258 -> V_34 -> V_270 ;
V_264:
F_127 ( V_258 -> V_34 ) ;
V_258 -> V_34 = NULL ;
V_266:
F_128 ( & V_2 -> V_271 ) ;
}
static void F_129 ( struct V_1 * V_2 )
{
if ( ++ V_2 -> V_272 == V_273 )
V_2 -> V_272 = 0 ;
V_2 -> V_241 ++ ;
}
static struct V_27 * F_130 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = NULL ;
V_28 = & V_2 -> V_274 [ V_2 -> V_275 ] ;
V_2 -> V_247 ++ ;
if ( ++ V_2 -> V_275 == V_2 -> V_276 )
V_2 -> V_275 = 0 ;
return V_28 ;
}
static void F_131 ( struct V_1 * V_2 ,
struct V_277 * V_278 )
{
struct V_27 * V_279 = NULL ;
struct V_27 * V_280 = NULL ;
struct V_281 * V_34 ;
V_65 V_282 = F_132 ( V_278 -> V_282 ) ;
F_129 ( V_2 ) ;
if ( V_2 -> V_210 == V_283 )
V_279 = F_130 ( V_2 ) ;
V_280 = F_130 ( V_2 ) ;
V_34 = V_280 -> V_34 ;
V_2 -> V_17 -> V_262 . V_284 ++ ;
V_2 -> V_17 -> V_262 . V_285 += V_282 ;
F_133 ( V_34 , V_282 ) ;
F_123 ( V_2 -> V_38 ,
F_124 ( V_280 , V_43 ) ,
F_125 ( V_280 , V_44 ) ,
V_40 ) ;
F_134 ( V_34 -> V_39 ) ;
F_135 ( V_34 ) ;
V_34 -> V_286 = F_136 ( V_34 , V_2 -> V_17 ) ;
F_137 ( V_34 ) ;
V_280 -> V_34 = NULL ;
if ( V_2 -> V_210 == V_283 )
F_26 ( V_2 , V_279 ) ;
F_26 ( V_2 , V_280 ) ;
}
static void F_138 ( struct V_1 * V_2 ,
struct V_287 * V_288 )
{
struct V_27 * V_279 = NULL ;
struct V_27 * V_280 = NULL ;
struct V_281 * V_289 = NULL , * V_290 ;
struct V_67 * V_17 = V_2 -> V_17 ;
V_65 V_282 = F_132 ( V_288 -> V_282 ) ;
V_65 V_291 = 0 ;
F_129 ( V_2 ) ;
if ( V_2 -> V_210 == V_283 ) {
V_279 = F_130 ( V_2 ) ;
V_289 = V_279 -> V_34 ;
V_291 = V_292 ;
if ( * ( ( V_65 * ) V_289 -> V_39 ) != 0xFFFF )
V_291 += V_293 - V_292 ;
}
V_280 = F_130 ( V_2 ) ;
V_290 = V_280 -> V_34 ;
F_133 ( V_290 , V_282 ) ;
F_123 ( V_2 -> V_38 ,
F_124 ( V_280 , V_43 ) ,
F_125 ( V_280 , V_44 ) ,
V_40 ) ;
F_134 ( V_290 -> V_39 ) ;
F_135 ( V_290 ) ;
if ( V_2 -> V_210 == V_283 ) {
F_139 ( V_289 , V_294 ,
F_140 ( V_290 , V_291 ) , V_291 ) ;
} else {
V_65 V_72 = F_132 ( V_288 -> V_72 ) ;
if ( V_72 &
( V_295 |
V_296 ) ) {
F_9 ( V_17 ,
L_31 ,
V_76 ,
( ( V_72 & V_297 ) ?
L_32 : L_33 ) , V_72 ) ;
} else if ( ( V_72 & V_297 ) ||
( V_72 & V_298 &&
! ( V_72 & V_299 ) ) ) {
V_290 -> V_300 = V_301 ;
}
}
V_290 -> V_286 = F_136 ( V_290 , V_2 -> V_17 ) ;
F_137 ( V_290 ) ;
V_17 -> V_262 . V_284 ++ ;
V_17 -> V_262 . V_285 += V_282 ;
V_280 -> V_34 = NULL ;
if ( V_2 -> V_210 == V_283 )
F_26 ( V_2 , V_279 ) ;
F_26 ( V_2 , V_280 ) ;
}
static int F_141 ( struct V_1 * V_2 ,
int * V_302 , int * V_303 , int V_304 )
{
struct V_305 * V_306 ;
struct V_67 * V_17 = V_2 -> V_17 ;
int V_307 = 0 ;
while ( ( F_142 ( * ( V_2 -> V_308 ) ) !=
V_2 -> V_309 ) && ( V_307 < V_304 ) ) {
V_306 = V_2 -> V_310 ;
F_143 () ;
if ( V_2 -> V_210 == V_211 )
V_306 -> V_311 &= 0x7f ;
switch ( V_306 -> V_311 ) {
case V_312 :
case V_313 :
F_121 ( V_2 , (struct V_255 * )
V_306 ) ;
( * V_302 ) ++ ;
break;
case V_314 :
case V_315 :
F_131 ( V_2 , (struct V_277 * )
V_306 ) ;
( * V_303 ) ++ ;
break;
case V_316 :
case V_317 :
F_138 ( V_2 , (struct V_287 * )
V_306 ) ;
( * V_303 ) ++ ;
break;
default: {
T_1 * V_318 = ( T_1 * ) V_306 ;
F_9 ( V_17 ,
L_34
L_35
L_36 ,
V_306 -> V_311 ,
( unsigned long int ) V_318 [ 0 ] ,
( unsigned long int ) V_318 [ 1 ] ,
( unsigned long int ) V_318 [ 2 ] ,
( unsigned long int ) V_318 [ 3 ] ) ;
}
}
V_2 -> V_309 ++ ;
if ( V_2 -> V_309 == V_319 ) {
V_2 -> V_309 = 0 ;
V_2 -> V_310 = V_2 -> V_320 ;
} else {
V_2 -> V_310 ++ ;
}
V_307 = * V_302 + * V_303 ;
}
return V_307 ;
}
static int F_144 ( struct V_321 * V_322 , int V_323 )
{
struct V_1 * V_2 = F_97 ( V_322 , struct V_1 , V_322 ) ;
int V_303 = 0 , V_302 = 0 ;
unsigned long V_23 ;
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
F_141 ( V_2 , & V_302 , & V_303 , V_323 ) ;
if ( V_302 + V_303 != V_323 ) {
F_12 ( & V_2 -> V_24 , V_23 ) ;
F_145 ( V_322 ) ;
F_118 ( V_2 ) ;
F_120 ( V_2 ) ;
F_2 ( V_2 -> V_309 ,
& V_6 -> V_10 . V_324 ) ;
F_13 ( & V_2 -> V_24 , V_23 ) ;
F_25 ( V_2 ) ;
}
return V_302 + V_303 ;
}
static T_6 F_146 ( int V_325 , void * V_326 )
{
struct V_67 * V_17 = V_326 ;
struct V_1 * V_2 = F_108 ( V_17 ) ;
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
T_1 V_8 ;
int V_327 = 1 ;
T_1 V_328 ;
V_8 = F_11 ( V_2 ,
& V_6 -> V_10 . V_20 ) ;
if ( V_8 & ( V_329 | V_330 ) ) {
F_147 ( & V_2 -> V_331 ) ;
F_148 ( V_2 -> V_17 ) ;
F_149 ( V_2 -> V_17 ) ;
F_24 ( V_2 ) ;
V_2 -> V_200 = V_196 ;
F_100 ( V_205 , & V_2 -> V_199 ) ;
if ( V_8 & V_329 ) {
V_328 =
F_15 ( V_2 ,
& V_6 -> V_332 ) ;
F_122 ( V_17 ,
L_37 ,
V_328 ) ;
F_100 ( V_333 , & V_2 -> V_199 ) ;
} else {
F_100 ( V_334 , & V_2 -> V_199 ) ;
F_9 ( V_17 ,
L_38 ,
V_8 ) ;
}
F_150 ( V_2 -> V_335 , & V_2 -> V_336 , 0 ) ;
F_151 ( & V_2 -> V_331 ) ;
} else if ( V_8 & V_337 ) {
F_24 ( V_2 ) ;
if ( F_152 ( F_153 ( & V_2 -> V_322 ) ) )
F_154 ( & V_2 -> V_322 ) ;
} else
return V_338 ;
return F_155 ( V_327 ) ;
}
static int F_156 ( struct V_1 * V_2 , unsigned short V_339 )
{
if ( V_2 -> V_210 == V_283 )
return 1 ;
if ( V_339 <= 2 )
return V_339 + 1 ;
else if ( V_339 <= 6 )
return V_339 + 2 ;
else if ( V_339 <= 10 )
return V_339 + 3 ;
else if ( V_339 <= 14 )
return V_339 + 4 ;
else if ( V_339 <= 18 )
return V_339 + 5 ;
return - 1 ;
}
static void F_157 ( const struct V_281 * V_34 ,
struct V_340 * V_341 )
{
const struct V_342 * V_343 = F_158 ( V_34 ) ;
V_341 -> V_344 = F_159 ( V_34 ) ;
V_341 -> V_345 = V_343 -> V_346 ;
if ( V_343 -> V_286 == V_347 ) {
V_341 -> V_348 |= V_349 |
V_350 ;
} else {
V_341 -> V_348 |= V_351 |
V_350 ;
}
}
static int F_160 ( struct V_1 * V_2 ,
struct V_340 * V_341 ,
struct V_257 * V_258 ,
struct V_281 * V_34 )
{
struct V_352 * V_352 ;
struct V_353 * V_353 ;
int V_270 = F_161 ( V_34 ) ;
T_3 V_29 ;
int V_30 ;
int V_354 , V_12 ;
int V_355 , V_356 = 0 ;
int V_357 = ( int ) F_162 ( V_34 ) -> V_358 ;
V_355 = V_258 -> V_265 ;
V_29 = F_30 ( V_2 -> V_38 , V_34 -> V_39 , V_270 , V_267 ) ;
V_30 = F_31 ( V_2 -> V_38 , V_29 ) ;
if ( V_30 ) {
F_9 ( V_2 -> V_17 , L_3 ,
V_30 ) ;
return V_359 ;
}
V_353 = (struct V_353 * ) & V_341 -> V_360 ;
V_353 -> V_361 = F_33 ( F_34 ( V_29 ) ) ;
V_353 -> V_362 = F_33 ( F_35 ( V_29 ) ) ;
V_353 -> V_270 = F_33 ( V_270 ) ;
F_36 ( & V_258 -> V_29 [ V_356 ] , V_43 , V_29 ) ;
F_37 ( & V_258 -> V_29 [ V_356 ] , V_44 , V_270 ) ;
V_356 ++ ;
if ( V_355 == 1 ) {
V_353 -> V_270 |= F_33 ( V_363 ) ;
return V_364 ;
}
V_352 = V_258 -> V_352 ;
for ( V_354 = 0 ;
V_354 < V_357 ;
V_354 ++ , V_356 ++ ) {
T_7 * V_365 = & F_162 ( V_34 ) -> V_339 [ V_354 ] ;
V_353 ++ ;
if ( ( V_356 == 2 && V_355 > 3 ) ||
( V_356 == 7 && V_355 > 8 ) ||
( V_356 == 12 && V_355 > 13 ) ||
( V_356 == 17 && V_355 > 18 ) ) {
V_29 = F_30 ( V_2 -> V_38 , V_352 ,
sizeof( struct V_352 ) ,
V_267 ) ;
V_30 = F_31 ( V_2 -> V_38 , V_29 ) ;
if ( V_30 ) {
F_9 ( V_2 -> V_17 ,
L_39 ,
V_30 ) ;
goto V_366;
}
V_353 -> V_361 = F_33 ( F_34 ( V_29 ) ) ;
V_353 -> V_362 = F_33 ( F_35 ( V_29 ) ) ;
V_353 -> V_270 = F_33 ( sizeof( struct V_352 ) |
V_367 ) ;
F_36 ( & V_258 -> V_29 [ V_356 ] , V_43 , V_29 ) ;
F_37 ( & V_258 -> V_29 [ V_356 ] , V_44 ,
sizeof( struct V_352 ) ) ;
V_353 = (struct V_353 * ) V_352 ;
V_352 ++ ;
V_356 ++ ;
}
V_29 = F_163 ( & V_2 -> V_38 -> V_368 , V_365 , 0 , F_164 ( V_365 ) ,
V_369 ) ;
V_30 = F_165 ( & V_2 -> V_38 -> V_368 , V_29 ) ;
if ( V_30 ) {
F_9 ( V_2 -> V_17 ,
L_40 ,
V_30 ) ;
goto V_366;
}
V_353 -> V_361 = F_33 ( F_34 ( V_29 ) ) ;
V_353 -> V_362 = F_33 ( F_35 ( V_29 ) ) ;
V_353 -> V_270 = F_33 ( F_164 ( V_365 ) ) ;
F_36 ( & V_258 -> V_29 [ V_356 ] , V_43 , V_29 ) ;
F_37 ( & V_258 -> V_29 [ V_356 ] , V_44 , F_164 ( V_365 ) ) ;
}
V_353 -> V_270 |= F_33 ( V_363 ) ;
return V_364 ;
V_366:
V_356 = 1 ;
V_353 = (struct V_353 * ) & V_341 -> V_360 ;
V_352 = V_258 -> V_352 ;
for ( V_12 = 0 ; V_12 < V_354 ; V_12 ++ , V_356 ++ ) {
V_353 ++ ;
if ( ( V_356 == 2 && V_355 > 3 ) ||
( V_356 == 7 && V_355 > 8 ) ||
( V_356 == 12 && V_355 > 13 ) ||
( V_356 == 17 && V_355 > 18 ) ) {
F_123 ( V_2 -> V_38 ,
F_124 ( & V_258 -> V_29 [ V_356 ] , V_43 ) ,
F_125 ( & V_258 -> V_29 [ V_356 ] , V_44 ) ,
V_267 ) ;
V_352 ++ ;
V_356 ++ ;
}
F_126 ( V_2 -> V_38 ,
F_124 ( & V_258 -> V_29 [ V_356 ] , V_43 ) ,
F_125 ( & V_258 -> V_29 [ V_356 ] , V_44 ) ,
V_267 ) ;
}
F_123 ( V_2 -> V_38 ,
F_124 ( & V_258 -> V_29 [ 0 ] , V_43 ) ,
F_124 ( & V_258 -> V_29 [ 0 ] , V_44 ) ,
V_267 ) ;
return V_359 ;
}
static T_8 F_166 ( struct V_281 * V_34 ,
struct V_67 * V_17 )
{
struct V_1 * V_2 = F_108 ( V_17 ) ;
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
struct V_257 * V_258 ;
T_1 V_370 = V_34 -> V_270 ;
struct V_340 * V_341 ;
if ( F_28 ( F_167 ( & V_2 -> V_271 ) < 2 ) )
return V_359 ;
V_258 = & V_2 -> V_260 [ V_2 -> V_371 ] ;
V_258 -> V_265 = F_156 ( V_2 ,
F_162 ( V_34 ) -> V_358 ) ;
if ( V_258 -> V_265 == - 1 ) {
F_9 ( V_17 , L_41 , V_76 ) ;
return V_364 ;
}
V_341 = V_258 -> V_372 ;
memset ( ( void * ) V_341 , 0 , sizeof( struct V_340 ) ) ;
V_341 -> V_311 = V_2 -> V_373 ;
V_341 -> V_199 = V_374 ;
V_341 -> V_199 |= V_2 -> V_375 ;
V_341 -> V_261 = V_2 -> V_371 ;
V_341 -> V_376 = F_45 ( ( V_65 ) V_370 ) ;
V_258 -> V_34 = V_34 ;
if ( V_2 -> V_210 == V_211 &&
V_34 -> V_300 == V_377 )
F_157 ( V_34 , V_341 ) ;
if ( F_160 ( V_2 , V_341 , V_258 , V_34 ) != V_364 ) {
F_9 ( V_17 , L_42 , V_76 ) ;
return V_359 ;
}
F_119 () ;
V_2 -> V_371 ++ ;
if ( V_2 -> V_371 == V_378 )
V_2 -> V_371 = 0 ;
F_119 () ;
F_17 ( V_2 ,
& V_6 -> V_10 . V_379 ,
V_2 -> V_371 ) ;
F_86 ( V_2 , V_380 , V_16 , V_17 ,
L_43 ,
V_2 -> V_371 , V_34 -> V_270 ) ;
F_168 ( & V_2 -> V_271 ) ;
return V_364 ;
}
static int F_169 ( struct V_1 * V_2 )
{
V_2 -> V_381 =
( T_1 ) ( V_378 * sizeof( struct V_340 ) ) ;
V_2 -> V_382 = V_319 * sizeof( struct V_305 ) ;
F_119 () ;
V_2 -> V_383 =
F_170 ( V_2 -> V_38 ,
( V_384 ) V_2 -> V_381 ,
& V_2 -> V_385 ) ;
if ( ( V_2 -> V_383 == NULL ) ||
F_34 ( V_2 -> V_385 ) & ( V_2 -> V_381 - 1 ) ) {
F_9 ( V_2 -> V_17 , L_44 ) ;
return - V_386 ;
}
V_2 -> V_320 =
F_170 ( V_2 -> V_38 ,
( V_384 ) V_2 -> V_382 ,
& V_2 -> V_387 ) ;
if ( ( V_2 -> V_320 == NULL ) ||
F_34 ( V_2 -> V_387 ) & ( V_2 -> V_382 - 1 ) ) {
F_9 ( V_2 -> V_17 , L_45 ) ;
F_171 ( V_2 -> V_38 , ( V_384 ) V_2 -> V_381 ,
V_2 -> V_383 ,
V_2 -> V_385 ) ;
return - V_386 ;
}
F_100 ( V_388 , & V_2 -> V_199 ) ;
return 0 ;
}
static void F_172 ( struct V_1 * V_2 )
{
if ( ! F_93 ( V_388 , & V_2 -> V_199 ) ) {
F_64 ( V_2 -> V_17 , L_46 ) ;
return;
}
F_171 ( V_2 -> V_38 ,
V_2 -> V_381 ,
V_2 -> V_383 , V_2 -> V_385 ) ;
V_2 -> V_383 = NULL ;
F_171 ( V_2 -> V_38 ,
V_2 -> V_382 ,
V_2 -> V_320 , V_2 -> V_387 ) ;
V_2 -> V_320 = NULL ;
F_101 ( V_388 , & V_2 -> V_199 ) ;
}
static int F_173 ( struct V_1 * V_2 )
{
V_2 -> V_389 =
V_2 -> V_252 * sizeof( struct V_390 ) ;
if ( V_2 -> V_389 < V_391 )
V_2 -> V_392 = V_391 ;
else
V_2 -> V_392 = V_2 -> V_389 * 2 ;
V_2 -> V_274 = F_174 ( V_2 -> V_276 ,
sizeof( struct V_27 ) ,
V_393 ) ;
if ( V_2 -> V_274 == NULL )
return - V_386 ;
V_2 -> V_394 =
F_170 ( V_2 -> V_38 ,
V_2 -> V_392 ,
& V_2 -> V_395 ) ;
if ( V_2 -> V_394 == NULL ) {
F_9 ( V_2 -> V_17 , L_47 ) ;
return - V_386 ;
}
V_2 -> V_253 = V_2 -> V_394 ;
V_2 -> V_396 = V_2 -> V_395 ;
V_2 -> V_397 =
V_243 * sizeof( struct V_390 ) ;
if ( V_2 -> V_397 < V_391 )
V_2 -> V_398 = V_391 ;
else
V_2 -> V_398 = V_2 -> V_397 * 2 ;
V_2 -> V_399 =
F_170 ( V_2 -> V_38 ,
V_2 -> V_398 ,
& V_2 -> V_400 ) ;
if ( V_2 -> V_399 == NULL ) {
F_9 ( V_2 -> V_17 , L_48 ) ;
F_171 ( V_2 -> V_38 , V_2 -> V_392 ,
V_2 -> V_394 ,
V_2 -> V_395 ) ;
return - V_386 ;
}
V_2 -> V_401 = V_2 -> V_399 ;
V_2 -> V_402 = V_2 -> V_400 ;
F_100 ( V_403 , & V_2 -> V_199 ) ;
return 0 ;
}
static void F_175 ( struct V_1 * V_2 )
{
if ( ! F_93 ( V_403 , & V_2 -> V_199 ) ) {
F_64 ( V_2 -> V_17 , L_46 ) ;
return;
}
F_176 ( V_2 -> V_274 ) ;
F_171 ( V_2 -> V_38 ,
V_2 -> V_392 ,
V_2 -> V_394 ,
V_2 -> V_395 ) ;
V_2 -> V_253 = NULL ;
F_171 ( V_2 -> V_38 ,
V_2 -> V_398 ,
V_2 -> V_399 ,
V_2 -> V_400 ) ;
V_2 -> V_401 = NULL ;
F_101 ( V_403 , & V_2 -> V_199 ) ;
}
static int F_177 ( struct V_1 * V_2 )
{
int V_12 ;
struct V_245 * V_404 ;
V_2 -> V_405 =
( V_406 * V_243 *
V_407 ) ;
V_2 -> V_408 =
F_170 ( V_2 -> V_38 ,
V_2 -> V_405 ,
& V_2 -> V_409 ) ;
if ( V_2 -> V_408 == NULL ) {
F_9 ( V_2 -> V_17 , L_49 ) ;
return - V_386 ;
}
V_2 -> V_410 = F_34 ( V_2 -> V_409 ) ;
V_2 -> V_411 = F_35 ( V_2 -> V_409 ) ;
V_404 = V_2 -> V_401 ;
for ( V_12 = 0 ; V_12 < ( V_406 * V_243 ) ; V_12 ++ ) {
V_404 -> V_249 =
F_33 ( V_2 -> V_411 ) ;
V_404 -> V_250 =
F_33 ( V_2 -> V_410 +
( V_12 * V_407 ) ) ;
V_404 ++ ;
}
V_2 -> V_272 = 0 ;
F_100 ( V_412 , & V_2 -> V_199 ) ;
return 0 ;
}
static void F_178 ( struct V_1 * V_2 )
{
if ( ! F_93 ( V_412 , & V_2 -> V_199 ) ) {
F_64 ( V_2 -> V_17 , L_46 ) ;
return;
}
if ( V_2 -> V_408 != NULL ) {
F_171 ( V_2 -> V_38 ,
V_2 -> V_405 ,
V_2 -> V_408 ,
V_2 -> V_409 ) ;
V_2 -> V_408 = NULL ;
}
}
static void F_179 ( struct V_1 * V_2 )
{
int V_12 = 0 ;
struct V_27 * V_28 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_276 ; V_12 ++ ) {
V_28 = & V_2 -> V_274 [ V_12 ] ;
if ( V_28 -> V_34 ) {
F_32 ( V_28 -> V_34 ) ;
F_123 ( V_2 -> V_38 ,
F_124 ( V_28 , V_43 ) ,
F_125 ( V_28 , V_44 ) ,
V_40 ) ;
memset ( V_28 , 0 , sizeof( struct V_27 ) ) ;
} else {
break;
}
}
}
static void F_180 ( struct V_1 * V_2 )
{
int V_12 ;
struct V_27 * V_28 ;
struct V_245 * V_413 = V_2 -> V_253 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_276 ; V_12 ++ ) {
V_28 = & V_2 -> V_274 [ V_12 ] ;
V_413 -> V_249 = V_28 -> V_42 ;
V_413 -> V_250 = V_28 -> V_41 ;
V_413 ++ ;
}
V_2 -> V_275 = 0 ;
V_2 -> V_36 = 0 ;
}
static int F_181 ( struct V_1 * V_2 )
{
int V_12 ;
struct V_27 * V_28 ;
struct V_281 * V_34 ;
T_3 V_29 ;
int V_30 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_276 ; V_12 ++ ) {
V_34 = F_27 ( V_2 -> V_17 ,
V_2 -> V_35 ) ;
if ( F_28 ( ! V_34 ) ) {
F_9 ( V_2 -> V_17 ,
L_50 ,
V_2 -> V_35 * 2 , V_12 ) ;
F_179 ( V_2 ) ;
return - V_386 ;
} else {
V_28 = & V_2 -> V_274 [ V_12 ] ;
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
L_3 ,
V_30 ) ;
F_179 ( V_2 ) ;
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
static void F_182 ( struct V_1 * V_2 )
{
struct V_257 * V_258 ;
int V_12 ;
V_258 = & V_2 -> V_260 [ 0 ] ;
for ( V_12 = 0 ; V_12 < V_378 ; V_12 ++ ) {
F_176 ( V_258 -> V_352 ) ;
V_258 -> V_352 = NULL ;
V_258 ++ ;
}
}
static int F_183 ( struct V_1 * V_2 )
{
struct V_257 * V_258 ;
int V_12 ;
struct V_340 * V_414 = V_2 -> V_383 ;
for ( V_12 = 0 ; V_12 < V_378 ; V_12 ++ ) {
V_258 = & V_2 -> V_260 [ V_12 ] ;
V_258 -> V_34 = NULL ;
V_258 -> V_372 = V_414 ;
V_414 ++ ;
V_258 -> V_352 = F_184 ( 512 , V_393 ) ;
if ( V_258 -> V_352 == NULL )
return - V_386 ;
}
return 0 ;
}
static int F_185 ( struct V_1 * V_2 )
{
if ( V_2 -> V_17 -> V_415 == V_416 ) {
V_2 -> V_252 = V_417 ;
V_2 -> V_35 = V_416 ;
} else if ( V_2 -> V_17 -> V_415 == V_418 ) {
V_2 -> V_252 = V_419 ;
V_2 -> V_35 = V_418 ;
} else {
F_9 ( V_2 -> V_17 , L_51 ,
V_2 -> V_17 -> V_415 , V_416 , V_418 ) ;
return - V_386 ;
}
V_2 -> V_276 =
V_2 -> V_252 * V_406 ;
V_2 -> V_35 += V_293 + V_294 + V_37 ;
V_2 -> V_420 =
( V_2 -> V_35 - V_37 ) + V_421 ;
V_2 -> V_422 =
F_170 ( V_2 -> V_38 ,
V_391 , & V_2 -> V_423 ) ;
if ( V_2 -> V_422 != NULL ) {
V_2 -> V_424 = V_2 -> V_422 ;
V_2 -> V_425 =
F_35 ( V_2 -> V_423 ) ;
V_2 -> V_426 =
F_34 ( V_2 -> V_423 ) ;
V_2 -> V_308 =
( V_427 * ) ( ( ( T_5 * ) V_2 -> V_424 ) + 8 ) ;
V_2 -> V_428 =
V_2 -> V_425 ;
V_2 -> V_429 =
V_2 -> V_426 + 8 ;
} else {
F_9 ( V_2 -> V_17 , L_52 ) ;
return - V_386 ;
}
if ( F_169 ( V_2 ) != 0 ) {
F_9 ( V_2 -> V_17 , L_53 ) ;
goto V_430;
}
if ( F_173 ( V_2 ) != 0 ) {
F_9 ( V_2 -> V_17 , L_54 ) ;
goto V_431;
}
if ( F_177 ( V_2 ) != 0 ) {
F_9 ( V_2 -> V_17 , L_55 ) ;
goto V_432;
}
if ( F_181 ( V_2 ) != 0 ) {
F_9 ( V_2 -> V_17 , L_56 ) ;
goto V_432;
}
F_180 ( V_2 ) ;
if ( F_183 ( V_2 ) )
goto V_433;
V_2 -> V_310 = V_2 -> V_320 ;
return 0 ;
V_433:
F_182 ( V_2 ) ;
V_432:
F_175 ( V_2 ) ;
V_431:
F_172 ( V_2 ) ;
V_430:
F_171 ( V_2 -> V_38 ,
V_391 ,
V_2 -> V_422 ,
V_2 -> V_423 ) ;
return - V_386 ;
}
static void F_186 ( struct V_1 * V_2 )
{
F_182 ( V_2 ) ;
F_179 ( V_2 ) ;
F_178 ( V_2 ) ;
F_175 ( V_2 ) ;
F_172 ( V_2 ) ;
if ( V_2 -> V_422 != NULL ) {
F_171 ( V_2 -> V_38 ,
V_391 ,
V_2 -> V_422 ,
V_2 -> V_423 ) ;
V_2 -> V_422 = NULL ;
}
}
static int F_187 ( struct V_1 * V_2 )
{
struct V_434 T_2 * V_435 =
( void T_2 * ) V_2 -> V_7 ;
if ( F_1 ( V_2 , V_436 ,
( V_14 | ( V_2 -> V_15 ) *
2 ) << 4 ) )
return - 1 ;
F_23 ( V_2 ,
& V_435 -> V_437 , V_2 -> V_74 . V_437 ) ;
F_23 ( V_2 ,
& V_435 -> V_438 ,
V_2 -> V_74 . V_439 ) ;
F_23 ( V_2 ,
& V_435 -> V_440 ,
( V_2 -> V_74 . V_441 << 16 ) |
( V_2 -> V_74 . V_442 ) ) ;
F_23 ( V_2 ,
& V_435 -> V_443 ,
V_2 -> V_74 . V_444 ) ;
F_23 ( V_2 ,
& V_435 -> V_445 ,
( V_2 -> V_74 . V_446 << 16 ) |
V_2 -> V_74 . V_447 ) ;
F_23 ( V_2 ,
& V_435 -> V_448 ,
V_2 -> V_74 . V_449 ) ;
F_23 ( V_2 ,
& V_435 -> V_450 ,
( V_2 -> V_74 . V_451 << 16 ) |
V_2 -> V_74 . V_452 ) ;
F_23 ( V_2 ,
& V_435 -> V_453 ,
V_2 -> V_74 . V_454 ) ;
F_23 ( V_2 ,
& V_435 -> V_455 ,
( V_2 -> V_74 . V_456 << 16 ) |
V_2 -> V_74 . V_457 ) ;
F_23 ( V_2 ,
& V_435 -> V_458 ,
V_2 -> V_74 . V_459 ) ;
F_23 ( V_2 ,
& V_435 -> V_460 ,
( V_2 -> V_74 . V_461 << 16 ) |
V_2 -> V_74 . V_462 ) ;
F_23 ( V_2 ,
& V_435 -> V_463 ,
V_2 -> V_74 . V_464 ) ;
F_5 ( V_2 , V_436 ) ;
return 0 ;
}
static int F_188 ( struct V_1 * V_2 )
{
T_1 V_8 ;
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
T_2 T_1 * V_46 = & V_6 -> V_10 . V_47 ;
struct V_465 T_2 * V_466 =
( void T_2 * ) V_6 ;
T_1 V_467 = 10 ;
int V_214 = 0 ;
if ( F_103 ( V_2 ) )
return - 1 ;
F_18 ( V_2 , V_46 ,
( V_468 |
( V_468 << 16 ) ) ) ;
F_189 ( 100 ) ;
V_2 -> V_200 = V_196 ;
F_149 ( V_2 -> V_17 ) ;
F_18 ( V_2 , V_46 ,
( V_469 |
( V_469 << 16 ) ) ) ;
* ( ( T_1 * ) ( V_2 -> V_424 ) ) = 0 ;
F_190 ( & V_2 -> V_271 , V_378 ) ;
V_2 -> V_371 = 0 ;
F_22 ( V_2 ,
& V_466 -> V_470 ,
V_2 -> V_425 ) ;
F_22 ( V_2 ,
& V_466 -> V_471 ,
V_2 -> V_426 ) ;
F_22 ( V_2 ,
& V_466 -> V_472 ,
F_35 ( V_2 -> V_385 ) ) ;
F_22 ( V_2 ,
& V_466 -> V_473 ,
F_34 ( V_2 -> V_385 ) ) ;
F_22 ( V_2 , & V_466 -> V_474 , V_378 ) ;
* ( ( T_4 * ) ( V_2 -> V_308 ) ) = 0 ;
V_2 -> V_309 = 0 ;
V_2 -> V_310 = V_2 -> V_320 ;
F_22 ( V_2 ,
& V_466 -> V_475 ,
V_2 -> V_428 ) ;
F_22 ( V_2 ,
& V_466 -> V_476 ,
V_2 -> V_429 ) ;
F_22 ( V_2 ,
& V_466 -> V_477 ,
F_35 ( V_2 -> V_387 ) ) ;
F_22 ( V_2 ,
& V_466 -> V_478 ,
F_34 ( V_2 -> V_387 ) ) ;
F_22 ( V_2 , & V_466 -> V_479 , V_319 ) ;
F_22 ( V_2 ,
& V_466 -> V_480 ,
F_35 ( V_2 -> V_396 ) ) ;
F_22 ( V_2 ,
& V_466 -> V_481 ,
F_34 ( V_2 -> V_396 ) ) ;
F_22 ( V_2 ,
& V_466 -> V_482 ,
V_2 -> V_252 ) ;
F_22 ( V_2 ,
& V_466 -> V_483 ,
V_2 -> V_35 ) ;
F_22 ( V_2 ,
& V_466 -> V_484 ,
F_35 ( V_2 -> V_402 ) ) ;
F_22 ( V_2 ,
& V_466 -> V_485 ,
F_34 ( V_2 -> V_402 ) ) ;
F_22 ( V_2 , & V_466 -> V_486 , V_243 ) ;
F_22 ( V_2 ,
& V_466 -> V_487 ,
V_407 ) ;
V_2 -> V_242 = V_243 - 1 ;
V_2 -> V_241 = 8 ;
V_2 -> V_251 = V_2 -> V_252 - 1 ;
V_2 -> V_247 = 8 ;
V_2 -> V_248 = V_2 -> V_253 ;
V_2 -> V_272 = 0 ;
V_2 -> V_275 = 0 ;
V_2 -> V_45 = 0 ;
V_2 -> V_33 = NULL ;
V_2 -> V_32 = NULL ;
F_18 ( V_2 ,
& V_6 -> V_10 .
V_244 ,
V_2 -> V_242 ) ;
F_18 ( V_2 ,
& V_6 -> V_10 .
V_254 ,
V_2 -> V_251 ) ;
F_101 ( V_198 , & V_2 -> V_199 ) ;
V_8 = F_16 ( V_2 , & V_6 -> V_157 ) ;
if ( ( V_8 & V_488 ) == 0 ) {
if ( F_187 ( V_2 ) ) {
V_214 = - 1 ;
goto V_489;
}
V_8 = V_2 -> V_74 . V_490 ;
F_21 ( V_2 , & V_6 -> V_491 , V_8 ) ;
V_8 = ( 0xFFFF << 16 ) | V_2 -> V_74 . V_492 ;
if ( F_1 ( V_2 , V_493 ,
( V_14 | ( V_2 -> V_15 )
* 2 ) << 13 ) ) {
V_214 = - 1 ;
goto V_489;
}
F_21 ( V_2 , & V_6 -> V_494 , V_8 ) ;
F_21 ( V_2 , & V_6 -> V_495 ,
( ( ( V_496 | V_497 ) <<
16 ) | ( V_496 |
V_497 ) ) ) ;
F_5 ( V_2 , V_493 ) ;
}
if ( V_2 -> V_15 )
F_21 ( V_2 ,
& V_6 -> V_498 ,
V_2 -> V_420 ) ;
else
F_21 ( V_2 ,
& V_6 -> V_499 ,
V_2 -> V_420 ) ;
if ( F_1 ( V_2 , V_197 ,
( V_14 | ( V_2 -> V_15 ) *
2 ) << 7 ) ) {
V_214 = - 1 ;
goto V_489;
}
F_69 ( V_2 ) ;
F_102 ( V_2 ) ;
F_99 ( V_2 ) ;
F_21 ( V_2 , & V_6 -> V_500 ,
( V_501 << 16 ) ) ;
F_21 ( V_2 , & V_6 -> V_502 ,
( ( V_2 -> V_17 -> V_70 [ 2 ] << 24 )
| ( V_2 -> V_17 -> V_70 [ 3 ] << 16 )
| ( V_2 -> V_17 -> V_70 [ 4 ] << 8 )
| V_2 -> V_17 -> V_70 [ 5 ] ) ) ;
F_21 ( V_2 , & V_6 -> V_500 ,
( ( V_501 << 16 ) | 1 ) ) ;
F_21 ( V_2 , & V_6 -> V_502 ,
( ( V_2 -> V_17 -> V_70 [ 0 ] << 8 )
| V_2 -> V_17 -> V_70 [ 1 ] ) ) ;
F_21 ( V_2 , & V_6 -> V_500 ,
( ( V_503 << 16 ) |
V_503 ) ) ;
F_21 ( V_2 , & V_6 -> V_504 ,
( ( V_505 << 16 ) |
( V_2 -> V_15 << 2 ) ) ) ;
F_21 ( V_2 , & V_6 -> V_506 , 0 ) ;
F_21 ( V_2 , & V_6 -> V_504 ,
( ( V_505 << 16 ) |
( ( V_2 -> V_15 << 2 ) + 1 ) ) ) ;
F_21 ( V_2 , & V_6 -> V_506 , 0 ) ;
F_5 ( V_2 , V_197 ) ;
F_21 ( V_2 ,
& V_6 -> V_507 ,
( ( V_508 << 16 ) | V_508 ) ) ;
do {
V_8 = F_16 ( V_2 , & V_6 -> V_157 ) ;
if ( V_8 & V_488 )
break;
F_191 ( & V_2 -> V_24 ) ;
F_192 ( 500 ) ;
F_193 ( & V_2 -> V_24 ) ;
} while ( -- V_467 );
if ( V_467 == 0 ) {
F_9 ( V_2 -> V_17 , L_57 ) ;
V_214 = - 1 ;
goto V_489;
}
if ( V_2 -> V_210 == V_211 ) {
V_8 =
( V_509 | V_510 |
V_511 | V_512 |
V_513 ) ;
F_21 ( V_2 , & V_6 -> V_514 ,
( ( V_8 << 16 ) | V_8 ) ) ;
} else {
V_8 =
( V_515 | V_516 | V_517 |
V_518 ) ;
F_21 ( V_2 , & V_6 -> V_507 ,
( ( V_8 << 16 ) | V_8 ) ) ;
}
V_489:
return V_214 ;
}
static int F_194 ( struct V_1 * V_2 )
{
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
int V_214 = 0 ;
V_65 V_8 ;
int V_519 ;
F_100 ( V_205 , & V_2 -> V_199 ) ;
F_101 ( V_520 , & V_2 -> V_199 ) ;
F_8 ( V_16 , V_2 -> V_17 , L_58 ) ;
F_18 ( V_2 ,
& V_6 -> V_10 . V_20 ,
( ( V_521 << 16 ) | V_521 ) ) ;
F_8 ( V_16 , V_2 -> V_17 ,
L_59 ) ;
V_519 = 5 ;
do {
V_8 =
F_14 ( V_2 ,
& V_6 -> V_10 . V_20 ) ;
if ( ( V_8 & V_521 ) == 0 )
break;
F_4 ( 1 ) ;
} while ( ( -- V_519 ) );
V_8 =
F_14 ( V_2 , & V_6 -> V_10 . V_20 ) ;
if ( V_8 & V_330 ) {
F_8 ( V_16 , V_2 -> V_17 ,
L_60 ) ;
F_18 ( V_2 ,
& V_6 -> V_10 .
V_20 ,
( ( V_330 << 16 ) | V_330 ) ) ;
}
if ( V_519 == 0 ) {
F_18 ( V_2 ,
& V_6 -> V_10 .
V_20 ,
( ( V_522 << 16 ) |
V_522 ) ) ;
V_519 = 5 ;
do {
V_8 = F_14 ( V_2 ,
& V_6 -> V_10 .
V_20 ) ;
if ( ( V_8 & V_522 ) == 0 )
break;
F_4 ( 1 ) ;
} while ( ( -- V_519 ) );
}
if ( V_519 == 0 )
V_214 = 1 ;
F_101 ( V_205 , & V_2 -> V_199 ) ;
F_100 ( V_520 , & V_2 -> V_199 ) ;
return V_214 ;
}
static void F_195 ( struct V_1 * V_2 )
{
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
T_1 V_8 , V_523 ;
T_5 V_524 ;
V_8 =
F_11 ( V_2 , & V_6 -> V_10 . V_20 ) ;
V_524 = ( T_5 ) ( ( V_8 >> 4 ) & V_525 ) ;
V_523 = F_16 ( V_2 , & V_6 -> V_157 ) ;
switch ( V_8 & V_526 ) {
case V_527 :
V_2 -> V_15 = 0 ;
V_2 -> V_373 = V_528 | V_524 ;
V_2 -> V_375 = V_529 ;
V_2 -> V_87 = V_530 ;
if ( V_523 & V_155 )
F_100 ( V_209 , & V_2 -> V_199 ) ;
else
F_101 ( V_209 , & V_2 -> V_199 ) ;
break;
case V_531 :
V_2 -> V_15 = 1 ;
V_2 -> V_373 = V_528 | V_524 ;
V_2 -> V_375 = V_532 ;
V_2 -> V_87 = V_533 ;
if ( V_523 & V_156 )
F_100 ( V_209 , & V_2 -> V_199 ) ;
else
F_101 ( V_209 , & V_2 -> V_199 ) ;
break;
case V_534 :
case V_535 :
default:
F_8 ( V_16 , V_2 -> V_17 ,
L_61 ,
V_8 ) ;
break;
}
V_2 -> V_83 = V_2 -> V_74 . V_536 >> 8 ;
}
static void F_196 ( struct V_67 * V_17 )
{
struct V_1 * V_2 = F_108 ( V_17 ) ;
struct V_537 * V_38 = V_2 -> V_38 ;
F_64 ( V_17 ,
L_62 ,
V_538 , V_2 -> V_73 , V_2 -> V_539 ,
V_2 -> V_210 == V_211 ? L_63 : L_64 ,
V_2 -> V_540 ) ;
F_64 ( V_17 , L_65 ,
F_93 ( V_209 , & V_2 -> V_199 ) ? L_66 : L_67 ) ;
F_64 ( V_17 , L_68 ,
( ( V_2 -> V_541 == 64 ) ? L_69 : L_70 ) ,
( ( V_2 -> V_542 ) ? L_71 : L_72 ) ) ;
F_64 ( V_17 , L_73 ,
V_2 -> V_7 ) ;
F_64 ( V_17 , L_74 , V_38 -> V_325 ) ;
F_78 ( V_2 , V_543 , V_17 , L_75 , V_17 -> V_70 ) ;
}
static int F_197 ( struct V_1 * V_2 , int V_544 )
{
struct V_67 * V_17 = V_2 -> V_17 ;
int V_545 = 0 ;
F_148 ( V_17 ) ;
F_149 ( V_17 ) ;
F_101 ( V_546 , & V_2 -> V_199 ) ;
F_101 ( V_198 , & V_2 -> V_199 ) ;
F_24 ( V_2 ) ;
F_198 ( V_2 -> V_38 -> V_325 , V_17 ) ;
if ( V_2 -> V_547 && F_93 ( V_548 , & V_2 -> V_199 ) ) {
F_64 ( V_2 -> V_17 , L_76 ) ;
F_101 ( V_548 , & V_2 -> V_199 ) ;
F_199 ( V_2 -> V_38 ) ;
}
F_200 ( & V_2 -> V_206 ) ;
F_201 ( & V_2 -> V_322 ) ;
if ( V_544 ) {
int V_549 ;
unsigned long V_23 ;
F_12 ( & V_2 -> V_24 , V_23 ) ;
if ( F_7 ( V_2 ) ) {
V_549 = F_194 ( V_2 ) ;
if ( V_549 ) {
F_9 ( V_17 , L_77 ,
V_2 -> V_73 ) ;
}
F_9 ( V_17 ,
L_78 ) ;
} else {
F_9 ( V_17 ,
L_79 ) ;
V_545 = - 1 ;
}
F_13 ( & V_2 -> V_24 , V_23 ) ;
}
F_186 ( V_2 ) ;
return V_545 ;
}
static int F_202 ( struct V_1 * V_2 )
{
struct V_67 * V_17 = V_2 -> V_17 ;
int V_30 ;
unsigned long V_550 = V_551 ;
unsigned long V_23 ;
if ( F_185 ( V_2 ) ) {
F_9 ( V_17 , L_80 ) ;
return - V_386 ;
}
if ( V_2 -> V_547 ) {
if ( F_203 ( V_2 -> V_38 ) ) {
F_9 ( V_17 ,
L_81 ) ;
V_2 -> V_547 = 0 ;
} else {
F_64 ( V_17 , L_82 ) ;
F_100 ( V_548 , & V_2 -> V_199 ) ;
V_550 &= ~ V_551 ;
}
}
V_30 = F_204 ( V_2 -> V_38 -> V_325 , F_146 ,
V_550 , V_17 -> V_125 , V_17 ) ;
if ( V_30 ) {
F_9 ( V_17 ,
L_83 ,
V_2 -> V_38 -> V_325 ) ;
goto V_552;
}
F_12 ( & V_2 -> V_24 , V_23 ) ;
V_30 = F_7 ( V_2 ) ;
if ( V_30 ) {
V_30 = F_188 ( V_2 ) ;
if ( V_30 ) {
F_9 ( V_17 , L_84 ) ;
goto V_553;
}
F_9 ( V_17 , L_85 ) ;
F_5 ( V_2 , V_13 ) ;
} else {
F_9 ( V_17 , L_86 ) ;
goto V_554;
}
F_13 ( & V_2 -> V_24 , V_23 ) ;
F_100 ( V_546 , & V_2 -> V_199 ) ;
F_98 ( & V_2 -> V_206 , V_207 + V_208 * 1 ) ;
F_205 ( & V_2 -> V_322 ) ;
F_25 ( V_2 ) ;
return 0 ;
V_553:
F_5 ( V_2 , V_13 ) ;
V_554:
F_13 ( & V_2 -> V_24 , V_23 ) ;
F_198 ( V_2 -> V_38 -> V_325 , V_17 ) ;
V_552:
if ( V_2 -> V_547 && F_93 ( V_548 , & V_2 -> V_199 ) ) {
F_64 ( V_17 , L_76 ) ;
F_101 ( V_548 , & V_2 -> V_199 ) ;
F_199 ( V_2 -> V_38 ) ;
}
return V_30 ;
}
static int F_206 ( struct V_1 * V_2 , int V_555 )
{
if ( F_197 ( V_2 , V_555 ) || F_202 ( V_2 ) ) {
F_9 ( V_2 -> V_17 ,
L_87 ) ;
F_207 () ;
F_208 ( V_2 -> V_17 ) ;
F_209 () ;
return - 1 ;
}
return 0 ;
}
static int F_210 ( struct V_67 * V_17 )
{
struct V_1 * V_2 = F_108 ( V_17 ) ;
while ( ! F_93 ( V_546 , & V_2 -> V_199 ) )
F_192 ( 50 ) ;
F_197 ( V_2 , V_556 ) ;
return 0 ;
}
static int F_211 ( struct V_67 * V_17 )
{
struct V_1 * V_2 = F_108 ( V_17 ) ;
return F_202 ( V_2 ) ;
}
static int F_212 ( struct V_67 * V_17 , void * V_69 )
{
struct V_1 * V_2 = F_108 ( V_17 ) ;
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
struct V_557 * V_68 = V_69 ;
unsigned long V_23 ;
if ( F_213 ( V_17 ) )
return - V_558 ;
if ( ! F_214 ( V_68 -> V_559 ) )
return - V_560 ;
memcpy ( V_17 -> V_70 , V_68 -> V_559 , V_17 -> V_561 ) ;
F_12 ( & V_2 -> V_24 , V_23 ) ;
F_21 ( V_2 , & V_6 -> V_500 ,
( V_501 << 16 ) ) ;
F_21 ( V_2 , & V_6 -> V_502 ,
( ( V_17 -> V_70 [ 2 ] << 24 ) | ( V_17 ->
V_70 [ 3 ] << 16 ) |
( V_17 -> V_70 [ 4 ] << 8 ) | V_17 -> V_70 [ 5 ] ) ) ;
F_21 ( V_2 , & V_6 -> V_500 ,
( ( V_501 << 16 ) | 1 ) ) ;
F_21 ( V_2 , & V_6 -> V_502 ,
( ( V_17 -> V_70 [ 0 ] << 8 ) | V_17 -> V_70 [ 1 ] ) ) ;
F_13 ( & V_2 -> V_24 , V_23 ) ;
return 0 ;
}
static void F_215 ( struct V_67 * V_17 )
{
struct V_1 * V_2 = F_108 ( V_17 ) ;
F_9 ( V_17 , L_88 ) ;
F_148 ( V_17 ) ;
F_150 ( V_2 -> V_335 , & V_2 -> V_562 , 0 ) ;
}
static void F_216 ( struct V_201 * V_202 )
{
struct V_1 * V_2 =
F_97 ( V_202 , struct V_1 , V_336 . V_202 ) ;
struct V_67 * V_17 = V_2 -> V_17 ;
T_1 V_8 ;
struct V_257 * V_258 ;
int V_519 , V_12 ;
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
unsigned long V_23 ;
if ( F_93 ( ( V_334 | V_333 ) , & V_2 -> V_199 ) ) {
F_101 ( V_198 , & V_2 -> V_199 ) ;
for ( V_12 = 0 ; V_12 < V_378 ; V_12 ++ ) {
int V_563 ;
V_258 = & V_2 -> V_260 [ V_12 ] ;
if ( V_258 -> V_34 ) {
F_8 ( V_16 , V_17 ,
L_89 ) ;
F_123 ( V_2 -> V_38 ,
F_124 ( & V_258 -> V_29 [ 0 ] ,
V_43 ) ,
F_125 ( & V_258 -> V_29 [ 0 ] , V_44 ) ,
V_267 ) ;
for ( V_563 = 1 ; V_563 < V_258 -> V_265 ; V_563 ++ ) {
F_126 ( V_2 -> V_38 ,
F_124 ( & V_258 -> V_29 [ V_563 ] ,
V_43 ) ,
F_125 ( & V_258 -> V_29 [ V_563 ] ,
V_44 ) ,
V_267 ) ;
}
F_32 ( V_258 -> V_34 ) ;
V_258 -> V_34 = NULL ;
}
}
F_9 ( V_17 , L_90 ) ;
F_12 ( & V_2 -> V_24 , V_23 ) ;
F_18 ( V_2 ,
& V_6 -> V_10 .
V_20 ,
( ( V_330 << 16 ) | V_330 ) ) ;
V_519 = 10 ;
do {
V_8 = F_14 ( V_2 ,
& V_6 -> V_10 .
V_20 ) ;
if ( ( V_8 & V_521 ) == 0 ) {
F_8 ( V_16 , V_17 ,
L_91 ) ;
break;
}
if ( V_8 & V_330 ) {
F_8 ( V_16 , V_17 ,
L_92 ) ;
F_18 ( V_2 ,
& V_6 ->
V_10 .
V_20 ,
( ( V_330 <<
16 ) | V_330 ) ) ;
}
F_13 ( & V_2 -> V_24 , V_23 ) ;
F_4 ( 1 ) ;
F_12 ( & V_2 -> V_24 , V_23 ) ;
} while ( -- V_519 );
F_13 ( & V_2 -> V_24 , V_23 ) ;
if ( V_8 & V_521 ) {
F_9 ( V_17 ,
L_93 ) ;
F_9 ( V_17 , L_94 ) ;
F_101 ( V_334 , & V_2 -> V_199 ) ;
F_101 ( V_333 , & V_2 -> V_199 ) ;
F_206 ( V_2 , V_556 ) ;
return;
}
F_101 ( V_205 , & V_2 -> V_199 ) ;
F_101 ( V_334 , & V_2 -> V_199 ) ;
F_101 ( V_333 , & V_2 -> V_199 ) ;
F_206 ( V_2 , V_564 ) ;
}
}
static void F_217 ( struct V_201 * V_202 )
{
struct V_1 * V_2 =
F_97 ( V_202 , struct V_1 , V_562 . V_202 ) ;
F_206 ( V_2 , V_556 ) ;
}
static void F_218 ( struct V_1 * V_2 )
{
struct V_5 T_2 * V_6 =
V_2 -> V_7 ;
T_1 V_8 ;
V_8 = F_15 ( V_2 , & V_6 -> V_157 ) ;
V_2 -> V_539 = ( ( V_8 & V_565 ) >> 12 ) ;
if ( V_8 & V_566 )
V_2 -> V_541 = 64 ;
else
V_2 -> V_541 = 32 ;
if ( V_8 & V_567 )
V_2 -> V_542 = 1 ;
else
V_2 -> V_542 = 0 ;
V_2 -> V_540 = ( T_5 ) F_219 ( V_2 -> V_38 -> V_568 ) ;
}
static void F_220 ( unsigned long V_569 )
{
struct V_1 * V_2 = (struct V_1 * ) V_569 ;
F_150 ( V_2 -> V_335 , & V_2 -> V_203 , 0 ) ;
}
static int F_221 ( struct V_537 * V_38 ,
const struct V_570 * V_571 )
{
struct V_67 * V_17 = NULL ;
struct V_1 * V_2 = NULL ;
static int V_572 ;
int V_573 ( V_574 ) , V_30 ;
V_30 = F_222 ( V_38 ) ;
if ( V_30 ) {
F_47 ( L_95 , F_113 ( V_38 ) ) ;
goto V_575;
}
V_30 = F_223 ( V_38 , V_538 ) ;
if ( V_30 ) {
F_47 ( L_96 , F_113 ( V_38 ) ) ;
goto V_576;
}
F_224 ( V_38 ) ;
if ( ! F_225 ( V_38 , F_226 ( 64 ) ) ) {
V_574 = 1 ;
V_30 = F_227 ( V_38 , F_226 ( 64 ) ) ;
} else if ( ! ( V_30 = F_225 ( V_38 , F_226 ( 32 ) ) ) ) {
V_574 = 0 ;
V_30 = F_227 ( V_38 , F_226 ( 32 ) ) ;
}
if ( V_30 ) {
F_47 ( L_97 , F_113 ( V_38 ) ) ;
goto V_577;
}
V_17 = F_228 ( sizeof( struct V_1 ) ) ;
if ( ! V_17 ) {
V_30 = - V_386 ;
goto V_577;
}
F_229 ( V_17 , & V_38 -> V_368 ) ;
F_230 ( V_38 , V_17 ) ;
V_2 = F_108 ( V_17 ) ;
V_2 -> V_73 = V_572 ;
V_2 -> V_17 = V_17 ;
V_2 -> V_38 = V_38 ;
V_2 -> V_210 = V_571 -> V_578 ;
V_2 -> V_200 = V_196 ;
if ( V_547 )
V_2 -> V_547 = 1 ;
V_2 -> V_236 = F_231 ( V_579 , V_580 ) ;
if ( V_574 )
V_17 -> V_581 |= V_582 ;
if ( V_2 -> V_210 == V_211 )
V_17 -> V_581 |= V_583 | V_584 ;
V_2 -> V_7 = F_232 ( V_38 , 1 ) ;
if ( ! V_2 -> V_7 ) {
F_47 ( L_98 , F_113 ( V_38 ) ) ;
V_30 = - V_144 ;
goto V_585;
}
F_233 ( & V_2 -> V_331 ) ;
F_233 ( & V_2 -> V_24 ) ;
V_17 -> V_586 = & V_587 ;
V_17 -> V_588 = & V_589 ;
V_17 -> V_590 = 5 * V_208 ;
F_234 ( V_17 , & V_2 -> V_322 , F_144 , 64 ) ;
V_17 -> V_325 = V_38 -> V_325 ;
if ( F_46 ( V_2 ) ) {
F_235 ( L_99 ,
V_76 , V_2 -> V_73 ) ;
V_30 = - V_144 ;
goto V_591;
}
F_195 ( V_2 ) ;
if ( V_2 -> V_15 ) {
V_17 -> V_415 = V_2 -> V_74 . V_170 . V_592 ;
F_44 ( V_17 , V_2 -> V_74 . V_593 . V_594 ) ;
} else {
V_17 -> V_415 = V_2 -> V_74 . V_169 . V_592 ;
F_44 ( V_17 , V_2 -> V_74 . V_595 . V_594 ) ;
}
V_17 -> V_596 = V_378 ;
F_218 ( V_2 ) ;
if ( V_2 -> V_542 )
F_236 ( V_38 , ( int ) 0x4e , ( V_65 ) 0x0036 ) ;
V_30 = F_237 ( V_17 ) ;
if ( V_30 ) {
F_47 ( L_100 , F_113 ( V_38 ) ) ;
goto V_591;
}
F_149 ( V_17 ) ;
F_148 ( V_17 ) ;
V_2 -> V_335 = F_238 ( V_17 -> V_125 ) ;
F_239 ( & V_2 -> V_336 , F_216 ) ;
F_239 ( & V_2 -> V_562 , F_217 ) ;
F_239 ( & V_2 -> V_203 , F_96 ) ;
F_240 ( & V_2 -> V_206 ) ;
V_2 -> V_206 . V_597 = F_220 ;
V_2 -> V_206 . V_598 = V_207 + V_208 * 2 ;
V_2 -> V_206 . V_39 = ( unsigned long ) V_2 ;
if ( ! V_572 ) {
F_235 ( L_101 , V_599 ) ;
F_235 ( L_102 ,
V_538 , V_600 ) ;
}
F_196 ( V_17 ) ;
V_572 ++ ;
return 0 ;
V_591:
F_241 ( V_2 -> V_7 ) ;
V_585:
F_242 ( V_17 ) ;
V_577:
F_243 ( V_38 ) ;
V_576:
F_244 ( V_38 ) ;
V_575:
return V_30 ;
}
static void F_245 ( struct V_537 * V_38 )
{
struct V_67 * V_17 = F_246 ( V_38 ) ;
struct V_1 * V_2 = F_108 ( V_17 ) ;
F_247 ( V_17 ) ;
F_24 ( V_2 ) ;
if ( V_2 -> V_335 ) {
F_248 ( & V_2 -> V_336 ) ;
F_248 ( & V_2 -> V_562 ) ;
F_249 ( V_2 -> V_335 ) ;
V_2 -> V_335 = NULL ;
}
F_241 ( V_2 -> V_7 ) ;
F_243 ( V_38 ) ;
F_242 ( V_17 ) ;
}

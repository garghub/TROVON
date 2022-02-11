static void F_1 ( struct V_1 * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
F_2 ( 2 , L_1 , V_1 ) ;
F_3 ( V_4 , 3 , ( V_2 ? V_5 : V_6 ) ) ;
}
static void F_4 ( struct V_1 * V_1 , int V_7 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
F_2 ( 2 , L_1 , V_1 ) ;
F_3 ( V_4 , 3 , V_5 ) ;
F_5 ( V_7 ? 500 : 1000 ) ;
F_3 ( V_4 , 3 , V_6 ) ;
F_5 ( V_7 ? 1000 : 500 ) ;
}
static void F_6 ( struct V_1 * V_1 , int V_7 )
{
int V_8 , V_9 = 1 , V_10 ;
F_2 ( 2 , L_1 , V_1 ) ;
for ( V_8 = 7 ; V_8 >= 0 ; V_8 -- ) {
V_10 = ( V_7 >> V_8 ) & 1 ;
V_9 ^= V_10 ;
F_4 ( V_1 , V_10 ) ;
}
F_4 ( V_1 , V_9 ) ;
}
static int F_7 ( struct V_1 * V_1 , int V_11 , T_1 * V_12 , unsigned long V_13 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
int V_8 ;
F_2 ( 2 , L_1 , V_1 ) ;
F_3 ( V_4 , 3 , V_6 ) ;
F_8 ( 16 ) ;
for ( V_8 = 0 ; V_8 < V_11 ; V_8 ++ )
F_6 ( V_1 , V_12 [ V_8 ] ) ;
F_8 ( 16 ) ;
if ( V_13 != - 1 ) {
if ( V_13 )
F_6 ( V_1 , 0xff ) ;
else {
F_3 ( V_4 , 3 , V_5 ) ;
F_8 ( 12 ) ;
F_5 ( 500 ) ;
F_3 ( V_4 , 3 , V_6 ) ;
}
F_9 ( 20 ) ;
}
return 0 ;
}
static int F_10 ( struct V_14 * V_15 ,
enum V_16 V_17 )
{
struct V_1 * V_1 = (struct V_1 * ) V_15 -> V_18 -> V_19 ;
switch ( V_17 ) {
case V_20 :
F_1 ( V_1 , 1 ) ;
break;
case V_21 :
F_1 ( V_1 , 0 ) ;
break;
default:
return - V_22 ;
}
return 0 ;
}
static int F_11 ( struct V_14 * V_15 , struct V_23 * V_24 )
{
struct V_1 * V_1 = (struct V_1 * ) V_15 -> V_18 -> V_19 ;
F_7 ( V_1 , V_24 -> V_25 , V_24 -> V_12 , 0 ) ;
return 0 ;
}
static int F_12 ( struct V_14 * V_15 ,
enum V_26 V_27 )
{
struct V_1 * V_1 = (struct V_1 * ) V_15 -> V_18 -> V_19 ;
F_7 ( V_1 , 0 , NULL , V_27 ) ;
return 0 ;
}
static int F_13 ( struct V_28 * V_1 , T_2 * V_29 , int V_30 )
{
int V_8 ;
F_2 ( 2 , L_1 , V_1 ) ;
for ( V_8 = 2 ; V_8 < V_30 ; V_8 ++ )
{
F_14 ( V_1 , V_31 , V_32 + 2 * V_8 , 2 , ( V_33 ) V_29 [ V_8 ] , 0 , 0 ) ;
F_9 ( 5 ) ;
}
if ( V_30 )
F_14 ( V_1 , V_31 , V_32 + 2 , 2 , ( V_33 ) V_29 [ 1 ] , 0 , 0 ) ;
else
F_14 ( V_1 , V_31 , V_32 + 2 , 2 , 0 , 0 , 0 ) ;
F_9 ( 5 ) ;
F_14 ( V_1 , V_31 , V_32 , 2 , ( V_33 ) V_29 [ 0 ] , 0 , 0 ) ;
F_9 ( 5 ) ;
return 0 ;
}
static void F_15 ( struct V_28 * V_1 , int V_2 )
{
T_2 V_29 [ 2 ] = { ( V_34 << 8 ) | ( V_2 ? V_35 : V_36 ) , 0 } ;
F_2 ( 2 , L_1 , V_1 ) ;
F_13 ( V_1 , V_29 , 2 ) ;
}
static int F_16 ( struct V_28 * V_1 , int V_11 , T_1 * V_12 , int V_13 )
{
int V_8 ;
T_2 V_29 [ 18 ] = { ( ( V_34 << 8 ) | V_37 ) ,
16 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
F_2 ( 2 , L_1 , V_1 ) ;
if ( V_11 > 10 )
V_11 = 10 ;
V_29 [ 1 ] = V_11 + 2 ;
V_29 [ 2 ] = V_11 ;
if ( V_13 != - 1 )
V_29 [ 3 ] = V_13 ? 0x01 : 0x00 ;
else
V_29 [ 3 ] = 0xffff ;
for ( V_8 = 0 ; V_8 < V_11 ; V_8 ++ )
V_29 [ V_8 + 4 ] = V_12 [ V_8 ] ;
F_13 ( V_1 , V_29 , 18 ) ;
return 0 ;
}
static int F_17 ( struct V_14 * V_15 ,
enum V_16 V_17 )
{
struct V_28 * V_1 = (struct V_28 * ) V_15 -> V_18 -> V_19 ;
switch ( V_17 ) {
case V_20 :
F_15 ( V_1 , 1 ) ;
break;
case V_21 :
F_15 ( V_1 , 0 ) ;
break;
default:
return - V_22 ;
}
return 0 ;
}
static int F_18 ( struct V_14 * V_15 , struct V_23 * V_24 )
{
struct V_28 * V_1 = (struct V_28 * ) V_15 -> V_18 -> V_19 ;
F_16 ( V_1 , V_24 -> V_25 , V_24 -> V_12 , 0 ) ;
return 0 ;
}
static int F_19 ( struct V_14 * V_15 ,
enum V_26 V_27 )
{
struct V_28 * V_1 = (struct V_28 * ) V_15 -> V_18 -> V_19 ;
F_16 ( V_1 , 0 , NULL , V_27 ) ;
return 0 ;
}
static int F_20 ( struct V_14 * V_15 )
{
struct V_38 * V_39 = & V_15 -> V_40 ;
struct V_28 * V_1 = (struct V_28 * ) V_15 -> V_18 -> V_19 ;
T_1 V_41 = 0 ;
T_1 V_29 [ 4 ] ;
struct V_42 V_12 = { . V_43 = 0x61 , . V_44 = 0 , . V_29 = V_29 , . V_11 = sizeof( V_29 ) } ;
V_33 div = ( V_39 -> V_45 + 479500 ) / 125 ;
if ( V_39 -> V_45 > 2000000 )
V_41 = 3 ;
else if ( V_39 -> V_45 > 1800000 )
V_41 = 2 ;
else if ( V_39 -> V_45 > 1600000 )
V_41 = 1 ;
else if ( V_39 -> V_45 > 1200000 )
V_41 = 0 ;
else if ( V_39 -> V_45 >= 1100000 )
V_41 = 1 ;
else V_41 = 2 ;
V_29 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_29 [ 1 ] = div & 0xff ;
V_29 [ 2 ] = ( ( div & 0x18000 ) >> 10 ) | 0x95 ;
V_29 [ 3 ] = ( V_41 << 6 ) | 0x30 ;
if ( V_15 -> V_46 . V_47 )
V_15 -> V_46 . V_47 ( V_15 , 1 ) ;
if ( F_21 ( & V_1 -> V_48 , & V_12 , 1 ) != 1 )
return - V_49 ;
return 0 ;
}
static int F_22 ( struct V_14 * V_15 )
{
struct V_38 * V_39 = & V_15 -> V_40 ;
struct V_28 * V_1 = (struct V_28 * ) V_15 -> V_18 -> V_19 ;
V_33 div ;
T_1 V_7 [ 4 ] ;
struct V_42 V_12 = { . V_43 = 0x61 , . V_44 = 0 , . V_29 = V_7 , . V_11 = sizeof( V_7 ) } ;
div = V_39 -> V_45 / 125 ;
V_7 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_7 [ 1 ] = div & 0xff ;
V_7 [ 2 ] = 0x8e ;
V_7 [ 3 ] = 0x00 ;
if ( V_15 -> V_46 . V_47 )
V_15 -> V_46 . V_47 ( V_15 , 1 ) ;
if ( F_21 ( & V_1 -> V_48 , & V_12 , 1 ) != 1 )
return - V_49 ;
return 0 ;
}
static void F_23 ( struct V_28 * V_1 )
{
switch( V_1 -> V_4 -> V_50 -> V_51 ) {
case 0x0000 :
case 0x1013 :
V_1 -> V_14 = F_24 ( V_52 , & V_53 , & V_1 -> V_48 ) ;
if ( V_1 -> V_14 ) {
V_1 -> V_14 -> V_46 . V_54 . V_55 = F_20 ;
V_1 -> V_14 -> V_46 . V_56 = F_18 ;
V_1 -> V_14 -> V_46 . V_57 = F_19 ;
V_1 -> V_14 -> V_46 . V_58 = F_17 ;
break;
}
V_1 -> V_14 = F_24 ( V_59 , & V_60 , & V_1 -> V_48 ) ;
if ( V_1 -> V_14 ) {
V_1 -> V_14 -> V_46 . V_54 . V_55 = V_61 ;
V_1 -> V_14 -> V_62 = & V_1 -> V_48 ;
V_1 -> V_14 -> V_46 . V_56 = F_11 ;
V_1 -> V_14 -> V_46 . V_57 = F_12 ;
V_1 -> V_14 -> V_46 . V_58 = F_10 ;
break;
}
V_1 -> V_14 = F_24 ( V_63 , & V_64 , & V_1 -> V_48 ) ;
if ( V_1 -> V_14 ) {
V_1 -> V_14 -> V_46 . V_54 . V_55 = F_22 ;
V_1 -> V_14 -> V_46 . V_56 = F_11 ;
V_1 -> V_14 -> V_46 . V_57 = F_12 ;
V_1 -> V_14 -> V_46 . V_58 = F_10 ;
break;
}
break;
}
if ( V_1 -> V_14 == NULL ) {
F_25 ( L_2 ,
V_1 -> V_4 -> V_50 -> V_65 ,
V_1 -> V_4 -> V_50 -> V_66 ,
V_1 -> V_4 -> V_50 -> V_67 ,
V_1 -> V_4 -> V_50 -> V_51 ) ;
} else {
if ( F_26 ( & V_1 -> V_68 , V_1 -> V_14 ) ) {
F_25 ( L_3 ) ;
F_27 ( V_1 -> V_14 ) ;
V_1 -> V_14 = NULL ;
}
}
}
static int F_28 ( struct V_3 * V_4 , struct V_69 * V_70 )
{
struct V_28 * V_1 ;
int V_71 ;
int V_72 = 0 ;
int V_73 = 0 ;
#define F_29 0
#define F_30 0
#define F_31 0
#if F_29
F_32 ( V_4 , V_74 , V_75 ) ;
F_9 ( 40 ) ;
#endif
#if F_31
F_32 ( V_4 , V_76 , 0 ) ;
F_32 ( V_4 , V_77 , 0x00000200 ) ;
F_32 ( V_4 , V_78 , 0x00000000 ) ;
F_32 ( V_4 , V_79 , 0 ) ;
F_32 ( V_4 , V_80 , 0 ) ;
F_32 ( V_4 , V_81 , 0 ) ;
F_32 ( V_4 , V_82 , 0 ) ;
F_32 ( V_4 , V_83 , 0 ) ;
F_32 ( V_4 , V_84 , 0 ) ;
F_32 ( V_4 , V_85 , 0 ) ;
F_32 ( V_4 , V_86 , ( 1 << 30 ) | ( 0 << 29 ) | ( 1 << 28 ) | ( 0 << 12 ) ) ;
F_32 ( V_4 , V_87 ,
0 * ( V_88 | V_89 ) |
0 * ( V_90 | V_91 ) |
0 * ( V_92 | V_93 ) |
1 * ( V_94 | V_95 ) |
1 * ( V_96 | V_97 ) |
0 * ( V_98 | V_99 )
) ;
#endif
F_32 ( V_4 , V_74 , ( V_100 | V_101 ) ) ;
F_32 ( V_4 , V_102 , 0 ) ;
V_72 = 0 ;
#if 0
WRITE_RPS1(CMD_UPLOAD |
MASK_10 | MASK_09 | MASK_08 | MASK_06 | MASK_05 | MASK_04 | MASK_03 | MASK_02 );
#endif
F_33 ( V_103 | V_104 ) ;
F_33 ( V_105 | ( V_106 >> 2 ) ) ;
F_33 ( V_107 ) ;
F_33 ( V_6 << 24 ) ;
#if F_30
F_33 ( V_108 ) ;
F_33 ( V_109 ) ;
F_33 ( V_108 ) ;
#endif
F_33 ( V_110 ) ;
#if F_30
F_32 ( V_4 , V_111 , ( 0x03 << 2 ) | 3 ) ;
F_32 ( V_4 , V_112 , 0x3fff ) ;
#endif
F_3 ( V_4 , 3 , V_6 ) ;
F_32 ( V_4 , V_113 , V_4 -> V_114 . V_115 ) ;
F_32 ( V_4 , V_74 , ( V_116 | V_100 ) ) ;
F_8 ( 50 ) ;
F_3 ( V_4 , 3 , V_5 ) ;
F_8 ( 150 ) ;
if( ( F_34 ( V_4 , V_106 ) & 0x10000000 ) == 0 )
V_73 = 1 ;
#if F_30
F_25 ( L_4 , F_34 ( V_4 , V_117 ) & 0x3fff ) ;
#endif
F_32 ( V_4 , V_74 , ( V_100 ) ) ;
if( V_73 == 0 )
F_25 ( L_5
L_6 ) ;
else
F_25 ( L_7 ) ;
V_72 = 0 ;
F_33 ( V_103 | V_118 ) ;
F_33 ( V_105 | ( V_106 >> 2 ) ) ;
F_33 ( V_107 ) ;
F_33 ( V_5 << 24 ) ;
#if F_30
F_33 ( V_108 ) ;
#endif
F_33 ( V_103 | V_119 | V_118 ) ;
F_33 ( V_105 | ( V_106 >> 2 ) ) ;
F_33 ( V_107 ) ;
F_33 ( V_6 << 24 ) ;
#if F_30
F_33 ( V_108 ) ;
#endif
F_33 ( V_120 ) ;
F_33 ( V_4 -> V_114 . V_115 ) ;
F_3 ( V_4 , 3 , V_6 ) ;
F_32 ( V_4 , V_113 , V_4 -> V_114 . V_115 ) ;
if ( ! ( V_1 = F_35 ( sizeof( struct V_28 ) , V_121 ) ) )
return - V_122 ;
F_2 ( 2 , L_1 , V_1 ) ;
V_71 = F_36 ( V_1 , V_4 , V_70 , V_123 , V_124 ) ;
if ( V_71 ) {
F_37 ( V_1 ) ;
return V_71 ;
}
F_32 ( V_4 , V_125 , V_1 -> V_126 | V_127 ) ;
F_32 ( V_4 , V_74 , ( V_116 | V_100 ) ) ;
V_4 -> V_128 = V_1 ;
V_1 -> V_68 . V_19 = V_1 ;
F_23 ( V_1 ) ;
F_38 ( V_1 ) ;
return 0 ;
}
static int F_39 ( struct V_3 * V_4 )
{
struct V_28 * V_1 = (struct V_28 * ) V_4 -> V_128 ;
int V_71 ;
if ( V_1 -> V_14 ) {
F_40 ( V_1 -> V_14 ) ;
F_27 ( V_1 -> V_14 ) ;
}
V_71 = F_41 ( V_1 ) ;
F_37 ( V_1 ) ;
return V_71 ;
}
static int T_3 F_42 ( void )
{
return F_43 ( & V_129 ) ;
}
static void T_4 F_44 ( void )
{
F_45 ( & V_129 ) ;
}

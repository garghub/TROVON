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
static int F_10 ( struct V_14 * V_15 , T_2 V_16 )
{
struct V_1 * V_1 = (struct V_1 * ) V_15 -> V_17 -> V_18 ;
switch ( V_16 ) {
case V_19 :
F_1 ( V_1 , 1 ) ;
break;
case V_20 :
F_1 ( V_1 , 0 ) ;
break;
default:
return - V_21 ;
}
return 0 ;
}
static int F_11 ( struct V_14 * V_15 , struct V_22 * V_23 )
{
struct V_1 * V_1 = (struct V_1 * ) V_15 -> V_17 -> V_18 ;
F_7 ( V_1 , V_23 -> V_24 , V_23 -> V_12 , 0 ) ;
return 0 ;
}
static int F_12 ( struct V_14 * V_15 , T_3 V_25 )
{
struct V_1 * V_1 = (struct V_1 * ) V_15 -> V_17 -> V_18 ;
F_7 ( V_1 , 0 , NULL , V_25 ) ;
return 0 ;
}
static int F_13 ( struct V_26 * V_1 , T_4 * V_27 , int V_28 )
{
int V_8 ;
F_2 ( 2 , L_1 , V_1 ) ;
for ( V_8 = 2 ; V_8 < V_28 ; V_8 ++ )
{
F_14 ( V_1 , V_29 , V_30 + 2 * V_8 , 2 , ( V_31 ) V_27 [ V_8 ] , 0 , 0 ) ;
F_9 ( 5 ) ;
}
if ( V_28 )
F_14 ( V_1 , V_29 , V_30 + 2 , 2 , ( V_31 ) V_27 [ 1 ] , 0 , 0 ) ;
else
F_14 ( V_1 , V_29 , V_30 + 2 , 2 , 0 , 0 , 0 ) ;
F_9 ( 5 ) ;
F_14 ( V_1 , V_29 , V_30 , 2 , ( V_31 ) V_27 [ 0 ] , 0 , 0 ) ;
F_9 ( 5 ) ;
return 0 ;
}
static void F_15 ( struct V_26 * V_1 , int V_2 )
{
T_4 V_27 [ 2 ] = { ( V_32 << 8 ) | ( V_2 ? V_33 : V_34 ) , 0 } ;
F_2 ( 2 , L_1 , V_1 ) ;
F_13 ( V_1 , V_27 , 2 ) ;
}
static int F_16 ( struct V_26 * V_1 , int V_11 , T_1 * V_12 , int V_13 )
{
int V_8 ;
T_4 V_27 [ 18 ] = { ( ( V_32 << 8 ) | V_35 ) ,
16 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
F_2 ( 2 , L_1 , V_1 ) ;
if ( V_11 > 10 )
V_11 = 10 ;
V_27 [ 1 ] = V_11 + 2 ;
V_27 [ 2 ] = V_11 ;
if ( V_13 != - 1 )
V_27 [ 3 ] = V_13 ? 0x01 : 0x00 ;
else
V_27 [ 3 ] = 0xffff ;
for ( V_8 = 0 ; V_8 < V_11 ; V_8 ++ )
V_27 [ V_8 + 4 ] = V_12 [ V_8 ] ;
F_13 ( V_1 , V_27 , 18 ) ;
return 0 ;
}
static int F_17 ( struct V_14 * V_15 , T_2 V_16 )
{
struct V_26 * V_1 = (struct V_26 * ) V_15 -> V_17 -> V_18 ;
switch ( V_16 ) {
case V_19 :
F_15 ( V_1 , 1 ) ;
break;
case V_20 :
F_15 ( V_1 , 0 ) ;
break;
default:
return - V_21 ;
}
return 0 ;
}
static int F_18 ( struct V_14 * V_15 , struct V_22 * V_23 )
{
struct V_26 * V_1 = (struct V_26 * ) V_15 -> V_17 -> V_18 ;
F_16 ( V_1 , V_23 -> V_24 , V_23 -> V_12 , 0 ) ;
return 0 ;
}
static int F_19 ( struct V_14 * V_15 , T_3 V_25 )
{
struct V_26 * V_1 = (struct V_26 * ) V_15 -> V_17 -> V_18 ;
F_16 ( V_1 , 0 , NULL , V_25 ) ;
return 0 ;
}
static int F_20 ( struct V_14 * V_15 )
{
struct V_36 * V_37 = & V_15 -> V_38 ;
struct V_26 * V_1 = (struct V_26 * ) V_15 -> V_17 -> V_18 ;
T_1 V_39 = 0 ;
T_1 V_27 [ 4 ] ;
struct V_40 V_12 = { . V_41 = 0x61 , . V_42 = 0 , . V_27 = V_27 , . V_11 = sizeof( V_27 ) } ;
V_31 div = ( V_37 -> V_43 + 479500 ) / 125 ;
if ( V_37 -> V_43 > 2000000 )
V_39 = 3 ;
else if ( V_37 -> V_43 > 1800000 )
V_39 = 2 ;
else if ( V_37 -> V_43 > 1600000 )
V_39 = 1 ;
else if ( V_37 -> V_43 > 1200000 )
V_39 = 0 ;
else if ( V_37 -> V_43 >= 1100000 )
V_39 = 1 ;
else V_39 = 2 ;
V_27 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_27 [ 1 ] = div & 0xff ;
V_27 [ 2 ] = ( ( div & 0x18000 ) >> 10 ) | 0x95 ;
V_27 [ 3 ] = ( V_39 << 6 ) | 0x30 ;
if ( V_15 -> V_44 . V_45 )
V_15 -> V_44 . V_45 ( V_15 , 1 ) ;
if ( F_21 ( & V_1 -> V_46 , & V_12 , 1 ) != 1 )
return - V_47 ;
return 0 ;
}
static int F_22 ( struct V_14 * V_15 )
{
struct V_36 * V_37 = & V_15 -> V_38 ;
struct V_26 * V_1 = (struct V_26 * ) V_15 -> V_17 -> V_18 ;
V_31 div ;
T_1 V_7 [ 4 ] ;
struct V_40 V_12 = { . V_41 = 0x61 , . V_42 = 0 , . V_27 = V_7 , . V_11 = sizeof( V_7 ) } ;
div = V_37 -> V_43 / 125 ;
V_7 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_7 [ 1 ] = div & 0xff ;
V_7 [ 2 ] = 0x8e ;
V_7 [ 3 ] = 0x00 ;
if ( V_15 -> V_44 . V_45 )
V_15 -> V_44 . V_45 ( V_15 , 1 ) ;
if ( F_21 ( & V_1 -> V_46 , & V_12 , 1 ) != 1 )
return - V_47 ;
return 0 ;
}
static void F_23 ( struct V_26 * V_1 )
{
switch( V_1 -> V_4 -> V_48 -> V_49 ) {
case 0x0000 :
case 0x1013 :
V_1 -> V_14 = F_24 ( V_50 , & V_51 , & V_1 -> V_46 ) ;
if ( V_1 -> V_14 ) {
V_1 -> V_14 -> V_44 . V_52 . V_53 = F_20 ;
V_1 -> V_14 -> V_44 . V_54 = F_18 ;
V_1 -> V_14 -> V_44 . V_55 = F_19 ;
V_1 -> V_14 -> V_44 . V_56 = F_17 ;
break;
}
V_1 -> V_14 = F_24 ( V_57 , & V_58 , & V_1 -> V_46 ) ;
if ( V_1 -> V_14 ) {
V_1 -> V_14 -> V_44 . V_52 . V_53 = V_59 ;
V_1 -> V_14 -> V_60 = & V_1 -> V_46 ;
V_1 -> V_14 -> V_44 . V_54 = F_11 ;
V_1 -> V_14 -> V_44 . V_55 = F_12 ;
V_1 -> V_14 -> V_44 . V_56 = F_10 ;
break;
}
V_1 -> V_14 = F_24 ( V_61 , & V_62 , & V_1 -> V_46 ) ;
if ( V_1 -> V_14 ) {
V_1 -> V_14 -> V_44 . V_52 . V_53 = F_22 ;
V_1 -> V_14 -> V_44 . V_54 = F_11 ;
V_1 -> V_14 -> V_44 . V_55 = F_12 ;
V_1 -> V_14 -> V_44 . V_56 = F_10 ;
break;
}
break;
}
if ( V_1 -> V_14 == NULL ) {
F_25 ( L_2 ,
V_1 -> V_4 -> V_48 -> V_63 ,
V_1 -> V_4 -> V_48 -> V_64 ,
V_1 -> V_4 -> V_48 -> V_65 ,
V_1 -> V_4 -> V_48 -> V_49 ) ;
} else {
if ( F_26 ( & V_1 -> V_66 , V_1 -> V_14 ) ) {
F_25 ( L_3 ) ;
F_27 ( V_1 -> V_14 ) ;
V_1 -> V_14 = NULL ;
}
}
}
static int F_28 ( struct V_3 * V_4 , struct V_67 * V_68 )
{
struct V_26 * V_1 ;
int V_69 ;
int V_70 = 0 ;
int V_71 = 0 ;
#define F_29 0
#define F_30 0
#define F_31 0
#if F_29
F_32 ( V_4 , V_72 , V_73 ) ;
F_9 ( 40 ) ;
#endif
#if F_31
F_32 ( V_4 , V_74 , 0 ) ;
F_32 ( V_4 , V_75 , 0x00000200 ) ;
F_32 ( V_4 , V_76 , 0x00000000 ) ;
F_32 ( V_4 , V_77 , 0 ) ;
F_32 ( V_4 , V_78 , 0 ) ;
F_32 ( V_4 , V_79 , 0 ) ;
F_32 ( V_4 , V_80 , 0 ) ;
F_32 ( V_4 , V_81 , 0 ) ;
F_32 ( V_4 , V_82 , 0 ) ;
F_32 ( V_4 , V_83 , 0 ) ;
F_32 ( V_4 , V_84 , ( 1 << 30 ) | ( 0 << 29 ) | ( 1 << 28 ) | ( 0 << 12 ) ) ;
F_32 ( V_4 , V_85 ,
0 * ( V_86 | V_87 ) |
0 * ( V_88 | V_89 ) |
0 * ( V_90 | V_91 ) |
1 * ( V_92 | V_93 ) |
1 * ( V_94 | V_95 ) |
0 * ( V_96 | V_97 )
) ;
#endif
F_32 ( V_4 , V_72 , ( V_98 | V_99 ) ) ;
F_32 ( V_4 , V_100 , 0 ) ;
V_70 = 0 ;
#if 0
WRITE_RPS1(CMD_UPLOAD |
MASK_10 | MASK_09 | MASK_08 | MASK_06 | MASK_05 | MASK_04 | MASK_03 | MASK_02 );
#endif
F_33 ( V_101 | V_102 ) ;
F_33 ( V_103 | ( V_104 >> 2 ) ) ;
F_33 ( V_105 ) ;
F_33 ( V_6 << 24 ) ;
#if F_30
F_33 ( V_106 ) ;
F_33 ( V_107 ) ;
F_33 ( V_106 ) ;
#endif
F_33 ( V_108 ) ;
#if F_30
F_32 ( V_4 , V_109 , ( 0x03 << 2 ) | 3 ) ;
F_32 ( V_4 , V_110 , 0x3fff ) ;
#endif
F_3 ( V_4 , 3 , V_6 ) ;
F_32 ( V_4 , V_111 , V_4 -> V_112 . V_113 ) ;
F_32 ( V_4 , V_72 , ( V_114 | V_98 ) ) ;
F_8 ( 50 ) ;
F_3 ( V_4 , 3 , V_5 ) ;
F_8 ( 150 ) ;
if( ( F_34 ( V_4 , V_104 ) & 0x10000000 ) == 0 )
V_71 = 1 ;
#if F_30
F_25 ( L_4 , F_34 ( V_4 , V_115 ) & 0x3fff ) ;
#endif
F_32 ( V_4 , V_72 , ( V_98 ) ) ;
if( V_71 == 0 )
F_25 ( L_5
L_6 ) ;
else
F_25 ( L_7 ) ;
V_70 = 0 ;
F_33 ( V_101 | V_116 ) ;
F_33 ( V_103 | ( V_104 >> 2 ) ) ;
F_33 ( V_105 ) ;
F_33 ( V_5 << 24 ) ;
#if F_30
F_33 ( V_106 ) ;
#endif
F_33 ( V_101 | V_117 | V_116 ) ;
F_33 ( V_103 | ( V_104 >> 2 ) ) ;
F_33 ( V_105 ) ;
F_33 ( V_6 << 24 ) ;
#if F_30
F_33 ( V_106 ) ;
#endif
F_33 ( V_118 ) ;
F_33 ( V_4 -> V_112 . V_113 ) ;
F_3 ( V_4 , 3 , V_6 ) ;
F_32 ( V_4 , V_111 , V_4 -> V_112 . V_113 ) ;
if ( ! ( V_1 = F_35 ( sizeof( struct V_26 ) , V_119 ) ) )
return - V_120 ;
F_2 ( 2 , L_1 , V_1 ) ;
V_69 = F_36 ( V_1 , V_4 , V_68 , V_121 , V_122 ) ;
if ( V_69 ) {
F_37 ( V_1 ) ;
return V_69 ;
}
F_32 ( V_4 , V_123 , V_1 -> V_124 | V_125 ) ;
F_32 ( V_4 , V_72 , ( V_114 | V_98 ) ) ;
V_4 -> V_126 = V_1 ;
V_1 -> V_66 . V_18 = V_1 ;
F_23 ( V_1 ) ;
F_38 ( V_1 ) ;
return 0 ;
}
static int F_39 ( struct V_3 * V_4 )
{
struct V_26 * V_1 = (struct V_26 * ) V_4 -> V_126 ;
int V_69 ;
if ( V_1 -> V_14 ) {
F_40 ( V_1 -> V_14 ) ;
F_27 ( V_1 -> V_14 ) ;
}
V_69 = F_41 ( V_1 ) ;
F_37 ( V_1 ) ;
return V_69 ;
}
static int T_5 F_42 ( void )
{
return F_43 ( & V_127 ) ;
}
static void T_6 F_44 ( void )
{
F_45 ( & V_127 ) ;
}

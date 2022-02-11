static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_2 V_4 = 0 ;
T_3 V_5 ;
V_2 -> V_6 . V_7 ++ ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
V_3 = F_3 ( V_2 ) ;
if ( V_3 & 3 )
return F_2 ( V_2 , V_14 ) ;
if ( F_4 ( V_2 , V_4 , ( T_2 V_15 * ) V_3 ) )
return F_2 ( V_2 , V_16 ) ;
V_4 = V_4 & 0x7fffe000u ;
if ( F_5 ( V_2 , & V_5 , V_4 , 1 ) ||
( F_5 ( V_2 , & V_5 , V_4 + V_17 , 1 ) ) )
return F_2 ( V_2 , V_16 ) ;
F_6 ( V_2 , V_4 ) ;
F_7 ( V_2 , 5 , L_1 , V_4 ) ;
F_8 ( V_2 , 1 , V_4 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_2 V_4 ;
V_2 -> V_6 . V_18 ++ ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
V_3 = F_3 ( V_2 ) ;
if ( V_3 & 3 )
return F_2 ( V_2 , V_14 ) ;
V_4 = V_2 -> V_8 . V_9 -> V_19 ;
V_4 = V_4 & 0x7fffe000u ;
if ( F_10 ( V_2 , V_4 , ( T_2 V_15 * ) V_3 ) )
return F_2 ( V_2 , V_16 ) ;
F_7 ( V_2 , 5 , L_2 , V_4 ) ;
F_8 ( V_2 , 0 , V_4 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
T_1 V_20 ;
V_2 -> V_6 . V_21 ++ ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
V_20 = F_3 ( V_2 ) ;
if ( V_20 & 1 )
return F_2 ( V_2 , V_14 ) ;
if ( F_10 ( V_2 , V_2 -> V_22 , ( V_23 V_15 * ) V_20 ) )
return F_2 ( V_2 , V_16 ) ;
F_7 ( V_2 , 5 , L_3 , V_20 ) ;
F_12 ( V_2 , V_20 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
V_2 -> V_6 . V_24 ++ ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
V_2 -> V_8 . V_9 -> V_10 . V_25 =
F_14 ( V_2 -> V_8 . V_9 -> V_10 , 4 ) ;
F_7 ( V_2 , 4 , L_4 , L_5 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_26 * V_27 ;
T_1 V_25 ;
int V_28 ;
V_25 = F_3 ( V_2 ) ;
if ( V_25 & 3 )
return F_2 ( V_2 , V_14 ) ;
V_28 = 0 ;
V_27 = F_16 ( V_2 -> V_29 , V_2 -> V_30 -> V_31 . V_32 . V_33 [ 6 ] , 0 ) ;
if ( ! V_27 )
goto V_34;
V_28 = 1 ;
if ( V_25 ) {
if ( F_10 ( V_2 , V_27 -> V_35 . V_36 , ( V_23 V_15 * ) V_25 )
|| F_10 ( V_2 , V_27 -> V_35 . V_37 , ( V_23 V_15 * ) ( V_25 + 2 ) )
|| F_10 ( V_2 , V_27 -> V_35 . V_38 , ( T_2 V_15 * ) ( V_25 + 4 ) ) )
return F_2 ( V_2 , V_16 ) ;
} else {
F_10 ( V_2 , V_27 -> V_35 . V_36 , ( V_23 V_15 * ) V_39 ) ;
F_10 ( V_2 , V_27 -> V_35 . V_37 , ( V_23 V_15 * ) V_40 ) ;
F_10 ( V_2 , V_27 -> V_35 . V_38 , ( T_2 V_15 * ) V_41 ) ;
F_10 ( V_2 , V_27 -> V_35 . V_42 , ( T_2 V_15 * ) V_43 ) ;
}
F_17 ( V_27 ) ;
V_34:
V_2 -> V_8 . V_9 -> V_10 . V_11 &= ~ ( 3ul << 44 ) ;
V_2 -> V_8 . V_9 -> V_10 . V_11 |= ( V_28 & 3ul ) << 44 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_26 * V_27 ;
V_27 = F_16 ( V_2 -> V_29 , 0 ,
V_2 -> V_30 -> V_31 . V_32 . V_44 [ 1 ] ) ;
V_2 -> V_30 -> V_45 = V_46 ;
V_2 -> V_30 -> V_47 . V_48 = ! ! V_27 ;
if ( V_27 ) {
V_2 -> V_30 -> V_47 . V_36 = V_27 -> V_35 . V_36 ;
V_2 -> V_30 -> V_47 . V_37 = V_27 -> V_35 . V_37 ;
V_2 -> V_30 -> V_47 . V_38 = V_27 -> V_35 . V_38 ;
V_2 -> V_30 -> V_47 . V_42 = V_27 -> V_35 . V_42 ;
}
V_2 -> V_30 -> V_47 . V_49 = V_2 -> V_8 . V_9 -> V_49 ;
F_17 ( V_27 ) ;
return - V_50 ;
}
static int F_19 ( struct V_1 * V_2 )
{
F_7 ( V_2 , 4 , L_4 , L_6 ) ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
if ( V_2 -> V_29 -> V_8 . V_51 ) {
if ( V_2 -> V_8 . V_9 -> V_52 == 0xb236 )
return F_15 ( V_2 ) ;
if ( V_2 -> V_8 . V_9 -> V_52 == 0xb235 )
return F_18 ( V_2 ) ;
return - V_53 ;
} else {
V_2 -> V_8 . V_9 -> V_10 . V_11 &= ~ ( 3ul << 44 ) ;
V_2 -> V_8 . V_9 -> V_10 . V_11 |= ( 3 & 3ul ) << 44 ;
return 0 ;
}
}
static int F_20 ( struct V_1 * V_2 )
{
unsigned int V_54 ;
int V_55 ;
V_2 -> V_6 . V_56 ++ ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
V_54 = V_57 . V_58 & 0xff82fff3 ;
V_55 = F_21 ( V_2 , F_22 ( struct V_59 , V_58 ) ,
& V_54 , sizeof( V_54 ) ) ;
if ( V_55 )
return F_2 ( V_2 , V_16 ) ;
F_7 ( V_2 , 5 , L_7 , V_54 ) ;
F_23 ( V_2 , V_54 ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_60 )
F_25 ( V_2 ) ;
}
static int F_26 ( T_4 * V_61 ) {
if ( V_61 -> V_11 & V_62 )
return 0 ;
if ( ( V_61 -> V_11 & V_63 ) == V_64 ) {
if ( V_61 -> V_25 & ~ V_65 )
return 0 ;
}
if ( ! ( V_61 -> V_11 & V_63 ) && ( V_61 -> V_25 & ~ V_66 ) )
return 0 ;
if ( ( V_61 -> V_11 & V_63 ) == V_67 )
return 0 ;
return 1 ;
}
int F_27 ( struct V_1 * V_2 )
{
T_4 * V_10 = & V_2 -> V_8 . V_9 -> V_10 ;
T_5 V_68 ;
T_1 V_25 ;
if ( V_10 -> V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
V_25 = F_3 ( V_2 ) ;
if ( V_25 & 7 )
return F_2 ( V_2 , V_14 ) ;
if ( F_28 ( V_2 , & V_68 , V_25 , sizeof( V_68 ) ) )
return F_2 ( V_2 , V_16 ) ;
if ( ! ( V_68 . V_11 & V_69 ) )
return F_2 ( V_2 , V_14 ) ;
V_10 -> V_11 = ( V_68 . V_11 & ~ V_69 ) << 32 ;
V_10 -> V_11 |= V_68 . V_25 & V_70 ;
V_10 -> V_25 = V_68 . V_25 & ~ V_70 ;
if ( ! F_26 ( V_10 ) )
return F_2 ( V_2 , V_14 ) ;
F_24 ( V_2 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
T_4 V_68 ;
T_1 V_25 ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
V_25 = F_3 ( V_2 ) ;
if ( V_25 & 7 )
return F_2 ( V_2 , V_14 ) ;
if ( F_28 ( V_2 , & V_68 , V_25 , sizeof( V_68 ) ) )
return F_2 ( V_2 , V_16 ) ;
V_2 -> V_8 . V_9 -> V_10 = V_68 ;
if ( ! F_26 ( & V_2 -> V_8 . V_9 -> V_10 ) )
return F_2 ( V_2 , V_14 ) ;
F_24 ( V_2 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_2 -> V_6 . V_71 ++ ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
V_3 = F_3 ( V_2 ) ;
if ( V_3 & 7 )
return F_2 ( V_2 , V_14 ) ;
if ( F_10 ( V_2 , V_2 -> V_8 . V_72 , ( T_1 V_15 * ) V_3 ) )
return F_2 ( V_2 , V_16 ) ;
F_7 ( V_2 , 5 , L_4 , L_8 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 , struct V_73 * V_74 )
{
struct V_75 * V_76 = & V_2 -> V_29 -> V_8 . V_77 ;
int V_78 = 0 ;
int V_79 ;
F_32 ( & V_76 -> V_80 ) ;
for ( V_79 = 0 ; V_79 < V_81 ; V_79 ++ )
if ( V_76 -> V_82 [ V_79 ] )
V_78 ++ ;
F_33 ( & V_76 -> V_80 ) ;
if ( F_34 ( V_74 , 3 , 2 , 2 ) )
V_74 -> V_83 = 0 ;
if ( V_74 -> V_83 < 8 )
V_74 -> V_83 ++ ;
for ( V_79 = V_74 -> V_83 - 1 ; V_79 > 0 ; V_79 -- )
memcpy ( & V_74 -> V_84 [ V_79 ] , & V_74 -> V_84 [ V_79 - 1 ] , sizeof( V_74 -> V_84 [ 0 ] ) ) ;
V_74 -> V_84 [ 0 ] . V_85 = V_78 ;
V_74 -> V_84 [ 0 ] . V_86 = V_78 ;
V_74 -> V_84 [ 0 ] . V_87 = 0 ;
V_74 -> V_84 [ 0 ] . V_88 = 0 ;
V_74 -> V_84 [ 0 ] . V_89 = 1000 ;
memcpy ( V_74 -> V_84 [ 0 ] . V_90 , L_9 , 8 ) ;
F_35 ( V_74 -> V_84 [ 0 ] . V_90 , 8 ) ;
memcpy ( V_74 -> V_84 [ 0 ] . V_91 , L_10 , 16 ) ;
F_35 ( V_74 -> V_84 [ 0 ] . V_91 , 16 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_92 = ( V_2 -> V_30 -> V_31 . V_32 . V_44 [ 0 ] & 0xf0000000 ) >> 28 ;
int V_93 = V_2 -> V_30 -> V_31 . V_32 . V_44 [ 0 ] & 0xff ;
int V_94 = V_2 -> V_30 -> V_31 . V_32 . V_44 [ 1 ] & 0xffff ;
unsigned long V_74 = 0 ;
T_1 V_3 ;
int V_55 = 0 ;
V_2 -> V_6 . V_95 ++ ;
F_7 ( V_2 , 4 , L_11 , V_92 , V_93 , V_94 ) ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
if ( V_92 > 3 ) {
V_2 -> V_8 . V_9 -> V_10 . V_11 |= 3ul << 44 ;
return 0 ;
}
if ( V_2 -> V_30 -> V_31 . V_32 . V_44 [ 0 ] & 0x0fffff00
|| V_2 -> V_30 -> V_31 . V_32 . V_44 [ 1 ] & 0xffff0000 )
return F_2 ( V_2 , V_14 ) ;
if ( V_92 == 0 ) {
V_2 -> V_30 -> V_31 . V_32 . V_44 [ 0 ] = 3 << 28 ;
V_2 -> V_8 . V_9 -> V_10 . V_11 &= ~ ( 3ul << 44 ) ;
return 0 ;
}
V_3 = F_3 ( V_2 ) ;
if ( V_3 & 0xfff )
return F_2 ( V_2 , V_14 ) ;
switch ( V_92 ) {
case 1 :
case 2 :
V_74 = F_37 ( V_96 ) ;
if ( ! V_74 )
goto V_97;
if ( F_34 ( ( void * ) V_74 , V_92 , V_93 , V_94 ) )
goto V_97;
break;
case 3 :
if ( V_93 != 2 || V_94 != 2 )
goto V_97;
V_74 = F_37 ( V_96 ) ;
if ( ! V_74 )
goto V_97;
F_31 ( V_2 , ( void * ) V_74 ) ;
break;
}
if ( F_38 ( V_2 , V_3 , ( void * ) V_74 , V_17 ) ) {
V_55 = F_2 ( V_2 , V_16 ) ;
goto V_98;
}
F_39 ( V_2 , V_92 , V_93 , V_94 , V_3 ) ;
F_40 ( V_74 ) ;
V_2 -> V_8 . V_9 -> V_10 . V_11 &= ~ ( 3ul << 44 ) ;
V_2 -> V_30 -> V_31 . V_32 . V_44 [ 0 ] = 0 ;
return 0 ;
V_97:
V_2 -> V_8 . V_9 -> V_10 . V_11 |= 3ul << 44 ;
V_98:
F_40 ( V_74 ) ;
return V_55 ;
}
int F_41 ( struct V_1 * V_2 )
{
T_6 V_99 ;
V_99 = V_100 [ V_2 -> V_8 . V_9 -> V_52 & 0x00ff ] ;
if ( V_99 )
return V_99 ( V_2 ) ;
return - V_53 ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_101 , V_102 ;
F_43 ( V_2 , & V_101 , & V_102 ) ;
V_2 -> V_30 -> V_31 . V_32 . V_44 [ V_101 ] &= 0xffffffff00000000 ;
V_2 -> V_30 -> V_31 . V_32 . V_44 [ V_101 ] |= V_2 -> V_8 . V_9 -> V_10 . V_11 >> 32 ;
if ( V_102 ) {
V_2 -> V_30 -> V_31 . V_32 . V_44 [ V_102 ] &= 0xffffffff00000000 ;
V_2 -> V_30 -> V_31 . V_32 . V_44 [ V_102 ] |=
V_2 -> V_8 . V_9 -> V_10 . V_11 & 0x00000000ffffffff ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
int V_101 , V_102 ;
unsigned long V_103 , V_104 ;
V_2 -> V_6 . V_105 ++ ;
F_43 ( V_2 , & V_101 , & V_102 ) ;
if ( ! V_106 )
return F_2 ( V_2 , V_107 ) ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
if ( V_2 -> V_30 -> V_31 . V_32 . V_44 [ V_101 ] & V_108 )
return F_2 ( V_2 , V_14 ) ;
if ( V_2 -> V_30 -> V_31 . V_32 . V_44 [ V_101 ] & V_109 && ! F_45 ( 14 ) )
return F_2 ( V_2 , V_14 ) ;
if ( V_2 -> V_30 -> V_31 . V_32 . V_44 [ V_101 ] & ( V_110 | V_111 ) )
return F_2 ( V_2 , V_14 ) ;
V_103 = V_2 -> V_30 -> V_31 . V_32 . V_44 [ V_102 ] & V_112 ;
switch ( V_2 -> V_30 -> V_31 . V_32 . V_44 [ V_101 ] & V_113 ) {
case 0x00000000 :
V_104 = ( V_103 + ( 1UL << 12 ) ) & ~ ( ( 1UL << 12 ) - 1 ) ;
break;
case 0x00001000 :
V_104 = ( V_103 + ( 1UL << 20 ) ) & ~ ( ( 1UL << 20 ) - 1 ) ;
break;
default:
return F_2 ( V_2 , V_14 ) ;
}
while ( V_103 < V_104 ) {
unsigned long V_20 ;
V_20 = F_46 ( V_103 , V_2 -> V_8 . V_114 ) ;
if ( F_47 ( ( void * ) V_20 ) )
return F_2 ( V_2 , V_16 ) ;
if ( V_2 -> V_30 -> V_31 . V_32 . V_44 [ V_101 ] & V_115 ) {
if ( F_48 ( ( void V_15 * ) V_20 , V_17 ) )
return F_2 ( V_2 , V_16 ) ;
}
if ( V_2 -> V_30 -> V_31 . V_32 . V_44 [ V_101 ] & V_116 ) {
if ( F_49 ( V_117 -> V_118 , V_20 ,
V_2 -> V_30 -> V_31 . V_32 . V_44 [ V_101 ] & V_119 ,
V_2 -> V_30 -> V_31 . V_32 . V_44 [ V_101 ] & V_109 ) )
return F_2 ( V_2 , V_16 ) ;
}
V_103 += V_17 ;
}
if ( V_2 -> V_30 -> V_31 . V_32 . V_44 [ V_101 ] & V_113 )
V_2 -> V_30 -> V_31 . V_32 . V_44 [ V_102 ] = V_104 ;
return 0 ;
}
int F_50 ( struct V_1 * V_2 )
{
T_6 V_99 ;
V_99 = V_120 [ V_2 -> V_8 . V_9 -> V_52 & 0x00ff ] ;
if ( V_99 )
return V_99 ( V_2 ) ;
return - V_53 ;
}
int F_51 ( struct V_1 * V_2 )
{
int V_101 = ( V_2 -> V_8 . V_9 -> V_52 & 0x00f0 ) >> 4 ;
int V_121 = V_2 -> V_8 . V_9 -> V_52 & 0x000f ;
T_1 V_20 ;
T_2 V_122 = 0 ;
int V_123 , V_55 ;
V_2 -> V_6 . V_124 ++ ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
V_20 = F_52 ( V_2 ) ;
if ( V_20 & 3 )
return F_2 ( V_2 , V_14 ) ;
F_7 ( V_2 , 5 , L_12 , V_101 , V_121 ,
V_20 ) ;
F_53 ( V_2 , 0 , V_101 , V_121 , V_20 ) ;
V_123 = V_101 ;
do {
V_55 = F_4 ( V_2 , V_122 , ( T_2 V_15 * ) V_20 ) ;
if ( V_55 )
return F_2 ( V_2 , V_16 ) ;
V_2 -> V_8 . V_9 -> V_125 [ V_123 ] &= 0xffffffff00000000ul ;
V_2 -> V_8 . V_9 -> V_125 [ V_123 ] |= V_122 ;
V_20 += 4 ;
if ( V_123 == V_121 )
break;
V_123 = ( V_123 + 1 ) % 16 ;
} while ( 1 );
return 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
int V_101 = ( V_2 -> V_8 . V_9 -> V_52 & 0x00f0 ) >> 4 ;
int V_121 = V_2 -> V_8 . V_9 -> V_52 & 0x000f ;
T_1 V_20 ;
int V_123 , V_55 ;
V_2 -> V_6 . V_126 ++ ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
V_20 = F_55 ( V_2 ) ;
if ( V_20 & 7 )
return F_2 ( V_2 , V_14 ) ;
V_123 = V_101 ;
F_7 ( V_2 , 5 , L_13 , V_101 , V_121 ,
V_20 ) ;
F_53 ( V_2 , 1 , V_101 , V_121 , V_20 ) ;
do {
V_55 = F_4 ( V_2 , V_2 -> V_8 . V_9 -> V_125 [ V_123 ] ,
( T_1 V_15 * ) V_20 ) ;
if ( V_55 )
return F_2 ( V_2 , V_16 ) ;
V_20 += 8 ;
if ( V_123 == V_121 )
break;
V_123 = ( V_123 + 1 ) % 16 ;
} while ( 1 );
return 0 ;
}
int F_56 ( struct V_1 * V_2 )
{
T_6 V_99 ;
V_99 = V_127 [ V_2 -> V_8 . V_9 -> V_49 & 0xff ] ;
if ( V_99 )
return V_99 ( V_2 ) ;
return - V_53 ;
}
static int F_57 ( struct V_1 * V_2 )
{
T_1 V_128 , V_129 ;
struct V_130 * V_131 ;
unsigned long V_132 ;
V_2 -> V_6 . V_133 ++ ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
F_58 ( V_2 , & V_128 , & V_129 ) ;
if ( V_129 & 0xf0 )
return - V_53 ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_134 )
return - V_53 ;
F_59 ( & V_117 -> V_118 -> V_135 ) ;
V_132 = F_60 ( V_128 , V_2 -> V_8 . V_114 ) ;
if ( F_61 ( V_132 ) )
goto V_136;
V_131 = F_62 ( V_117 -> V_118 , V_132 ) ;
if ( ! V_131 )
goto V_136;
V_2 -> V_8 . V_9 -> V_10 . V_11 &= ~ ( 3ul << 44 ) ;
if ( ! ( V_131 -> V_137 & V_138 ) && ( V_131 -> V_137 & V_139 ) )
V_2 -> V_8 . V_9 -> V_10 . V_11 |= ( 1ul << 44 ) ;
if ( ! ( V_131 -> V_137 & V_138 ) && ! ( V_131 -> V_137 & V_139 ) )
V_2 -> V_8 . V_9 -> V_10 . V_11 |= ( 2ul << 44 ) ;
F_63 ( & V_117 -> V_118 -> V_135 ) ;
return 0 ;
V_136:
F_63 ( & V_117 -> V_118 -> V_135 ) ;
return F_2 ( V_2 , V_16 ) ;
}
int F_64 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_8 . V_9 -> V_52 & 0x00ff ) == 0x01 )
return F_57 ( V_2 ) ;
return - V_53 ;
}
static int F_65 ( struct V_1 * V_2 )
{
T_2 V_140 ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
if ( V_2 -> V_30 -> V_31 . V_32 . V_44 [ 0 ] & 0x00000000ffff0000 )
return F_2 ( V_2 ,
V_14 ) ;
V_140 = V_2 -> V_30 -> V_31 . V_32 . V_44 [ 0 ] & 0x000000000000ffff ;
V_2 -> V_8 . V_9 -> V_141 = V_140 ;
return 0 ;
}
int F_66 ( struct V_1 * V_2 )
{
T_6 V_99 ;
V_99 = V_142 [ V_2 -> V_8 . V_9 -> V_52 & 0x00ff ] ;
if ( V_99 )
return V_99 ( V_2 ) ;
return - V_53 ;
}

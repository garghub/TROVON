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
F_18 ( V_2 , V_28 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
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
static int F_20 ( struct V_1 * V_2 )
{
F_7 ( V_2 , 4 , L_4 , L_6 ) ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
if ( V_2 -> V_29 -> V_8 . V_51 ) {
if ( V_2 -> V_8 . V_9 -> V_52 == 0xb236 )
return F_15 ( V_2 ) ;
if ( V_2 -> V_8 . V_9 -> V_52 == 0xb235 )
return F_19 ( V_2 ) ;
return - V_53 ;
} else {
F_18 ( V_2 , 3 ) ;
return 0 ;
}
}
static int F_21 ( struct V_1 * V_2 )
{
int V_54 ;
V_2 -> V_6 . V_55 ++ ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
V_54 = F_22 ( V_2 , F_23 ( struct V_56 , V_57 ) ,
V_58 , 4 ) ;
if ( V_54 )
return F_2 ( V_2 , V_16 ) ;
F_7 ( V_2 , 5 , L_7 ,
* ( unsigned int * ) V_58 ) ;
F_24 ( V_2 , * ( unsigned int * ) V_58 ) ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_59 )
F_26 ( V_2 ) ;
}
static int F_27 ( T_4 * V_60 ) {
if ( V_60 -> V_11 & V_61 )
return 0 ;
if ( ( V_60 -> V_11 & V_62 ) == V_63 ) {
if ( V_60 -> V_25 & ~ V_64 )
return 0 ;
}
if ( ! ( V_60 -> V_11 & V_62 ) && ( V_60 -> V_25 & ~ V_65 ) )
return 0 ;
if ( ( V_60 -> V_11 & V_62 ) == V_66 )
return 0 ;
return 1 ;
}
int F_28 ( struct V_1 * V_2 )
{
T_4 * V_10 = & V_2 -> V_8 . V_9 -> V_10 ;
T_5 V_67 ;
T_1 V_25 ;
if ( V_10 -> V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
V_25 = F_3 ( V_2 ) ;
if ( V_25 & 7 )
return F_2 ( V_2 , V_14 ) ;
if ( F_29 ( V_2 , & V_67 , V_25 , sizeof( V_67 ) ) )
return F_2 ( V_2 , V_16 ) ;
if ( ! ( V_67 . V_11 & V_68 ) )
return F_2 ( V_2 , V_14 ) ;
V_10 -> V_11 = ( V_67 . V_11 & ~ V_68 ) << 32 ;
V_10 -> V_11 |= V_67 . V_25 & V_69 ;
V_10 -> V_25 = V_67 . V_25 & ~ V_69 ;
if ( ! F_27 ( V_10 ) )
return F_2 ( V_2 , V_14 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
T_4 V_67 ;
T_1 V_25 ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
V_25 = F_3 ( V_2 ) ;
if ( V_25 & 7 )
return F_2 ( V_2 , V_14 ) ;
if ( F_29 ( V_2 , & V_67 , V_25 , sizeof( V_67 ) ) )
return F_2 ( V_2 , V_16 ) ;
V_2 -> V_8 . V_9 -> V_10 = V_67 ;
if ( ! F_27 ( & V_2 -> V_8 . V_9 -> V_10 ) )
return F_2 ( V_2 , V_14 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_2 -> V_6 . V_70 ++ ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
V_3 = F_3 ( V_2 ) ;
if ( V_3 & 7 )
return F_2 ( V_2 , V_14 ) ;
if ( F_10 ( V_2 , V_2 -> V_8 . V_71 , ( T_1 V_15 * ) V_3 ) )
return F_2 ( V_2 , V_16 ) ;
F_7 ( V_2 , 5 , L_4 , L_8 ) ;
return 0 ;
}
static void F_32 ( struct V_1 * V_2 , struct V_72 * V_73 )
{
struct V_74 * V_75 = & V_2 -> V_29 -> V_8 . V_76 ;
int V_77 = 0 ;
int V_78 ;
F_33 ( & V_75 -> V_79 ) ;
for ( V_78 = 0 ; V_78 < V_80 ; V_78 ++ )
if ( V_75 -> V_81 [ V_78 ] )
V_77 ++ ;
F_34 ( & V_75 -> V_79 ) ;
if ( F_35 ( V_73 , 3 , 2 , 2 ) )
V_73 -> V_82 = 0 ;
if ( V_73 -> V_82 < 8 )
V_73 -> V_82 ++ ;
for ( V_78 = V_73 -> V_82 - 1 ; V_78 > 0 ; V_78 -- )
memcpy ( & V_73 -> V_83 [ V_78 ] , & V_73 -> V_83 [ V_78 - 1 ] , sizeof( V_73 -> V_83 [ 0 ] ) ) ;
V_73 -> V_83 [ 0 ] . V_84 = V_77 ;
V_73 -> V_83 [ 0 ] . V_85 = V_77 ;
V_73 -> V_83 [ 0 ] . V_86 = 0 ;
V_73 -> V_83 [ 0 ] . V_87 = 0 ;
V_73 -> V_83 [ 0 ] . V_88 = 1000 ;
memcpy ( V_73 -> V_83 [ 0 ] . V_89 , L_9 , 8 ) ;
F_36 ( V_73 -> V_83 [ 0 ] . V_89 , 8 ) ;
memcpy ( V_73 -> V_83 [ 0 ] . V_90 , L_10 , 16 ) ;
F_36 ( V_73 -> V_83 [ 0 ] . V_90 , 16 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_91 = ( V_2 -> V_30 -> V_31 . V_32 . V_44 [ 0 ] & 0xf0000000 ) >> 28 ;
int V_92 = V_2 -> V_30 -> V_31 . V_32 . V_44 [ 0 ] & 0xff ;
int V_93 = V_2 -> V_30 -> V_31 . V_32 . V_44 [ 1 ] & 0xffff ;
unsigned long V_73 = 0 ;
T_1 V_3 ;
int V_54 = 0 ;
V_2 -> V_6 . V_94 ++ ;
F_7 ( V_2 , 4 , L_11 , V_91 , V_92 , V_93 ) ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
if ( V_91 > 3 ) {
F_18 ( V_2 , 3 ) ;
return 0 ;
}
if ( V_2 -> V_30 -> V_31 . V_32 . V_44 [ 0 ] & 0x0fffff00
|| V_2 -> V_30 -> V_31 . V_32 . V_44 [ 1 ] & 0xffff0000 )
return F_2 ( V_2 , V_14 ) ;
if ( V_91 == 0 ) {
V_2 -> V_30 -> V_31 . V_32 . V_44 [ 0 ] = 3 << 28 ;
F_18 ( V_2 , 0 ) ;
return 0 ;
}
V_3 = F_3 ( V_2 ) ;
if ( V_3 & 0xfff )
return F_2 ( V_2 , V_14 ) ;
switch ( V_91 ) {
case 1 :
case 2 :
V_73 = F_38 ( V_95 ) ;
if ( ! V_73 )
goto V_96;
if ( F_35 ( ( void * ) V_73 , V_91 , V_92 , V_93 ) )
goto V_96;
break;
case 3 :
if ( V_92 != 2 || V_93 != 2 )
goto V_96;
V_73 = F_38 ( V_95 ) ;
if ( ! V_73 )
goto V_96;
F_32 ( V_2 , ( void * ) V_73 ) ;
break;
}
if ( F_39 ( V_2 , V_3 , ( void * ) V_73 , V_17 ) ) {
V_54 = F_2 ( V_2 , V_16 ) ;
goto V_97;
}
F_40 ( V_2 , V_91 , V_92 , V_93 , V_3 ) ;
F_41 ( V_73 ) ;
F_18 ( V_2 , 0 ) ;
V_2 -> V_30 -> V_31 . V_32 . V_44 [ 0 ] = 0 ;
return 0 ;
V_96:
F_18 ( V_2 , 3 ) ;
V_97:
F_41 ( V_73 ) ;
return V_54 ;
}
int F_42 ( struct V_1 * V_2 )
{
T_6 V_98 ;
V_98 = V_99 [ V_2 -> V_8 . V_9 -> V_52 & 0x00ff ] ;
if ( V_98 )
return V_98 ( V_2 ) ;
return - V_53 ;
}
static int F_43 ( struct V_1 * V_2 )
{
int V_100 , V_101 ;
F_44 ( V_2 , & V_100 , & V_101 ) ;
V_2 -> V_30 -> V_31 . V_32 . V_44 [ V_100 ] &= 0xffffffff00000000UL ;
V_2 -> V_30 -> V_31 . V_32 . V_44 [ V_100 ] |= V_2 -> V_8 . V_9 -> V_10 . V_11 >> 32 ;
if ( V_101 ) {
V_2 -> V_30 -> V_31 . V_32 . V_44 [ V_101 ] &= 0xffffffff00000000UL ;
V_2 -> V_30 -> V_31 . V_32 . V_44 [ V_101 ] |=
V_2 -> V_8 . V_9 -> V_10 . V_11 & 0x00000000ffffffffUL ;
}
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
int V_100 , V_101 ;
unsigned long V_102 , V_103 ;
V_2 -> V_6 . V_104 ++ ;
F_44 ( V_2 , & V_100 , & V_101 ) ;
if ( ! V_105 )
return F_2 ( V_2 , V_106 ) ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
if ( V_2 -> V_30 -> V_31 . V_32 . V_44 [ V_100 ] & V_107 )
return F_2 ( V_2 , V_14 ) ;
if ( V_2 -> V_30 -> V_31 . V_32 . V_44 [ V_100 ] & V_108 && ! F_46 ( 14 ) )
return F_2 ( V_2 , V_14 ) ;
if ( V_2 -> V_30 -> V_31 . V_32 . V_44 [ V_100 ] & ( V_109 | V_110 ) )
return F_2 ( V_2 , V_14 ) ;
V_102 = V_2 -> V_30 -> V_31 . V_32 . V_44 [ V_101 ] & V_111 ;
switch ( V_2 -> V_30 -> V_31 . V_32 . V_44 [ V_100 ] & V_112 ) {
case 0x00000000 :
V_103 = ( V_102 + ( 1UL << 12 ) ) & ~ ( ( 1UL << 12 ) - 1 ) ;
break;
case 0x00001000 :
V_103 = ( V_102 + ( 1UL << 20 ) ) & ~ ( ( 1UL << 20 ) - 1 ) ;
break;
default:
return F_2 ( V_2 , V_14 ) ;
}
while ( V_102 < V_103 ) {
unsigned long V_20 ;
V_20 = F_47 ( V_102 , V_2 -> V_8 . V_113 ) ;
if ( F_48 ( ( void * ) V_20 ) )
return F_2 ( V_2 , V_16 ) ;
if ( V_2 -> V_30 -> V_31 . V_32 . V_44 [ V_100 ] & V_114 ) {
if ( F_49 ( ( void V_15 * ) V_20 , V_17 ) )
return F_2 ( V_2 , V_16 ) ;
}
if ( V_2 -> V_30 -> V_31 . V_32 . V_44 [ V_100 ] & V_115 ) {
if ( F_50 ( V_116 -> V_117 , V_20 ,
V_2 -> V_30 -> V_31 . V_32 . V_44 [ V_100 ] & V_118 ,
V_2 -> V_30 -> V_31 . V_32 . V_44 [ V_100 ] & V_108 ) )
return F_2 ( V_2 , V_16 ) ;
}
V_102 += V_17 ;
}
if ( V_2 -> V_30 -> V_31 . V_32 . V_44 [ V_100 ] & V_112 )
V_2 -> V_30 -> V_31 . V_32 . V_44 [ V_101 ] = V_103 ;
return 0 ;
}
int F_51 ( struct V_1 * V_2 )
{
T_6 V_98 ;
V_98 = V_119 [ V_2 -> V_8 . V_9 -> V_52 & 0x00ff ] ;
if ( V_98 )
return V_98 ( V_2 ) ;
return - V_53 ;
}
int F_52 ( struct V_1 * V_2 )
{
int V_100 = ( V_2 -> V_8 . V_9 -> V_52 & 0x00f0 ) >> 4 ;
int V_120 = V_2 -> V_8 . V_9 -> V_52 & 0x000f ;
T_1 V_20 ;
T_2 V_121 = 0 ;
int V_122 , V_54 ;
V_2 -> V_6 . V_123 ++ ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
V_20 = F_53 ( V_2 ) ;
if ( V_20 & 3 )
return F_2 ( V_2 , V_14 ) ;
F_7 ( V_2 , 5 , L_12 , V_100 , V_120 ,
V_20 ) ;
F_54 ( V_2 , 0 , V_100 , V_120 , V_20 ) ;
V_122 = V_100 ;
do {
V_54 = F_4 ( V_2 , V_121 , ( T_2 V_15 * ) V_20 ) ;
if ( V_54 )
return F_2 ( V_2 , V_16 ) ;
V_2 -> V_8 . V_9 -> V_124 [ V_122 ] &= 0xffffffff00000000ul ;
V_2 -> V_8 . V_9 -> V_124 [ V_122 ] |= V_121 ;
V_20 += 4 ;
if ( V_122 == V_120 )
break;
V_122 = ( V_122 + 1 ) % 16 ;
} while ( 1 );
return 0 ;
}
static int F_55 ( struct V_1 * V_2 )
{
int V_100 = ( V_2 -> V_8 . V_9 -> V_52 & 0x00f0 ) >> 4 ;
int V_120 = V_2 -> V_8 . V_9 -> V_52 & 0x000f ;
T_1 V_20 ;
int V_122 , V_54 ;
V_2 -> V_6 . V_125 ++ ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
V_20 = F_56 ( V_2 ) ;
if ( V_20 & 7 )
return F_2 ( V_2 , V_14 ) ;
V_122 = V_100 ;
F_7 ( V_2 , 5 , L_13 , V_100 , V_120 ,
V_20 ) ;
F_54 ( V_2 , 1 , V_100 , V_120 , V_20 ) ;
do {
V_54 = F_4 ( V_2 , V_2 -> V_8 . V_9 -> V_124 [ V_122 ] ,
( T_1 V_15 * ) V_20 ) ;
if ( V_54 )
return F_2 ( V_2 , V_16 ) ;
V_20 += 8 ;
if ( V_122 == V_120 )
break;
V_122 = ( V_122 + 1 ) % 16 ;
} while ( 1 );
return 0 ;
}
int F_57 ( struct V_1 * V_2 )
{
T_6 V_98 ;
V_98 = V_126 [ V_2 -> V_8 . V_9 -> V_49 & 0xff ] ;
if ( V_98 )
return V_98 ( V_2 ) ;
return - V_53 ;
}
static int F_58 ( struct V_1 * V_2 )
{
T_1 V_127 , V_128 ;
struct V_129 * V_130 ;
unsigned long V_131 ;
V_2 -> V_6 . V_132 ++ ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
F_59 ( V_2 , & V_127 , & V_128 ) ;
if ( V_128 & 0xf0 )
return - V_53 ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_133 )
return - V_53 ;
F_60 ( & V_116 -> V_117 -> V_134 ) ;
V_131 = F_61 ( V_127 , V_2 -> V_8 . V_113 ) ;
if ( F_62 ( V_131 ) )
goto V_135;
V_130 = F_63 ( V_116 -> V_117 , V_131 ) ;
if ( ! V_130 )
goto V_135;
V_2 -> V_8 . V_9 -> V_10 . V_11 &= ~ ( 3ul << 44 ) ;
if ( ! ( V_130 -> V_136 & V_137 ) && ( V_130 -> V_136 & V_138 ) )
V_2 -> V_8 . V_9 -> V_10 . V_11 |= ( 1ul << 44 ) ;
if ( ! ( V_130 -> V_136 & V_137 ) && ! ( V_130 -> V_136 & V_138 ) )
V_2 -> V_8 . V_9 -> V_10 . V_11 |= ( 2ul << 44 ) ;
F_64 ( & V_116 -> V_117 -> V_134 ) ;
return 0 ;
V_135:
F_64 ( & V_116 -> V_117 -> V_134 ) ;
return F_2 ( V_2 , V_16 ) ;
}
int F_65 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_8 . V_9 -> V_52 & 0x00ff ) == 0x01 )
return F_58 ( V_2 ) ;
return - V_53 ;
}
static int F_66 ( struct V_1 * V_2 )
{
T_2 V_139 ;
if ( V_2 -> V_8 . V_9 -> V_10 . V_11 & V_12 )
return F_2 ( V_2 , V_13 ) ;
if ( V_2 -> V_30 -> V_31 . V_32 . V_44 [ 0 ] & 0x00000000ffff0000 )
return F_2 ( V_2 ,
V_14 ) ;
V_139 = V_2 -> V_30 -> V_31 . V_32 . V_44 [ 0 ] & 0x000000000000ffff ;
V_2 -> V_8 . V_9 -> V_140 = V_139 ;
return 0 ;
}
int F_67 ( struct V_1 * V_2 )
{
T_6 V_98 ;
V_98 = V_141 [ V_2 -> V_8 . V_9 -> V_52 & 0x00ff ] ;
if ( V_98 )
return V_98 ( V_2 ) ;
return - V_53 ;
}

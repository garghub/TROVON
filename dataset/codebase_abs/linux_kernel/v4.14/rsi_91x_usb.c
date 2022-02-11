static int F_1 ( struct V_1 * V_2 ,
T_1 * V_3 ,
T_2 V_4 ,
T_1 V_5 )
{
struct V_6 * V_7 = (struct V_6 * ) V_2 -> V_8 ;
int V_9 ;
T_1 * V_10 = V_7 -> V_11 ;
int V_12 ;
int V_13 = V_7 -> V_14 [ V_5 - 1 ] ;
memset ( V_10 , 0 , V_4 + V_15 ) ;
memcpy ( V_10 + V_15 , V_3 , V_4 ) ;
V_4 += V_15 ;
V_12 = V_4 ;
V_9 = F_2 ( V_7 -> V_16 ,
F_3 ( V_7 -> V_16 , V_13 ) ,
( void * ) V_10 ,
( int ) V_4 ,
& V_12 ,
V_17 * 5 ) ;
if ( V_9 < 0 ) {
F_4 ( V_18 ,
L_1 , V_9 ) ;
V_7 -> V_19 = 1 ;
}
return V_9 ;
}
static int F_5 ( struct V_1 * V_2 ,
T_1 V_5 ,
T_1 * V_20 ,
T_3 V_21 )
{
struct V_6 * V_7 =
(struct V_6 * ) V_2 -> V_8 ;
if ( ! V_2 )
return - V_22 ;
if ( V_5 == 0 )
return - V_23 ;
if ( V_7 -> V_19 )
return - V_24 ;
return F_1 ( V_2 , V_20 , V_21 , V_5 ) ;
}
static int F_6 ( struct V_25 * V_26 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 = (struct V_6 * ) V_2 -> V_8 ;
struct V_27 * V_28 ;
struct V_29 * V_5 ;
T_4 V_30 ;
int V_31 , V_32 = 0 ;
V_28 = & ( V_26 -> V_33 [ 0 ] ) ;
for ( V_31 = 0 ; V_31 < V_28 -> V_34 . V_35 ; ++ V_31 ) {
V_5 = & ( V_28 -> V_5 [ V_31 ] . V_34 ) ;
if ( ( ! ( V_7 -> V_36 ) ) &&
( V_5 -> V_37 & V_38 ) &&
( ( V_5 -> V_39 &
V_40 ) ==
V_41 ) ) {
V_30 = V_5 -> V_42 ;
V_7 -> V_43 = V_30 ;
V_7 -> V_36 =
V_5 -> V_37 ;
}
if ( ! V_7 -> V_14 [ V_32 ] &&
! ( V_5 -> V_37 & V_38 ) &&
( ( V_5 -> V_39 & V_40 ) ==
V_41 ) ) {
V_7 -> V_14 [ V_32 ] =
V_5 -> V_37 ;
V_30 = V_5 -> V_42 ;
V_7 -> V_44 [ V_32 ] = V_30 ;
V_32 ++ ;
}
if ( V_32 >= V_45 )
break;
}
if ( ! ( V_7 -> V_36 ) &&
( V_7 -> V_14 [ 0 ] ) )
return - V_23 ;
return 0 ;
}
static int F_7 ( struct V_46 * V_16 ,
T_3 V_47 ,
T_2 * V_48 ,
T_2 V_4 )
{
T_1 * V_3 ;
int V_9 = - V_49 ;
V_3 = F_8 ( V_50 , V_51 ) ;
if ( ! V_3 )
return V_9 ;
if ( V_4 > V_50 )
return - V_23 ;
V_9 = F_9 ( V_16 ,
F_10 ( V_16 , 0 ) ,
V_52 ,
V_53 ,
( ( V_47 & 0xffff0000 ) >> 16 ) , ( V_47 & 0xffff ) ,
( void * ) V_3 ,
V_4 ,
V_54 ) ;
* V_48 = ( V_3 [ 0 ] | ( V_3 [ 1 ] << 8 ) ) ;
if ( V_9 < 0 ) {
F_4 ( V_18 ,
L_2 ,
V_55 , V_9 ) ;
}
F_11 ( V_3 ) ;
return V_9 ;
}
static int F_12 ( struct V_46 * V_16 ,
T_3 V_47 ,
T_2 V_48 ,
T_2 V_4 )
{
T_1 * V_56 ;
int V_9 = - V_49 ;
V_56 = F_8 ( V_50 , V_51 ) ;
if ( ! V_56 )
return V_9 ;
if ( V_4 > V_50 )
return - V_23 ;
V_56 [ 0 ] = ( V_48 & 0x00ff ) ;
V_56 [ 1 ] = ( V_48 & 0xff00 ) >> 8 ;
V_56 [ 2 ] = 0x0 ;
V_56 [ 3 ] = 0x0 ;
V_9 = F_9 ( V_16 ,
F_13 ( V_16 , 0 ) ,
V_57 ,
V_58 ,
( ( V_47 & 0xffff0000 ) >> 16 ) ,
( V_47 & 0xffff ) ,
( void * ) V_56 ,
V_4 ,
V_59 ) ;
if ( V_9 < 0 ) {
F_4 ( V_18 ,
L_3 ,
V_55 , V_9 ) ;
}
F_11 ( V_56 ) ;
return V_9 ;
}
static void F_14 ( struct V_60 * V_60 )
{
struct V_1 * V_2 = V_60 -> V_61 ;
struct V_6 * V_7 = (struct V_6 * ) V_2 -> V_8 ;
if ( V_60 -> V_9 )
return;
F_15 ( & V_7 -> V_62 . V_63 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = (struct V_6 * ) V_2 -> V_8 ;
struct V_60 * V_60 = V_7 -> V_64 [ 0 ] ;
int V_9 ;
F_17 ( V_60 ,
V_7 -> V_16 ,
F_18 ( V_7 -> V_16 ,
V_7 -> V_36 ) ,
V_60 -> V_65 ,
3000 ,
F_14 ,
V_2 ) ;
V_9 = F_19 ( V_60 , V_51 ) ;
if ( V_9 )
F_4 ( V_18 , L_4 , V_55 ) ;
return V_9 ;
}
static int F_20 ( struct V_1 * V_2 , T_3 V_66 ,
T_1 * V_20 , T_2 V_21 )
{
struct V_6 * V_7 = (struct V_6 * ) V_2 -> V_8 ;
T_1 * V_3 ;
T_2 V_12 ;
int V_9 ;
if ( ! V_66 )
return - V_23 ;
V_3 = F_21 ( V_67 , V_51 ) ;
if ( ! V_3 )
return - V_49 ;
while ( V_21 ) {
V_12 = F_22 ( T_2 , V_21 , V_67 ) ;
V_9 = F_9 ( V_7 -> V_16 ,
F_10 ( V_7 -> V_16 , 0 ) ,
V_52 ,
V_53 ,
( ( V_66 & 0xffff0000 ) >> 16 ) ,
( V_66 & 0xffff ) , ( void * ) V_3 ,
V_12 , V_54 ) ;
if ( V_9 < 0 ) {
F_4 ( V_18 ,
L_5 ,
V_9 ) ;
F_11 ( V_3 ) ;
return V_9 ;
}
memcpy ( V_20 , V_3 , V_12 ) ;
V_21 -= V_12 ;
V_20 += V_12 ;
V_66 += V_12 ;
}
F_11 ( V_3 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , T_3 V_66 ,
T_1 * V_20 , T_2 V_21 )
{
struct V_6 * V_7 = (struct V_6 * ) V_2 -> V_8 ;
T_1 * V_3 ;
T_2 V_12 ;
int V_9 = 0 ;
V_3 = F_21 ( V_67 , V_51 ) ;
if ( ! V_3 )
return - V_49 ;
while ( V_21 ) {
V_12 = F_22 ( T_2 , V_21 , V_67 ) ;
memcpy ( V_3 , V_20 , V_12 ) ;
V_9 = F_9 ( V_7 -> V_16 ,
F_13 ( V_7 -> V_16 , 0 ) ,
V_57 ,
V_58 ,
( ( V_66 & 0xffff0000 ) >> 16 ) ,
( V_66 & 0xffff ) ,
( void * ) V_3 ,
V_12 ,
V_59 ) ;
if ( V_9 < 0 ) {
F_4 ( V_18 ,
L_6 ,
V_9 ) ;
F_11 ( V_3 ) ;
return V_9 ;
}
V_21 -= V_12 ;
V_20 += V_12 ;
V_66 += V_12 ;
}
F_11 ( V_3 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
T_1 * V_68 ,
T_3 V_4 )
{
T_3 V_69 = ( ( V_68 [ 1 ] >> 4 ) & 0x7 ) ;
T_1 V_5 ;
V_5 = ( ( V_69 == V_70 || V_69 == V_71 ||
V_69 == V_72 ) ? V_73 : V_74 ) ;
return F_5 ( V_2 ,
V_5 ,
( T_1 * ) V_68 ,
V_4 ) ;
}
static int F_25 ( struct V_1 * V_2 , T_3 V_47 ,
T_3 * V_48 , T_2 V_4 )
{
struct V_46 * V_16 =
( (struct V_6 * ) V_2 -> V_8 ) -> V_16 ;
T_2 V_75 ;
int V_76 ;
V_76 = F_7 ( V_16 , V_47 , & V_75 , V_4 ) ;
if ( V_76 < 0 )
return V_76 ;
* V_48 = V_75 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
unsigned long V_47 ,
unsigned long V_48 , T_2 V_4 )
{
struct V_46 * V_16 =
( (struct V_6 * ) V_2 -> V_8 ) -> V_16 ;
return F_12 ( V_16 , V_47 , V_48 , V_4 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
T_3 V_77 ,
T_3 V_78 , T_2 V_79 ,
T_1 * V_80 )
{
T_2 V_81 ;
T_3 V_82 , V_83 ;
T_1 V_84 [ 256 ] ;
int V_9 ;
V_81 = V_78 / V_79 ;
F_4 ( V_85 , L_7 , V_81 ) ;
for ( V_82 = 0 , V_83 = 0 ; V_83 < V_81 ; V_83 ++ , V_82 += V_79 ) {
memcpy ( V_84 , V_80 + V_82 , V_79 ) ;
V_9 = F_23 ( V_2 , V_77 ,
( T_1 * ) ( V_84 ) ,
V_79 ) ;
if ( V_9 < 0 )
return V_9 ;
F_4 ( V_85 , L_8 , V_55 , V_83 ) ;
V_77 += V_79 ;
}
if ( V_78 % V_79 ) {
memset ( V_84 , 0 , V_79 ) ;
memcpy ( V_84 , V_80 + V_82 ,
V_78 % V_79 ) ;
V_9 = F_23
( V_2 , V_77 ,
( T_1 * ) V_84 ,
V_78 % V_79 ) ;
if ( V_9 < 0 )
return V_9 ;
F_4 ( V_85 ,
L_9 ,
V_82 ) ;
}
return 0 ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = (struct V_6 * ) V_2 -> V_8 ;
F_29 ( & V_7 -> V_62 ) ;
F_30 ( V_7 -> V_64 [ 0 ] ) ;
F_11 ( V_2 -> V_86 -> V_87 ) ;
F_11 ( V_7 -> V_11 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_25 * V_88 )
{
struct V_6 * V_8 ;
struct V_89 * V_90 = V_2 -> V_86 ;
int V_9 ;
V_8 = F_21 ( sizeof( * V_8 ) , V_51 ) ;
if ( ! V_8 )
return - V_49 ;
V_2 -> V_8 = V_8 ;
V_8 -> V_16 = F_32 ( V_88 ) ;
if ( F_6 ( V_88 , V_2 ) )
return - V_23 ;
V_2 -> V_91 = & V_88 -> V_7 ;
F_33 ( V_88 , V_2 ) ;
V_90 -> V_87 = F_8 ( 2048 , V_51 ) ;
if ( ! V_90 -> V_87 ) {
F_4 ( V_18 , L_10 ,
V_55 ) ;
return - V_49 ;
}
V_8 -> V_11 = F_8 ( 2048 , V_51 ) ;
if ( ! V_8 -> V_11 ) {
V_9 = - V_49 ;
goto V_92;
}
V_8 -> V_64 [ 0 ] = F_34 ( 0 , V_51 ) ;
if ( ! V_8 -> V_64 [ 0 ] ) {
V_9 = - V_49 ;
goto V_93;
}
V_8 -> V_64 [ 0 ] -> V_65 = V_2 -> V_86 -> V_87 ;
V_8 -> V_94 = 252 ;
V_2 -> V_79 = V_8 -> V_94 ;
V_2 -> V_95 = F_16 ;
V_2 -> V_96 = V_97 ;
V_2 -> V_98 = V_99 ;
V_2 -> V_100 = V_101 ;
V_2 -> V_102 = & V_103 ;
F_35 ( & V_8 -> V_62 . V_63 ) ;
V_9 = F_36 ( V_90 , & V_8 -> V_62 ,
V_104 , L_11 ) ;
if ( V_9 ) {
F_4 ( V_18 , L_12 , V_55 ) ;
goto V_105;
}
#ifdef F_37
V_2 -> V_106 = ( V_107 - 1 ) ;
#endif
F_4 ( V_108 , L_13 , V_55 ) ;
return 0 ;
V_105:
F_30 ( V_8 -> V_64 [ 0 ] ) ;
V_93:
F_11 ( V_8 -> V_11 ) ;
V_92:
F_11 ( V_90 -> V_87 ) ;
return V_9 ;
}
static int F_38 ( struct V_1 * V_2 , T_2 V_66 , T_3 V_20 ,
T_2 V_109 )
{
int V_76 ;
V_76 = F_26
( V_2 , V_110 ,
( ( V_66 << 6 ) | ( ( V_20 >> 16 ) & 0xffff ) ) , 2 ) ;
if ( V_76 < 0 )
return V_76 ;
V_76 = F_26 ( V_2 , V_111 ,
( V_20 & 0xffff ) , 2 ) ;
if ( V_76 < 0 )
return V_76 ;
F_26 ( V_2 , V_112 ,
V_113 , 2 ) ;
V_76 = F_26 ( V_2 , V_114 ,
( ( V_109 - 1 ) | V_115 ) , 2 ) ;
if ( V_76 < 0 )
return V_76 ;
F_39 ( 20 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_76 ;
F_4 ( V_85 , L_14 ) ;
F_26 ( V_2 , V_116 , 0xE , 4 ) ;
F_39 ( 100 ) ;
V_76 = F_38 ( V_2 , V_117 ,
V_118 , 32 ) ;
if ( V_76 < 0 )
goto V_119;
V_76 = F_38 ( V_2 , V_120 ,
V_121 , 32 ) ;
if ( V_76 < 0 )
goto V_119;
V_76 = F_38 ( V_2 , V_122 ,
V_123 , 32 ) ;
if ( V_76 < 0 )
goto V_119;
V_76 = F_38 ( V_2 , V_124 ,
V_121 , 32 ) ;
if ( V_76 < 0 )
goto V_119;
V_76 = F_38 ( V_2 , V_125 ,
V_126 , 32 ) ;
if ( V_76 < 0 )
goto V_119;
F_4 ( V_85 , L_15 ) ;
return V_76 ;
V_119:
F_4 ( V_18 , L_16 ) ;
return V_76 ;
}
static int F_41 ( struct V_25 * V_88 ,
const struct V_127 * V_128 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
T_2 V_129 ;
int V_9 ;
F_4 ( V_108 , L_17 , V_55 ) ;
V_2 = F_42 () ;
if ( ! V_2 ) {
F_4 ( V_18 , L_18 ,
V_55 ) ;
return - V_49 ;
}
V_2 -> V_100 = V_101 ;
V_9 = F_31 ( V_2 , V_88 ) ;
if ( V_9 ) {
F_4 ( V_18 , L_19 ,
V_55 ) ;
goto V_130;
}
F_4 ( V_18 , L_20 , V_55 ) ;
V_7 = (struct V_6 * ) V_2 -> V_8 ;
V_9 = F_7 ( V_7 -> V_16 , V_131 , & V_129 , 2 ) ;
if ( V_9 < 0 )
goto V_132;
else
V_129 &= 1 ;
if ( ! V_129 ) {
F_4 ( V_108 , L_21 ) ;
V_9 = F_43 ( V_2 ) ;
if ( V_9 ) {
F_4 ( V_18 , L_22 ,
V_55 ) ;
goto V_132;
}
F_4 ( V_108 , L_23 , V_55 ) ;
}
V_9 = F_16 ( V_2 ) ;
if ( V_9 )
goto V_132;
return 0 ;
V_132:
F_28 ( V_2 ) ;
V_130:
F_44 ( V_2 ) ;
F_4 ( V_18 , L_24 , V_55 ) ;
return V_9 ;
}
static void F_45 ( struct V_25 * V_88 )
{
struct V_1 * V_2 = F_46 ( V_88 ) ;
if ( ! V_2 )
return;
F_47 ( V_2 ) ;
F_40 ( V_2 ) ;
F_28 ( V_2 ) ;
F_44 ( V_2 ) ;
F_4 ( V_85 , L_25 , V_55 ) ;
}
static int F_48 ( struct V_25 * V_133 , T_5 V_134 )
{
return - V_135 ;
}
static int F_49 ( struct V_25 * V_133 )
{
return - V_135 ;
}

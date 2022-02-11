static const char * F_1 ( void )
{
switch ( F_2 ( F_3 ( V_1 ) ) ) {
case V_2 :
case V_3 :
return L_1 ;
case V_4 :
return L_2 ;
default:
return L_3 ;
}
}
const char * F_4 ( void )
{
return F_1 () ;
}
static int T_1 F_5 ( void )
{
int V_5 ;
F_6 ( V_6 ,
V_6 + V_7 ) ;
if ( V_4 == F_2 ( F_3 ( V_1 ) ) ) {
unsigned short V_8 = F_3 ( V_9 ) ;
F_7 ( V_9 , ~ V_8 ) ;
if ( F_3 ( V_9 ) != V_8 ) {
F_7 ( V_9 , V_8 ) ;
return 0 ;
}
}
F_6 ( V_10 ,
V_10 + V_11 ) ;
V_5 = F_2 ( F_3 ( V_1 ) ) ;
if ( ( V_5 == V_2 ) ||
( V_5 == V_3 ) ) {
unsigned short V_8 = F_3 ( V_9 ) ;
F_7 ( V_9 , ~ V_8 ) ;
if ( F_3 ( V_9 ) != V_8 ) {
F_7 ( V_9 , V_8 ) ;
return 0 ;
}
}
return 1 ;
}
void T_1 F_8 ( void )
{
unsigned long V_12 , V_13 , div , V_14 ;
unsigned short V_15 ;
if ( F_5 () ) {
F_9 ( V_16 L_4 ) ;
return;
}
V_15 = F_3 ( V_1 ) ;
F_9 ( V_17 L_5
L_6 , F_1 () ,
( V_15 >> 4 ) & 0xf , ( V_15 >> 8 ) & 0xf , V_15 & 0xf ) ;
V_14 = F_10 ( ( void V_18 * ) V_19 ) ;
V_14 &= ~ ( V_20 | V_21 ) ;
V_14 &= ~ ( V_22 | V_23 | V_24 ) ;
V_14 |= V_25 ;
F_11 ( V_14 , ( void V_18 * ) V_19 ) ;
F_12 () ;
div = ( F_13 () + 25000000 ) / 50000000 ;
if ( div & 1 )
div ++ ;
div = ( ( div >> 1 ) - 1 ) & 0xff ;
V_12 = div << V_26 ;
F_11 ( V_12 , ( void V_18 * ) V_27 ) ;
F_12 () ;
V_12 |= V_28 ;
F_11 ( V_12 , ( void V_18 * ) V_27 ) ;
F_12 () ;
V_13 = V_29 << V_30 ;
F_11 ( V_13 , ( void V_18 * ) V_31 ) ;
F_12 () ;
}
static void F_14 ( struct V_32 * V_33 , int V_34 ,
unsigned int V_35 )
{
struct V_36 * V_37 = V_33 -> V_38 ;
unsigned long V_39 = ( unsigned long ) V_37 -> V_40 ;
V_39 &= 0xffffff00 ;
if ( V_35 & V_41 ) {
V_39 += V_42 ;
} else if ( V_35 & V_43 ) {
V_39 += V_44 ;
} else {
V_39 += V_45 ;
}
V_37 -> V_46 = V_37 -> V_40 = ( void V_18 * ) V_39 ;
if ( V_34 != V_47 ) {
F_15 ( V_34 , V_37 -> V_40 ) ;
F_12 () ;
}
}
static int F_16 ( struct V_32 * V_33 )
{
return F_10 ( ( void V_18 * ) V_48 ) & 1 ;
}
static T_2 F_17 ( int V_49 , void * V_50 )
{
void (* F_18)( struct V_51 * , unsigned long );
if ( V_49 == V_52 ) {
F_19 ( V_52 ) ;
F_20 ( V_53 ) ;
} else {
F_19 ( V_53 ) ;
F_20 ( V_52 ) ;
}
F_18 = F_21 ( V_54 ) ;
if ( F_18 ) {
F_18 ( V_50 , F_22 ( 500 ) ) ;
F_23 ( V_54 ) ;
}
return V_55 ;
}
static int F_24 ( void * V_51 , int V_56 )
{
int V_57 ;
if ( V_56 ) {
V_57 = F_25 ( V_52 , F_17 ,
0 , L_7 , V_51 ) ;
if ( V_57 )
goto V_58;
V_57 = F_25 ( V_53 , F_17 ,
0 , L_8 , V_51 ) ;
if ( V_57 ) {
F_26 ( V_52 , V_51 ) ;
goto V_58;
}
if ( F_3 ( V_59 ) & V_60 )
F_20 ( V_53 ) ;
else
F_20 ( V_52 ) ;
} else {
F_26 ( V_52 , V_51 ) ;
F_26 ( V_53 , V_51 ) ;
}
V_57 = 0 ;
V_58:
return V_57 ;
}
static void F_27 ( void * V_51 , int V_61 )
{
if ( V_61 ) {
F_28 ( V_62 , 0 , V_63 ) ;
F_29 ( 400 ) ;
} else
F_28 ( V_62 , V_63 , 0 ) ;
}
static int F_30 ( void * V_51 )
{
return ( F_3 ( V_64 ) & V_65 ) ? 1 : 0 ;
}
static int F_31 ( void * V_51 )
{
return ( F_3 ( V_59 ) & V_60 ) ? 1 : 0 ;
}
static void F_32 ( struct V_66 * V_67 ,
enum V_68 V_69 )
{
if ( V_69 != V_70 )
F_28 ( V_71 , V_72 , 0 ) ;
else
F_28 ( V_71 , 0 , V_72 ) ;
}
static T_2 F_33 ( int V_49 , void * V_50 )
{
void (* F_18)( struct V_51 * , unsigned long );
if ( V_49 == V_73 ) {
F_19 ( V_73 ) ;
F_20 ( V_74 ) ;
} else {
F_19 ( V_74 ) ;
F_20 ( V_73 ) ;
}
F_18 = F_21 ( V_54 ) ;
if ( F_18 ) {
F_18 ( V_50 , F_22 ( 500 ) ) ;
F_23 ( V_54 ) ;
}
return V_55 ;
}
static int F_34 ( void * V_51 , int V_56 )
{
int V_57 ;
if ( V_56 ) {
V_57 = F_25 ( V_73 , F_33 , 0 ,
L_9 , V_51 ) ;
if ( V_57 )
goto V_58;
V_57 = F_25 ( V_74 , F_33 , 0 ,
L_10 , V_51 ) ;
if ( V_57 ) {
F_26 ( V_73 , V_51 ) ;
goto V_58;
}
if ( F_3 ( V_59 ) & V_75 )
F_20 ( V_74 ) ;
else
F_20 ( V_73 ) ;
} else {
F_26 ( V_73 , V_51 ) ;
F_26 ( V_74 , V_51 ) ;
}
V_57 = 0 ;
V_58:
return V_57 ;
}
static void F_35 ( struct V_66 * V_67 ,
enum V_68 V_69 )
{
if ( V_69 != V_70 )
F_28 ( V_71 , V_76 , 0 ) ;
else
F_28 ( V_71 , 0 , V_76 ) ;
}
static void F_36 ( void * V_51 , int V_61 )
{
if ( V_61 ) {
F_28 ( V_62 , 0 , V_77 ) ;
F_29 ( 400 ) ;
} else
F_28 ( V_62 , V_77 , 0 ) ;
}
static int F_37 ( void * V_51 )
{
return ( F_3 ( V_64 ) & V_78 ) ? 1 : 0 ;
}
static int F_38 ( void * V_51 )
{
return ( F_3 ( V_59 ) & V_75 ) ? 1 : 0 ;
}
static int F_39 ( void )
{
return ( F_3 ( V_79 ) >> 8 ) & 0x0f ;
}
static int F_40 ( void )
{
F_28 ( V_62 , 0 , V_80 | V_81 |
V_82 ) ;
return 0 ;
}
static int F_41 ( void )
{
F_28 ( V_62 , V_80 | V_81 |
V_82 , 0 ) ;
return 0 ;
}
static void F_42 ( struct V_83 * V_84 , int V_85 , int V_86 )
{
if ( V_85 )
F_28 ( V_87 , 0 , V_88 ) ;
else
F_28 ( V_87 , V_88 , 0 ) ;
}
static int T_1 F_43 ( void )
{
if ( F_44 ( F_3 ( V_1 ) ) <= 3 ) {
F_9 ( V_16 L_11 ) ;
F_9 ( V_16 L_11 ) ;
F_9 ( V_16 L_12 ) ;
F_9 ( V_16 L_13 ) ;
F_9 ( V_16 L_14 ) ;
F_9 ( V_16 L_15 ) ;
F_9 ( V_16 L_11 ) ;
F_9 ( V_16 L_11 ) ;
return 1 ;
}
V_89 [ 0 ] . V_90 = V_91 ;
V_89 [ 0 ] . V_92 = V_91 + 0xff ;
V_93 [ 0 ] . V_90 = V_94 ;
V_93 [ 0 ] . V_92 = V_94 + V_95 - 1 ;
V_96 [ 0 ] . V_90 = V_97 ;
V_96 [ 0 ] . V_92 = V_97 + 0xff ;
return 0 ;
}
static int T_1 F_45 ( void )
{
unsigned long V_14 ;
unsigned short V_98 ;
int V_99 , V_5 ;
V_5 = F_2 ( F_3 ( V_1 ) ) ;
if ( ( V_5 == V_2 ) ||
( V_5 == V_3 ) ) {
if ( F_43 () )
return - V_100 ;
}
F_46 ( V_101 , V_102 ) ;
F_47 ( V_103 , V_104 , V_101 ) ;
F_48 ( V_52 , V_105 ) ;
F_48 ( V_53 , V_105 ) ;
F_48 ( V_106 , V_105 ) ;
F_48 ( V_107 , V_105 ) ;
F_48 ( V_108 , V_105 ) ;
F_48 ( V_109 , V_105 ) ;
F_49 ( 0 , V_110 ,
F_50 ( V_110 ) ) ;
F_51 ( V_111 ,
F_50 ( V_110 ) ) ;
V_14 = F_10 ( ( void V_18 * ) V_19 ) & ~ V_20 ;
F_52 ( 215 , L_16 ) ;
F_53 ( 215 , 1 ) ;
F_9 ( V_17 L_17 , F_1 () ) ;
V_98 = F_3 ( V_79 ) ;
if ( V_98 & V_112 ) {
V_113 [ 0 ] = & V_114 ;
F_28 ( V_87 , V_115 , 0 ) ;
V_14 |= ( 2 << 17 ) ;
F_9 ( V_17 L_18 ) ;
F_9 ( V_17 L_19 ) ;
} else {
V_113 [ 0 ] = & V_116 ;
F_28 ( V_87 , 0 , V_115 ) ;
V_14 |= ( 1 << 17 ) ;
F_9 ( V_17 L_20 ) ;
F_9 ( V_17 L_21 ) ;
}
F_11 ( V_14 , ( void V_18 * ) V_19 ) ;
F_12 () ;
V_98 &= V_112 | V_117 ;
if ( V_98 == V_112 ) {
F_28 ( V_87 , 0 , V_118 ) ;
V_119 . V_120 = L_22 ;
V_121 . V_120 = L_23 ;
F_9 ( V_17 L_24 ) ;
} else {
F_28 ( V_87 , V_118 , 0 ) ;
V_119 . V_120 = L_25 ;
V_121 . V_120 = L_26 ;
F_9 ( V_17 L_27 ) ;
}
F_11 ( V_122 ,
( void V_18 * ) F_54 ( V_123 ) + V_124 ) ;
F_12 () ;
F_55 (
V_125 ,
V_125 + 0x000400000 - 1 ,
V_126 ,
V_126 + 0x000400000 - 1 ,
V_127 ,
V_127 + 0x000010000 - 1 ,
V_128 , V_106 ,
0 , V_107 , 0 ) ;
F_55 (
V_125 + 0x004000000 ,
V_125 + 0x004400000 - 1 ,
V_126 + 0x004000000 ,
V_126 + 0x004400000 - 1 ,
V_127 + 0x004000000 ,
V_127 + 0x004010000 - 1 ,
V_129 , V_108 ,
0 , V_109 , 1 ) ;
V_99 = F_3 ( V_64 ) & V_130 ;
F_56 ( 64 << 20 , 2 , V_99 ) ;
F_57 ( V_113 , F_50 ( V_113 ) ) ;
if ( ( V_5 == V_2 ) ||
( V_5 == V_3 ) )
F_57 ( V_131 , F_50 ( V_131 ) ) ;
return 0 ;
}

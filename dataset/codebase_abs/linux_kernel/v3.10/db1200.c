static int T_1 F_1 ( void )
{
int V_1 ;
F_2 ( V_2 ,
V_2 + V_3 ) ;
if ( V_4 == F_3 ( F_4 ( V_5 ) ) ) {
unsigned short V_6 = F_4 ( V_7 ) ;
F_5 ( V_7 , ~ V_6 ) ;
if ( F_4 ( V_7 ) != V_6 ) {
F_5 ( V_7 , V_6 ) ;
return 0 ;
}
}
F_2 ( V_8 ,
V_8 + V_9 ) ;
V_1 = F_3 ( F_4 ( V_5 ) ) ;
if ( ( V_1 == V_10 ) ||
( V_1 == V_11 ) ) {
unsigned short V_6 = F_4 ( V_7 ) ;
F_5 ( V_7 , ~ V_6 ) ;
if ( F_4 ( V_7 ) != V_6 ) {
F_5 ( V_7 , V_6 ) ;
return 0 ;
}
}
return 1 ;
}
int T_1 F_6 ( void )
{
unsigned long V_12 , V_13 , div , V_14 ;
unsigned short V_15 ;
if ( F_1 () )
return - V_16 ;
V_15 = F_4 ( V_5 ) ;
F_7 ( V_17 L_1
L_2 , F_8 () ,
( V_15 >> 4 ) & 0xf , ( V_15 >> 8 ) & 0xf , V_15 & 0xf ) ;
V_14 = F_9 ( ( void V_18 * ) V_19 ) ;
V_14 &= ~ ( V_20 | V_21 ) ;
V_14 &= ~ ( V_22 | V_23 | V_24 ) ;
V_14 |= V_25 ;
F_10 ( V_14 , ( void V_18 * ) V_19 ) ;
F_11 () ;
div = ( F_12 () + 25000000 ) / 50000000 ;
if ( div & 1 )
div ++ ;
div = ( ( div >> 1 ) - 1 ) & 0xff ;
V_12 = div << V_26 ;
F_10 ( V_12 , ( void V_18 * ) V_27 ) ;
F_11 () ;
V_12 |= V_28 ;
F_10 ( V_12 , ( void V_18 * ) V_27 ) ;
F_11 () ;
V_13 = V_29 << V_30 ;
F_10 ( V_13 , ( void V_18 * ) V_31 ) ;
F_11 () ;
return 0 ;
}
static void F_13 ( struct V_32 * V_33 , int V_34 ,
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
F_14 ( V_34 , V_37 -> V_40 ) ;
F_11 () ;
}
}
static int F_15 ( struct V_32 * V_33 )
{
return F_9 ( ( void V_18 * ) V_48 ) & 1 ;
}
static T_2 F_16 ( int V_49 , void * V_50 )
{
void (* F_17)( struct V_51 * , unsigned long );
if ( V_49 == V_52 ) {
F_18 ( V_52 ) ;
F_19 ( V_53 ) ;
} else {
F_18 ( V_53 ) ;
F_19 ( V_52 ) ;
}
F_17 = F_20 ( V_54 ) ;
if ( F_17 ) {
F_17 ( V_50 , F_21 ( 500 ) ) ;
F_22 ( V_54 ) ;
}
return V_55 ;
}
static int F_23 ( void * V_51 , int V_56 )
{
int V_57 ;
if ( V_56 ) {
V_57 = F_24 ( V_52 , F_16 ,
0 , L_3 , V_51 ) ;
if ( V_57 )
goto V_58;
V_57 = F_24 ( V_53 , F_16 ,
0 , L_4 , V_51 ) ;
if ( V_57 ) {
F_25 ( V_52 , V_51 ) ;
goto V_58;
}
if ( F_4 ( V_59 ) & V_60 )
F_19 ( V_53 ) ;
else
F_19 ( V_52 ) ;
} else {
F_25 ( V_52 , V_51 ) ;
F_25 ( V_53 , V_51 ) ;
}
V_57 = 0 ;
V_58:
return V_57 ;
}
static void F_26 ( void * V_51 , int V_61 )
{
if ( V_61 ) {
F_27 ( V_62 , 0 , V_63 ) ;
F_28 ( 400 ) ;
} else
F_27 ( V_62 , V_63 , 0 ) ;
}
static int F_29 ( void * V_51 )
{
return ( F_4 ( V_64 ) & V_65 ) ? 1 : 0 ;
}
static int F_30 ( void * V_51 )
{
return ( F_4 ( V_59 ) & V_60 ) ? 1 : 0 ;
}
static void F_31 ( struct V_66 * V_67 ,
enum V_68 V_69 )
{
if ( V_69 != V_70 )
F_27 ( V_71 , V_72 , 0 ) ;
else
F_27 ( V_71 , 0 , V_72 ) ;
}
static T_2 F_32 ( int V_49 , void * V_50 )
{
void (* F_17)( struct V_51 * , unsigned long );
if ( V_49 == V_73 ) {
F_18 ( V_73 ) ;
F_19 ( V_74 ) ;
} else {
F_18 ( V_74 ) ;
F_19 ( V_73 ) ;
}
F_17 = F_20 ( V_54 ) ;
if ( F_17 ) {
F_17 ( V_50 , F_21 ( 500 ) ) ;
F_22 ( V_54 ) ;
}
return V_55 ;
}
static int F_33 ( void * V_51 , int V_56 )
{
int V_57 ;
if ( V_56 ) {
V_57 = F_24 ( V_73 , F_32 , 0 ,
L_5 , V_51 ) ;
if ( V_57 )
goto V_58;
V_57 = F_24 ( V_74 , F_32 , 0 ,
L_6 , V_51 ) ;
if ( V_57 ) {
F_25 ( V_73 , V_51 ) ;
goto V_58;
}
if ( F_4 ( V_59 ) & V_75 )
F_19 ( V_74 ) ;
else
F_19 ( V_73 ) ;
} else {
F_25 ( V_73 , V_51 ) ;
F_25 ( V_74 , V_51 ) ;
}
V_57 = 0 ;
V_58:
return V_57 ;
}
static void F_34 ( struct V_66 * V_67 ,
enum V_68 V_69 )
{
if ( V_69 != V_70 )
F_27 ( V_71 , V_76 , 0 ) ;
else
F_27 ( V_71 , 0 , V_76 ) ;
}
static void F_35 ( void * V_51 , int V_61 )
{
if ( V_61 ) {
F_27 ( V_62 , 0 , V_77 ) ;
F_28 ( 400 ) ;
} else
F_27 ( V_62 , V_77 , 0 ) ;
}
static int F_36 ( void * V_51 )
{
return ( F_4 ( V_64 ) & V_78 ) ? 1 : 0 ;
}
static int F_37 ( void * V_51 )
{
return ( F_4 ( V_59 ) & V_75 ) ? 1 : 0 ;
}
static int F_38 ( void )
{
return ( F_4 ( V_79 ) >> 8 ) & 0x0f ;
}
static int F_39 ( void )
{
F_27 ( V_62 , 0 , V_80 | V_81 |
V_82 ) ;
return 0 ;
}
static int F_40 ( void )
{
F_27 ( V_62 , V_80 | V_81 |
V_82 , 0 ) ;
return 0 ;
}
static void F_41 ( struct V_83 * V_84 , int V_85 , int V_86 )
{
if ( V_85 )
F_27 ( V_87 , 0 , V_88 ) ;
else
F_27 ( V_87 , V_88 , 0 ) ;
}
static int T_1 F_42 ( void )
{
if ( F_43 ( F_4 ( V_5 ) ) <= 3 ) {
F_7 ( V_89 L_7 ) ;
F_7 ( V_89 L_7 ) ;
F_7 ( V_89 L_8 ) ;
F_7 ( V_89 L_9 ) ;
F_7 ( V_89 L_10 ) ;
F_7 ( V_89 L_11 ) ;
F_7 ( V_89 L_7 ) ;
F_7 ( V_89 L_7 ) ;
return 1 ;
}
V_90 [ 0 ] . V_91 = V_92 ;
V_90 [ 0 ] . V_93 = V_92 + 0xff ;
V_94 [ 0 ] . V_91 = V_95 ;
V_94 [ 0 ] . V_93 = V_95 + V_96 - 1 ;
V_97 [ 0 ] . V_91 = V_98 ;
V_97 [ 0 ] . V_93 = V_98 + 0xff ;
return 0 ;
}
int T_1 F_44 ( void )
{
unsigned long V_14 ;
unsigned short V_99 ;
int V_100 , V_1 ;
V_1 = F_3 ( F_4 ( V_5 ) ) ;
if ( ( V_1 == V_10 ) ||
( V_1 == V_11 ) ) {
if ( F_42 () )
return - V_16 ;
}
F_45 ( V_101 , V_102 ) ;
F_46 ( V_103 , V_104 , V_101 ) ;
F_47 ( V_52 , V_105 ) ;
F_47 ( V_53 , V_105 ) ;
F_47 ( V_106 , V_105 ) ;
F_47 ( V_107 , V_105 ) ;
F_47 ( V_108 , V_105 ) ;
F_47 ( V_109 , V_105 ) ;
F_48 ( 0 , V_110 ,
F_49 ( V_110 ) ) ;
F_50 ( V_111 ,
F_49 ( V_110 ) ) ;
V_14 = F_9 ( ( void V_18 * ) V_19 ) & ~ V_20 ;
F_51 ( 215 , L_12 ) ;
F_52 ( 215 , 1 ) ;
F_7 ( V_17 L_13 , F_8 () ) ;
V_99 = F_4 ( V_79 ) ;
if ( V_99 & V_112 ) {
V_113 [ 0 ] = & V_114 ;
F_27 ( V_87 , V_115 , 0 ) ;
V_14 |= ( 2 << 17 ) ;
F_7 ( V_17 L_14 ) ;
F_7 ( V_17 L_15 ) ;
} else {
V_113 [ 0 ] = & V_116 ;
F_27 ( V_87 , 0 , V_115 ) ;
V_14 |= ( 1 << 17 ) ;
F_7 ( V_17 L_16 ) ;
F_7 ( V_17 L_17 ) ;
}
F_10 ( V_14 , ( void V_18 * ) V_19 ) ;
F_11 () ;
V_99 &= V_112 | V_117 ;
if ( V_99 == V_112 ) {
F_27 ( V_87 , 0 , V_118 ) ;
V_119 . V_120 = L_18 ;
V_121 . V_120 = L_19 ;
F_7 ( V_17 L_20 ) ;
} else {
F_27 ( V_87 , V_118 , 0 ) ;
V_119 . V_120 = L_21 ;
V_121 . V_120 = L_22 ;
F_7 ( V_17 L_23 ) ;
}
F_10 ( V_122 ,
( void V_18 * ) F_53 ( V_123 ) + V_124 ) ;
F_11 () ;
F_54 (
V_125 ,
V_125 + 0x000400000 - 1 ,
V_126 ,
V_126 + 0x000400000 - 1 ,
V_127 ,
V_127 + 0x000010000 - 1 ,
V_128 , V_106 ,
0 , V_107 , 0 ) ;
F_54 (
V_125 + 0x004000000 ,
V_125 + 0x004400000 - 1 ,
V_126 + 0x004000000 ,
V_126 + 0x004400000 - 1 ,
V_127 + 0x004000000 ,
V_127 + 0x004010000 - 1 ,
V_129 , V_108 ,
0 , V_109 , 1 ) ;
V_100 = F_4 ( V_64 ) & V_130 ;
F_55 ( 64 << 20 , 2 , V_100 ) ;
F_56 ( V_113 , F_49 ( V_113 ) ) ;
if ( ( V_1 == V_10 ) ||
( V_1 == V_11 ) )
F_56 ( V_131 , F_49 ( V_131 ) ) ;
return 0 ;
}

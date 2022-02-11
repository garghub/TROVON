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
unsigned short V_12 ;
if ( F_1 () )
return - V_13 ;
V_12 = F_4 ( V_5 ) ;
switch ( F_3 ( V_12 ) ) {
case V_10 :
case V_11 :
case V_4 :
break;
default:
return - V_13 ;
}
F_7 ( V_14 L_1
L_2 , F_8 () ,
( V_12 >> 4 ) & 0xf , ( V_12 >> 8 ) & 0xf , V_12 & 0xf ) ;
return 0 ;
}
static void F_9 ( struct V_15 * V_16 , int V_17 ,
unsigned int V_18 )
{
struct V_19 * V_20 = F_10 ( V_16 ) ;
unsigned long V_21 = ( unsigned long ) V_20 -> V_22 ;
V_21 &= 0xffffff00 ;
if ( V_18 & V_23 ) {
V_21 += V_24 ;
} else if ( V_18 & V_25 ) {
V_21 += V_26 ;
} else {
V_21 += V_27 ;
}
V_20 -> V_28 = V_20 -> V_22 = ( void V_29 * ) V_21 ;
if ( V_17 != V_30 ) {
F_11 ( V_17 , V_20 -> V_22 ) ;
F_12 () ;
}
}
static int F_13 ( struct V_15 * V_16 )
{
return F_14 ( V_31 ) & 1 ;
}
static T_2 F_15 ( int V_32 , void * V_33 )
{
void (* F_16)( struct V_34 * , unsigned long );
if ( V_32 == V_35 ) {
F_17 ( V_35 ) ;
F_18 ( V_36 ) ;
} else {
F_17 ( V_36 ) ;
F_18 ( V_35 ) ;
}
F_16 = F_19 ( V_37 ) ;
if ( F_16 ) {
F_16 ( V_33 , F_20 ( 500 ) ) ;
F_21 ( V_37 ) ;
}
return V_38 ;
}
static int F_22 ( void * V_34 , int V_39 )
{
int V_40 ;
if ( V_39 ) {
V_40 = F_23 ( V_35 , F_15 ,
0 , L_3 , V_34 ) ;
if ( V_40 )
goto V_41;
V_40 = F_23 ( V_36 , F_15 ,
0 , L_4 , V_34 ) ;
if ( V_40 ) {
F_24 ( V_35 , V_34 ) ;
goto V_41;
}
if ( F_4 ( V_42 ) & V_43 )
F_18 ( V_36 ) ;
else
F_18 ( V_35 ) ;
} else {
F_24 ( V_35 , V_34 ) ;
F_24 ( V_36 , V_34 ) ;
}
V_40 = 0 ;
V_41:
return V_40 ;
}
static void F_25 ( void * V_34 , int V_44 )
{
if ( V_44 ) {
F_26 ( V_45 , 0 , V_46 ) ;
F_27 ( 400 ) ;
} else
F_26 ( V_45 , V_46 , 0 ) ;
}
static int F_28 ( void * V_34 )
{
return ( F_4 ( V_47 ) & V_48 ) ? 1 : 0 ;
}
static int F_29 ( void * V_34 )
{
return ( F_4 ( V_42 ) & V_43 ) ? 1 : 0 ;
}
static void F_30 ( struct V_49 * V_50 ,
enum V_51 V_52 )
{
if ( V_52 != V_53 )
F_26 ( V_54 , V_55 , 0 ) ;
else
F_26 ( V_54 , 0 , V_55 ) ;
}
static T_2 F_31 ( int V_32 , void * V_33 )
{
void (* F_16)( struct V_34 * , unsigned long );
if ( V_32 == V_56 ) {
F_17 ( V_56 ) ;
F_18 ( V_57 ) ;
} else {
F_17 ( V_57 ) ;
F_18 ( V_56 ) ;
}
F_16 = F_19 ( V_37 ) ;
if ( F_16 ) {
F_16 ( V_33 , F_20 ( 500 ) ) ;
F_21 ( V_37 ) ;
}
return V_38 ;
}
static int F_32 ( void * V_34 , int V_39 )
{
int V_40 ;
if ( V_39 ) {
V_40 = F_23 ( V_56 , F_31 , 0 ,
L_5 , V_34 ) ;
if ( V_40 )
goto V_41;
V_40 = F_23 ( V_57 , F_31 , 0 ,
L_6 , V_34 ) ;
if ( V_40 ) {
F_24 ( V_56 , V_34 ) ;
goto V_41;
}
if ( F_4 ( V_42 ) & V_58 )
F_18 ( V_57 ) ;
else
F_18 ( V_56 ) ;
} else {
F_24 ( V_56 , V_34 ) ;
F_24 ( V_57 , V_34 ) ;
}
V_40 = 0 ;
V_41:
return V_40 ;
}
static void F_33 ( struct V_49 * V_50 ,
enum V_51 V_52 )
{
if ( V_52 != V_53 )
F_26 ( V_54 , V_59 , 0 ) ;
else
F_26 ( V_54 , 0 , V_59 ) ;
}
static void F_34 ( void * V_34 , int V_44 )
{
if ( V_44 ) {
F_26 ( V_45 , 0 , V_60 ) ;
F_27 ( 400 ) ;
} else
F_26 ( V_45 , V_60 , 0 ) ;
}
static int F_35 ( void * V_34 )
{
return ( F_4 ( V_47 ) & V_61 ) ? 1 : 0 ;
}
static int F_36 ( void * V_34 )
{
return ( F_4 ( V_42 ) & V_58 ) ? 1 : 0 ;
}
static int F_37 ( void )
{
return ( F_4 ( V_62 ) >> 8 ) & 0x0f ;
}
static int F_38 ( void )
{
F_26 ( V_45 , 0 , V_63 | V_64 |
V_65 ) ;
return 0 ;
}
static int F_39 ( void )
{
F_26 ( V_45 , V_63 | V_64 |
V_65 , 0 ) ;
return 0 ;
}
static void F_40 ( struct V_66 * V_67 , int V_68 , int V_69 )
{
if ( V_68 )
F_26 ( V_70 , 0 , V_71 ) ;
else
F_26 ( V_70 , V_71 , 0 ) ;
}
static int T_1 F_41 ( void )
{
if ( F_42 ( F_4 ( V_5 ) ) <= 3 ) {
F_7 ( V_72 L_7 ) ;
F_7 ( V_72 L_7 ) ;
F_7 ( V_72 L_8 ) ;
F_7 ( V_72 L_9 ) ;
F_7 ( V_72 L_10 ) ;
F_7 ( V_72 L_11 ) ;
F_7 ( V_72 L_7 ) ;
F_7 ( V_72 L_7 ) ;
return 1 ;
}
V_73 [ 0 ] . V_74 = V_75 ;
V_73 [ 0 ] . V_76 = V_75 + 0xff ;
V_77 [ 0 ] . V_74 = V_78 ;
V_77 [ 0 ] . V_76 = V_78 + V_79 - 1 ;
V_80 [ 0 ] . V_74 = V_81 ;
V_80 [ 0 ] . V_76 = V_81 + 0xff ;
return 0 ;
}
int T_1 F_43 ( void )
{
unsigned long V_82 ;
unsigned short V_83 ;
int V_84 , V_1 ;
struct V_85 * V_86 ;
V_1 = F_3 ( F_4 ( V_5 ) ) ;
if ( ( V_1 == V_10 ) ||
( V_1 == V_11 ) ) {
if ( F_41 () )
return - V_13 ;
}
F_44 ( V_87 , V_88 ) ;
F_45 ( V_89 , V_90 , V_87 ) ;
V_82 = F_46 ( V_91 ) ;
V_82 &= ~ ( V_92 | V_93 ) ;
V_82 &= ~ ( V_94 | V_95 | V_96 ) ;
V_82 |= V_97 ;
F_47 ( V_82 , V_91 ) ;
V_86 = F_48 ( NULL , L_12 ) ;
if ( ! F_49 ( V_86 ) ) {
V_82 = F_50 ( V_86 , 50000000 ) ;
if ( ( V_82 < 1 ) || ( abs ( 50000000 - V_82 ) > 2500000 ) )
F_51 ( L_13 ) ;
else
F_52 ( V_86 , V_82 ) ;
F_53 ( V_86 ) ;
F_54 ( V_86 ) ;
}
F_55 ( V_35 , V_98 ) ;
F_55 ( V_36 , V_98 ) ;
F_55 ( V_99 , V_98 ) ;
F_55 ( V_100 , V_98 ) ;
F_55 ( V_101 , V_98 ) ;
F_55 ( V_102 , V_98 ) ;
F_56 ( 0 , V_103 ,
F_57 ( V_103 ) ) ;
F_58 ( V_104 ,
F_57 ( V_103 ) ) ;
V_82 = F_46 ( V_91 ) & ~ V_92 ;
F_59 ( 215 , L_14 ) ;
F_60 ( 215 , 1 ) ;
F_7 ( V_14 L_15 , F_8 () ) ;
V_83 = F_4 ( V_62 ) ;
if ( V_83 & V_105 ) {
V_106 [ 0 ] = & V_107 ;
F_26 ( V_70 , V_108 , 0 ) ;
V_82 |= ( 2 << 17 ) ;
F_7 ( V_14 L_16 ) ;
F_7 ( V_14 L_17 ) ;
} else {
V_106 [ 0 ] = & V_109 ;
F_26 ( V_70 , 0 , V_108 ) ;
V_82 |= ( 1 << 17 ) ;
F_7 ( V_14 L_18 ) ;
F_7 ( V_14 L_19 ) ;
}
F_47 ( V_82 , V_91 ) ;
V_83 &= V_105 | V_110 ;
if ( V_83 == V_105 ) {
F_26 ( V_70 , 0 , V_111 ) ;
V_112 . V_113 = L_20 ;
V_114 . V_113 = L_21 ;
F_7 ( V_14 L_22 ) ;
} else {
F_26 ( V_70 , V_111 , 0 ) ;
V_112 . V_113 = L_23 ;
V_114 . V_113 = L_24 ;
F_7 ( V_14 L_25 ) ;
}
F_61 ( V_115 ,
( void V_29 * ) F_62 ( V_116 ) + V_117 ) ;
F_12 () ;
F_63 (
V_118 ,
V_118 + 0x000400000 - 1 ,
V_119 ,
V_119 + 0x000400000 - 1 ,
V_120 ,
V_120 + 0x000010000 - 1 ,
V_121 , V_99 ,
0 , V_100 , 0 ) ;
F_63 (
V_118 + 0x004000000 ,
V_118 + 0x004400000 - 1 ,
V_119 + 0x004000000 ,
V_119 + 0x004400000 - 1 ,
V_120 + 0x004000000 ,
V_120 + 0x004010000 - 1 ,
V_122 , V_101 ,
0 , V_102 , 1 ) ;
V_84 = F_4 ( V_47 ) & V_123 ;
F_64 ( 64 << 20 , 2 , V_84 ) ;
F_65 ( V_106 , F_57 ( V_106 ) ) ;
if ( ( V_1 == V_10 ) ||
( V_1 == V_11 ) )
F_65 ( V_124 , F_57 ( V_124 ) ) ;
return 0 ;
}

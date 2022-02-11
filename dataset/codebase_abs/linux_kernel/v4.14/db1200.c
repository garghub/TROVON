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
F_16 ( V_32 ) ;
return V_34 ;
}
static T_2 F_17 ( int V_32 , void * V_33 )
{
void (* F_18)( struct V_35 * , unsigned long );
F_18 = F_19 ( V_36 ) ;
if ( F_18 ) {
F_18 ( V_33 , F_20 ( 200 ) ) ;
F_21 ( V_36 ) ;
}
F_22 ( 100 ) ;
if ( V_32 == V_37 )
F_23 ( V_38 ) ;
else
F_23 ( V_37 ) ;
return V_39 ;
}
static int F_24 ( void * V_35 , int V_40 )
{
int V_41 ;
if ( V_40 ) {
V_41 = F_25 ( V_37 , F_15 ,
F_17 , 0 , L_3 , V_35 ) ;
if ( V_41 )
goto V_42;
V_41 = F_25 ( V_38 , F_15 ,
F_17 , 0 , L_4 , V_35 ) ;
if ( V_41 ) {
F_26 ( V_37 , V_35 ) ;
goto V_42;
}
if ( F_4 ( V_43 ) & V_44 )
F_23 ( V_38 ) ;
else
F_23 ( V_37 ) ;
} else {
F_26 ( V_37 , V_35 ) ;
F_26 ( V_38 , V_35 ) ;
}
V_41 = 0 ;
V_42:
return V_41 ;
}
static void F_27 ( void * V_35 , int V_45 )
{
if ( V_45 ) {
F_28 ( V_46 , 0 , V_47 ) ;
F_22 ( 400 ) ;
} else
F_28 ( V_46 , V_47 , 0 ) ;
}
static int F_29 ( void * V_35 )
{
return ( F_4 ( V_48 ) & V_49 ) ? 1 : 0 ;
}
static int F_30 ( void * V_35 )
{
return ( F_4 ( V_43 ) & V_44 ) ? 1 : 0 ;
}
static void F_31 ( struct V_50 * V_51 ,
enum V_52 V_53 )
{
if ( V_53 != V_54 )
F_28 ( V_55 , V_56 , 0 ) ;
else
F_28 ( V_55 , 0 , V_56 ) ;
}
static T_2 F_32 ( int V_32 , void * V_33 )
{
F_16 ( V_32 ) ;
return V_34 ;
}
static T_2 F_33 ( int V_32 , void * V_33 )
{
void (* F_18)( struct V_35 * , unsigned long );
F_18 = F_19 ( V_36 ) ;
if ( F_18 ) {
F_18 ( V_33 , F_20 ( 200 ) ) ;
F_21 ( V_36 ) ;
}
F_22 ( 100 ) ;
if ( V_32 == V_57 )
F_23 ( V_58 ) ;
else
F_23 ( V_57 ) ;
return V_39 ;
}
static int F_34 ( void * V_35 , int V_40 )
{
int V_41 ;
if ( V_40 ) {
V_41 = F_25 ( V_57 , F_32 ,
F_33 , 0 , L_5 , V_35 ) ;
if ( V_41 )
goto V_42;
V_41 = F_25 ( V_58 , F_32 ,
F_33 , 0 , L_6 , V_35 ) ;
if ( V_41 ) {
F_26 ( V_57 , V_35 ) ;
goto V_42;
}
if ( F_4 ( V_43 ) & V_59 )
F_23 ( V_58 ) ;
else
F_23 ( V_57 ) ;
} else {
F_26 ( V_57 , V_35 ) ;
F_26 ( V_58 , V_35 ) ;
}
V_41 = 0 ;
V_42:
return V_41 ;
}
static void F_35 ( struct V_50 * V_51 ,
enum V_52 V_53 )
{
if ( V_53 != V_54 )
F_28 ( V_55 , V_60 , 0 ) ;
else
F_28 ( V_55 , 0 , V_60 ) ;
}
static void F_36 ( void * V_35 , int V_45 )
{
if ( V_45 ) {
F_28 ( V_46 , 0 , V_61 ) ;
F_22 ( 400 ) ;
} else
F_28 ( V_46 , V_61 , 0 ) ;
}
static int F_37 ( void * V_35 )
{
return ( F_4 ( V_48 ) & V_62 ) ? 1 : 0 ;
}
static int F_38 ( void * V_35 )
{
return ( F_4 ( V_43 ) & V_59 ) ? 1 : 0 ;
}
static int F_39 ( void )
{
return ( F_4 ( V_63 ) >> 8 ) & 0x0f ;
}
static int F_40 ( void )
{
F_28 ( V_46 , 0 , V_64 | V_65 |
V_66 ) ;
return 0 ;
}
static int F_41 ( void )
{
F_28 ( V_46 , V_64 | V_65 |
V_66 , 0 ) ;
return 0 ;
}
static void F_42 ( struct V_67 * V_68 , int V_69 , int V_70 )
{
if ( V_69 )
F_28 ( V_71 , 0 , V_72 ) ;
else
F_28 ( V_71 , V_72 , 0 ) ;
}
static int T_1 F_43 ( void )
{
if ( F_44 ( F_4 ( V_5 ) ) <= 3 ) {
F_7 ( V_73 L_7 ) ;
F_7 ( V_73 L_7 ) ;
F_7 ( V_73 L_8 ) ;
F_7 ( V_73 L_9 ) ;
F_7 ( V_73 L_10 ) ;
F_7 ( V_73 L_11 ) ;
F_7 ( V_73 L_7 ) ;
F_7 ( V_73 L_7 ) ;
return 1 ;
}
V_74 [ 0 ] . V_75 = V_76 ;
V_74 [ 0 ] . V_77 = V_76 + 0xff ;
V_78 [ 0 ] . V_75 = V_79 ;
V_78 [ 0 ] . V_77 = V_79 + V_80 - 1 ;
V_81 [ 0 ] . V_75 = V_82 ;
V_81 [ 0 ] . V_77 = V_82 + 0xff ;
return 0 ;
}
int T_1 F_45 ( void )
{
unsigned long V_83 ;
unsigned short V_84 ;
int V_85 , V_1 ;
struct V_86 * V_87 ;
V_1 = F_3 ( F_4 ( V_5 ) ) ;
if ( ( V_1 == V_10 ) ||
( V_1 == V_11 ) ) {
if ( F_43 () )
return - V_13 ;
}
F_46 ( V_88 , V_89 ) ;
F_47 ( V_90 , V_91 , V_88 ) ;
V_83 = F_48 ( V_92 ) ;
V_83 &= ~ ( V_93 | V_94 ) ;
V_83 &= ~ ( V_95 | V_96 | V_97 ) ;
V_83 |= V_98 ;
F_49 ( V_83 , V_92 ) ;
V_87 = F_50 ( NULL , L_12 ) ;
if ( ! F_51 ( V_87 ) ) {
V_83 = F_52 ( V_87 , 50000000 ) ;
if ( ( V_83 < 1 ) || ( abs ( 50000000 - V_83 ) > 2500000 ) )
F_53 ( L_13 ) ;
else
F_54 ( V_87 , V_83 ) ;
F_55 ( V_87 ) ;
F_56 ( V_87 ) ;
}
F_57 ( V_37 , V_99 ) ;
F_57 ( V_38 , V_99 ) ;
F_57 ( V_100 , V_99 ) ;
F_57 ( V_101 , V_99 ) ;
F_57 ( V_102 , V_99 ) ;
F_57 ( V_103 , V_99 ) ;
F_58 ( 0 , V_104 ,
F_59 ( V_104 ) ) ;
F_60 ( V_105 ,
F_59 ( V_104 ) ) ;
V_83 = F_48 ( V_92 ) & ~ V_93 ;
F_61 ( 215 , L_14 ) ;
F_62 ( 215 , 1 ) ;
F_7 ( V_14 L_15 , F_8 () ) ;
V_84 = F_4 ( V_63 ) ;
if ( V_84 & V_106 ) {
V_107 [ 0 ] = & V_108 ;
F_28 ( V_71 , V_109 , 0 ) ;
V_83 |= ( 2 << 17 ) ;
F_7 ( V_14 L_16 ) ;
F_7 ( V_14 L_17 ) ;
} else {
V_107 [ 0 ] = & V_110 ;
F_28 ( V_71 , 0 , V_109 ) ;
V_83 |= ( 1 << 17 ) ;
F_7 ( V_14 L_18 ) ;
F_7 ( V_14 L_19 ) ;
}
F_49 ( V_83 , V_92 ) ;
V_84 &= V_106 | V_111 ;
if ( V_84 == V_106 ) {
F_28 ( V_71 , 0 , V_112 ) ;
V_113 . V_114 = L_20 ;
V_115 . V_114 = L_21 ;
F_7 ( V_14 L_22 ) ;
} else {
F_28 ( V_71 , V_112 , 0 ) ;
V_113 . V_114 = L_23 ;
V_115 . V_114 = L_24 ;
F_7 ( V_14 L_25 ) ;
}
F_63 ( V_116 ,
( void V_29 * ) F_64 ( V_117 ) + V_118 ) ;
F_12 () ;
F_65 (
V_119 ,
V_119 + 0x000400000 - 1 ,
V_120 ,
V_120 + 0x000400000 - 1 ,
V_121 ,
V_121 + 0x000010000 - 1 ,
V_122 , V_100 ,
0 , V_101 , 0 ) ;
F_65 (
V_119 + 0x004000000 ,
V_119 + 0x004400000 - 1 ,
V_120 + 0x004000000 ,
V_120 + 0x004400000 - 1 ,
V_121 + 0x004000000 ,
V_121 + 0x004010000 - 1 ,
V_123 , V_102 ,
0 , V_103 , 1 ) ;
V_85 = F_4 ( V_48 ) & V_124 ;
F_66 ( 64 << 20 , 2 , V_85 ) ;
F_67 ( V_107 , F_59 ( V_107 ) ) ;
if ( ( V_1 == V_10 ) ||
( V_1 == V_11 ) )
F_67 ( V_125 , F_59 ( V_125 ) ) ;
return 0 ;
}

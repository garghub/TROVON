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
struct V_19 * V_20 = V_16 -> V_21 ;
unsigned long V_22 = ( unsigned long ) V_20 -> V_23 ;
V_22 &= 0xffffff00 ;
if ( V_18 & V_24 ) {
V_22 += V_25 ;
} else if ( V_18 & V_26 ) {
V_22 += V_27 ;
} else {
V_22 += V_28 ;
}
V_20 -> V_29 = V_20 -> V_23 = ( void V_30 * ) V_22 ;
if ( V_17 != V_31 ) {
F_10 ( V_17 , V_20 -> V_23 ) ;
F_11 () ;
}
}
static int F_12 ( struct V_15 * V_16 )
{
return F_13 ( V_32 ) & 1 ;
}
static T_2 F_14 ( int V_33 , void * V_34 )
{
void (* F_15)( struct V_35 * , unsigned long );
if ( V_33 == V_36 ) {
F_16 ( V_36 ) ;
F_17 ( V_37 ) ;
} else {
F_16 ( V_37 ) ;
F_17 ( V_36 ) ;
}
F_15 = F_18 ( V_38 ) ;
if ( F_15 ) {
F_15 ( V_34 , F_19 ( 500 ) ) ;
F_20 ( V_38 ) ;
}
return V_39 ;
}
static int F_21 ( void * V_35 , int V_40 )
{
int V_41 ;
if ( V_40 ) {
V_41 = F_22 ( V_36 , F_14 ,
0 , L_3 , V_35 ) ;
if ( V_41 )
goto V_42;
V_41 = F_22 ( V_37 , F_14 ,
0 , L_4 , V_35 ) ;
if ( V_41 ) {
F_23 ( V_36 , V_35 ) ;
goto V_42;
}
if ( F_4 ( V_43 ) & V_44 )
F_17 ( V_37 ) ;
else
F_17 ( V_36 ) ;
} else {
F_23 ( V_36 , V_35 ) ;
F_23 ( V_37 , V_35 ) ;
}
V_41 = 0 ;
V_42:
return V_41 ;
}
static void F_24 ( void * V_35 , int V_45 )
{
if ( V_45 ) {
F_25 ( V_46 , 0 , V_47 ) ;
F_26 ( 400 ) ;
} else
F_25 ( V_46 , V_47 , 0 ) ;
}
static int F_27 ( void * V_35 )
{
return ( F_4 ( V_48 ) & V_49 ) ? 1 : 0 ;
}
static int F_28 ( void * V_35 )
{
return ( F_4 ( V_43 ) & V_44 ) ? 1 : 0 ;
}
static void F_29 ( struct V_50 * V_51 ,
enum V_52 V_53 )
{
if ( V_53 != V_54 )
F_25 ( V_55 , V_56 , 0 ) ;
else
F_25 ( V_55 , 0 , V_56 ) ;
}
static T_2 F_30 ( int V_33 , void * V_34 )
{
void (* F_15)( struct V_35 * , unsigned long );
if ( V_33 == V_57 ) {
F_16 ( V_57 ) ;
F_17 ( V_58 ) ;
} else {
F_16 ( V_58 ) ;
F_17 ( V_57 ) ;
}
F_15 = F_18 ( V_38 ) ;
if ( F_15 ) {
F_15 ( V_34 , F_19 ( 500 ) ) ;
F_20 ( V_38 ) ;
}
return V_39 ;
}
static int F_31 ( void * V_35 , int V_40 )
{
int V_41 ;
if ( V_40 ) {
V_41 = F_22 ( V_57 , F_30 , 0 ,
L_5 , V_35 ) ;
if ( V_41 )
goto V_42;
V_41 = F_22 ( V_58 , F_30 , 0 ,
L_6 , V_35 ) ;
if ( V_41 ) {
F_23 ( V_57 , V_35 ) ;
goto V_42;
}
if ( F_4 ( V_43 ) & V_59 )
F_17 ( V_58 ) ;
else
F_17 ( V_57 ) ;
} else {
F_23 ( V_57 , V_35 ) ;
F_23 ( V_58 , V_35 ) ;
}
V_41 = 0 ;
V_42:
return V_41 ;
}
static void F_32 ( struct V_50 * V_51 ,
enum V_52 V_53 )
{
if ( V_53 != V_54 )
F_25 ( V_55 , V_60 , 0 ) ;
else
F_25 ( V_55 , 0 , V_60 ) ;
}
static void F_33 ( void * V_35 , int V_45 )
{
if ( V_45 ) {
F_25 ( V_46 , 0 , V_61 ) ;
F_26 ( 400 ) ;
} else
F_25 ( V_46 , V_61 , 0 ) ;
}
static int F_34 ( void * V_35 )
{
return ( F_4 ( V_48 ) & V_62 ) ? 1 : 0 ;
}
static int F_35 ( void * V_35 )
{
return ( F_4 ( V_43 ) & V_59 ) ? 1 : 0 ;
}
static int F_36 ( void )
{
return ( F_4 ( V_63 ) >> 8 ) & 0x0f ;
}
static int F_37 ( void )
{
F_25 ( V_46 , 0 , V_64 | V_65 |
V_66 ) ;
return 0 ;
}
static int F_38 ( void )
{
F_25 ( V_46 , V_64 | V_65 |
V_66 , 0 ) ;
return 0 ;
}
static void F_39 ( struct V_67 * V_68 , int V_69 , int V_70 )
{
if ( V_69 )
F_25 ( V_71 , 0 , V_72 ) ;
else
F_25 ( V_71 , V_72 , 0 ) ;
}
static int T_1 F_40 ( void )
{
if ( F_41 ( F_4 ( V_5 ) ) <= 3 ) {
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
int T_1 F_42 ( void )
{
unsigned long V_83 ;
unsigned short V_84 ;
int V_85 , V_1 ;
struct V_86 * V_87 ;
V_1 = F_3 ( F_4 ( V_5 ) ) ;
if ( ( V_1 == V_10 ) ||
( V_1 == V_11 ) ) {
if ( F_40 () )
return - V_13 ;
}
F_43 ( V_88 , V_89 ) ;
F_44 ( V_90 , V_91 , V_88 ) ;
V_83 = F_45 ( V_92 ) ;
V_83 &= ~ ( V_93 | V_94 ) ;
V_83 &= ~ ( V_95 | V_96 | V_97 ) ;
V_83 |= V_98 ;
F_46 ( V_83 , V_92 ) ;
V_87 = F_47 ( NULL , L_12 ) ;
if ( ! F_48 ( V_87 ) ) {
V_83 = F_49 ( V_87 , 50000000 ) ;
if ( ( V_83 < 1 ) || ( abs ( 50000000 - V_83 ) > 2500000 ) )
F_50 ( L_13 ) ;
else
F_51 ( V_87 , V_83 ) ;
F_52 ( V_87 ) ;
F_53 ( V_87 ) ;
}
F_54 ( V_36 , V_99 ) ;
F_54 ( V_37 , V_99 ) ;
F_54 ( V_100 , V_99 ) ;
F_54 ( V_101 , V_99 ) ;
F_54 ( V_102 , V_99 ) ;
F_54 ( V_103 , V_99 ) ;
F_55 ( 0 , V_104 ,
F_56 ( V_104 ) ) ;
F_57 ( V_105 ,
F_56 ( V_104 ) ) ;
V_83 = F_45 ( V_92 ) & ~ V_93 ;
F_58 ( 215 , L_14 ) ;
F_59 ( 215 , 1 ) ;
F_7 ( V_14 L_15 , F_8 () ) ;
V_84 = F_4 ( V_63 ) ;
if ( V_84 & V_106 ) {
V_107 [ 0 ] = & V_108 ;
F_25 ( V_71 , V_109 , 0 ) ;
V_83 |= ( 2 << 17 ) ;
F_7 ( V_14 L_16 ) ;
F_7 ( V_14 L_17 ) ;
} else {
V_107 [ 0 ] = & V_110 ;
F_25 ( V_71 , 0 , V_109 ) ;
V_83 |= ( 1 << 17 ) ;
F_7 ( V_14 L_18 ) ;
F_7 ( V_14 L_19 ) ;
}
F_46 ( V_83 , V_92 ) ;
V_84 &= V_106 | V_111 ;
if ( V_84 == V_106 ) {
F_25 ( V_71 , 0 , V_112 ) ;
V_113 . V_114 = L_20 ;
V_115 . V_114 = L_21 ;
F_7 ( V_14 L_22 ) ;
} else {
F_25 ( V_71 , V_112 , 0 ) ;
V_113 . V_114 = L_23 ;
V_115 . V_114 = L_24 ;
F_7 ( V_14 L_25 ) ;
}
F_60 ( V_116 ,
( void V_30 * ) F_61 ( V_117 ) + V_118 ) ;
F_11 () ;
F_62 (
V_119 ,
V_119 + 0x000400000 - 1 ,
V_120 ,
V_120 + 0x000400000 - 1 ,
V_121 ,
V_121 + 0x000010000 - 1 ,
V_122 , V_100 ,
0 , V_101 , 0 ) ;
F_62 (
V_119 + 0x004000000 ,
V_119 + 0x004400000 - 1 ,
V_120 + 0x004000000 ,
V_120 + 0x004400000 - 1 ,
V_121 + 0x004000000 ,
V_121 + 0x004010000 - 1 ,
V_123 , V_102 ,
0 , V_103 , 1 ) ;
V_85 = F_4 ( V_48 ) & V_124 ;
F_63 ( 64 << 20 , 2 , V_85 ) ;
F_64 ( V_107 , F_56 ( V_107 ) ) ;
if ( ( V_1 == V_10 ) ||
( V_1 == V_11 ) )
F_64 ( V_125 , F_56 ( V_125 ) ) ;
return 0 ;
}

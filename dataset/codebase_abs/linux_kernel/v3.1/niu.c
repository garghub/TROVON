static T_1 F_1 ( void T_2 * V_1 )
{
return ( ( T_1 ) F_2 ( V_1 ) ) | ( ( ( T_1 ) F_2 ( V_1 + 4UL ) ) << 32 ) ;
}
static void F_3 ( T_1 V_2 , void T_2 * V_1 )
{
F_4 ( V_2 & 0xffffffff , V_1 ) ;
F_4 ( V_2 >> 32 , V_1 + 0x4UL ) ;
}
static int F_5 ( struct V_3 * V_4 , unsigned long V_1 ,
T_1 V_5 , int V_6 , int V_7 )
{
while ( -- V_6 >= 0 ) {
T_1 V_2 = F_6 ( V_1 ) ;
if ( ! ( V_2 & V_5 ) )
break;
F_7 ( V_7 ) ;
}
if ( V_6 < 0 )
return - V_8 ;
return 0 ;
}
static int F_8 ( struct V_3 * V_4 , unsigned long V_1 ,
T_1 V_5 , int V_6 , int V_7 ,
const char * V_9 )
{
int V_10 ;
F_9 ( V_1 , V_5 ) ;
V_10 = F_5 ( V_4 , V_1 , V_5 , V_6 , V_7 ) ;
if ( V_10 )
F_10 ( V_4 -> V_11 , L_1 ,
( unsigned long long ) V_5 , V_9 ,
( unsigned long long ) F_6 ( V_1 ) ) ;
return V_10 ;
}
static int F_11 ( struct V_3 * V_4 , unsigned long V_1 ,
T_1 V_5 , int V_6 , int V_7 )
{
while ( -- V_6 >= 0 ) {
T_1 V_2 = F_12 ( V_1 ) ;
if ( ! ( V_2 & V_5 ) )
break;
F_7 ( V_7 ) ;
}
if ( V_6 < 0 )
return - V_8 ;
return 0 ;
}
static int F_13 ( struct V_3 * V_4 , unsigned long V_1 ,
T_1 V_5 , int V_6 , int V_7 ,
const char * V_9 )
{
int V_10 ;
T_1 V_2 ;
V_2 = F_12 ( V_1 ) ;
V_2 |= V_5 ;
F_14 ( V_1 , V_2 ) ;
V_10 = F_11 ( V_4 , V_1 , V_5 , V_6 , V_7 ) ;
if ( V_10 )
F_10 ( V_4 -> V_11 , L_1 ,
( unsigned long long ) V_5 , V_9 ,
( unsigned long long ) F_12 ( V_1 ) ) ;
return V_10 ;
}
static int F_15 ( struct V_3 * V_4 , unsigned long V_1 ,
T_1 V_5 , int V_6 , int V_7 )
{
while ( -- V_6 >= 0 ) {
T_1 V_2 = F_16 ( V_1 ) ;
if ( ! ( V_2 & V_5 ) )
break;
F_7 ( V_7 ) ;
}
if ( V_6 < 0 )
return - V_8 ;
return 0 ;
}
static int F_17 ( struct V_3 * V_4 , unsigned long V_1 ,
T_1 V_5 , int V_6 , int V_7 ,
const char * V_9 )
{
int V_10 ;
F_18 ( V_1 , V_5 ) ;
V_10 = F_15 ( V_4 , V_1 , V_5 , V_6 , V_7 ) ;
if ( V_10 )
F_10 ( V_4 -> V_11 , L_1 ,
( unsigned long long ) V_5 , V_9 ,
( unsigned long long ) F_16 ( V_1 ) ) ;
return V_10 ;
}
static void F_19 ( struct V_3 * V_4 , struct V_12 * V_13 , int V_14 )
{
T_1 V_2 = ( T_1 ) V_13 -> V_15 ;
if ( V_14 )
V_2 |= V_16 ;
F_18 ( F_20 ( V_13 -> V_17 ) , V_2 ) ;
}
static int F_21 ( struct V_3 * V_4 , int V_18 , int V_14 )
{
unsigned long V_19 , V_5 ;
T_1 V_2 ;
if ( V_18 < 0 || V_18 > V_20 )
return - V_21 ;
if ( V_18 < 64 ) {
V_19 = F_22 ( V_18 ) ;
V_5 = V_22 ;
} else {
V_19 = F_23 ( V_18 - 64 ) ;
V_5 = V_23 ;
}
V_2 = F_16 ( V_19 ) ;
if ( V_14 )
V_2 &= ~ V_5 ;
else
V_2 |= V_5 ;
F_18 ( V_19 , V_2 ) ;
return 0 ;
}
static int F_24 ( struct V_3 * V_4 , struct V_12 * V_13 , int V_14 )
{
struct V_24 * V_25 = V_4 -> V_25 ;
int V_26 ;
for ( V_26 = 0 ; V_26 <= V_20 ; V_26 ++ ) {
int V_10 ;
if ( V_25 -> V_27 [ V_26 ] != V_13 -> V_17 )
continue;
V_10 = F_21 ( V_4 , V_26 , V_14 ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
static int F_25 ( struct V_3 * V_4 , int V_14 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_28 ; V_26 ++ ) {
struct V_12 * V_13 = & V_4 -> V_29 [ V_26 ] ;
int V_10 ;
V_10 = F_24 ( V_4 , V_13 , V_14 ) ;
if ( V_10 )
return V_10 ;
}
for ( V_26 = 0 ; V_26 < V_4 -> V_28 ; V_26 ++ )
F_19 ( V_4 , & V_4 -> V_29 [ V_26 ] , V_14 ) ;
return 0 ;
}
static T_3 F_26 ( T_3 type , int V_30 )
{
return type << ( V_30 * 2 ) ;
}
static T_3 F_27 ( T_3 V_2 , int V_30 )
{
return ( V_2 >> ( V_30 * 2 ) ) & V_31 ;
}
static int F_28 ( struct V_3 * V_4 )
{
int V_6 = 1000 ;
T_1 V_2 ;
while ( -- V_6 > 0 ) {
V_2 = F_16 ( V_32 ) ;
if ( ( V_2 >> V_33 ) & 0x1 )
return V_2 & V_34 ;
F_7 ( 10 ) ;
}
return - V_8 ;
}
static int F_29 ( struct V_3 * V_4 , int V_30 , int V_11 , int V_1 )
{
int V_10 ;
F_18 ( V_32 , F_30 ( V_30 , V_11 , V_1 ) ) ;
V_10 = F_28 ( V_4 ) ;
if ( V_10 < 0 )
return V_10 ;
F_18 ( V_32 , F_31 ( V_30 , V_11 ) ) ;
return F_28 ( V_4 ) ;
}
static int F_32 ( struct V_3 * V_4 , int V_30 , int V_11 , int V_1 , int V_35 )
{
int V_10 ;
F_18 ( V_32 , F_30 ( V_30 , V_11 , V_1 ) ) ;
V_10 = F_28 ( V_4 ) ;
if ( V_10 < 0 )
return V_10 ;
F_18 ( V_32 , F_33 ( V_30 , V_11 , V_35 ) ) ;
V_10 = F_28 ( V_4 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
static int F_34 ( struct V_3 * V_4 , int V_30 , int V_1 )
{
F_18 ( V_32 , F_35 ( V_30 , V_1 ) ) ;
return F_28 ( V_4 ) ;
}
static int F_36 ( struct V_3 * V_4 , int V_30 , int V_1 , int V_35 )
{
int V_10 ;
F_18 ( V_32 , F_37 ( V_30 , V_1 , V_35 ) ) ;
V_10 = F_28 ( V_4 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
static int F_38 ( struct V_3 * V_4 , unsigned long V_36 , T_3 V_2 )
{
int V_10 ;
V_10 = F_32 ( V_4 , V_4 -> V_30 , V_37 ,
F_39 ( V_36 ) ,
V_2 & 0xffff ) ;
if ( ! V_10 )
V_10 = F_32 ( V_4 , V_4 -> V_30 , V_37 ,
F_40 ( V_36 ) ,
V_2 >> 16 ) ;
return V_10 ;
}
static int F_41 ( struct V_3 * V_4 , unsigned long V_36 , T_3 V_2 )
{
int V_10 ;
V_10 = F_32 ( V_4 , V_4 -> V_30 , V_37 ,
F_42 ( V_36 ) ,
V_2 & 0xffff ) ;
if ( ! V_10 )
V_10 = F_32 ( V_4 , V_4 -> V_30 , V_37 ,
F_43 ( V_36 ) ,
V_2 >> 16 ) ;
return V_10 ;
}
static int F_44 ( struct V_3 * V_4 )
{
struct V_38 * V_13 = & V_4 -> V_39 ;
T_3 V_40 , V_41 ;
unsigned long V_26 ;
V_40 = ( V_42 | V_43 ) ;
V_41 = ( V_44 | V_45 |
V_46 | V_47 |
V_48 ) ;
if ( V_13 -> V_49 == V_50 ) {
T_4 V_51 = V_52 ;
F_32 ( V_4 , V_4 -> V_30 , V_37 ,
V_53 , V_51 ) ;
V_40 |= V_54 ;
V_41 |= V_55 ;
}
for ( V_26 = 0 ; V_26 < 4 ; V_26 ++ ) {
int V_10 = F_38 ( V_4 , V_26 , V_40 ) ;
if ( V_10 )
return V_10 ;
}
for ( V_26 = 0 ; V_26 < 4 ; V_26 ++ ) {
int V_10 = F_41 ( V_4 , V_26 , V_41 ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
static int F_45 ( struct V_3 * V_4 )
{
struct V_38 * V_13 = & V_4 -> V_39 ;
T_4 V_56 , V_57 ;
int V_58 = 100 ;
T_1 V_59 ( V_60 ) , V_61 , V_2 ;
T_3 V_40 , V_41 ;
unsigned long V_26 ;
int V_10 ;
V_40 = ( V_42 | V_43 |
V_62 ) ;
V_41 = ( V_44 | V_45 |
V_46 | V_47 |
V_63 ) ;
if ( V_4 -> V_30 == 0 )
V_41 |= V_48 ;
if ( V_13 -> V_49 == V_50 ) {
T_4 V_51 = V_52 ;
F_32 ( V_4 , V_4 -> V_30 , V_37 ,
V_53 , V_51 ) ;
V_40 |= V_54 ;
V_41 |= V_55 ;
}
V_56 = ( V_64 | V_65 ) ;
V_10 = F_32 ( V_4 , V_4 -> V_30 , V_37 ,
V_66 , V_56 ) ;
if ( V_10 ) {
F_10 ( V_4 -> V_11 , L_2 ,
V_4 -> V_30 , V_67 ) ;
return V_10 ;
}
V_57 = V_64 ;
V_10 = F_32 ( V_4 , V_4 -> V_30 , V_37 ,
V_68 , V_57 ) ;
if ( V_10 ) {
F_10 ( V_4 -> V_11 , L_3 ,
V_4 -> V_30 , V_67 ) ;
return V_10 ;
}
F_7 ( 200 ) ;
for ( V_26 = 0 ; V_26 < 4 ; V_26 ++ ) {
V_10 = F_38 ( V_4 , V_26 , V_40 ) ;
if ( V_10 )
return V_10 ;
}
for ( V_26 = 0 ; V_26 < 4 ; V_26 ++ ) {
V_10 = F_41 ( V_4 , V_26 , V_41 ) ;
if ( V_10 )
return V_10 ;
}
switch ( V_4 -> V_30 ) {
case 0 :
V_2 = ( V_69 | V_70 ) ;
V_61 = V_2 ;
break;
case 1 :
V_2 = ( V_71 | V_72 ) ;
V_61 = V_2 ;
break;
default:
return - V_21 ;
}
while ( V_58 -- ) {
V_60 = F_16 ( V_73 ) ;
if ( ( V_60 & V_61 ) == V_2 )
break;
F_46 ( 500 ) ;
}
if ( ( V_60 & V_61 ) != V_2 ) {
F_10 ( V_4 -> V_11 , L_4 ,
V_4 -> V_30 , ( int ) ( V_60 & V_61 ) , ( int ) V_2 ) ;
return - V_8 ;
}
return 0 ;
}
static int F_47 ( struct V_3 * V_4 )
{
struct V_38 * V_13 = & V_4 -> V_39 ;
T_3 V_40 , V_41 , V_56 , V_57 ;
int V_58 = 100 ;
T_1 V_59 ( V_60 ) , V_61 , V_2 ;
unsigned long V_26 ;
int V_10 ;
V_40 = ( V_42 | V_43 ) ;
V_41 = ( V_44 | V_45 |
V_46 | V_47 |
V_48 ) ;
if ( V_13 -> V_49 == V_50 ) {
T_4 V_51 = V_52 ;
F_32 ( V_4 , V_4 -> V_30 , V_37 ,
V_53 , V_51 ) ;
V_40 |= V_54 ;
V_41 |= V_55 ;
}
V_56 = ( V_64 | V_74 ) ;
V_10 = F_32 ( V_4 , V_4 -> V_30 , V_37 ,
V_66 , V_56 & 0xffff ) ;
if ( V_10 ) {
F_10 ( V_4 -> V_11 , L_2 ,
V_4 -> V_30 , V_67 ) ;
return V_10 ;
}
V_57 = V_64 ;
V_10 = F_32 ( V_4 , V_4 -> V_30 , V_37 ,
V_68 , V_57 & 0xffff ) ;
if ( V_10 ) {
F_10 ( V_4 -> V_11 , L_3 ,
V_4 -> V_30 , V_67 ) ;
return V_10 ;
}
F_7 ( 200 ) ;
for ( V_26 = 0 ; V_26 < 4 ; V_26 ++ ) {
V_10 = F_38 ( V_4 , V_26 , V_40 ) ;
if ( V_10 )
return V_10 ;
}
for ( V_26 = 0 ; V_26 < 4 ; V_26 ++ ) {
V_10 = F_41 ( V_4 , V_26 , V_41 ) ;
if ( V_10 )
return V_10 ;
}
switch ( V_4 -> V_30 ) {
case 0 :
V_61 = V_75 ;
V_2 = ( V_69 |
V_70 |
V_76 |
V_77 |
V_78 |
V_79 |
V_80 ) ;
break;
case 1 :
V_61 = V_81 ;
V_2 = ( V_71 |
V_72 |
V_82 |
V_83 |
V_84 |
V_85 |
V_86 ) ;
break;
default:
return - V_21 ;
}
while ( V_58 -- ) {
V_60 = F_16 ( V_73 ) ;
if ( ( V_60 & V_61 ) == V_2 )
break;
F_46 ( 500 ) ;
}
if ( ( V_60 & V_61 ) != V_2 ) {
F_48 ( L_5 ,
V_4 -> V_30 , ( int ) ( V_60 & V_61 ) , ( int ) V_2 ) ;
V_10 = F_45 ( V_4 ) ;
if ( ! V_10 ) {
V_4 -> V_87 &= ~ V_88 ;
V_4 -> V_89 = V_90 ;
} else {
F_10 ( V_4 -> V_11 , L_6 ,
V_4 -> V_30 ) ;
return - V_8 ;
}
}
return 0 ;
}
static int F_49 ( struct V_3 * V_4 , unsigned long V_91 , T_3 * V_2 )
{
int V_10 ;
V_10 = F_29 ( V_4 , V_4 -> V_30 , V_92 , F_50 ( V_91 ) ) ;
if ( V_10 >= 0 ) {
* V_2 = ( V_10 & 0xffff ) ;
V_10 = F_29 ( V_4 , V_4 -> V_30 , V_92 ,
F_51 ( V_91 ) ) ;
if ( V_10 >= 0 )
* V_2 |= ( ( V_10 & 0xffff ) << 16 ) ;
V_10 = 0 ;
}
return V_10 ;
}
static int F_52 ( struct V_3 * V_4 , unsigned long V_91 , T_3 * V_2 )
{
int V_10 ;
V_10 = F_29 ( V_4 , V_4 -> V_30 , V_92 ,
F_53 ( V_91 ) ) ;
if ( V_10 >= 0 ) {
* V_2 = ( V_10 & 0xffff ) ;
V_10 = F_29 ( V_4 , V_4 -> V_30 , V_92 ,
F_54 ( V_91 ) ) ;
if ( V_10 >= 0 ) {
* V_2 |= ( ( V_10 & 0xffff ) << 16 ) ;
V_10 = 0 ;
}
}
return V_10 ;
}
static int F_55 ( struct V_3 * V_4 , T_3 * V_2 )
{
int V_10 ;
V_10 = F_29 ( V_4 , V_4 -> V_30 , V_92 ,
V_93 ) ;
if ( V_10 >= 0 ) {
* V_2 = ( V_10 & 0xffff ) ;
V_10 = F_29 ( V_4 , V_4 -> V_30 , V_92 ,
V_94 ) ;
if ( V_10 >= 0 ) {
* V_2 |= ( ( V_10 & 0xffff ) << 16 ) ;
V_10 = 0 ;
}
}
return V_10 ;
}
static int F_56 ( struct V_3 * V_4 , unsigned long V_91 , T_3 V_2 )
{
int V_10 ;
V_10 = F_32 ( V_4 , V_4 -> V_30 , V_92 ,
F_50 ( V_91 ) , V_2 & 0xffff ) ;
if ( ! V_10 )
V_10 = F_32 ( V_4 , V_4 -> V_30 , V_92 ,
F_51 ( V_91 ) , ( V_2 >> 16 ) ) ;
return V_10 ;
}
static int F_57 ( struct V_3 * V_4 , unsigned long V_91 , T_3 V_2 )
{
int V_10 ;
V_10 = F_32 ( V_4 , V_4 -> V_30 , V_92 ,
F_53 ( V_91 ) , V_2 & 0xffff ) ;
if ( ! V_10 )
V_10 = F_32 ( V_4 , V_4 -> V_30 , V_92 ,
F_54 ( V_91 ) , ( V_2 >> 16 ) ) ;
return V_10 ;
}
static int F_58 ( struct V_3 * V_4 )
{
T_3 V_59 ( V_95 ) ;
int V_10 ;
V_10 = F_32 ( V_4 , V_4 -> V_30 , V_92 ,
V_93 , 0x0000 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_32 ( V_4 , V_4 -> V_30 , V_92 ,
V_94 , 0xffff ) ;
if ( V_10 )
return V_10 ;
F_7 ( 200 ) ;
V_10 = F_32 ( V_4 , V_4 -> V_30 , V_92 ,
V_93 , 0xffff ) ;
if ( V_10 )
return V_10 ;
F_7 ( 200 ) ;
V_10 = F_32 ( V_4 , V_4 -> V_30 , V_92 ,
V_94 , 0x0000 ) ;
if ( V_10 )
return V_10 ;
F_7 ( 200 ) ;
V_10 = F_55 ( V_4 , & V_95 ) ;
if ( V_10 )
return V_10 ;
if ( V_95 != 0 ) {
F_10 ( V_4 -> V_11 , L_7 ,
V_4 -> V_30 , V_95 ) ;
return - V_8 ;
}
return 0 ;
}
static int F_59 ( struct V_3 * V_4 )
{
struct V_38 * V_13 = & V_4 -> V_39 ;
unsigned long V_96 , V_97 , V_26 ;
T_1 V_98 , V_99 , V_60 , V_61 , V_2 ;
int V_10 ;
switch ( V_4 -> V_30 ) {
case 0 :
V_96 = V_100 ;
V_97 = V_101 ;
break;
case 1 :
V_96 = V_102 ;
V_97 = V_103 ;
break;
default:
return - V_21 ;
}
V_98 = ( V_104 |
V_105 |
V_106 |
V_107 |
( 0x5 << V_108 ) |
( 0x5 << V_109 ) |
( 0x5 << V_110 ) |
( 0x5 << V_111 ) |
( 0x1 << V_112 ) |
( 0x1 << V_113 ) |
( 0x1 << V_114 ) |
( 0x1 << V_115 ) ) ;
V_99 = 0 ;
if ( V_13 -> V_49 == V_50 ) {
V_99 |= ( ( V_116 <<
V_117 ) |
( V_116 <<
V_118 ) |
( V_116 <<
V_119 ) |
( V_116 <<
V_120 ) ) ;
}
F_18 ( V_96 , V_98 ) ;
F_18 ( V_97 , V_99 ) ;
for ( V_26 = 0 ; V_26 < 4 ; V_26 ++ ) {
T_3 V_121 , V_122 ;
V_10 = F_49 ( V_4 , V_26 , & V_121 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_52 ( V_4 , V_26 , & V_122 ) ;
if ( V_10 )
return V_10 ;
V_121 &= ~ ( V_123 ) ;
V_121 |= ( V_124 |
( 2 << V_125 ) ) ;
V_122 &= ~ ( V_126 |
V_127 |
V_128 ) ;
V_122 |= ( V_129 |
( 0xf << V_130 ) |
( 0xff << V_131 ) |
( V_132 <<
V_133 ) ) ;
V_10 = F_56 ( V_4 , V_26 , V_121 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_57 ( V_4 , V_26 , V_122 ) ;
if ( V_10 )
return V_10 ;
}
V_10 = F_58 ( V_4 ) ;
if ( V_10 )
return V_10 ;
V_60 = F_16 ( V_73 ) ;
switch ( V_4 -> V_30 ) {
case 0 :
V_61 = V_75 ;
V_2 = ( V_69 |
V_70 |
V_76 |
V_77 |
V_78 |
V_79 |
V_80 ) ;
break;
case 1 :
V_61 = V_81 ;
V_2 = ( V_71 |
V_72 |
V_82 |
V_83 |
V_84 |
V_85 |
V_86 ) ;
break;
default:
return - V_21 ;
}
if ( ( V_60 & V_61 ) != V_2 ) {
if ( V_4 -> V_87 & V_134 ) {
V_4 -> V_87 &= ~ V_135 ;
return 0 ;
}
F_10 ( V_4 -> V_11 , L_4 ,
V_4 -> V_30 , ( int ) ( V_60 & V_61 ) , ( int ) V_2 ) ;
return - V_8 ;
}
if ( V_4 -> V_87 & V_134 )
V_4 -> V_87 |= V_135 ;
return 0 ;
}
static int F_60 ( struct V_3 * V_4 )
{
T_1 V_2 ;
V_2 = F_16 ( V_136 ) ;
V_2 &= ~ V_137 ;
switch ( V_4 -> V_30 ) {
case 0 :
V_2 |= V_138 ;
break;
case 1 :
V_2 |= V_139 ;
break;
case 2 :
V_2 |= V_140 ;
break;
case 3 :
V_2 |= V_141 ;
break;
default:
return - V_21 ;
}
F_18 ( V_136 , V_2 ) ;
return 0 ;
}
static int F_61 ( struct V_3 * V_4 )
{
struct V_38 * V_13 = & V_4 -> V_39 ;
unsigned long V_96 , V_97 , V_56 , V_26 ;
T_1 V_98 , V_99 , V_60 , V_61 , V_2 ;
int V_10 ;
T_1 V_142 , V_143 ;
V_2 = V_138 | V_139 |
V_140 | V_141 |
V_144 ;
switch ( V_4 -> V_30 ) {
case 0 :
V_142 = V_145 ;
V_96 = V_100 ;
V_97 = V_101 ;
V_56 = V_146 ;
break;
case 1 :
V_142 = V_147 ;
V_96 = V_102 ;
V_97 = V_103 ;
V_56 = V_136 ;
break;
default:
return - V_21 ;
}
V_98 = ( V_104 |
V_105 |
V_106 |
V_107 |
( 0x5 << V_108 ) |
( 0x5 << V_109 ) |
( 0x5 << V_110 ) |
( 0x5 << V_111 ) |
( 0x1 << V_112 ) |
( 0x1 << V_113 ) |
( 0x1 << V_114 ) |
( 0x1 << V_115 ) ) ;
V_99 = 0 ;
if ( V_13 -> V_49 == V_50 ) {
V_99 |= ( ( V_116 <<
V_117 ) |
( V_116 <<
V_118 ) |
( V_116 <<
V_119 ) |
( V_116 <<
V_120 ) ) ;
}
F_18 ( V_148 , V_142 ) ;
F_46 ( 20 ) ;
V_143 = F_16 ( V_148 ) ;
V_143 &= ~ V_142 ;
F_18 ( V_56 , V_2 ) ;
F_18 ( V_96 , V_98 ) ;
F_18 ( V_97 , V_99 ) ;
F_18 ( V_148 , V_143 ) ;
F_46 ( 2000 ) ;
for ( V_26 = 0 ; V_26 < 4 ; V_26 ++ ) {
T_3 V_121 , V_122 ;
V_10 = F_49 ( V_4 , V_26 , & V_121 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_52 ( V_4 , V_26 , & V_122 ) ;
if ( V_10 )
return V_10 ;
V_121 &= ~ ( V_123 ) ;
V_121 |= ( V_124 |
( 2 << V_125 ) ) ;
V_122 &= ~ ( V_126 |
V_127 |
V_128 ) ;
V_122 |= ( V_129 |
( 0xf << V_130 ) |
( 0xff << V_131 ) |
( V_132 <<
V_133 ) ) ;
V_10 = F_56 ( V_4 , V_26 , V_121 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_57 ( V_4 , V_26 , V_122 ) ;
if ( V_10 )
return V_10 ;
}
V_60 = F_16 ( V_73 ) ;
switch ( V_4 -> V_30 ) {
case 0 :
V_2 = ( V_69 | V_70 ) ;
V_61 = V_2 ;
break;
case 1 :
V_2 = ( V_71 | V_72 ) ;
V_61 = V_2 ;
break;
default:
return - V_21 ;
}
if ( ( V_60 & V_61 ) != V_2 ) {
F_10 ( V_4 -> V_11 , L_4 ,
V_4 -> V_30 , ( int ) ( V_60 & V_61 ) , ( int ) V_2 ) ;
return - V_8 ;
}
return 0 ;
}
static int F_62 ( struct V_3 * V_4 , int * V_149 )
{
struct V_38 * V_13 = & V_4 -> V_39 ;
int V_150 ;
T_1 V_2 ;
T_4 V_151 ;
unsigned long V_87 ;
T_5 V_152 ;
V_150 = 0 ;
V_151 = V_153 ;
V_152 = V_154 ;
F_63 ( & V_4 -> V_155 , V_87 ) ;
V_2 = F_64 ( V_156 ) ;
if ( V_2 & V_157 ) {
V_150 = 1 ;
V_151 = V_158 ;
V_152 = V_159 ;
}
V_13 -> V_160 = V_151 ;
V_13 -> V_161 = V_152 ;
F_65 ( & V_4 -> V_155 , V_87 ) ;
* V_149 = V_150 ;
return 0 ;
}
static int F_66 ( struct V_3 * V_4 , int * V_149 )
{
unsigned long V_87 ;
struct V_38 * V_13 = & V_4 -> V_39 ;
int V_150 = 0 ;
int V_162 = 1 ;
T_1 V_2 , V_163 ;
T_4 V_151 ;
T_5 V_152 ;
if ( ! ( V_4 -> V_87 & V_88 ) )
return F_62 ( V_4 , V_149 ) ;
V_151 = V_153 ;
V_152 = V_154 ;
F_63 ( & V_4 -> V_155 , V_87 ) ;
V_2 = F_67 ( F_68 ( 0 ) ) ;
V_163 = F_6 ( V_164 ) ;
if ( V_163 & 0x01000000 )
V_162 = 0 ;
if ( ( V_2 & 0x1000ULL ) && V_162 ) {
V_150 = 1 ;
V_151 = V_165 ;
V_152 = V_159 ;
}
V_13 -> V_160 = V_151 ;
V_13 -> V_161 = V_152 ;
F_65 ( & V_4 -> V_155 , V_87 ) ;
* V_149 = V_150 ;
return 0 ;
}
static int F_69 ( struct V_3 * V_4 , int * V_149 )
{
struct V_38 * V_13 = & V_4 -> V_39 ;
int V_10 ;
int V_166 , V_167 , V_168 , V_169 , V_170 , V_171 , V_172 ;
int V_173 , V_174 , V_160 , V_161 ;
V_10 = F_34 ( V_4 , V_4 -> V_175 , V_176 ) ;
if ( F_70 ( V_10 < 0 ) )
return V_10 ;
V_171 = V_10 ;
V_10 = F_34 ( V_4 , V_4 -> V_175 , V_177 ) ;
if ( F_70 ( V_10 < 0 ) )
return V_10 ;
V_166 = V_10 ;
V_10 = F_34 ( V_4 , V_4 -> V_175 , V_178 ) ;
if ( F_70 ( V_10 < 0 ) )
return V_10 ;
V_167 = V_10 ;
V_10 = F_34 ( V_4 , V_4 -> V_175 , V_179 ) ;
if ( F_70 ( V_10 < 0 ) )
return V_10 ;
V_170 = V_10 ;
if ( F_71 ( V_166 & V_180 ) ) {
V_10 = F_34 ( V_4 , V_4 -> V_175 , V_181 ) ;
if ( F_70 ( V_10 < 0 ) )
return V_10 ;
V_172 = V_10 ;
V_10 = F_34 ( V_4 , V_4 -> V_175 , V_182 ) ;
if ( F_70 ( V_10 < 0 ) )
return V_10 ;
V_168 = V_10 ;
V_10 = F_34 ( V_4 , V_4 -> V_175 , V_183 ) ;
if ( F_70 ( V_10 < 0 ) )
return V_10 ;
V_169 = V_10 ;
} else
V_172 = V_168 = V_169 = 0 ;
V_173 = 0 ;
if ( V_166 & V_184 )
V_173 |= V_185 ;
if ( V_166 & V_186 )
V_173 |= V_187 ;
if ( V_166 & V_188 )
V_173 |= V_189 ;
if ( V_166 & V_190 )
V_173 |= V_191 ;
if ( V_166 & V_192 )
V_173 |= V_193 ;
if ( V_172 & V_194 )
V_173 |= V_195 ;
if ( V_172 & V_196 )
V_173 |= V_197 ;
V_13 -> V_173 = V_173 ;
V_174 = 0 ;
if ( V_167 & V_198 )
V_174 |= V_199 ;
if ( V_167 & V_200 )
V_174 |= V_201 ;
if ( V_167 & V_202 )
V_174 |= V_203 ;
if ( V_167 & V_204 )
V_174 |= V_205 ;
if ( V_168 & V_206 )
V_174 |= V_207 ;
if ( V_168 & V_208 )
V_174 |= V_209 ;
if ( V_171 & V_210 ) {
int V_211 , V_212 ;
V_13 -> V_213 = 1 ;
V_174 |= V_214 ;
V_211 = V_167 & V_170 ;
V_212 = ( V_168 << 2 ) & V_169 ;
if ( V_212 & ( V_215 | V_216 ) )
V_160 = V_158 ;
else if ( V_211 & V_217 )
V_160 = V_218 ;
else if ( V_211 & ( V_219 | V_220 ) )
V_160 = V_221 ;
else
V_160 = V_153 ;
if ( ( V_212 & V_215 ) || ( V_211 & V_222 ) )
V_161 = V_159 ;
else if ( V_160 != V_153 )
V_161 = V_223 ;
else
V_161 = V_154 ;
} else {
V_13 -> V_213 = 0 ;
if ( ( V_171 & V_224 ) && ! ( V_171 & V_225 ) )
V_160 = V_158 ;
else if ( V_171 & V_225 )
V_160 = V_218 ;
else
V_160 = V_221 ;
if ( V_171 & V_226 )
V_161 = V_159 ;
else
V_161 = V_223 ;
}
V_13 -> V_227 = V_174 ;
V_13 -> V_160 = V_160 ;
V_13 -> V_161 = V_161 ;
* V_149 = ! ! ( V_166 & V_228 ) ;
return 0 ;
}
static int F_72 ( struct V_3 * V_4 , int * V_149 )
{
struct V_38 * V_13 = & V_4 -> V_39 ;
T_4 V_151 , V_166 ;
unsigned long V_87 ;
T_5 V_152 ;
int V_10 , V_150 ;
V_150 = 0 ;
V_151 = V_153 ;
V_152 = V_154 ;
F_63 ( & V_4 -> V_155 , V_87 ) ;
V_10 = - V_21 ;
V_10 = F_34 ( V_4 , V_4 -> V_175 , V_177 ) ;
if ( V_10 < 0 )
goto V_229;
V_166 = V_10 ;
if ( V_166 & V_228 ) {
T_4 V_230 , V_170 ;
V_10 = F_34 ( V_4 , V_4 -> V_175 , V_178 ) ;
if ( V_10 < 0 )
goto V_229;
V_230 = V_10 ;
V_10 = F_34 ( V_4 , V_4 -> V_175 , V_179 ) ;
if ( V_10 < 0 )
goto V_229;
V_170 = V_10 ;
V_10 = F_34 ( V_4 , V_4 -> V_175 , V_181 ) ;
if ( V_10 < 0 )
goto V_229;
V_150 = 1 ;
V_151 = V_158 ;
V_152 = V_159 ;
}
V_13 -> V_160 = V_151 ;
V_13 -> V_161 = V_152 ;
V_10 = 0 ;
V_229:
F_65 ( & V_4 -> V_155 , V_87 ) ;
* V_149 = V_150 ;
return V_10 ;
}
static int F_73 ( struct V_3 * V_4 , int * V_149 )
{
struct V_38 * V_13 = & V_4 -> V_39 ;
unsigned long V_87 ;
int V_10 ;
F_63 ( & V_4 -> V_155 , V_87 ) ;
V_10 = F_69 ( V_4 , V_149 ) ;
V_13 -> V_173 |= V_231 ;
V_13 -> V_227 |= V_232 ;
F_65 ( & V_4 -> V_155 , V_87 ) ;
return V_10 ;
}
static int F_74 ( struct V_3 * V_4 )
{
int V_10 , V_6 ;
V_10 = F_29 ( V_4 , V_4 -> V_175 ,
V_233 , V_176 ) ;
if ( V_10 < 0 || V_10 == 0xffff )
return V_10 ;
V_10 |= V_234 ;
V_10 = F_32 ( V_4 , V_4 -> V_175 , V_233 ,
V_176 , V_10 ) ;
if ( V_10 )
return V_10 ;
V_6 = 1000 ;
while ( -- V_6 >= 0 ) {
V_10 = F_29 ( V_4 , V_4 -> V_175 ,
V_233 , V_176 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( ! ( V_10 & V_234 ) )
break;
}
if ( V_6 < 0 ) {
F_10 ( V_4 -> V_11 , L_8 ,
V_4 -> V_30 , ( V_10 & 0xffff ) ) ;
return - V_8 ;
}
return 0 ;
}
static int F_75 ( struct V_3 * V_4 , int V_1 )
{
int V_10 = F_29 ( V_4 , V_4 -> V_175 , V_235 , V_1 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_235 , V_1 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
static int F_76 ( struct V_3 * V_4 )
{
int V_10 ;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_235 ,
V_236 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 &= ~ V_237 ;
V_10 |= ( 0x3 << V_238 ) ;
V_10 |= V_239 ;
V_10 = F_32 ( V_4 , V_4 -> V_175 , V_235 ,
V_236 , V_10 ) ;
if ( V_10 )
return V_10 ;
F_46 ( 1000 ) ;
return 0 ;
}
static int F_77 ( struct V_3 * V_4 )
{
int V_10 ;
V_10 = F_32 ( V_4 , V_4 -> V_175 ,
V_235 , V_240 ,
( V_241 |
V_242 |
V_243 |
V_244 |
V_245 |
V_246 |
V_247 |
V_248 |
( 0x3f << V_249 ) ) ) ;
if ( V_10 )
return V_10 ;
V_10 = F_32 ( V_4 , V_4 -> V_175 ,
V_235 , V_250 ,
( V_251 |
( 1 << V_252 ) |
( 2 << V_253 ) |
V_254 ) ) ;
if ( V_10 )
return V_10 ;
V_10 = F_75 ( V_4 , V_240 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_75 ( V_4 , V_250 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_235 ,
V_236 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 &= ~ V_237 ;
V_10 |= ( 0x3 << V_238 ) ;
V_10 = F_32 ( V_4 , V_4 -> V_175 , V_235 ,
V_236 , V_10 ) ;
if ( V_10 )
return V_10 ;
F_46 ( 1000 ) ;
return 0 ;
}
static int F_78 ( struct V_3 * V_4 , int V_2 )
{
int V_10 ;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_255 ,
V_256 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 &= ~ F_79 ( V_257 , V_258 ) ;
V_10 |= F_79 ( V_257 , V_2 ) ;
return F_32 ( V_4 , V_4 -> V_175 , V_255 ,
V_256 , V_10 ) ;
}
static int F_80 ( struct V_3 * V_4 , int V_259 )
{
int V_10 ;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_255 ,
V_260 ) ;
if ( V_10 >= 0 ) {
V_10 &= ~ V_261 ;
V_10 |= ( V_259 << 4 ) ;
V_10 = F_32 ( V_4 , V_4 -> V_175 , V_255 ,
V_260 , V_10 ) ;
}
return V_10 ;
}
static int F_81 ( struct V_3 * V_4 )
{
int V_10 ;
V_10 = F_80 ( V_4 , V_262 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_78 ( V_4 , V_263 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_264 ,
V_265 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 |= V_266 ;
V_10 = F_32 ( V_4 , V_4 -> V_175 , V_264 ,
V_265 , V_10 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_267 ,
V_268 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_4 -> V_39 . V_49 == V_269 )
V_10 |= V_270 ;
else
V_10 &= ~ V_270 ;
V_10 = F_32 ( V_4 , V_4 -> V_175 , V_267 ,
V_268 , V_10 ) ;
if ( V_10 < 0 )
return V_10 ;
return F_32 ( V_4 , V_4 -> V_175 , V_267 ,
V_271 , V_272 ) ;
}
static int F_82 ( struct V_3 * V_4 )
{
T_4 V_273 , V_274 ;
int V_10 = 0 ;
#if 1
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_275 ,
V_183 ) ;
if ( V_10 < 0 )
return V_10 ;
F_48 ( L_9 , V_4 -> V_30 , V_10 ) ;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_235 , 0x20 ) ;
if ( V_10 < 0 )
return V_10 ;
F_48 ( L_10 , V_4 -> V_30 , V_10 ) ;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_233 ,
V_276 ) ;
if ( V_10 < 0 )
return V_10 ;
F_48 ( L_11 , V_4 -> V_30 , V_10 ) ;
#endif
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_235 ,
V_277 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_235 ,
V_277 ) ;
if ( V_10 < 0 )
return V_10 ;
V_273 = V_10 ;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_235 ,
V_278 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_235 ,
V_278 ) ;
if ( V_10 < 0 )
return V_10 ;
V_274 = V_10 ;
if ( V_273 != 0x03fc ) {
if ( ( V_273 == 0x43bc ) && ( V_274 != 0 ) ) {
F_48 ( L_12 ,
V_4 -> V_30 ) ;
} else if ( V_273 == 0x639c ) {
F_48 ( L_13 ,
V_4 -> V_30 ) ;
}
}
return 0 ;
}
static int F_83 ( struct V_3 * V_4 )
{
struct V_38 * V_13 = & V_4 -> V_39 ;
int V_10 ;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_279 ,
V_176 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 &= ~ V_280 ;
if ( V_13 -> V_49 == V_269 )
V_10 |= V_280 ;
V_10 = F_32 ( V_4 , V_4 -> V_175 , V_279 ,
V_176 , V_10 ) ;
if ( V_10 )
return V_10 ;
return 0 ;
}
static int F_84 ( struct V_3 * V_4 )
{
int V_10 = 0 ;
T_1 V_2 ;
if ( ( V_4 -> V_87 & V_134 ) &&
( V_4 -> V_87 & V_135 ) == 0 )
return V_10 ;
V_2 = F_6 ( V_281 ) ;
V_2 &= ~ V_282 ;
V_2 |= V_283 ;
F_9 ( V_281 , V_2 ) ;
V_2 = F_16 ( V_284 ) ;
V_2 |= V_285 ;
F_18 ( V_284 , V_2 ) ;
V_10 = F_74 ( V_4 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_83 ( V_4 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_76 ( V_4 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_82 ( V_4 ) ;
if ( V_10 )
return V_10 ;
return 0 ;
}
static int F_85 ( struct V_3 * V_4 )
{
int V_10 ;
V_10 = F_74 ( V_4 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_77 ( V_4 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_83 ( V_4 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_82 ( V_4 ) ;
if ( V_10 )
return V_10 ;
return 0 ;
}
static int F_86 ( struct V_3 * V_4 )
{
int V_286 , V_10 ;
T_1 V_2 ;
V_2 = F_6 ( V_281 ) ;
V_2 &= ~ V_282 ;
V_2 |= V_283 ;
F_9 ( V_281 , V_2 ) ;
V_2 = F_16 ( V_284 ) ;
V_2 |= V_285 ;
F_18 ( V_284 , V_2 ) ;
V_286 = F_27 ( V_4 -> V_25 -> V_287 , V_4 -> V_30 ) ;
V_286 = V_4 -> V_25 -> V_288 . V_286 [ V_286 ] [ V_4 -> V_30 ] ;
switch ( V_286 & V_289 ) {
case V_290 :
V_10 = F_81 ( V_4 ) ;
break;
default:
V_10 = F_85 ( V_4 ) ;
break;
}
return V_10 ;
}
static int F_87 ( struct V_3 * V_4 )
{
int V_6 , V_10 ;
V_10 = F_36 ( V_4 , V_4 -> V_175 , V_176 , V_234 ) ;
if ( V_10 )
return V_10 ;
V_6 = 1000 ;
while ( -- V_6 >= 0 ) {
F_7 ( 500 ) ;
V_10 = F_34 ( V_4 , V_4 -> V_175 , V_176 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( ! ( V_10 & V_234 ) )
break;
}
if ( V_6 < 0 ) {
F_10 ( V_4 -> V_11 , L_14 ,
V_4 -> V_30 , V_10 ) ;
return - V_8 ;
}
return 0 ;
}
static int F_88 ( struct V_3 * V_4 )
{
int V_10 ;
T_1 V_2 ;
T_4 V_171 , V_166 , V_291 ;
V_2 = F_16 ( V_284 ) ;
V_2 &= ~ V_285 ;
F_18 ( V_284 , V_2 ) ;
V_10 = F_87 ( V_4 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_34 ( V_4 , V_4 -> V_175 , V_177 ) ;
if ( V_10 < 0 )
return V_10 ;
V_166 = V_10 ;
V_291 = 0 ;
if ( V_166 & V_180 ) {
V_10 = F_34 ( V_4 , V_4 -> V_175 , V_181 ) ;
if ( V_10 < 0 )
return V_10 ;
V_291 = V_10 ;
}
V_171 = 0 ;
V_10 = F_36 ( V_4 , V_4 -> V_175 , V_176 , V_171 ) ;
if ( V_10 )
return V_10 ;
if ( V_166 & V_180 ) {
T_4 V_168 = 0 ;
if ( V_291 & V_196 )
V_168 |= V_208 ;
V_10 = F_36 ( V_4 , V_4 -> V_175 , V_182 , V_168 ) ;
if ( V_10 )
return V_10 ;
}
V_171 = ( V_224 | V_226 ) ;
V_10 = F_36 ( V_4 , V_4 -> V_175 , V_176 , V_171 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_34 ( V_4 , V_4 -> V_175 , V_176 ) ;
if ( V_10 < 0 )
return V_10 ;
V_171 = F_34 ( V_4 , V_4 -> V_175 , V_176 ) ;
V_10 = F_34 ( V_4 , V_4 -> V_175 , V_177 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
static int F_89 ( struct V_3 * V_4 )
{
struct V_38 * V_13 = & V_4 -> V_39 ;
T_4 V_171 , V_166 , V_230 , V_291 ;
int V_10 ;
V_10 = F_87 ( V_4 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_34 ( V_4 , V_4 -> V_175 , V_177 ) ;
if ( V_10 < 0 )
return V_10 ;
V_166 = V_10 ;
V_291 = 0 ;
if ( V_166 & V_180 ) {
V_10 = F_34 ( V_4 , V_4 -> V_175 , V_181 ) ;
if ( V_10 < 0 )
return V_10 ;
V_291 = V_10 ;
}
V_171 = 0 ;
V_10 = F_36 ( V_4 , V_4 -> V_175 , V_176 , V_171 ) ;
if ( V_10 )
return V_10 ;
if ( V_13 -> V_49 == V_269 ) {
V_171 |= V_280 ;
if ( V_13 -> V_160 == V_158 )
V_171 |= V_224 ;
if ( V_13 -> V_161 == V_159 )
V_171 |= V_226 ;
}
if ( V_13 -> V_49 == V_50 ) {
T_4 V_292 ;
V_292 = ( V_293 |
V_294 ) ;
V_10 = F_36 ( V_4 , V_4 -> V_175 , V_295 , V_292 ) ;
if ( V_10 )
return V_10 ;
}
if ( V_13 -> V_296 ) {
T_4 V_168 ;
V_230 = V_297 | V_298 ;
if ( ( V_166 & V_186 ) &&
( V_13 -> V_174 & V_199 ) )
V_230 |= V_198 ;
if ( ( V_166 & V_188 ) &&
( V_13 -> V_174 & V_201 ) )
V_230 |= V_200 ;
if ( ( V_166 & V_190 ) &&
( V_13 -> V_174 & V_203 ) )
V_230 |= V_202 ;
if ( ( V_166 & V_192 ) &&
( V_13 -> V_174 & V_205 ) )
V_230 |= V_204 ;
V_10 = F_36 ( V_4 , V_4 -> V_175 , V_178 , V_230 ) ;
if ( V_10 )
return V_10 ;
if ( F_71 ( V_166 & V_180 ) ) {
V_168 = 0 ;
if ( ( V_291 & V_194 ) &&
( V_13 -> V_174 & V_207 ) )
V_168 |= V_206 ;
if ( ( V_291 & V_196 ) &&
( V_13 -> V_174 & V_209 ) )
V_168 |= V_208 ;
V_10 = F_36 ( V_4 , V_4 -> V_175 ,
V_182 , V_168 ) ;
if ( V_10 )
return V_10 ;
}
V_171 |= ( V_210 | V_299 ) ;
} else {
int V_300 ;
if ( V_13 -> V_301 == V_159 ) {
V_171 |= V_226 ;
V_300 = 1 ;
} else if ( V_13 -> V_301 == V_223 )
V_300 = 0 ;
else
return - V_21 ;
if ( V_13 -> V_302 == V_158 ) {
if ( ( V_300 && ! ( V_291 & V_196 ) ) ||
( ! V_300 && ! ( V_291 & V_194 ) ) )
return - V_21 ;
V_171 |= V_224 ;
} else if ( V_13 -> V_302 == V_218 ) {
if ( ( V_300 && ! ( V_166 & V_192 ) ) ||
( ! V_300 && ! ( V_166 & V_190 ) ) )
return - V_21 ;
V_171 |= V_225 ;
} else if ( V_13 -> V_302 == V_221 ) {
if ( ( V_300 && ! ( V_166 & V_188 ) ) ||
( ! V_300 && ! ( V_166 & V_186 ) ) )
return - V_21 ;
} else
return - V_21 ;
}
V_10 = F_36 ( V_4 , V_4 -> V_175 , V_176 , V_171 ) ;
if ( V_10 )
return V_10 ;
#if 0
err = mii_read(np, np->phy_addr, MII_BMCR);
if (err < 0)
return err;
bmcr = err;
err = mii_read(np, np->phy_addr, MII_BMSR);
if (err < 0)
return err;
bmsr = err;
pr_info("Port %u after MII init bmcr[%04x] bmsr[%04x]\n",
np->port, bmcr, bmsr);
#endif
return 0 ;
}
static int F_90 ( struct V_3 * V_4 )
{
T_1 V_2 ;
V_2 = F_16 ( V_284 ) ;
V_2 &= ~ V_285 ;
F_18 ( V_284 , V_2 ) ;
return F_89 ( V_4 ) ;
}
static int F_91 ( struct V_3 * V_4 )
{
const struct V_303 * V_304 = V_4 -> V_305 ;
int V_10 ;
V_10 = 0 ;
if ( V_304 -> V_306 )
V_10 = V_304 -> V_306 ( V_4 ) ;
return V_10 ;
}
static int F_92 ( struct V_3 * V_4 )
{
const struct V_303 * V_304 = V_4 -> V_305 ;
int V_10 ;
V_10 = 0 ;
if ( V_304 -> V_307 )
V_10 = V_304 -> V_307 ( V_4 ) ;
return V_10 ;
}
static int F_93 ( struct V_3 * V_4 , int V_150 )
{
struct V_38 * V_13 = & V_4 -> V_39 ;
struct V_308 * V_11 = V_4 -> V_11 ;
unsigned long V_87 ;
if ( ! F_94 ( V_11 ) && V_150 ) {
F_95 ( V_4 , V_309 , V_11 , L_15 ,
V_13 -> V_160 == V_165 ? L_16 :
V_13 -> V_160 == V_158 ? L_17 :
V_13 -> V_160 == V_218 ? L_18 :
L_19 ,
V_13 -> V_161 == V_159 ? L_20 : L_21 ) ;
F_63 ( & V_4 -> V_155 , V_87 ) ;
F_96 ( V_4 ) ;
F_97 ( V_4 , 1 ) ;
F_65 ( & V_4 -> V_155 , V_87 ) ;
F_98 ( V_11 ) ;
} else if ( F_94 ( V_11 ) && ! V_150 ) {
F_99 ( V_4 , V_309 , V_11 , L_22 ) ;
F_63 ( & V_4 -> V_155 , V_87 ) ;
F_97 ( V_4 , 0 ) ;
F_65 ( & V_4 -> V_155 , V_87 ) ;
F_100 ( V_11 ) ;
}
return 0 ;
}
static int F_101 ( struct V_3 * V_4 , int * V_149 )
{
int V_10 , V_150 , V_310 , V_311 ;
V_150 = 0 ;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_267 ,
V_312 ) ;
if ( V_10 < 0 )
goto V_229;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_267 ,
V_313 ) ;
if ( V_10 < 0 )
goto V_229;
V_310 = ( ( V_10 & V_314 ) ? 1 : 0 ) ;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_264 ,
V_313 ) ;
if ( V_10 < 0 )
goto V_229;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_264 ,
V_313 ) ;
if ( V_10 < 0 )
goto V_229;
V_311 = ( ( V_10 & V_314 ) ? 1 : 0 ) ;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_315 ,
V_316 ) ;
if ( V_10 < 0 )
goto V_229;
if ( V_10 == ( V_317 | V_318 |
V_319 | V_320 |
V_321 | V_322 |
0x800 ) )
V_150 = ( V_310 && V_311 ) ? 1 : 0 ;
V_4 -> V_39 . V_160 = V_165 ;
V_4 -> V_39 . V_161 = V_159 ;
V_10 = 0 ;
V_229:
F_78 ( V_4 , ( V_150 ?
V_323 :
V_263 ) ) ;
* V_149 = V_150 ;
return V_10 ;
}
static int F_102 ( struct V_3 * V_4 , int * V_149 )
{
int V_10 , V_150 ;
V_150 = 0 ;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_275 ,
V_324 ) ;
if ( V_10 < 0 || V_10 == 0xffff )
goto V_229;
if ( ! ( V_10 & V_325 ) ) {
V_10 = 0 ;
goto V_229;
}
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_279 ,
V_326 ) ;
if ( V_10 < 0 )
goto V_229;
if ( ! ( V_10 & V_327 ) ) {
V_10 = 0 ;
goto V_229;
}
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_233 ,
V_328 ) ;
if ( V_10 < 0 )
goto V_229;
if ( V_10 != ( V_317 |
V_322 |
V_329 |
V_318 |
V_319 |
V_320 |
V_321 ) ) {
V_10 = 0 ;
V_4 -> V_39 . V_160 = V_153 ;
V_4 -> V_39 . V_161 = V_154 ;
goto V_229;
}
V_150 = 1 ;
V_4 -> V_39 . V_160 = V_165 ;
V_4 -> V_39 . V_161 = V_159 ;
V_10 = 0 ;
V_229:
* V_149 = V_150 ;
return V_10 ;
}
static int F_103 ( struct V_3 * V_4 , int * V_149 )
{
int V_10 , V_150 ;
V_150 = 0 ;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_275 ,
V_324 ) ;
if ( V_10 < 0 )
goto V_229;
if ( ! ( V_10 & V_325 ) ) {
V_10 = 0 ;
goto V_229;
}
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_279 ,
V_326 ) ;
if ( V_10 < 0 )
goto V_229;
if ( ! ( V_10 & V_327 ) ) {
V_10 = 0 ;
goto V_229;
}
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_233 ,
V_328 ) ;
if ( V_10 < 0 )
goto V_229;
if ( V_10 != ( V_317 |
V_322 |
V_318 |
V_319 |
V_320 |
V_321 ) ) {
V_10 = 0 ;
goto V_229;
}
V_150 = 1 ;
V_4 -> V_39 . V_160 = V_165 ;
V_4 -> V_39 . V_161 = V_159 ;
V_10 = 0 ;
V_229:
* V_149 = V_150 ;
return V_10 ;
}
static int F_104 ( struct V_3 * V_4 , int * V_149 )
{
unsigned long V_87 ;
int V_10 = - V_21 ;
F_63 ( & V_4 -> V_155 , V_87 ) ;
if ( V_4 -> V_39 . V_49 == V_330 ) {
int V_286 ;
V_286 = F_27 ( V_4 -> V_25 -> V_287 , V_4 -> V_30 ) ;
V_286 = V_4 -> V_25 -> V_288 . V_286 [ V_286 ] [ V_4 -> V_30 ] ;
switch ( V_286 & V_289 ) {
case V_290 :
V_10 = F_101 ( V_4 , V_149 ) ;
break;
default:
V_10 = F_103 ( V_4 , V_149 ) ;
break;
}
}
F_65 ( & V_4 -> V_155 , V_87 ) ;
return V_10 ;
}
static int F_105 ( struct V_3 * V_4 )
{
T_1 V_60 , V_61 , V_2 ;
V_60 = F_16 ( V_73 ) ;
switch ( V_4 -> V_30 ) {
case 0 :
V_61 = V_75 ;
V_2 = ( V_69 |
V_70 |
V_76 |
V_77 |
V_78 |
V_79 |
V_80 ) ;
break;
case 1 :
V_61 = V_81 ;
V_2 = ( V_71 |
V_72 |
V_82 |
V_83 |
V_84 |
V_85 |
V_86 ) ;
break;
default:
return 0 ;
}
if ( ( V_60 & V_61 ) != V_2 )
return 0 ;
return 1 ;
}
static int F_106 ( struct V_3 * V_4 , int * V_149 )
{
unsigned long V_87 ;
int V_10 = 0 ;
int V_331 ;
int V_332 ;
F_63 ( & V_4 -> V_155 , V_87 ) ;
if ( V_4 -> V_39 . V_49 == V_330 ) {
V_332 = ( V_4 -> V_87 & V_135 ) ?
1 : 0 ;
V_331 = F_105 ( V_4 ) ;
if ( V_331 != V_332 ) {
if ( V_331 ) {
V_4 -> V_87 |= V_135 ;
if ( V_4 -> V_305 -> V_306 )
V_10 = V_4 -> V_305 -> V_306 ( V_4 ) ;
if ( V_10 ) {
V_10 = F_29 ( V_4 , V_4 -> V_175 ,
V_233 , V_176 ) ;
if ( V_10 == 0xffff ) {
goto V_229;
}
V_4 -> V_87 &= ~ V_135 ;
}
} else {
V_4 -> V_87 &= ~ V_135 ;
* V_149 = 0 ;
F_99 ( V_4 , V_309 , V_4 -> V_11 ,
L_23 ) ;
}
}
V_229:
if ( V_4 -> V_87 & V_135 ) {
V_10 = F_102 ( V_4 , V_149 ) ;
if ( V_10 == 0xffff ) {
* V_149 = 1 ;
V_4 -> V_39 . V_160 = V_165 ;
V_4 -> V_39 . V_161 = V_159 ;
}
}
}
F_65 ( & V_4 -> V_155 , V_87 ) ;
return 0 ;
}
static int F_107 ( struct V_3 * V_4 , int * V_149 )
{
const struct V_303 * V_304 = V_4 -> V_305 ;
int V_10 ;
V_10 = 0 ;
if ( V_304 -> V_333 )
V_10 = V_304 -> V_333 ( V_4 , V_149 ) ;
return V_10 ;
}
static void F_108 ( unsigned long V_334 )
{
struct V_3 * V_4 = (struct V_3 * ) V_334 ;
unsigned long V_335 ;
int V_10 , V_150 ;
V_10 = F_107 ( V_4 , & V_150 ) ;
if ( ! V_10 )
F_93 ( V_4 , V_150 ) ;
if ( F_94 ( V_4 -> V_11 ) )
V_335 = 5 * V_336 ;
else
V_335 = 1 * V_336 ;
V_4 -> V_15 . V_337 = V_338 + V_335 ;
F_109 ( & V_4 -> V_15 ) ;
}
static int F_110 ( struct V_3 * V_4 )
{
struct V_38 * V_13 = & V_4 -> V_39 ;
unsigned long V_96 , V_97 , V_56 , V_26 ;
T_1 V_98 , V_99 , V_60 , V_61 , V_2 ;
switch ( V_4 -> V_30 ) {
case 0 :
V_96 = V_100 ;
V_97 = V_101 ;
V_56 = V_146 ;
break;
case 1 :
V_96 = V_102 ;
V_97 = V_103 ;
V_56 = V_136 ;
break;
default:
return - V_21 ;
}
V_98 = ( V_104 |
V_105 |
V_106 |
V_107 |
( 0x5 << V_108 ) |
( 0x5 << V_109 ) |
( 0x5 << V_110 ) |
( 0x5 << V_111 ) |
( 0x1 << V_112 ) |
( 0x1 << V_113 ) |
( 0x1 << V_114 ) |
( 0x1 << V_115 ) ) ;
V_99 = 0 ;
if ( V_13 -> V_49 == V_50 ) {
V_99 |= ( ( V_116 <<
V_117 ) |
( V_116 <<
V_118 ) |
( V_116 <<
V_119 ) |
( V_116 <<
V_120 ) ) ;
}
F_58 ( V_4 ) ;
F_18 ( V_56 , V_137 ) ;
F_18 ( V_96 , V_98 ) ;
F_18 ( V_97 , V_99 ) ;
for ( V_26 = 0 ; V_26 < 4 ; V_26 ++ ) {
T_3 V_121 , V_122 ;
int V_10 ;
V_10 = F_49 ( V_4 , V_26 , & V_121 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_52 ( V_4 , V_26 , & V_122 ) ;
if ( V_10 )
return V_10 ;
V_121 &= ~ ( V_123 ) ;
V_121 |= ( V_124 |
( 2 << V_125 ) ) ;
V_122 &= ~ ( V_126 |
V_127 |
V_128 ) ;
V_122 |= ( V_129 |
( 0xf << V_130 ) |
( 0xff << V_131 ) |
( V_132 <<
V_133 ) ) ;
V_10 = F_56 ( V_4 , V_26 , V_121 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_57 ( V_4 , V_26 , V_122 ) ;
if ( V_10 )
return V_10 ;
}
V_60 = F_16 ( V_73 ) ;
switch ( V_4 -> V_30 ) {
case 0 :
V_61 = V_75 ;
V_2 = ( V_69 |
V_70 |
V_76 |
V_77 |
V_78 |
V_79 |
V_80 ) ;
break;
case 1 :
V_61 = V_81 ;
V_2 = ( V_71 |
V_72 |
V_82 |
V_83 |
V_84 |
V_85 |
V_86 ) ;
break;
default:
return - V_21 ;
}
if ( ( V_60 & V_61 ) != V_2 ) {
int V_10 ;
V_10 = F_61 ( V_4 ) ;
if ( ! V_10 ) {
V_4 -> V_87 &= ~ V_88 ;
V_4 -> V_89 = V_90 ;
} else {
F_10 ( V_4 -> V_11 , L_6 ,
V_4 -> V_30 ) ;
return - V_8 ;
}
}
return 0 ;
}
static int F_111 ( struct V_3 * V_4 )
{
struct V_24 * V_25 = V_4 -> V_25 ;
T_5 V_339 = V_25 -> V_339 ;
const struct V_340 * V_341 ;
T_3 V_342 = 0 ;
if ( V_339 == V_343 ) {
switch ( V_4 -> V_87 &
( V_88 |
V_344 |
V_345 ) ) {
case V_88 | V_345 :
V_341 = & V_346 ;
break;
case V_345 :
V_341 = & V_347 ;
break;
case V_88 | V_344 :
default:
if ( V_4 -> V_87 & V_134 ) {
V_341 = & V_348 ;
if ( V_4 -> V_30 == 0 )
V_342 = 8 ;
if ( V_4 -> V_30 == 1 )
V_342 = 12 ;
} else {
V_341 = & V_349 ;
V_342 += V_4 -> V_30 ;
}
break;
}
} else {
switch ( V_4 -> V_87 &
( V_88 |
V_344 |
V_345 ) ) {
case 0 :
V_341 = & V_350 ;
if ( V_339 == V_351 )
V_342 = 10 ;
else if ( V_339 == V_352 )
V_342 = 26 ;
V_342 += ( V_4 -> V_30 ^ 0x3 ) ;
break;
case V_88 :
V_341 = & V_353 ;
break;
case V_344 :
V_341 = & V_354 ;
break;
case V_88 | V_344 :
V_341 = & V_355 ;
if ( V_339 == V_351 ||
V_339 == V_352 )
V_342 = 8 ;
V_342 += V_4 -> V_30 ;
if ( V_4 -> V_87 & V_134 ) {
V_341 = & V_356 ;
if ( V_4 -> V_30 == 0 )
V_342 = 8 ;
if ( V_4 -> V_30 == 1 )
V_342 = 12 ;
}
break;
case V_88 | V_345 :
case V_345 | V_344 :
case V_345 :
switch( V_4 -> V_30 ) {
case 0 :
case 1 :
V_341 = & V_357 ;
break;
case 2 :
case 3 :
V_341 = & V_358 ;
break;
default:
return - V_21 ;
break;
}
V_342 = V_359 [ V_4 -> V_30 ] ;
break;
default:
return - V_21 ;
}
}
V_4 -> V_305 = V_341 -> V_304 ;
V_4 -> V_175 = V_341 -> V_360 + V_342 ;
return 0 ;
}
static int F_112 ( struct V_3 * V_4 )
{
struct V_24 * V_25 = V_4 -> V_25 ;
int V_10 , V_361 ;
if ( V_25 -> V_339 == V_343 ) {
V_10 = F_91 ( V_4 ) ;
if ( V_10 )
return V_10 ;
F_113 ( 200 ) ;
}
V_10 = F_92 ( V_4 ) ;
if ( V_10 && ! ( V_4 -> V_87 & V_134 ) )
return V_10 ;
F_113 ( 200 ) ;
V_10 = F_91 ( V_4 ) ;
if ( ! V_10 || ( V_4 -> V_87 & V_134 ) )
F_107 ( V_4 , & V_361 ) ;
return 0 ;
}
static void F_114 ( struct V_3 * V_4 , unsigned char * V_362 )
{
T_4 V_363 = V_362 [ 4 ] << 8 | V_362 [ 5 ] ;
T_4 V_364 = V_362 [ 2 ] << 8 | V_362 [ 3 ] ;
T_4 V_365 = V_362 [ 0 ] << 8 | V_362 [ 1 ] ;
if ( V_4 -> V_87 & V_366 ) {
F_9 ( V_367 , V_363 ) ;
F_9 ( V_368 , V_364 ) ;
F_9 ( V_369 , V_365 ) ;
} else {
F_9 ( V_370 , V_363 ) ;
F_9 ( V_371 , V_364 ) ;
F_9 ( V_372 , V_365 ) ;
}
}
static int F_115 ( struct V_3 * V_4 )
{
if ( V_4 -> V_87 & V_366 )
return V_373 ;
else
return V_374 ;
}
static int F_116 ( struct V_3 * V_4 , int V_375 , unsigned char * V_362 )
{
T_4 V_363 = V_362 [ 4 ] << 8 | V_362 [ 5 ] ;
T_4 V_364 = V_362 [ 2 ] << 8 | V_362 [ 3 ] ;
T_4 V_365 = V_362 [ 0 ] << 8 | V_362 [ 1 ] ;
if ( V_375 >= F_115 ( V_4 ) )
return - V_21 ;
if ( V_4 -> V_87 & V_366 ) {
F_9 ( F_117 ( V_375 ) , V_363 ) ;
F_9 ( F_118 ( V_375 ) , V_364 ) ;
F_9 ( F_119 ( V_375 ) , V_365 ) ;
} else {
F_9 ( F_120 ( V_375 ) , V_363 ) ;
F_9 ( F_121 ( V_375 ) , V_364 ) ;
F_9 ( F_122 ( V_375 ) , V_365 ) ;
}
return 0 ;
}
static int F_123 ( struct V_3 * V_4 , int V_375 , int V_14 )
{
unsigned long V_1 ;
T_1 V_2 , V_61 ;
if ( V_375 >= F_115 ( V_4 ) )
return - V_21 ;
if ( V_4 -> V_87 & V_366 ) {
V_1 = V_376 ;
V_61 = 1 << V_375 ;
} else {
V_1 = V_377 ;
V_61 = 1 << ( V_375 + 1 ) ;
}
V_2 = F_6 ( V_1 ) ;
if ( V_14 )
V_2 |= V_61 ;
else
V_2 &= ~ V_61 ;
F_9 ( V_1 , V_2 ) ;
return 0 ;
}
static void F_124 ( struct V_3 * V_4 , unsigned long V_1 ,
int V_378 , int V_379 )
{
T_1 V_2 = F_6 ( V_1 ) ;
V_2 &= ~ ( V_380 | V_381 ) ;
V_2 |= V_378 ;
if ( V_379 )
V_2 |= V_381 ;
F_9 ( V_1 , V_2 ) ;
}
static int F_125 ( struct V_3 * V_4 ,
int V_382 , int V_383 ,
int V_384 , int V_379 )
{
unsigned long V_1 ;
if ( V_384 & ~ V_380 )
return - V_21 ;
if ( V_4 -> V_87 & V_366 )
V_1 = F_126 ( V_382 ) ;
else
V_1 = F_127 ( V_383 ) ;
F_124 ( V_4 , V_1 , V_384 , V_379 ) ;
return 0 ;
}
static int F_128 ( struct V_3 * V_4 , int V_385 ,
int V_379 )
{
return F_125 ( V_4 , 17 , 0 , V_385 , V_379 ) ;
}
static int F_129 ( struct V_3 * V_4 , int V_385 ,
int V_379 )
{
return F_125 ( V_4 , 16 , 8 , V_385 , V_379 ) ;
}
static int F_130 ( struct V_3 * V_4 , int V_386 ,
int V_385 , int V_379 )
{
if ( V_386 >= F_115 ( V_4 ) )
return - V_21 ;
return F_125 ( V_4 , V_386 , V_386 + 1 , V_385 , V_379 ) ;
}
static T_1 F_131 ( T_1 V_387 )
{
T_1 V_388 ;
T_1 V_389 ;
V_388 = 0x00ff ;
V_389 = 0xff00 ;
if ( F_132 ( V_387 & V_388 ) & 1 )
V_387 |= V_390 ;
else
V_387 &= ~ V_390 ;
if ( F_132 ( V_387 & V_389 ) & 1 )
V_387 |= V_391 ;
else
V_387 &= ~ V_391 ;
return V_387 ;
}
static void F_133 ( struct V_3 * V_4 , unsigned long V_375 ,
int V_30 , int V_392 , int V_393 )
{
T_1 V_387 = F_16 ( F_134 ( V_375 ) ) ;
V_387 &= ~ ( ( V_394 |
V_395 ) <<
F_135 ( V_30 ) ) ;
if ( V_392 )
V_387 |= ( V_394 <<
F_135 ( V_30 ) ) ;
V_387 |= ( V_393 << F_135 ( V_30 ) ) ;
V_387 = F_131 ( V_387 ) ;
F_18 ( F_134 ( V_375 ) , V_387 ) ;
}
static void F_136 ( struct V_3 * V_4 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_396 ; V_26 ++ )
F_18 ( F_134 ( V_26 ) , 0 ) ;
}
static int F_137 ( struct V_3 * V_4 , T_1 V_397 )
{
int V_6 = 1000 ;
while ( -- V_6 > 0 ) {
if ( F_16 ( V_398 ) & V_397 )
break;
F_7 ( 1 ) ;
}
if ( V_6 <= 0 )
return - V_8 ;
return 0 ;
}
static int F_138 ( struct V_3 * V_4 , int V_375 )
{
F_18 ( V_399 , 0x00 ) ;
F_18 ( V_400 , 0xff ) ;
F_18 ( V_398 , ( V_401 | V_375 ) ) ;
return F_137 ( V_4 , V_402 ) ;
}
static int F_139 ( struct V_3 * V_4 , int V_375 ,
T_1 * V_403 , T_1 * V_61 )
{
F_18 ( V_399 , V_403 [ 0 ] ) ;
F_18 ( V_404 , V_403 [ 1 ] ) ;
F_18 ( V_405 , V_403 [ 2 ] ) ;
F_18 ( V_406 , V_403 [ 3 ] ) ;
F_18 ( V_400 , V_61 [ 0 ] ) ;
F_18 ( V_407 , V_61 [ 1 ] ) ;
F_18 ( V_408 , V_61 [ 2 ] ) ;
F_18 ( V_409 , V_61 [ 3 ] ) ;
F_18 ( V_398 , ( V_401 | V_375 ) ) ;
return F_137 ( V_4 , V_402 ) ;
}
static int F_140 ( struct V_3 * V_4 , int V_375 , T_1 V_410 )
{
F_18 ( V_404 , V_410 ) ;
F_18 ( V_398 , ( V_411 | V_375 ) ) ;
return F_137 ( V_4 , V_402 ) ;
}
static void F_141 ( struct V_3 * V_4 , int V_14 )
{
T_1 V_2 = F_16 ( V_412 ) ;
if ( V_14 )
V_2 &= ~ V_413 ;
else
V_2 |= V_413 ;
F_18 ( V_412 , V_2 ) ;
}
static void F_142 ( struct V_3 * V_4 , T_1 V_414 , T_1 V_415 )
{
T_1 V_2 = F_16 ( V_412 ) ;
V_2 &= ~ ( V_416 |
V_417 |
V_418 ) ;
V_2 |= ( V_414 << V_419 ) ;
V_2 |= ( V_415 << V_420 ) ;
F_18 ( V_412 , V_2 ) ;
V_2 = F_16 ( V_412 ) ;
V_2 |= V_416 ;
F_18 ( V_412 , V_2 ) ;
}
static int F_143 ( struct V_3 * V_4 , unsigned long V_421 ,
int V_14 )
{
unsigned long V_1 ;
T_1 V_2 ;
if ( V_421 < V_422 ||
V_421 > V_423 )
return - V_21 ;
V_1 = F_144 ( V_421 - V_422 ) ;
V_2 = F_16 ( V_1 ) ;
if ( V_14 )
V_2 |= V_424 ;
else
V_2 &= ~ V_424 ;
F_18 ( V_1 , V_2 ) ;
return 0 ;
}
static int F_145 ( struct V_3 * V_4 , unsigned long V_421 ,
int V_14 )
{
unsigned long V_1 ;
T_1 V_2 ;
if ( V_421 < V_425 ||
V_421 > V_426 )
return - V_21 ;
V_1 = F_146 ( V_421 - V_425 ) ;
V_2 = F_16 ( V_1 ) ;
if ( V_14 )
V_2 |= V_427 ;
else
V_2 &= ~ V_427 ;
F_18 ( V_1 , V_2 ) ;
return 0 ;
}
static int F_147 ( struct V_3 * V_4 , unsigned long V_421 ,
int V_428 , T_1 V_429 ,
T_1 V_430 , T_1 V_431 )
{
unsigned long V_1 ;
T_1 V_2 ;
if ( V_421 < V_425 ||
V_421 > V_426 ||
( V_429 & ~ ( T_1 ) 0xff ) != 0 ||
( V_430 & ~ ( T_1 ) 0xff ) != 0 ||
( V_431 & ~ ( T_1 ) 0xff ) != 0 )
return - V_21 ;
V_1 = F_146 ( V_421 - V_425 ) ;
V_2 = F_16 ( V_1 ) ;
V_2 &= ~ ( V_432 | V_433 |
V_434 | V_435 ) ;
if ( V_428 )
V_2 |= V_432 ;
V_2 |= ( V_429 << V_436 ) ;
V_2 |= ( V_430 << V_437 ) ;
V_2 |= ( V_431 << V_438 ) ;
F_18 ( V_1 , V_2 ) ;
return 0 ;
}
static int F_148 ( struct V_3 * V_4 )
{
unsigned long V_26 ;
int V_10 ;
F_141 ( V_4 , 0 ) ;
F_142 ( V_4 ,
V_439 ,
V_440 ) ;
for ( V_26 = V_422 ; V_26 <= V_423 ; V_26 ++ ) {
V_10 = F_143 ( V_4 , V_26 , 0 ) ;
if ( V_10 )
return V_10 ;
}
for ( V_26 = V_425 ; V_26 <= V_426 ; V_26 ++ ) {
V_10 = F_145 ( V_4 , V_26 , 0 ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
static int F_149 ( struct V_3 * V_4 )
{
unsigned long V_26 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_25 -> V_441 ; V_26 ++ ) {
int V_10 = F_138 ( V_4 , V_26 ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
static T_1 F_150 ( unsigned long V_375 , unsigned long V_442 )
{
return ( T_1 ) V_375 | ( V_442 == 1 ? V_443 : 0 ) ;
}
static int F_151 ( struct V_3 * V_4 , unsigned long V_444 ,
unsigned long V_375 , unsigned long V_442 ,
T_1 * V_35 )
{
T_1 V_2 = F_150 ( V_375 , V_442 ) ;
unsigned long V_26 ;
if ( V_444 >= V_445 ||
V_375 + ( V_442 * 8 ) > V_446 )
return - V_21 ;
F_18 ( F_152 ( V_444 ) , V_2 ) ;
for ( V_26 = 0 ; V_26 < V_442 ; V_26 ++ )
F_18 ( F_153 ( V_444 ) , V_35 [ V_26 ] ) ;
return 0 ;
}
static void F_154 ( struct V_3 * V_4 )
{
T_1 V_2 ;
F_18 ( V_412 , V_447 ) ;
F_7 ( 10 ) ;
F_18 ( V_412 , 0 ) ;
V_2 = V_448 | V_416 ;
F_18 ( V_412 , V_2 ) ;
}
static void F_155 ( struct V_3 * V_4 )
{
T_1 V_2 = F_16 ( V_412 ) ;
V_2 &= ~ V_416 ;
V_2 |= ( V_449 << V_450 ) ;
F_18 ( V_412 , V_2 ) ;
V_2 = F_16 ( V_412 ) ;
V_2 |= V_416 ;
F_18 ( V_412 , V_2 ) ;
V_2 = F_16 ( V_451 ) ;
V_2 &= ~ ( V_452 | V_453 ) ;
V_2 |= ( V_454 << V_455 ) ;
V_2 |= ( V_456 << V_457 ) ;
F_18 ( V_451 , V_2 ) ;
}
static int F_156 ( struct V_3 * V_4 , T_1 V_444 ,
T_1 V_61 , T_1 V_458 , int V_459 )
{
unsigned long V_1 ;
T_1 V_2 ;
if ( V_444 >= V_445 ||
( V_61 & ~ ( T_1 ) 0x1f ) != 0 ||
( V_458 & ~ ( T_1 ) 0x1f ) != 0 )
return - V_21 ;
V_1 = F_157 ( V_444 ) ;
V_2 = F_16 ( V_1 ) ;
V_2 &= ~ ( V_460 | V_461 | V_462 ) ;
V_2 |= ( V_61 << V_463 ) ;
V_2 |= ( V_458 << V_464 ) ;
if ( V_459 )
V_2 |= V_460 ;
F_18 ( V_1 , V_2 ) ;
return 0 ;
}
static int F_158 ( struct V_3 * V_4 )
{
unsigned long V_26 ;
for ( V_26 = 0 ; V_26 < V_445 ; V_26 ++ ) {
int V_10 = F_156 ( V_4 , 0 , 0 , 0 , 0 ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
static void F_159 ( struct V_3 * V_4 , int V_14 )
{
T_1 V_2 = F_16 ( V_412 ) ;
if ( V_14 )
V_2 |= V_465 ;
else
V_2 &= ~ V_465 ;
F_18 ( V_412 , V_2 ) ;
}
static void F_160 ( struct V_3 * V_4 , int V_14 )
{
T_1 V_2 = F_16 ( V_412 ) ;
if ( V_14 )
V_2 &= ~ V_466 ;
else
V_2 |= V_466 ;
F_18 ( V_412 , V_2 ) ;
}
static int F_161 ( struct V_3 * V_4 )
{
struct V_467 V_468 ;
unsigned long V_26 ;
memset ( & V_468 , 0 , sizeof( V_468 ) ) ;
V_468 . V_469 = V_470 ;
for ( V_26 = 0 ; V_26 < V_446 ; V_26 += sizeof( V_468 ) ) {
int V_10 = F_151 ( V_4 , 0 , V_26 , 1 , ( T_1 * ) & V_468 ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
static int F_162 ( struct V_3 * V_4 )
{
struct V_24 * V_25 ;
unsigned long V_87 ;
int V_10 ;
F_163 ( V_4 , V_87 ) ;
V_25 = V_4 -> V_25 ;
V_10 = 0 ;
if ( ! ( V_25 -> V_87 & V_471 ) ) {
if ( V_4 -> V_25 -> V_339 != V_343 ) {
F_154 ( V_4 ) ;
F_155 ( V_4 ) ;
V_10 = F_158 ( V_4 ) ;
if ( V_10 ) {
F_164 ( V_4 , V_472 , V_473 , V_4 -> V_11 ,
L_24 ,
V_10 ) ;
goto V_229;
}
}
V_10 = F_148 ( V_4 ) ;
if ( V_10 ) {
F_164 ( V_4 , V_472 , V_473 , V_4 -> V_11 ,
L_25 , V_10 ) ;
goto V_229;
}
F_159 ( V_4 , 1 ) ;
F_160 ( V_4 , 0 ) ;
F_18 ( V_474 , 0 ) ;
F_18 ( V_475 , 0 ) ;
V_10 = F_149 ( V_4 ) ;
if ( V_10 ) {
F_164 ( V_4 , V_472 , V_473 , V_4 -> V_11 ,
L_26 , V_10 ) ;
goto V_229;
}
if ( V_4 -> V_25 -> V_339 != V_343 ) {
V_10 = F_161 ( V_4 ) ;
if ( V_10 ) {
F_164 ( V_4 , V_472 , V_473 , V_4 -> V_11 ,
L_27 ,
V_10 ) ;
goto V_229;
}
}
F_136 ( V_4 ) ;
V_25 -> V_87 |= V_471 ;
}
V_229:
F_165 ( V_4 , V_87 ) ;
return V_10 ;
}
static int F_166 ( struct V_3 * V_4 , unsigned long V_476 , T_1 V_403 )
{
if ( V_476 < V_425 ||
V_476 > V_477 )
return - V_21 ;
F_18 ( F_167 ( V_476 - V_425 ) , V_403 ) ;
return 0 ;
}
static int F_168 ( struct V_3 * V_4 , unsigned long V_476 , T_1 V_403 )
{
if ( V_476 < V_425 ||
V_476 > V_477 )
return - V_21 ;
F_18 ( F_169 ( V_476 - V_425 ) , V_403 ) ;
return 0 ;
}
static T_4 F_170 ( struct V_3 * V_4 , T_4 V_386 )
{
if ( V_386 >= ( V_4 -> V_478 . V_479 - 1 ) )
V_386 = 0 ;
return V_4 -> V_478 . V_480 + ( ( V_386 + 1 ) * V_4 -> V_25 -> V_481 ) ;
}
static T_4 F_171 ( struct V_3 * V_4 )
{
return V_4 -> V_478 . V_479 - 1 ;
}
static T_4 F_172 ( struct V_3 * V_4 )
{
return V_4 -> V_478 . V_482 - 1 ;
}
static void F_173 ( struct V_483 * V_484 , struct V_485 * V_485 ,
T_3 V_486 , T_3 V_487 )
{
int V_26 = F_174 ( V_484 ) -> V_488 ;
T_6 * V_489 = & F_174 ( V_484 ) -> V_490 [ V_26 ] ;
V_489 -> V_485 = V_485 ;
V_489 -> V_491 = V_486 ;
V_489 -> V_487 = V_487 ;
V_484 -> V_492 += V_487 ;
V_484 -> V_493 += V_487 ;
V_484 -> V_494 += V_487 ;
F_174 ( V_484 ) -> V_488 = V_26 + 1 ;
}
static unsigned int F_175 ( struct V_495 * V_496 , T_1 V_497 )
{
V_497 >>= V_498 ;
V_497 ^= ( V_497 >> F_176 ( V_499 ) ) ;
return V_497 & ( V_499 - 1 ) ;
}
static struct V_485 * F_177 ( struct V_495 * V_496 , T_1 V_362 ,
struct V_485 * * * V_309 )
{
unsigned int V_500 = F_175 ( V_496 , V_362 ) ;
struct V_485 * V_501 , * * V_502 ;
V_362 &= V_503 ;
V_502 = & V_496 -> V_504 [ V_500 ] ;
for (; ( V_501 = * V_502 ) != NULL ; V_502 = (struct V_485 * * ) & V_501 -> V_505 ) {
if ( V_501 -> V_375 == V_362 ) {
* V_309 = V_502 ;
goto V_506;
}
}
F_178 () ;
V_506:
return V_501 ;
}
static void F_179 ( struct V_495 * V_496 , struct V_485 * V_485 , T_1 V_458 )
{
unsigned int V_500 = F_175 ( V_496 , V_458 ) ;
V_485 -> V_375 = V_458 ;
V_485 -> V_505 = (struct V_507 * ) V_496 -> V_504 [ V_500 ] ;
V_496 -> V_504 [ V_500 ] = V_485 ;
}
static int F_180 ( struct V_3 * V_4 , struct V_495 * V_496 ,
T_7 V_61 , int V_508 )
{
struct V_485 * V_485 ;
T_1 V_362 ;
int V_26 ;
V_485 = F_181 ( V_61 ) ;
if ( ! V_485 )
return - V_509 ;
V_362 = V_4 -> V_304 -> V_510 ( V_4 -> V_511 , V_485 , 0 ,
V_512 , V_513 ) ;
F_179 ( V_496 , V_485 , V_362 ) ;
if ( V_496 -> V_514 > 1 )
F_182 ( V_496 -> V_514 - 1 ,
& F_183 ( V_485 ) -> V_515 ) ;
for ( V_26 = 0 ; V_26 < V_496 -> V_514 ; V_26 ++ ) {
T_8 * V_516 = & V_496 -> V_516 [ V_508 + V_26 ] ;
* V_516 = F_184 ( V_362 >> V_517 ) ;
V_362 += V_496 -> V_518 ;
}
return 0 ;
}
static void F_185 ( struct V_3 * V_4 , struct V_495 * V_496 , T_7 V_61 )
{
int V_375 = V_496 -> V_519 ;
V_496 -> V_520 ++ ;
if ( ( V_496 -> V_520 % V_496 -> V_514 ) == 0 ) {
int V_10 = F_180 ( V_4 , V_496 , V_61 , V_375 ) ;
if ( F_70 ( V_10 ) ) {
V_496 -> V_520 -- ;
return;
}
V_496 -> V_519 += V_496 -> V_514 ;
F_186 ( V_496 -> V_519 > V_496 -> V_521 ) ;
if ( V_496 -> V_519 == V_496 -> V_521 )
V_496 -> V_519 = 0 ;
if ( V_496 -> V_520 >= V_496 -> V_522 ) {
F_18 ( F_187 ( V_496 -> V_523 ) , V_496 -> V_520 ) ;
V_496 -> V_520 = 0 ;
}
}
}
static int F_188 ( struct V_3 * V_4 , struct V_495 * V_496 )
{
unsigned int V_375 = V_496 -> V_524 ;
int V_525 = 0 ;
V_496 -> V_526 ++ ;
while ( 1 ) {
struct V_485 * V_485 , * * V_309 ;
T_1 V_362 , V_2 ;
T_3 V_527 ;
V_525 ++ ;
V_2 = F_189 ( & V_496 -> V_528 [ V_375 ] ) ;
V_362 = ( V_2 & V_529 ) <<
V_530 ;
V_485 = F_177 ( V_496 , V_362 , & V_309 ) ;
V_527 = V_496 -> V_531 [ ( V_2 & V_532 ) >>
V_533 ] ;
if ( ( V_485 -> V_375 + V_512 ) - V_527 == V_362 ) {
* V_309 = (struct V_485 * ) V_485 -> V_505 ;
V_4 -> V_304 -> V_534 ( V_4 -> V_511 , V_485 -> V_375 ,
V_512 , V_513 ) ;
V_485 -> V_375 = 0 ;
V_485 -> V_505 = NULL ;
F_190 ( V_485 ) ;
V_496 -> V_535 ++ ;
}
V_375 = F_191 ( V_496 , V_375 ) ;
if ( ! ( V_2 & V_536 ) )
break;
}
V_496 -> V_524 = V_375 ;
return V_525 ;
}
static int F_192 ( struct V_537 * V_538 , struct V_3 * V_4 ,
struct V_495 * V_496 )
{
unsigned int V_375 = V_496 -> V_524 ;
struct V_539 * V_540 ;
struct V_483 * V_484 ;
int V_492 , V_525 ;
V_484 = F_193 ( V_4 -> V_11 , V_541 ) ;
if ( F_70 ( ! V_484 ) )
return F_188 ( V_4 , V_496 ) ;
V_525 = 0 ;
while ( 1 ) {
struct V_485 * V_485 , * * V_309 ;
T_3 V_527 , V_542 ;
T_1 V_362 , V_2 , V_335 ;
V_525 ++ ;
V_2 = F_189 ( & V_496 -> V_528 [ V_375 ] ) ;
V_492 = ( V_2 & V_543 ) >>
V_544 ;
V_492 -= V_545 ;
V_362 = ( V_2 & V_529 ) <<
V_530 ;
V_485 = F_177 ( V_496 , V_362 , & V_309 ) ;
V_527 = V_496 -> V_531 [ ( V_2 & V_532 ) >>
V_533 ] ;
V_335 = V_362 & ~ V_503 ;
V_542 = V_527 ;
if ( V_525 == 1 ) {
int V_546 ;
V_546 = ( V_2 >> V_547 ) ;
if ( ( V_546 == V_548 ||
V_546 == V_549 ) &&
! ( V_2 & ( V_550 |
V_551 ) ) )
V_484 -> V_552 = V_553 ;
else
F_194 ( V_484 ) ;
} else if ( ! ( V_2 & V_536 ) )
V_542 = V_492 - V_484 -> V_492 ;
F_173 ( V_484 , V_485 , V_335 , V_542 ) ;
if ( ( V_485 -> V_375 + V_496 -> V_518 ) - V_527 == V_362 ) {
* V_309 = (struct V_485 * ) V_485 -> V_505 ;
V_4 -> V_304 -> V_534 ( V_4 -> V_511 , V_485 -> V_375 ,
V_512 , V_513 ) ;
V_485 -> V_375 = 0 ;
V_485 -> V_505 = NULL ;
V_496 -> V_535 ++ ;
} else
F_195 ( V_485 ) ;
V_375 = F_191 ( V_496 , V_375 ) ;
if ( ! ( V_2 & V_536 ) )
break;
}
V_496 -> V_524 = V_375 ;
V_492 += sizeof( * V_540 ) ;
V_492 = F_196 ( int , V_492 , sizeof( * V_540 ) + V_554 ) ;
F_197 ( V_484 , V_492 ) ;
V_540 = (struct V_539 * ) V_484 -> V_35 ;
if ( V_4 -> V_11 -> V_555 & V_556 )
V_484 -> V_504 = ( ( T_3 ) V_540 -> V_557 << 24 |
( T_3 ) V_540 -> V_558 << 16 |
( T_3 ) V_540 -> V_559 << 8 |
( T_3 ) V_540 -> V_560 << 0 ) ;
F_198 ( V_484 , sizeof( * V_540 ) ) ;
V_496 -> V_561 ++ ;
V_496 -> V_562 += V_484 -> V_492 ;
V_484 -> V_563 = F_199 ( V_484 , V_4 -> V_11 ) ;
F_200 ( V_484 , V_496 -> V_523 ) ;
F_201 ( V_538 , V_484 ) ;
return V_525 ;
}
static int F_202 ( struct V_3 * V_4 , struct V_495 * V_496 , T_7 V_61 )
{
int V_564 = V_496 -> V_514 ;
int V_10 , V_375 = V_496 -> V_519 ;
V_10 = 0 ;
while ( V_375 < ( V_496 -> V_521 - V_564 ) ) {
V_10 = F_180 ( V_4 , V_496 , V_61 , V_375 ) ;
if ( V_10 )
break;
V_375 += V_564 ;
}
V_496 -> V_519 = V_375 ;
return V_10 ;
}
static void F_203 ( struct V_3 * V_4 , struct V_495 * V_496 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_499 ; V_26 ++ ) {
struct V_485 * V_485 ;
V_485 = V_496 -> V_504 [ V_26 ] ;
while ( V_485 ) {
struct V_485 * V_565 = (struct V_485 * ) V_485 -> V_505 ;
T_1 V_458 = V_485 -> V_375 ;
V_4 -> V_304 -> V_534 ( V_4 -> V_511 , V_458 , V_512 ,
V_513 ) ;
V_485 -> V_375 = 0 ;
V_485 -> V_505 = NULL ;
F_190 ( V_485 ) ;
V_485 = V_565 ;
}
}
for ( V_26 = 0 ; V_26 < V_496 -> V_521 ; V_26 ++ )
V_496 -> V_516 [ V_26 ] = F_184 ( 0 ) ;
V_496 -> V_519 = 0 ;
}
static int F_204 ( struct V_3 * V_4 , struct V_566 * V_496 , int V_386 )
{
struct V_567 * V_568 = & V_496 -> V_569 [ V_386 ] ;
struct V_483 * V_484 = V_568 -> V_484 ;
struct V_570 * V_341 ;
T_1 V_571 ;
int V_26 , V_492 ;
V_341 = (struct V_570 * ) V_484 -> V_35 ;
V_571 = F_189 ( & V_341 -> V_87 ) ;
V_496 -> V_572 ++ ;
V_496 -> V_573 += ( ( ( V_571 & V_574 ) >> V_575 ) -
( ( V_571 & V_576 ) / 2 ) ) ;
V_492 = F_205 ( V_484 ) ;
V_4 -> V_304 -> V_577 ( V_4 -> V_511 , V_568 -> V_505 ,
V_492 , V_578 ) ;
if ( F_206 ( V_496 -> V_579 [ V_386 ] ) & V_580 )
V_496 -> V_581 -- ;
V_568 -> V_484 = NULL ;
do {
V_386 = F_207 ( V_496 , V_386 ) ;
V_492 -= V_582 ;
} while ( V_492 > 0 );
for ( V_26 = 0 ; V_26 < F_174 ( V_484 ) -> V_488 ; V_26 ++ ) {
V_568 = & V_496 -> V_569 [ V_386 ] ;
F_186 ( V_568 -> V_484 != NULL ) ;
V_4 -> V_304 -> V_534 ( V_4 -> V_511 , V_568 -> V_505 ,
F_174 ( V_484 ) -> V_490 [ V_26 ] . V_487 ,
V_578 ) ;
V_386 = F_207 ( V_496 , V_386 ) ;
}
F_208 ( V_484 ) ;
return V_386 ;
}
static void F_209 ( struct V_3 * V_4 , struct V_566 * V_496 )
{
struct V_583 * V_584 ;
T_4 V_585 , V_586 ;
int V_587 , V_375 ;
T_1 V_588 ;
V_375 = ( V_496 - V_4 -> V_589 ) ;
V_584 = F_210 ( V_4 -> V_11 , V_375 ) ;
V_588 = V_496 -> V_590 ;
if ( F_70 ( ! ( V_588 & ( V_591 | V_592 ) ) ) )
goto V_229;
V_586 = V_585 = ( V_588 & V_593 ) >> V_594 ;
V_585 = ( V_585 - V_496 -> V_595 ) &
( V_593 >> V_594 ) ;
V_496 -> V_595 = V_586 ;
V_587 = V_496 -> V_587 ;
F_164 ( V_4 , V_596 , V_473 , V_4 -> V_11 ,
L_28 , V_67 , V_585 , V_587 ) ;
while ( V_585 -- )
V_587 = F_204 ( V_4 , V_496 , V_587 ) ;
V_496 -> V_587 = V_587 ;
F_211 () ;
V_229:
if ( F_70 ( F_212 ( V_584 ) &&
( F_213 ( V_496 ) > F_214 ( V_496 ) ) ) ) {
F_215 ( V_584 , F_216 () ) ;
if ( F_212 ( V_584 ) &&
( F_213 ( V_496 ) > F_214 ( V_496 ) ) )
F_217 ( V_584 ) ;
F_218 ( V_584 ) ;
}
}
static inline void F_219 ( struct V_3 * V_4 ,
struct V_495 * V_496 ,
const int V_6 )
{
int V_523 = V_496 -> V_523 ;
T_3 V_597 , V_598 ;
V_597 = F_16 ( F_220 ( V_523 ) ) ;
if ( F_70 ( ( V_597 & V_599 ) > V_6 ) ) {
F_18 ( F_220 ( V_523 ) , 0 ) ;
V_496 -> V_600 += V_597 & V_599 ;
if ( F_70 ( V_597 & V_601 ) )
F_221 ( V_4 -> V_511 , L_29 ,
V_523 ) ;
F_164 ( V_4 , V_602 , V_473 , V_4 -> V_11 ,
L_30 ,
V_523 , V_597 , V_597 - V_6 ) ;
}
V_598 = F_16 ( F_222 ( V_523 ) ) ;
if ( F_70 ( ( V_598 & V_603 ) > V_6 ) ) {
F_18 ( F_222 ( V_523 ) , 0 ) ;
V_496 -> V_526 += V_598 & V_603 ;
if ( F_70 ( V_598 & V_604 ) )
F_221 ( V_4 -> V_511 , L_31 , V_523 ) ;
F_164 ( V_4 , V_602 , V_473 , V_4 -> V_11 ,
L_32 ,
V_523 , V_598 , V_598 - V_6 ) ;
}
}
static int F_223 ( struct V_537 * V_538 , struct V_3 * V_4 ,
struct V_495 * V_496 , int V_605 )
{
int V_606 , V_607 = 0 , V_608 = 0 ;
struct V_609 * V_610 = V_496 -> V_610 ;
T_1 V_611 ;
#if 1
V_611 = F_16 ( F_224 ( V_496 -> V_523 ) ) ;
V_606 = F_16 ( F_225 ( V_496 -> V_523 ) ) & V_612 ;
#else
V_611 = F_189 ( & V_610 -> V_613 ) ;
V_606 = ( F_189 ( & V_610 -> V_614 ) & V_612 ) ;
#endif
V_610 -> V_613 = 0 ;
V_610 -> V_614 = 0 ;
F_164 ( V_4 , V_615 , V_473 , V_4 -> V_11 ,
L_33 ,
V_67 , V_496 -> V_523 , ( unsigned long long ) V_611 , V_606 ) ;
V_607 = V_608 = 0 ;
V_606 = F_226 ( V_606 , V_605 ) ;
while ( V_608 < V_606 ) {
V_607 += F_192 ( V_538 , V_4 , V_496 ) ;
V_608 ++ ;
}
if ( V_496 -> V_535 >= V_496 -> V_522 ) {
unsigned int V_26 ;
for ( V_26 = 0 ; V_26 < V_496 -> V_535 ; V_26 ++ )
F_185 ( V_4 , V_496 , V_616 ) ;
V_496 -> V_535 = 0 ;
}
V_611 = ( V_617 |
( ( T_1 ) V_608 << V_618 ) |
( ( T_1 ) V_607 << V_619 ) ) ;
F_18 ( F_224 ( V_496 -> V_523 ) , V_611 ) ;
if ( V_606 > 10 )
F_219 ( V_4 , V_496 , 0x7FFF ) ;
return V_608 ;
}
static int F_227 ( struct V_3 * V_4 , struct V_12 * V_13 , int V_605 )
{
T_1 V_620 = V_13 -> V_620 ;
T_3 V_621 = ( V_620 >> 32 ) ;
T_3 V_622 = ( V_620 & 0xffffffff ) ;
int V_26 , V_608 = 0 ;
F_164 ( V_4 , V_623 , V_473 , V_4 -> V_11 ,
L_34 , V_67 , ( unsigned long long ) V_620 ) ;
for ( V_26 = 0 ; V_26 < V_4 -> V_624 ; V_26 ++ ) {
struct V_566 * V_496 = & V_4 -> V_589 [ V_26 ] ;
if ( V_621 & ( 1 << V_496 -> V_625 ) )
F_209 ( V_4 , V_496 ) ;
F_18 ( F_22 ( F_228 ( V_496 -> V_625 ) ) , 0 ) ;
}
for ( V_26 = 0 ; V_26 < V_4 -> V_626 ; V_26 ++ ) {
struct V_495 * V_496 = & V_4 -> V_627 [ V_26 ] ;
if ( V_622 & ( 1 << V_496 -> V_523 ) ) {
int V_628 ;
V_628 = F_223 ( & V_13 -> V_538 , V_4 , V_496 ,
V_605 ) ;
V_605 -= V_628 ;
V_608 += V_628 ;
}
F_18 ( F_22 ( F_229 ( V_496 -> V_523 ) ) , 0 ) ;
}
return V_608 ;
}
static int F_230 ( struct V_537 * V_538 , int V_605 )
{
struct V_12 * V_13 = F_231 ( V_538 , struct V_12 , V_538 ) ;
struct V_3 * V_4 = V_13 -> V_4 ;
int V_608 ;
V_608 = F_227 ( V_4 , V_13 , V_605 ) ;
if ( V_608 < V_605 ) {
F_232 ( V_538 ) ;
F_19 ( V_4 , V_13 , 1 ) ;
}
return V_608 ;
}
static void F_233 ( struct V_3 * V_4 , struct V_495 * V_496 ,
T_1 V_611 )
{
F_10 ( V_4 -> V_11 , L_35 , V_496 -> V_523 ) ;
if ( V_611 & V_629 )
F_234 ( L_36 ) ;
if ( V_611 & V_630 )
F_234 ( L_37 ) ;
if ( V_611 & V_631 )
F_234 ( L_38 ) ;
if ( V_611 & V_632 )
F_234 ( L_39 ) ;
if ( V_611 & V_633 )
F_234 ( L_40 ) ;
if ( V_611 & V_634 )
F_234 ( L_41 ) ;
if ( V_611 & V_635 )
F_234 ( L_42 ) ;
if ( V_611 & V_636 )
F_234 ( L_43 ) ;
if ( V_611 & V_637 )
F_234 ( L_44 ) ;
if ( V_611 & V_638 )
F_234 ( L_45 ) ;
if ( V_611 & V_639 )
F_234 ( L_46 ) ;
if ( V_611 & V_640 )
F_234 ( L_47 ) ;
if ( V_611 & V_641 )
F_234 ( L_48 ) ;
if ( V_611 & V_642 )
F_234 ( L_49 ) ;
F_234 ( L_50 ) ;
}
static int F_235 ( struct V_3 * V_4 , struct V_495 * V_496 )
{
T_1 V_611 = F_16 ( F_224 ( V_496 -> V_523 ) ) ;
int V_10 = 0 ;
if ( V_611 & ( V_643 |
V_644 ) )
V_10 = - V_21 ;
if ( V_10 ) {
F_10 ( V_4 -> V_11 , L_51 ,
V_496 -> V_523 ,
( unsigned long long ) V_611 ) ;
F_233 ( V_4 , V_496 , V_611 ) ;
}
F_18 ( F_224 ( V_496 -> V_523 ) ,
V_611 & V_645 ) ;
return V_10 ;
}
static void F_236 ( struct V_3 * V_4 , struct V_566 * V_496 ,
T_1 V_588 )
{
F_10 ( V_4 -> V_11 , L_52 , V_496 -> V_625 ) ;
if ( V_588 & V_646 )
F_234 ( L_53 ) ;
if ( V_588 & V_647 )
F_234 ( L_54 ) ;
if ( V_588 & V_648 )
F_234 ( L_55 ) ;
if ( V_588 & V_649 )
F_234 ( L_56 ) ;
if ( V_588 & V_650 )
F_234 ( L_57 ) ;
if ( V_588 & V_651 )
F_234 ( L_58 ) ;
if ( V_588 & V_652 )
F_234 ( L_59 ) ;
if ( V_588 & V_653 )
F_234 ( L_60 ) ;
F_234 ( L_50 ) ;
}
static int F_237 ( struct V_3 * V_4 , struct V_566 * V_496 )
{
T_1 V_588 , V_654 , V_655 ;
V_588 = F_16 ( F_238 ( V_496 -> V_625 ) ) ;
V_654 = F_16 ( F_239 ( V_496 -> V_625 ) ) ;
V_655 = F_16 ( F_240 ( V_496 -> V_625 ) ) ;
F_10 ( V_4 -> V_11 , L_61 ,
V_496 -> V_625 ,
( unsigned long long ) V_588 ,
( unsigned long long ) V_654 ,
( unsigned long long ) V_655 ) ;
F_236 ( V_4 , V_496 , V_588 ) ;
return - V_8 ;
}
static int F_241 ( struct V_3 * V_4 )
{
T_1 V_656 = F_16 ( V_657 ) ;
int V_658 = 0 ;
if ( V_4 -> V_87 & V_366 ) {
T_1 V_659 = F_6 ( V_660 ) ;
if ( V_659 & V_661 )
V_658 = 1 ;
}
F_10 ( V_4 -> V_11 , L_62 ,
( unsigned long long ) V_656 , V_658 ) ;
return - V_8 ;
}
static void F_242 ( struct V_3 * V_4 )
{
struct V_662 * V_663 = & V_4 -> V_664 . V_665 ;
T_1 V_2 ;
V_2 = F_6 ( V_666 ) ;
if ( V_2 & V_667 )
V_663 -> V_668 += V_669 ;
if ( V_2 & V_670 )
V_663 -> V_573 += V_671 ;
if ( V_2 & V_672 )
V_663 -> V_673 ++ ;
if ( V_2 & V_674 )
V_663 -> V_675 ++ ;
if ( V_2 & V_676 )
V_663 -> V_677 ++ ;
if ( V_2 & V_678 )
V_663 -> V_679 ++ ;
V_2 = F_6 ( V_660 ) ;
if ( V_2 & V_680 )
V_663 -> V_681 ++ ;
if ( V_2 & V_682 )
V_663 -> V_683 ++ ;
if ( V_2 & V_684 )
V_663 -> V_685 += V_686 ;
if ( V_2 & V_687 )
V_663 -> V_688 += V_689 ;
if ( V_2 & V_690 )
V_663 -> V_691 += V_692 ;
if ( V_2 & V_693 )
V_663 -> V_694 += V_695 ;
if ( V_2 & V_696 )
V_663 -> V_697 += V_698 ;
if ( V_2 & V_696 )
V_663 -> V_697 += V_698 ;
if ( V_2 & V_699 )
V_663 -> V_700 += V_701 ;
if ( V_2 & V_702 )
V_663 -> V_703 += V_704 ;
if ( V_2 & V_705 )
V_663 -> V_706 += V_707 ;
if ( V_2 & V_708 )
V_663 -> V_709 += V_710 ;
if ( V_2 & V_711 )
V_663 -> V_712 += V_713 ;
if ( V_2 & V_714 )
V_663 -> V_715 += V_716 ;
if ( V_2 & V_717 )
V_663 -> V_718 += V_719 ;
if ( V_2 & V_720 )
V_663 -> V_721 += V_722 ;
if ( V_2 & V_723 )
V_663 -> V_724 += V_725 ;
if ( V_2 & V_726 )
V_663 -> V_727 += V_728 ;
if ( V_2 & V_729 )
V_663 -> V_730 += V_731 ;
if ( V_2 & V_732 )
V_663 -> V_733 ++ ;
if ( V_2 & V_734 )
V_663 -> V_735 ++ ;
V_2 = F_6 ( V_736 ) ;
if ( V_2 & V_737 )
V_663 -> V_738 ++ ;
if ( V_2 & V_739 )
V_663 -> V_740 ++ ;
if ( V_2 & V_741 )
V_663 -> V_742 ++ ;
}
static void F_243 ( struct V_3 * V_4 )
{
struct V_743 * V_663 = & V_4 -> V_664 . V_744 ;
T_1 V_2 ;
V_2 = F_6 ( V_745 ) ;
if ( V_2 & V_746 )
V_663 -> V_679 ++ ;
if ( V_2 & V_747 )
V_663 -> V_677 ++ ;
if ( V_2 & V_748 )
V_663 -> V_573 += V_749 ;
if ( V_2 & V_750 )
V_663 -> V_668 += V_751 ;
V_2 = F_6 ( V_752 ) ;
if ( V_2 & V_753 )
V_663 -> V_735 ++ ;
if ( V_2 & V_754 )
V_663 -> V_755 += V_756 ;
if ( V_2 & V_757 )
V_663 -> V_688 += V_758 ;
if ( V_2 & V_759 )
V_663 -> V_730 += V_758 ;
if ( V_2 & V_760 )
V_663 -> V_727 += V_761 ;
V_2 = F_6 ( V_762 ) ;
if ( V_2 & V_763 )
V_663 -> V_738 ++ ;
if ( V_2 & V_764 )
V_663 -> V_740 ++ ;
if ( V_2 & V_765 )
V_663 -> V_742 ++ ;
}
static int F_244 ( struct V_3 * V_4 )
{
if ( V_4 -> V_87 & V_366 )
F_242 ( V_4 ) ;
else
F_243 ( V_4 ) ;
return 0 ;
}
static void F_245 ( struct V_3 * V_4 , T_1 V_611 )
{
F_10 ( V_4 -> V_11 , L_63 ) ;
if ( V_611 & V_766 )
F_234 ( L_64 ) ;
if ( V_611 & V_767 )
F_234 ( L_65 ) ;
if ( V_611 & V_768 )
F_234 ( L_66 ) ;
if ( V_611 & V_769 )
F_234 ( L_67 ) ;
if ( V_611 & V_770 )
F_234 ( L_68 ) ;
if ( V_611 & V_771 )
F_234 ( L_69 ) ;
if ( V_611 & V_772 )
F_234 ( L_70 ) ;
if ( V_611 & V_773 )
F_234 ( L_71 ) ;
if ( V_611 & V_774 )
F_234 ( L_72 ) ;
if ( V_611 & V_775 )
F_234 ( L_73 ) ;
if ( V_611 & V_776 )
F_234 ( L_74 ) ;
F_234 ( L_50 ) ;
}
static int F_246 ( struct V_3 * V_4 )
{
T_1 V_611 = F_16 ( V_777 ) ;
F_10 ( V_4 -> V_11 , L_75 ,
( unsigned long long ) V_611 ) ;
F_245 ( V_4 , V_611 ) ;
return - V_8 ;
}
static int F_247 ( struct V_3 * V_4 , struct V_12 * V_13 ,
T_1 V_620 , T_1 V_778 , T_1 V_779 )
{
int V_26 , V_10 = 0 ;
V_13 -> V_620 = V_620 ;
V_13 -> V_778 = V_778 ;
V_13 -> V_779 = V_779 ;
if ( V_778 & 0x00000000ffffffffULL ) {
T_3 V_622 = ( V_778 & 0xffffffff ) ;
for ( V_26 = 0 ; V_26 < V_4 -> V_626 ; V_26 ++ ) {
struct V_495 * V_496 = & V_4 -> V_627 [ V_26 ] ;
if ( V_622 & ( 1 << V_496 -> V_523 ) ) {
int V_780 = F_235 ( V_4 , V_496 ) ;
if ( V_780 ) {
V_10 = V_780 ;
} else {
if ( ! V_620 )
F_18 ( F_224 ( V_496 -> V_523 ) ,
V_617 ) ;
}
}
}
}
if ( V_778 & 0x7fffffff00000000ULL ) {
T_3 V_621 = ( V_778 >> 32 ) & 0x7fffffff ;
for ( V_26 = 0 ; V_26 < V_4 -> V_624 ; V_26 ++ ) {
struct V_566 * V_496 = & V_4 -> V_589 [ V_26 ] ;
if ( V_621 & ( 1 << V_496 -> V_625 ) ) {
int V_780 = F_237 ( V_4 , V_496 ) ;
if ( V_780 )
V_10 = V_780 ;
}
}
}
if ( ( V_620 | V_778 ) & 0x8000000000000000ULL ) {
int V_780 = F_241 ( V_4 ) ;
if ( V_780 )
V_10 = V_780 ;
}
if ( V_779 ) {
if ( V_779 & 0x01ef ) {
int V_780 = F_244 ( V_4 ) ;
if ( V_780 )
V_10 = V_780 ;
}
if ( V_779 & 0x0210 ) {
int V_780 = F_246 ( V_4 ) ;
if ( V_780 )
V_10 = V_780 ;
}
}
if ( V_10 )
F_25 ( V_4 , 0 ) ;
return V_10 ;
}
static void F_248 ( struct V_3 * V_4 , struct V_495 * V_496 ,
int V_18 )
{
struct V_609 * V_610 = V_496 -> V_610 ;
T_1 V_781 , V_611 = F_189 ( & V_610 -> V_613 ) ;
V_781 = ( V_782 |
V_783 ) ;
F_18 ( F_224 ( V_496 -> V_523 ) , V_781 ) ;
F_164 ( V_4 , V_623 , V_473 , V_4 -> V_11 ,
L_76 , V_67 , ( unsigned long long ) V_611 ) ;
}
static void F_249 ( struct V_3 * V_4 , struct V_566 * V_496 ,
int V_18 )
{
V_496 -> V_590 = F_16 ( F_238 ( V_496 -> V_625 ) ) ;
F_164 ( V_4 , V_623 , V_473 , V_4 -> V_11 ,
L_77 , V_67 , ( unsigned long long ) V_496 -> V_590 ) ;
}
static void F_250 ( struct V_3 * V_4 , int V_29 , T_1 V_620 )
{
struct V_24 * V_25 = V_4 -> V_25 ;
T_3 V_622 , V_621 ;
int V_26 ;
V_621 = ( V_620 >> 32 ) ;
V_622 = ( V_620 & 0xffffffff ) ;
for ( V_26 = 0 ; V_26 < V_4 -> V_626 ; V_26 ++ ) {
struct V_495 * V_496 = & V_4 -> V_627 [ V_26 ] ;
int V_18 = F_229 ( V_496 -> V_523 ) ;
if ( V_25 -> V_27 [ V_18 ] != V_29 )
continue;
F_18 ( F_22 ( V_18 ) , V_22 ) ;
if ( V_622 & ( 1 << V_496 -> V_523 ) )
F_248 ( V_4 , V_496 , V_18 ) ;
}
for ( V_26 = 0 ; V_26 < V_4 -> V_624 ; V_26 ++ ) {
struct V_566 * V_496 = & V_4 -> V_589 [ V_26 ] ;
int V_18 = F_228 ( V_496 -> V_625 ) ;
if ( V_25 -> V_27 [ V_18 ] != V_29 )
continue;
F_18 ( F_22 ( V_18 ) , V_22 ) ;
if ( V_621 & ( 1 << V_496 -> V_625 ) )
F_249 ( V_4 , V_496 , V_18 ) ;
}
}
static void F_251 ( struct V_3 * V_4 , struct V_12 * V_13 ,
T_1 V_620 , T_1 V_778 , T_1 V_779 )
{
if ( F_71 ( F_252 ( & V_13 -> V_538 ) ) ) {
V_13 -> V_620 = V_620 ;
V_13 -> V_778 = V_778 ;
V_13 -> V_779 = V_779 ;
F_250 ( V_4 , V_13 -> V_17 , V_620 ) ;
F_253 ( & V_13 -> V_538 ) ;
}
}
static T_9 F_254 ( int V_784 , void * V_785 )
{
struct V_12 * V_13 = V_785 ;
struct V_3 * V_4 = V_13 -> V_4 ;
int V_29 = V_13 -> V_17 ;
unsigned long V_87 ;
T_1 V_620 , V_778 , V_779 ;
if ( F_255 ( V_4 ) )
F_256 (KERN_DEBUG KBUILD_MODNAME L_78 L_79 ,
__func__, lp, ldg) ;
F_63 ( & V_4 -> V_155 , V_87 ) ;
V_620 = F_16 ( F_257 ( V_29 ) ) ;
V_778 = F_16 ( F_258 ( V_29 ) ) ;
V_779 = F_16 ( F_259 ( V_29 ) ) ;
if ( F_255 ( V_4 ) )
F_234 ( L_80 ,
( unsigned long long ) V_620 ,
( unsigned long long ) V_778 ,
( unsigned long long ) V_779 ) ;
if ( F_70 ( ! V_620 && ! V_778 && ! V_779 ) ) {
F_65 ( & V_4 -> V_155 , V_87 ) ;
return V_786 ;
}
if ( F_70 ( ( V_620 & ( ( T_1 ) 1 << V_787 ) ) || V_778 || V_779 ) ) {
int V_10 = F_247 ( V_4 , V_13 , V_620 , V_778 , V_779 ) ;
if ( V_10 )
goto V_229;
}
if ( F_71 ( V_620 & ~ ( ( T_1 ) 1 << V_787 ) ) )
F_251 ( V_4 , V_13 , V_620 , V_778 , V_779 ) ;
else
F_19 ( V_4 , V_13 , 1 ) ;
V_229:
F_65 ( & V_4 -> V_155 , V_87 ) ;
return V_788 ;
}
static void F_260 ( struct V_3 * V_4 , struct V_495 * V_496 )
{
if ( V_496 -> V_610 ) {
V_4 -> V_304 -> V_789 ( V_4 -> V_511 ,
sizeof( struct V_609 ) ,
V_496 -> V_610 , V_496 -> V_790 ) ;
V_496 -> V_610 = NULL ;
}
if ( V_496 -> V_528 ) {
V_4 -> V_304 -> V_789 ( V_4 -> V_511 ,
V_791 * sizeof( V_792 ) ,
V_496 -> V_528 , V_496 -> V_793 ) ;
V_496 -> V_528 = NULL ;
V_496 -> V_794 = 0 ;
V_496 -> V_524 = 0 ;
}
if ( V_496 -> V_516 ) {
F_203 ( V_4 , V_496 ) ;
V_4 -> V_304 -> V_789 ( V_4 -> V_511 ,
V_499 * sizeof( T_8 ) ,
V_496 -> V_516 , V_496 -> V_795 ) ;
V_496 -> V_516 = NULL ;
V_496 -> V_521 = 0 ;
V_496 -> V_519 = 0 ;
}
F_261 ( V_496 -> V_504 ) ;
V_496 -> V_504 = NULL ;
}
static void F_262 ( struct V_3 * V_4 , struct V_566 * V_496 )
{
if ( V_496 -> V_610 ) {
V_4 -> V_304 -> V_789 ( V_4 -> V_511 ,
sizeof( struct V_796 ) ,
V_496 -> V_610 , V_496 -> V_790 ) ;
V_496 -> V_610 = NULL ;
}
if ( V_496 -> V_579 ) {
int V_26 ;
for ( V_26 = 0 ; V_26 < V_797 ; V_26 ++ ) {
if ( V_496 -> V_569 [ V_26 ] . V_484 )
( void ) F_204 ( V_4 , V_496 , V_26 ) ;
}
V_4 -> V_304 -> V_789 ( V_4 -> V_511 ,
V_797 * sizeof( V_792 ) ,
V_496 -> V_579 , V_496 -> V_798 ) ;
V_496 -> V_579 = NULL ;
V_496 -> V_799 = 0 ;
V_496 -> V_800 = 0 ;
V_496 -> V_587 = 0 ;
V_496 -> V_801 = 0 ;
}
}
static void F_263 ( struct V_3 * V_4 )
{
int V_26 ;
if ( V_4 -> V_627 ) {
for ( V_26 = 0 ; V_26 < V_4 -> V_626 ; V_26 ++ ) {
struct V_495 * V_496 = & V_4 -> V_627 [ V_26 ] ;
F_260 ( V_4 , V_496 ) ;
}
F_261 ( V_4 -> V_627 ) ;
V_4 -> V_627 = NULL ;
V_4 -> V_626 = 0 ;
}
if ( V_4 -> V_589 ) {
for ( V_26 = 0 ; V_26 < V_4 -> V_624 ; V_26 ++ ) {
struct V_566 * V_496 = & V_4 -> V_589 [ V_26 ] ;
F_262 ( V_4 , V_496 ) ;
}
F_261 ( V_4 -> V_589 ) ;
V_4 -> V_589 = NULL ;
V_4 -> V_624 = 0 ;
}
}
static int F_264 ( struct V_3 * V_4 ,
struct V_495 * V_496 )
{
F_265 ( sizeof( struct V_609 ) != 64 ) ;
V_496 -> V_504 = F_266 ( V_499 * sizeof( struct V_485 * ) ,
V_802 ) ;
if ( ! V_496 -> V_504 )
return - V_509 ;
V_496 -> V_610 = V_4 -> V_304 -> V_803 ( V_4 -> V_511 ,
sizeof( struct V_609 ) ,
& V_496 -> V_790 , V_802 ) ;
if ( ! V_496 -> V_610 )
return - V_509 ;
if ( ( unsigned long ) V_496 -> V_610 & ( 64UL - 1 ) ) {
F_10 ( V_4 -> V_11 , L_81 ,
V_496 -> V_610 ) ;
return - V_21 ;
}
V_496 -> V_528 = V_4 -> V_304 -> V_803 ( V_4 -> V_511 ,
V_791 * sizeof( V_792 ) ,
& V_496 -> V_793 , V_802 ) ;
if ( ! V_496 -> V_528 )
return - V_509 ;
if ( ( unsigned long ) V_496 -> V_528 & ( 64UL - 1 ) ) {
F_10 ( V_4 -> V_11 , L_82 ,
V_496 -> V_528 ) ;
return - V_21 ;
}
V_496 -> V_794 = V_791 ;
V_496 -> V_524 = 0 ;
V_496 -> V_516 = V_4 -> V_304 -> V_803 ( V_4 -> V_511 ,
V_499 * sizeof( T_8 ) ,
& V_496 -> V_795 , V_802 ) ;
if ( ! V_496 -> V_516 )
return - V_509 ;
if ( ( unsigned long ) V_496 -> V_516 & ( 64UL - 1 ) ) {
F_10 ( V_4 -> V_11 , L_83 ,
V_496 -> V_516 ) ;
return - V_21 ;
}
V_496 -> V_521 = V_499 ;
V_496 -> V_519 = 0 ;
V_496 -> V_520 = 0 ;
return 0 ;
}
static void F_267 ( struct V_3 * V_4 , struct V_566 * V_496 )
{
int V_804 = V_4 -> V_11 -> V_804 ;
V_496 -> V_805 = V_804 + 32 ;
if ( V_496 -> V_805 > 4096 )
V_496 -> V_805 = 4096 ;
}
static int F_268 ( struct V_3 * V_4 ,
struct V_566 * V_496 )
{
F_265 ( sizeof( struct V_796 ) != 64 ) ;
V_496 -> V_610 = V_4 -> V_304 -> V_803 ( V_4 -> V_511 ,
sizeof( struct V_796 ) ,
& V_496 -> V_790 , V_802 ) ;
if ( ! V_496 -> V_610 )
return - V_509 ;
if ( ( unsigned long ) V_496 -> V_610 & ( 64UL - 1 ) ) {
F_10 ( V_4 -> V_11 , L_84 ,
V_496 -> V_610 ) ;
return - V_21 ;
}
V_496 -> V_579 = V_4 -> V_304 -> V_803 ( V_4 -> V_511 ,
V_797 * sizeof( V_792 ) ,
& V_496 -> V_798 , V_802 ) ;
if ( ! V_496 -> V_579 )
return - V_509 ;
if ( ( unsigned long ) V_496 -> V_579 & ( 64UL - 1 ) ) {
F_10 ( V_4 -> V_11 , L_85 ,
V_496 -> V_579 ) ;
return - V_21 ;
}
V_496 -> V_799 = V_797 ;
V_496 -> V_800 = 0 ;
V_496 -> V_587 = 0 ;
V_496 -> V_801 = 0 ;
V_496 -> V_806 = V_496 -> V_799 / 4 ;
F_267 ( V_4 , V_496 ) ;
return 0 ;
}
static void F_269 ( struct V_3 * V_4 , struct V_495 * V_496 )
{
T_4 V_807 ;
V_807 = F_226 ( V_498 , 15 ) ;
V_496 -> V_518 = 1 << V_807 ;
V_496 -> V_514 = 1 << ( V_498 - V_807 ) ;
V_496 -> V_531 [ 0 ] = 256 ;
V_496 -> V_531 [ 1 ] = 1024 ;
if ( V_4 -> V_11 -> V_804 > V_808 ) {
switch ( V_512 ) {
case 4 * 1024 :
V_496 -> V_531 [ 2 ] = 4096 ;
break;
default:
V_496 -> V_531 [ 2 ] = 8192 ;
break;
}
} else {
V_496 -> V_531 [ 2 ] = 2048 ;
}
V_496 -> V_531 [ 3 ] = V_496 -> V_518 ;
}
static int F_270 ( struct V_3 * V_4 )
{
struct V_24 * V_25 = V_4 -> V_25 ;
int V_809 , V_810 ;
int V_626 , V_624 ;
struct V_495 * V_627 ;
struct V_566 * V_589 ;
int V_26 , V_30 , V_10 ;
V_30 = V_4 -> V_30 ;
V_809 = V_810 = 0 ;
for ( V_26 = 0 ; V_26 < V_30 ; V_26 ++ ) {
V_809 += V_25 -> V_811 [ V_26 ] ;
V_810 += V_25 -> V_812 [ V_26 ] ;
}
V_626 = V_25 -> V_811 [ V_30 ] ;
V_624 = V_25 -> V_812 [ V_30 ] ;
V_627 = F_271 ( V_626 , sizeof( struct V_495 ) ,
V_802 ) ;
V_10 = - V_509 ;
if ( ! V_627 )
goto V_813;
V_4 -> V_626 = V_626 ;
F_272 () ;
V_4 -> V_627 = V_627 ;
F_273 ( V_4 -> V_11 , V_626 ) ;
for ( V_26 = 0 ; V_26 < V_4 -> V_626 ; V_26 ++ ) {
struct V_495 * V_496 = & V_4 -> V_627 [ V_26 ] ;
V_496 -> V_4 = V_4 ;
V_496 -> V_523 = V_809 + V_26 ;
V_10 = F_264 ( V_4 , V_496 ) ;
if ( V_10 )
goto V_813;
F_269 ( V_4 , V_496 ) ;
V_496 -> V_814 = 64 ;
V_496 -> V_815 = V_496 -> V_794 - 64 ;
V_496 -> V_816 = 64 ;
V_496 -> V_817 = V_496 -> V_794 - 64 ;
V_496 -> V_818 = 16 ;
V_496 -> V_819 = 8 ;
V_496 -> V_522 = V_820 ;
if ( V_496 -> V_522 < V_496 -> V_514 )
V_496 -> V_522 = V_496 -> V_514 ;
V_10 = F_202 ( V_4 , V_496 , V_802 ) ;
if ( V_10 )
return V_10 ;
}
V_589 = F_271 ( V_624 , sizeof( struct V_566 ) ,
V_802 ) ;
V_10 = - V_509 ;
if ( ! V_589 )
goto V_813;
V_4 -> V_624 = V_624 ;
F_272 () ;
V_4 -> V_589 = V_589 ;
F_274 ( V_4 -> V_11 , V_624 ) ;
for ( V_26 = 0 ; V_26 < V_4 -> V_624 ; V_26 ++ ) {
struct V_566 * V_496 = & V_4 -> V_589 [ V_26 ] ;
V_496 -> V_4 = V_4 ;
V_496 -> V_625 = V_810 + V_26 ;
V_10 = F_268 ( V_4 , V_496 ) ;
if ( V_10 )
goto V_813;
}
return 0 ;
V_813:
F_263 ( V_4 ) ;
return V_10 ;
}
static int F_275 ( struct V_3 * V_4 , int V_36 )
{
int V_6 = 1000 ;
while ( -- V_6 > 0 ) {
T_1 V_2 = F_16 ( F_238 ( V_36 ) ) ;
if ( V_2 & V_821 )
return 0 ;
}
return - V_8 ;
}
static int F_276 ( struct V_3 * V_4 , int V_36 )
{
T_1 V_2 = F_16 ( F_238 ( V_36 ) ) ;
V_2 |= V_822 ;
F_18 ( F_238 ( V_36 ) , V_2 ) ;
return F_275 ( V_4 , V_36 ) ;
}
static int F_277 ( struct V_3 * V_4 , int V_36 )
{
int V_6 = 1000 ;
while ( -- V_6 > 0 ) {
T_1 V_2 = F_16 ( F_238 ( V_36 ) ) ;
if ( ! ( V_2 & V_823 ) )
return 0 ;
}
return - V_8 ;
}
static int F_278 ( struct V_3 * V_4 , int V_36 )
{
T_1 V_2 = F_16 ( F_238 ( V_36 ) ) ;
int V_10 ;
V_2 |= V_823 ;
F_18 ( F_238 ( V_36 ) , V_2 ) ;
V_10 = F_277 ( V_4 , V_36 ) ;
if ( ! V_10 )
F_18 ( F_279 ( V_36 ) , 0 ) ;
return V_10 ;
}
static int F_280 ( struct V_3 * V_4 , int V_36 )
{
T_1 V_2 ;
F_18 ( F_281 ( V_36 ) , 0 ) ;
F_18 ( F_282 ( V_36 ) , 0 ) ;
F_18 ( F_283 ( V_36 ) , 0 ) ;
F_18 ( F_284 ( V_36 ) , 0 ) ;
F_18 ( F_285 ( V_36 ) , 0 ) ;
F_18 ( F_286 ( V_36 ) , 0 ) ;
F_18 ( F_287 ( V_36 ) , 0 ) ;
V_2 = ( T_1 ) V_4 -> V_30 << V_824 ;
V_2 |= ( V_825 | V_826 ) ;
F_18 ( F_288 ( V_36 ) , V_2 ) ;
return 0 ;
}
static void F_289 ( struct V_3 * V_4 , int V_14 )
{
unsigned long V_87 ;
T_1 V_2 , V_61 ;
F_163 ( V_4 , V_87 ) ;
V_2 = F_16 ( V_827 ) ;
V_61 = ( T_1 ) 1 << V_4 -> V_30 ;
if ( V_14 ) {
V_2 |= V_828 | V_61 ;
} else {
V_2 &= ~ V_61 ;
if ( ( V_2 & ~ V_828 ) == 0 )
V_2 &= ~ V_828 ;
}
F_18 ( V_827 , V_2 ) ;
F_165 ( V_4 , V_87 ) ;
}
static void F_290 ( struct V_3 * V_4 , T_1 V_829 )
{
unsigned long V_87 ;
T_1 V_2 ;
F_163 ( V_4 , V_87 ) ;
V_2 = F_16 ( V_830 ) ;
V_2 &= ~ F_291 ( V_4 -> V_30 ) ;
V_2 |= ( V_829 << F_292 ( V_4 -> V_30 ) ) ;
F_165 ( V_4 , V_87 ) ;
}
static void F_293 ( struct V_3 * V_4 , int V_14 )
{
T_1 V_2 = 0 ;
if ( V_14 ) {
int V_26 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_624 ; V_26 ++ )
V_2 |= ( 1 << V_4 -> V_589 [ V_26 ] . V_625 ) ;
}
F_18 ( F_294 ( V_4 -> V_30 ) , V_2 ) ;
}
static int F_295 ( struct V_3 * V_4 , struct V_566 * V_496 )
{
int V_10 , V_36 = V_496 -> V_625 ;
T_1 V_2 , V_831 ;
V_10 = F_276 ( V_4 , V_36 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_278 ( V_4 , V_36 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_280 ( V_4 , V_36 ) ;
if ( V_10 )
return V_10 ;
F_18 ( F_296 ( V_36 ) , V_496 -> V_805 ) ;
F_18 ( F_297 ( V_36 ) , 0 ) ;
if ( V_496 -> V_798 & ~ ( V_832 |
V_833 ) ) {
F_10 ( V_4 -> V_11 , L_86 ,
V_36 , ( unsigned long long ) V_496 -> V_798 ) ;
return - V_21 ;
}
V_831 = ( V_496 -> V_799 / 8 ) ;
V_2 = ( ( V_831 << V_834 ) |
V_496 -> V_798 ) ;
F_18 ( F_298 ( V_36 ) , V_2 ) ;
if ( ( ( V_496 -> V_790 >> 32 ) & ~ V_835 ) ||
( ( T_3 ) V_496 -> V_790 & ~ V_836 ) ) {
F_10 ( V_4 -> V_11 , L_87 ,
V_36 , ( unsigned long long ) V_496 -> V_790 ) ;
return - V_21 ;
}
F_18 ( F_299 ( V_36 ) , V_496 -> V_790 >> 32 ) ;
F_18 ( F_300 ( V_36 ) , V_496 -> V_790 & V_836 ) ;
F_18 ( F_238 ( V_36 ) , 0 ) ;
V_496 -> V_595 = 0 ;
return 0 ;
}
static void F_301 ( struct V_3 * V_4 )
{
struct V_837 * V_341 = & V_4 -> V_25 -> V_838 [ V_4 -> V_30 ] ;
int V_26 , V_839 = V_341 -> V_839 ;
for ( V_26 = 0 ; V_26 < V_341 -> V_840 ; V_26 ++ ) {
struct V_393 * V_841 = & V_341 -> V_842 [ V_26 ] ;
int V_843 = V_839 + V_26 ;
int V_844 ;
for ( V_844 = 0 ; V_844 < V_845 ; V_844 ++ )
F_18 ( F_302 ( V_843 , V_844 ) ,
V_841 -> V_846 [ V_844 ] ) ;
}
F_18 ( F_303 ( V_4 -> V_30 ) , V_4 -> V_25 -> V_847 [ V_4 -> V_30 ] ) ;
}
static void F_304 ( struct V_3 * V_4 )
{
int type = F_27 ( V_4 -> V_25 -> V_287 , V_4 -> V_30 ) ;
T_1 V_2 ;
switch ( type ) {
case V_848 :
V_2 = V_849 ;
break;
case V_850 :
default:
V_2 = V_851 ;
break;
}
F_18 ( F_305 ( V_4 -> V_30 ) , V_2 ) ;
}
static int F_306 ( struct V_3 * V_4 )
{
struct V_24 * V_25 = V_4 -> V_25 ;
struct V_837 * V_341 = & V_25 -> V_838 [ V_4 -> V_30 ] ;
int V_26 , V_10 , V_852 = F_115 ( V_4 ) ;
int V_853 = V_341 -> V_839 ;
V_10 = F_128 ( V_4 , V_853 , 1 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_129 ( V_4 , V_853 , 1 ) ;
if ( V_10 )
return V_10 ;
for ( V_26 = 0 ; V_26 < V_852 ; V_26 ++ ) {
V_10 = F_130 ( V_4 , V_26 , V_853 , 1 ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
static int F_307 ( struct V_3 * V_4 , int V_36 )
{
return F_308 ( V_4 , F_309 ( V_36 ) ,
V_854 , 1000 , 10 ,
L_88 ) ;
}
static int F_310 ( struct V_3 * V_4 , int V_36 )
{
T_1 V_2 ;
F_18 ( F_311 ( V_36 ) , 0 ) ;
F_18 ( F_312 ( V_36 ) , 0 ) ;
F_18 ( F_313 ( V_36 ) , 0 ) ;
F_18 ( F_314 ( V_36 ) , 0 ) ;
F_18 ( F_315 ( V_36 ) , 0 ) ;
F_18 ( F_316 ( V_36 ) , 0 ) ;
F_18 ( F_317 ( V_36 ) , 0 ) ;
V_2 = ( T_1 ) V_4 -> V_30 << V_855 ;
V_2 |= ( V_856 | V_857 ) ;
F_18 ( F_318 ( V_36 ) , V_2 ) ;
return 0 ;
}
static void F_319 ( struct V_3 * V_4 , struct V_495 * V_496 )
{
T_1 V_2 ;
V_2 = ( ( ( T_1 ) V_496 -> V_814 << V_858 ) |
( ( T_1 ) V_496 -> V_815 << V_859 ) |
( ( T_1 ) V_496 -> V_816 << V_860 ) |
( ( T_1 ) V_496 -> V_817 << V_861 ) ) ;
F_18 ( F_320 ( V_496 -> V_523 ) , V_2 ) ;
}
static int F_321 ( struct V_495 * V_496 , T_1 * V_862 )
{
T_1 V_2 = 0 ;
* V_862 = 0 ;
switch ( V_496 -> V_518 ) {
case 4 * 1024 :
V_2 |= ( V_863 << V_864 ) ;
break;
case 8 * 1024 :
V_2 |= ( V_865 << V_864 ) ;
break;
case 16 * 1024 :
V_2 |= ( V_866 << V_864 ) ;
break;
case 32 * 1024 :
V_2 |= ( V_867 << V_864 ) ;
break;
default:
return - V_21 ;
}
V_2 |= V_868 ;
switch ( V_496 -> V_531 [ 2 ] ) {
case 2 * 1024 :
V_2 |= ( V_869 << V_870 ) ;
break;
case 4 * 1024 :
V_2 |= ( V_871 << V_870 ) ;
break;
case 8 * 1024 :
V_2 |= ( V_872 << V_870 ) ;
break;
case 16 * 1024 :
V_2 |= ( V_873 << V_870 ) ;
break;
default:
return - V_21 ;
}
V_2 |= V_874 ;
switch ( V_496 -> V_531 [ 1 ] ) {
case 1 * 1024 :
V_2 |= ( V_875 << V_876 ) ;
break;
case 2 * 1024 :
V_2 |= ( V_877 << V_876 ) ;
break;
case 4 * 1024 :
V_2 |= ( V_878 << V_876 ) ;
break;
case 8 * 1024 :
V_2 |= ( V_879 << V_876 ) ;
break;
default:
return - V_21 ;
}
V_2 |= V_880 ;
switch ( V_496 -> V_531 [ 0 ] ) {
case 256 :
V_2 |= ( V_881 << V_882 ) ;
break;
case 512 :
V_2 |= ( V_883 << V_882 ) ;
break;
case 1 * 1024 :
V_2 |= ( V_884 << V_882 ) ;
break;
case 2 * 1024 :
V_2 |= ( V_885 << V_882 ) ;
break;
default:
return - V_21 ;
}
* V_862 = V_2 ;
return 0 ;
}
static int F_322 ( struct V_3 * V_4 , int V_36 , int V_14 )
{
T_1 V_2 = F_16 ( F_309 ( V_36 ) ) ;
int V_6 ;
if ( V_14 )
V_2 |= V_886 ;
else
V_2 &= ~ V_886 ;
F_18 ( F_309 ( V_36 ) , V_2 ) ;
V_6 = 1000 ;
while ( -- V_6 > 0 ) {
if ( F_16 ( F_309 ( V_36 ) ) & V_887 )
break;
F_7 ( 10 ) ;
}
if ( V_6 <= 0 )
return - V_8 ;
return 0 ;
}
static int F_323 ( struct V_3 * V_4 , struct V_495 * V_496 )
{
int V_10 , V_36 = V_496 -> V_523 ;
T_1 V_2 ;
V_10 = F_307 ( V_4 , V_36 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_310 ( V_4 , V_36 ) ;
if ( V_10 )
return V_10 ;
F_319 ( V_4 , V_496 ) ;
F_18 ( F_324 ( V_36 ) , V_888 ) ;
F_18 ( F_224 ( V_36 ) ,
( V_617 |
V_782 |
V_783 |
V_889 ) ) ;
F_18 ( F_309 ( V_36 ) , V_496 -> V_790 >> 32 ) ;
F_18 ( F_325 ( V_36 ) ,
( ( V_496 -> V_790 & V_890 ) |
V_891 ) ) ;
F_18 ( F_326 ( V_36 ) ,
( ( T_1 ) V_496 -> V_521 << V_892 ) |
( V_496 -> V_795 & ( V_893 | V_894 ) ) ) ;
V_10 = F_321 ( V_496 , & V_2 ) ;
if ( V_10 )
return V_10 ;
F_18 ( F_327 ( V_36 ) , V_2 ) ;
F_18 ( F_328 ( V_36 ) ,
( ( T_1 ) V_496 -> V_794 << V_895 ) |
( V_496 -> V_793 & ( V_896 | V_897 ) ) ) ;
F_18 ( F_329 ( V_36 ) ,
( ( T_1 ) V_496 -> V_818 << V_898 ) |
V_899 |
( ( T_1 ) V_496 -> V_819 << V_900 ) ) ;
V_10 = F_322 ( V_4 , V_36 , 1 ) ;
if ( V_10 )
return V_10 ;
F_18 ( F_187 ( V_36 ) , V_496 -> V_519 ) ;
V_2 = F_16 ( F_224 ( V_36 ) ) ;
V_2 |= V_889 ;
F_18 ( F_224 ( V_36 ) , V_2 ) ;
return 0 ;
}
static int F_330 ( struct V_3 * V_4 )
{
unsigned long V_87 ;
T_1 V_901 = V_902 ;
int V_10 , V_26 ;
F_163 ( V_4 , V_87 ) ;
F_18 ( V_903 , V_4 -> V_25 -> V_904 ) ;
F_18 ( V_905 , V_906 | ( V_901 & V_907 ) ) ;
F_165 ( V_4 , V_87 ) ;
F_301 ( V_4 ) ;
F_304 ( V_4 ) ;
V_10 = F_306 ( V_4 ) ;
if ( V_10 )
return V_10 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_626 ; V_26 ++ ) {
struct V_495 * V_496 = & V_4 -> V_627 [ V_26 ] ;
V_10 = F_323 ( V_4 , V_496 ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
static int F_331 ( struct V_3 * V_4 )
{
struct V_24 * V_25 = V_4 -> V_25 ;
struct V_908 * V_909 = & V_4 -> V_478 ;
struct V_910 * V_341 ;
int V_375 , V_10 ;
V_375 = V_909 -> V_480 ;
V_341 = & V_25 -> V_911 [ V_375 ] ;
memset ( V_341 , 0 , sizeof( * V_341 ) ) ;
V_341 -> V_403 [ 1 ] = V_912 ;
V_341 -> V_913 [ 1 ] = V_912 ;
V_341 -> V_410 = ( V_914 |
( ( T_1 ) 0 << V_915 ) ) ;
V_10 = F_139 ( V_4 , V_375 , V_341 -> V_403 , V_341 -> V_913 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_140 ( V_4 , V_375 , V_341 -> V_410 ) ;
if ( V_10 )
return V_10 ;
V_341 -> V_916 = 1 ;
V_909 -> V_482 ++ ;
return 0 ;
}
static int F_332 ( struct V_3 * V_4 )
{
struct V_24 * V_25 = V_4 -> V_25 ;
struct V_908 * V_909 = & V_4 -> V_478 ;
int V_26 , V_10 ;
F_18 ( V_474 , V_909 -> V_917 ) ;
F_18 ( V_475 , V_909 -> V_918 ) ;
V_10 = F_306 ( V_4 ) ;
if ( V_10 )
return V_10 ;
for ( V_26 = 0 ; V_26 < V_396 ; V_26 ++ ) {
struct V_919 * V_920 = & V_909 -> V_921 [ V_26 ] ;
F_133 ( V_4 , V_26 , V_4 -> V_30 ,
V_920 -> V_922 , V_920 -> V_923 ) ;
}
for ( V_26 = 0 ; V_26 < V_909 -> V_924 ; V_26 ++ ) {
struct V_925 * V_926 = & V_909 -> V_927 [ V_26 ] ;
V_10 = F_130 ( V_4 , V_926 -> V_928 ,
V_926 -> V_923 , V_926 -> V_379 ) ;
if ( V_10 )
return V_10 ;
}
for ( V_26 = V_425 ; V_26 <= V_477 ; V_26 ++ ) {
int V_375 = V_26 - V_425 ;
V_10 = F_168 ( V_4 , V_26 , V_25 -> V_929 [ V_375 ] ) ;
if ( V_10 )
return V_10 ;
V_10 = F_166 ( V_4 , V_26 , V_25 -> V_930 [ V_375 ] ) ;
if ( V_10 )
return V_10 ;
}
V_10 = F_331 ( V_4 ) ;
if ( V_10 )
return V_10 ;
F_141 ( V_4 , 1 ) ;
return 0 ;
}
static int F_333 ( struct V_3 * V_4 , int V_375 , T_1 * V_35 )
{
F_18 ( V_931 , V_35 [ 0 ] ) ;
F_18 ( V_932 , V_35 [ 1 ] ) ;
F_18 ( V_933 , V_35 [ 2 ] ) ;
F_18 ( V_934 , V_35 [ 3 ] ) ;
F_18 ( V_935 , V_35 [ 4 ] ) ;
F_18 ( V_936 , V_937 ) ;
F_18 ( V_938 ,
( V_939 |
( 0 << V_940 ) |
( F_334 ( V_4 -> V_30 ) << V_941 ) ) ) ;
return F_335 ( V_4 , V_938 , V_942 ,
1000 , 100 ) ;
}
static int F_336 ( struct V_3 * V_4 , int V_375 , T_1 * V_35 )
{
int V_10 ;
V_10 = F_335 ( V_4 , V_938 , V_942 ,
1000 , 100 ) ;
if ( V_10 ) {
F_10 ( V_4 -> V_11 , L_89 ,
( unsigned long long ) F_16 ( V_938 ) ) ;
return V_10 ;
}
F_18 ( V_938 ,
( V_943 |
( 0 << V_940 ) |
( F_334 ( V_4 -> V_30 ) << V_941 ) ) ) ;
V_10 = F_335 ( V_4 , V_938 , V_942 ,
1000 , 100 ) ;
if ( V_10 ) {
F_10 ( V_4 -> V_11 , L_90 ,
( unsigned long long ) F_16 ( V_938 ) ) ;
return V_10 ;
}
V_35 [ 0 ] = F_16 ( V_931 ) ;
V_35 [ 1 ] = F_16 ( V_932 ) ;
V_35 [ 2 ] = F_16 ( V_933 ) ;
V_35 [ 3 ] = F_16 ( V_934 ) ;
V_35 [ 4 ] = F_16 ( V_935 ) ;
return 0 ;
}
static void F_337 ( struct V_3 * V_4 )
{
T_1 V_2 = F_16 ( V_944 ) ;
V_2 |= F_338 ( V_4 -> V_30 ) ;
F_18 ( V_944 , V_2 ) ;
F_7 ( 10 ) ;
V_2 &= ~ F_338 ( V_4 -> V_30 ) ;
F_18 ( V_944 , V_2 ) ;
}
static int F_339 ( struct V_3 * V_4 )
{
T_1 V_35 [ 5 ] , V_945 [ 5 ] ;
int V_26 , V_946 , V_10 ;
if ( V_4 -> V_25 -> V_339 != V_343 ) {
if ( V_4 -> V_30 == 0 || V_4 -> V_30 == 1 )
V_946 = V_947 ;
else
V_946 = V_948 ;
} else
V_946 = V_949 ;
V_35 [ 0 ] = 0 ;
V_35 [ 1 ] = 0 ;
V_35 [ 2 ] = 0 ;
V_35 [ 3 ] = 0 ;
V_35 [ 4 ] = 0 ;
for ( V_26 = 0 ; V_26 < V_946 ; V_26 ++ ) {
V_10 = F_333 ( V_4 , V_26 , V_35 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_336 ( V_4 , V_26 , V_945 ) ;
if ( V_10 )
return V_10 ;
}
F_337 ( V_4 ) ;
F_18 ( F_340 ( V_4 -> V_30 ) , 0 ) ;
F_18 ( V_950 , V_951 ) ;
( void ) F_16 ( V_950 ) ;
F_18 ( V_952 , V_953 ) ;
return 0 ;
}
static void F_341 ( struct V_3 * V_4 , int V_375 , T_1 * V_35 )
{
T_1 V_2 = F_12 ( V_954 ) ;
F_14 ( V_954 , V_2 | V_955 ) ;
F_14 ( V_956 , V_375 ) ;
F_14 ( V_957 , V_35 [ 0 ] ) ;
F_14 ( V_958 , V_35 [ 1 ] ) ;
F_14 ( V_959 , V_35 [ 2 ] ) ;
F_14 ( V_960 , V_35 [ 3 ] ) ;
F_14 ( V_961 , V_35 [ 4 ] ) ;
F_14 ( V_954 , V_2 & ~ V_955 ) ;
}
static void F_342 ( struct V_3 * V_4 , int V_375 , T_1 * V_35 )
{
F_14 ( V_962 , V_375 ) ;
V_35 [ 0 ] = F_12 ( V_963 ) ;
V_35 [ 1 ] = F_12 ( V_964 ) ;
V_35 [ 2 ] = F_12 ( V_965 ) ;
V_35 [ 3 ] = F_12 ( V_966 ) ;
V_35 [ 4 ] = F_12 ( V_967 ) ;
}
static int F_343 ( struct V_3 * V_4 )
{
return F_344 ( V_4 , V_954 , V_968 ,
1000 , 100 , L_91 ) ;
}
static int F_345 ( struct V_3 * V_4 )
{
T_1 V_35 [ 5 ] , V_945 [ 5 ] , V_2 ;
int V_26 , V_946 , V_10 ;
if ( V_4 -> V_25 -> V_339 != V_343 ) {
if ( V_4 -> V_30 == 0 || V_4 -> V_30 == 1 )
V_946 = V_969 ;
else
V_946 = V_970 ;
} else
V_946 = V_971 ;
V_35 [ 0 ] = 0 ;
V_35 [ 1 ] = 0 ;
V_35 [ 2 ] = 0 ;
V_35 [ 3 ] = 0 ;
V_35 [ 4 ] = 0 ;
for ( V_26 = 0 ; V_26 < V_946 ; V_26 ++ ) {
F_341 ( V_4 , V_26 , V_35 ) ;
F_342 ( V_4 , V_26 , V_945 ) ;
}
( void ) F_12 ( V_972 ) ;
( void ) F_12 ( V_972 ) ;
V_10 = F_343 ( V_4 ) ;
if ( V_10 )
return V_10 ;
( void ) F_12 ( V_973 ) ;
( void ) F_12 ( V_974 ) ;
( void ) F_12 ( V_975 ) ;
( void ) F_12 ( V_972 ) ;
F_14 ( V_976 , ~ V_977 ) ;
V_2 = F_12 ( V_954 ) ;
V_2 &= ~ V_978 ;
V_2 |= ( V_979 |
V_980 |
V_981 |
V_982 |
( 0x1ffff << V_983 ) ) ;
F_14 ( V_954 , V_2 ) ;
return 0 ;
}
static void F_97 ( struct V_3 * V_4 , int V_984 )
{
T_1 V_2 ;
V_2 = F_6 ( V_281 ) ;
if ( ( V_4 -> V_87 & V_88 ) != 0 &&
( V_4 -> V_87 & V_344 ) != 0 ) {
if ( V_984 ) {
V_2 |= V_282 ;
V_2 &= ~ V_283 ;
} else {
V_2 |= V_283 ;
V_2 &= ~ V_282 ;
}
}
F_9 ( V_281 , V_2 ) ;
}
static void F_346 ( struct V_3 * V_4 )
{
struct V_38 * V_13 = & V_4 -> V_39 ;
T_1 V_2 ;
if ( V_4 -> V_87 & V_345 ) {
V_2 = F_16 ( V_284 ) ;
V_2 |= V_985 ;
F_18 ( V_284 , V_2 ) ;
}
V_2 = F_6 ( V_281 ) ;
V_2 &= ~ V_986 ;
V_2 |= V_987 ;
if ( V_13 -> V_49 == V_269 ) {
V_2 &= ~ V_986 ;
V_2 |= V_988 ;
} else {
V_2 &= ~ V_988 ;
}
if ( V_4 -> V_87 & V_88 ) {
V_2 &= ~ V_989 ;
} else {
V_2 |= V_989 ;
if ( ! ( V_4 -> V_87 & V_344 ) &&
! ( V_4 -> V_87 & V_345 ) )
V_2 |= V_990 ;
else
V_2 &= ~ V_990 ;
}
V_2 &= ~ V_991 ;
if ( V_13 -> V_160 == V_218 )
V_2 |= V_992 ;
else
V_2 &= ~ V_992 ;
F_9 ( V_281 , V_2 ) ;
V_2 = F_6 ( V_281 ) ;
V_2 &= ~ V_993 ;
if ( V_4 -> V_87 & V_88 ) {
V_2 |= V_994 ;
} else {
if ( V_13 -> V_160 == V_158 )
V_2 |= V_995 ;
else
V_2 |= V_996 ;
}
F_9 ( V_281 , V_2 ) ;
}
static void F_347 ( struct V_3 * V_4 )
{
struct V_38 * V_13 = & V_4 -> V_39 ;
T_1 V_2 ;
V_2 = V_997 ;
if ( V_13 -> V_49 == V_269 )
V_2 |= V_998 ;
else
V_2 &= ~ V_998 ;
if ( V_13 -> V_160 == V_158 )
V_2 |= V_999 ;
else
V_2 &= ~ V_999 ;
V_2 &= ~ ( V_1000 |
V_1001 ) ;
if ( ! ( V_4 -> V_87 & V_88 ) &&
! ( V_4 -> V_87 & V_344 ) &&
V_13 -> V_160 == V_218 )
V_2 |= V_1002 ;
else
V_2 &= ~ V_1002 ;
F_9 ( V_1003 , V_2 ) ;
}
static void F_96 ( struct V_3 * V_4 )
{
if ( V_4 -> V_87 & V_366 )
F_346 ( V_4 ) ;
else
F_347 ( V_4 ) ;
}
static void F_348 ( struct V_3 * V_4 )
{
int V_6 = 1000 ;
T_1 V_2 = F_64 ( V_1004 ) ;
V_2 |= V_1005 ;
F_349 ( V_1004 , V_2 ) ;
while ( ( -- V_6 >= 0 ) && ( V_2 & V_1005 ) ) {
F_7 ( 100 ) ;
V_2 = F_64 ( V_1004 ) ;
}
}
static void F_350 ( struct V_3 * V_4 )
{
int V_6 = 1000 ;
T_1 V_2 = F_67 ( V_1006 ) ;
V_2 |= V_1007 ;
F_351 ( V_1006 , V_2 ) ;
while ( ( -- V_6 >= 0 ) && ( V_2 & V_1007 ) ) {
F_7 ( 100 ) ;
V_2 = F_67 ( V_1006 ) ;
}
}
static int F_352 ( struct V_3 * V_4 )
{
struct V_38 * V_13 = & V_4 -> V_39 ;
T_1 V_2 ;
switch ( V_4 -> V_87 & ( V_88 |
V_344 |
V_345 ) ) {
case V_344 :
F_349 ( V_1008 , V_1009 | V_1010 ) ;
F_349 ( V_1011 , 0 ) ;
F_348 ( V_4 ) ;
break;
case V_88 :
case V_88 | V_344 :
case V_88 | V_345 :
if ( ! ( V_4 -> V_87 & V_366 ) )
return - V_21 ;
V_2 = F_6 ( V_281 ) ;
V_2 &= ~ V_991 ;
F_9 ( V_281 , V_2 ) ;
F_350 ( V_4 ) ;
V_2 = F_67 ( V_1006 ) ;
if ( V_13 -> V_49 == V_50 )
V_2 |= V_1012 ;
else
V_2 &= ~ V_1012 ;
F_351 ( V_1006 , V_2 ) ;
F_351 ( V_1013 , 0 ) ;
( void ) F_67 ( V_1014 ) ;
( void ) F_67 ( V_1015 ) ;
break;
case V_345 :
F_348 ( V_4 ) ;
F_349 ( V_1008 , V_1009 | V_1010 ) ;
F_349 ( V_1011 , 0 ) ;
break;
case 0 :
case V_345 | V_344 :
F_349 ( V_1011 , V_1016 ) ;
F_348 ( V_4 ) ;
break;
default:
return - V_21 ;
}
return 0 ;
}
static int F_353 ( struct V_3 * V_4 )
{
return F_354 ( V_4 , V_1017 ,
( V_1018 |
V_1019 ) ,
1000 , 100 , L_92 ) ;
}
static int F_355 ( struct V_3 * V_4 )
{
int V_6 ;
F_9 ( V_1020 , V_1021 ) ;
V_6 = 1000 ;
while ( -- V_6 >= 0 ) {
if ( ! ( F_6 ( V_1020 ) & V_1021 ) )
break;
F_7 ( 100 ) ;
}
if ( V_6 < 0 ) {
F_221 ( V_4 -> V_511 , L_93 ,
V_4 -> V_30 ,
( unsigned long long ) F_6 ( V_1020 ) ) ;
return - V_8 ;
}
return 0 ;
}
static int F_356 ( struct V_3 * V_4 )
{
if ( V_4 -> V_87 & V_366 )
return F_353 ( V_4 ) ;
else
return F_355 ( V_4 ) ;
}
static void F_357 ( struct V_3 * V_4 , T_1 F_226 , T_1 V_946 )
{
T_1 V_2 ;
V_2 = F_6 ( V_1022 ) ;
V_2 &= ~ ( V_1023 |
V_1024 ) ;
V_2 |= ( F_226 << V_1025 ) ;
V_2 |= ( F_226 << V_1026 ) ;
F_9 ( V_1022 , V_2 ) ;
F_9 ( V_1027 , V_946 ) ;
F_9 ( V_1028 , ~ ( T_1 ) 0 ) ;
V_2 = F_6 ( V_1029 ) ;
if ( V_4 -> V_87 & V_88 ) {
V_2 &= ~ V_1030 ;
V_2 |= ( V_1031 << V_1032 ) ;
} else {
V_2 &= ~ V_1033 ;
V_2 |= ( V_1034 << V_1035 ) ;
}
F_9 ( V_1029 , V_2 ) ;
V_2 = F_6 ( V_281 ) ;
V_2 &= ~ ( V_1036 |
V_1037 |
V_1038 |
V_1039 ) ;
F_9 ( V_281 , V_2 ) ;
F_9 ( V_1040 , 0 ) ;
F_9 ( V_1041 , 0 ) ;
}
static void F_358 ( struct V_3 * V_4 , T_1 F_226 , T_1 V_946 )
{
T_1 V_2 ;
F_9 ( V_1042 , F_226 ) ;
F_9 ( V_1043 , V_946 ) ;
F_9 ( V_1044 , ~ ( T_1 ) 0 ) ;
F_9 ( V_1045 , 0x8808 ) ;
F_9 ( V_1046 , 7 ) ;
V_2 = F_6 ( V_1047 ) ;
V_2 &= ~ ( V_1048 |
V_1049 ) ;
F_9 ( V_1047 , V_2 ) ;
}
static void F_359 ( struct V_3 * V_4 )
{
T_1 F_226 , V_946 ;
F_226 = 64 ;
if ( V_4 -> V_11 -> V_804 > V_808 )
V_946 = 9216 ;
else
V_946 = 1522 ;
F_186 ( F_226 & 0x7 ) ;
if ( V_4 -> V_87 & V_366 )
F_357 ( V_4 , F_226 , V_946 ) ;
else
F_358 ( V_4 , F_226 , V_946 ) ;
}
static int F_360 ( struct V_3 * V_4 )
{
int V_6 ;
F_9 ( V_1050 ,
V_1051 | V_1052 ) ;
V_6 = 1000 ;
while ( -- V_6 >= 0 ) {
if ( ! ( F_6 ( V_1050 ) & ( V_1051 |
V_1052 ) ) )
break;
F_7 ( 100 ) ;
}
if ( V_6 < 0 ) {
F_221 ( V_4 -> V_511 , L_94 ,
V_4 -> V_30 ,
( unsigned long long ) F_6 ( V_1050 ) ) ;
return - V_8 ;
}
return 0 ;
}
static int F_361 ( struct V_3 * V_4 )
{
int V_6 ;
F_9 ( V_1053 , V_1054 ) ;
V_6 = 1000 ;
while ( -- V_6 >= 0 ) {
if ( ! ( F_6 ( V_1053 ) & V_1054 ) )
break;
F_7 ( 100 ) ;
}
if ( V_6 < 0 ) {
F_221 ( V_4 -> V_511 , L_95 ,
V_4 -> V_30 ,
( unsigned long long ) F_6 ( V_1053 ) ) ;
return - V_8 ;
}
return 0 ;
}
static int F_362 ( struct V_3 * V_4 )
{
if ( V_4 -> V_87 & V_366 )
return F_360 ( V_4 ) ;
else
return F_361 ( V_4 ) ;
}
static void F_363 ( struct V_3 * V_4 )
{
struct V_24 * V_25 = V_4 -> V_25 ;
struct V_837 * V_341 = & V_25 -> V_838 [ V_4 -> V_30 ] ;
int V_853 = V_341 -> V_839 ;
unsigned long V_26 ;
T_1 V_2 ;
F_9 ( V_1055 , 0 ) ;
F_9 ( V_1056 , 0 ) ;
F_9 ( V_1057 , 0 ) ;
F_9 ( V_1058 , 0 ) ;
F_9 ( V_1059 , 0 ) ;
for ( V_26 = 0 ; V_26 < V_1060 ; V_26 ++ )
F_9 ( F_364 ( V_26 ) , 0 ) ;
F_9 ( V_1061 , ~ ( T_1 ) 0 ) ;
F_128 ( V_4 , V_853 , 1 ) ;
F_129 ( V_4 , V_853 , 1 ) ;
V_2 = F_6 ( V_281 ) ;
V_2 &= ~ ( V_1062 |
V_1063 |
V_1064 |
V_1065 |
V_1066 |
V_1067 |
V_1068 |
V_1069 |
V_1070 |
V_1071 |
V_1072 |
V_1073 ) ;
V_2 |= ( V_1074 ) ;
F_9 ( V_281 , V_2 ) ;
F_9 ( V_1075 , 0 ) ;
F_9 ( V_1076 , 0 ) ;
F_9 ( V_1077 , 0 ) ;
F_9 ( V_1078 , 0 ) ;
F_9 ( V_1079 , 0 ) ;
F_9 ( V_1080 , 0 ) ;
F_9 ( V_1081 , 0 ) ;
F_9 ( V_1082 , 0 ) ;
F_9 ( V_1083 , 0 ) ;
F_9 ( V_1084 , 0 ) ;
F_9 ( V_1085 , 0 ) ;
F_9 ( V_1086 , 0 ) ;
F_9 ( V_1087 , 0 ) ;
F_9 ( V_1088 , 0 ) ;
F_9 ( V_1089 , 0 ) ;
}
static void F_365 ( struct V_3 * V_4 )
{
struct V_24 * V_25 = V_4 -> V_25 ;
struct V_837 * V_341 = & V_25 -> V_838 [ V_4 -> V_30 ] ;
int V_853 = V_341 -> V_839 ;
unsigned long V_26 ;
T_1 V_2 ;
F_9 ( V_1090 , 0 ) ;
F_9 ( V_1091 , 0 ) ;
F_9 ( V_1092 , 0 ) ;
F_9 ( V_1093 , 0 ) ;
F_9 ( V_1094 , 0 ) ;
for ( V_26 = 0 ; V_26 < V_1060 ; V_26 ++ )
F_9 ( F_366 ( V_26 ) , 0 ) ;
F_128 ( V_4 , V_853 , 1 ) ;
F_129 ( V_4 , V_853 , 1 ) ;
F_9 ( V_1095 , ~ ( T_1 ) 0 ) ;
V_2 = F_6 ( V_1096 ) ;
V_2 &= ~ ( V_1097 |
V_1098 |
V_1099 |
V_1100 |
V_1101 |
V_1102 |
V_1103 ) ;
V_2 |= ( V_1104 ) ;
F_9 ( V_1096 , V_2 ) ;
V_2 = F_6 ( V_377 ) ;
V_2 |= V_1105 ;
F_9 ( V_377 , V_2 ) ;
}
static void F_367 ( struct V_3 * V_4 )
{
F_114 ( V_4 , V_4 -> V_11 -> V_1106 ) ;
if ( V_4 -> V_87 & V_366 )
F_363 ( V_4 ) ;
else
F_365 ( V_4 ) ;
}
static void F_368 ( struct V_3 * V_4 , int V_14 )
{
T_1 V_2 = F_6 ( V_281 ) ;
if ( V_14 )
V_2 |= V_1039 ;
else
V_2 &= ~ V_1039 ;
F_9 ( V_281 , V_2 ) ;
}
static void F_369 ( struct V_3 * V_4 , int V_14 )
{
T_1 V_2 = F_6 ( V_1047 ) ;
if ( V_14 )
V_2 |= V_1049 ;
else
V_2 &= ~ V_1049 ;
F_9 ( V_1047 , V_2 ) ;
}
static void F_370 ( struct V_3 * V_4 , int V_14 )
{
if ( V_4 -> V_87 & V_366 )
F_368 ( V_4 , V_14 ) ;
else
F_369 ( V_4 , V_14 ) ;
}
static void F_371 ( struct V_3 * V_4 , int V_14 )
{
T_1 V_2 = F_6 ( V_281 ) ;
V_2 &= ~ ( V_1074 |
V_1063 ) ;
if ( V_4 -> V_87 & V_1107 )
V_2 |= V_1074 ;
if ( V_4 -> V_87 & V_1108 )
V_2 |= V_1063 ;
if ( V_14 )
V_2 |= V_1062 ;
else
V_2 &= ~ V_1062 ;
F_9 ( V_281 , V_2 ) ;
}
static void F_372 ( struct V_3 * V_4 , int V_14 )
{
T_1 V_2 = F_6 ( V_1096 ) ;
V_2 &= ~ ( V_1104 |
V_1100 ) ;
if ( V_4 -> V_87 & V_1107 )
V_2 |= V_1104 ;
if ( V_4 -> V_87 & V_1108 )
V_2 |= V_1100 ;
if ( V_14 )
V_2 |= V_1097 ;
else
V_2 &= ~ V_1097 ;
F_9 ( V_1096 , V_2 ) ;
}
static void F_373 ( struct V_3 * V_4 , int V_14 )
{
if ( V_4 -> V_87 & V_366 )
F_371 ( V_4 , V_14 ) ;
else
F_372 ( V_4 , V_14 ) ;
}
static int F_374 ( struct V_3 * V_4 )
{
int V_10 ;
F_96 ( V_4 ) ;
V_10 = F_352 ( V_4 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_356 ( V_4 ) ;
if ( V_10 )
return V_10 ;
F_359 ( V_4 ) ;
V_10 = F_362 ( V_4 ) ;
if ( V_10 )
return V_10 ;
F_367 ( V_4 ) ;
F_359 ( V_4 ) ;
F_370 ( V_4 , 1 ) ;
F_373 ( V_4 , 1 ) ;
return 0 ;
}
static void F_375 ( struct V_3 * V_4 , struct V_566 * V_496 )
{
( void ) F_276 ( V_4 , V_496 -> V_625 ) ;
}
static void F_376 ( struct V_3 * V_4 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_624 ; V_26 ++ ) {
struct V_566 * V_496 = & V_4 -> V_589 [ V_26 ] ;
F_375 ( V_4 , V_496 ) ;
}
}
static void F_377 ( struct V_3 * V_4 , struct V_566 * V_496 )
{
( void ) F_278 ( V_4 , V_496 -> V_625 ) ;
}
static void F_378 ( struct V_3 * V_4 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_624 ; V_26 ++ ) {
struct V_566 * V_496 = & V_4 -> V_589 [ V_26 ] ;
F_377 ( V_4 , V_496 ) ;
}
}
static void F_379 ( struct V_3 * V_4 , struct V_495 * V_496 )
{
( void ) F_322 ( V_4 , V_496 -> V_523 , 0 ) ;
}
static void F_380 ( struct V_3 * V_4 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_626 ; V_26 ++ ) {
struct V_495 * V_496 = & V_4 -> V_627 [ V_26 ] ;
F_379 ( V_4 , V_496 ) ;
}
}
static void F_381 ( struct V_3 * V_4 , struct V_495 * V_496 )
{
int V_36 = V_496 -> V_523 ;
( void ) F_307 ( V_4 , V_36 ) ;
F_18 ( F_324 ( V_36 ) , V_1109 ) ;
F_18 ( F_224 ( V_36 ) , 0 ) ;
( void ) F_322 ( V_4 , V_36 , 0 ) ;
}
static void F_382 ( struct V_3 * V_4 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_626 ; V_26 ++ ) {
struct V_495 * V_496 = & V_4 -> V_627 [ V_26 ] ;
F_381 ( V_4 , V_496 ) ;
}
}
static void F_383 ( struct V_3 * V_4 )
{
T_1 V_1110 , V_1111 , V_2 ;
int V_6 ;
V_1110 = F_12 ( V_962 ) ;
V_1111 = F_12 ( V_956 ) ;
V_6 = 100 ;
while ( -- V_6 >= 0 && ( V_1110 != V_1111 ) ) {
V_1110 = F_12 ( V_962 ) ;
V_1111 = F_12 ( V_956 ) ;
}
if ( V_6 < 0 &&
( V_1110 != 0 && V_1111 != 1 ) ) {
F_10 ( V_4 -> V_11 , L_96 ,
( unsigned long long ) F_12 ( V_962 ) ,
( unsigned long long ) F_12 ( V_956 ) ) ;
}
V_2 = F_12 ( V_954 ) ;
V_2 &= ~ ( V_979 |
V_980 |
V_981 |
V_982 ) ;
F_14 ( V_954 , V_2 ) ;
( void ) F_343 ( V_4 ) ;
}
static int F_384 ( struct V_3 * V_4 )
{
int V_26 , V_10 ;
F_164 ( V_4 , V_1112 , V_473 , V_4 -> V_11 , L_97 ) ;
F_289 ( V_4 , 1 ) ;
F_293 ( V_4 , 1 ) ;
F_290 ( V_4 , 0 ) ;
F_164 ( V_4 , V_1112 , V_473 , V_4 -> V_11 , L_98 ) ;
for ( V_26 = 0 ; V_26 < V_4 -> V_624 ; V_26 ++ ) {
struct V_566 * V_496 = & V_4 -> V_589 [ V_26 ] ;
V_10 = F_295 ( V_4 , V_496 ) ;
if ( V_10 )
return V_10 ;
}
F_164 ( V_4 , V_1112 , V_473 , V_4 -> V_11 , L_99 ) ;
V_10 = F_330 ( V_4 ) ;
if ( V_10 )
goto V_1113;
F_164 ( V_4 , V_1112 , V_473 , V_4 -> V_11 , L_100 ) ;
V_10 = F_332 ( V_4 ) ;
if ( V_10 )
goto V_1114;
F_164 ( V_4 , V_1112 , V_473 , V_4 -> V_11 , L_101 ) ;
V_10 = F_339 ( V_4 ) ;
if ( V_10 )
goto V_1114;
F_164 ( V_4 , V_1112 , V_473 , V_4 -> V_11 , L_102 ) ;
V_10 = F_345 ( V_4 ) ;
if ( V_10 )
goto V_1114;
F_164 ( V_4 , V_1112 , V_473 , V_4 -> V_11 , L_103 ) ;
V_10 = F_374 ( V_4 ) ;
if ( V_10 )
goto V_1115;
return 0 ;
V_1115:
F_164 ( V_4 , V_1112 , V_473 , V_4 -> V_11 , L_104 ) ;
F_383 ( V_4 ) ;
V_1114:
F_164 ( V_4 , V_1112 , V_473 , V_4 -> V_11 , L_105 ) ;
F_380 ( V_4 ) ;
F_382 ( V_4 ) ;
V_1113:
F_164 ( V_4 , V_1112 , V_473 , V_4 -> V_11 , L_106 ) ;
F_376 ( V_4 ) ;
F_378 ( V_4 ) ;
return V_10 ;
}
static void F_385 ( struct V_3 * V_4 )
{
F_164 ( V_4 , V_1116 , V_473 , V_4 -> V_11 , L_107 ) ;
F_25 ( V_4 , 0 ) ;
F_164 ( V_4 , V_1116 , V_473 , V_4 -> V_11 , L_108 ) ;
F_373 ( V_4 , 0 ) ;
F_164 ( V_4 , V_1116 , V_473 , V_4 -> V_11 , L_109 ) ;
F_383 ( V_4 ) ;
F_164 ( V_4 , V_1116 , V_473 , V_4 -> V_11 , L_110 ) ;
F_376 ( V_4 ) ;
F_164 ( V_4 , V_1116 , V_473 , V_4 -> V_11 , L_111 ) ;
F_380 ( V_4 ) ;
F_164 ( V_4 , V_1116 , V_473 , V_4 -> V_11 , L_112 ) ;
F_378 ( V_4 ) ;
F_164 ( V_4 , V_1116 , V_473 , V_4 -> V_11 , L_113 ) ;
F_382 ( V_4 ) ;
}
static void F_386 ( struct V_3 * V_4 )
{
int V_30 = V_4 -> V_30 ;
int V_26 , V_1117 = 1 ;
sprintf ( V_4 -> V_1118 [ 0 ] , L_114 , V_4 -> V_11 -> V_1119 ) ;
if ( V_30 == 0 ) {
sprintf ( V_4 -> V_1118 [ 1 ] , L_115 , V_4 -> V_11 -> V_1119 ) ;
sprintf ( V_4 -> V_1118 [ 2 ] , L_116 , V_4 -> V_11 -> V_1119 ) ;
V_1117 = 3 ;
}
for ( V_26 = 0 ; V_26 < V_4 -> V_28 - V_1117 ; V_26 ++ ) {
if ( V_26 < V_4 -> V_626 )
sprintf ( V_4 -> V_1118 [ V_26 + V_1117 ] , L_117 ,
V_4 -> V_11 -> V_1119 , V_26 ) ;
else if ( V_26 < V_4 -> V_624 + V_4 -> V_626 )
sprintf ( V_4 -> V_1118 [ V_26 + V_1117 ] , L_118 , V_4 -> V_11 -> V_1119 ,
V_26 - V_4 -> V_626 ) ;
}
}
static int F_387 ( struct V_3 * V_4 )
{
int V_26 , V_1117 , V_10 ;
F_386 ( V_4 ) ;
V_10 = 0 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_28 ; V_26 ++ ) {
struct V_12 * V_13 = & V_4 -> V_29 [ V_26 ] ;
V_10 = F_388 ( V_13 -> V_784 , F_254 , V_1120 ,
V_4 -> V_1118 [ V_26 ] , V_13 ) ;
if ( V_10 )
goto V_1121;
}
return 0 ;
V_1121:
for ( V_1117 = 0 ; V_1117 < V_26 ; V_1117 ++ ) {
struct V_12 * V_13 = & V_4 -> V_29 [ V_1117 ] ;
F_389 ( V_13 -> V_784 , V_13 ) ;
}
return V_10 ;
}
static void F_390 ( struct V_3 * V_4 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_28 ; V_26 ++ ) {
struct V_12 * V_13 = & V_4 -> V_29 [ V_26 ] ;
F_389 ( V_13 -> V_784 , V_13 ) ;
}
}
static void F_391 ( struct V_3 * V_4 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_28 ; V_26 ++ )
F_392 ( & V_4 -> V_29 [ V_26 ] . V_538 ) ;
}
static void F_393 ( struct V_3 * V_4 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_28 ; V_26 ++ )
F_394 ( & V_4 -> V_29 [ V_26 ] . V_538 ) ;
}
static int F_395 ( struct V_308 * V_11 )
{
struct V_3 * V_4 = F_396 ( V_11 ) ;
int V_10 ;
F_100 ( V_11 ) ;
V_10 = F_270 ( V_4 ) ;
if ( V_10 )
goto V_813;
V_10 = F_25 ( V_4 , 0 ) ;
if ( V_10 )
goto V_1122;
V_10 = F_387 ( V_4 ) ;
if ( V_10 )
goto V_1122;
F_391 ( V_4 ) ;
F_397 ( & V_4 -> V_155 ) ;
V_10 = F_384 ( V_4 ) ;
if ( ! V_10 ) {
F_398 ( & V_4 -> V_15 ) ;
V_4 -> V_15 . V_337 = V_338 + V_336 ;
V_4 -> V_15 . V_35 = ( unsigned long ) V_4 ;
V_4 -> V_15 . V_1123 = F_108 ;
V_10 = F_25 ( V_4 , 1 ) ;
if ( V_10 )
F_385 ( V_4 ) ;
}
F_399 ( & V_4 -> V_155 ) ;
if ( V_10 ) {
F_393 ( V_4 ) ;
goto V_1124;
}
F_400 ( V_11 ) ;
if ( V_4 -> V_39 . V_49 != V_330 )
F_98 ( V_11 ) ;
F_109 ( & V_4 -> V_15 ) ;
return 0 ;
V_1124:
F_390 ( V_4 ) ;
V_1122:
F_263 ( V_4 ) ;
V_813:
return V_10 ;
}
static void F_401 ( struct V_3 * V_4 , struct V_308 * V_11 )
{
F_402 ( & V_4 -> V_1125 ) ;
F_393 ( V_4 ) ;
F_403 ( V_11 ) ;
F_404 ( & V_4 -> V_15 ) ;
F_397 ( & V_4 -> V_155 ) ;
F_385 ( V_4 ) ;
F_399 ( & V_4 -> V_155 ) ;
}
static int F_405 ( struct V_308 * V_11 )
{
struct V_3 * V_4 = F_396 ( V_11 ) ;
F_401 ( V_4 , V_11 ) ;
F_390 ( V_4 ) ;
F_263 ( V_4 ) ;
F_97 ( V_4 , 0 ) ;
return 0 ;
}
static void F_406 ( struct V_3 * V_4 )
{
struct V_662 * V_663 = & V_4 -> V_664 . V_665 ;
V_663 -> V_668 += F_6 ( V_1040 ) ;
V_663 -> V_573 += F_6 ( V_1041 ) ;
V_663 -> V_685 += F_6 ( V_1089 ) ;
V_663 -> V_688 += F_6 ( V_1126 ) ;
V_663 -> V_691 += F_6 ( V_1078 ) ;
V_663 -> V_694 += F_6 ( V_1077 ) ;
V_663 -> V_697 += F_6 ( V_1076 ) ;
V_663 -> V_700 += F_6 ( V_1079 ) ;
V_663 -> V_703 += F_6 ( V_1080 ) ;
V_663 -> V_706 += F_6 ( V_1081 ) ;
V_663 -> V_709 += F_6 ( V_1082 ) ;
V_663 -> V_712 += F_6 ( V_1083 ) ;
V_663 -> V_715 += F_6 ( V_1084 ) ;
V_663 -> V_718 += F_6 ( V_1085 ) ;
V_663 -> V_721 += F_6 ( V_1075 ) ;
V_663 -> V_724 += F_6 ( V_1088 ) ;
V_663 -> V_727 += F_6 ( V_1086 ) ;
V_663 -> V_730 += F_6 ( V_1087 ) ;
}
static void F_407 ( struct V_3 * V_4 )
{
struct V_743 * V_663 = & V_4 -> V_664 . V_744 ;
V_663 -> V_573 += F_6 ( V_1127 ) ;
V_663 -> V_668 += F_6 ( V_1128 ) ;
V_663 -> V_755 += F_6 ( V_1129 ) ;
V_663 -> V_688 += F_6 ( V_1130 ) ;
V_663 -> V_730 += F_6 ( V_1130 ) ;
V_663 -> V_727 += F_6 ( V_1131 ) ;
}
static void F_408 ( struct V_3 * V_4 )
{
if ( V_4 -> V_87 & V_366 )
F_406 ( V_4 ) ;
else
F_407 ( V_4 ) ;
}
static void F_409 ( struct V_3 * V_4 ,
struct V_1132 * V_1133 )
{
T_1 V_1134 , V_1135 , V_1136 , V_1137 ;
struct V_495 * V_627 ;
int V_26 ;
V_1134 = V_1135 = V_1136 = V_1137 = 0 ;
V_627 = F_410 ( V_4 -> V_627 ) ;
if ( ! V_627 )
goto V_1138;
for ( V_26 = 0 ; V_26 < V_4 -> V_626 ; V_26 ++ ) {
struct V_495 * V_496 = & V_627 [ V_26 ] ;
F_219 ( V_4 , V_496 , 0 ) ;
V_1134 += V_496 -> V_561 ;
V_1137 += V_496 -> V_562 ;
V_1135 += V_496 -> V_526 ;
V_1136 += V_496 -> V_600 ;
}
V_1138:
V_1133 -> V_561 = V_1134 ;
V_1133 -> V_562 = V_1137 ;
V_1133 -> V_526 = V_1135 ;
V_1133 -> V_600 = V_1136 ;
}
static void F_411 ( struct V_3 * V_4 ,
struct V_1132 * V_1133 )
{
T_1 V_1134 , V_1136 , V_1137 ;
struct V_566 * V_589 ;
int V_26 ;
V_1134 = V_1136 = V_1137 = 0 ;
V_589 = F_410 ( V_4 -> V_589 ) ;
if ( ! V_589 )
goto V_1138;
for ( V_26 = 0 ; V_26 < V_4 -> V_624 ; V_26 ++ ) {
struct V_566 * V_496 = & V_589 [ V_26 ] ;
V_1134 += V_496 -> V_572 ;
V_1137 += V_496 -> V_573 ;
V_1136 += V_496 -> V_1139 ;
}
V_1138:
V_1133 -> V_572 = V_1134 ;
V_1133 -> V_573 = V_1137 ;
V_1133 -> V_1139 = V_1136 ;
}
static struct V_1132 * F_412 ( struct V_308 * V_11 ,
struct V_1132 * V_1133 )
{
struct V_3 * V_4 = F_396 ( V_11 ) ;
if ( F_413 ( V_11 ) ) {
F_409 ( V_4 , V_1133 ) ;
F_411 ( V_4 , V_1133 ) ;
}
return V_1133 ;
}
static void F_414 ( struct V_3 * V_4 , T_4 * V_1140 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < 16 ; V_26 ++ )
F_9 ( F_364 ( V_26 ) , V_1140 [ V_26 ] ) ;
}
static void F_415 ( struct V_3 * V_4 , T_4 * V_1140 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < 16 ; V_26 ++ )
F_9 ( F_366 ( V_26 ) , V_1140 [ V_26 ] ) ;
}
static void F_416 ( struct V_3 * V_4 , T_4 * V_1140 )
{
if ( V_4 -> V_87 & V_366 )
F_414 ( V_4 , V_1140 ) ;
else
F_415 ( V_4 , V_1140 ) ;
}
static void F_417 ( struct V_308 * V_11 )
{
struct V_3 * V_4 = F_396 ( V_11 ) ;
int V_26 , V_1141 , V_10 ;
struct V_1142 * V_1143 ;
unsigned long V_87 ;
T_4 V_1140 [ 16 ] = { 0 , } ;
F_63 ( & V_4 -> V_155 , V_87 ) ;
F_373 ( V_4 , 0 ) ;
V_4 -> V_87 &= ~ ( V_1107 | V_1108 ) ;
if ( V_11 -> V_87 & V_1144 )
V_4 -> V_87 |= V_1108 ;
if ( ( V_11 -> V_87 & V_1145 ) || ( ! F_418 ( V_11 ) ) )
V_4 -> V_87 |= V_1107 ;
V_1141 = F_419 ( V_11 ) ;
if ( V_1141 > F_115 ( V_4 ) ) {
V_1141 = 0 ;
V_4 -> V_87 |= V_1108 ;
}
if ( V_1141 ) {
int V_375 = 0 ;
F_420 (ha, dev) {
V_10 = F_116 ( V_4 , V_375 , V_1143 -> V_362 ) ;
if ( V_10 )
F_421 ( V_11 , L_119 ,
V_10 , V_375 ) ;
V_10 = F_123 ( V_4 , V_375 , 1 ) ;
if ( V_10 )
F_421 ( V_11 , L_120 ,
V_10 , V_375 ) ;
V_375 ++ ;
}
} else {
int V_1146 ;
if ( V_4 -> V_87 & V_366 )
V_1146 = 0 ;
else
V_1146 = 1 ;
for ( V_26 = V_1146 ; V_26 < F_115 ( V_4 ) ; V_26 ++ ) {
V_10 = F_123 ( V_4 , V_26 , 0 ) ;
if ( V_10 )
F_421 ( V_11 , L_121 ,
V_10 , V_26 ) ;
}
}
if ( V_11 -> V_87 & V_1145 ) {
for ( V_26 = 0 ; V_26 < 16 ; V_26 ++ )
V_1140 [ V_26 ] = 0xffff ;
} else if ( ! F_418 ( V_11 ) ) {
F_422 (ha, dev) {
T_3 V_1147 = F_423 ( V_1148 , V_1143 -> V_362 ) ;
V_1147 >>= 24 ;
V_1140 [ V_1147 >> 4 ] |= ( 1 << ( 15 - ( V_1147 & 0xf ) ) ) ;
}
}
if ( V_4 -> V_87 & V_1107 )
F_416 ( V_4 , V_1140 ) ;
F_373 ( V_4 , 1 ) ;
F_65 ( & V_4 -> V_155 , V_87 ) ;
}
static int F_424 ( struct V_308 * V_11 , void * V_501 )
{
struct V_3 * V_4 = F_396 ( V_11 ) ;
struct V_1149 * V_362 = V_501 ;
unsigned long V_87 ;
if ( ! F_425 ( V_362 -> V_1150 ) )
return - V_21 ;
memcpy ( V_11 -> V_1106 , V_362 -> V_1150 , V_1148 ) ;
if ( ! F_413 ( V_11 ) )
return 0 ;
F_63 ( & V_4 -> V_155 , V_87 ) ;
F_373 ( V_4 , 0 ) ;
F_114 ( V_4 , V_11 -> V_1106 ) ;
F_373 ( V_4 , 1 ) ;
F_65 ( & V_4 -> V_155 , V_87 ) ;
return 0 ;
}
static int F_426 ( struct V_308 * V_11 , struct V_1151 * V_1152 , int V_1153 )
{
return - V_1154 ;
}
static void F_427 ( struct V_3 * V_4 )
{
V_4 -> V_11 -> V_1155 = V_338 ;
F_393 ( V_4 ) ;
F_428 ( V_4 -> V_11 ) ;
}
static void F_429 ( struct V_3 * V_4 )
{
F_430 ( V_4 -> V_11 ) ;
F_391 ( V_4 ) ;
F_25 ( V_4 , 1 ) ;
}
static void F_431 ( struct V_3 * V_4 )
{
int V_26 , V_1117 , V_1156 , V_10 ;
if ( V_4 -> V_627 ) {
for ( V_26 = 0 ; V_26 < V_4 -> V_626 ; V_26 ++ ) {
struct V_495 * V_496 = & V_4 -> V_627 [ V_26 ] ;
for ( V_1117 = 0 , V_1156 = 0 ; V_1117 < V_499 ; V_1117 ++ ) {
struct V_485 * V_485 ;
V_485 = V_496 -> V_504 [ V_1117 ] ;
while ( V_485 ) {
struct V_485 * V_565 =
(struct V_485 * ) V_485 -> V_505 ;
T_1 V_458 = V_485 -> V_375 ;
V_458 = V_458 >> V_517 ;
V_496 -> V_516 [ V_1156 ++ ] = F_184 ( V_458 ) ;
V_485 = V_565 ;
}
}
for (; V_1156 < V_499 ; V_1156 ++ ) {
V_10 = F_180 ( V_4 , V_496 , V_616 , V_1156 ) ;
if ( F_70 ( V_10 ) )
break;
}
V_496 -> V_519 = V_496 -> V_521 - 1 ;
V_496 -> V_524 = 0 ;
V_496 -> V_520 = 0 ;
V_496 -> V_535 = 0 ;
}
}
if ( V_4 -> V_589 ) {
for ( V_26 = 0 ; V_26 < V_4 -> V_624 ; V_26 ++ ) {
struct V_566 * V_496 = & V_4 -> V_589 [ V_26 ] ;
for ( V_1117 = 0 ; V_1117 < V_797 ; V_1117 ++ ) {
if ( V_496 -> V_569 [ V_1117 ] . V_484 )
( void ) F_204 ( V_4 , V_496 , V_1117 ) ;
}
V_496 -> V_799 = V_797 ;
V_496 -> V_800 = 0 ;
V_496 -> V_587 = 0 ;
V_496 -> V_801 = 0 ;
}
}
}
static void F_432 ( struct V_1157 * V_1158 )
{
struct V_3 * V_4 = F_231 ( V_1158 , struct V_3 , V_1125 ) ;
unsigned long V_87 ;
int V_10 ;
F_63 ( & V_4 -> V_155 , V_87 ) ;
if ( ! F_413 ( V_4 -> V_11 ) ) {
F_65 ( & V_4 -> V_155 , V_87 ) ;
return;
}
F_65 ( & V_4 -> V_155 , V_87 ) ;
F_404 ( & V_4 -> V_15 ) ;
F_427 ( V_4 ) ;
F_63 ( & V_4 -> V_155 , V_87 ) ;
F_385 ( V_4 ) ;
F_65 ( & V_4 -> V_155 , V_87 ) ;
F_431 ( V_4 ) ;
F_63 ( & V_4 -> V_155 , V_87 ) ;
V_10 = F_384 ( V_4 ) ;
if ( ! V_10 ) {
V_4 -> V_15 . V_337 = V_338 + V_336 ;
F_109 ( & V_4 -> V_15 ) ;
F_429 ( V_4 ) ;
}
F_65 ( & V_4 -> V_155 , V_87 ) ;
}
static void F_433 ( struct V_308 * V_11 )
{
struct V_3 * V_4 = F_396 ( V_11 ) ;
F_221 ( V_4 -> V_511 , L_122 ,
V_11 -> V_1119 ) ;
F_434 ( & V_4 -> V_1125 ) ;
}
static void F_435 ( struct V_566 * V_496 , int V_375 ,
T_1 V_505 , T_1 V_492 , T_1 V_1159 ,
T_1 V_1160 )
{
V_792 * V_1161 = & V_496 -> V_579 [ V_375 ] ;
* V_1161 = F_436 ( V_1159 |
( V_1160 << V_1162 ) |
( V_492 << V_1163 ) |
( V_505 & V_1164 ) ) ;
}
static T_1 F_437 ( struct V_483 * V_484 , struct V_1165 * V_1166 ,
T_1 V_1167 , T_1 V_492 )
{
T_4 V_1168 , V_1169 ;
T_1 V_1170 , V_1171 , V_1172 , V_862 ;
T_5 V_1173 ;
int V_428 ;
V_1168 = F_438 ( V_1166 -> V_1174 ) ;
V_1169 = V_1168 ;
if ( V_1168 == V_1175 ) {
struct V_1176 * V_920 = (struct V_1176 * ) V_1166 ;
T_10 V_2 = V_920 -> V_1177 ;
V_1169 = F_438 ( V_2 ) ;
}
V_428 = V_1172 = 0 ;
switch ( V_484 -> V_563 ) {
case F_439 ( V_1178 ) :
V_1173 = F_440 ( V_484 ) -> V_563 ;
V_1172 = F_440 ( V_484 ) -> V_1172 ;
break;
case F_439 ( V_1179 ) :
V_1173 = F_441 ( V_484 ) -> V_1180 ;
V_1172 = ( 40 >> 2 ) ;
V_428 = 1 ;
break;
default:
V_1173 = V_1172 = 0 ;
break;
}
V_1170 = V_1181 ;
if ( V_484 -> V_552 == V_1182 ) {
T_1 V_1183 , V_1184 ;
V_1170 = ( V_1173 == V_1185 ?
V_1186 :
( V_1173 == V_1187 ?
V_1188 : V_1189 ) ) ;
V_1183 = F_442 ( V_484 ) -
( V_1167 + sizeof( struct V_570 ) ) ;
V_1184 = V_1183 + V_484 -> V_1190 ;
V_1170 |= ( V_1183 / 2 ) << V_1191 ;
V_1170 |= ( V_1184 / 2 ) << V_1192 ;
}
V_1171 = F_443 ( V_484 ) -
( V_1167 + sizeof( struct V_570 ) ) ;
V_862 = ( ( ( V_1167 / 2 ) << V_1193 ) |
( V_492 << V_575 ) |
( ( V_1171 / 2 ) << V_1194 ) |
( V_1172 << V_1195 ) |
( ( V_1169 < 1536 ) ? V_1196 : 0 ) |
( ( V_1168 == V_1175 ) ? V_1197 : 0 ) |
( V_428 ? V_1198 : 0 ) |
V_1170 ) ;
return V_862 ;
}
static T_11 F_444 ( struct V_483 * V_484 ,
struct V_308 * V_11 )
{
struct V_3 * V_4 = F_396 ( V_11 ) ;
unsigned long V_1199 , V_1200 ;
struct V_583 * V_584 ;
struct V_566 * V_496 ;
struct V_570 * V_341 ;
unsigned int V_492 , V_1201 ;
struct V_1165 * V_1166 ;
int V_800 , V_26 , V_1202 ;
T_1 V_505 , V_1203 ;
V_26 = F_445 ( V_484 ) ;
V_496 = & V_4 -> V_589 [ V_26 ] ;
V_584 = F_210 ( V_11 , V_26 ) ;
if ( F_213 ( V_496 ) <= ( F_174 ( V_484 ) -> V_488 + 1 ) ) {
F_446 ( V_584 ) ;
F_221 ( V_4 -> V_511 , L_123 , V_11 -> V_1119 ) ;
V_496 -> V_1139 ++ ;
return V_1204 ;
}
if ( V_484 -> V_492 < V_1205 ) {
unsigned int V_1167 = V_1205 - V_484 -> V_492 ;
if ( F_447 ( V_484 , V_1167 ) )
goto V_229;
F_448 ( V_484 , V_1167 ) ;
}
V_492 = sizeof( struct V_570 ) + 15 ;
if ( F_449 ( V_484 ) < V_492 ) {
struct V_483 * V_1206 ;
V_1206 = F_450 ( V_484 , V_492 ) ;
if ( ! V_1206 ) {
V_496 -> V_1139 ++ ;
goto V_1207;
}
F_451 ( V_484 ) ;
V_484 = V_1206 ;
} else
F_452 ( V_484 ) ;
V_1199 = ( ( unsigned long ) V_484 -> V_35 & ( 16 - 1 ) ) ;
V_1200 = V_1199 + sizeof( struct V_570 ) ;
V_1166 = (struct V_1165 * ) V_484 -> V_35 ;
V_341 = (struct V_570 * ) F_453 ( V_484 , V_1200 ) ;
V_492 = V_484 -> V_492 - sizeof( struct V_570 ) ;
V_341 -> V_87 = F_436 ( F_437 ( V_484 , V_1166 , V_1199 , V_492 ) ) ;
V_341 -> V_1208 = 0 ;
V_492 = F_205 ( V_484 ) ;
V_505 = V_4 -> V_304 -> V_1209 ( V_4 -> V_511 , V_484 -> V_35 ,
V_492 , V_578 ) ;
V_800 = V_496 -> V_800 ;
V_496 -> V_569 [ V_800 ] . V_484 = V_484 ;
V_496 -> V_569 [ V_800 ] . V_505 = V_505 ;
V_1203 = V_1210 ;
if ( ++ V_496 -> V_1211 == V_496 -> V_806 ) {
V_496 -> V_1211 = 0 ;
V_1203 |= V_580 ;
V_496 -> V_581 ++ ;
}
V_1202 = V_492 ;
V_1201 = F_174 ( V_484 ) -> V_488 ;
while ( V_1202 > 0 ) {
V_1202 -= V_582 ;
V_1201 ++ ;
}
while ( V_492 > 0 ) {
unsigned int V_1212 = V_492 ;
if ( V_1212 > V_582 )
V_1212 = V_582 ;
F_435 ( V_496 , V_800 , V_505 , V_1212 , V_1203 , V_1201 ) ;
V_1203 = V_1201 = 0 ;
V_800 = F_207 ( V_496 , V_800 ) ;
V_505 += V_1212 ;
V_492 -= V_1212 ;
}
for ( V_26 = 0 ; V_26 < F_174 ( V_484 ) -> V_488 ; V_26 ++ ) {
T_6 * V_489 = & F_174 ( V_484 ) -> V_490 [ V_26 ] ;
V_492 = V_489 -> V_487 ;
V_505 = V_4 -> V_304 -> V_510 ( V_4 -> V_511 , V_489 -> V_485 ,
V_489 -> V_491 , V_492 ,
V_578 ) ;
V_496 -> V_569 [ V_800 ] . V_484 = NULL ;
V_496 -> V_569 [ V_800 ] . V_505 = V_505 ;
F_435 ( V_496 , V_800 , V_505 , V_492 , 0 , 0 ) ;
V_800 = F_207 ( V_496 , V_800 ) ;
}
if ( V_800 < V_496 -> V_800 )
V_496 -> V_801 ^= V_1213 ;
V_496 -> V_800 = V_800 ;
F_18 ( F_279 ( V_496 -> V_625 ) , V_496 -> V_801 | ( V_800 << 3 ) ) ;
if ( F_70 ( F_213 ( V_496 ) <= ( V_1214 + 1 ) ) ) {
F_446 ( V_584 ) ;
if ( F_213 ( V_496 ) > F_214 ( V_496 ) )
F_217 ( V_584 ) ;
}
V_229:
return V_1215 ;
V_1207:
V_496 -> V_1139 ++ ;
F_451 ( V_484 ) ;
goto V_229;
}
static int F_454 ( struct V_308 * V_11 , int V_1216 )
{
struct V_3 * V_4 = F_396 ( V_11 ) ;
int V_10 , V_1217 , V_1218 ;
if ( V_1216 < 68 || V_1216 > V_1219 )
return - V_21 ;
V_1217 = ( V_11 -> V_804 > V_808 ) ;
V_1218 = ( V_1216 > V_808 ) ;
V_11 -> V_804 = V_1216 ;
if ( ! F_413 ( V_11 ) ||
( V_1217 == V_1218 ) )
return 0 ;
F_401 ( V_4 , V_11 ) ;
F_263 ( V_4 ) ;
F_391 ( V_4 ) ;
V_10 = F_270 ( V_4 ) ;
if ( V_10 )
return V_10 ;
F_397 ( & V_4 -> V_155 ) ;
V_10 = F_384 ( V_4 ) ;
if ( ! V_10 ) {
F_398 ( & V_4 -> V_15 ) ;
V_4 -> V_15 . V_337 = V_338 + V_336 ;
V_4 -> V_15 . V_35 = ( unsigned long ) V_4 ;
V_4 -> V_15 . V_1123 = F_108 ;
V_10 = F_25 ( V_4 , 1 ) ;
if ( V_10 )
F_385 ( V_4 ) ;
}
F_399 ( & V_4 -> V_155 ) ;
if ( ! V_10 ) {
F_400 ( V_11 ) ;
if ( V_4 -> V_39 . V_49 != V_330 )
F_98 ( V_11 ) ;
F_109 ( & V_4 -> V_15 ) ;
}
return V_10 ;
}
static void F_455 ( struct V_308 * V_11 ,
struct V_1220 * V_1221 )
{
struct V_3 * V_4 = F_396 ( V_11 ) ;
struct V_1222 * V_1223 = & V_4 -> V_1223 ;
strcpy ( V_1221 -> V_1224 , V_1225 ) ;
strcpy ( V_1221 -> V_1226 , V_1227 ) ;
sprintf ( V_1221 -> V_1228 , L_124 ,
V_1223 -> V_1229 , V_1223 -> V_1230 ) ;
if ( V_4 -> V_25 -> V_339 != V_343 )
strcpy ( V_1221 -> V_1231 , F_456 ( V_4 -> V_1232 ) ) ;
}
static int F_457 ( struct V_308 * V_11 , struct V_1233 * V_1153 )
{
struct V_3 * V_4 = F_396 ( V_11 ) ;
struct V_38 * V_13 ;
V_13 = & V_4 -> V_39 ;
memset ( V_1153 , 0 , sizeof( * V_1153 ) ) ;
V_1153 -> V_1234 = V_4 -> V_175 ;
V_1153 -> V_173 = V_13 -> V_173 ;
V_1153 -> V_174 = V_13 -> V_227 ;
V_1153 -> V_296 = V_13 -> V_213 ;
F_458 ( V_1153 , V_13 -> V_160 ) ;
V_1153 -> V_301 = V_13 -> V_161 ;
V_1153 -> V_30 = ( V_4 -> V_87 & V_344 ) ? V_1235 : V_1236 ;
V_1153 -> V_1237 = ( V_4 -> V_87 & V_345 ) ?
V_1238 : V_1239 ;
return 0 ;
}
static int F_459 ( struct V_308 * V_11 , struct V_1233 * V_1153 )
{
struct V_3 * V_4 = F_396 ( V_11 ) ;
struct V_38 * V_13 = & V_4 -> V_39 ;
V_13 -> V_174 = V_1153 -> V_174 ;
V_13 -> V_302 = F_460 ( V_1153 ) ;
V_13 -> V_301 = V_1153 -> V_301 ;
V_13 -> V_296 = V_1153 -> V_296 ;
return F_112 ( V_4 ) ;
}
static T_3 F_461 ( struct V_308 * V_11 )
{
struct V_3 * V_4 = F_396 ( V_11 ) ;
return V_4 -> V_1240 ;
}
static void F_462 ( struct V_308 * V_11 , T_3 V_1241 )
{
struct V_3 * V_4 = F_396 ( V_11 ) ;
V_4 -> V_1240 = V_1241 ;
}
static int F_463 ( struct V_308 * V_11 )
{
struct V_3 * V_4 = F_396 ( V_11 ) ;
if ( V_4 -> V_39 . V_296 )
return F_112 ( V_4 ) ;
return 0 ;
}
static int F_464 ( struct V_308 * V_11 )
{
struct V_3 * V_4 = F_396 ( V_11 ) ;
return V_4 -> V_1242 ;
}
static int F_465 ( struct V_308 * V_11 ,
struct V_1243 * V_1244 , T_5 * V_35 )
{
struct V_3 * V_4 = F_396 ( V_11 ) ;
T_3 V_486 , V_492 , V_2 ;
V_486 = V_1244 -> V_486 ;
V_492 = V_1244 -> V_492 ;
if ( V_486 + V_492 < V_486 )
return - V_21 ;
if ( V_486 >= V_4 -> V_1242 )
return - V_21 ;
if ( V_486 + V_492 > V_4 -> V_1242 )
V_492 = V_1244 -> V_492 = V_4 -> V_1242 - V_486 ;
if ( V_486 & 3 ) {
T_3 V_1245 , V_1246 ;
V_1245 = V_486 & 3 ;
V_1246 = 4 - V_1245 ;
if ( V_1246 > V_492 )
V_1246 = V_492 ;
V_2 = F_16 ( F_466 ( ( V_486 - V_1245 ) / 4 ) ) ;
memcpy ( V_35 , ( ( char * ) & V_2 ) + V_1245 , V_1246 ) ;
V_35 += V_1246 ;
V_492 -= V_1246 ;
V_486 += V_1246 ;
}
while ( V_492 >= 4 ) {
V_2 = F_16 ( F_466 ( V_486 / 4 ) ) ;
memcpy ( V_35 , & V_2 , 4 ) ;
V_35 += 4 ;
V_492 -= 4 ;
V_486 += 4 ;
}
if ( V_492 ) {
V_2 = F_16 ( F_466 ( V_486 / 4 ) ) ;
memcpy ( V_35 , & V_2 , V_492 ) ;
}
return 0 ;
}
static void F_467 ( int V_1247 , T_5 * V_1248 )
{
switch ( V_1247 ) {
case V_1249 :
case V_1250 :
* V_1248 = V_1185 ;
break;
case V_1251 :
case V_1252 :
* V_1248 = V_1187 ;
break;
case V_1253 :
case V_1254 :
* V_1248 = V_1255 ;
break;
case V_1256 :
case V_1257 :
* V_1248 = V_1258 ;
break;
case V_1259 :
case V_1260 :
* V_1248 = V_1261 ;
break;
default:
* V_1248 = 0 ;
break;
}
}
static int F_468 ( T_1 V_421 , int * V_1247 )
{
switch ( V_421 ) {
case V_1262 :
* V_1247 = V_1249 ;
break;
case V_1263 :
* V_1247 = V_1251 ;
break;
case V_1264 :
* V_1247 = V_1256 ;
break;
case V_1265 :
* V_1247 = V_1253 ;
break;
case V_1266 :
* V_1247 = V_1250 ;
break;
case V_1267 :
* V_1247 = V_1252 ;
break;
case V_1268 :
* V_1247 = V_1257 ;
break;
case V_477 :
* V_1247 = V_1254 ;
break;
case V_425 :
case V_1269 :
case V_1270 :
case V_426 :
* V_1247 = V_1271 ;
break;
default:
return 0 ;
}
return 1 ;
}
static int F_469 ( int V_1247 , T_1 * V_421 )
{
switch ( V_1247 ) {
case V_1249 :
* V_421 = V_1262 ;
break;
case V_1251 :
* V_421 = V_1263 ;
break;
case V_1272 :
case V_1256 :
case V_1259 :
* V_421 = V_1264 ;
break;
case V_1253 :
* V_421 = V_1265 ;
break;
case V_1250 :
* V_421 = V_1266 ;
break;
case V_1252 :
* V_421 = V_1267 ;
break;
case V_1273 :
case V_1257 :
case V_1260 :
* V_421 = V_1268 ;
break;
case V_1254 :
* V_421 = V_477 ;
break;
default:
return 0 ;
}
return 1 ;
}
static T_1 F_470 ( T_1 V_930 )
{
T_1 V_1274 = 0 ;
if ( V_930 & V_1275 )
V_1274 |= V_1276 ;
if ( V_930 & V_1277 )
V_1274 |= V_1278 ;
if ( V_930 & V_1279 )
V_1274 |= V_1280 ;
if ( V_930 & V_1281 )
V_1274 |= V_1282 ;
if ( V_930 & V_1283 )
V_1274 |= V_1284 ;
if ( V_930 & ( V_1285 << V_1286 ) )
V_1274 |= V_1287 ;
if ( V_930 & ( V_1285 << V_1288 ) )
V_1274 |= V_1289 ;
return V_1274 ;
}
static int F_471 ( T_1 V_1274 , T_1 * V_930 )
{
T_1 V_403 = 0 ;
if ( V_1274 & V_1276 )
V_403 |= V_1275 ;
if ( V_1274 & V_1278 )
V_403 |= V_1277 ;
if ( V_1274 & V_1280 )
V_403 |= V_1279 ;
if ( V_1274 & V_1282 )
V_403 |= V_1281 ;
if ( V_1274 & V_1284 )
V_403 |= V_1283 ;
if ( V_1274 & V_1287 )
V_403 |= ( V_1285 << V_1286 ) ;
if ( V_1274 & V_1289 )
V_403 |= ( V_1285 << V_1288 ) ;
* V_930 = V_403 ;
return 1 ;
}
static int F_472 ( struct V_3 * V_4 , struct V_1290 * V_1291 )
{
T_1 V_421 ;
V_1291 -> V_35 = 0 ;
if ( ! F_469 ( V_1291 -> V_1247 , & V_421 ) )
return - V_21 ;
if ( V_4 -> V_25 -> V_929 [ V_421 - V_425 ] &
V_1292 )
V_1291 -> V_35 = V_1293 ;
else
V_1291 -> V_35 = F_470 ( V_4 -> V_25 -> V_930 [ V_421 -
V_425 ] ) ;
return 0 ;
}
static void F_473 ( struct V_910 * V_341 ,
struct V_1294 * V_1295 )
{
T_3 V_586 ;
T_4 V_1296 ;
V_586 = ( V_341 -> V_403 [ 3 ] & V_1297 ) >> V_1298 ;
V_1295 -> V_1299 . V_1300 . V_1301 = F_474 ( V_586 ) ;
V_586 = ( V_341 -> V_403 [ 3 ] & V_1302 ) >> V_1303 ;
V_1295 -> V_1299 . V_1300 . V_1304 = F_474 ( V_586 ) ;
V_586 = ( V_341 -> V_913 [ 3 ] & V_1297 ) >> V_1298 ;
V_1295 -> V_1305 . V_1300 . V_1301 = F_474 ( V_586 ) ;
V_586 = ( V_341 -> V_913 [ 3 ] & V_1302 ) >> V_1303 ;
V_1295 -> V_1305 . V_1300 . V_1304 = F_474 ( V_586 ) ;
V_1295 -> V_1299 . V_1300 . V_1306 = ( V_341 -> V_403 [ 2 ] & V_1307 ) >>
V_1308 ;
V_1295 -> V_1305 . V_1300 . V_1306 = ( V_341 -> V_913 [ 2 ] & V_1307 ) >>
V_1308 ;
switch ( V_1295 -> V_1247 ) {
case V_1249 :
case V_1251 :
case V_1253 :
V_1296 = ( ( V_341 -> V_403 [ 2 ] & V_1309 ) >>
V_1310 ) >> 16 ;
V_1295 -> V_1299 . V_1300 . V_1311 = F_439 ( V_1296 ) ;
V_1296 = ( ( V_341 -> V_403 [ 2 ] & V_1309 ) >>
V_1310 ) & 0xffff ;
V_1295 -> V_1299 . V_1300 . V_1312 = F_439 ( V_1296 ) ;
V_1296 = ( ( V_341 -> V_913 [ 2 ] & V_1309 ) >>
V_1310 ) >> 16 ;
V_1295 -> V_1305 . V_1300 . V_1311 = F_439 ( V_1296 ) ;
V_1296 = ( ( V_341 -> V_913 [ 2 ] & V_1309 ) >>
V_1310 ) & 0xffff ;
V_1295 -> V_1305 . V_1300 . V_1312 = F_439 ( V_1296 ) ;
break;
case V_1256 :
case V_1259 :
V_586 = ( V_341 -> V_403 [ 2 ] & V_1309 ) >>
V_1310 ;
V_1295 -> V_1299 . V_1313 . V_1314 = F_474 ( V_586 ) ;
V_586 = ( V_341 -> V_913 [ 2 ] & V_1309 ) >>
V_1310 ;
V_1295 -> V_1305 . V_1313 . V_1314 = F_474 ( V_586 ) ;
break;
case V_1271 :
V_586 = ( V_341 -> V_403 [ 2 ] & V_1309 ) >>
V_1310 ;
V_1295 -> V_1299 . V_1315 . V_1316 = F_474 ( V_586 ) ;
V_586 = ( V_341 -> V_913 [ 2 ] & V_1309 ) >>
V_1310 ;
V_1295 -> V_1305 . V_1315 . V_1316 = F_474 ( V_586 ) ;
V_1295 -> V_1299 . V_1315 . V_1317 =
( V_341 -> V_403 [ 2 ] & V_1318 ) >>
V_1319 ;
V_1295 -> V_1305 . V_1315 . V_1317 =
( V_341 -> V_913 [ 2 ] & V_1318 ) >>
V_1319 ;
V_1295 -> V_1299 . V_1315 . V_1320 = V_1321 ;
break;
default:
break;
}
}
static int F_475 ( struct V_3 * V_4 ,
struct V_1290 * V_1291 )
{
struct V_24 * V_25 = V_4 -> V_25 ;
struct V_910 * V_341 ;
struct V_1294 * V_1295 = & V_1291 -> V_1322 ;
T_4 V_386 ;
T_1 V_421 ;
int V_862 = 0 ;
V_386 = F_170 ( V_4 , ( T_4 ) V_1291 -> V_1322 . V_1323 ) ;
V_341 = & V_25 -> V_911 [ V_386 ] ;
if ( ! V_341 -> V_916 ) {
F_476 ( V_4 -> V_11 , L_125 ,
V_25 -> V_375 , ( T_4 ) V_1291 -> V_1322 . V_1323 , V_386 ) ;
return - V_21 ;
}
V_421 = ( V_341 -> V_403 [ 0 ] & V_1324 ) >>
V_1325 ;
V_862 = F_468 ( V_421 , & V_1295 -> V_1247 ) ;
if ( V_862 < 0 ) {
F_476 ( V_4 -> V_11 , L_126 ,
V_25 -> V_375 ) ;
V_862 = - V_21 ;
goto V_229;
}
if ( V_1295 -> V_1247 == V_1256 || V_1295 -> V_1247 == V_1257 ) {
T_3 V_1317 = ( V_341 -> V_403 [ 2 ] & V_1318 ) >>
V_1319 ;
if ( V_1317 == V_1261 ) {
if ( V_1295 -> V_1247 == V_1256 )
V_1295 -> V_1247 = V_1259 ;
else
V_1295 -> V_1247 = V_1260 ;
}
}
switch ( V_1295 -> V_1247 ) {
case V_1249 :
case V_1251 :
case V_1253 :
case V_1256 :
case V_1259 :
F_473 ( V_341 , V_1295 ) ;
break;
case V_1250 :
case V_1252 :
case V_1254 :
case V_1257 :
case V_1260 :
V_862 = - V_21 ;
break;
case V_1271 :
F_473 ( V_341 , V_1295 ) ;
break;
default:
V_862 = - V_21 ;
break;
}
if ( V_862 < 0 )
goto V_229;
if ( V_341 -> V_410 & V_1326 )
V_1295 -> V_1327 = V_1328 ;
else
V_1295 -> V_1327 = ( V_341 -> V_410 & V_1329 ) >>
V_915 ;
V_1291 -> V_35 = F_171 ( V_4 ) ;
V_229:
return V_862 ;
}
static int F_477 ( struct V_3 * V_4 ,
struct V_1290 * V_1291 ,
T_3 * V_1330 )
{
struct V_24 * V_25 = V_4 -> V_25 ;
struct V_910 * V_341 ;
int V_26 , V_386 , V_1331 ;
unsigned long V_87 ;
int V_862 = 0 ;
V_1291 -> V_35 = F_171 ( V_4 ) ;
F_163 ( V_4 , V_87 ) ;
for ( V_1331 = 0 , V_26 = 0 ; V_26 < V_1291 -> V_35 ; V_26 ++ ) {
V_386 = F_170 ( V_4 , V_26 ) ;
V_341 = & V_25 -> V_911 [ V_386 ] ;
if ( ! V_341 -> V_916 )
continue;
if ( V_1331 == V_1291 -> V_1332 ) {
V_862 = - V_1333 ;
break;
}
V_1330 [ V_1331 ] = V_26 ;
V_1331 ++ ;
}
F_165 ( V_4 , V_87 ) ;
return V_862 ;
}
static int F_478 ( struct V_308 * V_11 , struct V_1290 * V_1153 ,
void * V_1330 )
{
struct V_3 * V_4 = F_396 ( V_11 ) ;
int V_862 = 0 ;
switch ( V_1153 -> V_1153 ) {
case V_1334 :
V_862 = F_472 ( V_4 , V_1153 ) ;
break;
case V_1335 :
V_1153 -> V_35 = V_4 -> V_626 ;
break;
case V_1336 :
V_1153 -> V_1332 = F_172 ( V_4 ) ;
break;
case V_1337 :
V_862 = F_475 ( V_4 , V_1153 ) ;
break;
case V_1338 :
V_862 = F_477 ( V_4 , V_1153 , ( T_3 * ) V_1330 ) ;
break;
default:
V_862 = - V_21 ;
break;
}
return V_862 ;
}
static int F_479 ( struct V_3 * V_4 , struct V_1290 * V_1291 )
{
T_1 V_421 ;
T_1 V_930 = 0 ;
unsigned long V_87 ;
if ( ! F_469 ( V_1291 -> V_1247 , & V_421 ) )
return - V_21 ;
if ( V_421 < V_425 ||
V_421 > V_477 )
return - V_21 ;
if ( V_1291 -> V_35 & V_1293 ) {
F_163 ( V_4 , V_87 ) ;
V_930 = V_4 -> V_25 -> V_929 [ V_421 -
V_425 ] ;
V_930 |= V_1292 ;
F_18 ( F_169 ( V_421 - V_425 ) , V_930 ) ;
V_4 -> V_25 -> V_929 [ V_421 - V_425 ] = V_930 ;
F_165 ( V_4 , V_87 ) ;
return 0 ;
} else {
if ( V_4 -> V_25 -> V_929 [ V_421 - V_425 ] &
V_1292 ) {
F_163 ( V_4 , V_87 ) ;
V_930 = V_4 -> V_25 -> V_929 [ V_421 -
V_425 ] ;
V_930 &= ~ V_1292 ;
F_18 ( F_169 ( V_421 - V_425 ) ,
V_930 ) ;
V_4 -> V_25 -> V_929 [ V_421 - V_425 ] =
V_930 ;
F_165 ( V_4 , V_87 ) ;
}
}
if ( ! F_471 ( V_1291 -> V_35 , & V_930 ) )
return - V_21 ;
F_163 ( V_4 , V_87 ) ;
F_18 ( F_167 ( V_421 - V_425 ) , V_930 ) ;
V_4 -> V_25 -> V_930 [ V_421 - V_425 ] = V_930 ;
F_165 ( V_4 , V_87 ) ;
return 0 ;
}
static void F_480 ( struct V_1294 * V_1295 ,
struct V_910 * V_341 ,
int V_1339 , T_1 V_421 )
{
T_5 V_1248 = 0 ;
T_3 V_1340 , V_1341 , V_1342 , V_1343 , V_1314 , V_1344 ;
T_4 V_1345 , V_1346 , V_1347 , V_1348 ;
V_1340 = F_481 ( V_1295 -> V_1299 . V_1300 . V_1301 ) ;
V_1342 = F_481 ( V_1295 -> V_1305 . V_1300 . V_1301 ) ;
V_1341 = F_481 ( V_1295 -> V_1299 . V_1300 . V_1304 ) ;
V_1343 = F_481 ( V_1295 -> V_1305 . V_1300 . V_1304 ) ;
V_341 -> V_403 [ 0 ] = V_421 << V_1325 ;
V_341 -> V_913 [ 0 ] = V_1324 ;
V_341 -> V_403 [ 1 ] = ( T_1 ) V_1339 << V_1349 ;
V_341 -> V_913 [ 1 ] = V_1350 ;
V_341 -> V_403 [ 3 ] = ( T_1 ) V_1340 << V_1298 ;
V_341 -> V_403 [ 3 ] |= V_1341 ;
V_341 -> V_913 [ 3 ] = ( T_1 ) V_1342 << V_1298 ;
V_341 -> V_913 [ 3 ] |= V_1343 ;
V_341 -> V_403 [ 2 ] |= ( ( T_1 ) V_1295 -> V_1299 . V_1300 . V_1306 <<
V_1308 ) ;
V_341 -> V_913 [ 2 ] |= ( ( T_1 ) V_1295 -> V_1305 . V_1300 . V_1306 <<
V_1308 ) ;
switch ( V_1295 -> V_1247 ) {
case V_1249 :
case V_1251 :
case V_1253 :
V_1345 = F_438 ( V_1295 -> V_1299 . V_1300 . V_1311 ) ;
V_1347 = F_438 ( V_1295 -> V_1305 . V_1300 . V_1311 ) ;
V_1346 = F_438 ( V_1295 -> V_1299 . V_1300 . V_1312 ) ;
V_1348 = F_438 ( V_1295 -> V_1305 . V_1300 . V_1312 ) ;
V_341 -> V_403 [ 2 ] |= ( ( ( T_1 ) V_1345 << 16 ) | V_1346 ) ;
V_341 -> V_913 [ 2 ] |= ( ( ( T_1 ) V_1347 << 16 ) | V_1348 ) ;
F_467 ( V_1295 -> V_1247 , & V_1248 ) ;
break;
case V_1256 :
case V_1259 :
V_1314 = F_481 ( V_1295 -> V_1299 . V_1313 . V_1314 ) ;
V_1344 = F_481 ( V_1295 -> V_1305 . V_1313 . V_1314 ) ;
V_341 -> V_403 [ 2 ] |= V_1314 ;
V_341 -> V_913 [ 2 ] |= V_1344 ;
F_467 ( V_1295 -> V_1247 , & V_1248 ) ;
break;
case V_1271 :
V_1314 = F_481 ( V_1295 -> V_1299 . V_1315 . V_1316 ) ;
V_1344 = F_481 ( V_1295 -> V_1305 . V_1315 . V_1316 ) ;
V_341 -> V_403 [ 2 ] |= V_1314 ;
V_341 -> V_913 [ 2 ] |= V_1344 ;
V_1248 = V_1295 -> V_1299 . V_1315 . V_1317 ;
break;
default:
break;
}
V_341 -> V_403 [ 2 ] |= ( ( T_1 ) V_1248 << V_1319 ) ;
if ( V_1248 ) {
V_341 -> V_913 [ 2 ] |= V_1318 ;
}
}
static int F_482 ( struct V_3 * V_4 ,
struct V_1290 * V_1291 )
{
struct V_24 * V_25 = V_4 -> V_25 ;
struct V_910 * V_341 ;
struct V_1294 * V_1295 = & V_1291 -> V_1322 ;
struct V_837 * V_393 = & V_25 -> V_838 [ V_4 -> V_30 ] ;
int V_1351 = V_393 -> V_839 ;
T_4 V_386 ;
T_1 V_421 ;
unsigned long V_87 ;
int V_10 , V_862 ;
V_862 = 0 ;
V_386 = V_1291 -> V_1322 . V_1323 ;
if ( V_386 >= F_171 ( V_4 ) )
return - V_21 ;
if ( V_1295 -> V_1247 == V_1271 ) {
int V_26 ;
int V_1352 = 0 ;
struct V_1353 * V_1354 = & V_1295 -> V_1299 . V_1315 ;
struct V_1353 * V_1355 = & V_1295 -> V_1305 . V_1315 ;
if ( V_1354 -> V_1320 != V_1321 )
return - V_21 ;
F_163 ( V_4 , V_87 ) ;
for ( V_26 = 0 ; V_26 < V_1356 ; V_26 ++ ) {
if ( V_25 -> V_1357 [ V_26 ] ) {
if ( V_1354 -> V_1317 == V_25 -> V_1358 [ V_26 ] ) {
V_421 = V_25 -> V_1357 [ V_26 ] ;
V_25 -> V_1359 [ V_26 ] ++ ;
V_1352 = 1 ;
break;
}
} else {
switch ( V_26 ) {
case 0 :
V_421 = V_425 ;
break;
case 1 :
V_421 = V_1269 ;
break;
case 2 :
V_421 = V_1270 ;
break;
case 3 :
V_421 = V_426 ;
break;
default:
break;
}
V_862 = F_147 ( V_4 , V_421 , 0 ,
V_1354 -> V_1317 ,
V_1354 -> V_1306 ,
V_1355 -> V_1306 ) ;
if ( V_862 )
goto V_229;
V_862 = F_145 ( V_4 , V_421 , 1 ) ;
if ( V_862 )
goto V_229;
V_25 -> V_1357 [ V_26 ] = V_421 ;
V_25 -> V_1358 [ V_26 ] = V_1354 -> V_1317 ;
V_25 -> V_1359 [ V_26 ] ++ ;
V_1352 = 1 ;
break;
}
}
if ( ! V_1352 ) {
F_476 ( V_4 -> V_11 , L_127 ,
V_25 -> V_375 , V_67 , V_1354 -> V_1317 ) ;
V_862 = - V_21 ;
goto V_229;
}
F_165 ( V_4 , V_87 ) ;
} else {
if ( ! F_469 ( V_1295 -> V_1247 , & V_421 ) ) {
return - V_21 ;
}
}
F_163 ( V_4 , V_87 ) ;
V_386 = F_170 ( V_4 , V_386 ) ;
V_341 = & V_25 -> V_911 [ V_386 ] ;
memset ( V_341 , 0 , sizeof( * V_341 ) ) ;
switch ( V_1295 -> V_1247 ) {
case V_1249 :
case V_1251 :
case V_1253 :
case V_1256 :
case V_1259 :
F_480 ( V_1295 , V_341 , V_1351 , V_421 ) ;
break;
case V_1250 :
case V_1252 :
case V_1254 :
case V_1257 :
case V_1260 :
F_476 ( V_4 -> V_11 , L_128 ,
V_25 -> V_375 , V_67 , V_1295 -> V_1247 ) ;
V_862 = - V_21 ;
goto V_229;
case V_1271 :
F_480 ( V_1295 , V_341 , V_1351 , V_421 ) ;
break;
default:
F_476 ( V_4 -> V_11 , L_129 ,
V_25 -> V_375 , V_67 , V_1295 -> V_1247 ) ;
V_862 = - V_21 ;
goto V_229;
}
if ( V_1295 -> V_1327 == V_1328 ) {
V_341 -> V_410 = V_1326 ;
} else {
if ( V_1295 -> V_1327 >= V_4 -> V_626 ) {
F_476 ( V_4 -> V_11 , L_130 ,
V_25 -> V_375 , V_67 ,
( long long ) V_1295 -> V_1327 ) ;
V_862 = - V_21 ;
goto V_229;
}
V_341 -> V_410 = ( V_914 |
( V_1295 -> V_1327 <<
V_915 ) ) ;
}
V_10 = F_139 ( V_4 , V_386 , V_341 -> V_403 , V_341 -> V_913 ) ;
if ( V_10 ) {
V_862 = - V_21 ;
goto V_229;
}
V_10 = F_140 ( V_4 , V_386 , V_341 -> V_410 ) ;
if ( V_10 ) {
V_862 = - V_21 ;
goto V_229;
}
V_341 -> V_916 = 1 ;
V_4 -> V_478 . V_482 ++ ;
V_229:
F_165 ( V_4 , V_87 ) ;
return V_862 ;
}
static int F_483 ( struct V_3 * V_4 , T_3 V_1360 )
{
struct V_24 * V_25 = V_4 -> V_25 ;
struct V_910 * V_341 ;
T_4 V_386 ;
unsigned long V_87 ;
T_1 V_421 ;
int V_862 = 0 ;
if ( V_1360 >= F_171 ( V_4 ) )
return - V_21 ;
F_163 ( V_4 , V_87 ) ;
V_386 = F_170 ( V_4 , V_1360 ) ;
V_341 = & V_25 -> V_911 [ V_386 ] ;
V_421 = ( V_341 -> V_403 [ 0 ] & V_1324 ) >>
V_1325 ;
if ( V_421 >= V_425 && V_421 <= V_426 ) {
int V_26 ;
for ( V_26 = 0 ; V_26 < V_1356 ; V_26 ++ ) {
if ( V_25 -> V_1357 [ V_26 ] == V_421 ) {
V_25 -> V_1359 [ V_26 ] -- ;
if ( ! V_25 -> V_1359 [ V_26 ] ) {
V_862 = F_145 ( V_4 ,
V_421 ,
0 ) ;
if ( V_862 )
goto V_229;
V_25 -> V_1357 [ V_26 ] = 0 ;
V_25 -> V_1358 [ V_26 ] = 0 ;
}
break;
}
}
if ( V_26 == V_1356 ) {
F_476 ( V_4 -> V_11 , L_131 ,
V_25 -> V_375 , V_67 ,
( unsigned long long ) V_421 ) ;
V_862 = - V_21 ;
goto V_229;
}
}
V_862 = F_138 ( V_4 , V_386 ) ;
if ( V_862 )
goto V_229;
V_341 -> V_916 = 0 ;
V_4 -> V_478 . V_482 -- ;
V_229:
F_165 ( V_4 , V_87 ) ;
return V_862 ;
}
static int F_484 ( struct V_308 * V_11 , struct V_1290 * V_1153 )
{
struct V_3 * V_4 = F_396 ( V_11 ) ;
int V_862 = 0 ;
switch ( V_1153 -> V_1153 ) {
case V_1361 :
V_862 = F_479 ( V_4 , V_1153 ) ;
break;
case V_1362 :
V_862 = F_482 ( V_4 , V_1153 ) ;
break;
case V_1363 :
V_862 = F_483 ( V_4 , V_1153 -> V_1322 . V_1323 ) ;
break;
default:
V_862 = - V_21 ;
break;
}
return V_862 ;
}
static void F_485 ( struct V_308 * V_11 , T_3 V_1364 , T_5 * V_35 )
{
struct V_3 * V_4 = F_396 ( V_11 ) ;
int V_26 ;
if ( V_1364 != V_1365 )
return;
if ( V_4 -> V_87 & V_366 ) {
memcpy ( V_35 , V_1366 ,
sizeof( V_1366 ) ) ;
V_35 += sizeof( V_1366 ) ;
} else {
memcpy ( V_35 , V_1367 ,
sizeof( V_1367 ) ) ;
V_35 += sizeof( V_1367 ) ;
}
for ( V_26 = 0 ; V_26 < V_4 -> V_626 ; V_26 ++ ) {
memcpy ( V_35 , V_1368 ,
sizeof( V_1368 ) ) ;
V_35 += sizeof( V_1368 ) ;
}
for ( V_26 = 0 ; V_26 < V_4 -> V_624 ; V_26 ++ ) {
memcpy ( V_35 , V_1369 ,
sizeof( V_1369 ) ) ;
V_35 += sizeof( V_1369 ) ;
}
}
static int F_486 ( struct V_308 * V_11 , int V_1364 )
{
struct V_3 * V_4 = F_396 ( V_11 ) ;
if ( V_1364 != V_1365 )
return - V_21 ;
return ( V_4 -> V_87 & V_366 ?
V_1370 :
V_1371 ) +
( V_4 -> V_626 * V_1372 ) +
( V_4 -> V_624 * V_1373 ) ;
}
static void F_487 ( struct V_308 * V_11 ,
struct V_1374 * V_1133 , T_1 * V_35 )
{
struct V_3 * V_4 = F_396 ( V_11 ) ;
int V_26 ;
F_408 ( V_4 ) ;
if ( V_4 -> V_87 & V_366 ) {
memcpy ( V_35 , & V_4 -> V_664 . V_665 ,
sizeof( struct V_662 ) ) ;
V_35 += ( sizeof( struct V_662 ) / sizeof( T_1 ) ) ;
} else {
memcpy ( V_35 , & V_4 -> V_664 . V_744 ,
sizeof( struct V_743 ) ) ;
V_35 += ( sizeof( struct V_743 ) / sizeof( T_1 ) ) ;
}
for ( V_26 = 0 ; V_26 < V_4 -> V_626 ; V_26 ++ ) {
struct V_495 * V_496 = & V_4 -> V_627 [ V_26 ] ;
F_219 ( V_4 , V_496 , 0 ) ;
V_35 [ 0 ] = V_496 -> V_523 ;
V_35 [ 1 ] = V_496 -> V_561 ;
V_35 [ 2 ] = V_496 -> V_562 ;
V_35 [ 3 ] = V_496 -> V_526 ;
V_35 [ 4 ] = V_496 -> V_600 ;
V_35 += 5 ;
}
for ( V_26 = 0 ; V_26 < V_4 -> V_624 ; V_26 ++ ) {
struct V_566 * V_496 = & V_4 -> V_589 [ V_26 ] ;
V_35 [ 0 ] = V_496 -> V_625 ;
V_35 [ 1 ] = V_496 -> V_572 ;
V_35 [ 2 ] = V_496 -> V_573 ;
V_35 [ 3 ] = V_496 -> V_1139 ;
V_35 += 4 ;
}
}
static T_1 F_488 ( struct V_3 * V_4 )
{
if ( V_4 -> V_87 & V_366 )
return F_6 ( V_281 ) ;
else
return F_6 ( V_1003 ) ;
}
static void F_489 ( struct V_3 * V_4 , T_1 V_2 )
{
if ( V_4 -> V_87 & V_366 )
F_9 ( V_281 , V_2 ) ;
else
F_9 ( V_1003 , V_2 ) ;
}
static void F_490 ( struct V_3 * V_4 , int V_14 )
{
T_1 V_2 , V_1 , V_397 ;
if ( V_4 -> V_87 & V_366 ) {
V_1 = V_281 ;
V_397 = V_283 ;
} else {
V_1 = V_1003 ;
V_397 = V_1000 ;
}
V_2 = F_6 ( V_1 ) ;
if ( V_14 )
V_2 |= V_397 ;
else
V_2 &= ~ V_397 ;
F_9 ( V_1 , V_2 ) ;
}
static int F_491 ( struct V_308 * V_11 ,
enum V_1375 V_1376 )
{
struct V_3 * V_4 = F_396 ( V_11 ) ;
if ( ! F_413 ( V_11 ) )
return - V_1377 ;
switch ( V_1376 ) {
case V_1378 :
V_4 -> V_1379 = F_488 ( V_4 ) ;
return 1 ;
case V_1380 :
F_490 ( V_4 , 1 ) ;
break;
case V_1381 :
F_490 ( V_4 , 0 ) ;
break;
case V_1382 :
F_489 ( V_4 , V_4 -> V_1379 ) ;
}
return 0 ;
}
static int F_492 ( struct V_3 * V_4 , struct V_24 * V_25 ,
int V_29 , int V_18 )
{
if ( V_29 < V_1383 || V_29 > V_1384 )
return - V_21 ;
if ( V_18 < 0 || V_18 > V_20 )
return - V_21 ;
V_25 -> V_27 [ V_18 ] = V_29 ;
if ( V_4 -> V_25 -> V_339 == V_343 ) {
if ( F_16 ( F_493 ( V_18 ) ) != V_29 ) {
F_221 ( V_4 -> V_511 , L_132 ,
V_4 -> V_30 , V_18 , V_29 ,
( unsigned long long ) F_16 ( F_493 ( V_18 ) ) ) ;
return - V_21 ;
}
} else
F_18 ( F_493 ( V_18 ) , V_29 ) ;
return 0 ;
}
static int F_494 ( struct V_3 * V_4 , int V_1385 )
{
if ( V_1385 < 0 || V_1385 > V_1386 )
return - V_21 ;
F_18 ( V_1387 , V_1385 ) ;
return 0 ;
}
static int F_495 ( struct V_3 * V_4 , int V_29 , int V_1388 , int V_1389 )
{
if ( ( V_29 < V_1383 || V_29 > V_1384 ) ||
( V_1388 < 0 || V_1388 > 3 ) ||
( V_1389 < 0 || V_1389 > 0x1f ) )
return - V_21 ;
F_18 ( F_496 ( V_29 ) , ( V_1388 << V_1390 ) | V_1389 ) ;
return 0 ;
}
static int T_12 F_497 ( struct V_3 * V_4 , T_3 V_362 )
{
T_1 V_1391 , V_1392 = ( V_1393 |
( V_362 << V_1394 ) ) ;
int V_6 ;
if ( V_362 > ( V_1395 >> V_1394 ) )
return - V_21 ;
V_1391 = V_1392 ;
F_18 ( V_1396 , V_1391 ) ;
V_6 = 64 ;
do {
F_7 ( 5 ) ;
V_1391 = F_16 ( V_1396 ) ;
if ( V_1391 & V_1397 )
break;
} while ( V_6 -- );
if ( ! ( V_1391 & V_1397 ) ) {
F_221 ( V_4 -> V_511 , L_133 ,
( unsigned long long ) V_1391 ) ;
return - V_8 ;
}
V_1391 = V_1392 ;
F_18 ( V_1396 , V_1391 ) ;
V_6 = 64 ;
do {
F_7 ( 5 ) ;
V_1391 = F_16 ( V_1396 ) ;
if ( V_1391 & V_1397 )
break;
} while ( V_6 -- );
if ( ! ( V_1391 & V_1397 ) ) {
F_221 ( V_4 -> V_511 , L_133 ,
( unsigned long long ) V_1391 ) ;
return - V_8 ;
}
V_1391 = F_16 ( V_1396 ) ;
return ( V_1391 & V_1398 ) >> V_1399 ;
}
static int T_12 F_498 ( struct V_3 * V_4 , T_3 V_335 )
{
int V_10 = F_497 ( V_4 , V_335 ) ;
T_4 V_2 ;
if ( V_10 < 0 )
return V_10 ;
V_2 = ( V_10 << 8 ) ;
V_10 = F_497 ( V_4 , V_335 + 1 ) ;
if ( V_10 < 0 )
return V_10 ;
V_2 |= ( V_10 & 0xff ) ;
return V_2 ;
}
static int T_12 F_499 ( struct V_3 * V_4 , T_3 V_335 )
{
int V_10 = F_497 ( V_4 , V_335 ) ;
T_4 V_2 ;
if ( V_10 < 0 )
return V_10 ;
V_2 = ( V_10 & 0xff ) ;
V_10 = F_497 ( V_4 , V_335 + 1 ) ;
if ( V_10 < 0 )
return V_10 ;
V_2 |= ( V_10 & 0xff ) << 8 ;
return V_2 ;
}
static int T_12 F_500 ( struct V_3 * V_4 ,
T_3 V_335 ,
char * V_1400 ,
int V_1401 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_1401 ; V_26 ++ ) {
int V_10 = F_497 ( V_4 , V_335 + V_26 ) ;
if ( V_10 < 0 )
return V_10 ;
* V_1400 ++ = V_10 ;
if ( ! V_10 )
break;
}
if ( V_26 >= V_1401 )
return - V_21 ;
return V_26 + 1 ;
}
static void T_12 F_501 ( struct V_3 * V_4 )
{
struct V_1222 * V_1223 = & V_4 -> V_1223 ;
int V_492 = strlen ( V_1223 -> V_1226 ) + 1 ;
const char * V_1402 = V_1223 -> V_1226 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_492 - 5 ; V_26 ++ ) {
if ( ! strncmp ( V_1402 + V_26 , L_134 , 6 ) )
break;
}
if ( V_26 >= V_492 - 5 )
return;
V_1402 += V_26 + 5 ;
sscanf ( V_1402 , L_124 , & V_1223 -> V_1229 , & V_1223 -> V_1230 ) ;
F_164 ( V_4 , V_472 , V_473 , V_4 -> V_11 ,
L_135 ,
V_1223 -> V_1229 , V_1223 -> V_1230 ) ;
if ( V_1223 -> V_1229 > V_1403 ||
( V_1223 -> V_1229 == V_1403 &&
V_1223 -> V_1230 >= V_1404 ) )
V_4 -> V_87 |= V_1405 ;
}
static int T_12 F_502 ( struct V_3 * V_4 ,
T_3 V_1183 , T_3 V_1406 )
{
unsigned int V_1407 = 0 ;
#define F_503 0x00000001
#define F_504 0x00000002
#define F_505 0x00000004
#define F_506 0x00000008
#define F_507 0x00000010
#define F_508 0x00000020
#define F_509 0x0000003f
F_164 ( V_4 , V_472 , V_473 , V_4 -> V_11 ,
L_136 , V_1183 , V_1406 ) ;
while ( V_1183 < V_1406 ) {
int V_492 , V_10 , V_1408 ;
char V_1400 [ 64 ] ;
T_5 * V_1409 ;
int V_1410 ;
if ( V_1407 == F_509 ) {
F_501 ( V_4 ) ;
return 1 ;
}
V_10 = F_497 ( V_4 , V_1183 + 2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_492 = V_10 ;
V_1183 += 3 ;
V_1408 = F_497 ( V_4 , V_1183 + 4 ) ;
V_10 = F_500 ( V_4 , V_1183 + 5 , V_1400 , 64 ) ;
if ( V_10 < 0 )
return V_10 ;
V_1409 = NULL ;
V_1410 = 0 ;
if ( ! strcmp ( V_1400 , L_137 ) ) {
V_1409 = V_4 -> V_1223 . V_1411 ;
V_1410 = V_1412 ;
V_1407 |= F_503 ;
} else if ( ! strcmp ( V_1400 , L_138 ) ) {
V_1409 = V_4 -> V_1223 . V_1413 ;
V_1410 = V_1414 ;
V_1407 |= F_504 ;
} else if ( ! strcmp ( V_1400 , L_139 ) ) {
V_1409 = V_4 -> V_1223 . V_1226 ;
V_1410 = V_1415 ;
V_1407 |= F_505 ;
} else if ( ! strcmp ( V_1400 , L_140 ) ) {
V_1409 = V_4 -> V_1223 . V_1416 ;
V_1410 = V_1148 ;
V_1407 |= F_506 ;
} else if ( ! strcmp ( V_1400 , L_141 ) ) {
V_1409 = & V_4 -> V_1223 . V_1417 ;
V_1410 = 1 ;
V_1407 |= F_507 ;
} else if ( ! strcmp ( V_1400 , L_142 ) ) {
V_1409 = V_4 -> V_1223 . V_1418 ;
V_1410 = V_1419 ;
V_1407 |= F_508 ;
}
if ( V_1410 && V_1408 > V_1410 ) {
F_221 ( V_4 -> V_511 , L_143 , V_1400 , V_1408 ) ;
return - V_21 ;
}
if ( V_1409 ) {
T_3 V_335 = V_1183 + 5 + V_10 ;
int V_26 ;
F_164 ( V_4 , V_472 , V_473 , V_4 -> V_11 ,
L_144 ,
V_1400 , V_1408 ) ;
for ( V_26 = 0 ; V_26 < V_1408 ; V_26 ++ )
* V_1409 ++ = F_497 ( V_4 , V_335 + V_26 ) ;
}
V_1183 += V_492 ;
}
return 0 ;
}
static void T_12 F_510 ( struct V_3 * V_4 , T_3 V_1183 )
{
T_3 V_486 ;
int V_10 ;
V_10 = F_499 ( V_4 , V_1183 + 1 ) ;
if ( V_10 < 0 )
return;
V_486 = V_10 + 3 ;
while ( V_1183 + V_486 < V_1420 ) {
T_3 V_1421 = V_1183 + V_486 ;
T_3 V_1406 ;
V_10 = F_497 ( V_4 , V_1421 ) ;
if ( V_10 != 0x90 )
return;
V_10 = F_499 ( V_4 , V_1421 + 1 ) ;
if ( V_10 < 0 )
return;
V_1421 = V_1183 + V_486 + 3 ;
V_1406 = V_1183 + V_486 + V_10 ;
V_486 += V_10 ;
V_10 = F_502 ( V_4 , V_1421 , V_1406 ) ;
if ( V_10 < 0 || V_10 == 1 )
return;
}
}
static T_3 T_12 F_511 ( struct V_3 * V_4 )
{
T_3 V_1183 = 0 , V_1406 = V_1420 , V_862 ;
int V_10 ;
while ( V_1183 < V_1406 ) {
V_862 = V_1183 ;
V_10 = F_498 ( V_4 , V_1183 + 0 ) ;
if ( V_10 != 0x55aa )
return 0 ;
V_10 = F_498 ( V_4 , V_1183 + 23 ) ;
if ( V_10 < 0 )
return 0 ;
V_1183 += V_10 ;
V_10 = F_498 ( V_4 , V_1183 + 0 ) ;
if ( V_10 != 0x5043 )
return 0 ;
V_10 = F_498 ( V_4 , V_1183 + 2 ) ;
if ( V_10 != 0x4952 )
return 0 ;
V_10 = F_497 ( V_4 , V_1183 + 20 ) ;
if ( V_10 < 0 )
return 0 ;
if ( V_10 != 0x01 ) {
V_10 = F_497 ( V_4 , V_862 + 2 ) ;
if ( V_10 < 0 )
return 0 ;
V_1183 = V_862 + ( V_10 * 512 ) ;
continue;
}
V_10 = F_499 ( V_4 , V_1183 + 8 ) ;
if ( V_10 < 0 )
return V_10 ;
V_862 += V_10 ;
V_10 = F_497 ( V_4 , V_862 + 0 ) ;
if ( V_10 != 0x82 )
return 0 ;
return V_862 ;
}
return 0 ;
}
static int T_12 F_512 ( struct V_3 * V_4 ,
const char * V_1422 )
{
if ( ! strcmp ( V_1422 , L_145 ) ) {
V_4 -> V_87 &= ~ ( V_344 |
V_88 ) ;
V_4 -> V_89 = V_1423 ;
} else if ( ! strcmp ( V_1422 , L_146 ) ) {
V_4 -> V_87 |= ( V_88 |
V_344 ) ;
V_4 -> V_89 = V_1424 ;
} else if ( ! strcmp ( V_1422 , L_147 ) ) {
V_4 -> V_87 &= ~ V_88 ;
V_4 -> V_87 |= V_344 ;
V_4 -> V_89 = V_90 ;
} else if ( ! strcmp ( V_1422 , L_148 ) ) {
V_4 -> V_87 |= V_88 ;
V_4 -> V_87 &= ~ V_344 ;
V_4 -> V_89 = V_1424 ;
} else if ( ! strcmp ( V_1422 , L_149 ) || ! strcmp ( V_1422 , L_150 ) ) {
V_4 -> V_87 |= V_88 ;
V_4 -> V_87 &= ~ V_344 ;
V_4 -> V_87 |= V_345 ;
V_4 -> V_89 = V_1424 ;
} else {
return - V_21 ;
}
return 0 ;
}
static int F_513 ( struct V_3 * V_4 )
{
int V_1425 = 0 ;
if ( ( ! strcmp ( V_4 -> V_1223 . V_1411 , V_1426 ) ) ||
( ! strcmp ( V_4 -> V_1223 . V_1411 , V_1427 ) ) ||
( ! strcmp ( V_4 -> V_1223 . V_1411 , V_1428 ) ) ||
( ! strcmp ( V_4 -> V_1223 . V_1411 , V_1429 ) ) ||
( ! strcmp ( V_4 -> V_1223 . V_1411 , V_1430 ) ) ) {
V_1425 = 4 ;
} else if ( ( ! strcmp ( V_4 -> V_1223 . V_1411 , V_1431 ) ) ||
( ! strcmp ( V_4 -> V_1223 . V_1411 , V_1432 ) ) ||
( ! strcmp ( V_4 -> V_1223 . V_1411 , V_1433 ) ) ||
( ! strcmp ( V_4 -> V_1223 . V_1411 , V_1434 ) ) ) {
V_1425 = 2 ;
}
return V_1425 ;
}
static void T_12 F_514 ( struct V_3 * V_4 )
{
struct V_308 * V_11 = V_4 -> V_11 ;
struct V_1222 * V_1223 = & V_4 -> V_1223 ;
T_5 V_1435 ;
if ( ! F_425 ( & V_1223 -> V_1416 [ 0 ] ) ) {
F_221 ( V_4 -> V_511 , L_151 ) ;
V_4 -> V_87 &= ~ V_1405 ;
return;
}
if ( ! strcmp ( V_4 -> V_1223 . V_1411 , V_1430 ) ||
! strcmp ( V_4 -> V_1223 . V_1411 , V_1429 ) ) {
V_4 -> V_87 |= V_88 ;
V_4 -> V_87 &= ~ V_344 ;
V_4 -> V_87 |= V_345 ;
V_4 -> V_89 = V_90 ;
if ( V_4 -> V_30 > 1 ) {
V_4 -> V_87 |= V_344 ;
V_4 -> V_87 &= ~ V_88 ;
}
if ( V_4 -> V_87 & V_88 )
V_4 -> V_89 = V_1424 ;
} else if ( ! strcmp ( V_4 -> V_1223 . V_1411 , V_1433 ) ) {
V_4 -> V_87 |= ( V_88 | V_344 |
V_134 ) ;
} else if ( F_512 ( V_4 , V_4 -> V_1223 . V_1418 ) ) {
F_221 ( V_4 -> V_511 , L_152 ,
V_4 -> V_1223 . V_1418 ) ;
F_221 ( V_4 -> V_511 , L_153 ) ;
V_4 -> V_87 &= ~ V_1405 ;
return;
}
memcpy ( V_11 -> V_1436 , V_1223 -> V_1416 , V_1148 ) ;
V_1435 = V_11 -> V_1436 [ 5 ] ;
V_11 -> V_1436 [ 5 ] += V_4 -> V_30 ;
if ( V_11 -> V_1436 [ 5 ] < V_1435 )
V_11 -> V_1436 [ 4 ] ++ ;
memcpy ( V_11 -> V_1106 , V_11 -> V_1436 , V_11 -> V_1437 ) ;
}
static int T_12 F_515 ( struct V_3 * V_4 )
{
struct V_308 * V_11 = V_4 -> V_11 ;
int V_492 , V_26 ;
T_1 V_2 , V_1438 ;
T_5 V_1435 ;
V_2 = ( F_16 ( V_1439 ) & V_1440 ) ;
V_2 >>= V_1441 ;
V_492 = V_2 / 4 ;
V_4 -> V_1242 = V_492 ;
F_164 ( V_4 , V_472 , V_473 , V_4 -> V_11 ,
L_154 , ( unsigned long long ) V_2 ) ;
V_1438 = 0 ;
for ( V_26 = 0 ; V_26 < V_492 ; V_26 ++ ) {
V_2 = F_16 ( F_466 ( V_26 ) ) ;
V_1438 += ( V_2 >> 0 ) & 0xff ;
V_1438 += ( V_2 >> 8 ) & 0xff ;
V_1438 += ( V_2 >> 16 ) & 0xff ;
V_1438 += ( V_2 >> 24 ) & 0xff ;
}
F_164 ( V_4 , V_472 , V_473 , V_4 -> V_11 ,
L_155 , ( int ) ( V_1438 & 0xff ) ) ;
if ( ( V_1438 & 0xff ) != 0xab ) {
F_221 ( V_4 -> V_511 , L_156 , ( int ) ( V_1438 & 0xff ) ) ;
return - V_21 ;
}
V_2 = F_16 ( V_1442 ) ;
switch ( V_4 -> V_30 ) {
case 0 :
V_1435 = ( V_2 & V_1443 ) >>
V_1444 ;
break;
case 1 :
V_1435 = ( V_2 & V_1445 ) >>
V_1446 ;
break;
case 2 :
V_1435 = ( V_2 & V_1447 ) >>
V_1448 ;
break;
case 3 :
V_1435 = ( V_2 & V_1449 ) >>
V_1450 ;
break;
default:
F_221 ( V_4 -> V_511 , L_157 ,
V_4 -> V_30 ) ;
return - V_21 ;
}
F_164 ( V_4 , V_472 , V_473 , V_4 -> V_11 ,
L_158 , V_1435 ) ;
switch ( V_1435 ) {
case V_1451 :
V_4 -> V_87 &= ~ ( V_344 |
V_88 ) ;
V_4 -> V_89 = V_1423 ;
break;
case V_1452 :
V_4 -> V_87 &= ~ V_88 ;
V_4 -> V_87 |= V_344 ;
V_4 -> V_89 = V_90 ;
break;
case V_1453 :
V_4 -> V_87 |= V_88 ;
V_4 -> V_87 &= ~ V_344 ;
V_4 -> V_89 = V_1424 ;
break;
case V_1454 :
V_4 -> V_87 |= ( V_88 |
V_344 ) ;
V_4 -> V_89 = V_1424 ;
break;
default:
F_221 ( V_4 -> V_511 , L_159 , V_1435 ) ;
return - V_21 ;
}
V_2 = F_16 ( V_1455 ) ;
F_164 ( V_4 , V_472 , V_473 , V_4 -> V_11 ,
L_160 , ( unsigned long long ) V_2 ) ;
V_11 -> V_1436 [ 0 ] = ( V_2 >> 0 ) & 0xff ;
V_11 -> V_1436 [ 1 ] = ( V_2 >> 8 ) & 0xff ;
V_11 -> V_1436 [ 2 ] = ( V_2 >> 16 ) & 0xff ;
V_11 -> V_1436 [ 3 ] = ( V_2 >> 24 ) & 0xff ;
V_2 = F_16 ( V_1456 ) ;
F_164 ( V_4 , V_472 , V_473 , V_4 -> V_11 ,
L_161 , ( unsigned long long ) V_2 ) ;
V_11 -> V_1436 [ 4 ] = ( V_2 >> 0 ) & 0xff ;
V_11 -> V_1436 [ 5 ] = ( V_2 >> 8 ) & 0xff ;
if ( ! F_425 ( & V_11 -> V_1436 [ 0 ] ) ) {
F_221 ( V_4 -> V_511 , L_162 ,
V_11 -> V_1436 ) ;
return - V_21 ;
}
V_1435 = V_11 -> V_1436 [ 5 ] ;
V_11 -> V_1436 [ 5 ] += V_4 -> V_30 ;
if ( V_11 -> V_1436 [ 5 ] < V_1435 )
V_11 -> V_1436 [ 4 ] ++ ;
memcpy ( V_11 -> V_1106 , V_11 -> V_1436 , V_11 -> V_1437 ) ;
V_2 = F_16 ( V_1457 ) ;
F_164 ( V_4 , V_472 , V_473 , V_4 -> V_11 ,
L_163 , ( unsigned long long ) V_2 ) ;
if ( V_2 >= 8 * 4 )
return - V_21 ;
for ( V_26 = 0 ; V_26 < V_2 ; V_26 += 4 ) {
T_1 V_586 = F_16 ( F_466 ( 5 + ( V_26 / 4 ) ) ) ;
V_4 -> V_1223 . V_1411 [ V_26 + 3 ] = ( V_586 >> 0 ) & 0xff ;
V_4 -> V_1223 . V_1411 [ V_26 + 2 ] = ( V_586 >> 8 ) & 0xff ;
V_4 -> V_1223 . V_1411 [ V_26 + 1 ] = ( V_586 >> 16 ) & 0xff ;
V_4 -> V_1223 . V_1411 [ V_26 + 0 ] = ( V_586 >> 24 ) & 0xff ;
}
V_4 -> V_1223 . V_1411 [ V_2 ] = '\0' ;
V_2 = F_16 ( V_1458 ) ;
F_164 ( V_4 , V_472 , V_473 , V_4 -> V_11 ,
L_164 , ( unsigned long long ) V_2 ) ;
if ( V_2 >= 4 * 4 )
return - V_21 ;
for ( V_26 = 0 ; V_26 < V_2 ; V_26 += 4 ) {
T_1 V_586 = F_16 ( F_466 ( 14 + ( V_26 / 4 ) ) ) ;
V_4 -> V_1223 . V_1413 [ V_26 + 3 ] = ( V_586 >> 0 ) & 0xff ;
V_4 -> V_1223 . V_1413 [ V_26 + 2 ] = ( V_586 >> 8 ) & 0xff ;
V_4 -> V_1223 . V_1413 [ V_26 + 1 ] = ( V_586 >> 16 ) & 0xff ;
V_4 -> V_1223 . V_1413 [ V_26 + 0 ] = ( V_586 >> 24 ) & 0xff ;
}
V_4 -> V_1223 . V_1413 [ V_2 ] = '\0' ;
V_4 -> V_1223 . V_1417 =
F_16 ( V_1459 ) & V_1460 ;
F_164 ( V_4 , V_472 , V_473 , V_4 -> V_11 ,
L_165 , V_4 -> V_1223 . V_1417 ) ;
return 0 ;
}
static int T_12 F_516 ( struct V_3 * V_4 )
{
struct V_24 * V_25 = V_4 -> V_25 ;
if ( V_4 -> V_30 <= 1 )
V_4 -> V_87 |= V_366 ;
if ( ! V_25 -> V_481 ) {
if ( V_25 -> V_339 == V_343 ) {
V_25 -> V_481 = 2 ;
} else {
V_25 -> V_481 = F_513 ( V_4 ) ;
if ( ! V_25 -> V_481 ) {
V_25 -> V_481 = F_16 ( V_1459 ) &
V_1460 ;
if ( ! V_25 -> V_481 )
V_25 -> V_481 = 4 ;
}
}
}
if ( V_4 -> V_30 >= V_25 -> V_481 )
return - V_8 ;
return 0 ;
}
static int T_12 F_517 ( struct V_24 * V_25 ,
struct V_288 * V_501 ,
int V_1461 , int V_1462 , T_5 V_1463 ,
int type )
{
T_3 V_1464 = ( V_1461 << 16 ) | V_1462 ;
T_5 V_386 ;
if ( V_1461 < 0 || V_1462 < 0 )
return 0 ;
if ( type == V_1465 || type == V_1466 ) {
if ( ( ( V_1464 & V_289 ) != V_1467 ) &&
( ( V_1464 & V_289 ) != V_290 ) &&
( ( V_1464 & V_289 ) != V_1468 ) )
return 0 ;
} else {
if ( ( V_1464 & V_289 ) != V_1469 )
return 0 ;
}
F_48 ( L_166 ,
V_25 -> V_375 , V_1464 ,
type == V_1465 ? L_167 :
type == V_1466 ? L_168 : L_169 ,
V_1463 ) ;
if ( V_501 -> V_1470 [ type ] >= V_1471 ) {
F_518 ( L_170 ) ;
return - V_21 ;
}
V_386 = V_501 -> V_1470 [ type ] ;
V_501 -> V_286 [ type ] [ V_386 ] = V_1464 ;
V_501 -> V_1463 [ type ] [ V_386 ] = V_1463 ;
V_501 -> V_1470 [ type ] = V_386 + 1 ;
return 0 ;
}
static int T_12 F_519 ( struct V_288 * V_501 , int V_30 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_501 -> V_1470 [ V_1465 ] ; V_26 ++ ) {
if ( V_501 -> V_1463 [ V_1465 ] [ V_26 ] == V_30 )
return 1 ;
}
for ( V_26 = 0 ; V_26 < V_501 -> V_1470 [ V_1466 ] ; V_26 ++ ) {
if ( V_501 -> V_1463 [ V_1466 ] [ V_26 ] == V_30 )
return 1 ;
}
return 0 ;
}
static int T_12 F_520 ( struct V_288 * V_501 , int * V_1472 )
{
int V_30 , V_1331 ;
V_1331 = 0 ;
* V_1472 = 32 ;
for ( V_30 = 8 ; V_30 < 32 ; V_30 ++ ) {
if ( F_519 ( V_501 , V_30 ) ) {
if ( ! V_1331 )
* V_1472 = V_30 ;
V_1331 ++ ;
}
}
return V_1331 ;
}
static int T_12 F_521 ( struct V_288 * V_501 , int * V_1472 )
{
* V_1472 = 32 ;
if ( V_501 -> V_1470 [ V_1473 ] )
* V_1472 = V_501 -> V_1463 [ V_1473 ] [ 0 ] ;
return V_501 -> V_1470 [ V_1473 ] ;
}
static void T_12 F_522 ( struct V_24 * V_25 )
{
int V_481 = V_25 -> V_481 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_481 ; V_26 ++ ) {
V_25 -> V_811 [ V_26 ] = ( 16 / V_481 ) ;
V_25 -> V_812 [ V_26 ] = ( 16 / V_481 ) ;
F_48 ( L_171 ,
V_25 -> V_375 , V_26 ,
V_25 -> V_811 [ V_26 ] ,
V_25 -> V_812 [ V_26 ] ) ;
}
}
static void T_12 F_523 ( struct V_24 * V_25 ,
int V_1474 , int V_1475 )
{
int V_481 = V_25 -> V_481 ;
int V_1476 , V_1477 ;
int V_1478 , V_1479 ;
int V_26 , V_1480 , V_1481 ;
if ( ! V_1474 || ! V_1475 ) {
V_1476 = V_1477 =
( V_1482 / V_481 ) ;
V_1478 = V_1479 =
( V_1483 / V_481 ) ;
} else {
V_1477 = V_1482 / 8 ;
V_1476 = ( V_1482 -
( V_1477 * V_1475 ) ) /
V_1474 ;
V_1479 = V_1483 / 6 ;
V_1478 = ( V_1483 -
( V_1479 * V_1475 ) ) /
V_1474 ;
}
V_1480 = V_1481 = 0 ;
for ( V_26 = 0 ; V_26 < V_481 ; V_26 ++ ) {
int type = F_27 ( V_25 -> V_287 , V_26 ) ;
if ( type == V_848 ) {
V_25 -> V_811 [ V_26 ] = V_1476 ;
V_25 -> V_812 [ V_26 ] = V_1478 ;
} else {
V_25 -> V_811 [ V_26 ] = V_1477 ;
V_25 -> V_812 [ V_26 ] = V_1479 ;
}
F_48 ( L_171 ,
V_25 -> V_375 , V_26 ,
V_25 -> V_811 [ V_26 ] ,
V_25 -> V_812 [ V_26 ] ) ;
V_1480 += V_25 -> V_811 [ V_26 ] ;
V_1481 += V_25 -> V_812 [ V_26 ] ;
}
if ( V_1480 > V_1482 ) {
F_518 ( L_172 ,
V_25 -> V_375 , V_1480 ) ;
for ( V_26 = 0 ; V_26 < V_481 ; V_26 ++ )
V_25 -> V_811 [ V_26 ] = 1 ;
}
if ( V_1481 > V_1483 ) {
F_518 ( L_173 ,
V_25 -> V_375 , V_1481 ) ;
for ( V_26 = 0 ; V_26 < V_481 ; V_26 ++ )
V_25 -> V_812 [ V_26 ] = 1 ;
}
if ( V_1480 < V_1482 || V_1481 < V_1483 ) {
F_524 ( L_174 ,
V_25 -> V_375 , V_1480 , V_1481 ) ;
}
}
static void T_12 F_525 ( struct V_24 * V_25 ,
int V_1474 , int V_1475 )
{
int V_26 , V_481 = V_25 -> V_481 ;
int V_1484 , V_1485 ;
int V_1486 ;
V_1484 = 0 ;
V_1485 = V_1487 / V_481 ;
V_1486 = 0 ;
for ( V_26 = 0 ; V_26 < V_481 ; V_26 ++ ) {
struct V_837 * V_341 = & V_25 -> V_838 [ V_26 ] ;
int V_1488 , V_1489 = V_25 -> V_811 [ V_26 ] ;
int V_1490 ;
V_341 -> V_839 = V_1484 ;
V_341 -> V_840 = V_1485 ;
V_1490 = 0 ;
for ( V_1488 = 0 ; V_1488 < V_341 -> V_840 ; V_1488 ++ ) {
struct V_393 * V_1491 = & V_341 -> V_842 [ V_1488 ] ;
int V_844 ;
F_48 ( L_175 ,
V_25 -> V_375 , V_26 , V_341 -> V_839 + V_1488 ) ;
for ( V_844 = 0 ; V_844 < V_845 ; V_844 ++ ) {
V_1491 -> V_846 [ V_844 ] =
V_1486 + V_1490 ;
F_234 ( L_176 , V_1491 -> V_846 [ V_844 ] ) ;
if ( ++ V_1490 == V_1489 )
V_1490 = 0 ;
}
F_234 ( L_177 ) ;
}
V_25 -> V_847 [ V_26 ] = V_1486 ;
V_1486 += V_1489 ;
V_1484 += V_1485 ;
}
}
static int T_12 F_526 ( struct V_3 * V_4 ,
struct V_24 * V_25 ,
struct V_288 * V_1221 )
{
unsigned long V_87 ;
int V_30 , V_10 ;
memset ( V_1221 , 0 , sizeof( * V_1221 ) ) ;
F_163 ( V_4 , V_87 ) ;
V_10 = 0 ;
for ( V_30 = 8 ; V_30 < 32 ; V_30 ++ ) {
int V_1461 , V_1462 ;
V_1461 = F_29 ( V_4 , V_30 ,
V_1492 , V_1493 ) ;
V_1462 = F_29 ( V_4 , V_30 ,
V_1492 , V_1494 ) ;
V_10 = F_517 ( V_25 , V_1221 , V_1461 , V_1462 , V_30 ,
V_1465 ) ;
if ( V_10 )
break;
V_1461 = F_29 ( V_4 , V_30 ,
V_1495 , V_1493 ) ;
V_1462 = F_29 ( V_4 , V_30 ,
V_1495 , V_1494 ) ;
V_10 = F_517 ( V_25 , V_1221 , V_1461 , V_1462 , V_30 ,
V_1466 ) ;
if ( V_10 )
break;
V_1461 = F_34 ( V_4 , V_30 , V_1493 ) ;
V_1462 = F_34 ( V_4 , V_30 , V_1494 ) ;
V_10 = F_517 ( V_25 , V_1221 , V_1461 , V_1462 , V_30 ,
V_1473 ) ;
if ( V_10 )
break;
}
F_165 ( V_4 , V_87 ) ;
return V_10 ;
}
static int T_12 F_527 ( struct V_3 * V_4 , struct V_24 * V_25 )
{
struct V_288 * V_1221 = & V_25 -> V_288 ;
int V_1496 , V_1497 ;
int V_1474 , V_1475 ;
T_3 V_2 ;
int V_10 ;
V_1474 = V_1475 = 0 ;
if ( ! strcmp ( V_4 -> V_1223 . V_1411 , V_1430 ) ||
! strcmp ( V_4 -> V_1223 . V_1411 , V_1429 ) ) {
V_1474 = 0 ;
V_1475 = 2 ;
V_25 -> V_339 = V_1498 ;
V_25 -> V_481 = 4 ;
V_2 = ( F_26 ( V_850 , 0 ) |
F_26 ( V_850 , 1 ) |
F_26 ( V_850 , 2 ) |
F_26 ( V_850 , 3 ) ) ;
} else if ( ! strcmp ( V_4 -> V_1223 . V_1411 , V_1433 ) ) {
V_1474 = 2 ;
V_1475 = 0 ;
V_25 -> V_481 = 2 ;
V_2 = ( F_26 ( V_848 , 0 ) |
F_26 ( V_848 , 1 ) ) ;
} else if ( ( V_4 -> V_87 & V_345 ) &&
( V_25 -> V_339 == V_343 ) ) {
if ( V_4 -> V_87 & V_88 ) {
V_2 = ( F_26 ( V_848 , 0 ) |
F_26 ( V_848 , 1 ) ) ;
} else {
V_2 = ( F_26 ( V_850 , 0 ) |
F_26 ( V_850 , 1 ) ) ;
}
} else {
V_10 = F_526 ( V_4 , V_25 , V_1221 ) ;
if ( V_10 )
return V_10 ;
V_1474 = F_520 ( V_1221 , & V_1496 ) ;
V_1475 = F_521 ( V_1221 , & V_1497 ) ;
switch ( ( V_1474 << 4 ) | V_1475 ) {
case 0x24 :
if ( V_1497 == 10 )
V_25 -> V_339 = V_351 ;
else if ( V_1497 == 26 )
V_25 -> V_339 = V_352 ;
else
goto V_1499;
case 0x22 :
V_2 = ( F_26 ( V_848 , 0 ) |
F_26 ( V_848 , 1 ) |
F_26 ( V_850 , 2 ) |
F_26 ( V_850 , 3 ) ) ;
break;
case 0x20 :
V_2 = ( F_26 ( V_848 , 0 ) |
F_26 ( V_848 , 1 ) ) ;
break;
case 0x10 :
V_2 = F_26 ( V_848 , V_4 -> V_30 ) ;
break;
case 0x14 :
if ( V_1497 == 10 )
V_25 -> V_339 = V_351 ;
else if ( V_1497 == 26 )
V_25 -> V_339 = V_352 ;
else
goto V_1499;
case 0x13 :
if ( ( V_1496 & 0x7 ) == 0 )
V_2 = ( F_26 ( V_848 , 0 ) |
F_26 ( V_850 , 1 ) |
F_26 ( V_850 , 2 ) |
F_26 ( V_850 , 3 ) ) ;
else
V_2 = ( F_26 ( V_850 , 0 ) |
F_26 ( V_848 , 1 ) |
F_26 ( V_850 , 2 ) |
F_26 ( V_850 , 3 ) ) ;
break;
case 0x04 :
if ( V_1497 == 10 )
V_25 -> V_339 = V_351 ;
else if ( V_1497 == 26 )
V_25 -> V_339 = V_352 ;
else
goto V_1499;
V_2 = ( F_26 ( V_850 , 0 ) |
F_26 ( V_850 , 1 ) |
F_26 ( V_850 , 2 ) |
F_26 ( V_850 , 3 ) ) ;
break;
default:
F_518 ( L_178 ,
V_1474 , V_1475 ) ;
return - V_21 ;
}
}
V_25 -> V_287 = V_2 ;
if ( V_25 -> V_339 == V_343 )
F_522 ( V_25 ) ;
else
F_523 ( V_25 , V_1474 , V_1475 ) ;
F_525 ( V_25 , V_1474 , V_1475 ) ;
return 0 ;
V_1499:
F_518 ( L_179 , V_1497 ) ;
return - V_21 ;
}
static int T_12 F_528 ( struct V_3 * V_4 )
{
struct V_24 * V_25 = V_4 -> V_25 ;
int V_10 , V_26 ;
if ( V_25 -> V_287 == V_1500 ) {
V_10 = F_527 ( V_4 , V_25 ) ;
if ( V_10 )
return V_10 ;
F_494 ( V_4 , 2 ) ;
for ( V_26 = 0 ; V_26 <= V_20 ; V_26 ++ )
F_21 ( V_4 , V_26 , 0 ) ;
}
if ( V_25 -> V_287 == V_1501 )
return - V_21 ;
return 0 ;
}
static int T_12 F_529 ( struct V_3 * V_4 )
{
struct V_908 * V_909 = & V_4 -> V_478 ;
V_909 -> V_480 = ( T_4 ) V_4 -> V_30 ;
V_909 -> V_479 = V_4 -> V_25 -> V_441 / V_4 -> V_25 -> V_481 ;
V_909 -> V_917 = 0xffffffff ;
V_909 -> V_918 = 0xffff ;
return F_162 ( V_4 ) ;
}
static void T_12 F_530 ( struct V_3 * V_4 )
{
struct V_38 * V_13 = & V_4 -> V_39 ;
V_13 -> V_174 = ( V_199 |
V_201 |
V_203 |
V_205 |
V_207 |
V_209 |
V_1502 |
V_214 ) ;
V_13 -> V_302 = V_13 -> V_160 = V_153 ;
V_13 -> V_301 = V_159 ;
V_13 -> V_161 = V_154 ;
V_13 -> V_296 = 1 ;
#if 0
lp->loopback_mode = LOOPBACK_MAC;
lp->active_speed = SPEED_10000;
lp->active_duplex = DUPLEX_FULL;
#else
V_13 -> V_49 = V_330 ;
#endif
}
static int T_12 F_531 ( struct V_3 * V_4 )
{
switch ( V_4 -> V_30 ) {
case 0 :
V_4 -> V_1503 = V_4 -> V_1504 + V_1505 ;
V_4 -> V_1506 = 0x00000 ;
V_4 -> V_1507 = 0x04000 ;
V_4 -> V_1508 = 0x02000 ;
break;
case 1 :
V_4 -> V_1503 = V_4 -> V_1504 + V_1509 ;
V_4 -> V_1506 = 0x08000 ;
V_4 -> V_1507 = 0x0a000 ;
V_4 -> V_1508 = 0x08000 ;
break;
case 2 :
V_4 -> V_1503 = V_4 -> V_1504 + V_1510 ;
V_4 -> V_1506 = 0x04000 ;
V_4 -> V_1507 = 0x0e000 ;
V_4 -> V_1508 = ~ 0UL ;
break;
case 3 :
V_4 -> V_1503 = V_4 -> V_1504 + V_1511 ;
V_4 -> V_1506 = 0x0c000 ;
V_4 -> V_1507 = 0x12000 ;
V_4 -> V_1508 = ~ 0UL ;
break;
default:
F_221 ( V_4 -> V_511 , L_180 , V_4 -> V_30 ) ;
return - V_21 ;
}
return 0 ;
}
static void T_12 F_532 ( struct V_3 * V_4 , T_5 * V_1512 )
{
struct V_1513 V_1514 [ V_1515 ] ;
struct V_24 * V_25 = V_4 -> V_25 ;
struct V_1516 * V_1232 = V_4 -> V_1232 ;
int V_26 , V_1517 , V_10 ;
T_5 V_1518 ;
V_1518 = ( V_1515 / V_25 -> V_481 ) * V_4 -> V_30 ;
for ( V_26 = 0 ; V_26 < ( V_1515 / V_25 -> V_481 ) ; V_26 ++ )
V_1512 [ V_26 ] = V_1518 + V_26 ;
V_1517 = ( V_25 -> V_811 [ V_4 -> V_30 ] +
V_25 -> V_812 [ V_4 -> V_30 ] +
( V_4 -> V_30 == 0 ? 3 : 1 ) ) ;
F_186 ( V_1517 > ( V_1515 / V_25 -> V_481 ) ) ;
V_1519:
for ( V_26 = 0 ; V_26 < V_1517 ; V_26 ++ ) {
V_1514 [ V_26 ] . V_1389 = 0 ;
V_1514 [ V_26 ] . V_1520 = V_26 ;
}
V_10 = F_533 ( V_1232 , V_1514 , V_1517 ) ;
if ( V_10 < 0 ) {
V_4 -> V_87 &= ~ V_1521 ;
return;
}
if ( V_10 > 0 ) {
V_1517 = V_10 ;
goto V_1519;
}
V_4 -> V_87 |= V_1521 ;
for ( V_26 = 0 ; V_26 < V_1517 ; V_26 ++ )
V_4 -> V_29 [ V_26 ] . V_784 = V_1514 [ V_26 ] . V_1389 ;
V_4 -> V_28 = V_1517 ;
}
static int T_12 F_534 ( struct V_3 * V_4 , T_5 * V_1512 )
{
#ifdef F_535
struct V_1522 * V_1523 = V_4 -> V_1523 ;
const T_3 * V_1524 ;
int V_26 ;
V_1524 = F_536 ( V_1523 -> V_11 . V_1525 , L_181 , NULL ) ;
if ( ! V_1524 )
return - V_8 ;
for ( V_26 = 0 ; V_26 < V_1523 -> V_1526 . V_1517 ; V_26 ++ ) {
V_1512 [ V_26 ] = V_1524 [ V_26 ] ;
V_4 -> V_29 [ V_26 ] . V_784 = V_1523 -> V_1526 . V_1527 [ V_26 ] ;
}
V_4 -> V_28 = V_1523 -> V_1526 . V_1517 ;
return 0 ;
#else
return - V_21 ;
#endif
}
static int T_12 F_537 ( struct V_3 * V_4 )
{
struct V_24 * V_25 = V_4 -> V_25 ;
T_5 V_1512 [ V_1515 ] ;
int V_1528 , V_1529 ;
int V_26 , V_10 , V_1530 ;
T_5 V_30 ;
V_4 -> V_28 = 1 ;
V_4 -> V_29 [ 0 ] . V_784 = V_4 -> V_11 -> V_784 ;
if ( V_25 -> V_339 == V_343 ) {
V_10 = F_534 ( V_4 , V_1512 ) ;
if ( V_10 )
return V_10 ;
} else
F_532 ( V_4 , V_1512 ) ;
V_30 = V_4 -> V_30 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_28 ; V_26 ++ ) {
struct V_12 * V_13 = & V_4 -> V_29 [ V_26 ] ;
F_538 ( V_4 -> V_11 , & V_13 -> V_538 , F_230 , 64 ) ;
V_13 -> V_4 = V_4 ;
V_13 -> V_17 = V_1512 [ V_26 ] ;
V_13 -> V_15 = 2 ;
if ( V_4 -> V_25 -> V_339 != V_343 ) {
V_10 = F_495 ( V_4 , V_13 -> V_17 , V_30 , V_26 ) ;
if ( V_10 )
return V_10 ;
}
}
V_1530 = 0 ;
V_10 = F_492 ( V_4 , V_25 , V_1512 [ V_1530 ] ,
F_539 ( V_30 ) ) ;
if ( V_10 )
return V_10 ;
V_1530 ++ ;
if ( V_1530 == V_4 -> V_28 )
V_1530 = 0 ;
if ( V_30 == 0 ) {
V_10 = F_492 ( V_4 , V_25 ,
V_1512 [ V_1530 ] ,
V_787 ) ;
if ( V_10 )
return V_10 ;
V_1530 ++ ;
if ( V_1530 == V_4 -> V_28 )
V_1530 = 0 ;
V_10 = F_492 ( V_4 , V_25 ,
V_1512 [ V_1530 ] ,
V_1531 ) ;
if ( V_10 )
return V_10 ;
V_1530 ++ ;
if ( V_1530 == V_4 -> V_28 )
V_1530 = 0 ;
}
V_1528 = 0 ;
for ( V_26 = 0 ; V_26 < V_30 ; V_26 ++ )
V_1528 += V_25 -> V_811 [ V_26 ] ;
V_1529 = V_25 -> V_811 [ V_30 ] ;
for ( V_26 = V_1528 ; V_26 < ( V_1528 + V_1529 ) ; V_26 ++ ) {
V_10 = F_492 ( V_4 , V_25 ,
V_1512 [ V_1530 ] ,
F_229 ( V_26 ) ) ;
if ( V_10 )
return V_10 ;
V_1530 ++ ;
if ( V_1530 == V_4 -> V_28 )
V_1530 = 0 ;
}
V_1528 = 0 ;
for ( V_26 = 0 ; V_26 < V_30 ; V_26 ++ )
V_1528 += V_25 -> V_812 [ V_26 ] ;
V_1529 = V_25 -> V_812 [ V_30 ] ;
for ( V_26 = V_1528 ; V_26 < ( V_1528 + V_1529 ) ; V_26 ++ ) {
V_10 = F_492 ( V_4 , V_25 ,
V_1512 [ V_1530 ] ,
F_228 ( V_26 ) ) ;
if ( V_10 )
return V_10 ;
V_1530 ++ ;
if ( V_1530 == V_4 -> V_28 )
V_1530 = 0 ;
}
return 0 ;
}
static void T_13 F_540 ( struct V_3 * V_4 )
{
if ( V_4 -> V_87 & V_1521 )
F_541 ( V_4 -> V_1232 ) ;
}
static int T_12 F_542 ( struct V_3 * V_4 )
{
#ifdef F_535
struct V_308 * V_11 = V_4 -> V_11 ;
struct V_1532 * V_1533 ;
const char * V_1418 ;
const T_5 * V_1534 ;
const char * V_1411 ;
int V_1408 ;
if ( V_4 -> V_25 -> V_339 == V_343 )
V_1533 = V_4 -> V_1523 -> V_11 . V_1525 ;
else
V_1533 = F_543 ( V_4 -> V_1232 ) ;
V_1418 = F_536 ( V_1533 , L_142 , & V_1408 ) ;
if ( ! V_1418 ) {
F_10 ( V_11 , L_182 ,
V_1533 -> V_1535 ) ;
return - V_21 ;
}
if ( ! strcmp ( V_1418 , L_183 ) )
return - V_8 ;
strcpy ( V_4 -> V_1223 . V_1418 , V_1418 ) ;
if ( F_512 ( V_4 , V_4 -> V_1223 . V_1418 ) ) {
F_10 ( V_11 , L_184 ,
V_1533 -> V_1535 , V_4 -> V_1223 . V_1418 ) ;
return - V_21 ;
}
V_1534 = F_536 ( V_1533 , L_140 , & V_1408 ) ;
if ( ! V_1534 ) {
F_10 ( V_11 , L_185 ,
V_1533 -> V_1535 ) ;
return - V_21 ;
}
if ( V_1408 != V_11 -> V_1437 ) {
F_10 ( V_11 , L_186 ,
V_1533 -> V_1535 , V_1408 ) ;
}
memcpy ( V_11 -> V_1436 , V_1534 , V_11 -> V_1437 ) ;
if ( ! F_425 ( & V_11 -> V_1436 [ 0 ] ) ) {
F_10 ( V_11 , L_187 ,
V_1533 -> V_1535 ) ;
F_10 ( V_11 , L_188 , V_1533 -> V_1535 , V_11 -> V_1436 ) ;
return - V_21 ;
}
memcpy ( V_11 -> V_1106 , V_11 -> V_1436 , V_11 -> V_1437 ) ;
V_1411 = F_536 ( V_1533 , L_137 , & V_1408 ) ;
if ( V_1411 )
strcpy ( V_4 -> V_1223 . V_1411 , V_1411 ) ;
if ( F_544 ( V_1533 , L_189 , & V_1408 ) ) {
V_4 -> V_87 |= ( V_88 | V_344 |
V_134 ) ;
}
return 0 ;
#else
return - V_21 ;
#endif
}
static int T_12 F_545 ( struct V_3 * V_4 )
{
int V_10 , V_1536 ;
T_3 V_486 ;
V_10 = F_542 ( V_4 ) ;
if ( V_10 == - V_8 )
return V_10 ;
V_1536 = ! V_10 ;
V_10 = F_531 ( V_4 ) ;
if ( V_10 )
return V_10 ;
if ( V_1536 ) {
V_10 = F_516 ( V_4 ) ;
if ( V_10 )
return V_10 ;
} else {
if ( V_4 -> V_25 -> V_339 == V_343 )
return - V_21 ;
F_18 ( V_1537 , V_1538 ) ;
V_486 = F_511 ( V_4 ) ;
F_164 ( V_4 , V_472 , V_473 , V_4 -> V_11 ,
L_190 , V_67 , V_486 ) ;
if ( V_486 )
F_510 ( V_4 , V_486 ) ;
F_18 ( V_1537 , 0 ) ;
if ( V_4 -> V_87 & V_1405 ) {
F_514 ( V_4 ) ;
V_10 = F_516 ( V_4 ) ;
if ( V_10 )
return V_10 ;
}
if ( ! ( V_4 -> V_87 & V_1405 ) ) {
V_10 = F_516 ( V_4 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_515 ( V_4 ) ;
if ( V_10 )
return V_10 ;
}
}
V_10 = F_528 ( V_4 ) ;
if ( V_10 )
return V_10 ;
F_537 ( V_4 ) ;
F_529 ( V_4 ) ;
F_530 ( V_4 ) ;
V_10 = F_111 ( V_4 ) ;
if ( ! V_10 )
V_10 = F_112 ( V_4 ) ;
return V_10 ;
}
static T_14 F_546 ( struct V_511 * V_11 ,
struct V_1539 * V_1540 , char * V_1541 )
{
struct V_1522 * V_1542 = F_547 ( V_11 ) ;
struct V_24 * V_501 = V_1542 -> V_11 . V_1543 ;
T_3 V_287 = V_501 -> V_287 ;
char * V_1544 = V_1541 ;
int V_26 ;
if ( V_287 == V_1500 ||
V_287 == V_1501 )
return 0 ;
for ( V_26 = 0 ; V_26 < V_501 -> V_481 ; V_26 ++ ) {
const char * V_1545 ;
int type ;
type = F_27 ( V_287 , V_26 ) ;
if ( type == V_848 )
V_1545 = L_191 ;
else
V_1545 = L_192 ;
V_1541 += sprintf ( V_1541 ,
( V_26 == 0 ) ? L_193 : L_194 ,
V_1545 ) ;
}
V_1541 += sprintf ( V_1541 , L_195 ) ;
return V_1541 - V_1544 ;
}
static T_14 F_548 ( struct V_511 * V_11 ,
struct V_1539 * V_1540 , char * V_1541 )
{
struct V_1522 * V_1542 = F_547 ( V_11 ) ;
struct V_24 * V_501 = V_1542 -> V_11 . V_1543 ;
const char * V_1545 ;
switch ( V_501 -> V_339 ) {
case V_1546 :
V_1545 = L_196 ;
break;
case V_343 :
V_1545 = L_197 ;
break;
case V_351 :
V_1545 = L_198 ;
break;
case V_352 :
V_1545 = L_199 ;
break;
default:
V_1545 = L_200 ;
break;
}
return sprintf ( V_1541 , L_201 , V_1545 ) ;
}
static T_14 F_549 ( struct V_511 * V_11 ,
struct V_1539 * V_1540 , char * V_1541 ,
int V_1547 )
{
struct V_1522 * V_1542 = F_547 ( V_11 ) ;
struct V_24 * V_501 = V_1542 -> V_11 . V_1543 ;
char * V_1544 = V_1541 ;
T_5 * V_1548 ;
int V_26 ;
V_1548 = ( V_1547 ? V_501 -> V_811 : V_501 -> V_812 ) ;
for ( V_26 = 0 ; V_26 < V_501 -> V_481 ; V_26 ++ ) {
V_1541 += sprintf ( V_1541 ,
( V_26 == 0 ) ? L_202 : L_203 ,
V_1548 [ V_26 ] ) ;
}
V_1541 += sprintf ( V_1541 , L_195 ) ;
return V_1541 - V_1544 ;
}
static T_14 F_550 ( struct V_511 * V_11 ,
struct V_1539 * V_1540 , char * V_1541 )
{
return F_549 ( V_11 , V_1540 , V_1541 , 1 ) ;
}
static T_14 F_551 ( struct V_511 * V_11 ,
struct V_1539 * V_1540 , char * V_1541 )
{
return F_549 ( V_11 , V_1540 , V_1541 , 1 ) ;
}
static T_14 F_552 ( struct V_511 * V_11 ,
struct V_1539 * V_1540 , char * V_1541 )
{
struct V_1522 * V_1542 = F_547 ( V_11 ) ;
struct V_24 * V_501 = V_1542 -> V_11 . V_1543 ;
return sprintf ( V_1541 , L_204 , V_501 -> V_481 ) ;
}
static struct V_24 * T_12 F_553 ( struct V_3 * V_4 ,
union V_1549 * V_1464 ,
T_5 V_546 )
{
struct V_1522 * V_1542 ;
struct V_24 * V_501 ;
int V_26 ;
V_1542 = F_554 ( L_205 , V_1550 ,
NULL , 0 ) ;
if ( F_555 ( V_1542 ) )
return NULL ;
for ( V_26 = 0 ; F_556 ( V_1551 [ V_26 ] ) ; V_26 ++ ) {
int V_10 = F_557 ( & V_1542 -> V_11 ,
& V_1551 [ V_26 ] ) ;
if ( V_10 )
goto V_1552;
}
V_501 = F_266 ( sizeof( * V_501 ) , V_802 ) ;
if ( ! V_501 )
goto V_1552;
V_501 -> V_375 = V_1550 ++ ;
V_1542 -> V_11 . V_1543 = V_501 ;
V_501 -> V_1542 = V_1542 ;
memcpy ( & V_501 -> V_1464 , V_1464 , sizeof( * V_1464 ) ) ;
V_501 -> V_339 = V_546 ;
F_558 ( & V_501 -> V_1553 ) ;
F_559 ( & V_501 -> V_1554 , 0 ) ;
F_560 ( & V_501 -> V_1553 , & V_1555 ) ;
F_561 ( & V_501 -> V_155 ) ;
V_501 -> V_904 = 7500 ;
V_501 -> V_441 = V_1556 ;
if ( V_501 -> V_339 == V_343 )
V_501 -> V_441 = V_1557 ;
for ( V_26 = V_425 ; V_26 <= V_477 ; V_26 ++ ) {
int V_375 = V_26 - V_425 ;
V_501 -> V_929 [ V_375 ] = V_1558 ;
V_501 -> V_930 [ V_375 ] = ( V_1279 |
V_1281 |
V_1283 |
( V_1285 <<
V_1286 ) |
( V_1285 <<
V_1288 ) ) ;
}
for ( V_26 = 0 ; V_26 < V_20 + 1 ; V_26 ++ )
V_501 -> V_27 [ V_26 ] = V_1559 ;
return V_501 ;
V_1552:
F_562 ( V_1542 ) ;
return NULL ;
}
static struct V_24 * T_12 F_563 ( struct V_3 * V_4 ,
union V_1549 * V_1464 ,
T_5 V_546 )
{
struct V_24 * V_501 , * V_586 ;
int V_30 = V_4 -> V_30 ;
F_564 ( & V_1560 ) ;
V_501 = NULL ;
F_565 (tmp, &niu_parent_list, list) {
if ( ! memcmp ( V_1464 , & V_586 -> V_1464 , sizeof( * V_1464 ) ) ) {
V_501 = V_586 ;
break;
}
}
if ( ! V_501 )
V_501 = F_553 ( V_4 , V_1464 , V_546 ) ;
if ( V_501 ) {
char V_1561 [ 6 ] ;
int V_10 ;
sprintf ( V_1561 , L_206 , V_30 ) ;
V_10 = F_566 ( & V_501 -> V_1542 -> V_11 . V_1562 ,
& V_4 -> V_511 -> V_1562 ,
V_1561 ) ;
if ( ! V_10 ) {
V_501 -> V_1425 [ V_30 ] = V_4 ;
F_567 ( & V_501 -> V_1554 ) ;
}
}
F_568 ( & V_1560 ) ;
return V_501 ;
}
static void F_569 ( struct V_3 * V_4 )
{
struct V_24 * V_501 = V_4 -> V_25 ;
T_5 V_30 = V_4 -> V_30 ;
char V_1561 [ 6 ] ;
F_186 ( ! V_501 || V_501 -> V_1425 [ V_30 ] != V_4 ) ;
F_164 ( V_4 , V_472 , V_473 , V_4 -> V_11 ,
L_207 , V_67 , V_30 ) ;
sprintf ( V_1561 , L_206 , V_30 ) ;
F_564 ( & V_1560 ) ;
F_570 ( & V_501 -> V_1542 -> V_11 . V_1562 , V_1561 ) ;
V_501 -> V_1425 [ V_30 ] = NULL ;
V_4 -> V_25 = NULL ;
if ( F_571 ( & V_501 -> V_1554 ) ) {
F_572 ( & V_501 -> V_1553 ) ;
F_562 ( V_501 -> V_1542 ) ;
}
F_568 ( & V_1560 ) ;
}
static void * F_573 ( struct V_511 * V_11 , T_15 V_487 ,
T_1 * V_1563 , T_7 V_1564 )
{
T_16 V_1565 ;
void * V_862 ;
V_862 = F_574 ( V_11 , V_487 , & V_1565 , V_1564 ) ;
if ( V_862 )
* V_1563 = V_1565 ;
return V_862 ;
}
static void F_575 ( struct V_511 * V_11 , T_15 V_487 ,
void * V_1566 , T_1 V_1563 )
{
F_576 ( V_11 , V_487 , V_1566 , V_1563 ) ;
}
static T_1 F_577 ( struct V_511 * V_11 , struct V_485 * V_485 ,
unsigned long V_486 , T_15 V_487 ,
enum V_1567 V_1568 )
{
return F_578 ( V_11 , V_485 , V_486 , V_487 , V_1568 ) ;
}
static void F_579 ( struct V_511 * V_11 , T_1 V_1569 ,
T_15 V_487 , enum V_1567 V_1568 )
{
F_580 ( V_11 , V_1569 , V_487 , V_1568 ) ;
}
static T_1 F_581 ( struct V_511 * V_11 , void * V_1566 ,
T_15 V_487 ,
enum V_1567 V_1568 )
{
return F_582 ( V_11 , V_1566 , V_487 , V_1568 ) ;
}
static void F_583 ( struct V_511 * V_11 , T_1 V_1569 ,
T_15 V_487 ,
enum V_1567 V_1568 )
{
F_584 ( V_11 , V_1569 , V_487 , V_1568 ) ;
}
static void T_12 F_585 ( void )
{
static int V_1570 ;
if ( V_1570 ++ == 0 )
F_48 ( L_193 , V_1226 ) ;
}
static struct V_308 * T_12 F_586 (
struct V_511 * V_1571 , struct V_1516 * V_1232 ,
struct V_1522 * V_1523 , const struct V_1572 * V_304 ,
T_5 V_30 )
{
struct V_308 * V_11 ;
struct V_3 * V_4 ;
V_11 = F_587 ( sizeof( struct V_3 ) , V_1483 ) ;
if ( ! V_11 ) {
F_221 ( V_1571 , L_208 ) ;
return NULL ;
}
F_588 ( V_11 , V_1571 ) ;
V_4 = F_396 ( V_11 ) ;
V_4 -> V_11 = V_11 ;
V_4 -> V_1232 = V_1232 ;
V_4 -> V_1523 = V_1523 ;
V_4 -> V_511 = V_1571 ;
V_4 -> V_304 = V_304 ;
V_4 -> V_1240 = V_1573 ;
F_561 ( & V_4 -> V_155 ) ;
F_589 ( & V_4 -> V_1125 , F_432 ) ;
V_4 -> V_30 = V_30 ;
return V_11 ;
}
static void T_12 F_590 ( struct V_308 * V_11 )
{
V_11 -> V_1574 = & V_1575 ;
V_11 -> V_1576 = & V_1577 ;
V_11 -> V_1578 = V_1579 ;
}
static void T_12 F_591 ( struct V_3 * V_4 )
{
struct V_308 * V_11 = V_4 -> V_11 ;
F_48 ( L_209 , V_11 -> V_1119 , V_11 -> V_1106 ) ;
if ( V_4 -> V_25 -> V_339 == V_1498 ) {
F_48 ( L_210 ,
V_11 -> V_1119 ,
( V_4 -> V_87 & V_366 ? L_211 : L_212 ) ,
( V_4 -> V_87 & V_88 ? L_191 : L_192 ) ,
( V_4 -> V_87 & V_344 ? L_213 : L_214 ) ,
( V_4 -> V_89 == V_1423 ? L_169 :
( V_4 -> V_89 == V_90 ? L_168 : L_215 ) ) ,
V_4 -> V_1223 . V_1418 ) ;
} else {
F_48 ( L_210 ,
V_11 -> V_1119 ,
( V_4 -> V_87 & V_366 ? L_211 : L_212 ) ,
( V_4 -> V_87 & V_88 ? L_191 : L_192 ) ,
( V_4 -> V_87 & V_344 ? L_216 :
( V_4 -> V_87 & V_345 ? L_214 :
L_217 ) ) ,
( V_4 -> V_89 == V_1423 ? L_169 :
( V_4 -> V_89 == V_90 ? L_168 : L_215 ) ) ,
V_4 -> V_1223 . V_1418 ) ;
}
}
static void T_12 F_592 ( struct V_308 * V_11 )
{
V_11 -> V_1580 = V_1581 | V_1582 | V_556 ;
V_11 -> V_555 |= V_11 -> V_1580 | V_1583 ;
}
static int T_12 F_593 ( struct V_1516 * V_1232 ,
const struct V_1584 * V_468 )
{
union V_1549 V_1585 ;
struct V_308 * V_11 ;
struct V_3 * V_4 ;
int V_10 , V_1586 ;
T_1 V_1587 ;
T_4 V_1588 ;
F_585 () ;
V_10 = F_594 ( V_1232 ) ;
if ( V_10 ) {
F_221 ( & V_1232 -> V_11 , L_218 ) ;
return V_10 ;
}
if ( ! ( F_595 ( V_1232 , 0 ) & V_1589 ) ||
! ( F_595 ( V_1232 , 2 ) & V_1589 ) ) {
F_221 ( & V_1232 -> V_11 , L_219 ) ;
V_10 = - V_8 ;
goto V_1590;
}
V_10 = F_596 ( V_1232 , V_1225 ) ;
if ( V_10 ) {
F_221 ( & V_1232 -> V_11 , L_220 ) ;
goto V_1590;
}
V_1586 = F_597 ( V_1232 ) ;
if ( V_1586 <= 0 ) {
F_221 ( & V_1232 -> V_11 , L_221 ) ;
goto V_1591;
}
V_11 = F_586 ( & V_1232 -> V_11 , V_1232 , NULL ,
& V_1592 , F_598 ( V_1232 -> V_1593 ) ) ;
if ( ! V_11 ) {
V_10 = - V_509 ;
goto V_1591;
}
V_4 = F_396 ( V_11 ) ;
memset ( & V_1585 , 0 , sizeof( V_1585 ) ) ;
V_1585 . V_1594 . V_1595 = F_599 ( V_1232 -> V_1596 ) ;
V_1585 . V_1594 . V_1596 = V_1232 -> V_1596 -> V_1597 ;
V_1585 . V_1594 . V_511 = F_600 ( V_1232 -> V_1593 ) ;
V_4 -> V_25 = F_563 ( V_4 , & V_1585 ,
V_1546 ) ;
if ( ! V_4 -> V_25 ) {
V_10 = - V_509 ;
goto V_1598;
}
F_601 ( V_1232 , V_1586 + V_1599 , & V_1588 ) ;
V_1588 &= ~ V_1600 ;
V_1588 |= ( V_1601 |
V_1602 |
V_1603 |
V_1604 |
V_1605 ) ;
F_602 ( V_1232 , V_1586 + V_1599 , V_1588 ) ;
V_1587 = F_603 ( 44 ) ;
V_10 = F_604 ( V_1232 , V_1587 ) ;
if ( ! V_10 ) {
V_11 -> V_555 |= V_1606 ;
V_10 = F_605 ( V_1232 , V_1587 ) ;
if ( V_10 ) {
F_221 ( & V_1232 -> V_11 , L_222 ) ;
goto V_1607;
}
}
if ( V_10 || V_1587 == F_603 ( 32 ) ) {
V_10 = F_604 ( V_1232 , F_603 ( 32 ) ) ;
if ( V_10 ) {
F_221 ( & V_1232 -> V_11 , L_223 ) ;
goto V_1607;
}
}
F_592 ( V_11 ) ;
V_4 -> V_1504 = F_606 ( V_1232 , 0 ) ;
if ( ! V_4 -> V_1504 ) {
F_221 ( & V_1232 -> V_11 , L_224 ) ;
V_10 = - V_509 ;
goto V_1607;
}
F_607 ( V_1232 ) ;
F_608 ( V_1232 ) ;
V_11 -> V_784 = V_1232 -> V_784 ;
F_590 ( V_11 ) ;
V_10 = F_545 ( V_4 ) ;
if ( V_10 ) {
if ( V_10 != - V_8 )
F_221 ( & V_1232 -> V_11 , L_225 ) ;
goto V_1608;
}
V_10 = F_609 ( V_11 ) ;
if ( V_10 ) {
F_221 ( & V_1232 -> V_11 , L_226 ) ;
goto V_1608;
}
F_610 ( V_1232 , V_11 ) ;
F_591 ( V_4 ) ;
return 0 ;
V_1608:
if ( V_4 -> V_1504 ) {
F_611 ( V_4 -> V_1504 ) ;
V_4 -> V_1504 = NULL ;
}
V_1607:
F_569 ( V_4 ) ;
V_1598:
F_612 ( V_11 ) ;
V_1591:
F_613 ( V_1232 ) ;
V_1590:
F_614 ( V_1232 ) ;
F_610 ( V_1232 , NULL ) ;
return V_10 ;
}
static void T_13 F_615 ( struct V_1516 * V_1232 )
{
struct V_308 * V_11 = F_616 ( V_1232 ) ;
if ( V_11 ) {
struct V_3 * V_4 = F_396 ( V_11 ) ;
F_617 ( V_11 ) ;
if ( V_4 -> V_1504 ) {
F_611 ( V_4 -> V_1504 ) ;
V_4 -> V_1504 = NULL ;
}
F_540 ( V_4 ) ;
F_569 ( V_4 ) ;
F_612 ( V_11 ) ;
F_613 ( V_1232 ) ;
F_614 ( V_1232 ) ;
F_610 ( V_1232 , NULL ) ;
}
}
static int F_618 ( struct V_1516 * V_1232 , T_17 V_1376 )
{
struct V_308 * V_11 = F_616 ( V_1232 ) ;
struct V_3 * V_4 = F_396 ( V_11 ) ;
unsigned long V_87 ;
if ( ! F_413 ( V_11 ) )
return 0 ;
F_619 ( & V_4 -> V_1125 ) ;
F_427 ( V_4 ) ;
F_404 ( & V_4 -> V_15 ) ;
F_63 ( & V_4 -> V_155 , V_87 ) ;
F_25 ( V_4 , 0 ) ;
F_65 ( & V_4 -> V_155 , V_87 ) ;
F_620 ( V_11 ) ;
F_63 ( & V_4 -> V_155 , V_87 ) ;
F_385 ( V_4 ) ;
F_65 ( & V_4 -> V_155 , V_87 ) ;
F_608 ( V_1232 ) ;
return 0 ;
}
static int F_621 ( struct V_1516 * V_1232 )
{
struct V_308 * V_11 = F_616 ( V_1232 ) ;
struct V_3 * V_4 = F_396 ( V_11 ) ;
unsigned long V_87 ;
int V_10 ;
if ( ! F_413 ( V_11 ) )
return 0 ;
F_622 ( V_1232 ) ;
F_623 ( V_11 ) ;
F_63 ( & V_4 -> V_155 , V_87 ) ;
V_10 = F_384 ( V_4 ) ;
if ( ! V_10 ) {
V_4 -> V_15 . V_337 = V_338 + V_336 ;
F_109 ( & V_4 -> V_15 ) ;
F_429 ( V_4 ) ;
}
F_65 ( & V_4 -> V_155 , V_87 ) ;
return V_10 ;
}
static void * F_624 ( struct V_511 * V_11 , T_15 V_487 ,
T_1 * V_1609 , T_7 V_1564 )
{
unsigned long V_1610 = F_625 ( V_487 ) ;
unsigned long V_485 = F_626 ( V_1564 , V_1610 ) ;
if ( V_485 == 0UL )
return NULL ;
memset ( ( char * ) V_485 , 0 , V_512 << V_1610 ) ;
* V_1609 = F_627 ( V_485 ) ;
return ( void * ) V_485 ;
}
static void F_628 ( struct V_511 * V_11 , T_15 V_487 ,
void * V_1566 , T_1 V_1563 )
{
unsigned long V_1610 = F_625 ( V_487 ) ;
F_629 ( ( unsigned long ) V_1566 , V_1610 ) ;
}
static T_1 F_630 ( struct V_511 * V_11 , struct V_485 * V_485 ,
unsigned long V_486 , T_15 V_487 ,
enum V_1567 V_1568 )
{
return F_631 ( V_485 ) + V_486 ;
}
static void F_632 ( struct V_511 * V_11 , T_1 V_1569 ,
T_15 V_487 , enum V_1567 V_1568 )
{
}
static T_1 F_633 ( struct V_511 * V_11 , void * V_1566 ,
T_15 V_487 ,
enum V_1567 V_1568 )
{
return F_627 ( V_1566 ) ;
}
static void F_634 ( struct V_511 * V_11 , T_1 V_1569 ,
T_15 V_487 ,
enum V_1567 V_1568 )
{
}
static int T_12 F_635 ( struct V_1522 * V_1523 )
{
union V_1549 V_1585 ;
struct V_308 * V_11 ;
struct V_3 * V_4 ;
const T_3 * V_1 ;
int V_10 ;
F_585 () ;
V_1 = F_536 ( V_1523 -> V_11 . V_1525 , L_227 , NULL ) ;
if ( ! V_1 ) {
F_221 ( & V_1523 -> V_11 , L_228 ,
V_1523 -> V_11 . V_1525 -> V_1535 ) ;
return - V_8 ;
}
V_11 = F_586 ( & V_1523 -> V_11 , NULL , V_1523 ,
& V_1611 , V_1 [ 0 ] & 0x1 ) ;
if ( ! V_11 ) {
V_10 = - V_509 ;
goto V_1612;
}
V_4 = F_396 ( V_11 ) ;
memset ( & V_1585 , 0 , sizeof( V_1585 ) ) ;
V_1585 . V_1613 = F_636 ( V_1523 -> V_11 . V_1525 ) ;
V_4 -> V_25 = F_563 ( V_4 , & V_1585 ,
V_343 ) ;
if ( ! V_4 -> V_25 ) {
V_10 = - V_509 ;
goto V_1598;
}
F_592 ( V_11 ) ;
V_4 -> V_1504 = F_637 ( & V_1523 -> V_1614 [ 1 ] , 0 ,
F_638 ( & V_1523 -> V_1614 [ 1 ] ) ,
L_229 ) ;
if ( ! V_4 -> V_1504 ) {
F_221 ( & V_1523 -> V_11 , L_224 ) ;
V_10 = - V_509 ;
goto V_1607;
}
V_4 -> V_1615 = F_637 ( & V_1523 -> V_1614 [ 2 ] , 0 ,
F_638 ( & V_1523 -> V_1614 [ 2 ] ) ,
L_230 ) ;
if ( ! V_4 -> V_1615 ) {
F_221 ( & V_1523 -> V_11 , L_231 ) ;
V_10 = - V_509 ;
goto V_1608;
}
V_4 -> V_1616 = F_637 ( & V_1523 -> V_1614 [ 3 ] , 0 ,
F_638 ( & V_1523 -> V_1614 [ 3 ] ) ,
L_232 ) ;
if ( ! V_4 -> V_1616 ) {
F_221 ( & V_1523 -> V_11 , L_233 ) ;
V_10 = - V_509 ;
goto V_1608;
}
F_590 ( V_11 ) ;
V_10 = F_545 ( V_4 ) ;
if ( V_10 ) {
if ( V_10 != - V_8 )
F_221 ( & V_1523 -> V_11 , L_225 ) ;
goto V_1608;
}
V_10 = F_609 ( V_11 ) ;
if ( V_10 ) {
F_221 ( & V_1523 -> V_11 , L_226 ) ;
goto V_1608;
}
F_639 ( & V_1523 -> V_11 , V_11 ) ;
F_591 ( V_4 ) ;
return 0 ;
V_1608:
if ( V_4 -> V_1615 ) {
F_640 ( & V_1523 -> V_1614 [ 2 ] , V_4 -> V_1615 ,
F_638 ( & V_1523 -> V_1614 [ 2 ] ) ) ;
V_4 -> V_1615 = NULL ;
}
if ( V_4 -> V_1616 ) {
F_640 ( & V_1523 -> V_1614 [ 3 ] , V_4 -> V_1616 ,
F_638 ( & V_1523 -> V_1614 [ 3 ] ) ) ;
V_4 -> V_1616 = NULL ;
}
if ( V_4 -> V_1504 ) {
F_640 ( & V_1523 -> V_1614 [ 1 ] , V_4 -> V_1504 ,
F_638 ( & V_1523 -> V_1614 [ 1 ] ) ) ;
V_4 -> V_1504 = NULL ;
}
V_1607:
F_569 ( V_4 ) ;
V_1598:
F_612 ( V_11 ) ;
V_1612:
return V_10 ;
}
static int T_13 F_641 ( struct V_1522 * V_1523 )
{
struct V_308 * V_11 = F_642 ( & V_1523 -> V_11 ) ;
if ( V_11 ) {
struct V_3 * V_4 = F_396 ( V_11 ) ;
F_617 ( V_11 ) ;
if ( V_4 -> V_1615 ) {
F_640 ( & V_1523 -> V_1614 [ 2 ] , V_4 -> V_1615 ,
F_638 ( & V_1523 -> V_1614 [ 2 ] ) ) ;
V_4 -> V_1615 = NULL ;
}
if ( V_4 -> V_1616 ) {
F_640 ( & V_1523 -> V_1614 [ 3 ] , V_4 -> V_1616 ,
F_638 ( & V_1523 -> V_1614 [ 3 ] ) ) ;
V_4 -> V_1616 = NULL ;
}
if ( V_4 -> V_1504 ) {
F_640 ( & V_1523 -> V_1614 [ 1 ] , V_4 -> V_1504 ,
F_638 ( & V_1523 -> V_1614 [ 1 ] ) ) ;
V_4 -> V_1504 = NULL ;
}
F_540 ( V_4 ) ;
F_569 ( V_4 ) ;
F_612 ( V_11 ) ;
F_639 ( & V_1523 -> V_11 , NULL ) ;
}
return 0 ;
}
static int T_18 F_643 ( void )
{
int V_10 = 0 ;
F_265 ( V_512 < 4 * 1024 ) ;
V_1573 = F_644 ( V_1617 , V_1618 ) ;
#ifdef F_535
V_10 = F_645 ( & V_1619 ) ;
#endif
if ( ! V_10 ) {
V_10 = F_646 ( & V_1620 ) ;
#ifdef F_535
if ( V_10 )
F_647 ( & V_1619 ) ;
#endif
}
return V_10 ;
}
static void T_19 F_648 ( void )
{
F_649 ( & V_1620 ) ;
#ifdef F_535
F_647 ( & V_1619 ) ;
#endif
}

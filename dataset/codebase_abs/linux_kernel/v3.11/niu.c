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
V_174 = F_72 ( V_167 ) ;
V_174 |= F_73 ( V_168 ) ;
if ( V_171 & V_198 ) {
int V_199 , V_200 ;
V_13 -> V_201 = 1 ;
V_174 |= V_202 ;
V_199 = V_167 & V_170 ;
V_200 = ( V_168 << 2 ) & V_169 ;
if ( V_200 & ( V_203 | V_204 ) )
V_160 = V_158 ;
else if ( V_199 & V_205 )
V_160 = V_206 ;
else if ( V_199 & ( V_207 | V_208 ) )
V_160 = V_209 ;
else
V_160 = V_153 ;
if ( ( V_200 & V_203 ) || ( V_199 & V_210 ) )
V_161 = V_159 ;
else if ( V_160 != V_153 )
V_161 = V_211 ;
else
V_161 = V_154 ;
} else {
V_13 -> V_201 = 0 ;
if ( ( V_171 & V_212 ) && ! ( V_171 & V_213 ) )
V_160 = V_158 ;
else if ( V_171 & V_213 )
V_160 = V_206 ;
else
V_160 = V_209 ;
if ( V_171 & V_214 )
V_161 = V_159 ;
else
V_161 = V_211 ;
}
V_13 -> V_215 = V_174 ;
V_13 -> V_160 = V_160 ;
V_13 -> V_161 = V_161 ;
* V_149 = ! ! ( V_166 & V_216 ) ;
return 0 ;
}
static int F_74 ( struct V_3 * V_4 , int * V_149 )
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
goto V_217;
V_166 = V_10 ;
if ( V_166 & V_216 ) {
T_4 V_218 , V_170 ;
V_10 = F_34 ( V_4 , V_4 -> V_175 , V_178 ) ;
if ( V_10 < 0 )
goto V_217;
V_218 = V_10 ;
V_10 = F_34 ( V_4 , V_4 -> V_175 , V_179 ) ;
if ( V_10 < 0 )
goto V_217;
V_170 = V_10 ;
V_10 = F_34 ( V_4 , V_4 -> V_175 , V_181 ) ;
if ( V_10 < 0 )
goto V_217;
V_150 = 1 ;
V_151 = V_158 ;
V_152 = V_159 ;
}
V_13 -> V_160 = V_151 ;
V_13 -> V_161 = V_152 ;
V_10 = 0 ;
V_217:
F_65 ( & V_4 -> V_155 , V_87 ) ;
* V_149 = V_150 ;
return V_10 ;
}
static int F_75 ( struct V_3 * V_4 , int * V_149 )
{
struct V_38 * V_13 = & V_4 -> V_39 ;
unsigned long V_87 ;
int V_10 ;
F_63 ( & V_4 -> V_155 , V_87 ) ;
V_10 = F_69 ( V_4 , V_149 ) ;
V_13 -> V_173 |= V_219 ;
V_13 -> V_215 |= V_220 ;
F_65 ( & V_4 -> V_155 , V_87 ) ;
return V_10 ;
}
static int F_76 ( struct V_3 * V_4 )
{
int V_10 , V_6 ;
V_10 = F_29 ( V_4 , V_4 -> V_175 ,
V_221 , V_176 ) ;
if ( V_10 < 0 || V_10 == 0xffff )
return V_10 ;
V_10 |= V_222 ;
V_10 = F_32 ( V_4 , V_4 -> V_175 , V_221 ,
V_176 , V_10 ) ;
if ( V_10 )
return V_10 ;
V_6 = 1000 ;
while ( -- V_6 >= 0 ) {
V_10 = F_29 ( V_4 , V_4 -> V_175 ,
V_221 , V_176 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( ! ( V_10 & V_222 ) )
break;
}
if ( V_6 < 0 ) {
F_10 ( V_4 -> V_11 , L_8 ,
V_4 -> V_30 , ( V_10 & 0xffff ) ) ;
return - V_8 ;
}
return 0 ;
}
static int F_77 ( struct V_3 * V_4 , int V_1 )
{
int V_10 = F_29 ( V_4 , V_4 -> V_175 , V_223 , V_1 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_223 , V_1 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
static int F_78 ( struct V_3 * V_4 )
{
int V_10 ;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_223 ,
V_224 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 &= ~ V_225 ;
V_10 |= ( 0x3 << V_226 ) ;
V_10 |= V_227 ;
V_10 = F_32 ( V_4 , V_4 -> V_175 , V_223 ,
V_224 , V_10 ) ;
if ( V_10 )
return V_10 ;
F_46 ( 1000 ) ;
return 0 ;
}
static int F_79 ( struct V_3 * V_4 )
{
int V_10 ;
V_10 = F_32 ( V_4 , V_4 -> V_175 ,
V_223 , V_228 ,
( V_229 |
V_230 |
V_231 |
V_232 |
V_233 |
V_234 |
V_235 |
V_236 |
( 0x3f << V_237 ) ) ) ;
if ( V_10 )
return V_10 ;
V_10 = F_32 ( V_4 , V_4 -> V_175 ,
V_223 , V_238 ,
( V_239 |
( 1 << V_240 ) |
( 2 << V_241 ) |
V_242 ) ) ;
if ( V_10 )
return V_10 ;
V_10 = F_77 ( V_4 , V_228 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_77 ( V_4 , V_238 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_223 ,
V_224 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 &= ~ V_225 ;
V_10 |= ( 0x3 << V_226 ) ;
V_10 = F_32 ( V_4 , V_4 -> V_175 , V_223 ,
V_224 , V_10 ) ;
if ( V_10 )
return V_10 ;
F_46 ( 1000 ) ;
return 0 ;
}
static int F_80 ( struct V_3 * V_4 , int V_2 )
{
int V_10 ;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_243 ,
V_244 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 &= ~ F_81 ( V_245 , V_246 ) ;
V_10 |= F_81 ( V_245 , V_2 ) ;
return F_32 ( V_4 , V_4 -> V_175 , V_243 ,
V_244 , V_10 ) ;
}
static int F_82 ( struct V_3 * V_4 , int V_247 )
{
int V_10 ;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_243 ,
V_248 ) ;
if ( V_10 >= 0 ) {
V_10 &= ~ V_249 ;
V_10 |= ( V_247 << 4 ) ;
V_10 = F_32 ( V_4 , V_4 -> V_175 , V_243 ,
V_248 , V_10 ) ;
}
return V_10 ;
}
static int F_83 ( struct V_3 * V_4 )
{
int V_10 ;
V_10 = F_82 ( V_4 , V_250 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_80 ( V_4 , V_251 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_252 ,
V_253 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 |= V_254 ;
V_10 = F_32 ( V_4 , V_4 -> V_175 , V_252 ,
V_253 , V_10 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_255 ,
V_256 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_4 -> V_39 . V_49 == V_257 )
V_10 |= V_258 ;
else
V_10 &= ~ V_258 ;
V_10 = F_32 ( V_4 , V_4 -> V_175 , V_255 ,
V_256 , V_10 ) ;
if ( V_10 < 0 )
return V_10 ;
return F_32 ( V_4 , V_4 -> V_175 , V_255 ,
V_259 , V_260 ) ;
}
static int F_84 ( struct V_3 * V_4 )
{
T_4 V_261 , V_262 ;
int V_10 = 0 ;
#if 1
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_263 ,
V_183 ) ;
if ( V_10 < 0 )
return V_10 ;
F_48 ( L_9 , V_4 -> V_30 , V_10 ) ;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_223 , 0x20 ) ;
if ( V_10 < 0 )
return V_10 ;
F_48 ( L_10 , V_4 -> V_30 , V_10 ) ;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_221 ,
V_264 ) ;
if ( V_10 < 0 )
return V_10 ;
F_48 ( L_11 , V_4 -> V_30 , V_10 ) ;
#endif
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_223 ,
V_265 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_223 ,
V_265 ) ;
if ( V_10 < 0 )
return V_10 ;
V_261 = V_10 ;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_223 ,
V_266 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_223 ,
V_266 ) ;
if ( V_10 < 0 )
return V_10 ;
V_262 = V_10 ;
if ( V_261 != 0x03fc ) {
if ( ( V_261 == 0x43bc ) && ( V_262 != 0 ) ) {
F_48 ( L_12 ,
V_4 -> V_30 ) ;
} else if ( V_261 == 0x639c ) {
F_48 ( L_13 ,
V_4 -> V_30 ) ;
}
}
return 0 ;
}
static int F_85 ( struct V_3 * V_4 )
{
struct V_38 * V_13 = & V_4 -> V_39 ;
int V_10 ;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_267 ,
V_176 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 &= ~ V_268 ;
if ( V_13 -> V_49 == V_257 )
V_10 |= V_268 ;
V_10 = F_32 ( V_4 , V_4 -> V_175 , V_267 ,
V_176 , V_10 ) ;
if ( V_10 )
return V_10 ;
return 0 ;
}
static int F_86 ( struct V_3 * V_4 )
{
int V_10 = 0 ;
T_1 V_2 ;
if ( ( V_4 -> V_87 & V_134 ) &&
( V_4 -> V_87 & V_135 ) == 0 )
return V_10 ;
V_2 = F_6 ( V_269 ) ;
V_2 &= ~ V_270 ;
V_2 |= V_271 ;
F_9 ( V_269 , V_2 ) ;
V_2 = F_16 ( V_272 ) ;
V_2 |= V_273 ;
F_18 ( V_272 , V_2 ) ;
V_10 = F_76 ( V_4 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_85 ( V_4 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_78 ( V_4 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_84 ( V_4 ) ;
if ( V_10 )
return V_10 ;
return 0 ;
}
static int F_87 ( struct V_3 * V_4 )
{
int V_10 ;
V_10 = F_76 ( V_4 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_79 ( V_4 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_85 ( V_4 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_84 ( V_4 ) ;
if ( V_10 )
return V_10 ;
return 0 ;
}
static int F_88 ( struct V_3 * V_4 )
{
int V_274 , V_10 ;
T_1 V_2 ;
V_2 = F_6 ( V_269 ) ;
V_2 &= ~ V_270 ;
V_2 |= V_271 ;
F_9 ( V_269 , V_2 ) ;
V_2 = F_16 ( V_272 ) ;
V_2 |= V_273 ;
F_18 ( V_272 , V_2 ) ;
V_274 = F_27 ( V_4 -> V_25 -> V_275 , V_4 -> V_30 ) ;
V_274 = V_4 -> V_25 -> V_276 . V_274 [ V_274 ] [ V_4 -> V_30 ] ;
switch ( V_274 & V_277 ) {
case V_278 :
V_10 = F_83 ( V_4 ) ;
break;
default:
V_10 = F_87 ( V_4 ) ;
break;
}
return V_10 ;
}
static int F_89 ( struct V_3 * V_4 )
{
int V_6 , V_10 ;
V_10 = F_36 ( V_4 , V_4 -> V_175 , V_176 , V_222 ) ;
if ( V_10 )
return V_10 ;
V_6 = 1000 ;
while ( -- V_6 >= 0 ) {
F_7 ( 500 ) ;
V_10 = F_34 ( V_4 , V_4 -> V_175 , V_176 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( ! ( V_10 & V_222 ) )
break;
}
if ( V_6 < 0 ) {
F_10 ( V_4 -> V_11 , L_14 ,
V_4 -> V_30 , V_10 ) ;
return - V_8 ;
}
return 0 ;
}
static int F_90 ( struct V_3 * V_4 )
{
int V_10 ;
T_1 V_2 ;
T_4 V_171 , V_166 , V_279 ;
V_2 = F_16 ( V_272 ) ;
V_2 &= ~ V_273 ;
F_18 ( V_272 , V_2 ) ;
V_10 = F_89 ( V_4 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_34 ( V_4 , V_4 -> V_175 , V_177 ) ;
if ( V_10 < 0 )
return V_10 ;
V_166 = V_10 ;
V_279 = 0 ;
if ( V_166 & V_180 ) {
V_10 = F_34 ( V_4 , V_4 -> V_175 , V_181 ) ;
if ( V_10 < 0 )
return V_10 ;
V_279 = V_10 ;
}
V_171 = 0 ;
V_10 = F_36 ( V_4 , V_4 -> V_175 , V_176 , V_171 ) ;
if ( V_10 )
return V_10 ;
if ( V_166 & V_180 ) {
T_4 V_168 = 0 ;
if ( V_279 & V_196 )
V_168 |= V_280 ;
V_10 = F_36 ( V_4 , V_4 -> V_175 , V_182 , V_168 ) ;
if ( V_10 )
return V_10 ;
}
V_171 = ( V_212 | V_214 ) ;
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
static int F_91 ( struct V_3 * V_4 )
{
struct V_38 * V_13 = & V_4 -> V_39 ;
T_4 V_171 , V_166 , V_218 , V_279 ;
int V_10 ;
V_10 = F_89 ( V_4 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_34 ( V_4 , V_4 -> V_175 , V_177 ) ;
if ( V_10 < 0 )
return V_10 ;
V_166 = V_10 ;
V_279 = 0 ;
if ( V_166 & V_180 ) {
V_10 = F_34 ( V_4 , V_4 -> V_175 , V_181 ) ;
if ( V_10 < 0 )
return V_10 ;
V_279 = V_10 ;
}
V_171 = 0 ;
V_10 = F_36 ( V_4 , V_4 -> V_175 , V_176 , V_171 ) ;
if ( V_10 )
return V_10 ;
if ( V_13 -> V_49 == V_257 ) {
V_171 |= V_268 ;
if ( V_13 -> V_160 == V_158 )
V_171 |= V_212 ;
if ( V_13 -> V_161 == V_159 )
V_171 |= V_214 ;
}
if ( V_13 -> V_49 == V_50 ) {
T_4 V_281 ;
V_281 = ( V_282 |
V_283 ) ;
V_10 = F_36 ( V_4 , V_4 -> V_175 , V_284 , V_281 ) ;
if ( V_10 )
return V_10 ;
}
if ( V_13 -> V_285 ) {
T_4 V_168 ;
V_218 = V_286 | V_287 ;
if ( ( V_166 & V_186 ) &&
( V_13 -> V_174 & V_288 ) )
V_218 |= V_289 ;
if ( ( V_166 & V_188 ) &&
( V_13 -> V_174 & V_290 ) )
V_218 |= V_291 ;
if ( ( V_166 & V_190 ) &&
( V_13 -> V_174 & V_292 ) )
V_218 |= V_293 ;
if ( ( V_166 & V_192 ) &&
( V_13 -> V_174 & V_294 ) )
V_218 |= V_295 ;
V_10 = F_36 ( V_4 , V_4 -> V_175 , V_178 , V_218 ) ;
if ( V_10 )
return V_10 ;
if ( F_71 ( V_166 & V_180 ) ) {
V_168 = 0 ;
if ( ( V_279 & V_194 ) &&
( V_13 -> V_174 & V_296 ) )
V_168 |= V_297 ;
if ( ( V_279 & V_196 ) &&
( V_13 -> V_174 & V_298 ) )
V_168 |= V_280 ;
V_10 = F_36 ( V_4 , V_4 -> V_175 ,
V_182 , V_168 ) ;
if ( V_10 )
return V_10 ;
}
V_171 |= ( V_198 | V_299 ) ;
} else {
int V_300 ;
if ( V_13 -> V_301 == V_159 ) {
V_171 |= V_214 ;
V_300 = 1 ;
} else if ( V_13 -> V_301 == V_211 )
V_300 = 0 ;
else
return - V_21 ;
if ( V_13 -> V_302 == V_158 ) {
if ( ( V_300 && ! ( V_279 & V_196 ) ) ||
( ! V_300 && ! ( V_279 & V_194 ) ) )
return - V_21 ;
V_171 |= V_212 ;
} else if ( V_13 -> V_302 == V_206 ) {
if ( ( V_300 && ! ( V_166 & V_192 ) ) ||
( ! V_300 && ! ( V_166 & V_190 ) ) )
return - V_21 ;
V_171 |= V_213 ;
} else if ( V_13 -> V_302 == V_209 ) {
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
static int F_92 ( struct V_3 * V_4 )
{
T_1 V_2 ;
V_2 = F_16 ( V_272 ) ;
V_2 &= ~ V_273 ;
F_18 ( V_272 , V_2 ) ;
return F_91 ( V_4 ) ;
}
static int F_93 ( struct V_3 * V_4 )
{
const struct V_303 * V_304 = V_4 -> V_305 ;
int V_10 ;
V_10 = 0 ;
if ( V_304 -> V_306 )
V_10 = V_304 -> V_306 ( V_4 ) ;
return V_10 ;
}
static int F_94 ( struct V_3 * V_4 )
{
const struct V_303 * V_304 = V_4 -> V_305 ;
int V_10 ;
V_10 = 0 ;
if ( V_304 -> V_307 )
V_10 = V_304 -> V_307 ( V_4 ) ;
return V_10 ;
}
static int F_95 ( struct V_3 * V_4 , int V_150 )
{
struct V_38 * V_13 = & V_4 -> V_39 ;
struct V_308 * V_11 = V_4 -> V_11 ;
unsigned long V_87 ;
if ( ! F_96 ( V_11 ) && V_150 ) {
F_97 ( V_4 , V_309 , V_11 , L_15 ,
V_13 -> V_160 == V_165 ? L_16 :
V_13 -> V_160 == V_158 ? L_17 :
V_13 -> V_160 == V_206 ? L_18 :
L_19 ,
V_13 -> V_161 == V_159 ? L_20 : L_21 ) ;
F_63 ( & V_4 -> V_155 , V_87 ) ;
F_98 ( V_4 ) ;
F_99 ( V_4 , 1 ) ;
F_65 ( & V_4 -> V_155 , V_87 ) ;
F_100 ( V_11 ) ;
} else if ( F_96 ( V_11 ) && ! V_150 ) {
F_101 ( V_4 , V_309 , V_11 , L_22 ) ;
F_63 ( & V_4 -> V_155 , V_87 ) ;
F_99 ( V_4 , 0 ) ;
F_65 ( & V_4 -> V_155 , V_87 ) ;
F_102 ( V_11 ) ;
}
return 0 ;
}
static int F_103 ( struct V_3 * V_4 , int * V_149 )
{
int V_10 , V_150 , V_310 , V_311 ;
V_150 = 0 ;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_255 ,
V_312 ) ;
if ( V_10 < 0 )
goto V_217;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_255 ,
V_313 ) ;
if ( V_10 < 0 )
goto V_217;
V_310 = ( ( V_10 & V_314 ) ? 1 : 0 ) ;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_252 ,
V_313 ) ;
if ( V_10 < 0 )
goto V_217;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_252 ,
V_313 ) ;
if ( V_10 < 0 )
goto V_217;
V_311 = ( ( V_10 & V_314 ) ? 1 : 0 ) ;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_315 ,
V_316 ) ;
if ( V_10 < 0 )
goto V_217;
if ( V_10 == ( V_317 | V_318 |
V_319 | V_320 |
V_321 | V_322 |
0x800 ) )
V_150 = ( V_310 && V_311 ) ? 1 : 0 ;
V_4 -> V_39 . V_160 = V_165 ;
V_4 -> V_39 . V_161 = V_159 ;
V_10 = 0 ;
V_217:
F_80 ( V_4 , ( V_150 ?
V_323 :
V_251 ) ) ;
* V_149 = V_150 ;
return V_10 ;
}
static int F_104 ( struct V_3 * V_4 , int * V_149 )
{
int V_10 , V_150 ;
V_150 = 0 ;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_263 ,
V_324 ) ;
if ( V_10 < 0 || V_10 == 0xffff )
goto V_217;
if ( ! ( V_10 & V_325 ) ) {
V_10 = 0 ;
goto V_217;
}
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_267 ,
V_326 ) ;
if ( V_10 < 0 )
goto V_217;
if ( ! ( V_10 & V_327 ) ) {
V_10 = 0 ;
goto V_217;
}
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_221 ,
V_328 ) ;
if ( V_10 < 0 )
goto V_217;
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
goto V_217;
}
V_150 = 1 ;
V_4 -> V_39 . V_160 = V_165 ;
V_4 -> V_39 . V_161 = V_159 ;
V_10 = 0 ;
V_217:
* V_149 = V_150 ;
return V_10 ;
}
static int F_105 ( struct V_3 * V_4 , int * V_149 )
{
int V_10 , V_150 ;
V_150 = 0 ;
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_263 ,
V_324 ) ;
if ( V_10 < 0 )
goto V_217;
if ( ! ( V_10 & V_325 ) ) {
V_10 = 0 ;
goto V_217;
}
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_267 ,
V_326 ) ;
if ( V_10 < 0 )
goto V_217;
if ( ! ( V_10 & V_327 ) ) {
V_10 = 0 ;
goto V_217;
}
V_10 = F_29 ( V_4 , V_4 -> V_175 , V_221 ,
V_328 ) ;
if ( V_10 < 0 )
goto V_217;
if ( V_10 != ( V_317 |
V_322 |
V_318 |
V_319 |
V_320 |
V_321 ) ) {
V_10 = 0 ;
goto V_217;
}
V_150 = 1 ;
V_4 -> V_39 . V_160 = V_165 ;
V_4 -> V_39 . V_161 = V_159 ;
V_10 = 0 ;
V_217:
* V_149 = V_150 ;
return V_10 ;
}
static int F_106 ( struct V_3 * V_4 , int * V_149 )
{
unsigned long V_87 ;
int V_10 = - V_21 ;
F_63 ( & V_4 -> V_155 , V_87 ) ;
if ( V_4 -> V_39 . V_49 == V_330 ) {
int V_274 ;
V_274 = F_27 ( V_4 -> V_25 -> V_275 , V_4 -> V_30 ) ;
V_274 = V_4 -> V_25 -> V_276 . V_274 [ V_274 ] [ V_4 -> V_30 ] ;
switch ( V_274 & V_277 ) {
case V_278 :
V_10 = F_103 ( V_4 , V_149 ) ;
break;
default:
V_10 = F_105 ( V_4 , V_149 ) ;
break;
}
}
F_65 ( & V_4 -> V_155 , V_87 ) ;
return V_10 ;
}
static int F_107 ( struct V_3 * V_4 )
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
static int F_108 ( struct V_3 * V_4 , int * V_149 )
{
unsigned long V_87 ;
int V_10 = 0 ;
int V_331 ;
int V_332 ;
F_63 ( & V_4 -> V_155 , V_87 ) ;
if ( V_4 -> V_39 . V_49 == V_330 ) {
V_332 = ( V_4 -> V_87 & V_135 ) ?
1 : 0 ;
V_331 = F_107 ( V_4 ) ;
if ( V_331 != V_332 ) {
if ( V_331 ) {
V_4 -> V_87 |= V_135 ;
if ( V_4 -> V_305 -> V_306 )
V_10 = V_4 -> V_305 -> V_306 ( V_4 ) ;
if ( V_10 ) {
V_10 = F_29 ( V_4 , V_4 -> V_175 ,
V_221 , V_176 ) ;
if ( V_10 == 0xffff ) {
goto V_217;
}
V_4 -> V_87 &= ~ V_135 ;
}
} else {
V_4 -> V_87 &= ~ V_135 ;
* V_149 = 0 ;
F_101 ( V_4 , V_309 , V_4 -> V_11 ,
L_23 ) ;
}
}
V_217:
if ( V_4 -> V_87 & V_135 ) {
V_10 = F_104 ( V_4 , V_149 ) ;
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
static int F_109 ( struct V_3 * V_4 , int * V_149 )
{
const struct V_303 * V_304 = V_4 -> V_305 ;
int V_10 ;
V_10 = 0 ;
if ( V_304 -> V_333 )
V_10 = V_304 -> V_333 ( V_4 , V_149 ) ;
return V_10 ;
}
static void F_110 ( unsigned long V_334 )
{
struct V_3 * V_4 = (struct V_3 * ) V_334 ;
unsigned long V_335 ;
int V_10 , V_150 ;
V_10 = F_109 ( V_4 , & V_150 ) ;
if ( ! V_10 )
F_95 ( V_4 , V_150 ) ;
if ( F_96 ( V_4 -> V_11 ) )
V_335 = 5 * V_336 ;
else
V_335 = 1 * V_336 ;
V_4 -> V_15 . V_337 = V_338 + V_335 ;
F_111 ( & V_4 -> V_15 ) ;
}
static int F_112 ( struct V_3 * V_4 )
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
static int F_113 ( struct V_3 * V_4 )
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
static int F_114 ( struct V_3 * V_4 )
{
struct V_24 * V_25 = V_4 -> V_25 ;
int V_10 , V_361 ;
if ( V_25 -> V_339 == V_343 ) {
V_10 = F_93 ( V_4 ) ;
if ( V_10 )
return V_10 ;
F_115 ( 200 ) ;
}
V_10 = F_94 ( V_4 ) ;
if ( V_10 && ! ( V_4 -> V_87 & V_134 ) )
return V_10 ;
F_115 ( 200 ) ;
V_10 = F_93 ( V_4 ) ;
if ( ! V_10 || ( V_4 -> V_87 & V_134 ) )
F_109 ( V_4 , & V_361 ) ;
return 0 ;
}
static void F_116 ( struct V_3 * V_4 , unsigned char * V_362 )
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
static int F_117 ( struct V_3 * V_4 )
{
if ( V_4 -> V_87 & V_366 )
return V_373 ;
else
return V_374 ;
}
static int F_118 ( struct V_3 * V_4 , int V_375 , unsigned char * V_362 )
{
T_4 V_363 = V_362 [ 4 ] << 8 | V_362 [ 5 ] ;
T_4 V_364 = V_362 [ 2 ] << 8 | V_362 [ 3 ] ;
T_4 V_365 = V_362 [ 0 ] << 8 | V_362 [ 1 ] ;
if ( V_375 >= F_117 ( V_4 ) )
return - V_21 ;
if ( V_4 -> V_87 & V_366 ) {
F_9 ( F_119 ( V_375 ) , V_363 ) ;
F_9 ( F_120 ( V_375 ) , V_364 ) ;
F_9 ( F_121 ( V_375 ) , V_365 ) ;
} else {
F_9 ( F_122 ( V_375 ) , V_363 ) ;
F_9 ( F_123 ( V_375 ) , V_364 ) ;
F_9 ( F_124 ( V_375 ) , V_365 ) ;
}
return 0 ;
}
static int F_125 ( struct V_3 * V_4 , int V_375 , int V_14 )
{
unsigned long V_1 ;
T_1 V_2 , V_61 ;
if ( V_375 >= F_117 ( V_4 ) )
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
static void F_126 ( struct V_3 * V_4 , unsigned long V_1 ,
int V_378 , int V_379 )
{
T_1 V_2 = F_6 ( V_1 ) ;
V_2 &= ~ ( V_380 | V_381 ) ;
V_2 |= V_378 ;
if ( V_379 )
V_2 |= V_381 ;
F_9 ( V_1 , V_2 ) ;
}
static int F_127 ( struct V_3 * V_4 ,
int V_382 , int V_383 ,
int V_384 , int V_379 )
{
unsigned long V_1 ;
if ( V_384 & ~ V_380 )
return - V_21 ;
if ( V_4 -> V_87 & V_366 )
V_1 = F_128 ( V_382 ) ;
else
V_1 = F_129 ( V_383 ) ;
F_126 ( V_4 , V_1 , V_384 , V_379 ) ;
return 0 ;
}
static int F_130 ( struct V_3 * V_4 , int V_385 ,
int V_379 )
{
return F_127 ( V_4 , 17 , 0 , V_385 , V_379 ) ;
}
static int F_131 ( struct V_3 * V_4 , int V_385 ,
int V_379 )
{
return F_127 ( V_4 , 16 , 8 , V_385 , V_379 ) ;
}
static int F_132 ( struct V_3 * V_4 , int V_386 ,
int V_385 , int V_379 )
{
if ( V_386 >= F_117 ( V_4 ) )
return - V_21 ;
return F_127 ( V_4 , V_386 , V_386 + 1 , V_385 , V_379 ) ;
}
static T_1 F_133 ( T_1 V_387 )
{
T_1 V_388 ;
T_1 V_389 ;
V_388 = 0x00ff ;
V_389 = 0xff00 ;
if ( F_134 ( V_387 & V_388 ) & 1 )
V_387 |= V_390 ;
else
V_387 &= ~ V_390 ;
if ( F_134 ( V_387 & V_389 ) & 1 )
V_387 |= V_391 ;
else
V_387 &= ~ V_391 ;
return V_387 ;
}
static void F_135 ( struct V_3 * V_4 , unsigned long V_375 ,
int V_30 , int V_392 , int V_393 )
{
T_1 V_387 = F_16 ( F_136 ( V_375 ) ) ;
V_387 &= ~ ( ( V_394 |
V_395 ) <<
F_137 ( V_30 ) ) ;
if ( V_392 )
V_387 |= ( V_394 <<
F_137 ( V_30 ) ) ;
V_387 |= ( V_393 << F_137 ( V_30 ) ) ;
V_387 = F_133 ( V_387 ) ;
F_18 ( F_136 ( V_375 ) , V_387 ) ;
}
static void F_138 ( struct V_3 * V_4 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_396 ; V_26 ++ )
F_18 ( F_136 ( V_26 ) , 0 ) ;
}
static int F_139 ( struct V_3 * V_4 , T_1 V_397 )
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
static int F_140 ( struct V_3 * V_4 , int V_375 )
{
F_18 ( V_399 , 0x00 ) ;
F_18 ( V_400 , 0xff ) ;
F_18 ( V_398 , ( V_401 | V_375 ) ) ;
return F_139 ( V_4 , V_402 ) ;
}
static int F_141 ( struct V_3 * V_4 , int V_375 ,
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
return F_139 ( V_4 , V_402 ) ;
}
static int F_142 ( struct V_3 * V_4 , int V_375 , T_1 V_410 )
{
F_18 ( V_404 , V_410 ) ;
F_18 ( V_398 , ( V_411 | V_375 ) ) ;
return F_139 ( V_4 , V_402 ) ;
}
static void F_143 ( struct V_3 * V_4 , int V_14 )
{
T_1 V_2 = F_16 ( V_412 ) ;
if ( V_14 )
V_2 &= ~ V_413 ;
else
V_2 |= V_413 ;
F_18 ( V_412 , V_2 ) ;
}
static void F_144 ( struct V_3 * V_4 , T_1 V_414 , T_1 V_415 )
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
static int F_145 ( struct V_3 * V_4 , unsigned long V_421 ,
int V_14 )
{
unsigned long V_1 ;
T_1 V_2 ;
if ( V_421 < V_422 ||
V_421 > V_423 )
return - V_21 ;
V_1 = F_146 ( V_421 - V_422 ) ;
V_2 = F_16 ( V_1 ) ;
if ( V_14 )
V_2 |= V_424 ;
else
V_2 &= ~ V_424 ;
F_18 ( V_1 , V_2 ) ;
return 0 ;
}
static int F_147 ( struct V_3 * V_4 , unsigned long V_421 ,
int V_14 )
{
unsigned long V_1 ;
T_1 V_2 ;
if ( V_421 < V_425 ||
V_421 > V_426 )
return - V_21 ;
V_1 = F_148 ( V_421 - V_425 ) ;
V_2 = F_16 ( V_1 ) ;
if ( V_14 )
V_2 |= V_427 ;
else
V_2 &= ~ V_427 ;
F_18 ( V_1 , V_2 ) ;
return 0 ;
}
static int F_149 ( struct V_3 * V_4 , unsigned long V_421 ,
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
V_1 = F_148 ( V_421 - V_425 ) ;
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
static int F_150 ( struct V_3 * V_4 )
{
unsigned long V_26 ;
int V_10 ;
F_143 ( V_4 , 0 ) ;
F_144 ( V_4 ,
V_439 ,
V_440 ) ;
for ( V_26 = V_422 ; V_26 <= V_423 ; V_26 ++ ) {
V_10 = F_145 ( V_4 , V_26 , 0 ) ;
if ( V_10 )
return V_10 ;
}
for ( V_26 = V_425 ; V_26 <= V_426 ; V_26 ++ ) {
V_10 = F_147 ( V_4 , V_26 , 0 ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
static int F_151 ( struct V_3 * V_4 )
{
unsigned long V_26 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_25 -> V_441 ; V_26 ++ ) {
int V_10 = F_140 ( V_4 , V_26 ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
static T_1 F_152 ( unsigned long V_375 , unsigned long V_442 )
{
return ( T_1 ) V_375 | ( V_442 == 1 ? V_443 : 0 ) ;
}
static int F_153 ( struct V_3 * V_4 , unsigned long V_444 ,
unsigned long V_375 , unsigned long V_442 ,
T_1 * V_35 )
{
T_1 V_2 = F_152 ( V_375 , V_442 ) ;
unsigned long V_26 ;
if ( V_444 >= V_445 ||
V_375 + ( V_442 * 8 ) > V_446 )
return - V_21 ;
F_18 ( F_154 ( V_444 ) , V_2 ) ;
for ( V_26 = 0 ; V_26 < V_442 ; V_26 ++ )
F_18 ( F_155 ( V_444 ) , V_35 [ V_26 ] ) ;
return 0 ;
}
static void F_156 ( struct V_3 * V_4 )
{
T_1 V_2 ;
F_18 ( V_412 , V_447 ) ;
F_7 ( 10 ) ;
F_18 ( V_412 , 0 ) ;
V_2 = V_448 | V_416 ;
F_18 ( V_412 , V_2 ) ;
}
static void F_157 ( struct V_3 * V_4 )
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
static int F_158 ( struct V_3 * V_4 , T_1 V_444 ,
T_1 V_61 , T_1 V_458 , int V_459 )
{
unsigned long V_1 ;
T_1 V_2 ;
if ( V_444 >= V_445 ||
( V_61 & ~ ( T_1 ) 0x1f ) != 0 ||
( V_458 & ~ ( T_1 ) 0x1f ) != 0 )
return - V_21 ;
V_1 = F_159 ( V_444 ) ;
V_2 = F_16 ( V_1 ) ;
V_2 &= ~ ( V_460 | V_461 | V_462 ) ;
V_2 |= ( V_61 << V_463 ) ;
V_2 |= ( V_458 << V_464 ) ;
if ( V_459 )
V_2 |= V_460 ;
F_18 ( V_1 , V_2 ) ;
return 0 ;
}
static int F_160 ( struct V_3 * V_4 )
{
unsigned long V_26 ;
for ( V_26 = 0 ; V_26 < V_445 ; V_26 ++ ) {
int V_10 = F_158 ( V_4 , 0 , 0 , 0 , 0 ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
static void F_161 ( struct V_3 * V_4 , int V_14 )
{
T_1 V_2 = F_16 ( V_412 ) ;
if ( V_14 )
V_2 |= V_465 ;
else
V_2 &= ~ V_465 ;
F_18 ( V_412 , V_2 ) ;
}
static void F_162 ( struct V_3 * V_4 , int V_14 )
{
T_1 V_2 = F_16 ( V_412 ) ;
if ( V_14 )
V_2 &= ~ V_466 ;
else
V_2 |= V_466 ;
F_18 ( V_412 , V_2 ) ;
}
static int F_163 ( struct V_3 * V_4 )
{
struct V_467 V_468 ;
unsigned long V_26 ;
memset ( & V_468 , 0 , sizeof( V_468 ) ) ;
V_468 . V_469 = V_470 ;
for ( V_26 = 0 ; V_26 < V_446 ; V_26 += sizeof( V_468 ) ) {
int V_10 = F_153 ( V_4 , 0 , V_26 , 1 , ( T_1 * ) & V_468 ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
static int F_164 ( struct V_3 * V_4 )
{
struct V_24 * V_25 ;
unsigned long V_87 ;
int V_10 ;
F_165 ( V_4 , V_87 ) ;
V_25 = V_4 -> V_25 ;
V_10 = 0 ;
if ( ! ( V_25 -> V_87 & V_471 ) ) {
if ( V_4 -> V_25 -> V_339 != V_343 ) {
F_156 ( V_4 ) ;
F_157 ( V_4 ) ;
V_10 = F_160 ( V_4 ) ;
if ( V_10 ) {
F_166 ( V_4 , V_472 , V_473 , V_4 -> V_11 ,
L_24 ,
V_10 ) ;
goto V_217;
}
}
V_10 = F_150 ( V_4 ) ;
if ( V_10 ) {
F_166 ( V_4 , V_472 , V_473 , V_4 -> V_11 ,
L_25 , V_10 ) ;
goto V_217;
}
F_161 ( V_4 , 1 ) ;
F_162 ( V_4 , 0 ) ;
F_18 ( V_474 , 0 ) ;
F_18 ( V_475 , 0 ) ;
V_10 = F_151 ( V_4 ) ;
if ( V_10 ) {
F_166 ( V_4 , V_472 , V_473 , V_4 -> V_11 ,
L_26 , V_10 ) ;
goto V_217;
}
if ( V_4 -> V_25 -> V_339 != V_343 ) {
V_10 = F_163 ( V_4 ) ;
if ( V_10 ) {
F_166 ( V_4 , V_472 , V_473 , V_4 -> V_11 ,
L_27 ,
V_10 ) ;
goto V_217;
}
}
F_138 ( V_4 ) ;
V_25 -> V_87 |= V_471 ;
}
V_217:
F_167 ( V_4 , V_87 ) ;
return V_10 ;
}
static int F_168 ( struct V_3 * V_4 , unsigned long V_476 , T_1 V_403 )
{
if ( V_476 < V_425 ||
V_476 > V_477 )
return - V_21 ;
F_18 ( F_169 ( V_476 - V_425 ) , V_403 ) ;
return 0 ;
}
static int F_170 ( struct V_3 * V_4 , unsigned long V_476 , T_1 V_403 )
{
if ( V_476 < V_425 ||
V_476 > V_477 )
return - V_21 ;
F_18 ( F_171 ( V_476 - V_425 ) , V_403 ) ;
return 0 ;
}
static T_4 F_172 ( struct V_3 * V_4 , T_4 V_386 )
{
if ( V_386 >= ( V_4 -> V_478 . V_479 - 1 ) )
V_386 = 0 ;
return V_4 -> V_478 . V_480 + ( ( V_386 + 1 ) * V_4 -> V_25 -> V_481 ) ;
}
static T_4 F_173 ( struct V_3 * V_4 )
{
return V_4 -> V_478 . V_479 - 1 ;
}
static T_4 F_174 ( struct V_3 * V_4 )
{
return V_4 -> V_478 . V_482 - 1 ;
}
static void F_175 ( struct V_483 * V_484 , struct V_485 * V_485 ,
T_3 V_486 , T_3 V_487 , T_3 V_488 )
{
F_176 ( V_484 , F_177 ( V_484 ) -> V_489 , V_485 , V_486 , V_487 ) ;
V_484 -> V_490 += V_487 ;
V_484 -> V_491 += V_487 ;
V_484 -> V_488 += V_488 ;
}
static unsigned int F_178 ( struct V_492 * V_493 , T_1 V_494 )
{
V_494 >>= V_495 ;
V_494 ^= ( V_494 >> F_179 ( V_496 ) ) ;
return V_494 & ( V_496 - 1 ) ;
}
static struct V_485 * F_180 ( struct V_492 * V_493 , T_1 V_362 ,
struct V_485 * * * V_309 )
{
unsigned int V_497 = F_178 ( V_493 , V_362 ) ;
struct V_485 * V_498 , * * V_499 ;
V_362 &= V_500 ;
V_499 = & V_493 -> V_501 [ V_497 ] ;
for (; ( V_498 = * V_499 ) != NULL ; V_499 = (struct V_485 * * ) & V_498 -> V_502 ) {
if ( V_498 -> V_375 == V_362 ) {
* V_309 = V_499 ;
goto V_503;
}
}
F_181 () ;
V_503:
return V_498 ;
}
static void F_182 ( struct V_492 * V_493 , struct V_485 * V_485 , T_1 V_458 )
{
unsigned int V_497 = F_178 ( V_493 , V_458 ) ;
V_485 -> V_375 = V_458 ;
V_485 -> V_502 = (struct V_504 * ) V_493 -> V_501 [ V_497 ] ;
V_493 -> V_501 [ V_497 ] = V_485 ;
}
static int F_183 ( struct V_3 * V_4 , struct V_492 * V_493 ,
T_6 V_61 , int V_505 )
{
struct V_485 * V_485 ;
T_1 V_362 ;
int V_26 ;
V_485 = F_184 ( V_61 ) ;
if ( ! V_485 )
return - V_506 ;
V_362 = V_4 -> V_304 -> V_507 ( V_4 -> V_508 , V_485 , 0 ,
V_509 , V_510 ) ;
if ( ! V_362 ) {
F_185 ( V_485 ) ;
return - V_506 ;
}
F_182 ( V_493 , V_485 , V_362 ) ;
if ( V_493 -> V_511 > 1 )
F_186 ( V_493 -> V_511 - 1 ,
& F_187 ( V_485 ) -> V_512 ) ;
for ( V_26 = 0 ; V_26 < V_493 -> V_511 ; V_26 ++ ) {
T_7 * V_513 = & V_493 -> V_513 [ V_505 + V_26 ] ;
* V_513 = F_188 ( V_362 >> V_514 ) ;
V_362 += V_493 -> V_515 ;
}
return 0 ;
}
static void F_189 ( struct V_3 * V_4 , struct V_492 * V_493 , T_6 V_61 )
{
int V_375 = V_493 -> V_516 ;
V_493 -> V_517 ++ ;
if ( ( V_493 -> V_517 % V_493 -> V_511 ) == 0 ) {
int V_10 = F_183 ( V_4 , V_493 , V_61 , V_375 ) ;
if ( F_70 ( V_10 ) ) {
V_493 -> V_517 -- ;
return;
}
V_493 -> V_516 += V_493 -> V_511 ;
F_190 ( V_493 -> V_516 > V_493 -> V_518 ) ;
if ( V_493 -> V_516 == V_493 -> V_518 )
V_493 -> V_516 = 0 ;
if ( V_493 -> V_517 >= V_493 -> V_519 ) {
F_18 ( F_191 ( V_493 -> V_520 ) , V_493 -> V_517 ) ;
V_493 -> V_517 = 0 ;
}
}
}
static int F_192 ( struct V_3 * V_4 , struct V_492 * V_493 )
{
unsigned int V_375 = V_493 -> V_521 ;
int V_522 = 0 ;
V_493 -> V_523 ++ ;
while ( 1 ) {
struct V_485 * V_485 , * * V_309 ;
T_1 V_362 , V_2 ;
T_3 V_524 ;
V_522 ++ ;
V_2 = F_193 ( & V_493 -> V_525 [ V_375 ] ) ;
V_362 = ( V_2 & V_526 ) <<
V_527 ;
V_485 = F_180 ( V_493 , V_362 , & V_309 ) ;
V_524 = V_493 -> V_528 [ ( V_2 & V_529 ) >>
V_530 ] ;
if ( ( V_485 -> V_375 + V_509 ) - V_524 == V_362 ) {
* V_309 = (struct V_485 * ) V_485 -> V_502 ;
V_4 -> V_304 -> V_531 ( V_4 -> V_508 , V_485 -> V_375 ,
V_509 , V_510 ) ;
V_485 -> V_375 = 0 ;
V_485 -> V_502 = NULL ;
F_185 ( V_485 ) ;
V_493 -> V_532 ++ ;
}
V_375 = F_194 ( V_493 , V_375 ) ;
if ( ! ( V_2 & V_533 ) )
break;
}
V_493 -> V_521 = V_375 ;
return V_522 ;
}
static int F_195 ( struct V_534 * V_535 , struct V_3 * V_4 ,
struct V_492 * V_493 )
{
unsigned int V_375 = V_493 -> V_521 ;
struct V_536 * V_537 ;
struct V_483 * V_484 ;
int V_490 , V_522 ;
V_484 = F_196 ( V_4 -> V_11 , V_538 ) ;
if ( F_70 ( ! V_484 ) )
return F_192 ( V_4 , V_493 ) ;
V_522 = 0 ;
while ( 1 ) {
struct V_485 * V_485 , * * V_309 ;
T_3 V_524 , V_539 ;
T_1 V_362 , V_2 , V_335 ;
V_522 ++ ;
V_2 = F_193 ( & V_493 -> V_525 [ V_375 ] ) ;
V_490 = ( V_2 & V_540 ) >>
V_541 ;
V_490 -= V_542 ;
V_362 = ( V_2 & V_526 ) <<
V_527 ;
V_485 = F_180 ( V_493 , V_362 , & V_309 ) ;
V_524 = V_493 -> V_528 [ ( V_2 & V_529 ) >>
V_530 ] ;
V_335 = V_362 & ~ V_500 ;
V_539 = V_524 ;
if ( V_522 == 1 ) {
int V_543 ;
V_543 = ( V_2 >> V_544 ) ;
if ( ( V_543 == V_545 ||
V_543 == V_546 ) &&
! ( V_2 & ( V_547 |
V_548 ) ) )
V_484 -> V_549 = V_550 ;
else
F_197 ( V_484 ) ;
} else if ( ! ( V_2 & V_533 ) )
V_539 = V_490 - V_484 -> V_490 ;
F_175 ( V_484 , V_485 , V_335 , V_539 , V_524 ) ;
if ( ( V_485 -> V_375 + V_493 -> V_515 ) - V_524 == V_362 ) {
* V_309 = (struct V_485 * ) V_485 -> V_502 ;
V_4 -> V_304 -> V_531 ( V_4 -> V_508 , V_485 -> V_375 ,
V_509 , V_510 ) ;
V_485 -> V_375 = 0 ;
V_485 -> V_502 = NULL ;
V_493 -> V_532 ++ ;
} else
F_198 ( V_485 ) ;
V_375 = F_194 ( V_493 , V_375 ) ;
if ( ! ( V_2 & V_533 ) )
break;
}
V_493 -> V_521 = V_375 ;
V_490 += sizeof( * V_537 ) ;
V_490 = F_199 ( int , V_490 , sizeof( * V_537 ) + V_551 ) ;
F_200 ( V_484 , V_490 ) ;
V_537 = (struct V_536 * ) V_484 -> V_35 ;
if ( V_4 -> V_11 -> V_552 & V_553 )
V_484 -> V_501 = ( ( T_3 ) V_537 -> V_554 << 24 |
( T_3 ) V_537 -> V_555 << 16 |
( T_3 ) V_537 -> V_556 << 8 |
( T_3 ) V_537 -> V_557 << 0 ) ;
F_201 ( V_484 , sizeof( * V_537 ) ) ;
V_493 -> V_558 ++ ;
V_493 -> V_559 += V_484 -> V_490 ;
V_484 -> V_560 = F_202 ( V_484 , V_4 -> V_11 ) ;
F_203 ( V_484 , V_493 -> V_520 ) ;
F_204 ( V_535 , V_484 ) ;
return V_522 ;
}
static int F_205 ( struct V_3 * V_4 , struct V_492 * V_493 , T_6 V_61 )
{
int V_561 = V_493 -> V_511 ;
int V_10 , V_375 = V_493 -> V_516 ;
V_10 = 0 ;
while ( V_375 < ( V_493 -> V_518 - V_561 ) ) {
V_10 = F_183 ( V_4 , V_493 , V_61 , V_375 ) ;
if ( F_70 ( V_10 ) )
break;
V_375 += V_561 ;
}
V_493 -> V_516 = V_375 ;
return V_10 ;
}
static void F_206 ( struct V_3 * V_4 , struct V_492 * V_493 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_496 ; V_26 ++ ) {
struct V_485 * V_485 ;
V_485 = V_493 -> V_501 [ V_26 ] ;
while ( V_485 ) {
struct V_485 * V_562 = (struct V_485 * ) V_485 -> V_502 ;
T_1 V_458 = V_485 -> V_375 ;
V_4 -> V_304 -> V_531 ( V_4 -> V_508 , V_458 , V_509 ,
V_510 ) ;
V_485 -> V_375 = 0 ;
V_485 -> V_502 = NULL ;
F_185 ( V_485 ) ;
V_485 = V_562 ;
}
}
for ( V_26 = 0 ; V_26 < V_493 -> V_518 ; V_26 ++ )
V_493 -> V_513 [ V_26 ] = F_188 ( 0 ) ;
V_493 -> V_516 = 0 ;
}
static int F_207 ( struct V_3 * V_4 , struct V_563 * V_493 , int V_386 )
{
struct V_564 * V_565 = & V_493 -> V_566 [ V_386 ] ;
struct V_483 * V_484 = V_565 -> V_484 ;
struct V_567 * V_341 ;
T_1 V_568 ;
int V_26 , V_490 ;
V_341 = (struct V_567 * ) V_484 -> V_35 ;
V_568 = F_193 ( & V_341 -> V_87 ) ;
V_493 -> V_569 ++ ;
V_493 -> V_570 += ( ( ( V_568 & V_571 ) >> V_572 ) -
( ( V_568 & V_573 ) / 2 ) ) ;
V_490 = F_208 ( V_484 ) ;
V_4 -> V_304 -> V_574 ( V_4 -> V_508 , V_565 -> V_502 ,
V_490 , V_575 ) ;
if ( F_209 ( V_493 -> V_576 [ V_386 ] ) & V_577 )
V_493 -> V_578 -- ;
V_565 -> V_484 = NULL ;
do {
V_386 = F_210 ( V_493 , V_386 ) ;
V_490 -= V_579 ;
} while ( V_490 > 0 );
for ( V_26 = 0 ; V_26 < F_177 ( V_484 ) -> V_489 ; V_26 ++ ) {
V_565 = & V_493 -> V_566 [ V_386 ] ;
F_190 ( V_565 -> V_484 != NULL ) ;
V_4 -> V_304 -> V_531 ( V_4 -> V_508 , V_565 -> V_502 ,
F_211 ( & F_177 ( V_484 ) -> V_580 [ V_26 ] ) ,
V_575 ) ;
V_386 = F_210 ( V_493 , V_386 ) ;
}
F_212 ( V_484 ) ;
return V_386 ;
}
static void F_213 ( struct V_3 * V_4 , struct V_563 * V_493 )
{
struct V_581 * V_582 ;
T_4 V_583 , V_584 ;
int V_585 , V_375 ;
T_1 V_586 ;
V_375 = ( V_493 - V_4 -> V_587 ) ;
V_582 = F_214 ( V_4 -> V_11 , V_375 ) ;
V_586 = V_493 -> V_588 ;
if ( F_70 ( ! ( V_586 & ( V_589 | V_590 ) ) ) )
goto V_217;
V_584 = V_583 = ( V_586 & V_591 ) >> V_592 ;
V_583 = ( V_583 - V_493 -> V_593 ) &
( V_591 >> V_592 ) ;
V_493 -> V_593 = V_584 ;
V_585 = V_493 -> V_585 ;
F_166 ( V_4 , V_594 , V_473 , V_4 -> V_11 ,
L_28 , V_67 , V_583 , V_585 ) ;
while ( V_583 -- )
V_585 = F_207 ( V_4 , V_493 , V_585 ) ;
V_493 -> V_585 = V_585 ;
F_215 () ;
V_217:
if ( F_70 ( F_216 ( V_582 ) &&
( F_217 ( V_493 ) > F_218 ( V_493 ) ) ) ) {
F_219 ( V_582 , F_220 () ) ;
if ( F_216 ( V_582 ) &&
( F_217 ( V_493 ) > F_218 ( V_493 ) ) )
F_221 ( V_582 ) ;
F_222 ( V_582 ) ;
}
}
static inline void F_223 ( struct V_3 * V_4 ,
struct V_492 * V_493 ,
const int V_6 )
{
int V_520 = V_493 -> V_520 ;
T_3 V_595 , V_596 ;
V_595 = F_16 ( F_224 ( V_520 ) ) ;
if ( F_70 ( ( V_595 & V_597 ) > V_6 ) ) {
F_18 ( F_224 ( V_520 ) , 0 ) ;
V_493 -> V_598 += V_595 & V_597 ;
if ( F_70 ( V_595 & V_599 ) )
F_225 ( V_4 -> V_508 , L_29 ,
V_520 ) ;
F_166 ( V_4 , V_600 , V_473 , V_4 -> V_11 ,
L_30 ,
V_520 , V_595 , V_595 - V_6 ) ;
}
V_596 = F_16 ( F_226 ( V_520 ) ) ;
if ( F_70 ( ( V_596 & V_601 ) > V_6 ) ) {
F_18 ( F_226 ( V_520 ) , 0 ) ;
V_493 -> V_523 += V_596 & V_601 ;
if ( F_70 ( V_596 & V_602 ) )
F_225 ( V_4 -> V_508 , L_31 , V_520 ) ;
F_166 ( V_4 , V_600 , V_473 , V_4 -> V_11 ,
L_32 ,
V_520 , V_596 , V_596 - V_6 ) ;
}
}
static int F_227 ( struct V_534 * V_535 , struct V_3 * V_4 ,
struct V_492 * V_493 , int V_603 )
{
int V_604 , V_605 = 0 , V_606 = 0 ;
struct V_607 * V_608 = V_493 -> V_608 ;
T_1 V_609 ;
#if 1
V_609 = F_16 ( F_228 ( V_493 -> V_520 ) ) ;
V_604 = F_16 ( F_229 ( V_493 -> V_520 ) ) & V_610 ;
#else
V_609 = F_193 ( & V_608 -> V_611 ) ;
V_604 = ( F_193 ( & V_608 -> V_612 ) & V_610 ) ;
#endif
V_608 -> V_611 = 0 ;
V_608 -> V_612 = 0 ;
F_166 ( V_4 , V_613 , V_473 , V_4 -> V_11 ,
L_33 ,
V_67 , V_493 -> V_520 , ( unsigned long long ) V_609 , V_604 ) ;
V_605 = V_606 = 0 ;
V_604 = F_230 ( V_604 , V_603 ) ;
while ( V_606 < V_604 ) {
V_605 += F_195 ( V_535 , V_4 , V_493 ) ;
V_606 ++ ;
}
if ( V_493 -> V_532 >= V_493 -> V_519 ) {
unsigned int V_26 ;
for ( V_26 = 0 ; V_26 < V_493 -> V_532 ; V_26 ++ )
F_189 ( V_4 , V_493 , V_614 ) ;
V_493 -> V_532 = 0 ;
}
V_609 = ( V_615 |
( ( T_1 ) V_606 << V_616 ) |
( ( T_1 ) V_605 << V_617 ) ) ;
F_18 ( F_228 ( V_493 -> V_520 ) , V_609 ) ;
if ( V_604 > 10 )
F_223 ( V_4 , V_493 , 0x7FFF ) ;
return V_606 ;
}
static int F_231 ( struct V_3 * V_4 , struct V_12 * V_13 , int V_603 )
{
T_1 V_618 = V_13 -> V_618 ;
T_3 V_619 = ( V_618 >> 32 ) ;
T_3 V_620 = ( V_618 & 0xffffffff ) ;
int V_26 , V_606 = 0 ;
F_166 ( V_4 , V_621 , V_473 , V_4 -> V_11 ,
L_34 , V_67 , ( unsigned long long ) V_618 ) ;
for ( V_26 = 0 ; V_26 < V_4 -> V_622 ; V_26 ++ ) {
struct V_563 * V_493 = & V_4 -> V_587 [ V_26 ] ;
if ( V_619 & ( 1 << V_493 -> V_623 ) )
F_213 ( V_4 , V_493 ) ;
F_18 ( F_22 ( F_232 ( V_493 -> V_623 ) ) , 0 ) ;
}
for ( V_26 = 0 ; V_26 < V_4 -> V_624 ; V_26 ++ ) {
struct V_492 * V_493 = & V_4 -> V_625 [ V_26 ] ;
if ( V_620 & ( 1 << V_493 -> V_520 ) ) {
int V_626 ;
V_626 = F_227 ( & V_13 -> V_535 , V_4 , V_493 ,
V_603 ) ;
V_603 -= V_626 ;
V_606 += V_626 ;
}
F_18 ( F_22 ( F_233 ( V_493 -> V_520 ) ) , 0 ) ;
}
return V_606 ;
}
static int F_234 ( struct V_534 * V_535 , int V_603 )
{
struct V_12 * V_13 = F_235 ( V_535 , struct V_12 , V_535 ) ;
struct V_3 * V_4 = V_13 -> V_4 ;
int V_606 ;
V_606 = F_231 ( V_4 , V_13 , V_603 ) ;
if ( V_606 < V_603 ) {
F_236 ( V_535 ) ;
F_19 ( V_4 , V_13 , 1 ) ;
}
return V_606 ;
}
static void F_237 ( struct V_3 * V_4 , struct V_492 * V_493 ,
T_1 V_609 )
{
F_10 ( V_4 -> V_11 , L_35 , V_493 -> V_520 ) ;
if ( V_609 & V_627 )
F_238 ( L_36 ) ;
if ( V_609 & V_628 )
F_238 ( L_37 ) ;
if ( V_609 & V_629 )
F_238 ( L_38 ) ;
if ( V_609 & V_630 )
F_238 ( L_39 ) ;
if ( V_609 & V_631 )
F_238 ( L_40 ) ;
if ( V_609 & V_632 )
F_238 ( L_41 ) ;
if ( V_609 & V_633 )
F_238 ( L_42 ) ;
if ( V_609 & V_634 )
F_238 ( L_43 ) ;
if ( V_609 & V_635 )
F_238 ( L_44 ) ;
if ( V_609 & V_636 )
F_238 ( L_45 ) ;
if ( V_609 & V_637 )
F_238 ( L_46 ) ;
if ( V_609 & V_638 )
F_238 ( L_47 ) ;
if ( V_609 & V_639 )
F_238 ( L_48 ) ;
if ( V_609 & V_640 )
F_238 ( L_49 ) ;
F_238 ( L_50 ) ;
}
static int F_239 ( struct V_3 * V_4 , struct V_492 * V_493 )
{
T_1 V_609 = F_16 ( F_228 ( V_493 -> V_520 ) ) ;
int V_10 = 0 ;
if ( V_609 & ( V_641 |
V_642 ) )
V_10 = - V_21 ;
if ( V_10 ) {
F_10 ( V_4 -> V_11 , L_51 ,
V_493 -> V_520 ,
( unsigned long long ) V_609 ) ;
F_237 ( V_4 , V_493 , V_609 ) ;
}
F_18 ( F_228 ( V_493 -> V_520 ) ,
V_609 & V_643 ) ;
return V_10 ;
}
static void F_240 ( struct V_3 * V_4 , struct V_563 * V_493 ,
T_1 V_586 )
{
F_10 ( V_4 -> V_11 , L_52 , V_493 -> V_623 ) ;
if ( V_586 & V_644 )
F_238 ( L_53 ) ;
if ( V_586 & V_645 )
F_238 ( L_54 ) ;
if ( V_586 & V_646 )
F_238 ( L_55 ) ;
if ( V_586 & V_647 )
F_238 ( L_56 ) ;
if ( V_586 & V_648 )
F_238 ( L_57 ) ;
if ( V_586 & V_649 )
F_238 ( L_58 ) ;
if ( V_586 & V_650 )
F_238 ( L_59 ) ;
if ( V_586 & V_651 )
F_238 ( L_60 ) ;
F_238 ( L_50 ) ;
}
static int F_241 ( struct V_3 * V_4 , struct V_563 * V_493 )
{
T_1 V_586 , V_652 , V_653 ;
V_586 = F_16 ( F_242 ( V_493 -> V_623 ) ) ;
V_652 = F_16 ( F_243 ( V_493 -> V_623 ) ) ;
V_653 = F_16 ( F_244 ( V_493 -> V_623 ) ) ;
F_10 ( V_4 -> V_11 , L_61 ,
V_493 -> V_623 ,
( unsigned long long ) V_586 ,
( unsigned long long ) V_652 ,
( unsigned long long ) V_653 ) ;
F_240 ( V_4 , V_493 , V_586 ) ;
return - V_8 ;
}
static int F_245 ( struct V_3 * V_4 )
{
T_1 V_654 = F_16 ( V_655 ) ;
int V_656 = 0 ;
if ( V_4 -> V_87 & V_366 ) {
T_1 V_657 = F_6 ( V_658 ) ;
if ( V_657 & V_659 )
V_656 = 1 ;
}
F_10 ( V_4 -> V_11 , L_62 ,
( unsigned long long ) V_654 , V_656 ) ;
return - V_8 ;
}
static void F_246 ( struct V_3 * V_4 )
{
struct V_660 * V_661 = & V_4 -> V_662 . V_663 ;
T_1 V_2 ;
V_2 = F_6 ( V_664 ) ;
if ( V_2 & V_665 )
V_661 -> V_666 += V_667 ;
if ( V_2 & V_668 )
V_661 -> V_570 += V_669 ;
if ( V_2 & V_670 )
V_661 -> V_671 ++ ;
if ( V_2 & V_672 )
V_661 -> V_673 ++ ;
if ( V_2 & V_674 )
V_661 -> V_675 ++ ;
if ( V_2 & V_676 )
V_661 -> V_677 ++ ;
V_2 = F_6 ( V_658 ) ;
if ( V_2 & V_678 )
V_661 -> V_679 ++ ;
if ( V_2 & V_680 )
V_661 -> V_681 ++ ;
if ( V_2 & V_682 )
V_661 -> V_683 += V_684 ;
if ( V_2 & V_685 )
V_661 -> V_686 += V_687 ;
if ( V_2 & V_688 )
V_661 -> V_689 += V_690 ;
if ( V_2 & V_691 )
V_661 -> V_692 += V_693 ;
if ( V_2 & V_694 )
V_661 -> V_695 += V_696 ;
if ( V_2 & V_694 )
V_661 -> V_695 += V_696 ;
if ( V_2 & V_697 )
V_661 -> V_698 += V_699 ;
if ( V_2 & V_700 )
V_661 -> V_701 += V_702 ;
if ( V_2 & V_703 )
V_661 -> V_704 += V_705 ;
if ( V_2 & V_706 )
V_661 -> V_707 += V_708 ;
if ( V_2 & V_709 )
V_661 -> V_710 += V_711 ;
if ( V_2 & V_712 )
V_661 -> V_713 += V_714 ;
if ( V_2 & V_715 )
V_661 -> V_716 += V_717 ;
if ( V_2 & V_718 )
V_661 -> V_719 += V_720 ;
if ( V_2 & V_721 )
V_661 -> V_722 += V_723 ;
if ( V_2 & V_724 )
V_661 -> V_725 += V_726 ;
if ( V_2 & V_727 )
V_661 -> V_728 += V_729 ;
if ( V_2 & V_730 )
V_661 -> V_731 ++ ;
if ( V_2 & V_732 )
V_661 -> V_733 ++ ;
V_2 = F_6 ( V_734 ) ;
if ( V_2 & V_735 )
V_661 -> V_736 ++ ;
if ( V_2 & V_737 )
V_661 -> V_738 ++ ;
if ( V_2 & V_739 )
V_661 -> V_740 ++ ;
}
static void F_247 ( struct V_3 * V_4 )
{
struct V_741 * V_661 = & V_4 -> V_662 . V_742 ;
T_1 V_2 ;
V_2 = F_6 ( V_743 ) ;
if ( V_2 & V_744 )
V_661 -> V_677 ++ ;
if ( V_2 & V_745 )
V_661 -> V_675 ++ ;
if ( V_2 & V_746 )
V_661 -> V_570 += V_747 ;
if ( V_2 & V_748 )
V_661 -> V_666 += V_749 ;
V_2 = F_6 ( V_750 ) ;
if ( V_2 & V_751 )
V_661 -> V_733 ++ ;
if ( V_2 & V_752 )
V_661 -> V_753 += V_754 ;
if ( V_2 & V_755 )
V_661 -> V_686 += V_756 ;
if ( V_2 & V_757 )
V_661 -> V_728 += V_756 ;
if ( V_2 & V_758 )
V_661 -> V_725 += V_759 ;
V_2 = F_6 ( V_760 ) ;
if ( V_2 & V_761 )
V_661 -> V_736 ++ ;
if ( V_2 & V_762 )
V_661 -> V_738 ++ ;
if ( V_2 & V_763 )
V_661 -> V_740 ++ ;
}
static int F_248 ( struct V_3 * V_4 )
{
if ( V_4 -> V_87 & V_366 )
F_246 ( V_4 ) ;
else
F_247 ( V_4 ) ;
return 0 ;
}
static void F_249 ( struct V_3 * V_4 , T_1 V_609 )
{
F_10 ( V_4 -> V_11 , L_63 ) ;
if ( V_609 & V_764 )
F_238 ( L_64 ) ;
if ( V_609 & V_765 )
F_238 ( L_65 ) ;
if ( V_609 & V_766 )
F_238 ( L_66 ) ;
if ( V_609 & V_767 )
F_238 ( L_67 ) ;
if ( V_609 & V_768 )
F_238 ( L_68 ) ;
if ( V_609 & V_769 )
F_238 ( L_69 ) ;
if ( V_609 & V_770 )
F_238 ( L_70 ) ;
if ( V_609 & V_771 )
F_238 ( L_71 ) ;
if ( V_609 & V_772 )
F_238 ( L_72 ) ;
if ( V_609 & V_773 )
F_238 ( L_73 ) ;
if ( V_609 & V_774 )
F_238 ( L_74 ) ;
F_238 ( L_50 ) ;
}
static int F_250 ( struct V_3 * V_4 )
{
T_1 V_609 = F_16 ( V_775 ) ;
F_10 ( V_4 -> V_11 , L_75 ,
( unsigned long long ) V_609 ) ;
F_249 ( V_4 , V_609 ) ;
return - V_8 ;
}
static int F_251 ( struct V_3 * V_4 , struct V_12 * V_13 ,
T_1 V_618 , T_1 V_776 , T_1 V_777 )
{
int V_26 , V_10 = 0 ;
V_13 -> V_618 = V_618 ;
V_13 -> V_776 = V_776 ;
V_13 -> V_777 = V_777 ;
if ( V_776 & 0x00000000ffffffffULL ) {
T_3 V_620 = ( V_776 & 0xffffffff ) ;
for ( V_26 = 0 ; V_26 < V_4 -> V_624 ; V_26 ++ ) {
struct V_492 * V_493 = & V_4 -> V_625 [ V_26 ] ;
if ( V_620 & ( 1 << V_493 -> V_520 ) ) {
int V_778 = F_239 ( V_4 , V_493 ) ;
if ( V_778 ) {
V_10 = V_778 ;
} else {
if ( ! V_618 )
F_18 ( F_228 ( V_493 -> V_520 ) ,
V_615 ) ;
}
}
}
}
if ( V_776 & 0x7fffffff00000000ULL ) {
T_3 V_619 = ( V_776 >> 32 ) & 0x7fffffff ;
for ( V_26 = 0 ; V_26 < V_4 -> V_622 ; V_26 ++ ) {
struct V_563 * V_493 = & V_4 -> V_587 [ V_26 ] ;
if ( V_619 & ( 1 << V_493 -> V_623 ) ) {
int V_778 = F_241 ( V_4 , V_493 ) ;
if ( V_778 )
V_10 = V_778 ;
}
}
}
if ( ( V_618 | V_776 ) & 0x8000000000000000ULL ) {
int V_778 = F_245 ( V_4 ) ;
if ( V_778 )
V_10 = V_778 ;
}
if ( V_777 ) {
if ( V_777 & 0x01ef ) {
int V_778 = F_248 ( V_4 ) ;
if ( V_778 )
V_10 = V_778 ;
}
if ( V_777 & 0x0210 ) {
int V_778 = F_250 ( V_4 ) ;
if ( V_778 )
V_10 = V_778 ;
}
}
if ( V_10 )
F_25 ( V_4 , 0 ) ;
return V_10 ;
}
static void F_252 ( struct V_3 * V_4 , struct V_492 * V_493 ,
int V_18 )
{
struct V_607 * V_608 = V_493 -> V_608 ;
T_1 V_779 , V_609 = F_193 ( & V_608 -> V_611 ) ;
V_779 = ( V_780 |
V_781 ) ;
F_18 ( F_228 ( V_493 -> V_520 ) , V_779 ) ;
F_166 ( V_4 , V_621 , V_473 , V_4 -> V_11 ,
L_76 , V_67 , ( unsigned long long ) V_609 ) ;
}
static void F_253 ( struct V_3 * V_4 , struct V_563 * V_493 ,
int V_18 )
{
V_493 -> V_588 = F_16 ( F_242 ( V_493 -> V_623 ) ) ;
F_166 ( V_4 , V_621 , V_473 , V_4 -> V_11 ,
L_77 , V_67 , ( unsigned long long ) V_493 -> V_588 ) ;
}
static void F_254 ( struct V_3 * V_4 , int V_29 , T_1 V_618 )
{
struct V_24 * V_25 = V_4 -> V_25 ;
T_3 V_620 , V_619 ;
int V_26 ;
V_619 = ( V_618 >> 32 ) ;
V_620 = ( V_618 & 0xffffffff ) ;
for ( V_26 = 0 ; V_26 < V_4 -> V_624 ; V_26 ++ ) {
struct V_492 * V_493 = & V_4 -> V_625 [ V_26 ] ;
int V_18 = F_233 ( V_493 -> V_520 ) ;
if ( V_25 -> V_27 [ V_18 ] != V_29 )
continue;
F_18 ( F_22 ( V_18 ) , V_22 ) ;
if ( V_620 & ( 1 << V_493 -> V_520 ) )
F_252 ( V_4 , V_493 , V_18 ) ;
}
for ( V_26 = 0 ; V_26 < V_4 -> V_622 ; V_26 ++ ) {
struct V_563 * V_493 = & V_4 -> V_587 [ V_26 ] ;
int V_18 = F_232 ( V_493 -> V_623 ) ;
if ( V_25 -> V_27 [ V_18 ] != V_29 )
continue;
F_18 ( F_22 ( V_18 ) , V_22 ) ;
if ( V_619 & ( 1 << V_493 -> V_623 ) )
F_253 ( V_4 , V_493 , V_18 ) ;
}
}
static void F_255 ( struct V_3 * V_4 , struct V_12 * V_13 ,
T_1 V_618 , T_1 V_776 , T_1 V_777 )
{
if ( F_71 ( F_256 ( & V_13 -> V_535 ) ) ) {
V_13 -> V_618 = V_618 ;
V_13 -> V_776 = V_776 ;
V_13 -> V_777 = V_777 ;
F_254 ( V_4 , V_13 -> V_17 , V_618 ) ;
F_257 ( & V_13 -> V_535 ) ;
}
}
static T_8 F_258 ( int V_782 , void * V_783 )
{
struct V_12 * V_13 = V_783 ;
struct V_3 * V_4 = V_13 -> V_4 ;
int V_29 = V_13 -> V_17 ;
unsigned long V_87 ;
T_1 V_618 , V_776 , V_777 ;
if ( F_259 ( V_4 ) )
F_260 (KERN_DEBUG KBUILD_MODNAME L_78 L_79 ,
__func__, lp, ldg) ;
F_63 ( & V_4 -> V_155 , V_87 ) ;
V_618 = F_16 ( F_261 ( V_29 ) ) ;
V_776 = F_16 ( F_262 ( V_29 ) ) ;
V_777 = F_16 ( F_263 ( V_29 ) ) ;
if ( F_259 ( V_4 ) )
F_238 ( L_80 ,
( unsigned long long ) V_618 ,
( unsigned long long ) V_776 ,
( unsigned long long ) V_777 ) ;
if ( F_70 ( ! V_618 && ! V_776 && ! V_777 ) ) {
F_65 ( & V_4 -> V_155 , V_87 ) ;
return V_784 ;
}
if ( F_70 ( ( V_618 & ( ( T_1 ) 1 << V_785 ) ) || V_776 || V_777 ) ) {
int V_10 = F_251 ( V_4 , V_13 , V_618 , V_776 , V_777 ) ;
if ( V_10 )
goto V_217;
}
if ( F_71 ( V_618 & ~ ( ( T_1 ) 1 << V_785 ) ) )
F_255 ( V_4 , V_13 , V_618 , V_776 , V_777 ) ;
else
F_19 ( V_4 , V_13 , 1 ) ;
V_217:
F_65 ( & V_4 -> V_155 , V_87 ) ;
return V_786 ;
}
static void F_264 ( struct V_3 * V_4 , struct V_492 * V_493 )
{
if ( V_493 -> V_608 ) {
V_4 -> V_304 -> V_787 ( V_4 -> V_508 ,
sizeof( struct V_607 ) ,
V_493 -> V_608 , V_493 -> V_788 ) ;
V_493 -> V_608 = NULL ;
}
if ( V_493 -> V_525 ) {
V_4 -> V_304 -> V_787 ( V_4 -> V_508 ,
V_789 * sizeof( V_790 ) ,
V_493 -> V_525 , V_493 -> V_791 ) ;
V_493 -> V_525 = NULL ;
V_493 -> V_792 = 0 ;
V_493 -> V_521 = 0 ;
}
if ( V_493 -> V_513 ) {
F_206 ( V_4 , V_493 ) ;
V_4 -> V_304 -> V_787 ( V_4 -> V_508 ,
V_496 * sizeof( T_7 ) ,
V_493 -> V_513 , V_493 -> V_793 ) ;
V_493 -> V_513 = NULL ;
V_493 -> V_518 = 0 ;
V_493 -> V_516 = 0 ;
}
F_265 ( V_493 -> V_501 ) ;
V_493 -> V_501 = NULL ;
}
static void F_266 ( struct V_3 * V_4 , struct V_563 * V_493 )
{
if ( V_493 -> V_608 ) {
V_4 -> V_304 -> V_787 ( V_4 -> V_508 ,
sizeof( struct V_794 ) ,
V_493 -> V_608 , V_493 -> V_788 ) ;
V_493 -> V_608 = NULL ;
}
if ( V_493 -> V_576 ) {
int V_26 ;
for ( V_26 = 0 ; V_26 < V_795 ; V_26 ++ ) {
if ( V_493 -> V_566 [ V_26 ] . V_484 )
( void ) F_207 ( V_4 , V_493 , V_26 ) ;
}
V_4 -> V_304 -> V_787 ( V_4 -> V_508 ,
V_795 * sizeof( V_790 ) ,
V_493 -> V_576 , V_493 -> V_796 ) ;
V_493 -> V_576 = NULL ;
V_493 -> V_797 = 0 ;
V_493 -> V_798 = 0 ;
V_493 -> V_585 = 0 ;
V_493 -> V_799 = 0 ;
}
}
static void F_267 ( struct V_3 * V_4 )
{
int V_26 ;
if ( V_4 -> V_625 ) {
for ( V_26 = 0 ; V_26 < V_4 -> V_624 ; V_26 ++ ) {
struct V_492 * V_493 = & V_4 -> V_625 [ V_26 ] ;
F_264 ( V_4 , V_493 ) ;
}
F_265 ( V_4 -> V_625 ) ;
V_4 -> V_625 = NULL ;
V_4 -> V_624 = 0 ;
}
if ( V_4 -> V_587 ) {
for ( V_26 = 0 ; V_26 < V_4 -> V_622 ; V_26 ++ ) {
struct V_563 * V_493 = & V_4 -> V_587 [ V_26 ] ;
F_266 ( V_4 , V_493 ) ;
}
F_265 ( V_4 -> V_587 ) ;
V_4 -> V_587 = NULL ;
V_4 -> V_622 = 0 ;
}
}
static int F_268 ( struct V_3 * V_4 ,
struct V_492 * V_493 )
{
F_269 ( sizeof( struct V_607 ) != 64 ) ;
V_493 -> V_501 = F_270 ( V_496 , sizeof( struct V_485 * ) ,
V_800 ) ;
if ( ! V_493 -> V_501 )
return - V_506 ;
V_493 -> V_608 = V_4 -> V_304 -> V_801 ( V_4 -> V_508 ,
sizeof( struct V_607 ) ,
& V_493 -> V_788 , V_800 ) ;
if ( ! V_493 -> V_608 )
return - V_506 ;
if ( ( unsigned long ) V_493 -> V_608 & ( 64UL - 1 ) ) {
F_10 ( V_4 -> V_11 , L_81 ,
V_493 -> V_608 ) ;
return - V_21 ;
}
V_493 -> V_525 = V_4 -> V_304 -> V_801 ( V_4 -> V_508 ,
V_789 * sizeof( V_790 ) ,
& V_493 -> V_791 , V_800 ) ;
if ( ! V_493 -> V_525 )
return - V_506 ;
if ( ( unsigned long ) V_493 -> V_525 & ( 64UL - 1 ) ) {
F_10 ( V_4 -> V_11 , L_82 ,
V_493 -> V_525 ) ;
return - V_21 ;
}
V_493 -> V_792 = V_789 ;
V_493 -> V_521 = 0 ;
V_493 -> V_513 = V_4 -> V_304 -> V_801 ( V_4 -> V_508 ,
V_496 * sizeof( T_7 ) ,
& V_493 -> V_793 , V_800 ) ;
if ( ! V_493 -> V_513 )
return - V_506 ;
if ( ( unsigned long ) V_493 -> V_513 & ( 64UL - 1 ) ) {
F_10 ( V_4 -> V_11 , L_83 ,
V_493 -> V_513 ) ;
return - V_21 ;
}
V_493 -> V_518 = V_496 ;
V_493 -> V_516 = 0 ;
V_493 -> V_517 = 0 ;
return 0 ;
}
static void F_271 ( struct V_3 * V_4 , struct V_563 * V_493 )
{
int V_802 = V_4 -> V_11 -> V_802 ;
V_493 -> V_803 = V_802 + 32 ;
if ( V_493 -> V_803 > 4096 )
V_493 -> V_803 = 4096 ;
}
static int F_272 ( struct V_3 * V_4 ,
struct V_563 * V_493 )
{
F_269 ( sizeof( struct V_794 ) != 64 ) ;
V_493 -> V_608 = V_4 -> V_304 -> V_801 ( V_4 -> V_508 ,
sizeof( struct V_794 ) ,
& V_493 -> V_788 , V_800 ) ;
if ( ! V_493 -> V_608 )
return - V_506 ;
if ( ( unsigned long ) V_493 -> V_608 & ( 64UL - 1 ) ) {
F_10 ( V_4 -> V_11 , L_84 ,
V_493 -> V_608 ) ;
return - V_21 ;
}
V_493 -> V_576 = V_4 -> V_304 -> V_801 ( V_4 -> V_508 ,
V_795 * sizeof( V_790 ) ,
& V_493 -> V_796 , V_800 ) ;
if ( ! V_493 -> V_576 )
return - V_506 ;
if ( ( unsigned long ) V_493 -> V_576 & ( 64UL - 1 ) ) {
F_10 ( V_4 -> V_11 , L_85 ,
V_493 -> V_576 ) ;
return - V_21 ;
}
V_493 -> V_797 = V_795 ;
V_493 -> V_798 = 0 ;
V_493 -> V_585 = 0 ;
V_493 -> V_799 = 0 ;
V_493 -> V_804 = V_493 -> V_797 / 4 ;
F_271 ( V_4 , V_493 ) ;
return 0 ;
}
static void F_273 ( struct V_3 * V_4 , struct V_492 * V_493 )
{
T_4 V_805 ;
V_805 = F_230 ( V_495 , 15 ) ;
V_493 -> V_515 = 1 << V_805 ;
V_493 -> V_511 = 1 << ( V_495 - V_805 ) ;
V_493 -> V_528 [ 0 ] = 256 ;
V_493 -> V_528 [ 1 ] = 1024 ;
if ( V_4 -> V_11 -> V_802 > V_806 ) {
switch ( V_509 ) {
case 4 * 1024 :
V_493 -> V_528 [ 2 ] = 4096 ;
break;
default:
V_493 -> V_528 [ 2 ] = 8192 ;
break;
}
} else {
V_493 -> V_528 [ 2 ] = 2048 ;
}
V_493 -> V_528 [ 3 ] = V_493 -> V_515 ;
}
static int F_274 ( struct V_3 * V_4 )
{
struct V_24 * V_25 = V_4 -> V_25 ;
int V_807 , V_808 ;
int V_624 , V_622 ;
struct V_492 * V_625 ;
struct V_563 * V_587 ;
int V_26 , V_30 , V_10 ;
V_30 = V_4 -> V_30 ;
V_807 = V_808 = 0 ;
for ( V_26 = 0 ; V_26 < V_30 ; V_26 ++ ) {
V_807 += V_25 -> V_809 [ V_26 ] ;
V_808 += V_25 -> V_810 [ V_26 ] ;
}
V_624 = V_25 -> V_809 [ V_30 ] ;
V_622 = V_25 -> V_810 [ V_30 ] ;
V_625 = F_270 ( V_624 , sizeof( struct V_492 ) ,
V_800 ) ;
V_10 = - V_506 ;
if ( ! V_625 )
goto V_811;
V_4 -> V_624 = V_624 ;
F_275 () ;
V_4 -> V_625 = V_625 ;
F_276 ( V_4 -> V_11 , V_624 ) ;
for ( V_26 = 0 ; V_26 < V_4 -> V_624 ; V_26 ++ ) {
struct V_492 * V_493 = & V_4 -> V_625 [ V_26 ] ;
V_493 -> V_4 = V_4 ;
V_493 -> V_520 = V_807 + V_26 ;
V_10 = F_268 ( V_4 , V_493 ) ;
if ( V_10 )
goto V_811;
F_273 ( V_4 , V_493 ) ;
V_493 -> V_812 = 64 ;
V_493 -> V_813 = V_493 -> V_792 - 64 ;
V_493 -> V_814 = 64 ;
V_493 -> V_815 = V_493 -> V_792 - 64 ;
V_493 -> V_816 = 16 ;
V_493 -> V_817 = 8 ;
V_493 -> V_519 = V_818 ;
if ( V_493 -> V_519 < V_493 -> V_511 )
V_493 -> V_519 = V_493 -> V_511 ;
V_10 = F_205 ( V_4 , V_493 , V_800 ) ;
if ( V_10 )
return V_10 ;
}
V_587 = F_270 ( V_622 , sizeof( struct V_563 ) ,
V_800 ) ;
V_10 = - V_506 ;
if ( ! V_587 )
goto V_811;
V_4 -> V_622 = V_622 ;
F_275 () ;
V_4 -> V_587 = V_587 ;
F_277 ( V_4 -> V_11 , V_622 ) ;
for ( V_26 = 0 ; V_26 < V_4 -> V_622 ; V_26 ++ ) {
struct V_563 * V_493 = & V_4 -> V_587 [ V_26 ] ;
V_493 -> V_4 = V_4 ;
V_493 -> V_623 = V_808 + V_26 ;
V_10 = F_272 ( V_4 , V_493 ) ;
if ( V_10 )
goto V_811;
}
return 0 ;
V_811:
F_267 ( V_4 ) ;
return V_10 ;
}
static int F_278 ( struct V_3 * V_4 , int V_36 )
{
int V_6 = 1000 ;
while ( -- V_6 > 0 ) {
T_1 V_2 = F_16 ( F_242 ( V_36 ) ) ;
if ( V_2 & V_819 )
return 0 ;
}
return - V_8 ;
}
static int F_279 ( struct V_3 * V_4 , int V_36 )
{
T_1 V_2 = F_16 ( F_242 ( V_36 ) ) ;
V_2 |= V_820 ;
F_18 ( F_242 ( V_36 ) , V_2 ) ;
return F_278 ( V_4 , V_36 ) ;
}
static int F_280 ( struct V_3 * V_4 , int V_36 )
{
int V_6 = 1000 ;
while ( -- V_6 > 0 ) {
T_1 V_2 = F_16 ( F_242 ( V_36 ) ) ;
if ( ! ( V_2 & V_821 ) )
return 0 ;
}
return - V_8 ;
}
static int F_281 ( struct V_3 * V_4 , int V_36 )
{
T_1 V_2 = F_16 ( F_242 ( V_36 ) ) ;
int V_10 ;
V_2 |= V_821 ;
F_18 ( F_242 ( V_36 ) , V_2 ) ;
V_10 = F_280 ( V_4 , V_36 ) ;
if ( ! V_10 )
F_18 ( F_282 ( V_36 ) , 0 ) ;
return V_10 ;
}
static int F_283 ( struct V_3 * V_4 , int V_36 )
{
T_1 V_2 ;
F_18 ( F_284 ( V_36 ) , 0 ) ;
F_18 ( F_285 ( V_36 ) , 0 ) ;
F_18 ( F_286 ( V_36 ) , 0 ) ;
F_18 ( F_287 ( V_36 ) , 0 ) ;
F_18 ( F_288 ( V_36 ) , 0 ) ;
F_18 ( F_289 ( V_36 ) , 0 ) ;
F_18 ( F_290 ( V_36 ) , 0 ) ;
V_2 = ( T_1 ) V_4 -> V_30 << V_822 ;
V_2 |= ( V_823 | V_824 ) ;
F_18 ( F_291 ( V_36 ) , V_2 ) ;
return 0 ;
}
static void F_292 ( struct V_3 * V_4 , int V_14 )
{
unsigned long V_87 ;
T_1 V_2 , V_61 ;
F_165 ( V_4 , V_87 ) ;
V_2 = F_16 ( V_825 ) ;
V_61 = ( T_1 ) 1 << V_4 -> V_30 ;
if ( V_14 ) {
V_2 |= V_826 | V_61 ;
} else {
V_2 &= ~ V_61 ;
if ( ( V_2 & ~ V_826 ) == 0 )
V_2 &= ~ V_826 ;
}
F_18 ( V_825 , V_2 ) ;
F_167 ( V_4 , V_87 ) ;
}
static void F_293 ( struct V_3 * V_4 , T_1 V_827 )
{
unsigned long V_87 ;
T_1 V_2 ;
F_165 ( V_4 , V_87 ) ;
V_2 = F_16 ( V_828 ) ;
V_2 &= ~ F_294 ( V_4 -> V_30 ) ;
V_2 |= ( V_827 << F_295 ( V_4 -> V_30 ) ) ;
F_167 ( V_4 , V_87 ) ;
}
static void F_296 ( struct V_3 * V_4 , int V_14 )
{
T_1 V_2 = 0 ;
if ( V_14 ) {
int V_26 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_622 ; V_26 ++ )
V_2 |= ( 1 << V_4 -> V_587 [ V_26 ] . V_623 ) ;
}
F_18 ( F_297 ( V_4 -> V_30 ) , V_2 ) ;
}
static int F_298 ( struct V_3 * V_4 , struct V_563 * V_493 )
{
int V_10 , V_36 = V_493 -> V_623 ;
T_1 V_2 , V_829 ;
V_10 = F_279 ( V_4 , V_36 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_281 ( V_4 , V_36 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_283 ( V_4 , V_36 ) ;
if ( V_10 )
return V_10 ;
F_18 ( F_299 ( V_36 ) , V_493 -> V_803 ) ;
F_18 ( F_300 ( V_36 ) , 0 ) ;
if ( V_493 -> V_796 & ~ ( V_830 |
V_831 ) ) {
F_10 ( V_4 -> V_11 , L_86 ,
V_36 , ( unsigned long long ) V_493 -> V_796 ) ;
return - V_21 ;
}
V_829 = ( V_493 -> V_797 / 8 ) ;
V_2 = ( ( V_829 << V_832 ) |
V_493 -> V_796 ) ;
F_18 ( F_301 ( V_36 ) , V_2 ) ;
if ( ( ( V_493 -> V_788 >> 32 ) & ~ V_833 ) ||
( ( T_3 ) V_493 -> V_788 & ~ V_834 ) ) {
F_10 ( V_4 -> V_11 , L_87 ,
V_36 , ( unsigned long long ) V_493 -> V_788 ) ;
return - V_21 ;
}
F_18 ( F_302 ( V_36 ) , V_493 -> V_788 >> 32 ) ;
F_18 ( F_303 ( V_36 ) , V_493 -> V_788 & V_834 ) ;
F_18 ( F_242 ( V_36 ) , 0 ) ;
V_493 -> V_593 = 0 ;
return 0 ;
}
static void F_304 ( struct V_3 * V_4 )
{
struct V_835 * V_341 = & V_4 -> V_25 -> V_836 [ V_4 -> V_30 ] ;
int V_26 , V_837 = V_341 -> V_837 ;
for ( V_26 = 0 ; V_26 < V_341 -> V_838 ; V_26 ++ ) {
struct V_393 * V_839 = & V_341 -> V_840 [ V_26 ] ;
int V_841 = V_837 + V_26 ;
int V_842 ;
for ( V_842 = 0 ; V_842 < V_843 ; V_842 ++ )
F_18 ( F_305 ( V_841 , V_842 ) ,
V_839 -> V_844 [ V_842 ] ) ;
}
F_18 ( F_306 ( V_4 -> V_30 ) , V_4 -> V_25 -> V_845 [ V_4 -> V_30 ] ) ;
}
static void F_307 ( struct V_3 * V_4 )
{
int type = F_27 ( V_4 -> V_25 -> V_275 , V_4 -> V_30 ) ;
T_1 V_2 ;
switch ( type ) {
case V_846 :
V_2 = V_847 ;
break;
case V_848 :
default:
V_2 = V_849 ;
break;
}
F_18 ( F_308 ( V_4 -> V_30 ) , V_2 ) ;
}
static int F_309 ( struct V_3 * V_4 )
{
struct V_24 * V_25 = V_4 -> V_25 ;
struct V_835 * V_341 = & V_25 -> V_836 [ V_4 -> V_30 ] ;
int V_26 , V_10 , V_850 = F_117 ( V_4 ) ;
int V_851 = V_341 -> V_837 ;
V_10 = F_130 ( V_4 , V_851 , 1 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_131 ( V_4 , V_851 , 1 ) ;
if ( V_10 )
return V_10 ;
for ( V_26 = 0 ; V_26 < V_850 ; V_26 ++ ) {
V_10 = F_132 ( V_4 , V_26 , V_851 , 1 ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
static int F_310 ( struct V_3 * V_4 , int V_36 )
{
return F_311 ( V_4 , F_312 ( V_36 ) ,
V_852 , 1000 , 10 ,
L_88 ) ;
}
static int F_313 ( struct V_3 * V_4 , int V_36 )
{
T_1 V_2 ;
F_18 ( F_314 ( V_36 ) , 0 ) ;
F_18 ( F_315 ( V_36 ) , 0 ) ;
F_18 ( F_316 ( V_36 ) , 0 ) ;
F_18 ( F_317 ( V_36 ) , 0 ) ;
F_18 ( F_318 ( V_36 ) , 0 ) ;
F_18 ( F_319 ( V_36 ) , 0 ) ;
F_18 ( F_320 ( V_36 ) , 0 ) ;
V_2 = ( T_1 ) V_4 -> V_30 << V_853 ;
V_2 |= ( V_854 | V_855 ) ;
F_18 ( F_321 ( V_36 ) , V_2 ) ;
return 0 ;
}
static void F_322 ( struct V_3 * V_4 , struct V_492 * V_493 )
{
T_1 V_2 ;
V_2 = ( ( ( T_1 ) V_493 -> V_812 << V_856 ) |
( ( T_1 ) V_493 -> V_813 << V_857 ) |
( ( T_1 ) V_493 -> V_814 << V_858 ) |
( ( T_1 ) V_493 -> V_815 << V_859 ) ) ;
F_18 ( F_323 ( V_493 -> V_520 ) , V_2 ) ;
}
static int F_324 ( struct V_492 * V_493 , T_1 * V_860 )
{
T_1 V_2 = 0 ;
* V_860 = 0 ;
switch ( V_493 -> V_515 ) {
case 4 * 1024 :
V_2 |= ( V_861 << V_862 ) ;
break;
case 8 * 1024 :
V_2 |= ( V_863 << V_862 ) ;
break;
case 16 * 1024 :
V_2 |= ( V_864 << V_862 ) ;
break;
case 32 * 1024 :
V_2 |= ( V_865 << V_862 ) ;
break;
default:
return - V_21 ;
}
V_2 |= V_866 ;
switch ( V_493 -> V_528 [ 2 ] ) {
case 2 * 1024 :
V_2 |= ( V_867 << V_868 ) ;
break;
case 4 * 1024 :
V_2 |= ( V_869 << V_868 ) ;
break;
case 8 * 1024 :
V_2 |= ( V_870 << V_868 ) ;
break;
case 16 * 1024 :
V_2 |= ( V_871 << V_868 ) ;
break;
default:
return - V_21 ;
}
V_2 |= V_872 ;
switch ( V_493 -> V_528 [ 1 ] ) {
case 1 * 1024 :
V_2 |= ( V_873 << V_874 ) ;
break;
case 2 * 1024 :
V_2 |= ( V_875 << V_874 ) ;
break;
case 4 * 1024 :
V_2 |= ( V_876 << V_874 ) ;
break;
case 8 * 1024 :
V_2 |= ( V_877 << V_874 ) ;
break;
default:
return - V_21 ;
}
V_2 |= V_878 ;
switch ( V_493 -> V_528 [ 0 ] ) {
case 256 :
V_2 |= ( V_879 << V_880 ) ;
break;
case 512 :
V_2 |= ( V_881 << V_880 ) ;
break;
case 1 * 1024 :
V_2 |= ( V_882 << V_880 ) ;
break;
case 2 * 1024 :
V_2 |= ( V_883 << V_880 ) ;
break;
default:
return - V_21 ;
}
* V_860 = V_2 ;
return 0 ;
}
static int F_325 ( struct V_3 * V_4 , int V_36 , int V_14 )
{
T_1 V_2 = F_16 ( F_312 ( V_36 ) ) ;
int V_6 ;
if ( V_14 )
V_2 |= V_884 ;
else
V_2 &= ~ V_884 ;
F_18 ( F_312 ( V_36 ) , V_2 ) ;
V_6 = 1000 ;
while ( -- V_6 > 0 ) {
if ( F_16 ( F_312 ( V_36 ) ) & V_885 )
break;
F_7 ( 10 ) ;
}
if ( V_6 <= 0 )
return - V_8 ;
return 0 ;
}
static int F_326 ( struct V_3 * V_4 , struct V_492 * V_493 )
{
int V_10 , V_36 = V_493 -> V_520 ;
T_1 V_2 ;
V_10 = F_310 ( V_4 , V_36 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_313 ( V_4 , V_36 ) ;
if ( V_10 )
return V_10 ;
F_322 ( V_4 , V_493 ) ;
F_18 ( F_327 ( V_36 ) , V_886 ) ;
F_18 ( F_228 ( V_36 ) ,
( V_615 |
V_780 |
V_781 |
V_887 ) ) ;
F_18 ( F_312 ( V_36 ) , V_493 -> V_788 >> 32 ) ;
F_18 ( F_328 ( V_36 ) ,
( ( V_493 -> V_788 & V_888 ) |
V_889 ) ) ;
F_18 ( F_329 ( V_36 ) ,
( ( T_1 ) V_493 -> V_518 << V_890 ) |
( V_493 -> V_793 & ( V_891 | V_892 ) ) ) ;
V_10 = F_324 ( V_493 , & V_2 ) ;
if ( V_10 )
return V_10 ;
F_18 ( F_330 ( V_36 ) , V_2 ) ;
F_18 ( F_331 ( V_36 ) ,
( ( T_1 ) V_493 -> V_792 << V_893 ) |
( V_493 -> V_791 & ( V_894 | V_895 ) ) ) ;
F_18 ( F_332 ( V_36 ) ,
( ( T_1 ) V_493 -> V_816 << V_896 ) |
V_897 |
( ( T_1 ) V_493 -> V_817 << V_898 ) ) ;
V_10 = F_325 ( V_4 , V_36 , 1 ) ;
if ( V_10 )
return V_10 ;
F_18 ( F_191 ( V_36 ) , V_493 -> V_516 ) ;
V_2 = F_16 ( F_228 ( V_36 ) ) ;
V_2 |= V_887 ;
F_18 ( F_228 ( V_36 ) , V_2 ) ;
return 0 ;
}
static int F_333 ( struct V_3 * V_4 )
{
unsigned long V_87 ;
T_1 V_899 = V_900 ;
int V_10 , V_26 ;
F_165 ( V_4 , V_87 ) ;
F_18 ( V_901 , V_4 -> V_25 -> V_902 ) ;
F_18 ( V_903 , V_904 | ( V_899 & V_905 ) ) ;
F_167 ( V_4 , V_87 ) ;
F_304 ( V_4 ) ;
F_307 ( V_4 ) ;
V_10 = F_309 ( V_4 ) ;
if ( V_10 )
return V_10 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_624 ; V_26 ++ ) {
struct V_492 * V_493 = & V_4 -> V_625 [ V_26 ] ;
V_10 = F_326 ( V_4 , V_493 ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
static int F_334 ( struct V_3 * V_4 )
{
struct V_24 * V_25 = V_4 -> V_25 ;
struct V_906 * V_907 = & V_4 -> V_478 ;
struct V_908 * V_341 ;
int V_375 , V_10 ;
V_375 = V_907 -> V_480 ;
V_341 = & V_25 -> V_909 [ V_375 ] ;
memset ( V_341 , 0 , sizeof( * V_341 ) ) ;
V_341 -> V_403 [ 1 ] = V_910 ;
V_341 -> V_911 [ 1 ] = V_910 ;
V_341 -> V_410 = ( V_912 |
( ( T_1 ) 0 << V_913 ) ) ;
V_10 = F_141 ( V_4 , V_375 , V_341 -> V_403 , V_341 -> V_911 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_142 ( V_4 , V_375 , V_341 -> V_410 ) ;
if ( V_10 )
return V_10 ;
V_341 -> V_914 = 1 ;
V_907 -> V_482 ++ ;
return 0 ;
}
static int F_335 ( struct V_3 * V_4 )
{
struct V_24 * V_25 = V_4 -> V_25 ;
struct V_906 * V_907 = & V_4 -> V_478 ;
int V_26 , V_10 ;
F_18 ( V_474 , V_907 -> V_915 ) ;
F_18 ( V_475 , V_907 -> V_916 ) ;
V_10 = F_309 ( V_4 ) ;
if ( V_10 )
return V_10 ;
for ( V_26 = 0 ; V_26 < V_396 ; V_26 ++ ) {
struct V_917 * V_918 = & V_907 -> V_919 [ V_26 ] ;
F_135 ( V_4 , V_26 , V_4 -> V_30 ,
V_918 -> V_920 , V_918 -> V_921 ) ;
}
for ( V_26 = 0 ; V_26 < V_907 -> V_922 ; V_26 ++ ) {
struct V_923 * V_924 = & V_907 -> V_925 [ V_26 ] ;
V_10 = F_132 ( V_4 , V_924 -> V_926 ,
V_924 -> V_921 , V_924 -> V_379 ) ;
if ( V_10 )
return V_10 ;
}
for ( V_26 = V_425 ; V_26 <= V_477 ; V_26 ++ ) {
int V_375 = V_26 - V_425 ;
V_10 = F_170 ( V_4 , V_26 , V_25 -> V_927 [ V_375 ] ) ;
if ( V_10 )
return V_10 ;
V_10 = F_168 ( V_4 , V_26 , V_25 -> V_928 [ V_375 ] ) ;
if ( V_10 )
return V_10 ;
}
V_10 = F_334 ( V_4 ) ;
if ( V_10 )
return V_10 ;
F_143 ( V_4 , 1 ) ;
return 0 ;
}
static int F_336 ( struct V_3 * V_4 , int V_375 , T_1 * V_35 )
{
F_18 ( V_929 , V_35 [ 0 ] ) ;
F_18 ( V_930 , V_35 [ 1 ] ) ;
F_18 ( V_931 , V_35 [ 2 ] ) ;
F_18 ( V_932 , V_35 [ 3 ] ) ;
F_18 ( V_933 , V_35 [ 4 ] ) ;
F_18 ( V_934 , V_935 ) ;
F_18 ( V_936 ,
( V_937 |
( 0 << V_938 ) |
( F_337 ( V_4 -> V_30 ) << V_939 ) ) ) ;
return F_338 ( V_4 , V_936 , V_940 ,
1000 , 100 ) ;
}
static int F_339 ( struct V_3 * V_4 , int V_375 , T_1 * V_35 )
{
int V_10 ;
V_10 = F_338 ( V_4 , V_936 , V_940 ,
1000 , 100 ) ;
if ( V_10 ) {
F_10 ( V_4 -> V_11 , L_89 ,
( unsigned long long ) F_16 ( V_936 ) ) ;
return V_10 ;
}
F_18 ( V_936 ,
( V_941 |
( 0 << V_938 ) |
( F_337 ( V_4 -> V_30 ) << V_939 ) ) ) ;
V_10 = F_338 ( V_4 , V_936 , V_940 ,
1000 , 100 ) ;
if ( V_10 ) {
F_10 ( V_4 -> V_11 , L_90 ,
( unsigned long long ) F_16 ( V_936 ) ) ;
return V_10 ;
}
V_35 [ 0 ] = F_16 ( V_929 ) ;
V_35 [ 1 ] = F_16 ( V_930 ) ;
V_35 [ 2 ] = F_16 ( V_931 ) ;
V_35 [ 3 ] = F_16 ( V_932 ) ;
V_35 [ 4 ] = F_16 ( V_933 ) ;
return 0 ;
}
static void F_340 ( struct V_3 * V_4 )
{
T_1 V_2 = F_16 ( V_942 ) ;
V_2 |= F_341 ( V_4 -> V_30 ) ;
F_18 ( V_942 , V_2 ) ;
F_7 ( 10 ) ;
V_2 &= ~ F_341 ( V_4 -> V_30 ) ;
F_18 ( V_942 , V_2 ) ;
}
static int F_342 ( struct V_3 * V_4 )
{
T_1 V_35 [ 5 ] , V_943 [ 5 ] ;
int V_26 , V_944 , V_10 ;
if ( V_4 -> V_25 -> V_339 != V_343 ) {
if ( V_4 -> V_30 == 0 || V_4 -> V_30 == 1 )
V_944 = V_945 ;
else
V_944 = V_946 ;
} else
V_944 = V_947 ;
V_35 [ 0 ] = 0 ;
V_35 [ 1 ] = 0 ;
V_35 [ 2 ] = 0 ;
V_35 [ 3 ] = 0 ;
V_35 [ 4 ] = 0 ;
for ( V_26 = 0 ; V_26 < V_944 ; V_26 ++ ) {
V_10 = F_336 ( V_4 , V_26 , V_35 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_339 ( V_4 , V_26 , V_943 ) ;
if ( V_10 )
return V_10 ;
}
F_340 ( V_4 ) ;
F_18 ( F_343 ( V_4 -> V_30 ) , 0 ) ;
F_18 ( V_948 , V_949 ) ;
( void ) F_16 ( V_948 ) ;
F_18 ( V_950 , V_951 ) ;
return 0 ;
}
static void F_344 ( struct V_3 * V_4 , int V_375 , T_1 * V_35 )
{
T_1 V_2 = F_12 ( V_952 ) ;
F_14 ( V_952 , V_2 | V_953 ) ;
F_14 ( V_954 , V_375 ) ;
F_14 ( V_955 , V_35 [ 0 ] ) ;
F_14 ( V_956 , V_35 [ 1 ] ) ;
F_14 ( V_957 , V_35 [ 2 ] ) ;
F_14 ( V_958 , V_35 [ 3 ] ) ;
F_14 ( V_959 , V_35 [ 4 ] ) ;
F_14 ( V_952 , V_2 & ~ V_953 ) ;
}
static void F_345 ( struct V_3 * V_4 , int V_375 , T_1 * V_35 )
{
F_14 ( V_960 , V_375 ) ;
V_35 [ 0 ] = F_12 ( V_961 ) ;
V_35 [ 1 ] = F_12 ( V_962 ) ;
V_35 [ 2 ] = F_12 ( V_963 ) ;
V_35 [ 3 ] = F_12 ( V_964 ) ;
V_35 [ 4 ] = F_12 ( V_965 ) ;
}
static int F_346 ( struct V_3 * V_4 )
{
return F_347 ( V_4 , V_952 , V_966 ,
1000 , 100 , L_91 ) ;
}
static int F_348 ( struct V_3 * V_4 )
{
T_1 V_35 [ 5 ] , V_943 [ 5 ] , V_2 ;
int V_26 , V_944 , V_10 ;
if ( V_4 -> V_25 -> V_339 != V_343 ) {
if ( V_4 -> V_30 == 0 || V_4 -> V_30 == 1 )
V_944 = V_967 ;
else
V_944 = V_968 ;
} else
V_944 = V_969 ;
V_35 [ 0 ] = 0 ;
V_35 [ 1 ] = 0 ;
V_35 [ 2 ] = 0 ;
V_35 [ 3 ] = 0 ;
V_35 [ 4 ] = 0 ;
for ( V_26 = 0 ; V_26 < V_944 ; V_26 ++ ) {
F_344 ( V_4 , V_26 , V_35 ) ;
F_345 ( V_4 , V_26 , V_943 ) ;
}
( void ) F_12 ( V_970 ) ;
( void ) F_12 ( V_970 ) ;
V_10 = F_346 ( V_4 ) ;
if ( V_10 )
return V_10 ;
( void ) F_12 ( V_971 ) ;
( void ) F_12 ( V_972 ) ;
( void ) F_12 ( V_973 ) ;
( void ) F_12 ( V_970 ) ;
F_14 ( V_974 , ~ V_975 ) ;
V_2 = F_12 ( V_952 ) ;
V_2 &= ~ V_976 ;
V_2 |= ( V_977 |
V_978 |
V_979 |
V_980 |
( 0x1ffff << V_981 ) ) ;
F_14 ( V_952 , V_2 ) ;
return 0 ;
}
static void F_99 ( struct V_3 * V_4 , int V_982 )
{
T_1 V_2 ;
V_2 = F_6 ( V_269 ) ;
if ( ( V_4 -> V_87 & V_88 ) != 0 &&
( V_4 -> V_87 & V_344 ) != 0 ) {
if ( V_982 ) {
V_2 |= V_270 ;
V_2 &= ~ V_271 ;
} else {
V_2 |= V_271 ;
V_2 &= ~ V_270 ;
}
}
F_9 ( V_269 , V_2 ) ;
}
static void F_349 ( struct V_3 * V_4 )
{
struct V_38 * V_13 = & V_4 -> V_39 ;
T_1 V_2 ;
if ( V_4 -> V_87 & V_345 ) {
V_2 = F_16 ( V_272 ) ;
V_2 |= V_983 ;
F_18 ( V_272 , V_2 ) ;
}
V_2 = F_6 ( V_269 ) ;
V_2 &= ~ V_984 ;
V_2 |= V_985 ;
if ( V_13 -> V_49 == V_257 ) {
V_2 &= ~ V_984 ;
V_2 |= V_986 ;
} else {
V_2 &= ~ V_986 ;
}
if ( V_4 -> V_87 & V_88 ) {
V_2 &= ~ V_987 ;
} else {
V_2 |= V_987 ;
if ( ! ( V_4 -> V_87 & V_344 ) &&
! ( V_4 -> V_87 & V_345 ) )
V_2 |= V_988 ;
else
V_2 &= ~ V_988 ;
}
V_2 &= ~ V_989 ;
if ( V_13 -> V_160 == V_206 )
V_2 |= V_990 ;
else
V_2 &= ~ V_990 ;
F_9 ( V_269 , V_2 ) ;
V_2 = F_6 ( V_269 ) ;
V_2 &= ~ V_991 ;
if ( V_4 -> V_87 & V_88 ) {
V_2 |= V_992 ;
} else {
if ( V_13 -> V_160 == V_158 )
V_2 |= V_993 ;
else
V_2 |= V_994 ;
}
F_9 ( V_269 , V_2 ) ;
}
static void F_350 ( struct V_3 * V_4 )
{
struct V_38 * V_13 = & V_4 -> V_39 ;
T_1 V_2 ;
V_2 = V_995 ;
if ( V_13 -> V_49 == V_257 )
V_2 |= V_996 ;
else
V_2 &= ~ V_996 ;
if ( V_13 -> V_160 == V_158 )
V_2 |= V_997 ;
else
V_2 &= ~ V_997 ;
V_2 &= ~ ( V_998 |
V_999 ) ;
if ( ! ( V_4 -> V_87 & V_88 ) &&
! ( V_4 -> V_87 & V_344 ) &&
V_13 -> V_160 == V_206 )
V_2 |= V_1000 ;
else
V_2 &= ~ V_1000 ;
F_9 ( V_1001 , V_2 ) ;
}
static void F_98 ( struct V_3 * V_4 )
{
if ( V_4 -> V_87 & V_366 )
F_349 ( V_4 ) ;
else
F_350 ( V_4 ) ;
}
static void F_351 ( struct V_3 * V_4 )
{
int V_6 = 1000 ;
T_1 V_2 = F_64 ( V_1002 ) ;
V_2 |= V_1003 ;
F_352 ( V_1002 , V_2 ) ;
while ( ( -- V_6 >= 0 ) && ( V_2 & V_1003 ) ) {
F_7 ( 100 ) ;
V_2 = F_64 ( V_1002 ) ;
}
}
static void F_353 ( struct V_3 * V_4 )
{
int V_6 = 1000 ;
T_1 V_2 = F_67 ( V_1004 ) ;
V_2 |= V_1005 ;
F_354 ( V_1004 , V_2 ) ;
while ( ( -- V_6 >= 0 ) && ( V_2 & V_1005 ) ) {
F_7 ( 100 ) ;
V_2 = F_67 ( V_1004 ) ;
}
}
static int F_355 ( struct V_3 * V_4 )
{
struct V_38 * V_13 = & V_4 -> V_39 ;
T_1 V_2 ;
switch ( V_4 -> V_87 & ( V_88 |
V_344 |
V_345 ) ) {
case V_344 :
F_352 ( V_1006 , V_1007 | V_1008 ) ;
F_352 ( V_1009 , 0 ) ;
F_351 ( V_4 ) ;
break;
case V_88 :
case V_88 | V_344 :
case V_88 | V_345 :
if ( ! ( V_4 -> V_87 & V_366 ) )
return - V_21 ;
V_2 = F_6 ( V_269 ) ;
V_2 &= ~ V_989 ;
F_9 ( V_269 , V_2 ) ;
F_353 ( V_4 ) ;
V_2 = F_67 ( V_1004 ) ;
if ( V_13 -> V_49 == V_50 )
V_2 |= V_1010 ;
else
V_2 &= ~ V_1010 ;
F_354 ( V_1004 , V_2 ) ;
F_354 ( V_1011 , 0 ) ;
( void ) F_67 ( V_1012 ) ;
( void ) F_67 ( V_1013 ) ;
break;
case V_345 :
F_351 ( V_4 ) ;
F_352 ( V_1006 , V_1007 | V_1008 ) ;
F_352 ( V_1009 , 0 ) ;
break;
case 0 :
case V_345 | V_344 :
F_352 ( V_1009 , V_1014 ) ;
F_351 ( V_4 ) ;
break;
default:
return - V_21 ;
}
return 0 ;
}
static int F_356 ( struct V_3 * V_4 )
{
return F_357 ( V_4 , V_1015 ,
( V_1016 |
V_1017 ) ,
1000 , 100 , L_92 ) ;
}
static int F_358 ( struct V_3 * V_4 )
{
int V_6 ;
F_9 ( V_1018 , V_1019 ) ;
V_6 = 1000 ;
while ( -- V_6 >= 0 ) {
if ( ! ( F_6 ( V_1018 ) & V_1019 ) )
break;
F_7 ( 100 ) ;
}
if ( V_6 < 0 ) {
F_225 ( V_4 -> V_508 , L_93 ,
V_4 -> V_30 ,
( unsigned long long ) F_6 ( V_1018 ) ) ;
return - V_8 ;
}
return 0 ;
}
static int F_359 ( struct V_3 * V_4 )
{
if ( V_4 -> V_87 & V_366 )
return F_356 ( V_4 ) ;
else
return F_358 ( V_4 ) ;
}
static void F_360 ( struct V_3 * V_4 , T_1 F_230 , T_1 V_944 )
{
T_1 V_2 ;
V_2 = F_6 ( V_1020 ) ;
V_2 &= ~ ( V_1021 |
V_1022 ) ;
V_2 |= ( F_230 << V_1023 ) ;
V_2 |= ( F_230 << V_1024 ) ;
F_9 ( V_1020 , V_2 ) ;
F_9 ( V_1025 , V_944 ) ;
F_9 ( V_1026 , ~ ( T_1 ) 0 ) ;
V_2 = F_6 ( V_1027 ) ;
if ( V_4 -> V_87 & V_88 ) {
V_2 &= ~ V_1028 ;
V_2 |= ( V_1029 << V_1030 ) ;
} else {
V_2 &= ~ V_1031 ;
V_2 |= ( V_1032 << V_1033 ) ;
}
F_9 ( V_1027 , V_2 ) ;
V_2 = F_6 ( V_269 ) ;
V_2 &= ~ ( V_1034 |
V_1035 |
V_1036 |
V_1037 ) ;
F_9 ( V_269 , V_2 ) ;
F_9 ( V_1038 , 0 ) ;
F_9 ( V_1039 , 0 ) ;
}
static void F_361 ( struct V_3 * V_4 , T_1 F_230 , T_1 V_944 )
{
T_1 V_2 ;
F_9 ( V_1040 , F_230 ) ;
F_9 ( V_1041 , V_944 ) ;
F_9 ( V_1042 , ~ ( T_1 ) 0 ) ;
F_9 ( V_1043 , 0x8808 ) ;
F_9 ( V_1044 , 7 ) ;
V_2 = F_6 ( V_1045 ) ;
V_2 &= ~ ( V_1046 |
V_1047 ) ;
F_9 ( V_1045 , V_2 ) ;
}
static void F_362 ( struct V_3 * V_4 )
{
T_1 F_230 , V_944 ;
F_230 = 64 ;
if ( V_4 -> V_11 -> V_802 > V_806 )
V_944 = 9216 ;
else
V_944 = 1522 ;
F_190 ( F_230 & 0x7 ) ;
if ( V_4 -> V_87 & V_366 )
F_360 ( V_4 , F_230 , V_944 ) ;
else
F_361 ( V_4 , F_230 , V_944 ) ;
}
static int F_363 ( struct V_3 * V_4 )
{
int V_6 ;
F_9 ( V_1048 ,
V_1049 | V_1050 ) ;
V_6 = 1000 ;
while ( -- V_6 >= 0 ) {
if ( ! ( F_6 ( V_1048 ) & ( V_1049 |
V_1050 ) ) )
break;
F_7 ( 100 ) ;
}
if ( V_6 < 0 ) {
F_225 ( V_4 -> V_508 , L_94 ,
V_4 -> V_30 ,
( unsigned long long ) F_6 ( V_1048 ) ) ;
return - V_8 ;
}
return 0 ;
}
static int F_364 ( struct V_3 * V_4 )
{
int V_6 ;
F_9 ( V_1051 , V_1052 ) ;
V_6 = 1000 ;
while ( -- V_6 >= 0 ) {
if ( ! ( F_6 ( V_1051 ) & V_1052 ) )
break;
F_7 ( 100 ) ;
}
if ( V_6 < 0 ) {
F_225 ( V_4 -> V_508 , L_95 ,
V_4 -> V_30 ,
( unsigned long long ) F_6 ( V_1051 ) ) ;
return - V_8 ;
}
return 0 ;
}
static int F_365 ( struct V_3 * V_4 )
{
if ( V_4 -> V_87 & V_366 )
return F_363 ( V_4 ) ;
else
return F_364 ( V_4 ) ;
}
static void F_366 ( struct V_3 * V_4 )
{
struct V_24 * V_25 = V_4 -> V_25 ;
struct V_835 * V_341 = & V_25 -> V_836 [ V_4 -> V_30 ] ;
int V_851 = V_341 -> V_837 ;
unsigned long V_26 ;
T_1 V_2 ;
F_9 ( V_1053 , 0 ) ;
F_9 ( V_1054 , 0 ) ;
F_9 ( V_1055 , 0 ) ;
F_9 ( V_1056 , 0 ) ;
F_9 ( V_1057 , 0 ) ;
for ( V_26 = 0 ; V_26 < V_1058 ; V_26 ++ )
F_9 ( F_367 ( V_26 ) , 0 ) ;
F_9 ( V_1059 , ~ ( T_1 ) 0 ) ;
F_130 ( V_4 , V_851 , 1 ) ;
F_131 ( V_4 , V_851 , 1 ) ;
V_2 = F_6 ( V_269 ) ;
V_2 &= ~ ( V_1060 |
V_1061 |
V_1062 |
V_1063 |
V_1064 |
V_1065 |
V_1066 |
V_1067 |
V_1068 |
V_1069 |
V_1070 |
V_1071 ) ;
V_2 |= ( V_1072 ) ;
F_9 ( V_269 , V_2 ) ;
F_9 ( V_1073 , 0 ) ;
F_9 ( V_1074 , 0 ) ;
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
}
static void F_368 ( struct V_3 * V_4 )
{
struct V_24 * V_25 = V_4 -> V_25 ;
struct V_835 * V_341 = & V_25 -> V_836 [ V_4 -> V_30 ] ;
int V_851 = V_341 -> V_837 ;
unsigned long V_26 ;
T_1 V_2 ;
F_9 ( V_1088 , 0 ) ;
F_9 ( V_1089 , 0 ) ;
F_9 ( V_1090 , 0 ) ;
F_9 ( V_1091 , 0 ) ;
F_9 ( V_1092 , 0 ) ;
for ( V_26 = 0 ; V_26 < V_1058 ; V_26 ++ )
F_9 ( F_369 ( V_26 ) , 0 ) ;
F_130 ( V_4 , V_851 , 1 ) ;
F_131 ( V_4 , V_851 , 1 ) ;
F_9 ( V_1093 , ~ ( T_1 ) 0 ) ;
V_2 = F_6 ( V_1094 ) ;
V_2 &= ~ ( V_1095 |
V_1096 |
V_1097 |
V_1098 |
V_1099 |
V_1100 |
V_1101 ) ;
V_2 |= ( V_1102 ) ;
F_9 ( V_1094 , V_2 ) ;
V_2 = F_6 ( V_377 ) ;
V_2 |= V_1103 ;
F_9 ( V_377 , V_2 ) ;
}
static void F_370 ( struct V_3 * V_4 )
{
F_116 ( V_4 , V_4 -> V_11 -> V_1104 ) ;
if ( V_4 -> V_87 & V_366 )
F_366 ( V_4 ) ;
else
F_368 ( V_4 ) ;
}
static void F_371 ( struct V_3 * V_4 , int V_14 )
{
T_1 V_2 = F_6 ( V_269 ) ;
if ( V_14 )
V_2 |= V_1037 ;
else
V_2 &= ~ V_1037 ;
F_9 ( V_269 , V_2 ) ;
}
static void F_372 ( struct V_3 * V_4 , int V_14 )
{
T_1 V_2 = F_6 ( V_1045 ) ;
if ( V_14 )
V_2 |= V_1047 ;
else
V_2 &= ~ V_1047 ;
F_9 ( V_1045 , V_2 ) ;
}
static void F_373 ( struct V_3 * V_4 , int V_14 )
{
if ( V_4 -> V_87 & V_366 )
F_371 ( V_4 , V_14 ) ;
else
F_372 ( V_4 , V_14 ) ;
}
static void F_374 ( struct V_3 * V_4 , int V_14 )
{
T_1 V_2 = F_6 ( V_269 ) ;
V_2 &= ~ ( V_1072 |
V_1061 ) ;
if ( V_4 -> V_87 & V_1105 )
V_2 |= V_1072 ;
if ( V_4 -> V_87 & V_1106 )
V_2 |= V_1061 ;
if ( V_14 )
V_2 |= V_1060 ;
else
V_2 &= ~ V_1060 ;
F_9 ( V_269 , V_2 ) ;
}
static void F_375 ( struct V_3 * V_4 , int V_14 )
{
T_1 V_2 = F_6 ( V_1094 ) ;
V_2 &= ~ ( V_1102 |
V_1098 ) ;
if ( V_4 -> V_87 & V_1105 )
V_2 |= V_1102 ;
if ( V_4 -> V_87 & V_1106 )
V_2 |= V_1098 ;
if ( V_14 )
V_2 |= V_1095 ;
else
V_2 &= ~ V_1095 ;
F_9 ( V_1094 , V_2 ) ;
}
static void F_376 ( struct V_3 * V_4 , int V_14 )
{
if ( V_4 -> V_87 & V_366 )
F_374 ( V_4 , V_14 ) ;
else
F_375 ( V_4 , V_14 ) ;
}
static int F_377 ( struct V_3 * V_4 )
{
int V_10 ;
F_98 ( V_4 ) ;
V_10 = F_355 ( V_4 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_359 ( V_4 ) ;
if ( V_10 )
return V_10 ;
F_362 ( V_4 ) ;
V_10 = F_365 ( V_4 ) ;
if ( V_10 )
return V_10 ;
F_370 ( V_4 ) ;
F_362 ( V_4 ) ;
F_373 ( V_4 , 1 ) ;
F_376 ( V_4 , 1 ) ;
return 0 ;
}
static void F_378 ( struct V_3 * V_4 , struct V_563 * V_493 )
{
( void ) F_279 ( V_4 , V_493 -> V_623 ) ;
}
static void F_379 ( struct V_3 * V_4 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_622 ; V_26 ++ ) {
struct V_563 * V_493 = & V_4 -> V_587 [ V_26 ] ;
F_378 ( V_4 , V_493 ) ;
}
}
static void F_380 ( struct V_3 * V_4 , struct V_563 * V_493 )
{
( void ) F_281 ( V_4 , V_493 -> V_623 ) ;
}
static void F_381 ( struct V_3 * V_4 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_622 ; V_26 ++ ) {
struct V_563 * V_493 = & V_4 -> V_587 [ V_26 ] ;
F_380 ( V_4 , V_493 ) ;
}
}
static void F_382 ( struct V_3 * V_4 , struct V_492 * V_493 )
{
( void ) F_325 ( V_4 , V_493 -> V_520 , 0 ) ;
}
static void F_383 ( struct V_3 * V_4 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_624 ; V_26 ++ ) {
struct V_492 * V_493 = & V_4 -> V_625 [ V_26 ] ;
F_382 ( V_4 , V_493 ) ;
}
}
static void F_384 ( struct V_3 * V_4 , struct V_492 * V_493 )
{
int V_36 = V_493 -> V_520 ;
( void ) F_310 ( V_4 , V_36 ) ;
F_18 ( F_327 ( V_36 ) , V_1107 ) ;
F_18 ( F_228 ( V_36 ) , 0 ) ;
( void ) F_325 ( V_4 , V_36 , 0 ) ;
}
static void F_385 ( struct V_3 * V_4 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_624 ; V_26 ++ ) {
struct V_492 * V_493 = & V_4 -> V_625 [ V_26 ] ;
F_384 ( V_4 , V_493 ) ;
}
}
static void F_386 ( struct V_3 * V_4 )
{
T_1 V_1108 , V_1109 , V_2 ;
int V_6 ;
V_1108 = F_12 ( V_960 ) ;
V_1109 = F_12 ( V_954 ) ;
V_6 = 100 ;
while ( -- V_6 >= 0 && ( V_1108 != V_1109 ) ) {
V_1108 = F_12 ( V_960 ) ;
V_1109 = F_12 ( V_954 ) ;
}
if ( V_6 < 0 &&
( V_1108 != 0 && V_1109 != 1 ) ) {
F_10 ( V_4 -> V_11 , L_96 ,
( unsigned long long ) F_12 ( V_960 ) ,
( unsigned long long ) F_12 ( V_954 ) ) ;
}
V_2 = F_12 ( V_952 ) ;
V_2 &= ~ ( V_977 |
V_978 |
V_979 |
V_980 ) ;
F_14 ( V_952 , V_2 ) ;
( void ) F_346 ( V_4 ) ;
}
static int F_387 ( struct V_3 * V_4 )
{
int V_26 , V_10 ;
F_166 ( V_4 , V_1110 , V_473 , V_4 -> V_11 , L_97 ) ;
F_292 ( V_4 , 1 ) ;
F_296 ( V_4 , 1 ) ;
F_293 ( V_4 , 0 ) ;
F_166 ( V_4 , V_1110 , V_473 , V_4 -> V_11 , L_98 ) ;
for ( V_26 = 0 ; V_26 < V_4 -> V_622 ; V_26 ++ ) {
struct V_563 * V_493 = & V_4 -> V_587 [ V_26 ] ;
V_10 = F_298 ( V_4 , V_493 ) ;
if ( V_10 )
return V_10 ;
}
F_166 ( V_4 , V_1110 , V_473 , V_4 -> V_11 , L_99 ) ;
V_10 = F_333 ( V_4 ) ;
if ( V_10 )
goto V_1111;
F_166 ( V_4 , V_1110 , V_473 , V_4 -> V_11 , L_100 ) ;
V_10 = F_335 ( V_4 ) ;
if ( V_10 )
goto V_1112;
F_166 ( V_4 , V_1110 , V_473 , V_4 -> V_11 , L_101 ) ;
V_10 = F_342 ( V_4 ) ;
if ( V_10 )
goto V_1112;
F_166 ( V_4 , V_1110 , V_473 , V_4 -> V_11 , L_102 ) ;
V_10 = F_348 ( V_4 ) ;
if ( V_10 )
goto V_1112;
F_166 ( V_4 , V_1110 , V_473 , V_4 -> V_11 , L_103 ) ;
V_10 = F_377 ( V_4 ) ;
if ( V_10 )
goto V_1113;
return 0 ;
V_1113:
F_166 ( V_4 , V_1110 , V_473 , V_4 -> V_11 , L_104 ) ;
F_386 ( V_4 ) ;
V_1112:
F_166 ( V_4 , V_1110 , V_473 , V_4 -> V_11 , L_105 ) ;
F_383 ( V_4 ) ;
F_385 ( V_4 ) ;
V_1111:
F_166 ( V_4 , V_1110 , V_473 , V_4 -> V_11 , L_106 ) ;
F_379 ( V_4 ) ;
F_381 ( V_4 ) ;
return V_10 ;
}
static void F_388 ( struct V_3 * V_4 )
{
F_166 ( V_4 , V_1114 , V_473 , V_4 -> V_11 , L_107 ) ;
F_25 ( V_4 , 0 ) ;
F_166 ( V_4 , V_1114 , V_473 , V_4 -> V_11 , L_108 ) ;
F_376 ( V_4 , 0 ) ;
F_166 ( V_4 , V_1114 , V_473 , V_4 -> V_11 , L_109 ) ;
F_386 ( V_4 ) ;
F_166 ( V_4 , V_1114 , V_473 , V_4 -> V_11 , L_110 ) ;
F_379 ( V_4 ) ;
F_166 ( V_4 , V_1114 , V_473 , V_4 -> V_11 , L_111 ) ;
F_383 ( V_4 ) ;
F_166 ( V_4 , V_1114 , V_473 , V_4 -> V_11 , L_112 ) ;
F_381 ( V_4 ) ;
F_166 ( V_4 , V_1114 , V_473 , V_4 -> V_11 , L_113 ) ;
F_385 ( V_4 ) ;
}
static void F_389 ( struct V_3 * V_4 )
{
int V_30 = V_4 -> V_30 ;
int V_26 , V_1115 = 1 ;
sprintf ( V_4 -> V_1116 [ 0 ] , L_114 , V_4 -> V_11 -> V_1117 ) ;
if ( V_30 == 0 ) {
sprintf ( V_4 -> V_1116 [ 1 ] , L_115 , V_4 -> V_11 -> V_1117 ) ;
sprintf ( V_4 -> V_1116 [ 2 ] , L_116 , V_4 -> V_11 -> V_1117 ) ;
V_1115 = 3 ;
}
for ( V_26 = 0 ; V_26 < V_4 -> V_28 - V_1115 ; V_26 ++ ) {
if ( V_26 < V_4 -> V_624 )
sprintf ( V_4 -> V_1116 [ V_26 + V_1115 ] , L_117 ,
V_4 -> V_11 -> V_1117 , V_26 ) ;
else if ( V_26 < V_4 -> V_622 + V_4 -> V_624 )
sprintf ( V_4 -> V_1116 [ V_26 + V_1115 ] , L_118 , V_4 -> V_11 -> V_1117 ,
V_26 - V_4 -> V_624 ) ;
}
}
static int F_390 ( struct V_3 * V_4 )
{
int V_26 , V_1115 , V_10 ;
F_389 ( V_4 ) ;
V_10 = 0 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_28 ; V_26 ++ ) {
struct V_12 * V_13 = & V_4 -> V_29 [ V_26 ] ;
V_10 = F_391 ( V_13 -> V_782 , F_258 , V_1118 ,
V_4 -> V_1116 [ V_26 ] , V_13 ) ;
if ( V_10 )
goto V_1119;
}
return 0 ;
V_1119:
for ( V_1115 = 0 ; V_1115 < V_26 ; V_1115 ++ ) {
struct V_12 * V_13 = & V_4 -> V_29 [ V_1115 ] ;
F_392 ( V_13 -> V_782 , V_13 ) ;
}
return V_10 ;
}
static void F_393 ( struct V_3 * V_4 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_28 ; V_26 ++ ) {
struct V_12 * V_13 = & V_4 -> V_29 [ V_26 ] ;
F_392 ( V_13 -> V_782 , V_13 ) ;
}
}
static void F_394 ( struct V_3 * V_4 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_28 ; V_26 ++ )
F_395 ( & V_4 -> V_29 [ V_26 ] . V_535 ) ;
}
static void F_396 ( struct V_3 * V_4 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_28 ; V_26 ++ )
F_397 ( & V_4 -> V_29 [ V_26 ] . V_535 ) ;
}
static int F_398 ( struct V_308 * V_11 )
{
struct V_3 * V_4 = F_399 ( V_11 ) ;
int V_10 ;
F_102 ( V_11 ) ;
V_10 = F_274 ( V_4 ) ;
if ( V_10 )
goto V_811;
V_10 = F_25 ( V_4 , 0 ) ;
if ( V_10 )
goto V_1120;
V_10 = F_390 ( V_4 ) ;
if ( V_10 )
goto V_1120;
F_394 ( V_4 ) ;
F_400 ( & V_4 -> V_155 ) ;
V_10 = F_387 ( V_4 ) ;
if ( ! V_10 ) {
F_401 ( & V_4 -> V_15 ) ;
V_4 -> V_15 . V_337 = V_338 + V_336 ;
V_4 -> V_15 . V_35 = ( unsigned long ) V_4 ;
V_4 -> V_15 . V_1121 = F_110 ;
V_10 = F_25 ( V_4 , 1 ) ;
if ( V_10 )
F_388 ( V_4 ) ;
}
F_402 ( & V_4 -> V_155 ) ;
if ( V_10 ) {
F_396 ( V_4 ) ;
goto V_1122;
}
F_403 ( V_11 ) ;
if ( V_4 -> V_39 . V_49 != V_330 )
F_100 ( V_11 ) ;
F_111 ( & V_4 -> V_15 ) ;
return 0 ;
V_1122:
F_393 ( V_4 ) ;
V_1120:
F_267 ( V_4 ) ;
V_811:
return V_10 ;
}
static void F_404 ( struct V_3 * V_4 , struct V_308 * V_11 )
{
F_405 ( & V_4 -> V_1123 ) ;
F_396 ( V_4 ) ;
F_406 ( V_11 ) ;
F_407 ( & V_4 -> V_15 ) ;
F_400 ( & V_4 -> V_155 ) ;
F_388 ( V_4 ) ;
F_402 ( & V_4 -> V_155 ) ;
}
static int F_408 ( struct V_308 * V_11 )
{
struct V_3 * V_4 = F_399 ( V_11 ) ;
F_404 ( V_4 , V_11 ) ;
F_393 ( V_4 ) ;
F_267 ( V_4 ) ;
F_99 ( V_4 , 0 ) ;
return 0 ;
}
static void F_409 ( struct V_3 * V_4 )
{
struct V_660 * V_661 = & V_4 -> V_662 . V_663 ;
V_661 -> V_666 += F_6 ( V_1038 ) ;
V_661 -> V_570 += F_6 ( V_1039 ) ;
V_661 -> V_683 += F_6 ( V_1087 ) ;
V_661 -> V_686 += F_6 ( V_1124 ) ;
V_661 -> V_689 += F_6 ( V_1076 ) ;
V_661 -> V_692 += F_6 ( V_1075 ) ;
V_661 -> V_695 += F_6 ( V_1074 ) ;
V_661 -> V_698 += F_6 ( V_1077 ) ;
V_661 -> V_701 += F_6 ( V_1078 ) ;
V_661 -> V_704 += F_6 ( V_1079 ) ;
V_661 -> V_707 += F_6 ( V_1080 ) ;
V_661 -> V_710 += F_6 ( V_1081 ) ;
V_661 -> V_713 += F_6 ( V_1082 ) ;
V_661 -> V_716 += F_6 ( V_1083 ) ;
V_661 -> V_719 += F_6 ( V_1073 ) ;
V_661 -> V_722 += F_6 ( V_1086 ) ;
V_661 -> V_725 += F_6 ( V_1084 ) ;
V_661 -> V_728 += F_6 ( V_1085 ) ;
}
static void F_410 ( struct V_3 * V_4 )
{
struct V_741 * V_661 = & V_4 -> V_662 . V_742 ;
V_661 -> V_570 += F_6 ( V_1125 ) ;
V_661 -> V_666 += F_6 ( V_1126 ) ;
V_661 -> V_753 += F_6 ( V_1127 ) ;
V_661 -> V_686 += F_6 ( V_1128 ) ;
V_661 -> V_728 += F_6 ( V_1128 ) ;
V_661 -> V_725 += F_6 ( V_1129 ) ;
}
static void F_411 ( struct V_3 * V_4 )
{
if ( V_4 -> V_87 & V_366 )
F_409 ( V_4 ) ;
else
F_410 ( V_4 ) ;
}
static void F_412 ( struct V_3 * V_4 ,
struct V_1130 * V_1131 )
{
T_1 V_1132 , V_1133 , V_1134 , V_1135 ;
struct V_492 * V_625 ;
int V_26 ;
V_1132 = V_1133 = V_1134 = V_1135 = 0 ;
V_625 = F_413 ( V_4 -> V_625 ) ;
if ( ! V_625 )
goto V_1136;
for ( V_26 = 0 ; V_26 < V_4 -> V_624 ; V_26 ++ ) {
struct V_492 * V_493 = & V_625 [ V_26 ] ;
F_223 ( V_4 , V_493 , 0 ) ;
V_1132 += V_493 -> V_558 ;
V_1135 += V_493 -> V_559 ;
V_1133 += V_493 -> V_523 ;
V_1134 += V_493 -> V_598 ;
}
V_1136:
V_1131 -> V_558 = V_1132 ;
V_1131 -> V_559 = V_1135 ;
V_1131 -> V_523 = V_1133 ;
V_1131 -> V_598 = V_1134 ;
}
static void F_414 ( struct V_3 * V_4 ,
struct V_1130 * V_1131 )
{
T_1 V_1132 , V_1134 , V_1135 ;
struct V_563 * V_587 ;
int V_26 ;
V_1132 = V_1134 = V_1135 = 0 ;
V_587 = F_413 ( V_4 -> V_587 ) ;
if ( ! V_587 )
goto V_1136;
for ( V_26 = 0 ; V_26 < V_4 -> V_622 ; V_26 ++ ) {
struct V_563 * V_493 = & V_587 [ V_26 ] ;
V_1132 += V_493 -> V_569 ;
V_1135 += V_493 -> V_570 ;
V_1134 += V_493 -> V_1137 ;
}
V_1136:
V_1131 -> V_569 = V_1132 ;
V_1131 -> V_570 = V_1135 ;
V_1131 -> V_1137 = V_1134 ;
}
static struct V_1130 * F_415 ( struct V_308 * V_11 ,
struct V_1130 * V_1131 )
{
struct V_3 * V_4 = F_399 ( V_11 ) ;
if ( F_416 ( V_11 ) ) {
F_412 ( V_4 , V_1131 ) ;
F_414 ( V_4 , V_1131 ) ;
}
return V_1131 ;
}
static void F_417 ( struct V_3 * V_4 , T_4 * V_1138 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < 16 ; V_26 ++ )
F_9 ( F_367 ( V_26 ) , V_1138 [ V_26 ] ) ;
}
static void F_418 ( struct V_3 * V_4 , T_4 * V_1138 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < 16 ; V_26 ++ )
F_9 ( F_369 ( V_26 ) , V_1138 [ V_26 ] ) ;
}
static void F_419 ( struct V_3 * V_4 , T_4 * V_1138 )
{
if ( V_4 -> V_87 & V_366 )
F_417 ( V_4 , V_1138 ) ;
else
F_418 ( V_4 , V_1138 ) ;
}
static void F_420 ( struct V_308 * V_11 )
{
struct V_3 * V_4 = F_399 ( V_11 ) ;
int V_26 , V_1139 , V_10 ;
struct V_1140 * V_1141 ;
unsigned long V_87 ;
T_4 V_1138 [ 16 ] = { 0 , } ;
F_63 ( & V_4 -> V_155 , V_87 ) ;
F_376 ( V_4 , 0 ) ;
V_4 -> V_87 &= ~ ( V_1105 | V_1106 ) ;
if ( V_11 -> V_87 & V_1142 )
V_4 -> V_87 |= V_1106 ;
if ( ( V_11 -> V_87 & V_1143 ) || ( ! F_421 ( V_11 ) ) )
V_4 -> V_87 |= V_1105 ;
V_1139 = F_422 ( V_11 ) ;
if ( V_1139 > F_117 ( V_4 ) ) {
V_1139 = 0 ;
V_4 -> V_87 |= V_1106 ;
}
if ( V_1139 ) {
int V_375 = 0 ;
F_423 (ha, dev) {
V_10 = F_118 ( V_4 , V_375 , V_1141 -> V_362 ) ;
if ( V_10 )
F_424 ( V_11 , L_119 ,
V_10 , V_375 ) ;
V_10 = F_125 ( V_4 , V_375 , 1 ) ;
if ( V_10 )
F_424 ( V_11 , L_120 ,
V_10 , V_375 ) ;
V_375 ++ ;
}
} else {
int V_1144 ;
if ( V_4 -> V_87 & V_366 )
V_1144 = 0 ;
else
V_1144 = 1 ;
for ( V_26 = V_1144 ; V_26 < F_117 ( V_4 ) ; V_26 ++ ) {
V_10 = F_125 ( V_4 , V_26 , 0 ) ;
if ( V_10 )
F_424 ( V_11 , L_121 ,
V_10 , V_26 ) ;
}
}
if ( V_11 -> V_87 & V_1143 ) {
for ( V_26 = 0 ; V_26 < 16 ; V_26 ++ )
V_1138 [ V_26 ] = 0xffff ;
} else if ( ! F_421 ( V_11 ) ) {
F_425 (ha, dev) {
T_3 V_1145 = F_426 ( V_1146 , V_1141 -> V_362 ) ;
V_1145 >>= 24 ;
V_1138 [ V_1145 >> 4 ] |= ( 1 << ( 15 - ( V_1145 & 0xf ) ) ) ;
}
}
if ( V_4 -> V_87 & V_1105 )
F_419 ( V_4 , V_1138 ) ;
F_376 ( V_4 , 1 ) ;
F_65 ( & V_4 -> V_155 , V_87 ) ;
}
static int F_427 ( struct V_308 * V_11 , void * V_498 )
{
struct V_3 * V_4 = F_399 ( V_11 ) ;
struct V_1147 * V_362 = V_498 ;
unsigned long V_87 ;
if ( ! F_428 ( V_362 -> V_1148 ) )
return - V_1149 ;
memcpy ( V_11 -> V_1104 , V_362 -> V_1148 , V_1146 ) ;
if ( ! F_416 ( V_11 ) )
return 0 ;
F_63 ( & V_4 -> V_155 , V_87 ) ;
F_376 ( V_4 , 0 ) ;
F_116 ( V_4 , V_11 -> V_1104 ) ;
F_376 ( V_4 , 1 ) ;
F_65 ( & V_4 -> V_155 , V_87 ) ;
return 0 ;
}
static int F_429 ( struct V_308 * V_11 , struct V_1150 * V_1151 , int V_1152 )
{
return - V_1153 ;
}
static void F_430 ( struct V_3 * V_4 )
{
V_4 -> V_11 -> V_1154 = V_338 ;
F_396 ( V_4 ) ;
F_431 ( V_4 -> V_11 ) ;
}
static void F_432 ( struct V_3 * V_4 )
{
F_433 ( V_4 -> V_11 ) ;
F_394 ( V_4 ) ;
F_25 ( V_4 , 1 ) ;
}
static void F_434 ( struct V_3 * V_4 )
{
int V_26 , V_1115 , V_1155 , V_10 ;
if ( V_4 -> V_625 ) {
for ( V_26 = 0 ; V_26 < V_4 -> V_624 ; V_26 ++ ) {
struct V_492 * V_493 = & V_4 -> V_625 [ V_26 ] ;
for ( V_1115 = 0 , V_1155 = 0 ; V_1115 < V_496 ; V_1115 ++ ) {
struct V_485 * V_485 ;
V_485 = V_493 -> V_501 [ V_1115 ] ;
while ( V_485 ) {
struct V_485 * V_562 =
(struct V_485 * ) V_485 -> V_502 ;
T_1 V_458 = V_485 -> V_375 ;
V_458 = V_458 >> V_514 ;
V_493 -> V_513 [ V_1155 ++ ] = F_188 ( V_458 ) ;
V_485 = V_562 ;
}
}
for (; V_1155 < V_496 ; V_1155 ++ ) {
V_10 = F_183 ( V_4 , V_493 , V_614 , V_1155 ) ;
if ( F_70 ( V_10 ) )
break;
}
V_493 -> V_516 = V_493 -> V_518 - 1 ;
V_493 -> V_521 = 0 ;
V_493 -> V_517 = 0 ;
V_493 -> V_532 = 0 ;
}
}
if ( V_4 -> V_587 ) {
for ( V_26 = 0 ; V_26 < V_4 -> V_622 ; V_26 ++ ) {
struct V_563 * V_493 = & V_4 -> V_587 [ V_26 ] ;
for ( V_1115 = 0 ; V_1115 < V_795 ; V_1115 ++ ) {
if ( V_493 -> V_566 [ V_1115 ] . V_484 )
( void ) F_207 ( V_4 , V_493 , V_1115 ) ;
}
V_493 -> V_797 = V_795 ;
V_493 -> V_798 = 0 ;
V_493 -> V_585 = 0 ;
V_493 -> V_799 = 0 ;
}
}
}
static void F_435 ( struct V_1156 * V_1157 )
{
struct V_3 * V_4 = F_235 ( V_1157 , struct V_3 , V_1123 ) ;
unsigned long V_87 ;
int V_10 ;
F_63 ( & V_4 -> V_155 , V_87 ) ;
if ( ! F_416 ( V_4 -> V_11 ) ) {
F_65 ( & V_4 -> V_155 , V_87 ) ;
return;
}
F_65 ( & V_4 -> V_155 , V_87 ) ;
F_407 ( & V_4 -> V_15 ) ;
F_430 ( V_4 ) ;
F_63 ( & V_4 -> V_155 , V_87 ) ;
F_388 ( V_4 ) ;
F_65 ( & V_4 -> V_155 , V_87 ) ;
F_434 ( V_4 ) ;
F_63 ( & V_4 -> V_155 , V_87 ) ;
V_10 = F_387 ( V_4 ) ;
if ( ! V_10 ) {
V_4 -> V_15 . V_337 = V_338 + V_336 ;
F_111 ( & V_4 -> V_15 ) ;
F_432 ( V_4 ) ;
}
F_65 ( & V_4 -> V_155 , V_87 ) ;
}
static void F_436 ( struct V_308 * V_11 )
{
struct V_3 * V_4 = F_399 ( V_11 ) ;
F_225 ( V_4 -> V_508 , L_122 ,
V_11 -> V_1117 ) ;
F_437 ( & V_4 -> V_1123 ) ;
}
static void F_438 ( struct V_563 * V_493 , int V_375 ,
T_1 V_502 , T_1 V_490 , T_1 V_1158 ,
T_1 V_1159 )
{
V_790 * V_1160 = & V_493 -> V_576 [ V_375 ] ;
* V_1160 = F_439 ( V_1158 |
( V_1159 << V_1161 ) |
( V_490 << V_1162 ) |
( V_502 & V_1163 ) ) ;
}
static T_1 F_440 ( struct V_483 * V_484 , struct V_1164 * V_1165 ,
T_1 V_1166 , T_1 V_490 )
{
T_4 V_1167 , V_1168 ;
T_1 V_1169 , V_1170 , V_1171 , V_860 ;
T_5 V_1172 ;
int V_428 ;
V_1167 = F_441 ( V_1165 -> V_1173 ) ;
V_1168 = V_1167 ;
if ( V_1167 == V_1174 ) {
struct V_1175 * V_918 = (struct V_1175 * ) V_1165 ;
T_9 V_2 = V_918 -> V_1176 ;
V_1168 = F_441 ( V_2 ) ;
}
V_428 = V_1171 = 0 ;
switch ( V_484 -> V_560 ) {
case F_442 ( V_1177 ) :
V_1172 = F_443 ( V_484 ) -> V_560 ;
V_1171 = F_443 ( V_484 ) -> V_1171 ;
break;
case F_442 ( V_1178 ) :
V_1172 = F_444 ( V_484 ) -> V_1179 ;
V_1171 = ( 40 >> 2 ) ;
V_428 = 1 ;
break;
default:
V_1172 = V_1171 = 0 ;
break;
}
V_1169 = V_1180 ;
if ( V_484 -> V_549 == V_1181 ) {
T_1 V_1182 , V_1183 ;
V_1169 = ( V_1172 == V_1184 ?
V_1185 :
( V_1172 == V_1186 ?
V_1187 : V_1188 ) ) ;
V_1182 = F_445 ( V_484 ) -
( V_1166 + sizeof( struct V_567 ) ) ;
V_1183 = V_1182 + V_484 -> V_1189 ;
V_1169 |= ( V_1182 / 2 ) << V_1190 ;
V_1169 |= ( V_1183 / 2 ) << V_1191 ;
}
V_1170 = F_446 ( V_484 ) -
( V_1166 + sizeof( struct V_567 ) ) ;
V_860 = ( ( ( V_1166 / 2 ) << V_1192 ) |
( V_490 << V_572 ) |
( ( V_1170 / 2 ) << V_1193 ) |
( V_1171 << V_1194 ) |
( ( V_1168 < V_1195 ) ? V_1196 : 0 ) |
( ( V_1167 == V_1174 ) ? V_1197 : 0 ) |
( V_428 ? V_1198 : 0 ) |
V_1169 ) ;
return V_860 ;
}
static T_10 F_447 ( struct V_483 * V_484 ,
struct V_308 * V_11 )
{
struct V_3 * V_4 = F_399 ( V_11 ) ;
unsigned long V_1199 , V_1200 ;
struct V_581 * V_582 ;
struct V_563 * V_493 ;
struct V_567 * V_341 ;
unsigned int V_490 , V_1201 ;
struct V_1164 * V_1165 ;
int V_798 , V_26 , V_1202 ;
T_1 V_502 , V_1203 ;
V_26 = F_448 ( V_484 ) ;
V_493 = & V_4 -> V_587 [ V_26 ] ;
V_582 = F_214 ( V_11 , V_26 ) ;
if ( F_217 ( V_493 ) <= ( F_177 ( V_484 ) -> V_489 + 1 ) ) {
F_449 ( V_582 ) ;
F_225 ( V_4 -> V_508 , L_123 , V_11 -> V_1117 ) ;
V_493 -> V_1137 ++ ;
return V_1204 ;
}
if ( V_484 -> V_490 < V_1205 ) {
unsigned int V_1166 = V_1205 - V_484 -> V_490 ;
if ( F_450 ( V_484 , V_1166 ) )
goto V_217;
F_451 ( V_484 , V_1166 ) ;
}
V_490 = sizeof( struct V_567 ) + 15 ;
if ( F_452 ( V_484 ) < V_490 ) {
struct V_483 * V_1206 ;
V_1206 = F_453 ( V_484 , V_490 ) ;
if ( ! V_1206 ) {
V_493 -> V_1137 ++ ;
goto V_1207;
}
F_454 ( V_484 ) ;
V_484 = V_1206 ;
} else
F_455 ( V_484 ) ;
V_1199 = ( ( unsigned long ) V_484 -> V_35 & ( 16 - 1 ) ) ;
V_1200 = V_1199 + sizeof( struct V_567 ) ;
V_1165 = (struct V_1164 * ) V_484 -> V_35 ;
V_341 = (struct V_567 * ) F_456 ( V_484 , V_1200 ) ;
V_490 = V_484 -> V_490 - sizeof( struct V_567 ) ;
V_341 -> V_87 = F_439 ( F_440 ( V_484 , V_1165 , V_1199 , V_490 ) ) ;
V_341 -> V_1208 = 0 ;
V_490 = F_208 ( V_484 ) ;
V_502 = V_4 -> V_304 -> V_1209 ( V_4 -> V_508 , V_484 -> V_35 ,
V_490 , V_575 ) ;
V_798 = V_493 -> V_798 ;
V_493 -> V_566 [ V_798 ] . V_484 = V_484 ;
V_493 -> V_566 [ V_798 ] . V_502 = V_502 ;
V_1203 = V_1210 ;
if ( ++ V_493 -> V_1211 == V_493 -> V_804 ) {
V_493 -> V_1211 = 0 ;
V_1203 |= V_577 ;
V_493 -> V_578 ++ ;
}
V_1202 = V_490 ;
V_1201 = F_177 ( V_484 ) -> V_489 ;
while ( V_1202 > 0 ) {
V_1202 -= V_579 ;
V_1201 ++ ;
}
while ( V_490 > 0 ) {
unsigned int V_1212 = V_490 ;
if ( V_1212 > V_579 )
V_1212 = V_579 ;
F_438 ( V_493 , V_798 , V_502 , V_1212 , V_1203 , V_1201 ) ;
V_1203 = V_1201 = 0 ;
V_798 = F_210 ( V_493 , V_798 ) ;
V_502 += V_1212 ;
V_490 -= V_1212 ;
}
for ( V_26 = 0 ; V_26 < F_177 ( V_484 ) -> V_489 ; V_26 ++ ) {
const T_11 * V_1213 = & F_177 ( V_484 ) -> V_580 [ V_26 ] ;
V_490 = F_211 ( V_1213 ) ;
V_502 = V_4 -> V_304 -> V_507 ( V_4 -> V_508 , F_457 ( V_1213 ) ,
V_1213 -> V_1214 , V_490 ,
V_575 ) ;
V_493 -> V_566 [ V_798 ] . V_484 = NULL ;
V_493 -> V_566 [ V_798 ] . V_502 = V_502 ;
F_438 ( V_493 , V_798 , V_502 , V_490 , 0 , 0 ) ;
V_798 = F_210 ( V_493 , V_798 ) ;
}
if ( V_798 < V_493 -> V_798 )
V_493 -> V_799 ^= V_1215 ;
V_493 -> V_798 = V_798 ;
F_18 ( F_282 ( V_493 -> V_623 ) , V_493 -> V_799 | ( V_798 << 3 ) ) ;
if ( F_70 ( F_217 ( V_493 ) <= ( V_1216 + 1 ) ) ) {
F_449 ( V_582 ) ;
if ( F_217 ( V_493 ) > F_218 ( V_493 ) )
F_221 ( V_582 ) ;
}
V_217:
return V_1217 ;
V_1207:
V_493 -> V_1137 ++ ;
F_454 ( V_484 ) ;
goto V_217;
}
static int F_458 ( struct V_308 * V_11 , int V_1218 )
{
struct V_3 * V_4 = F_399 ( V_11 ) ;
int V_10 , V_1219 , V_1220 ;
if ( V_1218 < 68 || V_1218 > V_1221 )
return - V_21 ;
V_1219 = ( V_11 -> V_802 > V_806 ) ;
V_1220 = ( V_1218 > V_806 ) ;
V_11 -> V_802 = V_1218 ;
if ( ! F_416 ( V_11 ) ||
( V_1219 == V_1220 ) )
return 0 ;
F_404 ( V_4 , V_11 ) ;
F_267 ( V_4 ) ;
F_394 ( V_4 ) ;
V_10 = F_274 ( V_4 ) ;
if ( V_10 )
return V_10 ;
F_400 ( & V_4 -> V_155 ) ;
V_10 = F_387 ( V_4 ) ;
if ( ! V_10 ) {
F_401 ( & V_4 -> V_15 ) ;
V_4 -> V_15 . V_337 = V_338 + V_336 ;
V_4 -> V_15 . V_35 = ( unsigned long ) V_4 ;
V_4 -> V_15 . V_1121 = F_110 ;
V_10 = F_25 ( V_4 , 1 ) ;
if ( V_10 )
F_388 ( V_4 ) ;
}
F_402 ( & V_4 -> V_155 ) ;
if ( ! V_10 ) {
F_403 ( V_11 ) ;
if ( V_4 -> V_39 . V_49 != V_330 )
F_100 ( V_11 ) ;
F_111 ( & V_4 -> V_15 ) ;
}
return V_10 ;
}
static void F_459 ( struct V_308 * V_11 ,
struct V_1222 * V_1223 )
{
struct V_3 * V_4 = F_399 ( V_11 ) ;
struct V_1224 * V_1225 = & V_4 -> V_1225 ;
F_460 ( V_1223 -> V_1226 , V_1227 , sizeof( V_1223 -> V_1226 ) ) ;
F_460 ( V_1223 -> V_1228 , V_1229 , sizeof( V_1223 -> V_1228 ) ) ;
snprintf ( V_1223 -> V_1230 , sizeof( V_1223 -> V_1230 ) , L_124 ,
V_1225 -> V_1231 , V_1225 -> V_1232 ) ;
if ( V_4 -> V_25 -> V_339 != V_343 )
F_460 ( V_1223 -> V_1233 , F_461 ( V_4 -> V_1234 ) ,
sizeof( V_1223 -> V_1233 ) ) ;
}
static int F_462 ( struct V_308 * V_11 , struct V_1235 * V_1152 )
{
struct V_3 * V_4 = F_399 ( V_11 ) ;
struct V_38 * V_13 ;
V_13 = & V_4 -> V_39 ;
memset ( V_1152 , 0 , sizeof( * V_1152 ) ) ;
V_1152 -> V_1236 = V_4 -> V_175 ;
V_1152 -> V_173 = V_13 -> V_173 ;
V_1152 -> V_174 = V_13 -> V_215 ;
V_1152 -> V_285 = V_13 -> V_201 ;
F_463 ( V_1152 , V_13 -> V_160 ) ;
V_1152 -> V_301 = V_13 -> V_161 ;
V_1152 -> V_30 = ( V_4 -> V_87 & V_344 ) ? V_1237 : V_1238 ;
V_1152 -> V_1239 = ( V_4 -> V_87 & V_345 ) ?
V_1240 : V_1241 ;
return 0 ;
}
static int F_464 ( struct V_308 * V_11 , struct V_1235 * V_1152 )
{
struct V_3 * V_4 = F_399 ( V_11 ) ;
struct V_38 * V_13 = & V_4 -> V_39 ;
V_13 -> V_174 = V_1152 -> V_174 ;
V_13 -> V_302 = F_465 ( V_1152 ) ;
V_13 -> V_301 = V_1152 -> V_301 ;
V_13 -> V_285 = V_1152 -> V_285 ;
return F_114 ( V_4 ) ;
}
static T_3 F_466 ( struct V_308 * V_11 )
{
struct V_3 * V_4 = F_399 ( V_11 ) ;
return V_4 -> V_1242 ;
}
static void F_467 ( struct V_308 * V_11 , T_3 V_1243 )
{
struct V_3 * V_4 = F_399 ( V_11 ) ;
V_4 -> V_1242 = V_1243 ;
}
static int F_468 ( struct V_308 * V_11 )
{
struct V_3 * V_4 = F_399 ( V_11 ) ;
if ( V_4 -> V_39 . V_285 )
return F_114 ( V_4 ) ;
return 0 ;
}
static int F_469 ( struct V_308 * V_11 )
{
struct V_3 * V_4 = F_399 ( V_11 ) ;
return V_4 -> V_1244 ;
}
static int F_470 ( struct V_308 * V_11 ,
struct V_1245 * V_1246 , T_5 * V_35 )
{
struct V_3 * V_4 = F_399 ( V_11 ) ;
T_3 V_486 , V_490 , V_2 ;
V_486 = V_1246 -> V_486 ;
V_490 = V_1246 -> V_490 ;
if ( V_486 + V_490 < V_486 )
return - V_21 ;
if ( V_486 >= V_4 -> V_1244 )
return - V_21 ;
if ( V_486 + V_490 > V_4 -> V_1244 )
V_490 = V_1246 -> V_490 = V_4 -> V_1244 - V_486 ;
if ( V_486 & 3 ) {
T_3 V_1247 , V_1248 ;
V_1247 = V_486 & 3 ;
V_1248 = 4 - V_1247 ;
if ( V_1248 > V_490 )
V_1248 = V_490 ;
V_2 = F_16 ( F_471 ( ( V_486 - V_1247 ) / 4 ) ) ;
memcpy ( V_35 , ( ( char * ) & V_2 ) + V_1247 , V_1248 ) ;
V_35 += V_1248 ;
V_490 -= V_1248 ;
V_486 += V_1248 ;
}
while ( V_490 >= 4 ) {
V_2 = F_16 ( F_471 ( V_486 / 4 ) ) ;
memcpy ( V_35 , & V_2 , 4 ) ;
V_35 += 4 ;
V_490 -= 4 ;
V_486 += 4 ;
}
if ( V_490 ) {
V_2 = F_16 ( F_471 ( V_486 / 4 ) ) ;
memcpy ( V_35 , & V_2 , V_490 ) ;
}
return 0 ;
}
static void F_472 ( int V_1249 , T_5 * V_1250 )
{
switch ( V_1249 ) {
case V_1251 :
case V_1252 :
* V_1250 = V_1184 ;
break;
case V_1253 :
case V_1254 :
* V_1250 = V_1186 ;
break;
case V_1255 :
case V_1256 :
* V_1250 = V_1257 ;
break;
case V_1258 :
case V_1259 :
* V_1250 = V_1260 ;
break;
case V_1261 :
case V_1262 :
* V_1250 = V_1263 ;
break;
default:
* V_1250 = 0 ;
break;
}
}
static int F_473 ( T_1 V_421 , int * V_1249 )
{
switch ( V_421 ) {
case V_1264 :
* V_1249 = V_1251 ;
break;
case V_1265 :
* V_1249 = V_1253 ;
break;
case V_1266 :
* V_1249 = V_1258 ;
break;
case V_1267 :
* V_1249 = V_1255 ;
break;
case V_1268 :
* V_1249 = V_1252 ;
break;
case V_1269 :
* V_1249 = V_1254 ;
break;
case V_1270 :
* V_1249 = V_1259 ;
break;
case V_477 :
* V_1249 = V_1256 ;
break;
case V_425 :
case V_1271 :
case V_1272 :
case V_426 :
* V_1249 = V_1273 ;
break;
default:
return 0 ;
}
return 1 ;
}
static int F_474 ( int V_1249 , T_1 * V_421 )
{
switch ( V_1249 ) {
case V_1251 :
* V_421 = V_1264 ;
break;
case V_1253 :
* V_421 = V_1265 ;
break;
case V_1274 :
case V_1258 :
case V_1261 :
* V_421 = V_1266 ;
break;
case V_1255 :
* V_421 = V_1267 ;
break;
case V_1252 :
* V_421 = V_1268 ;
break;
case V_1254 :
* V_421 = V_1269 ;
break;
case V_1275 :
case V_1259 :
case V_1262 :
* V_421 = V_1270 ;
break;
case V_1256 :
* V_421 = V_477 ;
break;
default:
return 0 ;
}
return 1 ;
}
static T_1 F_475 ( T_1 V_928 )
{
T_1 V_1276 = 0 ;
if ( V_928 & V_1277 )
V_1276 |= V_1278 ;
if ( V_928 & V_1279 )
V_1276 |= V_1280 ;
if ( V_928 & V_1281 )
V_1276 |= V_1282 ;
if ( V_928 & V_1283 )
V_1276 |= V_1284 ;
if ( V_928 & V_1285 )
V_1276 |= V_1286 ;
if ( V_928 & ( V_1287 << V_1288 ) )
V_1276 |= V_1289 ;
if ( V_928 & ( V_1287 << V_1290 ) )
V_1276 |= V_1291 ;
return V_1276 ;
}
static int F_476 ( T_1 V_1276 , T_1 * V_928 )
{
T_1 V_403 = 0 ;
if ( V_1276 & V_1278 )
V_403 |= V_1277 ;
if ( V_1276 & V_1280 )
V_403 |= V_1279 ;
if ( V_1276 & V_1282 )
V_403 |= V_1281 ;
if ( V_1276 & V_1284 )
V_403 |= V_1283 ;
if ( V_1276 & V_1286 )
V_403 |= V_1285 ;
if ( V_1276 & V_1289 )
V_403 |= ( V_1287 << V_1288 ) ;
if ( V_1276 & V_1291 )
V_403 |= ( V_1287 << V_1290 ) ;
* V_928 = V_403 ;
return 1 ;
}
static int F_477 ( struct V_3 * V_4 , struct V_1292 * V_1293 )
{
T_1 V_421 ;
V_1293 -> V_35 = 0 ;
if ( ! F_474 ( V_1293 -> V_1249 , & V_421 ) )
return - V_21 ;
if ( V_4 -> V_25 -> V_927 [ V_421 - V_425 ] &
V_1294 )
V_1293 -> V_35 = V_1295 ;
else
V_1293 -> V_35 = F_475 ( V_4 -> V_25 -> V_928 [ V_421 -
V_425 ] ) ;
return 0 ;
}
static void F_478 ( struct V_908 * V_341 ,
struct V_1296 * V_1297 )
{
T_3 V_584 ;
T_4 V_1298 ;
V_584 = ( V_341 -> V_403 [ 3 ] & V_1299 ) >> V_1300 ;
V_1297 -> V_1301 . V_1302 . V_1303 = F_479 ( V_584 ) ;
V_584 = ( V_341 -> V_403 [ 3 ] & V_1304 ) >> V_1305 ;
V_1297 -> V_1301 . V_1302 . V_1306 = F_479 ( V_584 ) ;
V_584 = ( V_341 -> V_911 [ 3 ] & V_1299 ) >> V_1300 ;
V_1297 -> V_1307 . V_1302 . V_1303 = F_479 ( V_584 ) ;
V_584 = ( V_341 -> V_911 [ 3 ] & V_1304 ) >> V_1305 ;
V_1297 -> V_1307 . V_1302 . V_1306 = F_479 ( V_584 ) ;
V_1297 -> V_1301 . V_1302 . V_1308 = ( V_341 -> V_403 [ 2 ] & V_1309 ) >>
V_1310 ;
V_1297 -> V_1307 . V_1302 . V_1308 = ( V_341 -> V_911 [ 2 ] & V_1309 ) >>
V_1310 ;
switch ( V_1297 -> V_1249 ) {
case V_1251 :
case V_1253 :
case V_1255 :
V_1298 = ( ( V_341 -> V_403 [ 2 ] & V_1311 ) >>
V_1312 ) >> 16 ;
V_1297 -> V_1301 . V_1302 . V_1313 = F_442 ( V_1298 ) ;
V_1298 = ( ( V_341 -> V_403 [ 2 ] & V_1311 ) >>
V_1312 ) & 0xffff ;
V_1297 -> V_1301 . V_1302 . V_1314 = F_442 ( V_1298 ) ;
V_1298 = ( ( V_341 -> V_911 [ 2 ] & V_1311 ) >>
V_1312 ) >> 16 ;
V_1297 -> V_1307 . V_1302 . V_1313 = F_442 ( V_1298 ) ;
V_1298 = ( ( V_341 -> V_911 [ 2 ] & V_1311 ) >>
V_1312 ) & 0xffff ;
V_1297 -> V_1307 . V_1302 . V_1314 = F_442 ( V_1298 ) ;
break;
case V_1258 :
case V_1261 :
V_584 = ( V_341 -> V_403 [ 2 ] & V_1311 ) >>
V_1312 ;
V_1297 -> V_1301 . V_1315 . V_1316 = F_479 ( V_584 ) ;
V_584 = ( V_341 -> V_911 [ 2 ] & V_1311 ) >>
V_1312 ;
V_1297 -> V_1307 . V_1315 . V_1316 = F_479 ( V_584 ) ;
break;
case V_1273 :
V_584 = ( V_341 -> V_403 [ 2 ] & V_1311 ) >>
V_1312 ;
V_1297 -> V_1301 . V_1317 . V_1318 = F_479 ( V_584 ) ;
V_584 = ( V_341 -> V_911 [ 2 ] & V_1311 ) >>
V_1312 ;
V_1297 -> V_1307 . V_1317 . V_1318 = F_479 ( V_584 ) ;
V_1297 -> V_1301 . V_1317 . V_1319 =
( V_341 -> V_403 [ 2 ] & V_1320 ) >>
V_1321 ;
V_1297 -> V_1307 . V_1317 . V_1319 =
( V_341 -> V_911 [ 2 ] & V_1320 ) >>
V_1321 ;
V_1297 -> V_1301 . V_1317 . V_1322 = V_1323 ;
break;
default:
break;
}
}
static int F_480 ( struct V_3 * V_4 ,
struct V_1292 * V_1293 )
{
struct V_24 * V_25 = V_4 -> V_25 ;
struct V_908 * V_341 ;
struct V_1296 * V_1297 = & V_1293 -> V_1324 ;
T_4 V_386 ;
T_1 V_421 ;
int V_860 = 0 ;
V_386 = F_172 ( V_4 , ( T_4 ) V_1293 -> V_1324 . V_1325 ) ;
V_341 = & V_25 -> V_909 [ V_386 ] ;
if ( ! V_341 -> V_914 ) {
F_481 ( V_4 -> V_11 , L_125 ,
V_25 -> V_375 , ( T_4 ) V_1293 -> V_1324 . V_1325 , V_386 ) ;
return - V_21 ;
}
V_421 = ( V_341 -> V_403 [ 0 ] & V_1326 ) >>
V_1327 ;
V_860 = F_473 ( V_421 , & V_1297 -> V_1249 ) ;
if ( V_860 < 0 ) {
F_481 ( V_4 -> V_11 , L_126 ,
V_25 -> V_375 ) ;
V_860 = - V_21 ;
goto V_217;
}
if ( V_1297 -> V_1249 == V_1258 || V_1297 -> V_1249 == V_1259 ) {
T_3 V_1319 = ( V_341 -> V_403 [ 2 ] & V_1320 ) >>
V_1321 ;
if ( V_1319 == V_1263 ) {
if ( V_1297 -> V_1249 == V_1258 )
V_1297 -> V_1249 = V_1261 ;
else
V_1297 -> V_1249 = V_1262 ;
}
}
switch ( V_1297 -> V_1249 ) {
case V_1251 :
case V_1253 :
case V_1255 :
case V_1258 :
case V_1261 :
F_478 ( V_341 , V_1297 ) ;
break;
case V_1252 :
case V_1254 :
case V_1256 :
case V_1259 :
case V_1262 :
V_860 = - V_21 ;
break;
case V_1273 :
F_478 ( V_341 , V_1297 ) ;
break;
default:
V_860 = - V_21 ;
break;
}
if ( V_860 < 0 )
goto V_217;
if ( V_341 -> V_410 & V_1328 )
V_1297 -> V_1329 = V_1330 ;
else
V_1297 -> V_1329 = ( V_341 -> V_410 & V_1331 ) >>
V_913 ;
V_1293 -> V_35 = F_173 ( V_4 ) ;
V_217:
return V_860 ;
}
static int F_482 ( struct V_3 * V_4 ,
struct V_1292 * V_1293 ,
T_3 * V_1332 )
{
struct V_24 * V_25 = V_4 -> V_25 ;
struct V_908 * V_341 ;
int V_26 , V_386 , V_1333 ;
unsigned long V_87 ;
int V_860 = 0 ;
V_1293 -> V_35 = F_173 ( V_4 ) ;
F_165 ( V_4 , V_87 ) ;
for ( V_1333 = 0 , V_26 = 0 ; V_26 < V_1293 -> V_35 ; V_26 ++ ) {
V_386 = F_172 ( V_4 , V_26 ) ;
V_341 = & V_25 -> V_909 [ V_386 ] ;
if ( ! V_341 -> V_914 )
continue;
if ( V_1333 == V_1293 -> V_1334 ) {
V_860 = - V_1335 ;
break;
}
V_1332 [ V_1333 ] = V_26 ;
V_1333 ++ ;
}
F_167 ( V_4 , V_87 ) ;
V_1293 -> V_1334 = V_1333 ;
return V_860 ;
}
static int F_483 ( struct V_308 * V_11 , struct V_1292 * V_1152 ,
T_3 * V_1332 )
{
struct V_3 * V_4 = F_399 ( V_11 ) ;
int V_860 = 0 ;
switch ( V_1152 -> V_1152 ) {
case V_1336 :
V_860 = F_477 ( V_4 , V_1152 ) ;
break;
case V_1337 :
V_1152 -> V_35 = V_4 -> V_624 ;
break;
case V_1338 :
V_1152 -> V_1334 = F_174 ( V_4 ) ;
break;
case V_1339 :
V_860 = F_480 ( V_4 , V_1152 ) ;
break;
case V_1340 :
V_860 = F_482 ( V_4 , V_1152 , V_1332 ) ;
break;
default:
V_860 = - V_21 ;
break;
}
return V_860 ;
}
static int F_484 ( struct V_3 * V_4 , struct V_1292 * V_1293 )
{
T_1 V_421 ;
T_1 V_928 = 0 ;
unsigned long V_87 ;
if ( ! F_474 ( V_1293 -> V_1249 , & V_421 ) )
return - V_21 ;
if ( V_421 < V_425 ||
V_421 > V_477 )
return - V_21 ;
if ( V_1293 -> V_35 & V_1295 ) {
F_165 ( V_4 , V_87 ) ;
V_928 = V_4 -> V_25 -> V_927 [ V_421 -
V_425 ] ;
V_928 |= V_1294 ;
F_18 ( F_171 ( V_421 - V_425 ) , V_928 ) ;
V_4 -> V_25 -> V_927 [ V_421 - V_425 ] = V_928 ;
F_167 ( V_4 , V_87 ) ;
return 0 ;
} else {
if ( V_4 -> V_25 -> V_927 [ V_421 - V_425 ] &
V_1294 ) {
F_165 ( V_4 , V_87 ) ;
V_928 = V_4 -> V_25 -> V_927 [ V_421 -
V_425 ] ;
V_928 &= ~ V_1294 ;
F_18 ( F_171 ( V_421 - V_425 ) ,
V_928 ) ;
V_4 -> V_25 -> V_927 [ V_421 - V_425 ] =
V_928 ;
F_167 ( V_4 , V_87 ) ;
}
}
if ( ! F_476 ( V_1293 -> V_35 , & V_928 ) )
return - V_21 ;
F_165 ( V_4 , V_87 ) ;
F_18 ( F_169 ( V_421 - V_425 ) , V_928 ) ;
V_4 -> V_25 -> V_928 [ V_421 - V_425 ] = V_928 ;
F_167 ( V_4 , V_87 ) ;
return 0 ;
}
static void F_485 ( struct V_1296 * V_1297 ,
struct V_908 * V_341 ,
int V_1341 , T_1 V_421 )
{
T_5 V_1250 = 0 ;
T_3 V_1342 , V_1343 , V_1344 , V_1345 , V_1316 , V_1346 ;
T_4 V_1347 , V_1348 , V_1349 , V_1350 ;
V_1342 = F_486 ( V_1297 -> V_1301 . V_1302 . V_1303 ) ;
V_1344 = F_486 ( V_1297 -> V_1307 . V_1302 . V_1303 ) ;
V_1343 = F_486 ( V_1297 -> V_1301 . V_1302 . V_1306 ) ;
V_1345 = F_486 ( V_1297 -> V_1307 . V_1302 . V_1306 ) ;
V_341 -> V_403 [ 0 ] = V_421 << V_1327 ;
V_341 -> V_911 [ 0 ] = V_1326 ;
V_341 -> V_403 [ 1 ] = ( T_1 ) V_1341 << V_1351 ;
V_341 -> V_911 [ 1 ] = V_1352 ;
V_341 -> V_403 [ 3 ] = ( T_1 ) V_1342 << V_1300 ;
V_341 -> V_403 [ 3 ] |= V_1343 ;
V_341 -> V_911 [ 3 ] = ( T_1 ) V_1344 << V_1300 ;
V_341 -> V_911 [ 3 ] |= V_1345 ;
V_341 -> V_403 [ 2 ] |= ( ( T_1 ) V_1297 -> V_1301 . V_1302 . V_1308 <<
V_1310 ) ;
V_341 -> V_911 [ 2 ] |= ( ( T_1 ) V_1297 -> V_1307 . V_1302 . V_1308 <<
V_1310 ) ;
switch ( V_1297 -> V_1249 ) {
case V_1251 :
case V_1253 :
case V_1255 :
V_1347 = F_441 ( V_1297 -> V_1301 . V_1302 . V_1313 ) ;
V_1349 = F_441 ( V_1297 -> V_1307 . V_1302 . V_1313 ) ;
V_1348 = F_441 ( V_1297 -> V_1301 . V_1302 . V_1314 ) ;
V_1350 = F_441 ( V_1297 -> V_1307 . V_1302 . V_1314 ) ;
V_341 -> V_403 [ 2 ] |= ( ( ( T_1 ) V_1347 << 16 ) | V_1348 ) ;
V_341 -> V_911 [ 2 ] |= ( ( ( T_1 ) V_1349 << 16 ) | V_1350 ) ;
F_472 ( V_1297 -> V_1249 , & V_1250 ) ;
break;
case V_1258 :
case V_1261 :
V_1316 = F_486 ( V_1297 -> V_1301 . V_1315 . V_1316 ) ;
V_1346 = F_486 ( V_1297 -> V_1307 . V_1315 . V_1316 ) ;
V_341 -> V_403 [ 2 ] |= V_1316 ;
V_341 -> V_911 [ 2 ] |= V_1346 ;
F_472 ( V_1297 -> V_1249 , & V_1250 ) ;
break;
case V_1273 :
V_1316 = F_486 ( V_1297 -> V_1301 . V_1317 . V_1318 ) ;
V_1346 = F_486 ( V_1297 -> V_1307 . V_1317 . V_1318 ) ;
V_341 -> V_403 [ 2 ] |= V_1316 ;
V_341 -> V_911 [ 2 ] |= V_1346 ;
V_1250 = V_1297 -> V_1301 . V_1317 . V_1319 ;
break;
default:
break;
}
V_341 -> V_403 [ 2 ] |= ( ( T_1 ) V_1250 << V_1321 ) ;
if ( V_1250 ) {
V_341 -> V_911 [ 2 ] |= V_1320 ;
}
}
static int F_487 ( struct V_3 * V_4 ,
struct V_1292 * V_1293 )
{
struct V_24 * V_25 = V_4 -> V_25 ;
struct V_908 * V_341 ;
struct V_1296 * V_1297 = & V_1293 -> V_1324 ;
struct V_835 * V_393 = & V_25 -> V_836 [ V_4 -> V_30 ] ;
int V_1353 = V_393 -> V_837 ;
T_4 V_386 ;
T_1 V_421 ;
unsigned long V_87 ;
int V_10 , V_860 ;
V_860 = 0 ;
V_386 = V_1293 -> V_1324 . V_1325 ;
if ( V_386 >= F_173 ( V_4 ) )
return - V_21 ;
if ( V_1297 -> V_1249 == V_1273 ) {
int V_26 ;
int V_1354 = 0 ;
struct V_1355 * V_1356 = & V_1297 -> V_1301 . V_1317 ;
struct V_1355 * V_1357 = & V_1297 -> V_1307 . V_1317 ;
if ( V_1356 -> V_1322 != V_1323 )
return - V_21 ;
F_165 ( V_4 , V_87 ) ;
for ( V_26 = 0 ; V_26 < V_1358 ; V_26 ++ ) {
if ( V_25 -> V_1359 [ V_26 ] ) {
if ( V_1356 -> V_1319 == V_25 -> V_1360 [ V_26 ] ) {
V_421 = V_25 -> V_1359 [ V_26 ] ;
V_25 -> V_1361 [ V_26 ] ++ ;
V_1354 = 1 ;
break;
}
} else {
switch ( V_26 ) {
case 0 :
V_421 = V_425 ;
break;
case 1 :
V_421 = V_1271 ;
break;
case 2 :
V_421 = V_1272 ;
break;
case 3 :
V_421 = V_426 ;
break;
default:
break;
}
V_860 = F_149 ( V_4 , V_421 , 0 ,
V_1356 -> V_1319 ,
V_1356 -> V_1308 ,
V_1357 -> V_1308 ) ;
if ( V_860 )
goto V_217;
V_860 = F_147 ( V_4 , V_421 , 1 ) ;
if ( V_860 )
goto V_217;
V_25 -> V_1359 [ V_26 ] = V_421 ;
V_25 -> V_1360 [ V_26 ] = V_1356 -> V_1319 ;
V_25 -> V_1361 [ V_26 ] ++ ;
V_1354 = 1 ;
break;
}
}
if ( ! V_1354 ) {
F_481 ( V_4 -> V_11 , L_127 ,
V_25 -> V_375 , V_67 , V_1356 -> V_1319 ) ;
V_860 = - V_21 ;
goto V_217;
}
F_167 ( V_4 , V_87 ) ;
} else {
if ( ! F_474 ( V_1297 -> V_1249 , & V_421 ) ) {
return - V_21 ;
}
}
F_165 ( V_4 , V_87 ) ;
V_386 = F_172 ( V_4 , V_386 ) ;
V_341 = & V_25 -> V_909 [ V_386 ] ;
memset ( V_341 , 0 , sizeof( * V_341 ) ) ;
switch ( V_1297 -> V_1249 ) {
case V_1251 :
case V_1253 :
case V_1255 :
case V_1258 :
case V_1261 :
F_485 ( V_1297 , V_341 , V_1353 , V_421 ) ;
break;
case V_1252 :
case V_1254 :
case V_1256 :
case V_1259 :
case V_1262 :
F_481 ( V_4 -> V_11 , L_128 ,
V_25 -> V_375 , V_67 , V_1297 -> V_1249 ) ;
V_860 = - V_21 ;
goto V_217;
case V_1273 :
F_485 ( V_1297 , V_341 , V_1353 , V_421 ) ;
break;
default:
F_481 ( V_4 -> V_11 , L_129 ,
V_25 -> V_375 , V_67 , V_1297 -> V_1249 ) ;
V_860 = - V_21 ;
goto V_217;
}
if ( V_1297 -> V_1329 == V_1330 ) {
V_341 -> V_410 = V_1328 ;
} else {
if ( V_1297 -> V_1329 >= V_4 -> V_624 ) {
F_481 ( V_4 -> V_11 , L_130 ,
V_25 -> V_375 , V_67 ,
( long long ) V_1297 -> V_1329 ) ;
V_860 = - V_21 ;
goto V_217;
}
V_341 -> V_410 = ( V_912 |
( V_1297 -> V_1329 <<
V_913 ) ) ;
}
V_10 = F_141 ( V_4 , V_386 , V_341 -> V_403 , V_341 -> V_911 ) ;
if ( V_10 ) {
V_860 = - V_21 ;
goto V_217;
}
V_10 = F_142 ( V_4 , V_386 , V_341 -> V_410 ) ;
if ( V_10 ) {
V_860 = - V_21 ;
goto V_217;
}
V_341 -> V_914 = 1 ;
V_4 -> V_478 . V_482 ++ ;
V_217:
F_167 ( V_4 , V_87 ) ;
return V_860 ;
}
static int F_488 ( struct V_3 * V_4 , T_3 V_1362 )
{
struct V_24 * V_25 = V_4 -> V_25 ;
struct V_908 * V_341 ;
T_4 V_386 ;
unsigned long V_87 ;
T_1 V_421 ;
int V_860 = 0 ;
if ( V_1362 >= F_173 ( V_4 ) )
return - V_21 ;
F_165 ( V_4 , V_87 ) ;
V_386 = F_172 ( V_4 , V_1362 ) ;
V_341 = & V_25 -> V_909 [ V_386 ] ;
V_421 = ( V_341 -> V_403 [ 0 ] & V_1326 ) >>
V_1327 ;
if ( V_421 >= V_425 && V_421 <= V_426 ) {
int V_26 ;
for ( V_26 = 0 ; V_26 < V_1358 ; V_26 ++ ) {
if ( V_25 -> V_1359 [ V_26 ] == V_421 ) {
V_25 -> V_1361 [ V_26 ] -- ;
if ( ! V_25 -> V_1361 [ V_26 ] ) {
V_860 = F_147 ( V_4 ,
V_421 ,
0 ) ;
if ( V_860 )
goto V_217;
V_25 -> V_1359 [ V_26 ] = 0 ;
V_25 -> V_1360 [ V_26 ] = 0 ;
}
break;
}
}
if ( V_26 == V_1358 ) {
F_481 ( V_4 -> V_11 , L_131 ,
V_25 -> V_375 , V_67 ,
( unsigned long long ) V_421 ) ;
V_860 = - V_21 ;
goto V_217;
}
}
V_860 = F_140 ( V_4 , V_386 ) ;
if ( V_860 )
goto V_217;
V_341 -> V_914 = 0 ;
V_4 -> V_478 . V_482 -- ;
V_217:
F_167 ( V_4 , V_87 ) ;
return V_860 ;
}
static int F_489 ( struct V_308 * V_11 , struct V_1292 * V_1152 )
{
struct V_3 * V_4 = F_399 ( V_11 ) ;
int V_860 = 0 ;
switch ( V_1152 -> V_1152 ) {
case V_1363 :
V_860 = F_484 ( V_4 , V_1152 ) ;
break;
case V_1364 :
V_860 = F_487 ( V_4 , V_1152 ) ;
break;
case V_1365 :
V_860 = F_488 ( V_4 , V_1152 -> V_1324 . V_1325 ) ;
break;
default:
V_860 = - V_21 ;
break;
}
return V_860 ;
}
static void F_490 ( struct V_308 * V_11 , T_3 V_1366 , T_5 * V_35 )
{
struct V_3 * V_4 = F_399 ( V_11 ) ;
int V_26 ;
if ( V_1366 != V_1367 )
return;
if ( V_4 -> V_87 & V_366 ) {
memcpy ( V_35 , V_1368 ,
sizeof( V_1368 ) ) ;
V_35 += sizeof( V_1368 ) ;
} else {
memcpy ( V_35 , V_1369 ,
sizeof( V_1369 ) ) ;
V_35 += sizeof( V_1369 ) ;
}
for ( V_26 = 0 ; V_26 < V_4 -> V_624 ; V_26 ++ ) {
memcpy ( V_35 , V_1370 ,
sizeof( V_1370 ) ) ;
V_35 += sizeof( V_1370 ) ;
}
for ( V_26 = 0 ; V_26 < V_4 -> V_622 ; V_26 ++ ) {
memcpy ( V_35 , V_1371 ,
sizeof( V_1371 ) ) ;
V_35 += sizeof( V_1371 ) ;
}
}
static int F_491 ( struct V_308 * V_11 , int V_1366 )
{
struct V_3 * V_4 = F_399 ( V_11 ) ;
if ( V_1366 != V_1367 )
return - V_21 ;
return ( V_4 -> V_87 & V_366 ?
V_1372 :
V_1373 ) +
( V_4 -> V_624 * V_1374 ) +
( V_4 -> V_622 * V_1375 ) ;
}
static void F_492 ( struct V_308 * V_11 ,
struct V_1376 * V_1131 , T_1 * V_35 )
{
struct V_3 * V_4 = F_399 ( V_11 ) ;
int V_26 ;
F_411 ( V_4 ) ;
if ( V_4 -> V_87 & V_366 ) {
memcpy ( V_35 , & V_4 -> V_662 . V_663 ,
sizeof( struct V_660 ) ) ;
V_35 += ( sizeof( struct V_660 ) / sizeof( T_1 ) ) ;
} else {
memcpy ( V_35 , & V_4 -> V_662 . V_742 ,
sizeof( struct V_741 ) ) ;
V_35 += ( sizeof( struct V_741 ) / sizeof( T_1 ) ) ;
}
for ( V_26 = 0 ; V_26 < V_4 -> V_624 ; V_26 ++ ) {
struct V_492 * V_493 = & V_4 -> V_625 [ V_26 ] ;
F_223 ( V_4 , V_493 , 0 ) ;
V_35 [ 0 ] = V_493 -> V_520 ;
V_35 [ 1 ] = V_493 -> V_558 ;
V_35 [ 2 ] = V_493 -> V_559 ;
V_35 [ 3 ] = V_493 -> V_523 ;
V_35 [ 4 ] = V_493 -> V_598 ;
V_35 += 5 ;
}
for ( V_26 = 0 ; V_26 < V_4 -> V_622 ; V_26 ++ ) {
struct V_563 * V_493 = & V_4 -> V_587 [ V_26 ] ;
V_35 [ 0 ] = V_493 -> V_623 ;
V_35 [ 1 ] = V_493 -> V_569 ;
V_35 [ 2 ] = V_493 -> V_570 ;
V_35 [ 3 ] = V_493 -> V_1137 ;
V_35 += 4 ;
}
}
static T_1 F_493 ( struct V_3 * V_4 )
{
if ( V_4 -> V_87 & V_366 )
return F_6 ( V_269 ) ;
else
return F_6 ( V_1001 ) ;
}
static void F_494 ( struct V_3 * V_4 , T_1 V_2 )
{
if ( V_4 -> V_87 & V_366 )
F_9 ( V_269 , V_2 ) ;
else
F_9 ( V_1001 , V_2 ) ;
}
static void F_495 ( struct V_3 * V_4 , int V_14 )
{
T_1 V_2 , V_1 , V_397 ;
if ( V_4 -> V_87 & V_366 ) {
V_1 = V_269 ;
V_397 = V_271 ;
} else {
V_1 = V_1001 ;
V_397 = V_998 ;
}
V_2 = F_6 ( V_1 ) ;
if ( V_14 )
V_2 |= V_397 ;
else
V_2 &= ~ V_397 ;
F_9 ( V_1 , V_2 ) ;
}
static int F_496 ( struct V_308 * V_11 ,
enum V_1377 V_1378 )
{
struct V_3 * V_4 = F_399 ( V_11 ) ;
if ( ! F_416 ( V_11 ) )
return - V_1379 ;
switch ( V_1378 ) {
case V_1380 :
V_4 -> V_1381 = F_493 ( V_4 ) ;
return 1 ;
case V_1382 :
F_495 ( V_4 , 1 ) ;
break;
case V_1383 :
F_495 ( V_4 , 0 ) ;
break;
case V_1384 :
F_494 ( V_4 , V_4 -> V_1381 ) ;
}
return 0 ;
}
static int F_497 ( struct V_3 * V_4 , struct V_24 * V_25 ,
int V_29 , int V_18 )
{
if ( V_29 < V_1385 || V_29 > V_1386 )
return - V_21 ;
if ( V_18 < 0 || V_18 > V_20 )
return - V_21 ;
V_25 -> V_27 [ V_18 ] = V_29 ;
if ( V_4 -> V_25 -> V_339 == V_343 ) {
if ( F_16 ( F_498 ( V_18 ) ) != V_29 ) {
F_225 ( V_4 -> V_508 , L_132 ,
V_4 -> V_30 , V_18 , V_29 ,
( unsigned long long ) F_16 ( F_498 ( V_18 ) ) ) ;
return - V_21 ;
}
} else
F_18 ( F_498 ( V_18 ) , V_29 ) ;
return 0 ;
}
static int F_499 ( struct V_3 * V_4 , int V_1387 )
{
if ( V_1387 < 0 || V_1387 > V_1388 )
return - V_21 ;
F_18 ( V_1389 , V_1387 ) ;
return 0 ;
}
static int F_500 ( struct V_3 * V_4 , int V_29 , int V_1390 , int V_1391 )
{
if ( ( V_29 < V_1385 || V_29 > V_1386 ) ||
( V_1390 < 0 || V_1390 > 3 ) ||
( V_1391 < 0 || V_1391 > 0x1f ) )
return - V_21 ;
F_18 ( F_501 ( V_29 ) , ( V_1390 << V_1392 ) | V_1391 ) ;
return 0 ;
}
static int F_502 ( struct V_3 * V_4 , T_3 V_362 )
{
T_1 V_1393 , V_1394 = ( V_1395 |
( V_362 << V_1396 ) ) ;
int V_6 ;
if ( V_362 > ( V_1397 >> V_1396 ) )
return - V_21 ;
V_1393 = V_1394 ;
F_18 ( V_1398 , V_1393 ) ;
V_6 = 64 ;
do {
F_7 ( 5 ) ;
V_1393 = F_16 ( V_1398 ) ;
if ( V_1393 & V_1399 )
break;
} while ( V_6 -- );
if ( ! ( V_1393 & V_1399 ) ) {
F_225 ( V_4 -> V_508 , L_133 ,
( unsigned long long ) V_1393 ) ;
return - V_8 ;
}
V_1393 = V_1394 ;
F_18 ( V_1398 , V_1393 ) ;
V_6 = 64 ;
do {
F_7 ( 5 ) ;
V_1393 = F_16 ( V_1398 ) ;
if ( V_1393 & V_1399 )
break;
} while ( V_6 -- );
if ( ! ( V_1393 & V_1399 ) ) {
F_225 ( V_4 -> V_508 , L_133 ,
( unsigned long long ) V_1393 ) ;
return - V_8 ;
}
V_1393 = F_16 ( V_1398 ) ;
return ( V_1393 & V_1400 ) >> V_1401 ;
}
static int F_503 ( struct V_3 * V_4 , T_3 V_335 )
{
int V_10 = F_502 ( V_4 , V_335 ) ;
T_4 V_2 ;
if ( V_10 < 0 )
return V_10 ;
V_2 = ( V_10 << 8 ) ;
V_10 = F_502 ( V_4 , V_335 + 1 ) ;
if ( V_10 < 0 )
return V_10 ;
V_2 |= ( V_10 & 0xff ) ;
return V_2 ;
}
static int F_504 ( struct V_3 * V_4 , T_3 V_335 )
{
int V_10 = F_502 ( V_4 , V_335 ) ;
T_4 V_2 ;
if ( V_10 < 0 )
return V_10 ;
V_2 = ( V_10 & 0xff ) ;
V_10 = F_502 ( V_4 , V_335 + 1 ) ;
if ( V_10 < 0 )
return V_10 ;
V_2 |= ( V_10 & 0xff ) << 8 ;
return V_2 ;
}
static int F_505 ( struct V_3 * V_4 , T_3 V_335 , char * V_1402 ,
int V_1403 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_1403 ; V_26 ++ ) {
int V_10 = F_502 ( V_4 , V_335 + V_26 ) ;
if ( V_10 < 0 )
return V_10 ;
* V_1402 ++ = V_10 ;
if ( ! V_10 )
break;
}
if ( V_26 >= V_1403 )
return - V_21 ;
return V_26 + 1 ;
}
static void F_506 ( struct V_3 * V_4 )
{
struct V_1224 * V_1225 = & V_4 -> V_1225 ;
int V_490 = strlen ( V_1225 -> V_1228 ) + 1 ;
const char * V_1404 = V_1225 -> V_1228 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_490 - 5 ; V_26 ++ ) {
if ( ! strncmp ( V_1404 + V_26 , L_134 , 6 ) )
break;
}
if ( V_26 >= V_490 - 5 )
return;
V_1404 += V_26 + 5 ;
sscanf ( V_1404 , L_124 , & V_1225 -> V_1231 , & V_1225 -> V_1232 ) ;
F_166 ( V_4 , V_472 , V_473 , V_4 -> V_11 ,
L_135 ,
V_1225 -> V_1231 , V_1225 -> V_1232 ) ;
if ( V_1225 -> V_1231 > V_1405 ||
( V_1225 -> V_1231 == V_1405 &&
V_1225 -> V_1232 >= V_1406 ) )
V_4 -> V_87 |= V_1407 ;
}
static int F_507 ( struct V_3 * V_4 , T_3 V_1182 , T_3 V_1408 )
{
unsigned int V_1409 = 0 ;
#define F_508 0x00000001
#define F_509 0x00000002
#define F_510 0x00000004
#define F_511 0x00000008
#define F_512 0x00000010
#define F_513 0x00000020
#define F_514 0x0000003f
F_166 ( V_4 , V_472 , V_473 , V_4 -> V_11 ,
L_136 , V_1182 , V_1408 ) ;
while ( V_1182 < V_1408 ) {
int V_490 , V_10 , V_1410 ;
char V_1402 [ 64 ] ;
T_5 * V_1411 ;
int V_1412 ;
if ( V_1409 == F_514 ) {
F_506 ( V_4 ) ;
return 1 ;
}
V_10 = F_502 ( V_4 , V_1182 + 2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_490 = V_10 ;
V_1182 += 3 ;
V_1410 = F_502 ( V_4 , V_1182 + 4 ) ;
V_10 = F_505 ( V_4 , V_1182 + 5 , V_1402 , 64 ) ;
if ( V_10 < 0 )
return V_10 ;
V_1411 = NULL ;
V_1412 = 0 ;
if ( ! strcmp ( V_1402 , L_137 ) ) {
V_1411 = V_4 -> V_1225 . V_1413 ;
V_1412 = V_1414 ;
V_1409 |= F_508 ;
} else if ( ! strcmp ( V_1402 , L_138 ) ) {
V_1411 = V_4 -> V_1225 . V_1415 ;
V_1412 = V_1416 ;
V_1409 |= F_509 ;
} else if ( ! strcmp ( V_1402 , L_139 ) ) {
V_1411 = V_4 -> V_1225 . V_1228 ;
V_1412 = V_1417 ;
V_1409 |= F_510 ;
} else if ( ! strcmp ( V_1402 , L_140 ) ) {
V_1411 = V_4 -> V_1225 . V_1418 ;
V_1412 = V_1146 ;
V_1409 |= F_511 ;
} else if ( ! strcmp ( V_1402 , L_141 ) ) {
V_1411 = & V_4 -> V_1225 . V_1419 ;
V_1412 = 1 ;
V_1409 |= F_512 ;
} else if ( ! strcmp ( V_1402 , L_142 ) ) {
V_1411 = V_4 -> V_1225 . V_1420 ;
V_1412 = V_1421 ;
V_1409 |= F_513 ;
}
if ( V_1412 && V_1410 > V_1412 ) {
F_225 ( V_4 -> V_508 , L_143 , V_1402 , V_1410 ) ;
return - V_21 ;
}
if ( V_1411 ) {
T_3 V_335 = V_1182 + 5 + V_10 ;
int V_26 ;
F_166 ( V_4 , V_472 , V_473 , V_4 -> V_11 ,
L_144 ,
V_1402 , V_1410 ) ;
for ( V_26 = 0 ; V_26 < V_1410 ; V_26 ++ )
* V_1411 ++ = F_502 ( V_4 , V_335 + V_26 ) ;
}
V_1182 += V_490 ;
}
return 0 ;
}
static void F_515 ( struct V_3 * V_4 , T_3 V_1182 )
{
T_3 V_486 ;
int V_10 ;
V_10 = F_504 ( V_4 , V_1182 + 1 ) ;
if ( V_10 < 0 )
return;
V_486 = V_10 + 3 ;
while ( V_1182 + V_486 < V_1422 ) {
T_3 V_1423 = V_1182 + V_486 ;
T_3 V_1408 ;
V_10 = F_502 ( V_4 , V_1423 ) ;
if ( V_10 != 0x90 )
return;
V_10 = F_504 ( V_4 , V_1423 + 1 ) ;
if ( V_10 < 0 )
return;
V_1423 = V_1182 + V_486 + 3 ;
V_1408 = V_1182 + V_486 + V_10 ;
V_486 += V_10 ;
V_10 = F_507 ( V_4 , V_1423 , V_1408 ) ;
if ( V_10 < 0 || V_10 == 1 )
return;
}
}
static T_3 F_516 ( struct V_3 * V_4 )
{
T_3 V_1182 = 0 , V_1408 = V_1422 , V_860 ;
int V_10 ;
while ( V_1182 < V_1408 ) {
V_860 = V_1182 ;
V_10 = F_503 ( V_4 , V_1182 + 0 ) ;
if ( V_10 != 0x55aa )
return 0 ;
V_10 = F_503 ( V_4 , V_1182 + 23 ) ;
if ( V_10 < 0 )
return 0 ;
V_1182 += V_10 ;
V_10 = F_503 ( V_4 , V_1182 + 0 ) ;
if ( V_10 != 0x5043 )
return 0 ;
V_10 = F_503 ( V_4 , V_1182 + 2 ) ;
if ( V_10 != 0x4952 )
return 0 ;
V_10 = F_502 ( V_4 , V_1182 + 20 ) ;
if ( V_10 < 0 )
return 0 ;
if ( V_10 != 0x01 ) {
V_10 = F_502 ( V_4 , V_860 + 2 ) ;
if ( V_10 < 0 )
return 0 ;
V_1182 = V_860 + ( V_10 * 512 ) ;
continue;
}
V_10 = F_504 ( V_4 , V_1182 + 8 ) ;
if ( V_10 < 0 )
return V_10 ;
V_860 += V_10 ;
V_10 = F_502 ( V_4 , V_860 + 0 ) ;
if ( V_10 != 0x82 )
return 0 ;
return V_860 ;
}
return 0 ;
}
static int F_517 ( struct V_3 * V_4 , const char * V_1424 )
{
if ( ! strcmp ( V_1424 , L_145 ) ) {
V_4 -> V_87 &= ~ ( V_344 |
V_88 ) ;
V_4 -> V_89 = V_1425 ;
} else if ( ! strcmp ( V_1424 , L_146 ) ) {
V_4 -> V_87 |= ( V_88 |
V_344 ) ;
V_4 -> V_89 = V_1426 ;
} else if ( ! strcmp ( V_1424 , L_147 ) ) {
V_4 -> V_87 &= ~ V_88 ;
V_4 -> V_87 |= V_344 ;
V_4 -> V_89 = V_90 ;
} else if ( ! strcmp ( V_1424 , L_148 ) ) {
V_4 -> V_87 |= V_88 ;
V_4 -> V_87 &= ~ V_344 ;
V_4 -> V_89 = V_1426 ;
} else if ( ! strcmp ( V_1424 , L_149 ) || ! strcmp ( V_1424 , L_150 ) ) {
V_4 -> V_87 |= V_88 ;
V_4 -> V_87 &= ~ V_344 ;
V_4 -> V_87 |= V_345 ;
V_4 -> V_89 = V_1426 ;
} else {
return - V_21 ;
}
return 0 ;
}
static int F_518 ( struct V_3 * V_4 )
{
int V_1427 = 0 ;
if ( ( ! strcmp ( V_4 -> V_1225 . V_1413 , V_1428 ) ) ||
( ! strcmp ( V_4 -> V_1225 . V_1413 , V_1429 ) ) ||
( ! strcmp ( V_4 -> V_1225 . V_1413 , V_1430 ) ) ||
( ! strcmp ( V_4 -> V_1225 . V_1413 , V_1431 ) ) ||
( ! strcmp ( V_4 -> V_1225 . V_1413 , V_1432 ) ) ) {
V_1427 = 4 ;
} else if ( ( ! strcmp ( V_4 -> V_1225 . V_1413 , V_1433 ) ) ||
( ! strcmp ( V_4 -> V_1225 . V_1413 , V_1434 ) ) ||
( ! strcmp ( V_4 -> V_1225 . V_1413 , V_1435 ) ) ||
( ! strcmp ( V_4 -> V_1225 . V_1413 , V_1436 ) ) ) {
V_1427 = 2 ;
}
return V_1427 ;
}
static void F_519 ( struct V_3 * V_4 )
{
struct V_308 * V_11 = V_4 -> V_11 ;
struct V_1224 * V_1225 = & V_4 -> V_1225 ;
T_5 V_1437 ;
if ( ! F_428 ( & V_1225 -> V_1418 [ 0 ] ) ) {
F_225 ( V_4 -> V_508 , L_151 ) ;
V_4 -> V_87 &= ~ V_1407 ;
return;
}
if ( ! strcmp ( V_4 -> V_1225 . V_1413 , V_1432 ) ||
! strcmp ( V_4 -> V_1225 . V_1413 , V_1431 ) ) {
V_4 -> V_87 |= V_88 ;
V_4 -> V_87 &= ~ V_344 ;
V_4 -> V_87 |= V_345 ;
V_4 -> V_89 = V_90 ;
if ( V_4 -> V_30 > 1 ) {
V_4 -> V_87 |= V_344 ;
V_4 -> V_87 &= ~ V_88 ;
}
if ( V_4 -> V_87 & V_88 )
V_4 -> V_89 = V_1426 ;
} else if ( ! strcmp ( V_4 -> V_1225 . V_1413 , V_1435 ) ) {
V_4 -> V_87 |= ( V_88 | V_344 |
V_134 ) ;
} else if ( F_517 ( V_4 , V_4 -> V_1225 . V_1420 ) ) {
F_225 ( V_4 -> V_508 , L_152 ,
V_4 -> V_1225 . V_1420 ) ;
F_225 ( V_4 -> V_508 , L_153 ) ;
V_4 -> V_87 &= ~ V_1407 ;
return;
}
memcpy ( V_11 -> V_1104 , V_1225 -> V_1418 , V_1146 ) ;
V_1437 = V_11 -> V_1104 [ 5 ] ;
V_11 -> V_1104 [ 5 ] += V_4 -> V_30 ;
if ( V_11 -> V_1104 [ 5 ] < V_1437 )
V_11 -> V_1104 [ 4 ] ++ ;
}
static int F_520 ( struct V_3 * V_4 )
{
struct V_308 * V_11 = V_4 -> V_11 ;
int V_490 , V_26 ;
T_1 V_2 , V_1438 ;
T_5 V_1437 ;
V_2 = ( F_16 ( V_1439 ) & V_1440 ) ;
V_2 >>= V_1441 ;
V_490 = V_2 / 4 ;
V_4 -> V_1244 = V_490 ;
F_166 ( V_4 , V_472 , V_473 , V_4 -> V_11 ,
L_154 , ( unsigned long long ) V_2 ) ;
V_1438 = 0 ;
for ( V_26 = 0 ; V_26 < V_490 ; V_26 ++ ) {
V_2 = F_16 ( F_471 ( V_26 ) ) ;
V_1438 += ( V_2 >> 0 ) & 0xff ;
V_1438 += ( V_2 >> 8 ) & 0xff ;
V_1438 += ( V_2 >> 16 ) & 0xff ;
V_1438 += ( V_2 >> 24 ) & 0xff ;
}
F_166 ( V_4 , V_472 , V_473 , V_4 -> V_11 ,
L_155 , ( int ) ( V_1438 & 0xff ) ) ;
if ( ( V_1438 & 0xff ) != 0xab ) {
F_225 ( V_4 -> V_508 , L_156 , ( int ) ( V_1438 & 0xff ) ) ;
return - V_21 ;
}
V_2 = F_16 ( V_1442 ) ;
switch ( V_4 -> V_30 ) {
case 0 :
V_1437 = ( V_2 & V_1443 ) >>
V_1444 ;
break;
case 1 :
V_1437 = ( V_2 & V_1445 ) >>
V_1446 ;
break;
case 2 :
V_1437 = ( V_2 & V_1447 ) >>
V_1448 ;
break;
case 3 :
V_1437 = ( V_2 & V_1449 ) >>
V_1450 ;
break;
default:
F_225 ( V_4 -> V_508 , L_157 ,
V_4 -> V_30 ) ;
return - V_21 ;
}
F_166 ( V_4 , V_472 , V_473 , V_4 -> V_11 ,
L_158 , V_1437 ) ;
switch ( V_1437 ) {
case V_1451 :
V_4 -> V_87 &= ~ ( V_344 |
V_88 ) ;
V_4 -> V_89 = V_1425 ;
break;
case V_1452 :
V_4 -> V_87 &= ~ V_88 ;
V_4 -> V_87 |= V_344 ;
V_4 -> V_89 = V_90 ;
break;
case V_1453 :
V_4 -> V_87 |= V_88 ;
V_4 -> V_87 &= ~ V_344 ;
V_4 -> V_89 = V_1426 ;
break;
case V_1454 :
V_4 -> V_87 |= ( V_88 |
V_344 ) ;
V_4 -> V_89 = V_1426 ;
break;
default:
F_225 ( V_4 -> V_508 , L_159 , V_1437 ) ;
return - V_21 ;
}
V_2 = F_16 ( V_1455 ) ;
F_166 ( V_4 , V_472 , V_473 , V_4 -> V_11 ,
L_160 , ( unsigned long long ) V_2 ) ;
V_11 -> V_1104 [ 0 ] = ( V_2 >> 0 ) & 0xff ;
V_11 -> V_1104 [ 1 ] = ( V_2 >> 8 ) & 0xff ;
V_11 -> V_1104 [ 2 ] = ( V_2 >> 16 ) & 0xff ;
V_11 -> V_1104 [ 3 ] = ( V_2 >> 24 ) & 0xff ;
V_2 = F_16 ( V_1456 ) ;
F_166 ( V_4 , V_472 , V_473 , V_4 -> V_11 ,
L_161 , ( unsigned long long ) V_2 ) ;
V_11 -> V_1104 [ 4 ] = ( V_2 >> 0 ) & 0xff ;
V_11 -> V_1104 [ 5 ] = ( V_2 >> 8 ) & 0xff ;
if ( ! F_428 ( & V_11 -> V_1104 [ 0 ] ) ) {
F_225 ( V_4 -> V_508 , L_162 ,
V_11 -> V_1104 ) ;
return - V_21 ;
}
V_1437 = V_11 -> V_1104 [ 5 ] ;
V_11 -> V_1104 [ 5 ] += V_4 -> V_30 ;
if ( V_11 -> V_1104 [ 5 ] < V_1437 )
V_11 -> V_1104 [ 4 ] ++ ;
V_2 = F_16 ( V_1457 ) ;
F_166 ( V_4 , V_472 , V_473 , V_4 -> V_11 ,
L_163 , ( unsigned long long ) V_2 ) ;
if ( V_2 >= 8 * 4 )
return - V_21 ;
for ( V_26 = 0 ; V_26 < V_2 ; V_26 += 4 ) {
T_1 V_584 = F_16 ( F_471 ( 5 + ( V_26 / 4 ) ) ) ;
V_4 -> V_1225 . V_1413 [ V_26 + 3 ] = ( V_584 >> 0 ) & 0xff ;
V_4 -> V_1225 . V_1413 [ V_26 + 2 ] = ( V_584 >> 8 ) & 0xff ;
V_4 -> V_1225 . V_1413 [ V_26 + 1 ] = ( V_584 >> 16 ) & 0xff ;
V_4 -> V_1225 . V_1413 [ V_26 + 0 ] = ( V_584 >> 24 ) & 0xff ;
}
V_4 -> V_1225 . V_1413 [ V_2 ] = '\0' ;
V_2 = F_16 ( V_1458 ) ;
F_166 ( V_4 , V_472 , V_473 , V_4 -> V_11 ,
L_164 , ( unsigned long long ) V_2 ) ;
if ( V_2 >= 4 * 4 )
return - V_21 ;
for ( V_26 = 0 ; V_26 < V_2 ; V_26 += 4 ) {
T_1 V_584 = F_16 ( F_471 ( 14 + ( V_26 / 4 ) ) ) ;
V_4 -> V_1225 . V_1415 [ V_26 + 3 ] = ( V_584 >> 0 ) & 0xff ;
V_4 -> V_1225 . V_1415 [ V_26 + 2 ] = ( V_584 >> 8 ) & 0xff ;
V_4 -> V_1225 . V_1415 [ V_26 + 1 ] = ( V_584 >> 16 ) & 0xff ;
V_4 -> V_1225 . V_1415 [ V_26 + 0 ] = ( V_584 >> 24 ) & 0xff ;
}
V_4 -> V_1225 . V_1415 [ V_2 ] = '\0' ;
V_4 -> V_1225 . V_1419 =
F_16 ( V_1459 ) & V_1460 ;
F_166 ( V_4 , V_472 , V_473 , V_4 -> V_11 ,
L_165 , V_4 -> V_1225 . V_1419 ) ;
return 0 ;
}
static int F_521 ( struct V_3 * V_4 )
{
struct V_24 * V_25 = V_4 -> V_25 ;
if ( V_4 -> V_30 <= 1 )
V_4 -> V_87 |= V_366 ;
if ( ! V_25 -> V_481 ) {
if ( V_25 -> V_339 == V_343 ) {
V_25 -> V_481 = 2 ;
} else {
V_25 -> V_481 = F_518 ( V_4 ) ;
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
static int F_522 ( struct V_24 * V_25 , struct V_276 * V_498 ,
int V_1461 , int V_1462 , T_5 V_1463 , int type )
{
T_3 V_1464 = ( V_1461 << 16 ) | V_1462 ;
T_5 V_386 ;
if ( V_1461 < 0 || V_1462 < 0 )
return 0 ;
if ( type == V_1465 || type == V_1466 ) {
if ( ( ( V_1464 & V_277 ) != V_1467 ) &&
( ( V_1464 & V_277 ) != V_278 ) )
return 0 ;
} else {
if ( ( V_1464 & V_277 ) != V_1468 )
return 0 ;
}
F_48 ( L_166 ,
V_25 -> V_375 , V_1464 ,
type == V_1465 ? L_167 :
type == V_1466 ? L_168 : L_169 ,
V_1463 ) ;
if ( V_498 -> V_1469 [ type ] >= V_1470 ) {
F_523 ( L_170 ) ;
return - V_21 ;
}
V_386 = V_498 -> V_1469 [ type ] ;
V_498 -> V_274 [ type ] [ V_386 ] = V_1464 ;
V_498 -> V_1463 [ type ] [ V_386 ] = V_1463 ;
V_498 -> V_1469 [ type ] = V_386 + 1 ;
return 0 ;
}
static int F_524 ( struct V_276 * V_498 , int V_30 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_498 -> V_1469 [ V_1465 ] ; V_26 ++ ) {
if ( V_498 -> V_1463 [ V_1465 ] [ V_26 ] == V_30 )
return 1 ;
}
for ( V_26 = 0 ; V_26 < V_498 -> V_1469 [ V_1466 ] ; V_26 ++ ) {
if ( V_498 -> V_1463 [ V_1466 ] [ V_26 ] == V_30 )
return 1 ;
}
return 0 ;
}
static int F_525 ( struct V_276 * V_498 , int * V_1471 )
{
int V_30 , V_1333 ;
V_1333 = 0 ;
* V_1471 = 32 ;
for ( V_30 = 8 ; V_30 < 32 ; V_30 ++ ) {
if ( F_524 ( V_498 , V_30 ) ) {
if ( ! V_1333 )
* V_1471 = V_30 ;
V_1333 ++ ;
}
}
return V_1333 ;
}
static int F_526 ( struct V_276 * V_498 , int * V_1471 )
{
* V_1471 = 32 ;
if ( V_498 -> V_1469 [ V_1472 ] )
* V_1471 = V_498 -> V_1463 [ V_1472 ] [ 0 ] ;
return V_498 -> V_1469 [ V_1472 ] ;
}
static void F_527 ( struct V_24 * V_25 )
{
int V_481 = V_25 -> V_481 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_481 ; V_26 ++ ) {
V_25 -> V_809 [ V_26 ] = ( 16 / V_481 ) ;
V_25 -> V_810 [ V_26 ] = ( 16 / V_481 ) ;
F_48 ( L_171 ,
V_25 -> V_375 , V_26 ,
V_25 -> V_809 [ V_26 ] ,
V_25 -> V_810 [ V_26 ] ) ;
}
}
static void F_528 ( struct V_24 * V_25 ,
int V_1473 , int V_1474 )
{
int V_481 = V_25 -> V_481 ;
int V_1475 , V_1476 ;
int V_1477 , V_1478 ;
int V_26 , V_1479 , V_1480 ;
if ( ! V_1473 || ! V_1474 ) {
V_1475 = V_1476 =
( V_1481 / V_481 ) ;
V_1477 = V_1478 =
( V_1482 / V_481 ) ;
} else {
V_1476 = V_1481 / 8 ;
V_1475 = ( V_1481 -
( V_1476 * V_1474 ) ) /
V_1473 ;
V_1478 = V_1482 / 6 ;
V_1477 = ( V_1482 -
( V_1478 * V_1474 ) ) /
V_1473 ;
}
V_1479 = V_1480 = 0 ;
for ( V_26 = 0 ; V_26 < V_481 ; V_26 ++ ) {
int type = F_27 ( V_25 -> V_275 , V_26 ) ;
if ( type == V_846 ) {
V_25 -> V_809 [ V_26 ] = V_1475 ;
V_25 -> V_810 [ V_26 ] = V_1477 ;
} else {
V_25 -> V_809 [ V_26 ] = V_1476 ;
V_25 -> V_810 [ V_26 ] = V_1478 ;
}
F_48 ( L_171 ,
V_25 -> V_375 , V_26 ,
V_25 -> V_809 [ V_26 ] ,
V_25 -> V_810 [ V_26 ] ) ;
V_1479 += V_25 -> V_809 [ V_26 ] ;
V_1480 += V_25 -> V_810 [ V_26 ] ;
}
if ( V_1479 > V_1481 ) {
F_523 ( L_172 ,
V_25 -> V_375 , V_1479 ) ;
for ( V_26 = 0 ; V_26 < V_481 ; V_26 ++ )
V_25 -> V_809 [ V_26 ] = 1 ;
}
if ( V_1480 > V_1482 ) {
F_523 ( L_173 ,
V_25 -> V_375 , V_1480 ) ;
for ( V_26 = 0 ; V_26 < V_481 ; V_26 ++ )
V_25 -> V_810 [ V_26 ] = 1 ;
}
if ( V_1479 < V_1481 || V_1480 < V_1482 ) {
F_529 ( L_174 ,
V_25 -> V_375 , V_1479 , V_1480 ) ;
}
}
static void F_530 ( struct V_24 * V_25 ,
int V_1473 , int V_1474 )
{
int V_26 , V_481 = V_25 -> V_481 ;
int V_1483 , V_1484 ;
int V_1485 ;
V_1483 = 0 ;
V_1484 = V_1486 / V_481 ;
V_1485 = 0 ;
for ( V_26 = 0 ; V_26 < V_481 ; V_26 ++ ) {
struct V_835 * V_341 = & V_25 -> V_836 [ V_26 ] ;
int V_1487 , V_1488 = V_25 -> V_809 [ V_26 ] ;
int V_1489 ;
V_341 -> V_837 = V_1483 ;
V_341 -> V_838 = V_1484 ;
V_1489 = 0 ;
for ( V_1487 = 0 ; V_1487 < V_341 -> V_838 ; V_1487 ++ ) {
struct V_393 * V_1490 = & V_341 -> V_840 [ V_1487 ] ;
int V_842 ;
F_48 ( L_175 ,
V_25 -> V_375 , V_26 , V_341 -> V_837 + V_1487 ) ;
for ( V_842 = 0 ; V_842 < V_843 ; V_842 ++ ) {
V_1490 -> V_844 [ V_842 ] =
V_1485 + V_1489 ;
F_238 ( L_176 , V_1490 -> V_844 [ V_842 ] ) ;
if ( ++ V_1489 == V_1488 )
V_1489 = 0 ;
}
F_238 ( L_177 ) ;
}
V_25 -> V_845 [ V_26 ] = V_1485 ;
V_1485 += V_1488 ;
V_1483 += V_1484 ;
}
}
static int F_531 ( struct V_3 * V_4 , struct V_24 * V_25 ,
struct V_276 * V_1223 )
{
unsigned long V_87 ;
int V_30 , V_10 ;
memset ( V_1223 , 0 , sizeof( * V_1223 ) ) ;
F_165 ( V_4 , V_87 ) ;
V_10 = 0 ;
for ( V_30 = 8 ; V_30 < 32 ; V_30 ++ ) {
int V_1461 , V_1462 ;
V_1461 = F_29 ( V_4 , V_30 ,
V_1491 , V_1492 ) ;
V_1462 = F_29 ( V_4 , V_30 ,
V_1491 , V_1493 ) ;
V_10 = F_522 ( V_25 , V_1223 , V_1461 , V_1462 , V_30 ,
V_1465 ) ;
if ( V_10 )
break;
V_1461 = F_29 ( V_4 , V_30 ,
V_1494 , V_1492 ) ;
V_1462 = F_29 ( V_4 , V_30 ,
V_1494 , V_1493 ) ;
V_10 = F_522 ( V_25 , V_1223 , V_1461 , V_1462 , V_30 ,
V_1466 ) ;
if ( V_10 )
break;
V_1461 = F_34 ( V_4 , V_30 , V_1492 ) ;
V_1462 = F_34 ( V_4 , V_30 , V_1493 ) ;
V_10 = F_522 ( V_25 , V_1223 , V_1461 , V_1462 , V_30 ,
V_1472 ) ;
if ( V_10 )
break;
}
F_167 ( V_4 , V_87 ) ;
return V_10 ;
}
static int F_532 ( struct V_3 * V_4 , struct V_24 * V_25 )
{
struct V_276 * V_1223 = & V_25 -> V_276 ;
int V_1495 , V_1496 ;
int V_1473 , V_1474 ;
T_3 V_2 ;
int V_10 ;
V_1473 = V_1474 = 0 ;
if ( ! strcmp ( V_4 -> V_1225 . V_1413 , V_1432 ) ||
! strcmp ( V_4 -> V_1225 . V_1413 , V_1431 ) ) {
V_1473 = 0 ;
V_1474 = 2 ;
V_25 -> V_339 = V_1497 ;
V_25 -> V_481 = 4 ;
V_2 = ( F_26 ( V_848 , 0 ) |
F_26 ( V_848 , 1 ) |
F_26 ( V_848 , 2 ) |
F_26 ( V_848 , 3 ) ) ;
} else if ( ! strcmp ( V_4 -> V_1225 . V_1413 , V_1435 ) ) {
V_1473 = 2 ;
V_1474 = 0 ;
V_25 -> V_481 = 2 ;
V_2 = ( F_26 ( V_846 , 0 ) |
F_26 ( V_846 , 1 ) ) ;
} else if ( ( V_4 -> V_87 & V_345 ) &&
( V_25 -> V_339 == V_343 ) ) {
if ( V_4 -> V_87 & V_88 ) {
V_2 = ( F_26 ( V_846 , 0 ) |
F_26 ( V_846 , 1 ) ) ;
} else {
V_2 = ( F_26 ( V_848 , 0 ) |
F_26 ( V_848 , 1 ) ) ;
}
} else {
V_10 = F_531 ( V_4 , V_25 , V_1223 ) ;
if ( V_10 )
return V_10 ;
V_1473 = F_525 ( V_1223 , & V_1495 ) ;
V_1474 = F_526 ( V_1223 , & V_1496 ) ;
switch ( ( V_1473 << 4 ) | V_1474 ) {
case 0x24 :
if ( V_1496 == 10 )
V_25 -> V_339 = V_351 ;
else if ( V_1496 == 26 )
V_25 -> V_339 = V_352 ;
else
goto V_1498;
case 0x22 :
V_2 = ( F_26 ( V_846 , 0 ) |
F_26 ( V_846 , 1 ) |
F_26 ( V_848 , 2 ) |
F_26 ( V_848 , 3 ) ) ;
break;
case 0x20 :
V_2 = ( F_26 ( V_846 , 0 ) |
F_26 ( V_846 , 1 ) ) ;
break;
case 0x10 :
V_2 = F_26 ( V_846 , V_4 -> V_30 ) ;
break;
case 0x14 :
if ( V_1496 == 10 )
V_25 -> V_339 = V_351 ;
else if ( V_1496 == 26 )
V_25 -> V_339 = V_352 ;
else
goto V_1498;
case 0x13 :
if ( ( V_1495 & 0x7 ) == 0 )
V_2 = ( F_26 ( V_846 , 0 ) |
F_26 ( V_848 , 1 ) |
F_26 ( V_848 , 2 ) |
F_26 ( V_848 , 3 ) ) ;
else
V_2 = ( F_26 ( V_848 , 0 ) |
F_26 ( V_846 , 1 ) |
F_26 ( V_848 , 2 ) |
F_26 ( V_848 , 3 ) ) ;
break;
case 0x04 :
if ( V_1496 == 10 )
V_25 -> V_339 = V_351 ;
else if ( V_1496 == 26 )
V_25 -> V_339 = V_352 ;
else
goto V_1498;
V_2 = ( F_26 ( V_848 , 0 ) |
F_26 ( V_848 , 1 ) |
F_26 ( V_848 , 2 ) |
F_26 ( V_848 , 3 ) ) ;
break;
default:
F_523 ( L_178 ,
V_1473 , V_1474 ) ;
return - V_21 ;
}
}
V_25 -> V_275 = V_2 ;
if ( V_25 -> V_339 == V_343 )
F_527 ( V_25 ) ;
else
F_528 ( V_25 , V_1473 , V_1474 ) ;
F_530 ( V_25 , V_1473 , V_1474 ) ;
return 0 ;
V_1498:
F_523 ( L_179 , V_1496 ) ;
return - V_21 ;
}
static int F_533 ( struct V_3 * V_4 )
{
struct V_24 * V_25 = V_4 -> V_25 ;
int V_10 , V_26 ;
if ( V_25 -> V_275 == V_1499 ) {
V_10 = F_532 ( V_4 , V_25 ) ;
if ( V_10 )
return V_10 ;
F_499 ( V_4 , 2 ) ;
for ( V_26 = 0 ; V_26 <= V_20 ; V_26 ++ )
F_21 ( V_4 , V_26 , 0 ) ;
}
if ( V_25 -> V_275 == V_1500 )
return - V_21 ;
return 0 ;
}
static int F_534 ( struct V_3 * V_4 )
{
struct V_906 * V_907 = & V_4 -> V_478 ;
V_907 -> V_480 = ( T_4 ) V_4 -> V_30 ;
V_907 -> V_479 = V_4 -> V_25 -> V_441 / V_4 -> V_25 -> V_481 ;
V_907 -> V_915 = 0xffffffff ;
V_907 -> V_916 = 0xffff ;
return F_164 ( V_4 ) ;
}
static void F_535 ( struct V_3 * V_4 )
{
struct V_38 * V_13 = & V_4 -> V_39 ;
V_13 -> V_174 = ( V_288 |
V_290 |
V_292 |
V_294 |
V_296 |
V_298 |
V_1501 |
V_202 ) ;
V_13 -> V_302 = V_13 -> V_160 = V_153 ;
V_13 -> V_301 = V_159 ;
V_13 -> V_161 = V_154 ;
V_13 -> V_285 = 1 ;
#if 0
lp->loopback_mode = LOOPBACK_MAC;
lp->active_speed = SPEED_10000;
lp->active_duplex = DUPLEX_FULL;
#else
V_13 -> V_49 = V_330 ;
#endif
}
static int F_536 ( struct V_3 * V_4 )
{
switch ( V_4 -> V_30 ) {
case 0 :
V_4 -> V_1502 = V_4 -> V_1503 + V_1504 ;
V_4 -> V_1505 = 0x00000 ;
V_4 -> V_1506 = 0x04000 ;
V_4 -> V_1507 = 0x02000 ;
break;
case 1 :
V_4 -> V_1502 = V_4 -> V_1503 + V_1508 ;
V_4 -> V_1505 = 0x08000 ;
V_4 -> V_1506 = 0x0a000 ;
V_4 -> V_1507 = 0x08000 ;
break;
case 2 :
V_4 -> V_1502 = V_4 -> V_1503 + V_1509 ;
V_4 -> V_1505 = 0x04000 ;
V_4 -> V_1506 = 0x0e000 ;
V_4 -> V_1507 = ~ 0UL ;
break;
case 3 :
V_4 -> V_1502 = V_4 -> V_1503 + V_1510 ;
V_4 -> V_1505 = 0x0c000 ;
V_4 -> V_1506 = 0x12000 ;
V_4 -> V_1507 = ~ 0UL ;
break;
default:
F_225 ( V_4 -> V_508 , L_180 , V_4 -> V_30 ) ;
return - V_21 ;
}
return 0 ;
}
static void F_537 ( struct V_3 * V_4 , T_5 * V_1511 )
{
struct V_1512 V_1513 [ V_1514 ] ;
struct V_24 * V_25 = V_4 -> V_25 ;
struct V_1515 * V_1234 = V_4 -> V_1234 ;
int V_26 , V_1516 , V_10 ;
T_5 V_1517 ;
V_1517 = ( V_1514 / V_25 -> V_481 ) * V_4 -> V_30 ;
for ( V_26 = 0 ; V_26 < ( V_1514 / V_25 -> V_481 ) ; V_26 ++ )
V_1511 [ V_26 ] = V_1517 + V_26 ;
V_1516 = ( V_25 -> V_809 [ V_4 -> V_30 ] +
V_25 -> V_810 [ V_4 -> V_30 ] +
( V_4 -> V_30 == 0 ? 3 : 1 ) ) ;
F_190 ( V_1516 > ( V_1514 / V_25 -> V_481 ) ) ;
V_1518:
for ( V_26 = 0 ; V_26 < V_1516 ; V_26 ++ ) {
V_1513 [ V_26 ] . V_1391 = 0 ;
V_1513 [ V_26 ] . V_1519 = V_26 ;
}
V_10 = F_538 ( V_1234 , V_1513 , V_1516 ) ;
if ( V_10 < 0 ) {
V_4 -> V_87 &= ~ V_1520 ;
return;
}
if ( V_10 > 0 ) {
V_1516 = V_10 ;
goto V_1518;
}
V_4 -> V_87 |= V_1520 ;
for ( V_26 = 0 ; V_26 < V_1516 ; V_26 ++ )
V_4 -> V_29 [ V_26 ] . V_782 = V_1513 [ V_26 ] . V_1391 ;
V_4 -> V_28 = V_1516 ;
}
static int F_539 ( struct V_3 * V_4 , T_5 * V_1511 )
{
#ifdef F_540
struct V_1521 * V_1522 = V_4 -> V_1522 ;
const T_3 * V_1523 ;
int V_26 ;
V_1523 = F_541 ( V_1522 -> V_11 . V_1524 , L_181 , NULL ) ;
if ( ! V_1523 )
return - V_8 ;
for ( V_26 = 0 ; V_26 < V_1522 -> V_1525 . V_1516 ; V_26 ++ ) {
V_1511 [ V_26 ] = V_1523 [ V_26 ] ;
V_4 -> V_29 [ V_26 ] . V_782 = V_1522 -> V_1525 . V_1526 [ V_26 ] ;
}
V_4 -> V_28 = V_1522 -> V_1525 . V_1516 ;
return 0 ;
#else
return - V_21 ;
#endif
}
static int F_542 ( struct V_3 * V_4 )
{
struct V_24 * V_25 = V_4 -> V_25 ;
T_5 V_1511 [ V_1514 ] ;
int V_1527 , V_1528 ;
int V_26 , V_10 , V_1529 ;
T_5 V_30 ;
V_4 -> V_28 = 1 ;
V_4 -> V_29 [ 0 ] . V_782 = V_4 -> V_11 -> V_782 ;
if ( V_25 -> V_339 == V_343 ) {
V_10 = F_539 ( V_4 , V_1511 ) ;
if ( V_10 )
return V_10 ;
} else
F_537 ( V_4 , V_1511 ) ;
V_30 = V_4 -> V_30 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_28 ; V_26 ++ ) {
struct V_12 * V_13 = & V_4 -> V_29 [ V_26 ] ;
F_543 ( V_4 -> V_11 , & V_13 -> V_535 , F_234 , 64 ) ;
V_13 -> V_4 = V_4 ;
V_13 -> V_17 = V_1511 [ V_26 ] ;
V_13 -> V_15 = 2 ;
if ( V_4 -> V_25 -> V_339 != V_343 ) {
V_10 = F_500 ( V_4 , V_13 -> V_17 , V_30 , V_26 ) ;
if ( V_10 )
return V_10 ;
}
}
V_1529 = 0 ;
V_10 = F_497 ( V_4 , V_25 , V_1511 [ V_1529 ] ,
F_544 ( V_30 ) ) ;
if ( V_10 )
return V_10 ;
V_1529 ++ ;
if ( V_1529 == V_4 -> V_28 )
V_1529 = 0 ;
if ( V_30 == 0 ) {
V_10 = F_497 ( V_4 , V_25 ,
V_1511 [ V_1529 ] ,
V_785 ) ;
if ( V_10 )
return V_10 ;
V_1529 ++ ;
if ( V_1529 == V_4 -> V_28 )
V_1529 = 0 ;
V_10 = F_497 ( V_4 , V_25 ,
V_1511 [ V_1529 ] ,
V_1530 ) ;
if ( V_10 )
return V_10 ;
V_1529 ++ ;
if ( V_1529 == V_4 -> V_28 )
V_1529 = 0 ;
}
V_1527 = 0 ;
for ( V_26 = 0 ; V_26 < V_30 ; V_26 ++ )
V_1527 += V_25 -> V_809 [ V_26 ] ;
V_1528 = V_25 -> V_809 [ V_30 ] ;
for ( V_26 = V_1527 ; V_26 < ( V_1527 + V_1528 ) ; V_26 ++ ) {
V_10 = F_497 ( V_4 , V_25 ,
V_1511 [ V_1529 ] ,
F_233 ( V_26 ) ) ;
if ( V_10 )
return V_10 ;
V_1529 ++ ;
if ( V_1529 == V_4 -> V_28 )
V_1529 = 0 ;
}
V_1527 = 0 ;
for ( V_26 = 0 ; V_26 < V_30 ; V_26 ++ )
V_1527 += V_25 -> V_810 [ V_26 ] ;
V_1528 = V_25 -> V_810 [ V_30 ] ;
for ( V_26 = V_1527 ; V_26 < ( V_1527 + V_1528 ) ; V_26 ++ ) {
V_10 = F_497 ( V_4 , V_25 ,
V_1511 [ V_1529 ] ,
F_232 ( V_26 ) ) ;
if ( V_10 )
return V_10 ;
V_1529 ++ ;
if ( V_1529 == V_4 -> V_28 )
V_1529 = 0 ;
}
return 0 ;
}
static void F_545 ( struct V_3 * V_4 )
{
if ( V_4 -> V_87 & V_1520 )
F_546 ( V_4 -> V_1234 ) ;
}
static int F_547 ( struct V_3 * V_4 )
{
#ifdef F_540
struct V_308 * V_11 = V_4 -> V_11 ;
struct V_1531 * V_1532 ;
const char * V_1420 ;
const T_5 * V_1533 ;
const char * V_1413 ;
int V_1410 ;
if ( V_4 -> V_25 -> V_339 == V_343 )
V_1532 = V_4 -> V_1522 -> V_11 . V_1524 ;
else
V_1532 = F_548 ( V_4 -> V_1234 ) ;
V_1420 = F_541 ( V_1532 , L_142 , & V_1410 ) ;
if ( ! V_1420 ) {
F_10 ( V_11 , L_182 ,
V_1532 -> V_1534 ) ;
return - V_21 ;
}
if ( ! strcmp ( V_1420 , L_183 ) )
return - V_8 ;
strcpy ( V_4 -> V_1225 . V_1420 , V_1420 ) ;
if ( F_517 ( V_4 , V_4 -> V_1225 . V_1420 ) ) {
F_10 ( V_11 , L_184 ,
V_1532 -> V_1534 , V_4 -> V_1225 . V_1420 ) ;
return - V_21 ;
}
V_1533 = F_541 ( V_1532 , L_140 , & V_1410 ) ;
if ( ! V_1533 ) {
F_10 ( V_11 , L_185 ,
V_1532 -> V_1534 ) ;
return - V_21 ;
}
if ( V_1410 != V_11 -> V_1535 ) {
F_10 ( V_11 , L_186 ,
V_1532 -> V_1534 , V_1410 ) ;
}
memcpy ( V_11 -> V_1104 , V_1533 , V_11 -> V_1535 ) ;
if ( ! F_428 ( & V_11 -> V_1104 [ 0 ] ) ) {
F_10 ( V_11 , L_187 ,
V_1532 -> V_1534 ) ;
F_10 ( V_11 , L_188 , V_1532 -> V_1534 , V_11 -> V_1104 ) ;
return - V_21 ;
}
V_1413 = F_541 ( V_1532 , L_137 , & V_1410 ) ;
if ( V_1413 )
strcpy ( V_4 -> V_1225 . V_1413 , V_1413 ) ;
if ( F_549 ( V_1532 , L_189 , & V_1410 ) ) {
V_4 -> V_87 |= ( V_88 | V_344 |
V_134 ) ;
}
return 0 ;
#else
return - V_21 ;
#endif
}
static int F_550 ( struct V_3 * V_4 )
{
int V_10 , V_1536 ;
T_3 V_486 ;
V_10 = F_547 ( V_4 ) ;
if ( V_10 == - V_8 )
return V_10 ;
V_1536 = ! V_10 ;
V_10 = F_536 ( V_4 ) ;
if ( V_10 )
return V_10 ;
if ( V_1536 ) {
V_10 = F_521 ( V_4 ) ;
if ( V_10 )
return V_10 ;
} else {
if ( V_4 -> V_25 -> V_339 == V_343 )
return - V_21 ;
F_18 ( V_1537 , V_1538 ) ;
V_486 = F_516 ( V_4 ) ;
F_166 ( V_4 , V_472 , V_473 , V_4 -> V_11 ,
L_190 , V_67 , V_486 ) ;
if ( V_486 )
F_515 ( V_4 , V_486 ) ;
F_18 ( V_1537 , 0 ) ;
if ( V_4 -> V_87 & V_1407 ) {
F_519 ( V_4 ) ;
V_10 = F_521 ( V_4 ) ;
if ( V_10 )
return V_10 ;
}
if ( ! ( V_4 -> V_87 & V_1407 ) ) {
V_10 = F_521 ( V_4 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_520 ( V_4 ) ;
if ( V_10 )
return V_10 ;
}
}
V_10 = F_533 ( V_4 ) ;
if ( V_10 )
return V_10 ;
F_542 ( V_4 ) ;
F_534 ( V_4 ) ;
F_535 ( V_4 ) ;
V_10 = F_113 ( V_4 ) ;
if ( ! V_10 )
V_10 = F_114 ( V_4 ) ;
return V_10 ;
}
static T_12 F_551 ( struct V_508 * V_11 ,
struct V_1539 * V_1540 , char * V_1541 )
{
struct V_1521 * V_1542 = F_552 ( V_11 ) ;
struct V_24 * V_498 = V_1542 -> V_11 . V_1543 ;
T_3 V_275 = V_498 -> V_275 ;
char * V_1544 = V_1541 ;
int V_26 ;
if ( V_275 == V_1499 ||
V_275 == V_1500 )
return 0 ;
for ( V_26 = 0 ; V_26 < V_498 -> V_481 ; V_26 ++ ) {
const char * V_1545 ;
int type ;
type = F_27 ( V_275 , V_26 ) ;
if ( type == V_846 )
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
static T_12 F_553 ( struct V_508 * V_11 ,
struct V_1539 * V_1540 , char * V_1541 )
{
struct V_1521 * V_1542 = F_552 ( V_11 ) ;
struct V_24 * V_498 = V_1542 -> V_11 . V_1543 ;
const char * V_1545 ;
switch ( V_498 -> V_339 ) {
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
static T_12 F_554 ( struct V_508 * V_11 ,
struct V_1539 * V_1540 , char * V_1541 ,
int V_1547 )
{
struct V_1521 * V_1542 = F_552 ( V_11 ) ;
struct V_24 * V_498 = V_1542 -> V_11 . V_1543 ;
char * V_1544 = V_1541 ;
T_5 * V_1548 ;
int V_26 ;
V_1548 = ( V_1547 ? V_498 -> V_809 : V_498 -> V_810 ) ;
for ( V_26 = 0 ; V_26 < V_498 -> V_481 ; V_26 ++ ) {
V_1541 += sprintf ( V_1541 ,
( V_26 == 0 ) ? L_202 : L_203 ,
V_1548 [ V_26 ] ) ;
}
V_1541 += sprintf ( V_1541 , L_195 ) ;
return V_1541 - V_1544 ;
}
static T_12 F_555 ( struct V_508 * V_11 ,
struct V_1539 * V_1540 , char * V_1541 )
{
return F_554 ( V_11 , V_1540 , V_1541 , 1 ) ;
}
static T_12 F_556 ( struct V_508 * V_11 ,
struct V_1539 * V_1540 , char * V_1541 )
{
return F_554 ( V_11 , V_1540 , V_1541 , 1 ) ;
}
static T_12 F_557 ( struct V_508 * V_11 ,
struct V_1539 * V_1540 , char * V_1541 )
{
struct V_1521 * V_1542 = F_552 ( V_11 ) ;
struct V_24 * V_498 = V_1542 -> V_11 . V_1543 ;
return sprintf ( V_1541 , L_204 , V_498 -> V_481 ) ;
}
static struct V_24 * F_558 ( struct V_3 * V_4 ,
union V_1549 * V_1464 , T_5 V_543 )
{
struct V_1521 * V_1542 ;
struct V_24 * V_498 ;
int V_26 ;
V_1542 = F_559 ( L_205 , V_1550 ,
NULL , 0 ) ;
if ( F_560 ( V_1542 ) )
return NULL ;
for ( V_26 = 0 ; F_561 ( V_1551 [ V_26 ] ) ; V_26 ++ ) {
int V_10 = F_562 ( & V_1542 -> V_11 ,
& V_1551 [ V_26 ] ) ;
if ( V_10 )
goto V_1552;
}
V_498 = F_563 ( sizeof( * V_498 ) , V_800 ) ;
if ( ! V_498 )
goto V_1552;
V_498 -> V_375 = V_1550 ++ ;
V_1542 -> V_11 . V_1543 = V_498 ;
V_498 -> V_1542 = V_1542 ;
memcpy ( & V_498 -> V_1464 , V_1464 , sizeof( * V_1464 ) ) ;
V_498 -> V_339 = V_543 ;
F_564 ( & V_498 -> V_1553 ) ;
F_565 ( & V_498 -> V_1554 , 0 ) ;
F_566 ( & V_498 -> V_1553 , & V_1555 ) ;
F_567 ( & V_498 -> V_155 ) ;
V_498 -> V_902 = 7500 ;
V_498 -> V_441 = V_1556 ;
if ( V_498 -> V_339 == V_343 )
V_498 -> V_441 = V_1557 ;
for ( V_26 = V_425 ; V_26 <= V_477 ; V_26 ++ ) {
int V_375 = V_26 - V_425 ;
V_498 -> V_927 [ V_375 ] = V_1558 ;
V_498 -> V_928 [ V_375 ] = ( V_1281 |
V_1283 |
V_1285 |
( V_1287 <<
V_1288 ) |
( V_1287 <<
V_1290 ) ) ;
}
for ( V_26 = 0 ; V_26 < V_20 + 1 ; V_26 ++ )
V_498 -> V_27 [ V_26 ] = V_1559 ;
return V_498 ;
V_1552:
F_568 ( V_1542 ) ;
return NULL ;
}
static struct V_24 * F_569 ( struct V_3 * V_4 ,
union V_1549 * V_1464 , T_5 V_543 )
{
struct V_24 * V_498 , * V_584 ;
int V_30 = V_4 -> V_30 ;
F_570 ( & V_1560 ) ;
V_498 = NULL ;
F_571 (tmp, &niu_parent_list, list) {
if ( ! memcmp ( V_1464 , & V_584 -> V_1464 , sizeof( * V_1464 ) ) ) {
V_498 = V_584 ;
break;
}
}
if ( ! V_498 )
V_498 = F_558 ( V_4 , V_1464 , V_543 ) ;
if ( V_498 ) {
char V_1561 [ 6 ] ;
int V_10 ;
sprintf ( V_1561 , L_206 , V_30 ) ;
V_10 = F_572 ( & V_498 -> V_1542 -> V_11 . V_1562 ,
& V_4 -> V_508 -> V_1562 ,
V_1561 ) ;
if ( ! V_10 ) {
V_498 -> V_1427 [ V_30 ] = V_4 ;
F_573 ( & V_498 -> V_1554 ) ;
}
}
F_574 ( & V_1560 ) ;
return V_498 ;
}
static void F_575 ( struct V_3 * V_4 )
{
struct V_24 * V_498 = V_4 -> V_25 ;
T_5 V_30 = V_4 -> V_30 ;
char V_1561 [ 6 ] ;
F_190 ( ! V_498 || V_498 -> V_1427 [ V_30 ] != V_4 ) ;
F_166 ( V_4 , V_472 , V_473 , V_4 -> V_11 ,
L_207 , V_67 , V_30 ) ;
sprintf ( V_1561 , L_206 , V_30 ) ;
F_570 ( & V_1560 ) ;
F_576 ( & V_498 -> V_1542 -> V_11 . V_1562 , V_1561 ) ;
V_498 -> V_1427 [ V_30 ] = NULL ;
V_4 -> V_25 = NULL ;
if ( F_577 ( & V_498 -> V_1554 ) ) {
F_578 ( & V_498 -> V_1553 ) ;
F_568 ( V_498 -> V_1542 ) ;
}
F_574 ( & V_1560 ) ;
}
static void * F_579 ( struct V_508 * V_11 , T_13 V_487 ,
T_1 * V_1563 , T_6 V_1564 )
{
T_14 V_1565 ;
void * V_860 ;
V_860 = F_580 ( V_11 , V_487 , & V_1565 , V_1564 ) ;
if ( V_860 )
* V_1563 = V_1565 ;
return V_860 ;
}
static void F_581 ( struct V_508 * V_11 , T_13 V_487 ,
void * V_1566 , T_1 V_1563 )
{
F_582 ( V_11 , V_487 , V_1566 , V_1563 ) ;
}
static T_1 F_583 ( struct V_508 * V_11 , struct V_485 * V_485 ,
unsigned long V_486 , T_13 V_487 ,
enum V_1567 V_1568 )
{
return F_584 ( V_11 , V_485 , V_486 , V_487 , V_1568 ) ;
}
static void F_585 ( struct V_508 * V_11 , T_1 V_1569 ,
T_13 V_487 , enum V_1567 V_1568 )
{
F_586 ( V_11 , V_1569 , V_487 , V_1568 ) ;
}
static T_1 F_587 ( struct V_508 * V_11 , void * V_1566 ,
T_13 V_487 ,
enum V_1567 V_1568 )
{
return F_588 ( V_11 , V_1566 , V_487 , V_1568 ) ;
}
static void F_589 ( struct V_508 * V_11 , T_1 V_1569 ,
T_13 V_487 ,
enum V_1567 V_1568 )
{
F_590 ( V_11 , V_1569 , V_487 , V_1568 ) ;
}
static void F_591 ( void )
{
static int V_1570 ;
if ( V_1570 ++ == 0 )
F_48 ( L_193 , V_1228 ) ;
}
static struct V_308 * F_592 ( struct V_508 * V_1571 ,
struct V_1515 * V_1234 ,
struct V_1521 * V_1522 ,
const struct V_1572 * V_304 , T_5 V_30 )
{
struct V_308 * V_11 ;
struct V_3 * V_4 ;
V_11 = F_593 ( sizeof( struct V_3 ) , V_1482 ) ;
if ( ! V_11 )
return NULL ;
F_594 ( V_11 , V_1571 ) ;
V_4 = F_399 ( V_11 ) ;
V_4 -> V_11 = V_11 ;
V_4 -> V_1234 = V_1234 ;
V_4 -> V_1522 = V_1522 ;
V_4 -> V_508 = V_1571 ;
V_4 -> V_304 = V_304 ;
V_4 -> V_1242 = V_1573 ;
F_567 ( & V_4 -> V_155 ) ;
F_595 ( & V_4 -> V_1123 , F_435 ) ;
V_4 -> V_30 = V_30 ;
return V_11 ;
}
static void F_596 ( struct V_308 * V_11 )
{
V_11 -> V_1574 = & V_1575 ;
V_11 -> V_1576 = & V_1577 ;
V_11 -> V_1578 = V_1579 ;
}
static void F_597 ( struct V_3 * V_4 )
{
struct V_308 * V_11 = V_4 -> V_11 ;
F_48 ( L_208 , V_11 -> V_1117 , V_11 -> V_1104 ) ;
if ( V_4 -> V_25 -> V_339 == V_1497 ) {
F_48 ( L_209 ,
V_11 -> V_1117 ,
( V_4 -> V_87 & V_366 ? L_210 : L_211 ) ,
( V_4 -> V_87 & V_88 ? L_191 : L_192 ) ,
( V_4 -> V_87 & V_344 ? L_212 : L_213 ) ,
( V_4 -> V_89 == V_1425 ? L_169 :
( V_4 -> V_89 == V_90 ? L_168 : L_214 ) ) ,
V_4 -> V_1225 . V_1420 ) ;
} else {
F_48 ( L_209 ,
V_11 -> V_1117 ,
( V_4 -> V_87 & V_366 ? L_210 : L_211 ) ,
( V_4 -> V_87 & V_88 ? L_191 : L_192 ) ,
( V_4 -> V_87 & V_344 ? L_215 :
( V_4 -> V_87 & V_345 ? L_213 :
L_216 ) ) ,
( V_4 -> V_89 == V_1425 ? L_169 :
( V_4 -> V_89 == V_90 ? L_168 : L_214 ) ) ,
V_4 -> V_1225 . V_1420 ) ;
}
}
static void F_598 ( struct V_308 * V_11 )
{
V_11 -> V_1580 = V_1581 | V_1582 | V_553 ;
V_11 -> V_552 |= V_11 -> V_1580 | V_1583 ;
}
static int F_599 ( struct V_1515 * V_1234 ,
const struct V_1584 * V_468 )
{
union V_1549 V_1585 ;
struct V_308 * V_11 ;
struct V_3 * V_4 ;
int V_10 ;
T_1 V_1586 ;
F_591 () ;
V_10 = F_600 ( V_1234 ) ;
if ( V_10 ) {
F_225 ( & V_1234 -> V_11 , L_217 ) ;
return V_10 ;
}
if ( ! ( F_601 ( V_1234 , 0 ) & V_1587 ) ||
! ( F_601 ( V_1234 , 2 ) & V_1587 ) ) {
F_225 ( & V_1234 -> V_11 , L_218 ) ;
V_10 = - V_8 ;
goto V_1588;
}
V_10 = F_602 ( V_1234 , V_1227 ) ;
if ( V_10 ) {
F_225 ( & V_1234 -> V_11 , L_219 ) ;
goto V_1588;
}
if ( ! F_603 ( V_1234 ) ) {
F_225 ( & V_1234 -> V_11 , L_220 ) ;
V_10 = - V_8 ;
goto V_1589;
}
V_11 = F_592 ( & V_1234 -> V_11 , V_1234 , NULL ,
& V_1590 , F_604 ( V_1234 -> V_1591 ) ) ;
if ( ! V_11 ) {
V_10 = - V_506 ;
goto V_1589;
}
V_4 = F_399 ( V_11 ) ;
memset ( & V_1585 , 0 , sizeof( V_1585 ) ) ;
V_1585 . V_1592 . V_1593 = F_605 ( V_1234 -> V_1594 ) ;
V_1585 . V_1592 . V_1594 = V_1234 -> V_1594 -> V_1595 ;
V_1585 . V_1592 . V_508 = F_606 ( V_1234 -> V_1591 ) ;
V_4 -> V_25 = F_569 ( V_4 , & V_1585 ,
V_1546 ) ;
if ( ! V_4 -> V_25 ) {
V_10 = - V_506 ;
goto V_1596;
}
F_607 ( V_1234 , V_1597 ,
V_1598 ,
V_1599 | V_1600 |
V_1601 | V_1602 |
V_1603 ) ;
V_1586 = F_608 ( 44 ) ;
V_10 = F_609 ( V_1234 , V_1586 ) ;
if ( ! V_10 ) {
V_11 -> V_552 |= V_1604 ;
V_10 = F_610 ( V_1234 , V_1586 ) ;
if ( V_10 ) {
F_225 ( & V_1234 -> V_11 , L_221 ) ;
goto V_1605;
}
}
if ( V_10 ) {
V_10 = F_609 ( V_1234 , F_608 ( 32 ) ) ;
if ( V_10 ) {
F_225 ( & V_1234 -> V_11 , L_222 ) ;
goto V_1605;
}
}
F_598 ( V_11 ) ;
V_11 -> V_1606 |= V_1607 ;
V_4 -> V_1503 = F_611 ( V_1234 , 0 ) ;
if ( ! V_4 -> V_1503 ) {
F_225 ( & V_1234 -> V_11 , L_223 ) ;
V_10 = - V_506 ;
goto V_1605;
}
F_612 ( V_1234 ) ;
F_613 ( V_1234 ) ;
V_11 -> V_782 = V_1234 -> V_782 ;
F_596 ( V_11 ) ;
V_10 = F_550 ( V_4 ) ;
if ( V_10 ) {
if ( V_10 != - V_8 )
F_225 ( & V_1234 -> V_11 , L_224 ) ;
goto V_1608;
}
V_10 = F_614 ( V_11 ) ;
if ( V_10 ) {
F_225 ( & V_1234 -> V_11 , L_225 ) ;
goto V_1608;
}
F_615 ( V_1234 , V_11 ) ;
F_597 ( V_4 ) ;
return 0 ;
V_1608:
if ( V_4 -> V_1503 ) {
F_616 ( V_4 -> V_1503 ) ;
V_4 -> V_1503 = NULL ;
}
V_1605:
F_575 ( V_4 ) ;
V_1596:
F_617 ( V_11 ) ;
V_1589:
F_618 ( V_1234 ) ;
V_1588:
F_619 ( V_1234 ) ;
F_615 ( V_1234 , NULL ) ;
return V_10 ;
}
static void F_620 ( struct V_1515 * V_1234 )
{
struct V_308 * V_11 = F_621 ( V_1234 ) ;
if ( V_11 ) {
struct V_3 * V_4 = F_399 ( V_11 ) ;
F_622 ( V_11 ) ;
if ( V_4 -> V_1503 ) {
F_616 ( V_4 -> V_1503 ) ;
V_4 -> V_1503 = NULL ;
}
F_545 ( V_4 ) ;
F_575 ( V_4 ) ;
F_617 ( V_11 ) ;
F_618 ( V_1234 ) ;
F_619 ( V_1234 ) ;
F_615 ( V_1234 , NULL ) ;
}
}
static int F_623 ( struct V_1515 * V_1234 , T_15 V_1378 )
{
struct V_308 * V_11 = F_621 ( V_1234 ) ;
struct V_3 * V_4 = F_399 ( V_11 ) ;
unsigned long V_87 ;
if ( ! F_416 ( V_11 ) )
return 0 ;
F_624 ( & V_4 -> V_1123 ) ;
F_430 ( V_4 ) ;
F_407 ( & V_4 -> V_15 ) ;
F_63 ( & V_4 -> V_155 , V_87 ) ;
F_25 ( V_4 , 0 ) ;
F_65 ( & V_4 -> V_155 , V_87 ) ;
F_625 ( V_11 ) ;
F_63 ( & V_4 -> V_155 , V_87 ) ;
F_388 ( V_4 ) ;
F_65 ( & V_4 -> V_155 , V_87 ) ;
F_613 ( V_1234 ) ;
return 0 ;
}
static int F_626 ( struct V_1515 * V_1234 )
{
struct V_308 * V_11 = F_621 ( V_1234 ) ;
struct V_3 * V_4 = F_399 ( V_11 ) ;
unsigned long V_87 ;
int V_10 ;
if ( ! F_416 ( V_11 ) )
return 0 ;
F_627 ( V_1234 ) ;
F_628 ( V_11 ) ;
F_63 ( & V_4 -> V_155 , V_87 ) ;
V_10 = F_387 ( V_4 ) ;
if ( ! V_10 ) {
V_4 -> V_15 . V_337 = V_338 + V_336 ;
F_111 ( & V_4 -> V_15 ) ;
F_432 ( V_4 ) ;
}
F_65 ( & V_4 -> V_155 , V_87 ) ;
return V_10 ;
}
static void * F_629 ( struct V_508 * V_11 , T_13 V_487 ,
T_1 * V_1609 , T_6 V_1564 )
{
unsigned long V_1610 = F_630 ( V_487 ) ;
unsigned long V_485 = F_631 ( V_1564 , V_1610 ) ;
if ( V_485 == 0UL )
return NULL ;
memset ( ( char * ) V_485 , 0 , V_509 << V_1610 ) ;
* V_1609 = F_632 ( V_485 ) ;
return ( void * ) V_485 ;
}
static void F_633 ( struct V_508 * V_11 , T_13 V_487 ,
void * V_1566 , T_1 V_1563 )
{
unsigned long V_1610 = F_630 ( V_487 ) ;
F_634 ( ( unsigned long ) V_1566 , V_1610 ) ;
}
static T_1 F_635 ( struct V_508 * V_11 , struct V_485 * V_485 ,
unsigned long V_486 , T_13 V_487 ,
enum V_1567 V_1568 )
{
return F_636 ( V_485 ) + V_486 ;
}
static void F_637 ( struct V_508 * V_11 , T_1 V_1569 ,
T_13 V_487 , enum V_1567 V_1568 )
{
}
static T_1 F_638 ( struct V_508 * V_11 , void * V_1566 ,
T_13 V_487 ,
enum V_1567 V_1568 )
{
return F_632 ( V_1566 ) ;
}
static void F_639 ( struct V_508 * V_11 , T_1 V_1569 ,
T_13 V_487 ,
enum V_1567 V_1568 )
{
}
static int F_640 ( struct V_1521 * V_1522 )
{
union V_1549 V_1585 ;
struct V_308 * V_11 ;
struct V_3 * V_4 ;
const T_3 * V_1 ;
int V_10 ;
F_591 () ;
V_1 = F_541 ( V_1522 -> V_11 . V_1524 , L_226 , NULL ) ;
if ( ! V_1 ) {
F_225 ( & V_1522 -> V_11 , L_227 ,
V_1522 -> V_11 . V_1524 -> V_1534 ) ;
return - V_8 ;
}
V_11 = F_592 ( & V_1522 -> V_11 , NULL , V_1522 ,
& V_1611 , V_1 [ 0 ] & 0x1 ) ;
if ( ! V_11 ) {
V_10 = - V_506 ;
goto V_1612;
}
V_4 = F_399 ( V_11 ) ;
memset ( & V_1585 , 0 , sizeof( V_1585 ) ) ;
V_1585 . V_1613 = F_641 ( V_1522 -> V_11 . V_1524 ) ;
V_4 -> V_25 = F_569 ( V_4 , & V_1585 ,
V_343 ) ;
if ( ! V_4 -> V_25 ) {
V_10 = - V_506 ;
goto V_1596;
}
F_598 ( V_11 ) ;
V_4 -> V_1503 = F_642 ( & V_1522 -> V_1614 [ 1 ] , 0 ,
F_643 ( & V_1522 -> V_1614 [ 1 ] ) ,
L_228 ) ;
if ( ! V_4 -> V_1503 ) {
F_225 ( & V_1522 -> V_11 , L_223 ) ;
V_10 = - V_506 ;
goto V_1605;
}
V_4 -> V_1615 = F_642 ( & V_1522 -> V_1614 [ 2 ] , 0 ,
F_643 ( & V_1522 -> V_1614 [ 2 ] ) ,
L_229 ) ;
if ( ! V_4 -> V_1615 ) {
F_225 ( & V_1522 -> V_11 , L_230 ) ;
V_10 = - V_506 ;
goto V_1608;
}
V_4 -> V_1616 = F_642 ( & V_1522 -> V_1614 [ 3 ] , 0 ,
F_643 ( & V_1522 -> V_1614 [ 3 ] ) ,
L_231 ) ;
if ( ! V_4 -> V_1616 ) {
F_225 ( & V_1522 -> V_11 , L_232 ) ;
V_10 = - V_506 ;
goto V_1608;
}
F_596 ( V_11 ) ;
V_10 = F_550 ( V_4 ) ;
if ( V_10 ) {
if ( V_10 != - V_8 )
F_225 ( & V_1522 -> V_11 , L_224 ) ;
goto V_1608;
}
V_10 = F_614 ( V_11 ) ;
if ( V_10 ) {
F_225 ( & V_1522 -> V_11 , L_225 ) ;
goto V_1608;
}
F_644 ( V_1522 , V_11 ) ;
F_597 ( V_4 ) ;
return 0 ;
V_1608:
if ( V_4 -> V_1615 ) {
F_645 ( & V_1522 -> V_1614 [ 2 ] , V_4 -> V_1615 ,
F_643 ( & V_1522 -> V_1614 [ 2 ] ) ) ;
V_4 -> V_1615 = NULL ;
}
if ( V_4 -> V_1616 ) {
F_645 ( & V_1522 -> V_1614 [ 3 ] , V_4 -> V_1616 ,
F_643 ( & V_1522 -> V_1614 [ 3 ] ) ) ;
V_4 -> V_1616 = NULL ;
}
if ( V_4 -> V_1503 ) {
F_645 ( & V_1522 -> V_1614 [ 1 ] , V_4 -> V_1503 ,
F_643 ( & V_1522 -> V_1614 [ 1 ] ) ) ;
V_4 -> V_1503 = NULL ;
}
V_1605:
F_575 ( V_4 ) ;
V_1596:
F_617 ( V_11 ) ;
V_1612:
return V_10 ;
}
static int F_646 ( struct V_1521 * V_1522 )
{
struct V_308 * V_11 = F_647 ( V_1522 ) ;
if ( V_11 ) {
struct V_3 * V_4 = F_399 ( V_11 ) ;
F_622 ( V_11 ) ;
if ( V_4 -> V_1615 ) {
F_645 ( & V_1522 -> V_1614 [ 2 ] , V_4 -> V_1615 ,
F_643 ( & V_1522 -> V_1614 [ 2 ] ) ) ;
V_4 -> V_1615 = NULL ;
}
if ( V_4 -> V_1616 ) {
F_645 ( & V_1522 -> V_1614 [ 3 ] , V_4 -> V_1616 ,
F_643 ( & V_1522 -> V_1614 [ 3 ] ) ) ;
V_4 -> V_1616 = NULL ;
}
if ( V_4 -> V_1503 ) {
F_645 ( & V_1522 -> V_1614 [ 1 ] , V_4 -> V_1503 ,
F_643 ( & V_1522 -> V_1614 [ 1 ] ) ) ;
V_4 -> V_1503 = NULL ;
}
F_545 ( V_4 ) ;
F_575 ( V_4 ) ;
F_617 ( V_11 ) ;
}
return 0 ;
}
static int T_16 F_648 ( void )
{
int V_10 = 0 ;
F_269 ( V_509 < 4 * 1024 ) ;
V_1573 = F_649 ( V_1617 , V_1618 ) ;
#ifdef F_540
V_10 = F_650 ( & V_1619 ) ;
#endif
if ( ! V_10 ) {
V_10 = F_651 ( & V_1620 ) ;
#ifdef F_540
if ( V_10 )
F_652 ( & V_1619 ) ;
#endif
}
return V_10 ;
}
static void T_17 F_653 ( void )
{
F_654 ( & V_1620 ) ;
#ifdef F_540
F_652 ( & V_1619 ) ;
#endif
}

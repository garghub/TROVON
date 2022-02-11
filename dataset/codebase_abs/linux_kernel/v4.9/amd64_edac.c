int F_1 ( struct V_1 * V_2 , int V_3 ,
T_1 * V_4 , const char * V_5 )
{
int V_6 = 0 ;
V_6 = F_2 ( V_2 , V_3 , V_4 ) ;
if ( V_6 )
F_3 ( L_1 ,
V_5 , F_4 ( V_2 -> V_7 ) , V_3 ) ;
return V_6 ;
}
int F_5 ( struct V_1 * V_2 , int V_3 ,
T_1 V_4 , const char * V_5 )
{
int V_6 = 0 ;
V_6 = F_6 ( V_2 , V_3 , V_4 ) ;
if ( V_6 )
F_3 ( L_2 ,
V_5 , F_4 ( V_2 -> V_7 ) , V_3 ) ;
return V_6 ;
}
static void F_7 ( struct V_8 * V_9 , T_2 V_10 )
{
T_1 V_11 = 0 ;
F_8 ( V_9 -> V_12 , V_13 , & V_11 ) ;
V_11 &= ( V_9 -> V_14 == 0x30 ) ? ~ 3 : ~ 1 ;
V_11 |= V_10 ;
F_9 ( V_9 -> V_12 , V_13 , V_11 ) ;
}
static inline int F_10 ( struct V_8 * V_9 , T_2 V_10 ,
int V_3 , T_1 * V_4 )
{
switch ( V_9 -> V_15 ) {
case 0xf :
if ( V_10 || V_3 >= 0x100 )
return - V_16 ;
break;
case 0x10 :
if ( V_10 ) {
if ( F_11 ( V_9 ) )
return 0 ;
V_3 += 0x100 ;
}
break;
case 0x15 :
V_10 = ( V_10 && V_9 -> V_14 == 0x30 ) ? 3 : V_10 ;
F_7 ( V_9 , V_10 ) ;
break;
case 0x16 :
if ( V_10 )
return - V_16 ;
break;
default:
break;
}
return F_8 ( V_9 -> V_17 , V_3 , V_4 ) ;
}
static int F_12 ( struct V_8 * V_9 , T_1 V_18 , T_1 V_19 )
{
T_1 V_20 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < F_13 ( V_22 ) - 1 ; V_21 ++ ) {
if ( V_22 [ V_21 ] . V_20 < V_19 )
continue;
if ( V_22 [ V_21 ] . V_23 <= V_18 )
break;
}
V_20 = V_22 [ V_21 ] . V_20 ;
if ( V_9 -> V_15 == 0x15 && V_9 -> V_14 == 0x60 ) {
F_7 ( V_9 , 0 ) ;
F_14 ( V_9 -> V_17 , V_24 , V_20 , 0x001F ) ;
F_7 ( V_9 , 1 ) ;
F_14 ( V_9 -> V_17 , V_24 , V_20 , 0x001F ) ;
} else {
F_14 ( V_9 -> V_25 , V_26 , V_20 , 0x001F ) ;
}
if ( V_20 )
return V_22 [ V_21 ] . V_23 ;
return 0 ;
}
static int F_15 ( struct V_27 * V_28 , T_1 V_29 )
{
struct V_8 * V_9 = V_28 -> V_30 ;
T_1 V_31 = 0x5 ;
if ( V_9 -> V_15 == 0xf )
V_31 = 0x0 ;
if ( V_9 -> V_15 == 0x15 ) {
if ( V_9 -> V_14 < 0x10 )
F_7 ( V_9 , 0 ) ;
if ( V_9 -> V_14 == 0x60 )
V_31 = 0x6 ;
}
return F_12 ( V_9 , V_29 , V_31 ) ;
}
static int F_16 ( struct V_27 * V_28 )
{
struct V_8 * V_9 = V_28 -> V_30 ;
T_1 V_20 = 0 ;
int V_21 , V_32 = - V_16 ;
if ( V_9 -> V_15 == 0x15 ) {
if ( V_9 -> V_14 < 0x10 )
F_7 ( V_9 , 0 ) ;
if ( V_9 -> V_14 == 0x60 )
F_8 ( V_9 -> V_17 , V_24 , & V_20 ) ;
} else
F_8 ( V_9 -> V_25 , V_26 , & V_20 ) ;
V_20 = V_20 & 0x001F ;
for ( V_21 = 0 ; V_21 < F_13 ( V_22 ) ; V_21 ++ ) {
if ( V_22 [ V_21 ] . V_20 == V_20 ) {
V_32 = V_22 [ V_21 ] . V_23 ;
break;
}
}
return V_32 ;
}
static bool F_17 ( struct V_8 * V_9 , T_3 V_33 , T_2 V_34 )
{
T_3 V_35 ;
V_35 = V_33 & 0x000000ffffffffffull ;
return ( ( V_35 >= F_18 ( V_9 , V_34 ) ) &&
( V_35 <= F_19 ( V_9 , V_34 ) ) ) ;
}
static struct V_27 * F_20 ( struct V_27 * V_28 ,
T_3 V_33 )
{
struct V_8 * V_9 ;
T_2 V_36 ;
T_1 V_37 , V_38 ;
V_9 = V_28 -> V_30 ;
V_37 = F_21 ( V_9 , 0 ) ;
if ( V_37 == 0 ) {
for ( V_36 = 0 ; V_36 < V_39 ; V_36 ++ ) {
if ( F_17 ( V_9 , V_33 , V_36 ) )
goto V_40;
}
goto V_41;
}
if ( F_22 ( ( V_37 != 0x01 ) &&
( V_37 != 0x03 ) &&
( V_37 != 0x07 ) ) ) {
F_3 ( L_3 , V_37 ) ;
return NULL ;
}
V_38 = ( ( ( T_1 ) V_33 ) >> 12 ) & V_37 ;
for ( V_36 = 0 ; ; ) {
if ( ( F_23 ( V_9 , V_36 ) & V_37 ) == V_38 )
break;
if ( ++ V_36 >= V_39 )
goto V_41;
}
if ( F_22 ( ! F_17 ( V_9 , V_33 , V_36 ) ) ) {
F_3 ( L_4
L_5 ,
V_42 , V_33 , V_36 ) ;
return NULL ;
}
V_40:
return F_24 ( ( int ) V_36 ) ;
V_41:
F_25 ( 2 , L_6 ,
( unsigned long ) V_33 ) ;
return NULL ;
}
static void F_26 ( struct V_8 * V_9 , int V_43 , T_2 V_10 ,
T_3 * V_44 , T_3 * V_45 )
{
T_3 V_46 , V_47 , V_48 , V_49 ;
T_2 V_50 ;
if ( V_9 -> V_15 == 0xf && V_9 -> V_51 < V_52 ) {
V_46 = V_9 -> V_53 [ V_10 ] . V_54 [ V_43 ] ;
V_47 = V_9 -> V_53 [ V_10 ] . V_55 [ V_43 ] ;
V_48 = F_27 ( 31 , 21 ) | F_27 ( 15 , 9 ) ;
V_49 = F_27 ( 29 , 21 ) | F_27 ( 15 , 9 ) ;
V_50 = 4 ;
} else if ( V_9 -> V_15 == 0x16 ||
( V_9 -> V_15 == 0x15 && V_9 -> V_14 >= 0x30 ) ) {
V_46 = V_9 -> V_53 [ V_10 ] . V_54 [ V_43 ] ;
V_47 = V_9 -> V_53 [ V_10 ] . V_55 [ V_43 >> 1 ] ;
* V_44 = ( V_46 & F_27 ( 15 , 5 ) ) << 6 ;
* V_44 |= ( V_46 & F_27 ( 30 , 19 ) ) << 8 ;
* V_45 = ~ 0ULL ;
* V_45 &= ~ ( ( F_27 ( 15 , 5 ) << 6 ) |
( F_27 ( 30 , 19 ) << 8 ) ) ;
* V_45 |= ( V_47 & F_27 ( 15 , 5 ) ) << 6 ;
* V_45 |= ( V_47 & F_27 ( 30 , 19 ) ) << 8 ;
return;
} else {
V_46 = V_9 -> V_53 [ V_10 ] . V_54 [ V_43 ] ;
V_47 = V_9 -> V_53 [ V_10 ] . V_55 [ V_43 >> 1 ] ;
V_50 = 8 ;
if ( V_9 -> V_15 == 0x15 )
V_48 = V_49 =
F_27 ( 30 , 19 ) | F_27 ( 13 , 5 ) ;
else
V_48 = V_49 =
F_27 ( 28 , 19 ) | F_27 ( 13 , 5 ) ;
}
* V_44 = ( V_46 & V_48 ) << V_50 ;
* V_45 = ~ 0ULL ;
* V_45 &= ~ ( V_49 << V_50 ) ;
* V_45 |= ( V_47 & V_49 ) << V_50 ;
}
static int F_28 ( struct V_27 * V_28 , T_3 V_56 )
{
struct V_8 * V_9 ;
int V_43 ;
T_3 V_44 , V_45 ;
V_9 = V_28 -> V_30 ;
F_29 (csrow, 0 , pvt) {
if ( ! F_30 ( V_43 , 0 , V_9 ) )
continue;
F_26 ( V_9 , V_43 , 0 , & V_44 , & V_45 ) ;
V_45 = ~ V_45 ;
if ( ( V_56 & V_45 ) == ( V_44 & V_45 ) ) {
F_25 ( 2 , L_7 ,
( unsigned long ) V_56 , V_43 ,
V_9 -> V_57 ) ;
return V_43 ;
}
}
F_25 ( 2 , L_8 ,
( unsigned long ) V_56 , V_9 -> V_57 ) ;
return - 1 ;
}
int F_31 ( struct V_27 * V_28 , T_3 * V_58 ,
T_3 * V_59 , T_3 * V_60 )
{
struct V_8 * V_9 = V_28 -> V_30 ;
if ( V_9 -> V_15 == 0xf && V_9 -> V_51 < V_61 ) {
F_25 ( 1 , L_9 ,
V_9 -> V_51 , V_9 -> V_57 ) ;
return 1 ;
}
if ( V_9 -> V_15 >= 0x10 && ! F_32 ( V_9 ) ) {
F_25 ( 1 , L_10 ) ;
return 1 ;
}
if ( ! F_33 ( V_9 ) ) {
F_25 ( 1 , L_11 ,
V_9 -> V_57 ) ;
return 1 ;
}
* V_58 = F_34 ( V_9 ) ;
* V_60 = ( 1ULL << 32 ) - * V_58 ;
* V_59 = ( V_9 -> V_15 > 0xf ) ? F_35 ( V_9 )
: F_36 ( V_9 ) ;
F_25 ( 1 , L_12 ,
V_9 -> V_57 , ( unsigned long ) * V_58 ,
( unsigned long ) * V_59 , ( unsigned long ) * V_60 ) ;
return 0 ;
}
static T_3 F_37 ( struct V_27 * V_28 , T_3 V_33 )
{
struct V_8 * V_9 = V_28 -> V_30 ;
T_3 V_62 , V_58 , V_59 , V_60 , V_63 ;
int V_64 ;
V_62 = F_18 ( V_9 , V_9 -> V_57 ) ;
V_64 = F_31 ( V_28 , & V_58 , & V_59 ,
& V_60 ) ;
if ( ! V_64 ) {
if ( ( V_33 >= ( 1ULL << 32 ) ) &&
( V_33 < ( ( 1ULL << 32 ) + V_60 ) ) ) {
V_63 = V_33 - V_59 ;
F_25 ( 2 , L_13 ,
( unsigned long ) V_33 ,
( unsigned long ) V_63 ) ;
return V_63 ;
}
}
V_63 = ( V_33 & F_27 ( 39 , 0 ) ) - V_62 ;
F_25 ( 2 , L_14 ,
( unsigned long ) V_33 , ( unsigned long ) V_63 ) ;
return V_63 ;
}
static int F_38 ( unsigned V_37 )
{
static const int V_65 [] = { 0 , 1 , 0 , 2 , 0 , 0 , 0 , 3 } ;
int V_66 ;
F_39 ( V_37 > 7 ) ;
V_66 = V_65 [ V_37 ] ;
return V_66 ;
}
static T_3 F_40 ( struct V_27 * V_28 , T_3 V_63 )
{
struct V_8 * V_9 ;
int V_67 ;
T_3 V_56 ;
V_9 = V_28 -> V_30 ;
V_67 = F_38 ( F_21 ( V_9 , 0 ) ) ;
V_56 = ( ( V_63 >> V_67 ) & F_27 ( 35 , 12 ) ) +
( V_63 & 0xfff ) ;
F_25 ( 2 , L_15 ,
V_67 , ( unsigned long ) V_63 ,
( unsigned long ) V_56 ) ;
return V_56 ;
}
static T_3 F_41 ( struct V_27 * V_28 , T_3 V_33 )
{
T_3 V_56 ;
V_56 =
F_40 ( V_28 , F_37 ( V_28 , V_33 ) ) ;
F_25 ( 2 , L_16 ,
( unsigned long ) V_33 , ( unsigned long ) V_56 ) ;
return V_56 ;
}
static inline void F_42 ( T_3 V_68 ,
struct V_69 * V_6 )
{
V_6 -> V_70 = ( T_1 ) ( V_68 >> V_71 ) ;
V_6 -> V_3 = ( ( T_1 ) V_68 ) & ~ V_72 ;
}
static int F_43 ( struct V_27 * V_28 , T_3 V_33 )
{
int V_43 ;
V_43 = F_28 ( V_28 , F_41 ( V_28 , V_33 ) ) ;
if ( V_43 == - 1 )
F_44 ( V_28 , L_17
L_18 , ( unsigned long ) V_33 ) ;
return V_43 ;
}
static unsigned long F_45 ( struct V_8 * V_9 )
{
T_2 V_73 ;
unsigned long V_74 = V_75 ;
V_73 = ( V_9 -> V_15 > 0xf || V_9 -> V_51 >= V_52 )
? 19
: 17 ;
if ( V_9 -> V_76 & F_46 ( V_73 ) )
V_74 = V_77 ;
return V_74 ;
}
static void F_47 ( struct V_8 * V_9 , T_1 V_78 , int V_79 )
{
F_25 ( 1 , L_19 , V_79 , V_78 ) ;
if ( V_9 -> V_80 == V_81 ) {
T_1 V_82 = V_9 -> V_53 [ V_79 ] . V_55 [ 0 ] ;
F_25 ( 1 , L_20 , ( V_82 & 0x3 ) ) ;
}
F_25 ( 1 , L_21 ,
( V_78 & F_46 ( 19 ) ) ? L_22 : L_23 ) ;
F_25 ( 1 , L_24 ,
( V_78 & F_46 ( 8 ) ) ? L_25 : L_26 ) ;
if ( V_9 -> V_15 == 0x10 )
F_25 ( 1 , L_27 ,
( V_78 & F_46 ( 11 ) ) ? L_28 : L_29 ) ;
F_25 ( 1 , L_30 ,
( V_78 & F_46 ( 12 ) ) ? L_22 : L_23 ,
( V_78 & F_46 ( 13 ) ) ? L_22 : L_23 ,
( V_78 & F_46 ( 14 ) ) ? L_22 : L_23 ,
( V_78 & F_46 ( 15 ) ) ? L_22 : L_23 ) ;
}
static void F_48 ( struct V_8 * V_9 )
{
F_25 ( 1 , L_31 , V_9 -> V_83 ) ;
F_25 ( 1 , L_32 ,
( V_9 -> V_83 & V_84 ) ? L_22 : L_23 ) ;
F_25 ( 1 , L_33 ,
( V_9 -> V_83 & V_85 ) ? L_22 : L_23 ,
( V_9 -> V_83 & V_86 ) ? L_22 : L_23 ) ;
F_47 ( V_9 , V_9 -> V_76 , 0 ) ;
F_25 ( 1 , L_34 , V_9 -> V_87 ) ;
F_25 ( 1 , L_35 ,
V_9 -> V_88 , F_34 ( V_9 ) ,
( V_9 -> V_15 == 0xf ) ? F_36 ( V_9 )
: F_35 ( V_9 ) ) ;
F_25 ( 1 , L_36 , F_33 ( V_9 ) ? L_22 : L_23 ) ;
F_49 ( V_9 , 0 ) ;
if ( V_9 -> V_15 == 0xf )
return;
F_49 ( V_9 , 1 ) ;
F_50 ( L_37 , ( ( V_9 -> V_89 == 8 ) ? L_38 : L_39 ) ) ;
if ( ! F_11 ( V_9 ) )
F_47 ( V_9 , V_9 -> V_90 , 1 ) ;
}
static void F_51 ( struct V_8 * V_9 )
{
if ( V_9 -> V_15 == 0xf && V_9 -> V_51 < V_52 ) {
V_9 -> V_53 [ 0 ] . V_91 = V_9 -> V_53 [ 1 ] . V_91 = 8 ;
V_9 -> V_53 [ 0 ] . V_92 = V_9 -> V_53 [ 1 ] . V_92 = 8 ;
} else if ( V_9 -> V_15 == 0x15 && V_9 -> V_14 == 0x30 ) {
V_9 -> V_53 [ 0 ] . V_91 = V_9 -> V_53 [ 1 ] . V_91 = 4 ;
V_9 -> V_53 [ 0 ] . V_92 = V_9 -> V_53 [ 1 ] . V_92 = 2 ;
} else {
V_9 -> V_53 [ 0 ] . V_91 = V_9 -> V_53 [ 1 ] . V_91 = 8 ;
V_9 -> V_53 [ 0 ] . V_92 = V_9 -> V_53 [ 1 ] . V_92 = 4 ;
}
}
static void F_52 ( struct V_8 * V_9 )
{
int V_93 ;
F_51 ( V_9 ) ;
F_29 (cs, 0 , pvt) {
int V_94 = V_95 + ( V_93 * 4 ) ;
int V_96 = V_97 + ( V_93 * 4 ) ;
T_1 * V_98 = & V_9 -> V_53 [ 0 ] . V_54 [ V_93 ] ;
T_1 * V_99 = & V_9 -> V_53 [ 1 ] . V_54 [ V_93 ] ;
if ( ! F_10 ( V_9 , 0 , V_94 , V_98 ) )
F_25 ( 0 , L_40 ,
V_93 , * V_98 , V_94 ) ;
if ( V_9 -> V_15 == 0xf )
continue;
if ( ! F_10 ( V_9 , 1 , V_94 , V_99 ) )
F_25 ( 0 , L_41 ,
V_93 , * V_99 , ( V_9 -> V_15 == 0x10 ) ? V_96
: V_94 ) ;
}
F_53 (cs, 0 , pvt) {
int V_94 = V_100 + ( V_93 * 4 ) ;
int V_96 = V_101 + ( V_93 * 4 ) ;
T_1 * V_102 = & V_9 -> V_53 [ 0 ] . V_55 [ V_93 ] ;
T_1 * V_103 = & V_9 -> V_53 [ 1 ] . V_55 [ V_93 ] ;
if ( ! F_10 ( V_9 , 0 , V_94 , V_102 ) )
F_25 ( 0 , L_42 ,
V_93 , * V_102 , V_94 ) ;
if ( V_9 -> V_15 == 0xf )
continue;
if ( ! F_10 ( V_9 , 1 , V_94 , V_103 ) )
F_25 ( 0 , L_43 ,
V_93 , * V_103 , ( V_9 -> V_15 == 0x10 ) ? V_96
: V_94 ) ;
}
}
static void F_54 ( struct V_8 * V_9 )
{
T_1 V_104 , V_82 ;
switch ( V_9 -> V_15 ) {
case 0xf :
if ( V_9 -> V_51 >= V_52 )
goto V_105;
V_9 -> V_80 = ( V_9 -> V_76 & F_46 ( 18 ) ) ? V_106 : V_107 ;
return;
case 0x10 :
if ( V_9 -> V_108 & V_109 )
goto V_105;
V_9 -> V_80 = ( V_9 -> V_76 & F_46 ( 16 ) ) ? V_110 : V_111 ;
return;
case 0x15 :
if ( V_9 -> V_14 < 0x60 )
goto V_105;
F_10 ( V_9 , 0 , V_112 , & V_104 ) ;
V_82 = V_9 -> V_53 [ 0 ] . V_55 [ 0 ] ;
if ( ( ( V_104 >> 8 ) & 0x7 ) == 0x2 )
V_9 -> V_80 = V_113 ;
else if ( V_9 -> V_76 & F_46 ( 16 ) )
V_9 -> V_80 = V_114 ;
else if ( V_82 & 0x3 )
V_9 -> V_80 = V_81 ;
else
V_9 -> V_80 = V_115 ;
return;
case 0x16 :
goto V_105;
default:
F_55 ( 1 , V_116 L_44 , V_42 , V_9 -> V_15 ) ;
V_9 -> V_80 = V_117 ;
}
return;
V_105:
V_9 -> V_80 = ( V_9 -> V_76 & F_46 ( 16 ) ) ? V_114 : V_115 ;
}
static int F_56 ( struct V_8 * V_9 )
{
int V_118 ;
if ( V_9 -> V_51 >= V_52 )
V_118 = V_9 -> V_76 & V_119 ;
else
V_118 = V_9 -> V_76 & V_120 ;
V_9 -> V_90 = 0 ;
return ( V_118 ) ? 2 : 1 ;
}
static T_3 F_57 ( struct V_8 * V_9 , struct V_121 * V_122 )
{
T_4 V_123 = F_58 ( V_122 -> V_124 ) ;
struct V_27 * V_28 ;
T_2 V_125 = 1 ;
T_2 V_126 = 47 ;
T_3 V_35 ;
V_28 = F_24 ( V_123 ) ;
if ( ! V_28 )
return 0 ;
V_9 = V_28 -> V_30 ;
if ( V_9 -> V_15 == 0xf ) {
V_125 = 3 ;
V_126 = 39 ;
}
V_35 = V_122 -> V_35 & F_27 ( V_126 , V_125 ) ;
if ( V_9 -> V_15 == 0x15 ) {
T_3 V_127 , V_128 ;
T_1 V_129 ;
T_2 V_37 ;
if ( ( V_35 & F_27 ( 47 , 24 ) ) >> 24 != 0x00fdf7 )
return V_35 ;
F_8 ( V_9 -> V_12 , V_130 , & V_129 ) ;
V_37 = V_129 >> 21 & 0x7 ;
V_127 = ( V_129 & F_27 ( 20 , 0 ) ) << 3 ;
V_127 |= V_37 ^ 0x7 ;
V_127 <<= 24 ;
if ( ! V_37 )
return V_127 | ( V_35 & F_27 ( 23 , 0 ) ) ;
F_8 ( V_9 -> V_12 , V_131 , & V_129 ) ;
V_128 = ( V_35 & F_27 ( 23 , 12 ) ) << F_59 ( V_37 + 1 ) ;
V_128 |= ( V_129 & F_27 ( 23 , 21 ) ) >> 9 ;
V_128 |= V_35 & F_27 ( 11 , 0 ) ;
return V_127 | V_128 ;
}
return V_35 ;
}
static struct V_1 * F_60 ( unsigned int V_132 ,
unsigned int V_133 ,
struct V_1 * V_134 )
{
struct V_1 * V_135 = NULL ;
while ( ( V_135 = F_61 ( V_132 , V_133 , V_135 ) ) ) {
if ( F_62 ( V_135 -> V_136 ) == F_62 ( V_134 -> V_136 ) &&
( V_135 -> V_136 -> V_137 == V_134 -> V_136 -> V_137 ) &&
( F_63 ( V_135 -> V_7 ) == F_63 ( V_134 -> V_7 ) ) )
break;
}
return V_135 ;
}
static void F_64 ( struct V_8 * V_9 , unsigned V_138 )
{
struct V_139 * V_140 ;
struct V_1 * V_141 = NULL ;
unsigned int V_142 ;
int V_143 = V_138 << 3 ;
T_1 V_144 ;
F_8 ( V_9 -> V_12 , V_145 + V_143 , & V_9 -> V_146 [ V_138 ] . V_44 . V_147 ) ;
F_8 ( V_9 -> V_12 , V_148 + V_143 , & V_9 -> V_146 [ V_138 ] . V_149 . V_147 ) ;
if ( V_9 -> V_15 == 0xf )
return;
if ( ! F_65 ( V_9 , V_138 ) )
return;
F_8 ( V_9 -> V_12 , V_150 + V_143 , & V_9 -> V_146 [ V_138 ] . V_44 . V_151 ) ;
F_8 ( V_9 -> V_12 , V_152 + V_143 , & V_9 -> V_146 [ V_138 ] . V_149 . V_151 ) ;
if ( V_9 -> V_15 != 0x15 )
return;
V_140 = F_66 ( F_67 ( V_9 , V_138 ) ) ;
if ( F_68 ( ! V_140 ) )
return;
if ( V_9 -> V_14 == 0x60 )
V_142 = V_153 ;
else if ( V_9 -> V_14 == 0x30 )
V_142 = V_154 ;
else
V_142 = V_155 ;
V_141 = F_60 ( V_140 -> V_156 -> V_132 , V_142 , V_140 -> V_156 ) ;
if ( F_68 ( ! V_141 ) )
return;
F_8 ( V_141 , V_130 , & V_144 ) ;
V_9 -> V_146 [ V_138 ] . V_149 . V_147 &= F_27 ( 15 , 0 ) ;
V_9 -> V_146 [ V_138 ] . V_149 . V_147 |= ( ( V_144 & 0x1fff ) << 3 | 0x7 ) << 16 ;
V_9 -> V_146 [ V_138 ] . V_149 . V_151 &= F_27 ( 7 , 0 ) ;
V_9 -> V_146 [ V_138 ] . V_149 . V_151 |= V_144 >> 13 ;
F_69 ( V_141 ) ;
}
static void F_70 ( struct V_27 * V_28 , T_3 V_33 ,
struct V_69 * V_6 )
{
struct V_8 * V_9 = V_28 -> V_30 ;
F_42 ( V_33 , V_6 ) ;
V_6 -> V_157 = F_20 ( V_28 , V_33 ) ;
if ( ! V_6 -> V_157 ) {
F_44 ( V_28 , L_45 ,
( unsigned long ) V_33 ) ;
V_6 -> V_158 = V_159 ;
return;
}
V_6 -> V_43 = F_43 ( V_6 -> V_157 , V_33 ) ;
if ( V_6 -> V_43 < 0 ) {
V_6 -> V_158 = V_160 ;
return;
}
if ( V_9 -> V_161 & V_162 ) {
V_6 -> V_163 = F_71 ( V_28 , V_6 -> V_164 ) ;
if ( V_6 -> V_163 < 0 ) {
F_72 ( V_6 -> V_157 , L_46
L_47 ,
V_6 -> V_164 ) ;
V_6 -> V_158 = V_165 ;
return;
}
} else {
V_6 -> V_163 = ( ( V_33 & F_46 ( 3 ) ) != 0 ) ;
}
}
static int F_73 ( unsigned V_21 , bool V_166 )
{
unsigned V_167 = 0 ;
if ( V_21 <= 2 )
V_167 = V_21 ;
else if ( ! ( V_21 & 0x1 ) )
V_167 = V_21 >> 1 ;
else
V_167 = ( V_21 + 1 ) >> 1 ;
return 128 << ( V_167 + ! ! V_166 ) ;
}
static int F_74 ( struct V_8 * V_9 , T_2 V_10 ,
unsigned V_168 , int V_169 )
{
T_1 V_78 = V_10 ? V_9 -> V_90 : V_9 -> V_76 ;
if ( V_9 -> V_51 >= V_52 ) {
F_68 ( V_168 > 11 ) ;
return F_73 ( V_168 , V_78 & V_119 ) ;
}
else if ( V_9 -> V_51 >= V_170 ) {
unsigned V_171 ;
F_68 ( V_168 > 10 ) ;
V_171 = V_168 / 3 + ( unsigned ) ( V_168 > 5 ) ;
return 32 << ( V_168 - V_171 ) ;
}
else {
F_68 ( V_168 > 6 ) ;
return 32 << V_168 ;
}
}
static int F_75 ( struct V_8 * V_9 )
{
int V_21 , V_172 , V_173 = 0 ;
if ( V_9 -> V_15 == 0x10 && ( V_9 -> V_76 & V_119 ) )
return 2 ;
F_25 ( 0 , L_48 ) ;
for ( V_21 = 0 ; V_21 < 2 ; V_21 ++ ) {
T_1 V_174 = ( V_21 ? V_9 -> V_175 : V_9 -> V_176 ) ;
for ( V_172 = 0 ; V_172 < 4 ; V_172 ++ ) {
if ( F_76 ( V_172 , V_174 ) > 0 ) {
V_173 ++ ;
break;
}
}
}
if ( V_173 > 2 )
V_173 = 2 ;
F_50 ( L_49 , V_173 ) ;
return V_173 ;
}
static int F_77 ( unsigned V_21 , bool V_166 )
{
unsigned V_167 = 0 ;
int V_177 = 0 ;
if ( V_21 == 0 || V_21 == 3 || V_21 == 4 )
V_177 = - 1 ;
else if ( V_21 <= 2 )
V_167 = V_21 ;
else if ( V_21 == 12 )
V_167 = 7 ;
else if ( ! ( V_21 & 0x1 ) )
V_167 = V_21 >> 1 ;
else
V_167 = ( V_21 + 1 ) >> 1 ;
if ( V_177 != - 1 )
V_177 = ( 128 * ( 1 << ! ! V_166 ) ) << V_167 ;
return V_177 ;
}
static int F_78 ( unsigned V_21 , unsigned V_178 )
{
unsigned V_167 = 0 ;
int V_177 = 0 ;
if ( V_21 < 4 || V_21 == 6 )
V_177 = - 1 ;
else if ( V_21 == 12 )
V_167 = 7 ;
else if ( ! ( V_21 & 0x1 ) )
V_167 = V_21 >> 1 ;
else
V_167 = ( V_21 + 1 ) >> 1 ;
if ( V_177 != - 1 )
V_177 = V_178 * ( 128 << V_167 ) ;
return V_177 ;
}
static int F_79 ( unsigned V_21 )
{
int V_177 = 0 ;
if ( V_21 == 0 )
V_177 = - 1 ;
else if ( V_21 == 1 )
V_177 = 1024 ;
else
V_177 = 1024 * ( 1 << ( V_21 >> 1 ) ) ;
return V_177 ;
}
static int F_80 ( struct V_8 * V_9 , T_2 V_10 ,
unsigned V_168 , int V_169 )
{
T_1 V_78 = V_10 ? V_9 -> V_90 : V_9 -> V_76 ;
F_68 ( V_168 > 11 ) ;
if ( V_9 -> V_108 & V_109 || V_9 -> V_179 & V_109 )
return F_77 ( V_168 , V_78 & V_119 ) ;
else
return F_73 ( V_168 , V_78 & V_119 ) ;
}
static int F_81 ( struct V_8 * V_9 , T_2 V_10 ,
unsigned V_168 , int V_169 )
{
F_68 ( V_168 > 12 ) ;
return F_77 ( V_168 , false ) ;
}
static int F_82 ( struct V_8 * V_9 , T_2 V_10 ,
unsigned V_168 , int V_169 )
{
int V_177 ;
T_1 V_82 = V_9 -> V_53 [ V_10 ] . V_55 [ V_169 ] ;
F_68 ( V_168 > 12 ) ;
if ( V_9 -> V_80 == V_113 ) {
if ( V_168 > 9 )
return - 1 ;
V_177 = F_79 ( V_168 ) ;
} else if ( V_9 -> V_80 == V_81 ) {
unsigned V_178 = V_82 & 0xf ;
if ( V_178 == 3 )
V_178 = 4 ;
V_177 = F_78 ( V_168 , V_178 ) ;
} else {
if ( V_168 == 0x1 )
return - 1 ;
V_177 = F_77 ( V_168 , false ) ;
}
return V_177 ;
}
static int F_83 ( struct V_8 * V_9 , T_2 V_10 ,
unsigned V_168 , int V_169 )
{
F_68 ( V_168 > 12 ) ;
if ( V_168 == 6 || V_168 == 8 ||
V_168 == 9 || V_168 == 12 )
return - 1 ;
else
return F_77 ( V_168 , false ) ;
}
static void F_84 ( struct V_8 * V_9 )
{
if ( V_9 -> V_15 == 0xf )
return;
if ( ! F_8 ( V_9 -> V_17 , V_180 , & V_9 -> V_181 ) ) {
F_25 ( 0 , L_50 ,
V_9 -> V_181 , F_85 ( V_9 ) ) ;
F_25 ( 0 , L_51 ,
( F_11 ( V_9 ) ? L_52 : L_53 ) ) ;
if ( ! F_11 ( V_9 ) )
F_25 ( 0 , L_54 ,
( F_86 ( V_9 ) ? L_22 : L_23 ) ) ;
F_25 ( 0 , L_55 ,
( F_87 ( V_9 ) ? L_25 : L_26 ) ,
( F_88 ( V_9 ) ? L_22 : L_23 ) ) ;
F_25 ( 0 , L_56
L_57 ,
( F_89 ( V_9 ) ? L_25 : L_26 ) ,
F_90 ( V_9 ) ) ;
}
F_8 ( V_9 -> V_17 , V_182 , & V_9 -> V_183 ) ;
}
static T_2 F_91 ( struct V_8 * V_9 , T_3 V_33 ,
T_2 V_37 , int V_184 ,
T_1 V_185 )
{
T_2 V_163 = 0 ;
T_2 V_186 ;
if ( ! ( V_37 ) )
return ( T_2 ) ( V_185 ) ;
if ( V_184 == 2 ) {
V_186 = ( V_33 >> 8 ) & 0x3 ;
V_163 = V_186 ? 0x3 : 0 ;
} else if ( V_184 == 4 ) {
T_2 V_187 = F_90 ( V_9 ) ;
switch ( V_187 ) {
case 0x4 :
V_163 = ( V_33 >> 8 ) & 0x3 ;
break;
case 0x5 :
V_163 = ( V_33 >> 9 ) & 0x3 ;
break;
}
}
return V_163 ;
}
static T_2 F_92 ( struct V_8 * V_9 , T_3 V_33 ,
bool V_188 , T_2 V_37 )
{
T_2 V_189 = ( V_9 -> V_181 >> 1 ) & 1 ;
if ( F_11 ( V_9 ) )
return 0 ;
if ( V_188 )
return V_189 ;
if ( F_89 ( V_9 ) ) {
T_2 V_187 = F_90 ( V_9 ) ;
if ( ! V_187 )
return V_33 >> 6 & 1 ;
if ( V_187 & 0x2 ) {
T_2 V_167 = V_187 & 0x1 ? 9 : 6 ;
T_1 V_190 = F_93 ( ( T_1 ) ( ( V_33 >> 16 ) & 0x1F ) ) & 1 ;
return ( ( V_33 >> V_167 ) & 1 ) ^ V_190 ;
}
if ( V_187 & 0x4 ) {
T_2 V_167 = V_187 & 0x1 ? 9 : 8 ;
return ( V_33 >> V_167 ) & 1 ;
}
return ( V_33 >> ( 12 + F_94 ( V_37 ) ) ) & 1 ;
}
if ( F_86 ( V_9 ) )
return ~ V_189 & 1 ;
return 0 ;
}
static T_3 F_95 ( struct V_8 * V_9 , T_2 V_138 ,
T_3 V_33 , bool V_191 ,
T_1 V_192 )
{
T_3 V_193 ;
T_3 V_62 = F_18 ( V_9 , V_138 ) ;
T_3 V_194 = F_35 ( V_9 ) ;
T_3 V_195 = ( T_3 ) ( V_9 -> V_183 & 0xFFFFFC00 ) << 16 ;
if ( V_191 ) {
if ( ( ! ( V_192 >> 16 ) ||
V_192 < F_34 ( V_9 ) ) &&
F_33 ( V_9 ) &&
( V_33 >= F_96 ( 32 ) ) )
V_193 = V_194 ;
else
V_193 = V_195 ;
} else {
if ( F_33 ( V_9 ) && ( V_33 >= F_96 ( 32 ) ) )
V_193 = V_194 ;
else
V_193 = V_62 ;
}
return ( V_33 & F_27 ( 47 , 6 ) ) - ( V_193 & F_27 ( 47 , 23 ) ) ;
}
static int F_97 ( struct V_8 * V_9 , T_2 V_10 , int V_43 )
{
int V_196 ;
if ( F_98 ( V_9 , V_10 ) &&
V_43 == F_99 ( V_9 , V_10 ) ) {
F_29 (tmp_cs, dct, pvt) {
if ( F_100 ( V_196 , V_10 , V_9 ) & 0x2 ) {
V_43 = V_196 ;
break;
}
}
}
return V_43 ;
}
static int F_101 ( T_3 V_197 , T_2 V_34 , T_2 V_10 )
{
struct V_27 * V_28 ;
struct V_8 * V_9 ;
T_3 V_198 , V_199 ;
int V_200 = - V_16 ;
int V_43 ;
V_28 = F_24 ( V_34 ) ;
if ( ! V_28 )
return V_200 ;
V_9 = V_28 -> V_30 ;
F_25 ( 1 , L_58 , V_197 , V_10 ) ;
F_29 (csrow, dct, pvt) {
if ( ! F_30 ( V_43 , V_10 , V_9 ) )
continue;
F_26 ( V_9 , V_43 , V_10 , & V_198 , & V_199 ) ;
F_25 ( 1 , L_59 ,
V_43 , V_198 , V_199 ) ;
V_199 = ~ V_199 ;
F_25 ( 1 , L_60 ,
( V_197 & V_199 ) , ( V_198 & V_199 ) ) ;
if ( ( V_197 & V_199 ) == ( V_198 & V_199 ) ) {
if ( V_9 -> V_15 == 0x15 && V_9 -> V_14 >= 0x30 ) {
V_200 = V_43 ;
break;
}
V_200 = F_97 ( V_9 , V_10 , V_43 ) ;
F_25 ( 1 , L_61 , V_200 ) ;
break;
}
}
return V_200 ;
}
static T_3 F_102 ( struct V_8 * V_9 , T_3 V_33 )
{
T_1 V_201 , V_202 , V_203 , V_204 , V_128 ;
if ( V_9 -> V_15 == 0x10 ) {
if ( V_9 -> V_14 < 4 || ( V_9 -> V_14 < 0xa && V_9 -> V_205 < 3 ) )
return V_33 ;
}
F_8 ( V_9 -> V_17 , V_206 , & V_201 ) ;
if ( ! ( V_201 & 0x1 ) )
return V_33 ;
V_202 = ( V_201 >> 3 ) & 0x7f ;
V_203 = ( V_201 >> 11 ) & 0x7f ;
V_204 = ( V_201 >> 20 ) & 0x7f ;
V_128 = V_33 >> 27 ;
if ( ! ( V_33 >> 34 ) &&
( ( ( V_128 >= V_202 ) &&
( V_128 <= V_203 ) ) ||
( V_128 < V_204 ) ) )
return V_33 ^ ( T_3 ) V_202 << 27 ;
return V_33 ;
}
static int F_103 ( struct V_8 * V_9 , unsigned V_138 ,
T_3 V_33 , int * V_207 )
{
int V_200 = - V_16 ;
T_3 V_208 ;
T_1 V_209 ;
T_2 V_163 ;
bool V_210 = false ;
T_2 V_36 = F_67 ( V_9 , V_138 ) ;
T_2 V_37 = F_21 ( V_9 , V_138 ) ;
T_1 V_211 = F_23 ( V_9 , V_138 ) ;
F_25 ( 1 , L_62 ,
V_138 , V_33 , F_19 ( V_9 , V_138 ) ) ;
if ( F_33 ( V_9 ) &&
F_34 ( V_9 ) <= V_33 &&
V_33 < F_96 ( 32 ) ) {
F_3 ( L_63 ,
V_33 ) ;
return - V_16 ;
}
if ( V_37 && ( V_211 != ( ( V_33 >> 12 ) & V_37 ) ) )
return - V_16 ;
V_33 = F_102 ( V_9 , V_33 ) ;
V_209 = F_85 ( V_9 ) ;
if ( F_86 ( V_9 ) &&
! F_11 ( V_9 ) &&
( ( V_33 >> 27 ) >= ( V_209 >> 11 ) ) )
V_210 = true ;
V_163 = F_92 ( V_9 , V_33 , V_210 , V_37 ) ;
V_208 = F_95 ( V_9 , V_138 , V_33 ,
V_210 , V_209 ) ;
if ( V_37 )
V_208 = ( ( V_208 >> ( 12 + F_94 ( V_37 ) ) ) << 12 ) |
( V_208 & 0xfff ) ;
if ( F_89 ( V_9 ) &&
! F_86 ( V_9 ) &&
! F_11 ( V_9 ) ) {
if ( F_90 ( V_9 ) != 1 ) {
if ( F_90 ( V_9 ) == 0x3 )
V_208 = ( ( V_208 >> 10 ) << 9 ) |
( V_208 & 0x1ff ) ;
else
V_208 = ( ( V_208 >> 7 ) << 6 ) |
( V_208 & 0x3f ) ;
} else
V_208 = ( ( V_208 >> 13 ) << 12 ) |
( V_208 & 0xfff ) ;
}
F_25 ( 1 , L_64 , V_208 ) ;
V_200 = F_101 ( V_208 , V_36 , V_163 ) ;
if ( V_200 >= 0 )
* V_207 = V_163 ;
return V_200 ;
}
static int F_104 ( struct V_8 * V_9 , unsigned V_138 ,
T_3 V_33 , int * V_207 )
{
int V_200 = - V_16 ;
int V_184 = 0 ;
T_3 V_208 , V_212 ;
T_3 V_213 , V_214 ;
T_1 V_215 , V_216 , V_129 ;
T_2 V_163 , V_217 , V_218 , V_185 , V_219 ;
T_3 V_220 = F_35 ( V_9 ) ;
T_2 V_187 = F_90 ( V_9 ) ;
T_2 V_36 = F_67 ( V_9 , V_138 ) ;
T_2 V_37 = F_21 ( V_9 , V_138 ) ;
F_8 ( V_9 -> V_12 , V_221 , & V_215 ) ;
F_8 ( V_9 -> V_12 , V_222 , & V_216 ) ;
V_219 = ( T_2 ) ( ( V_215 >> 3 ) & F_46 ( 0 ) ) ;
V_185 = ( T_2 ) ( ( V_215 >> 4 ) & 0x7 ) ;
F_25 ( 1 , L_62 ,
V_138 , V_33 , F_19 ( V_9 , V_138 ) ) ;
if ( ! ( F_18 ( V_9 , V_138 ) <= V_33 ) &&
! ( F_19 ( V_9 , V_138 ) >= V_33 ) )
return - V_16 ;
if ( F_33 ( V_9 ) &&
F_34 ( V_9 ) <= V_33 &&
V_33 < F_96 ( 32 ) ) {
F_3 ( L_63 ,
V_33 ) ;
return - V_16 ;
}
V_213 = ( T_3 ) F_85 ( V_9 ) ;
V_214 = ( V_216 >> 11 ) & 0x1FFF ;
if ( ! ( V_215 & F_46 ( 0 ) ) &&
! ( V_213 <= ( V_33 >> 27 ) &&
V_214 >= ( V_33 >> 27 ) ) )
return - V_16 ;
V_184 = ( int ) F_94 ( V_37 ) ;
if ( ! ( V_184 % 2 == 0 ) || ( V_184 > 4 ) )
return - V_16 ;
if ( V_9 -> V_14 >= 0x60 )
V_163 = F_92 ( V_9 , V_33 , false , V_37 ) ;
else
V_163 = F_91 ( V_9 , V_33 , V_37 ,
V_184 , V_185 ) ;
if ( V_163 > 3 )
return - V_16 ;
V_218 = ( T_2 ) ( V_215 >> 1 & F_46 ( 0 ) ) ;
if ( V_218 && ( V_33 >= F_96 ( 32 ) ) )
V_212 = V_220 ;
else
V_212 = V_213 << 27 ;
V_208 = V_33 - V_212 ;
if ( V_184 == 2 ) {
if ( V_187 == 0x4 )
V_208 = ( ( V_208 >> 9 ) << 8 ) |
( V_208 & 0xff ) ;
else if ( V_187 == 0x5 )
V_208 = ( ( V_208 >> 10 ) << 9 ) |
( V_208 & 0x1ff ) ;
else
return - V_16 ;
} else if ( V_184 == 4 ) {
if ( V_187 == 0x4 )
V_208 = ( ( V_208 >> 10 ) << 8 ) |
( V_208 & 0xff ) ;
else if ( V_187 == 0x5 )
V_208 = ( ( V_208 >> 11 ) << 9 ) |
( V_208 & 0x1ff ) ;
else
return - V_16 ;
}
if ( V_219 ) {
F_8 ( V_9 -> V_12 ,
V_223 + ( int ) V_163 * 4 ,
& V_129 ) ;
V_208 += ( T_3 ) ( ( V_129 >> 11 ) & 0xfff ) << 27 ;
}
F_7 ( V_9 , V_163 ) ;
F_25 ( 1 , L_64 , V_208 ) ;
V_217 = ( V_163 == 3 ) ? 1 : V_163 ;
V_200 = F_101 ( V_208 , V_36 , V_217 ) ;
if ( V_200 >= 0 )
* V_207 = V_217 ;
return V_200 ;
}
static int F_105 ( struct V_8 * V_9 ,
T_3 V_33 ,
int * V_207 )
{
int V_200 = - V_16 ;
unsigned V_138 ;
for ( V_138 = 0 ; V_138 < V_39 ; V_138 ++ ) {
if ( ! F_65 ( V_9 , V_138 ) )
continue;
if ( V_9 -> V_15 == 0x15 && V_9 -> V_14 >= 0x30 )
V_200 = F_104 ( V_9 , V_138 ,
V_33 ,
V_207 ) ;
else if ( ( F_18 ( V_9 , V_138 ) <= V_33 ) &&
( F_19 ( V_9 , V_138 ) >= V_33 ) ) {
V_200 = F_103 ( V_9 , V_138 ,
V_33 , V_207 ) ;
if ( V_200 >= 0 )
break;
}
}
return V_200 ;
}
static void F_106 ( struct V_27 * V_28 , T_3 V_33 ,
struct V_69 * V_6 )
{
struct V_8 * V_9 = V_28 -> V_30 ;
F_42 ( V_33 , V_6 ) ;
V_6 -> V_43 = F_105 ( V_9 , V_33 , & V_6 -> V_163 ) ;
if ( V_6 -> V_43 < 0 ) {
V_6 -> V_158 = V_160 ;
return;
}
if ( F_11 ( V_9 ) )
V_6 -> V_163 = F_71 ( V_28 , V_6 -> V_164 ) ;
}
static void F_49 ( struct V_8 * V_9 , T_2 V_224 )
{
int V_225 , V_226 , V_227 ;
T_1 * V_228 = V_224 ? V_9 -> V_53 [ 1 ] . V_54 : V_9 -> V_53 [ 0 ] . V_54 ;
T_1 V_174 = V_224 ? V_9 -> V_175 : V_9 -> V_176 ;
if ( V_9 -> V_15 == 0xf ) {
if ( V_9 -> V_51 < V_52 )
return;
else
F_68 ( V_224 != 0 ) ;
}
if ( V_9 -> V_15 == 0x10 ) {
V_174 = ( V_224 && ! F_11 ( V_9 ) ) ? V_9 -> V_175
: V_9 -> V_176 ;
V_228 = ( V_224 && ! F_11 ( V_9 ) ) ?
V_9 -> V_53 [ 1 ] . V_54 :
V_9 -> V_53 [ 0 ] . V_54 ;
} else if ( V_224 ) {
V_174 = V_9 -> V_176 ;
V_228 = V_9 -> V_53 [ 1 ] . V_54 ;
}
F_25 ( 1 , L_65 ,
V_224 , V_174 ) ;
F_107 ( V_229 , V_230 , L_66 , V_224 ) ;
for ( V_225 = 0 ; V_225 < 4 ; V_225 ++ ) {
V_226 = 0 ;
if ( V_228 [ V_225 * 2 ] & V_231 )
V_226 = V_9 -> V_232 -> V_233 ( V_9 , V_224 ,
F_76 ( V_225 , V_174 ) ,
V_225 ) ;
V_227 = 0 ;
if ( V_228 [ V_225 * 2 + 1 ] & V_231 )
V_227 = V_9 -> V_232 -> V_233 ( V_9 , V_224 ,
F_76 ( V_225 , V_174 ) ,
V_225 ) ;
F_50 ( V_230 L_67 ,
V_225 * 2 , V_226 ,
V_225 * 2 + 1 , V_227 ) ;
}
}
static int F_108 ( T_4 V_164 , const T_4 * V_234 , unsigned V_235 ,
unsigned V_236 )
{
unsigned int V_21 , V_237 ;
for ( V_237 = 0 ; V_237 < V_235 / V_236 ; V_237 ++ ) {
T_4 V_238 = V_164 ;
unsigned V_239 = V_237 * V_236 ;
unsigned V_240 = ( V_237 + 1 ) * V_236 ;
for ( V_21 = 1 ; V_21 < ( 1U << 16 ) ; V_21 <<= 1 ) {
if ( V_239 < V_240 && V_234 [ V_239 ] & V_21 ) {
T_4 V_241 = V_234 [ V_239 ++ ] ;
if ( V_238 & V_21 ) {
V_238 ^= V_241 ;
if ( ! V_238 )
return V_237 ;
}
} else if ( V_238 & V_21 )
break;
}
}
F_25 ( 0 , L_68 , V_164 ) ;
return - 1 ;
}
static int F_109 ( int V_237 , int V_242 )
{
if ( V_242 == 4 )
switch ( V_237 ) {
case 0x20 :
case 0x21 :
return 0 ;
break;
case 0x22 :
case 0x23 :
return 1 ;
break;
default:
return V_237 >> 4 ;
break;
}
else
switch ( V_237 ) {
case 0x10 :
F_55 ( 1 , V_116 L_69 ,
V_237 ) ;
return - 1 ;
break;
case 0x11 :
return 0 ;
break;
case 0x12 :
return 1 ;
break;
default:
return V_237 >> 3 ;
break;
}
return - 1 ;
}
static int F_71 ( struct V_27 * V_28 , T_4 V_164 )
{
struct V_8 * V_9 = V_28 -> V_30 ;
int V_237 = - 1 ;
if ( V_9 -> V_89 == 8 )
V_237 = F_108 ( V_164 , V_243 ,
F_13 ( V_243 ) ,
V_9 -> V_89 ) ;
else if ( V_9 -> V_89 == 4 )
V_237 = F_108 ( V_164 , V_244 ,
F_13 ( V_244 ) ,
V_9 -> V_89 ) ;
else {
F_3 ( L_70 , V_9 -> V_89 ) ;
return V_237 ;
}
return F_109 ( V_237 , V_9 -> V_89 ) ;
}
static void F_110 ( struct V_27 * V_28 , struct V_69 * V_6 ,
T_2 V_245 )
{
enum V_246 V_247 ;
const char * string ;
if ( V_245 == 2 )
V_247 = V_248 ;
else if ( V_245 == 1 )
V_247 = V_249 ;
else {
F_55 ( 1 , L_71 ) ;
return;
}
switch ( V_6 -> V_158 ) {
case V_250 :
string = L_72 ;
break;
case V_159 :
string = L_73 ;
break;
case V_160 :
string = L_74 ;
break;
case V_165 :
string = L_75 ;
break;
default:
string = L_76 ;
break;
}
F_111 ( V_247 , V_28 , 1 ,
V_6 -> V_70 , V_6 -> V_3 , V_6 -> V_164 ,
V_6 -> V_43 , V_6 -> V_163 , - 1 ,
string , L_72 ) ;
}
static inline void F_112 ( int V_36 , struct V_121 * V_122 )
{
struct V_27 * V_28 ;
struct V_8 * V_9 ;
T_2 V_245 = ( V_122 -> V_251 >> 45 ) & 0x3 ;
T_2 V_252 = F_113 ( V_122 -> V_251 , 0x1f ) ;
T_4 V_253 = F_114 ( V_122 -> V_251 ) ;
T_3 V_33 ;
struct V_69 V_6 ;
V_28 = F_24 ( V_36 ) ;
if ( ! V_28 )
return;
V_9 = V_28 -> V_30 ;
if ( F_115 ( V_253 ) == V_254 )
return;
if ( V_252 && V_252 != V_255 )
return;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_33 = F_57 ( V_9 , V_122 ) ;
if ( V_245 == 2 )
V_6 . V_164 = F_116 ( V_122 -> V_251 ) ;
V_9 -> V_232 -> V_256 ( V_28 , V_33 , & V_6 ) ;
F_110 ( V_28 , & V_6 , V_245 ) ;
}
static int F_117 ( struct V_8 * V_9 , T_4 V_257 , T_4 V_258 )
{
V_9 -> V_12 = F_60 ( V_9 -> V_25 -> V_132 , V_257 , V_9 -> V_25 ) ;
if ( ! V_9 -> V_12 ) {
F_118 ( L_77
L_78 ,
V_259 , V_257 ) ;
return - V_260 ;
}
V_9 -> V_17 = F_60 ( V_9 -> V_25 -> V_132 , V_258 , V_9 -> V_25 ) ;
if ( ! V_9 -> V_17 ) {
F_69 ( V_9 -> V_12 ) ;
V_9 -> V_12 = NULL ;
F_118 ( L_79
L_78 ,
V_259 , V_258 ) ;
return - V_260 ;
}
F_25 ( 1 , L_80 , F_119 ( V_9 -> V_12 ) ) ;
F_25 ( 1 , L_81 , F_119 ( V_9 -> V_17 ) ) ;
F_25 ( 1 , L_82 , F_119 ( V_9 -> V_25 ) ) ;
return 0 ;
}
static void F_120 ( struct V_8 * V_9 )
{
F_69 ( V_9 -> V_12 ) ;
F_69 ( V_9 -> V_17 ) ;
}
static void F_121 ( struct V_8 * V_9 )
{
unsigned V_138 ;
T_3 V_261 ;
T_1 V_129 ;
F_122 ( V_262 , V_9 -> V_263 ) ;
F_25 ( 0 , L_83 , V_9 -> V_263 ) ;
F_122 ( V_264 , V_261 ) ;
if ( V_261 & ( 1U << 21 ) ) {
F_122 ( V_265 , V_9 -> V_266 ) ;
F_25 ( 0 , L_84 , V_9 -> V_266 ) ;
} else
F_25 ( 0 , L_85 ) ;
F_8 ( V_9 -> V_25 , V_267 , & V_9 -> V_83 ) ;
F_84 ( V_9 ) ;
for ( V_138 = 0 ; V_138 < V_39 ; V_138 ++ ) {
T_2 V_268 ;
F_64 ( V_9 , V_138 ) ;
V_268 = F_65 ( V_9 , V_138 ) ;
if ( ! V_268 )
continue;
F_25 ( 1 , L_86 ,
V_138 ,
F_18 ( V_9 , V_138 ) ,
F_19 ( V_9 , V_138 ) ) ;
F_25 ( 1 , L_87 ,
F_21 ( V_9 , V_138 ) ? L_88 : L_89 ,
( V_268 & 0x1 ) ? L_90 : L_91 ,
( V_268 & 0x2 ) ? L_92 : L_91 ,
F_23 ( V_9 , V_138 ) ,
F_67 ( V_9 , V_138 ) ) ;
}
F_52 ( V_9 ) ;
F_8 ( V_9 -> V_12 , V_269 , & V_9 -> V_88 ) ;
F_10 ( V_9 , 0 , V_270 , & V_9 -> V_176 ) ;
F_8 ( V_9 -> V_25 , V_271 , & V_9 -> V_87 ) ;
F_10 ( V_9 , 0 , V_272 , & V_9 -> V_76 ) ;
F_10 ( V_9 , 0 , V_273 , & V_9 -> V_108 ) ;
if ( ! F_11 ( V_9 ) ) {
F_10 ( V_9 , 1 , V_272 , & V_9 -> V_90 ) ;
F_10 ( V_9 , 1 , V_273 , & V_9 -> V_179 ) ;
}
V_9 -> V_89 = 4 ;
F_54 ( V_9 ) ;
F_25 ( 1 , L_93 , V_274 [ V_9 -> V_80 ] ) ;
if ( V_9 -> V_15 >= 0x10 ) {
F_8 ( V_9 -> V_25 , V_275 , & V_129 ) ;
if ( V_9 -> V_15 != 0x16 )
F_10 ( V_9 , 1 , V_270 , & V_9 -> V_175 ) ;
if ( ( V_9 -> V_15 > 0x10 || V_9 -> V_14 > 7 ) && V_129 & F_46 ( 25 ) )
V_9 -> V_89 = 8 ;
}
F_48 ( V_9 ) ;
}
static T_1 F_123 ( struct V_8 * V_9 , T_2 V_10 , int V_276 )
{
T_1 V_168 , V_277 ;
T_1 V_174 = V_10 ? V_9 -> V_175 : V_9 -> V_176 ;
V_168 = F_76 ( V_276 / 2 , V_174 ) ;
V_277 = V_9 -> V_232 -> V_233 ( V_9 , V_10 , V_168 , ( V_276 / 2 ) )
<< ( 20 - V_71 ) ;
F_25 ( 0 , L_94 ,
V_276 , V_10 , V_168 ) ;
F_25 ( 0 , L_95 , V_277 ) ;
return V_277 ;
}
static int F_124 ( struct V_27 * V_28 )
{
struct V_8 * V_9 = V_28 -> V_30 ;
struct V_278 * V_43 ;
struct V_279 * V_225 ;
enum V_280 V_281 ;
int V_21 , V_172 , V_282 = 1 ;
int V_277 = 0 ;
T_1 V_4 ;
F_8 ( V_9 -> V_25 , V_283 , & V_4 ) ;
V_9 -> V_161 = V_4 ;
F_25 ( 0 , L_96 ,
V_9 -> V_57 , V_4 ,
! ! ( V_4 & V_162 ) , ! ! ( V_4 & V_284 ) ) ;
F_29 (i, 0 , pvt) {
bool V_285 = ! ! F_30 ( V_21 , 0 , V_9 ) ;
bool V_286 = false ;
if ( V_9 -> V_15 != 0xf )
V_286 = ! ! F_30 ( V_21 , 1 , V_9 ) ;
if ( ! V_285 && ! V_286 )
continue;
V_43 = V_28 -> V_287 [ V_21 ] ;
V_282 = 0 ;
F_25 ( 1 , L_97 ,
V_9 -> V_57 , V_21 ) ;
if ( V_285 ) {
V_277 = F_123 ( V_9 , 0 , V_21 ) ;
V_43 -> V_173 [ 0 ] -> V_225 -> V_277 = V_277 ;
}
if ( V_9 -> V_15 != 0xf && V_286 ) {
int V_288 = F_123 ( V_9 , 1 , V_21 ) ;
V_43 -> V_173 [ 1 ] -> V_225 -> V_277 = V_288 ;
V_277 += V_288 ;
}
F_25 ( 1 , L_98 , V_21 , V_277 ) ;
if ( V_9 -> V_161 & V_284 )
V_281 = ( V_9 -> V_161 & V_162 ) ?
V_289 : V_290 ;
else
V_281 = V_291 ;
for ( V_172 = 0 ; V_172 < V_9 -> V_292 ; V_172 ++ ) {
V_225 = V_43 -> V_173 [ V_172 ] -> V_225 ;
V_225 -> V_293 = V_9 -> V_80 ;
V_225 -> V_281 = V_281 ;
}
}
return V_282 ;
}
static void F_125 ( struct V_294 * V_45 , T_4 V_34 )
{
int V_295 ;
F_126 (cpu)
if ( F_58 ( V_295 ) == V_34 )
F_127 ( V_295 , V_45 ) ;
}
static bool F_128 ( T_4 V_34 )
{
T_5 V_45 ;
int V_295 , V_296 ;
bool V_64 = false ;
if ( ! F_129 ( & V_45 , V_297 ) ) {
F_3 ( L_99 , V_42 ) ;
return false ;
}
F_125 ( V_45 , V_34 ) ;
F_130 ( V_45 , V_298 , V_299 ) ;
F_131 (cpu, mask) {
struct V_300 * V_11 = F_132 ( V_299 , V_295 ) ;
V_296 = V_11 -> V_301 & V_302 ;
F_25 ( 0 , L_100 ,
V_295 , V_11 -> V_303 ,
( V_296 ? L_25 : L_26 ) ) ;
if ( ! V_296 )
goto V_304;
}
V_64 = true ;
V_304:
F_133 ( V_45 ) ;
return V_64 ;
}
static int F_134 ( struct V_305 * V_238 , T_4 V_34 , bool V_306 )
{
T_5 V_307 ;
int V_295 ;
if ( ! F_129 ( & V_307 , V_297 ) ) {
F_3 ( L_101 , V_42 ) ;
return false ;
}
F_125 ( V_307 , V_34 ) ;
F_130 ( V_307 , V_298 , V_299 ) ;
F_131 (cpu, cmask) {
struct V_300 * V_11 = F_132 ( V_299 , V_295 ) ;
if ( V_306 ) {
if ( V_11 -> V_301 & V_302 )
V_238 -> V_308 . V_309 = 1 ;
V_11 -> V_301 |= V_302 ;
} else {
if ( ! V_238 -> V_308 . V_309 )
V_11 -> V_301 &= ~ V_302 ;
}
}
F_135 ( V_307 , V_298 , V_299 ) ;
F_133 ( V_307 ) ;
return 0 ;
}
static bool F_136 ( struct V_305 * V_238 , T_4 V_34 ,
struct V_1 * V_25 )
{
bool V_64 = true ;
T_1 V_310 , V_45 = 0x3 ;
if ( F_134 ( V_238 , V_34 , V_311 ) ) {
F_3 ( L_102 ) ;
return false ;
}
F_8 ( V_25 , V_312 , & V_310 ) ;
V_238 -> V_313 = V_310 & V_45 ;
V_238 -> V_314 = true ;
V_310 |= V_45 ;
F_9 ( V_25 , V_312 , V_310 ) ;
F_8 ( V_25 , V_283 , & V_310 ) ;
F_25 ( 0 , L_103 ,
V_34 , V_310 , ! ! ( V_310 & V_284 ) ) ;
if ( ! ( V_310 & V_284 ) ) {
F_3 ( L_104 ) ;
V_238 -> V_308 . V_315 = 0 ;
V_310 |= V_284 ;
F_9 ( V_25 , V_283 , V_310 ) ;
F_8 ( V_25 , V_283 , & V_310 ) ;
if ( ! ( V_310 & V_284 ) ) {
F_3 ( L_105
L_106 ) ;
V_64 = false ;
} else {
F_50 ( L_107 ) ;
}
} else {
V_238 -> V_308 . V_315 = 1 ;
}
F_25 ( 0 , L_108 ,
V_34 , V_310 , ! ! ( V_310 & V_284 ) ) ;
return V_64 ;
}
static void F_137 ( struct V_305 * V_238 , T_4 V_34 ,
struct V_1 * V_25 )
{
T_1 V_310 , V_45 = 0x3 ;
if ( ! V_238 -> V_314 )
return;
F_8 ( V_25 , V_312 , & V_310 ) ;
V_310 &= ~ V_45 ;
V_310 |= V_238 -> V_313 ;
F_9 ( V_25 , V_312 , V_310 ) ;
if ( ! V_238 -> V_308 . V_315 ) {
F_8 ( V_25 , V_283 , & V_310 ) ;
V_310 &= ~ V_284 ;
F_9 ( V_25 , V_283 , V_310 ) ;
}
if ( F_134 ( V_238 , V_34 , V_316 ) )
F_3 ( L_109 ) ;
}
static bool F_138 ( struct V_1 * V_25 , T_4 V_34 )
{
T_1 V_310 ;
T_2 V_317 = 0 ;
bool V_318 = false ;
F_8 ( V_25 , V_283 , & V_310 ) ;
V_317 = ! ! ( V_310 & V_284 ) ;
F_50 ( L_110 , ( V_317 ? L_25 : L_26 ) ) ;
V_318 = F_128 ( V_34 ) ;
if ( ! V_318 )
F_139 ( L_111
L_112 ,
V_298 , V_34 ) ;
if ( ! V_317 || ! V_318 ) {
F_139 ( L_113 , V_319 ) ;
return false ;
}
return true ;
}
static void F_140 ( struct V_27 * V_28 ,
struct V_320 * V_15 )
{
struct V_8 * V_9 = V_28 -> V_30 ;
V_28 -> V_321 = V_322 | V_323 ;
V_28 -> V_324 = V_75 ;
if ( V_9 -> V_83 & V_85 )
V_28 -> V_324 |= V_77 ;
if ( V_9 -> V_83 & V_86 )
V_28 -> V_324 |= V_325 ;
V_28 -> V_74 = F_45 ( V_9 ) ;
V_28 -> V_326 = V_327 ;
V_28 -> V_328 = V_329 ;
V_28 -> V_330 = V_15 -> V_330 ;
V_28 -> V_331 = F_119 ( V_9 -> V_17 ) ;
V_28 -> V_332 = NULL ;
V_28 -> V_333 = F_15 ;
V_28 -> V_334 = F_16 ;
}
static struct V_320 * F_141 ( struct V_8 * V_9 )
{
struct V_320 * V_335 = NULL ;
V_9 -> V_51 = V_336 . V_337 >> 4 ;
V_9 -> V_205 = V_336 . V_338 ;
V_9 -> V_14 = V_336 . V_337 ;
V_9 -> V_15 = V_336 . V_339 ;
switch ( V_9 -> V_15 ) {
case 0xf :
V_335 = & V_340 [ V_341 ] ;
V_9 -> V_232 = & V_340 [ V_341 ] . V_232 ;
break;
case 0x10 :
V_335 = & V_340 [ V_342 ] ;
V_9 -> V_232 = & V_340 [ V_342 ] . V_232 ;
break;
case 0x15 :
if ( V_9 -> V_14 == 0x30 ) {
V_335 = & V_340 [ V_343 ] ;
V_9 -> V_232 = & V_340 [ V_343 ] . V_232 ;
break;
} else if ( V_9 -> V_14 == 0x60 ) {
V_335 = & V_340 [ V_344 ] ;
V_9 -> V_232 = & V_340 [ V_344 ] . V_232 ;
break;
}
V_335 = & V_340 [ V_345 ] ;
V_9 -> V_232 = & V_340 [ V_345 ] . V_232 ;
break;
case 0x16 :
if ( V_9 -> V_14 == 0x30 ) {
V_335 = & V_340 [ V_346 ] ;
V_9 -> V_232 = & V_340 [ V_346 ] . V_232 ;
break;
}
V_335 = & V_340 [ V_347 ] ;
V_9 -> V_232 = & V_340 [ V_347 ] . V_232 ;
break;
default:
F_118 ( L_114 ) ;
return NULL ;
}
F_50 ( L_115 , V_335 -> V_330 ,
( V_9 -> V_15 == 0xf ?
( V_9 -> V_51 >= V_52 ? L_116
: L_117 )
: L_72 ) , V_9 -> V_57 ) ;
return V_335 ;
}
static int F_142 ( unsigned int V_34 )
{
struct V_1 * V_25 = F_66 ( V_34 ) -> V_156 ;
struct V_320 * V_335 = NULL ;
struct V_27 * V_28 = NULL ;
struct V_348 V_349 [ 2 ] ;
struct V_8 * V_9 = NULL ;
int V_6 = 0 , V_64 ;
V_64 = - V_350 ;
V_9 = F_143 ( sizeof( struct V_8 ) , V_297 ) ;
if ( ! V_9 )
goto V_351;
V_9 -> V_57 = V_34 ;
V_9 -> V_25 = V_25 ;
V_64 = - V_16 ;
V_335 = F_141 ( V_9 ) ;
if ( ! V_335 )
goto V_352;
V_64 = - V_260 ;
V_6 = F_117 ( V_9 , V_335 -> V_257 , V_335 -> V_258 ) ;
if ( V_6 )
goto V_352;
F_121 ( V_9 ) ;
V_64 = - V_16 ;
V_9 -> V_292 = V_9 -> V_232 -> V_353 ( V_9 ) ;
if ( V_9 -> V_292 < 0 )
goto V_354;
V_64 = - V_350 ;
V_349 [ 0 ] . type = V_355 ;
V_349 [ 0 ] . V_356 = V_9 -> V_53 [ 0 ] . V_91 ;
V_349 [ 0 ] . V_357 = true ;
V_349 [ 1 ] . type = V_358 ;
V_349 [ 1 ] . V_356 = 2 ;
V_349 [ 1 ] . V_357 = false ;
V_28 = F_144 ( V_34 , F_13 ( V_349 ) , V_349 , 0 ) ;
if ( ! V_28 )
goto V_354;
V_28 -> V_30 = V_9 ;
V_28 -> V_2 = & V_9 -> V_25 -> V_135 ;
F_140 ( V_28 , V_335 ) ;
if ( F_124 ( V_28 ) )
V_28 -> V_74 = V_75 ;
V_64 = - V_260 ;
if ( F_145 ( V_28 , V_359 ) ) {
F_25 ( 1 , L_118 ) ;
goto V_360;
}
if ( V_361 )
F_146 ( true ) ;
F_147 ( F_112 ) ;
return 0 ;
V_360:
F_148 ( V_28 ) ;
V_354:
F_120 ( V_9 ) ;
V_352:
F_149 ( V_9 ) ;
V_351:
return V_64 ;
}
static int F_150 ( unsigned int V_34 )
{
struct V_1 * V_25 = F_66 ( V_34 ) -> V_156 ;
struct V_305 * V_238 ;
int V_64 ;
V_64 = - V_350 ;
V_238 = F_143 ( sizeof( struct V_305 ) , V_297 ) ;
if ( ! V_238 )
goto V_362;
V_363 [ V_34 ] = V_238 ;
if ( ! F_138 ( V_25 , V_34 ) ) {
V_64 = - V_260 ;
if ( ! V_364 )
goto V_365;
F_3 ( L_119 ) ;
if ( ! F_136 ( V_238 , V_34 , V_25 ) )
goto V_365;
}
V_64 = F_142 ( V_34 ) ;
if ( V_64 < 0 ) {
F_118 ( L_120 , V_34 ) ;
F_137 ( V_238 , V_34 , V_25 ) ;
}
return V_64 ;
V_365:
F_149 ( V_238 ) ;
V_363 [ V_34 ] = NULL ;
V_362:
return V_64 ;
}
static void F_151 ( unsigned int V_34 )
{
struct V_1 * V_25 = F_66 ( V_34 ) -> V_156 ;
struct V_305 * V_238 = V_363 [ V_34 ] ;
struct V_27 * V_28 ;
struct V_8 * V_9 ;
V_28 = F_152 ( & V_25 -> V_135 ) ;
F_68 ( ! V_28 ) ;
V_28 = F_153 ( & V_25 -> V_135 ) ;
if ( ! V_28 )
return;
V_9 = V_28 -> V_30 ;
F_137 ( V_238 , V_34 , V_25 ) ;
F_120 ( V_9 ) ;
F_146 ( false ) ;
F_154 ( F_112 ) ;
F_149 ( V_363 [ V_34 ] ) ;
V_363 [ V_34 ] = NULL ;
V_28 -> V_30 = NULL ;
F_149 ( V_9 ) ;
F_148 ( V_28 ) ;
}
static void F_155 ( void )
{
struct V_27 * V_28 ;
struct V_8 * V_9 ;
if ( V_366 )
return;
V_28 = F_24 ( 0 ) ;
if ( ! V_28 )
return;
V_9 = V_28 -> V_30 ;
V_366 = F_156 ( & V_9 -> V_17 -> V_135 , V_327 ) ;
if ( ! V_366 ) {
F_157 ( L_121 , V_42 ) ;
F_157 ( L_122 , V_42 ) ;
}
}
static int T_6 F_158 ( void )
{
int V_6 = - V_260 ;
int V_21 ;
if ( F_159 () < 0 )
goto V_351;
F_160 () ;
V_6 = - V_350 ;
V_363 = F_143 ( F_161 () * sizeof( V_363 [ 0 ] ) , V_297 ) ;
if ( ! V_363 )
goto V_352;
V_299 = F_162 () ;
if ( ! V_299 )
goto V_352;
for ( V_21 = 0 ; V_21 < F_161 () ; V_21 ++ )
if ( F_150 ( V_21 ) ) {
while ( -- V_21 >= 0 )
F_151 ( V_21 ) ;
goto V_367;
}
F_155 () ;
#ifdef F_163
F_118 ( L_123 , V_327 ) ;
#endif
F_164 ( V_368 L_124 , V_329 ) ;
return 0 ;
V_367:
F_165 ( V_299 ) ;
V_299 = NULL ;
V_352:
F_149 ( V_363 ) ;
V_363 = NULL ;
V_351:
return V_6 ;
}
static void T_7 F_166 ( void )
{
int V_21 ;
if ( V_366 )
F_167 ( V_366 ) ;
for ( V_21 = 0 ; V_21 < F_161 () ; V_21 ++ )
F_151 ( V_21 ) ;
F_149 ( V_363 ) ;
V_363 = NULL ;
F_165 ( V_299 ) ;
V_299 = NULL ;
}

static inline short F_1 ( short V_1 )
{
return ( V_1 >> 4 ) & 0xfff ;
}
static void F_2 ( short * V_2 , unsigned int V_3 )
{
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )
V_2 [ V_4 ] = F_1 ( V_2 [ V_4 ] ) ;
}
static int F_3 ( struct V_5 * V_6 ,
struct V_7 * V_8 , struct V_9 * V_10 )
{
const struct V_11 * V_12 = F_4 ( V_6 ) ;
unsigned int V_13 = 0 , V_14 , V_4 ;
V_14 = V_10 -> V_15 ;
V_10 -> V_15 &= V_16 | V_17 ;
if ( ! V_10 -> V_15 || V_14 != V_10 -> V_15 )
V_13 ++ ;
V_14 = V_10 -> V_18 ;
V_10 -> V_18 &= V_19 ;
if ( ! V_10 -> V_18 || V_14 != V_10 -> V_18 )
V_13 ++ ;
V_14 = V_10 -> V_20 ;
V_10 -> V_20 &= V_21 | V_17 ;
if ( ! V_10 -> V_20 || V_14 != V_10 -> V_20 )
V_13 ++ ;
V_14 = V_10 -> V_22 ;
V_10 -> V_22 &= V_23 ;
if ( ! V_10 -> V_22 || V_14 != V_10 -> V_22 )
V_13 ++ ;
V_14 = V_10 -> V_24 ;
V_10 -> V_24 &= V_23 | V_25 ;
if ( ! V_10 -> V_24 || V_14 != V_10 -> V_24 )
V_13 ++ ;
if ( V_13 )
return 1 ;
if ( V_10 -> V_24 != V_23 && V_10 -> V_24 != V_25 )
V_13 ++ ;
if ( V_10 -> V_15 != V_16 && V_10 -> V_15 != V_17 )
V_13 ++ ;
if ( V_10 -> V_20 != V_21 && V_10 -> V_20 != V_17 )
V_13 ++ ;
if ( V_13 )
return 2 ;
if ( V_10 -> V_26 != 0 ) {
V_10 -> V_26 = 0 ;
V_13 ++ ;
}
if ( V_10 -> V_18 == V_19 ) {
if ( V_10 -> V_27 != 0 ) {
V_10 -> V_27 = 0 ;
V_13 ++ ;
}
}
if ( V_10 -> V_20 == V_21 ) {
if ( V_10 -> V_28 < V_12 -> V_29 ) {
V_10 -> V_28 = V_12 -> V_29 ;
V_13 ++ ;
}
}
if ( V_10 -> V_30 != V_10 -> V_31 ) {
V_10 -> V_30 = V_10 -> V_31 ;
V_13 ++ ;
}
if ( V_10 -> V_24 == V_23 ) {
} else {
if ( V_10 -> V_32 != 0 ) {
V_10 -> V_32 = 0 ;
V_13 ++ ;
}
}
if ( V_13 )
return 3 ;
if ( V_10 -> V_20 == V_21 ) {
V_14 = V_10 -> V_28 ;
F_5 ( V_33 ,
& ( V_34 -> V_35 ) ,
& ( V_34 -> V_36 ) ,
& ( V_10 -> V_28 ) ,
V_10 -> V_37 & V_38 ) ;
if ( V_14 != V_10 -> V_28 )
V_13 ++ ;
}
if ( V_13 )
return 4 ;
if ( V_10 -> V_39 && V_10 -> V_31 > 1 ) {
for ( V_4 = 0 ; V_4 < V_10 -> V_31 ; V_4 ++ ) {
if ( ( V_4 % 2 ) != ( F_6 ( V_10 -> V_39 [ V_4 ] ) % 2 ) ) {
F_7 ( V_6 , L_1
L_2 ) ;
V_13 ++ ;
}
}
if ( ( V_10 -> V_31 % 2 ) != 0 ) {
F_7 ( V_6 ,
L_3 ) ;
V_13 ++ ;
}
}
if ( V_13 )
return 5 ;
return 0 ;
}
static unsigned int F_8 ( struct V_5 * V_6 ,
unsigned int V_40 , int V_41 )
{
F_5 ( V_33 , & ( V_34 -> V_35 ) ,
& ( V_34 -> V_36 ) , & V_40 ,
V_41 & V_38 ) ;
F_9 ( V_6 -> V_42 + V_43 , 0 , 1 , V_34 -> V_35 ,
2 ) ;
F_9 ( V_6 -> V_42 + V_43 , 0 , 2 , V_34 -> V_36 ,
2 ) ;
return V_40 ;
}
static int F_10 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_44 * V_45 = V_8 -> V_45 ;
struct V_9 * V_10 = & V_45 -> V_10 ;
unsigned int V_46 , V_4 ;
if ( V_6 -> V_47 == 0 ) {
F_7 ( V_6 , L_4 ) ;
return - 1 ;
}
V_34 -> V_48 &= ~ V_49 & ~ V_50 ;
F_11 ( V_34 -> V_48 , V_6 -> V_42 + V_51 ) ;
V_34 -> V_52 = 0 ;
F_9 ( V_6 -> V_42 + V_53 , 0 , 1 , 0 , 2 ) ;
V_34 -> V_54 =
F_12 ( V_6 -> V_42 + V_53 , 0 , 1 ) ;
for ( V_4 = 0 ; V_4 < V_10 -> V_31 ; V_4 ++ ) {
F_11 ( V_4 , V_6 -> V_42 + V_55 ) ;
V_46 =
F_13 ( F_6 ( V_10 -> V_39 [ V_4 ] ) ) |
F_14 ( F_15 ( V_10 -> V_39 [ V_4 ] ) ) ;
F_11 ( V_46 , V_6 -> V_42 + V_56 ) ;
}
V_10 -> V_28 =
F_8 ( V_6 , V_10 -> V_28 ,
V_10 -> V_37 & V_38 ) ;
V_46 = 0 ;
if ( V_10 -> V_15 == V_17 && V_10 -> V_20 != V_17 )
V_46 |= V_57 ;
F_11 ( V_46 , V_6 -> V_42 + V_58 ) ;
F_11 ( 0 , V_6 -> V_42 + V_59 ) ;
V_34 -> V_48 &= ~ V_50 ;
if ( V_10 -> V_20 == V_21 )
V_34 -> V_48 |= V_60 ;
else
V_34 -> V_48 |= V_61 ;
V_34 -> V_48 |= V_49 ;
F_11 ( V_34 -> V_48 , V_6 -> V_42 + V_51 ) ;
return 0 ;
}
static int F_16 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
V_34 -> V_48 &= ~ V_49 & ~ V_50 ;
F_11 ( V_34 -> V_48 , V_6 -> V_42 + V_51 ) ;
return 0 ;
}
static int F_17 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_62 * V_63 , unsigned int * V_1 )
{
int V_4 , V_64 ;
int V_46 ;
const int V_65 = 1000 ;
V_34 -> V_48 &= ~ V_49 & ~ V_50 ;
F_11 ( V_34 -> V_48 , V_6 -> V_42 + V_51 ) ;
F_11 ( 0 , V_6 -> V_42 + V_55 ) ;
V_46 =
F_13 ( F_6 ( V_63 -> V_66 ) ) | F_14 ( F_15 ( V_63 -> V_66 ) ) ;
F_11 ( V_46 , V_6 -> V_42 + V_56 ) ;
for ( V_64 = 0 ; V_64 < V_63 -> V_64 ; V_64 ++ ) {
F_11 ( 0 , V_6 -> V_42 + V_59 ) ;
F_11 ( 0 , V_6 -> V_42 ) ;
for ( V_4 = 0 ; V_4 < V_65 ; V_4 ++ ) {
if ( F_18 ( V_6 -> V_42 + V_58 ) & V_67 )
break;
}
if ( V_4 == V_65 ) {
F_7 ( V_6 , L_5 ) ;
return - V_68 ;
}
V_1 [ V_64 ] = F_1 ( F_19 ( V_6 -> V_42 ) ) ;
}
return V_64 ;
}
static int F_20 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_62 * V_63 , unsigned int * V_1 )
{
unsigned int V_69 ;
V_69 = F_18 ( V_6 -> V_42 + V_70 ) & 0xf ;
V_1 [ 1 ] = V_69 ;
V_1 [ 0 ] = 0 ;
return V_63 -> V_64 ;
}
static int F_21 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_62 * V_63 , unsigned int * V_1 )
{
unsigned int V_71 ;
V_1 [ 0 ] &= 0xf ;
V_71 = V_34 -> V_72 ;
V_71 &= ~ V_1 [ 0 ] ;
V_71 |= V_1 [ 0 ] & V_1 [ 1 ] ;
V_34 -> V_72 = V_71 ;
V_1 [ 1 ] = V_71 ;
F_11 ( V_34 -> V_72 , V_6 -> V_42 + V_70 ) ;
return V_63 -> V_64 ;
}
static void F_22 ( struct V_5 * V_6 , unsigned int V_73 )
{
struct V_7 * V_8 ;
struct V_44 * V_45 ;
struct V_9 * V_10 ;
T_1 V_74 ;
T_1 V_75 ;
V_8 = V_6 -> V_76 ;
V_45 = V_8 -> V_45 ;
V_45 -> V_77 = 0 ;
V_10 = & V_45 -> V_10 ;
V_75 = F_12 ( V_6 -> V_42 + V_53 , 0 , 1 ) ;
if ( V_34 -> V_52 == 0 && V_75 == V_34 -> V_54 ) {
V_74 = 0 ;
} else {
V_74 = - V_75 - V_34 -> V_52 ;
}
if ( V_10 -> V_24 == V_23 ) {
if ( V_74 > V_10 -> V_32 * V_10 -> V_31 )
V_74 = V_10 -> V_32 * V_10 -> V_31 ;
}
if ( V_74 > V_78 )
V_74 = V_78 ;
F_23 ( V_6 -> V_42 , V_34 -> V_79 , V_74 ) ;
F_2 ( V_34 -> V_79 , V_74 ) ;
F_24 ( V_8 , V_34 -> V_79 ,
V_74 * sizeof( short ) ) ;
V_34 -> V_52 += V_74 ;
if ( V_10 -> V_24 == V_23 ) {
if ( V_34 -> V_52 >= V_10 -> V_32 * V_10 -> V_31 ) {
F_16 ( V_6 , V_8 ) ;
V_45 -> V_77 |= V_80 ;
}
}
if ( V_73 & V_81 ) {
F_16 ( V_6 , V_8 ) ;
V_45 -> V_77 |= V_80 | V_82 ;
F_7 ( V_6 , L_6 ) ;
}
F_25 ( V_6 , V_8 ) ;
}
static int F_26 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
unsigned long V_37 ;
unsigned int V_73 ;
F_27 ( & V_6 -> V_83 , V_37 ) ;
V_73 = F_18 ( V_6 -> V_42 + V_58 ) ;
F_22 ( V_6 , V_73 ) ;
F_28 ( & V_6 -> V_83 , V_37 ) ;
return V_8 -> V_45 -> V_84 - V_8 -> V_45 -> V_85 ;
}
static T_2 F_29 ( int V_47 , void * V_86 )
{
int V_73 ;
struct V_5 * V_6 = V_86 ;
if ( V_6 -> V_87 == 0 ) {
F_7 ( V_6 , L_7 ) ;
return V_88 ;
}
F_30 ( & V_6 -> V_83 ) ;
V_73 = F_18 ( V_6 -> V_42 + V_58 ) ;
if ( ( V_73 & ( V_67 | V_81 ) ) == 0 ) {
F_7 ( V_6 , L_8 ) ;
F_31 ( & V_6 -> V_83 ) ;
return V_89 ;
}
F_22 ( V_6 , V_73 ) ;
F_11 ( 0 , V_6 -> V_42 + V_59 ) ;
F_31 ( & V_6 -> V_83 ) ;
return V_88 ;
}
static int F_32 ( unsigned int V_47 )
{
int V_90 ;
switch ( V_47 ) {
case 10 :
V_90 = 0x0 ;
break;
case 11 :
V_90 = 0x1 ;
break;
case 12 :
V_90 = 0x2 ;
break;
case 15 :
V_90 = 0x3 ;
break;
case 2 :
V_90 = 0x4 ;
break;
case 3 :
V_90 = 0x5 ;
break;
case 5 :
V_90 = 0x6 ;
break;
case 7 :
V_90 = 0x7 ;
break;
default:
return - 1 ;
break;
}
return V_90 << 4 ;
}
static int F_33 ( struct V_5 * V_6 ,
struct V_91 * V_92 )
{
const struct V_11 * V_12 = F_4 ( V_6 ) ;
struct V_7 * V_8 ;
int V_90 ;
unsigned int V_47 ;
unsigned long V_42 ;
V_42 = V_92 -> V_93 [ 0 ] ;
V_90 = F_34 ( V_6 , sizeof( struct V_94 ) ) ;
if ( V_90 < 0 )
return V_90 ;
V_6 -> V_95 = V_12 -> V_96 ;
if ( ! F_35 ( V_42 , V_97 , V_6 -> V_98 -> V_99 ) ) {
F_7 ( V_6 , L_9 ) ;
return - V_100 ;
}
if ( ! F_35 ( V_42 + V_101 , V_102 ,
V_6 -> V_98 -> V_99 ) ) {
F_36 ( V_42 , V_97 ) ;
F_7 ( V_6 , L_9 ) ;
return - V_100 ;
}
V_6 -> V_42 = V_42 ;
V_47 = V_92 -> V_93 [ 1 ] ;
if ( F_32 ( V_47 ) >= 0 ) {
V_90 = F_37 ( V_47 , F_29 , 0 ,
V_6 -> V_98 -> V_99 , V_6 ) ;
if ( V_90 < 0 )
return V_90 ;
V_6 -> V_47 = V_47 ;
F_38
( L_10 , V_47 ) ;
} else if ( V_47 == 0 ) {
F_38
( L_11 ) ;
} else {
F_7 ( V_6 , L_12
L_13 ) ;
return - V_103 ;
}
V_90 = F_39 ( V_6 , 4 ) ;
if ( V_90 )
return V_90 ;
V_8 = V_6 -> V_104 + 0 ;
V_6 -> V_76 = V_8 ;
V_8 -> type = V_105 ;
V_8 -> V_106 = V_107 | V_108 ;
V_8 -> V_109 = 8 ;
V_8 -> V_106 = V_110 ;
V_8 -> V_111 = 256 ;
V_8 -> V_112 = ( 1 << 12 ) - 1 ;
V_8 -> V_113 = & V_114 ;
V_8 -> V_115 = F_17 ;
V_8 -> V_116 = F_3 ;
V_8 -> V_117 = F_10 ;
V_8 -> V_118 = F_16 ;
V_8 -> V_119 = F_26 ;
V_8 = V_6 -> V_104 + 1 ;
V_8 -> type = V_120 ;
V_8 -> V_106 = V_107 ;
V_8 -> V_109 = 4 ;
V_8 -> V_112 = 1 ;
V_8 -> V_113 = & V_121 ;
V_8 -> V_122 = F_20 ;
V_8 = V_6 -> V_104 + 2 ;
V_8 -> type = V_123 ;
V_8 -> V_106 = V_124 | V_107 ;
V_8 -> V_109 = 4 ;
V_8 -> V_112 = 1 ;
V_8 -> V_113 = & V_121 ;
V_8 -> V_122 = F_21 ;
V_8 = V_6 -> V_104 + 3 ;
F_40 ( V_6 , V_8 , NULL , V_6 -> V_42 + V_101 ) ;
F_11 ( V_125 , V_6 -> V_42 + V_126 ) ;
F_11 ( V_34 -> V_72 , V_6 -> V_42 + V_70 ) ;
if ( V_6 -> V_47 )
V_34 -> V_48 = F_32 ( V_6 -> V_47 ) ;
else
V_34 -> V_48 = 0 ;
F_11 ( V_34 -> V_48 , V_6 -> V_42 + V_51 ) ;
return 0 ;
}
static void F_41 ( struct V_5 * V_6 )
{
if ( V_6 -> V_104 )
F_42 ( V_6 , V_6 -> V_104 + 3 ) ;
if ( V_6 -> V_47 )
F_43 ( V_6 -> V_47 , V_6 ) ;
if ( V_6 -> V_42 ) {
F_36 ( V_6 -> V_42 , V_97 ) ;
F_36 ( V_6 -> V_42 + V_101 , V_102 ) ;
}
}

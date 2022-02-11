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
unsigned int V_11 = 0 , V_12 , V_4 ;
V_12 = V_10 -> V_13 ;
V_10 -> V_13 &= V_14 | V_15 ;
if ( ! V_10 -> V_13 || V_12 != V_10 -> V_13 )
V_11 ++ ;
V_12 = V_10 -> V_16 ;
V_10 -> V_16 &= V_17 ;
if ( ! V_10 -> V_16 || V_12 != V_10 -> V_16 )
V_11 ++ ;
V_12 = V_10 -> V_18 ;
V_10 -> V_18 &= V_19 | V_15 ;
if ( ! V_10 -> V_18 || V_12 != V_10 -> V_18 )
V_11 ++ ;
V_12 = V_10 -> V_20 ;
V_10 -> V_20 &= V_21 ;
if ( ! V_10 -> V_20 || V_12 != V_10 -> V_20 )
V_11 ++ ;
V_12 = V_10 -> V_22 ;
V_10 -> V_22 &= V_21 | V_23 ;
if ( ! V_10 -> V_22 || V_12 != V_10 -> V_22 )
V_11 ++ ;
if ( V_11 )
return 1 ;
if ( V_10 -> V_22 != V_21 && V_10 -> V_22 != V_23 )
V_11 ++ ;
if ( V_10 -> V_13 != V_14 && V_10 -> V_13 != V_15 )
V_11 ++ ;
if ( V_10 -> V_18 != V_19 && V_10 -> V_18 != V_15 )
V_11 ++ ;
if ( V_11 )
return 2 ;
if ( V_10 -> V_24 != 0 ) {
V_10 -> V_24 = 0 ;
V_11 ++ ;
}
if ( V_10 -> V_16 == V_17 ) {
if ( V_10 -> V_25 != 0 ) {
V_10 -> V_25 = 0 ;
V_11 ++ ;
}
}
if ( V_10 -> V_18 == V_19 ) {
if ( V_10 -> V_26 < V_27 -> V_28 ) {
V_10 -> V_26 = V_27 -> V_28 ;
V_11 ++ ;
}
}
if ( V_10 -> V_29 != V_10 -> V_30 ) {
V_10 -> V_29 = V_10 -> V_30 ;
V_11 ++ ;
}
if ( V_10 -> V_22 == V_21 ) {
} else {
if ( V_10 -> V_31 != 0 ) {
V_10 -> V_31 = 0 ;
V_11 ++ ;
}
}
if ( V_11 )
return 3 ;
if ( V_10 -> V_18 == V_19 ) {
V_12 = V_10 -> V_26 ;
F_4 ( V_32 ,
& ( V_33 -> V_34 ) ,
& ( V_33 -> V_35 ) ,
& ( V_10 -> V_26 ) ,
V_10 -> V_36 & V_37 ) ;
if ( V_12 != V_10 -> V_26 )
V_11 ++ ;
}
if ( V_11 )
return 4 ;
if ( V_10 -> V_38 && V_10 -> V_30 > 1 ) {
for ( V_4 = 0 ; V_4 < V_10 -> V_30 ; V_4 ++ ) {
if ( ( V_4 % 2 ) != ( F_5 ( V_10 -> V_38 [ V_4 ] ) % 2 ) ) {
F_6 ( V_6 , L_1
L_2 ) ;
V_11 ++ ;
}
}
if ( ( V_10 -> V_30 % 2 ) != 0 ) {
F_6 ( V_6 ,
L_3 ) ;
V_11 ++ ;
}
}
if ( V_11 )
return 5 ;
return 0 ;
}
static unsigned int F_7 ( struct V_5 * V_6 ,
unsigned int V_39 , int V_40 )
{
F_4 ( V_32 , & ( V_33 -> V_34 ) ,
& ( V_33 -> V_35 ) , & V_39 ,
V_40 & V_37 ) ;
F_8 ( V_6 -> V_41 + V_42 , 0 , 1 , V_33 -> V_34 ,
2 ) ;
F_8 ( V_6 -> V_41 + V_42 , 0 , 2 , V_33 -> V_35 ,
2 ) ;
return V_39 ;
}
static int F_9 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_43 * V_44 = V_8 -> V_44 ;
struct V_9 * V_10 = & V_44 -> V_10 ;
unsigned int V_45 , V_4 ;
if ( V_6 -> V_46 == 0 ) {
F_6 ( V_6 , L_4 ) ;
return - 1 ;
}
V_33 -> V_47 &= ~ V_48 & ~ V_49 ;
F_10 ( V_33 -> V_47 , V_6 -> V_41 + V_50 ) ;
V_33 -> V_51 = 0 ;
F_8 ( V_6 -> V_41 + V_52 , 0 , 1 , 0 , 2 ) ;
V_33 -> V_53 =
F_11 ( V_6 -> V_41 + V_52 , 0 , 1 ) ;
for ( V_4 = 0 ; V_4 < V_10 -> V_30 ; V_4 ++ ) {
F_10 ( V_4 , V_6 -> V_41 + V_54 ) ;
V_45 =
F_12 ( F_5 ( V_10 -> V_38 [ V_4 ] ) ) |
F_13 ( F_14 ( V_10 -> V_38 [ V_4 ] ) ) ;
F_10 ( V_45 , V_6 -> V_41 + V_55 ) ;
}
V_10 -> V_26 =
F_7 ( V_6 , V_10 -> V_26 ,
V_10 -> V_36 & V_37 ) ;
V_45 = 0 ;
if ( V_10 -> V_13 == V_15 && V_10 -> V_18 != V_15 )
V_45 |= V_56 ;
F_10 ( V_45 , V_6 -> V_41 + V_57 ) ;
F_10 ( 0 , V_6 -> V_41 + V_58 ) ;
V_33 -> V_47 &= ~ V_49 ;
if ( V_10 -> V_18 == V_19 )
V_33 -> V_47 |= V_59 ;
else
V_33 -> V_47 |= V_60 ;
V_33 -> V_47 |= V_48 ;
F_10 ( V_33 -> V_47 , V_6 -> V_41 + V_50 ) ;
return 0 ;
}
static int F_15 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
V_33 -> V_47 &= ~ V_48 & ~ V_49 ;
F_10 ( V_33 -> V_47 , V_6 -> V_41 + V_50 ) ;
return 0 ;
}
static int F_16 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_61 * V_62 , unsigned int * V_1 )
{
int V_4 , V_63 ;
int V_45 ;
const int V_64 = 1000 ;
V_33 -> V_47 &= ~ V_48 & ~ V_49 ;
F_10 ( V_33 -> V_47 , V_6 -> V_41 + V_50 ) ;
F_10 ( 0 , V_6 -> V_41 + V_54 ) ;
V_45 =
F_12 ( F_5 ( V_62 -> V_65 ) ) | F_13 ( F_14 ( V_62 -> V_65 ) ) ;
F_10 ( V_45 , V_6 -> V_41 + V_55 ) ;
for ( V_63 = 0 ; V_63 < V_62 -> V_63 ; V_63 ++ ) {
F_10 ( 0 , V_6 -> V_41 + V_58 ) ;
F_10 ( 0 , V_6 -> V_41 ) ;
for ( V_4 = 0 ; V_4 < V_64 ; V_4 ++ ) {
if ( F_17 ( V_6 -> V_41 + V_57 ) & V_66 )
break;
}
if ( V_4 == V_64 ) {
F_6 ( V_6 , L_5 ) ;
return - V_67 ;
}
V_1 [ V_63 ] = F_1 ( F_18 ( V_6 -> V_41 ) ) ;
}
return V_63 ;
}
static int F_19 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_61 * V_62 , unsigned int * V_1 )
{
unsigned int V_68 ;
V_68 = F_17 ( V_6 -> V_41 + V_69 ) & 0xf ;
V_1 [ 1 ] = V_68 ;
V_1 [ 0 ] = 0 ;
return 2 ;
}
static int F_20 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_61 * V_62 , unsigned int * V_1 )
{
unsigned int V_70 ;
V_1 [ 0 ] &= 0xf ;
V_70 = V_33 -> V_71 ;
V_70 &= ~ V_1 [ 0 ] ;
V_70 |= V_1 [ 0 ] & V_1 [ 1 ] ;
V_33 -> V_71 = V_70 ;
V_1 [ 1 ] = V_70 ;
F_10 ( V_33 -> V_71 , V_6 -> V_41 + V_69 ) ;
return 2 ;
}
static void F_21 ( struct V_5 * V_6 , unsigned int V_72 )
{
struct V_7 * V_8 ;
struct V_43 * V_44 ;
struct V_9 * V_10 ;
T_1 V_73 ;
T_1 V_74 ;
V_8 = V_6 -> V_75 ;
V_44 = V_8 -> V_44 ;
V_44 -> V_76 = 0 ;
V_10 = & V_44 -> V_10 ;
V_74 = F_11 ( V_6 -> V_41 + V_52 , 0 , 1 ) ;
if ( V_33 -> V_51 == 0 && V_74 == V_33 -> V_53 ) {
V_73 = 0 ;
} else {
V_73 = - V_74 - V_33 -> V_51 ;
}
if ( V_10 -> V_22 == V_21 ) {
if ( V_73 > V_10 -> V_31 * V_10 -> V_30 )
V_73 = V_10 -> V_31 * V_10 -> V_30 ;
}
if ( V_73 > V_77 )
V_73 = V_77 ;
F_22 ( V_6 -> V_41 , V_33 -> V_78 , V_73 ) ;
F_2 ( V_33 -> V_78 , V_73 ) ;
F_23 ( V_8 , V_33 -> V_78 ,
V_73 * sizeof( short ) ) ;
V_33 -> V_51 += V_73 ;
if ( V_10 -> V_22 == V_21 ) {
if ( V_33 -> V_51 >= V_10 -> V_31 * V_10 -> V_30 ) {
F_15 ( V_6 , V_8 ) ;
V_44 -> V_76 |= V_79 ;
}
}
if ( V_72 & V_80 ) {
F_15 ( V_6 , V_8 ) ;
V_44 -> V_76 |= V_79 | V_81 ;
F_6 ( V_6 , L_6 ) ;
}
F_24 ( V_6 , V_8 ) ;
}
static int F_25 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
unsigned long V_36 ;
unsigned int V_72 ;
F_26 ( & V_6 -> V_82 , V_36 ) ;
V_72 = F_17 ( V_6 -> V_41 + V_57 ) ;
F_21 ( V_6 , V_72 ) ;
F_27 ( & V_6 -> V_82 , V_36 ) ;
return V_8 -> V_44 -> V_83 - V_8 -> V_44 -> V_84 ;
}
static T_2 F_28 ( int V_46 , void * V_85 )
{
int V_72 ;
struct V_5 * V_6 = V_85 ;
if ( V_6 -> V_86 == 0 ) {
F_6 ( V_6 , L_7 ) ;
return V_87 ;
}
F_29 ( & V_6 -> V_82 ) ;
V_72 = F_17 ( V_6 -> V_41 + V_57 ) ;
if ( ( V_72 & ( V_66 | V_80 ) ) == 0 ) {
F_6 ( V_6 , L_8 ) ;
F_30 ( & V_6 -> V_82 ) ;
return V_88 ;
}
F_21 ( V_6 , V_72 ) ;
F_10 ( 0 , V_6 -> V_41 + V_58 ) ;
F_30 ( & V_6 -> V_82 ) ;
return V_87 ;
}
static int F_31 ( unsigned int V_46 )
{
int V_89 ;
switch ( V_46 ) {
case 10 :
V_89 = 0x0 ;
break;
case 11 :
V_89 = 0x1 ;
break;
case 12 :
V_89 = 0x2 ;
break;
case 15 :
V_89 = 0x3 ;
break;
case 2 :
V_89 = 0x4 ;
break;
case 3 :
V_89 = 0x5 ;
break;
case 5 :
V_89 = 0x6 ;
break;
case 7 :
V_89 = 0x7 ;
break;
default:
return - 1 ;
break;
}
return V_89 << 4 ;
}
static int F_32 ( struct V_5 * V_6 ,
struct V_90 * V_91 )
{
struct V_7 * V_8 ;
int V_89 ;
unsigned int V_46 ;
unsigned long V_41 ;
V_41 = V_91 -> V_92 [ 0 ] ;
V_89 = F_33 ( V_6 , sizeof( struct V_93 ) ) ;
if ( V_89 < 0 )
return V_89 ;
V_6 -> V_94 = V_27 -> V_95 ;
if ( ! F_34 ( V_41 , V_96 , V_6 -> V_97 -> V_98 ) ) {
F_6 ( V_6 , L_9 ) ;
return - V_99 ;
}
if ( ! F_34 ( V_41 + V_100 , V_101 ,
V_6 -> V_97 -> V_98 ) ) {
F_35 ( V_41 , V_96 ) ;
F_6 ( V_6 , L_9 ) ;
return - V_99 ;
}
V_6 -> V_41 = V_41 ;
V_46 = V_91 -> V_92 [ 1 ] ;
if ( F_31 ( V_46 ) >= 0 ) {
V_89 = F_36 ( V_46 , F_28 , 0 ,
V_6 -> V_97 -> V_98 , V_6 ) ;
if ( V_89 < 0 )
return V_89 ;
V_6 -> V_46 = V_46 ;
F_37
( L_10 , V_46 ) ;
} else if ( V_46 == 0 ) {
F_37
( L_11 ) ;
} else {
F_6 ( V_6 , L_12
L_13 ) ;
return - V_102 ;
}
V_89 = F_38 ( V_6 , 4 ) ;
if ( V_89 < 0 )
return V_89 ;
V_8 = V_6 -> V_103 + 0 ;
V_6 -> V_75 = V_8 ;
V_8 -> type = V_104 ;
V_8 -> V_105 = V_106 | V_107 ;
V_8 -> V_108 = 8 ;
V_8 -> V_105 = V_109 ;
V_8 -> V_110 = 256 ;
V_8 -> V_111 = ( 1 << 12 ) - 1 ;
V_8 -> V_112 = & V_113 ;
V_8 -> V_114 = F_16 ;
V_8 -> V_115 = F_3 ;
V_8 -> V_116 = F_9 ;
V_8 -> V_117 = F_15 ;
V_8 -> V_118 = F_25 ;
V_8 = V_6 -> V_103 + 1 ;
V_8 -> type = V_119 ;
V_8 -> V_105 = V_106 ;
V_8 -> V_108 = 4 ;
V_8 -> V_111 = 1 ;
V_8 -> V_112 = & V_120 ;
V_8 -> V_121 = F_19 ;
V_8 = V_6 -> V_103 + 2 ;
V_8 -> type = V_122 ;
V_8 -> V_105 = V_123 | V_106 ;
V_8 -> V_108 = 4 ;
V_8 -> V_111 = 1 ;
V_8 -> V_112 = & V_120 ;
V_8 -> V_121 = F_20 ;
V_8 = V_6 -> V_103 + 3 ;
F_39 ( V_6 , V_8 , NULL , V_6 -> V_41 + V_100 ) ;
F_10 ( V_124 , V_6 -> V_41 + V_125 ) ;
F_10 ( V_33 -> V_71 , V_6 -> V_41 + V_69 ) ;
if ( V_6 -> V_46 )
V_33 -> V_47 = F_31 ( V_6 -> V_46 ) ;
else
V_33 -> V_47 = 0 ;
F_10 ( V_33 -> V_47 , V_6 -> V_41 + V_50 ) ;
return 0 ;
}
static void F_40 ( struct V_5 * V_6 )
{
if ( V_6 -> V_103 )
F_41 ( V_6 , V_6 -> V_103 + 3 ) ;
if ( V_6 -> V_46 )
F_42 ( V_6 -> V_46 , V_6 ) ;
if ( V_6 -> V_41 ) {
F_35 ( V_6 -> V_41 , V_96 ) ;
F_35 ( V_6 -> V_41 + V_100 , V_101 ) ;
}
}

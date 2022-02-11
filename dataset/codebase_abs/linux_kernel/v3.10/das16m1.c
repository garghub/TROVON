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
struct V_11 * V_12 = V_6 -> V_13 ;
unsigned int V_14 = 0 , V_15 , V_4 ;
V_14 |= F_4 ( & V_10 -> V_16 , V_17 | V_18 ) ;
V_14 |= F_4 ( & V_10 -> V_19 , V_20 ) ;
V_14 |= F_4 ( & V_10 -> V_21 , V_22 | V_18 ) ;
V_14 |= F_4 ( & V_10 -> V_23 , V_24 ) ;
V_14 |= F_4 ( & V_10 -> V_25 , V_24 | V_26 ) ;
if ( V_14 )
return 1 ;
V_14 |= F_5 ( V_10 -> V_16 ) ;
V_14 |= F_5 ( V_10 -> V_21 ) ;
V_14 |= F_5 ( V_10 -> V_25 ) ;
if ( V_14 )
return 2 ;
V_14 |= F_6 ( & V_10 -> V_27 , 0 ) ;
if ( V_10 -> V_19 == V_20 )
V_14 |= F_6 ( & V_10 -> V_28 , 0 ) ;
if ( V_10 -> V_21 == V_22 )
V_14 |= F_7 ( & V_10 -> V_29 , 1000 ) ;
V_14 |= F_6 ( & V_10 -> V_30 , V_10 -> V_31 ) ;
if ( V_10 -> V_25 == V_24 ) {
} else {
V_14 |= F_6 ( & V_10 -> V_32 , 0 ) ;
}
if ( V_14 )
return 3 ;
if ( V_10 -> V_21 == V_22 ) {
V_15 = V_10 -> V_29 ;
F_8 ( V_33 ,
& ( V_12 -> V_34 ) ,
& ( V_12 -> V_35 ) ,
& ( V_10 -> V_29 ) ,
V_10 -> V_36 & V_37 ) ;
if ( V_15 != V_10 -> V_29 )
V_14 ++ ;
}
if ( V_14 )
return 4 ;
if ( V_10 -> V_38 && V_10 -> V_31 > 1 ) {
for ( V_4 = 0 ; V_4 < V_10 -> V_31 ; V_4 ++ ) {
if ( ( V_4 % 2 ) != ( F_9 ( V_10 -> V_38 [ V_4 ] ) % 2 ) ) {
F_10 ( V_6 , L_1
L_2 ) ;
V_14 ++ ;
}
}
if ( ( V_10 -> V_31 % 2 ) != 0 ) {
F_10 ( V_6 ,
L_3 ) ;
V_14 ++ ;
}
}
if ( V_14 )
return 5 ;
return 0 ;
}
static unsigned int F_11 ( struct V_5 * V_6 ,
unsigned int V_39 , int V_40 )
{
struct V_11 * V_12 = V_6 -> V_13 ;
F_8 ( V_33 , & ( V_12 -> V_34 ) ,
& ( V_12 -> V_35 ) , & V_39 ,
V_40 & V_37 ) ;
F_12 ( V_6 -> V_41 + V_42 , 0 , 1 , V_12 -> V_34 ,
2 ) ;
F_12 ( V_6 -> V_41 + V_42 , 0 , 2 , V_12 -> V_35 ,
2 ) ;
return V_39 ;
}
static int F_13 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_11 * V_12 = V_6 -> V_13 ;
struct V_43 * V_44 = V_8 -> V_44 ;
struct V_9 * V_10 = & V_44 -> V_10 ;
unsigned int V_45 , V_4 ;
if ( V_6 -> V_46 == 0 ) {
F_10 ( V_6 , L_4 ) ;
return - 1 ;
}
V_12 -> V_47 &= ~ V_48 & ~ V_49 ;
F_14 ( V_12 -> V_47 , V_6 -> V_41 + V_50 ) ;
V_12 -> V_51 = 0 ;
F_12 ( V_6 -> V_41 + V_52 , 0 , 1 , 0 , 2 ) ;
V_12 -> V_53 =
F_15 ( V_6 -> V_41 + V_52 , 0 , 1 ) ;
for ( V_4 = 0 ; V_4 < V_10 -> V_31 ; V_4 ++ ) {
F_14 ( V_4 , V_6 -> V_41 + V_54 ) ;
V_45 =
F_16 ( F_9 ( V_10 -> V_38 [ V_4 ] ) ) |
F_17 ( F_18 ( V_10 -> V_38 [ V_4 ] ) ) ;
F_14 ( V_45 , V_6 -> V_41 + V_55 ) ;
}
V_10 -> V_29 =
F_11 ( V_6 , V_10 -> V_29 ,
V_10 -> V_36 & V_37 ) ;
V_45 = 0 ;
if ( V_10 -> V_16 == V_18 && V_10 -> V_21 != V_18 )
V_45 |= V_56 ;
F_14 ( V_45 , V_6 -> V_41 + V_57 ) ;
F_14 ( 0 , V_6 -> V_41 + V_58 ) ;
V_12 -> V_47 &= ~ V_49 ;
if ( V_10 -> V_21 == V_22 )
V_12 -> V_47 |= V_59 ;
else
V_12 -> V_47 |= V_60 ;
V_12 -> V_47 |= V_48 ;
F_14 ( V_12 -> V_47 , V_6 -> V_41 + V_50 ) ;
return 0 ;
}
static int F_19 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
struct V_11 * V_12 = V_6 -> V_13 ;
V_12 -> V_47 &= ~ V_48 & ~ V_49 ;
F_14 ( V_12 -> V_47 , V_6 -> V_41 + V_50 ) ;
return 0 ;
}
static int F_20 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_61 * V_62 , unsigned int * V_1 )
{
struct V_11 * V_12 = V_6 -> V_13 ;
int V_4 , V_63 ;
int V_45 ;
const int V_64 = 1000 ;
V_12 -> V_47 &= ~ V_48 & ~ V_49 ;
F_14 ( V_12 -> V_47 , V_6 -> V_41 + V_50 ) ;
F_14 ( 0 , V_6 -> V_41 + V_54 ) ;
V_45 =
F_16 ( F_9 ( V_62 -> V_65 ) ) | F_17 ( F_18 ( V_62 -> V_65 ) ) ;
F_14 ( V_45 , V_6 -> V_41 + V_55 ) ;
for ( V_63 = 0 ; V_63 < V_62 -> V_63 ; V_63 ++ ) {
F_14 ( 0 , V_6 -> V_41 + V_58 ) ;
F_14 ( 0 , V_6 -> V_41 ) ;
for ( V_4 = 0 ; V_4 < V_64 ; V_4 ++ ) {
if ( F_21 ( V_6 -> V_41 + V_57 ) & V_66 )
break;
}
if ( V_4 == V_64 ) {
F_10 ( V_6 , L_5 ) ;
return - V_67 ;
}
V_1 [ V_63 ] = F_1 ( F_22 ( V_6 -> V_41 ) ) ;
}
return V_63 ;
}
static int F_23 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_61 * V_62 , unsigned int * V_1 )
{
unsigned int V_68 ;
V_68 = F_21 ( V_6 -> V_41 + V_69 ) & 0xf ;
V_1 [ 1 ] = V_68 ;
V_1 [ 0 ] = 0 ;
return V_62 -> V_63 ;
}
static int F_24 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_61 * V_62 , unsigned int * V_1 )
{
struct V_11 * V_12 = V_6 -> V_13 ;
unsigned int V_70 ;
V_1 [ 0 ] &= 0xf ;
V_70 = V_12 -> V_71 ;
V_70 &= ~ V_1 [ 0 ] ;
V_70 |= V_1 [ 0 ] & V_1 [ 1 ] ;
V_12 -> V_71 = V_70 ;
V_1 [ 1 ] = V_70 ;
F_14 ( V_12 -> V_71 , V_6 -> V_41 + V_69 ) ;
return V_62 -> V_63 ;
}
static void F_25 ( struct V_5 * V_6 , unsigned int V_72 )
{
struct V_11 * V_12 = V_6 -> V_13 ;
struct V_7 * V_8 ;
struct V_43 * V_44 ;
struct V_9 * V_10 ;
T_1 V_73 ;
T_1 V_74 ;
V_8 = V_6 -> V_75 ;
V_44 = V_8 -> V_44 ;
V_44 -> V_76 = 0 ;
V_10 = & V_44 -> V_10 ;
V_74 = F_15 ( V_6 -> V_41 + V_52 , 0 , 1 ) ;
if ( V_12 -> V_51 == 0 && V_74 == V_12 -> V_53 ) {
V_73 = 0 ;
} else {
V_73 = - V_74 - V_12 -> V_51 ;
}
if ( V_10 -> V_25 == V_24 ) {
if ( V_73 > V_10 -> V_32 * V_10 -> V_31 )
V_73 = V_10 -> V_32 * V_10 -> V_31 ;
}
if ( V_73 > V_77 )
V_73 = V_77 ;
F_26 ( V_6 -> V_41 , V_12 -> V_78 , V_73 ) ;
F_2 ( V_12 -> V_78 , V_73 ) ;
F_27 ( V_8 , V_12 -> V_78 ,
V_73 * sizeof( short ) ) ;
V_12 -> V_51 += V_73 ;
if ( V_10 -> V_25 == V_24 ) {
if ( V_12 -> V_51 >= V_10 -> V_32 * V_10 -> V_31 ) {
F_19 ( V_6 , V_8 ) ;
V_44 -> V_76 |= V_79 ;
}
}
if ( V_72 & V_80 ) {
F_19 ( V_6 , V_8 ) ;
V_44 -> V_76 |= V_79 | V_81 ;
F_10 ( V_6 , L_6 ) ;
}
F_28 ( V_6 , V_8 ) ;
}
static int F_29 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
unsigned long V_36 ;
unsigned int V_72 ;
F_30 ( & V_6 -> V_82 , V_36 ) ;
V_72 = F_21 ( V_6 -> V_41 + V_57 ) ;
F_25 ( V_6 , V_72 ) ;
F_31 ( & V_6 -> V_82 , V_36 ) ;
return V_8 -> V_44 -> V_83 - V_8 -> V_44 -> V_84 ;
}
static T_2 F_32 ( int V_46 , void * V_85 )
{
int V_72 ;
struct V_5 * V_6 = V_85 ;
if ( ! V_6 -> V_86 ) {
F_10 ( V_6 , L_7 ) ;
return V_87 ;
}
F_33 ( & V_6 -> V_82 ) ;
V_72 = F_21 ( V_6 -> V_41 + V_57 ) ;
if ( ( V_72 & ( V_66 | V_80 ) ) == 0 ) {
F_10 ( V_6 , L_8 ) ;
F_34 ( & V_6 -> V_82 ) ;
return V_88 ;
}
F_25 ( V_6 , V_72 ) ;
F_14 ( 0 , V_6 -> V_41 + V_58 ) ;
F_34 ( & V_6 -> V_82 ) ;
return V_87 ;
}
static int F_35 ( unsigned int V_46 )
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
static int F_36 ( struct V_5 * V_6 ,
struct V_90 * V_91 )
{
struct V_11 * V_12 ;
struct V_7 * V_8 ;
int V_89 ;
unsigned int V_46 ;
V_12 = F_37 ( sizeof( * V_12 ) , V_92 ) ;
if ( ! V_12 )
return - V_93 ;
V_6 -> V_13 = V_12 ;
V_89 = F_38 ( V_6 , V_91 -> V_94 [ 0 ] , V_95 ) ;
if ( V_89 )
return V_89 ;
V_89 = F_39 ( V_6 , V_6 -> V_41 + V_96 ,
V_97 ) ;
if ( V_89 )
return V_89 ;
V_12 -> V_98 = V_6 -> V_41 + V_96 ;
V_46 = V_91 -> V_94 [ 1 ] ;
if ( F_35 ( V_46 ) >= 0 ) {
V_89 = F_40 ( V_46 , F_32 , 0 ,
V_6 -> V_99 -> V_100 , V_6 ) ;
if ( V_89 < 0 )
return V_89 ;
V_6 -> V_46 = V_46 ;
F_41
( L_9 , V_46 ) ;
} else if ( V_46 == 0 ) {
F_41
( L_10 ) ;
} else {
F_10 ( V_6 , L_11
L_12 ) ;
return - V_101 ;
}
V_89 = F_42 ( V_6 , 4 ) ;
if ( V_89 )
return V_89 ;
V_8 = & V_6 -> V_102 [ 0 ] ;
V_6 -> V_75 = V_8 ;
V_8 -> type = V_103 ;
V_8 -> V_104 = V_105 | V_106 ;
V_8 -> V_107 = 8 ;
V_8 -> V_104 = V_108 ;
V_8 -> V_109 = 256 ;
V_8 -> V_110 = ( 1 << 12 ) - 1 ;
V_8 -> V_111 = & V_112 ;
V_8 -> V_113 = F_20 ;
V_8 -> V_114 = F_3 ;
V_8 -> V_115 = F_13 ;
V_8 -> V_116 = F_19 ;
V_8 -> V_117 = F_29 ;
V_8 = & V_6 -> V_102 [ 1 ] ;
V_8 -> type = V_118 ;
V_8 -> V_104 = V_105 ;
V_8 -> V_107 = 4 ;
V_8 -> V_110 = 1 ;
V_8 -> V_111 = & V_119 ;
V_8 -> V_120 = F_23 ;
V_8 = & V_6 -> V_102 [ 2 ] ;
V_8 -> type = V_121 ;
V_8 -> V_104 = V_122 | V_105 ;
V_8 -> V_107 = 4 ;
V_8 -> V_110 = 1 ;
V_8 -> V_111 = & V_119 ;
V_8 -> V_120 = F_24 ;
V_8 = & V_6 -> V_102 [ 3 ] ;
V_89 = F_43 ( V_6 , V_8 , NULL , V_12 -> V_98 ) ;
if ( V_89 )
return V_89 ;
F_14 ( V_123 , V_6 -> V_41 + V_124 ) ;
F_14 ( V_12 -> V_71 , V_6 -> V_41 + V_69 ) ;
if ( V_6 -> V_46 )
V_12 -> V_47 = F_35 ( V_6 -> V_46 ) ;
else
V_12 -> V_47 = 0 ;
F_14 ( V_12 -> V_47 , V_6 -> V_41 + V_50 ) ;
return 0 ;
}
static void F_44 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = V_6 -> V_13 ;
F_45 ( V_6 , 3 ) ;
if ( V_12 && V_12 -> V_98 )
F_46 ( V_12 -> V_98 , V_97 ) ;
F_47 ( V_6 ) ;
}

static inline unsigned short F_1 ( unsigned short V_1 )
{
return ( V_1 >> 4 ) & 0xfff ;
}
static void F_2 ( unsigned short * V_2 , unsigned int V_3 )
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
& V_12 -> V_34 ,
& V_12 -> V_35 ,
& V_10 -> V_29 , V_10 -> V_36 ) ;
if ( V_15 != V_10 -> V_29 )
V_14 ++ ;
}
if ( V_14 )
return 4 ;
if ( V_10 -> V_37 && V_10 -> V_31 > 1 ) {
for ( V_4 = 0 ; V_4 < V_10 -> V_31 ; V_4 ++ ) {
if ( ( V_4 % 2 ) != ( F_9 ( V_10 -> V_37 [ V_4 ] ) % 2 ) ) {
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
unsigned int V_38 , int V_39 )
{
struct V_11 * V_12 = V_6 -> V_13 ;
F_12 ( V_33 ,
& V_12 -> V_34 ,
& V_12 -> V_35 ,
& V_38 , V_39 ) ;
F_13 ( V_6 -> V_40 + V_41 , 0 , 1 , V_12 -> V_34 ,
2 ) ;
F_13 ( V_6 -> V_40 + V_41 , 0 , 2 , V_12 -> V_35 ,
2 ) ;
return V_38 ;
}
static int F_14 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_11 * V_12 = V_6 -> V_13 ;
struct V_42 * V_43 = V_8 -> V_43 ;
struct V_9 * V_10 = & V_43 -> V_10 ;
unsigned int V_44 , V_4 ;
if ( V_6 -> V_45 == 0 ) {
F_10 ( V_6 , L_4 ) ;
return - 1 ;
}
V_12 -> V_46 &= ~ V_47 & ~ V_48 ;
F_15 ( V_12 -> V_46 , V_6 -> V_40 + V_49 ) ;
V_12 -> V_50 = 0 ;
F_13 ( V_6 -> V_40 + V_51 , 0 , 1 , 0 , 2 ) ;
V_12 -> V_52 =
F_16 ( V_6 -> V_40 + V_51 , 0 , 1 ) ;
for ( V_4 = 0 ; V_4 < V_10 -> V_31 ; V_4 ++ ) {
F_15 ( V_4 , V_6 -> V_40 + V_53 ) ;
V_44 =
F_17 ( F_9 ( V_10 -> V_37 [ V_4 ] ) ) |
F_18 ( F_19 ( V_10 -> V_37 [ V_4 ] ) ) ;
F_15 ( V_44 , V_6 -> V_40 + V_54 ) ;
}
V_10 -> V_29 =
F_11 ( V_6 , V_10 -> V_29 ,
V_10 -> V_36 & V_55 ) ;
V_44 = 0 ;
if ( V_10 -> V_16 == V_18 && V_10 -> V_21 != V_18 )
V_44 |= V_56 ;
F_15 ( V_44 , V_6 -> V_40 + V_57 ) ;
F_15 ( 0 , V_6 -> V_40 + V_58 ) ;
V_12 -> V_46 &= ~ V_48 ;
if ( V_10 -> V_21 == V_22 )
V_12 -> V_46 |= V_59 ;
else
V_12 -> V_46 |= V_60 ;
V_12 -> V_46 |= V_47 ;
F_15 ( V_12 -> V_46 , V_6 -> V_40 + V_49 ) ;
return 0 ;
}
static int F_20 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
struct V_11 * V_12 = V_6 -> V_13 ;
V_12 -> V_46 &= ~ V_47 & ~ V_48 ;
F_15 ( V_12 -> V_46 , V_6 -> V_40 + V_49 ) ;
return 0 ;
}
static int F_21 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_61 * V_62 , unsigned int * V_1 )
{
struct V_11 * V_12 = V_6 -> V_13 ;
int V_4 , V_63 ;
int V_44 ;
const int V_64 = 1000 ;
V_12 -> V_46 &= ~ V_47 & ~ V_48 ;
F_15 ( V_12 -> V_46 , V_6 -> V_40 + V_49 ) ;
F_15 ( 0 , V_6 -> V_40 + V_53 ) ;
V_44 =
F_17 ( F_9 ( V_62 -> V_65 ) ) | F_18 ( F_19 ( V_62 -> V_65 ) ) ;
F_15 ( V_44 , V_6 -> V_40 + V_54 ) ;
for ( V_63 = 0 ; V_63 < V_62 -> V_63 ; V_63 ++ ) {
F_15 ( 0 , V_6 -> V_40 + V_58 ) ;
F_15 ( 0 , V_6 -> V_40 ) ;
for ( V_4 = 0 ; V_4 < V_64 ; V_4 ++ ) {
if ( F_22 ( V_6 -> V_40 + V_57 ) & V_66 )
break;
}
if ( V_4 == V_64 ) {
F_10 ( V_6 , L_5 ) ;
return - V_67 ;
}
V_1 [ V_63 ] = F_1 ( F_23 ( V_6 -> V_40 ) ) ;
}
return V_63 ;
}
static int F_24 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_61 * V_62 , unsigned int * V_1 )
{
unsigned int V_68 ;
V_68 = F_22 ( V_6 -> V_40 + V_69 ) & 0xf ;
V_1 [ 1 ] = V_68 ;
V_1 [ 0 ] = 0 ;
return V_62 -> V_63 ;
}
static int F_25 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_61 * V_62 ,
unsigned int * V_1 )
{
if ( F_26 ( V_8 , V_1 ) )
F_15 ( V_8 -> V_70 , V_6 -> V_40 + V_69 ) ;
V_1 [ 1 ] = V_8 -> V_70 ;
return V_62 -> V_63 ;
}
static void F_27 ( struct V_5 * V_6 , unsigned int V_71 )
{
struct V_11 * V_12 = V_6 -> V_13 ;
struct V_7 * V_8 ;
struct V_42 * V_43 ;
struct V_9 * V_10 ;
T_1 V_72 ;
T_1 V_73 ;
V_8 = V_6 -> V_74 ;
V_43 = V_8 -> V_43 ;
V_43 -> V_75 = 0 ;
V_10 = & V_43 -> V_10 ;
V_73 = F_16 ( V_6 -> V_40 + V_51 , 0 , 1 ) ;
if ( V_12 -> V_50 == 0 && V_73 == V_12 -> V_52 ) {
V_72 = 0 ;
} else {
V_72 = - V_73 - V_12 -> V_50 ;
}
if ( V_10 -> V_25 == V_24 ) {
if ( V_72 > V_10 -> V_32 * V_10 -> V_31 )
V_72 = V_10 -> V_32 * V_10 -> V_31 ;
}
if ( V_72 > V_76 )
V_72 = V_76 ;
F_28 ( V_6 -> V_40 , V_12 -> V_77 , V_72 ) ;
F_2 ( V_12 -> V_77 , V_72 ) ;
F_29 ( V_8 , V_12 -> V_77 ,
V_72 * sizeof( short ) ) ;
V_12 -> V_50 += V_72 ;
if ( V_10 -> V_25 == V_24 ) {
if ( V_12 -> V_50 >= V_10 -> V_32 * V_10 -> V_31 ) {
F_20 ( V_6 , V_8 ) ;
V_43 -> V_75 |= V_78 ;
}
}
if ( V_71 & V_79 ) {
F_20 ( V_6 , V_8 ) ;
V_43 -> V_75 |= V_78 | V_80 ;
F_10 ( V_6 , L_6 ) ;
}
F_30 ( V_6 , V_8 ) ;
}
static int F_31 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
unsigned long V_36 ;
unsigned int V_71 ;
F_32 ( & V_6 -> V_81 , V_36 ) ;
V_71 = F_22 ( V_6 -> V_40 + V_57 ) ;
F_27 ( V_6 , V_71 ) ;
F_33 ( & V_6 -> V_81 , V_36 ) ;
return V_8 -> V_43 -> V_82 - V_8 -> V_43 -> V_83 ;
}
static T_2 F_34 ( int V_45 , void * V_84 )
{
int V_71 ;
struct V_5 * V_6 = V_84 ;
if ( ! V_6 -> V_85 ) {
F_10 ( V_6 , L_7 ) ;
return V_86 ;
}
F_35 ( & V_6 -> V_81 ) ;
V_71 = F_22 ( V_6 -> V_40 + V_57 ) ;
if ( ( V_71 & ( V_66 | V_79 ) ) == 0 ) {
F_10 ( V_6 , L_8 ) ;
F_36 ( & V_6 -> V_81 ) ;
return V_87 ;
}
F_27 ( V_6 , V_71 ) ;
F_15 ( 0 , V_6 -> V_40 + V_58 ) ;
F_36 ( & V_6 -> V_81 ) ;
return V_86 ;
}
static int F_37 ( unsigned int V_45 )
{
int V_88 ;
switch ( V_45 ) {
case 10 :
V_88 = 0x0 ;
break;
case 11 :
V_88 = 0x1 ;
break;
case 12 :
V_88 = 0x2 ;
break;
case 15 :
V_88 = 0x3 ;
break;
case 2 :
V_88 = 0x4 ;
break;
case 3 :
V_88 = 0x5 ;
break;
case 5 :
V_88 = 0x6 ;
break;
case 7 :
V_88 = 0x7 ;
break;
default:
return - 1 ;
break;
}
return V_88 << 4 ;
}
static int F_38 ( struct V_5 * V_6 ,
struct V_89 * V_90 )
{
struct V_11 * V_12 ;
struct V_7 * V_8 ;
int V_88 ;
unsigned int V_45 ;
V_12 = F_39 ( V_6 , sizeof( * V_12 ) ) ;
if ( ! V_12 )
return - V_91 ;
V_88 = F_40 ( V_6 , V_90 -> V_92 [ 0 ] , V_93 ) ;
if ( V_88 )
return V_88 ;
V_88 = F_41 ( V_6 , V_6 -> V_40 + V_94 ,
V_95 ) ;
if ( V_88 )
return V_88 ;
V_12 -> V_96 = V_6 -> V_40 + V_94 ;
V_45 = V_90 -> V_92 [ 1 ] ;
if ( F_37 ( V_45 ) >= 0 ) {
V_88 = F_42 ( V_45 , F_34 , 0 ,
V_6 -> V_97 -> V_98 , V_6 ) ;
if ( V_88 < 0 )
return V_88 ;
V_6 -> V_45 = V_45 ;
F_43
( L_9 , V_45 ) ;
} else if ( V_45 == 0 ) {
F_43
( L_10 ) ;
} else {
F_10 ( V_6 , L_11
L_12 ) ;
return - V_99 ;
}
V_88 = F_44 ( V_6 , 4 ) ;
if ( V_88 )
return V_88 ;
V_8 = & V_6 -> V_100 [ 0 ] ;
V_6 -> V_74 = V_8 ;
V_8 -> type = V_101 ;
V_8 -> V_102 = V_103 | V_104 ;
V_8 -> V_105 = 8 ;
V_8 -> V_102 = V_106 ;
V_8 -> V_107 = 256 ;
V_8 -> V_108 = ( 1 << 12 ) - 1 ;
V_8 -> V_109 = & V_110 ;
V_8 -> V_111 = F_21 ;
V_8 -> V_112 = F_3 ;
V_8 -> V_113 = F_14 ;
V_8 -> V_114 = F_20 ;
V_8 -> V_115 = F_31 ;
V_8 = & V_6 -> V_100 [ 1 ] ;
V_8 -> type = V_116 ;
V_8 -> V_102 = V_103 ;
V_8 -> V_105 = 4 ;
V_8 -> V_108 = 1 ;
V_8 -> V_109 = & V_117 ;
V_8 -> V_118 = F_24 ;
V_8 = & V_6 -> V_100 [ 2 ] ;
V_8 -> type = V_119 ;
V_8 -> V_102 = V_120 | V_103 ;
V_8 -> V_105 = 4 ;
V_8 -> V_108 = 1 ;
V_8 -> V_109 = & V_117 ;
V_8 -> V_118 = F_25 ;
V_8 = & V_6 -> V_100 [ 3 ] ;
V_88 = F_45 ( V_6 , V_8 , NULL , V_12 -> V_96 ) ;
if ( V_88 )
return V_88 ;
F_15 ( V_121 , V_6 -> V_40 + V_122 ) ;
F_15 ( 0 , V_6 -> V_40 + V_69 ) ;
if ( V_6 -> V_45 )
V_12 -> V_46 = F_37 ( V_6 -> V_45 ) ;
else
V_12 -> V_46 = 0 ;
F_15 ( V_12 -> V_46 , V_6 -> V_40 + V_49 ) ;
return 0 ;
}
static void F_46 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = V_6 -> V_13 ;
if ( V_12 && V_12 -> V_96 )
F_47 ( V_12 -> V_96 , V_95 ) ;
F_48 ( V_6 ) ;
}

static int T_1 F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
static void T_2 F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static inline short F_5 ( short V_2 )
{
return ( V_2 >> 4 ) & 0xfff ;
}
static int F_6 ( struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_7 * V_8 )
{
unsigned int V_9 = 0 , V_10 , V_11 ;
V_10 = V_8 -> V_12 ;
V_8 -> V_12 &= V_13 | V_14 ;
if ( ! V_8 -> V_12 || V_10 != V_8 -> V_12 )
V_9 ++ ;
V_10 = V_8 -> V_15 ;
V_8 -> V_15 &= V_16 ;
if ( ! V_8 -> V_15 || V_10 != V_8 -> V_15 )
V_9 ++ ;
V_10 = V_8 -> V_17 ;
V_8 -> V_17 &= V_18 | V_14 ;
if ( ! V_8 -> V_17 || V_10 != V_8 -> V_17 )
V_9 ++ ;
V_10 = V_8 -> V_19 ;
V_8 -> V_19 &= V_20 ;
if ( ! V_8 -> V_19 || V_10 != V_8 -> V_19 )
V_9 ++ ;
V_10 = V_8 -> V_21 ;
V_8 -> V_21 &= V_20 | V_22 ;
if ( ! V_8 -> V_21 || V_10 != V_8 -> V_21 )
V_9 ++ ;
if ( V_9 )
return 1 ;
if ( V_8 -> V_21 != V_20 && V_8 -> V_21 != V_22 )
V_9 ++ ;
if ( V_8 -> V_12 != V_13 && V_8 -> V_12 != V_14 )
V_9 ++ ;
if ( V_8 -> V_17 != V_18 && V_8 -> V_17 != V_14 )
V_9 ++ ;
if ( V_9 )
return 2 ;
if ( V_8 -> V_23 != 0 ) {
V_8 -> V_23 = 0 ;
V_9 ++ ;
}
if ( V_8 -> V_15 == V_16 ) {
if ( V_8 -> V_24 != 0 ) {
V_8 -> V_24 = 0 ;
V_9 ++ ;
}
}
if ( V_8 -> V_17 == V_18 ) {
if ( V_8 -> V_25 < V_26 -> V_27 ) {
V_8 -> V_25 = V_26 -> V_27 ;
V_9 ++ ;
}
}
if ( V_8 -> V_28 != V_8 -> V_29 ) {
V_8 -> V_28 = V_8 -> V_29 ;
V_9 ++ ;
}
if ( V_8 -> V_21 == V_20 ) {
} else {
if ( V_8 -> V_30 != 0 ) {
V_8 -> V_30 = 0 ;
V_9 ++ ;
}
}
if ( V_9 )
return 3 ;
if ( V_8 -> V_17 == V_18 ) {
V_10 = V_8 -> V_25 ;
F_7 ( V_31 ,
& ( V_32 -> V_33 ) ,
& ( V_32 -> V_34 ) ,
& ( V_8 -> V_25 ) ,
V_8 -> V_35 & V_36 ) ;
if ( V_10 != V_8 -> V_25 )
V_9 ++ ;
}
if ( V_9 )
return 4 ;
if ( V_8 -> V_37 && V_8 -> V_29 > 1 ) {
for ( V_11 = 0 ; V_11 < V_8 -> V_29 ; V_11 ++ ) {
if ( ( V_11 % 2 ) != ( F_8 ( V_8 -> V_37 [ V_11 ] ) % 2 ) ) {
F_9 ( V_4 , L_1
L_2 ) ;
V_9 ++ ;
}
}
if ( ( V_8 -> V_29 % 2 ) != 0 ) {
F_9 ( V_4 ,
L_3 ) ;
V_9 ++ ;
}
}
if ( V_9 )
return 5 ;
return 0 ;
}
static int F_10 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_38 * V_39 = V_6 -> V_39 ;
struct V_7 * V_8 = & V_39 -> V_8 ;
unsigned int V_40 , V_11 ;
if ( V_4 -> V_41 == 0 ) {
F_9 ( V_4 , L_4 ) ;
return - 1 ;
}
V_32 -> V_42 &= ~ V_43 & ~ V_44 ;
F_11 ( V_32 -> V_42 , V_4 -> V_45 + V_46 ) ;
V_32 -> V_47 = 0 ;
F_12 ( V_4 -> V_45 + V_48 , 0 , 1 , 0 , 2 ) ;
V_32 -> V_49 =
F_13 ( V_4 -> V_45 + V_48 , 0 , 1 ) ;
for ( V_11 = 0 ; V_11 < V_8 -> V_29 ; V_11 ++ ) {
F_11 ( V_11 , V_4 -> V_45 + V_50 ) ;
V_40 =
F_14 ( F_8 ( V_8 -> V_37 [ V_11 ] ) ) |
F_15 ( F_16 ( V_8 -> V_37 [ V_11 ] ) ) ;
F_11 ( V_40 , V_4 -> V_45 + V_51 ) ;
}
V_8 -> V_25 =
F_17 ( V_4 , V_8 -> V_25 ,
V_8 -> V_35 & V_36 ) ;
V_40 = 0 ;
if ( V_8 -> V_12 == V_14 && V_8 -> V_17 != V_14 )
V_40 |= V_52 ;
F_11 ( V_40 , V_4 -> V_45 + V_53 ) ;
F_11 ( 0 , V_4 -> V_45 + V_54 ) ;
V_32 -> V_42 &= ~ V_44 ;
if ( V_8 -> V_17 == V_18 )
V_32 -> V_42 |= V_55 ;
else
V_32 -> V_42 |= V_56 ;
V_32 -> V_42 |= V_43 ;
F_11 ( V_32 -> V_42 , V_4 -> V_45 + V_46 ) ;
return 0 ;
}
static int F_18 ( struct V_3 * V_4 , struct V_5 * V_6 )
{
V_32 -> V_42 &= ~ V_43 & ~ V_44 ;
F_11 ( V_32 -> V_42 , V_4 -> V_45 + V_46 ) ;
return 0 ;
}
static int F_19 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_57 * V_58 , unsigned int * V_2 )
{
int V_11 , V_59 ;
int V_40 ;
const int V_60 = 1000 ;
V_32 -> V_42 &= ~ V_43 & ~ V_44 ;
F_11 ( V_32 -> V_42 , V_4 -> V_45 + V_46 ) ;
F_11 ( 0 , V_4 -> V_45 + V_50 ) ;
V_40 =
F_14 ( F_8 ( V_58 -> V_61 ) ) | F_15 ( F_16 ( V_58 -> V_61 ) ) ;
F_11 ( V_40 , V_4 -> V_45 + V_51 ) ;
for ( V_59 = 0 ; V_59 < V_58 -> V_59 ; V_59 ++ ) {
F_11 ( 0 , V_4 -> V_45 + V_54 ) ;
F_11 ( 0 , V_4 -> V_45 ) ;
for ( V_11 = 0 ; V_11 < V_60 ; V_11 ++ ) {
if ( F_20 ( V_4 -> V_45 + V_53 ) & V_62 )
break;
}
if ( V_11 == V_60 ) {
F_9 ( V_4 , L_5 ) ;
return - V_63 ;
}
V_2 [ V_59 ] = F_5 ( F_21 ( V_4 -> V_45 ) ) ;
}
return V_59 ;
}
static int F_22 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_57 * V_58 , unsigned int * V_2 )
{
unsigned int V_64 ;
V_64 = F_20 ( V_4 -> V_45 + V_65 ) & 0xf ;
V_2 [ 1 ] = V_64 ;
V_2 [ 0 ] = 0 ;
return 2 ;
}
static int F_23 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_57 * V_58 , unsigned int * V_2 )
{
unsigned int V_66 ;
V_2 [ 0 ] &= 0xf ;
V_66 = V_32 -> V_67 ;
V_66 &= ~ V_2 [ 0 ] ;
V_66 |= V_2 [ 0 ] & V_2 [ 1 ] ;
V_32 -> V_67 = V_66 ;
V_2 [ 1 ] = V_66 ;
F_11 ( V_32 -> V_67 , V_4 -> V_45 + V_65 ) ;
return 2 ;
}
static int F_24 ( struct V_3 * V_4 , struct V_5 * V_6 )
{
unsigned long V_35 ;
unsigned int V_68 ;
F_25 ( & V_4 -> V_69 , V_35 ) ;
V_68 = F_20 ( V_4 -> V_45 + V_53 ) ;
F_26 ( V_4 , V_68 ) ;
F_27 ( & V_4 -> V_69 , V_35 ) ;
return V_6 -> V_39 -> V_70 - V_6 -> V_39 -> V_71 ;
}
static T_3 F_28 ( int V_41 , void * V_72 )
{
int V_68 ;
struct V_3 * V_4 = V_72 ;
if ( V_4 -> V_73 == 0 ) {
F_9 ( V_4 , L_6 ) ;
return V_74 ;
}
F_29 ( & V_4 -> V_69 ) ;
V_68 = F_20 ( V_4 -> V_45 + V_53 ) ;
if ( ( V_68 & ( V_62 | V_75 ) ) == 0 ) {
F_9 ( V_4 , L_7 ) ;
F_30 ( & V_4 -> V_69 ) ;
return V_76 ;
}
F_26 ( V_4 , V_68 ) ;
F_11 ( 0 , V_4 -> V_45 + V_54 ) ;
F_30 ( & V_4 -> V_69 ) ;
return V_74 ;
}
static void F_31 ( short * V_77 , unsigned int V_78 )
{
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < V_78 ; V_11 ++ )
V_77 [ V_11 ] = F_5 ( V_77 [ V_11 ] ) ;
}
static void F_26 ( struct V_3 * V_4 , unsigned int V_68 )
{
struct V_5 * V_6 ;
struct V_38 * V_39 ;
struct V_7 * V_8 ;
T_4 V_79 ;
T_4 V_80 ;
V_6 = V_4 -> V_81 ;
V_39 = V_6 -> V_39 ;
V_39 -> V_82 = 0 ;
V_8 = & V_39 -> V_8 ;
V_80 = F_13 ( V_4 -> V_45 + V_48 , 0 , 1 ) ;
if ( V_32 -> V_47 == 0 && V_80 == V_32 -> V_49 ) {
V_79 = 0 ;
} else {
V_79 = - V_80 - V_32 -> V_47 ;
}
if ( V_8 -> V_21 == V_20 ) {
if ( V_79 > V_8 -> V_30 * V_8 -> V_29 )
V_79 = V_8 -> V_30 * V_8 -> V_29 ;
}
if ( V_79 > V_83 )
V_79 = V_83 ;
F_32 ( V_4 -> V_45 , V_32 -> V_84 , V_79 ) ;
F_31 ( V_32 -> V_84 , V_79 ) ;
F_33 ( V_6 , V_32 -> V_84 ,
V_79 * sizeof( short ) ) ;
V_32 -> V_47 += V_79 ;
if ( V_8 -> V_21 == V_20 ) {
if ( V_32 -> V_47 >= V_8 -> V_30 * V_8 -> V_29 ) {
F_18 ( V_4 , V_6 ) ;
V_39 -> V_82 |= V_85 ;
}
}
if ( V_68 & V_75 ) {
F_18 ( V_4 , V_6 ) ;
V_39 -> V_82 |= V_85 | V_86 ;
F_9 ( V_4 , L_8 ) ;
}
F_34 ( V_4 , V_6 ) ;
}
static unsigned int F_17 ( struct V_3 * V_4 ,
unsigned int V_87 , int V_88 )
{
F_7 ( V_31 , & ( V_32 -> V_33 ) ,
& ( V_32 -> V_34 ) , & V_87 ,
V_88 & V_36 ) ;
F_12 ( V_4 -> V_45 + V_89 , 0 , 1 , V_32 -> V_33 ,
2 ) ;
F_12 ( V_4 -> V_45 + V_89 , 0 , 2 , V_32 -> V_34 ,
2 ) ;
return V_87 ;
}
static int F_35 ( unsigned int V_41 )
{
int V_90 ;
switch ( V_41 ) {
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
static int F_36 ( struct V_3 * V_4 ,
struct V_91 * V_92 )
{
struct V_5 * V_6 ;
int V_90 ;
unsigned int V_41 ;
unsigned long V_45 ;
V_45 = V_92 -> V_93 [ 0 ] ;
V_90 = F_37 ( V_4 , sizeof( struct V_94 ) ) ;
if ( V_90 < 0 )
return V_90 ;
V_4 -> V_95 = V_26 -> V_96 ;
if ( ! F_38 ( V_45 , V_97 , V_1 . V_98 ) ) {
F_9 ( V_4 , L_9 ) ;
return - V_99 ;
}
if ( ! F_38 ( V_45 + V_100 , V_101 ,
V_1 . V_98 ) ) {
F_39 ( V_45 , V_97 ) ;
F_9 ( V_4 , L_9 ) ;
return - V_99 ;
}
V_4 -> V_45 = V_45 ;
V_41 = V_92 -> V_93 [ 1 ] ;
if ( F_35 ( V_41 ) >= 0 ) {
V_90 = F_40 ( V_41 , F_28 , 0 ,
V_1 . V_98 , V_4 ) ;
if ( V_90 < 0 )
return V_90 ;
V_4 -> V_41 = V_41 ;
F_41
( L_10 , V_41 ) ;
} else if ( V_41 == 0 ) {
F_41
( L_11 ) ;
} else {
F_9 ( V_4 , L_12
L_13 ) ;
return - V_102 ;
}
V_90 = F_42 ( V_4 , 4 ) ;
if ( V_90 < 0 )
return V_90 ;
V_6 = V_4 -> V_103 + 0 ;
V_4 -> V_81 = V_6 ;
V_6 -> type = V_104 ;
V_6 -> V_105 = V_106 | V_107 ;
V_6 -> V_108 = 8 ;
V_6 -> V_105 = V_109 ;
V_6 -> V_110 = 256 ;
V_6 -> V_111 = ( 1 << 12 ) - 1 ;
V_6 -> V_112 = & V_113 ;
V_6 -> V_114 = F_19 ;
V_6 -> V_115 = F_6 ;
V_6 -> V_116 = F_10 ;
V_6 -> V_117 = F_18 ;
V_6 -> V_118 = F_24 ;
V_6 = V_4 -> V_103 + 1 ;
V_6 -> type = V_119 ;
V_6 -> V_105 = V_106 ;
V_6 -> V_108 = 4 ;
V_6 -> V_111 = 1 ;
V_6 -> V_112 = & V_120 ;
V_6 -> V_121 = F_22 ;
V_6 = V_4 -> V_103 + 2 ;
V_6 -> type = V_122 ;
V_6 -> V_105 = V_123 | V_106 ;
V_6 -> V_108 = 4 ;
V_6 -> V_111 = 1 ;
V_6 -> V_112 = & V_120 ;
V_6 -> V_121 = F_23 ;
V_6 = V_4 -> V_103 + 3 ;
F_43 ( V_4 , V_6 , NULL , V_4 -> V_45 + V_100 ) ;
F_11 ( V_124 , V_4 -> V_45 + V_125 ) ;
F_11 ( V_32 -> V_67 , V_4 -> V_45 + V_65 ) ;
if ( V_4 -> V_41 )
V_32 -> V_42 = F_35 ( V_4 -> V_41 ) ;
else
V_32 -> V_42 = 0 ;
F_11 ( V_32 -> V_42 , V_4 -> V_45 + V_46 ) ;
return 0 ;
}
static int F_44 ( struct V_3 * V_4 )
{
if ( V_4 -> V_103 )
F_45 ( V_4 , V_4 -> V_103 + 3 ) ;
if ( V_4 -> V_41 )
F_46 ( V_4 -> V_41 , V_4 ) ;
if ( V_4 -> V_45 ) {
F_39 ( V_4 -> V_45 , V_97 ) ;
F_39 ( V_4 -> V_45 + V_100 , V_101 ) ;
}
return 0 ;
}

static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
int V_4 = 0 ;
if ( V_2 && V_2 -> V_5 ) {
for ( V_3 = 0 ; V_3 < V_2 -> V_6 ; V_3 ++ ) {
if ( V_2 -> V_5 [ V_3 ] ) {
F_2 ( V_2 -> V_5 [ V_3 ] ) ;
}
F_3 ( & V_2 -> V_7 -> V_8 ,
L_1 ,
V_3 , V_4 ) ;
}
}
return V_4 ;
}
static int F_4 ( struct V_1 * V_9 , int V_10 )
{
int V_11 = 0 ;
if ( ! V_9 ) {
F_5 ( L_2 ) ;
return - V_12 ;
}
F_3 ( & V_9 -> V_7 -> V_8 , L_3 ) ;
if ( V_10 ) {
V_11 = F_1 ( V_9 ) ;
}
V_9 -> V_13 = 0 ;
return V_11 ;
}
static int F_6 ( struct V_14 * V_8 ,
struct V_15 * V_16 )
{
struct V_1 * V_9 ;
int V_17 = 0 ;
V_9 = V_8 -> V_18 ;
if ( ! V_9 )
return - V_12 ;
F_3 ( & V_9 -> V_7 -> V_8 , L_4 ) ;
F_7 ( & V_9 -> V_19 ) ;
if ( ! ( V_9 -> V_20 ) ) {
F_8 ( & V_9 -> V_19 ) ;
return - V_21 ;
}
V_17 = F_4 ( V_9 , V_9 -> V_13 ) ;
F_8 ( & V_9 -> V_19 ) ;
return V_17 ;
}
static void F_9 ( struct V_22 * V_22 )
{
int V_3 , V_4 , V_23 ;
struct V_1 * V_9 ;
struct V_14 * V_24 ;
struct V_15 * V_16 ;
T_1 V_25 ;
unsigned int V_26 ;
V_24 = V_22 -> V_27 ;
V_9 = V_24 -> V_18 ;
V_16 = & V_24 -> V_28 [ V_29 ] ;
switch ( V_22 -> V_30 ) {
case 0 :
memcpy ( V_9 -> V_31 ,
V_22 -> V_32 , V_33 ) ;
break;
case - V_34 :
F_3 ( & V_22 -> V_8 -> V_8 ,
L_5 ,
V_9 -> V_35 -> V_36 ) ;
break;
case - V_37 :
case - V_38 :
case - V_39 :
case - V_40 :
if ( V_9 -> V_13 ) {
V_16 -> V_41 -> V_42 |= V_43 ;
V_16 -> V_41 -> V_42 |= V_44 ;
F_10 ( V_9 -> V_35 , V_16 ) ;
F_4 ( V_9 , 0 ) ;
}
return;
default:
if ( V_9 -> V_13 ) {
F_11 ( & V_22 -> V_8 -> V_8 ,
L_6
L_7 , V_22 -> V_30 ) ;
V_16 -> V_41 -> V_42 |= V_43 ;
V_16 -> V_41 -> V_42 |= V_44 ;
F_10 ( V_9 -> V_35 , V_16 ) ;
F_4 ( V_9 , 0 ) ;
}
return;
}
if ( F_12 ( ( ! ( V_9 -> V_13 ) ) ) ) {
return;
}
V_22 -> V_8 = V_9 -> V_45 ;
V_4 = F_13 ( V_22 , V_46 ) ;
if ( F_12 ( V_4 < 0 ) ) {
F_11 ( & V_22 -> V_8 -> V_8 ,
L_8
L_9 ,
V_4 ) ;
if ( V_4 == - V_47 )
F_11 ( & V_22 -> V_8 -> V_8 ,
L_10
L_11 ) ;
V_16 -> V_41 -> V_42 |= V_43 ;
V_16 -> V_41 -> V_42 |= V_44 ;
F_10 ( V_9 -> V_35 , V_16 ) ;
F_4 ( V_9 , 0 ) ;
return;
}
V_26 = F_14 ( V_9 -> V_31 [ 0 ] ) ;
V_9 -> V_48 -- ;
if ( F_15 ( V_9 -> V_48 > 0 ) )
return;
V_9 -> V_48 = V_9 -> V_49 ;
if ( ! ( V_9 -> V_50 ) ) {
V_9 -> V_51 -- ;
if ( V_9 -> V_51 < 0 ) {
F_4 ( V_9 , 0 ) ;
V_16 -> V_41 -> V_42 |= V_43 ;
F_10 ( V_9 -> V_35 , V_16 ) ;
return;
}
}
V_23 = V_16 -> V_41 -> V_52 . V_53 ;
for ( V_3 = 0 ; V_3 < V_23 ; V_3 ++ ) {
V_25 = F_14 ( V_9 -> V_31 [ V_3 + 1 ] ) ;
V_25 = V_25 & 0x00ffffff ;
V_25 = V_25 ^ 0x00800000 ;
V_4 = F_16 ( V_16 , & V_25 , sizeof( V_54 ) ) ;
if ( F_12 ( V_4 == 0 ) ) {
F_4 ( V_9 , 0 ) ;
return;
}
}
V_16 -> V_41 -> V_42 |= V_55 | V_56 ;
F_10 ( V_9 -> V_35 , V_16 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
int V_4 = 0 ;
if ( V_2 && V_2 -> V_57 ) {
for ( V_3 = 0 ; V_3 < V_2 -> V_58 ; V_3 ++ ) {
if ( V_2 -> V_57 [ V_3 ] )
F_2 ( V_2 -> V_57 [ V_3 ] ) ;
F_3 ( & V_2 -> V_7 -> V_8 ,
L_12 ,
V_3 , V_4 ) ;
}
}
return V_4 ;
}
static int F_18 ( struct V_1 * V_9 , int V_10 )
{
int V_11 = 0 ;
if ( ! V_9 )
return - V_12 ;
F_3 ( & V_9 -> V_7 -> V_8 , L_13 ) ;
if ( V_10 )
V_11 = F_17 ( V_9 ) ;
V_9 -> V_59 = 0 ;
return V_11 ;
}
static int F_19 ( struct V_14 * V_8 ,
struct V_15 * V_16 )
{
struct V_1 * V_9 = V_8 -> V_18 ;
int V_17 = 0 ;
if ( ! V_9 )
return - V_12 ;
F_7 ( & V_9 -> V_19 ) ;
if ( ! ( V_9 -> V_20 ) ) {
F_8 ( & V_9 -> V_19 ) ;
return - V_21 ;
}
V_17 = F_18 ( V_9 , V_9 -> V_59 ) ;
F_8 ( & V_9 -> V_19 ) ;
return V_17 ;
}
static void F_20 ( struct V_22 * V_22 )
{
int V_3 , V_11 ;
T_2 * V_60 ;
struct V_1 * V_9 ;
struct V_14 * V_24 ;
struct V_15 * V_16 ;
V_24 = V_22 -> V_27 ;
V_9 = V_24 -> V_18 ;
V_16 = & V_24 -> V_28 [ V_61 ] ;
switch ( V_22 -> V_30 ) {
case 0 :
break;
case - V_37 :
case - V_38 :
case - V_39 :
case - V_40 :
if ( V_9 -> V_59 ) {
V_16 -> V_41 -> V_42 |= V_43 ;
F_10 ( V_9 -> V_35 , V_16 ) ;
F_18 ( V_9 , 0 ) ;
}
return;
default:
if ( V_9 -> V_59 ) {
F_11 ( & V_22 -> V_8 -> V_8 ,
L_14
L_15 , V_22 -> V_30 ) ;
V_16 -> V_41 -> V_42 |= V_44 ;
V_16 -> V_41 -> V_42 |= V_43 ;
F_10 ( V_9 -> V_35 , V_16 ) ;
F_18 ( V_9 , 0 ) ;
}
return;
}
if ( ! ( V_9 -> V_59 ) )
return;
V_9 -> V_62 -- ;
if ( ( int ) V_9 -> V_62 <= 0 ) {
V_9 -> V_62 = V_9 -> V_63 ;
if ( ! ( V_9 -> V_64 ) ) {
V_9 -> V_65 -- ;
if ( V_9 -> V_65 < 0 ) {
F_18 ( V_9 , 0 ) ;
V_16 -> V_41 -> V_42 |= V_43 ;
F_10 ( V_9 -> V_35 , V_16 ) ;
return;
}
}
( ( T_2 * ) ( V_22 -> V_32 ) ) [ 0 ] =
V_16 -> V_41 -> V_52 . V_53 ;
for ( V_3 = 0 ; V_3 < V_16 -> V_41 -> V_52 . V_53 ; V_3 ++ ) {
short V_66 ;
if ( V_3 >= V_67 )
break;
V_60 =
( & ( ( ( T_2 * ) V_22 -> V_32 ) [ V_3 * 2 + 1 ] ) ) ;
V_11 = F_21 ( V_16 -> V_41 , & V_66 ) ;
V_60 [ 0 ] = V_66 ;
V_60 [ 1 ] = V_9 -> V_68 [ V_3 ] ;
if ( V_11 < 0 ) {
F_11 ( & V_22 -> V_8 -> V_8 ,
L_16 ) ;
V_16 -> V_41 -> V_42 |= V_43 ;
V_16 -> V_41 -> V_42 |= V_69 ;
}
V_16 -> V_41 -> V_42 |= V_55 ;
F_10 ( V_9 -> V_35 , V_16 ) ;
}
}
V_22 -> V_70 = V_71 ;
V_22 -> V_8 = V_9 -> V_45 ;
V_22 -> V_30 = 0 ;
if ( V_9 -> V_59 ) {
if ( V_9 -> V_72 ) {
V_22 -> V_73 = 8 ;
} else {
V_22 -> V_73 = 1 ;
}
V_22 -> V_74 = 1 ;
V_22 -> V_75 [ 0 ] . V_76 = 0 ;
V_22 -> V_75 [ 0 ] . V_77 = V_71 ;
V_22 -> V_75 [ 0 ] . V_30 = 0 ;
V_11 = F_13 ( V_22 , V_46 ) ;
if ( V_11 < 0 ) {
F_11 ( & V_22 -> V_8 -> V_8 ,
L_17
L_18 , V_11 ) ;
if ( V_11 == V_47 )
F_11 ( & V_22 -> V_8 -> V_8 ,
L_19
L_20 ) ;
V_16 -> V_41 -> V_42 |= V_43 ;
V_16 -> V_41 -> V_42 |= V_44 ;
F_10 ( V_9 -> V_35 , V_16 ) ;
F_18 ( V_9 , 0 ) ;
}
}
}
static int F_22 ( struct V_1 * V_1 )
{
int V_78 = 0 ;
T_2 * V_79 ;
V_79 = F_23 ( 16 , V_80 ) ;
if ( ! V_79 )
return - V_81 ;
V_79 [ 0 ] = 0 ;
V_78 = F_24 ( V_1 -> V_45 ,
F_25 ( V_1 -> V_45 , 0 ) ,
V_82 ,
V_83 ,
V_84 ,
0x0000 ,
V_79 ,
1 ,
V_85 ) ;
if ( V_78 < 0 )
F_11 ( & V_1 -> V_7 -> V_8 ,
L_21 ) ;
F_26 ( V_79 ) ;
return V_78 ;
}
static int F_27 ( struct V_1 * V_1 )
{
int V_78 = 0 ;
T_2 * V_79 ;
V_79 = F_23 ( 16 , V_80 ) ;
if ( ! V_79 )
return - V_81 ;
V_79 [ 0 ] = 1 ;
V_78 = F_24 ( V_1 -> V_45 ,
F_25 ( V_1 -> V_45 , 0 ) ,
V_82 ,
V_83 ,
V_84 ,
0x0000 , V_79 ,
1 ,
V_85 ) ;
if ( V_78 < 0 )
F_11 ( & V_1 -> V_7 -> V_8 ,
L_22 ) ;
F_26 ( V_79 ) ;
return V_78 ;
}
static int F_28 ( struct V_1 * V_1 ,
T_2 * V_79 ,
unsigned int V_86 , unsigned int V_87 )
{
int V_78 ;
V_78 = F_24 ( V_1 -> V_45 ,
F_25 ( V_1 -> V_45 , 0 ) ,
V_82 ,
V_83 ,
V_86 ,
0x0000 ,
V_79 ,
V_87 ,
V_85 ) ;
F_3 ( & V_1 -> V_7 -> V_8 , L_23 , V_78 ) ;
if ( V_78 < 0 ) {
F_11 ( & V_1 -> V_7 -> V_8 ,
L_24 ) ;
return V_78 ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_1 ,
const T_3 * V_88 , int V_89 )
{
int V_11 ;
T_2 * V_90 ;
if ( ! V_88 )
return 0 ;
if ( V_89 > V_91 ) {
F_11 ( & V_1 -> V_7 -> V_8 ,
L_25 ) ;
return - V_81 ;
}
V_90 = F_30 ( V_88 , V_89 , V_80 ) ;
if ( ! V_90 ) {
F_11 ( & V_1 -> V_7 -> V_8 ,
L_26 ) ;
return - V_81 ;
}
V_11 = F_27 ( V_1 ) ;
if ( V_11 < 0 ) {
F_11 ( & V_1 -> V_7 -> V_8 ,
L_27 ) ;
F_26 ( V_90 ) ;
return V_11 ;
}
V_11 = F_28 ( V_1 , V_90 , 0 , V_89 ) ;
if ( V_11 < 0 ) {
F_11 ( & V_1 -> V_7 -> V_8 ,
L_28 ) ;
F_26 ( V_90 ) ;
return V_11 ;
}
V_11 = F_22 ( V_1 ) ;
if ( V_11 < 0 ) {
F_11 ( & V_1 -> V_7 -> V_8 ,
L_29 ) ;
F_26 ( V_90 ) ;
return V_11 ;
}
F_26 ( V_90 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_1 )
{
int V_3 , V_92 ;
if ( ! V_1 )
return - V_12 ;
for ( V_3 = 0 ; V_3 < V_1 -> V_6 ; V_3 ++ ) {
V_1 -> V_5 [ V_3 ] -> V_73 = V_1 -> V_93 ;
V_1 -> V_5 [ V_3 ] -> V_27 = V_1 -> V_35 ;
V_1 -> V_5 [ V_3 ] -> V_8 = V_1 -> V_45 ;
V_1 -> V_5 [ V_3 ] -> V_30 = 0 ;
V_1 -> V_5 [ V_3 ] -> V_94 = V_95 ;
F_3 ( & V_1 -> V_7 -> V_8 ,
L_30 ,
V_1 -> V_35 -> V_36 , V_3 ,
( V_1 -> V_5 [ V_3 ] -> V_27 ) ,
( V_1 -> V_5 [ V_3 ] -> V_8 ) ,
( V_1 -> V_5 [ V_3 ] -> V_73 ) ) ;
V_92 = F_13 ( V_1 -> V_5 [ V_3 ] , V_46 ) ;
if ( V_92 ) {
F_11 ( & V_1 -> V_7 -> V_8 ,
L_31 ,
V_3 , V_92 ) ;
return V_92 ;
}
}
return 0 ;
}
static int F_32 ( struct V_1 * V_1 )
{
int V_3 , V_92 ;
if ( ! V_1 )
return - V_12 ;
for ( V_3 = 0 ; V_3 < V_1 -> V_58 ; V_3 ++ ) {
F_3 ( & V_1 -> V_7 -> V_8 ,
L_32 , V_3 ) ;
V_1 -> V_57 [ V_3 ] -> V_27 = V_1 -> V_35 ;
V_1 -> V_57 [ V_3 ] -> V_8 = V_1 -> V_45 ;
V_1 -> V_57 [ V_3 ] -> V_30 = 0 ;
V_1 -> V_57 [ V_3 ] -> V_94 = V_95 ;
V_92 = F_13 ( V_1 -> V_57 [ V_3 ] , V_46 ) ;
if ( V_92 ) {
F_11 ( & V_1 -> V_7 -> V_8 ,
L_33 ,
V_3 , V_92 ) ;
return V_92 ;
}
}
return 0 ;
}
static int F_33 ( int V_96 )
{
if ( V_96 <= 2 )
return 2 ;
if ( V_96 <= 8 )
return 4 ;
return 8 ;
}
static int F_34 ( struct V_14 * V_8 ,
struct V_15 * V_16 ,
struct V_97 * V_52 )
{
struct V_1 * V_9 = V_8 -> V_18 ;
int V_4 = 0 , V_3 ;
unsigned int V_98 ;
if ( ! ( V_9 -> V_20 ) )
return - V_21 ;
V_4 |= F_35 ( & V_52 -> V_99 , V_100 | V_101 ) ;
V_4 |= F_35 ( & V_52 -> V_102 , V_103 ) ;
V_4 |= F_35 ( & V_52 -> V_104 , V_100 ) ;
V_4 |= F_35 ( & V_52 -> V_105 , V_106 ) ;
V_4 |= F_35 ( & V_52 -> V_107 , V_106 | V_108 ) ;
if ( V_4 )
return 1 ;
V_4 |= F_36 ( V_52 -> V_99 ) ;
V_4 |= F_36 ( V_52 -> V_107 ) ;
if ( V_4 )
return 2 ;
V_4 |= F_37 ( & V_52 -> V_109 , 0 ) ;
if ( V_52 -> V_102 == V_110 )
V_4 |= F_37 ( & V_52 -> V_111 , 0 ) ;
if ( V_52 -> V_102 == V_103 ) {
if ( V_9 -> V_72 ) {
V_3 = F_33 ( V_52 -> V_53 ) ;
V_4 |= F_38 ( & V_52 -> V_111 ,
( 1000000 / 8 * V_3 ) ) ;
V_98 =
( ( unsigned int ) ( V_52 -> V_111 / 125000 ) ) *
125000 ;
} else {
V_4 |= F_38 ( & V_52 -> V_111 ,
1000000 ) ;
V_98 = ( ( unsigned int ) ( V_52 -> V_111 /
1000000 ) ) * 1000000 ;
}
V_4 |= F_37 ( & V_52 -> V_111 ,
V_98 ) ;
}
V_4 |= F_37 ( & V_52 -> V_112 , V_52 -> V_53 ) ;
if ( V_52 -> V_107 == V_106 ) {
} else {
V_4 |= F_37 ( & V_52 -> V_113 , 0 ) ;
}
if ( V_4 )
return 3 ;
return 0 ;
}
static void F_39 ( unsigned int V_114 ,
T_2 * V_115 ,
T_2 * V_116 )
{
if ( V_114 < 8 )
( * V_115 ) = ( * V_115 ) | ( 1 << V_114 ) ;
else if ( V_114 < 16 )
( * V_116 ) = ( * V_116 ) | ( 1 << ( V_114 - 8 ) ) ;
}
static int F_40 ( struct V_1 * V_9 , int V_117 )
{
int V_118 , V_119 ;
V_9 -> V_120 [ 0 ] = V_117 ;
#ifdef F_41
F_42 ( V_121 L_34 ,
V_9 -> V_35 -> V_36 ) ;
for ( V_118 = 0 ; V_118 < V_122 ; V_118 ++ )
F_42 ( L_35 , V_9 -> V_120 [ V_118 ] ) ;
F_42 ( L_36 ) ;
#endif
V_118 = F_43 ( V_9 -> V_45 ,
F_44 ( V_9 -> V_45 ,
V_123 ) ,
V_9 -> V_120 , V_122 ,
& V_119 , V_85 ) ;
if ( V_118 < 0 )
F_11 ( & V_9 -> V_7 -> V_8 , L_37
L_38
L_9 , V_9 -> V_35 -> V_36 , V_118 ) ;
return V_118 ;
}
static int F_45 ( struct V_1 * V_9 , int V_124 )
{
int V_118 = ( - V_12 ) ;
int V_125 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_126 ; V_3 ++ ) {
V_118 = F_43 ( V_9 -> V_45 ,
F_46 ( V_9 -> V_45 ,
V_127 ) ,
V_9 -> V_128 , V_129 ,
& V_125 , V_85 ) ;
if ( V_118 < 0 ) {
F_11 ( & V_9 -> V_7 -> V_8 , L_37
L_39
L_40
L_36 , V_9 -> V_35 -> V_36 ,
V_118 ) ;
return V_118 ;
}
if ( V_9 -> V_128 [ 0 ] == V_124 )
return V_118 ;
}
F_11 ( & V_9 -> V_7 -> V_8 , L_41
L_42 ,
V_9 -> V_35 -> V_36 , V_124 ,
V_9 -> V_128 [ 0 ] ) ;
return - V_12 ;
}
static int F_47 ( struct V_14 * V_8 ,
struct V_15 * V_16 , unsigned int V_130 )
{
int V_11 ;
struct V_1 * V_9 = V_8 -> V_18 ;
if ( ! V_9 )
return - V_12 ;
F_7 ( & V_9 -> V_19 ) ;
if ( ! ( V_9 -> V_20 ) ) {
F_8 ( & V_9 -> V_19 ) ;
return - V_21 ;
}
F_3 ( & V_9 -> V_7 -> V_8 ,
L_43 , V_8 -> V_36 ) ;
if ( V_130 != 0 ) {
F_11 ( & V_9 -> V_7 -> V_8 ,
L_44 ,
V_8 -> V_36 ) ;
F_8 ( & V_9 -> V_19 ) ;
return - V_131 ;
}
if ( ! ( V_9 -> V_13 ) ) {
V_9 -> V_13 = 1 ;
V_11 = F_31 ( V_9 ) ;
if ( V_11 < 0 ) {
F_11 ( & V_9 -> V_7 -> V_8 ,
L_45
L_46 , V_8 -> V_36 , V_11 ) ;
V_9 -> V_13 = 0 ;
F_8 ( & V_9 -> V_19 ) ;
return V_11 ;
}
V_16 -> V_41 -> V_132 = NULL ;
} else {
F_11 ( & V_9 -> V_7 -> V_8 ,
L_47 ,
V_8 -> V_36 ) ;
}
F_8 ( & V_9 -> V_19 ) ;
return 1 ;
}
static int F_48 ( struct V_14 * V_8 , struct V_15 * V_16 )
{
struct V_97 * V_52 = & V_16 -> V_41 -> V_52 ;
unsigned int V_114 ;
int V_3 , V_11 ;
struct V_1 * V_9 = V_8 -> V_18 ;
int V_118 ;
T_2 V_115 = 0 ;
T_2 V_116 = 0 ;
T_2 V_133 = 0 ;
if ( ! V_9 )
return - V_12 ;
F_3 ( & V_9 -> V_7 -> V_8 ,
L_48 , V_8 -> V_36 ) ;
F_7 ( & V_9 -> V_19 ) ;
if ( ! ( V_9 -> V_20 ) ) {
F_8 ( & V_9 -> V_19 ) ;
return - V_21 ;
}
if ( V_9 -> V_13 ) {
F_11 ( & V_9 -> V_7 -> V_8 , L_37
L_49 ,
V_8 -> V_36 ) ;
F_8 ( & V_9 -> V_19 ) ;
return - V_134 ;
}
V_16 -> V_41 -> V_135 = 0 ;
V_9 -> V_120 [ 1 ] = V_52 -> V_53 ;
V_9 -> V_120 [ 2 ] = 0x12 ;
V_9 -> V_120 [ 3 ] = 0x03 ;
V_9 -> V_120 [ 4 ] = 0x00 ;
for ( V_3 = 0 ; V_3 < V_52 -> V_53 ; V_3 ++ ) {
V_114 = F_49 ( V_52 -> V_136 [ V_3 ] ) ;
F_39 ( V_114 , & V_115 , & V_116 ) ;
if ( V_3 >= V_137 ) {
F_11 ( & V_9 -> V_7 -> V_8 ,
L_50 ,
V_8 -> V_36 ) ;
break;
}
}
V_9 -> V_120 [ 5 ] = V_115 ;
V_9 -> V_120 [ 6 ] = V_116 ;
V_9 -> V_120 [ 7 ] = V_133 ;
F_3 ( & V_9 -> V_7 -> V_8 ,
L_51 ,
V_8 -> V_36 , V_137 ) ;
V_118 = F_40 ( V_9 , V_138 ) ;
if ( V_118 < 0 ) {
F_8 ( & V_9 -> V_19 ) ;
return V_118 ;
}
if ( V_9 -> V_72 ) {
V_9 -> V_93 =
F_33 ( V_52 -> V_53 ) ;
V_9 -> V_49 = V_52 -> V_111 / ( 125000 *
( V_9 ->
V_93 ) ) ;
} else {
V_9 -> V_93 = 1 ;
V_9 -> V_49 = V_52 -> V_111 / 1000000 ;
}
if ( V_9 -> V_49 < 1 ) {
F_11 ( & V_9 -> V_7 -> V_8 , L_52
L_53
L_54 , V_8 -> V_36 ,
V_9 -> V_49 , V_52 -> V_111 ) ;
F_8 ( & V_9 -> V_19 ) ;
return - V_131 ;
}
V_9 -> V_48 = V_9 -> V_49 ;
if ( V_52 -> V_107 == V_106 ) {
V_9 -> V_51 = V_52 -> V_113 ;
V_9 -> V_50 = 0 ;
} else {
V_9 -> V_50 = 1 ;
V_9 -> V_51 = 0 ;
}
if ( V_52 -> V_99 == V_100 ) {
V_9 -> V_13 = 1 ;
V_11 = F_31 ( V_9 ) ;
if ( V_11 < 0 ) {
V_9 -> V_13 = 0 ;
F_8 ( & V_9 -> V_19 ) ;
return V_11 ;
}
V_16 -> V_41 -> V_132 = NULL ;
} else {
V_16 -> V_41 -> V_132 = F_47 ;
}
F_8 ( & V_9 -> V_19 ) ;
return 0 ;
}
static int F_50 ( struct V_14 * V_8 ,
struct V_15 * V_16 ,
struct V_139 * V_140 , unsigned int * V_141 )
{
int V_3 ;
T_1 V_142 = 0 ;
int V_114 ;
int V_4 ;
struct V_1 * V_9 = V_8 -> V_18 ;
T_2 V_115 = 0 ;
T_2 V_116 = 0 ;
T_2 V_133 = 0 ;
if ( ! V_9 )
return 0 ;
F_3 ( & V_9 -> V_7 -> V_8 ,
L_55 ,
V_8 -> V_36 , V_140 -> V_23 , V_140 -> V_143 ) ;
F_7 ( & V_9 -> V_19 ) ;
if ( ! ( V_9 -> V_20 ) ) {
F_8 ( & V_9 -> V_19 ) ;
return - V_21 ;
}
if ( V_9 -> V_13 ) {
F_11 ( & V_9 -> V_7 -> V_8 ,
L_56
L_57 , V_8 -> V_36 ) ;
F_8 ( & V_9 -> V_19 ) ;
return 0 ;
}
V_9 -> V_120 [ 1 ] = 0x16 ;
V_9 -> V_120 [ 2 ] = 0x80 ;
V_9 -> V_120 [ 3 ] = 0x00 ;
V_114 = F_49 ( V_140 -> V_144 ) ;
F_39 ( V_114 , & V_115 , & V_116 ) ;
V_9 -> V_120 [ 4 ] = V_115 ;
V_9 -> V_120 [ 5 ] = V_116 ;
V_9 -> V_120 [ 6 ] = V_133 ;
V_4 = F_40 ( V_9 , V_145 ) ;
if ( V_4 < 0 ) {
F_8 ( & V_9 -> V_19 ) ;
return V_4 ;
}
for ( V_3 = 0 ; V_3 < V_140 -> V_23 ; V_3 ++ ) {
V_4 = F_45 ( V_9 , V_145 ) ;
if ( V_4 < 0 ) {
F_8 ( & V_9 -> V_19 ) ;
return 0 ;
}
V_142 = F_14 ( * ( ( T_1 * )
( ( V_9 -> V_128 ) + 1 ) ) ) ;
V_142 = V_142 & 0x00ffffff ;
V_142 = V_142 ^ 0x00800000 ;
V_141 [ V_3 ] = V_142 ;
}
F_8 ( & V_9 -> V_19 ) ;
return V_3 ;
}
static int F_51 ( struct V_14 * V_8 , int V_114 )
{
struct V_1 * V_9 = V_8 -> V_18 ;
T_2 V_133 = 0 ;
V_54 V_142 ;
int V_4 ;
if ( ! V_9 )
return 0 ;
if ( V_9 -> V_13 ) {
F_11 ( & V_9 -> V_7 -> V_8 ,
L_58
L_57 , V_8 -> V_36 ) ;
return 0 ;
}
V_9 -> V_120 [ 1 ] = 0x12 ;
V_9 -> V_120 [ 2 ] = 0x80 ;
V_9 -> V_120 [ 3 ] = 0x00 ;
if ( V_114 == 1 ) {
V_133 = V_133 | 1 ;
} else if ( V_114 == 2 ) {
V_133 = V_133 | 4 ;
} else if ( V_114 == 3 ) {
V_133 = V_133 | 8 ;
} else if ( V_114 == 4 ) {
V_133 = V_133 | 16 ;
} else if ( V_114 == 5 ) {
V_133 = V_133 | 32 ;
}
V_9 -> V_120 [ 4 ] = 0 ;
V_9 -> V_120 [ 5 ] = 0 ;
V_9 -> V_120 [ 6 ] = V_133 ;
V_4 = F_40 ( V_9 , V_145 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_45 ( V_9 , V_145 ) ;
if ( V_4 < 0 )
return V_4 ;
V_142 = F_14 ( * ( ( T_1 * ) ( ( V_9 -> V_128 ) + 1 ) ) ) ;
V_142 = V_142 & 0x00ffffff ;
V_142 = V_142 ^ 0x00800000 ;
return ( int ) V_142 ;
}
static int F_52 ( struct V_14 * V_8 ,
struct V_15 * V_16 ,
struct V_139 * V_140 , unsigned int * V_141 )
{
int V_3 ;
int V_114 = F_49 ( V_140 -> V_144 ) ;
struct V_1 * V_9 = V_8 -> V_18 ;
if ( ! V_9 )
return - V_12 ;
F_7 ( & V_9 -> V_19 ) ;
if ( ! ( V_9 -> V_20 ) ) {
F_8 ( & V_9 -> V_19 ) ;
return - V_21 ;
}
for ( V_3 = 0 ; V_3 < V_140 -> V_23 ; V_3 ++ )
V_141 [ V_3 ] = V_9 -> V_146 [ V_114 ] ;
F_8 ( & V_9 -> V_19 ) ;
return V_3 ;
}
static int F_53 ( struct V_14 * V_8 ,
struct V_15 * V_16 ,
struct V_139 * V_140 , unsigned int * V_141 )
{
int V_3 , V_4 ;
int V_114 = F_49 ( V_140 -> V_144 ) ;
struct V_1 * V_9 = V_8 -> V_18 ;
if ( ! V_9 )
return - V_12 ;
F_3 ( & V_9 -> V_7 -> V_8 ,
L_59 , V_8 -> V_36 ) ;
F_7 ( & V_9 -> V_19 ) ;
if ( ! ( V_9 -> V_20 ) ) {
F_8 ( & V_9 -> V_19 ) ;
return - V_21 ;
}
if ( V_9 -> V_59 ) {
F_11 ( & V_9 -> V_7 -> V_8 ,
L_60
L_61 , V_8 -> V_36 ) ;
F_8 ( & V_9 -> V_19 ) ;
return 0 ;
}
for ( V_3 = 0 ; V_3 < V_140 -> V_23 ; V_3 ++ ) {
F_3 ( & V_9 -> V_7 -> V_8 ,
L_62 ,
V_8 -> V_36 , V_114 , V_3 , V_141 [ V_3 ] ) ;
V_9 -> V_120 [ 1 ] = 1 ;
V_9 -> V_120 [ 2 ] = V_141 [ V_3 ] ;
V_9 -> V_146 [ V_114 ] = V_141 [ V_3 ] ;
V_9 -> V_120 [ 3 ] = V_114 ;
V_4 = F_40 ( V_9 , V_147 ) ;
if ( V_4 < 0 ) {
F_8 ( & V_9 -> V_19 ) ;
return V_4 ;
}
}
F_8 ( & V_9 -> V_19 ) ;
return V_3 ;
}
static int F_54 ( struct V_14 * V_8 ,
struct V_15 * V_16 , unsigned int V_130 )
{
int V_11 ;
struct V_1 * V_9 = V_8 -> V_18 ;
if ( ! V_9 )
return - V_12 ;
F_7 ( & V_9 -> V_19 ) ;
if ( ! ( V_9 -> V_20 ) ) {
V_11 = - V_21 ;
goto V_148;
}
if ( V_130 != 0 ) {
F_11 ( & V_9 -> V_7 -> V_8 ,
L_63 ,
V_8 -> V_36 ) ;
V_11 = - V_131 ;
goto V_148;
}
if ( ! ( V_9 -> V_59 ) ) {
V_9 -> V_59 = 1 ;
V_11 = F_32 ( V_9 ) ;
if ( V_11 < 0 ) {
F_11 ( & V_9 -> V_7 -> V_8 ,
L_64
L_9 , V_8 -> V_36 , V_11 ) ;
V_9 -> V_59 = 0 ;
goto V_148;
}
V_16 -> V_41 -> V_132 = NULL ;
} else {
F_11 ( & V_9 -> V_7 -> V_8 ,
L_65 ,
V_8 -> V_36 ) ;
}
V_11 = 1 ;
V_148:
F_8 ( & V_9 -> V_19 ) ;
return V_11 ;
}
static int F_55 ( struct V_14 * V_8 ,
struct V_15 * V_16 ,
struct V_97 * V_52 )
{
struct V_1 * V_9 = V_8 -> V_18 ;
int V_4 = 0 ;
unsigned int V_149 ;
if ( ! V_9 )
return - V_12 ;
if ( ! ( V_9 -> V_20 ) )
return - V_21 ;
F_3 ( & V_9 -> V_7 -> V_8 ,
L_66 , V_8 -> V_36 ) ;
V_4 |= F_35 ( & V_52 -> V_99 , V_100 | V_101 ) ;
if ( 0 ) {
V_149 = V_110 ;
} else {
V_149 = V_103 ;
}
V_4 |= F_35 ( & V_52 -> V_102 , V_149 ) ;
V_4 |= F_35 ( & V_52 -> V_104 , V_100 ) ;
V_4 |= F_35 ( & V_52 -> V_105 , V_106 ) ;
V_4 |= F_35 ( & V_52 -> V_107 , V_106 | V_108 ) ;
if ( V_4 )
return 1 ;
V_4 |= F_36 ( V_52 -> V_99 ) ;
V_4 |= F_36 ( V_52 -> V_107 ) ;
if ( V_4 )
return 2 ;
V_4 |= F_37 ( & V_52 -> V_109 , 0 ) ;
if ( V_52 -> V_102 == V_110 )
V_4 |= F_37 ( & V_52 -> V_111 , 0 ) ;
if ( V_52 -> V_102 == V_103 )
V_4 |= F_38 ( & V_52 -> V_111 ,
1000000 ) ;
if ( V_52 -> V_104 == V_103 )
V_4 |= F_38 ( & V_52 -> V_150 , 125000 ) ;
V_4 |= F_37 ( & V_52 -> V_112 , V_52 -> V_53 ) ;
if ( V_52 -> V_107 == V_106 ) {
} else {
V_4 |= F_37 ( & V_52 -> V_113 , 0 ) ;
}
if ( V_4 )
return 3 ;
return 0 ;
}
static int F_56 ( struct V_14 * V_8 , struct V_15 * V_16 )
{
struct V_97 * V_52 = & V_16 -> V_41 -> V_52 ;
unsigned int V_114 , V_151 ;
int V_3 , V_11 ;
struct V_1 * V_9 = V_8 -> V_18 ;
if ( ! V_9 )
return - V_12 ;
F_7 ( & V_9 -> V_19 ) ;
if ( ! ( V_9 -> V_20 ) ) {
F_8 ( & V_9 -> V_19 ) ;
return - V_21 ;
}
F_3 ( & V_9 -> V_7 -> V_8 ,
L_67 , V_8 -> V_36 , V_152 ) ;
V_16 -> V_41 -> V_135 = 0 ;
for ( V_3 = 0 ; V_3 < V_52 -> V_53 ; ++ V_3 ) {
V_114 = F_49 ( V_52 -> V_136 [ V_3 ] ) ;
V_151 = F_57 ( V_52 -> V_136 [ V_3 ] ) ;
if ( V_3 >= V_67 ) {
F_11 ( & V_9 -> V_7 -> V_8 ,
L_68 ,
V_8 -> V_36 , V_152 ) ;
break;
}
V_9 -> V_68 [ V_3 ] = V_114 ;
F_3 ( & V_9 -> V_7 -> V_8 ,
L_69 ,
V_8 -> V_36 , V_3 , V_9 -> V_68 [ V_3 ] ) ;
}
if ( 0 ) {
V_9 -> V_63 = V_52 -> V_150 / 125000 ;
} else {
V_9 -> V_63 = V_52 -> V_111 / 1000000 ;
F_3 ( & V_9 -> V_7 -> V_8 ,
L_70
L_71 , V_8 -> V_36 ,
V_52 -> V_102 , V_52 -> V_111 ,
V_52 -> V_104 , V_52 -> V_150 ) ;
F_3 ( & V_9 -> V_7 -> V_8 ,
L_72 ,
V_8 -> V_36 , V_9 -> V_63 ) ;
if ( V_9 -> V_63 < 1 ) {
F_11 ( & V_9 -> V_7 -> V_8 ,
L_73
L_74
L_54 ,
V_8 -> V_36 , V_9 -> V_63 ,
V_52 -> V_111 ) ;
F_8 ( & V_9 -> V_19 ) ;
return - V_131 ;
}
}
V_9 -> V_62 = V_9 -> V_63 ;
if ( V_52 -> V_107 == V_106 ) {
if ( 0 ) {
V_9 -> V_65 =
( V_52 -> V_113 ) * ( V_52 -> V_112 ) ;
} else {
V_9 -> V_65 = V_52 -> V_113 ;
}
V_9 -> V_64 = 0 ;
} else {
V_9 -> V_64 = 1 ;
V_9 -> V_65 = 0 ;
}
if ( V_52 -> V_99 == V_100 ) {
V_9 -> V_59 = 1 ;
V_11 = F_32 ( V_9 ) ;
if ( V_11 < 0 ) {
V_9 -> V_59 = 0 ;
F_8 ( & V_9 -> V_19 ) ;
return V_11 ;
}
V_16 -> V_41 -> V_132 = NULL ;
} else {
V_16 -> V_41 -> V_132 = F_54 ;
}
F_8 ( & V_9 -> V_19 ) ;
return 0 ;
}
static int F_58 ( struct V_14 * V_8 ,
struct V_15 * V_16 ,
struct V_139 * V_140 , unsigned int * V_141 )
{
int V_114 = F_49 ( V_140 -> V_144 ) ;
switch ( V_141 [ 0 ] ) {
case V_153 :
V_16 -> V_154 |= 1 << V_114 ;
break;
case V_155 :
V_16 -> V_154 &= ~ ( 1 << V_114 ) ;
break;
case V_156 :
V_141 [ 1 ] =
( V_16 -> V_154 & ( 1 << V_114 ) ) ? V_157 : V_158 ;
break;
default:
return - V_131 ;
break;
}
return V_140 -> V_23 ;
}
static int F_59 ( struct V_14 * V_8 ,
struct V_15 * V_16 ,
struct V_139 * V_140 ,
unsigned int * V_141 )
{
struct V_1 * V_9 = V_8 -> V_18 ;
int V_4 ;
if ( ! V_9 )
return - V_12 ;
F_7 ( & V_9 -> V_19 ) ;
if ( ! ( V_9 -> V_20 ) ) {
F_8 ( & V_9 -> V_19 ) ;
return - V_21 ;
}
V_16 -> V_159 &= ~ V_141 [ 0 ] ;
V_16 -> V_159 |= V_141 [ 0 ] & V_141 [ 1 ] ;
V_9 -> V_120 [ 1 ] = ( V_16 -> V_154 ) & 0x000000FF ;
V_9 -> V_120 [ 4 ] = ( V_16 -> V_159 ) & 0x000000FF ;
V_9 -> V_120 [ 2 ] = ( ( V_16 -> V_154 ) & 0x0000FF00 ) >> 8 ;
V_9 -> V_120 [ 5 ] = ( ( V_16 -> V_159 ) & 0x0000FF00 ) >> 8 ;
V_9 -> V_120 [ 3 ] = ( ( V_16 -> V_154 ) & 0x00FF0000 ) >> 16 ;
V_9 -> V_120 [ 6 ] = ( ( V_16 -> V_159 ) & 0x00FF0000 ) >> 16 ;
V_4 = F_40 ( V_9 , V_160 ) ;
if ( V_4 < 0 ) {
F_8 ( & V_9 -> V_19 ) ;
return V_4 ;
}
V_4 = F_45 ( V_9 , V_160 ) ;
if ( V_4 < 0 ) {
F_8 ( & V_9 -> V_19 ) ;
return V_4 ;
}
V_141 [ 1 ] = ( ( ( unsigned int ) ( V_9 -> V_128 [ 1 ] ) ) & 0xff ) |
( ( ( ( unsigned int ) ( V_9 -> V_128 [ 2 ] ) ) & 0xff ) << 8 ) |
( ( ( ( unsigned int ) ( V_9 -> V_128 [ 3 ] ) ) & 0xff ) << 16 ) ;
V_16 -> V_159 = V_141 [ 1 ] ;
F_8 ( & V_9 -> V_19 ) ;
return V_140 -> V_23 ;
}
static int F_60 ( struct V_1 * V_2 )
{
int V_4 = 0 ;
if ( V_2 && V_2 -> V_161 ) {
if ( V_2 -> V_161 )
F_2 ( V_2 -> V_161 ) ;
F_3 ( & V_2 -> V_7 -> V_8 ,
L_75 , V_4 ) ;
}
return V_4 ;
}
static int F_61 ( struct V_1 * V_9 , int V_10 )
{
int V_11 = 0 ;
if ( ! V_9 )
return - V_12 ;
F_3 ( & V_9 -> V_7 -> V_8 , L_76 , V_152 ) ;
if ( V_10 )
V_11 = F_60 ( V_9 ) ;
V_9 -> V_162 = 0 ;
return V_11 ;
}
static int F_62 ( struct V_14 * V_8 ,
struct V_15 * V_16 )
{
struct V_1 * V_9 = V_8 -> V_18 ;
int V_17 = 0 ;
V_17 = F_61 ( V_9 , V_9 -> V_162 ) ;
F_3 ( & V_9 -> V_7 -> V_8 ,
L_77 ,
V_8 -> V_36 ) ;
V_17 = F_40 ( V_9 , V_163 ) ;
if ( V_17 < 0 )
return V_17 ;
return V_17 ;
}
static void F_63 ( struct V_22 * V_22 )
{
int V_11 ;
struct V_1 * V_9 ;
struct V_14 * V_24 ;
struct V_15 * V_16 ;
V_24 = V_22 -> V_27 ;
V_9 = V_24 -> V_18 ;
V_16 = & V_24 -> V_28 [ V_61 ] ;
switch ( V_22 -> V_30 ) {
case 0 :
break;
case - V_37 :
case - V_38 :
case - V_39 :
case - V_40 :
if ( V_9 -> V_162 )
F_61 ( V_9 , 0 ) ;
return;
default:
if ( V_9 -> V_162 ) {
F_11 ( & V_9 -> V_7 -> V_8 ,
L_78
L_79 , V_22 -> V_30 ) ;
F_61 ( V_9 , 0 ) ;
}
return;
}
if ( ! ( V_9 -> V_162 ) )
return;
V_22 -> V_70 = V_9 -> V_164 ;
V_22 -> V_8 = V_9 -> V_45 ;
V_22 -> V_30 = 0 ;
if ( V_9 -> V_162 ) {
V_11 = F_13 ( V_22 , V_46 ) ;
if ( V_11 < 0 ) {
F_11 ( & V_9 -> V_7 -> V_8 ,
L_80
L_18 , V_11 ) ;
if ( V_11 == V_47 )
F_11 ( & V_9 -> V_7 -> V_8 ,
L_19
L_20 ) ;
F_61 ( V_9 , 0 ) ;
}
}
}
static int F_64 ( struct V_1 * V_1 )
{
int V_92 ;
if ( ! V_1 )
return - V_12 ;
F_3 ( & V_1 -> V_7 -> V_8 , L_81 ) ;
F_65 ( V_1 -> V_161 ,
V_1 -> V_45 ,
F_44 ( V_1 -> V_45 , V_165 ) ,
V_1 -> V_161 -> V_32 ,
V_1 -> V_164 , F_63 ,
V_1 -> V_35 ) ;
V_92 = F_13 ( V_1 -> V_161 , V_46 ) ;
if ( V_92 ) {
F_11 ( & V_1 -> V_7 -> V_8 ,
L_82 ,
V_92 ) ;
return V_92 ;
}
return 0 ;
}
static int F_66 ( struct V_14 * V_8 ,
struct V_15 * V_16 , unsigned int V_166 )
{
struct V_1 * V_9 = V_8 -> V_18 ;
int V_167 = 255 ;
if ( V_166 < V_168 ) {
F_11 ( & V_9 -> V_7 -> V_8 ,
L_83 ,
V_8 -> V_36 ) ;
return - V_169 ;
} else {
V_167 = V_166 / ( ( int ) ( 6 * 512 * ( 1.0 / 0.033 ) ) ) - 6 ;
if ( V_167 > 255 ) {
F_11 ( & V_9 -> V_7 -> V_8 ,
L_84 ,
V_8 -> V_36 , V_166 ) ;
return - V_169 ;
}
}
V_9 -> V_170 = V_167 ;
V_9 -> V_171 = V_166 ;
F_3 ( & V_9 -> V_7 -> V_8 , L_85 ,
V_152 , V_166 , V_167 ) ;
return 0 ;
}
static int F_67 ( struct V_14 * V_8 ,
struct V_15 * V_16 )
{
int V_11 , V_3 ;
struct V_1 * V_9 = V_8 -> V_18 ;
F_3 ( & V_9 -> V_7 -> V_8 , L_67 ,
V_8 -> V_36 , V_152 ) ;
if ( V_9 -> V_162 ) {
return 0 ;
}
V_9 -> V_120 [ 1 ] = ( ( T_2 ) V_9 -> V_170 ) ;
V_11 = F_40 ( V_9 , V_172 ) ;
if ( V_11 < 0 )
return V_11 ;
for ( V_3 = 0 ; V_3 < V_9 -> V_164 ; V_3 ++ )
( ( char * ) ( V_9 -> V_161 -> V_32 ) ) [ V_3 ] = 0 ;
V_9 -> V_162 = 1 ;
V_11 = F_64 ( V_9 ) ;
if ( V_11 < 0 ) {
V_9 -> V_162 = 0 ;
return V_11 ;
}
return 0 ;
}
static int F_68 ( struct V_14 * V_8 ,
struct V_15 * V_16 , int V_173 ,
unsigned int V_174 , unsigned int V_175 )
{
struct V_1 * V_9 = V_8 -> V_18 ;
int V_3 , V_176 ;
char * V_177 ;
char V_178 ;
char V_179 ;
char V_180 ;
if ( ! V_9 )
return - V_12 ;
V_178 = ( 1 << V_173 ) ;
V_179 = ( 16 << V_173 ) ;
V_176 = V_9 -> V_164 ;
V_177 = ( char * ) ( V_9 -> V_161 -> V_32 ) ;
for ( V_3 = 0 ; V_3 < V_176 ; V_3 ++ ) {
V_180 = * V_177 ;
V_180 = V_180 & ( ~ V_178 ) ;
if ( V_3 < V_174 )
V_180 = V_180 | V_178 ;
if ( ! V_175 ) {
V_180 = V_180 & ( ~ V_179 ) ;
} else {
V_180 = V_180 | V_179 ;
}
* ( V_177 ++ ) = V_180 ;
}
return 1 ;
}
static int F_69 ( struct V_14 * V_8 ,
struct V_15 * V_16 ,
struct V_139 * V_140 , unsigned int * V_141 )
{
struct V_1 * V_9 = V_8 -> V_18 ;
if ( ! V_9 )
return - V_12 ;
if ( ( V_140 -> V_23 ) != 1 ) {
return - V_131 ;
}
return F_68 ( V_8 , V_16 , F_49 ( V_140 -> V_144 ) , V_141 [ 0 ] , 0 ) ;
}
static int F_70 ( struct V_14 * V_181 ,
struct V_15 * V_182 , struct V_139 * V_183 ,
unsigned int * V_184 )
{
return - V_131 ;
}
static int F_71 ( struct V_14 * V_8 ,
struct V_15 * V_16 ,
struct V_139 * V_140 , unsigned int * V_141 )
{
struct V_1 * V_9 = V_8 -> V_18 ;
switch ( V_141 [ 0 ] ) {
case V_185 :
F_3 ( & V_9 -> V_7 -> V_8 ,
L_86 , V_8 -> V_36 , V_152 ) ;
if ( V_141 [ 1 ] != 0 )
return - V_131 ;
return F_67 ( V_8 , V_16 ) ;
case V_186 :
F_3 ( & V_9 -> V_7 -> V_8 ,
L_87 , V_8 -> V_36 , V_152 ) ;
return F_62 ( V_8 , V_16 ) ;
case V_187 :
V_141 [ 1 ] = V_9 -> V_162 ;
return 0 ;
case V_188 :
F_3 ( & V_9 -> V_7 -> V_8 ,
L_88 , V_8 -> V_36 ,
V_152 ) ;
return F_66 ( V_8 , V_16 , V_141 [ 1 ] ) ;
case V_189 :
V_141 [ 1 ] = V_9 -> V_171 ;
return 0 ;
case V_190 :
return F_68 ( V_8 , V_16 ,
F_49 ( V_140 -> V_144 ) ,
V_141 [ 1 ] ,
( V_141 [ 2 ] != 0 ) ) ;
case V_191 :
return - V_131 ;
}
return - V_131 ;
}
static void F_72 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! V_2 )
return;
F_3 ( & V_2 -> V_7 -> V_8 , L_89 ) ;
if ( V_2 -> V_7 )
F_73 ( V_2 -> V_7 , NULL ) ;
V_2 -> V_20 = 0 ;
if ( V_2 -> V_5 ) {
if ( V_2 -> V_13 ) {
V_2 -> V_13 = 0 ;
F_1 ( V_2 ) ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_6 ; V_3 ++ ) {
F_26 ( V_2 -> V_5 [ V_3 ] -> V_32 ) ;
V_2 -> V_5 [ V_3 ] -> V_32 = NULL ;
F_2 ( V_2 -> V_5 [ V_3 ] ) ;
F_74 ( V_2 -> V_5 [ V_3 ] ) ;
V_2 -> V_5 [ V_3 ] = NULL ;
}
F_26 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
if ( V_2 -> V_57 ) {
if ( V_2 -> V_59 ) {
V_2 -> V_59 = 0 ;
F_17 ( V_2 ) ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_58 ; V_3 ++ ) {
if ( V_2 -> V_57 [ V_3 ] -> V_32 ) {
F_26 ( V_2 ->
V_57 [ V_3 ] -> V_32 ) ;
V_2 -> V_57 [ V_3 ] -> V_32 =
NULL ;
}
if ( V_2 -> V_57 [ V_3 ] ) {
F_2 ( V_2 -> V_57 [ V_3 ] ) ;
F_74 ( V_2 -> V_57 [ V_3 ] ) ;
V_2 -> V_57 [ V_3 ] = NULL ;
}
}
F_26 ( V_2 -> V_57 ) ;
V_2 -> V_57 = NULL ;
}
if ( V_2 -> V_161 ) {
if ( V_2 -> V_162 ) {
V_2 -> V_162 = 0 ;
F_60 ( V_2 ) ;
}
F_26 ( V_2 -> V_161 -> V_32 ) ;
V_2 -> V_161 -> V_32 = NULL ;
F_2 ( V_2 -> V_161 ) ;
F_74 ( V_2 -> V_161 ) ;
V_2 -> V_161 = NULL ;
}
F_26 ( V_2 -> V_31 ) ;
V_2 -> V_31 = NULL ;
F_26 ( V_2 -> V_128 ) ;
V_2 -> V_128 = NULL ;
F_26 ( V_2 -> V_146 ) ;
V_2 -> V_146 = NULL ;
F_26 ( V_2 -> V_68 ) ;
V_2 -> V_68 = NULL ;
F_26 ( V_2 -> V_120 ) ;
V_2 -> V_120 = NULL ;
V_2 -> V_13 = 0 ;
V_2 -> V_59 = 0 ;
V_2 -> V_162 = 0 ;
}
static int F_75 ( struct V_14 * V_8 ,
struct V_1 * V_192 )
{
int V_11 ;
struct V_15 * V_16 ;
int V_193 ;
int V_76 ;
F_7 ( & V_192 -> V_19 ) ;
V_192 -> V_35 = V_8 ;
if ( V_192 -> V_72 )
V_193 = 4 ;
else
V_193 = 3 ;
V_11 = F_76 ( V_8 , V_193 ) ;
if ( V_11 ) {
F_8 ( & V_192 -> V_19 ) ;
return V_11 ;
}
V_8 -> V_18 = V_192 ;
V_16 = & V_8 -> V_28 [ V_29 ] ;
V_8 -> V_194 = V_16 ;
V_16 -> V_18 = NULL ;
V_16 -> type = V_195 ;
V_16 -> V_196 = V_197 | V_198 |
V_199 | V_200 ;
V_16 -> V_201 = V_137 ;
V_16 -> V_202 = V_137 ;
V_16 -> V_203 = F_50 ;
V_16 -> V_204 = F_34 ;
V_16 -> V_205 = F_48 ;
V_16 -> V_206 = F_6 ;
V_16 -> V_207 = 0x00FFFFFF ;
V_16 -> V_208 = ( & V_209 ) ;
V_16 = & V_8 -> V_28 [ V_61 ] ;
V_16 -> type = V_210 ;
V_8 -> V_211 = V_16 ;
V_16 -> V_18 = NULL ;
V_16 -> V_196 = V_212 | V_198 | V_213 ;
V_16 -> V_201 = 4 ;
V_16 -> V_202 = 4 ;
V_16 -> V_207 = 0x00ff ;
V_16 -> V_208 = & V_214 ;
V_16 -> V_204 = F_55 ;
V_16 -> V_205 = F_56 ;
V_16 -> V_206 = F_19 ;
V_16 -> V_203 = F_52 ;
V_16 -> V_215 = F_53 ;
V_16 = & V_8 -> V_28 [ V_216 ] ;
V_16 -> type = V_217 ;
V_16 -> V_196 = V_197 | V_212 ;
V_16 -> V_201 = 24 ;
V_16 -> V_207 = 1 ;
V_16 -> V_208 = ( & V_218 ) ;
V_16 -> V_219 = F_59 ;
V_16 -> V_220 = F_58 ;
V_16 -> V_18 = NULL ;
if ( V_192 -> V_72 ) {
V_16 = & V_8 -> V_28 [ V_221 ] ;
V_16 -> type = V_222 ;
V_16 -> V_196 = V_212 | V_223 ;
V_16 -> V_201 = 8 ;
V_16 -> V_207 = V_192 -> V_164 ;
V_16 -> V_215 = F_69 ;
V_16 -> V_203 = F_70 ;
V_16 -> V_220 = F_71 ;
F_66 ( V_8 , V_16 , V_224 ) ;
}
V_192 -> V_225 = 1 ;
F_8 ( & V_192 -> V_19 ) ;
V_76 = F_51 ( V_8 , 0 ) ;
if ( V_76 < 0 )
F_11 ( & V_192 -> V_7 -> V_8 ,
L_90 ) ;
F_77 ( & V_192 -> V_7 -> V_8 ,
L_91 , V_8 -> V_36 , V_76 ) ;
return 0 ;
}
static int F_78 ( struct V_14 * V_8 ,
unsigned long V_226 )
{
struct V_227 * V_228 = F_79 ( V_8 ) ;
int V_11 ;
struct V_1 * V_192 ;
V_8 -> V_18 = NULL ;
F_7 ( & V_229 ) ;
V_192 = F_80 ( V_228 ) ;
if ( ! V_192 || ! V_192 -> V_20 ) {
F_11 ( V_8 -> V_230 ,
L_92 ) ;
V_11 = - V_21 ;
} else if ( V_192 -> V_225 ) {
F_11 ( V_8 -> V_230 ,
L_93 ) ;
V_11 = - V_21 ;
} else
V_11 = F_75 ( V_8 , V_192 ) ;
F_8 ( & V_229 ) ;
return V_11 ;
}
static void F_81 ( struct V_14 * V_8 )
{
struct V_1 * V_231 = V_8 -> V_18 ;
if ( V_231 ) {
F_7 ( & V_231 -> V_19 ) ;
V_8 -> V_18 = NULL ;
V_231 -> V_225 = 0 ;
V_231 -> V_35 = NULL ;
F_8 ( & V_231 -> V_19 ) ;
}
}
static void F_82 ( const struct V_232 * V_233 ,
void * V_27 )
{
struct V_1 * V_2 = V_27 ;
struct V_227 * V_228 = V_2 -> V_7 ;
int V_11 ;
if ( V_233 == NULL ) {
F_11 ( & V_228 -> V_8 ,
L_94 ) ;
return;
}
V_11 = F_29 ( V_2 , V_233 -> V_141 , V_233 -> V_234 ) ;
if ( V_11 ) {
F_11 ( & V_228 -> V_8 ,
L_95 , V_11 ) ;
goto V_148;
}
F_83 ( V_228 , & V_235 , 0 ) ;
V_148:
F_84 ( V_233 ) ;
}
static int F_85 ( struct V_227 * V_228 ,
const struct V_236 * V_237 )
{
struct V_238 * V_239 = F_86 ( V_228 ) ;
struct V_240 * V_8 = & V_228 -> V_8 ;
int V_3 ;
int V_241 ;
int V_11 ;
F_3 ( V_8 , L_96
L_97 ) ;
F_7 ( & V_229 ) ;
V_241 = - 1 ;
for ( V_3 = 0 ; V_3 < V_242 ; V_3 ++ ) {
if ( ! ( V_1 [ V_3 ] . V_20 ) ) {
V_241 = V_3 ;
break;
}
}
if ( V_241 == - 1 ) {
F_11 ( V_8 , L_98 ) ;
F_8 ( & V_229 ) ;
return - V_243 ;
}
F_3 ( V_8 , L_99
L_100 , V_241 ) ;
F_87 ( & ( V_1 [ V_241 ] . V_19 ) , 1 ) ;
V_1 [ V_241 ] . V_45 = V_239 ;
V_1 [ V_241 ] . V_7 = V_228 ;
V_1 [ V_241 ] . V_244 = V_228 -> V_245 -> V_246 . V_247 ;
F_73 ( V_228 , & ( V_1 [ V_241 ] ) ) ;
F_3 ( V_8 , L_101 , V_1 [ V_241 ] . V_244 ) ;
V_1 [ V_241 ] . V_72 =
( V_1 [ V_241 ] . V_45 -> V_248 == V_249 ) ;
V_1 [ V_241 ] . V_68 = F_88 ( V_67 , V_80 ) ;
if ( ! V_1 [ V_241 ] . V_68 ) {
F_72 ( & ( V_1 [ V_241 ] ) ) ;
F_8 ( & V_229 ) ;
return - V_81 ;
}
V_1 [ V_241 ] . V_120 = F_88 ( V_122 , V_80 ) ;
if ( ! V_1 [ V_241 ] . V_120 ) {
F_72 ( & ( V_1 [ V_241 ] ) ) ;
F_8 ( & V_229 ) ;
return - V_81 ;
}
V_1 [ V_241 ] . V_31 = F_88 ( V_33 , V_80 ) ;
if ( ! ( V_1 [ V_241 ] . V_31 ) ) {
F_72 ( & ( V_1 [ V_241 ] ) ) ;
F_8 ( & V_229 ) ;
return - V_81 ;
}
V_1 [ V_241 ] . V_128 = F_88 ( V_129 , V_80 ) ;
if ( ! ( V_1 [ V_241 ] . V_128 ) ) {
F_72 ( & ( V_1 [ V_241 ] ) ) ;
F_8 ( & V_229 ) ;
return - V_81 ;
}
V_1 [ V_241 ] . V_146 = F_88 ( V_71 , V_80 ) ;
if ( ! ( V_1 [ V_241 ] . V_146 ) ) {
F_72 ( & ( V_1 [ V_241 ] ) ) ;
F_8 ( & V_229 ) ;
return - V_81 ;
}
V_3 = F_89 ( V_1 [ V_241 ] . V_45 ,
V_1 [ V_241 ] . V_244 , 3 ) ;
if ( V_3 < 0 ) {
F_11 ( V_8 , L_102
L_103 ,
V_241 ) ;
F_72 ( & ( V_1 [ V_241 ] ) ) ;
F_8 ( & V_229 ) ;
return - V_21 ;
}
if ( V_1 [ V_241 ] . V_72 )
V_1 [ V_241 ] . V_6 = V_250 ;
else
V_1 [ V_241 ] . V_6 = V_251 ;
V_1 [ V_241 ] . V_5 = F_90 ( V_1 [ V_241 ] . V_6 ,
sizeof( struct V_22 * ) ,
V_80 ) ;
if ( ! ( V_1 [ V_241 ] . V_5 ) ) {
F_72 ( & ( V_1 [ V_241 ] ) ) ;
F_8 ( & V_229 ) ;
return - V_81 ;
}
for ( V_3 = 0 ; V_3 < V_1 [ V_241 ] . V_6 ; V_3 ++ ) {
V_1 [ V_241 ] . V_5 [ V_3 ] = F_91 ( 1 , V_80 ) ;
if ( V_1 [ V_241 ] . V_5 [ V_3 ] == NULL ) {
F_11 ( V_8 , L_102
L_104 , V_241 , V_3 ) ;
F_72 ( & ( V_1 [ V_241 ] ) ) ;
F_8 ( & V_229 ) ;
return - V_81 ;
}
V_1 [ V_241 ] . V_5 [ V_3 ] -> V_8 = V_1 [ V_241 ] . V_45 ;
V_1 [ V_241 ] . V_5 [ V_3 ] -> V_27 = NULL ;
V_1 [ V_241 ] . V_5 [ V_3 ] -> V_252 =
F_92 ( V_1 [ V_241 ] . V_45 , V_253 ) ;
V_1 [ V_241 ] . V_5 [ V_3 ] -> V_94 = V_95 ;
V_1 [ V_241 ] . V_5 [ V_3 ] -> V_32 =
F_88 ( V_33 , V_80 ) ;
if ( ! ( V_1 [ V_241 ] . V_5 [ V_3 ] -> V_32 ) ) {
F_72 ( & ( V_1 [ V_241 ] ) ) ;
F_8 ( & V_229 ) ;
return - V_81 ;
}
V_1 [ V_241 ] . V_5 [ V_3 ] -> V_254 = F_9 ;
V_1 [ V_241 ] . V_5 [ V_3 ] -> V_74 = 1 ;
V_1 [ V_241 ] . V_5 [ V_3 ] -> V_70 = V_33 ;
V_1 [ V_241 ] . V_5 [ V_3 ] -> V_75 [ 0 ] . V_76 = 0 ;
V_1 [ V_241 ] . V_5 [ V_3 ] -> V_75 [ 0 ] . V_77 =
V_33 ;
}
if ( V_1 [ V_241 ] . V_72 )
V_1 [ V_241 ] . V_58 = V_255 ;
else
V_1 [ V_241 ] . V_58 = V_256 ;
V_1 [ V_241 ] . V_57 = F_90 ( V_1 [ V_241 ] . V_58 ,
sizeof( struct V_22 * ) , V_80 ) ;
if ( ! ( V_1 [ V_241 ] . V_57 ) ) {
F_72 ( & ( V_1 [ V_241 ] ) ) ;
F_8 ( & V_229 ) ;
return - V_81 ;
}
for ( V_3 = 0 ; V_3 < V_1 [ V_241 ] . V_58 ; V_3 ++ ) {
V_1 [ V_241 ] . V_57 [ V_3 ] = F_91 ( 1 , V_80 ) ;
if ( V_1 [ V_241 ] . V_57 [ V_3 ] == NULL ) {
F_11 ( V_8 , L_102
L_104 , V_241 , V_3 ) ;
F_72 ( & ( V_1 [ V_241 ] ) ) ;
F_8 ( & V_229 ) ;
return - V_81 ;
}
V_1 [ V_241 ] . V_57 [ V_3 ] -> V_8 = V_1 [ V_241 ] . V_45 ;
V_1 [ V_241 ] . V_57 [ V_3 ] -> V_27 = NULL ;
V_1 [ V_241 ] . V_57 [ V_3 ] -> V_252 =
F_93 ( V_1 [ V_241 ] . V_45 , V_257 ) ;
V_1 [ V_241 ] . V_57 [ V_3 ] -> V_94 = V_95 ;
V_1 [ V_241 ] . V_57 [ V_3 ] -> V_32 =
F_88 ( V_71 , V_80 ) ;
if ( ! ( V_1 [ V_241 ] . V_57 [ V_3 ] -> V_32 ) ) {
F_72 ( & ( V_1 [ V_241 ] ) ) ;
F_8 ( & V_229 ) ;
return - V_81 ;
}
V_1 [ V_241 ] . V_57 [ V_3 ] -> V_254 = F_20 ;
V_1 [ V_241 ] . V_57 [ V_3 ] -> V_74 = 1 ;
V_1 [ V_241 ] . V_57 [ V_3 ] -> V_70 =
V_71 ;
V_1 [ V_241 ] . V_57 [ V_3 ] -> V_75 [ 0 ] . V_76 = 0 ;
V_1 [ V_241 ] . V_57 [ V_3 ] -> V_75 [ 0 ] . V_77 =
V_71 ;
if ( V_1 [ V_241 ] . V_72 ) {
V_1 [ V_241 ] . V_57 [ V_3 ] -> V_73 = 8 ;
} else {
V_1 [ V_241 ] . V_57 [ V_3 ] -> V_73 = 1 ;
}
}
if ( V_1 [ V_241 ] . V_72 ) {
V_1 [ V_241 ] . V_164 = 512 ;
V_1 [ V_241 ] . V_161 = F_91 ( 0 , V_80 ) ;
if ( V_1 [ V_241 ] . V_161 == NULL ) {
F_11 ( V_8 , L_102
L_105 , V_241 ) ;
F_72 ( & ( V_1 [ V_241 ] ) ) ;
F_8 ( & V_229 ) ;
return - V_81 ;
}
V_1 [ V_241 ] . V_161 -> V_32 =
F_88 ( V_1 [ V_241 ] . V_164 , V_80 ) ;
if ( ! ( V_1 [ V_241 ] . V_161 -> V_32 ) ) {
F_72 ( & ( V_1 [ V_241 ] ) ) ;
F_8 ( & V_229 ) ;
return - V_81 ;
}
} else {
V_1 [ V_241 ] . V_161 = NULL ;
V_1 [ V_241 ] . V_164 = 0 ;
}
V_1 [ V_241 ] . V_13 = 0 ;
V_1 [ V_241 ] . V_59 = 0 ;
V_1 [ V_241 ] . V_162 = 0 ;
V_1 [ V_241 ] . V_20 = 1 ;
F_8 ( & V_229 ) ;
V_11 = F_94 ( V_258 ,
V_259 ,
V_260 ,
& V_239 -> V_8 ,
V_80 ,
V_1 + V_241 ,
F_82
) ;
if ( V_11 ) {
F_11 ( V_8 , L_106 , V_11 ) ;
return V_11 ;
}
F_77 ( V_8 , L_107 ) ;
return 0 ;
}
static void F_95 ( struct V_227 * V_261 )
{
struct V_1 * V_2 = F_80 ( V_261 ) ;
struct V_238 * V_239 = F_86 ( V_261 ) ;
if ( ! V_2 ) {
F_11 ( & V_261 -> V_8 ,
L_108 ) ;
return;
}
if ( V_2 -> V_45 != V_239 ) {
F_11 ( & V_261 -> V_8 , L_109 ) ;
return;
}
if ( V_2 -> V_13 )
F_4 ( V_2 , 1 ) ;
if ( V_2 -> V_59 )
F_18 ( V_2 , 1 ) ;
F_96 ( V_261 ) ;
F_7 ( & V_229 ) ;
F_7 ( & V_2 -> V_19 ) ;
F_72 ( V_2 ) ;
F_8 ( & V_2 -> V_19 ) ;
F_8 ( & V_229 ) ;
F_77 ( & V_261 -> V_8 , L_110 ) ;
}

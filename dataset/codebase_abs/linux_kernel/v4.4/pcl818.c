static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_11 * V_12 = & V_10 -> V_12 [ V_10 -> V_13 ] ;
unsigned int V_14 = F_2 ( V_4 , V_12 -> V_15 ) ;
unsigned int V_16 ;
F_3 ( V_10 -> V_17 ) ;
V_16 = F_4 ( V_4 , V_14 + V_5 ) ;
if ( V_16 > V_5 ) {
V_16 -= V_5 ;
V_12 -> V_18 = F_5 ( V_4 , V_16 ) ;
F_6 ( V_12 ) ;
}
}
static void F_7 ( struct V_1 * V_2 ,
unsigned int V_17 ,
unsigned int V_19 )
{
F_8 ( V_17 , V_2 -> V_20 + V_21 ) ;
F_8 ( V_19 , V_2 -> V_20 + V_22 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
unsigned int V_23 ,
unsigned int V_24 )
{
F_8 ( F_10 ( V_23 , V_24 ) ,
V_2 -> V_20 + V_21 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
unsigned int * V_25 ,
unsigned int V_26 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned int V_23 = F_12 ( V_25 [ 0 ] ) ;
unsigned int V_24 ;
unsigned int V_19 ;
int V_27 ;
V_7 -> V_28 = V_26 ;
V_7 -> V_29 = 0 ;
for ( V_27 = 0 ; V_27 < V_26 ; V_27 ++ ) {
V_24 = F_12 ( V_25 [ V_27 ] ) ;
V_19 = F_13 ( V_25 [ V_27 ] ) ;
V_7 -> V_30 [ V_27 ] = V_24 ;
F_7 ( V_2 , V_24 , V_19 ) ;
}
F_14 ( 1 ) ;
F_9 ( V_2 , V_23 , V_24 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_8 ( 0 , V_2 -> V_20 + V_31 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_8 ( 0 , V_2 -> V_20 + V_32 ) ;
}
static unsigned int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int * V_17 )
{
unsigned int V_33 ;
V_33 = F_18 ( V_2 -> V_20 + V_34 ) ;
V_33 |= ( F_18 ( V_2 -> V_20 + V_35 ) << 8 ) ;
if ( V_17 )
* V_17 = V_33 & 0xf ;
return ( V_33 >> 4 ) & V_4 -> V_36 ;
}
static unsigned int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int * V_17 )
{
unsigned int V_33 ;
V_33 = F_18 ( V_2 -> V_20 + V_37 ) << 8 ;
V_33 |= F_18 ( V_2 -> V_20 + V_32 ) ;
if ( V_17 )
* V_17 = V_33 & 0xf ;
return ( V_33 >> 4 ) & V_4 -> V_36 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_38 * V_39 ,
unsigned long V_40 )
{
unsigned int V_41 ;
V_41 = F_18 ( V_2 -> V_20 + V_31 ) ;
if ( V_41 & V_42 )
return 0 ;
return - V_43 ;
}
static bool F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_17 , unsigned int V_33 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_44 * V_45 = & V_4 -> V_46 -> V_45 ;
unsigned int V_47 ;
V_47 = V_7 -> V_30 [ V_7 -> V_29 ] ;
if ( V_17 != V_47 ) {
F_22 ( V_2 -> V_48 ,
L_1 ,
( V_7 -> V_10 ) ? L_2 :
( V_7 -> V_49 ) ? L_3 : L_4 ,
V_17 , V_47 ) ;
V_4 -> V_46 -> V_50 |= V_51 ;
return false ;
}
F_23 ( V_4 , & V_33 , 1 ) ;
V_7 -> V_29 ++ ;
if ( V_7 -> V_29 >= V_7 -> V_28 )
V_7 -> V_29 = 0 ;
if ( V_45 -> V_52 == V_53 &&
V_4 -> V_46 -> V_54 >= V_45 -> V_55 ) {
V_4 -> V_46 -> V_50 |= V_56 ;
return false ;
}
return true ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_17 ;
unsigned int V_33 ;
if ( F_20 ( V_2 , V_4 , NULL , 0 ) ) {
F_25 ( V_2 -> V_48 , L_5 ) ;
V_4 -> V_46 -> V_50 |= V_51 ;
return;
}
V_33 = F_19 ( V_2 , V_4 , & V_17 ) ;
F_21 ( V_2 , V_4 , V_17 , V_33 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_11 * V_12 = & V_10 -> V_12 [ V_10 -> V_13 ] ;
unsigned short * V_57 = V_12 -> V_58 ;
unsigned int V_16 = F_2 ( V_4 , V_12 -> V_18 ) ;
unsigned int V_17 ;
unsigned int V_33 ;
int V_27 ;
V_10 -> V_13 = 1 - V_10 -> V_13 ;
F_1 ( V_2 , V_4 , V_16 ) ;
for ( V_27 = 0 ; V_27 < V_16 ; V_27 ++ ) {
V_33 = V_57 [ V_27 ] ;
V_17 = V_33 & 0xf ;
V_33 = ( V_33 >> 4 ) & V_4 -> V_36 ;
if ( ! F_21 ( V_2 , V_4 , V_17 , V_33 ) )
break;
}
}
static void F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_41 ;
unsigned int V_17 ;
unsigned int V_33 ;
int V_27 , V_59 ;
V_41 = F_18 ( V_2 -> V_20 + V_60 ) ;
if ( V_41 & 4 ) {
F_25 ( V_2 -> V_48 , L_6 ) ;
V_4 -> V_46 -> V_50 |= V_51 ;
return;
}
if ( V_41 & 1 ) {
F_25 ( V_2 -> V_48 ,
L_7 ) ;
V_4 -> V_46 -> V_50 |= V_51 ;
return;
}
if ( V_41 & 2 )
V_59 = 512 ;
else
V_59 = 0 ;
for ( V_27 = 0 ; V_27 < V_59 ; V_27 ++ ) {
V_33 = F_17 ( V_2 , V_4 , & V_17 ) ;
if ( ! F_21 ( V_2 , V_4 , V_17 , V_33 ) )
break;
}
}
static T_1 F_28 ( int V_61 , void * V_62 )
{
struct V_1 * V_2 = V_62 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_3 * V_4 = V_2 -> V_63 ;
struct V_44 * V_45 = & V_4 -> V_46 -> V_45 ;
if ( ! V_2 -> V_64 || ! V_7 -> V_65 ) {
F_15 ( V_2 ) ;
return V_66 ;
}
if ( V_7 -> V_67 ) {
V_4 -> V_46 -> V_54 = V_45 -> V_55 ;
V_4 -> V_68 ( V_2 , V_4 ) ;
return V_66 ;
}
if ( V_7 -> V_10 )
F_26 ( V_2 , V_4 ) ;
else if ( V_7 -> V_49 )
F_27 ( V_2 , V_4 ) ;
else
F_24 ( V_2 , V_4 ) ;
F_15 ( V_2 ) ;
F_29 ( V_2 , V_4 ) ;
return V_66 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int * V_25 , unsigned int V_69 )
{
unsigned int V_70 [ 16 ] ;
unsigned int V_27 , V_71 , V_26 , V_72 ;
if ( V_69 < 1 ) {
F_25 ( V_2 -> V_48 , L_8 ) ;
return 0 ;
}
if ( V_69 > 1 ) {
V_70 [ 0 ] = V_25 [ 0 ] ;
for ( V_27 = 1 , V_26 = 1 ; V_27 < V_69 ; V_27 ++ , V_26 ++ ) {
if ( V_25 [ 0 ] == V_25 [ V_27 ] )
break;
V_71 =
( F_12 ( V_70 [ V_27 - 1 ] ) + 1 ) % V_4 -> V_69 ;
if ( V_71 != F_12 ( V_25 [ V_27 ] ) ) {
F_22 ( V_2 -> V_48 ,
L_9 ,
V_27 , F_12 ( V_25 [ V_27 ] ) , V_71 ,
F_12 ( V_25 [ 0 ] ) ) ;
return 0 ;
}
V_70 [ V_27 ] = V_25 [ V_27 ] ;
}
for ( V_27 = 0 , V_72 = 0 ; V_27 < V_69 ; V_27 ++ ) {
if ( V_25 [ V_27 ] != V_70 [ V_27 % V_26 ] ) {
F_22 ( V_2 -> V_48 ,
L_10 ,
V_27 , F_12 ( V_70 [ V_27 ] ) ,
F_13 ( V_70 [ V_27 ] ) ,
F_31 ( V_70 [ V_27 ] ) ,
F_12 ( V_25 [ V_27 % V_26 ] ) ,
F_13 ( V_25 [ V_27 % V_26 ] ) ,
F_31 ( V_70 [ V_27 % V_26 ] ) ) ;
return 0 ;
}
}
} else {
V_26 = 1 ;
}
return V_26 ;
}
static int F_32 ( unsigned int V_73 )
{
if ( F_18 ( V_73 + V_31 ) & V_74 )
return 1 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_44 * V_45 )
{
const struct V_75 * V_76 = V_2 -> V_77 ;
int V_78 = 0 ;
V_78 |= F_34 ( & V_45 -> V_79 , V_80 ) ;
V_78 |= F_34 ( & V_45 -> V_81 , V_82 ) ;
V_78 |= F_34 ( & V_45 -> V_83 ,
V_84 | V_85 ) ;
V_78 |= F_34 ( & V_45 -> V_86 , V_53 ) ;
V_78 |= F_34 ( & V_45 -> V_52 , V_53 | V_87 ) ;
if ( V_78 )
return 1 ;
V_78 |= F_35 ( V_45 -> V_83 ) ;
V_78 |= F_35 ( V_45 -> V_52 ) ;
if ( V_78 )
return 2 ;
V_78 |= F_36 ( & V_45 -> V_88 , 0 ) ;
V_78 |= F_36 ( & V_45 -> V_89 , 0 ) ;
if ( V_45 -> V_83 == V_84 ) {
V_78 |= F_37 ( & V_45 -> V_90 ,
V_76 -> V_91 ) ;
} else {
V_78 |= F_36 ( & V_45 -> V_90 , 0 ) ;
}
V_78 |= F_36 ( & V_45 -> V_92 ,
V_45 -> V_93 ) ;
if ( V_45 -> V_52 == V_53 )
V_78 |= F_37 ( & V_45 -> V_55 , 1 ) ;
else
V_78 |= F_36 ( & V_45 -> V_55 , 0 ) ;
if ( V_78 )
return 3 ;
if ( V_45 -> V_83 == V_84 ) {
unsigned int V_94 = V_45 -> V_90 ;
F_38 ( V_2 -> V_95 , & V_94 , V_45 -> V_96 ) ;
V_78 |= F_36 ( & V_45 -> V_90 , V_94 ) ;
}
if ( V_78 )
return 4 ;
if ( V_45 -> V_25 ) {
if ( ! F_30 ( V_2 , V_4 , V_45 -> V_25 ,
V_45 -> V_93 ) )
return 5 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_44 * V_45 = & V_4 -> V_46 -> V_45 ;
unsigned int V_97 = 0 ;
unsigned int V_26 ;
if ( V_7 -> V_65 )
return - V_43 ;
V_26 = F_30 ( V_2 , V_4 , V_45 -> V_25 , V_45 -> V_93 ) ;
if ( V_26 < 1 )
return - V_98 ;
F_11 ( V_2 , V_45 -> V_25 , V_26 ) ;
V_7 -> V_65 = 1 ;
V_7 -> V_67 = 0 ;
V_7 -> V_29 = 0 ;
if ( V_45 -> V_83 == V_84 )
V_97 |= V_99 ;
else
V_97 |= V_100 ;
F_8 ( 0 , V_2 -> V_20 + V_101 ) ;
if ( V_10 ) {
V_10 -> V_13 = 0 ;
F_1 ( V_2 , V_4 , 0 ) ;
V_97 |= V_102 | F_40 ( V_2 -> V_61 ) |
V_103 ;
} else if ( V_7 -> V_49 ) {
F_8 ( 1 , V_2 -> V_20 + V_104 ) ;
} else {
V_97 |= V_102 | F_40 ( V_2 -> V_61 ) ;
}
F_8 ( V_97 , V_2 -> V_20 + V_105 ) ;
if ( V_45 -> V_83 == V_84 ) {
F_41 ( V_2 -> V_95 ) ;
F_42 ( V_2 -> V_95 , 1 , 2 , true ) ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_44 * V_45 = & V_4 -> V_46 -> V_45 ;
if ( ! V_7 -> V_65 )
return 0 ;
if ( V_10 ) {
if ( V_45 -> V_52 == V_87 ||
( V_45 -> V_52 == V_53 &&
V_4 -> V_46 -> V_54 < V_45 -> V_55 ) ) {
if ( ! V_7 -> V_67 ) {
V_7 -> V_67 = 1 ;
return 0 ;
}
}
F_3 ( V_10 -> V_17 ) ;
}
F_8 ( V_106 , V_2 -> V_20 + V_105 ) ;
F_42 ( V_2 -> V_95 , 1 , 2 , false ) ;
F_15 ( V_2 ) ;
if ( V_7 -> V_49 ) {
F_8 ( 0 , V_2 -> V_20 + V_107 ) ;
F_8 ( 0 , V_2 -> V_20 + V_108 ) ;
F_8 ( 0 , V_2 -> V_20 + V_104 ) ;
}
V_7 -> V_65 = 0 ;
V_7 -> V_67 = 0 ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_38 * V_39 ,
unsigned int * V_109 )
{
unsigned int V_17 = F_12 ( V_39 -> V_110 ) ;
unsigned int V_19 = F_13 ( V_39 -> V_110 ) ;
int V_111 = 0 ;
int V_27 ;
F_8 ( V_112 , V_2 -> V_20 + V_105 ) ;
F_7 ( V_2 , V_17 , V_19 ) ;
F_9 ( V_2 , V_17 , V_17 ) ;
for ( V_27 = 0 ; V_27 < V_39 -> V_113 ; V_27 ++ ) {
F_15 ( V_2 ) ;
F_16 ( V_2 ) ;
V_111 = F_45 ( V_2 , V_4 , V_39 , F_20 , 0 ) ;
if ( V_111 )
break;
V_109 [ V_27 ] = F_19 ( V_2 , V_4 , NULL ) ;
}
F_15 ( V_2 ) ;
return V_111 ? V_111 : V_39 -> V_113 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_38 * V_39 ,
unsigned int * V_109 )
{
unsigned int V_17 = F_12 ( V_39 -> V_110 ) ;
unsigned int V_33 = V_4 -> V_114 [ V_17 ] ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_39 -> V_113 ; V_27 ++ ) {
V_33 = V_109 [ V_27 ] ;
F_8 ( ( V_33 & 0x000f ) << 4 ,
V_2 -> V_20 + F_47 ( V_17 ) ) ;
F_8 ( ( V_33 & 0x0ff0 ) >> 4 ,
V_2 -> V_20 + F_48 ( V_17 ) ) ;
}
V_4 -> V_114 [ V_17 ] = V_33 ;
return V_39 -> V_113 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_38 * V_39 ,
unsigned int * V_109 )
{
V_109 [ 1 ] = F_18 ( V_2 -> V_20 + V_115 ) |
( F_18 ( V_2 -> V_20 + V_116 ) << 8 ) ;
return V_39 -> V_113 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_38 * V_39 ,
unsigned int * V_109 )
{
if ( F_51 ( V_4 , V_109 ) ) {
F_8 ( V_4 -> V_117 & 0xff , V_2 -> V_20 + V_115 ) ;
F_8 ( ( V_4 -> V_117 >> 8 ) , V_2 -> V_20 + V_116 ) ;
}
V_109 [ 1 ] = V_4 -> V_117 ;
return V_39 -> V_113 ;
}
static void F_52 ( struct V_1 * V_2 )
{
const struct V_75 * V_76 = V_2 -> V_77 ;
unsigned int V_17 ;
if ( V_76 -> V_118 ) {
F_8 ( 0 , V_2 -> V_20 + V_107 ) ;
F_8 ( 0 , V_2 -> V_20 + V_108 ) ;
F_8 ( 0 , V_2 -> V_20 + V_104 ) ;
}
F_8 ( V_106 , V_2 -> V_20 + V_105 ) ;
F_15 ( V_2 ) ;
F_7 ( V_2 , 0 , 0 ) ;
F_8 ( 0 , V_2 -> V_20 + V_101 ) ;
for ( V_17 = 0 ; V_17 < V_76 -> V_119 ; V_17 ++ ) {
F_8 ( 0 , V_2 -> V_20 + F_47 ( V_17 ) ) ;
F_8 ( 0 , V_2 -> V_20 + F_48 ( V_17 ) ) ;
}
F_8 ( 0 , V_2 -> V_20 + V_116 ) ;
F_8 ( 0 , V_2 -> V_20 + V_115 ) ;
}
static void F_53 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_120 * V_121 )
{
const struct V_75 * V_76 = V_2 -> V_77 ;
V_4 -> V_122 = V_76 -> V_123 ;
if ( V_76 -> V_124 ) {
if ( V_121 -> V_125 [ 4 ] == 1 || V_121 -> V_125 [ 4 ] == 10 ) {
V_4 -> V_122 = & V_126 ;
}
} else {
switch ( V_121 -> V_125 [ 4 ] ) {
case 0 :
V_4 -> V_122 = & V_127 ;
break;
case 1 :
V_4 -> V_122 = & V_128 ;
break;
case 2 :
V_4 -> V_122 = & V_129 ;
break;
case 3 :
V_4 -> V_122 = & V_130 ;
break;
case 4 :
V_4 -> V_122 = & V_131 ;
break;
case 6 :
V_4 -> V_122 = & V_132 ;
break;
case 7 :
V_4 -> V_122 = & V_133 ;
break;
case 8 :
V_4 -> V_122 = & V_134 ;
break;
case 9 :
V_4 -> V_122 = & V_135 ;
break;
default:
V_4 -> V_122 = & V_136 ;
break;
}
}
}
static void F_54 ( struct V_1 * V_2 , unsigned int V_137 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
if ( ! ( V_137 == 3 || V_137 == 1 ) )
return;
V_7 -> V_10 = F_55 ( V_2 , 2 , V_137 , V_137 ,
V_138 * 4 , V_139 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
if ( V_7 )
F_57 ( V_7 -> V_10 ) ;
}
static int F_58 ( struct V_1 * V_2 , struct V_120 * V_121 )
{
const struct V_75 * V_76 = V_2 -> V_77 ;
struct V_6 * V_7 ;
struct V_3 * V_4 ;
unsigned int V_140 ;
int V_111 ;
V_7 = F_59 ( V_2 , sizeof( * V_7 ) ) ;
if ( ! V_7 )
return - V_141 ;
V_111 = F_60 ( V_2 , V_121 -> V_125 [ 0 ] ,
V_76 -> V_118 ? 0x20 : 0x10 ) ;
if ( V_111 )
return V_111 ;
if ( V_121 -> V_125 [ 1 ] >= 2 && V_121 -> V_125 [ 1 ] <= 7 ) {
V_111 = F_61 ( V_121 -> V_125 [ 1 ] , F_28 , 0 ,
V_2 -> V_142 , V_2 ) ;
if ( V_111 == 0 )
V_2 -> V_61 = V_121 -> V_125 [ 1 ] ;
}
if ( V_2 -> V_61 && V_76 -> V_118 && V_121 -> V_125 [ 2 ] == - 1 )
V_7 -> V_49 = 1 ;
if ( V_2 -> V_61 && V_76 -> V_143 )
F_54 ( V_2 , V_121 -> V_125 [ 2 ] ) ;
if ( ( V_121 -> V_125 [ 3 ] == 0 ) || ( V_121 -> V_125 [ 3 ] == 10 ) )
V_140 = V_144 ;
else
V_140 = V_145 ;
V_2 -> V_95 = F_62 ( V_2 -> V_20 + V_146 ,
V_140 , V_147 , 0 ) ;
if ( ! V_2 -> V_95 )
return - V_141 ;
V_7 -> V_91 = V_76 -> V_91 ;
if ( ! V_76 -> V_124 ) {
if ( ( V_121 -> V_125 [ 6 ] == 1 ) || ( V_121 -> V_125 [ 6 ] == 100 ) )
V_7 -> V_91 = 10000 ;
}
V_111 = F_63 ( V_2 , 4 ) ;
if ( V_111 )
return V_111 ;
V_4 = & V_2 -> V_148 [ 0 ] ;
V_4 -> type = V_149 ;
V_4 -> V_150 = V_151 ;
if ( F_32 ( V_2 -> V_20 ) ) {
V_4 -> V_69 = 16 ;
V_4 -> V_150 |= V_152 | V_153 ;
} else {
V_4 -> V_69 = 8 ;
V_4 -> V_150 |= V_154 ;
}
V_4 -> V_36 = 0x0fff ;
F_53 ( V_2 , V_4 , V_121 ) ;
V_4 -> V_155 = F_44 ;
if ( V_2 -> V_61 ) {
V_2 -> V_63 = V_4 ;
V_4 -> V_150 |= V_156 ;
V_4 -> V_157 = V_4 -> V_69 ;
V_4 -> V_158 = F_33 ;
V_4 -> V_159 = F_39 ;
V_4 -> V_68 = F_43 ;
}
V_4 = & V_2 -> V_148 [ 1 ] ;
if ( V_76 -> V_119 ) {
V_4 -> type = V_160 ;
V_4 -> V_150 = V_161 | V_153 ;
V_4 -> V_69 = V_76 -> V_119 ;
V_4 -> V_36 = 0x0fff ;
V_4 -> V_122 = & V_133 ;
if ( V_76 -> V_124 ) {
if ( ( V_121 -> V_125 [ 4 ] == 1 ) || ( V_121 -> V_125 [ 4 ] == 10 ) )
V_4 -> V_122 = & V_132 ;
if ( V_121 -> V_125 [ 4 ] == 2 )
V_4 -> V_122 = & V_136 ;
} else {
if ( ( V_121 -> V_125 [ 5 ] == 1 ) || ( V_121 -> V_125 [ 5 ] == 10 ) )
V_4 -> V_122 = & V_132 ;
if ( V_121 -> V_125 [ 5 ] == 2 )
V_4 -> V_122 = & V_136 ;
}
V_4 -> V_162 = F_46 ;
V_111 = F_64 ( V_4 ) ;
if ( V_111 )
return V_111 ;
} else {
V_4 -> type = V_163 ;
}
V_4 = & V_2 -> V_148 [ 2 ] ;
V_4 -> type = V_164 ;
V_4 -> V_150 = V_151 ;
V_4 -> V_69 = 16 ;
V_4 -> V_36 = 1 ;
V_4 -> V_122 = & V_165 ;
V_4 -> V_166 = F_49 ;
V_4 = & V_2 -> V_148 [ 3 ] ;
V_4 -> type = V_167 ;
V_4 -> V_150 = V_161 ;
V_4 -> V_69 = 16 ;
V_4 -> V_36 = 1 ;
V_4 -> V_122 = & V_165 ;
V_4 -> V_166 = F_50 ;
F_52 ( V_2 ) ;
return 0 ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
if ( V_7 ) {
F_43 ( V_2 , V_2 -> V_63 ) ;
F_52 ( V_2 ) ;
}
F_56 ( V_2 ) ;
F_66 ( V_2 ) ;
}

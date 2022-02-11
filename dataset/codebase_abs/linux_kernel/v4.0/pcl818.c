static void F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_7 = V_2 -> V_8 + V_9 ;
F_2 ( V_7 , 0 , 2 , V_10 | V_11 ) ;
F_2 ( V_7 , 0 , 1 , V_10 | V_11 ) ;
F_3 ( 1 ) ;
if ( V_3 ) {
F_4 ( V_7 , 0 , 2 , V_5 -> V_12 ) ;
F_4 ( V_7 , 0 , 1 , V_5 -> V_13 ) ;
}
}
static void F_5 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
unsigned int V_16 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_17 * V_18 = V_5 -> V_18 ;
struct V_19 * V_20 = & V_18 -> V_20 [ V_18 -> V_21 ] ;
unsigned int V_22 = F_6 ( V_15 , V_20 -> V_23 ) ;
unsigned int V_24 ;
F_7 ( V_18 -> V_25 ) ;
V_24 = F_8 ( V_15 , V_22 + V_16 ) ;
if ( V_24 > V_16 ) {
V_24 -= V_16 ;
V_20 -> V_26 = F_9 ( V_15 , V_24 ) ;
F_10 ( V_20 ) ;
}
}
static void F_11 ( struct V_1 * V_2 ,
unsigned int V_25 ,
unsigned int V_27 )
{
F_12 ( V_25 , V_2 -> V_8 + V_28 ) ;
F_12 ( V_27 , V_2 -> V_8 + V_29 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
unsigned int V_30 ,
unsigned int V_31 )
{
F_12 ( F_14 ( V_30 , V_31 ) ,
V_2 -> V_8 + V_28 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
unsigned int * V_32 ,
unsigned int V_33 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_30 = F_16 ( V_32 [ 0 ] ) ;
unsigned int V_31 ;
unsigned int V_27 ;
int V_34 ;
V_5 -> V_35 = V_33 ;
V_5 -> V_36 = 0 ;
for ( V_34 = 0 ; V_34 < V_33 ; V_34 ++ ) {
V_31 = F_16 ( V_32 [ V_34 ] ) ;
V_27 = F_17 ( V_32 [ V_34 ] ) ;
V_5 -> V_37 [ V_34 ] = V_31 ;
F_11 ( V_2 , V_31 , V_27 ) ;
}
F_3 ( 1 ) ;
F_13 ( V_2 , V_30 , V_31 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_12 ( 0 , V_2 -> V_8 + V_38 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_12 ( 0 , V_2 -> V_8 + V_39 ) ;
}
static unsigned int F_20 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
unsigned int * V_25 )
{
unsigned int V_40 ;
V_40 = F_21 ( V_2 -> V_8 + V_41 ) ;
V_40 |= ( F_21 ( V_2 -> V_8 + V_42 ) << 8 ) ;
if ( V_25 )
* V_25 = V_40 & 0xf ;
return ( V_40 >> 4 ) & V_15 -> V_43 ;
}
static unsigned int F_22 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
unsigned int * V_25 )
{
unsigned int V_40 ;
V_40 = F_21 ( V_2 -> V_8 + V_44 ) << 8 ;
V_40 |= F_21 ( V_2 -> V_8 + V_39 ) ;
if ( V_25 )
* V_25 = V_40 & 0xf ;
return ( V_40 >> 4 ) & V_15 -> V_43 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_45 * V_46 ,
unsigned long V_47 )
{
unsigned int V_48 ;
V_48 = F_21 ( V_2 -> V_8 + V_38 ) ;
if ( V_48 & V_49 )
return 0 ;
return - V_50 ;
}
static bool F_24 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
unsigned int V_25 , unsigned int V_40 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_51 * V_52 = & V_15 -> V_53 -> V_52 ;
unsigned int V_54 ;
V_54 = V_5 -> V_37 [ V_5 -> V_36 ] ;
if ( V_25 != V_54 ) {
F_25 ( V_2 -> V_55 ,
L_1 ,
( V_5 -> V_18 ) ? L_2 :
( V_5 -> V_56 ) ? L_3 : L_4 ,
V_25 , V_54 ) ;
V_15 -> V_53 -> V_57 |= V_58 ;
return false ;
}
F_26 ( V_15 , & V_40 , 1 ) ;
V_5 -> V_36 ++ ;
if ( V_5 -> V_36 >= V_5 -> V_35 )
V_5 -> V_36 = 0 ;
if ( V_52 -> V_59 == V_60 &&
V_15 -> V_53 -> V_61 >= V_52 -> V_62 ) {
V_15 -> V_53 -> V_57 |= V_63 ;
return false ;
}
return true ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
unsigned int V_25 ;
unsigned int V_40 ;
if ( F_23 ( V_2 , V_15 , NULL , 0 ) ) {
F_28 ( V_2 -> V_55 , L_5 ) ;
V_15 -> V_53 -> V_57 |= V_58 ;
return;
}
V_40 = F_22 ( V_2 , V_15 , & V_25 ) ;
F_24 ( V_2 , V_15 , V_25 , V_40 ) ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_17 * V_18 = V_5 -> V_18 ;
struct V_19 * V_20 = & V_18 -> V_20 [ V_18 -> V_21 ] ;
unsigned short * V_64 = V_20 -> V_65 ;
unsigned int V_24 = F_6 ( V_15 , V_20 -> V_26 ) ;
unsigned int V_25 ;
unsigned int V_40 ;
int V_34 ;
V_18 -> V_21 = 1 - V_18 -> V_21 ;
F_5 ( V_2 , V_15 , V_24 ) ;
for ( V_34 = 0 ; V_34 < V_24 ; V_34 ++ ) {
V_40 = V_64 [ V_34 ] ;
V_25 = V_40 & 0xf ;
V_40 = ( V_40 >> 4 ) & V_15 -> V_43 ;
if ( ! F_24 ( V_2 , V_15 , V_25 , V_40 ) )
break;
}
}
static void F_30 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
unsigned int V_48 ;
unsigned int V_25 ;
unsigned int V_40 ;
int V_34 , V_66 ;
V_48 = F_21 ( V_2 -> V_8 + V_67 ) ;
if ( V_48 & 4 ) {
F_28 ( V_2 -> V_55 , L_6 ) ;
V_15 -> V_53 -> V_57 |= V_58 ;
return;
}
if ( V_48 & 1 ) {
F_28 ( V_2 -> V_55 ,
L_7 ) ;
V_15 -> V_53 -> V_57 |= V_58 ;
return;
}
if ( V_48 & 2 )
V_66 = 512 ;
else
V_66 = 0 ;
for ( V_34 = 0 ; V_34 < V_66 ; V_34 ++ ) {
V_40 = F_20 ( V_2 , V_15 , & V_25 ) ;
if ( ! F_24 ( V_2 , V_15 , V_25 , V_40 ) )
break;
}
}
static T_1 F_31 ( int V_68 , void * V_69 )
{
struct V_1 * V_2 = V_69 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_14 * V_15 = V_2 -> V_70 ;
struct V_51 * V_52 = & V_15 -> V_53 -> V_52 ;
if ( ! V_2 -> V_71 || ! V_5 -> V_72 ) {
F_18 ( V_2 ) ;
return V_73 ;
}
if ( V_5 -> V_74 ) {
V_15 -> V_53 -> V_61 = V_52 -> V_62 ;
V_15 -> V_75 ( V_2 , V_15 ) ;
return V_73 ;
}
if ( V_5 -> V_18 )
F_29 ( V_2 , V_15 ) ;
else if ( V_5 -> V_56 )
F_30 ( V_2 , V_15 ) ;
else
F_27 ( V_2 , V_15 ) ;
F_18 ( V_2 ) ;
F_32 ( V_2 , V_15 ) ;
return V_73 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
unsigned int * V_32 , unsigned int V_76 )
{
unsigned int V_77 [ 16 ] ;
unsigned int V_34 , V_78 , V_33 , V_79 ;
if ( V_76 < 1 ) {
F_28 ( V_2 -> V_55 , L_8 ) ;
return 0 ;
}
if ( V_76 > 1 ) {
V_77 [ 0 ] = V_32 [ 0 ] ;
for ( V_34 = 1 , V_33 = 1 ; V_34 < V_76 ; V_34 ++ , V_33 ++ ) {
if ( V_32 [ 0 ] == V_32 [ V_34 ] )
break;
V_78 =
( F_16 ( V_77 [ V_34 - 1 ] ) + 1 ) % V_15 -> V_76 ;
if ( V_78 != F_16 ( V_32 [ V_34 ] ) ) {
F_25 ( V_2 -> V_55 ,
L_9 ,
V_34 , F_16 ( V_32 [ V_34 ] ) , V_78 ,
F_16 ( V_32 [ 0 ] ) ) ;
return 0 ;
}
V_77 [ V_34 ] = V_32 [ V_34 ] ;
}
for ( V_34 = 0 , V_79 = 0 ; V_34 < V_76 ; V_34 ++ ) {
if ( V_32 [ V_34 ] != V_77 [ V_34 % V_33 ] ) {
F_25 ( V_2 -> V_55 ,
L_10 ,
V_34 , F_16 ( V_77 [ V_34 ] ) ,
F_17 ( V_77 [ V_34 ] ) ,
F_34 ( V_77 [ V_34 ] ) ,
F_16 ( V_32 [ V_34 % V_33 ] ) ,
F_17 ( V_32 [ V_34 % V_33 ] ) ,
F_34 ( V_77 [ V_34 % V_33 ] ) ) ;
return 0 ;
}
}
} else {
V_33 = 1 ;
}
return V_33 ;
}
static int F_35 ( unsigned int V_80 )
{
if ( F_21 ( V_80 + V_38 ) & V_81 )
return 1 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , struct V_14 * V_15 ,
struct V_51 * V_52 )
{
const struct V_82 * V_83 = V_2 -> V_84 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_85 = 0 ;
unsigned int V_86 ;
V_85 |= F_37 ( & V_52 -> V_87 , V_88 ) ;
V_85 |= F_37 ( & V_52 -> V_89 , V_90 ) ;
V_85 |= F_37 ( & V_52 -> V_91 , V_92 | V_93 ) ;
V_85 |= F_37 ( & V_52 -> V_94 , V_60 ) ;
V_85 |= F_37 ( & V_52 -> V_59 , V_60 | V_95 ) ;
if ( V_85 )
return 1 ;
V_85 |= F_38 ( V_52 -> V_91 ) ;
V_85 |= F_38 ( V_52 -> V_59 ) ;
if ( V_85 )
return 2 ;
V_85 |= F_39 ( & V_52 -> V_96 , 0 ) ;
V_85 |= F_39 ( & V_52 -> V_97 , 0 ) ;
if ( V_52 -> V_91 == V_92 )
V_85 |= F_40 ( & V_52 -> V_98 ,
V_83 -> V_99 ) ;
else
V_85 |= F_39 ( & V_52 -> V_98 , 0 ) ;
V_85 |= F_39 ( & V_52 -> V_100 , V_52 -> V_101 ) ;
if ( V_52 -> V_59 == V_60 )
V_85 |= F_40 ( & V_52 -> V_62 , 1 ) ;
else
V_85 |= F_39 ( & V_52 -> V_62 , 0 ) ;
if ( V_85 )
return 3 ;
if ( V_52 -> V_91 == V_92 ) {
V_86 = V_52 -> V_98 ;
F_41 ( V_5 -> V_102 ,
& V_5 -> V_13 ,
& V_5 -> V_12 ,
& V_86 , V_52 -> V_103 ) ;
V_85 |= F_39 ( & V_52 -> V_98 , V_86 ) ;
}
if ( V_85 )
return 4 ;
if ( V_52 -> V_32 ) {
if ( ! F_33 ( V_2 , V_15 , V_52 -> V_32 ,
V_52 -> V_101 ) )
return 5 ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_17 * V_18 = V_5 -> V_18 ;
struct V_51 * V_52 = & V_15 -> V_53 -> V_52 ;
unsigned int V_104 = 0 ;
unsigned int V_33 ;
if ( V_5 -> V_72 )
return - V_50 ;
F_1 ( V_2 , false ) ;
V_33 = F_33 ( V_2 , V_15 , V_52 -> V_32 , V_52 -> V_101 ) ;
if ( V_33 < 1 )
return - V_105 ;
F_15 ( V_2 , V_52 -> V_32 , V_33 ) ;
V_5 -> V_72 = 1 ;
V_5 -> V_74 = 0 ;
V_5 -> V_36 = 0 ;
if ( V_52 -> V_91 == V_92 )
V_104 |= V_106 ;
else
V_104 |= V_107 ;
F_12 ( V_108 , V_2 -> V_8 + V_109 ) ;
if ( V_18 ) {
V_18 -> V_21 = 0 ;
F_5 ( V_2 , V_15 , 0 ) ;
V_104 |= V_110 | F_43 ( V_2 -> V_68 ) |
V_111 ;
} else if ( V_5 -> V_56 ) {
F_12 ( 1 , V_2 -> V_8 + V_112 ) ;
} else {
V_104 |= V_110 | F_43 ( V_2 -> V_68 ) ;
}
F_12 ( V_104 , V_2 -> V_8 + V_113 ) ;
if ( V_52 -> V_91 == V_92 )
F_1 ( V_2 , true ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_17 * V_18 = V_5 -> V_18 ;
struct V_51 * V_52 = & V_15 -> V_53 -> V_52 ;
if ( ! V_5 -> V_72 )
return 0 ;
if ( V_18 ) {
if ( V_52 -> V_59 == V_95 ||
( V_52 -> V_59 == V_60 &&
V_15 -> V_53 -> V_61 < V_52 -> V_62 ) ) {
if ( ! V_5 -> V_74 ) {
V_5 -> V_74 = 1 ;
return 0 ;
}
}
F_7 ( V_18 -> V_25 ) ;
}
F_12 ( V_114 , V_2 -> V_8 + V_113 ) ;
F_1 ( V_2 , false ) ;
F_18 ( V_2 ) ;
if ( V_5 -> V_56 ) {
F_12 ( 0 , V_2 -> V_8 + V_115 ) ;
F_12 ( 0 , V_2 -> V_8 + V_116 ) ;
F_12 ( 0 , V_2 -> V_8 + V_112 ) ;
}
V_5 -> V_72 = 0 ;
V_5 -> V_74 = 0 ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_45 * V_46 ,
unsigned int * V_117 )
{
unsigned int V_25 = F_16 ( V_46 -> V_118 ) ;
unsigned int V_27 = F_17 ( V_46 -> V_118 ) ;
int V_119 = 0 ;
int V_34 ;
F_12 ( V_120 , V_2 -> V_8 + V_113 ) ;
F_11 ( V_2 , V_25 , V_27 ) ;
F_13 ( V_2 , V_25 , V_25 ) ;
for ( V_34 = 0 ; V_34 < V_46 -> V_121 ; V_34 ++ ) {
F_18 ( V_2 ) ;
F_19 ( V_2 ) ;
V_119 = F_46 ( V_2 , V_15 , V_46 , F_23 , 0 ) ;
if ( V_119 )
break;
V_117 [ V_34 ] = F_22 ( V_2 , V_15 , NULL ) ;
}
F_18 ( V_2 ) ;
return V_119 ? V_119 : V_46 -> V_121 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_45 * V_46 ,
unsigned int * V_117 )
{
unsigned int V_25 = F_16 ( V_46 -> V_118 ) ;
unsigned int V_40 = V_15 -> V_122 [ V_25 ] ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_46 -> V_121 ; V_34 ++ ) {
V_40 = V_117 [ V_34 ] ;
F_12 ( ( V_40 & 0x000f ) << 4 ,
V_2 -> V_8 + F_48 ( V_25 ) ) ;
F_12 ( ( V_40 & 0x0ff0 ) >> 4 ,
V_2 -> V_8 + F_49 ( V_25 ) ) ;
}
V_15 -> V_122 [ V_25 ] = V_40 ;
return V_46 -> V_121 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_45 * V_46 ,
unsigned int * V_117 )
{
V_117 [ 1 ] = F_21 ( V_2 -> V_8 + V_123 ) |
( F_21 ( V_2 -> V_8 + V_124 ) << 8 ) ;
return V_46 -> V_121 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_45 * V_46 ,
unsigned int * V_117 )
{
if ( F_52 ( V_15 , V_117 ) ) {
F_12 ( V_15 -> V_125 & 0xff , V_2 -> V_8 + V_123 ) ;
F_12 ( ( V_15 -> V_125 >> 8 ) , V_2 -> V_8 + V_124 ) ;
}
V_117 [ 1 ] = V_15 -> V_125 ;
return V_46 -> V_121 ;
}
static void F_53 ( struct V_1 * V_2 )
{
const struct V_82 * V_83 = V_2 -> V_84 ;
unsigned long V_7 = V_2 -> V_8 + V_9 ;
unsigned int V_25 ;
if ( V_83 -> V_126 ) {
F_12 ( 0 , V_2 -> V_8 + V_115 ) ;
F_12 ( 0 , V_2 -> V_8 + V_116 ) ;
F_12 ( 0 , V_2 -> V_8 + V_112 ) ;
}
F_12 ( V_114 , V_2 -> V_8 + V_113 ) ;
F_18 ( V_2 ) ;
F_11 ( V_2 , 0 , 0 ) ;
F_12 ( V_108 , V_2 -> V_8 + V_109 ) ;
F_2 ( V_7 , 0 , 2 , V_127 | V_11 ) ;
F_2 ( V_7 , 0 , 1 , V_127 | V_11 ) ;
F_2 ( V_7 , 0 , 0 , V_127 | V_11 ) ;
for ( V_25 = 0 ; V_25 < V_83 -> V_128 ; V_25 ++ ) {
F_12 ( 0 , V_2 -> V_8 + F_48 ( V_25 ) ) ;
F_12 ( 0 , V_2 -> V_8 + F_49 ( V_25 ) ) ;
}
F_12 ( 0 , V_2 -> V_8 + V_124 ) ;
F_12 ( 0 , V_2 -> V_8 + V_123 ) ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_129 * V_130 )
{
const struct V_82 * V_83 = V_2 -> V_84 ;
V_15 -> V_131 = V_83 -> V_132 ;
if ( V_83 -> V_133 ) {
if ( V_130 -> V_134 [ 4 ] == 1 || V_130 -> V_134 [ 4 ] == 10 ) {
V_15 -> V_131 = & V_135 ;
}
} else {
switch ( V_130 -> V_134 [ 4 ] ) {
case 0 :
V_15 -> V_131 = & V_136 ;
break;
case 1 :
V_15 -> V_131 = & V_137 ;
break;
case 2 :
V_15 -> V_131 = & V_138 ;
break;
case 3 :
V_15 -> V_131 = & V_139 ;
break;
case 4 :
V_15 -> V_131 = & V_140 ;
break;
case 6 :
V_15 -> V_131 = & V_141 ;
break;
case 7 :
V_15 -> V_131 = & V_142 ;
break;
case 8 :
V_15 -> V_131 = & V_143 ;
break;
case 9 :
V_15 -> V_131 = & V_144 ;
break;
default:
V_15 -> V_131 = & V_145 ;
break;
}
}
}
static void F_55 ( struct V_1 * V_2 , unsigned int V_146 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! ( V_146 == 3 || V_146 == 1 ) )
return;
V_5 -> V_18 = F_56 ( V_2 , 2 , V_146 , V_146 ,
V_147 * 4 , V_148 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 )
F_58 ( V_5 -> V_18 ) ;
}
static int F_59 ( struct V_1 * V_2 , struct V_129 * V_130 )
{
const struct V_82 * V_83 = V_2 -> V_84 ;
struct V_4 * V_5 ;
struct V_14 * V_15 ;
int V_119 ;
V_5 = F_60 ( V_2 , sizeof( * V_5 ) ) ;
if ( ! V_5 )
return - V_149 ;
V_119 = F_61 ( V_2 , V_130 -> V_134 [ 0 ] ,
V_83 -> V_126 ? 0x20 : 0x10 ) ;
if ( V_119 )
return V_119 ;
if ( V_130 -> V_134 [ 1 ] >= 2 && V_130 -> V_134 [ 1 ] <= 7 ) {
V_119 = F_62 ( V_130 -> V_134 [ 1 ] , F_31 , 0 ,
V_2 -> V_150 , V_2 ) ;
if ( V_119 == 0 )
V_2 -> V_68 = V_130 -> V_134 [ 1 ] ;
}
if ( V_2 -> V_68 && V_83 -> V_126 && V_130 -> V_134 [ 2 ] == - 1 )
V_5 -> V_56 = 1 ;
if ( V_2 -> V_68 && V_83 -> V_151 )
F_55 ( V_2 , V_130 -> V_134 [ 2 ] ) ;
V_119 = F_63 ( V_2 , 4 ) ;
if ( V_119 )
return V_119 ;
V_15 = & V_2 -> V_152 [ 0 ] ;
V_15 -> type = V_153 ;
V_15 -> V_154 = V_155 ;
if ( F_35 ( V_2 -> V_8 ) ) {
V_15 -> V_76 = 16 ;
V_15 -> V_154 |= V_156 | V_157 ;
} else {
V_15 -> V_76 = 8 ;
V_15 -> V_154 |= V_158 ;
}
V_15 -> V_43 = 0x0fff ;
F_54 ( V_2 , V_15 , V_130 ) ;
V_15 -> V_159 = F_45 ;
if ( V_2 -> V_68 ) {
V_2 -> V_70 = V_15 ;
V_15 -> V_154 |= V_160 ;
V_15 -> V_161 = V_15 -> V_76 ;
V_15 -> V_162 = F_36 ;
V_15 -> V_163 = F_42 ;
V_15 -> V_75 = F_44 ;
}
V_15 = & V_2 -> V_152 [ 1 ] ;
if ( V_83 -> V_128 ) {
V_15 -> type = V_164 ;
V_15 -> V_154 = V_165 | V_157 ;
V_15 -> V_76 = V_83 -> V_128 ;
V_15 -> V_43 = 0x0fff ;
V_15 -> V_131 = & V_142 ;
if ( V_83 -> V_133 ) {
if ( ( V_130 -> V_134 [ 4 ] == 1 ) || ( V_130 -> V_134 [ 4 ] == 10 ) )
V_15 -> V_131 = & V_141 ;
if ( V_130 -> V_134 [ 4 ] == 2 )
V_15 -> V_131 = & V_145 ;
} else {
if ( ( V_130 -> V_134 [ 5 ] == 1 ) || ( V_130 -> V_134 [ 5 ] == 10 ) )
V_15 -> V_131 = & V_141 ;
if ( V_130 -> V_134 [ 5 ] == 2 )
V_15 -> V_131 = & V_145 ;
}
V_15 -> V_166 = F_47 ;
V_119 = F_64 ( V_15 ) ;
if ( V_119 )
return V_119 ;
} else {
V_15 -> type = V_167 ;
}
V_15 = & V_2 -> V_152 [ 2 ] ;
V_15 -> type = V_168 ;
V_15 -> V_154 = V_155 ;
V_15 -> V_76 = 16 ;
V_15 -> V_43 = 1 ;
V_15 -> V_131 = & V_169 ;
V_15 -> V_170 = F_50 ;
V_15 = & V_2 -> V_152 [ 3 ] ;
V_15 -> type = V_171 ;
V_15 -> V_154 = V_165 ;
V_15 -> V_76 = 16 ;
V_15 -> V_43 = 1 ;
V_15 -> V_131 = & V_169 ;
V_15 -> V_170 = F_51 ;
if ( ( V_130 -> V_134 [ 3 ] == 0 ) || ( V_130 -> V_134 [ 3 ] == 10 ) )
V_5 -> V_102 = V_172 ;
else
V_5 -> V_102 = V_173 ;
V_5 -> V_99 = V_83 -> V_99 ;
if ( ! V_83 -> V_133 ) {
if ( ( V_130 -> V_134 [ 6 ] == 1 ) || ( V_130 -> V_134 [ 6 ] == 100 ) ) {
V_5 -> V_99 = 10000 ;
}
}
F_53 ( V_2 ) ;
return 0 ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 ) {
F_44 ( V_2 , V_2 -> V_70 ) ;
F_53 ( V_2 ) ;
}
F_57 ( V_2 ) ;
F_66 ( V_2 ) ;
}

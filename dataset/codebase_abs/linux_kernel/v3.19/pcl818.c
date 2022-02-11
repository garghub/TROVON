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
struct V_14 * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_16 * V_17 = & V_15 -> V_18 -> V_17 ;
unsigned int V_19 ;
unsigned int V_20 ;
F_6 ( V_5 -> V_21 ) ;
V_20 = V_5 -> V_22 ;
if ( V_17 -> V_23 == V_24 ) {
V_20 = V_17 -> V_25 * F_7 ( V_15 ) ;
V_5 -> V_26 = V_20 / V_5 -> V_22 ;
V_5 -> V_27 = V_20 % V_5 -> V_22 ;
V_5 -> V_26 -- ;
if ( V_5 -> V_26 >= 0 )
V_20 = V_5 -> V_22 ;
}
V_5 -> V_28 = 0 ;
F_8 ( V_5 -> V_21 , V_29 ) ;
V_19 = F_9 () ;
F_10 ( V_5 -> V_21 ) ;
F_11 ( V_5 -> V_21 , V_5 -> V_30 [ 0 ] ) ;
F_12 ( V_5 -> V_21 , V_20 ) ;
F_13 ( V_19 ) ;
F_14 ( V_5 -> V_21 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_16 * V_17 = & V_15 -> V_18 -> V_17 ;
unsigned long V_19 ;
F_6 ( V_5 -> V_21 ) ;
V_5 -> V_28 = 1 - V_5 -> V_28 ;
if ( V_5 -> V_26 > - 1 || V_17 -> V_23 == V_31 ) {
F_8 ( V_5 -> V_21 , V_29 ) ;
V_19 = F_9 () ;
F_11 ( V_5 -> V_21 ,
V_5 -> V_30 [ V_5 -> V_28 ] ) ;
if ( V_5 -> V_26 || V_17 -> V_23 == V_31 )
F_12 ( V_5 -> V_21 , V_5 -> V_22 ) ;
else
F_12 ( V_5 -> V_21 , V_5 -> V_27 ) ;
F_13 ( V_19 ) ;
F_14 ( V_5 -> V_21 ) ;
}
V_5 -> V_26 -- ;
}
static void F_16 ( struct V_1 * V_2 ,
unsigned int V_32 ,
unsigned int V_33 )
{
F_17 ( V_32 , V_2 -> V_8 + V_34 ) ;
F_17 ( V_33 , V_2 -> V_8 + V_35 ) ;
}
static void F_18 ( struct V_1 * V_2 ,
unsigned int V_36 ,
unsigned int V_37 )
{
F_17 ( F_19 ( V_36 , V_37 ) ,
V_2 -> V_8 + V_34 ) ;
}
static void F_20 ( struct V_1 * V_2 ,
unsigned int * V_38 ,
unsigned int V_39 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_36 = F_21 ( V_38 [ 0 ] ) ;
unsigned int V_37 ;
unsigned int V_33 ;
int V_40 ;
V_5 -> V_41 = V_39 ;
V_5 -> V_42 = 0 ;
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ ) {
V_37 = F_21 ( V_38 [ V_40 ] ) ;
V_33 = F_22 ( V_38 [ V_40 ] ) ;
V_5 -> V_43 [ V_40 ] = V_37 ;
F_16 ( V_2 , V_37 , V_33 ) ;
}
F_3 ( 1 ) ;
F_18 ( V_2 , V_36 , V_37 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_17 ( 0 , V_2 -> V_8 + V_44 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_17 ( 0 , V_2 -> V_8 + V_45 ) ;
}
static unsigned int F_25 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
unsigned int * V_32 )
{
unsigned int V_46 ;
V_46 = F_26 ( V_2 -> V_8 + V_47 ) ;
V_46 |= ( F_26 ( V_2 -> V_8 + V_48 ) << 8 ) ;
if ( V_32 )
* V_32 = V_46 & 0xf ;
return ( V_46 >> 4 ) & V_15 -> V_49 ;
}
static unsigned int F_27 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
unsigned int * V_32 )
{
unsigned int V_46 ;
V_46 = F_26 ( V_2 -> V_8 + V_50 ) << 8 ;
V_46 |= F_26 ( V_2 -> V_8 + V_45 ) ;
if ( V_32 )
* V_32 = V_46 & 0xf ;
return ( V_46 >> 4 ) & V_15 -> V_49 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_51 * V_52 ,
unsigned long V_53 )
{
unsigned int V_54 ;
V_54 = F_26 ( V_2 -> V_8 + V_44 ) ;
if ( V_54 & V_55 )
return 0 ;
return - V_56 ;
}
static bool F_29 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
unsigned int V_32 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_57 ;
V_57 = V_5 -> V_43 [ V_5 -> V_42 ] ;
if ( V_32 != V_57 ) {
F_30 ( V_2 -> V_58 ,
L_1 ,
( V_5 -> V_21 ) ? L_2 :
( V_5 -> V_59 ) ? L_3 : L_4 ,
V_32 , V_57 ) ;
V_15 -> V_18 -> V_60 |= V_61 | V_62 ;
return true ;
}
return false ;
}
static bool F_31 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_16 * V_17 = & V_15 -> V_18 -> V_17 ;
V_5 -> V_42 ++ ;
if ( V_5 -> V_42 >= V_5 -> V_41 )
V_5 -> V_42 = 0 ;
if ( V_17 -> V_23 == V_24 &&
V_15 -> V_18 -> V_63 >= V_17 -> V_25 ) {
V_15 -> V_18 -> V_60 |= V_61 ;
return false ;
}
return true ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
unsigned int V_32 ;
unsigned int V_46 ;
if ( F_28 ( V_2 , V_15 , NULL , 0 ) ) {
F_33 ( V_2 -> V_58 , L_5 ) ;
V_15 -> V_18 -> V_60 |= V_61 | V_62 ;
return;
}
V_46 = F_27 ( V_2 , V_15 , & V_32 ) ;
if ( F_29 ( V_2 , V_15 , V_32 ) )
return;
F_34 ( V_15 , & V_46 , 1 ) ;
F_31 ( V_2 , V_15 ) ;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned short * V_64 ;
unsigned int V_32 ;
unsigned int V_46 ;
int V_40 , V_65 , V_66 ;
F_15 ( V_2 , V_15 ) ;
V_64 = ( unsigned short * ) V_5 -> V_67 [ 1 - V_5 -> V_28 ] ;
V_65 = V_5 -> V_22 >> 1 ;
V_66 = 0 ;
for ( V_40 = 0 ; V_40 < V_65 ; V_40 ++ ) {
V_46 = V_64 [ V_66 ++ ] ;
V_32 = V_46 & 0xf ;
V_46 = ( V_46 >> 4 ) & V_15 -> V_49 ;
if ( F_29 ( V_2 , V_15 , V_32 ) )
break;
F_34 ( V_15 , & V_46 , 1 ) ;
if ( ! F_31 ( V_2 , V_15 ) )
break;
}
}
static void F_36 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
unsigned int V_54 ;
unsigned int V_32 ;
unsigned int V_46 ;
int V_40 , V_65 ;
V_54 = F_26 ( V_2 -> V_8 + V_68 ) ;
if ( V_54 & 4 ) {
F_33 ( V_2 -> V_58 , L_6 ) ;
V_15 -> V_18 -> V_60 |= V_61 | V_62 ;
return;
}
if ( V_54 & 1 ) {
F_33 ( V_2 -> V_58 ,
L_7 ) ;
V_15 -> V_18 -> V_60 |= V_61 | V_62 ;
return;
}
if ( V_54 & 2 )
V_65 = 512 ;
else
V_65 = 0 ;
for ( V_40 = 0 ; V_40 < V_65 ; V_40 ++ ) {
V_46 = F_25 ( V_2 , V_15 , & V_32 ) ;
if ( F_29 ( V_2 , V_15 , V_32 ) )
break;
F_34 ( V_15 , & V_46 , 1 ) ;
if ( ! F_31 ( V_2 , V_15 ) )
break;
}
}
static T_1 F_37 ( int V_69 , void * V_70 )
{
struct V_1 * V_2 = V_70 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_14 * V_15 = V_2 -> V_71 ;
struct V_16 * V_17 = & V_15 -> V_18 -> V_17 ;
if ( ! V_2 -> V_72 || ! V_5 -> V_73 ) {
F_23 ( V_2 ) ;
return V_74 ;
}
if ( V_5 -> V_75 ) {
V_15 -> V_18 -> V_63 = V_17 -> V_25 ;
V_15 -> V_76 ( V_2 , V_15 ) ;
return V_74 ;
}
if ( V_5 -> V_21 )
F_35 ( V_2 , V_15 ) ;
else if ( V_5 -> V_59 )
F_36 ( V_2 , V_15 ) ;
else
F_32 ( V_2 , V_15 ) ;
F_23 ( V_2 ) ;
F_38 ( V_2 , V_15 ) ;
return V_74 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
unsigned int * V_38 , unsigned int V_77 )
{
unsigned int V_78 [ 16 ] ;
unsigned int V_40 , V_79 , V_39 , V_80 ;
if ( V_77 < 1 ) {
F_33 ( V_2 -> V_58 , L_8 ) ;
return 0 ;
}
if ( V_77 > 1 ) {
V_78 [ 0 ] = V_38 [ 0 ] ;
for ( V_40 = 1 , V_39 = 1 ; V_40 < V_77 ; V_40 ++ , V_39 ++ ) {
if ( V_38 [ 0 ] == V_38 [ V_40 ] )
break;
V_79 =
( F_21 ( V_78 [ V_40 - 1 ] ) + 1 ) % V_15 -> V_77 ;
if ( V_79 != F_21 ( V_38 [ V_40 ] ) ) {
F_30 ( V_2 -> V_58 ,
L_9 ,
V_40 , F_21 ( V_38 [ V_40 ] ) , V_79 ,
F_21 ( V_38 [ 0 ] ) ) ;
return 0 ;
}
V_78 [ V_40 ] = V_38 [ V_40 ] ;
}
for ( V_40 = 0 , V_80 = 0 ; V_40 < V_77 ; V_40 ++ ) {
if ( V_38 [ V_40 ] != V_78 [ V_40 % V_39 ] ) {
F_30 ( V_2 -> V_58 ,
L_10 ,
V_40 , F_21 ( V_78 [ V_40 ] ) ,
F_22 ( V_78 [ V_40 ] ) ,
F_40 ( V_78 [ V_40 ] ) ,
F_21 ( V_38 [ V_40 % V_39 ] ) ,
F_22 ( V_38 [ V_40 % V_39 ] ) ,
F_40 ( V_78 [ V_40 % V_39 ] ) ) ;
return 0 ;
}
}
} else {
V_39 = 1 ;
}
return V_39 ;
}
static int F_41 ( unsigned int V_81 )
{
if ( F_26 ( V_81 + V_44 ) & V_82 )
return 1 ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , struct V_14 * V_15 ,
struct V_16 * V_17 )
{
const struct V_83 * V_84 = V_2 -> V_85 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_86 = 0 ;
unsigned int V_87 ;
V_86 |= F_43 ( & V_17 -> V_88 , V_89 ) ;
V_86 |= F_43 ( & V_17 -> V_90 , V_91 ) ;
V_86 |= F_43 ( & V_17 -> V_92 , V_93 | V_94 ) ;
V_86 |= F_43 ( & V_17 -> V_95 , V_24 ) ;
V_86 |= F_43 ( & V_17 -> V_23 , V_24 | V_31 ) ;
if ( V_86 )
return 1 ;
V_86 |= F_44 ( V_17 -> V_92 ) ;
V_86 |= F_44 ( V_17 -> V_23 ) ;
if ( V_86 )
return 2 ;
V_86 |= F_45 ( & V_17 -> V_96 , 0 ) ;
V_86 |= F_45 ( & V_17 -> V_97 , 0 ) ;
if ( V_17 -> V_92 == V_93 )
V_86 |= F_46 ( & V_17 -> V_98 ,
V_84 -> V_99 ) ;
else
V_86 |= F_45 ( & V_17 -> V_98 , 0 ) ;
V_86 |= F_45 ( & V_17 -> V_100 , V_17 -> V_101 ) ;
if ( V_17 -> V_23 == V_24 )
V_86 |= F_46 ( & V_17 -> V_25 , 1 ) ;
else
V_86 |= F_45 ( & V_17 -> V_25 , 0 ) ;
if ( V_86 )
return 3 ;
if ( V_17 -> V_92 == V_93 ) {
V_87 = V_17 -> V_98 ;
F_47 ( V_5 -> V_102 ,
& V_5 -> V_13 ,
& V_5 -> V_12 ,
& V_87 , V_17 -> V_19 ) ;
V_86 |= F_45 ( & V_17 -> V_98 , V_87 ) ;
}
if ( V_86 )
return 4 ;
if ( V_17 -> V_38 ) {
if ( ! F_39 ( V_2 , V_15 , V_17 -> V_38 ,
V_17 -> V_101 ) )
return 5 ;
}
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_16 * V_17 = & V_15 -> V_18 -> V_17 ;
unsigned int V_103 = 0 ;
unsigned int V_39 ;
if ( V_5 -> V_73 )
return - V_56 ;
F_1 ( V_2 , false ) ;
V_39 = F_39 ( V_2 , V_15 , V_17 -> V_38 , V_17 -> V_101 ) ;
if ( V_39 < 1 )
return - V_104 ;
F_20 ( V_2 , V_17 -> V_38 , V_39 ) ;
V_5 -> V_105 = V_15 -> V_18 -> V_106 ;
V_5 -> V_73 = 1 ;
V_5 -> V_75 = 0 ;
V_5 -> V_42 = 0 ;
V_5 -> V_26 = 0 ;
if ( V_17 -> V_92 == V_93 )
V_103 |= V_107 ;
else
V_103 |= V_108 ;
F_17 ( V_109 , V_2 -> V_8 + V_110 ) ;
if ( V_5 -> V_21 ) {
F_5 ( V_2 , V_15 ) ;
V_103 |= V_111 | F_49 ( V_2 -> V_69 ) |
V_112 ;
} else if ( V_5 -> V_59 ) {
F_17 ( 1 , V_2 -> V_8 + V_113 ) ;
} else {
V_103 |= V_111 | F_49 ( V_2 -> V_69 ) ;
}
F_17 ( V_103 , V_2 -> V_8 + V_114 ) ;
if ( V_17 -> V_92 == V_93 )
F_1 ( V_2 , true ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_16 * V_17 = & V_15 -> V_18 -> V_17 ;
if ( ! V_5 -> V_73 )
return 0 ;
if ( V_5 -> V_21 ) {
if ( V_17 -> V_23 == V_31 ||
( V_17 -> V_23 == V_24 &&
V_15 -> V_18 -> V_63 < V_17 -> V_25 ) ) {
if ( ! V_5 -> V_75 ) {
V_5 -> V_75 = 1 ;
return 0 ;
}
}
F_6 ( V_5 -> V_21 ) ;
}
F_17 ( V_115 , V_2 -> V_8 + V_114 ) ;
F_1 ( V_2 , false ) ;
F_23 ( V_2 ) ;
if ( V_5 -> V_59 ) {
F_17 ( 0 , V_2 -> V_8 + V_116 ) ;
F_17 ( 0 , V_2 -> V_8 + V_117 ) ;
F_17 ( 0 , V_2 -> V_8 + V_113 ) ;
}
V_5 -> V_73 = 0 ;
V_5 -> V_75 = 0 ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_51 * V_52 ,
unsigned int * V_118 )
{
unsigned int V_32 = F_21 ( V_52 -> V_119 ) ;
unsigned int V_33 = F_22 ( V_52 -> V_119 ) ;
int V_120 = 0 ;
int V_40 ;
F_17 ( V_121 , V_2 -> V_8 + V_114 ) ;
F_16 ( V_2 , V_32 , V_33 ) ;
F_18 ( V_2 , V_32 , V_32 ) ;
for ( V_40 = 0 ; V_40 < V_52 -> V_122 ; V_40 ++ ) {
F_23 ( V_2 ) ;
F_24 ( V_2 ) ;
V_120 = F_52 ( V_2 , V_15 , V_52 , F_28 , 0 ) ;
if ( V_120 )
break;
V_118 [ V_40 ] = F_27 ( V_2 , V_15 , NULL ) ;
}
F_23 ( V_2 ) ;
return V_120 ? V_120 : V_52 -> V_122 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_51 * V_52 ,
unsigned int * V_118 )
{
unsigned int V_32 = F_21 ( V_52 -> V_119 ) ;
unsigned int V_46 = V_15 -> V_123 [ V_32 ] ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_52 -> V_122 ; V_40 ++ ) {
V_46 = V_118 [ V_40 ] ;
F_17 ( ( V_46 & 0x000f ) << 4 ,
V_2 -> V_8 + F_54 ( V_32 ) ) ;
F_17 ( ( V_46 & 0x0ff0 ) >> 4 ,
V_2 -> V_8 + F_55 ( V_32 ) ) ;
}
V_15 -> V_123 [ V_32 ] = V_46 ;
return V_52 -> V_122 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_51 * V_52 ,
unsigned int * V_118 )
{
V_118 [ 1 ] = F_26 ( V_2 -> V_8 + V_124 ) |
( F_26 ( V_2 -> V_8 + V_125 ) << 8 ) ;
return V_52 -> V_122 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_51 * V_52 ,
unsigned int * V_118 )
{
if ( F_58 ( V_15 , V_118 ) ) {
F_17 ( V_15 -> V_126 & 0xff , V_2 -> V_8 + V_124 ) ;
F_17 ( ( V_15 -> V_126 >> 8 ) , V_2 -> V_8 + V_125 ) ;
}
V_118 [ 1 ] = V_15 -> V_126 ;
return V_52 -> V_122 ;
}
static void F_59 ( struct V_1 * V_2 )
{
const struct V_83 * V_84 = V_2 -> V_85 ;
unsigned long V_7 = V_2 -> V_8 + V_9 ;
unsigned int V_32 ;
if ( V_84 -> V_127 ) {
F_17 ( 0 , V_2 -> V_8 + V_116 ) ;
F_17 ( 0 , V_2 -> V_8 + V_117 ) ;
F_17 ( 0 , V_2 -> V_8 + V_113 ) ;
}
F_17 ( V_115 , V_2 -> V_8 + V_114 ) ;
F_23 ( V_2 ) ;
F_16 ( V_2 , 0 , 0 ) ;
F_17 ( V_109 , V_2 -> V_8 + V_110 ) ;
F_2 ( V_7 , 0 , 2 , V_128 | V_11 ) ;
F_2 ( V_7 , 0 , 1 , V_128 | V_11 ) ;
F_2 ( V_7 , 0 , 0 , V_128 | V_11 ) ;
for ( V_32 = 0 ; V_32 < V_84 -> V_129 ; V_32 ++ ) {
F_17 ( 0 , V_2 -> V_8 + F_54 ( V_32 ) ) ;
F_17 ( 0 , V_2 -> V_8 + F_55 ( V_32 ) ) ;
}
F_17 ( 0 , V_2 -> V_8 + V_125 ) ;
F_17 ( 0 , V_2 -> V_8 + V_124 ) ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_130 * V_131 )
{
const struct V_83 * V_84 = V_2 -> V_85 ;
V_15 -> V_132 = V_84 -> V_133 ;
if ( V_84 -> V_134 ) {
if ( V_131 -> V_135 [ 4 ] == 1 || V_131 -> V_135 [ 4 ] == 10 ) {
V_15 -> V_132 = & V_136 ;
}
} else {
switch ( V_131 -> V_135 [ 4 ] ) {
case 0 :
V_15 -> V_132 = & V_137 ;
break;
case 1 :
V_15 -> V_132 = & V_138 ;
break;
case 2 :
V_15 -> V_132 = & V_139 ;
break;
case 3 :
V_15 -> V_132 = & V_140 ;
break;
case 4 :
V_15 -> V_132 = & V_141 ;
break;
case 6 :
V_15 -> V_132 = & V_142 ;
break;
case 7 :
V_15 -> V_132 = & V_143 ;
break;
case 8 :
V_15 -> V_132 = & V_144 ;
break;
case 9 :
V_15 -> V_132 = & V_145 ;
break;
default:
V_15 -> V_132 = & V_146 ;
break;
}
}
}
static int F_61 ( struct V_1 * V_2 , struct V_130 * V_131 )
{
const struct V_83 * V_84 = V_2 -> V_85 ;
struct V_4 * V_5 ;
struct V_14 * V_15 ;
int V_120 ;
int V_40 ;
V_5 = F_62 ( V_2 , sizeof( * V_5 ) ) ;
if ( ! V_5 )
return - V_147 ;
V_120 = F_63 ( V_2 , V_131 -> V_135 [ 0 ] ,
V_84 -> V_127 ? 0x20 : 0x10 ) ;
if ( V_120 )
return V_120 ;
if ( V_131 -> V_135 [ 1 ] >= 2 && V_131 -> V_135 [ 1 ] <= 7 ) {
V_120 = F_64 ( V_131 -> V_135 [ 1 ] , F_37 , 0 ,
V_2 -> V_148 , V_2 ) ;
if ( V_120 == 0 )
V_2 -> V_69 = V_131 -> V_135 [ 1 ] ;
}
if ( V_2 -> V_69 && V_84 -> V_127 && V_131 -> V_135 [ 2 ] == - 1 )
V_5 -> V_59 = 1 ;
if ( V_2 -> V_69 && V_84 -> V_149 &&
( V_131 -> V_135 [ 2 ] == 3 || V_131 -> V_135 [ 2 ] == 1 ) ) {
V_120 = F_65 ( V_131 -> V_135 [ 2 ] , V_2 -> V_148 ) ;
if ( V_120 ) {
F_33 ( V_2 -> V_58 ,
L_11 ,
V_131 -> V_135 [ 2 ] ) ;
return - V_56 ;
}
V_5 -> V_21 = V_131 -> V_135 [ 2 ] ;
V_5 -> V_150 = 2 ;
V_5 -> V_22 = ( 1 << V_5 -> V_150 ) * V_151 ;
for ( V_40 = 0 ; V_40 < 2 ; V_40 ++ ) {
unsigned long V_67 ;
V_67 = F_66 ( V_152 , V_5 -> V_150 ) ;
if ( ! V_67 )
return - V_147 ;
V_5 -> V_67 [ V_40 ] = V_67 ;
V_5 -> V_30 [ V_40 ] = F_67 ( ( void * ) V_67 ) ;
}
}
V_120 = F_68 ( V_2 , 4 ) ;
if ( V_120 )
return V_120 ;
V_15 = & V_2 -> V_153 [ 0 ] ;
V_15 -> type = V_154 ;
V_15 -> V_155 = V_156 ;
if ( F_41 ( V_2 -> V_8 ) ) {
V_15 -> V_77 = 16 ;
V_15 -> V_155 |= V_157 | V_158 ;
} else {
V_15 -> V_77 = 8 ;
V_15 -> V_155 |= V_159 ;
}
V_15 -> V_49 = 0x0fff ;
F_60 ( V_2 , V_15 , V_131 ) ;
V_15 -> V_160 = F_51 ;
if ( V_2 -> V_69 ) {
V_2 -> V_71 = V_15 ;
V_15 -> V_155 |= V_161 ;
V_15 -> V_162 = V_15 -> V_77 ;
V_15 -> V_163 = F_42 ;
V_15 -> V_164 = F_48 ;
V_15 -> V_76 = F_50 ;
}
V_15 = & V_2 -> V_153 [ 1 ] ;
if ( V_84 -> V_129 ) {
V_15 -> type = V_165 ;
V_15 -> V_155 = V_166 | V_158 ;
V_15 -> V_77 = V_84 -> V_129 ;
V_15 -> V_49 = 0x0fff ;
V_15 -> V_132 = & V_143 ;
if ( V_84 -> V_134 ) {
if ( ( V_131 -> V_135 [ 4 ] == 1 ) || ( V_131 -> V_135 [ 4 ] == 10 ) )
V_15 -> V_132 = & V_142 ;
if ( V_131 -> V_135 [ 4 ] == 2 )
V_15 -> V_132 = & V_146 ;
} else {
if ( ( V_131 -> V_135 [ 5 ] == 1 ) || ( V_131 -> V_135 [ 5 ] == 10 ) )
V_15 -> V_132 = & V_142 ;
if ( V_131 -> V_135 [ 5 ] == 2 )
V_15 -> V_132 = & V_146 ;
}
V_15 -> V_167 = F_53 ;
V_120 = F_69 ( V_15 ) ;
if ( V_120 )
return V_120 ;
} else {
V_15 -> type = V_168 ;
}
V_15 = & V_2 -> V_153 [ 2 ] ;
V_15 -> type = V_169 ;
V_15 -> V_155 = V_156 ;
V_15 -> V_77 = 16 ;
V_15 -> V_49 = 1 ;
V_15 -> V_132 = & V_170 ;
V_15 -> V_171 = F_56 ;
V_15 = & V_2 -> V_153 [ 3 ] ;
V_15 -> type = V_172 ;
V_15 -> V_155 = V_166 ;
V_15 -> V_77 = 16 ;
V_15 -> V_49 = 1 ;
V_15 -> V_132 = & V_170 ;
V_15 -> V_171 = F_57 ;
if ( ( V_131 -> V_135 [ 3 ] == 0 ) || ( V_131 -> V_135 [ 3 ] == 10 ) )
V_5 -> V_102 = V_173 ;
else
V_5 -> V_102 = V_174 ;
V_5 -> V_99 = V_84 -> V_99 ;
if ( ! V_84 -> V_134 ) {
if ( ( V_131 -> V_135 [ 6 ] == 1 ) || ( V_131 -> V_135 [ 6 ] == 100 ) )
V_5 -> V_99 = 10000 ;
}
F_59 ( V_2 ) ;
return 0 ;
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 ) {
F_50 ( V_2 , V_2 -> V_71 ) ;
F_59 ( V_2 ) ;
if ( V_5 -> V_21 )
F_71 ( V_5 -> V_21 ) ;
if ( V_5 -> V_67 [ 0 ] )
F_72 ( V_5 -> V_67 [ 0 ] , V_5 -> V_150 ) ;
if ( V_5 -> V_67 [ 1 ] )
F_72 ( V_5 -> V_67 [ 1 ] , V_5 -> V_150 ) ;
}
F_73 ( V_2 ) ;
}

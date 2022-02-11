static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_10 = F_2 ( V_6 -> V_11 [ 0 ] ) ;
unsigned int V_12 = F_3 ( V_6 -> V_11 [ 0 ] ) ;
unsigned int V_13 = ( V_10 + 1 ) % V_4 -> V_14 ;
unsigned int V_15 [ 32 ] ;
unsigned int V_16 ;
int V_17 ;
if ( V_6 -> V_18 == 1 ) {
V_8 -> V_19 = V_6 -> V_18 ;
return 0 ;
}
V_15 [ 0 ] = V_6 -> V_11 [ 0 ] ;
for ( V_17 = 1 ; V_17 < V_6 -> V_18 ; V_17 ++ ) {
unsigned int V_20 = F_2 ( V_6 -> V_11 [ V_17 ] ) ;
unsigned int V_21 = F_3 ( V_6 -> V_11 [ V_17 ] ) ;
if ( V_6 -> V_11 [ 0 ] == V_6 -> V_11 [ V_17 ] )
break;
if ( V_21 == V_22 && ( V_20 & 1 ) ) {
F_4 ( V_2 -> V_23 ,
L_1 ) ;
return - V_24 ;
}
if ( V_12 == V_22 )
V_13 = ( V_13 + 1 ) % V_4 -> V_14 ;
if ( V_20 != V_13 ) {
F_4 ( V_2 -> V_23 ,
L_2 ,
V_17 , V_20 , V_13 , V_10 ) ;
return - V_24 ;
}
V_15 [ V_17 ] = V_6 -> V_11 [ V_17 ] ;
V_12 = V_21 ;
}
V_16 = V_17 ;
for ( V_17 = 0 ; V_17 < V_6 -> V_18 ; V_17 ++ ) {
if ( V_6 -> V_11 [ V_17 ] != V_15 [ V_17 % V_16 ] ) {
F_4 ( V_2 -> V_23 ,
L_3 ,
V_17 , F_2 ( V_15 [ V_17 ] ) ,
F_5 ( V_15 [ V_17 ] ) ,
F_3 ( V_15 [ V_17 ] ) ,
F_2 ( V_6 -> V_11 [ V_17 % V_16 ] ) ,
F_5 ( V_6 -> V_11 [ V_17 % V_16 ] ) ,
F_3 ( V_15 [ V_17 % V_16 ] ) ) ;
return - V_24 ;
}
}
V_8 -> V_19 = V_16 ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int * V_11 ,
unsigned int V_14 ,
unsigned int V_16 )
{
const struct V_25 * V_26 = V_2 -> V_27 ;
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_28 = F_2 ( V_11 [ 0 ] ) ;
unsigned int V_29 = F_2 ( V_11 [ V_16 - 1 ] ) ;
unsigned int V_17 ;
for ( V_17 = 0 ; V_17 < V_16 ; V_17 ++ ) {
unsigned int V_20 = F_2 ( V_11 [ V_17 ] ) ;
unsigned int V_30 = F_5 ( V_11 [ V_17 ] ) ;
unsigned int V_21 = F_3 ( V_11 [ V_17 ] ) ;
unsigned int V_31 ;
V_31 = V_26 -> V_32 [ V_30 ] ;
if ( V_21 == V_22 )
V_31 |= 0x0020 ;
F_7 ( V_20 | ( V_20 << 8 ) , V_2 -> V_33 + V_34 ) ;
F_7 ( V_31 , V_2 -> V_33 + V_35 ) ;
V_8 -> V_36 [ V_17 ] = V_20 ;
}
for ( ; V_17 < V_14 ; V_17 ++ )
V_8 -> V_36 [ V_17 ] = F_2 ( V_11 [ V_17 ] ) ;
V_8 -> V_37 = V_28 | ( V_29 << 8 ) ;
F_7 ( V_8 -> V_37 , V_2 -> V_33 + V_34 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_38 * V_39 ,
unsigned long V_40 )
{
unsigned int V_41 ;
V_41 = F_9 ( V_2 -> V_33 + V_42 ) ;
if ( ( V_41 & V_43 ) == 0 )
return 0 ;
return - V_44 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_45 ,
unsigned int * V_46 )
{
const struct V_25 * V_26 = V_2 -> V_27 ;
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_47 ;
unsigned int V_20 ;
V_47 = F_9 ( V_2 -> V_33 + V_48 ) ;
if ( ! V_26 -> V_49 ) {
V_20 = V_47 >> 12 ;
if ( V_20 != V_8 -> V_36 [ V_45 ] ) {
F_4 ( V_2 -> V_23 ,
L_4 ,
V_20 , V_8 -> V_36 [ V_45 ] ) ;
return - V_50 ;
}
}
* V_46 = V_47 & V_4 -> V_51 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_38 * V_39 ,
unsigned int * V_52 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_53 = 0 ;
int V_17 ;
V_8 -> V_54 &= V_55 ;
V_8 -> V_54 |= V_56 ;
F_7 ( V_8 -> V_54 , V_2 -> V_33 + V_57 ) ;
F_12 ( 0 , V_2 -> V_33 + V_58 ) ;
F_12 ( 0 , V_2 -> V_33 + V_59 ) ;
F_6 ( V_2 , V_4 , & V_39 -> V_60 , 1 , 1 ) ;
for ( V_17 = 0 ; V_17 < V_39 -> V_61 ; V_17 ++ ) {
unsigned int V_46 ;
F_7 ( 0 , V_2 -> V_33 + V_62 ) ;
V_53 = F_13 ( V_2 , V_4 , V_39 , F_8 , 0 ) ;
if ( V_53 )
break;
V_53 = F_10 ( V_2 , V_4 , 0 , & V_46 ) ;
if ( V_53 )
break;
V_52 [ V_17 ] = V_46 ;
}
F_12 ( 0 , V_2 -> V_33 + V_58 ) ;
F_12 ( 0 , V_2 -> V_33 + V_59 ) ;
return V_53 ? V_53 : V_39 -> V_61 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_38 * V_39 ,
unsigned int * V_52 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_20 = F_2 ( V_39 -> V_60 ) ;
unsigned int V_30 = F_5 ( V_39 -> V_60 ) ;
unsigned int V_63 = V_20 ? V_64 : V_65 ;
unsigned int V_46 = V_4 -> V_66 [ V_20 ] ;
int V_17 ;
V_8 -> V_67 &= ~ ( 1 << ( V_20 << 1 ) ) ;
V_8 -> V_67 |= ( V_30 << ( V_20 << 1 ) ) ;
F_7 ( V_8 -> V_67 , V_2 -> V_33 + V_68 ) ;
for ( V_17 = 0 ; V_17 < V_39 -> V_61 ; V_17 ++ ) {
V_46 = V_52 [ V_17 ] ;
F_7 ( V_46 , V_2 -> V_33 + V_63 ) ;
}
V_4 -> V_66 [ V_20 ] = V_46 ;
return V_39 -> V_61 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_38 * V_39 ,
unsigned int * V_52 )
{
V_52 [ 1 ] = F_9 ( V_2 -> V_33 + V_69 ) ;
return V_39 -> V_61 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_38 * V_39 ,
unsigned int * V_52 )
{
if ( F_17 ( V_4 , V_52 ) )
F_7 ( V_4 -> V_70 , V_2 -> V_33 + V_71 ) ;
V_52 [ 1 ] = V_4 -> V_70 ;
return V_39 -> V_61 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_38 * V_39 ,
unsigned int * V_52 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_20 = F_2 ( V_39 -> V_60 ) ;
unsigned int V_30 = F_5 ( V_39 -> V_60 ) ;
unsigned int V_46 ;
int V_17 ;
V_46 = V_8 -> V_67 & ( ~ ( 0x03 << ( V_20 << 1 ) ) ) ;
V_46 |= ( V_30 << ( V_20 << 1 ) ) ;
if ( V_46 != V_8 -> V_67 ) {
F_12 ( V_46 , V_2 -> V_33 + V_72 ) ;
V_8 -> V_67 = V_46 ;
}
V_46 = V_4 -> V_66 [ V_20 ] ;
for ( V_17 = 0 ; V_17 < V_39 -> V_61 ; V_17 ++ ) {
V_46 = V_52 [ V_17 ] ;
F_7 ( V_46 , V_2 -> V_33 + V_73 + ( V_20 << 1 ) ) ;
F_12 ( 0 , V_2 -> V_33 + V_74 ) ;
}
V_4 -> V_66 [ V_20 ] = V_46 ;
return V_39 -> V_61 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
V_8 -> V_54 &= V_55 ;
V_8 -> V_54 |= V_56 ;
F_7 ( V_8 -> V_54 , V_2 -> V_33 + V_57 ) ;
F_20 ( V_2 -> V_75 , 1 , 2 , false ) ;
F_12 ( 0 , V_2 -> V_33 + V_58 ) ;
F_12 ( 0 , V_2 -> V_33 + V_59 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_76 -> V_6 ;
unsigned int V_41 ;
unsigned int V_46 ;
int V_53 ;
V_41 = F_9 ( V_2 -> V_33 + V_42 ) ;
if ( V_41 & V_43 ) {
F_22 ( V_2 -> V_23 , L_5 , V_41 ) ;
V_4 -> V_76 -> V_77 |= V_78 ;
return;
}
if ( V_41 & V_79 ) {
F_22 ( V_2 -> V_23 ,
L_6 , V_41 ) ;
V_4 -> V_76 -> V_77 |= V_78 ;
return;
}
F_12 ( 0 , V_2 -> V_33 + V_59 ) ;
for (; ! ( F_9 ( V_2 -> V_33 + V_42 ) & V_43 ) ; ) {
V_53 = F_10 ( V_2 , V_4 , V_4 -> V_76 -> V_45 , & V_46 ) ;
if ( V_53 ) {
V_4 -> V_76 -> V_77 |= V_78 ;
break;
}
F_23 ( V_4 , & V_46 , 1 ) ;
if ( V_6 -> V_80 == V_81 &&
V_4 -> V_76 -> V_82 >= V_6 -> V_83 ) {
V_4 -> V_76 -> V_77 |= V_84 ;
break;
}
}
F_12 ( 0 , V_2 -> V_33 + V_59 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_85 * V_76 = V_4 -> V_76 ;
struct V_5 * V_6 = & V_76 -> V_6 ;
unsigned int V_41 ;
int V_17 ;
V_41 = F_9 ( V_2 -> V_33 + V_42 ) ;
if ( ! ( V_41 & V_86 ) ) {
F_22 ( V_2 -> V_23 , L_7 ) ;
V_76 -> V_77 |= V_78 ;
return;
}
if ( V_41 & V_79 ) {
F_22 ( V_2 -> V_23 ,
L_8 ) ;
V_76 -> V_77 |= V_78 ;
return;
}
for ( V_17 = 0 ; V_17 < V_8 -> V_87 ; V_17 ++ ) {
unsigned int V_46 ;
int V_53 ;
V_53 = F_10 ( V_2 , V_4 , V_4 -> V_76 -> V_45 , & V_46 ) ;
if ( V_53 ) {
V_4 -> V_76 -> V_77 |= V_78 ;
break;
}
if ( ! F_23 ( V_4 , & V_46 , 1 ) )
break;
if ( V_6 -> V_80 == V_81 &&
V_76 -> V_82 >= V_6 -> V_83 ) {
V_76 -> V_77 |= V_84 ;
break;
}
}
F_12 ( 0 , V_2 -> V_33 + V_59 ) ;
}
static T_1 F_25 ( int V_88 , void * V_89 )
{
struct V_1 * V_2 = V_89 ;
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
if ( ! V_2 -> V_90 )
return V_91 ;
V_4 = V_2 -> V_92 ;
V_6 = & V_4 -> V_76 -> V_6 ;
if ( ! ( F_9 ( V_2 -> V_33 + V_42 ) & V_93 ) )
return V_91 ;
if ( V_8 -> V_94 ) {
V_8 -> V_94 = 0 ;
V_8 -> V_54 &= V_55 ;
V_8 -> V_54 |= V_56 ;
F_7 ( V_8 -> V_54 , V_2 -> V_33 + V_57 ) ;
V_8 -> V_54 = V_8 -> V_95 ;
F_12 ( 0 , V_2 -> V_33 + V_58 ) ;
F_12 ( 0 , V_2 -> V_33 + V_59 ) ;
F_7 ( V_8 -> V_37 , V_2 -> V_33 + V_34 ) ;
F_7 ( V_8 -> V_54 , V_2 -> V_33 + V_57 ) ;
F_20 ( V_2 -> V_75 , 1 , 2 , true ) ;
return V_96 ;
}
if ( V_6 -> V_97 & V_98 )
F_21 ( V_2 , V_4 ) ;
else
F_24 ( V_2 , V_4 ) ;
F_26 ( V_2 , V_4 ) ;
return V_96 ;
}
static int F_27 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_5 * V_6 = & V_4 -> V_76 -> V_6 ;
F_6 ( V_2 , V_4 , V_6 -> V_11 , V_6 -> V_18 ,
V_8 -> V_19 ) ;
F_12 ( 0 , V_2 -> V_33 + V_58 ) ;
F_12 ( 0 , V_2 -> V_33 + V_59 ) ;
V_8 -> V_54 &= V_55 ;
if ( ( V_6 -> V_97 & V_98 ) == 0 )
V_8 -> V_54 |= V_99 ;
if ( V_6 -> V_100 == V_101 ) {
F_28 ( V_2 -> V_75 ) ;
V_8 -> V_54 |= V_102 | V_103 ;
if ( V_6 -> V_104 == V_105 ) {
V_8 -> V_95 = V_8 -> V_54 ;
V_8 -> V_54 &=
~ ( V_102 | V_99 | V_106 ) ;
V_8 -> V_54 |= V_107 ;
V_8 -> V_94 = 1 ;
} else {
V_8 -> V_94 = 0 ;
}
F_7 ( V_8 -> V_54 , V_2 -> V_33 + V_57 ) ;
if ( V_6 -> V_104 == V_108 )
F_20 ( V_2 -> V_75 , 1 , 2 , true ) ;
} else {
V_8 -> V_54 |= V_107 | V_103 ;
F_7 ( V_8 -> V_54 , V_2 -> V_33 + V_57 ) ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_109 = 0 ;
V_109 |= F_30 ( & V_6 -> V_104 , V_108 | V_105 ) ;
V_109 |= F_30 ( & V_6 -> V_110 , V_111 ) ;
V_109 |= F_30 ( & V_6 -> V_100 ,
V_101 | V_105 ) ;
V_109 |= F_30 ( & V_6 -> V_112 , V_81 ) ;
V_109 |= F_30 ( & V_6 -> V_80 , V_81 | V_113 ) ;
if ( V_109 )
return 1 ;
V_109 |= F_31 ( V_6 -> V_104 ) ;
V_109 |= F_31 ( V_6 -> V_100 ) ;
V_109 |= F_31 ( V_6 -> V_80 ) ;
if ( V_109 )
return 2 ;
V_109 |= F_32 ( & V_6 -> V_114 , 0 ) ;
V_109 |= F_32 ( & V_6 -> V_115 , 0 ) ;
if ( V_6 -> V_100 == V_101 )
V_109 |= F_33 ( & V_6 -> V_116 , 10000 ) ;
else
V_109 |= F_32 ( & V_6 -> V_116 , 0 ) ;
V_109 |= F_32 ( & V_6 -> V_117 ,
V_6 -> V_18 ) ;
if ( V_6 -> V_80 == V_81 )
V_109 |= F_33 ( & V_6 -> V_83 , 1 ) ;
else
V_109 |= F_32 ( & V_6 -> V_83 , 0 ) ;
if ( V_109 )
return 3 ;
if ( V_6 -> V_100 == V_101 ) {
unsigned int V_118 = V_6 -> V_116 ;
F_34 ( V_2 -> V_75 , & V_118 , V_6 -> V_97 ) ;
V_109 |= F_32 ( & V_6 -> V_116 , V_118 ) ;
}
if ( V_109 )
return 4 ;
V_109 |= F_1 ( V_2 , V_4 , V_6 ) ;
if ( V_109 )
return 5 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_38 * V_39 ,
unsigned int * V_52 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
switch ( V_52 [ 0 ] ) {
case V_119 :
switch ( V_52 [ 1 ] ) {
case 0 :
V_8 -> V_95 &= ~ V_55 ;
break;
case 1 :
V_8 -> V_95 |= V_55 ;
break;
default:
return - V_24 ;
}
F_7 ( V_8 -> V_95 , V_2 -> V_33 + V_57 ) ;
break;
case V_120 :
if ( V_8 -> V_95 & V_55 ) {
V_52 [ 1 ] = 1 ;
V_52 [ 2 ] = 0 ;
} else {
V_52 [ 1 ] = 0 ;
V_52 [ 2 ] = V_121 ;
}
break;
default:
return - V_24 ;
}
return V_39 -> V_61 ;
}
static int F_36 ( struct V_1 * V_2 )
{
const struct V_25 * V_26 = V_2 -> V_27 ;
struct V_7 * V_8 = V_2 -> V_9 ;
V_8 -> V_54 = V_56 | V_55 ;
F_7 ( V_8 -> V_54 , V_2 -> V_33 + V_57 ) ;
F_12 ( 0 , V_2 -> V_33 + V_58 ) ;
F_12 ( 0 , V_2 -> V_33 + V_59 ) ;
V_8 -> V_67 = 0 ;
if ( V_26 -> V_122 ) {
F_12 ( V_8 -> V_67 , V_2 -> V_33 + V_68 ) ;
F_7 ( 0 , V_2 -> V_33 + V_65 ) ;
F_7 ( 0 , V_2 -> V_33 + V_64 ) ;
}
F_7 ( 0 , V_2 -> V_33 + V_71 ) ;
F_12 ( 0 , V_2 -> V_33 + V_58 ) ;
F_12 ( 0 , V_2 -> V_33 + V_59 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
F_12 ( V_123 , V_2 -> V_33 + V_124 ) ;
V_8 -> V_67 = 0xAA ;
F_12 ( V_8 -> V_67 , V_2 -> V_33 + V_72 ) ;
F_7 ( 0x0800 , V_2 -> V_33 + V_73 ) ;
F_7 ( 0x0800 , V_2 -> V_33 + V_125 ) ;
F_7 ( 0x0800 , V_2 -> V_33 + V_126 ) ;
F_7 ( 0x0800 , V_2 -> V_33 + V_127 ) ;
F_12 ( 0 , V_2 -> V_33 + V_74 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
const struct V_25 * V_26 = V_2 -> V_27 ;
if ( V_26 -> V_128 )
return F_37 ( V_2 ) ;
return F_36 ( V_2 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
unsigned long V_40 )
{
struct V_129 * V_130 = F_40 ( V_2 ) ;
const struct V_25 * V_26 = NULL ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
int V_53 , V_131 , V_132 ;
if ( V_40 < F_41 ( V_133 ) )
V_26 = & V_133 [ V_40 ] ;
if ( ! V_26 )
return - V_134 ;
V_2 -> V_27 = V_26 ;
V_2 -> V_135 = V_26 -> V_136 ;
V_8 = F_42 ( V_2 , sizeof( * V_8 ) ) ;
if ( ! V_8 )
return - V_137 ;
V_53 = F_43 ( V_2 ) ;
if ( V_53 )
return V_53 ;
V_2 -> V_33 = F_44 ( V_130 , 2 ) ;
V_2 -> V_75 = F_45 ( V_2 -> V_33 + V_138 ,
V_121 , V_139 , 0 ) ;
if ( ! V_2 -> V_75 )
return - V_137 ;
V_132 = 0 ;
if ( V_26 -> V_140 )
V_132 ++ ;
if ( V_26 -> V_122 )
V_132 ++ ;
if ( V_26 -> V_141 )
V_132 += 2 ;
if ( V_26 -> V_142 )
V_132 ++ ;
V_53 = F_46 ( V_2 , V_132 ) ;
if ( V_53 )
return V_53 ;
F_38 ( V_2 ) ;
if ( V_26 -> V_143 && V_130 -> V_88 ) {
V_53 = F_47 ( V_130 -> V_88 , F_25 ,
V_144 , V_2 -> V_135 , V_2 ) ;
if ( V_53 == 0 )
V_2 -> V_88 = V_130 -> V_88 ;
}
V_131 = 0 ;
if ( V_26 -> V_140 ) {
V_4 = & V_2 -> V_145 [ V_131 ] ;
V_4 -> type = V_146 ;
V_4 -> V_147 = V_148 | V_149 | V_150 ;
if ( V_26 -> V_151 )
V_4 -> V_147 |= V_152 ;
V_4 -> V_14 = V_26 -> V_140 ;
V_4 -> V_51 = 0x0fff ;
V_4 -> V_153 = V_26 -> V_154 ;
V_4 -> V_155 = F_11 ;
if ( V_2 -> V_88 ) {
V_2 -> V_92 = V_4 ;
V_4 -> V_147 |= V_156 ;
V_4 -> V_157 = V_4 -> V_14 ;
V_4 -> V_158 = F_29 ;
V_4 -> V_159 = F_27 ;
V_4 -> V_160 = F_19 ;
}
V_131 ++ ;
}
if ( V_26 -> V_122 ) {
V_4 = & V_2 -> V_145 [ V_131 ] ;
V_4 -> type = V_161 ;
V_4 -> V_147 = V_162 | V_150 | V_149 ;
V_4 -> V_51 = 0x0fff ;
if ( V_26 -> V_128 ) {
V_4 -> V_14 = 4 ;
V_4 -> V_153 = & V_163 ;
V_4 -> V_164 = F_18 ;
} else {
V_4 -> V_14 = 2 ;
V_4 -> V_153 = & V_165 ;
V_4 -> V_164 = F_14 ;
}
V_53 = F_48 ( V_4 ) ;
if ( V_53 )
return V_53 ;
if ( V_26 -> V_128 ) {
int V_17 ;
for ( V_17 = 0 ; V_17 < V_4 -> V_14 ; V_17 ++ )
V_4 -> V_66 [ V_17 ] = 0x0800 ;
}
V_131 ++ ;
}
if ( V_26 -> V_141 ) {
V_4 = & V_2 -> V_145 [ V_131 ] ;
V_4 -> type = V_166 ;
V_4 -> V_147 = V_148 ;
V_4 -> V_14 = 16 ;
V_4 -> V_51 = 1 ;
V_4 -> V_153 = & V_167 ;
V_4 -> V_168 = F_15 ;
V_131 ++ ;
V_4 = & V_2 -> V_145 [ V_131 ] ;
V_4 -> type = V_169 ;
V_4 -> V_147 = V_162 ;
V_4 -> V_14 = 16 ;
V_4 -> V_51 = 1 ;
V_4 -> V_153 = & V_167 ;
V_4 -> V_168 = F_16 ;
V_131 ++ ;
}
if ( V_26 -> V_142 ) {
V_4 = & V_2 -> V_145 [ V_131 ] ;
F_49 ( V_4 , V_2 -> V_75 ) ;
V_2 -> V_75 -> V_170 = F_35 ;
F_50 ( V_2 -> V_75 , 1 , true ) ;
F_50 ( V_2 -> V_75 , 2 , true ) ;
V_131 ++ ;
}
V_8 -> V_87 = ( V_26 -> V_171 ) ? 2048 : 512 ;
return 0 ;
}
static void F_51 ( struct V_1 * V_2 )
{
if ( V_2 -> V_33 )
F_38 ( V_2 ) ;
F_52 ( V_2 ) ;
}
static int F_53 ( struct V_129 * V_2 ,
const struct V_172 * V_173 )
{
return F_54 ( V_2 , & V_174 ,
V_173 -> V_175 ) ;
}

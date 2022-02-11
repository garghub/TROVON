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
unsigned int V_46 = V_4 -> V_63 [ V_20 ] ;
int V_17 ;
V_8 -> V_64 &= ~ ( 1 << ( V_20 << 1 ) ) ;
V_8 -> V_64 |= ( V_30 << ( V_20 << 1 ) ) ;
F_7 ( V_8 -> V_64 , V_2 -> V_33 + V_65 ) ;
for ( V_17 = 0 ; V_17 < V_39 -> V_61 ; V_17 ++ ) {
V_46 = V_52 [ V_17 ] ;
F_7 ( V_46 , V_2 -> V_33 + F_15 ( V_20 ) ) ;
}
V_4 -> V_63 [ V_20 ] = V_46 ;
return V_39 -> V_61 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_38 * V_39 ,
unsigned int * V_52 )
{
V_52 [ 1 ] = F_9 ( V_2 -> V_33 + V_66 ) ;
return V_39 -> V_61 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_38 * V_39 ,
unsigned int * V_52 )
{
if ( F_18 ( V_4 , V_52 ) )
F_7 ( V_4 -> V_67 , V_2 -> V_33 + V_68 ) ;
V_52 [ 1 ] = V_4 -> V_67 ;
return V_39 -> V_61 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_38 * V_39 ,
unsigned int * V_52 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_20 = F_2 ( V_39 -> V_60 ) ;
unsigned int V_30 = F_5 ( V_39 -> V_60 ) ;
unsigned int V_46 ;
int V_17 ;
V_46 = V_8 -> V_64 & ( ~ ( 0x03 << ( V_20 << 1 ) ) ) ;
V_46 |= ( V_30 << ( V_20 << 1 ) ) ;
if ( V_46 != V_8 -> V_64 ) {
F_12 ( V_46 , V_2 -> V_33 + V_69 ) ;
V_8 -> V_64 = V_46 ;
}
V_46 = V_4 -> V_63 [ V_20 ] ;
for ( V_17 = 0 ; V_17 < V_39 -> V_61 ; V_17 ++ ) {
V_46 = V_52 [ V_17 ] ;
F_7 ( V_46 , V_2 -> V_33 + F_20 ( V_20 ) ) ;
F_12 ( 0 , V_2 -> V_33 + V_70 ) ;
}
V_4 -> V_63 [ V_20 ] = V_46 ;
return V_39 -> V_61 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
V_8 -> V_54 &= V_55 ;
V_8 -> V_54 |= V_56 ;
F_7 ( V_8 -> V_54 , V_2 -> V_33 + V_57 ) ;
F_22 ( V_2 -> V_71 , 1 , 2 , false ) ;
F_12 ( 0 , V_2 -> V_33 + V_58 ) ;
F_12 ( 0 , V_2 -> V_33 + V_59 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_72 -> V_6 ;
unsigned int V_41 ;
unsigned int V_46 ;
int V_53 ;
V_41 = F_9 ( V_2 -> V_33 + V_42 ) ;
if ( V_41 & V_43 ) {
F_24 ( V_2 -> V_23 , L_5 , V_41 ) ;
V_4 -> V_72 -> V_73 |= V_74 ;
return;
}
if ( V_41 & V_75 ) {
F_24 ( V_2 -> V_23 ,
L_6 , V_41 ) ;
V_4 -> V_72 -> V_73 |= V_74 ;
return;
}
F_12 ( 0 , V_2 -> V_33 + V_59 ) ;
for (; ! ( F_9 ( V_2 -> V_33 + V_42 ) & V_43 ) ; ) {
V_53 = F_10 ( V_2 , V_4 , V_4 -> V_72 -> V_45 , & V_46 ) ;
if ( V_53 ) {
V_4 -> V_72 -> V_73 |= V_74 ;
break;
}
F_25 ( V_4 , & V_46 , 1 ) ;
if ( V_6 -> V_76 == V_77 &&
V_4 -> V_72 -> V_78 >= V_6 -> V_79 ) {
V_4 -> V_72 -> V_73 |= V_80 ;
break;
}
}
F_12 ( 0 , V_2 -> V_33 + V_59 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_81 * V_72 = V_4 -> V_72 ;
struct V_5 * V_6 = & V_72 -> V_6 ;
unsigned int V_41 ;
int V_17 ;
V_41 = F_9 ( V_2 -> V_33 + V_42 ) ;
if ( ! ( V_41 & V_82 ) ) {
F_24 ( V_2 -> V_23 , L_7 ) ;
V_72 -> V_73 |= V_74 ;
return;
}
if ( V_41 & V_75 ) {
F_24 ( V_2 -> V_23 ,
L_8 ) ;
V_72 -> V_73 |= V_74 ;
return;
}
for ( V_17 = 0 ; V_17 < V_8 -> V_83 ; V_17 ++ ) {
unsigned int V_46 ;
int V_53 ;
V_53 = F_10 ( V_2 , V_4 , V_4 -> V_72 -> V_45 , & V_46 ) ;
if ( V_53 ) {
V_4 -> V_72 -> V_73 |= V_74 ;
break;
}
if ( ! F_25 ( V_4 , & V_46 , 1 ) )
break;
if ( V_6 -> V_76 == V_77 &&
V_72 -> V_78 >= V_6 -> V_79 ) {
V_72 -> V_73 |= V_80 ;
break;
}
}
F_12 ( 0 , V_2 -> V_33 + V_59 ) ;
}
static T_1 F_27 ( int V_84 , void * V_85 )
{
struct V_1 * V_2 = V_85 ;
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
if ( ! V_2 -> V_86 )
return V_87 ;
V_4 = V_2 -> V_88 ;
V_6 = & V_4 -> V_72 -> V_6 ;
if ( ! ( F_9 ( V_2 -> V_33 + V_42 ) & V_89 ) )
return V_87 ;
if ( V_8 -> V_90 ) {
V_8 -> V_90 = 0 ;
V_8 -> V_54 &= V_55 ;
V_8 -> V_54 |= V_56 ;
F_7 ( V_8 -> V_54 , V_2 -> V_33 + V_57 ) ;
V_8 -> V_54 = V_8 -> V_91 ;
F_12 ( 0 , V_2 -> V_33 + V_58 ) ;
F_12 ( 0 , V_2 -> V_33 + V_59 ) ;
F_7 ( V_8 -> V_37 , V_2 -> V_33 + V_34 ) ;
F_7 ( V_8 -> V_54 , V_2 -> V_33 + V_57 ) ;
F_22 ( V_2 -> V_71 , 1 , 2 , true ) ;
return V_92 ;
}
if ( V_6 -> V_93 & V_94 )
F_23 ( V_2 , V_4 ) ;
else
F_26 ( V_2 , V_4 ) ;
F_28 ( V_2 , V_4 ) ;
return V_92 ;
}
static int F_29 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_5 * V_6 = & V_4 -> V_72 -> V_6 ;
F_6 ( V_2 , V_4 , V_6 -> V_11 , V_6 -> V_18 ,
V_8 -> V_19 ) ;
F_12 ( 0 , V_2 -> V_33 + V_58 ) ;
F_12 ( 0 , V_2 -> V_33 + V_59 ) ;
V_8 -> V_54 &= V_55 ;
if ( ( V_6 -> V_93 & V_94 ) == 0 )
V_8 -> V_54 |= V_95 ;
if ( V_6 -> V_96 == V_97 ) {
F_30 ( V_2 -> V_71 ) ;
V_8 -> V_54 |= V_98 | V_99 ;
if ( V_6 -> V_100 == V_101 ) {
V_8 -> V_91 = V_8 -> V_54 ;
V_8 -> V_54 &= ~ ( V_98 |
V_95 |
V_102 ) ;
V_8 -> V_54 |= V_103 ;
V_8 -> V_90 = 1 ;
} else {
V_8 -> V_90 = 0 ;
}
F_7 ( V_8 -> V_54 , V_2 -> V_33 + V_57 ) ;
if ( V_6 -> V_100 == V_104 )
F_22 ( V_2 -> V_71 , 1 , 2 , true ) ;
} else {
V_8 -> V_54 |= V_103 | V_99 ;
F_7 ( V_8 -> V_54 , V_2 -> V_33 + V_57 ) ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_105 = 0 ;
V_105 |= F_32 ( & V_6 -> V_100 , V_104 | V_101 ) ;
V_105 |= F_32 ( & V_6 -> V_106 , V_107 ) ;
V_105 |= F_32 ( & V_6 -> V_96 ,
V_97 | V_101 ) ;
V_105 |= F_32 ( & V_6 -> V_108 , V_77 ) ;
V_105 |= F_32 ( & V_6 -> V_76 , V_77 | V_109 ) ;
if ( V_105 )
return 1 ;
V_105 |= F_33 ( V_6 -> V_100 ) ;
V_105 |= F_33 ( V_6 -> V_96 ) ;
V_105 |= F_33 ( V_6 -> V_76 ) ;
if ( V_105 )
return 2 ;
V_105 |= F_34 ( & V_6 -> V_110 , 0 ) ;
V_105 |= F_34 ( & V_6 -> V_111 , 0 ) ;
if ( V_6 -> V_96 == V_97 )
V_105 |= F_35 ( & V_6 -> V_112 , 10000 ) ;
else
V_105 |= F_34 ( & V_6 -> V_112 , 0 ) ;
V_105 |= F_34 ( & V_6 -> V_113 ,
V_6 -> V_18 ) ;
if ( V_6 -> V_76 == V_77 )
V_105 |= F_35 ( & V_6 -> V_79 , 1 ) ;
else
V_105 |= F_34 ( & V_6 -> V_79 , 0 ) ;
if ( V_105 )
return 3 ;
if ( V_6 -> V_96 == V_97 ) {
unsigned int V_114 = V_6 -> V_112 ;
F_36 ( V_2 -> V_71 , & V_114 , V_6 -> V_93 ) ;
V_105 |= F_34 ( & V_6 -> V_112 , V_114 ) ;
}
if ( V_105 )
return 4 ;
V_105 |= F_1 ( V_2 , V_4 , V_6 ) ;
if ( V_105 )
return 5 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_38 * V_39 ,
unsigned int * V_52 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
switch ( V_52 [ 0 ] ) {
case V_115 :
switch ( V_52 [ 1 ] ) {
case 0 :
V_8 -> V_91 &= ~ V_55 ;
break;
case 1 :
V_8 -> V_91 |= V_55 ;
break;
default:
return - V_24 ;
}
F_7 ( V_8 -> V_91 , V_2 -> V_33 + V_57 ) ;
break;
case V_116 :
if ( V_8 -> V_91 & V_55 ) {
V_52 [ 1 ] = 1 ;
V_52 [ 2 ] = 0 ;
} else {
V_52 [ 1 ] = 0 ;
V_52 [ 2 ] = V_117 ;
}
break;
default:
return - V_24 ;
}
return V_39 -> V_61 ;
}
static int F_38 ( struct V_1 * V_2 )
{
const struct V_25 * V_26 = V_2 -> V_27 ;
struct V_7 * V_8 = V_2 -> V_9 ;
V_8 -> V_54 = V_56 | V_55 ;
F_7 ( V_8 -> V_54 , V_2 -> V_33 + V_57 ) ;
F_12 ( 0 , V_2 -> V_33 + V_58 ) ;
F_12 ( 0 , V_2 -> V_33 + V_59 ) ;
V_8 -> V_64 = 0 ;
if ( V_26 -> V_118 ) {
F_12 ( V_8 -> V_64 , V_2 -> V_33 + V_65 ) ;
F_7 ( 0 , V_2 -> V_33 + F_15 ( 0 ) ) ;
F_7 ( 0 , V_2 -> V_33 + F_15 ( 1 ) ) ;
}
F_7 ( 0 , V_2 -> V_33 + V_68 ) ;
F_12 ( 0 , V_2 -> V_33 + V_58 ) ;
F_12 ( 0 , V_2 -> V_33 + V_59 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
F_12 ( V_119 , V_2 -> V_33 + V_120 ) ;
V_8 -> V_64 = 0xAA ;
F_12 ( V_8 -> V_64 , V_2 -> V_33 + V_69 ) ;
F_7 ( 0x0800 , V_2 -> V_33 + F_20 ( 0 ) ) ;
F_7 ( 0x0800 , V_2 -> V_33 + F_20 ( 1 ) ) ;
F_7 ( 0x0800 , V_2 -> V_33 + F_20 ( 2 ) ) ;
F_7 ( 0x0800 , V_2 -> V_33 + F_20 ( 3 ) ) ;
F_12 ( 0 , V_2 -> V_33 + V_70 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
const struct V_25 * V_26 = V_2 -> V_27 ;
if ( V_26 -> V_121 )
return F_39 ( V_2 ) ;
return F_38 ( V_2 ) ;
}
static int F_41 ( struct V_1 * V_2 ,
unsigned long V_40 )
{
struct V_122 * V_123 = F_42 ( V_2 ) ;
const struct V_25 * V_26 = NULL ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
int V_53 , V_124 , V_125 ;
if ( V_40 < F_43 ( V_126 ) )
V_26 = & V_126 [ V_40 ] ;
if ( ! V_26 )
return - V_127 ;
V_2 -> V_27 = V_26 ;
V_2 -> V_128 = V_26 -> V_129 ;
V_8 = F_44 ( V_2 , sizeof( * V_8 ) ) ;
if ( ! V_8 )
return - V_130 ;
V_53 = F_45 ( V_2 ) ;
if ( V_53 )
return V_53 ;
V_2 -> V_33 = F_46 ( V_123 , 2 ) ;
V_2 -> V_71 = F_47 ( V_2 -> V_33 + V_131 ,
V_117 , V_132 , 0 ) ;
if ( ! V_2 -> V_71 )
return - V_130 ;
V_125 = 0 ;
if ( V_26 -> V_133 )
V_125 ++ ;
if ( V_26 -> V_118 )
V_125 ++ ;
if ( V_26 -> V_134 )
V_125 += 2 ;
if ( V_26 -> V_135 )
V_125 ++ ;
V_53 = F_48 ( V_2 , V_125 ) ;
if ( V_53 )
return V_53 ;
F_40 ( V_2 ) ;
if ( V_26 -> V_136 && V_123 -> V_84 ) {
V_53 = F_49 ( V_123 -> V_84 , F_27 ,
V_137 , V_2 -> V_128 , V_2 ) ;
if ( V_53 == 0 )
V_2 -> V_84 = V_123 -> V_84 ;
}
V_124 = 0 ;
if ( V_26 -> V_133 ) {
V_4 = & V_2 -> V_138 [ V_124 ] ;
V_4 -> type = V_139 ;
V_4 -> V_140 = V_141 | V_142 | V_143 ;
if ( V_26 -> V_144 )
V_4 -> V_140 |= V_145 ;
V_4 -> V_14 = V_26 -> V_133 ;
V_4 -> V_51 = 0x0fff ;
V_4 -> V_146 = V_26 -> V_147 ;
V_4 -> V_148 = F_11 ;
if ( V_2 -> V_84 ) {
V_2 -> V_88 = V_4 ;
V_4 -> V_140 |= V_149 ;
V_4 -> V_150 = V_4 -> V_14 ;
V_4 -> V_151 = F_31 ;
V_4 -> V_152 = F_29 ;
V_4 -> V_153 = F_21 ;
}
V_124 ++ ;
}
if ( V_26 -> V_118 ) {
V_4 = & V_2 -> V_138 [ V_124 ] ;
V_4 -> type = V_154 ;
V_4 -> V_140 = V_155 | V_143 | V_142 ;
V_4 -> V_51 = 0x0fff ;
if ( V_26 -> V_121 ) {
V_4 -> V_14 = 4 ;
V_4 -> V_146 = & V_156 ;
V_4 -> V_157 = F_19 ;
} else {
V_4 -> V_14 = 2 ;
V_4 -> V_146 = & V_158 ;
V_4 -> V_157 = F_14 ;
}
V_53 = F_50 ( V_4 ) ;
if ( V_53 )
return V_53 ;
if ( V_26 -> V_121 ) {
int V_17 ;
for ( V_17 = 0 ; V_17 < V_4 -> V_14 ; V_17 ++ )
V_4 -> V_63 [ V_17 ] = 0x0800 ;
}
V_124 ++ ;
}
if ( V_26 -> V_134 ) {
V_4 = & V_2 -> V_138 [ V_124 ] ;
V_4 -> type = V_159 ;
V_4 -> V_140 = V_141 ;
V_4 -> V_14 = 16 ;
V_4 -> V_51 = 1 ;
V_4 -> V_146 = & V_160 ;
V_4 -> V_161 = F_16 ;
V_124 ++ ;
V_4 = & V_2 -> V_138 [ V_124 ] ;
V_4 -> type = V_162 ;
V_4 -> V_140 = V_155 ;
V_4 -> V_14 = 16 ;
V_4 -> V_51 = 1 ;
V_4 -> V_146 = & V_160 ;
V_4 -> V_161 = F_17 ;
V_124 ++ ;
}
if ( V_26 -> V_135 ) {
V_4 = & V_2 -> V_138 [ V_124 ] ;
F_51 ( V_4 , V_2 -> V_71 ) ;
V_2 -> V_71 -> V_163 = F_37 ;
F_52 ( V_2 -> V_71 , 1 , true ) ;
F_52 ( V_2 -> V_71 , 2 , true ) ;
V_124 ++ ;
}
V_8 -> V_83 = ( V_26 -> V_164 ) ? 2048 : 512 ;
return 0 ;
}
static void F_53 ( struct V_1 * V_2 )
{
if ( V_2 -> V_33 )
F_40 ( V_2 ) ;
F_54 ( V_2 ) ;
}
static int F_55 ( struct V_122 * V_2 ,
const struct V_165 * V_166 )
{
return F_56 ( V_2 , & V_167 ,
V_166 -> V_168 ) ;
}

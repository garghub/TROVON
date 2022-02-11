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
static void F_18 ( struct V_1 * V_2 ,
bool V_72 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned long V_73 = V_2 -> V_33 + V_74 ;
F_19 ( V_73 , 1 , 2 , V_75 | V_76 ) ;
F_19 ( V_73 , 1 , 1 , V_75 | V_76 ) ;
if ( V_72 ) {
F_20 ( V_73 , 1 , 2 , V_8 -> V_77 ) ;
F_20 ( V_73 , 1 , 1 , V_8 -> V_78 ) ;
}
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_38 * V_39 ,
unsigned int * V_52 )
{
unsigned int V_79 , V_80 , V_81 ;
int V_17 ;
V_81 = 0xD2 ;
for ( V_17 = 0 ; V_17 < V_39 -> V_61 ; V_17 ++ ) {
F_7 ( V_81 , V_2 -> V_33 + V_82 ) ;
V_80 = F_9 ( V_2 -> V_33 + V_83 ) & 0xFF ;
V_79 = F_9 ( V_2 -> V_33 + V_83 ) & 0xFF ;
V_52 [ 0 ] = V_80 | ( V_79 << 8 ) ;
}
return V_39 -> V_61 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_38 * V_39 ,
unsigned int * V_52 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
T_1 V_79 , V_80 , V_81 , V_41 ;
V_80 = V_52 [ 0 ] & 0x00FF ;
V_79 = ( V_52 [ 0 ] & 0xFF00 ) >> 8 ;
F_7 ( V_80 , V_2 -> V_33 + V_83 ) ;
F_7 ( V_79 , V_2 -> V_33 + V_83 ) ;
if ( V_8 -> V_84 ) {
V_81 = 0xE2 ;
do {
F_7 ( V_81 , V_2 -> V_33 + V_82 ) ;
V_41 = F_9 ( V_2 -> V_33 + V_83 ) & 0xFF ;
} while ( V_41 & 0x40 );
}
return V_39 -> V_61 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_38 * V_39 ,
unsigned int * V_52 )
{
#ifdef F_24
struct V_7 * V_8 = V_2 -> V_9 ;
T_1 V_81 = 0 ;
V_8 -> V_84 = V_52 [ 0 ] & 0x20 ;
if ( ! ( V_52 [ 0 ] & 0x10 ) ) {
V_8 -> V_54 &= ~ V_55 ;
} else {
V_8 -> V_54 |= V_55 ;
}
F_7 ( V_8 -> V_54 , V_2 -> V_33 + V_57 ) ;
if ( V_52 [ 0 ] & 0x01 )
V_81 |= V_85 ;
if ( V_52 [ 0 ] & 0x02 )
V_81 |= V_86 ;
if ( V_52 [ 0 ] & 0x04 )
V_81 |= V_87 ;
if ( V_52 [ 0 ] & 0x08 )
V_81 |= V_88 ;
V_81 |= V_89 ;
V_81 |= V_90 ;
F_7 ( V_81 , V_2 -> V_33 + V_82 ) ;
#endif
return 1 ;
}
static int F_25 ( struct V_1 * V_2 ,
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
F_12 ( V_46 , V_2 -> V_33 + V_91 ) ;
V_8 -> V_67 = V_46 ;
}
V_46 = V_4 -> V_66 [ V_20 ] ;
for ( V_17 = 0 ; V_17 < V_39 -> V_61 ; V_17 ++ ) {
V_46 = V_52 [ V_17 ] ;
F_7 ( V_46 , V_2 -> V_33 + V_92 + ( V_20 << 1 ) ) ;
F_12 ( 0 , V_2 -> V_33 + V_93 ) ;
}
V_4 -> V_66 [ V_20 ] = V_46 ;
return V_39 -> V_61 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
V_8 -> V_54 &= V_55 ;
V_8 -> V_54 |= V_56 ;
F_7 ( V_8 -> V_54 , V_2 -> V_33 + V_57 ) ;
F_18 ( V_2 , false ) ;
F_12 ( 0 , V_2 -> V_33 + V_58 ) ;
F_12 ( 0 , V_2 -> V_33 + V_59 ) ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_94 -> V_6 ;
unsigned int V_41 ;
unsigned int V_46 ;
int V_53 ;
V_41 = F_9 ( V_2 -> V_33 + V_42 ) ;
if ( V_41 & V_43 ) {
F_28 ( V_2 -> V_23 , L_5 , V_41 ) ;
V_4 -> V_94 -> V_95 |= V_96 ;
return;
}
if ( V_41 & V_97 ) {
F_28 ( V_2 -> V_23 ,
L_6 , V_41 ) ;
V_4 -> V_94 -> V_95 |= V_96 ;
return;
}
F_12 ( 0 , V_2 -> V_33 + V_59 ) ;
for (; ! ( F_9 ( V_2 -> V_33 + V_42 ) & V_43 ) ; ) {
V_53 = F_10 ( V_2 , V_4 , V_4 -> V_94 -> V_45 , & V_46 ) ;
if ( V_53 ) {
V_4 -> V_94 -> V_95 |= V_96 ;
break;
}
F_29 ( V_4 , & V_46 , 1 ) ;
if ( V_6 -> V_98 == V_99 &&
V_4 -> V_94 -> V_100 >= V_6 -> V_101 ) {
V_4 -> V_94 -> V_95 |= V_102 ;
break;
}
}
F_12 ( 0 , V_2 -> V_33 + V_59 ) ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_103 * V_94 = V_4 -> V_94 ;
struct V_5 * V_6 = & V_94 -> V_6 ;
unsigned int V_41 ;
int V_17 ;
V_41 = F_9 ( V_2 -> V_33 + V_42 ) ;
if ( ! ( V_41 & V_104 ) ) {
F_28 ( V_2 -> V_23 , L_7 ) ;
V_94 -> V_95 |= V_96 ;
return;
}
if ( V_41 & V_97 ) {
F_28 ( V_2 -> V_23 ,
L_8 ) ;
V_94 -> V_95 |= V_96 ;
return;
}
for ( V_17 = 0 ; V_17 < V_8 -> V_105 ; V_17 ++ ) {
unsigned int V_46 ;
int V_53 ;
V_53 = F_10 ( V_2 , V_4 , V_4 -> V_94 -> V_45 , & V_46 ) ;
if ( V_53 ) {
V_4 -> V_94 -> V_95 |= V_96 ;
break;
}
if ( ! F_29 ( V_4 , & V_46 , 1 ) )
break;
if ( V_6 -> V_98 == V_99 &&
V_94 -> V_100 >= V_6 -> V_101 ) {
V_94 -> V_95 |= V_102 ;
break;
}
}
F_12 ( 0 , V_2 -> V_33 + V_59 ) ;
}
static T_2 F_31 ( int V_106 , void * V_107 )
{
struct V_1 * V_2 = V_107 ;
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
if ( ! V_2 -> V_108 )
return V_109 ;
V_4 = V_2 -> V_110 ;
V_6 = & V_4 -> V_94 -> V_6 ;
if ( ! ( F_9 ( V_2 -> V_33 + V_42 ) & V_111 ) )
return V_109 ;
if ( V_8 -> V_112 ) {
V_8 -> V_112 = 0 ;
V_8 -> V_54 &= V_55 ;
V_8 -> V_54 |= V_56 ;
F_7 ( V_8 -> V_54 , V_2 -> V_33 + V_57 ) ;
V_8 -> V_54 = V_8 -> V_113 ;
F_12 ( 0 , V_2 -> V_33 + V_58 ) ;
F_12 ( 0 , V_2 -> V_33 + V_59 ) ;
F_7 ( V_8 -> V_37 , V_2 -> V_33 + V_34 ) ;
F_7 ( V_8 -> V_54 , V_2 -> V_33 + V_57 ) ;
F_18 ( V_2 , true ) ;
return V_114 ;
}
if ( V_6 -> V_115 & V_116 )
F_27 ( V_2 , V_4 ) ;
else
F_30 ( V_2 , V_4 ) ;
F_32 ( V_2 , V_4 ) ;
return V_114 ;
}
static int F_33 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_5 * V_6 = & V_4 -> V_94 -> V_6 ;
F_18 ( V_2 , false ) ;
F_6 ( V_2 , V_4 , V_6 -> V_11 , V_6 -> V_18 ,
V_8 -> V_19 ) ;
F_12 ( 0 , V_2 -> V_33 + V_58 ) ;
F_12 ( 0 , V_2 -> V_33 + V_59 ) ;
V_8 -> V_54 &= V_55 ;
if ( ( V_6 -> V_115 & V_116 ) == 0 )
V_8 -> V_54 |= V_117 ;
V_8 -> V_78 = V_8 -> V_118 ;
V_8 -> V_77 = V_8 -> V_119 ;
if ( V_6 -> V_120 == V_121 ) {
V_8 -> V_54 |= V_122 | V_123 ;
if ( V_6 -> V_124 == V_125 ) {
V_8 -> V_113 = V_8 -> V_54 ;
V_8 -> V_54 &=
~ ( V_122 | V_117 | V_126 ) ;
V_8 -> V_54 |= V_127 ;
V_8 -> V_112 = 1 ;
} else {
V_8 -> V_112 = 0 ;
}
F_7 ( V_8 -> V_54 , V_2 -> V_33 + V_57 ) ;
if ( V_6 -> V_124 == V_128 )
F_18 ( V_2 , true ) ;
} else {
V_8 -> V_54 |= V_127 | V_123 ;
F_7 ( V_8 -> V_54 , V_2 -> V_33 + V_57 ) ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_129 = 0 ;
unsigned int V_130 ;
V_129 |= F_35 ( & V_6 -> V_124 , V_128 | V_125 ) ;
V_129 |= F_35 ( & V_6 -> V_131 , V_132 ) ;
V_129 |= F_35 ( & V_6 -> V_120 , V_121 | V_125 ) ;
V_129 |= F_35 ( & V_6 -> V_133 , V_99 ) ;
V_129 |= F_35 ( & V_6 -> V_98 , V_99 | V_134 ) ;
if ( V_129 )
return 1 ;
V_129 |= F_36 ( V_6 -> V_124 ) ;
V_129 |= F_36 ( V_6 -> V_120 ) ;
V_129 |= F_36 ( V_6 -> V_98 ) ;
if ( V_129 )
return 2 ;
V_129 |= F_37 ( & V_6 -> V_135 , 0 ) ;
V_129 |= F_37 ( & V_6 -> V_136 , 0 ) ;
if ( V_6 -> V_120 == V_121 )
V_129 |= F_38 ( & V_6 -> V_137 , 10000 ) ;
else
V_129 |= F_37 ( & V_6 -> V_137 , 0 ) ;
V_129 |= F_37 ( & V_6 -> V_138 , V_6 -> V_18 ) ;
if ( V_6 -> V_98 == V_99 )
V_129 |= F_38 ( & V_6 -> V_101 , 1 ) ;
else
V_129 |= F_37 ( & V_6 -> V_101 , 0 ) ;
if ( V_129 )
return 3 ;
if ( V_6 -> V_120 == V_121 ) {
V_130 = V_6 -> V_137 ;
F_39 ( V_139 ,
& V_8 -> V_118 ,
& V_8 -> V_119 ,
& V_130 , V_6 -> V_115 ) ;
V_129 |= F_37 ( & V_6 -> V_137 , V_130 ) ;
}
if ( V_129 )
return 4 ;
V_129 |= F_1 ( V_2 , V_4 , V_6 ) ;
if ( V_129 )
return 5 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
const struct V_25 * V_26 = V_2 -> V_27 ;
struct V_7 * V_8 = V_2 -> V_9 ;
F_7 ( 0x30 , V_2 -> V_33 + V_82 ) ;
V_8 -> V_54 = V_56 | V_55 ;
F_7 ( V_8 -> V_54 , V_2 -> V_33 + V_57 ) ;
F_12 ( 0 , V_2 -> V_33 + V_58 ) ;
F_12 ( 0 , V_2 -> V_33 + V_59 ) ;
F_18 ( V_2 , false ) ;
V_8 -> V_67 = 0 ;
if ( V_26 -> V_140 ) {
F_12 ( V_8 -> V_67 , V_2 -> V_33 + V_68 ) ;
F_7 ( 0 , V_2 -> V_33 + V_65 ) ;
F_7 ( 0 , V_2 -> V_33 + V_64 ) ;
}
F_7 ( 0 , V_2 -> V_33 + V_71 ) ;
F_12 ( 0 , V_2 -> V_33 + V_58 ) ;
F_12 ( 0 , V_2 -> V_33 + V_59 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
F_12 ( V_141 , V_2 -> V_33 + V_142 ) ;
V_8 -> V_67 = 0xAA ;
F_12 ( V_8 -> V_67 , V_2 -> V_33 + V_91 ) ;
F_7 ( 0x0800 , V_2 -> V_33 + V_92 ) ;
F_7 ( 0x0800 , V_2 -> V_33 + V_143 ) ;
F_7 ( 0x0800 , V_2 -> V_33 + V_144 ) ;
F_7 ( 0x0800 , V_2 -> V_33 + V_145 ) ;
F_12 ( 0 , V_2 -> V_33 + V_93 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
const struct V_25 * V_26 = V_2 -> V_27 ;
if ( V_26 -> V_146 )
return F_41 ( V_2 ) ;
return F_40 ( V_2 ) ;
}
static int F_43 ( struct V_1 * V_2 ,
unsigned long V_40 )
{
struct V_147 * V_148 = F_44 ( V_2 ) ;
const struct V_25 * V_26 = NULL ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
int V_53 , V_149 , V_150 ;
if ( V_40 < F_45 ( V_151 ) )
V_26 = & V_151 [ V_40 ] ;
if ( ! V_26 )
return - V_152 ;
V_2 -> V_27 = V_26 ;
V_2 -> V_153 = V_26 -> V_154 ;
V_8 = F_46 ( V_2 , sizeof( * V_8 ) ) ;
if ( ! V_8 )
return - V_155 ;
V_53 = F_47 ( V_2 ) ;
if ( V_53 )
return V_53 ;
V_2 -> V_33 = F_48 ( V_148 , 2 ) ;
V_150 = 0 ;
if ( V_26 -> V_156 )
V_150 ++ ;
if ( V_26 -> V_140 )
V_150 ++ ;
if ( V_26 -> V_157 )
V_150 += 2 ;
if ( V_26 -> V_158 )
V_150 ++ ;
V_53 = F_49 ( V_2 , V_150 ) ;
if ( V_53 )
return V_53 ;
F_42 ( V_2 ) ;
if ( V_26 -> V_159 && V_148 -> V_106 ) {
V_53 = F_50 ( V_148 -> V_106 , F_31 ,
V_160 , V_2 -> V_153 , V_2 ) ;
if ( V_53 == 0 )
V_2 -> V_106 = V_148 -> V_106 ;
}
V_149 = 0 ;
if ( V_26 -> V_156 ) {
V_4 = & V_2 -> V_161 [ V_149 ] ;
V_4 -> type = V_162 ;
V_4 -> V_163 = V_164 | V_165 | V_166 ;
if ( V_26 -> V_167 )
V_4 -> V_163 |= V_168 ;
V_4 -> V_14 = V_26 -> V_156 ;
V_4 -> V_51 = 0x0fff ;
V_4 -> V_169 = V_26 -> V_170 ;
V_4 -> V_171 = F_11 ;
if ( V_2 -> V_106 ) {
V_2 -> V_110 = V_4 ;
V_4 -> V_163 |= V_172 ;
V_4 -> V_173 = V_4 -> V_14 ;
V_4 -> V_174 = F_34 ;
V_4 -> V_175 = F_33 ;
V_4 -> V_176 = F_26 ;
}
V_149 ++ ;
}
if ( V_26 -> V_140 ) {
V_4 = & V_2 -> V_161 [ V_149 ] ;
V_4 -> type = V_177 ;
V_4 -> V_163 = V_178 | V_166 | V_165 ;
V_4 -> V_51 = 0x0fff ;
if ( V_26 -> V_146 ) {
V_4 -> V_14 = 4 ;
V_4 -> V_169 = & V_179 ;
V_4 -> V_180 = F_25 ;
} else {
V_4 -> V_14 = 2 ;
V_4 -> V_169 = & V_181 ;
V_4 -> V_180 = F_14 ;
}
V_53 = F_51 ( V_4 ) ;
if ( V_53 )
return V_53 ;
if ( V_26 -> V_146 ) {
int V_17 ;
for ( V_17 = 0 ; V_17 < V_4 -> V_14 ; V_17 ++ )
V_4 -> V_66 [ V_17 ] = 0x0800 ;
}
V_149 ++ ;
}
if ( V_26 -> V_157 ) {
V_4 = & V_2 -> V_161 [ V_149 ] ;
V_4 -> type = V_182 ;
V_4 -> V_163 = V_164 ;
V_4 -> V_14 = 16 ;
V_4 -> V_51 = 1 ;
V_4 -> V_169 = & V_183 ;
V_4 -> V_184 = F_15 ;
V_149 ++ ;
V_4 = & V_2 -> V_161 [ V_149 ] ;
V_4 -> type = V_185 ;
V_4 -> V_163 = V_178 ;
V_4 -> V_14 = 16 ;
V_4 -> V_51 = 1 ;
V_4 -> V_169 = & V_183 ;
V_4 -> V_184 = F_16 ;
V_149 ++ ;
}
if ( V_26 -> V_158 ) {
V_4 = & V_2 -> V_161 [ V_149 ] ;
V_4 -> type = V_186 ;
V_4 -> V_163 = V_164 | V_178 ;
V_4 -> V_14 = 1 ;
V_4 -> V_51 = 0xffff ;
V_4 -> V_169 = & V_187 ;
V_4 -> V_171 = F_21 ;
V_4 -> V_180 = F_22 ;
V_4 -> V_188 = F_23 ;
V_149 ++ ;
}
V_8 -> V_105 = ( V_26 -> V_189 ) ? 2048 : 512 ;
return 0 ;
}
static void F_52 ( struct V_1 * V_2 )
{
if ( V_2 -> V_33 )
F_42 ( V_2 ) ;
F_53 ( V_2 ) ;
}
static int F_54 ( struct V_147 * V_2 ,
const struct V_190 * V_191 )
{
return F_55 ( V_2 , & V_192 ,
V_191 -> V_193 ) ;
}

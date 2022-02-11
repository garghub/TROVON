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
unsigned int V_23 = F_12 ( V_25 [ 0 ] ) ;
unsigned int V_24 ;
unsigned int V_19 ;
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < V_26 ; V_27 ++ ) {
V_24 = F_12 ( V_25 [ V_27 ] ) ;
V_19 = F_13 ( V_25 [ V_27 ] ) ;
F_7 ( V_2 , V_24 , V_19 ) ;
}
F_14 ( 1 ) ;
F_9 ( V_2 , V_23 , V_24 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_8 ( 0 , V_2 -> V_20 + V_28 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_8 ( 0 , V_2 -> V_20 + V_29 ) ;
}
static unsigned int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_30 ;
V_30 = F_18 ( V_2 -> V_20 + V_31 ) << 8 ;
V_30 |= F_18 ( V_2 -> V_20 + V_29 ) ;
return V_30 & V_4 -> V_32 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_33 * V_34 ,
unsigned long V_35 )
{
unsigned int V_36 ;
V_36 = F_18 ( V_2 -> V_20 + V_37 ) ;
if ( ( V_36 & V_38 ) == 0 )
return 0 ;
return - V_39 ;
}
static bool F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_40 * V_41 = & V_4 -> V_42 -> V_41 ;
if ( V_41 -> V_43 == V_44 &&
V_4 -> V_42 -> V_45 >= V_41 -> V_46 ) {
V_4 -> V_42 -> V_47 |= V_48 ;
return false ;
}
return true ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned short * V_49 ,
unsigned int V_50 , unsigned int V_51 )
{
unsigned short V_30 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_51 ; V_27 ++ ) {
V_30 = V_49 [ V_50 ++ ] ;
F_22 ( V_4 , & V_30 , 1 ) ;
if ( ! F_20 ( V_2 , V_4 ) )
return;
}
}
static T_1 F_23 ( int V_52 , void * V_53 )
{
struct V_1 * V_2 = V_53 ;
struct V_3 * V_4 = V_2 -> V_54 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_11 * V_12 = & V_10 -> V_12 [ V_10 -> V_13 ] ;
unsigned int V_16 ;
unsigned int V_50 ;
if ( ! V_2 -> V_55 || ! V_7 -> V_56 ) {
F_15 ( V_2 ) ;
return V_57 ;
}
if ( V_7 -> V_58 ) {
V_7 -> V_58 = 0 ;
F_15 ( V_2 ) ;
return V_57 ;
}
V_16 = F_2 ( V_4 , V_12 -> V_18 ) -
V_7 -> V_59 ;
V_50 = V_7 -> V_59 ;
V_7 -> V_59 = 0 ;
V_10 -> V_13 = 1 - V_10 -> V_13 ;
F_1 ( V_2 , V_4 , V_16 ) ;
F_21 ( V_2 , V_4 , V_12 -> V_60 , V_50 , V_16 ) ;
F_15 ( V_2 ) ;
F_24 ( V_2 , V_4 ) ;
return V_57 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int * V_25 ,
unsigned int V_61 )
{
unsigned int V_62 [ 16 ] ;
unsigned int V_27 , V_63 , V_26 , V_64 ;
if ( V_61 < 1 ) {
F_26 ( V_2 -> V_65 , L_1 ) ;
return 0 ;
}
if ( V_61 > 1 ) {
V_62 [ 0 ] = V_25 [ 0 ] ;
for ( V_27 = 1 , V_26 = 1 ; V_27 < V_61 ; V_27 ++ , V_26 ++ ) {
if ( V_25 [ 0 ] == V_25 [ V_27 ] )
break;
V_63 =
( F_12 ( V_62 [ V_27 - 1 ] ) + 1 ) % V_61 ;
if ( V_63 != F_12 ( V_25 [ V_27 ] ) ) {
F_27 ( V_2 -> V_65 ,
L_2 ,
V_27 , F_12 ( V_25 [ V_27 ] ) , V_63 ,
F_12 ( V_25 [ 0 ] ) ) ;
return 0 ;
}
V_62 [ V_27 ] = V_25 [ V_27 ] ;
}
for ( V_27 = 0 , V_64 = 0 ; V_27 < V_61 ; V_27 ++ ) {
if ( V_25 [ V_27 ] != V_62 [ V_27 % V_26 ] ) {
F_27 ( V_2 -> V_65 ,
L_3 ,
V_27 , F_12 ( V_62 [ V_27 ] ) ,
F_13 ( V_62 [ V_27 ] ) ,
F_28 ( V_62 [ V_27 ] ) ,
F_12 ( V_25 [ V_27 % V_26 ] ) ,
F_13 ( V_25 [ V_27 % V_26 ] ) ,
F_28 ( V_62 [ V_27 % V_26 ] ) ) ;
return 0 ;
}
}
} else {
V_26 = 1 ;
}
return V_26 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_40 * V_41 )
{
int V_66 = 0 ;
V_66 |= F_30 ( & V_41 -> V_67 , V_68 ) ;
V_66 |= F_30 ( & V_41 -> V_69 , V_70 ) ;
V_66 |= F_30 ( & V_41 -> V_71 ,
V_72 | V_73 ) ;
V_66 |= F_30 ( & V_41 -> V_74 , V_44 ) ;
V_66 |= F_30 ( & V_41 -> V_43 , V_44 | V_75 ) ;
if ( V_66 )
return 1 ;
V_66 |= F_31 ( V_41 -> V_71 ) ;
V_66 |= F_31 ( V_41 -> V_43 ) ;
if ( V_66 )
return 2 ;
V_66 |= F_32 ( & V_41 -> V_76 , 0 ) ;
V_66 |= F_32 ( & V_41 -> V_77 , 0 ) ;
if ( V_41 -> V_71 == V_73 )
V_66 |= F_33 ( & V_41 -> V_78 , 10000 ) ;
else
V_66 |= F_32 ( & V_41 -> V_78 , 0 ) ;
V_66 |= F_32 ( & V_41 -> V_79 ,
V_41 -> V_80 ) ;
if ( V_41 -> V_43 == V_44 )
V_66 |= F_33 ( & V_41 -> V_46 , 1 ) ;
else
V_66 |= F_32 ( & V_41 -> V_46 , 0 ) ;
if ( V_66 )
return 3 ;
if ( V_41 -> V_71 == V_73 ) {
unsigned int V_81 = V_41 -> V_78 ;
F_34 ( V_2 -> V_82 , & V_81 , V_41 -> V_83 ) ;
V_66 |= F_32 ( & V_41 -> V_78 , V_81 ) ;
}
if ( V_66 )
return 4 ;
if ( V_41 -> V_25 ) {
if ( ! F_25 ( V_2 , V_4 , V_41 -> V_25 ,
V_41 -> V_80 ) )
return 5 ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_40 * V_41 = & V_4 -> V_42 -> V_41 ;
unsigned int V_84 ;
unsigned int V_26 ;
if ( V_7 -> V_56 )
return - V_39 ;
V_26 = F_25 ( V_2 , V_4 , V_41 -> V_25 , V_41 -> V_80 ) ;
if ( V_26 < 1 )
return - V_85 ;
F_11 ( V_2 , V_41 -> V_25 , V_26 ) ;
F_14 ( 1 ) ;
V_7 -> V_56 = 1 ;
V_7 -> V_59 = 0 ;
V_7 -> V_58 = 0 ;
V_10 -> V_13 = 0 ;
F_1 ( V_2 , V_4 , 0 ) ;
F_36 ( V_2 -> V_82 , 0 , V_86 | V_87 ) ;
F_37 ( V_2 -> V_82 , 0 , 0x0ff ) ;
F_14 ( 1 ) ;
F_38 ( V_2 -> V_82 ) ;
F_39 ( V_2 -> V_82 , 1 , 2 , true ) ;
V_84 = V_88 | V_89 |
F_40 ( 0 ) ;
if ( V_41 -> V_71 == V_73 )
V_84 |= V_90 ;
else
V_84 |= V_91 ;
F_8 ( V_84 , V_2 -> V_20 + V_92 ) ;
F_8 ( ( V_10 -> V_17 << 4 ) | V_2 -> V_52 ,
V_2 -> V_20 + V_37 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_11 * V_12 ;
unsigned long V_83 ;
unsigned int V_93 ;
int V_94 ;
F_42 ( & V_2 -> V_95 , V_83 ) ;
V_93 = F_43 ( V_10 ) ;
V_93 = F_2 ( V_4 , V_93 ) ;
if ( V_93 > V_7 -> V_59 ) {
V_12 = & V_10 -> V_12 [ V_10 -> V_13 ] ;
F_21 ( V_2 , V_4 , V_12 -> V_60 ,
V_7 -> V_59 ,
V_93 - V_7 -> V_59 ) ;
V_7 -> V_59 = V_93 ;
F_24 ( V_2 , V_4 ) ;
V_94 = F_44 ( V_4 ) ;
} else {
V_94 = 0 ;
}
F_45 ( & V_2 -> V_95 , V_83 ) ;
return V_94 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
if ( ! V_7 -> V_56 )
return 0 ;
F_8 ( 0 , V_2 -> V_20 + V_92 ) ;
F_15 ( V_2 ) ;
F_39 ( V_2 -> V_82 , 1 , 2 , false ) ;
V_7 -> V_56 = 0 ;
V_7 -> V_58 = 1 ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_33 * V_34 ,
unsigned int * V_96 )
{
unsigned int V_17 = F_12 ( V_34 -> V_97 ) ;
unsigned int V_19 = F_13 ( V_34 -> V_97 ) ;
int V_94 = 0 ;
int V_27 ;
F_8 ( V_98 , V_2 -> V_20 + V_92 ) ;
F_7 ( V_2 , V_17 , V_19 ) ;
F_9 ( V_2 , V_17 , V_17 ) ;
for ( V_27 = 0 ; V_27 < V_34 -> V_99 ; V_27 ++ ) {
F_15 ( V_2 ) ;
F_16 ( V_2 ) ;
V_94 = F_48 ( V_2 , V_4 , V_34 , F_19 , 0 ) ;
if ( V_94 )
break;
V_96 [ V_27 ] = F_17 ( V_2 , V_4 ) ;
}
F_8 ( 0 , V_2 -> V_20 + V_92 ) ;
F_15 ( V_2 ) ;
return V_94 ? V_94 : V_34 -> V_99 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_33 * V_34 ,
unsigned int * V_96 )
{
V_96 [ 1 ] = F_18 ( V_2 -> V_20 + V_100 ) |
( F_18 ( V_2 -> V_20 + V_101 ) << 8 ) ;
return V_34 -> V_99 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_33 * V_34 ,
unsigned int * V_96 )
{
if ( F_51 ( V_4 , V_96 ) ) {
F_8 ( V_4 -> V_102 & 0xff , V_2 -> V_20 + V_100 ) ;
F_8 ( ( V_4 -> V_102 >> 8 ) , V_2 -> V_20 + V_101 ) ;
}
V_96 [ 1 ] = V_4 -> V_102 ;
return V_34 -> V_99 ;
}
static void F_52 ( struct V_1 * V_2 )
{
F_8 ( 0 , V_2 -> V_20 + V_92 ) ;
F_7 ( V_2 , 0 , 0 ) ;
F_15 ( V_2 ) ;
F_8 ( 0 , V_2 -> V_20 + V_100 ) ;
F_8 ( 0 , V_2 -> V_20 + V_101 ) ;
}
static void F_53 ( struct V_1 * V_2 ,
struct V_103 * V_104 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned int V_105 = V_104 -> V_106 [ 1 ] ;
unsigned int V_107 = V_104 -> V_106 [ 2 ] ;
if ( ! ( V_105 >= 2 && V_105 <= 7 ) ||
! ( V_107 == 3 || V_107 == 1 ) )
return;
if ( F_54 ( V_105 , F_23 , 0 , V_2 -> V_108 , V_2 ) )
return;
V_7 -> V_10 = F_55 ( V_2 , 2 , V_107 , V_107 ,
V_109 * 4 , V_110 ) ;
if ( ! V_7 -> V_10 )
F_56 ( V_105 , V_2 ) ;
else
V_2 -> V_52 = V_105 ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
if ( V_7 )
F_58 ( V_7 -> V_10 ) ;
}
static int F_59 ( struct V_1 * V_2 , struct V_103 * V_104 )
{
const struct V_111 * V_112 = V_2 -> V_113 ;
struct V_6 * V_7 ;
struct V_3 * V_4 ;
int V_94 ;
V_7 = F_60 ( V_2 , sizeof( * V_7 ) ) ;
if ( ! V_7 )
return - V_114 ;
V_94 = F_61 ( V_2 , V_104 -> V_106 [ 0 ] , 0x10 ) ;
if ( V_94 )
return V_94 ;
F_53 ( V_2 , V_104 ) ;
V_2 -> V_82 = F_62 ( V_2 -> V_20 + V_115 ,
V_116 , V_117 , 0 ) ;
if ( ! V_2 -> V_82 )
return - V_114 ;
V_94 = F_63 ( V_2 , 4 ) ;
if ( V_94 )
return V_94 ;
V_4 = & V_2 -> V_118 [ 0 ] ;
V_4 -> type = V_119 ;
V_4 -> V_120 = V_121 | V_122 ;
V_4 -> V_123 = 16 ;
V_4 -> V_32 = V_112 -> V_124 ;
V_4 -> V_125 = & V_126 ;
V_4 -> V_127 = F_47 ;
if ( V_2 -> V_52 ) {
V_2 -> V_54 = V_4 ;
V_4 -> V_120 |= V_121 ;
V_4 -> V_128 = V_112 -> V_129 ;
V_4 -> V_130 = F_29 ;
V_4 -> V_131 = F_35 ;
V_4 -> V_93 = F_41 ;
V_4 -> V_132 = F_46 ;
}
V_4 = & V_2 -> V_118 [ 1 ] ;
V_4 -> type = V_133 ;
V_4 = & V_2 -> V_118 [ 2 ] ;
V_4 -> type = V_134 ;
V_4 -> V_120 = V_135 ;
V_4 -> V_123 = 16 ;
V_4 -> V_32 = 1 ;
V_4 -> V_125 = & V_136 ;
V_4 -> V_137 = F_49 ;
V_4 = & V_2 -> V_118 [ 3 ] ;
V_4 -> type = V_138 ;
V_4 -> V_120 = V_139 ;
V_4 -> V_123 = 16 ;
V_4 -> V_32 = 1 ;
V_4 -> V_125 = & V_136 ;
V_4 -> V_137 = F_50 ;
F_52 ( V_2 ) ;
return 0 ;
}
static void F_64 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 ) {
F_46 ( V_2 , V_2 -> V_54 ) ;
F_52 ( V_2 ) ;
}
F_57 ( V_2 ) ;
F_65 ( V_2 ) ;
}

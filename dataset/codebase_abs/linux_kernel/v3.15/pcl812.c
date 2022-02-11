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
if ( V_5 -> V_21 ) {
V_5 -> V_22 [ 0 ] =
V_17 -> V_23 * sizeof( short ) ;
V_5 -> V_22 [ 1 ] =
V_17 -> V_23 * sizeof( short ) ;
V_5 -> V_24 = 1 ;
} else {
V_5 -> V_22 [ 0 ] = V_5 -> V_25 ;
V_5 -> V_22 [ 1 ] = V_5 -> V_25 ;
if ( V_15 -> V_18 -> V_26 < V_5 -> V_25 ) {
V_5 -> V_22 [ 0 ] =
V_15 -> V_18 -> V_26 ;
V_5 -> V_22 [ 1 ] =
V_15 -> V_18 -> V_26 ;
}
if ( V_17 -> V_27 == V_28 ) {
V_5 -> V_24 = 1 ;
} else {
V_20 = V_17 -> V_23 *
V_17 -> V_29 * sizeof( short ) ;
V_5 -> V_24 =
V_20 / V_5 -> V_22 [ 0 ] ;
V_5 -> V_30 =
V_20 % V_5 -> V_22 [ 0 ] ;
if ( V_5 -> V_24 == 0 )
V_5 -> V_22 [ 0 ] =
V_5 -> V_30 ;
V_5 -> V_24 -- ;
}
}
if ( V_5 -> V_22 [ 0 ] > V_5 -> V_25 ) {
V_5 -> V_22 [ 0 ] = V_5 -> V_25 ;
V_5 -> V_21 = 0 ;
}
if ( V_5 -> V_22 [ 1 ] > V_5 -> V_25 ) {
V_5 -> V_22 [ 1 ] = V_5 -> V_25 ;
V_5 -> V_21 = 0 ;
}
V_5 -> V_31 = 0 ;
F_6 ( V_5 -> V_32 , V_33 ) ;
V_19 = F_7 () ;
F_8 ( V_5 -> V_32 ) ;
F_9 ( V_5 -> V_32 , V_5 -> V_34 [ 0 ] ) ;
F_10 ( V_5 -> V_32 , V_5 -> V_22 [ 0 ] ) ;
F_11 ( V_19 ) ;
F_12 ( V_5 -> V_32 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_19 ;
V_5 -> V_31 = 1 - V_5 -> V_31 ;
F_14 ( V_5 -> V_32 ) ;
F_6 ( V_5 -> V_32 , V_33 ) ;
V_19 = F_7 () ;
F_9 ( V_5 -> V_32 , V_5 -> V_34 [ V_5 -> V_31 ] ) ;
if ( V_5 -> V_21 ) {
F_10 ( V_5 -> V_32 ,
V_5 -> V_22 [ V_5 -> V_31 ] ) ;
} else {
if ( V_5 -> V_24 ) {
F_10 ( V_5 -> V_32 ,
V_5 -> V_22 [ V_5 ->
V_31 ] ) ;
} else {
F_10 ( V_5 -> V_32 , V_5 -> V_30 ) ;
}
V_5 -> V_24 -- ;
}
F_11 ( V_19 ) ;
F_12 ( V_5 -> V_32 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
unsigned int V_35 , char V_36 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_37 = F_16 ( V_35 ) ;
unsigned int V_38 = F_17 ( V_35 ) ;
unsigned int V_39 = 0 ;
if ( V_35 == V_5 -> V_40 )
return;
V_5 -> V_40 = V_35 ;
if ( V_5 -> V_41 ) {
if ( V_5 -> V_42 ) {
V_39 |= V_43 | V_44 ;
} else {
if ( V_37 < 8 )
V_39 |= V_43 ;
else
V_39 |= V_44 ;
}
}
F_18 ( V_39 | F_19 ( V_37 ) , V_2 -> V_8 + V_45 ) ;
F_18 ( V_38 + V_5 -> V_46 , V_2 -> V_8 + V_47 ) ;
if ( V_36 )
F_3 ( V_5 -> V_48 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_18 ( 0 , V_2 -> V_8 + V_49 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_18 ( 255 , V_2 -> V_8 + V_50 ) ;
}
static unsigned int F_22 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
unsigned int V_51 ;
V_51 = F_23 ( V_2 -> V_8 + V_52 ) << 8 ;
V_51 |= F_23 ( V_2 -> V_8 + V_53 ) ;
return V_51 & V_15 -> V_54 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_55 * V_56 ,
unsigned long V_57 )
{
unsigned int V_58 ;
if ( V_15 -> V_54 > 0x0fff ) {
V_58 = F_23 ( V_2 -> V_8 + V_49 ) ;
if ( ( V_58 & V_59 ) == 0 )
return 0 ;
} else {
V_58 = F_23 ( V_2 -> V_8 + V_52 ) ;
if ( ( V_58 & V_60 ) == 0 )
return 0 ;
}
return - V_61 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_14 * V_15 , struct V_16 * V_17 )
{
const struct V_62 * V_63 = F_26 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_64 = 0 ;
unsigned int V_65 ;
int V_66 ;
V_64 |= F_27 ( & V_17 -> V_67 , V_68 ) ;
V_64 |= F_27 ( & V_17 -> V_69 , V_70 ) ;
if ( V_5 -> V_71 )
V_65 = V_72 ;
else
V_65 = V_73 ;
V_64 |= F_27 ( & V_17 -> V_74 , V_65 ) ;
V_64 |= F_27 ( & V_17 -> V_75 , V_76 ) ;
V_64 |= F_27 ( & V_17 -> V_27 , V_76 | V_28 ) ;
if ( V_64 )
return 1 ;
V_64 |= F_28 ( V_17 -> V_27 ) ;
if ( V_64 )
return 2 ;
V_64 |= F_29 ( & V_17 -> V_77 , 0 ) ;
V_64 |= F_29 ( & V_17 -> V_78 , 0 ) ;
if ( V_17 -> V_74 == V_73 )
V_64 |= F_30 ( & V_17 -> V_79 ,
V_63 -> V_80 ) ;
else
V_64 |= F_29 ( & V_17 -> V_79 , 0 ) ;
V_64 |= F_30 ( & V_17 -> V_23 , 1 ) ;
V_64 |= F_31 ( & V_17 -> V_23 , V_81 ) ;
V_64 |= F_29 ( & V_17 -> V_82 , V_17 -> V_23 ) ;
if ( V_17 -> V_27 == V_76 )
V_64 |= F_30 ( & V_17 -> V_29 , 1 ) ;
else
V_64 |= F_29 ( & V_17 -> V_29 , 0 ) ;
if ( V_64 )
return 3 ;
if ( V_17 -> V_74 == V_73 ) {
V_66 = V_17 -> V_79 ;
F_32 ( V_83 ,
& V_5 -> V_13 ,
& V_5 -> V_12 ,
& V_17 -> V_79 , V_17 -> V_65 ) ;
if ( V_17 -> V_79 < V_63 -> V_80 )
V_17 -> V_79 = V_63 -> V_80 ;
if ( V_66 != V_17 -> V_79 )
V_64 ++ ;
}
if ( V_64 )
return 4 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_16 * V_17 = & V_15 -> V_18 -> V_17 ;
unsigned int V_84 = 0 ;
unsigned int V_85 ;
F_1 ( V_2 , false ) ;
F_15 ( V_2 , V_17 -> V_86 [ 0 ] , 1 ) ;
if ( V_5 -> V_32 ) {
V_5 -> V_87 = 1 ;
for ( V_85 = 1 ; V_85 < V_17 -> V_23 ; V_85 ++ )
if ( V_17 -> V_86 [ 0 ] != V_17 -> V_86 [ V_85 ] ) {
V_5 -> V_87 = 0 ;
break;
}
} else
V_5 -> V_87 = 0 ;
V_5 -> V_88 = 0 ;
V_5 -> V_89 = 0 ;
V_15 -> V_18 -> V_90 = 0 ;
if ( V_17 -> V_65 & V_91 ) {
V_5 -> V_21 = 1 ;
if ( V_17 -> V_23 == 1 )
V_5 -> V_87 = 0 ;
}
if ( V_5 -> V_87 )
F_5 ( V_2 , V_15 ) ;
switch ( V_17 -> V_74 ) {
case V_73 :
F_1 ( V_2 , true ) ;
break;
}
if ( V_5 -> V_87 )
V_84 |= V_92 ;
else
V_84 |= V_93 ;
F_18 ( V_5 -> V_94 | V_84 , V_2 -> V_8 + V_95 ) ;
return 0 ;
}
static bool F_34 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_16 * V_17 = & V_15 -> V_18 -> V_17 ;
V_15 -> V_18 -> V_96 |= V_97 ;
V_15 -> V_18 -> V_90 ++ ;
if ( V_15 -> V_18 -> V_90 >= V_17 -> V_23 ) {
V_15 -> V_18 -> V_90 = 0 ;
V_5 -> V_88 ++ ;
V_15 -> V_18 -> V_96 |= V_98 ;
}
if ( V_17 -> V_27 == V_76 &&
V_5 -> V_88 >= V_17 -> V_29 ) {
V_15 -> V_18 -> V_96 |= V_99 ;
return false ;
}
return true ;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 = & V_15 -> V_18 -> V_17 ;
unsigned int V_100 ;
if ( F_24 ( V_2 , V_15 , NULL , 0 ) ) {
F_36 ( V_2 -> V_101 , L_1 ) ;
V_15 -> V_18 -> V_96 |= V_99 | V_102 ;
return;
}
F_37 ( V_15 -> V_18 , F_22 ( V_2 , V_15 ) ) ;
V_100 = V_15 -> V_18 -> V_90 + 1 ;
if ( V_100 >= V_17 -> V_23 )
V_100 = 0 ;
if ( V_17 -> V_86 [ V_15 -> V_18 -> V_90 ] != V_17 -> V_86 [ V_100 ] )
F_15 ( V_2 , V_17 -> V_86 [ V_100 ] , 0 ) ;
F_34 ( V_2 , V_15 ) ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
unsigned short * V_103 ,
unsigned int V_104 , unsigned int V_105 )
{
unsigned int V_85 ;
for ( V_85 = V_105 ; V_85 ; V_85 -- ) {
F_37 ( V_15 -> V_18 , V_103 [ V_104 ++ ] ) ;
if ( ! F_34 ( V_2 , V_15 ) )
break;
}
}
static void F_39 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_105 , V_104 ;
unsigned short * V_103 ;
V_103 = ( unsigned short * ) V_5 -> V_106 [ V_5 -> V_31 ] ;
V_105 = ( V_5 -> V_22 [ V_5 -> V_31 ] >> 1 ) -
V_5 -> V_89 ;
F_13 ( V_2 , V_15 ) ;
V_104 = V_5 -> V_89 ;
V_5 -> V_89 = 0 ;
F_38 ( V_2 , V_15 , V_103 , V_104 , V_105 ) ;
}
static T_1 F_40 ( int V_107 , void * V_108 )
{
struct V_1 * V_2 = V_108 ;
struct V_14 * V_15 = V_2 -> V_109 ;
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_2 -> V_110 ) {
F_20 ( V_2 ) ;
return V_111 ;
}
if ( V_5 -> V_87 )
F_39 ( V_2 , V_15 ) ;
else
F_35 ( V_2 , V_15 ) ;
F_20 ( V_2 ) ;
F_41 ( V_2 , V_15 ) ;
return V_111 ;
}
static int F_42 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_65 ;
unsigned int V_112 , V_113 , V_85 ;
if ( ! V_5 -> V_87 )
return 0 ;
F_43 ( & V_2 -> V_114 , V_65 ) ;
for ( V_85 = 0 ; V_85 < 10 ; V_85 ++ ) {
V_112 = F_44 ( V_5 -> V_87 ) ;
V_113 = F_44 ( V_5 -> V_87 ) ;
if ( V_112 == V_113 )
break;
}
if ( V_112 != V_113 ) {
F_45 ( & V_2 -> V_114 , V_65 ) ;
return 0 ;
}
V_112 = V_5 -> V_22 [ 1 - V_5 -> V_31 ] - V_112 ;
V_112 >>= 1 ;
V_113 = V_112 - V_5 -> V_89 ;
if ( V_113 < 1 ) {
F_45 ( & V_2 -> V_114 , V_65 ) ;
return 0 ;
}
F_38 ( V_2 , V_15 ,
( void * ) V_5 -> V_106 [ 1 -
V_5 -> V_31 ] ,
V_5 -> V_89 , V_113 ) ;
V_5 -> V_89 = V_112 ;
F_45 ( & V_2 -> V_114 , V_65 ) ;
return V_15 -> V_18 -> V_115 - V_15 -> V_18 -> V_116 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 -> V_87 )
F_14 ( V_5 -> V_32 ) ;
F_18 ( V_5 -> V_94 | V_117 ,
V_2 -> V_8 + V_95 ) ;
F_1 ( V_2 , false ) ;
F_20 ( V_2 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_55 * V_56 ,
unsigned int * V_118 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_119 = 0 ;
int V_85 ;
F_18 ( V_5 -> V_94 | V_120 ,
V_2 -> V_8 + V_95 ) ;
F_15 ( V_2 , V_56 -> V_35 , 1 ) ;
for ( V_85 = 0 ; V_85 < V_56 -> V_121 ; V_85 ++ ) {
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
V_119 = F_48 ( V_2 , V_15 , V_56 , F_24 , 0 ) ;
if ( V_119 )
break;
V_118 [ V_85 ] = F_22 ( V_2 , V_15 ) ;
}
F_18 ( V_5 -> V_94 | V_117 ,
V_2 -> V_8 + V_95 ) ;
F_20 ( V_2 ) ;
return V_119 ? V_119 : V_56 -> V_121 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_55 * V_56 ,
unsigned int * V_118 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_37 = F_16 ( V_56 -> V_35 ) ;
int V_85 ;
for ( V_85 = 0 ; V_85 < V_56 -> V_121 ; V_85 ++ ) {
F_18 ( ( V_118 [ V_85 ] & 0xff ) ,
V_2 -> V_8 + F_50 ( V_37 ) ) ;
F_18 ( ( V_118 [ V_85 ] >> 8 ) & 0x0f ,
V_2 -> V_8 + F_51 ( V_37 ) ) ;
V_5 -> V_122 [ V_37 ] = V_118 [ V_85 ] ;
}
return V_56 -> V_121 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_55 * V_56 ,
unsigned int * V_118 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_37 = F_16 ( V_56 -> V_35 ) ;
int V_85 ;
for ( V_85 = 0 ; V_85 < V_56 -> V_121 ; V_85 ++ )
V_118 [ V_85 ] = V_5 -> V_122 [ V_37 ] ;
return V_56 -> V_121 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_55 * V_56 ,
unsigned int * V_118 )
{
V_118 [ 1 ] = F_23 ( V_2 -> V_8 + V_123 ) |
( F_23 ( V_2 -> V_8 + V_124 ) << 8 ) ;
return V_56 -> V_121 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_55 * V_56 ,
unsigned int * V_118 )
{
if ( F_55 ( V_15 , V_118 ) ) {
F_18 ( V_15 -> V_125 & 0xff , V_2 -> V_8 + V_126 ) ;
F_18 ( ( V_15 -> V_125 >> 8 ) , V_2 -> V_8 + V_127 ) ;
}
V_118 [ 1 ] = V_15 -> V_125 ;
return V_56 -> V_121 ;
}
static void F_56 ( struct V_1 * V_2 )
{
const struct V_62 * V_63 = F_26 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_37 ;
F_18 ( V_5 -> V_94 | V_117 ,
V_2 -> V_8 + V_95 ) ;
F_20 ( V_2 ) ;
if ( V_63 -> V_128 )
F_1 ( V_2 , false ) ;
V_5 -> V_40 = F_57 ( 16 , 0 , 0 ) ;
F_15 ( V_2 , F_57 ( 0 , 0 , 0 ) , 0 ) ;
for ( V_37 = 0 ; V_37 < V_63 -> V_129 ; V_37 ++ ) {
F_18 ( 0 , V_2 -> V_8 + F_50 ( V_37 ) ) ;
F_18 ( 0 , V_2 -> V_8 + F_51 ( V_37 ) ) ;
}
if ( V_63 -> V_130 ) {
F_18 ( 0 , V_2 -> V_8 + V_127 ) ;
F_18 ( 0 , V_2 -> V_8 + V_126 ) ;
}
}
static void F_58 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_131 * V_132 )
{
const struct V_62 * V_63 = F_26 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
V_15 -> V_133 = V_63 -> V_134 ;
switch ( V_63 -> V_135 ) {
case V_136 :
if ( V_132 -> V_137 [ 4 ] == 1 )
V_15 -> V_133 = & V_138 ;
break;
case V_139 :
switch ( V_132 -> V_137 [ 4 ] ) {
case 0 :
V_15 -> V_133 = & V_140 ;
break;
case 1 :
V_15 -> V_133 = & V_141 ;
break;
case 2 :
V_15 -> V_133 = & V_142 ;
break;
case 3 :
V_15 -> V_133 = & V_143 ;
break;
case 4 :
V_15 -> V_133 = & V_144 ;
break;
case 5 :
V_15 -> V_133 = & V_145 ;
break;
default:
V_15 -> V_133 = & V_140 ;
break;
}
break;
case V_146 :
if ( V_132 -> V_137 [ 1 ] == 1 )
V_15 -> V_133 = & V_147 ;
break;
case V_148 :
switch ( V_132 -> V_137 [ 1 ] ) {
case 0 :
V_15 -> V_133 = & V_149 ;
break;
case 1 :
V_15 -> V_133 = & V_150 ;
break;
case 2 :
V_15 -> V_133 = & V_151 ;
V_5 -> V_46 = 1 ;
break;
case 3 :
V_15 -> V_133 = & V_152 ;
V_5 -> V_46 = 1 ;
break;
default:
V_15 -> V_133 = & V_149 ;
break;
}
break;
case V_153 :
switch ( V_132 -> V_137 [ 1 ] ) {
case 0 :
V_15 -> V_133 = & V_154 ;
break;
case 1 :
V_15 -> V_133 = & V_155 ;
break;
case 2 :
V_15 -> V_133 = & V_156 ;
V_5 -> V_46 = 1 ;
break;
case 3 :
V_15 -> V_133 = & V_157 ;
V_5 -> V_46 = 1 ;
break;
default:
V_15 -> V_133 = & V_154 ;
break;
}
break;
}
}
static int F_59 ( struct V_1 * V_2 , struct V_131 * V_132 )
{
const struct V_62 * V_63 = F_26 ( V_2 ) ;
struct V_4 * V_5 ;
struct V_14 * V_15 ;
int V_158 ;
int V_159 ;
int V_119 ;
int V_85 ;
V_5 = F_60 ( V_2 , sizeof( * V_5 ) ) ;
if ( ! V_5 )
return - V_160 ;
V_119 = F_61 ( V_2 , V_132 -> V_137 [ 0 ] , 0x10 ) ;
if ( V_119 )
return V_119 ;
if ( ( 1 << V_132 -> V_137 [ 1 ] ) & V_63 -> V_128 ) {
V_119 = F_62 ( V_132 -> V_137 [ 1 ] , F_40 , 0 ,
V_2 -> V_161 , V_2 ) ;
if ( V_119 == 0 )
V_2 -> V_107 = V_132 -> V_137 [ 1 ] ;
}
if ( V_2 -> V_107 && V_63 -> V_162 &&
( V_132 -> V_137 [ 2 ] == 3 || V_132 -> V_137 [ 2 ] == 1 ) ) {
V_119 = F_63 ( V_132 -> V_137 [ 2 ] , V_2 -> V_161 ) ;
if ( V_119 ) {
F_64 ( V_2 -> V_101 ,
L_2 ,
V_132 -> V_137 [ 2 ] ) ;
return - V_61 ;
}
V_5 -> V_32 = V_132 -> V_137 [ 2 ] ;
V_5 -> V_163 = 1 ;
V_5 -> V_25 = ( 1 << V_5 -> V_163 ) * V_164 ;
for ( V_85 = 0 ; V_85 < 2 ; V_85 ++ ) {
unsigned long V_106 ;
V_106 = F_65 ( V_165 , V_5 -> V_163 ) ;
if ( ! V_106 )
return - V_160 ;
V_5 -> V_106 [ V_85 ] = V_106 ;
V_5 -> V_34 [ V_85 ] = F_66 ( ( void * ) V_106 ) ;
}
}
switch ( V_63 -> V_135 ) {
case V_166 :
if ( V_132 -> V_137 [ 2 ] == 1 )
V_5 -> V_42 = 1 ;
break;
case V_167 :
case V_168 :
if ( V_132 -> V_137 [ 4 ] == 1 )
V_5 -> V_42 = 1 ;
break;
}
V_158 = 1 ;
if ( V_63 -> V_129 > 0 )
V_158 ++ ;
if ( V_63 -> V_130 )
V_158 += 2 ;
V_119 = F_67 ( V_2 , V_158 ) ;
if ( V_119 )
return V_119 ;
V_159 = 0 ;
V_15 = & V_2 -> V_169 [ V_159 ] ;
V_15 -> type = V_170 ;
V_15 -> V_171 = V_172 ;
if ( V_5 -> V_42 ) {
V_15 -> V_171 |= V_173 ;
V_15 -> V_174 = V_63 -> V_175 / 2 ;
} else {
V_15 -> V_171 |= V_176 ;
V_15 -> V_174 = V_63 -> V_175 ;
}
V_15 -> V_54 = V_63 -> V_177 ? 0xffff : 0x0fff ;
F_58 ( V_2 , V_15 , V_132 ) ;
V_15 -> V_178 = F_47 ;
if ( V_2 -> V_107 ) {
V_2 -> V_109 = V_15 ;
V_15 -> V_171 |= V_179 ;
V_15 -> V_180 = V_81 ;
V_15 -> V_181 = F_25 ;
V_15 -> V_182 = F_33 ;
V_15 -> V_183 = F_42 ;
V_15 -> V_184 = F_46 ;
}
V_5 -> V_41 = V_63 -> V_185 ;
V_159 ++ ;
if ( V_63 -> V_129 > 0 ) {
V_15 = & V_2 -> V_169 [ V_159 ] ;
V_15 -> type = V_186 ;
V_15 -> V_171 = V_187 | V_176 ;
V_15 -> V_174 = V_63 -> V_129 ;
V_15 -> V_54 = 0xfff ;
V_15 -> V_133 = & V_188 ;
V_15 -> V_178 = F_52 ;
V_15 -> V_189 = F_49 ;
switch ( V_63 -> V_135 ) {
case V_166 :
if ( V_132 -> V_137 [ 3 ] == 1 )
V_15 -> V_133 = & V_190 ;
break;
case V_139 :
case V_167 :
case V_136 :
case V_168 :
if ( V_132 -> V_137 [ 5 ] == 1 )
V_15 -> V_133 = & V_190 ;
if ( V_132 -> V_137 [ 5 ] == 2 )
V_15 -> V_133 = & V_191 ;
break;
}
V_159 ++ ;
}
if ( V_63 -> V_130 ) {
V_15 = & V_2 -> V_169 [ V_159 ] ;
V_15 -> type = V_192 ;
V_15 -> V_171 = V_172 ;
V_15 -> V_174 = 16 ;
V_15 -> V_54 = 1 ;
V_15 -> V_133 = & V_193 ;
V_15 -> V_194 = F_53 ;
V_159 ++ ;
V_15 = & V_2 -> V_169 [ V_159 ] ;
V_15 -> type = V_195 ;
V_15 -> V_171 = V_187 ;
V_15 -> V_174 = 16 ;
V_15 -> V_54 = 1 ;
V_15 -> V_133 = & V_193 ;
V_15 -> V_194 = F_54 ;
V_159 ++ ;
}
switch ( V_63 -> V_135 ) {
case V_168 :
case V_136 :
case V_139 :
case V_167 :
V_5 -> V_48 = 1 ;
if ( V_132 -> V_137 [ 3 ] > 0 )
V_5 -> V_71 = 1 ;
break;
case V_166 :
V_5 -> V_48 = 1 ;
V_5 -> V_94 = ( V_2 -> V_107 << 4 ) & 0xf0 ;
break;
case V_146 :
case V_196 :
case V_148 :
case V_153 :
V_5 -> V_48 = 5 ;
break;
}
F_56 ( V_2 ) ;
return 0 ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 ) {
if ( V_5 -> V_106 [ 0 ] )
F_69 ( V_5 -> V_106 [ 0 ] , V_5 -> V_163 ) ;
if ( V_5 -> V_106 [ 1 ] )
F_69 ( V_5 -> V_106 [ 1 ] , V_5 -> V_163 ) ;
if ( V_5 -> V_32 )
F_70 ( V_5 -> V_32 ) ;
}
F_71 ( V_2 ) ;
}

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
V_5 -> V_22 [ 0 ] = F_6 ( V_15 ) ;
V_5 -> V_22 [ 1 ] = F_6 ( V_15 ) ;
V_5 -> V_23 = 1 ;
} else {
V_5 -> V_22 [ 0 ] = V_5 -> V_24 ;
V_5 -> V_22 [ 1 ] = V_5 -> V_24 ;
if ( V_15 -> V_18 -> V_25 < V_5 -> V_24 ) {
V_5 -> V_22 [ 0 ] =
V_15 -> V_18 -> V_25 ;
V_5 -> V_22 [ 1 ] =
V_15 -> V_18 -> V_25 ;
}
if ( V_17 -> V_26 == V_27 ) {
V_5 -> V_23 = 1 ;
} else {
V_20 = V_17 -> V_28 * F_6 ( V_15 ) ;
V_5 -> V_23 =
V_20 / V_5 -> V_22 [ 0 ] ;
V_5 -> V_29 =
V_20 % V_5 -> V_22 [ 0 ] ;
if ( V_5 -> V_23 == 0 )
V_5 -> V_22 [ 0 ] =
V_5 -> V_29 ;
V_5 -> V_23 -- ;
}
}
if ( V_5 -> V_22 [ 0 ] > V_5 -> V_24 ) {
V_5 -> V_22 [ 0 ] = V_5 -> V_24 ;
V_5 -> V_21 = 0 ;
}
if ( V_5 -> V_22 [ 1 ] > V_5 -> V_24 ) {
V_5 -> V_22 [ 1 ] = V_5 -> V_24 ;
V_5 -> V_21 = 0 ;
}
V_5 -> V_30 = 0 ;
F_7 ( V_5 -> V_31 , V_32 ) ;
V_19 = F_8 () ;
F_9 ( V_5 -> V_31 ) ;
F_10 ( V_5 -> V_31 , V_5 -> V_33 [ 0 ] ) ;
F_11 ( V_5 -> V_31 , V_5 -> V_22 [ 0 ] ) ;
F_12 ( V_19 ) ;
F_13 ( V_5 -> V_31 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_19 ;
V_5 -> V_30 = 1 - V_5 -> V_30 ;
F_15 ( V_5 -> V_31 ) ;
F_7 ( V_5 -> V_31 , V_32 ) ;
V_19 = F_8 () ;
F_10 ( V_5 -> V_31 , V_5 -> V_33 [ V_5 -> V_30 ] ) ;
if ( V_5 -> V_21 ) {
F_11 ( V_5 -> V_31 ,
V_5 -> V_22 [ V_5 -> V_30 ] ) ;
} else {
if ( V_5 -> V_23 ) {
F_11 ( V_5 -> V_31 ,
V_5 -> V_22 [ V_5 ->
V_30 ] ) ;
} else {
F_11 ( V_5 -> V_31 , V_5 -> V_29 ) ;
}
V_5 -> V_23 -- ;
}
F_12 ( V_19 ) ;
F_13 ( V_5 -> V_31 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
unsigned int V_34 , char V_35 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_36 = F_17 ( V_34 ) ;
unsigned int V_37 = F_18 ( V_34 ) ;
unsigned int V_38 = 0 ;
if ( V_34 == V_5 -> V_39 )
return;
V_5 -> V_39 = V_34 ;
if ( V_5 -> V_40 ) {
if ( V_5 -> V_41 ) {
V_38 |= V_42 | V_43 ;
} else {
if ( V_36 < 8 )
V_38 |= V_42 ;
else
V_38 |= V_43 ;
}
}
F_19 ( V_38 | F_20 ( V_36 ) , V_2 -> V_8 + V_44 ) ;
F_19 ( V_37 + V_5 -> V_45 , V_2 -> V_8 + V_46 ) ;
if ( V_35 )
F_3 ( V_5 -> V_47 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_19 ( 0 , V_2 -> V_8 + V_48 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_19 ( 255 , V_2 -> V_8 + V_49 ) ;
}
static unsigned int F_23 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
unsigned int V_50 ;
V_50 = F_24 ( V_2 -> V_8 + V_51 ) << 8 ;
V_50 |= F_24 ( V_2 -> V_8 + V_52 ) ;
return V_50 & V_15 -> V_53 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_54 * V_55 ,
unsigned long V_56 )
{
unsigned int V_57 ;
if ( V_15 -> V_53 > 0x0fff ) {
V_57 = F_24 ( V_2 -> V_8 + V_48 ) ;
if ( ( V_57 & V_58 ) == 0 )
return 0 ;
} else {
V_57 = F_24 ( V_2 -> V_8 + V_51 ) ;
if ( ( V_57 & V_59 ) == 0 )
return 0 ;
}
return - V_60 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_14 * V_15 , struct V_16 * V_17 )
{
const struct V_61 * V_62 = F_27 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_63 = 0 ;
unsigned int V_64 ;
unsigned int V_65 ;
V_63 |= F_28 ( & V_17 -> V_66 , V_67 ) ;
V_63 |= F_28 ( & V_17 -> V_68 , V_69 ) ;
if ( V_5 -> V_70 )
V_64 = V_71 ;
else
V_64 = V_72 ;
V_63 |= F_28 ( & V_17 -> V_73 , V_64 ) ;
V_63 |= F_28 ( & V_17 -> V_74 , V_75 ) ;
V_63 |= F_28 ( & V_17 -> V_26 , V_75 | V_27 ) ;
if ( V_63 )
return 1 ;
V_63 |= F_29 ( V_17 -> V_26 ) ;
if ( V_63 )
return 2 ;
V_63 |= F_30 ( & V_17 -> V_76 , 0 ) ;
V_63 |= F_30 ( & V_17 -> V_77 , 0 ) ;
if ( V_17 -> V_73 == V_72 )
V_63 |= F_31 ( & V_17 -> V_78 ,
V_62 -> V_79 ) ;
else
V_63 |= F_30 ( & V_17 -> V_78 , 0 ) ;
V_63 |= F_31 ( & V_17 -> V_80 , 1 ) ;
V_63 |= F_30 ( & V_17 -> V_81 , V_17 -> V_80 ) ;
if ( V_17 -> V_26 == V_75 )
V_63 |= F_31 ( & V_17 -> V_28 , 1 ) ;
else
V_63 |= F_30 ( & V_17 -> V_28 , 0 ) ;
if ( V_63 )
return 3 ;
if ( V_17 -> V_73 == V_72 ) {
V_65 = V_17 -> V_78 ;
F_32 ( V_82 ,
& V_5 -> V_13 ,
& V_5 -> V_12 ,
& V_65 , V_17 -> V_64 ) ;
V_63 |= F_30 ( & V_17 -> V_78 , V_65 ) ;
}
if ( V_63 )
return 4 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_16 * V_17 = & V_15 -> V_18 -> V_17 ;
unsigned int V_83 = 0 ;
unsigned int V_84 ;
F_1 ( V_2 , false ) ;
F_16 ( V_2 , V_17 -> V_85 [ 0 ] , 1 ) ;
if ( V_5 -> V_31 ) {
V_5 -> V_86 = 1 ;
for ( V_84 = 1 ; V_84 < V_17 -> V_80 ; V_84 ++ )
if ( V_17 -> V_85 [ 0 ] != V_17 -> V_85 [ V_84 ] ) {
V_5 -> V_86 = 0 ;
break;
}
} else {
V_5 -> V_86 = 0 ;
}
V_5 -> V_87 = 0 ;
V_5 -> V_88 = 0 ;
V_15 -> V_18 -> V_89 = 0 ;
if ( V_17 -> V_64 & V_90 ) {
V_5 -> V_21 = 1 ;
if ( V_17 -> V_80 == 1 )
V_5 -> V_86 = 0 ;
}
if ( V_5 -> V_86 )
F_5 ( V_2 , V_15 ) ;
switch ( V_17 -> V_73 ) {
case V_72 :
F_1 ( V_2 , true ) ;
break;
}
if ( V_5 -> V_86 )
V_83 |= V_91 ;
else
V_83 |= V_92 ;
F_19 ( V_5 -> V_93 | V_83 , V_2 -> V_8 + V_94 ) ;
return 0 ;
}
static bool F_34 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_16 * V_17 = & V_15 -> V_18 -> V_17 ;
V_15 -> V_18 -> V_95 |= V_96 ;
V_15 -> V_18 -> V_89 ++ ;
if ( V_15 -> V_18 -> V_89 >= V_17 -> V_80 ) {
V_15 -> V_18 -> V_89 = 0 ;
V_5 -> V_87 ++ ;
V_15 -> V_18 -> V_95 |= V_97 ;
}
if ( V_17 -> V_26 == V_75 &&
V_5 -> V_87 >= V_17 -> V_28 ) {
V_15 -> V_18 -> V_95 |= V_98 ;
return false ;
}
return true ;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 = & V_15 -> V_18 -> V_17 ;
unsigned int V_99 ;
if ( F_25 ( V_2 , V_15 , NULL , 0 ) ) {
F_36 ( V_2 -> V_100 , L_1 ) ;
V_15 -> V_18 -> V_95 |= V_98 | V_101 ;
return;
}
F_37 ( V_15 , F_23 ( V_2 , V_15 ) ) ;
V_99 = V_15 -> V_18 -> V_89 + 1 ;
if ( V_99 >= V_17 -> V_80 )
V_99 = 0 ;
if ( V_17 -> V_85 [ V_15 -> V_18 -> V_89 ] != V_17 -> V_85 [ V_99 ] )
F_16 ( V_2 , V_17 -> V_85 [ V_99 ] , 0 ) ;
F_34 ( V_2 , V_15 ) ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
unsigned short * V_102 ,
unsigned int V_103 , unsigned int V_104 )
{
unsigned int V_84 ;
for ( V_84 = V_104 ; V_84 ; V_84 -- ) {
F_37 ( V_15 , V_102 [ V_103 ++ ] ) ;
if ( ! F_34 ( V_2 , V_15 ) )
break;
}
}
static void F_39 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_104 , V_103 ;
unsigned short * V_102 ;
V_102 = ( unsigned short * ) V_5 -> V_105 [ V_5 -> V_30 ] ;
V_104 = ( V_5 -> V_22 [ V_5 -> V_30 ] >> 1 ) -
V_5 -> V_88 ;
F_14 ( V_2 , V_15 ) ;
V_103 = V_5 -> V_88 ;
V_5 -> V_88 = 0 ;
F_38 ( V_2 , V_15 , V_102 , V_103 , V_104 ) ;
}
static T_1 F_40 ( int V_106 , void * V_107 )
{
struct V_1 * V_2 = V_107 ;
struct V_14 * V_15 = V_2 -> V_108 ;
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_2 -> V_109 ) {
F_21 ( V_2 ) ;
return V_110 ;
}
if ( V_5 -> V_86 )
F_39 ( V_2 , V_15 ) ;
else
F_35 ( V_2 , V_15 ) ;
F_21 ( V_2 ) ;
F_41 ( V_2 , V_15 ) ;
return V_110 ;
}
static int F_42 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_64 ;
unsigned int V_111 , V_112 , V_84 ;
if ( ! V_5 -> V_86 )
return 0 ;
F_43 ( & V_2 -> V_113 , V_64 ) ;
for ( V_84 = 0 ; V_84 < 10 ; V_84 ++ ) {
V_111 = F_44 ( V_5 -> V_86 ) ;
V_112 = F_44 ( V_5 -> V_86 ) ;
if ( V_111 == V_112 )
break;
}
if ( V_111 != V_112 ) {
F_45 ( & V_2 -> V_113 , V_64 ) ;
return 0 ;
}
V_111 = V_5 -> V_22 [ 1 - V_5 -> V_30 ] - V_111 ;
V_111 >>= 1 ;
V_112 = V_111 - V_5 -> V_88 ;
if ( V_112 < 1 ) {
F_45 ( & V_2 -> V_113 , V_64 ) ;
return 0 ;
}
F_38 ( V_2 , V_15 ,
( void * ) V_5 -> V_105 [ 1 -
V_5 -> V_30 ] ,
V_5 -> V_88 , V_112 ) ;
V_5 -> V_88 = V_111 ;
F_45 ( & V_2 -> V_113 , V_64 ) ;
return V_15 -> V_18 -> V_114 - V_15 -> V_18 -> V_115 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 -> V_86 )
F_15 ( V_5 -> V_31 ) ;
F_19 ( V_5 -> V_93 | V_116 ,
V_2 -> V_8 + V_94 ) ;
F_1 ( V_2 , false ) ;
F_21 ( V_2 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_54 * V_55 ,
unsigned int * V_117 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_118 = 0 ;
int V_84 ;
F_19 ( V_5 -> V_93 | V_119 ,
V_2 -> V_8 + V_94 ) ;
F_16 ( V_2 , V_55 -> V_34 , 1 ) ;
for ( V_84 = 0 ; V_84 < V_55 -> V_120 ; V_84 ++ ) {
F_21 ( V_2 ) ;
F_22 ( V_2 ) ;
V_118 = F_48 ( V_2 , V_15 , V_55 , F_25 , 0 ) ;
if ( V_118 )
break;
V_117 [ V_84 ] = F_23 ( V_2 , V_15 ) ;
}
F_19 ( V_5 -> V_93 | V_116 ,
V_2 -> V_8 + V_94 ) ;
F_21 ( V_2 ) ;
return V_118 ? V_118 : V_55 -> V_120 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_54 * V_55 ,
unsigned int * V_117 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_36 = F_17 ( V_55 -> V_34 ) ;
int V_84 ;
for ( V_84 = 0 ; V_84 < V_55 -> V_120 ; V_84 ++ ) {
F_19 ( ( V_117 [ V_84 ] & 0xff ) ,
V_2 -> V_8 + F_50 ( V_36 ) ) ;
F_19 ( ( V_117 [ V_84 ] >> 8 ) & 0x0f ,
V_2 -> V_8 + F_51 ( V_36 ) ) ;
V_5 -> V_121 [ V_36 ] = V_117 [ V_84 ] ;
}
return V_55 -> V_120 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_54 * V_55 ,
unsigned int * V_117 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_36 = F_17 ( V_55 -> V_34 ) ;
int V_84 ;
for ( V_84 = 0 ; V_84 < V_55 -> V_120 ; V_84 ++ )
V_117 [ V_84 ] = V_5 -> V_121 [ V_36 ] ;
return V_55 -> V_120 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_54 * V_55 ,
unsigned int * V_117 )
{
V_117 [ 1 ] = F_24 ( V_2 -> V_8 + V_122 ) |
( F_24 ( V_2 -> V_8 + V_123 ) << 8 ) ;
return V_55 -> V_120 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_54 * V_55 ,
unsigned int * V_117 )
{
if ( F_55 ( V_15 , V_117 ) ) {
F_19 ( V_15 -> V_124 & 0xff , V_2 -> V_8 + V_125 ) ;
F_19 ( ( V_15 -> V_124 >> 8 ) , V_2 -> V_8 + V_126 ) ;
}
V_117 [ 1 ] = V_15 -> V_124 ;
return V_55 -> V_120 ;
}
static void F_56 ( struct V_1 * V_2 )
{
const struct V_61 * V_62 = F_27 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_36 ;
F_19 ( V_5 -> V_93 | V_116 ,
V_2 -> V_8 + V_94 ) ;
F_21 ( V_2 ) ;
if ( V_62 -> V_127 )
F_1 ( V_2 , false ) ;
V_5 -> V_39 = F_57 ( 16 , 0 , 0 ) ;
F_16 ( V_2 , F_57 ( 0 , 0 , 0 ) , 0 ) ;
for ( V_36 = 0 ; V_36 < V_62 -> V_128 ; V_36 ++ ) {
F_19 ( 0 , V_2 -> V_8 + F_50 ( V_36 ) ) ;
F_19 ( 0 , V_2 -> V_8 + F_51 ( V_36 ) ) ;
}
if ( V_62 -> V_129 ) {
F_19 ( 0 , V_2 -> V_8 + V_126 ) ;
F_19 ( 0 , V_2 -> V_8 + V_125 ) ;
}
}
static void F_58 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_130 * V_131 )
{
const struct V_61 * V_62 = F_27 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
V_15 -> V_132 = V_62 -> V_133 ;
switch ( V_62 -> V_134 ) {
case V_135 :
if ( V_131 -> V_136 [ 4 ] == 1 )
V_15 -> V_132 = & V_137 ;
break;
case V_138 :
switch ( V_131 -> V_136 [ 4 ] ) {
case 0 :
V_15 -> V_132 = & V_139 ;
break;
case 1 :
V_15 -> V_132 = & V_140 ;
break;
case 2 :
V_15 -> V_132 = & V_141 ;
break;
case 3 :
V_15 -> V_132 = & V_142 ;
break;
case 4 :
V_15 -> V_132 = & V_143 ;
break;
case 5 :
V_15 -> V_132 = & V_144 ;
break;
default:
V_15 -> V_132 = & V_139 ;
break;
}
break;
case V_145 :
if ( V_131 -> V_136 [ 1 ] == 1 )
V_15 -> V_132 = & V_146 ;
break;
case V_147 :
switch ( V_131 -> V_136 [ 1 ] ) {
case 0 :
V_15 -> V_132 = & V_148 ;
break;
case 1 :
V_15 -> V_132 = & V_149 ;
break;
case 2 :
V_15 -> V_132 = & V_150 ;
V_5 -> V_45 = 1 ;
break;
case 3 :
V_15 -> V_132 = & V_151 ;
V_5 -> V_45 = 1 ;
break;
default:
V_15 -> V_132 = & V_148 ;
break;
}
break;
case V_152 :
switch ( V_131 -> V_136 [ 1 ] ) {
case 0 :
V_15 -> V_132 = & V_153 ;
break;
case 1 :
V_15 -> V_132 = & V_154 ;
break;
case 2 :
V_15 -> V_132 = & V_155 ;
V_5 -> V_45 = 1 ;
break;
case 3 :
V_15 -> V_132 = & V_156 ;
V_5 -> V_45 = 1 ;
break;
default:
V_15 -> V_132 = & V_153 ;
break;
}
break;
}
}
static int F_59 ( struct V_1 * V_2 , struct V_130 * V_131 )
{
const struct V_61 * V_62 = F_27 ( V_2 ) ;
struct V_4 * V_5 ;
struct V_14 * V_15 ;
int V_157 ;
int V_158 ;
int V_118 ;
int V_84 ;
V_5 = F_60 ( V_2 , sizeof( * V_5 ) ) ;
if ( ! V_5 )
return - V_159 ;
V_118 = F_61 ( V_2 , V_131 -> V_136 [ 0 ] , 0x10 ) ;
if ( V_118 )
return V_118 ;
if ( ( 1 << V_131 -> V_136 [ 1 ] ) & V_62 -> V_127 ) {
V_118 = F_62 ( V_131 -> V_136 [ 1 ] , F_40 , 0 ,
V_2 -> V_160 , V_2 ) ;
if ( V_118 == 0 )
V_2 -> V_106 = V_131 -> V_136 [ 1 ] ;
}
if ( V_2 -> V_106 && V_62 -> V_161 &&
( V_131 -> V_136 [ 2 ] == 3 || V_131 -> V_136 [ 2 ] == 1 ) ) {
V_118 = F_63 ( V_131 -> V_136 [ 2 ] , V_2 -> V_160 ) ;
if ( V_118 ) {
F_64 ( V_2 -> V_100 ,
L_2 ,
V_131 -> V_136 [ 2 ] ) ;
return - V_60 ;
}
V_5 -> V_31 = V_131 -> V_136 [ 2 ] ;
V_5 -> V_162 = 1 ;
V_5 -> V_24 = ( 1 << V_5 -> V_162 ) * V_163 ;
for ( V_84 = 0 ; V_84 < 2 ; V_84 ++ ) {
unsigned long V_105 ;
V_105 = F_65 ( V_164 , V_5 -> V_162 ) ;
if ( ! V_105 )
return - V_159 ;
V_5 -> V_105 [ V_84 ] = V_105 ;
V_5 -> V_33 [ V_84 ] = F_66 ( ( void * ) V_105 ) ;
}
}
switch ( V_62 -> V_134 ) {
case V_165 :
if ( V_131 -> V_136 [ 2 ] == 1 )
V_5 -> V_41 = 1 ;
break;
case V_166 :
case V_167 :
if ( V_131 -> V_136 [ 4 ] == 1 )
V_5 -> V_41 = 1 ;
break;
}
V_157 = 1 ;
if ( V_62 -> V_128 > 0 )
V_157 ++ ;
if ( V_62 -> V_129 )
V_157 += 2 ;
V_118 = F_67 ( V_2 , V_157 ) ;
if ( V_118 )
return V_118 ;
V_158 = 0 ;
V_15 = & V_2 -> V_168 [ V_158 ] ;
V_15 -> type = V_169 ;
V_15 -> V_170 = V_171 ;
if ( V_5 -> V_41 ) {
V_15 -> V_170 |= V_172 ;
V_15 -> V_173 = V_62 -> V_174 / 2 ;
} else {
V_15 -> V_170 |= V_175 ;
V_15 -> V_173 = V_62 -> V_174 ;
}
V_15 -> V_53 = V_62 -> V_176 ? 0xffff : 0x0fff ;
F_58 ( V_2 , V_15 , V_131 ) ;
V_15 -> V_177 = F_47 ;
if ( V_2 -> V_106 ) {
V_2 -> V_108 = V_15 ;
V_15 -> V_170 |= V_178 ;
V_15 -> V_179 = V_180 ;
V_15 -> V_181 = F_26 ;
V_15 -> V_182 = F_33 ;
V_15 -> V_183 = F_42 ;
V_15 -> V_184 = F_46 ;
}
V_5 -> V_40 = V_62 -> V_185 ;
V_158 ++ ;
if ( V_62 -> V_128 > 0 ) {
V_15 = & V_2 -> V_168 [ V_158 ] ;
V_15 -> type = V_186 ;
V_15 -> V_170 = V_187 | V_175 ;
V_15 -> V_173 = V_62 -> V_128 ;
V_15 -> V_53 = 0xfff ;
V_15 -> V_132 = & V_188 ;
V_15 -> V_177 = F_52 ;
V_15 -> V_189 = F_49 ;
switch ( V_62 -> V_134 ) {
case V_165 :
if ( V_131 -> V_136 [ 3 ] == 1 )
V_15 -> V_132 = & V_190 ;
break;
case V_138 :
case V_166 :
case V_135 :
case V_167 :
if ( V_131 -> V_136 [ 5 ] == 1 )
V_15 -> V_132 = & V_190 ;
if ( V_131 -> V_136 [ 5 ] == 2 )
V_15 -> V_132 = & V_191 ;
break;
}
V_158 ++ ;
}
if ( V_62 -> V_129 ) {
V_15 = & V_2 -> V_168 [ V_158 ] ;
V_15 -> type = V_192 ;
V_15 -> V_170 = V_171 ;
V_15 -> V_173 = 16 ;
V_15 -> V_53 = 1 ;
V_15 -> V_132 = & V_193 ;
V_15 -> V_194 = F_53 ;
V_158 ++ ;
V_15 = & V_2 -> V_168 [ V_158 ] ;
V_15 -> type = V_195 ;
V_15 -> V_170 = V_187 ;
V_15 -> V_173 = 16 ;
V_15 -> V_53 = 1 ;
V_15 -> V_132 = & V_193 ;
V_15 -> V_194 = F_54 ;
V_158 ++ ;
}
switch ( V_62 -> V_134 ) {
case V_167 :
case V_135 :
case V_138 :
case V_166 :
V_5 -> V_47 = 1 ;
if ( V_131 -> V_136 [ 3 ] > 0 )
V_5 -> V_70 = 1 ;
break;
case V_165 :
V_5 -> V_47 = 1 ;
V_5 -> V_93 = ( V_2 -> V_106 << 4 ) & 0xf0 ;
break;
case V_145 :
case V_196 :
case V_147 :
case V_152 :
V_5 -> V_47 = 5 ;
break;
}
F_56 ( V_2 ) ;
return 0 ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 ) {
if ( V_5 -> V_105 [ 0 ] )
F_69 ( V_5 -> V_105 [ 0 ] , V_5 -> V_162 ) ;
if ( V_5 -> V_105 [ 1 ] )
F_69 ( V_5 -> V_105 [ 1 ] , V_5 -> V_162 ) ;
if ( V_5 -> V_31 )
F_70 ( V_5 -> V_31 ) ;
}
F_71 ( V_2 ) ;
}

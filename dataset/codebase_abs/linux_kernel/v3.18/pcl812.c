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
const struct V_61 * V_62 = V_2 -> V_63 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_64 = 0 ;
unsigned int V_65 ;
unsigned int V_66 ;
V_64 |= F_27 ( & V_17 -> V_67 , V_68 ) ;
V_64 |= F_27 ( & V_17 -> V_69 , V_70 ) ;
if ( V_5 -> V_71 )
V_65 = V_72 ;
else
V_65 = V_73 ;
V_64 |= F_27 ( & V_17 -> V_74 , V_65 ) ;
V_64 |= F_27 ( & V_17 -> V_75 , V_76 ) ;
V_64 |= F_27 ( & V_17 -> V_26 , V_76 | V_27 ) ;
if ( V_64 )
return 1 ;
V_64 |= F_28 ( V_17 -> V_26 ) ;
if ( V_64 )
return 2 ;
V_64 |= F_29 ( & V_17 -> V_77 , 0 ) ;
V_64 |= F_29 ( & V_17 -> V_78 , 0 ) ;
if ( V_17 -> V_74 == V_73 )
V_64 |= F_30 ( & V_17 -> V_79 ,
V_62 -> V_80 ) ;
else
V_64 |= F_29 ( & V_17 -> V_79 , 0 ) ;
V_64 |= F_30 ( & V_17 -> V_81 , 1 ) ;
V_64 |= F_29 ( & V_17 -> V_82 , V_17 -> V_81 ) ;
if ( V_17 -> V_26 == V_76 )
V_64 |= F_30 ( & V_17 -> V_28 , 1 ) ;
else
V_64 |= F_29 ( & V_17 -> V_28 , 0 ) ;
if ( V_64 )
return 3 ;
if ( V_17 -> V_74 == V_73 ) {
V_66 = V_17 -> V_79 ;
F_31 ( V_83 ,
& V_5 -> V_13 ,
& V_5 -> V_12 ,
& V_66 , V_17 -> V_65 ) ;
V_64 |= F_29 ( & V_17 -> V_79 , V_66 ) ;
}
if ( V_64 )
return 4 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_16 * V_17 = & V_15 -> V_18 -> V_17 ;
unsigned int V_84 = 0 ;
unsigned int V_85 ;
F_1 ( V_2 , false ) ;
F_16 ( V_2 , V_17 -> V_86 [ 0 ] , 1 ) ;
if ( V_5 -> V_31 ) {
V_5 -> V_87 = 1 ;
for ( V_85 = 1 ; V_85 < V_17 -> V_81 ; V_85 ++ )
if ( V_17 -> V_86 [ 0 ] != V_17 -> V_86 [ V_85 ] ) {
V_5 -> V_87 = 0 ;
break;
}
} else {
V_5 -> V_87 = 0 ;
}
V_5 -> V_88 = 0 ;
V_5 -> V_89 = 0 ;
V_15 -> V_18 -> V_90 = 0 ;
if ( V_17 -> V_65 & V_91 ) {
V_5 -> V_21 = 1 ;
if ( V_17 -> V_81 == 1 )
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
F_19 ( V_5 -> V_94 | V_84 , V_2 -> V_8 + V_95 ) ;
return 0 ;
}
static bool F_33 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_16 * V_17 = & V_15 -> V_18 -> V_17 ;
V_15 -> V_18 -> V_96 |= V_97 ;
V_15 -> V_18 -> V_90 ++ ;
if ( V_15 -> V_18 -> V_90 >= V_17 -> V_81 ) {
V_15 -> V_18 -> V_90 = 0 ;
V_5 -> V_88 ++ ;
V_15 -> V_18 -> V_96 |= V_98 ;
}
if ( V_17 -> V_26 == V_76 &&
V_5 -> V_88 >= V_17 -> V_28 ) {
V_15 -> V_18 -> V_96 |= V_99 ;
return false ;
}
return true ;
}
static void F_34 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 = & V_15 -> V_18 -> V_17 ;
unsigned int V_100 ;
if ( F_25 ( V_2 , V_15 , NULL , 0 ) ) {
F_35 ( V_2 -> V_101 , L_1 ) ;
V_15 -> V_18 -> V_96 |= V_99 | V_102 ;
return;
}
F_36 ( V_15 , F_23 ( V_2 , V_15 ) ) ;
V_100 = V_15 -> V_18 -> V_90 + 1 ;
if ( V_100 >= V_17 -> V_81 )
V_100 = 0 ;
if ( V_17 -> V_86 [ V_15 -> V_18 -> V_90 ] != V_17 -> V_86 [ V_100 ] )
F_16 ( V_2 , V_17 -> V_86 [ V_100 ] , 0 ) ;
F_33 ( V_2 , V_15 ) ;
}
static void F_37 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
unsigned short * V_103 ,
unsigned int V_104 , unsigned int V_105 )
{
unsigned int V_85 ;
for ( V_85 = V_105 ; V_85 ; V_85 -- ) {
F_36 ( V_15 , V_103 [ V_104 ++ ] ) ;
if ( ! F_33 ( V_2 , V_15 ) )
break;
}
}
static void F_38 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_105 , V_104 ;
unsigned short * V_103 ;
V_103 = ( unsigned short * ) V_5 -> V_106 [ V_5 -> V_30 ] ;
V_105 = ( V_5 -> V_22 [ V_5 -> V_30 ] >> 1 ) -
V_5 -> V_89 ;
F_14 ( V_2 , V_15 ) ;
V_104 = V_5 -> V_89 ;
V_5 -> V_89 = 0 ;
F_37 ( V_2 , V_15 , V_103 , V_104 , V_105 ) ;
}
static T_1 F_39 ( int V_107 , void * V_108 )
{
struct V_1 * V_2 = V_108 ;
struct V_14 * V_15 = V_2 -> V_109 ;
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_2 -> V_110 ) {
F_21 ( V_2 ) ;
return V_111 ;
}
if ( V_5 -> V_87 )
F_38 ( V_2 , V_15 ) ;
else
F_34 ( V_2 , V_15 ) ;
F_21 ( V_2 ) ;
F_40 ( V_2 , V_15 ) ;
return V_111 ;
}
static int F_41 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_65 ;
unsigned int V_112 , V_113 , V_85 ;
if ( ! V_5 -> V_87 )
return 0 ;
F_42 ( & V_2 -> V_114 , V_65 ) ;
for ( V_85 = 0 ; V_85 < 10 ; V_85 ++ ) {
V_112 = F_43 ( V_5 -> V_87 ) ;
V_113 = F_43 ( V_5 -> V_87 ) ;
if ( V_112 == V_113 )
break;
}
if ( V_112 != V_113 ) {
F_44 ( & V_2 -> V_114 , V_65 ) ;
return 0 ;
}
V_112 = V_5 -> V_22 [ 1 - V_5 -> V_30 ] - V_112 ;
V_112 >>= 1 ;
V_113 = V_112 - V_5 -> V_89 ;
if ( V_113 < 1 ) {
F_44 ( & V_2 -> V_114 , V_65 ) ;
return 0 ;
}
F_37 ( V_2 , V_15 ,
( void * ) V_5 -> V_106 [ 1 -
V_5 -> V_30 ] ,
V_5 -> V_89 , V_113 ) ;
V_5 -> V_89 = V_112 ;
F_44 ( & V_2 -> V_114 , V_65 ) ;
return F_45 ( V_15 ) ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 -> V_87 )
F_15 ( V_5 -> V_31 ) ;
F_19 ( V_5 -> V_94 | V_115 ,
V_2 -> V_8 + V_95 ) ;
F_1 ( V_2 , false ) ;
F_21 ( V_2 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_54 * V_55 ,
unsigned int * V_116 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_117 = 0 ;
int V_85 ;
F_19 ( V_5 -> V_94 | V_118 ,
V_2 -> V_8 + V_95 ) ;
F_16 ( V_2 , V_55 -> V_34 , 1 ) ;
for ( V_85 = 0 ; V_85 < V_55 -> V_119 ; V_85 ++ ) {
F_21 ( V_2 ) ;
F_22 ( V_2 ) ;
V_117 = F_48 ( V_2 , V_15 , V_55 , F_25 , 0 ) ;
if ( V_117 )
break;
V_116 [ V_85 ] = F_23 ( V_2 , V_15 ) ;
}
F_19 ( V_5 -> V_94 | V_115 ,
V_2 -> V_8 + V_95 ) ;
F_21 ( V_2 ) ;
return V_117 ? V_117 : V_55 -> V_119 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_54 * V_55 ,
unsigned int * V_116 )
{
unsigned int V_36 = F_17 ( V_55 -> V_34 ) ;
unsigned int V_50 = V_15 -> V_120 [ V_36 ] ;
int V_85 ;
for ( V_85 = 0 ; V_85 < V_55 -> V_119 ; V_85 ++ ) {
V_50 = V_116 [ V_85 ] ;
F_19 ( V_50 & 0xff , V_2 -> V_8 + F_50 ( V_36 ) ) ;
F_19 ( ( V_50 >> 8 ) & 0x0f , V_2 -> V_8 + F_51 ( V_36 ) ) ;
}
V_15 -> V_120 [ V_36 ] = V_50 ;
return V_55 -> V_119 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_54 * V_55 ,
unsigned int * V_116 )
{
V_116 [ 1 ] = F_24 ( V_2 -> V_8 + V_121 ) |
( F_24 ( V_2 -> V_8 + V_122 ) << 8 ) ;
return V_55 -> V_119 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_54 * V_55 ,
unsigned int * V_116 )
{
if ( F_54 ( V_15 , V_116 ) ) {
F_19 ( V_15 -> V_123 & 0xff , V_2 -> V_8 + V_124 ) ;
F_19 ( ( V_15 -> V_123 >> 8 ) , V_2 -> V_8 + V_125 ) ;
}
V_116 [ 1 ] = V_15 -> V_123 ;
return V_55 -> V_119 ;
}
static void F_55 ( struct V_1 * V_2 )
{
const struct V_61 * V_62 = V_2 -> V_63 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_36 ;
F_19 ( V_5 -> V_94 | V_115 ,
V_2 -> V_8 + V_95 ) ;
F_21 ( V_2 ) ;
if ( V_62 -> V_126 )
F_1 ( V_2 , false ) ;
V_5 -> V_39 = F_56 ( 16 , 0 , 0 ) ;
F_16 ( V_2 , F_56 ( 0 , 0 , 0 ) , 0 ) ;
for ( V_36 = 0 ; V_36 < V_62 -> V_127 ; V_36 ++ ) {
F_19 ( 0 , V_2 -> V_8 + F_50 ( V_36 ) ) ;
F_19 ( 0 , V_2 -> V_8 + F_51 ( V_36 ) ) ;
}
if ( V_62 -> V_128 ) {
F_19 ( 0 , V_2 -> V_8 + V_125 ) ;
F_19 ( 0 , V_2 -> V_8 + V_124 ) ;
}
}
static void F_57 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_129 * V_130 )
{
const struct V_61 * V_62 = V_2 -> V_63 ;
struct V_4 * V_5 = V_2 -> V_6 ;
V_15 -> V_131 = V_62 -> V_132 ;
switch ( V_62 -> V_133 ) {
case V_134 :
if ( V_130 -> V_135 [ 4 ] == 1 )
V_15 -> V_131 = & V_136 ;
break;
case V_137 :
switch ( V_130 -> V_135 [ 4 ] ) {
case 0 :
V_15 -> V_131 = & V_138 ;
break;
case 1 :
V_15 -> V_131 = & V_139 ;
break;
case 2 :
V_15 -> V_131 = & V_140 ;
break;
case 3 :
V_15 -> V_131 = & V_141 ;
break;
case 4 :
V_15 -> V_131 = & V_142 ;
break;
case 5 :
V_15 -> V_131 = & V_143 ;
break;
default:
V_15 -> V_131 = & V_138 ;
break;
}
break;
case V_144 :
if ( V_130 -> V_135 [ 1 ] == 1 )
V_15 -> V_131 = & V_145 ;
break;
case V_146 :
switch ( V_130 -> V_135 [ 1 ] ) {
case 0 :
V_15 -> V_131 = & V_147 ;
break;
case 1 :
V_15 -> V_131 = & V_148 ;
break;
case 2 :
V_15 -> V_131 = & V_149 ;
V_5 -> V_45 = 1 ;
break;
case 3 :
V_15 -> V_131 = & V_150 ;
V_5 -> V_45 = 1 ;
break;
default:
V_15 -> V_131 = & V_147 ;
break;
}
break;
case V_151 :
switch ( V_130 -> V_135 [ 1 ] ) {
case 0 :
V_15 -> V_131 = & V_152 ;
break;
case 1 :
V_15 -> V_131 = & V_153 ;
break;
case 2 :
V_15 -> V_131 = & V_154 ;
V_5 -> V_45 = 1 ;
break;
case 3 :
V_15 -> V_131 = & V_155 ;
V_5 -> V_45 = 1 ;
break;
default:
V_15 -> V_131 = & V_152 ;
break;
}
break;
}
}
static int F_58 ( struct V_1 * V_2 , struct V_129 * V_130 )
{
const struct V_61 * V_62 = V_2 -> V_63 ;
struct V_4 * V_5 ;
struct V_14 * V_15 ;
int V_156 ;
int V_157 ;
int V_117 ;
int V_85 ;
V_5 = F_59 ( V_2 , sizeof( * V_5 ) ) ;
if ( ! V_5 )
return - V_158 ;
V_117 = F_60 ( V_2 , V_130 -> V_135 [ 0 ] , 0x10 ) ;
if ( V_117 )
return V_117 ;
if ( ( 1 << V_130 -> V_135 [ 1 ] ) & V_62 -> V_126 ) {
V_117 = F_61 ( V_130 -> V_135 [ 1 ] , F_39 , 0 ,
V_2 -> V_159 , V_2 ) ;
if ( V_117 == 0 )
V_2 -> V_107 = V_130 -> V_135 [ 1 ] ;
}
if ( V_2 -> V_107 && V_62 -> V_160 &&
( V_130 -> V_135 [ 2 ] == 3 || V_130 -> V_135 [ 2 ] == 1 ) ) {
V_117 = F_62 ( V_130 -> V_135 [ 2 ] , V_2 -> V_159 ) ;
if ( V_117 ) {
F_63 ( V_2 -> V_101 ,
L_2 ,
V_130 -> V_135 [ 2 ] ) ;
return - V_60 ;
}
V_5 -> V_31 = V_130 -> V_135 [ 2 ] ;
V_5 -> V_161 = 1 ;
V_5 -> V_24 = ( 1 << V_5 -> V_161 ) * V_162 ;
for ( V_85 = 0 ; V_85 < 2 ; V_85 ++ ) {
unsigned long V_106 ;
V_106 = F_64 ( V_163 , V_5 -> V_161 ) ;
if ( ! V_106 )
return - V_158 ;
V_5 -> V_106 [ V_85 ] = V_106 ;
V_5 -> V_33 [ V_85 ] = F_65 ( ( void * ) V_106 ) ;
}
}
switch ( V_62 -> V_133 ) {
case V_164 :
if ( V_130 -> V_135 [ 2 ] == 1 )
V_5 -> V_41 = 1 ;
break;
case V_165 :
case V_166 :
if ( V_130 -> V_135 [ 4 ] == 1 )
V_5 -> V_41 = 1 ;
break;
}
V_156 = 1 ;
if ( V_62 -> V_127 > 0 )
V_156 ++ ;
if ( V_62 -> V_128 )
V_156 += 2 ;
V_117 = F_66 ( V_2 , V_156 ) ;
if ( V_117 )
return V_117 ;
V_157 = 0 ;
V_15 = & V_2 -> V_167 [ V_157 ] ;
V_15 -> type = V_168 ;
V_15 -> V_169 = V_170 ;
if ( V_5 -> V_41 ) {
V_15 -> V_169 |= V_171 ;
V_15 -> V_172 = V_62 -> V_173 / 2 ;
} else {
V_15 -> V_169 |= V_174 ;
V_15 -> V_172 = V_62 -> V_173 ;
}
V_15 -> V_53 = V_62 -> V_175 ? 0xffff : 0x0fff ;
F_57 ( V_2 , V_15 , V_130 ) ;
V_15 -> V_176 = F_47 ;
if ( V_2 -> V_107 ) {
V_2 -> V_109 = V_15 ;
V_15 -> V_169 |= V_177 ;
V_15 -> V_178 = V_179 ;
V_15 -> V_180 = F_26 ;
V_15 -> V_181 = F_32 ;
V_15 -> V_182 = F_41 ;
V_15 -> V_183 = F_46 ;
}
V_5 -> V_40 = V_62 -> V_184 ;
V_157 ++ ;
if ( V_62 -> V_127 > 0 ) {
V_15 = & V_2 -> V_167 [ V_157 ] ;
V_15 -> type = V_185 ;
V_15 -> V_169 = V_186 | V_174 ;
V_15 -> V_172 = V_62 -> V_127 ;
V_15 -> V_53 = 0xfff ;
V_15 -> V_131 = & V_187 ;
switch ( V_62 -> V_133 ) {
case V_164 :
if ( V_130 -> V_135 [ 3 ] == 1 )
V_15 -> V_131 = & V_188 ;
break;
case V_137 :
case V_165 :
case V_134 :
case V_166 :
if ( V_130 -> V_135 [ 5 ] == 1 )
V_15 -> V_131 = & V_188 ;
if ( V_130 -> V_135 [ 5 ] == 2 )
V_15 -> V_131 = & V_189 ;
break;
}
V_15 -> V_190 = F_49 ;
V_15 -> V_176 = V_191 ;
V_117 = F_67 ( V_15 ) ;
if ( V_117 )
return V_117 ;
V_157 ++ ;
}
if ( V_62 -> V_128 ) {
V_15 = & V_2 -> V_167 [ V_157 ] ;
V_15 -> type = V_192 ;
V_15 -> V_169 = V_170 ;
V_15 -> V_172 = 16 ;
V_15 -> V_53 = 1 ;
V_15 -> V_131 = & V_193 ;
V_15 -> V_194 = F_52 ;
V_157 ++ ;
V_15 = & V_2 -> V_167 [ V_157 ] ;
V_15 -> type = V_195 ;
V_15 -> V_169 = V_186 ;
V_15 -> V_172 = 16 ;
V_15 -> V_53 = 1 ;
V_15 -> V_131 = & V_193 ;
V_15 -> V_194 = F_53 ;
V_157 ++ ;
}
switch ( V_62 -> V_133 ) {
case V_166 :
case V_134 :
case V_137 :
case V_165 :
V_5 -> V_47 = 1 ;
if ( V_130 -> V_135 [ 3 ] > 0 )
V_5 -> V_71 = 1 ;
break;
case V_164 :
V_5 -> V_47 = 1 ;
V_5 -> V_94 = ( V_2 -> V_107 << 4 ) & 0xf0 ;
break;
case V_144 :
case V_196 :
case V_146 :
case V_151 :
V_5 -> V_47 = 5 ;
break;
}
F_55 ( V_2 ) ;
return 0 ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 ) {
if ( V_5 -> V_106 [ 0 ] )
F_69 ( V_5 -> V_106 [ 0 ] , V_5 -> V_161 ) ;
if ( V_5 -> V_106 [ 1 ] )
F_69 ( V_5 -> V_106 [ 1 ] , V_5 -> V_161 ) ;
if ( V_5 -> V_31 )
F_70 ( V_5 -> V_31 ) ;
}
F_71 ( V_2 ) ;
}

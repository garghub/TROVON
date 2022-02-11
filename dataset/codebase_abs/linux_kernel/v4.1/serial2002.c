static long F_1 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned long V_4 )
{
if ( V_2 -> V_5 -> V_6 )
return V_2 -> V_5 -> V_6 ( V_2 , V_3 , V_4 ) ;
return - V_7 ;
}
static int F_2 ( struct V_1 * V_2 , unsigned char * V_8 , int V_9 )
{
const char T_1 * V_10 = ( V_11 const char T_1 * ) V_8 ;
int V_12 ;
T_2 V_13 = 0 ;
T_3 V_14 ;
V_14 = F_3 () ;
F_4 ( V_15 ) ;
V_12 = F_5 ( V_2 , V_10 , V_9 , & V_13 ) ;
F_4 ( V_14 ) ;
return V_12 ;
}
static void F_6 ( struct V_1 * V_2 , int V_16 )
{
struct V_17 V_18 ;
struct V_19 V_20 , V_21 ;
F_7 ( & V_20 ) ;
F_8 ( & V_18 ) ;
while ( 1 ) {
long V_22 ;
int V_23 ;
V_23 = V_2 -> V_5 -> V_24 ( V_2 , & V_18 . V_25 ) ;
if ( V_23 & ( V_26 | V_27 | V_28 |
V_29 | V_30 ) ) {
break;
}
F_7 ( & V_21 ) ;
V_22 = 1000000 * ( V_21 . V_31 - V_20 . V_31 ) +
V_21 . V_32 - V_20 . V_32 ;
if ( V_22 > V_16 )
break;
F_9 ( V_33 ) ;
F_10 ( ( ( V_16 - V_22 ) * V_34 ) / 10000 ) ;
}
F_11 ( & V_18 ) ;
}
static int F_12 ( struct V_1 * V_2 , int V_16 )
{
unsigned char V_35 ;
int V_12 ;
V_12 = - 1 ;
if ( ! F_13 ( V_2 ) ) {
T_3 V_14 ;
char T_1 * V_10 = ( V_11 char T_1 * ) & V_35 ;
T_2 V_13 = 0 ;
V_14 = F_3 () ;
F_4 ( V_15 ) ;
if ( V_2 -> V_5 -> V_24 ) {
F_6 ( V_2 , V_16 ) ;
if ( F_14 ( V_2 , V_10 , 1 , & V_13 ) == 1 )
V_12 = V_35 ;
} else {
int V_36 = 0 ;
while ( 1 ) {
V_36 ++ ;
if ( V_36 >= V_16 )
break;
if ( F_14 ( V_2 , V_10 , 1 , & V_13 ) == 1 ) {
V_12 = V_35 ;
break;
}
F_15 ( 100 ) ;
}
}
F_4 ( V_14 ) ;
}
return V_12 ;
}
static void F_16 ( struct V_1 * V_2 , int V_37 )
{
struct V_38 V_38 ;
struct V_39 V_40 ;
T_3 V_14 ;
V_14 = F_3 () ;
F_4 ( V_15 ) ;
F_1 ( V_2 , V_41 , ( unsigned long ) & V_38 ) ;
V_38 . V_42 = 0 ;
V_38 . V_43 = 0 ;
V_38 . V_44 = 0 ;
V_38 . V_45 = V_46 | V_47 | V_48 ;
V_38 . V_49 [ V_50 ] = 0 ;
V_38 . V_49 [ V_51 ] = 0 ;
switch ( V_37 ) {
case 2400 :
V_38 . V_45 |= V_52 ;
break;
case 4800 :
V_38 . V_45 |= V_53 ;
break;
case 9600 :
V_38 . V_45 |= V_54 ;
break;
case 19200 :
V_38 . V_45 |= V_55 ;
break;
case 38400 :
V_38 . V_45 |= V_56 ;
break;
case 57600 :
V_38 . V_45 |= V_57 ;
break;
case 115200 :
V_38 . V_45 |= V_58 ;
break;
default:
V_38 . V_45 |= V_54 ;
break;
}
F_1 ( V_2 , V_59 , ( unsigned long ) & V_38 ) ;
F_1 ( V_2 , V_60 , ( unsigned long ) & V_40 ) ;
V_40 . V_61 |= V_62 ;
F_1 ( V_2 , V_63 , ( unsigned long ) & V_40 ) ;
F_4 ( V_14 ) ;
}
static void F_17 ( struct V_1 * V_2 , int V_64 )
{
char V_65 ;
V_65 = 0x40 | ( V_64 & 0x1f ) ;
F_2 ( V_2 , & V_65 , 1 ) ;
}
static void F_18 ( struct V_1 * V_2 , int V_64 )
{
char V_65 ;
V_65 = 0x60 | ( V_64 & 0x1f ) ;
F_2 ( V_2 , & V_65 , 1 ) ;
}
static struct V_66 F_19 ( struct V_1 * V_2 , int V_16 )
{
struct V_66 V_12 ;
int V_67 ;
V_12 . V_68 = V_69 ;
V_12 . V_70 = 0 ;
V_12 . V_71 = 0 ;
V_67 = 0 ;
while ( 1 ) {
int V_72 = F_12 ( V_2 , V_16 ) ;
V_67 ++ ;
if ( V_72 < 0 ) {
break;
} else if ( V_72 & 0x80 ) {
V_12 . V_71 = ( V_12 . V_71 << 7 ) | ( V_72 & 0x7f ) ;
} else {
if ( V_67 == 1 ) {
switch ( ( V_72 >> 5 ) & 0x03 ) {
case 0 :
V_12 . V_71 = 0 ;
V_12 . V_68 = V_73 ;
break;
case 1 :
V_12 . V_71 = 1 ;
V_12 . V_68 = V_73 ;
break;
}
} else {
V_12 . V_71 =
( V_12 . V_71 << 2 ) | ( ( V_72 & 0x60 ) >> 5 ) ;
V_12 . V_68 = V_74 ;
}
V_12 . V_70 = V_72 & 0x1f ;
break;
}
}
return V_12 ;
}
static void F_20 ( struct V_1 * V_2 , struct V_66 V_72 )
{
if ( V_72 . V_68 == V_73 ) {
unsigned char V_35 =
( ( V_72 . V_71 << 5 ) & 0x20 ) | ( V_72 . V_70 & 0x1f ) ;
F_2 ( V_2 , & V_35 , 1 ) ;
} else {
unsigned char V_35 [ 6 ] ;
int V_75 = 0 ;
if ( V_72 . V_71 >= ( 1L << 30 ) ) {
V_35 [ V_75 ] = 0x80 | ( ( V_72 . V_71 >> 30 ) & 0x03 ) ;
V_75 ++ ;
}
if ( V_72 . V_71 >= ( 1L << 23 ) ) {
V_35 [ V_75 ] = 0x80 | ( ( V_72 . V_71 >> 23 ) & 0x7f ) ;
V_75 ++ ;
}
if ( V_72 . V_71 >= ( 1L << 16 ) ) {
V_35 [ V_75 ] = 0x80 | ( ( V_72 . V_71 >> 16 ) & 0x7f ) ;
V_75 ++ ;
}
if ( V_72 . V_71 >= ( 1L << 9 ) ) {
V_35 [ V_75 ] = 0x80 | ( ( V_72 . V_71 >> 9 ) & 0x7f ) ;
V_75 ++ ;
}
V_35 [ V_75 ] = 0x80 | ( ( V_72 . V_71 >> 2 ) & 0x7f ) ;
V_75 ++ ;
V_35 [ V_75 ] = ( ( V_72 . V_71 << 5 ) & 0x60 ) | ( V_72 . V_70 & 0x1f ) ;
V_75 ++ ;
F_2 ( V_2 , V_35 , V_75 ) ;
}
}
static int F_21 ( struct V_76 * V_77 ,
struct V_78 * V_79 ,
struct V_80 * V_81 ,
unsigned char * V_82 ,
int V_68 )
{
const struct V_83 * * V_84 = NULL ;
unsigned int * V_85 ;
int V_86 , V_87 ;
for ( V_87 = 0 , V_86 = 0 ; V_86 < 32 ; V_86 ++ ) {
if ( V_79 [ V_86 ] . V_68 == V_68 )
V_87 ++ ;
}
V_77 -> V_88 = V_87 ;
V_77 -> V_89 = 0 ;
F_22 ( V_77 -> V_85 ) ;
V_85 = F_23 ( V_77 -> V_88 , sizeof( unsigned int ) ,
V_90 ) ;
if ( ! V_85 )
return - V_91 ;
V_77 -> V_85 = V_85 ;
F_22 ( V_77 -> V_84 ) ;
V_77 -> V_92 = NULL ;
V_77 -> V_84 = NULL ;
if ( V_68 == 1 || V_68 == 2 ) {
V_77 -> V_92 = & V_93 ;
} else if ( V_81 ) {
V_84 = F_23 ( V_77 -> V_88 , sizeof( * V_81 ) ,
V_90 ) ;
if ( ! V_84 )
return - V_91 ;
V_77 -> V_84 = V_84 ;
}
for ( V_87 = 0 , V_86 = 0 ; V_86 < 32 ; V_86 ++ ) {
if ( V_79 [ V_86 ] . V_68 == V_68 ) {
if ( V_82 )
V_82 [ V_87 ] = V_86 ;
if ( V_81 ) {
V_81 [ V_86 ] . V_67 = 1 ;
V_81 [ V_86 ] . V_81 . V_94 = V_79 [ V_86 ] . V_94 ;
V_81 [ V_86 ] . V_81 . V_95 = V_79 [ V_86 ] . V_95 ;
V_84 [ V_87 ] =
( const struct V_83 * ) & V_81 [ V_86 ] ;
}
V_85 [ V_87 ] = ( ( long long ) 1 << V_79 [ V_86 ] . V_96 ) - 1 ;
V_87 ++ ;
}
}
return 0 ;
}
static int F_24 ( struct V_97 * V_98 )
{
struct V_99 * V_100 = V_98 -> V_101 ;
struct V_78 * V_102 ;
struct V_78 * V_103 ;
struct V_78 * V_104 ;
struct V_78 * V_105 ;
struct V_78 * V_79 ;
struct V_76 * V_77 ;
int V_12 = 0 ;
int V_75 ;
V_102 = F_25 ( 32 , sizeof( * V_79 ) , V_90 ) ;
V_103 = F_25 ( 32 , sizeof( * V_79 ) , V_90 ) ;
V_104 = F_25 ( 32 , sizeof( * V_79 ) , V_90 ) ;
V_105 = F_25 ( 32 , sizeof( * V_79 ) , V_90 ) ;
if ( ! V_102 || ! V_103 || ! V_104 || ! V_105 ) {
V_12 = - V_91 ;
goto V_106;
}
F_16 ( V_100 -> V_107 , V_100 -> V_37 ) ;
F_18 ( V_100 -> V_107 , 31 ) ;
while ( 1 ) {
struct V_66 V_72 = F_19 ( V_100 -> V_107 , 1000 ) ;
int V_68 = F_26 ( V_72 . V_71 ) ;
int V_64 = F_27 ( V_72 . V_71 ) ;
int V_81 = F_28 ( V_72 . V_71 ) ;
int V_65 = F_29 ( V_72 . V_71 ) ;
if ( V_72 . V_68 != V_74 || V_72 . V_70 != 31 ||
V_68 == V_108 )
break;
switch ( V_68 ) {
case V_109 :
V_79 = V_102 ;
break;
case V_110 :
V_79 = V_103 ;
break;
case V_111 :
V_79 = V_104 ;
break;
case V_112 :
V_79 = V_105 ;
break;
case V_113 :
V_79 = V_104 ;
break;
default:
V_79 = NULL ;
break;
}
if ( ! V_79 )
continue;
V_79 [ V_64 ] . V_68 = V_68 ;
switch ( V_65 ) {
case V_114 :
V_79 [ V_64 ] . V_96 = F_30 ( V_72 . V_71 ) ;
break;
case V_115 :
case V_116 :
switch ( F_31 ( V_72 . V_71 ) ) {
case 0 :
V_81 *= 1000000 ;
break;
case 1 :
V_81 *= 1000 ;
break;
case 2 :
V_81 *= 1 ;
break;
}
if ( F_32 ( V_72 . V_71 ) )
V_81 = - V_81 ;
if ( V_65 == V_115 )
V_79 [ V_64 ] . V_94 = V_81 ;
else
V_79 [ V_64 ] . V_95 = V_81 ;
break;
}
}
for ( V_75 = 0 ; V_75 <= 4 ; V_75 ++ ) {
unsigned char * V_82 = NULL ;
struct V_80 * V_81 = NULL ;
int V_68 = 0 ;
V_77 = & V_98 -> V_117 [ V_75 ] ;
switch ( V_75 ) {
case 0 :
V_79 = V_102 ;
V_82 = V_100 -> V_118 ;
V_68 = V_109 ;
break;
case 1 :
V_79 = V_103 ;
V_82 = V_100 -> V_119 ;
V_68 = V_110 ;
break;
case 2 :
V_79 = V_104 ;
V_82 = V_100 -> V_120 ;
V_81 = V_100 -> V_121 ;
V_68 = V_111 ;
break;
case 3 :
V_79 = V_105 ;
V_82 = V_100 -> V_122 ;
V_81 = V_100 -> V_123 ;
V_68 = V_112 ;
break;
case 4 :
V_79 = V_104 ;
V_82 = V_100 -> V_124 ;
V_81 = V_100 -> V_121 ;
V_68 = V_113 ;
break;
}
if ( F_21 ( V_77 , V_79 , V_81 , V_82 , V_68 ) )
break;
}
if ( V_75 <= 4 ) {
V_12 = - V_91 ;
for ( V_75 = 0 ; V_75 <= 4 ; V_75 ++ ) {
V_77 = & V_98 -> V_117 [ V_75 ] ;
F_22 ( V_77 -> V_85 ) ;
V_77 -> V_85 = NULL ;
F_22 ( V_77 -> V_84 ) ;
V_77 -> V_84 = NULL ;
}
}
V_106:
F_22 ( V_102 ) ;
F_22 ( V_103 ) ;
F_22 ( V_104 ) ;
F_22 ( V_105 ) ;
if ( V_12 ) {
if ( V_100 -> V_107 ) {
F_33 ( V_100 -> V_107 , NULL ) ;
V_100 -> V_107 = NULL ;
}
}
return V_12 ;
}
static int F_34 ( struct V_97 * V_98 )
{
struct V_99 * V_100 = V_98 -> V_101 ;
int V_12 ;
char V_125 [ 20 ] ;
sprintf ( V_125 , L_1 , V_100 -> V_125 ) ;
V_100 -> V_107 = F_35 ( V_125 , V_126 , 0 ) ;
if ( F_13 ( V_100 -> V_107 ) ) {
V_12 = ( int ) F_36 ( V_100 -> V_107 ) ;
F_37 ( V_98 -> V_127 , L_2 , V_12 ) ;
} else {
V_12 = F_24 ( V_98 ) ;
}
return V_12 ;
}
static void F_38 ( struct V_97 * V_98 )
{
struct V_99 * V_100 = V_98 -> V_101 ;
if ( ! F_13 ( V_100 -> V_107 ) && V_100 -> V_107 )
F_33 ( V_100 -> V_107 , NULL ) ;
}
static int F_39 ( struct V_97 * V_98 ,
struct V_76 * V_77 ,
struct V_128 * V_129 ,
unsigned int * V_72 )
{
struct V_99 * V_100 = V_98 -> V_101 ;
int V_130 ;
int V_87 ;
V_87 = V_100 -> V_118 [ F_40 ( V_129 -> V_131 ) ] ;
for ( V_130 = 0 ; V_130 < V_129 -> V_130 ; V_130 ++ ) {
struct V_66 V_132 ;
F_17 ( V_100 -> V_107 , V_87 ) ;
while ( 1 ) {
V_132 = F_19 ( V_100 -> V_107 , 1000 ) ;
if ( V_132 . V_68 != V_73 || V_132 . V_70 == V_87 )
break;
}
V_72 [ V_130 ] = V_132 . V_71 ;
}
return V_130 ;
}
static int F_41 ( struct V_97 * V_98 ,
struct V_76 * V_77 ,
struct V_128 * V_129 ,
unsigned int * V_72 )
{
struct V_99 * V_100 = V_98 -> V_101 ;
int V_130 ;
int V_87 ;
V_87 = V_100 -> V_119 [ F_40 ( V_129 -> V_131 ) ] ;
for ( V_130 = 0 ; V_130 < V_129 -> V_130 ; V_130 ++ ) {
struct V_66 V_133 ;
V_133 . V_68 = V_73 ;
V_133 . V_70 = V_87 ;
V_133 . V_71 = V_72 [ V_130 ] ;
F_20 ( V_100 -> V_107 , V_133 ) ;
}
return V_130 ;
}
static int F_42 ( struct V_97 * V_98 ,
struct V_76 * V_77 ,
struct V_128 * V_129 ,
unsigned int * V_72 )
{
struct V_99 * V_100 = V_98 -> V_101 ;
int V_130 ;
int V_87 ;
V_87 = V_100 -> V_120 [ F_40 ( V_129 -> V_131 ) ] ;
for ( V_130 = 0 ; V_130 < V_129 -> V_130 ; V_130 ++ ) {
struct V_66 V_132 ;
F_18 ( V_100 -> V_107 , V_87 ) ;
while ( 1 ) {
V_132 = F_19 ( V_100 -> V_107 , 1000 ) ;
if ( V_132 . V_68 != V_74 || V_132 . V_70 == V_87 )
break;
}
V_72 [ V_130 ] = V_132 . V_71 ;
}
return V_130 ;
}
static int F_43 ( struct V_97 * V_98 ,
struct V_76 * V_77 ,
struct V_128 * V_129 ,
unsigned int * V_72 )
{
struct V_99 * V_100 = V_98 -> V_101 ;
int V_130 ;
int V_87 ;
V_87 = V_100 -> V_122 [ F_40 ( V_129 -> V_131 ) ] ;
for ( V_130 = 0 ; V_130 < V_129 -> V_130 ; V_130 ++ ) {
struct V_66 V_133 ;
V_133 . V_68 = V_74 ;
V_133 . V_70 = V_87 ;
V_133 . V_71 = V_72 [ V_130 ] ;
F_20 ( V_100 -> V_107 , V_133 ) ;
V_100 -> V_134 [ V_87 ] = V_72 [ V_130 ] ;
}
return V_130 ;
}
static int F_44 ( struct V_97 * V_98 ,
struct V_76 * V_77 ,
struct V_128 * V_129 ,
unsigned int * V_72 )
{
struct V_99 * V_100 = V_98 -> V_101 ;
int V_130 ;
int V_87 = F_40 ( V_129 -> V_131 ) ;
for ( V_130 = 0 ; V_130 < V_129 -> V_130 ; V_130 ++ )
V_72 [ V_130 ] = V_100 -> V_134 [ V_87 ] ;
return V_130 ;
}
static int F_45 ( struct V_97 * V_98 ,
struct V_76 * V_77 ,
struct V_128 * V_129 ,
unsigned int * V_72 )
{
struct V_99 * V_100 = V_98 -> V_101 ;
int V_130 ;
int V_87 ;
V_87 = V_100 -> V_124 [ F_40 ( V_129 -> V_131 ) ] ;
for ( V_130 = 0 ; V_130 < V_129 -> V_130 ; V_130 ++ ) {
struct V_66 V_132 ;
F_18 ( V_100 -> V_107 , V_87 ) ;
while ( 1 ) {
V_132 = F_19 ( V_100 -> V_107 , 1000 ) ;
if ( V_132 . V_68 != V_74 || V_132 . V_70 == V_87 )
break;
}
V_72 [ V_130 ] = V_132 . V_71 ;
}
return V_130 ;
}
static int F_46 ( struct V_97 * V_98 ,
struct V_135 * V_136 )
{
struct V_99 * V_100 ;
struct V_76 * V_77 ;
int V_137 ;
V_100 = F_47 ( V_98 , sizeof( * V_100 ) ) ;
if ( ! V_100 )
return - V_91 ;
V_100 -> V_125 = V_136 -> V_138 [ 0 ] ;
V_100 -> V_37 = V_136 -> V_138 [ 1 ] ;
V_137 = F_48 ( V_98 , 5 ) ;
if ( V_137 )
return V_137 ;
V_77 = & V_98 -> V_117 [ 0 ] ;
V_77 -> type = V_139 ;
V_77 -> V_140 = V_141 ;
V_77 -> V_88 = 0 ;
V_77 -> V_89 = 1 ;
V_77 -> V_92 = & V_93 ;
V_77 -> V_142 = F_39 ;
V_77 = & V_98 -> V_117 [ 1 ] ;
V_77 -> type = V_143 ;
V_77 -> V_140 = V_144 ;
V_77 -> V_88 = 0 ;
V_77 -> V_89 = 1 ;
V_77 -> V_92 = & V_93 ;
V_77 -> V_145 = F_41 ;
V_77 = & V_98 -> V_117 [ 2 ] ;
V_77 -> type = V_146 ;
V_77 -> V_140 = V_141 | V_147 ;
V_77 -> V_88 = 0 ;
V_77 -> V_89 = 1 ;
V_77 -> V_92 = NULL ;
V_77 -> V_142 = F_42 ;
V_77 = & V_98 -> V_117 [ 3 ] ;
V_77 -> type = V_148 ;
V_77 -> V_140 = V_144 ;
V_77 -> V_88 = 0 ;
V_77 -> V_89 = 1 ;
V_77 -> V_92 = NULL ;
V_77 -> V_145 = F_43 ;
V_77 -> V_142 = F_44 ;
V_77 = & V_98 -> V_117 [ 4 ] ;
V_77 -> type = V_149 ;
V_77 -> V_140 = V_141 | V_150 ;
V_77 -> V_88 = 0 ;
V_77 -> V_89 = 1 ;
V_77 -> V_92 = NULL ;
V_77 -> V_142 = F_45 ;
V_98 -> V_151 = F_34 ;
V_98 -> V_152 = F_38 ;
return 0 ;
}
static void F_49 ( struct V_97 * V_98 )
{
struct V_76 * V_77 ;
int V_75 ;
for ( V_75 = 0 ; V_75 < V_98 -> V_153 ; V_75 ++ ) {
V_77 = & V_98 -> V_117 [ V_75 ] ;
F_22 ( V_77 -> V_85 ) ;
F_22 ( V_77 -> V_84 ) ;
}
}

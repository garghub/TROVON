static long F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
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
T_4 V_19 , V_20 ;
V_19 = F_7 () ;
F_8 ( & V_18 ) ;
while ( 1 ) {
long V_21 ;
int V_22 ;
V_22 = V_2 -> V_5 -> V_23 ( V_2 , & V_18 . V_24 ) ;
if ( V_22 & ( V_25 | V_26 | V_27 |
V_28 | V_29 ) ) {
break;
}
V_20 = F_7 () ;
V_21 = F_9 ( V_20 , V_19 ) ;
if ( V_21 > V_16 )
break;
F_10 ( V_30 ) ;
F_11 ( ( ( V_16 - V_21 ) * V_31 ) / 10000 ) ;
}
F_12 ( & V_18 ) ;
}
static int F_13 ( struct V_1 * V_2 , int V_16 )
{
unsigned char V_32 ;
int V_12 ;
V_12 = - 1 ;
if ( ! F_14 ( V_2 ) ) {
T_3 V_14 ;
char T_1 * V_10 = ( V_11 char T_1 * ) & V_32 ;
T_2 V_13 = 0 ;
V_14 = F_3 () ;
F_4 ( V_15 ) ;
if ( V_2 -> V_5 -> V_23 ) {
F_6 ( V_2 , V_16 ) ;
if ( F_15 ( V_2 , V_10 , 1 , & V_13 ) == 1 )
V_12 = V_32 ;
} else {
int V_33 = 0 ;
while ( 1 ) {
V_33 ++ ;
if ( V_33 >= V_16 )
break;
if ( F_15 ( V_2 , V_10 , 1 , & V_13 ) == 1 ) {
V_12 = V_32 ;
break;
}
F_16 ( 100 , 1000 ) ;
}
}
F_4 ( V_14 ) ;
}
return V_12 ;
}
static void F_17 ( struct V_1 * V_2 , int V_34 )
{
struct V_35 V_35 ;
struct V_36 V_37 ;
T_3 V_14 ;
V_14 = F_3 () ;
F_4 ( V_15 ) ;
F_1 ( V_2 , V_38 , ( unsigned long ) & V_35 ) ;
V_35 . V_39 = 0 ;
V_35 . V_40 = 0 ;
V_35 . V_41 = 0 ;
V_35 . V_42 = V_43 | V_44 | V_45 ;
V_35 . V_46 [ V_47 ] = 0 ;
V_35 . V_46 [ V_48 ] = 0 ;
switch ( V_34 ) {
case 2400 :
V_35 . V_42 |= V_49 ;
break;
case 4800 :
V_35 . V_42 |= V_50 ;
break;
case 9600 :
V_35 . V_42 |= V_51 ;
break;
case 19200 :
V_35 . V_42 |= V_52 ;
break;
case 38400 :
V_35 . V_42 |= V_53 ;
break;
case 57600 :
V_35 . V_42 |= V_54 ;
break;
case 115200 :
V_35 . V_42 |= V_55 ;
break;
default:
V_35 . V_42 |= V_51 ;
break;
}
F_1 ( V_2 , V_56 , ( unsigned long ) & V_35 ) ;
F_1 ( V_2 , V_57 , ( unsigned long ) & V_37 ) ;
V_37 . V_58 |= V_59 ;
F_1 ( V_2 , V_60 , ( unsigned long ) & V_37 ) ;
F_4 ( V_14 ) ;
}
static void F_18 ( struct V_1 * V_2 , int V_61 )
{
char V_62 ;
V_62 = 0x40 | ( V_61 & 0x1f ) ;
F_2 ( V_2 , & V_62 , 1 ) ;
}
static void F_19 ( struct V_1 * V_2 , int V_61 )
{
char V_62 ;
V_62 = 0x60 | ( V_61 & 0x1f ) ;
F_2 ( V_2 , & V_62 , 1 ) ;
}
static struct V_63 F_20 ( struct V_1 * V_2 , int V_16 )
{
struct V_63 V_12 ;
int V_64 ;
V_12 . V_65 = V_66 ;
V_12 . V_67 = 0 ;
V_12 . V_68 = 0 ;
V_64 = 0 ;
while ( 1 ) {
int V_69 = F_13 ( V_2 , V_16 ) ;
V_64 ++ ;
if ( V_69 < 0 ) {
break;
} else if ( V_69 & 0x80 ) {
V_12 . V_68 = ( V_12 . V_68 << 7 ) | ( V_69 & 0x7f ) ;
} else {
if ( V_64 == 1 ) {
switch ( ( V_69 >> 5 ) & 0x03 ) {
case 0 :
V_12 . V_68 = 0 ;
V_12 . V_65 = V_70 ;
break;
case 1 :
V_12 . V_68 = 1 ;
V_12 . V_65 = V_70 ;
break;
}
} else {
V_12 . V_68 =
( V_12 . V_68 << 2 ) | ( ( V_69 & 0x60 ) >> 5 ) ;
V_12 . V_65 = V_71 ;
}
V_12 . V_67 = V_69 & 0x1f ;
break;
}
}
return V_12 ;
}
static void F_21 ( struct V_1 * V_2 , struct V_63 V_69 )
{
if ( V_69 . V_65 == V_70 ) {
unsigned char V_32 =
( ( V_69 . V_68 << 5 ) & 0x20 ) | ( V_69 . V_67 & 0x1f ) ;
F_2 ( V_2 , & V_32 , 1 ) ;
} else {
unsigned char V_32 [ 6 ] ;
int V_72 = 0 ;
if ( V_69 . V_68 >= ( 1L << 30 ) ) {
V_32 [ V_72 ] = 0x80 | ( ( V_69 . V_68 >> 30 ) & 0x03 ) ;
V_72 ++ ;
}
if ( V_69 . V_68 >= ( 1L << 23 ) ) {
V_32 [ V_72 ] = 0x80 | ( ( V_69 . V_68 >> 23 ) & 0x7f ) ;
V_72 ++ ;
}
if ( V_69 . V_68 >= ( 1L << 16 ) ) {
V_32 [ V_72 ] = 0x80 | ( ( V_69 . V_68 >> 16 ) & 0x7f ) ;
V_72 ++ ;
}
if ( V_69 . V_68 >= ( 1L << 9 ) ) {
V_32 [ V_72 ] = 0x80 | ( ( V_69 . V_68 >> 9 ) & 0x7f ) ;
V_72 ++ ;
}
V_32 [ V_72 ] = 0x80 | ( ( V_69 . V_68 >> 2 ) & 0x7f ) ;
V_72 ++ ;
V_32 [ V_72 ] = ( ( V_69 . V_68 << 5 ) & 0x60 ) | ( V_69 . V_67 & 0x1f ) ;
V_72 ++ ;
F_2 ( V_2 , V_32 , V_72 ) ;
}
}
static int F_22 ( struct V_73 * V_74 ,
struct V_75 * V_76 ,
struct V_77 * V_78 ,
unsigned char * V_79 ,
int V_65 )
{
const struct V_80 * * V_81 = NULL ;
unsigned int * V_82 ;
int V_83 , V_84 ;
for ( V_84 = 0 , V_83 = 0 ; V_83 < 32 ; V_83 ++ ) {
if ( V_76 [ V_83 ] . V_65 == V_65 )
V_84 ++ ;
}
V_74 -> V_85 = V_84 ;
V_74 -> V_86 = 0 ;
F_23 ( V_74 -> V_82 ) ;
V_82 = F_24 ( V_74 -> V_85 , sizeof( unsigned int ) ,
V_87 ) ;
if ( ! V_82 )
return - V_88 ;
V_74 -> V_82 = V_82 ;
F_23 ( V_74 -> V_81 ) ;
V_74 -> V_89 = NULL ;
V_74 -> V_81 = NULL ;
if ( V_65 == 1 || V_65 == 2 ) {
V_74 -> V_89 = & V_90 ;
} else if ( V_78 ) {
V_81 = F_24 ( V_74 -> V_85 , sizeof( * V_78 ) ,
V_87 ) ;
if ( ! V_81 )
return - V_88 ;
V_74 -> V_81 = V_81 ;
}
for ( V_84 = 0 , V_83 = 0 ; V_83 < 32 ; V_83 ++ ) {
if ( V_76 [ V_83 ] . V_65 == V_65 ) {
if ( V_79 )
V_79 [ V_84 ] = V_83 ;
if ( V_78 && V_81 ) {
V_78 [ V_83 ] . V_64 = 1 ;
V_78 [ V_83 ] . V_78 . V_91 = V_76 [ V_83 ] . V_91 ;
V_78 [ V_83 ] . V_78 . V_92 = V_76 [ V_83 ] . V_92 ;
V_81 [ V_84 ] =
( const struct V_80 * ) & V_78 [ V_83 ] ;
}
if ( V_76 [ V_83 ] . V_93 < 32 )
V_82 [ V_84 ] = ( 1u << V_76 [ V_83 ] . V_93 ) - 1 ;
else
V_82 [ V_84 ] = 0xffffffff ;
V_84 ++ ;
}
}
return 0 ;
}
static int F_25 ( struct V_94 * V_95 )
{
struct V_96 * V_97 = V_95 -> V_98 ;
struct V_75 * V_99 ;
struct V_75 * V_100 ;
struct V_75 * V_101 ;
struct V_75 * V_102 ;
struct V_75 * V_76 ;
struct V_73 * V_74 ;
int V_12 = 0 ;
int V_72 ;
V_99 = F_26 ( 32 , sizeof( * V_76 ) , V_87 ) ;
V_100 = F_26 ( 32 , sizeof( * V_76 ) , V_87 ) ;
V_101 = F_26 ( 32 , sizeof( * V_76 ) , V_87 ) ;
V_102 = F_26 ( 32 , sizeof( * V_76 ) , V_87 ) ;
if ( ! V_99 || ! V_100 || ! V_101 || ! V_102 ) {
V_12 = - V_88 ;
goto V_103;
}
F_17 ( V_97 -> V_104 , V_97 -> V_34 ) ;
F_19 ( V_97 -> V_104 , 31 ) ;
while ( 1 ) {
struct V_63 V_69 = F_20 ( V_97 -> V_104 , 1000 ) ;
int V_65 = F_27 ( V_69 . V_68 ) ;
int V_61 = F_28 ( V_69 . V_68 ) ;
int V_78 = F_29 ( V_69 . V_68 ) ;
int V_62 = F_30 ( V_69 . V_68 ) ;
if ( V_69 . V_65 != V_71 || V_69 . V_67 != 31 ||
V_65 == V_105 )
break;
switch ( V_65 ) {
case V_106 :
V_76 = V_99 ;
break;
case V_107 :
V_76 = V_100 ;
break;
case V_108 :
V_76 = V_101 ;
break;
case V_109 :
V_76 = V_102 ;
break;
case V_110 :
V_76 = V_101 ;
break;
default:
V_76 = NULL ;
break;
}
if ( ! V_76 )
continue;
V_76 [ V_61 ] . V_65 = V_65 ;
switch ( V_62 ) {
case V_111 :
V_76 [ V_61 ] . V_93 = F_31 ( V_69 . V_68 ) ;
break;
case V_112 :
case V_113 :
switch ( F_32 ( V_69 . V_68 ) ) {
case 0 :
V_78 *= 1000000 ;
break;
case 1 :
V_78 *= 1000 ;
break;
case 2 :
V_78 *= 1 ;
break;
}
if ( F_33 ( V_69 . V_68 ) )
V_78 = - V_78 ;
if ( V_62 == V_112 )
V_76 [ V_61 ] . V_91 = V_78 ;
else
V_76 [ V_61 ] . V_92 = V_78 ;
break;
}
}
for ( V_72 = 0 ; V_72 <= 4 ; V_72 ++ ) {
unsigned char * V_79 = NULL ;
struct V_77 * V_78 = NULL ;
int V_65 = 0 ;
V_74 = & V_95 -> V_114 [ V_72 ] ;
switch ( V_72 ) {
case 0 :
V_76 = V_99 ;
V_79 = V_97 -> V_115 ;
V_65 = V_106 ;
break;
case 1 :
V_76 = V_100 ;
V_79 = V_97 -> V_116 ;
V_65 = V_107 ;
break;
case 2 :
V_76 = V_101 ;
V_79 = V_97 -> V_117 ;
V_78 = V_97 -> V_118 ;
V_65 = V_108 ;
break;
case 3 :
V_76 = V_102 ;
V_79 = V_97 -> V_119 ;
V_78 = V_97 -> V_120 ;
V_65 = V_109 ;
break;
case 4 :
V_76 = V_101 ;
V_79 = V_97 -> V_121 ;
V_78 = V_97 -> V_118 ;
V_65 = V_110 ;
break;
}
if ( F_22 ( V_74 , V_76 , V_78 , V_79 , V_65 ) )
break;
}
if ( V_72 <= 4 ) {
V_12 = - V_88 ;
for ( V_72 = 0 ; V_72 <= 4 ; V_72 ++ ) {
V_74 = & V_95 -> V_114 [ V_72 ] ;
F_23 ( V_74 -> V_82 ) ;
V_74 -> V_82 = NULL ;
F_23 ( V_74 -> V_81 ) ;
V_74 -> V_81 = NULL ;
}
}
V_103:
F_23 ( V_99 ) ;
F_23 ( V_100 ) ;
F_23 ( V_101 ) ;
F_23 ( V_102 ) ;
if ( V_12 ) {
if ( V_97 -> V_104 ) {
F_34 ( V_97 -> V_104 , NULL ) ;
V_97 -> V_104 = NULL ;
}
}
return V_12 ;
}
static int F_35 ( struct V_94 * V_95 )
{
struct V_96 * V_97 = V_95 -> V_98 ;
int V_12 ;
char V_122 [ 20 ] ;
sprintf ( V_122 , L_1 , V_97 -> V_122 ) ;
V_97 -> V_104 = F_36 ( V_122 , V_123 , 0 ) ;
if ( F_14 ( V_97 -> V_104 ) ) {
V_12 = ( int ) F_37 ( V_97 -> V_104 ) ;
F_38 ( V_95 -> V_124 , L_2 , V_12 ) ;
} else {
V_12 = F_25 ( V_95 ) ;
}
return V_12 ;
}
static void F_39 ( struct V_94 * V_95 )
{
struct V_96 * V_97 = V_95 -> V_98 ;
if ( ! F_14 ( V_97 -> V_104 ) && V_97 -> V_104 )
F_34 ( V_97 -> V_104 , NULL ) ;
}
static int F_40 ( struct V_94 * V_95 ,
struct V_73 * V_74 ,
struct V_125 * V_126 ,
unsigned int * V_69 )
{
struct V_96 * V_97 = V_95 -> V_98 ;
int V_127 ;
int V_84 ;
V_84 = V_97 -> V_115 [ F_41 ( V_126 -> V_128 ) ] ;
for ( V_127 = 0 ; V_127 < V_126 -> V_127 ; V_127 ++ ) {
struct V_63 V_129 ;
F_18 ( V_97 -> V_104 , V_84 ) ;
while ( 1 ) {
V_129 = F_20 ( V_97 -> V_104 , 1000 ) ;
if ( V_129 . V_65 != V_70 || V_129 . V_67 == V_84 )
break;
}
V_69 [ V_127 ] = V_129 . V_68 ;
}
return V_127 ;
}
static int F_42 ( struct V_94 * V_95 ,
struct V_73 * V_74 ,
struct V_125 * V_126 ,
unsigned int * V_69 )
{
struct V_96 * V_97 = V_95 -> V_98 ;
int V_127 ;
int V_84 ;
V_84 = V_97 -> V_116 [ F_41 ( V_126 -> V_128 ) ] ;
for ( V_127 = 0 ; V_127 < V_126 -> V_127 ; V_127 ++ ) {
struct V_63 V_130 ;
V_130 . V_65 = V_70 ;
V_130 . V_67 = V_84 ;
V_130 . V_68 = V_69 [ V_127 ] ;
F_21 ( V_97 -> V_104 , V_130 ) ;
}
return V_127 ;
}
static int F_43 ( struct V_94 * V_95 ,
struct V_73 * V_74 ,
struct V_125 * V_126 ,
unsigned int * V_69 )
{
struct V_96 * V_97 = V_95 -> V_98 ;
int V_127 ;
int V_84 ;
V_84 = V_97 -> V_117 [ F_41 ( V_126 -> V_128 ) ] ;
for ( V_127 = 0 ; V_127 < V_126 -> V_127 ; V_127 ++ ) {
struct V_63 V_129 ;
F_19 ( V_97 -> V_104 , V_84 ) ;
while ( 1 ) {
V_129 = F_20 ( V_97 -> V_104 , 1000 ) ;
if ( V_129 . V_65 != V_71 || V_129 . V_67 == V_84 )
break;
}
V_69 [ V_127 ] = V_129 . V_68 ;
}
return V_127 ;
}
static int F_44 ( struct V_94 * V_95 ,
struct V_73 * V_74 ,
struct V_125 * V_126 ,
unsigned int * V_69 )
{
struct V_96 * V_97 = V_95 -> V_98 ;
int V_127 ;
int V_84 ;
V_84 = V_97 -> V_119 [ F_41 ( V_126 -> V_128 ) ] ;
for ( V_127 = 0 ; V_127 < V_126 -> V_127 ; V_127 ++ ) {
struct V_63 V_130 ;
V_130 . V_65 = V_71 ;
V_130 . V_67 = V_84 ;
V_130 . V_68 = V_69 [ V_127 ] ;
F_21 ( V_97 -> V_104 , V_130 ) ;
V_97 -> V_131 [ V_84 ] = V_69 [ V_127 ] ;
}
return V_127 ;
}
static int F_45 ( struct V_94 * V_95 ,
struct V_73 * V_74 ,
struct V_125 * V_126 ,
unsigned int * V_69 )
{
struct V_96 * V_97 = V_95 -> V_98 ;
int V_127 ;
int V_84 = F_41 ( V_126 -> V_128 ) ;
for ( V_127 = 0 ; V_127 < V_126 -> V_127 ; V_127 ++ )
V_69 [ V_127 ] = V_97 -> V_131 [ V_84 ] ;
return V_127 ;
}
static int F_46 ( struct V_94 * V_95 ,
struct V_73 * V_74 ,
struct V_125 * V_126 ,
unsigned int * V_69 )
{
struct V_96 * V_97 = V_95 -> V_98 ;
int V_127 ;
int V_84 ;
V_84 = V_97 -> V_121 [ F_41 ( V_126 -> V_128 ) ] ;
for ( V_127 = 0 ; V_127 < V_126 -> V_127 ; V_127 ++ ) {
struct V_63 V_129 ;
F_19 ( V_97 -> V_104 , V_84 ) ;
while ( 1 ) {
V_129 = F_20 ( V_97 -> V_104 , 1000 ) ;
if ( V_129 . V_65 != V_71 || V_129 . V_67 == V_84 )
break;
}
V_69 [ V_127 ] = V_129 . V_68 ;
}
return V_127 ;
}
static int F_47 ( struct V_94 * V_95 ,
struct V_132 * V_133 )
{
struct V_96 * V_97 ;
struct V_73 * V_74 ;
int V_134 ;
V_97 = F_48 ( V_95 , sizeof( * V_97 ) ) ;
if ( ! V_97 )
return - V_88 ;
V_97 -> V_122 = V_133 -> V_135 [ 0 ] ;
V_97 -> V_34 = V_133 -> V_135 [ 1 ] ;
V_134 = F_49 ( V_95 , 5 ) ;
if ( V_134 )
return V_134 ;
V_74 = & V_95 -> V_114 [ 0 ] ;
V_74 -> type = V_136 ;
V_74 -> V_137 = V_138 ;
V_74 -> V_85 = 0 ;
V_74 -> V_86 = 1 ;
V_74 -> V_89 = & V_90 ;
V_74 -> V_139 = F_40 ;
V_74 = & V_95 -> V_114 [ 1 ] ;
V_74 -> type = V_140 ;
V_74 -> V_137 = V_141 ;
V_74 -> V_85 = 0 ;
V_74 -> V_86 = 1 ;
V_74 -> V_89 = & V_90 ;
V_74 -> V_142 = F_42 ;
V_74 = & V_95 -> V_114 [ 2 ] ;
V_74 -> type = V_143 ;
V_74 -> V_137 = V_138 | V_144 ;
V_74 -> V_85 = 0 ;
V_74 -> V_86 = 1 ;
V_74 -> V_89 = NULL ;
V_74 -> V_139 = F_43 ;
V_74 = & V_95 -> V_114 [ 3 ] ;
V_74 -> type = V_145 ;
V_74 -> V_137 = V_141 ;
V_74 -> V_85 = 0 ;
V_74 -> V_86 = 1 ;
V_74 -> V_89 = NULL ;
V_74 -> V_142 = F_44 ;
V_74 -> V_139 = F_45 ;
V_74 = & V_95 -> V_114 [ 4 ] ;
V_74 -> type = V_146 ;
V_74 -> V_137 = V_138 | V_147 ;
V_74 -> V_85 = 0 ;
V_74 -> V_86 = 1 ;
V_74 -> V_89 = NULL ;
V_74 -> V_139 = F_46 ;
V_95 -> V_148 = F_35 ;
V_95 -> V_149 = F_39 ;
return 0 ;
}
static void F_50 ( struct V_94 * V_95 )
{
struct V_73 * V_74 ;
int V_72 ;
for ( V_72 = 0 ; V_72 < V_95 -> V_150 ; V_72 ++ ) {
V_74 = & V_95 -> V_114 [ V_72 ] ;
F_23 ( V_74 -> V_82 ) ;
F_23 ( V_74 -> V_81 ) ;
}
}

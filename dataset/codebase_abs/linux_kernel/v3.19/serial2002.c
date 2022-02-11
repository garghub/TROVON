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
T_2 V_13 ;
V_13 = F_3 () ;
F_4 ( V_14 ) ;
V_2 -> V_15 = 0 ;
V_12 = V_2 -> V_5 -> V_16 ( V_2 , V_10 , V_9 , & V_2 -> V_15 ) ;
F_4 ( V_13 ) ;
return V_12 ;
}
static int F_5 ( struct V_1 * V_2 , unsigned char * V_8 )
{
char T_1 * V_10 = ( V_11 char T_1 * ) V_8 ;
V_2 -> V_15 = 0 ;
return V_2 -> V_5 -> V_17 ( V_2 , V_10 , 1 , & V_2 -> V_15 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_18 )
{
struct V_19 V_20 ;
struct V_21 V_22 , V_23 ;
F_7 ( & V_22 ) ;
F_8 ( & V_20 ) ;
while ( 1 ) {
long V_24 ;
int V_25 ;
V_25 = V_2 -> V_5 -> V_26 ( V_2 , & V_20 . V_27 ) ;
if ( V_25 & ( V_28 | V_29 | V_30 |
V_31 | V_32 ) ) {
break;
}
F_7 ( & V_23 ) ;
V_24 = ( 1000000 * ( V_23 . V_33 - V_22 . V_33 ) +
V_23 . V_34 - V_22 . V_34 ) ;
if ( V_24 > V_18 )
break;
F_9 ( V_35 ) ;
F_10 ( ( ( V_18 - V_24 ) * V_36 ) / 10000 ) ;
}
F_11 ( & V_20 ) ;
}
static int F_12 ( struct V_1 * V_2 , int V_18 )
{
unsigned char V_37 ;
int V_12 ;
V_12 = - 1 ;
if ( ! F_13 ( V_2 ) ) {
T_2 V_13 ;
V_13 = F_3 () ;
F_4 ( V_14 ) ;
if ( V_2 -> V_5 -> V_26 ) {
F_6 ( V_2 , V_18 ) ;
if ( F_5 ( V_2 , & V_37 ) == 1 )
V_12 = V_37 ;
} else {
int V_38 = 0 ;
while ( 1 ) {
V_38 ++ ;
if ( V_38 >= V_18 )
break;
if ( F_5 ( V_2 , & V_37 ) == 1 ) {
V_12 = V_37 ;
break;
}
F_14 ( 100 ) ;
}
}
F_4 ( V_13 ) ;
}
return V_12 ;
}
static void F_15 ( struct V_1 * V_2 , int V_39 )
{
struct V_40 V_40 ;
struct V_41 V_42 ;
T_2 V_13 ;
V_13 = F_3 () ;
F_4 ( V_14 ) ;
F_1 ( V_2 , V_43 , ( unsigned long ) & V_40 ) ;
V_40 . V_44 = 0 ;
V_40 . V_45 = 0 ;
V_40 . V_46 = 0 ;
V_40 . V_47 = V_48 | V_49 | V_50 ;
V_40 . V_51 [ V_52 ] = 0 ;
V_40 . V_51 [ V_53 ] = 0 ;
switch ( V_39 ) {
case 2400 :
V_40 . V_47 |= V_54 ;
break;
case 4800 :
V_40 . V_47 |= V_55 ;
break;
case 9600 :
V_40 . V_47 |= V_56 ;
break;
case 19200 :
V_40 . V_47 |= V_57 ;
break;
case 38400 :
V_40 . V_47 |= V_58 ;
break;
case 57600 :
V_40 . V_47 |= V_59 ;
break;
case 115200 :
V_40 . V_47 |= V_60 ;
break;
default:
V_40 . V_47 |= V_56 ;
break;
}
F_1 ( V_2 , V_61 , ( unsigned long ) & V_40 ) ;
F_1 ( V_2 , V_62 , ( unsigned long ) & V_42 ) ;
V_42 . V_63 |= V_64 ;
F_1 ( V_2 , V_65 , ( unsigned long ) & V_42 ) ;
F_4 ( V_13 ) ;
}
static void F_16 ( struct V_1 * V_2 , int V_66 )
{
char V_67 ;
V_67 = 0x40 | ( V_66 & 0x1f ) ;
F_2 ( V_2 , & V_67 , 1 ) ;
}
static void F_17 ( struct V_1 * V_2 , int V_66 )
{
char V_67 ;
V_67 = 0x60 | ( V_66 & 0x1f ) ;
F_2 ( V_2 , & V_67 , 1 ) ;
}
static struct V_68 F_18 ( struct V_1 * V_2 , int V_18 )
{
struct V_68 V_12 ;
int V_69 ;
V_12 . V_70 = V_71 ;
V_12 . V_72 = 0 ;
V_12 . V_73 = 0 ;
V_69 = 0 ;
while ( 1 ) {
int V_74 = F_12 ( V_2 , V_18 ) ;
V_69 ++ ;
if ( V_74 < 0 ) {
break;
} else if ( V_74 & 0x80 ) {
V_12 . V_73 = ( V_12 . V_73 << 7 ) | ( V_74 & 0x7f ) ;
} else {
if ( V_69 == 1 ) {
switch ( ( V_74 >> 5 ) & 0x03 ) {
case 0 :
V_12 . V_73 = 0 ;
V_12 . V_70 = V_75 ;
break;
case 1 :
V_12 . V_73 = 1 ;
V_12 . V_70 = V_75 ;
break;
}
} else {
V_12 . V_73 =
( V_12 . V_73 << 2 ) | ( ( V_74 & 0x60 ) >> 5 ) ;
V_12 . V_70 = V_76 ;
}
V_12 . V_72 = V_74 & 0x1f ;
break;
}
}
return V_12 ;
}
static void F_19 ( struct V_1 * V_2 , struct V_68 V_74 )
{
if ( V_74 . V_70 == V_75 ) {
unsigned char V_37 =
( ( V_74 . V_73 << 5 ) & 0x20 ) | ( V_74 . V_72 & 0x1f ) ;
F_2 ( V_2 , & V_37 , 1 ) ;
} else {
unsigned char V_37 [ 6 ] ;
int V_77 = 0 ;
if ( V_74 . V_73 >= ( 1L << 30 ) ) {
V_37 [ V_77 ] = 0x80 | ( ( V_74 . V_73 >> 30 ) & 0x03 ) ;
V_77 ++ ;
}
if ( V_74 . V_73 >= ( 1L << 23 ) ) {
V_37 [ V_77 ] = 0x80 | ( ( V_74 . V_73 >> 23 ) & 0x7f ) ;
V_77 ++ ;
}
if ( V_74 . V_73 >= ( 1L << 16 ) ) {
V_37 [ V_77 ] = 0x80 | ( ( V_74 . V_73 >> 16 ) & 0x7f ) ;
V_77 ++ ;
}
if ( V_74 . V_73 >= ( 1L << 9 ) ) {
V_37 [ V_77 ] = 0x80 | ( ( V_74 . V_73 >> 9 ) & 0x7f ) ;
V_77 ++ ;
}
V_37 [ V_77 ] = 0x80 | ( ( V_74 . V_73 >> 2 ) & 0x7f ) ;
V_77 ++ ;
V_37 [ V_77 ] = ( ( V_74 . V_73 << 5 ) & 0x60 ) | ( V_74 . V_72 & 0x1f ) ;
V_77 ++ ;
F_2 ( V_2 , V_37 , V_77 ) ;
}
}
static int F_20 ( struct V_78 * V_79 ,
struct V_80 * V_81 ,
struct V_82 * V_83 ,
unsigned char * V_84 ,
int V_70 )
{
const struct V_85 * * V_86 = NULL ;
unsigned int * V_87 ;
int V_88 , V_89 ;
for ( V_89 = 0 , V_88 = 0 ; V_88 < 32 ; V_88 ++ ) {
if ( V_81 [ V_88 ] . V_70 == V_70 )
V_89 ++ ;
}
V_79 -> V_90 = V_89 ;
V_79 -> V_91 = 0 ;
F_21 ( V_79 -> V_87 ) ;
V_87 = F_22 ( V_79 -> V_90 , sizeof( unsigned int ) ,
V_92 ) ;
if ( ! V_87 )
return - V_93 ;
V_79 -> V_87 = V_87 ;
F_21 ( V_79 -> V_86 ) ;
V_79 -> V_94 = NULL ;
V_79 -> V_86 = NULL ;
if ( V_70 == 1 || V_70 == 2 ) {
V_79 -> V_94 = & V_95 ;
} else if ( V_83 ) {
V_86 = F_22 ( V_79 -> V_90 , sizeof( * V_83 ) ,
V_92 ) ;
if ( ! V_86 )
return - V_93 ;
V_79 -> V_86 = V_86 ;
}
for ( V_89 = 0 , V_88 = 0 ; V_88 < 32 ; V_88 ++ ) {
if ( V_81 [ V_88 ] . V_70 == V_70 ) {
if ( V_84 )
V_84 [ V_89 ] = V_88 ;
if ( V_83 ) {
V_83 [ V_88 ] . V_69 = 1 ;
V_83 [ V_88 ] . V_83 . V_96 = V_81 [ V_88 ] . V_96 ;
V_83 [ V_88 ] . V_83 . V_97 = V_81 [ V_88 ] . V_97 ;
V_86 [ V_89 ] =
( const struct V_85 * ) & V_83 [ V_88 ] ;
}
V_87 [ V_89 ] = ( ( long long ) 1 << V_81 [ V_88 ] . V_98 ) - 1 ;
V_89 ++ ;
}
}
return 0 ;
}
static int F_23 ( struct V_99 * V_100 )
{
struct V_101 * V_102 = V_100 -> V_103 ;
struct V_80 * V_104 ;
struct V_80 * V_105 ;
struct V_80 * V_106 ;
struct V_80 * V_107 ;
struct V_80 * V_81 ;
struct V_78 * V_79 ;
int V_12 = 0 ;
int V_77 ;
V_104 = F_24 ( 32 , sizeof( * V_81 ) , V_92 ) ;
V_105 = F_24 ( 32 , sizeof( * V_81 ) , V_92 ) ;
V_106 = F_24 ( 32 , sizeof( * V_81 ) , V_92 ) ;
V_107 = F_24 ( 32 , sizeof( * V_81 ) , V_92 ) ;
if ( ! V_104 || ! V_105 || ! V_106 || ! V_107 ) {
V_12 = - V_93 ;
goto V_108;
}
F_15 ( V_102 -> V_109 , V_102 -> V_39 ) ;
F_17 ( V_102 -> V_109 , 31 ) ;
while ( 1 ) {
struct V_68 V_74 = F_18 ( V_102 -> V_109 , 1000 ) ;
int V_70 = F_25 ( V_74 . V_73 ) ;
int V_66 = F_26 ( V_74 . V_73 ) ;
int V_83 = F_27 ( V_74 . V_73 ) ;
int V_67 = F_28 ( V_74 . V_73 ) ;
if ( V_74 . V_70 != V_76 || V_74 . V_72 != 31 ||
V_70 == V_110 )
break;
switch ( V_70 ) {
case V_111 :
V_81 = V_104 ;
break;
case V_112 :
V_81 = V_105 ;
break;
case V_113 :
V_81 = V_106 ;
break;
case V_114 :
V_81 = V_107 ;
break;
case V_115 :
V_81 = V_106 ;
break;
default:
V_81 = NULL ;
break;
}
if ( ! V_81 )
continue;
V_81 [ V_66 ] . V_70 = V_70 ;
switch ( V_67 ) {
case V_116 :
V_81 [ V_66 ] . V_98 = F_29 ( V_74 . V_73 ) ;
break;
case V_117 :
case V_118 :
switch ( F_30 ( V_74 . V_73 ) ) {
case 0 :
V_83 *= 1000000 ;
break;
case 1 :
V_83 *= 1000 ;
break;
case 2 :
V_83 *= 1 ;
break;
}
if ( F_31 ( V_74 . V_73 ) )
V_83 = - V_83 ;
if ( V_67 == V_117 )
V_81 [ V_66 ] . V_96 = V_83 ;
else
V_81 [ V_66 ] . V_97 = V_83 ;
break;
}
}
for ( V_77 = 0 ; V_77 <= 4 ; V_77 ++ ) {
unsigned char * V_84 = NULL ;
struct V_82 * V_83 = NULL ;
int V_70 = 0 ;
V_79 = & V_100 -> V_119 [ V_77 ] ;
switch ( V_77 ) {
case 0 :
V_81 = V_104 ;
V_84 = V_102 -> V_120 ;
V_70 = V_111 ;
break;
case 1 :
V_81 = V_105 ;
V_84 = V_102 -> V_121 ;
V_70 = V_112 ;
break;
case 2 :
V_81 = V_106 ;
V_84 = V_102 -> V_122 ;
V_83 = V_102 -> V_123 ;
V_70 = V_113 ;
break;
case 3 :
V_81 = V_107 ;
V_84 = V_102 -> V_124 ;
V_83 = V_102 -> V_125 ;
V_70 = V_114 ;
break;
case 4 :
V_81 = V_106 ;
V_84 = V_102 -> V_126 ;
V_83 = V_102 -> V_123 ;
V_70 = V_115 ;
break;
}
if ( F_20 ( V_79 , V_81 , V_83 , V_84 , V_70 ) )
break;
}
if ( V_77 <= 4 ) {
V_12 = - V_93 ;
for ( V_77 = 0 ; V_77 <= 4 ; V_77 ++ ) {
V_79 = & V_100 -> V_119 [ V_77 ] ;
F_21 ( V_79 -> V_87 ) ;
V_79 -> V_87 = NULL ;
F_21 ( V_79 -> V_86 ) ;
V_79 -> V_86 = NULL ;
}
}
V_108:
F_21 ( V_104 ) ;
F_21 ( V_105 ) ;
F_21 ( V_106 ) ;
F_21 ( V_107 ) ;
if ( V_12 ) {
if ( V_102 -> V_109 ) {
F_32 ( V_102 -> V_109 , NULL ) ;
V_102 -> V_109 = NULL ;
}
}
return V_12 ;
}
static int F_33 ( struct V_99 * V_100 )
{
struct V_101 * V_102 = V_100 -> V_103 ;
int V_12 ;
char V_127 [ 20 ] ;
sprintf ( V_127 , L_1 , V_102 -> V_127 ) ;
V_102 -> V_109 = F_34 ( V_127 , V_128 , 0 ) ;
if ( F_13 ( V_102 -> V_109 ) ) {
V_12 = ( int ) F_35 ( V_102 -> V_109 ) ;
F_36 ( V_100 -> V_129 , L_2 , V_12 ) ;
} else {
V_12 = F_23 ( V_100 ) ;
}
return V_12 ;
}
static void F_37 ( struct V_99 * V_100 )
{
struct V_101 * V_102 = V_100 -> V_103 ;
if ( ! F_13 ( V_102 -> V_109 ) && V_102 -> V_109 )
F_32 ( V_102 -> V_109 , NULL ) ;
}
static int F_38 ( struct V_99 * V_100 ,
struct V_78 * V_79 ,
struct V_130 * V_131 ,
unsigned int * V_74 )
{
struct V_101 * V_102 = V_100 -> V_103 ;
int V_132 ;
int V_89 ;
V_89 = V_102 -> V_120 [ F_39 ( V_131 -> V_133 ) ] ;
for ( V_132 = 0 ; V_132 < V_131 -> V_132 ; V_132 ++ ) {
struct V_68 V_17 ;
F_16 ( V_102 -> V_109 , V_89 ) ;
while ( 1 ) {
V_17 = F_18 ( V_102 -> V_109 , 1000 ) ;
if ( V_17 . V_70 != V_75 || V_17 . V_72 == V_89 )
break;
}
V_74 [ V_132 ] = V_17 . V_73 ;
}
return V_132 ;
}
static int F_40 ( struct V_99 * V_100 ,
struct V_78 * V_79 ,
struct V_130 * V_131 ,
unsigned int * V_74 )
{
struct V_101 * V_102 = V_100 -> V_103 ;
int V_132 ;
int V_89 ;
V_89 = V_102 -> V_121 [ F_39 ( V_131 -> V_133 ) ] ;
for ( V_132 = 0 ; V_132 < V_131 -> V_132 ; V_132 ++ ) {
struct V_68 V_16 ;
V_16 . V_70 = V_75 ;
V_16 . V_72 = V_89 ;
V_16 . V_73 = V_74 [ V_132 ] ;
F_19 ( V_102 -> V_109 , V_16 ) ;
}
return V_132 ;
}
static int F_41 ( struct V_99 * V_100 ,
struct V_78 * V_79 ,
struct V_130 * V_131 ,
unsigned int * V_74 )
{
struct V_101 * V_102 = V_100 -> V_103 ;
int V_132 ;
int V_89 ;
V_89 = V_102 -> V_122 [ F_39 ( V_131 -> V_133 ) ] ;
for ( V_132 = 0 ; V_132 < V_131 -> V_132 ; V_132 ++ ) {
struct V_68 V_17 ;
F_17 ( V_102 -> V_109 , V_89 ) ;
while ( 1 ) {
V_17 = F_18 ( V_102 -> V_109 , 1000 ) ;
if ( V_17 . V_70 != V_76 || V_17 . V_72 == V_89 )
break;
}
V_74 [ V_132 ] = V_17 . V_73 ;
}
return V_132 ;
}
static int F_42 ( struct V_99 * V_100 ,
struct V_78 * V_79 ,
struct V_130 * V_131 ,
unsigned int * V_74 )
{
struct V_101 * V_102 = V_100 -> V_103 ;
int V_132 ;
int V_89 ;
V_89 = V_102 -> V_124 [ F_39 ( V_131 -> V_133 ) ] ;
for ( V_132 = 0 ; V_132 < V_131 -> V_132 ; V_132 ++ ) {
struct V_68 V_16 ;
V_16 . V_70 = V_76 ;
V_16 . V_72 = V_89 ;
V_16 . V_73 = V_74 [ V_132 ] ;
F_19 ( V_102 -> V_109 , V_16 ) ;
V_102 -> V_134 [ V_89 ] = V_74 [ V_132 ] ;
}
return V_132 ;
}
static int F_43 ( struct V_99 * V_100 ,
struct V_78 * V_79 ,
struct V_130 * V_131 ,
unsigned int * V_74 )
{
struct V_101 * V_102 = V_100 -> V_103 ;
int V_132 ;
int V_89 = F_39 ( V_131 -> V_133 ) ;
for ( V_132 = 0 ; V_132 < V_131 -> V_132 ; V_132 ++ )
V_74 [ V_132 ] = V_102 -> V_134 [ V_89 ] ;
return V_132 ;
}
static int F_44 ( struct V_99 * V_100 ,
struct V_78 * V_79 ,
struct V_130 * V_131 ,
unsigned int * V_74 )
{
struct V_101 * V_102 = V_100 -> V_103 ;
int V_132 ;
int V_89 ;
V_89 = V_102 -> V_126 [ F_39 ( V_131 -> V_133 ) ] ;
for ( V_132 = 0 ; V_132 < V_131 -> V_132 ; V_132 ++ ) {
struct V_68 V_17 ;
F_17 ( V_102 -> V_109 , V_89 ) ;
while ( 1 ) {
V_17 = F_18 ( V_102 -> V_109 , 1000 ) ;
if ( V_17 . V_70 != V_76 || V_17 . V_72 == V_89 )
break;
}
V_74 [ V_132 ] = V_17 . V_73 ;
}
return V_132 ;
}
static int F_45 ( struct V_99 * V_100 ,
struct V_135 * V_136 )
{
struct V_101 * V_102 ;
struct V_78 * V_79 ;
int V_137 ;
V_102 = F_46 ( V_100 , sizeof( * V_102 ) ) ;
if ( ! V_102 )
return - V_93 ;
V_102 -> V_127 = V_136 -> V_138 [ 0 ] ;
V_102 -> V_39 = V_136 -> V_138 [ 1 ] ;
V_137 = F_47 ( V_100 , 5 ) ;
if ( V_137 )
return V_137 ;
V_79 = & V_100 -> V_119 [ 0 ] ;
V_79 -> type = V_139 ;
V_79 -> V_140 = V_141 ;
V_79 -> V_90 = 0 ;
V_79 -> V_91 = 1 ;
V_79 -> V_94 = & V_95 ;
V_79 -> V_142 = F_38 ;
V_79 = & V_100 -> V_119 [ 1 ] ;
V_79 -> type = V_143 ;
V_79 -> V_140 = V_144 ;
V_79 -> V_90 = 0 ;
V_79 -> V_91 = 1 ;
V_79 -> V_94 = & V_95 ;
V_79 -> V_145 = F_40 ;
V_79 = & V_100 -> V_119 [ 2 ] ;
V_79 -> type = V_146 ;
V_79 -> V_140 = V_141 | V_147 ;
V_79 -> V_90 = 0 ;
V_79 -> V_91 = 1 ;
V_79 -> V_94 = NULL ;
V_79 -> V_142 = F_41 ;
V_79 = & V_100 -> V_119 [ 3 ] ;
V_79 -> type = V_148 ;
V_79 -> V_140 = V_144 ;
V_79 -> V_90 = 0 ;
V_79 -> V_91 = 1 ;
V_79 -> V_94 = NULL ;
V_79 -> V_145 = F_42 ;
V_79 -> V_142 = F_43 ;
V_79 = & V_100 -> V_119 [ 4 ] ;
V_79 -> type = V_149 ;
V_79 -> V_140 = V_141 | V_150 ;
V_79 -> V_90 = 0 ;
V_79 -> V_91 = 1 ;
V_79 -> V_94 = NULL ;
V_79 -> V_142 = F_44 ;
V_100 -> V_151 = F_33 ;
V_100 -> V_152 = F_37 ;
return 0 ;
}
static void F_48 ( struct V_99 * V_100 )
{
struct V_78 * V_79 ;
int V_77 ;
for ( V_77 = 0 ; V_77 < V_100 -> V_153 ; V_77 ++ ) {
V_79 = & V_100 -> V_119 [ V_77 ] ;
F_21 ( V_79 -> V_87 ) ;
F_21 ( V_79 -> V_86 ) ;
}
}

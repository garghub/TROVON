static long F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned long V_4 )
{
if ( V_2 -> V_5 -> V_6 )
return V_2 -> V_5 -> V_6 ( V_2 , V_3 , V_4 ) ;
return - V_7 ;
}
static int F_2 ( struct V_1 * V_2 , unsigned char * V_8 , int V_9 )
{
T_1 V_10 = 0 ;
return F_3 ( V_2 , V_8 , V_9 , & V_10 ) ;
}
static void F_4 ( struct V_1 * V_2 , int V_11 )
{
struct V_12 V_13 ;
T_2 V_14 , V_15 ;
V_14 = F_5 () ;
F_6 ( & V_13 ) ;
while ( 1 ) {
long V_16 ;
int V_17 ;
V_17 = V_2 -> V_5 -> V_18 ( V_2 , & V_13 . V_19 ) ;
if ( V_17 & ( V_20 | V_21 | V_22 |
V_23 | V_24 ) ) {
break;
}
V_15 = F_5 () ;
V_16 = F_7 ( V_15 , V_14 ) ;
if ( V_16 > V_11 )
break;
F_8 ( V_25 ) ;
F_9 ( ( ( V_11 - V_16 ) * V_26 ) / 10000 ) ;
}
F_10 ( & V_13 ) ;
}
static int F_11 ( struct V_1 * V_2 , int V_11 )
{
unsigned char V_27 ;
int V_28 ;
T_1 V_10 = 0 ;
V_28 = - 1 ;
if ( ! F_12 ( V_2 ) ) {
if ( V_2 -> V_5 -> V_18 ) {
F_4 ( V_2 , V_11 ) ;
if ( F_13 ( V_2 , & V_27 , 1 , & V_10 ) == 1 )
V_28 = V_27 ;
} else {
int V_29 = 0 ;
while ( 1 ) {
V_29 ++ ;
if ( V_29 >= V_11 )
break;
if ( F_13 ( V_2 , & V_27 , 1 , & V_10 ) == 1 ) {
V_28 = V_27 ;
break;
}
F_14 ( 100 , 1000 ) ;
}
}
}
return V_28 ;
}
static void F_15 ( struct V_1 * V_2 , int V_30 )
{
struct V_31 V_31 ;
struct V_32 V_33 ;
T_3 V_34 ;
V_34 = F_16 () ;
F_17 ( V_35 ) ;
F_1 ( V_2 , V_36 , ( unsigned long ) & V_31 ) ;
V_31 . V_37 = 0 ;
V_31 . V_38 = 0 ;
V_31 . V_39 = 0 ;
V_31 . V_40 = V_41 | V_42 | V_43 ;
V_31 . V_44 [ V_45 ] = 0 ;
V_31 . V_44 [ V_46 ] = 0 ;
switch ( V_30 ) {
case 2400 :
V_31 . V_40 |= V_47 ;
break;
case 4800 :
V_31 . V_40 |= V_48 ;
break;
case 9600 :
V_31 . V_40 |= V_49 ;
break;
case 19200 :
V_31 . V_40 |= V_50 ;
break;
case 38400 :
V_31 . V_40 |= V_51 ;
break;
case 57600 :
V_31 . V_40 |= V_52 ;
break;
case 115200 :
V_31 . V_40 |= V_53 ;
break;
default:
V_31 . V_40 |= V_49 ;
break;
}
F_1 ( V_2 , V_54 , ( unsigned long ) & V_31 ) ;
F_1 ( V_2 , V_55 , ( unsigned long ) & V_33 ) ;
V_33 . V_56 |= V_57 ;
F_1 ( V_2 , V_58 , ( unsigned long ) & V_33 ) ;
F_17 ( V_34 ) ;
}
static void F_18 ( struct V_1 * V_2 , int V_59 )
{
char V_60 ;
V_60 = 0x40 | ( V_59 & 0x1f ) ;
F_2 ( V_2 , & V_60 , 1 ) ;
}
static void F_19 ( struct V_1 * V_2 , int V_59 )
{
char V_60 ;
V_60 = 0x60 | ( V_59 & 0x1f ) ;
F_2 ( V_2 , & V_60 , 1 ) ;
}
static struct V_61 F_20 ( struct V_1 * V_2 , int V_11 )
{
struct V_61 V_28 ;
int V_62 ;
V_28 . V_63 = V_64 ;
V_28 . V_65 = 0 ;
V_28 . V_66 = 0 ;
V_62 = 0 ;
while ( 1 ) {
int V_67 = F_11 ( V_2 , V_11 ) ;
V_62 ++ ;
if ( V_67 < 0 ) {
break;
} else if ( V_67 & 0x80 ) {
V_28 . V_66 = ( V_28 . V_66 << 7 ) | ( V_67 & 0x7f ) ;
} else {
if ( V_62 == 1 ) {
switch ( ( V_67 >> 5 ) & 0x03 ) {
case 0 :
V_28 . V_66 = 0 ;
V_28 . V_63 = V_68 ;
break;
case 1 :
V_28 . V_66 = 1 ;
V_28 . V_63 = V_68 ;
break;
}
} else {
V_28 . V_66 =
( V_28 . V_66 << 2 ) | ( ( V_67 & 0x60 ) >> 5 ) ;
V_28 . V_63 = V_69 ;
}
V_28 . V_65 = V_67 & 0x1f ;
break;
}
}
return V_28 ;
}
static void F_21 ( struct V_1 * V_2 , struct V_61 V_67 )
{
if ( V_67 . V_63 == V_68 ) {
unsigned char V_27 =
( ( V_67 . V_66 << 5 ) & 0x20 ) | ( V_67 . V_65 & 0x1f ) ;
F_2 ( V_2 , & V_27 , 1 ) ;
} else {
unsigned char V_27 [ 6 ] ;
int V_70 = 0 ;
if ( V_67 . V_66 >= ( 1L << 30 ) ) {
V_27 [ V_70 ] = 0x80 | ( ( V_67 . V_66 >> 30 ) & 0x03 ) ;
V_70 ++ ;
}
if ( V_67 . V_66 >= ( 1L << 23 ) ) {
V_27 [ V_70 ] = 0x80 | ( ( V_67 . V_66 >> 23 ) & 0x7f ) ;
V_70 ++ ;
}
if ( V_67 . V_66 >= ( 1L << 16 ) ) {
V_27 [ V_70 ] = 0x80 | ( ( V_67 . V_66 >> 16 ) & 0x7f ) ;
V_70 ++ ;
}
if ( V_67 . V_66 >= ( 1L << 9 ) ) {
V_27 [ V_70 ] = 0x80 | ( ( V_67 . V_66 >> 9 ) & 0x7f ) ;
V_70 ++ ;
}
V_27 [ V_70 ] = 0x80 | ( ( V_67 . V_66 >> 2 ) & 0x7f ) ;
V_70 ++ ;
V_27 [ V_70 ] = ( ( V_67 . V_66 << 5 ) & 0x60 ) | ( V_67 . V_65 & 0x1f ) ;
V_70 ++ ;
F_2 ( V_2 , V_27 , V_70 ) ;
}
}
static int F_22 ( struct V_71 * V_72 ,
struct V_73 * V_74 ,
struct V_75 * V_76 ,
unsigned char * V_77 ,
int V_63 )
{
const struct V_78 * * V_79 = NULL ;
unsigned int * V_80 ;
int V_81 , V_82 ;
for ( V_82 = 0 , V_81 = 0 ; V_81 < 32 ; V_81 ++ ) {
if ( V_74 [ V_81 ] . V_63 == V_63 )
V_82 ++ ;
}
V_72 -> V_83 = V_82 ;
V_72 -> V_84 = 0 ;
F_23 ( V_72 -> V_80 ) ;
V_80 = F_24 ( V_72 -> V_83 , sizeof( unsigned int ) ,
V_85 ) ;
if ( ! V_80 )
return - V_86 ;
V_72 -> V_80 = V_80 ;
F_23 ( V_72 -> V_79 ) ;
V_72 -> V_87 = NULL ;
V_72 -> V_79 = NULL ;
if ( V_63 == 1 || V_63 == 2 ) {
V_72 -> V_87 = & V_88 ;
} else if ( V_76 ) {
V_79 = F_24 ( V_72 -> V_83 , sizeof( * V_76 ) ,
V_85 ) ;
if ( ! V_79 )
return - V_86 ;
V_72 -> V_79 = V_79 ;
}
for ( V_82 = 0 , V_81 = 0 ; V_81 < 32 ; V_81 ++ ) {
if ( V_74 [ V_81 ] . V_63 == V_63 ) {
if ( V_77 )
V_77 [ V_82 ] = V_81 ;
if ( V_76 && V_79 ) {
V_76 [ V_81 ] . V_62 = 1 ;
V_76 [ V_81 ] . V_76 . V_89 = V_74 [ V_81 ] . V_89 ;
V_76 [ V_81 ] . V_76 . V_90 = V_74 [ V_81 ] . V_90 ;
V_79 [ V_82 ] =
( const struct V_78 * ) & V_76 [ V_81 ] ;
}
if ( V_74 [ V_81 ] . V_91 < 32 )
V_80 [ V_82 ] = ( 1u << V_74 [ V_81 ] . V_91 ) - 1 ;
else
V_80 [ V_82 ] = 0xffffffff ;
V_82 ++ ;
}
}
return 0 ;
}
static int F_25 ( struct V_92 * V_93 )
{
struct V_94 * V_95 = V_93 -> V_96 ;
struct V_73 * V_97 ;
struct V_73 * V_98 ;
struct V_73 * V_99 ;
struct V_73 * V_100 ;
struct V_73 * V_74 ;
struct V_71 * V_72 ;
int V_28 = 0 ;
int V_70 ;
V_97 = F_26 ( 32 , sizeof( * V_74 ) , V_85 ) ;
V_98 = F_26 ( 32 , sizeof( * V_74 ) , V_85 ) ;
V_99 = F_26 ( 32 , sizeof( * V_74 ) , V_85 ) ;
V_100 = F_26 ( 32 , sizeof( * V_74 ) , V_85 ) ;
if ( ! V_97 || ! V_98 || ! V_99 || ! V_100 ) {
V_28 = - V_86 ;
goto V_101;
}
F_15 ( V_95 -> V_102 , V_95 -> V_30 ) ;
F_19 ( V_95 -> V_102 , 31 ) ;
while ( 1 ) {
struct V_61 V_67 = F_20 ( V_95 -> V_102 , 1000 ) ;
int V_63 = F_27 ( V_67 . V_66 ) ;
int V_59 = F_28 ( V_67 . V_66 ) ;
int V_76 = F_29 ( V_67 . V_66 ) ;
int V_60 = F_30 ( V_67 . V_66 ) ;
if ( V_67 . V_63 != V_69 || V_67 . V_65 != 31 ||
V_63 == V_103 )
break;
switch ( V_63 ) {
case V_104 :
V_74 = V_97 ;
break;
case V_105 :
V_74 = V_98 ;
break;
case V_106 :
V_74 = V_99 ;
break;
case V_107 :
V_74 = V_100 ;
break;
case V_108 :
V_74 = V_99 ;
break;
default:
V_74 = NULL ;
break;
}
if ( ! V_74 )
continue;
V_74 [ V_59 ] . V_63 = V_63 ;
switch ( V_60 ) {
case V_109 :
V_74 [ V_59 ] . V_91 = F_31 ( V_67 . V_66 ) ;
break;
case V_110 :
case V_111 :
switch ( F_32 ( V_67 . V_66 ) ) {
case 0 :
V_76 *= 1000000 ;
break;
case 1 :
V_76 *= 1000 ;
break;
case 2 :
V_76 *= 1 ;
break;
}
if ( F_33 ( V_67 . V_66 ) )
V_76 = - V_76 ;
if ( V_60 == V_110 )
V_74 [ V_59 ] . V_89 = V_76 ;
else
V_74 [ V_59 ] . V_90 = V_76 ;
break;
}
}
for ( V_70 = 0 ; V_70 <= 4 ; V_70 ++ ) {
unsigned char * V_77 = NULL ;
struct V_75 * V_76 = NULL ;
int V_63 = 0 ;
V_72 = & V_93 -> V_112 [ V_70 ] ;
switch ( V_70 ) {
case 0 :
V_74 = V_97 ;
V_77 = V_95 -> V_113 ;
V_63 = V_104 ;
break;
case 1 :
V_74 = V_98 ;
V_77 = V_95 -> V_114 ;
V_63 = V_105 ;
break;
case 2 :
V_74 = V_99 ;
V_77 = V_95 -> V_115 ;
V_76 = V_95 -> V_116 ;
V_63 = V_106 ;
break;
case 3 :
V_74 = V_100 ;
V_77 = V_95 -> V_117 ;
V_76 = V_95 -> V_118 ;
V_63 = V_107 ;
break;
case 4 :
V_74 = V_99 ;
V_77 = V_95 -> V_119 ;
V_76 = V_95 -> V_116 ;
V_63 = V_108 ;
break;
}
if ( F_22 ( V_72 , V_74 , V_76 , V_77 , V_63 ) )
break;
}
if ( V_70 <= 4 ) {
V_28 = - V_86 ;
for ( V_70 = 0 ; V_70 <= 4 ; V_70 ++ ) {
V_72 = & V_93 -> V_112 [ V_70 ] ;
F_23 ( V_72 -> V_80 ) ;
V_72 -> V_80 = NULL ;
F_23 ( V_72 -> V_79 ) ;
V_72 -> V_79 = NULL ;
}
}
V_101:
F_23 ( V_97 ) ;
F_23 ( V_98 ) ;
F_23 ( V_99 ) ;
F_23 ( V_100 ) ;
if ( V_28 ) {
if ( V_95 -> V_102 ) {
F_34 ( V_95 -> V_102 , NULL ) ;
V_95 -> V_102 = NULL ;
}
}
return V_28 ;
}
static int F_35 ( struct V_92 * V_93 )
{
struct V_94 * V_95 = V_93 -> V_96 ;
int V_28 ;
char V_120 [ 20 ] ;
sprintf ( V_120 , L_1 , V_95 -> V_120 ) ;
V_95 -> V_102 = F_36 ( V_120 , V_121 , 0 ) ;
if ( F_12 ( V_95 -> V_102 ) ) {
V_28 = ( int ) F_37 ( V_95 -> V_102 ) ;
F_38 ( V_93 -> V_122 , L_2 , V_28 ) ;
} else {
V_28 = F_25 ( V_93 ) ;
}
return V_28 ;
}
static void F_39 ( struct V_92 * V_93 )
{
struct V_94 * V_95 = V_93 -> V_96 ;
if ( ! F_12 ( V_95 -> V_102 ) && V_95 -> V_102 )
F_34 ( V_95 -> V_102 , NULL ) ;
}
static int F_40 ( struct V_92 * V_93 ,
struct V_71 * V_72 ,
struct V_123 * V_124 ,
unsigned int * V_67 )
{
struct V_94 * V_95 = V_93 -> V_96 ;
int V_125 ;
int V_82 ;
V_82 = V_95 -> V_113 [ F_41 ( V_124 -> V_126 ) ] ;
for ( V_125 = 0 ; V_125 < V_124 -> V_125 ; V_125 ++ ) {
struct V_61 V_127 ;
F_18 ( V_95 -> V_102 , V_82 ) ;
while ( 1 ) {
V_127 = F_20 ( V_95 -> V_102 , 1000 ) ;
if ( V_127 . V_63 != V_68 || V_127 . V_65 == V_82 )
break;
}
V_67 [ V_125 ] = V_127 . V_66 ;
}
return V_125 ;
}
static int F_42 ( struct V_92 * V_93 ,
struct V_71 * V_72 ,
struct V_123 * V_124 ,
unsigned int * V_67 )
{
struct V_94 * V_95 = V_93 -> V_96 ;
int V_125 ;
int V_82 ;
V_82 = V_95 -> V_114 [ F_41 ( V_124 -> V_126 ) ] ;
for ( V_125 = 0 ; V_125 < V_124 -> V_125 ; V_125 ++ ) {
struct V_61 V_128 ;
V_128 . V_63 = V_68 ;
V_128 . V_65 = V_82 ;
V_128 . V_66 = V_67 [ V_125 ] ;
F_21 ( V_95 -> V_102 , V_128 ) ;
}
return V_125 ;
}
static int F_43 ( struct V_92 * V_93 ,
struct V_71 * V_72 ,
struct V_123 * V_124 ,
unsigned int * V_67 )
{
struct V_94 * V_95 = V_93 -> V_96 ;
int V_125 ;
int V_82 ;
V_82 = V_95 -> V_115 [ F_41 ( V_124 -> V_126 ) ] ;
for ( V_125 = 0 ; V_125 < V_124 -> V_125 ; V_125 ++ ) {
struct V_61 V_127 ;
F_19 ( V_95 -> V_102 , V_82 ) ;
while ( 1 ) {
V_127 = F_20 ( V_95 -> V_102 , 1000 ) ;
if ( V_127 . V_63 != V_69 || V_127 . V_65 == V_82 )
break;
}
V_67 [ V_125 ] = V_127 . V_66 ;
}
return V_125 ;
}
static int F_44 ( struct V_92 * V_93 ,
struct V_71 * V_72 ,
struct V_123 * V_124 ,
unsigned int * V_67 )
{
struct V_94 * V_95 = V_93 -> V_96 ;
int V_125 ;
int V_82 ;
V_82 = V_95 -> V_117 [ F_41 ( V_124 -> V_126 ) ] ;
for ( V_125 = 0 ; V_125 < V_124 -> V_125 ; V_125 ++ ) {
struct V_61 V_128 ;
V_128 . V_63 = V_69 ;
V_128 . V_65 = V_82 ;
V_128 . V_66 = V_67 [ V_125 ] ;
F_21 ( V_95 -> V_102 , V_128 ) ;
V_95 -> V_129 [ V_82 ] = V_67 [ V_125 ] ;
}
return V_125 ;
}
static int F_45 ( struct V_92 * V_93 ,
struct V_71 * V_72 ,
struct V_123 * V_124 ,
unsigned int * V_67 )
{
struct V_94 * V_95 = V_93 -> V_96 ;
int V_125 ;
int V_82 = F_41 ( V_124 -> V_126 ) ;
for ( V_125 = 0 ; V_125 < V_124 -> V_125 ; V_125 ++ )
V_67 [ V_125 ] = V_95 -> V_129 [ V_82 ] ;
return V_125 ;
}
static int F_46 ( struct V_92 * V_93 ,
struct V_71 * V_72 ,
struct V_123 * V_124 ,
unsigned int * V_67 )
{
struct V_94 * V_95 = V_93 -> V_96 ;
int V_125 ;
int V_82 ;
V_82 = V_95 -> V_119 [ F_41 ( V_124 -> V_126 ) ] ;
for ( V_125 = 0 ; V_125 < V_124 -> V_125 ; V_125 ++ ) {
struct V_61 V_127 ;
F_19 ( V_95 -> V_102 , V_82 ) ;
while ( 1 ) {
V_127 = F_20 ( V_95 -> V_102 , 1000 ) ;
if ( V_127 . V_63 != V_69 || V_127 . V_65 == V_82 )
break;
}
V_67 [ V_125 ] = V_127 . V_66 ;
}
return V_125 ;
}
static int F_47 ( struct V_92 * V_93 ,
struct V_130 * V_131 )
{
struct V_94 * V_95 ;
struct V_71 * V_72 ;
int V_132 ;
V_95 = F_48 ( V_93 , sizeof( * V_95 ) ) ;
if ( ! V_95 )
return - V_86 ;
V_95 -> V_120 = V_131 -> V_133 [ 0 ] ;
V_95 -> V_30 = V_131 -> V_133 [ 1 ] ;
V_132 = F_49 ( V_93 , 5 ) ;
if ( V_132 )
return V_132 ;
V_72 = & V_93 -> V_112 [ 0 ] ;
V_72 -> type = V_134 ;
V_72 -> V_135 = V_136 ;
V_72 -> V_83 = 0 ;
V_72 -> V_84 = 1 ;
V_72 -> V_87 = & V_88 ;
V_72 -> V_137 = F_40 ;
V_72 = & V_93 -> V_112 [ 1 ] ;
V_72 -> type = V_138 ;
V_72 -> V_135 = V_139 ;
V_72 -> V_83 = 0 ;
V_72 -> V_84 = 1 ;
V_72 -> V_87 = & V_88 ;
V_72 -> V_140 = F_42 ;
V_72 = & V_93 -> V_112 [ 2 ] ;
V_72 -> type = V_141 ;
V_72 -> V_135 = V_136 | V_142 ;
V_72 -> V_83 = 0 ;
V_72 -> V_84 = 1 ;
V_72 -> V_87 = NULL ;
V_72 -> V_137 = F_43 ;
V_72 = & V_93 -> V_112 [ 3 ] ;
V_72 -> type = V_143 ;
V_72 -> V_135 = V_139 ;
V_72 -> V_83 = 0 ;
V_72 -> V_84 = 1 ;
V_72 -> V_87 = NULL ;
V_72 -> V_140 = F_44 ;
V_72 -> V_137 = F_45 ;
V_72 = & V_93 -> V_112 [ 4 ] ;
V_72 -> type = V_144 ;
V_72 -> V_135 = V_136 | V_145 ;
V_72 -> V_83 = 0 ;
V_72 -> V_84 = 1 ;
V_72 -> V_87 = NULL ;
V_72 -> V_137 = F_46 ;
V_93 -> V_146 = F_35 ;
V_93 -> V_147 = F_39 ;
return 0 ;
}
static void F_50 ( struct V_92 * V_93 )
{
struct V_71 * V_72 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_93 -> V_148 ; V_70 ++ ) {
V_72 = & V_93 -> V_112 [ V_70 ] ;
F_23 ( V_72 -> V_80 ) ;
F_23 ( V_72 -> V_79 ) ;
}
}

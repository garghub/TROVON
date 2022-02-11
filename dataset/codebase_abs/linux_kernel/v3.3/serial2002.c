static long F_1 ( struct V_1 * V_2 , unsigned V_3 , unsigned long V_4 )
{
if ( V_2 -> V_5 -> V_6 )
return V_2 -> V_5 -> V_6 ( V_2 , V_3 , V_4 ) ;
return - V_7 ;
}
static int F_2 ( struct V_1 * V_2 , unsigned char * V_8 , int V_9 )
{
int V_10 ;
T_1 V_11 ;
V_11 = F_3 () ;
F_4 ( V_12 ) ;
V_2 -> V_13 = 0 ;
V_10 = V_2 -> V_5 -> V_14 ( V_2 , V_8 , V_9 , & V_2 -> V_13 ) ;
F_4 ( V_11 ) ;
return V_10 ;
}
static int F_5 ( struct V_1 * V_2 , int V_15 )
{
int V_10 ;
V_10 = - 1 ;
if ( ! F_6 ( V_2 ) ) {
T_1 V_11 ;
V_11 = F_3 () ;
F_4 ( V_12 ) ;
if ( V_2 -> V_5 -> V_16 ) {
struct V_17 V_18 ;
struct V_19 V_20 , V_21 ;
F_7 ( & V_20 ) ;
F_8 ( & V_18 ) ;
while ( 1 ) {
long V_22 ;
int V_23 ;
V_23 = V_2 -> V_5 -> V_16 ( V_2 , & V_18 . V_24 ) ;
if ( V_23 & ( V_25 | V_26 | V_27 |
V_28 | V_29 ) ) {
break;
}
F_7 ( & V_21 ) ;
V_22 =
( 1000000 * ( V_21 . V_30 - V_20 . V_30 ) +
V_21 . V_31 - V_20 . V_31 ) ;
if ( V_22 > V_15 )
break;
F_9 ( V_32 ) ;
F_10 ( ( ( V_15 -
V_22 ) * V_33 ) / 10000 ) ;
}
F_11 ( & V_18 ) ;
{
unsigned char V_34 ;
V_2 -> V_13 = 0 ;
if ( V_2 -> V_5 -> V_35 ( V_2 , & V_34 , 1 , & V_2 -> V_13 ) == 1 )
V_10 = V_34 ;
}
} else {
int V_36 = 0 ;
while ( 1 ) {
unsigned char V_34 ;
V_36 ++ ;
if ( V_36 >= V_15 )
break;
V_2 -> V_13 = 0 ;
if ( V_2 -> V_5 -> V_35 ( V_2 , & V_34 , 1 , & V_2 -> V_13 ) == 1 ) {
V_10 = V_34 ;
break;
}
F_12 ( 100 ) ;
}
}
F_4 ( V_11 ) ;
}
return V_10 ;
}
static void F_13 ( struct V_1 * V_2 , int V_37 )
{
T_1 V_11 ;
V_11 = F_3 () ;
F_4 ( V_12 ) ;
{
struct V_38 V_39 ;
F_1 ( V_2 , V_40 , ( unsigned long ) & V_39 ) ;
V_39 . V_41 = 0 ;
V_39 . V_42 = 0 ;
V_39 . V_43 = 0 ;
V_39 . V_44 = V_45 | V_46 | V_47 ;
V_39 . V_48 [ V_49 ] = 0 ;
V_39 . V_48 [ V_50 ] = 0 ;
switch ( V_37 ) {
case 2400 : {
V_39 . V_44 |= V_51 ;
}
break;
case 4800 : {
V_39 . V_44 |= V_52 ;
}
break;
case 9600 : {
V_39 . V_44 |= V_53 ;
}
break;
case 19200 : {
V_39 . V_44 |= V_54 ;
}
break;
case 38400 : {
V_39 . V_44 |= V_55 ;
}
break;
case 57600 : {
V_39 . V_44 |= V_56 ;
}
break;
case 115200 : {
V_39 . V_44 |= V_57 ;
}
break;
default: {
V_39 . V_44 |= V_53 ;
}
break;
}
F_1 ( V_2 , V_58 , ( unsigned long ) & V_39 ) ;
}
{
struct V_59 V_39 ;
F_1 ( V_2 , V_60 , ( unsigned long ) & V_39 ) ;
V_39 . V_61 |= V_62 ;
F_1 ( V_2 , V_63 , ( unsigned long ) & V_39 ) ;
}
F_4 ( V_11 ) ;
}
static void F_14 ( struct V_1 * V_2 , int V_64 )
{
char V_65 ;
V_65 = 0x40 | ( V_64 & 0x1f ) ;
F_2 ( V_2 , & V_65 , 1 ) ;
}
static void F_15 ( struct V_1 * V_2 , int V_64 )
{
char V_65 ;
V_65 = 0x60 | ( V_64 & 0x1f ) ;
F_2 ( V_2 , & V_65 , 1 ) ;
}
static struct V_66 F_16 ( struct V_1 * V_2 , int V_15 )
{
struct V_66 V_10 ;
int V_67 ;
V_10 . V_68 = V_69 ;
V_10 . V_70 = 0 ;
V_10 . V_71 = 0 ;
V_67 = 0 ;
while ( 1 ) {
int V_72 = F_5 ( V_2 , V_15 ) ;
V_67 ++ ;
if ( V_72 < 0 ) {
F_17 ( V_73 L_1 ) ;
break;
} else if ( V_72 & 0x80 ) {
V_10 . V_71 = ( V_10 . V_71 << 7 ) | ( V_72 & 0x7f ) ;
} else {
if ( V_67 == 1 ) {
switch ( ( V_72 >> 5 ) & 0x03 ) {
case 0 : {
V_10 . V_71 = 0 ;
V_10 . V_68 = V_74 ;
}
break;
case 1 : {
V_10 . V_71 = 1 ;
V_10 . V_68 = V_74 ;
}
break;
}
} else {
V_10 . V_71 =
( V_10 . V_71 << 2 ) | ( ( V_72 & 0x60 ) >> 5 ) ;
V_10 . V_68 = V_75 ;
}
V_10 . V_70 = V_72 & 0x1f ;
break;
}
}
return V_10 ;
}
static void F_18 ( struct V_1 * V_2 , struct V_66 V_72 )
{
if ( V_72 . V_68 == V_74 ) {
unsigned char V_34 =
( ( V_72 . V_71 << 5 ) & 0x20 ) | ( V_72 . V_70 & 0x1f ) ;
F_2 ( V_2 , & V_34 , 1 ) ;
} else {
unsigned char V_34 [ 6 ] ;
int V_76 = 0 ;
if ( V_72 . V_71 >= ( 1L << 30 ) ) {
V_34 [ V_76 ] = 0x80 | ( ( V_72 . V_71 >> 30 ) & 0x03 ) ;
V_76 ++ ;
}
if ( V_72 . V_71 >= ( 1L << 23 ) ) {
V_34 [ V_76 ] = 0x80 | ( ( V_72 . V_71 >> 23 ) & 0x7f ) ;
V_76 ++ ;
}
if ( V_72 . V_71 >= ( 1L << 16 ) ) {
V_34 [ V_76 ] = 0x80 | ( ( V_72 . V_71 >> 16 ) & 0x7f ) ;
V_76 ++ ;
}
if ( V_72 . V_71 >= ( 1L << 9 ) ) {
V_34 [ V_76 ] = 0x80 | ( ( V_72 . V_71 >> 9 ) & 0x7f ) ;
V_76 ++ ;
}
V_34 [ V_76 ] = 0x80 | ( ( V_72 . V_71 >> 2 ) & 0x7f ) ;
V_76 ++ ;
V_34 [ V_76 ] = ( ( V_72 . V_71 << 5 ) & 0x60 ) | ( V_72 . V_70 & 0x1f ) ;
V_76 ++ ;
F_2 ( V_2 , V_34 , V_76 ) ;
}
}
static int F_19 ( struct V_77 * V_78 )
{
int V_10 ;
char V_79 [ 20 ] ;
sprintf ( V_79 , L_2 , V_80 -> V_79 ) ;
V_80 -> V_81 = F_20 ( V_79 , V_82 , 0 ) ;
if ( F_6 ( V_80 -> V_81 ) ) {
V_10 = ( int ) F_21 ( V_80 -> V_81 ) ;
F_17 ( V_73 L_3 , V_10 ) ;
} else {
struct V_83 {
short int V_68 ;
short int V_84 ;
int V_85 ;
int V_86 ;
};
struct V_83 * V_87 ;
struct V_83 * V_88 ;
struct V_83 * V_89 ;
struct V_83 * V_90 ;
int V_76 ;
V_10 = 0 ;
V_87 = F_22 ( 32 , sizeof( struct V_83 ) ,
V_91 ) ;
V_88 = F_22 ( 32 , sizeof( struct V_83 ) ,
V_91 ) ;
V_89 = F_22 ( 32 , sizeof( struct V_83 ) ,
V_91 ) ;
V_90 = F_22 ( 32 , sizeof( struct V_83 ) ,
V_91 ) ;
if ( ! V_87 || ! V_88
|| ! V_89 || ! V_90 ) {
V_10 = - V_92 ;
goto V_93;
}
F_13 ( V_80 -> V_81 , V_80 -> V_37 ) ;
F_15 ( V_80 -> V_81 , 31 ) ;
while ( 1 ) {
struct V_66 V_72 ;
V_72 = F_16 ( V_80 -> V_81 , 1000 ) ;
if ( V_72 . V_68 != V_75 || V_72 . V_70 != 31
|| ! ( V_72 . V_71 & 0xe0 ) ) {
break;
} else {
int V_94 , V_64 , V_68 ;
struct V_83 * V_95 = NULL ;
V_64 = V_72 . V_71 & 0x1f ;
V_68 = ( V_72 . V_71 >> 5 ) & 0x7 ;
V_94 = ( V_72 . V_71 >> 8 ) & 0x3 ;
switch ( V_68 ) {
case 1 : {
V_95 = V_87 ;
}
break;
case 2 : {
V_95 = V_88 ;
}
break;
case 3 : {
V_95 = V_89 ;
}
break;
case 4 : {
V_95 = V_90 ;
}
break;
case 5 : {
V_95 = V_89 ;
}
break;
}
if ( V_95 ) {
V_95 [ V_64 ] . V_68 = V_68 ;
switch ( V_94 ) {
case 0 : {
V_95 [ V_64 ] . V_84
=
( V_72 . V_71 >> 10 ) &
0x3f ;
}
break;
case 1 : {
int V_96 , V_97 , V_85 ;
V_96 =
( V_72 . V_71 >> 10 ) &
0x7 ;
V_97 =
( V_72 . V_71 >> 13 ) &
0x1 ;
V_85 =
( V_72 . V_71 >> 14 ) &
0xfffff ;
switch ( V_96 ) {
case 0 : {
V_85 =
V_85
*
1000000 ;
}
break;
case 1 : {
V_85 =
V_85
*
1000 ;
}
break;
case 2 : {
V_85 =
V_85
* 1 ;
}
break;
}
if ( V_97 )
V_85 = - V_85 ;
V_95 [ V_64 ] . V_85
= V_85 ;
}
break;
case 2 : {
int V_96 , V_97 , V_86 ;
V_96 =
( V_72 . V_71 >> 10 ) &
0x7 ;
V_97 =
( V_72 . V_71 >> 13 ) &
0x1 ;
V_86 =
( V_72 . V_71 >> 14 ) &
0xfffff ;
switch ( V_96 ) {
case 0 : {
V_86 =
V_86
*
1000000 ;
}
break;
case 1 : {
V_86 =
V_86
*
1000 ;
}
break;
case 2 : {
V_86 =
V_86
* 1 ;
}
break;
}
if ( V_97 )
V_86 = - V_86 ;
V_95 [ V_64 ] . V_86
= V_86 ;
}
break;
}
}
}
}
for ( V_76 = 0 ; V_76 <= 4 ; V_76 ++ ) {
struct V_83 * V_98 ;
unsigned char * V_99 = NULL ;
struct V_100 * V_101 = NULL ;
int V_68 = 0 ;
switch ( V_76 ) {
case 0 : {
V_98 = V_87 ;
V_99 = V_80 -> V_102 ;
V_68 = 1 ;
}
break;
case 1 : {
V_98 = V_88 ;
V_99 = V_80 -> V_103 ;
V_68 = 2 ;
}
break;
case 2 : {
V_98 = V_89 ;
V_99 = V_80 -> V_104 ;
V_101 = V_80 -> V_105 ;
V_68 = 3 ;
}
break;
case 3 : {
V_98 = V_90 ;
V_99 = V_80 -> V_106 ;
V_101 = V_80 -> V_107 ;
V_68 = 4 ;
}
break;
case 4 : {
V_98 = V_89 ;
V_99 = V_80 -> V_108 ;
V_101 = V_80 -> V_105 ;
V_68 = 5 ;
}
break;
default: {
V_98 = NULL ;
}
break;
}
if ( V_98 ) {
struct V_109 * V_110 ;
const struct V_111 * * V_112 =
NULL ;
unsigned int * V_113 ;
int V_114 , V_115 ;
for ( V_115 = 0 , V_114 = 0 ; V_114 < 32 ; V_114 ++ ) {
if ( V_98 [ V_114 ] . V_68 == V_68 )
V_115 ++ ;
}
V_110 = & V_78 -> V_116 [ V_76 ] ;
V_110 -> V_117 = V_115 ;
V_110 -> V_118 = 0 ;
F_23 ( V_110 -> V_113 ) ;
V_110 -> V_113 = V_113 =
F_24 ( sizeof( unsigned int ) * V_110 -> V_117 ,
V_91 ) ;
if ( ! V_110 -> V_113 )
break;
F_23 ( V_110 -> V_112 ) ;
V_110 -> V_119 = NULL ;
V_110 -> V_112 = NULL ;
if ( V_101 ) {
V_110 -> V_112 = V_112 =
F_24 ( sizeof
( struct
V_100 ) *
V_110 -> V_117 , V_91 ) ;
if ( ! V_110 -> V_112 )
break;
}
for ( V_115 = 0 , V_114 = 0 ; V_114 < 32 ; V_114 ++ ) {
if ( V_98 [ V_114 ] . V_68 == V_68 ) {
if ( V_99 )
V_99 [ V_115 ] = V_114 ;
if ( V_101 ) {
V_101 [ V_114 ] . V_67 = 1 ;
V_101 [ V_114 ] . V_101 . V_85 =
V_98 [ V_114 ] . V_85 ;
V_101 [ V_114 ] . V_101 . V_86 =
V_98 [ V_114 ] . V_86 ;
V_112 [ V_115 ] =
( const struct
V_111 * )
& V_101 [ V_114 ] ;
}
V_113 [ V_115 ] =
( ( long long ) 1 << V_98 [ V_114 ] . V_84 )
- 1 ;
V_115 ++ ;
}
}
}
}
if ( V_76 <= 4 ) {
V_10 = - V_92 ;
for ( V_76 = 0 ; V_76 <= 4 ; V_76 ++ ) {
struct V_109 * V_110 ;
V_110 = & V_78 -> V_116 [ V_76 ] ;
F_23 ( V_110 -> V_113 ) ;
V_110 -> V_113 = NULL ;
F_23 ( V_110 -> V_112 ) ;
V_110 -> V_112 = NULL ;
}
}
V_93:
F_23 ( V_87 ) ;
F_23 ( V_88 ) ;
F_23 ( V_89 ) ;
F_23 ( V_90 ) ;
if ( V_10 ) {
if ( V_80 -> V_81 ) {
F_25 ( V_80 -> V_81 , 0 ) ;
V_80 -> V_81 = NULL ;
}
}
}
return V_10 ;
}
static void F_26 ( struct V_77 * V_78 )
{
if ( ! F_6 ( V_80 -> V_81 ) && ( V_80 -> V_81 != 0 ) )
F_25 ( V_80 -> V_81 , 0 ) ;
}
static int F_27 ( struct V_77 * V_78 ,
struct V_109 * V_110 ,
struct V_120 * V_121 , unsigned int * V_72 )
{
int V_122 ;
int V_115 ;
V_115 = V_80 -> V_102 [ F_28 ( V_121 -> V_123 ) ] ;
for ( V_122 = 0 ; V_122 < V_121 -> V_122 ; V_122 ++ ) {
struct V_66 V_35 ;
F_14 ( V_80 -> V_81 , V_115 ) ;
while ( 1 ) {
V_35 = F_16 ( V_80 -> V_81 , 1000 ) ;
if ( V_35 . V_68 != V_74 || V_35 . V_70 == V_115 )
break;
}
V_72 [ V_122 ] = V_35 . V_71 ;
}
return V_122 ;
}
static int F_29 ( struct V_77 * V_78 ,
struct V_109 * V_110 ,
struct V_120 * V_121 , unsigned int * V_72 )
{
int V_122 ;
int V_115 ;
V_115 = V_80 -> V_103 [ F_28 ( V_121 -> V_123 ) ] ;
for ( V_122 = 0 ; V_122 < V_121 -> V_122 ; V_122 ++ ) {
struct V_66 V_14 ;
V_14 . V_68 = V_74 ;
V_14 . V_70 = V_115 ;
V_14 . V_71 = V_72 [ V_122 ] ;
F_18 ( V_80 -> V_81 , V_14 ) ;
}
return V_122 ;
}
static int F_30 ( struct V_77 * V_78 ,
struct V_109 * V_110 ,
struct V_120 * V_121 , unsigned int * V_72 )
{
int V_122 ;
int V_115 ;
V_115 = V_80 -> V_104 [ F_28 ( V_121 -> V_123 ) ] ;
for ( V_122 = 0 ; V_122 < V_121 -> V_122 ; V_122 ++ ) {
struct V_66 V_35 ;
F_15 ( V_80 -> V_81 , V_115 ) ;
while ( 1 ) {
V_35 = F_16 ( V_80 -> V_81 , 1000 ) ;
if ( V_35 . V_68 != V_75 || V_35 . V_70 == V_115 )
break;
}
V_72 [ V_122 ] = V_35 . V_71 ;
}
return V_122 ;
}
static int F_31 ( struct V_77 * V_78 ,
struct V_109 * V_110 ,
struct V_120 * V_121 , unsigned int * V_72 )
{
int V_122 ;
int V_115 ;
V_115 = V_80 -> V_106 [ F_28 ( V_121 -> V_123 ) ] ;
for ( V_122 = 0 ; V_122 < V_121 -> V_122 ; V_122 ++ ) {
struct V_66 V_14 ;
V_14 . V_68 = V_75 ;
V_14 . V_70 = V_115 ;
V_14 . V_71 = V_72 [ V_122 ] ;
F_18 ( V_80 -> V_81 , V_14 ) ;
V_80 -> V_124 [ V_115 ] = V_72 [ V_122 ] ;
}
return V_122 ;
}
static int F_32 ( struct V_77 * V_78 ,
struct V_109 * V_110 ,
struct V_120 * V_121 , unsigned int * V_72 )
{
int V_122 ;
int V_115 = F_28 ( V_121 -> V_123 ) ;
for ( V_122 = 0 ; V_122 < V_121 -> V_122 ; V_122 ++ )
V_72 [ V_122 ] = V_80 -> V_124 [ V_115 ] ;
return V_122 ;
}
static int F_33 ( struct V_77 * V_78 ,
struct V_109 * V_110 ,
struct V_120 * V_121 , unsigned int * V_72 )
{
int V_122 ;
int V_115 ;
V_115 = V_80 -> V_108 [ F_28 ( V_121 -> V_123 ) ] ;
for ( V_122 = 0 ; V_122 < V_121 -> V_122 ; V_122 ++ ) {
struct V_66 V_35 ;
F_15 ( V_80 -> V_81 , V_115 ) ;
while ( 1 ) {
V_35 = F_16 ( V_80 -> V_81 , 1000 ) ;
if ( V_35 . V_68 != V_75 || V_35 . V_70 == V_115 )
break;
}
V_72 [ V_122 ] = V_35 . V_71 ;
}
return V_122 ;
}
static int F_34 ( struct V_77 * V_78 ,
struct V_125 * V_126 )
{
struct V_109 * V_110 ;
F_35 ( V_78 -> V_127 , L_4 , V_78 -> V_128 ) ;
V_78 -> V_129 = V_130 -> V_131 ;
if ( F_36 ( V_78 , sizeof( struct V_132 ) ) < 0 )
return - V_92 ;
V_78 -> V_133 = F_19 ;
V_78 -> V_134 = F_26 ;
V_80 -> V_79 = V_126 -> V_135 [ 0 ] ;
V_80 -> V_37 = V_126 -> V_135 [ 1 ] ;
F_35 ( V_78 -> V_127 , L_5 , V_80 -> V_79 ,
V_80 -> V_37 ) ;
if ( F_37 ( V_78 , 5 ) < 0 )
return - V_92 ;
V_110 = V_78 -> V_116 + 0 ;
V_110 -> type = V_136 ;
V_110 -> V_137 = V_138 ;
V_110 -> V_117 = 0 ;
V_110 -> V_118 = 1 ;
V_110 -> V_119 = & V_139 ;
V_110 -> V_140 = & F_27 ;
V_110 = V_78 -> V_116 + 1 ;
V_110 -> type = V_141 ;
V_110 -> V_137 = V_142 ;
V_110 -> V_117 = 0 ;
V_110 -> V_118 = 1 ;
V_110 -> V_119 = & V_139 ;
V_110 -> V_143 = & F_29 ;
V_110 = V_78 -> V_116 + 2 ;
V_110 -> type = V_144 ;
V_110 -> V_137 = V_138 | V_145 ;
V_110 -> V_117 = 0 ;
V_110 -> V_118 = 1 ;
V_110 -> V_119 = 0 ;
V_110 -> V_140 = & F_30 ;
V_110 = V_78 -> V_116 + 3 ;
V_110 -> type = V_146 ;
V_110 -> V_137 = V_142 ;
V_110 -> V_117 = 0 ;
V_110 -> V_118 = 1 ;
V_110 -> V_119 = 0 ;
V_110 -> V_143 = & F_31 ;
V_110 -> V_140 = & F_32 ;
V_110 = V_78 -> V_116 + 4 ;
V_110 -> type = V_147 ;
V_110 -> V_137 = V_138 | V_148 ;
V_110 -> V_117 = 0 ;
V_110 -> V_118 = 1 ;
V_110 -> V_119 = 0 ;
V_110 -> V_140 = & F_33 ;
return 1 ;
}
static int F_38 ( struct V_77 * V_78 )
{
struct V_109 * V_110 ;
int V_76 ;
F_35 ( V_78 -> V_127 , L_6 , V_78 -> V_128 ) ;
for ( V_76 = 0 ; V_76 < 5 ; V_76 ++ ) {
V_110 = & V_78 -> V_116 [ V_76 ] ;
F_23 ( V_110 -> V_113 ) ;
F_23 ( V_110 -> V_112 ) ;
}
return 0 ;
}
static int T_2 F_39 ( void )
{
return F_40 ( & V_149 ) ;
}
static void T_3 F_41 ( void )
{
F_42 ( & V_149 ) ;
}

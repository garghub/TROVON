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
if ( V_22 > V_15 ) {
break;
}
F_9 ( V_32 ) ;
F_10 ( ( ( V_15 -
V_22 ) * V_33 ) / 10000 ) ;
}
F_11 ( & V_18 ) ;
{
unsigned char V_34 ;
V_2 -> V_13 = 0 ;
if ( V_2 -> V_5 -> V_35 ( V_2 , & V_34 , 1 , & V_2 -> V_13 ) == 1 ) {
V_10 = V_34 ;
}
}
} else {
int V_36 = 0 ;
while ( 1 ) {
unsigned char V_34 ;
V_36 ++ ;
if ( V_36 >= V_15 ) {
break;
}
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
F_17 ( L_1 ) ;
break;
} else if ( V_72 & 0x80 ) {
V_10 . V_71 = ( V_10 . V_71 << 7 ) | ( V_72 & 0x7f ) ;
} else {
if ( V_67 == 1 ) {
switch ( ( V_72 >> 5 ) & 0x03 ) {
case 0 : {
V_10 . V_71 = 0 ;
V_10 . V_68 = V_73 ;
}
break;
case 1 : {
V_10 . V_71 = 1 ;
V_10 . V_68 = V_73 ;
}
break;
}
} else {
V_10 . V_71 =
( V_10 . V_71 << 2 ) | ( ( V_72 & 0x60 ) >> 5 ) ;
V_10 . V_68 = V_74 ;
}
V_10 . V_70 = V_72 & 0x1f ;
break;
}
}
return V_10 ;
}
static void F_18 ( struct V_1 * V_2 , struct V_66 V_72 )
{
if ( V_72 . V_68 == V_73 ) {
unsigned char V_34 =
( ( V_72 . V_71 << 5 ) & 0x20 ) | ( V_72 . V_70 & 0x1f ) ;
F_2 ( V_2 , & V_34 , 1 ) ;
} else {
unsigned char V_34 [ 6 ] ;
int V_75 = 0 ;
if ( V_72 . V_71 >= ( 1L << 30 ) ) {
V_34 [ V_75 ] = 0x80 | ( ( V_72 . V_71 >> 30 ) & 0x03 ) ;
V_75 ++ ;
}
if ( V_72 . V_71 >= ( 1L << 23 ) ) {
V_34 [ V_75 ] = 0x80 | ( ( V_72 . V_71 >> 23 ) & 0x7f ) ;
V_75 ++ ;
}
if ( V_72 . V_71 >= ( 1L << 16 ) ) {
V_34 [ V_75 ] = 0x80 | ( ( V_72 . V_71 >> 16 ) & 0x7f ) ;
V_75 ++ ;
}
if ( V_72 . V_71 >= ( 1L << 9 ) ) {
V_34 [ V_75 ] = 0x80 | ( ( V_72 . V_71 >> 9 ) & 0x7f ) ;
V_75 ++ ;
}
V_34 [ V_75 ] = 0x80 | ( ( V_72 . V_71 >> 2 ) & 0x7f ) ;
V_75 ++ ;
V_34 [ V_75 ] = ( ( V_72 . V_71 << 5 ) & 0x60 ) | ( V_72 . V_70 & 0x1f ) ;
V_75 ++ ;
F_2 ( V_2 , V_34 , V_75 ) ;
}
}
static int F_19 ( struct V_76 * V_77 )
{
int V_10 ;
char V_78 [ 20 ] ;
sprintf ( V_78 , L_2 , V_79 -> V_78 ) ;
V_79 -> V_80 = F_20 ( V_78 , V_81 , 0 ) ;
if ( F_6 ( V_79 -> V_80 ) ) {
V_10 = ( int ) F_21 ( V_79 -> V_80 ) ;
F_17 ( L_3 , V_10 ) ;
} else {
struct V_82 {
short int V_68 ;
short int V_83 ;
int V_84 ;
int V_85 ;
};
struct V_82 * V_86 ;
struct V_82 * V_87 ;
struct V_82 * V_88 ;
struct V_82 * V_89 ;
int V_75 ;
V_10 = 0 ;
V_86 = F_22 ( 32 , sizeof( struct V_82 ) ,
V_90 ) ;
V_87 = F_22 ( 32 , sizeof( struct V_82 ) ,
V_90 ) ;
V_88 = F_22 ( 32 , sizeof( struct V_82 ) ,
V_90 ) ;
V_89 = F_22 ( 32 , sizeof( struct V_82 ) ,
V_90 ) ;
if ( ! V_86 || ! V_87
|| ! V_88 || ! V_89 ) {
V_10 = - V_91 ;
goto V_92;
}
F_13 ( V_79 -> V_80 , V_79 -> V_37 ) ;
F_15 ( V_79 -> V_80 , 31 ) ;
while ( 1 ) {
struct V_66 V_72 ;
V_72 = F_16 ( V_79 -> V_80 , 1000 ) ;
if ( V_72 . V_68 != V_74 || V_72 . V_70 != 31
|| ! ( V_72 . V_71 & 0xe0 ) ) {
break;
} else {
int V_93 , V_64 , V_68 ;
struct V_82 * V_94 = NULL ;
V_64 = V_72 . V_71 & 0x1f ;
V_68 = ( V_72 . V_71 >> 5 ) & 0x7 ;
V_93 = ( V_72 . V_71 >> 8 ) & 0x3 ;
switch ( V_68 ) {
case 1 : {
V_94 = V_86 ;
}
break;
case 2 : {
V_94 = V_87 ;
}
break;
case 3 : {
V_94 = V_88 ;
}
break;
case 4 : {
V_94 = V_89 ;
}
break;
case 5 : {
V_94 = V_88 ;
}
break;
}
if ( V_94 ) {
V_94 [ V_64 ] . V_68 = V_68 ;
switch ( V_93 ) {
case 0 : {
V_94 [ V_64 ] . V_83
=
( V_72 . V_71 >> 10 ) &
0x3f ;
}
break;
case 1 : {
int V_95 , V_96 , V_84 ;
V_95 =
( V_72 . V_71 >> 10 ) &
0x7 ;
V_96 =
( V_72 . V_71 >> 13 ) &
0x1 ;
V_84 =
( V_72 . V_71 >> 14 ) &
0xfffff ;
switch ( V_95 ) {
case 0 : {
V_84 =
V_84
*
1000000 ;
}
break;
case 1 : {
V_84 =
V_84
*
1000 ;
}
break;
case 2 : {
V_84 =
V_84
* 1 ;
}
break;
}
if ( V_96 ) {
V_84 = - V_84 ;
}
V_94 [ V_64 ] . V_84
= V_84 ;
}
break;
case 2 : {
int V_95 , V_96 , V_85 ;
V_95 =
( V_72 . V_71 >> 10 ) &
0x7 ;
V_96 =
( V_72 . V_71 >> 13 ) &
0x1 ;
V_85 =
( V_72 . V_71 >> 14 ) &
0xfffff ;
switch ( V_95 ) {
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
if ( V_96 ) {
V_85 = - V_85 ;
}
V_94 [ V_64 ] . V_85
= V_85 ;
}
break;
}
}
}
}
for ( V_75 = 0 ; V_75 <= 4 ; V_75 ++ ) {
struct V_82 * V_97 ;
unsigned char * V_98 = NULL ;
struct V_99 * V_100 = NULL ;
int V_68 = 0 ;
switch ( V_75 ) {
case 0 : {
V_97 = V_86 ;
V_98 = V_79 -> V_101 ;
V_68 = 1 ;
}
break;
case 1 : {
V_97 = V_87 ;
V_98 = V_79 -> V_102 ;
V_68 = 2 ;
}
break;
case 2 : {
V_97 = V_88 ;
V_98 = V_79 -> V_103 ;
V_100 = V_79 -> V_104 ;
V_68 = 3 ;
}
break;
case 3 : {
V_97 = V_89 ;
V_98 = V_79 -> V_105 ;
V_100 = V_79 -> V_106 ;
V_68 = 4 ;
}
break;
case 4 : {
V_97 = V_88 ;
V_98 = V_79 -> V_107 ;
V_100 = V_79 -> V_104 ;
V_68 = 5 ;
}
break;
default: {
V_97 = NULL ;
}
break;
}
if ( V_97 ) {
struct V_108 * V_109 ;
const struct V_110 * * V_111 =
NULL ;
unsigned int * V_112 ;
int V_113 , V_114 ;
for ( V_114 = 0 , V_113 = 0 ; V_113 < 32 ; V_113 ++ ) {
if ( V_97 [ V_113 ] . V_68 == V_68 ) {
V_114 ++ ;
}
}
V_109 = & V_77 -> V_115 [ V_75 ] ;
V_109 -> V_116 = V_114 ;
V_109 -> V_117 = 0 ;
F_23 ( V_109 -> V_112 ) ;
V_109 -> V_112 = V_112 =
F_24 ( sizeof( unsigned int ) * V_109 -> V_116 ,
V_90 ) ;
if ( ! V_109 -> V_112 )
break;
F_23 ( V_109 -> V_111 ) ;
V_109 -> V_118 = NULL ;
V_109 -> V_111 = NULL ;
if ( V_100 ) {
V_109 -> V_111 = V_111 =
F_24 ( sizeof
( struct
V_99 ) *
V_109 -> V_116 , V_90 ) ;
if ( ! V_109 -> V_111 )
break;
}
for ( V_114 = 0 , V_113 = 0 ; V_113 < 32 ; V_113 ++ ) {
if ( V_97 [ V_113 ] . V_68 == V_68 ) {
if ( V_98 ) {
V_98 [ V_114 ] = V_113 ;
}
if ( V_100 ) {
V_100 [ V_113 ] . V_67 = 1 ;
V_100 [ V_113 ] . V_100 . V_84 =
V_97 [ V_113 ] . V_84 ;
V_100 [ V_113 ] . V_100 . V_85 =
V_97 [ V_113 ] . V_85 ;
V_111 [ V_114 ] =
( const struct
V_110 * )
& V_100 [ V_113 ] ;
}
V_112 [ V_114 ] =
( ( long long ) 1 << V_97 [ V_113 ] . V_83 )
- 1 ;
V_114 ++ ;
}
}
}
}
if ( V_75 <= 4 ) {
V_10 = - V_91 ;
for ( V_75 = 0 ; V_75 <= 4 ; V_75 ++ ) {
struct V_108 * V_109 ;
V_109 = & V_77 -> V_115 [ V_75 ] ;
F_23 ( V_109 -> V_112 ) ;
V_109 -> V_112 = NULL ;
F_23 ( V_109 -> V_111 ) ;
V_109 -> V_111 = NULL ;
}
}
V_92:
F_23 ( V_86 ) ;
F_23 ( V_87 ) ;
F_23 ( V_88 ) ;
F_23 ( V_89 ) ;
if ( V_10 ) {
if ( V_79 -> V_80 ) {
F_25 ( V_79 -> V_80 , 0 ) ;
V_79 -> V_80 = NULL ;
}
}
}
return V_10 ;
}
static void F_26 ( struct V_76 * V_77 )
{
if ( ! F_6 ( V_79 -> V_80 ) && ( V_79 -> V_80 != 0 ) ) {
F_25 ( V_79 -> V_80 , 0 ) ;
}
}
static int F_27 ( struct V_76 * V_77 ,
struct V_108 * V_109 ,
struct V_119 * V_120 , unsigned int * V_72 )
{
int V_121 ;
int V_114 ;
V_114 = V_79 -> V_101 [ F_28 ( V_120 -> V_122 ) ] ;
for ( V_121 = 0 ; V_121 < V_120 -> V_121 ; V_121 ++ ) {
struct V_66 V_35 ;
F_14 ( V_79 -> V_80 , V_114 ) ;
while ( 1 ) {
V_35 = F_16 ( V_79 -> V_80 , 1000 ) ;
if ( V_35 . V_68 != V_73 || V_35 . V_70 == V_114 ) {
break;
}
}
V_72 [ V_121 ] = V_35 . V_71 ;
}
return V_121 ;
}
static int F_29 ( struct V_76 * V_77 ,
struct V_108 * V_109 ,
struct V_119 * V_120 , unsigned int * V_72 )
{
int V_121 ;
int V_114 ;
V_114 = V_79 -> V_102 [ F_28 ( V_120 -> V_122 ) ] ;
for ( V_121 = 0 ; V_121 < V_120 -> V_121 ; V_121 ++ ) {
struct V_66 V_14 ;
V_14 . V_68 = V_73 ;
V_14 . V_70 = V_114 ;
V_14 . V_71 = V_72 [ V_121 ] ;
F_18 ( V_79 -> V_80 , V_14 ) ;
}
return V_121 ;
}
static int F_30 ( struct V_76 * V_77 ,
struct V_108 * V_109 ,
struct V_119 * V_120 , unsigned int * V_72 )
{
int V_121 ;
int V_114 ;
V_114 = V_79 -> V_103 [ F_28 ( V_120 -> V_122 ) ] ;
for ( V_121 = 0 ; V_121 < V_120 -> V_121 ; V_121 ++ ) {
struct V_66 V_35 ;
F_15 ( V_79 -> V_80 , V_114 ) ;
while ( 1 ) {
V_35 = F_16 ( V_79 -> V_80 , 1000 ) ;
if ( V_35 . V_68 != V_74 || V_35 . V_70 == V_114 ) {
break;
}
}
V_72 [ V_121 ] = V_35 . V_71 ;
}
return V_121 ;
}
static int F_31 ( struct V_76 * V_77 ,
struct V_108 * V_109 ,
struct V_119 * V_120 , unsigned int * V_72 )
{
int V_121 ;
int V_114 ;
V_114 = V_79 -> V_105 [ F_28 ( V_120 -> V_122 ) ] ;
for ( V_121 = 0 ; V_121 < V_120 -> V_121 ; V_121 ++ ) {
struct V_66 V_14 ;
V_14 . V_68 = V_74 ;
V_14 . V_70 = V_114 ;
V_14 . V_71 = V_72 [ V_121 ] ;
F_18 ( V_79 -> V_80 , V_14 ) ;
V_79 -> V_123 [ V_114 ] = V_72 [ V_121 ] ;
}
return V_121 ;
}
static int F_32 ( struct V_76 * V_77 ,
struct V_108 * V_109 ,
struct V_119 * V_120 , unsigned int * V_72 )
{
int V_121 ;
int V_114 = F_28 ( V_120 -> V_122 ) ;
for ( V_121 = 0 ; V_121 < V_120 -> V_121 ; V_121 ++ ) {
V_72 [ V_121 ] = V_79 -> V_123 [ V_114 ] ;
}
return V_121 ;
}
static int F_33 ( struct V_76 * V_77 ,
struct V_108 * V_109 ,
struct V_119 * V_120 , unsigned int * V_72 )
{
int V_121 ;
int V_114 ;
V_114 = V_79 -> V_107 [ F_28 ( V_120 -> V_122 ) ] ;
for ( V_121 = 0 ; V_121 < V_120 -> V_121 ; V_121 ++ ) {
struct V_66 V_35 ;
F_15 ( V_79 -> V_80 , V_114 ) ;
while ( 1 ) {
V_35 = F_16 ( V_79 -> V_80 , 1000 ) ;
if ( V_35 . V_68 != V_74 || V_35 . V_70 == V_114 ) {
break;
}
}
V_72 [ V_121 ] = V_35 . V_71 ;
}
return V_121 ;
}
static int F_34 ( struct V_76 * V_77 ,
struct V_124 * V_125 )
{
struct V_108 * V_109 ;
F_17 ( L_4 , V_77 -> V_126 ) ;
V_77 -> V_127 = V_128 -> V_129 ;
if ( F_35 ( V_77 , sizeof( struct V_130 ) ) < 0 ) {
return - V_91 ;
}
V_77 -> V_131 = F_19 ;
V_77 -> V_132 = F_26 ;
V_79 -> V_78 = V_125 -> V_133 [ 0 ] ;
V_79 -> V_37 = V_125 -> V_133 [ 1 ] ;
F_17 ( L_5 , V_79 -> V_78 , V_79 -> V_37 ) ;
if ( F_36 ( V_77 , 5 ) < 0 )
return - V_91 ;
V_109 = V_77 -> V_115 + 0 ;
V_109 -> type = V_134 ;
V_109 -> V_135 = V_136 ;
V_109 -> V_116 = 0 ;
V_109 -> V_117 = 1 ;
V_109 -> V_118 = & V_137 ;
V_109 -> V_138 = & F_27 ;
V_109 = V_77 -> V_115 + 1 ;
V_109 -> type = V_139 ;
V_109 -> V_135 = V_140 ;
V_109 -> V_116 = 0 ;
V_109 -> V_117 = 1 ;
V_109 -> V_118 = & V_137 ;
V_109 -> V_141 = & F_29 ;
V_109 = V_77 -> V_115 + 2 ;
V_109 -> type = V_142 ;
V_109 -> V_135 = V_136 | V_143 ;
V_109 -> V_116 = 0 ;
V_109 -> V_117 = 1 ;
V_109 -> V_118 = 0 ;
V_109 -> V_138 = & F_30 ;
V_109 = V_77 -> V_115 + 3 ;
V_109 -> type = V_144 ;
V_109 -> V_135 = V_140 ;
V_109 -> V_116 = 0 ;
V_109 -> V_117 = 1 ;
V_109 -> V_118 = 0 ;
V_109 -> V_141 = & F_31 ;
V_109 -> V_138 = & F_32 ;
V_109 = V_77 -> V_115 + 4 ;
V_109 -> type = V_145 ;
V_109 -> V_135 = V_136 | V_146 ;
V_109 -> V_116 = 0 ;
V_109 -> V_117 = 1 ;
V_109 -> V_118 = 0 ;
V_109 -> V_138 = & F_33 ;
return 1 ;
}
static int F_37 ( struct V_76 * V_77 )
{
struct V_108 * V_109 ;
int V_75 ;
F_17 ( L_6 , V_77 -> V_126 ) ;
for ( V_75 = 0 ; V_75 < 5 ; V_75 ++ ) {
V_109 = & V_77 -> V_115 [ V_75 ] ;
F_23 ( V_109 -> V_112 ) ;
F_23 ( V_109 -> V_111 ) ;
}
return 0 ;
}
static int T_2 F_38 ( void )
{
return F_39 ( & V_147 ) ;
}
static void T_3 F_40 ( void )
{
F_41 ( & V_147 ) ;
}

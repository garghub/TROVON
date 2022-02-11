static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 ;
#ifdef F_2
F_3 ( V_9 L_1 , V_7 [ 0 ] , V_7 [ 1 ] ) ;
#endif
V_4 -> V_10 = 0 ;
for ( V_8 = 0 ; V_8 < V_4 -> V_11 / V_12 ; ++ V_8 ) {
unsigned long V_13 = V_14 -> V_15 [ V_8 ] ,
V_16 = V_8 * 8 ;
unsigned char V_17 = 0 ,
V_18 = ( V_7 [ 0 ] >> V_16 ) & 0xff ,
V_19 = ( V_7 [ 1 ] >> V_16 ) & 0xff ;
V_17 = F_4 ( V_13 ) ;
#ifdef F_2
F_3
( V_9 L_2
L_3 , V_8 , ( unsigned ) V_18 ,
( unsigned ) V_19 , V_16 , V_13 , ( unsigned ) V_17 ) ;
#endif
if ( V_18 ) {
V_17 &= ~ V_18 ;
V_17 |= ~ V_19 & V_18 ;
F_5 ( V_17 , V_13 ) ;
}
#ifdef F_2
F_3 ( V_9 L_4 , ( unsigned ) V_17 ) ;
#endif
V_4 -> V_10 |= ( ( unsigned int ) V_17 ) << V_16 ;
}
V_7 [ 1 ] = ~ V_4 -> V_10 ;
#ifdef F_2
F_3 ( V_9 L_5 , V_4 -> V_10 , V_7 [ 1 ] ) ;
#endif
return V_6 -> V_20 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_21 = F_7 ( V_6 -> V_22 ) , V_8 = V_21 / 8 , V_23 =
V_21 % 8 ;
unsigned long V_13 ;
unsigned char V_17 ;
V_13 = V_14 -> V_15 [ V_8 ] ;
switch ( V_7 [ 0 ] ) {
case V_24 :
V_4 -> V_25 |= 1 << V_21 ;
break;
case V_26 :
V_17 = F_4 ( V_13 ) ;
V_17 &= ~ ( 1 << V_23 ) ;
F_5 ( V_17 , V_13 ) ;
V_4 -> V_25 &= ~ ( 1 << V_21 ) ;
break;
case V_27 :
V_7 [ 1 ] =
( V_4 -> V_25 & ( 1 << V_21 ) ) ? V_28 : V_29 ;
return V_6 -> V_20 ;
break;
default:
return - V_30 ;
break;
}
return V_6 -> V_20 ;
}
static void F_8 ( struct V_1 * V_2 , int V_31 , int V_32 )
{
struct V_33 * V_34 = V_2 -> V_35 ;
if ( V_31 < 0 || V_31 >= 1 )
return;
if ( V_32 < 0 || V_32 >= V_36 )
return;
V_34 -> V_37 [ V_31 ] . V_38 &= ~ V_39 ;
V_34 -> V_37 [ V_31 ] . V_38 |= V_32 << V_40 ;
F_5 ( V_34 -> V_37 [ V_31 ] . V_38 ,
V_34 -> V_37 [ V_31 ] . V_41 + V_42 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = V_2 -> V_35 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < 1 ; ++ V_31 ) {
int V_43 , V_32 ;
unsigned long V_44 = V_34 -> V_37 [ V_31 ] . V_41 ;
F_8 ( V_2 , V_31 , 0 ) ;
for ( V_43 = 0 ; V_43 < V_45 ; ++ V_43 )
F_5 ( 0 , V_44 + V_46 + V_43 ) ;
for ( V_32 = 1 ; V_32 < V_36 ; ++ V_32 ) {
int V_47 ;
F_8 ( V_2 , V_31 , V_32 ) ;
for ( V_47 = V_48 ;
V_47 < V_48 + V_49 ; ++ V_47 )
F_5 ( 0 , V_44 + V_47 ) ;
}
F_8 ( V_2 , V_31 , 0 ) ;
}
}
static void F_10 ( struct V_1 * V_2 , int V_31 , int V_43 )
{
struct V_33 * V_34 = V_2 -> V_35 ;
if ( V_31 < 0 || V_31 >= 1 )
return;
if ( V_43 < 0 || V_43 >= V_45 )
return;
V_34 -> V_37 [ V_31 ] . V_38 |= 0x1 << V_43 ;
F_5 ( V_34 -> V_37 [ V_31 ] . V_38 ,
V_34 -> V_37 [ V_31 ] . V_41 + V_42 ) ;
return;
}
static void F_11 ( struct V_1 * V_2 , int V_31 , int V_43 )
{
struct V_33 * V_34 = V_2 -> V_35 ;
if ( V_31 < 0 || V_31 >= 1 )
return;
if ( V_43 < 0 || V_43 >= V_45 )
return;
V_34 -> V_37 [ V_31 ] . V_38 &= ~ ( 0x1 << V_43 ) | V_50 ;
F_5 ( V_34 -> V_37 [ V_31 ] . V_38 ,
V_34 -> V_37 [ V_31 ] . V_41 + V_42 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_33 * V_34 = V_2 -> V_35 ;
int V_51 , V_52 , V_31 , V_43 ;
V_31 = V_14 -> V_53 . V_54 . V_31 ;
if ( V_31 < 0 )
return;
V_14 -> V_53 . V_54 . V_55 = 0 ;
V_14 -> V_53 . V_54 . V_56 = 0 ;
V_4 -> V_57 -> V_58 = NULL ;
V_51 = V_14 -> V_53 . V_54 . V_59 / V_12 ;
V_52 = V_14 -> V_53 . V_54 . V_60 / V_12 ;
F_8 ( V_2 , V_31 , V_61 ) ;
for ( V_43 = V_52 ; V_43 < V_52 + V_51 ; ++ V_43 ) {
F_5 ( 0 , V_34 -> V_37 [ V_31 ] . V_41 + V_62 + V_43 ) ;
}
}
static T_1 F_13 ( int V_63 , void * V_64 )
{
int V_31 , V_65 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_64 ;
struct V_33 * V_34 = V_2 -> V_35 ;
int V_66 ;
for ( V_31 = 0 ; V_31 < V_67 ; ++ V_31 ) {
if ( V_63 == V_34 -> V_37 [ V_31 ] . V_63 ) {
unsigned long V_68 ;
unsigned V_69 = 0 ;
unsigned long V_41 = V_34 -> V_37 [ V_31 ] . V_41 ;
unsigned char V_70 ;
F_14 ( & V_34 -> V_37 [ V_31 ] . V_71 ,
V_68 ) ;
V_70 = F_4 ( V_41 + V_72 ) & 0x07 ;
if ( V_70 ) {
int V_43 ;
for ( V_43 = 0 ; V_43 < V_73 ;
++ V_43 ) {
if ( V_70 & ( 0x1 << V_43 ) ) {
unsigned char
V_74 = 0 ;
F_8 ( V_2 , V_31 ,
V_75 ) ;
V_74 =
F_4 ( V_41 +
V_76 + V_43 ) ;
if ( V_74 )
F_5 ( 0 , V_41 +
V_76 +
V_43 ) ;
V_69 |=
V_74 <<
V_43 * 8 ;
}
}
++ V_65 ;
}
F_15 ( & V_34 -> V_37 [ V_31 ] . V_71 ,
V_68 ) ;
if ( V_69 ) {
struct V_3 * V_4 ;
F_3
( V_9 L_6 ,
V_63 , V_31 , V_69 ) ;
for ( V_66 = 2 ; V_66 < V_2 -> V_77 ; V_66 ++ ) {
V_4 = & V_2 -> V_78 [ V_66 ] ;
if ( V_14 -> V_53 . V_54 . V_31 == V_31 ) {
unsigned long V_68 ;
unsigned V_79 ;
F_14 ( & V_14 -> V_53 .
V_54 . V_71 ,
V_68 ) ;
V_79 = V_4 -> V_57 -> V_80 ;
if ( V_14 -> V_53 . V_54 . V_56 ) {
unsigned V_81 =
( ( V_69 >>
V_14 -> V_53 . V_54 . V_60 )
&
( ( 0x1 << V_14 ->
V_53 . V_54 .
V_59 ) -
1 ) ) << V_14 ->
V_53 . V_54 . V_82 ;
if ( V_81 &
V_14 -> V_53 .
V_54 . V_55 ) {
unsigned int V_83
= 0 ;
unsigned int V_20 ,
V_84 , V_85 ;
V_85 =
V_4 ->
V_57 -> V_86 . V_87 ;
for ( V_20 = 0 ;
V_20 < V_85 ;
V_20 ++ ) {
V_84 = F_7 ( V_4 -> V_57 -> V_86 . V_88 [ V_20 ] ) ;
if ( V_81 & ( 1U << V_84 ) )
V_83 |= ( 1U << V_20 ) ;
}
if ( F_16 ( V_4 -> V_57 , ( ( short * ) & V_83 ) [ 0 ] )
&&
F_16
( V_4 -> V_57 ,
( ( short * )
& V_83 ) [ 1 ] ) ) {
V_4 -> V_57 -> V_80 |= ( V_89 | V_90 ) ;
} else {
F_12
( V_2 ,
V_4 ) ;
}
if ( ! V_14 -> V_53 . V_54 . V_91 ) {
if ( V_14 -> V_53 . V_54 . V_92 > 0 ) {
V_14 -> V_53 . V_54 . V_92 -- ;
if ( V_14 -> V_53 . V_54 . V_92 == 0 ) {
V_4 -> V_57 -> V_80 |= V_93 ;
F_12
( V_2 ,
V_4 ) ;
}
}
}
}
}
F_15
( & V_14 -> V_53 . V_54 .
V_71 , V_68 ) ;
if ( V_79 !=
V_4 -> V_57 -> V_80 ) {
F_17 ( V_2 , V_4 ) ;
}
}
}
}
}
}
if ( ! V_65 )
return V_94 ;
return V_95 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_33 * V_34 = V_2 -> V_35 ;
if ( ! V_14 -> V_53 . V_54 . V_91 && V_14 -> V_53 . V_54 . V_92 == 0 ) {
V_4 -> V_57 -> V_80 |= V_93 ;
V_14 -> V_53 . V_54 . V_56 = 0 ;
return 1 ;
} else {
unsigned V_96 = 0 , V_97 = 0 , V_20 ;
int V_51 , V_52 , V_31 , V_43 ;
struct V_98 * V_86 = & V_4 -> V_57 -> V_86 ;
V_31 = V_14 -> V_53 . V_54 . V_31 ;
if ( V_31 < 0 )
return 1 ;
V_14 -> V_53 . V_54 . V_55 = 0 ;
V_14 -> V_53 . V_54 . V_56 = 1 ;
V_51 = V_14 -> V_53 . V_54 . V_59 / V_12 ;
V_52 = V_14 -> V_53 . V_54 . V_60 / V_12 ;
if ( V_86 -> V_88 ) {
for ( V_20 = 0 ; V_20 < V_86 -> V_87 ; V_20 ++ ) {
V_96 |= ( 1U << F_7 ( V_86 -> V_88 [ V_20 ] ) ) ;
V_97 |= ( F_19 ( V_86 -> V_88 [ V_20 ] )
|| F_20 ( V_86 ->
V_88 [ V_20 ] ) ? 1U : 0U )
<< F_7 ( V_86 -> V_88 [ V_20 ] ) ;
}
}
V_96 &= ( ( 0x1 << V_14 -> V_53 . V_54 . V_59 ) -
1 ) << V_14 -> V_53 . V_54 . V_82 ;
V_14 -> V_53 . V_54 . V_55 = V_96 ;
{
unsigned char V_99 ;
F_5 ( 1 << 4 , V_2 -> V_41 + 3 ) ;
V_99 = V_2 -> V_63 & ( ( 1 << 4 ) - 1 ) ;
F_5 ( V_99 , V_2 -> V_41 + 2 ) ;
}
F_8 ( V_2 , V_31 , V_61 ) ;
for ( V_43 = V_52 ; V_43 < V_52 + V_51 ; ++ V_43 ) {
unsigned V_100 =
V_96 >> ( V_14 -> V_53 . V_54 . V_82 + ( V_43 -
V_52 )
* 8 ) & 0xff , V_101 =
V_97 >> ( V_14 -> V_53 . V_54 . V_82 +
( V_43 - V_52 ) * 8 ) & 0xff ;
F_5 ( V_100 ,
V_34 -> V_37 [ V_31 ] . V_41 + V_62 + V_43 ) ;
F_8 ( V_2 , V_31 , V_102 ) ;
F_5 ( V_101 ,
V_34 -> V_37 [ V_31 ] . V_41 + V_62 + V_43 ) ;
}
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_68 ;
F_14 ( & V_14 -> V_53 . V_54 . V_71 , V_68 ) ;
if ( V_14 -> V_53 . V_54 . V_56 )
F_12 ( V_2 , V_4 ) ;
F_15 ( & V_14 -> V_53 . V_54 . V_71 , V_68 ) ;
return 0 ;
}
static int
F_22 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_103 )
{
unsigned long V_68 ;
int V_104 = 0 ;
if ( V_103 != 0 )
return - V_30 ;
F_14 ( & V_14 -> V_53 . V_54 . V_71 , V_68 ) ;
V_4 -> V_57 -> V_58 = NULL ;
if ( V_14 -> V_53 . V_54 . V_56 )
V_104 = F_18 ( V_2 , V_4 ) ;
F_15 ( & V_14 -> V_53 . V_54 . V_71 , V_68 ) ;
if ( V_104 )
F_17 ( V_2 , V_4 ) ;
return 1 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_98 * V_86 = & V_4 -> V_57 -> V_86 ;
unsigned long V_68 ;
int V_104 = 0 ;
F_14 ( & V_14 -> V_53 . V_54 . V_71 , V_68 ) ;
V_14 -> V_53 . V_54 . V_56 = 1 ;
switch ( V_86 -> V_105 ) {
case V_106 :
V_14 -> V_53 . V_54 . V_91 = 0 ;
V_14 -> V_53 . V_54 . V_92 = V_86 -> V_107 ;
break;
default:
V_14 -> V_53 . V_54 . V_91 = 1 ;
V_14 -> V_53 . V_54 . V_92 = 0 ;
break;
}
switch ( V_86 -> V_108 ) {
case V_109 :
V_4 -> V_57 -> V_58 = F_22 ;
break;
default:
V_104 = F_18 ( V_2 , V_4 ) ;
break;
}
F_15 ( & V_14 -> V_53 . V_54 . V_71 , V_68 ) ;
if ( V_104 )
F_17 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_98 * V_86 )
{
int V_110 = 0 ;
V_110 |= F_25 ( & V_86 -> V_108 , V_111 | V_109 ) ;
V_110 |= F_25 ( & V_86 -> V_112 , V_113 ) ;
V_110 |= F_25 ( & V_86 -> V_114 , V_111 ) ;
V_110 |= F_25 ( & V_86 -> V_115 , V_106 ) ;
V_110 |= F_25 ( & V_86 -> V_105 , V_106 | V_116 ) ;
if ( V_110 )
return 1 ;
V_110 |= F_26 ( V_86 -> V_108 ) ;
V_110 |= F_26 ( V_86 -> V_105 ) ;
if ( V_110 )
return 2 ;
V_110 |= F_27 ( & V_86 -> V_117 , 0 ) ;
V_110 |= F_27 ( & V_86 -> V_118 , 0 ) ;
V_110 |= F_27 ( & V_86 -> V_119 , 0 ) ;
V_110 |= F_27 ( & V_86 -> V_120 , V_86 -> V_87 ) ;
switch ( V_86 -> V_105 ) {
case V_106 :
break;
case V_116 :
V_110 |= F_27 ( & V_86 -> V_107 , 0 ) ;
break;
default:
break;
}
if ( V_110 )
return 3 ;
return 0 ;
}
static int F_28 ( unsigned long V_41 )
{
unsigned long V_121 = 100000 ;
while ( V_121 -- )
if ( F_4 ( V_41 + 3 ) & 0x80 )
return 0 ;
return 1 ;
}
static int F_29 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_20 ;
unsigned long V_41 = V_14 -> V_41 ;
for ( V_20 = 0 ; V_20 < V_6 -> V_20 ; V_20 ++ ) {
unsigned V_21 = F_7 ( V_6 -> V_22 ) , V_122 =
F_20 ( V_6 -> V_22 ) , V_123 = F_19 ( V_6 -> V_22 ) ;
unsigned char V_124 = 0 ;
unsigned V_125 = 0 ;
short V_126 , V_127 = 0 ;
if ( V_21 > 7 )
V_21 -= 8 , V_125 = 4 ;
if ( V_123 != V_128 ) {
V_123 = V_129 ;
V_124 |= 1 << 7 ;
}
if ( V_122 < 2 )
V_127 = 0x8000 ;
if ( V_21 % 2 ) {
V_124 |= 1 << 6 ;
}
V_124 |= ( ( V_21 / 2 ) & 0x3 ) << 4 ;
V_124 |= ( V_122 & 0x3 ) << 2 ;
F_5 ( V_124 , V_41 + V_125 + 2 ) ;
F_28 ( V_41 + V_125 ) ;
F_5 ( V_124 , V_41 + V_125 + 2 ) ;
F_28 ( V_41 + V_125 ) ;
V_126 = F_4 ( V_41 + V_125 + 0 ) ;
V_126 |= F_4 ( V_41 + V_125 + 1 ) << 8 ;
V_126 += V_127 ;
V_7 [ V_20 ] = V_126 ;
}
return V_20 ;
}
static int F_30 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_6 -> V_20 ; V_20 ++ ) {
unsigned V_21 = F_7 ( V_6 -> V_22 ) ;
if ( V_21 < V_4 -> V_11 )
V_7 [ V_20 ] = V_14 -> V_130 . V_131 [ V_21 ] ;
}
return V_20 ;
}
static int F_31 ( unsigned long V_41 )
{
unsigned long V_121 = 100000L ;
while ( V_121 -- ) {
if ( F_4 ( V_41 + 3 ) & 0x80 )
return 0 ;
}
return 1 ;
}
static int F_32 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_20 ;
unsigned V_41 = V_14 -> V_41 , V_125 = 0 ;
for ( V_20 = 0 ; V_20 < V_6 -> V_20 ; V_20 ++ ) {
unsigned V_21 = F_7 ( V_6 -> V_22 ) , V_122 =
F_20 ( V_6 -> V_22 ) ;
if ( V_21 < V_4 -> V_11 ) {
unsigned char V_124 = 0 , V_132 =
V_122 & ( ( 1 << 4 ) - 1 ) ;
if ( V_21 >= 4 )
V_21 -= 4 , V_125 += 4 ;
F_5 ( V_132 , V_41 + V_125 + 0 ) ;
F_5 ( 0 , V_41 + V_125 + 1 ) ;
V_124 = ( V_21 << 1 ) | 0x60 ;
F_5 ( V_124 , V_41 + V_125 + 2 ) ;
F_31 ( V_41 + V_125 ) ;
F_5 ( V_7 [ V_20 ] & 0xff , V_41 + V_125 + 0 ) ;
F_5 ( ( V_7 [ V_20 ] >> 8 ) & 0xff , V_41 + V_125 + 1 ) ;
V_124 = 0x70 | ( V_21 << 1 ) ;
F_5 ( V_124 , V_41 + V_125 + 2 ) ;
F_31 ( V_41 + V_125 ) ;
V_14 -> V_130 . V_131 [ V_21 ] = V_7 [ V_20 ] ;
}
}
return V_20 ;
}
static int F_33 ( struct V_1 * V_2 , struct V_133 * V_134 )
{
struct V_33 * V_34 ;
struct V_3 * V_4 ;
int V_135 , V_136 , V_137 , V_138 , V_43 , V_31 ,
V_139 = 0 ;
unsigned int V_63 [ V_67 ] ;
int V_140 ;
V_63 [ 0 ] = V_134 -> V_141 [ 1 ] ;
V_140 = F_34 ( V_2 , V_134 -> V_141 [ 0 ] , 32 ) ;
if ( V_140 )
return V_140 ;
V_34 = F_35 ( sizeof( * V_34 ) , V_142 ) ;
if ( ! V_34 )
return - V_143 ;
V_2 -> V_35 = V_34 ;
for ( V_31 = 0 ; V_31 < V_67 ; ++ V_31 ) {
V_34 -> V_37 [ V_31 ] . V_144 = V_31 ;
V_34 -> V_37 [ V_31 ] . V_41 =
V_2 -> V_41 + 16 + V_31 * V_145 ;
V_34 -> V_37 [ V_31 ] . V_63 = 0 ;
F_36 ( & V_34 -> V_37 [ V_31 ] . V_71 ) ;
}
V_136 = V_146 * 1 ;
V_137 = F_37 ( V_136 ) ;
V_138 = V_137 + 2 ;
V_34 -> V_147 =
F_38 ( V_138 , sizeof( struct V_148 ) ,
V_142 ) ;
if ( ! V_34 -> V_147 ) {
F_3 ( V_149 L_7 ,
V_2 -> V_150 ) ;
return - V_143 ;
}
V_140 = F_39 ( V_2 , V_138 ) ;
if ( V_140 )
return V_140 ;
V_4 = & V_2 -> V_78 [ 0 ] ;
V_4 -> V_35 = & V_34 -> V_147 [ 0 ] ;
V_4 -> V_151 = 0xffff ;
V_4 -> V_152 = & V_153 ;
V_4 -> V_154 = V_155 | V_156 | V_157 ;
V_4 -> type = V_158 ;
V_4 -> V_11 = 16 ;
V_4 -> V_159 = V_4 -> V_11 ;
V_4 -> V_160 = F_29 ;
V_14 -> V_41 = V_2 -> V_41 + 0 ;
F_5 ( 0 , V_14 -> V_41 + 3 ) ;
F_5 ( 0 , V_14 -> V_41 + 4 + 3 ) ;
V_4 = & V_2 -> V_78 [ 1 ] ;
V_4 -> V_35 = & V_34 -> V_147 [ 1 ] ;
V_4 -> V_151 = 0xffff ;
V_4 -> V_152 = & V_161 ;
V_4 -> V_154 = V_155 ;
V_4 -> type = V_162 ;
V_4 -> V_11 = 8 ;
V_4 -> V_159 = V_4 -> V_11 ;
V_4 -> V_160 = F_30 ;
V_4 -> V_163 = F_32 ;
V_14 -> V_41 = V_2 -> V_41 + 8 ;
F_5 ( 0 , V_14 -> V_41 + 3 ) ;
F_5 ( 0 , V_14 -> V_41 + 4 + 3 ) ;
V_43 = 0 ;
V_31 = 0 ;
for ( V_135 = 2 ; V_135 < V_2 -> V_77 ; ++ V_135 ) {
int V_8 ;
V_4 = & V_2 -> V_78 [ V_135 ] ;
V_4 -> V_35 = & V_34 -> V_147 [ V_135 ] ;
V_4 -> V_151 = 1 ;
V_4 -> V_152 = & V_164 ;
V_4 -> V_154 = V_155 | V_165 ;
V_4 -> type = V_166 ;
V_4 -> V_167 = F_1 ;
V_4 -> V_168 = F_6 ;
V_4 -> V_11 = F_40 ( V_136 , V_169 ) ;
V_14 -> V_53 . V_54 . V_31 = - 1 ;
V_14 -> V_53 . V_54 . V_82 = - 1 ;
V_14 -> V_53 . V_54 . V_60 = - 1 ;
V_14 -> V_53 . V_54 . V_59 = - 1 ;
V_14 -> V_53 . V_54 . V_56 = 0 ;
V_4 -> V_159 = 1 ;
for ( V_8 = 0 ; V_8 < V_170 ; ++ V_8 , ++ V_43 ) {
if ( V_43 >= V_45 ) {
V_43 = 0 ;
++ V_31 ;
V_139 = 0 ;
}
V_14 -> V_15 [ V_8 ] =
V_34 -> V_37 [ V_31 ] . V_41 + V_43 ;
if ( V_139 <
V_12 * V_73
&& V_14 -> V_53 . V_54 . V_31 < 0 ) {
V_14 -> V_53 . V_54 . V_31 = V_31 ;
V_14 -> V_53 . V_54 . V_56 = 0 ;
V_14 -> V_53 . V_54 . V_92 = 0 ;
V_14 -> V_53 . V_54 . V_82 = V_8 * 8 ;
V_14 -> V_53 . V_54 . V_60 = V_139 ;
V_14 -> V_53 . V_54 . V_59 =
V_4 -> V_11 - V_14 -> V_53 . V_54 . V_82 ;
V_4 -> V_171 = F_21 ;
V_4 -> V_172 = F_23 ;
V_4 -> V_173 = F_24 ;
V_4 -> V_159 =
V_14 -> V_53 . V_54 . V_59 ;
}
V_139 += V_12 ;
}
F_36 ( & V_14 -> V_53 . V_54 . V_71 ) ;
V_136 -= V_4 -> V_11 ;
if ( ! V_136 ) {
V_31 = 0 ;
V_43 = 0 ;
}
}
F_9 ( V_2 ) ;
for ( V_31 = 0 ; V_63 [ 0 ] && V_31 < V_67 ; ++ V_31 ) {
if ( V_63 [ V_31 ]
&& F_41 ( V_63 [ V_31 ] , F_13 ,
V_174 , V_2 -> V_175 , V_2 ) ) {
int V_66 ;
for ( V_66 = V_31 - 1 ; V_66 >= 0 ; -- V_66 ) {
F_42 ( V_63 [ V_66 ] , V_2 ) ;
V_34 -> V_37 [ V_66 ] . V_63 = V_63 [ V_66 ] = 0 ;
}
V_63 [ V_31 ] = 0 ;
}
V_34 -> V_37 [ V_31 ] . V_63 = V_63 [ V_31 ] ;
}
return 1 ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = V_2 -> V_35 ;
int V_66 ;
for ( V_66 = 0 ; V_66 < V_67 ; ++ V_66 ) {
if ( V_34 && V_34 -> V_37 [ V_66 ] . V_63 )
F_42 ( V_34 -> V_37 [ V_66 ] . V_63 , V_2 ) ;
}
if ( V_34 && V_34 -> V_147 )
F_44 ( V_34 -> V_147 ) ;
F_45 ( V_2 ) ;
}

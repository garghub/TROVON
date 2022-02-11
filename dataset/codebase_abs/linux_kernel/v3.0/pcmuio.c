static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 , V_8 , V_9 , V_10 , V_11 , V_12 = 0 ;
unsigned long V_13 ;
unsigned int V_14 [ V_15 ] ;
V_13 = V_4 -> V_16 [ 0 ] ;
V_14 [ 0 ] = V_4 -> V_16 [ 1 ] ;
V_14 [ 1 ] = V_4 -> V_16 [ 2 ] ;
F_2 ( L_1 , V_2 -> V_17 , V_18 . V_19 ,
V_13 ) ;
V_2 -> V_13 = V_13 ;
if ( ! V_13 || ! F_3 ( V_13 ,
V_20 -> V_21 * V_22 ,
V_18 . V_19 ) ) {
F_2 ( L_2 ) ;
return - V_23 ;
}
V_2 -> V_24 = V_20 -> V_25 ;
if ( F_4 ( V_2 , sizeof( struct V_26 ) ) < 0 ) {
F_2 ( L_3 ) ;
return - V_27 ;
}
for ( V_11 = 0 ; V_11 < V_15 ; ++ V_11 ) {
V_28 -> V_29 [ V_11 ] . V_30 = V_11 ;
V_28 -> V_29 [ V_11 ] . V_13 = V_2 -> V_13 + V_11 * V_22 ;
V_28 -> V_29 [ V_11 ] . V_14 = 0 ;
F_5 ( & V_28 -> V_29 [ V_11 ] . V_31 ) ;
}
V_8 = V_32 * V_20 -> V_21 ;
V_9 = F_6 ( V_8 ) ;
V_28 -> V_33 =
F_7 ( V_9 , sizeof( struct V_34 ) ,
V_35 ) ;
if ( ! V_28 -> V_33 ) {
F_2 ( L_4 ) ;
return - V_27 ;
}
if ( F_8 ( V_2 , V_9 ) < 0 ) {
F_2 ( L_5 ) ;
return - V_27 ;
}
V_10 = 0 ;
V_11 = 0 ;
for ( V_7 = 0 ; V_7 < ( int ) V_2 -> V_36 ; ++ V_7 ) {
int V_37 ;
V_6 = V_2 -> V_38 + V_7 ;
V_6 -> V_39 = V_28 -> V_33 + V_7 ;
V_6 -> V_40 = 1 ;
V_6 -> V_41 = & V_42 ;
V_6 -> V_43 = V_44 | V_45 ;
V_6 -> type = V_46 ;
V_6 -> V_47 = V_48 ;
V_6 -> V_49 = V_50 ;
V_6 -> V_51 = F_9 ( V_8 , V_52 ) ;
V_53 -> V_54 . V_11 = - 1 ;
V_53 -> V_54 . V_55 = - 1 ;
V_53 -> V_54 . V_56 = - 1 ;
V_53 -> V_54 . V_57 = - 1 ;
V_53 -> V_54 . V_58 = 0 ;
V_6 -> V_59 = 1 ;
for ( V_37 = 0 ; V_37 < V_60 ; ++ V_37 , ++ V_10 ) {
if ( V_10 >= V_61 ) {
V_10 = 0 ;
++ V_11 ;
V_12 = 0 ;
}
V_53 -> V_62 [ V_37 ] =
V_28 -> V_29 [ V_11 ] . V_13 + V_10 ;
if ( V_12 <
V_63 * V_64
&& V_53 -> V_54 . V_11 < 0 ) {
V_53 -> V_54 . V_11 = V_11 ;
V_53 -> V_54 . V_58 = 0 ;
V_53 -> V_54 . V_65 = 0 ;
V_53 -> V_54 . V_55 = V_37 * 8 ;
V_53 -> V_54 . V_56 = V_12 ;
V_53 -> V_54 . V_57 =
V_6 -> V_51 - V_53 -> V_54 . V_55 ;
V_2 -> V_66 = V_6 ;
V_6 -> V_43 |= V_67 ;
V_6 -> V_68 = V_69 ;
V_6 -> V_70 = V_71 ;
V_6 -> V_72 = V_73 ;
V_6 -> V_59 = V_53 -> V_54 . V_57 ;
}
V_12 += V_63 ;
}
F_5 ( & V_53 -> V_54 . V_31 ) ;
V_8 -= V_6 -> V_51 ;
if ( ! V_8 ) {
V_11 = 0 ;
V_10 = 0 ;
}
}
F_10 ( V_2 ) ;
for ( V_11 = 0 ; V_14 [ 0 ] && V_11 < V_15 ; ++ V_11 ) {
if ( V_14 [ V_11 ]
&& F_11 ( V_14 [ V_11 ] , V_74 ,
V_75 , V_20 -> V_25 , V_2 ) ) {
int V_76 ;
for ( V_76 = V_11 - 1 ; V_76 >= 0 ; -- V_76 ) {
F_12 ( V_14 [ V_76 ] , V_2 ) ;
V_28 -> V_29 [ V_76 ] . V_14 = V_14 [ V_76 ] = 0 ;
}
V_14 [ V_11 ] = 0 ;
}
V_28 -> V_29 [ V_11 ] . V_14 = V_14 [ V_11 ] ;
}
V_2 -> V_14 = V_14 [ 0 ] ;
if ( V_14 [ 0 ] ) {
F_2 ( L_6 , V_14 [ 0 ] ) ;
if ( V_14 [ 1 ] && V_20 -> V_21 == 2 )
F_2 ( L_7 , V_14 [ 1 ] ) ;
} else {
F_2 ( L_8 ) ;
}
F_2 ( L_9 ) ;
return 1 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_76 ;
F_2 ( L_10 , V_2 -> V_17 , V_18 . V_19 ) ;
if ( V_2 -> V_13 )
F_14 ( V_2 -> V_13 , V_22 * V_20 -> V_21 ) ;
for ( V_76 = 0 ; V_76 < V_15 ; ++ V_76 ) {
if ( V_28 -> V_29 [ V_76 ] . V_14 )
F_12 ( V_28 -> V_29 [ V_76 ] . V_14 , V_2 ) ;
}
if ( V_28 && V_28 -> V_33 )
F_15 ( V_28 -> V_33 ) ;
return 0 ;
}
static int V_48 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_77 * V_78 , unsigned int * V_79 )
{
int V_37 ;
if ( V_78 -> V_80 != 2 )
return - V_81 ;
#ifdef F_16
F_2 ( L_11 , V_79 [ 0 ] , V_79 [ 1 ] ) ;
#endif
V_6 -> V_82 = 0 ;
for ( V_37 = 0 ; V_37 < V_6 -> V_51 / V_63 ; ++ V_37 ) {
unsigned long V_83 = V_53 -> V_62 [ V_37 ] ,
V_84 = V_37 * 8 ;
unsigned char V_85 = 0 ,
V_86 = ( V_79 [ 0 ] >> V_84 ) & 0xff ,
V_87 = ( V_79 [ 1 ] >> V_84 ) & 0xff ;
V_85 = F_17 ( V_83 ) ;
#ifdef F_16
F_2
( L_12 ,
V_37 , ( unsigned ) V_86 , ( unsigned ) V_87 ,
V_84 , V_83 , ( unsigned ) V_85 ) ;
#endif
if ( V_86 ) {
V_85 &= ~ V_86 ;
V_85 |= ~ V_87 & V_86 ;
F_18 ( V_85 , V_83 ) ;
}
#ifdef F_16
F_2 ( L_13 , ( unsigned ) V_85 ) ;
#endif
V_6 -> V_82 |= ( ( unsigned int ) V_85 ) << V_84 ;
}
V_79 [ 1 ] = ~ V_6 -> V_82 ;
#ifdef F_16
F_2 ( L_14 , V_6 -> V_82 , V_79 [ 1 ] ) ;
#endif
return 2 ;
}
static int V_50 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_77 * V_78 , unsigned int * V_79 )
{
int V_88 = F_19 ( V_78 -> V_89 ) , V_37 = V_88 / 8 , V_90 =
V_88 % 8 ;
unsigned long V_83 ;
unsigned char V_85 ;
V_83 = V_53 -> V_62 [ V_37 ] ;
switch ( V_79 [ 0 ] ) {
case V_91 :
V_6 -> V_92 |= 1 << V_88 ;
break;
case V_93 :
V_85 = F_17 ( V_83 ) ;
V_85 &= ~ ( 1 << V_90 ) ;
F_18 ( V_85 , V_83 ) ;
V_6 -> V_92 &= ~ ( 1 << V_88 ) ;
break;
case V_94 :
V_79 [ 1 ] =
( V_6 -> V_92 & ( 1 << V_88 ) ) ? V_95 : V_96 ;
return V_78 -> V_80 ;
break;
default:
return - V_81 ;
break;
}
return V_78 -> V_80 ;
}
static void F_10 ( struct V_1 * V_2 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_20 -> V_21 ; ++ V_11 ) {
int V_10 , V_97 ;
unsigned long V_98 = V_2 -> V_13 + V_11 * V_22 ;
F_20 ( V_2 , V_11 , 0 ) ;
for ( V_10 = 0 ; V_10 < V_61 ; ++ V_10 )
F_18 ( 0 , V_98 + V_99 + V_10 ) ;
for ( V_97 = 1 ; V_97 < V_100 ; ++ V_97 ) {
int V_101 ;
F_20 ( V_2 , V_11 , V_97 ) ;
for ( V_101 = V_102 ;
V_101 < V_102 + V_103 ; ++ V_101 )
F_18 ( 0 , V_98 + V_101 ) ;
}
F_20 ( V_2 , V_11 , 0 ) ;
}
}
static void F_20 ( struct V_1 * V_2 , int V_11 , int V_97 )
{
if ( V_11 < 0 || V_11 >= V_20 -> V_21 )
return;
if ( V_97 < 0 || V_97 >= V_100 )
return;
V_28 -> V_29 [ V_11 ] . V_104 &= ~ V_105 ;
V_28 -> V_29 [ V_11 ] . V_104 |= V_97 << V_106 ;
F_18 ( V_28 -> V_29 [ V_11 ] . V_104 ,
V_2 -> V_13 + V_22 * V_11 + V_107 ) ;
}
static void F_21 ( struct V_1 * V_2 , int V_11 , int V_10 )
{
if ( V_11 < 0 || V_11 >= V_20 -> V_21 )
return;
if ( V_10 < 0 || V_10 >= V_61 )
return;
V_28 -> V_29 [ V_11 ] . V_104 |= 0x1 << V_10 ;
F_18 ( V_28 -> V_29 [ V_11 ] . V_104 ,
V_2 -> V_13 + V_22 * V_11 + V_107 ) ;
}
static void F_22 ( struct V_1 * V_2 , int V_11 , int V_10 )
{
if ( V_11 < 0 || V_11 >= V_20 -> V_21 )
return;
if ( V_10 < 0 || V_10 >= V_61 )
return;
V_28 -> V_29 [ V_11 ] . V_104 &= ~ ( 0x1 << V_10 ) | V_108 ;
F_18 ( V_28 -> V_29 [ V_11 ] . V_104 ,
V_2 -> V_13 + V_22 * V_11 + V_107 ) ;
}
static T_1 V_74 ( int V_14 , void * V_109 )
{
int V_11 , V_110 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_109 ;
for ( V_11 = 0 ; V_11 < V_15 ; ++ V_11 ) {
if ( V_14 == V_28 -> V_29 [ V_11 ] . V_14 ) {
unsigned long V_111 ;
unsigned V_112 = 0 ;
unsigned long V_13 = V_28 -> V_29 [ V_11 ] . V_13 ;
unsigned char V_113 ;
F_23 ( & V_28 -> V_29 [ V_11 ] . V_31 ,
V_111 ) ;
V_113 = F_17 ( V_13 + V_114 ) & 0x07 ;
if ( V_113 ) {
int V_10 ;
for ( V_10 = 0 ; V_10 < V_64 ;
++ V_10 ) {
if ( V_113 & ( 0x1 << V_10 ) ) {
unsigned char
V_115 = 0 ;
F_20 ( V_2 , V_11 ,
V_116 ) ;
V_115 =
F_17 ( V_13 +
V_117 + V_10 ) ;
if ( V_115 )
F_18 ( 0 , V_13 +
V_117 +
V_10 ) ;
V_112 |=
V_115 <<
V_10 * 8 ;
}
}
++ V_110 ;
}
F_24 ( & V_28 -> V_29 [ V_11 ] . V_31 ,
V_111 ) ;
if ( V_112 ) {
struct V_5 * V_6 ;
F_2
( L_15 ,
V_14 , V_11 , V_112 ) ;
for ( V_6 = V_2 -> V_38 ;
V_6 < V_2 -> V_38 + V_2 -> V_36 ;
++ V_6 ) {
if ( V_53 -> V_54 . V_11 == V_11 ) {
unsigned long V_111 ;
unsigned V_118 ;
F_23 ( & V_53 ->
V_54 . V_31 ,
V_111 ) ;
V_118 = V_6 -> V_119 -> V_120 ;
if ( V_53 -> V_54 . V_58 ) {
unsigned V_121 =
( ( V_112 >>
V_53 -> V_54 . V_56 )
&
( ( 0x1 << V_53 ->
V_54 .
V_57 ) -
1 ) ) << V_53 ->
V_54 . V_55 ;
if ( V_121 &
V_53 -> V_54 . V_122 )
{
unsigned int V_123
= 0 ;
unsigned int V_80 ,
V_124 , V_125 ;
V_125 =
V_6 ->
V_119 -> V_126 . V_127 ;
for ( V_80 = 0 ;
V_80 < V_125 ;
V_80 ++ ) {
V_124 = F_19 ( V_6 -> V_119 -> V_126 . V_128 [ V_80 ] ) ;
if ( V_121 & ( 1U << V_124 ) ) {
V_123 |= ( 1U << V_80 ) ;
}
}
if ( F_25 ( V_6 -> V_119 , ( ( short * ) & V_123 ) [ 0 ] )
&&
F_25
( V_6 -> V_119 ,
( ( short * )
& V_123 ) [ 1 ] ) )
{
V_6 -> V_119 -> V_120 |= ( V_129 | V_130 ) ;
} else {
F_26
( V_2 ,
V_6 ) ;
}
if ( ! V_53 -> V_54 . V_131 ) {
if ( V_53 -> V_54 . V_65 > 0 ) {
V_53 -> V_54 . V_65 -- ;
if ( V_53 -> V_54 . V_65 == 0 ) {
V_6 -> V_119 -> V_120 |= V_132 ;
F_26
( V_2 ,
V_6 ) ;
}
}
}
}
}
F_24
( & V_53 -> V_54 . V_31 ,
V_111 ) ;
if ( V_118 !=
V_6 -> V_119 -> V_120 ) {
F_27 ( V_2 , V_6 ) ;
}
}
}
}
}
}
if ( ! V_110 )
return V_133 ;
return V_134 ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
int V_135 , V_136 , V_11 , V_10 ;
V_11 = V_53 -> V_54 . V_11 ;
if ( V_11 < 0 )
return;
V_53 -> V_54 . V_122 = 0 ;
V_53 -> V_54 . V_58 = 0 ;
V_6 -> V_119 -> V_137 = 0 ;
V_135 = V_53 -> V_54 . V_57 / V_63 ;
V_136 = V_53 -> V_54 . V_56 / V_63 ;
F_20 ( V_2 , V_11 , V_138 ) ;
for ( V_10 = V_136 ; V_10 < V_136 + V_135 ; ++ V_10 ) {
F_18 ( 0 , V_28 -> V_29 [ V_11 ] . V_13 + V_139 + V_10 ) ;
}
}
static int F_28 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
if ( ! V_53 -> V_54 . V_131 && V_53 -> V_54 . V_65 == 0 ) {
V_6 -> V_119 -> V_120 |= V_132 ;
V_53 -> V_54 . V_58 = 0 ;
return 1 ;
} else {
unsigned V_140 = 0 , V_141 = 0 , V_80 ;
int V_135 , V_136 , V_11 , V_10 ;
struct V_142 * V_126 = & V_6 -> V_119 -> V_126 ;
V_11 = V_53 -> V_54 . V_11 ;
if ( V_11 < 0 )
return 1 ;
V_53 -> V_54 . V_122 = 0 ;
V_53 -> V_54 . V_58 = 1 ;
V_135 = V_53 -> V_54 . V_57 / V_63 ;
V_136 = V_53 -> V_54 . V_56 / V_63 ;
if ( V_126 -> V_128 ) {
for ( V_80 = 0 ; V_80 < V_126 -> V_127 ; V_80 ++ ) {
V_140 |= ( 1U << F_19 ( V_126 -> V_128 [ V_80 ] ) ) ;
V_141 |= ( F_29 ( V_126 -> V_128 [ V_80 ] )
|| F_30 ( V_126 ->
V_128 [ V_80 ] ) ? 1U : 0U )
<< F_19 ( V_126 -> V_128 [ V_80 ] ) ;
}
}
V_140 &= ( ( 0x1 << V_53 -> V_54 . V_57 ) -
1 ) << V_53 -> V_54 . V_55 ;
V_53 -> V_54 . V_122 = V_140 ;
F_20 ( V_2 , V_11 , V_138 ) ;
for ( V_10 = V_136 ; V_10 < V_136 + V_135 ; ++ V_10 ) {
unsigned V_143 =
V_140 >> ( V_53 -> V_54 . V_55 + ( V_10 -
V_136 ) *
8 ) & 0xff , V_144 =
V_141 >> ( V_53 -> V_54 . V_55 +
( V_10 - V_136 ) * 8 ) & 0xff ;
F_18 ( V_143 ,
V_28 -> V_29 [ V_11 ] . V_13 + V_139 + V_10 ) ;
F_20 ( V_2 , V_11 , V_145 ) ;
F_18 ( V_144 ,
V_28 -> V_29 [ V_11 ] . V_13 + V_139 + V_10 ) ;
}
}
return 0 ;
}
static int V_69 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
unsigned long V_111 ;
F_23 ( & V_53 -> V_54 . V_31 , V_111 ) ;
if ( V_53 -> V_54 . V_58 )
F_26 ( V_2 , V_6 ) ;
F_24 ( & V_53 -> V_54 . V_31 , V_111 ) ;
return 0 ;
}
static int
F_31 ( struct V_1 * V_2 , struct V_5 * V_6 ,
unsigned int V_146 )
{
unsigned long V_111 ;
int V_147 = 0 ;
if ( V_146 != 0 )
return - V_81 ;
F_23 ( & V_53 -> V_54 . V_31 , V_111 ) ;
V_6 -> V_119 -> V_137 = 0 ;
if ( V_53 -> V_54 . V_58 ) {
V_147 = F_28 ( V_2 , V_6 ) ;
}
F_24 ( & V_53 -> V_54 . V_31 , V_111 ) ;
if ( V_147 ) {
F_27 ( V_2 , V_6 ) ;
}
return 1 ;
}
static int V_71 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_142 * V_126 = & V_6 -> V_119 -> V_126 ;
unsigned long V_111 ;
int V_147 = 0 ;
F_23 ( & V_53 -> V_54 . V_31 , V_111 ) ;
V_53 -> V_54 . V_58 = 1 ;
switch ( V_126 -> V_148 ) {
case V_149 :
V_53 -> V_54 . V_131 = 0 ;
V_53 -> V_54 . V_65 = V_126 -> V_150 ;
break;
default:
V_53 -> V_54 . V_131 = 1 ;
V_53 -> V_54 . V_65 = 0 ;
break;
}
switch ( V_126 -> V_151 ) {
case V_152 :
V_6 -> V_119 -> V_137 = F_31 ;
break;
default:
V_147 = F_28 ( V_2 , V_6 ) ;
break;
}
F_24 ( & V_53 -> V_54 . V_31 , V_111 ) ;
if ( V_147 ) {
F_27 ( V_2 , V_6 ) ;
}
return 0 ;
}
static int
V_73 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_142 * V_126 )
{
return F_32 ( V_2 , V_6 , V_126 ) ;
}
static int T_2 F_33 ( void )
{
return F_34 ( & V_18 ) ;
}
static void T_3 F_35 ( void )
{
F_36 ( & V_18 ) ;
}

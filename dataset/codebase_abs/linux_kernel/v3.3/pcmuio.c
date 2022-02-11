static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 , V_8 , V_9 , V_10 , V_11 , V_12 = 0 ;
unsigned long V_13 ;
unsigned int V_14 [ V_15 ] ;
V_13 = V_4 -> V_16 [ 0 ] ;
V_14 [ 0 ] = V_4 -> V_16 [ 1 ] ;
V_14 [ 1 ] = V_4 -> V_16 [ 2 ] ;
F_2 ( V_2 -> V_17 , L_1 , V_2 -> V_18 ,
V_19 . V_20 , V_13 ) ;
V_2 -> V_13 = V_13 ;
if ( ! V_13 || ! F_3 ( V_13 ,
V_21 -> V_22 * V_23 ,
V_19 . V_20 ) ) {
F_4 ( V_2 -> V_17 , L_2 ) ;
return - V_24 ;
}
V_2 -> V_25 = V_21 -> V_26 ;
if ( F_5 ( V_2 , sizeof( struct V_27 ) ) < 0 ) {
F_6 ( V_2 -> V_17 , L_3 ) ;
return - V_28 ;
}
for ( V_11 = 0 ; V_11 < V_15 ; ++ V_11 ) {
V_29 -> V_30 [ V_11 ] . V_31 = V_11 ;
V_29 -> V_30 [ V_11 ] . V_13 = V_2 -> V_13 + V_11 * V_23 ;
V_29 -> V_30 [ V_11 ] . V_14 = 0 ;
F_7 ( & V_29 -> V_30 [ V_11 ] . V_32 ) ;
}
V_8 = V_33 * V_21 -> V_22 ;
V_9 = F_8 ( V_8 ) ;
V_29 -> V_34 =
F_9 ( V_9 , sizeof( struct V_35 ) ,
V_36 ) ;
if ( ! V_29 -> V_34 ) {
F_6 ( V_2 -> V_17 , L_4 ) ;
return - V_28 ;
}
if ( F_10 ( V_2 , V_9 ) < 0 ) {
F_2 ( V_2 -> V_17 , L_5 ) ;
return - V_28 ;
}
V_10 = 0 ;
V_11 = 0 ;
for ( V_7 = 0 ; V_7 < ( int ) V_2 -> V_37 ; ++ V_7 ) {
int V_38 ;
V_6 = V_2 -> V_39 + V_7 ;
V_6 -> V_40 = V_29 -> V_34 + V_7 ;
V_6 -> V_41 = 1 ;
V_6 -> V_42 = & V_43 ;
V_6 -> V_44 = V_45 | V_46 ;
V_6 -> type = V_47 ;
V_6 -> V_48 = V_49 ;
V_6 -> V_50 = V_51 ;
V_6 -> V_52 = F_11 ( V_8 , V_53 ) ;
V_54 -> V_55 . V_11 = - 1 ;
V_54 -> V_55 . V_56 = - 1 ;
V_54 -> V_55 . V_57 = - 1 ;
V_54 -> V_55 . V_58 = - 1 ;
V_54 -> V_55 . V_59 = 0 ;
V_6 -> V_60 = 1 ;
for ( V_38 = 0 ; V_38 < V_61 ; ++ V_38 , ++ V_10 ) {
if ( V_10 >= V_62 ) {
V_10 = 0 ;
++ V_11 ;
V_12 = 0 ;
}
V_54 -> V_63 [ V_38 ] =
V_29 -> V_30 [ V_11 ] . V_13 + V_10 ;
if ( V_12 <
V_64 * V_65
&& V_54 -> V_55 . V_11 < 0 ) {
V_54 -> V_55 . V_11 = V_11 ;
V_54 -> V_55 . V_59 = 0 ;
V_54 -> V_55 . V_66 = 0 ;
V_54 -> V_55 . V_56 = V_38 * 8 ;
V_54 -> V_55 . V_57 = V_12 ;
V_54 -> V_55 . V_58 =
V_6 -> V_52 - V_54 -> V_55 . V_56 ;
V_2 -> V_67 = V_6 ;
V_6 -> V_44 |= V_68 ;
V_6 -> V_69 = V_70 ;
V_6 -> V_71 = V_72 ;
V_6 -> V_73 = V_74 ;
V_6 -> V_60 = V_54 -> V_55 . V_58 ;
}
V_12 += V_64 ;
}
F_7 ( & V_54 -> V_55 . V_32 ) ;
V_8 -= V_6 -> V_52 ;
if ( ! V_8 ) {
V_11 = 0 ;
V_10 = 0 ;
}
}
F_12 ( V_2 ) ;
for ( V_11 = 0 ; V_14 [ 0 ] && V_11 < V_15 ; ++ V_11 ) {
if ( V_14 [ V_11 ]
&& F_13 ( V_14 [ V_11 ] , V_75 ,
V_76 , V_21 -> V_26 , V_2 ) ) {
int V_77 ;
for ( V_77 = V_11 - 1 ; V_77 >= 0 ; -- V_77 ) {
F_14 ( V_14 [ V_77 ] , V_2 ) ;
V_29 -> V_30 [ V_77 ] . V_14 = V_14 [ V_77 ] = 0 ;
}
V_14 [ V_11 ] = 0 ;
}
V_29 -> V_30 [ V_11 ] . V_14 = V_14 [ V_11 ] ;
}
V_2 -> V_14 = V_14 [ 0 ] ;
if ( V_14 [ 0 ] ) {
F_2 ( V_2 -> V_17 , L_6 , V_14 [ 0 ] ) ;
if ( V_14 [ 1 ] && V_21 -> V_22 == 2 )
F_2 ( V_2 -> V_17 , L_7 , V_14 [ 1 ] ) ;
} else {
F_2 ( V_2 -> V_17 , L_8 ) ;
}
return 1 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_77 ;
F_2 ( V_2 -> V_17 , L_9 , V_2 -> V_18 ,
V_19 . V_20 ) ;
if ( V_2 -> V_13 )
F_16 ( V_2 -> V_13 , V_23 * V_21 -> V_22 ) ;
for ( V_77 = 0 ; V_77 < V_15 ; ++ V_77 ) {
if ( V_29 -> V_30 [ V_77 ] . V_14 )
F_14 ( V_29 -> V_30 [ V_77 ] . V_14 , V_2 ) ;
}
if ( V_29 && V_29 -> V_34 )
F_17 ( V_29 -> V_34 ) ;
return 0 ;
}
static int V_49 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_78 * V_79 , unsigned int * V_80 )
{
int V_38 ;
if ( V_79 -> V_81 != 2 )
return - V_82 ;
#ifdef F_18
F_2 ( V_2 -> V_17 , L_10 , V_80 [ 0 ] ,
V_80 [ 1 ] ) ;
#endif
V_6 -> V_83 = 0 ;
for ( V_38 = 0 ; V_38 < V_6 -> V_52 / V_64 ; ++ V_38 ) {
unsigned long V_84 = V_54 -> V_63 [ V_38 ] ,
V_85 = V_38 * 8 ;
unsigned char V_86 = 0 ,
V_87 = ( V_80 [ 0 ] >> V_85 ) & 0xff ,
V_88 = ( V_80 [ 1 ] >> V_85 ) & 0xff ;
V_86 = F_19 ( V_84 ) ;
#ifdef F_18
F_20
( L_11 ,
V_38 , ( unsigned ) V_87 , ( unsigned ) V_88 ,
V_85 , V_84 , ( unsigned ) V_86 ) ;
#endif
if ( V_87 ) {
V_86 &= ~ V_87 ;
V_86 |= ~ V_88 & V_87 ;
F_21 ( V_86 , V_84 ) ;
}
#ifdef F_18
F_2 ( V_2 -> V_17 , L_12 , ( unsigned ) V_86 ) ;
#endif
V_6 -> V_83 |= ( ( unsigned int ) V_86 ) << V_85 ;
}
V_80 [ 1 ] = ~ V_6 -> V_83 ;
#ifdef F_18
F_2 ( V_2 -> V_17 , L_13 , V_6 -> V_83 ,
V_80 [ 1 ] ) ;
#endif
return 2 ;
}
static int V_51 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_78 * V_79 , unsigned int * V_80 )
{
int V_89 = F_22 ( V_79 -> V_90 ) , V_38 = V_89 / 8 , V_91 =
V_89 % 8 ;
unsigned long V_84 ;
unsigned char V_86 ;
V_84 = V_54 -> V_63 [ V_38 ] ;
switch ( V_80 [ 0 ] ) {
case V_92 :
V_6 -> V_93 |= 1 << V_89 ;
break;
case V_94 :
V_86 = F_19 ( V_84 ) ;
V_86 &= ~ ( 1 << V_91 ) ;
F_21 ( V_86 , V_84 ) ;
V_6 -> V_93 &= ~ ( 1 << V_89 ) ;
break;
case V_95 :
V_80 [ 1 ] =
( V_6 -> V_93 & ( 1 << V_89 ) ) ? V_96 : V_97 ;
return V_79 -> V_81 ;
break;
default:
return - V_82 ;
break;
}
return V_79 -> V_81 ;
}
static void F_12 ( struct V_1 * V_2 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_21 -> V_22 ; ++ V_11 ) {
int V_10 , V_98 ;
unsigned long V_99 = V_2 -> V_13 + V_11 * V_23 ;
F_23 ( V_2 , V_11 , 0 ) ;
for ( V_10 = 0 ; V_10 < V_62 ; ++ V_10 )
F_21 ( 0 , V_99 + V_100 + V_10 ) ;
for ( V_98 = 1 ; V_98 < V_101 ; ++ V_98 ) {
int V_102 ;
F_23 ( V_2 , V_11 , V_98 ) ;
for ( V_102 = V_103 ;
V_102 < V_103 + V_104 ; ++ V_102 )
F_21 ( 0 , V_99 + V_102 ) ;
}
F_23 ( V_2 , V_11 , 0 ) ;
}
}
static void F_23 ( struct V_1 * V_2 , int V_11 , int V_98 )
{
if ( V_11 < 0 || V_11 >= V_21 -> V_22 )
return;
if ( V_98 < 0 || V_98 >= V_101 )
return;
V_29 -> V_30 [ V_11 ] . V_105 &= ~ V_106 ;
V_29 -> V_30 [ V_11 ] . V_105 |= V_98 << V_107 ;
F_21 ( V_29 -> V_30 [ V_11 ] . V_105 ,
V_2 -> V_13 + V_23 * V_11 + V_108 ) ;
}
static void F_24 ( struct V_1 * V_2 , int V_11 , int V_10 )
{
if ( V_11 < 0 || V_11 >= V_21 -> V_22 )
return;
if ( V_10 < 0 || V_10 >= V_62 )
return;
V_29 -> V_30 [ V_11 ] . V_105 |= 0x1 << V_10 ;
F_21 ( V_29 -> V_30 [ V_11 ] . V_105 ,
V_2 -> V_13 + V_23 * V_11 + V_108 ) ;
}
static void F_25 ( struct V_1 * V_2 , int V_11 , int V_10 )
{
if ( V_11 < 0 || V_11 >= V_21 -> V_22 )
return;
if ( V_10 < 0 || V_10 >= V_62 )
return;
V_29 -> V_30 [ V_11 ] . V_105 &= ~ ( 0x1 << V_10 ) | V_109 ;
F_21 ( V_29 -> V_30 [ V_11 ] . V_105 ,
V_2 -> V_13 + V_23 * V_11 + V_108 ) ;
}
static T_1 V_75 ( int V_14 , void * V_110 )
{
int V_11 , V_111 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_110 ;
for ( V_11 = 0 ; V_11 < V_15 ; ++ V_11 ) {
if ( V_14 == V_29 -> V_30 [ V_11 ] . V_14 ) {
unsigned long V_112 ;
unsigned V_113 = 0 ;
unsigned long V_13 = V_29 -> V_30 [ V_11 ] . V_13 ;
unsigned char V_114 ;
F_26 ( & V_29 -> V_30 [ V_11 ] . V_32 ,
V_112 ) ;
V_114 = F_19 ( V_13 + V_115 ) & 0x07 ;
if ( V_114 ) {
int V_10 ;
for ( V_10 = 0 ; V_10 < V_65 ;
++ V_10 ) {
if ( V_114 & ( 0x1 << V_10 ) ) {
unsigned char
V_116 = 0 ;
F_23 ( V_2 , V_11 ,
V_117 ) ;
V_116 =
F_19 ( V_13 +
V_118 + V_10 ) ;
if ( V_116 )
F_21 ( 0 , V_13 +
V_118 +
V_10 ) ;
V_113 |=
V_116 <<
V_10 * 8 ;
}
}
++ V_111 ;
}
F_27 ( & V_29 -> V_30 [ V_11 ] . V_32 ,
V_112 ) ;
if ( V_113 ) {
struct V_5 * V_6 ;
F_20
( L_14 ,
V_14 , V_11 , V_113 ) ;
for ( V_6 = V_2 -> V_39 ;
V_6 < V_2 -> V_39 + V_2 -> V_37 ;
++ V_6 ) {
if ( V_54 -> V_55 . V_11 == V_11 ) {
unsigned long V_112 ;
unsigned V_119 ;
F_26 ( & V_54 ->
V_55 . V_32 ,
V_112 ) ;
V_119 = V_6 -> V_120 -> V_121 ;
if ( V_54 -> V_55 . V_59 ) {
unsigned V_122 =
( ( V_113 >>
V_54 -> V_55 . V_57 )
&
( ( 0x1 << V_54 ->
V_55 .
V_58 ) -
1 ) ) << V_54 ->
V_55 . V_56 ;
if ( V_122 &
V_54 -> V_55 . V_123 )
{
unsigned int V_124
= 0 ;
unsigned int V_81 ,
V_125 , V_126 ;
V_126 =
V_6 ->
V_120 -> V_127 . V_128 ;
for ( V_81 = 0 ;
V_81 < V_126 ;
V_81 ++ ) {
V_125 = F_22 ( V_6 -> V_120 -> V_127 . V_129 [ V_81 ] ) ;
if ( V_122 & ( 1U << V_125 ) ) {
V_124 |= ( 1U << V_81 ) ;
}
}
if ( F_28 ( V_6 -> V_120 , ( ( short * ) & V_124 ) [ 0 ] )
&&
F_28
( V_6 -> V_120 ,
( ( short * )
& V_124 ) [ 1 ] ) )
{
V_6 -> V_120 -> V_121 |= ( V_130 | V_131 ) ;
} else {
F_29
( V_2 ,
V_6 ) ;
}
if ( ! V_54 -> V_55 . V_132 ) {
if ( V_54 -> V_55 . V_66 > 0 ) {
V_54 -> V_55 . V_66 -- ;
if ( V_54 -> V_55 . V_66 == 0 ) {
V_6 -> V_120 -> V_121 |= V_133 ;
F_29
( V_2 ,
V_6 ) ;
}
}
}
}
}
F_27
( & V_54 -> V_55 . V_32 ,
V_112 ) ;
if ( V_119 !=
V_6 -> V_120 -> V_121 ) {
F_30 ( V_2 , V_6 ) ;
}
}
}
}
}
}
if ( ! V_111 )
return V_134 ;
return V_135 ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
int V_136 , V_137 , V_11 , V_10 ;
V_11 = V_54 -> V_55 . V_11 ;
if ( V_11 < 0 )
return;
V_54 -> V_55 . V_123 = 0 ;
V_54 -> V_55 . V_59 = 0 ;
V_6 -> V_120 -> V_138 = 0 ;
V_136 = V_54 -> V_55 . V_58 / V_64 ;
V_137 = V_54 -> V_55 . V_57 / V_64 ;
F_23 ( V_2 , V_11 , V_139 ) ;
for ( V_10 = V_137 ; V_10 < V_137 + V_136 ; ++ V_10 ) {
F_21 ( 0 , V_29 -> V_30 [ V_11 ] . V_13 + V_140 + V_10 ) ;
}
}
static int F_31 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
if ( ! V_54 -> V_55 . V_132 && V_54 -> V_55 . V_66 == 0 ) {
V_6 -> V_120 -> V_121 |= V_133 ;
V_54 -> V_55 . V_59 = 0 ;
return 1 ;
} else {
unsigned V_141 = 0 , V_142 = 0 , V_81 ;
int V_136 , V_137 , V_11 , V_10 ;
struct V_143 * V_127 = & V_6 -> V_120 -> V_127 ;
V_11 = V_54 -> V_55 . V_11 ;
if ( V_11 < 0 )
return 1 ;
V_54 -> V_55 . V_123 = 0 ;
V_54 -> V_55 . V_59 = 1 ;
V_136 = V_54 -> V_55 . V_58 / V_64 ;
V_137 = V_54 -> V_55 . V_57 / V_64 ;
if ( V_127 -> V_129 ) {
for ( V_81 = 0 ; V_81 < V_127 -> V_128 ; V_81 ++ ) {
V_141 |= ( 1U << F_22 ( V_127 -> V_129 [ V_81 ] ) ) ;
V_142 |= ( F_32 ( V_127 -> V_129 [ V_81 ] )
|| F_33 ( V_127 ->
V_129 [ V_81 ] ) ? 1U : 0U )
<< F_22 ( V_127 -> V_129 [ V_81 ] ) ;
}
}
V_141 &= ( ( 0x1 << V_54 -> V_55 . V_58 ) -
1 ) << V_54 -> V_55 . V_56 ;
V_54 -> V_55 . V_123 = V_141 ;
F_23 ( V_2 , V_11 , V_139 ) ;
for ( V_10 = V_137 ; V_10 < V_137 + V_136 ; ++ V_10 ) {
unsigned V_144 =
V_141 >> ( V_54 -> V_55 . V_56 + ( V_10 -
V_137 ) *
8 ) & 0xff , V_145 =
V_142 >> ( V_54 -> V_55 . V_56 +
( V_10 - V_137 ) * 8 ) & 0xff ;
F_21 ( V_144 ,
V_29 -> V_30 [ V_11 ] . V_13 + V_140 + V_10 ) ;
F_23 ( V_2 , V_11 , V_146 ) ;
F_21 ( V_145 ,
V_29 -> V_30 [ V_11 ] . V_13 + V_140 + V_10 ) ;
}
}
return 0 ;
}
static int V_70 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
unsigned long V_112 ;
F_26 ( & V_54 -> V_55 . V_32 , V_112 ) ;
if ( V_54 -> V_55 . V_59 )
F_29 ( V_2 , V_6 ) ;
F_27 ( & V_54 -> V_55 . V_32 , V_112 ) ;
return 0 ;
}
static int
F_34 ( struct V_1 * V_2 , struct V_5 * V_6 ,
unsigned int V_147 )
{
unsigned long V_112 ;
int V_148 = 0 ;
if ( V_147 != 0 )
return - V_82 ;
F_26 ( & V_54 -> V_55 . V_32 , V_112 ) ;
V_6 -> V_120 -> V_138 = 0 ;
if ( V_54 -> V_55 . V_59 )
V_148 = F_31 ( V_2 , V_6 ) ;
F_27 ( & V_54 -> V_55 . V_32 , V_112 ) ;
if ( V_148 )
F_30 ( V_2 , V_6 ) ;
return 1 ;
}
static int V_72 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_143 * V_127 = & V_6 -> V_120 -> V_127 ;
unsigned long V_112 ;
int V_148 = 0 ;
F_26 ( & V_54 -> V_55 . V_32 , V_112 ) ;
V_54 -> V_55 . V_59 = 1 ;
switch ( V_127 -> V_149 ) {
case V_150 :
V_54 -> V_55 . V_132 = 0 ;
V_54 -> V_55 . V_66 = V_127 -> V_151 ;
break;
default:
V_54 -> V_55 . V_132 = 1 ;
V_54 -> V_55 . V_66 = 0 ;
break;
}
switch ( V_127 -> V_152 ) {
case V_153 :
V_6 -> V_120 -> V_138 = F_34 ;
break;
default:
V_148 = F_31 ( V_2 , V_6 ) ;
break;
}
F_27 ( & V_54 -> V_55 . V_32 , V_112 ) ;
if ( V_148 )
F_30 ( V_2 , V_6 ) ;
return 0 ;
}
static int
V_74 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_143 * V_127 )
{
return F_35 ( V_2 , V_6 , V_127 ) ;
}
static int T_2 F_36 ( void )
{
return F_37 ( & V_19 ) ;
}
static void T_3 F_38 ( void )
{
F_39 ( & V_19 ) ;
}

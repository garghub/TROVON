static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 ;
#ifdef F_2
F_3 ( V_2 -> V_9 , L_1 , V_7 [ 0 ] ,
V_7 [ 1 ] ) ;
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
F_5
( L_2 ,
V_8 , ( unsigned ) V_18 , ( unsigned ) V_19 ,
V_16 , V_13 , ( unsigned ) V_17 ) ;
#endif
if ( V_18 ) {
V_17 &= ~ V_18 ;
V_17 |= ~ V_19 & V_18 ;
F_6 ( V_17 , V_13 ) ;
}
#ifdef F_2
F_3 ( V_2 -> V_9 , L_3 , ( unsigned ) V_17 ) ;
#endif
V_4 -> V_10 |= ( ( unsigned int ) V_17 ) << V_16 ;
}
V_7 [ 1 ] = ~ V_4 -> V_10 ;
#ifdef F_2
F_3 ( V_2 -> V_9 , L_4 , V_4 -> V_10 ,
V_7 [ 1 ] ) ;
#endif
return V_6 -> V_20 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_21 = F_8 ( V_6 -> V_22 ) , V_8 = V_21 / 8 , V_23 =
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
F_6 ( V_17 , V_13 ) ;
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
static void F_9 ( struct V_1 * V_2 , int V_31 , int V_32 )
{
const struct V_33 * V_34 = F_10 ( V_2 ) ;
if ( V_31 < 0 || V_31 >= V_34 -> V_35 )
return;
if ( V_32 < 0 || V_32 >= V_36 )
return;
V_37 -> V_38 [ V_31 ] . V_39 &= ~ V_40 ;
V_37 -> V_38 [ V_31 ] . V_39 |= V_32 << V_41 ;
F_6 ( V_37 -> V_38 [ V_31 ] . V_39 ,
V_2 -> V_42 + V_43 * V_31 + V_44 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
const struct V_33 * V_34 = F_10 ( V_2 ) ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_34 -> V_35 ; ++ V_31 ) {
int V_45 , V_32 ;
unsigned long V_46 = V_2 -> V_42 + V_31 * V_43 ;
F_9 ( V_2 , V_31 , 0 ) ;
for ( V_45 = 0 ; V_45 < V_47 ; ++ V_45 )
F_6 ( 0 , V_46 + V_48 + V_45 ) ;
for ( V_32 = 1 ; V_32 < V_36 ; ++ V_32 ) {
int V_49 ;
F_9 ( V_2 , V_31 , V_32 ) ;
for ( V_49 = V_50 ;
V_49 < V_50 + V_51 ; ++ V_49 )
F_6 ( 0 , V_46 + V_49 ) ;
}
F_9 ( V_2 , V_31 , 0 ) ;
}
}
static void F_12 ( struct V_1 * V_2 , int V_31 , int V_45 )
{
const struct V_33 * V_34 = F_10 ( V_2 ) ;
if ( V_31 < 0 || V_31 >= V_34 -> V_35 )
return;
if ( V_45 < 0 || V_45 >= V_47 )
return;
V_37 -> V_38 [ V_31 ] . V_39 |= 0x1 << V_45 ;
F_6 ( V_37 -> V_38 [ V_31 ] . V_39 ,
V_2 -> V_42 + V_43 * V_31 + V_44 ) ;
}
static void F_13 ( struct V_1 * V_2 , int V_31 , int V_45 )
{
const struct V_33 * V_34 = F_10 ( V_2 ) ;
if ( V_31 < 0 || V_31 >= V_34 -> V_35 )
return;
if ( V_45 < 0 || V_45 >= V_47 )
return;
V_37 -> V_38 [ V_31 ] . V_39 &= ~ ( 0x1 << V_45 ) | V_52 ;
F_6 ( V_37 -> V_38 [ V_31 ] . V_39 ,
V_2 -> V_42 + V_43 * V_31 + V_44 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_53 , V_54 , V_31 , V_45 ;
V_31 = V_14 -> V_55 . V_31 ;
if ( V_31 < 0 )
return;
V_14 -> V_55 . V_56 = 0 ;
V_14 -> V_55 . V_57 = 0 ;
V_4 -> V_58 -> V_59 = 0 ;
V_53 = V_14 -> V_55 . V_60 / V_12 ;
V_54 = V_14 -> V_55 . V_61 / V_12 ;
F_9 ( V_2 , V_31 , V_62 ) ;
for ( V_45 = V_54 ; V_45 < V_54 + V_53 ; ++ V_45 ) {
F_6 ( 0 , V_37 -> V_38 [ V_31 ] . V_42 + V_63 + V_45 ) ;
}
}
static T_1 F_15 ( int V_64 , void * V_65 )
{
int V_31 , V_66 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_65 ;
for ( V_31 = 0 ; V_31 < V_67 ; ++ V_31 ) {
if ( V_64 == V_37 -> V_38 [ V_31 ] . V_64 ) {
unsigned long V_68 ;
unsigned V_69 = 0 ;
unsigned long V_42 = V_37 -> V_38 [ V_31 ] . V_42 ;
unsigned char V_70 ;
F_16 ( & V_37 -> V_38 [ V_31 ] . V_71 ,
V_68 ) ;
V_70 = F_4 ( V_42 + V_72 ) & 0x07 ;
if ( V_70 ) {
int V_45 ;
for ( V_45 = 0 ; V_45 < V_73 ;
++ V_45 ) {
if ( V_70 & ( 0x1 << V_45 ) ) {
unsigned char
V_74 = 0 ;
F_9 ( V_2 , V_31 ,
V_75 ) ;
V_74 =
F_4 ( V_42 +
V_76 + V_45 ) ;
if ( V_74 )
F_6 ( 0 , V_42 +
V_76 +
V_45 ) ;
V_69 |=
V_74 <<
V_45 * 8 ;
}
}
++ V_66 ;
}
F_17 ( & V_37 -> V_38 [ V_31 ] . V_71 ,
V_68 ) ;
if ( V_69 ) {
struct V_3 * V_4 ;
F_5
( L_5 ,
V_64 , V_31 , V_69 ) ;
for ( V_4 = V_2 -> V_77 ;
V_4 < V_2 -> V_77 + V_2 -> V_78 ;
++ V_4 ) {
if ( V_14 -> V_55 . V_31 == V_31 ) {
unsigned long V_68 ;
unsigned V_79 ;
F_16 ( & V_14 ->
V_55 . V_71 ,
V_68 ) ;
V_79 = V_4 -> V_58 -> V_80 ;
if ( V_14 -> V_55 . V_57 ) {
unsigned V_81 =
( ( V_69 >>
V_14 -> V_55 . V_61 )
&
( ( 0x1 << V_14 ->
V_55 .
V_60 ) -
1 ) ) << V_14 ->
V_55 . V_82 ;
if ( V_81 &
V_14 -> V_55 . V_56 )
{
unsigned int V_83
= 0 ;
unsigned int V_20 ,
V_84 , V_85 ;
V_85 =
V_4 ->
V_58 -> V_86 . V_87 ;
for ( V_20 = 0 ;
V_20 < V_85 ;
V_20 ++ ) {
V_84 = F_8 ( V_4 -> V_58 -> V_86 . V_88 [ V_20 ] ) ;
if ( V_81 & ( 1U << V_84 ) ) {
V_83 |= ( 1U << V_20 ) ;
}
}
if ( F_18 ( V_4 -> V_58 , ( ( short * ) & V_83 ) [ 0 ] )
&&
F_18
( V_4 -> V_58 ,
( ( short * )
& V_83 ) [ 1 ] ) )
{
V_4 -> V_58 -> V_80 |= ( V_89 | V_90 ) ;
} else {
F_14
( V_2 ,
V_4 ) ;
}
if ( ! V_14 -> V_55 . V_91 ) {
if ( V_14 -> V_55 . V_92 > 0 ) {
V_14 -> V_55 . V_92 -- ;
if ( V_14 -> V_55 . V_92 == 0 ) {
V_4 -> V_58 -> V_80 |= V_93 ;
F_14
( V_2 ,
V_4 ) ;
}
}
}
}
}
F_17
( & V_14 -> V_55 . V_71 ,
V_68 ) ;
if ( V_79 !=
V_4 -> V_58 -> V_80 ) {
F_19 ( V_2 , V_4 ) ;
}
}
}
}
}
}
if ( ! V_66 )
return V_94 ;
return V_95 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( ! V_14 -> V_55 . V_91 && V_14 -> V_55 . V_92 == 0 ) {
V_4 -> V_58 -> V_80 |= V_93 ;
V_14 -> V_55 . V_57 = 0 ;
return 1 ;
} else {
unsigned V_96 = 0 , V_97 = 0 , V_20 ;
int V_53 , V_54 , V_31 , V_45 ;
struct V_98 * V_86 = & V_4 -> V_58 -> V_86 ;
V_31 = V_14 -> V_55 . V_31 ;
if ( V_31 < 0 )
return 1 ;
V_14 -> V_55 . V_56 = 0 ;
V_14 -> V_55 . V_57 = 1 ;
V_53 = V_14 -> V_55 . V_60 / V_12 ;
V_54 = V_14 -> V_55 . V_61 / V_12 ;
if ( V_86 -> V_88 ) {
for ( V_20 = 0 ; V_20 < V_86 -> V_87 ; V_20 ++ ) {
V_96 |= ( 1U << F_8 ( V_86 -> V_88 [ V_20 ] ) ) ;
V_97 |= ( F_21 ( V_86 -> V_88 [ V_20 ] )
|| F_22 ( V_86 ->
V_88 [ V_20 ] ) ? 1U : 0U )
<< F_8 ( V_86 -> V_88 [ V_20 ] ) ;
}
}
V_96 &= ( ( 0x1 << V_14 -> V_55 . V_60 ) -
1 ) << V_14 -> V_55 . V_82 ;
V_14 -> V_55 . V_56 = V_96 ;
F_9 ( V_2 , V_31 , V_62 ) ;
for ( V_45 = V_54 ; V_45 < V_54 + V_53 ; ++ V_45 ) {
unsigned V_99 =
V_96 >> ( V_14 -> V_55 . V_82 + ( V_45 -
V_54 ) *
8 ) & 0xff , V_100 =
V_97 >> ( V_14 -> V_55 . V_82 +
( V_45 - V_54 ) * 8 ) & 0xff ;
F_6 ( V_99 ,
V_37 -> V_38 [ V_31 ] . V_42 + V_63 + V_45 ) ;
F_9 ( V_2 , V_31 , V_101 ) ;
F_6 ( V_100 ,
V_37 -> V_38 [ V_31 ] . V_42 + V_63 + V_45 ) ;
}
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_68 ;
F_16 ( & V_14 -> V_55 . V_71 , V_68 ) ;
if ( V_14 -> V_55 . V_57 )
F_14 ( V_2 , V_4 ) ;
F_17 ( & V_14 -> V_55 . V_71 , V_68 ) ;
return 0 ;
}
static int
F_24 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_102 )
{
unsigned long V_68 ;
int V_103 = 0 ;
if ( V_102 != 0 )
return - V_30 ;
F_16 ( & V_14 -> V_55 . V_71 , V_68 ) ;
V_4 -> V_58 -> V_59 = 0 ;
if ( V_14 -> V_55 . V_57 )
V_103 = F_20 ( V_2 , V_4 ) ;
F_17 ( & V_14 -> V_55 . V_71 , V_68 ) ;
if ( V_103 )
F_19 ( V_2 , V_4 ) ;
return 1 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_98 * V_86 = & V_4 -> V_58 -> V_86 ;
unsigned long V_68 ;
int V_103 = 0 ;
F_16 ( & V_14 -> V_55 . V_71 , V_68 ) ;
V_14 -> V_55 . V_57 = 1 ;
switch ( V_86 -> V_104 ) {
case V_105 :
V_14 -> V_55 . V_91 = 0 ;
V_14 -> V_55 . V_92 = V_86 -> V_106 ;
break;
default:
V_14 -> V_55 . V_91 = 1 ;
V_14 -> V_55 . V_92 = 0 ;
break;
}
switch ( V_86 -> V_107 ) {
case V_108 :
V_4 -> V_58 -> V_59 = F_24 ;
break;
default:
V_103 = F_20 ( V_2 , V_4 ) ;
break;
}
F_17 ( & V_14 -> V_55 . V_71 , V_68 ) ;
if ( V_103 )
F_19 ( V_2 , V_4 ) ;
return 0 ;
}
static int
F_26 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_98 * V_86 )
{
return F_27 ( V_2 , V_4 , V_86 ) ;
}
static int F_28 ( struct V_1 * V_2 , struct V_109 * V_110 )
{
const struct V_33 * V_34 = F_10 ( V_2 ) ;
struct V_3 * V_4 ;
int V_111 , V_112 , V_113 , V_45 , V_31 , V_114 = 0 ;
unsigned long V_42 ;
unsigned int V_64 [ V_67 ] ;
int V_115 ;
V_42 = V_110 -> V_116 [ 0 ] ;
V_64 [ 0 ] = V_110 -> V_116 [ 1 ] ;
V_64 [ 1 ] = V_110 -> V_116 [ 2 ] ;
F_3 ( V_2 -> V_9 , L_6 ,
V_2 -> V_117 -> V_118 , V_42 ) ;
V_2 -> V_42 = V_42 ;
if ( ! V_42 || ! F_29 ( V_42 ,
V_34 -> V_35 * V_43 ,
V_2 -> V_117 -> V_118 ) ) {
F_30 ( V_2 -> V_9 , L_7 ) ;
return - V_119 ;
}
V_2 -> V_120 = V_34 -> V_121 ;
if ( F_31 ( V_2 , sizeof( struct V_122 ) ) < 0 ) {
F_32 ( V_2 -> V_9 ,
L_8 ) ;
return - V_123 ;
}
for ( V_31 = 0 ; V_31 < V_67 ; ++ V_31 ) {
V_37 -> V_38 [ V_31 ] . V_124 = V_31 ;
V_37 -> V_38 [ V_31 ] . V_42 = V_2 -> V_42 + V_31 * V_43 ;
V_37 -> V_38 [ V_31 ] . V_64 = 0 ;
F_33 ( & V_37 -> V_38 [ V_31 ] . V_71 ) ;
}
V_112 = V_125 * V_34 -> V_35 ;
V_113 = F_34 ( V_112 ) ;
V_37 -> V_126 =
F_35 ( V_113 , sizeof( struct V_127 ) ,
V_128 ) ;
if ( ! V_37 -> V_126 ) {
F_32 ( V_2 -> V_9 ,
L_9 ) ;
return - V_123 ;
}
V_115 = F_36 ( V_2 , V_113 ) ;
if ( V_115 )
return V_115 ;
V_45 = 0 ;
V_31 = 0 ;
for ( V_111 = 0 ; V_111 < ( int ) V_2 -> V_78 ; ++ V_111 ) {
int V_8 ;
V_4 = V_2 -> V_77 + V_111 ;
V_4 -> V_129 = V_37 -> V_126 + V_111 ;
V_4 -> V_130 = 1 ;
V_4 -> V_131 = & V_132 ;
V_4 -> V_133 = V_134 | V_135 ;
V_4 -> type = V_136 ;
V_4 -> V_137 = F_1 ;
V_4 -> V_138 = F_7 ;
V_4 -> V_11 = F_37 ( V_112 , V_139 ) ;
V_14 -> V_55 . V_31 = - 1 ;
V_14 -> V_55 . V_82 = - 1 ;
V_14 -> V_55 . V_61 = - 1 ;
V_14 -> V_55 . V_60 = - 1 ;
V_14 -> V_55 . V_57 = 0 ;
V_4 -> V_140 = 1 ;
for ( V_8 = 0 ; V_8 < V_141 ; ++ V_8 , ++ V_45 ) {
if ( V_45 >= V_47 ) {
V_45 = 0 ;
++ V_31 ;
V_114 = 0 ;
}
V_14 -> V_15 [ V_8 ] =
V_37 -> V_38 [ V_31 ] . V_42 + V_45 ;
if ( V_114 <
V_12 * V_73
&& V_14 -> V_55 . V_31 < 0 ) {
V_14 -> V_55 . V_31 = V_31 ;
V_14 -> V_55 . V_57 = 0 ;
V_14 -> V_55 . V_92 = 0 ;
V_14 -> V_55 . V_82 = V_8 * 8 ;
V_14 -> V_55 . V_61 = V_114 ;
V_14 -> V_55 . V_60 =
V_4 -> V_11 - V_14 -> V_55 . V_82 ;
V_2 -> V_142 = V_4 ;
V_4 -> V_133 |= V_143 ;
V_4 -> V_144 = F_23 ;
V_4 -> V_145 = F_25 ;
V_4 -> V_146 = F_26 ;
V_4 -> V_140 = V_14 -> V_55 . V_60 ;
}
V_114 += V_12 ;
}
F_33 ( & V_14 -> V_55 . V_71 ) ;
V_112 -= V_4 -> V_11 ;
if ( ! V_112 ) {
V_31 = 0 ;
V_45 = 0 ;
}
}
F_11 ( V_2 ) ;
for ( V_31 = 0 ; V_64 [ 0 ] && V_31 < V_67 ; ++ V_31 ) {
if ( V_64 [ V_31 ]
&& F_38 ( V_64 [ V_31 ] , F_15 ,
V_147 , V_34 -> V_121 , V_2 ) ) {
int V_148 ;
for ( V_148 = V_31 - 1 ; V_148 >= 0 ; -- V_148 ) {
F_39 ( V_64 [ V_148 ] , V_2 ) ;
V_37 -> V_38 [ V_148 ] . V_64 = V_64 [ V_148 ] = 0 ;
}
V_64 [ V_31 ] = 0 ;
}
V_37 -> V_38 [ V_31 ] . V_64 = V_64 [ V_31 ] ;
}
V_2 -> V_64 = V_64 [ 0 ] ;
if ( V_64 [ 0 ] ) {
F_3 ( V_2 -> V_9 , L_10 , V_64 [ 0 ] ) ;
if ( V_64 [ 1 ] && V_34 -> V_35 == 2 )
F_3 ( V_2 -> V_9 , L_11 ,
V_64 [ 1 ] ) ;
} else {
F_3 ( V_2 -> V_9 , L_12 ) ;
}
return 1 ;
}
static void F_40 ( struct V_1 * V_2 )
{
const struct V_33 * V_34 = F_10 ( V_2 ) ;
int V_148 ;
if ( V_2 -> V_42 )
F_41 ( V_2 -> V_42 , V_43 * V_34 -> V_35 ) ;
for ( V_148 = 0 ; V_148 < V_67 ; ++ V_148 ) {
if ( V_37 -> V_38 [ V_148 ] . V_64 )
F_39 ( V_37 -> V_38 [ V_148 ] . V_64 , V_2 ) ;
}
if ( V_37 && V_37 -> V_126 )
F_42 ( V_37 -> V_126 ) ;
}

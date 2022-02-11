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
V_4 -> V_58 -> V_59 = NULL ;
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
int V_67 ;
for ( V_31 = 0 ; V_31 < V_68 ; ++ V_31 ) {
if ( V_64 == V_37 -> V_38 [ V_31 ] . V_64 ) {
unsigned long V_69 ;
unsigned V_70 = 0 ;
unsigned long V_42 = V_37 -> V_38 [ V_31 ] . V_42 ;
unsigned char V_71 ;
F_16 ( & V_37 -> V_38 [ V_31 ] . V_72 ,
V_69 ) ;
V_71 = F_4 ( V_42 + V_73 ) & 0x07 ;
if ( V_71 ) {
int V_45 ;
for ( V_45 = 0 ; V_45 < V_74 ;
++ V_45 ) {
if ( V_71 & ( 0x1 << V_45 ) ) {
unsigned char
V_75 = 0 ;
F_9 ( V_2 , V_31 ,
V_76 ) ;
V_75 =
F_4 ( V_42 +
V_77 + V_45 ) ;
if ( V_75 )
F_6 ( 0 , V_42 +
V_77 +
V_45 ) ;
V_70 |=
V_75 <<
V_45 * 8 ;
}
}
++ V_66 ;
}
F_17 ( & V_37 -> V_38 [ V_31 ] . V_72 ,
V_69 ) ;
if ( V_70 ) {
struct V_3 * V_4 ;
F_5
( L_5 ,
V_64 , V_31 , V_70 ) ;
for ( V_67 = 0 ; V_67 < V_2 -> V_78 ; V_67 ++ ) {
V_4 = & V_2 -> V_79 [ V_67 ] ;
if ( V_14 -> V_55 . V_31 == V_31 ) {
unsigned long V_69 ;
unsigned V_80 ;
F_16 ( & V_14 ->
V_55 . V_72 ,
V_69 ) ;
V_80 = V_4 -> V_58 -> V_81 ;
if ( V_14 -> V_55 . V_57 ) {
unsigned V_82 =
( ( V_70 >>
V_14 -> V_55 . V_61 )
&
( ( 0x1 << V_14 ->
V_55 .
V_60 ) -
1 ) ) << V_14 ->
V_55 . V_83 ;
if ( V_82 &
V_14 -> V_55 . V_56 )
{
unsigned int V_84
= 0 ;
unsigned int V_20 ,
V_85 , V_86 ;
V_86 =
V_4 ->
V_58 -> V_87 . V_88 ;
for ( V_20 = 0 ;
V_20 < V_86 ;
V_20 ++ ) {
V_85 = F_8 ( V_4 -> V_58 -> V_87 . V_89 [ V_20 ] ) ;
if ( V_82 & ( 1U << V_85 ) ) {
V_84 |= ( 1U << V_20 ) ;
}
}
if ( F_18 ( V_4 -> V_58 , ( ( short * ) & V_84 ) [ 0 ] )
&&
F_18
( V_4 -> V_58 ,
( ( short * )
& V_84 ) [ 1 ] ) )
{
V_4 -> V_58 -> V_81 |= ( V_90 | V_91 ) ;
} else {
F_14
( V_2 ,
V_4 ) ;
}
if ( ! V_14 -> V_55 . V_92 ) {
if ( V_14 -> V_55 . V_93 > 0 ) {
V_14 -> V_55 . V_93 -- ;
if ( V_14 -> V_55 . V_93 == 0 ) {
V_4 -> V_58 -> V_81 |= V_94 ;
F_14
( V_2 ,
V_4 ) ;
}
}
}
}
}
F_17
( & V_14 -> V_55 . V_72 ,
V_69 ) ;
if ( V_80 !=
V_4 -> V_58 -> V_81 ) {
F_19 ( V_2 , V_4 ) ;
}
}
}
}
}
}
if ( ! V_66 )
return V_95 ;
return V_96 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( ! V_14 -> V_55 . V_92 && V_14 -> V_55 . V_93 == 0 ) {
V_4 -> V_58 -> V_81 |= V_94 ;
V_14 -> V_55 . V_57 = 0 ;
return 1 ;
} else {
unsigned V_97 = 0 , V_98 = 0 , V_20 ;
int V_53 , V_54 , V_31 , V_45 ;
struct V_99 * V_87 = & V_4 -> V_58 -> V_87 ;
V_31 = V_14 -> V_55 . V_31 ;
if ( V_31 < 0 )
return 1 ;
V_14 -> V_55 . V_56 = 0 ;
V_14 -> V_55 . V_57 = 1 ;
V_53 = V_14 -> V_55 . V_60 / V_12 ;
V_54 = V_14 -> V_55 . V_61 / V_12 ;
if ( V_87 -> V_89 ) {
for ( V_20 = 0 ; V_20 < V_87 -> V_88 ; V_20 ++ ) {
V_97 |= ( 1U << F_8 ( V_87 -> V_89 [ V_20 ] ) ) ;
V_98 |= ( F_21 ( V_87 -> V_89 [ V_20 ] )
|| F_22 ( V_87 ->
V_89 [ V_20 ] ) ? 1U : 0U )
<< F_8 ( V_87 -> V_89 [ V_20 ] ) ;
}
}
V_97 &= ( ( 0x1 << V_14 -> V_55 . V_60 ) -
1 ) << V_14 -> V_55 . V_83 ;
V_14 -> V_55 . V_56 = V_97 ;
F_9 ( V_2 , V_31 , V_62 ) ;
for ( V_45 = V_54 ; V_45 < V_54 + V_53 ; ++ V_45 ) {
unsigned V_100 =
V_97 >> ( V_14 -> V_55 . V_83 + ( V_45 -
V_54 ) *
8 ) & 0xff , V_101 =
V_98 >> ( V_14 -> V_55 . V_83 +
( V_45 - V_54 ) * 8 ) & 0xff ;
F_6 ( V_100 ,
V_37 -> V_38 [ V_31 ] . V_42 + V_63 + V_45 ) ;
F_9 ( V_2 , V_31 , V_102 ) ;
F_6 ( V_101 ,
V_37 -> V_38 [ V_31 ] . V_42 + V_63 + V_45 ) ;
}
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_69 ;
F_16 ( & V_14 -> V_55 . V_72 , V_69 ) ;
if ( V_14 -> V_55 . V_57 )
F_14 ( V_2 , V_4 ) ;
F_17 ( & V_14 -> V_55 . V_72 , V_69 ) ;
return 0 ;
}
static int
F_24 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_103 )
{
unsigned long V_69 ;
int V_104 = 0 ;
if ( V_103 != 0 )
return - V_30 ;
F_16 ( & V_14 -> V_55 . V_72 , V_69 ) ;
V_4 -> V_58 -> V_59 = NULL ;
if ( V_14 -> V_55 . V_57 )
V_104 = F_20 ( V_2 , V_4 ) ;
F_17 ( & V_14 -> V_55 . V_72 , V_69 ) ;
if ( V_104 )
F_19 ( V_2 , V_4 ) ;
return 1 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_99 * V_87 = & V_4 -> V_58 -> V_87 ;
unsigned long V_69 ;
int V_104 = 0 ;
F_16 ( & V_14 -> V_55 . V_72 , V_69 ) ;
V_14 -> V_55 . V_57 = 1 ;
switch ( V_87 -> V_105 ) {
case V_106 :
V_14 -> V_55 . V_92 = 0 ;
V_14 -> V_55 . V_93 = V_87 -> V_107 ;
break;
default:
V_14 -> V_55 . V_92 = 1 ;
V_14 -> V_55 . V_93 = 0 ;
break;
}
switch ( V_87 -> V_108 ) {
case V_109 :
V_4 -> V_58 -> V_59 = F_24 ;
break;
default:
V_104 = F_20 ( V_2 , V_4 ) ;
break;
}
F_17 ( & V_14 -> V_55 . V_72 , V_69 ) ;
if ( V_104 )
F_19 ( V_2 , V_4 ) ;
return 0 ;
}
static int
F_26 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_99 * V_87 )
{
return F_27 ( V_2 , V_4 , V_87 ) ;
}
static int F_28 ( struct V_1 * V_2 , struct V_110 * V_111 )
{
const struct V_33 * V_34 = F_10 ( V_2 ) ;
struct V_3 * V_4 ;
int V_112 , V_113 , V_114 , V_45 , V_31 , V_115 = 0 ;
unsigned long V_42 ;
unsigned int V_64 [ V_68 ] ;
int V_116 ;
V_42 = V_111 -> V_117 [ 0 ] ;
V_64 [ 0 ] = V_111 -> V_117 [ 1 ] ;
V_64 [ 1 ] = V_111 -> V_117 [ 2 ] ;
F_3 ( V_2 -> V_9 , L_6 ,
V_2 -> V_118 -> V_119 , V_42 ) ;
V_2 -> V_42 = V_42 ;
if ( ! V_42 || ! F_29 ( V_42 ,
V_34 -> V_35 * V_43 ,
V_2 -> V_118 -> V_119 ) ) {
F_30 ( V_2 -> V_9 , L_7 ) ;
return - V_120 ;
}
V_2 -> V_121 = V_34 -> V_122 ;
if ( F_31 ( V_2 , sizeof( struct V_123 ) ) < 0 ) {
F_32 ( V_2 -> V_9 ,
L_8 ) ;
return - V_124 ;
}
for ( V_31 = 0 ; V_31 < V_68 ; ++ V_31 ) {
V_37 -> V_38 [ V_31 ] . V_125 = V_31 ;
V_37 -> V_38 [ V_31 ] . V_42 = V_2 -> V_42 + V_31 * V_43 ;
V_37 -> V_38 [ V_31 ] . V_64 = 0 ;
F_33 ( & V_37 -> V_38 [ V_31 ] . V_72 ) ;
}
V_113 = V_126 * V_34 -> V_35 ;
V_114 = F_34 ( V_113 ) ;
V_37 -> V_127 =
F_35 ( V_114 , sizeof( struct V_128 ) ,
V_129 ) ;
if ( ! V_37 -> V_127 ) {
F_32 ( V_2 -> V_9 ,
L_9 ) ;
return - V_124 ;
}
V_116 = F_36 ( V_2 , V_114 ) ;
if ( V_116 )
return V_116 ;
V_45 = 0 ;
V_31 = 0 ;
for ( V_112 = 0 ; V_112 < ( int ) V_2 -> V_78 ; ++ V_112 ) {
int V_8 ;
V_4 = & V_2 -> V_79 [ V_112 ] ;
V_4 -> V_130 = & V_37 -> V_127 [ V_112 ] ;
V_4 -> V_131 = 1 ;
V_4 -> V_132 = & V_133 ;
V_4 -> V_134 = V_135 | V_136 ;
V_4 -> type = V_137 ;
V_4 -> V_138 = F_1 ;
V_4 -> V_139 = F_7 ;
V_4 -> V_11 = F_37 ( V_113 , V_140 ) ;
V_14 -> V_55 . V_31 = - 1 ;
V_14 -> V_55 . V_83 = - 1 ;
V_14 -> V_55 . V_61 = - 1 ;
V_14 -> V_55 . V_60 = - 1 ;
V_14 -> V_55 . V_57 = 0 ;
V_4 -> V_141 = 1 ;
for ( V_8 = 0 ; V_8 < V_142 ; ++ V_8 , ++ V_45 ) {
if ( V_45 >= V_47 ) {
V_45 = 0 ;
++ V_31 ;
V_115 = 0 ;
}
V_14 -> V_15 [ V_8 ] =
V_37 -> V_38 [ V_31 ] . V_42 + V_45 ;
if ( V_115 <
V_12 * V_74
&& V_14 -> V_55 . V_31 < 0 ) {
V_14 -> V_55 . V_31 = V_31 ;
V_14 -> V_55 . V_57 = 0 ;
V_14 -> V_55 . V_93 = 0 ;
V_14 -> V_55 . V_83 = V_8 * 8 ;
V_14 -> V_55 . V_61 = V_115 ;
V_14 -> V_55 . V_60 =
V_4 -> V_11 - V_14 -> V_55 . V_83 ;
V_2 -> V_143 = V_4 ;
V_4 -> V_134 |= V_144 ;
V_4 -> V_145 = F_23 ;
V_4 -> V_146 = F_25 ;
V_4 -> V_147 = F_26 ;
V_4 -> V_141 = V_14 -> V_55 . V_60 ;
}
V_115 += V_12 ;
}
F_33 ( & V_14 -> V_55 . V_72 ) ;
V_113 -= V_4 -> V_11 ;
if ( ! V_113 ) {
V_31 = 0 ;
V_45 = 0 ;
}
}
F_11 ( V_2 ) ;
for ( V_31 = 0 ; V_64 [ 0 ] && V_31 < V_68 ; ++ V_31 ) {
if ( V_64 [ V_31 ]
&& F_38 ( V_64 [ V_31 ] , F_15 ,
V_148 , V_34 -> V_122 , V_2 ) ) {
int V_67 ;
for ( V_67 = V_31 - 1 ; V_67 >= 0 ; -- V_67 ) {
F_39 ( V_64 [ V_67 ] , V_2 ) ;
V_37 -> V_38 [ V_67 ] . V_64 = V_64 [ V_67 ] = 0 ;
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
int V_67 ;
if ( V_2 -> V_42 )
F_41 ( V_2 -> V_42 , V_43 * V_34 -> V_35 ) ;
for ( V_67 = 0 ; V_67 < V_68 ; ++ V_67 ) {
if ( V_37 -> V_38 [ V_67 ] . V_64 )
F_39 ( V_37 -> V_38 [ V_67 ] . V_64 , V_2 ) ;
}
if ( V_37 && V_37 -> V_127 )
F_42 ( V_37 -> V_127 ) ;
}

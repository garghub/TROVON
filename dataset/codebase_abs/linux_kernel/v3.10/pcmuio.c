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
struct V_35 * V_36 = V_2 -> V_37 ;
if ( V_31 < 0 || V_31 >= V_34 -> V_38 )
return;
if ( V_32 < 0 || V_32 >= V_39 )
return;
V_36 -> V_40 [ V_31 ] . V_41 &= ~ V_42 ;
V_36 -> V_40 [ V_31 ] . V_41 |= V_32 << V_43 ;
F_6 ( V_36 -> V_40 [ V_31 ] . V_41 ,
V_2 -> V_44 + V_45 * V_31 + V_46 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
const struct V_33 * V_34 = F_10 ( V_2 ) ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_34 -> V_38 ; ++ V_31 ) {
int V_47 , V_32 ;
unsigned long V_48 = V_2 -> V_44 + V_31 * V_45 ;
F_9 ( V_2 , V_31 , 0 ) ;
for ( V_47 = 0 ; V_47 < V_49 ; ++ V_47 )
F_6 ( 0 , V_48 + V_50 + V_47 ) ;
for ( V_32 = 1 ; V_32 < V_39 ; ++ V_32 ) {
int V_51 ;
F_9 ( V_2 , V_31 , V_32 ) ;
for ( V_51 = V_52 ;
V_51 < V_52 + V_53 ; ++ V_51 )
F_6 ( 0 , V_48 + V_51 ) ;
}
F_9 ( V_2 , V_31 , 0 ) ;
}
}
static void F_12 ( struct V_1 * V_2 , int V_31 , int V_47 )
{
const struct V_33 * V_34 = F_10 ( V_2 ) ;
struct V_35 * V_36 = V_2 -> V_37 ;
if ( V_31 < 0 || V_31 >= V_34 -> V_38 )
return;
if ( V_47 < 0 || V_47 >= V_49 )
return;
V_36 -> V_40 [ V_31 ] . V_41 |= 0x1 << V_47 ;
F_6 ( V_36 -> V_40 [ V_31 ] . V_41 ,
V_2 -> V_44 + V_45 * V_31 + V_46 ) ;
}
static void F_13 ( struct V_1 * V_2 , int V_31 , int V_47 )
{
const struct V_33 * V_34 = F_10 ( V_2 ) ;
struct V_35 * V_36 = V_2 -> V_37 ;
if ( V_31 < 0 || V_31 >= V_34 -> V_38 )
return;
if ( V_47 < 0 || V_47 >= V_49 )
return;
V_36 -> V_40 [ V_31 ] . V_41 &= ~ ( 0x1 << V_47 ) | V_54 ;
F_6 ( V_36 -> V_40 [ V_31 ] . V_41 ,
V_2 -> V_44 + V_45 * V_31 + V_46 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_55 , V_56 , V_31 , V_47 ;
struct V_35 * V_36 = V_2 -> V_37 ;
V_31 = V_14 -> V_57 . V_31 ;
if ( V_31 < 0 )
return;
V_14 -> V_57 . V_58 = 0 ;
V_14 -> V_57 . V_59 = 0 ;
V_4 -> V_60 -> V_61 = NULL ;
V_55 = V_14 -> V_57 . V_62 / V_12 ;
V_56 = V_14 -> V_57 . V_63 / V_12 ;
F_9 ( V_2 , V_31 , V_64 ) ;
for ( V_47 = V_56 ; V_47 < V_56 + V_55 ; ++ V_47 ) {
F_6 ( 0 , V_36 -> V_40 [ V_31 ] . V_44 + V_65 + V_47 ) ;
}
}
static T_1 F_15 ( int V_66 , void * V_67 )
{
int V_31 , V_68 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_67 ;
struct V_35 * V_36 = V_2 -> V_37 ;
int V_69 ;
for ( V_31 = 0 ; V_31 < V_70 ; ++ V_31 ) {
if ( V_66 == V_36 -> V_40 [ V_31 ] . V_66 ) {
unsigned long V_71 ;
unsigned V_72 = 0 ;
unsigned long V_44 = V_36 -> V_40 [ V_31 ] . V_44 ;
unsigned char V_73 ;
F_16 ( & V_36 -> V_40 [ V_31 ] . V_74 ,
V_71 ) ;
V_73 = F_4 ( V_44 + V_75 ) & 0x07 ;
if ( V_73 ) {
int V_47 ;
for ( V_47 = 0 ; V_47 < V_76 ;
++ V_47 ) {
if ( V_73 & ( 0x1 << V_47 ) ) {
unsigned char
V_77 = 0 ;
F_9 ( V_2 , V_31 ,
V_78 ) ;
V_77 =
F_4 ( V_44 +
V_79 + V_47 ) ;
if ( V_77 )
F_6 ( 0 , V_44 +
V_79 +
V_47 ) ;
V_72 |=
V_77 <<
V_47 * 8 ;
}
}
++ V_68 ;
}
F_17 ( & V_36 -> V_40 [ V_31 ] . V_74 ,
V_71 ) ;
if ( V_72 ) {
struct V_3 * V_4 ;
F_5
( L_5 ,
V_66 , V_31 , V_72 ) ;
for ( V_69 = 0 ; V_69 < V_2 -> V_80 ; V_69 ++ ) {
V_4 = & V_2 -> V_81 [ V_69 ] ;
if ( V_14 -> V_57 . V_31 == V_31 ) {
unsigned long V_71 ;
unsigned V_82 ;
F_16 ( & V_14 ->
V_57 . V_74 ,
V_71 ) ;
V_82 = V_4 -> V_60 -> V_83 ;
if ( V_14 -> V_57 . V_59 ) {
unsigned V_84 =
( ( V_72 >>
V_14 -> V_57 . V_63 )
&
( ( 0x1 << V_14 ->
V_57 .
V_62 ) -
1 ) ) << V_14 ->
V_57 . V_85 ;
if ( V_84 &
V_14 -> V_57 . V_58 )
{
unsigned int V_86
= 0 ;
unsigned int V_20 ,
V_87 , V_88 ;
V_88 =
V_4 ->
V_60 -> V_89 . V_90 ;
for ( V_20 = 0 ;
V_20 < V_88 ;
V_20 ++ ) {
V_87 = F_8 ( V_4 -> V_60 -> V_89 . V_91 [ V_20 ] ) ;
if ( V_84 & ( 1U << V_87 ) ) {
V_86 |= ( 1U << V_20 ) ;
}
}
if ( F_18 ( V_4 -> V_60 , ( ( short * ) & V_86 ) [ 0 ] )
&&
F_18
( V_4 -> V_60 ,
( ( short * )
& V_86 ) [ 1 ] ) )
{
V_4 -> V_60 -> V_83 |= ( V_92 | V_93 ) ;
} else {
F_14
( V_2 ,
V_4 ) ;
}
if ( ! V_14 -> V_57 . V_94 ) {
if ( V_14 -> V_57 . V_95 > 0 ) {
V_14 -> V_57 . V_95 -- ;
if ( V_14 -> V_57 . V_95 == 0 ) {
V_4 -> V_60 -> V_83 |= V_96 ;
F_14
( V_2 ,
V_4 ) ;
}
}
}
}
}
F_17
( & V_14 -> V_57 . V_74 ,
V_71 ) ;
if ( V_82 !=
V_4 -> V_60 -> V_83 ) {
F_19 ( V_2 , V_4 ) ;
}
}
}
}
}
}
if ( ! V_68 )
return V_97 ;
return V_98 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_35 * V_36 = V_2 -> V_37 ;
if ( ! V_14 -> V_57 . V_94 && V_14 -> V_57 . V_95 == 0 ) {
V_4 -> V_60 -> V_83 |= V_96 ;
V_14 -> V_57 . V_59 = 0 ;
return 1 ;
} else {
unsigned V_99 = 0 , V_100 = 0 , V_20 ;
int V_55 , V_56 , V_31 , V_47 ;
struct V_101 * V_89 = & V_4 -> V_60 -> V_89 ;
V_31 = V_14 -> V_57 . V_31 ;
if ( V_31 < 0 )
return 1 ;
V_14 -> V_57 . V_58 = 0 ;
V_14 -> V_57 . V_59 = 1 ;
V_55 = V_14 -> V_57 . V_62 / V_12 ;
V_56 = V_14 -> V_57 . V_63 / V_12 ;
if ( V_89 -> V_91 ) {
for ( V_20 = 0 ; V_20 < V_89 -> V_90 ; V_20 ++ ) {
V_99 |= ( 1U << F_8 ( V_89 -> V_91 [ V_20 ] ) ) ;
V_100 |= ( F_21 ( V_89 -> V_91 [ V_20 ] )
|| F_22 ( V_89 ->
V_91 [ V_20 ] ) ? 1U : 0U )
<< F_8 ( V_89 -> V_91 [ V_20 ] ) ;
}
}
V_99 &= ( ( 0x1 << V_14 -> V_57 . V_62 ) -
1 ) << V_14 -> V_57 . V_85 ;
V_14 -> V_57 . V_58 = V_99 ;
F_9 ( V_2 , V_31 , V_64 ) ;
for ( V_47 = V_56 ; V_47 < V_56 + V_55 ; ++ V_47 ) {
unsigned V_102 =
V_99 >> ( V_14 -> V_57 . V_85 + ( V_47 -
V_56 ) *
8 ) & 0xff , V_103 =
V_100 >> ( V_14 -> V_57 . V_85 +
( V_47 - V_56 ) * 8 ) & 0xff ;
F_6 ( V_102 ,
V_36 -> V_40 [ V_31 ] . V_44 + V_65 + V_47 ) ;
F_9 ( V_2 , V_31 , V_104 ) ;
F_6 ( V_103 ,
V_36 -> V_40 [ V_31 ] . V_44 + V_65 + V_47 ) ;
}
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_71 ;
F_16 ( & V_14 -> V_57 . V_74 , V_71 ) ;
if ( V_14 -> V_57 . V_59 )
F_14 ( V_2 , V_4 ) ;
F_17 ( & V_14 -> V_57 . V_74 , V_71 ) ;
return 0 ;
}
static int
F_24 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_105 )
{
unsigned long V_71 ;
int V_106 = 0 ;
if ( V_105 != 0 )
return - V_30 ;
F_16 ( & V_14 -> V_57 . V_74 , V_71 ) ;
V_4 -> V_60 -> V_61 = NULL ;
if ( V_14 -> V_57 . V_59 )
V_106 = F_20 ( V_2 , V_4 ) ;
F_17 ( & V_14 -> V_57 . V_74 , V_71 ) ;
if ( V_106 )
F_19 ( V_2 , V_4 ) ;
return 1 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_101 * V_89 = & V_4 -> V_60 -> V_89 ;
unsigned long V_71 ;
int V_106 = 0 ;
F_16 ( & V_14 -> V_57 . V_74 , V_71 ) ;
V_14 -> V_57 . V_59 = 1 ;
switch ( V_89 -> V_107 ) {
case V_108 :
V_14 -> V_57 . V_94 = 0 ;
V_14 -> V_57 . V_95 = V_89 -> V_109 ;
break;
default:
V_14 -> V_57 . V_94 = 1 ;
V_14 -> V_57 . V_95 = 0 ;
break;
}
switch ( V_89 -> V_110 ) {
case V_111 :
V_4 -> V_60 -> V_61 = F_24 ;
break;
default:
V_106 = F_20 ( V_2 , V_4 ) ;
break;
}
F_17 ( & V_14 -> V_57 . V_74 , V_71 ) ;
if ( V_106 )
F_19 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_101 * V_89 )
{
int V_112 = 0 ;
V_112 |= F_27 ( & V_89 -> V_110 , V_113 | V_111 ) ;
V_112 |= F_27 ( & V_89 -> V_114 , V_115 ) ;
V_112 |= F_27 ( & V_89 -> V_116 , V_113 ) ;
V_112 |= F_27 ( & V_89 -> V_117 , V_108 ) ;
V_112 |= F_27 ( & V_89 -> V_107 , V_108 | V_118 ) ;
if ( V_112 )
return 1 ;
V_112 |= F_28 ( V_89 -> V_110 ) ;
V_112 |= F_28 ( V_89 -> V_107 ) ;
if ( V_112 )
return 2 ;
V_112 |= F_29 ( & V_89 -> V_119 , 0 ) ;
V_112 |= F_29 ( & V_89 -> V_120 , 0 ) ;
V_112 |= F_29 ( & V_89 -> V_121 , 0 ) ;
V_112 |= F_29 ( & V_89 -> V_122 , V_89 -> V_90 ) ;
switch ( V_89 -> V_107 ) {
case V_108 :
break;
case V_118 :
V_112 |= F_29 ( & V_89 -> V_109 , 0 ) ;
break;
default:
break;
}
if ( V_112 )
return 3 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , struct V_123 * V_124 )
{
const struct V_33 * V_34 = F_10 ( V_2 ) ;
struct V_35 * V_36 ;
struct V_3 * V_4 ;
int V_125 , V_126 , V_127 , V_47 , V_31 , V_128 = 0 ;
unsigned int V_66 [ V_70 ] ;
int V_129 ;
V_66 [ 0 ] = V_124 -> V_130 [ 1 ] ;
V_66 [ 1 ] = V_124 -> V_130 [ 2 ] ;
V_129 = F_31 ( V_2 , V_124 -> V_130 [ 0 ] ,
V_34 -> V_38 * V_45 ) ;
if ( V_129 )
return V_129 ;
V_36 = F_32 ( sizeof( * V_36 ) , V_131 ) ;
if ( ! V_36 )
return - V_132 ;
V_2 -> V_37 = V_36 ;
for ( V_31 = 0 ; V_31 < V_70 ; ++ V_31 ) {
V_36 -> V_40 [ V_31 ] . V_133 = V_31 ;
V_36 -> V_40 [ V_31 ] . V_44 = V_2 -> V_44 + V_31 * V_45 ;
V_36 -> V_40 [ V_31 ] . V_66 = 0 ;
F_33 ( & V_36 -> V_40 [ V_31 ] . V_74 ) ;
}
V_126 = V_134 * V_34 -> V_38 ;
V_127 = F_34 ( V_126 ) ;
V_36 -> V_135 = F_35 ( V_127 ,
sizeof( struct V_136 ) ,
V_131 ) ;
if ( ! V_36 -> V_135 )
return - V_132 ;
V_129 = F_36 ( V_2 , V_127 ) ;
if ( V_129 )
return V_129 ;
V_47 = 0 ;
V_31 = 0 ;
for ( V_125 = 0 ; V_125 < ( int ) V_2 -> V_80 ; ++ V_125 ) {
int V_8 ;
V_4 = & V_2 -> V_81 [ V_125 ] ;
V_4 -> V_37 = & V_36 -> V_135 [ V_125 ] ;
V_4 -> V_137 = 1 ;
V_4 -> V_138 = & V_139 ;
V_4 -> V_140 = V_141 | V_142 ;
V_4 -> type = V_143 ;
V_4 -> V_144 = F_1 ;
V_4 -> V_145 = F_7 ;
V_4 -> V_11 = F_37 ( V_126 , V_146 ) ;
V_14 -> V_57 . V_31 = - 1 ;
V_14 -> V_57 . V_85 = - 1 ;
V_14 -> V_57 . V_63 = - 1 ;
V_14 -> V_57 . V_62 = - 1 ;
V_14 -> V_57 . V_59 = 0 ;
V_4 -> V_147 = 1 ;
for ( V_8 = 0 ; V_8 < V_148 ; ++ V_8 , ++ V_47 ) {
if ( V_47 >= V_49 ) {
V_47 = 0 ;
++ V_31 ;
V_128 = 0 ;
}
V_14 -> V_15 [ V_8 ] =
V_36 -> V_40 [ V_31 ] . V_44 + V_47 ;
if ( V_128 <
V_12 * V_76
&& V_14 -> V_57 . V_31 < 0 ) {
V_14 -> V_57 . V_31 = V_31 ;
V_14 -> V_57 . V_59 = 0 ;
V_14 -> V_57 . V_95 = 0 ;
V_14 -> V_57 . V_85 = V_8 * 8 ;
V_14 -> V_57 . V_63 = V_128 ;
V_14 -> V_57 . V_62 =
V_4 -> V_11 - V_14 -> V_57 . V_85 ;
V_2 -> V_149 = V_4 ;
V_4 -> V_140 |= V_150 ;
V_4 -> V_151 = F_23 ;
V_4 -> V_152 = F_25 ;
V_4 -> V_153 = F_26 ;
V_4 -> V_147 = V_14 -> V_57 . V_62 ;
}
V_128 += V_12 ;
}
F_33 ( & V_14 -> V_57 . V_74 ) ;
V_126 -= V_4 -> V_11 ;
if ( ! V_126 ) {
V_31 = 0 ;
V_47 = 0 ;
}
}
F_11 ( V_2 ) ;
for ( V_31 = 0 ; V_66 [ 0 ] && V_31 < V_70 ; ++ V_31 ) {
if ( V_66 [ V_31 ]
&& F_38 ( V_66 [ V_31 ] , F_15 ,
V_154 , V_34 -> V_155 , V_2 ) ) {
int V_69 ;
for ( V_69 = V_31 - 1 ; V_69 >= 0 ; -- V_69 ) {
F_39 ( V_66 [ V_69 ] , V_2 ) ;
V_36 -> V_40 [ V_69 ] . V_66 = V_66 [ V_69 ] = 0 ;
}
V_66 [ V_31 ] = 0 ;
}
V_36 -> V_40 [ V_31 ] . V_66 = V_66 [ V_31 ] ;
}
if ( V_66 [ 0 ] ) {
F_3 ( V_2 -> V_9 , L_6 , V_66 [ 0 ] ) ;
if ( V_66 [ 1 ] && V_34 -> V_38 == 2 )
F_3 ( V_2 -> V_9 , L_7 ,
V_66 [ 1 ] ) ;
} else {
F_3 ( V_2 -> V_9 , L_8 ) ;
}
return 1 ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = V_2 -> V_37 ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_70 ; ++ V_69 ) {
if ( V_36 -> V_40 [ V_69 ] . V_66 )
F_39 ( V_36 -> V_40 [ V_69 ] . V_66 , V_2 ) ;
}
if ( V_36 && V_36 -> V_135 )
F_41 ( V_36 -> V_135 ) ;
F_42 ( V_2 ) ;
}

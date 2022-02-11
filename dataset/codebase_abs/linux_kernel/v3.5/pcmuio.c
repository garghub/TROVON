static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 ;
if ( V_6 -> V_9 != 2 )
return - V_10 ;
#ifdef F_2
F_3 ( V_2 -> V_11 , L_1 , V_7 [ 0 ] ,
V_7 [ 1 ] ) ;
#endif
V_4 -> V_12 = 0 ;
for ( V_8 = 0 ; V_8 < V_4 -> V_13 / V_14 ; ++ V_8 ) {
unsigned long V_15 = V_16 -> V_17 [ V_8 ] ,
V_18 = V_8 * 8 ;
unsigned char V_19 = 0 ,
V_20 = ( V_7 [ 0 ] >> V_18 ) & 0xff ,
V_21 = ( V_7 [ 1 ] >> V_18 ) & 0xff ;
V_19 = F_4 ( V_15 ) ;
#ifdef F_2
F_5
( L_2 ,
V_8 , ( unsigned ) V_20 , ( unsigned ) V_21 ,
V_18 , V_15 , ( unsigned ) V_19 ) ;
#endif
if ( V_20 ) {
V_19 &= ~ V_20 ;
V_19 |= ~ V_21 & V_20 ;
F_6 ( V_19 , V_15 ) ;
}
#ifdef F_2
F_3 ( V_2 -> V_11 , L_3 , ( unsigned ) V_19 ) ;
#endif
V_4 -> V_12 |= ( ( unsigned int ) V_19 ) << V_18 ;
}
V_7 [ 1 ] = ~ V_4 -> V_12 ;
#ifdef F_2
F_3 ( V_2 -> V_11 , L_4 , V_4 -> V_12 ,
V_7 [ 1 ] ) ;
#endif
return 2 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_22 = F_8 ( V_6 -> V_23 ) , V_8 = V_22 / 8 , V_24 =
V_22 % 8 ;
unsigned long V_15 ;
unsigned char V_19 ;
V_15 = V_16 -> V_17 [ V_8 ] ;
switch ( V_7 [ 0 ] ) {
case V_25 :
V_4 -> V_26 |= 1 << V_22 ;
break;
case V_27 :
V_19 = F_4 ( V_15 ) ;
V_19 &= ~ ( 1 << V_24 ) ;
F_6 ( V_19 , V_15 ) ;
V_4 -> V_26 &= ~ ( 1 << V_22 ) ;
break;
case V_28 :
V_7 [ 1 ] =
( V_4 -> V_26 & ( 1 << V_22 ) ) ? V_29 : V_30 ;
return V_6 -> V_9 ;
break;
default:
return - V_10 ;
break;
}
return V_6 -> V_9 ;
}
static void F_9 ( struct V_1 * V_2 , int V_31 , int V_32 )
{
if ( V_31 < 0 || V_31 >= V_33 -> V_34 )
return;
if ( V_32 < 0 || V_32 >= V_35 )
return;
V_36 -> V_37 [ V_31 ] . V_38 &= ~ V_39 ;
V_36 -> V_37 [ V_31 ] . V_38 |= V_32 << V_40 ;
F_6 ( V_36 -> V_37 [ V_31 ] . V_38 ,
V_2 -> V_41 + V_42 * V_31 + V_43 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_33 -> V_34 ; ++ V_31 ) {
int V_44 , V_32 ;
unsigned long V_45 = V_2 -> V_41 + V_31 * V_42 ;
F_9 ( V_2 , V_31 , 0 ) ;
for ( V_44 = 0 ; V_44 < V_46 ; ++ V_44 )
F_6 ( 0 , V_45 + V_47 + V_44 ) ;
for ( V_32 = 1 ; V_32 < V_35 ; ++ V_32 ) {
int V_48 ;
F_9 ( V_2 , V_31 , V_32 ) ;
for ( V_48 = V_49 ;
V_48 < V_49 + V_50 ; ++ V_48 )
F_6 ( 0 , V_45 + V_48 ) ;
}
F_9 ( V_2 , V_31 , 0 ) ;
}
}
static void F_11 ( struct V_1 * V_2 , int V_31 , int V_44 )
{
if ( V_31 < 0 || V_31 >= V_33 -> V_34 )
return;
if ( V_44 < 0 || V_44 >= V_46 )
return;
V_36 -> V_37 [ V_31 ] . V_38 |= 0x1 << V_44 ;
F_6 ( V_36 -> V_37 [ V_31 ] . V_38 ,
V_2 -> V_41 + V_42 * V_31 + V_43 ) ;
}
static void F_12 ( struct V_1 * V_2 , int V_31 , int V_44 )
{
if ( V_31 < 0 || V_31 >= V_33 -> V_34 )
return;
if ( V_44 < 0 || V_44 >= V_46 )
return;
V_36 -> V_37 [ V_31 ] . V_38 &= ~ ( 0x1 << V_44 ) | V_51 ;
F_6 ( V_36 -> V_37 [ V_31 ] . V_38 ,
V_2 -> V_41 + V_42 * V_31 + V_43 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_52 , V_53 , V_31 , V_44 ;
V_31 = V_16 -> V_54 . V_31 ;
if ( V_31 < 0 )
return;
V_16 -> V_54 . V_55 = 0 ;
V_16 -> V_54 . V_56 = 0 ;
V_4 -> V_57 -> V_58 = 0 ;
V_52 = V_16 -> V_54 . V_59 / V_14 ;
V_53 = V_16 -> V_54 . V_60 / V_14 ;
F_9 ( V_2 , V_31 , V_61 ) ;
for ( V_44 = V_53 ; V_44 < V_53 + V_52 ; ++ V_44 ) {
F_6 ( 0 , V_36 -> V_37 [ V_31 ] . V_41 + V_62 + V_44 ) ;
}
}
static T_1 F_14 ( int V_63 , void * V_64 )
{
int V_31 , V_65 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_64 ;
for ( V_31 = 0 ; V_31 < V_66 ; ++ V_31 ) {
if ( V_63 == V_36 -> V_37 [ V_31 ] . V_63 ) {
unsigned long V_67 ;
unsigned V_68 = 0 ;
unsigned long V_41 = V_36 -> V_37 [ V_31 ] . V_41 ;
unsigned char V_69 ;
F_15 ( & V_36 -> V_37 [ V_31 ] . V_70 ,
V_67 ) ;
V_69 = F_4 ( V_41 + V_71 ) & 0x07 ;
if ( V_69 ) {
int V_44 ;
for ( V_44 = 0 ; V_44 < V_72 ;
++ V_44 ) {
if ( V_69 & ( 0x1 << V_44 ) ) {
unsigned char
V_73 = 0 ;
F_9 ( V_2 , V_31 ,
V_74 ) ;
V_73 =
F_4 ( V_41 +
V_75 + V_44 ) ;
if ( V_73 )
F_6 ( 0 , V_41 +
V_75 +
V_44 ) ;
V_68 |=
V_73 <<
V_44 * 8 ;
}
}
++ V_65 ;
}
F_16 ( & V_36 -> V_37 [ V_31 ] . V_70 ,
V_67 ) ;
if ( V_68 ) {
struct V_3 * V_4 ;
F_5
( L_5 ,
V_63 , V_31 , V_68 ) ;
for ( V_4 = V_2 -> V_76 ;
V_4 < V_2 -> V_76 + V_2 -> V_77 ;
++ V_4 ) {
if ( V_16 -> V_54 . V_31 == V_31 ) {
unsigned long V_67 ;
unsigned V_78 ;
F_15 ( & V_16 ->
V_54 . V_70 ,
V_67 ) ;
V_78 = V_4 -> V_57 -> V_79 ;
if ( V_16 -> V_54 . V_56 ) {
unsigned V_80 =
( ( V_68 >>
V_16 -> V_54 . V_60 )
&
( ( 0x1 << V_16 ->
V_54 .
V_59 ) -
1 ) ) << V_16 ->
V_54 . V_81 ;
if ( V_80 &
V_16 -> V_54 . V_55 )
{
unsigned int V_82
= 0 ;
unsigned int V_9 ,
V_83 , V_84 ;
V_84 =
V_4 ->
V_57 -> V_85 . V_86 ;
for ( V_9 = 0 ;
V_9 < V_84 ;
V_9 ++ ) {
V_83 = F_8 ( V_4 -> V_57 -> V_85 . V_87 [ V_9 ] ) ;
if ( V_80 & ( 1U << V_83 ) ) {
V_82 |= ( 1U << V_9 ) ;
}
}
if ( F_17 ( V_4 -> V_57 , ( ( short * ) & V_82 ) [ 0 ] )
&&
F_17
( V_4 -> V_57 ,
( ( short * )
& V_82 ) [ 1 ] ) )
{
V_4 -> V_57 -> V_79 |= ( V_88 | V_89 ) ;
} else {
F_13
( V_2 ,
V_4 ) ;
}
if ( ! V_16 -> V_54 . V_90 ) {
if ( V_16 -> V_54 . V_91 > 0 ) {
V_16 -> V_54 . V_91 -- ;
if ( V_16 -> V_54 . V_91 == 0 ) {
V_4 -> V_57 -> V_79 |= V_92 ;
F_13
( V_2 ,
V_4 ) ;
}
}
}
}
}
F_16
( & V_16 -> V_54 . V_70 ,
V_67 ) ;
if ( V_78 !=
V_4 -> V_57 -> V_79 ) {
F_18 ( V_2 , V_4 ) ;
}
}
}
}
}
}
if ( ! V_65 )
return V_93 ;
return V_94 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( ! V_16 -> V_54 . V_90 && V_16 -> V_54 . V_91 == 0 ) {
V_4 -> V_57 -> V_79 |= V_92 ;
V_16 -> V_54 . V_56 = 0 ;
return 1 ;
} else {
unsigned V_95 = 0 , V_96 = 0 , V_9 ;
int V_52 , V_53 , V_31 , V_44 ;
struct V_97 * V_85 = & V_4 -> V_57 -> V_85 ;
V_31 = V_16 -> V_54 . V_31 ;
if ( V_31 < 0 )
return 1 ;
V_16 -> V_54 . V_55 = 0 ;
V_16 -> V_54 . V_56 = 1 ;
V_52 = V_16 -> V_54 . V_59 / V_14 ;
V_53 = V_16 -> V_54 . V_60 / V_14 ;
if ( V_85 -> V_87 ) {
for ( V_9 = 0 ; V_9 < V_85 -> V_86 ; V_9 ++ ) {
V_95 |= ( 1U << F_8 ( V_85 -> V_87 [ V_9 ] ) ) ;
V_96 |= ( F_20 ( V_85 -> V_87 [ V_9 ] )
|| F_21 ( V_85 ->
V_87 [ V_9 ] ) ? 1U : 0U )
<< F_8 ( V_85 -> V_87 [ V_9 ] ) ;
}
}
V_95 &= ( ( 0x1 << V_16 -> V_54 . V_59 ) -
1 ) << V_16 -> V_54 . V_81 ;
V_16 -> V_54 . V_55 = V_95 ;
F_9 ( V_2 , V_31 , V_61 ) ;
for ( V_44 = V_53 ; V_44 < V_53 + V_52 ; ++ V_44 ) {
unsigned V_98 =
V_95 >> ( V_16 -> V_54 . V_81 + ( V_44 -
V_53 ) *
8 ) & 0xff , V_99 =
V_96 >> ( V_16 -> V_54 . V_81 +
( V_44 - V_53 ) * 8 ) & 0xff ;
F_6 ( V_98 ,
V_36 -> V_37 [ V_31 ] . V_41 + V_62 + V_44 ) ;
F_9 ( V_2 , V_31 , V_100 ) ;
F_6 ( V_99 ,
V_36 -> V_37 [ V_31 ] . V_41 + V_62 + V_44 ) ;
}
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_67 ;
F_15 ( & V_16 -> V_54 . V_70 , V_67 ) ;
if ( V_16 -> V_54 . V_56 )
F_13 ( V_2 , V_4 ) ;
F_16 ( & V_16 -> V_54 . V_70 , V_67 ) ;
return 0 ;
}
static int
F_23 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_101 )
{
unsigned long V_67 ;
int V_102 = 0 ;
if ( V_101 != 0 )
return - V_10 ;
F_15 ( & V_16 -> V_54 . V_70 , V_67 ) ;
V_4 -> V_57 -> V_58 = 0 ;
if ( V_16 -> V_54 . V_56 )
V_102 = F_19 ( V_2 , V_4 ) ;
F_16 ( & V_16 -> V_54 . V_70 , V_67 ) ;
if ( V_102 )
F_18 ( V_2 , V_4 ) ;
return 1 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_97 * V_85 = & V_4 -> V_57 -> V_85 ;
unsigned long V_67 ;
int V_102 = 0 ;
F_15 ( & V_16 -> V_54 . V_70 , V_67 ) ;
V_16 -> V_54 . V_56 = 1 ;
switch ( V_85 -> V_103 ) {
case V_104 :
V_16 -> V_54 . V_90 = 0 ;
V_16 -> V_54 . V_91 = V_85 -> V_105 ;
break;
default:
V_16 -> V_54 . V_90 = 1 ;
V_16 -> V_54 . V_91 = 0 ;
break;
}
switch ( V_85 -> V_106 ) {
case V_107 :
V_4 -> V_57 -> V_58 = F_23 ;
break;
default:
V_102 = F_19 ( V_2 , V_4 ) ;
break;
}
F_16 ( & V_16 -> V_54 . V_70 , V_67 ) ;
if ( V_102 )
F_18 ( V_2 , V_4 ) ;
return 0 ;
}
static int
F_25 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_97 * V_85 )
{
return F_26 ( V_2 , V_4 , V_85 ) ;
}
static int F_27 ( struct V_1 * V_2 , struct V_108 * V_109 )
{
struct V_3 * V_4 ;
int V_110 , V_111 , V_112 , V_44 , V_31 , V_113 = 0 ;
unsigned long V_41 ;
unsigned int V_63 [ V_66 ] ;
V_41 = V_109 -> V_114 [ 0 ] ;
V_63 [ 0 ] = V_109 -> V_114 [ 1 ] ;
V_63 [ 1 ] = V_109 -> V_114 [ 2 ] ;
F_3 ( V_2 -> V_11 , L_6 , V_2 -> V_115 ,
V_2 -> V_116 -> V_117 , V_41 ) ;
V_2 -> V_41 = V_41 ;
if ( ! V_41 || ! F_28 ( V_41 ,
V_33 -> V_34 * V_42 ,
V_2 -> V_116 -> V_117 ) ) {
F_29 ( V_2 -> V_11 , L_7 ) ;
return - V_118 ;
}
V_2 -> V_119 = V_33 -> V_120 ;
if ( F_30 ( V_2 , sizeof( struct V_121 ) ) < 0 ) {
F_31 ( V_2 -> V_11 , L_8 ) ;
return - V_122 ;
}
for ( V_31 = 0 ; V_31 < V_66 ; ++ V_31 ) {
V_36 -> V_37 [ V_31 ] . V_123 = V_31 ;
V_36 -> V_37 [ V_31 ] . V_41 = V_2 -> V_41 + V_31 * V_42 ;
V_36 -> V_37 [ V_31 ] . V_63 = 0 ;
F_32 ( & V_36 -> V_37 [ V_31 ] . V_70 ) ;
}
V_111 = V_124 * V_33 -> V_34 ;
V_112 = F_33 ( V_111 ) ;
V_36 -> V_125 =
F_34 ( V_112 , sizeof( struct V_126 ) ,
V_127 ) ;
if ( ! V_36 -> V_125 ) {
F_31 ( V_2 -> V_11 , L_9 ) ;
return - V_122 ;
}
if ( F_35 ( V_2 , V_112 ) < 0 ) {
F_3 ( V_2 -> V_11 , L_10 ) ;
return - V_122 ;
}
V_44 = 0 ;
V_31 = 0 ;
for ( V_110 = 0 ; V_110 < ( int ) V_2 -> V_77 ; ++ V_110 ) {
int V_8 ;
V_4 = V_2 -> V_76 + V_110 ;
V_4 -> V_128 = V_36 -> V_125 + V_110 ;
V_4 -> V_129 = 1 ;
V_4 -> V_130 = & V_131 ;
V_4 -> V_132 = V_133 | V_134 ;
V_4 -> type = V_135 ;
V_4 -> V_136 = F_1 ;
V_4 -> V_137 = F_7 ;
V_4 -> V_13 = F_36 ( V_111 , V_138 ) ;
V_16 -> V_54 . V_31 = - 1 ;
V_16 -> V_54 . V_81 = - 1 ;
V_16 -> V_54 . V_60 = - 1 ;
V_16 -> V_54 . V_59 = - 1 ;
V_16 -> V_54 . V_56 = 0 ;
V_4 -> V_139 = 1 ;
for ( V_8 = 0 ; V_8 < V_140 ; ++ V_8 , ++ V_44 ) {
if ( V_44 >= V_46 ) {
V_44 = 0 ;
++ V_31 ;
V_113 = 0 ;
}
V_16 -> V_17 [ V_8 ] =
V_36 -> V_37 [ V_31 ] . V_41 + V_44 ;
if ( V_113 <
V_14 * V_72
&& V_16 -> V_54 . V_31 < 0 ) {
V_16 -> V_54 . V_31 = V_31 ;
V_16 -> V_54 . V_56 = 0 ;
V_16 -> V_54 . V_91 = 0 ;
V_16 -> V_54 . V_81 = V_8 * 8 ;
V_16 -> V_54 . V_60 = V_113 ;
V_16 -> V_54 . V_59 =
V_4 -> V_13 - V_16 -> V_54 . V_81 ;
V_2 -> V_141 = V_4 ;
V_4 -> V_132 |= V_142 ;
V_4 -> V_143 = F_22 ;
V_4 -> V_144 = F_24 ;
V_4 -> V_145 = F_25 ;
V_4 -> V_139 = V_16 -> V_54 . V_59 ;
}
V_113 += V_14 ;
}
F_32 ( & V_16 -> V_54 . V_70 ) ;
V_111 -= V_4 -> V_13 ;
if ( ! V_111 ) {
V_31 = 0 ;
V_44 = 0 ;
}
}
F_10 ( V_2 ) ;
for ( V_31 = 0 ; V_63 [ 0 ] && V_31 < V_66 ; ++ V_31 ) {
if ( V_63 [ V_31 ]
&& F_37 ( V_63 [ V_31 ] , F_14 ,
V_146 , V_33 -> V_120 , V_2 ) ) {
int V_147 ;
for ( V_147 = V_31 - 1 ; V_147 >= 0 ; -- V_147 ) {
F_38 ( V_63 [ V_147 ] , V_2 ) ;
V_36 -> V_37 [ V_147 ] . V_63 = V_63 [ V_147 ] = 0 ;
}
V_63 [ V_31 ] = 0 ;
}
V_36 -> V_37 [ V_31 ] . V_63 = V_63 [ V_31 ] ;
}
V_2 -> V_63 = V_63 [ 0 ] ;
if ( V_63 [ 0 ] ) {
F_3 ( V_2 -> V_11 , L_11 , V_63 [ 0 ] ) ;
if ( V_63 [ 1 ] && V_33 -> V_34 == 2 )
F_3 ( V_2 -> V_11 , L_12 , V_63 [ 1 ] ) ;
} else {
F_3 ( V_2 -> V_11 , L_13 ) ;
}
return 1 ;
}
static void F_39 ( struct V_1 * V_2 )
{
int V_147 ;
if ( V_2 -> V_41 )
F_40 ( V_2 -> V_41 , V_42 * V_33 -> V_34 ) ;
for ( V_147 = 0 ; V_147 < V_66 ; ++ V_147 ) {
if ( V_36 -> V_37 [ V_147 ] . V_63 )
F_38 ( V_36 -> V_37 [ V_147 ] . V_63 , V_2 ) ;
}
if ( V_36 && V_36 -> V_125 )
F_41 ( V_36 -> V_125 ) ;
}

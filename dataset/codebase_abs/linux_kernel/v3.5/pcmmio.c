static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 ;
if ( V_6 -> V_9 != 2 )
return - V_10 ;
#ifdef F_2
F_3 ( V_11 L_1 , V_7 [ 0 ] , V_7 [ 1 ] ) ;
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
F_3
( V_11 L_2
L_3 , V_8 , ( unsigned ) V_20 ,
( unsigned ) V_21 , V_18 , V_15 , ( unsigned ) V_19 ) ;
#endif
if ( V_20 ) {
V_19 &= ~ V_20 ;
V_19 |= ~ V_21 & V_20 ;
F_5 ( V_19 , V_15 ) ;
}
#ifdef F_2
F_3 ( V_11 L_4 , ( unsigned ) V_19 ) ;
#endif
V_4 -> V_12 |= ( ( unsigned int ) V_19 ) << V_18 ;
}
V_7 [ 1 ] = ~ V_4 -> V_12 ;
#ifdef F_2
F_3 ( V_11 L_5 , V_4 -> V_12 , V_7 [ 1 ] ) ;
#endif
return 2 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_22 = F_7 ( V_6 -> V_23 ) , V_8 = V_22 / 8 , V_24 =
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
F_5 ( V_19 , V_15 ) ;
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
static void F_8 ( struct V_1 * V_2 , int V_31 , int V_32 )
{
if ( V_31 < 0 || V_31 >= V_33 -> V_34 )
return;
if ( V_32 < 0 || V_32 >= V_35 )
return;
V_36 -> V_37 [ V_31 ] . V_38 &= ~ V_39 ;
V_36 -> V_37 [ V_31 ] . V_38 |= V_32 << V_40 ;
F_5 ( V_36 -> V_37 [ V_31 ] . V_38 ,
V_36 -> V_37 [ V_31 ] . V_41 + V_42 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_33 -> V_34 ; ++ V_31 ) {
int V_43 , V_32 ;
unsigned long V_44 = V_36 -> V_37 [ V_31 ] . V_41 ;
F_8 ( V_2 , V_31 , 0 ) ;
for ( V_43 = 0 ; V_43 < V_45 ; ++ V_43 )
F_5 ( 0 , V_44 + V_46 + V_43 ) ;
for ( V_32 = 1 ; V_32 < V_35 ; ++ V_32 ) {
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
if ( V_31 < 0 || V_31 >= V_33 -> V_34 )
return;
if ( V_43 < 0 || V_43 >= V_45 )
return;
V_36 -> V_37 [ V_31 ] . V_38 |= 0x1 << V_43 ;
F_5 ( V_36 -> V_37 [ V_31 ] . V_38 ,
V_36 -> V_37 [ V_31 ] . V_41 + V_42 ) ;
return;
}
static void F_11 ( struct V_1 * V_2 , int V_31 , int V_43 )
{
if ( V_31 < 0 || V_31 >= V_33 -> V_34 )
return;
if ( V_43 < 0 || V_43 >= V_45 )
return;
V_36 -> V_37 [ V_31 ] . V_38 &= ~ ( 0x1 << V_43 ) | V_50 ;
F_5 ( V_36 -> V_37 [ V_31 ] . V_38 ,
V_36 -> V_37 [ V_31 ] . V_41 + V_42 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_51 , V_52 , V_31 , V_43 ;
V_31 = V_16 -> V_53 . V_54 . V_31 ;
if ( V_31 < 0 )
return;
V_16 -> V_53 . V_54 . V_55 = 0 ;
V_16 -> V_53 . V_54 . V_56 = 0 ;
V_4 -> V_57 -> V_58 = 0 ;
V_51 = V_16 -> V_53 . V_54 . V_59 / V_14 ;
V_52 = V_16 -> V_53 . V_54 . V_60 / V_14 ;
F_8 ( V_2 , V_31 , V_61 ) ;
for ( V_43 = V_52 ; V_43 < V_52 + V_51 ; ++ V_43 ) {
F_5 ( 0 , V_36 -> V_37 [ V_31 ] . V_41 + V_62 + V_43 ) ;
}
}
static T_1 F_13 ( int V_63 , void * V_64 )
{
int V_31 , V_65 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_64 ;
for ( V_31 = 0 ; V_31 < V_66 ; ++ V_31 ) {
if ( V_63 == V_36 -> V_37 [ V_31 ] . V_63 ) {
unsigned long V_67 ;
unsigned V_68 = 0 ;
unsigned long V_41 = V_36 -> V_37 [ V_31 ] . V_41 ;
unsigned char V_69 ;
F_14 ( & V_36 -> V_37 [ V_31 ] . V_70 ,
V_67 ) ;
V_69 = F_4 ( V_41 + V_71 ) & 0x07 ;
if ( V_69 ) {
int V_43 ;
for ( V_43 = 0 ; V_43 < V_72 ;
++ V_43 ) {
if ( V_69 & ( 0x1 << V_43 ) ) {
unsigned char
V_73 = 0 ;
F_8 ( V_2 , V_31 ,
V_74 ) ;
V_73 =
F_4 ( V_41 +
V_75 + V_43 ) ;
if ( V_73 )
F_5 ( 0 , V_41 +
V_75 +
V_43 ) ;
V_68 |=
V_73 <<
V_43 * 8 ;
}
}
++ V_65 ;
}
F_15 ( & V_36 -> V_37 [ V_31 ] . V_70 ,
V_67 ) ;
if ( V_68 ) {
struct V_3 * V_4 ;
F_3
( V_11 L_6 ,
V_63 , V_31 , V_68 ) ;
for ( V_4 = V_2 -> V_76 + 2 ;
V_4 < V_2 -> V_76 + V_2 -> V_77 ;
++ V_4 ) {
if ( V_16 -> V_53 . V_54 . V_31 == V_31 ) {
unsigned long V_67 ;
unsigned V_78 ;
F_14 ( & V_16 -> V_53 .
V_54 . V_70 ,
V_67 ) ;
V_78 = V_4 -> V_57 -> V_79 ;
if ( V_16 -> V_53 . V_54 . V_56 ) {
unsigned V_80 =
( ( V_68 >>
V_16 -> V_53 . V_54 . V_60 )
&
( ( 0x1 << V_16 ->
V_53 . V_54 .
V_59 ) -
1 ) ) << V_16 ->
V_53 . V_54 . V_81 ;
if ( V_80 &
V_16 -> V_53 .
V_54 . V_55 ) {
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
V_83 = F_7 ( V_4 -> V_57 -> V_85 . V_87 [ V_9 ] ) ;
if ( V_80 & ( 1U << V_83 ) )
V_82 |= ( 1U << V_9 ) ;
}
if ( F_16 ( V_4 -> V_57 , ( ( short * ) & V_82 ) [ 0 ] )
&&
F_16
( V_4 -> V_57 ,
( ( short * )
& V_82 ) [ 1 ] ) ) {
V_4 -> V_57 -> V_79 |= ( V_88 | V_89 ) ;
} else {
F_12
( V_2 ,
V_4 ) ;
}
if ( ! V_16 -> V_53 . V_54 . V_90 ) {
if ( V_16 -> V_53 . V_54 . V_91 > 0 ) {
V_16 -> V_53 . V_54 . V_91 -- ;
if ( V_16 -> V_53 . V_54 . V_91 == 0 ) {
V_4 -> V_57 -> V_79 |= V_92 ;
F_12
( V_2 ,
V_4 ) ;
}
}
}
}
}
F_15
( & V_16 -> V_53 . V_54 .
V_70 , V_67 ) ;
if ( V_78 !=
V_4 -> V_57 -> V_79 ) {
F_17 ( V_2 , V_4 ) ;
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
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( ! V_16 -> V_53 . V_54 . V_90 && V_16 -> V_53 . V_54 . V_91 == 0 ) {
V_4 -> V_57 -> V_79 |= V_92 ;
V_16 -> V_53 . V_54 . V_56 = 0 ;
return 1 ;
} else {
unsigned V_95 = 0 , V_96 = 0 , V_9 ;
int V_51 , V_52 , V_31 , V_43 ;
struct V_97 * V_85 = & V_4 -> V_57 -> V_85 ;
V_31 = V_16 -> V_53 . V_54 . V_31 ;
if ( V_31 < 0 )
return 1 ;
V_16 -> V_53 . V_54 . V_55 = 0 ;
V_16 -> V_53 . V_54 . V_56 = 1 ;
V_51 = V_16 -> V_53 . V_54 . V_59 / V_14 ;
V_52 = V_16 -> V_53 . V_54 . V_60 / V_14 ;
if ( V_85 -> V_87 ) {
for ( V_9 = 0 ; V_9 < V_85 -> V_86 ; V_9 ++ ) {
V_95 |= ( 1U << F_7 ( V_85 -> V_87 [ V_9 ] ) ) ;
V_96 |= ( F_19 ( V_85 -> V_87 [ V_9 ] )
|| F_20 ( V_85 ->
V_87 [ V_9 ] ) ? 1U : 0U )
<< F_7 ( V_85 -> V_87 [ V_9 ] ) ;
}
}
V_95 &= ( ( 0x1 << V_16 -> V_53 . V_54 . V_59 ) -
1 ) << V_16 -> V_53 . V_54 . V_81 ;
V_16 -> V_53 . V_54 . V_55 = V_95 ;
{
unsigned char V_98 ;
F_5 ( 1 << 4 , V_2 -> V_41 + 3 ) ;
V_98 = V_2 -> V_63 & ( ( 1 << 4 ) - 1 ) ;
F_5 ( V_98 , V_2 -> V_41 + 2 ) ;
}
F_8 ( V_2 , V_31 , V_61 ) ;
for ( V_43 = V_52 ; V_43 < V_52 + V_51 ; ++ V_43 ) {
unsigned V_99 =
V_95 >> ( V_16 -> V_53 . V_54 . V_81 + ( V_43 -
V_52 )
* 8 ) & 0xff , V_100 =
V_96 >> ( V_16 -> V_53 . V_54 . V_81 +
( V_43 - V_52 ) * 8 ) & 0xff ;
F_5 ( V_99 ,
V_36 -> V_37 [ V_31 ] . V_41 + V_62 + V_43 ) ;
F_8 ( V_2 , V_31 , V_101 ) ;
F_5 ( V_100 ,
V_36 -> V_37 [ V_31 ] . V_41 + V_62 + V_43 ) ;
}
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_67 ;
F_14 ( & V_16 -> V_53 . V_54 . V_70 , V_67 ) ;
if ( V_16 -> V_53 . V_54 . V_56 )
F_12 ( V_2 , V_4 ) ;
F_15 ( & V_16 -> V_53 . V_54 . V_70 , V_67 ) ;
return 0 ;
}
static int
F_22 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_102 )
{
unsigned long V_67 ;
int V_103 = 0 ;
if ( V_102 != 0 )
return - V_10 ;
F_14 ( & V_16 -> V_53 . V_54 . V_70 , V_67 ) ;
V_4 -> V_57 -> V_58 = 0 ;
if ( V_16 -> V_53 . V_54 . V_56 )
V_103 = F_18 ( V_2 , V_4 ) ;
F_15 ( & V_16 -> V_53 . V_54 . V_70 , V_67 ) ;
if ( V_103 )
F_17 ( V_2 , V_4 ) ;
return 1 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_97 * V_85 = & V_4 -> V_57 -> V_85 ;
unsigned long V_67 ;
int V_103 = 0 ;
F_14 ( & V_16 -> V_53 . V_54 . V_70 , V_67 ) ;
V_16 -> V_53 . V_54 . V_56 = 1 ;
switch ( V_85 -> V_104 ) {
case V_105 :
V_16 -> V_53 . V_54 . V_90 = 0 ;
V_16 -> V_53 . V_54 . V_91 = V_85 -> V_106 ;
break;
default:
V_16 -> V_53 . V_54 . V_90 = 1 ;
V_16 -> V_53 . V_54 . V_91 = 0 ;
break;
}
switch ( V_85 -> V_107 ) {
case V_108 :
V_4 -> V_57 -> V_58 = F_22 ;
break;
default:
V_103 = F_18 ( V_2 , V_4 ) ;
break;
}
F_15 ( & V_16 -> V_53 . V_54 . V_70 , V_67 ) ;
if ( V_103 )
F_17 ( V_2 , V_4 ) ;
return 0 ;
}
static int
F_24 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_97 * V_85 )
{
return F_25 ( V_2 , V_4 , V_85 ) ;
}
static int F_26 ( unsigned long V_41 )
{
unsigned long V_109 = 100000 ;
while ( V_109 -- )
if ( F_4 ( V_41 + 3 ) & 0x80 )
return 0 ;
return 1 ;
}
static int F_27 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_9 ;
unsigned long V_41 = V_16 -> V_41 ;
for ( V_9 = 0 ; V_9 < V_6 -> V_9 ; V_9 ++ ) {
unsigned V_22 = F_7 ( V_6 -> V_23 ) , V_110 =
F_20 ( V_6 -> V_23 ) , V_111 = F_19 ( V_6 -> V_23 ) ;
unsigned char V_112 = 0 ;
unsigned V_113 = 0 ;
short V_114 , V_115 = 0 ;
if ( V_22 > 7 )
V_22 -= 8 , V_113 = 4 ;
if ( V_111 != V_116 ) {
V_111 = V_117 ;
V_112 |= 1 << 7 ;
}
if ( V_110 < 2 )
V_115 = 0x8000 ;
if ( V_22 % 2 ) {
V_112 |= 1 << 6 ;
}
V_112 |= ( ( V_22 / 2 ) & 0x3 ) << 4 ;
V_112 |= ( V_110 & 0x3 ) << 2 ;
F_5 ( V_112 , V_41 + V_113 + 2 ) ;
F_26 ( V_41 + V_113 ) ;
F_5 ( V_112 , V_41 + V_113 + 2 ) ;
F_26 ( V_41 + V_113 ) ;
V_114 = F_4 ( V_41 + V_113 + 0 ) ;
V_114 |= F_4 ( V_41 + V_113 + 1 ) << 8 ;
V_114 += V_115 ;
V_7 [ V_9 ] = V_114 ;
}
return V_9 ;
}
static int F_28 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_6 -> V_9 ; V_9 ++ ) {
unsigned V_22 = F_7 ( V_6 -> V_23 ) ;
if ( V_22 < V_4 -> V_13 )
V_7 [ V_9 ] = V_16 -> V_118 . V_119 [ V_22 ] ;
}
return V_9 ;
}
static int F_29 ( unsigned long V_41 )
{
unsigned long V_109 = 100000L ;
while ( V_109 -- ) {
if ( F_4 ( V_41 + 3 ) & 0x80 )
return 0 ;
}
return 1 ;
}
static int F_30 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_9 ;
unsigned V_41 = V_16 -> V_41 , V_113 = 0 ;
for ( V_9 = 0 ; V_9 < V_6 -> V_9 ; V_9 ++ ) {
unsigned V_22 = F_7 ( V_6 -> V_23 ) , V_110 =
F_20 ( V_6 -> V_23 ) ;
if ( V_22 < V_4 -> V_13 ) {
unsigned char V_112 = 0 , V_120 =
V_110 & ( ( 1 << 4 ) - 1 ) ;
if ( V_22 >= 4 )
V_22 -= 4 , V_113 += 4 ;
F_5 ( V_120 , V_41 + V_113 + 0 ) ;
F_5 ( 0 , V_41 + V_113 + 1 ) ;
V_112 = ( V_22 << 1 ) | 0x60 ;
F_5 ( V_112 , V_41 + V_113 + 2 ) ;
F_29 ( V_41 + V_113 ) ;
F_5 ( V_7 [ V_9 ] & 0xff , V_41 + V_113 + 0 ) ;
F_5 ( ( V_7 [ V_9 ] >> 8 ) & 0xff , V_41 + V_113 + 1 ) ;
V_112 = 0x70 | ( V_22 << 1 ) ;
F_5 ( V_112 , V_41 + V_113 + 2 ) ;
F_29 ( V_41 + V_113 ) ;
V_16 -> V_118 . V_119 [ V_22 ] = V_7 [ V_9 ] ;
}
}
return V_9 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_121 * V_122 )
{
struct V_3 * V_4 ;
int V_123 , V_124 , V_125 , V_126 , V_43 , V_31 ,
V_127 = 0 ;
unsigned long V_41 ;
unsigned int V_63 [ V_66 ] ;
V_41 = V_122 -> V_128 [ 0 ] ;
V_63 [ 0 ] = V_122 -> V_128 [ 1 ] ;
F_3 ( V_129 L_7 , V_2 -> V_130 ,
V_2 -> V_131 -> V_132 , V_41 ) ;
V_2 -> V_41 = V_41 ;
if ( ! V_41 || ! F_32 ( V_41 ,
V_33 -> V_133 ,
V_2 -> V_131 -> V_132 ) ) {
F_3 ( V_134 L_8 , V_2 -> V_130 ) ;
return - V_135 ;
}
V_2 -> V_136 = V_33 -> V_137 ;
if ( F_33 ( V_2 , sizeof( struct V_138 ) ) < 0 ) {
F_3 ( V_134 L_9 ,
V_2 -> V_130 ) ;
return - V_139 ;
}
for ( V_31 = 0 ; V_31 < V_66 ; ++ V_31 ) {
V_36 -> V_37 [ V_31 ] . V_140 = V_31 ;
V_36 -> V_37 [ V_31 ] . V_41 =
V_2 -> V_41 + 16 + V_31 * V_141 ;
V_36 -> V_37 [ V_31 ] . V_63 = 0 ;
F_34 ( & V_36 -> V_37 [ V_31 ] . V_70 ) ;
}
V_124 = V_142 * V_33 -> V_34 ;
V_125 = F_35 ( V_124 ) ;
V_126 = V_125 + 2 ;
V_36 -> V_143 =
F_36 ( V_126 , sizeof( struct V_144 ) ,
V_145 ) ;
if ( ! V_36 -> V_143 ) {
F_3 ( V_134 L_10 ,
V_2 -> V_130 ) ;
return - V_139 ;
}
if ( F_37 ( V_2 , V_126 ) < 0 ) {
F_3 ( V_134 L_11 ,
V_2 -> V_130 ) ;
return - V_139 ;
}
V_123 = 0 ;
V_4 = V_2 -> V_76 + V_123 ;
V_4 -> V_146 = V_36 -> V_143 + V_123 ;
V_4 -> V_147 = ( 1 << V_33 -> V_148 ) - 1 ;
V_4 -> V_149 = V_33 -> V_150 ;
V_4 -> V_151 = V_152 | V_153 | V_154 ;
V_4 -> type = V_155 ;
V_4 -> V_13 = V_33 -> V_156 ;
V_4 -> V_157 = V_4 -> V_13 ;
V_4 -> V_158 = V_33 -> F_27 ;
V_16 -> V_41 = V_2 -> V_41 + 0 ;
F_5 ( 0 , V_16 -> V_41 + 3 ) ;
F_5 ( 0 , V_16 -> V_41 + 4 + 3 ) ;
++ V_123 ;
V_4 = V_2 -> V_76 + V_123 ;
V_4 -> V_146 = V_36 -> V_143 + V_123 ;
V_4 -> V_147 = ( 1 << V_33 -> V_159 ) - 1 ;
V_4 -> V_149 = V_33 -> V_160 ;
V_4 -> V_151 = V_152 ;
V_4 -> type = V_161 ;
V_4 -> V_13 = V_33 -> V_162 ;
V_4 -> V_157 = V_4 -> V_13 ;
V_4 -> V_158 = V_33 -> F_28 ;
V_4 -> V_163 = V_33 -> F_30 ;
V_16 -> V_41 = V_2 -> V_41 + 8 ;
F_5 ( 0 , V_16 -> V_41 + 3 ) ;
F_5 ( 0 , V_16 -> V_41 + 4 + 3 ) ;
++ V_123 ;
V_43 = 0 ;
V_31 = 0 ;
for (; V_123 < ( int ) V_2 -> V_77 ; ++ V_123 ) {
int V_8 ;
V_4 = V_2 -> V_76 + V_123 ;
V_4 -> V_146 = V_36 -> V_143 + V_123 ;
V_4 -> V_147 = 1 ;
V_4 -> V_149 = & V_164 ;
V_4 -> V_151 = V_152 | V_165 ;
V_4 -> type = V_166 ;
V_4 -> V_167 = F_1 ;
V_4 -> V_168 = F_6 ;
V_4 -> V_13 = F_38 ( V_124 , V_169 ) ;
V_16 -> V_53 . V_54 . V_31 = - 1 ;
V_16 -> V_53 . V_54 . V_81 = - 1 ;
V_16 -> V_53 . V_54 . V_60 = - 1 ;
V_16 -> V_53 . V_54 . V_59 = - 1 ;
V_16 -> V_53 . V_54 . V_56 = 0 ;
V_4 -> V_157 = 1 ;
for ( V_8 = 0 ; V_8 < V_170 ; ++ V_8 , ++ V_43 ) {
if ( V_43 >= V_45 ) {
V_43 = 0 ;
++ V_31 ;
V_127 = 0 ;
}
V_16 -> V_17 [ V_8 ] =
V_36 -> V_37 [ V_31 ] . V_41 + V_43 ;
if ( V_127 <
V_14 * V_72
&& V_16 -> V_53 . V_54 . V_31 < 0 ) {
V_16 -> V_53 . V_54 . V_31 = V_31 ;
V_16 -> V_53 . V_54 . V_56 = 0 ;
V_16 -> V_53 . V_54 . V_91 = 0 ;
V_16 -> V_53 . V_54 . V_81 = V_8 * 8 ;
V_16 -> V_53 . V_54 . V_60 = V_127 ;
V_16 -> V_53 . V_54 . V_59 =
V_4 -> V_13 - V_16 -> V_53 . V_54 . V_81 ;
V_4 -> V_171 = F_21 ;
V_4 -> V_172 = F_23 ;
V_4 -> V_173 = F_24 ;
V_4 -> V_157 =
V_16 -> V_53 . V_54 . V_59 ;
}
V_127 += V_14 ;
}
F_34 ( & V_16 -> V_53 . V_54 . V_70 ) ;
V_124 -= V_4 -> V_13 ;
if ( ! V_124 ) {
V_31 = 0 ;
V_43 = 0 ;
}
}
F_9 ( V_2 ) ;
for ( V_31 = 0 ; V_63 [ 0 ] && V_31 < V_66 ; ++ V_31 ) {
if ( V_63 [ V_31 ]
&& F_39 ( V_63 [ V_31 ] , F_13 ,
V_174 , V_33 -> V_137 , V_2 ) ) {
int V_175 ;
for ( V_175 = V_31 - 1 ; V_175 >= 0 ; -- V_175 ) {
F_40 ( V_63 [ V_175 ] , V_2 ) ;
V_36 -> V_37 [ V_175 ] . V_63 = V_63 [ V_175 ] = 0 ;
}
V_63 [ V_31 ] = 0 ;
}
V_36 -> V_37 [ V_31 ] . V_63 = V_63 [ V_31 ] ;
}
V_2 -> V_63 = V_63 [ 0 ] ;
if ( V_63 [ 0 ] ) {
F_3 ( V_11 L_12 , V_2 -> V_130 , V_63 [ 0 ] ) ;
if ( V_33 -> V_34 == 2 && V_63 [ 1 ] )
F_3 ( V_11 L_13 ,
V_2 -> V_130 , V_63 [ 1 ] ) ;
} else {
F_3 ( V_129 L_14 , V_2 -> V_130 ) ;
}
F_3 ( V_129 L_15 , V_2 -> V_130 ) ;
return 1 ;
}
static void F_41 ( struct V_1 * V_2 )
{
int V_175 ;
if ( V_2 -> V_41 )
F_42 ( V_2 -> V_41 , V_33 -> V_133 ) ;
for ( V_175 = 0 ; V_175 < V_66 ; ++ V_175 ) {
if ( V_36 && V_36 -> V_37 [ V_175 ] . V_63 )
F_40 ( V_36 -> V_37 [ V_175 ] . V_63 , V_2 ) ;
}
if ( V_36 && V_36 -> V_143 )
F_43 ( V_36 -> V_143 ) ;
}

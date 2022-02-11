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
const struct V_33 * V_34 = F_9 ( V_2 ) ;
if ( V_31 < 0 || V_31 >= V_34 -> V_35 )
return;
if ( V_32 < 0 || V_32 >= V_36 )
return;
V_37 -> V_38 [ V_31 ] . V_39 &= ~ V_40 ;
V_37 -> V_38 [ V_31 ] . V_39 |= V_32 << V_41 ;
F_5 ( V_37 -> V_38 [ V_31 ] . V_39 ,
V_37 -> V_38 [ V_31 ] . V_42 + V_43 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
const struct V_33 * V_34 = F_9 ( V_2 ) ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_34 -> V_35 ; ++ V_31 ) {
int V_44 , V_32 ;
unsigned long V_45 = V_37 -> V_38 [ V_31 ] . V_42 ;
F_8 ( V_2 , V_31 , 0 ) ;
for ( V_44 = 0 ; V_44 < V_46 ; ++ V_44 )
F_5 ( 0 , V_45 + V_47 + V_44 ) ;
for ( V_32 = 1 ; V_32 < V_36 ; ++ V_32 ) {
int V_48 ;
F_8 ( V_2 , V_31 , V_32 ) ;
for ( V_48 = V_49 ;
V_48 < V_49 + V_50 ; ++ V_48 )
F_5 ( 0 , V_45 + V_48 ) ;
}
F_8 ( V_2 , V_31 , 0 ) ;
}
}
static void F_11 ( struct V_1 * V_2 , int V_31 , int V_44 )
{
const struct V_33 * V_34 = F_9 ( V_2 ) ;
if ( V_31 < 0 || V_31 >= V_34 -> V_35 )
return;
if ( V_44 < 0 || V_44 >= V_46 )
return;
V_37 -> V_38 [ V_31 ] . V_39 |= 0x1 << V_44 ;
F_5 ( V_37 -> V_38 [ V_31 ] . V_39 ,
V_37 -> V_38 [ V_31 ] . V_42 + V_43 ) ;
return;
}
static void F_12 ( struct V_1 * V_2 , int V_31 , int V_44 )
{
const struct V_33 * V_34 = F_9 ( V_2 ) ;
if ( V_31 < 0 || V_31 >= V_34 -> V_35 )
return;
if ( V_44 < 0 || V_44 >= V_46 )
return;
V_37 -> V_38 [ V_31 ] . V_39 &= ~ ( 0x1 << V_44 ) | V_51 ;
F_5 ( V_37 -> V_38 [ V_31 ] . V_39 ,
V_37 -> V_38 [ V_31 ] . V_42 + V_43 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_52 , V_53 , V_31 , V_44 ;
V_31 = V_14 -> V_54 . V_55 . V_31 ;
if ( V_31 < 0 )
return;
V_14 -> V_54 . V_55 . V_56 = 0 ;
V_14 -> V_54 . V_55 . V_57 = 0 ;
V_4 -> V_58 -> V_59 = NULL ;
V_52 = V_14 -> V_54 . V_55 . V_60 / V_12 ;
V_53 = V_14 -> V_54 . V_55 . V_61 / V_12 ;
F_8 ( V_2 , V_31 , V_62 ) ;
for ( V_44 = V_53 ; V_44 < V_53 + V_52 ; ++ V_44 ) {
F_5 ( 0 , V_37 -> V_38 [ V_31 ] . V_42 + V_63 + V_44 ) ;
}
}
static T_1 F_14 ( int V_64 , void * V_65 )
{
int V_31 , V_66 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_65 ;
for ( V_31 = 0 ; V_31 < V_67 ; ++ V_31 ) {
if ( V_64 == V_37 -> V_38 [ V_31 ] . V_64 ) {
unsigned long V_68 ;
unsigned V_69 = 0 ;
unsigned long V_42 = V_37 -> V_38 [ V_31 ] . V_42 ;
unsigned char V_70 ;
F_15 ( & V_37 -> V_38 [ V_31 ] . V_71 ,
V_68 ) ;
V_70 = F_4 ( V_42 + V_72 ) & 0x07 ;
if ( V_70 ) {
int V_44 ;
for ( V_44 = 0 ; V_44 < V_73 ;
++ V_44 ) {
if ( V_70 & ( 0x1 << V_44 ) ) {
unsigned char
V_74 = 0 ;
F_8 ( V_2 , V_31 ,
V_75 ) ;
V_74 =
F_4 ( V_42 +
V_76 + V_44 ) ;
if ( V_74 )
F_5 ( 0 , V_42 +
V_76 +
V_44 ) ;
V_69 |=
V_74 <<
V_44 * 8 ;
}
}
++ V_66 ;
}
F_16 ( & V_37 -> V_38 [ V_31 ] . V_71 ,
V_68 ) ;
if ( V_69 ) {
struct V_3 * V_4 ;
F_3
( V_9 L_6 ,
V_64 , V_31 , V_69 ) ;
for ( V_4 = V_2 -> V_77 + 2 ;
V_4 < V_2 -> V_77 + V_2 -> V_78 ;
++ V_4 ) {
if ( V_14 -> V_54 . V_55 . V_31 == V_31 ) {
unsigned long V_68 ;
unsigned V_79 ;
F_15 ( & V_14 -> V_54 .
V_55 . V_71 ,
V_68 ) ;
V_79 = V_4 -> V_58 -> V_80 ;
if ( V_14 -> V_54 . V_55 . V_57 ) {
unsigned V_81 =
( ( V_69 >>
V_14 -> V_54 . V_55 . V_61 )
&
( ( 0x1 << V_14 ->
V_54 . V_55 .
V_60 ) -
1 ) ) << V_14 ->
V_54 . V_55 . V_82 ;
if ( V_81 &
V_14 -> V_54 .
V_55 . V_56 ) {
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
V_84 = F_7 ( V_4 -> V_58 -> V_86 . V_88 [ V_20 ] ) ;
if ( V_81 & ( 1U << V_84 ) )
V_83 |= ( 1U << V_20 ) ;
}
if ( F_17 ( V_4 -> V_58 , ( ( short * ) & V_83 ) [ 0 ] )
&&
F_17
( V_4 -> V_58 ,
( ( short * )
& V_83 ) [ 1 ] ) ) {
V_4 -> V_58 -> V_80 |= ( V_89 | V_90 ) ;
} else {
F_13
( V_2 ,
V_4 ) ;
}
if ( ! V_14 -> V_54 . V_55 . V_91 ) {
if ( V_14 -> V_54 . V_55 . V_92 > 0 ) {
V_14 -> V_54 . V_55 . V_92 -- ;
if ( V_14 -> V_54 . V_55 . V_92 == 0 ) {
V_4 -> V_58 -> V_80 |= V_93 ;
F_13
( V_2 ,
V_4 ) ;
}
}
}
}
}
F_16
( & V_14 -> V_54 . V_55 .
V_71 , V_68 ) ;
if ( V_79 !=
V_4 -> V_58 -> V_80 ) {
F_18 ( V_2 , V_4 ) ;
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
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( ! V_14 -> V_54 . V_55 . V_91 && V_14 -> V_54 . V_55 . V_92 == 0 ) {
V_4 -> V_58 -> V_80 |= V_93 ;
V_14 -> V_54 . V_55 . V_57 = 0 ;
return 1 ;
} else {
unsigned V_96 = 0 , V_97 = 0 , V_20 ;
int V_52 , V_53 , V_31 , V_44 ;
struct V_98 * V_86 = & V_4 -> V_58 -> V_86 ;
V_31 = V_14 -> V_54 . V_55 . V_31 ;
if ( V_31 < 0 )
return 1 ;
V_14 -> V_54 . V_55 . V_56 = 0 ;
V_14 -> V_54 . V_55 . V_57 = 1 ;
V_52 = V_14 -> V_54 . V_55 . V_60 / V_12 ;
V_53 = V_14 -> V_54 . V_55 . V_61 / V_12 ;
if ( V_86 -> V_88 ) {
for ( V_20 = 0 ; V_20 < V_86 -> V_87 ; V_20 ++ ) {
V_96 |= ( 1U << F_7 ( V_86 -> V_88 [ V_20 ] ) ) ;
V_97 |= ( F_20 ( V_86 -> V_88 [ V_20 ] )
|| F_21 ( V_86 ->
V_88 [ V_20 ] ) ? 1U : 0U )
<< F_7 ( V_86 -> V_88 [ V_20 ] ) ;
}
}
V_96 &= ( ( 0x1 << V_14 -> V_54 . V_55 . V_60 ) -
1 ) << V_14 -> V_54 . V_55 . V_82 ;
V_14 -> V_54 . V_55 . V_56 = V_96 ;
{
unsigned char V_99 ;
F_5 ( 1 << 4 , V_2 -> V_42 + 3 ) ;
V_99 = V_2 -> V_64 & ( ( 1 << 4 ) - 1 ) ;
F_5 ( V_99 , V_2 -> V_42 + 2 ) ;
}
F_8 ( V_2 , V_31 , V_62 ) ;
for ( V_44 = V_53 ; V_44 < V_53 + V_52 ; ++ V_44 ) {
unsigned V_100 =
V_96 >> ( V_14 -> V_54 . V_55 . V_82 + ( V_44 -
V_53 )
* 8 ) & 0xff , V_101 =
V_97 >> ( V_14 -> V_54 . V_55 . V_82 +
( V_44 - V_53 ) * 8 ) & 0xff ;
F_5 ( V_100 ,
V_37 -> V_38 [ V_31 ] . V_42 + V_63 + V_44 ) ;
F_8 ( V_2 , V_31 , V_102 ) ;
F_5 ( V_101 ,
V_37 -> V_38 [ V_31 ] . V_42 + V_63 + V_44 ) ;
}
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_68 ;
F_15 ( & V_14 -> V_54 . V_55 . V_71 , V_68 ) ;
if ( V_14 -> V_54 . V_55 . V_57 )
F_13 ( V_2 , V_4 ) ;
F_16 ( & V_14 -> V_54 . V_55 . V_71 , V_68 ) ;
return 0 ;
}
static int
F_23 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_103 )
{
unsigned long V_68 ;
int V_104 = 0 ;
if ( V_103 != 0 )
return - V_30 ;
F_15 ( & V_14 -> V_54 . V_55 . V_71 , V_68 ) ;
V_4 -> V_58 -> V_59 = NULL ;
if ( V_14 -> V_54 . V_55 . V_57 )
V_104 = F_19 ( V_2 , V_4 ) ;
F_16 ( & V_14 -> V_54 . V_55 . V_71 , V_68 ) ;
if ( V_104 )
F_18 ( V_2 , V_4 ) ;
return 1 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_98 * V_86 = & V_4 -> V_58 -> V_86 ;
unsigned long V_68 ;
int V_104 = 0 ;
F_15 ( & V_14 -> V_54 . V_55 . V_71 , V_68 ) ;
V_14 -> V_54 . V_55 . V_57 = 1 ;
switch ( V_86 -> V_105 ) {
case V_106 :
V_14 -> V_54 . V_55 . V_91 = 0 ;
V_14 -> V_54 . V_55 . V_92 = V_86 -> V_107 ;
break;
default:
V_14 -> V_54 . V_55 . V_91 = 1 ;
V_14 -> V_54 . V_55 . V_92 = 0 ;
break;
}
switch ( V_86 -> V_108 ) {
case V_109 :
V_4 -> V_58 -> V_59 = F_23 ;
break;
default:
V_104 = F_19 ( V_2 , V_4 ) ;
break;
}
F_16 ( & V_14 -> V_54 . V_55 . V_71 , V_68 ) ;
if ( V_104 )
F_18 ( V_2 , V_4 ) ;
return 0 ;
}
static int
F_25 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_98 * V_86 )
{
return F_26 ( V_2 , V_4 , V_86 ) ;
}
static int F_27 ( unsigned long V_42 )
{
unsigned long V_110 = 100000 ;
while ( V_110 -- )
if ( F_4 ( V_42 + 3 ) & 0x80 )
return 0 ;
return 1 ;
}
static int F_28 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_20 ;
unsigned long V_42 = V_14 -> V_42 ;
for ( V_20 = 0 ; V_20 < V_6 -> V_20 ; V_20 ++ ) {
unsigned V_21 = F_7 ( V_6 -> V_22 ) , V_111 =
F_21 ( V_6 -> V_22 ) , V_112 = F_20 ( V_6 -> V_22 ) ;
unsigned char V_113 = 0 ;
unsigned V_114 = 0 ;
short V_115 , V_116 = 0 ;
if ( V_21 > 7 )
V_21 -= 8 , V_114 = 4 ;
if ( V_112 != V_117 ) {
V_112 = V_118 ;
V_113 |= 1 << 7 ;
}
if ( V_111 < 2 )
V_116 = 0x8000 ;
if ( V_21 % 2 ) {
V_113 |= 1 << 6 ;
}
V_113 |= ( ( V_21 / 2 ) & 0x3 ) << 4 ;
V_113 |= ( V_111 & 0x3 ) << 2 ;
F_5 ( V_113 , V_42 + V_114 + 2 ) ;
F_27 ( V_42 + V_114 ) ;
F_5 ( V_113 , V_42 + V_114 + 2 ) ;
F_27 ( V_42 + V_114 ) ;
V_115 = F_4 ( V_42 + V_114 + 0 ) ;
V_115 |= F_4 ( V_42 + V_114 + 1 ) << 8 ;
V_115 += V_116 ;
V_7 [ V_20 ] = V_115 ;
}
return V_20 ;
}
static int F_29 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_6 -> V_20 ; V_20 ++ ) {
unsigned V_21 = F_7 ( V_6 -> V_22 ) ;
if ( V_21 < V_4 -> V_11 )
V_7 [ V_20 ] = V_14 -> V_119 . V_120 [ V_21 ] ;
}
return V_20 ;
}
static int F_30 ( unsigned long V_42 )
{
unsigned long V_110 = 100000L ;
while ( V_110 -- ) {
if ( F_4 ( V_42 + 3 ) & 0x80 )
return 0 ;
}
return 1 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_20 ;
unsigned V_42 = V_14 -> V_42 , V_114 = 0 ;
for ( V_20 = 0 ; V_20 < V_6 -> V_20 ; V_20 ++ ) {
unsigned V_21 = F_7 ( V_6 -> V_22 ) , V_111 =
F_21 ( V_6 -> V_22 ) ;
if ( V_21 < V_4 -> V_11 ) {
unsigned char V_113 = 0 , V_121 =
V_111 & ( ( 1 << 4 ) - 1 ) ;
if ( V_21 >= 4 )
V_21 -= 4 , V_114 += 4 ;
F_5 ( V_121 , V_42 + V_114 + 0 ) ;
F_5 ( 0 , V_42 + V_114 + 1 ) ;
V_113 = ( V_21 << 1 ) | 0x60 ;
F_5 ( V_113 , V_42 + V_114 + 2 ) ;
F_30 ( V_42 + V_114 ) ;
F_5 ( V_7 [ V_20 ] & 0xff , V_42 + V_114 + 0 ) ;
F_5 ( ( V_7 [ V_20 ] >> 8 ) & 0xff , V_42 + V_114 + 1 ) ;
V_113 = 0x70 | ( V_21 << 1 ) ;
F_5 ( V_113 , V_42 + V_114 + 2 ) ;
F_30 ( V_42 + V_114 ) ;
V_14 -> V_119 . V_120 [ V_21 ] = V_7 [ V_20 ] ;
}
}
return V_20 ;
}
static int F_32 ( struct V_1 * V_2 , struct V_122 * V_123 )
{
const struct V_33 * V_34 = F_9 ( V_2 ) ;
struct V_3 * V_4 ;
int V_124 , V_125 , V_126 , V_127 , V_44 , V_31 ,
V_128 = 0 ;
unsigned long V_42 ;
unsigned int V_64 [ V_67 ] ;
int V_129 ;
V_42 = V_123 -> V_130 [ 0 ] ;
V_64 [ 0 ] = V_123 -> V_130 [ 1 ] ;
F_3 ( V_131 L_7 , V_2 -> V_132 ,
V_2 -> V_133 -> V_134 , V_42 ) ;
V_2 -> V_42 = V_42 ;
if ( ! V_42 || ! F_33 ( V_42 ,
V_34 -> V_135 ,
V_2 -> V_133 -> V_134 ) ) {
F_3 ( V_136 L_8 , V_2 -> V_132 ) ;
return - V_137 ;
}
V_2 -> V_138 = V_34 -> V_139 ;
if ( F_34 ( V_2 , sizeof( struct V_140 ) ) < 0 ) {
F_3 ( V_136 L_9 ,
V_2 -> V_132 ) ;
return - V_141 ;
}
for ( V_31 = 0 ; V_31 < V_67 ; ++ V_31 ) {
V_37 -> V_38 [ V_31 ] . V_142 = V_31 ;
V_37 -> V_38 [ V_31 ] . V_42 =
V_2 -> V_42 + 16 + V_31 * V_143 ;
V_37 -> V_38 [ V_31 ] . V_64 = 0 ;
F_35 ( & V_37 -> V_38 [ V_31 ] . V_71 ) ;
}
V_125 = V_144 * V_34 -> V_35 ;
V_126 = F_36 ( V_125 ) ;
V_127 = V_126 + 2 ;
V_37 -> V_145 =
F_37 ( V_127 , sizeof( struct V_146 ) ,
V_147 ) ;
if ( ! V_37 -> V_145 ) {
F_3 ( V_136 L_10 ,
V_2 -> V_132 ) ;
return - V_141 ;
}
V_129 = F_38 ( V_2 , V_127 ) ;
if ( V_129 )
return V_129 ;
V_124 = 0 ;
V_4 = V_2 -> V_77 + V_124 ;
V_4 -> V_148 = V_37 -> V_145 + V_124 ;
V_4 -> V_149 = ( 1 << V_34 -> V_150 ) - 1 ;
V_4 -> V_151 = V_34 -> V_152 ;
V_4 -> V_153 = V_154 | V_155 | V_156 ;
V_4 -> type = V_157 ;
V_4 -> V_11 = V_34 -> V_158 ;
V_4 -> V_159 = V_4 -> V_11 ;
V_4 -> V_160 = V_34 -> F_28 ;
V_14 -> V_42 = V_2 -> V_42 + 0 ;
F_5 ( 0 , V_14 -> V_42 + 3 ) ;
F_5 ( 0 , V_14 -> V_42 + 4 + 3 ) ;
++ V_124 ;
V_4 = V_2 -> V_77 + V_124 ;
V_4 -> V_148 = V_37 -> V_145 + V_124 ;
V_4 -> V_149 = ( 1 << V_34 -> V_161 ) - 1 ;
V_4 -> V_151 = V_34 -> V_162 ;
V_4 -> V_153 = V_154 ;
V_4 -> type = V_163 ;
V_4 -> V_11 = V_34 -> V_164 ;
V_4 -> V_159 = V_4 -> V_11 ;
V_4 -> V_160 = V_34 -> F_29 ;
V_4 -> V_165 = V_34 -> F_31 ;
V_14 -> V_42 = V_2 -> V_42 + 8 ;
F_5 ( 0 , V_14 -> V_42 + 3 ) ;
F_5 ( 0 , V_14 -> V_42 + 4 + 3 ) ;
++ V_124 ;
V_44 = 0 ;
V_31 = 0 ;
for (; V_124 < ( int ) V_2 -> V_78 ; ++ V_124 ) {
int V_8 ;
V_4 = V_2 -> V_77 + V_124 ;
V_4 -> V_148 = V_37 -> V_145 + V_124 ;
V_4 -> V_149 = 1 ;
V_4 -> V_151 = & V_166 ;
V_4 -> V_153 = V_154 | V_167 ;
V_4 -> type = V_168 ;
V_4 -> V_169 = F_1 ;
V_4 -> V_170 = F_6 ;
V_4 -> V_11 = F_39 ( V_125 , V_171 ) ;
V_14 -> V_54 . V_55 . V_31 = - 1 ;
V_14 -> V_54 . V_55 . V_82 = - 1 ;
V_14 -> V_54 . V_55 . V_61 = - 1 ;
V_14 -> V_54 . V_55 . V_60 = - 1 ;
V_14 -> V_54 . V_55 . V_57 = 0 ;
V_4 -> V_159 = 1 ;
for ( V_8 = 0 ; V_8 < V_172 ; ++ V_8 , ++ V_44 ) {
if ( V_44 >= V_46 ) {
V_44 = 0 ;
++ V_31 ;
V_128 = 0 ;
}
V_14 -> V_15 [ V_8 ] =
V_37 -> V_38 [ V_31 ] . V_42 + V_44 ;
if ( V_128 <
V_12 * V_73
&& V_14 -> V_54 . V_55 . V_31 < 0 ) {
V_14 -> V_54 . V_55 . V_31 = V_31 ;
V_14 -> V_54 . V_55 . V_57 = 0 ;
V_14 -> V_54 . V_55 . V_92 = 0 ;
V_14 -> V_54 . V_55 . V_82 = V_8 * 8 ;
V_14 -> V_54 . V_55 . V_61 = V_128 ;
V_14 -> V_54 . V_55 . V_60 =
V_4 -> V_11 - V_14 -> V_54 . V_55 . V_82 ;
V_4 -> V_173 = F_22 ;
V_4 -> V_174 = F_24 ;
V_4 -> V_175 = F_25 ;
V_4 -> V_159 =
V_14 -> V_54 . V_55 . V_60 ;
}
V_128 += V_12 ;
}
F_35 ( & V_14 -> V_54 . V_55 . V_71 ) ;
V_125 -= V_4 -> V_11 ;
if ( ! V_125 ) {
V_31 = 0 ;
V_44 = 0 ;
}
}
F_10 ( V_2 ) ;
for ( V_31 = 0 ; V_64 [ 0 ] && V_31 < V_67 ; ++ V_31 ) {
if ( V_64 [ V_31 ]
&& F_40 ( V_64 [ V_31 ] , F_14 ,
V_176 , V_34 -> V_139 , V_2 ) ) {
int V_177 ;
for ( V_177 = V_31 - 1 ; V_177 >= 0 ; -- V_177 ) {
F_41 ( V_64 [ V_177 ] , V_2 ) ;
V_37 -> V_38 [ V_177 ] . V_64 = V_64 [ V_177 ] = 0 ;
}
V_64 [ V_31 ] = 0 ;
}
V_37 -> V_38 [ V_31 ] . V_64 = V_64 [ V_31 ] ;
}
V_2 -> V_64 = V_64 [ 0 ] ;
if ( V_64 [ 0 ] ) {
F_3 ( V_9 L_11 , V_2 -> V_132 , V_64 [ 0 ] ) ;
if ( V_34 -> V_35 == 2 && V_64 [ 1 ] )
F_3 ( V_9 L_12 ,
V_2 -> V_132 , V_64 [ 1 ] ) ;
} else {
F_3 ( V_131 L_13 , V_2 -> V_132 ) ;
}
F_3 ( V_131 L_14 , V_2 -> V_132 ) ;
return 1 ;
}
static void F_42 ( struct V_1 * V_2 )
{
const struct V_33 * V_34 = F_9 ( V_2 ) ;
int V_177 ;
if ( V_2 -> V_42 )
F_43 ( V_2 -> V_42 , V_34 -> V_135 ) ;
for ( V_177 = 0 ; V_177 < V_67 ; ++ V_177 ) {
if ( V_37 && V_37 -> V_38 [ V_177 ] . V_64 )
F_41 ( V_37 -> V_38 [ V_177 ] . V_64 , V_2 ) ;
}
if ( V_37 && V_37 -> V_145 )
F_44 ( V_37 -> V_145 ) ;
}

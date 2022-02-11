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
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned int V_21 = F_7 ( V_6 -> V_22 ) ;
int V_8 = V_21 / 8 ;
int V_23 = V_21 % 8 ;
int V_24 ;
V_24 = F_8 ( V_2 , V_4 , V_6 , V_7 , 0 ) ;
if ( V_24 )
return V_24 ;
if ( V_7 [ 0 ] == V_25 ) {
unsigned long V_13 = V_14 -> V_15 [ V_8 ] ;
unsigned char V_26 ;
V_26 = F_4 ( V_13 ) ;
V_26 &= ~ ( 1 << V_23 ) ;
F_5 ( V_26 , V_13 ) ;
}
return V_6 -> V_20 ;
}
static void F_9 ( struct V_1 * V_2 , int V_27 , int V_28 )
{
struct V_29 * V_30 = V_2 -> V_31 ;
if ( V_27 < 0 || V_27 >= 1 )
return;
if ( V_28 < 0 || V_28 >= V_32 )
return;
V_30 -> V_33 [ V_27 ] . V_34 &= ~ V_35 ;
V_30 -> V_33 [ V_27 ] . V_34 |= V_28 << V_36 ;
F_5 ( V_30 -> V_33 [ V_27 ] . V_34 ,
V_30 -> V_33 [ V_27 ] . V_37 + V_38 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = V_2 -> V_31 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < 1 ; ++ V_27 ) {
int V_39 , V_28 ;
unsigned long V_40 = V_30 -> V_33 [ V_27 ] . V_37 ;
F_9 ( V_2 , V_27 , 0 ) ;
for ( V_39 = 0 ; V_39 < V_41 ; ++ V_39 )
F_5 ( 0 , V_40 + V_42 + V_39 ) ;
for ( V_28 = 1 ; V_28 < V_32 ; ++ V_28 ) {
int V_43 ;
F_9 ( V_2 , V_27 , V_28 ) ;
for ( V_43 = V_44 ;
V_43 < V_44 + V_45 ; ++ V_43 )
F_5 ( 0 , V_40 + V_43 ) ;
}
F_9 ( V_2 , V_27 , 0 ) ;
}
}
static void F_11 ( struct V_1 * V_2 , int V_27 , int V_39 )
{
struct V_29 * V_30 = V_2 -> V_31 ;
if ( V_27 < 0 || V_27 >= 1 )
return;
if ( V_39 < 0 || V_39 >= V_41 )
return;
V_30 -> V_33 [ V_27 ] . V_34 |= 0x1 << V_39 ;
F_5 ( V_30 -> V_33 [ V_27 ] . V_34 ,
V_30 -> V_33 [ V_27 ] . V_37 + V_38 ) ;
return;
}
static void F_12 ( struct V_1 * V_2 , int V_27 , int V_39 )
{
struct V_29 * V_30 = V_2 -> V_31 ;
if ( V_27 < 0 || V_27 >= 1 )
return;
if ( V_39 < 0 || V_39 >= V_41 )
return;
V_30 -> V_33 [ V_27 ] . V_34 &= ~ ( 0x1 << V_39 ) | V_46 ;
F_5 ( V_30 -> V_33 [ V_27 ] . V_34 ,
V_30 -> V_33 [ V_27 ] . V_37 + V_38 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_29 * V_30 = V_2 -> V_31 ;
int V_47 , V_48 , V_27 , V_39 ;
V_27 = V_14 -> V_49 . V_50 . V_27 ;
if ( V_27 < 0 )
return;
V_14 -> V_49 . V_50 . V_51 = 0 ;
V_14 -> V_49 . V_50 . V_52 = 0 ;
V_4 -> V_53 -> V_54 = NULL ;
V_47 = V_14 -> V_49 . V_50 . V_55 / V_12 ;
V_48 = V_14 -> V_49 . V_50 . V_56 / V_12 ;
F_9 ( V_2 , V_27 , V_57 ) ;
for ( V_39 = V_48 ; V_39 < V_48 + V_47 ; ++ V_39 ) {
F_5 ( 0 , V_30 -> V_33 [ V_27 ] . V_37 + V_58 + V_39 ) ;
}
}
static T_1 F_14 ( int V_59 , void * V_60 )
{
int V_27 , V_61 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_60 ;
struct V_29 * V_30 = V_2 -> V_31 ;
int V_62 ;
for ( V_27 = 0 ; V_27 < V_63 ; ++ V_27 ) {
if ( V_59 == V_30 -> V_33 [ V_27 ] . V_59 ) {
unsigned long V_64 ;
unsigned V_65 = 0 ;
unsigned long V_37 = V_30 -> V_33 [ V_27 ] . V_37 ;
unsigned char V_66 ;
F_15 ( & V_30 -> V_33 [ V_27 ] . V_67 ,
V_64 ) ;
V_66 = F_4 ( V_37 + V_68 ) & 0x07 ;
if ( V_66 ) {
int V_39 ;
for ( V_39 = 0 ; V_39 < V_69 ;
++ V_39 ) {
if ( V_66 & ( 0x1 << V_39 ) ) {
unsigned char
V_70 = 0 ;
F_9 ( V_2 , V_27 ,
V_71 ) ;
V_70 =
F_4 ( V_37 +
V_72 + V_39 ) ;
if ( V_70 )
F_5 ( 0 , V_37 +
V_72 +
V_39 ) ;
V_65 |=
V_70 <<
V_39 * 8 ;
}
}
++ V_61 ;
}
F_16 ( & V_30 -> V_33 [ V_27 ] . V_67 ,
V_64 ) ;
if ( V_65 ) {
struct V_3 * V_4 ;
F_3
( V_9 L_6 ,
V_59 , V_27 , V_65 ) ;
for ( V_62 = 2 ; V_62 < V_2 -> V_73 ; V_62 ++ ) {
V_4 = & V_2 -> V_74 [ V_62 ] ;
if ( V_14 -> V_49 . V_50 . V_27 == V_27 ) {
unsigned long V_64 ;
unsigned V_75 ;
F_15 ( & V_14 -> V_49 .
V_50 . V_67 ,
V_64 ) ;
V_75 = V_4 -> V_53 -> V_76 ;
if ( V_14 -> V_49 . V_50 . V_52 ) {
unsigned V_77 =
( ( V_65 >>
V_14 -> V_49 . V_50 . V_56 )
&
( ( 0x1 << V_14 ->
V_49 . V_50 .
V_55 ) -
1 ) ) << V_14 ->
V_49 . V_50 . V_78 ;
if ( V_77 &
V_14 -> V_49 .
V_50 . V_51 ) {
unsigned int V_26
= 0 ;
unsigned int V_20 ,
V_79 , V_80 ;
V_80 =
V_4 ->
V_53 -> V_81 . V_82 ;
for ( V_20 = 0 ;
V_20 < V_80 ;
V_20 ++ ) {
V_79 = F_7 ( V_4 -> V_53 -> V_81 . V_83 [ V_20 ] ) ;
if ( V_77 & ( 1U << V_79 ) )
V_26 |= ( 1U << V_20 ) ;
}
if ( F_17 ( V_4 -> V_53 , V_26 )
&&
F_17
( V_4 -> V_53 ,
V_26 >> 16 ) ) {
V_4 -> V_53 -> V_76 |= ( V_84 | V_85 ) ;
} else {
F_13
( V_2 ,
V_4 ) ;
}
if ( ! V_14 -> V_49 . V_50 . V_86 ) {
if ( V_14 -> V_49 . V_50 . V_87 > 0 ) {
V_14 -> V_49 . V_50 . V_87 -- ;
if ( V_14 -> V_49 . V_50 . V_87 == 0 ) {
V_4 -> V_53 -> V_76 |= V_88 ;
F_13
( V_2 ,
V_4 ) ;
}
}
}
}
}
F_16
( & V_14 -> V_49 . V_50 .
V_67 , V_64 ) ;
if ( V_75 !=
V_4 -> V_53 -> V_76 ) {
F_18 ( V_2 , V_4 ) ;
}
}
}
}
}
}
if ( ! V_61 )
return V_89 ;
return V_90 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_29 * V_30 = V_2 -> V_31 ;
if ( ! V_14 -> V_49 . V_50 . V_86 && V_14 -> V_49 . V_50 . V_87 == 0 ) {
V_4 -> V_53 -> V_76 |= V_88 ;
V_14 -> V_49 . V_50 . V_52 = 0 ;
return 1 ;
} else {
unsigned V_91 = 0 , V_92 = 0 , V_20 ;
int V_47 , V_48 , V_27 , V_39 ;
struct V_93 * V_81 = & V_4 -> V_53 -> V_81 ;
V_27 = V_14 -> V_49 . V_50 . V_27 ;
if ( V_27 < 0 )
return 1 ;
V_14 -> V_49 . V_50 . V_51 = 0 ;
V_14 -> V_49 . V_50 . V_52 = 1 ;
V_47 = V_14 -> V_49 . V_50 . V_55 / V_12 ;
V_48 = V_14 -> V_49 . V_50 . V_56 / V_12 ;
if ( V_81 -> V_83 ) {
for ( V_20 = 0 ; V_20 < V_81 -> V_82 ; V_20 ++ ) {
V_91 |= ( 1U << F_7 ( V_81 -> V_83 [ V_20 ] ) ) ;
V_92 |= ( F_20 ( V_81 -> V_83 [ V_20 ] )
|| F_21 ( V_81 ->
V_83 [ V_20 ] ) ? 1U : 0U )
<< F_7 ( V_81 -> V_83 [ V_20 ] ) ;
}
}
V_91 &= ( ( 0x1 << V_14 -> V_49 . V_50 . V_55 ) -
1 ) << V_14 -> V_49 . V_50 . V_78 ;
V_14 -> V_49 . V_50 . V_51 = V_91 ;
{
unsigned char V_94 ;
F_5 ( 1 << 4 , V_2 -> V_37 + 3 ) ;
V_94 = V_2 -> V_59 & ( ( 1 << 4 ) - 1 ) ;
F_5 ( V_94 , V_2 -> V_37 + 2 ) ;
}
F_9 ( V_2 , V_27 , V_57 ) ;
for ( V_39 = V_48 ; V_39 < V_48 + V_47 ; ++ V_39 ) {
unsigned V_95 =
V_91 >> ( V_14 -> V_49 . V_50 . V_78 + ( V_39 -
V_48 )
* 8 ) & 0xff , V_96 =
V_92 >> ( V_14 -> V_49 . V_50 . V_78 +
( V_39 - V_48 ) * 8 ) & 0xff ;
F_5 ( V_95 ,
V_30 -> V_33 [ V_27 ] . V_37 + V_58 + V_39 ) ;
F_9 ( V_2 , V_27 , V_97 ) ;
F_5 ( V_96 ,
V_30 -> V_33 [ V_27 ] . V_37 + V_58 + V_39 ) ;
}
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_64 ;
F_15 ( & V_14 -> V_49 . V_50 . V_67 , V_64 ) ;
if ( V_14 -> V_49 . V_50 . V_52 )
F_13 ( V_2 , V_4 ) ;
F_16 ( & V_14 -> V_49 . V_50 . V_67 , V_64 ) ;
return 0 ;
}
static int
F_23 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_98 )
{
unsigned long V_64 ;
int V_99 = 0 ;
if ( V_98 != 0 )
return - V_100 ;
F_15 ( & V_14 -> V_49 . V_50 . V_67 , V_64 ) ;
V_4 -> V_53 -> V_54 = NULL ;
if ( V_14 -> V_49 . V_50 . V_52 )
V_99 = F_19 ( V_2 , V_4 ) ;
F_16 ( & V_14 -> V_49 . V_50 . V_67 , V_64 ) ;
if ( V_99 )
F_18 ( V_2 , V_4 ) ;
return 1 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_93 * V_81 = & V_4 -> V_53 -> V_81 ;
unsigned long V_64 ;
int V_99 = 0 ;
F_15 ( & V_14 -> V_49 . V_50 . V_67 , V_64 ) ;
V_14 -> V_49 . V_50 . V_52 = 1 ;
switch ( V_81 -> V_101 ) {
case V_102 :
V_14 -> V_49 . V_50 . V_86 = 0 ;
V_14 -> V_49 . V_50 . V_87 = V_81 -> V_103 ;
break;
default:
V_14 -> V_49 . V_50 . V_86 = 1 ;
V_14 -> V_49 . V_50 . V_87 = 0 ;
break;
}
switch ( V_81 -> V_104 ) {
case V_105 :
V_4 -> V_53 -> V_54 = F_23 ;
break;
default:
V_99 = F_19 ( V_2 , V_4 ) ;
break;
}
F_16 ( & V_14 -> V_49 . V_50 . V_67 , V_64 ) ;
if ( V_99 )
F_18 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_93 * V_81 )
{
int V_106 = 0 ;
V_106 |= F_26 ( & V_81 -> V_104 , V_107 | V_105 ) ;
V_106 |= F_26 ( & V_81 -> V_108 , V_109 ) ;
V_106 |= F_26 ( & V_81 -> V_110 , V_107 ) ;
V_106 |= F_26 ( & V_81 -> V_111 , V_102 ) ;
V_106 |= F_26 ( & V_81 -> V_101 , V_102 | V_112 ) ;
if ( V_106 )
return 1 ;
V_106 |= F_27 ( V_81 -> V_104 ) ;
V_106 |= F_27 ( V_81 -> V_101 ) ;
if ( V_106 )
return 2 ;
V_106 |= F_28 ( & V_81 -> V_113 , 0 ) ;
V_106 |= F_28 ( & V_81 -> V_114 , 0 ) ;
V_106 |= F_28 ( & V_81 -> V_115 , 0 ) ;
V_106 |= F_28 ( & V_81 -> V_116 , V_81 -> V_82 ) ;
switch ( V_81 -> V_101 ) {
case V_102 :
break;
case V_112 :
V_106 |= F_28 ( & V_81 -> V_103 , 0 ) ;
break;
default:
break;
}
if ( V_106 )
return 3 ;
return 0 ;
}
static int F_29 ( unsigned long V_37 )
{
unsigned long V_117 = 100000 ;
while ( V_117 -- )
if ( F_4 ( V_37 + 3 ) & 0x80 )
return 0 ;
return 1 ;
}
static int F_30 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_20 ;
unsigned long V_37 = V_14 -> V_37 ;
for ( V_20 = 0 ; V_20 < V_6 -> V_20 ; V_20 ++ ) {
unsigned V_21 = F_7 ( V_6 -> V_22 ) , V_118 =
F_21 ( V_6 -> V_22 ) , V_119 = F_20 ( V_6 -> V_22 ) ;
unsigned char V_120 = 0 ;
unsigned V_121 = 0 ;
unsigned short V_122 , V_123 = 0 ;
if ( V_21 > 7 )
V_21 -= 8 , V_121 = 4 ;
if ( V_119 != V_124 ) {
V_119 = V_125 ;
V_120 |= 1 << 7 ;
}
if ( V_118 < 2 )
V_123 = 0x8000 ;
if ( V_21 % 2 ) {
V_120 |= 1 << 6 ;
}
V_120 |= ( ( V_21 / 2 ) & 0x3 ) << 4 ;
V_120 |= ( V_118 & 0x3 ) << 2 ;
F_5 ( V_120 , V_37 + V_121 + 2 ) ;
F_29 ( V_37 + V_121 ) ;
F_5 ( V_120 , V_37 + V_121 + 2 ) ;
F_29 ( V_37 + V_121 ) ;
V_122 = F_4 ( V_37 + V_121 + 0 ) ;
V_122 |= F_4 ( V_37 + V_121 + 1 ) << 8 ;
V_122 += V_123 ;
V_7 [ V_20 ] = V_122 ;
}
return V_20 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_6 -> V_20 ; V_20 ++ ) {
unsigned V_21 = F_7 ( V_6 -> V_22 ) ;
if ( V_21 < V_4 -> V_11 )
V_7 [ V_20 ] = V_14 -> V_126 . V_127 [ V_21 ] ;
}
return V_20 ;
}
static int F_32 ( unsigned long V_37 )
{
unsigned long V_117 = 100000L ;
while ( V_117 -- ) {
if ( F_4 ( V_37 + 3 ) & 0x80 )
return 0 ;
}
return 1 ;
}
static int F_33 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_20 ;
unsigned V_37 = V_14 -> V_37 , V_121 = 0 ;
for ( V_20 = 0 ; V_20 < V_6 -> V_20 ; V_20 ++ ) {
unsigned V_21 = F_7 ( V_6 -> V_22 ) , V_118 =
F_21 ( V_6 -> V_22 ) ;
if ( V_21 < V_4 -> V_11 ) {
unsigned char V_120 = 0 , V_128 =
V_118 & ( ( 1 << 4 ) - 1 ) ;
if ( V_21 >= 4 )
V_21 -= 4 , V_121 += 4 ;
F_5 ( V_128 , V_37 + V_121 + 0 ) ;
F_5 ( 0 , V_37 + V_121 + 1 ) ;
V_120 = ( V_21 << 1 ) | 0x60 ;
F_5 ( V_120 , V_37 + V_121 + 2 ) ;
F_32 ( V_37 + V_121 ) ;
F_5 ( V_7 [ V_20 ] & 0xff , V_37 + V_121 + 0 ) ;
F_5 ( ( V_7 [ V_20 ] >> 8 ) & 0xff , V_37 + V_121 + 1 ) ;
V_120 = 0x70 | ( V_21 << 1 ) ;
F_5 ( V_120 , V_37 + V_121 + 2 ) ;
F_32 ( V_37 + V_121 ) ;
V_14 -> V_126 . V_127 [ V_21 ] = V_7 [ V_20 ] ;
}
}
return V_20 ;
}
static int F_34 ( struct V_1 * V_2 , struct V_129 * V_130 )
{
struct V_29 * V_30 ;
struct V_3 * V_4 ;
int V_131 , V_132 , V_133 , V_134 , V_39 , V_27 ,
V_135 = 0 ;
unsigned int V_59 [ V_63 ] ;
int V_24 ;
V_59 [ 0 ] = V_130 -> V_136 [ 1 ] ;
V_24 = F_35 ( V_2 , V_130 -> V_136 [ 0 ] , 32 ) ;
if ( V_24 )
return V_24 ;
V_30 = F_36 ( V_2 , sizeof( * V_30 ) ) ;
if ( ! V_30 )
return - V_137 ;
for ( V_27 = 0 ; V_27 < V_63 ; ++ V_27 ) {
V_30 -> V_33 [ V_27 ] . V_138 = V_27 ;
V_30 -> V_33 [ V_27 ] . V_37 =
V_2 -> V_37 + 16 + V_27 * V_139 ;
V_30 -> V_33 [ V_27 ] . V_59 = 0 ;
F_37 ( & V_30 -> V_33 [ V_27 ] . V_67 ) ;
}
V_132 = V_140 * 1 ;
V_133 = F_38 ( V_132 ) ;
V_134 = V_133 + 2 ;
V_30 -> V_141 =
F_39 ( V_134 , sizeof( struct V_142 ) ,
V_143 ) ;
if ( ! V_30 -> V_141 ) {
F_3 ( V_144 L_7 ,
V_2 -> V_145 ) ;
return - V_137 ;
}
V_24 = F_40 ( V_2 , V_134 ) ;
if ( V_24 )
return V_24 ;
V_4 = & V_2 -> V_74 [ 0 ] ;
V_4 -> V_31 = & V_30 -> V_141 [ 0 ] ;
V_4 -> V_146 = 0xffff ;
V_4 -> V_147 = & V_148 ;
V_4 -> V_149 = V_150 | V_151 | V_152 ;
V_4 -> type = V_153 ;
V_4 -> V_11 = 16 ;
V_4 -> V_154 = V_4 -> V_11 ;
V_4 -> V_155 = F_30 ;
V_14 -> V_37 = V_2 -> V_37 + 0 ;
F_5 ( 0 , V_14 -> V_37 + 3 ) ;
F_5 ( 0 , V_14 -> V_37 + 4 + 3 ) ;
V_4 = & V_2 -> V_74 [ 1 ] ;
V_4 -> V_31 = & V_30 -> V_141 [ 1 ] ;
V_4 -> V_146 = 0xffff ;
V_4 -> V_147 = & V_156 ;
V_4 -> V_149 = V_150 ;
V_4 -> type = V_157 ;
V_4 -> V_11 = 8 ;
V_4 -> V_154 = V_4 -> V_11 ;
V_4 -> V_155 = F_31 ;
V_4 -> V_158 = F_33 ;
V_14 -> V_37 = V_2 -> V_37 + 8 ;
F_5 ( 0 , V_14 -> V_37 + 3 ) ;
F_5 ( 0 , V_14 -> V_37 + 4 + 3 ) ;
V_39 = 0 ;
V_27 = 0 ;
for ( V_131 = 2 ; V_131 < V_2 -> V_73 ; ++ V_131 ) {
int V_8 ;
V_4 = & V_2 -> V_74 [ V_131 ] ;
V_4 -> V_31 = & V_30 -> V_141 [ V_131 ] ;
V_4 -> V_146 = 1 ;
V_4 -> V_147 = & V_159 ;
V_4 -> V_149 = V_150 | V_160 ;
V_4 -> type = V_161 ;
V_4 -> V_162 = F_1 ;
V_4 -> V_163 = F_6 ;
V_4 -> V_11 = F_41 ( V_132 , V_164 ) ;
V_14 -> V_49 . V_50 . V_27 = - 1 ;
V_14 -> V_49 . V_50 . V_78 = - 1 ;
V_14 -> V_49 . V_50 . V_56 = - 1 ;
V_14 -> V_49 . V_50 . V_55 = - 1 ;
V_14 -> V_49 . V_50 . V_52 = 0 ;
V_4 -> V_154 = 1 ;
for ( V_8 = 0 ; V_8 < V_165 ; ++ V_8 , ++ V_39 ) {
if ( V_39 >= V_41 ) {
V_39 = 0 ;
++ V_27 ;
V_135 = 0 ;
}
V_14 -> V_15 [ V_8 ] =
V_30 -> V_33 [ V_27 ] . V_37 + V_39 ;
if ( V_135 <
V_12 * V_69
&& V_14 -> V_49 . V_50 . V_27 < 0 ) {
V_14 -> V_49 . V_50 . V_27 = V_27 ;
V_14 -> V_49 . V_50 . V_52 = 0 ;
V_14 -> V_49 . V_50 . V_87 = 0 ;
V_14 -> V_49 . V_50 . V_78 = V_8 * 8 ;
V_14 -> V_49 . V_50 . V_56 = V_135 ;
V_14 -> V_49 . V_50 . V_55 =
V_4 -> V_11 - V_14 -> V_49 . V_50 . V_78 ;
V_4 -> V_166 = F_22 ;
V_4 -> V_167 = F_24 ;
V_4 -> V_168 = F_25 ;
V_4 -> V_154 =
V_14 -> V_49 . V_50 . V_55 ;
}
V_135 += V_12 ;
}
F_37 ( & V_14 -> V_49 . V_50 . V_67 ) ;
V_132 -= V_4 -> V_11 ;
if ( ! V_132 ) {
V_27 = 0 ;
V_39 = 0 ;
}
}
F_10 ( V_2 ) ;
for ( V_27 = 0 ; V_59 [ 0 ] && V_27 < V_63 ; ++ V_27 ) {
if ( V_59 [ V_27 ]
&& F_42 ( V_59 [ V_27 ] , F_14 ,
V_169 , V_2 -> V_170 , V_2 ) ) {
int V_62 ;
for ( V_62 = V_27 - 1 ; V_62 >= 0 ; -- V_62 ) {
F_43 ( V_59 [ V_62 ] , V_2 ) ;
V_30 -> V_33 [ V_62 ] . V_59 = V_59 [ V_62 ] = 0 ;
}
V_59 [ V_27 ] = 0 ;
}
V_30 -> V_33 [ V_27 ] . V_59 = V_59 [ V_27 ] ;
}
return 1 ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = V_2 -> V_31 ;
int V_62 ;
if ( V_30 ) {
for ( V_62 = 0 ; V_62 < V_63 ; ++ V_62 ) {
if ( V_30 -> V_33 [ V_62 ] . V_59 )
F_43 ( V_30 -> V_33 [ V_62 ] . V_59 , V_2 ) ;
}
F_45 ( V_30 -> V_141 ) ;
}
F_46 ( V_2 ) ;
}

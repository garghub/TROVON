static unsigned int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 + V_4 -> V_6 + V_4 -> V_7 ;
}
static void F_3 ( struct V_1 * V_2 )
{
unsigned int V_8 = F_1 ( V_2 ) ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_8 ; ++ V_9 )
F_4 ( 0x00 , V_2 -> V_10 + F_5 ( V_9 ) ) ;
F_6 ( 0x00000000 , V_2 -> V_10 + V_11 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
unsigned int V_12 ,
unsigned int V_13 ,
unsigned int V_14 )
{
unsigned int V_8 = F_1 ( V_2 ) ;
unsigned int V_15 ;
if ( V_12 >= F_8 ( V_8 ) )
return;
for ( V_15 = F_9 ( V_12 ) ; V_15 < V_8 ; V_15 ++ ) {
int V_16 = ( int ) ( F_8 ( V_15 ) - V_12 ) ;
unsigned int V_17 , V_18 , V_19 ;
if ( V_16 >= 32 )
break;
if ( V_16 >= 0 ) {
V_17 = ~ 0U >> V_16 ;
V_18 = V_13 >> V_16 ;
V_19 = V_14 >> V_16 ;
} else {
V_17 = ~ 0U << - V_16 ;
V_18 = V_13 << - V_16 ;
V_19 = V_14 << - V_16 ;
}
if ( V_17 & 0xff ) {
if ( ~ V_17 & 0xff ) {
V_18 |=
F_10 ( V_2 -> V_10 +
F_11 ( V_15 ) ) &
~ V_17 ;
V_19 |=
F_10 ( V_2 -> V_10 +
F_12 ( V_15 ) ) &
~ V_17 ;
}
F_4 ( V_18 & 0xff ,
V_2 -> V_10 + F_11 ( V_15 ) ) ;
F_4 ( V_19 & 0xff ,
V_2 -> V_10 + F_12 ( V_15 ) ) ;
}
}
}
static void F_13 ( struct V_1 * V_2 )
{
F_7 ( V_2 , 0 , 0 , 0 ) ;
F_7 ( V_2 , 32 , 0 , 0 ) ;
F_7 ( V_2 , 64 , 0 , 0 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_22 * V_23 ,
unsigned int * V_24 )
{
unsigned long V_25 = ( unsigned long ) V_21 -> V_26 ;
unsigned int V_27 = F_15 ( V_23 -> V_28 ) ;
unsigned int V_29 = F_16 ( V_27 ) ;
unsigned V_15 = V_25 + F_9 ( V_27 ) ;
unsigned int V_30 ;
unsigned int V_31 ;
switch ( V_24 [ 0 ] ) {
case V_32 :
V_30 = ( V_24 [ 1 ] + 100 ) / 200 ;
if ( V_30 > 0xfffff )
V_30 = 0xfffff ;
V_24 [ 1 ] = V_30 * 200 ;
V_31 = F_10 ( V_2 -> V_10 + F_5 ( V_15 ) ) ;
if ( V_30 ) {
F_6 ( V_30 , V_2 -> V_10 + V_11 ) ;
V_31 |= V_29 ;
} else {
V_31 &= ~ V_29 ;
}
F_4 ( V_31 , V_2 -> V_10 + F_5 ( V_15 ) ) ;
break;
case V_33 :
if ( V_21 -> type != V_34 )
return - V_35 ;
F_4 ( V_36 ,
V_2 -> V_10 + F_17 ( V_15 ) ) ;
break;
case V_37 :
if ( V_21 -> type != V_34 )
return - V_35 ;
F_4 ( V_38 ,
V_2 -> V_10 + F_17 ( V_15 ) ) ;
break;
case V_39 :
if ( V_21 -> type != V_34 )
return - V_35 ;
V_31 = F_10 ( V_2 -> V_10 + F_17 ( V_15 ) ) ;
V_24 [ 1 ] = ( V_31 == V_38 ) ? V_40
: V_41 ;
break;
default:
return - V_35 ;
}
return V_23 -> V_42 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_22 * V_23 ,
unsigned int * V_24 )
{
unsigned long V_25 = ( unsigned long ) V_21 -> V_26 ;
unsigned int V_12 = F_15 ( V_23 -> V_28 ) ;
int V_43 = F_9 ( V_21 -> V_44 - 1 ) ;
unsigned V_45 = 0 ;
int V_46 ;
for ( V_46 = F_9 ( V_12 ) ;
V_46 <= V_43 ; V_46 ++ ) {
unsigned V_15 = V_25 + V_46 ;
int V_47 = F_8 ( V_46 ) ;
unsigned V_17 , V_48 , V_49 ;
int V_16 = V_47 - V_12 ;
if ( V_16 >= 32 )
break;
V_17 = V_24 [ 0 ] ;
V_48 = V_24 [ 1 ] ;
if ( V_16 > 0 ) {
V_17 >>= V_16 ;
V_48 >>= V_16 ;
} else {
V_17 <<= - V_16 ;
V_48 <<= - V_16 ;
}
V_17 &= 0xff ;
V_48 &= 0xff ;
if ( V_17 ) {
V_49 = F_10 ( V_2 -> V_10 + F_19 ( V_15 ) ) ;
V_49 ^= V_21 -> V_50 ;
V_49 &= ~ V_17 ;
V_49 |= ( V_48 & V_17 ) ;
V_49 ^= V_21 -> V_50 ;
F_4 ( V_49 , V_2 -> V_10 + F_19 ( V_15 ) ) ;
}
V_49 = F_10 ( V_2 -> V_10 + F_19 ( V_15 ) ) ;
V_49 ^= V_21 -> V_50 ;
if ( V_16 > 0 )
V_49 <<= V_16 ;
else
V_49 >>= - V_16 ;
V_45 |= V_49 ;
}
V_24 [ 1 ] = V_45 ;
return V_23 -> V_42 ;
}
static T_1 F_20 ( int V_51 , void * V_52 )
{
struct V_1 * V_2 = V_52 ;
struct V_20 * V_21 = V_2 -> V_53 ;
unsigned int V_54 ;
V_54 = F_10 ( V_2 -> V_10 + V_55 ) ;
if ( ( V_54 & V_56 ) == 0 )
return V_57 ;
if ( ( V_54 & V_58 ) == 0 )
return V_57 ;
F_4 ( V_59 | V_60 ,
V_2 -> V_10 + V_61 ) ;
F_21 ( V_21 , 0 ) ;
V_21 -> V_62 -> V_63 |= V_64 ;
F_22 ( V_2 , V_21 ) ;
return V_65 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_66 * V_67 )
{
int V_68 = 0 ;
V_68 |= F_24 ( & V_67 -> V_69 , V_70 ) ;
V_68 |= F_24 ( & V_67 -> V_71 , V_72 ) ;
V_68 |= F_24 ( & V_67 -> V_73 , V_74 ) ;
V_68 |= F_24 ( & V_67 -> V_75 , V_76 ) ;
V_68 |= F_24 ( & V_67 -> V_77 , V_76 ) ;
if ( V_68 )
return 1 ;
if ( V_68 )
return 2 ;
V_68 |= F_25 ( & V_67 -> V_78 , 0 ) ;
V_68 |= F_25 ( & V_67 -> V_79 , 0 ) ;
V_68 |= F_25 ( & V_67 -> V_80 , 0 ) ;
V_68 |= F_25 ( & V_67 -> V_81 , V_67 -> V_82 ) ;
V_68 |= F_25 ( & V_67 -> V_83 , 0 ) ;
if ( V_68 )
return 3 ;
if ( V_68 )
return 4 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
F_4 ( V_59 | V_60 ,
V_2 -> V_10 + V_61 ) ;
F_4 ( V_84 | V_85 |
V_86 | V_87 ,
V_2 -> V_10 + V_88 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
F_4 ( 0x00 , V_2 -> V_10 + V_88 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_22 * V_23 ,
unsigned int * V_24 )
{
V_24 [ 1 ] = 0 ;
return V_23 -> V_42 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_22 * V_23 ,
unsigned int * V_24 )
{
switch ( V_24 [ 0 ] ) {
case V_89 :
if ( V_23 -> V_42 != 3 )
return - V_35 ;
F_7 ( V_2 , 0 , V_24 [ 1 ] , V_24 [ 2 ] ) ;
F_7 ( V_2 , 32 , 0 , 0 ) ;
F_7 ( V_2 , 64 , 0 , 0 ) ;
break;
case V_90 :
if ( V_24 [ 1 ] != 0 )
return - V_35 ;
switch ( V_24 [ 2 ] ) {
case V_91 :
F_13 ( V_2 ) ;
break;
case V_92 :
F_7 ( V_2 , V_24 [ 3 ] ,
V_24 [ 4 ] , V_24 [ 5 ] ) ;
break;
default:
return - V_35 ;
}
break;
default:
return - V_35 ;
}
return V_23 -> V_42 ;
}
static int F_30 ( struct V_93 * V_94 )
{
void T_2 * V_95 ;
T_3 V_96 ;
V_95 = F_31 ( V_94 , 0 ) ;
if ( ! V_95 )
return - V_97 ;
V_96 = F_32 ( V_94 , 1 ) ;
F_6 ( V_96 | V_98 , V_95 + V_99 ) ;
F_33 ( V_95 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
unsigned long V_100 )
{
struct V_93 * V_94 = F_35 ( V_2 ) ;
const struct V_3 * V_4 = NULL ;
struct V_20 * V_21 ;
unsigned V_9 ;
int V_101 ;
if ( V_100 < F_36 ( V_102 ) )
V_4 = & V_102 [ V_100 ] ;
if ( ! V_4 )
return - V_103 ;
V_2 -> V_104 = V_4 ;
V_2 -> V_105 = V_4 -> V_106 ;
V_101 = F_37 ( V_2 ) ;
if ( V_101 )
return V_101 ;
V_101 = F_30 ( V_94 ) ;
if ( V_101 )
return V_101 ;
V_2 -> V_10 = F_31 ( V_94 , 1 ) ;
if ( ! V_2 -> V_10 )
return - V_97 ;
F_4 ( V_59 | V_60 ,
V_2 -> V_10 + V_61 ) ;
F_4 ( 0x00 , V_2 -> V_10 + V_88 ) ;
if ( V_94 -> V_51 ) {
V_101 = F_38 ( V_94 -> V_51 , F_20 , V_107 ,
V_2 -> V_105 , V_2 ) ;
if ( V_101 == 0 )
V_2 -> V_51 = V_94 -> V_51 ;
}
F_39 ( V_2 -> V_108 , L_1 , V_2 -> V_105 ,
F_10 ( V_2 -> V_10 + V_109 ) ) ;
V_101 = F_40 ( V_2 , 4 ) ;
if ( V_101 )
return V_101 ;
V_21 = & V_2 -> V_110 [ 0 ] ;
if ( V_4 -> V_6 ) {
V_21 -> type = V_111 ;
V_21 -> V_112 = V_113 ;
V_21 -> V_44 = F_8 ( V_4 -> V_6 ) ;
V_21 -> V_114 = 1 ;
V_21 -> V_115 = & V_116 ;
V_21 -> V_117 = F_18 ;
V_21 -> V_118 = F_14 ;
V_21 -> V_26 = ( void * ) 0 ;
} else {
V_21 -> type = V_119 ;
}
V_21 = & V_2 -> V_110 [ 1 ] ;
if ( V_4 -> V_7 ) {
V_21 -> type = V_120 ;
V_21 -> V_112 = V_121 ;
V_21 -> V_44 = F_8 ( V_4 -> V_7 ) ;
V_21 -> V_114 = 1 ;
V_21 -> V_115 = & V_116 ;
V_21 -> V_117 = F_18 ;
V_21 -> V_26 = ( void * ) ( unsigned long ) V_4 -> V_6 ;
if ( V_122 && V_4 -> V_123 )
V_21 -> V_50 = 0xff ;
for ( V_9 = 0 ; V_9 < V_4 -> V_7 ; ++ V_9 ) {
F_4 ( V_21 -> V_50 ,
V_2 -> V_10 +
F_19 ( V_4 -> V_6 + V_9 ) ) ;
}
} else {
V_21 -> type = V_119 ;
}
V_21 = & V_2 -> V_110 [ 2 ] ;
if ( V_4 -> V_5 ) {
V_21 -> type = V_34 ;
V_21 -> V_112 = V_113 | V_121 ;
V_21 -> V_44 = F_8 ( V_4 -> V_5 ) ;
V_21 -> V_114 = 1 ;
V_21 -> V_115 = & V_116 ;
V_21 -> V_117 = F_18 ;
V_21 -> V_118 = F_14 ;
V_21 -> V_26 = ( void * ) 0 ;
for ( V_9 = 0 ; V_9 < V_4 -> V_5 ; ++ V_9 ) {
F_4 ( V_38 ,
V_2 -> V_10 + F_17 ( V_9 ) ) ;
}
} else {
V_21 -> type = V_119 ;
}
V_21 = & V_2 -> V_110 [ 3 ] ;
V_21 -> type = V_111 ;
V_21 -> V_112 = V_113 ;
V_21 -> V_44 = 1 ;
V_21 -> V_114 = 1 ;
V_21 -> V_115 = & V_116 ;
V_21 -> V_117 = F_28 ;
if ( V_2 -> V_51 ) {
V_2 -> V_53 = V_21 ;
V_21 -> V_112 |= V_124 ;
V_21 -> V_125 = 1 ;
V_21 -> V_118 = F_29 ;
V_21 -> V_126 = F_23 ;
V_21 -> V_127 = F_26 ;
V_21 -> V_128 = F_27 ;
}
F_3 ( V_2 ) ;
F_13 ( V_2 ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 )
{
if ( V_2 -> V_10 ) {
F_4 ( 0x00 , V_2 -> V_10 + V_88 ) ;
F_33 ( V_2 -> V_10 ) ;
}
if ( V_2 -> V_51 )
F_42 ( V_2 -> V_51 , V_2 ) ;
F_43 ( V_2 ) ;
}
static int F_44 ( struct V_93 * V_2 ,
const struct V_129 * V_130 )
{
return F_45 ( V_2 , & V_131 , V_130 -> V_132 ) ;
}

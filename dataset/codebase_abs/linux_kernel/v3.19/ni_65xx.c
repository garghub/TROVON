static unsigned int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
return V_4 -> V_6 + V_4 -> V_7 + V_4 -> V_8 ;
}
static void F_2 ( struct V_1 * V_2 )
{
unsigned int V_9 = F_1 ( V_2 ) ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_9 ; ++ V_10 )
F_3 ( 0x00 , V_2 -> V_11 + F_4 ( V_10 ) ) ;
F_5 ( 0x00000000 , V_2 -> V_11 + V_12 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
unsigned int V_13 ,
unsigned int V_14 ,
unsigned int V_15 )
{
unsigned int V_9 = F_1 ( V_2 ) ;
unsigned int V_16 ;
if ( V_13 >= F_7 ( V_9 ) )
return;
for ( V_16 = F_8 ( V_13 ) ; V_16 < V_9 ; V_16 ++ ) {
int V_17 = ( int ) ( F_7 ( V_16 ) - V_13 ) ;
unsigned int V_18 , V_19 , V_20 ;
if ( V_17 >= 32 )
break;
if ( V_17 >= 0 ) {
V_18 = ~ 0U >> V_17 ;
V_19 = V_14 >> V_17 ;
V_20 = V_15 >> V_17 ;
} else {
V_18 = ~ 0U << - V_17 ;
V_19 = V_14 << - V_17 ;
V_20 = V_15 << - V_17 ;
}
if ( V_18 & 0xff ) {
if ( ~ V_18 & 0xff ) {
V_19 |=
F_9 ( V_2 -> V_11 +
F_10 ( V_16 ) ) &
~ V_18 ;
V_20 |=
F_9 ( V_2 -> V_11 +
F_11 ( V_16 ) ) &
~ V_18 ;
}
F_3 ( V_19 & 0xff ,
V_2 -> V_11 + F_10 ( V_16 ) ) ;
F_3 ( V_20 & 0xff ,
V_2 -> V_11 + F_11 ( V_16 ) ) ;
}
}
}
static void F_12 ( struct V_1 * V_2 )
{
F_6 ( V_2 , 0 , 0 , 0 ) ;
F_6 ( V_2 , 32 , 0 , 0 ) ;
F_6 ( V_2 , 64 , 0 , 0 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 ,
unsigned int * V_25 )
{
unsigned long V_26 = ( unsigned long ) V_22 -> V_27 ;
unsigned int V_28 = F_14 ( V_24 -> V_29 ) ;
unsigned int V_30 = F_15 ( V_28 ) ;
unsigned V_16 = V_26 + F_8 ( V_28 ) ;
unsigned int V_31 ;
unsigned int V_32 ;
switch ( V_25 [ 0 ] ) {
case V_33 :
V_31 = ( V_25 [ 1 ] + 100 ) / 200 ;
if ( V_31 > 0xfffff )
V_31 = 0xfffff ;
V_25 [ 1 ] = V_31 * 200 ;
V_32 = F_9 ( V_2 -> V_11 + F_4 ( V_16 ) ) ;
if ( V_31 ) {
F_5 ( V_31 , V_2 -> V_11 + V_12 ) ;
V_32 |= V_30 ;
} else {
V_32 &= ~ V_30 ;
}
F_3 ( V_32 , V_2 -> V_11 + F_4 ( V_16 ) ) ;
break;
case V_34 :
if ( V_22 -> type != V_35 )
return - V_36 ;
F_3 ( V_37 ,
V_2 -> V_11 + F_16 ( V_16 ) ) ;
break;
case V_38 :
if ( V_22 -> type != V_35 )
return - V_36 ;
F_3 ( V_39 ,
V_2 -> V_11 + F_16 ( V_16 ) ) ;
break;
case V_40 :
if ( V_22 -> type != V_35 )
return - V_36 ;
V_32 = F_9 ( V_2 -> V_11 + F_16 ( V_16 ) ) ;
V_25 [ 1 ] = ( V_32 == V_39 ) ? V_41
: V_42 ;
break;
default:
return - V_36 ;
}
return V_24 -> V_43 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 ,
unsigned int * V_25 )
{
unsigned long V_26 = ( unsigned long ) V_22 -> V_27 ;
unsigned int V_13 = F_14 ( V_24 -> V_29 ) ;
int V_44 = F_8 ( V_22 -> V_45 - 1 ) ;
unsigned V_46 = 0 ;
int V_47 ;
for ( V_47 = F_8 ( V_13 ) ;
V_47 <= V_44 ; V_47 ++ ) {
unsigned V_16 = V_26 + V_47 ;
int V_48 = F_7 ( V_47 ) ;
unsigned V_18 , V_49 , V_50 ;
int V_17 = V_48 - V_13 ;
if ( V_17 >= 32 )
break;
V_18 = V_25 [ 0 ] ;
V_49 = V_25 [ 1 ] ;
if ( V_17 > 0 ) {
V_18 >>= V_17 ;
V_49 >>= V_17 ;
} else {
V_18 <<= - V_17 ;
V_49 <<= - V_17 ;
}
V_18 &= 0xff ;
V_49 &= 0xff ;
if ( V_18 ) {
V_50 = F_9 ( V_2 -> V_11 + F_18 ( V_16 ) ) ;
V_50 ^= V_22 -> V_51 ;
V_50 &= ~ V_18 ;
V_50 |= ( V_49 & V_18 ) ;
V_50 ^= V_22 -> V_51 ;
F_3 ( V_50 , V_2 -> V_11 + F_18 ( V_16 ) ) ;
}
V_50 = F_9 ( V_2 -> V_11 + F_18 ( V_16 ) ) ;
V_50 ^= V_22 -> V_51 ;
if ( V_17 > 0 )
V_50 <<= V_17 ;
else
V_50 >>= - V_17 ;
V_46 |= V_50 ;
}
V_25 [ 1 ] = V_46 ;
return V_24 -> V_43 ;
}
static T_1 F_19 ( int V_52 , void * V_53 )
{
struct V_1 * V_2 = V_53 ;
struct V_21 * V_22 = V_2 -> V_54 ;
unsigned int V_55 ;
V_55 = F_9 ( V_2 -> V_11 + V_56 ) ;
if ( ( V_55 & V_57 ) == 0 )
return V_58 ;
if ( ( V_55 & V_59 ) == 0 )
return V_58 ;
F_3 ( V_60 | V_61 ,
V_2 -> V_11 + V_62 ) ;
F_20 ( V_22 , & V_22 -> V_63 , 1 ) ;
F_21 ( V_2 , V_22 ) ;
return V_64 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_65 * V_66 )
{
int V_67 = 0 ;
V_67 |= F_23 ( & V_66 -> V_68 , V_69 ) ;
V_67 |= F_23 ( & V_66 -> V_70 , V_71 ) ;
V_67 |= F_23 ( & V_66 -> V_72 , V_73 ) ;
V_67 |= F_23 ( & V_66 -> V_74 , V_75 ) ;
V_67 |= F_23 ( & V_66 -> V_76 , V_75 ) ;
if ( V_67 )
return 1 ;
V_67 |= F_24 ( & V_66 -> V_77 , 0 ) ;
V_67 |= F_24 ( & V_66 -> V_78 , 0 ) ;
V_67 |= F_24 ( & V_66 -> V_79 , 0 ) ;
V_67 |= F_24 ( & V_66 -> V_80 , V_66 -> V_81 ) ;
V_67 |= F_24 ( & V_66 -> V_82 , 0 ) ;
if ( V_67 )
return 3 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
F_3 ( V_60 | V_61 ,
V_2 -> V_11 + V_62 ) ;
F_3 ( V_83 | V_84 |
V_85 | V_86 ,
V_2 -> V_11 + V_87 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
F_3 ( 0x00 , V_2 -> V_11 + V_87 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 ,
unsigned int * V_25 )
{
V_25 [ 1 ] = 0 ;
return V_24 -> V_43 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 ,
unsigned int * V_25 )
{
switch ( V_25 [ 0 ] ) {
case V_88 :
if ( V_24 -> V_43 != 3 )
return - V_36 ;
F_6 ( V_2 , 0 , V_25 [ 1 ] , V_25 [ 2 ] ) ;
F_6 ( V_2 , 32 , 0 , 0 ) ;
F_6 ( V_2 , 64 , 0 , 0 ) ;
break;
case V_89 :
if ( V_25 [ 1 ] != 0 )
return - V_36 ;
switch ( V_25 [ 2 ] ) {
case V_90 :
F_12 ( V_2 ) ;
break;
case V_91 :
F_6 ( V_2 , V_25 [ 3 ] ,
V_25 [ 4 ] , V_25 [ 5 ] ) ;
break;
default:
return - V_36 ;
}
break;
default:
return - V_36 ;
}
return V_24 -> V_43 ;
}
static int F_29 ( struct V_92 * V_93 )
{
void T_2 * V_94 ;
T_3 V_95 ;
V_94 = F_30 ( V_93 , 0 ) ;
if ( ! V_94 )
return - V_96 ;
V_95 = F_31 ( V_93 , 1 ) ;
F_5 ( V_95 | V_97 , V_94 + V_98 ) ;
F_32 ( V_94 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
unsigned long V_99 )
{
struct V_92 * V_93 = F_34 ( V_2 ) ;
const struct V_3 * V_4 = NULL ;
struct V_21 * V_22 ;
unsigned V_10 ;
int V_100 ;
if ( V_99 < F_35 ( V_101 ) )
V_4 = & V_101 [ V_99 ] ;
if ( ! V_4 )
return - V_102 ;
V_2 -> V_5 = V_4 ;
V_2 -> V_103 = V_4 -> V_104 ;
V_100 = F_36 ( V_2 ) ;
if ( V_100 )
return V_100 ;
V_100 = F_29 ( V_93 ) ;
if ( V_100 )
return V_100 ;
V_2 -> V_11 = F_30 ( V_93 , 1 ) ;
if ( ! V_2 -> V_11 )
return - V_96 ;
F_3 ( V_60 | V_61 ,
V_2 -> V_11 + V_62 ) ;
F_3 ( 0x00 , V_2 -> V_11 + V_87 ) ;
if ( V_93 -> V_52 ) {
V_100 = F_37 ( V_93 -> V_52 , F_19 , V_105 ,
V_2 -> V_103 , V_2 ) ;
if ( V_100 == 0 )
V_2 -> V_52 = V_93 -> V_52 ;
}
F_38 ( V_2 -> V_106 , L_1 , V_2 -> V_103 ,
F_9 ( V_2 -> V_11 + V_107 ) ) ;
V_100 = F_39 ( V_2 , 4 ) ;
if ( V_100 )
return V_100 ;
V_22 = & V_2 -> V_108 [ 0 ] ;
if ( V_4 -> V_7 ) {
V_22 -> type = V_109 ;
V_22 -> V_110 = V_111 ;
V_22 -> V_45 = F_7 ( V_4 -> V_7 ) ;
V_22 -> V_112 = 1 ;
V_22 -> V_113 = & V_114 ;
V_22 -> V_115 = F_17 ;
V_22 -> V_116 = F_13 ;
V_22 -> V_27 = ( void * ) 0 ;
} else {
V_22 -> type = V_117 ;
}
V_22 = & V_2 -> V_108 [ 1 ] ;
if ( V_4 -> V_8 ) {
V_22 -> type = V_118 ;
V_22 -> V_110 = V_119 ;
V_22 -> V_45 = F_7 ( V_4 -> V_8 ) ;
V_22 -> V_112 = 1 ;
V_22 -> V_113 = & V_114 ;
V_22 -> V_115 = F_17 ;
V_22 -> V_27 = ( void * ) ( unsigned long ) V_4 -> V_7 ;
if ( V_120 && V_4 -> V_121 )
V_22 -> V_51 = 0xff ;
for ( V_10 = 0 ; V_10 < V_4 -> V_8 ; ++ V_10 ) {
F_3 ( V_22 -> V_51 ,
V_2 -> V_11 +
F_18 ( V_4 -> V_7 + V_10 ) ) ;
}
} else {
V_22 -> type = V_117 ;
}
V_22 = & V_2 -> V_108 [ 2 ] ;
if ( V_4 -> V_6 ) {
V_22 -> type = V_35 ;
V_22 -> V_110 = V_111 | V_119 ;
V_22 -> V_45 = F_7 ( V_4 -> V_6 ) ;
V_22 -> V_112 = 1 ;
V_22 -> V_113 = & V_114 ;
V_22 -> V_115 = F_17 ;
V_22 -> V_116 = F_13 ;
V_22 -> V_27 = ( void * ) 0 ;
for ( V_10 = 0 ; V_10 < V_4 -> V_6 ; ++ V_10 ) {
F_3 ( V_39 ,
V_2 -> V_11 + F_16 ( V_10 ) ) ;
}
} else {
V_22 -> type = V_117 ;
}
V_22 = & V_2 -> V_108 [ 3 ] ;
V_22 -> type = V_109 ;
V_22 -> V_110 = V_111 ;
V_22 -> V_45 = 1 ;
V_22 -> V_112 = 1 ;
V_22 -> V_113 = & V_114 ;
V_22 -> V_115 = F_27 ;
if ( V_2 -> V_52 ) {
V_2 -> V_54 = V_22 ;
V_22 -> V_110 |= V_122 ;
V_22 -> V_123 = 1 ;
V_22 -> V_116 = F_28 ;
V_22 -> V_124 = F_22 ;
V_22 -> V_125 = F_25 ;
V_22 -> V_126 = F_26 ;
}
F_2 ( V_2 ) ;
F_12 ( V_2 ) ;
return 0 ;
}
static void F_40 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 )
F_3 ( 0x00 , V_2 -> V_11 + V_87 ) ;
F_41 ( V_2 ) ;
}
static int F_42 ( struct V_92 * V_2 ,
const struct V_127 * V_128 )
{
return F_43 ( V_2 , & V_129 , V_128 -> V_130 ) ;
}

static void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_3 == V_4 || V_3 == V_5 )
V_3 |= F_2 ( V_2 -> V_6 ) ;
F_3 ( V_3 , V_2 -> V_7 + V_8 ) ;
}
static unsigned int F_4 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
unsigned int V_11 ;
V_11 = F_5 ( V_2 -> V_7 + V_12 ) << 8 ;
V_11 |= F_5 ( V_2 -> V_7 + V_13 ) ;
return V_11 & V_10 -> V_14 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
F_3 ( V_15 , V_2 -> V_7 + V_16 ) ;
F_1 ( V_2 , V_17 ) ;
return 0 ;
}
static T_1 F_7 ( int V_6 , void * V_18 )
{
struct V_1 * V_2 = V_18 ;
struct V_19 * V_20 = V_2 -> V_21 ;
struct V_9 * V_10 = V_2 -> V_22 ;
unsigned int V_23 ;
if ( ! V_2 -> V_24 ) {
F_8 ( V_2 , L_1 ) ;
return V_25 ;
}
V_23 = F_4 ( V_2 , V_10 ) ;
F_3 ( V_15 , V_2 -> V_7 + V_16 ) ;
if ( F_9 ( V_10 -> V_26 , V_23 ) == 0 ) {
V_10 -> V_26 -> V_27 |= V_28 | V_29 ;
} else {
V_10 -> V_26 -> V_27 |= V_30 | V_31 ;
if ( V_10 -> V_26 -> V_32 . V_33 == V_34 &&
! ( -- V_20 -> V_35 ) ) {
F_1 ( V_2 , V_17 ) ;
V_10 -> V_26 -> V_27 |= V_36 ;
}
}
F_10 ( V_2 , V_10 ) ;
return V_25 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
unsigned int V_37 )
{
unsigned int V_38 = F_12 ( V_37 ) ;
unsigned int V_39 = F_13 ( V_37 ) ;
unsigned int V_40 = F_14 ( V_37 ) ;
unsigned int V_41 = 0 ;
F_3 ( F_15 ( V_39 ) , V_2 -> V_7 + V_42 ) ;
if ( V_10 -> V_43 > 8 ) {
if ( V_40 == V_44 ) {
V_38 &= 0x7 ;
V_41 |= V_45 ;
} else {
if ( V_38 < 8 )
V_41 |= V_46 ;
else
V_41 |= V_47 ;
}
}
F_3 ( V_41 | F_16 ( V_38 ) , V_2 -> V_7 + V_48 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
unsigned int V_49 )
{
unsigned int V_50 ;
while ( V_49 -- ) {
V_50 = F_5 ( V_2 -> V_7 + V_12 ) ;
if ( ( V_50 & V_51 ) == 0 )
return 0 ;
F_18 ( 1 ) ;
}
return - V_52 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_53 * V_54 ,
unsigned int * V_23 )
{
int V_55 ;
int V_56 ;
F_11 ( V_2 , V_10 , V_54 -> V_37 ) ;
F_1 ( V_2 , V_17 ) ;
for ( V_56 = 0 ; V_56 < V_54 -> V_57 ; V_56 ++ ) {
F_3 ( V_58 , V_2 -> V_7 + V_59 ) ;
V_55 = F_17 ( V_2 , 100 ) ;
if ( V_55 )
return V_55 ;
V_23 [ V_56 ] = F_4 ( V_2 , V_10 ) ;
}
return V_54 -> V_57 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_9 * V_10 , struct V_60 * V_32 )
{
struct V_19 * V_20 = V_2 -> V_21 ;
int V_61 ;
int V_62 = 0 ;
V_62 |= F_21 ( & V_32 -> V_63 , V_64 ) ;
V_62 |= F_21 ( & V_32 -> V_65 ,
V_66 | V_67 ) ;
V_62 |= F_21 ( & V_32 -> V_68 , V_64 ) ;
V_62 |= F_21 ( & V_32 -> V_69 , V_34 ) ;
V_62 |= F_21 ( & V_32 -> V_33 , V_34 | V_70 ) ;
if ( V_62 )
return 1 ;
V_62 |= F_22 ( V_32 -> V_65 ) ;
V_62 |= F_22 ( V_32 -> V_33 ) ;
if ( V_62 )
return 2 ;
V_62 |= F_23 ( & V_32 -> V_71 , 0 ) ;
if ( V_32 -> V_65 == V_67 ) {
V_62 |= F_23 ( & V_32 -> V_72 , 0 ) ;
} else {
#define F_24 1000
V_62 |= F_25 ( & V_32 -> V_72 ,
F_24 ) ;
}
V_62 |= F_23 ( & V_32 -> V_73 , 0 ) ;
V_62 |= F_23 ( & V_32 -> V_74 , V_32 -> V_75 ) ;
if ( V_32 -> V_33 == V_70 ) {
V_62 |= F_23 ( & V_32 -> V_76 , 0 ) ;
} else {
}
if ( V_62 )
return 3 ;
if ( V_32 -> V_65 == V_66 ) {
V_61 = V_32 -> V_72 ;
F_26 ( V_77 ,
& V_20 -> V_78 ,
& V_20 -> V_79 ,
& V_32 -> V_72 ,
V_32 -> V_80 ) ;
if ( V_61 != V_32 -> V_72 )
V_62 ++ ;
}
if ( V_62 )
return 4 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_19 * V_20 = V_2 -> V_21 ;
struct V_60 * V_32 = & V_10 -> V_26 -> V_32 ;
F_11 ( V_2 , V_10 , V_32 -> V_81 [ 0 ] ) ;
if ( V_32 -> V_33 == V_34 ) {
if ( V_32 -> V_76 == 0 ) {
V_10 -> V_26 -> V_27 |= V_36 ;
F_10 ( V_2 , V_10 ) ;
return 0 ;
}
V_20 -> V_35 = V_32 -> V_76 ;
}
if ( V_32 -> V_65 == V_66 ) {
F_28 ( V_2 -> V_7 + V_82 , 0 ,
1 , V_20 -> V_78 , V_83 | V_84 ) ;
F_28 ( V_2 -> V_7 + V_82 , 0 ,
2 , V_20 -> V_79 , V_83 | V_84 ) ;
F_3 ( V_15 , V_2 -> V_7 + V_16 ) ;
F_1 ( V_2 , V_5 ) ;
} else {
F_1 ( V_2 , V_4 ) ;
}
return 0 ;
}
static void F_29 ( struct V_1 * V_2 ,
unsigned int V_38 , unsigned int V_11 )
{
F_3 ( V_11 & 0xff , V_2 -> V_7 + F_30 ( V_38 ) ) ;
F_3 ( ( V_11 >> 8 ) & 0xff , V_2 -> V_7 + F_31 ( V_38 ) ) ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_53 * V_54 ,
unsigned int * V_23 )
{
struct V_19 * V_20 = V_2 -> V_21 ;
unsigned int V_38 = F_12 ( V_54 -> V_37 ) ;
unsigned int V_11 = V_20 -> V_85 [ V_38 ] ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_54 -> V_57 ; V_56 ++ ) {
V_11 = V_23 [ V_56 ] ;
F_29 ( V_2 , V_38 , V_11 ) ;
}
V_20 -> V_85 [ V_38 ] = V_11 ;
return V_54 -> V_57 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_53 * V_54 ,
unsigned int * V_23 )
{
struct V_19 * V_20 = V_2 -> V_21 ;
unsigned int V_38 = F_12 ( V_54 -> V_37 ) ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_54 -> V_57 ; V_56 ++ )
V_23 [ V_56 ] = V_20 -> V_85 [ V_38 ] ;
return V_54 -> V_57 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_53 * V_54 ,
unsigned int * V_23 )
{
unsigned int V_11 ;
V_11 = F_5 ( V_2 -> V_7 + V_86 ) ;
V_11 |= ( F_5 ( V_2 -> V_7 + V_87 ) << 8 ) ;
V_23 [ 1 ] = V_11 ;
return V_54 -> V_57 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_53 * V_54 ,
unsigned int * V_23 )
{
unsigned int V_88 ;
V_88 = F_36 ( V_10 , V_23 ) ;
if ( V_88 ) {
if ( V_88 & 0x00ff )
F_3 ( V_10 -> V_89 & 0xff , V_2 -> V_7 + V_90 ) ;
if ( V_88 & 0xff00 )
F_3 ( ( V_10 -> V_89 >> 8 ) , V_2 -> V_7 + V_91 ) ;
}
V_23 [ 1 ] = V_10 -> V_89 ;
return V_54 -> V_57 ;
}
static int F_37 ( struct V_1 * V_2 , struct V_92 * V_93 )
{
const struct V_94 * V_95 = F_38 ( V_2 ) ;
struct V_19 * V_20 ;
struct V_9 * V_10 ;
int V_55 ;
V_20 = F_39 ( V_2 , sizeof( * V_20 ) ) ;
if ( ! V_20 )
return - V_96 ;
V_55 = F_40 ( V_2 , V_93 -> V_97 [ 0 ] , 0x10 ) ;
if ( V_55 )
return V_55 ;
if ( V_93 -> V_97 [ 1 ] && V_93 -> V_97 [ 1 ] <= V_95 -> V_98 ) {
V_55 = F_41 ( V_93 -> V_97 [ 1 ] , F_7 , 0 ,
V_2 -> V_99 , V_2 ) ;
if ( V_55 == 0 )
V_2 -> V_6 = V_93 -> V_97 [ 1 ] ;
}
V_55 = F_42 ( V_2 , 4 ) ;
if ( V_55 )
return V_55 ;
V_10 = & V_2 -> V_100 [ 0 ] ;
V_10 -> type = V_101 ;
V_10 -> V_102 = V_103 | V_104 ;
if ( V_95 -> V_105 > 8 )
V_10 -> V_102 |= V_106 ;
V_10 -> V_43 = V_95 -> V_105 ;
V_10 -> V_14 = 0xfff ;
V_10 -> V_107 = V_95 -> V_108 ;
V_10 -> V_109 = F_19 ;
if ( V_2 -> V_6 ) {
V_2 -> V_22 = V_10 ;
V_10 -> V_102 |= V_110 ;
V_10 -> V_111 = 1 ;
V_10 -> V_112 = F_20 ;
V_10 -> V_113 = F_27 ;
V_10 -> V_114 = F_6 ;
}
V_10 = & V_2 -> V_100 [ 1 ] ;
V_10 -> type = V_115 ;
V_10 -> V_102 = V_116 ;
V_10 -> V_43 = V_95 -> V_117 ;
V_10 -> V_14 = 0xfff ;
V_10 -> V_107 = & V_118 ;
V_10 -> V_119 = F_32 ;
V_10 -> V_109 = F_33 ;
V_10 = & V_2 -> V_100 [ 2 ] ;
V_10 -> type = V_120 ;
V_10 -> V_102 = V_103 ;
V_10 -> V_43 = 16 ;
V_10 -> V_14 = 1 ;
V_10 -> V_107 = & V_121 ;
V_10 -> V_122 = F_34 ;
V_10 = & V_2 -> V_100 [ 3 ] ;
V_10 -> type = V_123 ;
V_10 -> V_102 = V_116 ;
V_10 -> V_43 = 16 ;
V_10 -> V_14 = 1 ;
V_10 -> V_107 = & V_121 ;
V_10 -> V_122 = F_35 ;
F_29 ( V_2 , 0 , 0x0 ) ;
F_29 ( V_2 , 1 , 0x0 ) ;
return 0 ;
}

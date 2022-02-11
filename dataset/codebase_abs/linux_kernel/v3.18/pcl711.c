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
struct V_23 * V_24 = & V_10 -> V_25 -> V_24 ;
unsigned int V_26 ;
if ( ! V_2 -> V_27 ) {
F_8 ( V_2 -> V_28 , L_1 ) ;
return V_29 ;
}
V_26 = F_4 ( V_2 , V_10 ) ;
F_3 ( V_15 , V_2 -> V_7 + V_16 ) ;
if ( F_9 ( V_10 , V_26 ) == 0 ) {
V_10 -> V_25 -> V_30 |= V_31 | V_32 ;
} else {
V_10 -> V_25 -> V_30 |= V_33 | V_34 ;
if ( V_24 -> V_35 == V_36 && ! ( -- V_20 -> V_37 ) ) {
F_1 ( V_2 , V_17 ) ;
V_10 -> V_25 -> V_30 |= V_38 ;
}
}
F_10 ( V_2 , V_10 ) ;
return V_29 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
unsigned int V_39 )
{
unsigned int V_40 = F_12 ( V_39 ) ;
unsigned int V_41 = F_13 ( V_39 ) ;
unsigned int V_42 = F_14 ( V_39 ) ;
unsigned int V_43 = 0 ;
F_3 ( F_15 ( V_41 ) , V_2 -> V_7 + V_44 ) ;
if ( V_10 -> V_45 > 8 ) {
if ( V_42 == V_46 ) {
V_40 &= 0x7 ;
V_43 |= V_47 ;
} else {
if ( V_40 < 8 )
V_43 |= V_48 ;
else
V_43 |= V_49 ;
}
}
F_3 ( V_43 | F_16 ( V_40 ) , V_2 -> V_7 + V_50 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_51 * V_52 ,
unsigned long V_53 )
{
unsigned int V_54 ;
V_54 = F_5 ( V_2 -> V_7 + V_12 ) ;
if ( ( V_54 & V_55 ) == 0 )
return 0 ;
return - V_56 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_51 * V_52 ,
unsigned int * V_26 )
{
int V_57 ;
int V_58 ;
F_11 ( V_2 , V_10 , V_52 -> V_39 ) ;
F_1 ( V_2 , V_17 ) ;
for ( V_58 = 0 ; V_58 < V_52 -> V_59 ; V_58 ++ ) {
F_3 ( V_60 , V_2 -> V_7 + V_61 ) ;
V_57 = F_19 ( V_2 , V_10 , V_52 , F_17 , 0 ) ;
if ( V_57 )
return V_57 ;
V_26 [ V_58 ] = F_4 ( V_2 , V_10 ) ;
}
return V_52 -> V_59 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_9 * V_10 , struct V_23 * V_24 )
{
struct V_19 * V_20 = V_2 -> V_21 ;
int V_62 = 0 ;
unsigned int V_63 ;
V_62 |= F_21 ( & V_24 -> V_64 , V_65 ) ;
V_62 |= F_21 ( & V_24 -> V_66 ,
V_67 | V_68 ) ;
V_62 |= F_21 ( & V_24 -> V_69 , V_65 ) ;
V_62 |= F_21 ( & V_24 -> V_70 , V_36 ) ;
V_62 |= F_21 ( & V_24 -> V_35 , V_36 | V_71 ) ;
if ( V_62 )
return 1 ;
V_62 |= F_22 ( V_24 -> V_66 ) ;
V_62 |= F_22 ( V_24 -> V_35 ) ;
if ( V_62 )
return 2 ;
V_62 |= F_23 ( & V_24 -> V_72 , 0 ) ;
if ( V_24 -> V_66 == V_68 ) {
V_62 |= F_23 ( & V_24 -> V_73 , 0 ) ;
} else {
#define F_24 1000
V_62 |= F_25 ( & V_24 -> V_73 ,
F_24 ) ;
}
V_62 |= F_23 ( & V_24 -> V_74 , 0 ) ;
V_62 |= F_23 ( & V_24 -> V_75 , V_24 -> V_76 ) ;
if ( V_24 -> V_35 == V_36 )
V_62 |= F_25 ( & V_24 -> V_77 , 1 ) ;
else
V_62 |= F_23 ( & V_24 -> V_77 , 0 ) ;
if ( V_62 )
return 3 ;
if ( V_24 -> V_66 == V_67 ) {
V_63 = V_24 -> V_73 ;
F_26 ( V_78 ,
& V_20 -> V_79 ,
& V_20 -> V_80 ,
& V_63 , V_24 -> V_81 ) ;
V_62 |= F_23 ( & V_24 -> V_73 , V_63 ) ;
}
if ( V_62 )
return 4 ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_21 ;
unsigned long V_82 = V_2 -> V_7 + V_83 ;
F_28 ( V_82 , 0 , 1 , V_84 | V_85 ) ;
F_28 ( V_82 , 0 , 2 , V_84 | V_85 ) ;
F_29 ( V_82 , 0 , 1 , V_20 -> V_79 ) ;
F_29 ( V_82 , 0 , 2 , V_20 -> V_80 ) ;
}
static int F_30 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_19 * V_20 = V_2 -> V_21 ;
struct V_23 * V_24 = & V_10 -> V_25 -> V_24 ;
F_11 ( V_2 , V_10 , V_24 -> V_86 [ 0 ] ) ;
if ( V_24 -> V_35 == V_36 )
V_20 -> V_37 = V_24 -> V_77 ;
if ( V_24 -> V_66 == V_67 ) {
F_27 ( V_2 ) ;
F_3 ( V_15 , V_2 -> V_7 + V_16 ) ;
F_1 ( V_2 , V_5 ) ;
} else {
F_1 ( V_2 , V_4 ) ;
}
return 0 ;
}
static void F_31 ( struct V_1 * V_2 ,
unsigned int V_40 , unsigned int V_11 )
{
F_3 ( V_11 & 0xff , V_2 -> V_7 + F_32 ( V_40 ) ) ;
F_3 ( ( V_11 >> 8 ) & 0xff , V_2 -> V_7 + F_33 ( V_40 ) ) ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_51 * V_52 ,
unsigned int * V_26 )
{
unsigned int V_40 = F_12 ( V_52 -> V_39 ) ;
unsigned int V_11 = V_10 -> V_87 [ V_40 ] ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_52 -> V_59 ; V_58 ++ ) {
V_11 = V_26 [ V_58 ] ;
F_31 ( V_2 , V_40 , V_11 ) ;
}
V_10 -> V_87 [ V_40 ] = V_11 ;
return V_52 -> V_59 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_51 * V_52 ,
unsigned int * V_26 )
{
unsigned int V_11 ;
V_11 = F_5 ( V_2 -> V_7 + V_88 ) ;
V_11 |= ( F_5 ( V_2 -> V_7 + V_89 ) << 8 ) ;
V_26 [ 1 ] = V_11 ;
return V_52 -> V_59 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_51 * V_52 ,
unsigned int * V_26 )
{
unsigned int V_90 ;
V_90 = F_37 ( V_10 , V_26 ) ;
if ( V_90 ) {
if ( V_90 & 0x00ff )
F_3 ( V_10 -> V_91 & 0xff , V_2 -> V_7 + V_92 ) ;
if ( V_90 & 0xff00 )
F_3 ( ( V_10 -> V_91 >> 8 ) , V_2 -> V_7 + V_93 ) ;
}
V_26 [ 1 ] = V_10 -> V_91 ;
return V_52 -> V_59 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_94 * V_95 )
{
const struct V_96 * V_97 = V_2 -> V_98 ;
struct V_19 * V_20 ;
struct V_9 * V_10 ;
int V_57 ;
V_20 = F_39 ( V_2 , sizeof( * V_20 ) ) ;
if ( ! V_20 )
return - V_99 ;
V_57 = F_40 ( V_2 , V_95 -> V_100 [ 0 ] , 0x10 ) ;
if ( V_57 )
return V_57 ;
if ( V_95 -> V_100 [ 1 ] && V_95 -> V_100 [ 1 ] <= V_97 -> V_101 ) {
V_57 = F_41 ( V_95 -> V_100 [ 1 ] , F_7 , 0 ,
V_2 -> V_102 , V_2 ) ;
if ( V_57 == 0 )
V_2 -> V_6 = V_95 -> V_100 [ 1 ] ;
}
V_57 = F_42 ( V_2 , 4 ) ;
if ( V_57 )
return V_57 ;
V_10 = & V_2 -> V_103 [ 0 ] ;
V_10 -> type = V_104 ;
V_10 -> V_105 = V_106 | V_107 ;
if ( V_97 -> V_108 > 8 )
V_10 -> V_105 |= V_109 ;
V_10 -> V_45 = V_97 -> V_108 ;
V_10 -> V_14 = 0xfff ;
V_10 -> V_110 = V_97 -> V_111 ;
V_10 -> V_112 = F_18 ;
if ( V_2 -> V_6 ) {
V_2 -> V_22 = V_10 ;
V_10 -> V_105 |= V_113 ;
V_10 -> V_114 = 1 ;
V_10 -> V_115 = F_20 ;
V_10 -> V_116 = F_30 ;
V_10 -> V_117 = F_6 ;
}
V_10 = & V_2 -> V_103 [ 1 ] ;
V_10 -> type = V_118 ;
V_10 -> V_105 = V_119 ;
V_10 -> V_45 = V_97 -> V_120 ;
V_10 -> V_14 = 0xfff ;
V_10 -> V_110 = & V_121 ;
V_10 -> V_122 = F_34 ;
V_10 -> V_112 = V_123 ;
V_57 = F_43 ( V_10 ) ;
if ( V_57 )
return V_57 ;
V_10 = & V_2 -> V_103 [ 2 ] ;
V_10 -> type = V_124 ;
V_10 -> V_105 = V_106 ;
V_10 -> V_45 = 16 ;
V_10 -> V_14 = 1 ;
V_10 -> V_110 = & V_125 ;
V_10 -> V_126 = F_35 ;
V_10 = & V_2 -> V_103 [ 3 ] ;
V_10 -> type = V_127 ;
V_10 -> V_105 = V_119 ;
V_10 -> V_45 = 16 ;
V_10 -> V_14 = 1 ;
V_10 -> V_110 = & V_125 ;
V_10 -> V_126 = F_36 ;
F_31 ( V_2 , 0 , 0x0 ) ;
F_31 ( V_2 , 1 , 0x0 ) ;
return 0 ;
}

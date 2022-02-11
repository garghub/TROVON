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
struct V_9 * V_10 = V_2 -> V_19 ;
struct V_20 * V_21 = & V_10 -> V_22 -> V_21 ;
unsigned int V_23 ;
if ( ! V_2 -> V_24 ) {
F_8 ( V_2 -> V_25 , L_1 ) ;
return V_26 ;
}
V_23 = F_4 ( V_2 , V_10 ) ;
F_3 ( V_15 , V_2 -> V_7 + V_16 ) ;
F_9 ( V_10 , & V_23 , 1 ) ;
if ( V_21 -> V_27 == V_28 &&
V_10 -> V_22 -> V_29 >= V_21 -> V_30 )
V_10 -> V_22 -> V_31 |= V_32 ;
F_10 ( V_2 , V_10 ) ;
return V_26 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
unsigned int V_33 )
{
unsigned int V_34 = F_12 ( V_33 ) ;
unsigned int V_35 = F_13 ( V_33 ) ;
unsigned int V_36 = F_14 ( V_33 ) ;
unsigned int V_37 = 0 ;
F_3 ( F_15 ( V_35 ) , V_2 -> V_7 + V_38 ) ;
if ( V_10 -> V_39 > 8 ) {
if ( V_36 == V_40 ) {
V_34 &= 0x7 ;
V_37 |= V_41 ;
} else {
if ( V_34 < 8 )
V_37 |= V_42 ;
else
V_37 |= V_43 ;
}
}
F_3 ( V_37 | F_16 ( V_34 ) , V_2 -> V_7 + V_44 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_45 * V_46 ,
unsigned long V_47 )
{
unsigned int V_48 ;
V_48 = F_5 ( V_2 -> V_7 + V_12 ) ;
if ( ( V_48 & V_49 ) == 0 )
return 0 ;
return - V_50 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_45 * V_46 ,
unsigned int * V_23 )
{
int V_51 ;
int V_52 ;
F_11 ( V_2 , V_10 , V_46 -> V_33 ) ;
F_1 ( V_2 , V_17 ) ;
for ( V_52 = 0 ; V_52 < V_46 -> V_53 ; V_52 ++ ) {
F_3 ( V_54 , V_2 -> V_7 + V_55 ) ;
V_51 = F_19 ( V_2 , V_10 , V_46 , F_17 , 0 ) ;
if ( V_51 )
return V_51 ;
V_23 [ V_52 ] = F_4 ( V_2 , V_10 ) ;
}
return V_46 -> V_53 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_9 * V_10 , struct V_20 * V_21 )
{
struct V_56 * V_57 = V_2 -> V_58 ;
int V_59 = 0 ;
unsigned int V_60 ;
V_59 |= F_21 ( & V_21 -> V_61 , V_62 ) ;
V_59 |= F_21 ( & V_21 -> V_63 ,
V_64 | V_65 ) ;
V_59 |= F_21 ( & V_21 -> V_66 , V_62 ) ;
V_59 |= F_21 ( & V_21 -> V_67 , V_28 ) ;
V_59 |= F_21 ( & V_21 -> V_27 , V_28 | V_68 ) ;
if ( V_59 )
return 1 ;
V_59 |= F_22 ( V_21 -> V_63 ) ;
V_59 |= F_22 ( V_21 -> V_27 ) ;
if ( V_59 )
return 2 ;
V_59 |= F_23 ( & V_21 -> V_69 , 0 ) ;
if ( V_21 -> V_63 == V_65 ) {
V_59 |= F_23 ( & V_21 -> V_70 , 0 ) ;
} else {
#define F_24 1000
V_59 |= F_25 ( & V_21 -> V_70 ,
F_24 ) ;
}
V_59 |= F_23 ( & V_21 -> V_71 , 0 ) ;
V_59 |= F_23 ( & V_21 -> V_72 , V_21 -> V_73 ) ;
if ( V_21 -> V_27 == V_28 )
V_59 |= F_25 ( & V_21 -> V_30 , 1 ) ;
else
V_59 |= F_23 ( & V_21 -> V_30 , 0 ) ;
if ( V_59 )
return 3 ;
if ( V_21 -> V_63 == V_64 ) {
V_60 = V_21 -> V_70 ;
F_26 ( V_74 ,
& V_57 -> V_75 ,
& V_57 -> V_76 ,
& V_60 , V_21 -> V_77 ) ;
V_59 |= F_23 ( & V_21 -> V_70 , V_60 ) ;
}
if ( V_59 )
return 4 ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_56 * V_57 = V_2 -> V_58 ;
unsigned long V_78 = V_2 -> V_7 + V_79 ;
F_28 ( V_78 , 0 , 1 , V_80 | V_81 ) ;
F_28 ( V_78 , 0 , 2 , V_80 | V_81 ) ;
F_29 ( V_78 , 0 , 1 , V_57 -> V_75 ) ;
F_29 ( V_78 , 0 , 2 , V_57 -> V_76 ) ;
}
static int F_30 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_20 * V_21 = & V_10 -> V_22 -> V_21 ;
F_11 ( V_2 , V_10 , V_21 -> V_82 [ 0 ] ) ;
if ( V_21 -> V_63 == V_64 ) {
F_27 ( V_2 ) ;
F_3 ( V_15 , V_2 -> V_7 + V_16 ) ;
F_1 ( V_2 , V_5 ) ;
} else {
F_1 ( V_2 , V_4 ) ;
}
return 0 ;
}
static void F_31 ( struct V_1 * V_2 ,
unsigned int V_34 , unsigned int V_11 )
{
F_3 ( V_11 & 0xff , V_2 -> V_7 + F_32 ( V_34 ) ) ;
F_3 ( ( V_11 >> 8 ) & 0xff , V_2 -> V_7 + F_33 ( V_34 ) ) ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_45 * V_46 ,
unsigned int * V_23 )
{
unsigned int V_34 = F_12 ( V_46 -> V_33 ) ;
unsigned int V_11 = V_10 -> V_83 [ V_34 ] ;
int V_52 ;
for ( V_52 = 0 ; V_52 < V_46 -> V_53 ; V_52 ++ ) {
V_11 = V_23 [ V_52 ] ;
F_31 ( V_2 , V_34 , V_11 ) ;
}
V_10 -> V_83 [ V_34 ] = V_11 ;
return V_46 -> V_53 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_45 * V_46 ,
unsigned int * V_23 )
{
unsigned int V_11 ;
V_11 = F_5 ( V_2 -> V_7 + V_84 ) ;
V_11 |= ( F_5 ( V_2 -> V_7 + V_85 ) << 8 ) ;
V_23 [ 1 ] = V_11 ;
return V_46 -> V_53 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_45 * V_46 ,
unsigned int * V_23 )
{
unsigned int V_86 ;
V_86 = F_37 ( V_10 , V_23 ) ;
if ( V_86 ) {
if ( V_86 & 0x00ff )
F_3 ( V_10 -> V_87 & 0xff , V_2 -> V_7 + V_88 ) ;
if ( V_86 & 0xff00 )
F_3 ( ( V_10 -> V_87 >> 8 ) , V_2 -> V_7 + V_89 ) ;
}
V_23 [ 1 ] = V_10 -> V_87 ;
return V_46 -> V_53 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_90 * V_91 )
{
const struct V_92 * V_93 = V_2 -> V_94 ;
struct V_56 * V_57 ;
struct V_9 * V_10 ;
int V_51 ;
V_57 = F_39 ( V_2 , sizeof( * V_57 ) ) ;
if ( ! V_57 )
return - V_95 ;
V_51 = F_40 ( V_2 , V_91 -> V_96 [ 0 ] , 0x10 ) ;
if ( V_51 )
return V_51 ;
if ( V_91 -> V_96 [ 1 ] && V_91 -> V_96 [ 1 ] <= V_93 -> V_97 ) {
V_51 = F_41 ( V_91 -> V_96 [ 1 ] , F_7 , 0 ,
V_2 -> V_98 , V_2 ) ;
if ( V_51 == 0 )
V_2 -> V_6 = V_91 -> V_96 [ 1 ] ;
}
V_51 = F_42 ( V_2 , 4 ) ;
if ( V_51 )
return V_51 ;
V_10 = & V_2 -> V_99 [ 0 ] ;
V_10 -> type = V_100 ;
V_10 -> V_101 = V_102 | V_103 ;
if ( V_93 -> V_104 > 8 )
V_10 -> V_101 |= V_105 ;
V_10 -> V_39 = V_93 -> V_104 ;
V_10 -> V_14 = 0xfff ;
V_10 -> V_106 = V_93 -> V_107 ;
V_10 -> V_108 = F_18 ;
if ( V_2 -> V_6 ) {
V_2 -> V_19 = V_10 ;
V_10 -> V_101 |= V_109 ;
V_10 -> V_110 = 1 ;
V_10 -> V_111 = F_20 ;
V_10 -> V_112 = F_30 ;
V_10 -> V_113 = F_6 ;
}
V_10 = & V_2 -> V_99 [ 1 ] ;
V_10 -> type = V_114 ;
V_10 -> V_101 = V_115 ;
V_10 -> V_39 = V_93 -> V_116 ;
V_10 -> V_14 = 0xfff ;
V_10 -> V_106 = & V_117 ;
V_10 -> V_118 = F_34 ;
V_51 = F_43 ( V_10 ) ;
if ( V_51 )
return V_51 ;
V_10 = & V_2 -> V_99 [ 2 ] ;
V_10 -> type = V_119 ;
V_10 -> V_101 = V_102 ;
V_10 -> V_39 = 16 ;
V_10 -> V_14 = 1 ;
V_10 -> V_106 = & V_120 ;
V_10 -> V_121 = F_35 ;
V_10 = & V_2 -> V_99 [ 3 ] ;
V_10 -> type = V_122 ;
V_10 -> V_101 = V_115 ;
V_10 -> V_39 = 16 ;
V_10 -> V_14 = 1 ;
V_10 -> V_106 = & V_120 ;
V_10 -> V_121 = F_36 ;
F_31 ( V_2 , 0 , 0x0 ) ;
F_31 ( V_2 , 1 , 0x0 ) ;
return 0 ;
}

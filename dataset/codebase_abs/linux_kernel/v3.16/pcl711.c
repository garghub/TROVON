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
F_8 ( V_2 , L_1 ) ;
return V_28 ;
}
V_26 = F_4 ( V_2 , V_10 ) ;
F_3 ( V_15 , V_2 -> V_7 + V_16 ) ;
if ( F_9 ( V_10 , V_26 ) == 0 ) {
V_10 -> V_25 -> V_29 |= V_30 | V_31 ;
} else {
V_10 -> V_25 -> V_29 |= V_32 | V_33 ;
if ( V_24 -> V_34 == V_35 && ! ( -- V_20 -> V_36 ) ) {
F_1 ( V_2 , V_17 ) ;
V_10 -> V_25 -> V_29 |= V_37 ;
}
}
F_10 ( V_2 , V_10 ) ;
return V_28 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
unsigned int V_38 )
{
unsigned int V_39 = F_12 ( V_38 ) ;
unsigned int V_40 = F_13 ( V_38 ) ;
unsigned int V_41 = F_14 ( V_38 ) ;
unsigned int V_42 = 0 ;
F_3 ( F_15 ( V_40 ) , V_2 -> V_7 + V_43 ) ;
if ( V_10 -> V_44 > 8 ) {
if ( V_41 == V_45 ) {
V_39 &= 0x7 ;
V_42 |= V_46 ;
} else {
if ( V_39 < 8 )
V_42 |= V_47 ;
else
V_42 |= V_48 ;
}
}
F_3 ( V_42 | F_16 ( V_39 ) , V_2 -> V_7 + V_49 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_50 * V_51 ,
unsigned long V_52 )
{
unsigned int V_53 ;
V_53 = F_5 ( V_2 -> V_7 + V_12 ) ;
if ( ( V_53 & V_54 ) == 0 )
return 0 ;
return - V_55 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_50 * V_51 ,
unsigned int * V_26 )
{
int V_56 ;
int V_57 ;
F_11 ( V_2 , V_10 , V_51 -> V_38 ) ;
F_1 ( V_2 , V_17 ) ;
for ( V_57 = 0 ; V_57 < V_51 -> V_58 ; V_57 ++ ) {
F_3 ( V_59 , V_2 -> V_7 + V_60 ) ;
V_56 = F_19 ( V_2 , V_10 , V_51 , F_17 , 0 ) ;
if ( V_56 )
return V_56 ;
V_26 [ V_57 ] = F_4 ( V_2 , V_10 ) ;
}
return V_51 -> V_58 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_9 * V_10 , struct V_23 * V_24 )
{
struct V_19 * V_20 = V_2 -> V_21 ;
int V_61 = 0 ;
unsigned int V_62 ;
V_61 |= F_21 ( & V_24 -> V_63 , V_64 ) ;
V_61 |= F_21 ( & V_24 -> V_65 ,
V_66 | V_67 ) ;
V_61 |= F_21 ( & V_24 -> V_68 , V_64 ) ;
V_61 |= F_21 ( & V_24 -> V_69 , V_35 ) ;
V_61 |= F_21 ( & V_24 -> V_34 , V_35 | V_70 ) ;
if ( V_61 )
return 1 ;
V_61 |= F_22 ( V_24 -> V_65 ) ;
V_61 |= F_22 ( V_24 -> V_34 ) ;
if ( V_61 )
return 2 ;
V_61 |= F_23 ( & V_24 -> V_71 , 0 ) ;
if ( V_24 -> V_65 == V_67 ) {
V_61 |= F_23 ( & V_24 -> V_72 , 0 ) ;
} else {
#define F_24 1000
V_61 |= F_25 ( & V_24 -> V_72 ,
F_24 ) ;
}
V_61 |= F_23 ( & V_24 -> V_73 , 0 ) ;
V_61 |= F_23 ( & V_24 -> V_74 , V_24 -> V_75 ) ;
if ( V_24 -> V_34 == V_70 )
V_61 |= F_23 ( & V_24 -> V_76 , 0 ) ;
if ( V_61 )
return 3 ;
if ( V_24 -> V_65 == V_66 ) {
V_62 = V_24 -> V_72 ;
F_26 ( V_77 ,
& V_20 -> V_78 ,
& V_20 -> V_79 ,
& V_62 , V_24 -> V_80 ) ;
V_61 |= F_23 ( & V_24 -> V_72 , V_62 ) ;
}
if ( V_61 )
return 4 ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_21 ;
unsigned long V_81 = V_2 -> V_7 + V_82 ;
F_28 ( V_81 , 0 , 1 , V_83 | V_84 ) ;
F_28 ( V_81 , 0 , 2 , V_83 | V_84 ) ;
F_29 ( V_81 , 0 , 1 , V_20 -> V_78 ) ;
F_29 ( V_81 , 0 , 2 , V_20 -> V_79 ) ;
}
static int F_30 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_19 * V_20 = V_2 -> V_21 ;
struct V_23 * V_24 = & V_10 -> V_25 -> V_24 ;
F_11 ( V_2 , V_10 , V_24 -> V_85 [ 0 ] ) ;
if ( V_24 -> V_34 == V_35 ) {
if ( V_24 -> V_76 == 0 ) {
V_10 -> V_25 -> V_29 |= V_37 ;
F_10 ( V_2 , V_10 ) ;
return 0 ;
}
V_20 -> V_36 = V_24 -> V_76 ;
}
if ( V_24 -> V_65 == V_66 ) {
F_27 ( V_2 ) ;
F_3 ( V_15 , V_2 -> V_7 + V_16 ) ;
F_1 ( V_2 , V_5 ) ;
} else {
F_1 ( V_2 , V_4 ) ;
}
return 0 ;
}
static void F_31 ( struct V_1 * V_2 ,
unsigned int V_39 , unsigned int V_11 )
{
F_3 ( V_11 & 0xff , V_2 -> V_7 + F_32 ( V_39 ) ) ;
F_3 ( ( V_11 >> 8 ) & 0xff , V_2 -> V_7 + F_33 ( V_39 ) ) ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_50 * V_51 ,
unsigned int * V_26 )
{
struct V_19 * V_20 = V_2 -> V_21 ;
unsigned int V_39 = F_12 ( V_51 -> V_38 ) ;
unsigned int V_11 = V_20 -> V_86 [ V_39 ] ;
int V_57 ;
for ( V_57 = 0 ; V_57 < V_51 -> V_58 ; V_57 ++ ) {
V_11 = V_26 [ V_57 ] ;
F_31 ( V_2 , V_39 , V_11 ) ;
}
V_20 -> V_86 [ V_39 ] = V_11 ;
return V_51 -> V_58 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_50 * V_51 ,
unsigned int * V_26 )
{
struct V_19 * V_20 = V_2 -> V_21 ;
unsigned int V_39 = F_12 ( V_51 -> V_38 ) ;
int V_57 ;
for ( V_57 = 0 ; V_57 < V_51 -> V_58 ; V_57 ++ )
V_26 [ V_57 ] = V_20 -> V_86 [ V_39 ] ;
return V_51 -> V_58 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_50 * V_51 ,
unsigned int * V_26 )
{
unsigned int V_11 ;
V_11 = F_5 ( V_2 -> V_7 + V_87 ) ;
V_11 |= ( F_5 ( V_2 -> V_7 + V_88 ) << 8 ) ;
V_26 [ 1 ] = V_11 ;
return V_51 -> V_58 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_50 * V_51 ,
unsigned int * V_26 )
{
unsigned int V_89 ;
V_89 = F_38 ( V_10 , V_26 ) ;
if ( V_89 ) {
if ( V_89 & 0x00ff )
F_3 ( V_10 -> V_90 & 0xff , V_2 -> V_7 + V_91 ) ;
if ( V_89 & 0xff00 )
F_3 ( ( V_10 -> V_90 >> 8 ) , V_2 -> V_7 + V_92 ) ;
}
V_26 [ 1 ] = V_10 -> V_90 ;
return V_51 -> V_58 ;
}
static int F_39 ( struct V_1 * V_2 , struct V_93 * V_94 )
{
const struct V_95 * V_96 = F_40 ( V_2 ) ;
struct V_19 * V_20 ;
struct V_9 * V_10 ;
int V_56 ;
V_20 = F_41 ( V_2 , sizeof( * V_20 ) ) ;
if ( ! V_20 )
return - V_97 ;
V_56 = F_42 ( V_2 , V_94 -> V_98 [ 0 ] , 0x10 ) ;
if ( V_56 )
return V_56 ;
if ( V_94 -> V_98 [ 1 ] && V_94 -> V_98 [ 1 ] <= V_96 -> V_99 ) {
V_56 = F_43 ( V_94 -> V_98 [ 1 ] , F_7 , 0 ,
V_2 -> V_100 , V_2 ) ;
if ( V_56 == 0 )
V_2 -> V_6 = V_94 -> V_98 [ 1 ] ;
}
V_56 = F_44 ( V_2 , 4 ) ;
if ( V_56 )
return V_56 ;
V_10 = & V_2 -> V_101 [ 0 ] ;
V_10 -> type = V_102 ;
V_10 -> V_103 = V_104 | V_105 ;
if ( V_96 -> V_106 > 8 )
V_10 -> V_103 |= V_107 ;
V_10 -> V_44 = V_96 -> V_106 ;
V_10 -> V_14 = 0xfff ;
V_10 -> V_108 = V_96 -> V_109 ;
V_10 -> V_110 = F_18 ;
if ( V_2 -> V_6 ) {
V_2 -> V_22 = V_10 ;
V_10 -> V_103 |= V_111 ;
V_10 -> V_112 = 1 ;
V_10 -> V_113 = F_20 ;
V_10 -> V_114 = F_30 ;
V_10 -> V_115 = F_6 ;
}
V_10 = & V_2 -> V_101 [ 1 ] ;
V_10 -> type = V_116 ;
V_10 -> V_103 = V_117 ;
V_10 -> V_44 = V_96 -> V_118 ;
V_10 -> V_14 = 0xfff ;
V_10 -> V_108 = & V_119 ;
V_10 -> V_120 = F_34 ;
V_10 -> V_110 = F_35 ;
V_10 = & V_2 -> V_101 [ 2 ] ;
V_10 -> type = V_121 ;
V_10 -> V_103 = V_104 ;
V_10 -> V_44 = 16 ;
V_10 -> V_14 = 1 ;
V_10 -> V_108 = & V_122 ;
V_10 -> V_123 = F_36 ;
V_10 = & V_2 -> V_101 [ 3 ] ;
V_10 -> type = V_124 ;
V_10 -> V_103 = V_117 ;
V_10 -> V_44 = 16 ;
V_10 -> V_14 = 1 ;
V_10 -> V_108 = & V_122 ;
V_10 -> V_123 = F_37 ;
F_31 ( V_2 , 0 , 0x0 ) ;
F_31 ( V_2 , 1 , 0x0 ) ;
return 0 ;
}

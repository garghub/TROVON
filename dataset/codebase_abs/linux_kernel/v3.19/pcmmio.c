static void F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned long V_9 = V_2 -> V_9 ;
unsigned long V_10 ;
F_2 ( & V_7 -> V_11 , V_10 ) ;
if ( V_4 == 0 ) {
F_3 ( V_3 & 0xff , V_9 + F_4 ( V_5 + 0 ) ) ;
F_3 ( ( V_3 >> 8 ) & 0xff , V_9 + F_4 ( V_5 + 1 ) ) ;
F_3 ( ( V_3 >> 16 ) & 0xff , V_9 + F_4 ( V_5 + 2 ) ) ;
} else {
F_3 ( F_5 ( V_4 ) , V_9 + V_12 ) ;
F_3 ( V_3 & 0xff , V_9 + F_6 ( 0 ) ) ;
F_3 ( ( V_3 >> 8 ) & 0xff , V_9 + F_6 ( 1 ) ) ;
F_3 ( ( V_3 >> 16 ) & 0xff , V_9 + F_6 ( 2 ) ) ;
}
F_7 ( & V_7 -> V_11 , V_10 ) ;
}
static unsigned int F_8 ( struct V_1 * V_2 ,
int V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned long V_9 = V_2 -> V_9 ;
unsigned long V_10 ;
unsigned int V_3 ;
F_2 ( & V_7 -> V_11 , V_10 ) ;
if ( V_4 == 0 ) {
V_3 = F_9 ( V_9 + F_4 ( V_5 + 0 ) ) ;
V_3 |= ( F_9 ( V_9 + F_4 ( V_5 + 1 ) ) << 8 ) ;
V_3 |= ( F_9 ( V_9 + F_4 ( V_5 + 2 ) ) << 16 ) ;
} else {
F_3 ( F_5 ( V_4 ) , V_9 + V_12 ) ;
V_3 = F_9 ( V_9 + F_6 ( 0 ) ) ;
V_3 |= ( F_9 ( V_9 + F_6 ( 1 ) ) << 8 ) ;
V_3 |= ( F_9 ( V_9 + F_6 ( 2 ) ) << 16 ) ;
}
F_7 ( & V_7 -> V_11 , V_10 ) ;
return V_3 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_15 * V_16 ,
unsigned int * V_17 )
{
int V_5 = V_14 -> V_18 == 2 ? 0 : 3 ;
unsigned int V_19 = ( 1 << V_14 -> V_20 ) - 1 ;
unsigned int V_21 ;
unsigned int V_3 ;
V_21 = F_11 ( V_14 , V_17 ) ;
if ( V_21 ) {
V_3 = ~ V_14 -> V_22 & V_19 ;
V_3 &= V_14 -> V_23 ;
F_1 ( V_2 , V_3 , 0 , V_5 ) ;
}
V_3 = F_8 ( V_2 , 0 , V_5 ) ;
V_17 [ 1 ] = ~ V_3 & V_19 ;
return V_16 -> V_24 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_15 * V_16 ,
unsigned int * V_17 )
{
int V_5 = V_14 -> V_18 == 2 ? 0 : 3 ;
int V_25 ;
V_25 = F_13 ( V_2 , V_14 , V_16 , V_17 , 0 ) ;
if ( V_25 )
return V_25 ;
if ( V_17 [ 0 ] == V_26 )
F_1 ( V_2 , V_14 -> V_23 , 0 , V_5 ) ;
return V_16 -> V_24 ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0 , 0 , 0 ) ;
F_1 ( V_2 , 0 , 0 , 3 ) ;
F_1 ( V_2 , 0 , V_27 , 0 ) ;
F_1 ( V_2 , 0 , V_28 , 0 ) ;
F_1 ( V_2 , 0 , V_29 , 0 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
V_7 -> V_30 = 0 ;
V_7 -> V_31 = 0 ;
V_14 -> V_32 -> V_33 = NULL ;
F_1 ( V_2 , 0 , V_28 , 0 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
unsigned int V_34 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_35 * V_36 = & V_14 -> V_32 -> V_36 ;
unsigned int V_3 = 0 ;
unsigned long V_10 ;
int V_37 ;
F_2 ( & V_7 -> V_38 , V_10 ) ;
if ( ! V_7 -> V_31 )
goto V_39;
if ( ! ( V_34 & V_7 -> V_30 ) )
goto V_39;
for ( V_37 = 0 ; V_37 < V_36 -> V_40 ; V_37 ++ ) {
unsigned int V_41 = F_17 ( V_36 -> V_42 [ V_37 ] ) ;
if ( V_34 & ( 1 << V_41 ) )
V_3 |= ( 1 << V_37 ) ;
}
F_18 ( V_14 , & V_3 , 1 ) ;
if ( V_36 -> V_43 == V_44 &&
V_14 -> V_32 -> V_45 >= V_36 -> V_46 )
V_14 -> V_32 -> V_47 |= V_48 ;
V_39:
F_7 ( & V_7 -> V_38 , V_10 ) ;
F_19 ( V_2 , V_14 ) ;
}
static T_1 F_20 ( int V_49 , void * V_50 )
{
struct V_1 * V_2 = V_50 ;
struct V_13 * V_14 = V_2 -> V_51 ;
unsigned int V_34 ;
unsigned char V_52 ;
V_52 = F_9 ( V_2 -> V_9 + V_53 ) & 0x07 ;
if ( ! V_52 )
return V_54 ;
V_34 = F_8 ( V_2 , V_29 , 0 ) ;
F_1 ( V_2 , 0 , V_29 , 0 ) ;
F_16 ( V_2 , V_14 , V_34 ) ;
return V_55 ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_35 * V_36 = & V_14 -> V_32 -> V_36 ;
unsigned int V_56 = 0 ;
unsigned int V_57 = 0 ;
int V_37 ;
V_7 -> V_30 = 0 ;
V_7 -> V_31 = 1 ;
if ( V_36 -> V_42 ) {
for ( V_37 = 0 ; V_37 < V_36 -> V_40 ; V_37 ++ ) {
unsigned int V_58 = V_36 -> V_42 [ V_37 ] ;
unsigned int V_41 = F_17 ( V_58 ) ;
unsigned int V_59 = F_22 ( V_58 ) ;
unsigned int V_60 = F_23 ( V_58 ) ;
V_56 |= ( 1 << V_41 ) ;
V_57 |= ( ( ( V_60 || V_59 ) ? 1 : 0 ) << V_41 ) ;
}
}
V_56 &= ( ( 1 << V_14 -> V_20 ) - 1 ) ;
V_7 -> V_30 = V_56 ;
F_1 ( V_2 , V_57 , V_27 , 0 ) ;
F_1 ( V_2 , V_56 , V_28 , 0 ) ;
}
static int F_24 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned long V_10 ;
F_2 ( & V_7 -> V_38 , V_10 ) ;
if ( V_7 -> V_31 )
F_15 ( V_2 , V_14 ) ;
F_7 ( & V_7 -> V_38 , V_10 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
unsigned int V_61 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_35 * V_36 = & V_14 -> V_32 -> V_36 ;
unsigned long V_10 ;
if ( V_61 != V_36 -> V_62 )
return - V_63 ;
F_2 ( & V_7 -> V_38 , V_10 ) ;
V_14 -> V_32 -> V_33 = NULL ;
if ( V_7 -> V_31 )
F_21 ( V_2 , V_14 ) ;
F_7 ( & V_7 -> V_38 , V_10 ) ;
return 1 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_35 * V_36 = & V_14 -> V_32 -> V_36 ;
unsigned long V_10 ;
F_2 ( & V_7 -> V_38 , V_10 ) ;
V_7 -> V_31 = 1 ;
if ( V_36 -> V_64 == V_65 )
V_14 -> V_32 -> V_33 = F_25 ;
else
F_21 ( V_2 , V_14 ) ;
F_7 ( & V_7 -> V_38 , V_10 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_35 * V_36 )
{
int V_66 = 0 ;
V_66 |= F_28 ( & V_36 -> V_64 , V_67 | V_65 ) ;
V_66 |= F_28 ( & V_36 -> V_68 , V_69 ) ;
V_66 |= F_28 ( & V_36 -> V_70 , V_67 ) ;
V_66 |= F_28 ( & V_36 -> V_71 , V_44 ) ;
V_66 |= F_28 ( & V_36 -> V_43 , V_44 | V_72 ) ;
if ( V_66 )
return 1 ;
V_66 |= F_29 ( V_36 -> V_64 ) ;
V_66 |= F_29 ( V_36 -> V_43 ) ;
if ( V_66 )
return 2 ;
V_66 |= F_30 ( & V_36 -> V_62 , 0 ) ;
V_66 |= F_30 ( & V_36 -> V_73 , 0 ) ;
V_66 |= F_30 ( & V_36 -> V_74 , 0 ) ;
V_66 |= F_30 ( & V_36 -> V_75 , V_36 -> V_40 ) ;
if ( V_36 -> V_43 == V_44 )
V_66 |= F_31 ( & V_36 -> V_46 , 1 ) ;
else
V_66 |= F_30 ( & V_36 -> V_46 , 0 ) ;
if ( V_66 )
return 3 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_15 * V_16 ,
unsigned long V_76 )
{
unsigned char V_77 ;
V_77 = F_9 ( V_2 -> V_9 + V_78 ) ;
if ( V_77 & V_79 )
return 0 ;
return - V_80 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_15 * V_16 ,
unsigned int * V_17 )
{
unsigned long V_9 = V_2 -> V_9 ;
unsigned int V_41 = F_17 ( V_16 -> V_58 ) ;
unsigned int V_59 = F_22 ( V_16 -> V_58 ) ;
unsigned int V_60 = F_23 ( V_16 -> V_58 ) ;
unsigned char V_36 = 0 ;
unsigned int V_3 ;
int V_25 ;
int V_37 ;
if ( V_41 > 7 ) {
V_41 -= 8 ;
V_9 += V_81 ;
}
if ( V_60 == V_82 )
V_36 |= V_83 ;
if ( V_41 % 2 )
V_36 |= V_84 ;
V_36 |= F_34 ( V_41 / 2 ) ;
V_36 |= F_35 ( V_59 ) ;
F_3 ( V_36 , V_9 + V_85 ) ;
V_25 = F_36 ( V_2 , V_14 , V_16 , F_32 , 0 ) ;
if ( V_25 )
return V_25 ;
V_3 = F_9 ( V_9 + V_86 ) ;
V_3 |= F_9 ( V_9 + V_87 ) << 8 ;
for ( V_37 = 0 ; V_37 < V_16 -> V_24 ; V_37 ++ ) {
F_3 ( V_36 , V_9 + V_85 ) ;
V_25 = F_36 ( V_2 , V_14 , V_16 , F_32 , 0 ) ;
if ( V_25 )
return V_25 ;
V_3 = F_9 ( V_9 + V_86 ) ;
V_3 |= F_9 ( V_9 + V_87 ) << 8 ;
if ( F_37 ( V_14 , V_59 ) )
V_3 = F_38 ( V_14 , V_3 ) ;
V_17 [ V_37 ] = V_3 ;
}
return V_16 -> V_24 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_15 * V_16 ,
unsigned long V_76 )
{
unsigned char V_77 ;
V_77 = F_9 ( V_2 -> V_9 + V_88 ) ;
if ( V_77 & V_89 )
return 0 ;
return - V_80 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_15 * V_16 ,
unsigned int * V_17 )
{
unsigned long V_9 = V_2 -> V_9 ;
unsigned int V_41 = F_17 ( V_16 -> V_58 ) ;
unsigned int V_59 = F_22 ( V_16 -> V_58 ) ;
unsigned char V_36 = 0 ;
int V_25 ;
int V_37 ;
if ( V_41 > 3 ) {
V_36 |= F_41 ( V_41 - 4 ) ;
V_9 += V_90 ;
} else {
V_36 |= F_41 ( V_41 ) ;
}
F_3 ( F_42 ( V_59 ) , V_9 + V_91 ) ;
F_3 ( 0 , V_9 + V_92 ) ;
F_3 ( V_36 | V_93 , V_9 + V_94 ) ;
V_25 = F_36 ( V_2 , V_14 , V_16 , F_39 , 0 ) ;
if ( V_25 )
return V_25 ;
for ( V_37 = 0 ; V_37 < V_16 -> V_24 ; V_37 ++ ) {
unsigned int V_3 = V_17 [ V_37 ] ;
F_3 ( V_3 & 0xff , V_9 + V_91 ) ;
F_3 ( ( V_3 >> 8 ) & 0xff , V_9 + V_92 ) ;
F_3 ( V_36 | V_95 ,
V_9 + V_94 ) ;
V_25 = F_36 ( V_2 , V_14 , V_16 , F_39 , 0 ) ;
if ( V_25 )
return V_25 ;
V_14 -> V_96 [ V_41 ] = V_3 ;
}
return V_16 -> V_24 ;
}
static int F_43 ( struct V_1 * V_2 , struct V_97 * V_98 )
{
struct V_6 * V_7 ;
struct V_13 * V_14 ;
int V_25 ;
V_25 = F_44 ( V_2 , V_98 -> V_99 [ 0 ] , 32 ) ;
if ( V_25 )
return V_25 ;
V_7 = F_45 ( V_2 , sizeof( * V_7 ) ) ;
if ( ! V_7 )
return - V_100 ;
F_46 ( & V_7 -> V_11 ) ;
F_46 ( & V_7 -> V_38 ) ;
F_14 ( V_2 ) ;
if ( V_98 -> V_99 [ 1 ] ) {
V_25 = F_47 ( V_98 -> V_99 [ 1 ] , F_20 , 0 ,
V_2 -> V_101 , V_2 ) ;
if ( V_25 == 0 ) {
V_2 -> V_49 = V_98 -> V_99 [ 1 ] ;
F_3 ( V_102 ,
V_2 -> V_9 + V_103 ) ;
F_3 ( F_48 ( V_2 -> V_49 ) ,
V_2 -> V_9 + V_104 ) ;
}
}
V_25 = F_49 ( V_2 , 4 ) ;
if ( V_25 )
return V_25 ;
V_14 = & V_2 -> V_105 [ 0 ] ;
V_14 -> type = V_106 ;
V_14 -> V_107 = V_108 | V_109 | V_110 ;
V_14 -> V_20 = 16 ;
V_14 -> V_111 = 0xffff ;
V_14 -> V_112 = & V_113 ;
V_14 -> V_114 = F_33 ;
F_3 ( V_115 ,
V_2 -> V_9 + V_103 ) ;
F_3 ( V_115 ,
V_2 -> V_9 + V_103 + V_81 ) ;
V_14 = & V_2 -> V_105 [ 1 ] ;
V_14 -> type = V_116 ;
V_14 -> V_107 = V_108 ;
V_14 -> V_20 = 8 ;
V_14 -> V_111 = 0xffff ;
V_14 -> V_112 = & V_117 ;
V_14 -> V_118 = F_40 ;
V_25 = F_50 ( V_14 ) ;
if ( V_25 )
return V_25 ;
F_3 ( 0 , V_2 -> V_9 + V_119 ) ;
F_3 ( 0 , V_2 -> V_9 + V_90 +
V_119 ) ;
V_14 = & V_2 -> V_105 [ 2 ] ;
V_14 -> type = V_120 ;
V_14 -> V_107 = V_108 | V_121 ;
V_14 -> V_20 = 24 ;
V_14 -> V_111 = 1 ;
V_14 -> V_122 = 1 ;
V_14 -> V_112 = & V_123 ;
V_14 -> V_124 = F_10 ;
V_14 -> V_125 = F_12 ;
if ( V_2 -> V_49 ) {
V_2 -> V_51 = V_14 ;
V_14 -> V_107 |= V_126 | V_127 | V_128 ;
V_14 -> V_122 = V_14 -> V_20 ;
V_14 -> V_129 = F_24 ;
V_14 -> V_130 = F_26 ;
V_14 -> V_131 = F_27 ;
}
V_14 = & V_2 -> V_105 [ 3 ] ;
V_14 -> type = V_120 ;
V_14 -> V_107 = V_108 | V_121 ;
V_14 -> V_20 = 24 ;
V_14 -> V_111 = 1 ;
V_14 -> V_112 = & V_123 ;
V_14 -> V_124 = F_10 ;
V_14 -> V_125 = F_12 ;
return 0 ;
}

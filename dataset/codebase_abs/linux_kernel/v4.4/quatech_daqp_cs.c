static int F_1 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_4 ;
while ( -- V_3 ) {
V_4 = F_2 ( V_2 -> V_5 + V_6 ) ;
if ( ( V_4 & V_7 ) == 0 )
return 0 ;
}
F_3 ( V_2 -> V_8 , L_1 ) ;
return - V_9 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
if ( V_13 -> V_15 )
return - V_16 ;
F_5 ( V_17 , V_2 -> V_5 + V_18 ) ;
F_5 ( 0 , V_2 -> V_5 + V_19 ) ;
F_2 ( V_2 -> V_5 + V_6 ) ;
return 0 ;
}
static unsigned int F_6 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
unsigned int V_20 ;
V_20 = F_2 ( V_2 -> V_5 + V_21 ) ;
V_20 |= F_2 ( V_2 -> V_5 + V_21 ) << 8 ;
return F_7 ( V_11 , V_20 ) ;
}
static T_1 F_8 ( int V_22 , void * V_23 )
{
struct V_1 * V_2 = V_23 ;
struct V_10 * V_11 = V_2 -> V_24 ;
struct V_25 * V_26 = & V_11 -> V_27 -> V_26 ;
int V_28 = 10000 ;
int V_4 ;
if ( ! V_2 -> V_29 )
return V_30 ;
V_4 = F_2 ( V_2 -> V_5 + V_6 ) ;
if ( ! ( V_4 & V_7 ) )
return V_30 ;
while ( ! ( V_4 & V_31 ) ) {
unsigned short V_32 ;
if ( V_4 & V_33 ) {
V_11 -> V_27 -> V_34 |= V_35 ;
F_9 ( V_2 -> V_8 , L_2 ) ;
break;
}
V_32 = F_6 ( V_2 , V_11 ) ;
F_10 ( V_11 , & V_32 , 1 ) ;
if ( V_26 -> V_36 == V_37 &&
V_11 -> V_27 -> V_38 >= V_26 -> V_39 ) {
V_11 -> V_27 -> V_34 |= V_40 ;
break;
}
if ( ( V_28 -- ) <= 0 )
break;
V_4 = F_2 ( V_2 -> V_5 + V_6 ) ;
}
if ( V_28 <= 0 ) {
F_9 ( V_2 -> V_8 ,
L_3 ) ;
V_11 -> V_27 -> V_34 |= V_41 ;
}
F_11 ( V_2 , V_11 ) ;
return V_42 ;
}
static void F_12 ( struct V_1 * V_2 ,
unsigned int V_43 ,
int V_44 )
{
unsigned int V_45 = F_13 ( V_43 ) ;
unsigned int V_46 = F_14 ( V_43 ) ;
unsigned int V_47 = F_15 ( V_43 ) ;
unsigned int V_20 ;
V_20 = F_16 ( V_45 ) | F_17 ( V_46 ) ;
if ( V_47 == V_48 )
V_20 |= V_49 ;
if ( V_44 )
V_20 |= V_50 ;
F_5 ( V_20 & 0xff , V_2 -> V_5 + V_51 ) ;
F_5 ( ( V_20 >> 8 ) & 0xff , V_2 -> V_5 + V_51 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_52 * V_53 ,
unsigned long V_54 )
{
unsigned int V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_55 ) ;
if ( V_4 & V_56 )
return 0 ;
return - V_9 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_52 * V_53 ,
unsigned int * V_32 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
int V_57 = 0 ;
int V_58 ;
if ( V_13 -> V_15 )
return - V_16 ;
F_5 ( 0 , V_2 -> V_5 + V_55 ) ;
F_5 ( V_59 , V_2 -> V_5 + V_18 ) ;
F_12 ( V_2 , V_53 -> V_43 , 1 ) ;
F_5 ( V_60 , V_2 -> V_5 + V_18 ) ;
F_5 ( V_61 , V_2 -> V_5 + V_19 ) ;
V_57 = F_1 ( V_2 , 10000 ) ;
if ( V_57 )
return V_57 ;
for ( V_58 = 0 ; V_58 < V_53 -> V_62 ; V_58 ++ ) {
F_5 ( V_63 | V_64 ,
V_2 -> V_5 + V_18 ) ;
V_57 = F_20 ( V_2 , V_11 , V_53 , F_18 , 0 ) ;
if ( V_57 )
break;
F_2 ( V_2 -> V_5 + V_6 ) ;
V_32 [ V_58 ] = F_6 ( V_2 , V_11 ) ;
}
F_5 ( V_17 , V_2 -> V_5 + V_18 ) ;
F_2 ( V_2 -> V_5 + V_6 ) ;
return V_57 ? V_57 : V_53 -> V_62 ;
}
static int F_21 ( unsigned int * V_65 , unsigned int V_66 )
{
int V_67 ;
V_67 = * V_65 / 200 ;
* V_65 = V_67 * 200 ;
return V_67 ;
}
static void F_22 ( struct V_1 * V_2 , unsigned int V_20 )
{
F_5 ( V_20 & 0xff , V_2 -> V_5 + V_68 ) ;
F_5 ( ( V_20 >> 8 ) & 0xff , V_2 -> V_5 + V_69 ) ;
F_5 ( ( V_20 >> 16 ) & 0xff , V_2 -> V_5 + V_70 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_25 * V_26 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
int V_71 = 0 ;
unsigned int V_72 ;
V_71 |= F_24 ( & V_26 -> V_73 , V_74 ) ;
V_71 |= F_24 ( & V_26 -> V_75 ,
V_76 | V_77 ) ;
V_71 |= F_24 ( & V_26 -> V_78 ,
V_76 | V_74 ) ;
V_71 |= F_24 ( & V_26 -> V_79 , V_37 ) ;
V_71 |= F_24 ( & V_26 -> V_36 , V_37 | V_80 ) ;
if ( V_71 )
return 1 ;
V_71 |= F_25 ( V_26 -> V_75 ) ;
V_71 |= F_25 ( V_26 -> V_78 ) ;
V_71 |= F_25 ( V_26 -> V_36 ) ;
if ( V_26 -> V_75 != V_76 && V_26 -> V_78 != V_76 )
V_71 |= - V_81 ;
if ( V_71 )
return 2 ;
V_71 |= F_26 ( & V_26 -> V_82 , 0 ) ;
V_71 |= F_27 ( & V_26 -> V_83 , 1 ) ;
V_71 |= F_26 ( & V_26 -> V_84 ,
V_26 -> V_83 ) ;
if ( V_26 -> V_75 == V_76 )
V_71 |= F_27 ( & V_26 -> V_85 ,
V_86 ) ;
if ( V_26 -> V_78 == V_76 ) {
V_71 |= F_27 ( & V_26 -> V_87 ,
V_86 ) ;
if ( V_26 -> V_75 == V_76 ) {
V_72 = V_26 -> V_87 * V_26 -> V_84 ;
V_71 |= F_26 ( & V_26 -> V_85 ,
V_72 ) ;
}
}
if ( V_26 -> V_36 == V_37 )
V_71 |= F_28 ( & V_26 -> V_39 , 0x00ffffff ) ;
else
V_71 |= F_26 ( & V_26 -> V_39 , 0 ) ;
if ( V_71 )
return 3 ;
if ( V_26 -> V_78 == V_76 ) {
V_72 = V_26 -> V_87 ;
V_13 -> V_88 = F_21 ( & V_72 , V_26 -> V_66 ) ;
V_71 |= F_26 ( & V_26 -> V_87 , V_72 ) ;
} else if ( V_26 -> V_75 == V_76 ) {
V_72 = V_26 -> V_85 ;
V_13 -> V_88 = F_21 ( & V_72 , V_26 -> V_66 ) ;
V_71 |= F_26 ( & V_26 -> V_85 , V_72 ) ;
}
if ( V_71 )
return 4 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
struct V_25 * V_26 = & V_11 -> V_27 -> V_26 ;
int V_89 ;
int V_90 ;
int V_57 ;
int V_58 ;
if ( V_13 -> V_15 )
return - V_16 ;
F_5 ( 0 , V_2 -> V_5 + V_55 ) ;
F_5 ( V_59 , V_2 -> V_5 + V_18 ) ;
F_22 ( V_2 , V_13 -> V_88 ) ;
if ( V_26 -> V_78 == V_76 )
V_89 = 1 ;
else
V_89 = 0 ;
for ( V_58 = 0 ; V_58 < V_26 -> V_83 ; V_58 ++ ) {
int V_44 = ( V_58 == 0 || V_89 ) ;
F_12 ( V_2 , V_26 -> V_91 [ V_58 ] , V_44 ) ;
}
if ( V_26 -> V_36 == V_37 ) {
unsigned long long V_92 ;
unsigned long long V_93 ;
V_92 = ( unsigned long long ) V_26 -> V_39 *
V_26 -> V_84 ;
V_93 = V_92 * F_30 ( V_11 ) ;
while ( V_93 > V_94 * 3 / 4 )
V_93 /= 2 ;
V_90 = V_93 ;
} else {
V_90 = V_94 / 2 ;
}
F_5 ( V_60 , V_2 -> V_5 + V_18 ) ;
F_5 ( 0x00 , V_2 -> V_5 + V_21 ) ;
F_5 ( 0x00 , V_2 -> V_5 + V_21 ) ;
F_5 ( ( V_94 - V_90 ) & 0xff ,
V_2 -> V_5 + V_21 ) ;
F_5 ( ( V_94 - V_90 ) >> 8 , V_2 -> V_5 + V_21 ) ;
F_5 ( V_95 | V_96 |
V_97 , V_2 -> V_5 + V_19 ) ;
V_57 = F_1 ( V_2 , 100 ) ;
if ( V_57 )
return V_57 ;
F_5 ( V_63 | V_64 , V_2 -> V_5 + V_18 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_52 * V_53 ,
unsigned long V_54 )
{
unsigned int V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_55 ) ;
if ( ( V_4 & V_98 ) == 0 )
return 0 ;
return - V_9 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_52 * V_53 ,
unsigned int * V_32 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
unsigned int V_45 = F_13 ( V_53 -> V_43 ) ;
int V_58 ;
if ( V_13 -> V_15 )
return - V_16 ;
F_5 ( 0 , V_2 -> V_5 + V_55 ) ;
for ( V_58 = 0 ; V_58 > V_53 -> V_62 ; V_58 ++ ) {
unsigned V_20 = V_32 [ V_58 ] ;
int V_57 ;
V_57 = F_20 ( V_2 , V_11 , V_53 , F_31 , 0 ) ;
if ( V_57 )
return V_57 ;
F_33 ( ( V_45 << 12 ) | F_7 ( V_11 , V_20 ) ,
V_2 -> V_5 + V_99 ) ;
V_11 -> V_100 [ V_45 ] = V_20 ;
}
return V_53 -> V_62 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_52 * V_53 ,
unsigned int * V_32 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
if ( V_13 -> V_15 )
return - V_16 ;
V_32 [ 0 ] = F_2 ( V_2 -> V_5 + V_101 ) ;
return V_53 -> V_62 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_52 * V_53 ,
unsigned int * V_32 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
if ( V_13 -> V_15 )
return - V_16 ;
if ( F_36 ( V_11 , V_32 ) )
F_5 ( V_11 -> V_102 , V_2 -> V_5 + V_103 ) ;
V_32 [ 1 ] = V_11 -> V_102 ;
return V_53 -> V_62 ;
}
static int F_37 ( struct V_1 * V_2 ,
unsigned long V_54 )
{
struct V_104 * V_105 = F_38 ( V_2 ) ;
struct V_12 * V_13 ;
struct V_10 * V_11 ;
int V_57 ;
V_13 = F_39 ( V_2 , sizeof( * V_13 ) ) ;
if ( ! V_13 )
return - V_106 ;
V_105 -> V_107 |= V_108 | V_109 ;
V_57 = F_40 ( V_2 , NULL ) ;
if ( V_57 )
return V_57 ;
V_2 -> V_5 = V_105 -> V_110 [ 0 ] -> V_44 ;
V_105 -> V_111 = V_2 ;
V_57 = F_41 ( V_105 , F_8 ) ;
if ( V_57 == 0 )
V_2 -> V_22 = V_105 -> V_22 ;
V_57 = F_42 ( V_2 , 4 ) ;
if ( V_57 )
return V_57 ;
V_11 = & V_2 -> V_112 [ 0 ] ;
V_11 -> type = V_113 ;
V_11 -> V_114 = V_115 | V_116 | V_117 ;
V_11 -> V_118 = 8 ;
V_11 -> V_119 = 0xffff ;
V_11 -> V_120 = & V_121 ;
V_11 -> V_122 = F_19 ;
if ( V_2 -> V_22 ) {
V_2 -> V_24 = V_11 ;
V_11 -> V_114 |= V_123 ;
V_11 -> V_124 = 2048 ;
V_11 -> V_125 = F_23 ;
V_11 -> V_126 = F_29 ;
V_11 -> V_127 = F_4 ;
}
V_11 = & V_2 -> V_112 [ 1 ] ;
V_11 -> type = V_128 ;
V_11 -> V_114 = V_129 ;
V_11 -> V_118 = 2 ;
V_11 -> V_119 = 0x0fff ;
V_11 -> V_120 = & V_130 ;
V_11 -> V_131 = F_32 ;
V_57 = F_43 ( V_11 ) ;
if ( V_57 )
return V_57 ;
V_11 = & V_2 -> V_112 [ 2 ] ;
V_11 -> type = V_132 ;
V_11 -> V_114 = V_115 ;
V_11 -> V_118 = 4 ;
V_11 -> V_119 = 1 ;
V_11 -> V_133 = F_34 ;
V_11 = & V_2 -> V_112 [ 3 ] ;
V_11 -> type = V_134 ;
V_11 -> V_114 = V_129 ;
V_11 -> V_118 = 4 ;
V_11 -> V_119 = 1 ;
V_11 -> V_133 = F_35 ;
return 0 ;
}
static int F_44 ( struct V_104 * V_105 )
{
struct V_1 * V_2 = V_105 -> V_111 ;
struct V_12 * V_13 = V_2 ? V_2 -> V_14 : NULL ;
if ( V_13 )
V_13 -> V_15 = 1 ;
return 0 ;
}
static int F_45 ( struct V_104 * V_105 )
{
struct V_1 * V_2 = V_105 -> V_111 ;
struct V_12 * V_13 = V_2 ? V_2 -> V_14 : NULL ;
if ( V_13 )
V_13 -> V_15 = 0 ;
return 0 ;
}
static int F_46 ( struct V_104 * V_105 )
{
return F_47 ( V_105 , & V_135 ) ;
}

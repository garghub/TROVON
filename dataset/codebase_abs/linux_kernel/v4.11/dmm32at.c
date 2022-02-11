static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_5 , int V_6 )
{
unsigned int V_7 = F_2 ( V_5 ) ;
unsigned int V_8 = F_3 ( V_5 ) ;
unsigned int V_9 = ( V_7 + V_6 - 1 ) % V_4 -> V_10 ;
F_4 ( V_11 , V_2 -> V_12 + V_13 ) ;
if ( V_6 > 1 )
F_4 ( V_14 ,
V_2 -> V_12 + V_13 ) ;
F_4 ( V_7 , V_2 -> V_12 + V_15 ) ;
F_4 ( V_9 , V_2 -> V_12 + V_16 ) ;
F_4 ( V_17 [ V_8 ] , V_2 -> V_12 + V_18 ) ;
}
static unsigned int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_19 ;
V_19 = F_6 ( V_2 -> V_12 + V_20 ) ;
V_19 |= ( F_6 ( V_2 -> V_12 + V_21 ) << 8 ) ;
return F_7 ( V_4 , V_19 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_22 * V_23 ,
unsigned long V_24 )
{
unsigned char V_25 ;
V_25 = F_6 ( V_2 -> V_12 + V_24 ) ;
if ( ( V_25 & V_26 ) == 0 )
return 0 ;
return - V_27 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_22 * V_23 ,
unsigned int * V_28 )
{
int V_29 ;
int V_30 ;
F_1 ( V_2 , V_4 , V_23 -> V_5 , 1 ) ;
V_29 = F_10 ( V_2 , V_4 , V_23 , F_8 ,
V_31 ) ;
if ( V_29 )
return V_29 ;
for ( V_30 = 0 ; V_30 < V_23 -> V_32 ; V_30 ++ ) {
F_4 ( 0xff , V_2 -> V_12 + V_33 ) ;
V_29 = F_10 ( V_2 , V_4 , V_23 , F_8 ,
V_34 ) ;
if ( V_29 )
return V_29 ;
V_28 [ V_30 ] = F_5 ( V_2 , V_4 ) ;
}
return V_23 -> V_32 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_35 * V_36 )
{
unsigned int V_37 = F_2 ( V_36 -> V_38 [ 0 ] ) ;
unsigned int V_39 = F_3 ( V_36 -> V_38 [ 0 ] ) ;
int V_30 ;
for ( V_30 = 1 ; V_30 < V_36 -> V_40 ; V_30 ++ ) {
unsigned int V_7 = F_2 ( V_36 -> V_38 [ V_30 ] ) ;
unsigned int V_8 = F_3 ( V_36 -> V_38 [ V_30 ] ) ;
if ( V_7 != ( V_37 + V_30 ) % V_4 -> V_10 ) {
F_12 ( V_2 -> V_41 ,
L_1 ) ;
return - V_42 ;
}
if ( V_8 != V_39 ) {
F_12 ( V_2 -> V_41 ,
L_2 ) ;
return - V_42 ;
}
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_35 * V_36 )
{
int V_43 = 0 ;
unsigned int V_44 ;
V_43 |= F_14 ( & V_36 -> V_45 , V_46 ) ;
V_43 |= F_14 ( & V_36 -> V_47 , V_48 ) ;
V_43 |= F_14 ( & V_36 -> V_49 , V_48 ) ;
V_43 |= F_14 ( & V_36 -> V_50 , V_51 ) ;
V_43 |= F_14 ( & V_36 -> V_52 , V_51 | V_53 ) ;
if ( V_43 )
return 1 ;
V_43 |= F_15 ( V_36 -> V_52 ) ;
if ( V_43 )
return 2 ;
V_43 |= F_16 ( & V_36 -> V_54 , 0 ) ;
V_43 |= F_17 ( & V_36 -> V_55 , 1000000 ) ;
V_43 |= F_18 ( & V_36 -> V_55 , 1000000000 ) ;
if ( V_36 -> V_56 >= 17500 )
V_36 -> V_56 = 20000 ;
else if ( V_36 -> V_56 >= 12500 )
V_36 -> V_56 = 15000 ;
else if ( V_36 -> V_56 >= 7500 )
V_36 -> V_56 = 10000 ;
else
V_36 -> V_56 = 5000 ;
V_43 |= F_16 ( & V_36 -> V_57 ,
V_36 -> V_40 ) ;
if ( V_36 -> V_52 == V_51 )
V_43 |= F_17 ( & V_36 -> V_58 , 1 ) ;
else
V_43 |= F_16 ( & V_36 -> V_58 , 0 ) ;
if ( V_43 )
return 3 ;
V_44 = V_36 -> V_56 * V_36 -> V_57 ;
V_43 |= F_17 ( & V_36 -> V_55 , V_44 ) ;
if ( V_43 )
return 4 ;
if ( V_36 -> V_38 && V_36 -> V_40 > 0 )
V_43 |= F_11 ( V_2 , V_4 , V_36 ) ;
if ( V_43 )
return 5 ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 , unsigned int V_59 )
{
unsigned char V_60 , V_61 , V_62 ;
unsigned short V_63 ;
V_60 = 200 ;
V_63 = V_59 / 20000 ;
V_62 = ( V_63 & 0xff00 ) >> 8 ;
V_61 = V_63 & 0x00ff ;
F_4 ( 0 , V_2 -> V_12 + V_64 ) ;
F_4 ( V_65 , V_2 -> V_12 + V_66 ) ;
F_4 ( V_67 , V_2 -> V_12 + V_68 ) ;
F_4 ( V_60 , V_2 -> V_12 + V_69 ) ;
F_4 ( V_70 , V_2 -> V_12 + V_68 ) ;
F_4 ( V_61 , V_2 -> V_12 + V_71 ) ;
F_4 ( V_62 , V_2 -> V_12 + V_71 ) ;
F_4 ( V_72 |
V_73 | V_74 ,
V_2 -> V_12 + V_75 ) ;
}
static int F_20 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_35 * V_36 = & V_4 -> V_76 -> V_36 ;
int V_29 ;
F_1 ( V_2 , V_4 , V_36 -> V_38 [ 0 ] , V_36 -> V_40 ) ;
F_4 ( V_77 , V_2 -> V_12 + V_66 ) ;
V_29 = F_10 ( V_2 , V_4 , NULL , F_8 ,
V_31 ) ;
if ( V_29 )
return V_29 ;
if ( V_36 -> V_52 == V_53 || V_36 -> V_58 > 1 ) {
F_19 ( V_2 , V_36 -> V_55 ) ;
} else {
F_4 ( V_72 , V_2 -> V_12 + V_75 ) ;
F_4 ( 0xff , V_2 -> V_12 + V_33 ) ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_4 ( 0x0 , V_2 -> V_12 + V_75 ) ;
return 0 ;
}
static T_1 F_22 ( int V_78 , void * V_79 )
{
struct V_1 * V_2 = V_79 ;
unsigned char V_80 ;
unsigned int V_19 ;
int V_30 ;
if ( ! V_2 -> V_81 ) {
F_23 ( V_2 -> V_41 , L_3 ) ;
return V_82 ;
}
V_80 = F_6 ( V_2 -> V_12 + V_75 ) ;
if ( V_80 & V_72 ) {
struct V_3 * V_4 = V_2 -> V_83 ;
struct V_35 * V_36 = & V_4 -> V_76 -> V_36 ;
for ( V_30 = 0 ; V_30 < V_36 -> V_40 ; V_30 ++ ) {
V_19 = F_5 ( V_2 , V_4 ) ;
F_24 ( V_4 , & V_19 , 1 ) ;
}
if ( V_36 -> V_52 == V_51 &&
V_4 -> V_76 -> V_84 >= V_36 -> V_58 )
V_4 -> V_76 -> V_85 |= V_86 ;
F_25 ( V_2 , V_4 ) ;
}
F_4 ( V_77 , V_2 -> V_12 + V_66 ) ;
return V_82 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_22 * V_23 ,
unsigned long V_24 )
{
unsigned char V_25 ;
V_25 = F_6 ( V_2 -> V_12 + V_87 ) ;
if ( ( V_25 & V_88 ) == 0 )
return 0 ;
return - V_27 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_22 * V_23 ,
unsigned int * V_28 )
{
unsigned int V_7 = F_2 ( V_23 -> V_5 ) ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_23 -> V_32 ; V_30 ++ ) {
unsigned int V_19 = V_28 [ V_30 ] ;
int V_29 ;
F_4 ( V_19 & 0xff , V_2 -> V_12 + V_89 ) ;
F_4 ( ( V_19 >> 8 ) | F_28 ( V_7 ) ,
V_2 -> V_12 + V_90 ) ;
V_29 = F_10 ( V_2 , V_4 , V_23 , F_26 , 0 ) ;
if ( V_29 )
return V_29 ;
F_6 ( V_2 -> V_12 + V_90 ) ;
V_4 -> V_91 [ V_7 ] = V_19 ;
}
return V_23 -> V_32 ;
}
static int F_29 ( struct V_1 * V_2 ,
int V_92 , int V_93 , int V_28 , unsigned long V_94 )
{
F_4 ( V_95 , V_2 -> V_12 + V_66 ) ;
if ( V_92 ) {
F_4 ( V_28 , V_2 -> V_12 + V_94 + V_93 ) ;
return 0 ;
}
return F_6 ( V_2 -> V_12 + V_94 + V_93 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
unsigned char V_96 , V_97 , V_98 , V_99 , V_80 , V_100 ;
F_4 ( V_101 , V_2 -> V_12 + V_66 ) ;
F_31 ( 1000 , 3000 ) ;
F_4 ( 0x0 , V_2 -> V_12 + V_13 ) ;
F_4 ( 0x0 , V_2 -> V_12 + V_75 ) ;
F_4 ( 0x80 , V_2 -> V_12 + V_15 ) ;
F_4 ( 0xff , V_2 -> V_12 + V_16 ) ;
F_4 ( V_102 , V_2 -> V_12 + V_18 ) ;
F_31 ( 100 , 200 ) ;
V_97 = F_6 ( V_2 -> V_12 + V_15 ) ;
V_96 = F_6 ( V_2 -> V_12 + V_16 ) ;
V_98 = F_6 ( V_2 -> V_12 + V_103 ) ;
V_99 = F_6 ( V_2 -> V_12 + V_34 ) ;
V_80 = F_6 ( V_2 -> V_12 + V_75 ) ;
V_100 = F_6 ( V_2 -> V_12 + V_31 ) ;
if ( V_97 != 0x00 || V_96 != 0x1f ||
V_98 != V_104 ||
V_99 != ( V_105 | V_106 ) ||
V_80 != 0x00 || V_100 != 0x0c )
return - V_107 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_108 * V_109 )
{
struct V_3 * V_4 ;
int V_29 ;
V_29 = F_33 ( V_2 , V_109 -> V_110 [ 0 ] , 0x10 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_30 ( V_2 ) ;
if ( V_29 ) {
F_23 ( V_2 -> V_41 , L_4 ) ;
return V_29 ;
}
if ( V_109 -> V_110 [ 1 ] ) {
V_29 = F_34 ( V_109 -> V_110 [ 1 ] , F_22 , 0 ,
V_2 -> V_111 , V_2 ) ;
if ( V_29 == 0 )
V_2 -> V_78 = V_109 -> V_110 [ 1 ] ;
}
V_29 = F_35 ( V_2 , 3 ) ;
if ( V_29 )
return V_29 ;
V_4 = & V_2 -> V_112 [ 0 ] ;
V_4 -> type = V_113 ;
V_4 -> V_114 = V_115 | V_116 | V_117 ;
V_4 -> V_10 = 32 ;
V_4 -> V_118 = 0xffff ;
V_4 -> V_119 = & V_120 ;
V_4 -> V_121 = F_9 ;
if ( V_2 -> V_78 ) {
V_2 -> V_83 = V_4 ;
V_4 -> V_114 |= V_122 ;
V_4 -> V_123 = V_4 -> V_10 ;
V_4 -> V_124 = F_20 ;
V_4 -> V_125 = F_13 ;
V_4 -> V_126 = F_21 ;
}
V_4 = & V_2 -> V_112 [ 1 ] ;
V_4 -> type = V_127 ;
V_4 -> V_114 = V_128 ;
V_4 -> V_10 = 4 ;
V_4 -> V_118 = 0x0fff ;
V_4 -> V_119 = & V_129 ;
V_4 -> V_130 = F_27 ;
V_29 = F_36 ( V_4 ) ;
if ( V_29 )
return V_29 ;
V_4 = & V_2 -> V_112 [ 2 ] ;
return F_37 ( V_2 , V_4 , F_29 , V_131 ) ;
}

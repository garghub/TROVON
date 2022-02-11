static unsigned int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_5 ;
V_5 = F_2 ( V_2 -> V_6 + V_7 ) |
( F_2 ( V_2 -> V_6 + V_8 ) << 8 ) ;
return V_5 & V_4 -> V_9 ;
}
static T_1 F_3 ( int V_10 , void * V_11 )
{
struct V_1 * V_2 = V_11 ;
struct V_3 * V_4 = V_2 -> V_12 ;
struct V_13 * V_14 = V_4 -> V_14 ;
struct V_15 * V_16 = & V_14 -> V_16 ;
unsigned int V_17 ;
if ( ! V_2 -> V_18 )
return V_19 ;
V_17 = F_2 ( V_2 -> V_6 + V_20 ) ;
if ( V_17 & V_21 ) {
V_14 -> V_22 |= V_23 ;
F_4 ( V_17 | V_24 ,
V_2 -> V_6 + V_20 ) ;
}
if ( V_17 & V_25 ) {
unsigned short V_5 ;
V_5 = F_1 ( V_2 , V_4 ) ;
F_5 ( V_4 , & V_5 , 1 ) ;
}
if ( V_16 -> V_26 == V_27 && V_14 -> V_28 >= V_16 -> V_29 )
V_14 -> V_22 |= V_30 ;
F_6 ( V_2 , V_4 ) ;
return V_31 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_4 ( F_8 ( 0 ) , V_2 -> V_6 + V_20 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 ,
unsigned int V_32 )
{
unsigned int V_33 = F_10 ( V_32 ) ;
unsigned int V_34 = F_11 ( V_32 ) ;
F_4 ( F_12 ( V_33 ) | F_13 ( V_34 ) ,
V_2 -> V_6 + V_35 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_36 * V_37 = V_2 -> V_38 ;
struct V_15 * V_16 = & V_4 -> V_14 -> V_16 ;
unsigned int V_39 ;
if ( V_16 -> V_40 == V_41 ) {
V_39 = F_8 ( 1 ) ;
} else {
if ( V_16 -> V_42 == V_43 ) {
V_39 = F_8 ( 2 ) ;
} else {
V_39 = F_8 ( 3 ) ;
}
}
F_4 ( V_39 | V_44 , V_2 -> V_6 + V_20 ) ;
F_4 ( V_37 -> V_45 , V_2 -> V_6 + V_46 ) ;
F_9 ( V_2 , V_16 -> V_47 [ 0 ] ) ;
return 0 ;
}
static unsigned int F_15 ( unsigned int * V_48 ,
unsigned int V_49 )
{
unsigned long long V_50 = * V_48 ;
unsigned int V_51 = V_52 ;
unsigned int V_53 = 0 ;
unsigned int V_54 = 0 ;
unsigned int V_55 = 0 ;
unsigned int V_56 ;
unsigned int V_57 ;
for ( V_56 = 0 ; V_56 <= 7 ; V_56 ++ ) {
for ( V_57 = 0 ; V_57 <= 7 ; V_57 ++ ) {
unsigned int div = V_58 [ V_56 ] ;
unsigned int V_59 = V_60 [ V_57 ] ;
unsigned long long V_61 = div * V_59 ;
unsigned int V_62 = F_16 ( V_56 ) |
F_17 ( V_57 ) ;
V_50 = V_61 * V_63 ;
if ( V_50 > V_52 )
continue;
if ( V_50 <= * V_48 && V_50 > V_53 ) {
V_53 = V_50 ;
V_54 = V_62 ;
}
if ( V_50 >= * V_48 && V_50 < V_51 ) {
V_51 = V_50 ;
V_55 = V_62 ;
}
}
}
if ( V_51 == V_52 ) {
V_51 = V_53 ;
V_55 = V_54 ;
}
if ( V_53 == 0 ) {
V_53 = V_51 ;
V_54 = V_55 ;
}
switch ( V_49 & V_64 ) {
case V_65 :
default:
if ( V_53 - * V_48 < * V_48 - V_51 ) {
* V_48 = V_51 ;
return V_55 ;
}
* V_48 = V_53 ;
return V_54 ;
case V_66 :
* V_48 = V_51 ;
return V_55 ;
case V_67 :
* V_48 = V_53 ;
return V_54 ;
}
}
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_15 * V_16 )
{
struct V_36 * V_37 = V_2 -> V_38 ;
unsigned int V_68 ;
int V_69 = 0 ;
V_69 |= F_19 ( & V_16 -> V_40 , V_41 | V_70 ) ;
V_69 |= F_19 ( & V_16 -> V_71 , V_72 ) ;
V_69 |= F_19 ( & V_16 -> V_42 ,
V_43 | V_70 ) ;
V_69 |= F_19 ( & V_16 -> V_73 , V_27 ) ;
V_69 |= F_19 ( & V_16 -> V_26 , V_27 | V_74 ) ;
if ( V_69 )
return 1 ;
V_69 |= F_20 ( V_16 -> V_40 ) ;
V_69 |= F_20 ( V_16 -> V_42 ) ;
V_69 |= F_20 ( V_16 -> V_26 ) ;
if ( V_16 -> V_42 == V_70 && V_16 -> V_40 != V_70 )
V_69 |= - V_75 ;
if ( V_69 )
return 2 ;
V_69 |= F_21 ( & V_16 -> V_76 , 0 ) ;
V_69 |= F_21 ( & V_16 -> V_77 , 0 ) ;
if ( V_16 -> V_42 == V_43 )
V_69 |= F_22 ( & V_16 -> V_78 , 12500 ) ;
V_69 |= F_21 ( & V_16 -> V_79 ,
V_16 -> V_80 ) ;
if ( V_16 -> V_26 == V_27 )
V_69 |= F_22 ( & V_16 -> V_29 , 1 ) ;
else
V_69 |= F_21 ( & V_16 -> V_29 , 0 ) ;
if ( V_69 )
return 3 ;
if ( V_16 -> V_42 == V_43 ) {
V_68 = V_16 -> V_78 ;
V_37 -> V_45 = F_15 ( & V_68 , V_16 -> V_49 ) ;
V_69 |= F_21 ( & V_16 -> V_78 , V_68 ) ;
} else {
V_37 -> V_45 = V_16 -> V_78 ;
}
if ( V_69 )
return 4 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_81 * V_82 ,
unsigned long V_83 )
{
unsigned int V_17 ;
V_17 = F_2 ( V_2 -> V_6 + V_20 ) ;
if ( ( V_17 & V_84 ) == 0 )
return 0 ;
return - V_85 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_81 * V_82 ,
unsigned int * V_86 )
{
int V_87 ;
int V_88 ;
for ( V_88 = 0 ; V_88 < V_82 -> V_89 ; V_88 ++ ) {
F_9 ( V_2 , V_82 -> V_32 ) ;
V_87 = F_25 ( V_2 , V_4 , V_82 , F_23 , 0 ) ;
if ( V_87 )
return V_87 ;
V_86 [ V_88 ] = F_1 ( V_2 , V_4 ) ;
}
return V_82 -> V_89 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_81 * V_82 ,
unsigned int * V_86 )
{
unsigned int V_33 = F_10 ( V_82 -> V_32 ) ;
unsigned int V_5 = V_4 -> V_90 [ V_33 ] ;
int V_88 ;
for ( V_88 = 0 ; V_88 < V_82 -> V_89 ; V_88 ++ ) {
V_5 = V_86 [ V_88 ] ;
F_4 ( V_5 & 0xff , V_2 -> V_6 + F_27 ( V_33 ) ) ;
F_4 ( ( V_5 >> 8 ) & 0xff ,
V_2 -> V_6 + F_28 ( V_33 ) ) ;
}
V_4 -> V_90 [ V_33 ] = V_5 ;
return V_82 -> V_89 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_81 * V_82 ,
unsigned int * V_86 )
{
V_86 [ 1 ] = F_2 ( V_2 -> V_6 + V_91 ) ;
return V_82 -> V_89 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_81 * V_82 ,
unsigned int * V_86 )
{
if ( F_31 ( V_4 , V_86 ) )
F_4 ( V_4 -> V_92 , V_2 -> V_6 + V_93 ) ;
V_86 [ 1 ] = V_4 -> V_92 ;
return V_82 -> V_89 ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_4 ( F_8 ( 0 ) , V_2 -> V_6 + V_20 ) ;
F_33 ( 100 , 1000 ) ;
F_2 ( V_2 -> V_6 + V_7 ) ;
F_2 ( V_2 -> V_6 + V_8 ) ;
F_4 ( F_8 ( 0 ) | V_24 ,
V_2 -> V_6 + V_20 ) ;
}
static int F_34 ( struct V_1 * V_2 , struct V_94 * V_95 )
{
const struct V_96 * V_97 = V_2 -> V_98 ;
struct V_36 * V_37 ;
struct V_3 * V_4 ;
int V_87 ;
V_37 = F_35 ( V_2 , sizeof( * V_37 ) ) ;
if ( ! V_37 )
return - V_99 ;
V_87 = F_36 ( V_2 , V_95 -> V_100 [ 0 ] , 0x8 ) ;
if ( V_87 )
return V_87 ;
F_32 ( V_2 ) ;
if ( V_95 -> V_100 [ 1 ] <= 7 && ( F_37 ( V_95 -> V_100 [ 1 ] ) & 0xac ) ) {
V_87 = F_38 ( V_95 -> V_100 [ 1 ] , F_3 , 0 ,
V_2 -> V_101 , V_2 ) ;
if ( V_87 == 0 )
V_2 -> V_10 = V_95 -> V_100 [ 1 ] ;
}
V_87 = F_39 ( V_2 , 4 ) ;
if ( V_87 )
return V_87 ;
V_4 = & V_2 -> V_102 [ 0 ] ;
V_4 -> type = V_103 ;
V_4 -> V_104 = V_105 |
( ( V_95 -> V_100 [ 2 ] == 1 ) ? V_106 :
( V_95 -> V_100 [ 2 ] == 2 ) ? V_107 : V_108 ) ;
V_4 -> V_109 = ( V_95 -> V_100 [ 2 ] == 1 ) ? 8 : 16 ;
V_4 -> V_9 = 0x0fff ;
V_4 -> V_110 = V_97 -> V_111 ? & V_112
: & V_113 ;
V_4 -> V_114 = F_24 ;
if ( V_2 -> V_10 ) {
V_2 -> V_12 = V_4 ;
V_4 -> V_104 |= V_115 ;
V_4 -> V_116 = 1 ;
V_4 -> V_117 = F_18 ;
V_4 -> V_118 = F_14 ;
V_4 -> V_119 = F_7 ;
}
V_4 = & V_2 -> V_102 [ 1 ] ;
V_4 -> type = V_120 ;
V_4 -> V_104 = V_121 ;
V_4 -> V_109 = 2 ;
V_4 -> V_9 = 0x0fff ;
V_4 -> V_110 = & V_122 ;
V_4 -> V_123 = F_26 ;
V_87 = F_40 ( V_4 ) ;
if ( V_87 )
return V_87 ;
V_4 = & V_2 -> V_102 [ 2 ] ;
V_4 -> type = V_124 ;
V_4 -> V_104 = V_105 ;
V_4 -> V_109 = 8 ;
V_4 -> V_9 = 1 ;
V_4 -> V_110 = & V_125 ;
V_4 -> V_126 = F_29 ;
V_4 = & V_2 -> V_102 [ 3 ] ;
V_4 -> type = V_127 ;
V_4 -> V_104 = V_121 ;
V_4 -> V_109 = 8 ;
V_4 -> V_9 = 1 ;
V_4 -> V_110 = & V_125 ;
V_4 -> V_126 = F_30 ;
return 0 ;
}

static void F_1 ( const char * V_1 , int V_2 )
{
F_2 ( V_3 ,
L_1 ,
V_1 , ( V_2 ? L_2 : L_3 ) ) ;
}
static int F_3 ( struct V_4 * V_5 , int * V_6 )
{
struct V_7 * V_8 = V_5 -> V_8 ;
if ( ( V_8 -> V_9 > 0 ) && ( V_8 -> V_9 <= V_10 ) ) {
* V_6 = V_8 -> V_11 [ V_8 -> V_9 - 1 ] ;
} else {
* V_6 = 0 ;
}
return 0 ;
}
static int F_4 ( struct V_4 * V_5 , int V_12 , int V_13 )
{
struct V_7 * V_8 = V_5 -> V_8 ;
unsigned int V_14 = V_8 -> V_9 ;
if ( ( V_14 > 0 ) && ( V_14 <= V_10 ) ) {
V_8 -> V_11 [ V_14 - 1 ] = V_13 ;
if ( V_8 -> V_15 ) {
if ( V_8 -> V_16 == V_14 ) {
V_8 -> V_16 = 0 ;
}
} else {
if ( V_8 -> V_17 == V_14 ) {
V_8 -> V_17 = 0 ;
}
}
}
return 0 ;
}
static int F_5 ( struct V_4 * V_5 , int * V_6 )
{
* V_6 = V_5 -> V_8 -> V_9 ;
return 0 ;
}
static int F_6 ( struct V_4 * V_5 , int V_12 , int V_13 )
{
struct V_7 * V_8 = V_5 -> V_8 ;
if ( ( V_13 >= 0 ) && ( V_13 <= V_10 ) ) {
V_8 -> V_9 = V_13 ;
}
return 0 ;
}
static int F_7 ( struct V_4 * V_5 , int * V_6 )
{
struct V_7 * V_8 = V_5 -> V_8 ;
* V_6 = V_8 -> V_15 ? V_8 -> V_16 : V_8 -> V_17 ;
return 0 ;
}
static int F_8 ( struct V_4 * V_5 , int V_12 , int V_14 )
{
unsigned V_18 = 0 ;
struct V_7 * V_8 = V_5 -> V_8 ;
if ( ( V_14 < 0 ) || ( V_14 > V_10 ) ) return 0 ;
if ( V_14 > 0 ) {
V_18 = V_8 -> V_11 [ V_14 - 1 ] ;
if ( ! V_18 ) return 0 ;
F_9 ( V_8 , V_18 ) ;
}
if ( V_8 -> V_15 ) {
V_8 -> V_16 = V_14 ;
} else {
V_8 -> V_17 = V_14 ;
}
return 0 ;
}
static int F_10 ( struct V_4 * V_5 , int * V_6 )
{
* V_6 = F_11 ( V_5 -> V_8 ) ;
return 0 ;
}
static int F_12 ( struct V_4 * V_5 )
{
return V_5 -> V_8 -> V_19 != 0 ;
}
static void F_13 ( struct V_4 * V_5 )
{
V_5 -> V_8 -> V_19 = 0 ;
}
static int F_14 ( struct V_4 * V_5 , int V_12 , int V_13 )
{
F_9 ( V_5 -> V_8 , V_13 ) ;
return 0 ;
}
static int F_15 ( struct V_4 * V_5 , int * V_20 )
{
struct V_21 * V_22 = & V_5 -> V_8 -> V_23 ;
int V_24 = F_16 ( V_5 -> V_8 ) ;
if ( V_24 != 0 ) {
return V_24 ;
}
* V_20 = V_22 -> V_25 . V_20 ;
return 0 ;
}
static int F_17 ( struct V_4 * V_5 , int * V_20 )
{
struct V_21 * V_22 = & V_5 -> V_8 -> V_23 ;
int V_24 = F_16 ( V_5 -> V_8 ) ;
if ( V_24 != 0 ) {
return V_24 ;
}
* V_20 = V_22 -> V_25 . V_20 ;
if ( V_22 -> V_25 . V_26 > V_5 -> V_8 -> V_27 ) {
* V_20 += V_22 -> V_25 . V_26 - V_5 -> V_8 -> V_27 ;
}
return 0 ;
}
static int F_18 ( struct V_4 * V_5 , int * V_28 )
{
struct V_21 * V_22 = & V_5 -> V_8 -> V_23 ;
int V_24 = F_16 ( V_5 -> V_8 ) ;
if ( V_24 != 0 ) {
return V_24 ;
}
* V_28 = V_22 -> V_25 . V_28 ;
return 0 ;
}
static int F_19 ( struct V_4 * V_5 , int * V_28 )
{
struct V_21 * V_22 = & V_5 -> V_8 -> V_23 ;
int V_24 = F_16 ( V_5 -> V_8 ) ;
if ( V_24 != 0 ) {
return V_24 ;
}
* V_28 = V_22 -> V_25 . V_28 ;
if ( V_22 -> V_25 . V_29 > V_5 -> V_8 -> V_30 ) {
* V_28 += V_22 -> V_25 . V_29 - V_5 -> V_8 -> V_30 ;
}
return 0 ;
}
static int F_20 ( struct V_4 * V_5 , int * V_26 )
{
struct V_21 * V_22 = & V_5 -> V_8 -> V_23 ;
int V_24 , V_31 , V_32 ;
V_24 = F_16 ( V_5 -> V_8 ) ;
if ( V_24 != 0 ) {
return V_24 ;
}
V_31 = V_22 -> V_25 . V_20 + V_22 -> V_25 . V_26 ;
V_32 = V_5 -> V_8 -> V_33 ;
* V_26 = V_32 < V_31 ? V_31 - V_32 : 0 ;
return 0 ;
}
static int F_21 ( struct V_4 * V_5 , int * V_29 )
{
struct V_21 * V_22 = & V_5 -> V_8 -> V_23 ;
int V_24 , V_34 , V_35 ;
V_24 = F_16 ( V_5 -> V_8 ) ;
if ( V_24 != 0 ) {
return V_24 ;
}
V_34 = V_22 -> V_25 . V_28 + V_22 -> V_25 . V_29 ;
V_35 = V_5 -> V_8 -> V_36 ;
* V_29 = V_35 < V_34 ? V_34 - V_35 : 0 ;
return 0 ;
}
static int F_22 ( struct V_4 * V_5 , int * V_2 )
{
struct V_21 * V_22 = & V_5 -> V_8 -> V_23 ;
int V_24 = F_16 ( V_5 -> V_8 ) ;
if ( V_24 != 0 ) {
return V_24 ;
}
* V_2 = V_22 -> V_25 . V_20 ;
return 0 ;
}
static int F_23 ( struct V_4 * V_5 , int * V_2 )
{
struct V_21 * V_22 = & V_5 -> V_8 -> V_23 ;
int V_24 = F_16 ( V_5 -> V_8 ) ;
if ( V_24 != 0 ) {
return V_24 ;
}
* V_2 = V_22 -> V_25 . V_28 ;
return 0 ;
}
static int F_24 ( struct V_4 * V_5 , int * V_2 )
{
struct V_21 * V_22 = & V_5 -> V_8 -> V_23 ;
int V_24 = F_16 ( V_5 -> V_8 ) ;
if ( V_24 != 0 ) {
return V_24 ;
}
* V_2 = V_22 -> V_25 . V_26 ;
return 0 ;
}
static int F_25 ( struct V_4 * V_5 , int * V_2 )
{
struct V_21 * V_22 = & V_5 -> V_8 -> V_23 ;
int V_24 = F_16 ( V_5 -> V_8 ) ;
if ( V_24 != 0 ) {
return V_24 ;
}
* V_2 = V_22 -> V_25 . V_29 ;
return 0 ;
}
static int F_26 ( struct V_4 * V_5 , int * V_2 )
{
struct V_21 * V_22 = & V_5 -> V_8 -> V_23 ;
int V_24 = F_16 ( V_5 -> V_8 ) ;
if ( V_24 != 0 ) {
return V_24 ;
}
* V_2 = V_22 -> V_37 . V_20 ;
return 0 ;
}
static int F_27 ( struct V_4 * V_5 , int * V_2 )
{
struct V_21 * V_22 = & V_5 -> V_8 -> V_23 ;
int V_24 = F_16 ( V_5 -> V_8 ) ;
if ( V_24 != 0 ) {
return V_24 ;
}
* V_2 = V_22 -> V_37 . V_28 ;
return 0 ;
}
static int F_28 ( struct V_4 * V_5 , int * V_2 )
{
struct V_21 * V_22 = & V_5 -> V_8 -> V_23 ;
int V_24 = F_16 ( V_5 -> V_8 ) ;
if ( V_24 != 0 ) {
return V_24 ;
}
* V_2 = V_22 -> V_37 . V_26 ;
return 0 ;
}
static int F_29 ( struct V_4 * V_5 , int * V_2 )
{
struct V_21 * V_22 = & V_5 -> V_8 -> V_23 ;
int V_24 = F_16 ( V_5 -> V_8 ) ;
if ( V_24 != 0 ) {
return V_24 ;
}
* V_2 = V_22 -> V_37 . V_29 ;
return 0 ;
}
static int F_30 ( struct V_4 * V_5 , int * V_2 )
{
struct V_21 * V_22 = & V_5 -> V_8 -> V_23 ;
int V_24 = F_16 ( V_5 -> V_8 ) ;
if ( V_24 != 0 ) {
return V_24 ;
}
* V_2 = V_22 -> V_38 . V_39 ;
return 0 ;
}
static int F_31 ( struct V_4 * V_5 , int * V_2 )
{
struct V_21 * V_22 = & V_5 -> V_8 -> V_23 ;
int V_24 = F_16 ( V_5 -> V_8 ) ;
if ( V_24 != 0 ) {
return V_24 ;
}
* V_2 = V_22 -> V_38 . V_40 ;
return 0 ;
}
static int F_32 ( struct V_4 * V_5 , int * V_6 )
{
if ( V_5 -> V_8 -> V_41 & V_42 ) {
* V_6 = 480 ;
} else {
* V_6 = 576 ;
}
return 0 ;
}
static int F_33 ( struct V_4 * V_5 , int * V_6 )
{
if ( V_5 -> V_8 -> V_43 -> V_44 ) {
* V_6 = 75 ;
} else {
* V_6 = 17 ;
}
return 0 ;
}
static int F_34 ( struct V_4 * V_5 , int * V_6 )
{
* V_6 = V_5 -> V_8 -> V_45 ;
return 0 ;
}
static int F_35 ( struct V_4 * V_5 , int V_13 )
{
return ( ( 1 << V_13 ) & V_5 -> V_8 -> V_46 ) != 0 ;
}
static int F_36 ( struct V_4 * V_5 , int V_12 , int V_13 )
{
return F_37 ( V_5 -> V_8 , V_13 ) ;
}
static int F_38 ( struct V_4 * V_5 )
{
return V_5 -> V_8 -> V_47 != 0 ;
}
static void F_39 ( struct V_4 * V_5 )
{
V_5 -> V_8 -> V_47 = 0 ;
}
static int F_40 ( struct V_4 * V_5 , int * V_6 )
{
unsigned long V_48 ;
struct V_7 * V_8 = V_5 -> V_8 ;
if ( V_8 -> V_49 ) {
F_41 ( V_8 ) ;
}
V_48 = V_8 -> V_50 . V_51 ;
if ( ! V_48 ) {
* V_6 = V_52 ;
return 0 ;
}
if ( V_8 -> V_50 . V_53 & V_54 ) {
V_48 = ( V_48 * 125 ) / 2 ;
} else {
V_48 = V_48 * 62500 ;
}
* V_6 = V_48 ;
return 0 ;
}
static int F_42 ( struct V_4 * V_5 , int * V_6 )
{
unsigned long V_48 ;
struct V_7 * V_8 = V_5 -> V_8 ;
if ( V_8 -> V_49 ) {
F_41 ( V_8 ) ;
}
V_48 = V_8 -> V_50 . V_55 ;
if ( ! V_48 ) {
* V_6 = V_56 ;
return 0 ;
}
if ( V_8 -> V_50 . V_53 & V_54 ) {
V_48 = ( V_48 * 125 ) / 2 ;
} else {
V_48 = V_48 * 62500 ;
}
* V_6 = V_48 ;
return 0 ;
}
static int F_43 ( struct V_4 * V_5 )
{
return V_5 -> V_8 -> V_57 != 0 ;
}
static void F_44 ( struct V_4 * V_5 )
{
V_5 -> V_8 -> V_57 = 0 ;
V_5 -> V_8 -> V_58 = 0 ;
}
static int F_45 ( struct V_4 * V_5 , int * V_6 )
{
int V_59 ;
struct V_60 V_61 ;
struct V_62 V_63 ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
memset ( & V_63 , 0 , sizeof( V_63 ) ) ;
V_61 . V_64 = & V_63 ;
V_61 . V_65 = 1 ;
V_63 . V_66 = V_5 -> V_67 -> V_68 ;
V_59 = F_46 ( & V_5 -> V_8 -> V_69 , 0 , & V_61 ,
V_70 ) ;
if ( V_59 ) return V_59 ;
* V_6 = V_63 . V_71 ;
return 0 ;
}
static int F_47 ( struct V_4 * V_5 , int V_12 , int V_13 )
{
int V_59 ;
struct V_7 * V_8 = V_5 -> V_8 ;
struct V_60 V_61 ;
struct V_62 V_63 ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
memset ( & V_63 , 0 , sizeof( V_63 ) ) ;
V_61 . V_64 = & V_63 ;
V_61 . V_65 = 1 ;
V_63 . V_66 = V_5 -> V_67 -> V_68 ;
V_63 . V_71 = V_13 ;
V_59 = F_46 ( & V_8 -> V_69 ,
V_8 -> V_72 , & V_61 ,
V_73 ) ;
if ( V_59 == - V_74 ) {
V_59 = F_46 ( & V_8 -> V_69 ,
0 , & V_61 ,
V_73 ) ;
if ( ! V_59 ) V_8 -> V_58 = ! 0 ;
}
if ( V_59 ) return V_59 ;
V_8 -> V_57 = ! 0 ;
return 0 ;
}
static unsigned int F_48 ( struct V_4 * V_5 )
{
struct V_75 V_76 ;
struct V_77 * V_67 ;
V_76 . V_66 = V_5 -> V_67 -> V_68 ;
F_49 ( & V_5 -> V_8 -> V_69 , & V_76 ) ;
V_67 = (struct V_77 * ) ( V_5 -> V_67 ) ;
if ( V_76 . V_78 & V_79 ) {
if ( V_67 -> V_80 ) {
V_67 -> V_80 = NULL ;
}
} else {
if ( ! ( V_67 -> V_80 ) ) {
V_67 -> V_80 = F_47 ;
}
}
return V_76 . V_78 ;
}
static int F_50 ( struct V_4 * V_5 , int * V_6 )
{
* V_6 = V_5 -> V_8 -> V_81 ;
return 0 ;
}
static int F_51 ( struct V_4 * V_5 , int * V_6 )
{
* V_6 = V_5 -> V_8 -> V_82 ;
return 0 ;
}
static int F_52 ( struct V_4 * V_5 , int * V_6 )
{
int V_83 = F_53 ( V_5 -> V_8 ) ;
* V_6 = V_84 ;
if ( V_83 < 0 ) * V_6 = V_85 ;
if ( V_83 ) * V_6 = V_86 ;
return 0 ;
}
static int F_54 ( struct V_4 * V_5 , int * V_6 )
{
* V_6 = F_55 ( V_5 -> V_8 ) ;
return 0 ;
}
static int F_56 ( struct V_4 * V_5 , int * V_6 )
{
* V_6 = V_5 -> V_8 -> V_87 ;
return 0 ;
}
static int F_57 ( struct V_4 * V_5 , int V_12 , int V_13 )
{
struct V_7 * V_8 = V_5 -> V_8 ;
T_1 V_88 ;
V_88 = V_8 -> V_87 ;
V_88 = ( V_88 & ~ V_12 ) | ( V_13 & V_12 ) ;
if ( V_88 == V_8 -> V_87 ) return 0 ;
V_8 -> V_87 = V_88 ;
V_8 -> V_89 . V_90 . V_91 . V_92 = V_8 -> V_87 ;
return 0 ;
}
static int F_58 ( struct V_4 * V_5 , int V_93 , int V_2 ,
char * V_94 , unsigned int V_95 ,
unsigned int * V_96 )
{
* V_96 = F_59 ( V_94 , V_95 , V_93 & V_2 ) ;
return 0 ;
}
static int F_60 ( struct V_4 * V_5 ,
const char * V_94 , unsigned int V_95 ,
int * V_97 , int * V_98 )
{
int V_59 ;
T_1 V_66 ;
V_59 = F_61 ( & V_66 , V_94 , V_95 ) ;
if ( V_59 < 0 ) return V_59 ;
if ( V_97 ) * V_97 = V_66 ;
if ( V_98 ) * V_98 = V_66 ;
return 0 ;
}
static int F_62 ( struct V_4 * V_5 , int * V_6 )
{
* V_6 = V_5 -> V_8 -> V_41 ;
return 0 ;
}
static int F_63 ( struct V_4 * V_5 , int V_12 , int V_13 )
{
struct V_7 * V_8 = V_5 -> V_8 ;
T_1 V_88 ;
V_88 = V_8 -> V_41 ;
V_88 = ( V_88 & ~ V_12 ) | ( V_13 & V_12 ) ;
if ( V_88 == V_8 -> V_41 ) return 0 ;
V_8 -> V_41 = V_88 ;
V_8 -> V_99 = ! 0 ;
return 0 ;
}
static int F_64 ( struct V_4 * V_5 )
{
return V_5 -> V_8 -> V_99 != 0 ;
}
static void F_65 ( struct V_4 * V_5 )
{
V_5 -> V_8 -> V_99 = 0 ;
}
static int F_66 ( struct V_4 * V_5 , int * V_6 )
{
struct V_7 * V_8 = V_5 -> V_8 ;
F_41 ( V_8 ) ;
* V_6 = V_8 -> V_50 . signal ;
return 0 ;
}
static int F_67 ( struct V_4 * V_5 , int * V_6 )
{
int V_2 = 0 ;
unsigned int V_100 ;
struct V_7 * V_8 = V_5 -> V_8 ;
F_41 ( V_8 ) ;
V_100 = V_8 -> V_50 . V_101 ;
if ( V_100 & V_102 ) {
V_2 |= ( 1 << V_103 ) ;
}
if ( V_100 & V_104 ) {
V_2 |= ( 1 << V_105 ) ;
}
if ( V_100 & V_106 ) {
V_2 |= ( 1 << V_107 ) ;
}
if ( V_100 & V_108 ) {
V_2 |= ( 1 << V_109 ) ;
}
* V_6 = V_2 ;
return 0 ;
}
const char * F_68 ( enum V_110 V_111 )
{
switch ( V_111 ) {
case V_112 : return L_4 ;
case V_113 : return L_5 ;
case V_114 : return L_6 ;
case V_115 : return L_7 ;
case V_116 : return L_8 ;
}
return L_9 ;
}
struct V_117 * F_69 ( struct V_7 * V_8 )
{
return V_8 -> V_118 ;
}
unsigned long F_70 ( struct V_7 * V_8 )
{
return V_8 -> V_119 ;
}
const char * F_71 ( struct V_7 * V_8 )
{
return V_8 -> V_120 ;
}
const char * F_72 ( struct V_7 * V_8 )
{
return V_8 -> V_121 ;
}
unsigned long F_11 ( struct V_7 * V_8 )
{
return V_8 -> V_15 ? V_8 -> V_122 : V_8 -> V_123 ;
}
static void F_9 ( struct V_7 * V_8 , unsigned long V_2 )
{
if ( V_8 -> V_45 == V_124 ) {
if ( V_8 -> V_15 ) {
V_8 -> V_15 = 0 ;
V_8 -> V_19 = ! 0 ;
}
if ( V_8 -> V_123 != V_2 ) {
V_8 -> V_123 = V_2 ;
V_8 -> V_16 = 0 ;
V_8 -> V_19 = ! 0 ;
}
} else {
if ( ! ( V_8 -> V_15 ) ) {
V_8 -> V_15 = 1 ;
V_8 -> V_19 = ! 0 ;
}
if ( V_8 -> V_122 != V_2 ) {
V_8 -> V_122 = V_2 ;
V_8 -> V_17 = 0 ;
V_8 -> V_19 = ! 0 ;
}
}
}
int F_73 ( struct V_7 * V_8 )
{
return V_8 -> V_125 ;
}
static int F_74 ( struct V_7 * V_8 ,
const struct V_126 * * V_127 ,
const char * V_128 ,
unsigned int V_129 ,
const char * V_130 [] )
{
unsigned int V_131 ;
int V_59 = - V_132 ;
for ( V_131 = 0 ; V_131 < V_129 ; V_131 ++ ) {
V_59 = F_75 ( V_127 ,
V_130 [ V_131 ] ,
& V_8 -> V_118 -> V_133 ) ;
if ( ! V_59 ) {
F_76 ( L_10
L_11 ,
V_128 ,
V_130 [ V_131 ] ) ;
return V_131 ;
}
if ( V_59 == - V_134 ) continue;
F_2 ( V_135 ,
L_12 , V_59 ) ;
return V_59 ;
}
F_2 ( V_135 ,
L_13
L_14
L_15 ,
V_128 ) ;
F_2 ( V_135 ,
L_16
L_17 ) ;
if ( V_129 == 1 ) {
F_2 ( V_135 ,
L_18 ,
V_128 , V_130 [ 0 ] ) ;
} else {
F_2 ( V_135 ,
L_19
L_20 ,
V_128 ) ;
for ( V_131 = 0 ; V_131 < V_129 ; V_131 ++ ) {
F_2 ( V_135 ,
L_21 ,
V_130 [ V_131 ] ) ;
}
}
return V_59 ;
}
static int F_77 ( struct V_7 * V_8 )
{
const struct V_126 * V_127 = NULL ;
void * V_136 ;
unsigned int V_137 ;
unsigned int V_138 ;
int V_59 ;
T_2 V_139 ;
if ( ! V_8 -> V_43 -> V_140 . V_141 ) {
V_8 -> V_142 = V_143 ;
F_2 ( V_135 ,
L_22
L_23 ) ;
return - V_144 ;
}
V_8 -> V_142 = V_145 ;
F_76 ( L_24 ) ;
V_59 = F_74 ( V_8 , & V_127 , L_25 ,
V_8 -> V_43 -> V_140 . V_141 ,
V_8 -> V_43 -> V_140 . V_146 ) ;
if ( V_59 < 0 ) {
if ( V_59 == - V_134 ) V_8 -> V_142 = V_147 ;
return V_59 ;
}
F_78 ( V_8 -> V_118 , F_79 ( V_8 -> V_118 , 0 & 0x7f ) ) ;
V_137 = F_80 ( V_8 -> V_118 , 0 ) ;
V_138 = V_127 -> V_148 ;
if ( ( V_138 != 0x2000 ) &&
( ! ( V_8 -> V_43 -> V_149 && ( V_138 == 0x4000 ) ) ) ) {
if ( V_8 -> V_43 -> V_149 ) {
F_2 ( V_135 ,
L_26
L_27 ,
V_138 ) ;
} else {
F_2 ( V_135 ,
L_26
L_28 ,
V_138 ) ;
}
F_81 ( V_127 ) ;
return - V_150 ;
}
V_136 = F_82 ( 0x800 , V_151 ) ;
if ( V_136 == NULL ) {
F_81 ( V_127 ) ;
return - V_150 ;
}
F_83 ( V_8 , 1 ) ;
V_59 = 0 ;
for ( V_139 = 0 ; V_139 < V_138 ; V_139 += 0x800 ) {
memcpy ( V_136 , V_127 -> V_152 + V_139 , 0x800 ) ;
V_59 += F_84 ( V_8 -> V_118 , V_137 , 0xa0 , 0x40 , V_139 ,
0 , V_136 , 0x800 , V_153 ) ;
}
F_76 ( L_29 ) ;
F_83 ( V_8 , 0 ) ;
F_85 ( V_136 ) ;
F_81 ( V_127 ) ;
F_76 ( L_30 , V_59 ) ;
if ( V_59 == V_138 ) {
V_8 -> V_142 = V_154 ;
return 0 ;
}
return - V_155 ;
}
int F_86 ( struct V_7 * V_8 )
{
const struct V_126 * V_127 = NULL ;
void * V_136 ;
unsigned int V_137 , V_156 , V_157 , V_158 , V_159 ;
int V_160 ;
int V_59 = 0 ;
int V_161 ;
static const char * V_162 [] = {
V_163 ,
} ;
if ( V_8 -> V_43 -> V_164 ) {
return 0 ;
}
F_76 ( L_31 ) ;
V_59 = F_74 ( V_8 , & V_127 , L_32 ,
F_87 ( V_162 ) , V_162 ) ;
if ( V_59 < 0 ) return V_59 ;
V_161 = V_59 ;
V_59 = 0 ;
V_8 -> V_165 = 0 ;
F_88 ( & V_8 -> V_166 ) ;
if ( V_8 -> V_167 ) {
V_8 -> V_167 = 0 ;
F_1 ( L_33 , V_8 -> V_167 ) ;
}
V_59 |= F_89 ( V_8 , 0x0048 , 0xffffffff ) ;
V_59 |= F_90 ( V_8 , 0xffffffff , 0x00000088 ) ;
V_59 |= F_91 ( V_8 , 0xffffffff , 0x00000008 ) ;
V_59 |= F_92 ( V_8 ) ;
V_59 |= F_89 ( V_8 , 0xa064 , 0x00000000 ) ;
V_59 |= F_90 ( V_8 , 0xffffffff , 0x00000408 ) ;
V_59 |= F_91 ( V_8 , 0xffffffff , 0x00000008 ) ;
V_59 |= F_89 ( V_8 , 0x9058 , 0xffffffed ) ;
V_59 |= F_89 ( V_8 , 0x9054 , 0xfffffffd ) ;
V_59 |= F_89 ( V_8 , 0x07f8 , 0x80000800 ) ;
V_59 |= F_89 ( V_8 , 0x07fc , 0x0000001a ) ;
V_59 |= F_89 ( V_8 , 0x0700 , 0x00000000 ) ;
V_59 |= F_89 ( V_8 , 0xaa00 , 0x00000000 ) ;
V_59 |= F_89 ( V_8 , 0xaa04 , 0x00057810 ) ;
V_59 |= F_89 ( V_8 , 0xaa10 , 0x00148500 ) ;
V_59 |= F_89 ( V_8 , 0xaa18 , 0x00840000 ) ;
V_59 |= F_93 ( V_8 , V_168 ) ;
V_59 |= F_93 ( V_8 , V_169 | ( 1 << 8 ) | ( 0 << 16 ) ) ;
if ( V_59 ) {
F_2 ( V_135 ,
L_34 , V_59 ) ;
F_81 ( V_127 ) ;
goto V_170;
}
V_156 = V_127 -> V_148 ;
if ( V_156 % sizeof( V_171 ) ) {
F_2 ( V_135 ,
L_35
L_36 ,
V_162 [ V_161 ] , sizeof( V_171 ) ) ;
F_81 ( V_127 ) ;
V_59 = - V_132 ;
goto V_170;
}
V_136 = F_82 ( V_172 , V_151 ) ;
if ( V_136 == NULL ) {
F_81 ( V_127 ) ;
F_2 ( V_135 ,
L_37 ) ;
V_59 = - V_150 ;
goto V_170;
}
V_137 = F_79 ( V_8 -> V_118 , V_173 ) ;
V_157 = 0 ;
for ( V_157 = 0 ; V_157 < V_156 ; ) {
V_158 = V_156 - V_157 ;
if ( V_158 > V_172 ) V_158 = V_172 ;
memcpy ( V_136 , V_127 -> V_152 + V_157 , V_158 ) ;
for ( V_159 = 0 ; V_159 < V_158 / 4 ; V_159 ++ )
( ( V_171 * ) V_136 ) [ V_159 ] = F_94 ( ( ( V_171 * ) V_136 ) [ V_159 ] ) ;
V_59 |= F_95 ( V_8 -> V_118 , V_137 , V_136 , V_158 ,
& V_160 , V_153 ) ;
V_59 |= ( V_160 != V_158 ) ;
if ( V_59 ) break;
V_157 += V_158 ;
}
F_76 ( L_38 ,
V_162 [ V_161 ] , V_157 , V_156 ) ;
F_85 ( V_136 ) ;
F_81 ( V_127 ) ;
if ( V_59 ) {
F_2 ( V_135 ,
L_39 ) ;
goto V_170;
}
V_59 |= F_89 ( V_8 , 0x9054 , 0xffffffff ) ;
V_59 |= F_89 ( V_8 , 0x9058 , 0xffffffe8 ) ;
V_59 |= F_93 ( V_8 , V_169 | ( 1 << 8 ) | ( 0 << 16 ) ) ;
if ( V_59 ) {
F_2 ( V_135 ,
L_40 ) ;
}
V_170:
if ( V_8 -> V_43 -> V_174 ==
V_175 ) {
F_90 ( V_8 , ( 1 << 11 ) , ~ 0 ) ;
}
return V_59 ;
}
static const char * F_96 ( unsigned int V_176 )
{
if ( V_176 < F_87 ( V_177 ) ) {
return V_177 [ V_176 ] ;
}
return L_41 ;
}
static int F_97 ( struct V_7 * V_8 , int V_178 )
{
F_2 ( V_179 , L_42 ,
( V_178 ? L_43 : L_44 ) ) ;
F_98 ( & V_8 -> V_180 , 0 , V_181 , V_182 , V_178 ) ;
F_98 ( & V_8 -> V_180 , 0 , V_183 , V_182 , V_178 ) ;
if ( V_8 -> V_184 ) {
return 0 ;
}
if ( ! V_8 -> V_185 ) {
F_2 ( V_135 ,
L_45 ) ;
V_8 -> V_185 = ! 0 ;
F_1 ( L_46 ,
V_8 -> V_185 ) ;
}
return - V_155 ;
}
int F_99 ( struct V_7 * V_8 )
{
return V_8 -> V_82 ;
}
static int F_100 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_186 ) return 0 ;
V_8 -> V_186 = 0 ;
F_2 ( V_135 ,
L_47 ) ;
return ! 0 ;
}
int F_101 ( struct V_7 * V_8 )
{
int V_187 ;
F_102 ( V_8 -> V_188 ) ; do {
V_187 = F_100 ( V_8 ) ;
} while ( 0 ); F_103 ( V_8 -> V_188 ) ;
if ( V_187 ) F_104 ( V_8 ) ;
return 0 ;
}
int F_105 ( struct V_7 * V_8 )
{
return V_8 -> V_81 != 0 ;
}
int F_106 ( struct V_7 * V_8 , int V_189 )
{
int V_59 , V_176 ;
F_102 ( V_8 -> V_188 ) ; do {
F_100 ( V_8 ) ;
if ( ( ! V_189 ) != ! ( V_8 -> V_81 ) ) {
V_8 -> V_81 = V_189 != 0 ;
F_2 ( V_190 ,
L_48 ,
V_189 ? L_49 : L_50 ) ;
}
F_104 ( V_8 ) ;
} while ( 0 ); F_103 ( V_8 -> V_188 ) ;
if ( ( V_59 = F_107 ( V_8 , 0 ) ) < 0 ) return V_59 ;
if ( V_189 ) {
while ( ( V_176 = V_8 -> V_82 ) != V_191 ) {
if ( V_176 != V_192 ) return - V_155 ;
if ( ( V_59 = F_107 ( V_8 , V_176 ) ) < 0 ) return V_59 ;
}
}
return 0 ;
}
int F_108 ( struct V_7 * V_8 , enum V_110 V_193 )
{
int V_187 ;
F_102 ( V_8 -> V_188 ) ;
if ( ( V_187 = ( V_8 -> V_194 != V_193 ) ) != 0 ) {
V_8 -> V_194 = V_193 ;
V_8 -> V_195 = 0 ;
F_1 ( L_51 ,
V_8 -> V_195 ) ;
F_104 ( V_8 ) ;
}
F_103 ( V_8 -> V_188 ) ;
if ( V_187 ) return 0 ;
return F_107 ( V_8 , 0 ) ;
}
static int F_109 ( struct V_7 * V_8 )
{
int V_125 = V_8 -> V_125 ;
int V_196 = - 1 ;
if ( ( V_125 >= 0 ) && ( V_125 < V_197 ) ) {
V_196 = V_198 [ V_125 ] ;
}
if ( V_196 < 0 ) return - V_132 ;
V_8 -> V_199 = V_196 ;
V_8 -> V_200 = ! 0 ;
return 0 ;
}
static T_1 F_110 ( struct V_7 * V_8 )
{
int V_125 = V_8 -> V_125 ;
int V_196 = 0 ;
if ( ( V_125 >= 0 ) && ( V_125 < V_197 ) ) {
V_196 = V_201 [ V_125 ] ;
if ( V_196 ) return V_196 ;
}
return 0 ;
}
static unsigned int F_111 ( struct V_7 * V_8 )
{
int V_125 = V_8 -> V_125 ;
int V_196 = 0 ;
if ( ( V_125 >= 0 ) && ( V_125 < V_197 ) ) {
V_196 = V_202 [ V_125 ] ;
}
return V_196 ;
}
static int F_112 ( struct V_7 * V_8 )
{
int V_83 ;
F_102 ( V_8 -> V_203 ) ; do {
V_8 -> V_204 [ 0 ] = V_205 ;
V_83 = F_113 ( V_8 , V_153 * 1 , ! 0 ,
V_8 -> V_204 , 1 ,
V_8 -> V_204 , 1 ) ;
if ( V_83 < 0 ) break;
} while( 0 ); F_103 ( V_8 -> V_203 ) ;
if ( V_83 ) {
F_2 ( V_206 ,
L_52 ,
V_83 ) ;
} else {
F_2 ( V_206 ,
L_53 ) ;
}
return V_83 == 0 ;
}
static void F_114 ( struct V_7 * V_8 )
{
char V_207 [ 40 ] ;
unsigned int V_158 ;
T_1 V_208 , V_209 , V_210 ;
V_208 = F_110 ( V_8 ) ;
V_210 = V_208 ? 0 : V_8 -> V_43 -> V_211 ;
V_158 = F_59 ( V_207 , sizeof( V_207 ) , V_8 -> V_212 ) ;
F_2 ( V_213 ,
L_54
L_55 ,
V_158 , V_207 ) ;
V_8 -> V_87 = V_8 -> V_212 ;
V_209 = ( V_208 | V_210 ) & ~ V_8 -> V_87 ;
if ( V_209 ) {
V_158 = F_59 ( V_207 , sizeof( V_207 ) , V_209 ) ;
F_2 ( V_213 ,
L_56
L_57 ,
V_158 , V_207 ) ;
V_8 -> V_87 |= V_209 ;
}
V_8 -> V_89 . V_90 . V_91 . V_92 = V_8 -> V_87 ;
if ( V_208 ) {
V_158 = F_59 ( V_207 , sizeof( V_207 ) , V_208 ) ;
F_2 ( V_213 ,
L_58 ,
V_158 , V_207 ) ;
V_8 -> V_41 = V_208 ;
V_8 -> V_99 = ! 0 ;
return;
}
if ( V_210 ) {
V_158 = F_59 ( V_207 , sizeof( V_207 ) , V_210 ) ;
F_2 ( V_213 ,
L_59
L_60 , V_158 , V_207 ) ;
V_8 -> V_41 = V_210 ;
V_8 -> V_99 = ! 0 ;
return;
}
{
unsigned int V_131 ;
for ( V_131 = 0 ; V_131 < F_87 ( V_214 ) ; V_131 ++ ) {
if ( V_214 [ V_131 ] . V_93 ?
( ( V_214 [ V_131 ] . V_215 ^
V_8 -> V_212 ) &
V_214 [ V_131 ] . V_93 ) :
( V_214 [ V_131 ] . V_215 !=
V_8 -> V_212 ) ) continue;
V_158 = F_59 ( V_207 , sizeof( V_207 ) ,
V_214 [ V_131 ] . V_216 ) ;
F_2 ( V_213 ,
L_61 ,
V_158 , V_207 ) ;
V_8 -> V_41 = V_214 [ V_131 ] . V_216 ;
V_8 -> V_99 = ! 0 ;
return;
}
}
}
static unsigned int F_115 (
unsigned short * V_217 , const unsigned char * V_218 ,
unsigned int V_219 )
{
unsigned int V_141 = 0 ;
if ( ! V_218 ) return 0 ;
while ( V_218 [ V_141 ] && ( V_141 + 1 ) < V_219 ) {
V_217 [ V_141 ] = V_218 [ V_141 ] ;
V_141 ++ ;
}
V_217 [ V_141 ] = V_220 ;
return V_141 ;
}
static void F_116 ( struct V_7 * V_8 )
{
struct V_221 V_222 ;
if ( V_8 -> V_184 != V_223 ) {
return;
}
F_2 ( V_206 ,
L_62
L_63 ,
V_8 -> V_184 ) ;
memset ( & V_222 , 0 , sizeof( V_222 ) ) ;
V_222 . type = V_224 ;
V_222 . V_222 . V_225 . V_226 [ 0 ] [ 21 ] = V_227 ;
V_222 . V_222 . V_225 . V_226 [ 1 ] [ 21 ] = V_227 ;
F_98 ( & V_8 -> V_180 , V_8 -> V_184 ,
V_228 , V_229 , & V_222 . V_222 . V_225 ) ;
}
static int F_117 ( struct V_7 * V_8 ,
const struct V_230 * V_231 )
{
const char * V_232 ;
unsigned char V_233 ;
struct V_234 * V_235 ;
unsigned int V_236 ;
const unsigned char * V_237 ;
unsigned short V_238 [ 25 ] ;
V_233 = V_231 -> V_239 ;
V_232 = ( V_233 < F_87 ( V_240 ) ) ? V_240 [ V_233 ] : NULL ;
if ( ! V_232 ) {
F_2 ( V_135 ,
L_64
L_65 ,
V_233 ,
V_8 -> V_43 -> V_241 ) ;
return - V_132 ;
}
F_2 ( V_206 ,
L_66 ,
V_233 , V_232 ,
V_8 -> V_43 -> V_241 ) ;
V_236 = F_115 ( V_238 , V_231 -> V_242 ,
F_87 ( V_238 ) ) ;
if ( ! V_236 && ( ( V_237 = ( V_233 < F_87 ( V_243 ) ) ?
V_243 [ V_233 ] : NULL ) != NULL ) ) {
V_236 = F_115 ( V_238 , V_237 ,
F_87 ( V_238 ) ) ;
if ( V_236 ) {
F_2 ( V_206 ,
L_62
L_67 ,
V_233 ) ;
}
}
if ( ! V_236 ) {
F_2 ( V_135 ,
L_68
L_69
L_65 ,
V_233 , V_232 , V_8 -> V_43 -> V_241 ) ;
return - V_132 ;
}
if ( V_236 == 1 ) {
F_2 ( V_206 ,
L_62
L_70 ,
V_233 , V_238 [ 0 ] ) ;
V_235 = F_118 ( & V_8 -> V_180 , & V_8 -> V_244 ,
V_232 , V_238 [ 0 ] , NULL ) ;
} else {
F_2 ( V_206 ,
L_62
L_71 ,
V_233 ) ;
V_235 = F_118 ( & V_8 -> V_180 , & V_8 -> V_244 ,
V_232 , 0 , V_238 ) ;
}
if ( ! V_235 ) {
F_2 ( V_135 ,
L_72
L_73
L_74 ,
V_233 , V_232 , V_8 -> V_43 -> V_241 ) ;
return - V_155 ;
}
V_235 -> V_245 = V_233 ;
F_2 ( V_246 , L_75 , V_232 ) ;
switch ( V_233 ) {
case V_223 :
case V_247 :
V_8 -> V_184 = V_233 ;
break;
default: break;
}
return 0 ;
}
static void F_119 ( struct V_7 * V_8 )
{
unsigned int V_131 ;
const struct V_248 * V_249 ;
const struct V_250 * V_251 ;
int V_252 = ! 0 ;
V_249 = & V_8 -> V_43 -> V_253 ;
for ( V_131 = 0 ; V_131 < V_249 -> V_141 ; V_131 ++ ) {
F_120 ( V_249 -> V_146 [ V_131 ] ) ;
}
V_251 = & V_8 -> V_43 -> V_254 ;
for ( V_131 = 0 ; V_131 < V_251 -> V_141 ; V_131 ++ ) {
if ( F_117 ( V_8 , & V_251 -> V_146 [ V_131 ] ) < 0 ) V_252 = 0 ;
}
if ( ! V_252 ) {
V_8 -> V_255 = ! 0 ;
F_121 ( V_8 ) ;
}
}
static void F_122 ( struct V_7 * V_8 )
{
int V_59 ;
unsigned int V_131 ;
struct V_4 * V_5 ;
int V_256 = 0 ;
if ( V_8 -> V_43 -> V_140 . V_141 ) {
if ( ! V_256 ) {
V_256 =
( V_8 -> V_257 -> V_258 -> V_259 . V_260
== 0 ) ;
if ( V_256 ) {
F_2 ( V_206 ,
L_76
L_77
L_78 ) ;
}
}
if ( ! V_256 ) {
V_256 = ! F_112 ( V_8 ) ;
if ( V_256 ) {
F_2 ( V_206 ,
L_79
L_77
L_78 ) ;
}
}
if ( V_256 ) {
if ( F_77 ( V_8 ) != 0 ) {
F_2 ( V_135 ,
L_80 ) ;
}
return;
}
}
V_8 -> V_142 = V_143 ;
if ( ! F_123 ( V_8 ) ) return;
V_8 -> V_261 = ! 0 ;
if ( ! V_8 -> V_43 -> V_262 ) {
F_124 ( V_8 ) ;
if ( ! F_123 ( V_8 ) ) return;
}
if ( V_8 -> V_263 == V_264 ) {
F_93 ( V_8 ,
V_265 |
( 1 << 8 ) |
( ( 0 ) << 16 ) ) ;
}
F_125 ( V_8 ) ;
if ( ! F_123 ( V_8 ) ) return;
F_119 ( V_8 ) ;
if ( ! F_123 ( V_8 ) ) return;
F_98 ( & V_8 -> V_180 , 0 , V_266 , V_267 ) ;
for ( V_131 = 0 ; V_131 < V_268 ; V_131 ++ ) {
V_5 = V_8 -> V_64 + V_131 ;
if ( V_5 -> V_67 -> V_269 ) continue;
if ( ! V_5 -> V_67 -> V_80 ) continue;
V_5 -> V_67 -> V_80 ( V_5 , ~ 0 , V_5 -> V_67 -> V_270 ) ;
}
F_116 ( V_8 ) ;
V_8 -> V_122 = V_271 ;
V_8 -> V_123 = V_272 ;
if ( V_8 -> V_43 -> V_273 ) {
V_59 = F_126 ( V_8 ) ;
if ( ! F_123 ( V_8 ) ) return;
if ( V_59 < 0 ) {
F_2 ( V_135 ,
L_81
L_82 ) ;
} else {
V_8 -> V_274 = V_59 ;
F_127 ( V_8 ) ;
if ( ! F_123 ( V_8 ) ) return;
}
} else {
V_8 -> V_199 = V_8 -> V_43 -> V_275 ;
V_8 -> V_200 = ! 0 ;
V_8 -> V_212 = V_276 ;
}
if ( V_8 -> V_119 ) {
V_131 = F_128 ( V_8 -> V_121 , sizeof( V_8 -> V_121 ) - 1 ,
L_83 , V_8 -> V_119 ) ;
} else if ( V_8 -> V_125 >= 0 ) {
V_131 = F_128 ( V_8 -> V_121 , sizeof( V_8 -> V_121 ) - 1 ,
L_84 ,
V_8 -> V_125 + 'a' ) ;
} else {
V_131 = F_128 ( V_8 -> V_121 , sizeof( V_8 -> V_121 ) - 1 ,
L_85 ) ;
}
V_8 -> V_121 [ V_131 ] = 0 ;
F_114 ( V_8 ) ;
if ( ! F_109 ( V_8 ) ) {
F_2 ( V_206 ,
L_86 ,
V_8 -> V_199 ) ;
}
if ( ! F_123 ( V_8 ) ) return;
if ( V_8 -> V_43 -> V_174 ==
V_175 ) {
F_90 ( V_8 , ( 1 << 11 ) , ~ 0 ) ;
}
F_129 ( V_8 ) ;
V_8 -> V_277 = F_130 () ;
if ( ! F_123 ( V_8 ) ) return;
F_2 ( V_206 ,
L_87 , V_8 -> V_277 ) ;
if ( V_8 -> V_277 ) {
V_131 = F_111 ( V_8 ) ;
if ( V_131 ) {
F_2 ( V_206 ,
L_88
L_89 ,
V_8 -> V_277 , V_131 ) ;
}
F_131 ( V_8 -> V_277 , V_8 -> V_118 ,
V_278 , V_131 ) ;
}
if ( ! F_123 ( V_8 ) ) return;
V_8 -> V_279 = ! 0 ;
F_104 ( V_8 ) ;
}
static void F_132 ( struct V_7 * V_8 )
{
F_2 ( V_206 , L_90 , V_8 ) ;
do {
F_122 ( V_8 ) ;
F_2 ( V_206 ,
L_91 ,
V_8 , F_123 ( V_8 ) , V_8 -> V_279 ) ;
if ( F_123 ( V_8 ) ) {
if ( V_8 -> V_279 ) {
F_2 (
V_246 ,
L_92
L_93 ) ;
break;
}
if ( V_8 -> V_142 == V_154 ) {
F_2 (
V_246 ,
L_94
L_95
L_96 ) ;
break;
}
F_2 (
V_135 ,
L_97 ) ;
if ( V_8 -> V_142 == V_147 ) {
F_2 (
V_135 ,
L_98
L_99
L_100 ) ;
break;
}
}
if ( V_8 -> V_255 ) {
F_2 (
V_135 ,
L_101
L_102
L_103 ) ;
F_2 (
V_135 ,
L_104
L_105
L_106
L_107 ) ;
break;
}
if ( V_280 ) {
F_2 (
V_135 ,
L_108
L_109 ) ;
F_2 (
V_135 ,
L_110
L_111 ) ;
V_8 -> V_142 = V_281 ;
F_77 ( V_8 ) ;
} else {
F_2 (
V_135 ,
L_112
L_113
L_114 ) ;
F_2 (
V_135 ,
L_115
L_116
L_117 ) ;
}
} while ( 0 );
F_2 ( V_206 , L_118 , V_8 ) ;
}
int F_133 ( struct V_7 * V_8 ,
void (* F_134)( void * ) ,
void * V_282 )
{
F_102 ( V_8 -> V_188 ) ; do {
if ( V_8 -> V_283 ) {
break;
}
V_8 -> V_284 = V_282 ;
V_8 -> V_285 = F_134 ;
F_132 ( V_8 ) ;
} while ( 0 ); F_103 ( V_8 -> V_188 ) ;
return V_8 -> V_279 ;
}
struct V_7 * F_135 ( struct V_286 * V_287 ,
const struct V_288 * V_289 )
{
unsigned int V_131 , V_290 , V_291 , V_12 ;
struct V_7 * V_8 = NULL ;
int V_292 ;
struct V_4 * V_5 ;
struct V_117 * V_118 ;
const struct V_293 * V_43 ;
T_3 V_294 ;
struct V_75 V_76 ;
struct V_77 * V_295 ;
V_118 = F_136 ( V_287 ) ;
V_43 = ( const struct V_293 * ) ( V_289 -> V_296 ) ;
if ( V_43 == NULL ) {
F_2 ( V_206 , L_119
L_120
L_121 ) ;
F_2 ( V_206 , L_122
L_123
L_124 ) ;
goto V_297;
}
V_8 = F_137 ( sizeof( * V_8 ) , V_151 ) ;
F_2 ( V_206 , L_125 ,
V_8 , V_43 -> V_241 ) ;
F_2 ( V_246 , L_126 ,
V_43 -> V_241 ) ;
if ( V_43 -> V_298 ) {
F_2 ( V_246 , L_127 ) ;
F_2 ( V_246 ,
L_128
L_129 , V_43 -> V_241 ) ;
F_2 ( V_246 ,
L_130
L_131 ) ;
F_2 ( V_246 ,
L_132
L_133 ) ;
F_2 ( V_246 , L_127 ) ;
}
if ( ! V_8 ) goto V_297;
F_138 ( & V_8 -> V_299 , V_300 ,
( unsigned long ) V_8 ) ;
F_138 ( & V_8 -> V_301 ,
V_302 ,
( unsigned long ) V_8 ) ;
F_138 ( & V_8 -> V_303 , V_304 ,
( unsigned long ) V_8 ) ;
F_138 ( & V_8 -> V_166 , V_305 ,
( unsigned long ) V_8 ) ;
V_8 -> V_82 = V_306 ;
F_139 ( & V_8 -> V_307 ) ;
V_8 -> V_49 = ! 0 ;
F_140 ( & V_8 -> V_69 ) ;
V_12 = 0 ;
if ( V_43 -> V_308 ) V_12 |= 1 << V_309 ;
if ( V_43 -> V_310 != V_311 ) {
V_12 |= 1 << V_312 ;
}
if ( V_43 -> V_313 ) V_12 |= 1 << V_314 ;
if ( V_43 -> V_315 ) V_12 |= 1 << V_316 ;
if ( V_43 -> V_317 ) V_12 |= 1 << V_124 ;
V_8 -> V_318 = V_12 ;
V_8 -> V_46 = V_8 -> V_318 ;
if ( ! ( V_8 -> V_318 & ( 1 << V_312 ) ) ) {
V_8 -> V_319 = V_320 ;
} else if ( ! ( V_8 -> V_318 & ( 1 << V_309 ) ) ) {
V_8 -> V_319 = V_321 ;
}
V_8 -> V_322 = V_268 ;
V_8 -> V_322 += V_323 ;
V_8 -> V_64 = F_137 ( sizeof( struct V_4 ) * V_8 -> V_322 ,
V_151 ) ;
if ( ! V_8 -> V_64 ) goto V_297;
V_8 -> V_43 = V_43 ;
V_8 -> V_263 = V_8 -> V_43 -> V_324 ;
for ( V_131 = 0 ; V_131 < V_8 -> V_322 ; V_131 ++ ) {
V_5 = V_8 -> V_64 + V_131 ;
V_5 -> V_8 = V_8 ;
}
for ( V_131 = 0 ; V_131 < 32 ; V_131 ++ ) {
V_8 -> V_325 [ V_131 ] = V_8 -> V_326 [ V_131 ] ;
}
for ( V_131 = 0 ; V_131 < V_268 ; V_131 ++ ) {
V_5 = V_8 -> V_64 + V_131 ;
V_5 -> V_67 = V_327 + V_131 ;
}
V_12 = V_8 -> V_318 ;
if ( V_12 ) for ( V_131 = 0 ; V_131 < ( sizeof( V_12 ) << 3 ) ; V_131 ++ ) {
if ( ! ( ( 1 << V_131 ) & V_12 ) ) continue;
V_8 -> V_45 = V_131 ;
break;
}
V_8 -> V_328 = F_141 ( V_323 ,
sizeof( * ( V_8 -> V_328 ) ) ,
V_151 ) ;
if ( ! V_8 -> V_328 ) goto V_297;
for ( V_131 = 0 ; V_131 < V_323 ; V_131 ++ ) {
V_5 = V_8 -> V_64 + V_131 + V_268 ;
V_295 = & ( V_8 -> V_328 [ V_131 ] . V_67 ) ;
V_295 -> V_259 = V_8 -> V_328 [ V_131 ] . V_259 ;
V_295 -> V_1 = V_329 [ V_131 ] . V_330 ;
V_295 -> V_68 = V_329 [ V_131 ] . V_66 ;
V_295 -> V_269 = ! 0 ;
V_295 -> V_331 = F_45 ;
V_295 -> V_332 = F_48 ;
V_295 -> V_333 = F_43 ;
if ( ! V_131 ) V_295 -> V_334 = F_44 ;
V_76 . V_66 = V_295 -> V_68 ;
F_49 ( & V_8 -> V_69 , & V_76 ) ;
if ( ! ( V_76 . V_78 & V_79 ) ) {
V_295 -> V_80 = F_47 ;
}
strncpy ( V_8 -> V_328 [ V_131 ] . V_259 , V_76 . V_1 ,
V_335 ) ;
V_8 -> V_328 [ V_131 ] . V_259 [ V_335 - 1 ] = 0 ;
V_295 -> V_270 = V_76 . V_270 ;
switch ( V_76 . type ) {
default:
case V_336 :
V_295 -> type = V_337 ;
V_295 -> V_90 . V_338 . V_339 = V_76 . V_340 ;
V_295 -> V_90 . V_338 . V_341 = V_76 . V_342 ;
break;
case V_343 :
V_295 -> type = V_344 ;
break;
case V_345 :
V_295 -> type = V_346 ;
V_295 -> V_90 . V_347 . V_348 =
F_142 ( & V_8 -> V_69 ,
V_295 -> V_68 ) ;
for ( V_290 = 0 ;
V_295 -> V_90 . V_347 . V_348 [ V_290 ] != NULL ;
V_290 ++ ) { }
V_295 -> V_90 . V_347 . V_65 = V_290 ;
break;
}
V_5 -> V_67 = V_295 ;
}
V_292 = F_143 () ;
for ( V_131 = 0 ; V_131 < 32 ; V_131 ++ ) {
if ( ! ( V_292 & ( 1 << V_131 ) ) ) continue;
V_290 = F_59 (
V_8 -> V_326 [ V_131 ] ,
sizeof( V_8 -> V_326 [ V_131 ] ) - 1 ,
1 << V_131 ) ;
V_8 -> V_326 [ V_131 ] [ V_290 ] = 0 ;
}
V_5 = F_144 ( V_8 , V_349 ) ;
if ( V_5 ) {
memcpy ( & V_8 -> V_350 , V_5 -> V_67 ,
sizeof( V_8 -> V_350 ) ) ;
V_5 -> V_67 = & V_8 -> V_350 ;
V_8 -> V_350 . V_90 . V_91 . V_351 =
V_8 -> V_325 ;
V_8 -> V_350 . V_90 . V_91 . V_92 =
V_292 ;
}
V_5 = F_144 ( V_8 , V_352 ) ;
if ( V_5 ) {
memcpy ( & V_8 -> V_89 , V_5 -> V_67 ,
sizeof( V_8 -> V_89 ) ) ;
V_5 -> V_67 = & V_8 -> V_89 ;
V_8 -> V_89 . V_90 . V_91 . V_351 =
V_8 -> V_325 ;
V_8 -> V_89 . V_90 . V_91 . V_92 =
V_292 ;
}
V_5 = F_144 ( V_8 , V_353 ) ;
if ( V_5 ) {
memcpy ( & V_8 -> V_354 , V_5 -> V_67 ,
sizeof( V_8 -> V_354 ) ) ;
V_5 -> V_67 = & V_8 -> V_354 ;
V_8 -> V_354 . V_90 . V_91 . V_351 =
V_8 -> V_325 ;
V_8 -> V_354 . V_90 . V_91 . V_92 =
V_292 ;
}
V_8 -> V_355 = ! 0 ;
V_8 -> V_274 = - 1 ;
V_8 -> V_125 = - 1 ;
V_8 -> V_356 = - 1 ;
V_8 -> V_357 = - 1 ;
V_8 -> V_358 = - 1 ;
V_8 -> V_359 = F_82 ( V_360 , V_151 ) ;
if ( ! V_8 -> V_359 ) goto V_297;
V_8 -> V_361 = F_82 ( V_360 , V_151 ) ;
if ( ! V_8 -> V_361 ) goto V_297;
V_8 -> V_362 = F_145 ( 0 , V_151 ) ;
if ( ! V_8 -> V_362 ) goto V_297;
V_8 -> V_363 = F_145 ( 0 , V_151 ) ;
if ( ! V_8 -> V_363 ) goto V_297;
if ( F_146 ( & V_287 -> V_133 , & V_8 -> V_180 ) != 0 ) {
F_2 ( V_135 ,
L_134 ) ;
goto V_297;
}
F_147 ( & V_364 ) ;
do {
for ( V_131 = 0 ; V_131 < V_197 ; V_131 ++ ) {
if ( V_365 [ V_131 ] ) continue;
V_8 -> V_125 = V_131 ;
V_365 [ V_131 ] = V_8 ;
break;
}
} while ( 0 );
F_148 ( & V_364 ) ;
V_290 = 0 ;
V_291 = F_128 ( V_8 -> V_1 + V_290 , sizeof( V_8 -> V_1 ) - V_290 , L_135 ) ;
V_290 += V_291 ;
if ( V_8 -> V_125 >= 0 ) {
V_291 = F_128 ( V_8 -> V_1 + V_290 , sizeof( V_8 -> V_1 ) - V_290 , L_136 ,
( 'a' + V_8 -> V_125 ) ) ;
V_290 += V_291 ;
}
if ( V_290 >= sizeof( V_8 -> V_1 ) ) V_290 = sizeof( V_8 -> V_1 ) - 1 ;
V_8 -> V_1 [ V_290 ] = 0 ;
V_8 -> V_366 = F_149 ( V_8 -> V_1 ) ;
F_150 ( & V_8 -> V_367 , V_368 ) ;
F_2 ( V_206 , L_137 ,
V_8 -> V_125 , V_8 -> V_1 ) ;
V_8 -> V_199 = - 1 ;
V_8 -> V_369 = ! 0 ;
V_8 -> V_257 = V_287 ;
V_8 -> V_118 = V_118 ;
F_151 ( V_8 -> V_118 , V_8 -> V_120 , sizeof( V_8 -> V_120 ) ) ;
V_294 = V_8 -> V_257 -> V_258 -> V_259 . V_370 ;
F_152 ( V_8 -> V_118 , V_294 , 0 ) ;
F_153 ( & V_8 -> V_371 ) ;
F_153 ( & V_8 -> V_372 ) ;
return V_8 ;
V_297:
if ( V_8 ) {
F_88 ( & V_8 -> V_299 ) ;
F_88 ( & V_8 -> V_301 ) ;
F_88 ( & V_8 -> V_166 ) ;
F_88 ( & V_8 -> V_303 ) ;
if ( V_8 -> V_366 ) {
F_154 ( V_8 -> V_366 ) ;
F_155 ( V_8 -> V_366 ) ;
V_8 -> V_366 = NULL ;
}
F_156 ( V_8 -> V_363 ) ;
F_156 ( V_8 -> V_362 ) ;
F_85 ( V_8 -> V_361 ) ;
F_85 ( V_8 -> V_359 ) ;
F_85 ( V_8 -> V_64 ) ;
F_85 ( V_8 -> V_328 ) ;
F_85 ( V_8 ) ;
}
return NULL ;
}
static void F_157 ( struct V_7 * V_8 )
{
if ( V_8 -> V_283 ) return;
F_2 ( V_206 , L_138 , V_8 ) ;
if ( V_8 -> V_363 ) {
F_158 ( V_8 -> V_363 ) ;
F_156 ( V_8 -> V_363 ) ;
V_8 -> V_363 = NULL ;
}
if ( V_8 -> V_362 ) {
F_158 ( V_8 -> V_362 ) ;
F_156 ( V_8 -> V_362 ) ;
V_8 -> V_362 = NULL ;
}
if ( V_8 -> V_361 ) {
F_85 ( V_8 -> V_361 ) ;
V_8 -> V_361 = NULL ;
}
if ( V_8 -> V_359 ) {
F_85 ( V_8 -> V_359 ) ;
V_8 -> V_359 = NULL ;
}
V_8 -> V_283 = ! 0 ;
F_159 ( & V_8 -> V_180 ) ;
V_8 -> V_118 = NULL ;
V_8 -> V_257 = NULL ;
F_121 ( V_8 ) ;
}
void F_160 ( struct V_7 * V_8 , struct V_373 * V_374 )
{
V_374 -> V_180 = & V_8 -> V_180 ;
}
void F_161 ( struct V_7 * V_8 )
{
if ( ! V_8 ) return;
F_2 ( V_206 , L_139 , V_8 ) ;
if ( V_8 -> V_366 ) {
F_154 ( V_8 -> V_366 ) ;
F_155 ( V_8 -> V_366 ) ;
V_8 -> V_366 = NULL ;
}
F_88 ( & V_8 -> V_299 ) ;
F_88 ( & V_8 -> V_301 ) ;
F_88 ( & V_8 -> V_166 ) ;
F_88 ( & V_8 -> V_303 ) ;
if ( V_8 -> V_375 ) {
F_85 ( V_8 -> V_375 ) ;
V_8 -> V_375 = NULL ;
}
if ( V_8 -> V_277 ) {
F_162 ( V_8 -> V_277 ) ;
V_8 -> V_277 = NULL ;
}
F_163 ( V_8 ) ;
F_164 ( & V_8 -> V_180 ) ;
F_157 ( V_8 ) ;
F_147 ( & V_364 ) ;
do {
if ( ( V_8 -> V_125 >= 0 ) &&
( V_8 -> V_125 < V_197 ) &&
( V_365 [ V_8 -> V_125 ] == V_8 ) ) {
V_365 [ V_8 -> V_125 ] = NULL ;
}
} while ( 0 );
F_148 ( & V_364 ) ;
F_85 ( V_8 -> V_64 ) ;
F_85 ( V_8 -> V_328 ) ;
F_85 ( V_8 ) ;
}
int F_123 ( struct V_7 * V_8 )
{
return ( V_8 && V_8 -> V_369 ) ;
}
void F_165 ( struct V_7 * V_8 )
{
F_2 ( V_206 , L_140 , V_8 ) ;
F_102 ( V_8 -> V_188 ) ;
F_102 ( V_8 -> V_203 ) ;
F_157 ( V_8 ) ;
F_103 ( V_8 -> V_203 ) ;
F_103 ( V_8 -> V_188 ) ;
}
unsigned int F_166 ( struct V_7 * V_8 )
{
return V_8 -> V_322 ;
}
struct V_4 * F_167 ( struct V_7 * V_8 ,
unsigned int V_131 )
{
if ( V_131 >= V_8 -> V_322 ) return NULL ;
return V_8 -> V_64 + V_131 ;
}
struct V_4 * F_144 ( struct V_7 * V_8 ,
unsigned int V_376 )
{
struct V_4 * V_5 ;
unsigned int V_131 ;
int V_377 ;
for ( V_131 = 0 ; V_131 < V_8 -> V_322 ; V_131 ++ ) {
V_5 = V_8 -> V_64 + V_131 ;
V_377 = V_5 -> V_67 -> V_378 ;
if ( V_377 && ( V_377 == V_376 ) ) return V_5 ;
}
return NULL ;
}
struct V_4 * F_168 ( struct V_7 * V_8 , unsigned int V_376 )
{
struct V_4 * V_5 ;
unsigned int V_131 ;
int V_377 ;
for ( V_131 = 0 ; V_131 < V_8 -> V_322 ; V_131 ++ ) {
V_5 = V_8 -> V_64 + V_131 ;
V_377 = V_5 -> V_67 -> V_68 ;
if ( V_377 && ( V_377 == V_376 ) ) return V_5 ;
}
return NULL ;
}
struct V_4 * F_169 ( struct V_7 * V_8 ,
unsigned int V_376 )
{
struct V_4 * V_5 , * V_379 ;
unsigned int V_131 ;
int V_377 ;
V_379 = NULL ;
for ( V_131 = 0 ; V_131 < V_8 -> V_322 ; V_131 ++ ) {
V_5 = V_8 -> V_64 + V_131 ;
V_377 = V_5 -> V_67 -> V_68 ;
if ( ! V_377 ) continue;
if ( V_377 <= V_376 ) continue;
if ( V_379 && ( V_379 -> V_67 -> V_68 < V_377 ) ) continue;
V_379 = V_5 ;
}
return V_379 ;
return NULL ;
}
static const char * F_170 ( enum V_380 V_196 )
{
switch ( V_196 ) {
case V_337 : return L_141 ;
case V_346 : return L_142 ;
case V_344 : return L_143 ;
case V_381 : return L_144 ;
}
return L_145 ;
}
static void F_171 ( struct V_7 * V_8 , int V_66 ,
const char * V_1 , int V_2 )
{
struct V_382 V_383 ;
F_2 ( V_179 , L_146 , V_1 , V_2 ) ;
memset ( & V_383 , 0 , sizeof( V_383 ) ) ;
V_383 . V_66 = V_66 ;
V_383 . V_71 = V_2 ;
F_98 ( & V_8 -> V_180 , 0 , V_266 , V_384 , & V_383 ) ;
}
static T_1 F_55 ( struct V_7 * V_8 )
{
T_1 V_216 ;
V_216 = ( T_1 ) V_8 -> V_87 ;
F_98 ( & V_8 -> V_180 , 0 ,
V_181 , V_385 , & V_216 ) ;
return V_216 ;
}
static void F_172 ( struct V_7 * V_8 )
{
struct V_234 * V_235 ;
unsigned int V_66 ;
T_4 V_386 ;
F_2 ( V_179 , L_147 ) ;
if ( V_8 -> V_200 || V_8 -> V_261 ) {
struct V_387 V_388 ;
F_2 ( V_179 , L_148 ,
V_8 -> V_199 ) ;
if ( ( ( int ) ( V_8 -> V_199 ) ) >= 0 ) {
memset ( & V_388 , 0 , sizeof( V_388 ) ) ;
V_388 . V_389 = V_390 ;
V_388 . type = V_8 -> V_199 ;
V_388 . V_391 = V_392 | V_393 ;
F_98 ( & V_8 -> V_180 , 0 ,
V_198 , V_394 , & V_388 ) ;
}
}
if ( V_8 -> V_47 || V_8 -> V_99 || V_8 -> V_261 ) {
F_2 ( V_179 , L_149 ) ;
if ( V_8 -> V_45 == V_124 ) {
F_98 ( & V_8 -> V_180 , 0 ,
V_198 , V_395 ) ;
} else {
T_1 V_396 ;
V_396 = V_8 -> V_41 ;
F_98 ( & V_8 -> V_180 , 0 ,
V_181 , V_397 , V_396 ) ;
F_116 ( V_8 ) ;
}
V_8 -> V_49 = ! 0 ;
V_8 -> V_355 = ! 0 ;
}
F_173 ( V_8 , V_398 , V_399 ) ;
F_173 ( V_8 , V_400 , V_401 ) ;
F_173 ( V_8 , V_402 , V_403 ) ;
F_173 ( V_8 , V_404 , V_405 ) ;
F_173 ( V_8 , V_406 , V_407 ) ;
F_173 ( V_8 , V_408 , V_409 ) ;
F_173 ( V_8 , V_410 , V_411 ) ;
F_173 ( V_8 , V_412 , V_413 ) ;
F_173 ( V_8 , V_414 , V_415 ) ;
if ( V_8 -> V_47 || V_8 -> V_416 || V_8 -> V_261 ) {
struct V_417 V_418 ;
memset ( & V_418 , 0 , sizeof( V_418 ) ) ;
V_418 . type = ( V_8 -> V_45 == V_124 ) ?
V_419 : V_420 ;
V_418 . V_421 = V_8 -> V_422 ;
F_98 ( & V_8 -> V_180 , 0 , V_198 , V_423 , & V_418 ) ;
}
if ( V_8 -> V_19 || V_8 -> V_261 ) {
unsigned long V_48 ;
struct V_424 V_18 ;
V_48 = F_11 ( V_8 ) ;
F_2 ( V_179 , L_150 , V_48 ) ;
if ( V_8 -> V_49 ) F_41 ( V_8 ) ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
if ( V_8 -> V_50 . V_53 & V_54 ) {
V_18 . V_425 = ( V_48 * 2 ) / 125 ;
} else {
V_18 . V_425 = V_48 / 62500 ;
}
if ( V_8 -> V_45 == V_124 ) {
V_18 . type = V_419 ;
} else {
V_18 . type = V_420 ;
}
V_18 . V_198 = 0 ;
F_98 ( & V_8 -> V_180 , 0 , V_198 ,
V_426 , & V_18 ) ;
}
if ( V_8 -> V_427 || V_8 -> V_428 || V_8 -> V_261 ) {
struct V_429 V_430 = {
. V_431 = V_432 ,
} ;
V_430 . V_430 . V_26 = V_8 -> V_433 ;
V_430 . V_430 . V_29 = V_8 -> V_434 ;
V_430 . V_430 . V_435 = V_436 ;
F_2 ( V_179 , L_151 ,
V_430 . V_430 . V_26 , V_430 . V_430 . V_29 ) ;
F_98 ( & V_8 -> V_180 , 0 , V_437 , V_438 ,
NULL , & V_430 ) ;
}
if ( V_8 -> V_439 || V_8 -> V_261 ) {
V_171 V_2 ;
F_2 ( V_179 , L_152 ,
V_8 -> V_440 ) ;
switch ( V_8 -> V_440 ) {
default:
case V_441 :
V_2 = 48000 ;
break;
case V_442 :
V_2 = 44100 ;
break;
case V_443 :
V_2 = 32000 ;
break;
}
F_98 ( & V_8 -> V_180 , 0 ,
V_183 , V_444 , V_2 ) ;
}
F_174 (sd, &hdw->v4l2_dev) {
V_66 = V_235 -> V_245 ;
if ( V_66 >= F_87 ( V_445 ) ) continue;
V_386 = V_445 [ V_66 ] ;
if ( ! V_386 ) continue;
(* V_386)( V_8 , V_235 ) ;
}
if ( V_8 -> V_49 || V_8 -> V_355 ) {
F_41 ( V_8 ) ;
}
}
static int F_129 ( struct V_7 * V_8 )
{
unsigned int V_131 ;
struct V_4 * V_5 ;
int V_71 ;
int V_446 = V_8 -> V_261 ;
char V_207 [ 100 ] ;
unsigned int V_158 , V_447 ;
for ( V_131 = 0 ; V_131 < V_8 -> V_322 ; V_131 ++ ) {
V_5 = V_8 -> V_64 + V_131 ;
if ( ! V_5 -> V_67 -> V_333 ) continue;
if ( ! V_5 -> V_67 -> V_333 ( V_5 ) ) continue;
V_446 = ! 0 ;
if ( ! ( V_448 & V_449 ) ) continue;
V_158 = F_128 ( V_207 , sizeof( V_207 ) , L_153 ,
V_5 -> V_67 -> V_1 ) ;
V_71 = 0 ;
V_5 -> V_67 -> V_331 ( V_5 , & V_71 ) ;
F_175 ( V_5 , ~ 0 , V_71 ,
V_207 + V_158 ,
sizeof( V_207 ) - V_158 , & V_447 ) ;
V_158 += V_447 ;
V_158 += F_128 ( V_207 + V_158 , sizeof( V_207 ) - V_158 , L_154 ,
F_170 ( V_5 -> V_67 -> type ) ) ;
F_2 ( V_449 ,
L_155 ,
V_158 , V_207 ) ;
}
if ( ! V_446 ) {
return 0 ;
}
V_8 -> V_195 = 0 ;
F_1 ( L_51 , V_8 -> V_195 ) ;
F_104 ( V_8 ) ;
return ! 0 ;
}
static int F_176 ( struct V_7 * V_8 )
{
unsigned int V_131 ;
struct V_4 * V_5 ;
int V_450 ;
if ( V_8 -> V_47 && V_8 -> V_451 &&
( ( ( V_8 -> V_45 == V_312 ) ?
V_321 : V_320 ) !=
V_8 -> V_319 ) ) {
V_8 -> V_451 = 0 ;
F_1 ( L_156 , V_8 -> V_451 ) ;
}
if ( ! V_8 -> V_451 ) {
return 0 ;
}
if ( V_8 -> V_99 ) {
int V_452 ;
int V_453 ;
if ( V_8 -> V_41 & V_42 ) {
V_452 = 480 ;
V_453 = 15 ;
} else {
V_452 = 576 ;
V_453 = 12 ;
}
if ( V_452 != V_8 -> V_434 ) {
V_8 -> V_434 = V_452 ;
V_8 -> V_428 = ! 0 ;
}
if ( V_453 != V_8 -> V_69 . V_454 ) {
struct V_60 V_61 ;
struct V_62 V_63 ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
memset ( & V_63 , 0 , sizeof( V_63 ) ) ;
V_61 . V_64 = & V_63 ;
V_61 . V_65 = 1 ;
V_63 . V_66 = V_455 ;
V_63 . V_71 = V_453 ;
F_46 ( & V_8 -> V_69 , 0 , & V_61 ,
V_73 ) ;
}
}
if ( V_8 -> V_427 && V_8 -> V_27 < V_8 -> V_433 ) {
V_8 -> V_27 = V_8 -> V_433 ;
V_8 -> V_456 = ! 0 ;
} else if ( V_8 -> V_456 ) {
V_8 -> V_427 = ! 0 ;
V_8 -> V_433 = F_177 ( 720 , V_8 -> V_27 ) ;
}
if ( V_8 -> V_428 && V_8 -> V_30 < V_8 -> V_434 ) {
V_8 -> V_30 = V_8 -> V_434 ;
V_8 -> V_457 = ! 0 ;
} else if ( V_8 -> V_457 ) {
int V_452 = V_8 -> V_41 & V_42 ? 480 : 576 ;
V_8 -> V_428 = ! 0 ;
V_8 -> V_434 = F_177 ( V_452 , V_8 -> V_30 ) ;
}
V_450 =
( V_8 -> V_99 ||
V_8 -> V_58 ||
V_8 -> V_439 ||
V_8 -> V_428 ||
V_8 -> V_427 ||
V_8 -> V_456 ||
V_8 -> V_457 ||
V_8 -> V_47 ||
( V_8 -> V_458 != V_8 -> V_194 ) ) ;
if ( V_450 && ! V_8 -> V_459 ) {
V_8 -> V_460 = ! 0 ;
return 0 ;
}
if ( V_8 -> V_439 ) {
struct V_60 V_61 ;
struct V_62 V_63 ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
memset ( & V_63 , 0 , sizeof( V_63 ) ) ;
V_61 . V_64 = & V_63 ;
V_61 . V_65 = 1 ;
V_63 . V_66 = V_461 ;
V_63 . V_71 = V_8 -> V_440 ;
F_46 ( & V_8 -> V_69 , 0 , & V_61 , V_73 ) ;
}
if ( V_8 -> V_458 != V_8 -> V_194 ) {
V_8 -> V_458 = V_8 -> V_194 ;
}
if ( V_8 -> V_43 -> V_174 ==
V_175 ) {
V_171 V_462 ;
F_178 ( V_8 , & V_462 ) ;
if ( V_8 -> V_45 == V_124 ) {
F_91 ( V_8 , ( 1 << 11 ) , ~ 0 ) ;
} else {
F_91 ( V_8 , ( 1 << 11 ) , 0 ) ;
}
}
F_172 ( V_8 ) ;
V_8 -> V_200 = 0 ;
V_8 -> V_261 = 0 ;
for ( V_131 = 0 ; V_131 < V_8 -> V_322 ; V_131 ++ ) {
V_5 = V_8 -> V_64 + V_131 ;
if ( ! V_5 -> V_67 -> V_334 ) continue;
V_5 -> V_67 -> V_334 ( V_5 ) ;
}
if ( ( V_8 -> V_319 == V_320 ) &&
V_8 -> V_72 ) {
if ( F_179 ( V_8 ) < 0 ) return ! 0 ;
}
V_8 -> V_195 = ! 0 ;
F_1 ( L_51 , V_8 -> V_195 ) ;
return ! 0 ;
}
int F_180 ( struct V_7 * V_8 )
{
int V_187 ;
F_102 ( V_8 -> V_188 ) ;
V_187 = F_129 ( V_8 ) ;
F_103 ( V_8 -> V_188 ) ;
if ( ! V_187 ) return 0 ;
return F_107 ( V_8 , 0 ) ;
}
static void V_368 ( struct V_463 * V_464 )
{
int V_187 = 0 ;
struct V_7 * V_8 = F_181 ( V_464 , struct V_7 , V_367 ) ;
F_102 ( V_8 -> V_188 ) ; do {
V_187 = F_182 ( V_8 ) ;
} while ( 0 ); F_103 ( V_8 -> V_188 ) ;
if ( V_187 && V_8 -> V_285 ) {
V_8 -> V_285 ( V_8 -> V_284 ) ;
}
}
static int F_107 ( struct V_7 * V_8 , int V_465 )
{
return F_183 (
V_8 -> V_307 ,
( V_8 -> V_466 == 0 ) &&
( ! V_465 || ( V_8 -> V_82 != V_465 ) ) ) ;
}
const char * F_184 ( struct V_7 * V_8 )
{
return V_8 -> V_1 ;
}
const char * F_185 ( struct V_7 * V_8 )
{
return V_8 -> V_43 -> V_241 ;
}
const char * F_186 ( struct V_7 * V_8 )
{
return V_8 -> V_43 -> V_467 ;
}
int F_53 ( struct V_7 * V_8 )
{
int V_83 ;
F_102 ( V_8 -> V_203 ) ; do {
V_8 -> V_204 [ 0 ] = V_468 ;
V_83 = F_187 ( V_8 ,
V_8 -> V_204 , 1 ,
V_8 -> V_204 , 1 ) ;
if ( V_83 < 0 ) break;
V_83 = ( V_8 -> V_204 [ 0 ] != 0 ) ;
} while( 0 ); F_103 ( V_8 -> V_203 ) ;
return V_83 ;
}
void F_188 ( struct V_7 * V_8 )
{
F_102 ( V_8 -> V_188 ) ; do {
F_41 ( V_8 ) ;
} while ( 0 ); F_103 ( V_8 -> V_188 ) ;
}
static int F_16 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_355 ) {
return 0 ;
}
F_41 ( V_8 ) ;
if ( V_8 -> V_355 ) {
return - V_155 ;
}
return 0 ;
}
int F_189 ( struct V_7 * V_8 , struct V_21 * V_469 )
{
int V_24 = 0 ;
F_102 ( V_8 -> V_188 ) ;
V_24 = F_16 ( V_8 ) ;
if ( ! V_24 ) {
memcpy ( V_469 , & V_8 -> V_23 , sizeof( V_8 -> V_23 ) ) ;
}
F_103 ( V_8 -> V_188 ) ;
return V_24 ;
}
int F_190 ( struct V_7 * V_8 , struct V_417 * V_470 )
{
F_102 ( V_8 -> V_188 ) ; do {
if ( V_8 -> V_49 ) {
F_41 ( V_8 ) ;
}
memcpy ( V_470 , & V_8 -> V_50 , sizeof( struct V_417 ) ) ;
} while ( 0 ); F_103 ( V_8 -> V_188 ) ;
return 0 ;
}
struct V_471 * F_191 ( struct V_7 * V_472 )
{
return V_472 -> V_277 ;
}
void F_192 ( struct V_7 * V_8 )
{
int V_473 = F_73 ( V_8 ) ;
F_102 ( V_8 -> V_188 ) ;
do {
F_193 ( V_474 L_157 , V_473 ) ;
F_98 ( & V_8 -> V_180 , 0 , V_266 , V_475 ) ;
F_2 ( V_246 , L_158 ) ;
F_194 ( & V_8 -> V_69 , L_135 ) ;
F_195 ( V_8 ) ;
F_193 ( V_474 L_159 , V_473 ) ;
} while ( 0 );
F_103 ( V_8 -> V_188 ) ;
}
static T_5 * F_196 ( struct V_7 * V_8 )
{
struct V_476 V_477 [ 2 ] ;
T_5 * V_478 ;
T_5 V_479 [ 2 ] ;
T_5 V_389 ;
T_2 V_480 ;
unsigned int V_481 ;
int V_59 ;
int V_482 = 0 ;
unsigned V_483 , V_484 ;
V_478 = F_82 ( V_485 , V_151 ) ;
if ( ! V_478 ) {
F_2 ( V_135 ,
L_160
L_161 ) ;
return NULL ;
}
F_197 ( L_162 ,
V_8 -> V_274 ) ;
V_389 = V_8 -> V_274 ;
if ( V_389 & 0x80 ) V_389 >>= 1 ;
V_482 = ( V_389 & 1 ) ;
V_480 = ( V_482 ? V_485 : 256 ) ;
F_197 ( L_163
L_164 , V_480 , V_389 ,
V_482 ? 16 : 8 ) ;
V_477 [ 0 ] . V_389 = V_389 ;
V_477 [ 0 ] . V_78 = 0 ;
V_477 [ 0 ] . V_96 = V_482 ? 2 : 1 ;
V_477 [ 0 ] . V_207 = V_479 ;
V_477 [ 1 ] . V_389 = V_389 ;
V_477 [ 1 ] . V_78 = V_486 ;
memset ( V_478 , 0 , V_485 ) ;
for ( V_484 = 0 ; V_484 < V_485 ; V_484 += V_483 ) {
V_483 = 16 ;
if ( V_483 + V_484 > V_485 ) V_483 = V_485 - V_484 ;
V_481 = V_484 + ( V_480 - V_485 ) ;
if ( V_482 ) {
V_479 [ 0 ] = V_481 >> 8 ;
V_479 [ 1 ] = V_481 ;
} else {
V_479 [ 0 ] = V_481 ;
}
V_477 [ 1 ] . V_96 = V_483 ;
V_477 [ 1 ] . V_207 = V_478 + V_484 ;
if ( ( V_59 = F_198 ( & V_8 -> V_244 ,
V_477 , F_87 ( V_477 ) ) ) != 2 ) {
F_2 ( V_135 ,
L_165 , V_59 ) ;
F_85 ( V_478 ) ;
return NULL ;
}
}
return V_478 ;
}
void F_199 ( struct V_7 * V_8 ,
int V_487 ,
int V_189 )
{
int V_59 ;
T_2 V_139 ;
unsigned int V_137 ;
F_102 ( V_8 -> V_188 ) ; do {
if ( ( V_8 -> V_375 == NULL ) == ! V_189 ) break;
if ( ! V_189 ) {
F_2 ( V_488 ,
L_166 ) ;
F_85 ( V_8 -> V_375 ) ;
V_8 -> V_375 = NULL ;
V_8 -> V_489 = 0 ;
if ( V_8 -> V_490 ) {
F_83 ( V_8 , 0 ) ;
}
break;
}
V_8 -> V_490 = ( V_487 != 2 ) ;
if ( V_8 -> V_490 ) {
V_8 -> V_489 = ( V_487 == 1 ) ? 0x4000 : 0x2000 ;
F_2 ( V_488 ,
L_167
L_168 , V_8 -> V_489 ) ;
V_8 -> V_375 = F_137 ( V_8 -> V_489 , V_151 ) ;
if ( ! V_8 -> V_375 ) {
V_8 -> V_489 = 0 ;
break;
}
F_83 ( V_8 , 1 ) ;
F_2 ( V_488 ,
L_169 ) ;
V_137 = F_200 ( V_8 -> V_118 , 0 ) ;
for( V_139 = 0 ; V_139 < V_8 -> V_489 ;
V_139 += 0x800 ) {
V_59 = F_84 ( V_8 -> V_118 , V_137 ,
0xa0 , 0xc0 ,
V_139 , 0 ,
V_8 -> V_375 + V_139 ,
0x800 , V_153 ) ;
if ( V_59 < 0 ) break;
}
F_2 ( V_488 ,
L_170 ) ;
} else {
F_2 ( V_488 ,
L_171 ) ;
V_8 -> V_375 = F_196 ( V_8 ) ;
if ( ! V_8 -> V_375 ) {
F_2 ( V_488 ,
L_172 ) ;
break;
}
V_8 -> V_489 = V_485 ;
F_2 ( V_488 ,
L_173 ) ;
}
} while ( 0 ); F_103 ( V_8 -> V_188 ) ;
}
int F_201 ( struct V_7 * V_8 )
{
return V_8 -> V_375 != NULL ;
}
int F_202 ( struct V_7 * V_8 , unsigned int V_481 ,
char * V_207 , unsigned int V_141 )
{
int V_59 = - V_132 ;
F_102 ( V_8 -> V_188 ) ; do {
if ( ! V_207 ) break;
if ( ! V_141 ) break;
if ( ! V_8 -> V_375 ) {
V_59 = - V_155 ;
break;
}
if ( V_481 >= V_8 -> V_489 ) {
F_2 ( V_488 ,
L_174 ,
V_481 ) ;
V_59 = 0 ;
break;
}
if ( V_481 + V_141 > V_8 -> V_489 ) V_141 = V_8 -> V_489 - V_481 ;
memcpy ( V_207 , V_8 -> V_375 + V_481 , V_141 ) ;
F_2 ( V_488 ,
L_175 ,
V_481 , V_141 ) ;
V_59 = V_141 ;
} while ( 0 ); F_103 ( V_8 -> V_188 ) ;
return V_59 ;
}
int F_203 ( struct V_7 * V_8 ,
enum V_491 V_492 )
{
switch ( V_492 ) {
case V_493 : return V_8 -> V_356 ;
case V_494 : return V_8 -> V_357 ;
case V_495 : return V_8 -> V_358 ;
default: return - 1 ;
}
}
void F_204 ( struct V_7 * V_8 ,
enum V_491 V_492 , int V_13 )
{
switch ( V_492 ) {
case V_493 : V_8 -> V_356 = V_13 ; break;
case V_494 : V_8 -> V_357 = V_13 ; break;
case V_495 : V_8 -> V_358 = V_13 ; break;
default: break;
}
}
static void F_205 ( struct V_496 * V_496 )
{
struct V_7 * V_8 = V_496 -> V_497 ;
V_8 -> V_498 = 0 ;
if ( V_8 -> V_499 ) return;
F_206 ( & V_8 -> V_500 ) ;
}
static void F_207 ( struct V_496 * V_496 )
{
struct V_7 * V_8 = V_496 -> V_497 ;
V_8 -> V_499 = 0 ;
if ( V_8 -> V_498 ) return;
F_206 ( & V_8 -> V_500 ) ;
}
static void F_208 ( unsigned long V_152 )
{
struct V_7 * V_8 = (struct V_7 * ) V_152 ;
if ( V_8 -> V_498 || V_8 -> V_499 ) {
V_8 -> V_501 = ! 0 ;
if ( V_8 -> V_498 )
F_209 ( V_8 -> V_362 ) ;
if ( V_8 -> V_499 )
F_209 ( V_8 -> V_363 ) ;
}
}
static int F_113 ( struct V_7 * V_8 ,
unsigned int V_502 , int V_503 ,
void * V_504 , unsigned int V_505 ,
void * V_506 , unsigned int V_507 )
{
unsigned int V_131 ;
int V_508 = 0 ;
struct V_509 V_510 ;
if ( ! V_8 -> V_511 ) {
F_2 ( V_135 ,
L_176
L_177 ) ;
return - V_512 ;
}
if ( ! V_8 -> V_369 && ! V_503 ) {
F_2 ( V_135 ,
L_176
L_178 ) ;
return - V_155 ;
}
if ( ! ( V_8 -> V_363 && V_8 -> V_362 ) ) {
if ( ! V_503 ) {
F_2 ( V_135 ,
L_176
L_179 ) ;
}
return - V_144 ;
}
if ( ! V_504 ) V_505 = 0 ;
if ( ! V_506 ) V_507 = 0 ;
if ( V_505 > V_360 ) {
F_2 (
V_135 ,
L_180
L_181 ,
V_505 , V_360 ) ;
return - V_132 ;
}
if ( V_507 > V_360 ) {
F_2 (
V_135 ,
L_180
L_182 ,
V_505 , V_360 ) ;
return - V_132 ;
}
if ( ( ! V_505 ) && ( ! V_507 ) ) {
F_2 (
V_135 ,
L_183 ) ;
return - V_132 ;
}
V_8 -> V_513 = 1 ;
if ( V_505 ) {
V_8 -> V_514 = ( ( unsigned char * ) V_504 ) [ 0 ] ;
} else {
V_8 -> V_514 = 0 ;
}
V_8 -> V_515 = V_505 ;
V_8 -> V_516 = V_507 ;
F_210 ( & V_8 -> V_500 ) ;
V_8 -> V_501 = 0 ;
V_8 -> V_498 = 0 ;
V_8 -> V_499 = 0 ;
F_138 ( & V_510 , F_208 , ( unsigned long ) V_8 ) ;
V_510 . V_517 = V_518 + V_502 ;
if ( V_505 ) {
V_8 -> V_513 = 2 ;
for ( V_131 = 0 ; V_131 < V_505 ; V_131 ++ ) {
V_8 -> V_359 [ V_131 ] =
( ( unsigned char * ) V_504 ) [ V_131 ] ;
}
F_211 ( V_8 -> V_362 ,
V_8 -> V_118 ,
F_79 ( V_8 -> V_118 ,
V_519 ) ,
V_8 -> V_359 ,
V_505 ,
F_205 ,
V_8 ) ;
V_8 -> V_362 -> V_160 = 0 ;
V_8 -> V_498 = ! 0 ;
V_508 = F_212 ( V_8 -> V_362 , V_151 ) ;
if ( V_508 < 0 ) {
F_2 ( V_135 ,
L_184
L_185 , V_508 ) ;
V_8 -> V_498 = 0 ;
goto V_170;
}
}
if ( V_507 ) {
V_8 -> V_513 = 3 ;
memset ( V_8 -> V_361 , 0x43 , V_507 ) ;
F_211 ( V_8 -> V_363 ,
V_8 -> V_118 ,
F_213 ( V_8 -> V_118 ,
V_520 ) ,
V_8 -> V_361 ,
V_507 ,
F_207 ,
V_8 ) ;
V_8 -> V_363 -> V_160 = 0 ;
V_8 -> V_499 = ! 0 ;
V_508 = F_212 ( V_8 -> V_363 , V_151 ) ;
if ( V_508 < 0 ) {
F_2 ( V_135 ,
L_186
L_185 , V_508 ) ;
V_8 -> V_499 = 0 ;
goto V_170;
}
}
F_214 ( & V_510 ) ;
V_8 -> V_513 = 4 ;
while ( V_8 -> V_498 || V_8 -> V_499 ) {
F_215 ( & V_8 -> V_500 ) ;
}
V_8 -> V_513 = 5 ;
F_88 ( & V_510 ) ;
V_8 -> V_513 = 6 ;
V_508 = 0 ;
if ( V_8 -> V_501 ) {
V_508 = - V_521 ;
if ( ! V_503 ) {
F_2 ( V_135 ,
L_187 ) ;
}
goto V_170;
}
if ( V_505 ) {
if ( ( V_8 -> V_362 -> V_508 != 0 ) &&
( V_8 -> V_362 -> V_508 != - V_134 ) &&
( V_8 -> V_362 -> V_508 != - V_522 ) &&
( V_8 -> V_362 -> V_508 != - V_523 ) ) {
V_508 = V_8 -> V_362 -> V_508 ;
if ( ! V_503 ) {
F_2 ( V_135 ,
L_188
L_189 ,
V_508 ) ;
}
goto V_170;
}
if ( V_8 -> V_362 -> V_160 < V_505 ) {
V_508 = - V_155 ;
if ( ! V_503 ) {
F_2 ( V_135 ,
L_190
L_191 ,
V_505 ,
V_8 -> V_362 -> V_160 ) ;
}
goto V_170;
}
}
if ( V_507 ) {
if ( ( V_8 -> V_363 -> V_508 != 0 ) &&
( V_8 -> V_363 -> V_508 != - V_134 ) &&
( V_8 -> V_363 -> V_508 != - V_522 ) &&
( V_8 -> V_363 -> V_508 != - V_523 ) ) {
V_508 = V_8 -> V_363 -> V_508 ;
if ( ! V_503 ) {
F_2 ( V_135 ,
L_192
L_189 ,
V_508 ) ;
}
goto V_170;
}
if ( V_8 -> V_363 -> V_160 < V_507 ) {
V_508 = - V_155 ;
if ( ! V_503 ) {
F_2 ( V_135 ,
L_193
L_191 ,
V_507 ,
V_8 -> V_363 -> V_160 ) ;
}
goto V_170;
}
for ( V_131 = 0 ; V_131 < V_507 ; V_131 ++ ) {
( ( unsigned char * ) V_506 ) [ V_131 ] =
V_8 -> V_361 [ V_131 ] ;
}
}
V_170:
V_8 -> V_513 = 0 ;
if ( ( V_508 < 0 ) && ( ! V_503 ) ) {
F_121 ( V_8 ) ;
}
return V_508 ;
}
int F_187 ( struct V_7 * V_8 ,
void * V_504 , unsigned int V_505 ,
void * V_506 , unsigned int V_507 )
{
return F_113 ( V_8 , V_153 * 4 , 0 ,
V_504 , V_505 ,
V_506 , V_507 ) ;
}
static int F_93 ( struct V_7 * V_8 , V_171 V_524 )
{
int V_59 ;
unsigned int V_141 = 1 ;
unsigned int args = 0 ;
F_102 ( V_8 -> V_203 ) ;
V_8 -> V_204 [ 0 ] = V_524 & 0xffu ;
args = ( V_524 >> 8 ) & 0xffu ;
args = ( args > 2 ) ? 2 : args ;
if ( args ) {
V_141 += args ;
V_8 -> V_204 [ 1 ] = ( V_524 >> 16 ) & 0xffu ;
if ( args > 1 ) {
V_8 -> V_204 [ 2 ] = ( V_524 >> 24 ) & 0xffu ;
}
}
if ( V_448 & V_206 ) {
unsigned int V_131 ;
unsigned int V_447 , V_158 ;
char V_525 [ 50 ] ;
V_524 &= 0xffu ;
V_158 = 0 ;
V_447 = F_128 ( V_525 + V_158 ,
sizeof( V_525 ) - V_158 ,
L_194 , V_524 ) ;
V_158 += V_447 ;
for ( V_131 = 0 ; V_131 < F_87 ( V_526 ) ; V_131 ++ ) {
if ( V_526 [ V_131 ] . V_66 == V_524 ) {
V_447 = F_128 ( V_525 + V_158 ,
sizeof( V_525 ) - V_158 ,
L_195 ,
V_526 [ V_131 ] . V_259 ) ;
V_158 += V_447 ;
break;
}
}
if ( args ) {
V_447 = F_128 ( V_525 + V_158 ,
sizeof( V_525 ) - V_158 ,
L_196 , V_8 -> V_204 [ 1 ] ) ;
V_158 += V_447 ;
if ( args > 1 ) {
V_447 = F_128 ( V_525 + V_158 ,
sizeof( V_525 ) - V_158 ,
L_197 , V_8 -> V_204 [ 2 ] ) ;
V_158 += V_447 ;
}
V_447 = F_128 ( V_525 + V_158 ,
sizeof( V_525 ) - V_158 ,
L_198 ) ;
V_158 += V_447 ;
}
F_2 ( V_206 , L_199 , V_158 , V_525 ) ;
}
V_59 = F_187 ( V_8 , V_8 -> V_204 , V_141 , NULL , 0 ) ;
F_103 ( V_8 -> V_203 ) ;
return V_59 ;
}
int F_89 ( struct V_7 * V_8 , T_2 V_527 , V_171 V_152 )
{
int V_59 ;
F_102 ( V_8 -> V_203 ) ;
V_8 -> V_204 [ 0 ] = V_528 ;
F_216 ( V_8 -> V_204 , 1 , V_152 ) ;
V_8 -> V_204 [ 5 ] = 0 ;
V_8 -> V_204 [ 6 ] = ( V_527 >> 8 ) & 0xff ;
V_8 -> V_204 [ 7 ] = V_527 & 0xff ;
V_59 = F_187 ( V_8 , V_8 -> V_204 , 8 , V_8 -> V_204 , 0 ) ;
F_103 ( V_8 -> V_203 ) ;
return V_59 ;
}
static int F_217 ( struct V_7 * V_8 , T_2 V_527 , V_171 * V_152 )
{
int V_59 = 0 ;
F_102 ( V_8 -> V_203 ) ;
V_8 -> V_204 [ 0 ] = V_529 ;
V_8 -> V_204 [ 1 ] = 0 ;
V_8 -> V_204 [ 2 ] = 0 ;
V_8 -> V_204 [ 3 ] = 0 ;
V_8 -> V_204 [ 4 ] = 0 ;
V_8 -> V_204 [ 5 ] = 0 ;
V_8 -> V_204 [ 6 ] = ( V_527 >> 8 ) & 0xff ;
V_8 -> V_204 [ 7 ] = V_527 & 0xff ;
V_59 |= F_187 ( V_8 , V_8 -> V_204 , 8 , V_8 -> V_204 , 4 ) ;
* V_152 = F_218 ( V_8 -> V_204 , 0 ) ;
F_103 ( V_8 -> V_203 ) ;
return V_59 ;
}
void F_121 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_369 ) return;
F_2 ( V_135 ,
L_200 ) ;
if ( V_8 -> V_277 ) {
F_131 ( V_8 -> V_277 , NULL , 0 , 0 ) ;
}
V_8 -> V_369 = 0 ;
F_1 ( L_201 , V_8 -> V_369 ) ;
F_104 ( V_8 ) ;
}
void F_219 ( struct V_7 * V_8 )
{
int V_59 ;
F_2 ( V_206 , L_202 ) ;
V_59 = F_220 ( V_8 -> V_118 , NULL ) ;
if ( V_59 == 0 ) {
V_59 = F_221 ( V_8 -> V_118 ) ;
F_222 ( V_8 -> V_118 ) ;
} else {
F_2 ( V_135 ,
L_203 , V_59 ) ;
}
if ( V_530 ) {
F_2 ( V_246 ,
L_204 ,
V_530 ) ;
F_223 ( V_530 ) ;
}
}
void F_83 ( struct V_7 * V_8 , int V_2 )
{
char * V_531 ;
unsigned int V_137 ;
int V_59 ;
if ( ! V_8 -> V_118 ) return;
V_531 = F_82 ( 16 , V_151 ) ;
if ( V_531 == NULL ) {
F_2 ( V_135 ,
L_205 ) ;
return;
}
F_2 ( V_206 , L_206 , V_2 ) ;
V_531 [ 0 ] = V_2 ? 0x01 : 0x00 ;
V_137 = F_80 ( V_8 -> V_118 , 0 ) ;
V_59 = F_84 ( V_8 -> V_118 , V_137 , 0xa0 , 0x40 , 0xe600 , 0 , V_531 , 1 , V_153 ) ;
if ( V_59 < 0 ) {
F_2 ( V_135 ,
L_207 , V_2 , V_59 ) ;
F_121 ( V_8 ) ;
}
F_85 ( V_531 ) ;
}
int F_92 ( struct V_7 * V_8 )
{
return F_93 ( V_8 , V_532 ) ;
}
int F_124 ( struct V_7 * V_8 )
{
return F_93 ( V_8 , V_533 ) ;
}
int F_224 ( struct V_7 * V_8 )
{
F_2 ( V_206 ,
L_208 ) ;
if ( V_8 -> V_184 ) {
F_98 ( & V_8 -> V_180 , V_8 -> V_184 ,
V_266 , V_534 , 0 ) ;
F_116 ( V_8 ) ;
return 0 ;
}
F_2 ( V_206 ,
L_209 ) ;
return - V_144 ;
}
static int F_225 ( struct V_7 * V_8 , int V_535 )
{
V_8 -> V_369 = ! 0 ;
return F_93 ( V_8 ,
V_536 |
( 1 << 8 ) |
( ( V_535 ? 1 : 0 ) << 16 ) ) ;
}
static int F_226 ( struct V_7 * V_8 , int V_535 )
{
V_8 -> V_369 = ! 0 ;
return F_93 ( V_8 , ( V_535 ?
V_537 :
V_538 ) ) ;
}
static int F_227 ( struct V_7 * V_8 ,
int V_535 )
{
return F_93 ( V_8 , ( V_535 ?
V_539 :
V_540 ) ) ;
}
static void F_228 ( struct V_7 * V_8 , int V_541 )
{
int V_542 ;
V_542 = ( V_541 ? V_321 : V_320 ) ;
if ( V_542 == V_8 -> V_319 ) {
return;
}
switch ( V_8 -> V_43 -> V_310 ) {
case V_543 :
F_225 ( V_8 , V_541 ) ;
if ( V_542 == V_320 ) {
F_224 ( V_8 ) ;
}
break;
case V_544 :
F_226 ( V_8 , V_541 ) ;
break;
default: break;
}
F_100 ( V_8 ) ;
V_8 -> V_319 = V_542 ;
}
static void F_229 ( struct V_7 * V_8 , int V_535 )
{
if ( V_535 ) {
F_90 ( V_8 , 0xffffffff , 0x00000481 ) ;
} else {
F_90 ( V_8 , 0xffffffff , 0x00000401 ) ;
}
F_91 ( V_8 , 0xffffffff , 0x00000000 ) ;
}
static void F_230 ( struct V_7 * V_8 , int V_535 )
{
unsigned int V_545 ;
T_6 V_386 ;
if ( ( ! V_535 ) == ( ! V_8 -> V_546 ) ) return;
V_8 -> V_546 = V_535 != 0 ;
V_545 = V_8 -> V_43 -> V_547 ;
if ( V_545 < F_87 ( V_548 ) ) {
V_386 = V_548 [ V_545 ] ;
} else {
V_386 = NULL ;
}
if ( V_386 ) (* V_386)( V_8 , V_535 ) ;
}
static int F_231 ( struct V_7 * V_8 , int V_549 )
{
int V_59 ;
if ( V_8 -> V_319 == V_320 ) {
return F_93 ( V_8 ,
( V_549 ?
V_550 :
V_551 ) ) ;
}
if ( V_8 -> V_319 != V_321 ) {
return - V_132 ;
}
switch ( V_8 -> V_43 -> V_310 ) {
case V_543 :
return F_93 ( V_8 ,
( V_549 ?
V_552 :
V_553 ) ) ;
case V_544 :
V_59 = F_93 ( V_8 ,
( V_549 ?
V_550 :
V_551 ) ) ;
if ( V_59 ) return V_59 ;
return F_227 ( V_8 , V_549 ) ;
default:
return - V_132 ;
}
}
static int F_232 ( struct V_7 * V_8 )
{
if ( V_8 -> V_451 ) {
return 0 ;
}
if ( ! V_8 -> V_459 ) {
return 0 ;
}
F_228 ( V_8 , V_8 -> V_45 == V_312 ) ;
V_8 -> V_451 = ! 0 ;
F_1 ( L_156 , V_8 -> V_451 ) ;
return ! 0 ;
}
static int F_233 ( struct V_7 * V_8 )
{
if ( V_8 -> V_554 ) return 0 ;
if ( V_8 -> V_186 ) return 0 ;
if ( V_8 -> V_72 ) return 0 ;
if ( V_8 -> V_555 ) return 0 ;
if ( V_8 -> V_556 ) return 0 ;
if ( V_8 -> V_557 ) return 0 ;
if ( V_8 -> V_319 == V_321 ) {
if ( ! V_8 -> V_43 -> V_558 ) return 0 ;
} else if ( V_8 -> V_319 != V_320 ) {
return 0 ;
}
if ( F_86 ( V_8 ) < 0 ) {
V_8 -> V_186 = ! 0 ;
F_1 ( L_210 , V_8 -> V_186 ) ;
return ! 0 ;
}
V_8 -> V_554 = ! 0 ;
F_1 ( L_211 , V_8 -> V_554 ) ;
return ! 0 ;
}
static int F_234 ( struct V_7 * V_8 )
{
if ( V_8 -> V_555 ) {
if ( V_8 -> V_554 ) {
if ( V_8 -> V_81 &&
! V_8 -> V_460 ) return 0 ;
}
V_8 -> V_555 = 0 ;
V_8 -> V_559 = 0 ;
F_1 ( L_212 , V_8 -> V_559 ) ;
F_88 ( & V_8 -> V_303 ) ;
} else {
if ( ! V_8 -> V_451 ||
( V_8 -> V_319 != V_320 ) ||
! V_8 -> V_554 ||
! V_8 -> V_459 ||
V_8 -> V_460 ||
! V_8 -> V_81 ||
! V_8 -> V_195 ) {
if ( F_235 ( & V_8 -> V_303 ) ) {
F_88 ( & V_8 -> V_303 ) ;
}
if ( V_8 -> V_559 ) {
V_8 -> V_559 = 0 ;
F_1 ( L_212 ,
V_8 -> V_559 ) ;
return ! 0 ;
}
return 0 ;
}
if ( ! V_8 -> V_559 ) {
if ( ! F_235 ( & V_8 -> V_303 ) ) {
if ( ! V_8 -> V_559 ) {
V_8 -> V_303 . V_517 =
V_518 + F_236 (
V_560 ) ;
F_214 ( & V_8 -> V_303 ) ;
}
}
return 0 ;
}
F_237 ( V_8 ) ;
if ( V_8 -> V_554 ) V_8 -> V_555 = ! 0 ;
}
F_1 ( L_213 , V_8 -> V_555 ) ;
return ! 0 ;
}
static int F_238 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_554 ) {
return ! 0 ;
}
if ( ! V_8 -> V_451 ) {
return ! 0 ;
}
switch ( V_8 -> V_319 ) {
case V_320 :
if ( ! V_8 -> V_556 ) {
return ! 0 ;
}
break;
case V_321 :
if ( V_8 -> V_167 ) {
return ! 0 ;
}
break;
default:
return ! 0 ;
}
return 0 ;
}
static int F_239 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_554 ) {
return 0 ;
}
if ( ! V_8 -> V_451 ) {
return 0 ;
}
switch ( V_8 -> V_319 ) {
case V_320 :
if ( V_8 -> V_556 && V_8 -> V_561 ) {
return ! 0 ;
}
break;
case V_321 :
if ( ( V_8 -> V_43 -> V_310 ==
V_544 ) &&
! V_8 -> V_167 ) {
return ! 0 ;
}
break;
default:
break;
}
return 0 ;
}
static int F_240 ( struct V_7 * V_8 )
{
if ( V_8 -> V_72 ) {
if ( ! F_238 ( V_8 ) ) return 0 ;
if ( V_8 -> V_554 ) {
F_88 ( & V_8 -> V_166 ) ;
if ( F_241 ( V_8 ) < 0 ) return ! 0 ;
}
V_8 -> V_72 = 0 ;
} else {
if ( ! F_239 ( V_8 ) ) return 0 ;
if ( F_242 ( V_8 ) < 0 ) return ! 0 ;
V_8 -> V_72 = ! 0 ;
if ( ! V_8 -> V_167 ) {
V_8 -> V_166 . V_517 = V_518 +
F_236 ( V_562 ) ;
F_214 ( & V_8 -> V_166 ) ;
}
}
F_1 ( L_214 , V_8 -> V_72 ) ;
return ! 0 ;
}
static void V_300 ( unsigned long V_152 )
{
struct V_7 * V_8 = (struct V_7 * ) V_152 ;
V_8 -> V_563 = ! 0 ;
F_1 ( L_215 , V_8 -> V_563 ) ;
V_8 -> V_466 = ! 0 ;
F_243 ( V_8 -> V_366 , & V_8 -> V_367 ) ;
}
static void V_302 ( unsigned long V_152 )
{
struct V_7 * V_8 = (struct V_7 * ) V_152 ;
V_8 -> V_561 = ! 0 ;
F_1 ( L_216 , V_8 -> V_561 ) ;
V_8 -> V_466 = ! 0 ;
F_243 ( V_8 -> V_366 , & V_8 -> V_367 ) ;
}
static void V_304 ( unsigned long V_152 )
{
struct V_7 * V_8 = (struct V_7 * ) V_152 ;
V_8 -> V_559 = ! 0 ;
F_1 ( L_212 , V_8 -> V_559 ) ;
V_8 -> V_466 = ! 0 ;
F_243 ( V_8 -> V_366 , & V_8 -> V_367 ) ;
}
static void V_305 ( unsigned long V_152 )
{
struct V_7 * V_8 = (struct V_7 * ) V_152 ;
if ( ! V_8 -> V_167 ) {
V_8 -> V_167 = ! 0 ;
F_1 ( L_33 , V_8 -> V_167 ) ;
V_8 -> V_466 = ! 0 ;
F_243 ( V_8 -> V_366 , & V_8 -> V_367 ) ;
}
}
static int F_244 ( struct V_7 * V_8 )
{
if ( V_8 -> V_556 ) {
if ( V_8 -> V_554 ) {
if ( V_8 -> V_81 &&
! V_8 -> V_460 &&
V_8 -> V_451 ) return 0 ;
}
if ( ! V_8 -> V_185 ) {
F_97 ( V_8 , 0 ) ;
}
V_8 -> V_563 = 0 ;
V_8 -> V_556 = 0 ;
F_88 ( & V_8 -> V_299 ) ;
F_88 ( & V_8 -> V_301 ) ;
V_8 -> V_561 = 0 ;
} else {
if ( ! V_8 -> V_563 ) {
if ( ! F_235 ( & V_8 -> V_299 ) ) {
if ( ! V_8 -> V_563 ) {
V_8 -> V_299 . V_517 =
V_518 + F_236 (
V_564 ) ;
F_214 ( & V_8 -> V_299 ) ;
}
}
return 0 ;
}
if ( ! V_8 -> V_451 ||
( V_8 -> V_319 != V_320 ) ||
! V_8 -> V_81 ||
V_8 -> V_460 ||
! V_8 -> V_195 ||
! V_8 -> V_555 ||
! V_8 -> V_554 ) return 0 ;
F_88 ( & V_8 -> V_299 ) ;
if ( V_8 -> V_185 ) return 0 ;
if ( F_97 ( V_8 , ! 0 ) < 0 ) return 0 ;
V_8 -> V_563 = 0 ;
V_8 -> V_561 = 0 ;
V_8 -> V_556 = ! 0 ;
if ( V_8 -> V_184 == V_247 ) {
V_8 -> V_301 . V_517 =
V_518 + F_236 (
V_565 ) ;
F_214 ( & V_8 -> V_301 ) ;
} else {
V_8 -> V_561 = ! 0 ;
}
}
F_1 ( L_215 , V_8 -> V_563 ) ;
F_1 ( L_217 , V_8 -> V_556 ) ;
F_1 ( L_216 , V_8 -> V_561 ) ;
return ! 0 ;
}
static int F_245 ( struct V_7 * V_8 )
{
if ( V_8 -> V_557 ) {
int V_187 = ! 0 ;
if ( V_8 -> V_319 == V_320 ) {
V_187 = ( V_8 -> V_554 &&
V_8 -> V_72 ) ;
} else if ( ( V_8 -> V_319 == V_321 ) &&
( V_8 -> V_43 -> V_558 ) ) {
V_187 = V_8 -> V_554 ;
}
if ( V_187 &&
V_8 -> V_81 &&
! V_8 -> V_460 &&
V_8 -> V_451 ) {
return 0 ;
}
F_231 ( V_8 , 0 ) ;
V_8 -> V_557 = 0 ;
} else {
if ( ! V_8 -> V_81 ||
V_8 -> V_460 ||
! V_8 -> V_451 ) return 0 ;
if ( V_8 -> V_319 == V_320 ) {
if ( ! V_8 -> V_554 ||
! V_8 -> V_72 ) return 0 ;
} else if ( ( V_8 -> V_319 == V_321 ) &&
( V_8 -> V_43 -> V_558 ) ) {
if ( ! V_8 -> V_554 ) return 0 ;
if ( V_8 -> V_72 ) return 0 ;
if ( V_8 -> V_43 -> V_310 ==
V_544 ) {
if ( ! V_8 -> V_167 ) return 0 ;
}
}
if ( F_231 ( V_8 , ! 0 ) < 0 ) return 0 ;
V_8 -> V_557 = ! 0 ;
}
F_1 ( L_218 , V_8 -> V_557 ) ;
return ! 0 ;
}
static int F_246 ( struct V_7 * V_8 )
{
if ( V_8 -> V_195 ||
V_8 -> V_460 ) return 0 ;
F_176 ( V_8 ) ;
return ! 0 ;
}
static int F_247 ( struct V_7 * V_8 )
{
unsigned int V_176 ;
int V_566 = 0 ;
V_176 = ! ( V_8 -> V_72 ||
V_8 -> V_556 ||
V_8 -> V_557 ||
( ! V_8 -> V_563 ) ) ;
if ( ! V_176 != ! V_8 -> V_459 ) {
V_8 -> V_459 = V_176 ;
V_566 = ! 0 ;
}
if ( V_8 -> V_459 && V_8 -> V_460 ) {
V_8 -> V_460 = 0 ;
V_566 = ! 0 ;
}
return V_566 ;
}
static int F_248 ( struct V_7 * V_8 )
{
unsigned int V_377 ;
int V_567 = 0 ;
int V_568 ;
if ( ! V_8 -> V_466 ) return 0 ;
if ( ( V_8 -> V_142 != V_143 ) ||
! V_8 -> V_369 ) {
V_8 -> V_466 = 0 ;
return ! 0 ;
}
do {
V_568 = 0 ;
F_247 ( V_8 ) ;
for ( V_377 = 0 ; ( V_377 < F_87 ( V_569 ) ) && V_8 -> V_369 ; V_377 ++ ) {
if ( (* V_569 [ V_377 ])( V_8 ) ) {
V_568 = ! 0 ;
V_567 = ! 0 ;
F_247 ( V_8 ) ;
}
}
} while ( V_568 && V_8 -> V_369 );
V_8 -> V_466 = 0 ;
F_1 ( L_219 , V_8 -> V_466 ) ;
return V_567 ;
}
static unsigned int F_249 ( unsigned int V_93 ,
char * V_207 , unsigned int V_570 )
{
unsigned int V_131 , V_447 ;
unsigned int V_484 = 0 ;
for ( V_131 = 0 ; V_131 < F_87 ( V_571 ) ; V_131 ++ ) {
if ( ! ( ( 1 << V_131 ) & V_93 ) ) continue;
V_447 = F_128 ( V_207 + V_484 ,
V_570 - V_484 ,
L_220 ,
( V_484 ? L_221 : L_145 ) ,
V_571 [ V_131 ] ) ;
V_484 += V_447 ;
}
return V_484 ;
}
static const char * F_250 ( int V_66 )
{
switch ( V_66 ) {
case V_320 : return L_222 ;
case V_321 : return L_223 ;
default: return L_224 ;
}
}
static unsigned int F_251 ( struct V_7 * V_8 , int V_431 ,
char * V_207 , unsigned int V_570 )
{
switch ( V_431 ) {
case 0 :
return F_128 (
V_207 , V_570 ,
L_225 ,
( V_8 -> V_369 ? L_226 : L_227 ) ,
( V_8 -> V_279 ? L_228 : L_229 ) ,
( V_8 -> V_283 ? L_230 :
L_231 ) ,
( V_8 -> V_186 ? L_232 : L_145 ) ,
( V_8 -> V_185 ? L_233 : L_145 ) ,
F_250 ( V_8 -> V_319 ) ) ;
case 1 :
return F_128 (
V_207 , V_570 ,
L_234 ,
( V_8 -> V_459 ? L_235 : L_145 ) ,
( V_8 -> V_195 ?
L_236 : L_237 ) ,
( V_8 -> V_81 ? L_238 : L_145 ) ,
( V_8 -> V_460 ? L_239 : L_145 ) ) ;
case 2 :
return F_128 (
V_207 , V_570 ,
L_240 ,
( V_8 -> V_556 ?
( V_8 -> V_561 ?
L_241 : L_242 ) :
( V_8 -> V_563 ?
L_145 : L_243 ) ) ,
( V_8 -> V_563 ?
L_244 : L_145 ) ,
( V_8 -> V_554 ?
L_145 : L_245 ) ,
( V_8 -> V_72 ?
( V_8 -> V_167 ?
L_246 :
L_247 ) :
( V_8 -> V_167 ?
L_248 :
L_249 ) ) ,
( V_8 -> V_555 ?
L_250 :
( V_8 -> V_559 ?
L_145 : L_251 ) ) ,
( V_8 -> V_557 ?
L_252 : L_253 ) ,
( V_8 -> V_451 ?
L_254 : L_145 ) ) ;
case 3 :
return F_128 (
V_207 , V_570 ,
L_255 ,
F_96 ( V_8 -> V_82 ) ) ;
case 4 : {
unsigned int V_484 = 0 ;
unsigned int V_447 ;
V_447 = F_128 ( V_207 ,
V_570 ,
L_256 ) ;
V_484 += V_447 ;
V_484 += F_249 ( V_8 -> V_318 ,
V_207 + V_484 ,
V_570 - V_484 ) ;
if ( V_8 -> V_318 != V_8 -> V_46 ) {
V_447 = F_128 ( V_207 + V_484 ,
V_570 - V_484 ,
L_257 ) ;
V_484 += V_447 ;
V_484 += F_249 ( V_8 -> V_46 ,
V_207 + V_484 ,
V_570 - V_484 ) ;
}
return V_484 ;
}
case 5 : {
struct V_572 V_573 ;
if ( ! V_8 -> V_277 ) break;
F_252 ( V_8 -> V_277 ,
& V_573 ,
0 ) ;
return F_128 (
V_207 , V_570 ,
L_258
L_259
L_260 ,
V_573 . V_574 ,
V_573 . V_575 ,
V_573 . V_576 ,
V_573 . V_577 ,
V_573 . V_578 ,
V_573 . V_579 ) ;
}
case 6 : {
unsigned int V_66 = V_8 -> V_263 ;
return F_128 ( V_207 , V_570 , L_261 , V_66 ,
( V_66 >= F_87 ( V_580 ) ?
L_262 : V_580 [ V_66 ] ) ) ;
}
default: break;
}
return 0 ;
}
static unsigned int F_253 ( struct V_7 * V_8 ,
char * V_207 , unsigned int V_570 )
{
struct V_234 * V_235 ;
unsigned int V_484 = 0 ;
unsigned int V_447 ;
struct V_581 * V_582 ;
const char * V_237 ;
unsigned int V_66 ;
V_447 = F_128 ( V_207 , V_570 , L_263 ) ;
V_484 += V_447 ;
F_174 (sd, &hdw->v4l2_dev) {
V_66 = V_235 -> V_245 ;
V_237 = NULL ;
if ( V_66 < F_87 ( V_240 ) ) V_237 = V_240 [ V_66 ] ;
if ( V_237 ) {
V_447 = F_128 ( V_207 + V_484 , V_570 - V_484 , L_264 , V_237 ) ;
V_484 += V_447 ;
} else {
V_447 = F_128 ( V_207 + V_484 , V_570 - V_484 ,
L_265 , V_66 ) ;
V_484 += V_447 ;
}
V_582 = F_254 ( V_235 ) ;
if ( V_582 ) {
V_447 = F_128 ( V_207 + V_484 , V_570 - V_484 ,
L_266 , V_582 -> V_1 ,
V_582 -> V_389 ) ;
V_484 += V_447 ;
} else {
V_447 = F_128 ( V_207 + V_484 , V_570 - V_484 ,
L_267 ) ;
V_484 += V_447 ;
}
}
return V_484 ;
}
unsigned int F_255 ( struct V_7 * V_8 ,
char * V_207 , unsigned int V_570 )
{
unsigned int V_158 , V_447 , V_131 ;
V_158 = 0 ;
F_102 ( V_8 -> V_188 ) ;
for ( V_131 = 0 ; ; V_131 ++ ) {
V_447 = F_251 ( V_8 , V_131 , V_207 , V_570 ) ;
if ( ! V_447 ) break;
V_158 += V_447 ; V_570 -= V_447 ; V_207 += V_447 ;
if ( ! V_570 ) break;
V_207 [ 0 ] = '\n' ; V_447 = 1 ;
V_158 += V_447 ; V_570 -= V_447 ; V_207 += V_447 ;
}
V_447 = F_253 ( V_8 , V_207 , V_570 ) ;
V_158 += V_447 ; V_570 -= V_447 ; V_207 += V_447 ;
F_103 ( V_8 -> V_188 ) ;
return V_158 ;
}
static void F_195 ( struct V_7 * V_8 )
{
char V_207 [ 256 ] ;
unsigned int V_131 , V_447 ;
unsigned int V_583 , V_584 ;
for ( V_131 = 0 ; ; V_131 ++ ) {
V_447 = F_251 ( V_8 , V_131 , V_207 , sizeof( V_207 ) ) ;
if ( ! V_447 ) break;
F_193 ( V_474 L_268 , V_8 -> V_1 , V_447 , V_207 ) ;
}
V_447 = F_253 ( V_8 , V_207 , sizeof( V_207 ) ) ;
V_584 = 0 ;
while ( V_584 < V_447 ) {
V_583 = 0 ;
while ( ( V_583 + V_584 < V_447 ) && ( V_207 [ V_583 + V_584 ] != '\n' ) ) {
V_583 ++ ;
}
F_193 ( V_474 L_268 , V_8 -> V_1 , V_583 , V_207 + V_584 ) ;
V_584 += V_583 + 1 ;
}
}
static int F_182 ( struct V_7 * V_8 )
{
unsigned int V_176 ;
int V_567 = 0 ;
int V_585 = 0 ;
int V_586 ;
F_2 ( V_3 ,
L_269 ) ;
if ( V_448 & V_3 ) {
F_195 ( V_8 ) ;
}
V_567 = F_248 ( V_8 ) ;
V_586 = ( V_8 -> V_319 != V_321 ) ;
if ( ! V_8 -> V_369 ) {
V_176 = V_306 ;
} else if ( V_8 -> V_142 != V_143 ) {
V_176 = V_587 ;
} else if ( ( V_586 ||
V_8 -> V_43 -> V_558 ) &&
! V_8 -> V_554 ) {
V_176 = V_588 ;
} else if ( V_8 -> V_186 ||
( V_586 && V_8 -> V_185 ) ) {
V_176 = V_589 ;
} else if ( V_8 -> V_557 &&
( ! V_586 ||
( V_8 -> V_72 && V_8 -> V_556 ) ) ) {
V_176 = V_191 ;
} else {
V_176 = V_192 ;
}
if ( V_8 -> V_82 != V_176 ) {
F_2 ( V_590 ,
L_270 ,
F_96 ( V_8 -> V_82 ) ,
F_96 ( V_176 ) ) ;
F_230 ( V_8 , V_176 == V_191 ) ;
V_8 -> V_82 = V_176 ;
V_567 = ! 0 ;
V_585 = ! 0 ;
}
if ( V_567 ) {
F_256 ( & V_8 -> V_307 ) ;
}
if ( V_448 & V_3 ) {
F_195 ( V_8 ) ;
}
F_2 ( V_3 ,
L_271 , V_585 ) ;
return V_585 ;
}
static void F_104 ( struct V_7 * V_8 )
{
if ( V_8 -> V_466 ) return;
V_8 -> V_466 = ! 0 ;
F_1 ( L_219 , V_8 -> V_466 ) ;
F_243 ( V_8 -> V_366 , & V_8 -> V_367 ) ;
}
int F_257 ( struct V_7 * V_8 , V_171 * V_591 )
{
return F_217 ( V_8 , V_592 , V_591 ) ;
}
int F_178 ( struct V_7 * V_8 , V_171 * V_591 )
{
return F_217 ( V_8 , V_593 , V_591 ) ;
}
int F_258 ( struct V_7 * V_8 , V_171 * V_591 )
{
return F_217 ( V_8 , V_594 , V_591 ) ;
}
int F_90 ( struct V_7 * V_8 , V_171 V_93 , V_171 V_2 )
{
V_171 V_595 , V_596 ;
int V_59 ;
if ( ~ V_93 ) {
V_59 = F_217 ( V_8 , V_592 , & V_595 ) ;
if ( V_59 ) return V_59 ;
V_596 = ( V_595 & ~ V_93 ) | ( V_2 & V_93 ) ;
F_2 ( V_597 ,
L_272
L_273 ,
V_93 , V_2 , V_595 , V_596 ) ;
} else {
V_596 = V_2 ;
F_2 ( V_597 ,
L_274 , V_596 ) ;
}
return F_89 ( V_8 , V_592 , V_596 ) ;
}
int F_91 ( struct V_7 * V_8 , V_171 V_93 , V_171 V_2 )
{
V_171 V_595 , V_596 ;
int V_59 ;
if ( ~ V_93 ) {
V_59 = F_217 ( V_8 , V_593 , & V_595 ) ;
if ( V_59 ) return V_59 ;
V_596 = ( V_595 & ~ V_93 ) | ( V_2 & V_93 ) ;
F_2 ( V_597 ,
L_275 ,
V_93 , V_2 , V_595 , V_596 ) ;
} else {
V_596 = V_2 ;
F_2 ( V_597 ,
L_276 , V_596 ) ;
}
return F_89 ( V_8 , V_593 , V_596 ) ;
}
void F_41 ( struct V_7 * V_8 )
{
struct V_417 * V_470 = & V_8 -> V_50 ;
memset ( V_470 , 0 , sizeof( * V_470 ) ) ;
V_470 -> type = ( V_8 -> V_45 == V_124 ) ?
V_419 : V_420 ;
V_8 -> V_49 = 0 ;
F_98 ( & V_8 -> V_180 , 0 , V_198 , V_598 , V_470 ) ;
F_2 ( V_179 , L_277
L_278
L_279 ,
V_470 -> type ,
V_470 -> signal , V_470 -> V_101 , V_470 -> V_53 ,
V_470 -> V_55 , V_470 -> V_51 ) ;
V_8 -> V_355 = 0 ;
}
unsigned int F_259 ( struct V_7 * V_8 )
{
return V_8 -> V_318 ;
}
unsigned int F_260 ( struct V_7 * V_8 )
{
return V_8 -> V_46 ;
}
static int F_37 ( struct V_7 * V_8 , int V_13 )
{
if ( V_8 -> V_45 != V_13 ) {
V_8 -> V_45 = V_13 ;
V_8 -> V_47 = ! 0 ;
}
if ( V_8 -> V_45 == V_124 ) {
V_8 -> V_15 = 0 ;
V_8 -> V_19 = ! 0 ;
} else if ( ( V_8 -> V_45 == V_309 ) ||
( V_8 -> V_45 == V_312 ) ) {
V_8 -> V_15 = 1 ;
V_8 -> V_19 = ! 0 ;
}
return 0 ;
}
int F_261 ( struct V_7 * V_8 ,
unsigned int V_599 ,
unsigned int V_600 )
{
int V_59 = 0 ;
unsigned int V_601 , V_12 , V_131 ;
F_102 ( V_8 -> V_188 ) ;
do {
V_601 = V_8 -> V_46 & ~ V_599 ;
V_601 |= ( V_600 & V_599 ) ;
V_601 &= V_8 -> V_318 ;
if ( ! V_601 ) {
V_59 = - V_602 ;
break;
}
V_8 -> V_46 = V_601 ;
if ( ( 1 << V_8 -> V_45 ) & V_8 -> V_46 ) {
break;
}
if ( ! V_8 -> V_46 ) {
break;
}
V_12 = V_8 -> V_46 ;
for ( V_131 = 0 ; V_131 < ( sizeof( V_12 ) << 3 ) ; V_131 ++ ) {
if ( ! ( ( 1 << V_131 ) & V_12 ) ) continue;
F_37 ( V_8 , V_131 ) ;
break;
}
} while ( 0 );
F_103 ( V_8 -> V_188 ) ;
return V_59 ;
}
static int F_126 ( struct V_7 * V_8 )
{
int V_83 ;
F_102 ( V_8 -> V_203 ) ; do {
V_8 -> V_204 [ 0 ] = V_205 ;
V_83 = F_187 ( V_8 ,
V_8 -> V_204 , 1 ,
V_8 -> V_204 , 1 ) ;
if ( V_83 < 0 ) break;
V_83 = V_8 -> V_204 [ 0 ] ;
} while( 0 ); F_103 ( V_8 -> V_203 ) ;
return V_83 ;
}

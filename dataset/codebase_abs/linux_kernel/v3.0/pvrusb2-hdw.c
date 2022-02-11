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
* V_6 = V_5 -> V_8 -> V_87 ;
return 0 ;
}
static int F_55 ( struct V_4 * V_5 , int V_12 , int V_13 )
{
struct V_7 * V_8 = V_5 -> V_8 ;
T_1 V_88 ;
V_88 = V_8 -> V_87 ;
V_88 = ( V_88 & ~ V_12 ) | ( V_13 & V_12 ) ;
if ( V_88 == V_8 -> V_87 ) return 0 ;
V_8 -> V_87 = V_88 ;
F_56 ( V_8 ) ;
F_57 ( V_8 ) ;
return 0 ;
}
static int F_58 ( struct V_4 * V_5 , int V_89 , int V_2 ,
char * V_90 , unsigned int V_91 ,
unsigned int * V_92 )
{
* V_92 = F_59 ( V_90 , V_91 , V_89 & V_2 ) ;
return 0 ;
}
static int F_60 ( struct V_4 * V_5 ,
const char * V_90 , unsigned int V_91 ,
int * V_93 , int * V_94 )
{
int V_59 ;
T_1 V_66 ;
V_59 = F_61 ( & V_66 , V_90 , V_91 ) ;
if ( V_59 < 0 ) return V_59 ;
if ( V_93 ) * V_93 = V_66 ;
if ( V_94 ) * V_94 = V_66 ;
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
V_8 -> V_95 = ! 0 ;
F_57 ( V_8 ) ;
return 0 ;
}
static int F_64 ( struct V_4 * V_5 )
{
return V_5 -> V_8 -> V_95 != 0 ;
}
static void F_65 ( struct V_4 * V_5 )
{
V_5 -> V_8 -> V_95 = 0 ;
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
unsigned int V_96 ;
struct V_7 * V_8 = V_5 -> V_8 ;
F_41 ( V_8 ) ;
V_96 = V_8 -> V_50 . V_97 ;
if ( V_96 & V_98 ) {
V_2 |= ( 1 << V_99 ) ;
}
if ( V_96 & V_100 ) {
V_2 |= ( 1 << V_101 ) ;
}
if ( V_96 & V_102 ) {
V_2 |= ( 1 << V_103 ) ;
}
if ( V_96 & V_104 ) {
V_2 |= ( 1 << V_105 ) ;
}
* V_6 = V_2 ;
return 0 ;
}
static int F_68 ( struct V_4 * V_5 , int V_12 , int V_13 )
{
struct V_7 * V_8 = V_5 -> V_8 ;
if ( V_13 < 0 ) return - V_106 ;
if ( V_13 > V_8 -> V_107 ) return - V_106 ;
V_8 -> V_108 = V_13 ;
if ( ! V_13 ) return 0 ;
V_13 -- ;
if ( V_8 -> V_41 == V_8 -> V_109 [ V_13 ] . V_66 ) return 0 ;
V_8 -> V_41 = V_8 -> V_109 [ V_13 ] . V_66 ;
V_8 -> V_95 = ! 0 ;
return 0 ;
}
static int F_69 ( struct V_4 * V_5 , int * V_6 )
{
* V_6 = V_5 -> V_8 -> V_108 ;
return 0 ;
}
static int F_70 ( struct V_4 * V_5 )
{
return V_5 -> V_8 -> V_95 != 0 ;
}
static void F_71 ( struct V_4 * V_5 )
{
V_5 -> V_8 -> V_95 = 0 ;
}
const char * F_72 ( enum V_110 V_111 )
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
struct V_117 * F_73 ( struct V_7 * V_8 )
{
return V_8 -> V_118 ;
}
unsigned long F_74 ( struct V_7 * V_8 )
{
return V_8 -> V_119 ;
}
const char * F_75 ( struct V_7 * V_8 )
{
return V_8 -> V_120 ;
}
const char * F_76 ( struct V_7 * V_8 )
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
int F_77 ( struct V_7 * V_8 )
{
return V_8 -> V_125 ;
}
static int F_78 ( struct V_7 * V_8 ,
const struct V_126 * * V_127 ,
const char * V_128 ,
unsigned int V_129 ,
const char * V_130 [] )
{
unsigned int V_131 ;
int V_59 = - V_106 ;
for ( V_131 = 0 ; V_131 < V_129 ; V_131 ++ ) {
V_59 = F_79 ( V_127 ,
V_130 [ V_131 ] ,
& V_8 -> V_118 -> V_132 ) ;
if ( ! V_59 ) {
F_80 ( L_10
L_11 ,
V_128 ,
V_130 [ V_131 ] ) ;
return V_131 ;
}
if ( V_59 == - V_133 ) continue;
F_2 ( V_134 ,
L_12 , V_59 ) ;
return V_59 ;
}
F_2 ( V_134 ,
L_13
L_14
L_15 ,
V_128 ) ;
F_2 ( V_134 ,
L_16
L_17 ) ;
if ( V_129 == 1 ) {
F_2 ( V_134 ,
L_18 ,
V_128 , V_130 [ 0 ] ) ;
} else {
F_2 ( V_134 ,
L_19
L_20 ,
V_128 ) ;
for ( V_131 = 0 ; V_131 < V_129 ; V_131 ++ ) {
F_2 ( V_134 ,
L_21 ,
V_130 [ V_131 ] ) ;
}
}
return V_59 ;
}
static int F_81 ( struct V_7 * V_8 )
{
const struct V_126 * V_127 = NULL ;
void * V_135 ;
unsigned int V_136 ;
unsigned int V_137 ;
int V_59 ;
T_2 V_138 ;
if ( ! V_8 -> V_43 -> V_139 . V_140 ) {
V_8 -> V_141 = V_142 ;
F_2 ( V_134 ,
L_22
L_23 ) ;
return - V_143 ;
}
V_8 -> V_141 = V_144 ;
F_80 ( L_24 ) ;
V_59 = F_78 ( V_8 , & V_127 , L_25 ,
V_8 -> V_43 -> V_139 . V_140 ,
V_8 -> V_43 -> V_139 . V_145 ) ;
if ( V_59 < 0 ) {
if ( V_59 == - V_133 ) V_8 -> V_141 = V_146 ;
return V_59 ;
}
F_82 ( V_8 -> V_118 , F_83 ( V_8 -> V_118 , 0 & 0x7f ) ) ;
V_136 = F_84 ( V_8 -> V_118 , 0 ) ;
V_137 = V_127 -> V_147 ;
if ( ( V_137 != 0x2000 ) &&
( ! ( V_8 -> V_43 -> V_148 && ( V_137 == 0x4000 ) ) ) ) {
if ( V_8 -> V_43 -> V_148 ) {
F_2 ( V_134 ,
L_26
L_27 ,
V_137 ) ;
} else {
F_2 ( V_134 ,
L_26
L_28 ,
V_137 ) ;
}
F_85 ( V_127 ) ;
return - V_149 ;
}
V_135 = F_86 ( 0x800 , V_150 ) ;
if ( V_135 == NULL ) {
F_85 ( V_127 ) ;
return - V_149 ;
}
F_87 ( V_8 , 1 ) ;
V_59 = 0 ;
for ( V_138 = 0 ; V_138 < V_137 ; V_138 += 0x800 ) {
memcpy ( V_135 , V_127 -> V_151 + V_138 , 0x800 ) ;
V_59 += F_88 ( V_8 -> V_118 , V_136 , 0xa0 , 0x40 , V_138 ,
0 , V_135 , 0x800 , V_152 ) ;
}
F_80 ( L_29 ) ;
F_87 ( V_8 , 0 ) ;
F_89 ( V_135 ) ;
F_85 ( V_127 ) ;
F_80 ( L_30 , V_59 ) ;
if ( V_59 == V_137 ) {
V_8 -> V_141 = V_153 ;
return 0 ;
}
return - V_154 ;
}
int F_90 ( struct V_7 * V_8 )
{
const struct V_126 * V_127 = NULL ;
void * V_135 ;
unsigned int V_136 , V_155 , V_156 , V_157 , V_158 ;
int V_159 ;
int V_59 = 0 ;
int V_160 ;
static const char * V_161 [] = {
V_162 ,
} ;
if ( V_8 -> V_43 -> V_163 ) {
return 0 ;
}
F_80 ( L_31 ) ;
V_59 = F_78 ( V_8 , & V_127 , L_32 ,
F_91 ( V_161 ) , V_161 ) ;
if ( V_59 < 0 ) return V_59 ;
V_160 = V_59 ;
V_59 = 0 ;
V_8 -> V_164 = 0 ;
F_92 ( & V_8 -> V_165 ) ;
if ( V_8 -> V_166 ) {
V_8 -> V_166 = 0 ;
F_1 ( L_33 , V_8 -> V_166 ) ;
}
V_59 |= F_93 ( V_8 , 0x0048 , 0xffffffff ) ;
V_59 |= F_94 ( V_8 , 0xffffffff , 0x00000088 ) ;
V_59 |= F_95 ( V_8 , 0xffffffff , 0x00000008 ) ;
V_59 |= F_96 ( V_8 ) ;
V_59 |= F_93 ( V_8 , 0xa064 , 0x00000000 ) ;
V_59 |= F_94 ( V_8 , 0xffffffff , 0x00000408 ) ;
V_59 |= F_95 ( V_8 , 0xffffffff , 0x00000008 ) ;
V_59 |= F_93 ( V_8 , 0x9058 , 0xffffffed ) ;
V_59 |= F_93 ( V_8 , 0x9054 , 0xfffffffd ) ;
V_59 |= F_93 ( V_8 , 0x07f8 , 0x80000800 ) ;
V_59 |= F_93 ( V_8 , 0x07fc , 0x0000001a ) ;
V_59 |= F_93 ( V_8 , 0x0700 , 0x00000000 ) ;
V_59 |= F_93 ( V_8 , 0xaa00 , 0x00000000 ) ;
V_59 |= F_93 ( V_8 , 0xaa04 , 0x00057810 ) ;
V_59 |= F_93 ( V_8 , 0xaa10 , 0x00148500 ) ;
V_59 |= F_93 ( V_8 , 0xaa18 , 0x00840000 ) ;
V_59 |= F_97 ( V_8 , V_167 ) ;
V_59 |= F_97 ( V_8 , V_168 | ( 1 << 8 ) | ( 0 << 16 ) ) ;
if ( V_59 ) {
F_2 ( V_134 ,
L_34 , V_59 ) ;
F_85 ( V_127 ) ;
goto V_169;
}
V_155 = V_127 -> V_147 ;
if ( V_155 % sizeof( V_170 ) ) {
F_2 ( V_134 ,
L_35
L_36 ,
V_161 [ V_160 ] , sizeof( V_170 ) ) ;
F_85 ( V_127 ) ;
V_59 = - V_106 ;
goto V_169;
}
V_135 = F_86 ( V_171 , V_150 ) ;
if ( V_135 == NULL ) {
F_85 ( V_127 ) ;
F_2 ( V_134 ,
L_37 ) ;
V_59 = - V_149 ;
goto V_169;
}
V_136 = F_83 ( V_8 -> V_118 , V_172 ) ;
V_156 = 0 ;
for ( V_156 = 0 ; V_156 < V_155 ; ) {
V_157 = V_155 - V_156 ;
if ( V_157 > V_171 ) V_157 = V_171 ;
memcpy ( V_135 , V_127 -> V_151 + V_156 , V_157 ) ;
for ( V_158 = 0 ; V_158 < V_157 / 4 ; V_158 ++ )
( ( V_170 * ) V_135 ) [ V_158 ] = F_98 ( ( ( V_170 * ) V_135 ) [ V_158 ] ) ;
V_59 |= F_99 ( V_8 -> V_118 , V_136 , V_135 , V_157 ,
& V_159 , V_152 ) ;
V_59 |= ( V_159 != V_157 ) ;
if ( V_59 ) break;
V_156 += V_157 ;
}
F_80 ( L_38 ,
V_161 [ V_160 ] , V_156 , V_155 ) ;
F_89 ( V_135 ) ;
F_85 ( V_127 ) ;
if ( V_59 ) {
F_2 ( V_134 ,
L_39 ) ;
goto V_169;
}
V_59 |= F_93 ( V_8 , 0x9054 , 0xffffffff ) ;
V_59 |= F_93 ( V_8 , 0x9058 , 0xffffffe8 ) ;
V_59 |= F_97 ( V_8 , V_168 | ( 1 << 8 ) | ( 0 << 16 ) ) ;
if ( V_59 ) {
F_2 ( V_134 ,
L_40 ) ;
}
V_169:
if ( V_8 -> V_43 -> V_173 ==
V_174 ) {
F_94 ( V_8 , ( 1 << 11 ) , ~ 0 ) ;
}
return V_59 ;
}
static const char * F_100 ( unsigned int V_175 )
{
if ( V_175 < F_91 ( V_176 ) ) {
return V_176 [ V_175 ] ;
}
return L_41 ;
}
static int F_101 ( struct V_7 * V_8 , int V_177 )
{
F_2 ( V_178 , L_42 ,
( V_177 ? L_43 : L_44 ) ) ;
F_102 ( & V_8 -> V_179 , 0 , V_180 , V_181 , V_177 ) ;
F_102 ( & V_8 -> V_179 , 0 , V_182 , V_181 , V_177 ) ;
if ( V_8 -> V_183 ) {
return 0 ;
}
if ( ! V_8 -> V_184 ) {
F_2 ( V_134 ,
L_45 ) ;
V_8 -> V_184 = ! 0 ;
F_1 ( L_46 ,
V_8 -> V_184 ) ;
}
return - V_154 ;
}
int F_103 ( struct V_7 * V_8 )
{
return V_8 -> V_82 ;
}
static int F_104 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_185 ) return 0 ;
V_8 -> V_185 = 0 ;
F_2 ( V_134 ,
L_47 ) ;
return ! 0 ;
}
int F_105 ( struct V_7 * V_8 )
{
int V_186 ;
F_106 ( V_8 -> V_187 ) ; do {
V_186 = F_104 ( V_8 ) ;
} while ( 0 ); F_107 ( V_8 -> V_187 ) ;
if ( V_186 ) F_108 ( V_8 ) ;
return 0 ;
}
int F_109 ( struct V_7 * V_8 )
{
return V_8 -> V_81 != 0 ;
}
int F_110 ( struct V_7 * V_8 , int V_188 )
{
int V_59 , V_175 ;
F_106 ( V_8 -> V_187 ) ; do {
F_104 ( V_8 ) ;
if ( ( ! V_188 ) != ! ( V_8 -> V_81 ) ) {
V_8 -> V_81 = V_188 != 0 ;
F_2 ( V_189 ,
L_48 ,
V_188 ? L_49 : L_50 ) ;
}
F_108 ( V_8 ) ;
} while ( 0 ); F_107 ( V_8 -> V_187 ) ;
if ( ( V_59 = F_111 ( V_8 , 0 ) ) < 0 ) return V_59 ;
if ( V_188 ) {
while ( ( V_175 = V_8 -> V_82 ) != V_190 ) {
if ( V_175 != V_191 ) return - V_154 ;
if ( ( V_59 = F_111 ( V_8 , V_175 ) ) < 0 ) return V_59 ;
}
}
return 0 ;
}
int F_112 ( struct V_7 * V_8 , enum V_110 V_192 )
{
int V_186 ;
F_106 ( V_8 -> V_187 ) ;
if ( ( V_186 = ( V_8 -> V_193 != V_192 ) ) != 0 ) {
V_8 -> V_193 = V_192 ;
V_8 -> V_194 = 0 ;
F_1 ( L_51 ,
V_8 -> V_194 ) ;
F_108 ( V_8 ) ;
}
F_107 ( V_8 -> V_187 ) ;
if ( V_186 ) return 0 ;
return F_111 ( V_8 , 0 ) ;
}
static int F_113 ( struct V_7 * V_8 )
{
int V_125 = V_8 -> V_125 ;
int V_195 = - 1 ;
if ( ( V_125 >= 0 ) && ( V_125 < V_196 ) ) {
V_195 = V_197 [ V_125 ] ;
}
if ( V_195 < 0 ) return - V_106 ;
V_8 -> V_198 = V_195 ;
V_8 -> V_199 = ! 0 ;
return 0 ;
}
static T_1 F_114 ( struct V_7 * V_8 )
{
int V_125 = V_8 -> V_125 ;
int V_195 = 0 ;
if ( ( V_125 >= 0 ) && ( V_125 < V_196 ) ) {
V_195 = V_200 [ V_125 ] ;
if ( V_195 ) return V_195 ;
}
return 0 ;
}
static unsigned int F_115 ( struct V_7 * V_8 )
{
int V_125 = V_8 -> V_125 ;
int V_195 = 0 ;
if ( ( V_125 >= 0 ) && ( V_125 < V_196 ) ) {
V_195 = V_201 [ V_125 ] ;
}
return V_195 ;
}
static int F_116 ( struct V_7 * V_8 )
{
int V_83 ;
F_106 ( V_8 -> V_202 ) ; do {
V_8 -> V_203 [ 0 ] = V_204 ;
V_83 = F_117 ( V_8 , V_152 * 1 , ! 0 ,
V_8 -> V_203 , 1 ,
V_8 -> V_203 , 1 ) ;
if ( V_83 < 0 ) break;
} while( 0 ); F_107 ( V_8 -> V_202 ) ;
if ( V_83 ) {
F_2 ( V_205 ,
L_52 ,
V_83 ) ;
} else {
F_2 ( V_205 ,
L_53 ) ;
}
return V_83 == 0 ;
}
static void F_118 ( struct V_7 * V_8 )
{
char V_206 [ 40 ] ;
unsigned int V_157 ;
T_1 V_207 , V_208 , V_209 ;
V_207 = F_114 ( V_8 ) ;
V_209 = V_207 ? 0 : V_8 -> V_43 -> V_210 ;
V_157 = F_59 ( V_206 , sizeof( V_206 ) , V_8 -> V_211 ) ;
F_2 ( V_212 ,
L_54
L_55 ,
V_157 , V_206 ) ;
V_8 -> V_87 = V_8 -> V_211 ;
V_208 = ( V_207 | V_209 ) & ~ V_8 -> V_87 ;
if ( V_208 ) {
V_157 = F_59 ( V_206 , sizeof( V_206 ) , V_208 ) ;
F_2 ( V_212 ,
L_56
L_57 ,
V_157 , V_206 ) ;
V_8 -> V_87 |= V_208 ;
}
F_56 ( V_8 ) ;
if ( V_207 ) {
V_157 = F_59 ( V_206 , sizeof( V_206 ) , V_207 ) ;
F_2 ( V_212 ,
L_58 ,
V_157 , V_206 ) ;
V_8 -> V_41 = V_207 ;
V_8 -> V_95 = ! 0 ;
F_57 ( V_8 ) ;
return;
}
if ( V_209 ) {
V_157 = F_59 ( V_206 , sizeof( V_206 ) , V_209 ) ;
F_2 ( V_212 ,
L_59
L_60 , V_157 , V_206 ) ;
V_8 -> V_41 = V_209 ;
V_8 -> V_95 = ! 0 ;
F_57 ( V_8 ) ;
return;
}
{
unsigned int V_131 ;
for ( V_131 = 0 ; V_131 < F_91 ( V_213 ) ; V_131 ++ ) {
if ( V_213 [ V_131 ] . V_89 ?
( ( V_213 [ V_131 ] . V_214 ^
V_8 -> V_211 ) &
V_213 [ V_131 ] . V_89 ) :
( V_213 [ V_131 ] . V_214 !=
V_8 -> V_211 ) ) continue;
V_157 = F_59 ( V_206 , sizeof( V_206 ) ,
V_213 [ V_131 ] . V_215 ) ;
F_2 ( V_212 ,
L_61 ,
V_157 , V_206 ) ;
V_8 -> V_41 = V_213 [ V_131 ] . V_215 ;
V_8 -> V_95 = ! 0 ;
F_57 ( V_8 ) ;
return;
}
}
if ( V_8 -> V_107 > 1 ) {
V_8 -> V_108 = 1 ;
V_8 -> V_41 = V_8 -> V_109 [ V_8 -> V_108 - 1 ] . V_66 ;
V_8 -> V_95 = ! 0 ;
F_2 ( V_212 ,
L_62 ,
V_8 -> V_109 [ V_8 -> V_108 - 1 ] . V_1 ) ;
return;
}
F_2 ( V_134 ,
L_63 ) ;
}
static unsigned int F_119 (
unsigned short * V_216 , const unsigned char * V_217 ,
unsigned int V_218 )
{
unsigned int V_140 = 0 ;
if ( ! V_217 ) return 0 ;
while ( V_217 [ V_140 ] && ( V_140 + 1 ) < V_218 ) {
V_216 [ V_140 ] = V_217 [ V_140 ] ;
V_140 ++ ;
}
V_216 [ V_140 ] = V_219 ;
return V_140 ;
}
static void F_120 ( struct V_7 * V_8 )
{
struct V_220 V_221 ;
if ( V_8 -> V_183 != V_222 ) {
return;
}
F_2 ( V_205 ,
L_64
L_65 ,
V_8 -> V_183 ) ;
memset ( & V_221 , 0 , sizeof( V_221 ) ) ;
V_221 . type = V_223 ;
V_221 . V_221 . V_224 . V_225 [ 0 ] [ 21 ] = V_226 ;
V_221 . V_221 . V_224 . V_225 [ 1 ] [ 21 ] = V_226 ;
F_102 ( & V_8 -> V_179 , V_8 -> V_183 ,
V_227 , V_228 , & V_221 . V_221 . V_224 ) ;
}
static int F_121 ( struct V_7 * V_8 ,
const struct V_229 * V_230 )
{
const char * V_231 ;
unsigned char V_232 ;
struct V_233 * V_234 ;
unsigned int V_235 ;
const unsigned char * V_236 ;
unsigned short V_237 [ 25 ] ;
V_232 = V_230 -> V_238 ;
V_231 = ( V_232 < F_91 ( V_239 ) ) ? V_239 [ V_232 ] : NULL ;
if ( ! V_231 ) {
F_2 ( V_134 ,
L_66
L_67 ,
V_232 ,
V_8 -> V_43 -> V_240 ) ;
return - V_106 ;
}
F_2 ( V_205 ,
L_68 ,
V_232 , V_231 ,
V_8 -> V_43 -> V_240 ) ;
V_235 = F_119 ( V_237 , V_230 -> V_241 ,
F_91 ( V_237 ) ) ;
if ( ! V_235 && ( ( V_236 = ( V_232 < F_91 ( V_242 ) ) ?
V_242 [ V_232 ] : NULL ) != NULL ) ) {
V_235 = F_119 ( V_237 , V_236 ,
F_91 ( V_237 ) ) ;
if ( V_235 ) {
F_2 ( V_205 ,
L_64
L_69 ,
V_232 ) ;
}
}
if ( ! V_235 ) {
F_2 ( V_134 ,
L_70
L_71
L_67 ,
V_232 , V_231 , V_8 -> V_43 -> V_240 ) ;
return - V_106 ;
}
if ( V_235 == 1 ) {
F_2 ( V_205 ,
L_64
L_72 ,
V_232 , V_237 [ 0 ] ) ;
V_234 = F_122 ( & V_8 -> V_179 , & V_8 -> V_243 ,
V_231 , V_237 [ 0 ] , NULL ) ;
} else {
F_2 ( V_205 ,
L_64
L_73 ,
V_232 ) ;
V_234 = F_122 ( & V_8 -> V_179 , & V_8 -> V_243 ,
V_231 , 0 , V_237 ) ;
}
if ( ! V_234 ) {
F_2 ( V_134 ,
L_74
L_75
L_76 ,
V_232 , V_231 , V_8 -> V_43 -> V_240 ) ;
return - V_154 ;
}
V_234 -> V_244 = V_232 ;
F_2 ( V_245 , L_77 , V_231 ) ;
switch ( V_232 ) {
case V_222 :
case V_246 :
V_8 -> V_183 = V_232 ;
break;
default: break;
}
return 0 ;
}
static void F_123 ( struct V_7 * V_8 )
{
unsigned int V_131 ;
const struct V_247 * V_248 ;
const struct V_249 * V_250 ;
int V_251 = ! 0 ;
V_248 = & V_8 -> V_43 -> V_252 ;
for ( V_131 = 0 ; V_131 < V_248 -> V_140 ; V_131 ++ ) {
F_124 ( V_248 -> V_145 [ V_131 ] ) ;
}
V_250 = & V_8 -> V_43 -> V_253 ;
for ( V_131 = 0 ; V_131 < V_250 -> V_140 ; V_131 ++ ) {
if ( F_121 ( V_8 , & V_250 -> V_145 [ V_131 ] ) < 0 ) V_251 = 0 ;
}
if ( ! V_251 ) {
V_8 -> V_254 = ! 0 ;
F_125 ( V_8 ) ;
}
}
static void F_126 ( struct V_7 * V_8 )
{
int V_59 ;
unsigned int V_131 ;
struct V_4 * V_5 ;
int V_255 = 0 ;
if ( V_8 -> V_43 -> V_139 . V_140 ) {
if ( ! V_255 ) {
V_255 =
( V_8 -> V_256 -> V_257 -> V_258 . V_259
== 0 ) ;
if ( V_255 ) {
F_2 ( V_205 ,
L_78
L_79
L_80 ) ;
}
}
if ( ! V_255 ) {
V_255 = ! F_116 ( V_8 ) ;
if ( V_255 ) {
F_2 ( V_205 ,
L_81
L_79
L_80 ) ;
}
}
if ( V_255 ) {
if ( F_81 ( V_8 ) != 0 ) {
F_2 ( V_134 ,
L_82 ) ;
}
return;
}
}
V_8 -> V_141 = V_142 ;
if ( ! F_127 ( V_8 ) ) return;
V_8 -> V_260 = ! 0 ;
if ( ! V_8 -> V_43 -> V_261 ) {
F_128 ( V_8 ) ;
if ( ! F_127 ( V_8 ) ) return;
}
if ( V_8 -> V_262 == V_263 ) {
F_97 ( V_8 ,
V_264 |
( 1 << 8 ) |
( ( 0 ) << 16 ) ) ;
}
F_129 ( V_8 ) ;
if ( ! F_127 ( V_8 ) ) return;
F_123 ( V_8 ) ;
if ( ! F_127 ( V_8 ) ) return;
F_102 ( & V_8 -> V_179 , 0 , V_265 , V_266 ) ;
for ( V_131 = 0 ; V_131 < V_267 ; V_131 ++ ) {
V_5 = V_8 -> V_64 + V_131 ;
if ( V_5 -> V_67 -> V_268 ) continue;
if ( ! V_5 -> V_67 -> V_80 ) continue;
V_5 -> V_67 -> V_80 ( V_5 , ~ 0 , V_5 -> V_67 -> V_269 ) ;
}
F_120 ( V_8 ) ;
V_8 -> V_122 = V_270 ;
V_8 -> V_123 = V_271 ;
if ( V_8 -> V_43 -> V_272 ) {
V_59 = F_130 ( V_8 ) ;
if ( ! F_127 ( V_8 ) ) return;
if ( V_59 < 0 ) {
F_2 ( V_134 ,
L_83
L_84 ) ;
} else {
V_8 -> V_273 = V_59 ;
F_131 ( V_8 ) ;
if ( ! F_127 ( V_8 ) ) return;
}
} else {
V_8 -> V_198 = V_8 -> V_43 -> V_274 ;
V_8 -> V_199 = ! 0 ;
V_8 -> V_211 = V_275 ;
}
if ( V_8 -> V_119 ) {
V_131 = F_132 ( V_8 -> V_121 , sizeof( V_8 -> V_121 ) - 1 ,
L_85 , V_8 -> V_119 ) ;
} else if ( V_8 -> V_125 >= 0 ) {
V_131 = F_132 ( V_8 -> V_121 , sizeof( V_8 -> V_121 ) - 1 ,
L_86 ,
V_8 -> V_125 + 'a' ) ;
} else {
V_131 = F_132 ( V_8 -> V_121 , sizeof( V_8 -> V_121 ) - 1 ,
L_87 ) ;
}
V_8 -> V_121 [ V_131 ] = 0 ;
F_118 ( V_8 ) ;
if ( ! F_113 ( V_8 ) ) {
F_2 ( V_205 ,
L_88 ,
V_8 -> V_198 ) ;
}
if ( ! F_127 ( V_8 ) ) return;
if ( V_8 -> V_43 -> V_173 ==
V_174 ) {
F_94 ( V_8 , ( 1 << 11 ) , ~ 0 ) ;
}
F_133 ( V_8 ) ;
V_8 -> V_276 = F_134 () ;
if ( ! F_127 ( V_8 ) ) return;
F_2 ( V_205 ,
L_89 , V_8 -> V_276 ) ;
if ( V_8 -> V_276 ) {
V_131 = F_115 ( V_8 ) ;
if ( V_131 ) {
F_2 ( V_205 ,
L_90
L_91 ,
V_8 -> V_276 , V_131 ) ;
}
F_135 ( V_8 -> V_276 , V_8 -> V_118 ,
V_277 , V_131 ) ;
}
if ( ! F_127 ( V_8 ) ) return;
V_8 -> V_278 = ! 0 ;
F_108 ( V_8 ) ;
}
static void F_136 ( struct V_7 * V_8 )
{
F_2 ( V_205 , L_92 , V_8 ) ;
do {
F_126 ( V_8 ) ;
F_2 ( V_205 ,
L_93 ,
V_8 , F_127 ( V_8 ) , V_8 -> V_278 ) ;
if ( F_127 ( V_8 ) ) {
if ( V_8 -> V_278 ) {
F_2 (
V_245 ,
L_94
L_95 ) ;
break;
}
if ( V_8 -> V_141 == V_153 ) {
F_2 (
V_245 ,
L_96
L_97
L_98 ) ;
break;
}
F_2 (
V_134 ,
L_99 ) ;
if ( V_8 -> V_141 == V_146 ) {
F_2 (
V_134 ,
L_100
L_101
L_102 ) ;
break;
}
}
if ( V_8 -> V_254 ) {
F_2 (
V_134 ,
L_103
L_104
L_105 ) ;
F_2 (
V_134 ,
L_106
L_107
L_108
L_109 ) ;
break;
}
if ( V_279 ) {
F_2 (
V_134 ,
L_110
L_111 ) ;
F_2 (
V_134 ,
L_112
L_113 ) ;
V_8 -> V_141 = V_280 ;
F_81 ( V_8 ) ;
} else {
F_2 (
V_134 ,
L_114
L_115
L_116 ) ;
F_2 (
V_134 ,
L_117
L_118
L_119 ) ;
}
} while ( 0 );
F_2 ( V_205 , L_120 , V_8 ) ;
}
int F_137 ( struct V_7 * V_8 ,
void (* F_138)( void * ) ,
void * V_281 )
{
F_106 ( V_8 -> V_187 ) ; do {
if ( V_8 -> V_282 ) {
break;
}
V_8 -> V_283 = V_281 ;
V_8 -> V_284 = F_138 ;
F_136 ( V_8 ) ;
} while ( 0 ); F_107 ( V_8 -> V_187 ) ;
return V_8 -> V_278 ;
}
struct V_7 * F_139 ( struct V_285 * V_286 ,
const struct V_287 * V_288 )
{
unsigned int V_131 , V_289 , V_290 , V_12 ;
struct V_7 * V_8 = NULL ;
int V_291 ;
struct V_4 * V_5 ;
struct V_117 * V_118 ;
const struct V_292 * V_43 ;
T_3 V_293 ;
struct V_75 V_76 ;
struct V_77 * V_294 ;
V_118 = F_140 ( V_286 ) ;
V_43 = ( const struct V_292 * ) ( V_288 -> V_295 ) ;
if ( V_43 == NULL ) {
F_2 ( V_205 , L_121
L_122
L_123 ) ;
F_2 ( V_205 , L_124
L_125
L_126 ) ;
goto V_296;
}
V_8 = F_141 ( sizeof( * V_8 ) , V_150 ) ;
F_2 ( V_205 , L_127 ,
V_8 , V_43 -> V_240 ) ;
F_2 ( V_245 , L_128 ,
V_43 -> V_240 ) ;
if ( V_43 -> V_297 ) {
F_2 ( V_245 , L_129 ) ;
F_2 ( V_245 ,
L_130
L_131 , V_43 -> V_240 ) ;
F_2 ( V_245 ,
L_132
L_133 ) ;
F_2 ( V_245 ,
L_134
L_135 ) ;
F_2 ( V_245 , L_129 ) ;
}
if ( ! V_8 ) goto V_296;
F_142 ( & V_8 -> V_298 ) ;
V_8 -> V_298 . V_151 = ( unsigned long ) V_8 ;
V_8 -> V_298 . V_299 = V_300 ;
F_142 ( & V_8 -> V_301 ) ;
V_8 -> V_301 . V_151 = ( unsigned long ) V_8 ;
V_8 -> V_301 . V_299 =
V_302 ;
F_142 ( & V_8 -> V_303 ) ;
V_8 -> V_303 . V_151 = ( unsigned long ) V_8 ;
V_8 -> V_303 . V_299 = V_304 ;
F_142 ( & V_8 -> V_165 ) ;
V_8 -> V_165 . V_151 = ( unsigned long ) V_8 ;
V_8 -> V_165 . V_299 = V_305 ;
V_8 -> V_82 = V_306 ;
F_143 ( & V_8 -> V_307 ) ;
V_8 -> V_49 = ! 0 ;
F_144 ( & V_8 -> V_69 ) ;
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
V_8 -> V_322 = V_267 ;
V_8 -> V_322 += V_323 ;
V_8 -> V_64 = F_141 ( sizeof( struct V_4 ) * V_8 -> V_322 ,
V_150 ) ;
if ( ! V_8 -> V_64 ) goto V_296;
V_8 -> V_43 = V_43 ;
V_8 -> V_262 = V_8 -> V_43 -> V_324 ;
for ( V_131 = 0 ; V_131 < V_8 -> V_322 ; V_131 ++ ) {
V_5 = V_8 -> V_64 + V_131 ;
V_5 -> V_8 = V_8 ;
}
for ( V_131 = 0 ; V_131 < 32 ; V_131 ++ ) {
V_8 -> V_325 [ V_131 ] = V_8 -> V_326 [ V_131 ] ;
}
for ( V_131 = 0 ; V_131 < V_267 ; V_131 ++ ) {
V_5 = V_8 -> V_64 + V_131 ;
V_5 -> V_67 = V_327 + V_131 ;
}
V_12 = V_8 -> V_318 ;
if ( V_12 ) for ( V_131 = 0 ; V_131 < ( sizeof( V_12 ) << 3 ) ; V_131 ++ ) {
if ( ! ( ( 1 << V_131 ) & V_12 ) ) continue;
V_8 -> V_45 = V_131 ;
break;
}
V_8 -> V_328 = F_141 (
sizeof( * ( V_8 -> V_328 ) ) * V_323 , V_150 ) ;
if ( ! V_8 -> V_328 ) goto V_296;
for ( V_131 = 0 ; V_131 < V_323 ; V_131 ++ ) {
V_5 = V_8 -> V_64 + V_131 + V_267 ;
V_294 = & ( V_8 -> V_328 [ V_131 ] . V_67 ) ;
V_294 -> V_258 = V_8 -> V_328 [ V_131 ] . V_258 ;
V_294 -> V_1 = V_329 [ V_131 ] . V_330 ;
V_294 -> V_68 = V_329 [ V_131 ] . V_66 ;
V_294 -> V_268 = ! 0 ;
V_294 -> V_331 = F_45 ;
V_294 -> V_332 = F_48 ;
V_294 -> V_333 = F_43 ;
if ( ! V_131 ) V_294 -> V_334 = F_44 ;
V_76 . V_66 = V_294 -> V_68 ;
F_49 ( & V_8 -> V_69 , & V_76 ) ;
if ( ! ( V_76 . V_78 & V_79 ) ) {
V_294 -> V_80 = F_47 ;
}
strncpy ( V_8 -> V_328 [ V_131 ] . V_258 , V_76 . V_1 ,
V_335 ) ;
V_8 -> V_328 [ V_131 ] . V_258 [ V_335 - 1 ] = 0 ;
V_294 -> V_269 = V_76 . V_269 ;
switch ( V_76 . type ) {
default:
case V_336 :
V_294 -> type = V_337 ;
V_294 -> V_338 . V_339 . V_340 = V_76 . V_341 ;
V_294 -> V_338 . V_339 . V_342 = V_76 . V_343 ;
break;
case V_344 :
V_294 -> type = V_345 ;
break;
case V_346 :
V_294 -> type = V_347 ;
V_294 -> V_338 . V_348 . V_349 =
F_145 ( & V_8 -> V_69 ,
V_294 -> V_68 ) ;
for ( V_289 = 0 ;
V_294 -> V_338 . V_348 . V_349 [ V_289 ] != NULL ;
V_289 ++ ) { }
V_294 -> V_338 . V_348 . V_65 = V_289 ;
break;
}
V_5 -> V_67 = V_294 ;
}
V_5 = F_146 ( V_8 , V_350 ) ;
if ( V_5 ) {
memcpy ( & V_8 -> V_351 , V_5 -> V_67 ,
sizeof( V_8 -> V_351 ) ) ;
V_5 -> V_67 = & V_8 -> V_351 ;
}
V_291 = F_147 () ;
for ( V_131 = 0 ; V_131 < 32 ; V_131 ++ ) {
if ( ! ( V_291 & ( 1 << V_131 ) ) ) continue;
V_289 = F_59 (
V_8 -> V_326 [ V_131 ] ,
sizeof( V_8 -> V_326 [ V_131 ] ) - 1 ,
1 << V_131 ) ;
V_8 -> V_326 [ V_131 ] [ V_289 ] = 0 ;
}
V_5 = F_146 ( V_8 , V_352 ) ;
if ( V_5 ) {
memcpy ( & V_8 -> V_353 , V_5 -> V_67 ,
sizeof( V_8 -> V_353 ) ) ;
V_5 -> V_67 = & V_8 -> V_353 ;
V_8 -> V_353 . V_338 . V_354 . V_355 =
V_8 -> V_325 ;
V_8 -> V_353 . V_338 . V_354 . V_356 =
V_291 ;
}
V_5 = F_146 ( V_8 , V_357 ) ;
if ( V_5 ) {
memcpy ( & V_8 -> V_358 , V_5 -> V_67 ,
sizeof( V_8 -> V_358 ) ) ;
V_5 -> V_67 = & V_8 -> V_358 ;
V_8 -> V_358 . V_338 . V_354 . V_355 =
V_8 -> V_325 ;
V_8 -> V_353 . V_338 . V_354 . V_356 =
V_291 ;
}
V_8 -> V_359 = ! 0 ;
V_8 -> V_273 = - 1 ;
V_8 -> V_125 = - 1 ;
V_8 -> V_360 = - 1 ;
V_8 -> V_361 = - 1 ;
V_8 -> V_362 = - 1 ;
V_8 -> V_363 = F_86 ( V_364 , V_150 ) ;
if ( ! V_8 -> V_363 ) goto V_296;
V_8 -> V_365 = F_86 ( V_364 , V_150 ) ;
if ( ! V_8 -> V_365 ) goto V_296;
V_8 -> V_366 = F_148 ( 0 , V_150 ) ;
if ( ! V_8 -> V_366 ) goto V_296;
V_8 -> V_367 = F_148 ( 0 , V_150 ) ;
if ( ! V_8 -> V_367 ) goto V_296;
if ( F_149 ( & V_286 -> V_132 , & V_8 -> V_179 ) != 0 ) {
F_2 ( V_134 ,
L_136 ) ;
goto V_296;
}
F_150 ( & V_368 ) ; do {
for ( V_131 = 0 ; V_131 < V_196 ; V_131 ++ ) {
if ( V_369 [ V_131 ] ) continue;
V_8 -> V_125 = V_131 ;
V_369 [ V_131 ] = V_8 ;
break;
}
} while ( 0 ); F_151 ( & V_368 ) ;
V_289 = 0 ;
V_290 = F_132 ( V_8 -> V_1 + V_289 , sizeof( V_8 -> V_1 ) - V_289 , L_137 ) ;
V_289 += V_290 ;
if ( V_8 -> V_125 >= 0 ) {
V_290 = F_132 ( V_8 -> V_1 + V_289 , sizeof( V_8 -> V_1 ) - V_289 , L_138 ,
( 'a' + V_8 -> V_125 ) ) ;
V_289 += V_290 ;
}
if ( V_289 >= sizeof( V_8 -> V_1 ) ) V_289 = sizeof( V_8 -> V_1 ) - 1 ;
V_8 -> V_1 [ V_289 ] = 0 ;
V_8 -> V_370 = F_152 ( V_8 -> V_1 ) ;
F_153 ( & V_8 -> V_371 , V_372 ) ;
F_2 ( V_205 , L_139 ,
V_8 -> V_125 , V_8 -> V_1 ) ;
V_8 -> V_198 = - 1 ;
V_8 -> V_373 = ! 0 ;
V_8 -> V_256 = V_286 ;
V_8 -> V_118 = V_118 ;
F_154 ( V_8 -> V_118 , V_8 -> V_120 , sizeof( V_8 -> V_120 ) ) ;
V_293 = V_8 -> V_256 -> V_257 -> V_258 . V_374 ;
F_155 ( V_8 -> V_118 , V_293 , 0 ) ;
F_156 ( & V_8 -> V_375 ) ;
F_156 ( & V_8 -> V_376 ) ;
return V_8 ;
V_296:
if ( V_8 ) {
F_92 ( & V_8 -> V_298 ) ;
F_92 ( & V_8 -> V_301 ) ;
F_92 ( & V_8 -> V_165 ) ;
F_92 ( & V_8 -> V_303 ) ;
if ( V_8 -> V_370 ) {
F_157 ( V_8 -> V_370 ) ;
F_158 ( V_8 -> V_370 ) ;
V_8 -> V_370 = NULL ;
}
F_159 ( V_8 -> V_367 ) ;
F_159 ( V_8 -> V_366 ) ;
F_89 ( V_8 -> V_365 ) ;
F_89 ( V_8 -> V_363 ) ;
F_89 ( V_8 -> V_64 ) ;
F_89 ( V_8 -> V_328 ) ;
F_89 ( V_8 -> V_109 ) ;
F_89 ( V_8 -> V_377 ) ;
F_89 ( V_8 ) ;
}
return NULL ;
}
static void F_160 ( struct V_7 * V_8 )
{
if ( V_8 -> V_282 ) return;
F_2 ( V_205 , L_140 , V_8 ) ;
if ( V_8 -> V_367 ) {
F_161 ( V_8 -> V_367 ) ;
F_159 ( V_8 -> V_367 ) ;
V_8 -> V_367 = NULL ;
}
if ( V_8 -> V_366 ) {
F_161 ( V_8 -> V_366 ) ;
F_159 ( V_8 -> V_366 ) ;
V_8 -> V_366 = NULL ;
}
if ( V_8 -> V_365 ) {
F_89 ( V_8 -> V_365 ) ;
V_8 -> V_365 = NULL ;
}
if ( V_8 -> V_363 ) {
F_89 ( V_8 -> V_363 ) ;
V_8 -> V_363 = NULL ;
}
V_8 -> V_282 = ! 0 ;
F_162 ( & V_8 -> V_179 ) ;
V_8 -> V_118 = NULL ;
V_8 -> V_256 = NULL ;
F_125 ( V_8 ) ;
}
void F_163 ( struct V_7 * V_8 )
{
if ( ! V_8 ) return;
F_2 ( V_205 , L_141 , V_8 ) ;
if ( V_8 -> V_370 ) {
F_157 ( V_8 -> V_370 ) ;
F_158 ( V_8 -> V_370 ) ;
V_8 -> V_370 = NULL ;
}
F_92 ( & V_8 -> V_298 ) ;
F_92 ( & V_8 -> V_301 ) ;
F_92 ( & V_8 -> V_165 ) ;
F_92 ( & V_8 -> V_303 ) ;
if ( V_8 -> V_378 ) {
F_89 ( V_8 -> V_378 ) ;
V_8 -> V_378 = NULL ;
}
if ( V_8 -> V_276 ) {
F_164 ( V_8 -> V_276 ) ;
V_8 -> V_276 = NULL ;
}
F_165 ( V_8 ) ;
F_166 ( & V_8 -> V_179 ) ;
F_160 ( V_8 ) ;
F_150 ( & V_368 ) ; do {
if ( ( V_8 -> V_125 >= 0 ) &&
( V_8 -> V_125 < V_196 ) &&
( V_369 [ V_8 -> V_125 ] == V_8 ) ) {
V_369 [ V_8 -> V_125 ] = NULL ;
}
} while ( 0 ); F_151 ( & V_368 ) ;
F_89 ( V_8 -> V_64 ) ;
F_89 ( V_8 -> V_328 ) ;
F_89 ( V_8 -> V_109 ) ;
F_89 ( V_8 -> V_377 ) ;
F_89 ( V_8 ) ;
}
int F_127 ( struct V_7 * V_8 )
{
return ( V_8 && V_8 -> V_373 ) ;
}
void F_167 ( struct V_7 * V_8 )
{
F_2 ( V_205 , L_142 , V_8 ) ;
F_106 ( V_8 -> V_187 ) ;
F_106 ( V_8 -> V_202 ) ;
F_160 ( V_8 ) ;
F_107 ( V_8 -> V_202 ) ;
F_107 ( V_8 -> V_187 ) ;
}
static void F_57 ( struct V_7 * V_8 )
{
unsigned int V_131 ;
for ( V_131 = 1 ; V_131 < V_8 -> V_107 ; V_131 ++ ) {
if ( V_8 -> V_109 [ V_131 - 1 ] . V_66 == V_8 -> V_41 ) {
V_8 -> V_108 = V_131 ;
return;
}
}
V_8 -> V_108 = 0 ;
}
static void F_56 ( struct V_7 * V_8 )
{
struct V_379 * V_380 ;
unsigned int V_381 ;
unsigned int V_131 ;
V_380 = F_168 ( & V_381 , V_8 -> V_87 ) ;
if ( V_8 -> V_109 ) {
F_89 ( V_8 -> V_109 ) ;
V_8 -> V_109 = NULL ;
}
V_8 -> V_107 = 0 ;
if ( V_8 -> V_377 ) {
F_89 ( V_8 -> V_377 ) ;
V_8 -> V_377 = NULL ;
}
if ( ! V_381 ) {
F_2 (
V_134 ,
L_143 ) ;
}
V_8 -> V_377 = F_86 ( sizeof( char * ) * ( V_381 + 1 ) , V_150 ) ;
if ( V_8 -> V_377 ) {
V_8 -> V_377 [ 0 ] = L_144 ;
for ( V_131 = 0 ; V_131 < V_381 ; V_131 ++ )
V_8 -> V_377 [ V_131 + 1 ] = V_380 [ V_131 ] . V_1 ;
V_8 -> V_351 . V_338 . V_348 . V_349 =
V_8 -> V_377 ;
V_8 -> V_351 . V_338 . V_348 . V_65 = V_381 + 1 ;
} else {
F_2 (
V_134 ,
L_145 ) ;
V_8 -> V_351 . V_338 . V_348 . V_349 = NULL ;
V_8 -> V_351 . V_338 . V_348 . V_65 = 0 ;
}
V_8 -> V_109 = V_380 ;
V_8 -> V_107 = V_381 + 1 ;
V_8 -> V_108 = 0 ;
V_8 -> V_358 . V_338 . V_354 . V_356 = V_8 -> V_87 ;
}
int F_169 ( struct V_7 * V_8 ,
struct V_379 * V_215 ,
unsigned int V_131 )
{
int V_59 = - V_106 ;
if ( ! V_131 ) return V_59 ;
F_106 ( V_8 -> V_187 ) ; do {
if ( V_131 >= V_8 -> V_107 ) break;
V_131 -- ;
memcpy ( V_215 , V_8 -> V_109 + V_131 , sizeof( * V_215 ) ) ;
V_59 = 0 ;
} while ( 0 ); F_107 ( V_8 -> V_187 ) ;
return V_59 ;
}
unsigned int F_170 ( struct V_7 * V_8 )
{
return V_8 -> V_322 ;
}
struct V_4 * F_171 ( struct V_7 * V_8 ,
unsigned int V_131 )
{
if ( V_131 >= V_8 -> V_322 ) return NULL ;
return V_8 -> V_64 + V_131 ;
}
struct V_4 * F_146 ( struct V_7 * V_8 ,
unsigned int V_382 )
{
struct V_4 * V_5 ;
unsigned int V_131 ;
int V_383 ;
for ( V_131 = 0 ; V_131 < V_8 -> V_322 ; V_131 ++ ) {
V_5 = V_8 -> V_64 + V_131 ;
V_383 = V_5 -> V_67 -> V_384 ;
if ( V_383 && ( V_383 == V_382 ) ) return V_5 ;
}
return NULL ;
}
struct V_4 * F_172 ( struct V_7 * V_8 , unsigned int V_382 )
{
struct V_4 * V_5 ;
unsigned int V_131 ;
int V_383 ;
for ( V_131 = 0 ; V_131 < V_8 -> V_322 ; V_131 ++ ) {
V_5 = V_8 -> V_64 + V_131 ;
V_383 = V_5 -> V_67 -> V_68 ;
if ( V_383 && ( V_383 == V_382 ) ) return V_5 ;
}
return NULL ;
}
struct V_4 * F_173 ( struct V_7 * V_8 ,
unsigned int V_382 )
{
struct V_4 * V_5 , * V_385 ;
unsigned int V_131 ;
int V_383 ;
V_385 = NULL ;
for ( V_131 = 0 ; V_131 < V_8 -> V_322 ; V_131 ++ ) {
V_5 = V_8 -> V_64 + V_131 ;
V_383 = V_5 -> V_67 -> V_68 ;
if ( ! V_383 ) continue;
if ( V_383 <= V_382 ) continue;
if ( V_385 && ( V_385 -> V_67 -> V_68 < V_383 ) ) continue;
V_385 = V_5 ;
}
return V_385 ;
return NULL ;
}
static const char * F_174 ( enum V_386 V_195 )
{
switch ( V_195 ) {
case V_337 : return L_146 ;
case V_347 : return L_147 ;
case V_345 : return L_148 ;
case V_387 : return L_149 ;
}
return L_150 ;
}
static void F_175 ( struct V_7 * V_8 , int V_66 ,
const char * V_1 , int V_2 )
{
struct V_388 V_389 ;
F_2 ( V_178 , L_151 , V_1 , V_2 ) ;
memset ( & V_389 , 0 , sizeof( V_389 ) ) ;
V_389 . V_66 = V_66 ;
V_389 . V_71 = V_2 ;
F_102 ( & V_8 -> V_179 , 0 , V_265 , V_390 , & V_389 ) ;
}
static void F_176 ( struct V_7 * V_8 )
{
struct V_233 * V_234 ;
unsigned int V_66 ;
T_4 V_391 ;
F_2 ( V_178 , L_152 ) ;
if ( V_8 -> V_199 || V_8 -> V_260 ) {
struct V_392 V_393 ;
F_2 ( V_178 , L_153 ,
V_8 -> V_198 ) ;
if ( ( ( int ) ( V_8 -> V_198 ) ) >= 0 ) {
memset ( & V_393 , 0 , sizeof( V_393 ) ) ;
V_393 . V_394 = V_395 ;
V_393 . type = V_8 -> V_198 ;
V_393 . V_396 = V_397 | V_398 ;
F_102 ( & V_8 -> V_179 , 0 ,
V_197 , V_399 , & V_393 ) ;
}
}
if ( V_8 -> V_47 || V_8 -> V_95 || V_8 -> V_260 ) {
F_2 ( V_178 , L_154 ) ;
if ( V_8 -> V_45 == V_124 ) {
F_102 ( & V_8 -> V_179 , 0 ,
V_197 , V_400 ) ;
} else {
T_1 V_401 ;
V_401 = V_8 -> V_41 ;
F_102 ( & V_8 -> V_179 , 0 ,
V_265 , V_402 , V_401 ) ;
F_120 ( V_8 ) ;
}
V_8 -> V_49 = ! 0 ;
V_8 -> V_359 = ! 0 ;
}
F_177 ( V_8 , V_403 , V_404 ) ;
F_177 ( V_8 , V_405 , V_406 ) ;
F_177 ( V_8 , V_407 , V_408 ) ;
F_177 ( V_8 , V_409 , V_410 ) ;
F_177 ( V_8 , V_411 , V_412 ) ;
F_177 ( V_8 , V_413 , V_414 ) ;
F_177 ( V_8 , V_415 , V_416 ) ;
F_177 ( V_8 , V_417 , V_418 ) ;
F_177 ( V_8 , V_419 , V_420 ) ;
if ( V_8 -> V_47 || V_8 -> V_421 || V_8 -> V_260 ) {
struct V_422 V_423 ;
memset ( & V_423 , 0 , sizeof( V_423 ) ) ;
V_423 . type = ( V_8 -> V_45 == V_124 ) ?
V_424 : V_425 ;
V_423 . V_426 = V_8 -> V_427 ;
F_102 ( & V_8 -> V_179 , 0 , V_197 , V_428 , & V_423 ) ;
}
if ( V_8 -> V_19 || V_8 -> V_260 ) {
unsigned long V_48 ;
struct V_429 V_18 ;
V_48 = F_11 ( V_8 ) ;
F_2 ( V_178 , L_155 , V_48 ) ;
if ( V_8 -> V_49 ) F_41 ( V_8 ) ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
if ( V_8 -> V_50 . V_53 & V_54 ) {
V_18 . V_430 = ( V_48 * 2 ) / 125 ;
} else {
V_18 . V_430 = V_48 / 62500 ;
}
if ( V_8 -> V_45 == V_124 ) {
V_18 . type = V_424 ;
} else {
V_18 . type = V_425 ;
}
V_18 . V_197 = 0 ;
F_102 ( & V_8 -> V_179 , 0 , V_197 ,
V_431 , & V_18 ) ;
}
if ( V_8 -> V_432 || V_8 -> V_433 || V_8 -> V_260 ) {
struct V_434 V_221 ;
memset ( & V_221 , 0 , sizeof( V_221 ) ) ;
V_221 . V_26 = V_8 -> V_435 ;
V_221 . V_29 = V_8 -> V_436 ;
V_221 . V_437 = V_438 ;
F_2 ( V_178 , L_156 ,
V_221 . V_26 , V_221 . V_29 ) ;
F_102 ( & V_8 -> V_179 , 0 , V_180 , V_439 , & V_221 ) ;
}
if ( V_8 -> V_440 || V_8 -> V_260 ) {
V_170 V_2 ;
F_2 ( V_178 , L_157 ,
V_8 -> V_441 ) ;
switch ( V_8 -> V_441 ) {
default:
case V_442 :
V_2 = 48000 ;
break;
case V_443 :
V_2 = 44100 ;
break;
case V_444 :
V_2 = 32000 ;
break;
}
F_102 ( & V_8 -> V_179 , 0 ,
V_182 , V_445 , V_2 ) ;
}
F_178 (sd, &hdw->v4l2_dev) {
V_66 = V_234 -> V_244 ;
if ( V_66 >= F_91 ( V_446 ) ) continue;
V_391 = V_446 [ V_66 ] ;
if ( ! V_391 ) continue;
(* V_391)( V_8 , V_234 ) ;
}
if ( V_8 -> V_49 || V_8 -> V_359 ) {
F_41 ( V_8 ) ;
}
}
static int F_133 ( struct V_7 * V_8 )
{
unsigned int V_131 ;
struct V_4 * V_5 ;
int V_71 ;
int V_447 = V_8 -> V_260 ;
char V_206 [ 100 ] ;
unsigned int V_157 , V_448 ;
for ( V_131 = 0 ; V_131 < V_8 -> V_322 ; V_131 ++ ) {
V_5 = V_8 -> V_64 + V_131 ;
if ( ! V_5 -> V_67 -> V_333 ) continue;
if ( ! V_5 -> V_67 -> V_333 ( V_5 ) ) continue;
V_447 = ! 0 ;
if ( ! ( V_449 & V_450 ) ) continue;
V_157 = F_132 ( V_206 , sizeof( V_206 ) , L_158 ,
V_5 -> V_67 -> V_1 ) ;
V_71 = 0 ;
V_5 -> V_67 -> V_331 ( V_5 , & V_71 ) ;
F_179 ( V_5 , ~ 0 , V_71 ,
V_206 + V_157 ,
sizeof( V_206 ) - V_157 , & V_448 ) ;
V_157 += V_448 ;
V_157 += F_132 ( V_206 + V_157 , sizeof( V_206 ) - V_157 , L_159 ,
F_174 ( V_5 -> V_67 -> type ) ) ;
F_2 ( V_450 ,
L_160 ,
V_157 , V_206 ) ;
}
if ( ! V_447 ) {
return 0 ;
}
V_8 -> V_194 = 0 ;
F_1 ( L_51 , V_8 -> V_194 ) ;
F_108 ( V_8 ) ;
return ! 0 ;
}
static int F_180 ( struct V_7 * V_8 )
{
unsigned int V_131 ;
struct V_4 * V_5 ;
int V_451 ;
if ( V_8 -> V_47 && V_8 -> V_452 &&
( ( ( V_8 -> V_45 == V_312 ) ?
V_321 : V_320 ) !=
V_8 -> V_319 ) ) {
V_8 -> V_452 = 0 ;
F_1 ( L_161 , V_8 -> V_452 ) ;
}
if ( ! V_8 -> V_452 ) {
return 0 ;
}
if ( V_8 -> V_95 ) {
int V_453 ;
int V_454 ;
if ( V_8 -> V_41 & V_42 ) {
V_453 = 480 ;
V_454 = 15 ;
} else {
V_453 = 576 ;
V_454 = 12 ;
}
if ( V_453 != V_8 -> V_436 ) {
V_8 -> V_436 = V_453 ;
V_8 -> V_433 = ! 0 ;
}
if ( V_454 != V_8 -> V_69 . V_455 ) {
struct V_60 V_61 ;
struct V_62 V_63 ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
memset ( & V_63 , 0 , sizeof( V_63 ) ) ;
V_61 . V_64 = & V_63 ;
V_61 . V_65 = 1 ;
V_63 . V_66 = V_456 ;
V_63 . V_71 = V_454 ;
F_46 ( & V_8 -> V_69 , 0 , & V_61 ,
V_73 ) ;
}
}
if ( V_8 -> V_432 && V_8 -> V_27 < V_8 -> V_435 ) {
V_8 -> V_27 = V_8 -> V_435 ;
V_8 -> V_457 = ! 0 ;
} else if ( V_8 -> V_457 ) {
V_8 -> V_432 = ! 0 ;
V_8 -> V_435 = F_181 ( 720 , V_8 -> V_27 ) ;
}
if ( V_8 -> V_433 && V_8 -> V_30 < V_8 -> V_436 ) {
V_8 -> V_30 = V_8 -> V_436 ;
V_8 -> V_458 = ! 0 ;
} else if ( V_8 -> V_458 ) {
int V_453 = V_8 -> V_41 & V_42 ? 480 : 576 ;
V_8 -> V_433 = ! 0 ;
V_8 -> V_436 = F_181 ( V_453 , V_8 -> V_30 ) ;
}
V_451 =
( V_8 -> V_95 ||
V_8 -> V_58 ||
V_8 -> V_440 ||
V_8 -> V_433 ||
V_8 -> V_432 ||
V_8 -> V_457 ||
V_8 -> V_458 ||
V_8 -> V_47 ||
( V_8 -> V_459 != V_8 -> V_193 ) ) ;
if ( V_451 && ! V_8 -> V_460 ) {
V_8 -> V_461 = ! 0 ;
return 0 ;
}
if ( V_8 -> V_440 ) {
struct V_60 V_61 ;
struct V_62 V_63 ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
memset ( & V_63 , 0 , sizeof( V_63 ) ) ;
V_61 . V_64 = & V_63 ;
V_61 . V_65 = 1 ;
V_63 . V_66 = V_462 ;
V_63 . V_71 = V_8 -> V_441 ;
F_46 ( & V_8 -> V_69 , 0 , & V_61 , V_73 ) ;
}
if ( V_8 -> V_459 != V_8 -> V_193 ) {
V_8 -> V_459 = V_8 -> V_193 ;
}
if ( V_8 -> V_43 -> V_173 ==
V_174 ) {
V_170 V_463 ;
F_182 ( V_8 , & V_463 ) ;
if ( V_8 -> V_45 == V_124 ) {
F_95 ( V_8 , ( 1 << 11 ) , ~ 0 ) ;
} else {
F_95 ( V_8 , ( 1 << 11 ) , 0 ) ;
}
}
F_176 ( V_8 ) ;
V_8 -> V_199 = 0 ;
V_8 -> V_260 = 0 ;
for ( V_131 = 0 ; V_131 < V_8 -> V_322 ; V_131 ++ ) {
V_5 = V_8 -> V_64 + V_131 ;
if ( ! V_5 -> V_67 -> V_334 ) continue;
V_5 -> V_67 -> V_334 ( V_5 ) ;
}
if ( ( V_8 -> V_319 == V_320 ) &&
V_8 -> V_72 ) {
if ( F_183 ( V_8 ) < 0 ) return ! 0 ;
}
V_8 -> V_194 = ! 0 ;
F_1 ( L_51 , V_8 -> V_194 ) ;
return ! 0 ;
}
int F_184 ( struct V_7 * V_8 )
{
int V_186 ;
F_106 ( V_8 -> V_187 ) ;
V_186 = F_133 ( V_8 ) ;
F_107 ( V_8 -> V_187 ) ;
if ( ! V_186 ) return 0 ;
return F_111 ( V_8 , 0 ) ;
}
static void V_372 ( struct V_464 * V_465 )
{
int V_186 = 0 ;
struct V_7 * V_8 = F_185 ( V_465 , struct V_7 , V_371 ) ;
F_106 ( V_8 -> V_187 ) ; do {
V_186 = F_186 ( V_8 ) ;
} while ( 0 ); F_107 ( V_8 -> V_187 ) ;
if ( V_186 && V_8 -> V_284 ) {
V_8 -> V_284 ( V_8 -> V_283 ) ;
}
}
static int F_111 ( struct V_7 * V_8 , int V_466 )
{
return F_187 (
V_8 -> V_307 ,
( V_8 -> V_467 == 0 ) &&
( ! V_466 || ( V_8 -> V_82 != V_466 ) ) ) ;
}
const char * F_188 ( struct V_7 * V_8 )
{
return V_8 -> V_1 ;
}
const char * F_189 ( struct V_7 * V_8 )
{
return V_8 -> V_43 -> V_240 ;
}
const char * F_190 ( struct V_7 * V_8 )
{
return V_8 -> V_43 -> V_468 ;
}
int F_53 ( struct V_7 * V_8 )
{
int V_83 ;
F_106 ( V_8 -> V_202 ) ; do {
V_8 -> V_203 [ 0 ] = V_469 ;
V_83 = F_191 ( V_8 ,
V_8 -> V_203 , 1 ,
V_8 -> V_203 , 1 ) ;
if ( V_83 < 0 ) break;
V_83 = ( V_8 -> V_203 [ 0 ] != 0 ) ;
} while( 0 ); F_107 ( V_8 -> V_202 ) ;
return V_83 ;
}
void F_192 ( struct V_7 * V_8 )
{
F_106 ( V_8 -> V_187 ) ; do {
F_41 ( V_8 ) ;
} while ( 0 ); F_107 ( V_8 -> V_187 ) ;
}
static int F_16 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_359 ) {
return 0 ;
}
F_41 ( V_8 ) ;
if ( V_8 -> V_359 ) {
return - V_154 ;
}
return 0 ;
}
int F_193 ( struct V_7 * V_8 , struct V_21 * V_470 )
{
int V_24 = 0 ;
F_106 ( V_8 -> V_187 ) ;
V_24 = F_16 ( V_8 ) ;
if ( ! V_24 ) {
memcpy ( V_470 , & V_8 -> V_23 , sizeof( V_8 -> V_23 ) ) ;
}
F_107 ( V_8 -> V_187 ) ;
return V_24 ;
}
int F_194 ( struct V_7 * V_8 , struct V_422 * V_471 )
{
F_106 ( V_8 -> V_187 ) ; do {
if ( V_8 -> V_49 ) {
F_41 ( V_8 ) ;
}
memcpy ( V_471 , & V_8 -> V_50 , sizeof( struct V_422 ) ) ;
} while ( 0 ); F_107 ( V_8 -> V_187 ) ;
return 0 ;
}
struct V_472 * F_195 ( struct V_7 * V_473 )
{
return V_473 -> V_276 ;
}
void F_196 ( struct V_7 * V_8 )
{
int V_474 = F_77 ( V_8 ) ;
F_106 ( V_8 -> V_187 ) ; do {
F_197 ( V_475 L_162 , V_474 ) ;
F_102 ( & V_8 -> V_179 , 0 , V_265 , V_476 ) ;
F_2 ( V_245 , L_163 ) ;
F_198 ( & V_8 -> V_69 , L_137 ) ;
F_199 ( V_8 ) ;
F_197 ( V_475 L_164 , V_474 ) ;
} while ( 0 ); F_107 ( V_8 -> V_187 ) ;
}
static T_5 * F_200 ( struct V_7 * V_8 )
{
struct V_477 V_478 [ 2 ] ;
T_5 * V_479 ;
T_5 V_480 [ 2 ] ;
T_5 V_394 ;
T_2 V_481 ;
unsigned int V_482 ;
int V_59 ;
int V_483 = 0 ;
unsigned V_484 , V_485 ;
V_479 = F_86 ( V_486 , V_150 ) ;
if ( ! V_479 ) {
F_2 ( V_134 ,
L_165
L_166 ) ;
return NULL ;
}
F_201 ( L_167 ,
V_8 -> V_273 ) ;
V_394 = V_8 -> V_273 ;
if ( V_394 & 0x80 ) V_394 >>= 1 ;
V_483 = ( V_394 & 1 ) ;
V_481 = ( V_483 ? V_486 : 256 ) ;
F_201 ( L_168
L_169 , V_481 , V_394 ,
V_483 ? 16 : 8 ) ;
V_478 [ 0 ] . V_394 = V_394 ;
V_478 [ 0 ] . V_78 = 0 ;
V_478 [ 0 ] . V_92 = V_483 ? 2 : 1 ;
V_478 [ 0 ] . V_206 = V_480 ;
V_478 [ 1 ] . V_394 = V_394 ;
V_478 [ 1 ] . V_78 = V_487 ;
memset ( V_479 , 0 , V_486 ) ;
for ( V_485 = 0 ; V_485 < V_486 ; V_485 += V_484 ) {
V_484 = 16 ;
if ( V_484 + V_485 > V_486 ) V_484 = V_486 - V_485 ;
V_482 = V_485 + ( V_481 - V_486 ) ;
if ( V_483 ) {
V_480 [ 0 ] = V_482 >> 8 ;
V_480 [ 1 ] = V_482 ;
} else {
V_480 [ 0 ] = V_482 ;
}
V_478 [ 1 ] . V_92 = V_484 ;
V_478 [ 1 ] . V_206 = V_479 + V_485 ;
if ( ( V_59 = F_202 ( & V_8 -> V_243 ,
V_478 , F_91 ( V_478 ) ) ) != 2 ) {
F_2 ( V_134 ,
L_170 , V_59 ) ;
F_89 ( V_479 ) ;
return NULL ;
}
}
return V_479 ;
}
void F_203 ( struct V_7 * V_8 ,
int V_488 ,
int V_188 )
{
int V_59 ;
T_2 V_138 ;
unsigned int V_136 ;
F_106 ( V_8 -> V_187 ) ; do {
if ( ( V_8 -> V_378 == NULL ) == ! V_188 ) break;
if ( ! V_188 ) {
F_2 ( V_489 ,
L_171 ) ;
F_89 ( V_8 -> V_378 ) ;
V_8 -> V_378 = NULL ;
V_8 -> V_490 = 0 ;
if ( V_8 -> V_491 ) {
F_87 ( V_8 , 0 ) ;
}
break;
}
V_8 -> V_491 = ( V_488 != 2 ) ;
if ( V_8 -> V_491 ) {
V_8 -> V_490 = ( V_488 == 1 ) ? 0x4000 : 0x2000 ;
F_2 ( V_489 ,
L_172
L_173 , V_8 -> V_490 ) ;
V_8 -> V_378 = F_141 ( V_8 -> V_490 , V_150 ) ;
if ( ! V_8 -> V_378 ) {
V_8 -> V_490 = 0 ;
break;
}
F_87 ( V_8 , 1 ) ;
F_2 ( V_489 ,
L_174 ) ;
V_136 = F_204 ( V_8 -> V_118 , 0 ) ;
for( V_138 = 0 ; V_138 < V_8 -> V_490 ;
V_138 += 0x800 ) {
V_59 = F_88 ( V_8 -> V_118 , V_136 ,
0xa0 , 0xc0 ,
V_138 , 0 ,
V_8 -> V_378 + V_138 ,
0x800 , V_152 ) ;
if ( V_59 < 0 ) break;
}
F_2 ( V_489 ,
L_175 ) ;
} else {
F_2 ( V_489 ,
L_176 ) ;
V_8 -> V_378 = F_200 ( V_8 ) ;
if ( ! V_8 -> V_378 ) {
F_2 ( V_489 ,
L_177 ) ;
break;
}
V_8 -> V_490 = V_486 ;
F_2 ( V_489 ,
L_178 ) ;
}
} while ( 0 ); F_107 ( V_8 -> V_187 ) ;
}
int F_205 ( struct V_7 * V_8 )
{
return V_8 -> V_378 != NULL ;
}
int F_206 ( struct V_7 * V_8 , unsigned int V_482 ,
char * V_206 , unsigned int V_140 )
{
int V_59 = - V_106 ;
F_106 ( V_8 -> V_187 ) ; do {
if ( ! V_206 ) break;
if ( ! V_140 ) break;
if ( ! V_8 -> V_378 ) {
V_59 = - V_154 ;
break;
}
if ( V_482 >= V_8 -> V_490 ) {
F_2 ( V_489 ,
L_179 ,
V_482 ) ;
V_59 = 0 ;
break;
}
if ( V_482 + V_140 > V_8 -> V_490 ) V_140 = V_8 -> V_490 - V_482 ;
memcpy ( V_206 , V_8 -> V_378 + V_482 , V_140 ) ;
F_2 ( V_489 ,
L_180 ,
V_482 , V_140 ) ;
V_59 = V_140 ;
} while ( 0 ); F_107 ( V_8 -> V_187 ) ;
return V_59 ;
}
int F_207 ( struct V_7 * V_8 ,
enum V_492 V_493 )
{
switch ( V_493 ) {
case V_494 : return V_8 -> V_360 ;
case V_495 : return V_8 -> V_361 ;
case V_496 : return V_8 -> V_362 ;
default: return - 1 ;
}
}
void F_208 ( struct V_7 * V_8 ,
enum V_492 V_493 , int V_13 )
{
switch ( V_493 ) {
case V_494 : V_8 -> V_360 = V_13 ;
case V_495 : V_8 -> V_361 = V_13 ;
case V_496 : V_8 -> V_362 = V_13 ;
default: break;
}
}
static void F_209 ( struct V_497 * V_497 )
{
struct V_7 * V_8 = V_497 -> V_498 ;
V_8 -> V_499 = 0 ;
if ( V_8 -> V_500 ) return;
F_210 ( & V_8 -> V_501 ) ;
}
static void F_211 ( struct V_497 * V_497 )
{
struct V_7 * V_8 = V_497 -> V_498 ;
V_8 -> V_500 = 0 ;
if ( V_8 -> V_499 ) return;
F_210 ( & V_8 -> V_501 ) ;
}
static void F_212 ( unsigned long V_151 )
{
struct V_7 * V_8 = (struct V_7 * ) V_151 ;
if ( V_8 -> V_499 || V_8 -> V_500 ) {
V_8 -> V_502 = ! 0 ;
if ( V_8 -> V_499 )
F_213 ( V_8 -> V_366 ) ;
if ( V_8 -> V_500 )
F_213 ( V_8 -> V_367 ) ;
}
}
static int F_117 ( struct V_7 * V_8 ,
unsigned int V_503 , int V_504 ,
void * V_505 , unsigned int V_506 ,
void * V_507 , unsigned int V_508 )
{
unsigned int V_131 ;
int V_509 = 0 ;
struct V_510 V_511 ;
if ( ! V_8 -> V_512 ) {
F_2 ( V_134 ,
L_181
L_182 ) ;
return - V_513 ;
}
if ( ! V_8 -> V_373 && ! V_504 ) {
F_2 ( V_134 ,
L_181
L_183 ) ;
return - V_154 ;
}
if ( ! ( V_8 -> V_367 && V_8 -> V_366 ) ) {
if ( ! V_504 ) {
F_2 ( V_134 ,
L_181
L_184 ) ;
}
return - V_143 ;
}
if ( ! V_505 ) V_506 = 0 ;
if ( ! V_507 ) V_508 = 0 ;
if ( V_506 > V_364 ) {
F_2 (
V_134 ,
L_185
L_186 ,
V_506 , V_364 ) ;
return - V_106 ;
}
if ( V_508 > V_364 ) {
F_2 (
V_134 ,
L_185
L_187 ,
V_506 , V_364 ) ;
return - V_106 ;
}
if ( ( ! V_506 ) && ( ! V_508 ) ) {
F_2 (
V_134 ,
L_188 ) ;
return - V_106 ;
}
V_8 -> V_514 = 1 ;
if ( V_506 ) {
V_8 -> V_515 = ( ( unsigned char * ) V_505 ) [ 0 ] ;
} else {
V_8 -> V_515 = 0 ;
}
V_8 -> V_516 = V_506 ;
V_8 -> V_517 = V_508 ;
F_214 ( & V_8 -> V_501 ) ;
V_8 -> V_502 = 0 ;
V_8 -> V_499 = 0 ;
V_8 -> V_500 = 0 ;
F_142 ( & V_511 ) ;
V_511 . V_518 = V_519 + V_503 ;
V_511 . V_151 = ( unsigned long ) V_8 ;
V_511 . V_299 = F_212 ;
if ( V_506 ) {
V_8 -> V_514 = 2 ;
for ( V_131 = 0 ; V_131 < V_506 ; V_131 ++ ) {
V_8 -> V_363 [ V_131 ] =
( ( unsigned char * ) V_505 ) [ V_131 ] ;
}
F_215 ( V_8 -> V_366 ,
V_8 -> V_118 ,
F_83 ( V_8 -> V_118 ,
V_520 ) ,
V_8 -> V_363 ,
V_506 ,
F_209 ,
V_8 ) ;
V_8 -> V_366 -> V_159 = 0 ;
V_8 -> V_499 = ! 0 ;
V_509 = F_216 ( V_8 -> V_366 , V_150 ) ;
if ( V_509 < 0 ) {
F_2 ( V_134 ,
L_189
L_190 , V_509 ) ;
V_8 -> V_499 = 0 ;
goto V_169;
}
}
if ( V_508 ) {
V_8 -> V_514 = 3 ;
memset ( V_8 -> V_365 , 0x43 , V_508 ) ;
F_215 ( V_8 -> V_367 ,
V_8 -> V_118 ,
F_217 ( V_8 -> V_118 ,
V_521 ) ,
V_8 -> V_365 ,
V_508 ,
F_211 ,
V_8 ) ;
V_8 -> V_367 -> V_159 = 0 ;
V_8 -> V_500 = ! 0 ;
V_509 = F_216 ( V_8 -> V_367 , V_150 ) ;
if ( V_509 < 0 ) {
F_2 ( V_134 ,
L_191
L_190 , V_509 ) ;
V_8 -> V_500 = 0 ;
goto V_169;
}
}
F_218 ( & V_511 ) ;
V_8 -> V_514 = 4 ;
while ( V_8 -> V_499 || V_8 -> V_500 ) {
F_219 ( & V_8 -> V_501 ) ;
}
V_8 -> V_514 = 5 ;
F_92 ( & V_511 ) ;
V_8 -> V_514 = 6 ;
V_509 = 0 ;
if ( V_8 -> V_502 ) {
V_509 = - V_522 ;
if ( ! V_504 ) {
F_2 ( V_134 ,
L_192 ) ;
}
goto V_169;
}
if ( V_506 ) {
if ( ( V_8 -> V_366 -> V_509 != 0 ) &&
( V_8 -> V_366 -> V_509 != - V_133 ) &&
( V_8 -> V_366 -> V_509 != - V_523 ) &&
( V_8 -> V_366 -> V_509 != - V_524 ) ) {
V_509 = V_8 -> V_366 -> V_509 ;
if ( ! V_504 ) {
F_2 ( V_134 ,
L_193
L_194 ,
V_509 ) ;
}
goto V_169;
}
if ( V_8 -> V_366 -> V_159 < V_506 ) {
V_509 = - V_154 ;
if ( ! V_504 ) {
F_2 ( V_134 ,
L_195
L_196 ,
V_506 ,
V_8 -> V_366 -> V_159 ) ;
}
goto V_169;
}
}
if ( V_508 ) {
if ( ( V_8 -> V_367 -> V_509 != 0 ) &&
( V_8 -> V_367 -> V_509 != - V_133 ) &&
( V_8 -> V_367 -> V_509 != - V_523 ) &&
( V_8 -> V_367 -> V_509 != - V_524 ) ) {
V_509 = V_8 -> V_367 -> V_509 ;
if ( ! V_504 ) {
F_2 ( V_134 ,
L_197
L_194 ,
V_509 ) ;
}
goto V_169;
}
if ( V_8 -> V_367 -> V_159 < V_508 ) {
V_509 = - V_154 ;
if ( ! V_504 ) {
F_2 ( V_134 ,
L_198
L_196 ,
V_508 ,
V_8 -> V_367 -> V_159 ) ;
}
goto V_169;
}
for ( V_131 = 0 ; V_131 < V_508 ; V_131 ++ ) {
( ( unsigned char * ) V_507 ) [ V_131 ] =
V_8 -> V_365 [ V_131 ] ;
}
}
V_169:
V_8 -> V_514 = 0 ;
if ( ( V_509 < 0 ) && ( ! V_504 ) ) {
F_125 ( V_8 ) ;
}
return V_509 ;
}
int F_191 ( struct V_7 * V_8 ,
void * V_505 , unsigned int V_506 ,
void * V_507 , unsigned int V_508 )
{
return F_117 ( V_8 , V_152 * 4 , 0 ,
V_505 , V_506 ,
V_507 , V_508 ) ;
}
static int F_97 ( struct V_7 * V_8 , V_170 V_525 )
{
int V_59 ;
unsigned int V_140 = 1 ;
unsigned int args = 0 ;
F_106 ( V_8 -> V_202 ) ;
V_8 -> V_203 [ 0 ] = V_525 & 0xffu ;
args = ( V_525 >> 8 ) & 0xffu ;
args = ( args > 2 ) ? 2 : args ;
if ( args ) {
V_140 += args ;
V_8 -> V_203 [ 1 ] = ( V_525 >> 16 ) & 0xffu ;
if ( args > 1 ) {
V_8 -> V_203 [ 2 ] = ( V_525 >> 24 ) & 0xffu ;
}
}
if ( V_449 & V_205 ) {
unsigned int V_131 ;
unsigned int V_448 , V_157 ;
char V_526 [ 50 ] ;
V_525 &= 0xffu ;
V_157 = 0 ;
V_448 = F_132 ( V_526 + V_157 ,
sizeof( V_526 ) - V_157 ,
L_199 , V_525 ) ;
V_157 += V_448 ;
for ( V_131 = 0 ; V_131 < F_91 ( V_527 ) ; V_131 ++ ) {
if ( V_527 [ V_131 ] . V_66 == V_525 ) {
V_448 = F_132 ( V_526 + V_157 ,
sizeof( V_526 ) - V_157 ,
L_200 ,
V_527 [ V_131 ] . V_258 ) ;
V_157 += V_448 ;
break;
}
}
if ( args ) {
V_448 = F_132 ( V_526 + V_157 ,
sizeof( V_526 ) - V_157 ,
L_201 , V_8 -> V_203 [ 1 ] ) ;
V_157 += V_448 ;
if ( args > 1 ) {
V_448 = F_132 ( V_526 + V_157 ,
sizeof( V_526 ) - V_157 ,
L_202 , V_8 -> V_203 [ 2 ] ) ;
V_157 += V_448 ;
}
V_448 = F_132 ( V_526 + V_157 ,
sizeof( V_526 ) - V_157 ,
L_203 ) ;
V_157 += V_448 ;
}
F_2 ( V_205 , L_204 , V_157 , V_526 ) ;
}
V_59 = F_191 ( V_8 , V_8 -> V_203 , V_140 , NULL , 0 ) ;
F_107 ( V_8 -> V_202 ) ;
return V_59 ;
}
int F_93 ( struct V_7 * V_8 , T_2 V_528 , V_170 V_151 )
{
int V_59 ;
F_106 ( V_8 -> V_202 ) ;
V_8 -> V_203 [ 0 ] = V_529 ;
F_220 ( V_8 -> V_203 , 1 , V_151 ) ;
V_8 -> V_203 [ 5 ] = 0 ;
V_8 -> V_203 [ 6 ] = ( V_528 >> 8 ) & 0xff ;
V_8 -> V_203 [ 7 ] = V_528 & 0xff ;
V_59 = F_191 ( V_8 , V_8 -> V_203 , 8 , V_8 -> V_203 , 0 ) ;
F_107 ( V_8 -> V_202 ) ;
return V_59 ;
}
static int F_221 ( struct V_7 * V_8 , T_2 V_528 , V_170 * V_151 )
{
int V_59 = 0 ;
F_106 ( V_8 -> V_202 ) ;
V_8 -> V_203 [ 0 ] = V_530 ;
V_8 -> V_203 [ 1 ] = 0 ;
V_8 -> V_203 [ 2 ] = 0 ;
V_8 -> V_203 [ 3 ] = 0 ;
V_8 -> V_203 [ 4 ] = 0 ;
V_8 -> V_203 [ 5 ] = 0 ;
V_8 -> V_203 [ 6 ] = ( V_528 >> 8 ) & 0xff ;
V_8 -> V_203 [ 7 ] = V_528 & 0xff ;
V_59 |= F_191 ( V_8 , V_8 -> V_203 , 8 , V_8 -> V_203 , 4 ) ;
* V_151 = F_222 ( V_8 -> V_203 , 0 ) ;
F_107 ( V_8 -> V_202 ) ;
return V_59 ;
}
void F_125 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_373 ) return;
F_2 ( V_134 ,
L_205 ) ;
if ( V_8 -> V_276 ) {
F_135 ( V_8 -> V_276 , NULL , 0 , 0 ) ;
}
V_8 -> V_373 = 0 ;
F_1 ( L_206 , V_8 -> V_373 ) ;
F_108 ( V_8 ) ;
}
void F_223 ( struct V_7 * V_8 )
{
int V_59 ;
F_2 ( V_205 , L_207 ) ;
V_59 = F_224 ( V_8 -> V_118 , NULL ) ;
if ( V_59 == 0 ) {
V_59 = F_225 ( V_8 -> V_118 ) ;
F_226 ( V_8 -> V_118 ) ;
} else {
F_2 ( V_134 ,
L_208 , V_59 ) ;
}
if ( V_531 ) {
F_2 ( V_245 ,
L_209 ,
V_531 ) ;
F_227 ( V_531 ) ;
}
}
void F_87 ( struct V_7 * V_8 , int V_2 )
{
char * V_532 ;
unsigned int V_136 ;
int V_59 ;
if ( ! V_8 -> V_118 ) return;
V_532 = F_86 ( 16 , V_150 ) ;
if ( V_532 == NULL ) {
F_2 ( V_134 ,
L_210 ) ;
return;
}
F_2 ( V_205 , L_211 , V_2 ) ;
V_532 [ 0 ] = V_2 ? 0x01 : 0x00 ;
V_136 = F_84 ( V_8 -> V_118 , 0 ) ;
V_59 = F_88 ( V_8 -> V_118 , V_136 , 0xa0 , 0x40 , 0xe600 , 0 , V_532 , 1 , V_152 ) ;
if ( V_59 < 0 ) {
F_2 ( V_134 ,
L_212 , V_2 , V_59 ) ;
F_125 ( V_8 ) ;
}
F_89 ( V_532 ) ;
}
int F_96 ( struct V_7 * V_8 )
{
return F_97 ( V_8 , V_533 ) ;
}
int F_128 ( struct V_7 * V_8 )
{
return F_97 ( V_8 , V_534 ) ;
}
int F_228 ( struct V_7 * V_8 )
{
return F_97 ( V_8 , V_535 ) ;
}
int F_229 ( struct V_7 * V_8 )
{
F_2 ( V_205 ,
L_213 ) ;
if ( V_8 -> V_183 ) {
F_102 ( & V_8 -> V_179 , V_8 -> V_183 ,
V_265 , V_536 , 0 ) ;
F_120 ( V_8 ) ;
return 0 ;
}
F_2 ( V_205 ,
L_214 ) ;
return - V_143 ;
}
static int F_230 ( struct V_7 * V_8 , int V_537 )
{
V_8 -> V_373 = ! 0 ;
return F_97 ( V_8 ,
V_538 |
( 1 << 8 ) |
( ( V_537 ? 1 : 0 ) << 16 ) ) ;
}
static int F_231 ( struct V_7 * V_8 , int V_537 )
{
V_8 -> V_373 = ! 0 ;
return F_97 ( V_8 , ( V_537 ?
V_539 :
V_540 ) ) ;
}
static int F_232 ( struct V_7 * V_8 ,
int V_537 )
{
return F_97 ( V_8 , ( V_537 ?
V_541 :
V_542 ) ) ;
}
static void F_233 ( struct V_7 * V_8 , int V_543 )
{
int V_544 ;
V_544 = ( V_543 ? V_321 : V_320 ) ;
if ( V_544 == V_8 -> V_319 ) {
return;
}
switch ( V_8 -> V_43 -> V_310 ) {
case V_545 :
F_230 ( V_8 , V_543 ) ;
if ( V_544 == V_320 ) {
F_229 ( V_8 ) ;
}
break;
case V_546 :
F_231 ( V_8 , V_543 ) ;
break;
default: break;
}
F_104 ( V_8 ) ;
V_8 -> V_319 = V_544 ;
}
static void F_234 ( struct V_7 * V_8 , int V_537 )
{
if ( V_537 ) {
F_94 ( V_8 , 0xffffffff , 0x00000481 ) ;
} else {
F_94 ( V_8 , 0xffffffff , 0x00000401 ) ;
}
F_95 ( V_8 , 0xffffffff , 0x00000000 ) ;
}
static void F_235 ( struct V_7 * V_8 , int V_537 )
{
unsigned int V_547 ;
T_6 V_391 ;
if ( ( ! V_537 ) == ( ! V_8 -> V_548 ) ) return;
V_8 -> V_548 = V_537 != 0 ;
V_547 = V_8 -> V_43 -> V_549 ;
if ( V_547 < F_91 ( V_550 ) ) {
V_391 = V_550 [ V_547 ] ;
} else {
V_391 = NULL ;
}
if ( V_391 ) (* V_391)( V_8 , V_537 ) ;
}
static int F_236 ( struct V_7 * V_8 , int V_551 )
{
int V_59 ;
if ( V_8 -> V_319 == V_320 ) {
return F_97 ( V_8 ,
( V_551 ?
V_552 :
V_553 ) ) ;
}
if ( V_8 -> V_319 != V_321 ) {
return - V_106 ;
}
switch ( V_8 -> V_43 -> V_310 ) {
case V_545 :
return F_97 ( V_8 ,
( V_551 ?
V_554 :
V_555 ) ) ;
case V_546 :
V_59 = F_97 ( V_8 ,
( V_551 ?
V_552 :
V_553 ) ) ;
if ( V_59 ) return V_59 ;
return F_232 ( V_8 , V_551 ) ;
default:
return - V_106 ;
}
}
static int F_237 ( struct V_7 * V_8 )
{
if ( V_8 -> V_452 ) {
return 0 ;
}
if ( ! V_8 -> V_460 ) {
return 0 ;
}
F_233 ( V_8 , V_8 -> V_45 == V_312 ) ;
V_8 -> V_452 = ! 0 ;
F_1 ( L_161 , V_8 -> V_452 ) ;
return ! 0 ;
}
static int F_238 ( struct V_7 * V_8 )
{
if ( V_8 -> V_556 ) return 0 ;
if ( V_8 -> V_185 ) return 0 ;
if ( V_8 -> V_72 ) return 0 ;
if ( V_8 -> V_557 ) return 0 ;
if ( V_8 -> V_558 ) return 0 ;
if ( V_8 -> V_559 ) return 0 ;
if ( V_8 -> V_319 == V_321 ) {
if ( ! V_8 -> V_43 -> V_560 ) return 0 ;
} else if ( V_8 -> V_319 != V_320 ) {
return 0 ;
}
if ( F_90 ( V_8 ) < 0 ) {
V_8 -> V_185 = ! 0 ;
F_1 ( L_215 , V_8 -> V_185 ) ;
return ! 0 ;
}
V_8 -> V_556 = ! 0 ;
F_1 ( L_216 , V_8 -> V_556 ) ;
return ! 0 ;
}
static int F_239 ( struct V_7 * V_8 )
{
if ( V_8 -> V_557 ) {
if ( V_8 -> V_556 ) {
if ( V_8 -> V_81 &&
! V_8 -> V_461 ) return 0 ;
}
V_8 -> V_557 = 0 ;
V_8 -> V_561 = 0 ;
F_1 ( L_217 , V_8 -> V_561 ) ;
F_92 ( & V_8 -> V_303 ) ;
} else {
if ( ! V_8 -> V_452 ||
( V_8 -> V_319 != V_320 ) ||
! V_8 -> V_556 ||
! V_8 -> V_460 ||
V_8 -> V_461 ||
! V_8 -> V_81 ||
! V_8 -> V_194 ) {
if ( F_240 ( & V_8 -> V_303 ) ) {
F_92 ( & V_8 -> V_303 ) ;
}
if ( V_8 -> V_561 ) {
V_8 -> V_561 = 0 ;
F_1 ( L_217 ,
V_8 -> V_561 ) ;
return ! 0 ;
}
return 0 ;
}
if ( ! V_8 -> V_561 ) {
if ( ! F_240 ( & V_8 -> V_303 ) ) {
if ( ! V_8 -> V_561 ) {
V_8 -> V_303 . V_518 =
V_519 +
( V_152 * V_562
/ 1000 ) ;
F_218 ( & V_8 -> V_303 ) ;
}
}
return 0 ;
}
F_241 ( V_8 ) ;
if ( V_8 -> V_556 ) V_8 -> V_557 = ! 0 ;
}
F_1 ( L_218 , V_8 -> V_557 ) ;
return ! 0 ;
}
static int F_242 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_556 ) {
return ! 0 ;
}
if ( ! V_8 -> V_452 ) {
return ! 0 ;
}
switch ( V_8 -> V_319 ) {
case V_320 :
if ( ! V_8 -> V_558 ) {
return ! 0 ;
}
break;
case V_321 :
if ( V_8 -> V_166 ) {
return ! 0 ;
}
break;
default:
return ! 0 ;
}
return 0 ;
}
static int F_243 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_556 ) {
return 0 ;
}
if ( ! V_8 -> V_452 ) {
return 0 ;
}
switch ( V_8 -> V_319 ) {
case V_320 :
if ( V_8 -> V_558 && V_8 -> V_563 ) {
return ! 0 ;
}
break;
case V_321 :
if ( ( V_8 -> V_43 -> V_310 ==
V_546 ) &&
! V_8 -> V_166 ) {
return ! 0 ;
}
break;
default:
break;
}
return 0 ;
}
static int F_244 ( struct V_7 * V_8 )
{
if ( V_8 -> V_72 ) {
if ( ! F_242 ( V_8 ) ) return 0 ;
if ( V_8 -> V_556 ) {
F_92 ( & V_8 -> V_165 ) ;
if ( F_245 ( V_8 ) < 0 ) return ! 0 ;
}
V_8 -> V_72 = 0 ;
} else {
if ( ! F_243 ( V_8 ) ) return 0 ;
if ( F_246 ( V_8 ) < 0 ) return ! 0 ;
V_8 -> V_72 = ! 0 ;
if ( ! V_8 -> V_166 ) {
V_8 -> V_165 . V_518 =
V_519 + ( V_152 * V_564 / 1000 ) ;
F_218 ( & V_8 -> V_165 ) ;
}
}
F_1 ( L_219 , V_8 -> V_72 ) ;
return ! 0 ;
}
static void V_300 ( unsigned long V_151 )
{
struct V_7 * V_8 = (struct V_7 * ) V_151 ;
V_8 -> V_565 = ! 0 ;
F_1 ( L_220 , V_8 -> V_565 ) ;
V_8 -> V_467 = ! 0 ;
F_247 ( V_8 -> V_370 , & V_8 -> V_371 ) ;
}
static void V_302 ( unsigned long V_151 )
{
struct V_7 * V_8 = (struct V_7 * ) V_151 ;
V_8 -> V_563 = ! 0 ;
F_1 ( L_221 , V_8 -> V_563 ) ;
V_8 -> V_467 = ! 0 ;
F_247 ( V_8 -> V_370 , & V_8 -> V_371 ) ;
}
static void V_304 ( unsigned long V_151 )
{
struct V_7 * V_8 = (struct V_7 * ) V_151 ;
V_8 -> V_561 = ! 0 ;
F_1 ( L_217 , V_8 -> V_561 ) ;
V_8 -> V_467 = ! 0 ;
F_247 ( V_8 -> V_370 , & V_8 -> V_371 ) ;
}
static void V_305 ( unsigned long V_151 )
{
struct V_7 * V_8 = (struct V_7 * ) V_151 ;
if ( ! V_8 -> V_166 ) {
V_8 -> V_166 = ! 0 ;
F_1 ( L_33 , V_8 -> V_166 ) ;
V_8 -> V_467 = ! 0 ;
F_247 ( V_8 -> V_370 , & V_8 -> V_371 ) ;
}
}
static int F_248 ( struct V_7 * V_8 )
{
if ( V_8 -> V_558 ) {
if ( V_8 -> V_556 ) {
if ( V_8 -> V_81 &&
! V_8 -> V_461 &&
V_8 -> V_452 ) return 0 ;
}
if ( ! V_8 -> V_184 ) {
F_101 ( V_8 , 0 ) ;
}
V_8 -> V_565 = 0 ;
V_8 -> V_558 = 0 ;
F_92 ( & V_8 -> V_298 ) ;
F_92 ( & V_8 -> V_301 ) ;
V_8 -> V_563 = 0 ;
} else {
if ( ! V_8 -> V_565 ) {
if ( ! F_240 ( & V_8 -> V_298 ) ) {
if ( ! V_8 -> V_565 ) {
V_8 -> V_298 . V_518 =
V_519 +
( V_152 * V_566
/ 1000 ) ;
F_218 ( & V_8 -> V_298 ) ;
}
}
return 0 ;
}
if ( ! V_8 -> V_452 ||
( V_8 -> V_319 != V_320 ) ||
! V_8 -> V_81 ||
V_8 -> V_461 ||
! V_8 -> V_194 ||
! V_8 -> V_557 ||
! V_8 -> V_556 ) return 0 ;
F_92 ( & V_8 -> V_298 ) ;
if ( V_8 -> V_184 ) return 0 ;
if ( F_101 ( V_8 , ! 0 ) < 0 ) return 0 ;
V_8 -> V_565 = 0 ;
V_8 -> V_563 = 0 ;
V_8 -> V_558 = ! 0 ;
if ( V_8 -> V_183 == V_246 ) {
V_8 -> V_301 . V_518 =
V_519 +
( V_152 * V_567 /
1000 ) ;
F_218 ( & V_8 -> V_301 ) ;
} else {
V_8 -> V_563 = ! 0 ;
}
}
F_1 ( L_220 , V_8 -> V_565 ) ;
F_1 ( L_222 , V_8 -> V_558 ) ;
F_1 ( L_221 , V_8 -> V_563 ) ;
return ! 0 ;
}
static int F_249 ( struct V_7 * V_8 )
{
if ( V_8 -> V_559 ) {
int V_186 = ! 0 ;
if ( V_8 -> V_319 == V_320 ) {
V_186 = ( V_8 -> V_556 &&
V_8 -> V_72 ) ;
} else if ( ( V_8 -> V_319 == V_321 ) &&
( V_8 -> V_43 -> V_560 ) ) {
V_186 = V_8 -> V_556 ;
}
if ( V_186 &&
V_8 -> V_81 &&
! V_8 -> V_461 &&
V_8 -> V_452 ) {
return 0 ;
}
F_236 ( V_8 , 0 ) ;
V_8 -> V_559 = 0 ;
} else {
if ( ! V_8 -> V_81 ||
V_8 -> V_461 ||
! V_8 -> V_452 ) return 0 ;
if ( V_8 -> V_319 == V_320 ) {
if ( ! V_8 -> V_556 ||
! V_8 -> V_72 ) return 0 ;
} else if ( ( V_8 -> V_319 == V_321 ) &&
( V_8 -> V_43 -> V_560 ) ) {
if ( ! V_8 -> V_556 ) return 0 ;
if ( V_8 -> V_72 ) return 0 ;
if ( V_8 -> V_43 -> V_310 ==
V_546 ) {
if ( ! V_8 -> V_166 ) return 0 ;
}
}
if ( F_236 ( V_8 , ! 0 ) < 0 ) return 0 ;
V_8 -> V_559 = ! 0 ;
}
F_1 ( L_223 , V_8 -> V_559 ) ;
return ! 0 ;
}
static int F_250 ( struct V_7 * V_8 )
{
if ( V_8 -> V_194 ||
V_8 -> V_461 ) return 0 ;
F_180 ( V_8 ) ;
return ! 0 ;
}
static int F_251 ( struct V_7 * V_8 )
{
unsigned int V_175 ;
int V_568 = 0 ;
V_175 = ! ( V_8 -> V_72 ||
V_8 -> V_558 ||
V_8 -> V_559 ||
( ! V_8 -> V_565 ) ) ;
if ( ! V_175 != ! V_8 -> V_460 ) {
V_8 -> V_460 = V_175 ;
V_568 = ! 0 ;
}
if ( V_8 -> V_460 && V_8 -> V_461 ) {
V_8 -> V_461 = 0 ;
V_568 = ! 0 ;
}
return V_568 ;
}
static int F_252 ( struct V_7 * V_8 )
{
unsigned int V_383 ;
int V_569 = 0 ;
int V_570 ;
if ( ! V_8 -> V_467 ) return 0 ;
if ( ( V_8 -> V_141 != V_142 ) ||
! V_8 -> V_373 ) {
V_8 -> V_467 = 0 ;
return ! 0 ;
}
do {
V_570 = 0 ;
F_251 ( V_8 ) ;
for ( V_383 = 0 ; ( V_383 < F_91 ( V_571 ) ) && V_8 -> V_373 ; V_383 ++ ) {
if ( (* V_571 [ V_383 ])( V_8 ) ) {
V_570 = ! 0 ;
V_569 = ! 0 ;
F_251 ( V_8 ) ;
}
}
} while ( V_570 && V_8 -> V_373 );
V_8 -> V_467 = 0 ;
F_1 ( L_224 , V_8 -> V_467 ) ;
return V_569 ;
}
static unsigned int F_253 ( unsigned int V_89 ,
char * V_206 , unsigned int V_572 )
{
unsigned int V_131 , V_448 ;
unsigned int V_485 = 0 ;
for ( V_131 = 0 ; V_131 < F_91 ( V_573 ) ; V_131 ++ ) {
if ( ! ( ( 1 << V_131 ) & V_89 ) ) continue;
V_448 = F_132 ( V_206 + V_485 ,
V_572 - V_485 ,
L_225 ,
( V_485 ? L_226 : L_150 ) ,
V_573 [ V_131 ] ) ;
V_485 += V_448 ;
}
return V_485 ;
}
static const char * F_254 ( int V_66 )
{
switch ( V_66 ) {
case V_320 : return L_227 ;
case V_321 : return L_228 ;
default: return L_229 ;
}
}
static unsigned int F_255 ( struct V_7 * V_8 , int V_574 ,
char * V_206 , unsigned int V_572 )
{
switch ( V_574 ) {
case 0 :
return F_132 (
V_206 , V_572 ,
L_230 ,
( V_8 -> V_373 ? L_231 : L_232 ) ,
( V_8 -> V_278 ? L_233 : L_234 ) ,
( V_8 -> V_282 ? L_235 :
L_236 ) ,
( V_8 -> V_185 ? L_237 : L_150 ) ,
( V_8 -> V_184 ? L_238 : L_150 ) ,
F_254 ( V_8 -> V_319 ) ) ;
case 1 :
return F_132 (
V_206 , V_572 ,
L_239 ,
( V_8 -> V_460 ? L_240 : L_150 ) ,
( V_8 -> V_194 ?
L_241 : L_242 ) ,
( V_8 -> V_81 ? L_243 : L_150 ) ,
( V_8 -> V_461 ? L_244 : L_150 ) ) ;
case 2 :
return F_132 (
V_206 , V_572 ,
L_245 ,
( V_8 -> V_558 ?
( V_8 -> V_563 ?
L_246 : L_247 ) :
( V_8 -> V_565 ?
L_150 : L_248 ) ) ,
( V_8 -> V_565 ?
L_249 : L_150 ) ,
( V_8 -> V_556 ?
L_150 : L_250 ) ,
( V_8 -> V_72 ?
( V_8 -> V_166 ?
L_251 :
L_252 ) :
( V_8 -> V_166 ?
L_253 :
L_254 ) ) ,
( V_8 -> V_557 ?
L_255 :
( V_8 -> V_561 ?
L_150 : L_256 ) ) ,
( V_8 -> V_559 ?
L_257 : L_258 ) ,
( V_8 -> V_452 ?
L_259 : L_150 ) ) ;
case 3 :
return F_132 (
V_206 , V_572 ,
L_260 ,
F_100 ( V_8 -> V_82 ) ) ;
case 4 : {
unsigned int V_485 = 0 ;
unsigned int V_448 ;
V_448 = F_132 ( V_206 ,
V_572 ,
L_261 ) ;
V_485 += V_448 ;
V_485 += F_253 ( V_8 -> V_318 ,
V_206 + V_485 ,
V_572 - V_485 ) ;
if ( V_8 -> V_318 != V_8 -> V_46 ) {
V_448 = F_132 ( V_206 + V_485 ,
V_572 - V_485 ,
L_262 ) ;
V_485 += V_448 ;
V_485 += F_253 ( V_8 -> V_46 ,
V_206 + V_485 ,
V_572 - V_485 ) ;
}
return V_485 ;
}
case 5 : {
struct V_575 V_576 ;
if ( ! V_8 -> V_276 ) break;
F_256 ( V_8 -> V_276 ,
& V_576 ,
0 ) ;
return F_132 (
V_206 , V_572 ,
L_263
L_264
L_265 ,
V_576 . V_577 ,
V_576 . V_578 ,
V_576 . V_579 ,
V_576 . V_580 ,
V_576 . V_581 ,
V_576 . V_582 ) ;
}
case 6 : {
unsigned int V_66 = V_8 -> V_262 ;
return F_132 ( V_206 , V_572 , L_266 , V_66 ,
( V_66 >= F_91 ( V_583 ) ?
L_267 : V_583 [ V_66 ] ) ) ;
}
default: break;
}
return 0 ;
}
static unsigned int F_257 ( struct V_7 * V_8 ,
char * V_206 , unsigned int V_572 )
{
struct V_233 * V_234 ;
unsigned int V_485 = 0 ;
unsigned int V_448 ;
struct V_584 * V_585 ;
const char * V_236 ;
unsigned int V_66 ;
V_448 = F_132 ( V_206 , V_572 , L_268 ) ;
V_485 += V_448 ;
F_178 (sd, &hdw->v4l2_dev) {
V_66 = V_234 -> V_244 ;
V_236 = NULL ;
if ( V_66 < F_91 ( V_239 ) ) V_236 = V_239 [ V_66 ] ;
if ( V_236 ) {
V_448 = F_132 ( V_206 + V_485 , V_572 - V_485 , L_269 , V_236 ) ;
V_485 += V_448 ;
} else {
V_448 = F_132 ( V_206 + V_485 , V_572 - V_485 ,
L_270 , V_66 ) ;
V_485 += V_448 ;
}
V_585 = F_258 ( V_234 ) ;
if ( V_585 ) {
V_448 = F_132 ( V_206 + V_485 , V_572 - V_485 ,
L_271 , V_585 -> V_1 ,
V_585 -> V_394 ) ;
V_485 += V_448 ;
} else {
V_448 = F_132 ( V_206 + V_485 , V_572 - V_485 ,
L_272 ) ;
V_485 += V_448 ;
}
}
return V_485 ;
}
unsigned int F_259 ( struct V_7 * V_8 ,
char * V_206 , unsigned int V_572 )
{
unsigned int V_157 , V_448 , V_131 ;
V_157 = 0 ;
F_106 ( V_8 -> V_187 ) ;
for ( V_131 = 0 ; ; V_131 ++ ) {
V_448 = F_255 ( V_8 , V_131 , V_206 , V_572 ) ;
if ( ! V_448 ) break;
V_157 += V_448 ; V_572 -= V_448 ; V_206 += V_448 ;
if ( ! V_572 ) break;
V_206 [ 0 ] = '\n' ; V_448 = 1 ;
V_157 += V_448 ; V_572 -= V_448 ; V_206 += V_448 ;
}
V_448 = F_257 ( V_8 , V_206 , V_572 ) ;
V_157 += V_448 ; V_572 -= V_448 ; V_206 += V_448 ;
F_107 ( V_8 -> V_187 ) ;
return V_157 ;
}
static void F_199 ( struct V_7 * V_8 )
{
char V_206 [ 256 ] ;
unsigned int V_131 , V_448 ;
unsigned int V_586 , V_587 ;
for ( V_131 = 0 ; ; V_131 ++ ) {
V_448 = F_255 ( V_8 , V_131 , V_206 , sizeof( V_206 ) ) ;
if ( ! V_448 ) break;
F_197 ( V_475 L_273 , V_8 -> V_1 , V_448 , V_206 ) ;
}
V_448 = F_257 ( V_8 , V_206 , sizeof( V_206 ) ) ;
V_587 = 0 ;
while ( V_587 < V_448 ) {
V_586 = 0 ;
while ( ( V_586 + V_587 < V_448 ) && ( V_206 [ V_586 + V_587 ] != '\n' ) ) {
V_586 ++ ;
}
F_197 ( V_475 L_273 , V_8 -> V_1 , V_586 , V_206 + V_587 ) ;
V_587 += V_586 + 1 ;
}
}
static int F_186 ( struct V_7 * V_8 )
{
unsigned int V_175 ;
int V_569 = 0 ;
int V_588 = 0 ;
int V_589 ;
F_2 ( V_3 ,
L_274 ) ;
if ( V_449 & V_3 ) {
F_199 ( V_8 ) ;
}
V_569 = F_252 ( V_8 ) ;
V_589 = ( V_8 -> V_319 != V_321 ) ;
if ( ! V_8 -> V_373 ) {
V_175 = V_306 ;
} else if ( V_8 -> V_141 != V_142 ) {
V_175 = V_590 ;
} else if ( ( V_589 ||
V_8 -> V_43 -> V_560 ) &&
! V_8 -> V_556 ) {
V_175 = V_591 ;
} else if ( V_8 -> V_185 ||
( V_589 && V_8 -> V_184 ) ) {
V_175 = V_592 ;
} else if ( V_8 -> V_559 &&
( ! V_589 ||
( V_8 -> V_72 && V_8 -> V_558 ) ) ) {
V_175 = V_190 ;
} else {
V_175 = V_191 ;
}
if ( V_8 -> V_82 != V_175 ) {
F_2 ( V_593 ,
L_275 ,
F_100 ( V_8 -> V_82 ) ,
F_100 ( V_175 ) ) ;
F_235 ( V_8 , V_175 == V_190 ) ;
V_8 -> V_82 = V_175 ;
V_569 = ! 0 ;
V_588 = ! 0 ;
}
if ( V_569 ) {
F_260 ( & V_8 -> V_307 ) ;
}
if ( V_449 & V_3 ) {
F_199 ( V_8 ) ;
}
F_2 ( V_3 ,
L_276 , V_588 ) ;
return V_588 ;
}
static void F_108 ( struct V_7 * V_8 )
{
if ( V_8 -> V_467 ) return;
V_8 -> V_467 = ! 0 ;
F_1 ( L_224 , V_8 -> V_467 ) ;
F_247 ( V_8 -> V_370 , & V_8 -> V_371 ) ;
}
int F_261 ( struct V_7 * V_8 , V_170 * V_594 )
{
return F_221 ( V_8 , V_595 , V_594 ) ;
}
int F_182 ( struct V_7 * V_8 , V_170 * V_594 )
{
return F_221 ( V_8 , V_596 , V_594 ) ;
}
int F_262 ( struct V_7 * V_8 , V_170 * V_594 )
{
return F_221 ( V_8 , V_597 , V_594 ) ;
}
int F_94 ( struct V_7 * V_8 , V_170 V_89 , V_170 V_2 )
{
V_170 V_598 , V_599 ;
int V_59 ;
if ( ~ V_89 ) {
V_59 = F_221 ( V_8 , V_595 , & V_598 ) ;
if ( V_59 ) return V_59 ;
V_599 = ( V_598 & ~ V_89 ) | ( V_2 & V_89 ) ;
F_2 ( V_600 ,
L_277
L_278 ,
V_89 , V_2 , V_598 , V_599 ) ;
} else {
V_599 = V_2 ;
F_2 ( V_600 ,
L_279 , V_599 ) ;
}
return F_93 ( V_8 , V_595 , V_599 ) ;
}
int F_95 ( struct V_7 * V_8 , V_170 V_89 , V_170 V_2 )
{
V_170 V_598 , V_599 ;
int V_59 ;
if ( ~ V_89 ) {
V_59 = F_221 ( V_8 , V_596 , & V_598 ) ;
if ( V_59 ) return V_59 ;
V_599 = ( V_598 & ~ V_89 ) | ( V_2 & V_89 ) ;
F_2 ( V_600 ,
L_280 ,
V_89 , V_2 , V_598 , V_599 ) ;
} else {
V_599 = V_2 ;
F_2 ( V_600 ,
L_281 , V_599 ) ;
}
return F_93 ( V_8 , V_596 , V_599 ) ;
}
void F_41 ( struct V_7 * V_8 )
{
struct V_422 * V_471 = & V_8 -> V_50 ;
memset ( V_471 , 0 , sizeof( * V_471 ) ) ;
V_471 -> type = ( V_8 -> V_45 == V_124 ) ?
V_424 : V_425 ;
V_8 -> V_49 = 0 ;
F_102 ( & V_8 -> V_179 , 0 , V_197 , V_601 , V_471 ) ;
F_2 ( V_178 , L_282
L_283
L_284 ,
V_471 -> type ,
V_471 -> signal , V_471 -> V_97 , V_471 -> V_53 ,
V_471 -> V_55 , V_471 -> V_51 ) ;
V_8 -> V_359 = 0 ;
}
unsigned int F_263 ( struct V_7 * V_8 )
{
return V_8 -> V_318 ;
}
unsigned int F_264 ( struct V_7 * V_8 )
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
int F_265 ( struct V_7 * V_8 ,
unsigned int V_602 ,
unsigned int V_603 )
{
int V_59 = 0 ;
unsigned int V_604 , V_12 , V_131 ;
F_106 ( V_8 -> V_187 ) ;
do {
V_604 = V_8 -> V_46 & ~ V_602 ;
V_604 |= ( V_603 & V_602 ) ;
V_604 &= V_8 -> V_318 ;
if ( ! V_604 ) {
V_59 = - V_605 ;
break;
}
V_8 -> V_46 = V_604 ;
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
F_107 ( V_8 -> V_187 ) ;
return V_59 ;
}
static int F_130 ( struct V_7 * V_8 )
{
int V_83 ;
F_106 ( V_8 -> V_202 ) ; do {
V_8 -> V_203 [ 0 ] = V_204 ;
V_83 = F_191 ( V_8 ,
V_8 -> V_203 , 1 ,
V_8 -> V_203 , 1 ) ;
if ( V_83 < 0 ) break;
V_83 = V_8 -> V_203 [ 0 ] ;
} while( 0 ); F_107 ( V_8 -> V_202 ) ;
return V_83 ;
}
int F_266 ( struct V_7 * V_8 ,
struct V_606 * V_607 , T_7 V_608 ,
int V_609 , T_7 * V_610 )
{
#ifdef F_267
struct V_611 V_612 ;
int V_24 = 0 ;
int V_251 = 0 ;
if ( ! F_268 ( V_613 ) ) return - V_605 ;
V_612 . V_607 = * V_607 ;
V_612 . V_528 = V_608 ;
if ( V_609 ) V_612 . V_2 = * V_610 ;
F_102 ( & V_8 -> V_179 , 0 , V_265 , V_614 , & V_612 ) ;
if ( ! V_609 ) * V_610 = V_612 . V_2 ;
if ( V_251 ) {
return V_24 ;
}
return - V_106 ;
#else
return - V_615 ;
#endif
}

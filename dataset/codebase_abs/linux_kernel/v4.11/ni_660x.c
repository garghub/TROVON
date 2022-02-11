static void F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 , unsigned int V_5 )
{
unsigned int V_6 = ( V_3 * V_7 ) +
V_8 [ V_5 ] . V_9 ;
if ( V_8 [ V_5 ] . V_10 == 2 )
F_2 ( V_4 , V_2 -> V_11 + V_6 ) ;
else
F_3 ( V_4 , V_2 -> V_11 + V_6 ) ;
}
static unsigned int F_4 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_5 )
{
unsigned int V_6 = ( V_3 * V_7 ) +
V_8 [ V_5 ] . V_9 ;
if ( V_8 [ V_5 ] . V_10 == 2 )
return F_5 ( V_2 -> V_11 + V_6 ) ;
return F_6 ( V_2 -> V_11 + V_6 ) ;
}
static void F_7 ( struct V_12 * V_13 , unsigned int V_4 ,
enum V_14 V_5 )
{
struct V_1 * V_2 = V_13 -> V_15 -> V_2 ;
F_1 ( V_2 , V_13 -> V_16 , V_4 , V_5 ) ;
}
static unsigned int F_8 ( struct V_12 * V_13 ,
enum V_14 V_5 )
{
struct V_1 * V_2 = V_13 -> V_15 -> V_2 ;
return F_4 ( V_2 , V_13 -> V_16 , V_5 ) ;
}
static inline void F_9 ( struct V_1 * V_2 ,
unsigned int V_17 ,
struct V_12 * V_13 )
{
struct V_18 * V_19 = V_2 -> V_20 ;
unsigned int V_3 = V_13 -> V_16 ;
V_19 -> V_21 [ V_3 ] &= ~ F_10 ( V_17 ) ;
V_19 -> V_21 [ V_3 ] |= F_11 ( V_17 ,
V_13 -> V_22 ) ;
F_1 ( V_2 , V_3 , V_19 -> V_21 [ V_3 ] |
F_12 ( V_17 ) ,
V_23 ) ;
F_13 () ;
}
static inline void F_14 ( struct V_1 * V_2 ,
unsigned int V_17 ,
struct V_12 * V_13 )
{
struct V_18 * V_19 = V_2 -> V_20 ;
unsigned int V_3 = V_13 -> V_16 ;
V_19 -> V_21 [ V_3 ] &= ~ F_10 ( V_17 ) ;
V_19 -> V_21 [ V_3 ] |= F_15 ( V_17 ) ;
F_1 ( V_2 , V_3 , V_19 -> V_21 [ V_3 ] , V_23 ) ;
F_13 () ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
enum V_24 V_25 )
{
struct V_18 * V_19 = V_2 -> V_20 ;
struct V_26 * V_27 ;
struct V_17 * V_28 ;
unsigned long V_29 ;
F_17 ( & V_19 -> V_30 , V_29 ) ;
V_27 = V_19 -> V_27 [ V_13 -> V_16 ] [ V_13 -> V_22 ] ;
V_28 = F_18 ( V_19 -> V_31 , V_27 ) ;
if ( ! V_28 ) {
F_19 ( & V_19 -> V_30 , V_29 ) ;
F_20 ( V_2 -> V_32 ,
L_1 ) ;
return - V_33 ;
}
V_28 -> V_34 = V_25 ;
F_21 ( V_13 , V_28 ) ;
F_9 ( V_2 , V_28 -> V_35 , V_13 ) ;
F_19 ( & V_19 -> V_30 , V_29 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_18 * V_19 = V_2 -> V_20 ;
unsigned long V_29 ;
F_17 ( & V_19 -> V_30 , V_29 ) ;
if ( V_13 -> V_28 ) {
struct V_17 * V_28 = V_13 -> V_28 ;
F_14 ( V_2 , V_28 -> V_35 , V_13 ) ;
F_21 ( V_13 , NULL ) ;
F_23 ( V_28 ) ;
}
F_19 ( & V_19 -> V_30 , V_29 ) ;
}
static int F_24 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
struct V_12 * V_13 = V_37 -> V_20 ;
int V_38 ;
V_38 = F_16 ( V_2 , V_13 , V_39 ) ;
if ( V_38 ) {
F_20 ( V_2 -> V_32 ,
L_2 ) ;
return V_38 ;
}
F_25 ( V_13 ) ;
return F_26 ( V_2 , V_37 ) ;
}
static int F_27 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
struct V_12 * V_13 = V_37 -> V_20 ;
int V_38 ;
V_38 = F_28 ( V_13 ) ;
F_22 ( V_2 , V_13 ) ;
return V_38 ;
}
static void F_29 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_4 = 0 ;
if ( V_3 )
V_4 = V_40 ;
F_1 ( V_2 , V_3 , V_4 , V_41 ) ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
struct V_12 * V_13 = V_37 -> V_20 ;
F_31 ( V_13 , V_37 ) ;
F_32 ( V_2 , V_37 ) ;
}
static T_1 F_33 ( int V_42 , void * V_43 )
{
struct V_1 * V_2 = V_43 ;
struct V_18 * V_19 = V_2 -> V_20 ;
struct V_36 * V_37 ;
unsigned int V_44 ;
unsigned long V_29 ;
if ( ! V_2 -> V_45 )
return V_46 ;
F_34 () ;
F_17 ( & V_19 -> V_47 , V_29 ) ;
for ( V_44 = 0 ; V_44 < V_2 -> V_48 ; ++ V_44 ) {
V_37 = & V_2 -> V_49 [ V_44 ] ;
if ( V_37 -> type == V_50 )
F_30 ( V_2 , V_37 ) ;
}
F_19 ( & V_19 -> V_47 , V_29 ) ;
return V_51 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
struct V_18 * V_19 = V_2 -> V_20 ;
struct V_12 * V_13 = V_37 -> V_20 ;
unsigned long V_29 ;
F_17 ( & V_19 -> V_47 , V_29 ) ;
F_36 ( V_13 -> V_28 , V_37 ) ;
F_19 ( & V_19 -> V_47 , V_29 ) ;
return F_37 ( V_37 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
struct V_18 * V_19 = V_2 -> V_20 ;
struct V_12 * V_13 = V_37 -> V_20 ;
struct V_26 * V_27 ;
int V_52 ;
V_27 = V_19 -> V_27 [ V_13 -> V_16 ] [ V_13 -> V_22 ] ;
V_52 = F_39 ( V_27 , V_37 ) ;
if ( V_52 < 0 )
return V_52 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_18 * V_19 ;
unsigned int V_44 ;
V_19 = F_41 ( V_2 , sizeof( * V_19 ) ) ;
if ( ! V_19 )
return - V_53 ;
F_42 ( & V_19 -> V_30 ) ;
F_42 ( & V_19 -> V_47 ) ;
for ( V_44 = 0 ; V_44 < V_54 ; ++ V_44 )
V_19 -> V_55 [ V_44 ] = V_56 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
const struct V_57 * V_58 = V_2 -> V_59 ;
struct V_18 * V_19 = V_2 -> V_20 ;
unsigned int V_44 ;
unsigned int V_60 ;
for ( V_44 = 0 ; V_44 < V_58 -> V_61 ; ++ V_44 ) {
for ( V_60 = 0 ; V_60 < V_62 ; ++ V_60 ) {
V_19 -> V_27 [ V_44 ] [ V_60 ] = F_44 ( V_19 -> V_31 ) ;
if ( ! V_19 -> V_27 [ V_44 ] [ V_60 ] )
return - V_53 ;
}
}
return 0 ;
}
static void F_45 ( struct V_1 * V_2 )
{
const struct V_57 * V_58 = V_2 -> V_59 ;
struct V_18 * V_19 = V_2 -> V_20 ;
unsigned int V_44 ;
unsigned int V_60 ;
for ( V_44 = 0 ; V_44 < V_58 -> V_61 ; ++ V_44 ) {
for ( V_60 = 0 ; V_60 < V_62 ; ++ V_60 )
F_46 ( V_19 -> V_27 [ V_44 ] [ V_60 ] ) ;
}
}
static int F_47 ( struct V_1 * V_2 ,
struct V_36 * V_37 ,
struct V_63 * V_64 ,
unsigned int * V_65 )
{
unsigned int V_66 = F_48 ( V_64 -> V_67 ) ;
unsigned int V_68 = V_65 [ 0 ] << V_66 ;
unsigned int V_4 = V_65 [ 1 ] << V_66 ;
if ( V_68 ) {
V_37 -> V_69 &= ~ V_68 ;
V_37 -> V_69 |= ( V_4 & V_68 ) ;
F_1 ( V_2 , 0 , V_37 -> V_69 , V_70 ) ;
}
V_65 [ 1 ] = F_4 ( V_2 , 0 , V_71 ) >> V_66 ;
return V_64 -> V_72 ;
}
static void F_49 ( struct V_1 * V_2 ,
unsigned int V_73 , unsigned int V_74 )
{
const struct V_57 * V_58 = V_2 -> V_59 ;
unsigned int V_75 = 0 ;
unsigned int V_76 = 0 ;
unsigned int V_4 ;
if ( V_58 -> V_61 > 1 ) {
if ( V_74 == V_56 &&
V_73 >= 8 && V_73 <= 23 ) {
V_75 = 1 ;
V_76 = 0 ;
} else {
V_75 = 0 ;
V_76 = 1 ;
}
}
if ( V_76 != V_75 ) {
V_4 = F_4 ( V_2 , V_76 , F_50 ( V_73 ) ) ;
V_4 &= ~ F_51 ( V_73 ) ;
V_4 |= F_52 ( V_73 , 0 ) ;
F_1 ( V_2 , V_76 , V_4 , F_50 ( V_73 ) ) ;
}
V_4 = F_4 ( V_2 , V_75 , F_50 ( V_73 ) ) ;
V_4 &= ~ F_51 ( V_73 ) ;
V_4 |= F_52 ( V_73 , V_74 ) ;
F_1 ( V_2 , V_75 , V_4 , F_50 ( V_73 ) ) ;
}
static int F_53 ( struct V_1 * V_2 ,
unsigned int V_73 , unsigned int V_77 )
{
struct V_18 * V_19 = V_2 -> V_20 ;
switch ( V_77 ) {
case V_56 :
if ( V_73 < 8 )
return - V_78 ;
break;
case V_79 :
if ( V_73 > 31 )
return - V_78 ;
default:
return - V_78 ;
}
V_19 -> V_55 [ V_73 ] = V_77 ;
if ( V_19 -> V_80 & ( 1ULL << V_73 ) )
F_49 ( V_2 , V_73 , V_19 -> V_55 [ V_73 ] ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_36 * V_37 ,
struct V_63 * V_64 ,
unsigned int * V_65 )
{
struct V_18 * V_19 = V_2 -> V_20 ;
unsigned int V_73 = F_48 ( V_64 -> V_67 ) ;
T_2 V_81 = 1ULL << V_73 ;
unsigned int V_82 ;
int V_52 ;
switch ( V_65 [ 0 ] ) {
case V_83 :
V_19 -> V_80 |= V_81 ;
F_49 ( V_2 , V_73 , V_19 -> V_55 [ V_73 ] ) ;
break;
case V_84 :
V_19 -> V_80 &= ~ V_81 ;
F_49 ( V_2 , V_73 , 0 ) ;
break;
case V_85 :
V_65 [ 1 ] = ( V_19 -> V_80 & V_81 ) ? V_86
: V_39 ;
break;
case V_87 :
V_52 = F_53 ( V_2 , V_73 , V_65 [ 1 ] ) ;
if ( V_52 )
return V_52 ;
break;
case V_88 :
V_65 [ 1 ] = V_19 -> V_55 [ V_73 ] ;
break;
case V_89 :
V_82 = F_4 ( V_2 , 0 , F_50 ( V_73 ) ) ;
V_82 &= ~ F_55 ( V_73 ) ;
V_82 |= F_56 ( V_73 , V_65 [ 1 ] ) ;
F_1 ( V_2 , 0 , V_82 , F_50 ( V_73 ) ) ;
break;
default:
return - V_78 ;
}
return V_64 -> V_72 ;
}
static void F_57 ( struct V_1 * V_2 ,
unsigned int V_61 )
{
struct V_18 * V_19 = V_2 -> V_20 ;
unsigned int V_3 ;
unsigned int V_73 ;
F_1 ( V_2 , 0 , 0 , V_90 ) ;
for ( V_3 = 0 ; V_3 < V_61 ; ++ V_3 ) {
V_19 -> V_21 [ V_3 ] = 0 ;
for ( V_73 = 0 ; V_73 < V_91 ; ++ V_73 )
V_19 -> V_21 [ V_3 ] |= F_15 ( V_73 ) ;
F_1 ( V_2 , V_3 , V_19 -> V_21 [ V_3 ] ,
V_23 ) ;
for ( V_73 = 0 ; V_73 < V_54 ; ++ V_73 )
F_1 ( V_2 , V_3 , 0 , F_50 ( V_73 ) ) ;
}
}
static int F_58 ( struct V_1 * V_2 ,
unsigned long V_92 )
{
struct V_93 * V_94 = F_59 ( V_2 ) ;
const struct V_57 * V_58 = NULL ;
struct V_18 * V_19 ;
struct V_36 * V_37 ;
struct V_95 * V_96 ;
unsigned int V_97 ;
int V_98 ;
int V_52 ;
unsigned int V_44 ;
unsigned int V_99 ;
if ( V_92 < F_60 ( V_100 ) )
V_58 = & V_100 [ V_92 ] ;
if ( ! V_58 )
return - V_101 ;
V_2 -> V_59 = V_58 ;
V_2 -> V_102 = V_58 -> V_103 ;
V_52 = F_61 ( V_2 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_40 ( V_2 ) ;
if ( V_52 < 0 )
return V_52 ;
V_19 = V_2 -> V_20 ;
V_19 -> V_31 = F_62 ( V_2 , true ) ;
if ( ! V_19 -> V_31 )
return - V_53 ;
V_52 = F_43 ( V_2 ) ;
if ( V_52 < 0 )
return V_52 ;
F_57 ( V_2 , V_58 -> V_61 ) ;
V_97 = V_58 -> V_61 * V_62 ;
V_96 = F_63 ( V_2 ,
F_7 ,
F_8 ,
V_104 ,
V_97 ) ;
if ( ! V_96 )
return - V_53 ;
V_19 -> V_15 = V_96 ;
V_52 = F_64 ( V_2 , 2 + V_105 ) ;
if ( V_52 )
return V_52 ;
V_98 = 0 ;
V_37 = & V_2 -> V_49 [ V_98 ++ ] ;
V_37 -> type = V_106 ;
V_37 = & V_2 -> V_49 [ V_98 ++ ] ;
V_37 -> type = V_107 ;
V_37 -> V_108 = V_109 | V_110 ;
V_37 -> V_111 = V_54 ;
V_37 -> V_112 = 1 ;
V_37 -> V_113 = & V_114 ;
V_37 -> V_115 = F_47 ;
V_37 -> V_116 = F_54 ;
for ( V_44 = 0 ; V_44 < V_37 -> V_111 ; ++ V_44 ) {
unsigned int V_77 = ( V_44 < 8 ) ? V_79
: V_56 ;
F_53 ( V_2 , V_44 , V_77 ) ;
F_49 ( V_2 , V_44 , 0 ) ;
}
for ( V_44 = 0 ; V_44 < V_105 ; ++ V_44 ) {
V_37 = & V_2 -> V_49 [ V_98 ++ ] ;
if ( V_44 < V_97 ) {
struct V_12 * V_13 = & V_96 -> V_117 [ V_44 ] ;
V_13 -> V_16 = V_44 / V_62 ;
V_13 -> V_22 = V_44 % V_62 ;
V_37 -> type = V_50 ;
V_37 -> V_108 = V_109 | V_110 |
V_118 | V_119 ;
V_37 -> V_111 = 3 ;
V_37 -> V_112 = 0xffffffff ;
V_37 -> V_120 = V_121 ;
V_37 -> V_122 = V_123 ;
V_37 -> V_116 = V_124 ;
V_37 -> V_125 = 1 ;
V_37 -> V_126 = F_24 ;
V_37 -> V_127 = V_128 ;
V_37 -> V_129 = F_27 ;
V_37 -> V_130 = F_35 ;
V_37 -> V_131 = F_38 ;
V_37 -> V_132 = V_133 ;
V_37 -> V_20 = V_13 ;
F_65 ( V_13 ) ;
} else {
V_37 -> type = V_106 ;
}
}
for ( V_44 = 0 ; V_44 < V_58 -> V_61 ; ++ V_44 )
F_29 ( V_2 , V_44 ) ;
V_52 = F_66 ( V_94 -> V_42 , F_33 , V_134 ,
V_2 -> V_102 , V_2 ) ;
if ( V_52 < 0 ) {
F_67 ( V_2 -> V_32 , L_3 ) ;
return V_52 ;
}
V_2 -> V_42 = V_94 -> V_42 ;
V_99 = V_135 ;
if ( V_58 -> V_61 > 1 )
V_99 |= V_136 ;
F_1 ( V_2 , 0 , V_99 ,
V_137 ) ;
return 0 ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_20 ;
if ( V_2 -> V_42 ) {
F_1 ( V_2 , 0 , 0 , V_137 ) ;
F_69 ( V_2 -> V_42 , V_2 ) ;
}
if ( V_19 ) {
F_70 ( V_19 -> V_15 ) ;
F_45 ( V_2 ) ;
F_71 ( V_19 -> V_31 ) ;
}
if ( V_2 -> V_11 )
F_72 ( V_2 -> V_11 ) ;
F_73 ( V_2 ) ;
}
static int F_74 ( struct V_93 * V_2 ,
const struct V_138 * V_139 )
{
return F_75 ( V_2 , & V_140 , V_139 -> V_141 ) ;
}

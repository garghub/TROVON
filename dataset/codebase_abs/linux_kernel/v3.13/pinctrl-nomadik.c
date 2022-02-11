static void F_1 ( struct V_1 * V_2 ,
unsigned V_3 , int V_4 )
{
T_1 V_5 = 1 << V_3 ;
T_1 V_6 , V_7 ;
V_6 = F_2 ( V_2 -> V_8 + V_9 ) & ~ V_5 ;
V_7 = F_2 ( V_2 -> V_8 + V_10 ) & ~ V_5 ;
if ( V_4 & V_11 )
V_6 |= V_5 ;
if ( V_4 & V_12 )
V_7 |= V_5 ;
F_3 ( V_6 , V_2 -> V_8 + V_9 ) ;
F_3 ( V_7 , V_2 -> V_8 + V_10 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
unsigned V_3 , enum V_13 V_14 )
{
T_1 V_5 = 1 << V_3 ;
T_1 V_15 ;
V_15 = F_2 ( V_2 -> V_8 + V_16 ) ;
if ( V_14 == V_17 )
V_15 |= V_5 ;
else
V_15 &= ~ V_5 ;
F_3 ( V_15 , V_2 -> V_8 + V_16 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
unsigned V_3 , enum V_18 V_19 )
{
T_1 V_5 = 1 << V_3 ;
T_1 V_20 ;
V_20 = F_2 ( V_2 -> V_8 + V_21 ) ;
if ( V_19 == V_22 ) {
V_20 |= V_5 ;
V_2 -> V_23 &= ~ V_5 ;
} else {
V_20 &= ~ V_5 ;
}
F_3 ( V_20 , V_2 -> V_8 + V_21 ) ;
if ( V_19 == V_24 ) {
V_2 -> V_23 |= V_5 ;
F_3 ( V_5 , V_2 -> V_8 + V_25 ) ;
} else if ( V_19 == V_26 ) {
V_2 -> V_23 &= ~ V_5 ;
F_3 ( V_5 , V_2 -> V_8 + V_27 ) ;
}
}
static void F_6 ( struct V_1 * V_2 ,
unsigned V_3 , bool V_28 )
{
T_1 V_5 = F_7 ( V_3 ) ;
bool V_29 = V_2 -> V_28 & V_5 ;
if ( V_28 == V_29 )
return;
if ( V_28 )
V_2 -> V_28 |= V_5 ;
else
V_2 -> V_28 &= ~ V_5 ;
F_8 ( V_2 -> V_28 ,
V_2 -> V_8 + V_30 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
unsigned V_3 )
{
F_3 ( 1 << V_3 , V_2 -> V_8 + V_31 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
unsigned V_3 , int V_32 )
{
if ( V_32 )
F_3 ( 1 << V_3 , V_2 -> V_8 + V_25 ) ;
else
F_3 ( 1 << V_3 , V_2 -> V_8 + V_27 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
unsigned V_3 , int V_32 )
{
F_3 ( 1 << V_3 , V_2 -> V_8 + V_33 ) ;
F_10 ( V_2 , V_3 , V_32 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
unsigned V_3 , int V_4 ,
bool V_34 )
{
T_1 V_35 = V_2 -> V_35 ;
T_1 V_36 = V_2 -> V_36 ;
if ( V_34 && V_2 -> V_37 ) {
T_1 V_5 = F_7 ( V_3 ) ;
F_3 ( V_35 & ~ V_5 , V_2 -> V_8 + V_38 ) ;
F_3 ( V_36 & ~ V_5 , V_2 -> V_8 + V_39 ) ;
V_2 -> V_37 ( true ) ;
}
F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_34 && V_2 -> V_37 ) {
V_2 -> V_37 ( false ) ;
F_3 ( V_35 , V_2 -> V_8 + V_38 ) ;
F_3 ( V_36 , V_2 -> V_8 + V_39 ) ;
}
}
static void
F_13 ( struct V_1 * V_2 , unsigned V_3 )
{
T_1 V_40 = V_2 -> V_41 & F_7 ( V_3 ) ;
T_1 V_42 = V_2 -> V_43 & F_7 ( V_3 ) ;
int V_44 = V_2 -> V_45 . V_46 + V_3 ;
int V_47 = F_14 ( V_2 -> V_48 , V_3 ) ;
struct V_49 * V_50 = F_15 ( V_47 ) ;
if ( ! V_42 && ! V_40 )
return;
if ( ! V_50 || ! F_16 ( V_50 ) )
return;
if ( V_42 ) {
V_2 -> V_43 &= ~ F_7 ( V_3 ) ;
F_8 ( V_2 -> V_43 ,
V_2 -> V_8 + V_51 ) ;
}
if ( V_40 ) {
V_2 -> V_41 &= ~ F_7 ( V_3 ) ;
F_8 ( V_2 -> V_41 ,
V_2 -> V_8 + V_52 ) ;
}
F_17 ( V_2 -> V_45 . V_53 , L_1 , V_44 ) ;
}
static void F_18 ( void T_2 * V_54 , T_1 V_55 , T_1 V_56 )
{
T_1 V_32 ;
V_32 = F_2 ( V_54 ) ;
V_32 = ( ( V_32 & ~ V_55 ) | ( V_56 & V_55 ) ) ;
F_3 ( V_32 , V_54 ) ;
}
static void F_19 ( struct V_57 * V_58 ,
unsigned V_3 , unsigned V_59 )
{
int V_60 ;
T_3 V_54 ;
T_4 V_5 ;
T_4 V_61 ;
const struct V_62 * V_63 ;
const T_3 * V_64 ;
if ( ! V_58 -> V_65 )
return;
if ( V_59 > V_66 ) {
F_20 ( V_58 -> V_53 , L_2 ,
V_59 ) ;
return;
}
for ( V_60 = 0 ; V_60 < V_58 -> V_67 -> V_68 ; V_60 ++ ) {
if ( V_58 -> V_67 -> V_69 [ V_60 ] . V_70 == V_3 )
break;
}
if ( V_60 == V_58 -> V_67 -> V_68 ) {
F_17 ( V_58 -> V_53 , L_3 ,
V_3 ) ;
return;
}
V_63 = V_58 -> V_67 -> V_69 + V_60 ;
V_64 = V_58 -> V_67 -> V_71 ;
if ( ! V_59 ) {
for ( V_60 = 0 ; V_60 < V_66 ; V_60 ++ ) {
if ( V_63 -> V_72 [ V_60 ] . V_73 == true ) {
V_54 = V_64 [ V_63 -> V_72 [ V_60 ] . V_74 ] ;
V_5 = V_63 -> V_72 [ V_60 ] . V_75 ;
if ( F_2 ( V_58 -> V_65 + V_54 ) & F_7 ( V_5 ) ) {
F_18 ( V_58 -> V_65 + V_54 , F_7 ( V_5 ) , 0 ) ;
F_17 ( V_58 -> V_53 ,
L_4 ,
V_3 , V_60 + 1 ) ;
}
}
}
return;
}
V_61 = V_59 - 1 ;
if ( V_63 -> V_72 [ V_61 ] . V_73 == false ) {
F_21 ( V_58 -> V_53 ,
L_5 ,
V_3 , V_59 ) ;
return;
}
for ( V_60 = 0 ; V_60 < V_66 ; V_60 ++ ) {
if ( V_60 == V_61 )
continue;
if ( V_63 -> V_72 [ V_60 ] . V_73 == true ) {
V_54 = V_64 [ V_63 -> V_72 [ V_60 ] . V_74 ] ;
V_5 = V_63 -> V_72 [ V_60 ] . V_75 ;
if ( F_2 ( V_58 -> V_65 + V_54 ) & F_7 ( V_5 ) ) {
F_18 ( V_58 -> V_65 + V_54 , F_7 ( V_5 ) , 0 ) ;
F_17 ( V_58 -> V_53 ,
L_4 ,
V_3 , V_60 + 1 ) ;
}
}
}
V_54 = V_64 [ V_63 -> V_72 [ V_61 ] . V_74 ] ;
V_5 = V_63 -> V_72 [ V_61 ] . V_75 ;
F_17 ( V_58 -> V_53 , L_6 ,
V_3 , V_61 + 1 ) ;
F_18 ( V_58 -> V_65 + V_54 , F_7 ( V_5 ) , F_7 ( V_5 ) ) ;
}
static void F_22 ( unsigned int * V_15 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_76 ; V_60 ++ ) {
struct V_1 * V_45 = V_77 [ V_60 ] ;
unsigned int V_78 = V_15 [ V_60 ] ;
if ( ! V_45 )
break;
F_23 ( V_45 -> V_79 ) ;
V_15 [ V_60 ] = F_2 ( V_45 -> V_8 + V_16 ) ;
F_3 ( V_78 , V_45 -> V_8 + V_16 ) ;
}
}
static void F_24 ( unsigned int * V_15 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_76 ; V_60 ++ ) {
struct V_1 * V_45 = V_77 [ V_60 ] ;
if ( ! V_45 )
break;
F_3 ( V_15 [ V_60 ] , V_45 -> V_8 + V_16 ) ;
F_25 ( V_45 -> V_79 ) ;
}
}
static int T_5 F_26 ( struct V_80 * V_81 , int V_44 )
{
int V_60 ;
T_3 V_54 ;
T_4 V_5 ;
struct V_57 * V_58 = F_27 ( V_81 ) ;
const struct V_62 * V_63 ;
const T_3 * V_64 ;
if ( ! V_58 -> V_65 )
return V_82 ;
for ( V_60 = 0 ; V_60 < V_58 -> V_67 -> V_68 ; V_60 ++ ) {
if ( V_58 -> V_67 -> V_69 [ V_60 ] . V_70 == V_44 )
break;
}
if ( V_60 == V_58 -> V_67 -> V_68 )
return V_82 ;
V_63 = V_58 -> V_67 -> V_69 + V_60 ;
V_64 = V_58 -> V_67 -> V_71 ;
for ( V_60 = 0 ; V_60 < V_66 ; V_60 ++ ) {
if ( V_63 -> V_72 [ V_60 ] . V_73 == true ) {
V_54 = V_64 [ V_63 -> V_72 [ V_60 ] . V_74 ] ;
V_5 = V_63 -> V_72 [ V_60 ] . V_75 ;
if ( F_2 ( V_58 -> V_65 + V_54 ) & F_7 ( V_5 ) )
return V_82 + V_60 + 1 ;
}
}
return V_82 ;
}
int F_28 ( int V_44 )
{
struct V_1 * V_2 ;
T_1 V_6 , V_7 , V_5 ;
V_2 = V_77 [ V_44 / V_83 ] ;
if ( ! V_2 )
return - V_84 ;
V_5 = 1 << ( V_44 % V_83 ) ;
F_23 ( V_2 -> V_79 ) ;
V_6 = F_2 ( V_2 -> V_8 + V_9 ) & V_5 ;
V_7 = F_2 ( V_2 -> V_8 + V_10 ) & V_5 ;
F_25 ( V_2 -> V_79 ) ;
return ( V_6 ? V_11 : 0 ) | ( V_7 ? V_12 : 0 ) ;
}
static inline int F_29 ( int V_44 )
{
return 1 << ( V_44 % V_83 ) ;
}
static void F_30 ( struct V_49 * V_50 )
{
struct V_1 * V_2 ;
V_2 = F_31 ( V_50 ) ;
if ( ! V_2 )
return;
F_23 ( V_2 -> V_79 ) ;
F_3 ( F_29 ( V_50 -> V_85 ) , V_2 -> V_8 + V_86 ) ;
F_25 ( V_2 -> V_79 ) ;
}
static void F_32 ( struct V_1 * V_2 ,
int V_44 , enum V_87 V_88 ,
bool V_89 )
{
T_1 V_90 = F_29 ( V_44 ) ;
T_1 * V_91 ;
T_1 * V_92 ;
T_1 V_93 ;
T_1 V_94 ;
if ( V_88 == V_95 ) {
V_93 = V_51 ;
V_94 = V_52 ;
V_91 = & V_2 -> V_43 ;
V_92 = & V_2 -> V_41 ;
} else {
V_93 = V_38 ;
V_94 = V_39 ;
V_91 = & V_2 -> V_35 ;
V_92 = & V_2 -> V_36 ;
}
if ( V_2 -> V_96 & V_90 ) {
if ( V_89 )
* V_91 |= V_90 ;
else
* V_91 &= ~ V_90 ;
F_3 ( * V_91 , V_2 -> V_8 + V_93 ) ;
}
if ( V_2 -> V_97 & V_90 ) {
if ( V_89 )
* V_92 |= V_90 ;
else
* V_92 &= ~ V_90 ;
F_3 ( * V_92 , V_2 -> V_8 + V_94 ) ;
}
}
static void F_33 ( struct V_1 * V_2 ,
int V_44 , bool V_98 )
{
if ( V_2 -> V_99 && V_98 ) {
F_4 ( V_2 , V_44 % V_83 ,
V_100 ) ;
}
F_32 ( V_2 , V_44 , V_101 , V_98 ) ;
}
static int F_34 ( struct V_49 * V_50 , bool V_89 )
{
struct V_1 * V_2 ;
unsigned long V_102 ;
T_1 V_90 ;
V_2 = F_31 ( V_50 ) ;
V_90 = F_29 ( V_50 -> V_85 ) ;
if ( ! V_2 )
return - V_84 ;
F_23 ( V_2 -> V_79 ) ;
F_35 ( & V_103 , V_102 ) ;
F_36 ( & V_2 -> V_104 ) ;
F_32 ( V_2 , V_50 -> V_85 , V_95 , V_89 ) ;
if ( ! ( V_2 -> V_105 & V_90 ) )
F_33 ( V_2 , V_50 -> V_85 , V_89 ) ;
F_37 ( & V_2 -> V_104 ) ;
F_38 ( & V_103 , V_102 ) ;
F_25 ( V_2 -> V_79 ) ;
return 0 ;
}
static void F_39 ( struct V_49 * V_50 )
{
F_34 ( V_50 , false ) ;
}
static void F_40 ( struct V_49 * V_50 )
{
F_34 ( V_50 , true ) ;
}
static int F_41 ( struct V_49 * V_50 , unsigned int V_98 )
{
struct V_1 * V_2 ;
unsigned long V_102 ;
T_1 V_90 ;
V_2 = F_31 ( V_50 ) ;
if ( ! V_2 )
return - V_84 ;
V_90 = F_29 ( V_50 -> V_85 ) ;
F_23 ( V_2 -> V_79 ) ;
F_35 ( & V_103 , V_102 ) ;
F_36 ( & V_2 -> V_104 ) ;
if ( F_16 ( V_50 ) )
F_33 ( V_2 , V_50 -> V_85 , V_98 ) ;
if ( V_98 )
V_2 -> V_105 |= V_90 ;
else
V_2 -> V_105 &= ~ V_90 ;
F_37 ( & V_2 -> V_104 ) ;
F_38 ( & V_103 , V_102 ) ;
F_25 ( V_2 -> V_79 ) ;
return 0 ;
}
static int F_42 ( struct V_49 * V_50 , unsigned int type )
{
bool V_29 = ! F_16 ( V_50 ) ;
bool V_106 = F_43 ( V_50 ) ;
struct V_1 * V_2 ;
unsigned long V_102 ;
T_1 V_90 ;
V_2 = F_31 ( V_50 ) ;
V_90 = F_29 ( V_50 -> V_85 ) ;
if ( ! V_2 )
return - V_84 ;
if ( type & V_107 )
return - V_84 ;
if ( type & V_108 )
return - V_84 ;
F_23 ( V_2 -> V_79 ) ;
F_35 ( & V_2 -> V_104 , V_102 ) ;
if ( V_29 )
F_32 ( V_2 , V_50 -> V_85 , V_95 , false ) ;
if ( V_29 || V_106 )
F_32 ( V_2 , V_50 -> V_85 , V_101 , false ) ;
V_2 -> V_96 &= ~ V_90 ;
if ( type & V_109 )
V_2 -> V_96 |= V_90 ;
V_2 -> V_97 &= ~ V_90 ;
if ( type & V_110 )
V_2 -> V_97 |= V_90 ;
if ( V_29 )
F_32 ( V_2 , V_50 -> V_85 , V_95 , true ) ;
if ( V_29 || V_106 )
F_32 ( V_2 , V_50 -> V_85 , V_101 , true ) ;
F_38 ( & V_2 -> V_104 , V_102 ) ;
F_25 ( V_2 -> V_79 ) ;
return 0 ;
}
static unsigned int F_44 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_31 ( V_50 ) ;
if ( F_45 ( & V_2 -> V_45 , V_50 -> V_85 ) )
F_20 ( V_2 -> V_45 . V_53 ,
L_7 ,
V_50 -> V_85 ) ;
F_23 ( V_2 -> V_79 ) ;
F_40 ( V_50 ) ;
return 0 ;
}
static void F_46 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_31 ( V_50 ) ;
F_39 ( V_50 ) ;
F_25 ( V_2 -> V_79 ) ;
F_47 ( & V_2 -> V_45 , V_50 -> V_85 ) ;
}
static void F_48 ( unsigned int V_47 , struct V_111 * V_112 ,
T_1 V_113 )
{
struct V_1 * V_2 ;
struct V_114 * V_115 = F_49 ( V_47 ) ;
F_50 ( V_115 , V_112 ) ;
V_2 = F_51 ( V_47 ) ;
while ( V_113 ) {
int V_5 = F_52 ( V_113 ) ;
F_53 ( F_14 ( V_2 -> V_48 , V_5 ) ) ;
V_113 &= ~ F_7 ( V_5 ) ;
}
F_54 ( V_115 , V_112 ) ;
}
static void F_55 ( unsigned int V_47 , struct V_111 * V_112 )
{
struct V_1 * V_2 = F_51 ( V_47 ) ;
T_1 V_113 ;
F_23 ( V_2 -> V_79 ) ;
V_113 = F_2 ( V_2 -> V_8 + V_116 ) ;
F_25 ( V_2 -> V_79 ) ;
F_48 ( V_47 , V_112 , V_113 ) ;
}
static void F_56 ( unsigned int V_47 ,
struct V_111 * V_112 )
{
struct V_1 * V_2 = F_51 ( V_47 ) ;
T_1 V_113 = V_2 -> V_117 ( V_2 -> V_118 ) ;
F_48 ( V_47 , V_112 , V_113 ) ;
}
static int F_57 ( struct V_1 * V_2 )
{
F_58 ( V_2 -> V_119 , F_55 ) ;
F_59 ( V_2 -> V_119 , V_2 ) ;
if ( V_2 -> V_120 >= 0 ) {
F_58 ( V_2 -> V_120 ,
F_56 ) ;
F_59 ( V_2 -> V_120 , V_2 ) ;
}
return 0 ;
}
static int F_60 ( struct V_121 * V_45 , unsigned V_3 )
{
int V_44 = V_45 -> V_46 + V_3 ;
return F_61 ( V_44 ) ;
}
static void F_62 ( struct V_121 * V_45 , unsigned V_3 )
{
int V_44 = V_45 -> V_46 + V_3 ;
F_63 ( V_44 ) ;
}
static int F_64 ( struct V_121 * V_45 , unsigned V_3 )
{
struct V_1 * V_2 =
F_65 ( V_45 , struct V_1 , V_45 ) ;
F_23 ( V_2 -> V_79 ) ;
F_3 ( 1 << V_3 , V_2 -> V_8 + V_31 ) ;
F_25 ( V_2 -> V_79 ) ;
return 0 ;
}
static int F_66 ( struct V_121 * V_45 , unsigned V_3 )
{
struct V_1 * V_2 =
F_65 ( V_45 , struct V_1 , V_45 ) ;
T_1 V_5 = 1 << V_3 ;
int V_56 ;
F_23 ( V_2 -> V_79 ) ;
V_56 = ( F_2 ( V_2 -> V_8 + V_122 ) & V_5 ) != 0 ;
F_25 ( V_2 -> V_79 ) ;
return V_56 ;
}
static void F_67 ( struct V_121 * V_45 , unsigned V_3 ,
int V_32 )
{
struct V_1 * V_2 =
F_65 ( V_45 , struct V_1 , V_45 ) ;
F_23 ( V_2 -> V_79 ) ;
F_10 ( V_2 , V_3 , V_32 ) ;
F_25 ( V_2 -> V_79 ) ;
}
static int F_68 ( struct V_121 * V_45 , unsigned V_3 ,
int V_32 )
{
struct V_1 * V_2 =
F_65 ( V_45 , struct V_1 , V_45 ) ;
F_23 ( V_2 -> V_79 ) ;
F_11 ( V_2 , V_3 , V_32 ) ;
F_25 ( V_2 -> V_79 ) ;
return 0 ;
}
static int F_69 ( struct V_121 * V_45 , unsigned V_3 )
{
struct V_1 * V_2 =
F_65 ( V_45 , struct V_1 , V_45 ) ;
return F_70 ( V_2 -> V_48 , V_3 ) ;
}
static void F_71 ( struct V_123 * V_124 ,
struct V_80 * V_81 , struct V_121 * V_45 ,
unsigned V_3 , unsigned V_44 )
{
const char * V_125 = F_72 ( V_45 , V_3 ) ;
struct V_1 * V_2 =
F_65 ( V_45 , struct V_1 , V_45 ) ;
int V_14 ;
bool V_126 ;
bool V_19 ;
T_1 V_5 = 1 << V_3 ;
const char * V_127 [] = {
[ V_128 ] = L_8 ,
[ V_11 ] = L_9 ,
[ V_12 ] = L_10 ,
[ V_82 ] = L_11 ,
[ V_82 + 1 ] = L_12 ,
[ V_82 + 2 ] = L_13 ,
[ V_82 + 3 ] = L_14 ,
[ V_82 + 4 ] = L_15 ,
} ;
F_23 ( V_2 -> V_79 ) ;
V_126 = ! ! ( F_2 ( V_2 -> V_8 + V_129 ) & V_5 ) ;
V_19 = ! ( F_2 ( V_2 -> V_8 + V_21 ) & V_5 ) ;
V_14 = F_28 ( V_44 ) ;
if ( ( V_14 == V_82 ) && V_81 )
V_14 = F_26 ( V_81 , V_44 ) ;
F_73 ( V_124 , L_16 ,
V_44 , V_125 ? : L_17 ,
V_126 ? L_18 : L_19 ,
V_45 -> V_130
? ( V_45 -> V_130 ( V_45 , V_3 ) ? L_20 : L_21 )
: L_22 ,
( V_14 < 0 ) ? L_23 : V_127 [ V_14 ] ,
V_19 ? L_24 : L_25 ) ;
if ( V_125 && ! V_126 ) {
int V_47 = F_74 ( V_44 ) ;
struct V_111 * V_112 = F_75 ( V_47 ) ;
if ( V_47 >= 0 && V_112 -> V_131 ) {
char * V_132 ;
T_1 V_90 = F_29 ( V_44 ) ;
if ( V_2 -> V_96 & V_90 )
V_132 = L_26 ;
else if ( V_2 -> V_97 & V_90 )
V_132 = L_27 ;
else
V_132 = L_28 ;
F_73 ( V_124 , L_29 ,
V_47 , V_132 ,
F_43 ( & V_112 -> V_49 )
? L_30 : L_31 ) ;
}
}
F_25 ( V_2 -> V_79 ) ;
}
static void F_76 ( struct V_123 * V_124 , struct V_121 * V_45 )
{
unsigned V_60 ;
unsigned V_44 = V_45 -> V_46 ;
for ( V_60 = 0 ; V_60 < V_45 -> V_133 ; V_60 ++ , V_44 ++ ) {
F_71 ( V_124 , NULL , V_45 , V_60 , V_44 ) ;
F_73 ( V_124 , L_32 ) ;
}
}
static inline void F_71 ( struct V_123 * V_124 ,
struct V_80 * V_81 ,
struct V_121 * V_45 ,
unsigned V_3 , unsigned V_44 )
{
}
void F_77 ( void )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_76 ; V_60 ++ ) {
struct V_1 * V_45 = V_77 [ V_60 ] ;
if ( ! V_45 )
continue;
F_23 ( V_45 -> V_79 ) ;
}
}
void F_78 ( void )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_76 ; V_60 ++ ) {
struct V_1 * V_45 = V_77 [ V_60 ] ;
if ( ! V_45 )
continue;
F_25 ( V_45 -> V_79 ) ;
}
}
void F_79 ( void )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_76 ; V_60 ++ ) {
struct V_1 * V_45 = V_77 [ V_60 ] ;
if ( ! V_45 )
break;
F_23 ( V_45 -> V_79 ) ;
F_3 ( V_45 -> V_35 & V_45 -> V_105 ,
V_45 -> V_8 + V_38 ) ;
F_3 ( V_45 -> V_36 & V_45 -> V_105 ,
V_45 -> V_8 + V_39 ) ;
F_25 ( V_45 -> V_79 ) ;
}
}
void F_80 ( void )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_76 ; V_60 ++ ) {
struct V_1 * V_45 = V_77 [ V_60 ] ;
if ( ! V_45 )
break;
F_23 ( V_45 -> V_79 ) ;
F_3 ( V_45 -> V_35 , V_45 -> V_8 + V_38 ) ;
F_3 ( V_45 -> V_36 , V_45 -> V_8 + V_39 ) ;
F_25 ( V_45 -> V_79 ) ;
}
}
void F_81 ( int V_134 , T_1 * V_23 )
{
if ( V_134 < V_76 ) {
struct V_1 * V_45 = V_77 [ V_134 ] ;
if ( ! V_45 )
return;
* V_23 = V_45 -> V_23 ;
}
}
static int F_82 ( struct V_135 * V_50 , unsigned int V_47 ,
T_6 V_85 )
{
struct V_1 * V_2 = V_50 -> V_136 ;
if ( ! V_2 )
return - V_84 ;
F_83 ( V_47 , & V_137 , V_138 ) ;
F_84 ( V_47 , V_139 ) ;
F_85 ( V_47 , V_2 ) ;
F_86 ( V_47 , V_110 ) ;
return 0 ;
}
static int F_87 ( struct V_140 * V_53 )
{
struct V_141 * V_142 = V_53 -> V_53 . V_143 ;
struct V_144 * V_145 = V_53 -> V_53 . V_146 ;
struct V_1 * V_2 ;
struct V_121 * V_45 ;
struct V_147 * V_148 ;
struct V_79 * V_79 ;
int V_149 ;
void T_2 * V_46 ;
int V_150 = 0 ;
int V_47 ;
int V_151 ;
if ( ! V_142 && ! V_145 ) {
F_20 ( & V_53 -> V_53 , L_33 ) ;
return - V_152 ;
}
if ( V_145 ) {
V_142 = F_88 ( & V_53 -> V_53 , sizeof( * V_142 ) , V_153 ) ;
if ( ! V_142 )
return - V_154 ;
if ( F_89 ( V_145 , L_34 , NULL ) )
V_142 -> V_155 = true ;
if ( F_90 ( V_145 , L_35 , & V_53 -> V_156 ) ) {
F_20 ( & V_53 -> V_53 , L_36 ) ;
return - V_84 ;
}
V_142 -> V_157 = V_53 -> V_156 * V_83 ;
V_142 -> V_158 = V_83 ;
}
V_47 = F_91 ( V_53 , 0 ) ;
if ( V_47 < 0 )
return V_47 ;
V_149 = F_91 ( V_53 , 1 ) ;
if ( V_149 >= 0 && ! V_142 -> V_117 )
return - V_84 ;
V_148 = F_92 ( V_53 , V_159 , 0 ) ;
V_46 = F_93 ( & V_53 -> V_53 , V_148 ) ;
if ( F_94 ( V_46 ) )
return F_95 ( V_46 ) ;
V_79 = F_96 ( & V_53 -> V_53 , NULL ) ;
if ( F_94 ( V_79 ) )
return F_95 ( V_79 ) ;
F_97 ( V_79 ) ;
V_2 = F_88 ( & V_53 -> V_53 , sizeof( * V_2 ) , V_153 ) ;
if ( ! V_2 )
return - V_154 ;
V_2 -> V_118 = V_53 -> V_156 ;
V_2 -> V_79 = V_79 ;
V_2 -> V_8 = V_46 ;
V_2 -> V_45 = V_160 ;
V_2 -> V_119 = V_47 ;
V_2 -> V_120 = V_149 ;
V_2 -> V_117 = V_142 -> V_117 ;
V_2 -> V_37 = V_142 -> V_37 ;
V_2 -> V_99 = V_142 -> V_155 ;
F_98 ( & V_2 -> V_104 ) ;
V_45 = & V_2 -> V_45 ;
V_45 -> V_46 = V_142 -> V_157 ;
V_45 -> V_133 = V_142 -> V_158 ;
V_45 -> V_125 = V_142 -> V_161 ? : F_99 ( & V_53 -> V_53 ) ;
V_45 -> V_53 = & V_53 -> V_53 ;
V_45 -> V_162 = V_163 ;
F_23 ( V_2 -> V_79 ) ;
V_2 -> V_28 = F_100 ( V_2 -> V_8 + V_30 ) ;
F_25 ( V_2 -> V_79 ) ;
#ifdef F_101
V_45 -> V_146 = V_145 ;
#endif
V_151 = F_102 ( & V_2 -> V_45 ) ;
if ( V_151 )
return V_151 ;
F_103 ( V_2 -> V_118 >= F_104 ( V_77 ) ) ;
V_77 [ V_2 -> V_118 ] = V_2 ;
F_105 ( V_53 , V_2 ) ;
if ( ! V_145 )
V_150 = V_142 -> V_164 ;
V_2 -> V_48 = F_106 ( V_145 ,
V_83 , V_150 ,
& V_165 , V_2 ) ;
if ( ! V_2 -> V_48 ) {
F_20 ( & V_53 -> V_53 , L_37 ) ;
V_151 = F_107 ( & V_2 -> V_45 ) ;
return - V_166 ;
}
F_57 ( V_2 ) ;
F_108 ( & V_53 -> V_53 , L_38 , V_2 -> V_8 ) ;
return 0 ;
}
static int F_109 ( struct V_80 * V_81 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
return V_58 -> V_67 -> V_167 ;
}
static const char * F_110 ( struct V_80 * V_81 ,
unsigned V_168 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
return V_58 -> V_67 -> V_169 [ V_168 ] . V_161 ;
}
static int F_111 ( struct V_80 * V_81 , unsigned V_168 ,
const unsigned * * V_170 ,
unsigned * V_171 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
* V_170 = V_58 -> V_67 -> V_169 [ V_168 ] . V_170 ;
* V_171 = V_58 -> V_67 -> V_169 [ V_168 ] . V_172 ;
return 0 ;
}
static struct V_173 *
F_112 ( struct V_80 * V_81 , unsigned V_3 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_58 -> V_67 -> V_174 ; V_60 ++ ) {
struct V_173 * V_175 ;
V_175 = & V_58 -> V_67 -> V_176 [ V_60 ] ;
if ( V_3 >= V_175 -> V_177 &&
V_3 <= ( V_175 -> V_177 + V_175 -> V_172 - 1 ) )
return V_175 ;
}
return NULL ;
}
static void F_113 ( struct V_80 * V_81 , struct V_123 * V_124 ,
unsigned V_3 )
{
struct V_173 * V_175 ;
struct V_121 * V_45 ;
V_175 = F_112 ( V_81 , V_3 ) ;
if ( ! V_175 || ! V_175 -> V_178 ) {
F_73 ( V_124 , L_39 ) ;
return;
}
V_45 = V_175 -> V_178 ;
F_71 ( V_124 , V_81 , V_45 , V_3 - V_45 -> V_46 , V_3 ) ;
}
static void F_114 ( struct V_80 * V_81 ,
struct V_179 * V_180 , unsigned V_181 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_181 ; V_60 ++ )
if ( V_180 [ V_60 ] . type == V_182 )
F_115 ( V_180 [ V_60 ] . V_183 . V_184 . V_184 ) ;
F_115 ( V_180 ) ;
}
static int F_116 ( struct V_179 * * V_180 , unsigned * V_185 ,
unsigned * V_181 , unsigned V_186 )
{
unsigned V_187 = * V_185 ;
unsigned V_188 = * V_181 + V_186 ;
struct V_179 * V_189 ;
if ( V_187 >= V_188 )
return 0 ;
V_189 = F_117 ( * V_180 , sizeof( * V_189 ) * V_188 , V_153 ) ;
if ( ! V_189 )
return - V_154 ;
memset ( V_189 + V_187 , 0 , ( V_188 - V_187 ) * sizeof( * V_189 ) ) ;
* V_180 = V_189 ;
* V_185 = V_188 ;
return 0 ;
}
static int F_118 ( struct V_179 * * V_180 , unsigned * V_185 ,
unsigned * V_181 , const char * V_190 ,
const char * V_191 )
{
if ( * V_181 == * V_185 )
return - V_192 ;
( * V_180 ) [ * V_181 ] . type = V_193 ;
( * V_180 ) [ * V_181 ] . V_183 . V_194 . V_190 = V_190 ;
( * V_180 ) [ * V_181 ] . V_183 . V_194 . V_191 = V_191 ;
( * V_181 ) ++ ;
return 0 ;
}
static int F_119 ( struct V_179 * * V_180 ,
unsigned * V_185 ,
unsigned * V_181 , const char * V_190 ,
unsigned long * V_184 , unsigned V_195 )
{
unsigned long * V_196 ;
if ( * V_181 == * V_185 )
return - V_192 ;
V_196 = F_120 ( V_184 , V_195 * sizeof( * V_196 ) ,
V_153 ) ;
if ( ! V_196 )
return - V_154 ;
( * V_180 ) [ * V_181 ] . type = V_182 ;
( * V_180 ) [ * V_181 ] . V_183 . V_184 . V_197 = V_190 ;
( * V_180 ) [ * V_181 ] . V_183 . V_184 . V_184 = V_196 ;
( * V_180 ) [ * V_181 ] . V_183 . V_184 . V_195 = V_195 ;
( * V_181 ) ++ ;
return 0 ;
}
static int F_121 ( int V_198 , int V_32 , unsigned long * V_199 )
{
int V_151 = 0 ;
if ( V_200 [ V_198 ] . V_201 == NULL )
* V_199 = V_200 [ V_198 ] . V_199 ;
else {
if ( V_32 < V_200 [ V_198 ] . V_202 ) {
* V_199 = V_200 [ V_198 ] . V_199 |
V_200 [ V_198 ] . V_201 [ V_32 ] ;
}
}
return V_151 ;
}
static const char * F_122 ( struct V_80 * V_81 , const char * V_203 )
{
int V_60 , V_204 ;
struct V_57 * V_58 = F_27 ( V_81 ) ;
if ( sscanf ( ( char * ) V_203 , L_40 , & V_204 ) == 1 )
for ( V_60 = 0 ; V_60 < V_58 -> V_67 -> V_172 ; V_60 ++ )
if ( V_58 -> V_67 -> V_170 [ V_60 ] . V_205 == V_204 )
return V_58 -> V_67 -> V_170 [ V_60 ] . V_161 ;
return NULL ;
}
static bool F_123 ( struct V_144 * V_145 ,
unsigned long * V_184 )
{
bool V_206 = 0 ;
unsigned long V_207 = 0 ;
int V_60 , V_32 , V_151 ;
for ( V_60 = 0 ; V_60 < F_104 ( V_200 ) ; V_60 ++ ) {
V_151 = F_90 ( V_145 ,
V_200 [ V_60 ] . V_208 , & V_32 ) ;
if ( V_151 != - V_84 ) {
if ( F_121 ( V_60 , V_32 , & V_207 ) == 0 ) {
* V_184 |= V_207 ;
V_206 = 1 ;
}
}
}
return V_206 ;
}
static int F_124 ( struct V_80 * V_81 ,
struct V_144 * V_145 ,
struct V_179 * * V_180 ,
unsigned * V_185 ,
unsigned * V_181 )
{
int V_151 ;
const char * V_191 = NULL ;
unsigned long V_184 = 0 ;
bool V_206 = 0 ;
unsigned V_186 = 0 ;
struct V_208 * V_209 ;
const char * V_190 , * V_210 ;
struct V_144 * V_211 ;
V_151 = F_125 ( V_145 , L_41 , & V_191 ) ;
if ( V_151 >= 0 )
V_186 = 1 ;
V_206 = F_123 ( V_145 , & V_184 ) ;
V_211 = F_126 ( V_145 , L_42 , 0 ) ;
if ( V_211 )
V_206 |= F_123 ( V_211 , & V_184 ) ;
V_151 = F_127 ( V_145 , L_43 ) ;
if ( V_151 < 0 )
goto exit;
if ( V_206 )
V_186 ++ ;
V_186 *= V_151 ;
V_151 = F_116 ( V_180 , V_185 , V_181 , V_186 ) ;
if ( V_151 < 0 )
goto exit;
F_128 (np, L_43 , prop, group) {
if ( V_191 ) {
V_151 = F_118 ( V_180 , V_185 , V_181 ,
V_190 , V_191 ) ;
if ( V_151 < 0 )
goto exit;
}
if ( V_206 ) {
V_210 = F_122 ( V_81 , V_190 ) ;
V_151 = F_119 ( V_180 , V_185 , V_181 ,
V_210 , & V_184 , 1 ) ;
if ( V_151 < 0 )
goto exit;
}
}
exit:
return V_151 ;
}
static int F_129 ( struct V_80 * V_81 ,
struct V_144 * V_211 ,
struct V_179 * * V_180 , unsigned * V_181 )
{
unsigned V_185 ;
struct V_144 * V_145 ;
int V_151 ;
V_185 = 0 ;
* V_180 = NULL ;
* V_181 = 0 ;
F_130 (np_config, np) {
V_151 = F_124 ( V_81 , V_145 , V_180 ,
& V_185 , V_181 ) ;
if ( V_151 < 0 ) {
F_114 ( V_81 , * V_180 , * V_181 ) ;
return V_151 ;
}
}
return 0 ;
}
static int F_131 ( struct V_80 * V_81 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
return V_58 -> V_67 -> V_212 ;
}
static const char * F_132 ( struct V_80 * V_81 ,
unsigned V_191 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
return V_58 -> V_67 -> V_213 [ V_191 ] . V_161 ;
}
static int F_133 ( struct V_80 * V_81 ,
unsigned V_191 ,
const char * const * * V_169 ,
unsigned * const V_214 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
* V_169 = V_58 -> V_67 -> V_213 [ V_191 ] . V_169 ;
* V_214 = V_58 -> V_67 -> V_213 [ V_191 ] . V_167 ;
return 0 ;
}
static int F_134 ( struct V_80 * V_81 , unsigned V_191 ,
unsigned V_190 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
const struct V_215 * V_216 ;
static unsigned int V_15 [ V_76 ] ;
unsigned long V_102 = 0 ;
bool V_34 ;
int V_151 = - V_84 ;
int V_60 ;
V_216 = & V_58 -> V_67 -> V_169 [ V_190 ] ;
if ( V_216 -> V_217 < 0 )
return - V_84 ;
F_17 ( V_58 -> V_53 , L_44 , V_216 -> V_161 , V_216 -> V_172 ) ;
V_34 = ( ( V_216 -> V_217 & V_82 ) == V_82 ) ;
if ( V_34 ) {
F_35 ( & V_103 , V_102 ) ;
memset ( V_15 , 0xff , sizeof( V_15 ) ) ;
for ( V_60 = 0 ; V_60 < V_216 -> V_172 ; V_60 ++ )
V_15 [ V_216 -> V_170 [ V_60 ] / V_83 ] &= ~ F_7 ( V_216 -> V_170 [ V_60 ] ) ;
F_22 ( V_15 ) ;
}
for ( V_60 = 0 ; V_60 < V_216 -> V_172 ; V_60 ++ ) {
struct V_173 * V_175 ;
struct V_1 * V_2 ;
struct V_121 * V_45 ;
unsigned V_5 ;
V_175 = F_112 ( V_81 , V_216 -> V_170 [ V_60 ] ) ;
if ( ! V_175 ) {
F_20 ( V_58 -> V_53 ,
L_45 ,
V_216 -> V_170 [ V_60 ] , V_216 -> V_161 , V_60 ) ;
goto V_218;
}
if ( ! V_175 -> V_178 ) {
F_20 ( V_58 -> V_53 , L_46 ,
V_216 -> V_170 [ V_60 ] , V_216 -> V_161 , V_60 ) ;
goto V_218;
}
V_45 = V_175 -> V_178 ;
V_2 = F_65 ( V_45 , struct V_1 , V_45 ) ;
F_17 ( V_58 -> V_53 , L_47 , V_216 -> V_170 [ V_60 ] , V_216 -> V_217 ) ;
F_23 ( V_2 -> V_79 ) ;
V_5 = V_216 -> V_170 [ V_60 ] % V_83 ;
F_13 ( V_2 , V_5 ) ;
F_12 ( V_2 , V_5 ,
( V_216 -> V_217 & V_82 ) , V_34 ) ;
F_25 ( V_2 -> V_79 ) ;
if ( ( V_216 -> V_217 & V_82 ) == V_82 )
F_19 ( V_58 , V_216 -> V_170 [ V_60 ] ,
V_216 -> V_217 >> V_219 ) ;
}
V_151 = 0 ;
V_218:
if ( V_34 ) {
F_24 ( V_15 ) ;
F_38 ( & V_103 , V_102 ) ;
}
return V_151 ;
}
static void F_135 ( struct V_80 * V_81 ,
unsigned V_191 , unsigned V_190 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
const struct V_215 * V_216 ;
V_216 = & V_58 -> V_67 -> V_169 [ V_190 ] ;
if ( V_216 -> V_217 < 0 )
return;
F_17 ( V_58 -> V_53 , L_48 , V_216 -> V_161 , V_216 -> V_172 ) ;
}
static int F_136 ( struct V_80 * V_81 ,
struct V_173 * V_175 ,
unsigned V_3 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
struct V_1 * V_2 ;
struct V_121 * V_45 ;
unsigned V_5 ;
if ( ! V_175 ) {
F_20 ( V_58 -> V_53 , L_49 ) ;
return - V_84 ;
}
if ( ! V_175 -> V_178 ) {
F_20 ( V_58 -> V_53 , L_50 ) ;
return - V_84 ;
}
V_45 = V_175 -> V_178 ;
V_2 = F_65 ( V_45 , struct V_1 , V_45 ) ;
F_17 ( V_58 -> V_53 , L_51 , V_3 ) ;
F_23 ( V_2 -> V_79 ) ;
V_5 = V_3 % V_83 ;
F_1 ( V_2 , V_5 , V_128 ) ;
F_25 ( V_2 -> V_79 ) ;
return 0 ;
}
static void F_137 ( struct V_80 * V_81 ,
struct V_173 * V_175 ,
unsigned V_3 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
F_17 ( V_58 -> V_53 , L_52 , V_3 ) ;
}
static int F_138 ( struct V_80 * V_81 , unsigned V_70 ,
unsigned long * V_199 )
{
return - V_84 ;
}
static int F_139 ( struct V_80 * V_81 , unsigned V_70 ,
unsigned long * V_184 , unsigned V_195 )
{
static const char * V_220 [] = {
[ V_22 ] = L_25 ,
[ V_24 ] = L_53 ,
[ V_26 ] = L_54 ,
[ 3 ] = L_55
} ;
static const char * V_221 [] = {
[ V_222 ] = L_56 ,
[ V_17 ] = L_57 ,
} ;
struct V_57 * V_58 = F_27 ( V_81 ) ;
struct V_1 * V_2 ;
struct V_173 * V_175 ;
struct V_121 * V_45 ;
unsigned V_5 ;
T_7 V_207 ;
int V_19 , V_15 , V_223 , V_32 , V_60 ;
bool V_28 , V_224 , V_225 ;
V_175 = F_112 ( V_81 , V_70 ) ;
if ( ! V_175 ) {
F_20 ( V_58 -> V_53 , L_58 , V_70 ) ;
return - V_84 ;
}
if ( ! V_175 -> V_178 ) {
F_20 ( V_58 -> V_53 , L_59 ,
V_70 ) ;
return - V_84 ;
}
V_45 = V_175 -> V_178 ;
V_2 = F_65 ( V_45 , struct V_1 , V_45 ) ;
for ( V_60 = 0 ; V_60 < V_195 ; V_60 ++ ) {
V_207 = ( T_7 ) V_184 [ V_60 ] ;
V_19 = F_140 ( V_207 ) ;
V_15 = F_141 ( V_207 ) ;
V_223 = F_142 ( V_207 ) ;
V_32 = F_143 ( V_207 ) ;
V_28 = F_144 ( V_207 ) ;
V_224 = F_145 ( V_207 ) ;
V_225 = F_146 ( V_207 ) ;
if ( V_225 ) {
int V_226 = F_147 ( V_207 ) ;
int V_227 = F_148 ( V_207 ) ;
int V_228 = F_149 ( V_207 ) ;
V_224 = true ;
if ( V_226 )
V_19 = V_226 - 1 ;
if ( V_227 )
V_223 = V_227 - 1 ;
if ( V_228 )
V_32 = V_228 - 1 ;
F_17 ( V_2 -> V_45 . V_53 ,
L_60 ,
V_70 ,
V_226 ? V_220 [ V_19 ] : L_61 ,
V_227 ? ( V_223 ? L_62 : L_63 )
: L_61 ,
V_228 ? ( V_32 ? L_64 : L_65 ) : L_61 ) ;
}
F_17 ( V_2 -> V_45 . V_53 ,
L_66 ,
V_70 , V_207 , V_220 [ V_19 ] , V_221 [ V_15 ] ,
V_223 ? L_67 : L_63 ,
V_223 ? ( V_32 ? L_64 : L_65 ) : L_31 ,
V_28 ? L_68 : L_69 ) ;
F_23 ( V_2 -> V_79 ) ;
V_5 = V_70 % V_83 ;
if ( V_224 )
F_1 ( V_2 , V_5 , V_128 ) ;
if ( V_223 )
F_11 ( V_2 , V_5 , V_32 ) ;
else {
F_9 ( V_2 , V_5 ) ;
F_5 ( V_2 , V_5 , V_19 ) ;
}
F_6 ( V_2 , V_5 , V_28 ) ;
F_4 ( V_2 , V_5 , V_15 ) ;
F_25 ( V_2 -> V_79 ) ;
}
return 0 ;
}
static int F_150 ( struct V_140 * V_229 , T_8 V_230 )
{
struct V_57 * V_58 ;
V_58 = F_151 ( V_229 ) ;
if ( ! V_58 )
return - V_84 ;
return F_152 ( V_58 -> V_231 ) ;
}
static int F_153 ( struct V_140 * V_229 )
{
struct V_57 * V_58 ;
V_58 = F_151 ( V_229 ) ;
if ( ! V_58 )
return - V_84 ;
return F_154 ( V_58 -> V_231 ) ;
}
static int F_155 ( struct V_140 * V_229 )
{
const struct V_232 * V_233 = F_156 ( V_229 ) ;
struct V_144 * V_145 = V_229 -> V_53 . V_146 ;
struct V_144 * V_234 ;
struct V_57 * V_58 ;
struct V_147 * V_148 ;
unsigned int V_235 = 0 ;
int V_60 ;
V_58 = F_88 ( & V_229 -> V_53 , sizeof( * V_58 ) , V_153 ) ;
if ( ! V_58 )
return - V_154 ;
if ( V_233 )
V_235 = V_233 -> V_236 ;
else if ( V_145 ) {
const struct V_237 * V_238 ;
V_238 = F_157 ( V_239 , & V_229 -> V_53 ) ;
if ( ! V_238 )
return - V_152 ;
V_235 = ( unsigned int ) V_238 -> V_183 ;
}
if ( V_235 == V_240 )
F_158 ( & V_58 -> V_67 ) ;
if ( V_235 == V_241 )
F_159 ( & V_58 -> V_67 ) ;
if ( V_235 == V_242 )
F_160 ( & V_58 -> V_67 ) ;
if ( V_145 ) {
V_234 = F_126 ( V_145 , L_70 , 0 ) ;
if ( V_234 )
V_58 -> V_65 = F_161 ( V_234 , 0 ) ;
}
V_148 = F_92 ( V_229 , V_159 , 0 ) ;
if ( V_148 )
V_58 -> V_65 = F_162 ( & V_229 -> V_53 , V_148 -> V_243 ,
F_163 ( V_148 ) ) ;
if ( ! V_58 -> V_65 ) {
if ( V_235 == V_240 ) {
F_108 ( & V_229 -> V_53 ,
L_71
L_72 ) ;
} else {
F_20 ( & V_229 -> V_53 , L_73 ) ;
return - V_84 ;
}
}
for ( V_60 = 0 ; V_60 < V_58 -> V_67 -> V_174 ; V_60 ++ ) {
if ( ! V_77 [ V_58 -> V_67 -> V_176 [ V_60 ] . V_156 ] ) {
F_21 ( & V_229 -> V_53 , L_74 , V_60 ) ;
return - V_244 ;
}
V_58 -> V_67 -> V_176 [ V_60 ] . V_178 = & V_77 [ V_58 -> V_67 -> V_176 [ V_60 ] . V_156 ] -> V_45 ;
}
V_245 . V_170 = V_58 -> V_67 -> V_170 ;
V_245 . V_172 = V_58 -> V_67 -> V_172 ;
V_58 -> V_53 = & V_229 -> V_53 ;
V_58 -> V_231 = F_164 ( & V_245 , & V_229 -> V_53 , V_58 ) ;
if ( ! V_58 -> V_231 ) {
F_20 ( & V_229 -> V_53 , L_75 ) ;
return - V_84 ;
}
for ( V_60 = 0 ; V_60 < V_58 -> V_67 -> V_174 ; V_60 ++ )
F_165 ( V_58 -> V_231 , & V_58 -> V_67 -> V_176 [ V_60 ] ) ;
F_105 ( V_229 , V_58 ) ;
F_108 ( & V_229 -> V_53 , L_76 ) ;
return 0 ;
}
static int T_9 F_166 ( void )
{
int V_151 ;
V_151 = F_167 ( & V_246 ) ;
if ( V_151 )
return V_151 ;
return F_167 ( & V_247 ) ;
}

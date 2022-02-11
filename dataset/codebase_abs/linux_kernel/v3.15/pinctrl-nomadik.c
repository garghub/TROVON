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
int V_47 = F_14 ( V_2 -> V_45 . V_48 , V_3 ) ;
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
struct V_85 * V_45 = F_31 ( V_50 ) ;
struct V_1 * V_2 = F_32 ( V_45 , struct V_1 , V_45 ) ;
F_23 ( V_2 -> V_79 ) ;
F_3 ( F_29 ( V_50 -> V_86 ) , V_2 -> V_8 + V_87 ) ;
F_25 ( V_2 -> V_79 ) ;
}
static void F_33 ( struct V_1 * V_2 ,
int V_44 , enum V_88 V_89 ,
bool V_90 )
{
T_1 V_91 = F_29 ( V_44 ) ;
T_1 * V_92 ;
T_1 * V_93 ;
T_1 V_94 ;
T_1 V_95 ;
if ( V_89 == V_96 ) {
V_94 = V_51 ;
V_95 = V_52 ;
V_92 = & V_2 -> V_43 ;
V_93 = & V_2 -> V_41 ;
} else {
V_94 = V_38 ;
V_95 = V_39 ;
V_92 = & V_2 -> V_35 ;
V_93 = & V_2 -> V_36 ;
}
if ( V_2 -> V_97 & V_91 ) {
if ( V_90 )
* V_92 |= V_91 ;
else
* V_92 &= ~ V_91 ;
F_3 ( * V_92 , V_2 -> V_8 + V_94 ) ;
}
if ( V_2 -> V_98 & V_91 ) {
if ( V_90 )
* V_93 |= V_91 ;
else
* V_93 &= ~ V_91 ;
F_3 ( * V_93 , V_2 -> V_8 + V_95 ) ;
}
}
static void F_34 ( struct V_1 * V_2 ,
int V_44 , bool V_99 )
{
if ( V_2 -> V_100 && V_99 ) {
F_4 ( V_2 , V_44 % V_83 ,
V_101 ) ;
}
F_33 ( V_2 , V_44 , V_102 , V_99 ) ;
}
static int F_35 ( struct V_49 * V_50 , bool V_90 )
{
struct V_1 * V_2 ;
unsigned long V_103 ;
T_1 V_91 ;
V_2 = F_31 ( V_50 ) ;
V_91 = F_29 ( V_50 -> V_86 ) ;
if ( ! V_2 )
return - V_84 ;
F_23 ( V_2 -> V_79 ) ;
F_36 ( & V_104 , V_103 ) ;
F_37 ( & V_2 -> V_105 ) ;
F_33 ( V_2 , V_50 -> V_86 , V_96 , V_90 ) ;
if ( ! ( V_2 -> V_106 & V_91 ) )
F_34 ( V_2 , V_50 -> V_86 , V_90 ) ;
F_38 ( & V_2 -> V_105 ) ;
F_39 ( & V_104 , V_103 ) ;
F_25 ( V_2 -> V_79 ) ;
return 0 ;
}
static void F_40 ( struct V_49 * V_50 )
{
F_35 ( V_50 , false ) ;
}
static void F_41 ( struct V_49 * V_50 )
{
F_35 ( V_50 , true ) ;
}
static int F_42 ( struct V_49 * V_50 , unsigned int V_99 )
{
struct V_1 * V_2 ;
unsigned long V_103 ;
T_1 V_91 ;
V_2 = F_31 ( V_50 ) ;
if ( ! V_2 )
return - V_84 ;
V_91 = F_29 ( V_50 -> V_86 ) ;
F_23 ( V_2 -> V_79 ) ;
F_36 ( & V_104 , V_103 ) ;
F_37 ( & V_2 -> V_105 ) ;
if ( F_16 ( V_50 ) )
F_34 ( V_2 , V_50 -> V_86 , V_99 ) ;
if ( V_99 )
V_2 -> V_106 |= V_91 ;
else
V_2 -> V_106 &= ~ V_91 ;
F_38 ( & V_2 -> V_105 ) ;
F_39 ( & V_104 , V_103 ) ;
F_25 ( V_2 -> V_79 ) ;
return 0 ;
}
static int F_43 ( struct V_49 * V_50 , unsigned int type )
{
bool V_29 = ! F_16 ( V_50 ) ;
bool V_107 = F_44 ( V_50 ) ;
struct V_1 * V_2 ;
unsigned long V_103 ;
T_1 V_91 ;
V_2 = F_31 ( V_50 ) ;
V_91 = F_29 ( V_50 -> V_86 ) ;
if ( ! V_2 )
return - V_84 ;
if ( type & V_108 )
return - V_84 ;
if ( type & V_109 )
return - V_84 ;
F_23 ( V_2 -> V_79 ) ;
F_36 ( & V_2 -> V_105 , V_103 ) ;
if ( V_29 )
F_33 ( V_2 , V_50 -> V_86 , V_96 , false ) ;
if ( V_29 || V_107 )
F_33 ( V_2 , V_50 -> V_86 , V_102 , false ) ;
V_2 -> V_97 &= ~ V_91 ;
if ( type & V_110 )
V_2 -> V_97 |= V_91 ;
V_2 -> V_98 &= ~ V_91 ;
if ( type & V_111 )
V_2 -> V_98 |= V_91 ;
if ( V_29 )
F_33 ( V_2 , V_50 -> V_86 , V_96 , true ) ;
if ( V_29 || V_107 )
F_33 ( V_2 , V_50 -> V_86 , V_102 , true ) ;
F_39 ( & V_2 -> V_105 , V_103 ) ;
F_25 ( V_2 -> V_79 ) ;
return 0 ;
}
static unsigned int F_45 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_31 ( V_50 ) ;
F_23 ( V_2 -> V_79 ) ;
F_41 ( V_50 ) ;
return 0 ;
}
static void F_46 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_31 ( V_50 ) ;
F_40 ( V_50 ) ;
F_25 ( V_2 -> V_79 ) ;
}
static void F_47 ( unsigned int V_47 , struct V_112 * V_113 ,
T_1 V_114 )
{
struct V_115 * V_116 = F_48 ( V_47 ) ;
struct V_85 * V_45 = F_49 ( V_113 ) ;
F_50 ( V_116 , V_113 ) ;
while ( V_114 ) {
int V_5 = F_51 ( V_114 ) ;
F_52 ( F_14 ( V_45 -> V_48 , V_5 ) ) ;
V_114 &= ~ F_7 ( V_5 ) ;
}
F_53 ( V_116 , V_113 ) ;
}
static void F_54 ( unsigned int V_47 , struct V_112 * V_113 )
{
struct V_85 * V_45 = F_49 ( V_113 ) ;
struct V_1 * V_2 = F_32 ( V_45 , struct V_1 , V_45 ) ;
T_1 V_114 ;
F_23 ( V_2 -> V_79 ) ;
V_114 = F_2 ( V_2 -> V_8 + V_117 ) ;
F_25 ( V_2 -> V_79 ) ;
F_47 ( V_47 , V_113 , V_114 ) ;
}
static void F_55 ( unsigned int V_47 ,
struct V_112 * V_113 )
{
struct V_85 * V_45 = F_49 ( V_113 ) ;
struct V_1 * V_2 = F_32 ( V_45 , struct V_1 , V_45 ) ;
T_1 V_114 = V_2 -> V_118 ( V_2 -> V_119 ) ;
F_47 ( V_47 , V_113 , V_114 ) ;
}
static int F_56 ( struct V_85 * V_45 , unsigned V_3 )
{
int V_44 = V_45 -> V_46 + V_3 ;
return F_57 ( V_44 ) ;
}
static void F_58 ( struct V_85 * V_45 , unsigned V_3 )
{
int V_44 = V_45 -> V_46 + V_3 ;
F_59 ( V_44 ) ;
}
static int F_60 ( struct V_85 * V_45 , unsigned V_3 )
{
struct V_1 * V_2 =
F_32 ( V_45 , struct V_1 , V_45 ) ;
F_23 ( V_2 -> V_79 ) ;
F_3 ( 1 << V_3 , V_2 -> V_8 + V_31 ) ;
F_25 ( V_2 -> V_79 ) ;
return 0 ;
}
static int F_61 ( struct V_85 * V_45 , unsigned V_3 )
{
struct V_1 * V_2 =
F_32 ( V_45 , struct V_1 , V_45 ) ;
T_1 V_5 = 1 << V_3 ;
int V_56 ;
F_23 ( V_2 -> V_79 ) ;
V_56 = ( F_2 ( V_2 -> V_8 + V_120 ) & V_5 ) != 0 ;
F_25 ( V_2 -> V_79 ) ;
return V_56 ;
}
static void F_62 ( struct V_85 * V_45 , unsigned V_3 ,
int V_32 )
{
struct V_1 * V_2 =
F_32 ( V_45 , struct V_1 , V_45 ) ;
F_23 ( V_2 -> V_79 ) ;
F_10 ( V_2 , V_3 , V_32 ) ;
F_25 ( V_2 -> V_79 ) ;
}
static int F_63 ( struct V_85 * V_45 , unsigned V_3 ,
int V_32 )
{
struct V_1 * V_2 =
F_32 ( V_45 , struct V_1 , V_45 ) ;
F_23 ( V_2 -> V_79 ) ;
F_11 ( V_2 , V_3 , V_32 ) ;
F_25 ( V_2 -> V_79 ) ;
return 0 ;
}
static void F_64 ( struct V_121 * V_122 ,
struct V_80 * V_81 , struct V_85 * V_45 ,
unsigned V_3 , unsigned V_44 )
{
const char * V_123 = F_65 ( V_45 , V_3 ) ;
struct V_1 * V_2 =
F_32 ( V_45 , struct V_1 , V_45 ) ;
int V_14 ;
bool V_124 ;
bool V_19 ;
T_1 V_5 = 1 << V_3 ;
const char * V_125 [] = {
[ V_126 ] = L_7 ,
[ V_11 ] = L_8 ,
[ V_12 ] = L_9 ,
[ V_82 ] = L_10 ,
[ V_82 + 1 ] = L_11 ,
[ V_82 + 2 ] = L_12 ,
[ V_82 + 3 ] = L_13 ,
[ V_82 + 4 ] = L_14 ,
} ;
F_23 ( V_2 -> V_79 ) ;
V_124 = ! ! ( F_2 ( V_2 -> V_8 + V_127 ) & V_5 ) ;
V_19 = ! ( F_2 ( V_2 -> V_8 + V_21 ) & V_5 ) ;
V_14 = F_28 ( V_44 ) ;
if ( ( V_14 == V_82 ) && V_81 )
V_14 = F_26 ( V_81 , V_44 ) ;
F_66 ( V_122 , L_15 ,
V_44 , V_123 ? : L_16 ,
V_124 ? L_17 : L_18 ,
V_45 -> V_128
? ( V_45 -> V_128 ( V_45 , V_3 ) ? L_19 : L_20 )
: L_21 ,
( V_14 < 0 ) ? L_22 : V_125 [ V_14 ] ,
V_19 ? L_23 : L_24 ) ;
if ( ! V_124 ) {
int V_47 = F_67 ( V_44 ) ;
struct V_112 * V_113 = F_68 ( V_47 ) ;
if ( V_47 > 0 && V_113 && V_113 -> V_129 ) {
char * V_130 ;
T_1 V_91 = F_29 ( V_44 ) ;
if ( V_2 -> V_97 & V_91 )
V_130 = L_25 ;
else if ( V_2 -> V_98 & V_91 )
V_130 = L_26 ;
else
V_130 = L_27 ;
F_66 ( V_122 , L_28 ,
V_47 , V_130 ,
F_44 ( & V_113 -> V_49 )
? L_29 : L_30 ) ;
}
}
F_25 ( V_2 -> V_79 ) ;
}
static void F_69 ( struct V_121 * V_122 , struct V_85 * V_45 )
{
unsigned V_60 ;
unsigned V_44 = V_45 -> V_46 ;
for ( V_60 = 0 ; V_60 < V_45 -> V_131 ; V_60 ++ , V_44 ++ ) {
F_64 ( V_122 , NULL , V_45 , V_60 , V_44 ) ;
F_66 ( V_122 , L_31 ) ;
}
}
static inline void F_64 ( struct V_121 * V_122 ,
struct V_80 * V_81 ,
struct V_85 * V_45 ,
unsigned V_3 , unsigned V_44 )
{
}
void F_70 ( void )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_76 ; V_60 ++ ) {
struct V_1 * V_45 = V_77 [ V_60 ] ;
if ( ! V_45 )
continue;
F_23 ( V_45 -> V_79 ) ;
}
}
void F_71 ( void )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_76 ; V_60 ++ ) {
struct V_1 * V_45 = V_77 [ V_60 ] ;
if ( ! V_45 )
continue;
F_25 ( V_45 -> V_79 ) ;
}
}
void F_72 ( void )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_76 ; V_60 ++ ) {
struct V_1 * V_45 = V_77 [ V_60 ] ;
if ( ! V_45 )
break;
F_23 ( V_45 -> V_79 ) ;
F_3 ( V_45 -> V_35 & V_45 -> V_106 ,
V_45 -> V_8 + V_38 ) ;
F_3 ( V_45 -> V_36 & V_45 -> V_106 ,
V_45 -> V_8 + V_39 ) ;
F_25 ( V_45 -> V_79 ) ;
}
}
void F_73 ( void )
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
void F_74 ( int V_132 , T_1 * V_23 )
{
if ( V_132 < V_76 ) {
struct V_1 * V_45 = V_77 [ V_132 ] ;
if ( ! V_45 )
return;
* V_23 = V_45 -> V_23 ;
}
}
static int F_75 ( struct V_133 * V_53 )
{
struct V_134 * V_135 = V_53 -> V_53 . V_136 ;
struct V_1 * V_2 ;
struct V_85 * V_45 ;
struct V_137 * V_138 ;
struct V_79 * V_79 ;
int V_139 ;
bool V_140 ;
void T_2 * V_46 ;
int V_47 ;
int V_141 ;
if ( F_76 ( V_135 , L_32 , NULL ) )
V_140 = true ;
else
V_140 = false ;
if ( F_77 ( V_135 , L_33 , & V_53 -> V_142 ) ) {
F_20 ( & V_53 -> V_53 , L_34 ) ;
return - V_84 ;
}
V_47 = F_78 ( V_53 , 0 ) ;
if ( V_47 < 0 )
return V_47 ;
V_139 = F_78 ( V_53 , 1 ) ;
V_138 = F_79 ( V_53 , V_143 , 0 ) ;
V_46 = F_80 ( & V_53 -> V_53 , V_138 ) ;
if ( F_81 ( V_46 ) )
return F_82 ( V_46 ) ;
V_79 = F_83 ( & V_53 -> V_53 , NULL ) ;
if ( F_81 ( V_79 ) )
return F_82 ( V_79 ) ;
F_84 ( V_79 ) ;
V_2 = F_85 ( & V_53 -> V_53 , sizeof( * V_2 ) , V_144 ) ;
if ( ! V_2 )
return - V_145 ;
V_2 -> V_119 = V_53 -> V_142 ;
V_2 -> V_79 = V_79 ;
V_2 -> V_8 = V_46 ;
V_2 -> V_45 = V_146 ;
V_2 -> V_147 = V_47 ;
V_2 -> V_148 = V_139 ;
V_2 -> V_100 = V_140 ;
F_86 ( & V_2 -> V_105 ) ;
V_45 = & V_2 -> V_45 ;
V_45 -> V_46 = V_53 -> V_142 * V_83 ;
V_45 -> V_131 = V_83 ;
V_45 -> V_123 = F_87 ( & V_53 -> V_53 ) ;
V_45 -> V_53 = & V_53 -> V_53 ;
V_45 -> V_149 = V_150 ;
F_23 ( V_2 -> V_79 ) ;
V_2 -> V_28 = F_88 ( V_2 -> V_8 + V_30 ) ;
F_25 ( V_2 -> V_79 ) ;
V_45 -> V_136 = V_135 ;
V_141 = F_89 ( & V_2 -> V_45 ) ;
if ( V_141 )
return V_141 ;
F_90 ( V_2 -> V_119 >= F_91 ( V_77 ) ) ;
V_77 [ V_2 -> V_119 ] = V_2 ;
F_92 ( V_53 , V_2 ) ;
V_141 = F_93 ( & V_2 -> V_45 ,
& V_151 ,
0 ,
V_152 ,
V_111 ) ;
if ( V_141 ) {
F_20 ( & V_53 -> V_53 , L_35 ) ;
V_141 = F_94 ( & V_2 -> V_45 ) ;
return - V_153 ;
}
F_95 ( & V_2 -> V_45 ,
& V_151 ,
V_2 -> V_147 ,
F_54 ) ;
if ( V_2 -> V_148 > 0 )
F_95 ( & V_2 -> V_45 ,
& V_151 ,
V_2 -> V_148 ,
F_55 ) ;
F_96 ( & V_53 -> V_53 , L_36 , V_2 -> V_8 ) ;
return 0 ;
}
static int F_97 ( struct V_80 * V_81 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
return V_58 -> V_67 -> V_154 ;
}
static const char * F_98 ( struct V_80 * V_81 ,
unsigned V_155 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
return V_58 -> V_67 -> V_156 [ V_155 ] . V_157 ;
}
static int F_99 ( struct V_80 * V_81 , unsigned V_155 ,
const unsigned * * V_158 ,
unsigned * V_159 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
* V_158 = V_58 -> V_67 -> V_156 [ V_155 ] . V_158 ;
* V_159 = V_58 -> V_67 -> V_156 [ V_155 ] . V_160 ;
return 0 ;
}
static struct V_161 *
F_100 ( struct V_80 * V_81 , unsigned V_3 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_58 -> V_67 -> V_162 ; V_60 ++ ) {
struct V_161 * V_163 ;
V_163 = & V_58 -> V_67 -> V_164 [ V_60 ] ;
if ( V_3 >= V_163 -> V_165 &&
V_3 <= ( V_163 -> V_165 + V_163 -> V_160 - 1 ) )
return V_163 ;
}
return NULL ;
}
static void F_101 ( struct V_80 * V_81 , struct V_121 * V_122 ,
unsigned V_3 )
{
struct V_161 * V_163 ;
struct V_85 * V_45 ;
V_163 = F_100 ( V_81 , V_3 ) ;
if ( ! V_163 || ! V_163 -> V_166 ) {
F_66 ( V_122 , L_37 ) ;
return;
}
V_45 = V_163 -> V_166 ;
F_64 ( V_122 , V_81 , V_45 , V_3 - V_45 -> V_46 , V_3 ) ;
}
static void F_102 ( struct V_80 * V_81 ,
struct V_167 * V_168 , unsigned V_169 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_169 ; V_60 ++ )
if ( V_168 [ V_60 ] . type == V_170 )
F_103 ( V_168 [ V_60 ] . V_171 . V_172 . V_172 ) ;
F_103 ( V_168 ) ;
}
static int F_104 ( struct V_167 * * V_168 , unsigned * V_173 ,
unsigned * V_169 , unsigned V_174 )
{
unsigned V_175 = * V_173 ;
unsigned V_176 = * V_169 + V_174 ;
struct V_167 * V_177 ;
if ( V_175 >= V_176 )
return 0 ;
V_177 = F_105 ( * V_168 , sizeof( * V_177 ) * V_176 , V_144 ) ;
if ( ! V_177 )
return - V_145 ;
memset ( V_177 + V_175 , 0 , ( V_176 - V_175 ) * sizeof( * V_177 ) ) ;
* V_168 = V_177 ;
* V_173 = V_176 ;
return 0 ;
}
static int F_106 ( struct V_167 * * V_168 , unsigned * V_173 ,
unsigned * V_169 , const char * V_178 ,
const char * V_179 )
{
if ( * V_169 == * V_173 )
return - V_180 ;
( * V_168 ) [ * V_169 ] . type = V_181 ;
( * V_168 ) [ * V_169 ] . V_171 . V_182 . V_178 = V_178 ;
( * V_168 ) [ * V_169 ] . V_171 . V_182 . V_179 = V_179 ;
( * V_169 ) ++ ;
return 0 ;
}
static int F_107 ( struct V_167 * * V_168 ,
unsigned * V_173 ,
unsigned * V_169 , const char * V_178 ,
unsigned long * V_172 , unsigned V_183 )
{
unsigned long * V_184 ;
if ( * V_169 == * V_173 )
return - V_180 ;
V_184 = F_108 ( V_172 , V_183 * sizeof( * V_184 ) ,
V_144 ) ;
if ( ! V_184 )
return - V_145 ;
( * V_168 ) [ * V_169 ] . type = V_170 ;
( * V_168 ) [ * V_169 ] . V_171 . V_172 . V_185 = V_178 ;
( * V_168 ) [ * V_169 ] . V_171 . V_172 . V_172 = V_184 ;
( * V_168 ) [ * V_169 ] . V_171 . V_172 . V_183 = V_183 ;
( * V_169 ) ++ ;
return 0 ;
}
static int F_109 ( int V_186 , int V_32 , unsigned long * V_187 )
{
int V_141 = 0 ;
if ( V_188 [ V_186 ] . V_189 == NULL )
* V_187 = V_188 [ V_186 ] . V_187 ;
else {
if ( V_32 < V_188 [ V_186 ] . V_190 ) {
* V_187 = V_188 [ V_186 ] . V_187 |
V_188 [ V_186 ] . V_189 [ V_32 ] ;
}
}
return V_141 ;
}
static const char * F_110 ( struct V_80 * V_81 , const char * V_191 )
{
int V_60 , V_192 ;
struct V_57 * V_58 = F_27 ( V_81 ) ;
if ( sscanf ( ( char * ) V_191 , L_38 , & V_192 ) == 1 )
for ( V_60 = 0 ; V_60 < V_58 -> V_67 -> V_160 ; V_60 ++ )
if ( V_58 -> V_67 -> V_158 [ V_60 ] . V_193 == V_192 )
return V_58 -> V_67 -> V_158 [ V_60 ] . V_157 ;
return NULL ;
}
static bool F_111 ( struct V_134 * V_135 ,
unsigned long * V_172 )
{
bool V_194 = 0 ;
unsigned long V_195 = 0 ;
int V_60 , V_32 , V_141 ;
for ( V_60 = 0 ; V_60 < F_91 ( V_188 ) ; V_60 ++ ) {
V_141 = F_77 ( V_135 ,
V_188 [ V_60 ] . V_196 , & V_32 ) ;
if ( V_141 != - V_84 ) {
if ( F_109 ( V_60 , V_32 , & V_195 ) == 0 ) {
* V_172 |= V_195 ;
V_194 = 1 ;
}
}
}
return V_194 ;
}
static int F_112 ( struct V_80 * V_81 ,
struct V_134 * V_135 ,
struct V_167 * * V_168 ,
unsigned * V_173 ,
unsigned * V_169 )
{
int V_141 ;
const char * V_179 = NULL ;
unsigned long V_172 = 0 ;
bool V_194 = 0 ;
unsigned V_174 = 0 ;
struct V_196 * V_197 ;
const char * V_178 , * V_198 ;
struct V_134 * V_199 ;
V_141 = F_113 ( V_135 , L_39 , & V_179 ) ;
if ( V_141 >= 0 )
V_174 = 1 ;
V_194 = F_111 ( V_135 , & V_172 ) ;
V_199 = F_114 ( V_135 , L_40 , 0 ) ;
if ( V_199 )
V_194 |= F_111 ( V_199 , & V_172 ) ;
V_141 = F_115 ( V_135 , L_41 ) ;
if ( V_141 < 0 )
goto exit;
if ( V_194 )
V_174 ++ ;
V_174 *= V_141 ;
V_141 = F_104 ( V_168 , V_173 , V_169 , V_174 ) ;
if ( V_141 < 0 )
goto exit;
F_116 (np, L_41 , prop, group) {
if ( V_179 ) {
V_141 = F_106 ( V_168 , V_173 , V_169 ,
V_178 , V_179 ) ;
if ( V_141 < 0 )
goto exit;
}
if ( V_194 ) {
V_198 = F_110 ( V_81 , V_178 ) ;
V_141 = F_107 ( V_168 , V_173 , V_169 ,
V_198 , & V_172 , 1 ) ;
if ( V_141 < 0 )
goto exit;
}
}
exit:
return V_141 ;
}
static int F_117 ( struct V_80 * V_81 ,
struct V_134 * V_199 ,
struct V_167 * * V_168 , unsigned * V_169 )
{
unsigned V_173 ;
struct V_134 * V_135 ;
int V_141 ;
V_173 = 0 ;
* V_168 = NULL ;
* V_169 = 0 ;
F_118 (np_config, np) {
V_141 = F_112 ( V_81 , V_135 , V_168 ,
& V_173 , V_169 ) ;
if ( V_141 < 0 ) {
F_102 ( V_81 , * V_168 , * V_169 ) ;
return V_141 ;
}
}
return 0 ;
}
static int F_119 ( struct V_80 * V_81 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
return V_58 -> V_67 -> V_200 ;
}
static const char * F_120 ( struct V_80 * V_81 ,
unsigned V_179 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
return V_58 -> V_67 -> V_201 [ V_179 ] . V_157 ;
}
static int F_121 ( struct V_80 * V_81 ,
unsigned V_179 ,
const char * const * * V_156 ,
unsigned * const V_202 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
* V_156 = V_58 -> V_67 -> V_201 [ V_179 ] . V_156 ;
* V_202 = V_58 -> V_67 -> V_201 [ V_179 ] . V_154 ;
return 0 ;
}
static int F_122 ( struct V_80 * V_81 , unsigned V_179 ,
unsigned V_178 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
const struct V_203 * V_204 ;
static unsigned int V_15 [ V_76 ] ;
unsigned long V_103 = 0 ;
bool V_34 ;
int V_141 = - V_84 ;
int V_60 ;
V_204 = & V_58 -> V_67 -> V_156 [ V_178 ] ;
if ( V_204 -> V_205 < 0 )
return - V_84 ;
F_17 ( V_58 -> V_53 , L_42 , V_204 -> V_157 , V_204 -> V_160 ) ;
V_34 = ( ( V_204 -> V_205 & V_82 ) == V_82 ) ;
if ( V_34 ) {
F_36 ( & V_104 , V_103 ) ;
memset ( V_15 , 0xff , sizeof( V_15 ) ) ;
for ( V_60 = 0 ; V_60 < V_204 -> V_160 ; V_60 ++ )
V_15 [ V_204 -> V_158 [ V_60 ] / V_83 ] &= ~ F_7 ( V_204 -> V_158 [ V_60 ] ) ;
F_22 ( V_15 ) ;
}
for ( V_60 = 0 ; V_60 < V_204 -> V_160 ; V_60 ++ ) {
struct V_161 * V_163 ;
struct V_1 * V_2 ;
struct V_85 * V_45 ;
unsigned V_5 ;
V_163 = F_100 ( V_81 , V_204 -> V_158 [ V_60 ] ) ;
if ( ! V_163 ) {
F_20 ( V_58 -> V_53 ,
L_43 ,
V_204 -> V_158 [ V_60 ] , V_204 -> V_157 , V_60 ) ;
goto V_206;
}
if ( ! V_163 -> V_166 ) {
F_20 ( V_58 -> V_53 , L_44 ,
V_204 -> V_158 [ V_60 ] , V_204 -> V_157 , V_60 ) ;
goto V_206;
}
V_45 = V_163 -> V_166 ;
V_2 = F_32 ( V_45 , struct V_1 , V_45 ) ;
F_17 ( V_58 -> V_53 , L_45 , V_204 -> V_158 [ V_60 ] , V_204 -> V_205 ) ;
F_23 ( V_2 -> V_79 ) ;
V_5 = V_204 -> V_158 [ V_60 ] % V_83 ;
F_13 ( V_2 , V_5 ) ;
F_12 ( V_2 , V_5 ,
( V_204 -> V_205 & V_82 ) , V_34 ) ;
F_25 ( V_2 -> V_79 ) ;
if ( ( V_204 -> V_205 & V_82 ) == V_82 )
F_19 ( V_58 , V_204 -> V_158 [ V_60 ] ,
V_204 -> V_205 >> V_207 ) ;
}
V_141 = 0 ;
V_206:
if ( V_34 ) {
F_24 ( V_15 ) ;
F_39 ( & V_104 , V_103 ) ;
}
return V_141 ;
}
static void F_123 ( struct V_80 * V_81 ,
unsigned V_179 , unsigned V_178 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
const struct V_203 * V_204 ;
V_204 = & V_58 -> V_67 -> V_156 [ V_178 ] ;
if ( V_204 -> V_205 < 0 )
return;
F_17 ( V_58 -> V_53 , L_46 , V_204 -> V_157 , V_204 -> V_160 ) ;
}
static int F_124 ( struct V_80 * V_81 ,
struct V_161 * V_163 ,
unsigned V_3 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
struct V_1 * V_2 ;
struct V_85 * V_45 ;
unsigned V_5 ;
if ( ! V_163 ) {
F_20 ( V_58 -> V_53 , L_47 ) ;
return - V_84 ;
}
if ( ! V_163 -> V_166 ) {
F_20 ( V_58 -> V_53 , L_48 ) ;
return - V_84 ;
}
V_45 = V_163 -> V_166 ;
V_2 = F_32 ( V_45 , struct V_1 , V_45 ) ;
F_17 ( V_58 -> V_53 , L_49 , V_3 ) ;
F_23 ( V_2 -> V_79 ) ;
V_5 = V_3 % V_83 ;
F_1 ( V_2 , V_5 , V_126 ) ;
F_25 ( V_2 -> V_79 ) ;
return 0 ;
}
static void F_125 ( struct V_80 * V_81 ,
struct V_161 * V_163 ,
unsigned V_3 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
F_17 ( V_58 -> V_53 , L_50 , V_3 ) ;
}
static int F_126 ( struct V_80 * V_81 , unsigned V_70 ,
unsigned long * V_187 )
{
return - V_84 ;
}
static int F_127 ( struct V_80 * V_81 , unsigned V_70 ,
unsigned long * V_172 , unsigned V_183 )
{
static const char * V_208 [] = {
[ V_22 ] = L_24 ,
[ V_24 ] = L_51 ,
[ V_26 ] = L_52 ,
[ 3 ] = L_53
} ;
static const char * V_209 [] = {
[ V_210 ] = L_54 ,
[ V_17 ] = L_55 ,
} ;
struct V_57 * V_58 = F_27 ( V_81 ) ;
struct V_1 * V_2 ;
struct V_161 * V_163 ;
struct V_85 * V_45 ;
unsigned V_5 ;
T_6 V_195 ;
int V_19 , V_15 , V_211 , V_32 , V_60 ;
bool V_28 , V_212 , V_213 ;
V_163 = F_100 ( V_81 , V_70 ) ;
if ( ! V_163 ) {
F_20 ( V_58 -> V_53 , L_56 , V_70 ) ;
return - V_84 ;
}
if ( ! V_163 -> V_166 ) {
F_20 ( V_58 -> V_53 , L_57 ,
V_70 ) ;
return - V_84 ;
}
V_45 = V_163 -> V_166 ;
V_2 = F_32 ( V_45 , struct V_1 , V_45 ) ;
for ( V_60 = 0 ; V_60 < V_183 ; V_60 ++ ) {
V_195 = ( T_6 ) V_172 [ V_60 ] ;
V_19 = F_128 ( V_195 ) ;
V_15 = F_129 ( V_195 ) ;
V_211 = F_130 ( V_195 ) ;
V_32 = F_131 ( V_195 ) ;
V_28 = F_132 ( V_195 ) ;
V_212 = F_133 ( V_195 ) ;
V_213 = F_134 ( V_195 ) ;
if ( V_213 ) {
int V_214 = F_135 ( V_195 ) ;
int V_215 = F_136 ( V_195 ) ;
int V_216 = F_137 ( V_195 ) ;
V_212 = true ;
if ( V_214 )
V_19 = V_214 - 1 ;
if ( V_215 )
V_211 = V_215 - 1 ;
if ( V_216 )
V_32 = V_216 - 1 ;
F_17 ( V_2 -> V_45 . V_53 ,
L_58 ,
V_70 ,
V_214 ? V_208 [ V_19 ] : L_59 ,
V_215 ? ( V_211 ? L_60 : L_61 )
: L_59 ,
V_216 ? ( V_32 ? L_62 : L_63 ) : L_59 ) ;
}
F_17 ( V_2 -> V_45 . V_53 ,
L_64 ,
V_70 , V_195 , V_208 [ V_19 ] , V_209 [ V_15 ] ,
V_211 ? L_65 : L_61 ,
V_211 ? ( V_32 ? L_62 : L_63 ) : L_30 ,
V_28 ? L_66 : L_67 ) ;
F_23 ( V_2 -> V_79 ) ;
V_5 = V_70 % V_83 ;
if ( V_212 )
F_1 ( V_2 , V_5 , V_126 ) ;
if ( V_211 )
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
static int F_138 ( struct V_217 * V_53 )
{
struct V_57 * V_58 ;
V_58 = F_139 ( V_53 ) ;
if ( ! V_58 )
return - V_84 ;
return F_140 ( V_58 -> V_218 ) ;
}
static int F_141 ( struct V_217 * V_53 )
{
struct V_57 * V_58 ;
V_58 = F_139 ( V_53 ) ;
if ( ! V_58 )
return - V_84 ;
return F_142 ( V_58 -> V_218 ) ;
}
static int F_143 ( struct V_133 * V_219 )
{
const struct V_220 * V_221 ;
struct V_134 * V_135 = V_219 -> V_53 . V_136 ;
struct V_134 * V_222 ;
struct V_57 * V_58 ;
unsigned int V_223 = 0 ;
int V_60 ;
V_58 = F_85 ( & V_219 -> V_53 , sizeof( * V_58 ) , V_144 ) ;
if ( ! V_58 )
return - V_145 ;
V_221 = F_144 ( V_224 , & V_219 -> V_53 ) ;
if ( ! V_221 )
return - V_153 ;
V_223 = ( unsigned int ) V_221 -> V_171 ;
if ( V_223 == V_225 )
F_145 ( & V_58 -> V_67 ) ;
if ( V_223 == V_226 )
F_146 ( & V_58 -> V_67 ) ;
if ( V_223 == V_227 )
F_147 ( & V_58 -> V_67 ) ;
V_222 = F_114 ( V_135 , L_68 , 0 ) ;
if ( V_222 )
V_58 -> V_65 = F_148 ( V_222 , 0 ) ;
if ( ! V_58 -> V_65 ) {
if ( V_223 == V_225 ) {
F_96 ( & V_219 -> V_53 ,
L_69
L_70 ) ;
} else {
F_20 ( & V_219 -> V_53 , L_71 ) ;
return - V_84 ;
}
}
for ( V_60 = 0 ; V_60 < V_58 -> V_67 -> V_162 ; V_60 ++ ) {
if ( ! V_77 [ V_58 -> V_67 -> V_164 [ V_60 ] . V_142 ] ) {
F_21 ( & V_219 -> V_53 , L_72 , V_60 ) ;
return - V_228 ;
}
V_58 -> V_67 -> V_164 [ V_60 ] . V_166 = & V_77 [ V_58 -> V_67 -> V_164 [ V_60 ] . V_142 ] -> V_45 ;
}
V_229 . V_158 = V_58 -> V_67 -> V_158 ;
V_229 . V_160 = V_58 -> V_67 -> V_160 ;
V_58 -> V_53 = & V_219 -> V_53 ;
V_58 -> V_218 = F_149 ( & V_229 , & V_219 -> V_53 , V_58 ) ;
if ( ! V_58 -> V_218 ) {
F_20 ( & V_219 -> V_53 , L_73 ) ;
return - V_84 ;
}
for ( V_60 = 0 ; V_60 < V_58 -> V_67 -> V_162 ; V_60 ++ )
F_150 ( V_58 -> V_218 , & V_58 -> V_67 -> V_164 [ V_60 ] ) ;
F_92 ( V_219 , V_58 ) ;
F_96 ( & V_219 -> V_53 , L_74 ) ;
return 0 ;
}
static int T_7 F_151 ( void )
{
int V_141 ;
V_141 = F_152 ( & V_230 ) ;
if ( V_141 )
return V_141 ;
return F_152 ( & V_231 ) ;
}

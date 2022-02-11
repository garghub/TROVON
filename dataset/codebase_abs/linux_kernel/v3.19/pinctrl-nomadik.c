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
bool V_125 ;
bool V_19 ;
T_1 V_5 = 1 << V_3 ;
const char * V_126 [] = {
[ V_127 ] = L_7 ,
[ V_11 ] = L_8 ,
[ V_12 ] = L_9 ,
[ V_82 ] = L_10 ,
[ V_82 + 1 ] = L_11 ,
[ V_82 + 2 ] = L_12 ,
[ V_82 + 3 ] = L_13 ,
[ V_82 + 4 ] = L_14 ,
} ;
const char * V_128 [] = {
L_15 ,
L_16 ,
L_17 ,
} ;
F_23 ( V_2 -> V_79 ) ;
V_124 = ! ! ( F_2 ( V_2 -> V_8 + V_129 ) & V_5 ) ;
V_19 = ! ( F_2 ( V_2 -> V_8 + V_21 ) & V_5 ) ;
V_125 = ! ! ( F_2 ( V_2 -> V_8 + V_120 ) & V_5 ) ;
V_14 = F_28 ( V_44 ) ;
if ( ( V_14 == V_82 ) && V_81 )
V_14 = F_26 ( V_81 , V_44 ) ;
if ( V_124 ) {
F_66 ( V_122 , L_18 ,
V_44 ,
V_123 ? : L_19 ,
V_125 ? L_20 : L_21 ,
( V_14 < 0 ) ? L_22 : V_126 [ V_14 ] ) ;
} else {
int V_47 = F_67 ( V_44 ) ;
struct V_112 * V_113 = F_68 ( V_47 ) ;
int V_130 = 0 ;
if ( V_19 )
V_130 = V_125 ? 1 : 2 ;
F_66 ( V_122 , L_23 ,
V_44 ,
V_123 ? : L_19 ,
V_128 [ V_130 ] ,
( V_14 < 0 ) ? L_22 : V_126 [ V_14 ] ) ;
if ( V_47 > 0 && V_113 && V_113 -> V_131 ) {
char * V_132 ;
T_1 V_91 = F_29 ( V_44 ) ;
if ( V_2 -> V_97 & V_91 )
V_132 = L_24 ;
else if ( V_2 -> V_98 & V_91 )
V_132 = L_25 ;
else
V_132 = L_26 ;
F_66 ( V_122 , L_27 ,
V_47 , V_132 ,
F_44 ( & V_113 -> V_49 )
? L_28 : L_29 ) ;
}
}
F_25 ( V_2 -> V_79 ) ;
}
static void F_69 ( struct V_121 * V_122 , struct V_85 * V_45 )
{
unsigned V_60 ;
unsigned V_44 = V_45 -> V_46 ;
for ( V_60 = 0 ; V_60 < V_45 -> V_133 ; V_60 ++ , V_44 ++ ) {
F_64 ( V_122 , NULL , V_45 , V_60 , V_44 ) ;
F_66 ( V_122 , L_30 ) ;
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
void F_74 ( int V_134 , T_1 * V_23 )
{
if ( V_134 < V_76 ) {
struct V_1 * V_45 = V_77 [ V_134 ] ;
if ( ! V_45 )
return;
* V_23 = V_45 -> V_23 ;
}
}
static int F_75 ( struct V_135 * V_53 )
{
struct V_136 * V_137 = V_53 -> V_53 . V_138 ;
struct V_1 * V_2 ;
struct V_85 * V_45 ;
struct V_139 * V_140 ;
struct V_79 * V_79 ;
int V_141 ;
bool V_142 ;
void T_2 * V_46 ;
int V_47 ;
int V_143 ;
if ( F_76 ( V_137 , L_31 , NULL ) )
V_142 = true ;
else
V_142 = false ;
if ( F_77 ( V_137 , L_32 , & V_53 -> V_144 ) ) {
F_20 ( & V_53 -> V_53 , L_33 ) ;
return - V_84 ;
}
V_47 = F_78 ( V_53 , 0 ) ;
if ( V_47 < 0 )
return V_47 ;
V_141 = F_78 ( V_53 , 1 ) ;
V_140 = F_79 ( V_53 , V_145 , 0 ) ;
V_46 = F_80 ( & V_53 -> V_53 , V_140 ) ;
if ( F_81 ( V_46 ) )
return F_82 ( V_46 ) ;
V_79 = F_83 ( & V_53 -> V_53 , NULL ) ;
if ( F_81 ( V_79 ) )
return F_82 ( V_79 ) ;
F_84 ( V_79 ) ;
V_2 = F_85 ( & V_53 -> V_53 , sizeof( * V_2 ) , V_146 ) ;
if ( ! V_2 )
return - V_147 ;
V_2 -> V_119 = V_53 -> V_144 ;
V_2 -> V_79 = V_79 ;
V_2 -> V_8 = V_46 ;
V_2 -> V_45 = V_148 ;
V_2 -> V_149 = V_47 ;
V_2 -> V_150 = V_141 ;
V_2 -> V_100 = V_142 ;
F_86 ( & V_2 -> V_105 ) ;
V_45 = & V_2 -> V_45 ;
V_45 -> V_46 = V_53 -> V_144 * V_83 ;
V_45 -> V_133 = V_83 ;
V_45 -> V_123 = F_87 ( & V_53 -> V_53 ) ;
V_45 -> V_53 = & V_53 -> V_53 ;
V_45 -> V_151 = V_152 ;
F_23 ( V_2 -> V_79 ) ;
V_2 -> V_28 = F_88 ( V_2 -> V_8 + V_30 ) ;
F_25 ( V_2 -> V_79 ) ;
V_45 -> V_138 = V_137 ;
V_143 = F_89 ( & V_2 -> V_45 ) ;
if ( V_143 )
return V_143 ;
F_90 ( V_2 -> V_119 >= F_91 ( V_77 ) ) ;
V_77 [ V_2 -> V_119 ] = V_2 ;
F_92 ( V_53 , V_2 ) ;
V_143 = F_93 ( & V_2 -> V_45 ,
& V_153 ,
0 ,
V_154 ,
V_111 ) ;
if ( V_143 ) {
F_20 ( & V_53 -> V_53 , L_34 ) ;
F_94 ( & V_2 -> V_45 ) ;
return - V_155 ;
}
F_95 ( & V_2 -> V_45 ,
& V_153 ,
V_2 -> V_149 ,
F_54 ) ;
if ( V_2 -> V_150 > 0 )
F_95 ( & V_2 -> V_45 ,
& V_153 ,
V_2 -> V_150 ,
F_55 ) ;
F_96 ( & V_53 -> V_53 , L_35 , V_2 -> V_8 ) ;
return 0 ;
}
static int F_97 ( struct V_80 * V_81 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
return V_58 -> V_67 -> V_156 ;
}
static const char * F_98 ( struct V_80 * V_81 ,
unsigned V_157 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
return V_58 -> V_67 -> V_158 [ V_157 ] . V_159 ;
}
static int F_99 ( struct V_80 * V_81 , unsigned V_157 ,
const unsigned * * V_160 ,
unsigned * V_161 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
* V_160 = V_58 -> V_67 -> V_158 [ V_157 ] . V_160 ;
* V_161 = V_58 -> V_67 -> V_158 [ V_157 ] . V_162 ;
return 0 ;
}
static struct V_163 *
F_100 ( struct V_80 * V_81 , unsigned V_3 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_58 -> V_67 -> V_164 ; V_60 ++ ) {
struct V_163 * V_165 ;
V_165 = & V_58 -> V_67 -> V_166 [ V_60 ] ;
if ( V_3 >= V_165 -> V_167 &&
V_3 <= ( V_165 -> V_167 + V_165 -> V_162 - 1 ) )
return V_165 ;
}
return NULL ;
}
static void F_101 ( struct V_80 * V_81 , struct V_121 * V_122 ,
unsigned V_3 )
{
struct V_163 * V_165 ;
struct V_85 * V_45 ;
V_165 = F_100 ( V_81 , V_3 ) ;
if ( ! V_165 || ! V_165 -> V_168 ) {
F_66 ( V_122 , L_36 ) ;
return;
}
V_45 = V_165 -> V_168 ;
F_64 ( V_122 , V_81 , V_45 , V_3 - V_45 -> V_46 , V_3 ) ;
}
static int F_102 ( struct V_169 * * V_170 , unsigned * V_171 ,
unsigned * V_172 , const char * V_173 ,
const char * V_174 )
{
if ( * V_172 == * V_171 )
return - V_175 ;
( * V_170 ) [ * V_172 ] . type = V_176 ;
( * V_170 ) [ * V_172 ] . V_177 . V_178 . V_173 = V_173 ;
( * V_170 ) [ * V_172 ] . V_177 . V_178 . V_174 = V_174 ;
( * V_172 ) ++ ;
return 0 ;
}
static int F_103 ( struct V_169 * * V_170 ,
unsigned * V_171 ,
unsigned * V_172 , const char * V_173 ,
unsigned long * V_179 , unsigned V_180 )
{
unsigned long * V_181 ;
if ( * V_172 == * V_171 )
return - V_175 ;
V_181 = F_104 ( V_179 , V_180 * sizeof( * V_181 ) ,
V_146 ) ;
if ( ! V_181 )
return - V_147 ;
( * V_170 ) [ * V_172 ] . type = V_182 ;
( * V_170 ) [ * V_172 ] . V_177 . V_179 . V_183 = V_173 ;
( * V_170 ) [ * V_172 ] . V_177 . V_179 . V_179 = V_181 ;
( * V_170 ) [ * V_172 ] . V_177 . V_179 . V_180 = V_180 ;
( * V_172 ) ++ ;
return 0 ;
}
static int F_105 ( int V_184 , int V_32 , unsigned long * V_185 )
{
int V_143 = 0 ;
if ( V_186 [ V_184 ] . V_187 == NULL )
* V_185 = V_186 [ V_184 ] . V_185 ;
else {
if ( V_32 < V_186 [ V_184 ] . V_188 ) {
* V_185 = V_186 [ V_184 ] . V_185 |
V_186 [ V_184 ] . V_187 [ V_32 ] ;
}
}
return V_143 ;
}
static const char * F_106 ( struct V_80 * V_81 , const char * V_189 )
{
int V_60 , V_190 ;
struct V_57 * V_58 = F_27 ( V_81 ) ;
if ( sscanf ( ( char * ) V_189 , L_37 , & V_190 ) == 1 )
for ( V_60 = 0 ; V_60 < V_58 -> V_67 -> V_162 ; V_60 ++ )
if ( V_58 -> V_67 -> V_160 [ V_60 ] . V_191 == V_190 )
return V_58 -> V_67 -> V_160 [ V_60 ] . V_159 ;
return NULL ;
}
static bool F_107 ( struct V_136 * V_137 ,
unsigned long * V_179 )
{
bool V_192 = 0 ;
unsigned long V_193 = 0 ;
int V_60 , V_32 , V_143 ;
for ( V_60 = 0 ; V_60 < F_91 ( V_186 ) ; V_60 ++ ) {
V_143 = F_77 ( V_137 ,
V_186 [ V_60 ] . V_194 , & V_32 ) ;
if ( V_143 != - V_84 ) {
if ( F_105 ( V_60 , V_32 , & V_193 ) == 0 ) {
* V_179 |= V_193 ;
V_192 = 1 ;
}
}
}
return V_192 ;
}
static int F_108 ( struct V_80 * V_81 ,
struct V_136 * V_137 ,
struct V_169 * * V_170 ,
unsigned * V_171 ,
unsigned * V_172 )
{
int V_143 ;
const char * V_174 = NULL ;
unsigned long V_179 = 0 ;
bool V_192 = 0 ;
struct V_194 * V_195 ;
struct V_136 * V_196 ;
V_143 = F_109 ( V_137 , L_38 , & V_174 ) ;
if ( V_143 >= 0 ) {
const char * V_173 ;
V_143 = F_110 ( V_137 , L_39 ) ;
if ( V_143 < 0 )
goto exit;
V_143 = F_111 ( V_81 , V_170 ,
V_171 ,
V_172 , V_143 ) ;
if ( V_143 < 0 )
goto exit;
F_112 (np, L_39 , prop, group) {
V_143 = F_102 ( V_170 , V_171 , V_172 ,
V_173 , V_174 ) ;
if ( V_143 < 0 )
goto exit;
}
}
V_192 = F_107 ( V_137 , & V_179 ) ;
V_196 = F_113 ( V_137 , L_40 , 0 ) ;
if ( V_196 )
V_192 |= F_107 ( V_196 , & V_179 ) ;
if ( V_192 ) {
const char * V_197 ;
const char * V_70 ;
V_143 = F_110 ( V_137 , L_41 ) ;
if ( V_143 < 0 )
goto exit;
V_143 = F_111 ( V_81 , V_170 ,
V_171 ,
V_172 , V_143 ) ;
if ( V_143 < 0 )
goto exit;
F_112 (np, L_41 , prop, pin) {
V_197 = F_106 ( V_81 , V_70 ) ;
V_143 = F_103 ( V_170 , V_171 ,
V_172 ,
V_197 , & V_179 , 1 ) ;
if ( V_143 < 0 )
goto exit;
}
}
exit:
return V_143 ;
}
static int F_114 ( struct V_80 * V_81 ,
struct V_136 * V_196 ,
struct V_169 * * V_170 , unsigned * V_172 )
{
unsigned V_171 ;
struct V_136 * V_137 ;
int V_143 ;
V_171 = 0 ;
* V_170 = NULL ;
* V_172 = 0 ;
F_115 (np_config, np) {
V_143 = F_108 ( V_81 , V_137 , V_170 ,
& V_171 , V_172 ) ;
if ( V_143 < 0 ) {
F_116 ( V_81 , * V_170 , * V_172 ) ;
return V_143 ;
}
}
return 0 ;
}
static int F_117 ( struct V_80 * V_81 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
return V_58 -> V_67 -> V_198 ;
}
static const char * F_118 ( struct V_80 * V_81 ,
unsigned V_174 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
return V_58 -> V_67 -> V_199 [ V_174 ] . V_159 ;
}
static int F_119 ( struct V_80 * V_81 ,
unsigned V_174 ,
const char * const * * V_158 ,
unsigned * const V_200 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
* V_158 = V_58 -> V_67 -> V_199 [ V_174 ] . V_158 ;
* V_200 = V_58 -> V_67 -> V_199 [ V_174 ] . V_156 ;
return 0 ;
}
static int F_120 ( struct V_80 * V_81 , unsigned V_174 ,
unsigned V_173 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
const struct V_201 * V_202 ;
static unsigned int V_15 [ V_76 ] ;
unsigned long V_103 = 0 ;
bool V_34 ;
int V_143 = - V_84 ;
int V_60 ;
V_202 = & V_58 -> V_67 -> V_158 [ V_173 ] ;
if ( V_202 -> V_203 < 0 )
return - V_84 ;
F_17 ( V_58 -> V_53 , L_42 , V_202 -> V_159 , V_202 -> V_162 ) ;
V_34 = ( ( V_202 -> V_203 & V_82 ) == V_82 ) ;
if ( V_34 ) {
F_36 ( & V_104 , V_103 ) ;
memset ( V_15 , 0xff , sizeof( V_15 ) ) ;
for ( V_60 = 0 ; V_60 < V_202 -> V_162 ; V_60 ++ )
V_15 [ V_202 -> V_160 [ V_60 ] / V_83 ] &= ~ F_7 ( V_202 -> V_160 [ V_60 ] ) ;
F_22 ( V_15 ) ;
}
for ( V_60 = 0 ; V_60 < V_202 -> V_162 ; V_60 ++ ) {
struct V_163 * V_165 ;
struct V_1 * V_2 ;
struct V_85 * V_45 ;
unsigned V_5 ;
V_165 = F_100 ( V_81 , V_202 -> V_160 [ V_60 ] ) ;
if ( ! V_165 ) {
F_20 ( V_58 -> V_53 ,
L_43 ,
V_202 -> V_160 [ V_60 ] , V_202 -> V_159 , V_60 ) ;
goto V_204;
}
if ( ! V_165 -> V_168 ) {
F_20 ( V_58 -> V_53 , L_44 ,
V_202 -> V_160 [ V_60 ] , V_202 -> V_159 , V_60 ) ;
goto V_204;
}
V_45 = V_165 -> V_168 ;
V_2 = F_32 ( V_45 , struct V_1 , V_45 ) ;
F_17 ( V_58 -> V_53 , L_45 , V_202 -> V_160 [ V_60 ] , V_202 -> V_203 ) ;
F_23 ( V_2 -> V_79 ) ;
V_5 = V_202 -> V_160 [ V_60 ] % V_83 ;
F_13 ( V_2 , V_5 ) ;
F_12 ( V_2 , V_5 ,
( V_202 -> V_203 & V_82 ) , V_34 ) ;
F_25 ( V_2 -> V_79 ) ;
if ( ( V_202 -> V_203 & V_82 ) == V_82 )
F_19 ( V_58 , V_202 -> V_160 [ V_60 ] ,
V_202 -> V_203 >> V_205 ) ;
}
V_143 = 0 ;
V_204:
if ( V_34 ) {
F_24 ( V_15 ) ;
F_39 ( & V_104 , V_103 ) ;
}
return V_143 ;
}
static int F_121 ( struct V_80 * V_81 ,
struct V_163 * V_165 ,
unsigned V_3 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
struct V_1 * V_2 ;
struct V_85 * V_45 ;
unsigned V_5 ;
if ( ! V_165 ) {
F_20 ( V_58 -> V_53 , L_46 ) ;
return - V_84 ;
}
if ( ! V_165 -> V_168 ) {
F_20 ( V_58 -> V_53 , L_47 ) ;
return - V_84 ;
}
V_45 = V_165 -> V_168 ;
V_2 = F_32 ( V_45 , struct V_1 , V_45 ) ;
F_17 ( V_58 -> V_53 , L_48 , V_3 ) ;
F_23 ( V_2 -> V_79 ) ;
V_5 = V_3 % V_83 ;
F_1 ( V_2 , V_5 , V_127 ) ;
F_25 ( V_2 -> V_79 ) ;
return 0 ;
}
static void F_122 ( struct V_80 * V_81 ,
struct V_163 * V_165 ,
unsigned V_3 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
F_17 ( V_58 -> V_53 , L_49 , V_3 ) ;
}
static int F_123 ( struct V_80 * V_81 , unsigned V_70 ,
unsigned long * V_185 )
{
return - V_84 ;
}
static int F_124 ( struct V_80 * V_81 , unsigned V_70 ,
unsigned long * V_179 , unsigned V_180 )
{
static const char * V_206 [] = {
[ V_22 ] = L_50 ,
[ V_24 ] = L_51 ,
[ V_26 ] = L_52 ,
[ 3 ] = L_53
} ;
static const char * V_207 [] = {
[ V_208 ] = L_54 ,
[ V_17 ] = L_55 ,
} ;
struct V_57 * V_58 = F_27 ( V_81 ) ;
struct V_1 * V_2 ;
struct V_163 * V_165 ;
struct V_85 * V_45 ;
unsigned V_5 ;
T_6 V_193 ;
int V_19 , V_15 , V_209 , V_32 , V_60 ;
bool V_28 , V_210 , V_211 ;
V_165 = F_100 ( V_81 , V_70 ) ;
if ( ! V_165 ) {
F_20 ( V_58 -> V_53 , L_56 , V_70 ) ;
return - V_84 ;
}
if ( ! V_165 -> V_168 ) {
F_20 ( V_58 -> V_53 , L_57 ,
V_70 ) ;
return - V_84 ;
}
V_45 = V_165 -> V_168 ;
V_2 = F_32 ( V_45 , struct V_1 , V_45 ) ;
for ( V_60 = 0 ; V_60 < V_180 ; V_60 ++ ) {
V_193 = ( T_6 ) V_179 [ V_60 ] ;
V_19 = F_125 ( V_193 ) ;
V_15 = F_126 ( V_193 ) ;
V_209 = F_127 ( V_193 ) ;
V_32 = F_128 ( V_193 ) ;
V_28 = F_129 ( V_193 ) ;
V_210 = F_130 ( V_193 ) ;
V_211 = F_131 ( V_193 ) ;
if ( V_211 ) {
int V_212 = F_132 ( V_193 ) ;
int V_213 = F_133 ( V_193 ) ;
int V_214 = F_134 ( V_193 ) ;
V_210 = true ;
if ( V_212 )
V_19 = V_212 - 1 ;
if ( V_213 )
V_209 = V_213 - 1 ;
if ( V_214 )
V_32 = V_214 - 1 ;
F_17 ( V_2 -> V_45 . V_53 ,
L_58 ,
V_70 ,
V_212 ? V_206 [ V_19 ] : L_59 ,
V_213 ? ( V_209 ? L_60 : L_61 )
: L_59 ,
V_214 ? ( V_32 ? L_62 : L_63 ) : L_59 ) ;
}
F_17 ( V_2 -> V_45 . V_53 ,
L_64 ,
V_70 , V_193 , V_206 [ V_19 ] , V_207 [ V_15 ] ,
V_209 ? L_65 : L_61 ,
V_209 ? ( V_32 ? L_62 : L_63 ) : L_29 ,
V_28 ? L_66 : L_67 ) ;
F_23 ( V_2 -> V_79 ) ;
V_5 = V_70 % V_83 ;
if ( V_210 )
F_1 ( V_2 , V_5 , V_127 ) ;
if ( V_209 )
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
static int F_135 ( struct V_215 * V_53 )
{
struct V_57 * V_58 ;
V_58 = F_136 ( V_53 ) ;
if ( ! V_58 )
return - V_84 ;
return F_137 ( V_58 -> V_216 ) ;
}
static int F_138 ( struct V_215 * V_53 )
{
struct V_57 * V_58 ;
V_58 = F_136 ( V_53 ) ;
if ( ! V_58 )
return - V_84 ;
return F_139 ( V_58 -> V_216 ) ;
}
static int F_140 ( struct V_135 * V_217 )
{
const struct V_218 * V_219 ;
struct V_136 * V_137 = V_217 -> V_53 . V_138 ;
struct V_136 * V_220 ;
struct V_57 * V_58 ;
unsigned int V_221 = 0 ;
int V_60 ;
V_58 = F_85 ( & V_217 -> V_53 , sizeof( * V_58 ) , V_146 ) ;
if ( ! V_58 )
return - V_147 ;
V_219 = F_141 ( V_222 , & V_217 -> V_53 ) ;
if ( ! V_219 )
return - V_155 ;
V_221 = ( unsigned int ) V_219 -> V_177 ;
if ( V_221 == V_223 )
F_142 ( & V_58 -> V_67 ) ;
if ( V_221 == V_224 )
F_143 ( & V_58 -> V_67 ) ;
if ( V_221 == V_225 )
F_144 ( & V_58 -> V_67 ) ;
V_220 = F_113 ( V_137 , L_68 , 0 ) ;
if ( V_220 )
V_58 -> V_65 = F_145 ( V_220 , 0 ) ;
if ( ! V_58 -> V_65 ) {
if ( V_221 == V_223 ) {
F_96 ( & V_217 -> V_53 ,
L_69
L_70 ) ;
} else {
F_20 ( & V_217 -> V_53 , L_71 ) ;
return - V_84 ;
}
}
for ( V_60 = 0 ; V_60 < V_58 -> V_67 -> V_164 ; V_60 ++ ) {
if ( ! V_77 [ V_58 -> V_67 -> V_166 [ V_60 ] . V_144 ] ) {
F_21 ( & V_217 -> V_53 , L_72 , V_60 ) ;
return - V_226 ;
}
V_58 -> V_67 -> V_166 [ V_60 ] . V_168 = & V_77 [ V_58 -> V_67 -> V_166 [ V_60 ] . V_144 ] -> V_45 ;
}
V_227 . V_160 = V_58 -> V_67 -> V_160 ;
V_227 . V_162 = V_58 -> V_67 -> V_162 ;
V_58 -> V_53 = & V_217 -> V_53 ;
V_58 -> V_216 = F_146 ( & V_227 , & V_217 -> V_53 , V_58 ) ;
if ( ! V_58 -> V_216 ) {
F_20 ( & V_217 -> V_53 , L_73 ) ;
return - V_84 ;
}
for ( V_60 = 0 ; V_60 < V_58 -> V_67 -> V_164 ; V_60 ++ )
F_147 ( V_58 -> V_216 , & V_58 -> V_67 -> V_166 [ V_60 ] ) ;
F_92 ( V_217 , V_58 ) ;
F_96 ( & V_217 -> V_53 , L_74 ) ;
return 0 ;
}
static int T_7 F_148 ( void )
{
int V_143 ;
V_143 = F_149 ( & V_228 ) ;
if ( V_143 )
return V_143 ;
return F_149 ( & V_229 ) ;
}

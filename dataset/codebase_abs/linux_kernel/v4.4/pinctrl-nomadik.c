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
static void F_47 ( struct V_112 * V_113 , T_1 V_114 )
{
struct V_115 * V_116 = F_48 ( V_113 ) ;
struct V_85 * V_45 = F_49 ( V_113 ) ;
F_50 ( V_116 , V_113 ) ;
while ( V_114 ) {
int V_5 = F_51 ( V_114 ) ;
F_52 ( F_14 ( V_45 -> V_48 , V_5 ) ) ;
V_114 &= ~ F_7 ( V_5 ) ;
}
F_53 ( V_116 , V_113 ) ;
}
static void F_54 ( struct V_112 * V_113 )
{
struct V_85 * V_45 = F_49 ( V_113 ) ;
struct V_1 * V_2 = F_32 ( V_45 , struct V_1 , V_45 ) ;
T_1 V_114 ;
F_23 ( V_2 -> V_79 ) ;
V_114 = F_2 ( V_2 -> V_8 + V_117 ) ;
F_25 ( V_2 -> V_79 ) ;
F_47 ( V_113 , V_114 ) ;
}
static void F_55 ( struct V_112 * V_113 )
{
struct V_85 * V_45 = F_49 ( V_113 ) ;
struct V_1 * V_2 = F_32 ( V_45 , struct V_1 , V_45 ) ;
T_1 V_114 = V_2 -> V_118 ( V_2 -> V_119 ) ;
F_47 ( V_113 , V_114 ) ;
}
static int F_56 ( struct V_85 * V_45 , unsigned V_3 )
{
struct V_1 * V_2 =
F_32 ( V_45 , struct V_1 , V_45 ) ;
F_23 ( V_2 -> V_79 ) ;
F_3 ( 1 << V_3 , V_2 -> V_8 + V_31 ) ;
F_25 ( V_2 -> V_79 ) ;
return 0 ;
}
static int F_57 ( struct V_85 * V_45 , unsigned V_3 )
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
static void F_58 ( struct V_85 * V_45 , unsigned V_3 ,
int V_32 )
{
struct V_1 * V_2 =
F_32 ( V_45 , struct V_1 , V_45 ) ;
F_23 ( V_2 -> V_79 ) ;
F_10 ( V_2 , V_3 , V_32 ) ;
F_25 ( V_2 -> V_79 ) ;
}
static int F_59 ( struct V_85 * V_45 , unsigned V_3 ,
int V_32 )
{
struct V_1 * V_2 =
F_32 ( V_45 , struct V_1 , V_45 ) ;
F_23 ( V_2 -> V_79 ) ;
F_11 ( V_2 , V_3 , V_32 ) ;
F_25 ( V_2 -> V_79 ) ;
return 0 ;
}
static void F_60 ( struct V_121 * V_122 ,
struct V_80 * V_81 , struct V_85 * V_45 ,
unsigned V_3 , unsigned V_44 )
{
const char * V_123 = F_61 ( V_45 , V_3 ) ;
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
F_62 ( V_122 , L_18 ,
V_44 ,
V_123 ? : L_19 ,
V_125 ? L_20 : L_21 ,
( V_14 < 0 ) ? L_22 : V_126 [ V_14 ] ) ;
} else {
int V_47 = F_63 ( V_44 ) ;
struct V_112 * V_113 = F_64 ( V_47 ) ;
int V_130 = 0 ;
int V_32 ;
if ( V_19 )
V_130 = V_125 ? 1 : 2 ;
F_62 ( V_122 , L_23 ,
V_44 ,
V_123 ? : L_19 ,
V_128 [ V_130 ] ,
( V_14 < 0 ) ? L_22 : V_126 [ V_14 ] ) ;
V_32 = F_57 ( V_45 , V_3 ) ;
F_62 ( V_122 , L_24 , V_32 ) ;
if ( V_47 > 0 && V_113 && V_113 -> V_131 ) {
char * V_132 ;
T_1 V_91 = F_29 ( V_44 ) ;
if ( V_2 -> V_97 & V_91 )
V_132 = L_25 ;
else if ( V_2 -> V_98 & V_91 )
V_132 = L_26 ;
else
V_132 = L_27 ;
F_62 ( V_122 , L_28 ,
V_47 , V_132 ,
F_44 ( & V_113 -> V_49 )
? L_29 : L_30 ) ;
}
}
F_25 ( V_2 -> V_79 ) ;
}
static void F_65 ( struct V_121 * V_122 , struct V_85 * V_45 )
{
unsigned V_60 ;
unsigned V_44 = V_45 -> V_46 ;
for ( V_60 = 0 ; V_60 < V_45 -> V_133 ; V_60 ++ , V_44 ++ ) {
F_60 ( V_122 , NULL , V_45 , V_60 , V_44 ) ;
F_62 ( V_122 , L_31 ) ;
}
}
static inline void F_60 ( struct V_121 * V_122 ,
struct V_80 * V_81 ,
struct V_85 * V_45 ,
unsigned V_3 , unsigned V_44 )
{
}
void F_66 ( void )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_76 ; V_60 ++ ) {
struct V_1 * V_45 = V_77 [ V_60 ] ;
if ( ! V_45 )
continue;
F_23 ( V_45 -> V_79 ) ;
}
}
void F_67 ( void )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_76 ; V_60 ++ ) {
struct V_1 * V_45 = V_77 [ V_60 ] ;
if ( ! V_45 )
continue;
F_25 ( V_45 -> V_79 ) ;
}
}
void F_68 ( void )
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
void F_69 ( void )
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
void F_70 ( int V_134 , T_1 * V_23 )
{
if ( V_134 < V_76 ) {
struct V_1 * V_45 = V_77 [ V_134 ] ;
if ( ! V_45 )
return;
* V_23 = V_45 -> V_23 ;
}
}
static struct V_1 * F_71 ( struct V_135 * V_136 ,
struct V_137 * V_138 )
{
struct V_1 * V_2 ;
struct V_137 * V_139 ;
struct V_85 * V_45 ;
struct V_140 * V_141 ;
struct V_79 * V_79 ;
void T_2 * V_46 ;
T_1 V_142 ;
V_139 = F_72 ( V_136 ) ;
if ( ! V_139 ) {
F_73 ( L_32 , V_136 -> V_143 ) ;
return F_74 ( - V_144 ) ;
}
if ( F_75 ( V_136 , L_33 , & V_142 ) ) {
F_20 ( & V_138 -> V_53 , L_34 ) ;
return F_74 ( - V_84 ) ;
}
V_2 = V_77 [ V_142 ] ;
if ( V_2 )
return V_2 ;
V_2 = F_76 ( & V_138 -> V_53 , sizeof( * V_2 ) , V_145 ) ;
if ( ! V_2 )
return F_74 ( - V_146 ) ;
V_2 -> V_119 = V_142 ;
V_45 = & V_2 -> V_45 ;
V_45 -> V_46 = V_142 * V_83 ;
V_45 -> V_133 = V_83 ;
V_45 -> V_123 = F_77 ( & V_139 -> V_53 ) ;
V_45 -> V_53 = & V_139 -> V_53 ;
V_141 = F_78 ( V_139 , V_147 , 0 ) ;
V_46 = F_79 ( & V_138 -> V_53 , V_141 ) ;
if ( F_80 ( V_46 ) )
return V_46 ;
V_2 -> V_8 = V_46 ;
V_79 = F_81 ( & V_139 -> V_53 , NULL ) ;
if ( F_80 ( V_79 ) )
return ( void * ) V_79 ;
F_82 ( V_79 ) ;
V_2 -> V_79 = V_79 ;
F_83 ( V_2 -> V_119 >= F_84 ( V_77 ) ) ;
V_77 [ V_142 ] = V_2 ;
return V_2 ;
}
static int F_85 ( struct V_137 * V_53 )
{
struct V_135 * V_136 = V_53 -> V_53 . V_148 ;
struct V_1 * V_2 ;
struct V_85 * V_45 ;
struct V_115 * V_149 ;
int V_150 ;
bool V_151 ;
int V_47 ;
int V_152 ;
V_2 = F_71 ( V_136 , V_53 ) ;
if ( F_80 ( V_2 ) ) {
F_20 ( & V_53 -> V_53 , L_35 ) ;
return F_86 ( V_2 ) ;
}
if ( F_87 ( V_136 , L_36 , NULL ) )
V_151 = true ;
else
V_151 = false ;
V_53 -> V_142 = V_2 -> V_119 ;
V_47 = F_88 ( V_53 , 0 ) ;
if ( V_47 < 0 )
return V_47 ;
V_150 = F_88 ( V_53 , 1 ) ;
V_2 -> V_153 = V_47 ;
V_2 -> V_154 = V_150 ;
V_2 -> V_100 = V_151 ;
F_89 ( & V_2 -> V_105 ) ;
V_45 = & V_2 -> V_45 ;
V_45 -> V_155 = V_156 ;
V_45 -> free = V_157 ;
V_45 -> V_158 = F_56 ;
V_45 -> V_159 = F_57 ;
V_45 -> V_160 = F_59 ;
V_45 -> V_161 = F_58 ;
V_45 -> V_162 = F_65 ;
V_45 -> V_163 = false ;
V_45 -> V_164 = V_165 ;
V_149 = & V_2 -> V_149 ;
V_149 -> V_166 = F_30 ;
V_149 -> V_167 = F_40 ;
V_149 -> V_168 = F_41 ;
V_149 -> V_169 = F_43 ;
V_149 -> V_170 = F_42 ;
V_149 -> V_171 = F_45 ;
V_149 -> V_172 = F_46 ;
V_149 -> V_103 = V_173 ;
V_149 -> V_143 = F_90 ( V_145 , L_37 ,
V_53 -> V_142 ,
V_45 -> V_46 ,
V_45 -> V_46 + V_45 -> V_133 - 1 ) ;
F_23 ( V_2 -> V_79 ) ;
V_2 -> V_28 = F_91 ( V_2 -> V_8 + V_30 ) ;
F_25 ( V_2 -> V_79 ) ;
V_45 -> V_148 = V_136 ;
V_152 = F_92 ( V_45 ) ;
if ( V_152 )
return V_152 ;
F_93 ( V_53 , V_2 ) ;
V_152 = F_94 ( V_45 ,
V_149 ,
0 ,
V_174 ,
V_111 ) ;
if ( V_152 ) {
F_20 ( & V_53 -> V_53 , L_38 ) ;
F_95 ( & V_2 -> V_45 ) ;
return - V_144 ;
}
F_96 ( V_45 ,
V_149 ,
V_2 -> V_153 ,
F_54 ) ;
if ( V_2 -> V_154 > 0 )
F_96 ( V_45 ,
V_149 ,
V_2 -> V_154 ,
F_55 ) ;
F_97 ( & V_53 -> V_53 , L_39 , V_2 -> V_8 ) ;
return 0 ;
}
static int F_98 ( struct V_80 * V_81 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
return V_58 -> V_67 -> V_175 ;
}
static const char * F_99 ( struct V_80 * V_81 ,
unsigned V_176 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
return V_58 -> V_67 -> V_177 [ V_176 ] . V_143 ;
}
static int F_100 ( struct V_80 * V_81 , unsigned V_176 ,
const unsigned * * V_178 ,
unsigned * V_179 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
* V_178 = V_58 -> V_67 -> V_177 [ V_176 ] . V_178 ;
* V_179 = V_58 -> V_67 -> V_177 [ V_176 ] . V_180 ;
return 0 ;
}
static struct V_1 * F_101 ( unsigned V_70 )
{
int V_60 ;
struct V_1 * V_181 ;
for( V_60 = 0 ; V_60 < V_182 ; V_60 ++ ) {
V_181 = V_77 [ V_60 ] ;
if ( ! V_181 )
continue;
if ( V_70 >= V_181 -> V_45 . V_46 &&
V_70 < V_181 -> V_45 . V_46 + V_181 -> V_45 . V_133 )
return V_181 ;
}
return NULL ;
}
static struct V_85 * F_102 ( unsigned V_70 )
{
struct V_1 * V_181 = F_101 ( V_70 ) ;
if ( V_181 )
return & V_181 -> V_45 ;
return NULL ;
}
static void F_103 ( struct V_80 * V_81 , struct V_121 * V_122 ,
unsigned V_3 )
{
struct V_85 * V_45 = F_102 ( V_3 ) ;
if ( ! V_45 ) {
F_62 ( V_122 , L_40 ) ;
return;
}
F_60 ( V_122 , V_81 , V_45 , V_3 - V_45 -> V_46 , V_3 ) ;
}
static int F_104 ( struct V_183 * * V_184 , unsigned * V_185 ,
unsigned * V_186 , const char * V_187 ,
const char * V_188 )
{
if ( * V_186 == * V_185 )
return - V_189 ;
( * V_184 ) [ * V_186 ] . type = V_190 ;
( * V_184 ) [ * V_186 ] . V_191 . V_192 . V_187 = V_187 ;
( * V_184 ) [ * V_186 ] . V_191 . V_192 . V_188 = V_188 ;
( * V_186 ) ++ ;
return 0 ;
}
static int F_105 ( struct V_183 * * V_184 ,
unsigned * V_185 ,
unsigned * V_186 , const char * V_187 ,
unsigned long * V_193 , unsigned V_194 )
{
unsigned long * V_195 ;
if ( * V_186 == * V_185 )
return - V_189 ;
V_195 = F_106 ( V_193 , V_194 * sizeof( * V_195 ) ,
V_145 ) ;
if ( ! V_195 )
return - V_146 ;
( * V_184 ) [ * V_186 ] . type = V_196 ;
( * V_184 ) [ * V_186 ] . V_191 . V_193 . V_197 = V_187 ;
( * V_184 ) [ * V_186 ] . V_191 . V_193 . V_193 = V_195 ;
( * V_184 ) [ * V_186 ] . V_191 . V_193 . V_194 = V_194 ;
( * V_186 ) ++ ;
return 0 ;
}
static int F_107 ( int V_198 , int V_32 , unsigned long * V_199 )
{
int V_152 = 0 ;
if ( V_200 [ V_198 ] . V_201 == NULL )
* V_199 = V_200 [ V_198 ] . V_199 ;
else {
if ( V_32 < V_200 [ V_198 ] . V_202 ) {
* V_199 = V_200 [ V_198 ] . V_199 |
V_200 [ V_198 ] . V_201 [ V_32 ] ;
}
}
return V_152 ;
}
static const char * F_108 ( struct V_80 * V_81 , const char * V_203 )
{
int V_60 , V_204 ;
struct V_57 * V_58 = F_27 ( V_81 ) ;
if ( sscanf ( ( char * ) V_203 , L_41 , & V_204 ) == 1 )
for ( V_60 = 0 ; V_60 < V_58 -> V_67 -> V_180 ; V_60 ++ )
if ( V_58 -> V_67 -> V_178 [ V_60 ] . V_205 == V_204 )
return V_58 -> V_67 -> V_178 [ V_60 ] . V_143 ;
return NULL ;
}
static bool F_109 ( struct V_135 * V_136 ,
unsigned long * V_193 )
{
bool V_206 = 0 ;
unsigned long V_207 = 0 ;
int V_60 , V_32 , V_152 ;
for ( V_60 = 0 ; V_60 < F_84 ( V_200 ) ; V_60 ++ ) {
V_152 = F_75 ( V_136 ,
V_200 [ V_60 ] . V_208 , & V_32 ) ;
if ( V_152 != - V_84 ) {
if ( F_107 ( V_60 , V_32 , & V_207 ) == 0 ) {
* V_193 |= V_207 ;
V_206 = 1 ;
}
}
}
return V_206 ;
}
static int F_110 ( struct V_80 * V_81 ,
struct V_135 * V_136 ,
struct V_183 * * V_184 ,
unsigned * V_185 ,
unsigned * V_186 )
{
int V_152 ;
const char * V_188 = NULL ;
unsigned long V_193 = 0 ;
bool V_206 = 0 ;
struct V_208 * V_209 ;
struct V_135 * V_210 ;
V_152 = F_111 ( V_136 , L_42 , & V_188 ) ;
if ( V_152 >= 0 ) {
const char * V_187 ;
V_152 = F_112 ( V_136 , L_43 ) ;
if ( V_152 < 0 )
goto exit;
V_152 = F_113 ( V_81 , V_184 ,
V_185 ,
V_186 , V_152 ) ;
if ( V_152 < 0 )
goto exit;
F_114 (np, L_43 , prop, group) {
V_152 = F_104 ( V_184 , V_185 , V_186 ,
V_187 , V_188 ) ;
if ( V_152 < 0 )
goto exit;
}
}
V_206 = F_109 ( V_136 , & V_193 ) ;
V_210 = F_115 ( V_136 , L_44 , 0 ) ;
if ( V_210 )
V_206 |= F_109 ( V_210 , & V_193 ) ;
if ( V_206 ) {
const char * V_211 ;
const char * V_70 ;
V_152 = F_112 ( V_136 , L_45 ) ;
if ( V_152 < 0 )
goto exit;
V_152 = F_113 ( V_81 , V_184 ,
V_185 ,
V_186 , V_152 ) ;
if ( V_152 < 0 )
goto exit;
F_114 (np, L_45 , prop, pin) {
V_211 = F_108 ( V_81 , V_70 ) ;
V_152 = F_105 ( V_184 , V_185 ,
V_186 ,
V_211 , & V_193 , 1 ) ;
if ( V_152 < 0 )
goto exit;
}
}
exit:
return V_152 ;
}
static int F_116 ( struct V_80 * V_81 ,
struct V_135 * V_210 ,
struct V_183 * * V_184 , unsigned * V_186 )
{
unsigned V_185 ;
struct V_135 * V_136 ;
int V_152 ;
V_185 = 0 ;
* V_184 = NULL ;
* V_186 = 0 ;
F_117 (np_config, np) {
V_152 = F_110 ( V_81 , V_136 , V_184 ,
& V_185 , V_186 ) ;
if ( V_152 < 0 ) {
F_118 ( V_81 , * V_184 , * V_186 ) ;
return V_152 ;
}
}
return 0 ;
}
static int F_119 ( struct V_80 * V_81 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
return V_58 -> V_67 -> V_212 ;
}
static const char * F_120 ( struct V_80 * V_81 ,
unsigned V_188 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
return V_58 -> V_67 -> V_213 [ V_188 ] . V_143 ;
}
static int F_121 ( struct V_80 * V_81 ,
unsigned V_188 ,
const char * const * * V_177 ,
unsigned * const V_214 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
* V_177 = V_58 -> V_67 -> V_213 [ V_188 ] . V_177 ;
* V_214 = V_58 -> V_67 -> V_213 [ V_188 ] . V_175 ;
return 0 ;
}
static int F_122 ( struct V_80 * V_81 , unsigned V_188 ,
unsigned V_187 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
const struct V_215 * V_216 ;
static unsigned int V_15 [ V_76 ] ;
unsigned long V_103 = 0 ;
bool V_34 ;
int V_152 = - V_84 ;
int V_60 ;
V_216 = & V_58 -> V_67 -> V_177 [ V_187 ] ;
if ( V_216 -> V_217 < 0 )
return - V_84 ;
F_17 ( V_58 -> V_53 , L_46 , V_216 -> V_143 , V_216 -> V_180 ) ;
V_34 = ( ( V_216 -> V_217 & V_82 ) == V_82 ) ;
if ( V_34 ) {
F_36 ( & V_104 , V_103 ) ;
memset ( V_15 , 0xff , sizeof( V_15 ) ) ;
for ( V_60 = 0 ; V_60 < V_216 -> V_180 ; V_60 ++ )
V_15 [ V_216 -> V_178 [ V_60 ] / V_83 ] &= ~ F_7 ( V_216 -> V_178 [ V_60 ] ) ;
F_22 ( V_15 ) ;
}
for ( V_60 = 0 ; V_60 < V_216 -> V_180 ; V_60 ++ ) {
struct V_1 * V_2 ;
unsigned V_5 ;
V_2 = F_101 ( V_216 -> V_178 [ V_60 ] ) ;
if ( ! V_2 ) {
F_20 ( V_58 -> V_53 ,
L_47 ,
V_216 -> V_178 [ V_60 ] , V_216 -> V_143 , V_60 ) ;
goto V_218;
}
F_17 ( V_58 -> V_53 , L_48 , V_216 -> V_178 [ V_60 ] , V_216 -> V_217 ) ;
F_23 ( V_2 -> V_79 ) ;
V_5 = V_216 -> V_178 [ V_60 ] % V_83 ;
F_13 ( V_2 , V_5 ) ;
F_12 ( V_2 , V_5 ,
( V_216 -> V_217 & V_82 ) , V_34 ) ;
F_25 ( V_2 -> V_79 ) ;
if ( ( V_216 -> V_217 & V_82 ) == V_82 )
F_19 ( V_58 , V_216 -> V_178 [ V_60 ] ,
V_216 -> V_217 >> V_219 ) ;
}
V_152 = 0 ;
V_218:
if ( V_34 ) {
F_24 ( V_15 ) ;
F_39 ( & V_104 , V_103 ) ;
}
return V_152 ;
}
static int F_123 ( struct V_80 * V_81 ,
struct V_220 * V_221 ,
unsigned V_3 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
struct V_1 * V_2 ;
struct V_85 * V_45 ;
unsigned V_5 ;
if ( ! V_221 ) {
F_20 ( V_58 -> V_53 , L_49 ) ;
return - V_84 ;
}
if ( ! V_221 -> V_222 ) {
F_20 ( V_58 -> V_53 , L_50 ) ;
return - V_84 ;
}
V_45 = V_221 -> V_222 ;
V_2 = F_32 ( V_45 , struct V_1 , V_45 ) ;
F_17 ( V_58 -> V_53 , L_51 , V_3 ) ;
F_23 ( V_2 -> V_79 ) ;
V_5 = V_3 % V_83 ;
F_1 ( V_2 , V_5 , V_127 ) ;
F_25 ( V_2 -> V_79 ) ;
return 0 ;
}
static void F_124 ( struct V_80 * V_81 ,
struct V_220 * V_221 ,
unsigned V_3 )
{
struct V_57 * V_58 = F_27 ( V_81 ) ;
F_17 ( V_58 -> V_53 , L_52 , V_3 ) ;
}
static int F_125 ( struct V_80 * V_81 , unsigned V_70 ,
unsigned long * V_199 )
{
return - V_84 ;
}
static int F_126 ( struct V_80 * V_81 , unsigned V_70 ,
unsigned long * V_193 , unsigned V_194 )
{
static const char * V_223 [] = {
[ V_22 ] = L_53 ,
[ V_24 ] = L_54 ,
[ V_26 ] = L_55 ,
[ 3 ] = L_56
} ;
static const char * V_224 [] = {
[ V_225 ] = L_57 ,
[ V_17 ] = L_58 ,
} ;
struct V_57 * V_58 = F_27 ( V_81 ) ;
struct V_1 * V_2 ;
unsigned V_5 ;
T_6 V_207 ;
int V_19 , V_15 , V_226 , V_32 , V_60 ;
bool V_28 , V_227 , V_228 ;
V_2 = F_101 ( V_70 ) ;
if ( ! V_2 ) {
F_20 ( V_58 -> V_53 ,
L_59 , V_70 ) ;
return - V_84 ;
}
for ( V_60 = 0 ; V_60 < V_194 ; V_60 ++ ) {
V_207 = ( T_6 ) V_193 [ V_60 ] ;
V_19 = F_127 ( V_207 ) ;
V_15 = F_128 ( V_207 ) ;
V_226 = F_129 ( V_207 ) ;
V_32 = F_130 ( V_207 ) ;
V_28 = F_131 ( V_207 ) ;
V_227 = F_132 ( V_207 ) ;
V_228 = F_133 ( V_207 ) ;
if ( V_228 ) {
int V_229 = F_134 ( V_207 ) ;
int V_230 = F_135 ( V_207 ) ;
int V_231 = F_136 ( V_207 ) ;
V_227 = true ;
if ( V_229 )
V_19 = V_229 - 1 ;
if ( V_230 )
V_226 = V_230 - 1 ;
if ( V_231 )
V_32 = V_231 - 1 ;
F_17 ( V_2 -> V_45 . V_53 ,
L_60 ,
V_70 ,
V_229 ? V_223 [ V_19 ] : L_61 ,
V_230 ? ( V_226 ? L_62 : L_63 )
: L_61 ,
V_231 ? ( V_32 ? L_64 : L_65 ) : L_61 ) ;
}
F_17 ( V_2 -> V_45 . V_53 ,
L_66 ,
V_70 , V_207 , V_223 [ V_19 ] , V_224 [ V_15 ] ,
V_226 ? L_67 : L_63 ,
V_226 ? ( V_32 ? L_64 : L_65 ) : L_30 ,
V_28 ? L_68 : L_69 ) ;
F_23 ( V_2 -> V_79 ) ;
V_5 = V_70 % V_83 ;
if ( V_227 )
F_1 ( V_2 , V_5 , V_127 ) ;
if ( V_226 )
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
static int F_137 ( struct V_232 * V_53 )
{
struct V_57 * V_58 ;
V_58 = F_138 ( V_53 ) ;
if ( ! V_58 )
return - V_84 ;
return F_139 ( V_58 -> V_233 ) ;
}
static int F_140 ( struct V_232 * V_53 )
{
struct V_57 * V_58 ;
V_58 = F_138 ( V_53 ) ;
if ( ! V_58 )
return - V_84 ;
return F_141 ( V_58 -> V_233 ) ;
}
static int F_142 ( struct V_137 * V_138 )
{
const struct V_234 * V_235 ;
struct V_135 * V_136 = V_138 -> V_53 . V_148 ;
struct V_135 * V_236 ;
struct V_57 * V_58 ;
unsigned int V_237 = 0 ;
int V_60 ;
V_58 = F_76 ( & V_138 -> V_53 , sizeof( * V_58 ) , V_145 ) ;
if ( ! V_58 )
return - V_146 ;
V_235 = F_143 ( V_238 , & V_138 -> V_53 ) ;
if ( ! V_235 )
return - V_144 ;
V_237 = ( unsigned int ) V_235 -> V_191 ;
if ( V_237 == V_239 )
F_144 ( & V_58 -> V_67 ) ;
if ( V_237 == V_240 )
F_145 ( & V_58 -> V_67 ) ;
if ( V_237 == V_241 )
F_146 ( & V_58 -> V_67 ) ;
for ( V_60 = 0 ; V_60 < V_182 ; V_60 ++ ) {
struct V_135 * V_242 ;
struct V_1 * V_2 ;
V_242 = F_115 ( V_136 , L_70 , V_60 ) ;
if ( V_242 ) {
F_97 ( & V_138 -> V_53 ,
L_71 ,
V_60 , V_242 -> V_143 ) ;
V_2 = F_71 ( V_242 , V_138 ) ;
if ( F_80 ( V_2 ) )
F_20 ( & V_138 -> V_53 ,
L_72
L_73 ) ;
F_147 ( V_242 ) ;
}
}
V_236 = F_115 ( V_136 , L_74 , 0 ) ;
if ( V_236 )
V_58 -> V_65 = F_148 ( V_236 , 0 ) ;
if ( ! V_58 -> V_65 ) {
if ( V_237 == V_239 ) {
F_97 ( & V_138 -> V_53 ,
L_75
L_76 ) ;
} else {
F_20 ( & V_138 -> V_53 , L_77 ) ;
return - V_84 ;
}
}
V_243 . V_178 = V_58 -> V_67 -> V_178 ;
V_243 . V_180 = V_58 -> V_67 -> V_180 ;
V_58 -> V_53 = & V_138 -> V_53 ;
V_58 -> V_233 = F_149 ( & V_243 , & V_138 -> V_53 , V_58 ) ;
if ( F_80 ( V_58 -> V_233 ) ) {
F_20 ( & V_138 -> V_53 , L_78 ) ;
return F_86 ( V_58 -> V_233 ) ;
}
F_93 ( V_138 , V_58 ) ;
F_97 ( & V_138 -> V_53 , L_79 ) ;
return 0 ;
}
static int T_7 F_150 ( void )
{
return F_151 ( & V_244 ) ;
}
static int T_7 F_152 ( void )
{
return F_151 ( & V_245 ) ;
}

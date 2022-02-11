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
F_20 ( V_58 -> V_67 , L_2 ,
V_59 ) ;
return;
}
for ( V_60 = 0 ; V_60 < V_58 -> V_68 -> V_69 ; V_60 ++ ) {
if ( V_58 -> V_68 -> V_70 [ V_60 ] . V_71 == V_3 )
break;
}
if ( V_60 == V_58 -> V_68 -> V_69 ) {
F_17 ( V_58 -> V_67 , L_3 ,
V_3 ) ;
return;
}
V_63 = V_58 -> V_68 -> V_70 + V_60 ;
V_64 = V_58 -> V_68 -> V_72 ;
if ( ! V_59 ) {
for ( V_60 = 0 ; V_60 < V_66 ; V_60 ++ ) {
if ( V_63 -> V_73 [ V_60 ] . V_74 == true ) {
V_54 = V_64 [ V_63 -> V_73 [ V_60 ] . V_75 ] ;
V_5 = V_63 -> V_73 [ V_60 ] . V_76 ;
if ( F_2 ( V_58 -> V_65 + V_54 ) & F_7 ( V_5 ) ) {
F_18 ( V_58 -> V_65 + V_54 , F_7 ( V_5 ) , 0 ) ;
F_17 ( V_58 -> V_67 ,
L_4 ,
V_3 , V_60 + 1 ) ;
}
}
}
return;
}
V_61 = V_59 - 1 ;
if ( V_63 -> V_73 [ V_61 ] . V_74 == false ) {
F_21 ( V_58 -> V_67 ,
L_5 ,
V_3 , V_59 ) ;
return;
}
for ( V_60 = 0 ; V_60 < V_66 ; V_60 ++ ) {
if ( V_60 == V_61 )
continue;
if ( V_63 -> V_73 [ V_60 ] . V_74 == true ) {
V_54 = V_64 [ V_63 -> V_73 [ V_60 ] . V_75 ] ;
V_5 = V_63 -> V_73 [ V_60 ] . V_76 ;
if ( F_2 ( V_58 -> V_65 + V_54 ) & F_7 ( V_5 ) ) {
F_18 ( V_58 -> V_65 + V_54 , F_7 ( V_5 ) , 0 ) ;
F_17 ( V_58 -> V_67 ,
L_4 ,
V_3 , V_60 + 1 ) ;
}
}
}
V_54 = V_64 [ V_63 -> V_73 [ V_61 ] . V_75 ] ;
V_5 = V_63 -> V_73 [ V_61 ] . V_76 ;
F_17 ( V_58 -> V_67 , L_6 ,
V_3 , V_61 + 1 ) ;
F_18 ( V_58 -> V_65 + V_54 , F_7 ( V_5 ) , F_7 ( V_5 ) ) ;
}
static void F_22 ( unsigned int * V_15 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_77 ; V_60 ++ ) {
struct V_1 * V_45 = V_78 [ V_60 ] ;
unsigned int V_79 = V_15 [ V_60 ] ;
if ( ! V_45 )
break;
F_23 ( V_45 -> V_80 ) ;
V_15 [ V_60 ] = F_2 ( V_45 -> V_8 + V_16 ) ;
F_3 ( V_79 , V_45 -> V_8 + V_16 ) ;
}
}
static void F_24 ( unsigned int * V_15 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_77 ; V_60 ++ ) {
struct V_1 * V_45 = V_78 [ V_60 ] ;
if ( ! V_45 )
break;
F_3 ( V_15 [ V_60 ] , V_45 -> V_8 + V_16 ) ;
F_25 ( V_45 -> V_80 ) ;
}
}
static int T_5 F_26 ( struct V_81 * V_82 , int V_44 )
{
int V_60 ;
T_3 V_54 ;
T_4 V_5 ;
struct V_57 * V_58 = F_27 ( V_82 ) ;
const struct V_62 * V_63 ;
const T_3 * V_64 ;
if ( ! V_58 -> V_65 )
return V_83 ;
for ( V_60 = 0 ; V_60 < V_58 -> V_68 -> V_69 ; V_60 ++ ) {
if ( V_58 -> V_68 -> V_70 [ V_60 ] . V_71 == V_44 )
break;
}
if ( V_60 == V_58 -> V_68 -> V_69 )
return V_83 ;
V_63 = V_58 -> V_68 -> V_70 + V_60 ;
V_64 = V_58 -> V_68 -> V_72 ;
for ( V_60 = 0 ; V_60 < V_66 ; V_60 ++ ) {
if ( V_63 -> V_73 [ V_60 ] . V_74 == true ) {
V_54 = V_64 [ V_63 -> V_73 [ V_60 ] . V_75 ] ;
V_5 = V_63 -> V_73 [ V_60 ] . V_76 ;
if ( F_2 ( V_58 -> V_65 + V_54 ) & F_7 ( V_5 ) )
return V_83 + V_60 + 1 ;
}
}
return V_83 ;
}
int F_28 ( int V_44 )
{
struct V_1 * V_2 ;
T_1 V_6 , V_7 , V_5 ;
V_2 = V_78 [ V_44 / V_84 ] ;
if ( ! V_2 )
return - V_85 ;
V_5 = 1 << ( V_44 % V_84 ) ;
F_23 ( V_2 -> V_80 ) ;
V_6 = F_2 ( V_2 -> V_8 + V_9 ) & V_5 ;
V_7 = F_2 ( V_2 -> V_8 + V_10 ) & V_5 ;
F_25 ( V_2 -> V_80 ) ;
return ( V_6 ? V_11 : 0 ) | ( V_7 ? V_12 : 0 ) ;
}
static inline int F_29 ( int V_44 )
{
return 1 << ( V_44 % V_84 ) ;
}
static void F_30 ( struct V_49 * V_50 )
{
struct V_86 * V_45 = F_31 ( V_50 ) ;
struct V_1 * V_2 = F_32 ( V_45 ) ;
F_23 ( V_2 -> V_80 ) ;
F_3 ( F_29 ( V_50 -> V_87 ) , V_2 -> V_8 + V_88 ) ;
F_25 ( V_2 -> V_80 ) ;
}
static void F_33 ( struct V_1 * V_2 ,
int V_44 , enum V_89 V_90 ,
bool V_91 )
{
T_1 V_92 = F_29 ( V_44 ) ;
T_1 * V_93 ;
T_1 * V_94 ;
T_1 V_95 ;
T_1 V_96 ;
if ( V_90 == V_97 ) {
V_95 = V_51 ;
V_96 = V_52 ;
V_93 = & V_2 -> V_43 ;
V_94 = & V_2 -> V_41 ;
} else {
V_95 = V_38 ;
V_96 = V_39 ;
V_93 = & V_2 -> V_35 ;
V_94 = & V_2 -> V_36 ;
}
if ( V_2 -> V_98 & V_92 ) {
if ( V_91 )
* V_93 |= V_92 ;
else
* V_93 &= ~ V_92 ;
F_3 ( * V_93 , V_2 -> V_8 + V_95 ) ;
}
if ( V_2 -> V_99 & V_92 ) {
if ( V_91 )
* V_94 |= V_92 ;
else
* V_94 &= ~ V_92 ;
F_3 ( * V_94 , V_2 -> V_8 + V_96 ) ;
}
}
static void F_34 ( struct V_1 * V_2 ,
int V_44 , bool V_100 )
{
if ( V_2 -> V_101 && V_100 ) {
F_4 ( V_2 , V_44 % V_84 ,
V_102 ) ;
}
F_33 ( V_2 , V_44 , V_103 , V_100 ) ;
}
static int F_35 ( struct V_49 * V_50 , bool V_91 )
{
struct V_1 * V_2 ;
unsigned long V_104 ;
T_1 V_92 ;
V_2 = F_31 ( V_50 ) ;
V_92 = F_29 ( V_50 -> V_87 ) ;
if ( ! V_2 )
return - V_85 ;
F_23 ( V_2 -> V_80 ) ;
F_36 ( & V_105 , V_104 ) ;
F_37 ( & V_2 -> V_106 ) ;
F_33 ( V_2 , V_50 -> V_87 , V_97 , V_91 ) ;
if ( ! ( V_2 -> V_107 & V_92 ) )
F_34 ( V_2 , V_50 -> V_87 , V_91 ) ;
F_38 ( & V_2 -> V_106 ) ;
F_39 ( & V_105 , V_104 ) ;
F_25 ( V_2 -> V_80 ) ;
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
static int F_42 ( struct V_49 * V_50 , unsigned int V_100 )
{
struct V_1 * V_2 ;
unsigned long V_104 ;
T_1 V_92 ;
V_2 = F_31 ( V_50 ) ;
if ( ! V_2 )
return - V_85 ;
V_92 = F_29 ( V_50 -> V_87 ) ;
F_23 ( V_2 -> V_80 ) ;
F_36 ( & V_105 , V_104 ) ;
F_37 ( & V_2 -> V_106 ) ;
if ( F_16 ( V_50 ) )
F_34 ( V_2 , V_50 -> V_87 , V_100 ) ;
if ( V_100 )
V_2 -> V_107 |= V_92 ;
else
V_2 -> V_107 &= ~ V_92 ;
F_38 ( & V_2 -> V_106 ) ;
F_39 ( & V_105 , V_104 ) ;
F_25 ( V_2 -> V_80 ) ;
return 0 ;
}
static int F_43 ( struct V_49 * V_50 , unsigned int type )
{
bool V_29 = ! F_16 ( V_50 ) ;
bool V_108 = F_44 ( V_50 ) ;
struct V_1 * V_2 ;
unsigned long V_104 ;
T_1 V_92 ;
V_2 = F_31 ( V_50 ) ;
V_92 = F_29 ( V_50 -> V_87 ) ;
if ( ! V_2 )
return - V_85 ;
if ( type & V_109 )
return - V_85 ;
if ( type & V_110 )
return - V_85 ;
F_23 ( V_2 -> V_80 ) ;
F_36 ( & V_2 -> V_106 , V_104 ) ;
if ( V_29 )
F_33 ( V_2 , V_50 -> V_87 , V_97 , false ) ;
if ( V_29 || V_108 )
F_33 ( V_2 , V_50 -> V_87 , V_103 , false ) ;
V_2 -> V_98 &= ~ V_92 ;
if ( type & V_111 )
V_2 -> V_98 |= V_92 ;
V_2 -> V_99 &= ~ V_92 ;
if ( type & V_112 )
V_2 -> V_99 |= V_92 ;
if ( V_29 )
F_33 ( V_2 , V_50 -> V_87 , V_97 , true ) ;
if ( V_29 || V_108 )
F_33 ( V_2 , V_50 -> V_87 , V_103 , true ) ;
F_39 ( & V_2 -> V_106 , V_104 ) ;
F_25 ( V_2 -> V_80 ) ;
return 0 ;
}
static unsigned int F_45 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_31 ( V_50 ) ;
F_23 ( V_2 -> V_80 ) ;
F_41 ( V_50 ) ;
return 0 ;
}
static void F_46 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_31 ( V_50 ) ;
F_40 ( V_50 ) ;
F_25 ( V_2 -> V_80 ) ;
}
static void F_47 ( struct V_113 * V_114 , T_1 V_115 )
{
struct V_116 * V_117 = F_48 ( V_114 ) ;
struct V_86 * V_45 = F_49 ( V_114 ) ;
F_50 ( V_117 , V_114 ) ;
while ( V_115 ) {
int V_5 = F_51 ( V_115 ) ;
F_52 ( F_14 ( V_45 -> V_48 , V_5 ) ) ;
V_115 &= ~ F_7 ( V_5 ) ;
}
F_53 ( V_117 , V_114 ) ;
}
static void F_54 ( struct V_113 * V_114 )
{
struct V_86 * V_45 = F_49 ( V_114 ) ;
struct V_1 * V_2 = F_32 ( V_45 ) ;
T_1 V_115 ;
F_23 ( V_2 -> V_80 ) ;
V_115 = F_2 ( V_2 -> V_8 + V_118 ) ;
F_25 ( V_2 -> V_80 ) ;
F_47 ( V_114 , V_115 ) ;
}
static void F_55 ( struct V_113 * V_114 )
{
struct V_86 * V_45 = F_49 ( V_114 ) ;
struct V_1 * V_2 = F_32 ( V_45 ) ;
T_1 V_115 = V_2 -> V_119 ( V_2 -> V_120 ) ;
F_47 ( V_114 , V_115 ) ;
}
static int F_56 ( struct V_86 * V_45 , unsigned V_3 )
{
struct V_1 * V_2 = F_32 ( V_45 ) ;
F_23 ( V_2 -> V_80 ) ;
F_3 ( 1 << V_3 , V_2 -> V_8 + V_31 ) ;
F_25 ( V_2 -> V_80 ) ;
return 0 ;
}
static int F_57 ( struct V_86 * V_45 , unsigned V_3 )
{
struct V_1 * V_2 = F_32 ( V_45 ) ;
T_1 V_5 = 1 << V_3 ;
int V_56 ;
F_23 ( V_2 -> V_80 ) ;
V_56 = ( F_2 ( V_2 -> V_8 + V_121 ) & V_5 ) != 0 ;
F_25 ( V_2 -> V_80 ) ;
return V_56 ;
}
static void F_58 ( struct V_86 * V_45 , unsigned V_3 ,
int V_32 )
{
struct V_1 * V_2 = F_32 ( V_45 ) ;
F_23 ( V_2 -> V_80 ) ;
F_10 ( V_2 , V_3 , V_32 ) ;
F_25 ( V_2 -> V_80 ) ;
}
static int F_59 ( struct V_86 * V_45 , unsigned V_3 ,
int V_32 )
{
struct V_1 * V_2 = F_32 ( V_45 ) ;
F_23 ( V_2 -> V_80 ) ;
F_11 ( V_2 , V_3 , V_32 ) ;
F_25 ( V_2 -> V_80 ) ;
return 0 ;
}
static void F_60 ( struct V_122 * V_123 ,
struct V_81 * V_82 , struct V_86 * V_45 ,
unsigned V_3 , unsigned V_44 )
{
const char * V_124 = F_61 ( V_45 , V_3 ) ;
struct V_1 * V_2 = F_32 ( V_45 ) ;
int V_14 ;
bool V_125 ;
bool V_126 ;
bool V_19 ;
T_1 V_5 = 1 << V_3 ;
const char * V_127 [] = {
[ V_128 ] = L_7 ,
[ V_11 ] = L_8 ,
[ V_12 ] = L_9 ,
[ V_83 ] = L_10 ,
[ V_83 + 1 ] = L_11 ,
[ V_83 + 2 ] = L_12 ,
[ V_83 + 3 ] = L_13 ,
[ V_83 + 4 ] = L_14 ,
} ;
const char * V_129 [] = {
L_15 ,
L_16 ,
L_17 ,
} ;
F_23 ( V_2 -> V_80 ) ;
V_125 = ! ! ( F_2 ( V_2 -> V_8 + V_130 ) & V_5 ) ;
V_19 = ! ( F_2 ( V_2 -> V_8 + V_21 ) & V_5 ) ;
V_126 = ! ! ( F_2 ( V_2 -> V_8 + V_121 ) & V_5 ) ;
V_14 = F_28 ( V_44 ) ;
if ( ( V_14 == V_83 ) && V_82 )
V_14 = F_26 ( V_82 , V_44 ) ;
if ( V_125 ) {
F_62 ( V_123 , L_18 ,
V_44 ,
V_124 ? : L_19 ,
V_126 ? L_20 : L_21 ,
( V_14 < 0 ) ? L_22 : V_127 [ V_14 ] ) ;
} else {
int V_47 = F_63 ( V_44 ) ;
struct V_113 * V_114 = F_64 ( V_47 ) ;
int V_131 = 0 ;
int V_32 ;
if ( V_19 )
V_131 = V_126 ? 1 : 2 ;
F_62 ( V_123 , L_23 ,
V_44 ,
V_124 ? : L_19 ,
V_129 [ V_131 ] ,
( V_14 < 0 ) ? L_22 : V_127 [ V_14 ] ) ;
V_32 = F_57 ( V_45 , V_3 ) ;
F_62 ( V_123 , L_24 , V_32 ) ;
if ( V_47 > 0 && V_114 && V_114 -> V_132 ) {
char * V_133 ;
T_1 V_92 = F_29 ( V_44 ) ;
if ( V_2 -> V_98 & V_92 )
V_133 = L_25 ;
else if ( V_2 -> V_99 & V_92 )
V_133 = L_26 ;
else
V_133 = L_27 ;
F_62 ( V_123 , L_28 ,
V_47 , V_133 ,
F_44 ( & V_114 -> V_49 )
? L_29 : L_30 ) ;
}
}
F_25 ( V_2 -> V_80 ) ;
}
static void F_65 ( struct V_122 * V_123 , struct V_86 * V_45 )
{
unsigned V_60 ;
unsigned V_44 = V_45 -> V_46 ;
for ( V_60 = 0 ; V_60 < V_45 -> V_134 ; V_60 ++ , V_44 ++ ) {
F_60 ( V_123 , NULL , V_45 , V_60 , V_44 ) ;
F_62 ( V_123 , L_31 ) ;
}
}
static inline void F_60 ( struct V_122 * V_123 ,
struct V_81 * V_82 ,
struct V_86 * V_45 ,
unsigned V_3 , unsigned V_44 )
{
}
void F_66 ( void )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_77 ; V_60 ++ ) {
struct V_1 * V_45 = V_78 [ V_60 ] ;
if ( ! V_45 )
continue;
F_23 ( V_45 -> V_80 ) ;
}
}
void F_67 ( void )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_77 ; V_60 ++ ) {
struct V_1 * V_45 = V_78 [ V_60 ] ;
if ( ! V_45 )
continue;
F_25 ( V_45 -> V_80 ) ;
}
}
void F_68 ( void )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_77 ; V_60 ++ ) {
struct V_1 * V_45 = V_78 [ V_60 ] ;
if ( ! V_45 )
break;
F_23 ( V_45 -> V_80 ) ;
F_3 ( V_45 -> V_35 & V_45 -> V_107 ,
V_45 -> V_8 + V_38 ) ;
F_3 ( V_45 -> V_36 & V_45 -> V_107 ,
V_45 -> V_8 + V_39 ) ;
F_25 ( V_45 -> V_80 ) ;
}
}
void F_69 ( void )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_77 ; V_60 ++ ) {
struct V_1 * V_45 = V_78 [ V_60 ] ;
if ( ! V_45 )
break;
F_23 ( V_45 -> V_80 ) ;
F_3 ( V_45 -> V_35 , V_45 -> V_8 + V_38 ) ;
F_3 ( V_45 -> V_36 , V_45 -> V_8 + V_39 ) ;
F_25 ( V_45 -> V_80 ) ;
}
}
void F_70 ( int V_135 , T_1 * V_23 )
{
if ( V_135 < V_77 ) {
struct V_1 * V_45 = V_78 [ V_135 ] ;
if ( ! V_45 )
return;
* V_23 = V_45 -> V_23 ;
}
}
static struct V_1 * F_71 ( struct V_136 * V_137 ,
struct V_138 * V_139 )
{
struct V_1 * V_2 ;
struct V_138 * V_140 ;
struct V_86 * V_45 ;
struct V_141 * V_142 ;
struct V_80 * V_80 ;
void T_2 * V_46 ;
T_1 V_143 ;
V_140 = F_72 ( V_137 ) ;
if ( ! V_140 ) {
F_73 ( L_32 , V_137 -> V_144 ) ;
return F_74 ( - V_145 ) ;
}
if ( F_75 ( V_137 , L_33 , & V_143 ) ) {
F_20 ( & V_139 -> V_67 , L_34 ) ;
return F_74 ( - V_85 ) ;
}
V_2 = V_78 [ V_143 ] ;
if ( V_2 )
return V_2 ;
V_2 = F_76 ( & V_139 -> V_67 , sizeof( * V_2 ) , V_146 ) ;
if ( ! V_2 )
return F_74 ( - V_147 ) ;
V_2 -> V_120 = V_143 ;
V_45 = & V_2 -> V_45 ;
V_45 -> V_46 = V_143 * V_84 ;
V_45 -> V_134 = V_84 ;
V_45 -> V_124 = F_77 ( & V_140 -> V_67 ) ;
V_45 -> V_53 = & V_140 -> V_67 ;
V_142 = F_78 ( V_140 , V_148 , 0 ) ;
V_46 = F_79 ( & V_139 -> V_67 , V_142 ) ;
if ( F_80 ( V_46 ) )
return V_46 ;
V_2 -> V_8 = V_46 ;
V_80 = F_81 ( & V_140 -> V_67 , NULL ) ;
if ( F_80 ( V_80 ) )
return ( void * ) V_80 ;
F_82 ( V_80 ) ;
V_2 -> V_80 = V_80 ;
F_83 ( V_2 -> V_120 >= F_84 ( V_78 ) ) ;
V_78 [ V_143 ] = V_2 ;
return V_2 ;
}
static int F_85 ( struct V_138 * V_67 )
{
struct V_136 * V_137 = V_67 -> V_67 . V_149 ;
struct V_1 * V_2 ;
struct V_86 * V_45 ;
struct V_116 * V_150 ;
int V_151 ;
bool V_152 ;
int V_47 ;
int V_153 ;
V_2 = F_71 ( V_137 , V_67 ) ;
if ( F_80 ( V_2 ) ) {
F_20 ( & V_67 -> V_67 , L_35 ) ;
return F_86 ( V_2 ) ;
}
if ( F_87 ( V_137 , L_36 , NULL ) )
V_152 = true ;
else
V_152 = false ;
V_67 -> V_143 = V_2 -> V_120 ;
V_47 = F_88 ( V_67 , 0 ) ;
if ( V_47 < 0 )
return V_47 ;
V_151 = F_88 ( V_67 , 1 ) ;
V_2 -> V_154 = V_47 ;
V_2 -> V_155 = V_151 ;
V_2 -> V_101 = V_152 ;
F_89 ( & V_2 -> V_106 ) ;
V_45 = & V_2 -> V_45 ;
V_45 -> V_156 = V_157 ;
V_45 -> free = V_158 ;
V_45 -> V_159 = F_56 ;
V_45 -> V_160 = F_57 ;
V_45 -> V_161 = F_59 ;
V_45 -> V_162 = F_58 ;
V_45 -> V_163 = F_65 ;
V_45 -> V_164 = false ;
V_45 -> V_165 = V_166 ;
V_150 = & V_2 -> V_150 ;
V_150 -> V_167 = F_30 ;
V_150 -> V_168 = F_40 ;
V_150 -> V_169 = F_41 ;
V_150 -> V_170 = F_43 ;
V_150 -> V_171 = F_42 ;
V_150 -> V_172 = F_45 ;
V_150 -> V_173 = F_46 ;
V_150 -> V_104 = V_174 ;
V_150 -> V_144 = F_90 ( V_146 , L_37 ,
V_67 -> V_143 ,
V_45 -> V_46 ,
V_45 -> V_46 + V_45 -> V_134 - 1 ) ;
F_23 ( V_2 -> V_80 ) ;
V_2 -> V_28 = F_91 ( V_2 -> V_8 + V_30 ) ;
F_25 ( V_2 -> V_80 ) ;
V_45 -> V_149 = V_137 ;
V_153 = F_92 ( V_45 , V_2 ) ;
if ( V_153 )
return V_153 ;
F_93 ( V_67 , V_2 ) ;
V_153 = F_94 ( V_45 ,
V_150 ,
0 ,
V_175 ,
V_112 ) ;
if ( V_153 ) {
F_20 ( & V_67 -> V_67 , L_38 ) ;
F_95 ( & V_2 -> V_45 ) ;
return - V_145 ;
}
F_96 ( V_45 ,
V_150 ,
V_2 -> V_154 ,
F_54 ) ;
if ( V_2 -> V_155 > 0 )
F_96 ( V_45 ,
V_150 ,
V_2 -> V_155 ,
F_55 ) ;
F_97 ( & V_67 -> V_67 , L_39 , V_2 -> V_8 ) ;
return 0 ;
}
static int F_98 ( struct V_81 * V_82 )
{
struct V_57 * V_58 = F_27 ( V_82 ) ;
return V_58 -> V_68 -> V_176 ;
}
static const char * F_99 ( struct V_81 * V_82 ,
unsigned V_177 )
{
struct V_57 * V_58 = F_27 ( V_82 ) ;
return V_58 -> V_68 -> V_178 [ V_177 ] . V_144 ;
}
static int F_100 ( struct V_81 * V_82 , unsigned V_177 ,
const unsigned * * V_179 ,
unsigned * V_180 )
{
struct V_57 * V_58 = F_27 ( V_82 ) ;
* V_179 = V_58 -> V_68 -> V_178 [ V_177 ] . V_179 ;
* V_180 = V_58 -> V_68 -> V_178 [ V_177 ] . V_181 ;
return 0 ;
}
static struct V_1 * F_101 ( unsigned V_71 )
{
int V_60 ;
struct V_1 * V_182 ;
for( V_60 = 0 ; V_60 < V_183 ; V_60 ++ ) {
V_182 = V_78 [ V_60 ] ;
if ( ! V_182 )
continue;
if ( V_71 >= V_182 -> V_45 . V_46 &&
V_71 < V_182 -> V_45 . V_46 + V_182 -> V_45 . V_134 )
return V_182 ;
}
return NULL ;
}
static struct V_86 * F_102 ( unsigned V_71 )
{
struct V_1 * V_182 = F_101 ( V_71 ) ;
if ( V_182 )
return & V_182 -> V_45 ;
return NULL ;
}
static void F_103 ( struct V_81 * V_82 , struct V_122 * V_123 ,
unsigned V_3 )
{
struct V_86 * V_45 = F_102 ( V_3 ) ;
if ( ! V_45 ) {
F_62 ( V_123 , L_40 ) ;
return;
}
F_60 ( V_123 , V_82 , V_45 , V_3 - V_45 -> V_46 , V_3 ) ;
}
static int F_104 ( struct V_184 * * V_185 , unsigned * V_186 ,
unsigned * V_187 , const char * V_188 ,
const char * V_189 )
{
if ( * V_187 == * V_186 )
return - V_190 ;
( * V_185 ) [ * V_187 ] . type = V_191 ;
( * V_185 ) [ * V_187 ] . V_192 . V_193 . V_188 = V_188 ;
( * V_185 ) [ * V_187 ] . V_192 . V_193 . V_189 = V_189 ;
( * V_187 ) ++ ;
return 0 ;
}
static int F_105 ( struct V_184 * * V_185 ,
unsigned * V_186 ,
unsigned * V_187 , const char * V_188 ,
unsigned long * V_194 , unsigned V_195 )
{
unsigned long * V_196 ;
if ( * V_187 == * V_186 )
return - V_190 ;
V_196 = F_106 ( V_194 , V_195 * sizeof( * V_196 ) ,
V_146 ) ;
if ( ! V_196 )
return - V_147 ;
( * V_185 ) [ * V_187 ] . type = V_197 ;
( * V_185 ) [ * V_187 ] . V_192 . V_194 . V_198 = V_188 ;
( * V_185 ) [ * V_187 ] . V_192 . V_194 . V_194 = V_196 ;
( * V_185 ) [ * V_187 ] . V_192 . V_194 . V_195 = V_195 ;
( * V_187 ) ++ ;
return 0 ;
}
static int F_107 ( int V_199 , int V_32 , unsigned long * V_200 )
{
int V_153 = 0 ;
if ( V_201 [ V_199 ] . V_202 == NULL )
* V_200 = V_201 [ V_199 ] . V_200 ;
else {
if ( V_32 < V_201 [ V_199 ] . V_203 ) {
* V_200 = V_201 [ V_199 ] . V_200 |
V_201 [ V_199 ] . V_202 [ V_32 ] ;
}
}
return V_153 ;
}
static const char * F_108 ( struct V_81 * V_82 , const char * V_204 )
{
int V_60 , V_205 ;
struct V_57 * V_58 = F_27 ( V_82 ) ;
if ( sscanf ( ( char * ) V_204 , L_41 , & V_205 ) == 1 )
for ( V_60 = 0 ; V_60 < V_58 -> V_68 -> V_181 ; V_60 ++ )
if ( V_58 -> V_68 -> V_179 [ V_60 ] . V_206 == V_205 )
return V_58 -> V_68 -> V_179 [ V_60 ] . V_144 ;
return NULL ;
}
static bool F_109 ( struct V_136 * V_137 ,
unsigned long * V_194 )
{
bool V_207 = 0 ;
unsigned long V_208 = 0 ;
int V_60 , V_32 , V_153 ;
for ( V_60 = 0 ; V_60 < F_84 ( V_201 ) ; V_60 ++ ) {
V_153 = F_75 ( V_137 ,
V_201 [ V_60 ] . V_209 , & V_32 ) ;
if ( V_153 != - V_85 ) {
if ( F_107 ( V_60 , V_32 , & V_208 ) == 0 ) {
* V_194 |= V_208 ;
V_207 = 1 ;
}
}
}
return V_207 ;
}
static int F_110 ( struct V_81 * V_82 ,
struct V_136 * V_137 ,
struct V_184 * * V_185 ,
unsigned * V_186 ,
unsigned * V_187 )
{
int V_153 ;
const char * V_189 = NULL ;
unsigned long V_194 = 0 ;
bool V_207 = 0 ;
struct V_209 * V_210 ;
struct V_136 * V_211 ;
V_153 = F_111 ( V_137 , L_42 , & V_189 ) ;
if ( V_153 >= 0 ) {
const char * V_188 ;
V_153 = F_112 ( V_137 , L_43 ) ;
if ( V_153 < 0 )
goto exit;
V_153 = F_113 ( V_82 , V_185 ,
V_186 ,
V_187 , V_153 ) ;
if ( V_153 < 0 )
goto exit;
F_114 (np, L_43 , prop, group) {
V_153 = F_104 ( V_185 , V_186 , V_187 ,
V_188 , V_189 ) ;
if ( V_153 < 0 )
goto exit;
}
}
V_207 = F_109 ( V_137 , & V_194 ) ;
V_211 = F_115 ( V_137 , L_44 , 0 ) ;
if ( V_211 )
V_207 |= F_109 ( V_211 , & V_194 ) ;
if ( V_207 ) {
const char * V_212 ;
const char * V_71 ;
V_153 = F_112 ( V_137 , L_45 ) ;
if ( V_153 < 0 )
goto exit;
V_153 = F_113 ( V_82 , V_185 ,
V_186 ,
V_187 , V_153 ) ;
if ( V_153 < 0 )
goto exit;
F_114 (np, L_45 , prop, pin) {
V_212 = F_108 ( V_82 , V_71 ) ;
V_153 = F_105 ( V_185 , V_186 ,
V_187 ,
V_212 , & V_194 , 1 ) ;
if ( V_153 < 0 )
goto exit;
}
}
exit:
return V_153 ;
}
static int F_116 ( struct V_81 * V_82 ,
struct V_136 * V_211 ,
struct V_184 * * V_185 , unsigned * V_187 )
{
unsigned V_186 ;
struct V_136 * V_137 ;
int V_153 ;
V_186 = 0 ;
* V_185 = NULL ;
* V_187 = 0 ;
F_117 (np_config, np) {
V_153 = F_110 ( V_82 , V_137 , V_185 ,
& V_186 , V_187 ) ;
if ( V_153 < 0 ) {
F_118 ( V_82 , * V_185 , * V_187 ) ;
return V_153 ;
}
}
return 0 ;
}
static int F_119 ( struct V_81 * V_82 )
{
struct V_57 * V_58 = F_27 ( V_82 ) ;
return V_58 -> V_68 -> V_213 ;
}
static const char * F_120 ( struct V_81 * V_82 ,
unsigned V_189 )
{
struct V_57 * V_58 = F_27 ( V_82 ) ;
return V_58 -> V_68 -> V_214 [ V_189 ] . V_144 ;
}
static int F_121 ( struct V_81 * V_82 ,
unsigned V_189 ,
const char * const * * V_178 ,
unsigned * const V_215 )
{
struct V_57 * V_58 = F_27 ( V_82 ) ;
* V_178 = V_58 -> V_68 -> V_214 [ V_189 ] . V_178 ;
* V_215 = V_58 -> V_68 -> V_214 [ V_189 ] . V_176 ;
return 0 ;
}
static int F_122 ( struct V_81 * V_82 , unsigned V_189 ,
unsigned V_188 )
{
struct V_57 * V_58 = F_27 ( V_82 ) ;
const struct V_216 * V_217 ;
static unsigned int V_15 [ V_77 ] ;
unsigned long V_104 = 0 ;
bool V_34 ;
int V_153 = - V_85 ;
int V_60 ;
V_217 = & V_58 -> V_68 -> V_178 [ V_188 ] ;
if ( V_217 -> V_218 < 0 )
return - V_85 ;
F_17 ( V_58 -> V_67 , L_46 , V_217 -> V_144 , V_217 -> V_181 ) ;
V_34 = ( ( V_217 -> V_218 & V_83 ) == V_83 ) ;
if ( V_34 ) {
F_36 ( & V_105 , V_104 ) ;
memset ( V_15 , 0xff , sizeof( V_15 ) ) ;
for ( V_60 = 0 ; V_60 < V_217 -> V_181 ; V_60 ++ )
V_15 [ V_217 -> V_179 [ V_60 ] / V_84 ] &= ~ F_7 ( V_217 -> V_179 [ V_60 ] ) ;
F_22 ( V_15 ) ;
}
for ( V_60 = 0 ; V_60 < V_217 -> V_181 ; V_60 ++ ) {
struct V_1 * V_2 ;
unsigned V_5 ;
V_2 = F_101 ( V_217 -> V_179 [ V_60 ] ) ;
if ( ! V_2 ) {
F_20 ( V_58 -> V_67 ,
L_47 ,
V_217 -> V_179 [ V_60 ] , V_217 -> V_144 , V_60 ) ;
goto V_219;
}
F_17 ( V_58 -> V_67 , L_48 , V_217 -> V_179 [ V_60 ] , V_217 -> V_218 ) ;
F_23 ( V_2 -> V_80 ) ;
V_5 = V_217 -> V_179 [ V_60 ] % V_84 ;
F_13 ( V_2 , V_5 ) ;
F_12 ( V_2 , V_5 ,
( V_217 -> V_218 & V_83 ) , V_34 ) ;
F_25 ( V_2 -> V_80 ) ;
if ( ( V_217 -> V_218 & V_83 ) == V_83 )
F_19 ( V_58 , V_217 -> V_179 [ V_60 ] ,
V_217 -> V_218 >> V_220 ) ;
}
V_153 = 0 ;
V_219:
if ( V_34 ) {
F_24 ( V_15 ) ;
F_39 ( & V_105 , V_104 ) ;
}
return V_153 ;
}
static int F_123 ( struct V_81 * V_82 ,
struct V_221 * V_222 ,
unsigned V_3 )
{
struct V_57 * V_58 = F_27 ( V_82 ) ;
struct V_1 * V_2 ;
struct V_86 * V_45 ;
unsigned V_5 ;
if ( ! V_222 ) {
F_20 ( V_58 -> V_67 , L_49 ) ;
return - V_85 ;
}
if ( ! V_222 -> V_223 ) {
F_20 ( V_58 -> V_67 , L_50 ) ;
return - V_85 ;
}
V_45 = V_222 -> V_223 ;
V_2 = F_32 ( V_45 ) ;
F_17 ( V_58 -> V_67 , L_51 , V_3 ) ;
F_23 ( V_2 -> V_80 ) ;
V_5 = V_3 % V_84 ;
F_1 ( V_2 , V_5 , V_128 ) ;
F_25 ( V_2 -> V_80 ) ;
return 0 ;
}
static void F_124 ( struct V_81 * V_82 ,
struct V_221 * V_222 ,
unsigned V_3 )
{
struct V_57 * V_58 = F_27 ( V_82 ) ;
F_17 ( V_58 -> V_67 , L_52 , V_3 ) ;
}
static int F_125 ( struct V_81 * V_82 , unsigned V_71 ,
unsigned long * V_200 )
{
return - V_85 ;
}
static int F_126 ( struct V_81 * V_82 , unsigned V_71 ,
unsigned long * V_194 , unsigned V_195 )
{
static const char * V_224 [] = {
[ V_22 ] = L_53 ,
[ V_24 ] = L_54 ,
[ V_26 ] = L_55 ,
[ 3 ] = L_56
} ;
static const char * V_225 [] = {
[ V_226 ] = L_57 ,
[ V_17 ] = L_58 ,
} ;
struct V_57 * V_58 = F_27 ( V_82 ) ;
struct V_1 * V_2 ;
unsigned V_5 ;
T_6 V_208 ;
int V_19 , V_15 , V_227 , V_32 , V_60 ;
bool V_28 , V_228 , V_229 ;
V_2 = F_101 ( V_71 ) ;
if ( ! V_2 ) {
F_20 ( V_58 -> V_67 ,
L_59 , V_71 ) ;
return - V_85 ;
}
for ( V_60 = 0 ; V_60 < V_195 ; V_60 ++ ) {
V_208 = ( T_6 ) V_194 [ V_60 ] ;
V_19 = F_127 ( V_208 ) ;
V_15 = F_128 ( V_208 ) ;
V_227 = F_129 ( V_208 ) ;
V_32 = F_130 ( V_208 ) ;
V_28 = F_131 ( V_208 ) ;
V_228 = F_132 ( V_208 ) ;
V_229 = F_133 ( V_208 ) ;
if ( V_229 ) {
int V_230 = F_134 ( V_208 ) ;
int V_231 = F_135 ( V_208 ) ;
int V_232 = F_136 ( V_208 ) ;
V_228 = true ;
if ( V_230 )
V_19 = V_230 - 1 ;
if ( V_231 )
V_227 = V_231 - 1 ;
if ( V_232 )
V_32 = V_232 - 1 ;
F_17 ( V_2 -> V_45 . V_53 ,
L_60 ,
V_71 ,
V_230 ? V_224 [ V_19 ] : L_61 ,
V_231 ? ( V_227 ? L_62 : L_63 )
: L_61 ,
V_232 ? ( V_32 ? L_64 : L_65 ) : L_61 ) ;
}
F_17 ( V_2 -> V_45 . V_53 ,
L_66 ,
V_71 , V_208 , V_224 [ V_19 ] , V_225 [ V_15 ] ,
V_227 ? L_67 : L_63 ,
V_227 ? ( V_32 ? L_64 : L_65 ) : L_30 ,
V_28 ? L_68 : L_69 ) ;
F_23 ( V_2 -> V_80 ) ;
V_5 = V_71 % V_84 ;
if ( V_228 )
F_1 ( V_2 , V_5 , V_128 ) ;
if ( V_227 )
F_11 ( V_2 , V_5 , V_32 ) ;
else {
F_9 ( V_2 , V_5 ) ;
F_5 ( V_2 , V_5 , V_19 ) ;
}
F_6 ( V_2 , V_5 , V_28 ) ;
F_4 ( V_2 , V_5 , V_15 ) ;
F_25 ( V_2 -> V_80 ) ;
}
return 0 ;
}
static int F_137 ( struct V_233 * V_67 )
{
struct V_57 * V_58 ;
V_58 = F_138 ( V_67 ) ;
if ( ! V_58 )
return - V_85 ;
return F_139 ( V_58 -> V_234 ) ;
}
static int F_140 ( struct V_233 * V_67 )
{
struct V_57 * V_58 ;
V_58 = F_138 ( V_67 ) ;
if ( ! V_58 )
return - V_85 ;
return F_141 ( V_58 -> V_234 ) ;
}
static int F_142 ( struct V_138 * V_139 )
{
const struct V_235 * V_236 ;
struct V_136 * V_137 = V_139 -> V_67 . V_149 ;
struct V_136 * V_237 ;
struct V_57 * V_58 ;
unsigned int V_238 = 0 ;
int V_60 ;
V_58 = F_76 ( & V_139 -> V_67 , sizeof( * V_58 ) , V_146 ) ;
if ( ! V_58 )
return - V_147 ;
V_236 = F_143 ( V_239 , & V_139 -> V_67 ) ;
if ( ! V_236 )
return - V_145 ;
V_238 = ( unsigned int ) V_236 -> V_192 ;
if ( V_238 == V_240 )
F_144 ( & V_58 -> V_68 ) ;
if ( V_238 == V_241 )
F_145 ( & V_58 -> V_68 ) ;
if ( V_238 == V_242 )
F_146 ( & V_58 -> V_68 ) ;
for ( V_60 = 0 ; V_60 < V_183 ; V_60 ++ ) {
struct V_136 * V_243 ;
struct V_1 * V_2 ;
V_243 = F_115 ( V_137 , L_70 , V_60 ) ;
if ( V_243 ) {
F_97 ( & V_139 -> V_67 ,
L_71 ,
V_60 , V_243 -> V_144 ) ;
V_2 = F_71 ( V_243 , V_139 ) ;
if ( F_80 ( V_2 ) )
F_20 ( & V_139 -> V_67 ,
L_72
L_73 ) ;
F_147 ( V_243 ) ;
}
}
V_237 = F_115 ( V_137 , L_74 , 0 ) ;
if ( V_237 )
V_58 -> V_65 = F_148 ( V_237 , 0 ) ;
if ( ! V_58 -> V_65 ) {
if ( V_238 == V_240 ) {
F_97 ( & V_139 -> V_67 ,
L_75
L_76 ) ;
} else {
F_20 ( & V_139 -> V_67 , L_77 ) ;
return - V_85 ;
}
}
V_244 . V_179 = V_58 -> V_68 -> V_179 ;
V_244 . V_181 = V_58 -> V_68 -> V_181 ;
V_58 -> V_67 = & V_139 -> V_67 ;
V_58 -> V_234 = F_149 ( & V_244 , & V_139 -> V_67 , V_58 ) ;
if ( F_80 ( V_58 -> V_234 ) ) {
F_20 ( & V_139 -> V_67 , L_78 ) ;
return F_86 ( V_58 -> V_234 ) ;
}
F_93 ( V_139 , V_58 ) ;
F_97 ( & V_139 -> V_67 , L_79 ) ;
return 0 ;
}
static int T_7 F_150 ( void )
{
return F_151 ( & V_245 ) ;
}
static int T_7 F_152 ( void )
{
return F_151 ( & V_246 ) ;
}

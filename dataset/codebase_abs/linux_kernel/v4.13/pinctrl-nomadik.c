static void F_1 ( struct V_1 * V_2 ,
unsigned V_3 , int V_4 )
{
T_1 V_5 , V_6 ;
V_5 = F_2 ( V_2 -> V_7 + V_8 ) & ~ F_3 ( V_3 ) ;
V_6 = F_2 ( V_2 -> V_7 + V_9 ) & ~ F_3 ( V_3 ) ;
if ( V_4 & V_10 )
V_5 |= F_3 ( V_3 ) ;
if ( V_4 & V_11 )
V_6 |= F_3 ( V_3 ) ;
F_4 ( V_5 , V_2 -> V_7 + V_8 ) ;
F_4 ( V_6 , V_2 -> V_7 + V_9 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
unsigned V_3 , enum V_12 V_13 )
{
T_1 V_14 ;
V_14 = F_2 ( V_2 -> V_7 + V_15 ) ;
if ( V_13 == V_16 )
V_14 |= F_3 ( V_3 ) ;
else
V_14 &= ~ F_3 ( V_3 ) ;
F_4 ( V_14 , V_2 -> V_7 + V_15 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
unsigned V_3 , enum V_17 V_18 )
{
T_1 V_19 ;
V_19 = F_2 ( V_2 -> V_7 + V_20 ) ;
if ( V_18 == V_21 ) {
V_19 |= F_3 ( V_3 ) ;
V_2 -> V_22 &= ~ F_3 ( V_3 ) ;
} else {
V_19 &= ~ F_3 ( V_3 ) ;
}
F_4 ( V_19 , V_2 -> V_7 + V_20 ) ;
if ( V_18 == V_23 ) {
V_2 -> V_22 |= F_3 ( V_3 ) ;
F_4 ( F_3 ( V_3 ) , V_2 -> V_7 + V_24 ) ;
} else if ( V_18 == V_25 ) {
V_2 -> V_22 &= ~ F_3 ( V_3 ) ;
F_4 ( F_3 ( V_3 ) , V_2 -> V_7 + V_26 ) ;
}
}
static void F_7 ( struct V_1 * V_2 ,
unsigned V_3 , bool V_27 )
{
bool V_28 = V_2 -> V_27 & F_3 ( V_3 ) ;
if ( V_27 == V_28 )
return;
if ( V_27 )
V_2 -> V_27 |= F_3 ( V_3 ) ;
else
V_2 -> V_27 &= ~ F_3 ( V_3 ) ;
F_8 ( V_2 -> V_27 ,
V_2 -> V_7 + V_29 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
unsigned V_3 )
{
F_4 ( F_3 ( V_3 ) , V_2 -> V_7 + V_30 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
unsigned V_3 , int V_31 )
{
if ( V_31 )
F_4 ( F_3 ( V_3 ) , V_2 -> V_7 + V_24 ) ;
else
F_4 ( F_3 ( V_3 ) , V_2 -> V_7 + V_26 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
unsigned V_3 , int V_31 )
{
F_4 ( F_3 ( V_3 ) , V_2 -> V_7 + V_32 ) ;
F_10 ( V_2 , V_3 , V_31 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
unsigned V_3 , int V_4 ,
bool V_33 )
{
T_1 V_34 = V_2 -> V_34 ;
T_1 V_35 = V_2 -> V_35 ;
if ( V_33 && V_2 -> V_36 ) {
T_1 V_37 = F_3 ( V_3 ) ;
F_4 ( V_34 & ~ V_37 , V_2 -> V_7 + V_38 ) ;
F_4 ( V_35 & ~ V_37 , V_2 -> V_7 + V_39 ) ;
V_2 -> V_36 ( true ) ;
}
F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_33 && V_2 -> V_36 ) {
V_2 -> V_36 ( false ) ;
F_4 ( V_34 , V_2 -> V_7 + V_38 ) ;
F_4 ( V_35 , V_2 -> V_7 + V_39 ) ;
}
}
static void
F_13 ( struct V_1 * V_2 , unsigned V_3 )
{
T_1 V_40 = V_2 -> V_41 & F_3 ( V_3 ) ;
T_1 V_42 = V_2 -> V_43 & F_3 ( V_3 ) ;
int V_44 = V_2 -> V_45 . V_46 + V_3 ;
int V_47 = F_14 ( V_2 -> V_45 . V_48 , V_3 ) ;
struct V_49 * V_50 = F_15 ( V_47 ) ;
if ( ! V_42 && ! V_40 )
return;
if ( ! V_50 || ! F_16 ( V_50 ) )
return;
if ( V_42 ) {
V_2 -> V_43 &= ~ F_3 ( V_3 ) ;
F_8 ( V_2 -> V_43 ,
V_2 -> V_7 + V_51 ) ;
}
if ( V_40 ) {
V_2 -> V_41 &= ~ F_3 ( V_3 ) ;
F_8 ( V_2 -> V_41 ,
V_2 -> V_7 + V_52 ) ;
}
F_17 ( V_2 -> V_45 . V_53 , L_1 , V_44 ) ;
}
static void F_18 ( void T_2 * V_54 , T_1 V_55 , T_1 V_56 )
{
T_1 V_31 ;
V_31 = F_2 ( V_54 ) ;
V_31 = ( ( V_31 & ~ V_55 ) | ( V_56 & V_55 ) ) ;
F_4 ( V_31 , V_54 ) ;
}
static void F_19 ( struct V_57 * V_58 ,
unsigned V_3 , unsigned V_59 )
{
int V_60 ;
T_3 V_54 ;
T_4 V_37 ;
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
V_37 = V_63 -> V_73 [ V_60 ] . V_76 ;
if ( F_2 ( V_58 -> V_65 + V_54 ) & F_3 ( V_37 ) ) {
F_18 ( V_58 -> V_65 + V_54 , F_3 ( V_37 ) , 0 ) ;
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
V_37 = V_63 -> V_73 [ V_60 ] . V_76 ;
if ( F_2 ( V_58 -> V_65 + V_54 ) & F_3 ( V_37 ) ) {
F_18 ( V_58 -> V_65 + V_54 , F_3 ( V_37 ) , 0 ) ;
F_17 ( V_58 -> V_67 ,
L_4 ,
V_3 , V_60 + 1 ) ;
}
}
}
V_54 = V_64 [ V_63 -> V_73 [ V_61 ] . V_75 ] ;
V_37 = V_63 -> V_73 [ V_61 ] . V_76 ;
F_17 ( V_58 -> V_67 , L_6 ,
V_3 , V_61 + 1 ) ;
F_18 ( V_58 -> V_65 + V_54 , F_3 ( V_37 ) , F_3 ( V_37 ) ) ;
}
static void F_22 ( unsigned int * V_14 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_77 ; V_60 ++ ) {
struct V_1 * V_45 = V_78 [ V_60 ] ;
unsigned int V_79 = V_14 [ V_60 ] ;
if ( ! V_45 )
break;
F_23 ( V_45 -> V_80 ) ;
V_14 [ V_60 ] = F_2 ( V_45 -> V_7 + V_15 ) ;
F_4 ( V_79 , V_45 -> V_7 + V_15 ) ;
}
}
static void F_24 ( unsigned int * V_14 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_77 ; V_60 ++ ) {
struct V_1 * V_45 = V_78 [ V_60 ] ;
if ( ! V_45 )
break;
F_4 ( V_14 [ V_60 ] , V_45 -> V_7 + V_15 ) ;
F_25 ( V_45 -> V_80 ) ;
}
}
static int T_5 F_26 ( struct V_81 * V_82 , int V_44 )
{
int V_60 ;
T_3 V_54 ;
T_4 V_37 ;
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
V_37 = V_63 -> V_73 [ V_60 ] . V_76 ;
if ( F_2 ( V_58 -> V_65 + V_54 ) & F_3 ( V_37 ) )
return V_83 + V_60 + 1 ;
}
}
return V_83 ;
}
static void F_28 ( struct V_49 * V_50 )
{
struct V_84 * V_45 = F_29 ( V_50 ) ;
struct V_1 * V_2 = F_30 ( V_45 ) ;
F_23 ( V_2 -> V_80 ) ;
F_4 ( F_3 ( V_50 -> V_85 ) , V_2 -> V_7 + V_86 ) ;
F_25 ( V_2 -> V_80 ) ;
}
static void F_31 ( struct V_1 * V_2 ,
int V_3 , enum V_87 V_88 ,
bool V_89 )
{
T_1 * V_90 ;
T_1 * V_91 ;
T_1 V_92 ;
T_1 V_93 ;
if ( V_88 == V_94 ) {
V_92 = V_51 ;
V_93 = V_52 ;
V_90 = & V_2 -> V_43 ;
V_91 = & V_2 -> V_41 ;
} else {
V_92 = V_38 ;
V_93 = V_39 ;
V_90 = & V_2 -> V_34 ;
V_91 = & V_2 -> V_35 ;
}
if ( V_2 -> V_95 & F_3 ( V_3 ) ) {
if ( V_89 )
* V_90 |= F_3 ( V_3 ) ;
else
* V_90 &= ~ F_3 ( V_3 ) ;
F_4 ( * V_90 , V_2 -> V_7 + V_92 ) ;
}
if ( V_2 -> V_96 & F_3 ( V_3 ) ) {
if ( V_89 )
* V_91 |= F_3 ( V_3 ) ;
else
* V_91 &= ~ F_3 ( V_3 ) ;
F_4 ( * V_91 , V_2 -> V_7 + V_93 ) ;
}
}
static void F_32 ( struct V_1 * V_2 ,
int V_3 , bool V_97 )
{
if ( V_2 -> V_98 && V_97 ) {
F_5 ( V_2 , V_3 ,
V_99 ) ;
}
F_31 ( V_2 , V_3 , V_100 , V_97 ) ;
}
static int F_33 ( struct V_49 * V_50 , bool V_89 )
{
struct V_1 * V_2 ;
unsigned long V_101 ;
V_2 = F_29 ( V_50 ) ;
if ( ! V_2 )
return - V_102 ;
F_23 ( V_2 -> V_80 ) ;
F_34 ( & V_103 , V_101 ) ;
F_35 ( & V_2 -> V_104 ) ;
F_31 ( V_2 , V_50 -> V_85 , V_94 , V_89 ) ;
if ( ! ( V_2 -> V_105 & F_3 ( V_50 -> V_85 ) ) )
F_32 ( V_2 , V_50 -> V_85 , V_89 ) ;
F_36 ( & V_2 -> V_104 ) ;
F_37 ( & V_103 , V_101 ) ;
F_25 ( V_2 -> V_80 ) ;
return 0 ;
}
static void F_38 ( struct V_49 * V_50 )
{
F_33 ( V_50 , false ) ;
}
static void F_39 ( struct V_49 * V_50 )
{
F_33 ( V_50 , true ) ;
}
static int F_40 ( struct V_49 * V_50 , unsigned int V_97 )
{
struct V_1 * V_2 ;
unsigned long V_101 ;
V_2 = F_29 ( V_50 ) ;
if ( ! V_2 )
return - V_102 ;
F_23 ( V_2 -> V_80 ) ;
F_34 ( & V_103 , V_101 ) ;
F_35 ( & V_2 -> V_104 ) ;
if ( F_16 ( V_50 ) )
F_32 ( V_2 , V_50 -> V_85 , V_97 ) ;
if ( V_97 )
V_2 -> V_105 |= F_3 ( V_50 -> V_85 ) ;
else
V_2 -> V_105 &= ~ F_3 ( V_50 -> V_85 ) ;
F_36 ( & V_2 -> V_104 ) ;
F_37 ( & V_103 , V_101 ) ;
F_25 ( V_2 -> V_80 ) ;
return 0 ;
}
static int F_41 ( struct V_49 * V_50 , unsigned int type )
{
bool V_28 = ! F_16 ( V_50 ) ;
bool V_106 = F_42 ( V_50 ) ;
struct V_1 * V_2 ;
unsigned long V_101 ;
V_2 = F_29 ( V_50 ) ;
if ( ! V_2 )
return - V_102 ;
if ( type & V_107 )
return - V_102 ;
if ( type & V_108 )
return - V_102 ;
F_23 ( V_2 -> V_80 ) ;
F_34 ( & V_2 -> V_104 , V_101 ) ;
if ( V_28 )
F_31 ( V_2 , V_50 -> V_85 , V_94 , false ) ;
if ( V_28 || V_106 )
F_31 ( V_2 , V_50 -> V_85 , V_100 , false ) ;
V_2 -> V_95 &= ~ F_3 ( V_50 -> V_85 ) ;
if ( type & V_109 )
V_2 -> V_95 |= F_3 ( V_50 -> V_85 ) ;
V_2 -> V_96 &= ~ F_3 ( V_50 -> V_85 ) ;
if ( type & V_110 )
V_2 -> V_96 |= F_3 ( V_50 -> V_85 ) ;
if ( V_28 )
F_31 ( V_2 , V_50 -> V_85 , V_94 , true ) ;
if ( V_28 || V_106 )
F_31 ( V_2 , V_50 -> V_85 , V_100 , true ) ;
F_37 ( & V_2 -> V_104 , V_101 ) ;
F_25 ( V_2 -> V_80 ) ;
return 0 ;
}
static unsigned int F_43 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_29 ( V_50 ) ;
F_23 ( V_2 -> V_80 ) ;
F_39 ( V_50 ) ;
return 0 ;
}
static void F_44 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_29 ( V_50 ) ;
F_38 ( V_50 ) ;
F_25 ( V_2 -> V_80 ) ;
}
static void F_45 ( struct V_111 * V_112 , T_1 V_113 )
{
struct V_114 * V_115 = F_46 ( V_112 ) ;
struct V_84 * V_45 = F_47 ( V_112 ) ;
F_48 ( V_115 , V_112 ) ;
while ( V_113 ) {
int V_37 = F_49 ( V_113 ) ;
F_50 ( F_14 ( V_45 -> V_48 , V_37 ) ) ;
V_113 &= ~ F_3 ( V_37 ) ;
}
F_51 ( V_115 , V_112 ) ;
}
static void F_52 ( struct V_111 * V_112 )
{
struct V_84 * V_45 = F_47 ( V_112 ) ;
struct V_1 * V_2 = F_30 ( V_45 ) ;
T_1 V_113 ;
F_23 ( V_2 -> V_80 ) ;
V_113 = F_2 ( V_2 -> V_7 + V_116 ) ;
F_25 ( V_2 -> V_80 ) ;
F_45 ( V_112 , V_113 ) ;
}
static void F_53 ( struct V_111 * V_112 )
{
struct V_84 * V_45 = F_47 ( V_112 ) ;
struct V_1 * V_2 = F_30 ( V_45 ) ;
T_1 V_113 = V_2 -> V_117 ( V_2 -> V_118 ) ;
F_45 ( V_112 , V_113 ) ;
}
static int F_54 ( struct V_84 * V_45 , unsigned V_3 )
{
struct V_1 * V_2 = F_30 ( V_45 ) ;
int V_119 ;
F_23 ( V_2 -> V_80 ) ;
V_119 = ! ( F_2 ( V_2 -> V_7 + V_120 ) & F_3 ( V_3 ) ) ;
F_25 ( V_2 -> V_80 ) ;
return V_119 ;
}
static int F_55 ( struct V_84 * V_45 , unsigned V_3 )
{
struct V_1 * V_2 = F_30 ( V_45 ) ;
F_23 ( V_2 -> V_80 ) ;
F_4 ( F_3 ( V_3 ) , V_2 -> V_7 + V_30 ) ;
F_25 ( V_2 -> V_80 ) ;
return 0 ;
}
static int F_56 ( struct V_84 * V_45 , unsigned V_3 )
{
struct V_1 * V_2 = F_30 ( V_45 ) ;
int V_56 ;
F_23 ( V_2 -> V_80 ) ;
V_56 = ! ! ( F_2 ( V_2 -> V_7 + V_121 ) & F_3 ( V_3 ) ) ;
F_25 ( V_2 -> V_80 ) ;
return V_56 ;
}
static void F_57 ( struct V_84 * V_45 , unsigned V_3 ,
int V_31 )
{
struct V_1 * V_2 = F_30 ( V_45 ) ;
F_23 ( V_2 -> V_80 ) ;
F_10 ( V_2 , V_3 , V_31 ) ;
F_25 ( V_2 -> V_80 ) ;
}
static int F_58 ( struct V_84 * V_45 , unsigned V_3 ,
int V_31 )
{
struct V_1 * V_2 = F_30 ( V_45 ) ;
F_23 ( V_2 -> V_80 ) ;
F_11 ( V_2 , V_3 , V_31 ) ;
F_25 ( V_2 -> V_80 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_5 , V_6 ;
F_23 ( V_2 -> V_80 ) ;
V_5 = F_2 ( V_2 -> V_7 + V_8 ) & F_3 ( V_3 ) ;
V_6 = F_2 ( V_2 -> V_7 + V_9 ) & F_3 ( V_3 ) ;
F_25 ( V_2 -> V_80 ) ;
return ( V_5 ? V_10 : 0 ) | ( V_6 ? V_11 : 0 ) ;
}
static void F_60 ( struct V_122 * V_123 ,
struct V_81 * V_82 , struct V_84 * V_45 ,
unsigned V_3 , unsigned V_44 )
{
const char * V_124 = F_61 ( V_45 , V_3 ) ;
struct V_1 * V_2 = F_30 ( V_45 ) ;
int V_13 ;
bool V_125 ;
bool V_126 ;
bool V_18 ;
const char * V_127 [] = {
[ V_128 ] = L_7 ,
[ V_10 ] = L_8 ,
[ V_11 ] = L_9 ,
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
V_125 = ! ! ( F_2 ( V_2 -> V_7 + V_120 ) & F_3 ( V_3 ) ) ;
V_18 = ! ( F_2 ( V_2 -> V_7 + V_20 ) & F_3 ( V_3 ) ) ;
V_126 = ! ! ( F_2 ( V_2 -> V_7 + V_121 ) & F_3 ( V_3 ) ) ;
V_13 = F_59 ( V_2 , V_3 ) ;
if ( ( V_13 == V_83 ) && V_82 )
V_13 = F_26 ( V_82 , V_44 ) ;
if ( V_125 ) {
F_62 ( V_123 , L_18 ,
V_44 ,
V_124 ? : L_19 ,
V_126 ? L_20 : L_21 ,
( V_13 < 0 ) ? L_22 : V_127 [ V_13 ] ) ;
} else {
int V_47 = F_63 ( V_44 ) ;
struct V_111 * V_112 = F_64 ( V_47 ) ;
int V_130 = 0 ;
int V_31 ;
if ( V_18 )
V_130 = V_126 ? 2 : 1 ;
F_62 ( V_123 , L_23 ,
V_44 ,
V_124 ? : L_19 ,
V_129 [ V_130 ] ,
( V_13 < 0 ) ? L_22 : V_127 [ V_13 ] ) ;
V_31 = F_56 ( V_45 , V_3 ) ;
F_62 ( V_123 , L_24 , V_31 ) ;
if ( V_47 > 0 && V_112 && V_112 -> V_131 ) {
char * V_132 ;
if ( V_2 -> V_95 & F_3 ( V_3 ) )
V_132 = L_25 ;
else if ( V_2 -> V_96 & F_3 ( V_3 ) )
V_132 = L_26 ;
else
V_132 = L_27 ;
F_62 ( V_123 , L_28 ,
V_47 , V_132 ,
F_42 ( & V_112 -> V_49 )
? L_29 : L_30 ) ;
}
}
F_25 ( V_2 -> V_80 ) ;
}
static void F_65 ( struct V_122 * V_123 , struct V_84 * V_45 )
{
unsigned V_60 ;
unsigned V_44 = V_45 -> V_46 ;
for ( V_60 = 0 ; V_60 < V_45 -> V_133 ; V_60 ++ , V_44 ++ ) {
F_60 ( V_123 , NULL , V_45 , V_60 , V_44 ) ;
F_62 ( V_123 , L_31 ) ;
}
}
static inline void F_60 ( struct V_122 * V_123 ,
struct V_81 * V_82 ,
struct V_84 * V_45 ,
unsigned V_3 , unsigned V_44 )
{
}
static struct V_1 * F_66 ( struct V_134 * V_135 ,
struct V_136 * V_137 )
{
struct V_1 * V_2 ;
struct V_136 * V_138 ;
struct V_84 * V_45 ;
struct V_139 * V_140 ;
struct V_80 * V_80 ;
void T_2 * V_46 ;
T_1 V_141 ;
V_138 = F_67 ( V_135 ) ;
if ( ! V_138 ) {
F_68 ( L_32 , V_135 -> V_142 ) ;
return F_69 ( - V_143 ) ;
}
if ( F_70 ( V_135 , L_33 , & V_141 ) ) {
F_20 ( & V_137 -> V_67 , L_34 ) ;
return F_69 ( - V_102 ) ;
}
V_2 = V_78 [ V_141 ] ;
if ( V_2 )
return V_2 ;
V_2 = F_71 ( & V_137 -> V_67 , sizeof( * V_2 ) , V_144 ) ;
if ( ! V_2 )
return F_69 ( - V_145 ) ;
V_2 -> V_118 = V_141 ;
V_45 = & V_2 -> V_45 ;
V_45 -> V_46 = V_141 * V_146 ;
V_45 -> V_133 = V_146 ;
V_45 -> V_124 = F_72 ( & V_138 -> V_67 ) ;
V_45 -> V_53 = & V_138 -> V_67 ;
V_140 = F_73 ( V_138 , V_147 , 0 ) ;
V_46 = F_74 ( & V_137 -> V_67 , V_140 ) ;
if ( F_75 ( V_46 ) )
return V_46 ;
V_2 -> V_7 = V_46 ;
V_80 = F_76 ( & V_138 -> V_67 , NULL ) ;
if ( F_75 ( V_80 ) )
return ( void * ) V_80 ;
F_77 ( V_80 ) ;
V_2 -> V_80 = V_80 ;
F_78 ( V_2 -> V_118 >= F_79 ( V_78 ) ) ;
V_78 [ V_141 ] = V_2 ;
return V_2 ;
}
static int F_80 ( struct V_136 * V_67 )
{
struct V_134 * V_135 = V_67 -> V_67 . V_148 ;
struct V_1 * V_2 ;
struct V_84 * V_45 ;
struct V_114 * V_149 ;
int V_150 ;
bool V_151 ;
int V_47 ;
int V_152 ;
V_2 = F_66 ( V_135 , V_67 ) ;
if ( F_75 ( V_2 ) ) {
F_20 ( & V_67 -> V_67 , L_35 ) ;
return F_81 ( V_2 ) ;
}
V_151 =
F_82 ( V_135 , L_36 ) ;
V_67 -> V_141 = V_2 -> V_118 ;
V_47 = F_83 ( V_67 , 0 ) ;
if ( V_47 < 0 )
return V_47 ;
V_150 = F_83 ( V_67 , 1 ) ;
V_2 -> V_153 = V_47 ;
V_2 -> V_154 = V_150 ;
V_2 -> V_98 = V_151 ;
F_84 ( & V_2 -> V_104 ) ;
V_45 = & V_2 -> V_45 ;
V_45 -> V_155 = V_156 ;
V_45 -> free = V_157 ;
V_45 -> V_158 = F_54 ;
V_45 -> V_159 = F_55 ;
V_45 -> V_160 = F_56 ;
V_45 -> V_161 = F_58 ;
V_45 -> V_162 = F_57 ;
V_45 -> V_163 = F_65 ;
V_45 -> V_164 = false ;
V_45 -> V_165 = V_166 ;
V_149 = & V_2 -> V_149 ;
V_149 -> V_167 = F_28 ;
V_149 -> V_168 = F_38 ;
V_149 -> V_169 = F_39 ;
V_149 -> V_170 = F_41 ;
V_149 -> V_171 = F_40 ;
V_149 -> V_172 = F_43 ;
V_149 -> V_173 = F_44 ;
V_149 -> V_101 = V_174 ;
V_149 -> V_142 = F_85 ( V_144 , L_37 ,
V_67 -> V_141 ,
V_45 -> V_46 ,
V_45 -> V_46 + V_45 -> V_133 - 1 ) ;
F_23 ( V_2 -> V_80 ) ;
V_2 -> V_27 = F_86 ( V_2 -> V_7 + V_29 ) ;
F_25 ( V_2 -> V_80 ) ;
V_45 -> V_148 = V_135 ;
V_152 = F_87 ( V_45 , V_2 ) ;
if ( V_152 )
return V_152 ;
F_88 ( V_67 , V_2 ) ;
V_152 = F_89 ( V_45 ,
V_149 ,
0 ,
V_175 ,
V_176 ) ;
if ( V_152 ) {
F_20 ( & V_67 -> V_67 , L_38 ) ;
F_90 ( & V_2 -> V_45 ) ;
return - V_143 ;
}
F_91 ( V_45 ,
V_149 ,
V_2 -> V_153 ,
F_52 ) ;
if ( V_2 -> V_154 > 0 )
F_91 ( V_45 ,
V_149 ,
V_2 -> V_154 ,
F_53 ) ;
F_92 ( & V_67 -> V_67 , L_39 , V_2 -> V_7 ) ;
return 0 ;
}
static int F_93 ( struct V_81 * V_82 )
{
struct V_57 * V_58 = F_27 ( V_82 ) ;
return V_58 -> V_68 -> V_177 ;
}
static const char * F_94 ( struct V_81 * V_82 ,
unsigned V_178 )
{
struct V_57 * V_58 = F_27 ( V_82 ) ;
return V_58 -> V_68 -> V_179 [ V_178 ] . V_142 ;
}
static int F_95 ( struct V_81 * V_82 , unsigned V_178 ,
const unsigned * * V_180 ,
unsigned * V_181 )
{
struct V_57 * V_58 = F_27 ( V_82 ) ;
* V_180 = V_58 -> V_68 -> V_179 [ V_178 ] . V_180 ;
* V_181 = V_58 -> V_68 -> V_179 [ V_178 ] . V_182 ;
return 0 ;
}
static struct V_1 * F_96 ( unsigned V_71 )
{
int V_60 ;
struct V_1 * V_183 ;
for( V_60 = 0 ; V_60 < V_184 ; V_60 ++ ) {
V_183 = V_78 [ V_60 ] ;
if ( ! V_183 )
continue;
if ( V_71 >= V_183 -> V_45 . V_46 &&
V_71 < V_183 -> V_45 . V_46 + V_183 -> V_45 . V_133 )
return V_183 ;
}
return NULL ;
}
static struct V_84 * F_97 ( unsigned V_71 )
{
struct V_1 * V_183 = F_96 ( V_71 ) ;
if ( V_183 )
return & V_183 -> V_45 ;
return NULL ;
}
static void F_98 ( struct V_81 * V_82 , struct V_122 * V_123 ,
unsigned V_3 )
{
struct V_84 * V_45 = F_97 ( V_3 ) ;
if ( ! V_45 ) {
F_62 ( V_123 , L_40 ) ;
return;
}
F_60 ( V_123 , V_82 , V_45 , V_3 - V_45 -> V_46 , V_3 ) ;
}
static int F_99 ( struct V_185 * * V_186 , unsigned * V_187 ,
unsigned * V_188 , const char * V_189 ,
const char * V_190 )
{
if ( * V_188 == * V_187 )
return - V_191 ;
( * V_186 ) [ * V_188 ] . type = V_192 ;
( * V_186 ) [ * V_188 ] . V_193 . V_194 . V_189 = V_189 ;
( * V_186 ) [ * V_188 ] . V_193 . V_194 . V_190 = V_190 ;
( * V_188 ) ++ ;
return 0 ;
}
static int F_100 ( struct V_185 * * V_186 ,
unsigned * V_187 ,
unsigned * V_188 , const char * V_189 ,
unsigned long * V_195 , unsigned V_196 )
{
unsigned long * V_197 ;
if ( * V_188 == * V_187 )
return - V_191 ;
V_197 = F_101 ( V_195 , V_196 * sizeof( * V_197 ) ,
V_144 ) ;
if ( ! V_197 )
return - V_145 ;
( * V_186 ) [ * V_188 ] . type = V_198 ;
( * V_186 ) [ * V_188 ] . V_193 . V_195 . V_199 = V_189 ;
( * V_186 ) [ * V_188 ] . V_193 . V_195 . V_195 = V_197 ;
( * V_186 ) [ * V_188 ] . V_193 . V_195 . V_196 = V_196 ;
( * V_188 ) ++ ;
return 0 ;
}
static int F_102 ( int V_200 , int V_31 , unsigned long * V_201 )
{
int V_152 = 0 ;
if ( V_202 [ V_200 ] . V_203 == NULL )
* V_201 = V_202 [ V_200 ] . V_201 ;
else {
if ( V_31 < V_202 [ V_200 ] . V_204 ) {
* V_201 = V_202 [ V_200 ] . V_201 |
V_202 [ V_200 ] . V_203 [ V_31 ] ;
}
}
return V_152 ;
}
static const char * F_103 ( struct V_81 * V_82 , const char * V_205 )
{
int V_60 , V_206 ;
struct V_57 * V_58 = F_27 ( V_82 ) ;
if ( sscanf ( ( char * ) V_205 , L_41 , & V_206 ) == 1 )
for ( V_60 = 0 ; V_60 < V_58 -> V_68 -> V_182 ; V_60 ++ )
if ( V_58 -> V_68 -> V_180 [ V_60 ] . V_207 == V_206 )
return V_58 -> V_68 -> V_180 [ V_60 ] . V_142 ;
return NULL ;
}
static bool F_104 ( struct V_134 * V_135 ,
unsigned long * V_195 )
{
bool V_208 = 0 ;
unsigned long V_209 = 0 ;
int V_60 , V_31 , V_152 ;
for ( V_60 = 0 ; V_60 < F_79 ( V_202 ) ; V_60 ++ ) {
V_152 = F_70 ( V_135 ,
V_202 [ V_60 ] . V_210 , & V_31 ) ;
if ( V_152 != - V_102 ) {
if ( F_102 ( V_60 , V_31 , & V_209 ) == 0 ) {
* V_195 |= V_209 ;
V_208 = 1 ;
}
}
}
return V_208 ;
}
static int F_105 ( struct V_81 * V_82 ,
struct V_134 * V_135 ,
struct V_185 * * V_186 ,
unsigned * V_187 ,
unsigned * V_188 )
{
int V_152 ;
const char * V_190 = NULL ;
unsigned long V_195 = 0 ;
bool V_208 = 0 ;
struct V_210 * V_211 ;
struct V_134 * V_212 ;
V_152 = F_106 ( V_135 , L_42 , & V_190 ) ;
if ( V_152 >= 0 ) {
const char * V_189 ;
V_152 = F_107 ( V_135 , L_43 ) ;
if ( V_152 < 0 )
goto exit;
V_152 = F_108 ( V_82 , V_186 ,
V_187 ,
V_188 , V_152 ) ;
if ( V_152 < 0 )
goto exit;
F_109 (np, L_43 , prop, group) {
V_152 = F_99 ( V_186 , V_187 , V_188 ,
V_189 , V_190 ) ;
if ( V_152 < 0 )
goto exit;
}
}
V_208 = F_104 ( V_135 , & V_195 ) ;
V_212 = F_110 ( V_135 , L_44 , 0 ) ;
if ( V_212 )
V_208 |= F_104 ( V_212 , & V_195 ) ;
if ( V_208 ) {
const char * V_213 ;
const char * V_71 ;
V_152 = F_107 ( V_135 , L_45 ) ;
if ( V_152 < 0 )
goto exit;
V_152 = F_108 ( V_82 , V_186 ,
V_187 ,
V_188 , V_152 ) ;
if ( V_152 < 0 )
goto exit;
F_109 (np, L_45 , prop, pin) {
V_213 = F_103 ( V_82 , V_71 ) ;
V_152 = F_100 ( V_186 , V_187 ,
V_188 ,
V_213 , & V_195 , 1 ) ;
if ( V_152 < 0 )
goto exit;
}
}
exit:
return V_152 ;
}
static int F_111 ( struct V_81 * V_82 ,
struct V_134 * V_212 ,
struct V_185 * * V_186 , unsigned * V_188 )
{
unsigned V_187 ;
struct V_134 * V_135 ;
int V_152 ;
V_187 = 0 ;
* V_186 = NULL ;
* V_188 = 0 ;
F_112 (np_config, np) {
V_152 = F_105 ( V_82 , V_135 , V_186 ,
& V_187 , V_188 ) ;
if ( V_152 < 0 ) {
F_113 ( V_82 , * V_186 , * V_188 ) ;
return V_152 ;
}
}
return 0 ;
}
static int F_114 ( struct V_81 * V_82 )
{
struct V_57 * V_58 = F_27 ( V_82 ) ;
return V_58 -> V_68 -> V_214 ;
}
static const char * F_115 ( struct V_81 * V_82 ,
unsigned V_190 )
{
struct V_57 * V_58 = F_27 ( V_82 ) ;
return V_58 -> V_68 -> V_215 [ V_190 ] . V_142 ;
}
static int F_116 ( struct V_81 * V_82 ,
unsigned V_190 ,
const char * const * * V_179 ,
unsigned * const V_216 )
{
struct V_57 * V_58 = F_27 ( V_82 ) ;
* V_179 = V_58 -> V_68 -> V_215 [ V_190 ] . V_179 ;
* V_216 = V_58 -> V_68 -> V_215 [ V_190 ] . V_177 ;
return 0 ;
}
static int F_117 ( struct V_81 * V_82 , unsigned V_190 ,
unsigned V_189 )
{
struct V_57 * V_58 = F_27 ( V_82 ) ;
const struct V_217 * V_218 ;
static unsigned int V_14 [ V_77 ] ;
unsigned long V_101 = 0 ;
bool V_33 ;
int V_152 = - V_102 ;
int V_60 ;
V_218 = & V_58 -> V_68 -> V_179 [ V_189 ] ;
if ( V_218 -> V_219 < 0 )
return - V_102 ;
F_17 ( V_58 -> V_67 , L_46 , V_218 -> V_142 , V_218 -> V_182 ) ;
V_33 = ( ( V_218 -> V_219 & V_83 ) == V_83 ) ;
if ( V_33 ) {
F_34 ( & V_103 , V_101 ) ;
memset ( V_14 , 0xff , sizeof( V_14 ) ) ;
for ( V_60 = 0 ; V_60 < V_218 -> V_182 ; V_60 ++ )
V_14 [ V_218 -> V_180 [ V_60 ] / V_146 ] &= ~ F_3 ( V_218 -> V_180 [ V_60 ] ) ;
F_22 ( V_14 ) ;
}
for ( V_60 = 0 ; V_60 < V_218 -> V_182 ; V_60 ++ ) {
struct V_1 * V_2 ;
unsigned V_37 ;
V_2 = F_96 ( V_218 -> V_180 [ V_60 ] ) ;
if ( ! V_2 ) {
F_20 ( V_58 -> V_67 ,
L_47 ,
V_218 -> V_180 [ V_60 ] , V_218 -> V_142 , V_60 ) ;
goto V_220;
}
F_17 ( V_58 -> V_67 , L_48 , V_218 -> V_180 [ V_60 ] , V_218 -> V_219 ) ;
F_23 ( V_2 -> V_80 ) ;
V_37 = V_218 -> V_180 [ V_60 ] % V_146 ;
F_13 ( V_2 , V_37 ) ;
F_12 ( V_2 , V_37 ,
( V_218 -> V_219 & V_83 ) , V_33 ) ;
F_25 ( V_2 -> V_80 ) ;
if ( ( V_218 -> V_219 & V_83 ) == V_83 )
F_19 ( V_58 , V_218 -> V_180 [ V_60 ] ,
V_218 -> V_219 >> V_221 ) ;
}
V_152 = 0 ;
V_220:
if ( V_33 ) {
F_24 ( V_14 ) ;
F_37 ( & V_103 , V_101 ) ;
}
return V_152 ;
}
static int F_118 ( struct V_81 * V_82 ,
struct V_222 * V_223 ,
unsigned V_3 )
{
struct V_57 * V_58 = F_27 ( V_82 ) ;
struct V_1 * V_2 ;
struct V_84 * V_45 ;
unsigned V_37 ;
if ( ! V_223 ) {
F_20 ( V_58 -> V_67 , L_49 ) ;
return - V_102 ;
}
if ( ! V_223 -> V_224 ) {
F_20 ( V_58 -> V_67 , L_50 ) ;
return - V_102 ;
}
V_45 = V_223 -> V_224 ;
V_2 = F_30 ( V_45 ) ;
F_17 ( V_58 -> V_67 , L_51 , V_3 ) ;
F_23 ( V_2 -> V_80 ) ;
V_37 = V_3 % V_146 ;
F_1 ( V_2 , V_37 , V_128 ) ;
F_25 ( V_2 -> V_80 ) ;
return 0 ;
}
static void F_119 ( struct V_81 * V_82 ,
struct V_222 * V_223 ,
unsigned V_3 )
{
struct V_57 * V_58 = F_27 ( V_82 ) ;
F_17 ( V_58 -> V_67 , L_52 , V_3 ) ;
}
static int F_120 ( struct V_81 * V_82 , unsigned V_71 ,
unsigned long * V_201 )
{
return - V_102 ;
}
static int F_121 ( struct V_81 * V_82 , unsigned V_71 ,
unsigned long * V_195 , unsigned V_196 )
{
static const char * V_225 [] = {
[ V_21 ] = L_53 ,
[ V_23 ] = L_54 ,
[ V_25 ] = L_55 ,
[ 3 ] = L_56
} ;
static const char * V_226 [] = {
[ V_227 ] = L_57 ,
[ V_16 ] = L_58 ,
} ;
struct V_57 * V_58 = F_27 ( V_82 ) ;
struct V_1 * V_2 ;
unsigned V_37 ;
T_6 V_209 ;
int V_18 , V_14 , V_228 , V_31 , V_60 ;
bool V_27 , V_229 , V_230 ;
V_2 = F_96 ( V_71 ) ;
if ( ! V_2 ) {
F_20 ( V_58 -> V_67 ,
L_59 , V_71 ) ;
return - V_102 ;
}
for ( V_60 = 0 ; V_60 < V_196 ; V_60 ++ ) {
V_209 = ( T_6 ) V_195 [ V_60 ] ;
V_18 = F_122 ( V_209 ) ;
V_14 = F_123 ( V_209 ) ;
V_228 = F_124 ( V_209 ) ;
V_31 = F_125 ( V_209 ) ;
V_27 = F_126 ( V_209 ) ;
V_229 = F_127 ( V_209 ) ;
V_230 = F_128 ( V_209 ) ;
if ( V_230 ) {
int V_231 = F_129 ( V_209 ) ;
int V_232 = F_130 ( V_209 ) ;
int V_233 = F_131 ( V_209 ) ;
V_229 = true ;
if ( V_231 )
V_18 = V_231 - 1 ;
if ( V_232 )
V_228 = V_232 - 1 ;
if ( V_233 )
V_31 = V_233 - 1 ;
F_17 ( V_2 -> V_45 . V_53 ,
L_60 ,
V_71 ,
V_231 ? V_225 [ V_18 ] : L_61 ,
V_232 ? ( V_228 ? L_62 : L_63 )
: L_61 ,
V_233 ? ( V_31 ? L_64 : L_65 ) : L_61 ) ;
}
F_17 ( V_2 -> V_45 . V_53 ,
L_66 ,
V_71 , V_209 , V_225 [ V_18 ] , V_226 [ V_14 ] ,
V_228 ? L_67 : L_63 ,
V_228 ? ( V_31 ? L_64 : L_65 ) : L_30 ,
V_27 ? L_68 : L_69 ) ;
F_23 ( V_2 -> V_80 ) ;
V_37 = V_71 % V_146 ;
if ( V_229 )
F_1 ( V_2 , V_37 , V_128 ) ;
if ( V_228 )
F_11 ( V_2 , V_37 , V_31 ) ;
else {
F_9 ( V_2 , V_37 ) ;
F_6 ( V_2 , V_37 , V_18 ) ;
}
F_7 ( V_2 , V_37 , V_27 ) ;
F_5 ( V_2 , V_37 , V_14 ) ;
F_25 ( V_2 -> V_80 ) ;
}
return 0 ;
}
static int F_132 ( struct V_234 * V_67 )
{
struct V_57 * V_58 ;
V_58 = F_133 ( V_67 ) ;
if ( ! V_58 )
return - V_102 ;
return F_134 ( V_58 -> V_235 ) ;
}
static int F_135 ( struct V_234 * V_67 )
{
struct V_57 * V_58 ;
V_58 = F_133 ( V_67 ) ;
if ( ! V_58 )
return - V_102 ;
return F_136 ( V_58 -> V_235 ) ;
}
static int F_137 ( struct V_136 * V_137 )
{
const struct V_236 * V_237 ;
struct V_134 * V_135 = V_137 -> V_67 . V_148 ;
struct V_134 * V_238 ;
struct V_57 * V_58 ;
unsigned int V_239 = 0 ;
int V_60 ;
V_58 = F_71 ( & V_137 -> V_67 , sizeof( * V_58 ) , V_144 ) ;
if ( ! V_58 )
return - V_145 ;
V_237 = F_138 ( V_240 , & V_137 -> V_67 ) ;
if ( ! V_237 )
return - V_143 ;
V_239 = ( unsigned int ) V_237 -> V_193 ;
if ( V_239 == V_241 )
F_139 ( & V_58 -> V_68 ) ;
if ( V_239 == V_242 )
F_140 ( & V_58 -> V_68 ) ;
if ( V_239 == V_243 )
F_141 ( & V_58 -> V_68 ) ;
for ( V_60 = 0 ; V_60 < V_184 ; V_60 ++ ) {
struct V_134 * V_244 ;
struct V_1 * V_2 ;
V_244 = F_110 ( V_135 , L_70 , V_60 ) ;
if ( V_244 ) {
F_92 ( & V_137 -> V_67 ,
L_71 ,
V_60 , V_244 -> V_142 ) ;
V_2 = F_66 ( V_244 , V_137 ) ;
if ( F_75 ( V_2 ) )
F_20 ( & V_137 -> V_67 ,
L_72
L_73 ) ;
F_142 ( V_244 ) ;
}
}
V_238 = F_110 ( V_135 , L_74 , 0 ) ;
if ( V_238 )
V_58 -> V_65 = F_143 ( V_238 , 0 ) ;
if ( ! V_58 -> V_65 ) {
if ( V_239 == V_241 ) {
F_92 ( & V_137 -> V_67 ,
L_75
L_76 ) ;
} else {
F_20 ( & V_137 -> V_67 , L_77 ) ;
return - V_102 ;
}
}
V_245 . V_180 = V_58 -> V_68 -> V_180 ;
V_245 . V_182 = V_58 -> V_68 -> V_182 ;
V_58 -> V_67 = & V_137 -> V_67 ;
V_58 -> V_235 = F_144 ( & V_137 -> V_67 , & V_245 , V_58 ) ;
if ( F_75 ( V_58 -> V_235 ) ) {
F_20 ( & V_137 -> V_67 , L_78 ) ;
return F_81 ( V_58 -> V_235 ) ;
}
F_88 ( V_137 , V_58 ) ;
F_92 ( & V_137 -> V_67 , L_79 ) ;
return 0 ;
}
static int T_7 F_145 ( void )
{
return F_146 ( & V_246 ) ;
}
static int T_7 F_147 ( void )
{
return F_146 ( & V_247 ) ;
}

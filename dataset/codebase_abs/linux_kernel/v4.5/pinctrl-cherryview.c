static void T_1 * F_1 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned V_4 )
{
unsigned V_5 = V_3 / V_6 ;
unsigned V_7 = V_3 % V_6 ;
V_3 = V_8 + V_9 * V_5 +
V_10 * V_7 ;
return V_2 -> V_11 + V_3 + V_4 ;
}
static void F_2 ( T_2 V_12 , void T_1 * V_4 )
{
F_3 ( V_12 , V_4 ) ;
F_4 ( V_4 ) ;
}
static bool F_5 ( struct V_1 * V_2 , unsigned V_3 )
{
void T_1 * V_4 ;
V_4 = F_1 ( V_2 , V_3 , V_13 ) ;
return F_4 ( V_4 ) & V_14 ;
}
static int F_6 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
return V_2 -> V_17 -> V_18 ;
}
static const char * F_8 ( struct V_15 * V_16 ,
unsigned V_19 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
return V_2 -> V_17 -> V_20 [ V_19 ] . V_21 ;
}
static int F_9 ( struct V_15 * V_16 , unsigned V_19 ,
const unsigned * * V_22 , unsigned * V_23 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
* V_22 = V_2 -> V_17 -> V_20 [ V_19 ] . V_22 ;
* V_23 = V_2 -> V_17 -> V_20 [ V_19 ] . V_23 ;
return 0 ;
}
static void F_10 ( struct V_15 * V_16 , struct V_24 * V_25 ,
unsigned V_3 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
unsigned long V_26 ;
T_2 V_27 , V_28 ;
bool V_29 ;
F_11 ( & V_2 -> V_30 , V_26 ) ;
V_27 = F_4 ( F_1 ( V_2 , V_3 , V_31 ) ) ;
V_28 = F_4 ( F_1 ( V_2 , V_3 , V_13 ) ) ;
V_29 = F_5 ( V_2 , V_3 ) ;
F_12 ( & V_2 -> V_30 , V_26 ) ;
if ( V_27 & V_32 ) {
F_13 ( V_25 , L_1 ) ;
} else {
T_2 V_33 ;
V_33 = V_27 & V_34 ;
V_33 >>= V_35 ;
F_14 ( V_25 , L_2 , V_33 ) ;
}
F_14 ( V_25 , L_3 , V_27 , V_28 ) ;
if ( V_29 )
F_13 ( V_25 , L_4 ) ;
}
static int F_15 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
return V_2 -> V_17 -> V_36 ;
}
static const char * F_16 ( struct V_15 * V_16 ,
unsigned V_37 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
return V_2 -> V_17 -> V_38 [ V_37 ] . V_21 ;
}
static int F_17 ( struct V_15 * V_16 ,
unsigned V_37 ,
const char * const * * V_20 ,
unsigned * const V_18 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
* V_20 = V_2 -> V_17 -> V_38 [ V_37 ] . V_20 ;
* V_18 = V_2 -> V_17 -> V_38 [ V_37 ] . V_18 ;
return 0 ;
}
static int F_18 ( struct V_15 * V_16 , unsigned V_37 ,
unsigned V_19 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
const struct V_39 * V_40 ;
unsigned long V_26 ;
int V_41 ;
V_40 = & V_2 -> V_17 -> V_20 [ V_19 ] ;
F_11 ( & V_2 -> V_30 , V_26 ) ;
for ( V_41 = 0 ; V_41 < V_40 -> V_23 ; V_41 ++ ) {
if ( F_5 ( V_2 , V_40 -> V_22 [ V_41 ] ) ) {
F_19 ( V_2 -> V_42 , L_5 ,
V_40 -> V_22 [ V_41 ] ) ;
F_12 ( & V_2 -> V_30 , V_26 ) ;
return - V_43 ;
}
}
for ( V_41 = 0 ; V_41 < V_40 -> V_23 ; V_41 ++ ) {
const struct V_44 * V_45 = & V_40 -> V_45 ;
int V_46 = V_40 -> V_22 [ V_41 ] ;
void T_1 * V_4 ;
T_2 V_12 ;
if ( V_40 -> V_47 ) {
int V_48 ;
for ( V_48 = 0 ; V_48 < V_40 -> V_49 ; V_48 ++ ) {
if ( V_40 -> V_47 [ V_48 ] . V_46 == V_46 ) {
V_45 = & V_40 -> V_47 [ V_48 ] ;
break;
}
}
}
V_4 = F_1 ( V_2 , V_46 , V_31 ) ;
V_12 = F_4 ( V_4 ) ;
V_12 &= ~ V_32 ;
V_12 &= ~ V_34 ;
V_12 |= V_45 -> V_33 << V_35 ;
F_2 ( V_12 , V_4 ) ;
V_4 = F_1 ( V_2 , V_46 , V_13 ) ;
V_12 = F_4 ( V_4 ) & ~ V_50 ;
if ( V_45 -> V_51 )
V_12 |= V_52 ;
F_2 ( V_12 , V_4 ) ;
F_20 ( V_2 -> V_42 , L_6 ,
V_46 , V_45 -> V_33 , V_45 -> V_51 ? L_7 : L_8 ) ;
}
F_12 ( & V_2 -> V_30 , V_26 ) ;
return 0 ;
}
static int F_21 ( struct V_15 * V_16 ,
struct V_53 * V_54 ,
unsigned V_3 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
unsigned long V_26 ;
void T_1 * V_4 ;
T_2 V_12 ;
F_11 ( & V_2 -> V_30 , V_26 ) ;
if ( F_5 ( V_2 , V_3 ) ) {
V_12 = F_4 ( F_1 ( V_2 , V_3 , V_31 ) ) ;
if ( ! ( V_12 & V_32 ) ) {
F_12 ( & V_2 -> V_30 , V_26 ) ;
return - V_43 ;
}
} else {
int V_41 ;
for ( V_41 = 0 ; V_41 < F_22 ( V_2 -> V_55 ) ; V_41 ++ ) {
if ( V_2 -> V_55 [ V_41 ] == V_3 ) {
V_2 -> V_55 [ V_41 ] = 0 ;
break;
}
}
V_4 = F_1 ( V_2 , V_3 , V_13 ) ;
V_12 = F_4 ( V_4 ) ;
V_12 &= ~ V_56 ;
V_12 &= ~ V_50 ;
F_2 ( V_12 , V_4 ) ;
V_4 = F_1 ( V_2 , V_3 , V_31 ) ;
V_12 = F_4 ( V_4 ) ;
if ( ( V_12 & V_57 ) ==
( V_58 << V_59 ) ) {
V_12 &= ~ V_57 ;
V_12 |= V_60 <<
V_59 ;
}
V_12 |= V_32 ;
F_2 ( V_12 , V_4 ) ;
}
F_12 ( & V_2 -> V_30 , V_26 ) ;
return 0 ;
}
static void F_23 ( struct V_15 * V_16 ,
struct V_53 * V_54 ,
unsigned V_3 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
unsigned long V_26 ;
void T_1 * V_4 ;
T_2 V_12 ;
F_11 ( & V_2 -> V_30 , V_26 ) ;
V_4 = F_1 ( V_2 , V_3 , V_31 ) ;
V_12 = F_4 ( V_4 ) & ~ V_32 ;
F_2 ( V_12 , V_4 ) ;
F_12 ( & V_2 -> V_30 , V_26 ) ;
}
static int F_24 ( struct V_15 * V_16 ,
struct V_53 * V_54 ,
unsigned V_3 , bool V_61 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
void T_1 * V_4 = F_1 ( V_2 , V_3 , V_31 ) ;
unsigned long V_26 ;
T_2 V_27 ;
F_11 ( & V_2 -> V_30 , V_26 ) ;
V_27 = F_4 ( V_4 ) & ~ V_57 ;
if ( V_61 )
V_27 |= V_60 << V_59 ;
else
V_27 |= V_62 << V_59 ;
F_2 ( V_27 , V_4 ) ;
F_12 ( & V_2 -> V_30 , V_26 ) ;
return 0 ;
}
static int F_25 ( struct V_15 * V_16 , unsigned V_46 ,
unsigned long * V_63 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
enum V_64 V_65 = F_26 ( * V_63 ) ;
unsigned long V_26 ;
T_2 V_27 , V_28 ;
T_3 V_66 = 0 ;
T_2 V_67 ;
F_11 ( & V_2 -> V_30 , V_26 ) ;
V_27 = F_4 ( F_1 ( V_2 , V_46 , V_31 ) ) ;
V_28 = F_4 ( F_1 ( V_2 , V_46 , V_13 ) ) ;
F_12 ( & V_2 -> V_30 , V_26 ) ;
V_67 = ( V_27 & V_68 ) >> V_69 ;
switch ( V_65 ) {
case V_70 :
if ( V_67 )
return - V_71 ;
break;
case V_72 :
if ( ! ( V_27 & V_73 ) )
return - V_71 ;
switch ( V_67 ) {
case V_74 :
V_66 = 20000 ;
break;
case V_75 :
V_66 = 5000 ;
break;
case V_76 :
V_66 = 1000 ;
break;
}
break;
case V_77 :
if ( ! V_67 || ( V_27 & V_73 ) )
return - V_71 ;
switch ( V_67 ) {
case V_74 :
V_66 = 20000 ;
break;
case V_75 :
V_66 = 5000 ;
break;
}
break;
case V_78 :
if ( ! ( V_28 & V_79 ) )
return - V_71 ;
break;
case V_80 : {
T_2 V_81 ;
V_81 = V_27 & V_57 ;
V_81 >>= V_59 ;
if ( V_81 != V_58 )
return - V_71 ;
break;
}
default:
return - V_82 ;
}
* V_63 = F_27 ( V_65 , V_66 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , unsigned V_46 ,
enum V_64 V_65 , T_3 V_66 )
{
void T_1 * V_4 = F_1 ( V_2 , V_46 , V_31 ) ;
unsigned long V_26 ;
T_2 V_27 , V_83 ;
F_11 ( & V_2 -> V_30 , V_26 ) ;
V_27 = F_4 ( V_4 ) ;
switch ( V_65 ) {
case V_70 :
V_27 &= ~ ( V_68 | V_73 ) ;
break;
case V_72 :
V_27 &= ~ ( V_68 | V_73 ) ;
switch ( V_66 ) {
case 1000 :
V_83 = V_76 << V_69 ;
break;
case 5000 :
V_83 = V_75 << V_69 ;
break;
case 20000 :
V_83 = V_74 << V_69 ;
break;
default:
F_12 ( & V_2 -> V_30 , V_26 ) ;
return - V_71 ;
}
V_27 |= V_73 | V_83 ;
break;
case V_77 :
V_27 &= ~ ( V_68 | V_73 ) ;
switch ( V_66 ) {
case 5000 :
V_83 = V_75 << V_69 ;
break;
case 20000 :
V_83 = V_74 << V_69 ;
break;
default:
F_12 ( & V_2 -> V_30 , V_26 ) ;
return - V_71 ;
}
V_27 |= V_83 ;
break;
default:
F_12 ( & V_2 -> V_30 , V_26 ) ;
return - V_71 ;
}
F_2 ( V_27 , V_4 ) ;
F_12 ( & V_2 -> V_30 , V_26 ) ;
return 0 ;
}
static int F_29 ( struct V_15 * V_16 , unsigned V_46 ,
unsigned long * V_84 , unsigned V_85 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
enum V_64 V_65 ;
int V_41 , V_86 ;
T_3 V_66 ;
if ( F_5 ( V_2 , V_46 ) )
return - V_43 ;
for ( V_41 = 0 ; V_41 < V_85 ; V_41 ++ ) {
V_65 = F_26 ( V_84 [ V_41 ] ) ;
V_66 = F_30 ( V_84 [ V_41 ] ) ;
switch ( V_65 ) {
case V_70 :
case V_72 :
case V_77 :
V_86 = F_28 ( V_2 , V_46 , V_65 , V_66 ) ;
if ( V_86 )
return V_86 ;
break;
default:
return - V_82 ;
}
F_20 ( V_2 -> V_42 , L_9 , V_46 ,
V_65 , V_66 ) ;
}
return 0 ;
}
static unsigned F_31 ( struct V_1 * V_2 ,
unsigned V_3 )
{
return V_2 -> V_17 -> V_22 [ V_3 ] . V_87 ;
}
static int F_32 ( struct V_88 * V_89 , unsigned V_3 )
{
struct V_1 * V_2 = F_33 ( V_89 ) ;
int V_46 = F_31 ( V_2 , V_3 ) ;
unsigned long V_26 ;
T_2 V_27 , V_81 ;
F_11 ( & V_2 -> V_30 , V_26 ) ;
V_27 = F_4 ( F_1 ( V_2 , V_46 , V_31 ) ) ;
F_12 ( & V_2 -> V_30 , V_26 ) ;
V_81 = V_27 & V_57 ;
V_81 >>= V_59 ;
if ( V_81 == V_62 )
return ! ! ( V_27 & V_90 ) ;
return ! ! ( V_27 & V_91 ) ;
}
static void F_34 ( struct V_88 * V_89 , unsigned V_3 , int V_12 )
{
struct V_1 * V_2 = F_33 ( V_89 ) ;
unsigned V_46 = F_31 ( V_2 , V_3 ) ;
unsigned long V_26 ;
void T_1 * V_4 ;
T_2 V_27 ;
F_11 ( & V_2 -> V_30 , V_26 ) ;
V_4 = F_1 ( V_2 , V_46 , V_31 ) ;
V_27 = F_4 ( V_4 ) ;
if ( V_12 )
V_27 |= V_90 ;
else
V_27 &= ~ V_90 ;
F_2 ( V_27 , V_4 ) ;
F_12 ( & V_2 -> V_30 , V_26 ) ;
}
static int F_35 ( struct V_88 * V_89 , unsigned V_3 )
{
struct V_1 * V_2 = F_33 ( V_89 ) ;
unsigned V_46 = F_31 ( V_2 , V_3 ) ;
T_2 V_27 , V_92 ;
unsigned long V_26 ;
F_11 ( & V_2 -> V_30 , V_26 ) ;
V_27 = F_4 ( F_1 ( V_2 , V_46 , V_31 ) ) ;
F_12 ( & V_2 -> V_30 , V_26 ) ;
V_92 = V_27 & V_57 ;
V_92 >>= V_59 ;
return V_92 != V_62 ;
}
static int F_36 ( struct V_88 * V_89 , unsigned V_3 )
{
return F_37 ( V_89 -> V_93 + V_3 ) ;
}
static int F_38 ( struct V_88 * V_89 , unsigned V_3 ,
int V_12 )
{
F_34 ( V_89 , V_3 , V_12 ) ;
return F_39 ( V_89 -> V_93 + V_3 ) ;
}
static void F_40 ( struct V_94 * V_95 )
{
struct V_88 * V_96 = F_41 ( V_95 ) ;
struct V_1 * V_2 = F_33 ( V_96 ) ;
int V_46 = F_31 ( V_2 , F_42 ( V_95 ) ) ;
T_2 V_97 ;
F_43 ( & V_2 -> V_30 ) ;
V_97 = F_4 ( F_1 ( V_2 , V_46 , V_31 ) ) ;
V_97 &= V_98 ;
V_97 >>= V_99 ;
F_2 ( F_44 ( V_97 ) , V_2 -> V_11 + V_100 ) ;
F_45 ( & V_2 -> V_30 ) ;
}
static void F_46 ( struct V_94 * V_95 , bool V_101 )
{
struct V_88 * V_96 = F_41 ( V_95 ) ;
struct V_1 * V_2 = F_33 ( V_96 ) ;
int V_46 = F_31 ( V_2 , F_42 ( V_95 ) ) ;
T_2 V_12 , V_97 ;
unsigned long V_26 ;
F_11 ( & V_2 -> V_30 , V_26 ) ;
V_97 = F_4 ( F_1 ( V_2 , V_46 , V_31 ) ) ;
V_97 &= V_98 ;
V_97 >>= V_99 ;
V_12 = F_4 ( V_2 -> V_11 + V_102 ) ;
if ( V_101 )
V_12 &= ~ F_44 ( V_97 ) ;
else
V_12 |= F_44 ( V_97 ) ;
F_2 ( V_12 , V_2 -> V_11 + V_102 ) ;
F_12 ( & V_2 -> V_30 , V_26 ) ;
}
static void F_47 ( struct V_94 * V_95 )
{
F_46 ( V_95 , true ) ;
}
static void F_48 ( struct V_94 * V_95 )
{
F_46 ( V_95 , false ) ;
}
static unsigned F_49 ( struct V_94 * V_95 )
{
if ( F_50 ( V_95 ) == V_103 ) {
struct V_88 * V_96 = F_41 ( V_95 ) ;
struct V_1 * V_2 = F_33 ( V_96 ) ;
unsigned V_3 = F_42 ( V_95 ) ;
int V_46 = F_31 ( V_2 , V_3 ) ;
T_4 V_104 ;
unsigned long V_26 ;
T_2 V_105 , V_12 ;
F_11 ( & V_2 -> V_30 , V_26 ) ;
V_105 = F_4 ( F_1 ( V_2 , V_46 , V_31 ) ) ;
V_105 &= V_98 ;
V_105 >>= V_99 ;
V_12 = F_4 ( F_1 ( V_2 , V_46 , V_13 ) ) ;
if ( V_12 & V_106 )
V_104 = V_107 ;
else
V_104 = V_108 ;
if ( ! V_2 -> V_55 [ V_105 ] ) {
F_51 ( V_95 , V_104 ) ;
V_2 -> V_55 [ V_105 ] = V_3 ;
}
F_12 ( & V_2 -> V_30 , V_26 ) ;
}
F_48 ( V_95 ) ;
return 0 ;
}
static int F_52 ( struct V_94 * V_95 , unsigned type )
{
struct V_88 * V_96 = F_41 ( V_95 ) ;
struct V_1 * V_2 = F_33 ( V_96 ) ;
unsigned V_3 = F_42 ( V_95 ) ;
int V_46 = F_31 ( V_2 , V_3 ) ;
unsigned long V_26 ;
T_2 V_12 ;
F_11 ( & V_2 -> V_30 , V_26 ) ;
if ( ! F_5 ( V_2 , V_46 ) ) {
void T_1 * V_4 = F_1 ( V_2 , V_46 , V_13 ) ;
V_12 = F_4 ( V_4 ) ;
V_12 &= ~ V_56 ;
V_12 &= ~ V_50 ;
if ( type & V_109 ) {
if ( ( type & V_109 ) == V_109 )
V_12 |= V_110 ;
else if ( type & V_111 )
V_12 |= V_112 ;
else if ( type & V_113 )
V_12 |= V_114 ;
} else if ( type & V_115 ) {
V_12 |= V_106 ;
if ( type & V_116 )
V_12 |= V_117 ;
}
F_2 ( V_12 , V_4 ) ;
}
V_12 = F_4 ( F_1 ( V_2 , V_46 , V_31 ) ) ;
V_12 &= V_98 ;
V_12 >>= V_99 ;
V_2 -> V_55 [ V_12 ] = V_3 ;
if ( type & V_109 )
F_51 ( V_95 , V_108 ) ;
else if ( type & V_115 )
F_51 ( V_95 , V_107 ) ;
F_12 ( & V_2 -> V_30 , V_26 ) ;
return 0 ;
}
static void F_53 ( struct V_118 * V_119 )
{
struct V_88 * V_96 = F_54 ( V_119 ) ;
struct V_1 * V_2 = F_33 ( V_96 ) ;
struct V_120 * V_89 = F_55 ( V_119 ) ;
unsigned long V_121 ;
T_2 V_97 ;
F_56 ( V_89 , V_119 ) ;
V_121 = F_4 ( V_2 -> V_11 + V_100 ) ;
F_57 (intr_line, &pending, 16 ) {
unsigned V_122 , V_3 ;
V_3 = V_2 -> V_55 [ V_97 ] ;
V_122 = F_58 ( V_96 -> V_123 , V_3 ) ;
F_59 ( V_122 ) ;
}
F_60 ( V_89 , V_119 ) ;
}
static int F_61 ( struct V_1 * V_2 , int V_122 )
{
const struct V_124 * V_54 ;
struct V_88 * V_89 = & V_2 -> V_89 ;
int V_86 , V_41 , V_3 ;
* V_89 = V_125 ;
V_89 -> V_126 = V_2 -> V_17 -> V_127 ;
V_89 -> V_128 = F_62 ( V_2 -> V_42 ) ;
V_89 -> V_129 = V_2 -> V_42 ;
V_89 -> V_93 = - 1 ;
V_86 = F_63 ( V_89 , V_2 ) ;
if ( V_86 ) {
F_64 ( V_2 -> V_42 , L_10 ) ;
return V_86 ;
}
for ( V_41 = 0 , V_3 = 0 ; V_41 < V_2 -> V_17 -> V_130 ; V_41 ++ ) {
V_54 = & V_2 -> V_17 -> V_131 [ V_41 ] ;
V_86 = F_65 ( V_89 , F_62 ( V_2 -> V_42 ) , V_3 ,
V_54 -> V_93 , V_54 -> V_23 ) ;
if ( V_86 ) {
F_64 ( V_2 -> V_42 , L_11 ) ;
goto V_132;
}
V_3 += V_54 -> V_23 ;
}
F_2 ( 0 , V_2 -> V_11 + V_102 ) ;
F_2 ( 0xffff , V_2 -> V_11 + V_100 ) ;
V_86 = F_66 ( V_89 , & V_133 , 0 ,
V_134 , V_103 ) ;
if ( V_86 ) {
F_64 ( V_2 -> V_42 , L_12 ) ;
goto V_132;
}
F_67 ( V_89 , & V_133 , V_122 ,
F_53 ) ;
return 0 ;
V_132:
F_68 ( V_89 ) ;
return V_86 ;
}
static int F_69 ( struct V_135 * V_136 )
{
struct V_1 * V_2 ;
struct V_137 * V_138 ;
struct V_139 * V_140 ;
int V_86 , V_122 , V_41 ;
V_138 = F_70 ( & V_136 -> V_42 ) ;
if ( ! V_138 )
return - V_141 ;
V_2 = F_71 ( & V_136 -> V_42 , sizeof( * V_2 ) , V_142 ) ;
if ( ! V_2 )
return - V_143 ;
for ( V_41 = 0 ; V_41 < F_22 ( V_144 ) ; V_41 ++ )
if ( ! strcmp ( V_138 -> V_145 . V_146 , V_144 [ V_41 ] -> V_147 ) ) {
V_2 -> V_17 = V_144 [ V_41 ] ;
break;
}
if ( V_41 == F_22 ( V_144 ) )
return - V_141 ;
F_72 ( & V_2 -> V_30 ) ;
V_2 -> V_42 = & V_136 -> V_42 ;
#ifdef F_73
V_2 -> V_148 = F_74 ( V_2 -> V_42 ,
V_2 -> V_17 -> V_23 , sizeof( * V_2 -> V_148 ) ,
V_142 ) ;
if ( ! V_2 -> V_148 )
return - V_143 ;
#endif
V_140 = F_75 ( V_136 , V_149 , 0 ) ;
V_2 -> V_11 = F_76 ( & V_136 -> V_42 , V_140 ) ;
if ( F_77 ( V_2 -> V_11 ) )
return F_78 ( V_2 -> V_11 ) ;
V_122 = F_79 ( V_136 , 0 ) ;
if ( V_122 < 0 ) {
F_64 ( & V_136 -> V_42 , L_13 ) ;
return V_122 ;
}
V_2 -> V_150 = V_151 ;
V_2 -> V_150 . V_21 = F_62 ( & V_136 -> V_42 ) ;
V_2 -> V_150 . V_22 = V_2 -> V_17 -> V_22 ;
V_2 -> V_150 . V_23 = V_2 -> V_17 -> V_23 ;
V_2 -> V_16 = F_80 ( & V_2 -> V_150 , & V_136 -> V_42 , V_2 ) ;
if ( F_77 ( V_2 -> V_16 ) ) {
F_64 ( & V_136 -> V_42 , L_14 ) ;
return F_78 ( V_2 -> V_16 ) ;
}
V_86 = F_61 ( V_2 , V_122 ) ;
if ( V_86 ) {
F_81 ( V_2 -> V_16 ) ;
return V_86 ;
}
F_82 ( V_136 , V_2 ) ;
return 0 ;
}
static int F_83 ( struct V_135 * V_136 )
{
struct V_1 * V_2 = F_84 ( V_136 ) ;
F_68 ( & V_2 -> V_89 ) ;
F_81 ( V_2 -> V_16 ) ;
return 0 ;
}
static int F_85 ( struct V_152 * V_42 )
{
struct V_135 * V_136 = F_86 ( V_42 ) ;
struct V_1 * V_2 = F_84 ( V_136 ) ;
int V_41 ;
V_2 -> V_153 = F_4 ( V_2 -> V_11 + V_102 ) ;
for ( V_41 = 0 ; V_41 < V_2 -> V_17 -> V_23 ; V_41 ++ ) {
const struct V_154 * V_119 ;
struct V_155 * V_156 ;
void T_1 * V_4 ;
V_119 = & V_2 -> V_17 -> V_22 [ V_41 ] ;
if ( F_5 ( V_2 , V_119 -> V_87 ) )
continue;
V_156 = & V_2 -> V_148 [ V_41 ] ;
V_4 = F_1 ( V_2 , V_119 -> V_87 , V_31 ) ;
V_156 -> V_157 = F_4 ( V_4 ) & ~ V_91 ;
V_4 = F_1 ( V_2 , V_119 -> V_87 , V_13 ) ;
V_156 -> V_158 = F_4 ( V_4 ) ;
}
return 0 ;
}
static int F_87 ( struct V_152 * V_42 )
{
struct V_135 * V_136 = F_86 ( V_42 ) ;
struct V_1 * V_2 = F_84 ( V_136 ) ;
int V_41 ;
F_2 ( 0 , V_2 -> V_11 + V_102 ) ;
for ( V_41 = 0 ; V_41 < V_2 -> V_17 -> V_23 ; V_41 ++ ) {
const struct V_154 * V_119 ;
const struct V_155 * V_156 ;
void T_1 * V_4 ;
T_2 V_159 ;
V_119 = & V_2 -> V_17 -> V_22 [ V_41 ] ;
if ( F_5 ( V_2 , V_119 -> V_87 ) )
continue;
V_156 = & V_2 -> V_148 [ V_41 ] ;
V_4 = F_1 ( V_2 , V_119 -> V_87 , V_31 ) ;
V_159 = F_4 ( V_4 ) & ~ V_91 ;
if ( V_156 -> V_157 != V_159 ) {
F_2 ( V_156 -> V_157 , V_4 ) ;
F_20 ( V_2 -> V_42 , L_15 ,
V_119 -> V_87 , F_4 ( V_4 ) ) ;
}
V_4 = F_1 ( V_2 , V_119 -> V_87 , V_13 ) ;
V_159 = F_4 ( V_4 ) ;
if ( V_156 -> V_158 != V_159 ) {
F_2 ( V_156 -> V_158 , V_4 ) ;
F_20 ( V_2 -> V_42 , L_16 ,
V_119 -> V_87 , F_4 ( V_4 ) ) ;
}
}
F_2 ( 0xffff , V_2 -> V_11 + V_100 ) ;
F_2 ( V_2 -> V_153 , V_2 -> V_11 + V_102 ) ;
return 0 ;
}
static int T_5 F_88 ( void )
{
return F_89 ( & V_160 ) ;
}
static void T_6 F_90 ( void )
{
F_91 ( & V_160 ) ;
}

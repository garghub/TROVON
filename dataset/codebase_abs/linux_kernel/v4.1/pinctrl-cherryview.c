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
static int F_31 ( struct V_87 * V_88 , unsigned V_3 )
{
return F_32 ( V_88 -> V_89 + V_3 ) ;
}
static void F_33 ( struct V_87 * V_88 , unsigned V_3 )
{
F_34 ( V_88 -> V_89 + V_3 ) ;
}
static unsigned F_35 ( struct V_1 * V_2 ,
unsigned V_3 )
{
return V_2 -> V_17 -> V_22 [ V_3 ] . V_90 ;
}
static int F_36 ( struct V_87 * V_88 , unsigned V_3 )
{
struct V_1 * V_2 = F_37 ( V_88 ) ;
int V_46 = F_35 ( V_2 , V_3 ) ;
T_2 V_27 , V_81 ;
V_27 = F_4 ( F_1 ( V_2 , V_46 , V_31 ) ) ;
V_81 = V_27 & V_57 ;
V_81 >>= V_59 ;
if ( V_81 == V_62 )
return ! ! ( V_27 & V_91 ) ;
return ! ! ( V_27 & V_92 ) ;
}
static void F_38 ( struct V_87 * V_88 , unsigned V_3 , int V_12 )
{
struct V_1 * V_2 = F_37 ( V_88 ) ;
unsigned V_46 = F_35 ( V_2 , V_3 ) ;
unsigned long V_26 ;
void T_1 * V_4 ;
T_2 V_27 ;
F_11 ( & V_2 -> V_30 , V_26 ) ;
V_4 = F_1 ( V_2 , V_46 , V_31 ) ;
V_27 = F_4 ( V_4 ) ;
if ( V_12 )
V_27 |= V_91 ;
else
V_27 &= ~ V_91 ;
F_2 ( V_27 , V_4 ) ;
F_12 ( & V_2 -> V_30 , V_26 ) ;
}
static int F_39 ( struct V_87 * V_88 , unsigned V_3 )
{
struct V_1 * V_2 = F_37 ( V_88 ) ;
unsigned V_46 = F_35 ( V_2 , V_3 ) ;
T_2 V_27 , V_93 ;
V_27 = F_4 ( F_1 ( V_2 , V_46 , V_31 ) ) ;
V_93 = V_27 & V_57 ;
V_93 >>= V_59 ;
return V_93 != V_62 ;
}
static int F_40 ( struct V_87 * V_88 , unsigned V_3 )
{
return F_41 ( V_88 -> V_89 + V_3 ) ;
}
static int F_42 ( struct V_87 * V_88 , unsigned V_3 ,
int V_12 )
{
F_38 ( V_88 , V_3 , V_12 ) ;
return F_43 ( V_88 -> V_89 + V_3 ) ;
}
static void F_44 ( struct V_94 * V_95 )
{
struct V_87 * V_96 = F_45 ( V_95 ) ;
struct V_1 * V_2 = F_37 ( V_96 ) ;
int V_46 = F_35 ( V_2 , F_46 ( V_95 ) ) ;
T_2 V_97 ;
F_47 ( & V_2 -> V_30 ) ;
V_97 = F_4 ( F_1 ( V_2 , V_46 , V_31 ) ) ;
V_97 &= V_98 ;
V_97 >>= V_99 ;
F_2 ( F_48 ( V_97 ) , V_2 -> V_11 + V_100 ) ;
F_49 ( & V_2 -> V_30 ) ;
}
static void F_50 ( struct V_94 * V_95 , bool V_101 )
{
struct V_87 * V_96 = F_45 ( V_95 ) ;
struct V_1 * V_2 = F_37 ( V_96 ) ;
int V_46 = F_35 ( V_2 , F_46 ( V_95 ) ) ;
T_2 V_12 , V_97 ;
unsigned long V_26 ;
F_11 ( & V_2 -> V_30 , V_26 ) ;
V_97 = F_4 ( F_1 ( V_2 , V_46 , V_31 ) ) ;
V_97 &= V_98 ;
V_97 >>= V_99 ;
V_12 = F_4 ( V_2 -> V_11 + V_102 ) ;
if ( V_101 )
V_12 &= ~ F_48 ( V_97 ) ;
else
V_12 |= F_48 ( V_97 ) ;
F_2 ( V_12 , V_2 -> V_11 + V_102 ) ;
F_12 ( & V_2 -> V_30 , V_26 ) ;
}
static void F_51 ( struct V_94 * V_95 )
{
F_50 ( V_95 , true ) ;
}
static void F_52 ( struct V_94 * V_95 )
{
F_50 ( V_95 , false ) ;
}
static unsigned F_53 ( struct V_94 * V_95 )
{
if ( F_54 ( V_95 ) == V_103 ) {
struct V_87 * V_96 = F_45 ( V_95 ) ;
struct V_1 * V_2 = F_37 ( V_96 ) ;
unsigned V_3 = F_46 ( V_95 ) ;
int V_46 = F_35 ( V_2 , V_3 ) ;
T_4 V_104 ;
unsigned long V_26 ;
T_2 V_105 , V_12 ;
V_105 = F_4 ( F_1 ( V_2 , V_46 , V_31 ) ) ;
V_105 &= V_98 ;
V_105 >>= V_99 ;
V_12 = F_4 ( F_1 ( V_2 , V_46 , V_13 ) ) ;
if ( V_12 & V_106 )
V_104 = V_107 ;
else
V_104 = V_108 ;
F_11 ( & V_2 -> V_30 , V_26 ) ;
if ( ! V_2 -> V_55 [ V_105 ] ) {
F_55 ( V_95 -> V_109 , V_104 ) ;
V_2 -> V_55 [ V_105 ] = V_3 ;
}
F_12 ( & V_2 -> V_30 , V_26 ) ;
}
F_52 ( V_95 ) ;
return 0 ;
}
static int F_56 ( struct V_94 * V_95 , unsigned type )
{
struct V_87 * V_96 = F_45 ( V_95 ) ;
struct V_1 * V_2 = F_37 ( V_96 ) ;
unsigned V_3 = F_46 ( V_95 ) ;
int V_46 = F_35 ( V_2 , V_3 ) ;
unsigned long V_26 ;
T_2 V_12 ;
F_11 ( & V_2 -> V_30 , V_26 ) ;
if ( ! F_5 ( V_2 , V_46 ) ) {
void T_1 * V_4 = F_1 ( V_2 , V_46 , V_13 ) ;
V_12 = F_4 ( V_4 ) ;
V_12 &= ~ V_56 ;
V_12 &= ~ V_50 ;
if ( type & V_110 ) {
if ( ( type & V_110 ) == V_110 )
V_12 |= V_111 ;
else if ( type & V_112 )
V_12 |= V_113 ;
else if ( type & V_114 )
V_12 |= V_115 ;
} else if ( type & V_116 ) {
V_12 |= V_106 ;
if ( type & V_117 )
V_12 |= V_118 ;
}
F_2 ( V_12 , V_4 ) ;
}
V_12 = F_4 ( F_1 ( V_2 , V_46 , V_31 ) ) ;
V_12 &= V_98 ;
V_12 >>= V_99 ;
V_2 -> V_55 [ V_12 ] = V_3 ;
if ( type & V_110 )
F_55 ( V_95 -> V_109 , V_108 ) ;
else if ( type & V_116 )
F_55 ( V_95 -> V_109 , V_107 ) ;
F_12 ( & V_2 -> V_30 , V_26 ) ;
return 0 ;
}
static void F_57 ( unsigned V_109 , struct V_119 * V_120 )
{
struct V_87 * V_96 = F_58 ( V_120 ) ;
struct V_1 * V_2 = F_37 ( V_96 ) ;
struct V_121 * V_88 = F_59 ( V_109 ) ;
unsigned long V_122 ;
T_2 V_97 ;
F_60 ( V_88 , V_120 ) ;
V_122 = F_4 ( V_2 -> V_11 + V_100 ) ;
F_61 (intr_line, &pending, 16 ) {
unsigned V_109 , V_3 ;
V_3 = V_2 -> V_55 [ V_97 ] ;
V_109 = F_62 ( V_96 -> V_123 , V_3 ) ;
F_63 ( V_109 ) ;
}
F_64 ( V_88 , V_120 ) ;
}
static int F_65 ( struct V_1 * V_2 , int V_109 )
{
const struct V_124 * V_54 ;
struct V_87 * V_88 = & V_2 -> V_88 ;
int V_86 , V_41 , V_3 ;
* V_88 = V_125 ;
V_88 -> V_126 = V_2 -> V_17 -> V_127 ;
V_88 -> V_128 = F_66 ( V_2 -> V_42 ) ;
V_88 -> V_42 = V_2 -> V_42 ;
V_88 -> V_89 = - 1 ;
V_86 = F_67 ( V_88 ) ;
if ( V_86 ) {
F_68 ( V_2 -> V_42 , L_10 ) ;
return V_86 ;
}
for ( V_41 = 0 , V_3 = 0 ; V_41 < V_2 -> V_17 -> V_129 ; V_41 ++ ) {
V_54 = & V_2 -> V_17 -> V_130 [ V_41 ] ;
V_86 = F_69 ( V_88 , F_66 ( V_2 -> V_42 ) , V_3 ,
V_54 -> V_89 , V_54 -> V_23 ) ;
if ( V_86 ) {
F_68 ( V_2 -> V_42 , L_11 ) ;
goto V_131;
}
V_3 += V_54 -> V_23 ;
}
F_2 ( 0 , V_2 -> V_11 + V_102 ) ;
F_2 ( 0xffff , V_2 -> V_11 + V_100 ) ;
V_86 = F_70 ( V_88 , & V_132 , 0 ,
V_133 , V_103 ) ;
if ( V_86 ) {
F_68 ( V_2 -> V_42 , L_12 ) ;
goto V_131;
}
F_71 ( V_88 , & V_132 , V_109 ,
F_57 ) ;
return 0 ;
V_131:
F_72 ( V_88 ) ;
return V_86 ;
}
static int F_73 ( struct V_134 * V_135 )
{
struct V_1 * V_2 ;
struct V_136 * V_137 ;
struct V_138 * V_139 ;
int V_86 , V_109 , V_41 ;
V_137 = F_74 ( & V_135 -> V_42 ) ;
if ( ! V_137 )
return - V_140 ;
V_2 = F_75 ( & V_135 -> V_42 , sizeof( * V_2 ) , V_141 ) ;
if ( ! V_2 )
return - V_142 ;
for ( V_41 = 0 ; V_41 < F_22 ( V_143 ) ; V_41 ++ )
if ( ! strcmp ( V_137 -> V_144 . V_145 , V_143 [ V_41 ] -> V_146 ) ) {
V_2 -> V_17 = V_143 [ V_41 ] ;
break;
}
if ( V_41 == F_22 ( V_143 ) )
return - V_140 ;
F_76 ( & V_2 -> V_30 ) ;
V_2 -> V_42 = & V_135 -> V_42 ;
#ifdef F_77
V_2 -> V_147 = F_78 ( V_2 -> V_42 ,
V_2 -> V_17 -> V_23 , sizeof( * V_2 -> V_147 ) ,
V_141 ) ;
if ( ! V_2 -> V_147 )
return - V_142 ;
#endif
V_139 = F_79 ( V_135 , V_148 , 0 ) ;
V_2 -> V_11 = F_80 ( & V_135 -> V_42 , V_139 ) ;
if ( F_81 ( V_2 -> V_11 ) )
return F_82 ( V_2 -> V_11 ) ;
V_109 = F_83 ( V_135 , 0 ) ;
if ( V_109 < 0 ) {
F_68 ( & V_135 -> V_42 , L_13 ) ;
return V_109 ;
}
V_2 -> V_149 = V_150 ;
V_2 -> V_149 . V_21 = F_66 ( & V_135 -> V_42 ) ;
V_2 -> V_149 . V_22 = V_2 -> V_17 -> V_22 ;
V_2 -> V_149 . V_23 = V_2 -> V_17 -> V_23 ;
V_2 -> V_16 = F_84 ( & V_2 -> V_149 , & V_135 -> V_42 , V_2 ) ;
if ( ! V_2 -> V_16 ) {
F_68 ( & V_135 -> V_42 , L_14 ) ;
return - V_140 ;
}
V_86 = F_65 ( V_2 , V_109 ) ;
if ( V_86 ) {
F_85 ( V_2 -> V_16 ) ;
return V_86 ;
}
F_86 ( V_135 , V_2 ) ;
return 0 ;
}
static int F_87 ( struct V_134 * V_135 )
{
struct V_1 * V_2 = F_88 ( V_135 ) ;
F_72 ( & V_2 -> V_88 ) ;
F_85 ( V_2 -> V_16 ) ;
return 0 ;
}
static int F_89 ( struct V_151 * V_42 )
{
struct V_134 * V_135 = F_90 ( V_42 ) ;
struct V_1 * V_2 = F_88 ( V_135 ) ;
int V_41 ;
V_2 -> V_152 = F_4 ( V_2 -> V_11 + V_102 ) ;
for ( V_41 = 0 ; V_41 < V_2 -> V_17 -> V_23 ; V_41 ++ ) {
const struct V_153 * V_120 ;
struct V_154 * V_155 ;
void T_1 * V_4 ;
V_120 = & V_2 -> V_17 -> V_22 [ V_41 ] ;
if ( F_5 ( V_2 , V_120 -> V_90 ) )
continue;
V_155 = & V_2 -> V_147 [ V_41 ] ;
V_4 = F_1 ( V_2 , V_120 -> V_90 , V_31 ) ;
V_155 -> V_156 = F_4 ( V_4 ) & ~ V_92 ;
V_4 = F_1 ( V_2 , V_120 -> V_90 , V_13 ) ;
V_155 -> V_157 = F_4 ( V_4 ) ;
}
return 0 ;
}
static int F_91 ( struct V_151 * V_42 )
{
struct V_134 * V_135 = F_90 ( V_42 ) ;
struct V_1 * V_2 = F_88 ( V_135 ) ;
int V_41 ;
F_2 ( 0 , V_2 -> V_11 + V_102 ) ;
for ( V_41 = 0 ; V_41 < V_2 -> V_17 -> V_23 ; V_41 ++ ) {
const struct V_153 * V_120 ;
const struct V_154 * V_155 ;
void T_1 * V_4 ;
T_2 V_158 ;
V_120 = & V_2 -> V_17 -> V_22 [ V_41 ] ;
if ( F_5 ( V_2 , V_120 -> V_90 ) )
continue;
V_155 = & V_2 -> V_147 [ V_41 ] ;
V_4 = F_1 ( V_2 , V_120 -> V_90 , V_31 ) ;
V_158 = F_4 ( V_4 ) & ~ V_92 ;
if ( V_155 -> V_156 != V_158 ) {
F_2 ( V_155 -> V_156 , V_4 ) ;
F_20 ( V_2 -> V_42 , L_15 ,
V_120 -> V_90 , F_4 ( V_4 ) ) ;
}
V_4 = F_1 ( V_2 , V_120 -> V_90 , V_13 ) ;
V_158 = F_4 ( V_4 ) ;
if ( V_155 -> V_157 != V_158 ) {
F_2 ( V_155 -> V_157 , V_4 ) ;
F_20 ( V_2 -> V_42 , L_16 ,
V_120 -> V_90 , F_4 ( V_4 ) ) ;
}
}
F_2 ( 0xffff , V_2 -> V_11 + V_100 ) ;
F_2 ( V_2 -> V_152 , V_2 -> V_11 + V_102 ) ;
return 0 ;
}
static int T_5 F_92 ( void )
{
return F_93 ( & V_159 ) ;
}
static void T_6 F_94 ( void )
{
F_95 ( & V_159 ) ;
}

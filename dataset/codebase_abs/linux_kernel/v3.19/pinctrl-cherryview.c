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
V_12 = F_4 ( V_4 ) | V_32 ;
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
unsigned V_3 , bool V_57 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
void T_1 * V_4 = F_1 ( V_2 , V_3 , V_31 ) ;
unsigned long V_26 ;
T_2 V_27 ;
F_11 ( & V_2 -> V_30 , V_26 ) ;
V_27 = F_4 ( V_4 ) & ~ V_58 ;
if ( V_57 )
V_27 |= V_59 << V_60 ;
else
V_27 |= V_61 << V_60 ;
F_2 ( V_27 , V_4 ) ;
F_12 ( & V_2 -> V_30 , V_26 ) ;
return 0 ;
}
static int F_25 ( struct V_15 * V_16 , unsigned V_46 ,
unsigned long * V_62 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
enum V_63 V_64 = F_26 ( * V_62 ) ;
unsigned long V_26 ;
T_2 V_27 , V_28 ;
T_3 V_65 = 0 ;
T_2 V_66 ;
F_11 ( & V_2 -> V_30 , V_26 ) ;
V_27 = F_4 ( F_1 ( V_2 , V_46 , V_31 ) ) ;
V_28 = F_4 ( F_1 ( V_2 , V_46 , V_13 ) ) ;
F_12 ( & V_2 -> V_30 , V_26 ) ;
V_66 = ( V_27 & V_67 ) >> V_68 ;
switch ( V_64 ) {
case V_69 :
if ( V_66 )
return - V_70 ;
break;
case V_71 :
if ( ! ( V_27 & V_72 ) )
return - V_70 ;
switch ( V_66 ) {
case V_73 :
V_65 = 20000 ;
break;
case V_74 :
V_65 = 5000 ;
break;
case V_75 :
V_65 = 1000 ;
break;
}
break;
case V_76 :
if ( ! V_66 || ( V_27 & V_72 ) )
return - V_70 ;
switch ( V_66 ) {
case V_73 :
V_65 = 20000 ;
break;
case V_74 :
V_65 = 5000 ;
break;
}
break;
case V_77 :
if ( ! ( V_28 & V_78 ) )
return - V_70 ;
break;
case V_79 : {
T_2 V_80 ;
V_80 = V_27 & V_58 ;
V_80 >>= V_60 ;
if ( V_80 != V_81 )
return - V_70 ;
break;
}
default:
return - V_82 ;
}
* V_62 = F_27 ( V_64 , V_65 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , unsigned V_46 ,
enum V_63 V_64 , T_3 V_65 )
{
void T_1 * V_4 = F_1 ( V_2 , V_46 , V_31 ) ;
unsigned long V_26 ;
T_2 V_27 , V_83 ;
F_11 ( & V_2 -> V_30 , V_26 ) ;
V_27 = F_4 ( V_4 ) ;
switch ( V_64 ) {
case V_69 :
V_27 &= ~ ( V_67 | V_72 ) ;
break;
case V_71 :
V_27 &= ~ ( V_67 | V_72 ) ;
switch ( V_65 ) {
case 1000 :
V_83 = V_75 << V_68 ;
break;
case 5000 :
V_83 = V_74 << V_68 ;
break;
case 20000 :
V_83 = V_73 << V_68 ;
break;
default:
F_12 ( & V_2 -> V_30 , V_26 ) ;
return - V_70 ;
}
V_27 |= V_72 | V_83 ;
break;
case V_76 :
V_27 &= ~ ( V_67 | V_72 ) ;
switch ( V_65 ) {
case 5000 :
V_83 = V_74 << V_68 ;
break;
case 20000 :
V_83 = V_73 << V_68 ;
break;
default:
F_12 ( & V_2 -> V_30 , V_26 ) ;
return - V_70 ;
}
V_27 |= V_83 ;
break;
default:
F_12 ( & V_2 -> V_30 , V_26 ) ;
return - V_70 ;
}
F_2 ( V_27 , V_4 ) ;
F_12 ( & V_2 -> V_30 , V_26 ) ;
return 0 ;
}
static int F_29 ( struct V_15 * V_16 , unsigned V_46 ,
unsigned long * V_84 , unsigned V_85 )
{
struct V_1 * V_2 = F_7 ( V_16 ) ;
enum V_63 V_64 ;
int V_41 , V_86 ;
T_3 V_65 ;
if ( F_5 ( V_2 , V_46 ) )
return - V_43 ;
for ( V_41 = 0 ; V_41 < V_85 ; V_41 ++ ) {
V_64 = F_26 ( V_84 [ V_41 ] ) ;
V_65 = F_30 ( V_84 [ V_41 ] ) ;
switch ( V_64 ) {
case V_69 :
case V_71 :
case V_76 :
V_86 = F_28 ( V_2 , V_46 , V_64 , V_65 ) ;
if ( V_86 )
return V_86 ;
break;
default:
return - V_82 ;
}
F_20 ( V_2 -> V_42 , L_9 , V_46 ,
V_64 , V_65 ) ;
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
T_2 V_27 , V_80 ;
V_27 = F_4 ( F_1 ( V_2 , V_46 , V_31 ) ) ;
V_80 = V_27 & V_58 ;
V_80 >>= V_60 ;
if ( V_80 == V_61 )
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
V_93 = V_27 & V_58 ;
V_93 >>= V_60 ;
return V_93 != V_61 ;
}
static int F_40 ( struct V_87 * V_88 , unsigned V_3 )
{
return F_41 ( V_88 -> V_89 + V_3 ) ;
}
static int F_42 ( struct V_87 * V_88 , unsigned V_3 ,
int V_12 )
{
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
static int F_53 ( struct V_94 * V_95 , unsigned type )
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
if ( type & V_103 ) {
if ( ( type & V_103 ) == V_103 )
V_12 |= V_104 ;
else if ( type & V_105 )
V_12 |= V_106 ;
else if ( type & V_107 )
V_12 |= V_108 ;
} else if ( type & V_109 ) {
V_12 |= V_110 ;
if ( type & V_111 )
V_12 |= V_112 ;
}
F_2 ( V_12 , V_4 ) ;
}
V_12 = F_4 ( F_1 ( V_2 , V_46 , V_31 ) ) ;
V_12 &= V_98 ;
V_12 >>= V_99 ;
V_2 -> V_55 [ V_12 ] = V_3 ;
if ( type & V_103 )
F_54 ( V_95 -> V_113 , V_114 ) ;
else if ( type & V_109 )
F_54 ( V_95 -> V_113 , V_115 ) ;
F_12 ( & V_2 -> V_30 , V_26 ) ;
return 0 ;
}
static void F_55 ( unsigned V_113 , struct V_116 * V_117 )
{
struct V_87 * V_96 = F_56 ( V_117 ) ;
struct V_1 * V_2 = F_37 ( V_96 ) ;
struct V_118 * V_88 = F_57 ( V_113 ) ;
unsigned long V_119 ;
T_2 V_97 ;
F_58 ( V_88 , V_117 ) ;
V_119 = F_4 ( V_2 -> V_11 + V_100 ) ;
F_59 (intr_line, &pending, 16 ) {
unsigned V_113 , V_3 ;
V_3 = V_2 -> V_55 [ V_97 ] ;
V_113 = F_60 ( V_96 -> V_120 , V_3 ) ;
F_61 ( V_113 ) ;
}
F_62 ( V_88 , V_117 ) ;
}
static int F_63 ( struct V_1 * V_2 , int V_113 )
{
const struct V_121 * V_54 ;
struct V_87 * V_88 = & V_2 -> V_88 ;
int V_86 , V_41 , V_3 ;
* V_88 = V_122 ;
V_88 -> V_123 = V_2 -> V_17 -> V_124 ;
V_88 -> V_125 = F_64 ( V_2 -> V_42 ) ;
V_88 -> V_42 = V_2 -> V_42 ;
V_88 -> V_89 = - 1 ;
V_86 = F_65 ( V_88 ) ;
if ( V_86 ) {
F_66 ( V_2 -> V_42 , L_10 ) ;
return V_86 ;
}
for ( V_41 = 0 , V_3 = 0 ; V_41 < V_2 -> V_17 -> V_126 ; V_41 ++ ) {
V_54 = & V_2 -> V_17 -> V_127 [ V_41 ] ;
V_86 = F_67 ( V_88 , F_64 ( V_2 -> V_42 ) , V_3 ,
V_54 -> V_89 , V_54 -> V_23 ) ;
if ( V_86 ) {
F_66 ( V_2 -> V_42 , L_11 ) ;
goto V_128;
}
V_3 += V_54 -> V_23 ;
}
F_2 ( 0 , V_2 -> V_11 + V_102 ) ;
F_2 ( 0xffff , V_2 -> V_11 + V_100 ) ;
V_86 = F_68 ( V_88 , & V_129 , 0 ,
V_130 , V_131 ) ;
if ( V_86 ) {
F_66 ( V_2 -> V_42 , L_12 ) ;
goto V_128;
}
F_69 ( V_88 , & V_129 , V_113 ,
F_55 ) ;
return 0 ;
V_128:
F_70 ( V_88 ) ;
return V_86 ;
}
static int F_71 ( struct V_132 * V_133 )
{
struct V_1 * V_2 ;
struct V_134 * V_135 ;
struct V_136 * V_137 ;
int V_86 , V_113 , V_41 ;
V_135 = F_72 ( & V_133 -> V_42 ) ;
if ( ! V_135 )
return - V_138 ;
V_2 = F_73 ( & V_133 -> V_42 , sizeof( * V_2 ) , V_139 ) ;
if ( ! V_2 )
return - V_140 ;
for ( V_41 = 0 ; V_41 < F_22 ( V_141 ) ; V_41 ++ )
if ( ! strcmp ( V_135 -> V_142 . V_143 , V_141 [ V_41 ] -> V_144 ) ) {
V_2 -> V_17 = V_141 [ V_41 ] ;
break;
}
if ( V_41 == F_22 ( V_141 ) )
return - V_138 ;
F_74 ( & V_2 -> V_30 ) ;
V_2 -> V_42 = & V_133 -> V_42 ;
V_137 = F_75 ( V_133 , V_145 , 0 ) ;
V_2 -> V_11 = F_76 ( & V_133 -> V_42 , V_137 ) ;
if ( F_77 ( V_2 -> V_11 ) )
return F_78 ( V_2 -> V_11 ) ;
V_113 = F_79 ( V_133 , 0 ) ;
if ( V_113 < 0 ) {
F_66 ( & V_133 -> V_42 , L_13 ) ;
return V_113 ;
}
V_2 -> V_146 = V_147 ;
V_2 -> V_146 . V_21 = F_64 ( & V_133 -> V_42 ) ;
V_2 -> V_146 . V_22 = V_2 -> V_17 -> V_22 ;
V_2 -> V_146 . V_23 = V_2 -> V_17 -> V_23 ;
V_2 -> V_16 = F_80 ( & V_2 -> V_146 , & V_133 -> V_42 , V_2 ) ;
if ( ! V_2 -> V_16 ) {
F_66 ( & V_133 -> V_42 , L_14 ) ;
return - V_138 ;
}
V_86 = F_63 ( V_2 , V_113 ) ;
if ( V_86 ) {
F_81 ( V_2 -> V_16 ) ;
return V_86 ;
}
F_82 ( V_133 , V_2 ) ;
return 0 ;
}
static int F_83 ( struct V_132 * V_133 )
{
struct V_1 * V_2 = F_84 ( V_133 ) ;
F_70 ( & V_2 -> V_88 ) ;
F_81 ( V_2 -> V_16 ) ;
return 0 ;
}
static int T_4 F_85 ( void )
{
return F_86 ( & V_148 ) ;
}
static void T_5 F_87 ( void )
{
F_88 ( & V_148 ) ;
}

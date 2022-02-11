static struct V_1 * F_1 ( struct V_2 * V_3 ,
unsigned V_4 )
{
struct V_1 * V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ ) {
V_5 = & V_3 -> V_8 [ V_6 ] ;
if ( V_4 >= V_5 -> V_9 &&
V_4 < V_5 -> V_9 + V_5 -> V_10 )
return V_5 ;
}
F_2 ( V_3 -> V_11 , L_1 , V_4 ) ;
return NULL ;
}
static const struct V_12 *
F_3 ( const struct V_1 * V_5 ,
unsigned V_4 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_13 ; V_6 ++ ) {
const struct V_12 * V_14 = & V_5 -> V_15 [ V_6 ] ;
if ( V_4 >= V_14 -> V_16 && V_4 < V_14 -> V_16 + V_14 -> V_17 )
return V_14 ;
}
return NULL ;
}
static void T_1 * F_4 ( struct V_2 * V_3 , unsigned V_4 ,
unsigned V_18 )
{
const struct V_1 * V_5 ;
unsigned V_19 ;
T_2 V_20 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 )
return NULL ;
V_19 = F_5 ( V_5 , V_4 ) ;
V_20 = ( V_5 -> V_21 & V_22 ) ? 4 : 2 ;
if ( V_18 == V_23 && ! ( V_5 -> V_21 & V_22 ) )
return NULL ;
return V_5 -> V_24 + V_18 + V_19 * V_20 * 4 ;
}
static bool F_6 ( struct V_2 * V_3 , unsigned V_4 )
{
const struct V_1 * V_5 ;
const struct V_12 * V_14 ;
unsigned V_25 , V_26 , V_27 ;
void T_1 * V_28 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 )
return false ;
if ( ! V_5 -> V_29 )
return true ;
V_14 = F_3 ( V_5 , V_4 ) ;
if ( ! V_14 )
return false ;
V_27 = F_7 ( V_14 , V_4 ) ;
V_25 = F_8 ( V_27 ) ;
V_26 = V_5 -> V_29 + V_14 -> V_30 * 4 + V_25 * 4 ;
V_28 = V_5 -> V_31 + V_26 ;
return ! ( F_9 ( V_28 ) & F_10 ( V_27 ) ) ;
}
static bool F_11 ( struct V_2 * V_3 , unsigned V_4 )
{
const struct V_1 * V_5 ;
const struct V_12 * V_14 ;
unsigned V_26 , V_27 ;
void T_1 * V_32 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 )
return true ;
if ( ! V_5 -> V_33 )
return false ;
V_14 = F_3 ( V_5 , V_4 ) ;
if ( ! V_14 )
return true ;
V_27 = F_7 ( V_14 , V_4 ) ;
V_26 = V_5 -> V_33 + V_14 -> V_34 * 4 ;
V_32 = V_5 -> V_31 + V_26 ;
return ! ( F_9 ( V_32 ) & F_12 ( V_27 ) ) ;
}
static bool F_13 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_5 ;
const struct V_12 * V_14 ;
unsigned V_26 , V_27 ;
T_3 V_35 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 )
return true ;
if ( ! V_5 -> V_36 )
return false ;
V_14 = F_3 ( V_5 , V_4 ) ;
if ( ! V_14 )
return true ;
V_27 = F_7 ( V_14 , V_4 ) ;
V_26 = V_5 -> V_36 + V_14 -> V_34 * 8 ;
V_35 = F_9 ( V_5 -> V_31 + V_26 ) ;
if ( V_35 & F_12 ( V_27 ) )
return true ;
V_26 = V_5 -> V_36 + 4 + V_14 -> V_34 * 8 ;
V_35 = F_9 ( V_5 -> V_31 + V_26 ) ;
if ( V_35 & F_12 ( V_27 ) )
return true ;
return false ;
}
static bool F_14 ( struct V_2 * V_3 , unsigned V_4 )
{
return F_6 ( V_3 , V_4 ) &&
! F_13 ( V_3 , V_4 ) ;
}
static int F_15 ( struct V_37 * V_38 )
{
struct V_2 * V_3 = F_16 ( V_38 ) ;
return V_3 -> V_39 -> V_40 ;
}
static const char * F_17 ( struct V_37 * V_38 ,
unsigned V_41 )
{
struct V_2 * V_3 = F_16 ( V_38 ) ;
return V_3 -> V_39 -> V_42 [ V_41 ] . V_43 ;
}
static int F_18 ( struct V_37 * V_38 , unsigned V_41 ,
const unsigned * * V_44 , unsigned * V_10 )
{
struct V_2 * V_3 = F_16 ( V_38 ) ;
* V_44 = V_3 -> V_39 -> V_42 [ V_41 ] . V_44 ;
* V_10 = V_3 -> V_39 -> V_42 [ V_41 ] . V_10 ;
return 0 ;
}
static void F_19 ( struct V_37 * V_38 , struct V_45 * V_46 ,
unsigned V_4 )
{
struct V_2 * V_3 = F_16 ( V_38 ) ;
void T_1 * V_47 ;
T_3 V_48 , V_49 , V_50 ;
bool V_51 , V_52 ;
if ( ! F_6 ( V_3 , V_4 ) ) {
F_20 ( V_46 , L_2 ) ;
return;
}
V_48 = F_9 ( F_4 ( V_3 , V_4 , V_53 ) ) ;
V_49 = F_9 ( F_4 ( V_3 , V_4 , V_54 ) ) ;
V_50 = ( V_48 & V_55 ) >> V_56 ;
if ( ! V_50 )
F_20 ( V_46 , L_3 ) ;
else
F_21 ( V_46 , L_4 , V_50 ) ;
F_21 ( V_46 , L_5 , V_48 , V_49 ) ;
V_47 = F_4 ( V_3 , V_4 , V_23 ) ;
if ( V_47 )
F_21 ( V_46 , L_6 , F_9 ( V_47 ) ) ;
V_51 = F_13 ( V_3 , V_4 ) ;
V_52 = F_11 ( V_3 , V_4 ) ;
if ( V_51 || V_52 ) {
F_20 ( V_46 , L_7 ) ;
if ( V_51 ) {
F_20 ( V_46 , L_8 ) ;
if ( V_52 )
F_20 ( V_46 , L_9 ) ;
}
if ( V_52 )
F_20 ( V_46 , L_10 ) ;
F_20 ( V_46 , L_11 ) ;
}
}
static int F_22 ( struct V_37 * V_38 )
{
struct V_2 * V_3 = F_16 ( V_38 ) ;
return V_3 -> V_39 -> V_57 ;
}
static const char * F_23 ( struct V_37 * V_38 ,
unsigned V_58 )
{
struct V_2 * V_3 = F_16 ( V_38 ) ;
return V_3 -> V_39 -> V_59 [ V_58 ] . V_43 ;
}
static int F_24 ( struct V_37 * V_38 ,
unsigned V_58 ,
const char * const * * V_42 ,
unsigned * const V_40 )
{
struct V_2 * V_3 = F_16 ( V_38 ) ;
* V_42 = V_3 -> V_39 -> V_59 [ V_58 ] . V_42 ;
* V_40 = V_3 -> V_39 -> V_59 [ V_58 ] . V_40 ;
return 0 ;
}
static int F_25 ( struct V_37 * V_38 , unsigned V_58 ,
unsigned V_41 )
{
struct V_2 * V_3 = F_16 ( V_38 ) ;
const struct V_60 * V_61 = & V_3 -> V_39 -> V_42 [ V_41 ] ;
unsigned long V_62 ;
int V_6 ;
F_26 ( & V_3 -> V_63 , V_62 ) ;
for ( V_6 = 0 ; V_6 < V_61 -> V_10 ; V_6 ++ ) {
if ( ! F_14 ( V_3 , V_61 -> V_44 [ V_6 ] ) ) {
F_27 ( & V_3 -> V_63 , V_62 ) ;
return - V_64 ;
}
}
for ( V_6 = 0 ; V_6 < V_61 -> V_10 ; V_6 ++ ) {
void T_1 * V_65 ;
T_3 V_35 ;
V_65 = F_4 ( V_3 , V_61 -> V_44 [ V_6 ] , V_53 ) ;
V_35 = F_9 ( V_65 ) ;
V_35 &= ~ V_55 ;
if ( V_61 -> V_66 )
V_35 |= V_61 -> V_66 [ V_6 ] << V_56 ;
else
V_35 |= V_61 -> V_50 << V_56 ;
F_28 ( V_35 , V_65 ) ;
}
F_27 ( & V_3 -> V_63 , V_62 ) ;
return 0 ;
}
static void F_29 ( void T_1 * V_65 , bool V_67 )
{
T_3 V_35 ;
V_35 = F_9 ( V_65 ) ;
if ( V_67 ) {
V_35 &= ~ V_68 ;
V_35 |= V_69 ;
} else {
V_35 &= ~ V_69 ;
V_35 |= V_68 ;
}
F_28 ( V_35 , V_65 ) ;
}
static int F_30 ( struct V_37 * V_38 ,
struct V_70 * V_71 ,
unsigned V_4 )
{
struct V_2 * V_3 = F_16 ( V_38 ) ;
void T_1 * V_65 ;
unsigned long V_62 ;
T_3 V_35 ;
F_26 ( & V_3 -> V_63 , V_62 ) ;
if ( ! F_14 ( V_3 , V_4 ) ) {
F_27 ( & V_3 -> V_63 , V_62 ) ;
return - V_64 ;
}
V_65 = F_4 ( V_3 , V_4 , V_53 ) ;
V_35 = F_9 ( V_65 ) & ~ V_55 ;
V_35 &= ~ ( V_72 | V_73 ) ;
V_35 &= ~ ( V_74 | V_75 ) ;
F_28 ( V_35 , V_65 ) ;
F_29 ( V_65 , true ) ;
F_27 ( & V_3 -> V_63 , V_62 ) ;
return 0 ;
}
static int F_31 ( struct V_37 * V_38 ,
struct V_70 * V_71 ,
unsigned V_4 , bool V_67 )
{
struct V_2 * V_3 = F_16 ( V_38 ) ;
void T_1 * V_65 ;
unsigned long V_62 ;
F_26 ( & V_3 -> V_63 , V_62 ) ;
V_65 = F_4 ( V_3 , V_4 , V_53 ) ;
F_29 ( V_65 , V_67 ) ;
F_27 ( & V_3 -> V_63 , V_62 ) ;
return 0 ;
}
static int F_32 ( struct V_37 * V_38 , unsigned V_4 ,
unsigned long * V_76 )
{
struct V_2 * V_3 = F_16 ( V_38 ) ;
enum V_77 V_78 = F_33 ( * V_76 ) ;
const struct V_1 * V_5 ;
T_3 V_35 , V_79 ;
T_3 V_80 = 0 ;
if ( ! F_6 ( V_3 , V_4 ) )
return - V_81 ;
V_5 = F_1 ( V_3 , V_4 ) ;
V_35 = F_9 ( F_4 ( V_3 , V_4 , V_54 ) ) ;
V_79 = ( V_35 & V_82 ) >> V_83 ;
switch ( V_78 ) {
case V_84 :
if ( V_79 )
return - V_85 ;
break;
case V_86 :
if ( ! V_79 || ! ( V_35 & V_87 ) )
return - V_85 ;
switch ( V_79 ) {
case V_88 :
V_80 = 1000 ;
break;
case V_89 :
V_80 = 2000 ;
break;
case V_90 :
V_80 = 5000 ;
break;
case V_91 :
V_80 = 20000 ;
break;
}
break;
case V_92 :
if ( ! V_79 || V_35 & V_87 )
return - V_85 ;
switch ( V_79 ) {
case V_88 :
if ( ! ( V_5 -> V_21 & V_93 ) )
return - V_85 ;
V_80 = 1000 ;
break;
case V_90 :
V_80 = 5000 ;
break;
case V_91 :
V_80 = 20000 ;
break;
}
break;
case V_94 : {
void T_1 * V_95 ;
T_3 V_96 ;
V_95 = F_4 ( V_3 , V_4 , V_23 ) ;
if ( ! V_95 )
return - V_81 ;
V_96 = F_9 ( V_95 ) ;
if ( ! ( V_96 & V_97 ) )
return - V_85 ;
V_96 = ( V_96 & V_98 ) >> V_99 ;
V_80 = F_12 ( V_96 ) * V_100 / 1000 ;
break;
}
default:
return - V_81 ;
}
* V_76 = F_34 ( V_78 , V_80 ) ;
return 0 ;
}
static int F_35 ( struct V_2 * V_3 , unsigned V_4 ,
unsigned long V_76 )
{
unsigned V_78 = F_33 ( V_76 ) ;
unsigned V_80 = F_36 ( V_76 ) ;
const struct V_1 * V_5 ;
void T_1 * V_101 ;
unsigned long V_62 ;
int V_102 = 0 ;
T_3 V_35 ;
F_26 ( & V_3 -> V_63 , V_62 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
V_101 = F_4 ( V_3 , V_4 , V_54 ) ;
V_35 = F_9 ( V_101 ) ;
switch ( V_78 ) {
case V_84 :
V_35 &= ~ ( V_82 | V_87 ) ;
break;
case V_86 :
V_35 &= ~ V_82 ;
V_35 |= V_87 ;
switch ( V_80 ) {
case 20000 :
V_35 |= V_91 << V_83 ;
break;
case 5000 :
V_35 |= V_90 << V_83 ;
break;
case 2000 :
V_35 |= V_89 << V_83 ;
break;
case 1000 :
V_35 |= V_88 << V_83 ;
break;
default:
V_102 = - V_85 ;
}
break;
case V_92 :
V_35 &= ~ ( V_87 | V_82 ) ;
switch ( V_80 ) {
case 20000 :
V_35 |= V_91 << V_83 ;
break;
case 5000 :
V_35 |= V_90 << V_83 ;
break;
case 1000 :
if ( ! ( V_5 -> V_21 & V_93 ) ) {
V_102 = - V_85 ;
break;
}
V_35 |= V_88 << V_83 ;
break;
default:
V_102 = - V_85 ;
}
break;
}
if ( ! V_102 )
F_28 ( V_35 , V_101 ) ;
F_27 ( & V_3 -> V_63 , V_62 ) ;
return V_102 ;
}
static int F_37 ( struct V_2 * V_3 , unsigned V_4 ,
unsigned V_103 )
{
void T_1 * V_65 , * V_95 ;
unsigned long V_62 ;
T_3 V_104 , V_105 ;
int V_102 = 0 ;
V_95 = F_4 ( V_3 , V_4 , V_23 ) ;
if ( ! V_95 )
return - V_81 ;
V_65 = F_4 ( V_3 , V_4 , V_53 ) ;
F_26 ( & V_3 -> V_63 , V_62 ) ;
V_104 = F_9 ( V_65 ) ;
V_105 = F_9 ( V_95 ) ;
V_104 &= ~ V_106 ;
V_105 &= ~ ( V_97 | V_98 ) ;
if ( V_103 ) {
unsigned long V_96 ;
V_96 = F_38 ( V_103 * 1000 / V_100 ) ;
if ( V_96 < 3 || V_96 > 15 ) {
V_102 = - V_85 ;
goto V_107;
} else {
V_104 |= V_106 ;
V_105 |= V_96 << V_99 ;
V_105 |= V_97 ;
}
}
F_28 ( V_104 , V_65 ) ;
F_28 ( V_105 , V_95 ) ;
V_107:
F_27 ( & V_3 -> V_63 , V_62 ) ;
return V_102 ;
}
static int F_39 ( struct V_37 * V_38 , unsigned V_4 ,
unsigned long * V_108 , unsigned V_109 )
{
struct V_2 * V_3 = F_16 ( V_38 ) ;
int V_6 , V_102 ;
if ( ! F_14 ( V_3 , V_4 ) )
return - V_81 ;
for ( V_6 = 0 ; V_6 < V_109 ; V_6 ++ ) {
switch ( F_33 ( V_108 [ V_6 ] ) ) {
case V_84 :
case V_86 :
case V_92 :
V_102 = F_35 ( V_3 , V_4 , V_108 [ V_6 ] ) ;
if ( V_102 )
return V_102 ;
break;
case V_94 :
V_102 = F_37 ( V_3 , V_4 ,
F_36 ( V_108 [ V_6 ] ) ) ;
if ( V_102 )
return V_102 ;
break;
default:
return - V_81 ;
}
}
return 0 ;
}
static int F_40 ( struct V_110 * V_111 , unsigned V_26 )
{
struct V_2 * V_3 = F_41 ( V_111 ) ;
void T_1 * V_18 ;
V_18 = F_4 ( V_3 , V_26 , V_53 ) ;
if ( ! V_18 )
return - V_85 ;
return ! ! ( F_9 ( V_18 ) & V_112 ) ;
}
static void F_42 ( struct V_110 * V_111 , unsigned V_26 , int V_35 )
{
struct V_2 * V_3 = F_41 ( V_111 ) ;
void T_1 * V_18 ;
V_18 = F_4 ( V_3 , V_26 , V_53 ) ;
if ( V_18 ) {
unsigned long V_62 ;
T_3 V_65 ;
F_26 ( & V_3 -> V_63 , V_62 ) ;
V_65 = F_9 ( V_18 ) ;
if ( V_35 )
V_65 |= V_113 ;
else
V_65 &= ~ V_113 ;
F_28 ( V_65 , V_18 ) ;
F_27 ( & V_3 -> V_63 , V_62 ) ;
}
}
static int F_43 ( struct V_110 * V_111 , unsigned V_26 )
{
return F_44 ( V_111 -> V_16 + V_26 ) ;
}
static int F_45 ( struct V_110 * V_111 , unsigned V_26 ,
int V_35 )
{
F_42 ( V_111 , V_26 , V_35 ) ;
return F_46 ( V_111 -> V_16 + V_26 ) ;
}
static void F_47 ( struct V_114 * V_115 )
{
struct V_110 * V_116 = F_48 ( V_115 ) ;
struct V_2 * V_3 = F_41 ( V_116 ) ;
const struct V_1 * V_5 ;
unsigned V_4 = F_49 ( V_115 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 ) {
const struct V_12 * V_14 ;
unsigned V_25 , V_27 ;
V_14 = F_3 ( V_5 , V_4 ) ;
if ( ! V_14 )
return;
V_25 = V_14 -> V_34 ;
V_27 = F_7 ( V_14 , V_4 ) ;
F_50 ( & V_3 -> V_63 ) ;
F_28 ( F_12 ( V_27 ) , V_5 -> V_31 + V_117 + V_25 * 4 ) ;
F_51 ( & V_3 -> V_63 ) ;
}
}
static void F_52 ( struct V_114 * V_115 )
{
struct V_110 * V_116 = F_48 ( V_115 ) ;
struct V_2 * V_3 = F_41 ( V_116 ) ;
const struct V_1 * V_5 ;
unsigned V_4 = F_49 ( V_115 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 ) {
const struct V_12 * V_14 ;
unsigned V_25 , V_27 ;
unsigned long V_62 ;
T_3 V_35 ;
V_14 = F_3 ( V_5 , V_4 ) ;
if ( ! V_14 )
return;
V_25 = V_14 -> V_34 ;
V_27 = F_7 ( V_14 , V_4 ) ;
F_26 ( & V_3 -> V_63 , V_62 ) ;
F_28 ( F_12 ( V_27 ) , V_5 -> V_31 + V_117 + V_25 * 4 ) ;
V_35 = F_9 ( V_5 -> V_31 + V_5 -> V_118 + V_25 * 4 ) ;
V_35 |= F_12 ( V_27 ) ;
F_28 ( V_35 , V_5 -> V_31 + V_5 -> V_118 + V_25 * 4 ) ;
F_27 ( & V_3 -> V_63 , V_62 ) ;
}
}
static void F_53 ( struct V_114 * V_115 , bool V_119 )
{
struct V_110 * V_116 = F_48 ( V_115 ) ;
struct V_2 * V_3 = F_41 ( V_116 ) ;
const struct V_1 * V_5 ;
unsigned V_4 = F_49 ( V_115 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 ) {
const struct V_12 * V_14 ;
unsigned V_25 , V_27 ;
unsigned long V_62 ;
void T_1 * V_18 ;
T_3 V_35 ;
V_14 = F_3 ( V_5 , V_4 ) ;
if ( ! V_14 )
return;
V_25 = V_14 -> V_34 ;
V_27 = F_7 ( V_14 , V_4 ) ;
V_18 = V_5 -> V_31 + V_5 -> V_118 + V_25 * 4 ;
F_26 ( & V_3 -> V_63 , V_62 ) ;
V_35 = F_9 ( V_18 ) ;
if ( V_119 )
V_35 &= ~ F_12 ( V_27 ) ;
else
V_35 |= F_12 ( V_27 ) ;
F_28 ( V_35 , V_18 ) ;
F_27 ( & V_3 -> V_63 , V_62 ) ;
}
}
static void F_54 ( struct V_114 * V_115 )
{
F_53 ( V_115 , true ) ;
}
static void F_55 ( struct V_114 * V_115 )
{
F_53 ( V_115 , false ) ;
}
static int F_56 ( struct V_114 * V_115 , unsigned type )
{
struct V_110 * V_116 = F_48 ( V_115 ) ;
struct V_2 * V_3 = F_41 ( V_116 ) ;
unsigned V_4 = F_49 ( V_115 ) ;
unsigned long V_62 ;
void T_1 * V_18 ;
T_3 V_35 ;
V_18 = F_4 ( V_3 , V_4 , V_53 ) ;
if ( ! V_18 )
return - V_85 ;
if ( F_11 ( V_3 , V_4 ) ) {
F_2 ( V_3 -> V_11 , L_12 , V_4 ) ;
return - V_120 ;
}
F_26 ( & V_3 -> V_63 , V_62 ) ;
V_35 = F_9 ( V_18 ) ;
V_35 &= ~ ( V_121 | V_122 ) ;
if ( ( type & V_123 ) == V_123 ) {
V_35 |= V_124 << V_125 ;
} else if ( type & V_126 ) {
V_35 |= V_127 << V_125 ;
V_35 |= V_122 ;
} else if ( type & V_128 ) {
V_35 |= V_127 << V_125 ;
} else if ( type & V_129 ) {
if ( type & V_130 )
V_35 |= V_122 ;
} else {
V_35 |= V_131 << V_125 ;
}
F_28 ( V_35 , V_18 ) ;
if ( type & V_123 )
F_57 ( V_115 , V_132 ) ;
else if ( type & V_129 )
F_57 ( V_115 , V_133 ) ;
F_27 ( & V_3 -> V_63 , V_62 ) ;
return 0 ;
}
static int F_58 ( struct V_114 * V_115 , unsigned int V_134 )
{
struct V_110 * V_116 = F_48 ( V_115 ) ;
struct V_2 * V_3 = F_41 ( V_116 ) ;
unsigned V_4 = F_49 ( V_115 ) ;
if ( V_134 )
F_59 ( V_3 -> V_135 ) ;
else
F_60 ( V_3 -> V_135 ) ;
F_61 ( V_3 -> V_11 , L_13 , V_134 ? L_14 : L_15 , V_4 ) ;
return 0 ;
}
static T_4 F_62 ( struct V_2 * V_3 ,
const struct V_1 * V_5 )
{
struct V_110 * V_116 = & V_3 -> V_111 ;
T_4 V_102 = V_136 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_5 -> V_13 ; V_25 ++ ) {
const struct V_12 * V_14 = & V_5 -> V_15 [ V_25 ] ;
unsigned long V_137 , V_138 , V_27 ;
V_137 = F_9 ( V_5 -> V_31 + V_117 + V_14 -> V_34 * 4 ) ;
V_138 = F_9 ( V_5 -> V_31 + V_5 -> V_118 +
V_14 -> V_34 * 4 ) ;
V_137 &= V_138 ;
F_63 (gpp_offset, &pending, padgrp->size) {
unsigned V_19 , V_135 ;
V_19 = V_14 -> V_16 - V_5 -> V_9 + V_27 ;
if ( V_19 >= V_5 -> V_10 )
break;
V_135 = F_64 ( V_116 -> V_139 ,
V_5 -> V_9 + V_19 ) ;
F_65 ( V_135 ) ;
V_102 |= V_140 ;
}
}
return V_102 ;
}
static T_4 F_66 ( int V_135 , void * V_141 )
{
const struct V_1 * V_5 ;
struct V_2 * V_3 = V_141 ;
T_4 V_102 = V_136 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ ) {
V_5 = & V_3 -> V_8 [ V_6 ] ;
V_102 |= F_62 ( V_3 , V_5 ) ;
}
return V_102 ;
}
static int F_67 ( struct V_2 * V_3 , int V_135 )
{
int V_102 ;
V_3 -> V_111 = V_142 ;
V_3 -> V_111 . V_143 = V_3 -> V_39 -> V_10 ;
V_3 -> V_111 . V_144 = F_68 ( V_3 -> V_11 ) ;
V_3 -> V_111 . V_145 = V_3 -> V_11 ;
V_3 -> V_111 . V_16 = - 1 ;
V_3 -> V_135 = V_135 ;
V_102 = F_69 ( V_3 -> V_11 , & V_3 -> V_111 , V_3 ) ;
if ( V_102 ) {
F_70 ( V_3 -> V_11 , L_16 ) ;
return V_102 ;
}
V_102 = F_71 ( & V_3 -> V_111 , F_68 ( V_3 -> V_11 ) ,
0 , 0 , V_3 -> V_39 -> V_10 ) ;
if ( V_102 ) {
F_70 ( V_3 -> V_11 , L_17 ) ;
return V_102 ;
}
V_102 = F_72 ( V_3 -> V_11 , V_135 , F_66 ,
V_146 | V_147 ,
F_68 ( V_3 -> V_11 ) , V_3 ) ;
if ( V_102 ) {
F_70 ( V_3 -> V_11 , L_18 ) ;
return V_102 ;
}
V_102 = F_73 ( & V_3 -> V_111 , & V_148 , 0 ,
V_149 , V_150 ) ;
if ( V_102 ) {
F_70 ( V_3 -> V_11 , L_19 ) ;
return V_102 ;
}
F_74 ( & V_3 -> V_111 , & V_148 , V_135 ,
NULL ) ;
return 0 ;
}
static int F_75 ( struct V_2 * V_3 ,
struct V_1 * V_5 )
{
struct V_12 * V_15 ;
unsigned V_10 = V_5 -> V_10 ;
unsigned V_30 = 0 ;
T_2 V_13 , V_6 ;
if ( V_5 -> V_15 )
V_13 = V_5 -> V_13 ;
else
V_13 = F_76 ( V_5 -> V_10 , V_5 -> V_151 ) ;
V_15 = F_77 ( V_3 -> V_11 , V_13 , sizeof( * V_15 ) , V_152 ) ;
if ( ! V_15 )
return - V_153 ;
for ( V_6 = 0 ; V_6 < V_13 ; V_6 ++ ) {
if ( V_5 -> V_15 ) {
V_15 [ V_6 ] = V_5 -> V_15 [ V_6 ] ;
} else {
unsigned V_151 = V_5 -> V_151 ;
V_15 [ V_6 ] . V_34 = V_6 ;
V_15 [ V_6 ] . V_16 = V_5 -> V_9 + V_6 * V_151 ;
V_15 [ V_6 ] . V_17 = F_78 ( V_151 , V_10 ) ;
V_10 -= V_15 [ V_6 ] . V_17 ;
}
if ( V_15 [ V_6 ] . V_17 > 32 )
return - V_85 ;
V_15 [ V_6 ] . V_30 = V_30 ;
if ( V_5 -> V_154 )
V_30 += V_5 -> V_154 ;
else
V_30 += F_76 ( V_15 [ V_6 ] . V_17 * 4 , 32 ) ;
}
V_5 -> V_13 = V_13 ;
V_5 -> V_15 = V_15 ;
return 0 ;
}
static int F_79 ( struct V_2 * V_3 )
{
#ifdef F_80
const struct V_155 * V_39 = V_3 -> V_39 ;
struct V_156 * V_8 ;
struct V_157 * V_158 ;
int V_6 ;
V_158 = F_77 ( V_3 -> V_11 , V_39 -> V_10 , sizeof( * V_158 ) , V_152 ) ;
if ( ! V_158 )
return - V_153 ;
V_8 = F_77 ( V_3 -> V_11 , V_3 -> V_7 ,
sizeof( * V_8 ) , V_152 ) ;
if ( ! V_8 )
return - V_153 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ ) {
struct V_1 * V_5 = & V_3 -> V_8 [ V_6 ] ;
T_3 * V_159 ;
V_159 = F_77 ( V_3 -> V_11 , V_5 -> V_13 ,
sizeof( * V_159 ) , V_152 ) ;
if ( ! V_159 )
return - V_153 ;
V_8 [ V_6 ] . V_159 = V_159 ;
}
V_3 -> V_160 . V_158 = V_158 ;
V_3 -> V_160 . V_8 = V_8 ;
#endif
return 0 ;
}
int F_81 ( struct V_161 * V_162 ,
const struct V_155 * V_163 )
{
struct V_2 * V_3 ;
int V_6 , V_102 , V_135 ;
if ( ! V_163 )
return - V_85 ;
V_3 = F_82 ( & V_162 -> V_11 , sizeof( * V_3 ) , V_152 ) ;
if ( ! V_3 )
return - V_153 ;
V_3 -> V_11 = & V_162 -> V_11 ;
V_3 -> V_39 = V_163 ;
F_83 ( & V_3 -> V_63 ) ;
V_3 -> V_7 = V_3 -> V_39 -> V_7 ;
V_3 -> V_8 = F_77 ( & V_162 -> V_11 , V_3 -> V_7 ,
sizeof( * V_3 -> V_8 ) , V_152 ) ;
if ( ! V_3 -> V_8 )
return - V_153 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ ) {
struct V_1 * V_5 = & V_3 -> V_8 [ V_6 ] ;
struct V_164 * V_165 ;
void T_1 * V_31 ;
T_3 V_166 ;
* V_5 = V_3 -> V_39 -> V_8 [ V_6 ] ;
V_165 = F_84 ( V_162 , V_167 ,
V_5 -> V_168 ) ;
V_31 = F_85 ( & V_162 -> V_11 , V_165 ) ;
if ( F_86 ( V_31 ) )
return F_87 ( V_31 ) ;
if ( ! V_5 -> V_21 ) {
T_3 V_169 ;
V_169 = ( F_9 ( V_31 + V_170 ) & V_171 ) >> V_172 ;
if ( V_169 >= 0x94 ) {
V_5 -> V_21 |= V_22 ;
V_5 -> V_21 |= V_93 ;
}
}
V_166 = F_9 ( V_31 + V_173 ) ;
V_5 -> V_31 = V_31 ;
V_5 -> V_24 = V_31 + V_166 ;
V_102 = F_75 ( V_3 , V_5 ) ;
if ( V_102 )
return V_102 ;
}
V_135 = F_88 ( V_162 , 0 ) ;
if ( V_135 < 0 ) {
F_70 ( & V_162 -> V_11 , L_20 ) ;
return V_135 ;
}
V_102 = F_79 ( V_3 ) ;
if ( V_102 )
return V_102 ;
V_3 -> V_174 = V_175 ;
V_3 -> V_174 . V_43 = F_68 ( & V_162 -> V_11 ) ;
V_3 -> V_174 . V_44 = V_3 -> V_39 -> V_44 ;
V_3 -> V_174 . V_10 = V_3 -> V_39 -> V_10 ;
V_3 -> V_38 = F_89 ( & V_162 -> V_11 , & V_3 -> V_174 ,
V_3 ) ;
if ( F_86 ( V_3 -> V_38 ) ) {
F_70 ( & V_162 -> V_11 , L_21 ) ;
return F_87 ( V_3 -> V_38 ) ;
}
V_102 = F_67 ( V_3 , V_135 ) ;
if ( V_102 )
return V_102 ;
F_90 ( V_162 , V_3 ) ;
return 0 ;
}
static bool F_91 ( struct V_2 * V_3 , unsigned V_4 )
{
const struct V_176 * V_177 = F_92 ( V_3 -> V_38 , V_4 ) ;
if ( ! V_177 || ! F_14 ( V_3 , V_4 ) )
return false ;
if ( V_177 -> V_178 || V_177 -> V_179 ||
F_93 ( & V_3 -> V_111 , V_4 ) )
return true ;
return false ;
}
int F_94 ( struct V_180 * V_11 )
{
struct V_161 * V_162 = F_95 ( V_11 ) ;
struct V_2 * V_3 = F_96 ( V_162 ) ;
struct V_156 * V_8 ;
struct V_157 * V_158 ;
int V_6 ;
V_158 = V_3 -> V_160 . V_158 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_39 -> V_10 ; V_6 ++ ) {
const struct V_181 * V_182 = & V_3 -> V_39 -> V_44 [ V_6 ] ;
void T_1 * V_47 ;
T_3 V_183 ;
if ( ! F_91 ( V_3 , V_182 -> V_184 ) )
continue;
V_183 = F_9 ( F_4 ( V_3 , V_182 -> V_184 , V_53 ) ) ;
V_158 [ V_6 ] . V_65 = V_183 & ~ V_112 ;
V_183 = F_9 ( F_4 ( V_3 , V_182 -> V_184 , V_54 ) ) ;
V_158 [ V_6 ] . V_101 = V_183 ;
V_47 = F_4 ( V_3 , V_182 -> V_184 , V_23 ) ;
if ( V_47 )
V_158 [ V_6 ] . V_95 = F_9 ( V_47 ) ;
}
V_8 = V_3 -> V_160 . V_8 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ ) {
struct V_1 * V_5 = & V_3 -> V_8 [ V_6 ] ;
void T_1 * V_16 ;
unsigned V_25 ;
V_16 = V_5 -> V_31 + V_5 -> V_118 ;
for ( V_25 = 0 ; V_25 < V_5 -> V_13 ; V_25 ++ )
V_8 [ V_6 ] . V_159 [ V_25 ] = F_9 ( V_16 + V_25 * 4 ) ;
}
return 0 ;
}
static void F_97 ( struct V_2 * V_3 )
{
T_2 V_6 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ ) {
const struct V_1 * V_5 ;
void T_1 * V_16 ;
unsigned V_25 ;
V_5 = & V_3 -> V_8 [ V_6 ] ;
V_16 = V_5 -> V_31 ;
for ( V_25 = 0 ; V_25 < V_5 -> V_13 ; V_25 ++ ) {
F_28 ( 0 , V_16 + V_5 -> V_118 + V_25 * 4 ) ;
F_28 ( 0xffff , V_16 + V_117 + V_25 * 4 ) ;
}
}
}
int F_98 ( struct V_180 * V_11 )
{
struct V_161 * V_162 = F_95 ( V_11 ) ;
struct V_2 * V_3 = F_96 ( V_162 ) ;
const struct V_156 * V_8 ;
const struct V_157 * V_158 ;
int V_6 ;
F_97 ( V_3 ) ;
V_158 = V_3 -> V_160 . V_158 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_39 -> V_10 ; V_6 ++ ) {
const struct V_181 * V_182 = & V_3 -> V_39 -> V_44 [ V_6 ] ;
void T_1 * V_47 ;
T_3 V_183 ;
if ( ! F_91 ( V_3 , V_182 -> V_184 ) )
continue;
V_47 = F_4 ( V_3 , V_182 -> V_184 , V_53 ) ;
V_183 = F_9 ( V_47 ) & ~ V_112 ;
if ( V_183 != V_158 [ V_6 ] . V_65 ) {
F_28 ( V_158 [ V_6 ] . V_65 , V_47 ) ;
F_61 ( V_11 , L_22 ,
V_182 -> V_184 , F_9 ( V_47 ) ) ;
}
V_47 = F_4 ( V_3 , V_182 -> V_184 , V_54 ) ;
V_183 = F_9 ( V_47 ) ;
if ( V_183 != V_158 [ V_6 ] . V_101 ) {
F_28 ( V_158 [ V_6 ] . V_101 , V_47 ) ;
F_61 ( V_11 , L_23 ,
V_182 -> V_184 , F_9 ( V_47 ) ) ;
}
V_47 = F_4 ( V_3 , V_182 -> V_184 , V_23 ) ;
if ( V_47 ) {
V_183 = F_9 ( V_47 ) ;
if ( V_183 != V_158 [ V_6 ] . V_95 ) {
F_28 ( V_158 [ V_6 ] . V_95 , V_47 ) ;
F_61 ( V_11 , L_24 ,
V_182 -> V_184 , F_9 ( V_47 ) ) ;
}
}
}
V_8 = V_3 -> V_160 . V_8 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ ) {
struct V_1 * V_5 = & V_3 -> V_8 [ V_6 ] ;
void T_1 * V_16 ;
unsigned V_25 ;
V_16 = V_5 -> V_31 + V_5 -> V_118 ;
for ( V_25 = 0 ; V_25 < V_5 -> V_13 ; V_25 ++ ) {
F_28 ( V_8 [ V_6 ] . V_159 [ V_25 ] , V_16 + V_25 * 4 ) ;
F_61 ( V_11 , L_25 , V_6 , V_25 ,
F_9 ( V_16 + V_25 * 4 ) ) ;
}
}
return 0 ;
}

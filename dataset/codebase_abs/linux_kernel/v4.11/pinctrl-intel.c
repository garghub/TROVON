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
static void T_1 * F_3 ( struct V_2 * V_3 , unsigned V_4 ,
unsigned V_12 )
{
const struct V_1 * V_5 ;
unsigned V_13 ;
T_2 V_14 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 )
return NULL ;
V_13 = F_4 ( V_5 , V_4 ) ;
V_14 = ( V_5 -> V_15 & V_16 ) ? 4 : 2 ;
if ( V_12 == V_17 && ! ( V_5 -> V_15 & V_16 ) )
return NULL ;
return V_5 -> V_18 + V_12 + V_13 * V_14 * 4 ;
}
static bool F_5 ( struct V_2 * V_3 , unsigned V_4 )
{
const struct V_1 * V_5 ;
unsigned V_13 , V_19 , V_20 , V_21 ;
void T_1 * V_22 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 )
return false ;
if ( ! V_5 -> V_23 )
return true ;
V_13 = F_4 ( V_5 , V_4 ) ;
V_21 = V_13 / V_5 -> V_24 ;
V_19 = F_6 ( V_13 % V_5 -> V_24 ) ;
V_20 = V_5 -> V_23 + 0x10 * V_21 + V_19 * 4 ;
V_22 = V_5 -> V_25 + V_20 ;
return ! ( F_7 ( V_22 ) & F_8 ( V_13 ) ) ;
}
static bool F_9 ( struct V_2 * V_3 , unsigned V_4 )
{
const struct V_1 * V_5 ;
unsigned V_13 , V_19 , V_20 ;
void T_1 * V_26 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 )
return true ;
if ( ! V_5 -> V_27 )
return false ;
V_13 = F_4 ( V_5 , V_4 ) ;
V_19 = V_13 / V_5 -> V_24 ;
V_20 = V_5 -> V_27 + V_19 * 4 ;
V_26 = V_5 -> V_25 + V_20 ;
return ! ( F_7 ( V_26 ) & F_10 ( V_13 % V_5 -> V_24 ) ) ;
}
static bool F_11 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_5 ;
unsigned V_13 , V_19 , V_20 ;
T_3 V_28 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 )
return true ;
if ( ! V_5 -> V_29 )
return false ;
V_13 = F_4 ( V_5 , V_4 ) ;
V_19 = V_13 / V_5 -> V_24 ;
V_20 = V_5 -> V_29 + V_19 * 8 ;
V_28 = F_7 ( V_5 -> V_25 + V_20 ) ;
if ( V_28 & F_10 ( V_4 % V_5 -> V_24 ) )
return true ;
V_20 = V_5 -> V_29 + 4 + V_19 * 8 ;
V_28 = F_7 ( V_5 -> V_25 + V_20 ) ;
if ( V_28 & F_10 ( V_4 % V_5 -> V_24 ) )
return true ;
return false ;
}
static bool F_12 ( struct V_2 * V_3 , unsigned V_4 )
{
return F_5 ( V_3 , V_4 ) &&
! F_11 ( V_3 , V_4 ) ;
}
static int F_13 ( struct V_30 * V_31 )
{
struct V_2 * V_3 = F_14 ( V_31 ) ;
return V_3 -> V_32 -> V_33 ;
}
static const char * F_15 ( struct V_30 * V_31 ,
unsigned V_21 )
{
struct V_2 * V_3 = F_14 ( V_31 ) ;
return V_3 -> V_32 -> V_34 [ V_21 ] . V_35 ;
}
static int F_16 ( struct V_30 * V_31 , unsigned V_21 ,
const unsigned * * V_36 , unsigned * V_10 )
{
struct V_2 * V_3 = F_14 ( V_31 ) ;
* V_36 = V_3 -> V_32 -> V_34 [ V_21 ] . V_36 ;
* V_10 = V_3 -> V_32 -> V_34 [ V_21 ] . V_10 ;
return 0 ;
}
static void F_17 ( struct V_30 * V_31 , struct V_37 * V_38 ,
unsigned V_4 )
{
struct V_2 * V_3 = F_14 ( V_31 ) ;
void T_1 * V_39 ;
T_3 V_40 , V_41 , V_42 ;
bool V_43 , V_44 ;
if ( ! F_5 ( V_3 , V_4 ) ) {
F_18 ( V_38 , L_2 ) ;
return;
}
V_40 = F_7 ( F_3 ( V_3 , V_4 , V_45 ) ) ;
V_41 = F_7 ( F_3 ( V_3 , V_4 , V_46 ) ) ;
V_42 = ( V_40 & V_47 ) >> V_48 ;
if ( ! V_42 )
F_18 ( V_38 , L_3 ) ;
else
F_19 ( V_38 , L_4 , V_42 ) ;
F_19 ( V_38 , L_5 , V_40 , V_41 ) ;
V_39 = F_3 ( V_3 , V_4 , V_17 ) ;
if ( V_39 )
F_19 ( V_38 , L_6 , F_7 ( V_39 ) ) ;
V_43 = F_11 ( V_3 , V_4 ) ;
V_44 = F_9 ( V_3 , V_4 ) ;
if ( V_43 || V_44 ) {
F_18 ( V_38 , L_7 ) ;
if ( V_43 ) {
F_18 ( V_38 , L_8 ) ;
if ( V_44 )
F_18 ( V_38 , L_9 ) ;
}
if ( V_44 )
F_18 ( V_38 , L_10 ) ;
F_18 ( V_38 , L_11 ) ;
}
}
static int F_20 ( struct V_30 * V_31 )
{
struct V_2 * V_3 = F_14 ( V_31 ) ;
return V_3 -> V_32 -> V_49 ;
}
static const char * F_21 ( struct V_30 * V_31 ,
unsigned V_50 )
{
struct V_2 * V_3 = F_14 ( V_31 ) ;
return V_3 -> V_32 -> V_51 [ V_50 ] . V_35 ;
}
static int F_22 ( struct V_30 * V_31 ,
unsigned V_50 ,
const char * const * * V_34 ,
unsigned * const V_33 )
{
struct V_2 * V_3 = F_14 ( V_31 ) ;
* V_34 = V_3 -> V_32 -> V_51 [ V_50 ] . V_34 ;
* V_33 = V_3 -> V_32 -> V_51 [ V_50 ] . V_33 ;
return 0 ;
}
static int F_23 ( struct V_30 * V_31 , unsigned V_50 ,
unsigned V_21 )
{
struct V_2 * V_3 = F_14 ( V_31 ) ;
const struct V_52 * V_53 = & V_3 -> V_32 -> V_34 [ V_21 ] ;
unsigned long V_54 ;
int V_6 ;
F_24 ( & V_3 -> V_55 , V_54 ) ;
for ( V_6 = 0 ; V_6 < V_53 -> V_10 ; V_6 ++ ) {
if ( ! F_12 ( V_3 , V_53 -> V_36 [ V_6 ] ) ) {
F_25 ( & V_3 -> V_55 , V_54 ) ;
return - V_56 ;
}
}
for ( V_6 = 0 ; V_6 < V_53 -> V_10 ; V_6 ++ ) {
void T_1 * V_57 ;
T_3 V_28 ;
V_57 = F_3 ( V_3 , V_53 -> V_36 [ V_6 ] , V_45 ) ;
V_28 = F_7 ( V_57 ) ;
V_28 &= ~ V_47 ;
V_28 |= V_53 -> V_42 << V_48 ;
F_26 ( V_28 , V_57 ) ;
}
F_25 ( & V_3 -> V_55 , V_54 ) ;
return 0 ;
}
static void F_27 ( void T_1 * V_57 , bool V_58 )
{
T_3 V_28 ;
V_28 = F_7 ( V_57 ) ;
if ( V_58 ) {
V_28 &= ~ V_59 ;
V_28 |= V_60 ;
} else {
V_28 &= ~ V_60 ;
V_28 |= V_59 ;
}
F_26 ( V_28 , V_57 ) ;
}
static int F_28 ( struct V_30 * V_31 ,
struct V_61 * V_62 ,
unsigned V_4 )
{
struct V_2 * V_3 = F_14 ( V_31 ) ;
void T_1 * V_57 ;
unsigned long V_54 ;
T_3 V_28 ;
F_24 ( & V_3 -> V_55 , V_54 ) ;
if ( ! F_12 ( V_3 , V_4 ) ) {
F_25 ( & V_3 -> V_55 , V_54 ) ;
return - V_56 ;
}
V_57 = F_3 ( V_3 , V_4 , V_45 ) ;
V_28 = F_7 ( V_57 ) & ~ V_47 ;
V_28 &= ~ ( V_63 | V_64 ) ;
V_28 &= ~ ( V_65 | V_66 ) ;
F_26 ( V_28 , V_57 ) ;
F_27 ( V_57 , true ) ;
F_25 ( & V_3 -> V_55 , V_54 ) ;
return 0 ;
}
static int F_29 ( struct V_30 * V_31 ,
struct V_61 * V_62 ,
unsigned V_4 , bool V_58 )
{
struct V_2 * V_3 = F_14 ( V_31 ) ;
void T_1 * V_57 ;
unsigned long V_54 ;
F_24 ( & V_3 -> V_55 , V_54 ) ;
V_57 = F_3 ( V_3 , V_4 , V_45 ) ;
F_27 ( V_57 , V_58 ) ;
F_25 ( & V_3 -> V_55 , V_54 ) ;
return 0 ;
}
static int F_30 ( struct V_30 * V_31 , unsigned V_4 ,
unsigned long * V_67 )
{
struct V_2 * V_3 = F_14 ( V_31 ) ;
enum V_68 V_69 = F_31 ( * V_67 ) ;
const struct V_1 * V_5 ;
T_3 V_28 , V_70 ;
T_3 V_71 = 0 ;
if ( ! F_5 ( V_3 , V_4 ) )
return - V_72 ;
V_5 = F_1 ( V_3 , V_4 ) ;
V_28 = F_7 ( F_3 ( V_3 , V_4 , V_46 ) ) ;
V_70 = ( V_28 & V_73 ) >> V_74 ;
switch ( V_69 ) {
case V_75 :
if ( V_70 )
return - V_76 ;
break;
case V_77 :
if ( ! V_70 || ! ( V_28 & V_78 ) )
return - V_76 ;
switch ( V_70 ) {
case V_79 :
V_71 = 1000 ;
break;
case V_80 :
V_71 = 2000 ;
break;
case V_81 :
V_71 = 5000 ;
break;
case V_82 :
V_71 = 20000 ;
break;
}
break;
case V_83 :
if ( ! V_70 || V_28 & V_78 )
return - V_76 ;
switch ( V_70 ) {
case V_79 :
if ( ! ( V_5 -> V_15 & V_84 ) )
return - V_76 ;
V_71 = 1000 ;
break;
case V_81 :
V_71 = 5000 ;
break;
case V_82 :
V_71 = 20000 ;
break;
}
break;
case V_85 : {
void T_1 * V_86 ;
T_3 V_87 ;
V_86 = F_3 ( V_3 , V_4 , V_17 ) ;
if ( ! V_86 )
return - V_72 ;
V_87 = F_7 ( V_86 ) ;
if ( ! ( V_87 & V_88 ) )
return - V_76 ;
V_87 = ( V_87 & V_89 ) >> V_90 ;
V_71 = F_10 ( V_87 ) * V_91 / 1000 ;
break;
}
default:
return - V_72 ;
}
* V_67 = F_32 ( V_69 , V_71 ) ;
return 0 ;
}
static int F_33 ( struct V_2 * V_3 , unsigned V_4 ,
unsigned long V_67 )
{
unsigned V_69 = F_31 ( V_67 ) ;
unsigned V_71 = F_34 ( V_67 ) ;
const struct V_1 * V_5 ;
void T_1 * V_92 ;
unsigned long V_54 ;
int V_93 = 0 ;
T_3 V_28 ;
F_24 ( & V_3 -> V_55 , V_54 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
V_92 = F_3 ( V_3 , V_4 , V_46 ) ;
V_28 = F_7 ( V_92 ) ;
switch ( V_69 ) {
case V_75 :
V_28 &= ~ ( V_73 | V_78 ) ;
break;
case V_77 :
V_28 &= ~ V_73 ;
V_28 |= V_78 ;
switch ( V_71 ) {
case 20000 :
V_28 |= V_82 << V_74 ;
break;
case 5000 :
V_28 |= V_81 << V_74 ;
break;
case 2000 :
V_28 |= V_80 << V_74 ;
break;
case 1000 :
V_28 |= V_79 << V_74 ;
break;
default:
V_93 = - V_76 ;
}
break;
case V_83 :
V_28 &= ~ ( V_78 | V_73 ) ;
switch ( V_71 ) {
case 20000 :
V_28 |= V_82 << V_74 ;
break;
case 5000 :
V_28 |= V_81 << V_74 ;
break;
case 1000 :
if ( ! ( V_5 -> V_15 & V_84 ) ) {
V_93 = - V_76 ;
break;
}
V_28 |= V_79 << V_74 ;
break;
default:
V_93 = - V_76 ;
}
break;
}
if ( ! V_93 )
F_26 ( V_28 , V_92 ) ;
F_25 ( & V_3 -> V_55 , V_54 ) ;
return V_93 ;
}
static int F_35 ( struct V_2 * V_3 , unsigned V_4 ,
unsigned V_94 )
{
void T_1 * V_57 , * V_86 ;
unsigned long V_54 ;
T_3 V_95 , V_96 ;
int V_93 = 0 ;
V_86 = F_3 ( V_3 , V_4 , V_17 ) ;
if ( ! V_86 )
return - V_72 ;
V_57 = F_3 ( V_3 , V_4 , V_45 ) ;
F_24 ( & V_3 -> V_55 , V_54 ) ;
V_95 = F_7 ( V_57 ) ;
V_96 = F_7 ( V_86 ) ;
V_95 &= ~ V_97 ;
V_96 &= ~ ( V_88 | V_89 ) ;
if ( V_94 ) {
unsigned long V_87 ;
V_87 = F_36 ( V_94 * 1000 / V_91 ) ;
if ( V_87 < 3 || V_87 > 15 ) {
V_93 = - V_76 ;
goto V_98;
} else {
V_95 |= V_97 ;
V_96 |= V_87 << V_90 ;
V_96 |= V_88 ;
}
}
F_26 ( V_95 , V_57 ) ;
F_26 ( V_96 , V_86 ) ;
V_98:
F_25 ( & V_3 -> V_55 , V_54 ) ;
return V_93 ;
}
static int F_37 ( struct V_30 * V_31 , unsigned V_4 ,
unsigned long * V_99 , unsigned V_100 )
{
struct V_2 * V_3 = F_14 ( V_31 ) ;
int V_6 , V_93 ;
if ( ! F_12 ( V_3 , V_4 ) )
return - V_72 ;
for ( V_6 = 0 ; V_6 < V_100 ; V_6 ++ ) {
switch ( F_31 ( V_99 [ V_6 ] ) ) {
case V_75 :
case V_77 :
case V_83 :
V_93 = F_33 ( V_3 , V_4 , V_99 [ V_6 ] ) ;
if ( V_93 )
return V_93 ;
break;
case V_85 :
V_93 = F_35 ( V_3 , V_4 ,
F_34 ( V_99 [ V_6 ] ) ) ;
if ( V_93 )
return V_93 ;
break;
default:
return - V_72 ;
}
}
return 0 ;
}
static int F_38 ( struct V_101 * V_102 , unsigned V_20 )
{
struct V_2 * V_3 = F_39 ( V_102 ) ;
void T_1 * V_12 ;
V_12 = F_3 ( V_3 , V_20 , V_45 ) ;
if ( ! V_12 )
return - V_76 ;
return ! ! ( F_7 ( V_12 ) & V_103 ) ;
}
static void F_40 ( struct V_101 * V_102 , unsigned V_20 , int V_28 )
{
struct V_2 * V_3 = F_39 ( V_102 ) ;
void T_1 * V_12 ;
V_12 = F_3 ( V_3 , V_20 , V_45 ) ;
if ( V_12 ) {
unsigned long V_54 ;
T_3 V_57 ;
F_24 ( & V_3 -> V_55 , V_54 ) ;
V_57 = F_7 ( V_12 ) ;
if ( V_28 )
V_57 |= V_104 ;
else
V_57 &= ~ V_104 ;
F_26 ( V_57 , V_12 ) ;
F_25 ( & V_3 -> V_55 , V_54 ) ;
}
}
static int F_41 ( struct V_101 * V_102 , unsigned V_20 )
{
return F_42 ( V_102 -> V_105 + V_20 ) ;
}
static int F_43 ( struct V_101 * V_102 , unsigned V_20 ,
int V_28 )
{
F_40 ( V_102 , V_20 , V_28 ) ;
return F_44 ( V_102 -> V_105 + V_20 ) ;
}
static void F_45 ( struct V_106 * V_107 )
{
struct V_101 * V_108 = F_46 ( V_107 ) ;
struct V_2 * V_3 = F_39 ( V_108 ) ;
const struct V_1 * V_5 ;
unsigned V_4 = F_47 ( V_107 ) ;
F_48 ( & V_3 -> V_55 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 ) {
unsigned V_13 = F_4 ( V_5 , V_4 ) ;
unsigned V_109 = V_13 % V_5 -> V_24 ;
unsigned V_19 = V_13 / V_5 -> V_24 ;
F_26 ( F_10 ( V_109 ) , V_5 -> V_25 + V_110 + V_19 * 4 ) ;
}
F_49 ( & V_3 -> V_55 ) ;
}
static void F_50 ( struct V_106 * V_107 )
{
struct V_101 * V_108 = F_46 ( V_107 ) ;
struct V_2 * V_3 = F_39 ( V_108 ) ;
const struct V_1 * V_5 ;
unsigned V_4 = F_47 ( V_107 ) ;
unsigned long V_54 ;
F_24 ( & V_3 -> V_55 , V_54 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 ) {
unsigned V_13 = F_4 ( V_5 , V_4 ) ;
unsigned V_24 = V_5 -> V_24 ;
unsigned V_109 = V_13 % V_24 ;
unsigned V_19 = V_13 / V_24 ;
T_3 V_28 ;
F_26 ( F_10 ( V_109 ) , V_5 -> V_25 + V_110 + V_19 * 4 ) ;
V_28 = F_7 ( V_5 -> V_25 + V_5 -> V_111 + V_19 * 4 ) ;
V_28 |= F_10 ( V_109 ) ;
F_26 ( V_28 , V_5 -> V_25 + V_5 -> V_111 + V_19 * 4 ) ;
}
F_25 ( & V_3 -> V_55 , V_54 ) ;
}
static void F_51 ( struct V_106 * V_107 , bool V_112 )
{
struct V_101 * V_108 = F_46 ( V_107 ) ;
struct V_2 * V_3 = F_39 ( V_108 ) ;
const struct V_1 * V_5 ;
unsigned V_4 = F_47 ( V_107 ) ;
unsigned long V_54 ;
F_24 ( & V_3 -> V_55 , V_54 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 ) {
unsigned V_13 = F_4 ( V_5 , V_4 ) ;
unsigned V_109 = V_13 % V_5 -> V_24 ;
unsigned V_19 = V_13 / V_5 -> V_24 ;
void T_1 * V_12 ;
T_3 V_28 ;
V_12 = V_5 -> V_25 + V_5 -> V_111 + V_19 * 4 ;
V_28 = F_7 ( V_12 ) ;
if ( V_112 )
V_28 &= ~ F_10 ( V_109 ) ;
else
V_28 |= F_10 ( V_109 ) ;
F_26 ( V_28 , V_12 ) ;
}
F_25 ( & V_3 -> V_55 , V_54 ) ;
}
static void F_52 ( struct V_106 * V_107 )
{
F_51 ( V_107 , true ) ;
}
static void F_53 ( struct V_106 * V_107 )
{
F_51 ( V_107 , false ) ;
}
static int F_54 ( struct V_106 * V_107 , unsigned type )
{
struct V_101 * V_108 = F_46 ( V_107 ) ;
struct V_2 * V_3 = F_39 ( V_108 ) ;
unsigned V_4 = F_47 ( V_107 ) ;
unsigned long V_54 ;
void T_1 * V_12 ;
T_3 V_28 ;
V_12 = F_3 ( V_3 , V_4 , V_45 ) ;
if ( ! V_12 )
return - V_76 ;
if ( F_9 ( V_3 , V_4 ) ) {
F_2 ( V_3 -> V_11 , L_12 , V_4 ) ;
return - V_113 ;
}
F_24 ( & V_3 -> V_55 , V_54 ) ;
V_28 = F_7 ( V_12 ) ;
V_28 &= ~ ( V_114 | V_115 ) ;
if ( ( type & V_116 ) == V_116 ) {
V_28 |= V_117 << V_118 ;
} else if ( type & V_119 ) {
V_28 |= V_120 << V_118 ;
V_28 |= V_115 ;
} else if ( type & V_121 ) {
V_28 |= V_120 << V_118 ;
} else if ( type & V_122 ) {
if ( type & V_123 )
V_28 |= V_115 ;
} else {
V_28 |= V_124 << V_118 ;
}
F_26 ( V_28 , V_12 ) ;
if ( type & V_116 )
F_55 ( V_107 , V_125 ) ;
else if ( type & V_122 )
F_55 ( V_107 , V_126 ) ;
F_25 ( & V_3 -> V_55 , V_54 ) ;
return 0 ;
}
static int F_56 ( struct V_106 * V_107 , unsigned int V_127 )
{
struct V_101 * V_108 = F_46 ( V_107 ) ;
struct V_2 * V_3 = F_39 ( V_108 ) ;
unsigned V_4 = F_47 ( V_107 ) ;
if ( V_127 )
F_57 ( V_3 -> V_128 ) ;
else
F_58 ( V_3 -> V_128 ) ;
F_59 ( V_3 -> V_11 , L_13 , V_127 ? L_14 : L_15 , V_4 ) ;
return 0 ;
}
static T_4 F_60 ( struct V_2 * V_3 ,
const struct V_1 * V_5 )
{
struct V_101 * V_108 = & V_3 -> V_102 ;
T_4 V_93 = V_129 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_5 -> V_130 ; V_19 ++ ) {
unsigned long V_131 , V_132 , V_109 ;
V_131 = F_7 ( V_5 -> V_25 + V_110 + V_19 * 4 ) ;
V_132 = F_7 ( V_5 -> V_25 + V_5 -> V_111 +
V_19 * 4 ) ;
V_131 &= V_132 ;
F_61 (gpp_offset, &pending, community->gpp_size) {
unsigned V_13 , V_128 ;
V_13 = V_109 + V_19 * V_5 -> V_24 ;
if ( V_13 >= V_5 -> V_10 )
break;
V_128 = F_62 ( V_108 -> V_133 ,
V_5 -> V_9 + V_13 ) ;
F_63 ( V_128 ) ;
V_93 |= V_134 ;
}
}
return V_93 ;
}
static T_4 F_64 ( int V_128 , void * V_135 )
{
const struct V_1 * V_5 ;
struct V_2 * V_3 = V_135 ;
T_4 V_93 = V_129 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ ) {
V_5 = & V_3 -> V_8 [ V_6 ] ;
V_93 |= F_60 ( V_3 , V_5 ) ;
}
return V_93 ;
}
static int F_65 ( struct V_2 * V_3 , int V_128 )
{
int V_93 ;
V_3 -> V_102 = V_136 ;
V_3 -> V_102 . V_137 = V_3 -> V_32 -> V_10 ;
V_3 -> V_102 . V_138 = F_66 ( V_3 -> V_11 ) ;
V_3 -> V_102 . V_139 = V_3 -> V_11 ;
V_3 -> V_102 . V_105 = - 1 ;
V_3 -> V_128 = V_128 ;
V_93 = F_67 ( V_3 -> V_11 , & V_3 -> V_102 , V_3 ) ;
if ( V_93 ) {
F_68 ( V_3 -> V_11 , L_16 ) ;
return V_93 ;
}
V_93 = F_69 ( & V_3 -> V_102 , F_66 ( V_3 -> V_11 ) ,
0 , 0 , V_3 -> V_32 -> V_10 ) ;
if ( V_93 ) {
F_68 ( V_3 -> V_11 , L_17 ) ;
return V_93 ;
}
V_93 = F_70 ( V_3 -> V_11 , V_128 , F_64 ,
V_140 | V_141 ,
F_66 ( V_3 -> V_11 ) , V_3 ) ;
if ( V_93 ) {
F_68 ( V_3 -> V_11 , L_18 ) ;
return V_93 ;
}
V_93 = F_71 ( & V_3 -> V_102 , & V_142 , 0 ,
V_143 , V_144 ) ;
if ( V_93 ) {
F_68 ( V_3 -> V_11 , L_19 ) ;
return V_93 ;
}
F_72 ( & V_3 -> V_102 , & V_142 , V_128 ,
NULL ) ;
return 0 ;
}
static int F_73 ( struct V_2 * V_3 )
{
#ifdef F_74
const struct V_145 * V_32 = V_3 -> V_32 ;
struct V_146 * V_8 ;
struct V_147 * V_148 ;
int V_6 ;
V_148 = F_75 ( V_3 -> V_11 , V_32 -> V_10 , sizeof( * V_148 ) , V_149 ) ;
if ( ! V_148 )
return - V_150 ;
V_8 = F_75 ( V_3 -> V_11 , V_3 -> V_7 ,
sizeof( * V_8 ) , V_149 ) ;
if ( ! V_8 )
return - V_150 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ ) {
struct V_1 * V_5 = & V_3 -> V_8 [ V_6 ] ;
T_3 * V_151 ;
V_151 = F_75 ( V_3 -> V_11 , V_5 -> V_130 ,
sizeof( * V_151 ) , V_149 ) ;
if ( ! V_151 )
return - V_150 ;
V_8 [ V_6 ] . V_151 = V_151 ;
}
V_3 -> V_152 . V_148 = V_148 ;
V_3 -> V_152 . V_8 = V_8 ;
#endif
return 0 ;
}
int F_76 ( struct V_153 * V_154 ,
const struct V_145 * V_155 )
{
struct V_2 * V_3 ;
int V_6 , V_93 , V_128 ;
if ( ! V_155 )
return - V_76 ;
V_3 = F_77 ( & V_154 -> V_11 , sizeof( * V_3 ) , V_149 ) ;
if ( ! V_3 )
return - V_150 ;
V_3 -> V_11 = & V_154 -> V_11 ;
V_3 -> V_32 = V_155 ;
F_78 ( & V_3 -> V_55 ) ;
V_3 -> V_7 = V_3 -> V_32 -> V_7 ;
V_3 -> V_8 = F_75 ( & V_154 -> V_11 , V_3 -> V_7 ,
sizeof( * V_3 -> V_8 ) , V_149 ) ;
if ( ! V_3 -> V_8 )
return - V_150 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ ) {
struct V_1 * V_5 = & V_3 -> V_8 [ V_6 ] ;
struct V_156 * V_157 ;
void T_1 * V_25 ;
T_3 V_158 ;
* V_5 = V_3 -> V_32 -> V_8 [ V_6 ] ;
V_157 = F_79 ( V_154 , V_159 ,
V_5 -> V_160 ) ;
V_25 = F_80 ( & V_154 -> V_11 , V_157 ) ;
if ( F_81 ( V_25 ) )
return F_82 ( V_25 ) ;
if ( ! V_5 -> V_15 ) {
T_3 V_161 ;
V_161 = ( F_7 ( V_25 + V_162 ) & V_163 ) >> V_164 ;
if ( V_161 >= 0x94 ) {
V_5 -> V_15 |= V_16 ;
V_5 -> V_15 |= V_84 ;
}
}
V_158 = F_7 ( V_25 + V_165 ) ;
V_5 -> V_25 = V_25 ;
V_5 -> V_18 = V_25 + V_158 ;
V_5 -> V_130 = F_83 ( V_5 -> V_10 ,
V_5 -> V_24 ) ;
}
V_128 = F_84 ( V_154 , 0 ) ;
if ( V_128 < 0 ) {
F_68 ( & V_154 -> V_11 , L_20 ) ;
return V_128 ;
}
V_93 = F_73 ( V_3 ) ;
if ( V_93 )
return V_93 ;
V_3 -> V_166 = V_167 ;
V_3 -> V_166 . V_35 = F_66 ( & V_154 -> V_11 ) ;
V_3 -> V_166 . V_36 = V_3 -> V_32 -> V_36 ;
V_3 -> V_166 . V_10 = V_3 -> V_32 -> V_10 ;
V_3 -> V_31 = F_85 ( & V_154 -> V_11 , & V_3 -> V_166 ,
V_3 ) ;
if ( F_81 ( V_3 -> V_31 ) ) {
F_68 ( & V_154 -> V_11 , L_21 ) ;
return F_82 ( V_3 -> V_31 ) ;
}
V_93 = F_65 ( V_3 , V_128 ) ;
if ( V_93 )
return V_93 ;
F_86 ( V_154 , V_3 ) ;
return 0 ;
}
static bool F_87 ( struct V_2 * V_3 , unsigned V_4 )
{
const struct V_168 * V_169 = F_88 ( V_3 -> V_31 , V_4 ) ;
if ( ! V_169 || ! F_12 ( V_3 , V_4 ) )
return false ;
if ( V_169 -> V_170 || V_169 -> V_171 ||
F_89 ( & V_3 -> V_102 , V_4 ) )
return true ;
return false ;
}
int F_90 ( struct V_172 * V_11 )
{
struct V_153 * V_154 = F_91 ( V_11 ) ;
struct V_2 * V_3 = F_92 ( V_154 ) ;
struct V_146 * V_8 ;
struct V_147 * V_148 ;
int V_6 ;
V_148 = V_3 -> V_152 . V_148 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_32 -> V_10 ; V_6 ++ ) {
const struct V_173 * V_174 = & V_3 -> V_32 -> V_36 [ V_6 ] ;
void T_1 * V_39 ;
T_3 V_175 ;
if ( ! F_87 ( V_3 , V_174 -> V_176 ) )
continue;
V_175 = F_7 ( F_3 ( V_3 , V_174 -> V_176 , V_45 ) ) ;
V_148 [ V_6 ] . V_57 = V_175 & ~ V_103 ;
V_175 = F_7 ( F_3 ( V_3 , V_174 -> V_176 , V_46 ) ) ;
V_148 [ V_6 ] . V_92 = V_175 ;
V_39 = F_3 ( V_3 , V_174 -> V_176 , V_17 ) ;
if ( V_39 )
V_148 [ V_6 ] . V_86 = F_7 ( V_39 ) ;
}
V_8 = V_3 -> V_152 . V_8 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ ) {
struct V_1 * V_5 = & V_3 -> V_8 [ V_6 ] ;
void T_1 * V_105 ;
unsigned V_19 ;
V_105 = V_5 -> V_25 + V_5 -> V_111 ;
for ( V_19 = 0 ; V_19 < V_5 -> V_130 ; V_19 ++ )
V_8 [ V_6 ] . V_151 [ V_19 ] = F_7 ( V_105 + V_19 * 4 ) ;
}
return 0 ;
}
static void F_93 ( struct V_2 * V_3 )
{
T_2 V_6 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ ) {
const struct V_1 * V_5 ;
void T_1 * V_105 ;
unsigned V_19 ;
V_5 = & V_3 -> V_8 [ V_6 ] ;
V_105 = V_5 -> V_25 ;
for ( V_19 = 0 ; V_19 < V_5 -> V_130 ; V_19 ++ ) {
F_26 ( 0 , V_105 + V_5 -> V_111 + V_19 * 4 ) ;
F_26 ( 0xffff , V_105 + V_110 + V_19 * 4 ) ;
}
}
}
int F_94 ( struct V_172 * V_11 )
{
struct V_153 * V_154 = F_91 ( V_11 ) ;
struct V_2 * V_3 = F_92 ( V_154 ) ;
const struct V_146 * V_8 ;
const struct V_147 * V_148 ;
int V_6 ;
F_93 ( V_3 ) ;
V_148 = V_3 -> V_152 . V_148 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_32 -> V_10 ; V_6 ++ ) {
const struct V_173 * V_174 = & V_3 -> V_32 -> V_36 [ V_6 ] ;
void T_1 * V_39 ;
T_3 V_175 ;
if ( ! F_87 ( V_3 , V_174 -> V_176 ) )
continue;
V_39 = F_3 ( V_3 , V_174 -> V_176 , V_45 ) ;
V_175 = F_7 ( V_39 ) & ~ V_103 ;
if ( V_175 != V_148 [ V_6 ] . V_57 ) {
F_26 ( V_148 [ V_6 ] . V_57 , V_39 ) ;
F_59 ( V_11 , L_22 ,
V_174 -> V_176 , F_7 ( V_39 ) ) ;
}
V_39 = F_3 ( V_3 , V_174 -> V_176 , V_46 ) ;
V_175 = F_7 ( V_39 ) ;
if ( V_175 != V_148 [ V_6 ] . V_92 ) {
F_26 ( V_148 [ V_6 ] . V_92 , V_39 ) ;
F_59 ( V_11 , L_23 ,
V_174 -> V_176 , F_7 ( V_39 ) ) ;
}
V_39 = F_3 ( V_3 , V_174 -> V_176 , V_17 ) ;
if ( V_39 ) {
V_175 = F_7 ( V_39 ) ;
if ( V_175 != V_148 [ V_6 ] . V_86 ) {
F_26 ( V_148 [ V_6 ] . V_86 , V_39 ) ;
F_59 ( V_11 , L_24 ,
V_174 -> V_176 , F_7 ( V_39 ) ) ;
}
}
}
V_8 = V_3 -> V_152 . V_8 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ ) {
struct V_1 * V_5 = & V_3 -> V_8 [ V_6 ] ;
void T_1 * V_105 ;
unsigned V_19 ;
V_105 = V_5 -> V_25 + V_5 -> V_111 ;
for ( V_19 = 0 ; V_19 < V_5 -> V_130 ; V_19 ++ ) {
F_26 ( V_8 [ V_6 ] . V_151 [ V_19 ] , V_105 + V_19 * 4 ) ;
F_59 ( V_11 , L_25 , V_6 , V_19 ,
F_7 ( V_105 + V_19 * 4 ) ) ;
}
}
return 0 ;
}

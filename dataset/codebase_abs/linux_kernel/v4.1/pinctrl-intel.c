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
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 )
return NULL ;
V_13 = F_4 ( V_5 , V_4 ) ;
return V_5 -> V_14 + V_12 + V_13 * 8 ;
}
static bool F_5 ( struct V_2 * V_3 , unsigned V_4 )
{
const struct V_1 * V_5 ;
unsigned V_13 , V_15 , V_16 , V_17 ;
void T_1 * V_18 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 )
return false ;
if ( ! V_5 -> V_19 )
return true ;
V_13 = F_4 ( V_5 , V_4 ) ;
V_15 = V_13 / V_20 ;
V_16 = V_13 % V_20 ;
V_17 = V_5 -> V_19 + V_15 * 16 + ( V_16 / 8 ) * 4 ;
V_18 = V_5 -> V_21 + V_17 ;
return ! ( F_6 ( V_18 ) & F_7 ( V_13 ) ) ;
}
static bool F_8 ( struct V_2 * V_3 ,
unsigned V_4 )
{
const struct V_1 * V_5 ;
unsigned V_13 , V_15 , V_17 ;
void T_1 * V_22 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 )
return true ;
if ( ! V_5 -> V_23 )
return false ;
V_13 = F_4 ( V_5 , V_4 ) ;
V_15 = V_13 / V_20 ;
V_17 = V_5 -> V_23 + V_15 * 4 ;
V_22 = V_5 -> V_21 + V_17 ;
return ! ( F_6 ( V_22 ) & F_9 ( V_13 % V_20 ) ) ;
}
static bool F_10 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_5 ;
unsigned V_13 , V_15 , V_17 ;
T_2 V_24 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 )
return true ;
if ( ! V_5 -> V_25 )
return false ;
V_13 = F_4 ( V_5 , V_4 ) ;
V_15 = V_13 / V_20 ;
V_17 = V_5 -> V_25 + V_15 * 8 ;
V_24 = F_6 ( V_5 -> V_21 + V_17 ) ;
if ( V_24 & F_9 ( V_4 % V_20 ) )
return true ;
V_17 = V_5 -> V_25 + 4 + V_15 * 8 ;
V_24 = F_6 ( V_5 -> V_21 + V_17 ) ;
if ( V_24 & F_9 ( V_4 % V_20 ) )
return true ;
return false ;
}
static bool F_11 ( struct V_2 * V_3 , unsigned V_4 )
{
return F_5 ( V_3 , V_4 ) &&
! F_8 ( V_3 , V_4 ) &&
! F_10 ( V_3 , V_4 ) ;
}
static int F_12 ( struct V_26 * V_27 )
{
struct V_2 * V_3 = F_13 ( V_27 ) ;
return V_3 -> V_28 -> V_29 ;
}
static const char * F_14 ( struct V_26 * V_27 ,
unsigned V_30 )
{
struct V_2 * V_3 = F_13 ( V_27 ) ;
return V_3 -> V_28 -> V_31 [ V_30 ] . V_32 ;
}
static int F_15 ( struct V_26 * V_27 , unsigned V_30 ,
const unsigned * * V_33 , unsigned * V_10 )
{
struct V_2 * V_3 = F_13 ( V_27 ) ;
* V_33 = V_3 -> V_28 -> V_31 [ V_30 ] . V_33 ;
* V_10 = V_3 -> V_28 -> V_31 [ V_30 ] . V_10 ;
return 0 ;
}
static void F_16 ( struct V_26 * V_27 , struct V_34 * V_35 ,
unsigned V_4 )
{
struct V_2 * V_3 = F_13 ( V_27 ) ;
T_2 V_36 , V_37 , V_38 ;
bool V_39 , V_40 ;
if ( ! F_5 ( V_3 , V_4 ) ) {
F_17 ( V_35 , L_2 ) ;
return;
}
V_36 = F_6 ( F_3 ( V_3 , V_4 , V_41 ) ) ;
V_37 = F_6 ( F_3 ( V_3 , V_4 , V_42 ) ) ;
V_38 = ( V_36 & V_43 ) >> V_44 ;
if ( ! V_38 )
F_17 ( V_35 , L_3 ) ;
else
F_18 ( V_35 , L_4 , V_38 ) ;
F_18 ( V_35 , L_5 , V_36 , V_37 ) ;
V_39 = F_10 ( V_3 , V_4 ) ;
V_40 = F_8 ( V_3 , V_4 ) ;
if ( V_39 || V_40 ) {
F_17 ( V_35 , L_6 ) ;
if ( V_39 ) {
F_17 ( V_35 , L_7 ) ;
if ( V_40 )
F_17 ( V_35 , L_8 ) ;
}
if ( V_40 )
F_17 ( V_35 , L_9 ) ;
F_17 ( V_35 , L_10 ) ;
}
}
static int F_19 ( struct V_26 * V_27 )
{
struct V_2 * V_3 = F_13 ( V_27 ) ;
return V_3 -> V_28 -> V_45 ;
}
static const char * F_20 ( struct V_26 * V_27 ,
unsigned V_46 )
{
struct V_2 * V_3 = F_13 ( V_27 ) ;
return V_3 -> V_28 -> V_47 [ V_46 ] . V_32 ;
}
static int F_21 ( struct V_26 * V_27 ,
unsigned V_46 ,
const char * const * * V_31 ,
unsigned * const V_29 )
{
struct V_2 * V_3 = F_13 ( V_27 ) ;
* V_31 = V_3 -> V_28 -> V_47 [ V_46 ] . V_31 ;
* V_29 = V_3 -> V_28 -> V_47 [ V_46 ] . V_29 ;
return 0 ;
}
static int F_22 ( struct V_26 * V_27 , unsigned V_46 ,
unsigned V_30 )
{
struct V_2 * V_3 = F_13 ( V_27 ) ;
const struct V_48 * V_49 = & V_3 -> V_28 -> V_31 [ V_30 ] ;
unsigned long V_50 ;
int V_6 ;
F_23 ( & V_3 -> V_51 , V_50 ) ;
for ( V_6 = 0 ; V_6 < V_49 -> V_10 ; V_6 ++ ) {
if ( ! F_11 ( V_3 , V_49 -> V_33 [ V_6 ] ) ) {
F_24 ( & V_3 -> V_51 , V_50 ) ;
return - V_52 ;
}
}
for ( V_6 = 0 ; V_6 < V_49 -> V_10 ; V_6 ++ ) {
void T_1 * V_53 ;
T_2 V_24 ;
V_53 = F_3 ( V_3 , V_49 -> V_33 [ V_6 ] , V_41 ) ;
V_24 = F_6 ( V_53 ) ;
V_24 &= ~ V_43 ;
V_24 |= V_49 -> V_38 << V_44 ;
F_25 ( V_24 , V_53 ) ;
}
F_24 ( & V_3 -> V_51 , V_50 ) ;
return 0 ;
}
static int F_26 ( struct V_26 * V_27 ,
struct V_54 * V_55 ,
unsigned V_4 )
{
struct V_2 * V_3 = F_13 ( V_27 ) ;
void T_1 * V_53 ;
unsigned long V_50 ;
T_2 V_24 ;
F_23 ( & V_3 -> V_51 , V_50 ) ;
if ( ! F_11 ( V_3 , V_4 ) ) {
F_24 ( & V_3 -> V_51 , V_50 ) ;
return - V_52 ;
}
V_53 = F_3 ( V_3 , V_4 , V_41 ) ;
V_24 = F_6 ( V_53 ) & ~ V_43 ;
V_24 &= ~ ( V_56 | V_57 ) ;
V_24 &= ~ ( V_58 | V_59 ) ;
V_24 &= ~ V_60 ;
V_24 |= V_61 ;
F_25 ( V_24 , V_53 ) ;
F_24 ( & V_3 -> V_51 , V_50 ) ;
return 0 ;
}
static int F_27 ( struct V_26 * V_27 ,
struct V_54 * V_55 ,
unsigned V_4 , bool V_62 )
{
struct V_2 * V_3 = F_13 ( V_27 ) ;
void T_1 * V_53 ;
unsigned long V_50 ;
T_2 V_24 ;
F_23 ( & V_3 -> V_51 , V_50 ) ;
V_53 = F_3 ( V_3 , V_4 , V_41 ) ;
V_24 = F_6 ( V_53 ) ;
if ( V_62 )
V_24 |= V_61 ;
else
V_24 &= ~ V_61 ;
F_25 ( V_24 , V_53 ) ;
F_24 ( & V_3 -> V_51 , V_50 ) ;
return 0 ;
}
static int F_28 ( struct V_26 * V_27 , unsigned V_4 ,
unsigned long * V_63 )
{
struct V_2 * V_3 = F_13 ( V_27 ) ;
enum V_64 V_65 = F_29 ( * V_63 ) ;
T_2 V_24 , V_66 ;
T_3 V_67 = 0 ;
if ( ! F_5 ( V_3 , V_4 ) )
return - V_68 ;
V_24 = F_6 ( F_3 ( V_3 , V_4 , V_42 ) ) ;
V_66 = ( V_24 & V_69 ) >> V_70 ;
switch ( V_65 ) {
case V_71 :
if ( V_66 )
return - V_72 ;
break;
case V_73 :
if ( ! V_66 || ! ( V_24 & V_74 ) )
return - V_72 ;
switch ( V_66 ) {
case V_75 :
V_67 = 1000 ;
break;
case V_76 :
V_67 = 2000 ;
break;
case V_77 :
V_67 = 5000 ;
break;
case V_78 :
V_67 = 20000 ;
break;
}
break;
case V_79 :
if ( ! V_66 || V_24 & V_74 )
return - V_72 ;
switch ( V_66 ) {
case V_77 :
V_67 = 5000 ;
break;
case V_78 :
V_67 = 20000 ;
break;
}
break;
default:
return - V_68 ;
}
* V_63 = F_30 ( V_65 , V_67 ) ;
return 0 ;
}
static int F_31 ( struct V_2 * V_3 , unsigned V_4 ,
unsigned long V_63 )
{
unsigned V_65 = F_29 ( V_63 ) ;
unsigned V_67 = F_32 ( V_63 ) ;
void T_1 * V_80 ;
unsigned long V_50 ;
int V_81 = 0 ;
T_2 V_24 ;
F_23 ( & V_3 -> V_51 , V_50 ) ;
V_80 = F_3 ( V_3 , V_4 , V_42 ) ;
V_24 = F_6 ( V_80 ) ;
switch ( V_65 ) {
case V_71 :
V_24 &= ~ ( V_69 | V_74 ) ;
break;
case V_73 :
V_24 &= ~ V_69 ;
V_24 |= V_74 ;
switch ( V_67 ) {
case 20000 :
V_24 |= V_78 << V_70 ;
break;
case 5000 :
V_24 |= V_77 << V_70 ;
break;
case 2000 :
V_24 |= V_76 << V_70 ;
break;
case 1000 :
V_24 |= V_75 << V_70 ;
break;
default:
V_81 = - V_72 ;
}
break;
case V_79 :
V_24 &= ~ ( V_74 | V_69 ) ;
switch ( V_67 ) {
case 20000 :
V_24 |= V_78 << V_70 ;
break;
case 5000 :
V_24 |= V_77 << V_70 ;
break;
default:
V_81 = - V_72 ;
}
break;
}
if ( ! V_81 )
F_25 ( V_24 , V_80 ) ;
F_24 ( & V_3 -> V_51 , V_50 ) ;
return V_81 ;
}
static int F_33 ( struct V_26 * V_27 , unsigned V_4 ,
unsigned long * V_82 , unsigned V_83 )
{
struct V_2 * V_3 = F_13 ( V_27 ) ;
int V_6 , V_81 ;
if ( ! F_11 ( V_3 , V_4 ) )
return - V_68 ;
for ( V_6 = 0 ; V_6 < V_83 ; V_6 ++ ) {
switch ( F_29 ( V_82 [ V_6 ] ) ) {
case V_71 :
case V_73 :
case V_79 :
V_81 = F_31 ( V_3 , V_4 , V_82 [ V_6 ] ) ;
if ( V_81 )
return V_81 ;
break;
default:
return - V_68 ;
}
}
return 0 ;
}
static int F_34 ( struct V_84 * V_85 , unsigned V_17 )
{
return F_35 ( V_85 -> V_86 + V_17 ) ;
}
static void F_36 ( struct V_84 * V_85 , unsigned V_17 )
{
F_37 ( V_85 -> V_86 + V_17 ) ;
}
static int F_38 ( struct V_84 * V_85 , unsigned V_17 )
{
struct V_2 * V_3 = F_39 ( V_85 ) ;
void T_1 * V_12 ;
V_12 = F_3 ( V_3 , V_17 , V_41 ) ;
if ( ! V_12 )
return - V_72 ;
return ! ! ( F_6 ( V_12 ) & V_87 ) ;
}
static void F_40 ( struct V_84 * V_85 , unsigned V_17 , int V_24 )
{
struct V_2 * V_3 = F_39 ( V_85 ) ;
void T_1 * V_12 ;
V_12 = F_3 ( V_3 , V_17 , V_41 ) ;
if ( V_12 ) {
unsigned long V_50 ;
T_2 V_53 ;
F_23 ( & V_3 -> V_51 , V_50 ) ;
V_53 = F_6 ( V_12 ) ;
if ( V_24 )
V_53 |= V_88 ;
else
V_53 &= ~ V_88 ;
F_25 ( V_53 , V_12 ) ;
F_24 ( & V_3 -> V_51 , V_50 ) ;
}
}
static int F_41 ( struct V_84 * V_85 , unsigned V_17 )
{
return F_42 ( V_85 -> V_86 + V_17 ) ;
}
static int F_43 ( struct V_84 * V_85 , unsigned V_17 ,
int V_24 )
{
F_40 ( V_85 , V_17 , V_24 ) ;
return F_44 ( V_85 -> V_86 + V_17 ) ;
}
static void F_45 ( struct V_89 * V_90 )
{
struct V_84 * V_91 = F_46 ( V_90 ) ;
struct V_2 * V_3 = F_39 ( V_91 ) ;
const struct V_1 * V_5 ;
unsigned V_4 = F_47 ( V_90 ) ;
F_48 ( & V_3 -> V_51 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 ) {
unsigned V_13 = F_4 ( V_5 , V_4 ) ;
unsigned V_16 = V_13 % V_20 ;
unsigned V_15 = V_13 / V_20 ;
F_25 ( F_9 ( V_16 ) , V_5 -> V_21 + V_92 + V_15 * 4 ) ;
}
F_49 ( & V_3 -> V_51 ) ;
}
static void F_50 ( struct V_89 * V_90 , bool V_93 )
{
struct V_84 * V_91 = F_46 ( V_90 ) ;
struct V_2 * V_3 = F_39 ( V_91 ) ;
const struct V_1 * V_5 ;
unsigned V_4 = F_47 ( V_90 ) ;
unsigned long V_50 ;
F_23 ( & V_3 -> V_51 , V_50 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 ) {
unsigned V_13 = F_4 ( V_5 , V_4 ) ;
unsigned V_16 = V_13 % V_20 ;
unsigned V_15 = V_13 / V_20 ;
void T_1 * V_12 ;
T_2 V_24 ;
V_12 = V_5 -> V_21 + V_5 -> V_94 + V_15 * 4 ;
V_24 = F_6 ( V_12 ) ;
if ( V_93 )
V_24 &= ~ F_9 ( V_16 ) ;
else
V_24 |= F_9 ( V_16 ) ;
F_25 ( V_24 , V_12 ) ;
}
F_24 ( & V_3 -> V_51 , V_50 ) ;
}
static void F_51 ( struct V_89 * V_90 )
{
F_50 ( V_90 , true ) ;
}
static void F_52 ( struct V_89 * V_90 )
{
F_50 ( V_90 , false ) ;
}
static int F_53 ( struct V_89 * V_90 , unsigned type )
{
struct V_84 * V_91 = F_46 ( V_90 ) ;
struct V_2 * V_3 = F_39 ( V_91 ) ;
unsigned V_4 = F_47 ( V_90 ) ;
unsigned long V_50 ;
void T_1 * V_12 ;
T_2 V_24 ;
V_12 = F_3 ( V_3 , V_4 , V_41 ) ;
if ( ! V_12 )
return - V_72 ;
F_23 ( & V_3 -> V_51 , V_50 ) ;
V_24 = F_6 ( V_12 ) ;
V_24 &= ~ ( V_95 | V_96 ) ;
if ( ( type & V_97 ) == V_97 ) {
V_24 |= V_98 << V_99 ;
} else if ( type & V_100 ) {
V_24 |= V_101 << V_99 ;
V_24 |= V_96 ;
} else if ( type & V_102 ) {
V_24 |= V_101 << V_99 ;
} else if ( type & V_103 ) {
V_24 |= V_96 ;
} else {
V_24 |= V_104 << V_99 ;
}
F_25 ( V_24 , V_12 ) ;
if ( type & V_97 )
F_54 ( V_90 -> V_105 , V_106 ) ;
else if ( type & V_107 )
F_54 ( V_90 -> V_105 , V_108 ) ;
F_24 ( & V_3 -> V_51 , V_50 ) ;
return 0 ;
}
static int F_55 ( struct V_89 * V_90 , unsigned int V_109 )
{
struct V_84 * V_91 = F_46 ( V_90 ) ;
struct V_2 * V_3 = F_39 ( V_91 ) ;
const struct V_1 * V_5 ;
unsigned V_4 = F_47 ( V_90 ) ;
unsigned V_13 , V_15 , V_16 ;
T_2 V_110 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 )
return - V_72 ;
V_13 = F_4 ( V_5 , V_4 ) ;
V_15 = V_13 / V_20 ;
V_16 = V_13 % V_20 ;
F_25 ( F_9 ( V_16 ) , V_5 -> V_21 + V_111 + V_15 * 4 ) ;
V_110 = F_6 ( V_5 -> V_21 + V_112 + V_15 * 4 ) ;
if ( V_109 )
V_110 |= F_9 ( V_16 ) ;
else
V_110 &= ~ F_9 ( V_16 ) ;
F_25 ( V_110 , V_5 -> V_21 + V_112 + V_15 * 4 ) ;
F_56 ( V_3 -> V_11 , L_11 , V_109 ? L_12 : L_13 , V_4 ) ;
return 0 ;
}
static void F_57 ( struct V_84 * V_91 ,
const struct V_1 * V_5 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_5 -> V_113 ; V_15 ++ ) {
unsigned long V_114 , V_115 , V_16 ;
V_114 = F_6 ( V_5 -> V_21 + V_92 + V_15 * 4 ) ;
V_115 = F_6 ( V_5 -> V_21 + V_5 -> V_94 +
V_15 * 4 ) ;
V_114 &= V_115 ;
F_58 (gpp_offset, &pending, NPADS_IN_GPP) {
unsigned V_13 , V_105 ;
V_13 = V_16 + V_15 * V_20 ;
if ( V_13 >= V_5 -> V_10 )
break;
V_105 = F_59 ( V_91 -> V_116 ,
V_5 -> V_9 + V_13 ) ;
F_60 ( V_105 ) ;
}
}
}
static void F_61 ( unsigned V_105 , struct V_117 * V_118 )
{
struct V_84 * V_91 = F_62 ( V_118 ) ;
struct V_2 * V_3 = F_39 ( V_91 ) ;
struct V_119 * V_85 = F_63 ( V_105 ) ;
int V_6 ;
F_64 ( V_85 , V_118 ) ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ )
F_57 ( V_91 , & V_3 -> V_8 [ V_6 ] ) ;
F_65 ( V_85 , V_118 ) ;
}
static void F_66 ( struct V_2 * V_3 )
{
T_4 V_6 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ ) {
const struct V_1 * V_5 ;
void T_1 * V_86 ;
unsigned V_15 ;
V_5 = & V_3 -> V_8 [ V_6 ] ;
V_86 = V_5 -> V_21 ;
for ( V_15 = 0 ; V_15 < V_5 -> V_113 ; V_15 ++ ) {
F_25 ( 0 , V_86 + V_5 -> V_94 + V_15 * 4 ) ;
F_25 ( 0xffff , V_86 + V_92 + V_15 * 4 ) ;
}
}
}
static int F_67 ( struct V_2 * V_3 , int V_105 )
{
int V_81 ;
V_3 -> V_85 = V_120 ;
V_3 -> V_85 . V_121 = V_3 -> V_28 -> V_10 ;
V_3 -> V_85 . V_122 = F_68 ( V_3 -> V_11 ) ;
V_3 -> V_85 . V_11 = V_3 -> V_11 ;
V_3 -> V_85 . V_86 = - 1 ;
V_81 = F_69 ( & V_3 -> V_85 ) ;
if ( V_81 ) {
F_70 ( V_3 -> V_11 , L_14 ) ;
return V_81 ;
}
V_81 = F_71 ( & V_3 -> V_85 , F_68 ( V_3 -> V_11 ) ,
0 , 0 , V_3 -> V_28 -> V_10 ) ;
if ( V_81 ) {
F_70 ( V_3 -> V_11 , L_15 ) ;
F_72 ( & V_3 -> V_85 ) ;
return V_81 ;
}
V_81 = F_73 ( & V_3 -> V_85 , & V_123 , 0 ,
V_124 , V_125 ) ;
if ( V_81 ) {
F_70 ( V_3 -> V_11 , L_16 ) ;
F_72 ( & V_3 -> V_85 ) ;
return V_81 ;
}
F_74 ( & V_3 -> V_85 , & V_123 , V_105 ,
F_61 ) ;
return 0 ;
}
static int F_75 ( struct V_2 * V_3 )
{
#ifdef F_76
const struct V_126 * V_28 = V_3 -> V_28 ;
struct V_127 * V_8 ;
struct V_128 * V_129 ;
int V_6 ;
V_129 = F_77 ( V_3 -> V_11 , V_28 -> V_10 , sizeof( * V_129 ) , V_130 ) ;
if ( ! V_129 )
return - V_131 ;
V_8 = F_77 ( V_3 -> V_11 , V_3 -> V_7 ,
sizeof( * V_8 ) , V_130 ) ;
if ( ! V_8 )
return - V_131 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ ) {
struct V_1 * V_5 = & V_3 -> V_8 [ V_6 ] ;
T_2 * V_132 ;
V_132 = F_77 ( V_3 -> V_11 , V_5 -> V_113 ,
sizeof( * V_132 ) , V_130 ) ;
if ( ! V_132 )
return - V_131 ;
V_8 [ V_6 ] . V_132 = V_132 ;
}
V_3 -> V_133 . V_129 = V_129 ;
V_3 -> V_133 . V_8 = V_8 ;
#endif
return 0 ;
}
int F_78 ( struct V_134 * V_135 ,
const struct V_126 * V_136 )
{
struct V_2 * V_3 ;
int V_6 , V_81 , V_105 ;
if ( ! V_136 )
return - V_72 ;
V_3 = F_79 ( & V_135 -> V_11 , sizeof( * V_3 ) , V_130 ) ;
if ( ! V_3 )
return - V_131 ;
V_3 -> V_11 = & V_135 -> V_11 ;
V_3 -> V_28 = V_136 ;
F_80 ( & V_3 -> V_51 ) ;
V_3 -> V_7 = V_3 -> V_28 -> V_7 ;
V_3 -> V_8 = F_77 ( & V_135 -> V_11 , V_3 -> V_7 ,
sizeof( * V_3 -> V_8 ) , V_130 ) ;
if ( ! V_3 -> V_8 )
return - V_131 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ ) {
struct V_1 * V_5 = & V_3 -> V_8 [ V_6 ] ;
struct V_137 * V_138 ;
void T_1 * V_21 ;
T_2 V_139 ;
* V_5 = V_3 -> V_28 -> V_8 [ V_6 ] ;
V_138 = F_81 ( V_135 , V_140 ,
V_5 -> V_141 ) ;
V_21 = F_82 ( & V_135 -> V_11 , V_138 ) ;
if ( F_83 ( V_21 ) )
return F_84 ( V_21 ) ;
V_139 = F_6 ( V_21 + V_142 ) ;
V_5 -> V_21 = V_21 ;
V_5 -> V_14 = V_21 + V_139 ;
V_5 -> V_113 = F_85 ( V_5 -> V_10 , V_20 ) ;
}
V_105 = F_86 ( V_135 , 0 ) ;
if ( V_105 < 0 ) {
F_70 ( & V_135 -> V_11 , L_17 ) ;
return V_105 ;
}
V_81 = F_75 ( V_3 ) ;
if ( V_81 )
return V_81 ;
V_3 -> V_143 = V_144 ;
V_3 -> V_143 . V_32 = F_68 ( & V_135 -> V_11 ) ;
V_3 -> V_143 . V_33 = V_3 -> V_28 -> V_33 ;
V_3 -> V_143 . V_10 = V_3 -> V_28 -> V_10 ;
V_3 -> V_27 = F_87 ( & V_3 -> V_143 , & V_135 -> V_11 , V_3 ) ;
if ( ! V_3 -> V_27 ) {
F_70 ( & V_135 -> V_11 , L_18 ) ;
return - V_145 ;
}
V_81 = F_67 ( V_3 , V_105 ) ;
if ( V_81 ) {
F_88 ( V_3 -> V_27 ) ;
return V_81 ;
}
F_89 ( V_135 , V_3 ) ;
return 0 ;
}
int F_90 ( struct V_134 * V_135 )
{
struct V_2 * V_3 = F_91 ( V_135 ) ;
F_72 ( & V_3 -> V_85 ) ;
F_88 ( V_3 -> V_27 ) ;
return 0 ;
}
int F_92 ( struct V_146 * V_11 )
{
struct V_134 * V_135 = F_93 ( V_11 ) ;
struct V_2 * V_3 = F_91 ( V_135 ) ;
struct V_127 * V_8 ;
struct V_128 * V_129 ;
int V_6 ;
V_129 = V_3 -> V_133 . V_129 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_28 -> V_10 ; V_6 ++ ) {
const struct V_147 * V_118 = & V_3 -> V_28 -> V_33 [ V_6 ] ;
T_2 V_148 ;
if ( ! F_11 ( V_3 , V_118 -> V_149 ) )
continue;
V_148 = F_6 ( F_3 ( V_3 , V_118 -> V_149 , V_41 ) ) ;
V_129 [ V_6 ] . V_53 = V_148 & ~ V_87 ;
V_148 = F_6 ( F_3 ( V_3 , V_118 -> V_149 , V_42 ) ) ;
V_129 [ V_6 ] . V_80 = V_148 ;
}
V_8 = V_3 -> V_133 . V_8 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ ) {
struct V_1 * V_5 = & V_3 -> V_8 [ V_6 ] ;
void T_1 * V_86 ;
unsigned V_15 ;
V_86 = V_5 -> V_21 + V_5 -> V_94 ;
for ( V_15 = 0 ; V_15 < V_5 -> V_113 ; V_15 ++ )
V_8 [ V_6 ] . V_132 [ V_15 ] = F_6 ( V_86 + V_15 * 4 ) ;
}
return 0 ;
}
int F_94 ( struct V_146 * V_11 )
{
struct V_134 * V_135 = F_93 ( V_11 ) ;
struct V_2 * V_3 = F_91 ( V_135 ) ;
const struct V_127 * V_8 ;
const struct V_128 * V_129 ;
int V_6 ;
F_66 ( V_3 ) ;
V_129 = V_3 -> V_133 . V_129 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_28 -> V_10 ; V_6 ++ ) {
const struct V_147 * V_118 = & V_3 -> V_28 -> V_33 [ V_6 ] ;
void T_1 * V_150 ;
T_2 V_148 ;
if ( ! F_11 ( V_3 , V_118 -> V_149 ) )
continue;
V_150 = F_3 ( V_3 , V_118 -> V_149 , V_41 ) ;
V_148 = F_6 ( V_150 ) & ~ V_87 ;
if ( V_148 != V_129 [ V_6 ] . V_53 ) {
F_25 ( V_129 [ V_6 ] . V_53 , V_150 ) ;
F_56 ( V_11 , L_19 ,
V_118 -> V_149 , F_6 ( V_150 ) ) ;
}
V_150 = F_3 ( V_3 , V_118 -> V_149 , V_42 ) ;
V_148 = F_6 ( V_150 ) ;
if ( V_148 != V_129 [ V_6 ] . V_80 ) {
F_25 ( V_129 [ V_6 ] . V_80 , V_150 ) ;
F_56 ( V_11 , L_20 ,
V_118 -> V_149 , F_6 ( V_150 ) ) ;
}
}
V_8 = V_3 -> V_133 . V_8 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ ) {
struct V_1 * V_5 = & V_3 -> V_8 [ V_6 ] ;
void T_1 * V_86 ;
unsigned V_15 ;
V_86 = V_5 -> V_21 + V_5 -> V_94 ;
for ( V_15 = 0 ; V_15 < V_5 -> V_113 ; V_15 ++ ) {
F_25 ( V_8 [ V_6 ] . V_132 [ V_15 ] , V_86 + V_15 * 4 ) ;
F_56 ( V_11 , L_21 , V_6 , V_15 ,
F_6 ( V_86 + V_15 * 4 ) ) ;
}
}
return 0 ;
}

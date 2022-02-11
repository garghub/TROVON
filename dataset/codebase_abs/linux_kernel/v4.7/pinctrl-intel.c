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
V_17 = V_13 / V_5 -> V_20 ;
V_15 = F_6 ( V_13 % V_5 -> V_20 ) ;
V_16 = V_5 -> V_19 + 0x10 * V_17 + V_15 * 4 ;
V_18 = V_5 -> V_21 + V_16 ;
return ! ( F_7 ( V_18 ) & F_8 ( V_13 ) ) ;
}
static bool F_9 ( struct V_2 * V_3 , unsigned V_4 )
{
const struct V_1 * V_5 ;
unsigned V_13 , V_15 , V_16 ;
void T_1 * V_22 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 )
return true ;
if ( ! V_5 -> V_23 )
return false ;
V_13 = F_4 ( V_5 , V_4 ) ;
V_15 = V_13 / V_5 -> V_20 ;
V_16 = V_5 -> V_23 + V_15 * 4 ;
V_22 = V_5 -> V_21 + V_16 ;
return ! ( F_7 ( V_22 ) & F_10 ( V_13 % V_5 -> V_20 ) ) ;
}
static bool F_11 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_5 ;
unsigned V_13 , V_15 , V_16 ;
T_2 V_24 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 )
return true ;
if ( ! V_5 -> V_25 )
return false ;
V_13 = F_4 ( V_5 , V_4 ) ;
V_15 = V_13 / V_5 -> V_20 ;
V_16 = V_5 -> V_25 + V_15 * 8 ;
V_24 = F_7 ( V_5 -> V_21 + V_16 ) ;
if ( V_24 & F_10 ( V_4 % V_5 -> V_20 ) )
return true ;
V_16 = V_5 -> V_25 + 4 + V_15 * 8 ;
V_24 = F_7 ( V_5 -> V_21 + V_16 ) ;
if ( V_24 & F_10 ( V_4 % V_5 -> V_20 ) )
return true ;
return false ;
}
static bool F_12 ( struct V_2 * V_3 , unsigned V_4 )
{
return F_5 ( V_3 , V_4 ) &&
! F_11 ( V_3 , V_4 ) ;
}
static int F_13 ( struct V_26 * V_27 )
{
struct V_2 * V_3 = F_14 ( V_27 ) ;
return V_3 -> V_28 -> V_29 ;
}
static const char * F_15 ( struct V_26 * V_27 ,
unsigned V_17 )
{
struct V_2 * V_3 = F_14 ( V_27 ) ;
return V_3 -> V_28 -> V_30 [ V_17 ] . V_31 ;
}
static int F_16 ( struct V_26 * V_27 , unsigned V_17 ,
const unsigned * * V_32 , unsigned * V_10 )
{
struct V_2 * V_3 = F_14 ( V_27 ) ;
* V_32 = V_3 -> V_28 -> V_30 [ V_17 ] . V_32 ;
* V_10 = V_3 -> V_28 -> V_30 [ V_17 ] . V_10 ;
return 0 ;
}
static void F_17 ( struct V_26 * V_27 , struct V_33 * V_34 ,
unsigned V_4 )
{
struct V_2 * V_3 = F_14 ( V_27 ) ;
T_2 V_35 , V_36 , V_37 ;
bool V_38 , V_39 ;
if ( ! F_5 ( V_3 , V_4 ) ) {
F_18 ( V_34 , L_2 ) ;
return;
}
V_35 = F_7 ( F_3 ( V_3 , V_4 , V_40 ) ) ;
V_36 = F_7 ( F_3 ( V_3 , V_4 , V_41 ) ) ;
V_37 = ( V_35 & V_42 ) >> V_43 ;
if ( ! V_37 )
F_18 ( V_34 , L_3 ) ;
else
F_19 ( V_34 , L_4 , V_37 ) ;
F_19 ( V_34 , L_5 , V_35 , V_36 ) ;
V_38 = F_11 ( V_3 , V_4 ) ;
V_39 = F_9 ( V_3 , V_4 ) ;
if ( V_38 || V_39 ) {
F_18 ( V_34 , L_6 ) ;
if ( V_38 ) {
F_18 ( V_34 , L_7 ) ;
if ( V_39 )
F_18 ( V_34 , L_8 ) ;
}
if ( V_39 )
F_18 ( V_34 , L_9 ) ;
F_18 ( V_34 , L_10 ) ;
}
}
static int F_20 ( struct V_26 * V_27 )
{
struct V_2 * V_3 = F_14 ( V_27 ) ;
return V_3 -> V_28 -> V_44 ;
}
static const char * F_21 ( struct V_26 * V_27 ,
unsigned V_45 )
{
struct V_2 * V_3 = F_14 ( V_27 ) ;
return V_3 -> V_28 -> V_46 [ V_45 ] . V_31 ;
}
static int F_22 ( struct V_26 * V_27 ,
unsigned V_45 ,
const char * const * * V_30 ,
unsigned * const V_29 )
{
struct V_2 * V_3 = F_14 ( V_27 ) ;
* V_30 = V_3 -> V_28 -> V_46 [ V_45 ] . V_30 ;
* V_29 = V_3 -> V_28 -> V_46 [ V_45 ] . V_29 ;
return 0 ;
}
static int F_23 ( struct V_26 * V_27 , unsigned V_45 ,
unsigned V_17 )
{
struct V_2 * V_3 = F_14 ( V_27 ) ;
const struct V_47 * V_48 = & V_3 -> V_28 -> V_30 [ V_17 ] ;
unsigned long V_49 ;
int V_6 ;
F_24 ( & V_3 -> V_50 , V_49 ) ;
for ( V_6 = 0 ; V_6 < V_48 -> V_10 ; V_6 ++ ) {
if ( ! F_12 ( V_3 , V_48 -> V_32 [ V_6 ] ) ) {
F_25 ( & V_3 -> V_50 , V_49 ) ;
return - V_51 ;
}
}
for ( V_6 = 0 ; V_6 < V_48 -> V_10 ; V_6 ++ ) {
void T_1 * V_52 ;
T_2 V_24 ;
V_52 = F_3 ( V_3 , V_48 -> V_32 [ V_6 ] , V_40 ) ;
V_24 = F_7 ( V_52 ) ;
V_24 &= ~ V_42 ;
V_24 |= V_48 -> V_37 << V_43 ;
F_26 ( V_24 , V_52 ) ;
}
F_25 ( & V_3 -> V_50 , V_49 ) ;
return 0 ;
}
static int F_27 ( struct V_26 * V_27 ,
struct V_53 * V_54 ,
unsigned V_4 )
{
struct V_2 * V_3 = F_14 ( V_27 ) ;
void T_1 * V_52 ;
unsigned long V_49 ;
T_2 V_24 ;
F_24 ( & V_3 -> V_50 , V_49 ) ;
if ( ! F_12 ( V_3 , V_4 ) ) {
F_25 ( & V_3 -> V_50 , V_49 ) ;
return - V_51 ;
}
V_52 = F_3 ( V_3 , V_4 , V_40 ) ;
V_24 = F_7 ( V_52 ) & ~ V_42 ;
V_24 &= ~ ( V_55 | V_56 ) ;
V_24 &= ~ ( V_57 | V_58 ) ;
V_24 &= ~ V_59 ;
V_24 |= V_60 ;
F_26 ( V_24 , V_52 ) ;
F_25 ( & V_3 -> V_50 , V_49 ) ;
return 0 ;
}
static int F_28 ( struct V_26 * V_27 ,
struct V_53 * V_54 ,
unsigned V_4 , bool V_61 )
{
struct V_2 * V_3 = F_14 ( V_27 ) ;
void T_1 * V_52 ;
unsigned long V_49 ;
T_2 V_24 ;
F_24 ( & V_3 -> V_50 , V_49 ) ;
V_52 = F_3 ( V_3 , V_4 , V_40 ) ;
V_24 = F_7 ( V_52 ) ;
if ( V_61 )
V_24 |= V_60 ;
else
V_24 &= ~ V_60 ;
F_26 ( V_24 , V_52 ) ;
F_25 ( & V_3 -> V_50 , V_49 ) ;
return 0 ;
}
static int F_29 ( struct V_26 * V_27 , unsigned V_4 ,
unsigned long * V_62 )
{
struct V_2 * V_3 = F_14 ( V_27 ) ;
enum V_63 V_64 = F_30 ( * V_62 ) ;
T_2 V_24 , V_65 ;
T_3 V_66 = 0 ;
if ( ! F_5 ( V_3 , V_4 ) )
return - V_67 ;
V_24 = F_7 ( F_3 ( V_3 , V_4 , V_41 ) ) ;
V_65 = ( V_24 & V_68 ) >> V_69 ;
switch ( V_64 ) {
case V_70 :
if ( V_65 )
return - V_71 ;
break;
case V_72 :
if ( ! V_65 || ! ( V_24 & V_73 ) )
return - V_71 ;
switch ( V_65 ) {
case V_74 :
V_66 = 1000 ;
break;
case V_75 :
V_66 = 2000 ;
break;
case V_76 :
V_66 = 5000 ;
break;
case V_77 :
V_66 = 20000 ;
break;
}
break;
case V_78 :
if ( ! V_65 || V_24 & V_73 )
return - V_71 ;
switch ( V_65 ) {
case V_76 :
V_66 = 5000 ;
break;
case V_77 :
V_66 = 20000 ;
break;
}
break;
default:
return - V_67 ;
}
* V_62 = F_31 ( V_64 , V_66 ) ;
return 0 ;
}
static int F_32 ( struct V_2 * V_3 , unsigned V_4 ,
unsigned long V_62 )
{
unsigned V_64 = F_30 ( V_62 ) ;
unsigned V_66 = F_33 ( V_62 ) ;
void T_1 * V_79 ;
unsigned long V_49 ;
int V_80 = 0 ;
T_2 V_24 ;
F_24 ( & V_3 -> V_50 , V_49 ) ;
V_79 = F_3 ( V_3 , V_4 , V_41 ) ;
V_24 = F_7 ( V_79 ) ;
switch ( V_64 ) {
case V_70 :
V_24 &= ~ ( V_68 | V_73 ) ;
break;
case V_72 :
V_24 &= ~ V_68 ;
V_24 |= V_73 ;
switch ( V_66 ) {
case 20000 :
V_24 |= V_77 << V_69 ;
break;
case 5000 :
V_24 |= V_76 << V_69 ;
break;
case 2000 :
V_24 |= V_75 << V_69 ;
break;
case 1000 :
V_24 |= V_74 << V_69 ;
break;
default:
V_80 = - V_71 ;
}
break;
case V_78 :
V_24 &= ~ ( V_73 | V_68 ) ;
switch ( V_66 ) {
case 20000 :
V_24 |= V_77 << V_69 ;
break;
case 5000 :
V_24 |= V_76 << V_69 ;
break;
default:
V_80 = - V_71 ;
}
break;
}
if ( ! V_80 )
F_26 ( V_24 , V_79 ) ;
F_25 ( & V_3 -> V_50 , V_49 ) ;
return V_80 ;
}
static int F_34 ( struct V_26 * V_27 , unsigned V_4 ,
unsigned long * V_81 , unsigned V_82 )
{
struct V_2 * V_3 = F_14 ( V_27 ) ;
int V_6 , V_80 ;
if ( ! F_12 ( V_3 , V_4 ) )
return - V_67 ;
for ( V_6 = 0 ; V_6 < V_82 ; V_6 ++ ) {
switch ( F_30 ( V_81 [ V_6 ] ) ) {
case V_70 :
case V_72 :
case V_78 :
V_80 = F_32 ( V_3 , V_4 , V_81 [ V_6 ] ) ;
if ( V_80 )
return V_80 ;
break;
default:
return - V_67 ;
}
}
return 0 ;
}
static int F_35 ( struct V_83 * V_84 , unsigned V_16 )
{
struct V_2 * V_3 = F_36 ( V_84 ) ;
void T_1 * V_12 ;
V_12 = F_3 ( V_3 , V_16 , V_40 ) ;
if ( ! V_12 )
return - V_71 ;
return ! ! ( F_7 ( V_12 ) & V_85 ) ;
}
static void F_37 ( struct V_83 * V_84 , unsigned V_16 , int V_24 )
{
struct V_2 * V_3 = F_36 ( V_84 ) ;
void T_1 * V_12 ;
V_12 = F_3 ( V_3 , V_16 , V_40 ) ;
if ( V_12 ) {
unsigned long V_49 ;
T_2 V_52 ;
F_24 ( & V_3 -> V_50 , V_49 ) ;
V_52 = F_7 ( V_12 ) ;
if ( V_24 )
V_52 |= V_86 ;
else
V_52 &= ~ V_86 ;
F_26 ( V_52 , V_12 ) ;
F_25 ( & V_3 -> V_50 , V_49 ) ;
}
}
static int F_38 ( struct V_83 * V_84 , unsigned V_16 )
{
return F_39 ( V_84 -> V_87 + V_16 ) ;
}
static int F_40 ( struct V_83 * V_84 , unsigned V_16 ,
int V_24 )
{
F_37 ( V_84 , V_16 , V_24 ) ;
return F_41 ( V_84 -> V_87 + V_16 ) ;
}
static void F_42 ( struct V_88 * V_89 )
{
struct V_83 * V_90 = F_43 ( V_89 ) ;
struct V_2 * V_3 = F_36 ( V_90 ) ;
const struct V_1 * V_5 ;
unsigned V_4 = F_44 ( V_89 ) ;
F_45 ( & V_3 -> V_50 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 ) {
unsigned V_13 = F_4 ( V_5 , V_4 ) ;
unsigned V_91 = V_13 % V_5 -> V_20 ;
unsigned V_15 = V_13 / V_5 -> V_20 ;
F_26 ( F_10 ( V_91 ) , V_5 -> V_21 + V_92 + V_15 * 4 ) ;
}
F_46 ( & V_3 -> V_50 ) ;
}
static void F_47 ( struct V_88 * V_89 )
{
struct V_83 * V_90 = F_43 ( V_89 ) ;
struct V_2 * V_3 = F_36 ( V_90 ) ;
const struct V_1 * V_5 ;
unsigned V_4 = F_44 ( V_89 ) ;
unsigned long V_49 ;
F_24 ( & V_3 -> V_50 , V_49 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 ) {
unsigned V_13 = F_4 ( V_5 , V_4 ) ;
unsigned V_20 = V_5 -> V_20 ;
unsigned V_91 = V_13 % V_20 ;
unsigned V_15 = V_13 / V_20 ;
T_2 V_24 ;
F_26 ( F_10 ( V_91 ) , V_5 -> V_21 + V_92 + V_15 * 4 ) ;
V_24 = F_7 ( V_5 -> V_21 + V_5 -> V_93 + V_15 * 4 ) ;
V_24 |= F_10 ( V_91 ) ;
F_26 ( V_24 , V_5 -> V_21 + V_5 -> V_93 + V_15 * 4 ) ;
}
F_25 ( & V_3 -> V_50 , V_49 ) ;
}
static void F_48 ( struct V_88 * V_89 , bool V_94 )
{
struct V_83 * V_90 = F_43 ( V_89 ) ;
struct V_2 * V_3 = F_36 ( V_90 ) ;
const struct V_1 * V_5 ;
unsigned V_4 = F_44 ( V_89 ) ;
unsigned long V_49 ;
F_24 ( & V_3 -> V_50 , V_49 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 ) {
unsigned V_13 = F_4 ( V_5 , V_4 ) ;
unsigned V_91 = V_13 % V_5 -> V_20 ;
unsigned V_15 = V_13 / V_5 -> V_20 ;
void T_1 * V_12 ;
T_2 V_24 ;
V_12 = V_5 -> V_21 + V_5 -> V_93 + V_15 * 4 ;
V_24 = F_7 ( V_12 ) ;
if ( V_94 )
V_24 &= ~ F_10 ( V_91 ) ;
else
V_24 |= F_10 ( V_91 ) ;
F_26 ( V_24 , V_12 ) ;
}
F_25 ( & V_3 -> V_50 , V_49 ) ;
}
static void F_49 ( struct V_88 * V_89 )
{
F_48 ( V_89 , true ) ;
}
static void F_50 ( struct V_88 * V_89 )
{
F_48 ( V_89 , false ) ;
}
static int F_51 ( struct V_88 * V_89 , unsigned type )
{
struct V_83 * V_90 = F_43 ( V_89 ) ;
struct V_2 * V_3 = F_36 ( V_90 ) ;
unsigned V_4 = F_44 ( V_89 ) ;
unsigned long V_49 ;
void T_1 * V_12 ;
T_2 V_24 ;
V_12 = F_3 ( V_3 , V_4 , V_40 ) ;
if ( ! V_12 )
return - V_71 ;
if ( F_9 ( V_3 , V_4 ) ) {
F_2 ( V_3 -> V_11 , L_11 , V_4 ) ;
return - V_95 ;
}
F_24 ( & V_3 -> V_50 , V_49 ) ;
V_24 = F_7 ( V_12 ) ;
V_24 &= ~ ( V_96 | V_97 ) ;
if ( ( type & V_98 ) == V_98 ) {
V_24 |= V_99 << V_100 ;
} else if ( type & V_101 ) {
V_24 |= V_102 << V_100 ;
V_24 |= V_97 ;
} else if ( type & V_103 ) {
V_24 |= V_102 << V_100 ;
} else if ( type & V_104 ) {
if ( type & V_105 )
V_24 |= V_97 ;
} else {
V_24 |= V_106 << V_100 ;
}
F_26 ( V_24 , V_12 ) ;
if ( type & V_98 )
F_52 ( V_89 , V_107 ) ;
else if ( type & V_104 )
F_52 ( V_89 , V_108 ) ;
F_25 ( & V_3 -> V_50 , V_49 ) ;
return 0 ;
}
static int F_53 ( struct V_88 * V_89 , unsigned int V_109 )
{
struct V_83 * V_90 = F_43 ( V_89 ) ;
struct V_2 * V_3 = F_36 ( V_90 ) ;
const struct V_1 * V_5 ;
unsigned V_4 = F_44 ( V_89 ) ;
unsigned V_13 , V_15 , V_91 ;
T_2 V_110 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 )
return - V_71 ;
V_13 = F_4 ( V_5 , V_4 ) ;
V_15 = V_13 / V_5 -> V_20 ;
V_91 = V_13 % V_5 -> V_20 ;
F_26 ( F_10 ( V_91 ) , V_5 -> V_21 + V_111 + V_15 * 4 ) ;
V_110 = F_7 ( V_5 -> V_21 + V_112 + V_15 * 4 ) ;
if ( V_109 )
V_110 |= F_10 ( V_91 ) ;
else
V_110 &= ~ F_10 ( V_91 ) ;
F_26 ( V_110 , V_5 -> V_21 + V_112 + V_15 * 4 ) ;
F_54 ( V_3 -> V_11 , L_12 , V_109 ? L_13 : L_14 , V_4 ) ;
return 0 ;
}
static T_4 F_55 ( struct V_2 * V_3 ,
const struct V_1 * V_5 )
{
struct V_83 * V_90 = & V_3 -> V_84 ;
T_4 V_80 = V_113 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_5 -> V_114 ; V_15 ++ ) {
unsigned long V_115 , V_116 , V_91 ;
V_115 = F_7 ( V_5 -> V_21 + V_92 + V_15 * 4 ) ;
V_116 = F_7 ( V_5 -> V_21 + V_5 -> V_93 +
V_15 * 4 ) ;
V_115 &= V_116 ;
F_56 (gpp_offset, &pending, community->gpp_size) {
unsigned V_13 , V_117 ;
V_13 = V_91 + V_15 * V_5 -> V_20 ;
if ( V_13 >= V_5 -> V_10 )
break;
V_117 = F_57 ( V_90 -> V_118 ,
V_5 -> V_9 + V_13 ) ;
F_58 ( V_117 ) ;
V_80 |= V_119 ;
}
}
return V_80 ;
}
static T_4 F_59 ( int V_117 , void * V_120 )
{
const struct V_1 * V_5 ;
struct V_2 * V_3 = V_120 ;
T_4 V_80 = V_113 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ ) {
V_5 = & V_3 -> V_8 [ V_6 ] ;
V_80 |= F_55 ( V_3 , V_5 ) ;
}
return V_80 ;
}
static int F_60 ( struct V_2 * V_3 , int V_117 )
{
int V_80 ;
V_3 -> V_84 = V_121 ;
V_3 -> V_84 . V_122 = V_3 -> V_28 -> V_10 ;
V_3 -> V_84 . V_123 = F_61 ( V_3 -> V_11 ) ;
V_3 -> V_84 . V_124 = V_3 -> V_11 ;
V_3 -> V_84 . V_87 = - 1 ;
V_80 = F_62 ( & V_3 -> V_84 , V_3 ) ;
if ( V_80 ) {
F_63 ( V_3 -> V_11 , L_15 ) ;
return V_80 ;
}
V_80 = F_64 ( & V_3 -> V_84 , F_61 ( V_3 -> V_11 ) ,
0 , 0 , V_3 -> V_28 -> V_10 ) ;
if ( V_80 ) {
F_63 ( V_3 -> V_11 , L_16 ) ;
goto V_125;
}
V_80 = F_65 ( V_3 -> V_11 , V_117 , F_59 , V_126 ,
F_61 ( V_3 -> V_11 ) , V_3 ) ;
if ( V_80 ) {
F_63 ( V_3 -> V_11 , L_17 ) ;
goto V_125;
}
V_80 = F_66 ( & V_3 -> V_84 , & V_127 , 0 ,
V_128 , V_129 ) ;
if ( V_80 ) {
F_63 ( V_3 -> V_11 , L_18 ) ;
goto V_125;
}
F_67 ( & V_3 -> V_84 , & V_127 , V_117 ,
NULL ) ;
return 0 ;
V_125:
F_68 ( & V_3 -> V_84 ) ;
return V_80 ;
}
static int F_69 ( struct V_2 * V_3 )
{
#ifdef F_70
const struct V_130 * V_28 = V_3 -> V_28 ;
struct V_131 * V_8 ;
struct V_132 * V_133 ;
int V_6 ;
V_133 = F_71 ( V_3 -> V_11 , V_28 -> V_10 , sizeof( * V_133 ) , V_134 ) ;
if ( ! V_133 )
return - V_135 ;
V_8 = F_71 ( V_3 -> V_11 , V_3 -> V_7 ,
sizeof( * V_8 ) , V_134 ) ;
if ( ! V_8 )
return - V_135 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ ) {
struct V_1 * V_5 = & V_3 -> V_8 [ V_6 ] ;
T_2 * V_136 ;
V_136 = F_71 ( V_3 -> V_11 , V_5 -> V_114 ,
sizeof( * V_136 ) , V_134 ) ;
if ( ! V_136 )
return - V_135 ;
V_8 [ V_6 ] . V_136 = V_136 ;
}
V_3 -> V_137 . V_133 = V_133 ;
V_3 -> V_137 . V_8 = V_8 ;
#endif
return 0 ;
}
int F_72 ( struct V_138 * V_139 ,
const struct V_130 * V_140 )
{
struct V_2 * V_3 ;
int V_6 , V_80 , V_117 ;
if ( ! V_140 )
return - V_71 ;
V_3 = F_73 ( & V_139 -> V_11 , sizeof( * V_3 ) , V_134 ) ;
if ( ! V_3 )
return - V_135 ;
V_3 -> V_11 = & V_139 -> V_11 ;
V_3 -> V_28 = V_140 ;
F_74 ( & V_3 -> V_50 ) ;
V_3 -> V_7 = V_3 -> V_28 -> V_7 ;
V_3 -> V_8 = F_71 ( & V_139 -> V_11 , V_3 -> V_7 ,
sizeof( * V_3 -> V_8 ) , V_134 ) ;
if ( ! V_3 -> V_8 )
return - V_135 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ ) {
struct V_1 * V_5 = & V_3 -> V_8 [ V_6 ] ;
struct V_141 * V_142 ;
void T_1 * V_21 ;
T_2 V_143 ;
* V_5 = V_3 -> V_28 -> V_8 [ V_6 ] ;
V_142 = F_75 ( V_139 , V_144 ,
V_5 -> V_145 ) ;
V_21 = F_76 ( & V_139 -> V_11 , V_142 ) ;
if ( F_77 ( V_21 ) )
return F_78 ( V_21 ) ;
V_143 = F_7 ( V_21 + V_146 ) ;
V_5 -> V_21 = V_21 ;
V_5 -> V_14 = V_21 + V_143 ;
V_5 -> V_114 = F_79 ( V_5 -> V_10 ,
V_5 -> V_20 ) ;
}
V_117 = F_80 ( V_139 , 0 ) ;
if ( V_117 < 0 ) {
F_63 ( & V_139 -> V_11 , L_19 ) ;
return V_117 ;
}
V_80 = F_69 ( V_3 ) ;
if ( V_80 )
return V_80 ;
V_3 -> V_147 = V_148 ;
V_3 -> V_147 . V_31 = F_61 ( & V_139 -> V_11 ) ;
V_3 -> V_147 . V_32 = V_3 -> V_28 -> V_32 ;
V_3 -> V_147 . V_10 = V_3 -> V_28 -> V_10 ;
V_3 -> V_27 = F_81 ( & V_139 -> V_11 , & V_3 -> V_147 ,
V_3 ) ;
if ( F_77 ( V_3 -> V_27 ) ) {
F_63 ( & V_139 -> V_11 , L_20 ) ;
return F_78 ( V_3 -> V_27 ) ;
}
V_80 = F_60 ( V_3 , V_117 ) ;
if ( V_80 )
return V_80 ;
F_82 ( V_139 , V_3 ) ;
return 0 ;
}
int F_83 ( struct V_138 * V_139 )
{
struct V_2 * V_3 = F_84 ( V_139 ) ;
F_68 ( & V_3 -> V_84 ) ;
return 0 ;
}
int F_85 ( struct V_149 * V_11 )
{
struct V_138 * V_139 = F_86 ( V_11 ) ;
struct V_2 * V_3 = F_84 ( V_139 ) ;
struct V_131 * V_8 ;
struct V_132 * V_133 ;
int V_6 ;
V_133 = V_3 -> V_137 . V_133 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_28 -> V_10 ; V_6 ++ ) {
const struct V_150 * V_151 = & V_3 -> V_28 -> V_32 [ V_6 ] ;
T_2 V_152 ;
if ( ! F_12 ( V_3 , V_151 -> V_153 ) )
continue;
V_152 = F_7 ( F_3 ( V_3 , V_151 -> V_153 , V_40 ) ) ;
V_133 [ V_6 ] . V_52 = V_152 & ~ V_85 ;
V_152 = F_7 ( F_3 ( V_3 , V_151 -> V_153 , V_41 ) ) ;
V_133 [ V_6 ] . V_79 = V_152 ;
}
V_8 = V_3 -> V_137 . V_8 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ ) {
struct V_1 * V_5 = & V_3 -> V_8 [ V_6 ] ;
void T_1 * V_87 ;
unsigned V_15 ;
V_87 = V_5 -> V_21 + V_5 -> V_93 ;
for ( V_15 = 0 ; V_15 < V_5 -> V_114 ; V_15 ++ )
V_8 [ V_6 ] . V_136 [ V_15 ] = F_7 ( V_87 + V_15 * 4 ) ;
}
return 0 ;
}
static void F_87 ( struct V_2 * V_3 )
{
T_5 V_6 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ ) {
const struct V_1 * V_5 ;
void T_1 * V_87 ;
unsigned V_15 ;
V_5 = & V_3 -> V_8 [ V_6 ] ;
V_87 = V_5 -> V_21 ;
for ( V_15 = 0 ; V_15 < V_5 -> V_114 ; V_15 ++ ) {
F_26 ( 0 , V_87 + V_5 -> V_93 + V_15 * 4 ) ;
F_26 ( 0xffff , V_87 + V_92 + V_15 * 4 ) ;
}
}
}
int F_88 ( struct V_149 * V_11 )
{
struct V_138 * V_139 = F_86 ( V_11 ) ;
struct V_2 * V_3 = F_84 ( V_139 ) ;
const struct V_131 * V_8 ;
const struct V_132 * V_133 ;
int V_6 ;
F_87 ( V_3 ) ;
V_133 = V_3 -> V_137 . V_133 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_28 -> V_10 ; V_6 ++ ) {
const struct V_150 * V_151 = & V_3 -> V_28 -> V_32 [ V_6 ] ;
void T_1 * V_154 ;
T_2 V_152 ;
if ( ! F_12 ( V_3 , V_151 -> V_153 ) )
continue;
V_154 = F_3 ( V_3 , V_151 -> V_153 , V_40 ) ;
V_152 = F_7 ( V_154 ) & ~ V_85 ;
if ( V_152 != V_133 [ V_6 ] . V_52 ) {
F_26 ( V_133 [ V_6 ] . V_52 , V_154 ) ;
F_54 ( V_11 , L_21 ,
V_151 -> V_153 , F_7 ( V_154 ) ) ;
}
V_154 = F_3 ( V_3 , V_151 -> V_153 , V_41 ) ;
V_152 = F_7 ( V_154 ) ;
if ( V_152 != V_133 [ V_6 ] . V_79 ) {
F_26 ( V_133 [ V_6 ] . V_79 , V_154 ) ;
F_54 ( V_11 , L_22 ,
V_151 -> V_153 , F_7 ( V_154 ) ) ;
}
}
V_8 = V_3 -> V_137 . V_8 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ ) {
struct V_1 * V_5 = & V_3 -> V_8 [ V_6 ] ;
void T_1 * V_87 ;
unsigned V_15 ;
V_87 = V_5 -> V_21 + V_5 -> V_93 ;
for ( V_15 = 0 ; V_15 < V_5 -> V_114 ; V_15 ++ ) {
F_26 ( V_8 [ V_6 ] . V_136 [ V_15 ] , V_87 + V_15 * 4 ) ;
F_54 ( V_11 , L_23 , V_6 , V_15 ,
F_7 ( V_87 + V_15 * 4 ) ) ;
}
}
return 0 ;
}

static struct V_1 * F_1 ( struct V_2 * V_3 ,
unsigned int V_4 )
{
struct V_1 * V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 -> V_8 ; V_6 ++ ) {
V_5 = V_3 -> V_9 + V_6 ;
if ( V_4 < V_5 -> V_10 + V_5 -> V_11 && V_4 >= V_5 -> V_10 )
return V_5 ;
}
return NULL ;
}
static void T_1 * F_2 ( struct V_2 * V_3 , unsigned int V_12 ,
int V_13 )
{
struct V_1 * V_5 = F_1 ( V_3 , V_12 ) ;
T_2 V_14 = 0 ;
if ( ! V_5 )
return NULL ;
V_12 -= V_5 -> V_10 ;
if ( V_13 == V_15 )
V_14 = ( V_12 / 32 ) * 4 ;
else
V_14 = V_5 -> V_16 [ V_12 ] * 16 ;
return V_5 -> V_17 + V_14 + V_13 ;
}
static int F_3 ( struct V_18 * V_19 )
{
struct V_2 * V_3 = F_4 ( V_19 ) ;
return V_3 -> V_7 -> V_20 ;
}
static const char * F_5 ( struct V_18 * V_19 ,
unsigned int V_21 )
{
struct V_2 * V_3 = F_4 ( V_19 ) ;
return V_3 -> V_7 -> V_22 [ V_21 ] . V_23 ;
}
static int F_6 ( struct V_18 * V_19 ,
unsigned int V_21 ,
const unsigned int * * V_24 ,
unsigned int * V_25 )
{
struct V_2 * V_3 = F_4 ( V_19 ) ;
* V_24 = V_3 -> V_7 -> V_22 [ V_21 ] . V_24 ;
* V_25 = V_3 -> V_7 -> V_22 [ V_21 ] . V_11 ;
return 0 ;
}
static int F_7 ( struct V_18 * V_19 )
{
struct V_2 * V_3 = F_4 ( V_19 ) ;
return V_3 -> V_7 -> V_26 ;
}
static const char * F_8 ( struct V_18 * V_19 ,
unsigned int V_21 )
{
struct V_2 * V_3 = F_4 ( V_19 ) ;
return V_3 -> V_7 -> V_27 [ V_21 ] . V_23 ;
}
static int F_9 ( struct V_18 * V_19 ,
unsigned int V_21 ,
const char * const * * V_22 ,
unsigned int * V_28 )
{
struct V_2 * V_3 = F_4 ( V_19 ) ;
* V_22 = V_3 -> V_7 -> V_27 [ V_21 ] . V_22 ;
* V_28 = V_3 -> V_7 -> V_27 [ V_21 ] . V_20 ;
return 0 ;
}
static int F_10 ( const struct V_29 V_30 ,
const char * V_31 ,
unsigned short * V_32 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_30 . V_33 ; V_6 ++ ) {
if ( ! strcmp ( V_30 . V_34 [ V_6 ] . V_23 , V_31 ) ) {
* V_32 = V_30 . V_34 [ V_6 ] . V_32 ;
return 0 ;
}
}
return 1 ;
}
static int F_11 ( const struct V_29 V_30 ,
const char * V_31 ,
const unsigned short * * V_32 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_30 . V_33 ; V_6 ++ ) {
if ( ! strcmp ( V_30 . V_35 [ V_6 ] . V_23 , V_31 ) ) {
* V_32 = V_30 . V_35 [ V_6 ] . V_36 ;
return 0 ;
}
}
return 1 ;
}
static void F_12 ( struct V_2 * V_3 ,
const struct V_29 V_30 ,
unsigned short V_32 )
{
unsigned long V_37 ;
int V_6 ;
F_13 ( & V_3 -> V_38 , V_37 ) ;
for ( V_6 = 0 ; V_6 < V_30 . V_11 ; V_6 ++ ) {
void T_1 * V_39 ;
T_2 V_40 ;
V_39 = F_2 ( V_3 , V_30 . V_24 [ V_6 ] , V_41 ) ;
if ( ! V_39 ) {
F_14 ( & V_3 -> V_42 -> V_43 ,
L_1 ,
V_30 . V_23 , V_6 ) ;
continue;
}
V_40 = F_15 ( V_39 ) ;
V_40 &= ~ V_44 ;
V_40 |= V_32 ;
F_16 ( V_40 , V_39 ) ;
}
F_17 ( & V_3 -> V_38 , V_37 ) ;
}
static void F_18 ( struct V_2 * V_3 ,
const struct V_29 V_30 ,
const unsigned short * V_32 )
{
unsigned long V_37 ;
int V_6 ;
F_13 ( & V_3 -> V_38 , V_37 ) ;
for ( V_6 = 0 ; V_6 < V_30 . V_11 ; V_6 ++ ) {
void T_1 * V_39 ;
T_2 V_40 ;
V_39 = F_2 ( V_3 , V_30 . V_24 [ V_6 ] , V_41 ) ;
if ( ! V_39 ) {
F_14 ( & V_3 -> V_42 -> V_43 ,
L_1 ,
V_30 . V_23 , V_6 ) ;
continue;
}
V_40 = F_15 ( V_39 ) ;
V_40 &= ~ V_44 ;
V_40 |= V_32 [ V_6 ] ;
F_16 ( V_40 , V_39 ) ;
}
F_17 ( & V_3 -> V_38 , V_37 ) ;
}
static int F_19 ( struct V_18 * V_19 , unsigned int V_45 ,
unsigned int V_46 )
{
struct V_2 * V_3 = F_4 ( V_19 ) ;
const struct V_47 V_32 = V_3 -> V_7 -> V_27 [ V_45 ] ;
const struct V_29 V_30 = V_3 -> V_7 -> V_22 [ V_46 ] ;
const unsigned short * V_48 ;
unsigned short V_49 ;
int V_50 = 1 ;
if ( V_30 . V_51 )
V_50 = F_10 ( V_30 , V_32 . V_23 , & V_49 ) ;
else
V_50 = F_11 ( V_30 , V_32 . V_23 , & V_48 ) ;
if ( V_50 )
F_12 ( V_3 , V_30 , V_52 ) ;
else if ( V_30 . V_51 )
F_12 ( V_3 , V_30 , V_49 ) ;
else
F_18 ( V_3 , V_30 , V_48 ) ;
return 0 ;
}
static T_2 F_20 ( struct V_2 * V_3 , unsigned V_12 )
{
if ( ! strcmp ( V_3 -> V_7 -> V_53 , V_54 ) &&
V_12 >= 92 && V_12 <= 93 )
return 1 ;
if ( ! strcmp ( V_3 -> V_7 -> V_53 , V_55 ) &&
V_12 >= 11 && V_12 <= 21 )
return 1 ;
return 0 ;
}
static void F_21 ( struct V_2 * V_3 , unsigned int V_12 )
{
void T_1 * V_13 = F_2 ( V_3 , V_12 , V_41 ) ;
unsigned long V_37 ;
T_2 V_40 ;
F_13 ( & V_3 -> V_38 , V_37 ) ;
V_40 = F_15 ( V_13 ) ;
V_40 &= ~ ( V_56 | V_57 | V_58 ) ;
F_16 ( V_40 , V_13 ) ;
F_17 ( & V_3 -> V_38 , V_37 ) ;
}
static int F_22 ( struct V_18 * V_59 ,
struct V_60 * V_61 ,
unsigned int V_12 )
{
struct V_2 * V_3 = F_4 ( V_59 ) ;
void T_1 * V_13 = F_2 ( V_3 , V_12 , V_41 ) ;
T_2 V_40 , V_62 ;
unsigned long V_37 ;
F_13 ( & V_3 -> V_38 , V_37 ) ;
V_40 = F_15 ( V_13 ) & V_44 ;
V_62 = F_20 ( V_3 , V_12 ) ;
if ( F_23 ( V_62 != V_40 ) ) {
V_40 = F_15 ( V_13 ) & ~ V_44 ;
V_40 |= V_62 ;
F_16 ( V_40 , V_13 ) ;
F_14 ( & V_3 -> V_42 -> V_43 ,
L_2 , V_12 ) ;
}
F_17 ( & V_3 -> V_38 , V_37 ) ;
F_24 ( & V_3 -> V_42 -> V_43 ) ;
return 0 ;
}
static void F_25 ( struct V_18 * V_59 ,
struct V_60 * V_61 ,
unsigned int V_12 )
{
struct V_2 * V_3 = F_4 ( V_59 ) ;
F_21 ( V_3 , V_12 ) ;
F_26 ( & V_3 -> V_42 -> V_43 ) ;
}
static int F_27 ( struct V_18 * V_59 ,
struct V_60 * V_61 ,
unsigned int V_12 ,
bool V_63 )
{
struct V_2 * V_3 = F_4 ( V_59 ) ;
void T_1 * V_64 = F_2 ( V_3 , V_12 , V_65 ) ;
void T_1 * V_66 = F_2 ( V_3 , V_12 , V_41 ) ;
unsigned long V_37 ;
T_2 V_40 ;
F_13 ( & V_3 -> V_38 , V_37 ) ;
V_40 = F_15 ( V_64 ) ;
V_40 &= ~ V_67 ;
if ( V_63 )
V_40 |= V_68 ;
else
F_28 ( F_15 ( V_66 ) & V_69 ,
L_3 ) ;
F_16 ( V_40 , V_64 ) ;
F_17 ( & V_3 -> V_38 , V_37 ) ;
return 0 ;
}
static void F_29 ( T_2 V_13 , T_3 * V_70 )
{
switch ( V_13 & V_71 ) {
case V_72 :
* V_70 = 2000 ;
break;
case V_73 :
* V_70 = 10000 ;
break;
case V_74 :
* V_70 = 20000 ;
break;
case V_75 :
* V_70 = 40000 ;
break;
}
}
static int F_30 ( T_2 * V_13 , T_3 V_70 )
{
* V_13 &= ~ V_71 ;
switch ( V_70 ) {
case 2000 :
* V_13 |= V_72 ;
break;
case 10000 :
* V_13 |= V_73 ;
break;
case 20000 :
* V_13 |= V_74 ;
break;
case 40000 :
* V_13 |= V_75 ;
break;
default:
return - V_76 ;
}
return 0 ;
}
static int F_31 ( struct V_18 * V_59 , unsigned int V_12 ,
unsigned long * V_77 )
{
struct V_2 * V_3 = F_4 ( V_59 ) ;
enum V_78 V_79 = F_32 ( * V_77 ) ;
void T_1 * V_66 = F_2 ( V_3 , V_12 , V_41 ) ;
void T_1 * V_64 = F_2 ( V_3 , V_12 , V_65 ) ;
unsigned long V_37 ;
T_2 V_80 , V_81 , V_82 , V_83 ;
T_3 V_84 = 0 ;
F_13 ( & V_3 -> V_38 , V_37 ) ;
V_80 = F_15 ( V_66 ) ;
V_81 = V_80 & V_85 ;
V_82 = F_15 ( V_64 ) ;
F_17 ( & V_3 -> V_38 , V_37 ) ;
switch ( V_79 ) {
case V_86 :
if ( V_81 )
return - V_76 ;
break;
case V_87 :
if ( ( V_82 & V_88 ) || V_81 != V_89 )
return - V_76 ;
F_29 ( V_80 , & V_84 ) ;
break;
case V_90 :
if ( ( V_82 & V_88 ) || V_81 != V_91 )
return - V_76 ;
F_29 ( V_80 , & V_84 ) ;
break;
case V_92 :
if ( ! ( V_80 & V_93 ) )
return - V_76 ;
F_13 ( & V_3 -> V_38 , V_37 ) ;
V_83 = F_15 ( F_2 ( V_3 , V_12 , V_94 ) ) ;
F_17 ( & V_3 -> V_38 , V_37 ) ;
switch ( V_83 & V_95 ) {
case V_96 :
V_84 = 375 ;
break;
case V_97 :
V_84 = 750 ;
break;
case V_98 :
V_84 = 1500 ;
break;
case V_99 :
V_84 = 3000 ;
break;
case V_100 :
V_84 = 6000 ;
break;
case V_101 :
V_84 = 12000 ;
break;
case V_102 :
V_84 = 24000 ;
break;
default:
return - V_76 ;
}
break;
default:
return - V_103 ;
}
* V_77 = F_33 ( V_79 , V_84 ) ;
return 0 ;
}
static int F_34 ( struct V_18 * V_59 ,
unsigned int V_12 ,
unsigned long * V_104 ,
unsigned int V_105 )
{
struct V_2 * V_3 = F_4 ( V_59 ) ;
unsigned int V_79 , V_84 ;
void T_1 * V_66 = F_2 ( V_3 , V_12 , V_41 ) ;
void T_1 * V_64 = F_2 ( V_3 , V_12 , V_65 ) ;
unsigned long V_37 ;
T_2 V_80 , V_82 , V_83 ;
int V_6 , V_50 = 0 ;
F_13 ( & V_3 -> V_38 , V_37 ) ;
V_80 = F_15 ( V_66 ) ;
V_82 = F_15 ( V_64 ) ;
for ( V_6 = 0 ; V_6 < V_105 ; V_6 ++ ) {
V_79 = F_32 ( V_104 [ V_6 ] ) ;
V_84 = F_35 ( V_104 [ V_6 ] ) ;
switch ( V_79 ) {
case V_86 :
V_80 &= ~ V_85 ;
break;
case V_87 :
if ( V_84 == 1 )
V_84 = 2000 ;
if ( V_82 & V_88 ) {
V_82 &= ~ V_88 ;
F_16 ( V_82 , V_64 ) ;
F_14 ( & V_3 -> V_42 -> V_43 ,
L_4 ,
V_12 ) ;
}
V_80 &= ~ V_85 ;
V_80 |= V_89 ;
V_50 = F_30 ( & V_80 , V_84 ) ;
break;
case V_90 :
if ( V_84 == 1 )
V_84 = 2000 ;
if ( V_82 & V_88 ) {
V_82 &= ~ V_88 ;
F_16 ( V_82 , V_64 ) ;
F_14 ( & V_3 -> V_42 -> V_43 ,
L_4 ,
V_12 ) ;
}
V_80 &= ~ V_85 ;
V_80 |= V_91 ;
V_50 = F_30 ( & V_80 , V_84 ) ;
break;
case V_92 :
V_83 = F_15 ( F_2 ( V_3 , V_12 ,
V_94 ) ) ;
V_80 &= ~ V_95 ;
switch ( V_84 ) {
case 375 :
V_80 |= V_96 ;
break;
case 750 :
V_80 |= V_97 ;
break;
case 1500 :
V_80 |= V_98 ;
break;
case 3000 :
V_80 |= V_99 ;
break;
case 6000 :
V_80 |= V_100 ;
break;
case 12000 :
V_80 |= V_101 ;
break;
case 24000 :
V_80 |= V_102 ;
break;
default:
V_50 = - V_76 ;
}
break;
default:
V_50 = - V_103 ;
}
if ( V_50 )
break;
}
if ( ! V_50 )
F_16 ( V_80 , V_66 ) ;
F_17 ( & V_3 -> V_38 , V_37 ) ;
return V_50 ;
}
static int F_36 ( struct V_106 * V_107 , unsigned V_12 )
{
struct V_2 * V_3 = F_37 ( V_107 ) ;
void T_1 * V_13 = F_2 ( V_3 , V_12 , V_65 ) ;
unsigned long V_37 ;
T_2 V_82 ;
F_13 ( & V_3 -> V_38 , V_37 ) ;
V_82 = F_15 ( V_13 ) ;
F_17 ( & V_3 -> V_38 , V_37 ) ;
return ! ! ( V_82 & V_108 ) ;
}
static void F_38 ( struct V_106 * V_107 , unsigned V_12 , int V_40 )
{
struct V_2 * V_3 = F_37 ( V_107 ) ;
void T_1 * V_13 = F_2 ( V_3 , V_12 , V_65 ) ;
unsigned long V_37 ;
T_2 V_109 ;
if ( ! V_13 )
return;
F_13 ( & V_3 -> V_38 , V_37 ) ;
V_109 = F_15 ( V_13 ) ;
if ( V_40 )
F_16 ( V_109 | V_108 , V_13 ) ;
else
F_16 ( V_109 & ~ V_108 , V_13 ) ;
F_17 ( & V_3 -> V_38 , V_37 ) ;
}
static int F_39 ( struct V_106 * V_107 , unsigned int V_12 )
{
struct V_2 * V_3 = F_37 ( V_107 ) ;
void T_1 * V_13 = F_2 ( V_3 , V_12 , V_65 ) ;
unsigned long V_37 ;
T_2 V_40 ;
if ( ! V_13 )
return - V_76 ;
F_13 ( & V_3 -> V_38 , V_37 ) ;
V_40 = F_15 ( V_13 ) ;
F_17 ( & V_3 -> V_38 , V_37 ) ;
if ( ! ( V_40 & V_68 ) )
return V_110 ;
if ( ! ( V_40 & V_88 ) )
return V_111 ;
return - V_76 ;
}
static int F_40 ( struct V_106 * V_107 , unsigned int V_12 )
{
return F_41 ( V_107 -> V_112 + V_12 ) ;
}
static int F_42 ( struct V_106 * V_107 ,
unsigned int V_12 , int V_40 )
{
int V_50 = F_43 ( V_107 -> V_112 + V_12 ) ;
if ( V_50 )
return V_50 ;
F_38 ( V_107 , V_12 , V_40 ) ;
return 0 ;
}
static void F_44 ( struct V_113 * V_114 , struct V_106 * V_107 )
{
struct V_2 * V_3 = F_37 ( V_107 ) ;
int V_6 ;
T_2 V_115 , V_82 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 -> V_11 ; V_6 ++ ) {
const struct V_1 * V_5 ;
const char * V_116 = NULL ;
const char * V_81 = NULL ;
void T_1 * V_13 ;
unsigned long V_37 ;
const char * V_117 ;
unsigned int V_4 ;
F_13 ( & V_3 -> V_38 , V_37 ) ;
V_4 = V_3 -> V_7 -> V_24 [ V_6 ] . V_118 ;
V_13 = F_2 ( V_3 , V_4 , V_41 ) ;
if ( ! V_13 ) {
F_45 ( V_114 ,
L_5 ,
V_4 ) ;
F_17 ( & V_3 -> V_38 , V_37 ) ;
continue;
}
V_115 = F_15 ( V_13 ) ;
V_13 = F_2 ( V_3 , V_4 , V_65 ) ;
if ( ! V_13 ) {
F_45 ( V_114 ,
L_6 , V_4 ) ;
F_17 ( & V_3 -> V_38 , V_37 ) ;
continue;
}
V_82 = F_15 ( V_13 ) ;
F_17 ( & V_3 -> V_38 , V_37 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 ) {
F_45 ( V_114 ,
L_7 , V_4 ) ;
continue;
}
V_117 = F_46 ( V_107 , V_6 ) ;
if ( ! V_117 )
V_117 = L_8 ;
switch ( V_115 & V_85 ) {
case V_91 :
V_81 = L_9 ;
break;
case V_89 :
V_81 = L_10 ;
break;
}
switch ( V_115 & V_71 ) {
case V_72 :
V_116 = L_11 ;
break;
case V_73 :
V_116 = L_12 ;
break;
case V_74 :
V_116 = L_13 ;
break;
case V_75 :
V_116 = L_14 ;
break;
}
F_45 ( V_114 ,
L_15 ,
V_4 ,
V_117 ,
V_82 & V_88 ? L_16 : L_17 ,
V_82 & V_68 ? L_18 : L_19 ,
V_82 & V_108 ? L_20 : L_21 ,
V_5 -> V_16 [ V_6 ] , V_5 -> V_16 [ V_6 ] * 32 ,
V_115 & 0x7 ,
V_115 & V_57 ? L_22 : L_23 ,
V_115 & V_56 ? L_24 : L_23 ,
V_115 & V_58 ? L_25 : L_26 ) ;
if ( V_81 && V_116 )
F_45 ( V_114 , L_27 , V_81 , V_116 ) ;
else
F_47 ( V_114 , L_28 ) ;
if ( V_115 & V_119 )
F_47 ( V_114 , L_29 ) ;
F_47 ( V_114 , L_30 ) ;
}
}
static void F_48 ( struct V_120 * V_121 )
{
struct V_106 * V_122 = F_49 ( V_121 ) ;
struct V_2 * V_3 = F_37 ( V_122 ) ;
unsigned V_12 = F_50 ( V_121 ) ;
void T_1 * V_13 ;
V_13 = F_2 ( V_3 , V_12 , V_15 ) ;
if ( ! V_13 )
return;
F_51 ( & V_3 -> V_38 ) ;
F_16 ( F_52 ( V_12 % 32 ) , V_13 ) ;
F_53 ( & V_3 -> V_38 ) ;
}
static void F_54 ( struct V_120 * V_121 )
{
struct V_106 * V_122 = F_49 ( V_121 ) ;
struct V_2 * V_3 = F_37 ( V_122 ) ;
F_21 ( V_3 , F_50 ( V_121 ) ) ;
}
static void F_55 ( struct V_120 * V_121 )
{
struct V_106 * V_122 = F_49 ( V_121 ) ;
struct V_2 * V_3 = F_37 ( V_122 ) ;
unsigned V_12 = F_50 ( V_121 ) ;
unsigned long V_37 ;
void T_1 * V_13 ;
T_2 V_40 ;
V_13 = F_2 ( V_3 , V_12 , V_41 ) ;
if ( ! V_13 )
return;
F_13 ( & V_3 -> V_38 , V_37 ) ;
V_40 = F_15 ( V_13 ) ;
switch ( F_56 ( V_121 ) ) {
case V_123 :
V_40 |= V_58 ;
case V_124 :
V_40 |= V_56 ;
break;
case V_125 :
V_40 |= V_58 ;
case V_126 :
V_40 |= V_57 ;
break;
case V_127 :
V_40 |= ( V_57 | V_56 ) ;
break;
}
F_16 ( V_40 , V_13 ) ;
F_17 ( & V_3 -> V_38 , V_37 ) ;
}
static int F_57 ( struct V_120 * V_121 , unsigned int type )
{
struct V_2 * V_3 = F_37 ( F_49 ( V_121 ) ) ;
T_2 V_12 = F_50 ( V_121 ) ;
T_2 V_40 ;
unsigned long V_37 ;
void T_1 * V_13 = F_2 ( V_3 , V_12 , V_41 ) ;
if ( ! V_13 || V_12 >= V_3 -> V_107 . V_128 )
return - V_76 ;
F_13 ( & V_3 -> V_38 , V_37 ) ;
V_40 = F_15 ( V_13 ) ;
F_28 ( V_40 & V_69 ,
L_31 ) ;
V_40 &= ~ ( V_69 | V_56 | V_57 |
V_58 ) ;
F_16 ( V_40 , V_13 ) ;
if ( type & V_127 )
F_58 ( V_121 , V_129 ) ;
else if ( type & V_130 )
F_58 ( V_121 , V_131 ) ;
F_17 ( & V_3 -> V_38 , V_37 ) ;
return 0 ;
}
static void F_59 ( struct V_132 * V_133 )
{
struct V_120 * V_134 = F_60 ( V_133 ) ;
struct V_2 * V_3 = F_37 (
F_61 ( V_133 ) ) ;
struct V_135 * V_107 = F_62 ( V_134 ) ;
T_2 V_112 , V_4 ;
void T_1 * V_13 ;
unsigned long V_136 ;
unsigned int V_137 ;
for ( V_112 = 0 ; V_112 < V_3 -> V_107 . V_128 ; V_112 += 32 ) {
V_13 = F_2 ( V_3 , V_112 , V_15 ) ;
if ( ! V_13 ) {
F_14 ( & V_3 -> V_42 -> V_43 ,
L_32 ,
V_112 ) ;
continue;
}
V_136 = F_15 ( V_13 ) ;
F_63 (pin, &pending, 32 ) {
V_137 = F_64 ( V_3 -> V_107 . V_138 , V_112 + V_4 ) ;
F_65 ( V_137 ) ;
}
}
V_107 -> V_139 ( V_134 ) ;
}
static void F_66 ( struct V_2 * V_3 )
{
void T_1 * V_13 ;
T_2 V_112 , V_40 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 -> V_11 ; V_6 ++ ) {
unsigned int V_4 = V_3 -> V_7 -> V_24 [ V_6 ] . V_118 ;
V_13 = F_2 ( V_3 , V_4 , V_41 ) ;
if ( ! V_13 ) {
F_14 ( & V_3 -> V_42 -> V_43 ,
L_33 ,
V_6 ) ;
continue;
}
V_40 = F_15 ( V_13 ) ;
if ( ( V_40 & V_44 ) == F_20 ( V_3 , V_6 ) &&
! ( V_40 & V_69 ) ) {
F_21 ( V_3 , V_6 ) ;
F_67 ( & V_3 -> V_42 -> V_43 , L_34 , V_6 ) ;
}
}
for ( V_112 = 0 ; V_112 < V_3 -> V_7 -> V_11 ; V_112 += 32 ) {
V_13 = F_2 ( V_3 , V_112 , V_15 ) ;
if ( ! V_13 ) {
F_14 ( & V_3 -> V_42 -> V_43 ,
L_35 ,
V_112 ) ;
continue;
}
F_16 ( 0xffffffff , V_13 ) ;
V_40 = F_15 ( V_13 ) ;
if ( V_40 )
F_68 ( & V_3 -> V_42 -> V_43 ,
L_36 ) ;
}
}
static int F_69 ( struct V_2 * V_3 )
{
struct V_106 * V_122 ;
struct V_140 * V_141 ;
int V_50 ;
V_3 -> V_107 = V_142 ;
V_122 = & V_3 -> V_107 ;
V_122 -> V_117 = F_70 ( & V_3 -> V_42 -> V_43 ) ;
V_122 -> V_112 = - 1 ;
V_122 -> V_143 = false ;
V_122 -> V_144 = & V_3 -> V_42 -> V_43 ;
V_122 -> V_128 = V_3 -> V_7 -> V_11 ;
#ifdef F_71
V_3 -> V_145 = F_72 ( & V_3 -> V_42 -> V_43 , V_122 -> V_128 ,
sizeof( * V_3 -> V_145 ) , V_146 ) ;
#endif
V_50 = F_73 ( V_122 , V_3 ) ;
if ( V_50 ) {
F_68 ( & V_3 -> V_42 -> V_43 , L_37 ) ;
return V_50 ;
}
V_50 = F_74 ( & V_3 -> V_107 , F_70 ( & V_3 -> V_42 -> V_43 ) ,
0 , 0 , V_3 -> V_7 -> V_11 ) ;
if ( V_50 ) {
F_68 ( & V_3 -> V_42 -> V_43 , L_38 ) ;
goto V_147;
}
V_141 = F_75 ( V_3 -> V_42 , V_148 , 0 ) ;
if ( V_141 && V_141 -> V_149 ) {
F_66 ( V_3 ) ;
V_50 = F_76 ( V_122 , & V_150 , 0 ,
V_151 , V_152 ) ;
if ( V_50 ) {
F_68 ( & V_3 -> V_42 -> V_43 , L_39 ) ;
goto V_147;
}
F_77 ( V_122 , & V_150 ,
( unsigned ) V_141 -> V_149 ,
F_59 ) ;
}
return V_50 ;
V_147:
F_78 ( & V_3 -> V_107 ) ;
return V_50 ;
}
static int F_79 ( struct V_2 * V_3 ,
const struct V_153 * V_7 )
{
int V_6 ;
V_3 -> V_7 = V_7 ;
V_3 -> V_9 = F_72 ( & V_3 -> V_42 -> V_43 ,
V_7 -> V_8 ,
sizeof( * V_3 -> V_9 ) ,
V_146 ) ;
if ( ! V_3 -> V_9 )
return - V_154 ;
for ( V_6 = 0 ; V_6 < V_7 -> V_8 ; V_6 ++ ) {
struct V_1 * V_5 = V_3 -> V_9 + V_6 ;
struct V_140 * V_155 ;
* V_5 = V_3 -> V_7 -> V_156 [ V_6 ] ;
V_155 = F_75 ( V_3 -> V_42 , V_157 , 0 ) ;
V_5 -> V_17 = F_80 ( & V_3 -> V_42 -> V_43 , V_155 ) ;
if ( F_81 ( V_5 -> V_17 ) )
return F_82 ( V_5 -> V_17 ) ;
}
return 0 ;
}
static int F_83 ( struct V_158 * V_42 )
{
const struct V_153 * V_7 = NULL ;
const struct V_153 * * V_159 ;
const struct V_160 * V_161 ;
struct V_162 * V_163 ;
struct V_2 * V_3 ;
int V_6 , V_50 ;
V_163 = F_84 ( & V_42 -> V_43 ) ;
if ( ! V_163 )
return - V_164 ;
V_161 = F_85 ( V_165 , & V_42 -> V_43 ) ;
if ( ! V_161 )
return - V_164 ;
V_159 = ( const struct V_153 * * ) V_161 -> V_166 ;
for ( V_6 = 0 ; V_159 [ V_6 ] ; V_6 ++ ) {
if ( ! strcmp ( V_163 -> V_167 . V_168 , V_159 [ V_6 ] -> V_53 ) ) {
V_7 = V_159 [ V_6 ] ;
break;
}
}
if ( ! V_7 )
return - V_164 ;
V_3 = F_86 ( & V_42 -> V_43 , sizeof( * V_3 ) , V_146 ) ;
if ( ! V_3 )
return - V_154 ;
V_3 -> V_42 = V_42 ;
V_50 = F_79 ( V_3 , V_7 ) ;
if ( V_50 ) {
F_68 ( & V_42 -> V_43 , L_40 ) ;
return V_50 ;
}
V_3 -> V_169 = V_170 ;
V_3 -> V_169 . V_23 = F_70 ( & V_42 -> V_43 ) ;
V_3 -> V_169 . V_24 = V_3 -> V_7 -> V_24 ;
V_3 -> V_169 . V_11 = V_3 -> V_7 -> V_11 ;
V_3 -> V_59 = F_87 ( & V_3 -> V_169 , & V_42 -> V_43 , V_3 ) ;
if ( F_81 ( V_3 -> V_59 ) ) {
F_68 ( & V_42 -> V_43 , L_41 ) ;
return F_82 ( V_3 -> V_59 ) ;
}
V_50 = F_69 ( V_3 ) ;
if ( V_50 ) {
F_88 ( V_3 -> V_59 ) ;
return V_50 ;
}
F_89 ( V_42 , V_3 ) ;
F_90 ( & V_3 -> V_38 ) ;
F_91 ( & V_42 -> V_43 ) ;
return 0 ;
}
static int F_92 ( struct V_171 * V_43 )
{
struct V_158 * V_42 = F_93 ( V_43 ) ;
struct V_2 * V_3 = F_94 ( V_42 ) ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 -> V_11 ; V_6 ++ ) {
void T_1 * V_13 ;
T_2 V_40 ;
unsigned int V_4 = V_3 -> V_7 -> V_24 [ V_6 ] . V_118 ;
V_13 = F_2 ( V_3 , V_4 , V_41 ) ;
if ( ! V_13 ) {
F_14 ( & V_3 -> V_42 -> V_43 ,
L_33 ,
V_6 ) ;
continue;
}
V_40 = F_15 ( V_13 ) & V_172 ;
V_3 -> V_145 [ V_6 ] . V_115 = V_40 ;
V_13 = F_2 ( V_3 , V_4 , V_65 ) ;
V_40 = F_15 ( V_13 ) & V_173 ;
V_3 -> V_145 [ V_6 ] . V_82 = V_40 ;
}
return 0 ;
}
static int F_95 ( struct V_171 * V_43 )
{
struct V_158 * V_42 = F_93 ( V_43 ) ;
struct V_2 * V_3 = F_94 ( V_42 ) ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 -> V_11 ; V_6 ++ ) {
void T_1 * V_13 ;
T_2 V_40 ;
unsigned int V_4 = V_3 -> V_7 -> V_24 [ V_6 ] . V_118 ;
V_13 = F_2 ( V_3 , V_4 , V_41 ) ;
if ( ! V_13 ) {
F_14 ( & V_3 -> V_42 -> V_43 ,
L_33 ,
V_6 ) ;
continue;
}
V_40 = F_15 ( V_13 ) ;
if ( ( V_40 & V_172 ) !=
V_3 -> V_145 [ V_6 ] . V_115 ) {
V_40 &= ~ V_172 ;
V_40 |= V_3 -> V_145 [ V_6 ] . V_115 ;
F_16 ( V_40 , V_13 ) ;
F_96 ( V_43 , L_42 , V_6 , V_40 ) ;
}
V_13 = F_2 ( V_3 , V_4 , V_65 ) ;
V_40 = F_15 ( V_13 ) ;
if ( ( V_40 & V_173 ) !=
V_3 -> V_145 [ V_6 ] . V_82 ) {
T_2 V_174 ;
V_174 = V_40 & ~ V_173 ;
V_174 |= V_3 -> V_145 [ V_6 ] . V_82 ;
if ( V_174 != V_40 ) {
F_16 ( V_174 , V_13 ) ;
F_67 ( V_43 , L_43 ,
V_6 , V_174 ) ;
}
}
}
return 0 ;
}
static int F_97 ( struct V_171 * V_43 )
{
return 0 ;
}
static int F_98 ( struct V_171 * V_43 )
{
return 0 ;
}
static int T_4 F_99 ( void )
{
return F_100 ( & V_175 ) ;
}

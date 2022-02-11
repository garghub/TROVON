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
T_2 V_14 ;
if ( ! V_5 )
return NULL ;
V_12 -= V_5 -> V_10 ;
switch ( V_13 ) {
case V_15 :
V_14 = ( V_12 / 32 ) * 4 ;
break;
case V_16 :
V_14 = 0 ;
break;
default:
V_14 = V_5 -> V_17 [ V_12 ] * 16 ;
break;
}
return V_5 -> V_18 + V_14 + V_13 ;
}
static int F_3 ( struct V_19 * V_20 )
{
struct V_2 * V_3 = F_4 ( V_20 ) ;
return V_3 -> V_7 -> V_21 ;
}
static const char * F_5 ( struct V_19 * V_20 ,
unsigned int V_22 )
{
struct V_2 * V_3 = F_4 ( V_20 ) ;
return V_3 -> V_7 -> V_23 [ V_22 ] . V_24 ;
}
static int F_6 ( struct V_19 * V_20 ,
unsigned int V_22 ,
const unsigned int * * V_25 ,
unsigned int * V_26 )
{
struct V_2 * V_3 = F_4 ( V_20 ) ;
* V_25 = V_3 -> V_7 -> V_23 [ V_22 ] . V_25 ;
* V_26 = V_3 -> V_7 -> V_23 [ V_22 ] . V_11 ;
return 0 ;
}
static int F_7 ( struct V_19 * V_20 )
{
struct V_2 * V_3 = F_4 ( V_20 ) ;
return V_3 -> V_7 -> V_27 ;
}
static const char * F_8 ( struct V_19 * V_20 ,
unsigned int V_22 )
{
struct V_2 * V_3 = F_4 ( V_20 ) ;
return V_3 -> V_7 -> V_28 [ V_22 ] . V_24 ;
}
static int F_9 ( struct V_19 * V_20 ,
unsigned int V_22 ,
const char * const * * V_23 ,
unsigned int * V_29 )
{
struct V_2 * V_3 = F_4 ( V_20 ) ;
* V_23 = V_3 -> V_7 -> V_28 [ V_22 ] . V_23 ;
* V_29 = V_3 -> V_7 -> V_28 [ V_22 ] . V_21 ;
return 0 ;
}
static int F_10 ( const struct V_30 V_31 ,
const char * V_32 ,
unsigned short * V_33 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_31 . V_34 ; V_6 ++ ) {
if ( ! strcmp ( V_31 . V_35 [ V_6 ] . V_24 , V_32 ) ) {
* V_33 = V_31 . V_35 [ V_6 ] . V_33 ;
return 0 ;
}
}
return 1 ;
}
static int F_11 ( const struct V_30 V_31 ,
const char * V_32 ,
const unsigned short * * V_33 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_31 . V_34 ; V_6 ++ ) {
if ( ! strcmp ( V_31 . V_36 [ V_6 ] . V_24 , V_32 ) ) {
* V_33 = V_31 . V_36 [ V_6 ] . V_37 ;
return 0 ;
}
}
return 1 ;
}
static void F_12 ( struct V_2 * V_3 ,
const struct V_30 V_31 ,
unsigned short V_33 )
{
unsigned long V_38 ;
int V_6 ;
F_13 ( & V_3 -> V_39 , V_38 ) ;
for ( V_6 = 0 ; V_6 < V_31 . V_11 ; V_6 ++ ) {
void T_1 * V_40 ;
T_2 V_41 ;
V_40 = F_2 ( V_3 , V_31 . V_25 [ V_6 ] , V_42 ) ;
if ( ! V_40 ) {
F_14 ( & V_3 -> V_43 -> V_44 ,
L_1 ,
V_31 . V_24 , V_6 ) ;
continue;
}
V_41 = F_15 ( V_40 ) ;
V_41 &= ~ V_45 ;
V_41 |= V_33 ;
F_16 ( V_41 , V_40 ) ;
}
F_17 ( & V_3 -> V_39 , V_38 ) ;
}
static void F_18 ( struct V_2 * V_3 ,
const struct V_30 V_31 ,
const unsigned short * V_33 )
{
unsigned long V_38 ;
int V_6 ;
F_13 ( & V_3 -> V_39 , V_38 ) ;
for ( V_6 = 0 ; V_6 < V_31 . V_11 ; V_6 ++ ) {
void T_1 * V_40 ;
T_2 V_41 ;
V_40 = F_2 ( V_3 , V_31 . V_25 [ V_6 ] , V_42 ) ;
if ( ! V_40 ) {
F_14 ( & V_3 -> V_43 -> V_44 ,
L_1 ,
V_31 . V_24 , V_6 ) ;
continue;
}
V_41 = F_15 ( V_40 ) ;
V_41 &= ~ V_45 ;
V_41 |= V_33 [ V_6 ] ;
F_16 ( V_41 , V_40 ) ;
}
F_17 ( & V_3 -> V_39 , V_38 ) ;
}
static int F_19 ( struct V_19 * V_20 , unsigned int V_46 ,
unsigned int V_47 )
{
struct V_2 * V_3 = F_4 ( V_20 ) ;
const struct V_48 V_33 = V_3 -> V_7 -> V_28 [ V_46 ] ;
const struct V_30 V_31 = V_3 -> V_7 -> V_23 [ V_47 ] ;
const unsigned short * V_49 ;
unsigned short V_50 ;
int V_51 = 1 ;
if ( V_31 . V_52 )
V_51 = F_10 ( V_31 , V_33 . V_24 , & V_50 ) ;
else
V_51 = F_11 ( V_31 , V_33 . V_24 , & V_49 ) ;
if ( V_51 )
F_12 ( V_3 , V_31 , V_53 ) ;
else if ( V_31 . V_52 )
F_12 ( V_3 , V_31 , V_50 ) ;
else
F_18 ( V_3 , V_31 , V_49 ) ;
return 0 ;
}
static T_2 F_20 ( struct V_2 * V_3 , unsigned V_12 )
{
if ( ! strcmp ( V_3 -> V_7 -> V_54 , V_55 ) &&
V_12 >= 92 && V_12 <= 93 )
return 1 ;
if ( ! strcmp ( V_3 -> V_7 -> V_54 , V_56 ) &&
V_12 >= 11 && V_12 <= 21 )
return 1 ;
return 0 ;
}
static void F_21 ( struct V_2 * V_3 , unsigned int V_12 )
{
void T_1 * V_13 = F_2 ( V_3 , V_12 , V_42 ) ;
unsigned long V_38 ;
T_2 V_41 ;
F_13 ( & V_3 -> V_39 , V_38 ) ;
V_41 = F_15 ( V_13 ) ;
V_41 &= ~ ( V_57 | V_58 | V_59 ) ;
F_16 ( V_41 , V_13 ) ;
F_17 ( & V_3 -> V_39 , V_38 ) ;
}
static int F_22 ( struct V_19 * V_60 ,
struct V_61 * V_62 ,
unsigned int V_12 )
{
struct V_2 * V_3 = F_4 ( V_60 ) ;
void T_1 * V_13 = F_2 ( V_3 , V_12 , V_42 ) ;
T_2 V_41 , V_63 ;
unsigned long V_38 ;
F_13 ( & V_3 -> V_39 , V_38 ) ;
V_41 = F_15 ( V_13 ) & V_45 ;
V_63 = F_20 ( V_3 , V_12 ) ;
if ( F_23 ( V_63 != V_41 ) ) {
V_41 = F_15 ( V_13 ) & ~ V_45 ;
V_41 |= V_63 ;
F_16 ( V_41 , V_13 ) ;
F_14 ( & V_3 -> V_43 -> V_44 ,
L_2 , V_12 ) ;
}
F_17 ( & V_3 -> V_39 , V_38 ) ;
F_24 ( & V_3 -> V_43 -> V_44 ) ;
return 0 ;
}
static void F_25 ( struct V_19 * V_60 ,
struct V_61 * V_62 ,
unsigned int V_12 )
{
struct V_2 * V_3 = F_4 ( V_60 ) ;
F_21 ( V_3 , V_12 ) ;
F_26 ( & V_3 -> V_43 -> V_44 ) ;
}
static int F_27 ( struct V_19 * V_60 ,
struct V_61 * V_62 ,
unsigned int V_12 ,
bool V_64 )
{
struct V_2 * V_3 = F_4 ( V_60 ) ;
void T_1 * V_65 = F_2 ( V_3 , V_12 , V_66 ) ;
void T_1 * V_67 = F_2 ( V_3 , V_12 , V_42 ) ;
unsigned long V_38 ;
T_2 V_41 ;
F_13 ( & V_3 -> V_39 , V_38 ) ;
V_41 = F_15 ( V_65 ) ;
V_41 &= ~ V_68 ;
if ( V_64 )
V_41 |= V_69 ;
else
F_28 ( F_15 ( V_67 ) & V_70 ,
L_3 ) ;
F_16 ( V_41 , V_65 ) ;
F_17 ( & V_3 -> V_39 , V_38 ) ;
return 0 ;
}
static void F_29 ( T_2 V_13 , T_3 * V_71 )
{
switch ( V_13 & V_72 ) {
case V_73 :
* V_71 = 2000 ;
break;
case V_74 :
* V_71 = 10000 ;
break;
case V_75 :
* V_71 = 20000 ;
break;
case V_76 :
* V_71 = 40000 ;
break;
}
}
static int F_30 ( T_2 * V_13 , T_3 V_71 )
{
* V_13 &= ~ V_72 ;
switch ( V_71 ) {
case 2000 :
* V_13 |= V_73 ;
break;
case 10000 :
* V_13 |= V_74 ;
break;
case 20000 :
* V_13 |= V_75 ;
break;
case 40000 :
* V_13 |= V_76 ;
break;
default:
return - V_77 ;
}
return 0 ;
}
static int F_31 ( struct V_19 * V_60 , unsigned int V_12 ,
unsigned long * V_78 )
{
struct V_2 * V_3 = F_4 ( V_60 ) ;
enum V_79 V_80 = F_32 ( * V_78 ) ;
void T_1 * V_67 = F_2 ( V_3 , V_12 , V_42 ) ;
void T_1 * V_65 = F_2 ( V_3 , V_12 , V_66 ) ;
void T_1 * V_81 = F_2 ( V_3 , V_12 , V_16 ) ;
unsigned long V_38 ;
T_2 V_82 , V_83 , V_84 , V_85 ;
T_3 V_86 = 0 ;
F_13 ( & V_3 -> V_39 , V_38 ) ;
V_82 = F_15 ( V_67 ) ;
V_83 = V_82 & V_87 ;
V_84 = F_15 ( V_65 ) ;
F_17 ( & V_3 -> V_39 , V_38 ) ;
switch ( V_80 ) {
case V_88 :
if ( V_83 )
return - V_77 ;
break;
case V_89 :
if ( ( V_84 & V_90 ) || V_83 != V_91 )
return - V_77 ;
F_29 ( V_82 , & V_86 ) ;
break;
case V_92 :
if ( ( V_84 & V_90 ) || V_83 != V_93 )
return - V_77 ;
F_29 ( V_82 , & V_86 ) ;
break;
case V_94 :
if ( ! ( V_82 & V_95 ) )
return - V_77 ;
F_13 ( & V_3 -> V_39 , V_38 ) ;
V_85 = F_15 ( V_81 ) ;
F_17 ( & V_3 -> V_39 , V_38 ) ;
switch ( V_85 & V_96 ) {
case V_97 :
V_86 = 375 ;
break;
case V_98 :
V_86 = 750 ;
break;
case V_99 :
V_86 = 1500 ;
break;
case V_100 :
V_86 = 3000 ;
break;
case V_101 :
V_86 = 6000 ;
break;
case V_102 :
V_86 = 12000 ;
break;
case V_103 :
V_86 = 24000 ;
break;
default:
return - V_77 ;
}
break;
default:
return - V_104 ;
}
* V_78 = F_33 ( V_80 , V_86 ) ;
return 0 ;
}
static int F_34 ( struct V_19 * V_60 ,
unsigned int V_12 ,
unsigned long * V_105 ,
unsigned int V_106 )
{
struct V_2 * V_3 = F_4 ( V_60 ) ;
unsigned int V_80 , V_86 ;
void T_1 * V_67 = F_2 ( V_3 , V_12 , V_42 ) ;
void T_1 * V_65 = F_2 ( V_3 , V_12 , V_66 ) ;
void T_1 * V_81 = F_2 ( V_3 , V_12 , V_16 ) ;
unsigned long V_38 ;
T_2 V_82 , V_84 , V_85 ;
int V_6 , V_51 = 0 ;
F_13 ( & V_3 -> V_39 , V_38 ) ;
V_82 = F_15 ( V_67 ) ;
V_84 = F_15 ( V_65 ) ;
for ( V_6 = 0 ; V_6 < V_106 ; V_6 ++ ) {
V_80 = F_32 ( V_105 [ V_6 ] ) ;
V_86 = F_35 ( V_105 [ V_6 ] ) ;
switch ( V_80 ) {
case V_88 :
V_82 &= ~ V_87 ;
break;
case V_89 :
if ( V_86 == 1 )
V_86 = 2000 ;
if ( V_84 & V_90 ) {
V_84 &= ~ V_90 ;
F_16 ( V_84 , V_65 ) ;
F_14 ( & V_3 -> V_43 -> V_44 ,
L_4 ,
V_12 ) ;
}
V_82 &= ~ V_87 ;
V_82 |= V_91 ;
V_51 = F_30 ( & V_82 , V_86 ) ;
break;
case V_92 :
if ( V_86 == 1 )
V_86 = 2000 ;
if ( V_84 & V_90 ) {
V_84 &= ~ V_90 ;
F_16 ( V_84 , V_65 ) ;
F_14 ( & V_3 -> V_43 -> V_44 ,
L_4 ,
V_12 ) ;
}
V_82 &= ~ V_87 ;
V_82 |= V_93 ;
V_51 = F_30 ( & V_82 , V_86 ) ;
break;
case V_94 :
V_85 = F_15 ( V_81 ) ;
V_85 &= ~ V_96 ;
if ( V_86 )
V_82 |= V_95 ;
else
V_82 &= ~ V_95 ;
switch ( V_86 ) {
case 375 :
V_85 |= V_97 ;
break;
case 750 :
V_85 |= V_98 ;
break;
case 1500 :
V_85 |= V_99 ;
break;
case 3000 :
V_85 |= V_100 ;
break;
case 6000 :
V_85 |= V_101 ;
break;
case 12000 :
V_85 |= V_102 ;
break;
case 24000 :
V_85 |= V_103 ;
break;
default:
if ( V_86 )
V_51 = - V_77 ;
break;
}
if ( ! V_51 )
F_16 ( V_85 , V_81 ) ;
break;
default:
V_51 = - V_104 ;
}
if ( V_51 )
break;
}
if ( ! V_51 )
F_16 ( V_82 , V_67 ) ;
F_17 ( & V_3 -> V_39 , V_38 ) ;
return V_51 ;
}
static int F_36 ( struct V_107 * V_108 , unsigned V_12 )
{
struct V_2 * V_3 = F_37 ( V_108 ) ;
void T_1 * V_13 = F_2 ( V_3 , V_12 , V_66 ) ;
unsigned long V_38 ;
T_2 V_84 ;
F_13 ( & V_3 -> V_39 , V_38 ) ;
V_84 = F_15 ( V_13 ) ;
F_17 ( & V_3 -> V_39 , V_38 ) ;
return ! ! ( V_84 & V_109 ) ;
}
static void F_38 ( struct V_107 * V_108 , unsigned V_12 , int V_41 )
{
struct V_2 * V_3 = F_37 ( V_108 ) ;
void T_1 * V_13 = F_2 ( V_3 , V_12 , V_66 ) ;
unsigned long V_38 ;
T_2 V_110 ;
if ( ! V_13 )
return;
F_13 ( & V_3 -> V_39 , V_38 ) ;
V_110 = F_15 ( V_13 ) ;
if ( V_41 )
F_16 ( V_110 | V_109 , V_13 ) ;
else
F_16 ( V_110 & ~ V_109 , V_13 ) ;
F_17 ( & V_3 -> V_39 , V_38 ) ;
}
static int F_39 ( struct V_107 * V_108 , unsigned int V_12 )
{
struct V_2 * V_3 = F_37 ( V_108 ) ;
void T_1 * V_13 = F_2 ( V_3 , V_12 , V_66 ) ;
unsigned long V_38 ;
T_2 V_41 ;
if ( ! V_13 )
return - V_77 ;
F_13 ( & V_3 -> V_39 , V_38 ) ;
V_41 = F_15 ( V_13 ) ;
F_17 ( & V_3 -> V_39 , V_38 ) ;
if ( ! ( V_41 & V_69 ) )
return V_111 ;
if ( ! ( V_41 & V_90 ) )
return V_112 ;
return - V_77 ;
}
static int F_40 ( struct V_107 * V_108 , unsigned int V_12 )
{
return F_41 ( V_108 -> V_113 + V_12 ) ;
}
static int F_42 ( struct V_107 * V_108 ,
unsigned int V_12 , int V_41 )
{
int V_51 = F_43 ( V_108 -> V_113 + V_12 ) ;
if ( V_51 )
return V_51 ;
F_38 ( V_108 , V_12 , V_41 ) ;
return 0 ;
}
static void F_44 ( struct V_114 * V_115 , struct V_107 * V_108 )
{
struct V_2 * V_3 = F_37 ( V_108 ) ;
int V_6 ;
T_2 V_116 , V_84 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 -> V_11 ; V_6 ++ ) {
const struct V_1 * V_5 ;
const char * V_117 = NULL ;
const char * V_83 = NULL ;
void T_1 * V_13 ;
unsigned long V_38 ;
const char * V_118 ;
unsigned int V_4 ;
F_13 ( & V_3 -> V_39 , V_38 ) ;
V_4 = V_3 -> V_7 -> V_25 [ V_6 ] . V_119 ;
V_13 = F_2 ( V_3 , V_4 , V_42 ) ;
if ( ! V_13 ) {
F_45 ( V_115 ,
L_5 ,
V_4 ) ;
F_17 ( & V_3 -> V_39 , V_38 ) ;
continue;
}
V_116 = F_15 ( V_13 ) ;
V_13 = F_2 ( V_3 , V_4 , V_66 ) ;
if ( ! V_13 ) {
F_45 ( V_115 ,
L_6 , V_4 ) ;
F_17 ( & V_3 -> V_39 , V_38 ) ;
continue;
}
V_84 = F_15 ( V_13 ) ;
F_17 ( & V_3 -> V_39 , V_38 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 ) {
F_45 ( V_115 ,
L_7 , V_4 ) ;
continue;
}
V_118 = F_46 ( V_108 , V_6 ) ;
if ( ! V_118 )
V_118 = L_8 ;
switch ( V_116 & V_87 ) {
case V_93 :
V_83 = L_9 ;
break;
case V_91 :
V_83 = L_10 ;
break;
}
switch ( V_116 & V_72 ) {
case V_73 :
V_117 = L_11 ;
break;
case V_74 :
V_117 = L_12 ;
break;
case V_75 :
V_117 = L_13 ;
break;
case V_76 :
V_117 = L_14 ;
break;
}
F_45 ( V_115 ,
L_15 ,
V_4 ,
V_118 ,
V_84 & V_90 ? L_16 : L_17 ,
V_84 & V_69 ? L_18 : L_19 ,
V_84 & V_109 ? L_20 : L_21 ,
V_5 -> V_17 [ V_6 ] , V_5 -> V_17 [ V_6 ] * 16 ,
V_116 & 0x7 ,
V_116 & V_58 ? L_22 : L_23 ,
V_116 & V_57 ? L_24 : L_23 ,
V_116 & V_59 ? L_25 : L_26 ) ;
if ( V_83 && V_117 )
F_45 ( V_115 , L_27 , V_83 , V_117 ) ;
else
F_47 ( V_115 , L_28 ) ;
if ( V_116 & V_120 )
F_47 ( V_115 , L_29 ) ;
F_47 ( V_115 , L_30 ) ;
}
}
static void F_48 ( struct V_121 * V_122 )
{
struct V_107 * V_123 = F_49 ( V_122 ) ;
struct V_2 * V_3 = F_37 ( V_123 ) ;
unsigned V_12 = F_50 ( V_122 ) ;
void T_1 * V_13 ;
V_13 = F_2 ( V_3 , V_12 , V_15 ) ;
if ( ! V_13 )
return;
F_51 ( & V_3 -> V_39 ) ;
F_16 ( F_52 ( V_12 % 32 ) , V_13 ) ;
F_53 ( & V_3 -> V_39 ) ;
}
static void F_54 ( struct V_121 * V_122 )
{
struct V_107 * V_123 = F_49 ( V_122 ) ;
struct V_2 * V_3 = F_37 ( V_123 ) ;
F_21 ( V_3 , F_50 ( V_122 ) ) ;
}
static void F_55 ( struct V_121 * V_122 )
{
struct V_107 * V_123 = F_49 ( V_122 ) ;
struct V_2 * V_3 = F_37 ( V_123 ) ;
unsigned V_12 = F_50 ( V_122 ) ;
unsigned long V_38 ;
void T_1 * V_13 ;
T_2 V_41 ;
V_13 = F_2 ( V_3 , V_12 , V_42 ) ;
if ( ! V_13 )
return;
F_13 ( & V_3 -> V_39 , V_38 ) ;
V_41 = F_15 ( V_13 ) ;
switch ( F_56 ( V_122 ) ) {
case V_124 :
V_41 |= V_59 ;
case V_125 :
V_41 |= V_57 ;
break;
case V_126 :
V_41 |= V_59 ;
case V_127 :
V_41 |= V_58 ;
break;
case V_128 :
V_41 |= ( V_58 | V_57 ) ;
break;
}
F_16 ( V_41 , V_13 ) ;
F_17 ( & V_3 -> V_39 , V_38 ) ;
}
static int F_57 ( struct V_121 * V_122 , unsigned int type )
{
struct V_2 * V_3 = F_37 ( F_49 ( V_122 ) ) ;
T_2 V_12 = F_50 ( V_122 ) ;
T_2 V_41 ;
unsigned long V_38 ;
void T_1 * V_13 = F_2 ( V_3 , V_12 , V_42 ) ;
if ( ! V_13 || V_12 >= V_3 -> V_108 . V_129 )
return - V_77 ;
F_13 ( & V_3 -> V_39 , V_38 ) ;
V_41 = F_15 ( V_13 ) ;
F_28 ( V_41 & V_70 ,
L_31 ) ;
V_41 &= ~ ( V_70 | V_57 | V_58 |
V_59 ) ;
F_16 ( V_41 , V_13 ) ;
if ( type & V_128 )
F_58 ( V_122 , V_130 ) ;
else if ( type & V_131 )
F_58 ( V_122 , V_132 ) ;
F_17 ( & V_3 -> V_39 , V_38 ) ;
return 0 ;
}
static void F_59 ( struct V_133 * V_134 )
{
struct V_121 * V_135 = F_60 ( V_134 ) ;
struct V_2 * V_3 = F_37 (
F_61 ( V_134 ) ) ;
struct V_136 * V_108 = F_62 ( V_135 ) ;
T_2 V_113 , V_4 ;
void T_1 * V_13 ;
unsigned long V_137 ;
unsigned int V_138 ;
for ( V_113 = 0 ; V_113 < V_3 -> V_108 . V_129 ; V_113 += 32 ) {
V_13 = F_2 ( V_3 , V_113 , V_15 ) ;
if ( ! V_13 ) {
F_14 ( & V_3 -> V_43 -> V_44 ,
L_32 ,
V_113 ) ;
continue;
}
F_51 ( & V_3 -> V_39 ) ;
V_137 = F_15 ( V_13 ) ;
F_53 ( & V_3 -> V_39 ) ;
F_63 (pin, &pending, 32 ) {
V_138 = F_64 ( V_3 -> V_108 . V_139 , V_113 + V_4 ) ;
F_65 ( V_138 ) ;
}
}
V_108 -> V_140 ( V_135 ) ;
}
static void F_66 ( struct V_2 * V_3 )
{
struct V_107 * V_123 = & V_3 -> V_108 ;
struct V_141 * V_44 = & V_3 -> V_43 -> V_44 ;
void T_1 * V_13 ;
T_2 V_113 , V_41 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 -> V_11 ; V_6 ++ ) {
unsigned int V_4 = V_3 -> V_7 -> V_25 [ V_6 ] . V_119 ;
V_13 = F_2 ( V_3 , V_4 , V_42 ) ;
if ( ! V_13 ) {
F_14 ( & V_3 -> V_43 -> V_44 ,
L_33 ,
V_6 ) ;
continue;
}
V_41 = F_15 ( V_13 ) ;
if ( V_41 & V_70 ) {
F_67 ( V_6 , V_123 -> V_142 ) ;
F_68 ( V_44 , L_34 , V_6 ) ;
} else if ( ( V_41 & V_45 ) == F_20 ( V_3 , V_6 ) ) {
F_21 ( V_3 , V_6 ) ;
F_68 ( V_44 , L_35 , V_6 ) ;
}
}
for ( V_113 = 0 ; V_113 < V_3 -> V_7 -> V_11 ; V_113 += 32 ) {
V_13 = F_2 ( V_3 , V_113 , V_15 ) ;
if ( ! V_13 ) {
F_14 ( & V_3 -> V_43 -> V_44 ,
L_36 ,
V_113 ) ;
continue;
}
F_16 ( 0xffffffff , V_13 ) ;
V_41 = F_15 ( V_13 ) ;
if ( V_41 )
F_69 ( & V_3 -> V_43 -> V_44 ,
L_37 ) ;
}
}
static int F_70 ( struct V_2 * V_3 )
{
struct V_107 * V_123 ;
struct V_143 * V_144 ;
int V_51 ;
V_3 -> V_108 = V_145 ;
V_123 = & V_3 -> V_108 ;
V_123 -> V_118 = F_71 ( & V_3 -> V_43 -> V_44 ) ;
V_123 -> V_113 = - 1 ;
V_123 -> V_146 = false ;
V_123 -> V_147 = & V_3 -> V_43 -> V_44 ;
V_123 -> V_129 = V_3 -> V_7 -> V_11 ;
V_123 -> V_148 = true ;
#ifdef F_72
V_3 -> V_149 = F_73 ( & V_3 -> V_43 -> V_44 , V_123 -> V_129 ,
sizeof( * V_3 -> V_149 ) , V_150 ) ;
#endif
V_51 = F_74 ( & V_3 -> V_43 -> V_44 , V_123 , V_3 ) ;
if ( V_51 ) {
F_69 ( & V_3 -> V_43 -> V_44 , L_38 ) ;
return V_51 ;
}
V_51 = F_75 ( & V_3 -> V_108 , F_71 ( & V_3 -> V_43 -> V_44 ) ,
0 , 0 , V_3 -> V_7 -> V_11 ) ;
if ( V_51 ) {
F_69 ( & V_3 -> V_43 -> V_44 , L_39 ) ;
return V_51 ;
}
V_144 = F_76 ( V_3 -> V_43 , V_151 , 0 ) ;
if ( V_144 && V_144 -> V_152 ) {
F_66 ( V_3 ) ;
V_51 = F_77 ( V_123 , & V_153 , 0 ,
V_154 , V_155 ) ;
if ( V_51 ) {
F_69 ( & V_3 -> V_43 -> V_44 , L_40 ) ;
return V_51 ;
}
F_78 ( V_123 , & V_153 ,
( unsigned ) V_144 -> V_152 ,
F_59 ) ;
}
return V_51 ;
}
static int F_79 ( struct V_2 * V_3 ,
const struct V_156 * V_7 )
{
int V_6 ;
V_3 -> V_7 = V_7 ;
V_3 -> V_9 = F_73 ( & V_3 -> V_43 -> V_44 ,
V_7 -> V_8 ,
sizeof( * V_3 -> V_9 ) ,
V_150 ) ;
if ( ! V_3 -> V_9 )
return - V_157 ;
for ( V_6 = 0 ; V_6 < V_7 -> V_8 ; V_6 ++ ) {
struct V_1 * V_5 = V_3 -> V_9 + V_6 ;
struct V_143 * V_158 ;
* V_5 = V_3 -> V_7 -> V_159 [ V_6 ] ;
V_158 = F_76 ( V_3 -> V_43 , V_160 , 0 ) ;
V_5 -> V_18 = F_80 ( & V_3 -> V_43 -> V_44 , V_158 ) ;
if ( F_81 ( V_5 -> V_18 ) )
return F_82 ( V_5 -> V_18 ) ;
}
return 0 ;
}
static int F_83 ( struct V_161 * V_43 )
{
const struct V_156 * V_7 = NULL ;
const struct V_156 * * V_162 ;
const struct V_163 * V_164 ;
struct V_165 * V_166 ;
struct V_2 * V_3 ;
int V_6 , V_51 ;
V_166 = F_84 ( & V_43 -> V_44 ) ;
if ( ! V_166 )
return - V_167 ;
V_164 = F_85 ( V_168 , & V_43 -> V_44 ) ;
if ( ! V_164 )
return - V_167 ;
V_162 = ( const struct V_156 * * ) V_164 -> V_169 ;
for ( V_6 = 0 ; V_162 [ V_6 ] ; V_6 ++ ) {
if ( ! strcmp ( V_166 -> V_170 . V_171 , V_162 [ V_6 ] -> V_54 ) ) {
V_7 = V_162 [ V_6 ] ;
break;
}
}
if ( ! V_7 )
return - V_167 ;
V_3 = F_86 ( & V_43 -> V_44 , sizeof( * V_3 ) , V_150 ) ;
if ( ! V_3 )
return - V_157 ;
V_3 -> V_43 = V_43 ;
V_51 = F_79 ( V_3 , V_7 ) ;
if ( V_51 ) {
F_69 ( & V_43 -> V_44 , L_41 ) ;
return V_51 ;
}
V_3 -> V_172 = V_173 ;
V_3 -> V_172 . V_24 = F_71 ( & V_43 -> V_44 ) ;
V_3 -> V_172 . V_25 = V_3 -> V_7 -> V_25 ;
V_3 -> V_172 . V_11 = V_3 -> V_7 -> V_11 ;
V_3 -> V_60 = F_87 ( & V_43 -> V_44 , & V_3 -> V_172 , V_3 ) ;
if ( F_81 ( V_3 -> V_60 ) ) {
F_69 ( & V_43 -> V_44 , L_42 ) ;
return F_82 ( V_3 -> V_60 ) ;
}
F_88 ( & V_3 -> V_39 ) ;
V_51 = F_70 ( V_3 ) ;
if ( V_51 )
return V_51 ;
F_89 ( V_43 , V_3 ) ;
F_90 ( & V_43 -> V_44 ) ;
return 0 ;
}
static int F_91 ( struct V_141 * V_44 )
{
struct V_161 * V_43 = F_92 ( V_44 ) ;
struct V_2 * V_3 = F_93 ( V_43 ) ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 -> V_11 ; V_6 ++ ) {
void T_1 * V_13 ;
T_2 V_41 ;
unsigned int V_4 = V_3 -> V_7 -> V_25 [ V_6 ] . V_119 ;
V_13 = F_2 ( V_3 , V_4 , V_42 ) ;
if ( ! V_13 ) {
F_14 ( & V_3 -> V_43 -> V_44 ,
L_33 ,
V_6 ) ;
continue;
}
V_41 = F_15 ( V_13 ) & V_174 ;
V_3 -> V_149 [ V_6 ] . V_116 = V_41 ;
V_13 = F_2 ( V_3 , V_4 , V_66 ) ;
V_41 = F_15 ( V_13 ) & V_175 ;
V_3 -> V_149 [ V_6 ] . V_84 = V_41 ;
}
return 0 ;
}
static int F_94 ( struct V_141 * V_44 )
{
struct V_161 * V_43 = F_92 ( V_44 ) ;
struct V_2 * V_3 = F_93 ( V_43 ) ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 -> V_11 ; V_6 ++ ) {
void T_1 * V_13 ;
T_2 V_41 ;
unsigned int V_4 = V_3 -> V_7 -> V_25 [ V_6 ] . V_119 ;
V_13 = F_2 ( V_3 , V_4 , V_42 ) ;
if ( ! V_13 ) {
F_14 ( & V_3 -> V_43 -> V_44 ,
L_33 ,
V_6 ) ;
continue;
}
V_41 = F_15 ( V_13 ) ;
if ( ( V_41 & V_174 ) !=
V_3 -> V_149 [ V_6 ] . V_116 ) {
V_41 &= ~ V_174 ;
V_41 |= V_3 -> V_149 [ V_6 ] . V_116 ;
F_16 ( V_41 , V_13 ) ;
F_95 ( V_44 , L_43 , V_6 , V_41 ) ;
}
V_13 = F_2 ( V_3 , V_4 , V_66 ) ;
V_41 = F_15 ( V_13 ) ;
if ( ( V_41 & V_175 ) !=
V_3 -> V_149 [ V_6 ] . V_84 ) {
T_2 V_176 ;
V_176 = V_41 & ~ V_175 ;
V_176 |= V_3 -> V_149 [ V_6 ] . V_84 ;
if ( V_176 != V_41 ) {
F_16 ( V_176 , V_13 ) ;
F_68 ( V_44 , L_44 ,
V_6 , V_176 ) ;
}
}
}
return 0 ;
}
static int F_96 ( struct V_141 * V_44 )
{
return 0 ;
}
static int F_97 ( struct V_141 * V_44 )
{
return 0 ;
}
static int T_4 F_98 ( void )
{
return F_99 ( & V_177 ) ;
}

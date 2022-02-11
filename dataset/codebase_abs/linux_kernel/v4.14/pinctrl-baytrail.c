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
if ( V_63 != V_41 ) {
V_41 = F_15 ( V_13 ) & ~ V_45 ;
V_41 |= V_63 ;
F_16 ( V_41 , V_13 ) ;
F_14 ( & V_3 -> V_43 -> V_44 , V_64
L_2 , V_12 ) ;
}
F_17 ( & V_3 -> V_39 , V_38 ) ;
F_23 ( & V_3 -> V_43 -> V_44 ) ;
return 0 ;
}
static void F_24 ( struct V_19 * V_60 ,
struct V_61 * V_62 ,
unsigned int V_12 )
{
struct V_2 * V_3 = F_4 ( V_60 ) ;
F_21 ( V_3 , V_12 ) ;
F_25 ( & V_3 -> V_43 -> V_44 ) ;
}
static int F_26 ( struct V_19 * V_60 ,
struct V_61 * V_62 ,
unsigned int V_12 ,
bool V_65 )
{
struct V_2 * V_3 = F_4 ( V_60 ) ;
void T_1 * V_66 = F_2 ( V_3 , V_12 , V_67 ) ;
void T_1 * V_68 = F_2 ( V_3 , V_12 , V_42 ) ;
unsigned long V_38 ;
T_2 V_41 ;
F_13 ( & V_3 -> V_39 , V_38 ) ;
V_41 = F_15 ( V_66 ) ;
V_41 &= ~ V_69 ;
if ( V_65 )
V_41 |= V_70 ;
else
F_27 ( F_15 ( V_68 ) & V_71 ,
L_3 ) ;
F_16 ( V_41 , V_66 ) ;
F_17 ( & V_3 -> V_39 , V_38 ) ;
return 0 ;
}
static void F_28 ( T_2 V_13 , T_3 * V_72 )
{
switch ( V_13 & V_73 ) {
case V_74 :
* V_72 = 2000 ;
break;
case V_75 :
* V_72 = 10000 ;
break;
case V_76 :
* V_72 = 20000 ;
break;
case V_77 :
* V_72 = 40000 ;
break;
}
}
static int F_29 ( T_2 * V_13 , T_3 V_72 )
{
* V_13 &= ~ V_73 ;
switch ( V_72 ) {
case 2000 :
* V_13 |= V_74 ;
break;
case 10000 :
* V_13 |= V_75 ;
break;
case 20000 :
* V_13 |= V_76 ;
break;
case 40000 :
* V_13 |= V_77 ;
break;
default:
return - V_78 ;
}
return 0 ;
}
static int F_30 ( struct V_19 * V_60 , unsigned int V_12 ,
unsigned long * V_79 )
{
struct V_2 * V_3 = F_4 ( V_60 ) ;
enum V_80 V_81 = F_31 ( * V_79 ) ;
void T_1 * V_68 = F_2 ( V_3 , V_12 , V_42 ) ;
void T_1 * V_66 = F_2 ( V_3 , V_12 , V_67 ) ;
void T_1 * V_82 = F_2 ( V_3 , V_12 , V_16 ) ;
unsigned long V_38 ;
T_2 V_83 , V_84 , V_85 , V_86 ;
T_3 V_87 = 0 ;
F_13 ( & V_3 -> V_39 , V_38 ) ;
V_83 = F_15 ( V_68 ) ;
V_84 = V_83 & V_88 ;
V_85 = F_15 ( V_66 ) ;
F_17 ( & V_3 -> V_39 , V_38 ) ;
switch ( V_81 ) {
case V_89 :
if ( V_84 )
return - V_78 ;
break;
case V_90 :
if ( ( V_85 & V_91 ) || V_84 != V_92 )
return - V_78 ;
F_28 ( V_83 , & V_87 ) ;
break;
case V_93 :
if ( ( V_85 & V_91 ) || V_84 != V_94 )
return - V_78 ;
F_28 ( V_83 , & V_87 ) ;
break;
case V_95 :
if ( ! ( V_83 & V_96 ) )
return - V_78 ;
F_13 ( & V_3 -> V_39 , V_38 ) ;
V_86 = F_15 ( V_82 ) ;
F_17 ( & V_3 -> V_39 , V_38 ) ;
switch ( V_86 & V_97 ) {
case V_98 :
V_87 = 375 ;
break;
case V_99 :
V_87 = 750 ;
break;
case V_100 :
V_87 = 1500 ;
break;
case V_101 :
V_87 = 3000 ;
break;
case V_102 :
V_87 = 6000 ;
break;
case V_103 :
V_87 = 12000 ;
break;
case V_104 :
V_87 = 24000 ;
break;
default:
return - V_78 ;
}
break;
default:
return - V_105 ;
}
* V_79 = F_32 ( V_81 , V_87 ) ;
return 0 ;
}
static int F_33 ( struct V_19 * V_60 ,
unsigned int V_12 ,
unsigned long * V_106 ,
unsigned int V_107 )
{
struct V_2 * V_3 = F_4 ( V_60 ) ;
unsigned int V_81 , V_87 ;
void T_1 * V_68 = F_2 ( V_3 , V_12 , V_42 ) ;
void T_1 * V_66 = F_2 ( V_3 , V_12 , V_67 ) ;
void T_1 * V_82 = F_2 ( V_3 , V_12 , V_16 ) ;
unsigned long V_38 ;
T_2 V_83 , V_85 , V_86 ;
int V_6 , V_51 = 0 ;
F_13 ( & V_3 -> V_39 , V_38 ) ;
V_83 = F_15 ( V_68 ) ;
V_85 = F_15 ( V_66 ) ;
for ( V_6 = 0 ; V_6 < V_107 ; V_6 ++ ) {
V_81 = F_31 ( V_106 [ V_6 ] ) ;
V_87 = F_34 ( V_106 [ V_6 ] ) ;
switch ( V_81 ) {
case V_89 :
V_83 &= ~ V_88 ;
break;
case V_90 :
if ( V_87 == 1 )
V_87 = 2000 ;
if ( V_85 & V_91 ) {
V_85 &= ~ V_91 ;
F_16 ( V_85 , V_66 ) ;
F_14 ( & V_3 -> V_43 -> V_44 ,
L_4 ,
V_12 ) ;
}
V_83 &= ~ V_88 ;
V_83 |= V_92 ;
V_51 = F_29 ( & V_83 , V_87 ) ;
break;
case V_93 :
if ( V_87 == 1 )
V_87 = 2000 ;
if ( V_85 & V_91 ) {
V_85 &= ~ V_91 ;
F_16 ( V_85 , V_66 ) ;
F_14 ( & V_3 -> V_43 -> V_44 ,
L_4 ,
V_12 ) ;
}
V_83 &= ~ V_88 ;
V_83 |= V_94 ;
V_51 = F_29 ( & V_83 , V_87 ) ;
break;
case V_95 :
V_86 = F_15 ( V_82 ) ;
V_86 &= ~ V_97 ;
if ( V_87 )
V_83 |= V_96 ;
else
V_83 &= ~ V_96 ;
switch ( V_87 ) {
case 375 :
V_86 |= V_98 ;
break;
case 750 :
V_86 |= V_99 ;
break;
case 1500 :
V_86 |= V_100 ;
break;
case 3000 :
V_86 |= V_101 ;
break;
case 6000 :
V_86 |= V_102 ;
break;
case 12000 :
V_86 |= V_103 ;
break;
case 24000 :
V_86 |= V_104 ;
break;
default:
if ( V_87 )
V_51 = - V_78 ;
break;
}
if ( ! V_51 )
F_16 ( V_86 , V_82 ) ;
break;
default:
V_51 = - V_105 ;
}
if ( V_51 )
break;
}
if ( ! V_51 )
F_16 ( V_83 , V_68 ) ;
F_17 ( & V_3 -> V_39 , V_38 ) ;
return V_51 ;
}
static int F_35 ( struct V_108 * V_109 , unsigned V_12 )
{
struct V_2 * V_3 = F_36 ( V_109 ) ;
void T_1 * V_13 = F_2 ( V_3 , V_12 , V_67 ) ;
unsigned long V_38 ;
T_2 V_85 ;
F_13 ( & V_3 -> V_39 , V_38 ) ;
V_85 = F_15 ( V_13 ) ;
F_17 ( & V_3 -> V_39 , V_38 ) ;
return ! ! ( V_85 & V_110 ) ;
}
static void F_37 ( struct V_108 * V_109 , unsigned V_12 , int V_41 )
{
struct V_2 * V_3 = F_36 ( V_109 ) ;
void T_1 * V_13 = F_2 ( V_3 , V_12 , V_67 ) ;
unsigned long V_38 ;
T_2 V_111 ;
if ( ! V_13 )
return;
F_13 ( & V_3 -> V_39 , V_38 ) ;
V_111 = F_15 ( V_13 ) ;
if ( V_41 )
F_16 ( V_111 | V_110 , V_13 ) ;
else
F_16 ( V_111 & ~ V_110 , V_13 ) ;
F_17 ( & V_3 -> V_39 , V_38 ) ;
}
static int F_38 ( struct V_108 * V_109 , unsigned int V_12 )
{
struct V_2 * V_3 = F_36 ( V_109 ) ;
void T_1 * V_13 = F_2 ( V_3 , V_12 , V_67 ) ;
unsigned long V_38 ;
T_2 V_41 ;
if ( ! V_13 )
return - V_78 ;
F_13 ( & V_3 -> V_39 , V_38 ) ;
V_41 = F_15 ( V_13 ) ;
F_17 ( & V_3 -> V_39 , V_38 ) ;
if ( ! ( V_41 & V_70 ) )
return V_112 ;
if ( ! ( V_41 & V_91 ) )
return V_113 ;
return - V_78 ;
}
static int F_39 ( struct V_108 * V_109 , unsigned int V_12 )
{
return F_40 ( V_109 -> V_114 + V_12 ) ;
}
static int F_41 ( struct V_108 * V_109 ,
unsigned int V_12 , int V_41 )
{
int V_51 = F_42 ( V_109 -> V_114 + V_12 ) ;
if ( V_51 )
return V_51 ;
F_37 ( V_109 , V_12 , V_41 ) ;
return 0 ;
}
static void F_43 ( struct V_115 * V_116 , struct V_108 * V_109 )
{
struct V_2 * V_3 = F_36 ( V_109 ) ;
int V_6 ;
T_2 V_117 , V_85 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 -> V_11 ; V_6 ++ ) {
const struct V_1 * V_5 ;
const char * V_118 = NULL ;
const char * V_84 = NULL ;
void T_1 * V_13 ;
unsigned long V_38 ;
const char * V_119 ;
unsigned int V_4 ;
F_13 ( & V_3 -> V_39 , V_38 ) ;
V_4 = V_3 -> V_7 -> V_25 [ V_6 ] . V_120 ;
V_13 = F_2 ( V_3 , V_4 , V_42 ) ;
if ( ! V_13 ) {
F_44 ( V_116 ,
L_5 ,
V_4 ) ;
F_17 ( & V_3 -> V_39 , V_38 ) ;
continue;
}
V_117 = F_15 ( V_13 ) ;
V_13 = F_2 ( V_3 , V_4 , V_67 ) ;
if ( ! V_13 ) {
F_44 ( V_116 ,
L_6 , V_4 ) ;
F_17 ( & V_3 -> V_39 , V_38 ) ;
continue;
}
V_85 = F_15 ( V_13 ) ;
F_17 ( & V_3 -> V_39 , V_38 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 ) {
F_44 ( V_116 ,
L_7 , V_4 ) ;
continue;
}
V_119 = F_45 ( V_109 , V_6 ) ;
if ( ! V_119 )
V_119 = L_8 ;
switch ( V_117 & V_88 ) {
case V_94 :
V_84 = L_9 ;
break;
case V_92 :
V_84 = L_10 ;
break;
}
switch ( V_117 & V_73 ) {
case V_74 :
V_118 = L_11 ;
break;
case V_75 :
V_118 = L_12 ;
break;
case V_76 :
V_118 = L_13 ;
break;
case V_77 :
V_118 = L_14 ;
break;
}
F_44 ( V_116 ,
L_15 ,
V_4 ,
V_119 ,
V_85 & V_91 ? L_16 : L_17 ,
V_85 & V_70 ? L_18 : L_19 ,
V_85 & V_110 ? L_20 : L_21 ,
V_5 -> V_17 [ V_6 ] , V_5 -> V_17 [ V_6 ] * 16 ,
V_117 & 0x7 ,
V_117 & V_58 ? L_22 : L_23 ,
V_117 & V_57 ? L_24 : L_23 ,
V_117 & V_59 ? L_25 : L_26 ) ;
if ( V_84 && V_118 )
F_44 ( V_116 , L_27 , V_84 , V_118 ) ;
else
F_46 ( V_116 , L_28 ) ;
if ( V_117 & V_121 )
F_46 ( V_116 , L_29 ) ;
F_46 ( V_116 , L_30 ) ;
}
}
static void F_47 ( struct V_122 * V_123 )
{
struct V_108 * V_124 = F_48 ( V_123 ) ;
struct V_2 * V_3 = F_36 ( V_124 ) ;
unsigned V_12 = F_49 ( V_123 ) ;
void T_1 * V_13 ;
V_13 = F_2 ( V_3 , V_12 , V_15 ) ;
if ( ! V_13 )
return;
F_50 ( & V_3 -> V_39 ) ;
F_16 ( F_51 ( V_12 % 32 ) , V_13 ) ;
F_52 ( & V_3 -> V_39 ) ;
}
static void F_53 ( struct V_122 * V_123 )
{
struct V_108 * V_124 = F_48 ( V_123 ) ;
struct V_2 * V_3 = F_36 ( V_124 ) ;
F_21 ( V_3 , F_49 ( V_123 ) ) ;
}
static void F_54 ( struct V_122 * V_123 )
{
struct V_108 * V_124 = F_48 ( V_123 ) ;
struct V_2 * V_3 = F_36 ( V_124 ) ;
unsigned V_12 = F_49 ( V_123 ) ;
unsigned long V_38 ;
void T_1 * V_13 ;
T_2 V_41 ;
V_13 = F_2 ( V_3 , V_12 , V_42 ) ;
if ( ! V_13 )
return;
F_13 ( & V_3 -> V_39 , V_38 ) ;
V_41 = F_15 ( V_13 ) ;
switch ( F_55 ( V_123 ) ) {
case V_125 :
V_41 |= V_59 ;
case V_126 :
V_41 |= V_57 ;
break;
case V_127 :
V_41 |= V_59 ;
case V_128 :
V_41 |= V_58 ;
break;
case V_129 :
V_41 |= ( V_58 | V_57 ) ;
break;
}
F_16 ( V_41 , V_13 ) ;
F_17 ( & V_3 -> V_39 , V_38 ) ;
}
static int F_56 ( struct V_122 * V_123 , unsigned int type )
{
struct V_2 * V_3 = F_36 ( F_48 ( V_123 ) ) ;
T_2 V_12 = F_49 ( V_123 ) ;
T_2 V_41 ;
unsigned long V_38 ;
void T_1 * V_13 = F_2 ( V_3 , V_12 , V_42 ) ;
if ( ! V_13 || V_12 >= V_3 -> V_109 . V_130 )
return - V_78 ;
F_13 ( & V_3 -> V_39 , V_38 ) ;
V_41 = F_15 ( V_13 ) ;
F_27 ( V_41 & V_71 ,
L_31 ) ;
V_41 &= ~ ( V_71 | V_57 | V_58 |
V_59 ) ;
F_16 ( V_41 , V_13 ) ;
if ( type & V_129 )
F_57 ( V_123 , V_131 ) ;
else if ( type & V_132 )
F_57 ( V_123 , V_133 ) ;
F_17 ( & V_3 -> V_39 , V_38 ) ;
return 0 ;
}
static void F_58 ( struct V_134 * V_135 )
{
struct V_122 * V_136 = F_59 ( V_135 ) ;
struct V_2 * V_3 = F_36 (
F_60 ( V_135 ) ) ;
struct V_137 * V_109 = F_61 ( V_136 ) ;
T_2 V_114 , V_4 ;
void T_1 * V_13 ;
unsigned long V_138 ;
unsigned int V_139 ;
for ( V_114 = 0 ; V_114 < V_3 -> V_109 . V_130 ; V_114 += 32 ) {
V_13 = F_2 ( V_3 , V_114 , V_15 ) ;
if ( ! V_13 ) {
F_14 ( & V_3 -> V_43 -> V_44 ,
L_32 ,
V_114 ) ;
continue;
}
F_50 ( & V_3 -> V_39 ) ;
V_138 = F_15 ( V_13 ) ;
F_52 ( & V_3 -> V_39 ) ;
F_62 (pin, &pending, 32 ) {
V_139 = F_63 ( V_3 -> V_109 . V_140 , V_114 + V_4 ) ;
F_64 ( V_139 ) ;
}
}
V_109 -> V_141 ( V_136 ) ;
}
static void F_65 ( struct V_2 * V_3 )
{
struct V_108 * V_124 = & V_3 -> V_109 ;
struct V_142 * V_44 = & V_3 -> V_43 -> V_44 ;
void T_1 * V_13 ;
T_2 V_114 , V_41 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 -> V_11 ; V_6 ++ ) {
unsigned int V_4 = V_3 -> V_7 -> V_25 [ V_6 ] . V_120 ;
V_13 = F_2 ( V_3 , V_4 , V_42 ) ;
if ( ! V_13 ) {
F_14 ( & V_3 -> V_43 -> V_44 ,
L_33 ,
V_6 ) ;
continue;
}
V_41 = F_15 ( V_13 ) ;
if ( V_41 & V_71 ) {
F_66 ( V_6 , V_124 -> V_143 ) ;
F_67 ( V_44 , L_34 , V_6 ) ;
} else if ( ( V_41 & V_45 ) == F_20 ( V_3 , V_6 ) ) {
F_21 ( V_3 , V_6 ) ;
F_67 ( V_44 , L_35 , V_6 ) ;
}
}
for ( V_114 = 0 ; V_114 < V_3 -> V_7 -> V_11 ; V_114 += 32 ) {
V_13 = F_2 ( V_3 , V_114 , V_15 ) ;
if ( ! V_13 ) {
F_14 ( & V_3 -> V_43 -> V_44 ,
L_36 ,
V_114 ) ;
continue;
}
F_16 ( 0xffffffff , V_13 ) ;
V_41 = F_15 ( V_13 ) ;
if ( V_41 )
F_68 ( & V_3 -> V_43 -> V_44 ,
L_37 ) ;
}
}
static int F_69 ( struct V_2 * V_3 )
{
struct V_108 * V_124 ;
struct V_144 * V_145 ;
int V_51 ;
V_3 -> V_109 = V_146 ;
V_124 = & V_3 -> V_109 ;
V_124 -> V_119 = F_70 ( & V_3 -> V_43 -> V_44 ) ;
V_124 -> V_114 = - 1 ;
V_124 -> V_147 = false ;
V_124 -> V_148 = & V_3 -> V_43 -> V_44 ;
V_124 -> V_130 = V_3 -> V_7 -> V_11 ;
V_124 -> V_149 = true ;
#ifdef F_71
V_3 -> V_150 = F_72 ( & V_3 -> V_43 -> V_44 , V_124 -> V_130 ,
sizeof( * V_3 -> V_150 ) , V_151 ) ;
#endif
V_51 = F_73 ( & V_3 -> V_43 -> V_44 , V_124 , V_3 ) ;
if ( V_51 ) {
F_68 ( & V_3 -> V_43 -> V_44 , L_38 ) ;
return V_51 ;
}
V_51 = F_74 ( & V_3 -> V_109 , F_70 ( & V_3 -> V_43 -> V_44 ) ,
0 , 0 , V_3 -> V_7 -> V_11 ) ;
if ( V_51 ) {
F_68 ( & V_3 -> V_43 -> V_44 , L_39 ) ;
return V_51 ;
}
V_145 = F_75 ( V_3 -> V_43 , V_152 , 0 ) ;
if ( V_145 && V_145 -> V_153 ) {
F_65 ( V_3 ) ;
V_51 = F_76 ( V_124 , & V_154 , 0 ,
V_155 , V_156 ) ;
if ( V_51 ) {
F_68 ( & V_3 -> V_43 -> V_44 , L_40 ) ;
return V_51 ;
}
F_77 ( V_124 , & V_154 ,
( unsigned ) V_145 -> V_153 ,
F_58 ) ;
}
return V_51 ;
}
static int F_78 ( struct V_2 * V_3 ,
const struct V_157 * V_7 )
{
int V_6 ;
V_3 -> V_7 = V_7 ;
V_3 -> V_9 = F_72 ( & V_3 -> V_43 -> V_44 ,
V_7 -> V_8 ,
sizeof( * V_3 -> V_9 ) ,
V_151 ) ;
if ( ! V_3 -> V_9 )
return - V_158 ;
for ( V_6 = 0 ; V_6 < V_7 -> V_8 ; V_6 ++ ) {
struct V_1 * V_5 = V_3 -> V_9 + V_6 ;
struct V_144 * V_159 ;
* V_5 = V_3 -> V_7 -> V_160 [ V_6 ] ;
V_159 = F_75 ( V_3 -> V_43 , V_161 , 0 ) ;
V_5 -> V_18 = F_79 ( & V_3 -> V_43 -> V_44 , V_159 ) ;
if ( F_80 ( V_5 -> V_18 ) )
return F_81 ( V_5 -> V_18 ) ;
}
return 0 ;
}
static int F_82 ( struct V_162 * V_43 )
{
const struct V_157 * V_7 = NULL ;
const struct V_157 * * V_163 ;
const struct V_164 * V_165 ;
struct V_166 * V_167 ;
struct V_2 * V_3 ;
int V_6 , V_51 ;
V_167 = F_83 ( & V_43 -> V_44 ) ;
if ( ! V_167 )
return - V_168 ;
V_165 = F_84 ( V_169 , & V_43 -> V_44 ) ;
if ( ! V_165 )
return - V_168 ;
V_163 = ( const struct V_157 * * ) V_165 -> V_170 ;
for ( V_6 = 0 ; V_163 [ V_6 ] ; V_6 ++ ) {
if ( ! strcmp ( V_167 -> V_171 . V_172 , V_163 [ V_6 ] -> V_54 ) ) {
V_7 = V_163 [ V_6 ] ;
break;
}
}
if ( ! V_7 )
return - V_168 ;
V_3 = F_85 ( & V_43 -> V_44 , sizeof( * V_3 ) , V_151 ) ;
if ( ! V_3 )
return - V_158 ;
V_3 -> V_43 = V_43 ;
V_51 = F_78 ( V_3 , V_7 ) ;
if ( V_51 ) {
F_68 ( & V_43 -> V_44 , L_41 ) ;
return V_51 ;
}
V_3 -> V_173 = V_174 ;
V_3 -> V_173 . V_24 = F_70 ( & V_43 -> V_44 ) ;
V_3 -> V_173 . V_25 = V_3 -> V_7 -> V_25 ;
V_3 -> V_173 . V_11 = V_3 -> V_7 -> V_11 ;
V_3 -> V_60 = F_86 ( & V_43 -> V_44 , & V_3 -> V_173 , V_3 ) ;
if ( F_80 ( V_3 -> V_60 ) ) {
F_68 ( & V_43 -> V_44 , L_42 ) ;
return F_81 ( V_3 -> V_60 ) ;
}
F_87 ( & V_3 -> V_39 ) ;
V_51 = F_69 ( V_3 ) ;
if ( V_51 )
return V_51 ;
F_88 ( V_43 , V_3 ) ;
F_89 ( & V_43 -> V_44 ) ;
return 0 ;
}
static int F_90 ( struct V_142 * V_44 )
{
struct V_162 * V_43 = F_91 ( V_44 ) ;
struct V_2 * V_3 = F_92 ( V_43 ) ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 -> V_11 ; V_6 ++ ) {
void T_1 * V_13 ;
T_2 V_41 ;
unsigned int V_4 = V_3 -> V_7 -> V_25 [ V_6 ] . V_120 ;
V_13 = F_2 ( V_3 , V_4 , V_42 ) ;
if ( ! V_13 ) {
F_14 ( & V_3 -> V_43 -> V_44 ,
L_33 ,
V_6 ) ;
continue;
}
V_41 = F_15 ( V_13 ) & V_175 ;
V_3 -> V_150 [ V_6 ] . V_117 = V_41 ;
V_13 = F_2 ( V_3 , V_4 , V_67 ) ;
V_41 = F_15 ( V_13 ) & V_176 ;
V_3 -> V_150 [ V_6 ] . V_85 = V_41 ;
}
return 0 ;
}
static int F_93 ( struct V_142 * V_44 )
{
struct V_162 * V_43 = F_91 ( V_44 ) ;
struct V_2 * V_3 = F_92 ( V_43 ) ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 -> V_11 ; V_6 ++ ) {
void T_1 * V_13 ;
T_2 V_41 ;
unsigned int V_4 = V_3 -> V_7 -> V_25 [ V_6 ] . V_120 ;
V_13 = F_2 ( V_3 , V_4 , V_42 ) ;
if ( ! V_13 ) {
F_14 ( & V_3 -> V_43 -> V_44 ,
L_33 ,
V_6 ) ;
continue;
}
V_41 = F_15 ( V_13 ) ;
if ( ( V_41 & V_175 ) !=
V_3 -> V_150 [ V_6 ] . V_117 ) {
V_41 &= ~ V_175 ;
V_41 |= V_3 -> V_150 [ V_6 ] . V_117 ;
F_16 ( V_41 , V_13 ) ;
F_94 ( V_44 , L_43 , V_6 , V_41 ) ;
}
V_13 = F_2 ( V_3 , V_4 , V_67 ) ;
V_41 = F_15 ( V_13 ) ;
if ( ( V_41 & V_176 ) !=
V_3 -> V_150 [ V_6 ] . V_85 ) {
T_2 V_177 ;
V_177 = V_41 & ~ V_176 ;
V_177 |= V_3 -> V_150 [ V_6 ] . V_85 ;
if ( V_177 != V_41 ) {
F_16 ( V_177 , V_13 ) ;
F_67 ( V_44 , L_44 ,
V_6 , V_177 ) ;
}
}
}
return 0 ;
}
static int F_95 ( struct V_142 * V_44 )
{
return 0 ;
}
static int F_96 ( struct V_142 * V_44 )
{
return 0 ;
}
static int T_4 F_97 ( void )
{
return F_98 ( & V_178 ) ;
}

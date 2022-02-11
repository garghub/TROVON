static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 -> V_5 ;
}
static void F_2 ( unsigned long V_6 )
{
struct V_2 * V_3 = (struct V_2 * ) V_6 ;
F_3 ( 0 , V_3 ) ;
F_4 ( & V_3 -> V_7 ) ;
if ( ! V_8 )
V_8 = 2 ;
F_5 ( V_3 , V_8 ) ;
}
static void F_5 ( struct V_2 * V_3 , int V_9 )
{
if ( ( V_9 <= 0 ) || ( V_9 > 60 ) )
V_9 = 2 ;
V_3 -> V_7 . V_10 = & F_2 ;
V_3 -> V_7 . V_6 = ( unsigned long ) V_3 ;
V_3 -> V_7 . V_11 = V_12 + V_9 * V_13 ;
F_6 ( & V_3 -> V_7 ) ;
}
static inline int F_7 ( struct V_2 * V_3 )
{
int V_14 , V_15 = V_3 -> V_4 -> V_15 ;
if ( V_16 ) {
F_4 ( & V_3 -> V_7 ) ;
F_5 ( V_3 , 10 ) ;
return 0 ;
}
V_14 = F_8 ( V_15 , F_3 , V_17 , V_18 , V_3 ) ;
if ( V_14 )
F_9 ( V_3 , L_1 ,
V_15 ) ;
return V_14 ;
}
static inline void F_10 ( struct V_2 * V_3 )
{
if ( V_16 )
F_11 ( & V_3 -> V_7 ) ;
else
F_12 ( V_3 -> V_4 -> V_15 , V_3 ) ;
}
static int F_13 ( struct V_2 * V_3 , int V_19 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
T_1 V_21 ;
F_14 ( V_20 , V_22 , & V_21 ) ;
if ( V_21 & V_23 ) {
F_15 ( V_20 , V_22 ,
V_23 ) ;
return 1 ;
}
while ( V_19 > 0 ) {
F_16 ( 10 ) ;
V_19 -= 10 ;
F_14 ( V_20 , V_22 , & V_21 ) ;
if ( V_21 & V_23 ) {
F_15 ( V_20 , V_22 ,
V_23 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_17 ( struct V_2 * V_3 )
{
unsigned int V_24 = V_16 ? 2500 : 1000 ;
unsigned long V_25 = F_18 ( V_24 ) ;
unsigned long V_26 = V_3 -> V_27 + V_25 ;
unsigned long V_28 , V_19 ;
int V_29 ;
if ( F_19 ( V_3 ) )
return;
if ( ! V_3 -> V_30 )
return;
V_28 = V_12 ;
if ( F_20 ( V_26 , V_28 ) )
V_19 = 1 ;
else
V_19 = V_26 - V_28 ;
if ( V_3 -> V_31 & V_32 &&
V_3 -> V_31 & V_33 )
V_29 = F_21 ( V_3 -> V_34 , ! V_3 -> V_30 , V_19 ) ;
else
V_29 = F_13 ( V_3 , F_22 ( V_19 ) ) ;
if ( ! V_29 )
F_23 ( V_3 , L_2 ,
V_3 -> V_31 ,
F_22 ( V_12 - V_3 -> V_27 ) ) ;
}
static void F_24 ( struct V_2 * V_3 , T_1 V_35 ,
T_1 V_36 , bool V_37 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
T_1 V_31 ;
F_25 ( & V_3 -> V_38 ) ;
F_17 ( V_3 ) ;
F_14 ( V_20 , V_39 , & V_31 ) ;
V_31 &= ~ V_36 ;
V_31 |= ( V_35 & V_36 ) ;
V_3 -> V_30 = 1 ;
F_26 () ;
F_15 ( V_20 , V_39 , V_31 ) ;
V_3 -> V_27 = V_12 ;
V_3 -> V_31 = V_31 ;
if ( V_37 )
F_17 ( V_3 ) ;
F_27 ( & V_3 -> V_38 ) ;
}
static void F_28 ( struct V_2 * V_3 , T_1 V_35 , T_1 V_36 )
{
F_24 ( V_3 , V_35 , V_36 , true ) ;
}
static void F_29 ( struct V_2 * V_3 , T_1 V_35 , T_1 V_36 )
{
F_24 ( V_3 , V_35 , V_36 , false ) ;
}
bool F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
T_1 V_40 ;
bool V_41 ;
F_14 ( V_20 , V_42 , & V_40 ) ;
V_41 = ! ! ( V_40 & V_43 ) ;
if ( V_41 )
F_31 ( V_3 , L_3 , V_44 , V_40 ) ;
return V_41 ;
}
static void F_32 ( struct V_2 * V_3 , bool V_45 )
{
int V_19 = 1000 ;
if ( F_30 ( V_3 ) == V_45 )
return;
while ( V_19 > 0 ) {
F_16 ( 10 ) ;
V_19 -= 10 ;
if ( F_30 ( V_3 ) == V_45 )
return;
}
F_31 ( V_3 , L_4 ,
V_45 ? L_5 : L_6 ) ;
}
static void F_33 ( struct V_2 * V_3 )
{
F_32 ( V_3 , true ) ;
}
static bool F_34 ( struct V_46 * V_47 , int V_48 )
{
T_2 V_49 ;
int V_50 = 0 ;
int V_51 = 1000 , V_52 = 20 ;
bool V_53 = false ;
do {
V_53 = F_35 ( V_47 , V_48 , & V_49 , 0 ) ;
V_50 ++ ;
if ( V_53 )
break;
F_16 ( V_52 ) ;
V_51 -= V_52 ;
} while ( V_51 > 0 );
if ( V_50 > 1 && V_54 )
F_36 ( V_55 L_7 ,
F_37 ( V_47 ) , V_47 -> V_56 , F_38 ( V_48 ) ,
F_39 ( V_48 ) , V_50 , V_52 , V_49 ) ;
return V_53 ;
}
int F_40 ( struct V_2 * V_3 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
bool V_53 ;
T_1 V_40 ;
if ( V_3 -> V_57 )
F_33 ( V_3 ) ;
else
F_16 ( 1000 ) ;
F_16 ( 100 ) ;
V_53 = F_34 ( V_3 -> V_4 -> V_5 -> V_58 ,
F_41 ( 0 , 0 ) ) ;
F_14 ( V_20 , V_42 , & V_40 ) ;
F_31 ( V_3 , L_3 , V_44 , V_40 ) ;
if ( ( V_40 & V_59 ) ||
! ( V_40 & V_60 ) ) {
F_9 ( V_3 , L_8 ,
V_40 ) ;
return - 1 ;
}
F_42 ( V_3 -> V_4 -> V_5 -> V_58 , V_40 ) ;
if ( ! V_53 )
return - 1 ;
return 0 ;
}
static int F_43 ( struct V_2 * V_3 , bool V_61 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
T_1 V_62 ;
F_14 ( V_20 , V_63 , & V_62 ) ;
if ( V_61 )
V_62 &= ~ V_64 ;
else
V_62 |= V_64 ;
F_15 ( V_20 , V_63 , V_62 ) ;
F_31 ( V_3 , L_9 , V_44 , V_62 ) ;
return 0 ;
}
static int F_44 ( struct V_2 * V_3 )
{
return F_43 ( V_3 , true ) ;
}
void F_45 ( struct V_65 * V_65 , T_3 * V_66 )
{
struct V_2 * V_3 = V_65 -> V_3 ;
struct V_1 * V_20 = F_1 ( V_3 ) ;
T_1 V_31 ;
F_14 ( V_20 , V_39 , & V_31 ) ;
F_31 ( V_3 , L_10 , V_44 ,
F_46 ( V_3 -> V_4 -> V_5 ) + V_39 , V_31 ) ;
switch ( V_31 & V_67 ) {
case V_68 :
* V_66 = 1 ;
break;
case V_69 :
* V_66 = 2 ;
break;
case V_70 :
* V_66 = 0 ;
break;
default:
* V_66 = 0xFF ;
break;
}
}
void F_47 ( struct V_65 * V_65 , T_3 * V_66 )
{
struct V_2 * V_3 = V_65 -> V_3 ;
struct V_1 * V_20 = F_1 ( V_3 ) ;
T_1 V_31 ;
F_14 ( V_20 , V_39 , & V_31 ) ;
F_31 ( V_3 , L_11 , V_44 ,
F_46 ( V_3 -> V_4 -> V_5 ) + V_39 , V_31 ) ;
switch ( V_31 & V_71 ) {
case V_72 :
* V_66 = 1 ;
break;
case V_73 :
* V_66 = 0 ;
break;
default:
* V_66 = 0xFF ;
break;
}
}
void F_48 ( struct V_65 * V_65 , T_3 * V_66 )
{
struct V_1 * V_20 = F_1 ( V_65 -> V_3 ) ;
T_1 V_21 ;
F_14 ( V_20 , V_22 , & V_21 ) ;
* V_66 = ! ! ( V_21 & V_74 ) ;
}
void F_49 ( struct V_65 * V_65 , T_3 * V_66 )
{
struct V_1 * V_20 = F_1 ( V_65 -> V_3 ) ;
T_1 V_21 ;
F_14 ( V_20 , V_22 , & V_21 ) ;
* V_66 = ! ! ( V_21 & V_75 ) ;
}
int F_50 ( struct V_65 * V_65 )
{
struct V_1 * V_20 = F_1 ( V_65 -> V_3 ) ;
T_1 V_21 ;
F_14 ( V_20 , V_22 , & V_21 ) ;
return ! ! ( V_21 & V_76 ) ;
}
void F_51 ( struct V_65 * V_65 , T_3 V_77 )
{
struct V_2 * V_3 = V_65 -> V_3 ;
T_1 V_78 ;
if ( ! F_52 ( V_3 ) )
return;
switch ( V_77 ) {
case 0 :
V_78 = V_70 ;
break;
case 1 :
V_78 = V_68 ;
break;
case 2 :
V_78 = V_69 ;
break;
default:
return;
}
F_29 ( V_3 , V_78 , V_67 ) ;
F_31 ( V_3 , L_12 , V_44 ,
F_46 ( V_3 -> V_4 -> V_5 ) + V_39 , V_78 ) ;
}
void F_53 ( struct V_65 * V_65 )
{
struct V_2 * V_3 = V_65 -> V_3 ;
if ( ! F_54 ( V_3 ) )
return;
F_29 ( V_3 , V_79 ,
V_80 ) ;
F_31 ( V_3 , L_12 , V_44 ,
F_46 ( V_3 -> V_4 -> V_5 ) + V_39 ,
V_79 ) ;
}
void F_55 ( struct V_65 * V_65 )
{
struct V_2 * V_3 = V_65 -> V_3 ;
if ( ! F_54 ( V_3 ) )
return;
F_29 ( V_3 , V_81 ,
V_80 ) ;
F_31 ( V_3 , L_12 , V_44 ,
F_46 ( V_3 -> V_4 -> V_5 ) + V_39 ,
V_81 ) ;
}
void F_56 ( struct V_65 * V_65 )
{
struct V_2 * V_3 = V_65 -> V_3 ;
if ( ! F_54 ( V_3 ) )
return;
F_29 ( V_3 , V_82 ,
V_80 ) ;
F_31 ( V_3 , L_12 , V_44 ,
F_46 ( V_3 -> V_4 -> V_5 ) + V_39 ,
V_82 ) ;
}
int F_57 ( struct V_65 * V_65 )
{
struct V_2 * V_3 = V_65 -> V_3 ;
struct V_1 * V_20 = F_1 ( V_3 ) ;
T_1 V_21 ;
int V_14 ;
F_14 ( V_20 , V_22 , & V_21 ) ;
if ( V_21 & V_76 )
F_15 ( V_20 , V_22 ,
V_76 ) ;
V_3 -> V_83 = 0 ;
F_28 ( V_3 , V_72 , V_71 ) ;
F_31 ( V_3 , L_12 , V_44 ,
F_46 ( V_3 -> V_4 -> V_5 ) + V_39 ,
V_72 ) ;
V_14 = F_44 ( V_3 ) ;
if ( V_14 )
F_9 ( V_3 , L_13 , V_44 ) ;
return V_14 ;
}
void F_58 ( struct V_65 * V_65 )
{
struct V_2 * V_3 = V_65 -> V_3 ;
F_28 ( V_3 , V_73 , V_71 ) ;
F_31 ( V_3 , L_12 , V_44 ,
F_46 ( V_3 -> V_4 -> V_5 ) + V_39 ,
V_73 ) ;
}
static T_4 F_3 ( int V_15 , void * V_84 )
{
struct V_2 * V_3 = (struct V_2 * ) V_84 ;
struct V_1 * V_20 = F_1 ( V_3 ) ;
struct V_46 * V_58 = V_20 -> V_58 ;
struct V_1 * V_85 ;
struct V_65 * V_65 = V_3 -> V_65 ;
T_1 V_86 , V_87 ;
T_3 V_88 , V_89 ;
bool V_90 ;
V_87 = 0 ;
do {
F_14 ( V_20 , V_22 , & V_86 ) ;
V_86 &= ( V_91 | V_76 |
V_92 | V_93 |
V_23 | V_94 ) ;
V_86 &= ~ V_87 ;
V_87 |= V_86 ;
if ( ! V_87 )
return V_95 ;
if ( V_86 )
F_15 ( V_20 , V_22 ,
V_87 ) ;
} while ( V_86 );
F_31 ( V_3 , L_14 , V_87 ) ;
if ( V_87 & V_23 ) {
V_3 -> V_30 = 0 ;
F_26 () ;
F_59 ( & V_3 -> V_34 ) ;
}
if ( V_58 ) {
F_60 (dev, &subordinate->devices, bus_list) {
if ( V_85 -> V_96 ) {
F_31 ( V_3 , L_15 ,
V_87 , F_61 ( V_85 ) ) ;
return V_97 ;
}
}
}
if ( ! ( V_87 & ~ V_23 ) )
return V_97 ;
if ( V_87 & V_92 ) {
F_48 ( V_65 , & V_88 ) ;
F_23 ( V_3 , L_16 ,
V_88 ? L_17 : L_18 , F_62 ( V_65 ) ) ;
F_63 ( V_65 , V_88 ? V_98 :
V_99 ) ;
}
if ( V_87 & V_91 ) {
F_23 ( V_3 , L_19 ,
F_62 ( V_65 ) ) ;
F_63 ( V_65 , V_100 ) ;
}
if ( V_87 & V_93 ) {
F_49 ( V_65 , & V_89 ) ;
F_23 ( V_3 , L_20 ,
V_89 ? L_21 : L_22 , F_62 ( V_65 ) ) ;
F_63 ( V_65 , V_89 ? V_101 :
V_102 ) ;
}
if ( ( V_87 & V_76 ) && ! V_3 -> V_83 ) {
V_3 -> V_83 = 1 ;
F_9 ( V_3 , L_23 , F_62 ( V_65 ) ) ;
F_63 ( V_65 , V_103 ) ;
}
if ( V_87 & V_94 ) {
V_90 = F_30 ( V_3 ) ;
F_23 ( V_3 , L_24 ,
F_62 ( V_65 ) , V_90 ? L_25 : L_26 ) ;
F_63 ( V_65 , V_90 ? V_104 :
V_105 ) ;
}
return V_97 ;
}
void F_64 ( struct V_2 * V_3 )
{
T_1 V_35 , V_36 ;
V_35 = V_106 ;
if ( F_65 ( V_3 ) )
V_35 |= V_107 ;
else
V_35 |= V_108 ;
if ( F_66 ( V_3 ) )
V_35 |= V_109 ;
if ( ! V_16 )
V_35 |= V_32 | V_33 ;
V_36 = ( V_108 | V_107 |
V_109 | V_110 |
V_32 | V_33 |
V_106 ) ;
F_29 ( V_3 , V_35 , V_36 ) ;
F_31 ( V_3 , L_12 , V_44 ,
F_46 ( V_3 -> V_4 -> V_5 ) + V_39 , V_35 ) ;
}
static void F_67 ( struct V_2 * V_3 )
{
T_1 V_36 ;
V_36 = ( V_108 | V_107 |
V_109 | V_110 |
V_32 | V_33 |
V_106 ) ;
F_28 ( V_3 , 0 , V_36 ) ;
F_31 ( V_3 , L_12 , V_44 ,
F_46 ( V_3 -> V_4 -> V_5 ) + V_39 , 0 ) ;
}
int F_68 ( struct V_65 * V_65 , int V_111 )
{
struct V_2 * V_3 = V_65 -> V_3 ;
struct V_1 * V_20 = F_1 ( V_3 ) ;
T_1 V_112 = 0 , V_113 = 0 ;
if ( V_111 )
return 0 ;
if ( ! F_65 ( V_3 ) ) {
V_113 |= V_108 ;
V_112 |= V_93 ;
}
V_113 |= V_106 ;
V_112 |= V_94 ;
F_28 ( V_3 , 0 , V_113 ) ;
F_31 ( V_3 , L_12 , V_44 ,
F_46 ( V_3 -> V_4 -> V_5 ) + V_39 , 0 ) ;
if ( V_16 )
F_11 ( & V_3 -> V_7 ) ;
F_69 ( V_3 -> V_4 -> V_5 ) ;
F_15 ( V_20 , V_22 , V_112 ) ;
F_29 ( V_3 , V_113 , V_113 ) ;
F_31 ( V_3 , L_12 , V_44 ,
F_46 ( V_3 -> V_4 -> V_5 ) + V_39 , V_113 ) ;
if ( V_16 )
F_2 ( V_3 -> V_7 . V_6 ) ;
return 0 ;
}
int F_70 ( struct V_2 * V_3 )
{
if ( F_7 ( V_3 ) )
return - 1 ;
F_64 ( V_3 ) ;
V_3 -> V_114 = 1 ;
return 0 ;
}
static void F_71 ( struct V_2 * V_3 )
{
if ( V_3 -> V_114 ) {
F_67 ( V_3 ) ;
F_10 ( V_3 ) ;
V_3 -> V_114 = 0 ;
}
}
static int F_72 ( struct V_2 * V_3 )
{
struct V_65 * V_65 ;
V_65 = F_73 ( sizeof( * V_65 ) , V_115 ) ;
if ( ! V_65 )
return - V_116 ;
V_65 -> V_117 = F_74 ( L_27 , 0 , 0 , F_75 ( V_3 ) ) ;
if ( ! V_65 -> V_117 )
goto abort;
V_65 -> V_3 = V_3 ;
F_76 ( & V_65 -> V_118 ) ;
F_76 ( & V_65 -> V_119 ) ;
F_77 ( & V_65 -> V_120 , V_121 ) ;
V_3 -> V_65 = V_65 ;
return 0 ;
abort:
F_78 ( V_65 ) ;
return - V_116 ;
}
static void F_79 ( struct V_2 * V_3 )
{
struct V_65 * V_65 = V_3 -> V_65 ;
F_80 ( & V_65 -> V_120 ) ;
F_81 ( V_65 -> V_117 ) ;
F_78 ( V_65 ) ;
}
static inline void F_82 ( struct V_2 * V_3 )
{
struct V_1 * V_20 = V_3 -> V_4 -> V_5 ;
T_1 V_122 ;
if ( ! V_54 )
return;
F_23 ( V_3 , L_28 , V_3 -> V_123 ) ;
F_14 ( V_20 , V_22 , & V_122 ) ;
F_23 ( V_3 , L_29 , V_122 ) ;
F_14 ( V_20 , V_39 , & V_122 ) ;
F_23 ( V_3 , L_30 , V_122 ) ;
}
struct V_2 * F_83 ( struct V_124 * V_85 )
{
struct V_2 * V_3 ;
T_2 V_123 , V_125 ;
struct V_1 * V_20 = V_85 -> V_5 ;
V_3 = F_73 ( sizeof( * V_3 ) , V_115 ) ;
if ( ! V_3 ) {
F_84 ( & V_85 -> V_126 , L_31 , V_44 ) ;
goto abort;
}
V_3 -> V_4 = V_85 ;
F_85 ( V_20 , V_127 , & V_123 ) ;
V_3 -> V_123 = V_123 ;
F_76 ( & V_3 -> V_38 ) ;
F_86 ( & V_3 -> V_34 ) ;
F_82 ( V_3 ) ;
F_85 ( V_20 , V_128 , & V_125 ) ;
if ( V_125 & V_129 )
V_3 -> V_57 = 1 ;
F_15 ( V_20 , V_22 ,
V_91 | V_76 |
V_92 | V_93 |
V_23 | V_94 ) ;
F_23 ( V_3 , L_32 ,
( V_123 & V_130 ) >> 19 ,
F_87 ( V_123 , V_131 ) ,
F_87 ( V_123 , V_132 ) ,
F_87 ( V_123 , V_133 ) ,
F_87 ( V_123 , V_134 ) ,
F_87 ( V_123 , V_135 ) ,
F_87 ( V_123 , V_136 ) ,
F_87 ( V_123 , V_137 ) ,
F_87 ( V_123 , V_138 ) ,
F_87 ( V_123 , V_139 ) ,
F_87 ( V_125 , V_129 ) ) ;
if ( F_72 ( V_3 ) )
goto V_140;
return V_3 ;
V_140:
F_78 ( V_3 ) ;
abort:
return NULL ;
}
void F_88 ( struct V_2 * V_3 )
{
F_71 ( V_3 ) ;
F_79 ( V_3 ) ;
F_78 ( V_3 ) ;
}

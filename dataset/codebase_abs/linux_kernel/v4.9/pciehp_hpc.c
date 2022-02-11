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
while ( true ) {
F_14 ( V_20 , V_22 , & V_21 ) ;
if ( V_21 == ( T_1 ) ~ 0 ) {
F_15 ( V_3 , L_2 ,
V_23 ) ;
return 0 ;
}
if ( V_21 & V_24 ) {
F_16 ( V_20 , V_22 ,
V_24 ) ;
return 1 ;
}
if ( V_19 < 0 )
break;
F_17 ( 10 ) ;
V_19 -= 10 ;
}
return 0 ;
}
static void F_18 ( struct V_2 * V_3 )
{
unsigned int V_25 = V_16 ? 2500 : 1000 ;
unsigned long V_26 = F_19 ( V_25 ) ;
unsigned long V_27 = V_3 -> V_28 + V_26 ;
unsigned long V_29 , V_19 ;
int V_30 ;
if ( F_20 ( V_3 ) )
return;
if ( ! V_3 -> V_31 )
return;
V_29 = V_12 ;
if ( F_21 ( V_27 , V_29 ) )
V_19 = 1 ;
else
V_19 = V_27 - V_29 ;
if ( V_3 -> V_32 & V_33 &&
V_3 -> V_32 & V_34 )
V_30 = F_22 ( V_3 -> V_35 , ! V_3 -> V_31 , V_19 ) ;
else
V_30 = F_13 ( V_3 , F_23 ( V_19 ) ) ;
if ( ! V_30 )
F_15 ( V_3 , L_3 ,
V_3 -> V_32 ,
F_23 ( V_12 - V_3 -> V_28 ) ) ;
}
static void F_24 ( struct V_2 * V_3 , T_1 V_36 ,
T_1 V_37 , bool V_38 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
T_1 V_32 ;
F_25 ( & V_3 -> V_39 ) ;
F_18 ( V_3 ) ;
F_14 ( V_20 , V_40 , & V_32 ) ;
if ( V_32 == ( T_1 ) ~ 0 ) {
F_15 ( V_3 , L_2 , V_23 ) ;
goto V_41;
}
V_32 &= ~ V_37 ;
V_32 |= ( V_36 & V_37 ) ;
V_3 -> V_31 = 1 ;
F_26 () ;
F_16 ( V_20 , V_40 , V_32 ) ;
V_3 -> V_28 = V_12 ;
V_3 -> V_32 = V_32 ;
if ( V_38 )
F_18 ( V_3 ) ;
V_41:
F_27 ( & V_3 -> V_39 ) ;
}
static void F_28 ( struct V_2 * V_3 , T_1 V_36 , T_1 V_37 )
{
F_24 ( V_3 , V_36 , V_37 , true ) ;
}
static void F_29 ( struct V_2 * V_3 , T_1 V_36 , T_1 V_37 )
{
F_24 ( V_3 , V_36 , V_37 , false ) ;
}
bool F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
T_1 V_42 ;
bool V_43 ;
F_14 ( V_20 , V_44 , & V_42 ) ;
V_43 = ! ! ( V_42 & V_45 ) ;
if ( V_43 )
F_31 ( V_3 , L_4 , V_23 , V_42 ) ;
return V_43 ;
}
static void F_32 ( struct V_2 * V_3 , bool V_46 )
{
int V_19 = 1000 ;
if ( F_30 ( V_3 ) == V_46 )
return;
while ( V_19 > 0 ) {
F_17 ( 10 ) ;
V_19 -= 10 ;
if ( F_30 ( V_3 ) == V_46 )
return;
}
F_31 ( V_3 , L_5 ,
V_46 ? L_6 : L_7 ) ;
}
static void F_33 ( struct V_2 * V_3 )
{
F_32 ( V_3 , true ) ;
}
static bool F_34 ( struct V_47 * V_48 , int V_49 )
{
T_2 V_50 ;
int V_51 = 0 ;
int V_52 = 1000 , V_53 = 20 ;
bool V_54 = false ;
do {
V_54 = F_35 ( V_48 , V_49 , & V_50 , 0 ) ;
V_51 ++ ;
if ( V_54 )
break;
F_17 ( V_53 ) ;
V_52 -= V_53 ;
} while ( V_52 > 0 );
if ( V_51 > 1 && V_55 )
F_36 ( V_56 L_8 ,
F_37 ( V_48 ) , V_48 -> V_57 , F_38 ( V_49 ) ,
F_39 ( V_49 ) , V_51 , V_53 , V_50 ) ;
return V_54 ;
}
int F_40 ( struct V_2 * V_3 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
bool V_54 ;
T_1 V_42 ;
if ( V_3 -> V_58 )
F_33 ( V_3 ) ;
else
F_17 ( 1000 ) ;
F_17 ( 100 ) ;
V_54 = F_34 ( V_3 -> V_4 -> V_5 -> V_59 ,
F_41 ( 0 , 0 ) ) ;
F_14 ( V_20 , V_44 , & V_42 ) ;
F_31 ( V_3 , L_4 , V_23 , V_42 ) ;
if ( ( V_42 & V_60 ) ||
! ( V_42 & V_61 ) ) {
F_9 ( V_3 , L_9 ,
V_42 ) ;
return - 1 ;
}
F_42 ( V_3 -> V_4 -> V_5 -> V_59 , V_42 ) ;
if ( ! V_54 )
return - 1 ;
return 0 ;
}
static int F_43 ( struct V_2 * V_3 , bool V_62 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
T_1 V_63 ;
F_14 ( V_20 , V_64 , & V_63 ) ;
if ( V_62 )
V_63 &= ~ V_65 ;
else
V_63 |= V_65 ;
F_16 ( V_20 , V_64 , V_63 ) ;
F_31 ( V_3 , L_10 , V_23 , V_63 ) ;
return 0 ;
}
static int F_44 ( struct V_2 * V_3 )
{
return F_43 ( V_3 , true ) ;
}
int F_45 ( struct V_66 * V_66 ,
T_3 * V_67 )
{
struct V_68 * V_68 = V_66 -> V_69 ;
struct V_1 * V_20 = F_1 ( V_68 -> V_3 ) ;
T_1 V_32 ;
F_14 ( V_20 , V_40 , & V_32 ) ;
* V_67 = ( V_32 & ( V_70 | V_71 ) ) >> 6 ;
return 0 ;
}
void F_46 ( struct V_68 * V_68 , T_3 * V_67 )
{
struct V_2 * V_3 = V_68 -> V_3 ;
struct V_1 * V_20 = F_1 ( V_3 ) ;
T_1 V_32 ;
F_14 ( V_20 , V_40 , & V_32 ) ;
F_31 ( V_3 , L_11 , V_23 ,
F_47 ( V_3 -> V_4 -> V_5 ) + V_40 , V_32 ) ;
switch ( V_32 & V_70 ) {
case V_72 :
* V_67 = 1 ;
break;
case V_73 :
* V_67 = 2 ;
break;
case V_74 :
* V_67 = 0 ;
break;
default:
* V_67 = 0xFF ;
break;
}
}
void F_48 ( struct V_68 * V_68 , T_3 * V_67 )
{
struct V_2 * V_3 = V_68 -> V_3 ;
struct V_1 * V_20 = F_1 ( V_3 ) ;
T_1 V_32 ;
F_14 ( V_20 , V_40 , & V_32 ) ;
F_31 ( V_3 , L_12 , V_23 ,
F_47 ( V_3 -> V_4 -> V_5 ) + V_40 , V_32 ) ;
switch ( V_32 & V_75 ) {
case V_76 :
* V_67 = 1 ;
break;
case V_77 :
* V_67 = 0 ;
break;
default:
* V_67 = 0xFF ;
break;
}
}
void F_49 ( struct V_68 * V_68 , T_3 * V_67 )
{
struct V_1 * V_20 = F_1 ( V_68 -> V_3 ) ;
T_1 V_21 ;
F_14 ( V_20 , V_22 , & V_21 ) ;
* V_67 = ! ! ( V_21 & V_78 ) ;
}
void F_50 ( struct V_68 * V_68 , T_3 * V_67 )
{
struct V_1 * V_20 = F_1 ( V_68 -> V_3 ) ;
T_1 V_21 ;
F_14 ( V_20 , V_22 , & V_21 ) ;
* V_67 = ! ! ( V_21 & V_79 ) ;
}
int F_51 ( struct V_68 * V_68 )
{
struct V_1 * V_20 = F_1 ( V_68 -> V_3 ) ;
T_1 V_21 ;
F_14 ( V_20 , V_22 , & V_21 ) ;
return ! ! ( V_21 & V_80 ) ;
}
int F_52 ( struct V_66 * V_66 ,
T_3 V_67 )
{
struct V_68 * V_68 = V_66 -> V_69 ;
struct V_2 * V_3 = V_68 -> V_3 ;
F_29 ( V_3 , V_67 << 6 ,
V_70 | V_71 ) ;
return 0 ;
}
void F_53 ( struct V_68 * V_68 , T_3 V_81 )
{
struct V_2 * V_3 = V_68 -> V_3 ;
T_1 V_82 ;
if ( ! F_54 ( V_3 ) )
return;
switch ( V_81 ) {
case 0 :
V_82 = V_74 ;
break;
case 1 :
V_82 = V_72 ;
break;
case 2 :
V_82 = V_73 ;
break;
default:
return;
}
F_29 ( V_3 , V_82 , V_70 ) ;
F_31 ( V_3 , L_13 , V_23 ,
F_47 ( V_3 -> V_4 -> V_5 ) + V_40 , V_82 ) ;
}
void F_55 ( struct V_68 * V_68 )
{
struct V_2 * V_3 = V_68 -> V_3 ;
if ( ! F_56 ( V_3 ) )
return;
F_29 ( V_3 , V_83 ,
V_71 ) ;
F_31 ( V_3 , L_13 , V_23 ,
F_47 ( V_3 -> V_4 -> V_5 ) + V_40 ,
V_83 ) ;
}
void F_57 ( struct V_68 * V_68 )
{
struct V_2 * V_3 = V_68 -> V_3 ;
if ( ! F_56 ( V_3 ) )
return;
F_29 ( V_3 , V_84 ,
V_71 ) ;
F_31 ( V_3 , L_13 , V_23 ,
F_47 ( V_3 -> V_4 -> V_5 ) + V_40 ,
V_84 ) ;
}
void F_58 ( struct V_68 * V_68 )
{
struct V_2 * V_3 = V_68 -> V_3 ;
if ( ! F_56 ( V_3 ) )
return;
F_29 ( V_3 , V_85 ,
V_71 ) ;
F_31 ( V_3 , L_13 , V_23 ,
F_47 ( V_3 -> V_4 -> V_5 ) + V_40 ,
V_85 ) ;
}
int F_59 ( struct V_68 * V_68 )
{
struct V_2 * V_3 = V_68 -> V_3 ;
struct V_1 * V_20 = F_1 ( V_3 ) ;
T_1 V_21 ;
int V_14 ;
F_14 ( V_20 , V_22 , & V_21 ) ;
if ( V_21 & V_80 )
F_16 ( V_20 , V_22 ,
V_80 ) ;
V_3 -> V_86 = 0 ;
F_28 ( V_3 , V_76 , V_75 ) ;
F_31 ( V_3 , L_13 , V_23 ,
F_47 ( V_3 -> V_4 -> V_5 ) + V_40 ,
V_76 ) ;
V_14 = F_44 ( V_3 ) ;
if ( V_14 )
F_9 ( V_3 , L_14 , V_23 ) ;
return V_14 ;
}
void F_60 ( struct V_68 * V_68 )
{
struct V_2 * V_3 = V_68 -> V_3 ;
F_28 ( V_3 , V_77 , V_75 ) ;
F_31 ( V_3 , L_13 , V_23 ,
F_47 ( V_3 -> V_4 -> V_5 ) + V_40 ,
V_77 ) ;
}
static T_4 F_61 ( int V_15 , void * V_87 )
{
struct V_2 * V_3 = (struct V_2 * ) V_87 ;
struct V_1 * V_20 = F_1 ( V_3 ) ;
struct V_47 * V_59 = V_20 -> V_59 ;
struct V_1 * V_88 ;
struct V_68 * V_68 = V_3 -> V_68 ;
T_1 V_67 , V_89 ;
T_3 V_90 ;
bool V_91 ;
if ( V_20 -> V_92 == V_93 )
return V_94 ;
F_14 ( V_20 , V_22 , & V_67 ) ;
if ( V_67 == ( T_1 ) ~ 0 ) {
F_15 ( V_3 , L_2 , V_23 ) ;
return V_94 ;
}
V_89 = V_67 & ( V_95 | V_80 |
V_96 | V_24 |
V_97 ) ;
if ( ! V_89 )
return V_94 ;
if ( V_89 & V_97 )
V_91 = F_30 ( V_3 ) ;
F_16 ( V_20 , V_22 , V_89 ) ;
F_31 ( V_3 , L_15 , V_89 ) ;
if ( V_89 & V_24 ) {
V_3 -> V_31 = 0 ;
F_26 () ;
F_62 ( & V_3 -> V_35 ) ;
}
if ( V_59 ) {
F_63 (dev, &subordinate->devices, bus_list) {
if ( V_88 -> V_98 ) {
F_31 ( V_3 , L_16 ,
V_89 , F_64 ( V_88 ) ) ;
return V_99 ;
}
}
}
if ( V_89 & V_95 ) {
F_15 ( V_3 , L_17 ,
F_65 ( V_68 ) ) ;
F_66 ( V_68 , V_100 ) ;
}
if ( V_89 & V_96 ) {
V_90 = ! ! ( V_67 & V_79 ) ;
F_15 ( V_3 , L_18 , F_65 ( V_68 ) ,
V_90 ? L_19 : L_20 ) ;
F_66 ( V_68 , V_90 ? V_101 :
V_102 ) ;
}
if ( ( V_89 & V_80 ) && ! V_3 -> V_86 ) {
V_3 -> V_86 = 1 ;
F_9 ( V_3 , L_21 , F_65 ( V_68 ) ) ;
F_66 ( V_68 , V_103 ) ;
}
if ( V_89 & V_97 ) {
F_15 ( V_3 , L_22 , F_65 ( V_68 ) ,
V_91 ? L_23 : L_24 ) ;
F_66 ( V_68 , V_91 ? V_104 :
V_105 ) ;
}
return V_99 ;
}
static T_4 F_3 ( int V_15 , void * V_87 )
{
T_4 V_30 , V_106 = V_94 ;
do {
V_30 = F_61 ( V_15 , V_87 ) ;
if ( V_30 == V_99 )
V_106 = V_99 ;
} while ( V_30 == V_99 );
return V_106 ;
}
void F_67 ( struct V_2 * V_3 )
{
T_1 V_36 , V_37 ;
V_36 = V_107 ;
if ( F_68 ( V_3 ) )
V_36 |= V_108 ;
else
V_36 |= V_109 ;
if ( ! V_16 )
V_36 |= V_33 | V_34 ;
V_37 = ( V_109 | V_108 |
V_110 |
V_33 | V_34 |
V_107 ) ;
F_29 ( V_3 , V_36 , V_37 ) ;
F_31 ( V_3 , L_13 , V_23 ,
F_47 ( V_3 -> V_4 -> V_5 ) + V_40 , V_36 ) ;
}
static void F_69 ( struct V_2 * V_3 )
{
T_1 V_37 ;
V_37 = ( V_109 | V_108 |
V_111 | V_110 |
V_33 | V_34 |
V_107 ) ;
F_28 ( V_3 , 0 , V_37 ) ;
F_31 ( V_3 , L_13 , V_23 ,
F_47 ( V_3 -> V_4 -> V_5 ) + V_40 , 0 ) ;
}
int F_70 ( struct V_68 * V_68 , int V_112 )
{
struct V_2 * V_3 = V_68 -> V_3 ;
struct V_1 * V_20 = F_1 ( V_3 ) ;
T_1 V_113 = 0 , V_114 = 0 ;
if ( V_112 )
return 0 ;
if ( ! F_68 ( V_3 ) ) {
V_114 |= V_109 ;
V_113 |= V_96 ;
}
V_114 |= V_107 ;
V_113 |= V_97 ;
F_28 ( V_3 , 0 , V_114 ) ;
F_31 ( V_3 , L_13 , V_23 ,
F_47 ( V_3 -> V_4 -> V_5 ) + V_40 , 0 ) ;
if ( V_16 )
F_11 ( & V_3 -> V_7 ) ;
F_71 ( V_3 -> V_4 -> V_5 ) ;
F_16 ( V_20 , V_22 , V_113 ) ;
F_29 ( V_3 , V_114 , V_114 ) ;
F_31 ( V_3 , L_13 , V_23 ,
F_47 ( V_3 -> V_4 -> V_5 ) + V_40 , V_114 ) ;
if ( V_16 )
F_2 ( V_3 -> V_7 . V_6 ) ;
return 0 ;
}
int F_72 ( struct V_2 * V_3 )
{
if ( F_7 ( V_3 ) )
return - 1 ;
F_67 ( V_3 ) ;
V_3 -> V_115 = 1 ;
return 0 ;
}
static void F_73 ( struct V_2 * V_3 )
{
if ( V_3 -> V_115 ) {
F_69 ( V_3 ) ;
F_10 ( V_3 ) ;
V_3 -> V_115 = 0 ;
}
}
static int F_74 ( struct V_2 * V_3 )
{
struct V_68 * V_68 ;
V_68 = F_75 ( sizeof( * V_68 ) , V_116 ) ;
if ( ! V_68 )
return - V_117 ;
V_68 -> V_118 = F_76 ( L_25 , 0 , 0 , F_77 ( V_3 ) ) ;
if ( ! V_68 -> V_118 )
goto abort;
V_68 -> V_3 = V_3 ;
F_78 ( & V_68 -> V_119 ) ;
F_78 ( & V_68 -> V_120 ) ;
F_79 ( & V_68 -> V_121 , V_122 ) ;
V_3 -> V_68 = V_68 ;
return 0 ;
abort:
F_80 ( V_68 ) ;
return - V_117 ;
}
static void F_81 ( struct V_2 * V_3 )
{
struct V_68 * V_68 = V_3 -> V_68 ;
F_82 ( & V_68 -> V_121 ) ;
F_83 ( V_68 -> V_118 ) ;
F_80 ( V_68 ) ;
}
static inline void F_84 ( struct V_2 * V_3 )
{
struct V_1 * V_20 = V_3 -> V_4 -> V_5 ;
T_1 V_123 ;
if ( ! V_55 )
return;
F_15 ( V_3 , L_26 , V_3 -> V_124 ) ;
F_14 ( V_20 , V_22 , & V_123 ) ;
F_15 ( V_3 , L_27 , V_123 ) ;
F_14 ( V_20 , V_40 , & V_123 ) ;
F_15 ( V_3 , L_28 , V_123 ) ;
}
struct V_2 * F_85 ( struct V_125 * V_88 )
{
struct V_2 * V_3 ;
T_2 V_124 , V_126 ;
struct V_1 * V_20 = V_88 -> V_5 ;
V_3 = F_75 ( sizeof( * V_3 ) , V_116 ) ;
if ( ! V_3 ) {
F_86 ( & V_88 -> V_127 , L_29 , V_23 ) ;
goto abort;
}
V_3 -> V_4 = V_88 ;
F_87 ( V_20 , V_128 , & V_124 ) ;
if ( V_20 -> V_129 )
V_124 &= ~ ( V_130 | V_131 ) ;
V_3 -> V_124 = V_124 ;
F_78 ( & V_3 -> V_39 ) ;
F_88 ( & V_3 -> V_35 ) ;
F_84 ( V_3 ) ;
F_87 ( V_20 , V_132 , & V_126 ) ;
if ( V_126 & V_133 )
V_3 -> V_58 = 1 ;
F_16 ( V_20 , V_22 ,
V_95 | V_80 |
V_134 | V_96 |
V_24 | V_97 ) ;
F_15 ( V_3 , L_30 ,
( V_124 & V_135 ) >> 19 ,
F_89 ( V_124 , V_136 ) ,
F_89 ( V_124 , V_137 ) ,
F_89 ( V_124 , V_138 ) ,
F_89 ( V_124 , V_130 ) ,
F_89 ( V_124 , V_131 ) ,
F_89 ( V_124 , V_139 ) ,
F_89 ( V_124 , V_140 ) ,
F_89 ( V_124 , V_141 ) ,
F_89 ( V_124 , V_142 ) ,
F_89 ( V_126 , V_133 ) ) ;
if ( F_74 ( V_3 ) )
goto V_143;
return V_3 ;
V_143:
F_80 ( V_3 ) ;
abort:
return NULL ;
}
void F_90 ( struct V_2 * V_3 )
{
F_73 ( V_3 ) ;
F_81 ( V_3 ) ;
F_80 ( V_3 ) ;
}

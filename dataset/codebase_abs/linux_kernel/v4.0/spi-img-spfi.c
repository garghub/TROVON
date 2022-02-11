static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_5 , T_1 V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_1 ( V_2 , V_6 ) ;
V_5 |= V_7 ;
F_3 ( V_2 , V_5 , V_6 ) ;
}
static inline void F_6 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_1 ( V_2 , V_6 ) ;
V_5 &= ~ V_7 ;
F_3 ( V_2 , V_5 , V_6 ) ;
}
static inline void F_7 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_8 , V_6 ) ;
F_8 ( 1 ) ;
F_3 ( V_2 , 0 , V_6 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
unsigned long V_9 = V_10 + F_10 ( 10 ) ;
F_3 ( V_2 , V_11 , V_12 ) ;
while ( F_11 ( V_10 , V_9 ) ) {
if ( F_1 ( V_2 , V_13 ) &
V_11 )
return;
F_12 () ;
}
F_13 ( V_2 -> V_14 , L_1 ) ;
F_7 ( V_2 ) ;
}
static unsigned int F_14 ( struct V_1 * V_2 , const T_1 * V_15 ,
unsigned int V_16 )
{
unsigned int V_17 = 0 ;
T_1 V_18 ;
while ( V_17 < V_16 / 4 ) {
F_3 ( V_2 , V_19 , V_12 ) ;
V_18 = F_1 ( V_2 , V_13 ) ;
if ( V_18 & V_19 )
break;
F_3 ( V_2 , V_15 [ V_17 ] , V_20 ) ;
V_17 ++ ;
}
return V_17 * 4 ;
}
static unsigned int F_15 ( struct V_1 * V_2 , const T_2 * V_15 ,
unsigned int V_16 )
{
unsigned int V_17 = 0 ;
T_1 V_18 ;
while ( V_17 < V_16 ) {
F_3 ( V_2 , V_19 , V_12 ) ;
V_18 = F_1 ( V_2 , V_13 ) ;
if ( V_18 & V_19 )
break;
F_3 ( V_2 , V_15 [ V_17 ] , V_21 ) ;
V_17 ++ ;
}
return V_17 ;
}
static unsigned int F_16 ( struct V_1 * V_2 , T_1 * V_15 ,
unsigned int V_16 )
{
unsigned int V_17 = 0 ;
T_1 V_18 ;
while ( V_17 < V_16 / 4 ) {
F_3 ( V_2 , V_22 ,
V_12 ) ;
V_18 = F_1 ( V_2 , V_13 ) ;
if ( ! ( V_18 & V_22 ) )
break;
V_15 [ V_17 ] = F_1 ( V_2 , V_23 ) ;
V_17 ++ ;
}
return V_17 * 4 ;
}
static unsigned int F_17 ( struct V_1 * V_2 , T_2 * V_15 ,
unsigned int V_16 )
{
unsigned int V_17 = 0 ;
T_1 V_18 ;
while ( V_17 < V_16 ) {
F_3 ( V_2 , V_24 ,
V_12 ) ;
V_18 = F_1 ( V_2 , V_13 ) ;
if ( ! ( V_18 & V_24 ) )
break;
V_15 [ V_17 ] = F_1 ( V_2 , V_25 ) ;
V_17 ++ ;
}
return V_17 ;
}
static int F_18 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_1 * V_2 = F_19 ( V_29 -> V_27 ) ;
unsigned int V_32 = 0 , V_33 = 0 ;
const void * V_34 = V_31 -> V_34 ;
void * V_35 = V_31 -> V_35 ;
unsigned long V_9 ;
if ( V_34 )
V_32 = V_31 -> V_36 ;
if ( V_35 )
V_33 = V_31 -> V_36 ;
F_5 ( V_2 ) ;
V_9 = V_10 +
F_10 ( V_31 -> V_36 * 8 * 1000 / V_31 -> V_37 + 100 ) ;
while ( ( V_32 > 0 || V_33 > 0 ) &&
F_11 ( V_10 , V_9 ) ) {
unsigned int V_38 , V_39 ;
if ( V_32 >= 4 )
V_38 = F_14 ( V_2 , V_34 , V_32 ) ;
else
V_38 = F_15 ( V_2 , V_34 , V_32 ) ;
if ( V_33 >= 4 )
V_39 = F_16 ( V_2 , V_35 , V_33 ) ;
else
V_39 = F_17 ( V_2 , V_35 , V_33 ) ;
V_34 += V_38 ;
V_35 += V_39 ;
V_32 -= V_38 ;
V_33 -= V_39 ;
F_12 () ;
}
if ( V_33 > 0 || V_32 > 0 ) {
F_13 ( V_2 -> V_14 , L_2 ) ;
F_7 ( V_2 ) ;
return - V_40 ;
}
if ( V_34 )
F_9 ( V_2 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static void F_20 ( void * V_41 )
{
struct V_1 * V_2 = V_41 ;
unsigned long V_42 ;
F_21 ( & V_2 -> V_43 , V_42 ) ;
V_2 -> V_44 = false ;
if ( ! V_2 -> V_45 ) {
F_6 ( V_2 ) ;
F_22 ( V_2 -> V_27 ) ;
}
F_23 ( & V_2 -> V_43 , V_42 ) ;
}
static void F_24 ( void * V_41 )
{
struct V_1 * V_2 = V_41 ;
unsigned long V_42 ;
F_9 ( V_2 ) ;
F_21 ( & V_2 -> V_43 , V_42 ) ;
V_2 -> V_45 = false ;
if ( ! V_2 -> V_44 ) {
F_6 ( V_2 ) ;
F_22 ( V_2 -> V_27 ) ;
}
F_23 ( & V_2 -> V_43 , V_42 ) ;
}
static int F_25 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_1 * V_2 = F_19 ( V_29 -> V_27 ) ;
struct V_46 * V_47 = NULL , * V_48 = NULL ;
struct V_49 V_50 , V_51 ;
V_2 -> V_44 = false ;
V_2 -> V_45 = false ;
if ( V_31 -> V_35 ) {
V_50 . V_52 = V_53 ;
if ( V_31 -> V_36 % 4 == 0 ) {
V_50 . V_54 = V_2 -> V_55 + V_23 ;
V_50 . V_56 = 4 ;
V_50 . V_57 = 4 ;
} else {
V_50 . V_54 = V_2 -> V_55 + V_25 ;
V_50 . V_56 = 1 ;
V_50 . V_57 = 4 ;
}
F_26 ( V_2 -> V_58 , & V_50 ) ;
V_47 = F_27 ( V_2 -> V_58 , V_31 -> V_59 . V_60 ,
V_31 -> V_59 . V_61 ,
V_53 ,
V_62 ) ;
if ( ! V_47 )
goto V_63;
V_47 -> V_64 = F_20 ;
V_47 -> V_65 = V_2 ;
}
if ( V_31 -> V_34 ) {
V_51 . V_52 = V_66 ;
if ( V_31 -> V_36 % 4 == 0 ) {
V_51 . V_67 = V_2 -> V_55 + V_20 ;
V_51 . V_68 = 4 ;
V_51 . V_69 = 4 ;
} else {
V_51 . V_67 = V_2 -> V_55 + V_21 ;
V_51 . V_68 = 1 ;
V_51 . V_69 = 4 ;
}
F_26 ( V_2 -> V_70 , & V_51 ) ;
V_48 = F_27 ( V_2 -> V_70 , V_31 -> V_71 . V_60 ,
V_31 -> V_71 . V_61 ,
V_66 ,
V_62 ) ;
if ( ! V_48 )
goto V_63;
V_48 -> V_64 = F_24 ;
V_48 -> V_65 = V_2 ;
}
if ( V_31 -> V_35 ) {
V_2 -> V_44 = true ;
F_28 ( V_47 ) ;
F_29 ( V_2 -> V_58 ) ;
}
F_5 ( V_2 ) ;
if ( V_31 -> V_34 ) {
V_2 -> V_45 = true ;
F_28 ( V_48 ) ;
F_29 ( V_2 -> V_70 ) ;
}
return 1 ;
V_63:
F_30 ( V_2 -> V_58 ) ;
F_30 ( V_2 -> V_70 ) ;
return - V_72 ;
}
static void F_31 ( struct V_26 * V_27 , struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_1 * V_2 = F_19 ( V_29 -> V_27 ) ;
T_1 V_5 , div ;
div = F_32 ( V_27 -> V_73 , V_31 -> V_37 ) ;
div = F_33 ( 512 / ( 1 << F_34 ( div ) ) , 1 , 255 ) ;
V_5 = F_1 ( V_2 , F_35 ( V_29 -> V_74 ) ) ;
V_5 &= ~ ( V_75 <<
V_76 ) ;
V_5 |= div << V_76 ;
F_3 ( V_2 , V_5 , F_35 ( V_29 -> V_74 ) ) ;
V_5 = F_1 ( V_2 , V_6 ) ;
V_5 &= ~ ( V_77 | V_78 ) ;
if ( V_31 -> V_34 )
V_5 |= V_77 ;
if ( V_31 -> V_35 )
V_5 |= V_78 ;
V_5 &= ~ ( V_79 << V_80 ) ;
if ( V_31 -> V_81 == V_82 &&
V_31 -> V_83 == V_82 )
V_5 |= V_84 << V_80 ;
else if ( V_31 -> V_81 == V_85 &&
V_31 -> V_83 == V_85 )
V_5 |= V_86 << V_80 ;
V_5 &= ~ V_87 ;
if ( ! V_31 -> V_88 && ! F_36 ( & V_31 -> V_89 ,
& V_27 -> V_90 -> V_91 ) )
V_5 |= V_87 ;
F_3 ( V_2 , V_5 , V_6 ) ;
V_5 = F_1 ( V_2 , V_92 ) ;
if ( V_29 -> V_93 & V_94 )
V_5 |= F_37 ( V_29 -> V_74 ) ;
else
V_5 &= ~ F_37 ( V_29 -> V_74 ) ;
if ( V_29 -> V_93 & V_95 )
V_5 |= F_38 ( V_29 -> V_74 ) ;
else
V_5 &= ~ F_38 ( V_29 -> V_74 ) ;
F_3 ( V_2 , V_5 , V_92 ) ;
F_3 ( V_2 , V_31 -> V_36 << V_96 ,
V_97 ) ;
}
static int F_39 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_1 * V_2 = F_19 ( V_29 -> V_27 ) ;
bool V_98 = false ;
unsigned long V_42 ;
int V_99 ;
if ( V_31 -> V_36 > V_100 ) {
F_13 ( V_2 -> V_14 ,
L_3 ,
V_31 -> V_36 , V_100 ) ;
return - V_101 ;
}
F_21 ( & V_2 -> V_43 , V_42 ) ;
if ( V_2 -> V_45 || V_2 -> V_44 ) {
F_13 ( V_2 -> V_14 , L_4 ) ;
V_98 = true ;
}
F_23 ( & V_2 -> V_43 , V_42 ) ;
if ( V_98 ) {
F_30 ( V_2 -> V_70 ) ;
F_30 ( V_2 -> V_58 ) ;
F_7 ( V_2 ) ;
}
F_31 ( V_27 , V_29 , V_31 ) ;
if ( V_27 -> V_102 && V_27 -> V_102 ( V_27 , V_29 , V_31 ) )
V_99 = F_25 ( V_27 , V_29 , V_31 ) ;
else
V_99 = F_18 ( V_27 , V_29 , V_31 ) ;
return V_99 ;
}
static void F_40 ( struct V_28 * V_29 , bool V_103 )
{
struct V_1 * V_2 = F_19 ( V_29 -> V_27 ) ;
T_1 V_5 ;
V_5 = F_1 ( V_2 , V_92 ) ;
V_5 &= ~ ( V_104 << V_105 ) ;
V_5 |= V_29 -> V_74 << V_105 ;
F_3 ( V_2 , V_5 , V_92 ) ;
}
static bool F_41 ( struct V_26 * V_27 , struct V_28 * V_29 ,
struct V_30 * V_31 )
{
if ( V_31 -> V_36 > V_106 )
return true ;
return false ;
}
static T_3 F_42 ( int V_107 , void * V_108 )
{
struct V_1 * V_2 = (struct V_1 * ) V_108 ;
T_1 V_18 ;
V_18 = F_1 ( V_2 , V_13 ) ;
if ( V_18 & V_109 ) {
F_3 ( V_2 , V_109 , V_12 ) ;
F_13 ( V_2 -> V_14 , L_5 ) ;
return V_110 ;
}
return V_111 ;
}
static int F_43 ( struct V_112 * V_113 )
{
struct V_26 * V_27 ;
struct V_1 * V_2 ;
struct V_114 * V_115 ;
int V_99 ;
V_27 = F_44 ( & V_113 -> V_14 , sizeof( * V_2 ) ) ;
if ( ! V_27 )
return - V_116 ;
F_45 ( V_113 , V_27 ) ;
V_2 = F_19 ( V_27 ) ;
V_2 -> V_14 = & V_113 -> V_14 ;
V_2 -> V_27 = V_27 ;
F_46 ( & V_2 -> V_43 ) ;
V_115 = F_47 ( V_113 , V_117 , 0 ) ;
V_2 -> V_4 = F_48 ( V_2 -> V_14 , V_115 ) ;
if ( F_49 ( V_2 -> V_4 ) ) {
V_99 = F_50 ( V_2 -> V_4 ) ;
goto V_118;
}
V_2 -> V_55 = V_115 -> V_119 ;
V_2 -> V_107 = F_51 ( V_113 , 0 ) ;
if ( V_2 -> V_107 < 0 ) {
V_99 = V_2 -> V_107 ;
goto V_118;
}
V_99 = F_52 ( V_2 -> V_14 , V_2 -> V_107 , F_42 ,
V_120 , F_53 ( V_2 -> V_14 ) , V_2 ) ;
if ( V_99 )
goto V_118;
V_2 -> V_121 = F_54 ( V_2 -> V_14 , L_6 ) ;
if ( F_49 ( V_2 -> V_121 ) ) {
V_99 = F_50 ( V_2 -> V_121 ) ;
goto V_118;
}
V_2 -> V_122 = F_54 ( V_2 -> V_14 , L_7 ) ;
if ( F_49 ( V_2 -> V_122 ) ) {
V_99 = F_50 ( V_2 -> V_122 ) ;
goto V_118;
}
V_99 = F_55 ( V_2 -> V_121 ) ;
if ( V_99 )
goto V_118;
V_99 = F_55 ( V_2 -> V_122 ) ;
if ( V_99 )
goto V_123;
F_7 ( V_2 ) ;
F_3 ( V_2 , V_109 , V_124 ) ;
V_27 -> V_125 = true ;
V_27 -> V_126 = V_113 -> V_127 ;
V_27 -> V_128 = V_95 | V_94 | V_129 | V_130 ;
if ( F_56 ( V_2 -> V_14 -> V_131 , L_8 ) )
V_27 -> V_128 |= V_132 | V_133 ;
V_27 -> V_134 = 5 ;
V_27 -> V_14 . V_131 = V_113 -> V_14 . V_131 ;
V_27 -> V_135 = F_57 ( 32 ) | F_57 ( 8 ) ;
V_27 -> V_73 = F_58 ( V_2 -> V_122 ) ;
V_27 -> V_136 = V_27 -> V_73 / 512 ;
V_27 -> V_137 = F_40 ;
V_27 -> V_138 = F_39 ;
V_2 -> V_70 = F_59 ( V_2 -> V_14 , L_9 ) ;
V_2 -> V_58 = F_59 ( V_2 -> V_14 , L_10 ) ;
if ( ! V_2 -> V_70 || ! V_2 -> V_58 ) {
if ( V_2 -> V_70 )
F_60 ( V_2 -> V_70 ) ;
if ( V_2 -> V_58 )
F_60 ( V_2 -> V_58 ) ;
F_61 ( V_2 -> V_14 , L_11 ) ;
} else {
V_27 -> V_139 = V_2 -> V_70 ;
V_27 -> V_140 = V_2 -> V_58 ;
V_27 -> V_102 = F_41 ;
}
F_62 ( V_2 -> V_14 ) ;
F_63 ( V_2 -> V_14 ) ;
V_99 = F_64 ( V_2 -> V_14 , V_27 ) ;
if ( V_99 )
goto V_141;
return 0 ;
V_141:
F_65 ( V_2 -> V_14 ) ;
if ( V_2 -> V_58 )
F_60 ( V_2 -> V_58 ) ;
if ( V_2 -> V_70 )
F_60 ( V_2 -> V_70 ) ;
F_66 ( V_2 -> V_122 ) ;
V_123:
F_66 ( V_2 -> V_121 ) ;
V_118:
F_67 ( V_27 ) ;
return V_99 ;
}
static int F_68 ( struct V_112 * V_113 )
{
struct V_26 * V_27 = F_69 ( V_113 ) ;
struct V_1 * V_2 = F_19 ( V_27 ) ;
if ( V_2 -> V_70 )
F_60 ( V_2 -> V_70 ) ;
if ( V_2 -> V_58 )
F_60 ( V_2 -> V_58 ) ;
F_65 ( V_2 -> V_14 ) ;
if ( ! F_70 ( V_2 -> V_14 ) ) {
F_66 ( V_2 -> V_122 ) ;
F_66 ( V_2 -> V_121 ) ;
}
F_67 ( V_27 ) ;
return 0 ;
}
static int F_71 ( struct V_142 * V_14 )
{
struct V_26 * V_27 = F_72 ( V_14 ) ;
struct V_1 * V_2 = F_19 ( V_27 ) ;
F_66 ( V_2 -> V_122 ) ;
F_66 ( V_2 -> V_121 ) ;
return 0 ;
}
static int F_73 ( struct V_142 * V_14 )
{
struct V_26 * V_27 = F_72 ( V_14 ) ;
struct V_1 * V_2 = F_19 ( V_27 ) ;
int V_99 ;
V_99 = F_55 ( V_2 -> V_121 ) ;
if ( V_99 )
return V_99 ;
V_99 = F_55 ( V_2 -> V_122 ) ;
if ( V_99 ) {
F_66 ( V_2 -> V_121 ) ;
return V_99 ;
}
return 0 ;
}
static int F_74 ( struct V_142 * V_14 )
{
struct V_26 * V_27 = F_72 ( V_14 ) ;
return F_75 ( V_27 ) ;
}
static int F_76 ( struct V_142 * V_14 )
{
struct V_26 * V_27 = F_72 ( V_14 ) ;
struct V_1 * V_2 = F_19 ( V_27 ) ;
int V_99 ;
V_99 = F_77 ( V_14 ) ;
if ( V_99 )
return V_99 ;
F_7 ( V_2 ) ;
F_78 ( V_14 ) ;
return F_79 ( V_27 ) ;
}

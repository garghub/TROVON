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
F_3 ( V_2 , V_8 , V_6 ) ;
F_3 ( V_2 , 0 , V_6 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
unsigned long V_9 = V_10 + F_8 ( 50 ) ;
while ( F_9 ( V_10 , V_9 ) ) {
T_1 V_11 = F_1 ( V_2 , V_12 ) ;
if ( V_11 & V_13 ) {
F_3 ( V_2 , V_13 ,
V_14 ) ;
return 0 ;
}
F_10 () ;
}
F_11 ( V_2 -> V_15 , L_1 ) ;
F_6 ( V_2 ) ;
return - V_16 ;
}
static unsigned int F_12 ( struct V_1 * V_2 , const T_1 * V_17 ,
unsigned int V_18 )
{
unsigned int V_19 = 0 ;
T_1 V_11 ;
while ( V_19 < V_18 / 4 ) {
F_3 ( V_2 , V_20 , V_14 ) ;
V_11 = F_1 ( V_2 , V_12 ) ;
if ( V_11 & V_20 )
break;
F_3 ( V_2 , V_17 [ V_19 ] , V_21 ) ;
V_19 ++ ;
}
return V_19 * 4 ;
}
static unsigned int F_13 ( struct V_1 * V_2 , const T_2 * V_17 ,
unsigned int V_18 )
{
unsigned int V_19 = 0 ;
T_1 V_11 ;
while ( V_19 < V_18 ) {
F_3 ( V_2 , V_20 , V_14 ) ;
V_11 = F_1 ( V_2 , V_12 ) ;
if ( V_11 & V_20 )
break;
F_3 ( V_2 , V_17 [ V_19 ] , V_22 ) ;
V_19 ++ ;
}
return V_19 ;
}
static unsigned int F_14 ( struct V_1 * V_2 , T_1 * V_17 ,
unsigned int V_18 )
{
unsigned int V_19 = 0 ;
T_1 V_11 ;
while ( V_19 < V_18 / 4 ) {
F_3 ( V_2 , V_23 ,
V_14 ) ;
V_11 = F_1 ( V_2 , V_12 ) ;
if ( ! ( V_11 & V_23 ) )
break;
V_17 [ V_19 ] = F_1 ( V_2 , V_24 ) ;
V_19 ++ ;
}
return V_19 * 4 ;
}
static unsigned int F_15 ( struct V_1 * V_2 , T_2 * V_17 ,
unsigned int V_18 )
{
unsigned int V_19 = 0 ;
T_1 V_11 ;
while ( V_19 < V_18 ) {
F_3 ( V_2 , V_25 ,
V_14 ) ;
V_11 = F_1 ( V_2 , V_12 ) ;
if ( ! ( V_11 & V_25 ) )
break;
V_17 [ V_19 ] = F_1 ( V_2 , V_26 ) ;
V_19 ++ ;
}
return V_19 ;
}
static int F_16 ( struct V_27 * V_28 ,
struct V_29 * V_30 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = F_17 ( V_30 -> V_28 ) ;
unsigned int V_33 = 0 , V_34 = 0 ;
const void * V_35 = V_32 -> V_35 ;
void * V_36 = V_32 -> V_36 ;
unsigned long V_9 ;
int V_37 ;
if ( V_35 )
V_33 = V_32 -> V_38 ;
if ( V_36 )
V_34 = V_32 -> V_38 ;
F_5 ( V_2 ) ;
V_9 = V_10 +
F_8 ( V_32 -> V_38 * 8 * 1000 / V_32 -> V_39 + 100 ) ;
while ( ( V_33 > 0 || V_34 > 0 ) &&
F_9 ( V_10 , V_9 ) ) {
unsigned int V_40 , V_41 ;
if ( V_33 >= 4 )
V_40 = F_12 ( V_2 , V_35 , V_33 ) ;
else
V_40 = F_13 ( V_2 , V_35 , V_33 ) ;
if ( V_34 >= 4 )
V_41 = F_14 ( V_2 , V_36 , V_34 ) ;
else
V_41 = F_15 ( V_2 , V_36 , V_34 ) ;
V_35 += V_40 ;
V_36 += V_41 ;
V_33 -= V_40 ;
V_34 -= V_41 ;
F_10 () ;
}
V_37 = F_7 ( V_2 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_34 > 0 || V_33 > 0 ) {
F_11 ( V_2 -> V_15 , L_2 ) ;
return - V_16 ;
}
return 0 ;
}
static void F_18 ( void * V_42 )
{
struct V_1 * V_2 = V_42 ;
unsigned long V_43 ;
F_7 ( V_2 ) ;
F_19 ( & V_2 -> V_44 , V_43 ) ;
V_2 -> V_45 = false ;
if ( ! V_2 -> V_46 )
F_20 ( V_2 -> V_28 ) ;
F_21 ( & V_2 -> V_44 , V_43 ) ;
}
static void F_22 ( void * V_42 )
{
struct V_1 * V_2 = V_42 ;
unsigned long V_43 ;
F_7 ( V_2 ) ;
F_19 ( & V_2 -> V_44 , V_43 ) ;
V_2 -> V_46 = false ;
if ( ! V_2 -> V_45 )
F_20 ( V_2 -> V_28 ) ;
F_21 ( & V_2 -> V_44 , V_43 ) ;
}
static int F_23 ( struct V_27 * V_28 ,
struct V_29 * V_30 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = F_17 ( V_30 -> V_28 ) ;
struct V_47 * V_48 = NULL , * V_49 = NULL ;
struct V_50 V_51 , V_52 ;
V_2 -> V_45 = false ;
V_2 -> V_46 = false ;
if ( V_32 -> V_36 ) {
V_51 . V_53 = V_54 ;
if ( V_32 -> V_38 % 4 == 0 ) {
V_51 . V_55 = V_2 -> V_56 + V_24 ;
V_51 . V_57 = 4 ;
V_51 . V_58 = 4 ;
} else {
V_51 . V_55 = V_2 -> V_56 + V_26 ;
V_51 . V_57 = 1 ;
V_51 . V_58 = 4 ;
}
F_24 ( V_2 -> V_59 , & V_51 ) ;
V_48 = F_25 ( V_2 -> V_59 , V_32 -> V_60 . V_61 ,
V_32 -> V_60 . V_62 ,
V_54 ,
V_63 ) ;
if ( ! V_48 )
goto V_64;
V_48 -> V_65 = F_18 ;
V_48 -> V_66 = V_2 ;
}
if ( V_32 -> V_35 ) {
V_52 . V_53 = V_67 ;
if ( V_32 -> V_38 % 4 == 0 ) {
V_52 . V_68 = V_2 -> V_56 + V_21 ;
V_52 . V_69 = 4 ;
V_52 . V_70 = 4 ;
} else {
V_52 . V_68 = V_2 -> V_56 + V_22 ;
V_52 . V_69 = 1 ;
V_52 . V_70 = 4 ;
}
F_24 ( V_2 -> V_71 , & V_52 ) ;
V_49 = F_25 ( V_2 -> V_71 , V_32 -> V_72 . V_61 ,
V_32 -> V_72 . V_62 ,
V_67 ,
V_63 ) ;
if ( ! V_49 )
goto V_64;
V_49 -> V_65 = F_22 ;
V_49 -> V_66 = V_2 ;
}
if ( V_32 -> V_36 ) {
V_2 -> V_45 = true ;
F_26 ( V_48 ) ;
F_27 ( V_2 -> V_59 ) ;
}
F_5 ( V_2 ) ;
if ( V_32 -> V_35 ) {
V_2 -> V_46 = true ;
F_26 ( V_49 ) ;
F_27 ( V_2 -> V_71 ) ;
}
return 1 ;
V_64:
F_28 ( V_2 -> V_59 ) ;
F_28 ( V_2 -> V_71 ) ;
return - V_73 ;
}
static void F_29 ( struct V_27 * V_28 ,
struct V_74 * V_75 )
{
struct V_1 * V_2 = F_17 ( V_28 ) ;
unsigned long V_43 ;
F_19 ( & V_2 -> V_44 , V_43 ) ;
if ( V_2 -> V_46 || V_2 -> V_45 ) {
V_2 -> V_46 = false ;
V_2 -> V_45 = false ;
F_28 ( V_2 -> V_71 ) ;
F_28 ( V_2 -> V_59 ) ;
}
F_21 ( & V_2 -> V_44 , V_43 ) ;
}
static int F_30 ( struct V_27 * V_28 , struct V_74 * V_75 )
{
struct V_1 * V_2 = F_17 ( V_28 ) ;
T_1 V_5 ;
V_5 = F_1 ( V_2 , V_76 ) ;
if ( V_75 -> V_30 -> V_77 & V_78 )
V_5 |= F_31 ( V_75 -> V_30 -> V_79 ) ;
else
V_5 &= ~ F_31 ( V_75 -> V_30 -> V_79 ) ;
if ( V_75 -> V_30 -> V_77 & V_80 )
V_5 |= F_32 ( V_75 -> V_30 -> V_79 ) ;
else
V_5 &= ~ F_32 ( V_75 -> V_30 -> V_79 ) ;
F_3 ( V_2 , V_5 , V_76 ) ;
return 0 ;
}
static int F_33 ( struct V_27 * V_28 ,
struct V_74 * V_75 )
{
struct V_1 * V_2 = F_17 ( V_28 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static int F_34 ( struct V_29 * V_30 )
{
int V_37 ;
V_37 = F_35 ( V_30 -> V_81 , ( V_30 -> V_77 & V_82 ) ?
V_83 : V_84 ,
F_36 ( & V_30 -> V_15 ) ) ;
if ( V_37 )
F_11 ( & V_30 -> V_15 , L_3 ,
V_30 -> V_81 ) ;
return V_37 ;
}
static void F_37 ( struct V_29 * V_30 )
{
F_38 ( V_30 -> V_81 ) ;
}
static void F_39 ( struct V_27 * V_28 , struct V_29 * V_30 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = F_17 ( V_30 -> V_28 ) ;
T_1 V_5 , div ;
div = F_40 ( F_41 ( V_2 -> V_85 ) , V_32 -> V_39 ) ;
div = F_42 ( 512 / ( 1 << F_43 ( div ) ) , 1 , 128 ) ;
V_5 = F_1 ( V_2 , F_44 ( V_30 -> V_79 ) ) ;
V_5 &= ~ ( V_86 <<
V_87 ) ;
V_5 |= div << V_87 ;
F_3 ( V_2 , V_5 , F_44 ( V_30 -> V_79 ) ) ;
F_3 ( V_2 , V_32 -> V_38 << V_88 ,
V_89 ) ;
V_5 = F_1 ( V_2 , V_6 ) ;
V_5 &= ~ ( V_90 | V_91 ) ;
if ( V_32 -> V_35 )
V_5 |= V_90 ;
if ( V_32 -> V_36 )
V_5 |= V_91 ;
V_5 &= ~ ( V_92 << V_93 ) ;
if ( V_32 -> V_94 == V_95 &&
V_32 -> V_96 == V_95 )
V_5 |= V_97 << V_93 ;
else if ( V_32 -> V_94 == V_98 &&
V_32 -> V_96 == V_98 )
V_5 |= V_99 << V_93 ;
V_5 |= V_100 ;
F_3 ( V_2 , V_5 , V_6 ) ;
}
static int F_45 ( struct V_27 * V_28 ,
struct V_29 * V_30 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = F_17 ( V_30 -> V_28 ) ;
int V_37 ;
if ( V_32 -> V_38 > V_101 ) {
F_11 ( V_2 -> V_15 ,
L_4 ,
V_32 -> V_38 , V_101 ) ;
return - V_102 ;
}
F_39 ( V_28 , V_30 , V_32 ) ;
if ( V_28 -> V_103 && V_28 -> V_103 ( V_28 , V_30 , V_32 ) )
V_37 = F_23 ( V_28 , V_30 , V_32 ) ;
else
V_37 = F_16 ( V_28 , V_30 , V_32 ) ;
return V_37 ;
}
static bool F_46 ( struct V_27 * V_28 , struct V_29 * V_30 ,
struct V_31 * V_32 )
{
if ( V_32 -> V_38 > V_104 )
return true ;
return false ;
}
static T_3 F_47 ( int V_105 , void * V_106 )
{
struct V_1 * V_2 = (struct V_1 * ) V_106 ;
T_1 V_11 ;
V_11 = F_1 ( V_2 , V_12 ) ;
if ( V_11 & V_107 ) {
F_3 ( V_2 , V_107 , V_14 ) ;
F_11 ( V_2 -> V_15 , L_5 ) ;
return V_108 ;
}
return V_109 ;
}
static int F_48 ( struct V_110 * V_111 )
{
struct V_27 * V_28 ;
struct V_1 * V_2 ;
struct V_112 * V_113 ;
int V_37 ;
V_28 = F_49 ( & V_111 -> V_15 , sizeof( * V_2 ) ) ;
if ( ! V_28 )
return - V_114 ;
F_50 ( V_111 , V_28 ) ;
V_2 = F_17 ( V_28 ) ;
V_2 -> V_15 = & V_111 -> V_15 ;
V_2 -> V_28 = V_28 ;
F_51 ( & V_2 -> V_44 ) ;
V_113 = F_52 ( V_111 , V_115 , 0 ) ;
V_2 -> V_4 = F_53 ( V_2 -> V_15 , V_113 ) ;
if ( F_54 ( V_2 -> V_4 ) ) {
V_37 = F_55 ( V_2 -> V_4 ) ;
goto V_116;
}
V_2 -> V_56 = V_113 -> V_117 ;
V_2 -> V_105 = F_56 ( V_111 , 0 ) ;
if ( V_2 -> V_105 < 0 ) {
V_37 = V_2 -> V_105 ;
goto V_116;
}
V_37 = F_57 ( V_2 -> V_15 , V_2 -> V_105 , F_47 ,
V_118 , F_36 ( V_2 -> V_15 ) , V_2 ) ;
if ( V_37 )
goto V_116;
V_2 -> V_119 = F_58 ( V_2 -> V_15 , L_6 ) ;
if ( F_54 ( V_2 -> V_119 ) ) {
V_37 = F_55 ( V_2 -> V_119 ) ;
goto V_116;
}
V_2 -> V_85 = F_58 ( V_2 -> V_15 , L_7 ) ;
if ( F_54 ( V_2 -> V_85 ) ) {
V_37 = F_55 ( V_2 -> V_85 ) ;
goto V_116;
}
V_37 = F_59 ( V_2 -> V_119 ) ;
if ( V_37 )
goto V_116;
V_37 = F_59 ( V_2 -> V_85 ) ;
if ( V_37 )
goto V_120;
F_6 ( V_2 ) ;
F_3 ( V_2 , V_107 , V_121 ) ;
V_28 -> V_122 = true ;
V_28 -> V_123 = V_111 -> V_124 ;
V_28 -> V_125 = V_80 | V_78 | V_126 | V_127 ;
if ( F_60 ( V_2 -> V_15 -> V_128 , L_8 ) )
V_28 -> V_125 |= V_129 | V_130 ;
V_28 -> V_15 . V_128 = V_111 -> V_15 . V_128 ;
V_28 -> V_131 = F_61 ( 32 ) | F_61 ( 8 ) ;
V_28 -> V_132 = F_41 ( V_2 -> V_85 ) / 4 ;
V_28 -> V_133 = F_41 ( V_2 -> V_85 ) / 512 ;
V_28 -> V_134 = F_34 ;
V_28 -> V_135 = F_37 ;
V_28 -> V_136 = F_45 ;
V_28 -> V_137 = F_30 ;
V_28 -> V_138 = F_33 ;
V_28 -> V_139 = F_29 ;
V_2 -> V_71 = F_62 ( V_2 -> V_15 , L_9 ) ;
V_2 -> V_59 = F_62 ( V_2 -> V_15 , L_10 ) ;
if ( ! V_2 -> V_71 || ! V_2 -> V_59 ) {
if ( V_2 -> V_71 )
F_63 ( V_2 -> V_71 ) ;
if ( V_2 -> V_59 )
F_63 ( V_2 -> V_59 ) ;
F_64 ( V_2 -> V_15 , L_11 ) ;
} else {
V_28 -> V_140 = V_2 -> V_71 ;
V_28 -> V_141 = V_2 -> V_59 ;
V_28 -> V_103 = F_46 ;
}
F_65 ( V_2 -> V_15 ) ;
F_66 ( V_2 -> V_15 ) ;
V_37 = F_67 ( V_2 -> V_15 , V_28 ) ;
if ( V_37 )
goto V_142;
return 0 ;
V_142:
F_68 ( V_2 -> V_15 ) ;
if ( V_2 -> V_59 )
F_63 ( V_2 -> V_59 ) ;
if ( V_2 -> V_71 )
F_63 ( V_2 -> V_71 ) ;
F_69 ( V_2 -> V_85 ) ;
V_120:
F_69 ( V_2 -> V_119 ) ;
V_116:
F_70 ( V_28 ) ;
return V_37 ;
}
static int F_71 ( struct V_110 * V_111 )
{
struct V_27 * V_28 = F_72 ( V_111 ) ;
struct V_1 * V_2 = F_17 ( V_28 ) ;
if ( V_2 -> V_71 )
F_63 ( V_2 -> V_71 ) ;
if ( V_2 -> V_59 )
F_63 ( V_2 -> V_59 ) ;
F_68 ( V_2 -> V_15 ) ;
if ( ! F_73 ( V_2 -> V_15 ) ) {
F_69 ( V_2 -> V_85 ) ;
F_69 ( V_2 -> V_119 ) ;
}
F_70 ( V_28 ) ;
return 0 ;
}
static int F_74 ( struct V_143 * V_15 )
{
struct V_27 * V_28 = F_75 ( V_15 ) ;
struct V_1 * V_2 = F_17 ( V_28 ) ;
F_69 ( V_2 -> V_85 ) ;
F_69 ( V_2 -> V_119 ) ;
return 0 ;
}
static int F_76 ( struct V_143 * V_15 )
{
struct V_27 * V_28 = F_75 ( V_15 ) ;
struct V_1 * V_2 = F_17 ( V_28 ) ;
int V_37 ;
V_37 = F_59 ( V_2 -> V_119 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_59 ( V_2 -> V_85 ) ;
if ( V_37 ) {
F_69 ( V_2 -> V_119 ) ;
return V_37 ;
}
return 0 ;
}
static int F_77 ( struct V_143 * V_15 )
{
struct V_27 * V_28 = F_75 ( V_15 ) ;
return F_78 ( V_28 ) ;
}
static int F_79 ( struct V_143 * V_15 )
{
struct V_27 * V_28 = F_75 ( V_15 ) ;
struct V_1 * V_2 = F_17 ( V_28 ) ;
int V_37 ;
V_37 = F_80 ( V_15 ) ;
if ( V_37 )
return V_37 ;
F_6 ( V_2 ) ;
F_81 ( V_15 ) ;
return F_82 ( V_28 ) ;
}

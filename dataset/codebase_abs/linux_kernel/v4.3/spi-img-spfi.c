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
if ( V_34 > 0 || V_33 > 0 ) {
F_11 ( V_2 -> V_15 , L_2 ) ;
return - V_16 ;
}
V_37 = F_7 ( V_2 ) ;
if ( V_37 < 0 )
return V_37 ;
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
int V_37 = - V_81 ;
struct V_82 * V_83 = F_35 ( V_30 ) ;
if ( ! V_83 ) {
V_83 = F_36 ( sizeof( * V_83 ) , V_84 ) ;
if ( ! V_83 )
return - V_85 ;
V_83 -> V_86 = false ;
F_37 ( V_30 , V_83 ) ;
}
if ( ! V_83 -> V_86 ) {
V_37 = F_38 ( V_30 -> V_87 ,
( V_30 -> V_77 & V_88 ) ?
V_89 : V_90 ,
F_39 ( & V_30 -> V_15 ) ) ;
if ( V_37 )
F_11 ( & V_30 -> V_15 , L_3 ,
V_30 -> V_87 ) ;
else
V_83 -> V_86 = true ;
} else {
if ( F_40 ( V_30 -> V_87 ) ) {
int V_77 = ( ( V_30 -> V_77 & V_88 ) ?
V_89 : V_90 ) ;
V_37 = F_41 ( V_30 -> V_87 , V_77 ) ;
if ( V_37 )
F_11 ( & V_30 -> V_15 , L_4 ,
V_30 -> V_87 , V_37 ) ;
}
}
return V_37 ;
}
static void F_42 ( struct V_29 * V_30 )
{
struct V_82 * V_83 = F_35 ( V_30 ) ;
if ( V_83 ) {
if ( V_83 -> V_86 )
F_43 ( V_30 -> V_87 ) ;
F_44 ( V_83 ) ;
F_37 ( V_30 , NULL ) ;
}
}
static void F_45 ( struct V_27 * V_28 , struct V_29 * V_30 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = F_17 ( V_30 -> V_28 ) ;
T_1 V_5 , div ;
div = F_46 ( F_47 ( V_2 -> V_91 ) , V_32 -> V_39 ) ;
div = F_48 ( 512 / ( 1 << F_49 ( div ) ) , 1 , 128 ) ;
V_5 = F_1 ( V_2 , F_50 ( V_30 -> V_79 ) ) ;
V_5 &= ~ ( V_92 <<
V_93 ) ;
V_5 |= div << V_93 ;
F_3 ( V_2 , V_5 , F_50 ( V_30 -> V_79 ) ) ;
F_3 ( V_2 , V_32 -> V_38 << V_94 ,
V_95 ) ;
V_5 = F_1 ( V_2 , V_6 ) ;
V_5 &= ~ ( V_96 | V_97 ) ;
if ( V_32 -> V_35 )
V_5 |= V_96 ;
if ( V_32 -> V_36 )
V_5 |= V_97 ;
V_5 &= ~ ( V_98 << V_99 ) ;
if ( V_32 -> V_100 == V_101 &&
V_32 -> V_102 == V_101 )
V_5 |= V_103 << V_99 ;
else if ( V_32 -> V_100 == V_104 &&
V_32 -> V_102 == V_104 )
V_5 |= V_105 << V_99 ;
V_5 |= V_106 ;
F_3 ( V_2 , V_5 , V_6 ) ;
}
static int F_51 ( struct V_27 * V_28 ,
struct V_29 * V_30 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = F_17 ( V_30 -> V_28 ) ;
int V_37 ;
if ( V_32 -> V_38 > V_107 ) {
F_11 ( V_2 -> V_15 ,
L_5 ,
V_32 -> V_38 , V_107 ) ;
return - V_81 ;
}
F_45 ( V_28 , V_30 , V_32 ) ;
if ( V_28 -> V_108 && V_28 -> V_108 ( V_28 , V_30 , V_32 ) )
V_37 = F_23 ( V_28 , V_30 , V_32 ) ;
else
V_37 = F_16 ( V_28 , V_30 , V_32 ) ;
return V_37 ;
}
static bool F_52 ( struct V_27 * V_28 , struct V_29 * V_30 ,
struct V_31 * V_32 )
{
if ( V_32 -> V_38 > V_109 )
return true ;
return false ;
}
static T_3 F_53 ( int V_110 , void * V_111 )
{
struct V_1 * V_2 = (struct V_1 * ) V_111 ;
T_1 V_11 ;
V_11 = F_1 ( V_2 , V_12 ) ;
if ( V_11 & V_112 ) {
F_3 ( V_2 , V_112 , V_14 ) ;
F_11 ( V_2 -> V_15 , L_6 ) ;
return V_113 ;
}
return V_114 ;
}
static int F_54 ( struct V_115 * V_116 )
{
struct V_27 * V_28 ;
struct V_1 * V_2 ;
struct V_117 * V_118 ;
int V_37 ;
T_1 V_119 ;
V_28 = F_55 ( & V_116 -> V_15 , sizeof( * V_2 ) ) ;
if ( ! V_28 )
return - V_85 ;
F_56 ( V_116 , V_28 ) ;
V_2 = F_17 ( V_28 ) ;
V_2 -> V_15 = & V_116 -> V_15 ;
V_2 -> V_28 = V_28 ;
F_57 ( & V_2 -> V_44 ) ;
V_118 = F_58 ( V_116 , V_120 , 0 ) ;
V_2 -> V_4 = F_59 ( V_2 -> V_15 , V_118 ) ;
if ( F_60 ( V_2 -> V_4 ) ) {
V_37 = F_61 ( V_2 -> V_4 ) ;
goto V_121;
}
V_2 -> V_56 = V_118 -> V_122 ;
V_2 -> V_110 = F_62 ( V_116 , 0 ) ;
if ( V_2 -> V_110 < 0 ) {
V_37 = V_2 -> V_110 ;
goto V_121;
}
V_37 = F_63 ( V_2 -> V_15 , V_2 -> V_110 , F_53 ,
V_123 , F_39 ( V_2 -> V_15 ) , V_2 ) ;
if ( V_37 )
goto V_121;
V_2 -> V_124 = F_64 ( V_2 -> V_15 , L_7 ) ;
if ( F_60 ( V_2 -> V_124 ) ) {
V_37 = F_61 ( V_2 -> V_124 ) ;
goto V_121;
}
V_2 -> V_91 = F_64 ( V_2 -> V_15 , L_8 ) ;
if ( F_60 ( V_2 -> V_91 ) ) {
V_37 = F_61 ( V_2 -> V_91 ) ;
goto V_121;
}
V_37 = F_65 ( V_2 -> V_124 ) ;
if ( V_37 )
goto V_121;
V_37 = F_65 ( V_2 -> V_91 ) ;
if ( V_37 )
goto V_125;
F_6 ( V_2 ) ;
F_3 ( V_2 , V_112 , V_126 ) ;
V_28 -> V_127 = true ;
V_28 -> V_128 = V_116 -> V_129 ;
V_28 -> V_130 = V_80 | V_78 | V_131 | V_132 ;
if ( F_66 ( V_2 -> V_15 -> V_133 , L_9 ) )
V_28 -> V_130 |= V_134 | V_135 ;
V_28 -> V_15 . V_133 = V_116 -> V_15 . V_133 ;
V_28 -> V_136 = F_67 ( 32 ) | F_67 ( 8 ) ;
V_28 -> V_119 = F_47 ( V_2 -> V_91 ) / 4 ;
V_28 -> V_137 = F_47 ( V_2 -> V_91 ) / 512 ;
if ( ! F_68 ( V_2 -> V_15 -> V_133 , L_10 ,
& V_119 ) ) {
if ( V_28 -> V_119 > V_119 )
V_28 -> V_119 = V_119 ;
}
V_28 -> V_138 = F_34 ;
V_28 -> V_139 = F_42 ;
V_28 -> V_140 = F_51 ;
V_28 -> V_141 = F_30 ;
V_28 -> V_142 = F_33 ;
V_28 -> V_143 = F_29 ;
V_2 -> V_71 = F_69 ( V_2 -> V_15 , L_11 ) ;
V_2 -> V_59 = F_69 ( V_2 -> V_15 , L_12 ) ;
if ( ! V_2 -> V_71 || ! V_2 -> V_59 ) {
if ( V_2 -> V_71 )
F_70 ( V_2 -> V_71 ) ;
if ( V_2 -> V_59 )
F_70 ( V_2 -> V_59 ) ;
F_71 ( V_2 -> V_15 , L_13 ) ;
} else {
V_28 -> V_144 = V_2 -> V_71 ;
V_28 -> V_145 = V_2 -> V_59 ;
V_28 -> V_108 = F_52 ;
}
F_72 ( V_2 -> V_15 ) ;
F_73 ( V_2 -> V_15 ) ;
V_37 = F_74 ( V_2 -> V_15 , V_28 ) ;
if ( V_37 )
goto V_146;
return 0 ;
V_146:
F_75 ( V_2 -> V_15 ) ;
if ( V_2 -> V_59 )
F_70 ( V_2 -> V_59 ) ;
if ( V_2 -> V_71 )
F_70 ( V_2 -> V_71 ) ;
F_76 ( V_2 -> V_91 ) ;
V_125:
F_76 ( V_2 -> V_124 ) ;
V_121:
F_77 ( V_28 ) ;
return V_37 ;
}
static int F_78 ( struct V_115 * V_116 )
{
struct V_27 * V_28 = F_79 ( V_116 ) ;
struct V_1 * V_2 = F_17 ( V_28 ) ;
if ( V_2 -> V_71 )
F_70 ( V_2 -> V_71 ) ;
if ( V_2 -> V_59 )
F_70 ( V_2 -> V_59 ) ;
F_75 ( V_2 -> V_15 ) ;
if ( ! F_80 ( V_2 -> V_15 ) ) {
F_76 ( V_2 -> V_91 ) ;
F_76 ( V_2 -> V_124 ) ;
}
F_77 ( V_28 ) ;
return 0 ;
}
static int F_81 ( struct V_147 * V_15 )
{
struct V_27 * V_28 = F_82 ( V_15 ) ;
struct V_1 * V_2 = F_17 ( V_28 ) ;
F_76 ( V_2 -> V_91 ) ;
F_76 ( V_2 -> V_124 ) ;
return 0 ;
}
static int F_83 ( struct V_147 * V_15 )
{
struct V_27 * V_28 = F_82 ( V_15 ) ;
struct V_1 * V_2 = F_17 ( V_28 ) ;
int V_37 ;
V_37 = F_65 ( V_2 -> V_124 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_65 ( V_2 -> V_91 ) ;
if ( V_37 ) {
F_76 ( V_2 -> V_124 ) ;
return V_37 ;
}
return 0 ;
}
static int F_84 ( struct V_147 * V_15 )
{
struct V_27 * V_28 = F_82 ( V_15 ) ;
return F_85 ( V_28 ) ;
}
static int F_86 ( struct V_147 * V_15 )
{
struct V_27 * V_28 = F_82 ( V_15 ) ;
struct V_1 * V_2 = F_17 ( V_28 ) ;
int V_37 ;
V_37 = F_87 ( V_15 ) ;
if ( V_37 )
return V_37 ;
F_6 ( V_2 ) ;
F_88 ( V_15 ) ;
return F_89 ( V_28 ) ;
}

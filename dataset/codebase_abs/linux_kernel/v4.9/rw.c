static unsigned long F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned long V_5 , unsigned long V_6 )
{
struct V_7 * V_8 = & V_2 -> V_7 ;
long V_9 ;
V_9 = V_6 ( V_8 -> V_10 - F_2 ( & V_8 -> V_11 ) , V_5 ) ;
if ( V_9 < 0 || V_9 < F_3 ( long , V_12 , V_5 ) ) {
V_9 = 0 ;
goto V_13;
}
if ( V_4 -> V_14 == 0 ) {
long V_15 = ( V_4 -> V_16 + V_9 ) % V_12 ;
if ( V_15 < V_9 )
V_9 -= V_15 ;
}
if ( F_4 ( V_9 , & V_8 -> V_11 ) > V_8 -> V_10 ) {
F_5 ( V_9 , & V_8 -> V_11 ) ;
V_9 = 0 ;
}
V_13:
if ( V_9 < V_6 ) {
F_6 ( V_6 - V_9 , & V_8 -> V_11 ) ;
V_9 = V_6 ;
}
return V_9 ;
}
void F_7 ( struct V_1 * V_2 , unsigned long V_17 )
{
struct V_7 * V_8 = & V_2 -> V_7 ;
F_5 ( V_17 , & V_8 -> V_11 ) ;
}
static void F_8 ( struct V_1 * V_2 , enum V_18 V_19 )
{
F_9 ( V_19 >= 0 && V_19 < V_20 , L_1 , V_19 ) ;
F_10 ( V_2 -> V_21 , V_19 ) ;
}
void F_11 ( struct V_22 * V_22 , enum V_18 V_19 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
F_8 ( V_2 , V_19 ) ;
}
static int F_13 ( unsigned long V_23 , unsigned long V_24 ,
unsigned long V_25 , unsigned long V_26 )
{
unsigned long V_27 = V_24 - V_25 , V_28 = V_24 + V_26 ;
if ( V_27 > V_24 )
V_27 = 0 ;
if ( V_28 < V_24 )
V_28 = ~ 0 ;
return V_27 <= V_23 && V_23 <= V_28 ;
}
void F_14 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = F_15 ( V_30 ) ;
struct V_33 * V_34 = & V_32 -> V_35 ;
F_16 ( & V_34 -> V_36 ) ;
V_34 -> V_37 ++ ;
V_34 -> V_38 = 0 ;
V_34 -> V_39 ++ ;
F_17 ( & V_34 -> V_36 ) ;
}
static int F_18 ( const struct V_40 * V_41 , struct V_42 * V_43 ,
struct V_44 * V_45 , struct V_46 * V_47 ,
struct V_48 * V_49 , T_1 * V_50 )
{
struct V_47 * V_51 = V_47 -> V_52 ;
struct V_53 * V_54 ;
int V_55 ;
V_55 = 0 ;
F_19 ( V_41 , V_43 , V_47 ) ;
F_20 ( & V_47 -> V_56 , L_2 , V_57 ) ;
V_54 = F_21 ( F_22 ( V_49 , V_47 ) ) ;
if ( ! V_54 -> V_58 && ! F_23 ( V_51 ) ) {
F_24 ( V_59 , L_3 ,
F_25 ( V_54 ) , * V_50 ) ;
if ( * V_50 == 0 || F_25 ( V_54 ) > * V_50 )
V_55 = F_26 ( V_41 , V_43 , V_47 , V_50 ) ;
if ( V_55 == 0 ) {
V_54 -> V_58 = 1 ;
V_54 -> V_60 = 0 ;
F_27 ( V_45 , V_47 ) ;
V_55 = 1 ;
} else {
F_28 ( V_41 , V_43 , V_47 ) ;
V_55 = - V_61 ;
}
} else {
F_29 ( V_41 , V_43 , V_47 ) ;
}
F_30 ( & V_47 -> V_56 , L_2 , V_57 ) ;
F_31 ( V_41 , V_47 ) ;
return V_55 ;
}
static int F_32 ( const struct V_40 * V_41 , struct V_42 * V_43 ,
struct V_44 * V_45 ,
T_1 V_23 , T_1 * V_50 )
{
struct V_48 * V_49 = V_43 -> V_62 ;
struct V_22 * V_22 = F_33 ( V_49 ) ;
struct V_47 * V_51 ;
struct V_46 * V_47 ;
enum V_18 V_19 = V_20 ;
int V_55 = 0 ;
const char * V_63 = NULL ;
V_51 = F_34 ( V_22 -> V_64 , V_23 ) ;
if ( V_51 ) {
if ( V_51 -> V_65 == V_22 -> V_64 ) {
V_47 = F_35 ( V_41 , V_49 , V_51 -> V_23 ,
V_51 , V_66 ) ;
if ( ! F_36 ( V_47 ) ) {
V_55 = F_18 ( V_41 , V_43 , V_45 ,
V_47 , V_49 , V_50 ) ;
if ( V_55 == - V_61 ) {
V_19 = V_67 ;
V_63 = L_4 ;
}
} else {
V_19 = V_68 ;
V_63 = L_5 ;
}
} else {
V_19 = V_69 ;
V_63 = L_6 ;
}
if ( V_55 != 1 )
F_37 ( V_51 ) ;
F_38 ( V_51 ) ;
} else {
V_19 = V_68 ;
V_63 = L_7 ;
}
if ( V_63 ) {
F_11 ( V_22 , V_19 ) ;
F_24 ( V_59 , L_8 , V_63 ) ;
}
return V_55 ;
}
static inline int F_39 ( struct V_33 * V_34 )
{
return V_34 -> V_70 > 1 ;
}
static unsigned long
F_40 ( T_1 V_71 , unsigned long V_72 , unsigned long V_73 ,
unsigned long V_74 , unsigned long V_75 )
{
T_2 V_27 = V_74 > V_71 ? V_74 - V_71 : 0 ;
T_2 V_28 = V_74 + V_75 > V_71 ? V_74 + V_75 - V_71 : 0 ;
unsigned long V_76 = 0 ;
unsigned long V_77 = 0 ;
unsigned long V_78 ;
if ( V_72 == 0 || V_75 == 0 || V_28 == 0 )
return V_75 ;
V_76 = F_41 ( V_27 , V_72 ) ;
if ( V_76 < V_73 )
V_76 = V_73 - V_76 ;
else
V_76 = 0 ;
V_77 = F_41 ( V_28 , V_72 ) ;
if ( V_77 > V_73 )
V_77 = V_73 ;
F_24 ( V_59 , L_9 ,
V_27 , V_28 , V_76 , V_77 ) ;
if ( V_27 == V_28 )
V_78 = V_77 - ( V_73 - V_76 ) ;
else
V_78 = V_76 + V_73 * ( V_28 - V_27 - 1 ) + V_77 ;
F_24 ( V_59 , L_10 ,
V_71 , V_72 , V_73 , V_74 , V_75 , V_78 ) ;
return V_78 ;
}
static int F_42 ( struct V_3 * V_4 )
{
T_2 V_75 = V_4 -> V_79 >= V_4 -> V_16 ?
V_4 -> V_79 - V_4 -> V_16 + 1 : 0 ;
return F_40 ( V_4 -> V_80 , V_4 -> V_81 ,
V_4 -> V_14 , V_4 -> V_16 ,
V_75 ) ;
}
static int F_43 ( unsigned long V_82 , struct V_3 * V_4 )
{
return V_4 -> V_81 == 0 || V_4 -> V_81 == V_4 -> V_14 ||
( V_82 >= V_4 -> V_80 && ( V_82 - V_4 -> V_80 ) %
V_4 -> V_81 < V_4 -> V_14 ) ;
}
static int F_44 ( const struct V_40 * V_41 ,
struct V_42 * V_43 , struct V_44 * V_45 ,
struct V_3 * V_4 ,
unsigned long * V_83 ,
unsigned long * V_84 )
{
int V_55 , V_85 = 0 ;
bool V_86 ;
T_1 V_87 ;
T_1 V_50 = 0 ;
F_45 ( V_4 ) ;
F_46 ( V_4 ) ;
V_86 = V_4 -> V_81 > V_4 -> V_14 && V_4 -> V_14 > 0 ;
for ( V_87 = V_4 -> V_16 ;
V_87 <= V_4 -> V_79 && * V_83 > 0 ; V_87 ++ ) {
if ( F_43 ( V_87 , V_4 ) ) {
V_55 = F_32 ( V_41 , V_43 , V_45 ,
V_87 , & V_50 ) ;
if ( V_55 == 1 ) {
( * V_83 ) -- ;
V_85 ++ ;
} else if ( V_55 == - V_61 ) {
break;
}
} else if ( V_86 ) {
T_1 V_88 ;
F_9 ( V_87 >= V_4 -> V_80 , L_11 ,
V_87 ,
V_4 -> V_16 , V_4 -> V_79 , V_4 -> V_80 ,
V_4 -> V_81 , V_4 -> V_14 ) ;
V_88 = V_87 - V_4 -> V_80 ;
V_88 = V_88 % ( V_4 -> V_81 ) ;
if ( V_88 > V_4 -> V_14 ) {
V_87 += V_4 -> V_81 - V_88 ;
F_24 ( V_59 , L_12 , V_87 ,
V_4 -> V_81 - V_88 ) ;
continue;
}
}
}
* V_84 = V_87 ;
return V_85 ;
}
int F_47 ( const struct V_40 * V_41 , struct V_42 * V_43 ,
struct V_44 * V_45 , struct V_33 * V_34 ,
bool V_89 )
{
struct V_90 * V_91 = F_48 ( V_41 ) ;
struct V_92 * V_93 = F_49 ( V_41 ) ;
struct V_94 * V_95 = F_50 ( V_41 ) ;
unsigned long V_27 = 0 , V_28 = 0 , V_96 ;
unsigned long V_84 , V_17 , V_97 = 0 ;
struct V_22 * V_22 ;
struct V_3 * V_4 = & V_93 -> V_98 ;
struct V_48 * V_49 ;
int V_9 = 0 ;
T_2 V_99 ;
V_49 = V_43 -> V_62 ;
V_22 = F_33 ( V_49 ) ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_51 ( V_49 ) ;
V_9 = F_52 ( V_41 , V_49 , V_95 ) ;
F_53 ( V_49 ) ;
if ( V_9 != 0 )
return V_9 ;
V_99 = V_95 -> V_100 ;
if ( V_99 == 0 ) {
F_11 ( V_22 , V_101 ) ;
return 0 ;
}
F_16 ( & V_34 -> V_36 ) ;
if ( V_91 -> V_102 &&
V_34 -> V_103 + V_34 -> V_104 <
V_91 -> V_105 + V_91 -> V_106 ) {
V_34 -> V_104 = V_91 -> V_105 + V_91 -> V_106 -
V_34 -> V_103 ;
}
if ( V_34 -> V_104 > 0 ) {
if ( F_39 ( V_34 ) )
V_27 = F_54 ( V_34 -> V_107 ,
V_34 -> V_108 ) ;
else
V_27 = V_34 -> V_107 ;
V_28 = V_34 -> V_103 + V_34 -> V_104 - 1 ;
}
if ( V_28 != 0 ) {
unsigned long V_109 ;
V_109 = ( V_28 + 1 ) & ( ~ ( V_12 - 1 ) ) ;
if ( V_109 > 0 )
V_109 -- ;
if ( V_109 > V_27 )
V_28 = V_109 ;
V_28 = V_6 ( V_28 , ( unsigned long ) ( ( V_99 - 1 ) >> V_110 ) ) ;
V_34 -> V_107 = F_54 ( V_28 , V_28 + 1 ) ;
F_55 ( V_34 ) ;
}
V_4 -> V_16 = V_27 ;
V_4 -> V_79 = V_28 ;
if ( F_39 ( V_34 ) ) {
V_4 -> V_80 = V_34 -> V_108 ;
V_4 -> V_81 = V_34 -> V_111 ;
V_4 -> V_14 = V_34 -> V_112 ;
}
F_17 ( & V_34 -> V_36 ) ;
if ( V_28 == 0 ) {
F_11 ( V_22 , V_113 ) ;
return 0 ;
}
V_17 = F_42 ( V_4 ) ;
if ( V_17 == 0 ) {
F_11 ( V_22 , V_113 ) ;
return 0 ;
}
F_24 ( V_59 , V_114 L_13 ,
F_56 ( F_57 ( & V_49 -> V_115 ) ) ,
V_4 -> V_16 , V_4 -> V_79 ,
V_91 -> V_102 ? V_91 -> V_105 : 0 ,
V_91 -> V_102 ? V_91 -> V_106 : 0 ,
V_89 ) ;
if ( ! V_89 && V_91 -> V_102 &&
V_91 -> V_105 + V_91 -> V_106 > V_4 -> V_16 ) {
V_97 = V_91 -> V_105 + V_91 -> V_106 - V_4 -> V_16 ;
V_27 = V_4 -> V_16 & ( V_12 - 1 ) ;
V_97 = V_6 ( V_97 , V_12 - V_27 ) ;
}
V_96 = F_1 ( F_12 ( V_22 ) , V_4 , V_17 , V_97 ) ;
if ( V_96 < V_17 )
F_11 ( V_22 , V_116 ) ;
F_24 ( V_59 , L_14 ,
V_96 , V_17 , V_97 ,
F_2 ( & F_12 ( V_22 ) -> V_7 . V_11 ) ,
F_12 ( V_22 ) -> V_7 . V_10 ) ;
V_9 = F_44 ( V_41 , V_43 , V_45 , V_4 , & V_96 , & V_84 ) ;
if ( V_96 != 0 )
F_7 ( F_12 ( V_22 ) , V_96 ) ;
if ( V_84 == V_28 + 1 && V_84 == ( V_99 >> V_110 ) )
F_11 ( V_22 , V_117 ) ;
F_24 ( V_59 , L_15 ,
V_84 , V_28 , V_4 -> V_79 ) ;
if ( V_84 != V_28 + 1 ) {
F_11 ( V_22 , V_118 ) ;
F_16 ( & V_34 -> V_36 ) ;
if ( V_84 < V_34 -> V_107 &&
F_13 ( V_84 , V_34 -> V_103 , 0 ,
V_34 -> V_104 ) ) {
V_34 -> V_107 = V_84 ;
F_55 ( V_34 ) ;
}
F_17 ( & V_34 -> V_36 ) ;
}
return V_9 ;
}
static void F_58 ( struct V_22 * V_22 , struct V_33 * V_34 ,
unsigned long V_23 )
{
V_34 -> V_103 = V_23 & ( ~ ( F_59 ( V_22 ) - 1 ) ) ;
}
static void F_60 ( struct V_22 * V_22 , struct V_33 * V_34 ,
unsigned long V_23 )
{
V_34 -> V_119 = V_23 ;
V_34 -> V_39 = 0 ;
V_34 -> V_120 = 0 ;
V_34 -> V_104 = 0 ;
F_58 ( V_22 , V_34 , V_23 ) ;
V_34 -> V_107 = F_54 ( V_34 -> V_103 , V_23 ) ;
F_55 ( V_34 ) ;
}
static void F_61 ( struct V_33 * V_34 )
{
V_34 -> V_70 = 0 ;
V_34 -> V_111 = 0 ;
V_34 -> V_112 = 0 ;
F_55 ( V_34 ) ;
}
void F_62 ( struct V_22 * V_22 , struct V_33 * V_34 )
{
F_63 ( & V_34 -> V_36 ) ;
F_60 ( V_22 , V_34 , 0 ) ;
V_34 -> V_37 = 0 ;
}
static int F_64 ( struct V_33 * V_34 ,
unsigned long V_23 )
{
unsigned long V_121 ;
if ( V_34 -> V_111 == 0 || V_34 -> V_112 == 0 ||
V_34 -> V_112 == V_34 -> V_111 )
return 0 ;
V_121 = V_23 - V_34 -> V_119 - 1 ;
if ( V_121 == 0 )
return V_34 -> V_120 + 1 <= V_34 -> V_112 ;
return ( V_34 -> V_111 - V_34 -> V_112 ) == V_121 &&
V_34 -> V_120 == V_34 -> V_112 ;
}
static void F_65 ( struct V_33 * V_34 ,
unsigned long V_23 )
{
unsigned long V_121 = V_23 - V_34 -> V_119 - 1 ;
if ( ( V_121 != 0 || V_34 -> V_70 == 0 ) &&
! F_39 ( V_34 ) ) {
V_34 -> V_112 = V_34 -> V_120 ;
V_34 -> V_111 = V_34 -> V_120 +
V_121 ;
}
F_45 ( V_34 -> V_38 == 0 ) ;
F_45 ( V_34 -> V_70 == 0 ) ;
if ( V_23 <= V_34 -> V_119 ) {
F_61 ( V_34 ) ;
return;
}
V_34 -> V_112 = V_34 -> V_120 ;
V_34 -> V_111 = V_121 + V_34 -> V_120 ;
F_55 ( V_34 ) ;
}
static void F_66 ( struct V_33 * V_34 ,
struct V_7 * V_8 ,
unsigned long V_122 )
{
unsigned long V_123 , V_124 , V_125 ;
unsigned long V_126 ;
F_45 ( V_34 -> V_111 > 0 ) ;
F_9 ( V_34 -> V_103 + V_34 -> V_104
>= V_34 -> V_108 , L_16 ,
V_34 -> V_103 ,
V_34 -> V_104 , V_34 -> V_108 ) ;
V_126 = V_34 -> V_103 + V_34 -> V_104 -
V_34 -> V_108 ;
V_123 = V_126 % V_34 -> V_111 ;
V_125 = V_34 -> V_104 - V_123 ;
if ( V_123 < V_34 -> V_112 )
V_123 += V_122 ;
else
V_123 = V_34 -> V_112 + V_122 ;
F_45 ( V_34 -> V_112 != 0 ) ;
V_124 = V_123 / V_34 -> V_112 ;
V_123 %= V_34 -> V_112 ;
V_125 += V_124 * V_34 -> V_111 + V_123 ;
if ( F_40 ( V_34 -> V_108 , V_34 -> V_111 ,
V_34 -> V_112 , V_34 -> V_108 ,
V_125 ) <= V_8 -> V_127 )
V_34 -> V_104 = V_125 ;
F_55 ( V_34 ) ;
}
static void F_67 ( struct V_22 * V_22 ,
struct V_33 * V_34 ,
struct V_7 * V_8 )
{
if ( F_39 ( V_34 ) )
F_66 ( V_34 , V_8 , F_59 ( V_22 ) ) ;
else
V_34 -> V_104 = V_6 ( V_34 -> V_104 +
F_59 ( V_22 ) ,
V_8 -> V_127 ) ;
}
void F_68 ( struct V_1 * V_2 , struct V_22 * V_22 ,
struct V_33 * V_34 , unsigned long V_23 ,
unsigned V_89 )
{
struct V_7 * V_8 = & V_2 -> V_7 ;
int V_128 = 0 , V_129 = 0 , V_130 = 0 ;
F_16 ( & V_34 -> V_36 ) ;
F_8 ( V_2 , V_89 ? V_131 : V_132 ) ;
if ( ! F_13 ( V_23 , V_34 -> V_119 , 8 , 8 ) ) {
V_128 = 1 ;
F_8 ( V_2 , V_133 ) ;
} else if ( ! V_89 && V_34 -> V_104 &&
V_23 < V_34 -> V_107 &&
F_13 ( V_23 , V_34 -> V_103 , 0 ,
V_34 -> V_104 ) ) {
V_130 = 1 ;
F_8 ( V_2 , V_134 ) ;
}
if ( V_34 -> V_37 == 2 && ! V_34 -> V_38 ) {
T_2 V_135 ;
V_135 = ( F_69 ( V_22 ) + V_136 - 1 ) >>
V_110 ;
F_24 ( V_59 , L_17 , V_135 ,
V_8 -> V_137 , V_8 -> V_127 ) ;
if ( V_135 &&
V_135 <= V_8 -> V_137 ) {
V_34 -> V_103 = 0 ;
V_34 -> V_119 = 0 ;
V_34 -> V_107 = 0 ;
V_34 -> V_104 = V_6 ( V_8 -> V_127 ,
V_8 -> V_137 ) ;
goto V_138;
}
}
if ( V_128 ) {
if ( ! F_64 ( V_34 , V_23 ) ) {
if ( V_34 -> V_70 == 0 &&
V_34 -> V_38 == 0 ) {
F_65 ( V_34 , V_23 ) ;
V_34 -> V_70 ++ ;
} else {
F_61 ( V_34 ) ;
}
F_60 ( V_22 , V_34 , V_23 ) ;
V_34 -> V_120 ++ ;
goto V_138;
} else {
V_34 -> V_120 = 0 ;
V_34 -> V_39 = 0 ;
if ( ++ V_34 -> V_70 > 1 )
V_129 = 1 ;
F_55 ( V_34 ) ;
}
} else {
if ( V_130 ) {
if ( F_64 ( V_34 , V_23 ) &&
F_39 ( V_34 ) ) {
if ( V_23 != V_34 -> V_119 + 1 )
V_34 -> V_120 = 0 ;
F_60 ( V_22 , V_34 , V_23 ) ;
F_55 ( V_34 ) ;
} else {
F_60 ( V_22 , V_34 , V_23 ) ;
V_34 -> V_120 ++ ;
F_61 ( V_34 ) ;
goto V_138;
}
} else if ( F_39 ( V_34 ) ) {
if ( ! F_64 ( V_34 , V_23 ) ) {
F_61 ( V_34 ) ;
V_34 -> V_104 = 0 ;
V_34 -> V_107 = V_23 ;
}
}
}
V_34 -> V_120 ++ ;
V_34 -> V_119 = V_23 ;
F_58 ( V_22 , V_34 , V_23 ) ;
if ( F_39 ( V_34 ) ) {
V_34 -> V_107 = F_54 ( V_23 , V_34 -> V_107 ) ;
} else {
if ( V_34 -> V_107 < V_34 -> V_103 )
V_34 -> V_107 = V_34 -> V_103 ;
if ( ! V_89 )
V_34 -> V_107 = V_23 + 1 ;
}
F_55 ( V_34 ) ;
if ( ! V_34 -> V_104 && V_34 -> V_120 == 4 ) {
V_34 -> V_104 = F_59 ( V_22 ) ;
goto V_138;
}
if ( V_34 -> V_70 == 2 && V_129 ) {
V_34 -> V_107 = F_54 ( V_23 , V_34 -> V_107 ) ;
V_34 -> V_108 = V_23 ;
V_34 -> V_104 = F_59 ( V_22 ) ;
}
if ( ( V_34 -> V_39 > 1 || V_129 ) &&
! V_34 -> V_38 )
F_67 ( V_22 , V_34 , V_8 ) ;
V_138:
F_55 ( V_34 ) ;
V_34 -> V_38 ++ ;
F_17 ( & V_34 -> V_36 ) ;
}
int F_70 ( struct V_47 * V_51 , struct V_139 * V_140 )
{
struct V_22 * V_22 = V_51 -> V_65 -> V_141 ;
struct V_142 * V_143 = F_71 ( V_22 ) ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_144 V_145 ;
bool V_146 = false ;
bool V_147 = false ;
int V_148 ;
F_45 ( F_72 ( V_51 ) ) ;
F_45 ( ! F_73 ( V_51 ) ) ;
F_45 ( F_74 ( V_22 ) ) ;
V_41 = F_75 ( & V_145 ) ;
if ( F_36 ( V_41 ) ) {
V_148 = F_76 ( V_41 ) ;
goto V_13;
}
V_49 = F_71 ( V_22 ) -> V_149 ;
F_45 ( V_49 ) ;
V_43 = F_77 ( V_41 ) ;
V_43 -> V_62 = V_49 ;
V_43 -> V_150 = 1 ;
V_148 = F_78 ( V_41 , V_43 , V_151 , V_49 ) ;
if ( V_148 == 0 ) {
V_47 = F_35 ( V_41 , V_49 , V_51 -> V_23 ,
V_51 , V_66 ) ;
if ( ! F_36 ( V_47 ) ) {
F_20 ( & V_47 -> V_56 , L_18 ,
V_57 ) ;
F_19 ( V_41 , V_43 , V_47 ) ;
V_148 = F_79 ( V_41 , V_43 , V_47 ) ;
if ( V_148 != 0 ) {
if ( ! F_80 ( V_51 ) ) {
F_81 ( V_140 , V_51 ) ;
V_148 = 0 ;
V_146 = true ;
}
}
F_82 ( V_41 , V_43 , V_47 ) ;
V_147 = true ;
F_30 ( & V_47 -> V_56 ,
L_18 , V_57 ) ;
F_31 ( V_41 , V_47 ) ;
} else {
V_148 = F_76 ( V_47 ) ;
}
}
F_83 ( V_41 , V_43 ) ;
if ( V_146 && V_140 -> V_152 == V_153 ) {
T_3 V_88 = F_84 ( V_49 , V_51 -> V_23 ) ;
V_148 = F_85 ( V_22 , V_88 ,
V_88 + V_136 - 1 ,
V_154 , 1 ) ;
if ( V_148 > 0 ) {
V_140 -> V_155 -= V_148 - 1 ;
V_148 = 0 ;
}
}
F_86 ( & V_145 , V_41 ) ;
goto V_13;
V_13:
if ( V_148 < 0 ) {
if ( ! V_143 -> V_156 )
V_143 -> V_156 = V_148 ;
F_87 ( V_51 ) ;
if ( ! V_147 )
F_37 ( V_51 ) ;
}
return V_148 ;
}
int F_88 ( struct V_157 * V_65 , struct V_139 * V_140 )
{
struct V_22 * V_22 = V_65 -> V_141 ;
struct V_1 * V_2 = F_12 ( V_22 ) ;
T_3 V_27 ;
T_3 V_28 ;
enum V_158 V_159 ;
int V_160 = 0 ;
int V_148 ;
int V_161 = 0 ;
if ( V_140 -> V_162 ) {
V_27 = V_65 -> V_163 << V_110 ;
V_28 = V_164 ;
} else {
V_27 = V_140 -> V_165 ;
V_28 = V_140 -> V_166 ;
if ( V_28 == V_167 ) {
V_28 = V_164 ;
V_160 = V_27 == 0 ;
}
}
V_159 = V_168 ;
if ( V_140 -> V_152 == V_153 )
V_159 = V_154 ;
if ( V_2 -> V_169 )
V_161 = 1 ;
if ( ! F_71 ( V_22 ) -> V_149 )
return 0 ;
V_148 = F_85 ( V_22 , V_27 , V_28 , V_159 , V_161 ) ;
if ( V_148 > 0 ) {
V_140 -> V_155 -= V_148 ;
V_148 = 0 ;
}
if ( V_140 -> V_162 || ( V_160 && V_140 -> V_155 > 0 ) ) {
if ( V_28 == V_164 )
V_65 -> V_163 = 0 ;
else
V_65 -> V_163 = ( V_28 >> V_110 ) + 1 ;
}
return V_148 ;
}
struct V_170 * F_89 ( struct V_29 * V_29 )
{
struct V_31 * V_32 = F_15 ( V_29 ) ;
struct V_170 * V_171 ;
struct V_170 * V_172 = NULL ;
F_90 ( & V_32 -> V_173 ) ;
F_91 (lcc, &fd->fd_lccs, lcc_list) {
if ( V_171 -> V_174 == V_57 ) {
V_172 = V_171 ;
break;
}
}
F_92 ( & V_32 -> V_173 ) ;
return V_172 ;
}
void F_93 ( struct V_29 * V_29 , const struct V_40 * V_41 , struct V_42 * V_43 )
{
struct V_31 * V_32 = F_15 ( V_29 ) ;
struct V_170 * V_171 = & F_49 ( V_41 ) -> V_175 ;
memset ( V_171 , 0 , sizeof( * V_171 ) ) ;
F_94 ( & V_171 -> V_176 ) ;
V_171 -> V_174 = V_57 ;
V_171 -> V_177 = V_41 ;
V_171 -> V_178 = V_43 ;
F_95 ( & V_32 -> V_173 ) ;
F_96 ( & V_171 -> V_176 , & V_32 -> V_179 ) ;
F_97 ( & V_32 -> V_173 ) ;
}
void F_98 ( struct V_29 * V_29 , const struct V_40 * V_41 )
{
struct V_31 * V_32 = F_15 ( V_29 ) ;
struct V_170 * V_171 = & F_49 ( V_41 ) -> V_175 ;
F_95 ( & V_32 -> V_173 ) ;
F_99 ( & V_171 -> V_176 ) ;
F_97 ( & V_32 -> V_173 ) ;
}
int F_100 ( struct V_29 * V_29 , struct V_47 * V_51 )
{
struct V_48 * V_49 = F_71 ( F_101 ( V_29 ) ) -> V_149 ;
struct V_170 * V_171 ;
const struct V_40 * V_41 ;
struct V_42 * V_43 ;
struct V_46 * V_47 ;
int V_148 ;
V_171 = F_89 ( V_29 ) ;
if ( ! V_171 ) {
F_37 ( V_51 ) ;
return - V_180 ;
}
V_41 = V_171 -> V_177 ;
V_43 = V_171 -> V_178 ;
F_45 ( V_43 -> V_181 == V_182 ) ;
V_47 = F_35 ( V_41 , V_49 , V_51 -> V_23 , V_51 , V_66 ) ;
if ( ! F_36 ( V_47 ) ) {
F_45 ( V_47 -> V_183 == V_66 ) ;
if ( F_102 ( ! F_23 ( V_51 ) ) ) {
F_19 ( V_41 , V_43 , V_47 ) ;
V_148 = F_103 ( V_41 , V_43 , V_47 ) ;
} else {
F_37 ( V_51 ) ;
V_148 = 0 ;
}
F_31 ( V_41 , V_47 ) ;
} else {
F_37 ( V_51 ) ;
V_148 = F_76 ( V_47 ) ;
}
return V_148 ;
}
int F_104 ( const struct V_40 * V_41 , struct V_42 * V_43 ,
struct V_46 * V_47 , enum V_184 V_185 )
{
struct V_186 * V_45 ;
int V_148 ;
F_45 ( V_43 -> V_187 == V_188 || V_43 -> V_187 == V_189 ) ;
V_45 = & V_43 -> V_190 ;
F_105 ( V_45 , V_47 ) ;
V_148 = F_106 ( V_41 , V_43 , V_185 , V_45 , 0 ) ;
F_45 ( F_107 ( V_47 , V_43 ) ) ;
if ( V_185 == V_191 )
F_108 ( V_41 , V_43 , & V_45 -> V_192 ) ;
F_109 ( V_41 , V_45 ) ;
return V_148 ;
}

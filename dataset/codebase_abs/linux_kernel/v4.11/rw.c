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
void F_7 ( struct V_1 * V_2 , unsigned long V_14 )
{
struct V_7 * V_8 = & V_2 -> V_7 ;
F_5 ( V_14 , & V_8 -> V_11 ) ;
}
static void F_8 ( struct V_1 * V_2 , enum V_15 V_16 )
{
F_9 ( V_16 >= 0 && V_16 < V_17 , L_1 , V_16 ) ;
F_10 ( V_2 -> V_18 , V_16 ) ;
}
void F_11 ( struct V_19 * V_19 , enum V_15 V_16 )
{
struct V_1 * V_2 = F_12 ( V_19 ) ;
F_8 ( V_2 , V_16 ) ;
}
static int F_13 ( unsigned long V_20 , unsigned long V_21 ,
unsigned long V_22 , unsigned long V_23 )
{
unsigned long V_24 = V_21 - V_22 , V_25 = V_21 + V_23 ;
if ( V_24 > V_21 )
V_24 = 0 ;
if ( V_25 < V_21 )
V_25 = ~ 0 ;
return V_24 <= V_20 && V_20 <= V_25 ;
}
void F_14 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_15 ( V_27 ) ;
struct V_30 * V_31 = & V_29 -> V_32 ;
F_16 ( & V_31 -> V_33 ) ;
V_31 -> V_34 ++ ;
V_31 -> V_35 = 0 ;
V_31 -> V_36 ++ ;
F_17 ( & V_31 -> V_33 ) ;
}
static int F_18 ( const struct V_37 * V_38 , struct V_39 * V_40 ,
struct V_41 * V_42 , T_1 V_20 )
{
enum V_15 V_16 = V_17 ;
struct V_43 * V_44 = V_40 -> V_45 ;
struct V_19 * V_19 = F_19 ( V_44 ) ;
const char * V_46 = NULL ;
struct V_47 * V_48 ;
struct V_49 * V_50 ;
struct V_48 * V_51 ;
int V_52 = 0 ;
V_51 = F_20 ( V_19 -> V_53 , V_20 ) ;
if ( ! V_51 ) {
V_16 = V_54 ;
V_46 = L_2 ;
V_52 = - V_55 ;
goto V_13;
}
if ( V_51 -> V_56 != V_19 -> V_53 ) {
V_16 = V_57 ;
V_46 = L_3 ;
V_52 = - V_55 ;
goto V_13;
}
V_48 = F_21 ( V_38 , V_44 , V_51 -> V_20 , V_51 , V_58 ) ;
if ( F_22 ( V_48 ) ) {
V_16 = V_54 ;
V_46 = L_4 ;
V_52 = F_23 ( V_48 ) ;
goto V_13;
}
F_24 ( & V_48 -> V_59 , L_5 , V_60 ) ;
F_25 ( V_38 , V_40 , V_48 ) ;
V_50 = F_26 ( F_27 ( V_44 , V_48 ) ) ;
if ( ! V_50 -> V_61 && ! F_28 ( V_51 ) ) {
V_50 -> V_61 = 1 ;
V_50 -> V_62 = 0 ;
F_29 ( V_42 , V_48 ) ;
} else {
F_30 ( V_38 , V_40 , V_48 ) ;
V_52 = 1 ;
}
F_31 ( & V_48 -> V_59 , L_5 , V_60 ) ;
F_32 ( V_38 , V_48 ) ;
V_13:
if ( V_51 ) {
if ( V_52 )
F_33 ( V_51 ) ;
F_34 ( V_51 ) ;
}
if ( V_46 ) {
F_11 ( V_19 , V_16 ) ;
F_35 ( V_63 , L_6 , V_46 ) ;
}
return V_52 ;
}
static inline int F_36 ( struct V_30 * V_31 )
{
return V_31 -> V_64 > 1 ;
}
static unsigned long
F_37 ( T_1 V_65 , unsigned long V_66 , unsigned long V_67 ,
unsigned long V_68 , unsigned long V_69 )
{
T_2 V_24 = V_68 > V_65 ? V_68 - V_65 : 0 ;
T_2 V_25 = V_68 + V_69 > V_65 ? V_68 + V_69 - V_65 : 0 ;
unsigned long V_70 = 0 ;
unsigned long V_71 = 0 ;
unsigned long V_72 ;
if ( V_66 == 0 || V_69 == 0 || V_25 == 0 )
return V_69 ;
V_70 = F_38 ( V_24 , V_66 ) ;
if ( V_70 < V_67 )
V_70 = V_67 - V_70 ;
else
V_70 = 0 ;
V_71 = F_38 ( V_25 , V_66 ) ;
if ( V_71 > V_67 )
V_71 = V_67 ;
F_35 ( V_63 , L_7 ,
V_24 , V_25 , V_70 , V_71 ) ;
if ( V_24 == V_25 )
V_72 = V_71 - ( V_67 - V_70 ) ;
else
V_72 = V_70 + V_67 * ( V_25 - V_24 - 1 ) + V_71 ;
F_35 ( V_63 , L_8 ,
V_65 , V_66 , V_67 , V_68 , V_69 , V_72 ) ;
return V_72 ;
}
static int F_39 ( struct V_3 * V_4 )
{
T_2 V_69 = V_4 -> V_73 >= V_4 -> V_74 ?
V_4 -> V_73 - V_4 -> V_74 + 1 : 0 ;
return F_37 ( V_4 -> V_75 , V_4 -> V_76 ,
V_4 -> V_77 , V_4 -> V_74 ,
V_69 ) ;
}
static unsigned long F_40 ( struct V_30 * V_31 ,
unsigned long V_20 ,
unsigned long * V_78 )
{
unsigned long V_79 = V_20 % V_31 -> V_80 ;
if ( V_78 )
* V_78 = V_79 ;
return V_20 - V_79 ;
}
static int F_41 ( unsigned long V_81 , struct V_3 * V_4 )
{
return V_4 -> V_76 == 0 || V_4 -> V_76 == V_4 -> V_77 ||
( V_81 >= V_4 -> V_75 && ( V_81 - V_4 -> V_75 ) %
V_4 -> V_76 < V_4 -> V_77 ) ;
}
static unsigned long
F_42 ( const struct V_37 * V_38 , struct V_39 * V_40 ,
struct V_41 * V_42 , struct V_30 * V_31 ,
struct V_3 * V_4 )
{
struct V_82 V_8 = { 0 } ;
unsigned long V_83 = 0 ;
bool V_84 ;
T_1 V_85 ;
int V_52 ;
F_43 ( V_4 ) ;
F_44 ( V_4 ) ;
V_84 = V_4 -> V_76 > V_4 -> V_77 && V_4 -> V_77 > 0 ;
for ( V_85 = V_4 -> V_74 ;
V_85 <= V_4 -> V_73 && V_4 -> V_86 > 0 ; V_85 ++ ) {
if ( F_41 ( V_85 , V_4 ) ) {
if ( ! V_8 . V_87 || V_8 . V_87 < V_85 ) {
unsigned long V_25 ;
F_45 ( V_38 , & V_8 ) ;
V_52 = F_46 ( V_38 , V_40 , V_85 , & V_8 ) ;
if ( V_52 < 0 )
break;
F_35 ( V_63 , L_9 ,
V_85 , V_8 . V_87 , V_8 . V_88 ) ;
F_9 ( V_8 . V_87 >= V_85 ,
L_10 ,
V_40 -> V_45 , V_8 . V_87 , V_85 ) ;
if ( V_31 -> V_80 > V_8 . V_88 &&
V_8 . V_88 > 0 )
V_31 -> V_80 = V_8 . V_88 ;
V_25 = F_40 ( V_31 , V_4 -> V_73 + 1 , NULL ) ;
if ( V_25 > 0 && ! V_4 -> V_89 )
V_4 -> V_73 = V_25 - 1 ;
if ( V_4 -> V_73 < V_4 -> V_90 )
V_4 -> V_73 = V_4 -> V_90 ;
if ( V_4 -> V_73 > V_8 . V_87 )
V_4 -> V_73 = V_8 . V_87 ;
}
V_52 = F_18 ( V_38 , V_40 , V_42 , V_85 ) ;
if ( V_52 < 0 )
break;
V_83 = V_85 ;
if ( ! V_52 )
V_4 -> V_86 -- ;
} else if ( V_84 ) {
T_1 V_91 ;
F_9 ( V_85 >= V_4 -> V_75 , L_11 ,
V_85 ,
V_4 -> V_74 , V_4 -> V_73 , V_4 -> V_75 ,
V_4 -> V_76 , V_4 -> V_77 ) ;
V_91 = V_85 - V_4 -> V_75 ;
V_91 = V_91 % ( V_4 -> V_76 ) ;
if ( V_91 > V_4 -> V_77 ) {
V_85 += V_4 -> V_76 - V_91 ;
F_35 ( V_63 , L_12 , V_85 ,
V_4 -> V_76 - V_91 ) ;
continue;
}
}
}
F_45 ( V_38 , & V_8 ) ;
return V_83 ;
}
static int F_47 ( const struct V_37 * V_38 , struct V_39 * V_40 ,
struct V_41 * V_42 ,
struct V_30 * V_31 , bool V_92 )
{
struct V_93 * V_94 = F_48 ( V_38 ) ;
struct V_95 * V_96 = F_49 ( V_38 ) ;
struct V_97 * V_98 = F_50 ( V_38 ) ;
unsigned long V_14 , V_99 = 0 ;
T_1 V_83 , V_24 = 0 , V_25 = 0 ;
struct V_19 * V_19 ;
struct V_3 * V_4 = & V_96 -> V_100 ;
struct V_43 * V_44 ;
int V_9 = 0 ;
T_2 V_101 ;
V_44 = V_40 -> V_45 ;
V_19 = F_19 ( V_44 ) ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_51 ( V_44 ) ;
V_9 = F_52 ( V_38 , V_44 , V_98 ) ;
F_53 ( V_44 ) ;
if ( V_9 != 0 )
return V_9 ;
V_101 = V_98 -> V_102 ;
if ( V_101 == 0 ) {
F_11 ( V_19 , V_103 ) ;
return 0 ;
}
F_16 ( & V_31 -> V_33 ) ;
if ( F_36 ( V_31 ) )
V_24 = F_54 ( V_31 -> V_104 , V_31 -> V_105 ) ;
else
V_24 = V_31 -> V_104 ;
if ( V_31 -> V_106 > 0 )
V_25 = V_31 -> V_107 + V_31 -> V_106 - 1 ;
if ( V_94 -> V_108 &&
V_25 < V_94 -> V_109 + V_94 -> V_110 - 1 )
V_25 = V_94 -> V_109 + V_94 -> V_110 - 1 ;
if ( V_25 ) {
unsigned long V_111 ;
V_111 = ( unsigned long ) ( ( V_101 - 1 ) >> V_112 ) ;
if ( V_111 <= V_25 ) {
V_25 = V_111 ;
V_4 -> V_89 = true ;
}
V_31 -> V_104 = F_54 ( V_25 , V_25 + 1 ) ;
F_55 ( V_31 ) ;
}
V_4 -> V_74 = V_24 ;
V_4 -> V_73 = V_25 ;
if ( F_36 ( V_31 ) ) {
V_4 -> V_75 = V_31 -> V_105 ;
V_4 -> V_76 = V_31 -> V_113 ;
V_4 -> V_77 = V_31 -> V_114 ;
}
F_17 ( & V_31 -> V_33 ) ;
if ( V_25 == 0 ) {
F_11 ( V_19 , V_115 ) ;
return 0 ;
}
V_14 = F_39 ( V_4 ) ;
if ( V_14 == 0 ) {
F_11 ( V_19 , V_115 ) ;
return 0 ;
}
F_35 ( V_63 , V_116 L_13 ,
F_56 ( F_57 ( & V_44 -> V_117 ) ) ,
V_4 -> V_74 , V_4 -> V_73 ,
V_94 -> V_108 ? V_94 -> V_109 : 0 ,
V_94 -> V_108 ? V_94 -> V_110 : 0 ,
V_92 ) ;
if ( ! V_92 && V_94 -> V_108 &&
V_94 -> V_109 + V_94 -> V_110 > V_4 -> V_74 ) {
unsigned long V_78 ;
V_99 = V_94 -> V_109 + V_94 -> V_110 - V_4 -> V_74 ;
F_40 ( V_31 , V_4 -> V_74 , & V_78 ) ;
V_99 = V_6 ( V_99 , V_31 -> V_80 - V_78 ) ;
V_4 -> V_90 = V_4 -> V_74 + V_99 ;
}
V_4 -> V_86 = F_1 ( F_12 ( V_19 ) , V_4 , V_14 , V_99 ) ;
if ( V_4 -> V_86 < V_14 )
F_11 ( V_19 , V_118 ) ;
F_35 ( V_63 , L_14 ,
V_4 -> V_86 , V_14 , V_99 ,
F_2 ( & F_12 ( V_19 ) -> V_7 . V_11 ) ,
F_12 ( V_19 ) -> V_7 . V_10 ) ;
V_83 = F_42 ( V_38 , V_40 , V_42 , V_31 , V_4 ) ;
if ( V_4 -> V_86 )
F_7 ( F_12 ( V_19 ) , V_4 -> V_86 ) ;
if ( V_83 == V_25 && V_83 == ( V_101 >> V_112 ) )
F_11 ( V_19 , V_119 ) ;
F_35 ( V_63 , L_15 ,
V_83 , V_25 , V_4 -> V_73 , V_9 ) ;
if ( V_83 > 0 && V_83 != V_25 ) {
F_11 ( V_19 , V_120 ) ;
F_16 ( & V_31 -> V_33 ) ;
if ( V_83 <= V_31 -> V_104 &&
F_13 ( V_83 , V_31 -> V_107 , 0 ,
V_31 -> V_106 ) ) {
V_31 -> V_104 = V_83 + 1 ;
F_55 ( V_31 ) ;
}
F_17 ( & V_31 -> V_33 ) ;
}
return V_9 ;
}
static void F_58 ( struct V_19 * V_19 , struct V_30 * V_31 ,
unsigned long V_20 )
{
V_31 -> V_107 = F_40 ( V_31 , V_20 , NULL ) ;
}
static void F_59 ( struct V_19 * V_19 , struct V_30 * V_31 ,
unsigned long V_20 )
{
V_31 -> V_121 = V_20 ;
V_31 -> V_36 = 0 ;
V_31 -> V_122 = 0 ;
V_31 -> V_106 = 0 ;
F_58 ( V_19 , V_31 , V_20 ) ;
V_31 -> V_104 = F_54 ( V_31 -> V_107 , V_20 + 1 ) ;
F_55 ( V_31 ) ;
}
static void F_60 ( struct V_30 * V_31 )
{
V_31 -> V_64 = 0 ;
V_31 -> V_113 = 0 ;
V_31 -> V_114 = 0 ;
F_55 ( V_31 ) ;
}
void F_61 ( struct V_19 * V_19 , struct V_30 * V_31 )
{
F_62 ( & V_31 -> V_33 ) ;
V_31 -> V_80 = V_12 ;
F_59 ( V_19 , V_31 , 0 ) ;
V_31 -> V_34 = 0 ;
}
static int F_63 ( struct V_30 * V_31 ,
unsigned long V_20 )
{
unsigned long V_123 ;
if ( V_31 -> V_113 == 0 || V_31 -> V_114 == 0 ||
V_31 -> V_114 == V_31 -> V_113 )
return 0 ;
V_123 = V_20 - V_31 -> V_121 - 1 ;
if ( V_123 == 0 )
return V_31 -> V_122 + 1 <= V_31 -> V_114 ;
return ( V_31 -> V_113 - V_31 -> V_114 ) == V_123 &&
V_31 -> V_122 == V_31 -> V_114 ;
}
static void F_64 ( struct V_30 * V_31 ,
unsigned long V_20 )
{
unsigned long V_123 = V_20 - V_31 -> V_121 - 1 ;
if ( ( V_123 != 0 || V_31 -> V_64 == 0 ) &&
! F_36 ( V_31 ) ) {
V_31 -> V_114 = V_31 -> V_122 ;
V_31 -> V_113 = V_31 -> V_122 +
V_123 ;
}
F_43 ( V_31 -> V_35 == 0 ) ;
F_43 ( V_31 -> V_64 == 0 ) ;
if ( V_20 <= V_31 -> V_121 ) {
F_60 ( V_31 ) ;
return;
}
V_31 -> V_114 = V_31 -> V_122 ;
V_31 -> V_113 = V_123 + V_31 -> V_122 ;
F_55 ( V_31 ) ;
}
static void F_65 ( struct V_30 * V_31 ,
struct V_7 * V_8 ,
unsigned long V_124 )
{
unsigned long V_125 , V_126 , V_127 ;
unsigned long V_128 ;
F_43 ( V_31 -> V_113 > 0 ) ;
F_9 ( V_31 -> V_107 + V_31 -> V_106
>= V_31 -> V_105 , L_16 ,
V_31 -> V_107 ,
V_31 -> V_106 , V_31 -> V_105 ) ;
V_128 = V_31 -> V_107 + V_31 -> V_106 -
V_31 -> V_105 ;
V_125 = V_128 % V_31 -> V_113 ;
V_127 = V_31 -> V_106 - V_125 ;
if ( V_125 < V_31 -> V_114 )
V_125 += V_124 ;
else
V_125 = V_31 -> V_114 + V_124 ;
F_43 ( V_31 -> V_114 != 0 ) ;
V_126 = V_125 / V_31 -> V_114 ;
V_125 %= V_31 -> V_114 ;
V_127 += V_126 * V_31 -> V_113 + V_125 ;
if ( F_37 ( V_31 -> V_105 , V_31 -> V_113 ,
V_31 -> V_114 , V_31 -> V_105 ,
V_127 ) <= V_8 -> V_129 )
V_31 -> V_106 = V_127 ;
F_55 ( V_31 ) ;
}
static void F_66 ( struct V_19 * V_19 ,
struct V_30 * V_31 ,
struct V_7 * V_8 )
{
if ( F_36 ( V_31 ) ) {
F_65 ( V_31 , V_8 , V_31 -> V_80 ) ;
} else {
unsigned long V_130 ;
V_130 = V_6 ( V_31 -> V_106 + V_31 -> V_80 ,
V_8 -> V_129 ) ;
V_31 -> V_106 = F_40 ( V_31 , V_130 , NULL ) ;
}
}
static void F_67 ( struct V_1 * V_2 , struct V_19 * V_19 ,
struct V_30 * V_31 , unsigned long V_20 ,
enum V_131 V_132 )
{
struct V_7 * V_8 = & V_2 -> V_7 ;
int V_133 = 0 , V_134 = 0 , V_135 = 0 ;
bool V_92 = V_132 & V_136 ;
F_16 ( & V_31 -> V_33 ) ;
if ( ! V_92 )
F_35 ( V_63 , V_116 L_17 ,
F_56 ( F_68 ( V_19 ) ) , V_20 ) ;
F_8 ( V_2 , V_92 ? V_137 : V_138 ) ;
if ( ! F_13 ( V_20 , V_31 -> V_121 , 8 , 8 ) ) {
V_133 = 1 ;
F_8 ( V_2 , V_139 ) ;
} else if ( ! V_92 && V_31 -> V_106 &&
V_20 < V_31 -> V_104 &&
F_13 ( V_20 , V_31 -> V_107 , 0 ,
V_31 -> V_106 ) ) {
V_135 = 1 ;
F_8 ( V_2 , V_140 ) ;
}
if ( V_31 -> V_34 >= 2 && ! V_31 -> V_35 ) {
T_2 V_141 ;
V_141 = ( F_69 ( V_19 ) + V_142 - 1 ) >>
V_112 ;
F_35 ( V_63 , L_18 , V_141 ,
V_8 -> V_143 , V_8 -> V_129 ) ;
if ( V_141 &&
V_141 <= V_8 -> V_143 ) {
V_31 -> V_107 = 0 ;
V_31 -> V_104 = V_20 + 1 ;
V_31 -> V_106 = V_6 ( V_8 -> V_129 ,
V_8 -> V_143 ) ;
goto V_144;
}
}
if ( V_133 ) {
if ( ! F_63 ( V_31 , V_20 ) ) {
if ( V_31 -> V_64 == 0 &&
V_31 -> V_35 == 0 ) {
F_64 ( V_31 , V_20 ) ;
V_31 -> V_64 ++ ;
} else {
F_60 ( V_31 ) ;
}
F_59 ( V_19 , V_31 , V_20 ) ;
V_31 -> V_122 ++ ;
goto V_144;
} else {
V_31 -> V_122 = 0 ;
V_31 -> V_36 = 0 ;
if ( ++ V_31 -> V_64 > 1 )
V_134 = 1 ;
F_55 ( V_31 ) ;
}
} else {
if ( V_135 ) {
if ( F_63 ( V_31 , V_20 ) &&
F_36 ( V_31 ) ) {
if ( V_20 != V_31 -> V_121 + 1 )
V_31 -> V_122 = 0 ;
F_59 ( V_19 , V_31 , V_20 ) ;
if ( V_31 -> V_107 <
V_31 -> V_105 )
F_60 ( V_31 ) ;
F_55 ( V_31 ) ;
} else {
F_59 ( V_19 , V_31 , V_20 ) ;
V_31 -> V_122 ++ ;
F_60 ( V_31 ) ;
goto V_144;
}
} else if ( F_36 ( V_31 ) ) {
if ( ! F_63 ( V_31 , V_20 ) ) {
F_60 ( V_31 ) ;
V_31 -> V_106 = 0 ;
V_31 -> V_104 = V_20 ;
}
}
}
V_31 -> V_122 ++ ;
V_31 -> V_121 = V_20 ;
F_58 ( V_19 , V_31 , V_20 ) ;
if ( F_36 ( V_31 ) ) {
V_31 -> V_104 = F_54 ( V_20 , V_31 -> V_104 ) ;
V_31 -> V_107 = F_54 ( V_31 -> V_105 ,
V_31 -> V_107 ) ;
} else {
if ( V_31 -> V_104 < V_31 -> V_107 )
V_31 -> V_104 = V_31 -> V_107 ;
if ( ! V_92 )
V_31 -> V_104 = V_20 + 1 ;
}
F_55 ( V_31 ) ;
if ( V_31 -> V_122 >= 4 && V_132 & V_145 ) {
F_66 ( V_19 , V_31 , V_8 ) ;
V_31 -> V_122 = 0 ;
goto V_144;
}
if ( V_31 -> V_64 == 2 && V_134 ) {
V_31 -> V_104 = F_54 ( V_20 , V_31 -> V_104 ) ;
V_31 -> V_105 = V_20 ;
V_31 -> V_107 = F_54 ( V_20 , V_31 -> V_107 ) ;
}
if ( ( V_31 -> V_36 > 1 || V_134 ) &&
! V_31 -> V_35 )
F_66 ( V_19 , V_31 , V_8 ) ;
V_144:
F_55 ( V_31 ) ;
V_31 -> V_35 ++ ;
F_17 ( & V_31 -> V_33 ) ;
}
int F_70 ( struct V_48 * V_51 , struct V_146 * V_147 )
{
struct V_19 * V_19 = V_51 -> V_56 -> V_148 ;
struct V_149 * V_150 = F_71 ( V_19 ) ;
struct V_37 * V_38 ;
struct V_39 * V_40 ;
struct V_47 * V_48 ;
struct V_43 * V_44 ;
bool V_151 = false ;
bool V_152 = false ;
int V_153 ;
int V_154 ;
F_43 ( F_72 ( V_51 ) ) ;
F_43 ( ! F_73 ( V_51 ) ) ;
F_43 ( F_74 ( V_19 ) ) ;
V_38 = F_75 ( & V_154 ) ;
if ( F_22 ( V_38 ) ) {
V_153 = F_23 ( V_38 ) ;
goto V_13;
}
V_44 = F_71 ( V_19 ) -> V_155 ;
F_43 ( V_44 ) ;
V_40 = F_76 ( V_38 ) ;
V_40 -> V_45 = V_44 ;
V_40 -> V_156 = 1 ;
V_153 = F_77 ( V_38 , V_40 , V_157 , V_44 ) ;
if ( V_153 == 0 ) {
V_48 = F_21 ( V_38 , V_44 , V_51 -> V_20 ,
V_51 , V_58 ) ;
if ( ! F_22 ( V_48 ) ) {
F_24 ( & V_48 -> V_59 , L_19 ,
V_60 ) ;
F_25 ( V_38 , V_40 , V_48 ) ;
V_153 = F_78 ( V_38 , V_40 , V_48 ) ;
if ( V_153 != 0 ) {
if ( ! F_79 ( V_51 ) ) {
F_80 ( V_147 , V_51 ) ;
V_153 = 0 ;
V_151 = true ;
}
}
F_81 ( V_38 , V_40 , V_48 ) ;
V_152 = true ;
F_31 ( & V_48 -> V_59 ,
L_19 , V_60 ) ;
F_32 ( V_38 , V_48 ) ;
} else {
V_153 = F_23 ( V_48 ) ;
}
}
F_82 ( V_38 , V_40 ) ;
if ( V_151 && V_147 -> V_158 == V_159 ) {
T_3 V_91 = F_83 ( V_44 , V_51 -> V_20 ) ;
V_153 = F_84 ( V_19 , V_91 ,
V_91 + V_142 - 1 ,
V_160 , 1 ) ;
if ( V_153 > 0 ) {
V_147 -> V_161 -= V_153 - 1 ;
V_153 = 0 ;
}
}
F_85 ( V_38 , & V_154 ) ;
goto V_13;
V_13:
if ( V_153 < 0 ) {
if ( ! V_150 -> V_162 )
V_150 -> V_162 = V_153 ;
F_86 ( V_51 ) ;
if ( ! V_152 )
F_33 ( V_51 ) ;
}
return V_153 ;
}
int F_87 ( struct V_163 * V_56 , struct V_146 * V_147 )
{
struct V_19 * V_19 = V_56 -> V_148 ;
struct V_1 * V_2 = F_12 ( V_19 ) ;
T_3 V_24 ;
T_3 V_25 ;
enum V_164 V_165 ;
int V_166 = 0 ;
int V_153 ;
int V_167 = 0 ;
if ( V_147 -> V_168 ) {
V_24 = V_56 -> V_169 << V_112 ;
V_25 = V_170 ;
} else {
V_24 = V_147 -> V_171 ;
V_25 = V_147 -> V_172 ;
if ( V_25 == V_173 ) {
V_25 = V_170 ;
V_166 = V_24 == 0 ;
}
}
V_165 = V_174 ;
if ( V_147 -> V_158 == V_159 )
V_165 = V_160 ;
if ( V_2 -> V_175 )
V_167 = 1 ;
if ( ! F_71 ( V_19 ) -> V_155 )
return 0 ;
V_153 = F_84 ( V_19 , V_24 , V_25 , V_165 , V_167 ) ;
if ( V_153 > 0 ) {
V_147 -> V_161 -= V_153 ;
V_153 = 0 ;
}
if ( V_147 -> V_168 || ( V_166 && V_147 -> V_161 > 0 ) ) {
if ( V_25 == V_170 )
V_56 -> V_169 = 0 ;
else
V_56 -> V_169 = ( V_25 >> V_112 ) + 1 ;
}
return V_153 ;
}
struct V_176 * F_88 ( struct V_26 * V_26 )
{
struct V_28 * V_29 = F_15 ( V_26 ) ;
struct V_176 * V_177 ;
struct V_176 * V_178 = NULL ;
F_89 ( & V_29 -> V_179 ) ;
F_90 (lcc, &fd->fd_lccs, lcc_list) {
if ( V_177 -> V_180 == V_60 ) {
V_178 = V_177 ;
break;
}
}
F_91 ( & V_29 -> V_179 ) ;
return V_178 ;
}
void F_92 ( struct V_26 * V_26 , const struct V_37 * V_38 , struct V_39 * V_40 )
{
struct V_28 * V_29 = F_15 ( V_26 ) ;
struct V_176 * V_177 = & F_49 ( V_38 ) -> V_181 ;
memset ( V_177 , 0 , sizeof( * V_177 ) ) ;
F_93 ( & V_177 -> V_182 ) ;
V_177 -> V_180 = V_60 ;
V_177 -> V_183 = V_38 ;
V_177 -> V_184 = V_40 ;
F_94 ( & V_29 -> V_179 ) ;
F_95 ( & V_177 -> V_182 , & V_29 -> V_185 ) ;
F_96 ( & V_29 -> V_179 ) ;
}
void F_97 ( struct V_26 * V_26 , const struct V_37 * V_38 )
{
struct V_28 * V_29 = F_15 ( V_26 ) ;
struct V_176 * V_177 = & F_49 ( V_38 ) -> V_181 ;
F_94 ( & V_29 -> V_179 ) ;
F_98 ( & V_177 -> V_182 ) ;
F_96 ( & V_29 -> V_179 ) ;
}
static int F_99 ( const struct V_37 * V_38 , struct V_39 * V_40 ,
struct V_47 * V_48 )
{
struct V_19 * V_19 = F_19 ( V_48 -> V_186 ) ;
struct V_28 * V_29 = F_48 ( V_38 ) -> V_187 ;
struct V_30 * V_31 = & V_29 -> V_32 ;
struct V_188 * V_42 = & V_40 -> V_189 ;
struct V_1 * V_2 = F_12 ( V_19 ) ;
struct V_49 * V_50 ;
bool V_190 ;
int V_52 = 0 ;
V_50 = F_26 ( F_27 ( V_48 -> V_186 , V_48 ) ) ;
V_190 = V_50 -> V_61 ;
if ( V_2 -> V_7 . V_129 > 0 &&
V_2 -> V_7 . V_10 > 0 ) {
struct V_93 * V_94 = F_48 ( V_38 ) ;
enum V_131 V_132 = 0 ;
if ( V_190 )
V_132 |= V_136 ;
if ( ! V_94 -> V_108 )
V_132 |= V_145 ;
F_67 ( V_2 , V_19 , V_31 , F_100 ( V_50 ) , V_132 ) ;
}
F_101 ( V_42 ) ;
if ( V_190 ) {
V_50 -> V_62 = 1 ;
F_102 ( V_38 , V_48 , 1 ) ;
F_81 ( V_38 , V_40 , V_48 ) ;
} else {
F_29 ( & V_42 -> V_191 , V_48 ) ;
}
if ( V_2 -> V_7 . V_129 > 0 &&
V_2 -> V_7 . V_10 > 0 ) {
int V_192 ;
V_192 = F_47 ( V_38 , V_40 , & V_42 -> V_191 , V_31 ,
V_190 ) ;
F_35 ( V_63 , V_116 L_20 ,
F_56 ( F_68 ( V_19 ) ) , V_192 , F_100 ( V_50 ) ) ;
}
if ( V_42 -> V_191 . V_193 > 0 )
V_52 = F_103 ( V_38 , V_40 , V_194 , V_42 ) ;
F_104 ( V_38 , V_40 , & V_42 -> V_191 ) ;
F_105 ( V_38 , V_42 ) ;
return V_52 ;
}
int F_106 ( struct V_26 * V_26 , struct V_48 * V_51 )
{
struct V_43 * V_44 = F_71 ( F_107 ( V_26 ) ) -> V_155 ;
struct V_176 * V_177 ;
const struct V_37 * V_38 ;
struct V_39 * V_40 ;
struct V_47 * V_48 ;
int V_153 ;
V_177 = F_88 ( V_26 ) ;
if ( ! V_177 ) {
F_33 ( V_51 ) ;
return - V_195 ;
}
V_38 = V_177 -> V_183 ;
V_40 = V_177 -> V_184 ;
F_43 ( V_40 -> V_196 == V_197 ) ;
V_48 = F_21 ( V_38 , V_44 , V_51 -> V_20 , V_51 , V_58 ) ;
if ( ! F_22 ( V_48 ) ) {
F_43 ( V_48 -> V_198 == V_58 ) ;
if ( F_108 ( ! F_28 ( V_51 ) ) ) {
F_25 ( V_38 , V_40 , V_48 ) ;
V_153 = F_99 ( V_38 , V_40 , V_48 ) ;
} else {
F_33 ( V_51 ) ;
V_153 = 0 ;
}
F_32 ( V_38 , V_48 ) ;
} else {
F_33 ( V_51 ) ;
V_153 = F_23 ( V_48 ) ;
}
return V_153 ;
}
int F_109 ( const struct V_37 * V_38 , struct V_39 * V_40 ,
struct V_47 * V_48 , enum V_199 V_200 )
{
struct V_188 * V_42 ;
int V_153 ;
F_43 ( V_40 -> V_201 == V_202 || V_40 -> V_201 == V_203 ) ;
V_42 = & V_40 -> V_189 ;
F_110 ( V_42 , V_48 ) ;
V_153 = F_111 ( V_38 , V_40 , V_200 , V_42 , 0 ) ;
F_43 ( F_112 ( V_48 , V_40 ) ) ;
if ( V_200 == V_194 )
F_104 ( V_38 , V_40 , & V_42 -> V_191 ) ;
F_105 ( V_38 , V_42 ) ;
return V_153 ;
}

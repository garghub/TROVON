static void
F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 -> V_4 , V_5 ) ;
F_2 ( & V_2 -> V_3 -> V_6 , V_5 ) ;
F_3 () ;
}
static void
F_4 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_3 -> V_4 , ~ V_5 ) ;
F_5 ( & V_2 -> V_3 -> V_6 , ~ V_5 ) ;
F_3 () ;
}
static T_1
F_6 ( T_2 V_7 )
{
T_3 V_8 , V_9 = F_7 () ;
int div = ( V_9 / ( 2 * V_7 ) ) - 1 ;
if ( div < 0 )
div = 0 ;
V_8 = V_9 / ( 2 * ( div + 1 ) ) ;
if ( V_8 > V_7 )
div ++ ;
return div ;
}
static void
F_8 ( struct V_10 * V_11 )
{
F_9 ( V_11 -> V_12 , 0 ) ;
}
static void
F_10 ( struct V_10 * V_11 )
{
F_9 ( V_11 -> V_12 , 1 ) ;
if ( V_11 -> V_13 )
F_11 ( V_11 -> V_13 ) ;
}
static void
F_12 ( struct V_1 * V_2 )
{
unsigned long V_14 = V_15 + V_16 ;
while ( ! ( F_13 ( & V_2 -> V_3 -> V_17 ) & V_18 ) ) {
if ( ! F_14 ( V_15 , V_14 ) )
break;
}
}
static void
F_15 ( struct V_1 * V_2 )
{
T_1 V_19 ;
while ( V_2 -> V_20 < V_2 -> V_21 ) {
F_16 ( & V_2 -> V_3 -> V_22 , * V_2 -> V_23 ++ ) ;
F_12 ( V_2 ) ;
V_19 = F_13 ( & V_2 -> V_3 -> V_24 ) ;
}
}
static void
F_17 ( struct V_1 * V_2 )
{
T_1 V_25 = V_2 -> V_26 -> V_27 ;
while ( V_2 -> V_28 < V_2 -> V_29 ) {
F_16 ( & V_2 -> V_3 -> V_22 , V_25 ) ;
F_12 ( V_2 ) ;
* V_2 -> V_30 ++ = F_13 ( & V_2 -> V_3 -> V_24 ) ;
}
}
static void
F_18 ( struct V_1 * V_2 )
{
while ( V_2 -> V_28 < V_2 -> V_29 ) {
F_16 ( & V_2 -> V_3 -> V_22 , * V_2 -> V_23 ++ ) ;
F_12 ( V_2 ) ;
* V_2 -> V_30 ++ = F_13 ( & V_2 -> V_3 -> V_24 ) ;
}
}
static void
F_19 ( struct V_1 * V_2 )
{
T_1 V_19 ;
while ( V_2 -> V_20 < V_2 -> V_21 ) {
F_16 ( & V_2 -> V_3 -> V_22 , * V_2 -> V_22 ++ ) ;
F_12 ( V_2 ) ;
V_19 = F_13 ( & V_2 -> V_3 -> V_24 ) ;
}
}
static void
F_20 ( struct V_1 * V_2 )
{
T_1 V_25 = V_2 -> V_26 -> V_27 ;
while ( V_2 -> V_28 < V_2 -> V_29 ) {
F_16 ( & V_2 -> V_3 -> V_22 , V_25 ) ;
F_12 ( V_2 ) ;
* V_2 -> V_24 ++ = F_13 ( & V_2 -> V_3 -> V_24 ) ;
}
}
static void
F_21 ( struct V_1 * V_2 )
{
while ( V_2 -> V_28 < V_2 -> V_29 ) {
F_16 ( & V_2 -> V_3 -> V_22 , * V_2 -> V_22 ++ ) ;
F_12 ( V_2 ) ;
* V_2 -> V_24 ++ = F_13 ( & V_2 -> V_3 -> V_24 ) ;
}
}
static void
F_22 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_26 ;
unsigned int V_31 = ( V_2 -> V_32 == & V_33 ? 7 : 15 ) ;
F_4 ( V_2 ) ;
F_23 ( V_2 -> V_34 , L_1 ) ;
F_16 ( & V_2 -> V_3 -> V_4 , V_11 -> V_35 ) ;
F_16 ( & V_2 -> V_3 -> V_36 , V_31 ) ;
F_16 ( & V_2 -> V_3 -> V_37 , V_11 -> V_38 ) ;
F_16 ( & V_2 -> V_3 -> V_39 , V_31 ) ;
F_3 () ;
F_16 ( & V_2 -> V_3 -> V_6 , V_11 -> V_35 & ~ ( V_40 | V_41 ) ) ;
F_16 ( & V_2 -> V_3 -> V_42 , V_31 ) ;
F_3 () ;
F_8 ( V_11 ) ;
}
static enum V_43
F_24 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_46 ;
struct V_47 * V_48 = V_2 -> V_49 ;
if ( V_48 -> V_50 . V_51 != & V_45 -> V_52 ) {
V_2 -> V_49 =
F_25 ( V_48 -> V_50 . V_51 ,
struct V_47 , V_50 ) ;
return V_53 ;
}
return V_54 ;
}
static void
F_26 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_26 ;
unsigned long V_55 ;
struct V_44 * V_45 ;
F_27 ( & V_2 -> V_56 , V_55 ) ;
V_45 = V_2 -> V_46 ;
V_2 -> V_57 = V_58 ;
V_2 -> V_46 = NULL ;
V_2 -> V_49 = NULL ;
V_2 -> V_26 = NULL ;
F_28 ( V_2 -> V_59 , & V_2 -> V_60 ) ;
F_29 ( & V_2 -> V_56 , V_55 ) ;
if ( ! V_2 -> V_61 )
F_10 ( V_11 ) ;
if ( V_45 -> V_62 )
V_45 -> V_62 ( V_45 -> V_63 ) ;
}
static T_4
F_30 ( int V_64 , void * V_65 )
{
struct V_1 * V_2 = V_65 ;
T_1 V_66 ;
F_23 ( V_2 -> V_34 , L_2 , V_67 ) ;
V_66 = F_13 ( & V_2 -> V_3 -> V_17 ) & ( V_68 | V_69 | V_70 | V_71 ) ;
if ( V_66 ) {
F_16 ( & V_2 -> V_3 -> V_17 , V_66 ) ;
F_3 () ;
F_4 ( V_2 ) ;
F_31 ( V_2 -> V_34 , L_3 ,
V_66 & V_68 ? L_4 : L_5 ,
V_66 & V_69 ? L_6 : L_5 ,
V_66 & V_70 ? L_7 : L_5 ,
V_66 & V_71 ? L_8 : L_5 ) ;
}
return V_72 ;
}
static void
F_32 ( unsigned long V_73 )
{
struct V_1 * V_2 = ( void * ) V_73 ;
struct V_44 * V_74 = NULL ;
struct V_47 * V_75 = NULL ;
struct V_47 * V_76 = NULL ;
struct V_10 * V_11 = NULL ;
unsigned int V_77 ;
T_2 V_78 = 1 ;
T_2 V_79 ;
T_5 V_80 = 0 ;
V_74 = V_2 -> V_46 ;
V_75 = V_2 -> V_49 ;
V_11 = V_2 -> V_26 ;
if ( V_75 -> V_7 )
V_79 = F_6 ( V_75 -> V_7 ) ;
else
V_79 = V_11 -> V_38 ;
F_16 ( & V_2 -> V_3 -> V_37 , V_79 ) ;
F_3 () ;
if ( V_2 -> V_57 == V_81 ) {
F_23 ( V_2 -> V_34 , L_9 ) ;
V_74 -> V_66 = - V_82 ;
F_26 ( V_2 ) ;
return;
}
if ( V_2 -> V_57 == V_54 ) {
F_23 ( V_2 -> V_34 , L_10 ) ;
V_74 -> V_66 = 0 ;
F_26 ( V_2 ) ;
return;
}
if ( V_2 -> V_57 == V_53 ) {
F_23 ( V_2 -> V_34 , L_11 ) ;
V_76 = F_25 ( V_75 -> V_50 . V_83 ,
struct V_47 , V_50 ) ;
if ( V_76 -> V_84 )
F_11 ( V_76 -> V_84 ) ;
}
if ( V_75 -> V_85 == 0 ) {
V_2 -> V_57 = F_24 ( V_2 ) ;
F_33 ( & V_2 -> V_86 ) ;
}
if ( V_75 -> V_87 != NULL ) {
V_2 -> V_20 = ( void * ) V_75 -> V_87 ;
V_2 -> V_21 = V_2 -> V_20 + V_75 -> V_85 ;
F_23 ( V_2 -> V_34 , L_12 ,
V_75 -> V_87 , V_2 -> V_21 ) ;
} else
V_2 -> V_20 = NULL ;
if ( V_75 -> V_88 != NULL ) {
V_80 = V_75 -> V_87 != NULL ;
V_2 -> V_28 = V_75 -> V_88 ;
V_2 -> V_29 = V_2 -> V_28 + V_75 -> V_85 ;
F_23 ( V_2 -> V_34 , L_13 ,
V_75 -> V_88 , V_2 -> V_29 ) ;
} else
V_2 -> V_28 = NULL ;
V_2 -> V_61 = V_75 -> V_61 ;
V_77 = V_75 -> V_77 ? : V_74 -> V_89 -> V_77 ;
if ( V_77 == 8 )
V_2 -> V_32 = & V_33 ;
else
V_2 -> V_32 = & V_90 ;
V_2 -> V_57 = V_53 ;
if ( V_2 -> V_61 )
F_8 ( V_11 ) ;
F_23 ( V_2 -> V_34 ,
L_14 ,
V_77 , V_75 -> V_85 ) ;
F_23 ( V_2 -> V_34 , L_15 ) ;
F_1 ( V_2 ) ;
if ( V_80 ) {
F_34 ( ( V_2 -> V_21 - V_2 -> V_20 ) !=
( V_2 -> V_29 - V_2 -> V_28 ) ) ;
V_2 -> V_32 -> V_91 ( V_2 ) ;
if ( V_2 -> V_20 != V_2 -> V_21 )
V_78 = 0 ;
} else if ( V_2 -> V_20 != NULL ) {
V_2 -> V_32 -> V_92 ( V_2 ) ;
if ( V_2 -> V_20 != V_2 -> V_21 )
V_78 = 0 ;
} else if ( V_2 -> V_28 != NULL ) {
V_2 -> V_32 -> V_93 ( V_2 ) ;
if ( V_2 -> V_28 != V_2 -> V_29 )
V_78 = 0 ;
}
F_4 ( V_2 ) ;
if ( ! V_78 ) {
F_23 ( V_2 -> V_34 , L_16 ) ;
V_2 -> V_57 = V_81 ;
} else {
V_74 -> V_94 += V_75 -> V_85 ;
V_2 -> V_57 = F_24 ( V_2 ) ;
if ( V_2 -> V_61 )
F_10 ( V_11 ) ;
}
F_33 ( & V_2 -> V_86 ) ;
}
static void
F_35 ( struct V_95 * V_96 )
{
struct V_1 * V_2 ;
unsigned long V_55 ;
struct V_44 * V_97 ;
V_2 = F_36 ( V_96 , struct V_1 , V_60 ) ;
F_27 ( & V_2 -> V_56 , V_55 ) ;
if ( F_37 ( & V_2 -> V_98 ) || ! V_2 -> V_99 ) {
V_2 -> V_100 = 0 ;
F_29 ( & V_2 -> V_56 , V_55 ) ;
return;
}
if ( V_2 -> V_46 ) {
F_29 ( & V_2 -> V_56 , V_55 ) ;
return;
}
V_97 = F_25 ( V_2 -> V_98 . V_51 ,
struct V_44 , V_98 ) ;
V_2 -> V_46 = V_97 ;
V_2 -> V_26 = F_38 ( V_2 -> V_46 -> V_89 ) ;
F_39 ( & V_2 -> V_46 -> V_98 ) ;
V_2 -> V_46 -> V_57 = V_58 ;
V_2 -> V_49 = F_25 ( V_2 -> V_46 -> V_52 . V_51 ,
struct V_47 , V_50 ) ;
F_22 ( V_2 ) ;
F_23 ( V_2 -> V_34 , L_17
L_18 ,
V_2 -> V_26 -> V_38 , V_2 -> V_26 -> V_12 ,
V_2 -> V_26 -> V_35 ) ;
F_23 ( V_2 -> V_34 ,
L_19 ,
V_2 -> V_49 -> V_85 ) ;
F_33 ( & V_2 -> V_86 ) ;
V_2 -> V_100 = 1 ;
F_29 ( & V_2 -> V_56 , V_55 ) ;
}
static int
F_40 ( struct V_101 * V_89 , struct V_44 * V_45 )
{
struct V_1 * V_2 = F_41 ( V_89 -> V_102 ) ;
unsigned long V_55 ;
F_27 ( & V_2 -> V_56 , V_55 ) ;
if ( ! V_2 -> V_99 ) {
F_29 ( & V_2 -> V_56 , V_55 ) ;
return - V_103 ;
}
V_45 -> V_94 = 0 ;
V_45 -> V_66 = - V_104 ;
V_45 -> V_57 = V_58 ;
F_23 ( & V_89 -> V_34 , L_20 ) ;
F_42 ( & V_45 -> V_98 , & V_2 -> V_98 ) ;
if ( V_2 -> V_99 && ! V_2 -> V_100 )
F_28 ( V_2 -> V_59 , & V_2 -> V_60 ) ;
F_29 ( & V_2 -> V_56 , V_55 ) ;
return 0 ;
}
static int
F_43 ( struct V_101 * V_89 )
{
struct V_10 * V_11 , * V_105 = NULL ;
int V_106 ;
V_11 = F_38 ( V_89 ) ;
if ( V_11 == NULL ) {
struct V_107 * V_108 ;
V_11 = V_105 = F_44 ( sizeof( * V_11 ) , V_109 ) ;
if ( ! V_11 )
return - V_110 ;
V_108 = V_89 -> V_111 ;
if ( V_108 ) {
if ( V_108 -> V_35 || V_108 -> V_112 ) {
V_106 = - V_113 ;
F_31 ( & V_89 -> V_34 , L_21 ) ;
goto error;
}
V_11 -> V_13 = V_108 -> V_13 ;
V_11 -> V_27 = V_108 -> V_27 ;
V_89 -> V_77 = V_108 -> V_77 ;
}
}
if ( V_89 -> V_77 != 8 && V_89 -> V_77 != 16 ) {
V_106 = - V_113 ;
goto error;
}
if ( V_89 -> V_114 & V_115 )
V_11 -> V_35 &= ~ V_116 ;
else
V_11 -> V_35 |= V_116 ;
if ( V_89 -> V_114 & V_117 )
V_11 -> V_35 |= V_118 ;
else
V_11 -> V_35 &= ~ V_118 ;
V_11 -> V_35 |= V_40 | V_41 | V_119 | V_120 | V_121 ;
V_11 -> V_38 = F_6 ( V_89 -> V_122 ) ;
V_11 -> V_12 = V_89 -> V_123 ;
V_106 = F_45 ( V_11 -> V_12 , V_89 -> V_124 ) ;
if ( V_106 )
goto error;
F_23 ( & V_89 -> V_34 , L_22 ,
V_89 -> V_124 , V_89 -> V_77 ) ;
F_23 ( & V_89 -> V_34 , L_23 ,
V_11 -> V_35 , V_89 -> V_123 ) ;
F_46 ( V_89 , V_11 ) ;
F_10 ( V_11 ) ;
return V_106 ;
error:
F_47 ( V_105 ) ;
return V_106 ;
}
static void
F_48 ( struct V_101 * V_89 )
{
struct V_10 * V_11 = F_38 ( V_89 ) ;
if ( ! V_11 )
return;
F_49 ( V_11 -> V_12 ) ;
F_47 ( V_11 ) ;
}
static int
F_50 ( struct V_1 * V_2 )
{
F_51 ( & V_2 -> V_98 ) ;
F_52 ( & V_2 -> V_56 ) ;
V_2 -> V_99 = false ;
V_2 -> V_100 = 0 ;
F_53 ( & V_2 -> V_86 ,
F_32 , ( unsigned long ) V_2 ) ;
F_54 ( & V_2 -> V_60 , F_35 ) ;
V_2 -> V_59 =
F_55 ( F_56 ( V_2 -> V_102 -> V_34 . V_125 ) ) ;
if ( V_2 -> V_59 == NULL )
return - V_126 ;
return 0 ;
}
static int
F_57 ( struct V_1 * V_2 )
{
unsigned long V_55 ;
F_27 ( & V_2 -> V_56 , V_55 ) ;
if ( V_2 -> V_99 || V_2 -> V_100 ) {
F_29 ( & V_2 -> V_56 , V_55 ) ;
return - V_126 ;
}
V_2 -> V_99 = true ;
V_2 -> V_46 = NULL ;
V_2 -> V_49 = NULL ;
V_2 -> V_26 = NULL ;
F_29 ( & V_2 -> V_56 , V_55 ) ;
F_28 ( V_2 -> V_59 , & V_2 -> V_60 ) ;
return 0 ;
}
static inline int
F_58 ( struct V_1 * V_2 )
{
unsigned long V_55 ;
unsigned V_127 = 500 ;
int V_66 = 0 ;
F_27 ( & V_2 -> V_56 , V_55 ) ;
V_2 -> V_99 = false ;
while ( ! F_37 ( & V_2 -> V_98 ) && V_2 -> V_100 && V_127 -- ) {
F_29 ( & V_2 -> V_56 , V_55 ) ;
F_59 ( 10 ) ;
F_27 ( & V_2 -> V_56 , V_55 ) ;
}
if ( ! F_37 ( & V_2 -> V_98 ) || V_2 -> V_100 )
V_66 = - V_126 ;
F_29 ( & V_2 -> V_56 , V_55 ) ;
return V_66 ;
}
static inline int
F_60 ( struct V_1 * V_2 )
{
int V_66 ;
V_66 = F_58 ( V_2 ) ;
if ( V_66 )
return V_66 ;
F_61 ( V_2 -> V_59 ) ;
return 0 ;
}
static int T_6
F_62 ( struct V_128 * V_129 )
{
struct V_130 * V_34 = & V_129 -> V_34 ;
struct V_131 * V_132 ;
struct V_133 * V_102 ;
struct V_134 * V_135 , * V_136 ;
struct V_1 * V_2 ;
int V_66 ;
V_132 = V_34 -> V_137 ;
V_102 = F_63 ( V_34 , sizeof( * V_102 ) + 16 ) ;
if ( ! V_102 ) {
F_31 ( V_34 , L_24 ) ;
return - V_110 ;
}
V_2 = F_41 ( V_102 ) ;
V_2 -> V_102 = V_102 ;
V_2 -> V_34 = V_34 ;
V_2 -> V_138 = V_132 -> V_138 ;
V_102 -> V_139 = V_140 | V_115 | V_117 ;
V_102 -> V_141 = V_129 -> V_142 ;
V_102 -> V_143 = V_132 -> V_143 ;
V_102 -> V_144 = F_48 ;
V_102 -> V_145 = F_43 ;
V_102 -> V_75 = F_40 ;
V_135 = F_64 ( V_129 , V_146 , 0 ) ;
if ( V_135 == NULL ) {
F_31 ( V_34 , L_25 ) ;
V_66 = - V_147 ;
goto V_148;
}
V_2 -> V_3 = F_65 ( V_135 -> V_149 , F_66 ( V_135 ) ) ;
if ( V_2 -> V_3 == NULL ) {
F_31 ( V_34 , L_26 ) ;
V_66 = - V_150 ;
goto V_151;
}
V_136 = F_64 ( V_129 , V_152 , 0 ) ;
if ( ! V_136 ) {
F_31 ( V_34 , L_27 ) ;
V_66 = - V_153 ;
goto V_154;
}
V_2 -> V_155 = V_136 -> V_149 ;
V_66 = F_50 ( V_2 ) ;
if ( V_66 ) {
F_31 ( V_34 , L_28 ) ;
goto V_156;
}
V_66 = F_57 ( V_2 ) ;
if ( V_66 ) {
F_31 ( V_34 , L_29 ) ;
goto V_156;
}
V_66 = F_67 ( V_2 -> V_155 , F_30 ,
0 , L_30 , V_2 ) ;
if ( V_66 ) {
F_31 ( V_34 , L_31 ) ;
goto V_157;
}
V_66 = F_68 ( V_2 -> V_138 , V_158 ) ;
if ( V_66 ) {
F_31 ( V_34 , L_32 ) ;
goto V_159;
}
F_69 ( V_129 , V_2 ) ;
V_66 = F_70 ( V_102 ) ;
if ( V_66 ) {
F_31 ( V_34 , L_33 ) ;
goto V_160;
}
F_71 ( V_34 , L_34 , V_161 , V_2 -> V_3 ) ;
return 0 ;
V_160:
F_72 ( V_2 -> V_138 ) ;
V_159:
F_73 ( V_2 -> V_155 , V_2 ) ;
V_157:
V_156:
F_60 ( V_2 ) ;
V_154:
F_74 ( V_2 -> V_3 ) ;
V_151:
V_148:
F_75 ( V_102 ) ;
return V_66 ;
}
static int T_7
F_76 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = F_77 ( V_129 ) ;
int V_66 = 0 ;
if ( ! V_2 )
return 0 ;
V_66 = F_60 ( V_2 ) ;
if ( V_66 )
return V_66 ;
F_4 ( V_2 ) ;
F_78 ( V_2 -> V_102 ) ;
F_72 ( V_2 -> V_138 ) ;
F_69 ( V_129 , NULL ) ;
return 0 ;
}
static int
F_79 ( struct V_128 * V_129 , T_8 V_57 )
{
struct V_1 * V_2 = F_77 ( V_129 ) ;
int V_66 ;
V_66 = F_58 ( V_2 ) ;
if ( V_66 )
return V_66 ;
F_4 ( V_2 ) ;
return V_66 ;
}
static int
F_80 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = F_77 ( V_129 ) ;
int V_66 ;
F_1 ( V_2 ) ;
V_66 = F_57 ( V_2 ) ;
if ( V_66 )
F_31 ( V_2 -> V_34 , L_35 ) ;
return V_66 ;
}
static int T_9 F_81 ( void )
{
return F_82 ( & V_162 ) ;
}
static void T_10 F_83 ( void )
{
F_84 ( & V_162 ) ;
}

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
F_4 ( V_2 ) ;
F_23 ( V_2 -> V_31 , L_1 ) ;
F_16 ( & V_2 -> V_3 -> V_4 , V_11 -> V_32 ) ;
F_16 ( & V_2 -> V_3 -> V_33 , V_11 -> V_34 ) ;
F_3 () ;
F_16 ( & V_2 -> V_3 -> V_6 , V_11 -> V_32 & ~ ( V_35 | V_36 ) ) ;
F_3 () ;
F_8 ( V_11 ) ;
}
static enum V_37
F_24 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
struct V_41 * V_42 = V_2 -> V_43 ;
if ( V_42 -> V_44 . V_45 != & V_39 -> V_46 ) {
V_2 -> V_43 =
F_25 ( V_42 -> V_44 . V_45 ,
struct V_41 , V_44 ) ;
return V_47 ;
}
return V_48 ;
}
static void
F_26 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_26 ;
unsigned long V_49 ;
struct V_38 * V_39 ;
F_27 ( & V_2 -> V_50 , V_49 ) ;
V_39 = V_2 -> V_40 ;
V_2 -> V_51 = V_52 ;
V_2 -> V_40 = NULL ;
V_2 -> V_43 = NULL ;
V_2 -> V_26 = NULL ;
F_28 ( & V_2 -> V_53 ) ;
F_29 ( & V_2 -> V_50 , V_49 ) ;
if ( ! V_2 -> V_54 )
F_10 ( V_11 ) ;
if ( V_39 -> V_55 )
V_39 -> V_55 ( V_39 -> V_56 ) ;
}
static T_4
F_30 ( int V_57 , void * V_58 )
{
struct V_1 * V_2 = V_58 ;
T_1 V_59 ;
F_23 ( V_2 -> V_31 , L_2 , V_60 ) ;
V_59 = F_13 ( & V_2 -> V_3 -> V_17 ) & ( V_61 | V_62 | V_63 | V_64 ) ;
if ( V_59 ) {
F_16 ( & V_2 -> V_3 -> V_17 , V_59 ) ;
F_3 () ;
F_4 ( V_2 ) ;
F_31 ( V_2 -> V_31 , L_3 ,
V_59 & V_61 ? L_4 : L_5 ,
V_59 & V_62 ? L_6 : L_5 ,
V_59 & V_63 ? L_7 : L_5 ,
V_59 & V_64 ? L_8 : L_5 ) ;
}
return V_65 ;
}
static void
F_32 ( unsigned long V_66 )
{
struct V_1 * V_2 = ( void * ) V_66 ;
struct V_38 * V_67 = NULL ;
struct V_41 * V_68 = NULL ;
struct V_41 * V_69 = NULL ;
struct V_10 * V_11 = NULL ;
unsigned int V_70 ;
T_2 V_71 = 1 ;
T_2 V_72 ;
T_5 V_73 = 0 ;
V_67 = V_2 -> V_40 ;
V_68 = V_2 -> V_43 ;
V_11 = V_2 -> V_26 ;
V_72 = F_6 ( V_68 -> V_7 ) ;
F_16 ( & V_2 -> V_3 -> V_33 , V_72 ) ;
F_3 () ;
if ( V_2 -> V_51 == V_74 ) {
F_23 ( V_2 -> V_31 , L_9 ) ;
V_67 -> V_59 = - V_75 ;
F_26 ( V_2 ) ;
return;
}
if ( V_2 -> V_51 == V_48 ) {
F_23 ( V_2 -> V_31 , L_10 ) ;
V_67 -> V_59 = 0 ;
F_26 ( V_2 ) ;
return;
}
if ( V_2 -> V_51 == V_47 ) {
F_23 ( V_2 -> V_31 , L_11 ) ;
V_69 = F_25 ( V_68 -> V_44 . V_76 ,
struct V_41 , V_44 ) ;
if ( V_69 -> V_77 )
F_11 ( V_69 -> V_77 ) ;
}
if ( V_68 -> V_78 == 0 ) {
V_2 -> V_51 = F_24 ( V_2 ) ;
F_33 ( & V_2 -> V_79 ) ;
}
if ( V_68 -> V_80 != NULL ) {
V_2 -> V_20 = ( void * ) V_68 -> V_80 ;
V_2 -> V_21 = V_2 -> V_20 + V_68 -> V_78 ;
F_23 ( V_2 -> V_31 , L_12 ,
V_68 -> V_80 , V_2 -> V_21 ) ;
} else
V_2 -> V_20 = NULL ;
if ( V_68 -> V_81 != NULL ) {
V_73 = V_68 -> V_80 != NULL ;
V_2 -> V_28 = V_68 -> V_81 ;
V_2 -> V_29 = V_2 -> V_28 + V_68 -> V_78 ;
F_23 ( V_2 -> V_31 , L_13 ,
V_68 -> V_81 , V_2 -> V_29 ) ;
} else
V_2 -> V_28 = NULL ;
V_2 -> V_54 = V_68 -> V_54 ;
V_70 = V_68 -> V_70 ;
if ( V_70 == 16 )
V_2 -> V_82 = & V_83 ;
else
V_2 -> V_82 = & V_84 ;
F_16 ( & V_2 -> V_3 -> V_85 , V_70 - 1 ) ;
F_16 ( & V_2 -> V_3 -> V_86 , V_70 - 1 ) ;
F_16 ( & V_2 -> V_3 -> V_87 , V_70 - 1 ) ;
V_2 -> V_51 = V_47 ;
if ( V_2 -> V_54 )
F_8 ( V_11 ) ;
F_23 ( V_2 -> V_31 ,
L_14 ,
V_70 , V_68 -> V_78 ) ;
F_23 ( V_2 -> V_31 , L_15 ) ;
F_1 ( V_2 ) ;
if ( V_73 ) {
F_34 ( ( V_2 -> V_21 - V_2 -> V_20 ) !=
( V_2 -> V_29 - V_2 -> V_28 ) ) ;
V_2 -> V_82 -> V_88 ( V_2 ) ;
if ( V_2 -> V_20 != V_2 -> V_21 )
V_71 = 0 ;
} else if ( V_2 -> V_20 != NULL ) {
V_2 -> V_82 -> V_89 ( V_2 ) ;
if ( V_2 -> V_20 != V_2 -> V_21 )
V_71 = 0 ;
} else if ( V_2 -> V_28 != NULL ) {
V_2 -> V_82 -> V_90 ( V_2 ) ;
if ( V_2 -> V_28 != V_2 -> V_29 )
V_71 = 0 ;
}
F_4 ( V_2 ) ;
if ( ! V_71 ) {
F_23 ( V_2 -> V_31 , L_16 ) ;
V_2 -> V_51 = V_74 ;
} else {
V_67 -> V_91 += V_68 -> V_78 ;
V_2 -> V_51 = F_24 ( V_2 ) ;
if ( V_2 -> V_54 )
F_10 ( V_11 ) ;
}
F_33 ( & V_2 -> V_79 ) ;
}
static void
F_35 ( struct V_92 * V_93 )
{
struct V_1 * V_2 ;
unsigned long V_49 ;
struct V_38 * V_94 ;
V_2 = F_36 ( V_93 , struct V_1 , V_53 ) ;
F_27 ( & V_2 -> V_50 , V_49 ) ;
if ( F_37 ( & V_2 -> V_95 ) || ! V_2 -> V_96 ) {
V_2 -> V_97 = 0 ;
F_29 ( & V_2 -> V_50 , V_49 ) ;
return;
}
if ( V_2 -> V_40 ) {
F_29 ( & V_2 -> V_50 , V_49 ) ;
return;
}
V_94 = F_25 ( V_2 -> V_95 . V_45 ,
struct V_38 , V_95 ) ;
V_2 -> V_40 = V_94 ;
V_2 -> V_26 = F_38 ( V_2 -> V_40 -> V_98 ) ;
F_39 ( & V_2 -> V_40 -> V_95 ) ;
V_2 -> V_40 -> V_51 = V_52 ;
V_2 -> V_43 = F_25 ( V_2 -> V_40 -> V_46 . V_45 ,
struct V_41 , V_44 ) ;
F_22 ( V_2 ) ;
F_23 ( V_2 -> V_31 , L_17
L_18 ,
V_2 -> V_26 -> V_34 , V_2 -> V_26 -> V_12 ,
V_2 -> V_26 -> V_32 ) ;
F_23 ( V_2 -> V_31 ,
L_19 ,
V_2 -> V_43 -> V_78 ) ;
F_33 ( & V_2 -> V_79 ) ;
V_2 -> V_97 = 1 ;
F_29 ( & V_2 -> V_50 , V_49 ) ;
}
static int
F_40 ( struct V_99 * V_98 , struct V_38 * V_39 )
{
struct V_1 * V_2 = F_41 ( V_98 -> V_100 ) ;
unsigned long V_49 ;
F_27 ( & V_2 -> V_50 , V_49 ) ;
if ( ! V_2 -> V_96 ) {
F_29 ( & V_2 -> V_50 , V_49 ) ;
return - V_101 ;
}
V_39 -> V_91 = 0 ;
V_39 -> V_59 = - V_102 ;
V_39 -> V_51 = V_52 ;
F_23 ( & V_98 -> V_31 , L_20 ) ;
F_42 ( & V_39 -> V_95 , & V_2 -> V_95 ) ;
if ( V_2 -> V_96 && ! V_2 -> V_97 )
F_28 ( & V_2 -> V_53 ) ;
F_29 ( & V_2 -> V_50 , V_49 ) ;
return 0 ;
}
static int
F_43 ( struct V_99 * V_98 )
{
struct V_10 * V_11 , * V_103 = NULL ;
int V_104 ;
V_11 = F_38 ( V_98 ) ;
if ( V_11 == NULL ) {
struct V_105 * V_106 ;
V_11 = V_103 = F_44 ( sizeof( * V_11 ) , V_107 ) ;
if ( ! V_11 )
return - V_108 ;
V_106 = V_98 -> V_109 ;
if ( V_106 ) {
if ( V_106 -> V_32 || V_106 -> V_110 ) {
V_104 = - V_111 ;
F_31 ( & V_98 -> V_31 , L_21 ) ;
goto error;
}
V_11 -> V_13 = V_106 -> V_13 ;
V_11 -> V_27 = V_106 -> V_27 ;
}
}
if ( V_98 -> V_112 & V_113 )
V_11 -> V_32 &= ~ V_114 ;
else
V_11 -> V_32 |= V_114 ;
if ( V_98 -> V_112 & V_115 )
V_11 -> V_32 |= V_116 ;
else
V_11 -> V_32 &= ~ V_116 ;
V_11 -> V_32 |= V_35 | V_36 | V_117 | V_118 | V_119 ;
V_11 -> V_34 = F_6 ( V_98 -> V_120 ) ;
V_11 -> V_12 = V_98 -> V_121 ;
V_104 = F_45 ( V_11 -> V_12 , V_98 -> V_122 ) ;
if ( V_104 )
goto error;
F_23 ( & V_98 -> V_31 , L_22 ,
V_98 -> V_122 , V_98 -> V_70 ) ;
F_23 ( & V_98 -> V_31 , L_23 ,
V_11 -> V_32 , V_98 -> V_121 ) ;
F_46 ( V_98 , V_11 ) ;
F_10 ( V_11 ) ;
return V_104 ;
error:
F_47 ( V_103 ) ;
return V_104 ;
}
static void
F_48 ( struct V_99 * V_98 )
{
struct V_10 * V_11 = F_38 ( V_98 ) ;
if ( ! V_11 )
return;
F_49 ( V_11 -> V_12 ) ;
F_47 ( V_11 ) ;
}
static int
F_50 ( struct V_1 * V_2 )
{
F_51 ( & V_2 -> V_95 ) ;
F_52 ( & V_2 -> V_50 ) ;
V_2 -> V_96 = false ;
V_2 -> V_97 = 0 ;
F_53 ( & V_2 -> V_79 ,
F_32 , ( unsigned long ) V_2 ) ;
F_54 ( & V_2 -> V_53 , F_35 ) ;
return 0 ;
}
static int
F_55 ( struct V_1 * V_2 )
{
unsigned long V_49 ;
F_27 ( & V_2 -> V_50 , V_49 ) ;
if ( V_2 -> V_96 || V_2 -> V_97 ) {
F_29 ( & V_2 -> V_50 , V_49 ) ;
return - V_123 ;
}
V_2 -> V_96 = true ;
V_2 -> V_40 = NULL ;
V_2 -> V_43 = NULL ;
V_2 -> V_26 = NULL ;
F_29 ( & V_2 -> V_50 , V_49 ) ;
F_28 ( & V_2 -> V_53 ) ;
return 0 ;
}
static inline int
F_56 ( struct V_1 * V_2 )
{
unsigned long V_49 ;
unsigned V_124 = 500 ;
int V_59 = 0 ;
F_27 ( & V_2 -> V_50 , V_49 ) ;
V_2 -> V_96 = false ;
while ( ! F_37 ( & V_2 -> V_95 ) && V_2 -> V_97 && V_124 -- ) {
F_29 ( & V_2 -> V_50 , V_49 ) ;
F_57 ( 10 ) ;
F_27 ( & V_2 -> V_50 , V_49 ) ;
}
if ( ! F_37 ( & V_2 -> V_95 ) || V_2 -> V_97 )
V_59 = - V_123 ;
F_29 ( & V_2 -> V_50 , V_49 ) ;
return V_59 ;
}
static inline int
F_58 ( struct V_1 * V_2 )
{
int V_59 ;
V_59 = F_56 ( V_2 ) ;
if ( V_59 )
return V_59 ;
F_59 ( & V_2 -> V_53 ) ;
return 0 ;
}
static int F_60 ( struct V_125 * V_126 )
{
struct V_127 * V_31 = & V_126 -> V_31 ;
struct V_128 * V_129 ;
struct V_130 * V_100 ;
struct V_131 * V_132 , * V_133 ;
struct V_1 * V_2 ;
int V_59 ;
V_129 = F_61 ( V_31 ) ;
V_100 = F_62 ( V_31 , sizeof( * V_100 ) + 16 ) ;
if ( ! V_100 ) {
F_31 ( V_31 , L_24 ) ;
return - V_108 ;
}
V_2 = F_41 ( V_100 ) ;
V_2 -> V_100 = V_100 ;
V_2 -> V_31 = V_31 ;
V_2 -> V_134 = V_129 -> V_134 ;
V_100 -> V_135 = V_136 | V_113 | V_115 ;
V_100 -> V_137 = F_63 ( 8 ) | F_63 ( 16 ) ;
V_100 -> V_138 = V_126 -> V_139 ;
V_100 -> V_140 = V_129 -> V_140 ;
V_100 -> V_141 = F_48 ;
V_100 -> V_142 = F_43 ;
V_100 -> V_68 = F_40 ;
V_132 = F_64 ( V_126 , V_143 , 0 ) ;
if ( V_132 == NULL ) {
F_31 ( V_31 , L_25 ) ;
V_59 = - V_144 ;
goto V_145;
}
V_2 -> V_3 = F_65 ( V_132 -> V_146 , F_66 ( V_132 ) ) ;
if ( V_2 -> V_3 == NULL ) {
F_31 ( V_31 , L_26 ) ;
V_59 = - V_147 ;
goto V_148;
}
V_133 = F_64 ( V_126 , V_149 , 0 ) ;
if ( ! V_133 ) {
F_31 ( V_31 , L_27 ) ;
V_59 = - V_150 ;
goto V_151;
}
V_2 -> V_152 = V_133 -> V_146 ;
V_59 = F_50 ( V_2 ) ;
if ( V_59 ) {
F_31 ( V_31 , L_28 ) ;
goto V_153;
}
V_59 = F_55 ( V_2 ) ;
if ( V_59 ) {
F_31 ( V_31 , L_29 ) ;
goto V_153;
}
V_59 = F_67 ( V_2 -> V_152 , F_30 ,
0 , L_30 , V_2 ) ;
if ( V_59 ) {
F_31 ( V_31 , L_31 ) ;
goto V_154;
}
V_59 = F_68 ( V_2 -> V_134 , V_155 ) ;
if ( V_59 ) {
F_31 ( V_31 , L_32 ) ;
goto V_156;
}
F_69 ( V_126 , V_2 ) ;
V_59 = F_70 ( V_100 ) ;
if ( V_59 ) {
F_31 ( V_31 , L_33 ) ;
goto V_157;
}
F_71 ( V_31 , L_34 , V_158 , V_2 -> V_3 ) ;
return 0 ;
V_157:
F_72 ( V_2 -> V_134 ) ;
V_156:
F_73 ( V_2 -> V_152 , V_2 ) ;
V_154:
V_153:
F_58 ( V_2 ) ;
V_151:
F_74 ( V_2 -> V_3 ) ;
V_148:
V_145:
F_75 ( V_100 ) ;
return V_59 ;
}
static int F_76 ( struct V_125 * V_126 )
{
struct V_1 * V_2 = F_77 ( V_126 ) ;
int V_59 = 0 ;
if ( ! V_2 )
return 0 ;
V_59 = F_58 ( V_2 ) ;
if ( V_59 )
return V_59 ;
F_4 ( V_2 ) ;
F_78 ( V_2 -> V_100 ) ;
F_72 ( V_2 -> V_134 ) ;
return 0 ;
}
static int F_79 ( struct V_127 * V_31 )
{
struct V_1 * V_2 = F_80 ( V_31 ) ;
int V_59 ;
V_59 = F_56 ( V_2 ) ;
if ( V_59 )
return V_59 ;
F_4 ( V_2 ) ;
return V_59 ;
}
static int F_81 ( struct V_127 * V_31 )
{
struct V_1 * V_2 = F_80 ( V_31 ) ;
int V_59 ;
F_1 ( V_2 ) ;
V_59 = F_55 ( V_2 ) ;
if ( V_59 )
F_31 ( V_2 -> V_31 , L_35 ) ;
return V_59 ;
}

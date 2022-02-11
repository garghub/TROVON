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
F_28 ( V_2 -> V_53 , & V_2 -> V_54 ) ;
F_29 ( & V_2 -> V_50 , V_49 ) ;
if ( ! V_2 -> V_55 )
F_10 ( V_11 ) ;
if ( V_39 -> V_56 )
V_39 -> V_56 ( V_39 -> V_57 ) ;
}
static T_4
F_30 ( int V_58 , void * V_59 )
{
struct V_1 * V_2 = V_59 ;
T_1 V_60 ;
F_23 ( V_2 -> V_31 , L_2 , V_61 ) ;
V_60 = F_13 ( & V_2 -> V_3 -> V_17 ) & ( V_62 | V_63 | V_64 | V_65 ) ;
if ( V_60 ) {
F_16 ( & V_2 -> V_3 -> V_17 , V_60 ) ;
F_3 () ;
F_4 ( V_2 ) ;
F_31 ( V_2 -> V_31 , L_3 ,
V_60 & V_62 ? L_4 : L_5 ,
V_60 & V_63 ? L_6 : L_5 ,
V_60 & V_64 ? L_7 : L_5 ,
V_60 & V_65 ? L_8 : L_5 ) ;
}
return V_66 ;
}
static void
F_32 ( unsigned long V_67 )
{
struct V_1 * V_2 = ( void * ) V_67 ;
struct V_38 * V_68 = NULL ;
struct V_41 * V_69 = NULL ;
struct V_41 * V_70 = NULL ;
struct V_10 * V_11 = NULL ;
unsigned int V_71 ;
T_2 V_72 = 1 ;
T_2 V_73 ;
T_5 V_74 = 0 ;
V_68 = V_2 -> V_40 ;
V_69 = V_2 -> V_43 ;
V_11 = V_2 -> V_26 ;
if ( V_69 -> V_7 )
V_73 = F_6 ( V_69 -> V_7 ) ;
else
V_73 = V_11 -> V_34 ;
F_16 ( & V_2 -> V_3 -> V_33 , V_73 ) ;
F_3 () ;
if ( V_2 -> V_51 == V_75 ) {
F_23 ( V_2 -> V_31 , L_9 ) ;
V_68 -> V_60 = - V_76 ;
F_26 ( V_2 ) ;
return;
}
if ( V_2 -> V_51 == V_48 ) {
F_23 ( V_2 -> V_31 , L_10 ) ;
V_68 -> V_60 = 0 ;
F_26 ( V_2 ) ;
return;
}
if ( V_2 -> V_51 == V_47 ) {
F_23 ( V_2 -> V_31 , L_11 ) ;
V_70 = F_25 ( V_69 -> V_44 . V_77 ,
struct V_41 , V_44 ) ;
if ( V_70 -> V_78 )
F_11 ( V_70 -> V_78 ) ;
}
if ( V_69 -> V_79 == 0 ) {
V_2 -> V_51 = F_24 ( V_2 ) ;
F_33 ( & V_2 -> V_80 ) ;
}
if ( V_69 -> V_81 != NULL ) {
V_2 -> V_20 = ( void * ) V_69 -> V_81 ;
V_2 -> V_21 = V_2 -> V_20 + V_69 -> V_79 ;
F_23 ( V_2 -> V_31 , L_12 ,
V_69 -> V_81 , V_2 -> V_21 ) ;
} else
V_2 -> V_20 = NULL ;
if ( V_69 -> V_82 != NULL ) {
V_74 = V_69 -> V_81 != NULL ;
V_2 -> V_28 = V_69 -> V_82 ;
V_2 -> V_29 = V_2 -> V_28 + V_69 -> V_79 ;
F_23 ( V_2 -> V_31 , L_13 ,
V_69 -> V_82 , V_2 -> V_29 ) ;
} else
V_2 -> V_28 = NULL ;
V_2 -> V_55 = V_69 -> V_55 ;
V_71 = V_69 -> V_71 ? :
V_68 -> V_83 -> V_71 ? : 8 ;
if ( V_71 % 16 == 0 )
V_2 -> V_84 = & V_85 ;
else
V_2 -> V_84 = & V_86 ;
F_16 ( & V_2 -> V_3 -> V_87 , V_71 - 1 ) ;
F_16 ( & V_2 -> V_3 -> V_88 , V_71 - 1 ) ;
F_16 ( & V_2 -> V_3 -> V_89 , V_71 - 1 ) ;
V_2 -> V_51 = V_47 ;
if ( V_2 -> V_55 )
F_8 ( V_11 ) ;
F_23 ( V_2 -> V_31 ,
L_14 ,
V_71 , V_69 -> V_79 ) ;
F_23 ( V_2 -> V_31 , L_15 ) ;
F_1 ( V_2 ) ;
if ( V_74 ) {
F_34 ( ( V_2 -> V_21 - V_2 -> V_20 ) !=
( V_2 -> V_29 - V_2 -> V_28 ) ) ;
V_2 -> V_84 -> V_90 ( V_2 ) ;
if ( V_2 -> V_20 != V_2 -> V_21 )
V_72 = 0 ;
} else if ( V_2 -> V_20 != NULL ) {
V_2 -> V_84 -> V_91 ( V_2 ) ;
if ( V_2 -> V_20 != V_2 -> V_21 )
V_72 = 0 ;
} else if ( V_2 -> V_28 != NULL ) {
V_2 -> V_84 -> V_92 ( V_2 ) ;
if ( V_2 -> V_28 != V_2 -> V_29 )
V_72 = 0 ;
}
F_4 ( V_2 ) ;
if ( ! V_72 ) {
F_23 ( V_2 -> V_31 , L_16 ) ;
V_2 -> V_51 = V_75 ;
} else {
V_68 -> V_93 += V_69 -> V_79 ;
V_2 -> V_51 = F_24 ( V_2 ) ;
if ( V_2 -> V_55 )
F_10 ( V_11 ) ;
}
F_33 ( & V_2 -> V_80 ) ;
}
static void
F_35 ( struct V_94 * V_95 )
{
struct V_1 * V_2 ;
unsigned long V_49 ;
struct V_38 * V_96 ;
V_2 = F_36 ( V_95 , struct V_1 , V_54 ) ;
F_27 ( & V_2 -> V_50 , V_49 ) ;
if ( F_37 ( & V_2 -> V_97 ) || ! V_2 -> V_98 ) {
V_2 -> V_99 = 0 ;
F_29 ( & V_2 -> V_50 , V_49 ) ;
return;
}
if ( V_2 -> V_40 ) {
F_29 ( & V_2 -> V_50 , V_49 ) ;
return;
}
V_96 = F_25 ( V_2 -> V_97 . V_45 ,
struct V_38 , V_97 ) ;
V_2 -> V_40 = V_96 ;
V_2 -> V_26 = F_38 ( V_2 -> V_40 -> V_83 ) ;
F_39 ( & V_2 -> V_40 -> V_97 ) ;
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
V_2 -> V_43 -> V_79 ) ;
F_33 ( & V_2 -> V_80 ) ;
V_2 -> V_99 = 1 ;
F_29 ( & V_2 -> V_50 , V_49 ) ;
}
static int
F_40 ( struct V_100 * V_83 , struct V_38 * V_39 )
{
struct V_1 * V_2 = F_41 ( V_83 -> V_101 ) ;
unsigned long V_49 ;
F_27 ( & V_2 -> V_50 , V_49 ) ;
if ( ! V_2 -> V_98 ) {
F_29 ( & V_2 -> V_50 , V_49 ) ;
return - V_102 ;
}
V_39 -> V_93 = 0 ;
V_39 -> V_60 = - V_103 ;
V_39 -> V_51 = V_52 ;
F_23 ( & V_83 -> V_31 , L_20 ) ;
F_42 ( & V_39 -> V_97 , & V_2 -> V_97 ) ;
if ( V_2 -> V_98 && ! V_2 -> V_99 )
F_28 ( V_2 -> V_53 , & V_2 -> V_54 ) ;
F_29 ( & V_2 -> V_50 , V_49 ) ;
return 0 ;
}
static int
F_43 ( struct V_100 * V_83 )
{
struct V_10 * V_11 , * V_104 = NULL ;
int V_105 ;
V_11 = F_38 ( V_83 ) ;
if ( V_11 == NULL ) {
struct V_106 * V_107 ;
V_11 = V_104 = F_44 ( sizeof( * V_11 ) , V_108 ) ;
if ( ! V_11 )
return - V_109 ;
V_107 = V_83 -> V_110 ;
if ( V_107 ) {
if ( V_107 -> V_32 || V_107 -> V_111 ) {
V_105 = - V_112 ;
F_31 ( & V_83 -> V_31 , L_21 ) ;
goto error;
}
V_11 -> V_13 = V_107 -> V_13 ;
V_11 -> V_27 = V_107 -> V_27 ;
}
}
if ( V_83 -> V_71 % 8 ) {
F_31 ( & V_83 -> V_31 , L_22 ,
V_83 -> V_71 ) ;
V_105 = - V_112 ;
goto error;
}
if ( V_83 -> V_113 & V_114 )
V_11 -> V_32 &= ~ V_115 ;
else
V_11 -> V_32 |= V_115 ;
if ( V_83 -> V_113 & V_116 )
V_11 -> V_32 |= V_117 ;
else
V_11 -> V_32 &= ~ V_117 ;
V_11 -> V_32 |= V_35 | V_36 | V_118 | V_119 | V_120 ;
V_11 -> V_34 = F_6 ( V_83 -> V_121 ) ;
V_11 -> V_12 = V_83 -> V_122 ;
V_105 = F_45 ( V_11 -> V_12 , V_83 -> V_123 ) ;
if ( V_105 )
goto error;
F_23 ( & V_83 -> V_31 , L_23 ,
V_83 -> V_123 , V_83 -> V_71 ) ;
F_23 ( & V_83 -> V_31 , L_24 ,
V_11 -> V_32 , V_83 -> V_122 ) ;
F_46 ( V_83 , V_11 ) ;
F_10 ( V_11 ) ;
return V_105 ;
error:
F_47 ( V_104 ) ;
return V_105 ;
}
static void
F_48 ( struct V_100 * V_83 )
{
struct V_10 * V_11 = F_38 ( V_83 ) ;
if ( ! V_11 )
return;
F_49 ( V_11 -> V_12 ) ;
F_47 ( V_11 ) ;
}
static int
F_50 ( struct V_1 * V_2 )
{
F_51 ( & V_2 -> V_97 ) ;
F_52 ( & V_2 -> V_50 ) ;
V_2 -> V_98 = false ;
V_2 -> V_99 = 0 ;
F_53 ( & V_2 -> V_80 ,
F_32 , ( unsigned long ) V_2 ) ;
F_54 ( & V_2 -> V_54 , F_35 ) ;
V_2 -> V_53 =
F_55 ( F_56 ( V_2 -> V_101 -> V_31 . V_124 ) ) ;
if ( V_2 -> V_53 == NULL )
return - V_125 ;
return 0 ;
}
static int
F_57 ( struct V_1 * V_2 )
{
unsigned long V_49 ;
F_27 ( & V_2 -> V_50 , V_49 ) ;
if ( V_2 -> V_98 || V_2 -> V_99 ) {
F_29 ( & V_2 -> V_50 , V_49 ) ;
return - V_125 ;
}
V_2 -> V_98 = true ;
V_2 -> V_40 = NULL ;
V_2 -> V_43 = NULL ;
V_2 -> V_26 = NULL ;
F_29 ( & V_2 -> V_50 , V_49 ) ;
F_28 ( V_2 -> V_53 , & V_2 -> V_54 ) ;
return 0 ;
}
static inline int
F_58 ( struct V_1 * V_2 )
{
unsigned long V_49 ;
unsigned V_126 = 500 ;
int V_60 = 0 ;
F_27 ( & V_2 -> V_50 , V_49 ) ;
V_2 -> V_98 = false ;
while ( ! F_37 ( & V_2 -> V_97 ) && V_2 -> V_99 && V_126 -- ) {
F_29 ( & V_2 -> V_50 , V_49 ) ;
F_59 ( 10 ) ;
F_27 ( & V_2 -> V_50 , V_49 ) ;
}
if ( ! F_37 ( & V_2 -> V_97 ) || V_2 -> V_99 )
V_60 = - V_125 ;
F_29 ( & V_2 -> V_50 , V_49 ) ;
return V_60 ;
}
static inline int
F_60 ( struct V_1 * V_2 )
{
int V_60 ;
V_60 = F_58 ( V_2 ) ;
if ( V_60 )
return V_60 ;
F_61 ( V_2 -> V_53 ) ;
return 0 ;
}
static int T_6
F_62 ( struct V_127 * V_128 )
{
struct V_129 * V_31 = & V_128 -> V_31 ;
struct V_130 * V_131 ;
struct V_132 * V_101 ;
struct V_133 * V_134 , * V_135 ;
struct V_1 * V_2 ;
int V_60 ;
V_131 = V_31 -> V_136 ;
V_101 = F_63 ( V_31 , sizeof( * V_101 ) + 16 ) ;
if ( ! V_101 ) {
F_31 ( V_31 , L_25 ) ;
return - V_109 ;
}
V_2 = F_41 ( V_101 ) ;
V_2 -> V_101 = V_101 ;
V_2 -> V_31 = V_31 ;
V_2 -> V_137 = V_131 -> V_137 ;
V_101 -> V_138 = V_139 | V_114 | V_116 ;
V_101 -> V_140 = V_128 -> V_141 ;
V_101 -> V_142 = V_131 -> V_142 ;
V_101 -> V_143 = F_48 ;
V_101 -> V_144 = F_43 ;
V_101 -> V_69 = F_40 ;
V_134 = F_64 ( V_128 , V_145 , 0 ) ;
if ( V_134 == NULL ) {
F_31 ( V_31 , L_26 ) ;
V_60 = - V_146 ;
goto V_147;
}
V_2 -> V_3 = F_65 ( V_134 -> V_148 , F_66 ( V_134 ) ) ;
if ( V_2 -> V_3 == NULL ) {
F_31 ( V_31 , L_27 ) ;
V_60 = - V_149 ;
goto V_150;
}
V_135 = F_64 ( V_128 , V_151 , 0 ) ;
if ( ! V_135 ) {
F_31 ( V_31 , L_28 ) ;
V_60 = - V_152 ;
goto V_153;
}
V_2 -> V_154 = V_135 -> V_148 ;
V_60 = F_50 ( V_2 ) ;
if ( V_60 ) {
F_31 ( V_31 , L_29 ) ;
goto V_155;
}
V_60 = F_57 ( V_2 ) ;
if ( V_60 ) {
F_31 ( V_31 , L_30 ) ;
goto V_155;
}
V_60 = F_67 ( V_2 -> V_154 , F_30 ,
0 , L_31 , V_2 ) ;
if ( V_60 ) {
F_31 ( V_31 , L_32 ) ;
goto V_156;
}
V_60 = F_68 ( V_2 -> V_137 , V_157 ) ;
if ( V_60 ) {
F_31 ( V_31 , L_33 ) ;
goto V_158;
}
F_69 ( V_128 , V_2 ) ;
V_60 = F_70 ( V_101 ) ;
if ( V_60 ) {
F_31 ( V_31 , L_34 ) ;
goto V_159;
}
F_71 ( V_31 , L_35 , V_160 , V_2 -> V_3 ) ;
return 0 ;
V_159:
F_72 ( V_2 -> V_137 ) ;
V_158:
F_73 ( V_2 -> V_154 , V_2 ) ;
V_156:
V_155:
F_60 ( V_2 ) ;
V_153:
F_74 ( V_2 -> V_3 ) ;
V_150:
V_147:
F_75 ( V_101 ) ;
return V_60 ;
}
static int T_7
F_76 ( struct V_127 * V_128 )
{
struct V_1 * V_2 = F_77 ( V_128 ) ;
int V_60 = 0 ;
if ( ! V_2 )
return 0 ;
V_60 = F_60 ( V_2 ) ;
if ( V_60 )
return V_60 ;
F_4 ( V_2 ) ;
F_78 ( V_2 -> V_101 ) ;
F_72 ( V_2 -> V_137 ) ;
F_69 ( V_128 , NULL ) ;
return 0 ;
}
static int
F_79 ( struct V_127 * V_128 , T_8 V_51 )
{
struct V_1 * V_2 = F_77 ( V_128 ) ;
int V_60 ;
V_60 = F_58 ( V_2 ) ;
if ( V_60 )
return V_60 ;
F_4 ( V_2 ) ;
return V_60 ;
}
static int
F_80 ( struct V_127 * V_128 )
{
struct V_1 * V_2 = F_77 ( V_128 ) ;
int V_60 ;
F_1 ( V_2 ) ;
V_60 = F_57 ( V_2 ) ;
if ( V_60 )
F_31 ( V_2 -> V_31 , L_36 ) ;
return V_60 ;
}

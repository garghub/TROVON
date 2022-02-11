static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 , V_7 = F_3 ( V_3 , sizeof( T_1 ) ) ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ )
F_4 ( V_5 , V_8 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
unsigned char * V_9 , T_1 V_10 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_6 , V_11 = V_10 & ( sizeof( T_1 ) - 1 ) ;
T_1 * V_12 = ( T_1 * ) V_9 , V_7 = V_10 / sizeof( T_1 ) ;
bool V_13 = F_6 ( ( unsigned long ) V_9 , sizeof( T_1 ) ) ;
if ( V_13 )
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ , V_12 ++ )
* V_12 = F_4 ( V_5 , V_8 ) ;
else {
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ , V_12 ++ ) {
T_1 V_14 = F_4 ( V_5 , V_8 ) ;
F_7 ( V_14 , V_12 ) ;
}
}
if ( V_11 ) {
T_1 V_14 = F_4 ( V_5 , V_8 ) ;
memcpy ( ( V_15 * ) V_12 , & V_14 , V_11 ) ;
}
}
static T_1 F_8 ( struct V_1 * V_2 )
{
T_1 V_3 , V_16 = 0 ;
T_1 V_17 = 0 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_18 * V_19 ;
struct V_20 V_21 ;
V_21 . V_22 = F_4 ( V_5 , V_23 ) ;
V_3 = V_21 . V_24 ;
if ( ! V_21 . V_25 )
return V_17 ;
V_17 ++ ;
if ( V_21 . V_26 ) {
V_2 -> V_27 . V_28 ++ ;
V_16 = 1 ;
}
if ( V_21 . V_29 ) {
V_2 -> V_27 . V_30 ++ ;
V_2 -> V_27 . V_31 ++ ;
V_16 = 1 ;
}
if ( F_9 ( V_3 < V_32 ) ) {
V_2 -> V_27 . V_33 ++ ;
V_2 -> V_27 . V_31 ++ ;
V_16 = 1 ;
}
if ( V_16 )
goto V_34;
V_19 = F_10 ( V_2 , V_3 ) ;
if ( F_9 ( ! V_19 ) ) {
V_2 -> V_27 . V_28 ++ ;
V_2 -> V_27 . V_31 ++ ;
goto V_34;
}
F_5 ( V_2 , V_19 -> V_35 , V_3 ) ;
F_11 ( V_19 , V_3 ) ;
V_19 -> V_36 = F_12 ( V_19 , V_2 ) ;
V_19 -> V_37 = V_38 ;
V_2 -> V_27 . V_39 ++ ;
V_2 -> V_27 . V_40 += V_3 ;
F_13 ( V_19 ) ;
goto V_41;
V_34:
F_1 ( V_2 , V_3 ) ;
V_41:
F_14 ( V_5 , V_23 , 0 ) ;
return V_17 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_42 V_43 ;
V_43 . V_22 = F_4 ( V_5 , V_44 ) ;
if ( ! V_5 -> V_45 || V_43 . V_46 )
return;
F_14 ( V_5 , V_44 , 0 ) ;
if ( F_9 ( V_43 . V_47 ) ) {
V_2 -> V_27 . V_48 ++ ;
} else {
V_2 -> V_27 . V_49 ++ ;
V_2 -> V_27 . V_50 += V_43 . V_51 ;
}
F_16 ( V_5 -> V_52 ) ;
V_5 -> V_45 = false ;
if ( F_17 ( V_2 ) )
F_18 ( V_2 ) ;
}
static int F_19 ( struct V_53 * V_54 , int V_55 )
{
struct V_1 * V_2 = V_54 -> V_56 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_17 ;
F_15 ( V_2 ) ;
V_17 = F_8 ( V_2 ) ;
if ( V_17 < V_55 ) {
struct V_57 V_58 ;
F_20 ( V_54 ) ;
V_58 . V_59 = V_60 ;
V_58 . V_61 = V_60 ;
F_14 ( V_5 , V_62 ,
V_58 . V_22 ) ;
}
return V_17 ;
}
static T_3 F_21 ( T_2 V_63 , void * V_64 )
{
struct V_1 * V_2 = V_64 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_20 V_21 ;
struct V_42 V_43 ;
V_21 . V_22 = F_4 ( V_5 , V_23 ) ;
V_43 . V_22 = F_4 ( V_5 , V_44 ) ;
if ( ( ! V_43 . V_46 && V_5 -> V_45 ) || V_21 . V_25 )
if ( F_22 ( F_23 ( & V_5 -> V_54 ) ) ) {
F_14 ( V_5 , V_62 , 0 ) ;
F_24 ( & V_5 -> V_54 ) ;
}
return V_65 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_66 V_67 ;
struct V_68 * V_69 = & V_5 -> V_69 ;
V_67 . V_70 = V_2 -> V_71 [ 0 ] ;
V_67 . V_72 = V_2 -> V_71 [ 1 ] ;
V_67 . V_73 = V_2 -> V_71 [ 2 ] ;
V_67 . V_74 = V_2 -> V_71 [ 3 ] ;
V_69 -> V_75 = V_2 -> V_71 [ 4 ] ;
V_69 -> V_76 = V_2 -> V_71 [ 5 ] ;
F_14 ( V_5 , V_77 ,
V_67 . V_22 ) ;
F_14 ( V_5 , V_78 ,
V_69 -> V_22 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_79 V_80 ;
struct V_81 V_82 ;
V_80 . V_22 = 0 ;
V_82 . V_22 = 0 ;
V_80 . V_83 = V_60 ;
F_14 ( V_5 , V_84 , V_80 . V_22 ) ;
F_27 ( 10 , 20 ) ;
V_80 . V_22 = 0 ;
F_14 ( V_5 , V_84 , V_80 . V_22 ) ;
V_82 . V_85 = V_60 ;
V_82 . V_86 = V_60 ;
F_14 ( V_5 , V_87 ,
V_82 . V_22 ) ;
F_27 ( 10 , 20 ) ;
V_82 . V_22 = 0 ;
F_14 ( V_5 , V_87 ,
V_82 . V_22 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_88 V_89 ;
struct V_57 V_58 ;
struct V_68 * V_69 = & V_5 -> V_69 ;
struct V_90 * V_91 = & V_5 -> V_91 ;
T_2 V_92 ;
V_89 . V_22 = 0 ;
V_58 . V_22 = 0 ;
V_69 -> V_93 = V_94 ;
V_69 -> V_95 = V_60 ;
V_69 -> V_96 = V_60 ;
F_14 ( V_5 , V_78 ,
V_69 -> V_22 ) ;
V_92 = V_97 + V_2 -> V_98 + V_99 ;
if ( V_92 <= V_100 )
V_91 -> V_101 = V_92 ;
V_58 . V_59 = V_60 ;
V_58 . V_61 = V_60 ;
F_14 ( V_5 , V_62 ,
V_58 . V_22 ) ;
F_25 ( V_2 ) ;
V_89 . V_102 = V_60 ;
V_89 . V_103 = V_60 ;
V_89 . V_104 = V_60 ;
V_89 . V_105 = V_106 ;
V_89 . V_107 = V_108 ;
V_89 . V_109 = V_60 ;
V_89 . V_110 = V_111 ;
V_89 . V_112 = V_60 ;
V_89 . V_113 = V_60 ;
V_89 . V_114 = V_115 ;
V_91 -> V_116 = V_60 ;
V_89 . V_117 = V_60 ;
V_89 . V_118 = V_60 ;
F_14 ( V_5 , V_119 ,
V_91 -> V_22 ) ;
F_14 ( V_5 , V_120 ,
V_89 . V_22 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_14 ( V_5 , V_62 , 0 ) ;
F_14 ( V_5 , V_120 , 0 ) ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_42 V_43 ;
short V_10 = V_19 -> V_7 ;
T_1 V_6 , V_7 = F_3 ( V_10 , sizeof( T_1 ) ) ;
T_1 * V_121 = ( void * ) V_19 -> V_35 ;
bool V_122 = F_6 ( ( unsigned long ) V_121 , sizeof( T_1 ) ) ;
V_43 . V_22 = 0 ;
if ( V_122 )
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ , V_121 ++ )
F_14 ( V_5 , V_123 , * V_121 ) ;
else
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ , V_121 ++ )
F_14 ( V_5 , V_123 ,
F_31 ( V_121 ) ) ;
V_43 . V_51 = V_10 ;
V_5 -> V_45 = true ;
V_43 . V_46 = V_60 ;
F_14 ( V_5 , V_44 , V_43 . V_22 ) ;
}
static T_2 F_32 ( struct V_1 * V_2 , void * V_124 )
{
struct V_125 * V_126 = V_124 ;
T_2 V_127 ;
if ( F_33 ( V_2 ) )
return - V_128 ;
V_127 = F_34 ( V_2 , V_124 ) ;
if ( ! V_127 ) {
F_35 ( V_2 -> V_71 , V_126 -> V_129 ) ;
F_25 ( V_2 ) ;
}
return V_127 ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_68 V_69 ;
V_69 . V_22 = V_5 -> V_69 . V_22 ;
if ( V_2 -> V_130 & V_131 ) {
V_69 . V_95 = V_132 ;
V_69 . V_96 = V_132 ;
} else {
V_69 . V_95 = V_60 ;
V_69 . V_96 = V_60 ;
}
F_14 ( V_5 , V_78 , V_69 . V_22 ) ;
}
static T_2 F_37 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_16 ;
V_5 -> V_45 = false ;
V_5 -> V_69 . V_22 = 0 ;
V_5 -> V_91 . V_22 = 0 ;
V_5 -> V_91 . V_133 = V_134 ;
V_5 -> V_91 . V_101 = V_135 ;
F_29 ( V_2 ) ;
V_16 = F_38 ( V_5 -> V_63 , F_21 ,
0 , L_1 , V_2 ) ;
if ( V_16 )
return V_16 ;
F_39 ( & V_5 -> V_54 ) ;
F_26 ( V_2 ) ;
F_28 ( V_2 ) ;
F_40 ( V_2 ) ;
return 0 ;
}
static T_2 F_41 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_42 ( & V_5 -> V_54 ) ;
F_43 ( V_2 ) ;
F_29 ( V_2 ) ;
F_44 ( V_5 -> V_63 , V_2 ) ;
return 0 ;
}
static T_4 F_45 ( struct V_18 * V_19 ,
struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_43 ( V_2 ) ;
V_5 -> V_52 = V_19 ;
F_30 ( V_2 , V_19 ) ;
return V_136 ;
}
static void F_46 ( struct V_1 * V_2 )
{
F_47 ( V_2 -> V_63 ) ;
F_21 ( V_2 -> V_63 , V_2 ) ;
F_48 ( V_2 -> V_63 ) ;
}
static T_2 F_49 ( struct V_137 * V_138 )
{
struct V_139 * V_56 = & V_138 -> V_56 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
T_2 V_16 = 0 ;
const char * V_140 ;
struct V_141 * V_142 ;
if ( ! V_56 -> V_143 )
return - V_144 ;
V_2 = F_50 ( sizeof( struct V_4 ) ) ;
if ( ! V_2 )
return - V_145 ;
F_51 ( V_138 , V_2 ) ;
F_52 ( V_2 , V_56 ) ;
V_5 = F_2 ( V_2 ) ;
V_2 -> V_146 = & V_147 ;
V_2 -> V_148 = ( 400 * V_149 / 1000 ) ;
V_2 -> V_130 &= ~ V_150 ;
V_142 = F_53 ( V_138 , V_151 , 0 ) ;
V_5 -> V_152 = F_54 ( V_56 , V_142 ) ;
if ( F_55 ( V_5 -> V_152 ) ) {
V_16 = F_56 ( V_5 -> V_152 ) ;
goto V_153;
}
F_57 ( V_56 , L_2 , V_5 -> V_152 ) ;
V_140 = F_58 ( V_56 -> V_143 ) ;
if ( V_140 )
F_35 ( V_2 -> V_71 , V_140 ) ;
else
F_59 ( V_2 ) ;
V_5 -> V_63 = F_60 ( V_138 , 0 ) ;
if ( ! V_5 -> V_63 ) {
F_61 ( V_56 , L_3 ) ;
V_16 = - V_144 ;
goto V_153;
}
F_62 ( V_2 , & V_5 -> V_54 , F_19 ,
V_154 ) ;
V_16 = F_63 ( V_2 ) ;
if ( V_16 ) {
F_61 ( V_56 , L_4 ,
V_2 -> V_155 , ( T_2 ) V_16 ) ;
goto V_156;
}
F_64 ( V_56 , L_5 , V_5 -> V_63 ) ;
return 0 ;
V_156:
F_65 ( & V_5 -> V_54 ) ;
V_153:
if ( V_16 )
F_66 ( V_2 ) ;
return V_16 ;
}
static T_2 F_67 ( struct V_137 * V_138 )
{
struct V_1 * V_2 = F_68 ( V_138 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_69 ( V_2 ) ;
F_66 ( V_2 ) ;
F_65 ( & V_5 -> V_54 ) ;
return 0 ;
}

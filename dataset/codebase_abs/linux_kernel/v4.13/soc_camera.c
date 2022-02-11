int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 ;
bool V_8 ;
if ( V_6 && ( ! V_4 -> V_9 ||
! F_2 ( 0 , & V_4 -> V_10 ) ) ) {
V_7 = F_3 ( V_6 ) ;
if ( V_7 < 0 ) {
F_4 ( V_2 , L_1 , V_7 ) ;
return V_7 ;
}
V_8 = true ;
} else {
V_8 = false ;
}
V_7 = F_5 ( V_4 -> V_11 . V_12 ,
V_4 -> V_11 . V_13 ) ;
if ( V_7 < 0 ) {
F_4 ( V_2 , L_2 ) ;
goto V_14;
}
if ( V_4 -> V_15 ) {
V_7 = V_4 -> V_15 ( V_2 , 1 ) ;
if ( V_7 < 0 ) {
F_4 ( V_2 ,
L_3 ) ;
goto V_16;
}
}
return 0 ;
V_16:
F_6 ( V_4 -> V_11 . V_12 ,
V_4 -> V_11 . V_13 ) ;
V_14:
if ( V_8 )
F_7 ( V_6 ) ;
return V_7 ;
}
int F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 = 0 ;
int V_17 ;
if ( V_4 -> V_15 ) {
V_17 = V_4 -> V_15 ( V_2 , 0 ) ;
if ( V_17 < 0 ) {
F_4 ( V_2 ,
L_4 ) ;
V_7 = V_17 ;
}
}
V_17 = F_6 ( V_4 -> V_11 . V_12 ,
V_4 -> V_11 . V_13 ) ;
if ( V_17 < 0 ) {
F_4 ( V_2 , L_5 ) ;
V_7 = V_7 ? : V_17 ;
}
if ( V_6 && ( ! V_4 -> V_9 || F_9 ( 0 , & V_4 -> V_10 ) ) )
F_7 ( V_6 ) ;
return V_7 ;
}
int F_10 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return F_11 ( V_2 , V_4 -> V_11 . V_12 ,
V_4 -> V_11 . V_13 ) ;
}
static int F_12 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
int V_7 ;
V_7 = F_14 ( V_21 , V_22 , V_23 , 1 ) ;
if ( V_7 < 0 && V_7 != - V_24 && V_7 != - V_25 )
return V_7 ;
return 0 ;
}
static int F_15 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
int V_7 ;
V_7 = F_14 ( V_21 , V_22 , V_23 , 0 ) ;
if ( V_7 < 0 && V_7 != - V_24 && V_7 != - V_25 )
return V_7 ;
return 0 ;
}
static int F_16 ( struct V_26 * V_27 )
{
int V_7 ;
if ( ! V_27 -> V_28 -> V_29 )
return 0 ;
F_17 ( & V_27 -> V_30 ) ;
V_7 = V_27 -> V_28 -> V_29 ( V_27 ) ;
F_18 ( & V_27 -> V_30 ) ;
return V_7 ;
}
static void F_19 ( struct V_26 * V_27 )
{
if ( ! V_27 -> V_28 -> V_31 )
return;
F_17 ( & V_27 -> V_30 ) ;
V_27 -> V_28 -> V_31 ( V_27 ) ;
F_18 ( & V_27 -> V_30 ) ;
}
const struct V_32 * F_20 (
struct V_18 * V_19 , unsigned int V_33 )
{
unsigned int V_34 ;
for ( V_34 = 0 ; V_34 < V_19 -> V_35 ; V_34 ++ )
if ( V_19 -> V_36 [ V_34 ] . V_37 -> V_33 == V_33 )
return V_19 -> V_36 + V_34 ;
return NULL ;
}
unsigned long F_21 ( struct V_3 * V_4 ,
const struct V_38 * V_39 )
{
unsigned long V_40 , V_41 = V_39 -> V_41 ;
if ( V_4 -> V_41 & V_42 ) {
V_40 = V_41 & ( V_43 | V_44 ) ;
if ( V_40 == V_43 || V_40 == V_44 )
V_41 ^= V_43 | V_44 ;
}
if ( V_4 -> V_41 & V_45 ) {
V_40 = V_41 & ( V_46 | V_47 ) ;
if ( V_40 == V_46 || V_40 == V_47 )
V_41 ^= V_46 | V_47 ;
}
if ( V_4 -> V_41 & V_48 ) {
V_40 = V_41 & ( V_49 | V_50 ) ;
if ( V_40 == V_49 || V_40 == V_50 )
V_41 ^= V_49 | V_50 ;
}
return V_41 ;
}
static int F_22 ( struct V_18 * V_19 ,
struct V_51 * V_40 )
{
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
const struct V_32 * V_53 ;
struct V_54 * V_55 = & V_40 -> V_56 . V_55 ;
int V_7 ;
F_24 ( V_19 -> V_57 , L_6 ,
F_25 ( V_55 -> V_58 ) , V_55 -> V_59 , V_55 -> V_60 ) ;
if ( V_55 -> V_58 != V_61 &&
! ( V_27 -> V_62 & V_63 ) ) {
V_55 -> V_64 = 0 ;
V_55 -> V_65 = 0 ;
}
V_7 = V_27 -> V_28 -> V_66 ( V_19 , V_40 ) ;
if ( V_7 < 0 )
return V_7 ;
V_53 = F_20 ( V_19 , V_55 -> V_58 ) ;
if ( ! V_53 )
return - V_67 ;
V_7 = F_26 ( V_55 -> V_59 , V_53 -> V_37 ) ;
if ( V_7 < 0 )
return V_7 ;
V_55 -> V_64 = F_27 ( V_68 , V_55 -> V_64 , V_7 ) ;
V_7 = F_28 ( V_53 -> V_37 , V_55 -> V_64 ,
V_55 -> V_60 ) ;
if ( V_7 < 0 )
return V_7 ;
V_55 -> V_65 = F_27 ( V_68 , V_55 -> V_65 , V_7 ) ;
return 0 ;
}
static int F_29 ( struct V_69 * V_69 , void * V_70 ,
struct V_51 * V_40 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
F_30 ( V_70 != V_69 -> V_71 ) ;
if ( V_40 -> type != V_72 )
return - V_67 ;
return F_22 ( V_19 , V_40 ) ;
}
static int F_31 ( struct V_69 * V_69 , void * V_70 ,
struct V_73 * V_74 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
if ( V_74 -> V_75 != 0 )
return - V_67 ;
V_74 -> type = V_76 ;
V_74 -> V_77 = V_19 -> V_78 -> V_79 ;
strcpy ( V_74 -> V_80 , L_7 ) ;
return 0 ;
}
static int F_32 ( struct V_69 * V_69 , void * V_70 , unsigned int * V_34 )
{
* V_34 = 0 ;
return 0 ;
}
static int F_33 ( struct V_69 * V_69 , void * V_70 , unsigned int V_34 )
{
if ( V_34 > 0 )
return - V_67 ;
return 0 ;
}
static int F_34 ( struct V_69 * V_69 , void * V_70 , T_1 V_81 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_82 , V_83 , V_81 ) ;
}
static int F_35 ( struct V_69 * V_69 , void * V_70 , T_1 * V_81 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_82 , V_84 , V_81 ) ;
}
static int F_36 ( struct V_69 * V_69 , void * V_85 ,
struct V_86 * V_87 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
return V_27 -> V_28 -> V_88 ( V_19 , V_87 ) ;
}
static int F_37 ( struct V_69 * V_69 , void * V_70 ,
struct V_89 * V_90 )
{
int V_7 ;
struct V_18 * V_19 = V_69 -> V_71 ;
F_30 ( V_70 != V_69 -> V_71 ) ;
if ( V_19 -> V_91 && V_19 -> V_91 != V_69 )
return - V_92 ;
V_7 = F_38 ( & V_19 -> V_93 , V_90 ) ;
if ( ! V_7 )
V_19 -> V_91 = V_90 -> V_94 ? V_69 : NULL ;
return V_7 ;
}
static int F_39 ( struct V_69 * V_69 , void * V_70 ,
struct V_95 * V_90 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
F_30 ( V_70 != V_69 -> V_71 ) ;
return F_40 ( & V_19 -> V_93 , V_90 ) ;
}
static int F_41 ( struct V_69 * V_69 , void * V_70 ,
struct V_95 * V_90 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
F_30 ( V_70 != V_69 -> V_71 ) ;
if ( V_19 -> V_91 != V_69 )
return - V_92 ;
return F_42 ( & V_19 -> V_93 , V_90 ) ;
}
static int F_43 ( struct V_69 * V_69 , void * V_70 ,
struct V_95 * V_90 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
F_30 ( V_70 != V_69 -> V_71 ) ;
if ( V_19 -> V_91 != V_69 )
return - V_92 ;
return F_44 ( & V_19 -> V_93 , V_90 , V_69 -> V_96 & V_97 ) ;
}
static int F_45 ( struct V_69 * V_69 , void * V_70 ,
struct V_98 * V_99 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
int V_7 ;
if ( V_19 -> V_91 && V_19 -> V_91 != V_69 )
return - V_92 ;
V_7 = F_46 ( & V_19 -> V_93 , V_99 ) ;
if ( ! V_7 )
V_19 -> V_91 = V_69 ;
return V_7 ;
}
static int F_47 ( struct V_69 * V_69 , void * V_70 ,
struct V_95 * V_100 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
return F_48 ( & V_19 -> V_93 , V_100 ) ;
}
static int F_49 ( struct V_69 * V_69 , void * V_70 ,
struct V_101 * V_90 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
if ( V_19 -> V_91 && V_19 -> V_91 != V_69 )
return - V_92 ;
return F_50 ( & V_19 -> V_93 , V_90 ) ;
}
static int F_51 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
unsigned int V_34 , V_102 = 0 , V_103 = 0 ;
int V_7 ;
struct V_104 V_105 = {
. V_106 = V_107 ,
} ;
while ( ! F_14 ( V_21 , V_108 , V_109 , NULL , & V_105 ) ) {
V_103 ++ ;
V_105 . V_75 ++ ;
}
if ( ! V_27 -> V_28 -> V_110 )
V_102 = V_103 ;
else
for ( V_34 = 0 ; V_34 < V_103 ; V_34 ++ ) {
V_7 = V_27 -> V_28 -> V_110 ( V_19 , V_34 , NULL ) ;
if ( V_7 < 0 )
return V_7 ;
V_102 += V_7 ;
}
if ( ! V_102 )
return - V_111 ;
V_19 -> V_36 =
F_52 ( V_102 * sizeof( struct V_32 ) ) ;
if ( ! V_19 -> V_36 )
return - V_112 ;
F_24 ( V_19 -> V_57 , L_8 , V_102 ) ;
V_102 = 0 ;
for ( V_34 = 0 ; V_34 < V_103 ; V_34 ++ )
if ( ! V_27 -> V_28 -> V_110 ) {
V_105 . V_75 = V_34 ;
F_14 ( V_21 , V_108 , V_109 , NULL , & V_105 ) ;
V_19 -> V_36 [ V_102 ] . V_37 =
F_53 ( V_105 . V_105 ) ;
if ( V_19 -> V_36 [ V_102 ] . V_37 )
V_19 -> V_36 [ V_102 ++ ] . V_105 = V_105 . V_105 ;
} else {
V_7 = V_27 -> V_28 -> V_110 ( V_19 , V_34 ,
& V_19 -> V_36 [ V_102 ] ) ;
if ( V_7 < 0 )
goto V_113;
V_102 += V_7 ;
}
V_19 -> V_35 = V_102 ;
V_19 -> V_114 = & V_19 -> V_36 [ 0 ] ;
return 0 ;
V_113:
F_54 ( V_19 -> V_36 ) ;
return V_7 ;
}
static void F_55 ( struct V_18 * V_19 )
{
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
if ( V_27 -> V_28 -> V_115 )
V_27 -> V_28 -> V_115 ( V_19 ) ;
V_19 -> V_114 = NULL ;
V_19 -> V_35 = 0 ;
F_54 ( V_19 -> V_36 ) ;
V_19 -> V_36 = NULL ;
}
static int F_56 ( struct V_18 * V_19 ,
struct V_51 * V_40 )
{
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
struct V_54 * V_55 = & V_40 -> V_56 . V_55 ;
int V_7 ;
F_24 ( V_19 -> V_57 , L_9 ,
F_25 ( V_55 -> V_58 ) , V_55 -> V_59 , V_55 -> V_60 ) ;
V_7 = F_22 ( V_19 , V_40 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = V_27 -> V_28 -> V_116 ( V_19 , V_40 ) ;
if ( V_7 < 0 ) {
return V_7 ;
} else if ( ! V_19 -> V_114 ||
V_19 -> V_114 -> V_37 -> V_33 != V_55 -> V_58 ) {
F_4 ( V_19 -> V_57 ,
L_10 ) ;
return - V_67 ;
}
V_19 -> V_117 = V_55 -> V_59 ;
V_19 -> V_118 = V_55 -> V_60 ;
V_19 -> V_64 = V_55 -> V_64 ;
V_19 -> V_65 = V_55 -> V_65 ;
V_19 -> V_119 = V_55 -> V_119 ;
V_19 -> V_120 = V_55 -> V_120 ;
F_24 ( V_19 -> V_57 , L_11 ,
V_19 -> V_117 , V_19 -> V_118 ) ;
return V_27 -> V_28 -> V_121 ( V_19 ) ;
}
static int F_57 ( struct V_18 * V_19 )
{
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
int V_7 ;
if ( V_27 -> V_19 )
return - V_92 ;
if ( ! V_19 -> V_6 ) {
V_7 = F_16 ( V_27 ) ;
if ( V_7 < 0 )
return V_7 ;
}
if ( V_27 -> V_28 -> V_122 ) {
V_7 = V_27 -> V_28 -> V_122 ( V_19 ) ;
if ( V_7 < 0 )
goto V_123;
}
V_27 -> V_19 = V_19 ;
return 0 ;
V_123:
if ( ! V_19 -> V_6 )
F_19 ( V_27 ) ;
return V_7 ;
}
static void F_58 ( struct V_18 * V_19 )
{
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
if ( F_30 ( V_19 != V_27 -> V_19 ) )
return;
if ( V_27 -> V_28 -> remove )
V_27 -> V_28 -> remove ( V_19 ) ;
if ( ! V_19 -> V_6 )
F_19 ( V_27 ) ;
V_27 -> V_19 = NULL ;
}
static int F_59 ( struct V_69 * V_69 )
{
struct V_124 * V_78 = F_60 ( V_69 ) ;
struct V_18 * V_19 ;
struct V_26 * V_27 ;
int V_7 ;
if ( F_61 ( & V_125 ) )
return - V_126 ;
if ( ! V_78 || ! F_62 ( V_78 ) ) {
F_18 ( & V_125 ) ;
return - V_25 ;
}
V_19 = F_63 ( V_78 ) ;
V_27 = F_23 ( V_19 -> V_52 ) ;
V_7 = F_64 ( V_27 -> V_28 -> V_127 ) ? 0 : - V_25 ;
F_18 ( & V_125 ) ;
if ( V_7 < 0 ) {
F_4 ( V_19 -> V_57 , L_12 ) ;
return V_7 ;
}
if ( ! F_65 ( V_19 ) ) {
V_7 = - V_25 ;
goto V_128;
}
if ( F_61 ( & V_27 -> V_129 ) ) {
V_7 = - V_126 ;
goto V_130;
}
V_19 -> V_131 ++ ;
if ( V_19 -> V_131 == 1 ) {
struct V_132 * V_133 = F_66 ( V_19 ) ;
struct V_51 V_40 = {
. type = V_72 ,
. V_56 . V_55 = {
. V_59 = V_19 -> V_117 ,
. V_60 = V_19 -> V_118 ,
. V_120 = V_19 -> V_120 ,
. V_119 = V_19 -> V_119 ,
. V_58 =
V_19 -> V_114 -> V_37 -> V_33 ,
} ,
} ;
if ( V_133 -> V_134 . V_135 )
if ( V_19 -> V_136 )
V_133 -> V_134 . V_135 ( V_19 -> V_136 ) ;
V_7 = F_57 ( V_19 ) ;
if ( V_7 < 0 ) {
F_4 ( V_19 -> V_57 , L_13 , V_7 ) ;
goto V_137;
}
V_7 = F_12 ( V_19 ) ;
if ( V_7 < 0 )
goto V_138;
F_67 ( & V_19 -> V_78 -> V_2 ) ;
V_7 = F_68 ( & V_19 -> V_78 -> V_2 ) ;
if ( V_7 < 0 && V_7 != - V_139 )
goto V_140;
V_7 = F_56 ( V_19 , & V_40 ) ;
if ( V_7 < 0 )
goto V_141;
V_7 = V_27 -> V_28 -> V_142 ( & V_19 -> V_93 , V_19 ) ;
if ( V_7 < 0 )
goto V_143;
F_69 ( & V_19 -> V_144 ) ;
}
F_18 ( & V_27 -> V_129 ) ;
V_69 -> V_71 = V_19 ;
F_24 ( V_19 -> V_57 , L_14 ) ;
return 0 ;
V_143:
V_141:
F_70 ( & V_19 -> V_78 -> V_2 ) ;
V_140:
F_15 ( V_19 ) ;
V_138:
F_58 ( V_19 ) ;
V_137:
V_19 -> V_131 -- ;
F_18 ( & V_27 -> V_129 ) ;
V_130:
V_128:
F_71 ( V_27 -> V_28 -> V_127 ) ;
return V_7 ;
}
static int F_72 ( struct V_69 * V_69 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
F_17 ( & V_27 -> V_129 ) ;
if ( V_19 -> V_91 == V_69 ) {
if ( V_27 -> V_28 -> V_142 )
F_73 ( & V_19 -> V_93 ) ;
V_19 -> V_91 = NULL ;
}
V_19 -> V_131 -- ;
if ( ! V_19 -> V_131 ) {
F_74 ( & V_19 -> V_78 -> V_2 ) ;
F_70 ( & V_19 -> V_78 -> V_2 ) ;
F_15 ( V_19 ) ;
F_58 ( V_19 ) ;
}
F_18 ( & V_27 -> V_129 ) ;
F_71 ( V_27 -> V_28 -> V_127 ) ;
F_24 ( V_19 -> V_57 , L_15 ) ;
return 0 ;
}
static T_2 F_75 ( struct V_69 * V_69 , char T_3 * V_145 ,
T_4 V_94 , T_5 * V_146 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
F_24 ( V_19 -> V_57 , L_16 , V_145 ) ;
if ( V_27 -> V_28 -> V_142 && V_19 -> V_93 . V_147 & V_148 )
return F_76 ( & V_19 -> V_93 , V_145 , V_94 , V_146 ,
V_69 -> V_96 & V_97 ) ;
F_4 ( V_19 -> V_57 , L_17 ) ;
return - V_67 ;
}
static int F_77 ( struct V_69 * V_69 , struct V_149 * V_150 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
int V_17 ;
F_24 ( V_19 -> V_57 , L_18 , ( unsigned long ) V_150 ) ;
if ( V_19 -> V_91 != V_69 )
return - V_92 ;
if ( F_61 ( & V_27 -> V_129 ) )
return - V_126 ;
V_17 = F_78 ( & V_19 -> V_93 , V_150 ) ;
F_18 ( & V_27 -> V_129 ) ;
F_24 ( V_19 -> V_57 , L_19 ,
( unsigned long ) V_150 -> V_151 ,
( unsigned long ) V_150 -> V_152 - ( unsigned long ) V_150 -> V_151 ,
V_17 ) ;
return V_17 ;
}
static unsigned int F_79 ( struct V_69 * V_69 , T_6 * V_153 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
unsigned V_154 = V_155 ;
if ( V_19 -> V_91 != V_69 )
return V_155 ;
F_17 ( & V_27 -> V_129 ) ;
V_154 = V_27 -> V_28 -> V_156 ( V_69 , V_153 ) ;
F_18 ( & V_27 -> V_129 ) ;
return V_154 ;
}
static int F_80 ( struct V_69 * V_69 , void * V_70 ,
struct V_51 * V_40 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
int V_7 ;
F_30 ( V_70 != V_69 -> V_71 ) ;
if ( V_40 -> type != V_72 ) {
F_81 ( V_19 -> V_57 , L_20 , V_40 -> type ) ;
return - V_67 ;
}
if ( V_19 -> V_91 && V_19 -> V_91 != V_69 )
return - V_92 ;
if ( F_82 ( & V_19 -> V_93 ) ) {
F_4 ( V_19 -> V_57 , L_21 ) ;
return - V_92 ;
}
V_7 = F_56 ( V_19 , V_40 ) ;
if ( ! V_7 && ! V_19 -> V_91 )
V_19 -> V_91 = V_69 ;
return V_7 ;
}
static int F_83 ( struct V_69 * V_69 , void * V_70 ,
struct V_157 * V_40 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
const struct V_158 * V_159 ;
F_30 ( V_70 != V_69 -> V_71 ) ;
if ( V_40 -> V_75 >= V_19 -> V_35 )
return - V_67 ;
V_159 = V_19 -> V_36 [ V_40 -> V_75 ] . V_37 ;
if ( V_159 -> V_80 )
F_84 ( V_40 -> V_160 , V_159 -> V_80 , sizeof( V_40 -> V_160 ) ) ;
V_40 -> V_58 = V_159 -> V_33 ;
return 0 ;
}
static int F_85 ( struct V_69 * V_69 , void * V_70 ,
struct V_51 * V_40 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_54 * V_55 = & V_40 -> V_56 . V_55 ;
F_30 ( V_70 != V_69 -> V_71 ) ;
if ( V_40 -> type != V_72 )
return - V_67 ;
V_55 -> V_59 = V_19 -> V_117 ;
V_55 -> V_60 = V_19 -> V_118 ;
V_55 -> V_64 = V_19 -> V_64 ;
V_55 -> V_65 = V_19 -> V_65 ;
V_55 -> V_120 = V_19 -> V_120 ;
V_55 -> V_58 = V_19 -> V_114 -> V_37 -> V_33 ;
V_55 -> V_119 = V_19 -> V_119 ;
F_24 ( V_19 -> V_57 , L_22 ,
V_19 -> V_114 -> V_37 -> V_33 ) ;
return 0 ;
}
static int F_86 ( struct V_69 * V_69 , void * V_70 ,
struct V_161 * V_162 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
F_30 ( V_70 != V_69 -> V_71 ) ;
F_84 ( V_162 -> V_163 , V_27 -> V_164 , sizeof( V_162 -> V_163 ) ) ;
return V_27 -> V_28 -> V_165 ( V_27 , V_162 ) ;
}
static int F_87 ( struct V_69 * V_69 , void * V_70 ,
enum V_166 V_34 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_20 * V_21 = F_13 ( V_19 ) ;
int V_7 ;
F_30 ( V_70 != V_69 -> V_71 ) ;
if ( V_34 != V_72 )
return - V_67 ;
if ( V_19 -> V_91 != V_69 )
return - V_92 ;
V_7 = F_88 ( & V_19 -> V_93 , V_34 ) ;
if ( ! V_7 )
F_14 ( V_21 , V_82 , V_167 , 1 ) ;
return V_7 ;
}
static int F_89 ( struct V_69 * V_69 , void * V_70 ,
enum V_166 V_34 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_20 * V_21 = F_13 ( V_19 ) ;
int V_7 ;
F_30 ( V_70 != V_69 -> V_71 ) ;
if ( V_34 != V_72 )
return - V_67 ;
if ( V_19 -> V_91 != V_69 )
return - V_92 ;
V_7 = F_90 ( & V_19 -> V_93 , V_34 ) ;
F_14 ( V_21 , V_82 , V_167 , 0 ) ;
return V_7 ;
}
static int F_91 ( struct V_69 * V_69 , void * V_85 ,
struct V_168 * V_169 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
if ( V_169 -> type != V_72 )
return - V_67 ;
return V_27 -> V_28 -> V_170 ( V_19 , V_169 ) ;
}
static int F_92 ( struct V_69 * V_69 , void * V_85 ,
struct V_168 * V_169 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
int V_7 ;
if ( V_169 -> type != V_72 ||
( V_169 -> V_171 != V_172 &&
V_169 -> V_171 != V_173 ) )
return - V_67 ;
if ( V_169 -> V_171 == V_172 ) {
if ( F_82 ( & V_19 -> V_93 ) &&
( V_19 -> V_117 != V_169 -> V_174 . V_59 ||
V_19 -> V_118 != V_169 -> V_174 . V_60 ) )
return - V_92 ;
if ( V_19 -> V_91 && V_19 -> V_91 != V_69 )
return - V_92 ;
}
if ( V_169 -> V_171 == V_173 &&
F_82 ( & V_19 -> V_93 ) &&
V_27 -> V_28 -> V_175 )
V_7 = V_27 -> V_28 -> V_175 ( V_19 , V_169 ) ;
else
V_7 = V_27 -> V_28 -> V_176 ( V_19 , V_169 ) ;
if ( ! V_7 &&
V_169 -> V_171 == V_172 ) {
V_19 -> V_117 = V_169 -> V_174 . V_59 ;
V_19 -> V_118 = V_169 -> V_174 . V_60 ;
if ( ! V_19 -> V_91 )
V_19 -> V_91 = V_69 ;
}
return V_7 ;
}
static int F_93 ( struct V_69 * V_69 , void * V_85 ,
struct V_177 * V_81 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
if ( V_27 -> V_28 -> V_178 )
return V_27 -> V_28 -> V_178 ( V_19 , V_81 ) ;
return - V_24 ;
}
static int F_94 ( struct V_69 * V_69 , void * V_85 ,
struct V_177 * V_81 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
if ( V_27 -> V_28 -> V_179 )
return V_27 -> V_28 -> V_179 ( V_19 , V_81 ) ;
return - V_24 ;
}
static void F_95 ( struct V_26 * V_27 )
{
struct V_18 * V_19 ;
F_17 ( & V_125 ) ;
F_96 (icd, &devices, list)
if ( V_19 -> V_180 == V_27 -> V_181 ) {
struct V_132 * V_133 = F_66 ( V_19 ) ;
struct V_3 * V_4 = & V_133 -> V_134 ;
if ( V_4 -> V_135 )
if ( V_19 -> V_136 )
V_4 -> V_135 ( V_19 -> V_136 ) ;
V_19 -> V_52 = V_27 -> V_182 . V_2 ;
F_97 ( V_27 , V_19 ) ;
}
F_18 ( & V_125 ) ;
}
static int F_98 ( struct V_5 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_70 ;
struct V_26 * V_27 ;
if ( ! V_19 || ! V_19 -> V_52 )
return - V_25 ;
V_27 = F_23 ( V_19 -> V_52 ) ;
if ( ! F_64 ( V_27 -> V_28 -> V_127 ) )
return - V_25 ;
return F_16 ( V_27 ) ;
}
static void F_99 ( struct V_5 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_70 ;
struct V_26 * V_27 ;
if ( ! V_19 || ! V_19 -> V_52 )
return;
V_27 = F_23 ( V_19 -> V_52 ) ;
F_19 ( V_27 ) ;
F_71 ( V_27 -> V_28 -> V_127 ) ;
}
static int F_100 ( struct V_132 * V_133 ,
struct V_183 * V_184 )
{
struct V_185 * V_57 ;
int V_7 , V_34 ;
F_17 ( & V_125 ) ;
V_34 = F_101 ( V_186 , V_187 ) ;
if ( V_34 < V_187 )
F_102 ( V_34 , V_186 ) ;
F_18 ( & V_125 ) ;
if ( V_34 >= V_187 )
return - V_112 ;
V_57 = F_103 ( L_23 , V_34 ) ;
if ( ! V_57 )
return - V_112 ;
V_7 = F_104 ( V_57 , V_133 , sizeof( * V_133 ) ) ;
if ( V_7 < 0 ) {
F_105 ( V_57 ) ;
return V_7 ;
}
V_184 -> V_57 = V_57 ;
return 0 ;
}
static struct V_18 * F_106 ( struct V_183 * V_184 )
{
struct V_185 * V_57 = V_184 -> V_57 ;
int V_7 ;
V_7 = F_107 ( V_57 ) ;
if ( V_7 < 0 || ! V_57 -> V_2 . V_163 )
return NULL ;
return F_108 ( V_57 ) ;
}
static int F_109 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
struct V_188 V_56 = {
. V_106 = V_107 ,
} ;
struct V_189 * V_190 = & V_56 . V_159 ;
int V_7 ;
V_21 -> V_191 = F_110 ( V_19 ) ;
F_111 ( V_21 , V_19 ) ;
F_14 ( V_21 , V_82 , V_192 , & V_19 -> V_78 -> V_79 ) ;
V_7 = F_112 ( & V_19 -> V_144 , V_21 -> V_144 , NULL ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_57 ( V_19 ) ;
if ( V_7 < 0 ) {
F_4 ( V_19 -> V_57 , L_13 , V_7 ) ;
return V_7 ;
}
V_7 = F_51 ( V_19 ) ;
if ( V_7 < 0 )
goto V_193;
V_19 -> V_120 = V_194 ;
V_7 = F_113 ( V_19 ) ;
if ( V_7 < 0 )
goto V_195;
if ( ! F_14 ( V_21 , V_108 , V_196 , NULL , & V_56 ) ) {
V_19 -> V_117 = V_190 -> V_59 ;
V_19 -> V_118 = V_190 -> V_60 ;
V_19 -> V_119 = V_190 -> V_119 ;
V_19 -> V_120 = V_190 -> V_120 ;
}
F_58 ( V_19 ) ;
return 0 ;
V_195:
F_55 ( V_19 ) ;
V_193:
F_58 ( V_19 ) ;
return V_7 ;
}
static int F_114 ( struct V_18 * V_19 ,
struct V_132 * V_133 )
{
struct V_3 * V_4 ;
struct V_197 * V_198 ;
struct V_26 * V_27 ;
struct V_199 * V_200 = & V_133 -> V_201 ;
struct V_202 * V_203 ;
struct V_20 * V_204 ;
char V_205 [ V_206 ] ;
int V_7 ;
if ( V_19 -> V_184 ) {
return - V_207 ;
}
V_27 = F_23 ( V_19 -> V_52 ) ;
V_203 = F_115 ( V_200 -> V_208 ) ;
if ( ! V_203 ) {
F_4 ( V_19 -> V_57 , L_24 ,
V_200 -> V_208 ) ;
return - V_25 ;
}
V_4 = F_116 ( & V_133 -> V_134 , sizeof( * V_4 ) , V_209 ) ;
if ( ! V_4 ) {
V_7 = - V_112 ;
goto V_210;
}
V_4 -> V_11 . V_12 = 0 ;
V_4 -> V_11 . V_13 = NULL ;
V_200 -> V_211 -> V_212 = V_4 ;
F_117 ( V_205 , sizeof( V_205 ) ,
V_200 -> V_208 , V_200 -> V_211 -> V_213 ) ;
V_19 -> V_6 = F_118 ( & V_214 , V_205 , V_19 ) ;
if ( F_119 ( V_19 -> V_6 ) ) {
V_7 = F_120 ( V_19 -> V_6 ) ;
goto V_215;
}
V_204 = F_121 ( & V_27 -> V_182 , V_203 ,
V_200 -> V_211 , NULL ) ;
if ( ! V_204 ) {
V_7 = - V_25 ;
goto V_216;
}
V_198 = F_122 ( V_204 ) ;
V_19 -> V_136 = & V_198 -> V_2 ;
return 0 ;
V_216:
F_123 ( V_19 -> V_6 ) ;
V_19 -> V_6 = NULL ;
V_215:
F_124 ( V_4 ) ;
V_210:
F_125 ( V_203 ) ;
return V_7 ;
}
static void F_126 ( struct V_18 * V_19 )
{
struct V_197 * V_198 =
F_127 ( F_65 ( V_19 ) ) ;
struct V_202 * V_203 ;
struct V_3 * V_4 ;
V_19 -> V_136 = NULL ;
if ( V_19 -> V_184 )
return;
V_203 = V_198 -> V_217 ;
V_4 = V_198 -> V_2 . V_212 ;
F_128 ( F_129 ( V_198 ) ) ;
F_130 ( V_198 ) ;
F_125 ( V_203 ) ;
F_124 ( V_4 ) ;
F_123 ( V_19 -> V_6 ) ;
V_19 -> V_6 = NULL ;
}
static int F_131 ( struct V_218 * V_219 ,
struct V_20 * V_21 ,
struct V_220 * V_221 )
{
struct V_183 * V_184 = F_132 ( V_219 ,
struct V_183 , V_219 ) ;
struct V_18 * V_19 = F_108 ( V_184 -> V_57 ) ;
if ( V_221 == V_184 -> V_222 && ! F_30 ( V_19 -> V_136 ) ) {
struct V_197 * V_198 = F_122 ( V_21 ) ;
if ( V_198 ) {
struct V_132 * V_133 = F_66 ( V_19 ) ;
struct V_3 * V_4 =
F_133 ( V_198 ) ;
if ( V_4 ) {
memcpy ( & V_133 -> V_134 , V_4 ,
sizeof( V_133 -> V_134 ) ) ;
if ( V_4 -> V_135 )
V_4 -> V_135 ( & V_198 -> V_2 ) ;
}
V_19 -> V_136 = & V_198 -> V_2 ;
}
}
return 0 ;
}
static void F_134 ( struct V_218 * V_219 ,
struct V_20 * V_21 ,
struct V_220 * V_221 )
{
struct V_183 * V_184 = F_132 ( V_219 ,
struct V_183 , V_219 ) ;
struct V_18 * V_19 = F_108 ( V_184 -> V_57 ) ;
V_19 -> V_136 = NULL ;
if ( V_19 -> V_6 ) {
F_123 ( V_19 -> V_6 ) ;
V_19 -> V_6 = NULL ;
}
}
static int F_135 ( struct V_218 * V_219 )
{
struct V_183 * V_184 = F_132 ( V_219 ,
struct V_183 , V_219 ) ;
struct V_18 * V_19 = F_108 ( V_184 -> V_57 ) ;
if ( F_65 ( V_19 ) ) {
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
int V_7 ;
F_17 ( & V_125 ) ;
V_7 = F_97 ( V_27 , V_19 ) ;
F_18 ( & V_125 ) ;
if ( V_7 < 0 )
return V_7 ;
}
return 0 ;
}
static int F_136 ( struct V_26 * V_27 ,
struct V_220 * * V_221 , unsigned int V_223 )
{
struct V_224 * V_225 ;
struct V_183 * V_184 ;
struct V_18 * V_19 ;
struct V_132 V_133 = { . V_201 . V_226 = V_27 -> V_181 ,} ;
char V_205 [ V_206 ] ;
unsigned int V_34 ;
int V_7 ;
for ( V_34 = 0 ; V_34 < V_223 ; V_34 ++ ) {
V_225 = F_132 ( V_221 [ V_34 ] , struct V_224 , V_221 ) ;
if ( V_225 -> V_227 == V_228 )
break;
}
if ( V_34 >= V_223 || V_221 [ V_34 ] -> V_229 != V_230 ) {
F_4 ( V_27 -> V_182 . V_2 , L_25 ) ;
return - V_25 ;
}
V_184 = F_137 ( V_27 -> V_182 . V_2 , sizeof( * V_184 ) , V_209 ) ;
if ( ! V_184 )
return - V_112 ;
V_133 . V_201 . V_211 = F_138 ( - V_231 ) ;
V_7 = F_100 ( & V_133 , V_184 ) ;
if ( V_7 < 0 )
goto V_232;
V_184 -> V_222 = & V_225 -> V_221 ;
V_19 = F_106 ( V_184 ) ;
if ( ! V_19 ) {
V_7 = - V_112 ;
goto V_233;
}
V_184 -> V_219 . V_234 = V_221 ;
V_184 -> V_219 . V_235 = V_223 ;
V_184 -> V_219 . V_236 = F_131 ;
V_184 -> V_219 . V_237 = F_134 ;
V_184 -> V_219 . V_238 = F_135 ;
V_19 -> V_184 = V_184 ;
V_19 -> V_52 = V_27 -> V_182 . V_2 ;
F_117 ( V_205 , sizeof( V_205 ) ,
V_225 -> V_221 . V_239 . V_240 . V_241 ,
V_225 -> V_221 . V_239 . V_240 . V_242 ) ;
V_19 -> V_6 = F_118 ( & V_214 , V_205 , V_19 ) ;
if ( F_119 ( V_19 -> V_6 ) ) {
V_7 = F_120 ( V_19 -> V_6 ) ;
goto V_215;
}
V_7 = F_139 ( & V_27 -> V_182 , & V_184 -> V_219 ) ;
if ( ! V_7 )
return 0 ;
F_123 ( V_19 -> V_6 ) ;
V_215:
V_19 -> V_6 = NULL ;
F_140 ( V_184 -> V_57 ) ;
V_233:
F_105 ( V_184 -> V_57 ) ;
V_232:
F_141 ( V_27 -> V_182 . V_2 , V_184 ) ;
F_4 ( V_27 -> V_182 . V_2 , L_26 , V_7 ) ;
return V_7 ;
}
static void F_142 ( struct V_26 * V_27 )
{
struct V_220 * * V_221 ;
int V_243 ;
for ( V_243 = 0 , V_221 = V_27 -> V_221 ; V_27 -> V_244 [ V_243 ] ; V_243 ++ ) {
F_136 ( V_27 , V_221 , V_27 -> V_244 [ V_243 ] ) ;
V_221 += V_27 -> V_244 [ V_243 ] ;
}
}
static int F_143 ( struct V_26 * V_27 ,
struct V_245 * V_246 ,
struct V_245 * V_247 )
{
struct V_18 * V_19 ;
struct V_132 V_133 = { . V_201 . V_226 = V_27 -> V_181 ,} ;
struct V_183 * V_184 ;
struct V_248 * V_249 ;
struct V_197 * V_198 ;
char V_205 [ V_206 ] ;
int V_7 ;
V_249 = F_137 ( V_27 -> V_182 . V_2 , sizeof( struct V_248 ) ,
V_209 ) ;
if ( ! V_249 )
return - V_112 ;
V_249 -> V_225 . V_221 . V_239 . V_250 . V_250 = F_144 ( V_247 ) ;
V_249 -> V_225 . V_221 . V_229 = V_251 ;
V_249 -> V_204 = & V_249 -> V_225 . V_221 ;
V_184 = & V_249 -> V_184 ;
V_133 . V_201 . V_211 = F_138 ( - V_231 ) ;
V_7 = F_100 ( & V_133 , V_184 ) ;
if ( V_7 < 0 )
goto V_232;
V_184 -> V_222 = & V_249 -> V_225 . V_221 ;
V_19 = F_106 ( V_184 ) ;
if ( ! V_19 ) {
V_7 = - V_112 ;
goto V_233;
}
V_184 -> V_219 . V_234 = & V_249 -> V_204 ;
V_184 -> V_219 . V_235 = 1 ;
V_184 -> V_219 . V_236 = F_131 ;
V_184 -> V_219 . V_237 = F_134 ;
V_184 -> V_219 . V_238 = F_135 ;
V_19 -> V_184 = V_184 ;
V_19 -> V_52 = V_27 -> V_182 . V_2 ;
V_198 = F_145 ( V_247 ) ;
if ( V_198 )
F_117 ( V_205 , sizeof( V_205 ) ,
V_198 -> V_217 -> V_181 , V_198 -> V_213 ) ;
else
F_146 ( V_205 , sizeof( V_205 ) ,
F_147 ( V_247 ) ) ;
V_19 -> V_6 = F_118 ( & V_214 , V_205 , V_19 ) ;
if ( F_119 ( V_19 -> V_6 ) ) {
V_7 = F_120 ( V_19 -> V_6 ) ;
goto V_215;
}
V_7 = F_139 ( & V_27 -> V_182 , & V_184 -> V_219 ) ;
if ( ! V_7 )
return 0 ;
F_123 ( V_19 -> V_6 ) ;
V_215:
V_19 -> V_6 = NULL ;
F_140 ( V_184 -> V_57 ) ;
V_233:
F_105 ( V_184 -> V_57 ) ;
V_232:
F_141 ( V_27 -> V_182 . V_2 , V_249 ) ;
F_4 ( V_27 -> V_182 . V_2 , L_26 , V_7 ) ;
return V_7 ;
}
static void F_148 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_182 . V_2 ;
struct V_245 * V_252 = V_2 -> V_253 ;
struct V_245 * V_254 = NULL , * V_255 ;
unsigned int V_34 ;
for ( V_34 = 0 ; ; V_34 ++ ) {
V_254 = F_149 ( V_252 , V_254 ) ;
if ( ! V_254 )
break;
V_255 = F_150 ( V_254 ) ;
if ( ! V_255 ) {
F_151 ( V_2 , L_27 ,
F_147 ( V_254 ) ) ;
continue;
}
if ( ! V_34 )
F_143 ( V_27 , V_254 , V_255 -> V_52 ) ;
F_152 ( V_255 ) ;
if ( V_34 ) {
F_4 ( V_2 , L_28 ) ;
break;
}
}
F_152 ( V_254 ) ;
}
static inline void F_148 ( struct V_26 * V_27 ) { }
static int F_97 ( struct V_26 * V_27 ,
struct V_18 * V_19 )
{
struct V_132 * V_133 = F_66 ( V_19 ) ;
struct V_199 * V_200 = & V_133 -> V_201 ;
struct V_1 * V_136 = NULL ;
int V_7 ;
F_153 ( V_19 -> V_57 , L_29 , F_154 ( V_19 -> V_57 ) ) ;
V_7 = F_155 ( & V_19 -> V_144 , 16 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_156 ( V_19 ) ;
if ( V_7 < 0 )
goto V_256;
if ( V_200 -> V_211 ) {
V_7 = F_114 ( V_19 , V_133 ) ;
if ( V_7 < 0 && V_7 != - V_207 )
goto V_123;
} else if ( ! V_200 -> V_257 || ! V_200 -> V_258 ) {
V_7 = - V_67 ;
goto V_123;
} else {
V_7 = F_16 ( V_27 ) ;
if ( V_7 < 0 )
goto V_123;
if ( V_200 -> V_259 )
V_7 = F_157 ( V_200 -> V_259 ) ;
V_7 = V_200 -> V_257 ( V_19 ) ;
if ( V_7 < 0 )
goto V_260;
V_136 = F_65 ( V_19 ) ;
if ( ! V_136 || ! V_136 -> V_163 || ! F_158 ( V_136 ) ||
! F_64 ( V_136 -> V_163 -> V_127 ) ) {
V_200 -> V_258 ( V_19 ) ;
V_7 = - V_25 ;
goto V_261;
}
}
F_17 ( & V_27 -> V_129 ) ;
V_7 = F_109 ( V_19 ) ;
F_18 ( & V_27 -> V_129 ) ;
if ( V_7 < 0 )
goto V_262;
return 0 ;
V_262:
if ( V_200 -> V_211 ) {
F_126 ( V_19 ) ;
} else {
V_200 -> V_258 ( V_19 ) ;
F_71 ( V_136 -> V_163 -> V_127 ) ;
V_261:
V_260:
F_19 ( V_27 ) ;
}
V_123:
if ( V_19 -> V_78 ) {
F_159 ( V_19 -> V_78 ) ;
V_19 -> V_78 = NULL ;
}
V_256:
F_160 ( & V_19 -> V_144 ) ;
return V_7 ;
}
static int F_161 ( struct V_18 * V_19 )
{
struct V_132 * V_133 = F_66 ( V_19 ) ;
struct V_124 * V_78 = V_19 -> V_78 ;
F_160 ( & V_19 -> V_144 ) ;
if ( V_78 ) {
F_162 ( V_78 ) ;
V_19 -> V_78 = NULL ;
}
if ( V_133 -> V_201 . V_211 ) {
F_126 ( V_19 ) ;
} else {
struct V_1 * V_2 = F_65 ( V_19 ) ;
struct V_263 * V_264 = V_2 ? V_2 -> V_163 : NULL ;
if ( V_264 ) {
V_133 -> V_201 . V_258 ( V_19 ) ;
F_71 ( V_264 -> V_127 ) ;
}
}
if ( V_19 -> V_35 )
F_55 ( V_19 ) ;
if ( V_19 -> V_6 ) {
F_123 ( V_19 -> V_6 ) ;
V_19 -> V_6 = NULL ;
}
if ( V_19 -> V_184 )
F_163 ( V_19 -> V_184 -> V_57 ) ;
return 0 ;
}
static int F_164 ( struct V_18 * V_19 ,
struct V_168 * V_265 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
struct V_266 V_267 = {
. V_106 = V_107 ,
. V_171 = V_265 -> V_171 ,
} ;
int V_7 ;
V_7 = F_14 ( V_21 , V_108 , V_170 , NULL , & V_267 ) ;
if ( V_7 )
return V_7 ;
V_265 -> V_174 = V_267 . V_174 ;
return 0 ;
}
static int F_165 ( struct V_18 * V_19 ,
struct V_168 * V_265 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
struct V_266 V_267 = {
. V_106 = V_107 ,
. V_171 = V_265 -> V_171 ,
. V_41 = V_265 -> V_41 ,
. V_174 = V_265 -> V_174 ,
} ;
int V_7 ;
V_7 = F_14 ( V_21 , V_108 , V_176 , NULL , & V_267 ) ;
if ( V_7 )
return V_7 ;
V_265 -> V_174 = V_267 . V_174 ;
return 0 ;
}
static int F_166 ( struct V_18 * V_19 ,
struct V_177 * V_268 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_82 , V_269 , V_268 ) ;
}
static int F_167 ( struct V_18 * V_19 ,
struct V_177 * V_268 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_82 , V_270 , V_268 ) ;
}
static int F_168 ( struct V_18 * V_19 ,
struct V_86 * V_87 )
{
int V_7 ;
struct V_20 * V_21 = F_13 ( V_19 ) ;
const struct V_32 * V_53 ;
struct V_271 V_272 = {
. V_75 = V_87 -> V_75 ,
. V_106 = V_107 ,
} ;
V_53 = F_20 ( V_19 , V_87 -> V_273 ) ;
if ( ! V_53 )
return - V_67 ;
V_272 . V_105 = V_53 -> V_105 ;
V_7 = F_14 ( V_21 , V_108 , V_274 , NULL , & V_272 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_272 . V_275 == V_272 . V_276 &&
V_272 . V_277 == V_272 . V_278 ) {
V_87 -> type = V_279 ;
V_87 -> V_280 . V_59 = V_272 . V_275 ;
V_87 -> V_280 . V_60 = V_272 . V_277 ;
return 0 ;
}
V_87 -> type = V_281 ;
V_87 -> V_282 . V_275 = V_272 . V_275 ;
V_87 -> V_282 . V_276 = V_272 . V_276 ;
V_87 -> V_282 . V_277 = V_272 . V_277 ;
V_87 -> V_282 . V_278 = V_272 . V_278 ;
V_87 -> V_282 . V_283 = 1 ;
V_87 -> V_282 . V_284 = 1 ;
return 0 ;
}
int F_169 ( struct V_26 * V_27 )
{
struct V_26 * V_285 ;
int V_7 ;
if ( ! V_27 || ! V_27 -> V_28 ||
! V_27 -> V_28 -> V_66 ||
! V_27 -> V_28 -> V_116 ||
! V_27 -> V_28 -> V_121 ||
! V_27 -> V_28 -> V_165 ||
! V_27 -> V_28 -> V_142 ||
! V_27 -> V_28 -> V_156 ||
! V_27 -> V_182 . V_2 )
return - V_67 ;
if ( ! V_27 -> V_28 -> V_176 )
V_27 -> V_28 -> V_176 = F_165 ;
if ( ! V_27 -> V_28 -> V_170 )
V_27 -> V_28 -> V_170 = F_164 ;
if ( ! V_27 -> V_28 -> V_179 )
V_27 -> V_28 -> V_179 = F_167 ;
if ( ! V_27 -> V_28 -> V_178 )
V_27 -> V_28 -> V_178 = F_166 ;
if ( ! V_27 -> V_28 -> V_88 )
V_27 -> V_28 -> V_88 = F_168 ;
F_17 ( & V_125 ) ;
F_96 (ix, &hosts, list) {
if ( V_285 -> V_181 == V_27 -> V_181 ) {
V_7 = - V_92 ;
goto V_286;
}
}
V_7 = F_170 ( V_27 -> V_182 . V_2 , & V_27 -> V_182 ) ;
if ( V_7 < 0 )
goto V_286;
F_171 ( & V_27 -> V_287 , & V_288 ) ;
F_18 ( & V_125 ) ;
F_172 ( & V_27 -> V_129 ) ;
F_172 ( & V_27 -> V_30 ) ;
if ( V_27 -> V_182 . V_2 -> V_253 )
F_148 ( V_27 ) ;
else if ( V_27 -> V_244 )
F_142 ( V_27 ) ;
else
F_95 ( V_27 ) ;
return 0 ;
V_286:
F_18 ( & V_125 ) ;
return V_7 ;
}
void F_173 ( struct V_26 * V_27 )
{
struct V_18 * V_19 , * V_289 ;
struct V_183 * V_184 ;
F_174 ( V_290 ) ;
F_17 ( & V_125 ) ;
F_175 ( & V_27 -> V_287 ) ;
F_96 (icd, &devices, list)
if ( V_19 -> V_180 == V_27 -> V_181 && V_19 -> V_184 ) {
F_176 ( V_19 -> V_57 ) ;
F_177 ( & V_19 -> V_184 -> V_287 , & V_290 ) ;
}
F_18 ( & V_125 ) ;
F_96 (sasc, &notifiers, list) {
F_178 ( & V_184 -> V_219 ) ;
F_179 ( & V_184 -> V_57 -> V_2 ) ;
}
F_17 ( & V_125 ) ;
F_180 (icd, tmp, &devices, list)
if ( V_19 -> V_180 == V_27 -> V_181 )
F_161 ( V_19 ) ;
F_18 ( & V_125 ) ;
F_181 ( & V_27 -> V_182 ) ;
}
static int F_182 ( struct V_18 * V_19 )
{
struct V_18 * V_285 ;
int V_291 = - 1 , V_34 ;
F_17 ( & V_125 ) ;
for ( V_34 = 0 ; V_34 < 256 && V_291 < 0 ; V_34 ++ ) {
V_291 = V_34 ;
F_96 (ix, &devices, list) {
if ( V_285 -> V_180 == V_19 -> V_180 && V_285 -> V_292 == V_34 ) {
V_291 = - 1 ;
break;
}
}
}
if ( V_291 < 0 ) {
F_18 ( & V_125 ) ;
return - V_112 ;
}
V_19 -> V_292 = V_291 ;
V_19 -> V_131 = 0 ;
V_19 -> V_293 = NULL ;
V_34 = F_183 ( V_19 -> V_57 ) -> V_294 ;
if ( V_34 < 0 )
V_34 = 0 ;
if ( V_34 >= V_187 ) {
F_18 ( & V_125 ) ;
return - V_92 ;
}
F_102 ( V_34 , V_186 ) ;
F_171 ( & V_19 -> V_287 , & V_295 ) ;
F_18 ( & V_125 ) ;
return 0 ;
}
static int F_156 ( struct V_18 * V_19 )
{
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
struct V_124 * V_78 = F_184 () ;
if ( ! V_78 )
return - V_112 ;
F_84 ( V_78 -> V_80 , V_27 -> V_164 , sizeof( V_78 -> V_80 ) ) ;
V_78 -> V_182 = & V_27 -> V_182 ;
V_78 -> V_296 = & V_297 ;
V_78 -> V_298 = & V_299 ;
V_78 -> V_300 = F_159 ;
V_78 -> V_144 = & V_19 -> V_144 ;
V_78 -> V_301 = & V_27 -> V_129 ;
V_19 -> V_78 = V_78 ;
return 0 ;
}
static int F_113 ( struct V_18 * V_19 )
{
const struct V_302 * type = V_19 -> V_78 -> V_2 . type ;
int V_7 ;
if ( ! V_19 -> V_52 )
return - V_25 ;
F_185 ( V_19 -> V_78 , V_19 ) ;
if ( V_19 -> V_78 -> V_79 == 0 ) {
F_186 ( V_19 -> V_78 , V_303 ) ;
F_186 ( V_19 -> V_78 , V_304 ) ;
F_186 ( V_19 -> V_78 , V_305 ) ;
}
V_7 = F_187 ( V_19 -> V_78 , V_306 , - 1 ) ;
if ( V_7 < 0 ) {
F_4 ( V_19 -> V_57 , L_30 , V_7 ) ;
return V_7 ;
}
V_19 -> V_78 -> V_2 . type = type ;
return 0 ;
}
static int F_188 ( struct V_185 * V_57 )
{
struct V_132 * V_133 = V_57 -> V_2 . V_212 ;
struct V_3 * V_4 = & V_133 -> V_134 ;
struct V_18 * V_19 ;
int V_7 ;
if ( ! V_133 )
return - V_67 ;
V_19 = F_137 ( & V_57 -> V_2 , sizeof( * V_19 ) , V_209 ) ;
if ( ! V_19 )
return - V_112 ;
V_7 = F_11 ( & V_57 -> V_2 , V_4 -> V_11 . V_12 ,
V_4 -> V_11 . V_13 ) ;
if ( V_7 < 0 )
return V_7 ;
V_19 -> V_180 = V_133 -> V_201 . V_226 ;
V_19 -> V_133 = V_133 ;
V_19 -> V_57 = & V_57 -> V_2 ;
F_189 ( V_57 , V_19 ) ;
V_19 -> V_117 = V_307 ;
V_19 -> V_118 = V_308 ;
return F_182 ( V_19 ) ;
}
static int F_190 ( struct V_185 * V_57 )
{
struct V_18 * V_19 = F_108 ( V_57 ) ;
int V_34 ;
if ( ! V_19 )
return - V_67 ;
V_34 = V_57 -> V_294 ;
if ( V_34 < 0 )
V_34 = 0 ;
if ( F_191 ( V_34 , V_186 ) ) {
F_192 ( V_34 , V_186 ) ;
F_175 ( & V_19 -> V_287 ) ;
}
return 0 ;
}

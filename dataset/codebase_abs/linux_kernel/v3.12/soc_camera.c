int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 = V_6 ? F_2 ( V_6 ) : 0 ;
if ( V_7 < 0 ) {
F_3 ( V_2 , L_1 , V_7 ) ;
return V_7 ;
}
V_7 = F_4 ( V_4 -> V_8 ,
V_4 -> V_9 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 , L_2 ) ;
goto V_10;
}
if ( V_4 -> V_11 ) {
V_7 = V_4 -> V_11 ( V_2 , 1 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 ,
L_3 ) ;
goto V_12;
}
}
return 0 ;
V_12:
F_5 ( V_4 -> V_8 ,
V_4 -> V_9 ) ;
V_10:
if ( V_6 )
F_6 ( V_6 ) ;
return V_7 ;
}
int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 = 0 ;
int V_13 ;
if ( V_4 -> V_11 ) {
V_13 = V_4 -> V_11 ( V_2 , 0 ) ;
if ( V_13 < 0 ) {
F_3 ( V_2 ,
L_4 ) ;
V_7 = V_13 ;
}
}
V_13 = F_5 ( V_4 -> V_8 ,
V_4 -> V_9 ) ;
if ( V_13 < 0 ) {
F_3 ( V_2 , L_5 ) ;
V_7 = V_7 ? : V_13 ;
}
if ( V_6 )
F_6 ( V_6 ) ;
return V_7 ;
}
int F_8 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return F_9 ( V_2 , V_4 -> V_8 ,
V_4 -> V_9 ) ;
}
static int F_10 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_11 ( V_15 ) ;
int V_7 ;
V_7 = F_12 ( V_17 , V_18 , V_19 , 1 ) ;
if ( V_7 < 0 && V_7 != - V_20 && V_7 != - V_21 )
return V_7 ;
return 0 ;
}
static int F_13 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_11 ( V_15 ) ;
int V_7 ;
V_7 = F_12 ( V_17 , V_18 , V_19 , 0 ) ;
if ( V_7 < 0 && V_7 != - V_20 && V_7 != - V_21 )
return V_7 ;
return 0 ;
}
const struct V_22 * F_14 (
struct V_14 * V_15 , unsigned int V_23 )
{
unsigned int V_24 ;
for ( V_24 = 0 ; V_24 < V_15 -> V_25 ; V_24 ++ )
if ( V_15 -> V_26 [ V_24 ] . V_27 -> V_23 == V_23 )
return V_15 -> V_26 + V_24 ;
return NULL ;
}
unsigned long F_15 ( struct V_3 * V_4 ,
const struct V_28 * V_29 )
{
unsigned long V_30 , V_31 = V_29 -> V_31 ;
if ( V_4 -> V_31 & V_32 ) {
V_30 = V_31 & ( V_33 | V_34 ) ;
if ( V_30 == V_33 || V_30 == V_34 )
V_31 ^= V_33 | V_34 ;
}
if ( V_4 -> V_31 & V_35 ) {
V_30 = V_31 & ( V_36 | V_37 ) ;
if ( V_30 == V_36 || V_30 == V_37 )
V_31 ^= V_36 | V_37 ;
}
if ( V_4 -> V_31 & V_38 ) {
V_30 = V_31 & ( V_39 | V_40 ) ;
if ( V_30 == V_39 || V_30 == V_40 )
V_31 ^= V_39 | V_40 ;
}
return V_31 ;
}
static int F_16 ( struct V_14 * V_15 ,
struct V_41 * V_30 )
{
struct V_42 * V_43 = F_17 ( V_15 -> V_44 ) ;
const struct V_22 * V_45 ;
struct V_46 * V_47 = & V_30 -> V_48 . V_47 ;
int V_7 ;
F_18 ( V_15 -> V_49 , L_6 ,
F_19 ( V_47 -> V_50 ) , V_47 -> V_51 , V_47 -> V_52 ) ;
if ( V_47 -> V_50 != V_53 &&
! ( V_43 -> V_54 & V_55 ) ) {
V_47 -> V_56 = 0 ;
V_47 -> V_57 = 0 ;
}
V_7 = V_43 -> V_58 -> V_59 ( V_15 , V_30 ) ;
if ( V_7 < 0 )
return V_7 ;
V_45 = F_14 ( V_15 , V_47 -> V_50 ) ;
if ( ! V_45 )
return - V_60 ;
V_7 = F_20 ( V_47 -> V_51 , V_45 -> V_27 ) ;
if ( V_7 < 0 )
return V_7 ;
V_47 -> V_56 = F_21 ( V_61 , V_47 -> V_56 , V_7 ) ;
V_7 = F_22 ( V_45 -> V_27 , V_47 -> V_56 ,
V_47 -> V_52 ) ;
if ( V_7 < 0 )
return V_7 ;
V_47 -> V_57 = F_21 ( V_61 , V_47 -> V_57 , V_7 ) ;
return 0 ;
}
static int F_23 ( struct V_62 * V_62 , void * V_63 ,
struct V_41 * V_30 )
{
struct V_14 * V_15 = V_62 -> V_64 ;
F_24 ( V_63 != V_62 -> V_64 ) ;
if ( V_30 -> type != V_65 )
return - V_60 ;
return F_16 ( V_15 , V_30 ) ;
}
static int F_25 ( struct V_62 * V_62 , void * V_63 ,
struct V_66 * V_67 )
{
if ( V_67 -> V_68 != 0 )
return - V_60 ;
V_67 -> type = V_69 ;
strcpy ( V_67 -> V_70 , L_7 ) ;
return 0 ;
}
static int F_26 ( struct V_62 * V_62 , void * V_63 , unsigned int * V_24 )
{
* V_24 = 0 ;
return 0 ;
}
static int F_27 ( struct V_62 * V_62 , void * V_63 , unsigned int V_24 )
{
if ( V_24 > 0 )
return - V_60 ;
return 0 ;
}
static int F_28 ( struct V_62 * V_62 , void * V_63 , T_1 V_71 )
{
struct V_14 * V_15 = V_62 -> V_64 ;
struct V_16 * V_17 = F_11 ( V_15 ) ;
return F_12 ( V_17 , V_18 , V_72 , V_71 ) ;
}
static int F_29 ( struct V_62 * V_62 , void * V_63 , T_1 * V_71 )
{
struct V_14 * V_15 = V_62 -> V_64 ;
struct V_16 * V_17 = F_11 ( V_15 ) ;
return F_12 ( V_17 , V_18 , V_73 , V_71 ) ;
}
static int F_30 ( struct V_62 * V_62 , void * V_74 ,
struct V_75 * V_76 )
{
struct V_14 * V_15 = V_62 -> V_64 ;
struct V_42 * V_43 = F_17 ( V_15 -> V_44 ) ;
return V_43 -> V_58 -> V_77 ( V_15 , V_76 ) ;
}
static int F_31 ( struct V_62 * V_62 , void * V_63 ,
struct V_78 * V_79 )
{
int V_7 ;
struct V_14 * V_15 = V_62 -> V_64 ;
struct V_42 * V_43 = F_17 ( V_15 -> V_44 ) ;
F_24 ( V_63 != V_62 -> V_64 ) ;
if ( V_15 -> V_80 && V_15 -> V_80 != V_62 )
return - V_81 ;
if ( V_43 -> V_58 -> V_82 ) {
V_7 = F_32 ( & V_15 -> V_83 , V_79 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = V_43 -> V_58 -> V_84 ( V_15 , V_79 ) ;
} else {
V_7 = F_33 ( & V_15 -> V_85 , V_79 ) ;
}
if ( ! V_7 && ! V_15 -> V_80 )
V_15 -> V_80 = V_62 ;
return V_7 ;
}
static int F_34 ( struct V_62 * V_62 , void * V_63 ,
struct V_86 * V_79 )
{
struct V_14 * V_15 = V_62 -> V_64 ;
struct V_42 * V_43 = F_17 ( V_15 -> V_44 ) ;
F_24 ( V_63 != V_62 -> V_64 ) ;
if ( V_43 -> V_58 -> V_82 )
return F_35 ( & V_15 -> V_83 , V_79 ) ;
else
return F_36 ( & V_15 -> V_85 , V_79 ) ;
}
static int F_37 ( struct V_62 * V_62 , void * V_63 ,
struct V_86 * V_79 )
{
struct V_14 * V_15 = V_62 -> V_64 ;
struct V_42 * V_43 = F_17 ( V_15 -> V_44 ) ;
F_24 ( V_63 != V_62 -> V_64 ) ;
if ( V_15 -> V_80 != V_62 )
return - V_81 ;
if ( V_43 -> V_58 -> V_82 )
return F_38 ( & V_15 -> V_83 , V_79 ) ;
else
return F_39 ( & V_15 -> V_85 , V_79 ) ;
}
static int F_40 ( struct V_62 * V_62 , void * V_63 ,
struct V_86 * V_79 )
{
struct V_14 * V_15 = V_62 -> V_64 ;
struct V_42 * V_43 = F_17 ( V_15 -> V_44 ) ;
F_24 ( V_63 != V_62 -> V_64 ) ;
if ( V_15 -> V_80 != V_62 )
return - V_81 ;
if ( V_43 -> V_58 -> V_82 )
return F_41 ( & V_15 -> V_83 , V_79 , V_62 -> V_87 & V_88 ) ;
else
return F_42 ( & V_15 -> V_85 , V_79 , V_62 -> V_87 & V_88 ) ;
}
static int F_43 ( struct V_62 * V_62 , void * V_63 ,
struct V_89 * V_90 )
{
struct V_14 * V_15 = V_62 -> V_64 ;
struct V_42 * V_43 = F_17 ( V_15 -> V_44 ) ;
if ( V_43 -> V_58 -> V_82 )
return - V_60 ;
else
return F_44 ( & V_15 -> V_85 , V_90 ) ;
}
static int F_45 ( struct V_62 * V_62 , void * V_63 ,
struct V_86 * V_91 )
{
struct V_14 * V_15 = V_62 -> V_64 ;
struct V_42 * V_43 = F_17 ( V_15 -> V_44 ) ;
if ( V_43 -> V_58 -> V_82 )
return - V_60 ;
else
return F_46 ( & V_15 -> V_85 , V_91 ) ;
}
static int F_47 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_11 ( V_15 ) ;
struct V_42 * V_43 = F_17 ( V_15 -> V_44 ) ;
unsigned int V_24 , V_92 = 0 , V_93 = 0 ;
int V_7 ;
enum V_94 V_95 ;
while ( ! F_12 ( V_17 , V_96 , V_97 , V_93 , & V_95 ) )
V_93 ++ ;
if ( ! V_43 -> V_58 -> V_98 )
V_92 = V_93 ;
else
for ( V_24 = 0 ; V_24 < V_93 ; V_24 ++ ) {
V_7 = V_43 -> V_58 -> V_98 ( V_15 , V_24 , NULL ) ;
if ( V_7 < 0 )
return V_7 ;
V_92 += V_7 ;
}
if ( ! V_92 )
return - V_99 ;
V_15 -> V_26 =
F_48 ( V_92 * sizeof( struct V_22 ) ) ;
if ( ! V_15 -> V_26 )
return - V_100 ;
F_18 ( V_15 -> V_49 , L_8 , V_92 ) ;
V_92 = 0 ;
for ( V_24 = 0 ; V_24 < V_93 ; V_24 ++ )
if ( ! V_43 -> V_58 -> V_98 ) {
F_12 ( V_17 , V_96 , V_97 , V_24 , & V_95 ) ;
V_15 -> V_26 [ V_92 ] . V_27 =
F_49 ( V_95 ) ;
if ( V_15 -> V_26 [ V_92 ] . V_27 )
V_15 -> V_26 [ V_92 ++ ] . V_95 = V_95 ;
} else {
V_7 = V_43 -> V_58 -> V_98 ( V_15 , V_24 ,
& V_15 -> V_26 [ V_92 ] ) ;
if ( V_7 < 0 )
goto V_101;
V_92 += V_7 ;
}
V_15 -> V_25 = V_92 ;
V_15 -> V_102 = & V_15 -> V_26 [ 0 ] ;
return 0 ;
V_101:
F_50 ( V_15 -> V_26 ) ;
return V_7 ;
}
static void F_51 ( struct V_14 * V_15 )
{
struct V_42 * V_43 = F_17 ( V_15 -> V_44 ) ;
if ( V_43 -> V_58 -> V_103 )
V_43 -> V_58 -> V_103 ( V_15 ) ;
V_15 -> V_102 = NULL ;
V_15 -> V_25 = 0 ;
F_50 ( V_15 -> V_26 ) ;
V_15 -> V_26 = NULL ;
}
static int F_52 ( struct V_14 * V_15 ,
struct V_41 * V_30 )
{
struct V_42 * V_43 = F_17 ( V_15 -> V_44 ) ;
struct V_46 * V_47 = & V_30 -> V_48 . V_47 ;
int V_7 ;
F_18 ( V_15 -> V_49 , L_9 ,
F_19 ( V_47 -> V_50 ) , V_47 -> V_51 , V_47 -> V_52 ) ;
V_7 = F_16 ( V_15 , V_30 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = V_43 -> V_58 -> V_104 ( V_15 , V_30 ) ;
if ( V_7 < 0 ) {
return V_7 ;
} else if ( ! V_15 -> V_102 ||
V_15 -> V_102 -> V_27 -> V_23 != V_47 -> V_50 ) {
F_3 ( V_15 -> V_49 ,
L_10 ) ;
return - V_60 ;
}
V_15 -> V_105 = V_47 -> V_51 ;
V_15 -> V_106 = V_47 -> V_52 ;
V_15 -> V_56 = V_47 -> V_56 ;
V_15 -> V_57 = V_47 -> V_57 ;
V_15 -> V_107 = V_47 -> V_107 ;
V_15 -> V_108 = V_47 -> V_108 ;
if ( V_43 -> V_58 -> V_82 )
V_15 -> V_83 . V_108 = V_47 -> V_108 ;
F_18 ( V_15 -> V_49 , L_11 ,
V_15 -> V_105 , V_15 -> V_106 ) ;
return V_43 -> V_58 -> V_109 ( V_15 ) ;
}
static int F_53 ( struct V_14 * V_15 )
{
struct V_42 * V_43 = F_17 ( V_15 -> V_44 ) ;
int V_7 ;
if ( V_43 -> V_15 )
return - V_81 ;
if ( ! V_15 -> V_6 ) {
F_54 ( & V_43 -> V_110 ) ;
V_7 = V_43 -> V_58 -> V_111 ( V_43 ) ;
F_55 ( & V_43 -> V_110 ) ;
if ( V_7 < 0 )
return V_7 ;
}
if ( V_43 -> V_58 -> V_112 ) {
V_7 = V_43 -> V_58 -> V_112 ( V_15 ) ;
if ( V_7 < 0 )
goto V_113;
}
V_43 -> V_15 = V_15 ;
return 0 ;
V_113:
if ( ! V_15 -> V_6 ) {
F_54 ( & V_43 -> V_110 ) ;
V_43 -> V_58 -> V_114 ( V_43 ) ;
F_55 ( & V_43 -> V_110 ) ;
}
return V_7 ;
}
static void F_56 ( struct V_14 * V_15 )
{
struct V_42 * V_43 = F_17 ( V_15 -> V_44 ) ;
if ( F_24 ( V_15 != V_43 -> V_15 ) )
return;
if ( V_43 -> V_58 -> remove )
V_43 -> V_58 -> remove ( V_15 ) ;
if ( ! V_15 -> V_6 ) {
F_54 ( & V_43 -> V_110 ) ;
V_43 -> V_58 -> V_114 ( V_43 ) ;
F_55 ( & V_43 -> V_110 ) ;
}
V_43 -> V_15 = NULL ;
}
static int F_57 ( struct V_62 * V_62 )
{
struct V_115 * V_116 = F_58 ( V_62 ) ;
struct V_14 * V_15 ;
struct V_42 * V_43 ;
int V_7 ;
if ( F_59 ( & V_117 ) )
return - V_118 ;
if ( ! V_116 || ! F_60 ( V_116 ) ) {
F_55 ( & V_117 ) ;
return - V_21 ;
}
V_15 = F_61 ( V_116 ) ;
V_43 = F_17 ( V_15 -> V_44 ) ;
V_7 = F_62 ( V_43 -> V_58 -> V_119 ) ? 0 : - V_21 ;
F_55 ( & V_117 ) ;
if ( V_7 < 0 ) {
F_3 ( V_15 -> V_49 , L_12 ) ;
return V_7 ;
}
if ( ! F_63 ( V_15 ) ) {
V_7 = - V_21 ;
goto V_120;
}
if ( F_59 ( & V_43 -> V_121 ) ) {
V_7 = - V_118 ;
goto V_122;
}
V_15 -> V_123 ++ ;
if ( V_15 -> V_123 == 1 ) {
struct V_124 * V_125 = F_64 ( V_15 ) ;
struct V_41 V_30 = {
. type = V_65 ,
. V_48 . V_47 = {
. V_51 = V_15 -> V_105 ,
. V_52 = V_15 -> V_106 ,
. V_108 = V_15 -> V_108 ,
. V_107 = V_15 -> V_107 ,
. V_50 =
V_15 -> V_102 -> V_27 -> V_23 ,
} ,
} ;
if ( V_125 -> V_126 . V_127 )
V_125 -> V_126 . V_127 ( V_15 -> V_49 ) ;
V_7 = F_53 ( V_15 ) ;
if ( V_7 < 0 ) {
F_3 ( V_15 -> V_49 , L_13 , V_7 ) ;
goto V_128;
}
V_7 = F_10 ( V_15 ) ;
if ( V_7 < 0 )
goto V_129;
F_65 ( & V_15 -> V_116 -> V_2 ) ;
V_7 = F_66 ( & V_15 -> V_116 -> V_2 ) ;
if ( V_7 < 0 && V_7 != - V_130 )
goto V_131;
V_7 = F_52 ( V_15 , & V_30 ) ;
if ( V_7 < 0 )
goto V_132;
if ( V_43 -> V_58 -> V_82 ) {
V_43 -> V_58 -> V_82 ( & V_15 -> V_83 , V_15 ) ;
} else {
V_7 = V_43 -> V_58 -> V_133 ( & V_15 -> V_85 , V_15 ) ;
if ( V_7 < 0 )
goto V_134;
}
F_67 ( & V_15 -> V_135 ) ;
}
F_55 ( & V_43 -> V_121 ) ;
V_62 -> V_64 = V_15 ;
F_18 ( V_15 -> V_49 , L_14 ) ;
return 0 ;
V_134:
V_132:
F_68 ( & V_15 -> V_116 -> V_2 ) ;
V_131:
F_13 ( V_15 ) ;
V_129:
F_56 ( V_15 ) ;
V_128:
V_15 -> V_123 -- ;
F_55 ( & V_43 -> V_121 ) ;
V_122:
V_120:
F_69 ( V_43 -> V_58 -> V_119 ) ;
return V_7 ;
}
static int F_70 ( struct V_62 * V_62 )
{
struct V_14 * V_15 = V_62 -> V_64 ;
struct V_42 * V_43 = F_17 ( V_15 -> V_44 ) ;
F_54 ( & V_43 -> V_121 ) ;
V_15 -> V_123 -- ;
if ( ! V_15 -> V_123 ) {
F_71 ( & V_15 -> V_116 -> V_2 ) ;
F_68 ( & V_15 -> V_116 -> V_2 ) ;
if ( V_43 -> V_58 -> V_133 )
F_72 ( & V_15 -> V_85 ) ;
F_13 ( V_15 ) ;
F_56 ( V_15 ) ;
}
if ( V_15 -> V_80 == V_62 )
V_15 -> V_80 = NULL ;
F_55 ( & V_43 -> V_121 ) ;
F_69 ( V_43 -> V_58 -> V_119 ) ;
F_18 ( V_15 -> V_49 , L_15 ) ;
return 0 ;
}
static T_2 F_73 ( struct V_62 * V_62 , char T_3 * V_136 ,
T_4 V_137 , T_5 * V_138 )
{
struct V_14 * V_15 = V_62 -> V_64 ;
struct V_42 * V_43 = F_17 ( V_15 -> V_44 ) ;
F_18 ( V_15 -> V_49 , L_16 , V_136 ) ;
if ( V_43 -> V_58 -> V_133 && V_15 -> V_85 . V_139 & V_140 )
return F_74 ( & V_15 -> V_85 , V_136 , V_137 , V_138 ,
V_62 -> V_87 & V_88 ) ;
F_3 ( V_15 -> V_49 , L_17 ) ;
return - V_60 ;
}
static int F_75 ( struct V_62 * V_62 , struct V_141 * V_142 )
{
struct V_14 * V_15 = V_62 -> V_64 ;
struct V_42 * V_43 = F_17 ( V_15 -> V_44 ) ;
int V_13 ;
F_18 ( V_15 -> V_49 , L_18 , ( unsigned long ) V_142 ) ;
if ( V_15 -> V_80 != V_62 )
return - V_81 ;
if ( F_59 ( & V_43 -> V_121 ) )
return - V_118 ;
if ( V_43 -> V_58 -> V_82 )
V_13 = F_76 ( & V_15 -> V_83 , V_142 ) ;
else
V_13 = F_77 ( & V_15 -> V_85 , V_142 ) ;
F_55 ( & V_43 -> V_121 ) ;
F_18 ( V_15 -> V_49 , L_19 ,
( unsigned long ) V_142 -> V_143 ,
( unsigned long ) V_142 -> V_144 - ( unsigned long ) V_142 -> V_143 ,
V_13 ) ;
return V_13 ;
}
static unsigned int F_78 ( struct V_62 * V_62 , T_6 * V_145 )
{
struct V_14 * V_15 = V_62 -> V_64 ;
struct V_42 * V_43 = F_17 ( V_15 -> V_44 ) ;
unsigned V_146 = V_147 ;
if ( V_15 -> V_80 != V_62 )
return V_147 ;
F_54 ( & V_43 -> V_121 ) ;
if ( V_43 -> V_58 -> V_82 && F_79 ( & V_15 -> V_83 . V_148 ) )
F_3 ( V_15 -> V_49 , L_20 ) ;
else
V_146 = V_43 -> V_58 -> V_149 ( V_62 , V_145 ) ;
F_55 ( & V_43 -> V_121 ) ;
return V_146 ;
}
void F_80 ( struct V_150 * V_151 )
{
struct V_14 * V_15 = F_81 ( V_151 ) ;
struct V_42 * V_43 = F_17 ( V_15 -> V_44 ) ;
F_54 ( & V_43 -> V_121 ) ;
}
void F_82 ( struct V_150 * V_151 )
{
struct V_14 * V_15 = F_81 ( V_151 ) ;
struct V_42 * V_43 = F_17 ( V_15 -> V_44 ) ;
F_55 ( & V_43 -> V_121 ) ;
}
static int F_83 ( struct V_62 * V_62 , void * V_63 ,
struct V_41 * V_30 )
{
struct V_14 * V_15 = V_62 -> V_64 ;
int V_7 ;
F_24 ( V_63 != V_62 -> V_64 ) ;
if ( V_30 -> type != V_65 ) {
F_84 ( V_15 -> V_49 , L_21 , V_30 -> type ) ;
return - V_60 ;
}
if ( V_15 -> V_80 && V_15 -> V_80 != V_62 )
return - V_81 ;
if ( F_85 ( F_17 ( V_15 -> V_44 ) , V_15 ) ) {
F_3 ( V_15 -> V_49 , L_22 ) ;
return - V_81 ;
}
V_7 = F_52 ( V_15 , V_30 ) ;
if ( ! V_7 && ! V_15 -> V_80 )
V_15 -> V_80 = V_62 ;
return V_7 ;
}
static int F_86 ( struct V_62 * V_62 , void * V_63 ,
struct V_152 * V_30 )
{
struct V_14 * V_15 = V_62 -> V_64 ;
const struct V_153 * V_154 ;
F_24 ( V_63 != V_62 -> V_64 ) ;
if ( V_30 -> V_68 >= V_15 -> V_25 )
return - V_60 ;
V_154 = V_15 -> V_26 [ V_30 -> V_68 ] . V_27 ;
if ( V_154 -> V_70 )
F_87 ( V_30 -> V_155 , V_154 -> V_70 , sizeof( V_30 -> V_155 ) ) ;
V_30 -> V_50 = V_154 -> V_23 ;
return 0 ;
}
static int F_88 ( struct V_62 * V_62 , void * V_63 ,
struct V_41 * V_30 )
{
struct V_14 * V_15 = V_62 -> V_64 ;
struct V_46 * V_47 = & V_30 -> V_48 . V_47 ;
F_24 ( V_63 != V_62 -> V_64 ) ;
if ( V_30 -> type != V_65 )
return - V_60 ;
V_47 -> V_51 = V_15 -> V_105 ;
V_47 -> V_52 = V_15 -> V_106 ;
V_47 -> V_56 = V_15 -> V_56 ;
V_47 -> V_57 = V_15 -> V_57 ;
V_47 -> V_108 = V_15 -> V_108 ;
V_47 -> V_50 = V_15 -> V_102 -> V_27 -> V_23 ;
V_47 -> V_107 = V_15 -> V_107 ;
F_18 ( V_15 -> V_49 , L_23 ,
V_15 -> V_102 -> V_27 -> V_23 ) ;
return 0 ;
}
static int F_89 ( struct V_62 * V_62 , void * V_63 ,
struct V_156 * V_157 )
{
struct V_14 * V_15 = V_62 -> V_64 ;
struct V_42 * V_43 = F_17 ( V_15 -> V_44 ) ;
F_24 ( V_63 != V_62 -> V_64 ) ;
F_87 ( V_157 -> V_158 , V_43 -> V_159 , sizeof( V_157 -> V_158 ) ) ;
return V_43 -> V_58 -> V_160 ( V_43 , V_157 ) ;
}
static int F_90 ( struct V_62 * V_62 , void * V_63 ,
enum V_161 V_24 )
{
struct V_14 * V_15 = V_62 -> V_64 ;
struct V_42 * V_43 = F_17 ( V_15 -> V_44 ) ;
struct V_16 * V_17 = F_11 ( V_15 ) ;
int V_7 ;
F_24 ( V_63 != V_62 -> V_64 ) ;
if ( V_24 != V_65 )
return - V_60 ;
if ( V_15 -> V_80 != V_62 )
return - V_81 ;
if ( V_43 -> V_58 -> V_82 )
V_7 = F_91 ( & V_15 -> V_83 ) ;
else
V_7 = F_92 ( & V_15 -> V_85 , V_24 ) ;
if ( ! V_7 )
F_12 ( V_17 , V_96 , V_162 , 1 ) ;
return V_7 ;
}
static int F_93 ( struct V_62 * V_62 , void * V_63 ,
enum V_161 V_24 )
{
struct V_14 * V_15 = V_62 -> V_64 ;
struct V_16 * V_17 = F_11 ( V_15 ) ;
struct V_42 * V_43 = F_17 ( V_15 -> V_44 ) ;
F_24 ( V_63 != V_62 -> V_64 ) ;
if ( V_24 != V_65 )
return - V_60 ;
if ( V_15 -> V_80 != V_62 )
return - V_81 ;
if ( V_43 -> V_58 -> V_82 )
F_94 ( & V_15 -> V_83 ) ;
else
F_95 ( & V_15 -> V_85 , V_24 ) ;
F_12 ( V_17 , V_96 , V_162 , 0 ) ;
return 0 ;
}
static int F_96 ( struct V_62 * V_62 , void * V_74 ,
struct V_163 * V_71 )
{
struct V_14 * V_15 = V_62 -> V_64 ;
struct V_42 * V_43 = F_17 ( V_15 -> V_44 ) ;
return V_43 -> V_58 -> V_164 ( V_15 , V_71 ) ;
}
static int F_97 ( struct V_62 * V_62 , void * V_74 ,
struct V_165 * V_71 )
{
struct V_14 * V_15 = V_62 -> V_64 ;
struct V_42 * V_43 = F_17 ( V_15 -> V_44 ) ;
int V_7 ;
V_7 = V_43 -> V_58 -> V_166 ( V_15 , V_71 ) ;
return V_7 ;
}
static int F_98 ( struct V_62 * V_62 , void * V_74 ,
const struct V_165 * V_71 )
{
struct V_14 * V_15 = V_62 -> V_64 ;
struct V_42 * V_43 = F_17 ( V_15 -> V_44 ) ;
const struct V_167 * V_168 = & V_71 -> V_169 ;
struct V_165 V_170 ;
int V_7 ;
if ( V_71 -> type != V_65 )
return - V_60 ;
F_18 ( V_15 -> V_49 , L_24 ,
V_168 -> V_51 , V_168 -> V_52 , V_168 -> V_171 , V_168 -> V_172 ) ;
V_170 . type = V_71 -> type ;
V_7 = V_43 -> V_58 -> V_166 ( V_15 , & V_170 ) ;
if ( V_7 < 0 ) {
F_3 ( V_15 -> V_49 ,
L_25 ) ;
} else if ( ( V_71 -> V_169 . V_51 == V_170 . V_169 . V_51 &&
V_71 -> V_169 . V_52 == V_170 . V_169 . V_52 ) ||
! F_85 ( V_43 , V_15 ) ) {
V_7 = V_43 -> V_58 -> V_173 ( V_15 , V_71 ) ;
} else if ( V_43 -> V_58 -> V_174 ) {
V_7 = V_43 -> V_58 -> V_174 ( V_15 , V_71 ) ;
} else {
F_3 ( V_15 -> V_49 ,
L_26 ) ;
V_7 = - V_81 ;
}
return V_7 ;
}
static int F_99 ( struct V_62 * V_62 , void * V_74 ,
struct V_175 * V_176 )
{
struct V_14 * V_15 = V_62 -> V_64 ;
struct V_42 * V_43 = F_17 ( V_15 -> V_44 ) ;
if ( V_176 -> type != V_65 )
return - V_60 ;
if ( ! V_43 -> V_58 -> V_177 )
return - V_178 ;
return V_43 -> V_58 -> V_177 ( V_15 , V_176 ) ;
}
static int F_100 ( struct V_62 * V_62 , void * V_74 ,
struct V_175 * V_176 )
{
struct V_14 * V_15 = V_62 -> V_64 ;
struct V_42 * V_43 = F_17 ( V_15 -> V_44 ) ;
int V_7 ;
if ( V_176 -> type != V_65 ||
( V_176 -> V_179 != V_180 &&
V_176 -> V_179 != V_181 ) )
return - V_60 ;
if ( V_176 -> V_179 == V_180 ) {
if ( F_85 ( V_43 , V_15 ) &&
( V_15 -> V_105 != V_176 -> V_182 . V_51 ||
V_15 -> V_106 != V_176 -> V_182 . V_52 ) )
return - V_81 ;
if ( V_15 -> V_80 && V_15 -> V_80 != V_62 )
return - V_81 ;
}
if ( ! V_43 -> V_58 -> V_183 )
return - V_178 ;
V_7 = V_43 -> V_58 -> V_183 ( V_15 , V_176 ) ;
if ( ! V_7 &&
V_176 -> V_179 == V_180 ) {
V_15 -> V_105 = V_176 -> V_182 . V_51 ;
V_15 -> V_106 = V_176 -> V_182 . V_52 ;
if ( ! V_15 -> V_80 )
V_15 -> V_80 = V_62 ;
}
return V_7 ;
}
static int F_101 ( struct V_62 * V_62 , void * V_74 ,
struct V_184 * V_71 )
{
struct V_14 * V_15 = V_62 -> V_64 ;
struct V_42 * V_43 = F_17 ( V_15 -> V_44 ) ;
if ( V_43 -> V_58 -> V_185 )
return V_43 -> V_58 -> V_185 ( V_15 , V_71 ) ;
return - V_20 ;
}
static int F_102 ( struct V_62 * V_62 , void * V_74 ,
struct V_184 * V_71 )
{
struct V_14 * V_15 = V_62 -> V_64 ;
struct V_42 * V_43 = F_17 ( V_15 -> V_44 ) ;
if ( V_43 -> V_58 -> V_186 )
return V_43 -> V_58 -> V_186 ( V_15 , V_71 ) ;
return - V_20 ;
}
static void F_103 ( struct V_42 * V_43 )
{
struct V_14 * V_15 ;
F_54 ( & V_117 ) ;
F_104 (icd, &devices, list)
if ( V_15 -> V_187 == V_43 -> V_188 ) {
struct V_124 * V_125 = F_64 ( V_15 ) ;
struct V_3 * V_4 = & V_125 -> V_126 ;
if ( V_4 -> V_127 )
V_4 -> V_127 ( V_15 -> V_49 ) ;
V_15 -> V_44 = V_43 -> V_189 . V_2 ;
F_105 ( V_43 , V_15 ) ;
}
F_55 ( & V_117 ) ;
}
static int F_106 ( struct V_5 * V_6 )
{
struct V_14 * V_15 = V_6 -> V_63 ;
struct V_42 * V_43 ;
int V_7 ;
if ( ! V_15 || ! V_15 -> V_44 )
return - V_21 ;
V_43 = F_17 ( V_15 -> V_44 ) ;
if ( ! F_62 ( V_43 -> V_58 -> V_119 ) )
return - V_21 ;
F_54 ( & V_43 -> V_110 ) ;
V_7 = V_43 -> V_58 -> V_111 ( V_43 ) ;
F_55 ( & V_43 -> V_110 ) ;
return V_7 ;
}
static void F_107 ( struct V_5 * V_6 )
{
struct V_14 * V_15 = V_6 -> V_63 ;
struct V_42 * V_43 ;
if ( ! V_15 || ! V_15 -> V_44 )
return;
V_43 = F_17 ( V_15 -> V_44 ) ;
F_54 ( & V_43 -> V_110 ) ;
V_43 -> V_58 -> V_114 ( V_43 ) ;
F_55 ( & V_43 -> V_110 ) ;
F_69 ( V_43 -> V_58 -> V_119 ) ;
}
static int F_108 ( struct V_124 * V_125 ,
struct V_190 * V_191 )
{
struct V_192 * V_49 ;
int V_7 , V_24 ;
F_54 ( & V_117 ) ;
V_24 = F_109 ( V_193 , V_194 ) ;
if ( V_24 < V_194 )
F_110 ( V_24 , V_193 ) ;
F_55 ( & V_117 ) ;
if ( V_24 >= V_194 )
return - V_100 ;
V_49 = F_111 ( L_27 , V_24 ) ;
if ( ! V_49 )
return - V_100 ;
V_7 = F_112 ( V_49 , V_125 , sizeof( * V_125 ) ) ;
if ( V_7 < 0 ) {
F_113 ( V_49 ) ;
return V_7 ;
}
V_191 -> V_49 = V_49 ;
return 0 ;
}
static struct V_14 * F_114 ( struct V_190 * V_191 )
{
struct V_192 * V_49 = V_191 -> V_49 ;
int V_7 ;
V_7 = F_115 ( V_49 ) ;
if ( V_7 < 0 || ! V_49 -> V_2 . V_158 )
return NULL ;
return F_116 ( V_49 ) ;
}
static int F_117 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_11 ( V_15 ) ;
struct V_195 V_196 ;
int V_7 ;
V_17 -> V_197 = F_118 ( V_15 ) ;
F_119 ( V_17 , V_15 ) ;
V_7 = F_120 ( & V_15 -> V_135 , V_17 -> V_135 , NULL ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_53 ( V_15 ) ;
if ( V_7 < 0 ) {
F_3 ( V_15 -> V_49 , L_13 , V_7 ) ;
return V_7 ;
}
V_7 = F_47 ( V_15 ) ;
if ( V_7 < 0 )
goto V_198;
V_15 -> V_108 = V_199 ;
V_7 = F_121 ( V_15 ) ;
if ( V_7 < 0 )
goto V_200;
if ( ! F_12 ( V_17 , V_96 , V_201 , & V_196 ) ) {
V_15 -> V_105 = V_196 . V_51 ;
V_15 -> V_106 = V_196 . V_52 ;
V_15 -> V_107 = V_196 . V_107 ;
V_15 -> V_108 = V_196 . V_108 ;
}
F_56 ( V_15 ) ;
return 0 ;
V_200:
F_51 ( V_15 ) ;
V_198:
F_56 ( V_15 ) ;
return V_7 ;
}
static int F_122 ( struct V_14 * V_15 ,
struct V_124 * V_125 )
{
struct V_3 * V_4 ;
struct V_202 * V_203 ;
struct V_42 * V_43 ;
struct V_204 * V_205 = & V_125 -> V_206 ;
struct V_207 * V_208 ;
struct V_16 * V_209 ;
char V_210 [ V_211 ] ;
int V_7 ;
if ( V_15 -> V_191 ) {
return - V_212 ;
}
V_43 = F_17 ( V_15 -> V_44 ) ;
V_208 = F_123 ( V_205 -> V_213 ) ;
if ( ! V_208 ) {
F_3 ( V_15 -> V_49 , L_28 ,
V_205 -> V_213 ) ;
return - V_21 ;
}
V_4 = F_124 ( sizeof( * V_4 ) , V_214 ) ;
if ( ! V_4 ) {
V_7 = - V_100 ;
goto V_215;
}
memcpy ( V_4 , & V_125 -> V_126 , sizeof( * V_4 ) ) ;
V_4 -> V_8 = 0 ;
V_4 -> V_9 = NULL ;
V_205 -> V_216 -> V_217 = V_4 ;
snprintf ( V_210 , sizeof( V_210 ) , L_29 ,
V_205 -> V_213 , V_205 -> V_216 -> V_218 ) ;
V_15 -> V_6 = F_125 ( & V_219 , V_210 , L_30 , V_15 ) ;
if ( F_126 ( V_15 -> V_6 ) ) {
V_7 = F_127 ( V_15 -> V_6 ) ;
goto V_220;
}
V_209 = F_128 ( & V_43 -> V_189 , V_208 ,
V_205 -> V_216 , NULL ) ;
if ( ! V_209 ) {
V_7 = - V_21 ;
goto V_221;
}
V_203 = F_129 ( V_209 ) ;
V_15 -> V_222 = & V_203 -> V_2 ;
return 0 ;
V_221:
F_130 ( V_15 -> V_6 ) ;
V_15 -> V_6 = NULL ;
V_220:
F_131 ( V_4 ) ;
V_215:
F_132 ( V_208 ) ;
return V_7 ;
}
static void F_133 ( struct V_14 * V_15 )
{
struct V_202 * V_203 =
F_134 ( F_63 ( V_15 ) ) ;
struct V_207 * V_208 ;
struct V_3 * V_4 ;
V_15 -> V_222 = NULL ;
if ( V_15 -> V_191 )
return;
V_208 = V_203 -> V_223 ;
V_4 = V_203 -> V_2 . V_217 ;
F_135 ( F_136 ( V_203 ) ) ;
F_137 ( V_203 ) ;
F_132 ( V_208 ) ;
F_131 ( V_4 ) ;
F_130 ( V_15 -> V_6 ) ;
V_15 -> V_6 = NULL ;
}
static int F_138 ( struct V_224 * V_225 ,
struct V_16 * V_17 ,
struct V_226 * V_227 )
{
struct V_190 * V_191 = F_139 ( V_225 ,
struct V_190 , V_225 ) ;
struct V_14 * V_15 = F_116 ( V_191 -> V_49 ) ;
if ( V_227 == V_191 -> V_228 && ! F_24 ( V_15 -> V_222 ) ) {
struct V_202 * V_203 = F_129 ( V_17 ) ;
if ( V_203 ) {
struct V_124 * V_125 = F_64 ( V_15 ) ;
struct V_3 * V_4 =
F_140 ( V_203 ) ;
if ( V_4 ) {
memcpy ( & V_125 -> V_126 , V_4 ,
sizeof( V_125 -> V_126 ) ) ;
if ( V_4 -> V_127 )
V_4 -> V_127 ( V_15 -> V_49 ) ;
}
V_15 -> V_222 = & V_203 -> V_2 ;
}
}
return 0 ;
}
static void F_141 ( struct V_224 * V_225 ,
struct V_16 * V_17 ,
struct V_226 * V_227 )
{
struct V_190 * V_191 = F_139 ( V_225 ,
struct V_190 , V_225 ) ;
struct V_14 * V_15 = F_116 ( V_191 -> V_49 ) ;
if ( V_15 -> V_6 ) {
F_130 ( V_15 -> V_6 ) ;
V_15 -> V_6 = NULL ;
}
}
static int F_142 ( struct V_224 * V_225 )
{
struct V_190 * V_191 = F_139 ( V_225 ,
struct V_190 , V_225 ) ;
struct V_14 * V_15 = F_116 ( V_191 -> V_49 ) ;
if ( F_63 ( V_15 ) ) {
struct V_42 * V_43 = F_17 ( V_15 -> V_44 ) ;
int V_7 ;
F_54 ( & V_117 ) ;
V_7 = F_105 ( V_43 , V_15 ) ;
F_55 ( & V_117 ) ;
if ( V_7 < 0 )
return V_7 ;
}
return 0 ;
}
static int F_143 ( struct V_42 * V_43 ,
struct V_226 * * V_227 , unsigned int V_229 )
{
struct V_230 * V_231 ;
struct V_190 * V_191 ;
struct V_14 * V_15 ;
struct V_124 V_125 = { . V_206 . V_232 = V_43 -> V_188 ,} ;
char V_210 [ V_211 ] ;
unsigned int V_24 ;
int V_7 ;
for ( V_24 = 0 ; V_24 < V_229 ; V_24 ++ ) {
V_231 = F_139 ( V_227 [ V_24 ] , struct V_230 , V_227 ) ;
if ( V_231 -> V_233 == V_234 )
break;
}
if ( V_24 >= V_229 || V_227 [ V_24 ] -> V_235 != V_236 ) {
F_3 ( V_43 -> V_189 . V_2 , L_31 ) ;
return - V_21 ;
}
V_191 = F_144 ( V_43 -> V_189 . V_2 , sizeof( * V_191 ) , V_214 ) ;
if ( ! V_191 )
return - V_100 ;
V_125 . V_206 . V_216 = F_145 ( - V_237 ) ;
V_7 = F_108 ( & V_125 , V_191 ) ;
if ( V_7 < 0 )
return V_7 ;
V_191 -> V_228 = & V_231 -> V_227 ;
V_15 = F_114 ( V_191 ) ;
if ( ! V_15 ) {
F_113 ( V_191 -> V_49 ) ;
return - V_100 ;
}
V_191 -> V_225 . V_238 = V_227 ;
V_191 -> V_225 . V_239 = V_229 ;
V_191 -> V_225 . V_240 = F_138 ;
V_191 -> V_225 . V_241 = F_141 ;
V_191 -> V_225 . V_242 = F_142 ;
V_15 -> V_191 = V_191 ;
V_15 -> V_44 = V_43 -> V_189 . V_2 ;
snprintf ( V_210 , sizeof( V_210 ) , L_29 ,
V_231 -> V_227 . V_243 . V_244 . V_245 , V_231 -> V_227 . V_243 . V_244 . V_246 ) ;
V_15 -> V_6 = F_125 ( & V_219 , V_210 , L_30 , V_15 ) ;
if ( F_126 ( V_15 -> V_6 ) ) {
V_7 = F_127 ( V_15 -> V_6 ) ;
goto V_220;
}
V_7 = F_146 ( & V_43 -> V_189 , & V_191 -> V_225 ) ;
if ( ! V_7 )
return 0 ;
F_130 ( V_15 -> V_6 ) ;
V_220:
V_15 -> V_6 = NULL ;
F_147 ( V_191 -> V_49 ) ;
F_3 ( V_43 -> V_189 . V_2 , L_32 , V_7 ) ;
return V_7 ;
}
static void F_148 ( struct V_42 * V_43 )
{
struct V_226 * * V_227 ;
int V_247 ;
for ( V_247 = 0 , V_227 = V_43 -> V_227 ; V_43 -> V_248 [ V_247 ] ; V_247 ++ ) {
F_143 ( V_43 , V_227 , V_43 -> V_248 [ V_247 ] ) ;
V_227 += V_43 -> V_248 [ V_247 ] ;
}
}
static int F_105 ( struct V_42 * V_43 ,
struct V_14 * V_15 )
{
struct V_124 * V_125 = F_64 ( V_15 ) ;
struct V_204 * V_205 = & V_125 -> V_206 ;
struct V_1 * V_222 = NULL ;
int V_7 ;
F_149 ( V_15 -> V_49 , L_33 , F_150 ( V_15 -> V_49 ) ) ;
V_7 = F_151 ( & V_15 -> V_135 , 16 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_152 ( V_15 ) ;
if ( V_7 < 0 )
goto V_249;
if ( V_205 -> V_216 ) {
V_7 = F_122 ( V_15 , V_125 ) ;
if ( V_7 < 0 && V_7 != - V_212 )
goto V_113;
} else if ( ! V_205 -> V_250 || ! V_205 -> V_251 ) {
V_7 = - V_60 ;
goto V_113;
} else {
F_54 ( & V_43 -> V_110 ) ;
V_7 = V_43 -> V_58 -> V_111 ( V_43 ) ;
F_55 ( & V_43 -> V_110 ) ;
if ( V_7 < 0 )
goto V_113;
if ( V_205 -> V_252 )
V_7 = F_153 ( V_205 -> V_252 ) ;
V_7 = V_205 -> V_250 ( V_15 ) ;
if ( V_7 < 0 )
goto V_253;
V_222 = F_63 ( V_15 ) ;
if ( ! V_222 || ! V_222 -> V_158 || ! F_154 ( V_222 ) ||
! F_62 ( V_222 -> V_158 -> V_119 ) ) {
V_205 -> V_251 ( V_15 ) ;
V_7 = - V_21 ;
goto V_254;
}
}
F_54 ( & V_43 -> V_121 ) ;
V_7 = F_117 ( V_15 ) ;
F_55 ( & V_43 -> V_121 ) ;
if ( V_7 < 0 )
goto V_255;
return 0 ;
V_255:
if ( V_205 -> V_216 ) {
F_133 ( V_15 ) ;
} else {
V_205 -> V_251 ( V_15 ) ;
F_69 ( V_222 -> V_158 -> V_119 ) ;
V_254:
V_253:
F_54 ( & V_43 -> V_110 ) ;
V_43 -> V_58 -> V_114 ( V_43 ) ;
F_55 ( & V_43 -> V_110 ) ;
}
V_113:
F_155 ( V_15 -> V_116 ) ;
V_15 -> V_116 = NULL ;
if ( V_15 -> V_116 ) {
F_155 ( V_15 -> V_116 ) ;
V_15 -> V_116 = NULL ;
}
V_249:
F_156 ( & V_15 -> V_135 ) ;
return V_7 ;
}
static int F_157 ( struct V_14 * V_15 )
{
struct V_124 * V_125 = F_64 ( V_15 ) ;
struct V_115 * V_116 = V_15 -> V_116 ;
F_156 ( & V_15 -> V_135 ) ;
if ( V_116 ) {
F_158 ( V_116 ) ;
V_15 -> V_116 = NULL ;
}
if ( V_125 -> V_206 . V_216 ) {
F_133 ( V_15 ) ;
} else {
struct V_1 * V_2 = F_63 ( V_15 ) ;
struct V_256 * V_257 = V_2 ? V_2 -> V_158 : NULL ;
if ( V_257 ) {
V_125 -> V_206 . V_251 ( V_15 ) ;
F_69 ( V_257 -> V_119 ) ;
}
}
if ( V_15 -> V_25 )
F_51 ( V_15 ) ;
if ( V_15 -> V_6 ) {
F_130 ( V_15 -> V_6 ) ;
V_15 -> V_6 = NULL ;
}
if ( V_15 -> V_191 )
F_147 ( V_15 -> V_191 -> V_49 ) ;
return 0 ;
}
static int F_159 ( struct V_14 * V_15 ,
struct V_163 * V_71 )
{
struct V_16 * V_17 = F_11 ( V_15 ) ;
return F_12 ( V_17 , V_96 , V_164 , V_71 ) ;
}
static int F_160 ( struct V_14 * V_15 , struct V_165 * V_71 )
{
struct V_16 * V_17 = F_11 ( V_15 ) ;
return F_12 ( V_17 , V_96 , V_258 , V_71 ) ;
}
static int F_161 ( struct V_14 * V_15 , const struct V_165 * V_71 )
{
struct V_16 * V_17 = F_11 ( V_15 ) ;
return F_12 ( V_17 , V_96 , V_259 , V_71 ) ;
}
static int F_162 ( struct V_14 * V_15 ,
struct V_184 * V_260 )
{
struct V_16 * V_17 = F_11 ( V_15 ) ;
return F_12 ( V_17 , V_96 , V_261 , V_260 ) ;
}
static int F_163 ( struct V_14 * V_15 ,
struct V_184 * V_260 )
{
struct V_16 * V_17 = F_11 ( V_15 ) ;
return F_12 ( V_17 , V_96 , V_262 , V_260 ) ;
}
static int F_164 ( struct V_14 * V_15 ,
struct V_75 * V_76 )
{
int V_7 ;
struct V_16 * V_17 = F_11 ( V_15 ) ;
const struct V_22 * V_45 ;
T_7 V_263 = V_76 -> V_264 ;
struct V_75 V_265 = * V_76 ;
V_45 = F_14 ( V_15 , V_263 ) ;
if ( ! V_45 )
return - V_60 ;
V_265 . V_264 = V_45 -> V_95 ;
V_7 = F_12 ( V_17 , V_96 , V_77 , & V_265 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_76 = V_265 ;
V_76 -> V_264 = V_263 ;
return 0 ;
}
int F_165 ( struct V_42 * V_43 )
{
struct V_42 * V_266 ;
int V_7 ;
if ( ! V_43 || ! V_43 -> V_58 ||
! V_43 -> V_58 -> V_59 ||
! V_43 -> V_58 -> V_104 ||
! V_43 -> V_58 -> V_109 ||
! V_43 -> V_58 -> V_160 ||
( ( ! V_43 -> V_58 -> V_82 ||
! V_43 -> V_58 -> V_84 ) &&
! V_43 -> V_58 -> V_133 ) ||
! V_43 -> V_58 -> V_111 ||
! V_43 -> V_58 -> V_114 ||
! V_43 -> V_58 -> V_149 ||
! V_43 -> V_189 . V_2 )
return - V_60 ;
if ( ! V_43 -> V_58 -> V_173 )
V_43 -> V_58 -> V_173 = F_161 ;
if ( ! V_43 -> V_58 -> V_166 )
V_43 -> V_58 -> V_166 = F_160 ;
if ( ! V_43 -> V_58 -> V_164 )
V_43 -> V_58 -> V_164 = F_159 ;
if ( ! V_43 -> V_58 -> V_186 )
V_43 -> V_58 -> V_186 = F_163 ;
if ( ! V_43 -> V_58 -> V_185 )
V_43 -> V_58 -> V_185 = F_162 ;
if ( ! V_43 -> V_58 -> V_77 )
V_43 -> V_58 -> V_77 = F_164 ;
F_54 ( & V_117 ) ;
F_104 (ix, &hosts, list) {
if ( V_266 -> V_188 == V_43 -> V_188 ) {
V_7 = - V_81 ;
goto V_267;
}
}
V_7 = F_166 ( V_43 -> V_189 . V_2 , & V_43 -> V_189 ) ;
if ( V_7 < 0 )
goto V_267;
F_167 ( & V_43 -> V_268 , & V_269 ) ;
F_55 ( & V_117 ) ;
F_168 ( & V_43 -> V_121 ) ;
F_168 ( & V_43 -> V_110 ) ;
if ( V_43 -> V_248 )
F_148 ( V_43 ) ;
else
F_103 ( V_43 ) ;
return 0 ;
V_267:
F_55 ( & V_117 ) ;
return V_7 ;
}
void F_169 ( struct V_42 * V_43 )
{
struct V_14 * V_15 , * V_270 ;
struct V_190 * V_191 ;
F_170 ( V_271 ) ;
F_54 ( & V_117 ) ;
F_171 ( & V_43 -> V_268 ) ;
F_104 (icd, &devices, list)
if ( V_15 -> V_187 == V_43 -> V_188 && V_15 -> V_191 ) {
F_172 ( V_15 -> V_49 ) ;
F_173 ( & V_15 -> V_191 -> V_268 , & V_271 ) ;
}
F_55 ( & V_117 ) ;
F_104 (sasc, &notifiers, list) {
F_174 ( & V_191 -> V_225 ) ;
F_175 ( & V_191 -> V_49 -> V_2 ) ;
}
F_54 ( & V_117 ) ;
F_176 (icd, tmp, &devices, list)
if ( V_15 -> V_187 == V_43 -> V_188 )
F_157 ( V_15 ) ;
F_55 ( & V_117 ) ;
F_177 ( & V_43 -> V_189 ) ;
}
static int F_178 ( struct V_14 * V_15 )
{
struct V_14 * V_266 ;
int V_272 = - 1 , V_24 ;
F_54 ( & V_117 ) ;
for ( V_24 = 0 ; V_24 < 256 && V_272 < 0 ; V_24 ++ ) {
V_272 = V_24 ;
F_104 (ix, &devices, list) {
if ( V_266 -> V_187 == V_15 -> V_187 && V_266 -> V_273 == V_24 ) {
V_272 = - 1 ;
break;
}
}
}
if ( V_272 < 0 ) {
F_55 ( & V_117 ) ;
return - V_100 ;
}
V_15 -> V_273 = V_272 ;
V_15 -> V_123 = 0 ;
V_15 -> V_274 = NULL ;
V_24 = F_179 ( V_15 -> V_49 ) -> V_275 ;
if ( V_24 < 0 )
V_24 = 0 ;
if ( V_24 >= V_194 ) {
F_55 ( & V_117 ) ;
return - V_81 ;
}
F_110 ( V_24 , V_193 ) ;
F_167 ( & V_15 -> V_268 , & V_276 ) ;
F_55 ( & V_117 ) ;
return 0 ;
}
static int F_152 ( struct V_14 * V_15 )
{
struct V_42 * V_43 = F_17 ( V_15 -> V_44 ) ;
struct V_115 * V_116 = F_180 () ;
if ( ! V_116 )
return - V_100 ;
F_87 ( V_116 -> V_70 , V_43 -> V_159 , sizeof( V_116 -> V_70 ) ) ;
V_116 -> V_189 = & V_43 -> V_189 ;
V_116 -> V_277 = & V_278 ;
V_116 -> V_279 = & V_280 ;
V_116 -> V_281 = F_155 ;
V_116 -> V_135 = & V_15 -> V_135 ;
V_116 -> V_282 = & V_43 -> V_121 ;
V_15 -> V_116 = V_116 ;
return 0 ;
}
static int F_121 ( struct V_14 * V_15 )
{
const struct V_283 * type = V_15 -> V_116 -> V_2 . type ;
int V_7 ;
if ( ! V_15 -> V_44 )
return - V_21 ;
F_181 ( V_15 -> V_116 , V_15 ) ;
V_7 = F_182 ( V_15 -> V_116 , V_284 , - 1 ) ;
if ( V_7 < 0 ) {
F_3 ( V_15 -> V_49 , L_34 , V_7 ) ;
return V_7 ;
}
V_15 -> V_116 -> V_2 . type = type ;
return 0 ;
}
static int F_183 ( struct V_192 * V_49 )
{
struct V_124 * V_125 = V_49 -> V_2 . V_217 ;
struct V_3 * V_4 = & V_125 -> V_126 ;
struct V_14 * V_15 ;
int V_7 ;
if ( ! V_125 )
return - V_60 ;
V_15 = F_144 ( & V_49 -> V_2 , sizeof( * V_15 ) , V_214 ) ;
if ( ! V_15 )
return - V_100 ;
V_7 = F_9 ( & V_49 -> V_2 , V_4 -> V_8 ,
V_4 -> V_9 ) ;
if ( V_7 < 0 )
return V_7 ;
V_15 -> V_187 = V_125 -> V_206 . V_232 ;
V_15 -> V_125 = V_125 ;
V_15 -> V_49 = & V_49 -> V_2 ;
F_184 ( V_49 , V_15 ) ;
V_15 -> V_105 = V_285 ;
V_15 -> V_106 = V_286 ;
return F_178 ( V_15 ) ;
}
static int F_185 ( struct V_192 * V_49 )
{
struct V_14 * V_15 = F_116 ( V_49 ) ;
int V_24 ;
if ( ! V_15 )
return - V_60 ;
V_24 = V_49 -> V_275 ;
if ( V_24 < 0 )
V_24 = 0 ;
if ( F_186 ( V_24 , V_193 ) ) {
F_187 ( V_24 , V_193 ) ;
F_171 ( & V_15 -> V_268 ) ;
}
return 0 ;
}

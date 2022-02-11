static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 = F_3 ( V_4 -> V_8 ,
V_4 -> V_9 ) ;
if ( V_7 < 0 ) {
F_4 ( V_2 -> V_10 , L_1 ) ;
return V_7 ;
}
if ( V_4 -> V_11 ) {
V_7 = V_4 -> V_11 ( V_2 -> V_10 , 1 ) ;
if ( V_7 < 0 ) {
F_4 ( V_2 -> V_10 ,
L_2 ) ;
goto V_12;
}
}
V_7 = F_5 ( V_6 , V_13 , V_14 , 1 ) ;
if ( V_7 < 0 && V_7 != - V_15 && V_7 != - V_16 )
goto V_17;
return 0 ;
V_17:
if ( V_4 -> V_11 )
V_4 -> V_11 ( V_2 -> V_10 , 0 ) ;
V_12:
F_6 ( V_4 -> V_8 ,
V_4 -> V_9 ) ;
return V_7 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 = F_5 ( V_6 , V_13 , V_14 , 0 ) ;
if ( V_7 < 0 && V_7 != - V_15 && V_7 != - V_16 )
return V_7 ;
if ( V_4 -> V_11 ) {
V_7 = V_4 -> V_11 ( V_2 -> V_10 , 0 ) ;
if ( V_7 < 0 ) {
F_4 ( V_2 -> V_10 ,
L_3 ) ;
return V_7 ;
}
}
V_7 = F_6 ( V_4 -> V_8 ,
V_4 -> V_9 ) ;
if ( V_7 < 0 )
F_4 ( V_2 -> V_10 , L_4 ) ;
return V_7 ;
}
const struct V_18 * F_8 (
struct V_1 * V_2 , unsigned int V_19 )
{
unsigned int V_20 ;
for ( V_20 = 0 ; V_20 < V_2 -> V_21 ; V_20 ++ )
if ( V_2 -> V_22 [ V_20 ] . V_23 -> V_19 == V_19 )
return V_2 -> V_22 + V_20 ;
return NULL ;
}
unsigned long F_9 ( struct V_3 * V_4 ,
const struct V_24 * V_25 )
{
unsigned long V_26 , V_27 = V_25 -> V_27 ;
if ( V_4 -> V_27 & V_28 ) {
V_26 = V_27 & ( V_29 | V_30 ) ;
if ( V_26 == V_29 || V_26 == V_30 )
V_27 ^= V_29 | V_30 ;
}
if ( V_4 -> V_27 & V_31 ) {
V_26 = V_27 & ( V_32 | V_33 ) ;
if ( V_26 == V_32 || V_26 == V_33 )
V_27 ^= V_32 | V_33 ;
}
if ( V_4 -> V_27 & V_34 ) {
V_26 = V_27 & ( V_35 | V_36 ) ;
if ( V_26 == V_35 || V_26 == V_36 )
V_27 ^= V_35 | V_36 ;
}
return V_27 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_37 * V_26 )
{
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
struct V_41 * V_42 = & V_26 -> V_43 . V_42 ;
int V_7 ;
F_12 ( V_2 -> V_10 , L_5 ,
F_13 ( V_42 -> V_44 ) , V_42 -> V_45 , V_42 -> V_46 ) ;
V_42 -> V_47 = 0 ;
V_42 -> V_48 = 0 ;
V_7 = V_39 -> V_49 -> V_50 ( V_2 , V_26 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( ! V_42 -> V_48 ) {
if ( ! V_42 -> V_47 ) {
const struct V_18 * V_51 ;
V_51 = F_8 ( V_2 , V_42 -> V_44 ) ;
if ( ! V_51 )
return - V_52 ;
V_7 = F_14 ( V_42 -> V_45 ,
V_51 -> V_23 ) ;
if ( V_7 > 0 )
V_42 -> V_47 = V_7 ;
}
if ( V_42 -> V_47 )
V_42 -> V_48 = V_42 -> V_47 * V_42 -> V_46 ;
}
return 0 ;
}
static int F_15 ( struct V_53 * V_53 , void * V_54 ,
struct V_37 * V_26 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
F_16 ( V_54 != V_53 -> V_55 ) ;
if ( V_26 -> type != V_56 )
return - V_52 ;
return F_10 ( V_2 , V_26 ) ;
}
static int F_17 ( struct V_53 * V_53 , void * V_54 ,
struct V_57 * V_58 )
{
if ( V_58 -> V_59 != 0 )
return - V_52 ;
V_58 -> type = V_60 ;
V_58 -> V_61 = V_62 ;
strcpy ( V_58 -> V_63 , L_6 ) ;
return 0 ;
}
static int F_18 ( struct V_53 * V_53 , void * V_54 , unsigned int * V_20 )
{
* V_20 = 0 ;
return 0 ;
}
static int F_19 ( struct V_53 * V_53 , void * V_54 , unsigned int V_20 )
{
if ( V_20 > 0 )
return - V_52 ;
return 0 ;
}
static int F_20 ( struct V_53 * V_53 , void * V_54 , T_1 * V_64 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_5 ( V_6 , V_13 , V_65 , * V_64 ) ;
}
static int F_21 ( struct V_53 * V_53 , void * V_54 , T_1 * V_64 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_5 ( V_6 , V_13 , V_66 , V_64 ) ;
}
static int F_22 ( struct V_53 * V_53 , void * V_67 ,
struct V_68 * V_69 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
return V_39 -> V_49 -> V_70 ( V_2 , V_69 ) ;
}
static int F_23 ( struct V_53 * V_53 , void * V_54 ,
struct V_71 * V_72 )
{
int V_7 ;
struct V_1 * V_2 = V_53 -> V_55 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
F_16 ( V_54 != V_53 -> V_55 ) ;
if ( V_2 -> V_73 && V_2 -> V_73 != V_53 )
return - V_74 ;
if ( V_39 -> V_49 -> V_75 ) {
V_7 = F_24 ( & V_2 -> V_76 , V_72 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = V_39 -> V_49 -> V_77 ( V_2 , V_72 ) ;
} else {
V_7 = F_25 ( & V_2 -> V_78 , V_72 ) ;
}
if ( ! V_7 && ! V_2 -> V_73 )
V_2 -> V_73 = V_53 ;
return V_7 ;
}
static int F_26 ( struct V_53 * V_53 , void * V_54 ,
struct V_79 * V_72 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
F_16 ( V_54 != V_53 -> V_55 ) ;
if ( V_39 -> V_49 -> V_75 )
return F_27 ( & V_2 -> V_76 , V_72 ) ;
else
return F_28 ( & V_2 -> V_78 , V_72 ) ;
}
static int F_29 ( struct V_53 * V_53 , void * V_54 ,
struct V_79 * V_72 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
F_16 ( V_54 != V_53 -> V_55 ) ;
if ( V_2 -> V_73 != V_53 )
return - V_74 ;
if ( V_39 -> V_49 -> V_75 )
return F_30 ( & V_2 -> V_76 , V_72 ) ;
else
return F_31 ( & V_2 -> V_78 , V_72 ) ;
}
static int F_32 ( struct V_53 * V_53 , void * V_54 ,
struct V_79 * V_72 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
F_16 ( V_54 != V_53 -> V_55 ) ;
if ( V_2 -> V_73 != V_53 )
return - V_74 ;
if ( V_39 -> V_49 -> V_75 )
return F_33 ( & V_2 -> V_76 , V_72 , V_53 -> V_80 & V_81 ) ;
else
return F_34 ( & V_2 -> V_78 , V_72 , V_53 -> V_80 & V_81 ) ;
}
static int F_35 ( struct V_53 * V_53 , void * V_54 ,
struct V_82 * V_83 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
if ( V_39 -> V_49 -> V_75 )
return - V_52 ;
else
return F_36 ( & V_2 -> V_78 , V_83 ) ;
}
static int F_37 ( struct V_53 * V_53 , void * V_54 ,
struct V_79 * V_84 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
if ( V_39 -> V_49 -> V_75 )
return - V_52 ;
else
return F_38 ( & V_2 -> V_78 , V_84 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
unsigned int V_20 , V_85 = 0 , V_86 = 0 ;
int V_7 ;
enum V_87 V_88 ;
while ( ! F_5 ( V_6 , V_89 , V_90 , V_86 , & V_88 ) )
V_86 ++ ;
if ( ! V_39 -> V_49 -> V_91 )
V_85 = V_86 ;
else
for ( V_20 = 0 ; V_20 < V_86 ; V_20 ++ ) {
V_7 = V_39 -> V_49 -> V_91 ( V_2 , V_20 , NULL ) ;
if ( V_7 < 0 )
return V_7 ;
V_85 += V_7 ;
}
if ( ! V_85 )
return - V_92 ;
V_2 -> V_22 =
F_40 ( V_85 * sizeof( struct V_18 ) ) ;
if ( ! V_2 -> V_22 )
return - V_93 ;
F_12 ( V_2 -> V_10 , L_7 , V_85 ) ;
V_85 = 0 ;
for ( V_20 = 0 ; V_20 < V_86 ; V_20 ++ )
if ( ! V_39 -> V_49 -> V_91 ) {
F_5 ( V_6 , V_89 , V_90 , V_20 , & V_88 ) ;
V_2 -> V_22 [ V_85 ] . V_23 =
F_41 ( V_88 ) ;
if ( V_2 -> V_22 [ V_85 ] . V_23 )
V_2 -> V_22 [ V_85 ++ ] . V_88 = V_88 ;
} else {
V_7 = V_39 -> V_49 -> V_91 ( V_2 , V_20 ,
& V_2 -> V_22 [ V_85 ] ) ;
if ( V_7 < 0 )
goto V_94;
V_85 += V_7 ;
}
V_2 -> V_21 = V_85 ;
V_2 -> V_95 = & V_2 -> V_22 [ 0 ] ;
return 0 ;
V_94:
F_42 ( V_2 -> V_22 ) ;
return V_7 ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
if ( V_39 -> V_49 -> V_96 )
V_39 -> V_49 -> V_96 ( V_2 ) ;
V_2 -> V_95 = NULL ;
V_2 -> V_21 = 0 ;
F_42 ( V_2 -> V_22 ) ;
V_2 -> V_22 = NULL ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_37 * V_26 )
{
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
struct V_41 * V_42 = & V_26 -> V_43 . V_42 ;
int V_7 ;
F_12 ( V_2 -> V_10 , L_8 ,
F_13 ( V_42 -> V_44 ) , V_42 -> V_45 , V_42 -> V_46 ) ;
V_7 = F_10 ( V_2 , V_26 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = V_39 -> V_49 -> V_97 ( V_2 , V_26 ) ;
if ( V_7 < 0 ) {
return V_7 ;
} else if ( ! V_2 -> V_95 ||
V_2 -> V_95 -> V_23 -> V_19 != V_42 -> V_44 ) {
F_4 ( V_2 -> V_10 ,
L_9 ) ;
return - V_52 ;
}
V_2 -> V_98 = V_42 -> V_45 ;
V_2 -> V_99 = V_42 -> V_46 ;
V_2 -> V_47 = V_42 -> V_47 ;
V_2 -> V_48 = V_42 -> V_48 ;
V_2 -> V_100 = V_42 -> V_100 ;
V_2 -> V_101 = V_42 -> V_101 ;
if ( V_39 -> V_49 -> V_75 )
V_2 -> V_76 . V_101 = V_42 -> V_101 ;
F_12 ( V_2 -> V_10 , L_10 ,
V_2 -> V_98 , V_2 -> V_99 ) ;
return V_39 -> V_49 -> V_102 ( V_2 ) ;
}
static int F_45 ( struct V_53 * V_53 )
{
struct V_103 * V_104 = F_46 ( V_53 ) ;
struct V_1 * V_2 = F_47 ( V_104 -> V_40 ) ;
struct V_3 * V_4 = F_48 ( V_2 ) ;
struct V_38 * V_39 ;
int V_7 ;
if ( ! F_49 ( V_2 ) )
return - V_16 ;
V_39 = F_11 ( V_2 -> V_40 ) ;
if ( ! F_50 ( V_39 -> V_49 -> V_105 ) ) {
F_4 ( V_2 -> V_10 , L_11 ) ;
return - V_52 ;
}
V_2 -> V_106 ++ ;
if ( V_2 -> V_106 == 1 ) {
struct V_37 V_26 = {
. type = V_56 ,
. V_43 . V_42 = {
. V_45 = V_2 -> V_98 ,
. V_46 = V_2 -> V_99 ,
. V_101 = V_2 -> V_101 ,
. V_100 = V_2 -> V_100 ,
. V_44 =
V_2 -> V_95 -> V_23 -> V_19 ,
} ,
} ;
if ( V_4 -> V_107 )
V_4 -> V_107 ( V_2 -> V_10 ) ;
F_51 ( & V_39 -> V_108 ) ;
V_7 = V_39 -> V_49 -> V_109 ( V_2 ) ;
F_52 ( & V_39 -> V_108 ) ;
if ( V_7 < 0 ) {
F_4 ( V_2 -> V_10 , L_12 , V_7 ) ;
goto V_110;
}
V_7 = F_1 ( V_2 , V_4 ) ;
if ( V_7 < 0 )
goto V_111;
F_53 ( & V_2 -> V_104 -> V_112 ) ;
V_7 = F_54 ( & V_2 -> V_104 -> V_112 ) ;
if ( V_7 < 0 && V_7 != - V_113 )
goto V_114;
V_7 = F_44 ( V_2 , & V_26 ) ;
if ( V_7 < 0 )
goto V_115;
if ( V_39 -> V_49 -> V_75 ) {
V_39 -> V_49 -> V_75 ( & V_2 -> V_76 , V_2 ) ;
} else {
V_7 = V_39 -> V_49 -> V_116 ( & V_2 -> V_78 , V_2 ) ;
if ( V_7 < 0 )
goto V_117;
}
F_55 ( & V_2 -> V_118 ) ;
}
V_53 -> V_55 = V_2 ;
F_12 ( V_2 -> V_10 , L_13 ) ;
return 0 ;
V_117:
V_115:
F_56 ( & V_2 -> V_104 -> V_112 ) ;
V_114:
F_7 ( V_2 , V_4 ) ;
V_111:
V_39 -> V_49 -> remove ( V_2 ) ;
V_110:
V_2 -> V_106 -- ;
F_57 ( V_39 -> V_49 -> V_105 ) ;
return V_7 ;
}
static int F_58 ( struct V_53 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
V_2 -> V_106 -- ;
if ( ! V_2 -> V_106 ) {
struct V_3 * V_4 = F_48 ( V_2 ) ;
F_59 ( & V_2 -> V_104 -> V_112 ) ;
F_56 ( & V_2 -> V_104 -> V_112 ) ;
if ( V_39 -> V_49 -> V_116 )
F_60 ( & V_2 -> V_78 ) ;
V_39 -> V_49 -> remove ( V_2 ) ;
F_7 ( V_2 , V_4 ) ;
}
if ( V_2 -> V_73 == V_53 )
V_2 -> V_73 = NULL ;
F_57 ( V_39 -> V_49 -> V_105 ) ;
F_12 ( V_2 -> V_10 , L_14 ) ;
return 0 ;
}
static T_2 F_61 ( struct V_53 * V_53 , char T_3 * V_119 ,
T_4 V_120 , T_5 * V_121 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
int V_122 = - V_52 ;
F_4 ( V_2 -> V_10 , L_15 ) ;
return V_122 ;
}
static int F_62 ( struct V_53 * V_53 , struct V_123 * V_124 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
int V_122 ;
F_12 ( V_2 -> V_10 , L_16 , ( unsigned long ) V_124 ) ;
if ( V_2 -> V_73 != V_53 )
return - V_74 ;
if ( V_39 -> V_49 -> V_75 )
V_122 = F_63 ( & V_2 -> V_76 , V_124 ) ;
else
V_122 = F_64 ( & V_2 -> V_78 , V_124 ) ;
F_12 ( V_2 -> V_10 , L_17 ,
( unsigned long ) V_124 -> V_125 ,
( unsigned long ) V_124 -> V_126 - ( unsigned long ) V_124 -> V_125 ,
V_122 ) ;
return V_122 ;
}
static unsigned int F_65 ( struct V_53 * V_53 , T_6 * V_127 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
if ( V_2 -> V_73 != V_53 )
return - V_74 ;
if ( V_39 -> V_49 -> V_75 && F_66 ( & V_2 -> V_76 . V_128 ) ) {
F_4 ( V_2 -> V_10 , L_18 ) ;
return V_129 ;
}
return V_39 -> V_49 -> V_130 ( V_53 , V_127 ) ;
}
void F_67 ( struct V_131 * V_132 )
{
struct V_1 * V_2 = F_68 ( V_132 ) ;
F_51 ( & V_2 -> V_133 ) ;
}
void F_69 ( struct V_131 * V_132 )
{
struct V_1 * V_2 = F_68 ( V_132 ) ;
F_52 ( & V_2 -> V_133 ) ;
}
static int F_70 ( struct V_53 * V_53 , void * V_54 ,
struct V_37 * V_26 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
int V_7 ;
F_16 ( V_54 != V_53 -> V_55 ) ;
if ( V_26 -> type != V_56 ) {
F_71 ( V_2 -> V_10 , L_19 , V_26 -> type ) ;
return - V_52 ;
}
if ( V_2 -> V_73 && V_2 -> V_73 != V_53 )
return - V_74 ;
if ( F_72 ( F_11 ( V_2 -> V_40 ) , V_2 ) ) {
F_4 ( V_2 -> V_10 , L_20 ) ;
return - V_74 ;
}
V_7 = F_44 ( V_2 , V_26 ) ;
if ( ! V_7 && ! V_2 -> V_73 )
V_2 -> V_73 = V_53 ;
return V_7 ;
}
static int F_73 ( struct V_53 * V_53 , void * V_54 ,
struct V_134 * V_26 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
const struct V_135 * V_136 ;
F_16 ( V_54 != V_53 -> V_55 ) ;
if ( V_26 -> V_59 >= V_2 -> V_21 )
return - V_52 ;
V_136 = V_2 -> V_22 [ V_26 -> V_59 ] . V_23 ;
if ( V_136 -> V_63 )
F_74 ( V_26 -> V_137 , V_136 -> V_63 , sizeof( V_26 -> V_137 ) ) ;
V_26 -> V_44 = V_136 -> V_19 ;
return 0 ;
}
static int F_75 ( struct V_53 * V_53 , void * V_54 ,
struct V_37 * V_26 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
struct V_41 * V_42 = & V_26 -> V_43 . V_42 ;
F_16 ( V_54 != V_53 -> V_55 ) ;
if ( V_26 -> type != V_56 )
return - V_52 ;
V_42 -> V_45 = V_2 -> V_98 ;
V_42 -> V_46 = V_2 -> V_99 ;
V_42 -> V_47 = V_2 -> V_47 ;
V_42 -> V_48 = V_2 -> V_48 ;
V_42 -> V_101 = V_2 -> V_101 ;
V_42 -> V_44 = V_2 -> V_95 -> V_23 -> V_19 ;
V_42 -> V_100 = V_2 -> V_100 ;
F_12 ( V_2 -> V_10 , L_21 ,
V_2 -> V_95 -> V_23 -> V_19 ) ;
return 0 ;
}
static int F_76 ( struct V_53 * V_53 , void * V_54 ,
struct V_138 * V_139 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
F_16 ( V_54 != V_53 -> V_55 ) ;
F_74 ( V_139 -> V_140 , V_39 -> V_141 , sizeof( V_139 -> V_140 ) ) ;
return V_39 -> V_49 -> V_142 ( V_39 , V_139 ) ;
}
static int F_77 ( struct V_53 * V_53 , void * V_54 ,
enum V_143 V_20 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
F_16 ( V_54 != V_53 -> V_55 ) ;
if ( V_20 != V_56 )
return - V_52 ;
if ( V_2 -> V_73 != V_53 )
return - V_74 ;
if ( V_39 -> V_49 -> V_75 )
V_7 = F_78 ( & V_2 -> V_76 ) ;
else
V_7 = F_79 ( & V_2 -> V_78 , V_20 ) ;
if ( ! V_7 )
F_5 ( V_6 , V_89 , V_144 , 1 ) ;
return V_7 ;
}
static int F_80 ( struct V_53 * V_53 , void * V_54 ,
enum V_143 V_20 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
F_16 ( V_54 != V_53 -> V_55 ) ;
if ( V_20 != V_56 )
return - V_52 ;
if ( V_2 -> V_73 != V_53 )
return - V_74 ;
if ( V_39 -> V_49 -> V_75 )
F_81 ( & V_2 -> V_76 ) ;
else
F_82 ( & V_2 -> V_78 , V_20 ) ;
F_5 ( V_6 , V_89 , V_144 , 0 ) ;
return 0 ;
}
static int F_83 ( struct V_53 * V_53 , void * V_67 ,
struct V_145 * V_64 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
return V_39 -> V_49 -> V_146 ( V_2 , V_64 ) ;
}
static int F_84 ( struct V_53 * V_53 , void * V_67 ,
struct V_147 * V_64 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
int V_7 ;
V_7 = V_39 -> V_49 -> V_148 ( V_2 , V_64 ) ;
return V_7 ;
}
static int F_85 ( struct V_53 * V_53 , void * V_67 ,
struct V_147 * V_64 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
struct V_149 * V_150 = & V_64 -> V_151 ;
struct V_147 V_152 ;
int V_7 ;
if ( V_64 -> type != V_56 )
return - V_52 ;
F_12 ( V_2 -> V_10 , L_22 ,
V_150 -> V_45 , V_150 -> V_46 , V_150 -> V_153 , V_150 -> V_154 ) ;
V_7 = V_39 -> V_49 -> V_148 ( V_2 , & V_152 ) ;
if ( V_7 < 0 ) {
F_4 ( V_2 -> V_10 ,
L_23 ) ;
} else if ( ( V_64 -> V_151 . V_45 == V_152 . V_151 . V_45 &&
V_64 -> V_151 . V_46 == V_152 . V_151 . V_46 ) ||
! F_72 ( V_39 , V_2 ) ) {
V_7 = V_39 -> V_49 -> V_155 ( V_2 , V_64 ) ;
} else if ( V_39 -> V_49 -> V_156 ) {
V_7 = V_39 -> V_49 -> V_156 ( V_2 , V_64 ) ;
} else {
F_4 ( V_2 -> V_10 ,
L_24 ) ;
V_7 = - V_74 ;
}
return V_7 ;
}
static int F_86 ( struct V_53 * V_53 , void * V_67 ,
struct V_157 * V_64 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
if ( V_39 -> V_49 -> V_158 )
return V_39 -> V_49 -> V_158 ( V_2 , V_64 ) ;
return - V_15 ;
}
static int F_87 ( struct V_53 * V_53 , void * V_67 ,
struct V_157 * V_64 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
if ( V_39 -> V_49 -> V_159 )
return V_39 -> V_49 -> V_159 ( V_2 , V_64 ) ;
return - V_15 ;
}
static int F_88 ( struct V_53 * V_53 , void * V_67 ,
struct V_160 * V_161 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_5 ( V_6 , V_13 , V_162 , V_161 ) ;
}
static int F_89 ( struct V_53 * V_53 , void * V_67 ,
struct V_163 * V_164 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_5 ( V_6 , V_13 , V_165 , V_164 ) ;
}
static int F_90 ( struct V_53 * V_53 , void * V_67 ,
struct V_163 * V_164 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_5 ( V_6 , V_13 , V_166 , V_164 ) ;
}
static void F_91 ( struct V_38 * V_39 )
{
struct V_1 * V_2 ;
F_51 ( & V_39 -> V_108 ) ;
F_92 (icd, &devices, list) {
if ( V_2 -> V_167 == V_39 -> V_168 ) {
int V_7 ;
V_2 -> V_40 = V_39 -> V_169 . V_112 ;
V_7 = F_93 ( V_2 ) ;
}
}
F_52 ( & V_39 -> V_108 ) ;
}
static int F_94 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_170 * V_171 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
struct V_172 * V_173 = F_95 ( V_4 -> V_174 ) ;
struct V_5 * V_175 ;
if ( ! V_173 ) {
F_4 ( V_2 -> V_10 , L_25 ,
V_4 -> V_174 ) ;
goto V_176;
}
V_4 -> V_177 -> V_178 = V_4 ;
V_175 = F_96 ( & V_39 -> V_169 , V_173 ,
V_4 -> V_177 , NULL ) ;
if ( ! V_175 )
goto V_179;
V_171 = F_97 ( V_175 ) ;
V_2 -> V_180 = & V_171 -> V_112 ;
return 0 ;
V_179:
F_98 ( V_173 ) ;
V_176:
return - V_16 ;
}
static void F_99 ( struct V_1 * V_2 )
{
struct V_170 * V_171 =
F_100 ( F_49 ( V_2 ) ) ;
struct V_172 * V_173 = V_171 -> V_181 ;
V_2 -> V_180 = NULL ;
F_101 ( F_102 ( V_171 ) ) ;
F_103 ( V_171 ) ;
F_98 ( V_173 ) ;
}
static int F_93 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
struct V_3 * V_4 = F_48 ( V_2 ) ;
struct V_182 * V_180 = NULL ;
struct V_5 * V_6 ;
struct V_183 V_184 ;
int V_7 ;
F_104 ( V_2 -> V_10 , L_26 , F_105 ( V_2 -> V_10 ) ) ;
V_7 = F_106 ( & V_2 -> V_118 , 16 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_107 ( V_2 -> V_10 , V_4 -> V_8 ,
V_4 -> V_9 ) ;
if ( V_7 < 0 )
goto V_185;
if ( V_4 -> V_107 )
V_4 -> V_107 ( V_2 -> V_10 ) ;
V_7 = V_39 -> V_49 -> V_109 ( V_2 ) ;
if ( V_7 < 0 )
goto V_186;
V_7 = F_1 ( V_2 , V_4 ) ;
if ( V_7 < 0 )
goto V_111;
V_7 = F_108 ( V_2 ) ;
if ( V_7 < 0 )
goto V_187;
if ( V_4 -> V_177 ) {
V_7 = F_94 ( V_2 , V_4 ) ;
if ( V_7 < 0 )
goto V_188;
} else if ( ! V_4 -> V_189 || ! V_4 -> V_190 ) {
V_7 = - V_52 ;
goto V_188;
} else {
if ( V_4 -> V_191 )
V_7 = F_109 ( V_4 -> V_191 ) ;
V_7 = V_4 -> V_189 ( V_2 ) ;
if ( V_7 < 0 )
goto V_188;
V_180 = F_49 ( V_2 ) ;
if ( ! V_180 || ! V_180 -> V_140 || ! F_47 ( V_180 ) ||
! F_50 ( V_180 -> V_140 -> V_105 ) ) {
V_4 -> V_190 ( V_2 ) ;
V_7 = - V_16 ;
goto V_192;
}
}
V_6 = F_2 ( V_2 ) ;
V_6 -> V_193 = F_110 ( V_2 ) ;
F_111 ( V_6 , V_2 ) ;
if ( F_112 ( & V_2 -> V_118 , V_6 -> V_118 ) )
goto V_194;
V_7 = F_39 ( V_2 ) ;
if ( V_7 < 0 )
goto V_195;
V_2 -> V_101 = V_196 ;
F_51 ( & V_2 -> V_133 ) ;
V_7 = F_113 ( V_2 ) ;
if ( V_7 < 0 )
goto V_197;
V_7 = F_5 ( V_6 , V_13 , V_14 , 1 ) ;
if ( V_7 < 0 && V_7 != - V_15 )
goto V_17;
if ( ! F_5 ( V_6 , V_89 , V_198 , & V_184 ) ) {
V_2 -> V_98 = V_184 . V_45 ;
V_2 -> V_99 = V_184 . V_46 ;
V_2 -> V_100 = V_184 . V_100 ;
V_2 -> V_101 = V_184 . V_101 ;
}
V_39 -> V_49 -> remove ( V_2 ) ;
F_7 ( V_2 , V_4 ) ;
F_52 ( & V_2 -> V_133 ) ;
return 0 ;
V_17:
F_114 ( V_2 -> V_104 ) ;
V_197:
F_52 ( & V_2 -> V_133 ) ;
F_43 ( V_2 ) ;
V_195:
V_194:
if ( V_4 -> V_177 ) {
F_99 ( V_2 ) ;
} else {
V_4 -> V_190 ( V_2 ) ;
F_57 ( V_180 -> V_140 -> V_105 ) ;
}
V_192:
V_188:
F_115 ( V_2 -> V_104 ) ;
V_2 -> V_104 = NULL ;
V_187:
F_7 ( V_2 , V_4 ) ;
V_111:
V_39 -> V_49 -> remove ( V_2 ) ;
V_186:
F_116 ( V_4 -> V_8 , V_4 -> V_9 ) ;
V_185:
F_117 ( & V_2 -> V_118 ) ;
return V_7 ;
}
static int F_118 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_48 ( V_2 ) ;
struct V_103 * V_104 = V_2 -> V_104 ;
F_119 ( ! V_2 -> V_40 ) ;
F_117 ( & V_2 -> V_118 ) ;
if ( V_104 ) {
F_114 ( V_104 ) ;
V_2 -> V_104 = NULL ;
}
if ( V_4 -> V_177 ) {
F_99 ( V_2 ) ;
} else {
struct V_199 * V_200 = F_49 ( V_2 ) -> V_140 ;
if ( V_200 ) {
V_4 -> V_190 ( V_2 ) ;
F_57 ( V_200 -> V_105 ) ;
}
}
F_43 ( V_2 ) ;
F_116 ( V_4 -> V_8 , V_4 -> V_9 ) ;
return 0 ;
}
static int F_120 ( struct V_1 * V_2 ,
struct V_145 * V_64 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_5 ( V_6 , V_89 , V_146 , V_64 ) ;
}
static int F_121 ( struct V_1 * V_2 , struct V_147 * V_64 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_5 ( V_6 , V_89 , V_201 , V_64 ) ;
}
static int F_122 ( struct V_1 * V_2 , struct V_147 * V_64 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_5 ( V_6 , V_89 , V_202 , V_64 ) ;
}
static int F_123 ( struct V_1 * V_2 ,
struct V_157 * V_203 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_5 ( V_6 , V_89 , V_204 , V_203 ) ;
}
static int F_124 ( struct V_1 * V_2 ,
struct V_157 * V_203 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_5 ( V_6 , V_89 , V_205 , V_203 ) ;
}
static int F_125 ( struct V_1 * V_2 ,
struct V_68 * V_69 )
{
int V_7 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_18 * V_51 ;
T_7 V_206 = V_69 -> V_207 ;
struct V_68 V_208 = * V_69 ;
V_51 = F_8 ( V_2 , V_206 ) ;
if ( ! V_51 )
return - V_52 ;
V_208 . V_207 = V_51 -> V_88 ;
V_7 = F_5 ( V_6 , V_89 , V_209 , & V_208 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_69 = V_208 ;
V_69 -> V_207 = V_206 ;
return 0 ;
}
int F_126 ( struct V_38 * V_39 )
{
struct V_38 * V_210 ;
int V_7 ;
if ( ! V_39 || ! V_39 -> V_49 ||
! V_39 -> V_49 -> V_50 ||
! V_39 -> V_49 -> V_97 ||
! V_39 -> V_49 -> V_102 ||
! V_39 -> V_49 -> V_142 ||
( ( ! V_39 -> V_49 -> V_75 ||
! V_39 -> V_49 -> V_77 ) &&
! V_39 -> V_49 -> V_116 ) ||
! V_39 -> V_49 -> V_109 ||
! V_39 -> V_49 -> remove ||
! V_39 -> V_49 -> V_130 ||
! V_39 -> V_169 . V_112 )
return - V_52 ;
if ( ! V_39 -> V_49 -> V_155 )
V_39 -> V_49 -> V_155 = F_122 ;
if ( ! V_39 -> V_49 -> V_148 )
V_39 -> V_49 -> V_148 = F_121 ;
if ( ! V_39 -> V_49 -> V_146 )
V_39 -> V_49 -> V_146 = F_120 ;
if ( ! V_39 -> V_49 -> V_159 )
V_39 -> V_49 -> V_159 = F_124 ;
if ( ! V_39 -> V_49 -> V_158 )
V_39 -> V_49 -> V_158 = F_123 ;
if ( ! V_39 -> V_49 -> V_70 )
V_39 -> V_49 -> V_70 = F_125 ;
F_51 ( & V_211 ) ;
F_92 (ix, &hosts, list) {
if ( V_210 -> V_168 == V_39 -> V_168 ) {
V_7 = - V_74 ;
goto V_212;
}
}
V_7 = F_127 ( V_39 -> V_169 . V_112 , & V_39 -> V_169 ) ;
if ( V_7 < 0 )
goto V_212;
F_128 ( & V_39 -> V_213 , & V_214 ) ;
F_52 ( & V_211 ) ;
F_129 ( & V_39 -> V_108 ) ;
F_91 ( V_39 ) ;
return 0 ;
V_212:
F_52 ( & V_211 ) ;
return V_7 ;
}
void F_130 ( struct V_38 * V_39 )
{
struct V_1 * V_2 ;
F_51 ( & V_211 ) ;
F_131 ( & V_39 -> V_213 ) ;
F_92 (icd, &devices, list)
if ( V_2 -> V_167 == V_39 -> V_168 && F_49 ( V_2 ) )
F_118 ( V_2 ) ;
F_52 ( & V_211 ) ;
F_132 ( & V_39 -> V_169 ) ;
}
static int F_133 ( struct V_1 * V_2 )
{
struct V_1 * V_210 ;
int V_215 = - 1 , V_20 ;
for ( V_20 = 0 ; V_20 < 256 && V_215 < 0 ; V_20 ++ ) {
V_215 = V_20 ;
F_92 (ix, &devices, list) {
if ( V_210 -> V_167 == V_2 -> V_167 && V_210 -> V_216 == V_20 ) {
V_215 = - 1 ;
break;
}
}
}
if ( V_215 < 0 )
return - V_93 ;
V_2 -> V_216 = V_215 ;
V_2 -> V_106 = 0 ;
V_2 -> V_217 = NULL ;
F_129 ( & V_2 -> V_133 ) ;
F_128 ( & V_2 -> V_213 , & V_218 ) ;
return 0 ;
}
static int F_108 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
struct V_103 * V_104 = F_134 () ;
if ( ! V_104 )
return - V_93 ;
F_74 ( V_104 -> V_63 , V_39 -> V_141 , sizeof( V_104 -> V_63 ) ) ;
V_104 -> V_40 = V_2 -> V_10 ;
V_104 -> V_219 = V_62 ;
V_104 -> V_220 = & V_221 ;
V_104 -> V_222 = & V_223 ;
V_104 -> V_224 = F_115 ;
V_104 -> V_225 = V_62 ;
V_104 -> V_118 = & V_2 -> V_118 ;
V_104 -> V_226 = & V_2 -> V_133 ;
V_2 -> V_104 = V_104 ;
return 0 ;
}
static int F_113 ( struct V_1 * V_2 )
{
const struct V_227 * type = V_2 -> V_104 -> V_112 . type ;
int V_7 ;
if ( ! V_2 -> V_40 )
return - V_16 ;
V_7 = F_135 ( V_2 -> V_104 , V_228 , - 1 ) ;
if ( V_7 < 0 ) {
F_4 ( V_2 -> V_10 , L_27 , V_7 ) ;
return V_7 ;
}
V_2 -> V_104 -> V_112 . type = type ;
return 0 ;
}
static int T_8 F_136 ( struct V_229 * V_10 )
{
struct V_3 * V_4 = V_10 -> V_112 . V_178 ;
struct V_1 * V_2 ;
int V_7 ;
if ( ! V_4 )
return - V_52 ;
V_2 = F_137 ( sizeof( * V_2 ) , V_230 ) ;
if ( ! V_2 )
return - V_93 ;
V_2 -> V_167 = V_4 -> V_231 ;
V_2 -> V_232 = V_4 ;
V_2 -> V_10 = & V_10 -> V_112 ;
F_138 ( V_10 , V_2 ) ;
V_7 = F_133 ( V_2 ) ;
if ( V_7 < 0 )
goto V_233;
V_2 -> V_98 = V_234 ;
V_2 -> V_99 = V_235 ;
return 0 ;
V_233:
F_139 ( V_2 ) ;
return V_7 ;
}
static int T_9 F_140 ( struct V_229 * V_10 )
{
struct V_1 * V_2 = F_141 ( V_10 ) ;
if ( ! V_2 )
return - V_52 ;
F_131 ( & V_2 -> V_213 ) ;
F_139 ( V_2 ) ;
return 0 ;
}
static int T_10 F_142 ( void )
{
return F_143 ( & V_236 , F_136 ) ;
}
static void T_11 F_144 ( void )
{
F_145 ( & V_236 ) ;
}

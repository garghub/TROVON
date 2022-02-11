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
const struct V_18 * V_41 ;
struct V_42 * V_43 = & V_26 -> V_44 . V_43 ;
int V_7 ;
F_12 ( V_2 -> V_10 , L_5 ,
F_13 ( V_43 -> V_45 ) , V_43 -> V_46 , V_43 -> V_47 ) ;
if ( ! ( V_39 -> V_48 & V_49 ) ) {
V_43 -> V_50 = 0 ;
V_43 -> V_51 = 0 ;
}
V_7 = V_39 -> V_52 -> V_53 ( V_2 , V_26 ) ;
if ( V_7 < 0 )
return V_7 ;
V_41 = F_8 ( V_2 , V_43 -> V_45 ) ;
if ( ! V_41 )
return - V_54 ;
V_7 = F_14 ( V_43 -> V_46 , V_41 -> V_23 ) ;
if ( V_7 < 0 )
return V_7 ;
V_43 -> V_50 = F_15 ( V_55 , V_43 -> V_50 , V_7 ) ;
V_7 = F_16 ( V_41 -> V_23 , V_43 -> V_50 ,
V_43 -> V_47 ) ;
if ( V_7 < 0 )
return V_7 ;
V_43 -> V_51 = F_15 ( V_55 , V_43 -> V_51 , V_7 ) ;
return 0 ;
}
static int F_17 ( struct V_56 * V_56 , void * V_57 ,
struct V_37 * V_26 )
{
struct V_1 * V_2 = V_56 -> V_58 ;
F_18 ( V_57 != V_56 -> V_58 ) ;
if ( V_26 -> type != V_59 )
return - V_54 ;
return F_10 ( V_2 , V_26 ) ;
}
static int F_19 ( struct V_56 * V_56 , void * V_57 ,
struct V_60 * V_61 )
{
if ( V_61 -> V_62 != 0 )
return - V_54 ;
V_61 -> type = V_63 ;
V_61 -> V_64 = V_65 ;
strcpy ( V_61 -> V_66 , L_6 ) ;
return 0 ;
}
static int F_20 ( struct V_56 * V_56 , void * V_57 , unsigned int * V_20 )
{
* V_20 = 0 ;
return 0 ;
}
static int F_21 ( struct V_56 * V_56 , void * V_57 , unsigned int V_20 )
{
if ( V_20 > 0 )
return - V_54 ;
return 0 ;
}
static int F_22 ( struct V_56 * V_56 , void * V_57 , T_1 * V_67 )
{
struct V_1 * V_2 = V_56 -> V_58 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_5 ( V_6 , V_13 , V_68 , * V_67 ) ;
}
static int F_23 ( struct V_56 * V_56 , void * V_57 , T_1 * V_67 )
{
struct V_1 * V_2 = V_56 -> V_58 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_5 ( V_6 , V_13 , V_69 , V_67 ) ;
}
static int F_24 ( struct V_56 * V_56 , void * V_70 ,
struct V_71 * V_72 )
{
struct V_1 * V_2 = V_56 -> V_58 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
return V_39 -> V_52 -> V_73 ( V_2 , V_72 ) ;
}
static int F_25 ( struct V_56 * V_56 , void * V_57 ,
struct V_74 * V_75 )
{
int V_7 ;
struct V_1 * V_2 = V_56 -> V_58 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
F_18 ( V_57 != V_56 -> V_58 ) ;
if ( V_2 -> V_76 && V_2 -> V_76 != V_56 )
return - V_77 ;
if ( V_39 -> V_52 -> V_78 ) {
V_7 = F_26 ( & V_2 -> V_79 , V_75 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = V_39 -> V_52 -> V_80 ( V_2 , V_75 ) ;
} else {
V_7 = F_27 ( & V_2 -> V_81 , V_75 ) ;
}
if ( ! V_7 && ! V_2 -> V_76 )
V_2 -> V_76 = V_56 ;
return V_7 ;
}
static int F_28 ( struct V_56 * V_56 , void * V_57 ,
struct V_82 * V_75 )
{
struct V_1 * V_2 = V_56 -> V_58 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
F_18 ( V_57 != V_56 -> V_58 ) ;
if ( V_39 -> V_52 -> V_78 )
return F_29 ( & V_2 -> V_79 , V_75 ) ;
else
return F_30 ( & V_2 -> V_81 , V_75 ) ;
}
static int F_31 ( struct V_56 * V_56 , void * V_57 ,
struct V_82 * V_75 )
{
struct V_1 * V_2 = V_56 -> V_58 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
F_18 ( V_57 != V_56 -> V_58 ) ;
if ( V_2 -> V_76 != V_56 )
return - V_77 ;
if ( V_39 -> V_52 -> V_78 )
return F_32 ( & V_2 -> V_79 , V_75 ) ;
else
return F_33 ( & V_2 -> V_81 , V_75 ) ;
}
static int F_34 ( struct V_56 * V_56 , void * V_57 ,
struct V_82 * V_75 )
{
struct V_1 * V_2 = V_56 -> V_58 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
F_18 ( V_57 != V_56 -> V_58 ) ;
if ( V_2 -> V_76 != V_56 )
return - V_77 ;
if ( V_39 -> V_52 -> V_78 )
return F_35 ( & V_2 -> V_79 , V_75 , V_56 -> V_83 & V_84 ) ;
else
return F_36 ( & V_2 -> V_81 , V_75 , V_56 -> V_83 & V_84 ) ;
}
static int F_37 ( struct V_56 * V_56 , void * V_57 ,
struct V_85 * V_86 )
{
struct V_1 * V_2 = V_56 -> V_58 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
if ( V_39 -> V_52 -> V_78 )
return - V_54 ;
else
return F_38 ( & V_2 -> V_81 , V_86 ) ;
}
static int F_39 ( struct V_56 * V_56 , void * V_57 ,
struct V_82 * V_87 )
{
struct V_1 * V_2 = V_56 -> V_58 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
if ( V_39 -> V_52 -> V_78 )
return - V_54 ;
else
return F_40 ( & V_2 -> V_81 , V_87 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
unsigned int V_20 , V_88 = 0 , V_89 = 0 ;
int V_7 ;
enum V_90 V_91 ;
while ( ! F_5 ( V_6 , V_92 , V_93 , V_89 , & V_91 ) )
V_89 ++ ;
if ( ! V_39 -> V_52 -> V_94 )
V_88 = V_89 ;
else
for ( V_20 = 0 ; V_20 < V_89 ; V_20 ++ ) {
V_7 = V_39 -> V_52 -> V_94 ( V_2 , V_20 , NULL ) ;
if ( V_7 < 0 )
return V_7 ;
V_88 += V_7 ;
}
if ( ! V_88 )
return - V_95 ;
V_2 -> V_22 =
F_42 ( V_88 * sizeof( struct V_18 ) ) ;
if ( ! V_2 -> V_22 )
return - V_96 ;
F_12 ( V_2 -> V_10 , L_7 , V_88 ) ;
V_88 = 0 ;
for ( V_20 = 0 ; V_20 < V_89 ; V_20 ++ )
if ( ! V_39 -> V_52 -> V_94 ) {
F_5 ( V_6 , V_92 , V_93 , V_20 , & V_91 ) ;
V_2 -> V_22 [ V_88 ] . V_23 =
F_43 ( V_91 ) ;
if ( V_2 -> V_22 [ V_88 ] . V_23 )
V_2 -> V_22 [ V_88 ++ ] . V_91 = V_91 ;
} else {
V_7 = V_39 -> V_52 -> V_94 ( V_2 , V_20 ,
& V_2 -> V_22 [ V_88 ] ) ;
if ( V_7 < 0 )
goto V_97;
V_88 += V_7 ;
}
V_2 -> V_21 = V_88 ;
V_2 -> V_98 = & V_2 -> V_22 [ 0 ] ;
return 0 ;
V_97:
F_44 ( V_2 -> V_22 ) ;
return V_7 ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
if ( V_39 -> V_52 -> V_99 )
V_39 -> V_52 -> V_99 ( V_2 ) ;
V_2 -> V_98 = NULL ;
V_2 -> V_21 = 0 ;
F_44 ( V_2 -> V_22 ) ;
V_2 -> V_22 = NULL ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_37 * V_26 )
{
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
struct V_42 * V_43 = & V_26 -> V_44 . V_43 ;
int V_7 ;
F_12 ( V_2 -> V_10 , L_8 ,
F_13 ( V_43 -> V_45 ) , V_43 -> V_46 , V_43 -> V_47 ) ;
V_7 = F_10 ( V_2 , V_26 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = V_39 -> V_52 -> V_100 ( V_2 , V_26 ) ;
if ( V_7 < 0 ) {
return V_7 ;
} else if ( ! V_2 -> V_98 ||
V_2 -> V_98 -> V_23 -> V_19 != V_43 -> V_45 ) {
F_4 ( V_2 -> V_10 ,
L_9 ) ;
return - V_54 ;
}
V_2 -> V_101 = V_43 -> V_46 ;
V_2 -> V_102 = V_43 -> V_47 ;
V_2 -> V_50 = V_43 -> V_50 ;
V_2 -> V_51 = V_43 -> V_51 ;
V_2 -> V_103 = V_43 -> V_103 ;
V_2 -> V_104 = V_43 -> V_104 ;
if ( V_39 -> V_52 -> V_78 )
V_2 -> V_79 . V_104 = V_43 -> V_104 ;
F_12 ( V_2 -> V_10 , L_10 ,
V_2 -> V_101 , V_2 -> V_102 ) ;
return V_39 -> V_52 -> V_105 ( V_2 ) ;
}
static int F_47 ( struct V_56 * V_56 )
{
struct V_106 * V_107 = F_48 ( V_56 ) ;
struct V_1 * V_2 = F_49 ( V_107 -> V_40 ) ;
struct V_3 * V_4 = F_50 ( V_2 ) ;
struct V_38 * V_39 ;
int V_7 ;
if ( ! F_51 ( V_2 ) )
return - V_16 ;
V_39 = F_11 ( V_2 -> V_40 ) ;
if ( ! F_52 ( V_39 -> V_52 -> V_108 ) ) {
F_4 ( V_2 -> V_10 , L_11 ) ;
return - V_54 ;
}
V_2 -> V_109 ++ ;
if ( V_2 -> V_109 == 1 ) {
struct V_37 V_26 = {
. type = V_59 ,
. V_44 . V_43 = {
. V_46 = V_2 -> V_101 ,
. V_47 = V_2 -> V_102 ,
. V_104 = V_2 -> V_104 ,
. V_103 = V_2 -> V_103 ,
. V_45 =
V_2 -> V_98 -> V_23 -> V_19 ,
} ,
} ;
if ( V_4 -> V_110 )
V_4 -> V_110 ( V_2 -> V_10 ) ;
F_53 ( & V_39 -> V_111 ) ;
V_7 = V_39 -> V_52 -> V_112 ( V_2 ) ;
F_54 ( & V_39 -> V_111 ) ;
if ( V_7 < 0 ) {
F_4 ( V_2 -> V_10 , L_12 , V_7 ) ;
goto V_113;
}
V_7 = F_1 ( V_2 , V_4 ) ;
if ( V_7 < 0 )
goto V_114;
F_55 ( & V_2 -> V_107 -> V_115 ) ;
V_7 = F_56 ( & V_2 -> V_107 -> V_115 ) ;
if ( V_7 < 0 && V_7 != - V_116 )
goto V_117;
V_7 = F_46 ( V_2 , & V_26 ) ;
if ( V_7 < 0 )
goto V_118;
if ( V_39 -> V_52 -> V_78 ) {
V_39 -> V_52 -> V_78 ( & V_2 -> V_79 , V_2 ) ;
} else {
V_7 = V_39 -> V_52 -> V_119 ( & V_2 -> V_81 , V_2 ) ;
if ( V_7 < 0 )
goto V_120;
}
F_57 ( & V_2 -> V_121 ) ;
}
V_56 -> V_58 = V_2 ;
F_12 ( V_2 -> V_10 , L_13 ) ;
return 0 ;
V_120:
V_118:
F_58 ( & V_2 -> V_107 -> V_115 ) ;
V_117:
F_7 ( V_2 , V_4 ) ;
V_114:
V_39 -> V_52 -> remove ( V_2 ) ;
V_113:
V_2 -> V_109 -- ;
F_59 ( V_39 -> V_52 -> V_108 ) ;
return V_7 ;
}
static int F_60 ( struct V_56 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_58 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
V_2 -> V_109 -- ;
if ( ! V_2 -> V_109 ) {
struct V_3 * V_4 = F_50 ( V_2 ) ;
F_61 ( & V_2 -> V_107 -> V_115 ) ;
F_58 ( & V_2 -> V_107 -> V_115 ) ;
if ( V_39 -> V_52 -> V_119 )
F_62 ( & V_2 -> V_81 ) ;
V_39 -> V_52 -> remove ( V_2 ) ;
F_7 ( V_2 , V_4 ) ;
}
if ( V_2 -> V_76 == V_56 )
V_2 -> V_76 = NULL ;
F_59 ( V_39 -> V_52 -> V_108 ) ;
F_12 ( V_2 -> V_10 , L_14 ) ;
return 0 ;
}
static T_2 F_63 ( struct V_56 * V_56 , char T_3 * V_122 ,
T_4 V_123 , T_5 * V_124 )
{
struct V_1 * V_2 = V_56 -> V_58 ;
int V_125 = - V_54 ;
F_4 ( V_2 -> V_10 , L_15 ) ;
return V_125 ;
}
static int F_64 ( struct V_56 * V_56 , struct V_126 * V_127 )
{
struct V_1 * V_2 = V_56 -> V_58 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
int V_125 ;
F_12 ( V_2 -> V_10 , L_16 , ( unsigned long ) V_127 ) ;
if ( V_2 -> V_76 != V_56 )
return - V_77 ;
if ( V_39 -> V_52 -> V_78 )
V_125 = F_65 ( & V_2 -> V_79 , V_127 ) ;
else
V_125 = F_66 ( & V_2 -> V_81 , V_127 ) ;
F_12 ( V_2 -> V_10 , L_17 ,
( unsigned long ) V_127 -> V_128 ,
( unsigned long ) V_127 -> V_129 - ( unsigned long ) V_127 -> V_128 ,
V_125 ) ;
return V_125 ;
}
static unsigned int F_67 ( struct V_56 * V_56 , T_6 * V_130 )
{
struct V_1 * V_2 = V_56 -> V_58 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
if ( V_2 -> V_76 != V_56 )
return - V_77 ;
if ( V_39 -> V_52 -> V_78 && F_68 ( & V_2 -> V_79 . V_131 ) ) {
F_4 ( V_2 -> V_10 , L_18 ) ;
return V_132 ;
}
return V_39 -> V_52 -> V_133 ( V_56 , V_130 ) ;
}
void F_69 ( struct V_134 * V_135 )
{
struct V_1 * V_2 = F_70 ( V_135 ) ;
F_53 ( & V_2 -> V_136 ) ;
}
void F_71 ( struct V_134 * V_135 )
{
struct V_1 * V_2 = F_70 ( V_135 ) ;
F_54 ( & V_2 -> V_136 ) ;
}
static int F_72 ( struct V_56 * V_56 , void * V_57 ,
struct V_37 * V_26 )
{
struct V_1 * V_2 = V_56 -> V_58 ;
int V_7 ;
F_18 ( V_57 != V_56 -> V_58 ) ;
if ( V_26 -> type != V_59 ) {
F_73 ( V_2 -> V_10 , L_19 , V_26 -> type ) ;
return - V_54 ;
}
if ( V_2 -> V_76 && V_2 -> V_76 != V_56 )
return - V_77 ;
if ( F_74 ( F_11 ( V_2 -> V_40 ) , V_2 ) ) {
F_4 ( V_2 -> V_10 , L_20 ) ;
return - V_77 ;
}
V_7 = F_46 ( V_2 , V_26 ) ;
if ( ! V_7 && ! V_2 -> V_76 )
V_2 -> V_76 = V_56 ;
return V_7 ;
}
static int F_75 ( struct V_56 * V_56 , void * V_57 ,
struct V_137 * V_26 )
{
struct V_1 * V_2 = V_56 -> V_58 ;
const struct V_138 * V_139 ;
F_18 ( V_57 != V_56 -> V_58 ) ;
if ( V_26 -> V_62 >= V_2 -> V_21 )
return - V_54 ;
V_139 = V_2 -> V_22 [ V_26 -> V_62 ] . V_23 ;
if ( V_139 -> V_66 )
F_76 ( V_26 -> V_140 , V_139 -> V_66 , sizeof( V_26 -> V_140 ) ) ;
V_26 -> V_45 = V_139 -> V_19 ;
return 0 ;
}
static int F_77 ( struct V_56 * V_56 , void * V_57 ,
struct V_37 * V_26 )
{
struct V_1 * V_2 = V_56 -> V_58 ;
struct V_42 * V_43 = & V_26 -> V_44 . V_43 ;
F_18 ( V_57 != V_56 -> V_58 ) ;
if ( V_26 -> type != V_59 )
return - V_54 ;
V_43 -> V_46 = V_2 -> V_101 ;
V_43 -> V_47 = V_2 -> V_102 ;
V_43 -> V_50 = V_2 -> V_50 ;
V_43 -> V_51 = V_2 -> V_51 ;
V_43 -> V_104 = V_2 -> V_104 ;
V_43 -> V_45 = V_2 -> V_98 -> V_23 -> V_19 ;
V_43 -> V_103 = V_2 -> V_103 ;
F_12 ( V_2 -> V_10 , L_21 ,
V_2 -> V_98 -> V_23 -> V_19 ) ;
return 0 ;
}
static int F_78 ( struct V_56 * V_56 , void * V_57 ,
struct V_141 * V_142 )
{
struct V_1 * V_2 = V_56 -> V_58 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
F_18 ( V_57 != V_56 -> V_58 ) ;
F_76 ( V_142 -> V_143 , V_39 -> V_144 , sizeof( V_142 -> V_143 ) ) ;
return V_39 -> V_52 -> V_145 ( V_39 , V_142 ) ;
}
static int F_79 ( struct V_56 * V_56 , void * V_57 ,
enum V_146 V_20 )
{
struct V_1 * V_2 = V_56 -> V_58 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
F_18 ( V_57 != V_56 -> V_58 ) ;
if ( V_20 != V_59 )
return - V_54 ;
if ( V_2 -> V_76 != V_56 )
return - V_77 ;
if ( V_39 -> V_52 -> V_78 )
V_7 = F_80 ( & V_2 -> V_79 ) ;
else
V_7 = F_81 ( & V_2 -> V_81 , V_20 ) ;
if ( ! V_7 )
F_5 ( V_6 , V_92 , V_147 , 1 ) ;
return V_7 ;
}
static int F_82 ( struct V_56 * V_56 , void * V_57 ,
enum V_146 V_20 )
{
struct V_1 * V_2 = V_56 -> V_58 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
F_18 ( V_57 != V_56 -> V_58 ) ;
if ( V_20 != V_59 )
return - V_54 ;
if ( V_2 -> V_76 != V_56 )
return - V_77 ;
if ( V_39 -> V_52 -> V_78 )
F_83 ( & V_2 -> V_79 ) ;
else
F_84 ( & V_2 -> V_81 , V_20 ) ;
F_5 ( V_6 , V_92 , V_147 , 0 ) ;
return 0 ;
}
static int F_85 ( struct V_56 * V_56 , void * V_70 ,
struct V_148 * V_67 )
{
struct V_1 * V_2 = V_56 -> V_58 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
return V_39 -> V_52 -> V_149 ( V_2 , V_67 ) ;
}
static int F_86 ( struct V_56 * V_56 , void * V_70 ,
struct V_150 * V_67 )
{
struct V_1 * V_2 = V_56 -> V_58 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
int V_7 ;
V_7 = V_39 -> V_52 -> V_151 ( V_2 , V_67 ) ;
return V_7 ;
}
static int F_87 ( struct V_56 * V_56 , void * V_70 ,
struct V_150 * V_67 )
{
struct V_1 * V_2 = V_56 -> V_58 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
struct V_152 * V_153 = & V_67 -> V_154 ;
struct V_150 V_155 ;
int V_7 ;
if ( V_67 -> type != V_59 )
return - V_54 ;
F_12 ( V_2 -> V_10 , L_22 ,
V_153 -> V_46 , V_153 -> V_47 , V_153 -> V_156 , V_153 -> V_157 ) ;
V_7 = V_39 -> V_52 -> V_151 ( V_2 , & V_155 ) ;
if ( V_7 < 0 ) {
F_4 ( V_2 -> V_10 ,
L_23 ) ;
} else if ( ( V_67 -> V_154 . V_46 == V_155 . V_154 . V_46 &&
V_67 -> V_154 . V_47 == V_155 . V_154 . V_47 ) ||
! F_74 ( V_39 , V_2 ) ) {
V_7 = V_39 -> V_52 -> V_158 ( V_2 , V_67 ) ;
} else if ( V_39 -> V_52 -> V_159 ) {
V_7 = V_39 -> V_52 -> V_159 ( V_2 , V_67 ) ;
} else {
F_4 ( V_2 -> V_10 ,
L_24 ) ;
V_7 = - V_77 ;
}
return V_7 ;
}
static int F_88 ( struct V_56 * V_56 , void * V_70 ,
struct V_160 * V_67 )
{
struct V_1 * V_2 = V_56 -> V_58 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
if ( V_39 -> V_52 -> V_161 )
return V_39 -> V_52 -> V_161 ( V_2 , V_67 ) ;
return - V_15 ;
}
static int F_89 ( struct V_56 * V_56 , void * V_70 ,
struct V_160 * V_67 )
{
struct V_1 * V_2 = V_56 -> V_58 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
if ( V_39 -> V_52 -> V_162 )
return V_39 -> V_52 -> V_162 ( V_2 , V_67 ) ;
return - V_15 ;
}
static int F_90 ( struct V_56 * V_56 , void * V_70 ,
struct V_163 * V_164 )
{
struct V_1 * V_2 = V_56 -> V_58 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_5 ( V_6 , V_13 , V_165 , V_164 ) ;
}
static int F_91 ( struct V_56 * V_56 , void * V_70 ,
struct V_166 * V_167 )
{
struct V_1 * V_2 = V_56 -> V_58 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_5 ( V_6 , V_13 , V_168 , V_167 ) ;
}
static int F_92 ( struct V_56 * V_56 , void * V_70 ,
struct V_166 * V_167 )
{
struct V_1 * V_2 = V_56 -> V_58 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_5 ( V_6 , V_13 , V_169 , V_167 ) ;
}
static void F_93 ( struct V_38 * V_39 )
{
struct V_1 * V_2 ;
F_53 ( & V_39 -> V_111 ) ;
F_94 (icd, &devices, list) {
if ( V_2 -> V_170 == V_39 -> V_171 ) {
int V_7 ;
V_2 -> V_40 = V_39 -> V_172 . V_115 ;
V_7 = F_95 ( V_2 ) ;
}
}
F_54 ( & V_39 -> V_111 ) ;
}
static int F_96 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_173 * V_174 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
struct V_175 * V_176 = F_97 ( V_4 -> V_177 ) ;
struct V_5 * V_178 ;
if ( ! V_176 ) {
F_4 ( V_2 -> V_10 , L_25 ,
V_4 -> V_177 ) ;
goto V_179;
}
V_4 -> V_180 -> V_181 = V_4 ;
V_178 = F_98 ( & V_39 -> V_172 , V_176 ,
V_4 -> V_180 , NULL ) ;
if ( ! V_178 )
goto V_182;
V_174 = F_99 ( V_178 ) ;
V_2 -> V_183 = & V_174 -> V_115 ;
return 0 ;
V_182:
F_100 ( V_176 ) ;
V_179:
return - V_16 ;
}
static void F_101 ( struct V_1 * V_2 )
{
struct V_173 * V_174 =
F_102 ( F_51 ( V_2 ) ) ;
struct V_175 * V_176 = V_174 -> V_184 ;
V_2 -> V_183 = NULL ;
F_103 ( F_104 ( V_174 ) ) ;
F_105 ( V_174 ) ;
F_100 ( V_176 ) ;
}
static int F_95 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
struct V_3 * V_4 = F_50 ( V_2 ) ;
struct V_185 * V_183 = NULL ;
struct V_5 * V_6 ;
struct V_186 V_187 ;
int V_7 ;
F_106 ( V_2 -> V_10 , L_26 , F_107 ( V_2 -> V_10 ) ) ;
V_7 = F_108 ( & V_2 -> V_121 , 16 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_109 ( V_2 -> V_10 , V_4 -> V_8 ,
V_4 -> V_9 ) ;
if ( V_7 < 0 )
goto V_188;
if ( V_4 -> V_110 )
V_4 -> V_110 ( V_2 -> V_10 ) ;
V_7 = V_39 -> V_52 -> V_112 ( V_2 ) ;
if ( V_7 < 0 )
goto V_189;
V_7 = F_1 ( V_2 , V_4 ) ;
if ( V_7 < 0 )
goto V_114;
V_7 = F_110 ( V_2 ) ;
if ( V_7 < 0 )
goto V_190;
if ( V_4 -> V_180 ) {
V_7 = F_96 ( V_2 , V_4 ) ;
if ( V_7 < 0 )
goto V_191;
} else if ( ! V_4 -> V_192 || ! V_4 -> V_193 ) {
V_7 = - V_54 ;
goto V_191;
} else {
if ( V_4 -> V_194 )
V_7 = F_111 ( V_4 -> V_194 ) ;
V_7 = V_4 -> V_192 ( V_2 ) ;
if ( V_7 < 0 )
goto V_191;
V_183 = F_51 ( V_2 ) ;
if ( ! V_183 || ! V_183 -> V_143 || ! F_49 ( V_183 ) ||
! F_52 ( V_183 -> V_143 -> V_108 ) ) {
V_4 -> V_193 ( V_2 ) ;
V_7 = - V_16 ;
goto V_195;
}
}
V_6 = F_2 ( V_2 ) ;
V_6 -> V_196 = F_112 ( V_2 ) ;
F_113 ( V_6 , V_2 ) ;
if ( F_114 ( & V_2 -> V_121 , V_6 -> V_121 ) )
goto V_197;
V_7 = F_41 ( V_2 ) ;
if ( V_7 < 0 )
goto V_198;
V_2 -> V_104 = V_199 ;
F_53 ( & V_2 -> V_136 ) ;
V_7 = F_115 ( V_2 ) ;
if ( V_7 < 0 )
goto V_200;
V_7 = F_5 ( V_6 , V_13 , V_14 , 1 ) ;
if ( V_7 < 0 && V_7 != - V_15 )
goto V_17;
if ( ! F_5 ( V_6 , V_92 , V_201 , & V_187 ) ) {
V_2 -> V_101 = V_187 . V_46 ;
V_2 -> V_102 = V_187 . V_47 ;
V_2 -> V_103 = V_187 . V_103 ;
V_2 -> V_104 = V_187 . V_104 ;
}
V_39 -> V_52 -> remove ( V_2 ) ;
F_7 ( V_2 , V_4 ) ;
F_54 ( & V_2 -> V_136 ) ;
return 0 ;
V_17:
F_116 ( V_2 -> V_107 ) ;
V_200:
F_54 ( & V_2 -> V_136 ) ;
F_45 ( V_2 ) ;
V_198:
V_197:
if ( V_4 -> V_180 ) {
F_101 ( V_2 ) ;
} else {
V_4 -> V_193 ( V_2 ) ;
F_59 ( V_183 -> V_143 -> V_108 ) ;
}
V_195:
V_191:
F_117 ( V_2 -> V_107 ) ;
V_2 -> V_107 = NULL ;
V_190:
F_7 ( V_2 , V_4 ) ;
V_114:
V_39 -> V_52 -> remove ( V_2 ) ;
V_189:
F_118 ( V_4 -> V_8 , V_4 -> V_9 ) ;
V_188:
F_119 ( & V_2 -> V_121 ) ;
return V_7 ;
}
static int F_120 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_50 ( V_2 ) ;
struct V_106 * V_107 = V_2 -> V_107 ;
F_121 ( ! V_2 -> V_40 ) ;
F_119 ( & V_2 -> V_121 ) ;
if ( V_107 ) {
F_116 ( V_107 ) ;
V_2 -> V_107 = NULL ;
}
if ( V_4 -> V_180 ) {
F_101 ( V_2 ) ;
} else {
struct V_202 * V_203 = F_51 ( V_2 ) -> V_143 ;
if ( V_203 ) {
V_4 -> V_193 ( V_2 ) ;
F_59 ( V_203 -> V_108 ) ;
}
}
F_45 ( V_2 ) ;
F_118 ( V_4 -> V_8 , V_4 -> V_9 ) ;
return 0 ;
}
static int F_122 ( struct V_1 * V_2 ,
struct V_148 * V_67 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_5 ( V_6 , V_92 , V_149 , V_67 ) ;
}
static int F_123 ( struct V_1 * V_2 , struct V_150 * V_67 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_5 ( V_6 , V_92 , V_204 , V_67 ) ;
}
static int F_124 ( struct V_1 * V_2 , struct V_150 * V_67 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_5 ( V_6 , V_92 , V_205 , V_67 ) ;
}
static int F_125 ( struct V_1 * V_2 ,
struct V_160 * V_206 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_5 ( V_6 , V_92 , V_207 , V_206 ) ;
}
static int F_126 ( struct V_1 * V_2 ,
struct V_160 * V_206 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_5 ( V_6 , V_92 , V_208 , V_206 ) ;
}
static int F_127 ( struct V_1 * V_2 ,
struct V_71 * V_72 )
{
int V_7 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_18 * V_41 ;
T_7 V_209 = V_72 -> V_210 ;
struct V_71 V_211 = * V_72 ;
V_41 = F_8 ( V_2 , V_209 ) ;
if ( ! V_41 )
return - V_54 ;
V_211 . V_210 = V_41 -> V_91 ;
V_7 = F_5 ( V_6 , V_92 , V_73 , & V_211 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_72 = V_211 ;
V_72 -> V_210 = V_209 ;
return 0 ;
}
int F_128 ( struct V_38 * V_39 )
{
struct V_38 * V_212 ;
int V_7 ;
if ( ! V_39 || ! V_39 -> V_52 ||
! V_39 -> V_52 -> V_53 ||
! V_39 -> V_52 -> V_100 ||
! V_39 -> V_52 -> V_105 ||
! V_39 -> V_52 -> V_145 ||
( ( ! V_39 -> V_52 -> V_78 ||
! V_39 -> V_52 -> V_80 ) &&
! V_39 -> V_52 -> V_119 ) ||
! V_39 -> V_52 -> V_112 ||
! V_39 -> V_52 -> remove ||
! V_39 -> V_52 -> V_133 ||
! V_39 -> V_172 . V_115 )
return - V_54 ;
if ( ! V_39 -> V_52 -> V_158 )
V_39 -> V_52 -> V_158 = F_124 ;
if ( ! V_39 -> V_52 -> V_151 )
V_39 -> V_52 -> V_151 = F_123 ;
if ( ! V_39 -> V_52 -> V_149 )
V_39 -> V_52 -> V_149 = F_122 ;
if ( ! V_39 -> V_52 -> V_162 )
V_39 -> V_52 -> V_162 = F_126 ;
if ( ! V_39 -> V_52 -> V_161 )
V_39 -> V_52 -> V_161 = F_125 ;
if ( ! V_39 -> V_52 -> V_73 )
V_39 -> V_52 -> V_73 = F_127 ;
F_53 ( & V_213 ) ;
F_94 (ix, &hosts, list) {
if ( V_212 -> V_171 == V_39 -> V_171 ) {
V_7 = - V_77 ;
goto V_214;
}
}
V_7 = F_129 ( V_39 -> V_172 . V_115 , & V_39 -> V_172 ) ;
if ( V_7 < 0 )
goto V_214;
F_130 ( & V_39 -> V_215 , & V_216 ) ;
F_54 ( & V_213 ) ;
F_131 ( & V_39 -> V_111 ) ;
F_93 ( V_39 ) ;
return 0 ;
V_214:
F_54 ( & V_213 ) ;
return V_7 ;
}
void F_132 ( struct V_38 * V_39 )
{
struct V_1 * V_2 ;
F_53 ( & V_213 ) ;
F_133 ( & V_39 -> V_215 ) ;
F_94 (icd, &devices, list)
if ( V_2 -> V_170 == V_39 -> V_171 && F_51 ( V_2 ) )
F_120 ( V_2 ) ;
F_54 ( & V_213 ) ;
F_134 ( & V_39 -> V_172 ) ;
}
static int F_135 ( struct V_1 * V_2 )
{
struct V_1 * V_212 ;
int V_217 = - 1 , V_20 ;
for ( V_20 = 0 ; V_20 < 256 && V_217 < 0 ; V_20 ++ ) {
V_217 = V_20 ;
F_94 (ix, &devices, list) {
if ( V_212 -> V_170 == V_2 -> V_170 && V_212 -> V_218 == V_20 ) {
V_217 = - 1 ;
break;
}
}
}
if ( V_217 < 0 )
return - V_96 ;
V_2 -> V_218 = V_217 ;
V_2 -> V_109 = 0 ;
V_2 -> V_219 = NULL ;
F_131 ( & V_2 -> V_136 ) ;
F_130 ( & V_2 -> V_215 , & V_220 ) ;
return 0 ;
}
static int F_110 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_11 ( V_2 -> V_40 ) ;
struct V_106 * V_107 = F_136 () ;
if ( ! V_107 )
return - V_96 ;
F_76 ( V_107 -> V_66 , V_39 -> V_144 , sizeof( V_107 -> V_66 ) ) ;
V_107 -> V_40 = V_2 -> V_10 ;
V_107 -> V_221 = V_65 ;
V_107 -> V_222 = & V_223 ;
V_107 -> V_224 = & V_225 ;
V_107 -> V_226 = F_117 ;
V_107 -> V_227 = V_65 ;
V_107 -> V_121 = & V_2 -> V_121 ;
V_107 -> V_228 = & V_2 -> V_136 ;
F_137 ( V_229 , & V_107 -> V_27 ) ;
V_2 -> V_107 = V_107 ;
return 0 ;
}
static int F_115 ( struct V_1 * V_2 )
{
const struct V_230 * type = V_2 -> V_107 -> V_115 . type ;
int V_7 ;
if ( ! V_2 -> V_40 )
return - V_16 ;
V_7 = F_138 ( V_2 -> V_107 , V_231 , - 1 ) ;
if ( V_7 < 0 ) {
F_4 ( V_2 -> V_10 , L_27 , V_7 ) ;
return V_7 ;
}
V_2 -> V_107 -> V_115 . type = type ;
return 0 ;
}
static int T_8 F_139 ( struct V_232 * V_10 )
{
struct V_3 * V_4 = V_10 -> V_115 . V_181 ;
struct V_1 * V_2 ;
int V_7 ;
if ( ! V_4 )
return - V_54 ;
V_2 = F_140 ( sizeof( * V_2 ) , V_233 ) ;
if ( ! V_2 )
return - V_96 ;
V_2 -> V_170 = V_4 -> V_234 ;
V_2 -> V_235 = V_4 ;
V_2 -> V_10 = & V_10 -> V_115 ;
F_141 ( V_10 , V_2 ) ;
V_7 = F_135 ( V_2 ) ;
if ( V_7 < 0 )
goto V_236;
V_2 -> V_101 = V_237 ;
V_2 -> V_102 = V_238 ;
return 0 ;
V_236:
F_142 ( V_2 ) ;
return V_7 ;
}
static int T_9 F_143 ( struct V_232 * V_10 )
{
struct V_1 * V_2 = F_144 ( V_10 ) ;
if ( ! V_2 )
return - V_54 ;
F_133 ( & V_2 -> V_215 ) ;
F_142 ( V_2 ) ;
return 0 ;
}
static int T_10 F_145 ( void )
{
return F_146 ( & V_239 , F_139 ) ;
}
static void T_11 F_147 ( void )
{
F_148 ( & V_239 ) ;
}

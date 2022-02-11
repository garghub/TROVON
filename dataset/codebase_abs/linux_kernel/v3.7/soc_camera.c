int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 = F_2 ( V_4 -> V_6 ,
V_4 -> V_7 ) ;
if ( V_5 < 0 ) {
F_3 ( V_2 , L_1 ) ;
return V_5 ;
}
if ( V_4 -> V_8 ) {
V_5 = V_4 -> V_8 ( V_2 , 1 ) ;
if ( V_5 < 0 ) {
F_3 ( V_2 ,
L_2 ) ;
F_4 ( V_4 -> V_6 ,
V_4 -> V_7 ) ;
}
}
return V_5 ;
}
int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 = 0 ;
int V_9 ;
if ( V_4 -> V_8 ) {
V_9 = V_4 -> V_8 ( V_2 , 0 ) ;
if ( V_9 < 0 ) {
F_3 ( V_2 ,
L_3 ) ;
V_5 = V_9 ;
}
}
V_9 = F_4 ( V_4 -> V_6 ,
V_4 -> V_7 ) ;
if ( V_9 < 0 ) {
F_3 ( V_2 , L_4 ) ;
V_5 = V_5 ? : V_9 ;
}
return V_5 ;
}
static int F_6 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_7 ( V_11 ) ;
int V_5 ;
V_5 = F_8 ( V_13 , V_14 , V_15 , 1 ) ;
if ( V_5 < 0 && V_5 != - V_16 && V_5 != - V_17 )
return V_5 ;
return 0 ;
}
static int F_9 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_7 ( V_11 ) ;
int V_5 ;
V_5 = F_8 ( V_13 , V_14 , V_15 , 0 ) ;
if ( V_5 < 0 && V_5 != - V_16 && V_5 != - V_17 )
return V_5 ;
return 0 ;
}
const struct V_18 * F_10 (
struct V_10 * V_11 , unsigned int V_19 )
{
unsigned int V_20 ;
for ( V_20 = 0 ; V_20 < V_11 -> V_21 ; V_20 ++ )
if ( V_11 -> V_22 [ V_20 ] . V_23 -> V_19 == V_19 )
return V_11 -> V_22 + V_20 ;
return NULL ;
}
unsigned long F_11 ( struct V_3 * V_4 ,
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
static int F_12 ( struct V_10 * V_11 ,
struct V_37 * V_26 )
{
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
const struct V_18 * V_41 ;
struct V_42 * V_43 = & V_26 -> V_44 . V_43 ;
int V_5 ;
F_14 ( V_11 -> V_45 , L_5 ,
F_15 ( V_43 -> V_46 ) , V_43 -> V_47 , V_43 -> V_48 ) ;
if ( V_43 -> V_46 != V_49 &&
! ( V_39 -> V_50 & V_51 ) ) {
V_43 -> V_52 = 0 ;
V_43 -> V_53 = 0 ;
}
V_5 = V_39 -> V_54 -> V_55 ( V_11 , V_26 ) ;
if ( V_5 < 0 )
return V_5 ;
V_41 = F_10 ( V_11 , V_43 -> V_46 ) ;
if ( ! V_41 )
return - V_56 ;
V_5 = F_16 ( V_43 -> V_47 , V_41 -> V_23 ) ;
if ( V_5 < 0 )
return V_5 ;
V_43 -> V_52 = F_17 ( V_57 , V_43 -> V_52 , V_5 ) ;
V_5 = F_18 ( V_41 -> V_23 , V_43 -> V_52 ,
V_43 -> V_48 ) ;
if ( V_5 < 0 )
return V_5 ;
V_43 -> V_53 = F_17 ( V_57 , V_43 -> V_53 , V_5 ) ;
return 0 ;
}
static int F_19 ( struct V_58 * V_58 , void * V_59 ,
struct V_37 * V_26 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
F_20 ( V_59 != V_58 -> V_60 ) ;
if ( V_26 -> type != V_61 )
return - V_56 ;
return F_12 ( V_11 , V_26 ) ;
}
static int F_21 ( struct V_58 * V_58 , void * V_59 ,
struct V_62 * V_63 )
{
if ( V_63 -> V_64 != 0 )
return - V_56 ;
V_63 -> type = V_65 ;
V_63 -> V_66 = V_67 ;
strcpy ( V_63 -> V_68 , L_6 ) ;
return 0 ;
}
static int F_22 ( struct V_58 * V_58 , void * V_59 , unsigned int * V_20 )
{
* V_20 = 0 ;
return 0 ;
}
static int F_23 ( struct V_58 * V_58 , void * V_59 , unsigned int V_20 )
{
if ( V_20 > 0 )
return - V_56 ;
return 0 ;
}
static int F_24 ( struct V_58 * V_58 , void * V_59 , T_1 * V_69 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_12 * V_13 = F_7 ( V_11 ) ;
return F_8 ( V_13 , V_14 , V_70 , * V_69 ) ;
}
static int F_25 ( struct V_58 * V_58 , void * V_59 , T_1 * V_69 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_12 * V_13 = F_7 ( V_11 ) ;
return F_8 ( V_13 , V_14 , V_71 , V_69 ) ;
}
static int F_26 ( struct V_58 * V_58 , void * V_72 ,
struct V_73 * V_74 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
return V_39 -> V_54 -> V_75 ( V_11 , V_74 ) ;
}
static int F_27 ( struct V_58 * V_58 , void * V_59 ,
struct V_76 * V_77 )
{
int V_5 ;
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
F_20 ( V_59 != V_58 -> V_60 ) ;
if ( V_11 -> V_78 && V_11 -> V_78 != V_58 )
return - V_79 ;
if ( V_39 -> V_54 -> V_80 ) {
V_5 = F_28 ( & V_11 -> V_81 , V_77 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = V_39 -> V_54 -> V_82 ( V_11 , V_77 ) ;
} else {
V_5 = F_29 ( & V_11 -> V_83 , V_77 ) ;
}
if ( ! V_5 && ! V_11 -> V_78 )
V_11 -> V_78 = V_58 ;
return V_5 ;
}
static int F_30 ( struct V_58 * V_58 , void * V_59 ,
struct V_84 * V_77 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
F_20 ( V_59 != V_58 -> V_60 ) ;
if ( V_39 -> V_54 -> V_80 )
return F_31 ( & V_11 -> V_81 , V_77 ) ;
else
return F_32 ( & V_11 -> V_83 , V_77 ) ;
}
static int F_33 ( struct V_58 * V_58 , void * V_59 ,
struct V_84 * V_77 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
F_20 ( V_59 != V_58 -> V_60 ) ;
if ( V_11 -> V_78 != V_58 )
return - V_79 ;
if ( V_39 -> V_54 -> V_80 )
return F_34 ( & V_11 -> V_81 , V_77 ) ;
else
return F_35 ( & V_11 -> V_83 , V_77 ) ;
}
static int F_36 ( struct V_58 * V_58 , void * V_59 ,
struct V_84 * V_77 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
F_20 ( V_59 != V_58 -> V_60 ) ;
if ( V_11 -> V_78 != V_58 )
return - V_79 ;
if ( V_39 -> V_54 -> V_80 )
return F_37 ( & V_11 -> V_81 , V_77 , V_58 -> V_85 & V_86 ) ;
else
return F_38 ( & V_11 -> V_83 , V_77 , V_58 -> V_85 & V_86 ) ;
}
static int F_39 ( struct V_58 * V_58 , void * V_59 ,
struct V_87 * V_88 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
if ( V_39 -> V_54 -> V_80 )
return - V_56 ;
else
return F_40 ( & V_11 -> V_83 , V_88 ) ;
}
static int F_41 ( struct V_58 * V_58 , void * V_59 ,
struct V_84 * V_89 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
if ( V_39 -> V_54 -> V_80 )
return - V_56 ;
else
return F_42 ( & V_11 -> V_83 , V_89 ) ;
}
static int F_43 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_7 ( V_11 ) ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
unsigned int V_20 , V_90 = 0 , V_91 = 0 ;
int V_5 ;
enum V_92 V_93 ;
while ( ! F_8 ( V_13 , V_94 , V_95 , V_91 , & V_93 ) )
V_91 ++ ;
if ( ! V_39 -> V_54 -> V_96 )
V_90 = V_91 ;
else
for ( V_20 = 0 ; V_20 < V_91 ; V_20 ++ ) {
V_5 = V_39 -> V_54 -> V_96 ( V_11 , V_20 , NULL ) ;
if ( V_5 < 0 )
return V_5 ;
V_90 += V_5 ;
}
if ( ! V_90 )
return - V_97 ;
V_11 -> V_22 =
F_44 ( V_90 * sizeof( struct V_18 ) ) ;
if ( ! V_11 -> V_22 )
return - V_98 ;
F_14 ( V_11 -> V_45 , L_7 , V_90 ) ;
V_90 = 0 ;
for ( V_20 = 0 ; V_20 < V_91 ; V_20 ++ )
if ( ! V_39 -> V_54 -> V_96 ) {
F_8 ( V_13 , V_94 , V_95 , V_20 , & V_93 ) ;
V_11 -> V_22 [ V_90 ] . V_23 =
F_45 ( V_93 ) ;
if ( V_11 -> V_22 [ V_90 ] . V_23 )
V_11 -> V_22 [ V_90 ++ ] . V_93 = V_93 ;
} else {
V_5 = V_39 -> V_54 -> V_96 ( V_11 , V_20 ,
& V_11 -> V_22 [ V_90 ] ) ;
if ( V_5 < 0 )
goto V_99;
V_90 += V_5 ;
}
V_11 -> V_21 = V_90 ;
V_11 -> V_100 = & V_11 -> V_22 [ 0 ] ;
return 0 ;
V_99:
F_46 ( V_11 -> V_22 ) ;
return V_5 ;
}
static void F_47 ( struct V_10 * V_11 )
{
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
if ( V_39 -> V_54 -> V_101 )
V_39 -> V_54 -> V_101 ( V_11 ) ;
V_11 -> V_100 = NULL ;
V_11 -> V_21 = 0 ;
F_46 ( V_11 -> V_22 ) ;
V_11 -> V_22 = NULL ;
}
static int F_48 ( struct V_10 * V_11 ,
struct V_37 * V_26 )
{
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
struct V_42 * V_43 = & V_26 -> V_44 . V_43 ;
int V_5 ;
F_14 ( V_11 -> V_45 , L_8 ,
F_15 ( V_43 -> V_46 ) , V_43 -> V_47 , V_43 -> V_48 ) ;
V_5 = F_12 ( V_11 , V_26 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = V_39 -> V_54 -> V_102 ( V_11 , V_26 ) ;
if ( V_5 < 0 ) {
return V_5 ;
} else if ( ! V_11 -> V_100 ||
V_11 -> V_100 -> V_23 -> V_19 != V_43 -> V_46 ) {
F_3 ( V_11 -> V_45 ,
L_9 ) ;
return - V_56 ;
}
V_11 -> V_103 = V_43 -> V_47 ;
V_11 -> V_104 = V_43 -> V_48 ;
V_11 -> V_52 = V_43 -> V_52 ;
V_11 -> V_53 = V_43 -> V_53 ;
V_11 -> V_105 = V_43 -> V_105 ;
V_11 -> V_106 = V_43 -> V_106 ;
if ( V_39 -> V_54 -> V_80 )
V_11 -> V_81 . V_106 = V_43 -> V_106 ;
F_14 ( V_11 -> V_45 , L_10 ,
V_11 -> V_103 , V_11 -> V_104 ) ;
return V_39 -> V_54 -> V_107 ( V_11 ) ;
}
static int F_49 ( struct V_58 * V_58 )
{
struct V_108 * V_109 = F_50 ( V_58 ) ;
struct V_10 * V_11 = F_51 ( V_109 -> V_40 ) ;
struct V_3 * V_4 = F_52 ( V_11 ) ;
struct V_38 * V_39 ;
int V_5 ;
if ( ! F_53 ( V_11 ) )
return - V_17 ;
V_39 = F_13 ( V_11 -> V_40 ) ;
if ( F_54 ( & V_11 -> V_110 ) )
return - V_111 ;
if ( ! F_55 ( V_39 -> V_54 -> V_112 ) ) {
F_3 ( V_11 -> V_45 , L_11 ) ;
V_5 = - V_56 ;
goto V_113;
}
V_11 -> V_114 ++ ;
if ( V_11 -> V_114 == 1 ) {
struct V_37 V_26 = {
. type = V_61 ,
. V_44 . V_43 = {
. V_47 = V_11 -> V_103 ,
. V_48 = V_11 -> V_104 ,
. V_106 = V_11 -> V_106 ,
. V_105 = V_11 -> V_105 ,
. V_46 =
V_11 -> V_100 -> V_23 -> V_19 ,
} ,
} ;
if ( V_4 -> V_115 )
V_4 -> V_115 ( V_11 -> V_45 ) ;
F_56 ( & V_39 -> V_116 ) ;
V_5 = V_39 -> V_54 -> V_117 ( V_11 ) ;
F_57 ( & V_39 -> V_116 ) ;
if ( V_5 < 0 ) {
F_3 ( V_11 -> V_45 , L_12 , V_5 ) ;
goto V_118;
}
V_5 = F_6 ( V_11 ) ;
if ( V_5 < 0 )
goto V_119;
F_58 ( & V_11 -> V_109 -> V_2 ) ;
V_5 = F_59 ( & V_11 -> V_109 -> V_2 ) ;
if ( V_5 < 0 && V_5 != - V_120 )
goto V_121;
V_5 = F_48 ( V_11 , & V_26 ) ;
if ( V_5 < 0 )
goto V_122;
if ( V_39 -> V_54 -> V_80 ) {
V_39 -> V_54 -> V_80 ( & V_11 -> V_81 , V_11 ) ;
} else {
V_5 = V_39 -> V_54 -> V_123 ( & V_11 -> V_83 , V_11 ) ;
if ( V_5 < 0 )
goto V_124;
}
F_60 ( & V_11 -> V_125 ) ;
}
F_57 ( & V_11 -> V_110 ) ;
V_58 -> V_60 = V_11 ;
F_14 ( V_11 -> V_45 , L_13 ) ;
return 0 ;
V_124:
V_122:
F_61 ( & V_11 -> V_109 -> V_2 ) ;
V_121:
F_9 ( V_11 ) ;
V_119:
V_39 -> V_54 -> remove ( V_11 ) ;
V_118:
V_11 -> V_114 -- ;
F_62 ( V_39 -> V_54 -> V_112 ) ;
V_113:
F_57 ( & V_11 -> V_110 ) ;
return V_5 ;
}
static int F_63 ( struct V_58 * V_58 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
F_56 ( & V_11 -> V_110 ) ;
V_11 -> V_114 -- ;
if ( ! V_11 -> V_114 ) {
F_64 ( & V_11 -> V_109 -> V_2 ) ;
F_61 ( & V_11 -> V_109 -> V_2 ) ;
if ( V_39 -> V_54 -> V_123 )
F_65 ( & V_11 -> V_83 ) ;
V_39 -> V_54 -> remove ( V_11 ) ;
F_9 ( V_11 ) ;
}
if ( V_11 -> V_78 == V_58 )
V_11 -> V_78 = NULL ;
F_57 ( & V_11 -> V_110 ) ;
F_62 ( V_39 -> V_54 -> V_112 ) ;
F_14 ( V_11 -> V_45 , L_14 ) ;
return 0 ;
}
static T_2 F_66 ( struct V_58 * V_58 , char T_3 * V_126 ,
T_4 V_127 , T_5 * V_128 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
int V_9 = - V_56 ;
F_3 ( V_11 -> V_45 , L_15 ) ;
return V_9 ;
}
static int F_67 ( struct V_58 * V_58 , struct V_129 * V_130 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
int V_9 ;
F_14 ( V_11 -> V_45 , L_16 , ( unsigned long ) V_130 ) ;
if ( V_11 -> V_78 != V_58 )
return - V_79 ;
if ( F_54 ( & V_11 -> V_110 ) )
return - V_111 ;
if ( V_39 -> V_54 -> V_80 )
V_9 = F_68 ( & V_11 -> V_81 , V_130 ) ;
else
V_9 = F_69 ( & V_11 -> V_83 , V_130 ) ;
F_57 ( & V_11 -> V_110 ) ;
F_14 ( V_11 -> V_45 , L_17 ,
( unsigned long ) V_130 -> V_131 ,
( unsigned long ) V_130 -> V_132 - ( unsigned long ) V_130 -> V_131 ,
V_9 ) ;
return V_9 ;
}
static unsigned int F_70 ( struct V_58 * V_58 , T_6 * V_133 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
unsigned V_134 = V_135 ;
if ( V_11 -> V_78 != V_58 )
return V_135 ;
F_56 ( & V_11 -> V_110 ) ;
if ( V_39 -> V_54 -> V_80 && F_71 ( & V_11 -> V_81 . V_136 ) )
F_3 ( V_11 -> V_45 , L_18 ) ;
else
V_134 = V_39 -> V_54 -> V_137 ( V_58 , V_133 ) ;
F_57 ( & V_11 -> V_110 ) ;
return V_134 ;
}
void F_72 ( struct V_138 * V_139 )
{
struct V_10 * V_11 = F_73 ( V_139 ) ;
F_56 ( & V_11 -> V_110 ) ;
}
void F_74 ( struct V_138 * V_139 )
{
struct V_10 * V_11 = F_73 ( V_139 ) ;
F_57 ( & V_11 -> V_110 ) ;
}
static int F_75 ( struct V_58 * V_58 , void * V_59 ,
struct V_37 * V_26 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
int V_5 ;
F_20 ( V_59 != V_58 -> V_60 ) ;
if ( V_26 -> type != V_61 ) {
F_76 ( V_11 -> V_45 , L_19 , V_26 -> type ) ;
return - V_56 ;
}
if ( V_11 -> V_78 && V_11 -> V_78 != V_58 )
return - V_79 ;
if ( F_77 ( F_13 ( V_11 -> V_40 ) , V_11 ) ) {
F_3 ( V_11 -> V_45 , L_20 ) ;
return - V_79 ;
}
V_5 = F_48 ( V_11 , V_26 ) ;
if ( ! V_5 && ! V_11 -> V_78 )
V_11 -> V_78 = V_58 ;
return V_5 ;
}
static int F_78 ( struct V_58 * V_58 , void * V_59 ,
struct V_140 * V_26 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
const struct V_141 * V_142 ;
F_20 ( V_59 != V_58 -> V_60 ) ;
if ( V_26 -> V_64 >= V_11 -> V_21 )
return - V_56 ;
V_142 = V_11 -> V_22 [ V_26 -> V_64 ] . V_23 ;
if ( V_142 -> V_68 )
F_79 ( V_26 -> V_143 , V_142 -> V_68 , sizeof( V_26 -> V_143 ) ) ;
V_26 -> V_46 = V_142 -> V_19 ;
return 0 ;
}
static int F_80 ( struct V_58 * V_58 , void * V_59 ,
struct V_37 * V_26 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_42 * V_43 = & V_26 -> V_44 . V_43 ;
F_20 ( V_59 != V_58 -> V_60 ) ;
if ( V_26 -> type != V_61 )
return - V_56 ;
V_43 -> V_47 = V_11 -> V_103 ;
V_43 -> V_48 = V_11 -> V_104 ;
V_43 -> V_52 = V_11 -> V_52 ;
V_43 -> V_53 = V_11 -> V_53 ;
V_43 -> V_106 = V_11 -> V_106 ;
V_43 -> V_46 = V_11 -> V_100 -> V_23 -> V_19 ;
V_43 -> V_105 = V_11 -> V_105 ;
F_14 ( V_11 -> V_45 , L_21 ,
V_11 -> V_100 -> V_23 -> V_19 ) ;
return 0 ;
}
static int F_81 ( struct V_58 * V_58 , void * V_59 ,
struct V_144 * V_145 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
F_20 ( V_59 != V_58 -> V_60 ) ;
F_79 ( V_145 -> V_146 , V_39 -> V_147 , sizeof( V_145 -> V_146 ) ) ;
return V_39 -> V_54 -> V_148 ( V_39 , V_145 ) ;
}
static int F_82 ( struct V_58 * V_58 , void * V_59 ,
enum V_149 V_20 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
struct V_12 * V_13 = F_7 ( V_11 ) ;
int V_5 ;
F_20 ( V_59 != V_58 -> V_60 ) ;
if ( V_20 != V_61 )
return - V_56 ;
if ( V_11 -> V_78 != V_58 )
return - V_79 ;
if ( V_39 -> V_54 -> V_80 )
V_5 = F_83 ( & V_11 -> V_81 ) ;
else
V_5 = F_84 ( & V_11 -> V_83 , V_20 ) ;
if ( ! V_5 )
F_8 ( V_13 , V_94 , V_150 , 1 ) ;
return V_5 ;
}
static int F_85 ( struct V_58 * V_58 , void * V_59 ,
enum V_149 V_20 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_12 * V_13 = F_7 ( V_11 ) ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
F_20 ( V_59 != V_58 -> V_60 ) ;
if ( V_20 != V_61 )
return - V_56 ;
if ( V_11 -> V_78 != V_58 )
return - V_79 ;
if ( V_39 -> V_54 -> V_80 )
F_86 ( & V_11 -> V_81 ) ;
else
F_87 ( & V_11 -> V_83 , V_20 ) ;
F_8 ( V_13 , V_94 , V_150 , 0 ) ;
return 0 ;
}
static int F_88 ( struct V_58 * V_58 , void * V_72 ,
struct V_151 * V_69 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
return V_39 -> V_54 -> V_152 ( V_11 , V_69 ) ;
}
static int F_89 ( struct V_58 * V_58 , void * V_72 ,
struct V_153 * V_69 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
int V_5 ;
V_5 = V_39 -> V_54 -> V_154 ( V_11 , V_69 ) ;
return V_5 ;
}
static int F_90 ( struct V_58 * V_58 , void * V_72 ,
const struct V_153 * V_69 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
const struct V_155 * V_156 = & V_69 -> V_157 ;
struct V_153 V_158 ;
int V_5 ;
if ( V_69 -> type != V_61 )
return - V_56 ;
F_14 ( V_11 -> V_45 , L_22 ,
V_156 -> V_47 , V_156 -> V_48 , V_156 -> V_159 , V_156 -> V_160 ) ;
V_5 = V_39 -> V_54 -> V_154 ( V_11 , & V_158 ) ;
if ( V_5 < 0 ) {
F_3 ( V_11 -> V_45 ,
L_23 ) ;
} else if ( ( V_69 -> V_157 . V_47 == V_158 . V_157 . V_47 &&
V_69 -> V_157 . V_48 == V_158 . V_157 . V_48 ) ||
! F_77 ( V_39 , V_11 ) ) {
V_5 = V_39 -> V_54 -> V_161 ( V_11 , V_69 ) ;
} else if ( V_39 -> V_54 -> V_162 ) {
V_5 = V_39 -> V_54 -> V_162 ( V_11 , V_69 ) ;
} else {
F_3 ( V_11 -> V_45 ,
L_24 ) ;
V_5 = - V_79 ;
}
return V_5 ;
}
static int F_91 ( struct V_58 * V_58 , void * V_72 ,
struct V_163 * V_164 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
if ( V_164 -> type != V_61 )
return - V_56 ;
if ( ! V_39 -> V_54 -> V_165 )
return - V_166 ;
return V_39 -> V_54 -> V_165 ( V_11 , V_164 ) ;
}
static int F_92 ( struct V_58 * V_58 , void * V_72 ,
struct V_163 * V_164 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
int V_5 ;
if ( V_164 -> type != V_61 ||
( V_164 -> V_167 != V_168 &&
V_164 -> V_167 != V_169 ) )
return - V_56 ;
if ( V_164 -> V_167 == V_168 ) {
if ( F_77 ( V_39 , V_11 ) &&
( V_11 -> V_103 != V_164 -> V_170 . V_47 ||
V_11 -> V_104 != V_164 -> V_170 . V_48 ) )
return - V_79 ;
if ( V_11 -> V_78 && V_11 -> V_78 != V_58 )
return - V_79 ;
}
if ( ! V_39 -> V_54 -> V_171 )
return - V_166 ;
V_5 = V_39 -> V_54 -> V_171 ( V_11 , V_164 ) ;
if ( ! V_5 &&
V_164 -> V_167 == V_168 ) {
V_11 -> V_103 = V_164 -> V_170 . V_47 ;
V_11 -> V_104 = V_164 -> V_170 . V_48 ;
if ( ! V_11 -> V_78 )
V_11 -> V_78 = V_58 ;
}
return V_5 ;
}
static int F_93 ( struct V_58 * V_58 , void * V_72 ,
struct V_172 * V_69 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
if ( V_39 -> V_54 -> V_173 )
return V_39 -> V_54 -> V_173 ( V_11 , V_69 ) ;
return - V_16 ;
}
static int F_94 ( struct V_58 * V_58 , void * V_72 ,
struct V_172 * V_69 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
if ( V_39 -> V_54 -> V_174 )
return V_39 -> V_54 -> V_174 ( V_11 , V_69 ) ;
return - V_16 ;
}
static int F_95 ( struct V_58 * V_58 , void * V_72 ,
struct V_175 * V_176 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_12 * V_13 = F_7 ( V_11 ) ;
return F_8 ( V_13 , V_14 , V_177 , V_176 ) ;
}
static int F_96 ( struct V_58 * V_58 , void * V_72 ,
struct V_178 * V_179 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_12 * V_13 = F_7 ( V_11 ) ;
return F_8 ( V_13 , V_14 , V_180 , V_179 ) ;
}
static int F_97 ( struct V_58 * V_58 , void * V_72 ,
struct V_178 * V_179 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_12 * V_13 = F_7 ( V_11 ) ;
return F_8 ( V_13 , V_14 , V_181 , V_179 ) ;
}
static void F_98 ( struct V_38 * V_39 )
{
struct V_10 * V_11 ;
F_56 ( & V_39 -> V_116 ) ;
F_99 (icd, &devices, list) {
if ( V_11 -> V_182 == V_39 -> V_183 ) {
int V_5 ;
V_11 -> V_40 = V_39 -> V_184 . V_2 ;
V_5 = F_100 ( V_11 ) ;
}
}
F_57 ( & V_39 -> V_116 ) ;
}
static int F_101 ( struct V_10 * V_11 ,
struct V_3 * V_4 )
{
struct V_185 * V_186 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
struct V_187 * V_188 = F_102 ( V_4 -> V_189 ) ;
struct V_12 * V_190 ;
if ( ! V_188 ) {
F_3 ( V_11 -> V_45 , L_25 ,
V_4 -> V_189 ) ;
goto V_191;
}
V_4 -> V_192 -> V_193 = V_4 ;
V_190 = F_103 ( & V_39 -> V_184 , V_188 ,
V_4 -> V_192 , NULL ) ;
if ( ! V_190 )
goto V_194;
V_186 = F_104 ( V_190 ) ;
V_11 -> V_195 = & V_186 -> V_2 ;
return 0 ;
V_194:
F_105 ( V_188 ) ;
V_191:
return - V_17 ;
}
static void F_106 ( struct V_10 * V_11 )
{
struct V_185 * V_186 =
F_107 ( F_53 ( V_11 ) ) ;
struct V_187 * V_188 = V_186 -> V_196 ;
V_11 -> V_195 = NULL ;
F_108 ( F_109 ( V_186 ) ) ;
F_110 ( V_186 ) ;
F_105 ( V_188 ) ;
}
static int F_100 ( struct V_10 * V_11 )
{
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
struct V_3 * V_4 = F_52 ( V_11 ) ;
struct V_1 * V_195 = NULL ;
struct V_12 * V_13 ;
struct V_197 V_198 ;
int V_5 ;
F_111 ( V_11 -> V_45 , L_26 , F_112 ( V_11 -> V_45 ) ) ;
V_5 = F_113 ( & V_11 -> V_125 , 16 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_114 ( V_11 -> V_45 , V_4 -> V_6 ,
V_4 -> V_7 ) ;
if ( V_5 < 0 )
goto V_199;
if ( V_4 -> V_115 )
V_4 -> V_115 ( V_11 -> V_45 ) ;
V_5 = V_39 -> V_54 -> V_117 ( V_11 ) ;
if ( V_5 < 0 )
goto V_200;
V_5 = F_115 ( V_11 ) ;
if ( V_5 < 0 )
goto V_201;
if ( V_4 -> V_192 ) {
V_5 = F_101 ( V_11 , V_4 ) ;
if ( V_5 < 0 )
goto V_202;
} else if ( ! V_4 -> V_203 || ! V_4 -> V_204 ) {
V_5 = - V_56 ;
goto V_202;
} else {
if ( V_4 -> V_205 )
V_5 = F_116 ( V_4 -> V_205 ) ;
V_5 = V_4 -> V_203 ( V_11 ) ;
if ( V_5 < 0 )
goto V_202;
V_195 = F_53 ( V_11 ) ;
if ( ! V_195 || ! V_195 -> V_146 || ! F_51 ( V_195 ) ||
! F_55 ( V_195 -> V_146 -> V_112 ) ) {
V_4 -> V_204 ( V_11 ) ;
V_5 = - V_17 ;
goto V_206;
}
}
V_13 = F_7 ( V_11 ) ;
V_13 -> V_207 = F_117 ( V_11 ) ;
F_118 ( V_13 , V_11 ) ;
V_5 = F_119 ( & V_11 -> V_125 , V_13 -> V_125 , NULL ) ;
if ( V_5 < 0 )
goto V_208;
V_5 = F_43 ( V_11 ) ;
if ( V_5 < 0 )
goto V_209;
V_11 -> V_106 = V_210 ;
F_56 ( & V_11 -> V_110 ) ;
V_5 = F_120 ( V_11 ) ;
if ( V_5 < 0 )
goto V_211;
if ( ! F_8 ( V_13 , V_94 , V_212 , & V_198 ) ) {
V_11 -> V_103 = V_198 . V_47 ;
V_11 -> V_104 = V_198 . V_48 ;
V_11 -> V_105 = V_198 . V_105 ;
V_11 -> V_106 = V_198 . V_106 ;
}
V_39 -> V_54 -> remove ( V_11 ) ;
F_57 ( & V_11 -> V_110 ) ;
return 0 ;
V_211:
F_57 ( & V_11 -> V_110 ) ;
F_47 ( V_11 ) ;
V_209:
V_208:
if ( V_4 -> V_192 ) {
F_106 ( V_11 ) ;
} else {
V_4 -> V_204 ( V_11 ) ;
F_62 ( V_195 -> V_146 -> V_112 ) ;
}
V_206:
V_202:
F_121 ( V_11 -> V_109 ) ;
V_11 -> V_109 = NULL ;
V_201:
V_39 -> V_54 -> remove ( V_11 ) ;
V_200:
F_122 ( V_4 -> V_6 , V_4 -> V_7 ) ;
V_199:
F_123 ( & V_11 -> V_125 ) ;
return V_5 ;
}
static int F_124 ( struct V_10 * V_11 )
{
struct V_3 * V_4 = F_52 ( V_11 ) ;
struct V_108 * V_109 = V_11 -> V_109 ;
F_125 ( ! V_11 -> V_40 ) ;
F_123 ( & V_11 -> V_125 ) ;
if ( V_109 ) {
F_126 ( V_109 ) ;
V_11 -> V_109 = NULL ;
}
if ( V_4 -> V_192 ) {
F_106 ( V_11 ) ;
} else {
struct V_213 * V_214 = F_53 ( V_11 ) -> V_146 ;
if ( V_214 ) {
V_4 -> V_204 ( V_11 ) ;
F_62 ( V_214 -> V_112 ) ;
}
}
F_47 ( V_11 ) ;
F_122 ( V_4 -> V_6 , V_4 -> V_7 ) ;
return 0 ;
}
static int F_127 ( struct V_10 * V_11 ,
struct V_151 * V_69 )
{
struct V_12 * V_13 = F_7 ( V_11 ) ;
return F_8 ( V_13 , V_94 , V_152 , V_69 ) ;
}
static int F_128 ( struct V_10 * V_11 , struct V_153 * V_69 )
{
struct V_12 * V_13 = F_7 ( V_11 ) ;
return F_8 ( V_13 , V_94 , V_215 , V_69 ) ;
}
static int F_129 ( struct V_10 * V_11 , const struct V_153 * V_69 )
{
struct V_12 * V_13 = F_7 ( V_11 ) ;
return F_8 ( V_13 , V_94 , V_216 , V_69 ) ;
}
static int F_130 ( struct V_10 * V_11 ,
struct V_172 * V_217 )
{
struct V_12 * V_13 = F_7 ( V_11 ) ;
return F_8 ( V_13 , V_94 , V_218 , V_217 ) ;
}
static int F_131 ( struct V_10 * V_11 ,
struct V_172 * V_217 )
{
struct V_12 * V_13 = F_7 ( V_11 ) ;
return F_8 ( V_13 , V_94 , V_219 , V_217 ) ;
}
static int F_132 ( struct V_10 * V_11 ,
struct V_73 * V_74 )
{
int V_5 ;
struct V_12 * V_13 = F_7 ( V_11 ) ;
const struct V_18 * V_41 ;
T_7 V_220 = V_74 -> V_221 ;
struct V_73 V_222 = * V_74 ;
V_41 = F_10 ( V_11 , V_220 ) ;
if ( ! V_41 )
return - V_56 ;
V_222 . V_221 = V_41 -> V_93 ;
V_5 = F_8 ( V_13 , V_94 , V_75 , & V_222 ) ;
if ( V_5 < 0 )
return V_5 ;
* V_74 = V_222 ;
V_74 -> V_221 = V_220 ;
return 0 ;
}
int F_133 ( struct V_38 * V_39 )
{
struct V_38 * V_223 ;
int V_5 ;
if ( ! V_39 || ! V_39 -> V_54 ||
! V_39 -> V_54 -> V_55 ||
! V_39 -> V_54 -> V_102 ||
! V_39 -> V_54 -> V_107 ||
! V_39 -> V_54 -> V_148 ||
( ( ! V_39 -> V_54 -> V_80 ||
! V_39 -> V_54 -> V_82 ) &&
! V_39 -> V_54 -> V_123 ) ||
! V_39 -> V_54 -> V_117 ||
! V_39 -> V_54 -> remove ||
! V_39 -> V_54 -> V_137 ||
! V_39 -> V_184 . V_2 )
return - V_56 ;
if ( ! V_39 -> V_54 -> V_161 )
V_39 -> V_54 -> V_161 = F_129 ;
if ( ! V_39 -> V_54 -> V_154 )
V_39 -> V_54 -> V_154 = F_128 ;
if ( ! V_39 -> V_54 -> V_152 )
V_39 -> V_54 -> V_152 = F_127 ;
if ( ! V_39 -> V_54 -> V_174 )
V_39 -> V_54 -> V_174 = F_131 ;
if ( ! V_39 -> V_54 -> V_173 )
V_39 -> V_54 -> V_173 = F_130 ;
if ( ! V_39 -> V_54 -> V_75 )
V_39 -> V_54 -> V_75 = F_132 ;
F_56 ( & V_224 ) ;
F_99 (ix, &hosts, list) {
if ( V_223 -> V_183 == V_39 -> V_183 ) {
V_5 = - V_79 ;
goto V_225;
}
}
V_5 = F_134 ( V_39 -> V_184 . V_2 , & V_39 -> V_184 ) ;
if ( V_5 < 0 )
goto V_225;
F_135 ( & V_39 -> V_226 , & V_227 ) ;
F_57 ( & V_224 ) ;
F_136 ( & V_39 -> V_116 ) ;
F_98 ( V_39 ) ;
return 0 ;
V_225:
F_57 ( & V_224 ) ;
return V_5 ;
}
void F_137 ( struct V_38 * V_39 )
{
struct V_10 * V_11 ;
F_56 ( & V_224 ) ;
F_138 ( & V_39 -> V_226 ) ;
F_99 (icd, &devices, list)
if ( V_11 -> V_182 == V_39 -> V_183 && F_53 ( V_11 ) )
F_124 ( V_11 ) ;
F_57 ( & V_224 ) ;
F_139 ( & V_39 -> V_184 ) ;
}
static int F_140 ( struct V_10 * V_11 )
{
struct V_10 * V_223 ;
int V_228 = - 1 , V_20 ;
for ( V_20 = 0 ; V_20 < 256 && V_228 < 0 ; V_20 ++ ) {
V_228 = V_20 ;
F_99 (ix, &devices, list) {
if ( V_223 -> V_182 == V_11 -> V_182 && V_223 -> V_229 == V_20 ) {
V_228 = - 1 ;
break;
}
}
}
if ( V_228 < 0 )
return - V_98 ;
V_11 -> V_229 = V_228 ;
V_11 -> V_114 = 0 ;
V_11 -> V_230 = NULL ;
F_136 ( & V_11 -> V_110 ) ;
F_135 ( & V_11 -> V_226 , & V_231 ) ;
return 0 ;
}
static int F_115 ( struct V_10 * V_11 )
{
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
struct V_108 * V_109 = F_141 () ;
if ( ! V_109 )
return - V_98 ;
F_79 ( V_109 -> V_68 , V_39 -> V_147 , sizeof( V_109 -> V_68 ) ) ;
V_109 -> V_40 = V_11 -> V_45 ;
V_109 -> V_232 = V_67 ;
V_109 -> V_233 = & V_234 ;
V_109 -> V_235 = & V_236 ;
V_109 -> V_237 = F_121 ;
V_109 -> V_238 = V_67 ;
V_109 -> V_125 = & V_11 -> V_125 ;
V_109 -> V_239 = & V_11 -> V_110 ;
V_11 -> V_109 = V_109 ;
return 0 ;
}
static int F_120 ( struct V_10 * V_11 )
{
const struct V_240 * type = V_11 -> V_109 -> V_2 . type ;
int V_5 ;
if ( ! V_11 -> V_40 )
return - V_17 ;
V_5 = F_142 ( V_11 -> V_109 , V_241 , - 1 ) ;
if ( V_5 < 0 ) {
F_3 ( V_11 -> V_45 , L_27 , V_5 ) ;
return V_5 ;
}
V_11 -> V_109 -> V_2 . type = type ;
return 0 ;
}
static int T_8 F_143 ( struct V_242 * V_45 )
{
struct V_3 * V_4 = V_45 -> V_2 . V_193 ;
struct V_10 * V_11 ;
if ( ! V_4 )
return - V_56 ;
V_11 = F_144 ( & V_45 -> V_2 , sizeof( * V_11 ) , V_243 ) ;
if ( ! V_11 )
return - V_98 ;
V_11 -> V_182 = V_4 -> V_244 ;
V_11 -> V_245 = V_4 ;
V_11 -> V_45 = & V_45 -> V_2 ;
F_145 ( V_45 , V_11 ) ;
V_11 -> V_103 = V_246 ;
V_11 -> V_104 = V_247 ;
return F_140 ( V_11 ) ;
}
static int T_9 F_146 ( struct V_242 * V_45 )
{
struct V_10 * V_11 = F_147 ( V_45 ) ;
if ( ! V_11 )
return - V_56 ;
F_138 ( & V_11 -> V_226 ) ;
return 0 ;
}

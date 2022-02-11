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
static int F_24 ( struct V_58 * V_58 , void * V_59 , T_1 V_69 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_12 * V_13 = F_7 ( V_11 ) ;
return F_8 ( V_13 , V_14 , V_70 , V_69 ) ;
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
struct V_10 * V_11 ;
struct V_38 * V_39 ;
int V_5 ;
if ( F_51 ( & V_110 ) )
return - V_111 ;
if ( ! V_109 || ! F_52 ( V_109 ) ) {
F_53 ( & V_110 ) ;
return - V_17 ;
}
V_11 = F_54 ( V_109 -> V_40 ) ;
V_39 = F_13 ( V_11 -> V_40 ) ;
V_5 = F_55 ( V_39 -> V_54 -> V_112 ) ? 0 : - V_17 ;
F_53 ( & V_110 ) ;
if ( V_5 < 0 ) {
F_3 ( V_11 -> V_45 , L_11 ) ;
return V_5 ;
}
if ( ! F_56 ( V_11 ) ) {
V_5 = - V_17 ;
goto V_113;
}
if ( F_51 ( & V_39 -> V_114 ) ) {
V_5 = - V_111 ;
goto V_115;
}
V_11 -> V_116 ++ ;
if ( V_11 -> V_116 == 1 ) {
struct V_117 * V_118 = F_57 ( V_11 ) ;
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
if ( V_118 -> V_119 . V_120 )
V_118 -> V_119 . V_120 ( V_11 -> V_45 ) ;
V_5 = V_39 -> V_54 -> V_121 ( V_11 ) ;
if ( V_5 < 0 ) {
F_3 ( V_11 -> V_45 , L_12 , V_5 ) ;
goto V_122;
}
V_5 = F_6 ( V_11 ) ;
if ( V_5 < 0 )
goto V_123;
F_58 ( & V_11 -> V_109 -> V_2 ) ;
V_5 = F_59 ( & V_11 -> V_109 -> V_2 ) ;
if ( V_5 < 0 && V_5 != - V_124 )
goto V_125;
V_5 = F_48 ( V_11 , & V_26 ) ;
if ( V_5 < 0 )
goto V_126;
if ( V_39 -> V_54 -> V_80 ) {
V_39 -> V_54 -> V_80 ( & V_11 -> V_81 , V_11 ) ;
} else {
V_5 = V_39 -> V_54 -> V_127 ( & V_11 -> V_83 , V_11 ) ;
if ( V_5 < 0 )
goto V_128;
}
F_60 ( & V_11 -> V_129 ) ;
}
F_53 ( & V_39 -> V_114 ) ;
V_58 -> V_60 = V_11 ;
F_14 ( V_11 -> V_45 , L_13 ) ;
return 0 ;
V_128:
V_126:
F_61 ( & V_11 -> V_109 -> V_2 ) ;
V_125:
F_9 ( V_11 ) ;
V_123:
V_39 -> V_54 -> remove ( V_11 ) ;
V_122:
V_11 -> V_116 -- ;
F_53 ( & V_39 -> V_114 ) ;
V_115:
V_113:
F_62 ( V_39 -> V_54 -> V_112 ) ;
return V_5 ;
}
static int F_63 ( struct V_58 * V_58 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
F_64 ( & V_39 -> V_114 ) ;
V_11 -> V_116 -- ;
if ( ! V_11 -> V_116 ) {
F_65 ( & V_11 -> V_109 -> V_2 ) ;
F_61 ( & V_11 -> V_109 -> V_2 ) ;
if ( V_39 -> V_54 -> V_127 )
F_66 ( & V_11 -> V_83 ) ;
F_9 ( V_11 ) ;
V_39 -> V_54 -> remove ( V_11 ) ;
}
if ( V_11 -> V_78 == V_58 )
V_11 -> V_78 = NULL ;
F_53 ( & V_39 -> V_114 ) ;
F_62 ( V_39 -> V_54 -> V_112 ) ;
F_14 ( V_11 -> V_45 , L_14 ) ;
return 0 ;
}
static T_2 F_67 ( struct V_58 * V_58 , char T_3 * V_130 ,
T_4 V_131 , T_5 * V_132 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
F_14 ( V_11 -> V_45 , L_15 , V_130 ) ;
if ( V_39 -> V_54 -> V_127 && V_11 -> V_83 . V_133 & V_134 )
return F_68 ( & V_11 -> V_83 , V_130 , V_131 , V_132 ,
V_58 -> V_85 & V_86 ) ;
F_3 ( V_11 -> V_45 , L_16 ) ;
return - V_56 ;
}
static int F_69 ( struct V_58 * V_58 , struct V_135 * V_136 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
int V_9 ;
F_14 ( V_11 -> V_45 , L_17 , ( unsigned long ) V_136 ) ;
if ( V_11 -> V_78 != V_58 )
return - V_79 ;
if ( F_51 ( & V_39 -> V_114 ) )
return - V_111 ;
if ( V_39 -> V_54 -> V_80 )
V_9 = F_70 ( & V_11 -> V_81 , V_136 ) ;
else
V_9 = F_71 ( & V_11 -> V_83 , V_136 ) ;
F_53 ( & V_39 -> V_114 ) ;
F_14 ( V_11 -> V_45 , L_18 ,
( unsigned long ) V_136 -> V_137 ,
( unsigned long ) V_136 -> V_138 - ( unsigned long ) V_136 -> V_137 ,
V_9 ) ;
return V_9 ;
}
static unsigned int F_72 ( struct V_58 * V_58 , T_6 * V_139 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
unsigned V_140 = V_141 ;
if ( V_11 -> V_78 != V_58 )
return V_141 ;
F_64 ( & V_39 -> V_114 ) ;
if ( V_39 -> V_54 -> V_80 && F_73 ( & V_11 -> V_81 . V_142 ) )
F_3 ( V_11 -> V_45 , L_19 ) ;
else
V_140 = V_39 -> V_54 -> V_143 ( V_58 , V_139 ) ;
F_53 ( & V_39 -> V_114 ) ;
return V_140 ;
}
void F_74 ( struct V_144 * V_145 )
{
struct V_10 * V_11 = F_75 ( V_145 ) ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
F_64 ( & V_39 -> V_114 ) ;
}
void F_76 ( struct V_144 * V_145 )
{
struct V_10 * V_11 = F_75 ( V_145 ) ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
F_53 ( & V_39 -> V_114 ) ;
}
static int F_77 ( struct V_58 * V_58 , void * V_59 ,
struct V_37 * V_26 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
int V_5 ;
F_20 ( V_59 != V_58 -> V_60 ) ;
if ( V_26 -> type != V_61 ) {
F_78 ( V_11 -> V_45 , L_20 , V_26 -> type ) ;
return - V_56 ;
}
if ( V_11 -> V_78 && V_11 -> V_78 != V_58 )
return - V_79 ;
if ( F_79 ( F_13 ( V_11 -> V_40 ) , V_11 ) ) {
F_3 ( V_11 -> V_45 , L_21 ) ;
return - V_79 ;
}
V_5 = F_48 ( V_11 , V_26 ) ;
if ( ! V_5 && ! V_11 -> V_78 )
V_11 -> V_78 = V_58 ;
return V_5 ;
}
static int F_80 ( struct V_58 * V_58 , void * V_59 ,
struct V_146 * V_26 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
const struct V_147 * V_148 ;
F_20 ( V_59 != V_58 -> V_60 ) ;
if ( V_26 -> V_64 >= V_11 -> V_21 )
return - V_56 ;
V_148 = V_11 -> V_22 [ V_26 -> V_64 ] . V_23 ;
if ( V_148 -> V_68 )
F_81 ( V_26 -> V_149 , V_148 -> V_68 , sizeof( V_26 -> V_149 ) ) ;
V_26 -> V_46 = V_148 -> V_19 ;
return 0 ;
}
static int F_82 ( struct V_58 * V_58 , void * V_59 ,
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
F_14 ( V_11 -> V_45 , L_22 ,
V_11 -> V_100 -> V_23 -> V_19 ) ;
return 0 ;
}
static int F_83 ( struct V_58 * V_58 , void * V_59 ,
struct V_150 * V_151 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
F_20 ( V_59 != V_58 -> V_60 ) ;
F_81 ( V_151 -> V_152 , V_39 -> V_153 , sizeof( V_151 -> V_152 ) ) ;
return V_39 -> V_54 -> V_154 ( V_39 , V_151 ) ;
}
static int F_84 ( struct V_58 * V_58 , void * V_59 ,
enum V_155 V_20 )
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
V_5 = F_85 ( & V_11 -> V_81 ) ;
else
V_5 = F_86 ( & V_11 -> V_83 , V_20 ) ;
if ( ! V_5 )
F_8 ( V_13 , V_94 , V_156 , 1 ) ;
return V_5 ;
}
static int F_87 ( struct V_58 * V_58 , void * V_59 ,
enum V_155 V_20 )
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
F_88 ( & V_11 -> V_81 ) ;
else
F_89 ( & V_11 -> V_83 , V_20 ) ;
F_8 ( V_13 , V_94 , V_156 , 0 ) ;
return 0 ;
}
static int F_90 ( struct V_58 * V_58 , void * V_72 ,
struct V_157 * V_69 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
return V_39 -> V_54 -> V_158 ( V_11 , V_69 ) ;
}
static int F_91 ( struct V_58 * V_58 , void * V_72 ,
struct V_159 * V_69 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
int V_5 ;
V_5 = V_39 -> V_54 -> V_160 ( V_11 , V_69 ) ;
return V_5 ;
}
static int F_92 ( struct V_58 * V_58 , void * V_72 ,
const struct V_159 * V_69 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
const struct V_161 * V_162 = & V_69 -> V_163 ;
struct V_159 V_164 ;
int V_5 ;
if ( V_69 -> type != V_61 )
return - V_56 ;
F_14 ( V_11 -> V_45 , L_23 ,
V_162 -> V_47 , V_162 -> V_48 , V_162 -> V_165 , V_162 -> V_166 ) ;
V_164 . type = V_69 -> type ;
V_5 = V_39 -> V_54 -> V_160 ( V_11 , & V_164 ) ;
if ( V_5 < 0 ) {
F_3 ( V_11 -> V_45 ,
L_24 ) ;
} else if ( ( V_69 -> V_163 . V_47 == V_164 . V_163 . V_47 &&
V_69 -> V_163 . V_48 == V_164 . V_163 . V_48 ) ||
! F_79 ( V_39 , V_11 ) ) {
V_5 = V_39 -> V_54 -> V_167 ( V_11 , V_69 ) ;
} else if ( V_39 -> V_54 -> V_168 ) {
V_5 = V_39 -> V_54 -> V_168 ( V_11 , V_69 ) ;
} else {
F_3 ( V_11 -> V_45 ,
L_25 ) ;
V_5 = - V_79 ;
}
return V_5 ;
}
static int F_93 ( struct V_58 * V_58 , void * V_72 ,
struct V_169 * V_170 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
if ( V_170 -> type != V_61 )
return - V_56 ;
if ( ! V_39 -> V_54 -> V_171 )
return - V_172 ;
return V_39 -> V_54 -> V_171 ( V_11 , V_170 ) ;
}
static int F_94 ( struct V_58 * V_58 , void * V_72 ,
struct V_169 * V_170 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
int V_5 ;
if ( V_170 -> type != V_61 ||
( V_170 -> V_173 != V_174 &&
V_170 -> V_173 != V_175 ) )
return - V_56 ;
if ( V_170 -> V_173 == V_174 ) {
if ( F_79 ( V_39 , V_11 ) &&
( V_11 -> V_103 != V_170 -> V_176 . V_47 ||
V_11 -> V_104 != V_170 -> V_176 . V_48 ) )
return - V_79 ;
if ( V_11 -> V_78 && V_11 -> V_78 != V_58 )
return - V_79 ;
}
if ( ! V_39 -> V_54 -> V_177 )
return - V_172 ;
V_5 = V_39 -> V_54 -> V_177 ( V_11 , V_170 ) ;
if ( ! V_5 &&
V_170 -> V_173 == V_174 ) {
V_11 -> V_103 = V_170 -> V_176 . V_47 ;
V_11 -> V_104 = V_170 -> V_176 . V_48 ;
if ( ! V_11 -> V_78 )
V_11 -> V_78 = V_58 ;
}
return V_5 ;
}
static int F_95 ( struct V_58 * V_58 , void * V_72 ,
struct V_178 * V_69 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
if ( V_39 -> V_54 -> V_179 )
return V_39 -> V_54 -> V_179 ( V_11 , V_69 ) ;
return - V_16 ;
}
static int F_96 ( struct V_58 * V_58 , void * V_72 ,
struct V_178 * V_69 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
if ( V_39 -> V_54 -> V_180 )
return V_39 -> V_54 -> V_180 ( V_11 , V_69 ) ;
return - V_16 ;
}
static int F_97 ( struct V_58 * V_58 , void * V_72 ,
struct V_181 * V_182 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_12 * V_13 = F_7 ( V_11 ) ;
return F_8 ( V_13 , V_14 , V_183 , V_182 ) ;
}
static int F_98 ( struct V_58 * V_58 , void * V_72 ,
struct V_184 * V_185 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_12 * V_13 = F_7 ( V_11 ) ;
return F_8 ( V_13 , V_14 , V_186 , V_185 ) ;
}
static int F_99 ( struct V_58 * V_58 , void * V_72 ,
const struct V_184 * V_185 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_12 * V_13 = F_7 ( V_11 ) ;
return F_8 ( V_13 , V_14 , V_187 , V_185 ) ;
}
static void F_100 ( struct V_38 * V_39 )
{
struct V_10 * V_11 ;
F_64 ( & V_110 ) ;
F_101 (icd, &devices, list) {
if ( V_11 -> V_188 == V_39 -> V_189 ) {
V_11 -> V_40 = V_39 -> V_190 . V_2 ;
F_102 ( V_11 ) ;
}
}
F_53 ( & V_110 ) ;
}
static int F_103 ( struct V_10 * V_11 ,
struct V_117 * V_118 )
{
struct V_191 * V_192 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
struct V_193 * V_194 = & V_118 -> V_195 ;
struct V_196 * V_197 = F_104 ( V_194 -> V_198 ) ;
struct V_12 * V_199 ;
if ( ! V_197 ) {
F_3 ( V_11 -> V_45 , L_26 ,
V_194 -> V_198 ) ;
goto V_200;
}
V_194 -> V_201 -> V_202 = & V_118 -> V_119 ;
V_199 = F_105 ( & V_39 -> V_190 , V_197 ,
V_194 -> V_201 , NULL ) ;
if ( ! V_199 )
goto V_203;
V_192 = F_106 ( V_199 ) ;
V_11 -> V_204 = & V_192 -> V_2 ;
return 0 ;
V_203:
F_107 ( V_197 ) ;
V_200:
return - V_17 ;
}
static void F_108 ( struct V_10 * V_11 )
{
struct V_191 * V_192 =
F_109 ( F_56 ( V_11 ) ) ;
struct V_196 * V_197 = V_192 -> V_205 ;
V_11 -> V_204 = NULL ;
F_110 ( F_111 ( V_192 ) ) ;
F_112 ( V_192 ) ;
F_107 ( V_197 ) ;
}
static int F_102 ( struct V_10 * V_11 )
{
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
struct V_117 * V_118 = F_57 ( V_11 ) ;
struct V_193 * V_194 = & V_118 -> V_195 ;
struct V_3 * V_4 = & V_118 -> V_119 ;
struct V_1 * V_204 = NULL ;
struct V_12 * V_13 ;
struct V_206 V_207 ;
int V_5 ;
F_113 ( V_11 -> V_45 , L_27 , F_114 ( V_11 -> V_45 ) ) ;
V_5 = F_115 ( & V_11 -> V_129 , 16 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_4 -> V_120 )
V_4 -> V_120 ( V_11 -> V_45 ) ;
F_64 ( & V_39 -> V_114 ) ;
V_5 = V_39 -> V_54 -> V_121 ( V_11 ) ;
F_53 ( & V_39 -> V_114 ) ;
if ( V_5 < 0 )
goto V_208;
V_5 = F_116 ( V_11 ) ;
if ( V_5 < 0 )
goto V_209;
if ( V_194 -> V_201 ) {
V_5 = F_103 ( V_11 , V_118 ) ;
if ( V_5 < 0 )
goto V_210;
} else if ( ! V_194 -> V_211 || ! V_194 -> V_212 ) {
V_5 = - V_56 ;
goto V_210;
} else {
if ( V_194 -> V_213 )
V_5 = F_117 ( V_194 -> V_213 ) ;
V_5 = V_194 -> V_211 ( V_11 ) ;
if ( V_5 < 0 )
goto V_210;
V_204 = F_56 ( V_11 ) ;
if ( ! V_204 || ! V_204 -> V_152 || ! F_54 ( V_204 ) ||
! F_55 ( V_204 -> V_152 -> V_112 ) ) {
V_194 -> V_212 ( V_11 ) ;
V_5 = - V_17 ;
goto V_214;
}
}
V_13 = F_7 ( V_11 ) ;
V_13 -> V_215 = F_118 ( V_11 ) ;
F_119 ( V_13 , V_11 ) ;
V_5 = F_120 ( & V_11 -> V_129 , V_13 -> V_129 , NULL ) ;
if ( V_5 < 0 )
goto V_216;
V_5 = F_43 ( V_11 ) ;
if ( V_5 < 0 )
goto V_217;
V_11 -> V_106 = V_218 ;
F_64 ( & V_39 -> V_114 ) ;
V_5 = F_121 ( V_11 ) ;
if ( V_5 < 0 )
goto V_219;
if ( ! F_8 ( V_13 , V_94 , V_220 , & V_207 ) ) {
V_11 -> V_103 = V_207 . V_47 ;
V_11 -> V_104 = V_207 . V_48 ;
V_11 -> V_105 = V_207 . V_105 ;
V_11 -> V_106 = V_207 . V_106 ;
}
V_39 -> V_54 -> remove ( V_11 ) ;
F_53 ( & V_39 -> V_114 ) ;
return 0 ;
V_219:
F_53 ( & V_39 -> V_114 ) ;
F_47 ( V_11 ) ;
V_217:
V_216:
if ( V_194 -> V_201 ) {
F_108 ( V_11 ) ;
} else {
V_194 -> V_212 ( V_11 ) ;
F_62 ( V_204 -> V_152 -> V_112 ) ;
}
V_214:
V_210:
F_122 ( V_11 -> V_109 ) ;
V_11 -> V_109 = NULL ;
V_209:
F_64 ( & V_39 -> V_114 ) ;
V_39 -> V_54 -> remove ( V_11 ) ;
F_53 ( & V_39 -> V_114 ) ;
V_208:
F_123 ( & V_11 -> V_129 ) ;
return V_5 ;
}
static int F_124 ( struct V_10 * V_11 )
{
struct V_117 * V_118 = F_57 ( V_11 ) ;
struct V_108 * V_109 = V_11 -> V_109 ;
F_125 ( ! V_11 -> V_40 ) ;
F_123 ( & V_11 -> V_129 ) ;
if ( V_109 ) {
F_126 ( V_109 ) ;
V_11 -> V_109 = NULL ;
}
if ( V_118 -> V_195 . V_201 ) {
F_108 ( V_11 ) ;
} else {
struct V_221 * V_222 = F_56 ( V_11 ) -> V_152 ;
if ( V_222 ) {
V_118 -> V_195 . V_212 ( V_11 ) ;
F_62 ( V_222 -> V_112 ) ;
}
}
F_47 ( V_11 ) ;
return 0 ;
}
static int F_127 ( struct V_10 * V_11 ,
struct V_157 * V_69 )
{
struct V_12 * V_13 = F_7 ( V_11 ) ;
return F_8 ( V_13 , V_94 , V_158 , V_69 ) ;
}
static int F_128 ( struct V_10 * V_11 , struct V_159 * V_69 )
{
struct V_12 * V_13 = F_7 ( V_11 ) ;
return F_8 ( V_13 , V_94 , V_223 , V_69 ) ;
}
static int F_129 ( struct V_10 * V_11 , const struct V_159 * V_69 )
{
struct V_12 * V_13 = F_7 ( V_11 ) ;
return F_8 ( V_13 , V_94 , V_224 , V_69 ) ;
}
static int F_130 ( struct V_10 * V_11 ,
struct V_178 * V_225 )
{
struct V_12 * V_13 = F_7 ( V_11 ) ;
return F_8 ( V_13 , V_94 , V_226 , V_225 ) ;
}
static int F_131 ( struct V_10 * V_11 ,
struct V_178 * V_225 )
{
struct V_12 * V_13 = F_7 ( V_11 ) ;
return F_8 ( V_13 , V_94 , V_227 , V_225 ) ;
}
static int F_132 ( struct V_10 * V_11 ,
struct V_73 * V_74 )
{
int V_5 ;
struct V_12 * V_13 = F_7 ( V_11 ) ;
const struct V_18 * V_41 ;
T_7 V_228 = V_74 -> V_229 ;
struct V_73 V_230 = * V_74 ;
V_41 = F_10 ( V_11 , V_228 ) ;
if ( ! V_41 )
return - V_56 ;
V_230 . V_229 = V_41 -> V_93 ;
V_5 = F_8 ( V_13 , V_94 , V_75 , & V_230 ) ;
if ( V_5 < 0 )
return V_5 ;
* V_74 = V_230 ;
V_74 -> V_229 = V_228 ;
return 0 ;
}
int F_133 ( struct V_38 * V_39 )
{
struct V_38 * V_231 ;
int V_5 ;
if ( ! V_39 || ! V_39 -> V_54 ||
! V_39 -> V_54 -> V_55 ||
! V_39 -> V_54 -> V_102 ||
! V_39 -> V_54 -> V_107 ||
! V_39 -> V_54 -> V_154 ||
( ( ! V_39 -> V_54 -> V_80 ||
! V_39 -> V_54 -> V_82 ) &&
! V_39 -> V_54 -> V_127 ) ||
! V_39 -> V_54 -> V_121 ||
! V_39 -> V_54 -> remove ||
! V_39 -> V_54 -> V_143 ||
! V_39 -> V_190 . V_2 )
return - V_56 ;
if ( ! V_39 -> V_54 -> V_167 )
V_39 -> V_54 -> V_167 = F_129 ;
if ( ! V_39 -> V_54 -> V_160 )
V_39 -> V_54 -> V_160 = F_128 ;
if ( ! V_39 -> V_54 -> V_158 )
V_39 -> V_54 -> V_158 = F_127 ;
if ( ! V_39 -> V_54 -> V_180 )
V_39 -> V_54 -> V_180 = F_131 ;
if ( ! V_39 -> V_54 -> V_179 )
V_39 -> V_54 -> V_179 = F_130 ;
if ( ! V_39 -> V_54 -> V_75 )
V_39 -> V_54 -> V_75 = F_132 ;
F_64 ( & V_110 ) ;
F_101 (ix, &hosts, list) {
if ( V_231 -> V_189 == V_39 -> V_189 ) {
V_5 = - V_79 ;
goto V_232;
}
}
V_5 = F_134 ( V_39 -> V_190 . V_2 , & V_39 -> V_190 ) ;
if ( V_5 < 0 )
goto V_232;
F_135 ( & V_39 -> V_233 , & V_234 ) ;
F_53 ( & V_110 ) ;
F_136 ( & V_39 -> V_114 ) ;
F_100 ( V_39 ) ;
return 0 ;
V_232:
F_53 ( & V_110 ) ;
return V_5 ;
}
void F_137 ( struct V_38 * V_39 )
{
struct V_10 * V_11 ;
F_64 ( & V_110 ) ;
F_138 ( & V_39 -> V_233 ) ;
F_101 (icd, &devices, list)
if ( V_11 -> V_188 == V_39 -> V_189 && F_56 ( V_11 ) )
F_124 ( V_11 ) ;
F_53 ( & V_110 ) ;
F_139 ( & V_39 -> V_190 ) ;
}
static int F_140 ( struct V_10 * V_11 )
{
struct V_10 * V_231 ;
int V_235 = - 1 , V_20 ;
for ( V_20 = 0 ; V_20 < 256 && V_235 < 0 ; V_20 ++ ) {
V_235 = V_20 ;
F_101 (ix, &devices, list) {
if ( V_231 -> V_188 == V_11 -> V_188 && V_231 -> V_236 == V_20 ) {
V_235 = - 1 ;
break;
}
}
}
if ( V_235 < 0 )
return - V_98 ;
V_11 -> V_236 = V_235 ;
V_11 -> V_116 = 0 ;
V_11 -> V_237 = NULL ;
F_135 ( & V_11 -> V_233 , & V_238 ) ;
return 0 ;
}
static int F_116 ( struct V_10 * V_11 )
{
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
struct V_108 * V_109 = F_141 () ;
if ( ! V_109 )
return - V_98 ;
F_81 ( V_109 -> V_68 , V_39 -> V_153 , sizeof( V_109 -> V_68 ) ) ;
V_109 -> V_40 = V_11 -> V_45 ;
V_109 -> V_239 = V_67 ;
V_109 -> V_240 = & V_241 ;
V_109 -> V_242 = & V_243 ;
V_109 -> V_244 = F_122 ;
V_109 -> V_245 = V_67 ;
V_109 -> V_129 = & V_11 -> V_129 ;
V_109 -> V_246 = & V_39 -> V_114 ;
V_11 -> V_109 = V_109 ;
return 0 ;
}
static int F_121 ( struct V_10 * V_11 )
{
const struct V_247 * type = V_11 -> V_109 -> V_2 . type ;
int V_5 ;
if ( ! V_11 -> V_40 )
return - V_17 ;
V_5 = F_142 ( V_11 -> V_109 , V_248 , - 1 ) ;
if ( V_5 < 0 ) {
F_3 ( V_11 -> V_45 , L_28 , V_5 ) ;
return V_5 ;
}
V_11 -> V_109 -> V_2 . type = type ;
return 0 ;
}
static int F_143 ( struct V_249 * V_45 )
{
struct V_117 * V_118 = V_45 -> V_2 . V_202 ;
struct V_3 * V_4 = & V_118 -> V_119 ;
struct V_10 * V_11 ;
int V_5 ;
if ( ! V_118 )
return - V_56 ;
V_11 = F_144 ( & V_45 -> V_2 , sizeof( * V_11 ) , V_250 ) ;
if ( ! V_11 )
return - V_98 ;
V_5 = F_145 ( & V_45 -> V_2 , V_4 -> V_6 ,
V_4 -> V_7 ) ;
if ( V_5 < 0 )
return V_5 ;
V_11 -> V_188 = V_118 -> V_195 . V_251 ;
V_11 -> V_118 = V_118 ;
V_11 -> V_45 = & V_45 -> V_2 ;
F_146 ( V_45 , V_11 ) ;
V_11 -> V_103 = V_252 ;
V_11 -> V_104 = V_253 ;
return F_140 ( V_11 ) ;
}
static int F_147 ( struct V_249 * V_45 )
{
struct V_10 * V_11 = F_148 ( V_45 ) ;
if ( ! V_11 )
return - V_56 ;
F_138 ( & V_11 -> V_233 ) ;
return 0 ;
}

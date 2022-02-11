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
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
F_14 ( V_11 -> V_45 , L_15 , V_126 ) ;
if ( V_39 -> V_54 -> V_123 && V_11 -> V_83 . V_129 & V_130 )
return F_67 ( & V_11 -> V_83 , V_126 , V_127 , V_128 ,
V_58 -> V_85 & V_86 ) ;
F_3 ( V_11 -> V_45 , L_16 ) ;
return - V_56 ;
}
static int F_68 ( struct V_58 * V_58 , struct V_131 * V_132 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
int V_9 ;
F_14 ( V_11 -> V_45 , L_17 , ( unsigned long ) V_132 ) ;
if ( V_11 -> V_78 != V_58 )
return - V_79 ;
if ( F_54 ( & V_11 -> V_110 ) )
return - V_111 ;
if ( V_39 -> V_54 -> V_80 )
V_9 = F_69 ( & V_11 -> V_81 , V_132 ) ;
else
V_9 = F_70 ( & V_11 -> V_83 , V_132 ) ;
F_57 ( & V_11 -> V_110 ) ;
F_14 ( V_11 -> V_45 , L_18 ,
( unsigned long ) V_132 -> V_133 ,
( unsigned long ) V_132 -> V_134 - ( unsigned long ) V_132 -> V_133 ,
V_9 ) ;
return V_9 ;
}
static unsigned int F_71 ( struct V_58 * V_58 , T_6 * V_135 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
unsigned V_136 = V_137 ;
if ( V_11 -> V_78 != V_58 )
return V_137 ;
F_56 ( & V_11 -> V_110 ) ;
if ( V_39 -> V_54 -> V_80 && F_72 ( & V_11 -> V_81 . V_138 ) )
F_3 ( V_11 -> V_45 , L_19 ) ;
else
V_136 = V_39 -> V_54 -> V_139 ( V_58 , V_135 ) ;
F_57 ( & V_11 -> V_110 ) ;
return V_136 ;
}
void F_73 ( struct V_140 * V_141 )
{
struct V_10 * V_11 = F_74 ( V_141 ) ;
F_56 ( & V_11 -> V_110 ) ;
}
void F_75 ( struct V_140 * V_141 )
{
struct V_10 * V_11 = F_74 ( V_141 ) ;
F_57 ( & V_11 -> V_110 ) ;
}
static int F_76 ( struct V_58 * V_58 , void * V_59 ,
struct V_37 * V_26 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
int V_5 ;
F_20 ( V_59 != V_58 -> V_60 ) ;
if ( V_26 -> type != V_61 ) {
F_77 ( V_11 -> V_45 , L_20 , V_26 -> type ) ;
return - V_56 ;
}
if ( V_11 -> V_78 && V_11 -> V_78 != V_58 )
return - V_79 ;
if ( F_78 ( F_13 ( V_11 -> V_40 ) , V_11 ) ) {
F_3 ( V_11 -> V_45 , L_21 ) ;
return - V_79 ;
}
V_5 = F_48 ( V_11 , V_26 ) ;
if ( ! V_5 && ! V_11 -> V_78 )
V_11 -> V_78 = V_58 ;
return V_5 ;
}
static int F_79 ( struct V_58 * V_58 , void * V_59 ,
struct V_142 * V_26 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
const struct V_143 * V_144 ;
F_20 ( V_59 != V_58 -> V_60 ) ;
if ( V_26 -> V_64 >= V_11 -> V_21 )
return - V_56 ;
V_144 = V_11 -> V_22 [ V_26 -> V_64 ] . V_23 ;
if ( V_144 -> V_68 )
F_80 ( V_26 -> V_145 , V_144 -> V_68 , sizeof( V_26 -> V_145 ) ) ;
V_26 -> V_46 = V_144 -> V_19 ;
return 0 ;
}
static int F_81 ( struct V_58 * V_58 , void * V_59 ,
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
static int F_82 ( struct V_58 * V_58 , void * V_59 ,
struct V_146 * V_147 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
F_20 ( V_59 != V_58 -> V_60 ) ;
F_80 ( V_147 -> V_148 , V_39 -> V_149 , sizeof( V_147 -> V_148 ) ) ;
return V_39 -> V_54 -> V_150 ( V_39 , V_147 ) ;
}
static int F_83 ( struct V_58 * V_58 , void * V_59 ,
enum V_151 V_20 )
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
V_5 = F_84 ( & V_11 -> V_81 ) ;
else
V_5 = F_85 ( & V_11 -> V_83 , V_20 ) ;
if ( ! V_5 )
F_8 ( V_13 , V_94 , V_152 , 1 ) ;
return V_5 ;
}
static int F_86 ( struct V_58 * V_58 , void * V_59 ,
enum V_151 V_20 )
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
F_87 ( & V_11 -> V_81 ) ;
else
F_88 ( & V_11 -> V_83 , V_20 ) ;
F_8 ( V_13 , V_94 , V_152 , 0 ) ;
return 0 ;
}
static int F_89 ( struct V_58 * V_58 , void * V_72 ,
struct V_153 * V_69 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
return V_39 -> V_54 -> V_154 ( V_11 , V_69 ) ;
}
static int F_90 ( struct V_58 * V_58 , void * V_72 ,
struct V_155 * V_69 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
int V_5 ;
V_5 = V_39 -> V_54 -> V_156 ( V_11 , V_69 ) ;
return V_5 ;
}
static int F_91 ( struct V_58 * V_58 , void * V_72 ,
const struct V_155 * V_69 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
const struct V_157 * V_158 = & V_69 -> V_159 ;
struct V_155 V_160 ;
int V_5 ;
if ( V_69 -> type != V_61 )
return - V_56 ;
F_14 ( V_11 -> V_45 , L_23 ,
V_158 -> V_47 , V_158 -> V_48 , V_158 -> V_161 , V_158 -> V_162 ) ;
V_5 = V_39 -> V_54 -> V_156 ( V_11 , & V_160 ) ;
if ( V_5 < 0 ) {
F_3 ( V_11 -> V_45 ,
L_24 ) ;
} else if ( ( V_69 -> V_159 . V_47 == V_160 . V_159 . V_47 &&
V_69 -> V_159 . V_48 == V_160 . V_159 . V_48 ) ||
! F_78 ( V_39 , V_11 ) ) {
V_5 = V_39 -> V_54 -> V_163 ( V_11 , V_69 ) ;
} else if ( V_39 -> V_54 -> V_164 ) {
V_5 = V_39 -> V_54 -> V_164 ( V_11 , V_69 ) ;
} else {
F_3 ( V_11 -> V_45 ,
L_25 ) ;
V_5 = - V_79 ;
}
return V_5 ;
}
static int F_92 ( struct V_58 * V_58 , void * V_72 ,
struct V_165 * V_166 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
if ( V_166 -> type != V_61 )
return - V_56 ;
if ( ! V_39 -> V_54 -> V_167 )
return - V_168 ;
return V_39 -> V_54 -> V_167 ( V_11 , V_166 ) ;
}
static int F_93 ( struct V_58 * V_58 , void * V_72 ,
struct V_165 * V_166 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
int V_5 ;
if ( V_166 -> type != V_61 ||
( V_166 -> V_169 != V_170 &&
V_166 -> V_169 != V_171 ) )
return - V_56 ;
if ( V_166 -> V_169 == V_170 ) {
if ( F_78 ( V_39 , V_11 ) &&
( V_11 -> V_103 != V_166 -> V_172 . V_47 ||
V_11 -> V_104 != V_166 -> V_172 . V_48 ) )
return - V_79 ;
if ( V_11 -> V_78 && V_11 -> V_78 != V_58 )
return - V_79 ;
}
if ( ! V_39 -> V_54 -> V_173 )
return - V_168 ;
V_5 = V_39 -> V_54 -> V_173 ( V_11 , V_166 ) ;
if ( ! V_5 &&
V_166 -> V_169 == V_170 ) {
V_11 -> V_103 = V_166 -> V_172 . V_47 ;
V_11 -> V_104 = V_166 -> V_172 . V_48 ;
if ( ! V_11 -> V_78 )
V_11 -> V_78 = V_58 ;
}
return V_5 ;
}
static int F_94 ( struct V_58 * V_58 , void * V_72 ,
struct V_174 * V_69 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
if ( V_39 -> V_54 -> V_175 )
return V_39 -> V_54 -> V_175 ( V_11 , V_69 ) ;
return - V_16 ;
}
static int F_95 ( struct V_58 * V_58 , void * V_72 ,
struct V_174 * V_69 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
if ( V_39 -> V_54 -> V_176 )
return V_39 -> V_54 -> V_176 ( V_11 , V_69 ) ;
return - V_16 ;
}
static int F_96 ( struct V_58 * V_58 , void * V_72 ,
struct V_177 * V_178 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_12 * V_13 = F_7 ( V_11 ) ;
return F_8 ( V_13 , V_14 , V_179 , V_178 ) ;
}
static int F_97 ( struct V_58 * V_58 , void * V_72 ,
struct V_180 * V_181 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_12 * V_13 = F_7 ( V_11 ) ;
return F_8 ( V_13 , V_14 , V_182 , V_181 ) ;
}
static int F_98 ( struct V_58 * V_58 , void * V_72 ,
struct V_180 * V_181 )
{
struct V_10 * V_11 = V_58 -> V_60 ;
struct V_12 * V_13 = F_7 ( V_11 ) ;
return F_8 ( V_13 , V_14 , V_183 , V_181 ) ;
}
static void F_99 ( struct V_38 * V_39 )
{
struct V_10 * V_11 ;
F_56 ( & V_39 -> V_116 ) ;
F_100 (icd, &devices, list) {
if ( V_11 -> V_184 == V_39 -> V_185 ) {
V_11 -> V_40 = V_39 -> V_186 . V_2 ;
F_101 ( V_11 ) ;
}
}
F_57 ( & V_39 -> V_116 ) ;
}
static int F_102 ( struct V_10 * V_11 ,
struct V_3 * V_4 )
{
struct V_187 * V_188 ;
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
struct V_189 * V_190 = F_103 ( V_4 -> V_191 ) ;
struct V_12 * V_192 ;
if ( ! V_190 ) {
F_3 ( V_11 -> V_45 , L_26 ,
V_4 -> V_191 ) ;
goto V_193;
}
V_4 -> V_194 -> V_195 = V_4 ;
V_192 = F_104 ( & V_39 -> V_186 , V_190 ,
V_4 -> V_194 , NULL ) ;
if ( ! V_192 )
goto V_196;
V_188 = F_105 ( V_192 ) ;
V_11 -> V_197 = & V_188 -> V_2 ;
return 0 ;
V_196:
F_106 ( V_190 ) ;
V_193:
return - V_17 ;
}
static void F_107 ( struct V_10 * V_11 )
{
struct V_187 * V_188 =
F_108 ( F_53 ( V_11 ) ) ;
struct V_189 * V_190 = V_188 -> V_198 ;
V_11 -> V_197 = NULL ;
F_109 ( F_110 ( V_188 ) ) ;
F_111 ( V_188 ) ;
F_106 ( V_190 ) ;
}
static int F_101 ( struct V_10 * V_11 )
{
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
struct V_3 * V_4 = F_52 ( V_11 ) ;
struct V_1 * V_197 = NULL ;
struct V_12 * V_13 ;
struct V_199 V_200 ;
int V_5 ;
F_112 ( V_11 -> V_45 , L_27 , F_113 ( V_11 -> V_45 ) ) ;
V_5 = F_114 ( & V_11 -> V_125 , 16 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_115 ( V_11 -> V_45 , V_4 -> V_6 ,
V_4 -> V_7 ) ;
if ( V_5 < 0 )
goto V_201;
if ( V_4 -> V_115 )
V_4 -> V_115 ( V_11 -> V_45 ) ;
V_5 = V_39 -> V_54 -> V_117 ( V_11 ) ;
if ( V_5 < 0 )
goto V_202;
V_5 = F_116 ( V_11 ) ;
if ( V_5 < 0 )
goto V_203;
if ( V_4 -> V_194 ) {
V_5 = F_102 ( V_11 , V_4 ) ;
if ( V_5 < 0 )
goto V_204;
} else if ( ! V_4 -> V_205 || ! V_4 -> V_206 ) {
V_5 = - V_56 ;
goto V_204;
} else {
if ( V_4 -> V_207 )
V_5 = F_117 ( V_4 -> V_207 ) ;
V_5 = V_4 -> V_205 ( V_11 ) ;
if ( V_5 < 0 )
goto V_204;
V_197 = F_53 ( V_11 ) ;
if ( ! V_197 || ! V_197 -> V_148 || ! F_51 ( V_197 ) ||
! F_55 ( V_197 -> V_148 -> V_112 ) ) {
V_4 -> V_206 ( V_11 ) ;
V_5 = - V_17 ;
goto V_208;
}
}
V_13 = F_7 ( V_11 ) ;
V_13 -> V_209 = F_118 ( V_11 ) ;
F_119 ( V_13 , V_11 ) ;
V_5 = F_120 ( & V_11 -> V_125 , V_13 -> V_125 , NULL ) ;
if ( V_5 < 0 )
goto V_210;
V_5 = F_43 ( V_11 ) ;
if ( V_5 < 0 )
goto V_211;
V_11 -> V_106 = V_212 ;
F_56 ( & V_11 -> V_110 ) ;
V_5 = F_121 ( V_11 ) ;
if ( V_5 < 0 )
goto V_213;
if ( ! F_8 ( V_13 , V_94 , V_214 , & V_200 ) ) {
V_11 -> V_103 = V_200 . V_47 ;
V_11 -> V_104 = V_200 . V_48 ;
V_11 -> V_105 = V_200 . V_105 ;
V_11 -> V_106 = V_200 . V_106 ;
}
V_39 -> V_54 -> remove ( V_11 ) ;
F_57 ( & V_11 -> V_110 ) ;
return 0 ;
V_213:
F_57 ( & V_11 -> V_110 ) ;
F_47 ( V_11 ) ;
V_211:
V_210:
if ( V_4 -> V_194 ) {
F_107 ( V_11 ) ;
} else {
V_4 -> V_206 ( V_11 ) ;
F_62 ( V_197 -> V_148 -> V_112 ) ;
}
V_208:
V_204:
F_122 ( V_11 -> V_109 ) ;
V_11 -> V_109 = NULL ;
V_203:
V_39 -> V_54 -> remove ( V_11 ) ;
V_202:
F_123 ( V_4 -> V_6 , V_4 -> V_7 ) ;
V_201:
F_124 ( & V_11 -> V_125 ) ;
return V_5 ;
}
static int F_125 ( struct V_10 * V_11 )
{
struct V_3 * V_4 = F_52 ( V_11 ) ;
struct V_108 * V_109 = V_11 -> V_109 ;
F_126 ( ! V_11 -> V_40 ) ;
F_124 ( & V_11 -> V_125 ) ;
if ( V_109 ) {
F_127 ( V_109 ) ;
V_11 -> V_109 = NULL ;
}
if ( V_4 -> V_194 ) {
F_107 ( V_11 ) ;
} else {
struct V_215 * V_216 = F_53 ( V_11 ) -> V_148 ;
if ( V_216 ) {
V_4 -> V_206 ( V_11 ) ;
F_62 ( V_216 -> V_112 ) ;
}
}
F_47 ( V_11 ) ;
F_123 ( V_4 -> V_6 , V_4 -> V_7 ) ;
return 0 ;
}
static int F_128 ( struct V_10 * V_11 ,
struct V_153 * V_69 )
{
struct V_12 * V_13 = F_7 ( V_11 ) ;
return F_8 ( V_13 , V_94 , V_154 , V_69 ) ;
}
static int F_129 ( struct V_10 * V_11 , struct V_155 * V_69 )
{
struct V_12 * V_13 = F_7 ( V_11 ) ;
return F_8 ( V_13 , V_94 , V_217 , V_69 ) ;
}
static int F_130 ( struct V_10 * V_11 , const struct V_155 * V_69 )
{
struct V_12 * V_13 = F_7 ( V_11 ) ;
return F_8 ( V_13 , V_94 , V_218 , V_69 ) ;
}
static int F_131 ( struct V_10 * V_11 ,
struct V_174 * V_219 )
{
struct V_12 * V_13 = F_7 ( V_11 ) ;
return F_8 ( V_13 , V_94 , V_220 , V_219 ) ;
}
static int F_132 ( struct V_10 * V_11 ,
struct V_174 * V_219 )
{
struct V_12 * V_13 = F_7 ( V_11 ) ;
return F_8 ( V_13 , V_94 , V_221 , V_219 ) ;
}
static int F_133 ( struct V_10 * V_11 ,
struct V_73 * V_74 )
{
int V_5 ;
struct V_12 * V_13 = F_7 ( V_11 ) ;
const struct V_18 * V_41 ;
T_7 V_222 = V_74 -> V_223 ;
struct V_73 V_224 = * V_74 ;
V_41 = F_10 ( V_11 , V_222 ) ;
if ( ! V_41 )
return - V_56 ;
V_224 . V_223 = V_41 -> V_93 ;
V_5 = F_8 ( V_13 , V_94 , V_75 , & V_224 ) ;
if ( V_5 < 0 )
return V_5 ;
* V_74 = V_224 ;
V_74 -> V_223 = V_222 ;
return 0 ;
}
int F_134 ( struct V_38 * V_39 )
{
struct V_38 * V_225 ;
int V_5 ;
if ( ! V_39 || ! V_39 -> V_54 ||
! V_39 -> V_54 -> V_55 ||
! V_39 -> V_54 -> V_102 ||
! V_39 -> V_54 -> V_107 ||
! V_39 -> V_54 -> V_150 ||
( ( ! V_39 -> V_54 -> V_80 ||
! V_39 -> V_54 -> V_82 ) &&
! V_39 -> V_54 -> V_123 ) ||
! V_39 -> V_54 -> V_117 ||
! V_39 -> V_54 -> remove ||
! V_39 -> V_54 -> V_139 ||
! V_39 -> V_186 . V_2 )
return - V_56 ;
if ( ! V_39 -> V_54 -> V_163 )
V_39 -> V_54 -> V_163 = F_130 ;
if ( ! V_39 -> V_54 -> V_156 )
V_39 -> V_54 -> V_156 = F_129 ;
if ( ! V_39 -> V_54 -> V_154 )
V_39 -> V_54 -> V_154 = F_128 ;
if ( ! V_39 -> V_54 -> V_176 )
V_39 -> V_54 -> V_176 = F_132 ;
if ( ! V_39 -> V_54 -> V_175 )
V_39 -> V_54 -> V_175 = F_131 ;
if ( ! V_39 -> V_54 -> V_75 )
V_39 -> V_54 -> V_75 = F_133 ;
F_56 ( & V_226 ) ;
F_100 (ix, &hosts, list) {
if ( V_225 -> V_185 == V_39 -> V_185 ) {
V_5 = - V_79 ;
goto V_227;
}
}
V_5 = F_135 ( V_39 -> V_186 . V_2 , & V_39 -> V_186 ) ;
if ( V_5 < 0 )
goto V_227;
F_136 ( & V_39 -> V_228 , & V_229 ) ;
F_57 ( & V_226 ) ;
F_137 ( & V_39 -> V_116 ) ;
F_99 ( V_39 ) ;
return 0 ;
V_227:
F_57 ( & V_226 ) ;
return V_5 ;
}
void F_138 ( struct V_38 * V_39 )
{
struct V_10 * V_11 ;
F_56 ( & V_226 ) ;
F_139 ( & V_39 -> V_228 ) ;
F_100 (icd, &devices, list)
if ( V_11 -> V_184 == V_39 -> V_185 && F_53 ( V_11 ) )
F_125 ( V_11 ) ;
F_57 ( & V_226 ) ;
F_140 ( & V_39 -> V_186 ) ;
}
static int F_141 ( struct V_10 * V_11 )
{
struct V_10 * V_225 ;
int V_230 = - 1 , V_20 ;
for ( V_20 = 0 ; V_20 < 256 && V_230 < 0 ; V_20 ++ ) {
V_230 = V_20 ;
F_100 (ix, &devices, list) {
if ( V_225 -> V_184 == V_11 -> V_184 && V_225 -> V_231 == V_20 ) {
V_230 = - 1 ;
break;
}
}
}
if ( V_230 < 0 )
return - V_98 ;
V_11 -> V_231 = V_230 ;
V_11 -> V_114 = 0 ;
V_11 -> V_232 = NULL ;
F_137 ( & V_11 -> V_110 ) ;
F_136 ( & V_11 -> V_228 , & V_233 ) ;
return 0 ;
}
static int F_116 ( struct V_10 * V_11 )
{
struct V_38 * V_39 = F_13 ( V_11 -> V_40 ) ;
struct V_108 * V_109 = F_142 () ;
if ( ! V_109 )
return - V_98 ;
F_80 ( V_109 -> V_68 , V_39 -> V_149 , sizeof( V_109 -> V_68 ) ) ;
V_109 -> V_40 = V_11 -> V_45 ;
V_109 -> V_234 = V_67 ;
V_109 -> V_235 = & V_236 ;
V_109 -> V_237 = & V_238 ;
V_109 -> V_239 = F_122 ;
V_109 -> V_240 = V_67 ;
V_109 -> V_125 = & V_11 -> V_125 ;
V_109 -> V_241 = & V_11 -> V_110 ;
V_11 -> V_109 = V_109 ;
return 0 ;
}
static int F_121 ( struct V_10 * V_11 )
{
const struct V_242 * type = V_11 -> V_109 -> V_2 . type ;
int V_5 ;
if ( ! V_11 -> V_40 )
return - V_17 ;
V_5 = F_143 ( V_11 -> V_109 , V_243 , - 1 ) ;
if ( V_5 < 0 ) {
F_3 ( V_11 -> V_45 , L_28 , V_5 ) ;
return V_5 ;
}
V_11 -> V_109 -> V_2 . type = type ;
return 0 ;
}
static int F_144 ( struct V_244 * V_45 )
{
struct V_3 * V_4 = V_45 -> V_2 . V_195 ;
struct V_10 * V_11 ;
if ( ! V_4 )
return - V_56 ;
V_11 = F_145 ( & V_45 -> V_2 , sizeof( * V_11 ) , V_245 ) ;
if ( ! V_11 )
return - V_98 ;
V_11 -> V_184 = V_4 -> V_246 ;
V_11 -> V_247 = V_4 ;
V_11 -> V_45 = & V_45 -> V_2 ;
F_146 ( V_45 , V_11 ) ;
V_11 -> V_103 = V_248 ;
V_11 -> V_104 = V_249 ;
return F_141 ( V_11 ) ;
}
static int F_147 ( struct V_244 * V_45 )
{
struct V_10 * V_11 = F_148 ( V_45 ) ;
if ( ! V_11 )
return - V_56 ;
F_139 ( & V_11 -> V_228 ) ;
return 0 ;
}

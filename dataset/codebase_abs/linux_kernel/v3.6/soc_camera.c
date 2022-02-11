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
V_7 = V_4 -> V_11 ( V_2 -> V_12 , 1 ) ;
if ( V_7 < 0 ) {
F_4 ( V_2 -> V_10 ,
L_2 ) ;
goto V_13;
}
}
V_7 = F_5 ( V_6 , V_14 , V_15 , 1 ) ;
if ( V_7 < 0 && V_7 != - V_16 && V_7 != - V_17 )
goto V_18;
return 0 ;
V_18:
if ( V_4 -> V_11 )
V_4 -> V_11 ( V_2 -> V_12 , 0 ) ;
V_13:
F_6 ( V_4 -> V_8 ,
V_4 -> V_9 ) ;
return V_7 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 = F_5 ( V_6 , V_14 , V_15 , 0 ) ;
if ( V_7 < 0 && V_7 != - V_16 && V_7 != - V_17 )
return V_7 ;
if ( V_4 -> V_11 ) {
V_7 = V_4 -> V_11 ( V_2 -> V_12 , 0 ) ;
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
const struct V_19 * F_8 (
struct V_1 * V_2 , unsigned int V_20 )
{
unsigned int V_21 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_22 ; V_21 ++ )
if ( V_2 -> V_23 [ V_21 ] . V_24 -> V_20 == V_20 )
return V_2 -> V_23 + V_21 ;
return NULL ;
}
unsigned long F_9 ( struct V_3 * V_4 ,
const struct V_25 * V_26 )
{
unsigned long V_27 , V_28 = V_26 -> V_28 ;
if ( V_4 -> V_28 & V_29 ) {
V_27 = V_28 & ( V_30 | V_31 ) ;
if ( V_27 == V_30 || V_27 == V_31 )
V_28 ^= V_30 | V_31 ;
}
if ( V_4 -> V_28 & V_32 ) {
V_27 = V_28 & ( V_33 | V_34 ) ;
if ( V_27 == V_33 || V_27 == V_34 )
V_28 ^= V_33 | V_34 ;
}
if ( V_4 -> V_28 & V_35 ) {
V_27 = V_28 & ( V_36 | V_37 ) ;
if ( V_27 == V_36 || V_27 == V_37 )
V_28 ^= V_36 | V_37 ;
}
return V_28 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_38 * V_27 )
{
struct V_39 * V_40 = F_11 ( V_2 -> V_41 ) ;
const struct V_19 * V_42 ;
struct V_43 * V_44 = & V_27 -> V_45 . V_44 ;
int V_7 ;
F_12 ( V_2 -> V_10 , L_5 ,
F_13 ( V_44 -> V_46 ) , V_44 -> V_47 , V_44 -> V_48 ) ;
if ( V_44 -> V_46 != V_49 &&
! ( V_40 -> V_50 & V_51 ) ) {
V_44 -> V_52 = 0 ;
V_44 -> V_53 = 0 ;
}
V_7 = V_40 -> V_54 -> V_55 ( V_2 , V_27 ) ;
if ( V_7 < 0 )
return V_7 ;
V_42 = F_8 ( V_2 , V_44 -> V_46 ) ;
if ( ! V_42 )
return - V_56 ;
V_7 = F_14 ( V_44 -> V_47 , V_42 -> V_24 ) ;
if ( V_7 < 0 )
return V_7 ;
V_44 -> V_52 = F_15 ( V_57 , V_44 -> V_52 , V_7 ) ;
V_7 = F_16 ( V_42 -> V_24 , V_44 -> V_52 ,
V_44 -> V_48 ) ;
if ( V_7 < 0 )
return V_7 ;
V_44 -> V_53 = F_15 ( V_57 , V_44 -> V_53 , V_7 ) ;
return 0 ;
}
static int F_17 ( struct V_58 * V_58 , void * V_59 ,
struct V_38 * V_27 )
{
struct V_1 * V_2 = V_58 -> V_60 ;
F_18 ( V_59 != V_58 -> V_60 ) ;
if ( V_27 -> type != V_61 )
return - V_56 ;
return F_10 ( V_2 , V_27 ) ;
}
static int F_19 ( struct V_58 * V_58 , void * V_59 ,
struct V_62 * V_63 )
{
if ( V_63 -> V_64 != 0 )
return - V_56 ;
V_63 -> type = V_65 ;
V_63 -> V_66 = V_67 ;
strcpy ( V_63 -> V_68 , L_6 ) ;
return 0 ;
}
static int F_20 ( struct V_58 * V_58 , void * V_59 , unsigned int * V_21 )
{
* V_21 = 0 ;
return 0 ;
}
static int F_21 ( struct V_58 * V_58 , void * V_59 , unsigned int V_21 )
{
if ( V_21 > 0 )
return - V_56 ;
return 0 ;
}
static int F_22 ( struct V_58 * V_58 , void * V_59 , T_1 * V_69 )
{
struct V_1 * V_2 = V_58 -> V_60 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_5 ( V_6 , V_14 , V_70 , * V_69 ) ;
}
static int F_23 ( struct V_58 * V_58 , void * V_59 , T_1 * V_69 )
{
struct V_1 * V_2 = V_58 -> V_60 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_5 ( V_6 , V_14 , V_71 , V_69 ) ;
}
static int F_24 ( struct V_58 * V_58 , void * V_72 ,
struct V_73 * V_74 )
{
struct V_1 * V_2 = V_58 -> V_60 ;
struct V_39 * V_40 = F_11 ( V_2 -> V_41 ) ;
return V_40 -> V_54 -> V_75 ( V_2 , V_74 ) ;
}
static int F_25 ( struct V_58 * V_58 , void * V_59 ,
struct V_76 * V_77 )
{
int V_7 ;
struct V_1 * V_2 = V_58 -> V_60 ;
struct V_39 * V_40 = F_11 ( V_2 -> V_41 ) ;
F_18 ( V_59 != V_58 -> V_60 ) ;
if ( V_2 -> V_78 && V_2 -> V_78 != V_58 )
return - V_79 ;
if ( V_40 -> V_54 -> V_80 ) {
V_7 = F_26 ( & V_2 -> V_81 , V_77 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = V_40 -> V_54 -> V_82 ( V_2 , V_77 ) ;
} else {
V_7 = F_27 ( & V_2 -> V_83 , V_77 ) ;
}
if ( ! V_7 && ! V_2 -> V_78 )
V_2 -> V_78 = V_58 ;
return V_7 ;
}
static int F_28 ( struct V_58 * V_58 , void * V_59 ,
struct V_84 * V_77 )
{
struct V_1 * V_2 = V_58 -> V_60 ;
struct V_39 * V_40 = F_11 ( V_2 -> V_41 ) ;
F_18 ( V_59 != V_58 -> V_60 ) ;
if ( V_40 -> V_54 -> V_80 )
return F_29 ( & V_2 -> V_81 , V_77 ) ;
else
return F_30 ( & V_2 -> V_83 , V_77 ) ;
}
static int F_31 ( struct V_58 * V_58 , void * V_59 ,
struct V_84 * V_77 )
{
struct V_1 * V_2 = V_58 -> V_60 ;
struct V_39 * V_40 = F_11 ( V_2 -> V_41 ) ;
F_18 ( V_59 != V_58 -> V_60 ) ;
if ( V_2 -> V_78 != V_58 )
return - V_79 ;
if ( V_40 -> V_54 -> V_80 )
return F_32 ( & V_2 -> V_81 , V_77 ) ;
else
return F_33 ( & V_2 -> V_83 , V_77 ) ;
}
static int F_34 ( struct V_58 * V_58 , void * V_59 ,
struct V_84 * V_77 )
{
struct V_1 * V_2 = V_58 -> V_60 ;
struct V_39 * V_40 = F_11 ( V_2 -> V_41 ) ;
F_18 ( V_59 != V_58 -> V_60 ) ;
if ( V_2 -> V_78 != V_58 )
return - V_79 ;
if ( V_40 -> V_54 -> V_80 )
return F_35 ( & V_2 -> V_81 , V_77 , V_58 -> V_85 & V_86 ) ;
else
return F_36 ( & V_2 -> V_83 , V_77 , V_58 -> V_85 & V_86 ) ;
}
static int F_37 ( struct V_58 * V_58 , void * V_59 ,
struct V_87 * V_88 )
{
struct V_1 * V_2 = V_58 -> V_60 ;
struct V_39 * V_40 = F_11 ( V_2 -> V_41 ) ;
if ( V_40 -> V_54 -> V_80 )
return - V_56 ;
else
return F_38 ( & V_2 -> V_83 , V_88 ) ;
}
static int F_39 ( struct V_58 * V_58 , void * V_59 ,
struct V_84 * V_89 )
{
struct V_1 * V_2 = V_58 -> V_60 ;
struct V_39 * V_40 = F_11 ( V_2 -> V_41 ) ;
if ( V_40 -> V_54 -> V_80 )
return - V_56 ;
else
return F_40 ( & V_2 -> V_83 , V_89 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_39 * V_40 = F_11 ( V_2 -> V_41 ) ;
unsigned int V_21 , V_90 = 0 , V_91 = 0 ;
int V_7 ;
enum V_92 V_93 ;
while ( ! F_5 ( V_6 , V_94 , V_95 , V_91 , & V_93 ) )
V_91 ++ ;
if ( ! V_40 -> V_54 -> V_96 )
V_90 = V_91 ;
else
for ( V_21 = 0 ; V_21 < V_91 ; V_21 ++ ) {
V_7 = V_40 -> V_54 -> V_96 ( V_2 , V_21 , NULL ) ;
if ( V_7 < 0 )
return V_7 ;
V_90 += V_7 ;
}
if ( ! V_90 )
return - V_97 ;
V_2 -> V_23 =
F_42 ( V_90 * sizeof( struct V_19 ) ) ;
if ( ! V_2 -> V_23 )
return - V_98 ;
F_12 ( V_2 -> V_10 , L_7 , V_90 ) ;
V_90 = 0 ;
for ( V_21 = 0 ; V_21 < V_91 ; V_21 ++ )
if ( ! V_40 -> V_54 -> V_96 ) {
F_5 ( V_6 , V_94 , V_95 , V_21 , & V_93 ) ;
V_2 -> V_23 [ V_90 ] . V_24 =
F_43 ( V_93 ) ;
if ( V_2 -> V_23 [ V_90 ] . V_24 )
V_2 -> V_23 [ V_90 ++ ] . V_93 = V_93 ;
} else {
V_7 = V_40 -> V_54 -> V_96 ( V_2 , V_21 ,
& V_2 -> V_23 [ V_90 ] ) ;
if ( V_7 < 0 )
goto V_99;
V_90 += V_7 ;
}
V_2 -> V_22 = V_90 ;
V_2 -> V_100 = & V_2 -> V_23 [ 0 ] ;
return 0 ;
V_99:
F_44 ( V_2 -> V_23 ) ;
return V_7 ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_11 ( V_2 -> V_41 ) ;
if ( V_40 -> V_54 -> V_101 )
V_40 -> V_54 -> V_101 ( V_2 ) ;
V_2 -> V_100 = NULL ;
V_2 -> V_22 = 0 ;
F_44 ( V_2 -> V_23 ) ;
V_2 -> V_23 = NULL ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_38 * V_27 )
{
struct V_39 * V_40 = F_11 ( V_2 -> V_41 ) ;
struct V_43 * V_44 = & V_27 -> V_45 . V_44 ;
int V_7 ;
F_12 ( V_2 -> V_10 , L_8 ,
F_13 ( V_44 -> V_46 ) , V_44 -> V_47 , V_44 -> V_48 ) ;
V_7 = F_10 ( V_2 , V_27 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = V_40 -> V_54 -> V_102 ( V_2 , V_27 ) ;
if ( V_7 < 0 ) {
return V_7 ;
} else if ( ! V_2 -> V_100 ||
V_2 -> V_100 -> V_24 -> V_20 != V_44 -> V_46 ) {
F_4 ( V_2 -> V_10 ,
L_9 ) ;
return - V_56 ;
}
V_2 -> V_103 = V_44 -> V_47 ;
V_2 -> V_104 = V_44 -> V_48 ;
V_2 -> V_52 = V_44 -> V_52 ;
V_2 -> V_53 = V_44 -> V_53 ;
V_2 -> V_105 = V_44 -> V_105 ;
V_2 -> V_106 = V_44 -> V_106 ;
if ( V_40 -> V_54 -> V_80 )
V_2 -> V_81 . V_106 = V_44 -> V_106 ;
F_12 ( V_2 -> V_10 , L_10 ,
V_2 -> V_103 , V_2 -> V_104 ) ;
return V_40 -> V_54 -> V_107 ( V_2 ) ;
}
static int F_47 ( struct V_58 * V_58 )
{
struct V_108 * V_109 = F_48 ( V_58 ) ;
struct V_1 * V_2 = F_49 ( V_109 -> V_41 ) ;
struct V_3 * V_4 = F_50 ( V_2 ) ;
struct V_39 * V_40 ;
int V_7 ;
if ( ! F_51 ( V_2 ) )
return - V_17 ;
V_40 = F_11 ( V_2 -> V_41 ) ;
if ( ! F_52 ( V_40 -> V_54 -> V_110 ) ) {
F_4 ( V_2 -> V_10 , L_11 ) ;
return - V_56 ;
}
V_2 -> V_111 ++ ;
if ( V_2 -> V_111 == 1 ) {
struct V_38 V_27 = {
. type = V_61 ,
. V_45 . V_44 = {
. V_47 = V_2 -> V_103 ,
. V_48 = V_2 -> V_104 ,
. V_106 = V_2 -> V_106 ,
. V_105 = V_2 -> V_105 ,
. V_46 =
V_2 -> V_100 -> V_24 -> V_20 ,
} ,
} ;
if ( V_4 -> V_112 )
V_4 -> V_112 ( V_2 -> V_10 ) ;
F_53 ( & V_40 -> V_113 ) ;
V_7 = V_40 -> V_54 -> V_114 ( V_2 ) ;
F_54 ( & V_40 -> V_113 ) ;
if ( V_7 < 0 ) {
F_4 ( V_2 -> V_10 , L_12 , V_7 ) ;
goto V_115;
}
V_7 = F_1 ( V_2 , V_4 ) ;
if ( V_7 < 0 )
goto V_116;
F_55 ( & V_2 -> V_109 -> V_117 ) ;
V_7 = F_56 ( & V_2 -> V_109 -> V_117 ) ;
if ( V_7 < 0 && V_7 != - V_118 )
goto V_119;
V_7 = F_46 ( V_2 , & V_27 ) ;
if ( V_7 < 0 )
goto V_120;
if ( V_40 -> V_54 -> V_80 ) {
V_40 -> V_54 -> V_80 ( & V_2 -> V_81 , V_2 ) ;
} else {
V_7 = V_40 -> V_54 -> V_121 ( & V_2 -> V_83 , V_2 ) ;
if ( V_7 < 0 )
goto V_122;
}
F_57 ( & V_2 -> V_123 ) ;
}
V_58 -> V_60 = V_2 ;
F_12 ( V_2 -> V_10 , L_13 ) ;
return 0 ;
V_122:
V_120:
F_58 ( & V_2 -> V_109 -> V_117 ) ;
V_119:
F_7 ( V_2 , V_4 ) ;
V_116:
V_40 -> V_54 -> remove ( V_2 ) ;
V_115:
V_2 -> V_111 -- ;
F_59 ( V_40 -> V_54 -> V_110 ) ;
return V_7 ;
}
static int F_60 ( struct V_58 * V_58 )
{
struct V_1 * V_2 = V_58 -> V_60 ;
struct V_39 * V_40 = F_11 ( V_2 -> V_41 ) ;
V_2 -> V_111 -- ;
if ( ! V_2 -> V_111 ) {
struct V_3 * V_4 = F_50 ( V_2 ) ;
F_61 ( & V_2 -> V_109 -> V_117 ) ;
F_58 ( & V_2 -> V_109 -> V_117 ) ;
if ( V_40 -> V_54 -> V_121 )
F_62 ( & V_2 -> V_83 ) ;
V_40 -> V_54 -> remove ( V_2 ) ;
F_7 ( V_2 , V_4 ) ;
}
if ( V_2 -> V_78 == V_58 )
V_2 -> V_78 = NULL ;
F_59 ( V_40 -> V_54 -> V_110 ) ;
F_12 ( V_2 -> V_10 , L_14 ) ;
return 0 ;
}
static T_2 F_63 ( struct V_58 * V_58 , char T_3 * V_124 ,
T_4 V_125 , T_5 * V_126 )
{
struct V_1 * V_2 = V_58 -> V_60 ;
int V_127 = - V_56 ;
F_4 ( V_2 -> V_10 , L_15 ) ;
return V_127 ;
}
static int F_64 ( struct V_58 * V_58 , struct V_128 * V_129 )
{
struct V_1 * V_2 = V_58 -> V_60 ;
struct V_39 * V_40 = F_11 ( V_2 -> V_41 ) ;
int V_127 ;
F_12 ( V_2 -> V_10 , L_16 , ( unsigned long ) V_129 ) ;
if ( V_2 -> V_78 != V_58 )
return - V_79 ;
if ( V_40 -> V_54 -> V_80 )
V_127 = F_65 ( & V_2 -> V_81 , V_129 ) ;
else
V_127 = F_66 ( & V_2 -> V_83 , V_129 ) ;
F_12 ( V_2 -> V_10 , L_17 ,
( unsigned long ) V_129 -> V_130 ,
( unsigned long ) V_129 -> V_131 - ( unsigned long ) V_129 -> V_130 ,
V_127 ) ;
return V_127 ;
}
static unsigned int F_67 ( struct V_58 * V_58 , T_6 * V_132 )
{
struct V_1 * V_2 = V_58 -> V_60 ;
struct V_39 * V_40 = F_11 ( V_2 -> V_41 ) ;
if ( V_2 -> V_78 != V_58 )
return - V_79 ;
if ( V_40 -> V_54 -> V_80 && F_68 ( & V_2 -> V_81 . V_133 ) ) {
F_4 ( V_2 -> V_10 , L_18 ) ;
return V_134 ;
}
return V_40 -> V_54 -> V_135 ( V_58 , V_132 ) ;
}
void F_69 ( struct V_136 * V_137 )
{
struct V_1 * V_2 = F_70 ( V_137 ) ;
F_53 ( & V_2 -> V_138 ) ;
}
void F_71 ( struct V_136 * V_137 )
{
struct V_1 * V_2 = F_70 ( V_137 ) ;
F_54 ( & V_2 -> V_138 ) ;
}
static int F_72 ( struct V_58 * V_58 , void * V_59 ,
struct V_38 * V_27 )
{
struct V_1 * V_2 = V_58 -> V_60 ;
int V_7 ;
F_18 ( V_59 != V_58 -> V_60 ) ;
if ( V_27 -> type != V_61 ) {
F_73 ( V_2 -> V_10 , L_19 , V_27 -> type ) ;
return - V_56 ;
}
if ( V_2 -> V_78 && V_2 -> V_78 != V_58 )
return - V_79 ;
if ( F_74 ( F_11 ( V_2 -> V_41 ) , V_2 ) ) {
F_4 ( V_2 -> V_10 , L_20 ) ;
return - V_79 ;
}
V_7 = F_46 ( V_2 , V_27 ) ;
if ( ! V_7 && ! V_2 -> V_78 )
V_2 -> V_78 = V_58 ;
return V_7 ;
}
static int F_75 ( struct V_58 * V_58 , void * V_59 ,
struct V_139 * V_27 )
{
struct V_1 * V_2 = V_58 -> V_60 ;
const struct V_140 * V_141 ;
F_18 ( V_59 != V_58 -> V_60 ) ;
if ( V_27 -> V_64 >= V_2 -> V_22 )
return - V_56 ;
V_141 = V_2 -> V_23 [ V_27 -> V_64 ] . V_24 ;
if ( V_141 -> V_68 )
F_76 ( V_27 -> V_142 , V_141 -> V_68 , sizeof( V_27 -> V_142 ) ) ;
V_27 -> V_46 = V_141 -> V_20 ;
return 0 ;
}
static int F_77 ( struct V_58 * V_58 , void * V_59 ,
struct V_38 * V_27 )
{
struct V_1 * V_2 = V_58 -> V_60 ;
struct V_43 * V_44 = & V_27 -> V_45 . V_44 ;
F_18 ( V_59 != V_58 -> V_60 ) ;
if ( V_27 -> type != V_61 )
return - V_56 ;
V_44 -> V_47 = V_2 -> V_103 ;
V_44 -> V_48 = V_2 -> V_104 ;
V_44 -> V_52 = V_2 -> V_52 ;
V_44 -> V_53 = V_2 -> V_53 ;
V_44 -> V_106 = V_2 -> V_106 ;
V_44 -> V_46 = V_2 -> V_100 -> V_24 -> V_20 ;
V_44 -> V_105 = V_2 -> V_105 ;
F_12 ( V_2 -> V_10 , L_21 ,
V_2 -> V_100 -> V_24 -> V_20 ) ;
return 0 ;
}
static int F_78 ( struct V_58 * V_58 , void * V_59 ,
struct V_143 * V_144 )
{
struct V_1 * V_2 = V_58 -> V_60 ;
struct V_39 * V_40 = F_11 ( V_2 -> V_41 ) ;
F_18 ( V_59 != V_58 -> V_60 ) ;
F_76 ( V_144 -> V_145 , V_40 -> V_146 , sizeof( V_144 -> V_145 ) ) ;
return V_40 -> V_54 -> V_147 ( V_40 , V_144 ) ;
}
static int F_79 ( struct V_58 * V_58 , void * V_59 ,
enum V_148 V_21 )
{
struct V_1 * V_2 = V_58 -> V_60 ;
struct V_39 * V_40 = F_11 ( V_2 -> V_41 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
F_18 ( V_59 != V_58 -> V_60 ) ;
if ( V_21 != V_61 )
return - V_56 ;
if ( V_2 -> V_78 != V_58 )
return - V_79 ;
if ( V_40 -> V_54 -> V_80 )
V_7 = F_80 ( & V_2 -> V_81 ) ;
else
V_7 = F_81 ( & V_2 -> V_83 , V_21 ) ;
if ( ! V_7 )
F_5 ( V_6 , V_94 , V_149 , 1 ) ;
return V_7 ;
}
static int F_82 ( struct V_58 * V_58 , void * V_59 ,
enum V_148 V_21 )
{
struct V_1 * V_2 = V_58 -> V_60 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_39 * V_40 = F_11 ( V_2 -> V_41 ) ;
F_18 ( V_59 != V_58 -> V_60 ) ;
if ( V_21 != V_61 )
return - V_56 ;
if ( V_2 -> V_78 != V_58 )
return - V_79 ;
if ( V_40 -> V_54 -> V_80 )
F_83 ( & V_2 -> V_81 ) ;
else
F_84 ( & V_2 -> V_83 , V_21 ) ;
F_5 ( V_6 , V_94 , V_149 , 0 ) ;
return 0 ;
}
static int F_85 ( struct V_58 * V_58 , void * V_72 ,
struct V_150 * V_69 )
{
struct V_1 * V_2 = V_58 -> V_60 ;
struct V_39 * V_40 = F_11 ( V_2 -> V_41 ) ;
return V_40 -> V_54 -> V_151 ( V_2 , V_69 ) ;
}
static int F_86 ( struct V_58 * V_58 , void * V_72 ,
struct V_152 * V_69 )
{
struct V_1 * V_2 = V_58 -> V_60 ;
struct V_39 * V_40 = F_11 ( V_2 -> V_41 ) ;
int V_7 ;
V_7 = V_40 -> V_54 -> V_153 ( V_2 , V_69 ) ;
return V_7 ;
}
static int F_87 ( struct V_58 * V_58 , void * V_72 ,
struct V_152 * V_69 )
{
struct V_1 * V_2 = V_58 -> V_60 ;
struct V_39 * V_40 = F_11 ( V_2 -> V_41 ) ;
struct V_154 * V_155 = & V_69 -> V_156 ;
struct V_152 V_157 ;
int V_7 ;
if ( V_69 -> type != V_61 )
return - V_56 ;
F_12 ( V_2 -> V_10 , L_22 ,
V_155 -> V_47 , V_155 -> V_48 , V_155 -> V_158 , V_155 -> V_159 ) ;
V_7 = V_40 -> V_54 -> V_153 ( V_2 , & V_157 ) ;
if ( V_7 < 0 ) {
F_4 ( V_2 -> V_10 ,
L_23 ) ;
} else if ( ( V_69 -> V_156 . V_47 == V_157 . V_156 . V_47 &&
V_69 -> V_156 . V_48 == V_157 . V_156 . V_48 ) ||
! F_74 ( V_40 , V_2 ) ) {
V_7 = V_40 -> V_54 -> V_160 ( V_2 , V_69 ) ;
} else if ( V_40 -> V_54 -> V_161 ) {
V_7 = V_40 -> V_54 -> V_161 ( V_2 , V_69 ) ;
} else {
F_4 ( V_2 -> V_10 ,
L_24 ) ;
V_7 = - V_79 ;
}
return V_7 ;
}
static int F_88 ( struct V_58 * V_58 , void * V_72 ,
struct V_162 * V_69 )
{
struct V_1 * V_2 = V_58 -> V_60 ;
struct V_39 * V_40 = F_11 ( V_2 -> V_41 ) ;
if ( V_40 -> V_54 -> V_163 )
return V_40 -> V_54 -> V_163 ( V_2 , V_69 ) ;
return - V_16 ;
}
static int F_89 ( struct V_58 * V_58 , void * V_72 ,
struct V_162 * V_69 )
{
struct V_1 * V_2 = V_58 -> V_60 ;
struct V_39 * V_40 = F_11 ( V_2 -> V_41 ) ;
if ( V_40 -> V_54 -> V_164 )
return V_40 -> V_54 -> V_164 ( V_2 , V_69 ) ;
return - V_16 ;
}
static int F_90 ( struct V_58 * V_58 , void * V_72 ,
struct V_165 * V_166 )
{
struct V_1 * V_2 = V_58 -> V_60 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_5 ( V_6 , V_14 , V_167 , V_166 ) ;
}
static int F_91 ( struct V_58 * V_58 , void * V_72 ,
struct V_168 * V_169 )
{
struct V_1 * V_2 = V_58 -> V_60 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_5 ( V_6 , V_14 , V_170 , V_169 ) ;
}
static int F_92 ( struct V_58 * V_58 , void * V_72 ,
struct V_168 * V_169 )
{
struct V_1 * V_2 = V_58 -> V_60 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_5 ( V_6 , V_14 , V_171 , V_169 ) ;
}
static void F_93 ( struct V_39 * V_40 )
{
struct V_1 * V_2 ;
F_53 ( & V_40 -> V_113 ) ;
F_94 (icd, &devices, list) {
if ( V_2 -> V_172 == V_40 -> V_173 ) {
int V_7 ;
V_2 -> V_41 = V_40 -> V_174 . V_117 ;
V_7 = F_95 ( V_2 ) ;
}
}
F_54 ( & V_40 -> V_113 ) ;
}
static int F_96 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_175 * V_176 ;
struct V_39 * V_40 = F_11 ( V_2 -> V_41 ) ;
struct V_177 * V_178 = F_97 ( V_4 -> V_179 ) ;
struct V_5 * V_180 ;
if ( ! V_178 ) {
F_4 ( V_2 -> V_10 , L_25 ,
V_4 -> V_179 ) ;
goto V_181;
}
V_4 -> V_182 -> V_183 = V_4 ;
V_180 = F_98 ( & V_40 -> V_174 , V_178 ,
V_4 -> V_182 , NULL ) ;
if ( ! V_180 )
goto V_184;
V_176 = F_99 ( V_180 ) ;
V_2 -> V_12 = & V_176 -> V_117 ;
return 0 ;
V_184:
F_100 ( V_178 ) ;
V_181:
return - V_17 ;
}
static void F_101 ( struct V_1 * V_2 )
{
struct V_175 * V_176 =
F_102 ( F_51 ( V_2 ) ) ;
struct V_177 * V_178 = V_176 -> V_185 ;
V_2 -> V_12 = NULL ;
F_103 ( F_104 ( V_176 ) ) ;
F_105 ( V_176 ) ;
F_100 ( V_178 ) ;
}
static int F_95 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_11 ( V_2 -> V_41 ) ;
struct V_3 * V_4 = F_50 ( V_2 ) ;
struct V_186 * V_12 = NULL ;
struct V_5 * V_6 ;
struct V_187 V_188 ;
int V_7 ;
F_106 ( V_2 -> V_10 , L_26 , F_107 ( V_2 -> V_10 ) ) ;
V_7 = F_108 ( & V_2 -> V_123 , 16 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_109 ( V_2 -> V_10 , V_4 -> V_8 ,
V_4 -> V_9 ) ;
if ( V_7 < 0 )
goto V_189;
if ( V_4 -> V_112 )
V_4 -> V_112 ( V_2 -> V_10 ) ;
V_7 = V_40 -> V_54 -> V_114 ( V_2 ) ;
if ( V_7 < 0 )
goto V_190;
V_7 = F_1 ( V_2 , V_4 ) ;
if ( V_7 < 0 )
goto V_116;
V_7 = F_110 ( V_2 ) ;
if ( V_7 < 0 )
goto V_191;
if ( V_4 -> V_182 ) {
V_7 = F_96 ( V_2 , V_4 ) ;
if ( V_7 < 0 )
goto V_192;
} else if ( ! V_4 -> V_193 || ! V_4 -> V_194 ) {
V_7 = - V_56 ;
goto V_192;
} else {
if ( V_4 -> V_195 )
V_7 = F_111 ( V_4 -> V_195 ) ;
V_7 = V_4 -> V_193 ( V_2 ) ;
if ( V_7 < 0 )
goto V_192;
V_12 = F_51 ( V_2 ) ;
if ( ! V_12 || ! V_12 -> V_145 || ! F_49 ( V_12 ) ||
! F_52 ( V_12 -> V_145 -> V_110 ) ) {
V_4 -> V_194 ( V_2 ) ;
V_7 = - V_17 ;
goto V_196;
}
}
V_6 = F_2 ( V_2 ) ;
V_6 -> V_197 = F_112 ( V_2 ) ;
F_113 ( V_6 , V_2 ) ;
if ( F_114 ( & V_2 -> V_123 , V_6 -> V_123 ) )
goto V_198;
V_7 = F_41 ( V_2 ) ;
if ( V_7 < 0 )
goto V_199;
V_2 -> V_106 = V_200 ;
F_53 ( & V_2 -> V_138 ) ;
V_7 = F_115 ( V_2 ) ;
if ( V_7 < 0 )
goto V_201;
V_7 = F_5 ( V_6 , V_14 , V_15 , 1 ) ;
if ( V_7 < 0 && V_7 != - V_16 )
goto V_18;
if ( ! F_5 ( V_6 , V_94 , V_202 , & V_188 ) ) {
V_2 -> V_103 = V_188 . V_47 ;
V_2 -> V_104 = V_188 . V_48 ;
V_2 -> V_105 = V_188 . V_105 ;
V_2 -> V_106 = V_188 . V_106 ;
}
V_40 -> V_54 -> remove ( V_2 ) ;
F_7 ( V_2 , V_4 ) ;
F_54 ( & V_2 -> V_138 ) ;
return 0 ;
V_18:
F_116 ( V_2 -> V_109 ) ;
V_201:
F_54 ( & V_2 -> V_138 ) ;
F_45 ( V_2 ) ;
V_199:
V_198:
if ( V_4 -> V_182 ) {
F_101 ( V_2 ) ;
} else {
V_4 -> V_194 ( V_2 ) ;
F_59 ( V_12 -> V_145 -> V_110 ) ;
}
V_196:
V_192:
F_117 ( V_2 -> V_109 ) ;
V_2 -> V_109 = NULL ;
V_191:
F_7 ( V_2 , V_4 ) ;
V_116:
V_40 -> V_54 -> remove ( V_2 ) ;
V_190:
F_118 ( V_4 -> V_8 , V_4 -> V_9 ) ;
V_189:
F_119 ( & V_2 -> V_123 ) ;
return V_7 ;
}
static int F_120 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_50 ( V_2 ) ;
struct V_108 * V_109 = V_2 -> V_109 ;
F_121 ( ! V_2 -> V_41 ) ;
F_119 ( & V_2 -> V_123 ) ;
if ( V_109 ) {
F_116 ( V_109 ) ;
V_2 -> V_109 = NULL ;
}
if ( V_4 -> V_182 ) {
F_101 ( V_2 ) ;
} else {
struct V_203 * V_204 = F_51 ( V_2 ) -> V_145 ;
if ( V_204 ) {
V_4 -> V_194 ( V_2 ) ;
F_59 ( V_204 -> V_110 ) ;
}
}
F_45 ( V_2 ) ;
F_118 ( V_4 -> V_8 , V_4 -> V_9 ) ;
return 0 ;
}
static int F_122 ( struct V_1 * V_2 ,
struct V_150 * V_69 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_5 ( V_6 , V_94 , V_151 , V_69 ) ;
}
static int F_123 ( struct V_1 * V_2 , struct V_152 * V_69 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_5 ( V_6 , V_94 , V_205 , V_69 ) ;
}
static int F_124 ( struct V_1 * V_2 , struct V_152 * V_69 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_5 ( V_6 , V_94 , V_206 , V_69 ) ;
}
static int F_125 ( struct V_1 * V_2 ,
struct V_162 * V_207 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_5 ( V_6 , V_94 , V_208 , V_207 ) ;
}
static int F_126 ( struct V_1 * V_2 ,
struct V_162 * V_207 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_5 ( V_6 , V_94 , V_209 , V_207 ) ;
}
static int F_127 ( struct V_1 * V_2 ,
struct V_73 * V_74 )
{
int V_7 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_19 * V_42 ;
T_7 V_210 = V_74 -> V_211 ;
struct V_73 V_212 = * V_74 ;
V_42 = F_8 ( V_2 , V_210 ) ;
if ( ! V_42 )
return - V_56 ;
V_212 . V_211 = V_42 -> V_93 ;
V_7 = F_5 ( V_6 , V_94 , V_75 , & V_212 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_74 = V_212 ;
V_74 -> V_211 = V_210 ;
return 0 ;
}
int F_128 ( struct V_39 * V_40 )
{
struct V_39 * V_213 ;
int V_7 ;
if ( ! V_40 || ! V_40 -> V_54 ||
! V_40 -> V_54 -> V_55 ||
! V_40 -> V_54 -> V_102 ||
! V_40 -> V_54 -> V_107 ||
! V_40 -> V_54 -> V_147 ||
( ( ! V_40 -> V_54 -> V_80 ||
! V_40 -> V_54 -> V_82 ) &&
! V_40 -> V_54 -> V_121 ) ||
! V_40 -> V_54 -> V_114 ||
! V_40 -> V_54 -> remove ||
! V_40 -> V_54 -> V_135 ||
! V_40 -> V_174 . V_117 )
return - V_56 ;
if ( ! V_40 -> V_54 -> V_160 )
V_40 -> V_54 -> V_160 = F_124 ;
if ( ! V_40 -> V_54 -> V_153 )
V_40 -> V_54 -> V_153 = F_123 ;
if ( ! V_40 -> V_54 -> V_151 )
V_40 -> V_54 -> V_151 = F_122 ;
if ( ! V_40 -> V_54 -> V_164 )
V_40 -> V_54 -> V_164 = F_126 ;
if ( ! V_40 -> V_54 -> V_163 )
V_40 -> V_54 -> V_163 = F_125 ;
if ( ! V_40 -> V_54 -> V_75 )
V_40 -> V_54 -> V_75 = F_127 ;
F_53 ( & V_214 ) ;
F_94 (ix, &hosts, list) {
if ( V_213 -> V_173 == V_40 -> V_173 ) {
V_7 = - V_79 ;
goto V_215;
}
}
V_7 = F_129 ( V_40 -> V_174 . V_117 , & V_40 -> V_174 ) ;
if ( V_7 < 0 )
goto V_215;
F_130 ( & V_40 -> V_216 , & V_217 ) ;
F_54 ( & V_214 ) ;
F_131 ( & V_40 -> V_113 ) ;
F_93 ( V_40 ) ;
return 0 ;
V_215:
F_54 ( & V_214 ) ;
return V_7 ;
}
void F_132 ( struct V_39 * V_40 )
{
struct V_1 * V_2 ;
F_53 ( & V_214 ) ;
F_133 ( & V_40 -> V_216 ) ;
F_94 (icd, &devices, list)
if ( V_2 -> V_172 == V_40 -> V_173 && F_51 ( V_2 ) )
F_120 ( V_2 ) ;
F_54 ( & V_214 ) ;
F_134 ( & V_40 -> V_174 ) ;
}
static int F_135 ( struct V_1 * V_2 )
{
struct V_1 * V_213 ;
int V_218 = - 1 , V_21 ;
for ( V_21 = 0 ; V_21 < 256 && V_218 < 0 ; V_21 ++ ) {
V_218 = V_21 ;
F_94 (ix, &devices, list) {
if ( V_213 -> V_172 == V_2 -> V_172 && V_213 -> V_219 == V_21 ) {
V_218 = - 1 ;
break;
}
}
}
if ( V_218 < 0 )
return - V_98 ;
V_2 -> V_219 = V_218 ;
V_2 -> V_111 = 0 ;
V_2 -> V_220 = NULL ;
F_131 ( & V_2 -> V_138 ) ;
F_130 ( & V_2 -> V_216 , & V_221 ) ;
return 0 ;
}
static int F_110 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_11 ( V_2 -> V_41 ) ;
struct V_108 * V_109 = F_136 () ;
if ( ! V_109 )
return - V_98 ;
F_76 ( V_109 -> V_68 , V_40 -> V_146 , sizeof( V_109 -> V_68 ) ) ;
V_109 -> V_41 = V_2 -> V_10 ;
V_109 -> V_222 = V_67 ;
V_109 -> V_223 = & V_224 ;
V_109 -> V_225 = & V_226 ;
V_109 -> V_227 = F_117 ;
V_109 -> V_228 = V_67 ;
V_109 -> V_123 = & V_2 -> V_123 ;
V_109 -> V_229 = & V_2 -> V_138 ;
F_137 ( V_230 , & V_109 -> V_28 ) ;
V_2 -> V_109 = V_109 ;
return 0 ;
}
static int F_115 ( struct V_1 * V_2 )
{
const struct V_231 * type = V_2 -> V_109 -> V_117 . type ;
int V_7 ;
if ( ! V_2 -> V_41 )
return - V_17 ;
V_7 = F_138 ( V_2 -> V_109 , V_232 , - 1 ) ;
if ( V_7 < 0 ) {
F_4 ( V_2 -> V_10 , L_27 , V_7 ) ;
return V_7 ;
}
V_2 -> V_109 -> V_117 . type = type ;
return 0 ;
}
static int T_8 F_139 ( struct V_233 * V_10 )
{
struct V_3 * V_4 = V_10 -> V_117 . V_183 ;
struct V_1 * V_2 ;
int V_7 ;
if ( ! V_4 )
return - V_56 ;
V_2 = F_140 ( sizeof( * V_2 ) , V_234 ) ;
if ( ! V_2 )
return - V_98 ;
V_2 -> V_172 = V_4 -> V_235 ;
V_2 -> V_236 = V_4 ;
V_2 -> V_10 = & V_10 -> V_117 ;
F_141 ( V_10 , V_2 ) ;
V_7 = F_135 ( V_2 ) ;
if ( V_7 < 0 )
goto V_237;
V_2 -> V_103 = V_238 ;
V_2 -> V_104 = V_239 ;
return 0 ;
V_237:
F_142 ( V_2 ) ;
return V_7 ;
}
static int T_9 F_143 ( struct V_233 * V_10 )
{
struct V_1 * V_2 = F_144 ( V_10 ) ;
if ( ! V_2 )
return - V_56 ;
F_133 ( & V_2 -> V_216 ) ;
F_142 ( V_2 ) ;
return 0 ;
}
static int T_10 F_145 ( void )
{
return F_146 ( & V_240 ) ;
}
static void T_11 F_147 ( void )
{
F_148 ( & V_240 ) ;
}

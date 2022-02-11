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
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
F_30 ( V_70 != V_69 -> V_71 ) ;
if ( V_19 -> V_91 && V_19 -> V_91 != V_69 )
return - V_92 ;
if ( V_27 -> V_28 -> V_93 ) {
V_7 = F_38 ( & V_19 -> V_94 , V_90 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = V_27 -> V_28 -> V_95 ( V_19 , V_90 ) ;
} else {
V_7 = F_39 ( & V_19 -> V_96 , V_90 ) ;
}
if ( ! V_7 )
V_19 -> V_91 = V_90 -> V_97 ? V_69 : NULL ;
return V_7 ;
}
static int F_40 ( struct V_69 * V_69 , void * V_70 ,
struct V_98 * V_90 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
F_30 ( V_70 != V_69 -> V_71 ) ;
if ( V_27 -> V_28 -> V_93 )
return F_41 ( & V_19 -> V_94 , V_90 ) ;
else
return F_42 ( & V_19 -> V_96 , V_90 ) ;
}
static int F_43 ( struct V_69 * V_69 , void * V_70 ,
struct V_98 * V_90 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
F_30 ( V_70 != V_69 -> V_71 ) ;
if ( V_19 -> V_91 != V_69 )
return - V_92 ;
if ( V_27 -> V_28 -> V_93 )
return F_44 ( & V_19 -> V_94 , V_90 ) ;
else
return F_45 ( & V_19 -> V_96 , V_90 ) ;
}
static int F_46 ( struct V_69 * V_69 , void * V_70 ,
struct V_98 * V_90 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
F_30 ( V_70 != V_69 -> V_71 ) ;
if ( V_19 -> V_91 != V_69 )
return - V_92 ;
if ( V_27 -> V_28 -> V_93 )
return F_47 ( & V_19 -> V_94 , V_90 , V_69 -> V_99 & V_100 ) ;
else
return F_48 ( & V_19 -> V_96 , V_90 , V_69 -> V_99 & V_100 ) ;
}
static int F_49 ( struct V_69 * V_69 , void * V_70 ,
struct V_101 * V_102 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
int V_7 ;
if ( V_27 -> V_28 -> V_93 )
return - V_103 ;
if ( V_19 -> V_91 && V_19 -> V_91 != V_69 )
return - V_92 ;
V_7 = F_50 ( & V_19 -> V_96 , V_102 ) ;
if ( ! V_7 )
V_19 -> V_91 = V_69 ;
return V_7 ;
}
static int F_51 ( struct V_69 * V_69 , void * V_70 ,
struct V_98 * V_104 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
if ( V_27 -> V_28 -> V_93 )
return - V_67 ;
else
return F_52 ( & V_19 -> V_96 , V_104 ) ;
}
static int F_53 ( struct V_69 * V_69 , void * V_70 ,
struct V_105 * V_90 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
if ( V_27 -> V_28 -> V_93 )
return - V_103 ;
if ( V_19 -> V_91 && V_19 -> V_91 != V_69 )
return - V_92 ;
return F_54 ( & V_19 -> V_96 , V_90 ) ;
}
static int F_55 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
unsigned int V_34 , V_106 = 0 , V_107 = 0 ;
int V_7 ;
struct V_108 V_109 = {
. V_110 = V_111 ,
} ;
while ( ! F_14 ( V_21 , V_112 , V_113 , NULL , & V_109 ) ) {
V_107 ++ ;
V_109 . V_75 ++ ;
}
if ( ! V_27 -> V_28 -> V_114 )
V_106 = V_107 ;
else
for ( V_34 = 0 ; V_34 < V_107 ; V_34 ++ ) {
V_7 = V_27 -> V_28 -> V_114 ( V_19 , V_34 , NULL ) ;
if ( V_7 < 0 )
return V_7 ;
V_106 += V_7 ;
}
if ( ! V_106 )
return - V_115 ;
V_19 -> V_36 =
F_56 ( V_106 * sizeof( struct V_32 ) ) ;
if ( ! V_19 -> V_36 )
return - V_116 ;
F_24 ( V_19 -> V_57 , L_8 , V_106 ) ;
V_106 = 0 ;
for ( V_34 = 0 ; V_34 < V_107 ; V_34 ++ )
if ( ! V_27 -> V_28 -> V_114 ) {
V_109 . V_75 = V_34 ;
F_14 ( V_21 , V_112 , V_113 , NULL , & V_109 ) ;
V_19 -> V_36 [ V_106 ] . V_37 =
F_57 ( V_109 . V_109 ) ;
if ( V_19 -> V_36 [ V_106 ] . V_37 )
V_19 -> V_36 [ V_106 ++ ] . V_109 = V_109 . V_109 ;
} else {
V_7 = V_27 -> V_28 -> V_114 ( V_19 , V_34 ,
& V_19 -> V_36 [ V_106 ] ) ;
if ( V_7 < 0 )
goto V_117;
V_106 += V_7 ;
}
V_19 -> V_35 = V_106 ;
V_19 -> V_118 = & V_19 -> V_36 [ 0 ] ;
return 0 ;
V_117:
F_58 ( V_19 -> V_36 ) ;
return V_7 ;
}
static void F_59 ( struct V_18 * V_19 )
{
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
if ( V_27 -> V_28 -> V_119 )
V_27 -> V_28 -> V_119 ( V_19 ) ;
V_19 -> V_118 = NULL ;
V_19 -> V_35 = 0 ;
F_58 ( V_19 -> V_36 ) ;
V_19 -> V_36 = NULL ;
}
static int F_60 ( struct V_18 * V_19 ,
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
V_7 = V_27 -> V_28 -> V_120 ( V_19 , V_40 ) ;
if ( V_7 < 0 ) {
return V_7 ;
} else if ( ! V_19 -> V_118 ||
V_19 -> V_118 -> V_37 -> V_33 != V_55 -> V_58 ) {
F_4 ( V_19 -> V_57 ,
L_10 ) ;
return - V_67 ;
}
V_19 -> V_121 = V_55 -> V_59 ;
V_19 -> V_122 = V_55 -> V_60 ;
V_19 -> V_64 = V_55 -> V_64 ;
V_19 -> V_65 = V_55 -> V_65 ;
V_19 -> V_123 = V_55 -> V_123 ;
V_19 -> V_124 = V_55 -> V_124 ;
if ( V_27 -> V_28 -> V_93 )
V_19 -> V_94 . V_124 = V_55 -> V_124 ;
F_24 ( V_19 -> V_57 , L_11 ,
V_19 -> V_121 , V_19 -> V_122 ) ;
return V_27 -> V_28 -> V_125 ( V_19 ) ;
}
static int F_61 ( struct V_18 * V_19 )
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
if ( V_27 -> V_28 -> V_126 ) {
V_7 = V_27 -> V_28 -> V_126 ( V_19 ) ;
if ( V_7 < 0 )
goto V_127;
}
V_27 -> V_19 = V_19 ;
return 0 ;
V_127:
if ( ! V_19 -> V_6 )
F_19 ( V_27 ) ;
return V_7 ;
}
static void F_62 ( struct V_18 * V_19 )
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
static int F_63 ( struct V_69 * V_69 )
{
struct V_128 * V_78 = F_64 ( V_69 ) ;
struct V_18 * V_19 ;
struct V_26 * V_27 ;
int V_7 ;
if ( F_65 ( & V_129 ) )
return - V_130 ;
if ( ! V_78 || ! F_66 ( V_78 ) ) {
F_18 ( & V_129 ) ;
return - V_25 ;
}
V_19 = F_67 ( V_78 ) ;
V_27 = F_23 ( V_19 -> V_52 ) ;
V_7 = F_68 ( V_27 -> V_28 -> V_131 ) ? 0 : - V_25 ;
F_18 ( & V_129 ) ;
if ( V_7 < 0 ) {
F_4 ( V_19 -> V_57 , L_12 ) ;
return V_7 ;
}
if ( ! F_69 ( V_19 ) ) {
V_7 = - V_25 ;
goto V_132;
}
if ( F_65 ( & V_27 -> V_133 ) ) {
V_7 = - V_130 ;
goto V_134;
}
V_19 -> V_135 ++ ;
if ( V_19 -> V_135 == 1 ) {
struct V_136 * V_137 = F_70 ( V_19 ) ;
struct V_51 V_40 = {
. type = V_72 ,
. V_56 . V_55 = {
. V_59 = V_19 -> V_121 ,
. V_60 = V_19 -> V_122 ,
. V_124 = V_19 -> V_124 ,
. V_123 = V_19 -> V_123 ,
. V_58 =
V_19 -> V_118 -> V_37 -> V_33 ,
} ,
} ;
if ( V_137 -> V_138 . V_139 )
if ( V_19 -> V_140 )
V_137 -> V_138 . V_139 ( V_19 -> V_140 ) ;
V_7 = F_61 ( V_19 ) ;
if ( V_7 < 0 ) {
F_4 ( V_19 -> V_57 , L_13 , V_7 ) ;
goto V_141;
}
V_7 = F_12 ( V_19 ) ;
if ( V_7 < 0 )
goto V_142;
F_71 ( & V_19 -> V_78 -> V_2 ) ;
V_7 = F_72 ( & V_19 -> V_78 -> V_2 ) ;
if ( V_7 < 0 && V_7 != - V_143 )
goto V_144;
V_7 = F_60 ( V_19 , & V_40 ) ;
if ( V_7 < 0 )
goto V_145;
if ( V_27 -> V_28 -> V_93 ) {
V_27 -> V_28 -> V_93 ( & V_19 -> V_94 , V_19 ) ;
} else {
V_7 = V_27 -> V_28 -> V_146 ( & V_19 -> V_96 , V_19 ) ;
if ( V_7 < 0 )
goto V_147;
}
F_73 ( & V_19 -> V_148 ) ;
}
F_18 ( & V_27 -> V_133 ) ;
V_69 -> V_71 = V_19 ;
F_24 ( V_19 -> V_57 , L_14 ) ;
return 0 ;
V_147:
V_145:
F_74 ( & V_19 -> V_78 -> V_2 ) ;
V_144:
F_15 ( V_19 ) ;
V_142:
F_62 ( V_19 ) ;
V_141:
V_19 -> V_135 -- ;
F_18 ( & V_27 -> V_133 ) ;
V_134:
V_132:
F_75 ( V_27 -> V_28 -> V_131 ) ;
return V_7 ;
}
static int F_76 ( struct V_69 * V_69 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
F_17 ( & V_27 -> V_133 ) ;
if ( V_19 -> V_91 == V_69 ) {
if ( V_27 -> V_28 -> V_146 )
F_77 ( & V_19 -> V_96 ) ;
V_19 -> V_91 = NULL ;
}
V_19 -> V_135 -- ;
if ( ! V_19 -> V_135 ) {
F_78 ( & V_19 -> V_78 -> V_2 ) ;
F_74 ( & V_19 -> V_78 -> V_2 ) ;
F_15 ( V_19 ) ;
F_62 ( V_19 ) ;
}
F_18 ( & V_27 -> V_133 ) ;
F_75 ( V_27 -> V_28 -> V_131 ) ;
F_24 ( V_19 -> V_57 , L_15 ) ;
return 0 ;
}
static T_2 F_79 ( struct V_69 * V_69 , char T_3 * V_149 ,
T_4 V_97 , T_5 * V_150 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
F_24 ( V_19 -> V_57 , L_16 , V_149 ) ;
if ( V_27 -> V_28 -> V_146 && V_19 -> V_96 . V_151 & V_152 )
return F_80 ( & V_19 -> V_96 , V_149 , V_97 , V_150 ,
V_69 -> V_99 & V_100 ) ;
F_4 ( V_19 -> V_57 , L_17 ) ;
return - V_67 ;
}
static int F_81 ( struct V_69 * V_69 , struct V_153 * V_154 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
int V_17 ;
F_24 ( V_19 -> V_57 , L_18 , ( unsigned long ) V_154 ) ;
if ( V_19 -> V_91 != V_69 )
return - V_92 ;
if ( F_65 ( & V_27 -> V_133 ) )
return - V_130 ;
if ( V_27 -> V_28 -> V_93 )
V_17 = F_82 ( & V_19 -> V_94 , V_154 ) ;
else
V_17 = F_83 ( & V_19 -> V_96 , V_154 ) ;
F_18 ( & V_27 -> V_133 ) ;
F_24 ( V_19 -> V_57 , L_19 ,
( unsigned long ) V_154 -> V_155 ,
( unsigned long ) V_154 -> V_156 - ( unsigned long ) V_154 -> V_155 ,
V_17 ) ;
return V_17 ;
}
static unsigned int F_84 ( struct V_69 * V_69 , T_6 * V_157 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
unsigned V_158 = V_159 ;
if ( V_19 -> V_91 != V_69 )
return V_159 ;
F_17 ( & V_27 -> V_133 ) ;
if ( V_27 -> V_28 -> V_93 && F_85 ( & V_19 -> V_94 . V_160 ) )
F_4 ( V_19 -> V_57 , L_20 ) ;
else
V_158 = V_27 -> V_28 -> V_161 ( V_69 , V_157 ) ;
F_18 ( & V_27 -> V_133 ) ;
return V_158 ;
}
static int F_86 ( struct V_69 * V_69 , void * V_70 ,
struct V_51 * V_40 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
int V_7 ;
F_30 ( V_70 != V_69 -> V_71 ) ;
if ( V_40 -> type != V_72 ) {
F_87 ( V_19 -> V_57 , L_21 , V_40 -> type ) ;
return - V_67 ;
}
if ( V_19 -> V_91 && V_19 -> V_91 != V_69 )
return - V_92 ;
if ( F_88 ( F_23 ( V_19 -> V_52 ) , V_19 ) ) {
F_4 ( V_19 -> V_57 , L_22 ) ;
return - V_92 ;
}
V_7 = F_60 ( V_19 , V_40 ) ;
if ( ! V_7 && ! V_19 -> V_91 )
V_19 -> V_91 = V_69 ;
return V_7 ;
}
static int F_89 ( struct V_69 * V_69 , void * V_70 ,
struct V_162 * V_40 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
const struct V_163 * V_164 ;
F_30 ( V_70 != V_69 -> V_71 ) ;
if ( V_40 -> V_75 >= V_19 -> V_35 )
return - V_67 ;
V_164 = V_19 -> V_36 [ V_40 -> V_75 ] . V_37 ;
if ( V_164 -> V_80 )
F_90 ( V_40 -> V_165 , V_164 -> V_80 , sizeof( V_40 -> V_165 ) ) ;
V_40 -> V_58 = V_164 -> V_33 ;
return 0 ;
}
static int F_91 ( struct V_69 * V_69 , void * V_70 ,
struct V_51 * V_40 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_54 * V_55 = & V_40 -> V_56 . V_55 ;
F_30 ( V_70 != V_69 -> V_71 ) ;
if ( V_40 -> type != V_72 )
return - V_67 ;
V_55 -> V_59 = V_19 -> V_121 ;
V_55 -> V_60 = V_19 -> V_122 ;
V_55 -> V_64 = V_19 -> V_64 ;
V_55 -> V_65 = V_19 -> V_65 ;
V_55 -> V_124 = V_19 -> V_124 ;
V_55 -> V_58 = V_19 -> V_118 -> V_37 -> V_33 ;
V_55 -> V_123 = V_19 -> V_123 ;
F_24 ( V_19 -> V_57 , L_23 ,
V_19 -> V_118 -> V_37 -> V_33 ) ;
return 0 ;
}
static int F_92 ( struct V_69 * V_69 , void * V_70 ,
struct V_166 * V_167 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
F_30 ( V_70 != V_69 -> V_71 ) ;
F_90 ( V_167 -> V_168 , V_27 -> V_169 , sizeof( V_167 -> V_168 ) ) ;
return V_27 -> V_28 -> V_170 ( V_27 , V_167 ) ;
}
static int F_93 ( struct V_69 * V_69 , void * V_70 ,
enum V_171 V_34 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
struct V_20 * V_21 = F_13 ( V_19 ) ;
int V_7 ;
F_30 ( V_70 != V_69 -> V_71 ) ;
if ( V_34 != V_72 )
return - V_67 ;
if ( V_19 -> V_91 != V_69 )
return - V_92 ;
if ( V_27 -> V_28 -> V_93 )
V_7 = F_94 ( & V_19 -> V_94 ) ;
else
V_7 = F_95 ( & V_19 -> V_96 , V_34 ) ;
if ( ! V_7 )
F_14 ( V_21 , V_82 , V_172 , 1 ) ;
return V_7 ;
}
static int F_96 ( struct V_69 * V_69 , void * V_70 ,
enum V_171 V_34 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_20 * V_21 = F_13 ( V_19 ) ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
int V_7 ;
F_30 ( V_70 != V_69 -> V_71 ) ;
if ( V_34 != V_72 )
return - V_67 ;
if ( V_19 -> V_91 != V_69 )
return - V_92 ;
if ( V_27 -> V_28 -> V_93 )
V_7 = F_97 ( & V_19 -> V_94 ) ;
else
V_7 = F_98 ( & V_19 -> V_96 , V_34 ) ;
F_14 ( V_21 , V_82 , V_172 , 0 ) ;
return V_7 ;
}
static int F_99 ( struct V_69 * V_69 , void * V_85 ,
struct V_173 * V_174 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
if ( V_174 -> type != V_72 )
return - V_67 ;
return V_27 -> V_28 -> V_175 ( V_19 , V_174 ) ;
}
static int F_100 ( struct V_69 * V_69 , void * V_85 ,
struct V_173 * V_174 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
int V_7 ;
if ( V_174 -> type != V_72 ||
( V_174 -> V_176 != V_177 &&
V_174 -> V_176 != V_178 ) )
return - V_67 ;
if ( V_174 -> V_176 == V_177 ) {
if ( F_88 ( V_27 , V_19 ) &&
( V_19 -> V_121 != V_174 -> V_179 . V_59 ||
V_19 -> V_122 != V_174 -> V_179 . V_60 ) )
return - V_92 ;
if ( V_19 -> V_91 && V_19 -> V_91 != V_69 )
return - V_92 ;
}
if ( V_174 -> V_176 == V_178 && F_88 ( V_27 , V_19 ) &&
V_27 -> V_28 -> V_180 )
V_7 = V_27 -> V_28 -> V_180 ( V_19 , V_174 ) ;
else
V_7 = V_27 -> V_28 -> V_181 ( V_19 , V_174 ) ;
if ( ! V_7 &&
V_174 -> V_176 == V_177 ) {
V_19 -> V_121 = V_174 -> V_179 . V_59 ;
V_19 -> V_122 = V_174 -> V_179 . V_60 ;
if ( ! V_19 -> V_91 )
V_19 -> V_91 = V_69 ;
}
return V_7 ;
}
static int F_101 ( struct V_69 * V_69 , void * V_85 ,
struct V_182 * V_81 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
if ( V_27 -> V_28 -> V_183 )
return V_27 -> V_28 -> V_183 ( V_19 , V_81 ) ;
return - V_24 ;
}
static int F_102 ( struct V_69 * V_69 , void * V_85 ,
struct V_182 * V_81 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
if ( V_27 -> V_28 -> V_184 )
return V_27 -> V_28 -> V_184 ( V_19 , V_81 ) ;
return - V_24 ;
}
static void F_103 ( struct V_26 * V_27 )
{
struct V_18 * V_19 ;
F_17 ( & V_129 ) ;
F_104 (icd, &devices, list)
if ( V_19 -> V_185 == V_27 -> V_186 ) {
struct V_136 * V_137 = F_70 ( V_19 ) ;
struct V_3 * V_4 = & V_137 -> V_138 ;
if ( V_4 -> V_139 )
if ( V_19 -> V_140 )
V_4 -> V_139 ( V_19 -> V_140 ) ;
V_19 -> V_52 = V_27 -> V_187 . V_2 ;
F_105 ( V_27 , V_19 ) ;
}
F_18 ( & V_129 ) ;
}
static int F_106 ( struct V_5 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_70 ;
struct V_26 * V_27 ;
if ( ! V_19 || ! V_19 -> V_52 )
return - V_25 ;
V_27 = F_23 ( V_19 -> V_52 ) ;
if ( ! F_68 ( V_27 -> V_28 -> V_131 ) )
return - V_25 ;
return F_16 ( V_27 ) ;
}
static void F_107 ( struct V_5 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_70 ;
struct V_26 * V_27 ;
if ( ! V_19 || ! V_19 -> V_52 )
return;
V_27 = F_23 ( V_19 -> V_52 ) ;
F_19 ( V_27 ) ;
F_75 ( V_27 -> V_28 -> V_131 ) ;
}
static int F_108 ( struct V_136 * V_137 ,
struct V_188 * V_189 )
{
struct V_190 * V_57 ;
int V_7 , V_34 ;
F_17 ( & V_129 ) ;
V_34 = F_109 ( V_191 , V_192 ) ;
if ( V_34 < V_192 )
F_110 ( V_34 , V_191 ) ;
F_18 ( & V_129 ) ;
if ( V_34 >= V_192 )
return - V_116 ;
V_57 = F_111 ( L_24 , V_34 ) ;
if ( ! V_57 )
return - V_116 ;
V_7 = F_112 ( V_57 , V_137 , sizeof( * V_137 ) ) ;
if ( V_7 < 0 ) {
F_113 ( V_57 ) ;
return V_7 ;
}
V_189 -> V_57 = V_57 ;
return 0 ;
}
static struct V_18 * F_114 ( struct V_188 * V_189 )
{
struct V_190 * V_57 = V_189 -> V_57 ;
int V_7 ;
V_7 = F_115 ( V_57 ) ;
if ( V_7 < 0 || ! V_57 -> V_2 . V_168 )
return NULL ;
return F_116 ( V_57 ) ;
}
static int F_117 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
struct V_193 V_56 = {
. V_110 = V_111 ,
} ;
struct V_194 * V_195 = & V_56 . V_164 ;
int V_7 ;
V_21 -> V_196 = F_118 ( V_19 ) ;
F_119 ( V_21 , V_19 ) ;
F_14 ( V_21 , V_82 , V_197 , & V_19 -> V_78 -> V_79 ) ;
V_7 = F_120 ( & V_19 -> V_148 , V_21 -> V_148 , NULL ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_61 ( V_19 ) ;
if ( V_7 < 0 ) {
F_4 ( V_19 -> V_57 , L_13 , V_7 ) ;
return V_7 ;
}
V_7 = F_55 ( V_19 ) ;
if ( V_7 < 0 )
goto V_198;
V_19 -> V_124 = V_199 ;
V_7 = F_121 ( V_19 ) ;
if ( V_7 < 0 )
goto V_200;
if ( ! F_14 ( V_21 , V_112 , V_201 , NULL , & V_56 ) ) {
V_19 -> V_121 = V_195 -> V_59 ;
V_19 -> V_122 = V_195 -> V_60 ;
V_19 -> V_123 = V_195 -> V_123 ;
V_19 -> V_124 = V_195 -> V_124 ;
}
F_62 ( V_19 ) ;
return 0 ;
V_200:
F_59 ( V_19 ) ;
V_198:
F_62 ( V_19 ) ;
return V_7 ;
}
static int F_122 ( struct V_18 * V_19 ,
struct V_136 * V_137 )
{
struct V_3 * V_4 ;
struct V_202 * V_203 ;
struct V_26 * V_27 ;
struct V_204 * V_205 = & V_137 -> V_206 ;
struct V_207 * V_208 ;
struct V_20 * V_209 ;
char V_210 [ V_211 ] ;
int V_7 ;
if ( V_19 -> V_189 ) {
return - V_212 ;
}
V_27 = F_23 ( V_19 -> V_52 ) ;
V_208 = F_123 ( V_205 -> V_213 ) ;
if ( ! V_208 ) {
F_4 ( V_19 -> V_57 , L_25 ,
V_205 -> V_213 ) ;
return - V_25 ;
}
V_4 = F_124 ( & V_137 -> V_138 , sizeof( * V_4 ) , V_214 ) ;
if ( ! V_4 ) {
V_7 = - V_116 ;
goto V_215;
}
V_4 -> V_11 . V_12 = 0 ;
V_4 -> V_11 . V_13 = NULL ;
V_205 -> V_216 -> V_217 = V_4 ;
F_125 ( V_210 , sizeof( V_210 ) ,
V_205 -> V_213 , V_205 -> V_216 -> V_218 ) ;
V_19 -> V_6 = F_126 ( & V_219 , V_210 , V_19 ) ;
if ( F_127 ( V_19 -> V_6 ) ) {
V_7 = F_128 ( V_19 -> V_6 ) ;
goto V_220;
}
V_209 = F_129 ( & V_27 -> V_187 , V_208 ,
V_205 -> V_216 , NULL ) ;
if ( ! V_209 ) {
V_7 = - V_25 ;
goto V_221;
}
V_203 = F_130 ( V_209 ) ;
V_19 -> V_140 = & V_203 -> V_2 ;
return 0 ;
V_221:
F_131 ( V_19 -> V_6 ) ;
V_19 -> V_6 = NULL ;
V_220:
F_132 ( V_4 ) ;
V_215:
F_133 ( V_208 ) ;
return V_7 ;
}
static void F_134 ( struct V_18 * V_19 )
{
struct V_202 * V_203 =
F_135 ( F_69 ( V_19 ) ) ;
struct V_207 * V_208 ;
struct V_3 * V_4 ;
V_19 -> V_140 = NULL ;
if ( V_19 -> V_189 )
return;
V_208 = V_203 -> V_222 ;
V_4 = V_203 -> V_2 . V_217 ;
F_136 ( F_137 ( V_203 ) ) ;
F_138 ( V_203 ) ;
F_133 ( V_208 ) ;
F_132 ( V_4 ) ;
F_131 ( V_19 -> V_6 ) ;
V_19 -> V_6 = NULL ;
}
static int F_139 ( struct V_223 * V_224 ,
struct V_20 * V_21 ,
struct V_225 * V_226 )
{
struct V_188 * V_189 = F_140 ( V_224 ,
struct V_188 , V_224 ) ;
struct V_18 * V_19 = F_116 ( V_189 -> V_57 ) ;
if ( V_226 == V_189 -> V_227 && ! F_30 ( V_19 -> V_140 ) ) {
struct V_202 * V_203 = F_130 ( V_21 ) ;
if ( V_203 ) {
struct V_136 * V_137 = F_70 ( V_19 ) ;
struct V_3 * V_4 =
F_141 ( V_203 ) ;
if ( V_4 ) {
memcpy ( & V_137 -> V_138 , V_4 ,
sizeof( V_137 -> V_138 ) ) ;
if ( V_4 -> V_139 )
V_4 -> V_139 ( & V_203 -> V_2 ) ;
}
V_19 -> V_140 = & V_203 -> V_2 ;
}
}
return 0 ;
}
static void F_142 ( struct V_223 * V_224 ,
struct V_20 * V_21 ,
struct V_225 * V_226 )
{
struct V_188 * V_189 = F_140 ( V_224 ,
struct V_188 , V_224 ) ;
struct V_18 * V_19 = F_116 ( V_189 -> V_57 ) ;
V_19 -> V_140 = NULL ;
if ( V_19 -> V_6 ) {
F_131 ( V_19 -> V_6 ) ;
V_19 -> V_6 = NULL ;
}
}
static int F_143 ( struct V_223 * V_224 )
{
struct V_188 * V_189 = F_140 ( V_224 ,
struct V_188 , V_224 ) ;
struct V_18 * V_19 = F_116 ( V_189 -> V_57 ) ;
if ( F_69 ( V_19 ) ) {
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
int V_7 ;
F_17 ( & V_129 ) ;
V_7 = F_105 ( V_27 , V_19 ) ;
F_18 ( & V_129 ) ;
if ( V_7 < 0 )
return V_7 ;
}
return 0 ;
}
static int F_144 ( struct V_26 * V_27 ,
struct V_225 * * V_226 , unsigned int V_228 )
{
struct V_229 * V_230 ;
struct V_188 * V_189 ;
struct V_18 * V_19 ;
struct V_136 V_137 = { . V_206 . V_231 = V_27 -> V_186 ,} ;
char V_210 [ V_211 ] ;
unsigned int V_34 ;
int V_7 ;
for ( V_34 = 0 ; V_34 < V_228 ; V_34 ++ ) {
V_230 = F_140 ( V_226 [ V_34 ] , struct V_229 , V_226 ) ;
if ( V_230 -> V_232 == V_233 )
break;
}
if ( V_34 >= V_228 || V_226 [ V_34 ] -> V_234 != V_235 ) {
F_4 ( V_27 -> V_187 . V_2 , L_26 ) ;
return - V_25 ;
}
V_189 = F_145 ( V_27 -> V_187 . V_2 , sizeof( * V_189 ) , V_214 ) ;
if ( ! V_189 )
return - V_116 ;
V_137 . V_206 . V_216 = F_146 ( - V_236 ) ;
V_7 = F_108 ( & V_137 , V_189 ) ;
if ( V_7 < 0 )
goto V_237;
V_189 -> V_227 = & V_230 -> V_226 ;
V_19 = F_114 ( V_189 ) ;
if ( ! V_19 ) {
V_7 = - V_116 ;
goto V_238;
}
V_189 -> V_224 . V_239 = V_226 ;
V_189 -> V_224 . V_240 = V_228 ;
V_189 -> V_224 . V_241 = F_139 ;
V_189 -> V_224 . V_242 = F_142 ;
V_189 -> V_224 . V_243 = F_143 ;
V_19 -> V_189 = V_189 ;
V_19 -> V_52 = V_27 -> V_187 . V_2 ;
F_125 ( V_210 , sizeof( V_210 ) ,
V_230 -> V_226 . V_244 . V_245 . V_246 ,
V_230 -> V_226 . V_244 . V_245 . V_247 ) ;
V_19 -> V_6 = F_126 ( & V_219 , V_210 , V_19 ) ;
if ( F_127 ( V_19 -> V_6 ) ) {
V_7 = F_128 ( V_19 -> V_6 ) ;
goto V_220;
}
V_7 = F_147 ( & V_27 -> V_187 , & V_189 -> V_224 ) ;
if ( ! V_7 )
return 0 ;
F_131 ( V_19 -> V_6 ) ;
V_220:
V_19 -> V_6 = NULL ;
F_148 ( V_189 -> V_57 ) ;
V_238:
F_113 ( V_189 -> V_57 ) ;
V_237:
F_149 ( V_27 -> V_187 . V_2 , V_189 ) ;
F_4 ( V_27 -> V_187 . V_2 , L_27 , V_7 ) ;
return V_7 ;
}
static void F_150 ( struct V_26 * V_27 )
{
struct V_225 * * V_226 ;
int V_248 ;
for ( V_248 = 0 , V_226 = V_27 -> V_226 ; V_27 -> V_249 [ V_248 ] ; V_248 ++ ) {
F_144 ( V_27 , V_226 , V_27 -> V_249 [ V_248 ] ) ;
V_226 += V_27 -> V_249 [ V_248 ] ;
}
}
static int F_151 ( struct V_26 * V_27 ,
struct V_250 * V_251 ,
struct V_250 * V_252 )
{
struct V_18 * V_19 ;
struct V_136 V_137 = { . V_206 . V_231 = V_27 -> V_186 ,} ;
struct V_188 * V_189 ;
struct V_253 * V_254 ;
struct V_202 * V_203 ;
char V_210 [ V_211 ] ;
int V_7 ;
V_254 = F_145 ( V_27 -> V_187 . V_2 , sizeof( struct V_253 ) ,
V_214 ) ;
if ( ! V_254 )
return - V_116 ;
V_254 -> V_230 . V_226 . V_244 . V_255 . V_256 = V_252 ;
V_254 -> V_230 . V_226 . V_234 = V_257 ;
V_254 -> V_209 = & V_254 -> V_230 . V_226 ;
V_189 = & V_254 -> V_189 ;
V_137 . V_206 . V_216 = F_146 ( - V_236 ) ;
V_7 = F_108 ( & V_137 , V_189 ) ;
if ( V_7 < 0 )
goto V_237;
V_189 -> V_227 = & V_254 -> V_230 . V_226 ;
V_19 = F_114 ( V_189 ) ;
if ( ! V_19 ) {
V_7 = - V_116 ;
goto V_238;
}
V_189 -> V_224 . V_239 = & V_254 -> V_209 ;
V_189 -> V_224 . V_240 = 1 ;
V_189 -> V_224 . V_241 = F_139 ;
V_189 -> V_224 . V_242 = F_142 ;
V_189 -> V_224 . V_243 = F_143 ;
V_19 -> V_189 = V_189 ;
V_19 -> V_52 = V_27 -> V_187 . V_2 ;
V_203 = F_152 ( V_252 ) ;
if ( V_203 )
F_125 ( V_210 , sizeof( V_210 ) ,
V_203 -> V_222 -> V_186 , V_203 -> V_218 ) ;
else
F_153 ( V_210 , sizeof( V_210 ) ,
F_154 ( V_252 ) ) ;
V_19 -> V_6 = F_126 ( & V_219 , V_210 , V_19 ) ;
if ( F_127 ( V_19 -> V_6 ) ) {
V_7 = F_128 ( V_19 -> V_6 ) ;
goto V_220;
}
V_7 = F_147 ( & V_27 -> V_187 , & V_189 -> V_224 ) ;
if ( ! V_7 )
return 0 ;
F_131 ( V_19 -> V_6 ) ;
V_220:
V_19 -> V_6 = NULL ;
F_148 ( V_189 -> V_57 ) ;
V_238:
F_113 ( V_189 -> V_57 ) ;
V_237:
F_149 ( V_27 -> V_187 . V_2 , V_254 ) ;
F_4 ( V_27 -> V_187 . V_2 , L_27 , V_7 ) ;
return V_7 ;
}
static void F_155 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_187 . V_2 ;
struct V_250 * V_258 = V_2 -> V_259 ;
struct V_250 * V_260 = NULL , * V_261 ;
unsigned int V_34 ;
for ( V_34 = 0 ; ; V_34 ++ ) {
V_260 = F_156 ( V_258 , V_260 ) ;
if ( ! V_260 )
break;
V_261 = F_157 ( V_260 ) ;
if ( ! V_261 ) {
F_158 ( V_2 , L_28 ,
F_154 ( V_260 ) ) ;
continue;
}
if ( ! V_34 )
F_151 ( V_27 , V_260 , V_261 -> V_52 ) ;
F_159 ( V_261 ) ;
if ( V_34 ) {
F_4 ( V_2 , L_29 ) ;
break;
}
}
F_159 ( V_260 ) ;
}
static inline void F_155 ( struct V_26 * V_27 ) { }
static int F_105 ( struct V_26 * V_27 ,
struct V_18 * V_19 )
{
struct V_136 * V_137 = F_70 ( V_19 ) ;
struct V_204 * V_205 = & V_137 -> V_206 ;
struct V_1 * V_140 = NULL ;
int V_7 ;
F_160 ( V_19 -> V_57 , L_30 , F_161 ( V_19 -> V_57 ) ) ;
V_7 = F_162 ( & V_19 -> V_148 , 16 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_163 ( V_19 ) ;
if ( V_7 < 0 )
goto V_262;
if ( V_205 -> V_216 ) {
V_7 = F_122 ( V_19 , V_137 ) ;
if ( V_7 < 0 && V_7 != - V_212 )
goto V_127;
} else if ( ! V_205 -> V_263 || ! V_205 -> V_264 ) {
V_7 = - V_67 ;
goto V_127;
} else {
V_7 = F_16 ( V_27 ) ;
if ( V_7 < 0 )
goto V_127;
if ( V_205 -> V_265 )
V_7 = F_164 ( V_205 -> V_265 ) ;
V_7 = V_205 -> V_263 ( V_19 ) ;
if ( V_7 < 0 )
goto V_266;
V_140 = F_69 ( V_19 ) ;
if ( ! V_140 || ! V_140 -> V_168 || ! F_165 ( V_140 ) ||
! F_68 ( V_140 -> V_168 -> V_131 ) ) {
V_205 -> V_264 ( V_19 ) ;
V_7 = - V_25 ;
goto V_267;
}
}
F_17 ( & V_27 -> V_133 ) ;
V_7 = F_117 ( V_19 ) ;
F_18 ( & V_27 -> V_133 ) ;
if ( V_7 < 0 )
goto V_268;
return 0 ;
V_268:
if ( V_205 -> V_216 ) {
F_134 ( V_19 ) ;
} else {
V_205 -> V_264 ( V_19 ) ;
F_75 ( V_140 -> V_168 -> V_131 ) ;
V_267:
V_266:
F_19 ( V_27 ) ;
}
V_127:
if ( V_19 -> V_78 ) {
F_166 ( V_19 -> V_78 ) ;
V_19 -> V_78 = NULL ;
}
V_262:
F_167 ( & V_19 -> V_148 ) ;
return V_7 ;
}
static int F_168 ( struct V_18 * V_19 )
{
struct V_136 * V_137 = F_70 ( V_19 ) ;
struct V_128 * V_78 = V_19 -> V_78 ;
F_167 ( & V_19 -> V_148 ) ;
if ( V_78 ) {
F_169 ( V_78 ) ;
V_19 -> V_78 = NULL ;
}
if ( V_137 -> V_206 . V_216 ) {
F_134 ( V_19 ) ;
} else {
struct V_1 * V_2 = F_69 ( V_19 ) ;
struct V_269 * V_270 = V_2 ? V_2 -> V_168 : NULL ;
if ( V_270 ) {
V_137 -> V_206 . V_264 ( V_19 ) ;
F_75 ( V_270 -> V_131 ) ;
}
}
if ( V_19 -> V_35 )
F_59 ( V_19 ) ;
if ( V_19 -> V_6 ) {
F_131 ( V_19 -> V_6 ) ;
V_19 -> V_6 = NULL ;
}
if ( V_19 -> V_189 )
F_170 ( V_19 -> V_189 -> V_57 ) ;
return 0 ;
}
static int F_171 ( struct V_18 * V_19 ,
struct V_173 * V_271 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
struct V_272 V_273 = {
. V_110 = V_111 ,
. V_176 = V_271 -> V_176 ,
} ;
int V_7 ;
V_7 = F_14 ( V_21 , V_112 , V_175 , NULL , & V_273 ) ;
if ( V_7 )
return V_7 ;
V_271 -> V_179 = V_273 . V_179 ;
return 0 ;
}
static int F_172 ( struct V_18 * V_19 ,
struct V_173 * V_271 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
struct V_272 V_273 = {
. V_110 = V_111 ,
. V_176 = V_271 -> V_176 ,
. V_41 = V_271 -> V_41 ,
. V_179 = V_271 -> V_179 ,
} ;
int V_7 ;
V_7 = F_14 ( V_21 , V_112 , V_181 , NULL , & V_273 ) ;
if ( V_7 )
return V_7 ;
V_271 -> V_179 = V_273 . V_179 ;
return 0 ;
}
static int F_173 ( struct V_18 * V_19 ,
struct V_182 * V_274 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_82 , V_275 , V_274 ) ;
}
static int F_174 ( struct V_18 * V_19 ,
struct V_182 * V_274 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_82 , V_276 , V_274 ) ;
}
static int F_175 ( struct V_18 * V_19 ,
struct V_86 * V_87 )
{
int V_7 ;
struct V_20 * V_21 = F_13 ( V_19 ) ;
const struct V_32 * V_53 ;
struct V_277 V_278 = {
. V_75 = V_87 -> V_75 ,
. V_110 = V_111 ,
} ;
V_53 = F_20 ( V_19 , V_87 -> V_279 ) ;
if ( ! V_53 )
return - V_67 ;
V_278 . V_109 = V_53 -> V_109 ;
V_7 = F_14 ( V_21 , V_112 , V_280 , NULL , & V_278 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_278 . V_281 == V_278 . V_282 &&
V_278 . V_283 == V_278 . V_284 ) {
V_87 -> type = V_285 ;
V_87 -> V_286 . V_59 = V_278 . V_281 ;
V_87 -> V_286 . V_60 = V_278 . V_283 ;
return 0 ;
}
V_87 -> type = V_287 ;
V_87 -> V_288 . V_281 = V_278 . V_281 ;
V_87 -> V_288 . V_282 = V_278 . V_282 ;
V_87 -> V_288 . V_283 = V_278 . V_283 ;
V_87 -> V_288 . V_284 = V_278 . V_284 ;
V_87 -> V_288 . V_289 = 1 ;
V_87 -> V_288 . V_290 = 1 ;
return 0 ;
}
int F_176 ( struct V_26 * V_27 )
{
struct V_26 * V_291 ;
int V_7 ;
if ( ! V_27 || ! V_27 -> V_28 ||
! V_27 -> V_28 -> V_66 ||
! V_27 -> V_28 -> V_120 ||
! V_27 -> V_28 -> V_125 ||
! V_27 -> V_28 -> V_170 ||
( ( ! V_27 -> V_28 -> V_93 ||
! V_27 -> V_28 -> V_95 ) &&
! V_27 -> V_28 -> V_146 ) ||
! V_27 -> V_28 -> V_161 ||
! V_27 -> V_187 . V_2 )
return - V_67 ;
if ( ! V_27 -> V_28 -> V_181 )
V_27 -> V_28 -> V_181 = F_172 ;
if ( ! V_27 -> V_28 -> V_175 )
V_27 -> V_28 -> V_175 = F_171 ;
if ( ! V_27 -> V_28 -> V_184 )
V_27 -> V_28 -> V_184 = F_174 ;
if ( ! V_27 -> V_28 -> V_183 )
V_27 -> V_28 -> V_183 = F_173 ;
if ( ! V_27 -> V_28 -> V_88 )
V_27 -> V_28 -> V_88 = F_175 ;
F_17 ( & V_129 ) ;
F_104 (ix, &hosts, list) {
if ( V_291 -> V_186 == V_27 -> V_186 ) {
V_7 = - V_92 ;
goto V_292;
}
}
V_7 = F_177 ( V_27 -> V_187 . V_2 , & V_27 -> V_187 ) ;
if ( V_7 < 0 )
goto V_292;
F_178 ( & V_27 -> V_293 , & V_294 ) ;
F_18 ( & V_129 ) ;
F_179 ( & V_27 -> V_133 ) ;
F_179 ( & V_27 -> V_30 ) ;
if ( V_27 -> V_187 . V_2 -> V_259 )
F_155 ( V_27 ) ;
else if ( V_27 -> V_249 )
F_150 ( V_27 ) ;
else
F_103 ( V_27 ) ;
return 0 ;
V_292:
F_18 ( & V_129 ) ;
return V_7 ;
}
void F_180 ( struct V_26 * V_27 )
{
struct V_18 * V_19 , * V_295 ;
struct V_188 * V_189 ;
F_181 ( V_296 ) ;
F_17 ( & V_129 ) ;
F_182 ( & V_27 -> V_293 ) ;
F_104 (icd, &devices, list)
if ( V_19 -> V_185 == V_27 -> V_186 && V_19 -> V_189 ) {
F_183 ( V_19 -> V_57 ) ;
F_184 ( & V_19 -> V_189 -> V_293 , & V_296 ) ;
}
F_18 ( & V_129 ) ;
F_104 (sasc, &notifiers, list) {
F_185 ( & V_189 -> V_224 ) ;
F_186 ( & V_189 -> V_57 -> V_2 ) ;
}
F_17 ( & V_129 ) ;
F_187 (icd, tmp, &devices, list)
if ( V_19 -> V_185 == V_27 -> V_186 )
F_168 ( V_19 ) ;
F_18 ( & V_129 ) ;
F_188 ( & V_27 -> V_187 ) ;
}
static int F_189 ( struct V_18 * V_19 )
{
struct V_18 * V_291 ;
int V_297 = - 1 , V_34 ;
F_17 ( & V_129 ) ;
for ( V_34 = 0 ; V_34 < 256 && V_297 < 0 ; V_34 ++ ) {
V_297 = V_34 ;
F_104 (ix, &devices, list) {
if ( V_291 -> V_185 == V_19 -> V_185 && V_291 -> V_298 == V_34 ) {
V_297 = - 1 ;
break;
}
}
}
if ( V_297 < 0 ) {
F_18 ( & V_129 ) ;
return - V_116 ;
}
V_19 -> V_298 = V_297 ;
V_19 -> V_135 = 0 ;
V_19 -> V_299 = NULL ;
V_34 = F_190 ( V_19 -> V_57 ) -> V_300 ;
if ( V_34 < 0 )
V_34 = 0 ;
if ( V_34 >= V_192 ) {
F_18 ( & V_129 ) ;
return - V_92 ;
}
F_110 ( V_34 , V_191 ) ;
F_178 ( & V_19 -> V_293 , & V_301 ) ;
F_18 ( & V_129 ) ;
return 0 ;
}
static int F_163 ( struct V_18 * V_19 )
{
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
struct V_128 * V_78 = F_191 () ;
if ( ! V_78 )
return - V_116 ;
F_90 ( V_78 -> V_80 , V_27 -> V_169 , sizeof( V_78 -> V_80 ) ) ;
V_78 -> V_187 = & V_27 -> V_187 ;
V_78 -> V_302 = & V_303 ;
V_78 -> V_304 = & V_305 ;
V_78 -> V_306 = F_166 ;
V_78 -> V_148 = & V_19 -> V_148 ;
V_78 -> V_307 = & V_27 -> V_133 ;
V_19 -> V_78 = V_78 ;
return 0 ;
}
static int F_121 ( struct V_18 * V_19 )
{
const struct V_308 * type = V_19 -> V_78 -> V_2 . type ;
int V_7 ;
if ( ! V_19 -> V_52 )
return - V_25 ;
F_192 ( V_19 -> V_78 , V_19 ) ;
if ( V_19 -> V_78 -> V_79 == 0 ) {
F_193 ( V_19 -> V_78 , V_309 ) ;
F_193 ( V_19 -> V_78 , V_310 ) ;
F_193 ( V_19 -> V_78 , V_311 ) ;
}
V_7 = F_194 ( V_19 -> V_78 , V_312 , - 1 ) ;
if ( V_7 < 0 ) {
F_4 ( V_19 -> V_57 , L_31 , V_7 ) ;
return V_7 ;
}
V_19 -> V_78 -> V_2 . type = type ;
return 0 ;
}
static int F_195 ( struct V_190 * V_57 )
{
struct V_136 * V_137 = V_57 -> V_2 . V_217 ;
struct V_3 * V_4 = & V_137 -> V_138 ;
struct V_18 * V_19 ;
int V_7 ;
if ( ! V_137 )
return - V_67 ;
V_19 = F_145 ( & V_57 -> V_2 , sizeof( * V_19 ) , V_214 ) ;
if ( ! V_19 )
return - V_116 ;
V_7 = F_11 ( & V_57 -> V_2 , V_4 -> V_11 . V_12 ,
V_4 -> V_11 . V_13 ) ;
if ( V_7 < 0 )
return V_7 ;
V_19 -> V_185 = V_137 -> V_206 . V_231 ;
V_19 -> V_137 = V_137 ;
V_19 -> V_57 = & V_57 -> V_2 ;
F_196 ( V_57 , V_19 ) ;
V_19 -> V_121 = V_313 ;
V_19 -> V_122 = V_314 ;
return F_189 ( V_19 ) ;
}
static int F_197 ( struct V_190 * V_57 )
{
struct V_18 * V_19 = F_116 ( V_57 ) ;
int V_34 ;
if ( ! V_19 )
return - V_67 ;
V_34 = V_57 -> V_300 ;
if ( V_34 < 0 )
V_34 = 0 ;
if ( F_198 ( V_34 , V_191 ) ) {
F_199 ( V_34 , V_191 ) ;
F_182 ( & V_19 -> V_293 ) ;
}
return 0 ;
}

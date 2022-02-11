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
struct V_173 * V_81 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
return V_27 -> V_28 -> V_174 ( V_19 , V_81 ) ;
}
static int F_100 ( struct V_69 * V_69 , void * V_85 ,
struct V_175 * V_81 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
int V_7 ;
V_7 = V_27 -> V_28 -> V_176 ( V_19 , V_81 ) ;
return V_7 ;
}
static int F_101 ( struct V_69 * V_69 , void * V_85 ,
const struct V_175 * V_81 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
const struct V_177 * V_178 = & V_81 -> V_179 ;
struct V_175 V_180 ;
int V_7 ;
if ( V_81 -> type != V_72 )
return - V_67 ;
F_24 ( V_19 -> V_57 , L_24 ,
V_178 -> V_59 , V_178 -> V_60 , V_178 -> V_181 , V_178 -> V_182 ) ;
V_180 . type = V_81 -> type ;
V_7 = V_27 -> V_28 -> V_176 ( V_19 , & V_180 ) ;
if ( V_7 < 0 ) {
F_4 ( V_19 -> V_57 ,
L_25 ) ;
} else if ( ( V_81 -> V_179 . V_59 == V_180 . V_179 . V_59 &&
V_81 -> V_179 . V_60 == V_180 . V_179 . V_60 ) ||
! F_88 ( V_27 , V_19 ) ) {
V_7 = V_27 -> V_28 -> V_183 ( V_19 , V_81 ) ;
} else if ( V_27 -> V_28 -> V_184 ) {
V_7 = V_27 -> V_28 -> V_184 ( V_19 , V_81 ) ;
} else {
F_4 ( V_19 -> V_57 ,
L_26 ) ;
V_7 = - V_92 ;
}
return V_7 ;
}
static int F_102 ( struct V_69 * V_69 , void * V_85 ,
struct V_185 * V_186 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
if ( V_186 -> type != V_72 )
return - V_67 ;
if ( ! V_27 -> V_28 -> V_187 )
return - V_103 ;
return V_27 -> V_28 -> V_187 ( V_19 , V_186 ) ;
}
static int F_103 ( struct V_69 * V_69 , void * V_85 ,
struct V_185 * V_186 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
int V_7 ;
if ( V_186 -> type != V_72 ||
( V_186 -> V_188 != V_189 &&
V_186 -> V_188 != V_190 ) )
return - V_67 ;
if ( V_186 -> V_188 == V_189 ) {
if ( F_88 ( V_27 , V_19 ) &&
( V_19 -> V_121 != V_186 -> V_191 . V_59 ||
V_19 -> V_122 != V_186 -> V_191 . V_60 ) )
return - V_92 ;
if ( V_19 -> V_91 && V_19 -> V_91 != V_69 )
return - V_92 ;
}
if ( ! V_27 -> V_28 -> V_192 )
return - V_103 ;
V_7 = V_27 -> V_28 -> V_192 ( V_19 , V_186 ) ;
if ( ! V_7 &&
V_186 -> V_188 == V_189 ) {
V_19 -> V_121 = V_186 -> V_191 . V_59 ;
V_19 -> V_122 = V_186 -> V_191 . V_60 ;
if ( ! V_19 -> V_91 )
V_19 -> V_91 = V_69 ;
}
return V_7 ;
}
static int F_104 ( struct V_69 * V_69 , void * V_85 ,
struct V_193 * V_81 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
if ( V_27 -> V_28 -> V_194 )
return V_27 -> V_28 -> V_194 ( V_19 , V_81 ) ;
return - V_24 ;
}
static int F_105 ( struct V_69 * V_69 , void * V_85 ,
struct V_193 * V_81 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
if ( V_27 -> V_28 -> V_195 )
return V_27 -> V_28 -> V_195 ( V_19 , V_81 ) ;
return - V_24 ;
}
static void F_106 ( struct V_26 * V_27 )
{
struct V_18 * V_19 ;
F_17 ( & V_129 ) ;
F_107 (icd, &devices, list)
if ( V_19 -> V_196 == V_27 -> V_197 ) {
struct V_136 * V_137 = F_70 ( V_19 ) ;
struct V_3 * V_4 = & V_137 -> V_138 ;
if ( V_4 -> V_139 )
if ( V_19 -> V_140 )
V_4 -> V_139 ( V_19 -> V_140 ) ;
V_19 -> V_52 = V_27 -> V_198 . V_2 ;
F_108 ( V_27 , V_19 ) ;
}
F_18 ( & V_129 ) ;
}
static int F_109 ( struct V_5 * V_6 )
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
static void F_110 ( struct V_5 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_70 ;
struct V_26 * V_27 ;
if ( ! V_19 || ! V_19 -> V_52 )
return;
V_27 = F_23 ( V_19 -> V_52 ) ;
F_19 ( V_27 ) ;
F_75 ( V_27 -> V_28 -> V_131 ) ;
}
static int F_111 ( struct V_136 * V_137 ,
struct V_199 * V_200 )
{
struct V_201 * V_57 ;
int V_7 , V_34 ;
F_17 ( & V_129 ) ;
V_34 = F_112 ( V_202 , V_203 ) ;
if ( V_34 < V_203 )
F_113 ( V_34 , V_202 ) ;
F_18 ( & V_129 ) ;
if ( V_34 >= V_203 )
return - V_116 ;
V_57 = F_114 ( L_27 , V_34 ) ;
if ( ! V_57 )
return - V_116 ;
V_7 = F_115 ( V_57 , V_137 , sizeof( * V_137 ) ) ;
if ( V_7 < 0 ) {
F_116 ( V_57 ) ;
return V_7 ;
}
V_200 -> V_57 = V_57 ;
return 0 ;
}
static struct V_18 * F_117 ( struct V_199 * V_200 )
{
struct V_201 * V_57 = V_200 -> V_57 ;
int V_7 ;
V_7 = F_118 ( V_57 ) ;
if ( V_7 < 0 || ! V_57 -> V_2 . V_168 )
return NULL ;
return F_119 ( V_57 ) ;
}
static int F_120 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
struct V_204 V_56 = {
. V_110 = V_111 ,
} ;
struct V_205 * V_206 = & V_56 . V_164 ;
int V_7 ;
V_21 -> V_207 = F_121 ( V_19 ) ;
F_122 ( V_21 , V_19 ) ;
F_14 ( V_21 , V_82 , V_208 , & V_19 -> V_78 -> V_79 ) ;
V_7 = F_123 ( & V_19 -> V_148 , V_21 -> V_148 , NULL ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_61 ( V_19 ) ;
if ( V_7 < 0 ) {
F_4 ( V_19 -> V_57 , L_13 , V_7 ) ;
return V_7 ;
}
V_7 = F_55 ( V_19 ) ;
if ( V_7 < 0 )
goto V_209;
V_19 -> V_124 = V_210 ;
V_7 = F_124 ( V_19 ) ;
if ( V_7 < 0 )
goto V_211;
if ( ! F_14 ( V_21 , V_112 , V_212 , NULL , & V_56 ) ) {
V_19 -> V_121 = V_206 -> V_59 ;
V_19 -> V_122 = V_206 -> V_60 ;
V_19 -> V_123 = V_206 -> V_123 ;
V_19 -> V_124 = V_206 -> V_124 ;
}
F_62 ( V_19 ) ;
return 0 ;
V_211:
F_59 ( V_19 ) ;
V_209:
F_62 ( V_19 ) ;
return V_7 ;
}
static int F_125 ( struct V_18 * V_19 ,
struct V_136 * V_137 )
{
struct V_3 * V_4 ;
struct V_213 * V_214 ;
struct V_26 * V_27 ;
struct V_215 * V_216 = & V_137 -> V_217 ;
struct V_218 * V_219 ;
struct V_20 * V_220 ;
char V_221 [ V_222 ] ;
int V_7 ;
if ( V_19 -> V_200 ) {
return - V_223 ;
}
V_27 = F_23 ( V_19 -> V_52 ) ;
V_219 = F_126 ( V_216 -> V_224 ) ;
if ( ! V_219 ) {
F_4 ( V_19 -> V_57 , L_28 ,
V_216 -> V_224 ) ;
return - V_25 ;
}
V_4 = F_127 ( & V_137 -> V_138 , sizeof( * V_4 ) , V_225 ) ;
if ( ! V_4 ) {
V_7 = - V_116 ;
goto V_226;
}
V_4 -> V_11 . V_12 = 0 ;
V_4 -> V_11 . V_13 = NULL ;
V_216 -> V_227 -> V_228 = V_4 ;
snprintf ( V_221 , sizeof( V_221 ) , L_29 ,
V_216 -> V_224 , V_216 -> V_227 -> V_229 ) ;
V_19 -> V_6 = F_128 ( & V_230 , V_221 , V_19 ) ;
if ( F_129 ( V_19 -> V_6 ) ) {
V_7 = F_130 ( V_19 -> V_6 ) ;
goto V_231;
}
V_220 = F_131 ( & V_27 -> V_198 , V_219 ,
V_216 -> V_227 , NULL ) ;
if ( ! V_220 ) {
V_7 = - V_25 ;
goto V_232;
}
V_214 = F_132 ( V_220 ) ;
V_19 -> V_140 = & V_214 -> V_2 ;
return 0 ;
V_232:
F_133 ( V_19 -> V_6 ) ;
V_19 -> V_6 = NULL ;
V_231:
F_134 ( V_4 ) ;
V_226:
F_135 ( V_219 ) ;
return V_7 ;
}
static void F_136 ( struct V_18 * V_19 )
{
struct V_213 * V_214 =
F_137 ( F_69 ( V_19 ) ) ;
struct V_218 * V_219 ;
struct V_3 * V_4 ;
V_19 -> V_140 = NULL ;
if ( V_19 -> V_200 )
return;
V_219 = V_214 -> V_233 ;
V_4 = V_214 -> V_2 . V_228 ;
F_138 ( F_139 ( V_214 ) ) ;
F_140 ( V_214 ) ;
F_135 ( V_219 ) ;
F_134 ( V_4 ) ;
F_133 ( V_19 -> V_6 ) ;
V_19 -> V_6 = NULL ;
}
static int F_141 ( struct V_234 * V_235 ,
struct V_20 * V_21 ,
struct V_236 * V_237 )
{
struct V_199 * V_200 = F_142 ( V_235 ,
struct V_199 , V_235 ) ;
struct V_18 * V_19 = F_119 ( V_200 -> V_57 ) ;
if ( V_237 == V_200 -> V_238 && ! F_30 ( V_19 -> V_140 ) ) {
struct V_213 * V_214 = F_132 ( V_21 ) ;
if ( V_214 ) {
struct V_136 * V_137 = F_70 ( V_19 ) ;
struct V_3 * V_4 =
F_143 ( V_214 ) ;
if ( V_4 ) {
memcpy ( & V_137 -> V_138 , V_4 ,
sizeof( V_137 -> V_138 ) ) ;
if ( V_4 -> V_139 )
V_4 -> V_139 ( & V_214 -> V_2 ) ;
}
V_19 -> V_140 = & V_214 -> V_2 ;
}
}
return 0 ;
}
static void F_144 ( struct V_234 * V_235 ,
struct V_20 * V_21 ,
struct V_236 * V_237 )
{
struct V_199 * V_200 = F_142 ( V_235 ,
struct V_199 , V_235 ) ;
struct V_18 * V_19 = F_119 ( V_200 -> V_57 ) ;
if ( V_19 -> V_6 ) {
F_133 ( V_19 -> V_6 ) ;
V_19 -> V_6 = NULL ;
}
}
static int F_145 ( struct V_234 * V_235 )
{
struct V_199 * V_200 = F_142 ( V_235 ,
struct V_199 , V_235 ) ;
struct V_18 * V_19 = F_119 ( V_200 -> V_57 ) ;
if ( F_69 ( V_19 ) ) {
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
int V_7 ;
F_17 ( & V_129 ) ;
V_7 = F_108 ( V_27 , V_19 ) ;
F_18 ( & V_129 ) ;
if ( V_7 < 0 )
return V_7 ;
}
return 0 ;
}
static int F_146 ( struct V_26 * V_27 ,
struct V_236 * * V_237 , unsigned int V_239 )
{
struct V_240 * V_241 ;
struct V_199 * V_200 ;
struct V_18 * V_19 ;
struct V_136 V_137 = { . V_217 . V_242 = V_27 -> V_197 ,} ;
char V_221 [ V_222 ] ;
unsigned int V_34 ;
int V_7 ;
for ( V_34 = 0 ; V_34 < V_239 ; V_34 ++ ) {
V_241 = F_142 ( V_237 [ V_34 ] , struct V_240 , V_237 ) ;
if ( V_241 -> V_243 == V_244 )
break;
}
if ( V_34 >= V_239 || V_237 [ V_34 ] -> V_245 != V_246 ) {
F_4 ( V_27 -> V_198 . V_2 , L_30 ) ;
return - V_25 ;
}
V_200 = F_147 ( V_27 -> V_198 . V_2 , sizeof( * V_200 ) , V_225 ) ;
if ( ! V_200 )
return - V_116 ;
V_137 . V_217 . V_227 = F_148 ( - V_247 ) ;
V_7 = F_111 ( & V_137 , V_200 ) ;
if ( V_7 < 0 )
goto V_248;
V_200 -> V_238 = & V_241 -> V_237 ;
V_19 = F_117 ( V_200 ) ;
if ( ! V_19 ) {
V_7 = - V_116 ;
goto V_249;
}
V_200 -> V_235 . V_250 = V_237 ;
V_200 -> V_235 . V_251 = V_239 ;
V_200 -> V_235 . V_252 = F_141 ;
V_200 -> V_235 . V_253 = F_144 ;
V_200 -> V_235 . V_254 = F_145 ;
V_19 -> V_200 = V_200 ;
V_19 -> V_52 = V_27 -> V_198 . V_2 ;
snprintf ( V_221 , sizeof( V_221 ) , L_29 ,
V_241 -> V_237 . V_255 . V_256 . V_257 , V_241 -> V_237 . V_255 . V_256 . V_258 ) ;
V_19 -> V_6 = F_128 ( & V_230 , V_221 , V_19 ) ;
if ( F_129 ( V_19 -> V_6 ) ) {
V_7 = F_130 ( V_19 -> V_6 ) ;
goto V_231;
}
V_7 = F_149 ( & V_27 -> V_198 , & V_200 -> V_235 ) ;
if ( ! V_7 )
return 0 ;
F_133 ( V_19 -> V_6 ) ;
V_231:
V_19 -> V_6 = NULL ;
F_150 ( V_200 -> V_57 ) ;
V_249:
F_116 ( V_200 -> V_57 ) ;
V_248:
F_151 ( V_27 -> V_198 . V_2 , V_200 ) ;
F_4 ( V_27 -> V_198 . V_2 , L_31 , V_7 ) ;
return V_7 ;
}
static void F_152 ( struct V_26 * V_27 )
{
struct V_236 * * V_237 ;
int V_259 ;
for ( V_259 = 0 , V_237 = V_27 -> V_237 ; V_27 -> V_260 [ V_259 ] ; V_259 ++ ) {
F_146 ( V_27 , V_237 , V_27 -> V_260 [ V_259 ] ) ;
V_237 += V_27 -> V_260 [ V_259 ] ;
}
}
static int F_153 ( struct V_26 * V_27 ,
struct V_261 * V_262 ,
struct V_261 * V_263 )
{
struct V_18 * V_19 ;
struct V_136 V_137 = { . V_217 . V_242 = V_27 -> V_197 ,} ;
struct V_199 * V_200 ;
struct V_264 * V_265 ;
struct V_213 * V_214 ;
char V_221 [ V_222 ] ;
int V_7 ;
V_265 = F_147 ( V_27 -> V_198 . V_2 , sizeof( struct V_264 ) ,
V_225 ) ;
if ( ! V_265 )
return - V_116 ;
V_265 -> V_241 . V_237 . V_255 . V_266 . V_267 = V_263 ;
V_265 -> V_241 . V_237 . V_245 = V_268 ;
V_265 -> V_220 = & V_265 -> V_241 . V_237 ;
V_200 = & V_265 -> V_200 ;
V_137 . V_217 . V_227 = F_148 ( - V_247 ) ;
V_7 = F_111 ( & V_137 , V_200 ) ;
if ( V_7 < 0 )
goto V_248;
V_200 -> V_238 = & V_265 -> V_241 . V_237 ;
V_19 = F_117 ( V_200 ) ;
if ( ! V_19 ) {
V_7 = - V_116 ;
goto V_249;
}
V_200 -> V_235 . V_250 = & V_265 -> V_220 ;
V_200 -> V_235 . V_251 = 1 ;
V_200 -> V_235 . V_252 = F_141 ;
V_200 -> V_235 . V_253 = F_144 ;
V_200 -> V_235 . V_254 = F_145 ;
V_19 -> V_200 = V_200 ;
V_19 -> V_52 = V_27 -> V_198 . V_2 ;
V_214 = F_154 ( V_263 ) ;
if ( V_214 )
snprintf ( V_221 , sizeof( V_221 ) , L_29 ,
V_214 -> V_233 -> V_197 , V_214 -> V_229 ) ;
else
snprintf ( V_221 , sizeof( V_221 ) , L_32 ,
F_155 ( V_263 ) ) ;
V_19 -> V_6 = F_128 ( & V_230 , V_221 , V_19 ) ;
if ( F_129 ( V_19 -> V_6 ) ) {
V_7 = F_130 ( V_19 -> V_6 ) ;
goto V_231;
}
V_7 = F_149 ( & V_27 -> V_198 , & V_200 -> V_235 ) ;
if ( ! V_7 )
return 0 ;
F_133 ( V_19 -> V_6 ) ;
V_231:
V_19 -> V_6 = NULL ;
F_150 ( V_200 -> V_57 ) ;
V_249:
F_116 ( V_200 -> V_57 ) ;
V_248:
F_151 ( V_27 -> V_198 . V_2 , V_265 ) ;
F_4 ( V_27 -> V_198 . V_2 , L_31 , V_7 ) ;
return V_7 ;
}
static void F_156 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_198 . V_2 ;
struct V_261 * V_269 = V_2 -> V_270 ;
struct V_261 * V_271 = NULL , * V_272 ;
unsigned int V_34 ;
for ( V_34 = 0 ; ; V_34 ++ ) {
V_271 = F_157 ( V_269 , V_271 ) ;
if ( ! V_271 )
break;
V_272 = F_158 ( V_271 ) ;
if ( ! V_272 ) {
F_159 ( V_2 , L_33 ,
F_155 ( V_271 ) ) ;
continue;
}
if ( ! V_34 )
F_153 ( V_27 , V_271 , V_272 -> V_52 ) ;
F_160 ( V_272 ) ;
if ( V_34 ) {
F_4 ( V_2 , L_34 ) ;
break;
}
}
F_160 ( V_271 ) ;
}
static inline void F_156 ( struct V_26 * V_27 ) { }
static int F_108 ( struct V_26 * V_27 ,
struct V_18 * V_19 )
{
struct V_136 * V_137 = F_70 ( V_19 ) ;
struct V_215 * V_216 = & V_137 -> V_217 ;
struct V_1 * V_140 = NULL ;
int V_7 ;
F_161 ( V_19 -> V_57 , L_35 , F_162 ( V_19 -> V_57 ) ) ;
V_7 = F_163 ( & V_19 -> V_148 , 16 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_164 ( V_19 ) ;
if ( V_7 < 0 )
goto V_273;
if ( V_216 -> V_227 ) {
V_7 = F_125 ( V_19 , V_137 ) ;
if ( V_7 < 0 && V_7 != - V_223 )
goto V_127;
} else if ( ! V_216 -> V_274 || ! V_216 -> V_275 ) {
V_7 = - V_67 ;
goto V_127;
} else {
V_7 = F_16 ( V_27 ) ;
if ( V_7 < 0 )
goto V_127;
if ( V_216 -> V_276 )
V_7 = F_165 ( V_216 -> V_276 ) ;
V_7 = V_216 -> V_274 ( V_19 ) ;
if ( V_7 < 0 )
goto V_277;
V_140 = F_69 ( V_19 ) ;
if ( ! V_140 || ! V_140 -> V_168 || ! F_166 ( V_140 ) ||
! F_68 ( V_140 -> V_168 -> V_131 ) ) {
V_216 -> V_275 ( V_19 ) ;
V_7 = - V_25 ;
goto V_278;
}
}
F_17 ( & V_27 -> V_133 ) ;
V_7 = F_120 ( V_19 ) ;
F_18 ( & V_27 -> V_133 ) ;
if ( V_7 < 0 )
goto V_279;
return 0 ;
V_279:
if ( V_216 -> V_227 ) {
F_136 ( V_19 ) ;
} else {
V_216 -> V_275 ( V_19 ) ;
F_75 ( V_140 -> V_168 -> V_131 ) ;
V_278:
V_277:
F_19 ( V_27 ) ;
}
V_127:
if ( V_19 -> V_78 ) {
F_167 ( V_19 -> V_78 ) ;
V_19 -> V_78 = NULL ;
}
V_273:
F_168 ( & V_19 -> V_148 ) ;
return V_7 ;
}
static int F_169 ( struct V_18 * V_19 )
{
struct V_136 * V_137 = F_70 ( V_19 ) ;
struct V_128 * V_78 = V_19 -> V_78 ;
F_168 ( & V_19 -> V_148 ) ;
if ( V_78 ) {
F_170 ( V_78 ) ;
V_19 -> V_78 = NULL ;
}
if ( V_137 -> V_217 . V_227 ) {
F_136 ( V_19 ) ;
} else {
struct V_1 * V_2 = F_69 ( V_19 ) ;
struct V_280 * V_281 = V_2 ? V_2 -> V_168 : NULL ;
if ( V_281 ) {
V_137 -> V_217 . V_275 ( V_19 ) ;
F_75 ( V_281 -> V_131 ) ;
}
}
if ( V_19 -> V_35 )
F_59 ( V_19 ) ;
if ( V_19 -> V_6 ) {
F_133 ( V_19 -> V_6 ) ;
V_19 -> V_6 = NULL ;
}
if ( V_19 -> V_200 )
F_171 ( V_19 -> V_200 -> V_57 ) ;
return 0 ;
}
static int F_172 ( struct V_18 * V_19 ,
struct V_173 * V_81 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_82 , V_174 , V_81 ) ;
}
static int F_173 ( struct V_18 * V_19 , struct V_175 * V_81 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_82 , V_282 , V_81 ) ;
}
static int F_174 ( struct V_18 * V_19 , const struct V_175 * V_81 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_82 , V_283 , V_81 ) ;
}
static int F_175 ( struct V_18 * V_19 ,
struct V_193 * V_284 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_82 , V_285 , V_284 ) ;
}
static int F_176 ( struct V_18 * V_19 ,
struct V_193 * V_284 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_82 , V_286 , V_284 ) ;
}
static int F_177 ( struct V_18 * V_19 ,
struct V_86 * V_87 )
{
int V_7 ;
struct V_20 * V_21 = F_13 ( V_19 ) ;
const struct V_32 * V_53 ;
struct V_287 V_288 = {
. V_75 = V_87 -> V_75 ,
. V_110 = V_111 ,
} ;
V_53 = F_20 ( V_19 , V_87 -> V_289 ) ;
if ( ! V_53 )
return - V_67 ;
V_288 . V_109 = V_53 -> V_109 ;
V_7 = F_14 ( V_21 , V_112 , V_290 , NULL , & V_288 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_288 . V_291 == V_288 . V_292 &&
V_288 . V_293 == V_288 . V_294 ) {
V_87 -> type = V_295 ;
V_87 -> V_296 . V_59 = V_288 . V_291 ;
V_87 -> V_296 . V_60 = V_288 . V_293 ;
return 0 ;
}
V_87 -> type = V_297 ;
V_87 -> V_298 . V_291 = V_288 . V_291 ;
V_87 -> V_298 . V_292 = V_288 . V_292 ;
V_87 -> V_298 . V_293 = V_288 . V_293 ;
V_87 -> V_298 . V_294 = V_288 . V_294 ;
V_87 -> V_298 . V_299 = 1 ;
V_87 -> V_298 . V_300 = 1 ;
return 0 ;
}
int F_178 ( struct V_26 * V_27 )
{
struct V_26 * V_301 ;
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
! V_27 -> V_198 . V_2 )
return - V_67 ;
if ( ! V_27 -> V_28 -> V_183 )
V_27 -> V_28 -> V_183 = F_174 ;
if ( ! V_27 -> V_28 -> V_176 )
V_27 -> V_28 -> V_176 = F_173 ;
if ( ! V_27 -> V_28 -> V_174 )
V_27 -> V_28 -> V_174 = F_172 ;
if ( ! V_27 -> V_28 -> V_195 )
V_27 -> V_28 -> V_195 = F_176 ;
if ( ! V_27 -> V_28 -> V_194 )
V_27 -> V_28 -> V_194 = F_175 ;
if ( ! V_27 -> V_28 -> V_88 )
V_27 -> V_28 -> V_88 = F_177 ;
F_17 ( & V_129 ) ;
F_107 (ix, &hosts, list) {
if ( V_301 -> V_197 == V_27 -> V_197 ) {
V_7 = - V_92 ;
goto V_302;
}
}
V_7 = F_179 ( V_27 -> V_198 . V_2 , & V_27 -> V_198 ) ;
if ( V_7 < 0 )
goto V_302;
F_180 ( & V_27 -> V_303 , & V_304 ) ;
F_18 ( & V_129 ) ;
F_181 ( & V_27 -> V_133 ) ;
F_181 ( & V_27 -> V_30 ) ;
if ( V_27 -> V_198 . V_2 -> V_270 )
F_156 ( V_27 ) ;
else if ( V_27 -> V_260 )
F_152 ( V_27 ) ;
else
F_106 ( V_27 ) ;
return 0 ;
V_302:
F_18 ( & V_129 ) ;
return V_7 ;
}
void F_182 ( struct V_26 * V_27 )
{
struct V_18 * V_19 , * V_305 ;
struct V_199 * V_200 ;
F_183 ( V_306 ) ;
F_17 ( & V_129 ) ;
F_184 ( & V_27 -> V_303 ) ;
F_107 (icd, &devices, list)
if ( V_19 -> V_196 == V_27 -> V_197 && V_19 -> V_200 ) {
F_185 ( V_19 -> V_57 ) ;
F_186 ( & V_19 -> V_200 -> V_303 , & V_306 ) ;
}
F_18 ( & V_129 ) ;
F_107 (sasc, &notifiers, list) {
F_187 ( & V_200 -> V_235 ) ;
F_188 ( & V_200 -> V_57 -> V_2 ) ;
}
F_17 ( & V_129 ) ;
F_189 (icd, tmp, &devices, list)
if ( V_19 -> V_196 == V_27 -> V_197 )
F_169 ( V_19 ) ;
F_18 ( & V_129 ) ;
F_190 ( & V_27 -> V_198 ) ;
}
static int F_191 ( struct V_18 * V_19 )
{
struct V_18 * V_301 ;
int V_307 = - 1 , V_34 ;
F_17 ( & V_129 ) ;
for ( V_34 = 0 ; V_34 < 256 && V_307 < 0 ; V_34 ++ ) {
V_307 = V_34 ;
F_107 (ix, &devices, list) {
if ( V_301 -> V_196 == V_19 -> V_196 && V_301 -> V_308 == V_34 ) {
V_307 = - 1 ;
break;
}
}
}
if ( V_307 < 0 ) {
F_18 ( & V_129 ) ;
return - V_116 ;
}
V_19 -> V_308 = V_307 ;
V_19 -> V_135 = 0 ;
V_19 -> V_309 = NULL ;
V_34 = F_192 ( V_19 -> V_57 ) -> V_310 ;
if ( V_34 < 0 )
V_34 = 0 ;
if ( V_34 >= V_203 ) {
F_18 ( & V_129 ) ;
return - V_92 ;
}
F_113 ( V_34 , V_202 ) ;
F_180 ( & V_19 -> V_303 , & V_311 ) ;
F_18 ( & V_129 ) ;
return 0 ;
}
static int F_164 ( struct V_18 * V_19 )
{
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
struct V_128 * V_78 = F_193 () ;
if ( ! V_78 )
return - V_116 ;
F_90 ( V_78 -> V_80 , V_27 -> V_169 , sizeof( V_78 -> V_80 ) ) ;
V_78 -> V_198 = & V_27 -> V_198 ;
V_78 -> V_312 = & V_313 ;
V_78 -> V_314 = & V_315 ;
V_78 -> V_316 = F_167 ;
V_78 -> V_148 = & V_19 -> V_148 ;
V_78 -> V_317 = & V_27 -> V_133 ;
V_19 -> V_78 = V_78 ;
return 0 ;
}
static int F_124 ( struct V_18 * V_19 )
{
const struct V_318 * type = V_19 -> V_78 -> V_2 . type ;
int V_7 ;
if ( ! V_19 -> V_52 )
return - V_25 ;
F_194 ( V_19 -> V_78 , V_19 ) ;
if ( V_19 -> V_78 -> V_79 == 0 ) {
F_195 ( V_19 -> V_78 , V_319 ) ;
F_195 ( V_19 -> V_78 , V_320 ) ;
F_195 ( V_19 -> V_78 , V_321 ) ;
}
V_7 = F_196 ( V_19 -> V_78 , V_322 , - 1 ) ;
if ( V_7 < 0 ) {
F_4 ( V_19 -> V_57 , L_36 , V_7 ) ;
return V_7 ;
}
V_19 -> V_78 -> V_2 . type = type ;
return 0 ;
}
static int F_197 ( struct V_201 * V_57 )
{
struct V_136 * V_137 = V_57 -> V_2 . V_228 ;
struct V_3 * V_4 = & V_137 -> V_138 ;
struct V_18 * V_19 ;
int V_7 ;
if ( ! V_137 )
return - V_67 ;
V_19 = F_147 ( & V_57 -> V_2 , sizeof( * V_19 ) , V_225 ) ;
if ( ! V_19 )
return - V_116 ;
V_7 = F_11 ( & V_57 -> V_2 , V_4 -> V_11 . V_12 ,
V_4 -> V_11 . V_13 ) ;
if ( V_7 < 0 )
return V_7 ;
V_19 -> V_196 = V_137 -> V_217 . V_242 ;
V_19 -> V_137 = V_137 ;
V_19 -> V_57 = & V_57 -> V_2 ;
F_198 ( V_57 , V_19 ) ;
V_19 -> V_121 = V_323 ;
V_19 -> V_122 = V_324 ;
return F_191 ( V_19 ) ;
}
static int F_199 ( struct V_201 * V_57 )
{
struct V_18 * V_19 = F_119 ( V_57 ) ;
int V_34 ;
if ( ! V_19 )
return - V_67 ;
V_34 = V_57 -> V_310 ;
if ( V_34 < 0 )
V_34 = 0 ;
if ( F_200 ( V_34 , V_202 ) ) {
F_201 ( V_34 , V_202 ) ;
F_184 ( & V_19 -> V_303 ) ;
}
return 0 ;
}

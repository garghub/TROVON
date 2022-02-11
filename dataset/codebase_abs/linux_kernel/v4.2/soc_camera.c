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
if ( V_74 -> V_75 != 0 )
return - V_67 ;
V_74 -> type = V_76 ;
strcpy ( V_74 -> V_77 , L_7 ) ;
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
static int F_34 ( struct V_69 * V_69 , void * V_70 , T_1 V_78 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_79 , V_80 , V_78 ) ;
}
static int F_35 ( struct V_69 * V_69 , void * V_70 , T_1 * V_78 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_79 , V_81 , V_78 ) ;
}
static int F_36 ( struct V_69 * V_69 , void * V_82 ,
struct V_83 * V_84 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
return V_27 -> V_28 -> V_85 ( V_19 , V_84 ) ;
}
static int F_37 ( struct V_69 * V_69 , void * V_70 ,
struct V_86 * V_87 )
{
int V_7 ;
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
F_30 ( V_70 != V_69 -> V_71 ) ;
if ( V_19 -> V_88 && V_19 -> V_88 != V_69 )
return - V_89 ;
if ( V_27 -> V_28 -> V_90 ) {
V_7 = F_38 ( & V_19 -> V_91 , V_87 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = V_27 -> V_28 -> V_92 ( V_19 , V_87 ) ;
} else {
V_7 = F_39 ( & V_19 -> V_93 , V_87 ) ;
}
if ( ! V_7 && ! V_19 -> V_88 )
V_19 -> V_88 = V_69 ;
return V_7 ;
}
static int F_40 ( struct V_69 * V_69 , void * V_70 ,
struct V_94 * V_87 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
F_30 ( V_70 != V_69 -> V_71 ) ;
if ( V_27 -> V_28 -> V_90 )
return F_41 ( & V_19 -> V_91 , V_87 ) ;
else
return F_42 ( & V_19 -> V_93 , V_87 ) ;
}
static int F_43 ( struct V_69 * V_69 , void * V_70 ,
struct V_94 * V_87 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
F_30 ( V_70 != V_69 -> V_71 ) ;
if ( V_19 -> V_88 != V_69 )
return - V_89 ;
if ( V_27 -> V_28 -> V_90 )
return F_44 ( & V_19 -> V_91 , V_87 ) ;
else
return F_45 ( & V_19 -> V_93 , V_87 ) ;
}
static int F_46 ( struct V_69 * V_69 , void * V_70 ,
struct V_94 * V_87 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
F_30 ( V_70 != V_69 -> V_71 ) ;
if ( V_19 -> V_88 != V_69 )
return - V_89 ;
if ( V_27 -> V_28 -> V_90 )
return F_47 ( & V_19 -> V_91 , V_87 , V_69 -> V_95 & V_96 ) ;
else
return F_48 ( & V_19 -> V_93 , V_87 , V_69 -> V_95 & V_96 ) ;
}
static int F_49 ( struct V_69 * V_69 , void * V_70 ,
struct V_97 * V_98 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
if ( V_27 -> V_28 -> V_90 )
return - V_67 ;
else
return F_50 ( & V_19 -> V_93 , V_98 ) ;
}
static int F_51 ( struct V_69 * V_69 , void * V_70 ,
struct V_94 * V_99 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
if ( V_27 -> V_28 -> V_90 )
return - V_67 ;
else
return F_52 ( & V_19 -> V_93 , V_99 ) ;
}
static int F_53 ( struct V_69 * V_69 , void * V_70 ,
struct V_100 * V_87 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
if ( V_19 -> V_88 != V_69 )
return - V_89 ;
if ( V_27 -> V_28 -> V_90 )
return - V_67 ;
else
return F_54 ( & V_19 -> V_93 , V_87 ) ;
}
static int F_55 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
unsigned int V_34 , V_101 = 0 , V_102 = 0 ;
int V_7 ;
struct V_103 V_104 = {
. V_105 = V_106 ,
} ;
while ( ! F_14 ( V_21 , V_107 , V_108 , NULL , & V_104 ) ) {
V_102 ++ ;
V_104 . V_75 ++ ;
}
if ( ! V_27 -> V_28 -> V_109 )
V_101 = V_102 ;
else
for ( V_34 = 0 ; V_34 < V_102 ; V_34 ++ ) {
V_7 = V_27 -> V_28 -> V_109 ( V_19 , V_34 , NULL ) ;
if ( V_7 < 0 )
return V_7 ;
V_101 += V_7 ;
}
if ( ! V_101 )
return - V_110 ;
V_19 -> V_36 =
F_56 ( V_101 * sizeof( struct V_32 ) ) ;
if ( ! V_19 -> V_36 )
return - V_111 ;
F_24 ( V_19 -> V_57 , L_8 , V_101 ) ;
V_101 = 0 ;
for ( V_34 = 0 ; V_34 < V_102 ; V_34 ++ )
if ( ! V_27 -> V_28 -> V_109 ) {
V_104 . V_75 = V_34 ;
F_14 ( V_21 , V_107 , V_108 , NULL , & V_104 ) ;
V_19 -> V_36 [ V_101 ] . V_37 =
F_57 ( V_104 . V_104 ) ;
if ( V_19 -> V_36 [ V_101 ] . V_37 )
V_19 -> V_36 [ V_101 ++ ] . V_104 = V_104 . V_104 ;
} else {
V_7 = V_27 -> V_28 -> V_109 ( V_19 , V_34 ,
& V_19 -> V_36 [ V_101 ] ) ;
if ( V_7 < 0 )
goto V_112;
V_101 += V_7 ;
}
V_19 -> V_35 = V_101 ;
V_19 -> V_113 = & V_19 -> V_36 [ 0 ] ;
return 0 ;
V_112:
F_58 ( V_19 -> V_36 ) ;
return V_7 ;
}
static void F_59 ( struct V_18 * V_19 )
{
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
if ( V_27 -> V_28 -> V_114 )
V_27 -> V_28 -> V_114 ( V_19 ) ;
V_19 -> V_113 = NULL ;
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
V_7 = V_27 -> V_28 -> V_115 ( V_19 , V_40 ) ;
if ( V_7 < 0 ) {
return V_7 ;
} else if ( ! V_19 -> V_113 ||
V_19 -> V_113 -> V_37 -> V_33 != V_55 -> V_58 ) {
F_4 ( V_19 -> V_57 ,
L_10 ) ;
return - V_67 ;
}
V_19 -> V_116 = V_55 -> V_59 ;
V_19 -> V_117 = V_55 -> V_60 ;
V_19 -> V_64 = V_55 -> V_64 ;
V_19 -> V_65 = V_55 -> V_65 ;
V_19 -> V_118 = V_55 -> V_118 ;
V_19 -> V_119 = V_55 -> V_119 ;
if ( V_27 -> V_28 -> V_90 )
V_19 -> V_91 . V_119 = V_55 -> V_119 ;
F_24 ( V_19 -> V_57 , L_11 ,
V_19 -> V_116 , V_19 -> V_117 ) ;
return V_27 -> V_28 -> V_120 ( V_19 ) ;
}
static int F_61 ( struct V_18 * V_19 )
{
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
int V_7 ;
if ( V_27 -> V_19 )
return - V_89 ;
if ( ! V_19 -> V_6 ) {
V_7 = F_16 ( V_27 ) ;
if ( V_7 < 0 )
return V_7 ;
}
if ( V_27 -> V_28 -> V_121 ) {
V_7 = V_27 -> V_28 -> V_121 ( V_19 ) ;
if ( V_7 < 0 )
goto V_122;
}
V_27 -> V_19 = V_19 ;
return 0 ;
V_122:
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
struct V_123 * V_124 = F_64 ( V_69 ) ;
struct V_18 * V_19 ;
struct V_26 * V_27 ;
int V_7 ;
if ( F_65 ( & V_125 ) )
return - V_126 ;
if ( ! V_124 || ! F_66 ( V_124 ) ) {
F_18 ( & V_125 ) ;
return - V_25 ;
}
V_19 = F_67 ( V_124 ) ;
V_27 = F_23 ( V_19 -> V_52 ) ;
V_7 = F_68 ( V_27 -> V_28 -> V_127 ) ? 0 : - V_25 ;
F_18 ( & V_125 ) ;
if ( V_7 < 0 ) {
F_4 ( V_19 -> V_57 , L_12 ) ;
return V_7 ;
}
if ( ! F_69 ( V_19 ) ) {
V_7 = - V_25 ;
goto V_128;
}
if ( F_65 ( & V_27 -> V_129 ) ) {
V_7 = - V_126 ;
goto V_130;
}
V_19 -> V_131 ++ ;
if ( V_19 -> V_131 == 1 ) {
struct V_132 * V_133 = F_70 ( V_19 ) ;
struct V_51 V_40 = {
. type = V_72 ,
. V_56 . V_55 = {
. V_59 = V_19 -> V_116 ,
. V_60 = V_19 -> V_117 ,
. V_119 = V_19 -> V_119 ,
. V_118 = V_19 -> V_118 ,
. V_58 =
V_19 -> V_113 -> V_37 -> V_33 ,
} ,
} ;
if ( V_133 -> V_134 . V_135 )
if ( V_19 -> V_136 )
V_133 -> V_134 . V_135 ( V_19 -> V_136 ) ;
V_7 = F_61 ( V_19 ) ;
if ( V_7 < 0 ) {
F_4 ( V_19 -> V_57 , L_13 , V_7 ) ;
goto V_137;
}
V_7 = F_12 ( V_19 ) ;
if ( V_7 < 0 )
goto V_138;
F_71 ( & V_19 -> V_124 -> V_2 ) ;
V_7 = F_72 ( & V_19 -> V_124 -> V_2 ) ;
if ( V_7 < 0 && V_7 != - V_139 )
goto V_140;
V_7 = F_60 ( V_19 , & V_40 ) ;
if ( V_7 < 0 )
goto V_141;
if ( V_27 -> V_28 -> V_90 ) {
V_27 -> V_28 -> V_90 ( & V_19 -> V_91 , V_19 ) ;
} else {
V_7 = V_27 -> V_28 -> V_142 ( & V_19 -> V_93 , V_19 ) ;
if ( V_7 < 0 )
goto V_143;
}
F_73 ( & V_19 -> V_144 ) ;
}
F_18 ( & V_27 -> V_129 ) ;
V_69 -> V_71 = V_19 ;
F_24 ( V_19 -> V_57 , L_14 ) ;
return 0 ;
V_143:
V_141:
F_74 ( & V_19 -> V_124 -> V_2 ) ;
V_140:
F_15 ( V_19 ) ;
V_138:
F_62 ( V_19 ) ;
V_137:
V_19 -> V_131 -- ;
F_18 ( & V_27 -> V_129 ) ;
V_130:
V_128:
F_75 ( V_27 -> V_28 -> V_127 ) ;
return V_7 ;
}
static int F_76 ( struct V_69 * V_69 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
F_17 ( & V_27 -> V_129 ) ;
V_19 -> V_131 -- ;
if ( ! V_19 -> V_131 ) {
F_77 ( & V_19 -> V_124 -> V_2 ) ;
F_74 ( & V_19 -> V_124 -> V_2 ) ;
if ( V_27 -> V_28 -> V_142 )
F_78 ( & V_19 -> V_93 ) ;
F_15 ( V_19 ) ;
F_62 ( V_19 ) ;
}
if ( V_19 -> V_88 == V_69 )
V_19 -> V_88 = NULL ;
F_18 ( & V_27 -> V_129 ) ;
F_75 ( V_27 -> V_28 -> V_127 ) ;
F_24 ( V_19 -> V_57 , L_15 ) ;
return 0 ;
}
static T_2 F_79 ( struct V_69 * V_69 , char T_3 * V_145 ,
T_4 V_146 , T_5 * V_147 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
F_24 ( V_19 -> V_57 , L_16 , V_145 ) ;
if ( V_27 -> V_28 -> V_142 && V_19 -> V_93 . V_148 & V_149 )
return F_80 ( & V_19 -> V_93 , V_145 , V_146 , V_147 ,
V_69 -> V_95 & V_96 ) ;
F_4 ( V_19 -> V_57 , L_17 ) ;
return - V_67 ;
}
static int F_81 ( struct V_69 * V_69 , struct V_150 * V_151 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
int V_17 ;
F_24 ( V_19 -> V_57 , L_18 , ( unsigned long ) V_151 ) ;
if ( V_19 -> V_88 != V_69 )
return - V_89 ;
if ( F_65 ( & V_27 -> V_129 ) )
return - V_126 ;
if ( V_27 -> V_28 -> V_90 )
V_17 = F_82 ( & V_19 -> V_91 , V_151 ) ;
else
V_17 = F_83 ( & V_19 -> V_93 , V_151 ) ;
F_18 ( & V_27 -> V_129 ) ;
F_24 ( V_19 -> V_57 , L_19 ,
( unsigned long ) V_151 -> V_152 ,
( unsigned long ) V_151 -> V_153 - ( unsigned long ) V_151 -> V_152 ,
V_17 ) ;
return V_17 ;
}
static unsigned int F_84 ( struct V_69 * V_69 , T_6 * V_154 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
unsigned V_155 = V_156 ;
if ( V_19 -> V_88 != V_69 )
return V_156 ;
F_17 ( & V_27 -> V_129 ) ;
if ( V_27 -> V_28 -> V_90 && F_85 ( & V_19 -> V_91 . V_157 ) )
F_4 ( V_19 -> V_57 , L_20 ) ;
else
V_155 = V_27 -> V_28 -> V_158 ( V_69 , V_154 ) ;
F_18 ( & V_27 -> V_129 ) ;
return V_155 ;
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
if ( V_19 -> V_88 && V_19 -> V_88 != V_69 )
return - V_89 ;
if ( F_88 ( F_23 ( V_19 -> V_52 ) , V_19 ) ) {
F_4 ( V_19 -> V_57 , L_22 ) ;
return - V_89 ;
}
V_7 = F_60 ( V_19 , V_40 ) ;
if ( ! V_7 && ! V_19 -> V_88 )
V_19 -> V_88 = V_69 ;
return V_7 ;
}
static int F_89 ( struct V_69 * V_69 , void * V_70 ,
struct V_159 * V_40 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
const struct V_160 * V_161 ;
F_30 ( V_70 != V_69 -> V_71 ) ;
if ( V_40 -> V_75 >= V_19 -> V_35 )
return - V_67 ;
V_161 = V_19 -> V_36 [ V_40 -> V_75 ] . V_37 ;
if ( V_161 -> V_77 )
F_90 ( V_40 -> V_162 , V_161 -> V_77 , sizeof( V_40 -> V_162 ) ) ;
V_40 -> V_58 = V_161 -> V_33 ;
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
V_55 -> V_59 = V_19 -> V_116 ;
V_55 -> V_60 = V_19 -> V_117 ;
V_55 -> V_64 = V_19 -> V_64 ;
V_55 -> V_65 = V_19 -> V_65 ;
V_55 -> V_119 = V_19 -> V_119 ;
V_55 -> V_58 = V_19 -> V_113 -> V_37 -> V_33 ;
V_55 -> V_118 = V_19 -> V_118 ;
F_24 ( V_19 -> V_57 , L_23 ,
V_19 -> V_113 -> V_37 -> V_33 ) ;
return 0 ;
}
static int F_92 ( struct V_69 * V_69 , void * V_70 ,
struct V_163 * V_164 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
F_30 ( V_70 != V_69 -> V_71 ) ;
F_90 ( V_164 -> V_165 , V_27 -> V_166 , sizeof( V_164 -> V_165 ) ) ;
return V_27 -> V_28 -> V_167 ( V_27 , V_164 ) ;
}
static int F_93 ( struct V_69 * V_69 , void * V_70 ,
enum V_168 V_34 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
struct V_20 * V_21 = F_13 ( V_19 ) ;
int V_7 ;
F_30 ( V_70 != V_69 -> V_71 ) ;
if ( V_34 != V_72 )
return - V_67 ;
if ( V_19 -> V_88 != V_69 )
return - V_89 ;
if ( V_27 -> V_28 -> V_90 )
V_7 = F_94 ( & V_19 -> V_91 ) ;
else
V_7 = F_95 ( & V_19 -> V_93 , V_34 ) ;
if ( ! V_7 )
F_14 ( V_21 , V_79 , V_169 , 1 ) ;
return V_7 ;
}
static int F_96 ( struct V_69 * V_69 , void * V_70 ,
enum V_168 V_34 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_20 * V_21 = F_13 ( V_19 ) ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
F_30 ( V_70 != V_69 -> V_71 ) ;
if ( V_34 != V_72 )
return - V_67 ;
if ( V_19 -> V_88 != V_69 )
return - V_89 ;
if ( V_27 -> V_28 -> V_90 )
F_97 ( & V_19 -> V_91 ) ;
else
F_98 ( & V_19 -> V_93 , V_34 ) ;
F_14 ( V_21 , V_79 , V_169 , 0 ) ;
return 0 ;
}
static int F_99 ( struct V_69 * V_69 , void * V_82 ,
struct V_170 * V_78 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
return V_27 -> V_28 -> V_171 ( V_19 , V_78 ) ;
}
static int F_100 ( struct V_69 * V_69 , void * V_82 ,
struct V_172 * V_78 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
int V_7 ;
V_7 = V_27 -> V_28 -> V_173 ( V_19 , V_78 ) ;
return V_7 ;
}
static int F_101 ( struct V_69 * V_69 , void * V_82 ,
const struct V_172 * V_78 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
const struct V_174 * V_175 = & V_78 -> V_176 ;
struct V_172 V_177 ;
int V_7 ;
if ( V_78 -> type != V_72 )
return - V_67 ;
F_24 ( V_19 -> V_57 , L_24 ,
V_175 -> V_59 , V_175 -> V_60 , V_175 -> V_178 , V_175 -> V_179 ) ;
V_177 . type = V_78 -> type ;
V_7 = V_27 -> V_28 -> V_173 ( V_19 , & V_177 ) ;
if ( V_7 < 0 ) {
F_4 ( V_19 -> V_57 ,
L_25 ) ;
} else if ( ( V_78 -> V_176 . V_59 == V_177 . V_176 . V_59 &&
V_78 -> V_176 . V_60 == V_177 . V_176 . V_60 ) ||
! F_88 ( V_27 , V_19 ) ) {
V_7 = V_27 -> V_28 -> V_180 ( V_19 , V_78 ) ;
} else if ( V_27 -> V_28 -> V_181 ) {
V_7 = V_27 -> V_28 -> V_181 ( V_19 , V_78 ) ;
} else {
F_4 ( V_19 -> V_57 ,
L_26 ) ;
V_7 = - V_89 ;
}
return V_7 ;
}
static int F_102 ( struct V_69 * V_69 , void * V_82 ,
struct V_182 * V_183 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
if ( V_183 -> type != V_72 )
return - V_67 ;
if ( ! V_27 -> V_28 -> V_184 )
return - V_185 ;
return V_27 -> V_28 -> V_184 ( V_19 , V_183 ) ;
}
static int F_103 ( struct V_69 * V_69 , void * V_82 ,
struct V_182 * V_183 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
int V_7 ;
if ( V_183 -> type != V_72 ||
( V_183 -> V_186 != V_187 &&
V_183 -> V_186 != V_188 ) )
return - V_67 ;
if ( V_183 -> V_186 == V_187 ) {
if ( F_88 ( V_27 , V_19 ) &&
( V_19 -> V_116 != V_183 -> V_189 . V_59 ||
V_19 -> V_117 != V_183 -> V_189 . V_60 ) )
return - V_89 ;
if ( V_19 -> V_88 && V_19 -> V_88 != V_69 )
return - V_89 ;
}
if ( ! V_27 -> V_28 -> V_190 )
return - V_185 ;
V_7 = V_27 -> V_28 -> V_190 ( V_19 , V_183 ) ;
if ( ! V_7 &&
V_183 -> V_186 == V_187 ) {
V_19 -> V_116 = V_183 -> V_189 . V_59 ;
V_19 -> V_117 = V_183 -> V_189 . V_60 ;
if ( ! V_19 -> V_88 )
V_19 -> V_88 = V_69 ;
}
return V_7 ;
}
static int F_104 ( struct V_69 * V_69 , void * V_82 ,
struct V_191 * V_78 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
if ( V_27 -> V_28 -> V_192 )
return V_27 -> V_28 -> V_192 ( V_19 , V_78 ) ;
return - V_24 ;
}
static int F_105 ( struct V_69 * V_69 , void * V_82 ,
struct V_191 * V_78 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
if ( V_27 -> V_28 -> V_193 )
return V_27 -> V_28 -> V_193 ( V_19 , V_78 ) ;
return - V_24 ;
}
static void F_106 ( struct V_26 * V_27 )
{
struct V_18 * V_19 ;
F_17 ( & V_125 ) ;
F_107 (icd, &devices, list)
if ( V_19 -> V_194 == V_27 -> V_195 ) {
struct V_132 * V_133 = F_70 ( V_19 ) ;
struct V_3 * V_4 = & V_133 -> V_134 ;
if ( V_4 -> V_135 )
if ( V_19 -> V_136 )
V_4 -> V_135 ( V_19 -> V_136 ) ;
V_19 -> V_52 = V_27 -> V_196 . V_2 ;
F_108 ( V_27 , V_19 ) ;
}
F_18 ( & V_125 ) ;
}
static int F_109 ( struct V_5 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_70 ;
struct V_26 * V_27 ;
if ( ! V_19 || ! V_19 -> V_52 )
return - V_25 ;
V_27 = F_23 ( V_19 -> V_52 ) ;
if ( ! F_68 ( V_27 -> V_28 -> V_127 ) )
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
F_75 ( V_27 -> V_28 -> V_127 ) ;
}
static int F_111 ( struct V_132 * V_133 ,
struct V_197 * V_198 )
{
struct V_199 * V_57 ;
int V_7 , V_34 ;
F_17 ( & V_125 ) ;
V_34 = F_112 ( V_200 , V_201 ) ;
if ( V_34 < V_201 )
F_113 ( V_34 , V_200 ) ;
F_18 ( & V_125 ) ;
if ( V_34 >= V_201 )
return - V_111 ;
V_57 = F_114 ( L_27 , V_34 ) ;
if ( ! V_57 )
return - V_111 ;
V_7 = F_115 ( V_57 , V_133 , sizeof( * V_133 ) ) ;
if ( V_7 < 0 ) {
F_116 ( V_57 ) ;
return V_7 ;
}
V_198 -> V_57 = V_57 ;
return 0 ;
}
static struct V_18 * F_117 ( struct V_197 * V_198 )
{
struct V_199 * V_57 = V_198 -> V_57 ;
int V_7 ;
V_7 = F_118 ( V_57 ) ;
if ( V_7 < 0 || ! V_57 -> V_2 . V_165 )
return NULL ;
return F_119 ( V_57 ) ;
}
static int F_120 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
struct V_202 V_56 = {
. V_105 = V_106 ,
} ;
struct V_203 * V_204 = & V_56 . V_161 ;
int V_7 ;
V_21 -> V_205 = F_121 ( V_19 ) ;
F_122 ( V_21 , V_19 ) ;
F_14 ( V_21 , V_79 , V_206 , & V_19 -> V_124 -> V_207 ) ;
V_7 = F_123 ( & V_19 -> V_144 , V_21 -> V_144 , NULL ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_61 ( V_19 ) ;
if ( V_7 < 0 ) {
F_4 ( V_19 -> V_57 , L_13 , V_7 ) ;
return V_7 ;
}
V_7 = F_55 ( V_19 ) ;
if ( V_7 < 0 )
goto V_208;
V_19 -> V_119 = V_209 ;
V_7 = F_124 ( V_19 ) ;
if ( V_7 < 0 )
goto V_210;
if ( ! F_14 ( V_21 , V_107 , V_211 , NULL , & V_56 ) ) {
V_19 -> V_116 = V_204 -> V_59 ;
V_19 -> V_117 = V_204 -> V_60 ;
V_19 -> V_118 = V_204 -> V_118 ;
V_19 -> V_119 = V_204 -> V_119 ;
}
F_62 ( V_19 ) ;
return 0 ;
V_210:
F_59 ( V_19 ) ;
V_208:
F_62 ( V_19 ) ;
return V_7 ;
}
static int F_125 ( struct V_18 * V_19 ,
struct V_132 * V_133 )
{
struct V_3 * V_4 ;
struct V_212 * V_213 ;
struct V_26 * V_27 ;
struct V_214 * V_215 = & V_133 -> V_216 ;
struct V_217 * V_218 ;
struct V_20 * V_219 ;
char V_220 [ V_221 ] ;
int V_7 ;
if ( V_19 -> V_198 ) {
return - V_222 ;
}
V_27 = F_23 ( V_19 -> V_52 ) ;
V_218 = F_126 ( V_215 -> V_223 ) ;
if ( ! V_218 ) {
F_4 ( V_19 -> V_57 , L_28 ,
V_215 -> V_223 ) ;
return - V_25 ;
}
V_4 = F_127 ( & V_133 -> V_134 , sizeof( * V_4 ) , V_224 ) ;
if ( ! V_4 ) {
V_7 = - V_111 ;
goto V_225;
}
V_4 -> V_11 . V_12 = 0 ;
V_4 -> V_11 . V_13 = NULL ;
V_215 -> V_226 -> V_227 = V_4 ;
snprintf ( V_220 , sizeof( V_220 ) , L_29 ,
V_215 -> V_223 , V_215 -> V_226 -> V_228 ) ;
V_19 -> V_6 = F_128 ( & V_229 , V_220 , V_19 ) ;
if ( F_129 ( V_19 -> V_6 ) ) {
V_7 = F_130 ( V_19 -> V_6 ) ;
goto V_230;
}
V_219 = F_131 ( & V_27 -> V_196 , V_218 ,
V_215 -> V_226 , NULL ) ;
if ( ! V_219 ) {
V_7 = - V_25 ;
goto V_231;
}
V_213 = F_132 ( V_219 ) ;
V_19 -> V_136 = & V_213 -> V_2 ;
return 0 ;
V_231:
F_133 ( V_19 -> V_6 ) ;
V_19 -> V_6 = NULL ;
V_230:
F_134 ( V_4 ) ;
V_225:
F_135 ( V_218 ) ;
return V_7 ;
}
static void F_136 ( struct V_18 * V_19 )
{
struct V_212 * V_213 =
F_137 ( F_69 ( V_19 ) ) ;
struct V_217 * V_218 ;
struct V_3 * V_4 ;
V_19 -> V_136 = NULL ;
if ( V_19 -> V_198 )
return;
V_218 = V_213 -> V_232 ;
V_4 = V_213 -> V_2 . V_227 ;
F_138 ( F_139 ( V_213 ) ) ;
F_140 ( V_213 ) ;
F_135 ( V_218 ) ;
F_134 ( V_4 ) ;
F_133 ( V_19 -> V_6 ) ;
V_19 -> V_6 = NULL ;
}
static int F_141 ( struct V_233 * V_234 ,
struct V_20 * V_21 ,
struct V_235 * V_236 )
{
struct V_197 * V_198 = F_142 ( V_234 ,
struct V_197 , V_234 ) ;
struct V_18 * V_19 = F_119 ( V_198 -> V_57 ) ;
if ( V_236 == V_198 -> V_237 && ! F_30 ( V_19 -> V_136 ) ) {
struct V_212 * V_213 = F_132 ( V_21 ) ;
if ( V_213 ) {
struct V_132 * V_133 = F_70 ( V_19 ) ;
struct V_3 * V_4 =
F_143 ( V_213 ) ;
if ( V_4 ) {
memcpy ( & V_133 -> V_134 , V_4 ,
sizeof( V_133 -> V_134 ) ) ;
if ( V_4 -> V_135 )
V_4 -> V_135 ( & V_213 -> V_2 ) ;
}
V_19 -> V_136 = & V_213 -> V_2 ;
}
}
return 0 ;
}
static void F_144 ( struct V_233 * V_234 ,
struct V_20 * V_21 ,
struct V_235 * V_236 )
{
struct V_197 * V_198 = F_142 ( V_234 ,
struct V_197 , V_234 ) ;
struct V_18 * V_19 = F_119 ( V_198 -> V_57 ) ;
if ( V_19 -> V_6 ) {
F_133 ( V_19 -> V_6 ) ;
V_19 -> V_6 = NULL ;
}
}
static int F_145 ( struct V_233 * V_234 )
{
struct V_197 * V_198 = F_142 ( V_234 ,
struct V_197 , V_234 ) ;
struct V_18 * V_19 = F_119 ( V_198 -> V_57 ) ;
if ( F_69 ( V_19 ) ) {
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
int V_7 ;
F_17 ( & V_125 ) ;
V_7 = F_108 ( V_27 , V_19 ) ;
F_18 ( & V_125 ) ;
if ( V_7 < 0 )
return V_7 ;
}
return 0 ;
}
static int F_146 ( struct V_26 * V_27 ,
struct V_235 * * V_236 , unsigned int V_238 )
{
struct V_239 * V_240 ;
struct V_197 * V_198 ;
struct V_18 * V_19 ;
struct V_132 V_133 = { . V_216 . V_241 = V_27 -> V_195 ,} ;
char V_220 [ V_221 ] ;
unsigned int V_34 ;
int V_7 ;
for ( V_34 = 0 ; V_34 < V_238 ; V_34 ++ ) {
V_240 = F_142 ( V_236 [ V_34 ] , struct V_239 , V_236 ) ;
if ( V_240 -> V_242 == V_243 )
break;
}
if ( V_34 >= V_238 || V_236 [ V_34 ] -> V_244 != V_245 ) {
F_4 ( V_27 -> V_196 . V_2 , L_30 ) ;
return - V_25 ;
}
V_198 = F_147 ( V_27 -> V_196 . V_2 , sizeof( * V_198 ) , V_224 ) ;
if ( ! V_198 )
return - V_111 ;
V_133 . V_216 . V_226 = F_148 ( - V_246 ) ;
V_7 = F_111 ( & V_133 , V_198 ) ;
if ( V_7 < 0 )
goto V_247;
V_198 -> V_237 = & V_240 -> V_236 ;
V_19 = F_117 ( V_198 ) ;
if ( ! V_19 ) {
V_7 = - V_111 ;
goto V_248;
}
V_198 -> V_234 . V_249 = V_236 ;
V_198 -> V_234 . V_250 = V_238 ;
V_198 -> V_234 . V_251 = F_141 ;
V_198 -> V_234 . V_252 = F_144 ;
V_198 -> V_234 . V_253 = F_145 ;
V_19 -> V_198 = V_198 ;
V_19 -> V_52 = V_27 -> V_196 . V_2 ;
snprintf ( V_220 , sizeof( V_220 ) , L_29 ,
V_240 -> V_236 . V_254 . V_255 . V_256 , V_240 -> V_236 . V_254 . V_255 . V_257 ) ;
V_19 -> V_6 = F_128 ( & V_229 , V_220 , V_19 ) ;
if ( F_129 ( V_19 -> V_6 ) ) {
V_7 = F_130 ( V_19 -> V_6 ) ;
goto V_230;
}
V_7 = F_149 ( & V_27 -> V_196 , & V_198 -> V_234 ) ;
if ( ! V_7 )
return 0 ;
F_133 ( V_19 -> V_6 ) ;
V_230:
V_19 -> V_6 = NULL ;
F_150 ( V_198 -> V_57 ) ;
V_248:
F_116 ( V_198 -> V_57 ) ;
V_247:
F_151 ( V_27 -> V_196 . V_2 , V_198 ) ;
F_4 ( V_27 -> V_196 . V_2 , L_31 , V_7 ) ;
return V_7 ;
}
static void F_152 ( struct V_26 * V_27 )
{
struct V_235 * * V_236 ;
int V_258 ;
for ( V_258 = 0 , V_236 = V_27 -> V_236 ; V_27 -> V_259 [ V_258 ] ; V_258 ++ ) {
F_146 ( V_27 , V_236 , V_27 -> V_259 [ V_258 ] ) ;
V_236 += V_27 -> V_259 [ V_258 ] ;
}
}
static int F_153 ( struct V_26 * V_27 ,
struct V_260 * V_261 ,
struct V_260 * V_262 )
{
struct V_18 * V_19 ;
struct V_132 V_133 = { . V_216 . V_241 = V_27 -> V_195 ,} ;
struct V_197 * V_198 ;
struct V_263 * V_264 ;
struct V_212 * V_213 ;
char V_220 [ V_221 ] ;
int V_7 ;
V_264 = F_147 ( V_27 -> V_196 . V_2 , sizeof( struct V_263 ) ,
V_224 ) ;
if ( ! V_264 )
return - V_111 ;
V_264 -> V_240 . V_236 . V_254 . V_265 . V_266 = V_262 ;
V_264 -> V_240 . V_236 . V_244 = V_267 ;
V_264 -> V_219 = & V_264 -> V_240 . V_236 ;
V_198 = & V_264 -> V_198 ;
V_133 . V_216 . V_226 = F_148 ( - V_246 ) ;
V_7 = F_111 ( & V_133 , V_198 ) ;
if ( V_7 < 0 )
goto V_247;
V_198 -> V_237 = & V_264 -> V_240 . V_236 ;
V_19 = F_117 ( V_198 ) ;
if ( ! V_19 ) {
V_7 = - V_111 ;
goto V_248;
}
V_198 -> V_234 . V_249 = & V_264 -> V_219 ;
V_198 -> V_234 . V_250 = 1 ;
V_198 -> V_234 . V_251 = F_141 ;
V_198 -> V_234 . V_252 = F_144 ;
V_198 -> V_234 . V_253 = F_145 ;
V_19 -> V_198 = V_198 ;
V_19 -> V_52 = V_27 -> V_196 . V_2 ;
V_213 = F_154 ( V_262 ) ;
if ( V_213 )
snprintf ( V_220 , sizeof( V_220 ) , L_29 ,
V_213 -> V_232 -> V_195 , V_213 -> V_228 ) ;
else
snprintf ( V_220 , sizeof( V_220 ) , L_32 ,
F_155 ( V_262 ) ) ;
V_19 -> V_6 = F_128 ( & V_229 , V_220 , V_19 ) ;
if ( F_129 ( V_19 -> V_6 ) ) {
V_7 = F_130 ( V_19 -> V_6 ) ;
goto V_230;
}
V_7 = F_149 ( & V_27 -> V_196 , & V_198 -> V_234 ) ;
if ( ! V_7 )
return 0 ;
F_133 ( V_19 -> V_6 ) ;
V_230:
V_19 -> V_6 = NULL ;
F_150 ( V_198 -> V_57 ) ;
V_248:
F_116 ( V_198 -> V_57 ) ;
V_247:
F_151 ( V_27 -> V_196 . V_2 , V_264 ) ;
F_4 ( V_27 -> V_196 . V_2 , L_31 , V_7 ) ;
return V_7 ;
}
static void F_156 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_196 . V_2 ;
struct V_260 * V_268 = V_2 -> V_269 ;
struct V_260 * V_270 = NULL , * V_271 ;
unsigned int V_34 ;
for ( V_34 = 0 ; ; V_34 ++ ) {
V_270 = F_157 ( V_268 , V_270 ) ;
if ( ! V_270 )
break;
V_271 = F_158 ( V_270 ) ;
if ( ! V_271 ) {
F_159 ( V_2 , L_33 ,
F_155 ( V_270 ) ) ;
continue;
}
if ( ! V_34 )
F_153 ( V_27 , V_270 , V_271 -> V_52 ) ;
F_160 ( V_271 ) ;
if ( V_34 ) {
F_4 ( V_2 , L_34 ) ;
break;
}
}
F_160 ( V_270 ) ;
}
static inline void F_156 ( struct V_26 * V_27 ) { }
static int F_108 ( struct V_26 * V_27 ,
struct V_18 * V_19 )
{
struct V_132 * V_133 = F_70 ( V_19 ) ;
struct V_214 * V_215 = & V_133 -> V_216 ;
struct V_1 * V_136 = NULL ;
int V_7 ;
F_161 ( V_19 -> V_57 , L_35 , F_162 ( V_19 -> V_57 ) ) ;
V_7 = F_163 ( & V_19 -> V_144 , 16 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_164 ( V_19 ) ;
if ( V_7 < 0 )
goto V_272;
if ( V_215 -> V_226 ) {
V_7 = F_125 ( V_19 , V_133 ) ;
if ( V_7 < 0 && V_7 != - V_222 )
goto V_122;
} else if ( ! V_215 -> V_273 || ! V_215 -> V_274 ) {
V_7 = - V_67 ;
goto V_122;
} else {
V_7 = F_16 ( V_27 ) ;
if ( V_7 < 0 )
goto V_122;
if ( V_215 -> V_275 )
V_7 = F_165 ( V_215 -> V_275 ) ;
V_7 = V_215 -> V_273 ( V_19 ) ;
if ( V_7 < 0 )
goto V_276;
V_136 = F_69 ( V_19 ) ;
if ( ! V_136 || ! V_136 -> V_165 || ! F_166 ( V_136 ) ||
! F_68 ( V_136 -> V_165 -> V_127 ) ) {
V_215 -> V_274 ( V_19 ) ;
V_7 = - V_25 ;
goto V_277;
}
}
F_17 ( & V_27 -> V_129 ) ;
V_7 = F_120 ( V_19 ) ;
F_18 ( & V_27 -> V_129 ) ;
if ( V_7 < 0 )
goto V_278;
return 0 ;
V_278:
if ( V_215 -> V_226 ) {
F_136 ( V_19 ) ;
} else {
V_215 -> V_274 ( V_19 ) ;
F_75 ( V_136 -> V_165 -> V_127 ) ;
V_277:
V_276:
F_19 ( V_27 ) ;
}
V_122:
if ( V_19 -> V_124 ) {
F_167 ( V_19 -> V_124 ) ;
V_19 -> V_124 = NULL ;
}
V_272:
F_168 ( & V_19 -> V_144 ) ;
return V_7 ;
}
static int F_169 ( struct V_18 * V_19 )
{
struct V_132 * V_133 = F_70 ( V_19 ) ;
struct V_123 * V_124 = V_19 -> V_124 ;
F_168 ( & V_19 -> V_144 ) ;
if ( V_124 ) {
F_170 ( V_124 ) ;
V_19 -> V_124 = NULL ;
}
if ( V_133 -> V_216 . V_226 ) {
F_136 ( V_19 ) ;
} else {
struct V_1 * V_2 = F_69 ( V_19 ) ;
struct V_279 * V_280 = V_2 ? V_2 -> V_165 : NULL ;
if ( V_280 ) {
V_133 -> V_216 . V_274 ( V_19 ) ;
F_75 ( V_280 -> V_127 ) ;
}
}
if ( V_19 -> V_35 )
F_59 ( V_19 ) ;
if ( V_19 -> V_6 ) {
F_133 ( V_19 -> V_6 ) ;
V_19 -> V_6 = NULL ;
}
if ( V_19 -> V_198 )
F_171 ( V_19 -> V_198 -> V_57 ) ;
return 0 ;
}
static int F_172 ( struct V_18 * V_19 ,
struct V_170 * V_78 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_79 , V_171 , V_78 ) ;
}
static int F_173 ( struct V_18 * V_19 , struct V_172 * V_78 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_79 , V_281 , V_78 ) ;
}
static int F_174 ( struct V_18 * V_19 , const struct V_172 * V_78 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_79 , V_282 , V_78 ) ;
}
static int F_175 ( struct V_18 * V_19 ,
struct V_191 * V_283 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_79 , V_284 , V_283 ) ;
}
static int F_176 ( struct V_18 * V_19 ,
struct V_191 * V_283 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_79 , V_285 , V_283 ) ;
}
static int F_177 ( struct V_18 * V_19 ,
struct V_83 * V_84 )
{
int V_7 ;
struct V_20 * V_21 = F_13 ( V_19 ) ;
const struct V_32 * V_53 ;
struct V_286 V_287 = {
. V_75 = V_84 -> V_75 ,
. V_105 = V_106 ,
} ;
V_53 = F_20 ( V_19 , V_84 -> V_288 ) ;
if ( ! V_53 )
return - V_67 ;
V_287 . V_104 = V_53 -> V_104 ;
V_7 = F_14 ( V_21 , V_107 , V_289 , NULL , & V_287 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_287 . V_290 == V_287 . V_291 &&
V_287 . V_292 == V_287 . V_293 ) {
V_84 -> type = V_294 ;
V_84 -> V_295 . V_59 = V_287 . V_290 ;
V_84 -> V_295 . V_60 = V_287 . V_292 ;
return 0 ;
}
V_84 -> type = V_296 ;
V_84 -> V_297 . V_290 = V_287 . V_290 ;
V_84 -> V_297 . V_291 = V_287 . V_291 ;
V_84 -> V_297 . V_292 = V_287 . V_292 ;
V_84 -> V_297 . V_293 = V_287 . V_293 ;
V_84 -> V_297 . V_298 = 1 ;
V_84 -> V_297 . V_299 = 1 ;
return 0 ;
}
int F_178 ( struct V_26 * V_27 )
{
struct V_26 * V_300 ;
int V_7 ;
if ( ! V_27 || ! V_27 -> V_28 ||
! V_27 -> V_28 -> V_66 ||
! V_27 -> V_28 -> V_115 ||
! V_27 -> V_28 -> V_120 ||
! V_27 -> V_28 -> V_167 ||
( ( ! V_27 -> V_28 -> V_90 ||
! V_27 -> V_28 -> V_92 ) &&
! V_27 -> V_28 -> V_142 ) ||
! V_27 -> V_28 -> V_158 ||
! V_27 -> V_196 . V_2 )
return - V_67 ;
if ( ! V_27 -> V_28 -> V_180 )
V_27 -> V_28 -> V_180 = F_174 ;
if ( ! V_27 -> V_28 -> V_173 )
V_27 -> V_28 -> V_173 = F_173 ;
if ( ! V_27 -> V_28 -> V_171 )
V_27 -> V_28 -> V_171 = F_172 ;
if ( ! V_27 -> V_28 -> V_193 )
V_27 -> V_28 -> V_193 = F_176 ;
if ( ! V_27 -> V_28 -> V_192 )
V_27 -> V_28 -> V_192 = F_175 ;
if ( ! V_27 -> V_28 -> V_85 )
V_27 -> V_28 -> V_85 = F_177 ;
F_17 ( & V_125 ) ;
F_107 (ix, &hosts, list) {
if ( V_300 -> V_195 == V_27 -> V_195 ) {
V_7 = - V_89 ;
goto V_301;
}
}
V_7 = F_179 ( V_27 -> V_196 . V_2 , & V_27 -> V_196 ) ;
if ( V_7 < 0 )
goto V_301;
F_180 ( & V_27 -> V_302 , & V_303 ) ;
F_18 ( & V_125 ) ;
F_181 ( & V_27 -> V_129 ) ;
F_181 ( & V_27 -> V_30 ) ;
if ( V_27 -> V_196 . V_2 -> V_269 )
F_156 ( V_27 ) ;
else if ( V_27 -> V_259 )
F_152 ( V_27 ) ;
else
F_106 ( V_27 ) ;
return 0 ;
V_301:
F_18 ( & V_125 ) ;
return V_7 ;
}
void F_182 ( struct V_26 * V_27 )
{
struct V_18 * V_19 , * V_304 ;
struct V_197 * V_198 ;
F_183 ( V_305 ) ;
F_17 ( & V_125 ) ;
F_184 ( & V_27 -> V_302 ) ;
F_107 (icd, &devices, list)
if ( V_19 -> V_194 == V_27 -> V_195 && V_19 -> V_198 ) {
F_185 ( V_19 -> V_57 ) ;
F_186 ( & V_19 -> V_198 -> V_302 , & V_305 ) ;
}
F_18 ( & V_125 ) ;
F_107 (sasc, &notifiers, list) {
F_187 ( & V_198 -> V_234 ) ;
F_188 ( & V_198 -> V_57 -> V_2 ) ;
}
F_17 ( & V_125 ) ;
F_189 (icd, tmp, &devices, list)
if ( V_19 -> V_194 == V_27 -> V_195 )
F_169 ( V_19 ) ;
F_18 ( & V_125 ) ;
F_190 ( & V_27 -> V_196 ) ;
}
static int F_191 ( struct V_18 * V_19 )
{
struct V_18 * V_300 ;
int V_306 = - 1 , V_34 ;
F_17 ( & V_125 ) ;
for ( V_34 = 0 ; V_34 < 256 && V_306 < 0 ; V_34 ++ ) {
V_306 = V_34 ;
F_107 (ix, &devices, list) {
if ( V_300 -> V_194 == V_19 -> V_194 && V_300 -> V_307 == V_34 ) {
V_306 = - 1 ;
break;
}
}
}
if ( V_306 < 0 ) {
F_18 ( & V_125 ) ;
return - V_111 ;
}
V_19 -> V_307 = V_306 ;
V_19 -> V_131 = 0 ;
V_19 -> V_308 = NULL ;
V_34 = F_192 ( V_19 -> V_57 ) -> V_309 ;
if ( V_34 < 0 )
V_34 = 0 ;
if ( V_34 >= V_201 ) {
F_18 ( & V_125 ) ;
return - V_89 ;
}
F_113 ( V_34 , V_200 ) ;
F_180 ( & V_19 -> V_302 , & V_310 ) ;
F_18 ( & V_125 ) ;
return 0 ;
}
static int F_164 ( struct V_18 * V_19 )
{
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
struct V_123 * V_124 = F_193 () ;
if ( ! V_124 )
return - V_111 ;
F_90 ( V_124 -> V_77 , V_27 -> V_166 , sizeof( V_124 -> V_77 ) ) ;
V_124 -> V_196 = & V_27 -> V_196 ;
V_124 -> V_311 = & V_312 ;
V_124 -> V_313 = & V_314 ;
V_124 -> V_315 = F_167 ;
V_124 -> V_144 = & V_19 -> V_144 ;
V_124 -> V_316 = & V_27 -> V_129 ;
V_19 -> V_124 = V_124 ;
return 0 ;
}
static int F_124 ( struct V_18 * V_19 )
{
const struct V_317 * type = V_19 -> V_124 -> V_2 . type ;
int V_7 ;
if ( ! V_19 -> V_52 )
return - V_25 ;
F_194 ( V_19 -> V_124 , V_19 ) ;
if ( V_19 -> V_124 -> V_207 == 0 ) {
F_195 ( V_19 -> V_124 , V_318 ) ;
F_195 ( V_19 -> V_124 , V_319 ) ;
F_195 ( V_19 -> V_124 , V_320 ) ;
}
V_7 = F_196 ( V_19 -> V_124 , V_321 , - 1 ) ;
if ( V_7 < 0 ) {
F_4 ( V_19 -> V_57 , L_36 , V_7 ) ;
return V_7 ;
}
V_19 -> V_124 -> V_2 . type = type ;
return 0 ;
}
static int F_197 ( struct V_199 * V_57 )
{
struct V_132 * V_133 = V_57 -> V_2 . V_227 ;
struct V_3 * V_4 = & V_133 -> V_134 ;
struct V_18 * V_19 ;
int V_7 ;
if ( ! V_133 )
return - V_67 ;
V_19 = F_147 ( & V_57 -> V_2 , sizeof( * V_19 ) , V_224 ) ;
if ( ! V_19 )
return - V_111 ;
V_7 = F_11 ( & V_57 -> V_2 , V_4 -> V_11 . V_12 ,
V_4 -> V_11 . V_13 ) ;
if ( V_7 < 0 )
return V_7 ;
V_19 -> V_194 = V_133 -> V_216 . V_241 ;
V_19 -> V_133 = V_133 ;
V_19 -> V_57 = & V_57 -> V_2 ;
F_198 ( V_57 , V_19 ) ;
V_19 -> V_116 = V_322 ;
V_19 -> V_117 = V_323 ;
return F_191 ( V_19 ) ;
}
static int F_199 ( struct V_199 * V_57 )
{
struct V_18 * V_19 = F_119 ( V_57 ) ;
int V_34 ;
if ( ! V_19 )
return - V_67 ;
V_34 = V_57 -> V_309 ;
if ( V_34 < 0 )
V_34 = 0 ;
if ( F_200 ( V_34 , V_200 ) ) {
F_201 ( V_34 , V_200 ) ;
F_184 ( & V_19 -> V_302 ) ;
}
return 0 ;
}

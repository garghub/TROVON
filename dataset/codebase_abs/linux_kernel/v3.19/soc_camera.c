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
const struct V_26 * F_16 (
struct V_18 * V_19 , unsigned int V_27 )
{
unsigned int V_28 ;
for ( V_28 = 0 ; V_28 < V_19 -> V_29 ; V_28 ++ )
if ( V_19 -> V_30 [ V_28 ] . V_31 -> V_27 == V_27 )
return V_19 -> V_30 + V_28 ;
return NULL ;
}
unsigned long F_17 ( struct V_3 * V_4 ,
const struct V_32 * V_33 )
{
unsigned long V_34 , V_35 = V_33 -> V_35 ;
if ( V_4 -> V_35 & V_36 ) {
V_34 = V_35 & ( V_37 | V_38 ) ;
if ( V_34 == V_37 || V_34 == V_38 )
V_35 ^= V_37 | V_38 ;
}
if ( V_4 -> V_35 & V_39 ) {
V_34 = V_35 & ( V_40 | V_41 ) ;
if ( V_34 == V_40 || V_34 == V_41 )
V_35 ^= V_40 | V_41 ;
}
if ( V_4 -> V_35 & V_42 ) {
V_34 = V_35 & ( V_43 | V_44 ) ;
if ( V_34 == V_43 || V_34 == V_44 )
V_35 ^= V_43 | V_44 ;
}
return V_35 ;
}
static int F_18 ( struct V_18 * V_19 ,
struct V_45 * V_34 )
{
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
const struct V_26 * V_49 ;
struct V_50 * V_51 = & V_34 -> V_52 . V_51 ;
int V_7 ;
F_20 ( V_19 -> V_53 , L_6 ,
F_21 ( V_51 -> V_54 ) , V_51 -> V_55 , V_51 -> V_56 ) ;
if ( V_51 -> V_54 != V_57 &&
! ( V_47 -> V_58 & V_59 ) ) {
V_51 -> V_60 = 0 ;
V_51 -> V_61 = 0 ;
}
V_7 = V_47 -> V_62 -> V_63 ( V_19 , V_34 ) ;
if ( V_7 < 0 )
return V_7 ;
V_49 = F_16 ( V_19 , V_51 -> V_54 ) ;
if ( ! V_49 )
return - V_64 ;
V_7 = F_22 ( V_51 -> V_55 , V_49 -> V_31 ) ;
if ( V_7 < 0 )
return V_7 ;
V_51 -> V_60 = F_23 ( V_65 , V_51 -> V_60 , V_7 ) ;
V_7 = F_24 ( V_49 -> V_31 , V_51 -> V_60 ,
V_51 -> V_56 ) ;
if ( V_7 < 0 )
return V_7 ;
V_51 -> V_61 = F_23 ( V_65 , V_51 -> V_61 , V_7 ) ;
return 0 ;
}
static int F_25 ( struct V_66 * V_66 , void * V_67 ,
struct V_45 * V_34 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
F_26 ( V_67 != V_66 -> V_68 ) ;
if ( V_34 -> type != V_69 )
return - V_64 ;
return F_18 ( V_19 , V_34 ) ;
}
static int F_27 ( struct V_66 * V_66 , void * V_67 ,
struct V_70 * V_71 )
{
if ( V_71 -> V_72 != 0 )
return - V_64 ;
V_71 -> type = V_73 ;
strcpy ( V_71 -> V_74 , L_7 ) ;
return 0 ;
}
static int F_28 ( struct V_66 * V_66 , void * V_67 , unsigned int * V_28 )
{
* V_28 = 0 ;
return 0 ;
}
static int F_29 ( struct V_66 * V_66 , void * V_67 , unsigned int V_28 )
{
if ( V_28 > 0 )
return - V_64 ;
return 0 ;
}
static int F_30 ( struct V_66 * V_66 , void * V_67 , T_1 V_75 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_76 , V_77 , V_75 ) ;
}
static int F_31 ( struct V_66 * V_66 , void * V_67 , T_1 * V_75 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_76 , V_78 , V_75 ) ;
}
static int F_32 ( struct V_66 * V_66 , void * V_79 ,
struct V_80 * V_81 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
return V_47 -> V_62 -> V_82 ( V_19 , V_81 ) ;
}
static int F_33 ( struct V_66 * V_66 , void * V_67 ,
struct V_83 * V_84 )
{
int V_7 ;
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
F_26 ( V_67 != V_66 -> V_68 ) ;
if ( V_19 -> V_85 && V_19 -> V_85 != V_66 )
return - V_86 ;
if ( V_47 -> V_62 -> V_87 ) {
V_7 = F_34 ( & V_19 -> V_88 , V_84 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = V_47 -> V_62 -> V_89 ( V_19 , V_84 ) ;
} else {
V_7 = F_35 ( & V_19 -> V_90 , V_84 ) ;
}
if ( ! V_7 && ! V_19 -> V_85 )
V_19 -> V_85 = V_66 ;
return V_7 ;
}
static int F_36 ( struct V_66 * V_66 , void * V_67 ,
struct V_91 * V_84 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
F_26 ( V_67 != V_66 -> V_68 ) ;
if ( V_47 -> V_62 -> V_87 )
return F_37 ( & V_19 -> V_88 , V_84 ) ;
else
return F_38 ( & V_19 -> V_90 , V_84 ) ;
}
static int F_39 ( struct V_66 * V_66 , void * V_67 ,
struct V_91 * V_84 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
F_26 ( V_67 != V_66 -> V_68 ) ;
if ( V_19 -> V_85 != V_66 )
return - V_86 ;
if ( V_47 -> V_62 -> V_87 )
return F_40 ( & V_19 -> V_88 , V_84 ) ;
else
return F_41 ( & V_19 -> V_90 , V_84 ) ;
}
static int F_42 ( struct V_66 * V_66 , void * V_67 ,
struct V_91 * V_84 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
F_26 ( V_67 != V_66 -> V_68 ) ;
if ( V_19 -> V_85 != V_66 )
return - V_86 ;
if ( V_47 -> V_62 -> V_87 )
return F_43 ( & V_19 -> V_88 , V_84 , V_66 -> V_92 & V_93 ) ;
else
return F_44 ( & V_19 -> V_90 , V_84 , V_66 -> V_92 & V_93 ) ;
}
static int F_45 ( struct V_66 * V_66 , void * V_67 ,
struct V_94 * V_95 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
if ( V_47 -> V_62 -> V_87 )
return - V_64 ;
else
return F_46 ( & V_19 -> V_90 , V_95 ) ;
}
static int F_47 ( struct V_66 * V_66 , void * V_67 ,
struct V_91 * V_96 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
if ( V_47 -> V_62 -> V_87 )
return - V_64 ;
else
return F_48 ( & V_19 -> V_90 , V_96 ) ;
}
static int F_49 ( struct V_66 * V_66 , void * V_67 ,
struct V_97 * V_84 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
if ( V_19 -> V_85 != V_66 )
return - V_86 ;
if ( V_47 -> V_62 -> V_87 )
return - V_64 ;
else
return F_50 ( & V_19 -> V_90 , V_84 ) ;
}
static int F_51 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
unsigned int V_28 , V_98 = 0 , V_99 = 0 ;
int V_7 ;
V_65 V_100 ;
while ( ! F_14 ( V_21 , V_76 , V_101 , V_99 , & V_100 ) )
V_99 ++ ;
if ( ! V_47 -> V_62 -> V_102 )
V_98 = V_99 ;
else
for ( V_28 = 0 ; V_28 < V_99 ; V_28 ++ ) {
V_7 = V_47 -> V_62 -> V_102 ( V_19 , V_28 , NULL ) ;
if ( V_7 < 0 )
return V_7 ;
V_98 += V_7 ;
}
if ( ! V_98 )
return - V_103 ;
V_19 -> V_30 =
F_52 ( V_98 * sizeof( struct V_26 ) ) ;
if ( ! V_19 -> V_30 )
return - V_104 ;
F_20 ( V_19 -> V_53 , L_8 , V_98 ) ;
V_98 = 0 ;
for ( V_28 = 0 ; V_28 < V_99 ; V_28 ++ )
if ( ! V_47 -> V_62 -> V_102 ) {
F_14 ( V_21 , V_76 , V_101 , V_28 , & V_100 ) ;
V_19 -> V_30 [ V_98 ] . V_31 =
F_53 ( V_100 ) ;
if ( V_19 -> V_30 [ V_98 ] . V_31 )
V_19 -> V_30 [ V_98 ++ ] . V_100 = V_100 ;
} else {
V_7 = V_47 -> V_62 -> V_102 ( V_19 , V_28 ,
& V_19 -> V_30 [ V_98 ] ) ;
if ( V_7 < 0 )
goto V_105;
V_98 += V_7 ;
}
V_19 -> V_29 = V_98 ;
V_19 -> V_106 = & V_19 -> V_30 [ 0 ] ;
return 0 ;
V_105:
F_54 ( V_19 -> V_30 ) ;
return V_7 ;
}
static void F_55 ( struct V_18 * V_19 )
{
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
if ( V_47 -> V_62 -> V_107 )
V_47 -> V_62 -> V_107 ( V_19 ) ;
V_19 -> V_106 = NULL ;
V_19 -> V_29 = 0 ;
F_54 ( V_19 -> V_30 ) ;
V_19 -> V_30 = NULL ;
}
static int F_56 ( struct V_18 * V_19 ,
struct V_45 * V_34 )
{
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
struct V_50 * V_51 = & V_34 -> V_52 . V_51 ;
int V_7 ;
F_20 ( V_19 -> V_53 , L_9 ,
F_21 ( V_51 -> V_54 ) , V_51 -> V_55 , V_51 -> V_56 ) ;
V_7 = F_18 ( V_19 , V_34 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = V_47 -> V_62 -> V_108 ( V_19 , V_34 ) ;
if ( V_7 < 0 ) {
return V_7 ;
} else if ( ! V_19 -> V_106 ||
V_19 -> V_106 -> V_31 -> V_27 != V_51 -> V_54 ) {
F_4 ( V_19 -> V_53 ,
L_10 ) ;
return - V_64 ;
}
V_19 -> V_109 = V_51 -> V_55 ;
V_19 -> V_110 = V_51 -> V_56 ;
V_19 -> V_60 = V_51 -> V_60 ;
V_19 -> V_61 = V_51 -> V_61 ;
V_19 -> V_111 = V_51 -> V_111 ;
V_19 -> V_112 = V_51 -> V_112 ;
if ( V_47 -> V_62 -> V_87 )
V_19 -> V_88 . V_112 = V_51 -> V_112 ;
F_20 ( V_19 -> V_53 , L_11 ,
V_19 -> V_109 , V_19 -> V_110 ) ;
return V_47 -> V_62 -> V_113 ( V_19 ) ;
}
static int F_57 ( struct V_18 * V_19 )
{
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
int V_7 ;
if ( V_47 -> V_19 )
return - V_86 ;
if ( ! V_19 -> V_6 ) {
F_58 ( & V_47 -> V_114 ) ;
V_7 = V_47 -> V_62 -> V_115 ( V_47 ) ;
F_59 ( & V_47 -> V_114 ) ;
if ( V_7 < 0 )
return V_7 ;
}
if ( V_47 -> V_62 -> V_116 ) {
V_7 = V_47 -> V_62 -> V_116 ( V_19 ) ;
if ( V_7 < 0 )
goto V_117;
}
V_47 -> V_19 = V_19 ;
return 0 ;
V_117:
if ( ! V_19 -> V_6 ) {
F_58 ( & V_47 -> V_114 ) ;
V_47 -> V_62 -> V_118 ( V_47 ) ;
F_59 ( & V_47 -> V_114 ) ;
}
return V_7 ;
}
static void F_60 ( struct V_18 * V_19 )
{
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
if ( F_26 ( V_19 != V_47 -> V_19 ) )
return;
if ( V_47 -> V_62 -> remove )
V_47 -> V_62 -> remove ( V_19 ) ;
if ( ! V_19 -> V_6 ) {
F_58 ( & V_47 -> V_114 ) ;
V_47 -> V_62 -> V_118 ( V_47 ) ;
F_59 ( & V_47 -> V_114 ) ;
}
V_47 -> V_19 = NULL ;
}
static int F_61 ( struct V_66 * V_66 )
{
struct V_119 * V_120 = F_62 ( V_66 ) ;
struct V_18 * V_19 ;
struct V_46 * V_47 ;
int V_7 ;
if ( F_63 ( & V_121 ) )
return - V_122 ;
if ( ! V_120 || ! F_64 ( V_120 ) ) {
F_59 ( & V_121 ) ;
return - V_25 ;
}
V_19 = F_65 ( V_120 ) ;
V_47 = F_19 ( V_19 -> V_48 ) ;
V_7 = F_66 ( V_47 -> V_62 -> V_123 ) ? 0 : - V_25 ;
F_59 ( & V_121 ) ;
if ( V_7 < 0 ) {
F_4 ( V_19 -> V_53 , L_12 ) ;
return V_7 ;
}
if ( ! F_67 ( V_19 ) ) {
V_7 = - V_25 ;
goto V_124;
}
if ( F_63 ( & V_47 -> V_125 ) ) {
V_7 = - V_122 ;
goto V_126;
}
V_19 -> V_127 ++ ;
if ( V_19 -> V_127 == 1 ) {
struct V_128 * V_129 = F_68 ( V_19 ) ;
struct V_45 V_34 = {
. type = V_69 ,
. V_52 . V_51 = {
. V_55 = V_19 -> V_109 ,
. V_56 = V_19 -> V_110 ,
. V_112 = V_19 -> V_112 ,
. V_111 = V_19 -> V_111 ,
. V_54 =
V_19 -> V_106 -> V_31 -> V_27 ,
} ,
} ;
if ( V_129 -> V_130 . V_131 )
V_129 -> V_130 . V_131 ( V_19 -> V_53 ) ;
V_7 = F_57 ( V_19 ) ;
if ( V_7 < 0 ) {
F_4 ( V_19 -> V_53 , L_13 , V_7 ) ;
goto V_132;
}
V_7 = F_12 ( V_19 ) ;
if ( V_7 < 0 )
goto V_133;
F_69 ( & V_19 -> V_120 -> V_2 ) ;
V_7 = F_70 ( & V_19 -> V_120 -> V_2 ) ;
if ( V_7 < 0 && V_7 != - V_134 )
goto V_135;
V_7 = F_56 ( V_19 , & V_34 ) ;
if ( V_7 < 0 )
goto V_136;
if ( V_47 -> V_62 -> V_87 ) {
V_47 -> V_62 -> V_87 ( & V_19 -> V_88 , V_19 ) ;
} else {
V_7 = V_47 -> V_62 -> V_137 ( & V_19 -> V_90 , V_19 ) ;
if ( V_7 < 0 )
goto V_138;
}
F_71 ( & V_19 -> V_139 ) ;
}
F_59 ( & V_47 -> V_125 ) ;
V_66 -> V_68 = V_19 ;
F_20 ( V_19 -> V_53 , L_14 ) ;
return 0 ;
V_138:
V_136:
F_72 ( & V_19 -> V_120 -> V_2 ) ;
V_135:
F_15 ( V_19 ) ;
V_133:
F_60 ( V_19 ) ;
V_132:
V_19 -> V_127 -- ;
F_59 ( & V_47 -> V_125 ) ;
V_126:
V_124:
F_73 ( V_47 -> V_62 -> V_123 ) ;
return V_7 ;
}
static int F_74 ( struct V_66 * V_66 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
F_58 ( & V_47 -> V_125 ) ;
V_19 -> V_127 -- ;
if ( ! V_19 -> V_127 ) {
F_75 ( & V_19 -> V_120 -> V_2 ) ;
F_72 ( & V_19 -> V_120 -> V_2 ) ;
if ( V_47 -> V_62 -> V_137 )
F_76 ( & V_19 -> V_90 ) ;
F_15 ( V_19 ) ;
F_60 ( V_19 ) ;
}
if ( V_19 -> V_85 == V_66 )
V_19 -> V_85 = NULL ;
F_59 ( & V_47 -> V_125 ) ;
F_73 ( V_47 -> V_62 -> V_123 ) ;
F_20 ( V_19 -> V_53 , L_15 ) ;
return 0 ;
}
static T_2 F_77 ( struct V_66 * V_66 , char T_3 * V_140 ,
T_4 V_141 , T_5 * V_142 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
F_20 ( V_19 -> V_53 , L_16 , V_140 ) ;
if ( V_47 -> V_62 -> V_137 && V_19 -> V_90 . V_143 & V_144 )
return F_78 ( & V_19 -> V_90 , V_140 , V_141 , V_142 ,
V_66 -> V_92 & V_93 ) ;
F_4 ( V_19 -> V_53 , L_17 ) ;
return - V_64 ;
}
static int F_79 ( struct V_66 * V_66 , struct V_145 * V_146 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
int V_17 ;
F_20 ( V_19 -> V_53 , L_18 , ( unsigned long ) V_146 ) ;
if ( V_19 -> V_85 != V_66 )
return - V_86 ;
if ( F_63 ( & V_47 -> V_125 ) )
return - V_122 ;
if ( V_47 -> V_62 -> V_87 )
V_17 = F_80 ( & V_19 -> V_88 , V_146 ) ;
else
V_17 = F_81 ( & V_19 -> V_90 , V_146 ) ;
F_59 ( & V_47 -> V_125 ) ;
F_20 ( V_19 -> V_53 , L_19 ,
( unsigned long ) V_146 -> V_147 ,
( unsigned long ) V_146 -> V_148 - ( unsigned long ) V_146 -> V_147 ,
V_17 ) ;
return V_17 ;
}
static unsigned int F_82 ( struct V_66 * V_66 , T_6 * V_149 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
unsigned V_150 = V_151 ;
if ( V_19 -> V_85 != V_66 )
return V_151 ;
F_58 ( & V_47 -> V_125 ) ;
if ( V_47 -> V_62 -> V_87 && F_83 ( & V_19 -> V_88 . V_152 ) )
F_4 ( V_19 -> V_53 , L_20 ) ;
else
V_150 = V_47 -> V_62 -> V_153 ( V_66 , V_149 ) ;
F_59 ( & V_47 -> V_125 ) ;
return V_150 ;
}
void F_84 ( struct V_154 * V_155 )
{
struct V_18 * V_19 = F_85 ( V_155 ) ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
F_58 ( & V_47 -> V_125 ) ;
}
void F_86 ( struct V_154 * V_155 )
{
struct V_18 * V_19 = F_85 ( V_155 ) ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
F_59 ( & V_47 -> V_125 ) ;
}
static int F_87 ( struct V_66 * V_66 , void * V_67 ,
struct V_45 * V_34 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
int V_7 ;
F_26 ( V_67 != V_66 -> V_68 ) ;
if ( V_34 -> type != V_69 ) {
F_88 ( V_19 -> V_53 , L_21 , V_34 -> type ) ;
return - V_64 ;
}
if ( V_19 -> V_85 && V_19 -> V_85 != V_66 )
return - V_86 ;
if ( F_89 ( F_19 ( V_19 -> V_48 ) , V_19 ) ) {
F_4 ( V_19 -> V_53 , L_22 ) ;
return - V_86 ;
}
V_7 = F_56 ( V_19 , V_34 ) ;
if ( ! V_7 && ! V_19 -> V_85 )
V_19 -> V_85 = V_66 ;
return V_7 ;
}
static int F_90 ( struct V_66 * V_66 , void * V_67 ,
struct V_156 * V_34 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
const struct V_157 * V_158 ;
F_26 ( V_67 != V_66 -> V_68 ) ;
if ( V_34 -> V_72 >= V_19 -> V_29 )
return - V_64 ;
V_158 = V_19 -> V_30 [ V_34 -> V_72 ] . V_31 ;
if ( V_158 -> V_74 )
F_91 ( V_34 -> V_159 , V_158 -> V_74 , sizeof( V_34 -> V_159 ) ) ;
V_34 -> V_54 = V_158 -> V_27 ;
return 0 ;
}
static int F_92 ( struct V_66 * V_66 , void * V_67 ,
struct V_45 * V_34 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_50 * V_51 = & V_34 -> V_52 . V_51 ;
F_26 ( V_67 != V_66 -> V_68 ) ;
if ( V_34 -> type != V_69 )
return - V_64 ;
V_51 -> V_55 = V_19 -> V_109 ;
V_51 -> V_56 = V_19 -> V_110 ;
V_51 -> V_60 = V_19 -> V_60 ;
V_51 -> V_61 = V_19 -> V_61 ;
V_51 -> V_112 = V_19 -> V_112 ;
V_51 -> V_54 = V_19 -> V_106 -> V_31 -> V_27 ;
V_51 -> V_111 = V_19 -> V_111 ;
F_20 ( V_19 -> V_53 , L_23 ,
V_19 -> V_106 -> V_31 -> V_27 ) ;
return 0 ;
}
static int F_93 ( struct V_66 * V_66 , void * V_67 ,
struct V_160 * V_161 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
F_26 ( V_67 != V_66 -> V_68 ) ;
F_91 ( V_161 -> V_162 , V_47 -> V_163 , sizeof( V_161 -> V_162 ) ) ;
return V_47 -> V_62 -> V_164 ( V_47 , V_161 ) ;
}
static int F_94 ( struct V_66 * V_66 , void * V_67 ,
enum V_165 V_28 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
struct V_20 * V_21 = F_13 ( V_19 ) ;
int V_7 ;
F_26 ( V_67 != V_66 -> V_68 ) ;
if ( V_28 != V_69 )
return - V_64 ;
if ( V_19 -> V_85 != V_66 )
return - V_86 ;
if ( V_47 -> V_62 -> V_87 )
V_7 = F_95 ( & V_19 -> V_88 ) ;
else
V_7 = F_96 ( & V_19 -> V_90 , V_28 ) ;
if ( ! V_7 )
F_14 ( V_21 , V_76 , V_166 , 1 ) ;
return V_7 ;
}
static int F_97 ( struct V_66 * V_66 , void * V_67 ,
enum V_165 V_28 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_20 * V_21 = F_13 ( V_19 ) ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
F_26 ( V_67 != V_66 -> V_68 ) ;
if ( V_28 != V_69 )
return - V_64 ;
if ( V_19 -> V_85 != V_66 )
return - V_86 ;
if ( V_47 -> V_62 -> V_87 )
F_98 ( & V_19 -> V_88 ) ;
else
F_99 ( & V_19 -> V_90 , V_28 ) ;
F_14 ( V_21 , V_76 , V_166 , 0 ) ;
return 0 ;
}
static int F_100 ( struct V_66 * V_66 , void * V_79 ,
struct V_167 * V_75 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
return V_47 -> V_62 -> V_168 ( V_19 , V_75 ) ;
}
static int F_101 ( struct V_66 * V_66 , void * V_79 ,
struct V_169 * V_75 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
int V_7 ;
V_7 = V_47 -> V_62 -> V_170 ( V_19 , V_75 ) ;
return V_7 ;
}
static int F_102 ( struct V_66 * V_66 , void * V_79 ,
const struct V_169 * V_75 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
const struct V_171 * V_172 = & V_75 -> V_173 ;
struct V_169 V_174 ;
int V_7 ;
if ( V_75 -> type != V_69 )
return - V_64 ;
F_20 ( V_19 -> V_53 , L_24 ,
V_172 -> V_55 , V_172 -> V_56 , V_172 -> V_175 , V_172 -> V_176 ) ;
V_174 . type = V_75 -> type ;
V_7 = V_47 -> V_62 -> V_170 ( V_19 , & V_174 ) ;
if ( V_7 < 0 ) {
F_4 ( V_19 -> V_53 ,
L_25 ) ;
} else if ( ( V_75 -> V_173 . V_55 == V_174 . V_173 . V_55 &&
V_75 -> V_173 . V_56 == V_174 . V_173 . V_56 ) ||
! F_89 ( V_47 , V_19 ) ) {
V_7 = V_47 -> V_62 -> V_177 ( V_19 , V_75 ) ;
} else if ( V_47 -> V_62 -> V_178 ) {
V_7 = V_47 -> V_62 -> V_178 ( V_19 , V_75 ) ;
} else {
F_4 ( V_19 -> V_53 ,
L_26 ) ;
V_7 = - V_86 ;
}
return V_7 ;
}
static int F_103 ( struct V_66 * V_66 , void * V_79 ,
struct V_179 * V_180 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
if ( V_180 -> type != V_69 )
return - V_64 ;
if ( ! V_47 -> V_62 -> V_181 )
return - V_182 ;
return V_47 -> V_62 -> V_181 ( V_19 , V_180 ) ;
}
static int F_104 ( struct V_66 * V_66 , void * V_79 ,
struct V_179 * V_180 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
int V_7 ;
if ( V_180 -> type != V_69 ||
( V_180 -> V_183 != V_184 &&
V_180 -> V_183 != V_185 ) )
return - V_64 ;
if ( V_180 -> V_183 == V_184 ) {
if ( F_89 ( V_47 , V_19 ) &&
( V_19 -> V_109 != V_180 -> V_186 . V_55 ||
V_19 -> V_110 != V_180 -> V_186 . V_56 ) )
return - V_86 ;
if ( V_19 -> V_85 && V_19 -> V_85 != V_66 )
return - V_86 ;
}
if ( ! V_47 -> V_62 -> V_187 )
return - V_182 ;
V_7 = V_47 -> V_62 -> V_187 ( V_19 , V_180 ) ;
if ( ! V_7 &&
V_180 -> V_183 == V_184 ) {
V_19 -> V_109 = V_180 -> V_186 . V_55 ;
V_19 -> V_110 = V_180 -> V_186 . V_56 ;
if ( ! V_19 -> V_85 )
V_19 -> V_85 = V_66 ;
}
return V_7 ;
}
static int F_105 ( struct V_66 * V_66 , void * V_79 ,
struct V_188 * V_75 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
if ( V_47 -> V_62 -> V_189 )
return V_47 -> V_62 -> V_189 ( V_19 , V_75 ) ;
return - V_24 ;
}
static int F_106 ( struct V_66 * V_66 , void * V_79 ,
struct V_188 * V_75 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
if ( V_47 -> V_62 -> V_190 )
return V_47 -> V_62 -> V_190 ( V_19 , V_75 ) ;
return - V_24 ;
}
static void F_107 ( struct V_46 * V_47 )
{
struct V_18 * V_19 ;
F_58 ( & V_121 ) ;
F_108 (icd, &devices, list)
if ( V_19 -> V_191 == V_47 -> V_192 ) {
struct V_128 * V_129 = F_68 ( V_19 ) ;
struct V_3 * V_4 = & V_129 -> V_130 ;
if ( V_4 -> V_131 )
V_4 -> V_131 ( V_19 -> V_53 ) ;
V_19 -> V_48 = V_47 -> V_193 . V_2 ;
F_109 ( V_47 , V_19 ) ;
}
F_59 ( & V_121 ) ;
}
static int F_110 ( struct V_5 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_67 ;
struct V_46 * V_47 ;
int V_7 ;
if ( ! V_19 || ! V_19 -> V_48 )
return - V_25 ;
V_47 = F_19 ( V_19 -> V_48 ) ;
if ( ! F_66 ( V_47 -> V_62 -> V_123 ) )
return - V_25 ;
F_58 ( & V_47 -> V_114 ) ;
V_7 = V_47 -> V_62 -> V_115 ( V_47 ) ;
F_59 ( & V_47 -> V_114 ) ;
return V_7 ;
}
static void F_111 ( struct V_5 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_67 ;
struct V_46 * V_47 ;
if ( ! V_19 || ! V_19 -> V_48 )
return;
V_47 = F_19 ( V_19 -> V_48 ) ;
F_58 ( & V_47 -> V_114 ) ;
V_47 -> V_62 -> V_118 ( V_47 ) ;
F_59 ( & V_47 -> V_114 ) ;
F_73 ( V_47 -> V_62 -> V_123 ) ;
}
static int F_112 ( struct V_128 * V_129 ,
struct V_194 * V_195 )
{
struct V_196 * V_53 ;
int V_7 , V_28 ;
F_58 ( & V_121 ) ;
V_28 = F_113 ( V_197 , V_198 ) ;
if ( V_28 < V_198 )
F_114 ( V_28 , V_197 ) ;
F_59 ( & V_121 ) ;
if ( V_28 >= V_198 )
return - V_104 ;
V_53 = F_115 ( L_27 , V_28 ) ;
if ( ! V_53 )
return - V_104 ;
V_7 = F_116 ( V_53 , V_129 , sizeof( * V_129 ) ) ;
if ( V_7 < 0 ) {
F_117 ( V_53 ) ;
return V_7 ;
}
V_195 -> V_53 = V_53 ;
return 0 ;
}
static struct V_18 * F_118 ( struct V_194 * V_195 )
{
struct V_196 * V_53 = V_195 -> V_53 ;
int V_7 ;
V_7 = F_119 ( V_53 ) ;
if ( V_7 < 0 || ! V_53 -> V_2 . V_162 )
return NULL ;
return F_120 ( V_53 ) ;
}
static int F_121 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
struct V_199 V_200 ;
int V_7 ;
V_21 -> V_201 = F_122 ( V_19 ) ;
F_123 ( V_21 , V_19 ) ;
F_14 ( V_21 , V_76 , V_202 , & V_19 -> V_120 -> V_203 ) ;
V_7 = F_124 ( & V_19 -> V_139 , V_21 -> V_139 , NULL ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_57 ( V_19 ) ;
if ( V_7 < 0 ) {
F_4 ( V_19 -> V_53 , L_13 , V_7 ) ;
return V_7 ;
}
V_7 = F_51 ( V_19 ) ;
if ( V_7 < 0 )
goto V_204;
V_19 -> V_112 = V_205 ;
V_7 = F_125 ( V_19 ) ;
if ( V_7 < 0 )
goto V_206;
if ( ! F_14 ( V_21 , V_76 , V_207 , & V_200 ) ) {
V_19 -> V_109 = V_200 . V_55 ;
V_19 -> V_110 = V_200 . V_56 ;
V_19 -> V_111 = V_200 . V_111 ;
V_19 -> V_112 = V_200 . V_112 ;
}
F_60 ( V_19 ) ;
return 0 ;
V_206:
F_55 ( V_19 ) ;
V_204:
F_60 ( V_19 ) ;
return V_7 ;
}
static int F_126 ( struct V_18 * V_19 ,
struct V_128 * V_129 )
{
struct V_3 * V_4 ;
struct V_208 * V_209 ;
struct V_46 * V_47 ;
struct V_210 * V_211 = & V_129 -> V_212 ;
struct V_213 * V_214 ;
struct V_20 * V_215 ;
char V_216 [ V_217 ] ;
int V_7 ;
if ( V_19 -> V_195 ) {
return - V_218 ;
}
V_47 = F_19 ( V_19 -> V_48 ) ;
V_214 = F_127 ( V_211 -> V_219 ) ;
if ( ! V_214 ) {
F_4 ( V_19 -> V_53 , L_28 ,
V_211 -> V_219 ) ;
return - V_25 ;
}
V_4 = F_128 ( & V_129 -> V_130 , sizeof( * V_4 ) , V_220 ) ;
if ( ! V_4 ) {
V_7 = - V_104 ;
goto V_221;
}
V_4 -> V_11 . V_12 = 0 ;
V_4 -> V_11 . V_13 = NULL ;
V_211 -> V_222 -> V_223 = V_4 ;
snprintf ( V_216 , sizeof( V_216 ) , L_29 ,
V_211 -> V_219 , V_211 -> V_222 -> V_224 ) ;
V_19 -> V_6 = F_129 ( & V_225 , V_216 , L_30 , V_19 ) ;
if ( F_130 ( V_19 -> V_6 ) ) {
V_7 = F_131 ( V_19 -> V_6 ) ;
goto V_226;
}
V_215 = F_132 ( & V_47 -> V_193 , V_214 ,
V_211 -> V_222 , NULL ) ;
if ( ! V_215 ) {
V_7 = - V_25 ;
goto V_227;
}
V_209 = F_133 ( V_215 ) ;
V_19 -> V_228 = & V_209 -> V_2 ;
return 0 ;
V_227:
F_134 ( V_19 -> V_6 ) ;
V_19 -> V_6 = NULL ;
V_226:
F_135 ( V_4 ) ;
V_221:
F_136 ( V_214 ) ;
return V_7 ;
}
static void F_137 ( struct V_18 * V_19 )
{
struct V_208 * V_209 =
F_138 ( F_67 ( V_19 ) ) ;
struct V_213 * V_214 ;
struct V_3 * V_4 ;
V_19 -> V_228 = NULL ;
if ( V_19 -> V_195 )
return;
V_214 = V_209 -> V_229 ;
V_4 = V_209 -> V_2 . V_223 ;
F_139 ( F_140 ( V_209 ) ) ;
F_141 ( V_209 ) ;
F_136 ( V_214 ) ;
F_135 ( V_4 ) ;
F_134 ( V_19 -> V_6 ) ;
V_19 -> V_6 = NULL ;
}
static int F_142 ( struct V_230 * V_231 ,
struct V_20 * V_21 ,
struct V_232 * V_233 )
{
struct V_194 * V_195 = F_143 ( V_231 ,
struct V_194 , V_231 ) ;
struct V_18 * V_19 = F_120 ( V_195 -> V_53 ) ;
if ( V_233 == V_195 -> V_234 && ! F_26 ( V_19 -> V_228 ) ) {
struct V_208 * V_209 = F_133 ( V_21 ) ;
if ( V_209 ) {
struct V_128 * V_129 = F_68 ( V_19 ) ;
struct V_3 * V_4 =
F_144 ( V_209 ) ;
if ( V_4 ) {
memcpy ( & V_129 -> V_130 , V_4 ,
sizeof( V_129 -> V_130 ) ) ;
if ( V_4 -> V_131 )
V_4 -> V_131 ( V_19 -> V_53 ) ;
}
V_19 -> V_228 = & V_209 -> V_2 ;
}
}
return 0 ;
}
static void F_145 ( struct V_230 * V_231 ,
struct V_20 * V_21 ,
struct V_232 * V_233 )
{
struct V_194 * V_195 = F_143 ( V_231 ,
struct V_194 , V_231 ) ;
struct V_18 * V_19 = F_120 ( V_195 -> V_53 ) ;
if ( V_19 -> V_6 ) {
F_134 ( V_19 -> V_6 ) ;
V_19 -> V_6 = NULL ;
}
}
static int F_146 ( struct V_230 * V_231 )
{
struct V_194 * V_195 = F_143 ( V_231 ,
struct V_194 , V_231 ) ;
struct V_18 * V_19 = F_120 ( V_195 -> V_53 ) ;
if ( F_67 ( V_19 ) ) {
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
int V_7 ;
F_58 ( & V_121 ) ;
V_7 = F_109 ( V_47 , V_19 ) ;
F_59 ( & V_121 ) ;
if ( V_7 < 0 )
return V_7 ;
}
return 0 ;
}
static int F_147 ( struct V_46 * V_47 ,
struct V_232 * * V_233 , unsigned int V_235 )
{
struct V_236 * V_237 ;
struct V_194 * V_195 ;
struct V_18 * V_19 ;
struct V_128 V_129 = { . V_212 . V_238 = V_47 -> V_192 ,} ;
char V_216 [ V_217 ] ;
unsigned int V_28 ;
int V_7 ;
for ( V_28 = 0 ; V_28 < V_235 ; V_28 ++ ) {
V_237 = F_143 ( V_233 [ V_28 ] , struct V_236 , V_233 ) ;
if ( V_237 -> V_239 == V_240 )
break;
}
if ( V_28 >= V_235 || V_233 [ V_28 ] -> V_241 != V_242 ) {
F_4 ( V_47 -> V_193 . V_2 , L_31 ) ;
return - V_25 ;
}
V_195 = F_148 ( V_47 -> V_193 . V_2 , sizeof( * V_195 ) , V_220 ) ;
if ( ! V_195 )
return - V_104 ;
V_129 . V_212 . V_222 = F_149 ( - V_243 ) ;
V_7 = F_112 ( & V_129 , V_195 ) ;
if ( V_7 < 0 )
goto V_244;
V_195 -> V_234 = & V_237 -> V_233 ;
V_19 = F_118 ( V_195 ) ;
if ( ! V_19 ) {
V_7 = - V_104 ;
goto V_245;
}
V_195 -> V_231 . V_246 = V_233 ;
V_195 -> V_231 . V_247 = V_235 ;
V_195 -> V_231 . V_248 = F_142 ;
V_195 -> V_231 . V_249 = F_145 ;
V_195 -> V_231 . V_250 = F_146 ;
V_19 -> V_195 = V_195 ;
V_19 -> V_48 = V_47 -> V_193 . V_2 ;
snprintf ( V_216 , sizeof( V_216 ) , L_29 ,
V_237 -> V_233 . V_251 . V_252 . V_253 , V_237 -> V_233 . V_251 . V_252 . V_254 ) ;
V_19 -> V_6 = F_129 ( & V_225 , V_216 , L_30 , V_19 ) ;
if ( F_130 ( V_19 -> V_6 ) ) {
V_7 = F_131 ( V_19 -> V_6 ) ;
goto V_226;
}
V_7 = F_150 ( & V_47 -> V_193 , & V_195 -> V_231 ) ;
if ( ! V_7 )
return 0 ;
F_134 ( V_19 -> V_6 ) ;
V_226:
V_19 -> V_6 = NULL ;
F_151 ( V_195 -> V_53 ) ;
V_245:
F_117 ( V_195 -> V_53 ) ;
V_244:
F_152 ( V_47 -> V_193 . V_2 , V_195 ) ;
F_4 ( V_47 -> V_193 . V_2 , L_32 , V_7 ) ;
return V_7 ;
}
static void F_153 ( struct V_46 * V_47 )
{
struct V_232 * * V_233 ;
int V_255 ;
for ( V_255 = 0 , V_233 = V_47 -> V_233 ; V_47 -> V_256 [ V_255 ] ; V_255 ++ ) {
F_147 ( V_47 , V_233 , V_47 -> V_256 [ V_255 ] ) ;
V_233 += V_47 -> V_256 [ V_255 ] ;
}
}
static int F_154 ( struct V_46 * V_47 ,
struct V_257 * V_258 ,
struct V_257 * V_259 )
{
struct V_18 * V_19 ;
struct V_128 V_129 = { . V_212 . V_238 = V_47 -> V_192 ,} ;
struct V_194 * V_195 ;
struct V_260 * V_261 ;
struct V_208 * V_209 ;
char V_216 [ V_217 ] ;
int V_7 ;
V_261 = F_148 ( V_47 -> V_193 . V_2 , sizeof( struct V_260 ) ,
V_220 ) ;
if ( ! V_261 )
return - V_104 ;
V_261 -> V_237 . V_233 . V_251 . V_262 . V_263 = V_259 ;
V_261 -> V_237 . V_233 . V_241 = V_264 ;
V_261 -> V_215 = & V_261 -> V_237 . V_233 ;
V_195 = & V_261 -> V_195 ;
V_129 . V_212 . V_222 = F_149 ( - V_243 ) ;
V_7 = F_112 ( & V_129 , V_195 ) ;
if ( V_7 < 0 )
goto V_244;
V_195 -> V_234 = & V_261 -> V_237 . V_233 ;
V_19 = F_118 ( V_195 ) ;
if ( ! V_19 ) {
V_7 = - V_104 ;
goto V_245;
}
V_195 -> V_231 . V_246 = & V_261 -> V_215 ;
V_195 -> V_231 . V_247 = 1 ;
V_195 -> V_231 . V_248 = F_142 ;
V_195 -> V_231 . V_249 = F_145 ;
V_195 -> V_231 . V_250 = F_146 ;
V_19 -> V_195 = V_195 ;
V_19 -> V_48 = V_47 -> V_193 . V_2 ;
V_209 = F_155 ( V_259 ) ;
if ( V_209 )
snprintf ( V_216 , sizeof( V_216 ) , L_29 ,
V_209 -> V_229 -> V_192 , V_209 -> V_224 ) ;
else
snprintf ( V_216 , sizeof( V_216 ) , L_33 ,
F_156 ( V_259 ) ) ;
V_19 -> V_6 = F_129 ( & V_225 , V_216 , L_30 , V_19 ) ;
if ( F_130 ( V_19 -> V_6 ) ) {
V_7 = F_131 ( V_19 -> V_6 ) ;
goto V_226;
}
V_7 = F_150 ( & V_47 -> V_193 , & V_195 -> V_231 ) ;
if ( ! V_7 )
return 0 ;
V_226:
V_19 -> V_6 = NULL ;
F_151 ( V_195 -> V_53 ) ;
V_245:
F_117 ( V_195 -> V_53 ) ;
V_244:
F_152 ( V_47 -> V_193 . V_2 , V_195 ) ;
F_4 ( V_47 -> V_193 . V_2 , L_32 , V_7 ) ;
return V_7 ;
}
static void F_157 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = V_47 -> V_193 . V_2 ;
struct V_257 * V_265 = V_2 -> V_266 ;
struct V_257 * V_267 = NULL , * V_268 ;
unsigned int V_28 ;
for ( V_28 = 0 ; ; V_28 ++ ) {
V_267 = F_158 ( V_265 , V_267 ) ;
if ( ! V_267 )
break;
V_268 = F_159 ( V_267 ) ;
if ( ! V_268 ) {
F_160 ( V_2 , L_34 ,
F_156 ( V_267 ) ) ;
continue;
}
if ( ! V_28 )
F_154 ( V_47 , V_267 , V_268 -> V_48 ) ;
F_161 ( V_267 ) ;
F_161 ( V_268 ) ;
if ( V_28 ) {
F_4 ( V_2 , L_35 ) ;
break;
}
}
}
static inline void F_157 ( struct V_46 * V_47 ) { }
static int F_109 ( struct V_46 * V_47 ,
struct V_18 * V_19 )
{
struct V_128 * V_129 = F_68 ( V_19 ) ;
struct V_210 * V_211 = & V_129 -> V_212 ;
struct V_1 * V_228 = NULL ;
int V_7 ;
F_162 ( V_19 -> V_53 , L_36 , F_163 ( V_19 -> V_53 ) ) ;
V_7 = F_164 ( & V_19 -> V_139 , 16 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_165 ( V_19 ) ;
if ( V_7 < 0 )
goto V_269;
if ( V_211 -> V_222 ) {
V_7 = F_126 ( V_19 , V_129 ) ;
if ( V_7 < 0 && V_7 != - V_218 )
goto V_117;
} else if ( ! V_211 -> V_270 || ! V_211 -> V_271 ) {
V_7 = - V_64 ;
goto V_117;
} else {
F_58 ( & V_47 -> V_114 ) ;
V_7 = V_47 -> V_62 -> V_115 ( V_47 ) ;
F_59 ( & V_47 -> V_114 ) ;
if ( V_7 < 0 )
goto V_117;
if ( V_211 -> V_272 )
V_7 = F_166 ( V_211 -> V_272 ) ;
V_7 = V_211 -> V_270 ( V_19 ) ;
if ( V_7 < 0 )
goto V_273;
V_228 = F_67 ( V_19 ) ;
if ( ! V_228 || ! V_228 -> V_162 || ! F_167 ( V_228 ) ||
! F_66 ( V_228 -> V_162 -> V_123 ) ) {
V_211 -> V_271 ( V_19 ) ;
V_7 = - V_25 ;
goto V_274;
}
}
F_58 ( & V_47 -> V_125 ) ;
V_7 = F_121 ( V_19 ) ;
F_59 ( & V_47 -> V_125 ) ;
if ( V_7 < 0 )
goto V_275;
return 0 ;
V_275:
if ( V_211 -> V_222 ) {
F_137 ( V_19 ) ;
} else {
V_211 -> V_271 ( V_19 ) ;
F_73 ( V_228 -> V_162 -> V_123 ) ;
V_274:
V_273:
F_58 ( & V_47 -> V_114 ) ;
V_47 -> V_62 -> V_118 ( V_47 ) ;
F_59 ( & V_47 -> V_114 ) ;
}
V_117:
F_168 ( V_19 -> V_120 ) ;
V_19 -> V_120 = NULL ;
if ( V_19 -> V_120 ) {
F_168 ( V_19 -> V_120 ) ;
V_19 -> V_120 = NULL ;
}
V_269:
F_169 ( & V_19 -> V_139 ) ;
return V_7 ;
}
static int F_170 ( struct V_18 * V_19 )
{
struct V_128 * V_129 = F_68 ( V_19 ) ;
struct V_119 * V_120 = V_19 -> V_120 ;
F_169 ( & V_19 -> V_139 ) ;
if ( V_120 ) {
F_171 ( V_120 ) ;
V_19 -> V_120 = NULL ;
}
if ( V_129 -> V_212 . V_222 ) {
F_137 ( V_19 ) ;
} else {
struct V_1 * V_2 = F_67 ( V_19 ) ;
struct V_276 * V_277 = V_2 ? V_2 -> V_162 : NULL ;
if ( V_277 ) {
V_129 -> V_212 . V_271 ( V_19 ) ;
F_73 ( V_277 -> V_123 ) ;
}
}
if ( V_19 -> V_29 )
F_55 ( V_19 ) ;
if ( V_19 -> V_6 ) {
F_134 ( V_19 -> V_6 ) ;
V_19 -> V_6 = NULL ;
}
if ( V_19 -> V_195 )
F_172 ( V_19 -> V_195 -> V_53 ) ;
return 0 ;
}
static int F_173 ( struct V_18 * V_19 ,
struct V_167 * V_75 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_76 , V_168 , V_75 ) ;
}
static int F_174 ( struct V_18 * V_19 , struct V_169 * V_75 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_76 , V_278 , V_75 ) ;
}
static int F_175 ( struct V_18 * V_19 , const struct V_169 * V_75 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_76 , V_279 , V_75 ) ;
}
static int F_176 ( struct V_18 * V_19 ,
struct V_188 * V_280 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_76 , V_281 , V_280 ) ;
}
static int F_177 ( struct V_18 * V_19 ,
struct V_188 * V_280 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_76 , V_282 , V_280 ) ;
}
static int F_178 ( struct V_18 * V_19 ,
struct V_80 * V_81 )
{
int V_7 ;
struct V_20 * V_21 = F_13 ( V_19 ) ;
const struct V_26 * V_49 ;
T_7 V_283 = V_81 -> V_284 ;
struct V_80 V_285 = * V_81 ;
V_49 = F_16 ( V_19 , V_283 ) ;
if ( ! V_49 )
return - V_64 ;
V_285 . V_284 = V_49 -> V_100 ;
V_7 = F_14 ( V_21 , V_76 , V_82 , & V_285 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_81 = V_285 ;
V_81 -> V_284 = V_283 ;
return 0 ;
}
int F_179 ( struct V_46 * V_47 )
{
struct V_46 * V_286 ;
int V_7 ;
if ( ! V_47 || ! V_47 -> V_62 ||
! V_47 -> V_62 -> V_63 ||
! V_47 -> V_62 -> V_108 ||
! V_47 -> V_62 -> V_113 ||
! V_47 -> V_62 -> V_164 ||
( ( ! V_47 -> V_62 -> V_87 ||
! V_47 -> V_62 -> V_89 ) &&
! V_47 -> V_62 -> V_137 ) ||
! V_47 -> V_62 -> V_115 ||
! V_47 -> V_62 -> V_118 ||
! V_47 -> V_62 -> V_153 ||
! V_47 -> V_193 . V_2 )
return - V_64 ;
if ( ! V_47 -> V_62 -> V_177 )
V_47 -> V_62 -> V_177 = F_175 ;
if ( ! V_47 -> V_62 -> V_170 )
V_47 -> V_62 -> V_170 = F_174 ;
if ( ! V_47 -> V_62 -> V_168 )
V_47 -> V_62 -> V_168 = F_173 ;
if ( ! V_47 -> V_62 -> V_190 )
V_47 -> V_62 -> V_190 = F_177 ;
if ( ! V_47 -> V_62 -> V_189 )
V_47 -> V_62 -> V_189 = F_176 ;
if ( ! V_47 -> V_62 -> V_82 )
V_47 -> V_62 -> V_82 = F_178 ;
F_58 ( & V_121 ) ;
F_108 (ix, &hosts, list) {
if ( V_286 -> V_192 == V_47 -> V_192 ) {
V_7 = - V_86 ;
goto V_287;
}
}
V_7 = F_180 ( V_47 -> V_193 . V_2 , & V_47 -> V_193 ) ;
if ( V_7 < 0 )
goto V_287;
F_181 ( & V_47 -> V_288 , & V_289 ) ;
F_59 ( & V_121 ) ;
F_182 ( & V_47 -> V_125 ) ;
F_182 ( & V_47 -> V_114 ) ;
if ( V_47 -> V_193 . V_2 -> V_266 )
F_157 ( V_47 ) ;
else if ( V_47 -> V_256 )
F_153 ( V_47 ) ;
else
F_107 ( V_47 ) ;
return 0 ;
V_287:
F_59 ( & V_121 ) ;
return V_7 ;
}
void F_183 ( struct V_46 * V_47 )
{
struct V_18 * V_19 , * V_290 ;
struct V_194 * V_195 ;
F_184 ( V_291 ) ;
F_58 ( & V_121 ) ;
F_185 ( & V_47 -> V_288 ) ;
F_108 (icd, &devices, list)
if ( V_19 -> V_191 == V_47 -> V_192 && V_19 -> V_195 ) {
F_186 ( V_19 -> V_53 ) ;
F_187 ( & V_19 -> V_195 -> V_288 , & V_291 ) ;
}
F_59 ( & V_121 ) ;
F_108 (sasc, &notifiers, list) {
F_188 ( & V_195 -> V_231 ) ;
F_189 ( & V_195 -> V_53 -> V_2 ) ;
}
F_58 ( & V_121 ) ;
F_190 (icd, tmp, &devices, list)
if ( V_19 -> V_191 == V_47 -> V_192 )
F_170 ( V_19 ) ;
F_59 ( & V_121 ) ;
F_191 ( & V_47 -> V_193 ) ;
}
static int F_192 ( struct V_18 * V_19 )
{
struct V_18 * V_286 ;
int V_292 = - 1 , V_28 ;
F_58 ( & V_121 ) ;
for ( V_28 = 0 ; V_28 < 256 && V_292 < 0 ; V_28 ++ ) {
V_292 = V_28 ;
F_108 (ix, &devices, list) {
if ( V_286 -> V_191 == V_19 -> V_191 && V_286 -> V_293 == V_28 ) {
V_292 = - 1 ;
break;
}
}
}
if ( V_292 < 0 ) {
F_59 ( & V_121 ) ;
return - V_104 ;
}
V_19 -> V_293 = V_292 ;
V_19 -> V_127 = 0 ;
V_19 -> V_294 = NULL ;
V_28 = F_193 ( V_19 -> V_53 ) -> V_295 ;
if ( V_28 < 0 )
V_28 = 0 ;
if ( V_28 >= V_198 ) {
F_59 ( & V_121 ) ;
return - V_86 ;
}
F_114 ( V_28 , V_197 ) ;
F_181 ( & V_19 -> V_288 , & V_296 ) ;
F_59 ( & V_121 ) ;
return 0 ;
}
static int F_165 ( struct V_18 * V_19 )
{
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
struct V_119 * V_120 = F_194 () ;
if ( ! V_120 )
return - V_104 ;
F_91 ( V_120 -> V_74 , V_47 -> V_163 , sizeof( V_120 -> V_74 ) ) ;
V_120 -> V_193 = & V_47 -> V_193 ;
V_120 -> V_297 = & V_298 ;
V_120 -> V_299 = & V_300 ;
V_120 -> V_301 = F_168 ;
V_120 -> V_139 = & V_19 -> V_139 ;
V_120 -> V_302 = & V_47 -> V_125 ;
V_19 -> V_120 = V_120 ;
return 0 ;
}
static int F_125 ( struct V_18 * V_19 )
{
const struct V_303 * type = V_19 -> V_120 -> V_2 . type ;
int V_7 ;
if ( ! V_19 -> V_48 )
return - V_25 ;
F_195 ( V_19 -> V_120 , V_19 ) ;
if ( V_19 -> V_120 -> V_203 == 0 ) {
F_196 ( V_19 -> V_120 , V_304 ) ;
F_196 ( V_19 -> V_120 , V_305 ) ;
F_196 ( V_19 -> V_120 , V_306 ) ;
}
V_7 = F_197 ( V_19 -> V_120 , V_307 , - 1 ) ;
if ( V_7 < 0 ) {
F_4 ( V_19 -> V_53 , L_37 , V_7 ) ;
return V_7 ;
}
V_19 -> V_120 -> V_2 . type = type ;
return 0 ;
}
static int F_198 ( struct V_196 * V_53 )
{
struct V_128 * V_129 = V_53 -> V_2 . V_223 ;
struct V_3 * V_4 = & V_129 -> V_130 ;
struct V_18 * V_19 ;
int V_7 ;
if ( ! V_129 )
return - V_64 ;
V_19 = F_148 ( & V_53 -> V_2 , sizeof( * V_19 ) , V_220 ) ;
if ( ! V_19 )
return - V_104 ;
V_7 = F_11 ( & V_53 -> V_2 , V_4 -> V_11 . V_12 ,
V_4 -> V_11 . V_13 ) ;
if ( V_7 < 0 )
return V_7 ;
V_19 -> V_191 = V_129 -> V_212 . V_238 ;
V_19 -> V_129 = V_129 ;
V_19 -> V_53 = & V_53 -> V_2 ;
F_199 ( V_53 , V_19 ) ;
V_19 -> V_109 = V_308 ;
V_19 -> V_110 = V_309 ;
return F_192 ( V_19 ) ;
}
static int F_200 ( struct V_196 * V_53 )
{
struct V_18 * V_19 = F_120 ( V_53 ) ;
int V_28 ;
if ( ! V_19 )
return - V_64 ;
V_28 = V_53 -> V_295 ;
if ( V_28 < 0 )
V_28 = 0 ;
if ( F_201 ( V_28 , V_197 ) ) {
F_202 ( V_28 , V_197 ) ;
F_185 ( & V_19 -> V_288 ) ;
}
return 0 ;
}

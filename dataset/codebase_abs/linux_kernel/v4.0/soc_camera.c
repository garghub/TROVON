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
static int F_84 ( struct V_66 * V_66 , void * V_67 ,
struct V_45 * V_34 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
int V_7 ;
F_26 ( V_67 != V_66 -> V_68 ) ;
if ( V_34 -> type != V_69 ) {
F_85 ( V_19 -> V_53 , L_21 , V_34 -> type ) ;
return - V_64 ;
}
if ( V_19 -> V_85 && V_19 -> V_85 != V_66 )
return - V_86 ;
if ( F_86 ( F_19 ( V_19 -> V_48 ) , V_19 ) ) {
F_4 ( V_19 -> V_53 , L_22 ) ;
return - V_86 ;
}
V_7 = F_56 ( V_19 , V_34 ) ;
if ( ! V_7 && ! V_19 -> V_85 )
V_19 -> V_85 = V_66 ;
return V_7 ;
}
static int F_87 ( struct V_66 * V_66 , void * V_67 ,
struct V_154 * V_34 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
const struct V_155 * V_156 ;
F_26 ( V_67 != V_66 -> V_68 ) ;
if ( V_34 -> V_72 >= V_19 -> V_29 )
return - V_64 ;
V_156 = V_19 -> V_30 [ V_34 -> V_72 ] . V_31 ;
if ( V_156 -> V_74 )
F_88 ( V_34 -> V_157 , V_156 -> V_74 , sizeof( V_34 -> V_157 ) ) ;
V_34 -> V_54 = V_156 -> V_27 ;
return 0 ;
}
static int F_89 ( struct V_66 * V_66 , void * V_67 ,
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
static int F_90 ( struct V_66 * V_66 , void * V_67 ,
struct V_158 * V_159 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
F_26 ( V_67 != V_66 -> V_68 ) ;
F_88 ( V_159 -> V_160 , V_47 -> V_161 , sizeof( V_159 -> V_160 ) ) ;
return V_47 -> V_62 -> V_162 ( V_47 , V_159 ) ;
}
static int F_91 ( struct V_66 * V_66 , void * V_67 ,
enum V_163 V_28 )
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
V_7 = F_92 ( & V_19 -> V_88 ) ;
else
V_7 = F_93 ( & V_19 -> V_90 , V_28 ) ;
if ( ! V_7 )
F_14 ( V_21 , V_76 , V_164 , 1 ) ;
return V_7 ;
}
static int F_94 ( struct V_66 * V_66 , void * V_67 ,
enum V_163 V_28 )
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
F_95 ( & V_19 -> V_88 ) ;
else
F_96 ( & V_19 -> V_90 , V_28 ) ;
F_14 ( V_21 , V_76 , V_164 , 0 ) ;
return 0 ;
}
static int F_97 ( struct V_66 * V_66 , void * V_79 ,
struct V_165 * V_75 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
return V_47 -> V_62 -> V_166 ( V_19 , V_75 ) ;
}
static int F_98 ( struct V_66 * V_66 , void * V_79 ,
struct V_167 * V_75 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
int V_7 ;
V_7 = V_47 -> V_62 -> V_168 ( V_19 , V_75 ) ;
return V_7 ;
}
static int F_99 ( struct V_66 * V_66 , void * V_79 ,
const struct V_167 * V_75 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
const struct V_169 * V_170 = & V_75 -> V_171 ;
struct V_167 V_172 ;
int V_7 ;
if ( V_75 -> type != V_69 )
return - V_64 ;
F_20 ( V_19 -> V_53 , L_24 ,
V_170 -> V_55 , V_170 -> V_56 , V_170 -> V_173 , V_170 -> V_174 ) ;
V_172 . type = V_75 -> type ;
V_7 = V_47 -> V_62 -> V_168 ( V_19 , & V_172 ) ;
if ( V_7 < 0 ) {
F_4 ( V_19 -> V_53 ,
L_25 ) ;
} else if ( ( V_75 -> V_171 . V_55 == V_172 . V_171 . V_55 &&
V_75 -> V_171 . V_56 == V_172 . V_171 . V_56 ) ||
! F_86 ( V_47 , V_19 ) ) {
V_7 = V_47 -> V_62 -> V_175 ( V_19 , V_75 ) ;
} else if ( V_47 -> V_62 -> V_176 ) {
V_7 = V_47 -> V_62 -> V_176 ( V_19 , V_75 ) ;
} else {
F_4 ( V_19 -> V_53 ,
L_26 ) ;
V_7 = - V_86 ;
}
return V_7 ;
}
static int F_100 ( struct V_66 * V_66 , void * V_79 ,
struct V_177 * V_178 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
if ( V_178 -> type != V_69 )
return - V_64 ;
if ( ! V_47 -> V_62 -> V_179 )
return - V_180 ;
return V_47 -> V_62 -> V_179 ( V_19 , V_178 ) ;
}
static int F_101 ( struct V_66 * V_66 , void * V_79 ,
struct V_177 * V_178 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
int V_7 ;
if ( V_178 -> type != V_69 ||
( V_178 -> V_181 != V_182 &&
V_178 -> V_181 != V_183 ) )
return - V_64 ;
if ( V_178 -> V_181 == V_182 ) {
if ( F_86 ( V_47 , V_19 ) &&
( V_19 -> V_109 != V_178 -> V_184 . V_55 ||
V_19 -> V_110 != V_178 -> V_184 . V_56 ) )
return - V_86 ;
if ( V_19 -> V_85 && V_19 -> V_85 != V_66 )
return - V_86 ;
}
if ( ! V_47 -> V_62 -> V_185 )
return - V_180 ;
V_7 = V_47 -> V_62 -> V_185 ( V_19 , V_178 ) ;
if ( ! V_7 &&
V_178 -> V_181 == V_182 ) {
V_19 -> V_109 = V_178 -> V_184 . V_55 ;
V_19 -> V_110 = V_178 -> V_184 . V_56 ;
if ( ! V_19 -> V_85 )
V_19 -> V_85 = V_66 ;
}
return V_7 ;
}
static int F_102 ( struct V_66 * V_66 , void * V_79 ,
struct V_186 * V_75 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
if ( V_47 -> V_62 -> V_187 )
return V_47 -> V_62 -> V_187 ( V_19 , V_75 ) ;
return - V_24 ;
}
static int F_103 ( struct V_66 * V_66 , void * V_79 ,
struct V_186 * V_75 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
if ( V_47 -> V_62 -> V_188 )
return V_47 -> V_62 -> V_188 ( V_19 , V_75 ) ;
return - V_24 ;
}
static void F_104 ( struct V_46 * V_47 )
{
struct V_18 * V_19 ;
F_58 ( & V_121 ) ;
F_105 (icd, &devices, list)
if ( V_19 -> V_189 == V_47 -> V_190 ) {
struct V_128 * V_129 = F_68 ( V_19 ) ;
struct V_3 * V_4 = & V_129 -> V_130 ;
if ( V_4 -> V_131 )
V_4 -> V_131 ( V_19 -> V_53 ) ;
V_19 -> V_48 = V_47 -> V_191 . V_2 ;
F_106 ( V_47 , V_19 ) ;
}
F_59 ( & V_121 ) ;
}
static int F_107 ( struct V_5 * V_6 )
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
static void F_108 ( struct V_5 * V_6 )
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
static int F_109 ( struct V_128 * V_129 ,
struct V_192 * V_193 )
{
struct V_194 * V_53 ;
int V_7 , V_28 ;
F_58 ( & V_121 ) ;
V_28 = F_110 ( V_195 , V_196 ) ;
if ( V_28 < V_196 )
F_111 ( V_28 , V_195 ) ;
F_59 ( & V_121 ) ;
if ( V_28 >= V_196 )
return - V_104 ;
V_53 = F_112 ( L_27 , V_28 ) ;
if ( ! V_53 )
return - V_104 ;
V_7 = F_113 ( V_53 , V_129 , sizeof( * V_129 ) ) ;
if ( V_7 < 0 ) {
F_114 ( V_53 ) ;
return V_7 ;
}
V_193 -> V_53 = V_53 ;
return 0 ;
}
static struct V_18 * F_115 ( struct V_192 * V_193 )
{
struct V_194 * V_53 = V_193 -> V_53 ;
int V_7 ;
V_7 = F_116 ( V_53 ) ;
if ( V_7 < 0 || ! V_53 -> V_2 . V_160 )
return NULL ;
return F_117 ( V_53 ) ;
}
static int F_118 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
struct V_197 V_198 ;
int V_7 ;
V_21 -> V_199 = F_119 ( V_19 ) ;
F_120 ( V_21 , V_19 ) ;
F_14 ( V_21 , V_76 , V_200 , & V_19 -> V_120 -> V_201 ) ;
V_7 = F_121 ( & V_19 -> V_139 , V_21 -> V_139 , NULL ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_57 ( V_19 ) ;
if ( V_7 < 0 ) {
F_4 ( V_19 -> V_53 , L_13 , V_7 ) ;
return V_7 ;
}
V_7 = F_51 ( V_19 ) ;
if ( V_7 < 0 )
goto V_202;
V_19 -> V_112 = V_203 ;
V_7 = F_122 ( V_19 ) ;
if ( V_7 < 0 )
goto V_204;
if ( ! F_14 ( V_21 , V_76 , V_205 , & V_198 ) ) {
V_19 -> V_109 = V_198 . V_55 ;
V_19 -> V_110 = V_198 . V_56 ;
V_19 -> V_111 = V_198 . V_111 ;
V_19 -> V_112 = V_198 . V_112 ;
}
F_60 ( V_19 ) ;
return 0 ;
V_204:
F_55 ( V_19 ) ;
V_202:
F_60 ( V_19 ) ;
return V_7 ;
}
static int F_123 ( struct V_18 * V_19 ,
struct V_128 * V_129 )
{
struct V_3 * V_4 ;
struct V_206 * V_207 ;
struct V_46 * V_47 ;
struct V_208 * V_209 = & V_129 -> V_210 ;
struct V_211 * V_212 ;
struct V_20 * V_213 ;
char V_214 [ V_215 ] ;
int V_7 ;
if ( V_19 -> V_193 ) {
return - V_216 ;
}
V_47 = F_19 ( V_19 -> V_48 ) ;
V_212 = F_124 ( V_209 -> V_217 ) ;
if ( ! V_212 ) {
F_4 ( V_19 -> V_53 , L_28 ,
V_209 -> V_217 ) ;
return - V_25 ;
}
V_4 = F_125 ( & V_129 -> V_130 , sizeof( * V_4 ) , V_218 ) ;
if ( ! V_4 ) {
V_7 = - V_104 ;
goto V_219;
}
V_4 -> V_11 . V_12 = 0 ;
V_4 -> V_11 . V_13 = NULL ;
V_209 -> V_220 -> V_221 = V_4 ;
snprintf ( V_214 , sizeof( V_214 ) , L_29 ,
V_209 -> V_217 , V_209 -> V_220 -> V_222 ) ;
V_19 -> V_6 = F_126 ( & V_223 , V_214 , L_30 , V_19 ) ;
if ( F_127 ( V_19 -> V_6 ) ) {
V_7 = F_128 ( V_19 -> V_6 ) ;
goto V_224;
}
V_213 = F_129 ( & V_47 -> V_191 , V_212 ,
V_209 -> V_220 , NULL ) ;
if ( ! V_213 ) {
V_7 = - V_25 ;
goto V_225;
}
V_207 = F_130 ( V_213 ) ;
V_19 -> V_226 = & V_207 -> V_2 ;
return 0 ;
V_225:
F_131 ( V_19 -> V_6 ) ;
V_19 -> V_6 = NULL ;
V_224:
F_132 ( V_4 ) ;
V_219:
F_133 ( V_212 ) ;
return V_7 ;
}
static void F_134 ( struct V_18 * V_19 )
{
struct V_206 * V_207 =
F_135 ( F_67 ( V_19 ) ) ;
struct V_211 * V_212 ;
struct V_3 * V_4 ;
V_19 -> V_226 = NULL ;
if ( V_19 -> V_193 )
return;
V_212 = V_207 -> V_227 ;
V_4 = V_207 -> V_2 . V_221 ;
F_136 ( F_137 ( V_207 ) ) ;
F_138 ( V_207 ) ;
F_133 ( V_212 ) ;
F_132 ( V_4 ) ;
F_131 ( V_19 -> V_6 ) ;
V_19 -> V_6 = NULL ;
}
static int F_139 ( struct V_228 * V_229 ,
struct V_20 * V_21 ,
struct V_230 * V_231 )
{
struct V_192 * V_193 = F_140 ( V_229 ,
struct V_192 , V_229 ) ;
struct V_18 * V_19 = F_117 ( V_193 -> V_53 ) ;
if ( V_231 == V_193 -> V_232 && ! F_26 ( V_19 -> V_226 ) ) {
struct V_206 * V_207 = F_130 ( V_21 ) ;
if ( V_207 ) {
struct V_128 * V_129 = F_68 ( V_19 ) ;
struct V_3 * V_4 =
F_141 ( V_207 ) ;
if ( V_4 ) {
memcpy ( & V_129 -> V_130 , V_4 ,
sizeof( V_129 -> V_130 ) ) ;
if ( V_4 -> V_131 )
V_4 -> V_131 ( V_19 -> V_53 ) ;
}
V_19 -> V_226 = & V_207 -> V_2 ;
}
}
return 0 ;
}
static void F_142 ( struct V_228 * V_229 ,
struct V_20 * V_21 ,
struct V_230 * V_231 )
{
struct V_192 * V_193 = F_140 ( V_229 ,
struct V_192 , V_229 ) ;
struct V_18 * V_19 = F_117 ( V_193 -> V_53 ) ;
if ( V_19 -> V_6 ) {
F_131 ( V_19 -> V_6 ) ;
V_19 -> V_6 = NULL ;
}
}
static int F_143 ( struct V_228 * V_229 )
{
struct V_192 * V_193 = F_140 ( V_229 ,
struct V_192 , V_229 ) ;
struct V_18 * V_19 = F_117 ( V_193 -> V_53 ) ;
if ( F_67 ( V_19 ) ) {
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
int V_7 ;
F_58 ( & V_121 ) ;
V_7 = F_106 ( V_47 , V_19 ) ;
F_59 ( & V_121 ) ;
if ( V_7 < 0 )
return V_7 ;
}
return 0 ;
}
static int F_144 ( struct V_46 * V_47 ,
struct V_230 * * V_231 , unsigned int V_233 )
{
struct V_234 * V_235 ;
struct V_192 * V_193 ;
struct V_18 * V_19 ;
struct V_128 V_129 = { . V_210 . V_236 = V_47 -> V_190 ,} ;
char V_214 [ V_215 ] ;
unsigned int V_28 ;
int V_7 ;
for ( V_28 = 0 ; V_28 < V_233 ; V_28 ++ ) {
V_235 = F_140 ( V_231 [ V_28 ] , struct V_234 , V_231 ) ;
if ( V_235 -> V_237 == V_238 )
break;
}
if ( V_28 >= V_233 || V_231 [ V_28 ] -> V_239 != V_240 ) {
F_4 ( V_47 -> V_191 . V_2 , L_31 ) ;
return - V_25 ;
}
V_193 = F_145 ( V_47 -> V_191 . V_2 , sizeof( * V_193 ) , V_218 ) ;
if ( ! V_193 )
return - V_104 ;
V_129 . V_210 . V_220 = F_146 ( - V_241 ) ;
V_7 = F_109 ( & V_129 , V_193 ) ;
if ( V_7 < 0 )
goto V_242;
V_193 -> V_232 = & V_235 -> V_231 ;
V_19 = F_115 ( V_193 ) ;
if ( ! V_19 ) {
V_7 = - V_104 ;
goto V_243;
}
V_193 -> V_229 . V_244 = V_231 ;
V_193 -> V_229 . V_245 = V_233 ;
V_193 -> V_229 . V_246 = F_139 ;
V_193 -> V_229 . V_247 = F_142 ;
V_193 -> V_229 . V_248 = F_143 ;
V_19 -> V_193 = V_193 ;
V_19 -> V_48 = V_47 -> V_191 . V_2 ;
snprintf ( V_214 , sizeof( V_214 ) , L_29 ,
V_235 -> V_231 . V_249 . V_250 . V_251 , V_235 -> V_231 . V_249 . V_250 . V_252 ) ;
V_19 -> V_6 = F_126 ( & V_223 , V_214 , L_30 , V_19 ) ;
if ( F_127 ( V_19 -> V_6 ) ) {
V_7 = F_128 ( V_19 -> V_6 ) ;
goto V_224;
}
V_7 = F_147 ( & V_47 -> V_191 , & V_193 -> V_229 ) ;
if ( ! V_7 )
return 0 ;
F_131 ( V_19 -> V_6 ) ;
V_224:
V_19 -> V_6 = NULL ;
F_148 ( V_193 -> V_53 ) ;
V_243:
F_114 ( V_193 -> V_53 ) ;
V_242:
F_149 ( V_47 -> V_191 . V_2 , V_193 ) ;
F_4 ( V_47 -> V_191 . V_2 , L_32 , V_7 ) ;
return V_7 ;
}
static void F_150 ( struct V_46 * V_47 )
{
struct V_230 * * V_231 ;
int V_253 ;
for ( V_253 = 0 , V_231 = V_47 -> V_231 ; V_47 -> V_254 [ V_253 ] ; V_253 ++ ) {
F_144 ( V_47 , V_231 , V_47 -> V_254 [ V_253 ] ) ;
V_231 += V_47 -> V_254 [ V_253 ] ;
}
}
static int F_151 ( struct V_46 * V_47 ,
struct V_255 * V_256 ,
struct V_255 * V_257 )
{
struct V_18 * V_19 ;
struct V_128 V_129 = { . V_210 . V_236 = V_47 -> V_190 ,} ;
struct V_192 * V_193 ;
struct V_258 * V_259 ;
struct V_206 * V_207 ;
char V_214 [ V_215 ] ;
int V_7 ;
V_259 = F_145 ( V_47 -> V_191 . V_2 , sizeof( struct V_258 ) ,
V_218 ) ;
if ( ! V_259 )
return - V_104 ;
V_259 -> V_235 . V_231 . V_249 . V_260 . V_261 = V_257 ;
V_259 -> V_235 . V_231 . V_239 = V_262 ;
V_259 -> V_213 = & V_259 -> V_235 . V_231 ;
V_193 = & V_259 -> V_193 ;
V_129 . V_210 . V_220 = F_146 ( - V_241 ) ;
V_7 = F_109 ( & V_129 , V_193 ) ;
if ( V_7 < 0 )
goto V_242;
V_193 -> V_232 = & V_259 -> V_235 . V_231 ;
V_19 = F_115 ( V_193 ) ;
if ( ! V_19 ) {
V_7 = - V_104 ;
goto V_243;
}
V_193 -> V_229 . V_244 = & V_259 -> V_213 ;
V_193 -> V_229 . V_245 = 1 ;
V_193 -> V_229 . V_246 = F_139 ;
V_193 -> V_229 . V_247 = F_142 ;
V_193 -> V_229 . V_248 = F_143 ;
V_19 -> V_193 = V_193 ;
V_19 -> V_48 = V_47 -> V_191 . V_2 ;
V_207 = F_152 ( V_257 ) ;
if ( V_207 )
snprintf ( V_214 , sizeof( V_214 ) , L_29 ,
V_207 -> V_227 -> V_190 , V_207 -> V_222 ) ;
else
snprintf ( V_214 , sizeof( V_214 ) , L_33 ,
F_153 ( V_257 ) ) ;
V_19 -> V_6 = F_126 ( & V_223 , V_214 , L_30 , V_19 ) ;
if ( F_127 ( V_19 -> V_6 ) ) {
V_7 = F_128 ( V_19 -> V_6 ) ;
goto V_224;
}
V_7 = F_147 ( & V_47 -> V_191 , & V_193 -> V_229 ) ;
if ( ! V_7 )
return 0 ;
V_224:
V_19 -> V_6 = NULL ;
F_148 ( V_193 -> V_53 ) ;
V_243:
F_114 ( V_193 -> V_53 ) ;
V_242:
F_149 ( V_47 -> V_191 . V_2 , V_259 ) ;
F_4 ( V_47 -> V_191 . V_2 , L_32 , V_7 ) ;
return V_7 ;
}
static void F_154 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = V_47 -> V_191 . V_2 ;
struct V_255 * V_263 = V_2 -> V_264 ;
struct V_255 * V_265 = NULL , * V_266 ;
unsigned int V_28 ;
for ( V_28 = 0 ; ; V_28 ++ ) {
V_265 = F_155 ( V_263 , V_265 ) ;
if ( ! V_265 )
break;
V_266 = F_156 ( V_265 ) ;
if ( ! V_266 ) {
F_157 ( V_2 , L_34 ,
F_153 ( V_265 ) ) ;
continue;
}
if ( ! V_28 )
F_151 ( V_47 , V_265 , V_266 -> V_48 ) ;
F_158 ( V_265 ) ;
F_158 ( V_266 ) ;
if ( V_28 ) {
F_4 ( V_2 , L_35 ) ;
break;
}
}
}
static inline void F_154 ( struct V_46 * V_47 ) { }
static int F_106 ( struct V_46 * V_47 ,
struct V_18 * V_19 )
{
struct V_128 * V_129 = F_68 ( V_19 ) ;
struct V_208 * V_209 = & V_129 -> V_210 ;
struct V_1 * V_226 = NULL ;
int V_7 ;
F_159 ( V_19 -> V_53 , L_36 , F_160 ( V_19 -> V_53 ) ) ;
V_7 = F_161 ( & V_19 -> V_139 , 16 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_162 ( V_19 ) ;
if ( V_7 < 0 )
goto V_267;
if ( V_209 -> V_220 ) {
V_7 = F_123 ( V_19 , V_129 ) ;
if ( V_7 < 0 && V_7 != - V_216 )
goto V_117;
} else if ( ! V_209 -> V_268 || ! V_209 -> V_269 ) {
V_7 = - V_64 ;
goto V_117;
} else {
F_58 ( & V_47 -> V_114 ) ;
V_7 = V_47 -> V_62 -> V_115 ( V_47 ) ;
F_59 ( & V_47 -> V_114 ) ;
if ( V_7 < 0 )
goto V_117;
if ( V_209 -> V_270 )
V_7 = F_163 ( V_209 -> V_270 ) ;
V_7 = V_209 -> V_268 ( V_19 ) ;
if ( V_7 < 0 )
goto V_271;
V_226 = F_67 ( V_19 ) ;
if ( ! V_226 || ! V_226 -> V_160 || ! F_164 ( V_226 ) ||
! F_66 ( V_226 -> V_160 -> V_123 ) ) {
V_209 -> V_269 ( V_19 ) ;
V_7 = - V_25 ;
goto V_272;
}
}
F_58 ( & V_47 -> V_125 ) ;
V_7 = F_118 ( V_19 ) ;
F_59 ( & V_47 -> V_125 ) ;
if ( V_7 < 0 )
goto V_273;
return 0 ;
V_273:
if ( V_209 -> V_220 ) {
F_134 ( V_19 ) ;
} else {
V_209 -> V_269 ( V_19 ) ;
F_73 ( V_226 -> V_160 -> V_123 ) ;
V_272:
V_271:
F_58 ( & V_47 -> V_114 ) ;
V_47 -> V_62 -> V_118 ( V_47 ) ;
F_59 ( & V_47 -> V_114 ) ;
}
V_117:
if ( V_19 -> V_120 ) {
F_165 ( V_19 -> V_120 ) ;
V_19 -> V_120 = NULL ;
}
V_267:
F_166 ( & V_19 -> V_139 ) ;
return V_7 ;
}
static int F_167 ( struct V_18 * V_19 )
{
struct V_128 * V_129 = F_68 ( V_19 ) ;
struct V_119 * V_120 = V_19 -> V_120 ;
F_166 ( & V_19 -> V_139 ) ;
if ( V_120 ) {
F_168 ( V_120 ) ;
V_19 -> V_120 = NULL ;
}
if ( V_129 -> V_210 . V_220 ) {
F_134 ( V_19 ) ;
} else {
struct V_1 * V_2 = F_67 ( V_19 ) ;
struct V_274 * V_275 = V_2 ? V_2 -> V_160 : NULL ;
if ( V_275 ) {
V_129 -> V_210 . V_269 ( V_19 ) ;
F_73 ( V_275 -> V_123 ) ;
}
}
if ( V_19 -> V_29 )
F_55 ( V_19 ) ;
if ( V_19 -> V_6 ) {
F_131 ( V_19 -> V_6 ) ;
V_19 -> V_6 = NULL ;
}
if ( V_19 -> V_193 )
F_169 ( V_19 -> V_193 -> V_53 ) ;
return 0 ;
}
static int F_170 ( struct V_18 * V_19 ,
struct V_165 * V_75 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_76 , V_166 , V_75 ) ;
}
static int F_171 ( struct V_18 * V_19 , struct V_167 * V_75 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_76 , V_276 , V_75 ) ;
}
static int F_172 ( struct V_18 * V_19 , const struct V_167 * V_75 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_76 , V_277 , V_75 ) ;
}
static int F_173 ( struct V_18 * V_19 ,
struct V_186 * V_278 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_76 , V_279 , V_278 ) ;
}
static int F_174 ( struct V_18 * V_19 ,
struct V_186 * V_278 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_76 , V_280 , V_278 ) ;
}
static int F_175 ( struct V_18 * V_19 ,
struct V_80 * V_81 )
{
int V_7 ;
struct V_20 * V_21 = F_13 ( V_19 ) ;
const struct V_26 * V_49 ;
T_7 V_281 = V_81 -> V_282 ;
struct V_80 V_283 = * V_81 ;
V_49 = F_16 ( V_19 , V_281 ) ;
if ( ! V_49 )
return - V_64 ;
V_283 . V_282 = V_49 -> V_100 ;
V_7 = F_14 ( V_21 , V_76 , V_82 , & V_283 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_81 = V_283 ;
V_81 -> V_282 = V_281 ;
return 0 ;
}
int F_176 ( struct V_46 * V_47 )
{
struct V_46 * V_284 ;
int V_7 ;
if ( ! V_47 || ! V_47 -> V_62 ||
! V_47 -> V_62 -> V_63 ||
! V_47 -> V_62 -> V_108 ||
! V_47 -> V_62 -> V_113 ||
! V_47 -> V_62 -> V_162 ||
( ( ! V_47 -> V_62 -> V_87 ||
! V_47 -> V_62 -> V_89 ) &&
! V_47 -> V_62 -> V_137 ) ||
! V_47 -> V_62 -> V_115 ||
! V_47 -> V_62 -> V_118 ||
! V_47 -> V_62 -> V_153 ||
! V_47 -> V_191 . V_2 )
return - V_64 ;
if ( ! V_47 -> V_62 -> V_175 )
V_47 -> V_62 -> V_175 = F_172 ;
if ( ! V_47 -> V_62 -> V_168 )
V_47 -> V_62 -> V_168 = F_171 ;
if ( ! V_47 -> V_62 -> V_166 )
V_47 -> V_62 -> V_166 = F_170 ;
if ( ! V_47 -> V_62 -> V_188 )
V_47 -> V_62 -> V_188 = F_174 ;
if ( ! V_47 -> V_62 -> V_187 )
V_47 -> V_62 -> V_187 = F_173 ;
if ( ! V_47 -> V_62 -> V_82 )
V_47 -> V_62 -> V_82 = F_175 ;
F_58 ( & V_121 ) ;
F_105 (ix, &hosts, list) {
if ( V_284 -> V_190 == V_47 -> V_190 ) {
V_7 = - V_86 ;
goto V_285;
}
}
V_7 = F_177 ( V_47 -> V_191 . V_2 , & V_47 -> V_191 ) ;
if ( V_7 < 0 )
goto V_285;
F_178 ( & V_47 -> V_286 , & V_287 ) ;
F_59 ( & V_121 ) ;
F_179 ( & V_47 -> V_125 ) ;
F_179 ( & V_47 -> V_114 ) ;
if ( V_47 -> V_191 . V_2 -> V_264 )
F_154 ( V_47 ) ;
else if ( V_47 -> V_254 )
F_150 ( V_47 ) ;
else
F_104 ( V_47 ) ;
return 0 ;
V_285:
F_59 ( & V_121 ) ;
return V_7 ;
}
void F_180 ( struct V_46 * V_47 )
{
struct V_18 * V_19 , * V_288 ;
struct V_192 * V_193 ;
F_181 ( V_289 ) ;
F_58 ( & V_121 ) ;
F_182 ( & V_47 -> V_286 ) ;
F_105 (icd, &devices, list)
if ( V_19 -> V_189 == V_47 -> V_190 && V_19 -> V_193 ) {
F_183 ( V_19 -> V_53 ) ;
F_184 ( & V_19 -> V_193 -> V_286 , & V_289 ) ;
}
F_59 ( & V_121 ) ;
F_105 (sasc, &notifiers, list) {
F_185 ( & V_193 -> V_229 ) ;
F_186 ( & V_193 -> V_53 -> V_2 ) ;
}
F_58 ( & V_121 ) ;
F_187 (icd, tmp, &devices, list)
if ( V_19 -> V_189 == V_47 -> V_190 )
F_167 ( V_19 ) ;
F_59 ( & V_121 ) ;
F_188 ( & V_47 -> V_191 ) ;
}
static int F_189 ( struct V_18 * V_19 )
{
struct V_18 * V_284 ;
int V_290 = - 1 , V_28 ;
F_58 ( & V_121 ) ;
for ( V_28 = 0 ; V_28 < 256 && V_290 < 0 ; V_28 ++ ) {
V_290 = V_28 ;
F_105 (ix, &devices, list) {
if ( V_284 -> V_189 == V_19 -> V_189 && V_284 -> V_291 == V_28 ) {
V_290 = - 1 ;
break;
}
}
}
if ( V_290 < 0 ) {
F_59 ( & V_121 ) ;
return - V_104 ;
}
V_19 -> V_291 = V_290 ;
V_19 -> V_127 = 0 ;
V_19 -> V_292 = NULL ;
V_28 = F_190 ( V_19 -> V_53 ) -> V_293 ;
if ( V_28 < 0 )
V_28 = 0 ;
if ( V_28 >= V_196 ) {
F_59 ( & V_121 ) ;
return - V_86 ;
}
F_111 ( V_28 , V_195 ) ;
F_178 ( & V_19 -> V_286 , & V_294 ) ;
F_59 ( & V_121 ) ;
return 0 ;
}
static int F_162 ( struct V_18 * V_19 )
{
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
struct V_119 * V_120 = F_191 () ;
if ( ! V_120 )
return - V_104 ;
F_88 ( V_120 -> V_74 , V_47 -> V_161 , sizeof( V_120 -> V_74 ) ) ;
V_120 -> V_191 = & V_47 -> V_191 ;
V_120 -> V_295 = & V_296 ;
V_120 -> V_297 = & V_298 ;
V_120 -> V_299 = F_165 ;
V_120 -> V_139 = & V_19 -> V_139 ;
V_120 -> V_300 = & V_47 -> V_125 ;
V_19 -> V_120 = V_120 ;
return 0 ;
}
static int F_122 ( struct V_18 * V_19 )
{
const struct V_301 * type = V_19 -> V_120 -> V_2 . type ;
int V_7 ;
if ( ! V_19 -> V_48 )
return - V_25 ;
F_192 ( V_19 -> V_120 , V_19 ) ;
if ( V_19 -> V_120 -> V_201 == 0 ) {
F_193 ( V_19 -> V_120 , V_302 ) ;
F_193 ( V_19 -> V_120 , V_303 ) ;
F_193 ( V_19 -> V_120 , V_304 ) ;
}
V_7 = F_194 ( V_19 -> V_120 , V_305 , - 1 ) ;
if ( V_7 < 0 ) {
F_4 ( V_19 -> V_53 , L_37 , V_7 ) ;
return V_7 ;
}
V_19 -> V_120 -> V_2 . type = type ;
return 0 ;
}
static int F_195 ( struct V_194 * V_53 )
{
struct V_128 * V_129 = V_53 -> V_2 . V_221 ;
struct V_3 * V_4 = & V_129 -> V_130 ;
struct V_18 * V_19 ;
int V_7 ;
if ( ! V_129 )
return - V_64 ;
V_19 = F_145 ( & V_53 -> V_2 , sizeof( * V_19 ) , V_218 ) ;
if ( ! V_19 )
return - V_104 ;
V_7 = F_11 ( & V_53 -> V_2 , V_4 -> V_11 . V_12 ,
V_4 -> V_11 . V_13 ) ;
if ( V_7 < 0 )
return V_7 ;
V_19 -> V_189 = V_129 -> V_210 . V_236 ;
V_19 -> V_129 = V_129 ;
V_19 -> V_53 = & V_53 -> V_2 ;
F_196 ( V_53 , V_19 ) ;
V_19 -> V_109 = V_306 ;
V_19 -> V_110 = V_307 ;
return F_189 ( V_19 ) ;
}
static int F_197 ( struct V_194 * V_53 )
{
struct V_18 * V_19 = F_117 ( V_53 ) ;
int V_28 ;
if ( ! V_19 )
return - V_64 ;
V_28 = V_53 -> V_293 ;
if ( V_28 < 0 )
V_28 = 0 ;
if ( F_198 ( V_28 , V_195 ) ) {
F_199 ( V_28 , V_195 ) ;
F_182 ( & V_19 -> V_286 ) ;
}
return 0 ;
}

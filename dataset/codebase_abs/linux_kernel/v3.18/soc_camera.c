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
enum V_100 V_101 ;
while ( ! F_14 ( V_21 , V_76 , V_102 , V_99 , & V_101 ) )
V_99 ++ ;
if ( ! V_47 -> V_62 -> V_103 )
V_98 = V_99 ;
else
for ( V_28 = 0 ; V_28 < V_99 ; V_28 ++ ) {
V_7 = V_47 -> V_62 -> V_103 ( V_19 , V_28 , NULL ) ;
if ( V_7 < 0 )
return V_7 ;
V_98 += V_7 ;
}
if ( ! V_98 )
return - V_104 ;
V_19 -> V_30 =
F_52 ( V_98 * sizeof( struct V_26 ) ) ;
if ( ! V_19 -> V_30 )
return - V_105 ;
F_20 ( V_19 -> V_53 , L_8 , V_98 ) ;
V_98 = 0 ;
for ( V_28 = 0 ; V_28 < V_99 ; V_28 ++ )
if ( ! V_47 -> V_62 -> V_103 ) {
F_14 ( V_21 , V_76 , V_102 , V_28 , & V_101 ) ;
V_19 -> V_30 [ V_98 ] . V_31 =
F_53 ( V_101 ) ;
if ( V_19 -> V_30 [ V_98 ] . V_31 )
V_19 -> V_30 [ V_98 ++ ] . V_101 = V_101 ;
} else {
V_7 = V_47 -> V_62 -> V_103 ( V_19 , V_28 ,
& V_19 -> V_30 [ V_98 ] ) ;
if ( V_7 < 0 )
goto V_106;
V_98 += V_7 ;
}
V_19 -> V_29 = V_98 ;
V_19 -> V_107 = & V_19 -> V_30 [ 0 ] ;
return 0 ;
V_106:
F_54 ( V_19 -> V_30 ) ;
return V_7 ;
}
static void F_55 ( struct V_18 * V_19 )
{
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
if ( V_47 -> V_62 -> V_108 )
V_47 -> V_62 -> V_108 ( V_19 ) ;
V_19 -> V_107 = NULL ;
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
V_7 = V_47 -> V_62 -> V_109 ( V_19 , V_34 ) ;
if ( V_7 < 0 ) {
return V_7 ;
} else if ( ! V_19 -> V_107 ||
V_19 -> V_107 -> V_31 -> V_27 != V_51 -> V_54 ) {
F_4 ( V_19 -> V_53 ,
L_10 ) ;
return - V_64 ;
}
V_19 -> V_110 = V_51 -> V_55 ;
V_19 -> V_111 = V_51 -> V_56 ;
V_19 -> V_60 = V_51 -> V_60 ;
V_19 -> V_61 = V_51 -> V_61 ;
V_19 -> V_112 = V_51 -> V_112 ;
V_19 -> V_113 = V_51 -> V_113 ;
if ( V_47 -> V_62 -> V_87 )
V_19 -> V_88 . V_113 = V_51 -> V_113 ;
F_20 ( V_19 -> V_53 , L_11 ,
V_19 -> V_110 , V_19 -> V_111 ) ;
return V_47 -> V_62 -> V_114 ( V_19 ) ;
}
static int F_57 ( struct V_18 * V_19 )
{
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
int V_7 ;
if ( V_47 -> V_19 )
return - V_86 ;
if ( ! V_19 -> V_6 ) {
F_58 ( & V_47 -> V_115 ) ;
V_7 = V_47 -> V_62 -> V_116 ( V_47 ) ;
F_59 ( & V_47 -> V_115 ) ;
if ( V_7 < 0 )
return V_7 ;
}
if ( V_47 -> V_62 -> V_117 ) {
V_7 = V_47 -> V_62 -> V_117 ( V_19 ) ;
if ( V_7 < 0 )
goto V_118;
}
V_47 -> V_19 = V_19 ;
return 0 ;
V_118:
if ( ! V_19 -> V_6 ) {
F_58 ( & V_47 -> V_115 ) ;
V_47 -> V_62 -> V_119 ( V_47 ) ;
F_59 ( & V_47 -> V_115 ) ;
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
F_58 ( & V_47 -> V_115 ) ;
V_47 -> V_62 -> V_119 ( V_47 ) ;
F_59 ( & V_47 -> V_115 ) ;
}
V_47 -> V_19 = NULL ;
}
static int F_61 ( struct V_66 * V_66 )
{
struct V_120 * V_121 = F_62 ( V_66 ) ;
struct V_18 * V_19 ;
struct V_46 * V_47 ;
int V_7 ;
if ( F_63 ( & V_122 ) )
return - V_123 ;
if ( ! V_121 || ! F_64 ( V_121 ) ) {
F_59 ( & V_122 ) ;
return - V_25 ;
}
V_19 = F_65 ( V_121 ) ;
V_47 = F_19 ( V_19 -> V_48 ) ;
V_7 = F_66 ( V_47 -> V_62 -> V_124 ) ? 0 : - V_25 ;
F_59 ( & V_122 ) ;
if ( V_7 < 0 ) {
F_4 ( V_19 -> V_53 , L_12 ) ;
return V_7 ;
}
if ( ! F_67 ( V_19 ) ) {
V_7 = - V_25 ;
goto V_125;
}
if ( F_63 ( & V_47 -> V_126 ) ) {
V_7 = - V_123 ;
goto V_127;
}
V_19 -> V_128 ++ ;
if ( V_19 -> V_128 == 1 ) {
struct V_129 * V_130 = F_68 ( V_19 ) ;
struct V_45 V_34 = {
. type = V_69 ,
. V_52 . V_51 = {
. V_55 = V_19 -> V_110 ,
. V_56 = V_19 -> V_111 ,
. V_113 = V_19 -> V_113 ,
. V_112 = V_19 -> V_112 ,
. V_54 =
V_19 -> V_107 -> V_31 -> V_27 ,
} ,
} ;
if ( V_130 -> V_131 . V_132 )
V_130 -> V_131 . V_132 ( V_19 -> V_53 ) ;
V_7 = F_57 ( V_19 ) ;
if ( V_7 < 0 ) {
F_4 ( V_19 -> V_53 , L_13 , V_7 ) ;
goto V_133;
}
V_7 = F_12 ( V_19 ) ;
if ( V_7 < 0 )
goto V_134;
F_69 ( & V_19 -> V_121 -> V_2 ) ;
V_7 = F_70 ( & V_19 -> V_121 -> V_2 ) ;
if ( V_7 < 0 && V_7 != - V_135 )
goto V_136;
V_7 = F_56 ( V_19 , & V_34 ) ;
if ( V_7 < 0 )
goto V_137;
if ( V_47 -> V_62 -> V_87 ) {
V_47 -> V_62 -> V_87 ( & V_19 -> V_88 , V_19 ) ;
} else {
V_7 = V_47 -> V_62 -> V_138 ( & V_19 -> V_90 , V_19 ) ;
if ( V_7 < 0 )
goto V_139;
}
F_71 ( & V_19 -> V_140 ) ;
}
F_59 ( & V_47 -> V_126 ) ;
V_66 -> V_68 = V_19 ;
F_20 ( V_19 -> V_53 , L_14 ) ;
return 0 ;
V_139:
V_137:
F_72 ( & V_19 -> V_121 -> V_2 ) ;
V_136:
F_15 ( V_19 ) ;
V_134:
F_60 ( V_19 ) ;
V_133:
V_19 -> V_128 -- ;
F_59 ( & V_47 -> V_126 ) ;
V_127:
V_125:
F_73 ( V_47 -> V_62 -> V_124 ) ;
return V_7 ;
}
static int F_74 ( struct V_66 * V_66 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
F_58 ( & V_47 -> V_126 ) ;
V_19 -> V_128 -- ;
if ( ! V_19 -> V_128 ) {
F_75 ( & V_19 -> V_121 -> V_2 ) ;
F_72 ( & V_19 -> V_121 -> V_2 ) ;
if ( V_47 -> V_62 -> V_138 )
F_76 ( & V_19 -> V_90 ) ;
F_15 ( V_19 ) ;
F_60 ( V_19 ) ;
}
if ( V_19 -> V_85 == V_66 )
V_19 -> V_85 = NULL ;
F_59 ( & V_47 -> V_126 ) ;
F_73 ( V_47 -> V_62 -> V_124 ) ;
F_20 ( V_19 -> V_53 , L_15 ) ;
return 0 ;
}
static T_2 F_77 ( struct V_66 * V_66 , char T_3 * V_141 ,
T_4 V_142 , T_5 * V_143 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
F_20 ( V_19 -> V_53 , L_16 , V_141 ) ;
if ( V_47 -> V_62 -> V_138 && V_19 -> V_90 . V_144 & V_145 )
return F_78 ( & V_19 -> V_90 , V_141 , V_142 , V_143 ,
V_66 -> V_92 & V_93 ) ;
F_4 ( V_19 -> V_53 , L_17 ) ;
return - V_64 ;
}
static int F_79 ( struct V_66 * V_66 , struct V_146 * V_147 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
int V_17 ;
F_20 ( V_19 -> V_53 , L_18 , ( unsigned long ) V_147 ) ;
if ( V_19 -> V_85 != V_66 )
return - V_86 ;
if ( F_63 ( & V_47 -> V_126 ) )
return - V_123 ;
if ( V_47 -> V_62 -> V_87 )
V_17 = F_80 ( & V_19 -> V_88 , V_147 ) ;
else
V_17 = F_81 ( & V_19 -> V_90 , V_147 ) ;
F_59 ( & V_47 -> V_126 ) ;
F_20 ( V_19 -> V_53 , L_19 ,
( unsigned long ) V_147 -> V_148 ,
( unsigned long ) V_147 -> V_149 - ( unsigned long ) V_147 -> V_148 ,
V_17 ) ;
return V_17 ;
}
static unsigned int F_82 ( struct V_66 * V_66 , T_6 * V_150 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
unsigned V_151 = V_152 ;
if ( V_19 -> V_85 != V_66 )
return V_152 ;
F_58 ( & V_47 -> V_126 ) ;
if ( V_47 -> V_62 -> V_87 && F_83 ( & V_19 -> V_88 . V_153 ) )
F_4 ( V_19 -> V_53 , L_20 ) ;
else
V_151 = V_47 -> V_62 -> V_154 ( V_66 , V_150 ) ;
F_59 ( & V_47 -> V_126 ) ;
return V_151 ;
}
void F_84 ( struct V_155 * V_156 )
{
struct V_18 * V_19 = F_85 ( V_156 ) ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
F_58 ( & V_47 -> V_126 ) ;
}
void F_86 ( struct V_155 * V_156 )
{
struct V_18 * V_19 = F_85 ( V_156 ) ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
F_59 ( & V_47 -> V_126 ) ;
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
struct V_157 * V_34 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
const struct V_158 * V_159 ;
F_26 ( V_67 != V_66 -> V_68 ) ;
if ( V_34 -> V_72 >= V_19 -> V_29 )
return - V_64 ;
V_159 = V_19 -> V_30 [ V_34 -> V_72 ] . V_31 ;
if ( V_159 -> V_74 )
F_91 ( V_34 -> V_160 , V_159 -> V_74 , sizeof( V_34 -> V_160 ) ) ;
V_34 -> V_54 = V_159 -> V_27 ;
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
V_51 -> V_55 = V_19 -> V_110 ;
V_51 -> V_56 = V_19 -> V_111 ;
V_51 -> V_60 = V_19 -> V_60 ;
V_51 -> V_61 = V_19 -> V_61 ;
V_51 -> V_113 = V_19 -> V_113 ;
V_51 -> V_54 = V_19 -> V_107 -> V_31 -> V_27 ;
V_51 -> V_112 = V_19 -> V_112 ;
F_20 ( V_19 -> V_53 , L_23 ,
V_19 -> V_107 -> V_31 -> V_27 ) ;
return 0 ;
}
static int F_93 ( struct V_66 * V_66 , void * V_67 ,
struct V_161 * V_162 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
F_26 ( V_67 != V_66 -> V_68 ) ;
F_91 ( V_162 -> V_163 , V_47 -> V_164 , sizeof( V_162 -> V_163 ) ) ;
return V_47 -> V_62 -> V_165 ( V_47 , V_162 ) ;
}
static int F_94 ( struct V_66 * V_66 , void * V_67 ,
enum V_166 V_28 )
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
F_14 ( V_21 , V_76 , V_167 , 1 ) ;
return V_7 ;
}
static int F_97 ( struct V_66 * V_66 , void * V_67 ,
enum V_166 V_28 )
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
F_14 ( V_21 , V_76 , V_167 , 0 ) ;
return 0 ;
}
static int F_100 ( struct V_66 * V_66 , void * V_79 ,
struct V_168 * V_75 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
return V_47 -> V_62 -> V_169 ( V_19 , V_75 ) ;
}
static int F_101 ( struct V_66 * V_66 , void * V_79 ,
struct V_170 * V_75 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
int V_7 ;
V_7 = V_47 -> V_62 -> V_171 ( V_19 , V_75 ) ;
return V_7 ;
}
static int F_102 ( struct V_66 * V_66 , void * V_79 ,
const struct V_170 * V_75 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
const struct V_172 * V_173 = & V_75 -> V_174 ;
struct V_170 V_175 ;
int V_7 ;
if ( V_75 -> type != V_69 )
return - V_64 ;
F_20 ( V_19 -> V_53 , L_24 ,
V_173 -> V_55 , V_173 -> V_56 , V_173 -> V_176 , V_173 -> V_177 ) ;
V_175 . type = V_75 -> type ;
V_7 = V_47 -> V_62 -> V_171 ( V_19 , & V_175 ) ;
if ( V_7 < 0 ) {
F_4 ( V_19 -> V_53 ,
L_25 ) ;
} else if ( ( V_75 -> V_174 . V_55 == V_175 . V_174 . V_55 &&
V_75 -> V_174 . V_56 == V_175 . V_174 . V_56 ) ||
! F_89 ( V_47 , V_19 ) ) {
V_7 = V_47 -> V_62 -> V_178 ( V_19 , V_75 ) ;
} else if ( V_47 -> V_62 -> V_179 ) {
V_7 = V_47 -> V_62 -> V_179 ( V_19 , V_75 ) ;
} else {
F_4 ( V_19 -> V_53 ,
L_26 ) ;
V_7 = - V_86 ;
}
return V_7 ;
}
static int F_103 ( struct V_66 * V_66 , void * V_79 ,
struct V_180 * V_181 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
if ( V_181 -> type != V_69 )
return - V_64 ;
if ( ! V_47 -> V_62 -> V_182 )
return - V_183 ;
return V_47 -> V_62 -> V_182 ( V_19 , V_181 ) ;
}
static int F_104 ( struct V_66 * V_66 , void * V_79 ,
struct V_180 * V_181 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
int V_7 ;
if ( V_181 -> type != V_69 ||
( V_181 -> V_184 != V_185 &&
V_181 -> V_184 != V_186 ) )
return - V_64 ;
if ( V_181 -> V_184 == V_185 ) {
if ( F_89 ( V_47 , V_19 ) &&
( V_19 -> V_110 != V_181 -> V_187 . V_55 ||
V_19 -> V_111 != V_181 -> V_187 . V_56 ) )
return - V_86 ;
if ( V_19 -> V_85 && V_19 -> V_85 != V_66 )
return - V_86 ;
}
if ( ! V_47 -> V_62 -> V_188 )
return - V_183 ;
V_7 = V_47 -> V_62 -> V_188 ( V_19 , V_181 ) ;
if ( ! V_7 &&
V_181 -> V_184 == V_185 ) {
V_19 -> V_110 = V_181 -> V_187 . V_55 ;
V_19 -> V_111 = V_181 -> V_187 . V_56 ;
if ( ! V_19 -> V_85 )
V_19 -> V_85 = V_66 ;
}
return V_7 ;
}
static int F_105 ( struct V_66 * V_66 , void * V_79 ,
struct V_189 * V_75 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
if ( V_47 -> V_62 -> V_190 )
return V_47 -> V_62 -> V_190 ( V_19 , V_75 ) ;
return - V_24 ;
}
static int F_106 ( struct V_66 * V_66 , void * V_79 ,
struct V_189 * V_75 )
{
struct V_18 * V_19 = V_66 -> V_68 ;
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
if ( V_47 -> V_62 -> V_191 )
return V_47 -> V_62 -> V_191 ( V_19 , V_75 ) ;
return - V_24 ;
}
static void F_107 ( struct V_46 * V_47 )
{
struct V_18 * V_19 ;
F_58 ( & V_122 ) ;
F_108 (icd, &devices, list)
if ( V_19 -> V_192 == V_47 -> V_193 ) {
struct V_129 * V_130 = F_68 ( V_19 ) ;
struct V_3 * V_4 = & V_130 -> V_131 ;
if ( V_4 -> V_132 )
V_4 -> V_132 ( V_19 -> V_53 ) ;
V_19 -> V_48 = V_47 -> V_194 . V_2 ;
F_109 ( V_47 , V_19 ) ;
}
F_59 ( & V_122 ) ;
}
static int F_110 ( struct V_5 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_67 ;
struct V_46 * V_47 ;
int V_7 ;
if ( ! V_19 || ! V_19 -> V_48 )
return - V_25 ;
V_47 = F_19 ( V_19 -> V_48 ) ;
if ( ! F_66 ( V_47 -> V_62 -> V_124 ) )
return - V_25 ;
F_58 ( & V_47 -> V_115 ) ;
V_7 = V_47 -> V_62 -> V_116 ( V_47 ) ;
F_59 ( & V_47 -> V_115 ) ;
return V_7 ;
}
static void F_111 ( struct V_5 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_67 ;
struct V_46 * V_47 ;
if ( ! V_19 || ! V_19 -> V_48 )
return;
V_47 = F_19 ( V_19 -> V_48 ) ;
F_58 ( & V_47 -> V_115 ) ;
V_47 -> V_62 -> V_119 ( V_47 ) ;
F_59 ( & V_47 -> V_115 ) ;
F_73 ( V_47 -> V_62 -> V_124 ) ;
}
static int F_112 ( struct V_129 * V_130 ,
struct V_195 * V_196 )
{
struct V_197 * V_53 ;
int V_7 , V_28 ;
F_58 ( & V_122 ) ;
V_28 = F_113 ( V_198 , V_199 ) ;
if ( V_28 < V_199 )
F_114 ( V_28 , V_198 ) ;
F_59 ( & V_122 ) ;
if ( V_28 >= V_199 )
return - V_105 ;
V_53 = F_115 ( L_27 , V_28 ) ;
if ( ! V_53 )
return - V_105 ;
V_7 = F_116 ( V_53 , V_130 , sizeof( * V_130 ) ) ;
if ( V_7 < 0 ) {
F_117 ( V_53 ) ;
return V_7 ;
}
V_196 -> V_53 = V_53 ;
return 0 ;
}
static struct V_18 * F_118 ( struct V_195 * V_196 )
{
struct V_197 * V_53 = V_196 -> V_53 ;
int V_7 ;
V_7 = F_119 ( V_53 ) ;
if ( V_7 < 0 || ! V_53 -> V_2 . V_163 )
return NULL ;
return F_120 ( V_53 ) ;
}
static int F_121 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
struct V_200 V_201 ;
int V_7 ;
V_21 -> V_202 = F_122 ( V_19 ) ;
F_123 ( V_21 , V_19 ) ;
F_14 ( V_21 , V_76 , V_203 , & V_19 -> V_121 -> V_204 ) ;
V_7 = F_124 ( & V_19 -> V_140 , V_21 -> V_140 , NULL ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_57 ( V_19 ) ;
if ( V_7 < 0 ) {
F_4 ( V_19 -> V_53 , L_13 , V_7 ) ;
return V_7 ;
}
V_7 = F_51 ( V_19 ) ;
if ( V_7 < 0 )
goto V_205;
V_19 -> V_113 = V_206 ;
V_7 = F_125 ( V_19 ) ;
if ( V_7 < 0 )
goto V_207;
if ( ! F_14 ( V_21 , V_76 , V_208 , & V_201 ) ) {
V_19 -> V_110 = V_201 . V_55 ;
V_19 -> V_111 = V_201 . V_56 ;
V_19 -> V_112 = V_201 . V_112 ;
V_19 -> V_113 = V_201 . V_113 ;
}
F_60 ( V_19 ) ;
return 0 ;
V_207:
F_55 ( V_19 ) ;
V_205:
F_60 ( V_19 ) ;
return V_7 ;
}
static int F_126 ( struct V_18 * V_19 ,
struct V_129 * V_130 )
{
struct V_3 * V_4 ;
struct V_209 * V_210 ;
struct V_46 * V_47 ;
struct V_211 * V_212 = & V_130 -> V_213 ;
struct V_214 * V_215 ;
struct V_20 * V_216 ;
char V_217 [ V_218 ] ;
int V_7 ;
if ( V_19 -> V_196 ) {
return - V_219 ;
}
V_47 = F_19 ( V_19 -> V_48 ) ;
V_215 = F_127 ( V_212 -> V_220 ) ;
if ( ! V_215 ) {
F_4 ( V_19 -> V_53 , L_28 ,
V_212 -> V_220 ) ;
return - V_25 ;
}
V_4 = F_128 ( & V_130 -> V_131 , sizeof( * V_4 ) , V_221 ) ;
if ( ! V_4 ) {
V_7 = - V_105 ;
goto V_222;
}
V_4 -> V_11 . V_12 = 0 ;
V_4 -> V_11 . V_13 = NULL ;
V_212 -> V_223 -> V_224 = V_4 ;
snprintf ( V_217 , sizeof( V_217 ) , L_29 ,
V_212 -> V_220 , V_212 -> V_223 -> V_225 ) ;
V_19 -> V_6 = F_129 ( & V_226 , V_217 , L_30 , V_19 ) ;
if ( F_130 ( V_19 -> V_6 ) ) {
V_7 = F_131 ( V_19 -> V_6 ) ;
goto V_227;
}
V_216 = F_132 ( & V_47 -> V_194 , V_215 ,
V_212 -> V_223 , NULL ) ;
if ( ! V_216 ) {
V_7 = - V_25 ;
goto V_228;
}
V_210 = F_133 ( V_216 ) ;
V_19 -> V_229 = & V_210 -> V_2 ;
return 0 ;
V_228:
F_134 ( V_19 -> V_6 ) ;
V_19 -> V_6 = NULL ;
V_227:
F_135 ( V_4 ) ;
V_222:
F_136 ( V_215 ) ;
return V_7 ;
}
static void F_137 ( struct V_18 * V_19 )
{
struct V_209 * V_210 =
F_138 ( F_67 ( V_19 ) ) ;
struct V_214 * V_215 ;
struct V_3 * V_4 ;
V_19 -> V_229 = NULL ;
if ( V_19 -> V_196 )
return;
V_215 = V_210 -> V_230 ;
V_4 = V_210 -> V_2 . V_224 ;
F_139 ( F_140 ( V_210 ) ) ;
F_141 ( V_210 ) ;
F_136 ( V_215 ) ;
F_135 ( V_4 ) ;
F_134 ( V_19 -> V_6 ) ;
V_19 -> V_6 = NULL ;
}
static int F_142 ( struct V_231 * V_232 ,
struct V_20 * V_21 ,
struct V_233 * V_234 )
{
struct V_195 * V_196 = F_143 ( V_232 ,
struct V_195 , V_232 ) ;
struct V_18 * V_19 = F_120 ( V_196 -> V_53 ) ;
if ( V_234 == V_196 -> V_235 && ! F_26 ( V_19 -> V_229 ) ) {
struct V_209 * V_210 = F_133 ( V_21 ) ;
if ( V_210 ) {
struct V_129 * V_130 = F_68 ( V_19 ) ;
struct V_3 * V_4 =
F_144 ( V_210 ) ;
if ( V_4 ) {
memcpy ( & V_130 -> V_131 , V_4 ,
sizeof( V_130 -> V_131 ) ) ;
if ( V_4 -> V_132 )
V_4 -> V_132 ( V_19 -> V_53 ) ;
}
V_19 -> V_229 = & V_210 -> V_2 ;
}
}
return 0 ;
}
static void F_145 ( struct V_231 * V_232 ,
struct V_20 * V_21 ,
struct V_233 * V_234 )
{
struct V_195 * V_196 = F_143 ( V_232 ,
struct V_195 , V_232 ) ;
struct V_18 * V_19 = F_120 ( V_196 -> V_53 ) ;
if ( V_19 -> V_6 ) {
F_134 ( V_19 -> V_6 ) ;
V_19 -> V_6 = NULL ;
}
}
static int F_146 ( struct V_231 * V_232 )
{
struct V_195 * V_196 = F_143 ( V_232 ,
struct V_195 , V_232 ) ;
struct V_18 * V_19 = F_120 ( V_196 -> V_53 ) ;
if ( F_67 ( V_19 ) ) {
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
int V_7 ;
F_58 ( & V_122 ) ;
V_7 = F_109 ( V_47 , V_19 ) ;
F_59 ( & V_122 ) ;
if ( V_7 < 0 )
return V_7 ;
}
return 0 ;
}
static int F_147 ( struct V_46 * V_47 ,
struct V_233 * * V_234 , unsigned int V_236 )
{
struct V_237 * V_238 ;
struct V_195 * V_196 ;
struct V_18 * V_19 ;
struct V_129 V_130 = { . V_213 . V_239 = V_47 -> V_193 ,} ;
char V_217 [ V_218 ] ;
unsigned int V_28 ;
int V_7 ;
for ( V_28 = 0 ; V_28 < V_236 ; V_28 ++ ) {
V_238 = F_143 ( V_234 [ V_28 ] , struct V_237 , V_234 ) ;
if ( V_238 -> V_240 == V_241 )
break;
}
if ( V_28 >= V_236 || V_234 [ V_28 ] -> V_242 != V_243 ) {
F_4 ( V_47 -> V_194 . V_2 , L_31 ) ;
return - V_25 ;
}
V_196 = F_148 ( V_47 -> V_194 . V_2 , sizeof( * V_196 ) , V_221 ) ;
if ( ! V_196 )
return - V_105 ;
V_130 . V_213 . V_223 = F_149 ( - V_244 ) ;
V_7 = F_112 ( & V_130 , V_196 ) ;
if ( V_7 < 0 )
goto V_245;
V_196 -> V_235 = & V_238 -> V_234 ;
V_19 = F_118 ( V_196 ) ;
if ( ! V_19 ) {
V_7 = - V_105 ;
goto V_246;
}
V_196 -> V_232 . V_247 = V_234 ;
V_196 -> V_232 . V_248 = V_236 ;
V_196 -> V_232 . V_249 = F_142 ;
V_196 -> V_232 . V_250 = F_145 ;
V_196 -> V_232 . V_251 = F_146 ;
V_19 -> V_196 = V_196 ;
V_19 -> V_48 = V_47 -> V_194 . V_2 ;
snprintf ( V_217 , sizeof( V_217 ) , L_29 ,
V_238 -> V_234 . V_252 . V_253 . V_254 , V_238 -> V_234 . V_252 . V_253 . V_255 ) ;
V_19 -> V_6 = F_129 ( & V_226 , V_217 , L_30 , V_19 ) ;
if ( F_130 ( V_19 -> V_6 ) ) {
V_7 = F_131 ( V_19 -> V_6 ) ;
goto V_227;
}
V_7 = F_150 ( & V_47 -> V_194 , & V_196 -> V_232 ) ;
if ( ! V_7 )
return 0 ;
F_134 ( V_19 -> V_6 ) ;
V_227:
V_19 -> V_6 = NULL ;
F_151 ( V_196 -> V_53 ) ;
V_246:
F_117 ( V_196 -> V_53 ) ;
V_245:
F_152 ( V_47 -> V_194 . V_2 , V_196 ) ;
F_4 ( V_47 -> V_194 . V_2 , L_32 , V_7 ) ;
return V_7 ;
}
static void F_153 ( struct V_46 * V_47 )
{
struct V_233 * * V_234 ;
int V_256 ;
for ( V_256 = 0 , V_234 = V_47 -> V_234 ; V_47 -> V_257 [ V_256 ] ; V_256 ++ ) {
F_147 ( V_47 , V_234 , V_47 -> V_257 [ V_256 ] ) ;
V_234 += V_47 -> V_257 [ V_256 ] ;
}
}
static int F_154 ( struct V_46 * V_47 ,
struct V_258 * V_259 ,
struct V_258 * V_260 )
{
struct V_18 * V_19 ;
struct V_129 V_130 = { . V_213 . V_239 = V_47 -> V_193 ,} ;
struct V_195 * V_196 ;
struct V_261 * V_262 ;
struct V_209 * V_210 ;
char V_217 [ V_218 ] ;
int V_7 ;
V_262 = F_148 ( V_47 -> V_194 . V_2 , sizeof( struct V_261 ) ,
V_221 ) ;
if ( ! V_262 )
return - V_105 ;
V_262 -> V_238 . V_234 . V_252 . V_263 . V_264 = V_260 ;
V_262 -> V_238 . V_234 . V_242 = V_265 ;
V_262 -> V_216 = & V_262 -> V_238 . V_234 ;
V_196 = & V_262 -> V_196 ;
V_130 . V_213 . V_223 = F_149 ( - V_244 ) ;
V_7 = F_112 ( & V_130 , V_196 ) ;
if ( V_7 < 0 )
goto V_245;
V_196 -> V_235 = & V_262 -> V_238 . V_234 ;
V_19 = F_118 ( V_196 ) ;
if ( ! V_19 ) {
V_7 = - V_105 ;
goto V_246;
}
V_196 -> V_232 . V_247 = & V_262 -> V_216 ;
V_196 -> V_232 . V_248 = 1 ;
V_196 -> V_232 . V_249 = F_142 ;
V_196 -> V_232 . V_250 = F_145 ;
V_196 -> V_232 . V_251 = F_146 ;
V_19 -> V_196 = V_196 ;
V_19 -> V_48 = V_47 -> V_194 . V_2 ;
V_210 = F_155 ( V_260 ) ;
if ( V_210 )
snprintf ( V_217 , sizeof( V_217 ) , L_29 ,
V_210 -> V_230 -> V_193 , V_210 -> V_225 ) ;
else
snprintf ( V_217 , sizeof( V_217 ) , L_33 ,
F_156 ( V_260 ) ) ;
V_19 -> V_6 = F_129 ( & V_226 , V_217 , L_30 , V_19 ) ;
if ( F_130 ( V_19 -> V_6 ) ) {
V_7 = F_131 ( V_19 -> V_6 ) ;
goto V_227;
}
V_7 = F_150 ( & V_47 -> V_194 , & V_196 -> V_232 ) ;
if ( ! V_7 )
return 0 ;
V_227:
V_19 -> V_6 = NULL ;
F_151 ( V_196 -> V_53 ) ;
V_246:
F_117 ( V_196 -> V_53 ) ;
V_245:
F_152 ( V_47 -> V_194 . V_2 , V_196 ) ;
F_4 ( V_47 -> V_194 . V_2 , L_32 , V_7 ) ;
return V_7 ;
}
static void F_157 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = V_47 -> V_194 . V_2 ;
struct V_258 * V_266 = V_2 -> V_267 ;
struct V_258 * V_268 = NULL , * V_269 ;
unsigned int V_28 ;
for ( V_28 = 0 ; ; V_28 ++ ) {
V_268 = F_158 ( V_266 , V_268 ) ;
if ( ! V_268 )
break;
V_269 = F_159 ( V_268 ) ;
if ( ! V_269 ) {
F_160 ( V_2 , L_34 ,
F_156 ( V_268 ) ) ;
continue;
}
if ( ! V_28 )
F_154 ( V_47 , V_268 , V_269 -> V_48 ) ;
F_161 ( V_268 ) ;
F_161 ( V_269 ) ;
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
struct V_129 * V_130 = F_68 ( V_19 ) ;
struct V_211 * V_212 = & V_130 -> V_213 ;
struct V_1 * V_229 = NULL ;
int V_7 ;
F_162 ( V_19 -> V_53 , L_36 , F_163 ( V_19 -> V_53 ) ) ;
V_7 = F_164 ( & V_19 -> V_140 , 16 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_165 ( V_19 ) ;
if ( V_7 < 0 )
goto V_270;
if ( V_212 -> V_223 ) {
V_7 = F_126 ( V_19 , V_130 ) ;
if ( V_7 < 0 && V_7 != - V_219 )
goto V_118;
} else if ( ! V_212 -> V_271 || ! V_212 -> V_272 ) {
V_7 = - V_64 ;
goto V_118;
} else {
F_58 ( & V_47 -> V_115 ) ;
V_7 = V_47 -> V_62 -> V_116 ( V_47 ) ;
F_59 ( & V_47 -> V_115 ) ;
if ( V_7 < 0 )
goto V_118;
if ( V_212 -> V_273 )
V_7 = F_166 ( V_212 -> V_273 ) ;
V_7 = V_212 -> V_271 ( V_19 ) ;
if ( V_7 < 0 )
goto V_274;
V_229 = F_67 ( V_19 ) ;
if ( ! V_229 || ! V_229 -> V_163 || ! F_167 ( V_229 ) ||
! F_66 ( V_229 -> V_163 -> V_124 ) ) {
V_212 -> V_272 ( V_19 ) ;
V_7 = - V_25 ;
goto V_275;
}
}
F_58 ( & V_47 -> V_126 ) ;
V_7 = F_121 ( V_19 ) ;
F_59 ( & V_47 -> V_126 ) ;
if ( V_7 < 0 )
goto V_276;
return 0 ;
V_276:
if ( V_212 -> V_223 ) {
F_137 ( V_19 ) ;
} else {
V_212 -> V_272 ( V_19 ) ;
F_73 ( V_229 -> V_163 -> V_124 ) ;
V_275:
V_274:
F_58 ( & V_47 -> V_115 ) ;
V_47 -> V_62 -> V_119 ( V_47 ) ;
F_59 ( & V_47 -> V_115 ) ;
}
V_118:
F_168 ( V_19 -> V_121 ) ;
V_19 -> V_121 = NULL ;
if ( V_19 -> V_121 ) {
F_168 ( V_19 -> V_121 ) ;
V_19 -> V_121 = NULL ;
}
V_270:
F_169 ( & V_19 -> V_140 ) ;
return V_7 ;
}
static int F_170 ( struct V_18 * V_19 )
{
struct V_129 * V_130 = F_68 ( V_19 ) ;
struct V_120 * V_121 = V_19 -> V_121 ;
F_169 ( & V_19 -> V_140 ) ;
if ( V_121 ) {
F_171 ( V_121 ) ;
V_19 -> V_121 = NULL ;
}
if ( V_130 -> V_213 . V_223 ) {
F_137 ( V_19 ) ;
} else {
struct V_1 * V_2 = F_67 ( V_19 ) ;
struct V_277 * V_278 = V_2 ? V_2 -> V_163 : NULL ;
if ( V_278 ) {
V_130 -> V_213 . V_272 ( V_19 ) ;
F_73 ( V_278 -> V_124 ) ;
}
}
if ( V_19 -> V_29 )
F_55 ( V_19 ) ;
if ( V_19 -> V_6 ) {
F_134 ( V_19 -> V_6 ) ;
V_19 -> V_6 = NULL ;
}
if ( V_19 -> V_196 )
F_172 ( V_19 -> V_196 -> V_53 ) ;
return 0 ;
}
static int F_173 ( struct V_18 * V_19 ,
struct V_168 * V_75 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_76 , V_169 , V_75 ) ;
}
static int F_174 ( struct V_18 * V_19 , struct V_170 * V_75 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_76 , V_279 , V_75 ) ;
}
static int F_175 ( struct V_18 * V_19 , const struct V_170 * V_75 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_76 , V_280 , V_75 ) ;
}
static int F_176 ( struct V_18 * V_19 ,
struct V_189 * V_281 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_76 , V_282 , V_281 ) ;
}
static int F_177 ( struct V_18 * V_19 ,
struct V_189 * V_281 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_76 , V_283 , V_281 ) ;
}
static int F_178 ( struct V_18 * V_19 ,
struct V_80 * V_81 )
{
int V_7 ;
struct V_20 * V_21 = F_13 ( V_19 ) ;
const struct V_26 * V_49 ;
T_7 V_284 = V_81 -> V_285 ;
struct V_80 V_286 = * V_81 ;
V_49 = F_16 ( V_19 , V_284 ) ;
if ( ! V_49 )
return - V_64 ;
V_286 . V_285 = V_49 -> V_101 ;
V_7 = F_14 ( V_21 , V_76 , V_82 , & V_286 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_81 = V_286 ;
V_81 -> V_285 = V_284 ;
return 0 ;
}
int F_179 ( struct V_46 * V_47 )
{
struct V_46 * V_287 ;
int V_7 ;
if ( ! V_47 || ! V_47 -> V_62 ||
! V_47 -> V_62 -> V_63 ||
! V_47 -> V_62 -> V_109 ||
! V_47 -> V_62 -> V_114 ||
! V_47 -> V_62 -> V_165 ||
( ( ! V_47 -> V_62 -> V_87 ||
! V_47 -> V_62 -> V_89 ) &&
! V_47 -> V_62 -> V_138 ) ||
! V_47 -> V_62 -> V_116 ||
! V_47 -> V_62 -> V_119 ||
! V_47 -> V_62 -> V_154 ||
! V_47 -> V_194 . V_2 )
return - V_64 ;
if ( ! V_47 -> V_62 -> V_178 )
V_47 -> V_62 -> V_178 = F_175 ;
if ( ! V_47 -> V_62 -> V_171 )
V_47 -> V_62 -> V_171 = F_174 ;
if ( ! V_47 -> V_62 -> V_169 )
V_47 -> V_62 -> V_169 = F_173 ;
if ( ! V_47 -> V_62 -> V_191 )
V_47 -> V_62 -> V_191 = F_177 ;
if ( ! V_47 -> V_62 -> V_190 )
V_47 -> V_62 -> V_190 = F_176 ;
if ( ! V_47 -> V_62 -> V_82 )
V_47 -> V_62 -> V_82 = F_178 ;
F_58 ( & V_122 ) ;
F_108 (ix, &hosts, list) {
if ( V_287 -> V_193 == V_47 -> V_193 ) {
V_7 = - V_86 ;
goto V_288;
}
}
V_7 = F_180 ( V_47 -> V_194 . V_2 , & V_47 -> V_194 ) ;
if ( V_7 < 0 )
goto V_288;
F_181 ( & V_47 -> V_289 , & V_290 ) ;
F_59 ( & V_122 ) ;
F_182 ( & V_47 -> V_126 ) ;
F_182 ( & V_47 -> V_115 ) ;
if ( V_47 -> V_194 . V_2 -> V_267 )
F_157 ( V_47 ) ;
else if ( V_47 -> V_257 )
F_153 ( V_47 ) ;
else
F_107 ( V_47 ) ;
return 0 ;
V_288:
F_59 ( & V_122 ) ;
return V_7 ;
}
void F_183 ( struct V_46 * V_47 )
{
struct V_18 * V_19 , * V_291 ;
struct V_195 * V_196 ;
F_184 ( V_292 ) ;
F_58 ( & V_122 ) ;
F_185 ( & V_47 -> V_289 ) ;
F_108 (icd, &devices, list)
if ( V_19 -> V_192 == V_47 -> V_193 && V_19 -> V_196 ) {
F_186 ( V_19 -> V_53 ) ;
F_187 ( & V_19 -> V_196 -> V_289 , & V_292 ) ;
}
F_59 ( & V_122 ) ;
F_108 (sasc, &notifiers, list) {
F_188 ( & V_196 -> V_232 ) ;
F_189 ( & V_196 -> V_53 -> V_2 ) ;
}
F_58 ( & V_122 ) ;
F_190 (icd, tmp, &devices, list)
if ( V_19 -> V_192 == V_47 -> V_193 )
F_170 ( V_19 ) ;
F_59 ( & V_122 ) ;
F_191 ( & V_47 -> V_194 ) ;
}
static int F_192 ( struct V_18 * V_19 )
{
struct V_18 * V_287 ;
int V_293 = - 1 , V_28 ;
F_58 ( & V_122 ) ;
for ( V_28 = 0 ; V_28 < 256 && V_293 < 0 ; V_28 ++ ) {
V_293 = V_28 ;
F_108 (ix, &devices, list) {
if ( V_287 -> V_192 == V_19 -> V_192 && V_287 -> V_294 == V_28 ) {
V_293 = - 1 ;
break;
}
}
}
if ( V_293 < 0 ) {
F_59 ( & V_122 ) ;
return - V_105 ;
}
V_19 -> V_294 = V_293 ;
V_19 -> V_128 = 0 ;
V_19 -> V_295 = NULL ;
V_28 = F_193 ( V_19 -> V_53 ) -> V_296 ;
if ( V_28 < 0 )
V_28 = 0 ;
if ( V_28 >= V_199 ) {
F_59 ( & V_122 ) ;
return - V_86 ;
}
F_114 ( V_28 , V_198 ) ;
F_181 ( & V_19 -> V_289 , & V_297 ) ;
F_59 ( & V_122 ) ;
return 0 ;
}
static int F_165 ( struct V_18 * V_19 )
{
struct V_46 * V_47 = F_19 ( V_19 -> V_48 ) ;
struct V_120 * V_121 = F_194 () ;
if ( ! V_121 )
return - V_105 ;
F_91 ( V_121 -> V_74 , V_47 -> V_164 , sizeof( V_121 -> V_74 ) ) ;
V_121 -> V_194 = & V_47 -> V_194 ;
V_121 -> V_298 = & V_299 ;
V_121 -> V_300 = & V_301 ;
V_121 -> V_302 = F_168 ;
V_121 -> V_140 = & V_19 -> V_140 ;
V_121 -> V_303 = & V_47 -> V_126 ;
V_19 -> V_121 = V_121 ;
return 0 ;
}
static int F_125 ( struct V_18 * V_19 )
{
const struct V_304 * type = V_19 -> V_121 -> V_2 . type ;
int V_7 ;
if ( ! V_19 -> V_48 )
return - V_25 ;
F_195 ( V_19 -> V_121 , V_19 ) ;
if ( V_19 -> V_121 -> V_204 == 0 ) {
F_196 ( V_19 -> V_121 , V_305 ) ;
F_196 ( V_19 -> V_121 , V_306 ) ;
F_196 ( V_19 -> V_121 , V_307 ) ;
}
V_7 = F_197 ( V_19 -> V_121 , V_308 , - 1 ) ;
if ( V_7 < 0 ) {
F_4 ( V_19 -> V_53 , L_37 , V_7 ) ;
return V_7 ;
}
V_19 -> V_121 -> V_2 . type = type ;
return 0 ;
}
static int F_198 ( struct V_197 * V_53 )
{
struct V_129 * V_130 = V_53 -> V_2 . V_224 ;
struct V_3 * V_4 = & V_130 -> V_131 ;
struct V_18 * V_19 ;
int V_7 ;
if ( ! V_130 )
return - V_64 ;
V_19 = F_148 ( & V_53 -> V_2 , sizeof( * V_19 ) , V_221 ) ;
if ( ! V_19 )
return - V_105 ;
V_7 = F_11 ( & V_53 -> V_2 , V_4 -> V_11 . V_12 ,
V_4 -> V_11 . V_13 ) ;
if ( V_7 < 0 )
return V_7 ;
V_19 -> V_192 = V_130 -> V_213 . V_239 ;
V_19 -> V_130 = V_130 ;
V_19 -> V_53 = & V_53 -> V_2 ;
F_199 ( V_53 , V_19 ) ;
V_19 -> V_110 = V_309 ;
V_19 -> V_111 = V_310 ;
return F_192 ( V_19 ) ;
}
static int F_200 ( struct V_197 * V_53 )
{
struct V_18 * V_19 = F_120 ( V_53 ) ;
int V_28 ;
if ( ! V_19 )
return - V_64 ;
V_28 = V_53 -> V_296 ;
if ( V_28 < 0 )
V_28 = 0 ;
if ( F_201 ( V_28 , V_198 ) ) {
F_202 ( V_28 , V_198 ) ;
F_185 ( & V_19 -> V_289 ) ;
}
return 0 ;
}

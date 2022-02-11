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
V_68 V_103 ;
while ( ! F_14 ( V_21 , V_79 , V_104 , V_102 , & V_103 ) )
V_102 ++ ;
if ( ! V_27 -> V_28 -> V_105 )
V_101 = V_102 ;
else
for ( V_34 = 0 ; V_34 < V_102 ; V_34 ++ ) {
V_7 = V_27 -> V_28 -> V_105 ( V_19 , V_34 , NULL ) ;
if ( V_7 < 0 )
return V_7 ;
V_101 += V_7 ;
}
if ( ! V_101 )
return - V_106 ;
V_19 -> V_36 =
F_56 ( V_101 * sizeof( struct V_32 ) ) ;
if ( ! V_19 -> V_36 )
return - V_107 ;
F_24 ( V_19 -> V_57 , L_8 , V_101 ) ;
V_101 = 0 ;
for ( V_34 = 0 ; V_34 < V_102 ; V_34 ++ )
if ( ! V_27 -> V_28 -> V_105 ) {
F_14 ( V_21 , V_79 , V_104 , V_34 , & V_103 ) ;
V_19 -> V_36 [ V_101 ] . V_37 =
F_57 ( V_103 ) ;
if ( V_19 -> V_36 [ V_101 ] . V_37 )
V_19 -> V_36 [ V_101 ++ ] . V_103 = V_103 ;
} else {
V_7 = V_27 -> V_28 -> V_105 ( V_19 , V_34 ,
& V_19 -> V_36 [ V_101 ] ) ;
if ( V_7 < 0 )
goto V_108;
V_101 += V_7 ;
}
V_19 -> V_35 = V_101 ;
V_19 -> V_109 = & V_19 -> V_36 [ 0 ] ;
return 0 ;
V_108:
F_58 ( V_19 -> V_36 ) ;
return V_7 ;
}
static void F_59 ( struct V_18 * V_19 )
{
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
if ( V_27 -> V_28 -> V_110 )
V_27 -> V_28 -> V_110 ( V_19 ) ;
V_19 -> V_109 = NULL ;
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
V_7 = V_27 -> V_28 -> V_111 ( V_19 , V_40 ) ;
if ( V_7 < 0 ) {
return V_7 ;
} else if ( ! V_19 -> V_109 ||
V_19 -> V_109 -> V_37 -> V_33 != V_55 -> V_58 ) {
F_4 ( V_19 -> V_57 ,
L_10 ) ;
return - V_67 ;
}
V_19 -> V_112 = V_55 -> V_59 ;
V_19 -> V_113 = V_55 -> V_60 ;
V_19 -> V_64 = V_55 -> V_64 ;
V_19 -> V_65 = V_55 -> V_65 ;
V_19 -> V_114 = V_55 -> V_114 ;
V_19 -> V_115 = V_55 -> V_115 ;
if ( V_27 -> V_28 -> V_90 )
V_19 -> V_91 . V_115 = V_55 -> V_115 ;
F_24 ( V_19 -> V_57 , L_11 ,
V_19 -> V_112 , V_19 -> V_113 ) ;
return V_27 -> V_28 -> V_116 ( V_19 ) ;
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
if ( V_27 -> V_28 -> V_117 ) {
V_7 = V_27 -> V_28 -> V_117 ( V_19 ) ;
if ( V_7 < 0 )
goto V_118;
}
V_27 -> V_19 = V_19 ;
return 0 ;
V_118:
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
struct V_119 * V_120 = F_64 ( V_69 ) ;
struct V_18 * V_19 ;
struct V_26 * V_27 ;
int V_7 ;
if ( F_65 ( & V_121 ) )
return - V_122 ;
if ( ! V_120 || ! F_66 ( V_120 ) ) {
F_18 ( & V_121 ) ;
return - V_25 ;
}
V_19 = F_67 ( V_120 ) ;
V_27 = F_23 ( V_19 -> V_52 ) ;
V_7 = F_68 ( V_27 -> V_28 -> V_123 ) ? 0 : - V_25 ;
F_18 ( & V_121 ) ;
if ( V_7 < 0 ) {
F_4 ( V_19 -> V_57 , L_12 ) ;
return V_7 ;
}
if ( ! F_69 ( V_19 ) ) {
V_7 = - V_25 ;
goto V_124;
}
if ( F_65 ( & V_27 -> V_125 ) ) {
V_7 = - V_122 ;
goto V_126;
}
V_19 -> V_127 ++ ;
if ( V_19 -> V_127 == 1 ) {
struct V_128 * V_129 = F_70 ( V_19 ) ;
struct V_51 V_40 = {
. type = V_72 ,
. V_56 . V_55 = {
. V_59 = V_19 -> V_112 ,
. V_60 = V_19 -> V_113 ,
. V_115 = V_19 -> V_115 ,
. V_114 = V_19 -> V_114 ,
. V_58 =
V_19 -> V_109 -> V_37 -> V_33 ,
} ,
} ;
if ( V_129 -> V_130 . V_131 )
if ( V_19 -> V_132 )
V_129 -> V_130 . V_131 ( V_19 -> V_132 ) ;
V_7 = F_61 ( V_19 ) ;
if ( V_7 < 0 ) {
F_4 ( V_19 -> V_57 , L_13 , V_7 ) ;
goto V_133;
}
V_7 = F_12 ( V_19 ) ;
if ( V_7 < 0 )
goto V_134;
F_71 ( & V_19 -> V_120 -> V_2 ) ;
V_7 = F_72 ( & V_19 -> V_120 -> V_2 ) ;
if ( V_7 < 0 && V_7 != - V_135 )
goto V_136;
V_7 = F_60 ( V_19 , & V_40 ) ;
if ( V_7 < 0 )
goto V_137;
if ( V_27 -> V_28 -> V_90 ) {
V_27 -> V_28 -> V_90 ( & V_19 -> V_91 , V_19 ) ;
} else {
V_7 = V_27 -> V_28 -> V_138 ( & V_19 -> V_93 , V_19 ) ;
if ( V_7 < 0 )
goto V_139;
}
F_73 ( & V_19 -> V_140 ) ;
}
F_18 ( & V_27 -> V_125 ) ;
V_69 -> V_71 = V_19 ;
F_24 ( V_19 -> V_57 , L_14 ) ;
return 0 ;
V_139:
V_137:
F_74 ( & V_19 -> V_120 -> V_2 ) ;
V_136:
F_15 ( V_19 ) ;
V_134:
F_62 ( V_19 ) ;
V_133:
V_19 -> V_127 -- ;
F_18 ( & V_27 -> V_125 ) ;
V_126:
V_124:
F_75 ( V_27 -> V_28 -> V_123 ) ;
return V_7 ;
}
static int F_76 ( struct V_69 * V_69 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
F_17 ( & V_27 -> V_125 ) ;
V_19 -> V_127 -- ;
if ( ! V_19 -> V_127 ) {
F_77 ( & V_19 -> V_120 -> V_2 ) ;
F_74 ( & V_19 -> V_120 -> V_2 ) ;
if ( V_27 -> V_28 -> V_138 )
F_78 ( & V_19 -> V_93 ) ;
F_15 ( V_19 ) ;
F_62 ( V_19 ) ;
}
if ( V_19 -> V_88 == V_69 )
V_19 -> V_88 = NULL ;
F_18 ( & V_27 -> V_125 ) ;
F_75 ( V_27 -> V_28 -> V_123 ) ;
F_24 ( V_19 -> V_57 , L_15 ) ;
return 0 ;
}
static T_2 F_79 ( struct V_69 * V_69 , char T_3 * V_141 ,
T_4 V_142 , T_5 * V_143 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
F_24 ( V_19 -> V_57 , L_16 , V_141 ) ;
if ( V_27 -> V_28 -> V_138 && V_19 -> V_93 . V_144 & V_145 )
return F_80 ( & V_19 -> V_93 , V_141 , V_142 , V_143 ,
V_69 -> V_95 & V_96 ) ;
F_4 ( V_19 -> V_57 , L_17 ) ;
return - V_67 ;
}
static int F_81 ( struct V_69 * V_69 , struct V_146 * V_147 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
int V_17 ;
F_24 ( V_19 -> V_57 , L_18 , ( unsigned long ) V_147 ) ;
if ( V_19 -> V_88 != V_69 )
return - V_89 ;
if ( F_65 ( & V_27 -> V_125 ) )
return - V_122 ;
if ( V_27 -> V_28 -> V_90 )
V_17 = F_82 ( & V_19 -> V_91 , V_147 ) ;
else
V_17 = F_83 ( & V_19 -> V_93 , V_147 ) ;
F_18 ( & V_27 -> V_125 ) ;
F_24 ( V_19 -> V_57 , L_19 ,
( unsigned long ) V_147 -> V_148 ,
( unsigned long ) V_147 -> V_149 - ( unsigned long ) V_147 -> V_148 ,
V_17 ) ;
return V_17 ;
}
static unsigned int F_84 ( struct V_69 * V_69 , T_6 * V_150 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
unsigned V_151 = V_152 ;
if ( V_19 -> V_88 != V_69 )
return V_152 ;
F_17 ( & V_27 -> V_125 ) ;
if ( V_27 -> V_28 -> V_90 && F_85 ( & V_19 -> V_91 . V_153 ) )
F_4 ( V_19 -> V_57 , L_20 ) ;
else
V_151 = V_27 -> V_28 -> V_154 ( V_69 , V_150 ) ;
F_18 ( & V_27 -> V_125 ) ;
return V_151 ;
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
struct V_155 * V_40 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
const struct V_156 * V_157 ;
F_30 ( V_70 != V_69 -> V_71 ) ;
if ( V_40 -> V_75 >= V_19 -> V_35 )
return - V_67 ;
V_157 = V_19 -> V_36 [ V_40 -> V_75 ] . V_37 ;
if ( V_157 -> V_77 )
F_90 ( V_40 -> V_158 , V_157 -> V_77 , sizeof( V_40 -> V_158 ) ) ;
V_40 -> V_58 = V_157 -> V_33 ;
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
V_55 -> V_59 = V_19 -> V_112 ;
V_55 -> V_60 = V_19 -> V_113 ;
V_55 -> V_64 = V_19 -> V_64 ;
V_55 -> V_65 = V_19 -> V_65 ;
V_55 -> V_115 = V_19 -> V_115 ;
V_55 -> V_58 = V_19 -> V_109 -> V_37 -> V_33 ;
V_55 -> V_114 = V_19 -> V_114 ;
F_24 ( V_19 -> V_57 , L_23 ,
V_19 -> V_109 -> V_37 -> V_33 ) ;
return 0 ;
}
static int F_92 ( struct V_69 * V_69 , void * V_70 ,
struct V_159 * V_160 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
F_30 ( V_70 != V_69 -> V_71 ) ;
F_90 ( V_160 -> V_161 , V_27 -> V_162 , sizeof( V_160 -> V_161 ) ) ;
return V_27 -> V_28 -> V_163 ( V_27 , V_160 ) ;
}
static int F_93 ( struct V_69 * V_69 , void * V_70 ,
enum V_164 V_34 )
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
F_14 ( V_21 , V_79 , V_165 , 1 ) ;
return V_7 ;
}
static int F_96 ( struct V_69 * V_69 , void * V_70 ,
enum V_164 V_34 )
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
F_14 ( V_21 , V_79 , V_165 , 0 ) ;
return 0 ;
}
static int F_99 ( struct V_69 * V_69 , void * V_82 ,
struct V_166 * V_78 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
return V_27 -> V_28 -> V_167 ( V_19 , V_78 ) ;
}
static int F_100 ( struct V_69 * V_69 , void * V_82 ,
struct V_168 * V_78 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
int V_7 ;
V_7 = V_27 -> V_28 -> V_169 ( V_19 , V_78 ) ;
return V_7 ;
}
static int F_101 ( struct V_69 * V_69 , void * V_82 ,
const struct V_168 * V_78 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
const struct V_170 * V_171 = & V_78 -> V_172 ;
struct V_168 V_173 ;
int V_7 ;
if ( V_78 -> type != V_72 )
return - V_67 ;
F_24 ( V_19 -> V_57 , L_24 ,
V_171 -> V_59 , V_171 -> V_60 , V_171 -> V_174 , V_171 -> V_175 ) ;
V_173 . type = V_78 -> type ;
V_7 = V_27 -> V_28 -> V_169 ( V_19 , & V_173 ) ;
if ( V_7 < 0 ) {
F_4 ( V_19 -> V_57 ,
L_25 ) ;
} else if ( ( V_78 -> V_172 . V_59 == V_173 . V_172 . V_59 &&
V_78 -> V_172 . V_60 == V_173 . V_172 . V_60 ) ||
! F_88 ( V_27 , V_19 ) ) {
V_7 = V_27 -> V_28 -> V_176 ( V_19 , V_78 ) ;
} else if ( V_27 -> V_28 -> V_177 ) {
V_7 = V_27 -> V_28 -> V_177 ( V_19 , V_78 ) ;
} else {
F_4 ( V_19 -> V_57 ,
L_26 ) ;
V_7 = - V_89 ;
}
return V_7 ;
}
static int F_102 ( struct V_69 * V_69 , void * V_82 ,
struct V_178 * V_179 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
if ( V_179 -> type != V_72 )
return - V_67 ;
if ( ! V_27 -> V_28 -> V_180 )
return - V_181 ;
return V_27 -> V_28 -> V_180 ( V_19 , V_179 ) ;
}
static int F_103 ( struct V_69 * V_69 , void * V_82 ,
struct V_178 * V_179 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
int V_7 ;
if ( V_179 -> type != V_72 ||
( V_179 -> V_182 != V_183 &&
V_179 -> V_182 != V_184 ) )
return - V_67 ;
if ( V_179 -> V_182 == V_183 ) {
if ( F_88 ( V_27 , V_19 ) &&
( V_19 -> V_112 != V_179 -> V_185 . V_59 ||
V_19 -> V_113 != V_179 -> V_185 . V_60 ) )
return - V_89 ;
if ( V_19 -> V_88 && V_19 -> V_88 != V_69 )
return - V_89 ;
}
if ( ! V_27 -> V_28 -> V_186 )
return - V_181 ;
V_7 = V_27 -> V_28 -> V_186 ( V_19 , V_179 ) ;
if ( ! V_7 &&
V_179 -> V_182 == V_183 ) {
V_19 -> V_112 = V_179 -> V_185 . V_59 ;
V_19 -> V_113 = V_179 -> V_185 . V_60 ;
if ( ! V_19 -> V_88 )
V_19 -> V_88 = V_69 ;
}
return V_7 ;
}
static int F_104 ( struct V_69 * V_69 , void * V_82 ,
struct V_187 * V_78 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
if ( V_27 -> V_28 -> V_188 )
return V_27 -> V_28 -> V_188 ( V_19 , V_78 ) ;
return - V_24 ;
}
static int F_105 ( struct V_69 * V_69 , void * V_82 ,
struct V_187 * V_78 )
{
struct V_18 * V_19 = V_69 -> V_71 ;
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
if ( V_27 -> V_28 -> V_189 )
return V_27 -> V_28 -> V_189 ( V_19 , V_78 ) ;
return - V_24 ;
}
static void F_106 ( struct V_26 * V_27 )
{
struct V_18 * V_19 ;
F_17 ( & V_121 ) ;
F_107 (icd, &devices, list)
if ( V_19 -> V_190 == V_27 -> V_191 ) {
struct V_128 * V_129 = F_70 ( V_19 ) ;
struct V_3 * V_4 = & V_129 -> V_130 ;
if ( V_4 -> V_131 )
if ( V_19 -> V_132 )
V_4 -> V_131 ( V_19 -> V_132 ) ;
V_19 -> V_52 = V_27 -> V_192 . V_2 ;
F_108 ( V_27 , V_19 ) ;
}
F_18 ( & V_121 ) ;
}
static int F_109 ( struct V_5 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_70 ;
struct V_26 * V_27 ;
if ( ! V_19 || ! V_19 -> V_52 )
return - V_25 ;
V_27 = F_23 ( V_19 -> V_52 ) ;
if ( ! F_68 ( V_27 -> V_28 -> V_123 ) )
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
F_75 ( V_27 -> V_28 -> V_123 ) ;
}
static int F_111 ( struct V_128 * V_129 ,
struct V_193 * V_194 )
{
struct V_195 * V_57 ;
int V_7 , V_34 ;
F_17 ( & V_121 ) ;
V_34 = F_112 ( V_196 , V_197 ) ;
if ( V_34 < V_197 )
F_113 ( V_34 , V_196 ) ;
F_18 ( & V_121 ) ;
if ( V_34 >= V_197 )
return - V_107 ;
V_57 = F_114 ( L_27 , V_34 ) ;
if ( ! V_57 )
return - V_107 ;
V_7 = F_115 ( V_57 , V_129 , sizeof( * V_129 ) ) ;
if ( V_7 < 0 ) {
F_116 ( V_57 ) ;
return V_7 ;
}
V_194 -> V_57 = V_57 ;
return 0 ;
}
static struct V_18 * F_117 ( struct V_193 * V_194 )
{
struct V_195 * V_57 = V_194 -> V_57 ;
int V_7 ;
V_7 = F_118 ( V_57 ) ;
if ( V_7 < 0 || ! V_57 -> V_2 . V_161 )
return NULL ;
return F_119 ( V_57 ) ;
}
static int F_120 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
struct V_198 V_199 ;
int V_7 ;
V_21 -> V_200 = F_121 ( V_19 ) ;
F_122 ( V_21 , V_19 ) ;
F_14 ( V_21 , V_79 , V_201 , & V_19 -> V_120 -> V_202 ) ;
V_7 = F_123 ( & V_19 -> V_140 , V_21 -> V_140 , NULL ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_61 ( V_19 ) ;
if ( V_7 < 0 ) {
F_4 ( V_19 -> V_57 , L_13 , V_7 ) ;
return V_7 ;
}
V_7 = F_55 ( V_19 ) ;
if ( V_7 < 0 )
goto V_203;
V_19 -> V_115 = V_204 ;
V_7 = F_124 ( V_19 ) ;
if ( V_7 < 0 )
goto V_205;
if ( ! F_14 ( V_21 , V_79 , V_206 , & V_199 ) ) {
V_19 -> V_112 = V_199 . V_59 ;
V_19 -> V_113 = V_199 . V_60 ;
V_19 -> V_114 = V_199 . V_114 ;
V_19 -> V_115 = V_199 . V_115 ;
}
F_62 ( V_19 ) ;
return 0 ;
V_205:
F_59 ( V_19 ) ;
V_203:
F_62 ( V_19 ) ;
return V_7 ;
}
static int F_125 ( struct V_18 * V_19 ,
struct V_128 * V_129 )
{
struct V_3 * V_4 ;
struct V_207 * V_208 ;
struct V_26 * V_27 ;
struct V_209 * V_210 = & V_129 -> V_211 ;
struct V_212 * V_213 ;
struct V_20 * V_214 ;
char V_215 [ V_216 ] ;
int V_7 ;
if ( V_19 -> V_194 ) {
return - V_217 ;
}
V_27 = F_23 ( V_19 -> V_52 ) ;
V_213 = F_126 ( V_210 -> V_218 ) ;
if ( ! V_213 ) {
F_4 ( V_19 -> V_57 , L_28 ,
V_210 -> V_218 ) ;
return - V_25 ;
}
V_4 = F_127 ( & V_129 -> V_130 , sizeof( * V_4 ) , V_219 ) ;
if ( ! V_4 ) {
V_7 = - V_107 ;
goto V_220;
}
V_4 -> V_11 . V_12 = 0 ;
V_4 -> V_11 . V_13 = NULL ;
V_210 -> V_221 -> V_222 = V_4 ;
snprintf ( V_215 , sizeof( V_215 ) , L_29 ,
V_210 -> V_218 , V_210 -> V_221 -> V_223 ) ;
V_19 -> V_6 = F_128 ( & V_224 , V_215 , V_19 ) ;
if ( F_129 ( V_19 -> V_6 ) ) {
V_7 = F_130 ( V_19 -> V_6 ) ;
goto V_225;
}
V_214 = F_131 ( & V_27 -> V_192 , V_213 ,
V_210 -> V_221 , NULL ) ;
if ( ! V_214 ) {
V_7 = - V_25 ;
goto V_226;
}
V_208 = F_132 ( V_214 ) ;
V_19 -> V_132 = & V_208 -> V_2 ;
return 0 ;
V_226:
F_133 ( V_19 -> V_6 ) ;
V_19 -> V_6 = NULL ;
V_225:
F_134 ( V_4 ) ;
V_220:
F_135 ( V_213 ) ;
return V_7 ;
}
static void F_136 ( struct V_18 * V_19 )
{
struct V_207 * V_208 =
F_137 ( F_69 ( V_19 ) ) ;
struct V_212 * V_213 ;
struct V_3 * V_4 ;
V_19 -> V_132 = NULL ;
if ( V_19 -> V_194 )
return;
V_213 = V_208 -> V_227 ;
V_4 = V_208 -> V_2 . V_222 ;
F_138 ( F_139 ( V_208 ) ) ;
F_140 ( V_208 ) ;
F_135 ( V_213 ) ;
F_134 ( V_4 ) ;
F_133 ( V_19 -> V_6 ) ;
V_19 -> V_6 = NULL ;
}
static int F_141 ( struct V_228 * V_229 ,
struct V_20 * V_21 ,
struct V_230 * V_231 )
{
struct V_193 * V_194 = F_142 ( V_229 ,
struct V_193 , V_229 ) ;
struct V_18 * V_19 = F_119 ( V_194 -> V_57 ) ;
if ( V_231 == V_194 -> V_232 && ! F_30 ( V_19 -> V_132 ) ) {
struct V_207 * V_208 = F_132 ( V_21 ) ;
if ( V_208 ) {
struct V_128 * V_129 = F_70 ( V_19 ) ;
struct V_3 * V_4 =
F_143 ( V_208 ) ;
if ( V_4 ) {
memcpy ( & V_129 -> V_130 , V_4 ,
sizeof( V_129 -> V_130 ) ) ;
if ( V_4 -> V_131 )
V_4 -> V_131 ( & V_208 -> V_2 ) ;
}
V_19 -> V_132 = & V_208 -> V_2 ;
}
}
return 0 ;
}
static void F_144 ( struct V_228 * V_229 ,
struct V_20 * V_21 ,
struct V_230 * V_231 )
{
struct V_193 * V_194 = F_142 ( V_229 ,
struct V_193 , V_229 ) ;
struct V_18 * V_19 = F_119 ( V_194 -> V_57 ) ;
if ( V_19 -> V_6 ) {
F_133 ( V_19 -> V_6 ) ;
V_19 -> V_6 = NULL ;
}
}
static int F_145 ( struct V_228 * V_229 )
{
struct V_193 * V_194 = F_142 ( V_229 ,
struct V_193 , V_229 ) ;
struct V_18 * V_19 = F_119 ( V_194 -> V_57 ) ;
if ( F_69 ( V_19 ) ) {
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
int V_7 ;
F_17 ( & V_121 ) ;
V_7 = F_108 ( V_27 , V_19 ) ;
F_18 ( & V_121 ) ;
if ( V_7 < 0 )
return V_7 ;
}
return 0 ;
}
static int F_146 ( struct V_26 * V_27 ,
struct V_230 * * V_231 , unsigned int V_233 )
{
struct V_234 * V_235 ;
struct V_193 * V_194 ;
struct V_18 * V_19 ;
struct V_128 V_129 = { . V_211 . V_236 = V_27 -> V_191 ,} ;
char V_215 [ V_216 ] ;
unsigned int V_34 ;
int V_7 ;
for ( V_34 = 0 ; V_34 < V_233 ; V_34 ++ ) {
V_235 = F_142 ( V_231 [ V_34 ] , struct V_234 , V_231 ) ;
if ( V_235 -> V_237 == V_238 )
break;
}
if ( V_34 >= V_233 || V_231 [ V_34 ] -> V_239 != V_240 ) {
F_4 ( V_27 -> V_192 . V_2 , L_30 ) ;
return - V_25 ;
}
V_194 = F_147 ( V_27 -> V_192 . V_2 , sizeof( * V_194 ) , V_219 ) ;
if ( ! V_194 )
return - V_107 ;
V_129 . V_211 . V_221 = F_148 ( - V_241 ) ;
V_7 = F_111 ( & V_129 , V_194 ) ;
if ( V_7 < 0 )
goto V_242;
V_194 -> V_232 = & V_235 -> V_231 ;
V_19 = F_117 ( V_194 ) ;
if ( ! V_19 ) {
V_7 = - V_107 ;
goto V_243;
}
V_194 -> V_229 . V_244 = V_231 ;
V_194 -> V_229 . V_245 = V_233 ;
V_194 -> V_229 . V_246 = F_141 ;
V_194 -> V_229 . V_247 = F_144 ;
V_194 -> V_229 . V_248 = F_145 ;
V_19 -> V_194 = V_194 ;
V_19 -> V_52 = V_27 -> V_192 . V_2 ;
snprintf ( V_215 , sizeof( V_215 ) , L_29 ,
V_235 -> V_231 . V_249 . V_250 . V_251 , V_235 -> V_231 . V_249 . V_250 . V_252 ) ;
V_19 -> V_6 = F_128 ( & V_224 , V_215 , V_19 ) ;
if ( F_129 ( V_19 -> V_6 ) ) {
V_7 = F_130 ( V_19 -> V_6 ) ;
goto V_225;
}
V_7 = F_149 ( & V_27 -> V_192 , & V_194 -> V_229 ) ;
if ( ! V_7 )
return 0 ;
F_133 ( V_19 -> V_6 ) ;
V_225:
V_19 -> V_6 = NULL ;
F_150 ( V_194 -> V_57 ) ;
V_243:
F_116 ( V_194 -> V_57 ) ;
V_242:
F_151 ( V_27 -> V_192 . V_2 , V_194 ) ;
F_4 ( V_27 -> V_192 . V_2 , L_31 , V_7 ) ;
return V_7 ;
}
static void F_152 ( struct V_26 * V_27 )
{
struct V_230 * * V_231 ;
int V_253 ;
for ( V_253 = 0 , V_231 = V_27 -> V_231 ; V_27 -> V_254 [ V_253 ] ; V_253 ++ ) {
F_146 ( V_27 , V_231 , V_27 -> V_254 [ V_253 ] ) ;
V_231 += V_27 -> V_254 [ V_253 ] ;
}
}
static int F_153 ( struct V_26 * V_27 ,
struct V_255 * V_256 ,
struct V_255 * V_257 )
{
struct V_18 * V_19 ;
struct V_128 V_129 = { . V_211 . V_236 = V_27 -> V_191 ,} ;
struct V_193 * V_194 ;
struct V_258 * V_259 ;
struct V_207 * V_208 ;
char V_215 [ V_216 ] ;
int V_7 ;
V_259 = F_147 ( V_27 -> V_192 . V_2 , sizeof( struct V_258 ) ,
V_219 ) ;
if ( ! V_259 )
return - V_107 ;
V_259 -> V_235 . V_231 . V_249 . V_260 . V_261 = V_257 ;
V_259 -> V_235 . V_231 . V_239 = V_262 ;
V_259 -> V_214 = & V_259 -> V_235 . V_231 ;
V_194 = & V_259 -> V_194 ;
V_129 . V_211 . V_221 = F_148 ( - V_241 ) ;
V_7 = F_111 ( & V_129 , V_194 ) ;
if ( V_7 < 0 )
goto V_242;
V_194 -> V_232 = & V_259 -> V_235 . V_231 ;
V_19 = F_117 ( V_194 ) ;
if ( ! V_19 ) {
V_7 = - V_107 ;
goto V_243;
}
V_194 -> V_229 . V_244 = & V_259 -> V_214 ;
V_194 -> V_229 . V_245 = 1 ;
V_194 -> V_229 . V_246 = F_141 ;
V_194 -> V_229 . V_247 = F_144 ;
V_194 -> V_229 . V_248 = F_145 ;
V_19 -> V_194 = V_194 ;
V_19 -> V_52 = V_27 -> V_192 . V_2 ;
V_208 = F_154 ( V_257 ) ;
if ( V_208 )
snprintf ( V_215 , sizeof( V_215 ) , L_29 ,
V_208 -> V_227 -> V_191 , V_208 -> V_223 ) ;
else
snprintf ( V_215 , sizeof( V_215 ) , L_32 ,
F_155 ( V_257 ) ) ;
V_19 -> V_6 = F_128 ( & V_224 , V_215 , V_19 ) ;
if ( F_129 ( V_19 -> V_6 ) ) {
V_7 = F_130 ( V_19 -> V_6 ) ;
goto V_225;
}
V_7 = F_149 ( & V_27 -> V_192 , & V_194 -> V_229 ) ;
if ( ! V_7 )
return 0 ;
F_133 ( V_19 -> V_6 ) ;
V_225:
V_19 -> V_6 = NULL ;
F_150 ( V_194 -> V_57 ) ;
V_243:
F_116 ( V_194 -> V_57 ) ;
V_242:
F_151 ( V_27 -> V_192 . V_2 , V_259 ) ;
F_4 ( V_27 -> V_192 . V_2 , L_31 , V_7 ) ;
return V_7 ;
}
static void F_156 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_192 . V_2 ;
struct V_255 * V_263 = V_2 -> V_264 ;
struct V_255 * V_265 = NULL , * V_266 ;
unsigned int V_34 ;
for ( V_34 = 0 ; ; V_34 ++ ) {
V_265 = F_157 ( V_263 , V_265 ) ;
if ( ! V_265 )
break;
V_266 = F_158 ( V_265 ) ;
if ( ! V_266 ) {
F_159 ( V_2 , L_33 ,
F_155 ( V_265 ) ) ;
continue;
}
if ( ! V_34 )
F_153 ( V_27 , V_265 , V_266 -> V_52 ) ;
F_160 ( V_266 ) ;
if ( V_34 ) {
F_4 ( V_2 , L_34 ) ;
break;
}
}
F_160 ( V_265 ) ;
}
static inline void F_156 ( struct V_26 * V_27 ) { }
static int F_108 ( struct V_26 * V_27 ,
struct V_18 * V_19 )
{
struct V_128 * V_129 = F_70 ( V_19 ) ;
struct V_209 * V_210 = & V_129 -> V_211 ;
struct V_1 * V_132 = NULL ;
int V_7 ;
F_161 ( V_19 -> V_57 , L_35 , F_162 ( V_19 -> V_57 ) ) ;
V_7 = F_163 ( & V_19 -> V_140 , 16 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_164 ( V_19 ) ;
if ( V_7 < 0 )
goto V_267;
if ( V_210 -> V_221 ) {
V_7 = F_125 ( V_19 , V_129 ) ;
if ( V_7 < 0 && V_7 != - V_217 )
goto V_118;
} else if ( ! V_210 -> V_268 || ! V_210 -> V_269 ) {
V_7 = - V_67 ;
goto V_118;
} else {
V_7 = F_16 ( V_27 ) ;
if ( V_7 < 0 )
goto V_118;
if ( V_210 -> V_270 )
V_7 = F_165 ( V_210 -> V_270 ) ;
V_7 = V_210 -> V_268 ( V_19 ) ;
if ( V_7 < 0 )
goto V_271;
V_132 = F_69 ( V_19 ) ;
if ( ! V_132 || ! V_132 -> V_161 || ! F_166 ( V_132 ) ||
! F_68 ( V_132 -> V_161 -> V_123 ) ) {
V_210 -> V_269 ( V_19 ) ;
V_7 = - V_25 ;
goto V_272;
}
}
F_17 ( & V_27 -> V_125 ) ;
V_7 = F_120 ( V_19 ) ;
F_18 ( & V_27 -> V_125 ) ;
if ( V_7 < 0 )
goto V_273;
return 0 ;
V_273:
if ( V_210 -> V_221 ) {
F_136 ( V_19 ) ;
} else {
V_210 -> V_269 ( V_19 ) ;
F_75 ( V_132 -> V_161 -> V_123 ) ;
V_272:
V_271:
F_19 ( V_27 ) ;
}
V_118:
if ( V_19 -> V_120 ) {
F_167 ( V_19 -> V_120 ) ;
V_19 -> V_120 = NULL ;
}
V_267:
F_168 ( & V_19 -> V_140 ) ;
return V_7 ;
}
static int F_169 ( struct V_18 * V_19 )
{
struct V_128 * V_129 = F_70 ( V_19 ) ;
struct V_119 * V_120 = V_19 -> V_120 ;
F_168 ( & V_19 -> V_140 ) ;
if ( V_120 ) {
F_170 ( V_120 ) ;
V_19 -> V_120 = NULL ;
}
if ( V_129 -> V_211 . V_221 ) {
F_136 ( V_19 ) ;
} else {
struct V_1 * V_2 = F_69 ( V_19 ) ;
struct V_274 * V_275 = V_2 ? V_2 -> V_161 : NULL ;
if ( V_275 ) {
V_129 -> V_211 . V_269 ( V_19 ) ;
F_75 ( V_275 -> V_123 ) ;
}
}
if ( V_19 -> V_35 )
F_59 ( V_19 ) ;
if ( V_19 -> V_6 ) {
F_133 ( V_19 -> V_6 ) ;
V_19 -> V_6 = NULL ;
}
if ( V_19 -> V_194 )
F_171 ( V_19 -> V_194 -> V_57 ) ;
return 0 ;
}
static int F_172 ( struct V_18 * V_19 ,
struct V_166 * V_78 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_79 , V_167 , V_78 ) ;
}
static int F_173 ( struct V_18 * V_19 , struct V_168 * V_78 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_79 , V_276 , V_78 ) ;
}
static int F_174 ( struct V_18 * V_19 , const struct V_168 * V_78 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_79 , V_277 , V_78 ) ;
}
static int F_175 ( struct V_18 * V_19 ,
struct V_187 * V_278 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_79 , V_279 , V_278 ) ;
}
static int F_176 ( struct V_18 * V_19 ,
struct V_187 * V_278 )
{
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_14 ( V_21 , V_79 , V_280 , V_278 ) ;
}
static int F_177 ( struct V_18 * V_19 ,
struct V_83 * V_84 )
{
int V_7 ;
struct V_20 * V_21 = F_13 ( V_19 ) ;
const struct V_32 * V_53 ;
struct V_281 V_282 = {
. V_75 = V_84 -> V_75 ,
. V_283 = V_284 ,
} ;
V_53 = F_20 ( V_19 , V_84 -> V_285 ) ;
if ( ! V_53 )
return - V_67 ;
V_282 . V_103 = V_53 -> V_103 ;
V_7 = F_14 ( V_21 , V_286 , V_287 , NULL , & V_282 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_282 . V_288 == V_282 . V_289 &&
V_282 . V_290 == V_282 . V_291 ) {
V_84 -> type = V_292 ;
V_84 -> V_293 . V_59 = V_282 . V_288 ;
V_84 -> V_293 . V_60 = V_282 . V_290 ;
return 0 ;
}
V_84 -> type = V_294 ;
V_84 -> V_295 . V_288 = V_282 . V_288 ;
V_84 -> V_295 . V_289 = V_282 . V_289 ;
V_84 -> V_295 . V_290 = V_282 . V_290 ;
V_84 -> V_295 . V_291 = V_282 . V_291 ;
V_84 -> V_295 . V_296 = 1 ;
V_84 -> V_295 . V_297 = 1 ;
return 0 ;
}
int F_178 ( struct V_26 * V_27 )
{
struct V_26 * V_298 ;
int V_7 ;
if ( ! V_27 || ! V_27 -> V_28 ||
! V_27 -> V_28 -> V_66 ||
! V_27 -> V_28 -> V_111 ||
! V_27 -> V_28 -> V_116 ||
! V_27 -> V_28 -> V_163 ||
( ( ! V_27 -> V_28 -> V_90 ||
! V_27 -> V_28 -> V_92 ) &&
! V_27 -> V_28 -> V_138 ) ||
! V_27 -> V_28 -> V_154 ||
! V_27 -> V_192 . V_2 )
return - V_67 ;
if ( ! V_27 -> V_28 -> V_176 )
V_27 -> V_28 -> V_176 = F_174 ;
if ( ! V_27 -> V_28 -> V_169 )
V_27 -> V_28 -> V_169 = F_173 ;
if ( ! V_27 -> V_28 -> V_167 )
V_27 -> V_28 -> V_167 = F_172 ;
if ( ! V_27 -> V_28 -> V_189 )
V_27 -> V_28 -> V_189 = F_176 ;
if ( ! V_27 -> V_28 -> V_188 )
V_27 -> V_28 -> V_188 = F_175 ;
if ( ! V_27 -> V_28 -> V_85 )
V_27 -> V_28 -> V_85 = F_177 ;
F_17 ( & V_121 ) ;
F_107 (ix, &hosts, list) {
if ( V_298 -> V_191 == V_27 -> V_191 ) {
V_7 = - V_89 ;
goto V_299;
}
}
V_7 = F_179 ( V_27 -> V_192 . V_2 , & V_27 -> V_192 ) ;
if ( V_7 < 0 )
goto V_299;
F_180 ( & V_27 -> V_300 , & V_301 ) ;
F_18 ( & V_121 ) ;
F_181 ( & V_27 -> V_125 ) ;
F_181 ( & V_27 -> V_30 ) ;
if ( V_27 -> V_192 . V_2 -> V_264 )
F_156 ( V_27 ) ;
else if ( V_27 -> V_254 )
F_152 ( V_27 ) ;
else
F_106 ( V_27 ) ;
return 0 ;
V_299:
F_18 ( & V_121 ) ;
return V_7 ;
}
void F_182 ( struct V_26 * V_27 )
{
struct V_18 * V_19 , * V_302 ;
struct V_193 * V_194 ;
F_183 ( V_303 ) ;
F_17 ( & V_121 ) ;
F_184 ( & V_27 -> V_300 ) ;
F_107 (icd, &devices, list)
if ( V_19 -> V_190 == V_27 -> V_191 && V_19 -> V_194 ) {
F_185 ( V_19 -> V_57 ) ;
F_186 ( & V_19 -> V_194 -> V_300 , & V_303 ) ;
}
F_18 ( & V_121 ) ;
F_107 (sasc, &notifiers, list) {
F_187 ( & V_194 -> V_229 ) ;
F_188 ( & V_194 -> V_57 -> V_2 ) ;
}
F_17 ( & V_121 ) ;
F_189 (icd, tmp, &devices, list)
if ( V_19 -> V_190 == V_27 -> V_191 )
F_169 ( V_19 ) ;
F_18 ( & V_121 ) ;
F_190 ( & V_27 -> V_192 ) ;
}
static int F_191 ( struct V_18 * V_19 )
{
struct V_18 * V_298 ;
int V_304 = - 1 , V_34 ;
F_17 ( & V_121 ) ;
for ( V_34 = 0 ; V_34 < 256 && V_304 < 0 ; V_34 ++ ) {
V_304 = V_34 ;
F_107 (ix, &devices, list) {
if ( V_298 -> V_190 == V_19 -> V_190 && V_298 -> V_305 == V_34 ) {
V_304 = - 1 ;
break;
}
}
}
if ( V_304 < 0 ) {
F_18 ( & V_121 ) ;
return - V_107 ;
}
V_19 -> V_305 = V_304 ;
V_19 -> V_127 = 0 ;
V_19 -> V_306 = NULL ;
V_34 = F_192 ( V_19 -> V_57 ) -> V_307 ;
if ( V_34 < 0 )
V_34 = 0 ;
if ( V_34 >= V_197 ) {
F_18 ( & V_121 ) ;
return - V_89 ;
}
F_113 ( V_34 , V_196 ) ;
F_180 ( & V_19 -> V_300 , & V_308 ) ;
F_18 ( & V_121 ) ;
return 0 ;
}
static int F_164 ( struct V_18 * V_19 )
{
struct V_26 * V_27 = F_23 ( V_19 -> V_52 ) ;
struct V_119 * V_120 = F_193 () ;
if ( ! V_120 )
return - V_107 ;
F_90 ( V_120 -> V_77 , V_27 -> V_162 , sizeof( V_120 -> V_77 ) ) ;
V_120 -> V_192 = & V_27 -> V_192 ;
V_120 -> V_309 = & V_310 ;
V_120 -> V_311 = & V_312 ;
V_120 -> V_313 = F_167 ;
V_120 -> V_140 = & V_19 -> V_140 ;
V_120 -> V_314 = & V_27 -> V_125 ;
V_19 -> V_120 = V_120 ;
return 0 ;
}
static int F_124 ( struct V_18 * V_19 )
{
const struct V_315 * type = V_19 -> V_120 -> V_2 . type ;
int V_7 ;
if ( ! V_19 -> V_52 )
return - V_25 ;
F_194 ( V_19 -> V_120 , V_19 ) ;
if ( V_19 -> V_120 -> V_202 == 0 ) {
F_195 ( V_19 -> V_120 , V_316 ) ;
F_195 ( V_19 -> V_120 , V_317 ) ;
F_195 ( V_19 -> V_120 , V_318 ) ;
}
V_7 = F_196 ( V_19 -> V_120 , V_319 , - 1 ) ;
if ( V_7 < 0 ) {
F_4 ( V_19 -> V_57 , L_36 , V_7 ) ;
return V_7 ;
}
V_19 -> V_120 -> V_2 . type = type ;
return 0 ;
}
static int F_197 ( struct V_195 * V_57 )
{
struct V_128 * V_129 = V_57 -> V_2 . V_222 ;
struct V_3 * V_4 = & V_129 -> V_130 ;
struct V_18 * V_19 ;
int V_7 ;
if ( ! V_129 )
return - V_67 ;
V_19 = F_147 ( & V_57 -> V_2 , sizeof( * V_19 ) , V_219 ) ;
if ( ! V_19 )
return - V_107 ;
V_7 = F_11 ( & V_57 -> V_2 , V_4 -> V_11 . V_12 ,
V_4 -> V_11 . V_13 ) ;
if ( V_7 < 0 )
return V_7 ;
V_19 -> V_190 = V_129 -> V_211 . V_236 ;
V_19 -> V_129 = V_129 ;
V_19 -> V_57 = & V_57 -> V_2 ;
F_198 ( V_57 , V_19 ) ;
V_19 -> V_112 = V_320 ;
V_19 -> V_113 = V_321 ;
return F_191 ( V_19 ) ;
}
static int F_199 ( struct V_195 * V_57 )
{
struct V_18 * V_19 = F_119 ( V_57 ) ;
int V_34 ;
if ( ! V_19 )
return - V_67 ;
V_34 = V_57 -> V_307 ;
if ( V_34 < 0 )
V_34 = 0 ;
if ( F_200 ( V_34 , V_196 ) ) {
F_201 ( V_34 , V_196 ) ;
F_184 ( & V_19 -> V_300 ) ;
}
return 0 ;
}

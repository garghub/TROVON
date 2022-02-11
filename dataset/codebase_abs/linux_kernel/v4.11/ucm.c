static struct V_1 * F_1 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_5 ;
F_2 ( & V_6 ) ;
V_5 = F_3 ( & V_7 , V_4 ) ;
if ( ! V_5 )
V_5 = F_4 ( - V_8 ) ;
else if ( V_5 -> V_3 != V_3 )
V_5 = F_4 ( - V_9 ) ;
else
F_5 ( & V_5 -> V_10 ) ;
F_6 ( & V_6 ) ;
return V_5 ;
}
static void F_7 ( struct V_1 * V_5 )
{
if ( F_8 ( & V_5 -> V_10 ) )
F_9 ( & V_5 -> V_11 ) ;
}
static inline int F_10 ( int V_12 )
{
return V_12 == V_13 || V_12 == V_14 ;
}
static void F_11 ( struct V_1 * V_5 )
{
struct V_15 * V_16 ;
F_2 ( & V_5 -> V_3 -> V_17 ) ;
F_12 ( & V_5 -> V_18 ) ;
while ( ! F_13 ( & V_5 -> V_19 ) ) {
V_16 = F_14 ( V_5 -> V_19 . V_20 ,
struct V_15 , V_21 ) ;
F_12 ( & V_16 -> V_18 ) ;
F_12 ( & V_16 -> V_21 ) ;
F_6 ( & V_5 -> V_3 -> V_17 ) ;
if ( F_10 ( V_16 -> V_22 . V_12 ) )
F_15 ( V_16 -> V_23 ) ;
F_16 ( V_16 ) ;
F_2 ( & V_5 -> V_3 -> V_17 ) ;
}
F_6 ( & V_5 -> V_3 -> V_17 ) ;
}
static struct V_1 * F_17 ( struct V_2 * V_3 )
{
struct V_1 * V_5 ;
V_5 = F_18 ( sizeof *V_5 , V_24 ) ;
if ( ! V_5 )
return NULL ;
F_19 ( & V_5 -> V_10 , 1 ) ;
F_20 ( & V_5 -> V_11 ) ;
V_5 -> V_3 = V_3 ;
F_21 ( & V_5 -> V_19 ) ;
F_2 ( & V_6 ) ;
V_5 -> V_4 = F_22 ( & V_7 , V_5 , 0 , 0 , V_24 ) ;
F_6 ( & V_6 ) ;
if ( V_5 -> V_4 < 0 )
goto error;
F_23 ( & V_5 -> V_18 , & V_3 -> V_25 ) ;
return V_5 ;
error:
F_16 ( V_5 ) ;
return NULL ;
}
static void F_24 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
V_27 -> V_30 = V_29 -> V_30 ;
V_27 -> V_31 = V_29 -> V_31 ;
V_27 -> V_32 = V_29 -> V_32 ;
V_27 -> V_33 = V_29 -> V_33 ;
V_27 -> V_34 = V_29 -> V_34 ;
V_27 -> V_35 = V_29 -> V_35 ;
V_27 -> V_36 = V_29 -> V_36 ;
V_27 -> V_37 = V_29 -> V_37 ;
V_27 -> V_38 = V_29 -> V_38 ;
V_27 -> V_39 = V_29 -> V_39 ;
V_27 -> V_40 = V_29 -> V_40 ;
V_27 -> V_41 = V_29 -> V_41 ;
V_27 -> V_42 = V_29 -> V_42 ;
V_27 -> V_43 = V_29 -> V_43 ;
F_25 ( & V_27 -> V_44 , V_29 -> V_44 ) ;
if ( V_29 -> V_45 )
F_25 ( & V_27 -> V_45 ,
V_29 -> V_45 ) ;
}
static void F_26 ( struct V_46 * V_47 ,
struct V_48 * V_49 )
{
V_47 -> V_30 = V_49 -> V_30 ;
V_47 -> V_31 = V_49 -> V_31 ;
V_47 -> V_32 = V_49 -> V_32 ;
V_47 -> V_34 = V_49 -> V_34 ;
V_47 -> V_35 = V_49 -> V_35 ;
V_47 -> V_36 = V_49 -> V_36 ;
V_47 -> V_50 = V_49 -> V_50 ;
V_47 -> V_51 = V_49 -> V_51 ;
V_47 -> V_38 = V_49 -> V_38 ;
V_47 -> V_41 = V_49 -> V_41 ;
V_47 -> V_42 = V_49 -> V_42 ;
}
static void F_27 ( struct V_52 * V_47 ,
struct V_53 * V_49 )
{
V_47 -> V_54 = V_49 -> V_54 ;
V_47 -> V_55 = V_49 -> V_55 ;
V_47 -> V_56 = V_49 -> V_56 ;
}
static int F_28 ( struct V_57 * V_58 ,
struct V_15 * V_59 )
{
void * V_60 = NULL ;
switch ( V_58 -> V_12 ) {
case V_13 :
F_24 ( & V_59 -> V_22 . V_61 . V_62 ,
& V_58 -> V_63 . V_64 ) ;
V_59 -> V_65 = V_66 ;
V_59 -> V_22 . V_67 = V_68 ;
V_59 -> V_22 . V_67 |= ( V_58 -> V_63 . V_64 . V_45 ?
V_69 : 0 ) ;
break;
case V_70 :
F_26 ( & V_59 -> V_22 . V_61 . V_71 ,
& V_58 -> V_63 . V_72 ) ;
V_59 -> V_65 = V_73 ;
break;
case V_74 :
V_59 -> V_65 = V_75 ;
V_59 -> V_22 . V_61 . V_76 = V_58 -> V_63 . V_76 ;
break;
case V_77 :
V_59 -> V_65 = V_78 ;
V_59 -> V_22 . V_61 . V_76 = V_58 -> V_63 . V_76 ;
break;
case V_79 :
V_59 -> V_65 = V_80 ;
V_59 -> V_22 . V_61 . V_76 = V_58 -> V_63 . V_76 ;
break;
case V_81 :
V_59 -> V_22 . V_61 . V_82 . V_83 =
V_58 -> V_63 . V_84 . V_85 ;
V_59 -> V_65 = V_86 ;
break;
case V_87 :
V_59 -> V_22 . V_61 . V_88 . V_89 = V_58 -> V_63 . V_90 . V_89 ;
V_59 -> V_65 = V_91 ;
V_59 -> V_92 = V_58 -> V_63 . V_90 . V_93 ;
V_60 = V_58 -> V_63 . V_90 . V_94 ;
break;
case V_95 :
F_25 ( & V_59 -> V_22 . V_61 . V_96 . V_97 ,
V_58 -> V_63 . V_98 . V_45 ) ;
V_59 -> V_65 = V_99 ;
V_59 -> V_22 . V_67 = V_69 ;
break;
case V_100 :
V_59 -> V_22 . V_61 . V_101 . V_54 = V_58 -> V_63 . V_102 . V_103 ;
V_59 -> V_65 = V_104 ;
V_59 -> V_92 = V_58 -> V_63 . V_102 . V_92 ;
V_60 = V_58 -> V_63 . V_102 . V_105 ;
break;
case V_14 :
V_59 -> V_22 . V_61 . V_106 . V_107 =
V_58 -> V_63 . V_108 . V_107 ;
V_59 -> V_22 . V_61 . V_106 . V_43 =
V_58 -> V_63 . V_108 . V_43 ;
V_59 -> V_65 = V_109 ;
break;
case V_110 :
F_27 ( & V_59 -> V_22 . V_61 . V_111 ,
& V_58 -> V_63 . V_112 ) ;
V_59 -> V_65 = V_113 ;
V_59 -> V_92 = V_58 -> V_63 . V_112 . V_92 ;
V_60 = V_58 -> V_63 . V_112 . V_60 ;
break;
default:
V_59 -> V_22 . V_61 . V_76 = V_58 -> V_63 . V_76 ;
break;
}
if ( V_59 -> V_65 ) {
V_59 -> V_114 = F_29 ( V_58 -> V_115 , V_59 -> V_65 , V_24 ) ;
if ( ! V_59 -> V_114 )
goto V_116;
V_59 -> V_22 . V_67 |= V_117 ;
}
if ( V_59 -> V_92 ) {
V_59 -> V_60 = F_29 ( V_60 , V_59 -> V_92 , V_24 ) ;
if ( ! V_59 -> V_60 )
goto V_118;
V_59 -> V_22 . V_67 |= V_119 ;
}
return 0 ;
V_118:
F_16 ( V_59 -> V_114 ) ;
V_116:
return - V_120 ;
}
static int F_30 ( struct V_121 * V_23 ,
struct V_57 * V_12 )
{
struct V_15 * V_16 ;
struct V_1 * V_5 ;
int V_122 = 0 ;
V_5 = V_23 -> V_123 ;
V_16 = F_18 ( sizeof *V_16 , V_24 ) ;
if ( ! V_16 )
goto V_116;
V_16 -> V_5 = V_5 ;
V_16 -> V_23 = V_23 ;
V_16 -> V_22 . V_124 = V_5 -> V_124 ;
V_16 -> V_22 . V_4 = V_5 -> V_4 ;
V_16 -> V_22 . V_12 = V_12 -> V_12 ;
V_122 = F_28 ( V_12 , V_16 ) ;
if ( V_122 )
goto V_118;
F_2 ( & V_5 -> V_3 -> V_17 ) ;
F_23 ( & V_16 -> V_18 , & V_5 -> V_3 -> V_19 ) ;
F_23 ( & V_16 -> V_21 , & V_5 -> V_19 ) ;
F_31 ( & V_5 -> V_3 -> V_125 ) ;
F_6 ( & V_5 -> V_3 -> V_17 ) ;
return 0 ;
V_118:
F_16 ( V_16 ) ;
V_116:
return F_10 ( V_12 -> V_12 ) ;
}
static T_1 V_15 ( struct V_2 * V_3 ,
const char T_2 * V_126 ,
int V_127 , int V_128 )
{
struct V_1 * V_5 ;
struct V_129 V_130 ;
struct V_15 * V_16 ;
int V_122 = 0 ;
if ( V_128 < sizeof( struct V_131 ) )
return - V_132 ;
if ( F_32 ( & V_130 , V_126 , sizeof( V_130 ) ) )
return - V_133 ;
F_2 ( & V_3 -> V_17 ) ;
while ( F_13 ( & V_3 -> V_19 ) ) {
F_6 ( & V_3 -> V_17 ) ;
if ( V_3 -> V_134 -> V_135 & V_136 )
return - V_137 ;
if ( F_33 ( V_3 -> V_125 ,
! F_13 ( & V_3 -> V_19 ) ) )
return - V_138 ;
F_2 ( & V_3 -> V_17 ) ;
}
V_16 = F_14 ( V_3 -> V_19 . V_20 , struct V_15 , V_18 ) ;
if ( F_10 ( V_16 -> V_22 . V_12 ) ) {
V_5 = F_17 ( V_3 ) ;
if ( ! V_5 ) {
V_122 = - V_120 ;
goto V_139;
}
V_5 -> V_23 = V_16 -> V_23 ;
V_5 -> V_23 -> V_123 = V_5 ;
V_16 -> V_22 . V_4 = V_5 -> V_4 ;
}
if ( F_34 ( ( void T_2 * ) ( unsigned long ) V_130 . V_140 ,
& V_16 -> V_22 , sizeof( V_16 -> V_22 ) ) ) {
V_122 = - V_133 ;
goto V_139;
}
if ( V_16 -> V_114 ) {
if ( V_130 . V_65 < V_16 -> V_65 ) {
V_122 = - V_120 ;
goto V_139;
}
if ( F_34 ( ( void T_2 * ) ( unsigned long ) V_130 . V_114 ,
V_16 -> V_114 , V_16 -> V_65 ) ) {
V_122 = - V_133 ;
goto V_139;
}
}
if ( V_16 -> V_60 ) {
if ( V_130 . V_92 < V_16 -> V_92 ) {
V_122 = - V_120 ;
goto V_139;
}
if ( F_34 ( ( void T_2 * ) ( unsigned long ) V_130 . V_60 ,
V_16 -> V_60 , V_16 -> V_92 ) ) {
V_122 = - V_133 ;
goto V_139;
}
}
F_12 ( & V_16 -> V_18 ) ;
F_12 ( & V_16 -> V_21 ) ;
V_16 -> V_5 -> V_141 ++ ;
F_16 ( V_16 -> V_114 ) ;
F_16 ( V_16 -> V_60 ) ;
F_16 ( V_16 ) ;
V_139:
F_6 ( & V_3 -> V_17 ) ;
return V_122 ;
}
static T_1 F_35 ( struct V_2 * V_3 ,
const char T_2 * V_126 ,
int V_127 , int V_128 )
{
struct F_35 V_130 ;
struct V_142 V_22 ;
struct V_1 * V_5 ;
int V_122 ;
if ( V_128 < sizeof( V_22 ) )
return - V_132 ;
if ( F_32 ( & V_130 , V_126 , sizeof( V_130 ) ) )
return - V_133 ;
F_2 ( & V_3 -> V_17 ) ;
V_5 = F_17 ( V_3 ) ;
F_6 ( & V_3 -> V_17 ) ;
if ( ! V_5 )
return - V_120 ;
V_5 -> V_124 = V_130 . V_124 ;
V_5 -> V_23 = F_36 ( V_3 -> V_143 -> V_144 ,
F_30 , V_5 ) ;
if ( F_37 ( V_5 -> V_23 ) ) {
V_122 = F_38 ( V_5 -> V_23 ) ;
goto V_116;
}
V_22 . V_4 = V_5 -> V_4 ;
if ( F_34 ( ( void T_2 * ) ( unsigned long ) V_130 . V_140 ,
& V_22 , sizeof( V_22 ) ) ) {
V_122 = - V_133 ;
goto V_118;
}
return 0 ;
V_118:
F_15 ( V_5 -> V_23 ) ;
V_116:
F_2 ( & V_6 ) ;
F_39 ( & V_7 , V_5 -> V_4 ) ;
F_6 ( & V_6 ) ;
F_16 ( V_5 ) ;
return V_122 ;
}
static T_1 F_40 ( struct V_2 * V_3 ,
const char T_2 * V_126 ,
int V_127 , int V_128 )
{
struct F_40 V_130 ;
struct V_145 V_22 ;
struct V_1 * V_5 ;
int V_122 = 0 ;
if ( V_128 < sizeof( V_22 ) )
return - V_132 ;
if ( F_32 ( & V_130 , V_126 , sizeof( V_130 ) ) )
return - V_133 ;
F_2 ( & V_6 ) ;
V_5 = F_3 ( & V_7 , V_130 . V_4 ) ;
if ( ! V_5 )
V_5 = F_4 ( - V_8 ) ;
else if ( V_5 -> V_3 != V_3 )
V_5 = F_4 ( - V_9 ) ;
else
F_39 ( & V_7 , V_5 -> V_4 ) ;
F_6 ( & V_6 ) ;
if ( F_37 ( V_5 ) )
return F_38 ( V_5 ) ;
F_7 ( V_5 ) ;
F_41 ( & V_5 -> V_11 ) ;
F_15 ( V_5 -> V_23 ) ;
F_11 ( V_5 ) ;
V_22 . V_141 = V_5 -> V_141 ;
if ( F_34 ( ( void T_2 * ) ( unsigned long ) V_130 . V_140 ,
& V_22 , sizeof( V_22 ) ) )
V_122 = - V_133 ;
F_16 ( V_5 ) ;
return V_122 ;
}
static T_1 F_42 ( struct V_2 * V_3 ,
const char T_2 * V_126 ,
int V_127 , int V_128 )
{
struct V_146 V_22 ;
struct F_42 V_130 ;
struct V_1 * V_5 ;
int V_122 = 0 ;
if ( V_128 < sizeof( V_22 ) )
return - V_132 ;
if ( F_32 ( & V_130 , V_126 , sizeof( V_130 ) ) )
return - V_133 ;
V_5 = F_1 ( V_3 , V_130 . V_4 ) ;
if ( F_37 ( V_5 ) )
return F_38 ( V_5 ) ;
V_22 . V_147 = V_5 -> V_23 -> V_147 ;
V_22 . V_148 = V_5 -> V_23 -> V_148 ;
V_22 . V_149 = V_5 -> V_23 -> V_149 ;
V_22 . V_150 = V_5 -> V_23 -> V_150 ;
if ( F_34 ( ( void T_2 * ) ( unsigned long ) V_130 . V_140 ,
& V_22 , sizeof( V_22 ) ) )
V_122 = - V_133 ;
F_7 ( V_5 ) ;
return V_122 ;
}
static T_1 F_43 ( struct V_2 * V_3 ,
const char T_2 * V_126 ,
int V_127 , int V_128 )
{
struct V_151 V_22 ;
struct F_43 V_130 ;
struct V_1 * V_5 ;
struct V_152 V_153 ;
int V_122 = 0 ;
if ( V_128 < sizeof( V_22 ) )
return - V_132 ;
if ( F_32 ( & V_130 , V_126 , sizeof( V_130 ) ) )
return - V_133 ;
V_5 = F_1 ( V_3 , V_130 . V_4 ) ;
if ( F_37 ( V_5 ) )
return F_38 ( V_5 ) ;
V_22 . V_154 = 0 ;
memset ( & V_153 , 0 , sizeof V_153 ) ;
V_153 . V_155 = V_130 . V_155 ;
V_122 = F_44 ( V_5 -> V_23 , & V_153 , & V_22 . V_154 ) ;
if ( V_122 )
goto V_156;
F_45 ( & V_22 , & V_153 ) ;
if ( F_34 ( ( void T_2 * ) ( unsigned long ) V_130 . V_140 ,
& V_22 , sizeof( V_22 ) ) )
V_122 = - V_133 ;
V_156:
F_7 ( V_5 ) ;
return V_122 ;
}
static int F_46 ( T_3 V_147 , T_3 V_148 )
{
V_147 &= V_148 ;
if ( ( ( V_147 & V_157 ) == V_158 ) ||
( ( V_147 & V_159 ) == V_160 ) )
return - V_9 ;
return 0 ;
}
static T_1 F_47 ( struct V_2 * V_3 ,
const char T_2 * V_126 ,
int V_127 , int V_128 )
{
struct F_47 V_130 ;
struct V_1 * V_5 ;
int V_122 ;
if ( F_32 ( & V_130 , V_126 , sizeof( V_130 ) ) )
return - V_133 ;
V_5 = F_1 ( V_3 , V_130 . V_4 ) ;
if ( F_37 ( V_5 ) )
return F_38 ( V_5 ) ;
V_122 = F_46 ( V_130 . V_147 , V_130 . V_148 ) ;
if ( V_122 )
goto V_156;
V_122 = F_48 ( V_5 -> V_23 , V_130 . V_147 , V_130 . V_148 ) ;
V_156:
F_7 ( V_5 ) ;
return V_122 ;
}
static T_1 F_49 ( struct V_2 * V_3 ,
const char T_2 * V_126 ,
int V_127 , int V_128 )
{
struct F_49 V_130 ;
struct V_1 * V_5 ;
int V_122 ;
if ( F_32 ( & V_130 , V_126 , sizeof( V_130 ) ) )
return - V_133 ;
V_5 = F_1 ( V_3 , V_130 . V_4 ) ;
if ( F_37 ( V_5 ) )
return F_38 ( V_5 ) ;
V_122 = F_50 ( V_5 -> V_23 , (enum V_161 ) V_130 . V_12 ) ;
F_7 ( V_5 ) ;
return V_122 ;
}
static int F_51 ( const void * * V_162 , T_4 V_163 , T_5 V_164 )
{
void * V_114 ;
* V_162 = NULL ;
if ( ! V_164 )
return 0 ;
V_114 = F_52 ( ( void T_2 * ) ( unsigned long ) V_163 , V_164 ) ;
if ( F_37 ( V_114 ) )
return F_38 ( V_114 ) ;
* V_162 = V_114 ;
return 0 ;
}
static int F_53 ( struct V_165 * * V_97 , T_4 V_163 )
{
struct V_166 V_167 ;
struct V_165 * V_168 ;
* V_97 = NULL ;
if ( ! V_163 )
return 0 ;
V_168 = F_54 ( sizeof( * V_168 ) , V_24 ) ;
if ( ! V_168 )
return - V_120 ;
if ( F_32 ( & V_167 , ( void T_2 * ) ( unsigned long ) V_163 ,
sizeof( V_167 ) ) ) {
F_16 ( V_168 ) ;
return - V_133 ;
}
F_55 ( V_168 , & V_167 ) ;
* V_97 = V_168 ;
return 0 ;
}
static T_1 F_56 ( struct V_2 * V_3 ,
const char T_2 * V_126 ,
int V_127 , int V_128 )
{
struct V_169 V_63 ;
struct V_1 * V_5 ;
struct V_170 V_130 ;
int V_122 ;
V_63 . V_115 = NULL ;
V_63 . V_44 = NULL ;
V_63 . V_45 = NULL ;
if ( F_32 ( & V_130 , V_126 , sizeof( V_130 ) ) )
return - V_133 ;
V_122 = F_51 ( & V_63 . V_115 , V_130 . V_114 , V_130 . V_164 ) ;
if ( V_122 )
goto V_139;
V_122 = F_53 ( & V_63 . V_44 , V_130 . V_44 ) ;
if ( V_122 )
goto V_139;
V_122 = F_53 ( & V_63 . V_45 , V_130 . V_45 ) ;
if ( V_122 )
goto V_139;
V_63 . V_171 = V_130 . V_164 ;
V_63 . V_147 = V_130 . V_172 ;
V_63 . V_173 = V_130 . V_56 ;
V_63 . V_33 = V_130 . V_33 ;
V_63 . V_34 = V_130 . V_174 ;
V_63 . V_175 = V_130 . V_175 ;
V_63 . V_35 = V_130 . V_35 ;
V_63 . V_36 = V_130 . V_36 ;
V_63 . V_39 = V_130 . V_39 ;
V_63 . V_38 = V_130 . V_38 ;
V_63 . V_37 = V_130 . V_37 ;
V_63 . V_40 = V_130 . V_40 ;
V_63 . V_41 = V_130 . V_41 ;
V_63 . V_176 = V_130 . V_176 ;
V_63 . V_42 = V_130 . V_42 ;
V_5 = F_1 ( V_3 , V_130 . V_4 ) ;
if ( ! F_37 ( V_5 ) ) {
V_122 = F_57 ( V_5 -> V_23 , & V_63 ) ;
F_7 ( V_5 ) ;
} else
V_122 = F_38 ( V_5 ) ;
V_139:
F_16 ( V_63 . V_115 ) ;
F_16 ( V_63 . V_44 ) ;
F_16 ( V_63 . V_45 ) ;
return V_122 ;
}
static T_1 F_58 ( struct V_2 * V_3 ,
const char T_2 * V_126 ,
int V_127 , int V_128 )
{
struct V_177 V_63 ;
struct V_1 * V_5 ;
struct V_178 V_130 ;
int V_122 ;
V_63 . V_115 = NULL ;
if ( F_32 ( & V_130 , V_126 , sizeof( V_130 ) ) )
return - V_133 ;
V_122 = F_51 ( & V_63 . V_115 , V_130 . V_114 , V_130 . V_164 ) ;
if ( V_122 )
return V_122 ;
V_63 . V_173 = V_130 . V_56 ;
V_63 . V_34 = V_130 . V_174 ;
V_63 . V_171 = V_130 . V_164 ;
V_63 . V_35 = V_130 . V_35 ;
V_63 . V_36 = V_130 . V_36 ;
V_63 . V_51 = V_130 . V_51 ;
V_63 . V_38 = V_130 . V_38 ;
V_63 . V_41 = V_130 . V_41 ;
V_63 . V_42 = V_130 . V_42 ;
V_5 = F_1 ( V_3 , V_130 . V_4 ) ;
if ( ! F_37 ( V_5 ) ) {
V_5 -> V_124 = V_130 . V_124 ;
V_122 = F_59 ( V_5 -> V_23 , & V_63 ) ;
F_7 ( V_5 ) ;
} else
V_122 = F_38 ( V_5 ) ;
F_16 ( V_63 . V_115 ) ;
return V_122 ;
}
static T_1 F_60 ( struct V_2 * V_3 ,
const char T_2 * V_126 , int V_127 ,
int (* F_61)( struct V_121 * V_23 ,
const void * V_115 ,
T_6 V_171 ) )
{
struct V_179 V_130 ;
struct V_1 * V_5 ;
const void * V_115 = NULL ;
int V_122 ;
if ( F_32 ( & V_130 , V_126 , sizeof( V_130 ) ) )
return - V_133 ;
V_122 = F_51 ( & V_115 , V_130 . V_114 , V_130 . V_164 ) ;
if ( V_122 )
return V_122 ;
V_5 = F_1 ( V_3 , V_130 . V_4 ) ;
if ( ! F_37 ( V_5 ) ) {
V_122 = F_61 ( V_5 -> V_23 , V_115 , V_130 . V_164 ) ;
F_7 ( V_5 ) ;
} else
V_122 = F_38 ( V_5 ) ;
F_16 ( V_115 ) ;
return V_122 ;
}
static T_1 F_62 ( struct V_2 * V_3 ,
const char T_2 * V_126 ,
int V_127 , int V_128 )
{
return F_60 ( V_3 , V_126 , V_127 , V_180 ) ;
}
static T_1 F_63 ( struct V_2 * V_3 ,
const char T_2 * V_126 ,
int V_127 , int V_128 )
{
return F_60 ( V_3 , V_126 , V_127 , V_181 ) ;
}
static T_1 F_64 ( struct V_2 * V_3 ,
const char T_2 * V_126 ,
int V_127 , int V_128 )
{
return F_60 ( V_3 , V_126 , V_127 , V_182 ) ;
}
static T_1 F_65 ( struct V_2 * V_3 ,
const char T_2 * V_126 , int V_127 ,
int (* F_61)( struct V_121 * V_23 ,
int V_54 ,
const void * V_60 ,
T_6 V_92 ,
const void * V_114 ,
T_6 V_65 ) )
{
struct V_1 * V_5 ;
struct V_183 V_130 ;
const void * V_114 = NULL ;
const void * V_60 = NULL ;
int V_122 ;
if ( F_32 ( & V_130 , V_126 , sizeof( V_130 ) ) )
return - V_133 ;
V_122 = F_51 ( & V_114 , V_130 . V_114 , V_130 . V_65 ) ;
if ( V_122 )
goto V_139;
V_122 = F_51 ( & V_60 , V_130 . V_60 , V_130 . V_92 ) ;
if ( V_122 )
goto V_139;
V_5 = F_1 ( V_3 , V_130 . V_4 ) ;
if ( ! F_37 ( V_5 ) ) {
V_122 = F_61 ( V_5 -> V_23 , V_130 . V_54 , V_60 , V_130 . V_92 ,
V_114 , V_130 . V_65 ) ;
F_7 ( V_5 ) ;
} else
V_122 = F_38 ( V_5 ) ;
V_139:
F_16 ( V_114 ) ;
F_16 ( V_60 ) ;
return V_122 ;
}
static T_1 F_66 ( struct V_2 * V_3 ,
const char T_2 * V_126 ,
int V_127 , int V_128 )
{
return F_65 ( V_3 , V_126 , V_127 , ( void * ) V_184 ) ;
}
static T_1 F_67 ( struct V_2 * V_3 ,
const char T_2 * V_126 ,
int V_127 , int V_128 )
{
return F_65 ( V_3 , V_126 , V_127 , ( void * ) V_185 ) ;
}
static T_1 F_68 ( struct V_2 * V_3 ,
const char T_2 * V_126 ,
int V_127 , int V_128 )
{
struct V_1 * V_5 ;
struct V_186 V_130 ;
const void * V_114 = NULL ;
int V_122 ;
if ( F_32 ( & V_130 , V_126 , sizeof( V_130 ) ) )
return - V_133 ;
V_122 = F_51 ( & V_114 , V_130 . V_114 , V_130 . V_164 ) ;
if ( V_122 )
return V_122 ;
V_5 = F_1 ( V_3 , V_130 . V_4 ) ;
if ( ! F_37 ( V_5 ) ) {
V_122 = F_69 ( V_5 -> V_23 , V_130 . V_83 , V_114 , V_130 . V_164 ) ;
F_7 ( V_5 ) ;
} else
V_122 = F_38 ( V_5 ) ;
F_16 ( V_114 ) ;
return V_122 ;
}
static T_1 F_70 ( struct V_2 * V_3 ,
const char T_2 * V_126 ,
int V_127 , int V_128 )
{
struct V_1 * V_5 ;
struct V_165 * V_97 = NULL ;
struct V_187 V_130 ;
const void * V_114 = NULL ;
int V_122 ;
if ( F_32 ( & V_130 , V_126 , sizeof( V_130 ) ) )
return - V_133 ;
V_122 = F_51 ( & V_114 , V_130 . V_114 , V_130 . V_164 ) ;
if ( V_122 )
goto V_139;
V_122 = F_53 ( & V_97 , V_130 . V_97 ) ;
if ( V_122 )
goto V_139;
V_5 = F_1 ( V_3 , V_130 . V_4 ) ;
if ( ! F_37 ( V_5 ) ) {
V_122 = F_71 ( V_5 -> V_23 , V_97 , V_114 , V_130 . V_164 ) ;
F_7 ( V_5 ) ;
} else
V_122 = F_38 ( V_5 ) ;
V_139:
F_16 ( V_114 ) ;
F_16 ( V_97 ) ;
return V_122 ;
}
static T_1 F_72 ( struct V_2 * V_3 ,
const char T_2 * V_126 ,
int V_127 , int V_128 )
{
struct V_188 V_63 ;
struct V_1 * V_5 ;
struct V_189 V_130 ;
int V_122 ;
V_63 . V_115 = NULL ;
V_63 . V_97 = NULL ;
if ( F_32 ( & V_130 , V_126 , sizeof( V_130 ) ) )
return - V_133 ;
V_122 = F_51 ( & V_63 . V_115 , V_130 . V_114 , V_130 . V_164 ) ;
if ( V_122 )
goto V_139;
V_122 = F_53 ( & V_63 . V_97 , V_130 . V_97 ) ;
if ( V_122 )
goto V_139;
V_63 . V_171 = V_130 . V_164 ;
V_63 . V_147 = V_130 . V_172 ;
V_63 . V_190 = V_130 . V_83 ;
V_63 . V_176 = V_130 . V_176 ;
V_5 = F_1 ( V_3 , V_130 . V_4 ) ;
if ( ! F_37 ( V_5 ) ) {
V_122 = F_73 ( V_5 -> V_23 , & V_63 ) ;
F_7 ( V_5 ) ;
} else
V_122 = F_38 ( V_5 ) ;
V_139:
F_16 ( V_63 . V_115 ) ;
F_16 ( V_63 . V_97 ) ;
return V_122 ;
}
static T_1 F_74 ( struct V_2 * V_3 ,
const char T_2 * V_126 ,
int V_127 , int V_128 )
{
struct V_191 V_63 ;
struct V_192 V_130 ;
struct V_1 * V_5 ;
int V_122 ;
V_63 . V_60 = NULL ;
if ( F_32 ( & V_130 , V_126 , sizeof( V_130 ) ) )
return - V_133 ;
V_122 = F_51 ( & V_63 . V_115 ,
V_130 . V_114 , V_130 . V_65 ) ;
if ( V_122 )
goto V_139;
V_122 = F_51 ( & V_63 . V_60 , V_130 . V_60 , V_130 . V_92 ) ;
if ( V_122 )
goto V_139;
V_63 . V_173 = V_130 . V_56 ;
V_63 . V_55 = V_130 . V_55 ;
V_63 . V_54 = V_130 . V_54 ;
V_63 . V_193 = V_130 . V_92 ;
V_63 . V_171 = V_130 . V_65 ;
V_5 = F_1 ( V_3 , V_130 . V_4 ) ;
if ( ! F_37 ( V_5 ) ) {
V_122 = F_75 ( V_5 -> V_23 , & V_63 ) ;
F_7 ( V_5 ) ;
} else
V_122 = F_38 ( V_5 ) ;
V_139:
F_16 ( V_63 . V_115 ) ;
F_16 ( V_63 . V_60 ) ;
return V_122 ;
}
static T_1 F_76 ( struct V_3 * V_134 , const char T_2 * V_194 ,
T_7 V_164 , T_8 * V_195 )
{
struct V_2 * V_3 = V_134 -> V_115 ;
struct V_196 V_197 ;
T_1 V_122 ;
if ( ! F_77 ( V_134 ) ) {
F_78 ( L_1 ,
F_79 ( V_198 ) , V_198 -> V_199 ) ;
return - V_200 ;
}
if ( V_164 < sizeof( V_197 ) )
return - V_9 ;
if ( F_32 ( & V_197 , V_194 , sizeof( V_197 ) ) )
return - V_133 ;
if ( V_197 . V_130 >= F_80 ( V_201 ) )
return - V_9 ;
if ( V_197 . V_202 + sizeof( V_197 ) > V_164 )
return - V_9 ;
V_122 = V_201 [ V_197 . V_130 ] ( V_3 , V_194 + sizeof( V_197 ) ,
V_197 . V_202 , V_197 . V_156 ) ;
if ( ! V_122 )
V_122 = V_164 ;
return V_122 ;
}
static unsigned int F_81 ( struct V_3 * V_134 ,
struct V_203 * V_204 )
{
struct V_2 * V_3 = V_134 -> V_115 ;
unsigned int V_205 = 0 ;
V_125 ( V_134 , & V_3 -> V_125 , V_204 ) ;
if ( ! F_13 ( & V_3 -> V_19 ) )
V_205 = V_206 | V_207 ;
return V_205 ;
}
static int F_82 ( struct V_208 * V_208 , struct V_3 * V_134 )
{
struct V_2 * V_3 ;
V_3 = F_54 ( sizeof( * V_3 ) , V_24 ) ;
if ( ! V_3 )
return - V_120 ;
F_21 ( & V_3 -> V_19 ) ;
F_21 ( & V_3 -> V_25 ) ;
F_83 ( & V_3 -> V_125 ) ;
F_84 ( & V_3 -> V_17 ) ;
V_134 -> V_115 = V_3 ;
V_3 -> V_134 = V_134 ;
V_3 -> V_143 = F_85 ( V_208 -> V_209 , struct V_210 , V_211 ) ;
return F_86 ( V_208 , V_134 ) ;
}
static int F_87 ( struct V_208 * V_208 , struct V_3 * V_134 )
{
struct V_2 * V_3 = V_134 -> V_115 ;
struct V_1 * V_5 ;
F_2 ( & V_3 -> V_17 ) ;
while ( ! F_13 ( & V_3 -> V_25 ) ) {
V_5 = F_14 ( V_3 -> V_25 . V_20 ,
struct V_1 , V_18 ) ;
F_6 ( & V_3 -> V_17 ) ;
F_2 ( & V_6 ) ;
F_39 ( & V_7 , V_5 -> V_4 ) ;
F_6 ( & V_6 ) ;
F_15 ( V_5 -> V_23 ) ;
F_11 ( V_5 ) ;
F_16 ( V_5 ) ;
F_2 ( & V_3 -> V_17 ) ;
}
F_6 ( & V_3 -> V_17 ) ;
F_16 ( V_3 ) ;
return 0 ;
}
static void F_88 ( struct V_143 * V_212 )
{
struct V_210 * V_213 ;
V_213 = F_85 ( V_212 , struct V_210 , V_212 ) ;
F_89 ( & V_213 -> V_211 ) ;
if ( V_213 -> V_214 < V_215 )
F_90 ( V_213 -> V_214 , V_216 ) ;
else
F_90 ( V_213 -> V_214 - V_215 , V_217 ) ;
F_16 ( V_213 ) ;
}
static T_1 F_91 ( struct V_143 * V_212 , struct V_218 * V_219 ,
char * V_194 )
{
struct V_210 * V_213 ;
V_213 = F_85 ( V_212 , struct V_210 , V_212 ) ;
return sprintf ( V_194 , L_2 , V_213 -> V_144 -> V_220 ) ;
}
static int F_92 ( void )
{
int V_221 ;
if ( ! V_222 ) {
V_221 = F_93 ( & V_222 , 0 , V_215 ,
L_3 ) ;
if ( V_221 ) {
F_94 ( L_4 ) ;
return V_221 ;
}
}
V_221 = F_95 ( V_217 , V_215 ) ;
if ( V_221 >= V_215 )
return - 1 ;
return V_221 ;
}
static void F_96 ( struct V_223 * V_143 )
{
int V_214 ;
T_9 V_224 ;
struct V_210 * V_213 ;
if ( ! V_143 -> V_225 || ! F_97 ( V_143 , 1 ) )
return;
V_213 = F_18 ( sizeof *V_213 , V_24 ) ;
if ( ! V_213 )
return;
V_213 -> V_144 = V_143 ;
V_214 = F_95 ( V_216 , V_215 ) ;
if ( V_214 >= V_215 ) {
V_214 = F_92 () ;
if ( V_214 < 0 )
goto V_226;
V_213 -> V_214 = V_214 + V_215 ;
V_224 = V_214 + V_222 ;
F_98 ( V_214 , V_217 ) ;
} else {
V_213 -> V_214 = V_214 ;
V_224 = V_214 + V_227 ;
F_98 ( V_214 , V_216 ) ;
}
F_99 ( & V_213 -> V_211 , & V_228 ) ;
V_213 -> V_211 . V_229 = V_230 ;
F_100 ( & V_213 -> V_211 . V_231 , L_5 , V_213 -> V_214 ) ;
if ( F_101 ( & V_213 -> V_211 , V_224 , 1 ) )
goto V_226;
V_213 -> V_212 . V_232 = & V_233 ;
V_213 -> V_212 . V_234 = V_143 -> V_212 . V_234 ;
V_213 -> V_212 . V_235 = V_213 -> V_211 . V_212 ;
V_213 -> V_212 . V_236 = F_88 ;
F_102 ( & V_213 -> V_212 , L_5 , V_213 -> V_214 ) ;
if ( F_103 ( & V_213 -> V_212 ) )
goto V_237;
if ( F_104 ( & V_213 -> V_212 , & V_238 ) )
goto V_239;
F_105 ( V_143 , & V_240 , V_213 ) ;
return;
V_239:
F_106 ( & V_213 -> V_212 ) ;
V_237:
F_89 ( & V_213 -> V_211 ) ;
if ( V_213 -> V_214 < V_215 )
F_90 ( V_214 , V_216 ) ;
else
F_90 ( V_214 , V_217 ) ;
V_226:
F_16 ( V_213 ) ;
return;
}
static void F_107 ( struct V_223 * V_143 , void * V_241 )
{
struct V_210 * V_213 = V_241 ;
if ( ! V_213 )
return;
F_106 ( & V_213 -> V_212 ) ;
}
static int T_10 F_108 ( void )
{
int V_221 ;
V_221 = F_109 ( V_227 , V_215 ,
L_3 ) ;
if ( V_221 ) {
F_94 ( L_6 ) ;
goto V_242;
}
V_221 = F_110 ( & V_233 , & V_243 . V_219 ) ;
if ( V_221 ) {
F_94 ( L_7 ) ;
goto V_244;
}
V_221 = F_111 ( & V_240 ) ;
if ( V_221 ) {
F_94 ( L_8 ) ;
goto V_245;
}
return 0 ;
V_245:
F_112 ( & V_233 , & V_243 . V_219 ) ;
V_244:
F_113 ( V_227 , V_215 ) ;
V_242:
return V_221 ;
}
static void T_11 F_114 ( void )
{
F_115 ( & V_240 ) ;
F_112 ( & V_233 , & V_243 . V_219 ) ;
F_113 ( V_227 , V_215 ) ;
if ( V_222 )
F_113 ( V_222 , V_215 ) ;
F_116 ( & V_7 ) ;
}

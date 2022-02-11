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
int V_24 ;
V_5 = F_18 ( sizeof *V_5 , V_25 ) ;
if ( ! V_5 )
return NULL ;
F_19 ( & V_5 -> V_10 , 1 ) ;
F_20 ( & V_5 -> V_11 ) ;
V_5 -> V_3 = V_3 ;
F_21 ( & V_5 -> V_19 ) ;
do {
V_24 = F_22 ( & V_7 , V_25 ) ;
if ( ! V_24 )
goto error;
F_2 ( & V_6 ) ;
V_24 = F_23 ( & V_7 , V_5 , & V_5 -> V_4 ) ;
F_6 ( & V_6 ) ;
} while ( V_24 == - V_26 );
if ( V_24 )
goto error;
F_24 ( & V_5 -> V_18 , & V_3 -> V_27 ) ;
return V_5 ;
error:
F_16 ( V_5 ) ;
return NULL ;
}
static void F_25 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
V_29 -> V_32 = V_31 -> V_32 ;
V_29 -> V_33 = V_31 -> V_33 ;
V_29 -> V_34 = V_31 -> V_34 ;
V_29 -> V_35 = V_31 -> V_35 ;
V_29 -> V_36 = V_31 -> V_36 ;
V_29 -> V_37 = V_31 -> V_37 ;
V_29 -> V_38 = V_31 -> V_38 ;
V_29 -> V_39 = V_31 -> V_39 ;
V_29 -> V_40 = V_31 -> V_40 ;
V_29 -> V_41 = V_31 -> V_41 ;
V_29 -> V_42 = V_31 -> V_42 ;
V_29 -> V_43 = V_31 -> V_43 ;
V_29 -> V_44 = V_31 -> V_44 ;
V_29 -> V_45 = V_31 -> V_45 ;
F_26 ( & V_29 -> V_46 , V_31 -> V_46 ) ;
if ( V_31 -> V_47 )
F_26 ( & V_29 -> V_47 ,
V_31 -> V_47 ) ;
}
static void F_27 ( struct V_48 * V_49 ,
struct V_50 * V_51 )
{
V_49 -> V_32 = V_51 -> V_32 ;
V_49 -> V_33 = V_51 -> V_33 ;
V_49 -> V_34 = V_51 -> V_34 ;
V_49 -> V_36 = V_51 -> V_36 ;
V_49 -> V_37 = V_51 -> V_37 ;
V_49 -> V_38 = V_51 -> V_38 ;
V_49 -> V_52 = V_51 -> V_52 ;
V_49 -> V_53 = V_51 -> V_53 ;
V_49 -> V_40 = V_51 -> V_40 ;
V_49 -> V_43 = V_51 -> V_43 ;
V_49 -> V_44 = V_51 -> V_44 ;
}
static void F_28 ( struct V_54 * V_49 ,
struct V_55 * V_51 )
{
V_49 -> V_56 = V_51 -> V_56 ;
V_49 -> V_57 = V_51 -> V_57 ;
V_49 -> V_58 = V_51 -> V_58 ;
}
static int F_29 ( struct V_59 * V_60 ,
struct V_15 * V_61 )
{
void * V_62 = NULL ;
switch ( V_60 -> V_12 ) {
case V_13 :
F_25 ( & V_61 -> V_22 . V_63 . V_64 ,
& V_60 -> V_65 . V_66 ) ;
V_61 -> V_67 = V_68 ;
V_61 -> V_22 . V_69 = V_70 ;
V_61 -> V_22 . V_69 |= ( V_60 -> V_65 . V_66 . V_47 ?
V_71 : 0 ) ;
break;
case V_72 :
F_27 ( & V_61 -> V_22 . V_63 . V_73 ,
& V_60 -> V_65 . V_74 ) ;
V_61 -> V_67 = V_75 ;
break;
case V_76 :
V_61 -> V_67 = V_77 ;
V_61 -> V_22 . V_63 . V_78 = V_60 -> V_65 . V_78 ;
break;
case V_79 :
V_61 -> V_67 = V_80 ;
V_61 -> V_22 . V_63 . V_78 = V_60 -> V_65 . V_78 ;
break;
case V_81 :
V_61 -> V_67 = V_82 ;
V_61 -> V_22 . V_63 . V_78 = V_60 -> V_65 . V_78 ;
break;
case V_83 :
V_61 -> V_22 . V_63 . V_84 . V_85 =
V_60 -> V_65 . V_86 . V_87 ;
V_61 -> V_67 = V_88 ;
break;
case V_89 :
V_61 -> V_22 . V_63 . V_90 . V_91 = V_60 -> V_65 . V_92 . V_91 ;
V_61 -> V_67 = V_93 ;
V_61 -> V_94 = V_60 -> V_65 . V_92 . V_95 ;
V_62 = V_60 -> V_65 . V_92 . V_96 ;
break;
case V_97 :
F_26 ( & V_61 -> V_22 . V_63 . V_98 . V_99 ,
V_60 -> V_65 . V_100 . V_47 ) ;
V_61 -> V_67 = V_101 ;
V_61 -> V_22 . V_69 = V_71 ;
break;
case V_102 :
V_61 -> V_22 . V_63 . V_103 . V_56 = V_60 -> V_65 . V_104 . V_105 ;
V_61 -> V_67 = V_106 ;
V_61 -> V_94 = V_60 -> V_65 . V_104 . V_94 ;
V_62 = V_60 -> V_65 . V_104 . V_107 ;
break;
case V_14 :
V_61 -> V_22 . V_63 . V_108 . V_109 =
V_60 -> V_65 . V_110 . V_109 ;
V_61 -> V_22 . V_63 . V_108 . V_45 =
V_60 -> V_65 . V_110 . V_45 ;
V_61 -> V_67 = V_111 ;
break;
case V_112 :
F_28 ( & V_61 -> V_22 . V_63 . V_113 ,
& V_60 -> V_65 . V_114 ) ;
V_61 -> V_67 = V_115 ;
V_61 -> V_94 = V_60 -> V_65 . V_114 . V_94 ;
V_62 = V_60 -> V_65 . V_114 . V_62 ;
break;
default:
V_61 -> V_22 . V_63 . V_78 = V_60 -> V_65 . V_78 ;
break;
}
if ( V_61 -> V_67 ) {
V_61 -> V_116 = F_30 ( V_60 -> V_117 , V_61 -> V_67 , V_25 ) ;
if ( ! V_61 -> V_116 )
goto V_118;
V_61 -> V_22 . V_69 |= V_119 ;
}
if ( V_61 -> V_94 ) {
V_61 -> V_62 = F_30 ( V_62 , V_61 -> V_94 , V_25 ) ;
if ( ! V_61 -> V_62 )
goto V_120;
V_61 -> V_22 . V_69 |= V_121 ;
}
return 0 ;
V_120:
F_16 ( V_61 -> V_116 ) ;
V_118:
return - V_122 ;
}
static int F_31 ( struct V_123 * V_23 ,
struct V_59 * V_12 )
{
struct V_15 * V_16 ;
struct V_1 * V_5 ;
int V_24 = 0 ;
V_5 = V_23 -> V_124 ;
V_16 = F_18 ( sizeof *V_16 , V_25 ) ;
if ( ! V_16 )
goto V_118;
V_16 -> V_5 = V_5 ;
V_16 -> V_23 = V_23 ;
V_16 -> V_22 . V_125 = V_5 -> V_125 ;
V_16 -> V_22 . V_4 = V_5 -> V_4 ;
V_16 -> V_22 . V_12 = V_12 -> V_12 ;
V_24 = F_29 ( V_12 , V_16 ) ;
if ( V_24 )
goto V_120;
F_2 ( & V_5 -> V_3 -> V_17 ) ;
F_24 ( & V_16 -> V_18 , & V_5 -> V_3 -> V_19 ) ;
F_24 ( & V_16 -> V_21 , & V_5 -> V_19 ) ;
F_32 ( & V_5 -> V_3 -> V_126 ) ;
F_6 ( & V_5 -> V_3 -> V_17 ) ;
return 0 ;
V_120:
F_16 ( V_16 ) ;
V_118:
return F_10 ( V_12 -> V_12 ) ;
}
static T_1 V_15 ( struct V_2 * V_3 ,
const char T_2 * V_127 ,
int V_128 , int V_129 )
{
struct V_1 * V_5 ;
struct V_130 V_131 ;
struct V_15 * V_16 ;
int V_24 = 0 ;
if ( V_129 < sizeof( struct V_132 ) )
return - V_133 ;
if ( F_33 ( & V_131 , V_127 , sizeof( V_131 ) ) )
return - V_134 ;
F_2 ( & V_3 -> V_17 ) ;
while ( F_13 ( & V_3 -> V_19 ) ) {
F_6 ( & V_3 -> V_17 ) ;
if ( V_3 -> V_135 -> V_136 & V_137 )
return - V_26 ;
if ( F_34 ( V_3 -> V_126 ,
! F_13 ( & V_3 -> V_19 ) ) )
return - V_138 ;
F_2 ( & V_3 -> V_17 ) ;
}
V_16 = F_14 ( V_3 -> V_19 . V_20 , struct V_15 , V_18 ) ;
if ( F_10 ( V_16 -> V_22 . V_12 ) ) {
V_5 = F_17 ( V_3 ) ;
if ( ! V_5 ) {
V_24 = - V_122 ;
goto V_139;
}
V_5 -> V_23 = V_16 -> V_23 ;
V_5 -> V_23 -> V_124 = V_5 ;
V_16 -> V_22 . V_4 = V_5 -> V_4 ;
}
if ( F_35 ( ( void T_2 * ) ( unsigned long ) V_131 . V_140 ,
& V_16 -> V_22 , sizeof( V_16 -> V_22 ) ) ) {
V_24 = - V_134 ;
goto V_139;
}
if ( V_16 -> V_116 ) {
if ( V_131 . V_67 < V_16 -> V_67 ) {
V_24 = - V_122 ;
goto V_139;
}
if ( F_35 ( ( void T_2 * ) ( unsigned long ) V_131 . V_116 ,
V_16 -> V_116 , V_16 -> V_67 ) ) {
V_24 = - V_134 ;
goto V_139;
}
}
if ( V_16 -> V_62 ) {
if ( V_131 . V_94 < V_16 -> V_94 ) {
V_24 = - V_122 ;
goto V_139;
}
if ( F_35 ( ( void T_2 * ) ( unsigned long ) V_131 . V_62 ,
V_16 -> V_62 , V_16 -> V_94 ) ) {
V_24 = - V_134 ;
goto V_139;
}
}
F_12 ( & V_16 -> V_18 ) ;
F_12 ( & V_16 -> V_21 ) ;
V_16 -> V_5 -> V_141 ++ ;
F_16 ( V_16 -> V_116 ) ;
F_16 ( V_16 -> V_62 ) ;
F_16 ( V_16 ) ;
V_139:
F_6 ( & V_3 -> V_17 ) ;
return V_24 ;
}
static T_1 F_36 ( struct V_2 * V_3 ,
const char T_2 * V_127 ,
int V_128 , int V_129 )
{
struct F_36 V_131 ;
struct V_142 V_22 ;
struct V_1 * V_5 ;
int V_24 ;
if ( V_129 < sizeof( V_22 ) )
return - V_133 ;
if ( F_33 ( & V_131 , V_127 , sizeof( V_131 ) ) )
return - V_134 ;
F_2 ( & V_3 -> V_17 ) ;
V_5 = F_17 ( V_3 ) ;
F_6 ( & V_3 -> V_17 ) ;
if ( ! V_5 )
return - V_122 ;
V_5 -> V_125 = V_131 . V_125 ;
V_5 -> V_23 = F_37 ( V_3 -> V_143 -> V_144 ,
F_31 , V_5 ) ;
if ( F_38 ( V_5 -> V_23 ) ) {
V_24 = F_39 ( V_5 -> V_23 ) ;
goto V_118;
}
V_22 . V_4 = V_5 -> V_4 ;
if ( F_35 ( ( void T_2 * ) ( unsigned long ) V_131 . V_140 ,
& V_22 , sizeof( V_22 ) ) ) {
V_24 = - V_134 ;
goto V_120;
}
return 0 ;
V_120:
F_15 ( V_5 -> V_23 ) ;
V_118:
F_2 ( & V_6 ) ;
F_40 ( & V_7 , V_5 -> V_4 ) ;
F_6 ( & V_6 ) ;
F_16 ( V_5 ) ;
return V_24 ;
}
static T_1 F_41 ( struct V_2 * V_3 ,
const char T_2 * V_127 ,
int V_128 , int V_129 )
{
struct F_41 V_131 ;
struct V_145 V_22 ;
struct V_1 * V_5 ;
int V_24 = 0 ;
if ( V_129 < sizeof( V_22 ) )
return - V_133 ;
if ( F_33 ( & V_131 , V_127 , sizeof( V_131 ) ) )
return - V_134 ;
F_2 ( & V_6 ) ;
V_5 = F_3 ( & V_7 , V_131 . V_4 ) ;
if ( ! V_5 )
V_5 = F_4 ( - V_8 ) ;
else if ( V_5 -> V_3 != V_3 )
V_5 = F_4 ( - V_9 ) ;
else
F_40 ( & V_7 , V_5 -> V_4 ) ;
F_6 ( & V_6 ) ;
if ( F_38 ( V_5 ) )
return F_39 ( V_5 ) ;
F_7 ( V_5 ) ;
F_42 ( & V_5 -> V_11 ) ;
F_15 ( V_5 -> V_23 ) ;
F_11 ( V_5 ) ;
V_22 . V_141 = V_5 -> V_141 ;
if ( F_35 ( ( void T_2 * ) ( unsigned long ) V_131 . V_140 ,
& V_22 , sizeof( V_22 ) ) )
V_24 = - V_134 ;
F_16 ( V_5 ) ;
return V_24 ;
}
static T_1 F_43 ( struct V_2 * V_3 ,
const char T_2 * V_127 ,
int V_128 , int V_129 )
{
struct V_146 V_22 ;
struct F_43 V_131 ;
struct V_1 * V_5 ;
int V_24 = 0 ;
if ( V_129 < sizeof( V_22 ) )
return - V_133 ;
if ( F_33 ( & V_131 , V_127 , sizeof( V_131 ) ) )
return - V_134 ;
V_5 = F_1 ( V_3 , V_131 . V_4 ) ;
if ( F_38 ( V_5 ) )
return F_39 ( V_5 ) ;
V_22 . V_147 = V_5 -> V_23 -> V_147 ;
V_22 . V_148 = V_5 -> V_23 -> V_148 ;
V_22 . V_149 = V_5 -> V_23 -> V_149 ;
V_22 . V_150 = V_5 -> V_23 -> V_150 ;
if ( F_35 ( ( void T_2 * ) ( unsigned long ) V_131 . V_140 ,
& V_22 , sizeof( V_22 ) ) )
V_24 = - V_134 ;
F_7 ( V_5 ) ;
return V_24 ;
}
static T_1 F_44 ( struct V_2 * V_3 ,
const char T_2 * V_127 ,
int V_128 , int V_129 )
{
struct V_151 V_22 ;
struct F_44 V_131 ;
struct V_1 * V_5 ;
struct V_152 V_153 ;
int V_24 = 0 ;
if ( V_129 < sizeof( V_22 ) )
return - V_133 ;
if ( F_33 ( & V_131 , V_127 , sizeof( V_131 ) ) )
return - V_134 ;
V_5 = F_1 ( V_3 , V_131 . V_4 ) ;
if ( F_38 ( V_5 ) )
return F_39 ( V_5 ) ;
V_22 . V_154 = 0 ;
memset ( & V_153 , 0 , sizeof V_153 ) ;
V_153 . V_155 = V_131 . V_155 ;
V_24 = F_45 ( V_5 -> V_23 , & V_153 , & V_22 . V_154 ) ;
if ( V_24 )
goto V_156;
F_46 ( & V_22 , & V_153 ) ;
if ( F_35 ( ( void T_2 * ) ( unsigned long ) V_131 . V_140 ,
& V_22 , sizeof( V_22 ) ) )
V_24 = - V_134 ;
V_156:
F_7 ( V_5 ) ;
return V_24 ;
}
static int F_47 ( T_3 V_147 , T_3 V_148 )
{
V_147 &= V_148 ;
if ( ( ( V_147 & V_157 ) == V_158 ) ||
( ( V_147 & V_159 ) == V_160 ) )
return - V_9 ;
return 0 ;
}
static T_1 F_48 ( struct V_2 * V_3 ,
const char T_2 * V_127 ,
int V_128 , int V_129 )
{
struct F_48 V_131 ;
struct V_1 * V_5 ;
int V_24 ;
if ( F_33 ( & V_131 , V_127 , sizeof( V_131 ) ) )
return - V_134 ;
V_5 = F_1 ( V_3 , V_131 . V_4 ) ;
if ( F_38 ( V_5 ) )
return F_39 ( V_5 ) ;
V_24 = F_47 ( V_131 . V_147 , V_131 . V_148 ) ;
if ( V_24 )
goto V_156;
V_24 = F_49 ( V_5 -> V_23 , V_131 . V_147 , V_131 . V_148 ,
NULL ) ;
V_156:
F_7 ( V_5 ) ;
return V_24 ;
}
static T_1 F_50 ( struct V_2 * V_3 ,
const char T_2 * V_127 ,
int V_128 , int V_129 )
{
struct F_50 V_131 ;
struct V_1 * V_5 ;
int V_24 ;
if ( F_33 ( & V_131 , V_127 , sizeof( V_131 ) ) )
return - V_134 ;
V_5 = F_1 ( V_3 , V_131 . V_4 ) ;
if ( F_38 ( V_5 ) )
return F_39 ( V_5 ) ;
V_24 = F_51 ( V_5 -> V_23 , (enum V_161 ) V_131 . V_12 ) ;
F_7 ( V_5 ) ;
return V_24 ;
}
static int F_52 ( const void * * V_162 , T_4 V_163 , T_5 V_164 )
{
void * V_116 ;
* V_162 = NULL ;
if ( ! V_164 )
return 0 ;
V_116 = F_53 ( ( void T_2 * ) ( unsigned long ) V_163 , V_164 ) ;
if ( F_38 ( V_116 ) )
return F_39 ( V_116 ) ;
* V_162 = V_116 ;
return 0 ;
}
static int F_54 ( struct V_165 * * V_99 , T_4 V_163 )
{
struct V_166 V_167 ;
struct V_165 * V_168 ;
* V_99 = NULL ;
if ( ! V_163 )
return 0 ;
V_168 = F_55 ( sizeof( * V_168 ) , V_25 ) ;
if ( ! V_168 )
return - V_122 ;
if ( F_33 ( & V_167 , ( void T_2 * ) ( unsigned long ) V_163 ,
sizeof( V_167 ) ) ) {
F_16 ( V_168 ) ;
return - V_134 ;
}
F_56 ( V_168 , & V_167 ) ;
* V_99 = V_168 ;
return 0 ;
}
static T_1 F_57 ( struct V_2 * V_3 ,
const char T_2 * V_127 ,
int V_128 , int V_129 )
{
struct V_169 V_65 ;
struct V_1 * V_5 ;
struct V_170 V_131 ;
int V_24 ;
V_65 . V_117 = NULL ;
V_65 . V_46 = NULL ;
V_65 . V_47 = NULL ;
if ( F_33 ( & V_131 , V_127 , sizeof( V_131 ) ) )
return - V_134 ;
V_24 = F_52 ( & V_65 . V_117 , V_131 . V_116 , V_131 . V_164 ) ;
if ( V_24 )
goto V_139;
V_24 = F_54 ( & V_65 . V_46 , V_131 . V_46 ) ;
if ( V_24 )
goto V_139;
V_24 = F_54 ( & V_65 . V_47 , V_131 . V_47 ) ;
if ( V_24 )
goto V_139;
V_65 . V_171 = V_131 . V_164 ;
V_65 . V_147 = V_131 . V_172 ;
V_65 . V_173 = V_131 . V_58 ;
V_65 . V_35 = V_131 . V_35 ;
V_65 . V_36 = V_131 . V_174 ;
V_65 . V_175 = V_131 . V_175 ;
V_65 . V_37 = V_131 . V_37 ;
V_65 . V_38 = V_131 . V_38 ;
V_65 . V_41 = V_131 . V_41 ;
V_65 . V_40 = V_131 . V_40 ;
V_65 . V_39 = V_131 . V_39 ;
V_65 . V_42 = V_131 . V_42 ;
V_65 . V_43 = V_131 . V_43 ;
V_65 . V_176 = V_131 . V_176 ;
V_65 . V_44 = V_131 . V_44 ;
V_5 = F_1 ( V_3 , V_131 . V_4 ) ;
if ( ! F_38 ( V_5 ) ) {
V_24 = F_58 ( V_5 -> V_23 , & V_65 ) ;
F_7 ( V_5 ) ;
} else
V_24 = F_39 ( V_5 ) ;
V_139:
F_16 ( V_65 . V_117 ) ;
F_16 ( V_65 . V_46 ) ;
F_16 ( V_65 . V_47 ) ;
return V_24 ;
}
static T_1 F_59 ( struct V_2 * V_3 ,
const char T_2 * V_127 ,
int V_128 , int V_129 )
{
struct V_177 V_65 ;
struct V_1 * V_5 ;
struct V_178 V_131 ;
int V_24 ;
V_65 . V_117 = NULL ;
if ( F_33 ( & V_131 , V_127 , sizeof( V_131 ) ) )
return - V_134 ;
V_24 = F_52 ( & V_65 . V_117 , V_131 . V_116 , V_131 . V_164 ) ;
if ( V_24 )
return V_24 ;
V_65 . V_173 = V_131 . V_58 ;
V_65 . V_36 = V_131 . V_174 ;
V_65 . V_171 = V_131 . V_164 ;
V_65 . V_37 = V_131 . V_37 ;
V_65 . V_38 = V_131 . V_38 ;
V_65 . V_53 = V_131 . V_53 ;
V_65 . V_40 = V_131 . V_40 ;
V_65 . V_43 = V_131 . V_43 ;
V_65 . V_44 = V_131 . V_44 ;
V_5 = F_1 ( V_3 , V_131 . V_4 ) ;
if ( ! F_38 ( V_5 ) ) {
V_5 -> V_125 = V_131 . V_125 ;
V_24 = F_60 ( V_5 -> V_23 , & V_65 ) ;
F_7 ( V_5 ) ;
} else
V_24 = F_39 ( V_5 ) ;
F_16 ( V_65 . V_117 ) ;
return V_24 ;
}
static T_1 F_61 ( struct V_2 * V_3 ,
const char T_2 * V_127 , int V_128 ,
int (* F_62)( struct V_123 * V_23 ,
const void * V_117 ,
T_6 V_171 ) )
{
struct V_179 V_131 ;
struct V_1 * V_5 ;
const void * V_117 = NULL ;
int V_24 ;
if ( F_33 ( & V_131 , V_127 , sizeof( V_131 ) ) )
return - V_134 ;
V_24 = F_52 ( & V_117 , V_131 . V_116 , V_131 . V_164 ) ;
if ( V_24 )
return V_24 ;
V_5 = F_1 ( V_3 , V_131 . V_4 ) ;
if ( ! F_38 ( V_5 ) ) {
V_24 = F_62 ( V_5 -> V_23 , V_117 , V_131 . V_164 ) ;
F_7 ( V_5 ) ;
} else
V_24 = F_39 ( V_5 ) ;
F_16 ( V_117 ) ;
return V_24 ;
}
static T_1 F_63 ( struct V_2 * V_3 ,
const char T_2 * V_127 ,
int V_128 , int V_129 )
{
return F_61 ( V_3 , V_127 , V_128 , V_180 ) ;
}
static T_1 F_64 ( struct V_2 * V_3 ,
const char T_2 * V_127 ,
int V_128 , int V_129 )
{
return F_61 ( V_3 , V_127 , V_128 , V_181 ) ;
}
static T_1 F_65 ( struct V_2 * V_3 ,
const char T_2 * V_127 ,
int V_128 , int V_129 )
{
return F_61 ( V_3 , V_127 , V_128 , V_182 ) ;
}
static T_1 F_66 ( struct V_2 * V_3 ,
const char T_2 * V_127 , int V_128 ,
int (* F_62)( struct V_123 * V_23 ,
int V_56 ,
const void * V_62 ,
T_6 V_94 ,
const void * V_116 ,
T_6 V_67 ) )
{
struct V_1 * V_5 ;
struct V_183 V_131 ;
const void * V_116 = NULL ;
const void * V_62 = NULL ;
int V_24 ;
if ( F_33 ( & V_131 , V_127 , sizeof( V_131 ) ) )
return - V_134 ;
V_24 = F_52 ( & V_116 , V_131 . V_116 , V_131 . V_67 ) ;
if ( V_24 )
goto V_139;
V_24 = F_52 ( & V_62 , V_131 . V_62 , V_131 . V_94 ) ;
if ( V_24 )
goto V_139;
V_5 = F_1 ( V_3 , V_131 . V_4 ) ;
if ( ! F_38 ( V_5 ) ) {
V_24 = F_62 ( V_5 -> V_23 , V_131 . V_56 , V_62 , V_131 . V_94 ,
V_116 , V_131 . V_67 ) ;
F_7 ( V_5 ) ;
} else
V_24 = F_39 ( V_5 ) ;
V_139:
F_16 ( V_116 ) ;
F_16 ( V_62 ) ;
return V_24 ;
}
static T_1 F_67 ( struct V_2 * V_3 ,
const char T_2 * V_127 ,
int V_128 , int V_129 )
{
return F_66 ( V_3 , V_127 , V_128 , ( void * ) V_184 ) ;
}
static T_1 F_68 ( struct V_2 * V_3 ,
const char T_2 * V_127 ,
int V_128 , int V_129 )
{
return F_66 ( V_3 , V_127 , V_128 , ( void * ) V_185 ) ;
}
static T_1 F_69 ( struct V_2 * V_3 ,
const char T_2 * V_127 ,
int V_128 , int V_129 )
{
struct V_1 * V_5 ;
struct V_186 V_131 ;
const void * V_116 = NULL ;
int V_24 ;
if ( F_33 ( & V_131 , V_127 , sizeof( V_131 ) ) )
return - V_134 ;
V_24 = F_52 ( & V_116 , V_131 . V_116 , V_131 . V_164 ) ;
if ( V_24 )
return V_24 ;
V_5 = F_1 ( V_3 , V_131 . V_4 ) ;
if ( ! F_38 ( V_5 ) ) {
V_24 = F_70 ( V_5 -> V_23 , V_131 . V_85 , V_116 , V_131 . V_164 ) ;
F_7 ( V_5 ) ;
} else
V_24 = F_39 ( V_5 ) ;
F_16 ( V_116 ) ;
return V_24 ;
}
static T_1 F_71 ( struct V_2 * V_3 ,
const char T_2 * V_127 ,
int V_128 , int V_129 )
{
struct V_1 * V_5 ;
struct V_165 * V_99 = NULL ;
struct V_187 V_131 ;
const void * V_116 = NULL ;
int V_24 ;
if ( F_33 ( & V_131 , V_127 , sizeof( V_131 ) ) )
return - V_134 ;
V_24 = F_52 ( & V_116 , V_131 . V_116 , V_131 . V_164 ) ;
if ( V_24 )
goto V_139;
V_24 = F_54 ( & V_99 , V_131 . V_99 ) ;
if ( V_24 )
goto V_139;
V_5 = F_1 ( V_3 , V_131 . V_4 ) ;
if ( ! F_38 ( V_5 ) ) {
V_24 = F_72 ( V_5 -> V_23 , V_99 , V_116 , V_131 . V_164 ) ;
F_7 ( V_5 ) ;
} else
V_24 = F_39 ( V_5 ) ;
V_139:
F_16 ( V_116 ) ;
F_16 ( V_99 ) ;
return V_24 ;
}
static T_1 F_73 ( struct V_2 * V_3 ,
const char T_2 * V_127 ,
int V_128 , int V_129 )
{
struct V_188 V_65 ;
struct V_1 * V_5 ;
struct V_189 V_131 ;
int V_24 ;
V_65 . V_117 = NULL ;
V_65 . V_99 = NULL ;
if ( F_33 ( & V_131 , V_127 , sizeof( V_131 ) ) )
return - V_134 ;
V_24 = F_52 ( & V_65 . V_117 , V_131 . V_116 , V_131 . V_164 ) ;
if ( V_24 )
goto V_139;
V_24 = F_54 ( & V_65 . V_99 , V_131 . V_99 ) ;
if ( V_24 )
goto V_139;
V_65 . V_171 = V_131 . V_164 ;
V_65 . V_147 = V_131 . V_172 ;
V_65 . V_190 = V_131 . V_85 ;
V_65 . V_176 = V_131 . V_176 ;
V_5 = F_1 ( V_3 , V_131 . V_4 ) ;
if ( ! F_38 ( V_5 ) ) {
V_24 = F_74 ( V_5 -> V_23 , & V_65 ) ;
F_7 ( V_5 ) ;
} else
V_24 = F_39 ( V_5 ) ;
V_139:
F_16 ( V_65 . V_117 ) ;
F_16 ( V_65 . V_99 ) ;
return V_24 ;
}
static T_1 F_75 ( struct V_2 * V_3 ,
const char T_2 * V_127 ,
int V_128 , int V_129 )
{
struct V_191 V_65 ;
struct V_192 V_131 ;
struct V_1 * V_5 ;
int V_24 ;
V_65 . V_62 = NULL ;
if ( F_33 ( & V_131 , V_127 , sizeof( V_131 ) ) )
return - V_134 ;
V_24 = F_52 ( & V_65 . V_117 ,
V_131 . V_116 , V_131 . V_67 ) ;
if ( V_24 )
goto V_139;
V_24 = F_52 ( & V_65 . V_62 , V_131 . V_62 , V_131 . V_94 ) ;
if ( V_24 )
goto V_139;
V_65 . V_173 = V_131 . V_58 ;
V_65 . V_57 = V_131 . V_57 ;
V_65 . V_56 = V_131 . V_56 ;
V_65 . V_193 = V_131 . V_94 ;
V_65 . V_171 = V_131 . V_67 ;
V_5 = F_1 ( V_3 , V_131 . V_4 ) ;
if ( ! F_38 ( V_5 ) ) {
V_24 = F_76 ( V_5 -> V_23 , & V_65 ) ;
F_7 ( V_5 ) ;
} else
V_24 = F_39 ( V_5 ) ;
V_139:
F_16 ( V_65 . V_117 ) ;
F_16 ( V_65 . V_62 ) ;
return V_24 ;
}
static T_1 F_77 ( struct V_3 * V_135 , const char T_2 * V_194 ,
T_7 V_164 , T_8 * V_195 )
{
struct V_2 * V_3 = V_135 -> V_117 ;
struct V_196 V_197 ;
T_1 V_24 ;
if ( V_164 < sizeof( V_197 ) )
return - V_9 ;
if ( F_33 ( & V_197 , V_194 , sizeof( V_197 ) ) )
return - V_134 ;
if ( V_197 . V_131 >= F_78 ( V_198 ) )
return - V_9 ;
if ( V_197 . V_199 + sizeof( V_197 ) > V_164 )
return - V_9 ;
V_24 = V_198 [ V_197 . V_131 ] ( V_3 , V_194 + sizeof( V_197 ) ,
V_197 . V_199 , V_197 . V_156 ) ;
if ( ! V_24 )
V_24 = V_164 ;
return V_24 ;
}
static unsigned int F_79 ( struct V_3 * V_135 ,
struct V_200 * V_201 )
{
struct V_2 * V_3 = V_135 -> V_117 ;
unsigned int V_202 = 0 ;
V_126 ( V_135 , & V_3 -> V_126 , V_201 ) ;
if ( ! F_13 ( & V_3 -> V_19 ) )
V_202 = V_203 | V_204 ;
return V_202 ;
}
static int F_80 ( struct V_205 * V_205 , struct V_3 * V_135 )
{
struct V_2 * V_3 ;
V_3 = F_55 ( sizeof( * V_3 ) , V_25 ) ;
if ( ! V_3 )
return - V_122 ;
F_21 ( & V_3 -> V_19 ) ;
F_21 ( & V_3 -> V_27 ) ;
F_81 ( & V_3 -> V_126 ) ;
F_82 ( & V_3 -> V_17 ) ;
V_135 -> V_117 = V_3 ;
V_3 -> V_135 = V_135 ;
V_3 -> V_143 = F_83 ( V_205 -> V_206 , struct V_207 , V_208 ) ;
return F_84 ( V_205 , V_135 ) ;
}
static int F_85 ( struct V_205 * V_205 , struct V_3 * V_135 )
{
struct V_2 * V_3 = V_135 -> V_117 ;
struct V_1 * V_5 ;
F_2 ( & V_3 -> V_17 ) ;
while ( ! F_13 ( & V_3 -> V_27 ) ) {
V_5 = F_14 ( V_3 -> V_27 . V_20 ,
struct V_1 , V_18 ) ;
F_6 ( & V_3 -> V_17 ) ;
F_2 ( & V_6 ) ;
F_40 ( & V_7 , V_5 -> V_4 ) ;
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
static void F_86 ( struct V_143 * V_209 )
{
struct V_207 * V_210 ;
V_210 = F_83 ( V_209 , struct V_207 , V_209 ) ;
F_87 ( & V_210 -> V_208 ) ;
if ( V_210 -> V_211 < V_212 )
F_88 ( V_210 -> V_211 , V_213 ) ;
else
F_88 ( V_210 -> V_211 - V_212 , V_213 ) ;
F_16 ( V_210 ) ;
}
static T_1 F_89 ( struct V_143 * V_209 , struct V_214 * V_215 ,
char * V_194 )
{
struct V_207 * V_210 ;
V_210 = F_83 ( V_209 , struct V_207 , V_209 ) ;
return sprintf ( V_194 , L_1 , V_210 -> V_144 -> V_216 ) ;
}
static int F_90 ( void )
{
int V_217 ;
if ( ! V_218 ) {
V_217 = F_91 ( & V_218 , 0 , V_212 ,
L_2 ) ;
if ( V_217 ) {
F_92 ( V_219 L_3 ) ;
return V_217 ;
}
}
V_217 = F_93 ( V_220 , V_212 ) ;
if ( V_217 >= V_212 )
return - 1 ;
return V_217 ;
}
static void F_94 ( struct V_221 * V_143 )
{
int V_211 ;
T_9 V_222 ;
struct V_207 * V_210 ;
if ( ! V_143 -> V_223 ||
F_95 ( V_143 -> V_224 ) != V_225 )
return;
V_210 = F_18 ( sizeof *V_210 , V_25 ) ;
if ( ! V_210 )
return;
V_210 -> V_144 = V_143 ;
V_211 = F_93 ( V_213 , V_212 ) ;
if ( V_211 >= V_212 ) {
V_211 = F_90 () ;
if ( V_211 < 0 )
goto V_226;
V_210 -> V_211 = V_211 + V_212 ;
V_222 = V_211 + V_218 ;
F_96 ( V_211 , V_220 ) ;
} else {
V_210 -> V_211 = V_211 ;
V_222 = V_211 + V_227 ;
F_96 ( V_211 , V_213 ) ;
}
F_97 ( & V_210 -> V_208 , & V_228 ) ;
V_210 -> V_208 . V_229 = V_230 ;
F_98 ( & V_210 -> V_208 . V_231 , L_4 , V_210 -> V_211 ) ;
if ( F_99 ( & V_210 -> V_208 , V_222 , 1 ) )
goto V_226;
V_210 -> V_209 . V_232 = & V_233 ;
V_210 -> V_209 . V_234 = V_143 -> V_235 ;
V_210 -> V_209 . V_236 = V_210 -> V_208 . V_209 ;
V_210 -> V_209 . V_237 = F_86 ;
F_100 ( & V_210 -> V_209 , L_4 , V_210 -> V_211 ) ;
if ( F_101 ( & V_210 -> V_209 ) )
goto V_238;
if ( F_102 ( & V_210 -> V_209 , & V_239 ) )
goto V_240;
F_103 ( V_143 , & V_241 , V_210 ) ;
return;
V_240:
F_104 ( & V_210 -> V_209 ) ;
V_238:
F_87 ( & V_210 -> V_208 ) ;
if ( V_210 -> V_211 < V_212 )
F_88 ( V_211 , V_213 ) ;
else
F_88 ( V_211 , V_220 ) ;
V_226:
F_16 ( V_210 ) ;
return;
}
static void F_105 ( struct V_221 * V_143 )
{
struct V_207 * V_210 = F_106 ( V_143 , & V_241 ) ;
if ( ! V_210 )
return;
F_104 ( & V_210 -> V_209 ) ;
}
static int T_10 F_107 ( void )
{
int V_217 ;
V_217 = F_108 ( V_227 , V_212 ,
L_2 ) ;
if ( V_217 ) {
F_92 ( V_219 L_5 ) ;
goto V_242;
}
V_217 = F_109 ( & V_233 , & V_243 . V_215 ) ;
if ( V_217 ) {
F_92 ( V_219 L_6 ) ;
goto V_244;
}
V_217 = F_110 ( & V_241 ) ;
if ( V_217 ) {
F_92 ( V_219 L_7 ) ;
goto V_245;
}
return 0 ;
V_245:
F_111 ( & V_233 , & V_243 . V_215 ) ;
V_244:
F_112 ( V_227 , V_212 ) ;
V_242:
return V_217 ;
}
static void T_11 F_113 ( void )
{
F_114 ( & V_241 ) ;
F_111 ( & V_233 , & V_243 . V_215 ) ;
F_112 ( V_227 , V_212 ) ;
if ( V_218 )
F_112 ( V_218 , V_212 ) ;
F_115 ( & V_7 ) ;
}

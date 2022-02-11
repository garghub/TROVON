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
F_33 ( V_132 ) ;
if ( V_129 < sizeof( struct V_133 ) )
return - V_134 ;
if ( F_34 ( & V_131 , V_127 , sizeof( V_131 ) ) )
return - V_135 ;
F_2 ( & V_3 -> V_17 ) ;
while ( F_13 ( & V_3 -> V_19 ) ) {
F_6 ( & V_3 -> V_17 ) ;
if ( V_3 -> V_136 -> V_137 & V_138 )
return - V_26 ;
if ( F_35 ( V_3 -> V_126 ,
! F_13 ( & V_3 -> V_19 ) ) )
return - V_139 ;
F_2 ( & V_3 -> V_17 ) ;
}
V_16 = F_14 ( V_3 -> V_19 . V_20 , struct V_15 , V_18 ) ;
if ( F_10 ( V_16 -> V_22 . V_12 ) ) {
V_5 = F_17 ( V_3 ) ;
if ( ! V_5 ) {
V_24 = - V_122 ;
goto V_140;
}
V_5 -> V_23 = V_16 -> V_23 ;
V_5 -> V_23 -> V_124 = V_5 ;
V_16 -> V_22 . V_4 = V_5 -> V_4 ;
}
if ( F_36 ( ( void T_2 * ) ( unsigned long ) V_131 . V_141 ,
& V_16 -> V_22 , sizeof( V_16 -> V_22 ) ) ) {
V_24 = - V_135 ;
goto V_140;
}
if ( V_16 -> V_116 ) {
if ( V_131 . V_67 < V_16 -> V_67 ) {
V_24 = - V_122 ;
goto V_140;
}
if ( F_36 ( ( void T_2 * ) ( unsigned long ) V_131 . V_116 ,
V_16 -> V_116 , V_16 -> V_67 ) ) {
V_24 = - V_135 ;
goto V_140;
}
}
if ( V_16 -> V_62 ) {
if ( V_131 . V_94 < V_16 -> V_94 ) {
V_24 = - V_122 ;
goto V_140;
}
if ( F_36 ( ( void T_2 * ) ( unsigned long ) V_131 . V_62 ,
V_16 -> V_62 , V_16 -> V_94 ) ) {
V_24 = - V_135 ;
goto V_140;
}
}
F_12 ( & V_16 -> V_18 ) ;
F_12 ( & V_16 -> V_21 ) ;
V_16 -> V_5 -> V_142 ++ ;
F_16 ( V_16 -> V_116 ) ;
F_16 ( V_16 -> V_62 ) ;
F_16 ( V_16 ) ;
V_140:
F_6 ( & V_3 -> V_17 ) ;
return V_24 ;
}
static T_1 F_37 ( struct V_2 * V_3 ,
const char T_2 * V_127 ,
int V_128 , int V_129 )
{
struct F_37 V_131 ;
struct V_143 V_22 ;
struct V_1 * V_5 ;
int V_24 ;
if ( V_129 < sizeof( V_22 ) )
return - V_134 ;
if ( F_34 ( & V_131 , V_127 , sizeof( V_131 ) ) )
return - V_135 ;
F_2 ( & V_3 -> V_17 ) ;
V_5 = F_17 ( V_3 ) ;
F_6 ( & V_3 -> V_17 ) ;
if ( ! V_5 )
return - V_122 ;
V_5 -> V_125 = V_131 . V_125 ;
V_5 -> V_23 = F_38 ( V_3 -> V_144 -> V_145 ,
F_31 , V_5 ) ;
if ( F_39 ( V_5 -> V_23 ) ) {
V_24 = F_40 ( V_5 -> V_23 ) ;
goto V_118;
}
V_22 . V_4 = V_5 -> V_4 ;
if ( F_36 ( ( void T_2 * ) ( unsigned long ) V_131 . V_141 ,
& V_22 , sizeof( V_22 ) ) ) {
V_24 = - V_135 ;
goto V_120;
}
return 0 ;
V_120:
F_15 ( V_5 -> V_23 ) ;
V_118:
F_2 ( & V_6 ) ;
F_41 ( & V_7 , V_5 -> V_4 ) ;
F_6 ( & V_6 ) ;
F_16 ( V_5 ) ;
return V_24 ;
}
static T_1 F_42 ( struct V_2 * V_3 ,
const char T_2 * V_127 ,
int V_128 , int V_129 )
{
struct F_42 V_131 ;
struct V_146 V_22 ;
struct V_1 * V_5 ;
int V_24 = 0 ;
if ( V_129 < sizeof( V_22 ) )
return - V_134 ;
if ( F_34 ( & V_131 , V_127 , sizeof( V_131 ) ) )
return - V_135 ;
F_2 ( & V_6 ) ;
V_5 = F_3 ( & V_7 , V_131 . V_4 ) ;
if ( ! V_5 )
V_5 = F_4 ( - V_8 ) ;
else if ( V_5 -> V_3 != V_3 )
V_5 = F_4 ( - V_9 ) ;
else
F_41 ( & V_7 , V_5 -> V_4 ) ;
F_6 ( & V_6 ) ;
if ( F_39 ( V_5 ) )
return F_40 ( V_5 ) ;
F_7 ( V_5 ) ;
F_43 ( & V_5 -> V_11 ) ;
F_15 ( V_5 -> V_23 ) ;
F_11 ( V_5 ) ;
V_22 . V_142 = V_5 -> V_142 ;
if ( F_36 ( ( void T_2 * ) ( unsigned long ) V_131 . V_141 ,
& V_22 , sizeof( V_22 ) ) )
V_24 = - V_135 ;
F_16 ( V_5 ) ;
return V_24 ;
}
static T_1 F_44 ( struct V_2 * V_3 ,
const char T_2 * V_127 ,
int V_128 , int V_129 )
{
struct V_147 V_22 ;
struct F_44 V_131 ;
struct V_1 * V_5 ;
int V_24 = 0 ;
if ( V_129 < sizeof( V_22 ) )
return - V_134 ;
if ( F_34 ( & V_131 , V_127 , sizeof( V_131 ) ) )
return - V_135 ;
V_5 = F_1 ( V_3 , V_131 . V_4 ) ;
if ( F_39 ( V_5 ) )
return F_40 ( V_5 ) ;
V_22 . V_148 = V_5 -> V_23 -> V_148 ;
V_22 . V_149 = V_5 -> V_23 -> V_149 ;
V_22 . V_150 = V_5 -> V_23 -> V_150 ;
V_22 . V_151 = V_5 -> V_23 -> V_151 ;
if ( F_36 ( ( void T_2 * ) ( unsigned long ) V_131 . V_141 ,
& V_22 , sizeof( V_22 ) ) )
V_24 = - V_135 ;
F_7 ( V_5 ) ;
return V_24 ;
}
static T_1 F_45 ( struct V_2 * V_3 ,
const char T_2 * V_127 ,
int V_128 , int V_129 )
{
struct V_152 V_22 ;
struct F_45 V_131 ;
struct V_1 * V_5 ;
struct V_153 V_154 ;
int V_24 = 0 ;
if ( V_129 < sizeof( V_22 ) )
return - V_134 ;
if ( F_34 ( & V_131 , V_127 , sizeof( V_131 ) ) )
return - V_135 ;
V_5 = F_1 ( V_3 , V_131 . V_4 ) ;
if ( F_39 ( V_5 ) )
return F_40 ( V_5 ) ;
V_22 . V_155 = 0 ;
memset ( & V_154 , 0 , sizeof V_154 ) ;
V_154 . V_156 = V_131 . V_156 ;
V_24 = F_46 ( V_5 -> V_23 , & V_154 , & V_22 . V_155 ) ;
if ( V_24 )
goto V_157;
F_47 ( & V_22 , & V_154 ) ;
if ( F_36 ( ( void T_2 * ) ( unsigned long ) V_131 . V_141 ,
& V_22 , sizeof( V_22 ) ) )
V_24 = - V_135 ;
V_157:
F_7 ( V_5 ) ;
return V_24 ;
}
static int F_48 ( T_3 V_148 , T_3 V_149 )
{
V_148 &= V_149 ;
if ( ( ( V_148 & V_158 ) == V_159 ) ||
( ( V_148 & V_160 ) == V_161 ) )
return - V_9 ;
return 0 ;
}
static T_1 F_49 ( struct V_2 * V_3 ,
const char T_2 * V_127 ,
int V_128 , int V_129 )
{
struct F_49 V_131 ;
struct V_1 * V_5 ;
int V_24 ;
if ( F_34 ( & V_131 , V_127 , sizeof( V_131 ) ) )
return - V_135 ;
V_5 = F_1 ( V_3 , V_131 . V_4 ) ;
if ( F_39 ( V_5 ) )
return F_40 ( V_5 ) ;
V_24 = F_48 ( V_131 . V_148 , V_131 . V_149 ) ;
if ( V_24 )
goto V_157;
V_24 = F_50 ( V_5 -> V_23 , V_131 . V_148 , V_131 . V_149 ,
NULL ) ;
V_157:
F_7 ( V_5 ) ;
return V_24 ;
}
static T_1 F_51 ( struct V_2 * V_3 ,
const char T_2 * V_127 ,
int V_128 , int V_129 )
{
struct F_51 V_131 ;
struct V_1 * V_5 ;
int V_24 ;
if ( F_34 ( & V_131 , V_127 , sizeof( V_131 ) ) )
return - V_135 ;
V_5 = F_1 ( V_3 , V_131 . V_4 ) ;
if ( F_39 ( V_5 ) )
return F_40 ( V_5 ) ;
V_24 = F_52 ( V_5 -> V_23 , (enum V_162 ) V_131 . V_12 ) ;
F_7 ( V_5 ) ;
return V_24 ;
}
static int F_53 ( const void * * V_163 , T_4 V_164 , T_5 V_165 )
{
void * V_116 ;
* V_163 = NULL ;
if ( ! V_165 )
return 0 ;
V_116 = F_54 ( ( void T_2 * ) ( unsigned long ) V_164 , V_165 ) ;
if ( F_39 ( V_116 ) )
return F_40 ( V_116 ) ;
* V_163 = V_116 ;
return 0 ;
}
static int F_55 ( struct V_166 * * V_99 , T_4 V_164 )
{
struct V_167 V_168 ;
struct V_166 * V_169 ;
* V_99 = NULL ;
if ( ! V_164 )
return 0 ;
V_169 = F_56 ( sizeof( * V_169 ) , V_25 ) ;
if ( ! V_169 )
return - V_122 ;
if ( F_34 ( & V_168 , ( void T_2 * ) ( unsigned long ) V_164 ,
sizeof( V_168 ) ) ) {
F_16 ( V_169 ) ;
return - V_135 ;
}
F_57 ( V_169 , & V_168 ) ;
* V_99 = V_169 ;
return 0 ;
}
static T_1 F_58 ( struct V_2 * V_3 ,
const char T_2 * V_127 ,
int V_128 , int V_129 )
{
struct V_170 V_65 ;
struct V_1 * V_5 ;
struct V_171 V_131 ;
int V_24 ;
V_65 . V_117 = NULL ;
V_65 . V_46 = NULL ;
V_65 . V_47 = NULL ;
if ( F_34 ( & V_131 , V_127 , sizeof( V_131 ) ) )
return - V_135 ;
V_24 = F_53 ( & V_65 . V_117 , V_131 . V_116 , V_131 . V_165 ) ;
if ( V_24 )
goto V_140;
V_24 = F_55 ( & V_65 . V_46 , V_131 . V_46 ) ;
if ( V_24 )
goto V_140;
V_24 = F_55 ( & V_65 . V_47 , V_131 . V_47 ) ;
if ( V_24 )
goto V_140;
V_65 . V_172 = V_131 . V_165 ;
V_65 . V_148 = V_131 . V_173 ;
V_65 . V_174 = V_131 . V_58 ;
V_65 . V_35 = V_131 . V_35 ;
V_65 . V_36 = V_131 . V_175 ;
V_65 . V_176 = V_131 . V_176 ;
V_65 . V_37 = V_131 . V_37 ;
V_65 . V_38 = V_131 . V_38 ;
V_65 . V_41 = V_131 . V_41 ;
V_65 . V_40 = V_131 . V_40 ;
V_65 . V_39 = V_131 . V_39 ;
V_65 . V_42 = V_131 . V_42 ;
V_65 . V_43 = V_131 . V_43 ;
V_65 . V_177 = V_131 . V_177 ;
V_65 . V_44 = V_131 . V_44 ;
V_5 = F_1 ( V_3 , V_131 . V_4 ) ;
if ( ! F_39 ( V_5 ) ) {
V_24 = F_59 ( V_5 -> V_23 , & V_65 ) ;
F_7 ( V_5 ) ;
} else
V_24 = F_40 ( V_5 ) ;
V_140:
F_16 ( V_65 . V_117 ) ;
F_16 ( V_65 . V_46 ) ;
F_16 ( V_65 . V_47 ) ;
return V_24 ;
}
static T_1 F_60 ( struct V_2 * V_3 ,
const char T_2 * V_127 ,
int V_128 , int V_129 )
{
struct V_178 V_65 ;
struct V_1 * V_5 ;
struct V_179 V_131 ;
int V_24 ;
V_65 . V_117 = NULL ;
if ( F_34 ( & V_131 , V_127 , sizeof( V_131 ) ) )
return - V_135 ;
V_24 = F_53 ( & V_65 . V_117 , V_131 . V_116 , V_131 . V_165 ) ;
if ( V_24 )
return V_24 ;
V_65 . V_174 = V_131 . V_58 ;
V_65 . V_36 = V_131 . V_175 ;
V_65 . V_172 = V_131 . V_165 ;
V_65 . V_37 = V_131 . V_37 ;
V_65 . V_38 = V_131 . V_38 ;
V_65 . V_53 = V_131 . V_53 ;
V_65 . V_40 = V_131 . V_40 ;
V_65 . V_43 = V_131 . V_43 ;
V_65 . V_44 = V_131 . V_44 ;
V_5 = F_1 ( V_3 , V_131 . V_4 ) ;
if ( ! F_39 ( V_5 ) ) {
V_5 -> V_125 = V_131 . V_125 ;
V_24 = F_61 ( V_5 -> V_23 , & V_65 ) ;
F_7 ( V_5 ) ;
} else
V_24 = F_40 ( V_5 ) ;
F_16 ( V_65 . V_117 ) ;
return V_24 ;
}
static T_1 F_62 ( struct V_2 * V_3 ,
const char T_2 * V_127 , int V_128 ,
int (* F_63)( struct V_123 * V_23 ,
const void * V_117 ,
T_6 V_172 ) )
{
struct V_180 V_131 ;
struct V_1 * V_5 ;
const void * V_117 = NULL ;
int V_24 ;
if ( F_34 ( & V_131 , V_127 , sizeof( V_131 ) ) )
return - V_135 ;
V_24 = F_53 ( & V_117 , V_131 . V_116 , V_131 . V_165 ) ;
if ( V_24 )
return V_24 ;
V_5 = F_1 ( V_3 , V_131 . V_4 ) ;
if ( ! F_39 ( V_5 ) ) {
V_24 = F_63 ( V_5 -> V_23 , V_117 , V_131 . V_165 ) ;
F_7 ( V_5 ) ;
} else
V_24 = F_40 ( V_5 ) ;
F_16 ( V_117 ) ;
return V_24 ;
}
static T_1 F_64 ( struct V_2 * V_3 ,
const char T_2 * V_127 ,
int V_128 , int V_129 )
{
return F_62 ( V_3 , V_127 , V_128 , V_181 ) ;
}
static T_1 F_65 ( struct V_2 * V_3 ,
const char T_2 * V_127 ,
int V_128 , int V_129 )
{
return F_62 ( V_3 , V_127 , V_128 , V_182 ) ;
}
static T_1 F_66 ( struct V_2 * V_3 ,
const char T_2 * V_127 ,
int V_128 , int V_129 )
{
return F_62 ( V_3 , V_127 , V_128 , V_183 ) ;
}
static T_1 F_67 ( struct V_2 * V_3 ,
const char T_2 * V_127 , int V_128 ,
int (* F_63)( struct V_123 * V_23 ,
int V_56 ,
const void * V_62 ,
T_6 V_94 ,
const void * V_116 ,
T_6 V_67 ) )
{
struct V_1 * V_5 ;
struct V_184 V_131 ;
const void * V_116 = NULL ;
const void * V_62 = NULL ;
int V_24 ;
if ( F_34 ( & V_131 , V_127 , sizeof( V_131 ) ) )
return - V_135 ;
V_24 = F_53 ( & V_116 , V_131 . V_116 , V_131 . V_67 ) ;
if ( V_24 )
goto V_140;
V_24 = F_53 ( & V_62 , V_131 . V_62 , V_131 . V_94 ) ;
if ( V_24 )
goto V_140;
V_5 = F_1 ( V_3 , V_131 . V_4 ) ;
if ( ! F_39 ( V_5 ) ) {
V_24 = F_63 ( V_5 -> V_23 , V_131 . V_56 , V_62 , V_131 . V_94 ,
V_116 , V_131 . V_67 ) ;
F_7 ( V_5 ) ;
} else
V_24 = F_40 ( V_5 ) ;
V_140:
F_16 ( V_116 ) ;
F_16 ( V_62 ) ;
return V_24 ;
}
static T_1 F_68 ( struct V_2 * V_3 ,
const char T_2 * V_127 ,
int V_128 , int V_129 )
{
return F_67 ( V_3 , V_127 , V_128 , ( void * ) V_185 ) ;
}
static T_1 F_69 ( struct V_2 * V_3 ,
const char T_2 * V_127 ,
int V_128 , int V_129 )
{
return F_67 ( V_3 , V_127 , V_128 , ( void * ) V_186 ) ;
}
static T_1 F_70 ( struct V_2 * V_3 ,
const char T_2 * V_127 ,
int V_128 , int V_129 )
{
struct V_1 * V_5 ;
struct V_187 V_131 ;
const void * V_116 = NULL ;
int V_24 ;
if ( F_34 ( & V_131 , V_127 , sizeof( V_131 ) ) )
return - V_135 ;
V_24 = F_53 ( & V_116 , V_131 . V_116 , V_131 . V_165 ) ;
if ( V_24 )
return V_24 ;
V_5 = F_1 ( V_3 , V_131 . V_4 ) ;
if ( ! F_39 ( V_5 ) ) {
V_24 = F_71 ( V_5 -> V_23 , V_131 . V_85 , V_116 , V_131 . V_165 ) ;
F_7 ( V_5 ) ;
} else
V_24 = F_40 ( V_5 ) ;
F_16 ( V_116 ) ;
return V_24 ;
}
static T_1 F_72 ( struct V_2 * V_3 ,
const char T_2 * V_127 ,
int V_128 , int V_129 )
{
struct V_1 * V_5 ;
struct V_166 * V_99 = NULL ;
struct V_188 V_131 ;
const void * V_116 = NULL ;
int V_24 ;
if ( F_34 ( & V_131 , V_127 , sizeof( V_131 ) ) )
return - V_135 ;
V_24 = F_53 ( & V_116 , V_131 . V_116 , V_131 . V_165 ) ;
if ( V_24 )
goto V_140;
V_24 = F_55 ( & V_99 , V_131 . V_99 ) ;
if ( V_24 )
goto V_140;
V_5 = F_1 ( V_3 , V_131 . V_4 ) ;
if ( ! F_39 ( V_5 ) ) {
V_24 = F_73 ( V_5 -> V_23 , V_99 , V_116 , V_131 . V_165 ) ;
F_7 ( V_5 ) ;
} else
V_24 = F_40 ( V_5 ) ;
V_140:
F_16 ( V_116 ) ;
F_16 ( V_99 ) ;
return V_24 ;
}
static T_1 F_74 ( struct V_2 * V_3 ,
const char T_2 * V_127 ,
int V_128 , int V_129 )
{
struct V_189 V_65 ;
struct V_1 * V_5 ;
struct V_190 V_131 ;
int V_24 ;
V_65 . V_117 = NULL ;
V_65 . V_99 = NULL ;
if ( F_34 ( & V_131 , V_127 , sizeof( V_131 ) ) )
return - V_135 ;
V_24 = F_53 ( & V_65 . V_117 , V_131 . V_116 , V_131 . V_165 ) ;
if ( V_24 )
goto V_140;
V_24 = F_55 ( & V_65 . V_99 , V_131 . V_99 ) ;
if ( V_24 )
goto V_140;
V_65 . V_172 = V_131 . V_165 ;
V_65 . V_148 = V_131 . V_173 ;
V_65 . V_191 = V_131 . V_85 ;
V_65 . V_177 = V_131 . V_177 ;
V_5 = F_1 ( V_3 , V_131 . V_4 ) ;
if ( ! F_39 ( V_5 ) ) {
V_24 = F_75 ( V_5 -> V_23 , & V_65 ) ;
F_7 ( V_5 ) ;
} else
V_24 = F_40 ( V_5 ) ;
V_140:
F_16 ( V_65 . V_117 ) ;
F_16 ( V_65 . V_99 ) ;
return V_24 ;
}
static T_1 F_76 ( struct V_2 * V_3 ,
const char T_2 * V_127 ,
int V_128 , int V_129 )
{
struct V_192 V_65 ;
struct V_193 V_131 ;
struct V_1 * V_5 ;
int V_24 ;
V_65 . V_62 = NULL ;
if ( F_34 ( & V_131 , V_127 , sizeof( V_131 ) ) )
return - V_135 ;
V_24 = F_53 ( & V_65 . V_117 ,
V_131 . V_116 , V_131 . V_67 ) ;
if ( V_24 )
goto V_140;
V_24 = F_53 ( & V_65 . V_62 , V_131 . V_62 , V_131 . V_94 ) ;
if ( V_24 )
goto V_140;
V_65 . V_174 = V_131 . V_58 ;
V_65 . V_57 = V_131 . V_57 ;
V_65 . V_56 = V_131 . V_56 ;
V_65 . V_194 = V_131 . V_94 ;
V_65 . V_172 = V_131 . V_67 ;
V_5 = F_1 ( V_3 , V_131 . V_4 ) ;
if ( ! F_39 ( V_5 ) ) {
V_24 = F_77 ( V_5 -> V_23 , & V_65 ) ;
F_7 ( V_5 ) ;
} else
V_24 = F_40 ( V_5 ) ;
V_140:
F_16 ( V_65 . V_117 ) ;
F_16 ( V_65 . V_62 ) ;
return V_24 ;
}
static T_1 F_78 ( struct V_3 * V_136 , const char T_2 * V_195 ,
T_7 V_165 , T_8 * V_196 )
{
struct V_2 * V_3 = V_136 -> V_117 ;
struct V_197 V_198 ;
T_1 V_24 ;
if ( V_165 < sizeof( V_198 ) )
return - V_9 ;
if ( F_34 ( & V_198 , V_195 , sizeof( V_198 ) ) )
return - V_135 ;
if ( V_198 . V_131 >= F_79 ( V_199 ) )
return - V_9 ;
if ( V_198 . V_200 + sizeof( V_198 ) > V_165 )
return - V_9 ;
V_24 = V_199 [ V_198 . V_131 ] ( V_3 , V_195 + sizeof( V_198 ) ,
V_198 . V_200 , V_198 . V_157 ) ;
if ( ! V_24 )
V_24 = V_165 ;
return V_24 ;
}
static unsigned int F_80 ( struct V_3 * V_136 ,
struct V_201 * V_132 )
{
struct V_2 * V_3 = V_136 -> V_117 ;
unsigned int V_202 = 0 ;
V_126 ( V_136 , & V_3 -> V_126 , V_132 ) ;
if ( ! F_13 ( & V_3 -> V_19 ) )
V_202 = V_203 | V_204 ;
return V_202 ;
}
static int F_81 ( struct V_205 * V_205 , struct V_3 * V_136 )
{
struct V_2 * V_3 ;
V_3 = F_56 ( sizeof( * V_3 ) , V_25 ) ;
if ( ! V_3 )
return - V_122 ;
F_21 ( & V_3 -> V_19 ) ;
F_21 ( & V_3 -> V_27 ) ;
F_82 ( & V_3 -> V_126 ) ;
F_83 ( & V_3 -> V_17 ) ;
V_136 -> V_117 = V_3 ;
V_3 -> V_136 = V_136 ;
V_3 -> V_144 = F_84 ( V_205 -> V_206 , struct V_207 , V_208 ) ;
return F_85 ( V_205 , V_136 ) ;
}
static int F_86 ( struct V_205 * V_205 , struct V_3 * V_136 )
{
struct V_2 * V_3 = V_136 -> V_117 ;
struct V_1 * V_5 ;
F_2 ( & V_3 -> V_17 ) ;
while ( ! F_13 ( & V_3 -> V_27 ) ) {
V_5 = F_14 ( V_3 -> V_27 . V_20 ,
struct V_1 , V_18 ) ;
F_6 ( & V_3 -> V_17 ) ;
F_2 ( & V_6 ) ;
F_41 ( & V_7 , V_5 -> V_4 ) ;
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
static void F_87 ( struct V_144 * V_209 )
{
struct V_207 * V_210 ;
V_210 = F_84 ( V_209 , struct V_207 , V_209 ) ;
F_88 ( & V_210 -> V_208 ) ;
if ( V_210 -> V_211 < V_212 )
F_89 ( V_210 -> V_211 , V_213 ) ;
else
F_89 ( V_210 -> V_211 - V_212 , V_213 ) ;
F_16 ( V_210 ) ;
}
static T_1 F_90 ( struct V_144 * V_209 , struct V_214 * V_215 ,
char * V_195 )
{
struct V_207 * V_210 ;
V_210 = F_84 ( V_209 , struct V_207 , V_209 ) ;
return sprintf ( V_195 , L_1 , V_210 -> V_145 -> V_216 ) ;
}
static int F_91 ( void )
{
int V_217 ;
if ( ! V_218 ) {
V_217 = F_92 ( & V_218 , 0 , V_212 ,
L_2 ) ;
if ( V_217 ) {
F_93 ( V_219 L_3 ) ;
return V_217 ;
}
}
V_217 = F_94 ( V_220 , V_212 ) ;
if ( V_217 >= V_212 )
return - 1 ;
return V_217 ;
}
static void F_95 ( struct V_221 * V_144 )
{
int V_211 ;
T_9 V_222 ;
struct V_207 * V_210 ;
if ( ! V_144 -> V_223 ||
F_96 ( V_144 -> V_224 ) != V_225 )
return;
V_210 = F_18 ( sizeof *V_210 , V_25 ) ;
if ( ! V_210 )
return;
V_210 -> V_145 = V_144 ;
V_211 = F_94 ( V_213 , V_212 ) ;
if ( V_211 >= V_212 ) {
V_211 = F_91 () ;
if ( V_211 < 0 )
goto V_226;
V_210 -> V_211 = V_211 + V_212 ;
V_222 = V_211 + V_218 ;
F_97 ( V_211 , V_220 ) ;
} else {
V_210 -> V_211 = V_211 ;
V_222 = V_211 + V_227 ;
F_97 ( V_211 , V_213 ) ;
}
F_98 ( & V_210 -> V_208 , & V_228 ) ;
V_210 -> V_208 . V_229 = V_230 ;
F_99 ( & V_210 -> V_208 . V_231 , L_4 , V_210 -> V_211 ) ;
if ( F_100 ( & V_210 -> V_208 , V_222 , 1 ) )
goto V_226;
V_210 -> V_209 . V_232 = & V_233 ;
V_210 -> V_209 . V_234 = V_144 -> V_235 ;
V_210 -> V_209 . V_236 = V_210 -> V_208 . V_209 ;
V_210 -> V_209 . V_237 = F_87 ;
F_101 ( & V_210 -> V_209 , L_4 , V_210 -> V_211 ) ;
if ( F_102 ( & V_210 -> V_209 ) )
goto V_238;
if ( F_103 ( & V_210 -> V_209 , & V_239 ) )
goto V_240;
F_104 ( V_144 , & V_241 , V_210 ) ;
return;
V_240:
F_105 ( & V_210 -> V_209 ) ;
V_238:
F_88 ( & V_210 -> V_208 ) ;
if ( V_210 -> V_211 < V_212 )
F_89 ( V_211 , V_213 ) ;
else
F_89 ( V_211 , V_220 ) ;
V_226:
F_16 ( V_210 ) ;
return;
}
static void F_106 ( struct V_221 * V_144 )
{
struct V_207 * V_210 = F_107 ( V_144 , & V_241 ) ;
if ( ! V_210 )
return;
F_105 ( & V_210 -> V_209 ) ;
}
static int T_10 F_108 ( void )
{
int V_217 ;
V_217 = F_109 ( V_227 , V_212 ,
L_2 ) ;
if ( V_217 ) {
F_93 ( V_219 L_5 ) ;
goto V_242;
}
V_217 = F_110 ( & V_233 , & V_243 . V_215 ) ;
if ( V_217 ) {
F_93 ( V_219 L_6 ) ;
goto V_244;
}
V_217 = F_111 ( & V_241 ) ;
if ( V_217 ) {
F_93 ( V_219 L_7 ) ;
goto V_245;
}
return 0 ;
V_245:
F_112 ( & V_233 , & V_243 . V_215 ) ;
V_244:
F_113 ( V_227 , V_212 ) ;
V_242:
return V_217 ;
}
static void T_11 F_114 ( void )
{
F_115 ( & V_241 ) ;
F_112 ( & V_233 , & V_243 . V_215 ) ;
F_113 ( V_227 , V_212 ) ;
if ( V_218 )
F_113 ( V_218 , V_212 ) ;
F_116 ( & V_7 ) ;
}

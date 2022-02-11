static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
return false ;
default:
return true ;
}
}
static int F_2 ( struct V_6 * V_7 ,
enum V_8 V_9 )
{
int V_10 ;
int V_11 ;
V_10 = F_3 ( V_7 -> V_12 [ V_9 ] , & V_11 ) ;
if ( V_10 < 0 )
return V_10 ;
return V_11 ;
}
static int F_4 ( struct V_6 * V_7 ,
enum V_8 V_9 , T_1 V_11 )
{
return F_5 ( V_7 -> V_12 [ V_9 ] , V_11 ) ;
}
static T_1 F_6 ( T_2 V_13 , const T_2 * V_14 , T_1 V_15 )
{
T_1 V_16 ;
for ( V_16 = 1 ; V_16 < V_15 ; V_16 ++ )
if ( V_13 < V_14 [ V_16 ] )
break;
return V_16 - 1 ;
}
static int F_7 ( struct V_6 * V_7 ,
union V_17 * V_11 )
{
int V_10 ;
V_10 = F_2 ( V_7 , V_18 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_10 >= V_19 )
return - V_20 ;
V_11 -> V_21 = V_22 [ V_10 ] ;
return 0 ;
}
static int F_8 ( struct V_6 * V_7 ,
const union V_17 * V_11 )
{
if ( V_7 -> V_23 )
F_9 ( & V_7 -> V_24 ) ;
return F_4 ( V_7 , V_18 ,
F_6 ( V_11 -> V_21 ,
V_22 ,
V_19 ) ) ;
}
static int F_10 ( struct V_25 * V_26 ,
enum V_27 V_28 ,
union V_17 * V_11 )
{
struct V_6 * V_7 = F_11 ( V_26 ) ;
struct V_29 V_30 ;
F_12 ( & V_7 -> V_31 ) ;
V_30 = V_7 -> V_30 ;
F_13 ( & V_7 -> V_31 ) ;
switch ( V_28 ) {
case V_32 :
if ( ! V_30 . V_33 )
V_11 -> V_21 = V_34 ;
else if ( V_30 . V_35 == V_36 )
V_11 -> V_21 = V_37 ;
else if ( V_30 . V_35 == V_38 )
V_11 -> V_21 = V_39 ;
else if ( V_30 . V_35 == V_40 )
V_11 -> V_21 = V_41 ;
else
V_11 -> V_21 = V_42 ;
break;
case V_43 :
V_11 -> V_44 = V_45 ;
break;
case V_46 :
V_11 -> V_44 = V_47 [ V_7 -> V_48 ] ;
break;
case V_49 :
V_11 -> V_21 = V_30 . V_33 ;
break;
case V_50 :
switch ( V_30 . V_51 ) {
case V_52 :
V_11 -> V_21 = V_53 ;
break;
case V_54 :
case V_55 :
V_11 -> V_21 = V_56 ;
break;
case V_57 :
case V_58 :
V_11 -> V_21 = V_59 ;
break;
case V_60 :
V_11 -> V_21 = V_61 ;
break;
default:
V_11 -> V_21 = V_62 ;
break;
}
break;
case V_63 :
V_11 -> V_21 = V_64 [ V_7 -> V_65 . V_66 ] ;
break;
case V_67 :
V_11 -> V_21 = V_64 [ V_68 - 1 ] ;
break;
case V_69 :
V_11 -> V_21 = V_70 [ V_7 -> V_65 . V_71 ] ;
break;
case V_72 :
V_11 -> V_21 = V_70 [ V_73 - 1 ] ;
break;
case V_74 :
V_11 -> V_21 = V_75 [ V_7 -> V_65 . V_76 ] ;
break;
case V_77 :
return F_7 ( V_7 , V_11 ) ;
default:
return - V_78 ;
}
return 0 ;
}
static int F_14 ( struct V_25 * V_26 ,
enum V_27 V_79 ,
const union V_17 * V_11 )
{
struct V_6 * V_7 = F_11 ( V_26 ) ;
switch ( V_79 ) {
case V_77 :
return F_8 ( V_7 , V_11 ) ;
default:
return - V_78 ;
}
}
static int F_15 ( struct V_25 * V_26 ,
enum V_27 V_28 )
{
switch ( V_28 ) {
case V_77 :
return true ;
default:
return false ;
}
}
static int F_16 ( struct V_6 * V_7 ,
struct V_29 * V_30 )
{
int V_10 ;
V_10 = F_2 ( V_7 , V_80 ) ;
if ( V_10 < 0 )
return V_10 ;
V_30 -> V_35 = V_10 ;
V_10 = F_2 ( V_7 , V_81 ) ;
if ( V_10 < 0 )
return V_10 ;
V_30 -> V_51 = V_10 ;
if ( V_7 -> V_82 )
V_30 -> V_33 = ! F_17 ( V_7 -> V_82 ) ;
else
switch ( V_30 -> V_51 ) {
case V_54 :
case V_83 :
case V_84 :
V_30 -> V_33 = false ;
break;
default:
V_30 -> V_33 = true ;
}
return 0 ;
}
static bool F_18 ( struct V_6 * V_7 ,
struct V_29 * V_85 )
{
int V_10 ;
F_12 ( & V_7 -> V_31 ) ;
V_10 = ( V_7 -> V_30 . V_35 != V_85 -> V_35 ||
V_7 -> V_30 . V_51 != V_85 -> V_51 ||
V_7 -> V_30 . V_33 != V_85 -> V_33 ) ;
F_13 ( & V_7 -> V_31 ) ;
return V_10 ;
}
static int F_19 ( struct V_6 * V_7 )
{
int V_86 ;
int V_87 ;
int V_88 ;
int V_10 ;
const T_1 V_89 [] = {
[ V_90 ] = V_91 ,
[ V_92 ] = V_91 ,
[ V_93 ] = V_94 ,
[ V_95 ] = V_94
} ;
V_10 = F_2 ( V_7 , V_96 ) ;
if ( V_10 < 0 )
goto error;
V_86 = V_10 ;
V_10 = F_2 ( V_7 , V_18 ) ;
if ( V_10 < 0 )
goto error;
V_87 = V_10 ;
if ( V_86 == V_97 && V_87 == V_94 )
return 0 ;
V_10 = F_2 ( V_7 , V_98 ) ;
if ( V_10 < 0 )
goto error;
V_88 = V_10 ;
V_10 = F_4 ( V_7 , V_18 , V_89 [ V_88 ] ) ;
if ( V_10 < 0 )
goto error;
V_10 = F_4 ( V_7 , V_99 , V_100 ) ;
if ( V_10 < 0 )
goto error;
V_10 = F_4 ( V_7 , V_101 , 1 ) ;
if ( V_10 < 0 )
goto error;
F_20 ( V_7 -> V_2 , L_1 ,
V_88 , V_86 , V_89 [ V_88 ] ) ;
return 0 ;
error:
F_21 ( V_7 -> V_2 , L_2 , V_102 ) ;
return V_10 ;
}
static void F_22 ( struct V_103 * V_104 )
{
struct V_6 * V_7 = F_23 ( V_104 , struct V_6 ,
V_24 . V_104 ) ;
F_19 ( V_7 ) ;
}
static void F_24 ( struct V_6 * V_7 ,
struct V_29 * V_85 )
{
int V_10 ;
struct V_29 V_105 ;
F_12 ( & V_7 -> V_31 ) ;
V_105 = V_7 -> V_30 ;
F_13 ( & V_7 -> V_31 ) ;
if ( ! V_85 -> V_33 ) {
F_20 ( V_7 -> V_2 , L_3 ) ;
if ( V_7 -> V_23 ) {
F_9 ( & V_7 -> V_24 ) ;
V_10 = F_4 ( V_7 , V_106 , 1 ) ;
if ( V_10 < 0 )
goto error;
}
V_10 = F_4 ( V_7 , V_18 , V_7 -> V_65 . V_87 ) ;
if ( V_10 < 0 )
goto error;
} else if ( ! V_105 . V_33 ) {
F_20 ( V_7 -> V_2 , L_4 ) ;
if ( V_7 -> V_23 )
F_25 ( & V_7 -> V_24 ,
F_26 ( V_107 ) ) ;
} else if ( V_85 -> V_51 == V_108 ) {
F_27 ( V_7 -> V_2 , L_5 ) ;
} else if ( V_85 -> V_51 == V_60 ) {
F_21 ( V_7 -> V_2 , L_6 ) ;
}
return;
error:
F_21 ( V_7 -> V_2 , L_2 , V_102 ) ;
}
static T_3 F_28 ( int V_109 , void * V_110 )
{
int V_10 ;
struct V_6 * V_7 = V_110 ;
struct V_29 V_30 ;
V_10 = F_16 ( V_7 , & V_30 ) ;
if ( V_10 < 0 )
return V_111 ;
if ( ! F_18 ( V_7 , & V_30 ) )
return V_111 ;
F_20 ( V_7 -> V_2 , L_7 ,
V_30 . V_35 , V_30 . V_51 , V_30 . V_33 ) ;
F_24 ( V_7 , & V_30 ) ;
F_12 ( & V_7 -> V_31 ) ;
V_7 -> V_30 = V_30 ;
F_13 ( & V_7 -> V_31 ) ;
F_29 ( V_7 -> V_112 ) ;
return V_111 ;
}
static int F_30 ( struct V_6 * V_7 )
{
int V_10 ;
int V_113 ;
struct V_29 V_30 ;
const struct {
int V_114 ;
T_2 V_13 ;
} V_65 [] = {
{ V_115 , V_7 -> V_65 . V_66 } ,
{ V_116 , V_7 -> V_65 . V_71 } ,
{ V_117 , V_7 -> V_65 . V_76 } ,
{ V_118 , V_7 -> V_65 . V_119 } ,
{ V_120 , V_7 -> V_65 . V_121 } ,
} ;
V_10 = F_4 ( V_7 , V_122 , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
for ( V_113 = 0 ; V_113 < F_31 ( V_65 ) ; V_113 ++ ) {
V_10 = F_4 ( V_7 , V_65 [ V_113 ] . V_114 ,
V_65 [ V_113 ] . V_13 ) ;
if ( V_10 < 0 )
return V_10 ;
}
V_10 = F_16 ( V_7 , & V_30 ) ;
if ( V_10 < 0 )
return V_10 ;
F_12 ( & V_7 -> V_31 ) ;
V_7 -> V_30 = V_30 ;
F_13 ( & V_7 -> V_31 ) ;
if ( ! V_7 -> V_23 ) {
F_20 ( V_7 -> V_2 , L_8 ,
V_7 -> V_65 . V_87 ) ;
V_10 = F_4 ( V_7 , V_18 ,
V_7 -> V_65 . V_87 ) ;
if ( V_10 < 0 )
return V_10 ;
} else if ( ! V_30 . V_33 )
V_10 = F_4 ( V_7 , V_106 , 1 ) ;
else if ( V_30 . V_51 != V_108 )
V_10 = F_19 ( V_7 ) ;
return V_10 ;
}
static T_4 F_32 ( struct V_1 * V_2 ,
struct V_123 * V_124 ,
char * V_125 )
{
struct V_25 * V_26 = F_33 ( V_2 ) ;
struct V_6 * V_7 = F_11 ( V_26 ) ;
return F_34 ( V_125 , V_126 , L_9 ,
V_127 [ V_7 -> V_65 . V_119 ] ) ;
}
static T_4 F_35 ( struct V_1 * V_2 ,
struct V_123 * V_124 ,
char * V_125 )
{
struct V_25 * V_26 = F_33 ( V_2 ) ;
struct V_6 * V_7 = F_11 ( V_26 ) ;
return F_34 ( V_125 , V_126 , L_9 ,
V_128 [ V_7 -> V_65 . V_121 ] ) ;
}
static T_4 F_36 ( struct V_1 * V_2 ,
struct V_123 * V_124 ,
char * V_125 )
{
struct V_25 * V_26 = F_33 ( V_2 ) ;
struct V_6 * V_7 = F_11 ( V_26 ) ;
int V_10 ;
if ( strcmp ( V_124 -> V_124 . V_129 , L_10 ) == 0 )
V_10 = F_2 ( V_7 , V_130 ) ;
else if ( strcmp ( V_124 -> V_124 . V_129 , L_11 ) == 0 )
V_10 = F_2 ( V_7 , V_131 ) ;
else
return - V_78 ;
if ( V_10 < 0 )
return V_10 ;
return F_34 ( V_125 , V_126 , L_12 , V_10 ) ;
}
static T_4 F_37 ( struct V_1 * V_2 ,
struct V_123 * V_124 ,
const char * V_125 ,
T_5 V_132 )
{
struct V_25 * V_26 = F_33 ( V_2 ) ;
struct V_6 * V_7 = F_11 ( V_26 ) ;
long V_11 ;
int V_10 ;
if ( F_38 ( V_125 , 10 , & V_11 ) < 0 )
return - V_78 ;
if ( strcmp ( V_124 -> V_124 . V_129 , L_10 ) == 0 )
V_10 = F_4 ( V_7 , V_130 , ( bool ) V_11 ) ;
else if ( strcmp ( V_124 -> V_124 . V_129 , L_11 ) == 0 )
V_10 = F_4 ( V_7 , V_131 , ( bool ) V_11 ) ;
else
return - V_78 ;
if ( V_10 < 0 )
return V_10 ;
return V_132 ;
}
static int F_39 ( struct V_6 * V_7 )
{
struct V_133 V_134 = { . V_135 = V_7 , } ;
V_134 . V_136 = V_137 ;
V_134 . V_138 = F_31 ( V_137 ) ;
V_7 -> V_112 = F_40 ( V_7 -> V_2 ,
& V_139 ,
& V_134 ) ;
return F_41 ( V_7 -> V_112 ) ;
}
static void F_42 ( struct V_6 * V_7 )
{
V_7 -> V_82 = F_43 ( V_7 -> V_2 , V_140 , V_141 ) ;
if ( F_44 ( V_7 -> V_82 ) == - V_142 ) {
F_45 ( V_7 -> V_2 , L_13 ) ;
return;
} else if ( F_46 ( V_7 -> V_82 ) ) {
F_21 ( V_7 -> V_2 , L_14 ) ;
V_7 -> V_82 = NULL ;
return;
}
if ( V_7 -> V_82 )
F_20 ( V_7 -> V_2 , L_15 , F_47 ( V_7 -> V_82 ) ) ;
}
static int F_48 ( struct V_6 * V_7 )
{
int V_10 ;
T_2 V_143 ;
V_10 = F_49 ( V_7 -> V_2 , L_16 , & V_143 ) ;
if ( V_10 < 0 )
return V_10 ;
V_7 -> V_65 . V_66 = F_6 ( V_143 , V_64 ,
V_68 ) ;
V_10 = F_49 ( V_7 -> V_2 , L_17 ,
& V_143 ) ;
if ( V_10 < 0 )
return V_10 ;
V_7 -> V_65 . V_71 = F_6 ( V_143 , V_70 ,
V_73 ) ;
V_10 = F_49 ( V_7 -> V_2 , L_18 ,
& V_143 ) ;
if ( V_10 < 0 )
return V_10 ;
V_7 -> V_65 . V_76 = F_6 ( V_143 , V_75 ,
V_144 ) ;
V_10 = F_49 ( V_7 -> V_2 , L_19 ,
& V_143 ) ;
if ( V_10 < 0 ) {
V_7 -> V_23 = true ;
V_7 -> V_65 . V_87 = V_94 ;
} else
V_7 -> V_65 . V_87 =
F_6 ( V_143 ,
V_22 ,
V_19 ) ;
V_10 = F_49 ( V_7 -> V_2 , L_20 ,
& V_143 ) ;
if ( V_10 < 0 )
V_7 -> V_65 . V_119 = V_145 ;
else
V_7 -> V_65 . V_119 = F_6 ( V_143 ,
V_127 ,
V_146 ) ;
V_10 = F_49 ( V_7 -> V_2 , L_21 ,
& V_143 ) ;
if ( V_10 < 0 )
V_7 -> V_65 . V_121 = V_147 ;
else
V_7 -> V_65 . V_121 =
F_6 ( V_143 ,
V_128 ,
V_148 ) ;
return 0 ;
}
static int F_50 ( struct V_149 * V_150 ,
const struct V_151 * V_152 )
{
struct V_153 * V_154 = F_51 ( V_150 -> V_2 . V_155 ) ;
struct V_1 * V_2 = & V_150 -> V_2 ;
const struct V_156 * V_157 ;
struct V_6 * V_7 ;
int V_10 ;
int V_113 ;
if ( ! F_52 ( V_154 , V_158 ) ) {
F_21 ( V_2 , L_22 ) ;
return - V_159 ;
}
V_7 = F_53 ( V_2 , sizeof( * V_7 ) , V_160 ) ;
if ( ! V_7 )
return - V_161 ;
V_7 -> V_150 = V_150 ;
V_7 -> V_2 = V_2 ;
if ( F_54 ( V_2 ) ) {
V_157 = F_55 ( V_2 -> V_162 -> V_163 ,
& V_150 -> V_2 ) ;
if ( ! V_157 ) {
F_21 ( V_2 , L_23 ) ;
return - V_159 ;
}
V_7 -> V_48 = (enum V_164 ) V_157 -> V_165 ;
} else {
V_7 -> V_48 = (enum V_164 ) V_152 -> V_165 ;
}
F_56 ( & V_7 -> V_31 ) ;
V_7 -> V_166 = F_57 ( V_150 , & V_167 ) ;
if ( F_46 ( V_7 -> V_166 ) ) {
F_21 ( V_2 , L_24 ) ;
return F_44 ( V_7 -> V_166 ) ;
}
for ( V_113 = 0 ; V_113 < F_31 ( V_168 ) ; V_113 ++ ) {
const struct V_169 * V_170 = V_168 ;
V_7 -> V_12 [ V_113 ] = F_58 ( V_2 , V_7 -> V_166 ,
V_170 [ V_113 ] ) ;
if ( F_46 ( V_7 -> V_12 [ V_113 ] ) ) {
F_21 ( V_2 , L_25 ) ;
return F_44 ( V_7 -> V_12 [ V_113 ] ) ;
}
}
F_59 ( V_150 , V_7 ) ;
if ( ! V_2 -> V_171 ) {
V_10 = F_48 ( V_7 ) ;
if ( V_10 < 0 ) {
F_21 ( V_2 , L_26 ) ;
return V_10 ;
}
} else {
return - V_159 ;
}
if ( V_7 -> V_48 == V_172 )
V_7 -> V_23 = false ;
if ( V_7 -> V_23 )
F_60 ( & V_7 -> V_24 ,
F_22 ) ;
if ( V_7 -> V_48 != V_172 )
F_42 ( V_7 ) ;
if ( F_44 ( V_7 -> V_82 ) == - V_142 )
return F_44 ( V_7 -> V_82 ) ;
else if ( ! V_7 -> V_82 )
F_45 ( V_7 -> V_2 , L_27 ) ;
V_10 = F_4 ( V_7 , V_173 , 1 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_4 ( V_7 , V_173 , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_30 ( V_7 ) ;
if ( V_10 < 0 ) {
F_21 ( V_2 , L_28 ) ;
return V_10 ;
}
V_10 = F_39 ( V_7 ) ;
if ( V_10 < 0 ) {
F_21 ( V_2 , L_29 ) ;
return V_10 ;
}
V_10 = F_61 ( V_2 , V_150 -> V_109 , NULL ,
F_28 ,
V_174 |
V_175 | V_176 ,
V_47 [ V_7 -> V_48 ] , V_7 ) ;
if ( V_10 ) {
F_21 ( V_2 , L_30 , V_150 -> V_109 ) ;
return V_10 ;
}
V_10 = F_62 ( & V_7 -> V_112 -> V_2 . V_177 , & V_178 ) ;
if ( V_10 < 0 ) {
F_21 ( V_2 , L_31 ) ;
return V_10 ;
}
return 0 ;
}
static int F_63 ( struct V_149 * V_150 )
{
struct V_6 * V_7 = F_64 ( V_150 ) ;
if ( V_7 -> V_23 )
F_9 ( & V_7 -> V_24 ) ;
F_65 ( & V_7 -> V_112 -> V_2 . V_177 , & V_178 ) ;
F_4 ( V_7 , V_173 , 1 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_33 ( V_2 ) ;
int V_10 = 0 ;
if ( V_7 -> V_23 )
F_9 ( & V_7 -> V_24 ) ;
V_10 = F_4 ( V_7 , V_173 , 1 ) ;
if ( V_10 < 0 )
F_21 ( V_7 -> V_2 , L_32 ) ;
return V_10 ;
}
static int F_67 ( struct V_1 * V_2 )
{
int V_10 ;
struct V_6 * V_7 = F_33 ( V_2 ) ;
V_10 = F_68 ( V_7 -> V_166 , V_179 , V_180 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_4 ( V_7 , V_173 , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_30 ( V_7 ) ;
if ( V_10 < 0 ) {
F_21 ( V_7 -> V_2 , L_33 ) ;
return V_10 ;
}
F_29 ( V_7 -> V_112 ) ;
return 0 ;
}

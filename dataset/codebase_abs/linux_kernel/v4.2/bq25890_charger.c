static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
int V_5 ;
int V_6 ;
V_5 = F_2 ( V_2 -> V_7 [ V_4 ] , & V_6 ) ;
if ( V_5 < 0 )
return V_5 ;
return V_6 ;
}
static int F_3 ( struct V_1 * V_2 ,
enum V_3 V_4 , T_1 V_6 )
{
return F_4 ( V_2 -> V_7 [ V_4 ] , V_6 ) ;
}
static T_1 F_5 ( T_2 V_8 , enum V_9 V_10 )
{
T_1 V_11 ;
if ( V_10 >= V_12 ) {
const T_2 * V_13 = V_14 [ V_10 ] . V_15 . V_13 ;
T_2 V_16 = V_14 [ V_10 ] . V_15 . V_17 ;
for ( V_11 = 1 ; V_11 < V_16 && V_13 [ V_11 ] <= V_8 ; V_11 ++ )
;
} else {
const struct V_18 * V_19 = & V_14 [ V_10 ] . V_20 ;
T_1 V_21 ;
V_21 = ( V_19 -> V_22 - V_19 -> V_23 ) / V_19 -> V_24 + 1 ;
for ( V_11 = 1 ;
V_11 < V_21 && ( V_11 * V_19 -> V_24 + V_19 -> V_23 <= V_8 ) ;
V_11 ++ )
;
}
return V_11 - 1 ;
}
static T_2 F_6 ( T_1 V_11 , enum V_9 V_10 )
{
const struct V_18 * V_19 ;
if ( V_10 >= V_12 )
return V_14 [ V_10 ] . V_15 . V_13 [ V_11 ] ;
V_19 = & V_14 [ V_10 ] . V_20 ;
return ( V_19 -> V_23 + V_11 * V_19 -> V_24 ) ;
}
static int F_7 ( struct V_25 * V_26 ,
enum V_27 V_28 ,
union V_29 * V_6 )
{
int V_5 ;
struct V_1 * V_2 = F_8 ( V_26 ) ;
struct V_30 V_31 ;
F_9 ( & V_2 -> V_32 ) ;
V_31 = V_2 -> V_31 ;
F_10 ( & V_2 -> V_32 ) ;
switch ( V_28 ) {
case V_33 :
if ( ! V_31 . V_34 )
V_6 -> V_35 = V_36 ;
else if ( V_31 . V_37 == V_38 )
V_6 -> V_35 = V_39 ;
else if ( V_31 . V_37 == V_40 ||
V_31 . V_37 == V_41 )
V_6 -> V_35 = V_42 ;
else if ( V_31 . V_37 == V_43 )
V_6 -> V_35 = V_44 ;
else
V_6 -> V_35 = V_45 ;
break;
case V_46 :
V_6 -> V_47 = V_48 ;
break;
case V_49 :
V_6 -> V_35 = V_31 . V_34 ;
break;
case V_50 :
if ( ! V_31 . V_51 && ! V_31 . V_52 && ! V_31 . V_53 )
V_6 -> V_35 = V_54 ;
else if ( V_31 . V_52 )
V_6 -> V_35 = V_55 ;
else if ( V_31 . V_51 == V_56 )
V_6 -> V_35 = V_57 ;
else if ( V_31 . V_51 == V_58 )
V_6 -> V_35 = V_59 ;
else
V_6 -> V_35 = V_60 ;
break;
case V_61 :
V_5 = F_1 ( V_2 , V_62 ) ;
if ( V_5 < 0 )
return V_5 ;
V_6 -> V_35 = V_5 * 50000 ;
break;
case V_63 :
V_6 -> V_35 = V_14 [ V_64 ] . V_20 . V_22 ;
break;
case V_65 :
if ( ! V_31 . V_34 ) {
V_6 -> V_35 = 0 ;
break;
}
V_5 = F_1 ( V_2 , V_66 ) ;
if ( V_5 < 0 )
return V_5 ;
V_6 -> V_35 = 2304000 + V_5 * 20000 ;
break;
case V_67 :
V_6 -> V_35 = V_14 [ V_68 ] . V_20 . V_22 ;
break;
case V_69 :
V_6 -> V_35 = F_6 ( V_2 -> V_70 . V_71 , V_72 ) ;
break;
default:
return - V_73 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
int V_74 , V_5 ;
struct {
enum V_3 V_10 ;
T_1 * V_75 ;
} V_76 [] = {
{ V_77 , & V_31 -> V_37 } ,
{ V_78 , & V_31 -> V_34 } ,
{ V_79 , & V_31 -> V_80 } ,
{ V_81 , & V_31 -> V_53 } ,
{ V_82 , & V_31 -> V_52 } ,
{ V_83 , & V_31 -> V_51 }
} ;
for ( V_74 = 0 ; V_74 < F_12 ( V_76 ) ; V_74 ++ ) {
V_5 = F_1 ( V_2 , V_76 [ V_74 ] . V_10 ) ;
if ( V_5 < 0 )
return V_5 ;
* V_76 [ V_74 ] . V_75 = V_5 ;
}
F_13 ( V_2 -> V_84 , L_1 ,
V_31 -> V_37 , V_31 -> V_34 , V_31 -> V_80 ,
V_31 -> V_51 , V_31 -> V_53 , V_31 -> V_52 ) ;
return 0 ;
}
static bool F_14 ( struct V_1 * V_2 ,
struct V_30 * V_85 )
{
struct V_30 V_86 ;
F_9 ( & V_2 -> V_32 ) ;
V_86 = V_2 -> V_31 ;
F_10 ( & V_2 -> V_32 ) ;
return ( V_86 . V_37 != V_85 -> V_37 ||
V_86 . V_51 != V_85 -> V_51 ||
V_86 . V_34 != V_85 -> V_34 ||
V_86 . V_52 != V_85 -> V_52 ||
V_86 . V_53 != V_85 -> V_53 ||
V_86 . V_80 != V_85 -> V_80 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_30 * V_85 )
{
int V_5 ;
struct V_30 V_86 ;
F_9 ( & V_2 -> V_32 ) ;
V_86 = V_2 -> V_31 ;
F_10 ( & V_2 -> V_32 ) ;
if ( ! V_85 -> V_34 ) {
V_5 = F_3 ( V_2 , V_87 , 0 ) ;
if ( V_5 < 0 )
goto error;
} else if ( ! V_86 . V_34 ) {
V_5 = F_3 ( V_2 , V_87 , 1 ) ;
if ( V_5 < 0 )
goto error;
}
return;
error:
F_16 ( V_2 -> V_84 , L_2 ) ;
}
static T_3 F_17 ( int V_88 , void * V_89 )
{
struct V_1 * V_2 = V_89 ;
int V_5 ;
struct V_30 V_31 ;
V_5 = F_11 ( V_2 , & V_31 ) ;
if ( V_5 < 0 )
goto V_90;
if ( ! F_14 ( V_2 , & V_31 ) )
goto V_90;
F_15 ( V_2 , & V_31 ) ;
F_9 ( & V_2 -> V_32 ) ;
V_2 -> V_31 = V_31 ;
F_10 ( & V_2 -> V_32 ) ;
F_18 ( V_2 -> V_91 ) ;
V_90:
return V_92 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_5 ;
int V_93 = 10 ;
V_5 = F_3 ( V_2 , V_94 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
do {
V_5 = F_1 ( V_2 , V_94 ) ;
if ( V_5 < 0 )
return V_5 ;
F_20 ( 5 , 10 ) ;
} while ( V_5 == 1 && -- V_93 );
if ( ! V_93 )
return - V_95 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_5 ;
int V_74 ;
struct V_30 V_31 ;
const struct {
enum V_3 V_10 ;
T_2 V_8 ;
} V_70 [] = {
{ V_96 , V_2 -> V_70 . V_97 } ,
{ V_98 , V_2 -> V_70 . V_99 } ,
{ V_100 , V_2 -> V_70 . V_71 } ,
{ V_101 , V_2 -> V_70 . V_102 } ,
{ V_103 , V_2 -> V_70 . V_104 } ,
{ V_105 , V_2 -> V_70 . V_106 } ,
{ V_107 , V_2 -> V_70 . V_108 } ,
{ V_109 , V_2 -> V_70 . V_110 } ,
{ V_111 , V_2 -> V_70 . V_112 } ,
{ V_113 , V_2 -> V_70 . V_114 }
} ;
V_5 = F_19 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_3 ( V_2 , V_115 , 0 ) ;
if ( V_5 < 0 )
return V_5 ;
for ( V_74 = 0 ; V_74 < F_12 ( V_70 ) ; V_74 ++ ) {
V_5 = F_3 ( V_2 , V_70 [ V_74 ] . V_10 ,
V_70 [ V_74 ] . V_8 ) ;
if ( V_5 < 0 )
return V_5 ;
}
V_5 = F_3 ( V_2 , V_116 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_11 ( V_2 , & V_31 ) ;
if ( V_5 < 0 )
return V_5 ;
F_9 ( & V_2 -> V_32 ) ;
V_2 -> V_31 = V_31 ;
F_10 ( & V_2 -> V_32 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_117 V_118 = { . V_119 = V_2 , } ;
V_118 . V_120 = V_121 ;
V_118 . V_122 = F_12 ( V_121 ) ;
V_2 -> V_91 = F_23 ( V_2 -> V_84 , & V_123 ,
& V_118 ) ;
return F_24 ( V_2 -> V_91 ) ;
}
static void F_25 ( struct V_124 * V_75 )
{
int V_5 ;
struct V_1 * V_2 =
F_26 ( V_75 , struct V_1 , V_125 ) ;
switch ( V_2 -> V_126 ) {
case V_127 :
V_5 = F_3 ( V_2 , V_128 , 1 ) ;
if ( V_5 < 0 )
goto error;
break;
case V_129 :
V_5 = F_3 ( V_2 , V_128 , 0 ) ;
if ( V_5 < 0 )
goto error;
F_18 ( V_2 -> V_91 ) ;
break;
}
return;
error:
F_16 ( V_2 -> V_84 , L_3 ) ;
}
static int F_27 ( struct V_130 * V_131 , unsigned long V_6 ,
void * V_132 )
{
struct V_1 * V_2 =
F_26 ( V_131 , struct V_1 , V_133 ) ;
V_2 -> V_126 = V_6 ;
F_28 ( V_134 , & V_2 -> V_125 ) ;
return V_135 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_136 * V_88 ;
V_88 = F_30 ( V_2 -> V_84 , V_137 , 0 , V_138 ) ;
if ( F_31 ( V_88 ) ) {
F_16 ( V_2 -> V_84 , L_4 ) ;
return F_32 ( V_88 ) ;
}
return F_33 ( V_88 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
int V_5 ;
T_2 V_139 ;
int V_74 ;
struct V_140 * V_141 = & V_2 -> V_70 ;
struct {
char * V_142 ;
bool V_143 ;
enum V_9 V_144 ;
T_1 * V_145 ;
} V_146 [] = {
{ L_5 , false , V_64 , & V_141 -> V_97 } ,
{ L_6 , false , V_68 , & V_141 -> V_99 } ,
{ L_7 , false , V_72 , & V_141 -> V_71 } ,
{ L_8 , false , V_72 , & V_141 -> V_102 } ,
{ L_9 , false , V_147 , & V_141 -> V_104 } ,
{ L_10 , false , V_148 , & V_141 -> V_106 } ,
{ L_11 , false , V_149 , & V_141 -> V_108 } ,
{ L_12 , true , V_12 , & V_141 -> V_114 }
} ;
V_141 -> V_114 = 3 ;
for ( V_74 = 0 ; V_74 < F_12 ( V_146 ) ; V_74 ++ ) {
V_5 = F_35 ( V_2 -> V_84 , V_146 [ V_74 ] . V_142 ,
& V_139 ) ;
if ( V_5 < 0 ) {
if ( V_146 [ V_74 ] . V_143 )
continue;
return V_5 ;
}
* V_146 [ V_74 ] . V_145 = F_5 ( V_139 ,
V_146 [ V_74 ] . V_144 ) ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_5 ;
struct V_140 * V_141 = & V_2 -> V_70 ;
V_5 = F_34 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
V_141 -> V_112 = F_37 ( V_2 -> V_84 , L_13 ) ;
V_141 -> V_110 = F_37 ( V_2 -> V_84 , L_14 ) ;
return 0 ;
}
static int F_38 ( struct V_150 * V_151 ,
const struct V_152 * V_10 )
{
struct V_153 * V_154 = F_39 ( V_151 -> V_84 . V_155 ) ;
struct V_156 * V_84 = & V_151 -> V_84 ;
struct V_1 * V_2 ;
int V_5 ;
int V_74 ;
if ( ! F_40 ( V_154 , V_157 ) ) {
F_16 ( V_84 , L_15 ) ;
return - V_158 ;
}
V_2 = F_41 ( V_84 , sizeof( * V_2 ) , V_159 ) ;
if ( ! V_2 )
return - V_160 ;
V_2 -> V_151 = V_151 ;
V_2 -> V_84 = V_84 ;
F_42 ( & V_2 -> V_32 ) ;
V_2 -> V_161 = F_43 ( V_151 , & V_162 ) ;
if ( F_31 ( V_2 -> V_161 ) ) {
F_16 ( V_84 , L_16 ) ;
return F_32 ( V_2 -> V_161 ) ;
}
for ( V_74 = 0 ; V_74 < F_12 ( V_163 ) ; V_74 ++ ) {
const struct V_164 * V_165 = V_163 ;
V_2 -> V_7 [ V_74 ] = F_44 ( V_84 , V_2 -> V_161 ,
V_165 [ V_74 ] ) ;
if ( F_31 ( V_2 -> V_7 [ V_74 ] ) ) {
F_16 ( V_84 , L_17 ) ;
return F_32 ( V_2 -> V_7 [ V_74 ] ) ;
}
}
F_45 ( V_151 , V_2 ) ;
V_2 -> V_166 = F_1 ( V_2 , V_167 ) ;
if ( V_2 -> V_166 < 0 ) {
F_16 ( V_84 , L_18 ) ;
return V_2 -> V_166 ;
}
if ( V_2 -> V_166 != V_168 ) {
F_16 ( V_84 , L_19 , V_2 -> V_166 ) ;
return - V_158 ;
}
if ( ! V_84 -> V_169 ) {
V_5 = F_36 ( V_2 ) ;
if ( V_5 < 0 ) {
F_16 ( V_84 , L_20 ) ;
return V_5 ;
}
} else {
return - V_158 ;
}
V_5 = F_21 ( V_2 ) ;
if ( V_5 < 0 ) {
F_16 ( V_84 , L_21 ) ;
return V_5 ;
}
if ( V_151 -> V_88 <= 0 )
V_151 -> V_88 = F_29 ( V_2 ) ;
if ( V_151 -> V_88 < 0 ) {
F_16 ( V_84 , L_22 ) ;
return V_151 -> V_88 ;
}
V_2 -> V_170 = F_46 ( V_84 , V_171 ) ;
if ( ! F_47 ( V_2 -> V_170 ) ) {
F_48 ( & V_2 -> V_125 , F_25 ) ;
V_2 -> V_133 . V_172 = F_27 ;
F_49 ( V_2 -> V_170 , & V_2 -> V_133 ) ;
}
V_5 = F_50 ( V_84 , V_151 -> V_88 , NULL ,
F_17 ,
V_173 | V_174 ,
V_137 , V_2 ) ;
if ( V_5 )
goto V_175;
V_5 = F_22 ( V_2 ) ;
if ( V_5 < 0 ) {
F_16 ( V_84 , L_23 ) ;
goto V_175;
}
return 0 ;
V_175:
if ( ! F_47 ( V_2 -> V_170 ) )
F_51 ( V_2 -> V_170 , & V_2 -> V_133 ) ;
return V_5 ;
}
static int F_52 ( struct V_150 * V_151 )
{
struct V_1 * V_2 = F_53 ( V_151 ) ;
F_54 ( V_2 -> V_91 ) ;
if ( ! F_47 ( V_2 -> V_170 ) )
F_51 ( V_2 -> V_170 , & V_2 -> V_133 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
static int F_55 ( struct V_156 * V_84 )
{
struct V_1 * V_2 = F_56 ( V_84 ) ;
return F_3 ( V_2 , V_87 , 0 ) ;
}
static int F_57 ( struct V_156 * V_84 )
{
int V_5 ;
struct V_30 V_31 ;
struct V_1 * V_2 = F_56 ( V_84 ) ;
V_5 = F_11 ( V_2 , & V_31 ) ;
if ( V_5 < 0 )
return V_5 ;
F_9 ( & V_2 -> V_32 ) ;
V_2 -> V_31 = V_31 ;
F_10 ( & V_2 -> V_32 ) ;
if ( V_31 . V_34 ) {
V_5 = F_3 ( V_2 , V_87 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
}
F_18 ( V_2 -> V_91 ) ;
return 0 ;
}

const char * F_1 ( T_1 V_1 )
{
T_1 V_2 = F_2 ( V_1 ) ;
F_3 ( V_2 < V_3 ,
L_1 ,
V_2 , V_3 ) ;
F_3 ( V_4 [ V_2 ] . V_1 == V_1 ,
L_2 ,
V_2 , V_4 [ V_2 ] . V_1 , V_1 ) ;
return V_4 [ V_2 ] . V_5 ;
}
static const char * F_4 ( T_1 V_1 )
{
F_5 ( V_6 [ V_1 ] . V_1 == V_1 ) ;
return V_6 [ V_1 ] . V_5 ;
}
static void
F_6 ( struct V_7 * V_8 , char * V_9 ,
char * V_10 ,
struct V_7 * * V_11 ,
struct V_12 * * V_13 )
{
struct V_7 * V_14 ;
struct V_12 * V_15 ;
int V_16 , V_17 ;
unsigned int V_18 = V_19 |
V_20 ;
F_5 ( * V_11 == NULL ) ;
F_5 ( * V_13 == NULL ) ;
V_15 = F_7 ( V_21 + V_3 ,
0 ) ;
if ( V_15 == NULL )
return;
if ( V_9 != NULL ) {
V_14 = F_8 ( V_9 , V_8 , NULL , NULL ) ;
if ( F_9 ( V_14 ) ) {
F_10 ( & V_15 ) ;
return;
}
} else {
V_14 = V_8 ;
}
F_11 ( V_15 , V_22 ,
V_18 , L_3 , L_4 ) ;
F_11 ( V_15 , V_23 ,
V_18 , L_5 , L_6 ) ;
F_11 ( V_15 , V_24 ,
V_18 , L_7 , L_6 ) ;
F_11 ( V_15 , V_25 ,
V_18 , L_8 , L_9 ) ;
F_11 ( V_15 , V_26 ,
V_18 , L_10 , L_11 ) ;
for ( V_16 = 0 ; V_16 < V_27 ; V_16 ++ ) {
char * V_28 ;
switch ( V_16 ) {
case V_29 :
case V_30 :
V_28 = L_12 ;
break;
default:
V_28 = L_6 ;
break;
}
F_11 ( V_15 , V_31 + V_16 ,
V_18 ,
F_4 ( V_16 ) , V_28 ) ;
}
for ( V_16 = 0 ; V_16 < V_3 ; V_16 ++ ) {
T_1 V_1 = V_4 [ V_16 ] . V_1 ;
F_11 ( V_15 ,
V_21 + V_16 , V_18 ,
F_1 ( V_1 ) , L_4 ) ;
}
V_17 = F_12 ( V_14 , V_10 , V_15 ) ;
if ( V_17 < 0 ) {
if ( V_9 != NULL )
F_13 ( & V_14 ) ;
F_10 ( & V_15 ) ;
} else {
if ( V_9 != NULL )
* V_11 = V_14 ;
* V_13 = V_15 ;
}
}
static int
F_14 ( struct V_32 * V_33 , void * V_34 )
{
struct V_35 * V_36 = V_33 -> V_37 ;
struct V_38 * V_39 ;
int V_40 = 0 ;
int V_16 ;
F_15 (svcpt, i, svc)
V_40 += V_39 -> V_41 ;
F_16 ( V_33 , L_13 , V_40 ) ;
return 0 ;
}
static int
F_17 ( struct V_32 * V_33 , void * V_42 )
{
struct V_35 * V_36 = V_33 -> V_37 ;
struct V_38 * V_39 ;
int V_40 = 0 ;
int V_16 ;
F_15 (svcpt, i, svc)
V_40 += V_36 -> V_43 ;
F_16 ( V_33 , L_13 , V_40 ) ;
return 0 ;
}
static T_2
F_18 ( struct V_44 * V_44 ,
const char T_3 * V_45 ,
T_4 V_46 , T_5 * V_47 )
{
struct V_35 * V_36 = ( (struct V_32 * ) V_44 -> V_48 ) -> V_37 ;
int V_49 ;
int V_50 ;
int V_17 ;
V_17 = F_19 ( V_45 , V_46 , & V_50 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_50 < 0 )
return - V_51 ;
V_49 = ( V_36 -> V_52 + V_53 - 1 ) >> V_54 ;
if ( V_50 > V_55 / ( 2 * V_49 ) )
return - V_51 ;
F_20 ( & V_36 -> V_56 ) ;
if ( V_50 == 0 )
V_36 -> V_43 = 0 ;
else
V_36 -> V_43 = F_21 ( 1 , ( V_50 / V_36 -> V_57 ) ) ;
F_22 ( & V_36 -> V_56 ) ;
return V_46 ;
}
static T_2 F_23 ( struct V_58 * V_59 , struct V_60 * V_61 ,
char * V_62 )
{
struct V_35 * V_36 = F_24 ( V_59 , struct V_35 ,
V_63 ) ;
return sprintf ( V_62 , L_13 , V_36 -> V_64 * V_36 -> V_57 ) ;
}
static T_2 F_25 ( struct V_58 * V_59 , struct V_60 * V_61 ,
const char * V_45 , T_4 V_46 )
{
struct V_35 * V_36 = F_24 ( V_59 , struct V_35 ,
V_63 ) ;
unsigned long V_50 ;
int V_17 = F_26 ( V_45 , 10 , & V_50 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_50 / V_36 -> V_57 < V_65 )
return - V_51 ;
F_20 ( & V_36 -> V_56 ) ;
if ( V_50 > V_36 -> V_66 * V_36 -> V_57 ) {
F_22 ( & V_36 -> V_56 ) ;
return - V_51 ;
}
V_36 -> V_64 = V_50 / V_36 -> V_57 ;
F_22 ( & V_36 -> V_56 ) ;
return V_46 ;
}
static T_2 F_27 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
char * V_62 )
{
struct V_35 * V_36 = F_24 ( V_59 , struct V_35 ,
V_63 ) ;
struct V_38 * V_39 ;
int V_40 = 0 ;
int V_16 ;
F_15 (svcpt, i, svc)
V_40 += V_39 -> V_67 ;
return sprintf ( V_62 , L_13 , V_40 ) ;
}
static T_2 F_28 ( struct V_58 * V_59 , struct V_60 * V_61 ,
char * V_62 )
{
struct V_35 * V_36 = F_24 ( V_59 , struct V_35 ,
V_63 ) ;
return sprintf ( V_62 , L_13 , V_36 -> V_66 * V_36 -> V_57 ) ;
}
static T_2 F_29 ( struct V_58 * V_59 , struct V_60 * V_61 ,
const char * V_45 , T_4 V_46 )
{
struct V_35 * V_36 = F_24 ( V_59 , struct V_35 ,
V_63 ) ;
unsigned long V_50 ;
int V_17 = F_26 ( V_45 , 10 , & V_50 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_50 / V_36 -> V_57 < V_65 )
return - V_51 ;
F_20 ( & V_36 -> V_56 ) ;
if ( V_50 < V_36 -> V_64 * V_36 -> V_57 ) {
F_22 ( & V_36 -> V_56 ) ;
return - V_51 ;
}
V_36 -> V_66 = V_50 / V_36 -> V_57 ;
F_22 ( & V_36 -> V_56 ) ;
return V_46 ;
}
static const char * F_30 ( enum V_68 V_69 )
{
switch ( V_69 ) {
default:
F_31 () ;
case V_70 :
return L_14 ;
case V_71 :
return L_15 ;
case V_72 :
return L_16 ;
case V_73 :
return L_17 ;
case V_74 :
return L_18 ;
}
}
void F_32 ( struct V_75 * V_76 ,
struct V_77 * V_78 )
{
F_5 ( V_76 != NULL ) ;
F_5 ( V_78 != NULL ) ;
F_33 ( & V_76 -> V_79 -> V_80 ) ;
memcpy ( V_78 -> V_81 , V_76 -> V_82 -> V_83 , V_84 ) ;
V_78 -> V_85 = ! ! ( V_76 -> V_86 & V_87 ) ;
V_78 -> V_88 = V_76 -> V_89 ;
V_78 -> V_90 = V_76 -> V_91 ;
V_78 -> V_92 = V_76 -> V_93 ;
}
static int F_34 ( struct V_32 * V_33 , void * V_42 )
{
struct V_35 * V_36 = V_33 -> V_37 ;
struct V_38 * V_39 ;
struct V_94 * V_95 ;
struct V_75 * V_76 ;
struct V_77 * V_96 ;
struct V_77 V_97 ;
unsigned V_98 ;
unsigned V_99 = 0 ;
bool V_100 = false ;
int V_16 ;
int V_17 = 0 ;
F_35 ( & V_101 . V_102 ) ;
V_95 = F_36 ( V_36 -> V_103 [ 0 ] , false ) ;
F_20 ( & V_95 -> V_80 ) ;
V_98 = V_36 -> V_103 [ 0 ] -> V_104 . V_105 ;
F_22 ( & V_95 -> V_80 ) ;
V_96 = F_37 ( V_98 , sizeof( * V_96 ) , V_106 ) ;
if ( V_96 == NULL ) {
V_17 = - V_107 ;
goto V_108;
}
V_109:
F_15 (svcpt, i, svc) {
V_95 = F_36 ( V_39 , V_100 ) ;
F_20 ( & V_95 -> V_80 ) ;
V_99 = 0 ;
F_38 (policy, &nrs->nrs_policy_list,
pol_list) {
F_5 ( V_99 < V_98 ) ;
F_32 ( V_76 , & V_97 ) ;
if ( V_16 == 0 ) {
memcpy ( V_96 [ V_99 ] . V_81 , V_97 . V_81 ,
V_84 ) ;
memcpy ( & V_96 [ V_99 ] . V_88 , & V_97 . V_88 ,
sizeof( V_97 . V_88 ) ) ;
V_96 [ V_99 ] . V_85 = V_97 . V_85 ;
} else {
F_5 ( strncmp ( V_96 [ V_99 ] . V_81 ,
V_97 . V_81 ,
V_84 ) == 0 ) ;
F_5 ( V_96 [ V_99 ] . V_85 ==
V_97 . V_85 ) ;
}
V_96 [ V_99 ] . V_90 += V_97 . V_90 ;
V_96 [ V_99 ] . V_92 += V_97 . V_92 ;
V_99 ++ ;
}
F_22 ( & V_95 -> V_80 ) ;
}
F_16 ( V_33 , L_19 ,
! V_100 ? L_20 : L_21 ) ;
for ( V_99 = 0 ; V_99 < V_98 ; V_99 ++ ) {
F_16 ( V_33 , L_22
L_23
L_24
L_25
L_26 ,
V_96 [ V_99 ] . V_81 ,
F_30 ( V_96 [ V_99 ] . V_88 ) ,
V_96 [ V_99 ] . V_85 ? L_27 : L_28 ,
( int ) V_96 [ V_99 ] . V_90 ,
( int ) V_96 [ V_99 ] . V_92 ) ;
}
if ( ! V_100 && F_39 ( V_36 ) ) {
memset ( V_96 , 0 , V_98 * sizeof( * V_96 ) ) ;
V_100 = true ;
goto V_109;
}
F_40 ( V_96 ) ;
V_108:
F_41 ( & V_101 . V_102 ) ;
return V_17 ;
}
static T_2 F_42 ( struct V_44 * V_44 ,
const char T_3 * V_45 ,
T_4 V_46 , T_5 * V_47 )
{
struct V_35 * V_36 = ( (struct V_32 * ) V_44 -> V_48 ) -> V_37 ;
enum V_110 V_111 = V_112 ;
char * V_113 ;
char * V_114 = NULL ;
char * V_115 ;
int V_17 = 0 ;
if ( V_46 >= V_116 )
return - V_117 ;
V_113 = F_43 ( V_116 , V_106 ) ;
if ( ! V_113 )
return - V_107 ;
V_114 = V_113 ;
if ( F_44 ( V_113 , V_45 , V_46 ) ) {
V_17 = - V_118 ;
goto V_119;
}
V_113 [ V_46 ] = '\0' ;
V_115 = F_45 ( & V_113 , L_29 ) ;
if ( strlen ( V_115 ) > V_84 - 1 ) {
V_17 = - V_117 ;
goto V_119;
}
if ( V_113 == NULL )
goto V_120;
if ( strcmp ( V_113 , L_30 ) == 0 )
V_111 = V_121 ;
else if ( strcmp ( V_113 , L_31 ) == 0 )
V_111 = V_122 ;
else {
V_17 = - V_117 ;
goto V_119;
}
V_120:
if ( V_111 == V_122 && ! F_39 ( V_36 ) ) {
V_17 = - V_123 ;
goto V_119;
} else if ( V_111 == V_112 && ! F_39 ( V_36 ) )
V_111 = V_121 ;
F_35 ( & V_101 . V_102 ) ;
V_17 = F_46 ( V_36 , V_111 , V_115 , V_124 ,
false , NULL ) ;
F_41 ( & V_101 . V_102 ) ;
V_119:
F_40 ( V_114 ) ;
return V_17 < 0 ? V_17 : V_46 ;
}
static int
F_47 ( struct V_38 * V_39 ,
struct V_125 * V_126 ,
T_6 V_127 )
{
struct V_128 * V_129 ;
struct V_130 * V_131 ;
if ( V_126 -> V_132 != NULL &&
V_126 -> V_133 > V_39 -> V_134 &&
V_126 -> V_133 <= V_127 ) {
F_3 ( V_126 -> V_133 == V_126 -> V_132 -> V_135 ,
L_32 ,
V_39 -> V_136 -> V_137 , V_39 -> V_138 ,
V_126 -> V_133 , V_126 -> V_132 -> V_135 ) ;
F_3 ( ! F_48 ( & V_39 -> V_139 ) ,
L_33 ,
V_39 -> V_136 -> V_137 , V_39 -> V_138 ,
V_127 , V_126 -> V_133 , V_39 -> V_134 ) ;
V_129 = & V_126 -> V_132 -> V_140 ;
} else {
V_129 = V_39 -> V_139 . V_141 ;
}
while ( V_129 != & V_39 -> V_139 ) {
V_131 = F_49 ( V_129 , struct V_130 , V_140 ) ;
if ( V_131 -> V_135 >= V_127 ) {
V_126 -> V_133 = V_131 -> V_135 ;
V_126 -> V_132 = V_131 ;
return 0 ;
}
V_129 = V_129 -> V_141 ;
}
return - V_142 ;
}
static void *
F_50 ( struct V_32 * V_143 , T_5 * V_144 )
{
struct V_35 * V_36 = V_143 -> V_37 ;
struct V_38 * V_39 ;
struct V_125 * V_126 ;
unsigned int V_145 ;
int V_17 ;
int V_16 ;
if ( sizeof( T_5 ) != sizeof( T_6 ) ) {
F_51 ( L_34 ,
( int ) sizeof( T_5 ) ) ;
return NULL ;
}
V_126 = F_43 ( sizeof( * V_126 ) , V_106 ) ;
if ( ! V_126 )
return NULL ;
V_126 -> V_133 = 0 ;
V_126 -> V_132 = NULL ;
V_145 = F_52 ( V_36 , * V_144 ) ;
F_15 (svcpt, i, svc) {
if ( V_16 < V_145 )
continue;
if ( V_16 > V_145 )
* V_144 = F_53 ( V_36 , V_16 ) ;
F_20 ( & V_39 -> V_146 ) ;
V_17 = F_47 ( V_39 , V_126 ,
F_54 ( V_36 , * V_144 ) ) ;
F_22 ( & V_39 -> V_146 ) ;
if ( V_17 == 0 ) {
* V_144 = F_55 ( V_36 , V_126 -> V_133 ) ;
V_126 -> V_147 = V_16 ;
return V_126 ;
}
}
F_40 ( V_126 ) ;
return NULL ;
}
static void
F_56 ( struct V_32 * V_143 , void * V_148 )
{
struct V_125 * V_126 = V_148 ;
F_40 ( V_126 ) ;
}
static void *
F_57 ( struct V_32 * V_143 ,
void * V_148 , T_5 * V_144 )
{
struct V_35 * V_36 = V_143 -> V_37 ;
struct V_125 * V_126 = V_148 ;
struct V_38 * V_39 ;
T_6 V_127 ;
int V_17 ;
int V_16 ;
for ( V_16 = V_126 -> V_147 ; V_16 < V_36 -> V_57 ; V_16 ++ ) {
V_39 = V_36 -> V_103 [ V_16 ] ;
if ( V_16 > V_126 -> V_147 ) {
V_126 -> V_132 = NULL ;
V_127 = V_126 -> V_133 = 0 ;
} else {
V_127 = V_126 -> V_133 + ( 1 << V_36 -> V_149 ) ;
}
F_20 ( & V_39 -> V_146 ) ;
V_17 = F_47 ( V_39 , V_126 , V_127 ) ;
F_22 ( & V_39 -> V_146 ) ;
if ( V_17 == 0 ) {
* V_144 = F_55 ( V_36 , V_126 -> V_133 ) ;
V_126 -> V_147 = V_16 ;
return V_126 ;
}
}
F_40 ( V_126 ) ;
return NULL ;
}
void F_58 ( void * V_32 , struct V_130 * V_131 )
{
struct V_32 * V_150 = V_32 ;
switch ( V_131 -> V_151 ) {
case V_152 :
F_16 ( V_150 , L_35 ) ;
break;
case V_153 :
case V_154 :
F_16 ( V_150 , L_36 , F_59 ( V_131 -> V_155 ) ) ;
break;
default:
F_60 ( V_156 , V_131 , L_37 , V_131 -> V_151 ) ;
}
}
static int F_61 ( struct V_32 * V_143 , void * V_148 )
{
struct V_35 * V_36 = V_143 -> V_37 ;
struct V_125 * V_126 = V_148 ;
struct V_38 * V_39 ;
struct V_130 * V_131 ;
int V_17 ;
F_5 ( V_126 -> V_147 < V_36 -> V_57 ) ;
V_39 = V_36 -> V_103 [ V_126 -> V_147 ] ;
F_20 ( & V_39 -> V_146 ) ;
V_17 = F_47 ( V_39 , V_126 , V_126 -> V_133 ) ;
if ( V_17 == 0 ) {
V_131 = V_126 -> V_132 ;
F_16 ( V_143 , L_38 ,
V_131 -> V_135 , F_62 ( V_131 -> V_157 ) ,
F_63 ( V_131 -> V_158 ) , V_131 -> V_159 ,
V_131 -> V_160 , F_64 ( V_131 ) ,
V_131 -> V_161 . V_162 ,
V_131 -> V_163 - V_131 -> V_161 . V_162 ,
V_131 -> V_163 - V_131 -> V_164 ) ;
if ( V_36 -> V_165 . V_166 == NULL )
F_16 ( V_143 , L_39 ) ;
else
V_36 -> V_165 . V_166 ( V_143 , V_126 -> V_132 ) ;
}
F_22 ( & V_39 -> V_146 ) ;
return V_17 ;
}
static int
F_65 ( struct V_167 * V_167 , struct V_44 * V_44 )
{
static struct V_168 V_169 = {
. V_170 = F_50 ,
. V_171 = F_56 ,
. V_141 = F_57 ,
. V_172 = F_61 ,
} ;
struct V_32 * V_173 ;
int V_17 ;
V_17 = F_66 ( V_44 , & V_169 ) ;
if ( V_17 )
return V_17 ;
V_173 = V_44 -> V_48 ;
V_173 -> V_37 = V_167 -> V_174 ;
return 0 ;
}
static int F_67 ( struct V_32 * V_33 , void * V_42 )
{
struct V_35 * V_36 = V_33 -> V_37 ;
struct V_38 * V_39 ;
struct V_175 V_176 ;
T_7 V_177 ;
unsigned int V_178 ;
unsigned int V_179 ;
int V_16 ;
if ( V_180 ) {
F_16 ( V_33 , L_40 ,
V_181 ) ;
return 0 ;
}
F_15 (svcpt, i, svc) {
V_178 = F_68 ( & V_39 -> V_182 ) ;
V_179 = V_39 -> V_182 . V_183 ;
V_177 = V_39 -> V_182 . V_184 ;
F_69 ( & V_176 , F_70 () - V_177 ) ;
F_16 ( V_33 , L_41
V_185 L_42 , L_43 ,
V_178 , V_179 , V_177 , F_71 ( & V_176 ) ) ;
F_72 ( V_33 , & V_39 -> V_182 ) ;
}
return 0 ;
}
static T_2 F_73 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
char * V_62 )
{
struct V_35 * V_36 = F_24 ( V_59 , struct V_35 ,
V_63 ) ;
return sprintf ( V_62 , L_13 , V_36 -> V_186 ) ;
}
static T_2 F_74 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
const char * V_45 ,
T_4 V_46 )
{
struct V_35 * V_36 = F_24 ( V_59 , struct V_35 ,
V_63 ) ;
int V_17 ;
int V_50 ;
V_17 = F_75 ( V_45 , 10 , & V_50 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_50 < 0 )
return - V_51 ;
F_20 ( & V_36 -> V_56 ) ;
V_36 -> V_186 = V_50 ;
F_22 ( & V_36 -> V_56 ) ;
return V_46 ;
}
static void F_76 ( struct V_58 * V_59 )
{
struct V_35 * V_36 = F_24 ( V_59 , struct V_35 ,
V_63 ) ;
F_77 ( & V_36 -> V_187 ) ;
}
void F_78 ( struct V_35 * V_36 )
{
if ( V_36 -> V_63 . V_188 ) {
F_79 ( & V_36 -> V_63 ) ;
F_80 ( & V_36 -> V_187 ) ;
}
}
int F_81 ( struct V_188 * V_189 ,
struct V_35 * V_36 )
{
int V_17 ;
V_36 -> V_63 . V_188 = V_189 ;
F_82 ( & V_36 -> V_187 ) ;
V_17 = F_83 ( & V_36 -> V_63 , & V_190 , NULL ,
L_44 , V_36 -> V_137 ) ;
return V_17 ;
}
void F_84 ( struct V_7 * V_191 ,
struct V_35 * V_36 )
{
struct V_192 V_193 [] = {
{ . V_10 = L_45 ,
. V_194 = & V_195 ,
. V_196 = V_36 } ,
{ . V_10 = L_46 ,
. V_194 = & V_197 ,
. V_196 = V_36 } ,
{ . V_10 = L_47 ,
. V_194 = & V_198 ,
. V_196 = V_36 } ,
{ . V_10 = L_48 ,
. V_194 = & V_199 ,
. V_196 = V_36 } ,
{ NULL }
} ;
static const struct V_200 V_201 = {
. V_202 = V_203 ,
. V_204 = F_65 ,
. V_205 = V_206 ,
. V_207 = V_208 ,
. V_209 = V_210 ,
} ;
int V_17 ;
F_6 ( V_191 , V_36 -> V_137 ,
L_49 , & V_36 -> V_211 ,
& V_36 -> V_212 ) ;
if ( V_36 -> V_211 == NULL )
return;
F_85 ( V_36 -> V_211 , V_193 , NULL ) ;
V_17 = F_86 ( V_36 -> V_211 , L_50 ,
0400 , & V_201 , V_36 ) ;
if ( V_17 )
F_51 ( L_51 ) ;
}
void F_87 ( struct V_213 * V_214 )
{
F_6 ( V_214 -> V_215 , NULL , L_49 ,
& V_214 -> V_216 ,
& V_214 -> V_217 ) ;
}
void F_88 ( struct V_130 * V_131 , long V_218 )
{
struct V_12 * V_15 ;
T_1 V_219 = F_59 ( V_131 -> V_155 ) ;
int V_220 = F_2 ( V_219 ) ;
V_15 = V_131 -> V_221 -> V_222 -> V_217 ;
if ( V_15 == NULL || V_220 <= 0 )
return;
F_5 ( V_220 < V_3 ) ;
if ( ! ( V_219 == V_223 || V_219 == V_224 ) )
F_89 ( V_15 , V_220 + V_21 , V_218 ) ;
}
void F_90 ( struct V_130 * V_131 , int V_225 )
{
struct V_12 * V_15 ;
int V_226 ;
if ( ! V_131 -> V_221 )
return;
V_15 = V_131 -> V_221 -> V_222 -> V_217 ;
if ( ! V_15 )
return;
V_226 = F_59 ( V_131 -> V_155 ) ;
switch ( V_226 ) {
case V_227 :
V_226 = V_30 + V_31 ;
break;
case V_228 :
V_226 = V_29 + V_31 ;
break;
default:
F_3 ( 0 , L_52 , V_226 ) ;
break;
}
F_89 ( V_15 , V_226 , V_225 ) ;
}
void F_91 ( struct V_35 * V_36 )
{
if ( V_36 -> V_211 != NULL )
F_13 ( & V_36 -> V_211 ) ;
if ( V_36 -> V_212 )
F_10 ( & V_36 -> V_212 ) ;
}
void F_92 ( struct V_213 * V_229 )
{
if ( ! F_93 ( V_229 -> V_216 ) )
F_13 ( & V_229 -> V_216 ) ;
if ( V_229 -> V_217 )
F_10 ( & V_229 -> V_217 ) ;
}
int F_94 ( struct V_44 * V_44 , const char T_3 * V_45 ,
T_4 V_46 , T_5 * V_47 )
{
struct V_213 * V_229 = ( (struct V_32 * ) V_44 -> V_48 ) -> V_37 ;
char * V_230 ;
char * V_231 ;
V_230 = F_43 ( V_232 , V_106 ) ;
if ( ! V_230 )
return - V_107 ;
if ( F_44 ( V_230 , V_45 ,
F_95 (unsigned long, BUFLEN - 1 , count) ) ) {
V_46 = - V_118 ;
goto V_119;
}
V_231 = F_96 ( V_230 , F_95 (unsigned long, BUFLEN - 1 , count) ) ;
F_97 ( V_229 , V_233 , V_234 ) ;
if ( strncmp ( V_231 , L_53 , 4 ) == 0 )
F_98 ( V_229 , V_231 + 4 ) ;
else if ( strncmp ( V_231 , L_54 , 5 ) == 0 )
F_99 ( V_229 , V_231 + 5 ) ;
else
F_99 ( V_229 , V_231 ) ;
F_100 ( V_229 , V_233 , V_234 ) ;
V_119:
F_40 ( V_230 ) ;
return V_46 ;
}
int F_101 ( struct V_44 * V_44 , const char T_3 * V_45 ,
T_4 V_46 , T_5 * V_47 )
{
struct V_213 * V_229 = ( (struct V_32 * ) V_44 -> V_48 ) -> V_37 ;
struct V_130 * V_131 ;
int V_17 ;
F_102 ( V_229 ) ;
V_131 = F_103 ( V_229 -> V_235 . V_236 . V_237 ) ;
F_104 ( V_229 ) ;
if ( V_131 == NULL )
return - V_107 ;
V_131 -> V_238 = V_239 ;
V_17 = F_105 ( V_131 ) ;
F_106 ( V_131 ) ;
if ( V_17 >= 0 )
return V_46 ;
return V_17 ;
}
int F_107 ( struct V_44 * V_44 , const char T_3 * V_45 ,
T_4 V_46 , T_5 * V_47 )
{
struct V_213 * V_229 = ( (struct V_32 * ) V_44 -> V_48 ) -> V_37 ;
struct V_240 * V_241 = V_229 -> V_235 . V_236 . V_237 ;
char * V_230 = NULL ;
char * V_242 ;
char * V_243 ;
int V_244 = 1 ;
const char V_245 [] = L_55 ;
const int V_246 = sizeof( V_245 ) - 1 ;
if ( V_46 > V_53 - 1 || V_46 <= V_246 )
return - V_117 ;
V_230 = F_43 ( V_46 + 1 , V_106 ) ;
if ( ! V_230 )
return - V_107 ;
if ( F_44 ( V_230 , V_45 , V_46 ) ) {
V_46 = - V_118 ;
goto V_119;
}
V_230 [ V_46 ] = 0 ;
if ( strncmp ( V_245 , V_230 , V_246 ) != 0 ) {
V_46 = - V_117 ;
goto V_119;
}
V_242 = V_230 + V_246 ;
V_243 = strstr ( V_242 , L_56 ) ;
if ( V_243 ) {
T_1 V_247 ;
char * V_248 ;
* V_243 = 0 ;
V_244 = 0 ;
V_243 += strlen ( L_56 ) ;
V_247 = F_108 ( V_243 , & V_248 , 10 ) ;
if ( * V_248 ) {
F_109 ( L_57 , V_243 ) ;
} else if ( V_247 != V_241 -> V_249 . V_250 ) {
F_110 ( V_251 , L_58 ,
V_241 -> V_222 -> V_252 ,
V_241 -> V_249 . V_250 , V_247 ) ;
V_244 = 1 ;
} else {
F_110 ( V_251 , L_59 ,
V_241 -> V_222 -> V_252 , V_247 ) ;
}
}
if ( V_244 )
F_111 ( V_241 , V_242 , 1 ) ;
V_119:
F_40 ( V_230 ) ;
return V_46 ;
}
int F_112 ( struct V_32 * V_33 , void * V_42 )
{
struct V_213 * V_229 = V_33 -> V_37 ;
struct V_240 * V_241 = V_229 -> V_235 . V_236 . V_237 ;
F_102 ( V_229 ) ;
F_16 ( V_33 , L_13 , ! V_241 -> V_253 ) ;
F_104 ( V_229 ) ;
return 0 ;
}
int F_113 ( struct V_44 * V_44 , const char T_3 * V_45 ,
T_4 V_46 , T_5 * V_47 )
{
struct V_213 * V_229 = ( (struct V_32 * ) V_44 -> V_48 ) -> V_37 ;
struct V_254 * V_236 = & V_229 -> V_235 . V_236 ;
struct V_240 * V_241 = V_236 -> V_237 ;
int V_17 , V_50 ;
V_17 = F_19 ( V_45 , V_46 , & V_50 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_50 != 0 && V_50 != 1 )
return - V_51 ;
F_102 ( V_229 ) ;
F_20 ( & V_241 -> V_255 ) ;
V_241 -> V_253 = ! V_50 ;
F_22 ( & V_241 -> V_255 ) ;
F_104 ( V_229 ) ;
return V_46 ;
}

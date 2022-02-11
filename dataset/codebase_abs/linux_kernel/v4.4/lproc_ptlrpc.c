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
static void F_32 ( struct V_75 * V_76 ,
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
static int F_58 ( struct V_32 * V_143 , void * V_148 )
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
char V_150 [ V_151 ] ;
V_131 = V_126 -> V_132 ;
F_59 ( V_131 -> V_152 , V_150 , sizeof( V_150 ) ) ;
F_16 ( V_143 , L_35 ,
V_131 -> V_135 , V_150 ,
F_60 ( V_131 -> V_153 ) , V_131 -> V_154 ,
V_131 -> V_155 , F_61 ( V_131 ) ,
( V_156 ) V_131 -> V_157 . V_158 ,
( long ) ( V_131 -> V_159 - V_131 -> V_157 . V_158 ) ,
( long ) ( V_131 -> V_159 - V_131 -> V_160 ) ) ;
if ( V_36 -> V_161 . V_162 == NULL )
F_62 ( V_143 , '\n' ) ;
else
V_36 -> V_161 . V_162 ( V_143 , V_126 -> V_132 ) ;
}
F_22 ( & V_39 -> V_146 ) ;
return V_17 ;
}
static int
F_63 ( struct V_163 * V_163 , struct V_44 * V_44 )
{
static struct V_164 V_165 = {
. V_166 = F_50 ,
. V_167 = F_56 ,
. V_141 = F_57 ,
. V_168 = F_58 ,
} ;
struct V_32 * V_169 ;
int V_17 ;
V_17 = F_64 ( V_44 , & V_165 ) ;
if ( V_17 )
return V_17 ;
V_169 = V_44 -> V_48 ;
V_169 -> V_37 = V_163 -> V_170 ;
return 0 ;
}
static int F_65 ( struct V_32 * V_33 , void * V_42 )
{
struct V_35 * V_36 = V_33 -> V_37 ;
struct V_38 * V_39 ;
struct V_171 V_172 ;
T_7 V_173 ;
unsigned int V_174 ;
unsigned int V_175 ;
int V_16 ;
if ( V_176 ) {
F_16 ( V_33 , L_36 ,
V_177 ) ;
return 0 ;
}
F_15 (svcpt, i, svc) {
V_174 = F_66 ( & V_39 -> V_178 ) ;
V_175 = V_39 -> V_178 . V_179 ;
V_173 = V_39 -> V_178 . V_180 ;
F_67 ( & V_172 , F_68 () - V_173 ) ;
F_16 ( V_33 , L_37
V_181 L_38 , L_39 ,
V_174 , V_175 , ( V_156 ) V_173 , F_69 ( & V_172 ) ) ;
F_70 ( V_33 , & V_39 -> V_178 ) ;
}
return 0 ;
}
static T_2 F_71 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
char * V_62 )
{
struct V_35 * V_36 = F_24 ( V_59 , struct V_35 ,
V_63 ) ;
return sprintf ( V_62 , L_13 , V_36 -> V_182 ) ;
}
static T_2 F_72 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
const char * V_45 ,
T_4 V_46 )
{
struct V_35 * V_36 = F_24 ( V_59 , struct V_35 ,
V_63 ) ;
int V_17 ;
int V_50 ;
V_17 = F_73 ( V_45 , 10 , & V_50 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_50 < 0 )
return - V_51 ;
F_20 ( & V_36 -> V_56 ) ;
V_36 -> V_182 = V_50 ;
F_22 ( & V_36 -> V_56 ) ;
return V_46 ;
}
static void F_74 ( struct V_58 * V_59 )
{
struct V_35 * V_36 = F_24 ( V_59 , struct V_35 ,
V_63 ) ;
F_75 ( & V_36 -> V_183 ) ;
}
void F_76 ( struct V_35 * V_36 )
{
if ( V_36 -> V_63 . V_184 ) {
F_77 ( & V_36 -> V_63 ) ;
F_78 ( & V_36 -> V_183 ) ;
}
}
int F_79 ( struct V_184 * V_185 ,
struct V_35 * V_36 )
{
int V_17 ;
V_36 -> V_63 . V_184 = V_185 ;
F_80 ( & V_36 -> V_183 ) ;
V_17 = F_81 ( & V_36 -> V_63 , & V_186 , NULL ,
L_40 , V_36 -> V_137 ) ;
return V_17 ;
}
void F_82 ( struct V_7 * V_187 ,
struct V_35 * V_36 )
{
struct V_188 V_189 [] = {
{ . V_10 = L_41 ,
. V_190 = & V_191 ,
. V_192 = V_36 } ,
{ . V_10 = L_42 ,
. V_190 = & V_193 ,
. V_192 = V_36 } ,
{ . V_10 = L_43 ,
. V_190 = & V_194 ,
. V_192 = V_36 } ,
{ . V_10 = L_44 ,
. V_190 = & V_195 ,
. V_192 = V_36 } ,
{ NULL }
} ;
static const struct V_196 V_197 = {
. V_198 = V_199 ,
. V_200 = F_63 ,
. V_201 = V_202 ,
. V_203 = V_204 ,
. V_205 = V_206 ,
} ;
int V_17 ;
F_6 ( V_187 , V_36 -> V_137 ,
L_45 , & V_36 -> V_207 ,
& V_36 -> V_208 ) ;
if ( V_36 -> V_207 == NULL )
return;
F_83 ( V_36 -> V_207 , V_189 , NULL ) ;
V_17 = F_84 ( V_36 -> V_207 , L_46 ,
0400 , & V_197 , V_36 ) ;
if ( V_17 )
F_51 ( L_47 ) ;
}
void F_85 ( struct V_209 * V_210 )
{
F_6 ( V_210 -> V_211 , NULL , L_45 ,
& V_210 -> V_212 ,
& V_210 -> V_213 ) ;
}
void F_86 ( struct V_130 * V_131 , long V_214 )
{
struct V_12 * V_15 ;
T_1 V_215 = F_87 ( V_131 -> V_216 ) ;
int V_217 = F_2 ( V_215 ) ;
V_15 = V_131 -> V_218 -> V_219 -> V_213 ;
if ( V_15 == NULL || V_217 <= 0 )
return;
F_5 ( V_217 < V_3 ) ;
if ( ! ( V_215 == V_220 || V_215 == V_221 ) )
F_88 ( V_15 , V_217 + V_21 , V_214 ) ;
}
void F_89 ( struct V_130 * V_131 , int V_222 )
{
struct V_12 * V_15 ;
int V_223 ;
if ( ! V_131 -> V_218 )
return;
V_15 = V_131 -> V_218 -> V_219 -> V_213 ;
if ( ! V_15 )
return;
V_223 = F_87 ( V_131 -> V_216 ) ;
switch ( V_223 ) {
case V_224 :
V_223 = V_30 + V_31 ;
break;
case V_225 :
V_223 = V_29 + V_31 ;
break;
default:
F_3 ( 0 , L_48 , V_223 ) ;
break;
}
F_88 ( V_15 , V_223 , V_222 ) ;
}
void F_90 ( struct V_35 * V_36 )
{
if ( V_36 -> V_207 != NULL )
F_13 ( & V_36 -> V_207 ) ;
if ( V_36 -> V_208 )
F_10 ( & V_36 -> V_208 ) ;
}
void F_91 ( struct V_209 * V_226 )
{
if ( ! F_92 ( V_226 -> V_212 ) )
F_13 ( & V_226 -> V_212 ) ;
if ( V_226 -> V_213 )
F_10 ( & V_226 -> V_213 ) ;
}
int F_93 ( struct V_44 * V_44 , const char T_3 * V_45 ,
T_4 V_46 , T_5 * V_47 )
{
struct V_209 * V_226 = ( (struct V_32 * ) V_44 -> V_48 ) -> V_37 ;
struct V_130 * V_131 ;
int V_17 ;
V_17 = F_94 ( V_226 ) ;
if ( V_17 )
return V_17 ;
V_131 = F_95 ( V_226 -> V_227 . V_228 . V_229 ) ;
F_96 ( V_226 ) ;
if ( V_131 == NULL )
return - V_107 ;
V_131 -> V_230 = V_231 ;
V_17 = F_97 ( V_131 ) ;
F_98 ( V_131 ) ;
if ( V_17 >= 0 )
return V_46 ;
return V_17 ;
}
int F_99 ( struct V_44 * V_44 , const char T_3 * V_45 ,
T_4 V_46 , T_5 * V_47 )
{
struct V_209 * V_226 = ( (struct V_32 * ) V_44 -> V_48 ) -> V_37 ;
struct V_232 * V_233 = V_226 -> V_227 . V_228 . V_229 ;
char * V_234 = NULL ;
char * V_235 ;
char * V_236 ;
int V_237 = 1 ;
const char V_238 [] = L_49 ;
const int V_239 = sizeof( V_238 ) - 1 ;
if ( V_46 > V_53 - 1 || V_46 <= V_239 )
return - V_117 ;
V_234 = F_43 ( V_46 + 1 , V_106 ) ;
if ( ! V_234 )
return - V_107 ;
if ( F_44 ( V_234 , V_45 , V_46 ) ) {
V_46 = - V_118 ;
goto V_119;
}
V_234 [ V_46 ] = 0 ;
if ( strncmp ( V_238 , V_234 , V_239 ) != 0 ) {
V_46 = - V_117 ;
goto V_119;
}
V_235 = V_234 + V_239 ;
V_236 = strstr ( V_235 , L_50 ) ;
if ( V_236 ) {
T_1 V_240 ;
char * V_241 ;
* V_236 = 0 ;
V_237 = 0 ;
V_236 += strlen ( L_50 ) ;
V_240 = F_100 ( V_236 , & V_241 , 10 ) ;
if ( * V_241 ) {
F_101 ( L_51 , V_236 ) ;
} else if ( V_240 != V_233 -> V_242 . V_243 ) {
F_102 ( V_244 , L_52 ,
V_233 -> V_219 -> V_245 ,
V_233 -> V_242 . V_243 , V_240 ) ;
V_237 = 1 ;
} else {
F_102 ( V_244 , L_53 ,
V_233 -> V_219 -> V_245 , V_240 ) ;
}
}
if ( V_237 )
F_103 ( V_233 , V_235 , 1 ) ;
V_119:
F_40 ( V_234 ) ;
return V_46 ;
}
int F_104 ( struct V_32 * V_33 , void * V_42 )
{
struct V_209 * V_226 = V_33 -> V_37 ;
struct V_232 * V_233 = V_226 -> V_227 . V_228 . V_229 ;
int V_17 ;
V_17 = F_94 ( V_226 ) ;
if ( V_17 )
return V_17 ;
F_16 ( V_33 , L_13 , ! V_233 -> V_246 ) ;
F_96 ( V_226 ) ;
return 0 ;
}
int F_105 ( struct V_44 * V_44 , const char T_3 * V_45 ,
T_4 V_46 , T_5 * V_47 )
{
struct V_209 * V_226 = ( (struct V_32 * ) V_44 -> V_48 ) -> V_37 ;
struct V_247 * V_228 = & V_226 -> V_227 . V_228 ;
struct V_232 * V_233 = V_228 -> V_229 ;
int V_17 , V_50 ;
V_17 = F_19 ( V_45 , V_46 , & V_50 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_50 != 0 && V_50 != 1 )
return - V_51 ;
V_17 = F_94 ( V_226 ) ;
if ( V_17 )
return V_17 ;
F_20 ( & V_233 -> V_248 ) ;
V_233 -> V_246 = ! V_50 ;
F_22 ( & V_233 -> V_248 ) ;
F_96 ( V_226 ) ;
return V_46 ;
}

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
const char * F_4 ( T_1 V_1 )
{
F_5 ( V_6 [ V_1 ] . V_1 == V_1 ) ;
return V_6 [ V_1 ] . V_5 ;
}
void F_6 ( struct V_7 * V_8 , char * V_9 ,
char * V_10 , struct V_7 * * V_11 ,
struct V_12 * * V_13 )
{
struct V_7 * V_14 ;
struct V_12 * V_15 ;
int V_16 , V_17 ;
unsigned int V_18 = V_19 |
V_20 ;
F_5 ( * V_11 == NULL ) ;
F_5 ( * V_13 == NULL ) ;
V_15 = F_7 ( V_21 + V_3 , 0 ) ;
if ( V_15 == NULL )
return;
if ( V_9 ) {
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
switch( V_16 ) {
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
if ( V_9 )
F_13 ( & V_14 ) ;
F_10 ( & V_15 ) ;
} else {
if ( V_9 )
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
return F_16 ( V_33 , L_13 , V_40 ) ;
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
return F_16 ( V_33 , L_13 , V_40 ) ;
}
static T_2
F_18 ( struct V_44 * V_44 , const char * V_45 ,
T_3 V_46 , T_4 * V_47 )
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
static int
F_23 ( struct V_32 * V_33 , void * V_42 )
{
struct V_35 * V_36 = V_33 -> V_37 ;
return F_16 ( V_33 , L_13 ,
V_36 -> V_58 * V_36 -> V_57 ) ;
}
static T_2
F_24 ( struct V_44 * V_44 , const char * V_45 ,
T_3 V_46 , T_4 * V_47 )
{
struct V_35 * V_36 = ( (struct V_32 * ) V_44 -> V_48 ) -> V_37 ;
int V_50 ;
int V_17 = F_19 ( V_45 , V_46 , & V_50 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_50 / V_36 -> V_57 < V_59 )
return - V_51 ;
F_20 ( & V_36 -> V_56 ) ;
if ( V_50 > V_36 -> V_60 * V_36 -> V_57 ) {
F_22 ( & V_36 -> V_56 ) ;
return - V_51 ;
}
V_36 -> V_58 = V_50 / V_36 -> V_57 ;
F_22 ( & V_36 -> V_56 ) ;
return V_46 ;
}
static int
F_25 ( struct V_32 * V_33 , void * V_42 )
{
struct V_35 * V_36 = V_33 -> V_37 ;
struct V_38 * V_39 ;
int V_40 = 0 ;
int V_16 ;
F_15 (svcpt, i, svc)
V_40 += V_39 -> V_61 ;
return F_16 ( V_33 , L_13 , V_40 ) ;
}
static int
F_26 ( struct V_32 * V_33 , void * V_42 )
{
struct V_35 * V_36 = V_33 -> V_37 ;
return F_16 ( V_33 , L_13 ,
V_36 -> V_60 * V_36 -> V_57 ) ;
}
static T_2
F_27 ( struct V_44 * V_44 , const char * V_45 ,
T_3 V_46 , T_4 * V_47 )
{
struct V_35 * V_36 = ( (struct V_32 * ) V_44 -> V_48 ) -> V_37 ;
int V_50 ;
int V_17 = F_19 ( V_45 , V_46 , & V_50 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_50 / V_36 -> V_57 < V_59 )
return - V_51 ;
F_20 ( & V_36 -> V_56 ) ;
if ( V_50 < V_36 -> V_58 * V_36 -> V_57 ) {
F_22 ( & V_36 -> V_56 ) ;
return - V_51 ;
}
V_36 -> V_60 = V_50 / V_36 -> V_57 ;
F_22 ( & V_36 -> V_56 ) ;
return V_46 ;
}
static const char * F_28 ( enum V_62 V_63 )
{
switch ( V_63 ) {
default:
F_29 () ;
case V_64 :
return L_14 ;
case V_65 :
return L_15 ;
case V_66 :
return L_16 ;
case V_67 :
return L_17 ;
case V_68 :
return L_18 ;
}
}
void F_30 ( struct V_69 * V_70 ,
struct V_71 * V_72 )
{
F_5 ( V_70 != NULL ) ;
F_5 ( V_72 != NULL ) ;
F_5 ( F_31 ( & V_70 -> V_73 -> V_74 ) ) ;
memcpy ( V_72 -> V_75 , V_70 -> V_76 -> V_77 , V_78 ) ;
V_72 -> V_79 = ! ! ( V_70 -> V_80 & V_81 ) ;
V_72 -> V_82 = V_70 -> V_83 ;
V_72 -> V_84 = V_70 -> V_85 ;
V_72 -> V_86 = V_70 -> V_87 ;
}
static int F_32 ( struct V_32 * V_33 , void * V_42 )
{
struct V_35 * V_36 = V_33 -> V_37 ;
struct V_38 * V_39 ;
struct V_88 * V_89 ;
struct V_69 * V_70 ;
struct V_71 * V_90 ;
struct V_71 V_91 ;
unsigned V_92 ;
unsigned V_93 = 0 ;
bool V_94 = false ;
int V_16 ;
int V_17 = 0 ;
F_33 ( & V_95 . V_96 ) ;
V_89 = F_34 ( V_36 -> V_97 [ 0 ] , false ) ;
F_20 ( & V_89 -> V_74 ) ;
V_92 = V_36 -> V_97 [ 0 ] -> V_98 . V_99 ;
F_22 ( & V_89 -> V_74 ) ;
F_35 ( V_90 , V_92 * sizeof( * V_90 ) ) ;
if ( V_90 == NULL )
GOTO ( V_100 , V_17 = - V_101 ) ;
V_102:
F_15 (svcpt, i, svc) {
V_89 = F_34 ( V_39 , V_94 ) ;
F_20 ( & V_89 -> V_74 ) ;
V_93 = 0 ;
F_36 (policy, &nrs->nrs_policy_list,
pol_list) {
F_5 ( V_93 < V_92 ) ;
F_30 ( V_70 , & V_91 ) ;
if ( V_16 == 0 ) {
memcpy ( V_90 [ V_93 ] . V_75 , V_91 . V_75 ,
V_78 ) ;
memcpy ( & V_90 [ V_93 ] . V_82 , & V_91 . V_82 ,
sizeof( V_91 . V_82 ) ) ;
V_90 [ V_93 ] . V_79 = V_91 . V_79 ;
} else {
F_5 ( strncmp ( V_90 [ V_93 ] . V_75 ,
V_91 . V_75 ,
V_78 ) == 0 ) ;
F_5 ( V_90 [ V_93 ] . V_79 ==
V_91 . V_79 ) ;
}
V_90 [ V_93 ] . V_84 += V_91 . V_84 ;
V_90 [ V_93 ] . V_86 += V_91 . V_86 ;
V_93 ++ ;
}
F_22 ( & V_89 -> V_74 ) ;
}
F_16 ( V_33 , L_19 ,
! V_94 ? L_20 : L_21 ) ;
for ( V_93 = 0 ; V_93 < V_92 ; V_93 ++ ) {
F_16 ( V_33 , L_22
L_23
L_24
L_25
L_26 ,
V_90 [ V_93 ] . V_75 ,
F_28 ( V_90 [ V_93 ] . V_82 ) ,
V_90 [ V_93 ] . V_79 ? L_27 : L_28 ,
( int ) V_90 [ V_93 ] . V_84 ,
( int ) V_90 [ V_93 ] . V_86 ) ;
}
if ( ! V_94 && F_37 ( V_36 ) ) {
memset ( V_90 , 0 , V_92 * sizeof( * V_90 ) ) ;
V_94 = true ;
goto V_102;
}
V_100:
if ( V_90 )
F_38 ( V_90 , V_92 * sizeof( * V_90 ) ) ;
F_39 ( & V_95 . V_96 ) ;
return V_17 ;
}
static T_2 F_40 ( struct V_44 * V_44 , const char * V_45 ,
T_3 V_46 , T_4 * V_47 )
{
struct V_35 * V_36 = ( (struct V_32 * ) V_44 -> V_48 ) -> V_37 ;
enum V_103 V_104 = V_105 ;
char * V_106 ;
char * V_107 = NULL ;
char * V_108 ;
int V_17 = 0 ;
if ( V_46 >= V_109 )
GOTO ( V_100 , V_17 = - V_110 ) ;
F_35 ( V_106 , V_109 ) ;
if ( V_106 == NULL )
GOTO ( V_100 , V_17 = - V_101 ) ;
V_107 = V_106 ;
if ( F_41 ( V_106 , V_45 , V_46 ) )
GOTO ( V_100 , V_17 = - V_111 ) ;
V_106 [ V_46 ] = '\0' ;
V_108 = F_42 ( & V_106 , L_29 ) ;
if ( strlen ( V_108 ) > V_78 - 1 )
GOTO ( V_100 , V_17 = - V_110 ) ;
if ( V_106 == NULL )
goto V_112;
if ( strcmp ( V_106 , L_30 ) == 0 )
V_104 = V_113 ;
else if ( strcmp ( V_106 , L_31 ) == 0 )
V_104 = V_114 ;
else
GOTO ( V_100 , V_17 = - V_110 ) ;
V_112:
if ( V_104 == V_114 && ! F_37 ( V_36 ) )
GOTO ( V_100 , V_17 = - V_115 ) ;
else if ( V_104 == V_105 && ! F_37 ( V_36 ) )
V_104 = V_113 ;
F_33 ( & V_95 . V_96 ) ;
V_17 = F_43 ( V_36 , V_104 , V_108 , V_116 ,
false , NULL ) ;
F_39 ( & V_95 . V_96 ) ;
V_100:
if ( V_107 )
F_38 ( V_107 , V_109 ) ;
return V_17 < 0 ? V_17 : V_46 ;
}
int
F_44 ( struct V_38 * V_39 ,
struct V_117 * V_118 ,
T_5 V_119 )
{
struct V_120 * V_121 ;
struct V_122 * V_123 ;
if ( V_118 -> V_124 != NULL &&
V_118 -> V_125 > V_39 -> V_126 &&
V_118 -> V_125 <= V_119 ) {
F_3 ( V_118 -> V_125 == V_118 -> V_124 -> V_127 ,
L_32 V_128 L_33 V_128 L_34 ,
V_39 -> V_129 -> V_130 , V_39 -> V_131 ,
V_118 -> V_125 , V_118 -> V_124 -> V_127 ) ;
F_3 ( ! F_45 ( & V_39 -> V_132 ) ,
L_35 V_128 L_33 V_128 L_36
L_37 V_128 L_34 ,
V_39 -> V_129 -> V_130 , V_39 -> V_131 ,
V_119 , V_118 -> V_125 , V_39 -> V_126 ) ;
V_121 = & V_118 -> V_124 -> V_133 ;
} else {
V_121 = V_39 -> V_132 . V_134 ;
}
while ( V_121 != & V_39 -> V_132 ) {
V_123 = F_46 ( V_121 , struct V_122 , V_133 ) ;
if ( V_123 -> V_127 >= V_119 ) {
V_118 -> V_125 = V_123 -> V_127 ;
V_118 -> V_124 = V_123 ;
return 0 ;
}
V_121 = V_121 -> V_134 ;
}
return - V_135 ;
}
static void *
F_47 ( struct V_32 * V_136 , T_4 * V_137 )
{
struct V_35 * V_36 = V_136 -> V_37 ;
struct V_38 * V_39 ;
struct V_117 * V_118 ;
unsigned int V_138 ;
int V_17 ;
int V_16 ;
if ( sizeof( T_4 ) != sizeof( T_5 ) ) {
F_48 ( L_38
L_39 , ( int ) sizeof( T_4 ) ) ;
return NULL ;
}
F_35 ( V_118 , sizeof( * V_118 ) ) ;
if ( V_118 == NULL )
return NULL ;
V_118 -> V_125 = 0 ;
V_118 -> V_124 = NULL ;
V_138 = F_49 ( V_36 , * V_137 ) ;
F_15 (svcpt, i, svc) {
if ( V_16 < V_138 )
continue;
if ( V_16 > V_138 )
* V_137 = F_50 ( V_36 , V_16 ) ;
F_20 ( & V_39 -> V_139 ) ;
V_17 = F_44 ( V_39 , V_118 ,
F_51 ( V_36 , * V_137 ) ) ;
F_22 ( & V_39 -> V_139 ) ;
if ( V_17 == 0 ) {
* V_137 = F_52 ( V_36 , V_118 -> V_125 ) ;
V_118 -> V_140 = V_16 ;
return V_118 ;
}
}
F_38 ( V_118 , sizeof( * V_118 ) ) ;
return NULL ;
}
static void
F_53 ( struct V_32 * V_136 , void * V_141 )
{
struct V_117 * V_118 = V_141 ;
if ( V_118 != NULL )
F_38 ( V_118 , sizeof( * V_118 ) ) ;
}
static void *
F_54 ( struct V_32 * V_136 ,
void * V_141 , T_4 * V_137 )
{
struct V_35 * V_36 = V_136 -> V_37 ;
struct V_117 * V_118 = V_141 ;
struct V_38 * V_39 ;
T_5 V_119 ;
int V_17 ;
int V_16 ;
for ( V_16 = V_118 -> V_140 ; V_16 < V_36 -> V_57 ; V_16 ++ ) {
V_39 = V_36 -> V_97 [ V_16 ] ;
if ( V_16 > V_118 -> V_140 ) {
V_118 -> V_124 = NULL ;
V_119 = V_118 -> V_125 = 0 ;
} else {
V_119 = V_118 -> V_125 + ( 1 << V_36 -> V_142 ) ;
}
F_20 ( & V_39 -> V_139 ) ;
V_17 = F_44 ( V_39 , V_118 , V_119 ) ;
F_22 ( & V_39 -> V_139 ) ;
if ( V_17 == 0 ) {
* V_137 = F_52 ( V_36 , V_118 -> V_125 ) ;
V_118 -> V_140 = V_16 ;
return V_118 ;
}
}
F_38 ( V_118 , sizeof( * V_118 ) ) ;
return NULL ;
}
void F_55 ( void * V_32 , struct V_122 * V_123 )
{
struct V_32 * V_143 = V_32 ;
switch ( V_123 -> V_144 ) {
case V_145 :
F_16 ( V_143 , L_40 ) ;
break;
case V_146 :
case V_147 :
F_16 ( V_143 , L_41 , F_56 ( V_123 -> V_148 ) ) ;
break;
default:
F_57 ( V_149 , V_123 , L_42 , V_123 -> V_144 ) ;
}
}
static int F_58 ( struct V_32 * V_136 , void * V_141 )
{
struct V_35 * V_36 = V_136 -> V_37 ;
struct V_117 * V_118 = V_141 ;
struct V_38 * V_39 ;
struct V_122 * V_123 ;
int V_17 ;
F_5 ( V_118 -> V_140 < V_36 -> V_57 ) ;
V_39 = V_36 -> V_97 [ V_118 -> V_140 ] ;
F_20 ( & V_39 -> V_139 ) ;
V_17 = F_44 ( V_39 , V_118 , V_118 -> V_125 ) ;
if ( V_17 == 0 ) {
V_123 = V_118 -> V_124 ;
F_16 ( V_136 , V_150 L_43 V_128 L_44 ,
V_123 -> V_127 , F_59 ( V_123 -> V_151 ) ,
F_60 ( V_123 -> V_152 ) , V_123 -> V_153 ,
V_123 -> V_154 , F_61 ( V_123 ) ,
V_123 -> V_155 . V_156 ,
V_123 -> V_157 - V_123 -> V_155 . V_156 ,
V_123 -> V_157 - V_123 -> V_158 ) ;
if ( V_36 -> V_159 . V_160 == NULL )
F_16 ( V_136 , L_34 ) ;
else
V_36 -> V_159 . V_160 ( V_136 , V_118 -> V_124 ) ;
}
F_22 ( & V_39 -> V_139 ) ;
return V_17 ;
}
static int
F_62 ( struct V_161 * V_161 , struct V_44 * V_44 )
{
static struct V_162 V_163 = {
. V_164 = F_47 ,
. V_165 = F_53 ,
. V_134 = F_54 ,
. V_166 = F_58 ,
} ;
struct V_32 * V_167 ;
int V_17 ;
V_17 = F_63 ( V_44 , & V_163 ) ;
if ( V_17 )
return V_17 ;
V_167 = V_44 -> V_48 ;
V_167 -> V_37 = F_64 ( V_161 ) ;
return 0 ;
}
static int F_65 ( struct V_32 * V_33 , void * V_42 )
{
struct V_35 * V_36 = V_33 -> V_37 ;
struct V_38 * V_39 ;
struct V_168 V_169 ;
T_6 V_170 ;
unsigned int V_171 ;
unsigned int V_172 ;
int V_16 ;
if ( V_173 ) {
F_16 ( V_33 , L_45 ,
V_174 ) ;
return 0 ;
}
F_15 (svcpt, i, svc) {
V_171 = F_66 ( & V_39 -> V_175 ) ;
V_172 = V_39 -> V_175 . V_176 ;
V_170 = V_39 -> V_175 . V_177 ;
F_67 ( & V_169 , F_68 () - V_170 ) ;
F_16 ( V_33 , L_46
V_178 L_47 , L_48 ,
V_171 , V_172 , V_170 , F_69 ( & V_169 ) ) ;
F_70 ( V_33 , & V_39 -> V_175 ) ;
}
return 0 ;
}
static int F_71 ( struct V_32 * V_33 , void * V_34 )
{
struct V_35 * V_36 = V_33 -> V_37 ;
return F_16 ( V_33 , L_49 , V_36 -> V_179 ) ;
}
static T_2 F_72 ( struct V_44 * V_44 ,
const char * V_45 ,
T_3 V_46 ,
T_4 * V_47 )
{
struct V_35 * V_36 = ( (struct V_32 * ) V_44 -> V_48 ) -> V_37 ;
int V_17 ;
int V_50 ;
V_17 = F_19 ( V_45 , V_46 , & V_50 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_50 < 0 )
return - V_51 ;
F_20 ( & V_36 -> V_56 ) ;
V_36 -> V_179 = V_50 ;
F_22 ( & V_36 -> V_56 ) ;
return V_46 ;
}
void F_73 ( struct V_7 * V_180 ,
struct V_35 * V_36 )
{
struct V_181 V_182 [] = {
{ . V_10 = L_50 ,
. V_183 = & V_184 ,
. V_185 = V_36 } ,
{ . V_10 = L_51 ,
. V_183 = & V_186 ,
. V_185 = V_36 } ,
{ . V_10 = L_52 ,
. V_183 = & V_187 ,
. V_185 = V_36 } ,
{ . V_10 = L_53 ,
. V_183 = & V_188 ,
. V_185 = V_36 } ,
{ . V_10 = L_54 ,
. V_183 = & V_189 ,
. V_185 = V_36 } ,
{ . V_10 = L_55 ,
. V_183 = & V_190 ,
. V_185 = V_36 } ,
{ . V_10 = L_56 ,
. V_183 = & V_191 ,
. V_185 = V_36 } ,
{ . V_10 = L_57 ,
. V_183 = & V_192 ,
. V_185 = V_36 } ,
{ NULL }
} ;
static struct V_193 V_194 = {
. V_195 = V_196 ,
. V_197 = F_62 ,
. V_198 = V_199 ,
. V_200 = V_201 ,
. V_202 = V_203 ,
} ;
int V_17 ;
F_6 ( V_180 , V_36 -> V_130 ,
L_58 , & V_36 -> V_204 ,
& V_36 -> V_205 ) ;
if ( V_36 -> V_204 == NULL )
return;
F_74 ( V_36 -> V_204 , V_182 , NULL ) ;
V_17 = F_75 ( V_36 -> V_204 , L_59 ,
0400 , & V_194 , V_36 ) ;
if ( V_17 )
F_48 ( L_60 ) ;
}
void F_76 ( struct V_206 * V_207 )
{
F_6 ( V_207 -> V_208 , NULL , L_58 ,
& V_207 -> V_209 ,
& V_207 -> V_210 ) ;
}
void F_77 ( struct V_122 * V_123 , long V_211 )
{
struct V_12 * V_15 ;
T_1 V_212 = F_56 ( V_123 -> V_148 ) ;
int V_213 = F_2 ( V_212 ) ;
V_15 = V_123 -> V_214 -> V_215 -> V_210 ;
if ( V_15 == NULL || V_213 <= 0 )
return;
F_5 ( V_213 < V_3 ) ;
if ( ! ( V_212 == V_216 || V_212 == V_217 ) )
F_78 ( V_15 , V_213 + V_21 , V_211 ) ;
}
void F_79 ( struct V_122 * V_123 , int V_218 )
{
struct V_12 * V_15 ;
int V_219 ;
if ( ! V_123 -> V_214 )
return;
V_15 = V_123 -> V_214 -> V_215 -> V_210 ;
if ( ! V_15 )
return;
V_219 = F_56 ( V_123 -> V_148 ) ;
switch ( V_219 ) {
case V_220 :
V_219 = V_30 + V_31 ;
break;
case V_221 :
V_219 = V_29 + V_31 ;
break;
default:
F_3 ( 0 , L_61 , V_219 ) ;
break;
}
F_78 ( V_15 , V_219 , V_218 ) ;
}
void F_80 ( struct V_35 * V_36 )
{
if ( V_36 -> V_204 != NULL )
F_13 ( & V_36 -> V_204 ) ;
if ( V_36 -> V_205 )
F_10 ( & V_36 -> V_205 ) ;
}
void F_81 ( struct V_206 * V_222 )
{
if ( V_222 -> V_209 )
F_13 ( & V_222 -> V_209 ) ;
if ( V_222 -> V_210 )
F_10 ( & V_222 -> V_210 ) ;
}
int F_82 ( struct V_44 * V_44 , const char * V_45 ,
T_3 V_46 , T_4 * V_47 )
{
struct V_206 * V_222 = ( (struct V_32 * ) V_44 -> V_48 ) -> V_37 ;
char * V_223 ;
char * V_224 ;
F_35 ( V_223 , V_225 ) ;
if ( V_223 == NULL )
return - V_101 ;
if ( F_41 ( V_223 , V_45 ,
F_83 (unsigned long, BUFLEN - 1 , count) ) ) {
V_46 = - V_111 ;
goto V_100;
}
V_224 = F_84 ( V_223 , F_83 (unsigned long, BUFLEN - 1 , count) ) ;
F_85 ( V_222 , V_226 , V_227 ) ;
if ( strncmp ( V_224 , L_62 , 4 ) == 0 )
F_86 ( V_222 , V_224 + 4 ) ;
else if ( strncmp ( V_224 , L_63 , 5 ) == 0 )
F_87 ( V_222 , V_224 + 5 ) ;
else
F_87 ( V_222 , V_224 ) ;
F_88 ( V_222 , V_226 , V_227 ) ;
V_100:
F_38 ( V_223 , V_225 ) ;
return V_46 ;
}
int F_89 ( struct V_44 * V_44 , const char * V_45 ,
T_3 V_46 , T_4 * V_47 )
{
struct V_206 * V_222 = ( (struct V_32 * ) V_44 -> V_48 ) -> V_37 ;
struct V_122 * V_123 ;
int V_17 ;
F_90 ( V_222 ) ;
V_123 = F_91 ( V_222 -> V_228 . V_229 . V_230 ) ;
F_92 ( V_222 ) ;
if ( V_123 == NULL )
return - V_101 ;
V_123 -> V_231 = V_232 ;
V_17 = F_93 ( V_123 ) ;
F_94 ( V_123 ) ;
if ( V_17 >= 0 )
return V_46 ;
return V_17 ;
}
int F_95 ( struct V_44 * V_44 , const char * V_45 ,
T_3 V_46 , T_4 * V_47 )
{
struct V_206 * V_222 = ( (struct V_32 * ) V_44 -> V_48 ) -> V_37 ;
struct V_233 * V_234 = V_222 -> V_228 . V_229 . V_230 ;
char * V_223 = NULL ;
char * V_235 ;
char * V_236 ;
int V_237 = 1 ;
const char V_238 [] = L_64 ;
const int V_239 = sizeof( V_238 ) - 1 ;
if ( V_46 > V_53 - 1 || V_46 <= V_239 )
return - V_110 ;
F_35 ( V_223 , V_46 + 1 ) ;
if ( V_223 == NULL )
return - V_101 ;
if ( F_41 ( V_223 , V_45 , V_46 ) )
GOTO ( V_100 , V_46 = - V_111 ) ;
V_223 [ V_46 ] = 0 ;
if ( strncmp ( V_238 , V_223 , V_239 ) != 0 )
GOTO ( V_100 , V_46 = - V_110 ) ;
V_235 = V_223 + V_239 ;
V_236 = strstr ( V_235 , L_65 ) ;
if ( V_236 ) {
T_1 V_240 ;
char * V_241 ;
* V_236 = 0 ;
V_237 = 0 ;
V_236 += strlen ( L_65 ) ;
V_240 = F_96 ( V_236 , & V_241 , 10 ) ;
if ( * V_241 ) {
F_97 ( L_66 , V_236 ) ;
} else if ( V_240 != V_234 -> V_242 . V_243 ) {
F_98 ( V_244 , L_67
L_68 ,
V_234 -> V_215 -> V_245 ,
V_234 -> V_242 . V_243 , V_240 ) ;
V_237 = 1 ;
} else {
F_98 ( V_244 , L_69
L_70 ,
V_234 -> V_215 -> V_245 , V_240 ) ;
}
}
if ( V_237 )
F_99 ( V_234 , V_235 , 1 ) ;
V_100:
F_38 ( V_223 , V_46 + 1 ) ;
return V_46 ;
}
int F_100 ( struct V_32 * V_33 , void * V_42 )
{
struct V_206 * V_222 = V_33 -> V_37 ;
struct V_233 * V_234 = V_222 -> V_228 . V_229 . V_230 ;
int V_17 ;
F_90 ( V_222 ) ;
V_17 = F_16 ( V_33 , L_13 , ! V_234 -> V_246 ) ;
F_92 ( V_222 ) ;
return V_17 ;
}
int F_101 ( struct V_44 * V_44 , const char * V_45 ,
T_3 V_46 , T_4 * V_47 )
{
struct V_206 * V_222 = ( (struct V_32 * ) V_44 -> V_48 ) -> V_37 ;
struct V_247 * V_229 = & V_222 -> V_228 . V_229 ;
struct V_233 * V_234 = V_229 -> V_230 ;
int V_17 , V_50 ;
V_17 = F_19 ( V_45 , V_46 , & V_50 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_50 != 0 && V_50 != 1 )
return - V_51 ;
F_90 ( V_222 ) ;
F_20 ( & V_234 -> V_248 ) ;
V_234 -> V_246 = ! V_50 ;
F_22 ( & V_234 -> V_248 ) ;
F_92 ( V_222 ) ;
return V_46 ;
}

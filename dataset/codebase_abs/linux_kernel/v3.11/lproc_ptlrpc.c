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
V_95 ;
F_33 ( & V_96 . V_97 ) ;
V_89 = F_34 ( V_36 -> V_98 [ 0 ] , false ) ;
F_20 ( & V_89 -> V_74 ) ;
V_92 = V_36 -> V_98 [ 0 ] -> V_99 . V_100 ;
F_22 ( & V_89 -> V_74 ) ;
F_35 ( V_90 , V_92 * sizeof( * V_90 ) ) ;
if ( V_90 == NULL )
GOTO ( V_101 , V_17 = - V_102 ) ;
V_103:
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
goto V_103;
}
V_101:
if ( V_90 )
F_38 ( V_90 , V_92 * sizeof( * V_90 ) ) ;
F_39 ( & V_96 . V_97 ) ;
RETURN ( V_17 ) ;
}
static T_2 F_40 ( struct V_44 * V_44 , const char * V_45 ,
T_3 V_46 , T_4 * V_47 )
{
struct V_35 * V_36 = ( (struct V_32 * ) V_44 -> V_48 ) -> V_37 ;
enum V_104 V_105 = V_106 ;
char * V_107 ;
char * V_108 = NULL ;
char * V_109 ;
int V_17 = 0 ;
V_95 ;
if ( V_46 >= V_110 )
GOTO ( V_101 , V_17 = - V_111 ) ;
F_35 ( V_107 , V_110 ) ;
if ( V_107 == NULL )
GOTO ( V_101 , V_17 = - V_102 ) ;
V_108 = V_107 ;
if ( F_41 ( V_107 , V_45 , V_46 ) )
GOTO ( V_101 , V_17 = - V_112 ) ;
V_107 [ V_46 ] = '\0' ;
V_109 = F_42 ( & V_107 , L_29 ) ;
if ( strlen ( V_109 ) > V_78 - 1 )
GOTO ( V_101 , V_17 = - V_111 ) ;
if ( V_107 == NULL )
goto V_113;
if ( strcmp ( V_107 , L_30 ) == 0 )
V_105 = V_114 ;
else if ( strcmp ( V_107 , L_31 ) == 0 )
V_105 = V_115 ;
else
GOTO ( V_101 , V_17 = - V_111 ) ;
V_113:
if ( V_105 == V_115 && ! F_37 ( V_36 ) )
GOTO ( V_101 , V_17 = - V_116 ) ;
else if ( V_105 == V_106 && ! F_37 ( V_36 ) )
V_105 = V_114 ;
F_33 ( & V_96 . V_97 ) ;
V_17 = F_43 ( V_36 , V_105 , V_109 , V_117 ,
false , NULL ) ;
F_39 ( & V_96 . V_97 ) ;
V_101:
if ( V_108 )
F_38 ( V_108 , V_110 ) ;
RETURN ( V_17 < 0 ? V_17 : V_46 ) ;
}
int
F_44 ( struct V_38 * V_39 ,
struct V_118 * V_119 ,
T_5 V_120 )
{
struct V_121 * V_122 ;
struct V_123 * V_124 ;
if ( V_119 -> V_125 != NULL &&
V_119 -> V_126 > V_39 -> V_127 &&
V_119 -> V_126 <= V_120 ) {
F_3 ( V_119 -> V_126 == V_119 -> V_125 -> V_128 ,
L_32 V_129 L_33 V_129 L_34 ,
V_39 -> V_130 -> V_131 , V_39 -> V_132 ,
V_119 -> V_126 , V_119 -> V_125 -> V_128 ) ;
F_3 ( ! F_45 ( & V_39 -> V_133 ) ,
L_35 V_129 L_33 V_129 L_36
L_37 V_129 L_34 ,
V_39 -> V_130 -> V_131 , V_39 -> V_132 ,
V_120 , V_119 -> V_126 , V_39 -> V_127 ) ;
V_122 = & V_119 -> V_125 -> V_134 ;
} else {
V_122 = V_39 -> V_133 . V_135 ;
}
while ( V_122 != & V_39 -> V_133 ) {
V_124 = F_46 ( V_122 , struct V_123 , V_134 ) ;
if ( V_124 -> V_128 >= V_120 ) {
V_119 -> V_126 = V_124 -> V_128 ;
V_119 -> V_125 = V_124 ;
return 0 ;
}
V_122 = V_122 -> V_135 ;
}
return - V_136 ;
}
static void *
F_47 ( struct V_32 * V_137 , T_4 * V_138 )
{
struct V_35 * V_36 = V_137 -> V_37 ;
struct V_38 * V_39 ;
struct V_118 * V_119 ;
unsigned int V_139 ;
int V_17 ;
int V_16 ;
if ( sizeof( T_4 ) != sizeof( T_5 ) ) {
F_48 ( L_38
L_39 , ( int ) sizeof( T_4 ) ) ;
return NULL ;
}
F_35 ( V_119 , sizeof( * V_119 ) ) ;
if ( V_119 == NULL )
return NULL ;
V_119 -> V_126 = 0 ;
V_119 -> V_125 = NULL ;
V_139 = F_49 ( V_36 , * V_138 ) ;
F_15 (svcpt, i, svc) {
if ( V_16 < V_139 )
continue;
if ( V_16 > V_139 )
* V_138 = F_50 ( V_36 , V_16 ) ;
F_20 ( & V_39 -> V_140 ) ;
V_17 = F_44 ( V_39 , V_119 ,
F_51 ( V_36 , * V_138 ) ) ;
F_22 ( & V_39 -> V_140 ) ;
if ( V_17 == 0 ) {
* V_138 = F_52 ( V_36 , V_119 -> V_126 ) ;
V_119 -> V_141 = V_16 ;
return V_119 ;
}
}
F_38 ( V_119 , sizeof( * V_119 ) ) ;
return NULL ;
}
static void
F_53 ( struct V_32 * V_137 , void * V_142 )
{
struct V_118 * V_119 = V_142 ;
if ( V_119 != NULL )
F_38 ( V_119 , sizeof( * V_119 ) ) ;
}
static void *
F_54 ( struct V_32 * V_137 ,
void * V_142 , T_4 * V_138 )
{
struct V_35 * V_36 = V_137 -> V_37 ;
struct V_118 * V_119 = V_142 ;
struct V_38 * V_39 ;
T_5 V_120 ;
int V_17 ;
int V_16 ;
for ( V_16 = V_119 -> V_141 ; V_16 < V_36 -> V_57 ; V_16 ++ ) {
V_39 = V_36 -> V_98 [ V_16 ] ;
if ( V_16 > V_119 -> V_141 ) {
V_119 -> V_125 = NULL ;
V_120 = V_119 -> V_126 = 0 ;
} else {
V_120 = V_119 -> V_126 + ( 1 << V_36 -> V_143 ) ;
}
F_20 ( & V_39 -> V_140 ) ;
V_17 = F_44 ( V_39 , V_119 , V_120 ) ;
F_22 ( & V_39 -> V_140 ) ;
if ( V_17 == 0 ) {
* V_138 = F_52 ( V_36 , V_119 -> V_126 ) ;
V_119 -> V_141 = V_16 ;
return V_119 ;
}
}
F_38 ( V_119 , sizeof( * V_119 ) ) ;
return NULL ;
}
void F_55 ( void * V_32 , struct V_123 * V_124 )
{
struct V_32 * V_144 = V_32 ;
switch ( V_124 -> V_145 ) {
case V_146 :
F_16 ( V_144 , L_40 ) ;
break;
case V_147 :
case V_148 :
F_16 ( V_144 , L_41 , F_56 ( V_124 -> V_149 ) ) ;
break;
default:
F_57 ( V_150 , V_124 , L_42 , V_124 -> V_145 ) ;
}
}
static int F_58 ( struct V_32 * V_137 , void * V_142 )
{
struct V_35 * V_36 = V_137 -> V_37 ;
struct V_118 * V_119 = V_142 ;
struct V_38 * V_39 ;
struct V_123 * V_124 ;
int V_17 ;
F_5 ( V_119 -> V_141 < V_36 -> V_57 ) ;
V_39 = V_36 -> V_98 [ V_119 -> V_141 ] ;
F_20 ( & V_39 -> V_140 ) ;
V_17 = F_44 ( V_39 , V_119 , V_119 -> V_126 ) ;
if ( V_17 == 0 ) {
V_124 = V_119 -> V_125 ;
F_16 ( V_137 , V_151 L_43 V_129 L_44 ,
V_124 -> V_128 , F_59 ( V_124 -> V_152 ) ,
F_60 ( V_124 -> V_153 ) , V_124 -> V_154 ,
V_124 -> V_155 , F_61 ( V_124 ) ,
V_124 -> V_156 . V_157 ,
V_124 -> V_158 - V_124 -> V_156 . V_157 ,
V_124 -> V_158 - V_124 -> V_159 ) ;
if ( V_36 -> V_160 . V_161 == NULL )
F_16 ( V_137 , L_34 ) ;
else
V_36 -> V_160 . V_161 ( V_137 , V_119 -> V_125 ) ;
}
F_22 ( & V_39 -> V_140 ) ;
return V_17 ;
}
static int
F_62 ( struct V_162 * V_162 , struct V_44 * V_44 )
{
static struct V_163 V_164 = {
. V_165 = F_47 ,
. V_166 = F_53 ,
. V_135 = F_54 ,
. V_167 = F_58 ,
} ;
struct V_32 * V_168 ;
int V_17 ;
V_17 = F_63 ( V_44 , & V_164 ) ;
if ( V_17 )
return V_17 ;
V_168 = V_44 -> V_48 ;
V_168 -> V_37 = F_64 ( V_162 ) ;
return 0 ;
}
static int F_65 ( struct V_32 * V_33 , void * V_42 )
{
struct V_35 * V_36 = V_33 -> V_37 ;
struct V_38 * V_39 ;
struct V_169 V_170 ;
T_6 V_171 ;
unsigned int V_172 ;
unsigned int V_173 ;
int V_16 ;
if ( V_174 ) {
F_16 ( V_33 , L_45 ,
V_175 ) ;
return 0 ;
}
F_15 (svcpt, i, svc) {
V_172 = F_66 ( & V_39 -> V_176 ) ;
V_173 = V_39 -> V_176 . V_177 ;
V_171 = V_39 -> V_176 . V_178 ;
F_67 ( & V_170 , F_68 () - V_171 ) ;
F_16 ( V_33 , L_46
V_179 L_47 , L_48 ,
V_172 , V_173 , V_171 , F_69 ( & V_170 ) ) ;
F_70 ( V_33 , & V_39 -> V_176 ) ;
}
return 0 ;
}
static int F_71 ( struct V_32 * V_33 , void * V_34 )
{
struct V_35 * V_36 = V_33 -> V_37 ;
return F_16 ( V_33 , L_49 , V_36 -> V_180 ) ;
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
V_36 -> V_180 = V_50 ;
F_22 ( & V_36 -> V_56 ) ;
return V_46 ;
}
void F_73 ( struct V_7 * V_181 ,
struct V_35 * V_36 )
{
struct V_182 V_183 [] = {
{ . V_10 = L_50 ,
. V_184 = & V_185 ,
. V_186 = V_36 } ,
{ . V_10 = L_51 ,
. V_184 = & V_187 ,
. V_186 = V_36 } ,
{ . V_10 = L_52 ,
. V_184 = & V_188 ,
. V_186 = V_36 } ,
{ . V_10 = L_53 ,
. V_184 = & V_189 ,
. V_186 = V_36 } ,
{ . V_10 = L_54 ,
. V_184 = & V_190 ,
. V_186 = V_36 } ,
{ . V_10 = L_55 ,
. V_184 = & V_191 ,
. V_186 = V_36 } ,
{ . V_10 = L_56 ,
. V_184 = & V_192 ,
. V_186 = V_36 } ,
{ . V_10 = L_57 ,
. V_184 = & V_193 ,
. V_186 = V_36 } ,
{ NULL }
} ;
static struct V_194 V_195 = {
. V_196 = V_197 ,
. V_198 = F_62 ,
. V_199 = V_200 ,
. V_201 = V_202 ,
. V_203 = V_204 ,
} ;
int V_17 ;
F_6 ( V_181 , V_36 -> V_131 ,
L_58 , & V_36 -> V_205 ,
& V_36 -> V_206 ) ;
if ( V_36 -> V_205 == NULL )
return;
F_74 ( V_36 -> V_205 , V_183 , NULL ) ;
V_17 = F_75 ( V_36 -> V_205 , L_59 ,
0400 , & V_195 , V_36 ) ;
if ( V_17 )
F_48 ( L_60 ) ;
}
void F_76 ( struct V_207 * V_208 )
{
F_6 ( V_208 -> V_209 , NULL , L_58 ,
& V_208 -> V_210 ,
& V_208 -> V_211 ) ;
}
void F_77 ( struct V_123 * V_124 , long V_212 )
{
struct V_12 * V_15 ;
T_1 V_213 = F_56 ( V_124 -> V_149 ) ;
int V_214 = F_2 ( V_213 ) ;
V_15 = V_124 -> V_215 -> V_216 -> V_211 ;
if ( V_15 == NULL || V_214 <= 0 )
return;
F_5 ( V_214 < V_3 ) ;
if ( ! ( V_213 == V_217 || V_213 == V_218 ) )
F_78 ( V_15 , V_214 + V_21 , V_212 ) ;
}
void F_79 ( struct V_123 * V_124 , int V_219 )
{
struct V_12 * V_15 ;
int V_220 ;
if ( ! V_124 -> V_215 )
return;
V_15 = V_124 -> V_215 -> V_216 -> V_211 ;
if ( ! V_15 )
return;
V_220 = F_56 ( V_124 -> V_149 ) ;
switch ( V_220 ) {
case V_221 :
V_220 = V_30 + V_31 ;
break;
case V_222 :
V_220 = V_29 + V_31 ;
break;
default:
F_3 ( 0 , L_61 , V_220 ) ;
break;
}
F_78 ( V_15 , V_220 , V_219 ) ;
}
void F_80 ( struct V_35 * V_36 )
{
if ( V_36 -> V_205 != NULL )
F_13 ( & V_36 -> V_205 ) ;
if ( V_36 -> V_206 )
F_10 ( & V_36 -> V_206 ) ;
}
void F_81 ( struct V_207 * V_223 )
{
if ( V_223 -> V_210 )
F_13 ( & V_223 -> V_210 ) ;
if ( V_223 -> V_211 )
F_10 ( & V_223 -> V_211 ) ;
}
int F_82 ( struct V_44 * V_44 , const char * V_45 ,
T_3 V_46 , T_4 * V_47 )
{
struct V_207 * V_223 = ( (struct V_32 * ) V_44 -> V_48 ) -> V_37 ;
char * V_224 ;
char * V_225 ;
F_35 ( V_224 , V_226 ) ;
if ( V_224 == NULL )
return - V_102 ;
if ( F_41 ( V_224 , V_45 ,
F_83 (unsigned long, BUFLEN - 1 , count) ) ) {
V_46 = - V_112 ;
goto V_101;
}
V_225 = F_84 ( V_224 , F_83 (unsigned long, BUFLEN - 1 , count) ) ;
F_85 ( V_223 , V_227 , V_228 ) ;
if ( strncmp ( V_225 , L_62 , 4 ) == 0 )
F_86 ( V_223 , V_225 + 4 ) ;
else if ( strncmp ( V_225 , L_63 , 5 ) == 0 )
F_87 ( V_223 , V_225 + 5 ) ;
else
F_87 ( V_223 , V_225 ) ;
F_88 ( V_223 , V_227 , V_228 ) ;
V_101:
F_38 ( V_224 , V_226 ) ;
return V_46 ;
}
int F_89 ( struct V_44 * V_44 , const char * V_45 ,
T_3 V_46 , T_4 * V_47 )
{
struct V_207 * V_223 = ( (struct V_32 * ) V_44 -> V_48 ) -> V_37 ;
struct V_123 * V_124 ;
int V_17 ;
V_95 ;
F_90 ( V_223 ) ;
V_124 = F_91 ( V_223 -> V_229 . V_230 . V_231 ) ;
F_92 ( V_223 ) ;
if ( V_124 == NULL )
RETURN ( - V_102 ) ;
V_124 -> V_232 = V_233 ;
V_17 = F_93 ( V_124 ) ;
F_94 ( V_124 ) ;
if ( V_17 >= 0 )
RETURN ( V_46 ) ;
RETURN ( V_17 ) ;
}
int F_95 ( struct V_44 * V_44 , const char * V_45 ,
T_3 V_46 , T_4 * V_47 )
{
struct V_207 * V_223 = ( (struct V_32 * ) V_44 -> V_48 ) -> V_37 ;
struct V_234 * V_235 = V_223 -> V_229 . V_230 . V_231 ;
char * V_224 = NULL ;
char * V_236 ;
char * V_237 ;
int V_238 = 1 ;
const char V_239 [] = L_64 ;
const int V_240 = sizeof( V_239 ) - 1 ;
if ( V_46 > V_53 - 1 || V_46 <= V_240 )
return - V_111 ;
F_35 ( V_224 , V_46 + 1 ) ;
if ( V_224 == NULL )
return - V_102 ;
if ( F_41 ( V_224 , V_45 , V_46 ) )
GOTO ( V_101 , V_46 = - V_112 ) ;
V_224 [ V_46 ] = 0 ;
if ( strncmp ( V_239 , V_224 , V_240 ) != 0 )
GOTO ( V_101 , V_46 = - V_111 ) ;
V_236 = V_224 + V_240 ;
V_237 = strstr ( V_236 , L_65 ) ;
if ( V_237 ) {
T_1 V_241 ;
char * V_242 ;
* V_237 = 0 ;
V_238 = 0 ;
V_237 += strlen ( L_65 ) ;
V_241 = F_96 ( V_237 , & V_242 , 10 ) ;
if ( * V_242 ) {
F_97 ( L_66 , V_237 ) ;
} else if ( V_241 != V_235 -> V_243 . V_244 ) {
F_98 ( V_245 , L_67
L_68 ,
V_235 -> V_216 -> V_246 ,
V_235 -> V_243 . V_244 , V_241 ) ;
V_238 = 1 ;
} else {
F_98 ( V_245 , L_69
L_70 ,
V_235 -> V_216 -> V_246 , V_241 ) ;
}
}
if ( V_238 )
F_99 ( V_235 , V_236 , 1 ) ;
V_101:
F_38 ( V_224 , V_46 + 1 ) ;
return V_46 ;
}
int F_100 ( struct V_32 * V_33 , void * V_42 )
{
struct V_207 * V_223 = V_33 -> V_37 ;
struct V_234 * V_235 = V_223 -> V_229 . V_230 . V_231 ;
int V_17 ;
F_90 ( V_223 ) ;
V_17 = F_16 ( V_33 , L_13 , ! V_235 -> V_247 ) ;
F_92 ( V_223 ) ;
return V_17 ;
}
int F_101 ( struct V_44 * V_44 , const char * V_45 ,
T_3 V_46 , T_4 * V_47 )
{
struct V_207 * V_223 = ( (struct V_32 * ) V_44 -> V_48 ) -> V_37 ;
struct V_248 * V_230 = & V_223 -> V_229 . V_230 ;
struct V_234 * V_235 = V_230 -> V_231 ;
int V_17 , V_50 ;
V_17 = F_19 ( V_45 , V_46 , & V_50 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_50 != 0 && V_50 != 1 )
return - V_51 ;
F_90 ( V_223 ) ;
F_20 ( & V_235 -> V_249 ) ;
V_235 -> V_247 = ! V_50 ;
F_22 ( & V_235 -> V_249 ) ;
F_92 ( V_223 ) ;
return V_46 ;
}

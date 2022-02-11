static int
F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
unsigned int V_3 = F_2 ( V_1 ) ;
if ( V_3 )
return - V_4 ;
V_2 -> V_5 = NULL ;
return 0 ;
}
static int
F_3 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return 0 ;
}
static void F_4 ( struct V_6 * V_7 )
{
}
static struct V_8 *
F_5 ( T_1 V_9 , T_2 V_10 , bool V_11 , bool * V_12 )
{
int V_13 = sizeof( struct V_8 ) + V_10 ;
struct V_8 * V_14 ;
if ( V_12 )
* V_12 = false ;
V_13 ++ ;
if ( ( V_15 + V_10 )
> V_16 ) {
if ( V_12 )
* V_12 = true ;
return NULL ;
}
V_14 = F_6 ( V_13 , V_17 | V_18 ) ;
if ( ! V_14 ) {
if ( V_12 )
* V_12 = true ;
return NULL ;
}
V_14 -> V_13 = V_13 ;
V_14 -> V_19 = V_10 ;
V_14 -> V_20 = NULL ;
V_14 -> V_21 = 0 ;
V_14 -> V_22 = false ;
if ( V_11 ) {
void * V_23 ;
if ( V_9 > F_7 ( V_24 - 1 ) )
goto V_25;
V_23 = F_8 ( ( unsigned long ) ( V_9 ) ) ;
memcpy ( V_14 -> V_26 , V_23 , V_10 ) ;
} else {
void * V_27 = F_9 ( V_9 , V_10 , V_28 ) ;
if ( ! V_27 )
goto V_25;
memcpy ( V_14 -> V_26 , V_27 , V_10 ) ;
F_10 ( V_27 ) ;
}
V_14 -> V_22 = true ;
V_15 += V_14 -> V_19 ;
return V_14 ;
V_25:
F_11 ( V_14 ) ;
return NULL ;
}
static T_3
F_12 ( struct V_8 * V_14 )
{
struct V_29 * V_30 = NULL ;
if ( ! V_14 )
return V_31 ;
V_30 = (struct V_29 * ) ( V_14 -> V_26 ) ;
return V_30 -> V_32 ;
}
static void
F_13 ( struct V_8 * V_14 ,
enum V_33 V_34 )
{
struct V_29 * V_30 = NULL ;
if ( ! V_14 )
return;
V_30 = (struct V_29 * ) ( V_14 -> V_26 ) ;
switch ( V_34 ) {
case V_35 :
V_14 -> V_20 = V_14 -> V_26 + V_30 -> V_36 ;
V_14 -> V_21 = V_30 -> V_37 ;
break;
case V_38 :
V_14 -> V_20 = V_14 -> V_26 + V_30 -> V_39 ;
V_14 -> V_21 = V_30 -> V_40 ;
break;
case V_41 :
V_14 -> V_20 = V_14 -> V_26 + V_30 -> V_42 ;
V_14 -> V_21 = V_30 -> V_43 ;
break;
case V_44 :
V_14 -> V_20 = V_14 -> V_26 + V_30 -> V_45 ;
V_14 -> V_21 = V_30 -> V_46 ;
break;
default:
break;
}
}
static void F_11 ( struct V_8 * V_14 )
{
if ( ! V_14 )
return;
V_15 -= V_14 -> V_19 ;
F_14 ( V_14 ) ;
}
static void *
F_15 ( struct V_8 * V_14 )
{
T_4 * V_47 ;
unsigned long V_48 ;
int V_49 = - 1 ;
void * V_50 = NULL ;
int V_51 ;
if ( ! V_14 )
return NULL ;
V_47 = V_14 -> V_20 ;
V_48 = V_14 -> V_21 ;
if ( V_48 == 0 )
return NULL ;
if ( ! V_47 )
return NULL ;
for ( V_51 = 0 , V_49 = - 1 ; V_51 < V_48 ; V_51 ++ )
if ( V_47 [ V_51 ] == '\0' ) {
V_49 = V_51 ;
break;
}
if ( V_49 < 0 )
V_49 = V_48 ;
V_50 = F_16 ( V_49 + 1 , V_17 | V_18 ) ;
if ( ! V_50 )
return NULL ;
if ( V_49 > 0 )
memcpy ( V_50 , V_47 , V_49 ) ;
( ( T_4 * ) ( V_50 ) ) [ V_49 ] = '\0' ;
return V_50 ;
}
static T_5 F_17 ( struct V_6 * V_7 ,
struct V_52 * V_53 ,
char * V_54 )
{
T_4 V_55 = 0 ;
F_18 ( V_56 ,
F_19 ( struct V_57 ,
V_55 ) , & V_55 , sizeof( T_4 ) ) ;
return F_20 ( V_54 , V_58 , L_1 , V_55 ) ;
}
static T_5 F_21 ( struct V_6 * V_7 ,
struct V_52 * V_53 ,
const char * V_54 , T_6 V_59 )
{
T_4 V_55 ;
int V_60 ;
if ( F_22 ( V_54 , 10 , & V_55 ) )
return - V_61 ;
V_60 = F_23
( V_56 ,
F_19 ( struct V_57 ,
V_55 ) ,
& V_55 , sizeof( T_4 ) ) ;
if ( V_60 )
return V_60 ;
return V_59 ;
}
static T_5 F_24 ( struct V_6 * V_7 ,
struct V_52 * V_53 ,
char * V_54 )
{
struct V_62 V_62 ;
F_18 ( V_56 ,
F_19 ( struct V_57 ,
V_63 ) , & V_62 ,
sizeof( struct V_62 ) ) ;
return F_20 ( V_54 , V_58 , L_1 ,
V_62 . V_64 ) ;
}
static T_5 F_25 ( struct V_6 * V_7 ,
struct V_52 * V_53 ,
const char * V_54 , T_6 V_59 )
{
int V_65 , V_60 ;
struct V_62 V_62 ;
if ( F_26 ( V_54 , 10 , & V_65 ) )
return - V_61 ;
V_62 . V_64 = V_65 ;
V_60 = F_23
( V_56 ,
F_19 ( struct V_57 ,
V_63 ) , & ( V_62 ) ,
sizeof( struct V_62 ) ) ;
if ( V_60 )
return V_60 ;
return V_59 ;
}
static T_5 F_27 ( struct V_6 * V_7 , struct V_52 * V_53 ,
char * V_54 )
{
T_2 error = 0 ;
F_18 ( V_56 ,
F_19 ( struct V_57 ,
V_66 ) ,
& error , sizeof( T_2 ) ) ;
return F_20 ( V_54 , V_58 , L_2 , error ) ;
}
static T_5 F_28 ( struct V_6 * V_7 , struct V_52 * V_53 ,
const char * V_54 , T_6 V_59 )
{
T_2 error ;
int V_60 ;
if ( F_29 ( V_54 , 10 , & error ) )
return - V_61 ;
V_60 = F_23
( V_56 ,
F_19 ( struct V_57 ,
V_66 ) ,
& error , sizeof( T_2 ) ) ;
if ( V_60 )
return V_60 ;
return V_59 ;
}
static T_5 F_30 ( struct V_6 * V_7 , struct V_52 * V_53 ,
char * V_54 )
{
T_2 V_67 = 0 ;
F_18
( V_56 ,
F_19 ( struct V_57 ,
V_68 ) ,
& V_67 , sizeof( T_2 ) ) ;
return F_20 ( V_54 , V_58 , L_2 , V_67 ) ;
}
static T_5 F_31 ( struct V_6 * V_7 , struct V_52 * V_53 ,
const char * V_54 , T_6 V_59 )
{
T_2 V_67 ;
int V_60 ;
if ( F_29 ( V_54 , 10 , & V_67 ) )
return - V_61 ;
V_60 = F_23
( V_56 ,
F_19 ( struct V_57 ,
V_68 ) ,
& V_67 , sizeof( T_2 ) ) ;
if ( V_60 )
return V_60 ;
return V_59 ;
}
static T_5 F_32 ( struct V_6 * V_7 ,
struct V_52 * V_53 , char * V_54 )
{
T_7 V_69 = 0 ;
F_18 ( V_56 ,
F_19 ( struct V_57 ,
V_70 ) ,
& V_69 , sizeof( T_7 ) ) ;
return F_20 ( V_54 , V_58 , L_3 , V_69 ) ;
}
static T_5 F_33 ( struct V_6 * V_7 ,
struct V_52 * V_53 ,
const char * V_54 , T_6 V_59 )
{
T_7 V_69 ;
int V_60 ;
if ( F_34 ( V_54 , 10 , & V_69 ) )
return - V_61 ;
V_60 = F_23
( V_56 ,
F_19 ( struct V_57 ,
V_70 ) ,
& V_69 , sizeof( T_7 ) ) ;
if ( V_60 )
return V_60 ;
return V_59 ;
}
static int F_35 ( struct V_6 * V_7 , void * V_26 )
{
struct V_71 * V_72 = F_36 ( V_7 ) ;
struct V_73 * V_32 = V_26 ;
T_2 V_74 = V_32 -> V_74 ;
T_2 V_75 = V_32 -> V_75 ;
if ( ( V_72 -> V_76 == V_74 ) &&
( V_72 -> V_77 == V_75 ) )
return 1 ;
return 0 ;
}
struct V_71 * F_37 ( T_2 V_74 , T_2 V_75 ,
struct V_71 * V_78 )
{
struct V_6 * V_7 ;
struct V_6 * V_79 = NULL ;
struct V_71 * V_72 = NULL ;
struct V_73 V_32 = {
. V_74 = V_74 ,
. V_75 = V_75
} ;
if ( V_78 )
V_79 = & V_78 -> V_6 ;
V_7 = F_38 ( & V_80 , V_79 , ( void * ) & V_32 ,
F_35 ) ;
if ( V_7 )
V_72 = F_36 ( V_7 ) ;
return V_72 ;
}
void
F_39 (
struct V_81 * V_82 ,
struct V_83 * V_84 ,
struct V_85 * V_86 )
{
F_40 ( & V_87 ) ;
if ( ! V_82 ) {
memset ( & V_88 , 0 ,
sizeof( V_88 ) ) ;
V_89 = 0 ;
} else {
V_88 = * V_82 ;
V_89 = 1 ;
}
if ( V_84 )
* V_84 = V_90 ;
if ( V_86 )
F_41 ( V_86 , L_4 , L_5 ,
V_91 , NULL ) ;
F_42 ( & V_87 ) ;
}
static void
F_43 ( struct V_92 * V_93 )
{
static int V_94 ;
enum V_95 V_96 = 0 ;
int V_97 = V_98 ;
F_44 ( V_99 , V_100 ) ;
if ( V_94 ) {
V_97 = - V_101 ;
goto V_102;
}
V_94 = 1 ;
F_44 ( V_103 , V_100 ) ;
V_96 =
V_93 -> V_104 . V_105 .
V_96 & V_106 ;
V_96 |= V_107 ;
V_102:
if ( V_93 -> V_108 . V_109 . V_110 )
F_45 ( & V_93 -> V_108 , V_97 , V_96 ) ;
}
static void
F_46 ( struct V_92 * V_111 ,
struct V_112 * V_113 , int V_114 )
{
memset ( V_111 , 0 , sizeof( struct V_92 ) ) ;
memcpy ( & V_111 -> V_108 , V_113 , sizeof( struct V_112 ) ) ;
V_111 -> V_108 . V_115 = 0 ;
V_111 -> V_108 . V_116 = 0 ;
V_111 -> V_108 . V_117 = 0 ;
if ( V_114 < 0 ) {
V_111 -> V_108 . V_109 . V_118 = 1 ;
V_111 -> V_108 . V_119 = ( T_2 ) ( - V_114 ) ;
}
}
static void
F_47 ( struct V_112 * V_113 , int V_114 )
{
struct V_92 V_120 ;
F_46 ( & V_120 , V_113 , V_114 ) ;
if ( V_120 . V_108 . V_109 . V_121 == 1 )
return;
if ( ! F_48 ( V_56 ,
V_122 , & V_120 ) ) {
return;
}
}
static void
F_45 ( struct V_112 * V_113 ,
int V_114 ,
enum V_95 V_96 )
{
struct V_92 V_120 ;
F_46 ( & V_120 , V_113 , V_114 ) ;
V_120 . V_104 . V_105 . V_96 = V_96 ;
if ( ! F_48 ( V_56 ,
V_122 , & V_120 ) ) {
return;
}
}
static void F_49 (
struct V_112 * V_113 , int V_114 ,
struct V_123 V_124 )
{
struct V_92 V_120 ;
F_46 ( & V_120 , V_113 , V_114 ) ;
V_120 . V_104 . V_125 . V_124 = V_124 ;
V_120 . V_104 . V_125 . V_109 . V_126 = 1 ;
if ( ! F_48 ( V_56 ,
V_122 , & V_120 ) ) {
return;
}
}
static void
F_50 ( struct V_92 * V_111 , enum V_127 V_128 )
{
T_2 V_129 ;
T_7 V_130 ;
if ( F_18 ( V_56 ,
F_19 ( struct V_57 ,
V_131 ) ,
& V_130 , sizeof( T_7 ) ) < 0 ) {
F_44 ( V_132 ,
V_133 ) ;
return;
}
if ( V_130 != V_134 ) {
F_51 ( V_135 ,
V_130 ,
V_133 ) ;
return;
}
if ( F_18 ( V_56 ,
F_19 ( struct V_57 ,
V_136 ) ,
& V_129 , sizeof( T_2 ) ) < 0 ) {
F_44 ( V_132 ,
V_133 ) ;
return;
}
if ( V_128 == V_137 ) {
if ( F_23 ( V_56 ,
V_129 ,
V_111 ,
sizeof( struct V_92 ) ) < 0 ) {
F_44 ( V_138 ,
V_133 ) ;
return;
}
} else {
V_129 += sizeof( struct V_92 ) ;
if ( F_23 ( V_56 ,
V_129 ,
V_111 ,
sizeof( struct V_92 ) ) < 0 ) {
F_44 ( V_139 ,
V_133 ) ;
return;
}
}
}
static void
F_52 ( enum V_140 V_141 ,
struct V_112 * V_142 ,
int V_114 )
{
if ( ! V_142 )
return;
if ( V_142 -> V_32 != ( T_2 ) V_141 )
return;
F_47 ( V_142 , V_114 ) ;
}
static void
F_53 ( enum V_140 V_141 ,
struct V_71 * V_23 , int V_114 ,
struct V_123 V_143 )
{
struct V_92 V_120 ;
T_2 V_74 = V_23 -> V_76 ;
T_2 V_75 = V_23 -> V_77 ;
if ( ! V_23 -> V_142 )
return;
if ( V_23 -> V_142 -> V_32 != V_141 )
return;
F_46 ( & V_120 , V_23 -> V_142 , V_114 ) ;
V_120 . V_104 . V_125 . V_74 = V_74 ;
V_120 . V_104 . V_125 . V_75 = V_75 ;
V_120 . V_104 . V_125 . V_124 = V_143 ;
if ( ! F_48 ( V_56 ,
V_122 , & V_120 ) )
return;
}
static void
F_54 ( enum V_140 V_141 ,
struct V_112 * V_142 ,
int V_114 )
{
if ( ! V_142 )
return;
if ( V_142 -> V_32 != ( T_2 ) V_141 )
return;
F_47 ( V_142 , V_114 ) ;
}
static void
F_55 ( struct V_71 * V_144 ,
T_2 V_104 , struct V_112 * V_113 ,
int V_114 , bool V_145 )
{
struct V_112 * V_146 = NULL ;
F_40 ( & V_87 ) ;
if ( ! V_144 ) {
V_146 = V_113 ;
goto V_147;
}
if ( V_144 -> V_142 ) {
V_114 = - V_148 ;
V_146 = V_144 -> V_142 ;
goto V_147;
}
if ( V_145 ) {
V_146 = F_6 ( sizeof( * V_146 ) , V_17 ) ;
if ( ! V_146 ) {
F_56 ( V_149 , V_104 ,
V_144 -> V_76 ,
V_133 ) ;
goto V_150;
}
memcpy ( V_146 , V_113 ,
sizeof( struct V_112 ) ) ;
V_144 -> V_142 = V_146 ;
}
if ( V_114 == V_98 ) {
switch ( V_104 ) {
case V_151 :
if ( V_88 . V_152 ) {
(* V_88 . V_152 ) ( V_144 ) ;
goto V_150;
}
break;
case V_153 :
if ( V_88 . V_154 ) {
(* V_88 . V_154 ) ( V_144 ) ;
goto V_150;
}
break;
}
}
V_147:
F_52 ( V_104 , V_146 , V_114 ) ;
V_150:
F_42 ( & V_87 ) ;
}
static void
F_57 ( struct V_71 * V_155 ,
struct V_123 V_124 , T_2 V_104 ,
struct V_112 * V_113 , int V_114 ,
bool V_145 , bool V_156 )
{
struct V_81 * V_82 ;
struct V_112 * V_146 = NULL ;
V_82 = & V_88 ;
F_40 ( & V_87 ) ;
if ( ! V_155 ) {
V_146 = V_113 ;
goto V_147;
}
if ( V_155 -> V_142 ) {
V_114 = - V_148 ;
V_146 = V_155 -> V_142 ;
goto V_147;
}
if ( V_145 ) {
V_146 = F_6 ( sizeof( * V_146 ) , V_17 ) ;
if ( ! V_146 ) {
V_114 = - V_157 ;
goto V_147;
}
memcpy ( V_146 , V_113 ,
sizeof( struct V_112 ) ) ;
V_155 -> V_142 = V_146 ;
}
if ( V_114 >= 0 ) {
switch ( V_104 ) {
case V_158 :
if ( V_82 -> V_159 ) {
(* V_82 -> V_159 ) ( V_155 ) ;
goto V_150;
}
break;
case V_160 :
if ( V_124 . V_161 == V_162 . V_161 &&
V_124 . V_163 ==
V_162 . V_163 ) {
if ( V_82 -> V_164 ) {
(* V_82 -> V_164 ) ( V_155 ) ;
goto V_150;
}
}
else if ( V_124 . V_161 == V_165 . V_161 &&
V_124 . V_163 ==
V_165 . V_163 ) {
if ( V_82 -> V_166 ) {
(* V_82 -> V_166 ) ( V_155 ) ;
goto V_150;
}
}
break;
case V_167 :
if ( V_82 -> V_168 ) {
(* V_82 -> V_168 ) ( V_155 ) ;
goto V_150;
}
break;
}
}
V_147:
F_54 ( V_104 , V_146 , V_114 ) ;
V_150:
F_42 ( & V_87 ) ;
}
static void
V_152 ( struct V_92 * V_93 )
{
struct V_169 * V_104 = & V_93 -> V_104 ;
T_2 V_74 = V_104 -> V_170 . V_74 ;
int V_97 = V_98 ;
struct V_71 * V_144 ;
struct V_171 * V_171 ;
V_144 = F_37 ( V_74 , V_172 , NULL ) ;
if ( V_144 && ( V_144 -> V_124 . V_173 == 1 ) ) {
F_51 ( V_174 , V_74 ,
V_133 ) ;
V_97 = - V_101 ;
goto V_175;
}
V_144 = F_6 ( sizeof( * V_144 ) , V_17 ) ;
if ( ! V_144 ) {
F_51 ( V_174 , V_74 ,
V_133 ) ;
V_97 = - V_157 ;
goto V_175;
}
F_58 ( & V_144 -> V_176 ) ;
V_144 -> V_76 = V_74 ;
V_144 -> V_77 = V_172 ;
F_51 ( V_177 , V_74 , V_100 ) ;
V_171 = F_59 ( V_104 -> V_170 . V_178 ,
V_104 -> V_170 . V_179 ,
V_17 ,
V_104 -> V_170 . V_180 ) ;
if ( ! V_171 ) {
F_51 ( V_174 , V_74 ,
V_133 ) ;
V_97 = - V_157 ;
F_14 ( V_144 ) ;
V_144 = NULL ;
goto V_175;
}
V_144 -> V_171 = V_171 ;
if ( F_60 ( V_104 -> V_170 . V_181 , V_182 ) == 0 ) {
V_183 = V_74 ;
F_50 ( V_93 , V_137 ) ;
}
F_51 ( V_184 , V_74 , V_100 ) ;
V_175:
F_55 ( V_144 , V_151 , & V_93 -> V_108 ,
V_97 , V_93 -> V_108 . V_109 . V_110 == 1 ) ;
}
static void
V_154 ( struct V_92 * V_93 )
{
struct V_169 * V_104 = & V_93 -> V_104 ;
T_2 V_74 = V_104 -> V_185 . V_74 ;
struct V_71 * V_144 ;
int V_97 = V_98 ;
V_144 = F_37 ( V_74 , V_172 , NULL ) ;
if ( ! V_144 )
V_97 = - V_186 ;
else if ( V_144 -> V_124 . V_173 == 0 )
V_97 = - V_101 ;
F_55 ( V_144 , V_153 , & V_93 -> V_108 ,
V_97 , V_93 -> V_108 . V_109 . V_110 == 1 ) ;
}
static void
F_61 ( struct V_92 * V_93 ,
struct V_8 * V_187 )
{
struct V_169 * V_104 = & V_93 -> V_104 ;
T_2 V_74 ;
struct V_71 * V_144 ;
int V_97 = V_98 ;
V_74 = V_104 -> V_188 . V_74 ;
F_51 ( V_189 , V_74 ,
V_100 ) ;
V_144 = F_37 ( V_74 , V_172 , NULL ) ;
if ( ! V_144 ) {
F_51 ( V_190 , V_74 ,
V_133 ) ;
V_97 = - V_186 ;
} else if ( V_144 -> V_124 . V_173 == 0 ) {
F_51 ( V_190 , V_74 ,
V_133 ) ;
V_97 = - V_186 ;
} else if ( V_144 -> V_142 ) {
F_51 ( V_190 , V_74 ,
V_133 ) ;
V_97 = - V_148 ;
} else {
F_62
( V_144 -> V_171 ,
V_104 -> V_188 . V_191 ) ;
V_144 -> V_192 = F_12 ( V_187 ) ;
F_13 ( V_187 , V_44 ) ;
V_144 -> V_193 = F_15 ( V_187 ) ;
F_51 ( V_194 , V_74 ,
V_100 ) ;
}
F_55 ( V_144 , V_195 , & V_93 -> V_108 ,
V_97 , V_93 -> V_108 . V_109 . V_110 == 1 ) ;
}
static void
F_63 ( struct V_92 * V_93 )
{
struct V_169 * V_104 = & V_93 -> V_104 ;
T_2 V_74 = V_104 -> V_196 . V_74 ;
T_2 V_75 = V_104 -> V_196 . V_75 ;
struct V_71 * V_155 = NULL ;
struct V_71 * V_144 ;
struct V_171 * V_171 ;
int V_97 = V_98 ;
V_144 = F_37 ( V_74 , V_172 , NULL ) ;
if ( ! V_144 ) {
F_56 ( V_197 , V_75 , V_74 ,
V_133 ) ;
V_97 = - V_186 ;
goto V_102;
}
if ( V_144 -> V_124 . V_173 == 0 ) {
F_56 ( V_197 , V_75 , V_74 ,
V_133 ) ;
V_97 = - V_186 ;
goto V_102;
}
V_155 = F_37 ( V_74 , V_75 , NULL ) ;
if ( V_155 && ( V_155 -> V_124 . V_173 == 1 ) ) {
F_56 ( V_197 , V_75 , V_74 ,
V_133 ) ;
V_97 = - V_101 ;
goto V_102;
}
V_155 = F_6 ( sizeof( * V_155 ) , V_17 ) ;
if ( ! V_155 ) {
F_56 ( V_197 , V_75 , V_74 ,
V_133 ) ;
V_97 = - V_157 ;
goto V_102;
}
V_155 -> V_76 = V_74 ;
V_155 -> V_77 = V_75 ;
V_155 -> V_198 = V_104 -> V_196 . V_199 ;
V_155 -> V_6 . V_200 = & V_144 -> V_6 ;
F_56 ( V_201 , V_75 , V_74 ,
V_100 ) ;
V_171 =
F_64 ( V_104 -> V_196 . V_178 ,
V_104 -> V_196 . V_179 ,
V_17 ,
V_104 -> V_196 . V_202 ) ;
if ( ! V_171 ) {
F_56 ( V_197 , V_75 , V_74 ,
V_133 ) ;
V_97 = - V_157 ;
F_14 ( V_155 ) ;
V_155 = NULL ;
goto V_102;
}
V_155 -> V_171 = V_171 ;
V_155 -> V_203 = V_104 -> V_196 . V_202 ;
if ( F_60 ( V_104 -> V_196 . V_202 ,
V_204 ) == 0 )
F_50 ( V_93 , V_205 ) ;
F_56 ( V_206 , V_75 , V_74 ,
V_100 ) ;
V_102:
F_57 ( V_155 , V_162 ,
V_158 , & V_93 -> V_108 , V_97 ,
V_93 -> V_108 . V_109 . V_110 == 1 , 1 ) ;
}
static void
F_65 ( struct V_92 * V_93 )
{
struct V_169 * V_104 = & V_93 -> V_104 ;
T_2 V_74 = V_104 -> V_125 . V_74 ;
T_2 V_75 = V_104 -> V_125 . V_75 ;
struct V_123 V_124 = V_104 -> V_125 . V_124 ;
struct V_71 * V_155 ;
int V_97 = V_98 ;
V_155 = F_37 ( V_74 , V_75 , NULL ) ;
if ( ! V_155 ) {
F_56 ( V_207 , V_75 , V_74 ,
V_133 ) ;
V_97 = - V_208 ;
} else if ( V_155 -> V_124 . V_173 == 0 ) {
F_56 ( V_207 , V_75 , V_74 ,
V_133 ) ;
V_97 = - V_208 ;
}
if ( ( V_97 >= V_98 ) && V_155 )
F_57 ( V_155 , V_124 ,
V_160 , & V_93 -> V_108 , V_97 ,
V_93 -> V_108 . V_109 . V_110 == 1 , 1 ) ;
}
static void
F_66 ( struct V_92 * V_93 )
{
struct V_169 * V_104 = & V_93 -> V_104 ;
T_2 V_74 = V_104 -> V_209 . V_74 ;
T_2 V_75 = V_104 -> V_209 . V_75 ;
struct V_71 * V_155 ;
int V_97 = V_98 ;
V_155 = F_37 ( V_74 , V_75 , NULL ) ;
if ( ! V_155 )
V_97 = - V_208 ;
else if ( V_155 -> V_124 . V_173 == 0 )
V_97 = - V_101 ;
if ( ( V_97 >= V_98 ) && V_155 )
F_57 ( V_155 , V_162 ,
V_167 , & V_93 -> V_108 , V_97 ,
V_93 -> V_108 . V_109 . V_110 == 1 , 1 ) ;
}
static int
F_67 ( T_1 V_210 , T_1 V_211 , T_2 V_10 ,
struct V_212 * V_213 )
{
T_4 * V_214 = NULL ;
if ( ! V_213 )
return - V_215 ;
memset ( V_213 , 0 , sizeof( struct V_212 ) ) ;
if ( ( V_211 == 0 ) || ( V_10 == 0 ) )
return - V_215 ;
V_214 = F_9 ( V_210 + V_211 , V_10 , V_28 ) ;
if ( ! V_214 )
return - V_216 ;
V_213 -> V_211 = V_211 ;
V_213 -> V_10 = V_10 ;
V_213 -> V_217 = V_214 ;
return V_98 ;
}
static void
F_68 ( struct V_212 * V_213 )
{
if ( V_213 -> V_217 ) {
F_10 ( V_213 -> V_217 ) ;
V_213 -> V_217 = NULL ;
}
memset ( V_213 , 0 , sizeof( struct V_212 ) ) ;
}
static void
F_69 ( void )
{
T_1 V_210 = F_70 ( V_56 ) ;
T_1 V_218 = 0 ;
T_2 V_115 = 0 ;
if ( F_18 ( V_56 ,
F_19 ( struct V_57 ,
V_219 ) ,
& V_218 , sizeof( V_218 ) ) < 0 ) {
F_44 ( V_220 ,
V_133 ) ;
return;
}
if ( F_18 ( V_56 ,
F_19 ( struct V_57 ,
V_221 ) ,
& V_115 , sizeof( V_115 ) ) < 0 ) {
F_44 ( V_220 ,
V_133 ) ;
return;
}
F_67 ( V_210 ,
V_218 , V_115 ,
& V_222 ) ;
}
static int
F_71 ( void )
{
F_72 ( & V_223 . V_7 . V_224 , V_225 ) ;
return V_98 ;
}
static int
F_73 ( void )
{
char V_226 [ 20 ] ;
char * V_227 [] = { V_226 , NULL } ;
sprintf ( V_226 , L_6 , 1 ) ;
F_74 ( & V_223 . V_7 . V_224 , V_228 ,
V_227 ) ;
return V_98 ;
}
static int
F_75 ( void )
{
F_72 ( & V_223 . V_7 . V_224 , V_229 ) ;
return V_98 ;
}
static void
F_76 ( struct V_112 * V_113 )
{
int V_97 = F_71 () ;
if ( V_97 != V_98 )
V_97 = - V_97 ;
if ( V_113 -> V_109 . V_110 )
F_47 ( V_113 , V_97 ) ;
}
static void
F_77 ( struct V_112 * V_113 )
{
int V_97 = F_73 () ;
if ( V_97 != V_98 )
V_97 = - V_97 ;
if ( V_113 -> V_109 . V_110 )
F_47 ( V_113 , V_97 ) ;
}
static void
F_78 ( struct V_112 * V_113 )
{
int V_97 = F_75 () ;
if ( V_97 != V_98 )
V_97 = - V_97 ;
if ( V_113 -> V_109 . V_110 )
F_47 ( V_113 , V_97 ) ;
}
static bool
F_79 ( struct V_92 * V_111 )
{
if ( F_80 ( V_56 ,
V_230 , V_111 ) ) {
if ( V_111 -> V_108 . V_109 . V_121 == 1 )
return false ;
return true ;
}
return false ;
}
static int
F_81 ( void )
{
static T_8 V_32 = F_82 ( 0 ) ;
return F_83 ( & V_32 ) ;
}
static unsigned long
F_84 ( void )
{
return V_231 + F_85 ( V_232 ) ;
}
static struct V_233 *
F_86 ( struct V_92 * V_111 )
{
struct V_233 * V_234 ;
V_234 = F_16 ( sizeof( * V_234 ) , V_17 | V_18 ) ;
if ( ! V_234 )
return NULL ;
V_234 -> V_32 = F_81 () ;
V_234 -> V_235 = F_84 () ;
V_234 -> V_111 = * V_111 ;
return V_234 ;
}
static void
F_87 ( struct V_233 * V_234 )
{
F_14 ( V_234 ) ;
}
static void
F_88 ( struct V_233 * V_234 )
{
struct V_169 * V_104 = & V_234 -> V_111 . V_104 ;
char V_236 [ 40 ] , V_237 [ 40 ] , V_238 [ 40 ] , V_239 [ 40 ] , V_240 [ 40 ] ,
V_241 [ 40 ] ;
char * V_227 [] = {
V_236 , V_237 , V_238 , V_239 , V_240 , V_241 , NULL
} ;
sprintf ( V_236 , L_7 ) ;
sprintf ( V_237 , L_8 , V_234 -> V_32 ) ;
sprintf ( V_238 , L_9 ,
V_104 -> V_125 . V_124 . V_242 ) ;
sprintf ( V_239 , L_10 ,
V_104 -> V_125 . V_74 ) ;
sprintf ( V_240 , L_11 ,
V_104 -> V_125 . V_75 >> 3 ) ;
sprintf ( V_241 , L_12 ,
V_104 -> V_125 . V_75 & 0x7 ) ;
F_74 ( & V_223 . V_7 . V_224 , V_228 ,
V_227 ) ;
}
static void
F_89 ( void )
{
struct V_243 * V_244 ;
struct V_243 * V_245 ;
F_90 ( & V_246 ) ;
F_91 (pos, tmp, &parahotplug_request_list) {
struct V_233 * V_234 =
F_92 ( V_244 , struct V_233 , V_247 ) ;
if ( ! F_93 ( V_231 , V_234 -> V_235 ) )
continue;
F_94 ( V_244 ) ;
if ( V_234 -> V_111 . V_108 . V_109 . V_110 )
F_49 (
& V_234 -> V_111 . V_108 ,
V_248 ,
V_234 -> V_111 . V_104 . V_125 . V_124 ) ;
F_87 ( V_234 ) ;
}
F_95 ( & V_246 ) ;
}
static int
F_96 ( int V_32 , T_7 V_242 )
{
struct V_243 * V_244 ;
struct V_243 * V_245 ;
F_90 ( & V_246 ) ;
F_91 (pos, tmp, &parahotplug_request_list) {
struct V_233 * V_234 =
F_92 ( V_244 , struct V_233 , V_247 ) ;
if ( V_234 -> V_32 == V_32 ) {
F_94 ( V_244 ) ;
F_95 ( & V_246 ) ;
V_234 -> V_111 . V_104 . V_125 . V_124 . V_242 = V_242 ;
if ( V_234 -> V_111 . V_108 . V_109 . V_110 )
F_49 (
& V_234 -> V_111 . V_108 , V_98 ,
V_234 -> V_111 . V_104 . V_125 . V_124 ) ;
F_87 ( V_234 ) ;
return 0 ;
}
}
F_95 ( & V_246 ) ;
return - V_61 ;
}
static void
F_97 ( struct V_92 * V_93 )
{
struct V_233 * V_234 ;
V_234 = F_86 ( V_93 ) ;
if ( ! V_234 )
return;
if ( V_93 -> V_104 . V_125 . V_124 . V_242 ) {
F_88 ( V_234 ) ;
F_49
( & V_93 -> V_108 ,
V_98 ,
V_93 -> V_104 . V_125 . V_124 ) ;
F_87 ( V_234 ) ;
} else {
F_90 ( & V_246 ) ;
F_98 ( & V_234 -> V_247 , & V_249 ) ;
F_95 ( & V_246 ) ;
F_88 ( V_234 ) ;
}
}
static bool
F_99 ( struct V_92 V_93 , T_1 V_178 )
{
struct V_169 * V_104 = & V_93 . V_104 ;
T_1 V_250 ;
T_2 V_251 ;
struct V_8 * V_187 = NULL ;
bool V_252 ;
struct V_92 V_253 ;
V_252 = ( V_93 . V_108 . V_109 . V_121 == 1 ) ;
if ( V_178 == 0 )
return true ;
V_250 = V_178 + V_93 . V_108 . V_116 ;
V_251 = V_93 . V_108 . V_115 ;
if ( V_250 && V_251 ) {
bool V_12 = false ;
V_187 =
F_5 ( V_250 , V_251 ,
V_252 , & V_12 ) ;
if ( ! V_187 && V_12 )
return false ;
}
if ( ! V_252 ) {
F_46 ( & V_253 , & V_93 . V_108 ,
V_98 ) ;
if ( V_56 )
F_48 ( V_56 ,
V_254 ,
& V_253 ) ;
}
switch ( V_93 . V_108 . V_32 ) {
case V_255 :
F_43 ( & V_93 ) ;
break;
case V_151 :
V_152 ( & V_93 ) ;
break;
case V_153 :
V_154 ( & V_93 ) ;
break;
case V_195 :
F_61 ( & V_93 , V_187 ) ;
break;
case V_158 :
F_63 ( & V_93 ) ;
break;
case V_160 :
if ( V_104 -> V_125 . V_109 . V_126 ) {
F_97 ( & V_93 ) ;
} else {
F_65 ( & V_93 ) ;
V_256 = V_93 . V_104 ;
break;
}
break;
case V_167 :
F_66 ( & V_93 ) ;
break;
case V_257 :
if ( V_93 . V_108 . V_109 . V_110 )
F_47 ( & V_93 . V_108 , V_98 ) ;
break;
case V_258 :
F_76 ( & V_93 . V_108 ) ;
break;
case V_259 :
F_77 ( & V_93 . V_108 ) ;
break;
case V_260 :
F_78 ( & V_93 . V_108 ) ;
break;
default:
if ( V_93 . V_108 . V_109 . V_110 )
F_47
( & V_93 . V_108 ,
- V_261 ) ;
break;
}
if ( V_187 ) {
F_11 ( V_187 ) ;
V_187 = NULL ;
}
return true ;
}
static inline unsigned int
F_100 ( T_1 * V_262 , T_2 * V_263 )
{
struct V_264 V_265 ;
int V_266 = V_267 ;
T_1 V_268 ;
V_268 = F_7 ( & V_265 ) ;
F_101 ( V_269 , V_268 , V_266 ) ;
if ( F_102 ( V_266 ) ) {
* V_262 = V_265 . V_270 ;
* V_263 = V_265 . V_179 ;
}
return V_266 ;
}
static T_1 F_103 ( void )
{
T_1 V_9 = 0 ;
T_2 V_271 = 0 ;
if ( ! F_102 ( F_100 ( & V_9 , & V_271 ) ) )
return 0 ;
return V_9 ;
}
static void
F_104 ( struct V_272 * V_273 )
{
struct V_92 V_93 ;
bool V_274 = false ;
bool V_275 = false ;
if ( V_276 && ! V_89 )
goto V_277;
while ( F_80 ( V_56 ,
V_278 ,
& V_93 ) )
;
if ( ! V_274 ) {
if ( V_279 ) {
V_93 = V_280 ;
V_279 = false ;
V_274 = true ;
} else {
V_274 = F_79 ( & V_93 ) ;
}
}
V_275 = false ;
while ( V_274 && ( ! V_275 ) ) {
V_281 = V_231 ;
if ( F_99 ( V_93 ,
F_70
( V_56 ) ) )
V_274 = F_79 ( & V_93 ) ;
else {
V_275 = true ;
V_280 = V_93 ;
V_279 = true ;
}
}
F_89 () ;
V_277:
if ( F_105 ( V_231 ,
V_281 + ( V_282 * V_283 ) ) ) {
if ( V_284 != V_285 )
V_284 = V_285 ;
} else {
if ( V_284 != V_286 )
V_284 = V_286 ;
}
F_106 ( & V_287 , V_284 ) ;
}
static void
F_107 ( struct V_272 * V_273 )
{
struct V_92 V_288 ;
struct V_92 V_289 ;
struct V_92 V_111 ;
T_2 V_129 ;
T_7 V_130 ;
if ( V_276 && ! V_89 ) {
V_284 = V_285 ;
F_106 ( & V_287 , V_284 ) ;
return;
}
F_44 ( V_290 , V_100 ) ;
V_111 . V_108 . V_32 = V_255 ;
V_111 . V_104 . V_105 . V_291 = 23 ;
V_111 . V_104 . V_105 . V_292 = 0 ;
F_43 ( & V_111 ) ;
if ( F_18 ( V_56 ,
F_19 ( struct V_57 ,
V_131 ) ,
& V_130 , sizeof( T_7 ) ) < 0 ) {
F_44 ( V_132 ,
V_133 ) ;
return;
}
if ( V_130 != V_134 ) {
F_51 ( V_135 ,
V_130 ,
V_133 ) ;
return;
}
if ( F_18 ( V_56 ,
F_19 ( struct V_57 ,
V_136 ) ,
& V_129 , sizeof( T_2 ) ) < 0 ) {
F_44 ( V_132 ,
V_133 ) ;
return;
}
if ( F_18 ( V_56 ,
V_129 ,
& V_288 ,
sizeof( struct V_92 ) ) < 0 ) {
F_44 ( V_293 ,
V_133 ) ;
return;
}
if ( F_18 ( V_56 ,
V_129 +
sizeof( struct V_92 ) ,
& V_289 ,
sizeof( struct V_92 ) ) < 0 ) {
F_44 ( V_294 ,
V_133 ) ;
return;
}
if ( V_288 . V_104 . V_170 . V_178 ) {
V_152 ( & V_288 ) ;
} else {
F_44 ( V_295 ,
V_133 ) ;
return;
}
if ( V_289 . V_104 . V_196 . V_178 ) {
F_63 ( & V_289 ) ;
} else {
F_44 ( V_296 ,
V_133 ) ;
return;
}
F_44 ( V_297 , V_100 ) ;
}
static void
F_108 ( struct V_71 * V_144 , int V_114 )
{
if ( V_114 >= 0 )
V_144 -> V_124 . V_173 = 1 ;
F_52 ( V_151 , V_144 -> V_142 ,
V_114 ) ;
F_14 ( V_144 -> V_142 ) ;
V_144 -> V_142 = NULL ;
}
static void
F_109 ( struct V_71 * V_144 , int V_114 )
{
F_52 ( V_153 , V_144 -> V_142 ,
V_114 ) ;
F_14 ( V_144 -> V_142 ) ;
V_144 -> V_142 = NULL ;
}
static void
F_110 ( struct V_71 * V_155 , int V_114 )
{
if ( V_114 >= 0 )
V_155 -> V_124 . V_173 = 1 ;
F_54 ( V_158 , V_155 -> V_142 ,
V_114 ) ;
F_14 ( V_155 -> V_142 ) ;
V_155 -> V_142 = NULL ;
}
static void
F_111 ( struct V_71 * V_155 , int V_114 )
{
F_54 ( V_167 , V_155 -> V_142 ,
V_114 ) ;
F_14 ( V_155 -> V_142 ) ;
V_155 -> V_142 = NULL ;
}
static void
F_112 ( struct V_71 * V_155 ,
int V_114 )
{
F_53 ( V_160 ,
V_155 , V_114 ,
V_165 ) ;
F_14 ( V_155 -> V_142 ) ;
V_155 -> V_142 = NULL ;
}
static void
F_113 ( struct V_71 * V_155 , int V_114 )
{
F_53 ( V_160 ,
V_155 , V_114 ,
V_162 ) ;
F_14 ( V_155 -> V_142 ) ;
V_155 -> V_142 = NULL ;
}
static T_5 F_114 ( struct V_6 * V_7 ,
struct V_52 * V_53 ,
const char * V_54 , T_6 V_59 )
{
unsigned int V_32 ;
if ( F_115 ( V_54 , 10 , & V_32 ) )
return - V_61 ;
F_96 ( V_32 , 0 ) ;
return V_59 ;
}
static T_5 F_116 ( struct V_6 * V_7 ,
struct V_52 * V_53 ,
const char * V_54 , T_6 V_59 )
{
unsigned int V_32 ;
if ( F_115 ( V_54 , 10 , & V_32 ) )
return - V_61 ;
F_96 ( V_32 , 1 ) ;
return V_59 ;
}
static int
F_117 ( struct V_2 * V_2 , struct V_298 * V_299 )
{
unsigned long V_268 = 0 ;
unsigned long V_211 = V_299 -> V_300 << V_301 ;
T_1 V_9 = 0 ;
if ( V_211 & ( V_58 - 1 ) )
return - V_302 ;
switch ( V_211 ) {
case V_303 :
V_299 -> V_304 |= V_305 ;
if ( ! * V_306 )
return - V_302 ;
F_18
( * V_306 ,
F_19 ( struct V_57 ,
V_307 ) ,
& V_9 , sizeof( V_9 ) ) ;
if ( ! V_9 )
return - V_302 ;
V_268 = ( unsigned long ) V_9 ;
if ( F_118 ( V_299 , V_299 -> V_308 ,
V_268 >> V_301 ,
V_299 -> V_309 - V_299 -> V_308 ,
( V_299 -> V_310 ) ) ) {
return - V_311 ;
}
break;
default:
return - V_302 ;
}
return 0 ;
}
static inline T_9 F_119 ( void )
{
T_1 V_266 = V_267 ;
T_1 V_268 = 0 ;
F_101 ( V_312 , V_268 ,
V_266 ) ;
return V_266 ;
}
static inline int F_120 ( T_1 V_313 )
{
int V_266 = V_267 ;
F_101 ( V_314 , V_313 , V_266 ) ;
return V_266 ;
}
static long F_121 ( struct V_2 * V_2 , unsigned int V_104 ,
unsigned long V_315 )
{
T_1 V_313 ;
T_9 V_316 ;
switch ( V_104 ) {
case V_312 :
V_316 = F_119 () ;
if ( F_122 ( ( void V_317 * ) V_315 , & V_316 ,
sizeof( V_316 ) ) ) {
return - V_318 ;
}
return 0 ;
case V_314 :
if ( F_123 ( & V_313 , ( void V_317 * ) V_315 ,
sizeof( V_313 ) ) ) {
return - V_318 ;
}
return F_120 ( V_313 ) ;
default:
return - V_318 ;
}
}
static int
F_124 ( T_10 V_319 , struct V_171 * * V_56 )
{
int V_97 = 0 ;
V_306 = V_56 ;
F_125 ( & V_320 , & V_321 ) ;
V_320 . V_322 = V_323 ;
if ( F_126 ( V_319 ) == 0 ) {
V_97 = F_127 ( & V_319 , 0 , 1 , L_5 ) ;
if ( V_97 < 0 )
return V_97 ;
} else {
V_97 = F_128 ( V_319 , 1 , L_5 ) ;
if ( V_97 < 0 )
return V_97 ;
}
V_97 = F_129 ( & V_320 , F_130 ( F_126 ( V_319 ) , 0 ) , 1 ) ;
if ( V_97 < 0 ) {
F_131 ( V_319 , 1 ) ;
return V_97 ;
}
return 0 ;
}
static void
F_132 ( T_10 V_319 )
{
if ( V_320 . V_324 )
F_133 ( & V_320 ) ;
V_320 . V_324 = NULL ;
F_131 ( V_319 , 1 ) ;
}
static int
F_134 ( struct V_325 * V_325 )
{
int V_326 = - V_4 ;
T_1 V_9 ;
T_3 V_327 = V_328 ;
V_9 = F_103 () ;
if ( ! V_9 )
goto error;
memset ( & V_88 , 0 , sizeof( V_88 ) ) ;
memset ( & V_222 , 0 , sizeof( V_222 ) ) ;
V_56 = F_64 ( V_9 , 0 ,
V_17 , V_327 ) ;
if ( ! V_56 )
goto error;
if ( F_135 (
F_136 ( V_56 ) ) ) {
F_69 () ;
} else {
goto V_329;
}
V_319 = F_130 ( V_330 , 0 ) ;
V_326 = F_124 ( V_319 , & V_56 ) ;
if ( V_326 < 0 )
goto V_331;
if ( F_137 () )
F_138 ( & V_287 ,
F_107 ) ;
else
F_138 ( & V_287 ,
F_104 ) ;
V_281 = V_231 ;
V_284 = V_286 ;
F_106 ( & V_287 , V_284 ) ;
V_223 . V_7 . V_332 = V_319 ;
if ( F_139 ( & V_223 ) < 0 ) {
F_44 ( V_333 , V_334 ) ;
V_326 = - V_4 ;
goto V_335;
}
F_44 ( V_336 , V_100 ) ;
V_326 = F_140 () ;
if ( V_326 < 0 )
goto V_337;
return 0 ;
V_337:
F_141 ( & V_223 ) ;
V_335:
F_142 ( & V_287 ) ;
F_132 ( V_319 ) ;
V_331:
F_68 ( & V_222 ) ;
V_329:
F_143 ( V_56 ) ;
error:
F_51 ( V_338 , V_326 , V_133 ) ;
return V_326 ;
}
static int
F_144 ( struct V_325 * V_325 )
{
F_44 ( V_339 , V_100 ) ;
F_145 () ;
F_142 ( & V_287 ) ;
F_68 ( & V_222 ) ;
F_143 ( V_56 ) ;
F_132 ( V_223 . V_7 . V_332 ) ;
F_141 ( & V_223 ) ;
F_44 ( V_339 , V_100 ) ;
return 0 ;
}
static T_11 T_12 F_146 ( void )
{
unsigned int V_340 , V_341 , V_342 , V_343 ;
if ( F_147 ( V_344 ) ) {
F_148 ( V_345 , & V_340 , & V_341 , & V_342 , & V_343 ) ;
return ( V_341 == V_346 ) &&
( V_342 == V_347 ) &&
( V_343 == V_348 ) ;
} else {
return 0 ;
}
}
static int F_149 ( void )
{
int V_266 ;
if ( ! F_146 () )
return - V_4 ;
V_266 = F_150 ( & V_349 ) ;
if ( V_266 )
return - V_4 ;
F_151 ( L_13 ) ;
return 0 ;
}
static void F_152 ( void )
{
F_153 ( & V_349 ) ;
}

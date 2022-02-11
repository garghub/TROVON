static int
F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
unsigned V_3 = F_2 ( V_1 ) ;
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
struct V_8 * V_14 = NULL ;
struct V_8 * V_15 = NULL ;
if ( V_12 )
* V_12 = false ;
V_13 ++ ;
if ( ( V_16 + V_10 )
> V_17 ) {
if ( V_12 )
* V_12 = true ;
V_14 = NULL ;
goto V_18;
}
V_15 = F_6 ( V_13 , V_19 | V_20 ) ;
if ( ! V_15 ) {
if ( V_12 )
* V_12 = true ;
V_14 = NULL ;
goto V_18;
}
V_15 -> V_13 = V_13 ;
V_15 -> V_21 = V_10 ;
V_15 -> V_22 = NULL ;
V_15 -> V_23 = 0 ;
V_15 -> V_24 = false ;
if ( V_11 ) {
void * V_25 ;
if ( V_9 > F_7 ( V_26 - 1 ) ) {
V_14 = NULL ;
goto V_18;
}
V_25 = F_8 ( ( unsigned long ) ( V_9 ) ) ;
memcpy ( V_15 -> V_27 , V_25 , V_10 ) ;
} else {
void * V_28 = F_9 ( V_9 , V_10 , V_29 ) ;
if ( ! V_28 ) {
V_14 = NULL ;
goto V_18;
}
memcpy ( V_15 -> V_27 , V_28 , V_10 ) ;
F_10 ( V_28 ) ;
}
V_15 -> V_24 = true ;
V_14 = V_15 ;
V_18:
if ( V_14 ) {
V_16 += V_15 -> V_21 ;
} else {
if ( V_15 ) {
F_11 ( V_15 ) ;
V_15 = NULL ;
}
}
return V_14 ;
}
static T_3
F_12 ( struct V_8 * V_15 )
{
struct V_30 * V_31 = NULL ;
if ( ! V_15 )
return V_32 ;
V_31 = (struct V_30 * ) ( V_15 -> V_27 ) ;
return V_31 -> V_33 ;
}
static void
F_13 ( struct V_8 * V_15 ,
enum V_34 V_35 )
{
struct V_30 * V_31 = NULL ;
if ( ! V_15 )
return;
V_31 = (struct V_30 * ) ( V_15 -> V_27 ) ;
switch ( V_35 ) {
case V_36 :
V_15 -> V_22 = V_15 -> V_27 + V_31 -> V_37 ;
V_15 -> V_23 = V_31 -> V_38 ;
break;
case V_39 :
V_15 -> V_22 = V_15 -> V_27 + V_31 -> V_40 ;
V_15 -> V_23 = V_31 -> V_41 ;
break;
case V_42 :
V_15 -> V_22 = V_15 -> V_27 + V_31 -> V_43 ;
V_15 -> V_23 = V_31 -> V_44 ;
break;
case V_45 :
V_15 -> V_22 = V_15 -> V_27 + V_31 -> V_46 ;
V_15 -> V_23 = V_31 -> V_47 ;
break;
default:
break;
}
}
static void F_11 ( struct V_8 * V_15 )
{
if ( ! V_15 )
return;
V_16 -= V_15 -> V_21 ;
F_14 ( V_15 ) ;
}
static void *
F_15 ( struct V_8 * V_15 )
{
T_4 * V_48 ;
unsigned long V_49 ;
int V_50 = - 1 ;
void * V_51 = NULL ;
int V_52 ;
if ( ! V_15 )
return NULL ;
V_48 = V_15 -> V_22 ;
V_49 = V_15 -> V_23 ;
if ( V_49 == 0 )
return NULL ;
if ( ! V_48 )
return NULL ;
for ( V_52 = 0 , V_50 = - 1 ; V_52 < V_49 ; V_52 ++ )
if ( V_48 [ V_52 ] == '\0' ) {
V_50 = V_52 ;
break;
}
if ( V_50 < 0 )
V_50 = V_49 ;
V_51 = F_16 ( V_50 + 1 , V_19 | V_20 ) ;
if ( ! V_51 )
return NULL ;
if ( V_50 > 0 )
memcpy ( V_51 , V_48 , V_50 ) ;
( ( T_4 * ) ( V_51 ) ) [ V_50 ] = '\0' ;
return V_51 ;
}
static T_5 F_17 ( struct V_6 * V_7 ,
struct V_53 * V_54 ,
char * V_55 )
{
T_4 V_56 ;
F_18 ( V_57 ,
F_19 ( struct V_58 ,
V_56 ) , & V_56 , sizeof( T_4 ) ) ;
return F_20 ( V_55 , V_59 , L_1 , V_56 ) ;
}
static T_5 F_21 ( struct V_6 * V_7 ,
struct V_53 * V_54 ,
const char * V_55 , T_6 V_60 )
{
T_4 V_56 ;
int V_61 ;
if ( F_22 ( V_55 , 10 , & V_56 ) )
return - V_62 ;
V_61 = F_23 ( V_57 ,
F_19 ( struct V_58 ,
V_56 ) ,
& V_56 , sizeof( T_4 ) ) ;
if ( V_61 )
return V_61 ;
return V_60 ;
}
static T_5 F_24 ( struct V_6 * V_7 ,
struct V_53 * V_54 ,
char * V_55 )
{
struct V_63 V_63 ;
F_18 ( V_57 ,
F_19 ( struct V_58 ,
V_64 ) , & V_63 ,
sizeof( struct V_63 ) ) ;
return F_20 ( V_55 , V_59 , L_1 ,
V_63 . V_65 ) ;
}
static T_5 F_25 ( struct V_6 * V_7 ,
struct V_53 * V_54 ,
const char * V_55 , T_6 V_60 )
{
int V_66 , V_61 ;
struct V_63 V_63 ;
if ( F_26 ( V_55 , 10 , & V_66 ) )
return - V_62 ;
V_63 . V_65 = V_66 ;
V_61 = F_23 ( V_57 ,
F_19 ( struct V_58 ,
V_64 ) , & ( V_63 ) ,
sizeof( struct V_63 ) ) ;
if ( V_61 )
return V_61 ;
return V_60 ;
}
static T_5 F_27 ( struct V_6 * V_7 , struct V_53 * V_54 ,
char * V_55 )
{
T_2 error ;
F_18 ( V_57 ,
F_19 ( struct V_58 ,
V_67 ) ,
& error , sizeof( T_2 ) ) ;
return F_20 ( V_55 , V_59 , L_2 , error ) ;
}
static T_5 F_28 ( struct V_6 * V_7 , struct V_53 * V_54 ,
const char * V_55 , T_6 V_60 )
{
T_2 error ;
int V_61 ;
if ( F_29 ( V_55 , 10 , & error ) )
return - V_62 ;
V_61 = F_23 ( V_57 ,
F_19 ( struct V_58 ,
V_67 ) ,
& error , sizeof( T_2 ) ) ;
if ( V_61 )
return V_61 ;
return V_60 ;
}
static T_5 F_30 ( struct V_6 * V_7 , struct V_53 * V_54 ,
char * V_55 )
{
T_2 V_68 ;
F_18 ( V_57 ,
F_19 ( struct V_58 ,
V_69 ) ,
& V_68 , sizeof( T_2 ) ) ;
return F_20 ( V_55 , V_59 , L_2 , V_68 ) ;
}
static T_5 F_31 ( struct V_6 * V_7 , struct V_53 * V_54 ,
const char * V_55 , T_6 V_60 )
{
T_2 V_68 ;
int V_61 ;
if ( F_29 ( V_55 , 10 , & V_68 ) )
return - V_62 ;
V_61 = F_23 ( V_57 ,
F_19 ( struct V_58 ,
V_69 ) ,
& V_68 , sizeof( T_2 ) ) ;
if ( V_61 )
return V_61 ;
return V_60 ;
}
static T_5 F_32 ( struct V_6 * V_7 ,
struct V_53 * V_54 , char * V_55 )
{
T_7 V_70 ;
F_18 ( V_57 ,
F_19 ( struct V_58 ,
V_71 ) ,
& V_70 , sizeof( T_7 ) ) ;
return F_20 ( V_55 , V_59 , L_3 , V_70 ) ;
}
static T_5 F_33 ( struct V_6 * V_7 ,
struct V_53 * V_54 ,
const char * V_55 , T_6 V_60 )
{
T_7 V_70 ;
int V_61 ;
if ( F_34 ( V_55 , 10 , & V_70 ) )
return - V_62 ;
V_61 = F_23 ( V_57 ,
F_19 ( struct V_58 ,
V_71 ) ,
& V_70 , sizeof( T_7 ) ) ;
if ( V_61 )
return V_61 ;
return V_60 ;
}
static int F_35 ( struct V_6 * V_7 , void * V_27 )
{
struct V_72 * V_73 = F_36 ( V_7 ) ;
struct V_74 * V_33 = V_27 ;
T_2 V_75 = V_33 -> V_75 ;
T_2 V_76 = V_33 -> V_76 ;
if ( ( V_73 -> V_77 == V_75 ) &&
( V_73 -> V_78 == V_76 ) )
return 1 ;
return 0 ;
}
struct V_72 * F_37 ( T_2 V_75 , T_2 V_76 ,
struct V_72 * V_79 )
{
struct V_6 * V_7 ;
struct V_6 * V_80 = NULL ;
struct V_72 * V_73 = NULL ;
struct V_74 V_33 = {
. V_75 = V_75 ,
. V_76 = V_76
} ;
if ( V_79 )
V_80 = & V_79 -> V_6 ;
V_7 = F_38 ( & V_81 , V_80 , ( void * ) & V_33 ,
F_35 ) ;
if ( V_7 )
V_73 = F_36 ( V_7 ) ;
return V_73 ;
}
static T_4
F_39 ( void )
{
int V_52 ;
T_4 V_82 = 1 ;
for ( V_52 = 0 ; V_52 < V_83 ; V_52 ++ )
V_82 &= V_84 [ V_52 ] ;
return V_82 ;
}
static void
F_40 ( void )
{
int V_52 ;
for ( V_52 = 0 ; V_52 < V_83 ; V_52 ++ )
V_84 [ V_52 ] = 0 ;
}
void
F_41 (
struct V_85 * V_86 ,
struct V_87 * V_88 ,
struct V_89 * V_90 )
{
F_42 ( & V_91 ) ;
if ( ! V_86 ) {
memset ( & V_92 , 0 ,
sizeof( V_92 ) ) ;
V_93 = 0 ;
} else {
V_92 = * V_86 ;
V_93 = 1 ;
}
if ( V_88 )
* V_88 = V_94 ;
if ( V_90 )
F_43 ( V_90 , L_4 , L_5 ,
V_95 , NULL ) ;
F_44 ( & V_91 ) ;
}
static void
F_45 ( struct V_96 * V_97 )
{
static int V_98 ;
enum V_99 V_100 = 0 ;
int V_14 = V_101 ;
F_46 ( V_102 , V_103 ) ;
if ( V_98 ) {
V_14 = - V_104 ;
goto V_18;
}
V_98 = 1 ;
F_46 ( V_105 , V_103 ) ;
V_100 =
V_97 -> V_106 . V_107 .
V_100 & V_108 ;
V_100 |= V_109 ;
V_18:
if ( V_97 -> V_110 . V_111 . V_112 )
F_47 ( & V_97 -> V_110 , V_14 , V_100 ) ;
}
static void
F_48 ( struct V_96 * V_113 ,
struct V_114 * V_115 , int V_116 )
{
memset ( V_113 , 0 , sizeof( struct V_96 ) ) ;
memcpy ( & V_113 -> V_110 , V_115 , sizeof( struct V_114 ) ) ;
V_113 -> V_110 . V_117 = 0 ;
V_113 -> V_110 . V_118 = 0 ;
V_113 -> V_110 . V_119 = 0 ;
if ( V_116 < 0 ) {
V_113 -> V_110 . V_111 . V_120 = 1 ;
V_113 -> V_110 . V_121 = ( T_2 ) ( - V_116 ) ;
}
}
static void
F_49 ( struct V_114 * V_115 , int V_116 )
{
struct V_96 V_122 ;
F_48 ( & V_122 , V_115 , V_116 ) ;
if ( V_122 . V_110 . V_111 . V_123 == 1 )
return;
if ( ! F_50 ( V_57 ,
V_124 , & V_122 ) ) {
return;
}
}
static void
F_47 ( struct V_114 * V_115 ,
int V_116 ,
enum V_99 V_100 )
{
struct V_96 V_122 ;
F_48 ( & V_122 , V_115 , V_116 ) ;
V_122 . V_106 . V_107 . V_100 = V_100 ;
if ( ! F_50 ( V_57 ,
V_124 , & V_122 ) ) {
return;
}
}
static void F_51 (
struct V_114 * V_115 , int V_116 ,
struct V_125 V_126 )
{
struct V_96 V_122 ;
F_48 ( & V_122 , V_115 , V_116 ) ;
V_122 . V_106 . V_127 . V_126 = V_126 ;
V_122 . V_106 . V_127 . V_111 . V_128 = 1 ;
if ( ! F_50 ( V_57 ,
V_124 , & V_122 ) ) {
return;
}
}
static void
F_52 ( struct V_96 * V_113 , enum V_129 V_130 )
{
T_2 V_131 ;
T_7 V_132 ;
if ( F_18 ( V_57 ,
F_19 ( struct V_58 ,
V_133 ) ,
& V_132 , sizeof( T_7 ) ) < 0 ) {
F_46 ( V_134 ,
V_135 ) ;
return;
}
if ( V_132 != V_136 ) {
F_53 ( V_137 ,
V_132 ,
V_135 ) ;
return;
}
if ( F_18 ( V_57 ,
F_19 ( struct V_58 ,
V_138 ) ,
& V_131 , sizeof( T_2 ) ) < 0 ) {
F_46 ( V_134 ,
V_135 ) ;
return;
}
if ( V_130 == V_139 ) {
if ( F_23 ( V_57 ,
V_131 ,
V_113 ,
sizeof( struct V_96 ) ) < 0 ) {
F_46 ( V_140 ,
V_135 ) ;
return;
}
} else {
V_131 += sizeof( struct V_96 ) ;
if ( F_23 ( V_57 ,
V_131 ,
V_113 ,
sizeof( struct V_96 ) ) < 0 ) {
F_46 ( V_141 ,
V_135 ) ;
return;
}
}
}
static void
F_54 ( enum V_142 V_143 ,
struct V_114 * V_144 ,
int V_116 )
{
if ( ! V_144 )
return;
if ( V_144 -> V_33 != ( T_2 ) V_143 )
return;
F_49 ( V_144 , V_116 ) ;
}
static void
F_55 ( enum V_142 V_143 ,
struct V_72 * V_25 , int V_116 ,
struct V_125 V_145 )
{
struct V_96 V_122 ;
T_2 V_75 = V_25 -> V_77 ;
T_2 V_76 = V_25 -> V_78 ;
if ( ! V_25 -> V_144 )
return;
if ( V_25 -> V_144 -> V_33 != V_143 )
return;
F_48 ( & V_122 , V_25 -> V_144 , V_116 ) ;
V_122 . V_106 . V_127 . V_75 = V_75 ;
V_122 . V_106 . V_127 . V_76 = V_76 ;
V_122 . V_106 . V_127 . V_126 = V_145 ;
if ( ! F_50 ( V_57 ,
V_124 , & V_122 ) )
return;
}
static void
F_56 ( enum V_142 V_143 ,
struct V_114 * V_144 ,
int V_116 )
{
if ( ! V_144 )
return;
if ( V_144 -> V_33 != ( T_2 ) V_143 )
return;
F_49 ( V_144 , V_116 ) ;
}
static void
F_57 ( struct V_72 * V_146 ,
T_2 V_106 , struct V_114 * V_115 ,
int V_116 , bool V_147 )
{
bool V_148 = false ;
struct V_114 * V_149 = NULL ;
if ( ! V_146 ) {
V_149 = V_115 ;
goto V_150;
}
if ( V_146 -> V_144 ) {
V_116 = - V_151 ;
V_149 = V_146 -> V_144 ;
goto V_150;
}
if ( V_147 ) {
V_149 = F_6 ( sizeof( * V_149 ) , V_19 ) ;
if ( ! V_149 ) {
V_116 = - V_152 ;
goto V_150;
}
memcpy ( V_149 , V_115 ,
sizeof( struct V_114 ) ) ;
V_146 -> V_144 = V_149 ;
}
F_42 ( & V_91 ) ;
if ( V_116 == V_101 ) {
switch ( V_106 ) {
case V_153 :
if ( V_92 . V_154 ) {
(* V_92 . V_154 ) ( V_146 ) ;
V_148 = true ;
}
break;
case V_155 :
if ( V_92 . V_156 ) {
(* V_92 . V_156 ) ( V_146 ) ;
V_148 = true ;
}
break;
}
}
V_150:
if ( V_148 )
;
else
F_54 ( V_106 , V_149 , V_116 ) ;
F_44 ( & V_91 ) ;
}
static void
F_58 ( struct V_72 * V_157 ,
struct V_125 V_126 , T_2 V_106 ,
struct V_114 * V_115 , int V_116 ,
bool V_147 , bool V_158 )
{
struct V_85 * V_86 ;
bool V_148 = false ;
struct V_114 * V_149 = NULL ;
V_86 = & V_92 ;
if ( ! V_157 ) {
V_149 = V_115 ;
goto V_150;
}
if ( V_157 -> V_144 ) {
V_116 = - V_151 ;
V_149 = V_157 -> V_144 ;
goto V_150;
}
if ( V_147 ) {
V_149 = F_6 ( sizeof( * V_149 ) , V_19 ) ;
if ( ! V_149 ) {
V_116 = - V_152 ;
goto V_150;
}
memcpy ( V_149 , V_115 ,
sizeof( struct V_114 ) ) ;
V_157 -> V_144 = V_149 ;
}
F_42 ( & V_91 ) ;
if ( V_116 >= 0 ) {
switch ( V_106 ) {
case V_159 :
if ( V_86 -> V_160 ) {
(* V_86 -> V_160 ) ( V_157 ) ;
V_148 = true ;
}
break;
case V_161 :
if ( V_126 . V_162 == V_163 . V_162 &&
V_126 . V_164 ==
V_163 . V_164 ) {
if ( V_86 -> V_165 ) {
(* V_86 -> V_165 ) ( V_157 ) ;
V_148 = true ;
}
}
else if ( V_126 . V_162 == V_166 . V_162 &&
V_126 . V_164 ==
V_166 . V_164 ) {
if ( V_86 -> V_167 ) {
(* V_86 -> V_167 ) ( V_157 ) ;
V_148 = true ;
}
}
break;
case V_168 :
if ( V_86 -> V_169 ) {
(* V_86 -> V_169 ) ( V_157 ) ;
V_148 = true ;
}
break;
}
}
V_150:
if ( V_148 )
;
else
F_56 ( V_106 , V_149 , V_116 ) ;
F_44 ( & V_91 ) ;
}
static void
V_154 ( struct V_96 * V_97 )
{
struct V_170 * V_106 = & V_97 -> V_106 ;
T_2 V_75 = V_106 -> V_171 . V_75 ;
int V_14 = V_101 ;
struct V_72 * V_146 ;
struct V_172 * V_172 ;
V_146 = F_37 ( V_75 , V_173 , NULL ) ;
if ( V_146 && ( V_146 -> V_126 . V_174 == 1 ) ) {
F_53 ( V_175 , V_75 ,
V_135 ) ;
V_14 = - V_104 ;
goto V_18;
}
V_146 = F_6 ( sizeof( * V_146 ) , V_19 ) ;
if ( ! V_146 ) {
F_53 ( V_175 , V_75 ,
V_135 ) ;
V_14 = - V_152 ;
goto V_18;
}
F_59 ( & V_146 -> V_176 ) ;
V_146 -> V_77 = V_75 ;
V_146 -> V_78 = V_173 ;
F_53 ( V_177 , V_75 , V_103 ) ;
V_172 = F_60 ( V_106 -> V_171 . V_178 ,
V_106 -> V_171 . V_179 ,
V_19 ,
V_106 -> V_171 . V_180 ) ;
if ( ! V_172 ) {
F_53 ( V_175 , V_75 ,
V_135 ) ;
V_14 = - V_152 ;
F_14 ( V_146 ) ;
V_146 = NULL ;
goto V_18;
}
V_146 -> V_172 = V_172 ;
if ( F_61 ( V_106 -> V_171 . V_181 , V_182 ) == 0 ) {
V_183 = V_75 ;
F_52 ( V_97 , V_139 ) ;
}
F_53 ( V_184 , V_75 , V_103 ) ;
V_18:
F_57 ( V_146 , V_153 , & V_97 -> V_110 ,
V_14 , V_97 -> V_110 . V_111 . V_112 == 1 ) ;
}
static void
V_156 ( struct V_96 * V_97 )
{
struct V_170 * V_106 = & V_97 -> V_106 ;
T_2 V_75 = V_106 -> V_185 . V_75 ;
struct V_72 * V_146 ;
int V_14 = V_101 ;
V_146 = F_37 ( V_75 , V_173 , NULL ) ;
if ( ! V_146 )
V_14 = - V_186 ;
else if ( V_146 -> V_126 . V_174 == 0 )
V_14 = - V_104 ;
F_57 ( V_146 , V_155 , & V_97 -> V_110 ,
V_14 , V_97 -> V_110 . V_111 . V_112 == 1 ) ;
}
static void
F_62 ( struct V_96 * V_97 ,
struct V_8 * V_187 )
{
struct V_170 * V_106 = & V_97 -> V_106 ;
T_2 V_75 ;
struct V_72 * V_146 ;
int V_14 = V_101 ;
V_75 = V_106 -> V_188 . V_75 ;
F_53 ( V_189 , V_75 ,
V_103 ) ;
V_146 = F_37 ( V_75 , V_173 , NULL ) ;
if ( ! V_146 ) {
F_53 ( V_190 , V_75 ,
V_135 ) ;
V_14 = - V_186 ;
} else if ( V_146 -> V_126 . V_174 == 0 ) {
F_53 ( V_190 , V_75 ,
V_135 ) ;
V_14 = - V_186 ;
} else if ( V_146 -> V_144 ) {
F_53 ( V_190 , V_75 ,
V_135 ) ;
V_14 = - V_151 ;
} else {
F_63 ( V_146 -> V_172 ,
V_106 -> V_188 . V_191 ) ;
V_146 -> V_192 = F_12 ( V_187 ) ;
F_13 ( V_187 , V_45 ) ;
V_146 -> V_193 = F_15 ( V_187 ) ;
F_53 ( V_194 , V_75 ,
V_103 ) ;
}
F_57 ( V_146 , V_195 , & V_97 -> V_110 ,
V_14 , V_97 -> V_110 . V_111 . V_112 == 1 ) ;
}
static void
F_64 ( struct V_96 * V_97 )
{
struct V_170 * V_106 = & V_97 -> V_106 ;
T_2 V_75 = V_106 -> V_196 . V_75 ;
T_2 V_76 = V_106 -> V_196 . V_76 ;
struct V_72 * V_157 = NULL ;
struct V_72 * V_146 ;
struct V_172 * V_172 ;
int V_14 = V_101 ;
V_146 = F_37 ( V_75 , V_173 , NULL ) ;
if ( ! V_146 ) {
F_65 ( V_197 , V_76 , V_75 ,
V_135 ) ;
V_14 = - V_186 ;
goto V_18;
}
if ( V_146 -> V_126 . V_174 == 0 ) {
F_65 ( V_197 , V_76 , V_75 ,
V_135 ) ;
V_14 = - V_186 ;
goto V_18;
}
V_157 = F_37 ( V_75 , V_76 , NULL ) ;
if ( V_157 && ( V_157 -> V_126 . V_174 == 1 ) ) {
F_65 ( V_197 , V_76 , V_75 ,
V_135 ) ;
V_14 = - V_104 ;
goto V_18;
}
V_157 = F_6 ( sizeof( * V_157 ) , V_19 ) ;
if ( ! V_157 ) {
F_65 ( V_197 , V_76 , V_75 ,
V_135 ) ;
V_14 = - V_152 ;
goto V_18;
}
V_157 -> V_77 = V_75 ;
V_157 -> V_78 = V_76 ;
V_157 -> V_198 = V_106 -> V_196 . V_199 ;
V_157 -> V_6 . V_200 = & V_146 -> V_6 ;
F_65 ( V_201 , V_76 , V_75 ,
V_103 ) ;
V_172 =
F_66 ( V_106 -> V_196 . V_178 ,
V_106 -> V_196 . V_179 ,
V_19 ,
V_106 -> V_196 . V_202 ) ;
if ( ! V_172 ) {
F_65 ( V_197 , V_76 , V_75 ,
V_135 ) ;
V_14 = - V_152 ;
F_14 ( V_157 ) ;
V_157 = NULL ;
goto V_18;
}
V_157 -> V_172 = V_172 ;
V_157 -> V_203 = V_106 -> V_196 . V_202 ;
if ( F_61 ( V_106 -> V_196 . V_202 ,
V_204 ) == 0 )
F_52 ( V_97 , V_205 ) ;
F_65 ( V_206 , V_76 , V_75 ,
V_103 ) ;
V_18:
F_58 ( V_157 , V_163 ,
V_159 , & V_97 -> V_110 , V_14 ,
V_97 -> V_110 . V_111 . V_112 == 1 , 1 ) ;
}
static void
F_67 ( struct V_96 * V_97 )
{
struct V_170 * V_106 = & V_97 -> V_106 ;
T_2 V_75 = V_106 -> V_127 . V_75 ;
T_2 V_76 = V_106 -> V_127 . V_76 ;
struct V_125 V_126 = V_106 -> V_127 . V_126 ;
struct V_72 * V_157 ;
int V_14 = V_101 ;
V_157 = F_37 ( V_75 , V_76 , NULL ) ;
if ( ! V_157 ) {
F_65 ( V_207 , V_76 , V_75 ,
V_135 ) ;
V_14 = - V_208 ;
} else if ( V_157 -> V_126 . V_174 == 0 ) {
F_65 ( V_207 , V_76 , V_75 ,
V_135 ) ;
V_14 = - V_208 ;
}
if ( ( V_14 >= V_101 ) && V_157 )
F_58 ( V_157 , V_126 ,
V_161 , & V_97 -> V_110 , V_14 ,
V_97 -> V_110 . V_111 . V_112 == 1 , 1 ) ;
}
static void
F_68 ( struct V_96 * V_97 )
{
struct V_170 * V_106 = & V_97 -> V_106 ;
T_2 V_75 = V_106 -> V_209 . V_75 ;
T_2 V_76 = V_106 -> V_209 . V_76 ;
struct V_72 * V_157 ;
int V_14 = V_101 ;
V_157 = F_37 ( V_75 , V_76 , NULL ) ;
if ( ! V_157 )
V_14 = - V_208 ;
else if ( V_157 -> V_126 . V_174 == 0 )
V_14 = - V_104 ;
if ( ( V_14 >= V_101 ) && V_157 )
F_58 ( V_157 , V_163 ,
V_168 , & V_97 -> V_110 , V_14 ,
V_97 -> V_110 . V_111 . V_112 == 1 , 1 ) ;
}
static int
F_69 ( T_1 V_210 , T_1 V_211 , T_2 V_10 ,
struct V_212 * V_213 )
{
T_4 * V_214 = NULL ;
int V_14 = V_101 ;
if ( ! V_213 ) {
V_14 = - V_215 ;
goto V_18;
}
memset ( V_213 , 0 , sizeof( struct V_212 ) ) ;
if ( ( V_211 == 0 ) || ( V_10 == 0 ) ) {
V_14 = - V_215 ;
goto V_18;
}
V_214 = F_9 ( V_210 + V_211 , V_10 , V_29 ) ;
if ( ! V_214 ) {
V_14 = - V_216 ;
goto V_18;
}
V_213 -> V_211 = V_211 ;
V_213 -> V_10 = V_10 ;
V_213 -> V_217 = V_214 ;
V_18:
if ( V_14 < 0 ) {
if ( V_214 ) {
F_10 ( V_214 ) ;
V_214 = NULL ;
}
}
return V_14 ;
}
static void
F_70 ( struct V_212 * V_213 )
{
if ( V_213 -> V_217 ) {
F_10 ( V_213 -> V_217 ) ;
V_213 -> V_217 = NULL ;
}
memset ( V_213 , 0 , sizeof( struct V_212 ) ) ;
}
static void
F_71 ( void )
{
T_1 V_210 = F_72 ( V_57 ) ;
T_1 V_218 = 0 ;
T_2 V_117 = 0 ;
if ( F_18 ( V_57 ,
F_19 ( struct V_58 ,
V_219 ) ,
& V_218 , sizeof( V_218 ) ) < 0 ) {
F_46 ( V_220 ,
V_135 ) ;
return;
}
if ( F_18 ( V_57 ,
F_19 ( struct V_58 ,
V_221 ) ,
& V_117 , sizeof( V_117 ) ) < 0 ) {
F_46 ( V_220 ,
V_135 ) ;
return;
}
F_69 ( V_210 ,
V_218 , V_117 ,
& V_222 ) ;
}
static int
F_73 ( void )
{
F_74 ( & V_223 . V_7 . V_224 , V_225 ) ;
return V_101 ;
}
static int
F_75 ( void )
{
char V_226 [ 20 ] ;
char * V_227 [] = { V_226 , NULL } ;
sprintf ( V_226 , L_6 , 1 ) ;
F_76 ( & V_223 . V_7 . V_224 , V_228 ,
V_227 ) ;
return V_101 ;
}
static int
F_77 ( void )
{
F_74 ( & V_223 . V_7 . V_224 , V_229 ) ;
return V_101 ;
}
static void
F_78 ( struct V_114 * V_115 )
{
int V_14 = F_73 () ;
if ( V_14 != V_101 )
V_14 = - V_14 ;
if ( V_115 -> V_111 . V_112 && ! V_230 )
F_49 ( V_115 , V_14 ) ;
if ( V_115 -> V_111 . V_112 && V_230 ) {
V_231 = * V_115 ;
}
}
static void
F_79 ( struct V_114 * V_115 )
{
int V_14 = F_75 () ;
if ( V_14 != V_101 )
V_14 = - V_14 ;
if ( V_115 -> V_111 . V_112 )
F_49 ( V_115 , V_14 ) ;
}
static void
F_80 ( struct V_114 * V_115 )
{
int V_14 = F_77 () ;
if ( V_14 != V_101 )
V_14 = - V_14 ;
if ( V_115 -> V_111 . V_112 )
F_49 ( V_115 , V_14 ) ;
}
static bool
F_81 ( struct V_96 * V_113 )
{
if ( F_82 ( V_57 ,
V_232 , V_113 ) ) {
if ( V_113 -> V_110 . V_111 . V_123 == 1 )
return false ;
return true ;
}
return false ;
}
static int
F_83 ( void )
{
static T_8 V_33 = F_84 ( 0 ) ;
return F_85 ( & V_33 ) ;
}
static unsigned long
F_86 ( void )
{
return V_233 + F_87 ( V_234 ) ;
}
static struct V_235 *
F_88 ( struct V_96 * V_113 )
{
struct V_235 * V_236 ;
V_236 = F_16 ( sizeof( * V_236 ) , V_19 | V_20 ) ;
if ( ! V_236 )
return NULL ;
V_236 -> V_33 = F_83 () ;
V_236 -> V_237 = F_86 () ;
V_236 -> V_113 = * V_113 ;
return V_236 ;
}
static void
F_89 ( struct V_235 * V_236 )
{
F_14 ( V_236 ) ;
}
static void
F_90 ( struct V_235 * V_236 )
{
struct V_170 * V_106 = & V_236 -> V_113 . V_106 ;
char V_238 [ 40 ] , V_239 [ 40 ] , V_240 [ 40 ] , V_241 [ 40 ] , V_242 [ 40 ] ,
V_243 [ 40 ] ;
char * V_227 [] = {
V_238 , V_239 , V_240 , V_241 , V_242 , V_243 , NULL
} ;
sprintf ( V_238 , L_7 ) ;
sprintf ( V_239 , L_8 , V_236 -> V_33 ) ;
sprintf ( V_240 , L_9 ,
V_106 -> V_127 . V_126 . V_244 ) ;
sprintf ( V_241 , L_10 ,
V_106 -> V_127 . V_75 ) ;
sprintf ( V_242 , L_11 ,
V_106 -> V_127 . V_76 >> 3 ) ;
sprintf ( V_243 , L_12 ,
V_106 -> V_127 . V_76 & 0x7 ) ;
F_76 ( & V_223 . V_7 . V_224 , V_228 ,
V_227 ) ;
}
static void
F_91 ( void )
{
struct V_245 * V_246 ;
struct V_245 * V_247 ;
F_92 ( & V_248 ) ;
F_93 (pos, tmp, &parahotplug_request_list) {
struct V_235 * V_236 =
F_94 ( V_246 , struct V_235 , V_249 ) ;
if ( ! F_95 ( V_233 , V_236 -> V_237 ) )
continue;
F_96 ( V_246 ) ;
if ( V_236 -> V_113 . V_110 . V_111 . V_112 )
F_51 (
& V_236 -> V_113 . V_110 ,
V_250 ,
V_236 -> V_113 . V_106 . V_127 . V_126 ) ;
F_89 ( V_236 ) ;
}
F_97 ( & V_248 ) ;
}
static int
F_98 ( int V_33 , T_7 V_244 )
{
struct V_245 * V_246 ;
struct V_245 * V_247 ;
F_92 ( & V_248 ) ;
F_93 (pos, tmp, &parahotplug_request_list) {
struct V_235 * V_236 =
F_94 ( V_246 , struct V_235 , V_249 ) ;
if ( V_236 -> V_33 == V_33 ) {
F_96 ( V_246 ) ;
F_97 ( & V_248 ) ;
V_236 -> V_113 . V_106 . V_127 . V_126 . V_244 = V_244 ;
if ( V_236 -> V_113 . V_110 . V_111 . V_112 )
F_51 (
& V_236 -> V_113 . V_110 , V_101 ,
V_236 -> V_113 . V_106 . V_127 . V_126 ) ;
F_89 ( V_236 ) ;
return 0 ;
}
}
F_97 ( & V_248 ) ;
return - 1 ;
}
static void
F_99 ( struct V_96 * V_97 )
{
struct V_235 * V_236 ;
V_236 = F_88 ( V_97 ) ;
if ( ! V_236 )
return;
if ( V_97 -> V_106 . V_127 . V_126 . V_244 ) {
F_90 ( V_236 ) ;
F_51 ( & V_97 -> V_110 ,
V_101 ,
V_97 -> V_106 . V_127 . V_126 ) ;
F_89 ( V_236 ) ;
} else {
F_92 ( & V_248 ) ;
F_100 ( & V_236 -> V_249 , & V_251 ) ;
F_97 ( & V_248 ) ;
F_90 ( V_236 ) ;
}
}
static bool
F_101 ( struct V_96 V_97 , T_1 V_178 )
{
struct V_170 * V_106 = & V_97 . V_106 ;
T_1 V_252 ;
T_2 V_253 ;
struct V_8 * V_187 = NULL ;
bool V_254 ;
struct V_96 V_255 ;
V_254 = ( V_97 . V_110 . V_111 . V_123 == 1 ) ;
if ( V_178 == 0 )
return true ;
V_252 = V_178 + V_97 . V_110 . V_118 ;
V_253 = V_97 . V_110 . V_117 ;
if ( V_252 && V_253 ) {
bool V_12 = false ;
V_187 =
F_5 ( V_252 , V_253 ,
V_254 , & V_12 ) ;
if ( ! V_187 && V_12 )
return false ;
}
if ( ! V_254 ) {
F_48 ( & V_255 , & V_97 . V_110 ,
V_101 ) ;
if ( V_57 )
F_50 ( V_57 ,
V_256 ,
& V_255 ) ;
}
switch ( V_97 . V_110 . V_33 ) {
case V_257 :
F_45 ( & V_97 ) ;
break;
case V_153 :
V_154 ( & V_97 ) ;
break;
case V_155 :
V_156 ( & V_97 ) ;
break;
case V_195 :
F_62 ( & V_97 , V_187 ) ;
break;
case V_159 :
F_64 ( & V_97 ) ;
break;
case V_161 :
if ( V_106 -> V_127 . V_111 . V_128 ) {
F_99 ( & V_97 ) ;
} else {
F_67 ( & V_97 ) ;
V_258 = V_97 . V_106 ;
break;
}
break;
case V_168 :
F_68 ( & V_97 ) ;
break;
case V_259 :
if ( V_97 . V_110 . V_111 . V_112 )
F_49 ( & V_97 . V_110 , V_101 ) ;
break;
case V_260 :
F_78 ( & V_97 . V_110 ) ;
break;
case V_261 :
F_79 ( & V_97 . V_110 ) ;
break;
case V_262 :
F_80 ( & V_97 . V_110 ) ;
break;
default:
if ( V_97 . V_110 . V_111 . V_112 )
F_49 ( & V_97 . V_110 ,
- V_263 ) ;
break;
}
if ( V_187 ) {
F_11 ( V_187 ) ;
V_187 = NULL ;
}
return true ;
}
static inline unsigned int
F_102 ( T_1 * V_264 , T_2 * V_265 )
{
struct V_266 V_267 ;
int V_268 = V_269 ;
T_1 V_270 ;
V_270 = F_7 ( & V_267 ) ;
F_103 ( V_271 , V_270 , V_268 ) ;
if ( F_104 ( V_268 ) ) {
* V_264 = V_267 . V_272 ;
* V_265 = V_267 . V_179 ;
}
return V_268 ;
}
static T_1 F_105 ( void )
{
T_1 V_9 = 0 ;
T_2 V_273 = 0 ;
if ( ! F_104 ( F_102 ( & V_9 , & V_273 ) ) )
return 0 ;
return V_9 ;
}
static void
F_106 ( struct V_274 * V_275 )
{
struct V_96 V_97 ;
bool V_276 = false ;
bool V_277 = false ;
static T_1 V_278 ;
if ( V_279 && ! V_93 )
goto V_18;
V_278 ++ ;
if ( V_278 >= 250 )
;
else
goto V_18;
if ( V_230 &&
( V_231 . V_33 != V_280 ) ) {
if ( F_39 () == 1 ) {
F_49 ( & V_231 , 0 ) ;
F_40 () ;
memset ( & V_231 , 0 ,
sizeof( struct V_114 ) ) ;
}
}
while ( F_82 ( V_57 ,
V_281 ,
& V_97 ) )
;
if ( ! V_276 ) {
if ( V_282 ) {
V_97 = V_283 ;
V_282 = false ;
V_276 = true ;
} else {
V_276 = F_81 ( & V_97 ) ;
}
}
V_277 = false ;
while ( V_276 && ( ! V_277 ) ) {
V_284 = V_233 ;
if ( F_101 ( V_97 ,
F_72
( V_57 ) ) )
V_276 = F_81 ( & V_97 ) ;
else {
V_277 = true ;
V_283 = V_97 ;
V_282 = true ;
}
}
F_91 () ;
V_18:
if ( F_107 ( V_233 ,
V_284 + ( V_285 * V_286 ) ) ) {
if ( V_287 != V_288 )
V_287 = V_288 ;
} else {
if ( V_287 != V_289 )
V_287 = V_289 ;
}
F_108 ( & V_290 , V_287 ) ;
}
static void
F_109 ( struct V_274 * V_275 )
{
struct V_96 V_291 ;
struct V_96 V_292 ;
struct V_96 V_113 ;
T_2 V_131 ;
T_7 V_132 ;
if ( V_279 && ! V_93 )
goto V_18;
F_46 ( V_293 , V_103 ) ;
V_113 . V_110 . V_33 = V_257 ;
V_113 . V_106 . V_107 . V_294 = 23 ;
V_113 . V_106 . V_107 . V_295 = 0 ;
F_45 ( & V_113 ) ;
if ( F_18 ( V_57 ,
F_19 ( struct V_58 ,
V_133 ) ,
& V_132 , sizeof( T_7 ) ) < 0 ) {
F_46 ( V_134 ,
V_135 ) ;
return;
}
if ( V_132 != V_136 ) {
F_53 ( V_137 ,
V_132 ,
V_135 ) ;
return;
}
if ( F_18 ( V_57 ,
F_19 ( struct V_58 ,
V_138 ) ,
& V_131 , sizeof( T_2 ) ) < 0 ) {
F_46 ( V_134 ,
V_135 ) ;
return;
}
if ( F_18 ( V_57 ,
V_131 ,
& V_291 ,
sizeof( struct V_96 ) ) < 0 ) {
F_46 ( V_296 ,
V_135 ) ;
return;
}
if ( F_18 ( V_57 ,
V_131 +
sizeof( struct V_96 ) ,
& V_292 ,
sizeof( struct V_96 ) ) < 0 ) {
F_46 ( V_297 ,
V_135 ) ;
return;
}
if ( V_291 . V_106 . V_171 . V_178 ) {
V_154 ( & V_291 ) ;
} else {
F_46 ( V_298 ,
V_135 ) ;
return;
}
if ( V_292 . V_106 . V_196 . V_178 ) {
F_64 ( & V_292 ) ;
} else {
F_46 ( V_299 ,
V_135 ) ;
return;
}
F_46 ( V_300 , V_103 ) ;
return;
V_18:
V_287 = V_288 ;
F_108 ( & V_290 , V_287 ) ;
}
static void
F_110 ( struct V_72 * V_146 , int V_116 )
{
if ( V_116 >= 0 )
V_146 -> V_126 . V_174 = 1 ;
F_54 ( V_153 , V_146 -> V_144 ,
V_116 ) ;
F_14 ( V_146 -> V_144 ) ;
V_146 -> V_144 = NULL ;
}
static void
F_111 ( struct V_72 * V_146 , int V_116 )
{
F_54 ( V_155 , V_146 -> V_144 ,
V_116 ) ;
F_14 ( V_146 -> V_144 ) ;
V_146 -> V_144 = NULL ;
}
static void
F_112 ( struct V_72 * V_157 , int V_116 )
{
if ( V_116 >= 0 )
V_157 -> V_126 . V_174 = 1 ;
F_56 ( V_159 , V_157 -> V_144 ,
V_116 ) ;
F_14 ( V_157 -> V_144 ) ;
V_157 -> V_144 = NULL ;
}
static void
F_113 ( struct V_72 * V_157 , int V_116 )
{
F_56 ( V_168 , V_157 -> V_144 ,
V_116 ) ;
F_14 ( V_157 -> V_144 ) ;
V_157 -> V_144 = NULL ;
}
static void
F_114 ( struct V_72 * V_157 ,
int V_116 )
{
F_55 ( V_161 ,
V_157 , V_116 ,
V_166 ) ;
F_14 ( V_157 -> V_144 ) ;
V_157 -> V_144 = NULL ;
}
static void
F_115 ( struct V_72 * V_157 , int V_116 )
{
F_55 ( V_161 ,
V_157 , V_116 ,
V_163 ) ;
F_14 ( V_157 -> V_144 ) ;
V_157 -> V_144 = NULL ;
}
static T_5 F_116 ( struct V_6 * V_7 ,
struct V_53 * V_54 ,
const char * V_55 , T_6 V_60 )
{
char V_301 [ 64 ] ;
if ( sscanf ( V_55 , L_13 , V_301 ) != 1 )
return - V_62 ;
if ( ! strcmp ( V_301 , L_14 ) ) {
V_84 [ 0 ] = 1 ;
return V_60 ;
} else if ( ! strcmp ( V_301 , L_15 ) ) {
V_84 [ 1 ] = 1 ;
return V_60 ;
}
return - V_62 ;
}
static T_5 F_117 ( struct V_6 * V_7 ,
struct V_53 * V_54 ,
const char * V_55 , T_6 V_60 )
{
unsigned int V_33 ;
if ( F_118 ( V_55 , 10 , & V_33 ) )
return - V_62 ;
F_98 ( V_33 , 0 ) ;
return V_60 ;
}
static T_5 F_119 ( struct V_6 * V_7 ,
struct V_53 * V_54 ,
const char * V_55 , T_6 V_60 )
{
unsigned int V_33 ;
if ( F_118 ( V_55 , 10 , & V_33 ) )
return - V_62 ;
F_98 ( V_33 , 1 ) ;
return V_60 ;
}
static int
F_120 ( struct V_2 * V_2 , struct V_302 * V_303 )
{
unsigned long V_270 = 0 ;
unsigned long V_211 = V_303 -> V_304 << V_305 ;
T_1 V_9 = 0 ;
if ( V_211 & ( V_59 - 1 ) )
return - V_306 ;
switch ( V_211 ) {
case V_307 :
V_303 -> V_308 |= V_309 ;
if ( ! * V_310 )
return - V_306 ;
F_18 ( * V_310 ,
F_19 ( struct V_58 ,
V_311 ) ,
& V_9 , sizeof( V_9 ) ) ;
if ( ! V_9 )
return - V_306 ;
V_270 = ( unsigned long ) V_9 ;
if ( F_121 ( V_303 , V_303 -> V_312 ,
V_270 >> V_305 ,
V_303 -> V_313 - V_303 -> V_312 ,
( V_303 -> V_314 ) ) ) {
return - V_315 ;
}
break;
default:
return - V_306 ;
}
return 0 ;
}
static inline T_9 F_122 ( void )
{
T_1 V_268 = V_269 ;
T_1 V_270 = 0 ;
F_103 ( V_316 , V_270 ,
V_268 ) ;
return V_268 ;
}
static inline int F_123 ( T_1 V_317 )
{
int V_268 = V_269 ;
F_103 ( V_318 , V_317 , V_268 ) ;
return V_268 ;
}
static long F_124 ( struct V_2 * V_2 , unsigned int V_106 ,
unsigned long V_319 )
{
T_1 V_317 ;
T_9 V_320 ;
switch ( V_106 ) {
case V_316 :
V_320 = F_122 () ;
if ( F_125 ( ( void V_321 * ) V_319 , & V_320 ,
sizeof( V_320 ) ) ) {
return - V_322 ;
}
return 0 ;
case V_318 :
if ( F_126 ( & V_317 , ( void V_321 * ) V_319 ,
sizeof( V_317 ) ) ) {
return - V_322 ;
}
return F_123 ( V_317 ) ;
default:
return - V_322 ;
}
}
static int
F_127 ( T_10 V_323 , struct V_172 * * V_57 )
{
int V_14 = 0 ;
V_310 = V_57 ;
F_128 ( & V_324 , & V_325 ) ;
V_324 . V_326 = V_327 ;
if ( F_129 ( V_323 ) == 0 ) {
V_14 = F_130 ( & V_323 , 0 , 1 , L_5 ) ;
if ( V_14 < 0 )
return V_14 ;
} else {
V_14 = F_131 ( V_323 , 1 , L_5 ) ;
if ( V_14 < 0 )
return V_14 ;
}
V_14 = F_132 ( & V_324 , F_133 ( F_129 ( V_323 ) , 0 ) , 1 ) ;
if ( V_14 < 0 ) {
F_134 ( V_323 , 1 ) ;
return V_14 ;
}
return 0 ;
}
static int
F_135 ( struct V_328 * V_328 )
{
int V_14 = 0 ;
T_1 V_9 ;
T_3 V_329 = V_330 ;
V_9 = F_105 () ;
if ( ! V_9 )
return - V_4 ;
memset ( & V_92 , 0 , sizeof( V_92 ) ) ;
memset ( & V_222 , 0 , sizeof( V_222 ) ) ;
V_57 = F_66 ( V_9 , 0 ,
V_19 , V_329 ) ;
if ( ! V_57 )
return - V_4 ;
if ( F_136 (
F_137 ( V_57 ) ) ) {
F_71 () ;
} else {
F_138 ( V_57 ) ;
V_57 = NULL ;
return - V_4 ;
}
V_323 = F_133 ( V_331 , 0 ) ;
V_14 = F_127 ( V_323 , & V_57 ) ;
if ( V_14 < 0 ) {
F_46 ( V_332 , V_333 ) ;
goto V_18;
}
memset ( & V_231 , 0 , sizeof( struct V_114 ) ) ;
if ( F_139 () )
F_140 ( & V_290 ,
F_109 ) ;
else
F_140 ( & V_290 ,
F_106 ) ;
V_284 = V_233 ;
V_287 = V_289 ;
F_108 ( & V_290 , V_287 ) ;
V_223 . V_7 . V_334 = V_323 ;
if ( F_141 ( & V_223 ) < 0 ) {
F_46 ( V_335 , V_333 ) ;
V_14 = - V_4 ;
goto V_18;
}
F_46 ( V_336 , V_103 ) ;
V_14 = F_142 () ;
V_18:
if ( V_14 ) {
F_53 ( V_332 , V_14 ,
V_135 ) ;
}
return V_14 ;
}
static void
F_143 ( T_10 V_323 )
{
if ( V_324 . V_337 )
F_144 ( & V_324 ) ;
V_324 . V_337 = NULL ;
F_134 ( V_323 , 1 ) ;
}
static int
F_145 ( struct V_328 * V_328 )
{
F_46 ( V_338 , V_103 ) ;
F_146 () ;
F_147 ( & V_290 ) ;
F_70 ( & V_222 ) ;
memset ( & V_231 , 0 , sizeof( struct V_114 ) ) ;
F_138 ( V_57 ) ;
F_143 ( V_223 . V_7 . V_334 ) ;
F_148 ( & V_223 ) ;
F_46 ( V_338 , V_103 ) ;
return 0 ;
}
static T_11 T_12 F_149 ( void )
{
unsigned int V_339 , V_340 , V_341 , V_342 ;
if ( V_343 ) {
F_150 ( V_344 , & V_339 , & V_340 , & V_341 , & V_342 ) ;
return ( V_340 == V_345 ) &&
( V_341 == V_346 ) &&
( V_342 == V_347 ) ;
} else {
return 0 ;
}
}
static int F_151 ( void )
{
int V_268 ;
if ( ! F_149 () )
return - V_4 ;
V_268 = F_152 ( & V_348 ) ;
if ( V_268 )
return - V_4 ;
F_153 ( L_16 ) ;
return 0 ;
}
static void F_154 ( void )
{
F_155 ( & V_348 ) ;
}

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
void T_3 * V_28 ;
if ( ! F_9 ( V_9 , V_10 , L_1 ) ) {
V_14 = NULL ;
goto V_18;
}
V_28 = F_10 ( V_9 , V_10 ) ;
if ( ! V_28 ) {
F_11 ( V_9 , V_10 ) ;
V_14 = NULL ;
goto V_18;
}
F_12 ( V_15 -> V_27 , V_28 , V_10 ) ;
F_11 ( V_9 , V_10 ) ;
}
V_15 -> V_24 = true ;
V_14 = V_15 ;
V_18:
if ( V_14 ) {
V_16 += V_15 -> V_21 ;
} else {
if ( V_15 ) {
F_13 ( V_15 ) ;
V_15 = NULL ;
}
}
return V_14 ;
}
static T_4
F_14 ( struct V_8 * V_15 )
{
struct V_29 * V_30 = NULL ;
if ( V_15 == NULL )
return V_31 ;
V_30 = (struct V_29 * ) ( V_15 -> V_27 ) ;
return V_30 -> V_32 ;
}
static void
F_15 ( struct V_8 * V_15 ,
enum V_33 V_34 )
{
struct V_29 * V_30 = NULL ;
if ( V_15 == NULL )
goto V_35;
V_30 = (struct V_29 * ) ( V_15 -> V_27 ) ;
switch ( V_34 ) {
case V_36 :
V_15 -> V_22 = V_15 -> V_27 + V_30 -> V_37 ;
V_15 -> V_23 = V_30 -> V_38 ;
break;
case V_39 :
V_15 -> V_22 = V_15 -> V_27 + V_30 -> V_40 ;
V_15 -> V_23 = V_30 -> V_41 ;
break;
case V_42 :
V_15 -> V_22 = V_15 -> V_27 + V_30 -> V_43 ;
V_15 -> V_23 = V_30 -> V_44 ;
break;
case V_45 :
V_15 -> V_22 = V_15 -> V_27 + V_30 -> V_46 ;
V_15 -> V_23 = V_30 -> V_47 ;
break;
default:
break;
}
V_35:
return;
}
static void F_13 ( struct V_8 * V_15 )
{
if ( ! V_15 )
return;
V_16 -= V_15 -> V_21 ;
F_16 ( V_15 ) ;
}
static void *
F_17 ( struct V_8 * V_15 )
{
T_5 * V_48 ;
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
V_51 = F_18 ( V_50 + 1 , V_19 | V_20 ) ;
if ( V_51 == NULL )
return NULL ;
if ( V_50 > 0 )
memcpy ( V_51 , V_48 , V_50 ) ;
( ( T_5 * ) ( V_51 ) ) [ V_50 ] = '\0' ;
return V_51 ;
}
static T_6 F_19 ( struct V_6 * V_7 ,
struct V_53 * V_54 ,
char * V_55 )
{
T_5 V_56 ;
F_20 ( V_57 ,
F_21 ( struct V_58 ,
V_56 ) , & V_56 , sizeof( T_5 ) ) ;
return F_22 ( V_55 , V_59 , L_2 , V_56 ) ;
}
static T_6 F_23 ( struct V_6 * V_7 ,
struct V_53 * V_54 ,
const char * V_55 , T_7 V_60 )
{
T_5 V_56 ;
int V_61 ;
if ( F_24 ( V_55 , 10 , & V_56 ) )
return - V_62 ;
V_61 = F_25 ( V_57 ,
F_21 ( struct V_58 ,
V_56 ) ,
& V_56 , sizeof( T_5 ) ) ;
if ( V_61 )
return V_61 ;
return V_60 ;
}
static T_6 F_26 ( struct V_6 * V_7 ,
struct V_53 * V_54 ,
char * V_55 )
{
struct V_63 V_63 ;
F_20 ( V_57 ,
F_21 ( struct V_58 ,
V_64 ) , & V_63 ,
sizeof( struct V_63 ) ) ;
return F_22 ( V_55 , V_59 , L_2 ,
V_63 . V_65 ) ;
}
static T_6 F_27 ( struct V_6 * V_7 ,
struct V_53 * V_54 ,
const char * V_55 , T_7 V_60 )
{
int V_66 , V_61 ;
struct V_63 V_63 ;
if ( F_28 ( V_55 , 10 , & V_66 ) )
return - V_62 ;
V_63 . V_65 = V_66 ;
V_61 = F_25 ( V_57 ,
F_21 ( struct V_58 ,
V_64 ) , & ( V_63 ) ,
sizeof( struct V_63 ) ) ;
if ( V_61 )
return V_61 ;
return V_60 ;
}
static T_6 F_29 ( struct V_6 * V_7 , struct V_53 * V_54 ,
char * V_55 )
{
T_2 error ;
F_20 ( V_57 ,
F_21 ( struct V_58 ,
V_67 ) ,
& error , sizeof( T_2 ) ) ;
return F_22 ( V_55 , V_59 , L_3 , error ) ;
}
static T_6 F_30 ( struct V_6 * V_7 , struct V_53 * V_54 ,
const char * V_55 , T_7 V_60 )
{
T_2 error ;
int V_61 ;
if ( F_31 ( V_55 , 10 , & error ) )
return - V_62 ;
V_61 = F_25 ( V_57 ,
F_21 ( struct V_58 ,
V_67 ) ,
& error , sizeof( T_2 ) ) ;
if ( V_61 )
return V_61 ;
return V_60 ;
}
static T_6 F_32 ( struct V_6 * V_7 , struct V_53 * V_54 ,
char * V_55 )
{
T_2 V_68 ;
F_20 ( V_57 ,
F_21 ( struct V_58 ,
V_69 ) ,
& V_68 , sizeof( T_2 ) ) ;
return F_22 ( V_55 , V_59 , L_3 , V_68 ) ;
}
static T_6 F_33 ( struct V_6 * V_7 , struct V_53 * V_54 ,
const char * V_55 , T_7 V_60 )
{
T_2 V_68 ;
int V_61 ;
if ( F_31 ( V_55 , 10 , & V_68 ) )
return - V_62 ;
V_61 = F_25 ( V_57 ,
F_21 ( struct V_58 ,
V_69 ) ,
& V_68 , sizeof( T_2 ) ) ;
if ( V_61 )
return V_61 ;
return V_60 ;
}
static T_6 F_34 ( struct V_6 * V_7 ,
struct V_53 * V_54 , char * V_55 )
{
T_8 V_70 ;
F_20 ( V_57 ,
F_21 ( struct V_58 ,
V_71 ) ,
& V_70 , sizeof( T_8 ) ) ;
return F_22 ( V_55 , V_59 , L_4 , V_70 ) ;
}
static T_6 F_35 ( struct V_6 * V_7 ,
struct V_53 * V_54 ,
const char * V_55 , T_7 V_60 )
{
T_8 V_70 ;
int V_61 ;
if ( F_36 ( V_55 , 10 , & V_70 ) )
return - V_62 ;
V_61 = F_25 ( V_57 ,
F_21 ( struct V_58 ,
V_71 ) ,
& V_70 , sizeof( T_8 ) ) ;
if ( V_61 )
return V_61 ;
return V_60 ;
}
static int F_37 ( struct V_6 * V_7 , void * V_27 )
{
struct V_72 * V_73 = F_38 ( V_7 ) ;
struct V_74 * V_32 = (struct V_74 * ) V_27 ;
T_2 V_75 = V_32 -> V_75 ;
T_2 V_76 = V_32 -> V_76 ;
if ( ( V_73 -> V_77 == V_75 ) &&
( V_73 -> V_78 == V_76 ) )
return 1 ;
return 0 ;
}
struct V_72 * F_39 ( T_2 V_75 , T_2 V_76 ,
struct V_72 * V_79 )
{
struct V_6 * V_7 ;
struct V_6 * V_80 = NULL ;
struct V_72 * V_73 = NULL ;
struct V_74 V_32 = {
. V_75 = V_75 ,
. V_76 = V_76
} ;
if ( V_79 )
V_80 = & V_79 -> V_6 ;
V_7 = F_40 ( & V_81 , V_80 , ( void * ) & V_32 ,
F_37 ) ;
if ( V_7 )
V_73 = F_38 ( V_7 ) ;
return V_73 ;
}
static T_5
F_41 ( void )
{
int V_52 ;
T_5 V_82 = 1 ;
for ( V_52 = 0 ; V_52 < V_83 ; V_52 ++ )
V_82 &= V_84 [ V_52 ] ;
return V_82 ;
}
static void
F_42 ( void )
{
int V_52 ;
for ( V_52 = 0 ; V_52 < V_83 ; V_52 ++ )
V_84 [ V_52 ] = 0 ;
}
void
F_43 (
struct V_85 * V_86 ,
struct V_87 * V_88 ,
struct V_89 * V_90 )
{
F_44 ( & V_91 ) ;
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
F_45 ( V_90 , L_5 , L_1 ,
V_95 , NULL ) ;
F_46 ( & V_91 ) ;
}
static void
F_47 ( struct V_96 * V_97 )
{
static int V_98 ;
enum V_99 V_100 = 0 ;
int V_14 = V_101 ;
F_48 ( V_102 , V_103 ) ;
if ( V_98 ) {
V_14 = - V_104 ;
goto V_18;
}
V_98 = 1 ;
F_48 ( V_105 , V_103 ) ;
V_100 =
V_97 -> V_106 . V_107 .
V_100 & V_108 ;
V_100 |= V_109 ;
V_18:
if ( V_97 -> V_110 . V_111 . V_112 )
F_49 ( & V_97 -> V_110 , V_14 , V_100 ) ;
}
static void
F_50 ( struct V_96 * V_113 ,
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
F_51 ( struct V_114 * V_115 , int V_116 )
{
struct V_96 V_122 ;
F_50 ( & V_122 , V_115 , V_116 ) ;
if ( V_122 . V_110 . V_111 . V_123 == 1 )
return;
if ( ! F_52 ( V_57 ,
V_124 , & V_122 ) ) {
return;
}
}
static void
F_49 ( struct V_114 * V_115 ,
int V_116 ,
enum V_99 V_100 )
{
struct V_96 V_122 ;
F_50 ( & V_122 , V_115 , V_116 ) ;
V_122 . V_106 . V_107 . V_100 = V_100 ;
if ( ! F_52 ( V_57 ,
V_124 , & V_122 ) ) {
return;
}
}
static void F_53 (
struct V_114 * V_115 , int V_116 ,
struct V_125 V_126 )
{
struct V_96 V_122 ;
F_50 ( & V_122 , V_115 , V_116 ) ;
V_122 . V_106 . V_127 . V_126 = V_126 ;
V_122 . V_106 . V_127 . V_111 . V_128 = 1 ;
if ( ! F_52 ( V_57 ,
V_124 , & V_122 ) ) {
return;
}
}
static void
F_54 ( enum V_129 V_130 ,
struct V_114 * V_131 ,
int V_116 )
{
if ( V_131 == NULL )
return;
if ( V_131 -> V_32 != ( T_2 ) V_130 )
return;
F_51 ( V_131 , V_116 ) ;
}
static void
F_55 ( enum V_129 V_130 ,
struct V_72 * V_25 , int V_116 ,
struct V_125 V_132 )
{
struct V_96 V_122 ;
T_2 V_75 = V_25 -> V_77 ;
T_2 V_76 = V_25 -> V_78 ;
if ( V_25 -> V_131 == NULL )
return;
if ( V_25 -> V_131 -> V_32 != V_130 )
return;
F_50 ( & V_122 , V_25 -> V_131 , V_116 ) ;
V_122 . V_106 . V_127 . V_75 = V_75 ;
V_122 . V_106 . V_127 . V_76 = V_76 ;
V_122 . V_106 . V_127 . V_126 = V_132 ;
if ( ! F_52 ( V_57 ,
V_124 , & V_122 ) )
return;
}
static void
F_56 ( enum V_129 V_130 ,
struct V_114 * V_131 ,
int V_116 )
{
if ( V_131 == NULL )
return;
if ( V_131 -> V_32 != ( T_2 ) V_130 )
return;
F_51 ( V_131 , V_116 ) ;
}
static void
F_57 ( struct V_72 * V_133 ,
T_2 V_106 , struct V_114 * V_115 ,
int V_116 , bool V_134 )
{
bool V_135 = false ;
struct V_114 * V_136 = NULL ;
if ( ! V_133 ) {
V_136 = V_115 ;
goto V_137;
}
if ( V_133 -> V_131 ) {
V_116 = - V_138 ;
V_136 = V_133 -> V_131 ;
goto V_137;
}
if ( V_134 ) {
V_136 = F_6 ( sizeof( * V_136 ) , V_19 ) ;
if ( ! V_136 ) {
V_116 = - V_139 ;
goto V_137;
}
memcpy ( V_136 , V_115 ,
sizeof( struct V_114 ) ) ;
V_133 -> V_131 = V_136 ;
}
F_44 ( & V_91 ) ;
if ( V_116 == V_101 ) {
switch ( V_106 ) {
case V_140 :
if ( V_92 . V_141 ) {
(* V_92 . V_141 ) ( V_133 ) ;
V_135 = true ;
}
break;
case V_142 :
if ( V_92 . V_143 ) {
(* V_92 . V_143 ) ( V_133 ) ;
V_135 = true ;
}
break;
}
}
V_137:
if ( V_135 )
;
else
F_54 ( V_106 , V_136 , V_116 ) ;
F_46 ( & V_91 ) ;
}
static void
F_58 ( struct V_72 * V_144 ,
struct V_125 V_126 , T_2 V_106 ,
struct V_114 * V_115 , int V_116 ,
bool V_134 , bool V_145 )
{
struct V_85 * V_86 ;
bool V_135 = false ;
struct V_114 * V_136 = NULL ;
V_86 = & V_92 ;
if ( ! V_144 ) {
V_136 = V_115 ;
goto V_137;
}
if ( V_144 -> V_131 ) {
V_116 = - V_138 ;
V_136 = V_144 -> V_131 ;
goto V_137;
}
if ( V_134 ) {
V_136 = F_6 ( sizeof( * V_136 ) , V_19 ) ;
if ( ! V_136 ) {
V_116 = - V_139 ;
goto V_137;
}
memcpy ( V_136 , V_115 ,
sizeof( struct V_114 ) ) ;
V_144 -> V_131 = V_136 ;
}
F_44 ( & V_91 ) ;
if ( V_116 >= 0 ) {
switch ( V_106 ) {
case V_146 :
if ( V_86 -> V_147 ) {
(* V_86 -> V_147 ) ( V_144 ) ;
V_135 = true ;
}
break;
case V_148 :
if ( V_126 . V_149 == V_150 . V_149 &&
V_126 . V_151 ==
V_150 . V_151 ) {
if ( V_86 -> V_152 ) {
(* V_86 -> V_152 ) ( V_144 ) ;
V_135 = true ;
}
}
else if ( V_126 . V_149 == V_153 . V_149 &&
V_126 . V_151 ==
V_153 . V_151 ) {
if ( V_86 -> V_154 ) {
(* V_86 -> V_154 ) ( V_144 ) ;
V_135 = true ;
}
}
break;
case V_155 :
if ( V_86 -> V_156 ) {
(* V_86 -> V_156 ) ( V_144 ) ;
V_135 = true ;
}
break;
}
}
V_137:
if ( V_135 )
;
else
F_56 ( V_106 , V_136 , V_116 ) ;
F_46 ( & V_91 ) ;
}
static void
V_141 ( struct V_96 * V_97 )
{
struct V_157 * V_106 = & V_97 -> V_106 ;
T_2 V_75 = V_106 -> V_158 . V_75 ;
int V_14 = V_101 ;
struct V_72 * V_133 ;
struct V_159 * V_159 ;
V_133 = F_39 ( V_75 , V_160 , NULL ) ;
if ( V_133 && ( V_133 -> V_126 . V_161 == 1 ) ) {
F_59 ( V_162 , V_75 ,
V_163 ) ;
V_14 = - V_104 ;
goto V_18;
}
V_133 = F_6 ( sizeof( * V_133 ) , V_19 ) ;
if ( ! V_133 ) {
F_59 ( V_162 , V_75 ,
V_163 ) ;
V_14 = - V_139 ;
goto V_18;
}
F_60 ( & V_133 -> V_164 ) ;
V_133 -> V_77 = V_75 ;
V_133 -> V_78 = V_160 ;
F_59 ( V_165 , V_75 , V_103 ) ;
V_159 = F_61 ( V_106 -> V_158 . V_166 ,
V_106 -> V_158 . V_167 ,
V_19 ,
V_106 -> V_158 . V_168 ) ;
if ( ! V_159 ) {
F_59 ( V_162 , V_75 ,
V_163 ) ;
V_14 = - V_139 ;
F_16 ( V_133 ) ;
V_133 = NULL ;
goto V_18;
}
V_133 -> V_159 = V_159 ;
F_59 ( V_169 , V_75 , V_103 ) ;
V_18:
F_57 ( V_133 , V_140 , & V_97 -> V_110 ,
V_14 , V_97 -> V_110 . V_111 . V_112 == 1 ) ;
}
static void
V_143 ( struct V_96 * V_97 )
{
struct V_157 * V_106 = & V_97 -> V_106 ;
T_2 V_75 = V_106 -> V_170 . V_75 ;
struct V_72 * V_133 ;
int V_14 = V_101 ;
V_133 = F_39 ( V_75 , V_160 , NULL ) ;
if ( ! V_133 )
V_14 = - V_171 ;
else if ( V_133 -> V_126 . V_161 == 0 )
V_14 = - V_104 ;
F_57 ( V_133 , V_142 , & V_97 -> V_110 ,
V_14 , V_97 -> V_110 . V_111 . V_112 == 1 ) ;
}
static void
F_62 ( struct V_96 * V_97 ,
struct V_8 * V_172 )
{
struct V_157 * V_106 = & V_97 -> V_106 ;
T_2 V_75 ;
struct V_72 * V_133 ;
int V_14 = V_101 ;
V_75 = V_106 -> V_173 . V_75 ;
F_59 ( V_174 , V_75 ,
V_103 ) ;
V_133 = F_39 ( V_75 , V_160 , NULL ) ;
if ( ! V_133 ) {
F_59 ( V_175 , V_75 ,
V_163 ) ;
V_14 = - V_171 ;
} else if ( V_133 -> V_126 . V_161 == 0 ) {
F_59 ( V_175 , V_75 ,
V_163 ) ;
V_14 = - V_171 ;
} else if ( V_133 -> V_131 != NULL ) {
F_59 ( V_175 , V_75 ,
V_163 ) ;
V_14 = - V_138 ;
} else {
F_63 ( V_133 -> V_159 ,
V_106 -> V_173 . V_176 ) ;
V_133 -> V_177 = F_14 ( V_172 ) ;
F_15 ( V_172 , V_45 ) ;
V_133 -> V_178 = F_17 ( V_172 ) ;
F_59 ( V_179 , V_75 ,
V_103 ) ;
}
F_57 ( V_133 , V_180 , & V_97 -> V_110 ,
V_14 , V_97 -> V_110 . V_111 . V_112 == 1 ) ;
}
static void
F_64 ( struct V_96 * V_97 )
{
struct V_157 * V_106 = & V_97 -> V_106 ;
T_2 V_75 = V_106 -> V_181 . V_75 ;
T_2 V_76 = V_106 -> V_181 . V_76 ;
struct V_72 * V_144 = NULL ;
struct V_72 * V_133 ;
struct V_159 * V_159 ;
int V_14 = V_101 ;
V_133 = F_39 ( V_75 , V_160 , NULL ) ;
if ( ! V_133 ) {
F_65 ( V_182 , V_76 , V_75 ,
V_163 ) ;
V_14 = - V_171 ;
goto V_18;
}
if ( V_133 -> V_126 . V_161 == 0 ) {
F_65 ( V_182 , V_76 , V_75 ,
V_163 ) ;
V_14 = - V_171 ;
goto V_18;
}
V_144 = F_39 ( V_75 , V_76 , NULL ) ;
if ( V_144 && ( V_144 -> V_126 . V_161 == 1 ) ) {
F_65 ( V_182 , V_76 , V_75 ,
V_163 ) ;
V_14 = - V_104 ;
goto V_18;
}
V_144 = F_6 ( sizeof( * V_144 ) , V_19 ) ;
if ( ! V_144 ) {
F_65 ( V_182 , V_76 , V_75 ,
V_163 ) ;
V_14 = - V_139 ;
goto V_18;
}
V_144 -> V_77 = V_75 ;
V_144 -> V_78 = V_76 ;
V_144 -> V_183 = V_106 -> V_181 . V_184 ;
V_144 -> V_6 . V_185 = & V_133 -> V_6 ;
F_65 ( V_186 , V_76 , V_75 ,
V_103 ) ;
V_159 = F_61 ( V_106 -> V_181 . V_166 ,
V_106 -> V_181 . V_167 ,
V_19 ,
V_106 -> V_181 . V_187 ) ;
if ( ! V_159 ) {
F_65 ( V_182 , V_76 , V_75 ,
V_163 ) ;
V_14 = - V_139 ;
F_16 ( V_144 ) ;
V_144 = NULL ;
goto V_18;
}
V_144 -> V_159 = V_159 ;
V_144 -> V_188 = V_106 -> V_181 . V_187 ;
F_65 ( V_189 , V_76 , V_75 ,
V_103 ) ;
V_18:
F_58 ( V_144 , V_150 ,
V_146 , & V_97 -> V_110 , V_14 ,
V_97 -> V_110 . V_111 . V_112 == 1 , 1 ) ;
}
static void
F_66 ( struct V_96 * V_97 )
{
struct V_157 * V_106 = & V_97 -> V_106 ;
T_2 V_75 = V_106 -> V_127 . V_75 ;
T_2 V_76 = V_106 -> V_127 . V_76 ;
struct V_125 V_126 = V_106 -> V_127 . V_126 ;
struct V_72 * V_144 ;
int V_14 = V_101 ;
V_144 = F_39 ( V_75 , V_76 , NULL ) ;
if ( ! V_144 ) {
F_65 ( V_190 , V_76 , V_75 ,
V_163 ) ;
V_14 = - V_191 ;
} else if ( V_144 -> V_126 . V_161 == 0 ) {
F_65 ( V_190 , V_76 , V_75 ,
V_163 ) ;
V_14 = - V_191 ;
}
if ( ( V_14 >= V_101 ) && V_144 )
F_58 ( V_144 , V_126 ,
V_148 , & V_97 -> V_110 , V_14 ,
V_97 -> V_110 . V_111 . V_112 == 1 , 1 ) ;
}
static void
F_67 ( struct V_96 * V_97 )
{
struct V_157 * V_106 = & V_97 -> V_106 ;
T_2 V_75 = V_106 -> V_192 . V_75 ;
T_2 V_76 = V_106 -> V_192 . V_76 ;
struct V_72 * V_144 ;
int V_14 = V_101 ;
V_144 = F_39 ( V_75 , V_76 , NULL ) ;
if ( ! V_144 )
V_14 = - V_191 ;
else if ( V_144 -> V_126 . V_161 == 0 )
V_14 = - V_104 ;
if ( ( V_14 >= V_101 ) && V_144 )
F_58 ( V_144 , V_150 ,
V_155 , & V_97 -> V_110 , V_14 ,
V_97 -> V_110 . V_111 . V_112 == 1 , 1 ) ;
}
static int
F_68 ( T_1 V_193 , T_1 V_194 , T_2 V_10 ,
struct V_195 * V_196 )
{
T_5 T_3 * V_197 = NULL ;
int V_14 = V_101 ;
if ( ! V_196 ) {
V_14 = - V_198 ;
goto V_18;
}
memset ( V_196 , 0 , sizeof( struct V_195 ) ) ;
if ( ( V_194 == 0 ) || ( V_10 == 0 ) ) {
V_14 = - V_198 ;
goto V_18;
}
V_197 = F_10 ( V_193 + V_194 , V_10 ) ;
if ( ! V_197 ) {
V_14 = - V_199 ;
goto V_18;
}
V_196 -> V_194 = V_194 ;
V_196 -> V_10 = V_10 ;
V_196 -> V_200 = V_197 ;
V_18:
if ( V_14 < 0 ) {
if ( V_197 ) {
F_69 ( V_197 ) ;
V_197 = NULL ;
}
}
return V_14 ;
}
static void
F_70 ( struct V_195 * V_196 )
{
if ( V_196 -> V_200 ) {
F_69 ( V_196 -> V_200 ) ;
V_196 -> V_200 = NULL ;
}
memset ( V_196 , 0 , sizeof( struct V_195 ) ) ;
}
static void
F_71 ( void )
{
T_1 V_193 = F_72 ( V_57 ) ;
T_1 V_201 = 0 ;
T_2 V_117 = 0 ;
if ( F_20 ( V_57 ,
F_21 ( struct V_58 ,
V_202 ) ,
& V_201 , sizeof( V_201 ) ) < 0 ) {
F_48 ( V_203 ,
V_163 ) ;
return;
}
if ( F_20 ( V_57 ,
F_21 ( struct V_58 ,
V_204 ) ,
& V_117 , sizeof( V_117 ) ) < 0 ) {
F_48 ( V_203 ,
V_163 ) ;
return;
}
F_68 ( V_193 ,
V_201 , V_117 ,
& V_205 ) ;
}
static int
F_73 ( void )
{
F_74 ( & V_206 . V_7 . V_207 , V_208 ) ;
return V_101 ;
}
static int
F_75 ( void )
{
char V_209 [ 20 ] ;
char * V_210 [] = { V_209 , NULL } ;
sprintf ( V_209 , L_6 , 1 ) ;
F_76 ( & V_206 . V_7 . V_207 , V_211 ,
V_210 ) ;
return V_101 ;
}
static int
F_77 ( void )
{
F_74 ( & V_206 . V_7 . V_207 , V_212 ) ;
return V_101 ;
}
static void
F_78 ( struct V_114 * V_115 )
{
int V_14 = F_73 () ;
if ( V_14 != V_101 )
V_14 = - V_14 ;
if ( V_115 -> V_111 . V_112 && ! V_213 )
F_51 ( V_115 , V_14 ) ;
if ( V_115 -> V_111 . V_112 && V_213 ) {
V_214 = * V_115 ;
}
}
static void
F_79 ( struct V_114 * V_115 )
{
int V_14 = F_75 () ;
if ( V_14 != V_101 )
V_14 = - V_14 ;
if ( V_115 -> V_111 . V_112 )
F_51 ( V_115 , V_14 ) ;
}
static void
F_80 ( struct V_114 * V_115 )
{
int V_14 = F_77 () ;
if ( V_14 != V_101 )
V_14 = - V_14 ;
if ( V_115 -> V_111 . V_112 )
F_51 ( V_115 , V_14 ) ;
}
static bool
F_81 ( struct V_96 * V_113 )
{
if ( F_82 ( V_57 ,
V_215 , V_113 ) ) {
if ( V_113 -> V_110 . V_111 . V_123 == 1 )
return false ;
return true ;
}
return false ;
}
static int
F_83 ( void )
{
static T_9 V_32 = F_84 ( 0 ) ;
return F_85 ( & V_32 ) ;
}
static unsigned long
F_86 ( void )
{
return V_216 + F_87 ( V_217 ) ;
}
static struct V_218 *
F_88 ( struct V_96 * V_113 )
{
struct V_218 * V_219 ;
V_219 = F_18 ( sizeof( * V_219 ) , V_19 | V_20 ) ;
if ( ! V_219 )
return NULL ;
V_219 -> V_32 = F_83 () ;
V_219 -> V_220 = F_86 () ;
V_219 -> V_113 = * V_113 ;
return V_219 ;
}
static void
F_89 ( struct V_218 * V_219 )
{
F_16 ( V_219 ) ;
}
static void
F_90 ( struct V_218 * V_219 )
{
struct V_157 * V_106 = & V_219 -> V_113 . V_106 ;
char V_221 [ 40 ] , V_222 [ 40 ] , V_223 [ 40 ] , V_224 [ 40 ] , V_225 [ 40 ] ,
V_226 [ 40 ] ;
char * V_210 [] = {
V_221 , V_222 , V_223 , V_224 , V_225 , V_226 , NULL
} ;
sprintf ( V_221 , L_7 ) ;
sprintf ( V_222 , L_8 , V_219 -> V_32 ) ;
sprintf ( V_223 , L_9 ,
V_106 -> V_127 . V_126 . V_227 ) ;
sprintf ( V_224 , L_10 ,
V_106 -> V_127 . V_75 ) ;
sprintf ( V_225 , L_11 ,
V_106 -> V_127 . V_76 >> 3 ) ;
sprintf ( V_226 , L_12 ,
V_106 -> V_127 . V_76 & 0x7 ) ;
F_76 ( & V_206 . V_7 . V_207 , V_211 ,
V_210 ) ;
}
static void
F_91 ( void )
{
struct V_228 * V_229 ;
struct V_228 * V_230 ;
F_92 ( & V_231 ) ;
F_93 (pos, tmp, &parahotplug_request_list) {
struct V_218 * V_219 =
F_94 ( V_229 , struct V_218 , V_232 ) ;
if ( ! F_95 ( V_216 , V_219 -> V_220 ) )
continue;
F_96 ( V_229 ) ;
if ( V_219 -> V_113 . V_110 . V_111 . V_112 )
F_53 (
& V_219 -> V_113 . V_110 ,
V_233 ,
V_219 -> V_113 . V_106 . V_127 . V_126 ) ;
F_89 ( V_219 ) ;
}
F_97 ( & V_231 ) ;
}
static int
F_98 ( int V_32 , T_8 V_227 )
{
struct V_228 * V_229 ;
struct V_228 * V_230 ;
F_92 ( & V_231 ) ;
F_93 (pos, tmp, &parahotplug_request_list) {
struct V_218 * V_219 =
F_94 ( V_229 , struct V_218 , V_232 ) ;
if ( V_219 -> V_32 == V_32 ) {
F_96 ( V_229 ) ;
F_97 ( & V_231 ) ;
V_219 -> V_113 . V_106 . V_127 . V_126 . V_227 = V_227 ;
if ( V_219 -> V_113 . V_110 . V_111 . V_112 )
F_53 (
& V_219 -> V_113 . V_110 , V_101 ,
V_219 -> V_113 . V_106 . V_127 . V_126 ) ;
F_89 ( V_219 ) ;
return 0 ;
}
}
F_97 ( & V_231 ) ;
return - 1 ;
}
static void
F_99 ( struct V_96 * V_97 )
{
struct V_218 * V_219 ;
V_219 = F_88 ( V_97 ) ;
if ( ! V_219 )
return;
if ( V_97 -> V_106 . V_127 . V_126 . V_227 ) {
F_90 ( V_219 ) ;
F_53 ( & V_97 -> V_110 ,
V_101 ,
V_97 -> V_106 . V_127 . V_126 ) ;
F_89 ( V_219 ) ;
} else {
F_92 ( & V_231 ) ;
F_100 ( & V_219 -> V_232 , & V_234 ) ;
F_97 ( & V_231 ) ;
F_90 ( V_219 ) ;
}
}
static bool
F_101 ( struct V_96 V_97 , T_1 V_166 )
{
struct V_157 * V_106 = & V_97 . V_106 ;
T_1 V_235 ;
T_2 V_236 ;
struct V_8 * V_172 = NULL ;
bool V_237 ;
struct V_96 V_238 ;
V_237 = ( V_97 . V_110 . V_111 . V_123 == 1 ) ;
if ( V_166 == 0 )
return true ;
V_235 = V_166 + V_97 . V_110 . V_118 ;
V_236 = V_97 . V_110 . V_117 ;
if ( V_235 && V_236 ) {
bool V_12 = false ;
V_172 =
F_5 ( V_235 , V_236 ,
V_237 , & V_12 ) ;
if ( ! V_172 && V_12 )
return false ;
}
if ( ! V_237 ) {
F_50 ( & V_238 , & V_97 . V_110 ,
V_101 ) ;
if ( V_57 )
F_52 ( V_57 ,
V_239 ,
& V_238 ) ;
}
switch ( V_97 . V_110 . V_32 ) {
case V_240 :
F_47 ( & V_97 ) ;
break;
case V_140 :
V_141 ( & V_97 ) ;
break;
case V_142 :
V_143 ( & V_97 ) ;
break;
case V_180 :
F_62 ( & V_97 , V_172 ) ;
break;
case V_146 :
F_64 ( & V_97 ) ;
break;
case V_148 :
if ( V_106 -> V_127 . V_111 . V_128 ) {
F_99 ( & V_97 ) ;
} else {
F_66 ( & V_97 ) ;
V_241 = V_97 . V_106 ;
break;
}
break;
case V_155 :
F_67 ( & V_97 ) ;
break;
case V_242 :
if ( V_97 . V_110 . V_111 . V_112 )
F_51 ( & V_97 . V_110 , V_101 ) ;
break;
case V_243 :
F_78 ( & V_97 . V_110 ) ;
break;
case V_244 :
F_79 ( & V_97 . V_110 ) ;
break;
case V_245 :
F_80 ( & V_97 . V_110 ) ;
break;
default:
if ( V_97 . V_110 . V_111 . V_112 )
F_51 ( & V_97 . V_110 ,
- V_246 ) ;
break;
}
if ( V_172 ) {
F_13 ( V_172 ) ;
V_172 = NULL ;
}
return true ;
}
static inline unsigned int
F_102 ( T_1 * V_247 , T_2 * V_248 )
{
struct V_249 V_250 ;
int V_251 = V_252 ;
T_1 V_253 ;
V_253 = F_7 ( & V_250 ) ;
F_103 ( V_254 , V_253 , V_251 ) ;
if ( F_104 ( V_251 ) ) {
* V_247 = V_250 . V_255 ;
* V_248 = V_250 . V_167 ;
}
return V_251 ;
}
static T_1 F_105 ( void )
{
T_1 V_9 = 0 ;
T_2 V_256 = 0 ;
if ( ! F_104 ( F_102 ( & V_9 , & V_256 ) ) )
return 0 ;
return V_9 ;
}
static void
F_106 ( struct V_257 * V_258 )
{
struct V_96 V_97 ;
bool V_259 = false ;
bool V_260 = false ;
static T_1 V_261 ;
if ( V_262 && ! V_93 )
goto V_18;
V_261 ++ ;
if ( V_261 >= 250 )
;
else
goto V_18;
if ( V_213 &&
( V_214 . V_32 != V_263 ) ) {
if ( F_41 () == 1 ) {
F_51 ( & V_214 , 0 ) ;
F_42 () ;
memset ( & V_214 , 0 ,
sizeof( struct V_114 ) ) ;
}
}
while ( F_82 ( V_57 ,
V_264 ,
& V_97 ) )
;
if ( ! V_259 ) {
if ( V_265 ) {
V_97 = V_266 ;
V_265 = false ;
V_259 = true ;
} else {
V_259 = F_81 ( & V_97 ) ;
}
}
V_260 = false ;
while ( V_259 && ( ! V_260 ) ) {
V_267 = V_216 ;
if ( F_101 ( V_97 ,
F_72
( V_57 ) ) )
V_259 = F_81 ( & V_97 ) ;
else {
V_260 = true ;
V_266 = V_97 ;
V_265 = true ;
}
}
F_91 () ;
V_18:
if ( F_107 ( V_216 ,
V_267 + ( V_268 * V_269 ) ) ) {
if ( V_270 != V_271 )
V_270 = V_271 ;
} else {
if ( V_270 != V_272 )
V_270 = V_272 ;
}
F_108 ( V_273 ,
& V_274 , V_270 ) ;
}
static void
F_109 ( struct V_257 * V_258 )
{
struct V_96 V_275 ;
struct V_96 V_276 ;
struct V_96 V_113 ;
T_2 V_277 ;
T_8 V_278 ;
if ( V_262 && ! V_93 )
goto V_18;
F_48 ( V_279 , V_103 ) ;
V_113 . V_110 . V_32 = V_240 ;
V_113 . V_106 . V_107 . V_280 = 23 ;
V_113 . V_106 . V_107 . V_281 = 0 ;
F_47 ( & V_113 ) ;
if ( F_20 ( V_57 ,
F_21 ( struct V_58 ,
V_282 ) ,
& V_278 , sizeof( T_8 ) ) < 0 ) {
F_48 ( V_283 ,
V_163 ) ;
return;
}
if ( V_278 != V_284 ) {
F_59 ( V_285 ,
V_278 ,
V_163 ) ;
return;
}
if ( F_20 ( V_57 ,
F_21 ( struct V_58 ,
V_286 ) ,
& V_277 , sizeof( T_2 ) ) < 0 ) {
F_48 ( V_283 ,
V_163 ) ;
return;
}
if ( F_20 ( V_57 ,
V_277 ,
& V_275 ,
sizeof( struct V_96 ) ) < 0 ) {
F_48 ( V_287 ,
V_163 ) ;
return;
}
if ( F_20 ( V_57 ,
V_277 +
sizeof( struct V_96 ) ,
& V_276 ,
sizeof( struct V_96 ) ) < 0 ) {
F_48 ( V_288 ,
V_163 ) ;
return;
}
if ( V_275 . V_106 . V_158 . V_166 ) {
V_141 ( & V_275 ) ;
} else {
F_48 ( V_289 ,
V_163 ) ;
return;
}
if ( V_276 . V_106 . V_181 . V_166 ) {
F_64 ( & V_276 ) ;
} else {
F_48 ( V_290 ,
V_163 ) ;
return;
}
F_48 ( V_291 , V_103 ) ;
return;
V_18:
V_270 = V_271 ;
F_108 ( V_273 ,
& V_274 , V_270 ) ;
}
static void
F_110 ( struct V_72 * V_133 , int V_116 )
{
if ( V_116 >= 0 )
V_133 -> V_126 . V_161 = 1 ;
F_54 ( V_140 , V_133 -> V_131 ,
V_116 ) ;
F_16 ( V_133 -> V_131 ) ;
V_133 -> V_131 = NULL ;
}
static void
F_111 ( struct V_72 * V_133 , int V_116 )
{
F_54 ( V_142 , V_133 -> V_131 ,
V_116 ) ;
F_16 ( V_133 -> V_131 ) ;
V_133 -> V_131 = NULL ;
}
static void
F_112 ( struct V_72 * V_144 , int V_116 )
{
if ( V_116 >= 0 )
V_144 -> V_126 . V_161 = 1 ;
F_56 ( V_146 , V_144 -> V_131 ,
V_116 ) ;
F_16 ( V_144 -> V_131 ) ;
}
static void
F_113 ( struct V_72 * V_144 , int V_116 )
{
F_56 ( V_155 , V_144 -> V_131 ,
V_116 ) ;
F_16 ( V_144 -> V_131 ) ;
V_144 -> V_131 = NULL ;
}
static void
F_114 ( struct V_72 * V_144 ,
int V_116 )
{
F_55 ( V_148 ,
V_144 , V_116 ,
V_153 ) ;
F_16 ( V_144 -> V_131 ) ;
V_144 -> V_131 = NULL ;
}
static void
F_115 ( struct V_72 * V_144 , int V_116 )
{
F_55 ( V_148 ,
V_144 , V_116 ,
V_150 ) ;
F_16 ( V_144 -> V_131 ) ;
V_144 -> V_131 = NULL ;
}
static T_6 F_116 ( struct V_6 * V_7 ,
struct V_53 * V_54 ,
const char * V_55 , T_7 V_60 )
{
char V_292 [ 64 ] ;
if ( sscanf ( V_55 , L_13 , V_292 ) != 1 )
return - V_62 ;
if ( ! strcmp ( V_292 , L_14 ) ) {
V_84 [ 0 ] = 1 ;
return V_60 ;
} else if ( ! strcmp ( V_292 , L_15 ) ) {
V_84 [ 1 ] = 1 ;
return V_60 ;
}
return - V_62 ;
}
static T_6 F_117 ( struct V_6 * V_7 ,
struct V_53 * V_54 ,
const char * V_55 , T_7 V_60 )
{
unsigned int V_32 ;
if ( F_118 ( V_55 , 10 , & V_32 ) )
return - V_62 ;
F_98 ( V_32 , 0 ) ;
return V_60 ;
}
static T_6 F_119 ( struct V_6 * V_7 ,
struct V_53 * V_54 ,
const char * V_55 , T_7 V_60 )
{
unsigned int V_32 ;
if ( F_118 ( V_55 , 10 , & V_32 ) )
return - V_62 ;
F_98 ( V_32 , 1 ) ;
return V_60 ;
}
static int
F_120 ( struct V_2 * V_2 , struct V_293 * V_294 )
{
unsigned long V_253 = 0 ;
unsigned long V_194 = V_294 -> V_295 << V_296 ;
T_1 V_9 = 0 ;
if ( V_194 & ( V_59 - 1 ) )
return - V_297 ;
switch ( V_194 ) {
case V_298 :
V_294 -> V_299 |= V_300 ;
if ( ! * V_301 )
return - V_297 ;
F_20 ( * V_301 ,
F_21 ( struct V_58 ,
V_302 ) ,
& V_9 , sizeof( V_9 ) ) ;
if ( ! V_9 )
return - V_297 ;
V_253 = ( unsigned long ) V_9 ;
if ( F_121 ( V_294 , V_294 -> V_303 ,
V_253 >> V_296 ,
V_294 -> V_304 - V_294 -> V_303 ,
( V_294 -> V_305 ) ) ) {
return - V_306 ;
}
break;
default:
return - V_297 ;
}
return 0 ;
}
static inline T_10 F_122 ( void )
{
T_1 V_251 = V_252 ;
T_1 V_253 = 0 ;
F_103 ( V_307 , V_253 ,
V_251 ) ;
return V_251 ;
}
static inline int F_123 ( T_1 V_308 )
{
int V_251 = V_252 ;
F_103 ( V_309 , V_308 , V_251 ) ;
return V_251 ;
}
static long F_124 ( struct V_2 * V_2 , unsigned int V_106 ,
unsigned long V_310 )
{
T_10 V_308 ;
T_10 V_311 ;
switch ( V_106 ) {
case V_307 :
V_311 = F_122 () ;
if ( F_125 ( ( void V_312 * ) V_310 , & V_311 ,
sizeof( V_311 ) ) ) {
return - V_313 ;
}
return 0 ;
case V_309 :
if ( F_126 ( & V_308 , ( void V_312 * ) V_310 ,
sizeof( V_308 ) ) ) {
return - V_313 ;
}
return F_123 ( V_308 ) ;
default:
return - V_313 ;
}
}
static int
F_127 ( T_11 V_314 , struct V_159 * * V_57 )
{
int V_14 = 0 ;
V_301 = V_57 ;
F_128 ( & V_315 , & V_316 ) ;
V_315 . V_317 = V_318 ;
if ( F_129 ( V_314 ) == 0 ) {
V_14 = F_130 ( & V_314 , 0 , 1 , L_1 ) ;
if ( V_14 < 0 )
return V_14 ;
} else {
V_14 = F_131 ( V_314 , 1 , L_1 ) ;
if ( V_14 < 0 )
return V_14 ;
}
V_14 = F_132 ( & V_315 , F_133 ( F_129 ( V_314 ) , 0 ) , 1 ) ;
if ( V_14 < 0 ) {
F_134 ( V_314 , 1 ) ;
return V_14 ;
}
return 0 ;
}
static int
F_135 ( struct V_319 * V_319 )
{
int V_14 = 0 ;
T_1 V_9 ;
int V_320 = sizeof( struct V_58 ) ;
T_4 V_321 = V_322 ;
V_9 = F_105 () ;
if ( ! V_9 )
return - V_4 ;
memset ( & V_92 , 0 , sizeof( V_92 ) ) ;
memset ( & V_205 , 0 , sizeof( V_205 ) ) ;
V_57 = F_136 ( V_9 , V_320 ,
V_19 , V_321 ) ;
if ( F_137 (
F_138 ( V_57 ) ) ) {
F_71 () ;
} else {
F_139 ( V_57 ) ;
V_57 = NULL ;
return - V_4 ;
}
V_314 = F_133 ( V_323 , 0 ) ;
V_14 = F_127 ( V_314 , & V_57 ) ;
if ( V_14 < 0 ) {
F_48 ( V_324 , V_325 ) ;
goto V_18;
}
memset ( & V_214 , 0 , sizeof( struct V_114 ) ) ;
if ( F_140 () )
F_141 ( & V_274 ,
F_109 ) ;
else
F_141 ( & V_274 ,
F_106 ) ;
V_273 =
F_142 ( L_16 ) ;
if ( ! V_273 ) {
F_48 ( V_326 ,
V_325 ) ;
V_14 = - V_327 ;
goto V_18;
}
V_267 = V_216 ;
V_270 = V_272 ;
V_14 = F_108 ( V_273 ,
& V_274 , V_270 ) ;
if ( V_14 < 0 ) {
F_48 ( V_328 ,
V_325 ) ;
goto V_18;
}
V_206 . V_7 . V_329 = V_314 ;
if ( F_143 ( & V_206 ) < 0 ) {
F_48 ( V_330 , V_325 ) ;
V_14 = - 1 ;
goto V_18;
}
F_48 ( V_331 , V_103 ) ;
V_14 = F_144 () ;
V_18:
if ( V_14 ) {
F_59 ( V_324 , V_14 ,
V_163 ) ;
}
return V_14 ;
}
static void
F_145 ( T_11 V_314 )
{
if ( V_315 . V_332 )
F_146 ( & V_315 ) ;
V_315 . V_332 = NULL ;
F_134 ( V_314 , 1 ) ;
}
static int
F_147 ( struct V_319 * V_319 )
{
F_48 ( V_333 , V_103 ) ;
F_148 () ;
F_149 ( & V_274 ) ;
F_150 ( V_273 ) ;
F_151 ( V_273 ) ;
V_273 = NULL ;
F_70 ( & V_205 ) ;
memset ( & V_214 , 0 , sizeof( struct V_114 ) ) ;
F_139 ( V_57 ) ;
F_145 ( V_206 . V_7 . V_329 ) ;
F_152 ( & V_206 ) ;
F_48 ( V_333 , V_103 ) ;
return 0 ;
}
static T_12 T_13 F_153 ( void )
{
unsigned int V_334 , V_335 , V_336 , V_337 ;
if ( V_338 ) {
F_154 ( V_339 , & V_334 , & V_335 , & V_336 , & V_337 ) ;
return ( V_335 == V_340 ) &&
( V_336 == V_341 ) &&
( V_337 == V_342 ) ;
} else {
return 0 ;
}
}
static int F_155 ( void )
{
int V_251 ;
if ( ! F_153 () )
return - V_4 ;
V_251 = F_156 ( & V_343 ) ;
if ( V_251 )
return - V_4 ;
F_157 ( L_17 ) ;
return 0 ;
}
static void F_158 ( void )
{
F_159 ( & V_343 ) ;
}

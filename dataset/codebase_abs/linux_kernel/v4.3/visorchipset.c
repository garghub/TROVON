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
void * V_28 ;
if ( ! F_9 ( V_9 , V_10 , L_1 ) ) {
V_14 = NULL ;
goto V_18;
}
V_28 = F_10 ( V_9 , V_10 , V_29 ) ;
if ( ! V_28 ) {
F_11 ( V_9 , V_10 ) ;
V_14 = NULL ;
goto V_18;
}
memcpy ( V_15 -> V_27 , V_28 , V_10 ) ;
F_11 ( V_9 , V_10 ) ;
F_12 ( V_28 ) ;
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
static T_3
F_14 ( struct V_8 * V_15 )
{
struct V_30 * V_31 = NULL ;
if ( V_15 == NULL )
return V_32 ;
V_31 = (struct V_30 * ) ( V_15 -> V_27 ) ;
return V_31 -> V_33 ;
}
static void
F_15 ( struct V_8 * V_15 ,
enum V_34 V_35 )
{
struct V_30 * V_31 = NULL ;
if ( V_15 == NULL )
goto V_36;
V_31 = (struct V_30 * ) ( V_15 -> V_27 ) ;
switch ( V_35 ) {
case V_37 :
V_15 -> V_22 = V_15 -> V_27 + V_31 -> V_38 ;
V_15 -> V_23 = V_31 -> V_39 ;
break;
case V_40 :
V_15 -> V_22 = V_15 -> V_27 + V_31 -> V_41 ;
V_15 -> V_23 = V_31 -> V_42 ;
break;
case V_43 :
V_15 -> V_22 = V_15 -> V_27 + V_31 -> V_44 ;
V_15 -> V_23 = V_31 -> V_45 ;
break;
case V_46 :
V_15 -> V_22 = V_15 -> V_27 + V_31 -> V_47 ;
V_15 -> V_23 = V_31 -> V_48 ;
break;
default:
break;
}
V_36:
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
T_4 * V_49 ;
unsigned long V_50 ;
int V_51 = - 1 ;
void * V_52 = NULL ;
int V_53 ;
if ( ! V_15 )
return NULL ;
V_49 = V_15 -> V_22 ;
V_50 = V_15 -> V_23 ;
if ( V_50 == 0 )
return NULL ;
if ( ! V_49 )
return NULL ;
for ( V_53 = 0 , V_51 = - 1 ; V_53 < V_50 ; V_53 ++ )
if ( V_49 [ V_53 ] == '\0' ) {
V_51 = V_53 ;
break;
}
if ( V_51 < 0 )
V_51 = V_50 ;
V_52 = F_18 ( V_51 + 1 , V_19 | V_20 ) ;
if ( V_52 == NULL )
return NULL ;
if ( V_51 > 0 )
memcpy ( V_52 , V_49 , V_51 ) ;
( ( T_4 * ) ( V_52 ) ) [ V_51 ] = '\0' ;
return V_52 ;
}
static T_5 F_19 ( struct V_6 * V_7 ,
struct V_54 * V_55 ,
char * V_56 )
{
T_4 V_57 ;
F_20 ( V_58 ,
F_21 ( struct V_59 ,
V_57 ) , & V_57 , sizeof( T_4 ) ) ;
return F_22 ( V_56 , V_60 , L_2 , V_57 ) ;
}
static T_5 F_23 ( struct V_6 * V_7 ,
struct V_54 * V_55 ,
const char * V_56 , T_6 V_61 )
{
T_4 V_57 ;
int V_62 ;
if ( F_24 ( V_56 , 10 , & V_57 ) )
return - V_63 ;
V_62 = F_25 ( V_58 ,
F_21 ( struct V_59 ,
V_57 ) ,
& V_57 , sizeof( T_4 ) ) ;
if ( V_62 )
return V_62 ;
return V_61 ;
}
static T_5 F_26 ( struct V_6 * V_7 ,
struct V_54 * V_55 ,
char * V_56 )
{
struct V_64 V_64 ;
F_20 ( V_58 ,
F_21 ( struct V_59 ,
V_65 ) , & V_64 ,
sizeof( struct V_64 ) ) ;
return F_22 ( V_56 , V_60 , L_2 ,
V_64 . V_66 ) ;
}
static T_5 F_27 ( struct V_6 * V_7 ,
struct V_54 * V_55 ,
const char * V_56 , T_6 V_61 )
{
int V_67 , V_62 ;
struct V_64 V_64 ;
if ( F_28 ( V_56 , 10 , & V_67 ) )
return - V_63 ;
V_64 . V_66 = V_67 ;
V_62 = F_25 ( V_58 ,
F_21 ( struct V_59 ,
V_65 ) , & ( V_64 ) ,
sizeof( struct V_64 ) ) ;
if ( V_62 )
return V_62 ;
return V_61 ;
}
static T_5 F_29 ( struct V_6 * V_7 , struct V_54 * V_55 ,
char * V_56 )
{
T_2 error ;
F_20 ( V_58 ,
F_21 ( struct V_59 ,
V_68 ) ,
& error , sizeof( T_2 ) ) ;
return F_22 ( V_56 , V_60 , L_3 , error ) ;
}
static T_5 F_30 ( struct V_6 * V_7 , struct V_54 * V_55 ,
const char * V_56 , T_6 V_61 )
{
T_2 error ;
int V_62 ;
if ( F_31 ( V_56 , 10 , & error ) )
return - V_63 ;
V_62 = F_25 ( V_58 ,
F_21 ( struct V_59 ,
V_68 ) ,
& error , sizeof( T_2 ) ) ;
if ( V_62 )
return V_62 ;
return V_61 ;
}
static T_5 F_32 ( struct V_6 * V_7 , struct V_54 * V_55 ,
char * V_56 )
{
T_2 V_69 ;
F_20 ( V_58 ,
F_21 ( struct V_59 ,
V_70 ) ,
& V_69 , sizeof( T_2 ) ) ;
return F_22 ( V_56 , V_60 , L_3 , V_69 ) ;
}
static T_5 F_33 ( struct V_6 * V_7 , struct V_54 * V_55 ,
const char * V_56 , T_6 V_61 )
{
T_2 V_69 ;
int V_62 ;
if ( F_31 ( V_56 , 10 , & V_69 ) )
return - V_63 ;
V_62 = F_25 ( V_58 ,
F_21 ( struct V_59 ,
V_70 ) ,
& V_69 , sizeof( T_2 ) ) ;
if ( V_62 )
return V_62 ;
return V_61 ;
}
static T_5 F_34 ( struct V_6 * V_7 ,
struct V_54 * V_55 , char * V_56 )
{
T_7 V_71 ;
F_20 ( V_58 ,
F_21 ( struct V_59 ,
V_72 ) ,
& V_71 , sizeof( T_7 ) ) ;
return F_22 ( V_56 , V_60 , L_4 , V_71 ) ;
}
static T_5 F_35 ( struct V_6 * V_7 ,
struct V_54 * V_55 ,
const char * V_56 , T_6 V_61 )
{
T_7 V_71 ;
int V_62 ;
if ( F_36 ( V_56 , 10 , & V_71 ) )
return - V_63 ;
V_62 = F_25 ( V_58 ,
F_21 ( struct V_59 ,
V_72 ) ,
& V_71 , sizeof( T_7 ) ) ;
if ( V_62 )
return V_62 ;
return V_61 ;
}
static int F_37 ( struct V_6 * V_7 , void * V_27 )
{
struct V_73 * V_74 = F_38 ( V_7 ) ;
struct V_75 * V_33 = (struct V_75 * ) V_27 ;
T_2 V_76 = V_33 -> V_76 ;
T_2 V_77 = V_33 -> V_77 ;
if ( ( V_74 -> V_78 == V_76 ) &&
( V_74 -> V_79 == V_77 ) )
return 1 ;
return 0 ;
}
struct V_73 * F_39 ( T_2 V_76 , T_2 V_77 ,
struct V_73 * V_80 )
{
struct V_6 * V_7 ;
struct V_6 * V_81 = NULL ;
struct V_73 * V_74 = NULL ;
struct V_75 V_33 = {
. V_76 = V_76 ,
. V_77 = V_77
} ;
if ( V_80 )
V_81 = & V_80 -> V_6 ;
V_7 = F_40 ( & V_82 , V_81 , ( void * ) & V_33 ,
F_37 ) ;
if ( V_7 )
V_74 = F_38 ( V_7 ) ;
return V_74 ;
}
static T_4
F_41 ( void )
{
int V_53 ;
T_4 V_83 = 1 ;
for ( V_53 = 0 ; V_53 < V_84 ; V_53 ++ )
V_83 &= V_85 [ V_53 ] ;
return V_83 ;
}
static void
F_42 ( void )
{
int V_53 ;
for ( V_53 = 0 ; V_53 < V_84 ; V_53 ++ )
V_85 [ V_53 ] = 0 ;
}
void
F_43 (
struct V_86 * V_87 ,
struct V_88 * V_89 ,
struct V_90 * V_91 )
{
F_44 ( & V_92 ) ;
if ( ! V_87 ) {
memset ( & V_93 , 0 ,
sizeof( V_93 ) ) ;
V_94 = 0 ;
} else {
V_93 = * V_87 ;
V_94 = 1 ;
}
if ( V_89 )
* V_89 = V_95 ;
if ( V_91 )
F_45 ( V_91 , L_5 , L_1 ,
V_96 , NULL ) ;
F_46 ( & V_92 ) ;
}
static void
F_47 ( struct V_97 * V_98 )
{
static int V_99 ;
enum V_100 V_101 = 0 ;
int V_14 = V_102 ;
F_48 ( V_103 , V_104 ) ;
if ( V_99 ) {
V_14 = - V_105 ;
goto V_18;
}
V_99 = 1 ;
F_48 ( V_106 , V_104 ) ;
V_101 =
V_98 -> V_107 . V_108 .
V_101 & V_109 ;
V_101 |= V_110 ;
V_18:
if ( V_98 -> V_111 . V_112 . V_113 )
F_49 ( & V_98 -> V_111 , V_14 , V_101 ) ;
}
static void
F_50 ( struct V_97 * V_114 ,
struct V_115 * V_116 , int V_117 )
{
memset ( V_114 , 0 , sizeof( struct V_97 ) ) ;
memcpy ( & V_114 -> V_111 , V_116 , sizeof( struct V_115 ) ) ;
V_114 -> V_111 . V_118 = 0 ;
V_114 -> V_111 . V_119 = 0 ;
V_114 -> V_111 . V_120 = 0 ;
if ( V_117 < 0 ) {
V_114 -> V_111 . V_112 . V_121 = 1 ;
V_114 -> V_111 . V_122 = ( T_2 ) ( - V_117 ) ;
}
}
static void
F_51 ( struct V_115 * V_116 , int V_117 )
{
struct V_97 V_123 ;
F_50 ( & V_123 , V_116 , V_117 ) ;
if ( V_123 . V_111 . V_112 . V_124 == 1 )
return;
if ( ! F_52 ( V_58 ,
V_125 , & V_123 ) ) {
return;
}
}
static void
F_49 ( struct V_115 * V_116 ,
int V_117 ,
enum V_100 V_101 )
{
struct V_97 V_123 ;
F_50 ( & V_123 , V_116 , V_117 ) ;
V_123 . V_107 . V_108 . V_101 = V_101 ;
if ( ! F_52 ( V_58 ,
V_125 , & V_123 ) ) {
return;
}
}
static void F_53 (
struct V_115 * V_116 , int V_117 ,
struct V_126 V_127 )
{
struct V_97 V_123 ;
F_50 ( & V_123 , V_116 , V_117 ) ;
V_123 . V_107 . V_128 . V_127 = V_127 ;
V_123 . V_107 . V_128 . V_112 . V_129 = 1 ;
if ( ! F_52 ( V_58 ,
V_125 , & V_123 ) ) {
return;
}
}
static void
F_54 ( enum V_130 V_131 ,
struct V_115 * V_132 ,
int V_117 )
{
if ( V_132 == NULL )
return;
if ( V_132 -> V_33 != ( T_2 ) V_131 )
return;
F_51 ( V_132 , V_117 ) ;
}
static void
F_55 ( enum V_130 V_131 ,
struct V_73 * V_25 , int V_117 ,
struct V_126 V_133 )
{
struct V_97 V_123 ;
T_2 V_76 = V_25 -> V_78 ;
T_2 V_77 = V_25 -> V_79 ;
if ( V_25 -> V_132 == NULL )
return;
if ( V_25 -> V_132 -> V_33 != V_131 )
return;
F_50 ( & V_123 , V_25 -> V_132 , V_117 ) ;
V_123 . V_107 . V_128 . V_76 = V_76 ;
V_123 . V_107 . V_128 . V_77 = V_77 ;
V_123 . V_107 . V_128 . V_127 = V_133 ;
if ( ! F_52 ( V_58 ,
V_125 , & V_123 ) )
return;
}
static void
F_56 ( enum V_130 V_131 ,
struct V_115 * V_132 ,
int V_117 )
{
if ( V_132 == NULL )
return;
if ( V_132 -> V_33 != ( T_2 ) V_131 )
return;
F_51 ( V_132 , V_117 ) ;
}
static void
F_57 ( struct V_73 * V_134 ,
T_2 V_107 , struct V_115 * V_116 ,
int V_117 , bool V_135 )
{
bool V_136 = false ;
struct V_115 * V_137 = NULL ;
if ( ! V_134 ) {
V_137 = V_116 ;
goto V_138;
}
if ( V_134 -> V_132 ) {
V_117 = - V_139 ;
V_137 = V_134 -> V_132 ;
goto V_138;
}
if ( V_135 ) {
V_137 = F_6 ( sizeof( * V_137 ) , V_19 ) ;
if ( ! V_137 ) {
V_117 = - V_140 ;
goto V_138;
}
memcpy ( V_137 , V_116 ,
sizeof( struct V_115 ) ) ;
V_134 -> V_132 = V_137 ;
}
F_44 ( & V_92 ) ;
if ( V_117 == V_102 ) {
switch ( V_107 ) {
case V_141 :
if ( V_93 . V_142 ) {
(* V_93 . V_142 ) ( V_134 ) ;
V_136 = true ;
}
break;
case V_143 :
if ( V_93 . V_144 ) {
(* V_93 . V_144 ) ( V_134 ) ;
V_136 = true ;
}
break;
}
}
V_138:
if ( V_136 )
;
else
F_54 ( V_107 , V_137 , V_117 ) ;
F_46 ( & V_92 ) ;
}
static void
F_58 ( struct V_73 * V_145 ,
struct V_126 V_127 , T_2 V_107 ,
struct V_115 * V_116 , int V_117 ,
bool V_135 , bool V_146 )
{
struct V_86 * V_87 ;
bool V_136 = false ;
struct V_115 * V_137 = NULL ;
V_87 = & V_93 ;
if ( ! V_145 ) {
V_137 = V_116 ;
goto V_138;
}
if ( V_145 -> V_132 ) {
V_117 = - V_139 ;
V_137 = V_145 -> V_132 ;
goto V_138;
}
if ( V_135 ) {
V_137 = F_6 ( sizeof( * V_137 ) , V_19 ) ;
if ( ! V_137 ) {
V_117 = - V_140 ;
goto V_138;
}
memcpy ( V_137 , V_116 ,
sizeof( struct V_115 ) ) ;
V_145 -> V_132 = V_137 ;
}
F_44 ( & V_92 ) ;
if ( V_117 >= 0 ) {
switch ( V_107 ) {
case V_147 :
if ( V_87 -> V_148 ) {
(* V_87 -> V_148 ) ( V_145 ) ;
V_136 = true ;
}
break;
case V_149 :
if ( V_127 . V_150 == V_151 . V_150 &&
V_127 . V_152 ==
V_151 . V_152 ) {
if ( V_87 -> V_153 ) {
(* V_87 -> V_153 ) ( V_145 ) ;
V_136 = true ;
}
}
else if ( V_127 . V_150 == V_154 . V_150 &&
V_127 . V_152 ==
V_154 . V_152 ) {
if ( V_87 -> V_155 ) {
(* V_87 -> V_155 ) ( V_145 ) ;
V_136 = true ;
}
}
break;
case V_156 :
if ( V_87 -> V_157 ) {
(* V_87 -> V_157 ) ( V_145 ) ;
V_136 = true ;
}
break;
}
}
V_138:
if ( V_136 )
;
else
F_56 ( V_107 , V_137 , V_117 ) ;
F_46 ( & V_92 ) ;
}
static void
V_142 ( struct V_97 * V_98 )
{
struct V_158 * V_107 = & V_98 -> V_107 ;
T_2 V_76 = V_107 -> V_159 . V_76 ;
int V_14 = V_102 ;
struct V_73 * V_134 ;
struct V_160 * V_160 ;
V_134 = F_39 ( V_76 , V_161 , NULL ) ;
if ( V_134 && ( V_134 -> V_127 . V_162 == 1 ) ) {
F_59 ( V_163 , V_76 ,
V_164 ) ;
V_14 = - V_105 ;
goto V_18;
}
V_134 = F_6 ( sizeof( * V_134 ) , V_19 ) ;
if ( ! V_134 ) {
F_59 ( V_163 , V_76 ,
V_164 ) ;
V_14 = - V_140 ;
goto V_18;
}
F_60 ( & V_134 -> V_165 ) ;
V_134 -> V_78 = V_76 ;
V_134 -> V_79 = V_161 ;
F_59 ( V_166 , V_76 , V_104 ) ;
V_160 = F_61 ( V_107 -> V_159 . V_167 ,
V_107 -> V_159 . V_168 ,
V_19 ,
V_107 -> V_159 . V_169 ) ;
if ( ! V_160 ) {
F_59 ( V_163 , V_76 ,
V_164 ) ;
V_14 = - V_140 ;
F_16 ( V_134 ) ;
V_134 = NULL ;
goto V_18;
}
V_134 -> V_160 = V_160 ;
F_59 ( V_170 , V_76 , V_104 ) ;
V_18:
F_57 ( V_134 , V_141 , & V_98 -> V_111 ,
V_14 , V_98 -> V_111 . V_112 . V_113 == 1 ) ;
}
static void
V_144 ( struct V_97 * V_98 )
{
struct V_158 * V_107 = & V_98 -> V_107 ;
T_2 V_76 = V_107 -> V_171 . V_76 ;
struct V_73 * V_134 ;
int V_14 = V_102 ;
V_134 = F_39 ( V_76 , V_161 , NULL ) ;
if ( ! V_134 )
V_14 = - V_172 ;
else if ( V_134 -> V_127 . V_162 == 0 )
V_14 = - V_105 ;
F_57 ( V_134 , V_143 , & V_98 -> V_111 ,
V_14 , V_98 -> V_111 . V_112 . V_113 == 1 ) ;
}
static void
F_62 ( struct V_97 * V_98 ,
struct V_8 * V_173 )
{
struct V_158 * V_107 = & V_98 -> V_107 ;
T_2 V_76 ;
struct V_73 * V_134 ;
int V_14 = V_102 ;
V_76 = V_107 -> V_174 . V_76 ;
F_59 ( V_175 , V_76 ,
V_104 ) ;
V_134 = F_39 ( V_76 , V_161 , NULL ) ;
if ( ! V_134 ) {
F_59 ( V_176 , V_76 ,
V_164 ) ;
V_14 = - V_172 ;
} else if ( V_134 -> V_127 . V_162 == 0 ) {
F_59 ( V_176 , V_76 ,
V_164 ) ;
V_14 = - V_172 ;
} else if ( V_134 -> V_132 != NULL ) {
F_59 ( V_176 , V_76 ,
V_164 ) ;
V_14 = - V_139 ;
} else {
F_63 ( V_134 -> V_160 ,
V_107 -> V_174 . V_177 ) ;
V_134 -> V_178 = F_14 ( V_173 ) ;
F_15 ( V_173 , V_46 ) ;
V_134 -> V_179 = F_17 ( V_173 ) ;
F_59 ( V_180 , V_76 ,
V_104 ) ;
}
F_57 ( V_134 , V_181 , & V_98 -> V_111 ,
V_14 , V_98 -> V_111 . V_112 . V_113 == 1 ) ;
}
static void
F_64 ( struct V_97 * V_98 )
{
struct V_158 * V_107 = & V_98 -> V_107 ;
T_2 V_76 = V_107 -> V_182 . V_76 ;
T_2 V_77 = V_107 -> V_182 . V_77 ;
struct V_73 * V_145 = NULL ;
struct V_73 * V_134 ;
struct V_160 * V_160 ;
int V_14 = V_102 ;
V_134 = F_39 ( V_76 , V_161 , NULL ) ;
if ( ! V_134 ) {
F_65 ( V_183 , V_77 , V_76 ,
V_164 ) ;
V_14 = - V_172 ;
goto V_18;
}
if ( V_134 -> V_127 . V_162 == 0 ) {
F_65 ( V_183 , V_77 , V_76 ,
V_164 ) ;
V_14 = - V_172 ;
goto V_18;
}
V_145 = F_39 ( V_76 , V_77 , NULL ) ;
if ( V_145 && ( V_145 -> V_127 . V_162 == 1 ) ) {
F_65 ( V_183 , V_77 , V_76 ,
V_164 ) ;
V_14 = - V_105 ;
goto V_18;
}
V_145 = F_6 ( sizeof( * V_145 ) , V_19 ) ;
if ( ! V_145 ) {
F_65 ( V_183 , V_77 , V_76 ,
V_164 ) ;
V_14 = - V_140 ;
goto V_18;
}
V_145 -> V_78 = V_76 ;
V_145 -> V_79 = V_77 ;
V_145 -> V_184 = V_107 -> V_182 . V_185 ;
V_145 -> V_6 . V_186 = & V_134 -> V_6 ;
F_65 ( V_187 , V_77 , V_76 ,
V_104 ) ;
V_160 =
F_66 ( V_107 -> V_182 . V_167 ,
V_107 -> V_182 . V_168 ,
V_19 ,
V_107 -> V_182 . V_188 ) ;
if ( ! V_160 ) {
F_65 ( V_183 , V_77 , V_76 ,
V_164 ) ;
V_14 = - V_140 ;
F_16 ( V_145 ) ;
V_145 = NULL ;
goto V_18;
}
V_145 -> V_160 = V_160 ;
V_145 -> V_189 = V_107 -> V_182 . V_188 ;
F_65 ( V_190 , V_77 , V_76 ,
V_104 ) ;
V_18:
F_58 ( V_145 , V_151 ,
V_147 , & V_98 -> V_111 , V_14 ,
V_98 -> V_111 . V_112 . V_113 == 1 , 1 ) ;
}
static void
F_67 ( struct V_97 * V_98 )
{
struct V_158 * V_107 = & V_98 -> V_107 ;
T_2 V_76 = V_107 -> V_128 . V_76 ;
T_2 V_77 = V_107 -> V_128 . V_77 ;
struct V_126 V_127 = V_107 -> V_128 . V_127 ;
struct V_73 * V_145 ;
int V_14 = V_102 ;
V_145 = F_39 ( V_76 , V_77 , NULL ) ;
if ( ! V_145 ) {
F_65 ( V_191 , V_77 , V_76 ,
V_164 ) ;
V_14 = - V_192 ;
} else if ( V_145 -> V_127 . V_162 == 0 ) {
F_65 ( V_191 , V_77 , V_76 ,
V_164 ) ;
V_14 = - V_192 ;
}
if ( ( V_14 >= V_102 ) && V_145 )
F_58 ( V_145 , V_127 ,
V_149 , & V_98 -> V_111 , V_14 ,
V_98 -> V_111 . V_112 . V_113 == 1 , 1 ) ;
}
static void
F_68 ( struct V_97 * V_98 )
{
struct V_158 * V_107 = & V_98 -> V_107 ;
T_2 V_76 = V_107 -> V_193 . V_76 ;
T_2 V_77 = V_107 -> V_193 . V_77 ;
struct V_73 * V_145 ;
int V_14 = V_102 ;
V_145 = F_39 ( V_76 , V_77 , NULL ) ;
if ( ! V_145 )
V_14 = - V_192 ;
else if ( V_145 -> V_127 . V_162 == 0 )
V_14 = - V_105 ;
if ( ( V_14 >= V_102 ) && V_145 )
F_58 ( V_145 , V_151 ,
V_156 , & V_98 -> V_111 , V_14 ,
V_98 -> V_111 . V_112 . V_113 == 1 , 1 ) ;
}
static int
F_69 ( T_1 V_194 , T_1 V_195 , T_2 V_10 ,
struct V_196 * V_197 )
{
T_4 * V_198 = NULL ;
int V_14 = V_102 ;
if ( ! V_197 ) {
V_14 = - V_199 ;
goto V_18;
}
memset ( V_197 , 0 , sizeof( struct V_196 ) ) ;
if ( ( V_195 == 0 ) || ( V_10 == 0 ) ) {
V_14 = - V_199 ;
goto V_18;
}
V_198 = F_10 ( V_194 + V_195 , V_10 , V_29 ) ;
if ( ! V_198 ) {
V_14 = - V_200 ;
goto V_18;
}
V_197 -> V_195 = V_195 ;
V_197 -> V_10 = V_10 ;
V_197 -> V_201 = V_198 ;
V_18:
if ( V_14 < 0 ) {
if ( V_198 ) {
F_12 ( V_198 ) ;
V_198 = NULL ;
}
}
return V_14 ;
}
static void
F_70 ( struct V_196 * V_197 )
{
if ( V_197 -> V_201 ) {
F_12 ( V_197 -> V_201 ) ;
V_197 -> V_201 = NULL ;
}
memset ( V_197 , 0 , sizeof( struct V_196 ) ) ;
}
static void
F_71 ( void )
{
T_1 V_194 = F_72 ( V_58 ) ;
T_1 V_202 = 0 ;
T_2 V_118 = 0 ;
if ( F_20 ( V_58 ,
F_21 ( struct V_59 ,
V_203 ) ,
& V_202 , sizeof( V_202 ) ) < 0 ) {
F_48 ( V_204 ,
V_164 ) ;
return;
}
if ( F_20 ( V_58 ,
F_21 ( struct V_59 ,
V_205 ) ,
& V_118 , sizeof( V_118 ) ) < 0 ) {
F_48 ( V_204 ,
V_164 ) ;
return;
}
F_69 ( V_194 ,
V_202 , V_118 ,
& V_206 ) ;
}
static int
F_73 ( void )
{
F_74 ( & V_207 . V_7 . V_208 , V_209 ) ;
return V_102 ;
}
static int
F_75 ( void )
{
char V_210 [ 20 ] ;
char * V_211 [] = { V_210 , NULL } ;
sprintf ( V_210 , L_6 , 1 ) ;
F_76 ( & V_207 . V_7 . V_208 , V_212 ,
V_211 ) ;
return V_102 ;
}
static int
F_77 ( void )
{
F_74 ( & V_207 . V_7 . V_208 , V_213 ) ;
return V_102 ;
}
static void
F_78 ( struct V_115 * V_116 )
{
int V_14 = F_73 () ;
if ( V_14 != V_102 )
V_14 = - V_14 ;
if ( V_116 -> V_112 . V_113 && ! V_214 )
F_51 ( V_116 , V_14 ) ;
if ( V_116 -> V_112 . V_113 && V_214 ) {
V_215 = * V_116 ;
}
}
static void
F_79 ( struct V_115 * V_116 )
{
int V_14 = F_75 () ;
if ( V_14 != V_102 )
V_14 = - V_14 ;
if ( V_116 -> V_112 . V_113 )
F_51 ( V_116 , V_14 ) ;
}
static void
F_80 ( struct V_115 * V_116 )
{
int V_14 = F_77 () ;
if ( V_14 != V_102 )
V_14 = - V_14 ;
if ( V_116 -> V_112 . V_113 )
F_51 ( V_116 , V_14 ) ;
}
static bool
F_81 ( struct V_97 * V_114 )
{
if ( F_82 ( V_58 ,
V_216 , V_114 ) ) {
if ( V_114 -> V_111 . V_112 . V_124 == 1 )
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
return V_217 + F_87 ( V_218 ) ;
}
static struct V_219 *
F_88 ( struct V_97 * V_114 )
{
struct V_219 * V_220 ;
V_220 = F_18 ( sizeof( * V_220 ) , V_19 | V_20 ) ;
if ( ! V_220 )
return NULL ;
V_220 -> V_33 = F_83 () ;
V_220 -> V_221 = F_86 () ;
V_220 -> V_114 = * V_114 ;
return V_220 ;
}
static void
F_89 ( struct V_219 * V_220 )
{
F_16 ( V_220 ) ;
}
static void
F_90 ( struct V_219 * V_220 )
{
struct V_158 * V_107 = & V_220 -> V_114 . V_107 ;
char V_222 [ 40 ] , V_223 [ 40 ] , V_224 [ 40 ] , V_225 [ 40 ] , V_226 [ 40 ] ,
V_227 [ 40 ] ;
char * V_211 [] = {
V_222 , V_223 , V_224 , V_225 , V_226 , V_227 , NULL
} ;
sprintf ( V_222 , L_7 ) ;
sprintf ( V_223 , L_8 , V_220 -> V_33 ) ;
sprintf ( V_224 , L_9 ,
V_107 -> V_128 . V_127 . V_228 ) ;
sprintf ( V_225 , L_10 ,
V_107 -> V_128 . V_76 ) ;
sprintf ( V_226 , L_11 ,
V_107 -> V_128 . V_77 >> 3 ) ;
sprintf ( V_227 , L_12 ,
V_107 -> V_128 . V_77 & 0x7 ) ;
F_76 ( & V_207 . V_7 . V_208 , V_212 ,
V_211 ) ;
}
static void
F_91 ( void )
{
struct V_229 * V_230 ;
struct V_229 * V_231 ;
F_92 ( & V_232 ) ;
F_93 (pos, tmp, &parahotplug_request_list) {
struct V_219 * V_220 =
F_94 ( V_230 , struct V_219 , V_233 ) ;
if ( ! F_95 ( V_217 , V_220 -> V_221 ) )
continue;
F_96 ( V_230 ) ;
if ( V_220 -> V_114 . V_111 . V_112 . V_113 )
F_53 (
& V_220 -> V_114 . V_111 ,
V_234 ,
V_220 -> V_114 . V_107 . V_128 . V_127 ) ;
F_89 ( V_220 ) ;
}
F_97 ( & V_232 ) ;
}
static int
F_98 ( int V_33 , T_7 V_228 )
{
struct V_229 * V_230 ;
struct V_229 * V_231 ;
F_92 ( & V_232 ) ;
F_93 (pos, tmp, &parahotplug_request_list) {
struct V_219 * V_220 =
F_94 ( V_230 , struct V_219 , V_233 ) ;
if ( V_220 -> V_33 == V_33 ) {
F_96 ( V_230 ) ;
F_97 ( & V_232 ) ;
V_220 -> V_114 . V_107 . V_128 . V_127 . V_228 = V_228 ;
if ( V_220 -> V_114 . V_111 . V_112 . V_113 )
F_53 (
& V_220 -> V_114 . V_111 , V_102 ,
V_220 -> V_114 . V_107 . V_128 . V_127 ) ;
F_89 ( V_220 ) ;
return 0 ;
}
}
F_97 ( & V_232 ) ;
return - 1 ;
}
static void
F_99 ( struct V_97 * V_98 )
{
struct V_219 * V_220 ;
V_220 = F_88 ( V_98 ) ;
if ( ! V_220 )
return;
if ( V_98 -> V_107 . V_128 . V_127 . V_228 ) {
F_90 ( V_220 ) ;
F_53 ( & V_98 -> V_111 ,
V_102 ,
V_98 -> V_107 . V_128 . V_127 ) ;
F_89 ( V_220 ) ;
} else {
F_92 ( & V_232 ) ;
F_100 ( & V_220 -> V_233 , & V_235 ) ;
F_97 ( & V_232 ) ;
F_90 ( V_220 ) ;
}
}
static bool
F_101 ( struct V_97 V_98 , T_1 V_167 )
{
struct V_158 * V_107 = & V_98 . V_107 ;
T_1 V_236 ;
T_2 V_237 ;
struct V_8 * V_173 = NULL ;
bool V_238 ;
struct V_97 V_239 ;
V_238 = ( V_98 . V_111 . V_112 . V_124 == 1 ) ;
if ( V_167 == 0 )
return true ;
V_236 = V_167 + V_98 . V_111 . V_119 ;
V_237 = V_98 . V_111 . V_118 ;
if ( V_236 && V_237 ) {
bool V_12 = false ;
V_173 =
F_5 ( V_236 , V_237 ,
V_238 , & V_12 ) ;
if ( ! V_173 && V_12 )
return false ;
}
if ( ! V_238 ) {
F_50 ( & V_239 , & V_98 . V_111 ,
V_102 ) ;
if ( V_58 )
F_52 ( V_58 ,
V_240 ,
& V_239 ) ;
}
switch ( V_98 . V_111 . V_33 ) {
case V_241 :
F_47 ( & V_98 ) ;
break;
case V_141 :
V_142 ( & V_98 ) ;
break;
case V_143 :
V_144 ( & V_98 ) ;
break;
case V_181 :
F_62 ( & V_98 , V_173 ) ;
break;
case V_147 :
F_64 ( & V_98 ) ;
break;
case V_149 :
if ( V_107 -> V_128 . V_112 . V_129 ) {
F_99 ( & V_98 ) ;
} else {
F_67 ( & V_98 ) ;
V_242 = V_98 . V_107 ;
break;
}
break;
case V_156 :
F_68 ( & V_98 ) ;
break;
case V_243 :
if ( V_98 . V_111 . V_112 . V_113 )
F_51 ( & V_98 . V_111 , V_102 ) ;
break;
case V_244 :
F_78 ( & V_98 . V_111 ) ;
break;
case V_245 :
F_79 ( & V_98 . V_111 ) ;
break;
case V_246 :
F_80 ( & V_98 . V_111 ) ;
break;
default:
if ( V_98 . V_111 . V_112 . V_113 )
F_51 ( & V_98 . V_111 ,
- V_247 ) ;
break;
}
if ( V_173 ) {
F_13 ( V_173 ) ;
V_173 = NULL ;
}
return true ;
}
static inline unsigned int
F_102 ( T_1 * V_248 , T_2 * V_249 )
{
struct V_250 V_251 ;
int V_252 = V_253 ;
T_1 V_254 ;
V_254 = F_7 ( & V_251 ) ;
F_103 ( V_255 , V_254 , V_252 ) ;
if ( F_104 ( V_252 ) ) {
* V_248 = V_251 . V_256 ;
* V_249 = V_251 . V_168 ;
}
return V_252 ;
}
static T_1 F_105 ( void )
{
T_1 V_9 = 0 ;
T_2 V_257 = 0 ;
if ( ! F_104 ( F_102 ( & V_9 , & V_257 ) ) )
return 0 ;
return V_9 ;
}
static void
F_106 ( struct V_258 * V_259 )
{
struct V_97 V_98 ;
bool V_260 = false ;
bool V_261 = false ;
static T_1 V_262 ;
if ( V_263 && ! V_94 )
goto V_18;
V_262 ++ ;
if ( V_262 >= 250 )
;
else
goto V_18;
if ( V_214 &&
( V_215 . V_33 != V_264 ) ) {
if ( F_41 () == 1 ) {
F_51 ( & V_215 , 0 ) ;
F_42 () ;
memset ( & V_215 , 0 ,
sizeof( struct V_115 ) ) ;
}
}
while ( F_82 ( V_58 ,
V_265 ,
& V_98 ) )
;
if ( ! V_260 ) {
if ( V_266 ) {
V_98 = V_267 ;
V_266 = false ;
V_260 = true ;
} else {
V_260 = F_81 ( & V_98 ) ;
}
}
V_261 = false ;
while ( V_260 && ( ! V_261 ) ) {
V_268 = V_217 ;
if ( F_101 ( V_98 ,
F_72
( V_58 ) ) )
V_260 = F_81 ( & V_98 ) ;
else {
V_261 = true ;
V_267 = V_98 ;
V_266 = true ;
}
}
F_91 () ;
V_18:
if ( F_107 ( V_217 ,
V_268 + ( V_269 * V_270 ) ) ) {
if ( V_271 != V_272 )
V_271 = V_272 ;
} else {
if ( V_271 != V_273 )
V_271 = V_273 ;
}
F_108 ( V_274 ,
& V_275 , V_271 ) ;
}
static void
F_109 ( struct V_258 * V_259 )
{
struct V_97 V_276 ;
struct V_97 V_277 ;
struct V_97 V_114 ;
T_2 V_278 ;
T_7 V_279 ;
if ( V_263 && ! V_94 )
goto V_18;
F_48 ( V_280 , V_104 ) ;
V_114 . V_111 . V_33 = V_241 ;
V_114 . V_107 . V_108 . V_281 = 23 ;
V_114 . V_107 . V_108 . V_282 = 0 ;
F_47 ( & V_114 ) ;
if ( F_20 ( V_58 ,
F_21 ( struct V_59 ,
V_283 ) ,
& V_279 , sizeof( T_7 ) ) < 0 ) {
F_48 ( V_284 ,
V_164 ) ;
return;
}
if ( V_279 != V_285 ) {
F_59 ( V_286 ,
V_279 ,
V_164 ) ;
return;
}
if ( F_20 ( V_58 ,
F_21 ( struct V_59 ,
V_287 ) ,
& V_278 , sizeof( T_2 ) ) < 0 ) {
F_48 ( V_284 ,
V_164 ) ;
return;
}
if ( F_20 ( V_58 ,
V_278 ,
& V_276 ,
sizeof( struct V_97 ) ) < 0 ) {
F_48 ( V_288 ,
V_164 ) ;
return;
}
if ( F_20 ( V_58 ,
V_278 +
sizeof( struct V_97 ) ,
& V_277 ,
sizeof( struct V_97 ) ) < 0 ) {
F_48 ( V_289 ,
V_164 ) ;
return;
}
if ( V_276 . V_107 . V_159 . V_167 ) {
V_142 ( & V_276 ) ;
} else {
F_48 ( V_290 ,
V_164 ) ;
return;
}
if ( V_277 . V_107 . V_182 . V_167 ) {
F_64 ( & V_277 ) ;
} else {
F_48 ( V_291 ,
V_164 ) ;
return;
}
F_48 ( V_292 , V_104 ) ;
return;
V_18:
V_271 = V_272 ;
F_108 ( V_274 ,
& V_275 , V_271 ) ;
}
static void
F_110 ( struct V_73 * V_134 , int V_117 )
{
if ( V_117 >= 0 )
V_134 -> V_127 . V_162 = 1 ;
F_54 ( V_141 , V_134 -> V_132 ,
V_117 ) ;
F_16 ( V_134 -> V_132 ) ;
V_134 -> V_132 = NULL ;
}
static void
F_111 ( struct V_73 * V_134 , int V_117 )
{
F_54 ( V_143 , V_134 -> V_132 ,
V_117 ) ;
F_16 ( V_134 -> V_132 ) ;
V_134 -> V_132 = NULL ;
}
static void
F_112 ( struct V_73 * V_145 , int V_117 )
{
if ( V_117 >= 0 )
V_145 -> V_127 . V_162 = 1 ;
F_56 ( V_147 , V_145 -> V_132 ,
V_117 ) ;
F_16 ( V_145 -> V_132 ) ;
V_145 -> V_132 = NULL ;
}
static void
F_113 ( struct V_73 * V_145 , int V_117 )
{
F_56 ( V_156 , V_145 -> V_132 ,
V_117 ) ;
F_16 ( V_145 -> V_132 ) ;
V_145 -> V_132 = NULL ;
}
static void
F_114 ( struct V_73 * V_145 ,
int V_117 )
{
F_55 ( V_149 ,
V_145 , V_117 ,
V_154 ) ;
F_16 ( V_145 -> V_132 ) ;
V_145 -> V_132 = NULL ;
}
static void
F_115 ( struct V_73 * V_145 , int V_117 )
{
F_55 ( V_149 ,
V_145 , V_117 ,
V_151 ) ;
F_16 ( V_145 -> V_132 ) ;
V_145 -> V_132 = NULL ;
}
static T_5 F_116 ( struct V_6 * V_7 ,
struct V_54 * V_55 ,
const char * V_56 , T_6 V_61 )
{
char V_293 [ 64 ] ;
if ( sscanf ( V_56 , L_13 , V_293 ) != 1 )
return - V_63 ;
if ( ! strcmp ( V_293 , L_14 ) ) {
V_85 [ 0 ] = 1 ;
return V_61 ;
} else if ( ! strcmp ( V_293 , L_15 ) ) {
V_85 [ 1 ] = 1 ;
return V_61 ;
}
return - V_63 ;
}
static T_5 F_117 ( struct V_6 * V_7 ,
struct V_54 * V_55 ,
const char * V_56 , T_6 V_61 )
{
unsigned int V_33 ;
if ( F_118 ( V_56 , 10 , & V_33 ) )
return - V_63 ;
F_98 ( V_33 , 0 ) ;
return V_61 ;
}
static T_5 F_119 ( struct V_6 * V_7 ,
struct V_54 * V_55 ,
const char * V_56 , T_6 V_61 )
{
unsigned int V_33 ;
if ( F_118 ( V_56 , 10 , & V_33 ) )
return - V_63 ;
F_98 ( V_33 , 1 ) ;
return V_61 ;
}
static int
F_120 ( struct V_2 * V_2 , struct V_294 * V_295 )
{
unsigned long V_254 = 0 ;
unsigned long V_195 = V_295 -> V_296 << V_297 ;
T_1 V_9 = 0 ;
if ( V_195 & ( V_60 - 1 ) )
return - V_298 ;
switch ( V_195 ) {
case V_299 :
V_295 -> V_300 |= V_301 ;
if ( ! * V_302 )
return - V_298 ;
F_20 ( * V_302 ,
F_21 ( struct V_59 ,
V_303 ) ,
& V_9 , sizeof( V_9 ) ) ;
if ( ! V_9 )
return - V_298 ;
V_254 = ( unsigned long ) V_9 ;
if ( F_121 ( V_295 , V_295 -> V_304 ,
V_254 >> V_297 ,
V_295 -> V_305 - V_295 -> V_304 ,
( V_295 -> V_306 ) ) ) {
return - V_307 ;
}
break;
default:
return - V_298 ;
}
return 0 ;
}
static inline T_9 F_122 ( void )
{
T_1 V_252 = V_253 ;
T_1 V_254 = 0 ;
F_103 ( V_308 , V_254 ,
V_252 ) ;
return V_252 ;
}
static inline int F_123 ( T_1 V_309 )
{
int V_252 = V_253 ;
F_103 ( V_310 , V_309 , V_252 ) ;
return V_252 ;
}
static long F_124 ( struct V_2 * V_2 , unsigned int V_107 ,
unsigned long V_311 )
{
T_9 V_309 ;
T_9 V_312 ;
switch ( V_107 ) {
case V_308 :
V_312 = F_122 () ;
if ( F_125 ( ( void V_313 * ) V_311 , & V_312 ,
sizeof( V_312 ) ) ) {
return - V_314 ;
}
return 0 ;
case V_310 :
if ( F_126 ( & V_309 , ( void V_313 * ) V_311 ,
sizeof( V_309 ) ) ) {
return - V_314 ;
}
return F_123 ( V_309 ) ;
default:
return - V_314 ;
}
}
static int
F_127 ( T_10 V_315 , struct V_160 * * V_58 )
{
int V_14 = 0 ;
V_302 = V_58 ;
F_128 ( & V_316 , & V_317 ) ;
V_316 . V_318 = V_319 ;
if ( F_129 ( V_315 ) == 0 ) {
V_14 = F_130 ( & V_315 , 0 , 1 , L_1 ) ;
if ( V_14 < 0 )
return V_14 ;
} else {
V_14 = F_131 ( V_315 , 1 , L_1 ) ;
if ( V_14 < 0 )
return V_14 ;
}
V_14 = F_132 ( & V_316 , F_133 ( F_129 ( V_315 ) , 0 ) , 1 ) ;
if ( V_14 < 0 ) {
F_134 ( V_315 , 1 ) ;
return V_14 ;
}
return 0 ;
}
static int
F_135 ( struct V_320 * V_320 )
{
int V_14 = 0 ;
T_1 V_9 ;
int V_321 = sizeof( struct V_59 ) ;
T_3 V_322 = V_323 ;
V_9 = F_105 () ;
if ( ! V_9 )
return - V_4 ;
memset ( & V_93 , 0 , sizeof( V_93 ) ) ;
memset ( & V_206 , 0 , sizeof( V_206 ) ) ;
V_58 = F_66 ( V_9 , V_321 ,
V_19 , V_322 ) ;
if ( F_136 (
F_137 ( V_58 ) ) ) {
F_71 () ;
} else {
F_138 ( V_58 ) ;
V_58 = NULL ;
return - V_4 ;
}
V_315 = F_133 ( V_324 , 0 ) ;
V_14 = F_127 ( V_315 , & V_58 ) ;
if ( V_14 < 0 ) {
F_48 ( V_325 , V_326 ) ;
goto V_18;
}
memset ( & V_215 , 0 , sizeof( struct V_115 ) ) ;
if ( F_139 () )
F_140 ( & V_275 ,
F_109 ) ;
else
F_140 ( & V_275 ,
F_106 ) ;
V_274 =
F_141 ( L_16 ) ;
if ( ! V_274 ) {
F_48 ( V_327 ,
V_326 ) ;
V_14 = - V_328 ;
goto V_18;
}
V_268 = V_217 ;
V_271 = V_273 ;
V_14 = F_108 ( V_274 ,
& V_275 , V_271 ) ;
if ( V_14 < 0 ) {
F_48 ( V_329 ,
V_326 ) ;
goto V_18;
}
V_207 . V_7 . V_330 = V_315 ;
if ( F_142 ( & V_207 ) < 0 ) {
F_48 ( V_331 , V_326 ) ;
V_14 = - 1 ;
goto V_18;
}
F_48 ( V_332 , V_104 ) ;
V_14 = F_143 () ;
V_18:
if ( V_14 ) {
F_59 ( V_325 , V_14 ,
V_164 ) ;
}
return V_14 ;
}
static void
F_144 ( T_10 V_315 )
{
if ( V_316 . V_333 )
F_145 ( & V_316 ) ;
V_316 . V_333 = NULL ;
F_134 ( V_315 , 1 ) ;
}
static int
F_146 ( struct V_320 * V_320 )
{
F_48 ( V_334 , V_104 ) ;
F_147 () ;
F_148 ( & V_275 ) ;
F_149 ( V_274 ) ;
F_150 ( V_274 ) ;
V_274 = NULL ;
F_70 ( & V_206 ) ;
memset ( & V_215 , 0 , sizeof( struct V_115 ) ) ;
F_138 ( V_58 ) ;
F_144 ( V_207 . V_7 . V_330 ) ;
F_151 ( & V_207 ) ;
F_48 ( V_334 , V_104 ) ;
return 0 ;
}
static T_11 T_12 F_152 ( void )
{
unsigned int V_335 , V_336 , V_337 , V_338 ;
if ( V_339 ) {
F_153 ( V_340 , & V_335 , & V_336 , & V_337 , & V_338 ) ;
return ( V_336 == V_341 ) &&
( V_337 == V_342 ) &&
( V_338 == V_343 ) ;
} else {
return 0 ;
}
}
static int F_154 ( void )
{
int V_252 ;
if ( ! F_152 () )
return - V_4 ;
V_252 = F_155 ( & V_344 ) ;
if ( V_252 )
return - V_4 ;
F_156 ( L_17 ) ;
return 0 ;
}
static void F_157 ( void )
{
F_158 ( & V_344 ) ;
}

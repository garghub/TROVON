static struct V_1 * F_1 ( struct V_2 * V_2 , unsigned V_3 )
{
struct V_1 * V_4 = NULL ;
if ( V_3 < V_2 -> V_5 . V_6 ) {
struct V_1 T_1 * * V_7 =
F_2 ( V_2 -> V_5 . V_7 ) ;
V_4 = F_2 ( V_7 [ V_3 ] ) ;
}
return V_4 ;
}
bool F_3 ( const struct V_8 * V_9 )
{
return V_9 && ( V_9 -> V_10 & V_11 ) && F_4 ( V_9 ) ;
}
static T_2 * F_5 ( struct V_1 * V_4 , struct V_12 * V_13 )
{
return ( T_2 * ) V_13 + V_4 -> V_14 ;
}
static const T_2 * F_6 ( const struct V_1 * V_4 ,
const struct V_12 * V_13 )
{
return F_5 ( (struct V_1 * ) V_4 , (struct V_12 * ) V_13 ) ;
}
static unsigned int F_7 ( const struct V_12 * V_13 )
{
return V_13 -> V_15 * sizeof( struct V_16 ) ;
}
unsigned int F_8 ( const struct V_8 * V_9 )
{
return V_9 -> V_17 ;
}
bool F_9 ( const struct V_18 * V_19 , unsigned int V_17 )
{
if ( V_19 -> V_20 <= V_17 )
return false ;
if ( F_10 ( V_19 ) && F_11 ( V_19 , V_17 ) )
return false ;
return true ;
}
void F_12 ( struct V_8 * V_9 ,
const struct V_18 * V_19 )
{
struct V_21 * V_22 ;
if ( V_19 -> V_23 == F_13 ( V_24 ) ) {
V_22 = F_14 ( V_9 ) ;
if ( V_22 )
F_15 ( V_22 , V_19 -> V_20 ,
V_25 ,
V_26 ) ;
} else if ( V_19 -> V_23 == F_13 ( V_27 ) ) {
F_16 ( F_17 ( V_9 ) , V_28 , V_19 -> V_20 ) ;
#if F_18 ( V_29 )
} else if ( V_19 -> V_23 == F_13 ( V_30 ) ) {
struct V_31 * V_32 = F_19 ( V_9 ) ;
if ( V_32 )
F_20 ( F_17 ( V_9 ) , V_32 ,
V_28 , V_19 -> V_20 ) ;
#endif
}
}
static T_3 F_21 ( struct V_1 * V_4 , struct V_18 * V_19 )
{
struct V_33 V_34 ;
unsigned int V_35 = 0 ;
struct V_16 * V_36 ;
bool V_37 = false ;
int V_38 ;
T_3 V_39 = 0 ;
for ( V_38 = 0 ; V_38 < V_40 ;
V_38 ++ ) {
V_35 += sizeof( * V_36 ) ;
if ( ! F_22 ( V_19 , V_35 ) )
break;
V_36 = F_23 ( V_19 ) + V_38 ;
V_34 = F_24 ( V_36 ) ;
if ( F_25 ( V_34 . V_41 >= V_42 ) ) {
V_39 = F_26 ( V_34 . V_41 , V_39 ) ;
if ( V_37 )
break;
} else if ( V_34 . V_41 == V_43 ) {
V_37 = true ;
}
if ( ! V_34 . V_44 )
continue;
if ( F_22 ( V_19 , V_35 + sizeof( struct V_45 ) ) ) {
const struct V_45 * V_46 ;
V_46 = ( const struct V_45 * ) ( V_36 + 1 ) ;
if ( V_46 -> V_47 == 4 ) {
V_39 = F_27 ( F_28 ( V_46 -> V_48 ) ,
F_28 ( V_46 -> V_49 ) ,
V_46 -> V_23 , V_39 ) ;
} else if ( V_46 -> V_47 == 6 &&
F_22 ( V_19 , V_35 +
sizeof( struct V_50 ) ) ) {
const struct V_50 * V_51 ;
V_51 = ( const struct V_50 * ) ( V_36 + 1 ) ;
V_39 = F_29 ( & V_51 -> V_48 , V_39 ) ;
V_39 = F_29 ( & V_51 -> V_49 , V_39 ) ;
V_39 = F_26 ( V_51 -> V_52 , V_39 ) ;
}
}
break;
}
return V_39 ;
}
static struct V_12 * F_30 ( struct V_1 * V_4 , T_2 V_3 )
{
return (struct V_12 * ) ( ( T_2 * ) V_4 -> V_53 + V_3 * V_4 -> V_54 ) ;
}
static struct V_12 * F_31 ( struct V_1 * V_4 ,
struct V_18 * V_19 )
{
T_3 V_39 = 0 ;
int V_55 = 0 ;
int V_56 = 0 ;
T_2 V_57 ;
if ( V_4 -> V_58 == 1 )
return V_4 -> V_53 ;
V_57 = F_32 ( V_4 -> V_59 ) ;
if ( V_57 == 0 )
return NULL ;
V_39 = F_21 ( V_4 , V_19 ) ;
V_55 = V_39 % V_57 ;
if ( V_57 == V_4 -> V_58 )
goto V_60;
F_33 (rt) {
unsigned int V_61 = F_32 ( V_13 -> V_61 ) ;
if ( V_61 & ( V_62 | V_63 ) )
continue;
if ( V_56 == V_55 )
return V_13 ;
V_56 ++ ;
} F_34 ( V_4 ) ;
V_60:
return F_30 ( V_4 , V_55 ) ;
}
static bool F_35 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_18 * V_19 , struct V_33 V_34 )
{
enum V_64 V_65 ;
bool V_66 = false ;
if ( ! F_22 ( V_19 , 12 ) )
return false ;
V_65 = V_4 -> V_67 ;
if ( V_65 == V_68 )
V_65 = F_36 ( V_19 ) -> V_47 ;
switch ( V_65 ) {
case V_69 : {
struct V_45 * V_70 = F_36 ( V_19 ) ;
T_2 V_71 ;
V_19 -> V_23 = F_13 ( V_27 ) ;
if ( V_4 -> V_72 == V_73 ||
( V_4 -> V_72 == V_74 &&
V_2 -> V_5 . V_75 ) )
V_71 = V_34 . V_76 ;
else
V_71 = V_70 -> V_76 ? V_70 -> V_76 - 1 : 0 ;
F_37 ( & V_70 -> V_77 ,
F_13 ( V_70 -> V_76 << 8 ) ,
F_13 ( V_71 << 8 ) ) ;
V_70 -> V_76 = V_71 ;
V_66 = true ;
break;
}
case V_78 : {
struct V_50 * V_79 = F_38 ( V_19 ) ;
V_19 -> V_23 = F_13 ( V_30 ) ;
if ( V_4 -> V_72 == V_73 ||
( V_4 -> V_72 == V_74 &&
V_2 -> V_5 . V_75 ) )
V_79 -> V_80 = V_34 . V_76 ;
else if ( V_79 -> V_80 )
V_79 -> V_80 = V_79 -> V_80 - 1 ;
V_66 = true ;
break;
}
case V_68 :
break;
}
return V_66 ;
}
static int F_39 ( struct V_18 * V_19 , struct V_8 * V_9 ,
struct V_81 * V_82 , struct V_8 * V_83 )
{
struct V_2 * V_2 = F_17 ( V_9 ) ;
struct V_16 * V_36 ;
struct V_1 * V_4 ;
struct V_12 * V_13 ;
struct V_33 V_34 ;
struct V_8 * V_84 ;
struct V_21 * V_85 ;
struct V_21 * V_22 ;
unsigned int V_86 ;
unsigned int V_87 ;
unsigned int V_17 ;
int V_88 ;
V_22 = F_14 ( V_9 ) ;
if ( ! V_22 )
goto V_89;
F_15 ( V_22 , V_19 -> V_20 , V_90 ,
V_91 ) ;
if ( ! V_22 -> V_92 ) {
F_40 ( V_22 , V_93 ) ;
goto V_89;
}
if ( V_19 -> V_94 != V_95 )
goto V_88;
if ( ( V_19 = F_41 ( V_19 , V_96 ) ) == NULL )
goto V_88;
if ( ! F_22 ( V_19 , sizeof( * V_36 ) ) )
goto V_88;
V_36 = F_23 ( V_19 ) ;
V_34 = F_24 ( V_36 ) ;
V_4 = F_1 ( V_2 , V_34 . V_41 ) ;
if ( ! V_4 ) {
F_40 ( V_22 , V_97 ) ;
goto V_89;
}
V_13 = F_31 ( V_4 , V_19 ) ;
if ( ! V_13 )
goto V_88;
F_42 ( V_19 , sizeof( * V_36 ) ) ;
F_43 ( V_19 ) ;
F_44 ( V_19 ) ;
if ( F_45 ( V_19 ) )
goto V_88;
F_46 ( V_19 ) ;
if ( V_34 . V_76 <= 1 )
goto V_88;
V_34 . V_76 -= 1 ;
V_84 = F_2 ( V_13 -> V_98 ) ;
if ( ! F_3 ( V_84 ) )
goto V_99;
V_87 = F_7 ( V_13 ) ;
V_17 = F_8 ( V_84 ) ;
if ( F_9 ( V_19 , V_17 - V_87 ) )
goto V_99;
V_86 = F_47 ( V_84 ) ;
if ( ! V_84 -> V_100 )
V_86 = 0 ;
if ( F_48 ( V_19 , V_86 + V_87 ) )
goto V_99;
V_19 -> V_9 = V_84 ;
V_19 -> V_23 = F_13 ( V_24 ) ;
if ( F_49 ( ! V_87 && V_34 . V_44 ) ) {
if ( ! F_35 ( F_17 ( V_84 ) , V_4 , V_19 , V_34 ) )
goto V_88;
} else {
bool V_44 ;
int V_101 ;
F_50 ( V_19 , V_87 ) ;
F_43 ( V_19 ) ;
V_36 = F_23 ( V_19 ) ;
V_44 = V_34 . V_44 ;
for ( V_101 = V_13 -> V_15 - 1 ; V_101 >= 0 ; V_101 -- ) {
V_36 [ V_101 ] = F_51 ( V_13 -> V_102 [ V_101 ] ,
V_34 . V_76 , 0 , V_44 ) ;
V_44 = false ;
}
}
F_12 ( V_84 , V_19 ) ;
if ( V_13 -> V_103 == V_104 )
V_88 = F_52 ( V_105 , V_84 ,
V_84 -> V_106 , V_19 ) ;
else
V_88 = F_52 ( V_13 -> V_103 , V_84 ,
F_6 ( V_4 , V_13 ) , V_19 ) ;
if ( V_88 )
F_53 ( L_1 ,
V_107 , V_88 ) ;
return 0 ;
V_99:
V_85 = V_84 ? F_14 ( V_84 ) : NULL ;
if ( V_85 )
F_40 ( V_85 , V_108 ) ;
goto V_89;
V_88:
F_40 ( V_22 , V_109 ) ;
V_89:
F_54 ( V_19 ) ;
return V_110 ;
}
static struct V_1 * F_55 ( T_2 V_111 , T_2 V_112 , T_2 V_113 )
{
T_2 V_114 = F_56 ( V_113 , V_112 ) ;
struct V_1 * V_4 ;
T_4 V_115 ;
V_115 = sizeof( * V_4 ) + V_111 * V_114 ;
if ( V_115 > V_116 )
return F_57 ( - V_117 ) ;
V_4 = F_58 ( V_115 , V_118 ) ;
if ( ! V_4 )
return F_57 ( - V_119 ) ;
V_4 -> V_58 = V_111 ;
V_4 -> V_59 = V_111 ;
V_4 -> V_54 = V_114 ;
V_4 -> V_14 = F_59 ( V_113 ) ;
return V_4 ;
}
static void F_60 ( struct V_1 * V_4 )
{
if ( V_4 )
F_61 ( V_4 , V_120 ) ;
}
static void F_62 ( struct V_2 * V_2 , unsigned V_3 ,
struct V_1 * V_121 , struct V_1 * V_122 ,
const struct V_123 * V_124 )
{
struct V_125 * V_126 = V_124 ? V_124 -> V_126 : NULL ;
unsigned V_127 = V_124 ? V_124 -> V_127 : 0 ;
int V_128 = V_122 ? V_129 : V_130 ;
struct V_1 * V_4 = V_122 ? V_122 : V_121 ;
unsigned V_131 = ( V_121 && V_122 ) ? V_132 : 0 ;
if ( V_4 && ( V_3 >= V_42 ) )
F_63 ( V_128 , V_3 , V_4 , V_126 , V_2 , V_127 , V_131 ) ;
}
static void F_64 ( struct V_2 * V_2 , unsigned V_3 ,
struct V_1 * V_122 ,
const struct V_123 * V_124 )
{
struct V_1 T_1 * * V_7 ;
struct V_1 * V_4 ;
F_65 () ;
V_7 = F_66 ( V_2 -> V_5 . V_7 ) ;
V_4 = F_66 ( V_7 [ V_3 ] ) ;
F_67 ( V_7 [ V_3 ] , V_122 ) ;
F_62 ( V_2 , V_3 , V_4 , V_122 , V_124 ) ;
F_60 ( V_4 ) ;
}
static unsigned F_68 ( struct V_2 * V_2 )
{
struct V_1 T_1 * * V_7 ;
T_4 V_6 ;
unsigned V_3 ;
V_7 = F_66 ( V_2 -> V_5 . V_7 ) ;
V_6 = V_2 -> V_5 . V_6 ;
for ( V_3 = V_42 ; V_3 < V_6 ;
V_3 ++ ) {
if ( ! F_66 ( V_7 [ V_3 ] ) )
return V_3 ;
}
return V_133 ;
}
static struct V_8 * F_69 ( struct V_2 * V_2 ,
const void * V_134 )
{
struct V_8 * V_9 ;
struct V_135 * V_4 ;
struct V_136 V_49 ;
memcpy ( & V_49 , V_134 , sizeof( struct V_136 ) ) ;
V_4 = F_70 ( V_2 , V_49 . V_137 , 0 , 0 , 0 ) ;
if ( F_71 ( V_4 ) )
return F_72 ( V_4 ) ;
V_9 = V_4 -> V_138 . V_9 ;
F_73 ( V_9 ) ;
F_74 ( V_4 ) ;
return V_9 ;
}
static struct V_8 * F_69 ( struct V_2 * V_2 ,
const void * V_134 )
{
return F_57 ( - V_139 ) ;
}
static struct V_8 * F_75 ( struct V_2 * V_2 ,
const void * V_134 )
{
struct V_8 * V_9 ;
struct V_140 * V_138 ;
struct V_141 V_142 ;
int V_88 ;
if ( ! V_143 )
return F_57 ( - V_139 ) ;
memset ( & V_142 , 0 , sizeof( V_142 ) ) ;
memcpy ( & V_142 . V_49 , V_134 , sizeof( struct V_144 ) ) ;
V_88 = V_143 -> V_145 ( V_2 , NULL , & V_138 , & V_142 ) ;
if ( V_88 )
return F_57 ( V_88 ) ;
V_9 = V_138 -> V_9 ;
F_73 ( V_9 ) ;
F_76 ( V_138 ) ;
return V_9 ;
}
static struct V_8 * F_75 ( struct V_2 * V_2 ,
const void * V_134 )
{
return F_57 ( - V_139 ) ;
}
static struct V_8 * F_77 ( struct V_2 * V_2 ,
struct V_1 * V_4 ,
struct V_12 * V_13 , int V_146 )
{
struct V_8 * V_9 = NULL ;
if ( ! V_146 ) {
switch ( V_13 -> V_103 ) {
case V_147 :
V_9 = F_69 ( V_2 , F_6 ( V_4 , V_13 ) ) ;
break;
case V_148 :
V_9 = F_75 ( V_2 , F_6 ( V_4 , V_13 ) ) ;
break;
case V_105 :
break;
}
} else {
V_9 = F_78 ( V_2 , V_146 ) ;
}
if ( ! V_9 )
return F_57 ( - V_149 ) ;
if ( F_71 ( V_9 ) )
return V_9 ;
F_79 ( V_9 ) ;
return V_9 ;
}
static int F_80 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_12 * V_13 , int V_146 )
{
struct V_8 * V_9 = NULL ;
int V_88 = - V_149 ;
V_9 = F_77 ( V_2 , V_4 , V_13 , V_146 ) ;
if ( F_71 ( V_9 ) ) {
V_88 = F_81 ( V_9 ) ;
V_9 = NULL ;
goto V_150;
}
V_88 = - V_117 ;
if ( ! F_14 ( V_9 ) )
goto V_150;
if ( ( V_13 -> V_103 == V_105 ) &&
( V_9 -> V_151 != V_13 -> V_152 ) )
goto V_150;
F_82 ( V_13 -> V_98 , V_9 ) ;
if ( ! ( V_9 -> V_10 & V_11 ) ) {
V_13 -> V_61 |= V_62 ;
} else {
unsigned int V_10 ;
V_10 = F_83 ( V_9 ) ;
if ( ! ( V_10 & ( V_153 | V_154 ) ) )
V_13 -> V_61 |= V_63 ;
}
return 0 ;
V_150:
return V_88 ;
}
static int F_84 ( const struct V_155 * V_156 , T_2 * V_157 , T_2 * V_158 ,
T_2 V_159 [] , struct V_160 * V_161 )
{
struct V_162 * V_163 = F_85 ( V_156 ) ;
int V_88 = - V_117 ;
int V_164 ;
if ( F_86 ( V_156 ) < F_87 ( struct V_162 , V_165 ) ) {
F_88 ( V_161 , V_156 ,
L_2 ) ;
goto V_150;
}
V_164 = F_86 ( V_156 ) -
F_87 ( struct V_162 , V_165 ) ;
if ( V_164 > V_166 ) {
F_88 ( V_161 , V_156 ,
L_3 ) ;
goto V_150;
}
switch ( V_163 -> V_167 ) {
case V_168 :
* V_158 = V_105 ;
break;
case V_169 :
* V_158 = V_147 ;
if ( V_164 != 4 )
goto V_150;
break;
case V_170 :
* V_158 = V_148 ;
if ( V_164 != 16 )
goto V_150;
break;
default:
goto V_150;
}
memcpy ( V_159 , V_163 -> V_165 , V_164 ) ;
* V_157 = V_164 ;
V_88 = 0 ;
V_150:
return V_88 ;
}
static int F_89 ( struct V_171 * V_172 ,
struct V_1 * V_4 )
{
struct V_2 * V_2 = V_172 -> V_173 . V_174 ;
struct V_12 * V_13 = V_4 -> V_53 ;
int V_88 ;
int V_101 ;
if ( ! V_13 )
return - V_119 ;
V_13 -> V_15 = V_172 -> V_175 ;
for ( V_101 = 0 ; V_101 < V_13 -> V_15 ; V_101 ++ )
V_13 -> V_102 [ V_101 ] = V_172 -> V_176 [ V_101 ] ;
V_13 -> V_103 = V_172 -> V_177 ;
memcpy ( F_5 ( V_4 , V_13 ) , V_172 -> V_178 , V_172 -> V_179 ) ;
V_13 -> V_152 = V_172 -> V_179 ;
V_88 = F_80 ( V_2 , V_4 , V_13 , V_172 -> V_180 ) ;
if ( V_88 )
goto V_150;
if ( V_13 -> V_61 & ( V_62 | V_63 ) )
V_4 -> V_59 -- ;
return 0 ;
V_150:
return V_88 ;
}
static int F_90 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_12 * V_13 , int V_146 , struct V_155 * V_163 ,
struct V_155 * V_181 , T_2 V_113 ,
struct V_160 * V_161 )
{
int V_88 = - V_119 ;
if ( ! V_13 )
goto V_150;
if ( V_181 ) {
V_88 = F_91 ( V_181 , V_113 , & V_13 -> V_15 ,
V_13 -> V_102 , V_161 ) ;
if ( V_88 )
goto V_150;
}
if ( V_163 ) {
V_88 = F_84 ( V_163 , & V_13 -> V_152 , & V_13 -> V_103 ,
F_5 ( V_4 , V_13 ) , V_161 ) ;
if ( V_88 )
goto V_150;
} else {
V_13 -> V_103 = V_104 ;
}
V_88 = F_80 ( V_2 , V_4 , V_13 , V_146 ) ;
if ( V_88 )
goto V_150;
return 0 ;
V_150:
return V_88 ;
}
static T_2 F_92 ( struct V_182 * V_183 , int V_20 ,
T_2 V_184 , T_2 * V_185 ,
T_2 * V_113 )
{
int V_186 = V_20 ;
T_2 V_187 = 0 ;
* V_185 = 0 ;
* V_113 = 0 ;
while ( F_93 ( V_183 , V_186 ) ) {
struct V_155 * V_156 , * V_188 = F_94 ( V_183 ) ;
int V_189 ;
T_2 V_190 = 0 ;
V_189 = F_95 ( V_183 ) ;
V_156 = F_96 ( V_188 , V_189 , V_191 ) ;
if ( V_156 && F_86 ( V_156 ) >=
F_87 ( struct V_162 , V_165 ) ) {
int V_157 = F_86 ( V_156 ) -
F_87 ( struct V_162 , V_165 ) ;
if ( V_157 <= V_166 )
* V_185 = F_97 ( V_192 , * V_185 ,
V_157 ) ;
}
V_156 = F_96 ( V_188 , V_189 , V_193 ) ;
if ( V_156 &&
F_91 ( V_156 , V_194 , & V_190 ,
NULL , NULL ) != 0 )
return 0 ;
* V_113 = F_97 ( T_2 , * V_113 , V_190 ) ;
if ( V_187 == 255 )
return 0 ;
V_187 ++ ;
V_183 = F_98 ( V_183 , & V_186 ) ;
}
return V_186 > 0 ? 0 : V_187 ;
}
static int F_99 ( struct V_171 * V_172 ,
struct V_1 * V_4 , T_2 V_113 ,
struct V_160 * V_161 )
{
struct V_182 * V_183 = V_172 -> V_195 ;
struct V_155 * V_196 , * V_197 ;
int V_186 = V_172 -> V_198 ;
int V_88 = 0 ;
T_2 V_187 = 0 ;
F_100 (rt) {
int V_189 ;
V_196 = NULL ;
V_197 = NULL ;
V_88 = - V_117 ;
if ( ! F_93 ( V_183 , V_186 ) )
goto V_150;
if ( V_183 -> V_199 || V_183 -> V_200 )
goto V_150;
V_189 = F_95 ( V_183 ) ;
if ( V_189 > 0 ) {
struct V_155 * V_188 = F_94 ( V_183 ) ;
V_196 = F_96 ( V_188 , V_189 , V_191 ) ;
V_197 = F_96 ( V_188 , V_189 , V_193 ) ;
}
V_88 = F_90 ( V_172 -> V_173 . V_174 , V_4 , V_13 ,
V_183 -> V_201 , V_196 , V_197 ,
V_113 , V_161 ) ;
if ( V_88 )
goto V_150;
if ( V_13 -> V_61 & ( V_62 | V_63 ) )
V_4 -> V_59 -- ;
V_183 = F_98 ( V_183 , & V_186 ) ;
V_187 ++ ;
} F_34 ( V_4 ) ;
V_4 -> V_58 = V_187 ;
return 0 ;
V_150:
return V_88 ;
}
static bool F_101 ( struct V_2 * V_2 , unsigned int V_3 ,
struct V_160 * V_161 )
{
if ( V_3 < V_42 ) {
F_102 ( V_161 ,
L_4 ) ;
return false ;
}
if ( V_3 >= V_2 -> V_5 . V_6 ) {
F_102 ( V_161 ,
L_5 ) ;
return false ;
}
return true ;
}
static int F_103 ( struct V_171 * V_172 ,
struct V_160 * V_161 )
{
struct V_1 T_1 * * V_7 ;
struct V_2 * V_2 = V_172 -> V_173 . V_174 ;
struct V_1 * V_4 , * V_121 ;
int V_88 = - V_117 ;
T_2 V_185 ;
unsigned V_3 ;
T_2 V_113 ;
T_2 V_187 ;
V_3 = V_172 -> V_202 ;
if ( ( V_3 == V_133 ) &&
( V_172 -> V_203 & V_204 ) ) {
V_3 = F_68 ( V_2 ) ;
}
if ( ! F_101 ( V_2 , V_3 , V_161 ) )
goto V_150;
V_88 = - V_205 ;
if ( V_172 -> V_203 & V_206 ) {
F_102 ( V_161 , L_6 ) ;
goto V_150;
}
V_88 = - V_207 ;
V_7 = F_66 ( V_2 -> V_5 . V_7 ) ;
V_121 = F_66 ( V_7 [ V_3 ] ) ;
if ( ( V_172 -> V_203 & V_208 ) && V_121 )
goto V_150;
V_88 = - V_207 ;
if ( ! ( V_172 -> V_203 & V_132 ) && V_121 )
goto V_150;
V_88 = - V_209 ;
if ( ! ( V_172 -> V_203 & V_204 ) && ! V_121 )
goto V_150;
V_88 = - V_117 ;
if ( V_172 -> V_195 ) {
V_187 = F_92 ( V_172 -> V_195 , V_172 -> V_198 ,
V_172 -> V_179 , & V_185 ,
& V_113 ) ;
} else {
V_185 = V_172 -> V_179 ;
V_113 = V_172 -> V_175 ;
V_187 = 1 ;
}
if ( V_187 == 0 ) {
F_102 ( V_161 , L_7 ) ;
goto V_150;
}
V_88 = - V_119 ;
V_4 = F_55 ( V_187 , V_185 , V_113 ) ;
if ( F_71 ( V_4 ) ) {
V_88 = F_81 ( V_4 ) ;
goto V_150;
}
V_4 -> V_210 = V_172 -> V_211 ;
V_4 -> V_67 = V_172 -> V_212 ;
V_4 -> V_72 = V_172 -> V_213 ;
if ( V_172 -> V_195 )
V_88 = F_99 ( V_172 , V_4 , V_113 , V_161 ) ;
else
V_88 = F_89 ( V_172 , V_4 ) ;
if ( V_88 )
goto V_214;
F_64 ( V_2 , V_3 , V_4 , & V_172 -> V_173 ) ;
return 0 ;
V_214:
F_60 ( V_4 ) ;
V_150:
return V_88 ;
}
static int F_104 ( struct V_171 * V_172 ,
struct V_160 * V_161 )
{
struct V_2 * V_2 = V_172 -> V_173 . V_174 ;
unsigned V_3 ;
int V_88 = - V_117 ;
V_3 = V_172 -> V_202 ;
if ( ! F_101 ( V_2 , V_3 , V_161 ) )
goto V_150;
F_64 ( V_2 , V_3 , NULL , & V_172 -> V_173 ) ;
V_88 = 0 ;
V_150:
return V_88 ;
}
static void F_105 ( struct V_21 * V_22 ,
struct V_215 * V_216 )
{
struct V_217 * V_218 ;
int V_101 ;
memset ( V_216 , 0 , sizeof( * V_216 ) ) ;
F_106 (i) {
struct V_215 V_219 ;
unsigned int V_220 ;
V_218 = F_107 ( V_22 -> V_216 , V_101 ) ;
do {
V_220 = F_108 ( & V_218 -> V_221 ) ;
V_219 = V_218 -> V_216 ;
} while ( F_109 ( & V_218 -> V_221 , V_220 ) );
V_216 -> V_90 += V_219 . V_90 ;
V_216 -> V_91 += V_219 . V_91 ;
V_216 -> V_25 += V_219 . V_25 ;
V_216 -> V_26 += V_219 . V_26 ;
V_216 -> V_109 += V_219 . V_109 ;
V_216 -> V_108 += V_219 . V_108 ;
V_216 -> V_93 += V_219 . V_93 ;
V_216 -> V_222 += V_219 . V_222 ;
V_216 -> V_97 += V_219 . V_97 ;
}
}
static int F_110 ( struct V_18 * V_19 ,
const struct V_8 * V_9 )
{
struct V_215 * V_216 ;
struct V_21 * V_22 ;
struct V_155 * V_156 ;
V_22 = F_14 ( V_9 ) ;
if ( ! V_22 )
return - V_223 ;
V_156 = F_111 ( V_19 , V_224 ,
sizeof( struct V_215 ) ,
V_225 ) ;
if ( ! V_156 )
return - V_226 ;
V_216 = F_85 ( V_156 ) ;
F_105 ( V_22 , V_216 ) ;
return 0 ;
}
static T_4 F_112 ( const struct V_8 * V_9 )
{
struct V_21 * V_22 ;
V_22 = F_14 ( V_9 ) ;
if ( ! V_22 )
return 0 ;
return F_113 ( sizeof( struct V_215 ) ) ;
}
static int F_114 ( struct V_18 * V_19 , struct V_21 * V_22 ,
T_3 V_127 , T_3 V_227 , int V_128 ,
unsigned int V_10 , int type )
{
struct V_125 * V_126 ;
struct V_228 * V_229 ;
bool V_230 = false ;
V_126 = F_115 ( V_19 , V_127 , V_227 , V_128 , sizeof( struct V_228 ) ,
V_10 ) ;
if ( ! V_126 )
return - V_226 ;
if ( type == V_231 )
V_230 = true ;
V_229 = F_116 ( V_126 ) ;
V_229 -> V_232 = V_233 ;
if ( F_117 ( V_19 , V_234 , V_22 -> V_9 -> V_235 ) < 0 )
goto V_236;
if ( ( V_230 || type == V_237 ) &&
F_117 ( V_19 , V_237 ,
V_22 -> V_92 ) < 0 )
goto V_236;
F_118 ( V_19 , V_126 ) ;
return 0 ;
V_236:
F_119 ( V_19 , V_126 ) ;
return - V_226 ;
}
static int F_120 ( int type )
{
int V_115 = F_121 ( sizeof( struct V_228 ) )
+ F_122 ( 4 ) ;
bool V_230 = false ;
if ( type == V_231 )
V_230 = true ;
if ( V_230 || type == V_237 )
V_115 += F_122 ( 4 ) ;
return V_115 ;
}
static void F_123 ( struct V_2 * V_2 , int V_128 ,
int type , struct V_21 * V_22 )
{
struct V_18 * V_19 ;
int V_88 = - V_238 ;
V_19 = F_124 ( F_120 ( type ) , V_118 ) ;
if ( ! V_19 )
goto V_150;
V_88 = F_114 ( V_19 , V_22 , 0 , 0 , V_128 , 0 , type ) ;
if ( V_88 < 0 ) {
F_125 ( V_88 == - V_226 ) ;
F_54 ( V_19 ) ;
goto V_150;
}
F_126 ( V_19 , V_2 , 0 , V_239 , NULL , V_118 ) ;
return;
V_150:
if ( V_88 < 0 )
F_127 ( V_2 , V_239 , V_88 ) ;
}
static int F_128 ( struct V_18 * V_240 ,
struct V_125 * V_126 ,
struct V_160 * V_161 )
{
struct V_2 * V_2 = F_129 ( V_240 -> V_241 ) ;
struct V_155 * V_242 [ V_243 + 1 ] ;
struct V_228 * V_229 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
struct V_18 * V_19 ;
int V_235 ;
int V_88 ;
V_88 = F_130 ( V_126 , sizeof( * V_229 ) , V_242 , V_243 ,
V_244 , NULL ) ;
if ( V_88 < 0 )
goto V_150;
V_88 = - V_117 ;
if ( ! V_242 [ V_234 ] )
goto V_150;
V_235 = F_131 ( V_242 [ V_234 ] ) ;
V_9 = F_132 ( V_2 , V_235 ) ;
if ( ! V_9 )
goto V_150;
V_22 = F_14 ( V_9 ) ;
if ( ! V_22 )
goto V_150;
V_88 = - V_238 ;
V_19 = F_124 ( F_120 ( V_231 ) , V_118 ) ;
if ( ! V_19 )
goto V_150;
V_88 = F_114 ( V_19 , V_22 ,
F_133 ( V_240 ) . V_127 ,
V_126 -> V_245 , V_246 , 0 ,
V_231 ) ;
if ( V_88 < 0 ) {
F_125 ( V_88 == - V_226 ) ;
F_54 ( V_19 ) ;
goto V_150;
}
V_88 = F_134 ( V_19 , V_2 , F_133 ( V_240 ) . V_127 ) ;
V_150:
return V_88 ;
}
static int F_135 ( struct V_18 * V_19 ,
struct V_247 * V_248 )
{
struct V_2 * V_2 = F_129 ( V_19 -> V_241 ) ;
struct V_249 * V_250 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
int V_251 , V_252 ;
int V_253 , V_254 ;
V_254 = V_248 -> args [ 0 ] ;
V_252 = V_251 = V_248 -> args [ 1 ] ;
for ( V_253 = V_254 ; V_253 < V_255 ; V_253 ++ , V_252 = 0 ) {
V_251 = 0 ;
V_250 = & V_2 -> V_256 [ V_253 ] ;
F_136 () ;
V_248 -> V_227 = V_2 -> V_257 ;
F_137 (dev, head, index_hlist) {
if ( V_251 < V_252 )
goto V_258;
V_22 = F_14 ( V_9 ) ;
if ( ! V_22 )
goto V_258;
if ( F_114 ( V_19 , V_22 ,
F_133 ( V_248 -> V_19 ) . V_127 ,
V_248 -> V_126 -> V_245 ,
V_246 ,
V_259 ,
V_231 ) < 0 ) {
F_138 () ;
goto V_260;
}
F_139 ( V_248 , F_140 ( V_19 ) ) ;
V_258:
V_251 ++ ;
}
F_138 () ;
}
V_260:
V_248 -> args [ 0 ] = V_253 ;
V_248 -> args [ 1 ] = V_251 ;
return V_19 -> V_20 ;
}
static int F_141 ( struct V_261 * V_262 , int V_263 ,
void T_5 * V_264 ,
T_4 * V_265 , T_6 * V_266 )
{
int V_267 = * ( int * ) V_262 -> V_268 ;
int V_269 = F_142 ( V_262 , V_263 , V_264 , V_265 , V_266 ) ;
if ( V_263 ) {
struct V_21 * V_22 = V_262 -> V_270 ;
int V_101 = ( int * ) V_262 -> V_268 - ( int * ) V_22 ;
struct V_2 * V_2 = V_262 -> V_271 ;
int V_272 = * ( int * ) V_262 -> V_268 ;
if ( V_101 == F_87 ( struct V_21 , V_92 ) &&
V_272 != V_267 ) {
F_123 ( V_2 , V_246 ,
V_237 , V_22 ) ;
}
}
return V_269 ;
}
static int F_143 ( struct V_8 * V_9 ,
struct V_21 * V_22 )
{
char V_273 [ sizeof( L_8 ) + V_274 ] ;
struct V_2 * V_2 = F_17 ( V_9 ) ;
struct V_261 * V_275 ;
int V_101 ;
V_275 = F_144 ( & V_276 , sizeof( V_276 ) , V_118 ) ;
if ( ! V_275 )
goto V_60;
for ( V_101 = 0 ; V_101 < F_145 ( V_276 ) ; V_101 ++ ) {
V_275 [ V_101 ] . V_268 = ( char * ) V_22 + ( V_277 ) V_275 [ V_101 ] . V_268 ;
V_275 [ V_101 ] . V_270 = V_22 ;
V_275 [ V_101 ] . V_271 = V_2 ;
}
snprintf ( V_273 , sizeof( V_273 ) , L_9 , V_9 -> V_278 ) ;
V_22 -> V_279 = F_146 ( V_2 , V_273 , V_275 ) ;
if ( ! V_22 -> V_279 )
goto free;
F_123 ( V_2 , V_246 , V_231 , V_22 ) ;
return 0 ;
free:
F_147 ( V_275 ) ;
V_60:
return - V_238 ;
}
static void F_148 ( struct V_8 * V_9 ,
struct V_21 * V_22 )
{
struct V_2 * V_2 = F_17 ( V_9 ) ;
struct V_261 * V_275 ;
V_275 = V_22 -> V_279 -> V_280 ;
F_149 ( V_22 -> V_279 ) ;
F_147 ( V_275 ) ;
F_123 ( V_2 , V_281 , 0 , V_22 ) ;
}
static struct V_21 * F_150 ( struct V_8 * V_9 )
{
struct V_21 * V_22 ;
int V_88 = - V_119 ;
int V_101 ;
F_65 () ;
V_22 = F_58 ( sizeof( * V_22 ) , V_118 ) ;
if ( ! V_22 )
return F_57 ( V_88 ) ;
V_22 -> V_216 = F_151 ( struct V_217 ) ;
if ( ! V_22 -> V_216 )
goto free;
F_106 (i) {
struct V_217 * V_282 ;
V_282 = F_107 ( V_22 -> V_216 , V_101 ) ;
F_152 ( & V_282 -> V_221 ) ;
}
V_22 -> V_9 = V_9 ;
V_88 = F_143 ( V_9 , V_22 ) ;
if ( V_88 )
goto free;
F_67 ( V_9 -> V_283 , V_22 ) ;
return V_22 ;
free:
F_153 ( V_22 -> V_216 ) ;
F_147 ( V_22 ) ;
return F_57 ( V_88 ) ;
}
static void F_154 ( struct V_284 * V_250 )
{
struct V_21 * V_22 = F_155 ( V_250 , struct V_21 , V_285 ) ;
F_153 ( V_22 -> V_216 ) ;
F_147 ( V_22 ) ;
}
static void F_156 ( struct V_8 * V_9 , int V_128 )
{
struct V_1 T_1 * * V_7 ;
struct V_2 * V_2 = F_17 ( V_9 ) ;
T_2 V_57 , V_286 ;
unsigned V_3 ;
V_7 = F_66 ( V_2 -> V_5 . V_7 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 . V_6 ; V_3 ++ ) {
struct V_1 * V_4 = F_66 ( V_7 [ V_3 ] ) ;
if ( ! V_4 )
continue;
V_57 = 0 ;
V_286 = 0 ;
F_100 (rt) {
unsigned int V_61 = V_13 -> V_61 ;
if ( F_66 ( V_13 -> V_98 ) != V_9 )
goto V_287;
switch ( V_128 ) {
case V_288 :
case V_289 :
V_61 |= V_62 ;
case V_290 :
V_61 |= V_63 ;
break;
}
if ( V_128 == V_289 )
F_82 ( V_13 -> V_98 , NULL ) ;
if ( V_13 -> V_61 != V_61 )
F_157 ( V_13 -> V_61 , V_61 ) ;
V_287:
if ( ! ( V_61 & ( V_62 | V_63 ) ) )
V_57 ++ ;
if ( ! F_66 ( V_13 -> V_98 ) )
V_286 ++ ;
} F_34 ( V_4 ) ;
F_157 ( V_4 -> V_59 , V_57 ) ;
if ( V_128 == V_289 && V_286 == V_4 -> V_58 )
F_64 ( V_2 , V_3 , NULL , NULL ) ;
}
}
static void F_158 ( struct V_8 * V_9 , unsigned int V_10 )
{
struct V_1 T_1 * * V_7 ;
struct V_2 * V_2 = F_17 ( V_9 ) ;
unsigned V_3 ;
T_2 V_57 ;
V_7 = F_66 ( V_2 -> V_5 . V_7 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 . V_6 ; V_3 ++ ) {
struct V_1 * V_4 = F_66 ( V_7 [ V_3 ] ) ;
if ( ! V_4 )
continue;
V_57 = 0 ;
F_100 (rt) {
unsigned int V_61 = V_13 -> V_61 ;
struct V_8 * V_98 =
F_66 ( V_13 -> V_98 ) ;
if ( ! ( V_61 & V_10 ) ) {
V_57 ++ ;
continue;
}
if ( V_98 != V_9 )
continue;
V_57 ++ ;
V_61 &= ~ V_10 ;
F_157 ( V_13 -> V_61 , V_61 ) ;
} F_34 ( V_4 ) ;
F_157 ( V_4 -> V_59 , V_57 ) ;
}
}
static int F_159 ( struct V_291 * V_292 , unsigned long V_128 ,
void * V_293 )
{
struct V_8 * V_9 = F_160 ( V_293 ) ;
struct V_21 * V_22 ;
unsigned int V_10 ;
if ( V_128 == V_294 ) {
if ( V_9 -> type == V_295 ||
V_9 -> type == V_296 ||
V_9 -> type == V_297 ||
V_9 -> type == V_298 ||
V_9 -> type == V_299 ) {
V_22 = F_150 ( V_9 ) ;
if ( F_71 ( V_22 ) )
return F_161 ( F_81 ( V_22 ) ) ;
}
return V_300 ;
}
V_22 = F_14 ( V_9 ) ;
if ( ! V_22 )
return V_300 ;
switch ( V_128 ) {
case V_288 :
F_156 ( V_9 , V_128 ) ;
break;
case V_301 :
V_10 = F_83 ( V_9 ) ;
if ( V_10 & ( V_153 | V_154 ) )
F_158 ( V_9 , V_62 | V_63 ) ;
else
F_158 ( V_9 , V_62 ) ;
break;
case V_290 :
V_10 = F_83 ( V_9 ) ;
if ( V_10 & ( V_153 | V_154 ) )
F_158 ( V_9 , V_62 | V_63 ) ;
else
F_156 ( V_9 , V_128 ) ;
break;
case V_289 :
F_156 ( V_9 , V_128 ) ;
V_22 = F_14 ( V_9 ) ;
if ( V_22 ) {
F_148 ( V_9 , V_22 ) ;
F_82 ( V_9 -> V_283 , NULL ) ;
F_162 ( & V_22 -> V_285 , F_154 ) ;
}
break;
case V_302 :
V_22 = F_14 ( V_9 ) ;
if ( V_22 ) {
int V_88 ;
F_148 ( V_9 , V_22 ) ;
V_88 = F_143 ( V_9 , V_22 ) ;
if ( V_88 )
return F_161 ( V_88 ) ;
}
break;
}
return V_300 ;
}
static int F_163 ( struct V_18 * V_19 ,
T_2 V_275 , const void * V_134 , int V_164 )
{
static const int V_303 [ V_304 + 1 ] = {
V_169 , V_170 , V_305 , V_168 ,
} ;
struct V_155 * V_156 ;
struct V_162 * V_163 ;
int V_306 = V_307 ;
V_156 = F_164 ( V_19 , V_191 , V_164 + 2 ) ;
if ( ! V_156 )
return - V_226 ;
if ( V_275 <= V_304 )
V_306 = V_303 [ V_275 ] ;
V_163 = F_85 ( V_156 ) ;
V_163 -> V_167 = V_306 ;
memcpy ( V_163 -> V_165 , V_134 , V_164 ) ;
return 0 ;
}
int F_165 ( struct V_18 * V_19 , int V_308 ,
T_2 V_309 , const T_3 V_41 [] )
{
struct V_155 * V_156 ;
struct V_16 * V_310 ;
bool V_44 ;
int V_101 ;
V_156 = F_164 ( V_19 , V_308 , V_309 * 4 ) ;
if ( ! V_156 )
return - V_226 ;
V_310 = F_85 ( V_156 ) ;
V_44 = true ;
for ( V_101 = V_309 - 1 ; V_101 >= 0 ; V_101 -- ) {
V_310 [ V_101 ] = F_51 ( V_41 [ V_101 ] , 0 , 0 , V_44 ) ;
V_44 = false ;
}
return 0 ;
}
int F_91 ( const struct V_155 * V_156 , T_2 V_113 , T_2 * V_309 ,
T_3 V_41 [] , struct V_160 * V_161 )
{
unsigned V_20 = F_86 ( V_156 ) ;
struct V_16 * V_310 ;
T_2 V_311 ;
bool V_44 ;
int V_101 ;
if ( V_20 & 3 || V_20 / 4 > 255 ) {
F_88 ( V_161 , V_156 ,
L_10 ) ;
return - V_117 ;
}
V_311 = V_20 / 4 ;
if ( V_311 > V_113 ) {
F_102 ( V_161 , L_11 ) ;
return - V_117 ;
}
if ( ! V_41 )
goto V_60;
V_310 = F_85 ( V_156 ) ;
V_44 = true ;
for ( V_101 = V_311 - 1 ; V_101 >= 0 ; V_101 -- , V_44 = false ) {
struct V_33 V_34 ;
V_34 = F_24 ( V_310 + V_101 ) ;
if ( V_34 . V_76 ) {
F_88 ( V_161 , V_156 ,
L_12 ) ;
return - V_117 ;
}
if ( V_34 . V_312 ) {
F_88 ( V_161 , V_156 ,
L_13 ) ;
return - V_117 ;
}
if ( V_34 . V_44 != V_44 ) {
F_166 ( V_161 , V_156 ) ;
if ( V_44 ) {
F_102 ( V_161 ,
L_14 ) ;
} else {
F_102 ( V_161 ,
L_15 ) ;
}
return - V_117 ;
}
switch ( V_34 . V_41 ) {
case V_313 :
F_88 ( V_161 , V_156 ,
L_16 ) ;
return - V_117 ;
}
V_41 [ V_101 ] = V_34 . V_41 ;
}
V_60:
* V_309 = V_311 ;
return 0 ;
}
static int F_167 ( struct V_18 * V_19 ,
struct V_125 * V_126 ,
struct V_171 * V_172 ,
struct V_160 * V_161 )
{
struct V_314 * V_315 ;
struct V_155 * V_242 [ V_316 + 1 ] ;
int V_3 ;
int V_88 ;
V_88 = F_130 ( V_126 , sizeof( * V_315 ) , V_242 , V_316 , V_317 ,
V_161 ) ;
if ( V_88 < 0 )
goto V_150;
V_88 = - V_117 ;
V_315 = F_116 ( V_126 ) ;
if ( V_315 -> V_318 != V_233 ) {
F_102 ( V_161 , L_17 ) ;
goto V_150;
}
if ( V_315 -> V_319 != 20 ) {
F_102 ( V_161 , L_18 ) ;
goto V_150;
}
if ( V_315 -> V_320 != 0 ) {
F_102 ( V_161 , L_19 ) ;
goto V_150;
}
if ( V_315 -> V_321 != 0 ) {
F_102 ( V_161 , L_20 ) ;
goto V_150;
}
if ( V_315 -> V_322 != V_323 ) {
F_102 ( V_161 ,
L_21 ) ;
goto V_150;
}
if ( V_315 -> V_324 != V_325 ) {
F_102 ( V_161 ,
L_22 ) ;
goto V_150;
}
if ( V_315 -> V_326 != V_327 ) {
F_102 ( V_161 ,
L_23 ) ;
goto V_150;
}
if ( V_315 -> V_328 != 0 ) {
F_102 ( V_161 , L_24 ) ;
goto V_150;
}
V_172 -> V_202 = V_133 ;
V_172 -> V_211 = V_315 -> V_329 ;
V_172 -> V_177 = V_104 ;
V_172 -> V_213 = V_74 ;
V_172 -> V_203 = V_126 -> V_330 ;
V_172 -> V_173 . V_127 = F_133 ( V_19 ) . V_127 ;
V_172 -> V_173 . V_126 = V_126 ;
V_172 -> V_173 . V_174 = F_129 ( V_19 -> V_241 ) ;
for ( V_3 = 0 ; V_3 <= V_316 ; V_3 ++ ) {
struct V_155 * V_156 = V_242 [ V_3 ] ;
if ( ! V_156 )
continue;
switch ( V_3 ) {
case V_331 :
V_172 -> V_180 = F_168 ( V_156 ) ;
break;
case V_193 :
if ( F_91 ( V_156 , V_194 ,
& V_172 -> V_175 ,
V_172 -> V_176 , V_161 ) )
goto V_150;
break;
case V_332 :
{
T_2 V_333 ;
if ( F_91 ( V_156 , 1 , & V_333 ,
& V_172 -> V_202 , V_161 ) )
goto V_150;
if ( ! F_101 ( V_172 -> V_173 . V_174 ,
V_172 -> V_202 , V_161 ) )
goto V_150;
break;
}
case V_191 :
{
if ( F_84 ( V_156 , & V_172 -> V_179 ,
& V_172 -> V_177 , V_172 -> V_178 ,
V_161 ) )
goto V_150;
break;
}
case V_334 :
{
V_172 -> V_195 = F_85 ( V_156 ) ;
V_172 -> V_198 = F_86 ( V_156 ) ;
break;
}
case V_335 :
{
T_2 V_336 = F_169 ( V_156 ) ;
if ( V_336 > 1 ) {
F_88 ( V_161 , V_156 ,
L_25 ) ;
goto V_150;
}
V_172 -> V_213 = V_336 ?
V_73 :
V_337 ;
break;
}
default:
F_88 ( V_161 , V_156 , L_26 ) ;
goto V_150;
}
}
V_88 = 0 ;
V_150:
return V_88 ;
}
static int F_170 ( struct V_18 * V_19 , struct V_125 * V_126 ,
struct V_160 * V_161 )
{
struct V_171 * V_172 ;
int V_88 ;
V_172 = F_58 ( sizeof( * V_172 ) , V_118 ) ;
if ( ! V_172 )
return - V_119 ;
V_88 = F_167 ( V_19 , V_126 , V_172 , V_161 ) ;
if ( V_88 < 0 )
goto V_60;
V_88 = F_104 ( V_172 , V_161 ) ;
V_60:
F_147 ( V_172 ) ;
return V_88 ;
}
static int F_171 ( struct V_18 * V_19 , struct V_125 * V_126 ,
struct V_160 * V_161 )
{
struct V_171 * V_172 ;
int V_88 ;
V_172 = F_58 ( sizeof( * V_172 ) , V_118 ) ;
if ( ! V_172 )
return - V_119 ;
V_88 = F_167 ( V_19 , V_126 , V_172 , V_161 ) ;
if ( V_88 < 0 )
goto V_60;
V_88 = F_103 ( V_172 , V_161 ) ;
V_60:
F_147 ( V_172 ) ;
return V_88 ;
}
static int F_172 ( struct V_18 * V_19 , T_3 V_127 , T_3 V_227 , int V_128 ,
T_3 V_41 , struct V_1 * V_4 , int V_10 )
{
struct V_8 * V_9 ;
struct V_125 * V_126 ;
struct V_314 * V_315 ;
V_126 = F_115 ( V_19 , V_127 , V_227 , V_128 , sizeof( * V_315 ) , V_10 ) ;
if ( V_126 == NULL )
return - V_226 ;
V_315 = F_116 ( V_126 ) ;
V_315 -> V_318 = V_233 ;
V_315 -> V_319 = 20 ;
V_315 -> V_320 = 0 ;
V_315 -> V_321 = 0 ;
V_315 -> V_322 = V_323 ;
V_315 -> V_329 = V_4 -> V_210 ;
V_315 -> V_324 = V_325 ;
V_315 -> V_326 = V_327 ;
V_315 -> V_328 = 0 ;
if ( F_165 ( V_19 , V_332 , 1 , & V_41 ) )
goto V_236;
if ( V_4 -> V_72 != V_74 ) {
bool V_336 =
V_4 -> V_72 == V_73 ;
if ( F_173 ( V_19 , V_335 ,
V_336 ) )
goto V_236;
}
if ( V_4 -> V_58 == 1 ) {
const struct V_12 * V_13 = V_4 -> V_53 ;
if ( V_13 -> V_15 &&
F_165 ( V_19 , V_193 , V_13 -> V_15 ,
V_13 -> V_102 ) )
goto V_236;
if ( V_13 -> V_103 != V_104 &&
F_163 ( V_19 , V_13 -> V_103 , F_6 ( V_4 , V_13 ) ,
V_13 -> V_152 ) )
goto V_236;
V_9 = F_66 ( V_13 -> V_98 ) ;
if ( V_9 && F_174 ( V_19 , V_331 , V_9 -> V_235 ) )
goto V_236;
if ( V_13 -> V_61 & V_63 )
V_315 -> V_328 |= V_63 ;
if ( V_13 -> V_61 & V_62 )
V_315 -> V_328 |= V_62 ;
} else {
struct V_182 * V_183 ;
struct V_155 * V_338 ;
T_2 V_339 = 0 ;
T_2 V_340 = 0 ;
V_338 = F_175 ( V_19 , V_334 ) ;
if ( ! V_338 )
goto V_236;
F_33 (rt) {
V_9 = F_66 ( V_13 -> V_98 ) ;
if ( ! V_9 )
continue;
V_183 = F_176 ( V_19 , sizeof( * V_183 ) ) ;
if ( ! V_183 )
goto V_236;
V_183 -> V_201 = V_9 -> V_235 ;
if ( V_13 -> V_61 & V_63 ) {
V_183 -> V_200 |= V_63 ;
V_339 ++ ;
}
if ( V_13 -> V_61 & V_62 ) {
V_183 -> V_200 |= V_62 ;
V_340 ++ ;
}
if ( V_13 -> V_15 && F_165 ( V_19 , V_193 ,
V_13 -> V_15 ,
V_13 -> V_102 ) )
goto V_236;
if ( V_13 -> V_103 != V_104 &&
F_163 ( V_19 , V_13 -> V_103 ,
F_6 ( V_4 , V_13 ) ,
V_13 -> V_152 ) )
goto V_236;
V_183 -> V_341 = F_177 ( V_19 ) - ( void * ) V_183 ;
} F_34 ( V_4 ) ;
if ( V_339 == V_4 -> V_58 )
V_315 -> V_328 |= V_63 ;
if ( V_340 == V_4 -> V_58 )
V_315 -> V_328 |= V_62 ;
F_178 ( V_19 , V_338 ) ;
}
F_118 ( V_19 , V_126 ) ;
return 0 ;
V_236:
F_119 ( V_19 , V_126 ) ;
return - V_226 ;
}
static int F_179 ( struct V_18 * V_19 , struct V_247 * V_248 )
{
struct V_2 * V_2 = F_129 ( V_19 -> V_241 ) ;
struct V_1 T_1 * * V_7 ;
T_4 V_6 ;
unsigned int V_3 ;
F_65 () ;
V_3 = V_248 -> args [ 0 ] ;
if ( V_3 < V_42 )
V_3 = V_42 ;
V_7 = F_66 ( V_2 -> V_5 . V_7 ) ;
V_6 = V_2 -> V_5 . V_6 ;
for (; V_3 < V_6 ; V_3 ++ ) {
struct V_1 * V_4 ;
V_4 = F_66 ( V_7 [ V_3 ] ) ;
if ( ! V_4 )
continue;
if ( F_172 ( V_19 , F_133 ( V_248 -> V_19 ) . V_127 ,
V_248 -> V_126 -> V_245 , V_129 ,
V_3 , V_4 , V_259 ) < 0 )
break;
}
V_248 -> args [ 0 ] = V_3 ;
return V_19 -> V_20 ;
}
static inline T_4 F_180 ( struct V_1 * V_4 )
{
T_4 V_342 =
F_121 ( sizeof( struct V_314 ) )
+ F_122 ( 4 )
+ F_122 ( 1 ) ;
if ( V_4 -> V_58 == 1 ) {
struct V_12 * V_13 = V_4 -> V_53 ;
if ( V_13 -> V_98 )
V_342 += F_122 ( 4 ) ;
if ( V_13 -> V_103 != V_104 )
V_342 += F_122 ( 2 + V_13 -> V_152 ) ;
if ( V_13 -> V_15 )
V_342 += F_122 ( V_13 -> V_15 * 4 ) ;
} else {
T_4 V_343 = 0 ;
F_33 (rt) {
if ( ! F_66 ( V_13 -> V_98 ) )
continue;
V_343 += F_122 ( sizeof( struct V_182 ) ) ;
if ( V_13 -> V_103 != V_104 )
V_343 += F_122 ( 2 + V_13 -> V_152 ) ;
if ( V_13 -> V_15 )
V_343 += F_122 ( V_13 -> V_15 * 4 ) ;
} F_34 ( V_4 ) ;
V_342 += F_122 ( V_343 ) ;
}
return V_342 ;
}
static void F_63 ( int V_128 , T_3 V_41 , struct V_1 * V_4 ,
struct V_125 * V_126 , struct V_2 * V_2 , T_3 V_127 ,
unsigned int V_131 )
{
struct V_18 * V_19 ;
T_3 V_227 = V_126 ? V_126 -> V_245 : 0 ;
int V_88 = - V_238 ;
V_19 = F_124 ( F_180 ( V_4 ) , V_118 ) ;
if ( V_19 == NULL )
goto V_150;
V_88 = F_172 ( V_19 , V_127 , V_227 , V_128 , V_41 , V_4 , V_131 ) ;
if ( V_88 < 0 ) {
F_125 ( V_88 == - V_226 ) ;
F_54 ( V_19 ) ;
goto V_150;
}
F_126 ( V_19 , V_2 , V_127 , V_344 , V_126 , V_118 ) ;
return;
V_150:
if ( V_88 < 0 )
F_127 ( V_2 , V_344 , V_88 ) ;
}
static int F_181 ( struct V_18 * V_240 , struct V_125 * V_345 ,
struct V_160 * V_161 )
{
struct V_2 * V_2 = F_129 ( V_240 -> V_241 ) ;
T_3 V_127 = F_133 ( V_240 ) . V_127 ;
T_3 V_346 = V_133 ;
struct V_155 * V_242 [ V_316 + 1 ] ;
T_3 V_309 [ V_194 ] ;
struct V_16 * V_36 ;
unsigned int V_347 = 0 ;
struct V_8 * V_9 ;
struct V_1 * V_4 ;
struct V_314 * V_315 , * V_348 ;
struct V_125 * V_126 ;
struct V_18 * V_19 ;
struct V_12 * V_13 ;
T_2 V_190 ;
int V_88 ;
V_88 = F_130 ( V_345 , sizeof( * V_315 ) , V_242 , V_316 ,
V_317 , V_161 ) ;
if ( V_88 < 0 )
goto V_150;
V_315 = F_116 ( V_345 ) ;
if ( V_242 [ V_332 ] ) {
T_2 V_333 ;
if ( F_91 ( V_242 [ V_332 ] , 1 , & V_333 ,
& V_346 , V_161 ) ) {
V_88 = - V_117 ;
goto V_150;
}
if ( ! F_101 ( V_2 , V_346 , V_161 ) ) {
V_88 = - V_117 ;
goto V_150;
}
}
V_4 = F_1 ( V_2 , V_346 ) ;
if ( ! V_4 ) {
V_88 = - V_349 ;
goto V_150;
}
if ( V_315 -> V_328 & V_350 ) {
V_19 = F_124 ( F_180 ( V_4 ) , V_118 ) ;
if ( ! V_19 ) {
V_88 = - V_238 ;
goto V_150;
}
V_88 = F_172 ( V_19 , V_127 , V_345 -> V_245 ,
V_129 , V_346 , V_4 , 0 ) ;
if ( V_88 < 0 ) {
F_125 ( V_88 == - V_226 ) ;
goto V_351;
}
return F_134 ( V_19 , V_2 , V_127 ) ;
}
if ( V_242 [ V_193 ] ) {
if ( F_91 ( V_242 [ V_193 ] , V_194 , & V_190 ,
V_309 , V_161 ) != 0 ) {
V_88 = - V_117 ;
goto V_150;
}
V_347 = V_190 * sizeof( struct V_16 ) ;
}
V_19 = F_182 ( V_352 , V_118 ) ;
if ( ! V_19 ) {
V_88 = - V_238 ;
goto V_150;
}
V_19 -> V_23 = F_13 ( V_24 ) ;
if ( V_347 ) {
bool V_44 ;
int V_101 ;
if ( F_48 ( V_19 , V_347 ) ) {
V_88 = - V_238 ;
goto V_351;
}
F_183 ( V_19 , V_347 ) ;
F_50 ( V_19 , V_347 ) ;
F_43 ( V_19 ) ;
V_36 = F_23 ( V_19 ) ;
V_44 = true ;
for ( V_101 = V_190 - 1 ; V_101 >= 0 ; V_101 -- ) {
V_36 [ V_101 ] = F_51 ( V_309 [ V_101 ] ,
1 , 0 , V_44 ) ;
V_44 = false ;
}
}
V_13 = F_31 ( V_4 , V_19 ) ;
if ( ! V_13 ) {
V_88 = - V_349 ;
goto V_351;
}
if ( V_347 ) {
F_42 ( V_19 , V_347 ) ;
F_43 ( V_19 ) ;
}
V_126 = F_115 ( V_19 , V_127 , V_345 -> V_245 ,
V_129 , sizeof( * V_348 ) , 0 ) ;
if ( ! V_126 ) {
V_88 = - V_226 ;
goto V_351;
}
V_348 = F_116 ( V_126 ) ;
V_348 -> V_318 = V_233 ;
V_348 -> V_319 = 20 ;
V_348 -> V_320 = 0 ;
V_348 -> V_322 = V_323 ;
V_348 -> V_326 = V_327 ;
V_348 -> V_324 = V_325 ;
V_348 -> V_329 = V_4 -> V_210 ;
V_348 -> V_328 = 0 ;
if ( F_165 ( V_19 , V_332 , 1 , & V_346 ) )
goto V_236;
if ( V_13 -> V_15 &&
F_165 ( V_19 , V_193 , V_13 -> V_15 ,
V_13 -> V_102 ) )
goto V_236;
if ( V_13 -> V_103 != V_104 &&
F_163 ( V_19 , V_13 -> V_103 , F_6 ( V_4 , V_13 ) ,
V_13 -> V_152 ) )
goto V_236;
V_9 = F_66 ( V_13 -> V_98 ) ;
if ( V_9 && F_174 ( V_19 , V_331 , V_9 -> V_235 ) )
goto V_236;
F_118 ( V_19 , V_126 ) ;
V_88 = F_134 ( V_19 , V_2 , V_127 ) ;
V_150:
return V_88 ;
V_236:
F_119 ( V_19 , V_126 ) ;
V_88 = - V_226 ;
V_351:
F_54 ( V_19 ) ;
return V_88 ;
}
static int F_184 ( struct V_2 * V_2 , T_4 V_353 )
{
T_4 V_115 = sizeof( struct V_1 * ) * V_353 ;
T_4 V_354 ;
T_4 V_355 ;
struct V_1 T_1 * * V_309 = NULL , * * V_121 ;
struct V_1 * V_356 = NULL , * V_357 = NULL ;
unsigned V_3 ;
if ( V_115 ) {
V_309 = F_185 ( V_115 , V_118 ) ;
if ( ! V_309 )
goto V_358;
}
if ( V_353 > V_359 ) {
struct V_8 * V_360 = V_2 -> V_361 ;
V_356 = F_55 ( 1 , V_360 -> V_151 , 0 ) ;
if ( F_71 ( V_356 ) )
goto V_362;
F_82 ( V_356 -> V_53 -> V_98 , V_360 ) ;
V_356 -> V_210 = V_363 ;
V_356 -> V_67 = V_69 ;
V_356 -> V_72 = V_74 ;
V_356 -> V_53 -> V_103 = V_105 ;
V_356 -> V_53 -> V_152 = V_360 -> V_151 ;
memcpy ( F_5 ( V_356 , V_356 -> V_53 ) , V_360 -> V_106 ,
V_360 -> V_151 ) ;
}
if ( V_353 > V_364 ) {
struct V_8 * V_360 = V_2 -> V_361 ;
V_357 = F_55 ( 1 , V_360 -> V_151 , 0 ) ;
if ( F_71 ( V_357 ) )
goto V_365;
F_82 ( V_357 -> V_53 -> V_98 , V_360 ) ;
V_357 -> V_210 = V_363 ;
V_357 -> V_67 = V_78 ;
V_357 -> V_72 = V_74 ;
V_357 -> V_53 -> V_103 = V_105 ;
V_357 -> V_53 -> V_152 = V_360 -> V_151 ;
memcpy ( F_5 ( V_357 , V_357 -> V_53 ) , V_360 -> V_106 ,
V_360 -> V_151 ) ;
}
F_186 () ;
V_121 = F_66 ( V_2 -> V_5 . V_7 ) ;
V_354 = V_2 -> V_5 . V_6 ;
for ( V_3 = V_353 ; V_3 < V_354 ; V_3 ++ )
F_64 ( V_2 , V_3 , NULL , NULL ) ;
V_355 = V_115 ;
if ( V_354 < V_353 )
V_355 = V_354 * sizeof( struct V_1 * ) ;
memcpy ( V_309 , V_121 , V_355 ) ;
if ( ( V_354 <= V_364 ) &&
( V_353 > V_364 ) ) {
F_82 ( V_309 [ V_364 ] , V_357 ) ;
V_357 = NULL ;
}
if ( ( V_354 <= V_359 ) &&
( V_353 > V_359 ) ) {
F_82 ( V_309 [ V_359 ] , V_356 ) ;
V_356 = NULL ;
}
V_2 -> V_5 . V_6 = V_353 ;
F_67 ( V_2 -> V_5 . V_7 , V_309 ) ;
F_187 () ;
F_60 ( V_357 ) ;
F_60 ( V_356 ) ;
if ( V_121 ) {
F_188 () ;
F_189 ( V_121 ) ;
}
return 0 ;
V_365:
F_60 ( V_356 ) ;
V_362:
F_189 ( V_309 ) ;
V_358:
return - V_119 ;
}
static int F_190 ( struct V_261 * V_275 , int V_263 ,
void T_5 * V_264 , T_4 * V_265 , T_6 * V_266 )
{
struct V_2 * V_2 = V_275 -> V_268 ;
int V_6 = V_2 -> V_5 . V_6 ;
int V_269 ;
struct V_261 V_366 = {
. V_367 = V_275 -> V_367 ,
. V_268 = & V_6 ,
. V_368 = sizeof( int ) ,
. V_369 = V_275 -> V_369 ,
. V_270 = & V_370 ,
. V_271 = & V_371 ,
} ;
V_269 = F_191 ( & V_366 , V_263 , V_264 , V_265 , V_266 ) ;
if ( V_263 && V_269 == 0 )
V_269 = F_184 ( V_2 , V_6 ) ;
return V_269 ;
}
static int F_192 ( struct V_2 * V_2 )
{
struct V_261 * V_275 ;
int V_101 ;
V_2 -> V_5 . V_6 = 0 ;
V_2 -> V_5 . V_7 = NULL ;
V_2 -> V_5 . V_75 = 1 ;
V_2 -> V_5 . V_372 = 255 ;
V_275 = F_144 ( V_373 , sizeof( V_373 ) , V_118 ) ;
if ( V_275 == NULL )
return - V_119 ;
for ( V_101 = 0 ; V_101 < F_145 ( V_373 ) - 1 ; V_101 ++ )
V_275 [ V_101 ] . V_268 = ( char * ) V_2 + ( V_277 ) V_275 [ V_101 ] . V_268 ;
V_2 -> V_5 . V_262 = F_146 ( V_2 , L_27 , V_275 ) ;
if ( V_2 -> V_5 . V_262 == NULL ) {
F_147 ( V_275 ) ;
return - V_119 ;
}
return 0 ;
}
static void F_193 ( struct V_2 * V_2 )
{
struct V_1 T_1 * * V_7 ;
T_4 V_6 ;
struct V_261 * V_275 ;
unsigned int V_3 ;
V_275 = V_2 -> V_5 . V_262 -> V_280 ;
F_149 ( V_2 -> V_5 . V_262 ) ;
F_147 ( V_275 ) ;
F_186 () ;
V_7 = F_66 ( V_2 -> V_5 . V_7 ) ;
V_6 = V_2 -> V_5 . V_6 ;
for ( V_3 = 0 ; V_3 < V_6 ; V_3 ++ ) {
struct V_1 * V_4 = F_66 ( V_7 [ V_3 ] ) ;
F_82 ( V_7 [ V_3 ] , NULL ) ;
F_62 ( V_2 , V_3 , V_4 , NULL , NULL ) ;
F_60 ( V_4 ) ;
}
F_187 () ;
F_189 ( V_7 ) ;
}
static int T_7 F_194 ( void )
{
int V_88 ;
F_195 ( sizeof( struct V_16 ) != 4 ) ;
V_88 = F_196 ( & V_374 ) ;
if ( V_88 )
goto V_60;
V_88 = F_197 ( & V_375 ) ;
if ( V_88 )
goto V_376;
F_198 ( & V_377 ) ;
F_199 ( & V_378 ) ;
F_200 ( V_379 , V_129 , F_171 , NULL , NULL ) ;
F_200 ( V_379 , V_130 , F_170 , NULL , NULL ) ;
F_200 ( V_379 , V_380 , F_181 , F_179 ,
NULL ) ;
F_200 ( V_379 , V_381 , F_128 ,
F_135 , NULL ) ;
V_88 = 0 ;
V_60:
return V_88 ;
V_376:
F_201 ( & V_374 ) ;
goto V_60;
}
static void T_8 F_202 ( void )
{
F_203 ( V_379 ) ;
F_204 ( & V_378 ) ;
F_205 ( & V_377 ) ;
F_206 ( & V_375 ) ;
F_201 ( & V_374 ) ;
}

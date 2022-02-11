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
static int F_84 ( struct V_155 * V_156 ,
struct V_1 * V_4 )
{
struct V_2 * V_2 = V_156 -> V_157 . V_158 ;
struct V_12 * V_13 = V_4 -> V_53 ;
int V_88 ;
int V_101 ;
if ( ! V_13 )
return - V_119 ;
V_88 = - V_117 ;
V_13 -> V_15 = V_156 -> V_159 ;
for ( V_101 = 0 ; V_101 < V_13 -> V_15 ; V_101 ++ )
V_13 -> V_102 [ V_101 ] = V_156 -> V_160 [ V_101 ] ;
V_13 -> V_103 = V_156 -> V_161 ;
memcpy ( F_5 ( V_4 , V_13 ) , V_156 -> V_162 , V_156 -> V_163 ) ;
V_13 -> V_152 = V_156 -> V_163 ;
V_88 = F_80 ( V_2 , V_4 , V_13 , V_156 -> V_164 ) ;
if ( V_88 )
goto V_150;
if ( V_13 -> V_61 & ( V_62 | V_63 ) )
V_4 -> V_59 -- ;
return 0 ;
V_150:
return V_88 ;
}
static int F_85 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_12 * V_13 , int V_146 , struct V_165 * V_166 ,
struct V_165 * V_167 , T_2 V_113 )
{
int V_88 = - V_119 ;
if ( ! V_13 )
goto V_150;
if ( V_167 ) {
V_88 = F_86 ( V_167 , V_113 ,
& V_13 -> V_15 , V_13 -> V_102 ) ;
if ( V_88 )
goto V_150;
}
if ( V_166 ) {
V_88 = F_87 ( V_166 , & V_13 -> V_152 , & V_13 -> V_103 ,
F_5 ( V_4 , V_13 ) ) ;
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
static T_2 F_88 ( struct V_168 * V_169 , int V_20 ,
T_2 V_170 , T_2 * V_171 ,
T_2 * V_113 )
{
int V_172 = V_20 ;
T_2 V_173 = 0 ;
* V_171 = 0 ;
* V_113 = 0 ;
while ( F_89 ( V_169 , V_172 ) ) {
struct V_165 * V_174 , * V_175 = F_90 ( V_169 ) ;
int V_176 ;
T_2 V_177 = 0 ;
V_176 = F_91 ( V_169 ) ;
V_174 = F_92 ( V_175 , V_176 , V_178 ) ;
if ( V_174 && F_93 ( V_174 ) >=
F_94 ( struct V_179 , V_180 ) ) {
int V_181 = F_93 ( V_174 ) -
F_94 ( struct V_179 , V_180 ) ;
if ( V_181 <= V_182 )
* V_171 = F_95 ( V_183 , * V_171 ,
V_181 ) ;
}
V_174 = F_92 ( V_175 , V_176 , V_184 ) ;
if ( V_174 &&
F_86 ( V_174 , V_185 , & V_177 , NULL ) != 0 )
return 0 ;
* V_113 = F_95 ( T_2 , * V_113 , V_177 ) ;
if ( V_173 == 255 )
return 0 ;
V_173 ++ ;
V_169 = F_96 ( V_169 , & V_172 ) ;
}
return V_172 > 0 ? 0 : V_173 ;
}
static int F_97 ( struct V_155 * V_156 ,
struct V_1 * V_4 , T_2 V_113 )
{
struct V_168 * V_169 = V_156 -> V_186 ;
struct V_165 * V_187 , * V_188 ;
int V_172 = V_156 -> V_189 ;
int V_88 = 0 ;
T_2 V_173 = 0 ;
F_98 (rt) {
int V_176 ;
V_187 = NULL ;
V_188 = NULL ;
V_88 = - V_117 ;
if ( ! F_89 ( V_169 , V_172 ) )
goto V_150;
if ( V_169 -> V_190 || V_169 -> V_191 )
goto V_150;
V_176 = F_91 ( V_169 ) ;
if ( V_176 > 0 ) {
struct V_165 * V_175 = F_90 ( V_169 ) ;
V_187 = F_92 ( V_175 , V_176 , V_178 ) ;
V_188 = F_92 ( V_175 , V_176 , V_184 ) ;
}
V_88 = F_85 ( V_156 -> V_157 . V_158 , V_4 , V_13 ,
V_169 -> V_192 , V_187 , V_188 ,
V_113 ) ;
if ( V_88 )
goto V_150;
if ( V_13 -> V_61 & ( V_62 | V_63 ) )
V_4 -> V_59 -- ;
V_169 = F_96 ( V_169 , & V_172 ) ;
V_173 ++ ;
} F_34 ( V_4 ) ;
V_4 -> V_58 = V_173 ;
return 0 ;
V_150:
return V_88 ;
}
static int F_99 ( struct V_155 * V_156 )
{
struct V_1 T_1 * * V_7 ;
struct V_2 * V_2 = V_156 -> V_157 . V_158 ;
struct V_1 * V_4 , * V_121 ;
int V_88 = - V_117 ;
T_2 V_171 ;
unsigned V_3 ;
T_2 V_113 ;
T_2 V_173 ;
V_3 = V_156 -> V_193 ;
if ( ( V_3 == V_133 ) &&
( V_156 -> V_194 & V_195 ) ) {
V_3 = F_68 ( V_2 ) ;
}
if ( V_3 < V_42 )
goto V_150;
if ( V_3 >= V_2 -> V_5 . V_6 )
goto V_150;
V_88 = - V_196 ;
if ( V_156 -> V_194 & V_197 )
goto V_150;
V_88 = - V_198 ;
V_7 = F_66 ( V_2 -> V_5 . V_7 ) ;
V_121 = F_66 ( V_7 [ V_3 ] ) ;
if ( ( V_156 -> V_194 & V_199 ) && V_121 )
goto V_150;
V_88 = - V_198 ;
if ( ! ( V_156 -> V_194 & V_132 ) && V_121 )
goto V_150;
V_88 = - V_200 ;
if ( ! ( V_156 -> V_194 & V_195 ) && ! V_121 )
goto V_150;
V_88 = - V_117 ;
if ( V_156 -> V_186 ) {
V_173 = F_88 ( V_156 -> V_186 , V_156 -> V_189 ,
V_156 -> V_163 , & V_171 ,
& V_113 ) ;
} else {
V_171 = V_156 -> V_163 ;
V_113 = V_156 -> V_159 ;
V_173 = 1 ;
}
if ( V_173 == 0 )
goto V_150;
V_88 = - V_119 ;
V_4 = F_55 ( V_173 , V_171 , V_113 ) ;
if ( F_71 ( V_4 ) ) {
V_88 = F_81 ( V_4 ) ;
goto V_150;
}
V_4 -> V_201 = V_156 -> V_202 ;
V_4 -> V_67 = V_156 -> V_203 ;
V_4 -> V_72 = V_156 -> V_204 ;
if ( V_156 -> V_186 )
V_88 = F_97 ( V_156 , V_4 , V_113 ) ;
else
V_88 = F_84 ( V_156 , V_4 ) ;
if ( V_88 )
goto V_205;
F_64 ( V_2 , V_3 , V_4 , & V_156 -> V_157 ) ;
return 0 ;
V_205:
F_60 ( V_4 ) ;
V_150:
return V_88 ;
}
static int F_100 ( struct V_155 * V_156 )
{
struct V_2 * V_2 = V_156 -> V_157 . V_158 ;
unsigned V_3 ;
int V_88 = - V_117 ;
V_3 = V_156 -> V_193 ;
if ( V_3 < V_42 )
goto V_150;
if ( V_3 >= V_2 -> V_5 . V_6 )
goto V_150;
F_64 ( V_2 , V_3 , NULL , & V_156 -> V_157 ) ;
V_88 = 0 ;
V_150:
return V_88 ;
}
static void F_101 ( struct V_21 * V_22 ,
struct V_206 * V_207 )
{
struct V_208 * V_209 ;
int V_101 ;
memset ( V_207 , 0 , sizeof( * V_207 ) ) ;
F_102 (i) {
struct V_206 V_210 ;
unsigned int V_211 ;
V_209 = F_103 ( V_22 -> V_207 , V_101 ) ;
do {
V_211 = F_104 ( & V_209 -> V_212 ) ;
V_210 = V_209 -> V_207 ;
} while ( F_105 ( & V_209 -> V_212 , V_211 ) );
V_207 -> V_90 += V_210 . V_90 ;
V_207 -> V_91 += V_210 . V_91 ;
V_207 -> V_25 += V_210 . V_25 ;
V_207 -> V_26 += V_210 . V_26 ;
V_207 -> V_109 += V_210 . V_109 ;
V_207 -> V_108 += V_210 . V_108 ;
V_207 -> V_93 += V_210 . V_93 ;
V_207 -> V_213 += V_210 . V_213 ;
V_207 -> V_97 += V_210 . V_97 ;
}
}
static int F_106 ( struct V_18 * V_19 ,
const struct V_8 * V_9 )
{
struct V_206 * V_207 ;
struct V_21 * V_22 ;
struct V_165 * V_174 ;
V_22 = F_14 ( V_9 ) ;
if ( ! V_22 )
return - V_214 ;
V_174 = F_107 ( V_19 , V_215 ,
sizeof( struct V_206 ) ,
V_216 ) ;
if ( ! V_174 )
return - V_217 ;
V_207 = F_108 ( V_174 ) ;
F_101 ( V_22 , V_207 ) ;
return 0 ;
}
static T_4 F_109 ( const struct V_8 * V_9 )
{
struct V_21 * V_22 ;
V_22 = F_14 ( V_9 ) ;
if ( ! V_22 )
return 0 ;
return F_110 ( sizeof( struct V_206 ) ) ;
}
static int F_111 ( struct V_18 * V_19 , struct V_21 * V_22 ,
T_3 V_127 , T_3 V_218 , int V_128 ,
unsigned int V_10 , int type )
{
struct V_125 * V_126 ;
struct V_219 * V_220 ;
bool V_221 = false ;
V_126 = F_112 ( V_19 , V_127 , V_218 , V_128 , sizeof( struct V_219 ) ,
V_10 ) ;
if ( ! V_126 )
return - V_217 ;
if ( type == V_222 )
V_221 = true ;
V_220 = F_113 ( V_126 ) ;
V_220 -> V_223 = V_224 ;
if ( F_114 ( V_19 , V_225 , V_22 -> V_9 -> V_226 ) < 0 )
goto V_227;
if ( ( V_221 || type == V_228 ) &&
F_114 ( V_19 , V_228 ,
V_22 -> V_92 ) < 0 )
goto V_227;
F_115 ( V_19 , V_126 ) ;
return 0 ;
V_227:
F_116 ( V_19 , V_126 ) ;
return - V_217 ;
}
static int F_117 ( int type )
{
int V_115 = F_118 ( sizeof( struct V_219 ) )
+ F_119 ( 4 ) ;
bool V_221 = false ;
if ( type == V_222 )
V_221 = true ;
if ( V_221 || type == V_228 )
V_115 += F_119 ( 4 ) ;
return V_115 ;
}
static void F_120 ( struct V_2 * V_2 , int V_128 ,
int type , struct V_21 * V_22 )
{
struct V_18 * V_19 ;
int V_88 = - V_229 ;
V_19 = F_121 ( F_117 ( type ) , V_118 ) ;
if ( ! V_19 )
goto V_150;
V_88 = F_111 ( V_19 , V_22 , 0 , 0 , V_128 , 0 , type ) ;
if ( V_88 < 0 ) {
F_122 ( V_88 == - V_217 ) ;
F_54 ( V_19 ) ;
goto V_150;
}
F_123 ( V_19 , V_2 , 0 , V_230 , NULL , V_118 ) ;
return;
V_150:
if ( V_88 < 0 )
F_124 ( V_2 , V_230 , V_88 ) ;
}
static int F_125 ( struct V_18 * V_231 ,
struct V_125 * V_126 ,
struct V_232 * V_233 )
{
struct V_2 * V_2 = F_126 ( V_231 -> V_234 ) ;
struct V_165 * V_235 [ V_236 + 1 ] ;
struct V_219 * V_220 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
struct V_18 * V_19 ;
int V_226 ;
int V_88 ;
V_88 = F_127 ( V_126 , sizeof( * V_220 ) , V_235 , V_236 ,
V_237 , NULL ) ;
if ( V_88 < 0 )
goto V_150;
V_88 = - V_117 ;
if ( ! V_235 [ V_225 ] )
goto V_150;
V_226 = F_128 ( V_235 [ V_225 ] ) ;
V_9 = F_129 ( V_2 , V_226 ) ;
if ( ! V_9 )
goto V_150;
V_22 = F_14 ( V_9 ) ;
if ( ! V_22 )
goto V_150;
V_88 = - V_229 ;
V_19 = F_121 ( F_117 ( V_222 ) , V_118 ) ;
if ( ! V_19 )
goto V_150;
V_88 = F_111 ( V_19 , V_22 ,
F_130 ( V_231 ) . V_127 ,
V_126 -> V_238 , V_239 , 0 ,
V_222 ) ;
if ( V_88 < 0 ) {
F_122 ( V_88 == - V_217 ) ;
F_54 ( V_19 ) ;
goto V_150;
}
V_88 = F_131 ( V_19 , V_2 , F_130 ( V_231 ) . V_127 ) ;
V_150:
return V_88 ;
}
static int F_132 ( struct V_18 * V_19 ,
struct V_240 * V_241 )
{
struct V_2 * V_2 = F_126 ( V_19 -> V_234 ) ;
struct V_242 * V_243 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
int V_244 , V_245 ;
int V_246 , V_247 ;
V_247 = V_241 -> args [ 0 ] ;
V_245 = V_244 = V_241 -> args [ 1 ] ;
for ( V_246 = V_247 ; V_246 < V_248 ; V_246 ++ , V_245 = 0 ) {
V_244 = 0 ;
V_243 = & V_2 -> V_249 [ V_246 ] ;
F_133 () ;
V_241 -> V_218 = V_2 -> V_250 ;
F_134 (dev, head, index_hlist) {
if ( V_244 < V_245 )
goto V_251;
V_22 = F_14 ( V_9 ) ;
if ( ! V_22 )
goto V_251;
if ( F_111 ( V_19 , V_22 ,
F_130 ( V_241 -> V_19 ) . V_127 ,
V_241 -> V_126 -> V_238 ,
V_239 ,
V_252 ,
V_222 ) < 0 ) {
F_135 () ;
goto V_253;
}
F_136 ( V_241 , F_137 ( V_19 ) ) ;
V_251:
V_244 ++ ;
}
F_135 () ;
}
V_253:
V_241 -> args [ 0 ] = V_246 ;
V_241 -> args [ 1 ] = V_244 ;
return V_19 -> V_20 ;
}
static int F_138 ( struct V_254 * V_255 , int V_256 ,
void T_5 * V_257 ,
T_4 * V_258 , T_6 * V_259 )
{
int V_260 = * ( int * ) V_255 -> V_261 ;
int V_262 = F_139 ( V_255 , V_256 , V_257 , V_258 , V_259 ) ;
if ( V_256 ) {
struct V_21 * V_22 = V_255 -> V_263 ;
int V_101 = ( int * ) V_255 -> V_261 - ( int * ) V_22 ;
struct V_2 * V_2 = V_255 -> V_264 ;
int V_265 = * ( int * ) V_255 -> V_261 ;
if ( V_101 == F_94 ( struct V_21 , V_92 ) &&
V_265 != V_260 ) {
F_120 ( V_2 , V_239 ,
V_228 , V_22 ) ;
}
}
return V_262 ;
}
static int F_140 ( struct V_8 * V_9 ,
struct V_21 * V_22 )
{
char V_266 [ sizeof( L_2 ) + V_267 ] ;
struct V_2 * V_2 = F_17 ( V_9 ) ;
struct V_254 * V_268 ;
int V_101 ;
V_268 = F_141 ( & V_269 , sizeof( V_269 ) , V_118 ) ;
if ( ! V_268 )
goto V_60;
for ( V_101 = 0 ; V_101 < F_142 ( V_269 ) ; V_101 ++ ) {
V_268 [ V_101 ] . V_261 = ( char * ) V_22 + ( V_270 ) V_268 [ V_101 ] . V_261 ;
V_268 [ V_101 ] . V_263 = V_22 ;
V_268 [ V_101 ] . V_264 = V_2 ;
}
snprintf ( V_266 , sizeof( V_266 ) , L_3 , V_9 -> V_271 ) ;
V_22 -> V_272 = F_143 ( V_2 , V_266 , V_268 ) ;
if ( ! V_22 -> V_272 )
goto free;
F_120 ( V_2 , V_239 , V_222 , V_22 ) ;
return 0 ;
free:
F_144 ( V_268 ) ;
V_60:
return - V_229 ;
}
static void F_145 ( struct V_8 * V_9 ,
struct V_21 * V_22 )
{
struct V_2 * V_2 = F_17 ( V_9 ) ;
struct V_254 * V_268 ;
V_268 = V_22 -> V_272 -> V_273 ;
F_146 ( V_22 -> V_272 ) ;
F_144 ( V_268 ) ;
F_120 ( V_2 , V_274 , 0 , V_22 ) ;
}
static struct V_21 * F_147 ( struct V_8 * V_9 )
{
struct V_21 * V_22 ;
int V_88 = - V_119 ;
int V_101 ;
F_65 () ;
V_22 = F_58 ( sizeof( * V_22 ) , V_118 ) ;
if ( ! V_22 )
return F_57 ( V_88 ) ;
V_22 -> V_207 = F_148 ( struct V_208 ) ;
if ( ! V_22 -> V_207 )
goto free;
F_102 (i) {
struct V_208 * V_275 ;
V_275 = F_103 ( V_22 -> V_207 , V_101 ) ;
F_149 ( & V_275 -> V_212 ) ;
}
V_22 -> V_9 = V_9 ;
V_88 = F_140 ( V_9 , V_22 ) ;
if ( V_88 )
goto free;
F_67 ( V_9 -> V_276 , V_22 ) ;
return V_22 ;
free:
F_150 ( V_22 -> V_207 ) ;
F_144 ( V_22 ) ;
return F_57 ( V_88 ) ;
}
static void F_151 ( struct V_277 * V_243 )
{
struct V_21 * V_22 = F_152 ( V_243 , struct V_21 , V_278 ) ;
F_150 ( V_22 -> V_207 ) ;
F_144 ( V_22 ) ;
}
static void F_153 ( struct V_8 * V_9 , int V_128 )
{
struct V_1 T_1 * * V_7 ;
struct V_2 * V_2 = F_17 ( V_9 ) ;
T_2 V_57 , V_279 ;
unsigned V_3 ;
V_7 = F_66 ( V_2 -> V_5 . V_7 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 . V_6 ; V_3 ++ ) {
struct V_1 * V_4 = F_66 ( V_7 [ V_3 ] ) ;
if ( ! V_4 )
continue;
V_57 = 0 ;
V_279 = 0 ;
F_98 (rt) {
unsigned int V_61 = V_13 -> V_61 ;
if ( F_66 ( V_13 -> V_98 ) != V_9 )
goto V_280;
switch ( V_128 ) {
case V_281 :
case V_282 :
V_61 |= V_62 ;
case V_283 :
V_61 |= V_63 ;
break;
}
if ( V_128 == V_282 )
F_82 ( V_13 -> V_98 , NULL ) ;
if ( V_13 -> V_61 != V_61 )
F_154 ( V_13 -> V_61 , V_61 ) ;
V_280:
if ( ! ( V_61 & ( V_62 | V_63 ) ) )
V_57 ++ ;
if ( ! F_66 ( V_13 -> V_98 ) )
V_279 ++ ;
} F_34 ( V_4 ) ;
F_154 ( V_4 -> V_59 , V_57 ) ;
if ( V_128 == V_282 && V_279 == V_4 -> V_58 )
F_64 ( V_2 , V_3 , NULL , NULL ) ;
}
}
static void F_155 ( struct V_8 * V_9 , unsigned int V_10 )
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
F_98 (rt) {
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
F_154 ( V_13 -> V_61 , V_61 ) ;
} F_34 ( V_4 ) ;
F_154 ( V_4 -> V_59 , V_57 ) ;
}
}
static int F_156 ( struct V_284 * V_285 , unsigned long V_128 ,
void * V_286 )
{
struct V_8 * V_9 = F_157 ( V_286 ) ;
struct V_21 * V_22 ;
unsigned int V_10 ;
if ( V_128 == V_287 ) {
if ( V_9 -> type == V_288 ||
V_9 -> type == V_289 ||
V_9 -> type == V_290 ||
V_9 -> type == V_291 ||
V_9 -> type == V_292 ) {
V_22 = F_147 ( V_9 ) ;
if ( F_71 ( V_22 ) )
return F_158 ( F_81 ( V_22 ) ) ;
}
return V_293 ;
}
V_22 = F_14 ( V_9 ) ;
if ( ! V_22 )
return V_293 ;
switch ( V_128 ) {
case V_281 :
F_153 ( V_9 , V_128 ) ;
break;
case V_294 :
V_10 = F_83 ( V_9 ) ;
if ( V_10 & ( V_153 | V_154 ) )
F_155 ( V_9 , V_62 | V_63 ) ;
else
F_155 ( V_9 , V_62 ) ;
break;
case V_283 :
V_10 = F_83 ( V_9 ) ;
if ( V_10 & ( V_153 | V_154 ) )
F_155 ( V_9 , V_62 | V_63 ) ;
else
F_153 ( V_9 , V_128 ) ;
break;
case V_282 :
F_153 ( V_9 , V_128 ) ;
V_22 = F_14 ( V_9 ) ;
if ( V_22 ) {
F_145 ( V_9 , V_22 ) ;
F_82 ( V_9 -> V_276 , NULL ) ;
F_159 ( & V_22 -> V_278 , F_151 ) ;
}
break;
case V_295 :
V_22 = F_14 ( V_9 ) ;
if ( V_22 ) {
int V_88 ;
F_145 ( V_9 , V_22 ) ;
V_88 = F_140 ( V_9 , V_22 ) ;
if ( V_88 )
return F_158 ( V_88 ) ;
}
break;
}
return V_293 ;
}
static int F_160 ( struct V_18 * V_19 ,
T_2 V_268 , const void * V_134 , int V_296 )
{
static const int V_297 [ V_298 + 1 ] = {
V_299 , V_300 , V_301 , V_302 ,
} ;
struct V_165 * V_174 ;
struct V_179 * V_166 ;
int V_303 = V_304 ;
V_174 = F_161 ( V_19 , V_178 , V_296 + 2 ) ;
if ( ! V_174 )
return - V_217 ;
if ( V_268 <= V_298 )
V_303 = V_297 [ V_268 ] ;
V_166 = F_108 ( V_174 ) ;
V_166 -> V_305 = V_303 ;
memcpy ( V_166 -> V_180 , V_134 , V_296 ) ;
return 0 ;
}
int F_162 ( struct V_18 * V_19 , int V_306 ,
T_2 V_307 , const T_3 V_41 [] )
{
struct V_165 * V_174 ;
struct V_16 * V_308 ;
bool V_44 ;
int V_101 ;
V_174 = F_161 ( V_19 , V_306 , V_307 * 4 ) ;
if ( ! V_174 )
return - V_217 ;
V_308 = F_108 ( V_174 ) ;
V_44 = true ;
for ( V_101 = V_307 - 1 ; V_101 >= 0 ; V_101 -- ) {
V_308 [ V_101 ] = F_51 ( V_41 [ V_101 ] , 0 , 0 , V_44 ) ;
V_44 = false ;
}
return 0 ;
}
int F_86 ( const struct V_165 * V_174 ,
T_2 V_113 , T_2 * V_307 , T_3 V_41 [] )
{
unsigned V_20 = F_93 ( V_174 ) ;
struct V_16 * V_308 ;
T_2 V_309 ;
bool V_44 ;
int V_101 ;
if ( V_20 & 3 || V_20 / 4 > 255 )
return - V_117 ;
V_309 = V_20 / 4 ;
if ( V_309 > V_113 )
return - V_117 ;
if ( ! V_41 )
goto V_60;
V_308 = F_108 ( V_174 ) ;
V_44 = true ;
for ( V_101 = V_309 - 1 ; V_101 >= 0 ; V_101 -- , V_44 = false ) {
struct V_33 V_34 ;
V_34 = F_24 ( V_308 + V_101 ) ;
if ( ( V_34 . V_44 != V_44 ) || V_34 . V_76 || V_34 . V_310 )
return - V_117 ;
switch ( V_34 . V_41 ) {
case V_311 :
return - V_117 ;
}
V_41 [ V_101 ] = V_34 . V_41 ;
}
V_60:
* V_307 = V_309 ;
return 0 ;
}
int F_87 ( const struct V_165 * V_174 , T_2 * V_181 ,
T_2 * V_312 , T_2 V_313 [] )
{
struct V_179 * V_166 = F_108 ( V_174 ) ;
int V_88 = - V_117 ;
int V_296 ;
if ( F_93 ( V_174 ) < F_94 ( struct V_179 , V_180 ) )
goto V_150;
V_296 = F_93 ( V_174 ) -
F_94 ( struct V_179 , V_180 ) ;
if ( V_296 > V_182 )
goto V_150;
switch ( V_166 -> V_305 ) {
case V_302 :
* V_312 = V_105 ;
break;
case V_299 :
* V_312 = V_147 ;
if ( V_296 != 4 )
goto V_150;
break;
case V_300 :
* V_312 = V_148 ;
if ( V_296 != 16 )
goto V_150;
break;
default:
goto V_150;
}
memcpy ( V_313 , V_166 -> V_180 , V_296 ) ;
* V_181 = V_296 ;
V_88 = 0 ;
V_150:
return V_88 ;
}
static int F_163 ( struct V_18 * V_19 , struct V_125 * V_126 ,
struct V_155 * V_156 )
{
struct V_314 * V_315 ;
struct V_165 * V_235 [ V_316 + 1 ] ;
int V_3 ;
int V_88 ;
V_88 = F_127 ( V_126 , sizeof( * V_315 ) , V_235 , V_316 , V_317 ,
NULL ) ;
if ( V_88 < 0 )
goto V_150;
V_88 = - V_117 ;
V_315 = F_113 ( V_126 ) ;
if ( V_315 -> V_318 != V_224 )
goto V_150;
if ( V_315 -> V_319 != 20 )
goto V_150;
if ( V_315 -> V_320 != 0 )
goto V_150;
if ( V_315 -> V_321 != 0 )
goto V_150;
if ( V_315 -> V_322 != V_323 )
goto V_150;
if ( V_315 -> V_324 != V_325 )
goto V_150;
if ( V_315 -> V_326 != V_327 )
goto V_150;
if ( V_315 -> V_328 != 0 )
goto V_150;
V_156 -> V_193 = V_133 ;
V_156 -> V_202 = V_315 -> V_329 ;
V_156 -> V_161 = V_104 ;
V_156 -> V_204 = V_74 ;
V_156 -> V_194 = V_126 -> V_330 ;
V_156 -> V_157 . V_127 = F_130 ( V_19 ) . V_127 ;
V_156 -> V_157 . V_126 = V_126 ;
V_156 -> V_157 . V_158 = F_126 ( V_19 -> V_234 ) ;
for ( V_3 = 0 ; V_3 <= V_316 ; V_3 ++ ) {
struct V_165 * V_174 = V_235 [ V_3 ] ;
if ( ! V_174 )
continue;
switch ( V_3 ) {
case V_331 :
V_156 -> V_164 = F_164 ( V_174 ) ;
break;
case V_184 :
if ( F_86 ( V_174 , V_185 ,
& V_156 -> V_159 ,
V_156 -> V_160 ) )
goto V_150;
break;
case V_332 :
{
T_2 V_333 ;
if ( F_86 ( V_174 , 1 , & V_333 ,
& V_156 -> V_193 ) )
goto V_150;
if ( V_156 -> V_193 < V_42 )
goto V_150;
break;
}
case V_178 :
{
if ( F_87 ( V_174 , & V_156 -> V_163 ,
& V_156 -> V_161 , V_156 -> V_162 ) )
goto V_150;
break;
}
case V_334 :
{
V_156 -> V_186 = F_108 ( V_174 ) ;
V_156 -> V_189 = F_93 ( V_174 ) ;
break;
}
case V_335 :
{
T_2 V_336 = F_165 ( V_174 ) ;
if ( V_336 > 1 )
goto V_150;
V_156 -> V_204 = V_336 ?
V_73 :
V_337 ;
break;
}
default:
goto V_150;
}
}
V_88 = 0 ;
V_150:
return V_88 ;
}
static int F_166 ( struct V_18 * V_19 , struct V_125 * V_126 ,
struct V_232 * V_233 )
{
struct V_155 * V_156 ;
int V_88 ;
V_156 = F_58 ( sizeof( * V_156 ) , V_118 ) ;
if ( ! V_156 )
return - V_119 ;
V_88 = F_163 ( V_19 , V_126 , V_156 ) ;
if ( V_88 < 0 )
goto V_60;
V_88 = F_100 ( V_156 ) ;
V_60:
F_144 ( V_156 ) ;
return V_88 ;
}
static int F_167 ( struct V_18 * V_19 , struct V_125 * V_126 ,
struct V_232 * V_233 )
{
struct V_155 * V_156 ;
int V_88 ;
V_156 = F_58 ( sizeof( * V_156 ) , V_118 ) ;
if ( ! V_156 )
return - V_119 ;
V_88 = F_163 ( V_19 , V_126 , V_156 ) ;
if ( V_88 < 0 )
goto V_60;
V_88 = F_99 ( V_156 ) ;
V_60:
F_144 ( V_156 ) ;
return V_88 ;
}
static int F_168 ( struct V_18 * V_19 , T_3 V_127 , T_3 V_218 , int V_128 ,
T_3 V_41 , struct V_1 * V_4 , int V_10 )
{
struct V_8 * V_9 ;
struct V_125 * V_126 ;
struct V_314 * V_315 ;
V_126 = F_112 ( V_19 , V_127 , V_218 , V_128 , sizeof( * V_315 ) , V_10 ) ;
if ( V_126 == NULL )
return - V_217 ;
V_315 = F_113 ( V_126 ) ;
V_315 -> V_318 = V_224 ;
V_315 -> V_319 = 20 ;
V_315 -> V_320 = 0 ;
V_315 -> V_321 = 0 ;
V_315 -> V_322 = V_323 ;
V_315 -> V_329 = V_4 -> V_201 ;
V_315 -> V_324 = V_325 ;
V_315 -> V_326 = V_327 ;
V_315 -> V_328 = 0 ;
if ( F_162 ( V_19 , V_332 , 1 , & V_41 ) )
goto V_227;
if ( V_4 -> V_72 != V_74 ) {
bool V_336 =
V_4 -> V_72 == V_73 ;
if ( F_169 ( V_19 , V_335 ,
V_336 ) )
goto V_227;
}
if ( V_4 -> V_58 == 1 ) {
const struct V_12 * V_13 = V_4 -> V_53 ;
if ( V_13 -> V_15 &&
F_162 ( V_19 , V_184 , V_13 -> V_15 ,
V_13 -> V_102 ) )
goto V_227;
if ( V_13 -> V_103 != V_104 &&
F_160 ( V_19 , V_13 -> V_103 , F_6 ( V_4 , V_13 ) ,
V_13 -> V_152 ) )
goto V_227;
V_9 = F_66 ( V_13 -> V_98 ) ;
if ( V_9 && F_170 ( V_19 , V_331 , V_9 -> V_226 ) )
goto V_227;
if ( V_13 -> V_61 & V_63 )
V_315 -> V_328 |= V_63 ;
if ( V_13 -> V_61 & V_62 )
V_315 -> V_328 |= V_62 ;
} else {
struct V_168 * V_169 ;
struct V_165 * V_338 ;
T_2 V_339 = 0 ;
T_2 V_340 = 0 ;
V_338 = F_171 ( V_19 , V_334 ) ;
if ( ! V_338 )
goto V_227;
F_33 (rt) {
V_9 = F_66 ( V_13 -> V_98 ) ;
if ( ! V_9 )
continue;
V_169 = F_172 ( V_19 , sizeof( * V_169 ) ) ;
if ( ! V_169 )
goto V_227;
V_169 -> V_192 = V_9 -> V_226 ;
if ( V_13 -> V_61 & V_63 ) {
V_169 -> V_191 |= V_63 ;
V_339 ++ ;
}
if ( V_13 -> V_61 & V_62 ) {
V_169 -> V_191 |= V_62 ;
V_340 ++ ;
}
if ( V_13 -> V_15 && F_162 ( V_19 , V_184 ,
V_13 -> V_15 ,
V_13 -> V_102 ) )
goto V_227;
if ( V_13 -> V_103 != V_104 &&
F_160 ( V_19 , V_13 -> V_103 ,
F_6 ( V_4 , V_13 ) ,
V_13 -> V_152 ) )
goto V_227;
V_169 -> V_341 = F_173 ( V_19 ) - ( void * ) V_169 ;
} F_34 ( V_4 ) ;
if ( V_339 == V_4 -> V_58 )
V_315 -> V_328 |= V_63 ;
if ( V_340 == V_4 -> V_58 )
V_315 -> V_328 |= V_62 ;
F_174 ( V_19 , V_338 ) ;
}
F_115 ( V_19 , V_126 ) ;
return 0 ;
V_227:
F_116 ( V_19 , V_126 ) ;
return - V_217 ;
}
static int F_175 ( struct V_18 * V_19 , struct V_240 * V_241 )
{
struct V_2 * V_2 = F_126 ( V_19 -> V_234 ) ;
struct V_1 T_1 * * V_7 ;
T_4 V_6 ;
unsigned int V_3 ;
F_65 () ;
V_3 = V_241 -> args [ 0 ] ;
if ( V_3 < V_42 )
V_3 = V_42 ;
V_7 = F_66 ( V_2 -> V_5 . V_7 ) ;
V_6 = V_2 -> V_5 . V_6 ;
for (; V_3 < V_6 ; V_3 ++ ) {
struct V_1 * V_4 ;
V_4 = F_66 ( V_7 [ V_3 ] ) ;
if ( ! V_4 )
continue;
if ( F_168 ( V_19 , F_130 ( V_241 -> V_19 ) . V_127 ,
V_241 -> V_126 -> V_238 , V_129 ,
V_3 , V_4 , V_252 ) < 0 )
break;
}
V_241 -> args [ 0 ] = V_3 ;
return V_19 -> V_20 ;
}
static inline T_4 F_176 ( struct V_1 * V_4 )
{
T_4 V_342 =
F_118 ( sizeof( struct V_314 ) )
+ F_119 ( 4 )
+ F_119 ( 1 ) ;
if ( V_4 -> V_58 == 1 ) {
struct V_12 * V_13 = V_4 -> V_53 ;
if ( V_13 -> V_98 )
V_342 += F_119 ( 4 ) ;
if ( V_13 -> V_103 != V_104 )
V_342 += F_119 ( 2 + V_13 -> V_152 ) ;
if ( V_13 -> V_15 )
V_342 += F_119 ( V_13 -> V_15 * 4 ) ;
} else {
T_4 V_343 = 0 ;
F_33 (rt) {
if ( ! F_66 ( V_13 -> V_98 ) )
continue;
V_343 += F_119 ( sizeof( struct V_168 ) ) ;
if ( V_13 -> V_103 != V_104 )
V_343 += F_119 ( 2 + V_13 -> V_152 ) ;
if ( V_13 -> V_15 )
V_343 += F_119 ( V_13 -> V_15 * 4 ) ;
} F_34 ( V_4 ) ;
V_342 += F_119 ( V_343 ) ;
}
return V_342 ;
}
static void F_63 ( int V_128 , T_3 V_41 , struct V_1 * V_4 ,
struct V_125 * V_126 , struct V_2 * V_2 , T_3 V_127 ,
unsigned int V_131 )
{
struct V_18 * V_19 ;
T_3 V_218 = V_126 ? V_126 -> V_238 : 0 ;
int V_88 = - V_229 ;
V_19 = F_121 ( F_176 ( V_4 ) , V_118 ) ;
if ( V_19 == NULL )
goto V_150;
V_88 = F_168 ( V_19 , V_127 , V_218 , V_128 , V_41 , V_4 , V_131 ) ;
if ( V_88 < 0 ) {
F_122 ( V_88 == - V_217 ) ;
F_54 ( V_19 ) ;
goto V_150;
}
F_123 ( V_19 , V_2 , V_127 , V_344 , V_126 , V_118 ) ;
return;
V_150:
if ( V_88 < 0 )
F_124 ( V_2 , V_344 , V_88 ) ;
}
static int F_177 ( struct V_2 * V_2 , T_4 V_345 )
{
T_4 V_115 = sizeof( struct V_1 * ) * V_345 ;
T_4 V_346 ;
T_4 V_347 ;
struct V_1 T_1 * * V_307 = NULL , * * V_121 ;
struct V_1 * V_348 = NULL , * V_349 = NULL ;
unsigned V_3 ;
if ( V_115 ) {
V_307 = F_178 ( V_115 , V_118 ) ;
if ( ! V_307 )
goto V_350;
}
if ( V_345 > V_351 ) {
struct V_8 * V_352 = V_2 -> V_353 ;
V_348 = F_55 ( 1 , V_352 -> V_151 , 0 ) ;
if ( F_71 ( V_348 ) )
goto V_354;
F_82 ( V_348 -> V_53 -> V_98 , V_352 ) ;
V_348 -> V_201 = V_355 ;
V_348 -> V_67 = V_69 ;
V_348 -> V_72 = V_74 ;
V_348 -> V_53 -> V_103 = V_105 ;
V_348 -> V_53 -> V_152 = V_352 -> V_151 ;
memcpy ( F_5 ( V_348 , V_348 -> V_53 ) , V_352 -> V_106 ,
V_352 -> V_151 ) ;
}
if ( V_345 > V_356 ) {
struct V_8 * V_352 = V_2 -> V_353 ;
V_349 = F_55 ( 1 , V_352 -> V_151 , 0 ) ;
if ( F_71 ( V_349 ) )
goto V_357;
F_82 ( V_349 -> V_53 -> V_98 , V_352 ) ;
V_349 -> V_201 = V_355 ;
V_349 -> V_67 = V_78 ;
V_349 -> V_72 = V_74 ;
V_349 -> V_53 -> V_103 = V_105 ;
V_349 -> V_53 -> V_152 = V_352 -> V_151 ;
memcpy ( F_5 ( V_349 , V_349 -> V_53 ) , V_352 -> V_106 ,
V_352 -> V_151 ) ;
}
F_179 () ;
V_121 = F_66 ( V_2 -> V_5 . V_7 ) ;
V_346 = V_2 -> V_5 . V_6 ;
for ( V_3 = V_345 ; V_3 < V_346 ; V_3 ++ )
F_64 ( V_2 , V_3 , NULL , NULL ) ;
V_347 = V_115 ;
if ( V_346 < V_345 )
V_347 = V_346 * sizeof( struct V_1 * ) ;
memcpy ( V_307 , V_121 , V_347 ) ;
if ( ( V_346 <= V_356 ) &&
( V_345 > V_356 ) ) {
F_82 ( V_307 [ V_356 ] , V_349 ) ;
V_349 = NULL ;
}
if ( ( V_346 <= V_351 ) &&
( V_345 > V_351 ) ) {
F_82 ( V_307 [ V_351 ] , V_348 ) ;
V_348 = NULL ;
}
V_2 -> V_5 . V_6 = V_345 ;
F_67 ( V_2 -> V_5 . V_7 , V_307 ) ;
F_180 () ;
F_60 ( V_349 ) ;
F_60 ( V_348 ) ;
if ( V_121 ) {
F_181 () ;
F_182 ( V_121 ) ;
}
return 0 ;
V_357:
F_60 ( V_348 ) ;
V_354:
F_182 ( V_307 ) ;
V_350:
return - V_119 ;
}
static int F_183 ( struct V_254 * V_268 , int V_256 ,
void T_5 * V_257 , T_4 * V_258 , T_6 * V_259 )
{
struct V_2 * V_2 = V_268 -> V_261 ;
int V_6 = V_2 -> V_5 . V_6 ;
int V_262 ;
struct V_254 V_358 = {
. V_359 = V_268 -> V_359 ,
. V_261 = & V_6 ,
. V_360 = sizeof( int ) ,
. V_361 = V_268 -> V_361 ,
. V_263 = & V_362 ,
. V_264 = & V_363 ,
} ;
V_262 = F_184 ( & V_358 , V_256 , V_257 , V_258 , V_259 ) ;
if ( V_256 && V_262 == 0 )
V_262 = F_177 ( V_2 , V_6 ) ;
return V_262 ;
}
static int F_185 ( struct V_2 * V_2 )
{
struct V_254 * V_268 ;
int V_101 ;
V_2 -> V_5 . V_6 = 0 ;
V_2 -> V_5 . V_7 = NULL ;
V_2 -> V_5 . V_75 = 1 ;
V_2 -> V_5 . V_364 = 255 ;
V_268 = F_141 ( V_365 , sizeof( V_365 ) , V_118 ) ;
if ( V_268 == NULL )
return - V_119 ;
for ( V_101 = 0 ; V_101 < F_142 ( V_365 ) - 1 ; V_101 ++ )
V_268 [ V_101 ] . V_261 = ( char * ) V_2 + ( V_270 ) V_268 [ V_101 ] . V_261 ;
V_2 -> V_5 . V_255 = F_143 ( V_2 , L_4 , V_268 ) ;
if ( V_2 -> V_5 . V_255 == NULL ) {
F_144 ( V_268 ) ;
return - V_119 ;
}
return 0 ;
}
static void F_186 ( struct V_2 * V_2 )
{
struct V_1 T_1 * * V_7 ;
T_4 V_6 ;
struct V_254 * V_268 ;
unsigned int V_3 ;
V_268 = V_2 -> V_5 . V_255 -> V_273 ;
F_146 ( V_2 -> V_5 . V_255 ) ;
F_144 ( V_268 ) ;
F_179 () ;
V_7 = F_66 ( V_2 -> V_5 . V_7 ) ;
V_6 = V_2 -> V_5 . V_6 ;
for ( V_3 = 0 ; V_3 < V_6 ; V_3 ++ ) {
struct V_1 * V_4 = F_66 ( V_7 [ V_3 ] ) ;
F_82 ( V_7 [ V_3 ] , NULL ) ;
F_62 ( V_2 , V_3 , V_4 , NULL , NULL ) ;
F_60 ( V_4 ) ;
}
F_180 () ;
F_182 ( V_7 ) ;
}
static int T_7 F_187 ( void )
{
int V_88 ;
F_188 ( sizeof( struct V_16 ) != 4 ) ;
V_88 = F_189 ( & V_366 ) ;
if ( V_88 )
goto V_60;
V_88 = F_190 ( & V_367 ) ;
if ( V_88 )
goto V_368;
F_191 ( & V_369 ) ;
F_192 ( & V_370 ) ;
F_193 ( V_371 , V_129 , F_167 , NULL , NULL ) ;
F_193 ( V_371 , V_130 , F_166 , NULL , NULL ) ;
F_193 ( V_371 , V_372 , NULL , F_175 , NULL ) ;
F_193 ( V_371 , V_373 , F_125 ,
F_132 , NULL ) ;
V_88 = 0 ;
V_60:
return V_88 ;
V_368:
F_194 ( & V_366 ) ;
goto V_60;
}
static void T_8 F_195 ( void )
{
F_196 ( V_371 ) ;
F_197 ( & V_370 ) ;
F_198 ( & V_369 ) ;
F_199 ( & V_367 ) ;
F_194 ( & V_366 ) ;
}

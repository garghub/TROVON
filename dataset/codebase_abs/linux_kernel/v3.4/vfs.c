int
F_1 ( struct V_1 * V_2 , struct V_3 * * V_4 ,
struct V_5 * * V_6 )
{
struct V_5 * exp = * V_6 , * V_7 = NULL ;
struct V_3 * V_3 = * V_4 ;
struct V_8 V_8 = { . V_9 = F_2 ( exp -> V_10 . V_9 ) ,
. V_3 = F_3 (dentry) } ;
int V_11 = 0 ;
V_11 = F_4 ( & V_8 ) ;
if ( V_11 < 0 )
goto V_12;
V_7 = F_5 ( V_2 , & V_8 ) ;
if ( F_6 ( V_7 ) ) {
V_11 = F_7 ( V_7 ) ;
if ( V_11 == - V_13 && ! ( exp -> V_14 & V_15 ) )
V_11 = 0 ;
F_8 ( & V_8 ) ;
goto V_12;
}
if ( F_9 ( V_2 ) ||
( exp -> V_14 & V_16 ) || F_10 ( V_7 ) ) {
* V_4 = V_8 . V_3 ;
V_8 . V_3 = V_3 ;
* V_6 = V_7 ;
V_7 = exp ;
}
F_8 ( & V_8 ) ;
F_11 ( V_7 ) ;
V_12:
return V_11 ;
}
static void F_12 ( struct V_8 * V_8 )
{
struct V_3 * V_17 ;
while ( V_8 -> V_3 == V_8 -> V_9 -> V_18 && F_13 ( V_8 ) )
;
V_17 = F_14 ( V_8 -> V_3 ) ;
F_15 ( V_8 -> V_3 ) ;
V_8 -> V_3 = V_17 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_3 * V_19 , struct V_5 * * exp , struct V_3 * * V_20 )
{
struct V_5 * V_7 ;
struct V_8 V_8 = { . V_9 = F_2 ( ( * exp ) -> V_10 . V_9 ) ,
. V_3 = F_3 (dparent) } ;
F_12 ( & V_8 ) ;
V_7 = F_17 ( V_2 , & V_8 ) ;
if ( F_7 ( V_7 ) == - V_13 ) {
* V_20 = F_3 ( V_19 ) ;
} else if ( F_6 ( V_7 ) ) {
F_8 ( & V_8 ) ;
return F_7 ( V_7 ) ;
} else {
* V_20 = F_3 ( V_8 . V_3 ) ;
F_11 ( * exp ) ;
* exp = V_7 ;
}
F_8 ( & V_8 ) ;
return 0 ;
}
int F_18 ( struct V_3 * V_3 , struct V_5 * exp )
{
if ( F_19 ( V_3 ) )
return 1 ;
if ( F_20 ( V_3 ) )
return 1 ;
if ( ! ( exp -> V_14 & V_15 ) )
return 0 ;
return V_3 -> V_21 != NULL ;
}
T_1
F_21 ( struct V_1 * V_2 , struct V_22 * V_23 ,
const char * V_24 , unsigned int V_25 ,
struct V_5 * * V_26 , struct V_3 * * V_27 )
{
struct V_5 * exp ;
struct V_3 * V_19 ;
struct V_3 * V_3 ;
int V_28 ;
F_22 ( L_1 , F_23 ( V_23 ) , V_25 , V_24 ) ;
V_19 = V_23 -> V_29 ;
exp = V_23 -> V_30 ;
F_24 ( exp ) ;
if ( F_25 ( V_24 , V_25 ) ) {
if ( V_25 == 1 )
V_3 = F_3 ( V_19 ) ;
else if ( V_19 != exp -> V_10 . V_3 )
V_3 = F_14 ( V_19 ) ;
else if ( ! F_10 ( exp ) && ! F_9 ( V_2 ) )
V_3 = F_3 ( V_19 ) ;
else {
V_28 = F_16 ( V_2 , V_19 , & exp , & V_3 ) ;
if ( V_28 )
goto V_31;
}
} else {
F_26 ( V_23 ) ;
V_3 = F_27 ( V_24 , V_19 , V_25 ) ;
V_28 = F_7 ( V_3 ) ;
if ( F_6 ( V_3 ) )
goto V_31;
if ( F_18 ( V_3 , exp ) ) {
if ( ( V_28 = F_1 ( V_2 , & V_3 , & exp ) ) ) {
F_15 ( V_3 ) ;
goto V_31;
}
}
}
* V_27 = V_3 ;
* V_26 = exp ;
return 0 ;
V_31:
F_11 ( exp ) ;
return F_28 ( V_28 ) ;
}
T_1
F_29 ( struct V_1 * V_2 , struct V_22 * V_23 , const char * V_24 ,
unsigned int V_25 , struct V_22 * V_32 )
{
struct V_5 * exp ;
struct V_3 * V_3 ;
T_1 V_11 ;
V_11 = F_30 ( V_2 , V_23 , V_33 , V_34 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_21 ( V_2 , V_23 , V_24 , V_25 , & exp , & V_3 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_31 ( exp , V_2 ) ;
if ( V_11 )
goto V_12;
V_11 = F_32 ( V_32 , exp , V_3 , V_23 ) ;
if ( ! V_11 && ! V_3 -> V_21 )
V_11 = V_35 ;
V_12:
F_15 ( V_3 ) ;
F_11 ( exp ) ;
return V_11 ;
}
static int F_33 ( struct V_36 * V_36 )
{
if ( ! F_34 ( V_36 -> V_37 ) )
return 0 ;
return F_35 ( V_36 , V_38 | V_39 ) ;
}
static int
F_36 ( struct V_22 * V_23 )
{
struct V_36 * V_36 = V_23 -> V_29 -> V_21 ;
const struct V_40 * V_41 = V_36 -> V_42 -> V_43 ;
if ( ! F_37 ( V_23 -> V_30 ) )
return 0 ;
if ( V_41 -> F_36 )
return V_41 -> F_36 ( V_36 ) ;
return F_38 ( V_36 , 1 ) ;
}
T_1
F_39 ( struct V_1 * V_2 , struct V_22 * V_23 , struct V_44 * V_45 ,
int V_46 , T_2 V_47 )
{
struct V_3 * V_3 ;
struct V_36 * V_36 ;
int V_48 = V_49 ;
T_3 V_50 = 0 ;
T_1 V_11 ;
int V_28 ;
int V_51 = 0 ;
if ( V_45 -> V_52 & ( V_53 | V_54 | V_55 ) )
V_48 |= V_56 | V_57 ;
if ( V_45 -> V_52 & V_55 )
V_50 = V_58 ;
V_11 = F_30 ( V_2 , V_23 , V_50 , V_48 ) ;
if ( V_11 )
goto V_12;
V_3 = V_23 -> V_29 ;
V_36 = V_3 -> V_21 ;
if ( F_40 ( V_36 -> V_37 ) )
V_45 -> V_52 &= ~ V_59 ;
if ( ! V_45 -> V_52 )
goto V_12;
#define F_41 (ATTR_ATIME_SET | ATTR_MTIME_SET)
#define F_42 (30*60)
if ( ( V_45 -> V_52 & F_41 ) == F_41 &&
V_45 -> V_60 . V_61 == V_45 -> V_62 . V_61 ) {
T_2 V_63 = V_45 -> V_62 . V_61 - F_43 () ;
if ( V_63 < 0 )
V_63 = - V_63 ;
if ( V_63 < F_42 &&
F_44 ( V_36 , V_45 ) != 0 ) {
V_45 -> V_52 &= ~ F_41 ;
}
}
if ( V_45 -> V_52 & V_55 ) {
if ( V_45 -> V_64 < V_36 -> V_65 ) {
V_11 = F_45 ( V_2 , V_23 -> V_30 , V_3 ,
V_66 | V_57 ) ;
if ( V_11 )
goto V_12;
}
V_28 = F_46 ( V_36 ) ;
if ( V_28 )
goto V_31;
V_51 = 1 ;
V_28 = F_47 ( V_36 , NULL , V_45 -> V_64 ) ;
if ( V_28 ) {
F_48 ( V_36 ) ;
goto V_31;
}
}
if ( V_45 -> V_52 & V_59 ) {
V_45 -> V_67 &= V_68 ;
V_45 -> V_67 |= ( V_36 -> V_37 & ~ V_68 ) ;
}
if ( ! F_49 ( V_36 -> V_37 ) &&
( ( ( V_45 -> V_52 & V_69 ) && V_45 -> V_70 != V_36 -> V_71 ) ||
( ( V_45 -> V_52 & V_72 ) && V_45 -> V_73 != V_36 -> V_74 ) ) ) {
V_45 -> V_52 |= V_75 ;
if ( V_45 -> V_52 & V_59 ) {
V_45 -> V_67 &= ~ V_76 ;
if ( V_45 -> V_67 & V_77 )
V_45 -> V_67 &= ~ V_78 ;
} else {
V_45 -> V_52 |= ( V_79 | V_80 ) ;
}
}
V_45 -> V_52 |= V_81 ;
V_11 = V_82 ;
if ( ! V_46 || V_47 == V_36 -> V_83 . V_61 ) {
V_28 = F_33 ( V_36 ) ;
if ( V_28 )
goto V_31;
F_26 ( V_23 ) ;
V_28 = F_50 ( V_3 , V_45 ) ;
V_11 = F_28 ( V_28 ) ;
F_51 ( V_23 ) ;
}
if ( V_51 )
F_48 ( V_36 ) ;
if ( ! V_11 )
F_36 ( V_23 ) ;
V_12:
return V_11 ;
V_31:
V_11 = F_28 ( V_28 ) ;
goto V_12;
}
static T_4 F_52 ( struct V_3 * V_3 , char * V_84 , void * * V_85 )
{
T_4 V_86 ;
T_4 V_87 ;
V_86 = F_53 ( V_3 , V_84 , NULL , 0 ) ;
if ( V_86 <= 0 )
return V_86 ;
* V_85 = F_54 ( V_86 , V_88 ) ;
if ( ! * V_85 )
return - V_89 ;
V_87 = F_53 ( V_3 , V_84 , * V_85 , V_86 ) ;
if ( V_87 < 0 )
F_55 ( * V_85 ) ;
return V_87 ;
}
static int
F_56 ( struct V_3 * V_3 , struct V_90 * V_91 , char * V_84 )
{
int V_25 ;
T_5 V_86 ;
char * V_85 = NULL ;
int error = 0 ;
V_86 = F_57 ( V_91 -> V_92 ) ;
V_85 = F_54 ( V_86 , V_88 ) ;
error = - V_89 ;
if ( V_85 == NULL )
goto V_12;
V_25 = F_58 ( V_91 , V_85 , V_86 ) ;
if ( V_25 < 0 ) {
error = V_25 ;
goto V_12;
}
error = F_59 ( V_3 , V_84 , V_85 , V_25 , 0 ) ;
V_12:
F_55 ( V_85 ) ;
return error ;
}
T_1
F_60 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_93 * V_94 )
{
T_1 error ;
int V_95 ;
struct V_3 * V_3 ;
struct V_36 * V_36 ;
struct V_90 * V_91 = NULL , * V_96 = NULL ;
unsigned int V_97 = 0 ;
error = F_30 ( V_2 , V_23 , 0 , V_49 ) ;
if ( error )
return error ;
V_3 = V_23 -> V_29 ;
V_36 = V_3 -> V_21 ;
if ( F_49 ( V_36 -> V_37 ) )
V_97 = V_98 ;
V_95 = F_61 ( V_94 , & V_91 , & V_96 , V_97 ) ;
if ( V_95 == - V_99 ) {
return V_100 ;
} else if ( V_95 < 0 )
goto V_31;
V_95 = F_56 ( V_3 , V_91 , V_101 ) ;
if ( V_95 < 0 )
goto V_102;
if ( F_49 ( V_36 -> V_37 ) )
V_95 = F_56 ( V_3 , V_96 , V_103 ) ;
V_102:
F_62 ( V_91 ) ;
F_62 ( V_96 ) ;
V_31:
if ( V_95 == - V_104 )
return V_100 ;
else
return F_28 ( V_95 ) ;
}
static struct V_90 *
F_63 ( struct V_3 * V_3 , char * V_84 )
{
void * V_85 = NULL ;
struct V_90 * V_91 = NULL ;
int V_86 ;
V_86 = F_52 ( V_3 , V_84 , & V_85 ) ;
if ( ! V_86 )
V_86 = - V_105 ;
if ( V_86 <= 0 )
return F_64 ( V_86 ) ;
V_91 = F_65 ( V_85 , V_86 ) ;
F_55 ( V_85 ) ;
return V_91 ;
}
int
F_66 ( struct V_1 * V_2 , struct V_3 * V_3 , struct V_93 * * V_94 )
{
struct V_36 * V_36 = V_3 -> V_21 ;
int error = 0 ;
struct V_90 * V_91 = NULL , * V_96 = NULL ;
unsigned int V_97 = 0 ;
V_91 = F_63 ( V_3 , V_101 ) ;
if ( F_6 ( V_91 ) && F_7 ( V_91 ) == - V_105 )
V_91 = F_67 ( V_36 -> V_37 , V_88 ) ;
if ( F_6 ( V_91 ) ) {
error = F_7 ( V_91 ) ;
V_91 = NULL ;
goto V_12;
}
if ( F_49 ( V_36 -> V_37 ) ) {
V_96 = F_63 ( V_3 , V_103 ) ;
if ( F_6 ( V_96 ) && F_7 ( V_96 ) == - V_105 )
V_96 = NULL ;
else if ( F_6 ( V_96 ) ) {
error = F_7 ( V_96 ) ;
V_96 = NULL ;
goto V_12;
}
V_97 = V_98 ;
}
* V_94 = F_68 ( V_91 , V_96 , V_97 ) ;
if ( F_6 ( * V_94 ) ) {
error = F_7 ( * V_94 ) ;
* V_94 = NULL ;
}
V_12:
F_62 ( V_91 ) ;
F_62 ( V_96 ) ;
return error ;
}
int F_20 ( struct V_3 * V_3 )
{
struct V_36 * V_36 = V_3 -> V_21 ;
if ( V_36 == NULL )
return 0 ;
if ( V_36 -> V_37 & V_106 )
return 0 ;
if ( ! ( V_36 -> V_37 & V_107 ) )
return 0 ;
if ( F_53 ( V_3 , V_108 , NULL , 0 ) <= 0 )
return 0 ;
return 1 ;
}
T_1
F_69 ( struct V_1 * V_2 , struct V_22 * V_23 , T_6 * V_109 , T_6 * V_110 )
{
struct V_111 * V_112 ;
struct V_5 * V_113 ;
struct V_3 * V_3 ;
T_6 V_114 , V_115 = 0 , V_116 = 0 ;
T_1 error ;
error = F_30 ( V_2 , V_23 , 0 , V_117 ) ;
if ( error )
goto V_12;
V_113 = V_23 -> V_30 ;
V_3 = V_23 -> V_29 ;
if ( F_34 ( V_3 -> V_21 -> V_37 ) )
V_112 = V_118 ;
else if ( F_49 ( V_3 -> V_21 -> V_37 ) )
V_112 = V_119 ;
else
V_112 = V_120 ;
V_114 = * V_109 ;
for (; V_112 -> V_109 ; V_112 ++ ) {
if ( V_112 -> V_109 & V_114 ) {
T_1 V_121 ;
V_116 |= V_112 -> V_109 ;
V_121 = F_45 ( V_2 , V_113 , V_3 , V_112 -> V_122 ) ;
switch ( V_121 ) {
case V_123 :
V_115 |= V_112 -> V_109 ;
break;
case V_124 :
case V_125 :
case V_126 :
break;
default:
error = V_121 ;
goto V_12;
}
}
}
* V_109 = V_115 ;
if ( V_110 )
* V_110 = V_116 ;
V_12:
return error ;
}
static int F_70 ( struct V_36 * V_36 , int V_109 )
{
unsigned int V_127 ;
if ( V_109 & V_128 )
return 0 ;
V_127 = ( V_109 & V_56 ) ? V_38 : V_129 ;
return F_35 ( V_36 , V_127 | V_39 ) ;
}
T_1
F_71 ( struct V_1 * V_2 , struct V_22 * V_23 , T_3 type ,
int V_130 , struct V_131 * * V_132 )
{
struct V_3 * V_3 ;
struct V_36 * V_36 ;
int V_97 = V_129 | V_133 ;
T_1 V_11 ;
int V_28 = 0 ;
F_72 () ;
V_11 = F_30 ( V_2 , V_23 , type , V_130 | V_57 ) ;
if ( V_11 )
goto V_12;
V_3 = V_23 -> V_29 ;
V_36 = V_3 -> V_21 ;
V_11 = V_126 ;
if ( F_73 ( V_36 ) && ( V_130 & V_56 ) )
goto V_12;
if ( F_34 ( ( V_36 ) -> V_37 ) && F_74 ( V_36 ) )
goto V_12;
if ( ! V_36 -> V_134 )
goto V_12;
V_28 = F_70 ( V_36 , V_130 ) ;
if ( V_28 )
goto V_31;
if ( V_130 & V_56 ) {
if ( V_130 & V_135 )
V_97 = V_136 | V_133 ;
else
V_97 = V_38 | V_133 ;
}
* V_132 = F_75 ( F_3 ( V_3 ) , F_2 ( V_23 -> V_30 -> V_10 . V_9 ) ,
V_97 , F_76 () ) ;
if ( F_6 ( * V_132 ) )
V_28 = F_7 ( * V_132 ) ;
else {
V_28 = F_77 ( * V_132 , V_130 ) ;
if ( V_130 & V_137 )
( * V_132 ) -> V_138 |= V_139 ;
else
( * V_132 ) -> V_138 |= V_140 ;
}
V_31:
V_11 = F_28 ( V_28 ) ;
V_12:
F_72 () ;
return V_11 ;
}
void
F_78 ( struct V_131 * V_132 )
{
F_79 ( V_132 ) ;
}
static inline struct V_141 *
F_80 ( T_7 V_142 , T_8 V_143 )
{
struct V_141 * V_144 , * * V_145 , * * V_146 = NULL ;
int V_147 = 0 ;
unsigned int V_148 ;
struct V_149 * V_150 ;
V_148 = F_81 ( V_142 , V_143 , 0xfeedbeef ) & V_151 ;
V_150 = & V_152 [ V_148 ] ;
F_82 ( & V_150 -> V_153 ) ;
for ( V_145 = & V_150 -> V_154 ; ( V_144 = * V_145 ) ; V_145 = & V_144 -> V_155 ) {
if ( V_144 -> V_156 == V_143 && V_144 -> V_157 == V_142 )
goto V_158;
V_147 ++ ;
if ( V_144 -> V_159 == 0 )
V_146 = V_145 ;
}
V_147 = V_160 . V_161 ;
if ( ! V_146 ) {
F_83 ( & V_150 -> V_153 ) ;
return NULL ;
}
V_145 = V_146 ;
V_144 = * V_146 ;
V_144 -> V_157 = V_142 ;
V_144 -> V_156 = V_143 ;
V_144 -> V_162 = 0 ;
V_144 -> V_163 = V_148 ;
V_158:
if ( V_145 != & V_150 -> V_154 ) {
* V_145 = V_144 -> V_155 ;
V_144 -> V_155 = V_150 -> V_154 ;
V_150 -> V_154 = V_144 ;
}
V_144 -> V_159 ++ ;
V_160 . V_164 [ V_147 * 10 / V_160 . V_161 ] ++ ;
F_83 ( & V_150 -> V_153 ) ;
return V_144 ;
}
static int
F_84 ( struct V_165 * V_166 , struct V_167 * V_85 ,
struct V_168 * V_169 )
{
struct V_1 * V_2 = V_169 -> V_170 . V_171 ;
struct V_172 * * V_173 = V_2 -> V_174 + V_2 -> V_175 ;
struct V_172 * V_172 = V_85 -> V_172 ;
T_5 V_176 ;
V_176 = V_169 -> V_25 ;
if ( V_2 -> V_177 . V_178 == 0 ) {
F_85 ( V_172 ) ;
F_86 ( * V_173 ) ;
* V_173 = V_172 ;
V_2 -> V_175 ++ ;
V_2 -> V_177 . V_179 = V_85 -> V_180 ;
V_2 -> V_177 . V_178 = V_176 ;
} else if ( V_172 != V_173 [ - 1 ] ) {
F_85 ( V_172 ) ;
if ( * V_173 )
F_86 ( * V_173 ) ;
* V_173 = V_172 ;
V_2 -> V_175 ++ ;
V_2 -> V_177 . V_178 += V_176 ;
} else
V_2 -> V_177 . V_178 += V_176 ;
return V_176 ;
}
static int F_87 ( struct V_165 * V_166 ,
struct V_168 * V_169 )
{
return F_88 ( V_166 , V_169 , F_84 ) ;
}
static T_1
F_89 ( struct V_1 * V_2 , struct V_22 * V_23 , struct V_131 * V_131 ,
T_9 V_180 , struct V_181 * V_182 , int V_183 , unsigned long * V_184 )
{
T_10 V_185 ;
T_1 V_11 ;
int V_28 ;
V_11 = V_126 ;
if ( V_131 -> V_186 -> V_187 && V_2 -> V_188 ) {
struct V_168 V_169 = {
. V_25 = 0 ,
. V_189 = * V_184 ,
. V_190 = V_180 ,
. V_170 . V_171 = V_2 ,
} ;
V_2 -> V_175 = 1 ;
V_28 = F_90 ( V_131 , & V_169 , F_87 ) ;
} else {
V_185 = F_91 () ;
F_92 ( V_191 ) ;
V_28 = F_93 ( V_131 , (struct V_192 V_193 * ) V_182 , V_183 , & V_180 ) ;
F_92 ( V_185 ) ;
}
if ( V_28 >= 0 ) {
V_160 . V_194 += V_28 ;
* V_184 = V_28 ;
V_11 = 0 ;
F_94 ( V_131 ) ;
} else
V_11 = F_28 ( V_28 ) ;
return V_11 ;
}
static void F_95 ( struct V_3 * V_3 )
{
struct V_44 V_195 ;
V_195 . V_52 = V_79 | V_80 | V_75 ;
F_96 ( & V_3 -> V_21 -> V_196 ) ;
F_50 ( V_3 , & V_195 ) ;
F_97 ( & V_3 -> V_21 -> V_196 ) ;
}
static int F_98 ( struct V_131 * V_131 )
{
struct V_36 * V_36 = V_131 -> V_197 . V_3 -> V_21 ;
static T_8 V_198 ;
static T_7 V_199 ;
int V_11 = 0 ;
if ( F_99 ( & V_36 -> V_200 ) > 1
|| ( V_198 == V_36 -> V_201 && V_199 == V_36 -> V_42 -> V_202 ) ) {
F_22 ( L_2 , F_100 ( V_203 ) ) ;
F_101 ( 10 ) ;
F_22 ( L_3 , F_100 ( V_203 ) ) ;
}
if ( V_36 -> V_204 & V_205 ) {
F_22 ( L_4 , F_100 ( V_203 ) ) ;
V_11 = F_102 ( V_131 , 0 ) ;
}
V_198 = V_36 -> V_201 ;
V_199 = V_36 -> V_42 -> V_202 ;
return V_11 ;
}
static T_1
F_103 ( struct V_1 * V_2 , struct V_22 * V_23 , struct V_131 * V_131 ,
T_9 V_180 , struct V_181 * V_182 , int V_183 ,
unsigned long * V_206 , int * V_207 )
{
struct V_5 * exp ;
struct V_3 * V_3 ;
struct V_36 * V_36 ;
T_10 V_185 ;
T_1 V_11 = 0 ;
int V_28 ;
int V_208 = * V_207 ;
int V_209 ;
V_3 = V_131 -> V_197 . V_3 ;
V_36 = V_3 -> V_21 ;
exp = V_23 -> V_30 ;
V_209 = ( V_2 -> V_210 == 2 ) && F_104 ( exp ) ;
if ( ! V_131 -> V_186 -> V_211 ) {
V_208 = 2 ;
* V_207 = 2 ;
}
if ( ! F_37 ( exp ) )
V_208 = 0 ;
if ( V_208 && ! V_209 ) {
F_82 ( & V_131 -> V_212 ) ;
V_131 -> V_213 |= V_214 ;
F_83 ( & V_131 -> V_212 ) ;
}
V_185 = F_91 () ; F_92 ( V_191 ) ;
V_28 = F_105 ( V_131 , (struct V_192 V_193 * ) V_182 , V_183 , & V_180 ) ;
F_92 ( V_185 ) ;
if ( V_28 < 0 )
goto V_31;
* V_206 = V_28 ;
V_160 . V_215 += V_28 ;
F_106 ( V_131 ) ;
if ( V_36 -> V_37 & ( V_76 | V_78 ) )
F_95 ( V_3 ) ;
if ( V_208 && V_209 )
V_28 = F_98 ( V_131 ) ;
V_31:
F_22 ( L_5 , V_28 ) ;
if ( V_28 >= 0 )
V_11 = 0 ;
else
V_11 = F_28 ( V_28 ) ;
return V_11 ;
}
T_1 F_107 ( struct V_1 * V_2 , struct V_22 * V_23 ,
T_9 V_180 , struct V_181 * V_182 , int V_183 , unsigned long * V_184 )
{
struct V_131 * V_131 ;
struct V_36 * V_36 ;
struct V_141 * V_144 ;
T_1 V_11 ;
V_11 = F_71 ( V_2 , V_23 , V_58 , V_135 , & V_131 ) ;
if ( V_11 )
return V_11 ;
V_36 = V_131 -> V_197 . V_3 -> V_21 ;
V_144 = F_80 ( V_36 -> V_42 -> V_202 , V_36 -> V_201 ) ;
if ( V_144 && V_144 -> V_162 )
V_131 -> V_216 = V_144 -> V_217 ;
V_11 = F_89 ( V_2 , V_23 , V_131 , V_180 , V_182 , V_183 , V_184 ) ;
if ( V_144 ) {
struct V_149 * V_150 = & V_152 [ V_144 -> V_163 ] ;
F_82 ( & V_150 -> V_153 ) ;
V_144 -> V_217 = V_131 -> V_216 ;
V_144 -> V_162 = 1 ;
V_144 -> V_159 -- ;
F_83 ( & V_150 -> V_153 ) ;
}
F_78 ( V_131 ) ;
return V_11 ;
}
T_1
F_108 ( struct V_1 * V_2 , struct V_22 * V_23 , struct V_131 * V_131 ,
T_9 V_180 , struct V_181 * V_182 , int V_183 ,
unsigned long * V_184 )
{
T_1 V_11 ;
if ( V_131 ) {
V_11 = F_45 ( V_2 , V_23 -> V_30 , V_23 -> V_29 ,
V_135 | V_57 ) ;
if ( V_11 )
goto V_12;
V_11 = F_89 ( V_2 , V_23 , V_131 , V_180 , V_182 , V_183 , V_184 ) ;
} else
V_11 = F_107 ( V_2 , V_23 , V_180 , V_182 , V_183 , V_184 ) ;
V_12:
return V_11 ;
}
T_1
F_109 ( struct V_1 * V_2 , struct V_22 * V_23 , struct V_131 * V_131 ,
T_9 V_180 , struct V_181 * V_182 , int V_183 , unsigned long * V_206 ,
int * V_207 )
{
T_1 V_11 = 0 ;
if ( V_131 ) {
V_11 = F_45 ( V_2 , V_23 -> V_30 , V_23 -> V_29 ,
V_56 | V_57 ) ;
if ( V_11 )
goto V_12;
V_11 = F_103 ( V_2 , V_23 , V_131 , V_180 , V_182 , V_183 , V_206 ,
V_207 ) ;
} else {
V_11 = F_71 ( V_2 , V_23 , V_58 , V_56 , & V_131 ) ;
if ( V_11 )
goto V_12;
if ( V_206 )
V_11 = F_103 ( V_2 , V_23 , V_131 , V_180 , V_182 , V_183 ,
V_206 , V_207 ) ;
F_78 ( V_131 ) ;
}
V_12:
return V_11 ;
}
T_1
F_110 ( struct V_1 * V_2 , struct V_22 * V_23 ,
T_9 V_180 , unsigned long V_184 )
{
struct V_131 * V_131 ;
T_9 V_218 = V_219 ;
T_1 V_11 = V_220 ;
if ( V_180 < 0 )
goto V_12;
if ( V_184 != 0 ) {
V_218 = V_180 + ( T_9 ) V_184 - 1 ;
if ( V_218 < V_180 )
goto V_12;
}
V_11 = F_71 ( V_2 , V_23 , V_58 ,
V_56 | V_128 , & V_131 ) ;
if ( V_11 )
goto V_12;
if ( F_37 ( V_23 -> V_30 ) ) {
int V_121 = F_111 ( V_131 , V_180 , V_218 , 0 ) ;
if ( V_121 != - V_99 )
V_11 = F_28 ( V_121 ) ;
else
V_11 = V_221 ;
}
F_78 ( V_131 ) ;
V_12:
return V_11 ;
}
static T_1
F_112 ( struct V_1 * V_2 , struct V_22 * V_222 ,
struct V_44 * V_45 )
{
V_45 -> V_52 &= ~ V_59 ;
if ( F_113 () != 0 )
V_45 -> V_52 &= ~ ( V_69 | V_72 ) ;
if ( V_45 -> V_52 )
return F_39 ( V_2 , V_222 , V_45 , 0 , ( T_2 ) 0 ) ;
return 0 ;
}
static void
F_114 ( struct V_44 * V_45 )
{
if ( ( V_45 -> V_52 & V_55 ) && ( V_45 -> V_64 == 0 ) )
V_45 -> V_52 &= ~ V_55 ;
}
T_1
F_115 ( struct V_1 * V_2 , struct V_22 * V_23 ,
char * V_223 , int V_224 , struct V_44 * V_45 ,
int type , T_7 V_225 , struct V_22 * V_222 )
{
struct V_3 * V_3 , * V_226 = NULL ;
struct V_36 * V_227 ;
T_1 V_11 ;
T_1 V_121 ;
int V_28 ;
V_11 = V_126 ;
if ( ! V_224 )
goto V_12;
V_11 = V_228 ;
if ( F_25 ( V_223 , V_224 ) )
goto V_12;
V_11 = F_30 ( V_2 , V_23 , V_33 , V_229 ) ;
if ( V_11 )
goto V_12;
V_3 = V_23 -> V_29 ;
V_227 = V_3 -> V_21 ;
V_11 = V_230 ;
if ( ! V_227 -> V_231 -> V_232 )
goto V_12;
if ( ! V_222 -> V_29 ) {
F_116 ( V_23 , V_233 ) ;
V_226 = F_27 ( V_223 , V_3 , V_224 ) ;
V_28 = F_7 ( V_226 ) ;
if ( F_6 ( V_226 ) )
goto V_31;
V_11 = F_32 ( V_222 , V_23 -> V_30 , V_226 , V_23 ) ;
if ( V_11 )
goto V_12;
} else {
V_226 = F_3 ( V_222 -> V_29 ) ;
if ( ! V_23 -> V_234 ) {
F_117 ( V_235
L_6 ,
V_3 -> V_236 -> V_237 . V_24 ,
V_3 -> V_237 . V_24 ) ;
V_11 = V_238 ;
goto V_12;
}
}
V_11 = V_228 ;
if ( V_226 -> V_21 ) {
F_22 ( L_7 ,
V_3 -> V_237 . V_24 , V_226 -> V_237 . V_24 ) ;
goto V_12;
}
if ( ! ( V_45 -> V_52 & V_59 ) )
V_45 -> V_67 = 0 ;
V_45 -> V_67 = ( V_45 -> V_67 & V_68 ) | type ;
V_11 = V_220 ;
if ( ! F_34 ( type ) && ! F_49 ( type ) && ! F_118 ( type ) ) {
F_117 ( V_239 L_8 ,
type ) ;
goto V_12;
}
V_28 = F_119 ( V_23 ) ;
if ( V_28 )
goto V_31;
V_11 = 0 ;
switch ( type ) {
case V_58 :
V_28 = F_120 ( V_227 , V_226 , V_45 -> V_67 , NULL ) ;
if ( ! V_28 )
F_114 ( V_45 ) ;
break;
case V_33 :
V_28 = F_121 ( V_227 , V_226 , V_45 -> V_67 ) ;
break;
case V_240 :
case V_241 :
case V_242 :
case V_243 :
V_28 = F_122 ( V_227 , V_226 , V_45 -> V_67 , V_225 ) ;
break;
}
if ( V_28 < 0 ) {
F_123 ( V_23 ) ;
goto V_31;
}
V_11 = F_112 ( V_2 , V_222 , V_45 ) ;
V_121 = F_28 ( F_36 ( V_23 ) ) ;
if ( V_121 )
V_11 = V_121 ;
F_123 ( V_23 ) ;
if ( ! V_11 )
V_11 = F_124 ( V_222 ) ;
V_12:
if ( V_226 && ! F_6 ( V_226 ) )
F_15 ( V_226 ) ;
return V_11 ;
V_31:
V_11 = F_28 ( V_28 ) ;
goto V_12;
}
static inline int F_125 ( int V_244 )
{
return V_244 == V_245
|| V_244 == V_246 ;
}
T_1
F_126 ( struct V_1 * V_2 , struct V_22 * V_23 ,
char * V_223 , int V_224 , struct V_44 * V_45 ,
struct V_22 * V_222 , int V_244 , T_6 * V_247 ,
bool * V_248 , bool * V_249 )
{
struct V_3 * V_3 , * V_226 = NULL ;
struct V_36 * V_227 ;
T_1 V_11 ;
int V_28 ;
T_11 V_250 = 0 , V_251 = 0 ;
V_11 = V_126 ;
if ( ! V_224 )
goto V_12;
V_11 = V_228 ;
if ( F_25 ( V_223 , V_224 ) )
goto V_12;
if ( ! ( V_45 -> V_52 & V_59 ) )
V_45 -> V_67 = 0 ;
V_11 = F_30 ( V_2 , V_23 , V_33 , V_34 ) ;
if ( V_11 )
goto V_12;
V_3 = V_23 -> V_29 ;
V_227 = V_3 -> V_21 ;
V_11 = V_230 ;
if ( ! V_227 -> V_231 -> V_232 )
goto V_12;
F_116 ( V_23 , V_233 ) ;
V_226 = F_27 ( V_223 , V_3 , V_224 ) ;
V_28 = F_7 ( V_226 ) ;
if ( F_6 ( V_226 ) )
goto V_31;
if ( ! V_226 -> V_21 ) {
V_11 = F_30 ( V_2 , V_23 , V_33 , V_229 ) ;
if ( V_11 )
goto V_12;
}
V_11 = F_32 ( V_222 , V_23 -> V_30 , V_226 , V_23 ) ;
if ( V_11 )
goto V_12;
if ( F_125 ( V_244 ) ) {
V_250 = V_247 [ 0 ] & 0x7fffffff ;
V_251 = V_247 [ 1 ] & 0x7fffffff ;
}
V_28 = F_119 ( V_23 ) ;
if ( V_28 )
goto V_31;
if ( V_226 -> V_21 ) {
V_11 = 0 ;
switch ( V_244 ) {
case V_252 :
if ( ! F_34 ( V_226 -> V_21 -> V_37 ) )
goto V_12;
else if ( V_248 ) {
* V_248 = ( V_45 -> V_52 & V_55 ) && ! V_45 -> V_64 ;
}
else {
V_45 -> V_52 &= V_55 ;
goto V_253;
}
break;
case V_245 :
if ( V_226 -> V_21 -> V_254 . V_61 == V_250
&& V_226 -> V_21 -> V_255 . V_61 == V_251
&& V_226 -> V_21 -> V_65 == 0 )
break;
case V_246 :
if ( V_226 -> V_21 -> V_254 . V_61 == V_250
&& V_226 -> V_21 -> V_255 . V_61 == V_251
&& V_226 -> V_21 -> V_65 == 0 )
goto V_253;
case V_256 :
V_11 = V_228 ;
}
F_123 ( V_23 ) ;
goto V_12;
}
V_28 = F_120 ( V_227 , V_226 , V_45 -> V_67 , NULL ) ;
if ( V_28 < 0 ) {
F_123 ( V_23 ) ;
goto V_31;
}
if ( V_249 )
* V_249 = 1 ;
F_114 ( V_45 ) ;
if ( F_125 ( V_244 ) ) {
V_45 -> V_52 = V_54 | V_53
| V_257 | V_258 ;
V_45 -> V_60 . V_61 = V_250 ;
V_45 -> V_62 . V_61 = V_251 ;
V_45 -> V_60 . V_259 = 0 ;
V_45 -> V_62 . V_259 = 0 ;
}
V_253:
V_11 = F_112 ( V_2 , V_222 , V_45 ) ;
if ( ! V_11 )
V_11 = F_28 ( F_36 ( V_23 ) ) ;
F_123 ( V_23 ) ;
if ( ! V_11 )
V_11 = F_124 ( V_222 ) ;
V_12:
F_51 ( V_23 ) ;
if ( V_226 && ! F_6 ( V_226 ) )
F_15 ( V_226 ) ;
return V_11 ;
V_31:
V_11 = F_28 ( V_28 ) ;
goto V_12;
}
T_1
F_127 ( struct V_1 * V_2 , struct V_22 * V_23 , char * V_85 , int * V_260 )
{
struct V_36 * V_36 ;
T_10 V_185 ;
T_1 V_11 ;
int V_28 ;
struct V_8 V_8 ;
V_11 = F_30 ( V_2 , V_23 , V_261 , V_117 ) ;
if ( V_11 )
goto V_12;
V_8 . V_9 = V_23 -> V_30 -> V_10 . V_9 ;
V_8 . V_3 = V_23 -> V_29 ;
V_36 = V_8 . V_3 -> V_21 ;
V_11 = V_220 ;
if ( ! V_36 -> V_231 -> V_262 )
goto V_12;
F_128 ( & V_8 ) ;
V_185 = F_91 () ; F_92 ( V_191 ) ;
V_28 = V_36 -> V_231 -> V_262 ( V_8 . V_3 , V_85 , * V_260 ) ;
F_92 ( V_185 ) ;
if ( V_28 < 0 )
goto V_31;
* V_260 = V_28 ;
V_11 = 0 ;
V_12:
return V_11 ;
V_31:
V_11 = F_28 ( V_28 ) ;
goto V_12;
}
T_1
F_129 ( struct V_1 * V_2 , struct V_22 * V_23 ,
char * V_223 , int V_224 ,
char * V_8 , int V_263 ,
struct V_22 * V_222 ,
struct V_44 * V_45 )
{
struct V_3 * V_3 , * V_264 ;
T_1 V_11 , V_265 ;
int V_28 ;
V_11 = V_35 ;
if ( ! V_224 || ! V_263 )
goto V_12;
V_11 = V_228 ;
if ( F_25 ( V_223 , V_224 ) )
goto V_12;
V_11 = F_30 ( V_2 , V_23 , V_33 , V_229 ) ;
if ( V_11 )
goto V_12;
F_26 ( V_23 ) ;
V_3 = V_23 -> V_29 ;
V_264 = F_27 ( V_223 , V_3 , V_224 ) ;
V_28 = F_7 ( V_264 ) ;
if ( F_6 ( V_264 ) )
goto V_31;
V_28 = F_119 ( V_23 ) ;
if ( V_28 )
goto V_31;
if ( F_130 ( V_8 [ V_263 ] != 0 ) ) {
char * V_266 = F_54 ( V_263 + 1 , V_88 ) ;
if ( V_266 == NULL )
V_28 = - V_89 ;
else {
strncpy ( V_266 , V_8 , V_263 ) ;
V_266 [ V_263 ] = 0 ;
V_28 = F_131 ( V_3 -> V_21 , V_264 , V_266 ) ;
F_55 ( V_266 ) ;
}
} else
V_28 = F_131 ( V_3 -> V_21 , V_264 , V_8 ) ;
V_11 = F_28 ( V_28 ) ;
if ( ! V_11 )
V_11 = F_28 ( F_36 ( V_23 ) ) ;
F_51 ( V_23 ) ;
F_123 ( V_23 ) ;
V_265 = F_32 ( V_222 , V_23 -> V_30 , V_264 , V_23 ) ;
F_15 ( V_264 ) ;
if ( V_11 == 0 ) V_11 = V_265 ;
V_12:
return V_11 ;
V_31:
V_11 = F_28 ( V_28 ) ;
goto V_12;
}
T_1
F_132 ( struct V_1 * V_2 , struct V_22 * V_267 ,
char * V_24 , int V_25 , struct V_22 * V_268 )
{
struct V_3 * V_269 , * V_264 , * V_270 ;
struct V_36 * V_227 ;
T_1 V_11 ;
int V_28 ;
V_11 = F_30 ( V_2 , V_267 , V_33 , V_229 ) ;
if ( V_11 )
goto V_12;
V_11 = F_30 ( V_2 , V_268 , 0 , V_117 ) ;
if ( V_11 )
goto V_12;
V_11 = V_271 ;
if ( F_49 ( V_268 -> V_29 -> V_21 -> V_37 ) )
goto V_12;
V_11 = V_126 ;
if ( ! V_25 )
goto V_12;
V_11 = V_228 ;
if ( F_25 ( V_24 , V_25 ) )
goto V_12;
F_116 ( V_267 , V_233 ) ;
V_269 = V_267 -> V_29 ;
V_227 = V_269 -> V_21 ;
V_264 = F_27 ( V_24 , V_269 , V_25 ) ;
V_28 = F_7 ( V_264 ) ;
if ( F_6 ( V_264 ) )
goto V_31;
V_270 = V_268 -> V_29 ;
V_28 = F_119 ( V_268 ) ;
if ( V_28 ) {
V_11 = F_28 ( V_28 ) ;
goto V_272;
}
V_11 = V_35 ;
if ( ! V_270 -> V_21 )
goto V_273;
V_28 = F_33 ( V_270 -> V_21 ) ;
if ( V_28 ) {
V_11 = F_28 ( V_28 ) ;
goto V_273;
}
V_28 = F_133 ( V_270 , V_227 , V_264 ) ;
if ( ! V_28 ) {
V_11 = F_28 ( F_36 ( V_267 ) ) ;
if ( ! V_11 )
V_11 = F_28 ( F_36 ( V_268 ) ) ;
} else {
if ( V_28 == - V_274 && V_2 -> V_210 == 2 )
V_11 = V_125 ;
else
V_11 = F_28 ( V_28 ) ;
}
V_273:
F_123 ( V_268 ) ;
V_272:
F_15 ( V_264 ) ;
V_275:
F_51 ( V_267 ) ;
V_12:
return V_11 ;
V_31:
V_11 = F_28 ( V_28 ) ;
goto V_275;
}
T_1
F_134 ( struct V_1 * V_2 , struct V_22 * V_267 , char * V_223 , int V_224 ,
struct V_22 * V_268 , char * V_276 , int V_277 )
{
struct V_3 * V_278 , * V_279 , * V_280 , * V_281 , * V_282 ;
struct V_36 * V_283 , * V_284 ;
T_1 V_11 ;
int V_28 ;
V_11 = F_30 ( V_2 , V_267 , V_33 , V_285 ) ;
if ( V_11 )
goto V_12;
V_11 = F_30 ( V_2 , V_268 , V_33 , V_229 ) ;
if ( V_11 )
goto V_12;
V_278 = V_267 -> V_29 ;
V_283 = V_278 -> V_21 ;
V_279 = V_268 -> V_29 ;
V_284 = V_279 -> V_21 ;
V_11 = ( V_2 -> V_210 == 2 ) ? V_125 : V_286 ;
if ( V_267 -> V_30 != V_268 -> V_30 )
goto V_12;
V_11 = V_126 ;
if ( ! V_224 || F_25 ( V_223 , V_224 ) || ! V_277 || F_25 ( V_276 , V_277 ) )
goto V_12;
V_282 = F_135 ( V_279 , V_278 ) ;
V_267 -> V_234 = V_268 -> V_234 = 1 ;
F_136 ( V_267 ) ;
F_136 ( V_268 ) ;
V_280 = F_27 ( V_223 , V_278 , V_224 ) ;
V_28 = F_7 ( V_280 ) ;
if ( F_6 ( V_280 ) )
goto V_31;
V_28 = - V_13 ;
if ( ! V_280 -> V_21 )
goto V_287;
V_28 = - V_99 ;
if ( V_280 == V_282 )
goto V_287;
V_281 = F_27 ( V_276 , V_279 , V_277 ) ;
V_28 = F_7 ( V_281 ) ;
if ( F_6 ( V_281 ) )
goto V_287;
V_28 = - V_288 ;
if ( V_281 == V_282 )
goto V_289;
V_28 = - V_274 ;
if ( V_267 -> V_30 -> V_10 . V_9 != V_268 -> V_30 -> V_10 . V_9 )
goto V_289;
V_28 = F_119 ( V_267 ) ;
if ( V_28 )
goto V_289;
V_28 = F_33 ( V_280 -> V_21 ) ;
if ( V_28 )
goto V_273;
if ( V_281 -> V_21 ) {
V_28 = F_33 ( V_281 -> V_21 ) ;
if ( V_28 )
goto V_273;
}
V_28 = F_137 ( V_283 , V_280 , V_284 , V_281 ) ;
if ( ! V_28 ) {
V_28 = F_36 ( V_268 ) ;
if ( ! V_28 )
V_28 = F_36 ( V_267 ) ;
}
V_273:
F_123 ( V_267 ) ;
V_289:
F_15 ( V_281 ) ;
V_287:
F_15 ( V_280 ) ;
V_31:
V_11 = F_28 ( V_28 ) ;
F_138 ( V_267 ) ;
F_138 ( V_268 ) ;
F_139 ( V_279 , V_278 ) ;
V_267 -> V_234 = V_268 -> V_234 = 0 ;
V_12:
return V_11 ;
}
T_1
F_140 ( struct V_1 * V_2 , struct V_22 * V_23 , int type ,
char * V_223 , int V_224 )
{
struct V_3 * V_3 , * V_290 ;
struct V_36 * V_227 ;
T_1 V_11 ;
int V_28 ;
V_11 = V_125 ;
if ( ! V_224 || F_25 ( V_223 , V_224 ) )
goto V_12;
V_11 = F_30 ( V_2 , V_23 , V_33 , V_285 ) ;
if ( V_11 )
goto V_12;
F_116 ( V_23 , V_233 ) ;
V_3 = V_23 -> V_29 ;
V_227 = V_3 -> V_21 ;
V_290 = F_27 ( V_223 , V_3 , V_224 ) ;
V_28 = F_7 ( V_290 ) ;
if ( F_6 ( V_290 ) )
goto V_31;
if ( ! V_290 -> V_21 ) {
F_15 ( V_290 ) ;
V_11 = V_35 ;
goto V_12;
}
if ( ! type )
type = V_290 -> V_21 -> V_37 & V_291 ;
V_28 = F_119 ( V_23 ) ;
if ( V_28 )
goto V_292;
V_28 = F_33 ( V_290 -> V_21 ) ;
if ( V_28 )
goto V_273;
if ( type != V_33 )
V_28 = F_141 ( V_227 , V_290 ) ;
else
V_28 = F_142 ( V_227 , V_290 ) ;
if ( ! V_28 )
V_28 = F_36 ( V_23 ) ;
V_273:
F_123 ( V_23 ) ;
V_292:
F_15 ( V_290 ) ;
V_31:
V_11 = F_28 ( V_28 ) ;
V_12:
return V_11 ;
}
static int F_143 ( void * V_293 , const char * V_24 , int V_294 ,
T_9 V_180 , T_12 V_143 , unsigned int V_295 )
{
struct V_296 * V_85 = V_293 ;
struct V_297 * V_298 = ( void * ) ( V_85 -> V_299 + V_85 -> V_300 ) ;
unsigned int V_301 ;
V_301 = F_144 ( sizeof( struct V_297 ) + V_294 , sizeof( T_12 ) ) ;
if ( V_85 -> V_300 + V_301 > V_302 ) {
V_85 -> V_303 = 1 ;
return - V_99 ;
}
V_298 -> V_294 = V_294 ;
V_298 -> V_180 = V_180 ;
V_298 -> V_143 = V_143 ;
V_298 -> V_295 = V_295 ;
memcpy ( V_298 -> V_24 , V_24 , V_294 ) ;
V_85 -> V_300 += V_301 ;
return 0 ;
}
static T_1 F_145 ( struct V_131 * V_131 , T_13 V_304 ,
struct V_305 * V_306 , T_9 * V_307 )
{
struct V_296 V_85 ;
struct V_297 * V_298 ;
int V_28 ;
int V_176 ;
T_9 V_180 ;
V_85 . V_299 = ( void * ) F_146 ( V_88 ) ;
if ( ! V_85 . V_299 )
return F_28 ( - V_89 ) ;
V_180 = * V_307 ;
while ( 1 ) {
struct V_36 * V_308 = V_131 -> V_197 . V_3 -> V_21 ;
unsigned int V_301 ;
V_306 -> V_11 = V_309 ;
V_85 . V_300 = 0 ;
V_85 . V_303 = 0 ;
V_28 = F_147 ( V_131 , F_143 , & V_85 ) ;
if ( V_85 . V_303 )
V_28 = 0 ;
if ( V_28 < 0 )
break;
V_176 = V_85 . V_300 ;
if ( ! V_176 )
break;
V_28 = F_148 ( & V_308 -> V_196 ) ;
if ( V_28 )
break;
V_298 = (struct V_297 * ) V_85 . V_299 ;
while ( V_176 > 0 ) {
V_180 = V_298 -> V_180 ;
if ( V_304 ( V_306 , V_298 -> V_24 , V_298 -> V_294 , V_298 -> V_180 ,
V_298 -> V_143 , V_298 -> V_295 ) )
break;
if ( V_306 -> V_11 != V_123 )
break;
V_301 = F_144 ( sizeof( * V_298 ) + V_298 -> V_294 ,
sizeof( T_12 ) ) ;
V_176 -= V_301 ;
V_298 = (struct V_297 * ) ( ( char * ) V_298 + V_301 ) ;
}
F_97 ( & V_308 -> V_196 ) ;
if ( V_176 > 0 )
break;
V_180 = F_149 ( V_131 , 0 , V_310 ) ;
}
F_150 ( ( unsigned long ) ( V_85 . V_299 ) ) ;
if ( V_28 )
return F_28 ( V_28 ) ;
* V_307 = V_180 ;
return V_306 -> V_11 ;
}
T_1
F_151 ( struct V_1 * V_2 , struct V_22 * V_23 , T_9 * V_307 ,
struct V_305 * V_306 , T_13 V_304 )
{
T_1 V_11 ;
struct V_131 * V_131 ;
T_9 V_180 = * V_307 ;
int V_130 = V_135 ;
if ( V_2 -> V_210 > 2 )
V_130 |= V_137 ;
V_11 = F_71 ( V_2 , V_23 , V_33 , V_130 , & V_131 ) ;
if ( V_11 )
goto V_12;
V_180 = F_149 ( V_131 , V_180 , 0 ) ;
if ( V_180 < 0 ) {
V_11 = F_28 ( ( int ) V_180 ) ;
goto V_311;
}
V_11 = F_145 ( V_131 , V_304 , V_306 , V_307 ) ;
if ( V_11 == V_309 || V_11 == V_312 )
V_11 = V_123 ;
V_311:
F_78 ( V_131 ) ;
V_12:
return V_11 ;
}
T_1
F_152 ( struct V_1 * V_2 , struct V_22 * V_23 , struct V_313 * V_314 , int V_109 )
{
T_1 V_11 ;
V_11 = F_30 ( V_2 , V_23 , 0 , V_117 | V_109 ) ;
if ( ! V_11 ) {
struct V_8 V_8 = {
. V_9 = V_23 -> V_30 -> V_10 . V_9 ,
. V_3 = V_23 -> V_29 ,
} ;
if ( F_153 ( & V_8 , V_314 ) )
V_11 = V_238 ;
}
return V_11 ;
}
static int F_154 ( struct V_1 * V_2 , struct V_5 * exp )
{
return F_155 ( V_2 , exp ) & V_315 ;
}
T_1
F_45 ( struct V_1 * V_2 , struct V_5 * exp ,
struct V_3 * V_3 , int V_316 )
{
struct V_36 * V_36 = V_3 -> V_21 ;
int V_11 ;
if ( ( V_316 & V_317 ) == V_117 )
return 0 ;
#if 0
dprintk("nfsd: permission 0x%x%s%s%s%s%s%s%s mode 0%o%s%s%s\n",
acc,
(acc & NFSD_MAY_READ)? " read" : "",
(acc & NFSD_MAY_WRITE)? " write" : "",
(acc & NFSD_MAY_EXEC)? " exec" : "",
(acc & NFSD_MAY_SATTR)? " sattr" : "",
(acc & NFSD_MAY_TRUNC)? " trunc" : "",
(acc & NFSD_MAY_LOCK)? " lock" : "",
(acc & NFSD_MAY_OWNER_OVERRIDE)? " owneroverride" : "",
inode->i_mode,
IS_IMMUTABLE(inode)? " immut" : "",
IS_APPEND(inode)? " append" : "",
__mnt_is_readonly(exp->ex_path.mnt)? " ro" : "");
dprintk(" owner %d/%d user %d/%d\n",
inode->i_uid, inode->i_gid, current_fsuid(), current_fsgid());
#endif
if ( ! ( V_316 & V_318 ) )
if ( V_316 & ( V_56 | V_49 | V_66 ) ) {
if ( F_154 ( V_2 , exp ) ||
F_156 ( exp -> V_10 . V_9 ) )
return V_124 ;
if ( F_157 ( V_36 ) )
return V_126 ;
}
if ( ( V_316 & V_66 ) && F_73 ( V_36 ) )
return V_126 ;
if ( V_316 & V_319 ) {
if ( exp -> V_14 & V_320 )
return 0 ;
else
V_316 = V_135 | V_57 ;
}
if ( ( V_316 & V_57 ) &&
V_36 -> V_71 == F_113 () )
return 0 ;
V_11 = F_158 ( V_36 , V_316 & ( V_321 | V_322 | V_323 ) ) ;
if ( V_11 == - V_324 && F_34 ( V_36 -> V_37 ) &&
( V_316 == ( V_135 | V_57 ) ||
V_316 == ( V_135 | V_325 ) ) )
V_11 = F_158 ( V_36 , V_323 ) ;
return V_11 ? F_28 ( V_11 ) : 0 ;
}
void
F_159 ( void )
{
struct V_141 * V_326 , * V_327 ;
unsigned int V_328 ;
F_22 ( L_9 ) ;
for ( V_328 = 0 ; V_328 < V_329 ; V_328 ++ ) {
V_326 = V_152 [ V_328 ] . V_154 ;
while( V_326 ) {
V_327 = V_326 ;
V_326 = V_326 -> V_155 ;
F_55 ( V_327 ) ;
}
V_152 [ V_328 ] . V_154 = NULL ;
}
}
int
F_160 ( int V_330 )
{
int V_328 ;
int V_331 = 0 ;
int V_332 ;
struct V_141 * * V_326 = NULL ;
if ( V_152 [ 0 ] . V_154 )
return 0 ;
V_332 = F_161 ( V_330 , V_329 ) ;
if ( V_332 < 2 )
V_332 = 2 ;
V_330 = V_332 * V_329 ;
F_22 ( L_10 , V_330 ) ;
for ( V_328 = 0 ; V_328 < V_329 ; V_328 ++ ) {
F_162 ( & V_152 [ V_328 ] . V_153 ) ;
V_326 = & V_152 [ V_328 ] . V_154 ;
for ( V_331 = 0 ; V_331 < V_332 ; V_331 ++ ) {
* V_326 = F_163 ( sizeof( struct V_141 ) , V_88 ) ;
if ( ! * V_326 )
goto V_333;
V_326 = & ( * V_326 ) -> V_155 ;
}
* V_326 = NULL ;
}
V_160 . V_161 = V_330 ;
return 0 ;
V_333:
F_22 ( L_11 ) ;
F_159 () ;
return - V_89 ;
}
struct V_90 *
F_164 ( struct V_22 * V_23 , int type )
{
struct V_36 * V_36 = V_23 -> V_29 -> V_21 ;
char * V_24 ;
void * V_334 = NULL ;
T_4 V_176 ;
struct V_90 * V_94 ;
if ( ! F_165 ( V_36 ) )
return F_64 ( - V_104 ) ;
switch ( type ) {
case V_335 :
V_24 = V_101 ;
break;
case V_336 :
V_24 = V_103 ;
break;
default:
return F_64 ( - V_104 ) ;
}
V_176 = F_52 ( V_23 -> V_29 , V_24 , & V_334 ) ;
if ( V_176 < 0 )
return F_64 ( V_176 ) ;
V_94 = F_65 ( V_334 , V_176 ) ;
F_55 ( V_334 ) ;
return V_94 ;
}
int
F_166 ( struct V_22 * V_23 , int type , struct V_90 * V_94 )
{
struct V_36 * V_36 = V_23 -> V_29 -> V_21 ;
char * V_24 ;
void * V_334 = NULL ;
T_5 V_176 ;
int error ;
if ( ! F_165 ( V_36 ) ||
! V_36 -> V_231 -> V_337 || ! V_36 -> V_231 -> V_338 )
return - V_104 ;
switch( type ) {
case V_335 :
V_24 = V_101 ;
break;
case V_336 :
V_24 = V_103 ;
break;
default:
return - V_104 ;
}
if ( V_94 && V_94 -> V_92 ) {
V_176 = F_57 ( V_94 -> V_92 ) ;
V_334 = F_54 ( V_176 , V_88 ) ;
if ( ! V_334 )
return - V_89 ;
error = F_58 ( V_94 , V_334 , V_176 ) ;
if ( error < 0 )
goto V_339;
V_176 = error ;
} else
V_176 = 0 ;
error = F_119 ( V_23 ) ;
if ( error )
goto V_339;
if ( V_176 )
error = F_59 ( V_23 -> V_29 , V_24 , V_334 , V_176 , 0 ) ;
else {
if ( ! F_49 ( V_36 -> V_37 ) && type == V_336 )
error = 0 ;
else {
error = F_167 ( V_23 -> V_29 , V_24 ) ;
if ( error == - V_105 )
error = 0 ;
}
}
F_123 ( V_23 ) ;
V_339:
F_55 ( V_334 ) ;
return error ;
}

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
( ( ( V_45 -> V_52 & V_69 ) && ! F_50 ( V_45 -> V_70 , V_36 -> V_71 ) ) ||
( ( V_45 -> V_52 & V_72 ) && ! F_51 ( V_45 -> V_73 , V_36 -> V_74 ) ) ) ) {
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
V_28 = F_52 ( V_3 , V_45 ) ;
V_11 = F_28 ( V_28 ) ;
F_53 ( V_23 ) ;
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
static T_4 F_54 ( struct V_3 * V_3 , char * V_84 , void * * V_85 )
{
T_4 V_86 ;
T_4 V_87 ;
V_86 = F_55 ( V_3 , V_84 , NULL , 0 ) ;
if ( V_86 <= 0 )
return V_86 ;
* V_85 = F_56 ( V_86 , V_88 ) ;
if ( ! * V_85 )
return - V_89 ;
V_87 = F_55 ( V_3 , V_84 , * V_85 , V_86 ) ;
if ( V_87 < 0 )
F_57 ( * V_85 ) ;
return V_87 ;
}
static int
F_58 ( struct V_3 * V_3 , struct V_90 * V_91 , char * V_84 )
{
int V_25 ;
T_5 V_86 ;
char * V_85 = NULL ;
int error = 0 ;
V_86 = F_59 ( V_91 -> V_92 ) ;
V_85 = F_56 ( V_86 , V_88 ) ;
error = - V_89 ;
if ( V_85 == NULL )
goto V_12;
V_25 = F_60 ( & V_93 , V_91 , V_85 , V_86 ) ;
if ( V_25 < 0 ) {
error = V_25 ;
goto V_12;
}
error = F_61 ( V_3 , V_84 , V_85 , V_25 , 0 ) ;
V_12:
F_57 ( V_85 ) ;
return error ;
}
T_1
F_62 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_94 * V_95 )
{
T_1 error ;
int V_96 ;
struct V_3 * V_3 ;
struct V_36 * V_36 ;
struct V_90 * V_91 = NULL , * V_97 = NULL ;
unsigned int V_98 = 0 ;
error = F_30 ( V_2 , V_23 , 0 , V_49 ) ;
if ( error )
return error ;
V_3 = V_23 -> V_29 ;
V_36 = V_3 -> V_21 ;
if ( F_49 ( V_36 -> V_37 ) )
V_98 = V_99 ;
V_96 = F_63 ( V_95 , & V_91 , & V_97 , V_98 ) ;
if ( V_96 == - V_100 ) {
return V_101 ;
} else if ( V_96 < 0 )
goto V_31;
V_96 = F_58 ( V_3 , V_91 , V_102 ) ;
if ( V_96 < 0 )
goto V_103;
if ( F_49 ( V_36 -> V_37 ) )
V_96 = F_58 ( V_3 , V_97 , V_104 ) ;
V_103:
F_64 ( V_91 ) ;
F_64 ( V_97 ) ;
V_31:
if ( V_96 == - V_105 )
return V_101 ;
else
return F_28 ( V_96 ) ;
}
static struct V_90 *
F_65 ( struct V_3 * V_3 , char * V_84 )
{
void * V_85 = NULL ;
struct V_90 * V_91 = NULL ;
int V_86 ;
V_86 = F_54 ( V_3 , V_84 , & V_85 ) ;
if ( ! V_86 )
V_86 = - V_106 ;
if ( V_86 <= 0 )
return F_66 ( V_86 ) ;
V_91 = F_67 ( & V_93 , V_85 , V_86 ) ;
F_57 ( V_85 ) ;
return V_91 ;
}
int
F_68 ( struct V_1 * V_2 , struct V_3 * V_3 , struct V_94 * * V_95 )
{
struct V_36 * V_36 = V_3 -> V_21 ;
int error = 0 ;
struct V_90 * V_91 = NULL , * V_97 = NULL ;
unsigned int V_98 = 0 ;
V_91 = F_65 ( V_3 , V_102 ) ;
if ( F_6 ( V_91 ) && F_7 ( V_91 ) == - V_106 )
V_91 = F_69 ( V_36 -> V_37 , V_88 ) ;
if ( F_6 ( V_91 ) ) {
error = F_7 ( V_91 ) ;
V_91 = NULL ;
goto V_12;
}
if ( F_49 ( V_36 -> V_37 ) ) {
V_97 = F_65 ( V_3 , V_104 ) ;
if ( F_6 ( V_97 ) && F_7 ( V_97 ) == - V_106 )
V_97 = NULL ;
else if ( F_6 ( V_97 ) ) {
error = F_7 ( V_97 ) ;
V_97 = NULL ;
goto V_12;
}
V_98 = V_99 ;
}
* V_95 = F_70 ( V_91 , V_97 , V_98 ) ;
if ( F_6 ( * V_95 ) ) {
error = F_7 ( * V_95 ) ;
* V_95 = NULL ;
}
V_12:
F_64 ( V_91 ) ;
F_64 ( V_97 ) ;
return error ;
}
int F_20 ( struct V_3 * V_3 )
{
struct V_36 * V_36 = V_3 -> V_21 ;
if ( V_36 == NULL )
return 0 ;
if ( V_36 -> V_37 & V_107 )
return 0 ;
if ( ! ( V_36 -> V_37 & V_108 ) )
return 0 ;
if ( F_55 ( V_3 , V_109 , NULL , 0 ) <= 0 )
return 0 ;
return 1 ;
}
T_1 F_71 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_110 * V_111 )
{
T_1 error ;
int V_96 ;
struct V_3 * V_3 ;
error = F_30 ( V_2 , V_23 , 0 , V_49 ) ;
if ( error )
return error ;
V_3 = V_23 -> V_29 ;
F_72 ( & V_3 -> V_21 -> V_112 ) ;
V_96 = F_73 ( V_3 , V_111 -> V_113 , V_111 -> V_25 ) ;
F_74 ( & V_3 -> V_21 -> V_112 ) ;
return F_28 ( V_96 ) ;
}
T_1 F_71 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_110 * V_111 )
{
return V_114 ;
}
T_1
F_75 ( struct V_1 * V_2 , struct V_22 * V_23 , T_6 * V_115 , T_6 * V_116 )
{
struct V_117 * V_118 ;
struct V_5 * V_119 ;
struct V_3 * V_3 ;
T_6 V_120 , V_121 = 0 , V_122 = 0 ;
T_1 error ;
error = F_30 ( V_2 , V_23 , 0 , V_123 ) ;
if ( error )
goto V_12;
V_119 = V_23 -> V_30 ;
V_3 = V_23 -> V_29 ;
if ( F_34 ( V_3 -> V_21 -> V_37 ) )
V_118 = V_124 ;
else if ( F_49 ( V_3 -> V_21 -> V_37 ) )
V_118 = V_125 ;
else
V_118 = V_126 ;
V_120 = * V_115 ;
for (; V_118 -> V_115 ; V_118 ++ ) {
if ( V_118 -> V_115 & V_120 ) {
T_1 V_127 ;
V_122 |= V_118 -> V_115 ;
V_127 = F_45 ( V_2 , V_119 , V_3 , V_118 -> V_128 ) ;
switch ( V_127 ) {
case V_129 :
V_121 |= V_118 -> V_115 ;
break;
case V_130 :
case V_131 :
case V_132 :
break;
default:
error = V_127 ;
goto V_12;
}
}
}
* V_115 = V_121 ;
if ( V_116 )
* V_116 = V_122 ;
V_12:
return error ;
}
static int F_76 ( struct V_36 * V_36 , int V_115 )
{
unsigned int V_133 ;
if ( V_115 & V_134 )
return 0 ;
V_133 = ( V_115 & V_56 ) ? V_38 : V_135 ;
return F_35 ( V_36 , V_133 | V_39 ) ;
}
T_1
F_77 ( struct V_1 * V_2 , struct V_22 * V_23 , T_3 type ,
int V_136 , struct V_137 * * V_138 )
{
struct V_8 V_8 ;
struct V_36 * V_36 ;
int V_98 = V_135 | V_139 ;
T_1 V_11 ;
int V_28 = 0 ;
F_78 () ;
if ( type == V_58 )
V_136 |= V_57 ;
V_11 = F_30 ( V_2 , V_23 , type , V_136 ) ;
if ( V_11 )
goto V_12;
V_8 . V_9 = V_23 -> V_30 -> V_10 . V_9 ;
V_8 . V_3 = V_23 -> V_29 ;
V_36 = V_8 . V_3 -> V_21 ;
V_11 = V_132 ;
if ( F_79 ( V_36 ) && ( V_136 & V_56 ) )
goto V_12;
if ( F_34 ( ( V_36 ) -> V_37 ) && F_80 ( V_36 ) )
goto V_12;
if ( ! V_36 -> V_140 )
goto V_12;
V_28 = F_76 ( V_36 , V_136 ) ;
if ( V_28 )
goto V_31;
if ( V_136 & V_56 ) {
if ( V_136 & V_141 )
V_98 = V_142 | V_139 ;
else
V_98 = V_38 | V_139 ;
}
* V_138 = F_81 ( & V_8 , V_98 , F_82 () ) ;
if ( F_6 ( * V_138 ) ) {
V_28 = F_7 ( * V_138 ) ;
* V_138 = NULL ;
} else {
V_28 = F_83 ( * V_138 , V_136 ) ;
if ( V_136 & V_143 )
( * V_138 ) -> V_144 |= V_145 ;
else
( * V_138 ) -> V_144 |= V_146 ;
}
V_31:
V_11 = F_28 ( V_28 ) ;
V_12:
F_78 () ;
return V_11 ;
}
void
F_84 ( struct V_137 * V_138 )
{
F_85 ( V_138 ) ;
}
static inline struct V_147 *
F_86 ( T_7 V_148 , T_8 V_149 )
{
struct V_147 * V_150 , * * V_151 , * * V_152 = NULL ;
int V_153 = 0 ;
unsigned int V_154 ;
struct V_155 * V_156 ;
V_154 = F_87 ( V_148 , V_149 , 0xfeedbeef ) & V_157 ;
V_156 = & V_158 [ V_154 ] ;
F_88 ( & V_156 -> V_159 ) ;
for ( V_151 = & V_156 -> V_160 ; ( V_150 = * V_151 ) ; V_151 = & V_150 -> V_161 ) {
if ( V_150 -> V_162 == V_149 && V_150 -> V_163 == V_148 )
goto V_164;
V_153 ++ ;
if ( V_150 -> V_165 == 0 )
V_152 = V_151 ;
}
V_153 = V_166 . V_167 ;
if ( ! V_152 ) {
F_89 ( & V_156 -> V_159 ) ;
return NULL ;
}
V_151 = V_152 ;
V_150 = * V_152 ;
V_150 -> V_163 = V_148 ;
V_150 -> V_162 = V_149 ;
V_150 -> V_168 = 0 ;
V_150 -> V_169 = V_154 ;
V_164:
if ( V_151 != & V_156 -> V_160 ) {
* V_151 = V_150 -> V_161 ;
V_150 -> V_161 = V_156 -> V_160 ;
V_156 -> V_160 = V_150 ;
}
V_150 -> V_165 ++ ;
V_166 . V_170 [ V_153 * 10 / V_166 . V_167 ] ++ ;
F_89 ( & V_156 -> V_159 ) ;
return V_150 ;
}
static int
F_90 ( struct V_171 * V_172 , struct V_173 * V_85 ,
struct V_174 * V_175 )
{
struct V_1 * V_2 = V_175 -> V_176 . V_113 ;
struct V_177 * * V_178 = V_2 -> V_179 ;
struct V_177 * V_177 = V_85 -> V_177 ;
T_5 V_180 ;
V_180 = V_175 -> V_25 ;
if ( V_2 -> V_181 . V_182 == 0 ) {
F_91 ( V_177 ) ;
F_92 ( * V_2 -> V_179 ) ;
* ( V_2 -> V_179 ++ ) = V_177 ;
V_2 -> V_181 . V_183 = V_85 -> V_184 ;
V_2 -> V_181 . V_182 = V_180 ;
} else if ( V_177 != V_178 [ - 1 ] ) {
F_91 ( V_177 ) ;
if ( * V_2 -> V_179 )
F_92 ( * V_2 -> V_179 ) ;
* ( V_2 -> V_179 ++ ) = V_177 ;
V_2 -> V_181 . V_182 += V_180 ;
} else
V_2 -> V_181 . V_182 += V_180 ;
return V_180 ;
}
static int F_93 ( struct V_171 * V_172 ,
struct V_174 * V_175 )
{
return F_94 ( V_172 , V_175 , F_90 ) ;
}
static T_1
F_95 ( struct V_1 * V_2 , struct V_22 * V_23 , struct V_137 * V_137 ,
T_9 V_184 , struct V_185 * V_186 , int V_187 , unsigned long * V_188 )
{
T_10 V_189 ;
T_1 V_11 ;
int V_28 ;
V_11 = V_132 ;
if ( V_137 -> V_190 -> V_191 && V_2 -> V_192 ) {
struct V_174 V_175 = {
. V_25 = 0 ,
. V_193 = * V_188 ,
. V_194 = V_184 ,
. V_176 . V_113 = V_2 ,
} ;
V_2 -> V_179 = V_2 -> V_195 + 1 ;
V_28 = F_96 ( V_137 , & V_175 , F_93 ) ;
} else {
V_189 = F_97 () ;
F_98 ( V_196 ) ;
V_28 = F_99 ( V_137 , (struct V_197 V_198 * ) V_186 , V_187 , & V_184 ) ;
F_98 ( V_189 ) ;
}
if ( V_28 >= 0 ) {
V_166 . V_199 += V_28 ;
* V_188 = V_28 ;
V_11 = 0 ;
F_100 ( V_137 ) ;
} else
V_11 = F_28 ( V_28 ) ;
return V_11 ;
}
static void F_101 ( struct V_3 * V_3 )
{
struct V_44 V_200 ;
V_200 . V_52 = V_79 | V_80 | V_75 ;
F_72 ( & V_3 -> V_21 -> V_112 ) ;
F_52 ( V_3 , & V_200 ) ;
F_74 ( & V_3 -> V_21 -> V_112 ) ;
}
static int F_102 ( struct V_137 * V_137 )
{
struct V_36 * V_36 = F_103 ( V_137 ) ;
static T_8 V_201 ;
static T_7 V_202 ;
int V_11 = 0 ;
if ( F_104 ( & V_36 -> V_203 ) > 1
|| ( V_201 == V_36 -> V_204 && V_202 == V_36 -> V_42 -> V_205 ) ) {
F_22 ( L_2 , F_105 ( V_206 ) ) ;
F_106 ( 10 ) ;
F_22 ( L_3 , F_105 ( V_206 ) ) ;
}
if ( V_36 -> V_207 & V_208 ) {
F_22 ( L_4 , F_105 ( V_206 ) ) ;
V_11 = F_107 ( V_137 , 0 ) ;
}
V_201 = V_36 -> V_204 ;
V_202 = V_36 -> V_42 -> V_205 ;
return V_11 ;
}
static T_1
F_108 ( struct V_1 * V_2 , struct V_22 * V_23 , struct V_137 * V_137 ,
T_9 V_184 , struct V_185 * V_186 , int V_187 ,
unsigned long * V_209 , int * V_210 )
{
struct V_5 * exp ;
struct V_3 * V_3 ;
struct V_36 * V_36 ;
T_10 V_189 ;
T_1 V_11 = 0 ;
int V_28 ;
int V_211 = * V_210 ;
int V_212 ;
T_9 V_194 = V_184 ;
V_3 = V_137 -> V_213 . V_3 ;
V_36 = V_3 -> V_21 ;
exp = V_23 -> V_30 ;
V_212 = ( V_2 -> V_214 == 2 ) && F_109 ( exp ) ;
if ( ! F_37 ( exp ) )
V_211 = 0 ;
V_189 = F_97 () ; F_98 ( V_196 ) ;
V_28 = F_110 ( V_137 , (struct V_197 V_198 * ) V_186 , V_187 , & V_194 ) ;
F_98 ( V_189 ) ;
if ( V_28 < 0 )
goto V_31;
* V_209 = V_28 ;
V_166 . V_215 += V_28 ;
F_111 ( V_137 ) ;
if ( V_36 -> V_37 & ( V_76 | V_78 ) )
F_101 ( V_3 ) ;
if ( V_211 ) {
if ( V_212 )
V_28 = F_102 ( V_137 ) ;
else
V_28 = F_112 ( V_137 , V_184 , V_184 + * V_209 , 0 ) ;
}
V_31:
F_22 ( L_5 , V_28 ) ;
if ( V_28 >= 0 )
V_11 = 0 ;
else
V_11 = F_28 ( V_28 ) ;
return V_11 ;
}
T_1 F_113 ( struct V_1 * V_2 , struct V_22 * V_23 ,
T_9 V_184 , struct V_185 * V_186 , int V_187 , unsigned long * V_188 )
{
struct V_137 * V_137 ;
struct V_36 * V_36 ;
struct V_147 * V_150 ;
T_1 V_11 ;
V_11 = F_77 ( V_2 , V_23 , V_58 , V_141 , & V_137 ) ;
if ( V_11 )
return V_11 ;
V_36 = F_103 ( V_137 ) ;
V_150 = F_86 ( V_36 -> V_42 -> V_205 , V_36 -> V_204 ) ;
if ( V_150 && V_150 -> V_168 )
V_137 -> V_216 = V_150 -> V_217 ;
V_11 = F_95 ( V_2 , V_23 , V_137 , V_184 , V_186 , V_187 , V_188 ) ;
if ( V_150 ) {
struct V_155 * V_156 = & V_158 [ V_150 -> V_169 ] ;
F_88 ( & V_156 -> V_159 ) ;
V_150 -> V_217 = V_137 -> V_216 ;
V_150 -> V_168 = 1 ;
V_150 -> V_165 -- ;
F_89 ( & V_156 -> V_159 ) ;
}
F_84 ( V_137 ) ;
return V_11 ;
}
T_1
F_114 ( struct V_1 * V_2 , struct V_22 * V_23 , struct V_137 * V_137 ,
T_9 V_184 , struct V_185 * V_186 , int V_187 ,
unsigned long * V_188 )
{
T_1 V_11 ;
if ( V_137 ) {
V_11 = F_45 ( V_2 , V_23 -> V_30 , V_23 -> V_29 ,
V_141 | V_57 ) ;
if ( V_11 )
goto V_12;
V_11 = F_95 ( V_2 , V_23 , V_137 , V_184 , V_186 , V_187 , V_188 ) ;
} else
V_11 = F_113 ( V_2 , V_23 , V_184 , V_186 , V_187 , V_188 ) ;
V_12:
return V_11 ;
}
T_1
F_115 ( struct V_1 * V_2 , struct V_22 * V_23 , struct V_137 * V_137 ,
T_9 V_184 , struct V_185 * V_186 , int V_187 , unsigned long * V_209 ,
int * V_210 )
{
T_1 V_11 = 0 ;
if ( V_137 ) {
V_11 = F_45 ( V_2 , V_23 -> V_30 , V_23 -> V_29 ,
V_56 | V_57 ) ;
if ( V_11 )
goto V_12;
V_11 = F_108 ( V_2 , V_23 , V_137 , V_184 , V_186 , V_187 , V_209 ,
V_210 ) ;
} else {
V_11 = F_77 ( V_2 , V_23 , V_58 , V_56 , & V_137 ) ;
if ( V_11 )
goto V_12;
if ( V_209 )
V_11 = F_108 ( V_2 , V_23 , V_137 , V_184 , V_186 , V_187 ,
V_209 , V_210 ) ;
F_84 ( V_137 ) ;
}
V_12:
return V_11 ;
}
T_1
F_116 ( struct V_1 * V_2 , struct V_22 * V_23 ,
T_9 V_184 , unsigned long V_188 )
{
struct V_137 * V_137 ;
T_9 V_218 = V_219 ;
T_1 V_11 = V_220 ;
if ( V_184 < 0 )
goto V_12;
if ( V_188 != 0 ) {
V_218 = V_184 + ( T_9 ) V_188 - 1 ;
if ( V_218 < V_184 )
goto V_12;
}
V_11 = F_77 ( V_2 , V_23 , V_58 ,
V_56 | V_134 , & V_137 ) ;
if ( V_11 )
goto V_12;
if ( F_37 ( V_23 -> V_30 ) ) {
int V_127 = F_112 ( V_137 , V_184 , V_218 , 0 ) ;
if ( V_127 != - V_100 )
V_11 = F_28 ( V_127 ) ;
else
V_11 = V_114 ;
}
F_84 ( V_137 ) ;
V_12:
return V_11 ;
}
static T_1
F_117 ( struct V_1 * V_2 , struct V_22 * V_221 ,
struct V_44 * V_45 )
{
V_45 -> V_52 &= ~ V_59 ;
if ( ! F_50 ( F_118 () , V_222 ) )
V_45 -> V_52 &= ~ ( V_69 | V_72 ) ;
if ( V_45 -> V_52 )
return F_39 ( V_2 , V_221 , V_45 , 0 , ( T_2 ) 0 ) ;
return 0 ;
}
static void
F_119 ( struct V_44 * V_45 )
{
if ( ( V_45 -> V_52 & V_55 ) && ( V_45 -> V_64 == 0 ) )
V_45 -> V_52 &= ~ V_55 ;
}
T_1
F_120 ( struct V_1 * V_2 , struct V_22 * V_23 ,
char * V_223 , int V_224 , struct V_44 * V_45 ,
int type , T_7 V_225 , struct V_22 * V_221 )
{
struct V_3 * V_3 , * V_226 = NULL ;
struct V_36 * V_227 ;
T_1 V_11 ;
T_1 V_127 ;
int V_28 ;
V_11 = V_132 ;
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
if ( ! V_221 -> V_29 ) {
V_28 = F_121 ( V_23 ) ;
if ( V_28 )
goto V_31;
F_122 ( V_23 , V_233 ) ;
V_226 = F_27 ( V_223 , V_3 , V_224 ) ;
V_28 = F_7 ( V_226 ) ;
if ( F_6 ( V_226 ) )
goto V_31;
V_11 = F_32 ( V_221 , V_23 -> V_30 , V_226 , V_23 ) ;
if ( V_11 )
goto V_12;
} else {
V_226 = F_3 ( V_221 -> V_29 ) ;
if ( ! V_23 -> V_234 ) {
F_123 ( V_235
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
if ( ! F_34 ( type ) && ! F_49 ( type ) && ! F_124 ( type ) ) {
F_123 ( V_239 L_8 ,
type ) ;
goto V_12;
}
V_11 = 0 ;
V_28 = 0 ;
switch ( type ) {
case V_58 :
V_28 = F_125 ( V_227 , V_226 , V_45 -> V_67 , true ) ;
if ( ! V_28 )
F_119 ( V_45 ) ;
break;
case V_33 :
V_28 = F_126 ( V_227 , V_226 , V_45 -> V_67 ) ;
break;
case V_240 :
case V_241 :
case V_242 :
case V_243 :
V_28 = F_127 ( V_227 , V_226 , V_45 -> V_67 , V_225 ) ;
break;
}
if ( V_28 < 0 )
goto V_31;
V_11 = F_117 ( V_2 , V_221 , V_45 ) ;
V_127 = F_28 ( F_36 ( V_23 ) ) ;
if ( V_127 )
V_11 = V_127 ;
if ( ! V_11 )
V_11 = F_128 ( V_221 ) ;
V_12:
if ( V_226 && ! F_6 ( V_226 ) )
F_15 ( V_226 ) ;
return V_11 ;
V_31:
V_11 = F_28 ( V_28 ) ;
goto V_12;
}
static inline int F_129 ( int V_244 )
{
return V_244 == V_245
|| V_244 == V_246 ;
}
T_1
F_130 ( struct V_1 * V_2 , struct V_22 * V_23 ,
char * V_223 , int V_224 , struct V_44 * V_45 ,
struct V_22 * V_221 , int V_244 , T_6 * V_247 ,
bool * V_248 , bool * V_249 )
{
struct V_3 * V_3 , * V_226 = NULL ;
struct V_36 * V_227 ;
T_1 V_11 ;
int V_28 ;
T_11 V_250 = 0 , V_251 = 0 ;
V_11 = V_132 ;
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
V_28 = F_121 ( V_23 ) ;
if ( V_28 )
goto V_31;
F_122 ( V_23 , V_233 ) ;
V_226 = F_27 ( V_223 , V_3 , V_224 ) ;
V_28 = F_7 ( V_226 ) ;
if ( F_6 ( V_226 ) )
goto V_31;
if ( ! V_226 -> V_21 ) {
V_11 = F_30 ( V_2 , V_23 , V_33 , V_229 ) ;
if ( V_11 )
goto V_12;
}
V_11 = F_32 ( V_221 , V_23 -> V_30 , V_226 , V_23 ) ;
if ( V_11 )
goto V_12;
if ( F_129 ( V_244 ) ) {
V_250 = V_247 [ 0 ] & 0x7fffffff ;
V_251 = V_247 [ 1 ] & 0x7fffffff ;
}
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
&& V_226 -> V_21 -> V_65 == 0 ) {
if ( V_249 )
* V_249 = 1 ;
break;
}
case V_246 :
if ( V_226 -> V_21 -> V_254 . V_61 == V_250
&& V_226 -> V_21 -> V_255 . V_61 == V_251
&& V_226 -> V_21 -> V_65 == 0 ) {
if ( V_249 )
* V_249 = 1 ;
goto V_253;
}
case V_256 :
V_11 = V_228 ;
}
F_131 ( V_23 ) ;
goto V_12;
}
V_28 = F_125 ( V_227 , V_226 , V_45 -> V_67 , true ) ;
if ( V_28 < 0 ) {
F_131 ( V_23 ) ;
goto V_31;
}
if ( V_249 )
* V_249 = 1 ;
F_119 ( V_45 ) ;
if ( F_129 ( V_244 ) ) {
V_45 -> V_52 = V_54 | V_53
| V_257 | V_258 ;
V_45 -> V_60 . V_61 = V_250 ;
V_45 -> V_62 . V_61 = V_251 ;
V_45 -> V_60 . V_259 = 0 ;
V_45 -> V_62 . V_259 = 0 ;
}
V_253:
V_11 = F_117 ( V_2 , V_221 , V_45 ) ;
if ( ! V_11 )
V_11 = F_28 ( F_36 ( V_23 ) ) ;
if ( ! V_11 )
V_11 = F_128 ( V_221 ) ;
V_12:
F_53 ( V_23 ) ;
if ( V_226 && ! F_6 ( V_226 ) )
F_15 ( V_226 ) ;
F_131 ( V_23 ) ;
return V_11 ;
V_31:
V_11 = F_28 ( V_28 ) ;
goto V_12;
}
T_1
F_132 ( struct V_1 * V_2 , struct V_22 * V_23 , char * V_85 , int * V_260 )
{
struct V_36 * V_36 ;
T_10 V_189 ;
T_1 V_11 ;
int V_28 ;
struct V_8 V_8 ;
V_11 = F_30 ( V_2 , V_23 , V_261 , V_123 ) ;
if ( V_11 )
goto V_12;
V_8 . V_9 = V_23 -> V_30 -> V_10 . V_9 ;
V_8 . V_3 = V_23 -> V_29 ;
V_36 = V_8 . V_3 -> V_21 ;
V_11 = V_220 ;
if ( ! V_36 -> V_231 -> V_262 )
goto V_12;
F_133 ( & V_8 ) ;
V_189 = F_97 () ; F_98 ( V_196 ) ;
V_28 = V_36 -> V_231 -> V_262 ( V_8 . V_3 , ( char V_198 * ) V_85 , * V_260 ) ;
F_98 ( V_189 ) ;
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
F_134 ( struct V_1 * V_2 , struct V_22 * V_23 ,
char * V_223 , int V_224 ,
char * V_8 , int V_263 ,
struct V_22 * V_221 ,
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
V_28 = F_121 ( V_23 ) ;
if ( V_28 )
goto V_31;
F_26 ( V_23 ) ;
V_3 = V_23 -> V_29 ;
V_264 = F_27 ( V_223 , V_3 , V_224 ) ;
V_28 = F_7 ( V_264 ) ;
if ( F_6 ( V_264 ) )
goto V_31;
if ( F_135 ( V_8 [ V_263 ] != 0 ) ) {
char * V_266 = F_56 ( V_263 + 1 , V_88 ) ;
if ( V_266 == NULL )
V_28 = - V_89 ;
else {
strncpy ( V_266 , V_8 , V_263 ) ;
V_266 [ V_263 ] = 0 ;
V_28 = F_136 ( V_3 -> V_21 , V_264 , V_266 ) ;
F_57 ( V_266 ) ;
}
} else
V_28 = F_136 ( V_3 -> V_21 , V_264 , V_8 ) ;
V_11 = F_28 ( V_28 ) ;
if ( ! V_11 )
V_11 = F_28 ( F_36 ( V_23 ) ) ;
F_53 ( V_23 ) ;
F_131 ( V_23 ) ;
V_265 = F_32 ( V_221 , V_23 -> V_30 , V_264 , V_23 ) ;
F_15 ( V_264 ) ;
if ( V_11 == 0 ) V_11 = V_265 ;
V_12:
return V_11 ;
V_31:
V_11 = F_28 ( V_28 ) ;
goto V_12;
}
T_1
F_137 ( struct V_1 * V_2 , struct V_22 * V_267 ,
char * V_24 , int V_25 , struct V_22 * V_268 )
{
struct V_3 * V_269 , * V_264 , * V_270 ;
struct V_36 * V_227 ;
T_1 V_11 ;
int V_28 ;
V_11 = F_30 ( V_2 , V_267 , V_33 , V_229 ) ;
if ( V_11 )
goto V_12;
V_11 = F_30 ( V_2 , V_268 , 0 , V_123 ) ;
if ( V_11 )
goto V_12;
V_11 = V_271 ;
if ( F_49 ( V_268 -> V_29 -> V_21 -> V_37 ) )
goto V_12;
V_11 = V_132 ;
if ( ! V_25 )
goto V_12;
V_11 = V_228 ;
if ( F_25 ( V_24 , V_25 ) )
goto V_12;
V_28 = F_121 ( V_268 ) ;
if ( V_28 ) {
V_11 = F_28 ( V_28 ) ;
goto V_12;
}
F_122 ( V_267 , V_233 ) ;
V_269 = V_267 -> V_29 ;
V_227 = V_269 -> V_21 ;
V_264 = F_27 ( V_24 , V_269 , V_25 ) ;
V_28 = F_7 ( V_264 ) ;
if ( F_6 ( V_264 ) )
goto V_31;
V_270 = V_268 -> V_29 ;
V_11 = V_35 ;
if ( ! V_270 -> V_21 )
goto V_272;
V_28 = F_33 ( V_270 -> V_21 ) ;
if ( V_28 ) {
V_11 = F_28 ( V_28 ) ;
goto V_272;
}
V_28 = F_138 ( V_270 , V_227 , V_264 ) ;
if ( ! V_28 ) {
V_11 = F_28 ( F_36 ( V_267 ) ) ;
if ( ! V_11 )
V_11 = F_28 ( F_36 ( V_268 ) ) ;
} else {
if ( V_28 == - V_273 && V_2 -> V_214 == 2 )
V_11 = V_131 ;
else
V_11 = F_28 ( V_28 ) ;
}
V_272:
F_15 ( V_264 ) ;
V_274:
F_53 ( V_267 ) ;
F_131 ( V_268 ) ;
V_12:
return V_11 ;
V_31:
V_11 = F_28 ( V_28 ) ;
goto V_274;
}
T_1
F_139 ( struct V_1 * V_2 , struct V_22 * V_267 , char * V_223 , int V_224 ,
struct V_22 * V_268 , char * V_275 , int V_276 )
{
struct V_3 * V_277 , * V_278 , * V_279 , * V_280 , * V_281 ;
struct V_36 * V_282 , * V_283 ;
T_1 V_11 ;
int V_28 ;
V_11 = F_30 ( V_2 , V_267 , V_33 , V_284 ) ;
if ( V_11 )
goto V_12;
V_11 = F_30 ( V_2 , V_268 , V_33 , V_229 ) ;
if ( V_11 )
goto V_12;
V_277 = V_267 -> V_29 ;
V_282 = V_277 -> V_21 ;
V_278 = V_268 -> V_29 ;
V_283 = V_278 -> V_21 ;
V_11 = V_132 ;
if ( ! V_224 || F_25 ( V_223 , V_224 ) || ! V_276 || F_25 ( V_275 , V_276 ) )
goto V_12;
V_28 = F_121 ( V_267 ) ;
if ( V_28 ) {
V_11 = F_28 ( V_28 ) ;
goto V_12;
}
V_281 = F_140 ( V_278 , V_277 ) ;
V_267 -> V_234 = V_268 -> V_234 = 1 ;
F_141 ( V_267 ) ;
F_141 ( V_268 ) ;
V_279 = F_27 ( V_223 , V_277 , V_224 ) ;
V_28 = F_7 ( V_279 ) ;
if ( F_6 ( V_279 ) )
goto V_31;
V_28 = - V_13 ;
if ( ! V_279 -> V_21 )
goto V_285;
V_28 = - V_100 ;
if ( V_279 == V_281 )
goto V_285;
V_280 = F_27 ( V_275 , V_278 , V_276 ) ;
V_28 = F_7 ( V_280 ) ;
if ( F_6 ( V_280 ) )
goto V_285;
V_28 = - V_286 ;
if ( V_280 == V_281 )
goto V_287;
V_28 = - V_273 ;
if ( V_267 -> V_30 -> V_10 . V_9 != V_268 -> V_30 -> V_10 . V_9 )
goto V_287;
if ( V_267 -> V_30 -> V_10 . V_3 != V_268 -> V_30 -> V_10 . V_3 )
goto V_287;
V_28 = F_33 ( V_279 -> V_21 ) ;
if ( V_28 )
goto V_287;
if ( V_280 -> V_21 ) {
V_28 = F_33 ( V_280 -> V_21 ) ;
if ( V_28 )
goto V_287;
}
V_28 = F_142 ( V_282 , V_279 , V_283 , V_280 ) ;
if ( ! V_28 ) {
V_28 = F_36 ( V_268 ) ;
if ( ! V_28 )
V_28 = F_36 ( V_267 ) ;
}
V_287:
F_15 ( V_280 ) ;
V_285:
F_15 ( V_279 ) ;
V_31:
V_11 = F_28 ( V_28 ) ;
F_143 ( V_267 ) ;
F_143 ( V_268 ) ;
F_144 ( V_278 , V_277 ) ;
V_267 -> V_234 = V_268 -> V_234 = 0 ;
F_131 ( V_267 ) ;
V_12:
return V_11 ;
}
T_1
F_145 ( struct V_1 * V_2 , struct V_22 * V_23 , int type ,
char * V_223 , int V_224 )
{
struct V_3 * V_3 , * V_288 ;
struct V_36 * V_227 ;
T_1 V_11 ;
int V_28 ;
V_11 = V_131 ;
if ( ! V_224 || F_25 ( V_223 , V_224 ) )
goto V_12;
V_11 = F_30 ( V_2 , V_23 , V_33 , V_284 ) ;
if ( V_11 )
goto V_12;
V_28 = F_121 ( V_23 ) ;
if ( V_28 )
goto V_31;
F_122 ( V_23 , V_233 ) ;
V_3 = V_23 -> V_29 ;
V_227 = V_3 -> V_21 ;
V_288 = F_27 ( V_223 , V_3 , V_224 ) ;
V_28 = F_7 ( V_288 ) ;
if ( F_6 ( V_288 ) )
goto V_31;
if ( ! V_288 -> V_21 ) {
F_15 ( V_288 ) ;
V_11 = V_35 ;
goto V_12;
}
if ( ! type )
type = V_288 -> V_21 -> V_37 & V_289 ;
V_28 = F_33 ( V_288 -> V_21 ) ;
if ( V_28 )
goto V_290;
if ( type != V_33 )
V_28 = F_146 ( V_227 , V_288 ) ;
else
V_28 = F_147 ( V_227 , V_288 ) ;
if ( ! V_28 )
V_28 = F_36 ( V_23 ) ;
V_290:
F_15 ( V_288 ) ;
V_31:
V_11 = F_28 ( V_28 ) ;
V_12:
return V_11 ;
}
static int F_148 ( void * V_291 , const char * V_24 , int V_292 ,
T_9 V_184 , T_12 V_149 , unsigned int V_293 )
{
struct V_294 * V_85 = V_291 ;
struct V_295 * V_296 = ( void * ) ( V_85 -> V_297 + V_85 -> V_298 ) ;
unsigned int V_299 ;
V_299 = F_149 ( sizeof( struct V_295 ) + V_292 , sizeof( T_12 ) ) ;
if ( V_85 -> V_298 + V_299 > V_300 ) {
V_85 -> V_301 = 1 ;
return - V_100 ;
}
V_296 -> V_292 = V_292 ;
V_296 -> V_184 = V_184 ;
V_296 -> V_149 = V_149 ;
V_296 -> V_293 = V_293 ;
memcpy ( V_296 -> V_24 , V_24 , V_292 ) ;
V_85 -> V_298 += V_299 ;
return 0 ;
}
static T_1 F_150 ( struct V_137 * V_137 , T_13 V_302 ,
struct V_303 * V_304 , T_9 * V_305 )
{
struct V_295 * V_296 ;
int V_28 ;
int V_180 ;
T_9 V_184 ;
struct V_294 V_85 = {
. V_306 . V_307 = F_148 ,
. V_297 = ( void * ) F_151 (GFP_KERNEL)
} ;
if ( ! V_85 . V_297 )
return F_28 ( - V_89 ) ;
V_184 = * V_305 ;
while ( 1 ) {
struct V_36 * V_308 = F_103 ( V_137 ) ;
unsigned int V_299 ;
V_304 -> V_11 = V_309 ;
V_85 . V_298 = 0 ;
V_85 . V_301 = 0 ;
V_28 = F_152 ( V_137 , & V_85 . V_306 ) ;
if ( V_85 . V_301 )
V_28 = 0 ;
if ( V_28 < 0 )
break;
V_180 = V_85 . V_298 ;
if ( ! V_180 )
break;
V_28 = F_153 ( & V_308 -> V_112 ) ;
if ( V_28 )
break;
V_296 = (struct V_295 * ) V_85 . V_297 ;
while ( V_180 > 0 ) {
V_184 = V_296 -> V_184 ;
if ( V_302 ( V_304 , V_296 -> V_24 , V_296 -> V_292 , V_296 -> V_184 ,
V_296 -> V_149 , V_296 -> V_293 ) )
break;
if ( V_304 -> V_11 != V_129 )
break;
V_299 = F_149 ( sizeof( * V_296 ) + V_296 -> V_292 ,
sizeof( T_12 ) ) ;
V_180 -= V_299 ;
V_296 = (struct V_295 * ) ( ( char * ) V_296 + V_299 ) ;
}
F_74 ( & V_308 -> V_112 ) ;
if ( V_180 > 0 )
break;
V_184 = F_154 ( V_137 , 0 , V_310 ) ;
}
F_155 ( ( unsigned long ) ( V_85 . V_297 ) ) ;
if ( V_28 )
return F_28 ( V_28 ) ;
* V_305 = V_184 ;
return V_304 -> V_11 ;
}
T_1
F_156 ( struct V_1 * V_2 , struct V_22 * V_23 , T_9 * V_305 ,
struct V_303 * V_304 , T_13 V_302 )
{
T_1 V_11 ;
struct V_137 * V_137 ;
T_9 V_184 = * V_305 ;
int V_136 = V_141 ;
if ( V_2 -> V_214 > 2 )
V_136 |= V_143 ;
V_11 = F_77 ( V_2 , V_23 , V_33 , V_136 , & V_137 ) ;
if ( V_11 )
goto V_12;
V_184 = F_154 ( V_137 , V_184 , V_311 ) ;
if ( V_184 < 0 ) {
V_11 = F_28 ( ( int ) V_184 ) ;
goto V_312;
}
V_11 = F_150 ( V_137 , V_302 , V_304 , V_305 ) ;
if ( V_11 == V_309 || V_11 == V_313 )
V_11 = V_129 ;
V_312:
F_84 ( V_137 ) ;
V_12:
return V_11 ;
}
T_1
F_157 ( struct V_1 * V_2 , struct V_22 * V_23 , struct V_314 * V_315 , int V_115 )
{
T_1 V_11 ;
V_11 = F_30 ( V_2 , V_23 , 0 , V_123 | V_115 ) ;
if ( ! V_11 ) {
struct V_8 V_8 = {
. V_9 = V_23 -> V_30 -> V_10 . V_9 ,
. V_3 = V_23 -> V_29 ,
} ;
if ( F_158 ( & V_8 , V_315 ) )
V_11 = V_238 ;
}
return V_11 ;
}
static int F_159 ( struct V_1 * V_2 , struct V_5 * exp )
{
return F_160 ( V_2 , exp ) & V_316 ;
}
T_1
F_45 ( struct V_1 * V_2 , struct V_5 * exp ,
struct V_3 * V_3 , int V_317 )
{
struct V_36 * V_36 = V_3 -> V_21 ;
int V_11 ;
if ( ( V_317 & V_318 ) == V_123 )
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
if ( ! ( V_317 & V_319 ) )
if ( V_317 & ( V_56 | V_49 | V_66 ) ) {
if ( F_159 ( V_2 , exp ) ||
F_161 ( exp -> V_10 . V_9 ) )
return V_130 ;
if ( F_162 ( V_36 ) )
return V_132 ;
}
if ( ( V_317 & V_66 ) && F_79 ( V_36 ) )
return V_132 ;
if ( V_317 & V_320 ) {
if ( exp -> V_14 & V_321 )
return 0 ;
else
V_317 = V_141 | V_57 ;
}
if ( ( V_317 & V_57 ) &&
F_50 ( V_36 -> V_71 , F_118 () ) )
return 0 ;
V_11 = F_163 ( V_36 , V_317 & ( V_322 | V_323 | V_324 ) ) ;
if ( V_11 == - V_325 && F_34 ( V_36 -> V_37 ) &&
( V_317 == ( V_141 | V_57 ) ||
V_317 == ( V_141 | V_326 ) ) )
V_11 = F_163 ( V_36 , V_324 ) ;
return V_11 ? F_28 ( V_11 ) : 0 ;
}
void
F_164 ( void )
{
struct V_147 * V_327 , * V_328 ;
unsigned int V_329 ;
F_22 ( L_9 ) ;
for ( V_329 = 0 ; V_329 < V_330 ; V_329 ++ ) {
V_327 = V_158 [ V_329 ] . V_160 ;
while( V_327 ) {
V_328 = V_327 ;
V_327 = V_327 -> V_161 ;
F_57 ( V_328 ) ;
}
V_158 [ V_329 ] . V_160 = NULL ;
}
}
int
F_165 ( int V_331 )
{
int V_329 ;
int V_332 = 0 ;
int V_333 ;
struct V_147 * * V_327 = NULL ;
if ( V_158 [ 0 ] . V_160 )
return 0 ;
V_333 = F_166 ( V_331 , V_330 ) ;
if ( V_333 < 2 )
V_333 = 2 ;
V_331 = V_333 * V_330 ;
F_22 ( L_10 , V_331 ) ;
for ( V_329 = 0 ; V_329 < V_330 ; V_329 ++ ) {
F_167 ( & V_158 [ V_329 ] . V_159 ) ;
V_327 = & V_158 [ V_329 ] . V_160 ;
for ( V_332 = 0 ; V_332 < V_333 ; V_332 ++ ) {
* V_327 = F_168 ( sizeof( struct V_147 ) , V_88 ) ;
if ( ! * V_327 )
goto V_334;
V_327 = & ( * V_327 ) -> V_161 ;
}
* V_327 = NULL ;
}
V_166 . V_167 = V_331 ;
return 0 ;
V_334:
F_22 ( L_11 ) ;
F_164 () ;
return - V_89 ;
}
struct V_90 *
F_169 ( struct V_22 * V_23 , int type )
{
struct V_36 * V_36 = V_23 -> V_29 -> V_21 ;
char * V_24 ;
void * V_335 = NULL ;
T_4 V_180 ;
struct V_90 * V_95 ;
if ( ! F_170 ( V_36 ) )
return F_66 ( - V_105 ) ;
switch ( type ) {
case V_336 :
V_24 = V_102 ;
break;
case V_337 :
V_24 = V_104 ;
break;
default:
return F_66 ( - V_105 ) ;
}
V_180 = F_54 ( V_23 -> V_29 , V_24 , & V_335 ) ;
if ( V_180 < 0 )
return F_66 ( V_180 ) ;
V_95 = F_67 ( & V_93 , V_335 , V_180 ) ;
F_57 ( V_335 ) ;
return V_95 ;
}
int
F_171 ( struct V_22 * V_23 , int type , struct V_90 * V_95 )
{
struct V_36 * V_36 = V_23 -> V_29 -> V_21 ;
char * V_24 ;
void * V_335 = NULL ;
T_5 V_180 ;
int error ;
if ( ! F_170 ( V_36 ) ||
! V_36 -> V_231 -> V_338 || ! V_36 -> V_231 -> V_339 )
return - V_105 ;
switch( type ) {
case V_336 :
V_24 = V_102 ;
break;
case V_337 :
V_24 = V_104 ;
break;
default:
return - V_105 ;
}
if ( V_95 && V_95 -> V_92 ) {
V_180 = F_59 ( V_95 -> V_92 ) ;
V_335 = F_56 ( V_180 , V_88 ) ;
if ( ! V_335 )
return - V_89 ;
error = F_60 ( & V_93 , V_95 , V_335 , V_180 ) ;
if ( error < 0 )
goto V_340;
V_180 = error ;
} else
V_180 = 0 ;
error = F_121 ( V_23 ) ;
if ( error )
goto V_340;
if ( V_180 )
error = F_61 ( V_23 -> V_29 , V_24 , V_335 , V_180 , 0 ) ;
else {
if ( ! F_49 ( V_36 -> V_37 ) && type == V_337 )
error = 0 ;
else {
error = F_172 ( V_23 -> V_29 , V_24 ) ;
if ( error == - V_106 )
error = 0 ;
}
}
F_131 ( V_23 ) ;
V_340:
F_57 ( V_335 ) ;
return error ;
}

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
V_25 = F_58 ( & V_93 , V_91 , V_85 , V_86 ) ;
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
V_96 = F_61 ( V_95 , & V_91 , & V_97 , V_98 ) ;
if ( V_96 == - V_100 ) {
return V_101 ;
} else if ( V_96 < 0 )
goto V_31;
V_96 = F_56 ( V_3 , V_91 , V_102 ) ;
if ( V_96 < 0 )
goto V_103;
if ( F_49 ( V_36 -> V_37 ) )
V_96 = F_56 ( V_3 , V_97 , V_104 ) ;
V_103:
F_62 ( V_91 ) ;
F_62 ( V_97 ) ;
V_31:
if ( V_96 == - V_105 )
return V_101 ;
else
return F_28 ( V_96 ) ;
}
static struct V_90 *
F_63 ( struct V_3 * V_3 , char * V_84 )
{
void * V_85 = NULL ;
struct V_90 * V_91 = NULL ;
int V_86 ;
V_86 = F_52 ( V_3 , V_84 , & V_85 ) ;
if ( ! V_86 )
V_86 = - V_106 ;
if ( V_86 <= 0 )
return F_64 ( V_86 ) ;
V_91 = F_65 ( & V_93 , V_85 , V_86 ) ;
F_55 ( V_85 ) ;
return V_91 ;
}
int
F_66 ( struct V_1 * V_2 , struct V_3 * V_3 , struct V_94 * * V_95 )
{
struct V_36 * V_36 = V_3 -> V_21 ;
int error = 0 ;
struct V_90 * V_91 = NULL , * V_97 = NULL ;
unsigned int V_98 = 0 ;
V_91 = F_63 ( V_3 , V_102 ) ;
if ( F_6 ( V_91 ) && F_7 ( V_91 ) == - V_106 )
V_91 = F_67 ( V_36 -> V_37 , V_88 ) ;
if ( F_6 ( V_91 ) ) {
error = F_7 ( V_91 ) ;
V_91 = NULL ;
goto V_12;
}
if ( F_49 ( V_36 -> V_37 ) ) {
V_97 = F_63 ( V_3 , V_104 ) ;
if ( F_6 ( V_97 ) && F_7 ( V_97 ) == - V_106 )
V_97 = NULL ;
else if ( F_6 ( V_97 ) ) {
error = F_7 ( V_97 ) ;
V_97 = NULL ;
goto V_12;
}
V_98 = V_99 ;
}
* V_95 = F_68 ( V_91 , V_97 , V_98 ) ;
if ( F_6 ( * V_95 ) ) {
error = F_7 ( * V_95 ) ;
* V_95 = NULL ;
}
V_12:
F_62 ( V_91 ) ;
F_62 ( V_97 ) ;
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
if ( F_53 ( V_3 , V_109 , NULL , 0 ) <= 0 )
return 0 ;
return 1 ;
}
T_1
F_69 ( struct V_1 * V_2 , struct V_22 * V_23 , T_6 * V_110 , T_6 * V_111 )
{
struct V_112 * V_113 ;
struct V_5 * V_114 ;
struct V_3 * V_3 ;
T_6 V_115 , V_116 = 0 , V_117 = 0 ;
T_1 error ;
error = F_30 ( V_2 , V_23 , 0 , V_118 ) ;
if ( error )
goto V_12;
V_114 = V_23 -> V_30 ;
V_3 = V_23 -> V_29 ;
if ( F_34 ( V_3 -> V_21 -> V_37 ) )
V_113 = V_119 ;
else if ( F_49 ( V_3 -> V_21 -> V_37 ) )
V_113 = V_120 ;
else
V_113 = V_121 ;
V_115 = * V_110 ;
for (; V_113 -> V_110 ; V_113 ++ ) {
if ( V_113 -> V_110 & V_115 ) {
T_1 V_122 ;
V_117 |= V_113 -> V_110 ;
V_122 = F_45 ( V_2 , V_114 , V_3 , V_113 -> V_123 ) ;
switch ( V_122 ) {
case V_124 :
V_116 |= V_113 -> V_110 ;
break;
case V_125 :
case V_126 :
case V_127 :
break;
default:
error = V_122 ;
goto V_12;
}
}
}
* V_110 = V_116 ;
if ( V_111 )
* V_111 = V_117 ;
V_12:
return error ;
}
static int F_70 ( struct V_36 * V_36 , int V_110 )
{
unsigned int V_128 ;
if ( V_110 & V_129 )
return 0 ;
V_128 = ( V_110 & V_56 ) ? V_38 : V_130 ;
return F_35 ( V_36 , V_128 | V_39 ) ;
}
T_1
F_71 ( struct V_1 * V_2 , struct V_22 * V_23 , T_3 type ,
int V_131 , struct V_132 * * V_133 )
{
struct V_8 V_8 ;
struct V_36 * V_36 ;
int V_98 = V_130 | V_134 ;
T_1 V_11 ;
int V_28 = 0 ;
F_72 () ;
if ( type == V_58 )
V_131 |= V_57 ;
V_11 = F_30 ( V_2 , V_23 , type , V_131 ) ;
if ( V_11 )
goto V_12;
V_8 . V_9 = V_23 -> V_30 -> V_10 . V_9 ;
V_8 . V_3 = V_23 -> V_29 ;
V_36 = V_8 . V_3 -> V_21 ;
V_11 = V_127 ;
if ( F_73 ( V_36 ) && ( V_131 & V_56 ) )
goto V_12;
if ( F_34 ( ( V_36 ) -> V_37 ) && F_74 ( V_36 ) )
goto V_12;
if ( ! V_36 -> V_135 )
goto V_12;
V_28 = F_70 ( V_36 , V_131 ) ;
if ( V_28 )
goto V_31;
if ( V_131 & V_56 ) {
if ( V_131 & V_136 )
V_98 = V_137 | V_134 ;
else
V_98 = V_38 | V_134 ;
}
* V_133 = F_75 ( & V_8 , V_98 , F_76 () ) ;
if ( F_6 ( * V_133 ) )
V_28 = F_7 ( * V_133 ) ;
else {
V_28 = F_77 ( * V_133 , V_131 ) ;
if ( V_131 & V_138 )
( * V_133 ) -> V_139 |= V_140 ;
else
( * V_133 ) -> V_139 |= V_141 ;
}
V_31:
V_11 = F_28 ( V_28 ) ;
V_12:
F_72 () ;
return V_11 ;
}
void
F_78 ( struct V_132 * V_133 )
{
F_79 ( V_133 ) ;
}
static inline struct V_142 *
F_80 ( T_7 V_143 , T_8 V_144 )
{
struct V_142 * V_145 , * * V_146 , * * V_147 = NULL ;
int V_148 = 0 ;
unsigned int V_149 ;
struct V_150 * V_151 ;
V_149 = F_81 ( V_143 , V_144 , 0xfeedbeef ) & V_152 ;
V_151 = & V_153 [ V_149 ] ;
F_82 ( & V_151 -> V_154 ) ;
for ( V_146 = & V_151 -> V_155 ; ( V_145 = * V_146 ) ; V_146 = & V_145 -> V_156 ) {
if ( V_145 -> V_157 == V_144 && V_145 -> V_158 == V_143 )
goto V_159;
V_148 ++ ;
if ( V_145 -> V_160 == 0 )
V_147 = V_146 ;
}
V_148 = V_161 . V_162 ;
if ( ! V_147 ) {
F_83 ( & V_151 -> V_154 ) ;
return NULL ;
}
V_146 = V_147 ;
V_145 = * V_147 ;
V_145 -> V_158 = V_143 ;
V_145 -> V_157 = V_144 ;
V_145 -> V_163 = 0 ;
V_145 -> V_164 = V_149 ;
V_159:
if ( V_146 != & V_151 -> V_155 ) {
* V_146 = V_145 -> V_156 ;
V_145 -> V_156 = V_151 -> V_155 ;
V_151 -> V_155 = V_145 ;
}
V_145 -> V_160 ++ ;
V_161 . V_165 [ V_148 * 10 / V_161 . V_162 ] ++ ;
F_83 ( & V_151 -> V_154 ) ;
return V_145 ;
}
static int
F_84 ( struct V_166 * V_167 , struct V_168 * V_85 ,
struct V_169 * V_170 )
{
struct V_1 * V_2 = V_170 -> V_171 . V_172 ;
struct V_173 * * V_174 = V_2 -> V_175 + V_2 -> V_176 ;
struct V_173 * V_173 = V_85 -> V_173 ;
T_5 V_177 ;
V_177 = V_170 -> V_25 ;
if ( V_2 -> V_178 . V_179 == 0 ) {
F_85 ( V_173 ) ;
F_86 ( * V_174 ) ;
* V_174 = V_173 ;
V_2 -> V_176 ++ ;
V_2 -> V_178 . V_180 = V_85 -> V_181 ;
V_2 -> V_178 . V_179 = V_177 ;
} else if ( V_173 != V_174 [ - 1 ] ) {
F_85 ( V_173 ) ;
if ( * V_174 )
F_86 ( * V_174 ) ;
* V_174 = V_173 ;
V_2 -> V_176 ++ ;
V_2 -> V_178 . V_179 += V_177 ;
} else
V_2 -> V_178 . V_179 += V_177 ;
return V_177 ;
}
static int F_87 ( struct V_166 * V_167 ,
struct V_169 * V_170 )
{
return F_88 ( V_167 , V_170 , F_84 ) ;
}
static T_1
F_89 ( struct V_1 * V_2 , struct V_22 * V_23 , struct V_132 * V_132 ,
T_9 V_181 , struct V_182 * V_183 , int V_184 , unsigned long * V_185 )
{
T_10 V_186 ;
T_1 V_11 ;
int V_28 ;
V_11 = V_127 ;
if ( V_132 -> V_187 -> V_188 && V_2 -> V_189 ) {
struct V_169 V_170 = {
. V_25 = 0 ,
. V_190 = * V_185 ,
. V_191 = V_181 ,
. V_171 . V_172 = V_2 ,
} ;
V_2 -> V_176 = 1 ;
V_28 = F_90 ( V_132 , & V_170 , F_87 ) ;
} else {
V_186 = F_91 () ;
F_92 ( V_192 ) ;
V_28 = F_93 ( V_132 , (struct V_193 V_194 * ) V_183 , V_184 , & V_181 ) ;
F_92 ( V_186 ) ;
}
if ( V_28 >= 0 ) {
V_161 . V_195 += V_28 ;
* V_185 = V_28 ;
V_11 = 0 ;
F_94 ( V_132 ) ;
} else
V_11 = F_28 ( V_28 ) ;
return V_11 ;
}
static void F_95 ( struct V_3 * V_3 )
{
struct V_44 V_196 ;
V_196 . V_52 = V_79 | V_80 | V_75 ;
F_96 ( & V_3 -> V_21 -> V_197 ) ;
F_50 ( V_3 , & V_196 ) ;
F_97 ( & V_3 -> V_21 -> V_197 ) ;
}
static int F_98 ( struct V_132 * V_132 )
{
struct V_36 * V_36 = V_132 -> V_198 . V_3 -> V_21 ;
static T_8 V_199 ;
static T_7 V_200 ;
int V_11 = 0 ;
if ( F_99 ( & V_36 -> V_201 ) > 1
|| ( V_199 == V_36 -> V_202 && V_200 == V_36 -> V_42 -> V_203 ) ) {
F_22 ( L_2 , F_100 ( V_204 ) ) ;
F_101 ( 10 ) ;
F_22 ( L_3 , F_100 ( V_204 ) ) ;
}
if ( V_36 -> V_205 & V_206 ) {
F_22 ( L_4 , F_100 ( V_204 ) ) ;
V_11 = F_102 ( V_132 , 0 ) ;
}
V_199 = V_36 -> V_202 ;
V_200 = V_36 -> V_42 -> V_203 ;
return V_11 ;
}
static T_1
F_103 ( struct V_1 * V_2 , struct V_22 * V_23 , struct V_132 * V_132 ,
T_9 V_181 , struct V_182 * V_183 , int V_184 ,
unsigned long * V_207 , int * V_208 )
{
struct V_5 * exp ;
struct V_3 * V_3 ;
struct V_36 * V_36 ;
T_10 V_186 ;
T_1 V_11 = 0 ;
int V_28 ;
int V_209 = * V_208 ;
int V_210 ;
V_3 = V_132 -> V_198 . V_3 ;
V_36 = V_3 -> V_21 ;
exp = V_23 -> V_30 ;
V_210 = ( V_2 -> V_211 == 2 ) && F_104 ( exp ) ;
if ( ! V_132 -> V_187 -> V_212 ) {
V_209 = 2 ;
* V_208 = 2 ;
}
if ( ! F_37 ( exp ) )
V_209 = 0 ;
if ( V_209 && ! V_210 ) {
F_82 ( & V_132 -> V_213 ) ;
V_132 -> V_214 |= V_215 ;
F_83 ( & V_132 -> V_213 ) ;
}
V_186 = F_91 () ; F_92 ( V_192 ) ;
V_28 = F_105 ( V_132 , (struct V_193 V_194 * ) V_183 , V_184 , & V_181 ) ;
F_92 ( V_186 ) ;
if ( V_28 < 0 )
goto V_31;
* V_207 = V_28 ;
V_161 . V_216 += V_28 ;
F_106 ( V_132 ) ;
if ( V_36 -> V_37 & ( V_76 | V_78 ) )
F_95 ( V_3 ) ;
if ( V_209 && V_210 )
V_28 = F_98 ( V_132 ) ;
V_31:
F_22 ( L_5 , V_28 ) ;
if ( V_28 >= 0 )
V_11 = 0 ;
else
V_11 = F_28 ( V_28 ) ;
return V_11 ;
}
T_1 F_107 ( struct V_1 * V_2 , struct V_22 * V_23 ,
T_9 V_181 , struct V_182 * V_183 , int V_184 , unsigned long * V_185 )
{
struct V_132 * V_132 ;
struct V_36 * V_36 ;
struct V_142 * V_145 ;
T_1 V_11 ;
V_11 = F_71 ( V_2 , V_23 , V_58 , V_136 , & V_132 ) ;
if ( V_11 )
return V_11 ;
V_36 = V_132 -> V_198 . V_3 -> V_21 ;
V_145 = F_80 ( V_36 -> V_42 -> V_203 , V_36 -> V_202 ) ;
if ( V_145 && V_145 -> V_163 )
V_132 -> V_217 = V_145 -> V_218 ;
V_11 = F_89 ( V_2 , V_23 , V_132 , V_181 , V_183 , V_184 , V_185 ) ;
if ( V_145 ) {
struct V_150 * V_151 = & V_153 [ V_145 -> V_164 ] ;
F_82 ( & V_151 -> V_154 ) ;
V_145 -> V_218 = V_132 -> V_217 ;
V_145 -> V_163 = 1 ;
V_145 -> V_160 -- ;
F_83 ( & V_151 -> V_154 ) ;
}
F_78 ( V_132 ) ;
return V_11 ;
}
T_1
F_108 ( struct V_1 * V_2 , struct V_22 * V_23 , struct V_132 * V_132 ,
T_9 V_181 , struct V_182 * V_183 , int V_184 ,
unsigned long * V_185 )
{
T_1 V_11 ;
if ( V_132 ) {
V_11 = F_45 ( V_2 , V_23 -> V_30 , V_23 -> V_29 ,
V_136 | V_57 ) ;
if ( V_11 )
goto V_12;
V_11 = F_89 ( V_2 , V_23 , V_132 , V_181 , V_183 , V_184 , V_185 ) ;
} else
V_11 = F_107 ( V_2 , V_23 , V_181 , V_183 , V_184 , V_185 ) ;
V_12:
return V_11 ;
}
T_1
F_109 ( struct V_1 * V_2 , struct V_22 * V_23 , struct V_132 * V_132 ,
T_9 V_181 , struct V_182 * V_183 , int V_184 , unsigned long * V_207 ,
int * V_208 )
{
T_1 V_11 = 0 ;
if ( V_132 ) {
V_11 = F_45 ( V_2 , V_23 -> V_30 , V_23 -> V_29 ,
V_56 | V_57 ) ;
if ( V_11 )
goto V_12;
V_11 = F_103 ( V_2 , V_23 , V_132 , V_181 , V_183 , V_184 , V_207 ,
V_208 ) ;
} else {
V_11 = F_71 ( V_2 , V_23 , V_58 , V_56 , & V_132 ) ;
if ( V_11 )
goto V_12;
if ( V_207 )
V_11 = F_103 ( V_2 , V_23 , V_132 , V_181 , V_183 , V_184 ,
V_207 , V_208 ) ;
F_78 ( V_132 ) ;
}
V_12:
return V_11 ;
}
T_1
F_110 ( struct V_1 * V_2 , struct V_22 * V_23 ,
T_9 V_181 , unsigned long V_185 )
{
struct V_132 * V_132 ;
T_9 V_219 = V_220 ;
T_1 V_11 = V_221 ;
if ( V_181 < 0 )
goto V_12;
if ( V_185 != 0 ) {
V_219 = V_181 + ( T_9 ) V_185 - 1 ;
if ( V_219 < V_181 )
goto V_12;
}
V_11 = F_71 ( V_2 , V_23 , V_58 ,
V_56 | V_129 , & V_132 ) ;
if ( V_11 )
goto V_12;
if ( F_37 ( V_23 -> V_30 ) ) {
int V_122 = F_111 ( V_132 , V_181 , V_219 , 0 ) ;
if ( V_122 != - V_100 )
V_11 = F_28 ( V_122 ) ;
else
V_11 = V_222 ;
}
F_78 ( V_132 ) ;
V_12:
return V_11 ;
}
static T_1
F_112 ( struct V_1 * V_2 , struct V_22 * V_223 ,
struct V_44 * V_45 )
{
V_45 -> V_52 &= ~ V_59 ;
if ( F_113 () != 0 )
V_45 -> V_52 &= ~ ( V_69 | V_72 ) ;
if ( V_45 -> V_52 )
return F_39 ( V_2 , V_223 , V_45 , 0 , ( T_2 ) 0 ) ;
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
char * V_224 , int V_225 , struct V_44 * V_45 ,
int type , T_7 V_226 , struct V_22 * V_223 )
{
struct V_3 * V_3 , * V_227 = NULL ;
struct V_36 * V_228 ;
T_1 V_11 ;
T_1 V_122 ;
int V_28 ;
V_11 = V_127 ;
if ( ! V_225 )
goto V_12;
V_11 = V_229 ;
if ( F_25 ( V_224 , V_225 ) )
goto V_12;
V_11 = F_30 ( V_2 , V_23 , V_33 , V_230 ) ;
if ( V_11 )
goto V_12;
V_3 = V_23 -> V_29 ;
V_228 = V_3 -> V_21 ;
V_11 = V_231 ;
if ( ! V_228 -> V_232 -> V_233 )
goto V_12;
if ( ! V_223 -> V_29 ) {
V_28 = F_116 ( V_23 ) ;
if ( V_28 )
goto V_31;
F_117 ( V_23 , V_234 ) ;
V_227 = F_27 ( V_224 , V_3 , V_225 ) ;
V_28 = F_7 ( V_227 ) ;
if ( F_6 ( V_227 ) )
goto V_31;
V_11 = F_32 ( V_223 , V_23 -> V_30 , V_227 , V_23 ) ;
if ( V_11 )
goto V_12;
} else {
V_227 = F_3 ( V_223 -> V_29 ) ;
if ( ! V_23 -> V_235 ) {
F_118 ( V_236
L_6 ,
V_3 -> V_237 -> V_238 . V_24 ,
V_3 -> V_238 . V_24 ) ;
V_11 = V_239 ;
goto V_12;
}
}
V_11 = V_229 ;
if ( V_227 -> V_21 ) {
F_22 ( L_7 ,
V_3 -> V_238 . V_24 , V_227 -> V_238 . V_24 ) ;
goto V_12;
}
if ( ! ( V_45 -> V_52 & V_59 ) )
V_45 -> V_67 = 0 ;
V_45 -> V_67 = ( V_45 -> V_67 & V_68 ) | type ;
V_11 = V_221 ;
if ( ! F_34 ( type ) && ! F_49 ( type ) && ! F_119 ( type ) ) {
F_118 ( V_240 L_8 ,
type ) ;
goto V_12;
}
V_11 = 0 ;
V_28 = 0 ;
switch ( type ) {
case V_58 :
V_28 = F_120 ( V_228 , V_227 , V_45 -> V_67 , true ) ;
if ( ! V_28 )
F_114 ( V_45 ) ;
break;
case V_33 :
V_28 = F_121 ( V_228 , V_227 , V_45 -> V_67 ) ;
break;
case V_241 :
case V_242 :
case V_243 :
case V_244 :
V_28 = F_122 ( V_228 , V_227 , V_45 -> V_67 , V_226 ) ;
break;
}
if ( V_28 < 0 )
goto V_31;
V_11 = F_112 ( V_2 , V_223 , V_45 ) ;
V_122 = F_28 ( F_36 ( V_23 ) ) ;
if ( V_122 )
V_11 = V_122 ;
if ( ! V_11 )
V_11 = F_123 ( V_223 ) ;
V_12:
if ( V_227 && ! F_6 ( V_227 ) )
F_15 ( V_227 ) ;
return V_11 ;
V_31:
V_11 = F_28 ( V_28 ) ;
goto V_12;
}
static inline int F_124 ( int V_245 )
{
return V_245 == V_246
|| V_245 == V_247 ;
}
T_1
F_125 ( struct V_1 * V_2 , struct V_22 * V_23 ,
char * V_224 , int V_225 , struct V_44 * V_45 ,
struct V_22 * V_223 , int V_245 , T_6 * V_248 ,
bool * V_249 , bool * V_250 )
{
struct V_3 * V_3 , * V_227 = NULL ;
struct V_36 * V_228 ;
T_1 V_11 ;
int V_28 ;
T_11 V_251 = 0 , V_252 = 0 ;
V_11 = V_127 ;
if ( ! V_225 )
goto V_12;
V_11 = V_229 ;
if ( F_25 ( V_224 , V_225 ) )
goto V_12;
if ( ! ( V_45 -> V_52 & V_59 ) )
V_45 -> V_67 = 0 ;
V_11 = F_30 ( V_2 , V_23 , V_33 , V_34 ) ;
if ( V_11 )
goto V_12;
V_3 = V_23 -> V_29 ;
V_228 = V_3 -> V_21 ;
V_11 = V_231 ;
if ( ! V_228 -> V_232 -> V_233 )
goto V_12;
V_28 = F_116 ( V_23 ) ;
if ( V_28 )
goto V_31;
F_117 ( V_23 , V_234 ) ;
V_227 = F_27 ( V_224 , V_3 , V_225 ) ;
V_28 = F_7 ( V_227 ) ;
if ( F_6 ( V_227 ) )
goto V_31;
if ( ! V_227 -> V_21 ) {
V_11 = F_30 ( V_2 , V_23 , V_33 , V_230 ) ;
if ( V_11 )
goto V_12;
}
V_11 = F_32 ( V_223 , V_23 -> V_30 , V_227 , V_23 ) ;
if ( V_11 )
goto V_12;
if ( F_124 ( V_245 ) ) {
V_251 = V_248 [ 0 ] & 0x7fffffff ;
V_252 = V_248 [ 1 ] & 0x7fffffff ;
}
if ( V_227 -> V_21 ) {
V_11 = 0 ;
switch ( V_245 ) {
case V_253 :
if ( ! F_34 ( V_227 -> V_21 -> V_37 ) )
goto V_12;
else if ( V_249 ) {
* V_249 = ( V_45 -> V_52 & V_55 ) && ! V_45 -> V_64 ;
}
else {
V_45 -> V_52 &= V_55 ;
goto V_254;
}
break;
case V_246 :
if ( V_227 -> V_21 -> V_255 . V_61 == V_251
&& V_227 -> V_21 -> V_256 . V_61 == V_252
&& V_227 -> V_21 -> V_65 == 0 )
break;
case V_247 :
if ( V_227 -> V_21 -> V_255 . V_61 == V_251
&& V_227 -> V_21 -> V_256 . V_61 == V_252
&& V_227 -> V_21 -> V_65 == 0 )
goto V_254;
case V_257 :
V_11 = V_229 ;
}
F_126 ( V_23 ) ;
goto V_12;
}
V_28 = F_120 ( V_228 , V_227 , V_45 -> V_67 , true ) ;
if ( V_28 < 0 ) {
F_126 ( V_23 ) ;
goto V_31;
}
if ( V_250 )
* V_250 = 1 ;
F_114 ( V_45 ) ;
if ( F_124 ( V_245 ) ) {
V_45 -> V_52 = V_54 | V_53
| V_258 | V_259 ;
V_45 -> V_60 . V_61 = V_251 ;
V_45 -> V_62 . V_61 = V_252 ;
V_45 -> V_60 . V_260 = 0 ;
V_45 -> V_62 . V_260 = 0 ;
}
V_254:
V_11 = F_112 ( V_2 , V_223 , V_45 ) ;
if ( ! V_11 )
V_11 = F_28 ( F_36 ( V_23 ) ) ;
if ( ! V_11 )
V_11 = F_123 ( V_223 ) ;
V_12:
F_51 ( V_23 ) ;
if ( V_227 && ! F_6 ( V_227 ) )
F_15 ( V_227 ) ;
F_126 ( V_23 ) ;
return V_11 ;
V_31:
V_11 = F_28 ( V_28 ) ;
goto V_12;
}
T_1
F_127 ( struct V_1 * V_2 , struct V_22 * V_23 , char * V_85 , int * V_261 )
{
struct V_36 * V_36 ;
T_10 V_186 ;
T_1 V_11 ;
int V_28 ;
struct V_8 V_8 ;
V_11 = F_30 ( V_2 , V_23 , V_262 , V_118 ) ;
if ( V_11 )
goto V_12;
V_8 . V_9 = V_23 -> V_30 -> V_10 . V_9 ;
V_8 . V_3 = V_23 -> V_29 ;
V_36 = V_8 . V_3 -> V_21 ;
V_11 = V_221 ;
if ( ! V_36 -> V_232 -> V_263 )
goto V_12;
F_128 ( & V_8 ) ;
V_186 = F_91 () ; F_92 ( V_192 ) ;
V_28 = V_36 -> V_232 -> V_263 ( V_8 . V_3 , ( char V_194 * ) V_85 , * V_261 ) ;
F_92 ( V_186 ) ;
if ( V_28 < 0 )
goto V_31;
* V_261 = V_28 ;
V_11 = 0 ;
V_12:
return V_11 ;
V_31:
V_11 = F_28 ( V_28 ) ;
goto V_12;
}
T_1
F_129 ( struct V_1 * V_2 , struct V_22 * V_23 ,
char * V_224 , int V_225 ,
char * V_8 , int V_264 ,
struct V_22 * V_223 ,
struct V_44 * V_45 )
{
struct V_3 * V_3 , * V_265 ;
T_1 V_11 , V_266 ;
int V_28 ;
V_11 = V_35 ;
if ( ! V_225 || ! V_264 )
goto V_12;
V_11 = V_229 ;
if ( F_25 ( V_224 , V_225 ) )
goto V_12;
V_11 = F_30 ( V_2 , V_23 , V_33 , V_230 ) ;
if ( V_11 )
goto V_12;
V_28 = F_116 ( V_23 ) ;
if ( V_28 )
goto V_31;
F_26 ( V_23 ) ;
V_3 = V_23 -> V_29 ;
V_265 = F_27 ( V_224 , V_3 , V_225 ) ;
V_28 = F_7 ( V_265 ) ;
if ( F_6 ( V_265 ) )
goto V_31;
if ( F_130 ( V_8 [ V_264 ] != 0 ) ) {
char * V_267 = F_54 ( V_264 + 1 , V_88 ) ;
if ( V_267 == NULL )
V_28 = - V_89 ;
else {
strncpy ( V_267 , V_8 , V_264 ) ;
V_267 [ V_264 ] = 0 ;
V_28 = F_131 ( V_3 -> V_21 , V_265 , V_267 ) ;
F_55 ( V_267 ) ;
}
} else
V_28 = F_131 ( V_3 -> V_21 , V_265 , V_8 ) ;
V_11 = F_28 ( V_28 ) ;
if ( ! V_11 )
V_11 = F_28 ( F_36 ( V_23 ) ) ;
F_51 ( V_23 ) ;
F_126 ( V_23 ) ;
V_266 = F_32 ( V_223 , V_23 -> V_30 , V_265 , V_23 ) ;
F_15 ( V_265 ) ;
if ( V_11 == 0 ) V_11 = V_266 ;
V_12:
return V_11 ;
V_31:
V_11 = F_28 ( V_28 ) ;
goto V_12;
}
T_1
F_132 ( struct V_1 * V_2 , struct V_22 * V_268 ,
char * V_24 , int V_25 , struct V_22 * V_269 )
{
struct V_3 * V_270 , * V_265 , * V_271 ;
struct V_36 * V_228 ;
T_1 V_11 ;
int V_28 ;
V_11 = F_30 ( V_2 , V_268 , V_33 , V_230 ) ;
if ( V_11 )
goto V_12;
V_11 = F_30 ( V_2 , V_269 , 0 , V_118 ) ;
if ( V_11 )
goto V_12;
V_11 = V_272 ;
if ( F_49 ( V_269 -> V_29 -> V_21 -> V_37 ) )
goto V_12;
V_11 = V_127 ;
if ( ! V_25 )
goto V_12;
V_11 = V_229 ;
if ( F_25 ( V_24 , V_25 ) )
goto V_12;
V_28 = F_116 ( V_269 ) ;
if ( V_28 ) {
V_11 = F_28 ( V_28 ) ;
goto V_12;
}
F_117 ( V_268 , V_234 ) ;
V_270 = V_268 -> V_29 ;
V_228 = V_270 -> V_21 ;
V_265 = F_27 ( V_24 , V_270 , V_25 ) ;
V_28 = F_7 ( V_265 ) ;
if ( F_6 ( V_265 ) )
goto V_31;
V_271 = V_269 -> V_29 ;
V_11 = V_35 ;
if ( ! V_271 -> V_21 )
goto V_273;
V_28 = F_33 ( V_271 -> V_21 ) ;
if ( V_28 ) {
V_11 = F_28 ( V_28 ) ;
goto V_273;
}
V_28 = F_133 ( V_271 , V_228 , V_265 ) ;
if ( ! V_28 ) {
V_11 = F_28 ( F_36 ( V_268 ) ) ;
if ( ! V_11 )
V_11 = F_28 ( F_36 ( V_269 ) ) ;
} else {
if ( V_28 == - V_274 && V_2 -> V_211 == 2 )
V_11 = V_126 ;
else
V_11 = F_28 ( V_28 ) ;
}
V_273:
F_15 ( V_265 ) ;
V_275:
F_51 ( V_268 ) ;
F_126 ( V_269 ) ;
V_12:
return V_11 ;
V_31:
V_11 = F_28 ( V_28 ) ;
goto V_275;
}
T_1
F_134 ( struct V_1 * V_2 , struct V_22 * V_268 , char * V_224 , int V_225 ,
struct V_22 * V_269 , char * V_276 , int V_277 )
{
struct V_3 * V_278 , * V_279 , * V_280 , * V_281 , * V_282 ;
struct V_36 * V_283 , * V_284 ;
T_1 V_11 ;
int V_28 ;
V_11 = F_30 ( V_2 , V_268 , V_33 , V_285 ) ;
if ( V_11 )
goto V_12;
V_11 = F_30 ( V_2 , V_269 , V_33 , V_230 ) ;
if ( V_11 )
goto V_12;
V_278 = V_268 -> V_29 ;
V_283 = V_278 -> V_21 ;
V_279 = V_269 -> V_29 ;
V_284 = V_279 -> V_21 ;
V_11 = ( V_2 -> V_211 == 2 ) ? V_126 : V_286 ;
if ( V_268 -> V_30 != V_269 -> V_30 )
goto V_12;
V_11 = V_127 ;
if ( ! V_225 || F_25 ( V_224 , V_225 ) || ! V_277 || F_25 ( V_276 , V_277 ) )
goto V_12;
V_28 = F_116 ( V_268 ) ;
if ( V_28 ) {
V_11 = F_28 ( V_28 ) ;
goto V_12;
}
V_282 = F_135 ( V_279 , V_278 ) ;
V_268 -> V_235 = V_269 -> V_235 = 1 ;
F_136 ( V_268 ) ;
F_136 ( V_269 ) ;
V_280 = F_27 ( V_224 , V_278 , V_225 ) ;
V_28 = F_7 ( V_280 ) ;
if ( F_6 ( V_280 ) )
goto V_31;
V_28 = - V_13 ;
if ( ! V_280 -> V_21 )
goto V_287;
V_28 = - V_100 ;
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
if ( V_268 -> V_30 -> V_10 . V_9 != V_269 -> V_30 -> V_10 . V_9 )
goto V_289;
V_28 = F_33 ( V_280 -> V_21 ) ;
if ( V_28 )
goto V_289;
if ( V_281 -> V_21 ) {
V_28 = F_33 ( V_281 -> V_21 ) ;
if ( V_28 )
goto V_289;
}
V_28 = F_137 ( V_283 , V_280 , V_284 , V_281 ) ;
if ( ! V_28 ) {
V_28 = F_36 ( V_269 ) ;
if ( ! V_28 )
V_28 = F_36 ( V_268 ) ;
}
V_289:
F_15 ( V_281 ) ;
V_287:
F_15 ( V_280 ) ;
V_31:
V_11 = F_28 ( V_28 ) ;
F_138 ( V_268 ) ;
F_138 ( V_269 ) ;
F_139 ( V_279 , V_278 ) ;
V_268 -> V_235 = V_269 -> V_235 = 0 ;
F_126 ( V_268 ) ;
V_12:
return V_11 ;
}
T_1
F_140 ( struct V_1 * V_2 , struct V_22 * V_23 , int type ,
char * V_224 , int V_225 )
{
struct V_3 * V_3 , * V_290 ;
struct V_36 * V_228 ;
T_1 V_11 ;
int V_28 ;
V_11 = V_126 ;
if ( ! V_225 || F_25 ( V_224 , V_225 ) )
goto V_12;
V_11 = F_30 ( V_2 , V_23 , V_33 , V_285 ) ;
if ( V_11 )
goto V_12;
V_28 = F_116 ( V_23 ) ;
if ( V_28 )
goto V_31;
F_117 ( V_23 , V_234 ) ;
V_3 = V_23 -> V_29 ;
V_228 = V_3 -> V_21 ;
V_290 = F_27 ( V_224 , V_3 , V_225 ) ;
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
V_28 = F_33 ( V_290 -> V_21 ) ;
if ( V_28 )
goto V_292;
if ( type != V_33 )
V_28 = F_141 ( V_228 , V_290 ) ;
else
V_28 = F_142 ( V_228 , V_290 ) ;
if ( ! V_28 )
V_28 = F_36 ( V_23 ) ;
V_292:
F_15 ( V_290 ) ;
V_31:
V_11 = F_28 ( V_28 ) ;
V_12:
return V_11 ;
}
static int F_143 ( void * V_293 , const char * V_24 , int V_294 ,
T_9 V_181 , T_12 V_144 , unsigned int V_295 )
{
struct V_296 * V_85 = V_293 ;
struct V_297 * V_298 = ( void * ) ( V_85 -> V_299 + V_85 -> V_300 ) ;
unsigned int V_301 ;
V_301 = F_144 ( sizeof( struct V_297 ) + V_294 , sizeof( T_12 ) ) ;
if ( V_85 -> V_300 + V_301 > V_302 ) {
V_85 -> V_303 = 1 ;
return - V_100 ;
}
V_298 -> V_294 = V_294 ;
V_298 -> V_181 = V_181 ;
V_298 -> V_144 = V_144 ;
V_298 -> V_295 = V_295 ;
memcpy ( V_298 -> V_24 , V_24 , V_294 ) ;
V_85 -> V_300 += V_301 ;
return 0 ;
}
static T_1 F_145 ( struct V_132 * V_132 , T_13 V_304 ,
struct V_305 * V_306 , T_9 * V_307 )
{
struct V_296 V_85 ;
struct V_297 * V_298 ;
int V_28 ;
int V_177 ;
T_9 V_181 ;
V_85 . V_299 = ( void * ) F_146 ( V_88 ) ;
if ( ! V_85 . V_299 )
return F_28 ( - V_89 ) ;
V_181 = * V_307 ;
while ( 1 ) {
struct V_36 * V_308 = V_132 -> V_198 . V_3 -> V_21 ;
unsigned int V_301 ;
V_306 -> V_11 = V_309 ;
V_85 . V_300 = 0 ;
V_85 . V_303 = 0 ;
V_28 = F_147 ( V_132 , F_143 , & V_85 ) ;
if ( V_85 . V_303 )
V_28 = 0 ;
if ( V_28 < 0 )
break;
V_177 = V_85 . V_300 ;
if ( ! V_177 )
break;
V_28 = F_148 ( & V_308 -> V_197 ) ;
if ( V_28 )
break;
V_298 = (struct V_297 * ) V_85 . V_299 ;
while ( V_177 > 0 ) {
V_181 = V_298 -> V_181 ;
if ( V_304 ( V_306 , V_298 -> V_24 , V_298 -> V_294 , V_298 -> V_181 ,
V_298 -> V_144 , V_298 -> V_295 ) )
break;
if ( V_306 -> V_11 != V_124 )
break;
V_301 = F_144 ( sizeof( * V_298 ) + V_298 -> V_294 ,
sizeof( T_12 ) ) ;
V_177 -= V_301 ;
V_298 = (struct V_297 * ) ( ( char * ) V_298 + V_301 ) ;
}
F_97 ( & V_308 -> V_197 ) ;
if ( V_177 > 0 )
break;
V_181 = F_149 ( V_132 , 0 , V_310 ) ;
}
F_150 ( ( unsigned long ) ( V_85 . V_299 ) ) ;
if ( V_28 )
return F_28 ( V_28 ) ;
* V_307 = V_181 ;
return V_306 -> V_11 ;
}
T_1
F_151 ( struct V_1 * V_2 , struct V_22 * V_23 , T_9 * V_307 ,
struct V_305 * V_306 , T_13 V_304 )
{
T_1 V_11 ;
struct V_132 * V_132 ;
T_9 V_181 = * V_307 ;
int V_131 = V_136 ;
if ( V_2 -> V_211 > 2 )
V_131 |= V_138 ;
V_11 = F_71 ( V_2 , V_23 , V_33 , V_131 , & V_132 ) ;
if ( V_11 )
goto V_12;
V_181 = F_149 ( V_132 , V_181 , V_311 ) ;
if ( V_181 < 0 ) {
V_11 = F_28 ( ( int ) V_181 ) ;
goto V_312;
}
V_11 = F_145 ( V_132 , V_304 , V_306 , V_307 ) ;
if ( V_11 == V_309 || V_11 == V_313 )
V_11 = V_124 ;
V_312:
F_78 ( V_132 ) ;
V_12:
return V_11 ;
}
T_1
F_152 ( struct V_1 * V_2 , struct V_22 * V_23 , struct V_314 * V_315 , int V_110 )
{
T_1 V_11 ;
V_11 = F_30 ( V_2 , V_23 , 0 , V_118 | V_110 ) ;
if ( ! V_11 ) {
struct V_8 V_8 = {
. V_9 = V_23 -> V_30 -> V_10 . V_9 ,
. V_3 = V_23 -> V_29 ,
} ;
if ( F_153 ( & V_8 , V_315 ) )
V_11 = V_239 ;
}
return V_11 ;
}
static int F_154 ( struct V_1 * V_2 , struct V_5 * exp )
{
return F_155 ( V_2 , exp ) & V_316 ;
}
T_1
F_45 ( struct V_1 * V_2 , struct V_5 * exp ,
struct V_3 * V_3 , int V_317 )
{
struct V_36 * V_36 = V_3 -> V_21 ;
int V_11 ;
if ( ( V_317 & V_318 ) == V_118 )
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
if ( F_154 ( V_2 , exp ) ||
F_156 ( exp -> V_10 . V_9 ) )
return V_125 ;
if ( F_157 ( V_36 ) )
return V_127 ;
}
if ( ( V_317 & V_66 ) && F_73 ( V_36 ) )
return V_127 ;
if ( V_317 & V_320 ) {
if ( exp -> V_14 & V_321 )
return 0 ;
else
V_317 = V_136 | V_57 ;
}
if ( ( V_317 & V_57 ) &&
V_36 -> V_71 == F_113 () )
return 0 ;
V_11 = F_158 ( V_36 , V_317 & ( V_322 | V_323 | V_324 ) ) ;
if ( V_11 == - V_325 && F_34 ( V_36 -> V_37 ) &&
( V_317 == ( V_136 | V_57 ) ||
V_317 == ( V_136 | V_326 ) ) )
V_11 = F_158 ( V_36 , V_324 ) ;
return V_11 ? F_28 ( V_11 ) : 0 ;
}
void
F_159 ( void )
{
struct V_142 * V_327 , * V_328 ;
unsigned int V_329 ;
F_22 ( L_9 ) ;
for ( V_329 = 0 ; V_329 < V_330 ; V_329 ++ ) {
V_327 = V_153 [ V_329 ] . V_155 ;
while( V_327 ) {
V_328 = V_327 ;
V_327 = V_327 -> V_156 ;
F_55 ( V_328 ) ;
}
V_153 [ V_329 ] . V_155 = NULL ;
}
}
int
F_160 ( int V_331 )
{
int V_329 ;
int V_332 = 0 ;
int V_333 ;
struct V_142 * * V_327 = NULL ;
if ( V_153 [ 0 ] . V_155 )
return 0 ;
V_333 = F_161 ( V_331 , V_330 ) ;
if ( V_333 < 2 )
V_333 = 2 ;
V_331 = V_333 * V_330 ;
F_22 ( L_10 , V_331 ) ;
for ( V_329 = 0 ; V_329 < V_330 ; V_329 ++ ) {
F_162 ( & V_153 [ V_329 ] . V_154 ) ;
V_327 = & V_153 [ V_329 ] . V_155 ;
for ( V_332 = 0 ; V_332 < V_333 ; V_332 ++ ) {
* V_327 = F_163 ( sizeof( struct V_142 ) , V_88 ) ;
if ( ! * V_327 )
goto V_334;
V_327 = & ( * V_327 ) -> V_156 ;
}
* V_327 = NULL ;
}
V_161 . V_162 = V_331 ;
return 0 ;
V_334:
F_22 ( L_11 ) ;
F_159 () ;
return - V_89 ;
}
struct V_90 *
F_164 ( struct V_22 * V_23 , int type )
{
struct V_36 * V_36 = V_23 -> V_29 -> V_21 ;
char * V_24 ;
void * V_335 = NULL ;
T_4 V_177 ;
struct V_90 * V_95 ;
if ( ! F_165 ( V_36 ) )
return F_64 ( - V_105 ) ;
switch ( type ) {
case V_336 :
V_24 = V_102 ;
break;
case V_337 :
V_24 = V_104 ;
break;
default:
return F_64 ( - V_105 ) ;
}
V_177 = F_52 ( V_23 -> V_29 , V_24 , & V_335 ) ;
if ( V_177 < 0 )
return F_64 ( V_177 ) ;
V_95 = F_65 ( & V_93 , V_335 , V_177 ) ;
F_55 ( V_335 ) ;
return V_95 ;
}
int
F_166 ( struct V_22 * V_23 , int type , struct V_90 * V_95 )
{
struct V_36 * V_36 = V_23 -> V_29 -> V_21 ;
char * V_24 ;
void * V_335 = NULL ;
T_5 V_177 ;
int error ;
if ( ! F_165 ( V_36 ) ||
! V_36 -> V_232 -> V_338 || ! V_36 -> V_232 -> V_339 )
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
V_177 = F_57 ( V_95 -> V_92 ) ;
V_335 = F_54 ( V_177 , V_88 ) ;
if ( ! V_335 )
return - V_89 ;
error = F_58 ( & V_93 , V_95 , V_335 , V_177 ) ;
if ( error < 0 )
goto V_340;
V_177 = error ;
} else
V_177 = 0 ;
error = F_116 ( V_23 ) ;
if ( error )
goto V_340;
if ( V_177 )
error = F_59 ( V_23 -> V_29 , V_24 , V_335 , V_177 , 0 ) ;
else {
if ( ! F_49 ( V_36 -> V_37 ) && type == V_337 )
error = 0 ;
else {
error = F_167 ( V_23 -> V_29 , V_24 ) ;
if ( error == - V_106 )
error = 0 ;
}
}
F_126 ( V_23 ) ;
V_340:
F_55 ( V_335 ) ;
return error ;
}

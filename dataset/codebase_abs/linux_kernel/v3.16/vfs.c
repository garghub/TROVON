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
F_26 ( V_23 , V_32 ) ;
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
unsigned int V_25 , struct V_22 * V_33 )
{
struct V_5 * exp ;
struct V_3 * V_3 ;
T_1 V_11 ;
V_11 = F_30 ( V_2 , V_23 , V_34 , V_35 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_21 ( V_2 , V_23 , V_24 , V_25 , & exp , & V_3 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_31 ( exp , V_2 ) ;
if ( V_11 )
goto V_12;
V_11 = F_32 ( V_33 , exp , V_3 , V_23 ) ;
if ( ! V_11 && ! V_3 -> V_21 )
V_11 = V_36 ;
V_12:
F_15 ( V_3 ) ;
F_11 ( exp ) ;
return V_11 ;
}
static int
F_33 ( struct V_22 * V_23 )
{
struct V_37 * V_37 = V_23 -> V_29 -> V_21 ;
const struct V_38 * V_39 = V_37 -> V_40 -> V_41 ;
if ( ! F_34 ( V_23 -> V_30 ) )
return 0 ;
if ( V_39 -> F_33 )
return V_39 -> F_33 ( V_37 ) ;
return F_35 ( V_37 , 1 ) ;
}
static void
F_36 ( struct V_37 * V_37 , struct V_42 * V_43 )
{
#define F_37 (ATTR_ATIME_SET | ATTR_MTIME_SET)
#define F_38 (30*60)
if ( ( V_43 -> V_44 & F_37 ) == F_37 &&
V_43 -> V_45 . V_46 == V_43 -> V_47 . V_46 ) {
T_2 V_48 = V_43 -> V_47 . V_46 - F_39 () ;
if ( V_48 < 0 )
V_48 = - V_48 ;
if ( V_48 < F_38 &&
F_40 ( V_37 , V_43 ) != 0 ) {
V_43 -> V_44 &= ~ F_37 ;
}
}
if ( V_43 -> V_44 & V_49 ) {
V_43 -> V_50 &= V_51 ;
V_43 -> V_50 |= ( V_37 -> V_52 & ~ V_51 ) ;
}
if ( ! F_41 ( V_37 -> V_52 ) &&
( ( V_43 -> V_44 & V_53 ) || ( V_43 -> V_44 & V_54 ) ) ) {
V_43 -> V_44 |= V_55 ;
if ( V_43 -> V_44 & V_49 ) {
V_43 -> V_50 &= ~ V_56 ;
if ( V_43 -> V_50 & V_57 )
V_43 -> V_50 &= ~ V_58 ;
} else {
V_43 -> V_44 |= ( V_59 | V_60 ) ;
}
}
}
static T_1
F_42 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_42 * V_43 )
{
struct V_37 * V_37 = V_23 -> V_29 -> V_21 ;
int V_28 ;
if ( V_43 -> V_61 < V_37 -> V_62 ) {
T_1 V_11 ;
V_11 = F_43 ( V_2 , V_23 -> V_30 , V_23 -> V_29 ,
V_63 | V_64 ) ;
if ( V_11 )
return V_11 ;
}
V_28 = F_44 ( V_37 ) ;
if ( V_28 )
goto V_65;
V_28 = F_45 ( V_37 , NULL , V_43 -> V_61 ) ;
if ( V_28 )
goto V_66;
return 0 ;
V_66:
F_46 ( V_37 ) ;
V_65:
return F_28 ( V_28 ) ;
}
T_1
F_47 ( struct V_1 * V_2 , struct V_22 * V_23 , struct V_42 * V_43 ,
int V_67 , T_2 V_68 )
{
struct V_3 * V_3 ;
struct V_37 * V_37 ;
int V_69 = V_70 ;
T_3 V_71 = 0 ;
T_1 V_11 ;
int V_28 ;
bool V_72 ;
int V_73 = 0 ;
if ( V_43 -> V_44 & ( V_74 | V_75 | V_76 ) )
V_69 |= V_77 | V_64 ;
if ( V_43 -> V_44 & V_76 )
V_71 = V_78 ;
V_72 = ! V_23 -> V_29 ;
V_11 = F_30 ( V_2 , V_23 , V_71 , V_69 ) ;
if ( V_11 )
goto V_12;
if ( V_72 ) {
V_28 = F_48 ( V_23 ) ;
if ( V_28 )
return F_28 ( V_28 ) ;
}
V_3 = V_23 -> V_29 ;
V_37 = V_3 -> V_21 ;
if ( F_49 ( V_37 -> V_52 ) )
V_43 -> V_44 &= ~ V_49 ;
if ( ! V_43 -> V_44 )
goto V_12;
F_36 ( V_37 , V_43 ) ;
if ( V_43 -> V_44 & V_76 ) {
V_11 = F_42 ( V_2 , V_23 , V_43 ) ;
if ( V_11 )
goto V_12;
V_73 = 1 ;
}
V_43 -> V_44 |= V_79 ;
if ( V_67 && V_68 != V_37 -> V_80 . V_46 ) {
V_11 = V_81 ;
goto V_66;
}
F_50 ( V_23 ) ;
V_28 = F_51 ( V_3 , V_43 , NULL ) ;
F_52 ( V_23 ) ;
V_11 = F_28 ( V_28 ) ;
V_66:
if ( V_73 )
F_46 ( V_37 ) ;
if ( ! V_11 )
F_33 ( V_23 ) ;
V_12:
return V_11 ;
}
int F_20 ( struct V_3 * V_3 )
{
struct V_37 * V_37 = V_3 -> V_21 ;
if ( V_37 == NULL )
return 0 ;
if ( V_37 -> V_52 & V_82 )
return 0 ;
if ( ! ( V_37 -> V_52 & V_83 ) )
return 0 ;
if ( F_53 ( V_3 , V_84 , NULL , 0 ) <= 0 )
return 0 ;
return 1 ;
}
T_1 F_54 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_85 * V_86 )
{
T_1 error ;
int V_87 ;
struct V_3 * V_3 ;
error = F_30 ( V_2 , V_23 , 0 , V_70 ) ;
if ( error )
return error ;
V_3 = V_23 -> V_29 ;
F_55 ( & V_3 -> V_21 -> V_88 ) ;
V_87 = F_56 ( V_3 , V_86 -> V_89 , V_86 -> V_25 ) ;
F_57 ( & V_3 -> V_21 -> V_88 ) ;
return F_28 ( V_87 ) ;
}
T_1 F_54 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_85 * V_86 )
{
return V_90 ;
}
T_1
F_58 ( struct V_1 * V_2 , struct V_22 * V_23 , T_4 * V_91 , T_4 * V_92 )
{
struct V_93 * V_94 ;
struct V_5 * V_95 ;
struct V_3 * V_3 ;
T_4 V_96 , V_97 = 0 , V_98 = 0 ;
T_1 error ;
error = F_30 ( V_2 , V_23 , 0 , V_99 ) ;
if ( error )
goto V_12;
V_95 = V_23 -> V_30 ;
V_3 = V_23 -> V_29 ;
if ( F_59 ( V_3 -> V_21 -> V_52 ) )
V_94 = V_100 ;
else if ( F_41 ( V_3 -> V_21 -> V_52 ) )
V_94 = V_101 ;
else
V_94 = V_102 ;
V_96 = * V_91 ;
for (; V_94 -> V_91 ; V_94 ++ ) {
if ( V_94 -> V_91 & V_96 ) {
T_1 V_103 ;
V_98 |= V_94 -> V_91 ;
V_103 = F_43 ( V_2 , V_95 , V_3 , V_94 -> V_104 ) ;
switch ( V_103 ) {
case V_105 :
V_97 |= V_94 -> V_91 ;
break;
case V_106 :
case V_107 :
case V_108 :
break;
default:
error = V_103 ;
goto V_12;
}
}
}
* V_91 = V_97 ;
if ( V_92 )
* V_92 = V_98 ;
V_12:
return error ;
}
static int F_60 ( struct V_37 * V_37 , int V_91 )
{
unsigned int V_109 ;
if ( V_91 & V_110 )
return 0 ;
V_109 = ( V_91 & V_77 ) ? V_111 : V_112 ;
return F_61 ( V_37 , V_109 | V_113 ) ;
}
T_1
F_62 ( struct V_1 * V_2 , struct V_22 * V_23 , T_3 type ,
int V_114 , struct V_115 * * V_116 )
{
struct V_8 V_8 ;
struct V_37 * V_37 ;
int V_117 = V_112 | V_118 ;
T_1 V_11 ;
int V_28 = 0 ;
F_63 () ;
if ( type == V_78 )
V_114 |= V_64 ;
V_11 = F_30 ( V_2 , V_23 , type , V_114 ) ;
if ( V_11 )
goto V_12;
V_8 . V_9 = V_23 -> V_30 -> V_10 . V_9 ;
V_8 . V_3 = V_23 -> V_29 ;
V_37 = V_8 . V_3 -> V_21 ;
V_11 = V_108 ;
if ( F_64 ( V_37 ) && ( V_114 & V_77 ) )
goto V_12;
if ( F_59 ( ( V_37 ) -> V_52 ) && F_65 ( V_37 ) )
goto V_12;
if ( ! V_37 -> V_119 )
goto V_12;
V_28 = F_60 ( V_37 , V_114 ) ;
if ( V_28 )
goto V_31;
if ( V_114 & V_77 ) {
if ( V_114 & V_120 )
V_117 = V_121 | V_118 ;
else
V_117 = V_111 | V_118 ;
}
* V_116 = F_66 ( & V_8 , V_117 , F_67 () ) ;
if ( F_6 ( * V_116 ) ) {
V_28 = F_7 ( * V_116 ) ;
* V_116 = NULL ;
} else {
V_28 = F_68 ( * V_116 , V_114 ) ;
if ( V_114 & V_122 )
( * V_116 ) -> V_123 |= V_124 ;
else
( * V_116 ) -> V_123 |= V_125 ;
}
V_31:
V_11 = F_28 ( V_28 ) ;
V_12:
F_63 () ;
return V_11 ;
}
void
F_69 ( struct V_115 * V_116 )
{
F_70 ( V_116 ) ;
}
static inline struct V_126 *
F_71 ( T_5 V_127 , T_6 V_128 )
{
struct V_126 * V_129 , * * V_130 , * * V_131 = NULL ;
int V_132 = 0 ;
unsigned int V_133 ;
struct V_134 * V_135 ;
V_133 = F_72 ( V_127 , V_128 , 0xfeedbeef ) & V_136 ;
V_135 = & V_137 [ V_133 ] ;
F_73 ( & V_135 -> V_138 ) ;
for ( V_130 = & V_135 -> V_139 ; ( V_129 = * V_130 ) ; V_130 = & V_129 -> V_140 ) {
if ( V_129 -> V_141 == V_128 && V_129 -> V_142 == V_127 )
goto V_143;
V_132 ++ ;
if ( V_129 -> V_144 == 0 )
V_131 = V_130 ;
}
V_132 = V_145 . V_146 ;
if ( ! V_131 ) {
F_74 ( & V_135 -> V_138 ) ;
return NULL ;
}
V_130 = V_131 ;
V_129 = * V_131 ;
V_129 -> V_142 = V_127 ;
V_129 -> V_141 = V_128 ;
V_129 -> V_147 = 0 ;
V_129 -> V_148 = V_133 ;
V_143:
if ( V_130 != & V_135 -> V_139 ) {
* V_130 = V_129 -> V_140 ;
V_129 -> V_140 = V_135 -> V_139 ;
V_135 -> V_139 = V_129 ;
}
V_129 -> V_144 ++ ;
V_145 . V_149 [ V_132 * 10 / V_145 . V_146 ] ++ ;
F_74 ( & V_135 -> V_138 ) ;
return V_129 ;
}
static int
F_75 ( struct V_150 * V_151 , struct V_152 * V_153 ,
struct V_154 * V_155 )
{
struct V_1 * V_2 = V_155 -> V_156 . V_89 ;
struct V_157 * * V_158 = V_2 -> V_159 ;
struct V_157 * V_157 = V_153 -> V_157 ;
T_7 V_160 ;
V_160 = V_155 -> V_25 ;
if ( V_2 -> V_161 . V_162 == 0 ) {
F_76 ( V_157 ) ;
F_77 ( * V_2 -> V_159 ) ;
* ( V_2 -> V_159 ++ ) = V_157 ;
V_2 -> V_161 . V_163 = V_153 -> V_164 ;
V_2 -> V_161 . V_162 = V_160 ;
} else if ( V_157 != V_158 [ - 1 ] ) {
F_76 ( V_157 ) ;
if ( * V_2 -> V_159 )
F_77 ( * V_2 -> V_159 ) ;
* ( V_2 -> V_159 ++ ) = V_157 ;
V_2 -> V_161 . V_162 += V_160 ;
} else
V_2 -> V_161 . V_162 += V_160 ;
return V_160 ;
}
static int F_78 ( struct V_150 * V_151 ,
struct V_154 * V_155 )
{
return F_79 ( V_151 , V_155 , F_75 ) ;
}
T_1 F_80 ( struct V_115 * V_115 , unsigned long * V_165 , int V_28 )
{
if ( V_28 >= 0 ) {
V_145 . V_166 += V_28 ;
* V_165 = V_28 ;
F_81 ( V_115 ) ;
return 0 ;
} else
return F_28 ( V_28 ) ;
}
int F_82 ( struct V_1 * V_2 ,
struct V_115 * V_115 , T_8 V_164 , unsigned long * V_165 )
{
struct V_154 V_155 = {
. V_25 = 0 ,
. V_167 = * V_165 ,
. V_168 = V_164 ,
. V_156 . V_89 = V_2 ,
} ;
int V_28 ;
V_2 -> V_159 = V_2 -> V_169 + 1 ;
V_28 = F_83 ( V_115 , & V_155 , F_78 ) ;
return F_80 ( V_115 , V_165 , V_28 ) ;
}
int F_84 ( struct V_115 * V_115 , T_8 V_164 , struct V_170 * V_171 , int V_172 ,
unsigned long * V_165 )
{
T_9 V_173 ;
int V_28 ;
V_173 = F_85 () ;
F_86 ( V_174 ) ;
V_28 = F_87 ( V_115 , (struct V_175 V_176 * ) V_171 , V_172 , & V_164 ) ;
F_86 ( V_173 ) ;
return F_80 ( V_115 , V_165 , V_28 ) ;
}
static T_1
F_88 ( struct V_1 * V_2 , struct V_115 * V_115 ,
T_8 V_164 , struct V_170 * V_171 , int V_172 , unsigned long * V_165 )
{
if ( V_115 -> V_177 -> V_178 && V_2 -> V_179 )
return F_82 ( V_2 , V_115 , V_164 , V_165 ) ;
else
return F_84 ( V_115 , V_164 , V_171 , V_172 , V_165 ) ;
}
static int F_89 ( struct V_115 * V_115 )
{
struct V_37 * V_37 = F_90 ( V_115 ) ;
static T_6 V_180 ;
static T_5 V_181 ;
int V_11 = 0 ;
if ( F_91 ( & V_37 -> V_182 ) > 1
|| ( V_180 == V_37 -> V_183 && V_181 == V_37 -> V_40 -> V_184 ) ) {
F_22 ( L_2 , F_92 ( V_185 ) ) ;
F_93 ( 10 ) ;
F_22 ( L_3 , F_92 ( V_185 ) ) ;
}
if ( V_37 -> V_186 & V_187 ) {
F_22 ( L_4 , F_92 ( V_185 ) ) ;
V_11 = F_94 ( V_115 , 0 ) ;
}
V_180 = V_37 -> V_183 ;
V_181 = V_37 -> V_40 -> V_184 ;
return V_11 ;
}
static T_1
F_95 ( struct V_1 * V_2 , struct V_22 * V_23 , struct V_115 * V_115 ,
T_8 V_164 , struct V_170 * V_171 , int V_172 ,
unsigned long * V_188 , int * V_189 )
{
struct V_5 * exp ;
struct V_3 * V_3 ;
struct V_37 * V_37 ;
T_9 V_173 ;
T_1 V_11 = 0 ;
int V_28 ;
int V_190 = * V_189 ;
int V_191 ;
T_8 V_168 = V_164 ;
unsigned int V_192 = V_185 -> V_117 ;
if ( V_2 -> V_193 )
V_185 -> V_117 |= V_194 ;
V_3 = V_115 -> V_195 . V_3 ;
V_37 = V_3 -> V_21 ;
exp = V_23 -> V_30 ;
V_191 = ( V_2 -> V_196 == 2 ) && F_96 ( exp ) ;
if ( ! F_34 ( exp ) )
V_190 = 0 ;
V_173 = F_85 () ; F_86 ( V_174 ) ;
V_28 = F_97 ( V_115 , (struct V_175 V_176 * ) V_171 , V_172 , & V_168 ) ;
F_86 ( V_173 ) ;
if ( V_28 < 0 )
goto V_31;
* V_188 = V_28 ;
V_145 . V_197 += V_28 ;
F_98 ( V_115 ) ;
if ( V_190 ) {
if ( V_191 )
V_28 = F_89 ( V_115 ) ;
else
V_28 = F_99 ( V_115 , V_164 , V_164 + * V_188 , 0 ) ;
}
V_31:
F_22 ( L_5 , V_28 ) ;
if ( V_28 >= 0 )
V_11 = 0 ;
else
V_11 = F_28 ( V_28 ) ;
if ( V_2 -> V_193 )
F_100 ( V_185 , V_192 , V_194 ) ;
return V_11 ;
}
T_1 F_101 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_115 * * V_115 , struct V_126 * * V_129 )
{
struct V_37 * V_37 ;
T_1 V_11 ;
V_11 = F_62 ( V_2 , V_23 , V_78 , V_120 , V_115 ) ;
if ( V_11 )
return V_11 ;
V_37 = F_90 ( * V_115 ) ;
* V_129 = F_71 ( V_37 -> V_40 -> V_184 , V_37 -> V_183 ) ;
if ( * V_129 && ( * V_129 ) -> V_147 )
( * V_115 ) -> V_198 = ( * V_129 ) -> V_199 ;
return V_105 ;
}
void F_102 ( struct V_115 * V_115 , struct V_126 * V_129 )
{
if ( V_129 ) {
struct V_134 * V_135 = & V_137 [ V_129 -> V_148 ] ;
F_73 ( & V_135 -> V_138 ) ;
V_129 -> V_199 = V_115 -> V_198 ;
V_129 -> V_147 = 1 ;
V_129 -> V_144 -- ;
F_74 ( & V_135 -> V_138 ) ;
}
F_69 ( V_115 ) ;
}
T_1 F_103 ( struct V_1 * V_2 , struct V_22 * V_23 ,
T_8 V_164 , struct V_170 * V_171 , int V_172 , unsigned long * V_165 )
{
struct V_115 * V_115 ;
struct V_126 * V_129 ;
T_1 V_11 ;
V_11 = F_101 ( V_2 , V_23 , & V_115 , & V_129 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_88 ( V_2 , V_115 , V_164 , V_171 , V_172 , V_165 ) ;
F_102 ( V_115 , V_129 ) ;
return V_11 ;
}
T_1
F_104 ( struct V_1 * V_2 , struct V_22 * V_23 , struct V_115 * V_115 ,
T_8 V_164 , struct V_170 * V_171 , int V_172 , unsigned long * V_188 ,
int * V_189 )
{
T_1 V_11 = 0 ;
if ( V_115 ) {
V_11 = F_43 ( V_2 , V_23 -> V_30 , V_23 -> V_29 ,
V_77 | V_64 ) ;
if ( V_11 )
goto V_12;
V_11 = F_95 ( V_2 , V_23 , V_115 , V_164 , V_171 , V_172 , V_188 ,
V_189 ) ;
} else {
V_11 = F_62 ( V_2 , V_23 , V_78 , V_77 , & V_115 ) ;
if ( V_11 )
goto V_12;
if ( V_188 )
V_11 = F_95 ( V_2 , V_23 , V_115 , V_164 , V_171 , V_172 ,
V_188 , V_189 ) ;
F_69 ( V_115 ) ;
}
V_12:
return V_11 ;
}
T_1
F_105 ( struct V_1 * V_2 , struct V_22 * V_23 ,
T_8 V_164 , unsigned long V_165 )
{
struct V_115 * V_115 ;
T_8 V_200 = V_201 ;
T_1 V_11 = V_202 ;
if ( V_164 < 0 )
goto V_12;
if ( V_165 != 0 ) {
V_200 = V_164 + ( T_8 ) V_165 - 1 ;
if ( V_200 < V_164 )
goto V_12;
}
V_11 = F_62 ( V_2 , V_23 , V_78 ,
V_77 | V_110 , & V_115 ) ;
if ( V_11 )
goto V_12;
if ( F_34 ( V_23 -> V_30 ) ) {
int V_103 = F_99 ( V_115 , V_164 , V_200 , 0 ) ;
if ( V_103 != - V_203 )
V_11 = F_28 ( V_103 ) ;
else
V_11 = V_90 ;
}
F_69 ( V_115 ) ;
V_12:
return V_11 ;
}
static T_1
F_106 ( struct V_1 * V_2 , struct V_22 * V_204 ,
struct V_42 * V_43 )
{
V_43 -> V_44 &= ~ V_49 ;
if ( ! F_107 ( F_108 () , V_205 ) )
V_43 -> V_44 &= ~ ( V_53 | V_54 ) ;
if ( V_43 -> V_44 )
return F_47 ( V_2 , V_204 , V_43 , 0 , ( T_2 ) 0 ) ;
return 0 ;
}
static void
F_109 ( struct V_42 * V_43 )
{
if ( ( V_43 -> V_44 & V_76 ) && ( V_43 -> V_61 == 0 ) )
V_43 -> V_44 &= ~ V_76 ;
}
T_1
F_110 ( struct V_1 * V_2 , struct V_22 * V_23 ,
char * V_206 , int V_207 , struct V_42 * V_43 ,
int type , T_5 V_208 , struct V_22 * V_204 )
{
struct V_3 * V_3 , * V_209 = NULL ;
struct V_37 * V_210 ;
T_1 V_11 ;
T_1 V_103 ;
int V_28 ;
V_11 = V_108 ;
if ( ! V_207 )
goto V_12;
V_11 = V_211 ;
if ( F_25 ( V_206 , V_207 ) )
goto V_12;
V_11 = F_30 ( V_2 , V_23 , V_34 , V_212 ) ;
if ( V_11 )
goto V_12;
V_3 = V_23 -> V_29 ;
V_210 = V_3 -> V_21 ;
V_11 = V_213 ;
if ( ! V_210 -> V_214 -> V_215 )
goto V_12;
if ( ! V_204 -> V_29 ) {
V_28 = F_48 ( V_23 ) ;
if ( V_28 )
goto V_31;
F_26 ( V_23 , V_32 ) ;
V_209 = F_27 ( V_206 , V_3 , V_207 ) ;
V_28 = F_7 ( V_209 ) ;
if ( F_6 ( V_209 ) )
goto V_31;
V_11 = F_32 ( V_204 , V_23 -> V_30 , V_209 , V_23 ) ;
if ( V_11 )
goto V_12;
} else {
V_209 = F_3 ( V_204 -> V_29 ) ;
if ( ! V_23 -> V_216 ) {
F_111 ( V_217
L_6 ,
V_3 ) ;
V_11 = V_218 ;
goto V_12;
}
}
V_11 = V_211 ;
if ( V_209 -> V_21 ) {
F_22 ( L_7 ,
V_3 , V_209 ) ;
goto V_12;
}
if ( ! ( V_43 -> V_44 & V_49 ) )
V_43 -> V_50 = 0 ;
V_43 -> V_50 = ( V_43 -> V_50 & V_51 ) | type ;
V_11 = V_202 ;
if ( ! F_59 ( type ) && ! F_41 ( type ) && ! F_112 ( type ) ) {
F_111 ( V_219 L_8 ,
type ) ;
goto V_12;
}
V_11 = 0 ;
V_28 = 0 ;
switch ( type ) {
case V_78 :
V_28 = F_113 ( V_210 , V_209 , V_43 -> V_50 , true ) ;
if ( ! V_28 )
F_109 ( V_43 ) ;
break;
case V_34 :
V_28 = F_114 ( V_210 , V_209 , V_43 -> V_50 ) ;
break;
case V_220 :
case V_221 :
case V_222 :
case V_223 :
V_28 = F_115 ( V_210 , V_209 , V_43 -> V_50 , V_208 ) ;
break;
}
if ( V_28 < 0 )
goto V_31;
V_11 = F_106 ( V_2 , V_204 , V_43 ) ;
V_103 = F_28 ( F_33 ( V_23 ) ) ;
if ( V_103 )
V_11 = V_103 ;
if ( ! V_11 )
V_11 = F_116 ( V_204 ) ;
V_12:
if ( V_209 && ! F_6 ( V_209 ) )
F_15 ( V_209 ) ;
return V_11 ;
V_31:
V_11 = F_28 ( V_28 ) ;
goto V_12;
}
static inline int F_117 ( int V_224 )
{
return V_224 == V_225
|| V_224 == V_226 ;
}
T_1
F_118 ( struct V_1 * V_2 , struct V_22 * V_23 ,
char * V_206 , int V_207 , struct V_42 * V_43 ,
struct V_22 * V_204 , int V_224 , T_4 * V_227 ,
bool * V_228 , bool * V_229 )
{
struct V_3 * V_3 , * V_209 = NULL ;
struct V_37 * V_210 ;
T_1 V_11 ;
int V_28 ;
T_10 V_230 = 0 , V_231 = 0 ;
V_11 = V_108 ;
if ( ! V_207 )
goto V_12;
V_11 = V_211 ;
if ( F_25 ( V_206 , V_207 ) )
goto V_12;
if ( ! ( V_43 -> V_44 & V_49 ) )
V_43 -> V_50 = 0 ;
V_11 = F_30 ( V_2 , V_23 , V_34 , V_35 ) ;
if ( V_11 )
goto V_12;
V_3 = V_23 -> V_29 ;
V_210 = V_3 -> V_21 ;
V_11 = V_213 ;
if ( ! V_210 -> V_214 -> V_215 )
goto V_12;
V_28 = F_48 ( V_23 ) ;
if ( V_28 )
goto V_31;
F_26 ( V_23 , V_32 ) ;
V_209 = F_27 ( V_206 , V_3 , V_207 ) ;
V_28 = F_7 ( V_209 ) ;
if ( F_6 ( V_209 ) )
goto V_31;
if ( ! V_209 -> V_21 ) {
V_11 = F_30 ( V_2 , V_23 , V_34 , V_212 ) ;
if ( V_11 )
goto V_12;
}
V_11 = F_32 ( V_204 , V_23 -> V_30 , V_209 , V_23 ) ;
if ( V_11 )
goto V_12;
if ( F_117 ( V_224 ) ) {
V_230 = V_227 [ 0 ] & 0x7fffffff ;
V_231 = V_227 [ 1 ] & 0x7fffffff ;
}
if ( V_209 -> V_21 ) {
V_11 = 0 ;
switch ( V_224 ) {
case V_232 :
if ( ! F_59 ( V_209 -> V_21 -> V_52 ) )
goto V_12;
else if ( V_228 ) {
* V_228 = ( V_43 -> V_44 & V_76 ) && ! V_43 -> V_61 ;
}
else {
V_43 -> V_44 &= V_76 ;
goto V_233;
}
break;
case V_225 :
if ( V_209 -> V_21 -> V_234 . V_46 == V_230
&& V_209 -> V_21 -> V_235 . V_46 == V_231
&& V_209 -> V_21 -> V_62 == 0 ) {
if ( V_229 )
* V_229 = 1 ;
break;
}
case V_226 :
if ( V_209 -> V_21 -> V_234 . V_46 == V_230
&& V_209 -> V_21 -> V_235 . V_46 == V_231
&& V_209 -> V_21 -> V_62 == 0 ) {
if ( V_229 )
* V_229 = 1 ;
goto V_233;
}
case V_236 :
V_11 = V_211 ;
}
F_119 ( V_23 ) ;
goto V_12;
}
V_28 = F_113 ( V_210 , V_209 , V_43 -> V_50 , true ) ;
if ( V_28 < 0 ) {
F_119 ( V_23 ) ;
goto V_31;
}
if ( V_229 )
* V_229 = 1 ;
F_109 ( V_43 ) ;
if ( F_117 ( V_224 ) ) {
V_43 -> V_44 = V_75 | V_74
| V_237 | V_238 ;
V_43 -> V_45 . V_46 = V_230 ;
V_43 -> V_47 . V_46 = V_231 ;
V_43 -> V_45 . V_239 = 0 ;
V_43 -> V_47 . V_239 = 0 ;
}
V_233:
V_11 = F_106 ( V_2 , V_204 , V_43 ) ;
if ( ! V_11 )
V_11 = F_28 ( F_33 ( V_23 ) ) ;
if ( ! V_11 )
V_11 = F_116 ( V_204 ) ;
V_12:
F_52 ( V_23 ) ;
if ( V_209 && ! F_6 ( V_209 ) )
F_15 ( V_209 ) ;
F_119 ( V_23 ) ;
return V_11 ;
V_31:
V_11 = F_28 ( V_28 ) ;
goto V_12;
}
T_1
F_120 ( struct V_1 * V_2 , struct V_22 * V_23 , char * V_153 , int * V_240 )
{
struct V_37 * V_37 ;
T_9 V_173 ;
T_1 V_11 ;
int V_28 ;
struct V_8 V_8 ;
V_11 = F_30 ( V_2 , V_23 , V_241 , V_99 ) ;
if ( V_11 )
goto V_12;
V_8 . V_9 = V_23 -> V_30 -> V_10 . V_9 ;
V_8 . V_3 = V_23 -> V_29 ;
V_37 = V_8 . V_3 -> V_21 ;
V_11 = V_202 ;
if ( ! V_37 -> V_214 -> V_242 )
goto V_12;
F_121 ( & V_8 ) ;
V_173 = F_85 () ; F_86 ( V_174 ) ;
V_28 = V_37 -> V_214 -> V_242 ( V_8 . V_3 , ( char V_176 * ) V_153 , * V_240 ) ;
F_86 ( V_173 ) ;
if ( V_28 < 0 )
goto V_31;
* V_240 = V_28 ;
V_11 = 0 ;
V_12:
return V_11 ;
V_31:
V_11 = F_28 ( V_28 ) ;
goto V_12;
}
T_1
F_122 ( struct V_1 * V_2 , struct V_22 * V_23 ,
char * V_206 , int V_207 ,
char * V_8 , int V_243 ,
struct V_22 * V_204 ,
struct V_42 * V_43 )
{
struct V_3 * V_3 , * V_244 ;
T_1 V_11 , V_245 ;
int V_28 ;
V_11 = V_36 ;
if ( ! V_207 || ! V_243 )
goto V_12;
V_11 = V_211 ;
if ( F_25 ( V_206 , V_207 ) )
goto V_12;
V_11 = F_30 ( V_2 , V_23 , V_34 , V_212 ) ;
if ( V_11 )
goto V_12;
V_28 = F_48 ( V_23 ) ;
if ( V_28 )
goto V_31;
F_50 ( V_23 ) ;
V_3 = V_23 -> V_29 ;
V_244 = F_27 ( V_206 , V_3 , V_207 ) ;
V_28 = F_7 ( V_244 ) ;
if ( F_6 ( V_244 ) )
goto V_31;
if ( F_123 ( V_8 [ V_243 ] != 0 ) ) {
char * V_246 = F_124 ( V_243 + 1 , V_247 ) ;
if ( V_246 == NULL )
V_28 = - V_248 ;
else {
strncpy ( V_246 , V_8 , V_243 ) ;
V_246 [ V_243 ] = 0 ;
V_28 = F_125 ( V_3 -> V_21 , V_244 , V_246 ) ;
F_126 ( V_246 ) ;
}
} else
V_28 = F_125 ( V_3 -> V_21 , V_244 , V_8 ) ;
V_11 = F_28 ( V_28 ) ;
if ( ! V_11 )
V_11 = F_28 ( F_33 ( V_23 ) ) ;
F_52 ( V_23 ) ;
F_119 ( V_23 ) ;
V_245 = F_32 ( V_204 , V_23 -> V_30 , V_244 , V_23 ) ;
F_15 ( V_244 ) ;
if ( V_11 == 0 ) V_11 = V_245 ;
V_12:
return V_11 ;
V_31:
V_11 = F_28 ( V_28 ) ;
goto V_12;
}
T_1
F_127 ( struct V_1 * V_2 , struct V_22 * V_249 ,
char * V_24 , int V_25 , struct V_22 * V_250 )
{
struct V_3 * V_251 , * V_244 , * V_252 ;
struct V_37 * V_210 ;
T_1 V_11 ;
int V_28 ;
V_11 = F_30 ( V_2 , V_249 , V_34 , V_212 ) ;
if ( V_11 )
goto V_12;
V_11 = F_30 ( V_2 , V_250 , 0 , V_99 ) ;
if ( V_11 )
goto V_12;
V_11 = V_253 ;
if ( F_41 ( V_250 -> V_29 -> V_21 -> V_52 ) )
goto V_12;
V_11 = V_108 ;
if ( ! V_25 )
goto V_12;
V_11 = V_211 ;
if ( F_25 ( V_24 , V_25 ) )
goto V_12;
V_28 = F_48 ( V_250 ) ;
if ( V_28 ) {
V_11 = F_28 ( V_28 ) ;
goto V_12;
}
F_26 ( V_249 , V_32 ) ;
V_251 = V_249 -> V_29 ;
V_210 = V_251 -> V_21 ;
V_244 = F_27 ( V_24 , V_251 , V_25 ) ;
V_28 = F_7 ( V_244 ) ;
if ( F_6 ( V_244 ) )
goto V_31;
V_252 = V_250 -> V_29 ;
V_11 = V_36 ;
if ( ! V_252 -> V_21 )
goto V_254;
V_28 = F_128 ( V_252 , V_210 , V_244 , NULL ) ;
if ( ! V_28 ) {
V_11 = F_28 ( F_33 ( V_249 ) ) ;
if ( ! V_11 )
V_11 = F_28 ( F_33 ( V_250 ) ) ;
} else {
if ( V_28 == - V_255 && V_2 -> V_196 == 2 )
V_11 = V_107 ;
else
V_11 = F_28 ( V_28 ) ;
}
V_254:
F_15 ( V_244 ) ;
V_256:
F_52 ( V_249 ) ;
F_119 ( V_250 ) ;
V_12:
return V_11 ;
V_31:
V_11 = F_28 ( V_28 ) ;
goto V_256;
}
T_1
F_129 ( struct V_1 * V_2 , struct V_22 * V_249 , char * V_206 , int V_207 ,
struct V_22 * V_250 , char * V_257 , int V_258 )
{
struct V_3 * V_259 , * V_260 , * V_261 , * V_262 , * V_263 ;
struct V_37 * V_264 , * V_265 ;
T_1 V_11 ;
int V_28 ;
V_11 = F_30 ( V_2 , V_249 , V_34 , V_266 ) ;
if ( V_11 )
goto V_12;
V_11 = F_30 ( V_2 , V_250 , V_34 , V_212 ) ;
if ( V_11 )
goto V_12;
V_259 = V_249 -> V_29 ;
V_264 = V_259 -> V_21 ;
V_260 = V_250 -> V_29 ;
V_265 = V_260 -> V_21 ;
V_11 = V_108 ;
if ( ! V_207 || F_25 ( V_206 , V_207 ) || ! V_258 || F_25 ( V_257 , V_258 ) )
goto V_12;
V_28 = F_48 ( V_249 ) ;
if ( V_28 ) {
V_11 = F_28 ( V_28 ) ;
goto V_12;
}
V_263 = F_130 ( V_260 , V_259 ) ;
V_249 -> V_216 = V_250 -> V_216 = 1 ;
F_131 ( V_249 ) ;
F_131 ( V_250 ) ;
V_261 = F_27 ( V_206 , V_259 , V_207 ) ;
V_28 = F_7 ( V_261 ) ;
if ( F_6 ( V_261 ) )
goto V_31;
V_28 = - V_13 ;
if ( ! V_261 -> V_21 )
goto V_267;
V_28 = - V_203 ;
if ( V_261 == V_263 )
goto V_267;
V_262 = F_27 ( V_257 , V_260 , V_258 ) ;
V_28 = F_7 ( V_262 ) ;
if ( F_6 ( V_262 ) )
goto V_267;
V_28 = - V_268 ;
if ( V_262 == V_263 )
goto V_269;
V_28 = - V_255 ;
if ( V_249 -> V_30 -> V_10 . V_9 != V_250 -> V_30 -> V_10 . V_9 )
goto V_269;
if ( V_249 -> V_30 -> V_10 . V_3 != V_250 -> V_30 -> V_10 . V_3 )
goto V_269;
V_28 = F_132 ( V_264 , V_261 , V_265 , V_262 , NULL , 0 ) ;
if ( ! V_28 ) {
V_28 = F_33 ( V_250 ) ;
if ( ! V_28 )
V_28 = F_33 ( V_249 ) ;
}
V_269:
F_15 ( V_262 ) ;
V_267:
F_15 ( V_261 ) ;
V_31:
V_11 = F_28 ( V_28 ) ;
F_133 ( V_249 ) ;
F_133 ( V_250 ) ;
F_134 ( V_260 , V_259 ) ;
V_249 -> V_216 = V_250 -> V_216 = 0 ;
F_119 ( V_249 ) ;
V_12:
return V_11 ;
}
T_1
F_135 ( struct V_1 * V_2 , struct V_22 * V_23 , int type ,
char * V_206 , int V_207 )
{
struct V_3 * V_3 , * V_270 ;
struct V_37 * V_210 ;
T_1 V_11 ;
int V_28 ;
V_11 = V_107 ;
if ( ! V_207 || F_25 ( V_206 , V_207 ) )
goto V_12;
V_11 = F_30 ( V_2 , V_23 , V_34 , V_266 ) ;
if ( V_11 )
goto V_12;
V_28 = F_48 ( V_23 ) ;
if ( V_28 )
goto V_31;
F_26 ( V_23 , V_32 ) ;
V_3 = V_23 -> V_29 ;
V_210 = V_3 -> V_21 ;
V_270 = F_27 ( V_206 , V_3 , V_207 ) ;
V_28 = F_7 ( V_270 ) ;
if ( F_6 ( V_270 ) )
goto V_31;
if ( ! V_270 -> V_21 ) {
F_15 ( V_270 ) ;
V_11 = V_36 ;
goto V_12;
}
if ( ! type )
type = V_270 -> V_21 -> V_52 & V_271 ;
if ( type != V_34 )
V_28 = F_136 ( V_210 , V_270 , NULL ) ;
else
V_28 = F_137 ( V_210 , V_270 ) ;
if ( ! V_28 )
V_28 = F_33 ( V_23 ) ;
F_15 ( V_270 ) ;
V_31:
V_11 = F_28 ( V_28 ) ;
V_12:
return V_11 ;
}
static int F_138 ( void * V_272 , const char * V_24 , int V_273 ,
T_8 V_164 , T_11 V_128 , unsigned int V_274 )
{
struct V_275 * V_153 = V_272 ;
struct V_276 * V_277 = ( void * ) ( V_153 -> V_278 + V_153 -> V_279 ) ;
unsigned int V_280 ;
V_280 = F_139 ( sizeof( struct V_276 ) + V_273 , sizeof( T_11 ) ) ;
if ( V_153 -> V_279 + V_280 > V_281 ) {
V_153 -> V_282 = 1 ;
return - V_203 ;
}
V_277 -> V_273 = V_273 ;
V_277 -> V_164 = V_164 ;
V_277 -> V_128 = V_128 ;
V_277 -> V_274 = V_274 ;
memcpy ( V_277 -> V_24 , V_24 , V_273 ) ;
V_153 -> V_279 += V_280 ;
return 0 ;
}
static T_1 F_140 ( struct V_115 * V_115 , T_12 V_283 ,
struct V_284 * V_285 , T_8 * V_286 )
{
struct V_276 * V_277 ;
int V_28 ;
int V_160 ;
T_8 V_164 ;
struct V_275 V_153 = {
. V_287 . V_288 = F_138 ,
. V_278 = ( void * ) F_141 (GFP_KERNEL)
} ;
if ( ! V_153 . V_278 )
return F_28 ( - V_248 ) ;
V_164 = * V_286 ;
while ( 1 ) {
struct V_37 * V_289 = F_90 ( V_115 ) ;
unsigned int V_280 ;
V_285 -> V_11 = V_290 ;
V_153 . V_279 = 0 ;
V_153 . V_282 = 0 ;
V_28 = F_142 ( V_115 , & V_153 . V_287 ) ;
if ( V_153 . V_282 )
V_28 = 0 ;
if ( V_28 < 0 )
break;
V_160 = V_153 . V_279 ;
if ( ! V_160 )
break;
V_28 = F_143 ( & V_289 -> V_88 ) ;
if ( V_28 )
break;
V_277 = (struct V_276 * ) V_153 . V_278 ;
while ( V_160 > 0 ) {
V_164 = V_277 -> V_164 ;
if ( V_283 ( V_285 , V_277 -> V_24 , V_277 -> V_273 , V_277 -> V_164 ,
V_277 -> V_128 , V_277 -> V_274 ) )
break;
if ( V_285 -> V_11 != V_105 )
break;
V_280 = F_139 ( sizeof( * V_277 ) + V_277 -> V_273 ,
sizeof( T_11 ) ) ;
V_160 -= V_280 ;
V_277 = (struct V_276 * ) ( ( char * ) V_277 + V_280 ) ;
}
F_57 ( & V_289 -> V_88 ) ;
if ( V_160 > 0 )
break;
V_164 = F_144 ( V_115 , 0 , V_291 ) ;
}
F_145 ( ( unsigned long ) ( V_153 . V_278 ) ) ;
if ( V_28 )
return F_28 ( V_28 ) ;
* V_286 = V_164 ;
return V_285 -> V_11 ;
}
T_1
F_146 ( struct V_1 * V_2 , struct V_22 * V_23 , T_8 * V_286 ,
struct V_284 * V_285 , T_12 V_283 )
{
T_1 V_11 ;
struct V_115 * V_115 ;
T_8 V_164 = * V_286 ;
int V_114 = V_120 ;
if ( V_2 -> V_196 > 2 )
V_114 |= V_122 ;
V_11 = F_62 ( V_2 , V_23 , V_34 , V_114 , & V_115 ) ;
if ( V_11 )
goto V_12;
V_164 = F_144 ( V_115 , V_164 , V_292 ) ;
if ( V_164 < 0 ) {
V_11 = F_28 ( ( int ) V_164 ) ;
goto V_293;
}
V_11 = F_140 ( V_115 , V_283 , V_285 , V_286 ) ;
if ( V_11 == V_290 || V_11 == V_294 )
V_11 = V_105 ;
V_293:
F_69 ( V_115 ) ;
V_12:
return V_11 ;
}
T_1
F_147 ( struct V_1 * V_2 , struct V_22 * V_23 , struct V_295 * V_296 , int V_91 )
{
T_1 V_11 ;
V_11 = F_30 ( V_2 , V_23 , 0 , V_99 | V_91 ) ;
if ( ! V_11 ) {
struct V_8 V_8 = {
. V_9 = V_23 -> V_30 -> V_10 . V_9 ,
. V_3 = V_23 -> V_29 ,
} ;
if ( F_148 ( & V_8 , V_296 ) )
V_11 = V_218 ;
}
return V_11 ;
}
static int F_149 ( struct V_1 * V_2 , struct V_5 * exp )
{
return F_150 ( V_2 , exp ) & V_297 ;
}
T_1
F_43 ( struct V_1 * V_2 , struct V_5 * exp ,
struct V_3 * V_3 , int V_298 )
{
struct V_37 * V_37 = V_3 -> V_21 ;
int V_11 ;
if ( ( V_298 & V_299 ) == V_99 )
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
if ( ! ( V_298 & V_300 ) )
if ( V_298 & ( V_77 | V_70 | V_63 ) ) {
if ( F_149 ( V_2 , exp ) ||
F_151 ( exp -> V_10 . V_9 ) )
return V_106 ;
if ( F_152 ( V_37 ) )
return V_108 ;
}
if ( ( V_298 & V_63 ) && F_64 ( V_37 ) )
return V_108 ;
if ( V_298 & V_301 ) {
if ( exp -> V_14 & V_302 )
return 0 ;
else
V_298 = V_120 | V_64 ;
}
if ( ( V_298 & V_64 ) &&
F_107 ( V_37 -> V_303 , F_108 () ) )
return 0 ;
V_11 = F_153 ( V_37 , V_298 & ( V_304 | V_305 | V_306 ) ) ;
if ( V_11 == - V_307 && F_59 ( V_37 -> V_52 ) &&
( V_298 == ( V_120 | V_64 ) ||
V_298 == ( V_120 | V_308 ) ) )
V_11 = F_153 ( V_37 , V_306 ) ;
return V_11 ? F_28 ( V_11 ) : 0 ;
}
void
F_154 ( void )
{
struct V_126 * V_309 , * V_310 ;
unsigned int V_311 ;
F_22 ( L_9 ) ;
for ( V_311 = 0 ; V_311 < V_312 ; V_311 ++ ) {
V_309 = V_137 [ V_311 ] . V_139 ;
while( V_309 ) {
V_310 = V_309 ;
V_309 = V_309 -> V_140 ;
F_126 ( V_310 ) ;
}
V_137 [ V_311 ] . V_139 = NULL ;
}
}
int
F_155 ( int V_313 )
{
int V_311 ;
int V_314 = 0 ;
int V_315 ;
struct V_126 * * V_309 = NULL ;
if ( V_137 [ 0 ] . V_139 )
return 0 ;
V_315 = F_156 ( V_313 , V_312 ) ;
if ( V_315 < 2 )
V_315 = 2 ;
V_313 = V_315 * V_312 ;
F_22 ( L_10 , V_313 ) ;
for ( V_311 = 0 ; V_311 < V_312 ; V_311 ++ ) {
F_157 ( & V_137 [ V_311 ] . V_138 ) ;
V_309 = & V_137 [ V_311 ] . V_139 ;
for ( V_314 = 0 ; V_314 < V_315 ; V_314 ++ ) {
* V_309 = F_158 ( sizeof( struct V_126 ) , V_247 ) ;
if ( ! * V_309 )
goto V_316;
V_309 = & ( * V_309 ) -> V_140 ;
}
* V_309 = NULL ;
}
V_145 . V_146 = V_313 ;
return 0 ;
V_316:
F_22 ( L_11 ) ;
F_154 () ;
return - V_248 ;
}

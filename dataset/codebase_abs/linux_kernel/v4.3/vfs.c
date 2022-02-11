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
return F_21 ( V_3 ) != NULL ;
}
T_1
F_22 ( struct V_1 * V_2 , struct V_21 * V_22 ,
const char * V_23 , unsigned int V_24 ,
struct V_5 * * V_25 , struct V_3 * * V_26 )
{
struct V_5 * exp ;
struct V_3 * V_19 ;
struct V_3 * V_3 ;
int V_27 ;
F_23 ( L_1 , F_24 ( V_22 ) , V_24 , V_23 ) ;
V_19 = V_22 -> V_28 ;
exp = F_25 ( V_22 -> V_29 ) ;
if ( F_26 ( V_23 , V_24 ) ) {
if ( V_24 == 1 )
V_3 = F_3 ( V_19 ) ;
else if ( V_19 != exp -> V_10 . V_3 )
V_3 = F_14 ( V_19 ) ;
else if ( ! F_10 ( exp ) && ! F_9 ( V_2 ) )
V_3 = F_3 ( V_19 ) ;
else {
V_27 = F_16 ( V_2 , V_19 , & exp , & V_3 ) ;
if ( V_27 )
goto V_30;
}
} else {
F_27 ( V_22 , V_31 ) ;
V_3 = F_28 ( V_23 , V_19 , V_24 ) ;
V_27 = F_7 ( V_3 ) ;
if ( F_6 ( V_3 ) )
goto V_30;
if ( F_18 ( V_3 , exp ) ) {
if ( ( V_27 = F_1 ( V_2 , & V_3 , & exp ) ) ) {
F_15 ( V_3 ) ;
goto V_30;
}
}
}
* V_26 = V_3 ;
* V_25 = exp ;
return 0 ;
V_30:
F_11 ( exp ) ;
return F_29 ( V_27 ) ;
}
T_1
F_30 ( struct V_1 * V_2 , struct V_21 * V_22 , const char * V_23 ,
unsigned int V_24 , struct V_21 * V_32 )
{
struct V_5 * exp ;
struct V_3 * V_3 ;
T_1 V_11 ;
V_11 = F_31 ( V_2 , V_22 , V_33 , V_34 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_22 ( V_2 , V_22 , V_23 , V_24 , & exp , & V_3 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_32 ( exp , V_2 ) ;
if ( V_11 )
goto V_12;
V_11 = F_33 ( V_32 , exp , V_3 , V_22 ) ;
if ( ! V_11 && F_34 ( V_3 ) )
V_11 = V_35 ;
V_12:
F_15 ( V_3 ) ;
F_11 ( exp ) ;
return V_11 ;
}
static int
F_35 ( struct V_21 * V_22 )
{
struct V_36 * V_36 = F_21 ( V_22 -> V_28 ) ;
const struct V_37 * V_38 = V_36 -> V_39 -> V_40 ;
if ( ! F_36 ( V_22 -> V_29 ) )
return 0 ;
if ( V_38 -> F_35 )
return V_38 -> F_35 ( V_36 ) ;
return F_37 ( V_36 , 1 ) ;
}
static void
F_38 ( struct V_36 * V_36 , struct V_41 * V_42 )
{
if ( V_42 -> V_43 & V_44 ) {
V_42 -> V_45 &= V_46 ;
V_42 -> V_45 |= ( V_36 -> V_47 & ~ V_46 ) ;
}
if ( ! F_39 ( V_36 -> V_47 ) &&
( ( V_42 -> V_43 & V_48 ) || ( V_42 -> V_43 & V_49 ) ) ) {
V_42 -> V_43 |= V_50 ;
if ( V_42 -> V_43 & V_44 ) {
V_42 -> V_45 &= ~ V_51 ;
if ( V_42 -> V_45 & V_52 )
V_42 -> V_45 &= ~ V_53 ;
} else {
V_42 -> V_43 |= ( V_54 | V_55 ) ;
}
}
}
static T_1
F_40 ( struct V_1 * V_2 , struct V_21 * V_22 ,
struct V_41 * V_42 )
{
struct V_36 * V_36 = F_21 ( V_22 -> V_28 ) ;
int V_27 ;
if ( V_42 -> V_56 < V_36 -> V_57 ) {
T_1 V_11 ;
V_11 = F_41 ( V_2 , V_22 -> V_29 , V_22 -> V_28 ,
V_58 | V_59 ) ;
if ( V_11 )
return V_11 ;
}
V_27 = F_42 ( V_36 ) ;
if ( V_27 )
goto V_60;
V_27 = F_43 ( V_36 , NULL , V_42 -> V_56 ) ;
if ( V_27 )
goto V_61;
return 0 ;
V_61:
F_44 ( V_36 ) ;
V_60:
return F_29 ( V_27 ) ;
}
T_1
F_45 ( struct V_1 * V_2 , struct V_21 * V_22 , struct V_41 * V_42 ,
int V_62 , T_2 V_63 )
{
struct V_3 * V_3 ;
struct V_36 * V_36 ;
int V_64 = V_65 ;
T_3 V_66 = 0 ;
T_1 V_11 ;
int V_27 ;
bool V_67 ;
int V_68 = 0 ;
if ( V_42 -> V_43 & ( V_69 | V_70 | V_71 ) )
V_64 |= V_72 | V_59 ;
if ( V_42 -> V_43 & V_71 )
V_66 = V_73 ;
V_67 = ! V_22 -> V_28 ;
V_11 = F_31 ( V_2 , V_22 , V_66 , V_64 ) ;
if ( V_11 )
goto V_12;
if ( V_67 ) {
V_27 = F_46 ( V_22 ) ;
if ( V_27 )
return F_29 ( V_27 ) ;
}
V_3 = V_22 -> V_28 ;
V_36 = F_21 ( V_3 ) ;
if ( F_47 ( V_36 -> V_47 ) )
V_42 -> V_43 &= ~ V_44 ;
if ( ! V_42 -> V_43 )
goto V_12;
F_38 ( V_36 , V_42 ) ;
if ( V_42 -> V_43 & V_71 ) {
V_11 = F_40 ( V_2 , V_22 , V_42 ) ;
if ( V_11 )
goto V_12;
V_68 = 1 ;
if ( V_42 -> V_56 != F_48 ( V_36 ) )
V_42 -> V_43 |= V_70 ;
}
V_42 -> V_43 |= V_74 ;
if ( V_62 && V_63 != V_36 -> V_75 . V_76 ) {
V_11 = V_77 ;
goto V_61;
}
F_49 ( V_22 ) ;
V_27 = F_50 ( V_3 , V_42 , NULL ) ;
F_51 ( V_22 ) ;
V_11 = F_29 ( V_27 ) ;
V_61:
if ( V_68 )
F_44 ( V_36 ) ;
if ( ! V_11 )
V_11 = F_29 ( F_35 ( V_22 ) ) ;
V_12:
return V_11 ;
}
int F_20 ( struct V_3 * V_3 )
{
struct V_36 * V_36 = F_21 ( V_3 ) ;
if ( V_36 == NULL )
return 0 ;
if ( V_36 -> V_47 & V_78 )
return 0 ;
if ( ! ( V_36 -> V_47 & V_79 ) )
return 0 ;
if ( F_52 ( V_3 , V_80 , NULL , 0 ) <= 0 )
return 0 ;
return 1 ;
}
T_1 F_53 ( struct V_1 * V_2 , struct V_21 * V_22 ,
struct V_81 * V_82 )
{
T_1 error ;
int V_83 ;
struct V_3 * V_3 ;
error = F_31 ( V_2 , V_22 , 0 , V_65 ) ;
if ( error )
return error ;
V_3 = V_22 -> V_28 ;
F_54 ( & F_21 ( V_3 ) -> V_84 ) ;
V_83 = F_55 ( V_3 , V_82 -> V_85 , V_82 -> V_24 ) ;
F_56 ( & F_21 ( V_3 ) -> V_84 ) ;
return F_29 ( V_83 ) ;
}
T_1 F_53 ( struct V_1 * V_2 , struct V_21 * V_22 ,
struct V_81 * V_82 )
{
return V_86 ;
}
T_1 F_57 ( struct V_1 * V_2 , struct V_21 * V_22 ,
struct V_87 * V_87 , T_4 V_88 , T_4 V_24 ,
int V_89 )
{
int error ;
if ( ! F_58 ( F_59 ( V_87 ) -> V_47 ) )
return V_90 ;
error = F_60 ( V_87 , V_89 , V_88 , V_24 ) ;
if ( ! error )
error = F_35 ( V_22 ) ;
return F_29 ( error ) ;
}
T_1
F_61 ( struct V_1 * V_2 , struct V_21 * V_22 , T_5 * V_91 , T_5 * V_92 )
{
struct V_93 * V_94 ;
struct V_5 * V_95 ;
struct V_3 * V_3 ;
T_5 V_96 , V_97 = 0 , V_98 = 0 ;
T_1 error ;
error = F_31 ( V_2 , V_22 , 0 , V_99 ) ;
if ( error )
goto V_12;
V_95 = V_22 -> V_29 ;
V_3 = V_22 -> V_28 ;
if ( F_62 ( V_3 ) )
V_94 = V_100 ;
else if ( F_63 ( V_3 ) )
V_94 = V_101 ;
else
V_94 = V_102 ;
V_96 = * V_91 ;
for (; V_94 -> V_91 ; V_94 ++ ) {
if ( V_94 -> V_91 & V_96 ) {
T_1 V_103 ;
V_98 |= V_94 -> V_91 ;
V_103 = F_41 ( V_2 , V_95 , V_3 , V_94 -> V_104 ) ;
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
static int F_64 ( struct V_36 * V_36 , int V_91 )
{
unsigned int V_109 ;
if ( V_91 & V_110 )
return 0 ;
V_109 = ( V_91 & V_72 ) ? V_111 : V_112 ;
return F_65 ( V_36 , V_109 | V_113 ) ;
}
T_1
F_66 ( struct V_1 * V_2 , struct V_21 * V_22 , T_3 type ,
int V_114 , struct V_87 * * V_115 )
{
struct V_8 V_8 ;
struct V_36 * V_36 ;
struct V_87 * V_87 ;
int V_89 = V_112 | V_116 ;
T_1 V_11 ;
int V_27 = 0 ;
F_67 () ;
if ( type == V_73 )
V_114 |= V_59 ;
V_11 = F_31 ( V_2 , V_22 , type , V_114 ) ;
if ( V_11 )
goto V_12;
V_8 . V_9 = V_22 -> V_29 -> V_10 . V_9 ;
V_8 . V_3 = V_22 -> V_28 ;
V_36 = F_21 ( V_8 . V_3 ) ;
V_11 = V_108 ;
if ( F_68 ( V_36 ) && ( V_114 & V_72 ) )
goto V_12;
if ( F_58 ( ( V_36 ) -> V_47 ) && F_69 ( V_36 ) )
goto V_12;
if ( ! V_36 -> V_117 )
goto V_12;
V_27 = F_64 ( V_36 , V_114 ) ;
if ( V_27 )
goto V_30;
if ( V_114 & V_72 ) {
if ( V_114 & V_118 )
V_89 = V_119 | V_116 ;
else
V_89 = V_111 | V_116 ;
}
V_87 = F_70 ( & V_8 , V_89 , F_71 () ) ;
if ( F_6 ( V_87 ) ) {
V_27 = F_7 ( V_87 ) ;
goto V_30;
}
V_27 = F_72 ( V_87 , V_114 , 0 ) ;
if ( V_27 ) {
F_73 ( V_87 ) ;
goto V_30;
}
if ( V_114 & V_120 )
V_87 -> V_121 |= V_122 ;
else
V_87 -> V_121 |= V_123 ;
* V_115 = V_87 ;
V_30:
V_11 = F_29 ( V_27 ) ;
V_12:
F_67 () ;
return V_11 ;
}
struct V_124 *
F_74 ( struct V_87 * V_87 )
{
struct V_36 * V_36 = F_59 ( V_87 ) ;
T_6 V_125 = V_36 -> V_39 -> V_126 ;
T_7 V_127 = V_36 -> V_128 ;
struct V_124 * V_129 , * * V_130 , * * V_131 = NULL ;
int V_132 = 0 ;
unsigned int V_133 ;
struct V_134 * V_135 ;
V_133 = F_75 ( V_125 , V_127 , 0xfeedbeef ) & V_136 ;
V_135 = & V_137 [ V_133 ] ;
F_76 ( & V_135 -> V_138 ) ;
for ( V_130 = & V_135 -> V_139 ; ( V_129 = * V_130 ) ; V_130 = & V_129 -> V_140 ) {
if ( V_129 -> V_141 == V_127 && V_129 -> V_142 == V_125 )
goto V_143;
V_132 ++ ;
if ( V_129 -> V_144 == 0 )
V_131 = V_130 ;
}
V_132 = V_145 . V_146 ;
if ( ! V_131 ) {
F_77 ( & V_135 -> V_138 ) ;
return NULL ;
}
V_130 = V_131 ;
V_129 = * V_131 ;
V_129 -> V_142 = V_125 ;
V_129 -> V_141 = V_127 ;
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
F_77 ( & V_135 -> V_138 ) ;
if ( V_129 -> V_147 )
V_87 -> V_150 = V_129 -> V_151 ;
return V_129 ;
}
void F_78 ( struct V_87 * V_87 , struct V_124 * V_129 )
{
struct V_134 * V_135 = & V_137 [ V_129 -> V_148 ] ;
F_76 ( & V_135 -> V_138 ) ;
V_129 -> V_151 = V_87 -> V_150 ;
V_129 -> V_147 = 1 ;
V_129 -> V_144 -- ;
F_77 ( & V_135 -> V_138 ) ;
}
static int
F_79 ( struct V_152 * V_153 , struct V_154 * V_155 ,
struct V_156 * V_157 )
{
struct V_1 * V_2 = V_157 -> V_158 . V_85 ;
struct V_159 * * V_160 = V_2 -> V_161 ;
struct V_159 * V_159 = V_155 -> V_159 ;
T_8 V_162 ;
V_162 = V_157 -> V_24 ;
if ( V_2 -> V_163 . V_164 == 0 ) {
F_80 ( V_159 ) ;
F_81 ( * V_2 -> V_161 ) ;
* ( V_2 -> V_161 ++ ) = V_159 ;
V_2 -> V_163 . V_165 = V_155 -> V_88 ;
V_2 -> V_163 . V_164 = V_162 ;
} else if ( V_159 != V_160 [ - 1 ] ) {
F_80 ( V_159 ) ;
if ( * V_2 -> V_161 )
F_81 ( * V_2 -> V_161 ) ;
* ( V_2 -> V_161 ++ ) = V_159 ;
V_2 -> V_163 . V_164 += V_162 ;
} else
V_2 -> V_163 . V_164 += V_162 ;
return V_162 ;
}
static int F_82 ( struct V_152 * V_153 ,
struct V_156 * V_157 )
{
return F_83 ( V_153 , V_157 , F_79 ) ;
}
static T_1
F_84 ( struct V_87 * V_87 , unsigned long * V_166 , int V_27 )
{
if ( V_27 >= 0 ) {
V_145 . V_167 += V_27 ;
* V_166 = V_27 ;
F_85 ( V_87 ) ;
return 0 ;
} else
return F_29 ( V_27 ) ;
}
T_1 F_86 ( struct V_1 * V_2 ,
struct V_87 * V_87 , T_4 V_88 , unsigned long * V_166 )
{
struct V_156 V_157 = {
. V_24 = 0 ,
. V_168 = * V_166 ,
. V_169 = V_88 ,
. V_158 . V_85 = V_2 ,
} ;
int V_27 ;
V_2 -> V_161 = V_2 -> V_170 + 1 ;
V_27 = F_87 ( V_87 , & V_157 , F_82 ) ;
return F_84 ( V_87 , V_166 , V_27 ) ;
}
T_1 F_88 ( struct V_87 * V_87 , T_4 V_88 , struct V_171 * V_172 , int V_173 ,
unsigned long * V_166 )
{
T_9 V_174 ;
int V_27 ;
V_174 = F_89 () ;
F_90 ( V_175 ) ;
V_27 = F_91 ( V_87 , (struct V_176 V_177 * ) V_172 , V_173 , & V_88 ) ;
F_90 ( V_174 ) ;
return F_84 ( V_87 , V_166 , V_27 ) ;
}
static T_1
F_92 ( struct V_1 * V_2 , struct V_87 * V_87 ,
T_4 V_88 , struct V_171 * V_172 , int V_173 , unsigned long * V_166 )
{
if ( V_87 -> V_178 -> V_179 && F_93 ( V_180 , & V_2 -> V_181 ) )
return F_86 ( V_2 , V_87 , V_88 , V_166 ) ;
else
return F_88 ( V_87 , V_88 , V_172 , V_173 , V_166 ) ;
}
static int F_94 ( struct V_87 * V_87 )
{
struct V_36 * V_36 = F_59 ( V_87 ) ;
static T_7 V_182 ;
static T_6 V_183 ;
int V_11 = 0 ;
if ( F_95 ( & V_36 -> V_184 ) > 1
|| ( V_182 == V_36 -> V_128 && V_183 == V_36 -> V_39 -> V_126 ) ) {
F_23 ( L_2 , F_96 ( V_185 ) ) ;
F_97 ( 10 ) ;
F_23 ( L_3 , F_96 ( V_185 ) ) ;
}
if ( V_36 -> V_186 & V_187 ) {
F_23 ( L_4 , F_96 ( V_185 ) ) ;
V_11 = F_98 ( V_87 , 0 ) ;
}
V_182 = V_36 -> V_128 ;
V_183 = V_36 -> V_39 -> V_126 ;
return V_11 ;
}
T_1
F_99 ( struct V_1 * V_2 , struct V_21 * V_22 , struct V_87 * V_87 ,
T_4 V_88 , struct V_171 * V_172 , int V_173 ,
unsigned long * V_188 , int * V_189 )
{
struct V_5 * exp ;
struct V_36 * V_36 ;
T_9 V_174 ;
T_1 V_11 = 0 ;
int V_27 ;
int V_190 = * V_189 ;
int V_191 ;
T_4 V_169 = V_88 ;
T_4 V_192 = V_193 ;
unsigned int V_194 = V_185 -> V_89 ;
if ( F_93 ( V_195 , & V_2 -> V_181 ) )
V_185 -> V_89 |= V_196 ;
V_36 = F_59 ( V_87 ) ;
exp = V_22 -> V_29 ;
V_191 = ( V_2 -> V_197 == 2 ) && F_100 ( exp ) ;
if ( ! F_36 ( exp ) )
V_190 = 0 ;
V_174 = F_89 () ; F_90 ( V_175 ) ;
V_27 = F_101 ( V_87 , (struct V_176 V_177 * ) V_172 , V_173 , & V_169 ) ;
F_90 ( V_174 ) ;
if ( V_27 < 0 )
goto V_30;
* V_188 = V_27 ;
V_145 . V_198 += V_27 ;
F_102 ( V_87 ) ;
if ( V_190 ) {
if ( V_191 ) {
V_27 = F_94 ( V_87 ) ;
} else {
if ( * V_188 )
V_192 = V_88 + * V_188 - 1 ;
V_27 = F_103 ( V_87 , V_88 , V_192 , 0 ) ;
}
}
V_30:
F_23 ( L_5 , V_27 ) ;
if ( V_27 >= 0 )
V_11 = 0 ;
else
V_11 = F_29 ( V_27 ) ;
if ( F_93 ( V_195 , & V_2 -> V_181 ) )
F_104 ( V_185 , V_194 , V_196 ) ;
return V_11 ;
}
T_1 F_105 ( struct V_1 * V_2 , struct V_21 * V_22 ,
T_4 V_88 , struct V_171 * V_172 , int V_173 , unsigned long * V_166 )
{
struct V_87 * V_87 ;
struct V_124 * V_129 ;
T_1 V_11 ;
V_11 = F_66 ( V_2 , V_22 , V_73 , V_118 , & V_87 ) ;
if ( V_11 )
return V_11 ;
V_129 = F_74 ( V_87 ) ;
V_11 = F_92 ( V_2 , V_87 , V_88 , V_172 , V_173 , V_166 ) ;
if ( V_129 )
F_78 ( V_87 , V_129 ) ;
F_73 ( V_87 ) ;
return V_11 ;
}
T_1
F_106 ( struct V_1 * V_2 , struct V_21 * V_22 , struct V_87 * V_87 ,
T_4 V_88 , struct V_171 * V_172 , int V_173 , unsigned long * V_188 ,
int * V_189 )
{
T_1 V_11 = 0 ;
if ( V_87 ) {
V_11 = F_41 ( V_2 , V_22 -> V_29 , V_22 -> V_28 ,
V_72 | V_59 ) ;
if ( V_11 )
goto V_12;
V_11 = F_99 ( V_2 , V_22 , V_87 , V_88 , V_172 , V_173 , V_188 ,
V_189 ) ;
} else {
V_11 = F_66 ( V_2 , V_22 , V_73 , V_72 , & V_87 ) ;
if ( V_11 )
goto V_12;
if ( V_188 )
V_11 = F_99 ( V_2 , V_22 , V_87 , V_88 , V_172 , V_173 ,
V_188 , V_189 ) ;
F_73 ( V_87 ) ;
}
V_12:
return V_11 ;
}
T_1
F_107 ( struct V_1 * V_2 , struct V_21 * V_22 ,
T_4 V_88 , unsigned long V_166 )
{
struct V_87 * V_87 ;
T_4 V_192 = V_193 ;
T_1 V_11 = V_90 ;
if ( V_88 < 0 )
goto V_12;
if ( V_166 != 0 ) {
V_192 = V_88 + ( T_4 ) V_166 - 1 ;
if ( V_192 < V_88 )
goto V_12;
}
V_11 = F_66 ( V_2 , V_22 , V_73 ,
V_72 | V_110 , & V_87 ) ;
if ( V_11 )
goto V_12;
if ( F_36 ( V_22 -> V_29 ) ) {
int V_103 = F_103 ( V_87 , V_88 , V_192 , 0 ) ;
if ( V_103 != - V_199 )
V_11 = F_29 ( V_103 ) ;
else
V_11 = V_86 ;
}
F_73 ( V_87 ) ;
V_12:
return V_11 ;
}
static T_1
F_108 ( struct V_1 * V_2 , struct V_21 * V_200 ,
struct V_41 * V_42 )
{
V_42 -> V_43 &= ~ V_44 ;
if ( ! F_109 ( F_110 () , V_201 ) )
V_42 -> V_43 &= ~ ( V_48 | V_49 ) ;
if ( V_42 -> V_43 )
return F_45 ( V_2 , V_200 , V_42 , 0 , ( T_2 ) 0 ) ;
return F_29 ( F_35 ( V_200 ) ) ;
}
static void
F_111 ( struct V_41 * V_42 )
{
if ( ( V_42 -> V_43 & V_71 ) && ( V_42 -> V_56 == 0 ) )
V_42 -> V_43 &= ~ V_71 ;
}
T_1
F_112 ( struct V_1 * V_2 , struct V_21 * V_22 ,
char * V_202 , int V_203 , struct V_41 * V_42 ,
int type , T_6 V_204 , struct V_21 * V_200 )
{
struct V_3 * V_3 , * V_205 = NULL ;
struct V_36 * V_206 ;
T_1 V_11 ;
T_1 V_103 ;
int V_27 ;
V_11 = V_108 ;
if ( ! V_203 )
goto V_12;
V_11 = V_207 ;
if ( F_26 ( V_202 , V_203 ) )
goto V_12;
V_11 = F_31 ( V_2 , V_22 , V_33 , V_208 ) ;
if ( V_11 )
goto V_12;
V_3 = V_22 -> V_28 ;
V_206 = F_21 ( V_3 ) ;
V_11 = V_209 ;
if ( ! V_206 -> V_210 -> V_211 )
goto V_12;
if ( ! V_200 -> V_28 ) {
V_27 = F_46 ( V_22 ) ;
if ( V_27 )
goto V_30;
F_27 ( V_22 , V_31 ) ;
V_205 = F_28 ( V_202 , V_3 , V_203 ) ;
V_27 = F_7 ( V_205 ) ;
if ( F_6 ( V_205 ) )
goto V_30;
V_11 = F_33 ( V_200 , V_22 -> V_29 , V_205 , V_22 ) ;
if ( V_11 )
goto V_12;
} else {
V_205 = F_3 ( V_200 -> V_28 ) ;
if ( ! V_22 -> V_212 ) {
F_113 ( V_213
L_6 ,
V_3 ) ;
V_11 = V_214 ;
goto V_12;
}
}
V_11 = V_207 ;
if ( F_114 ( V_205 ) ) {
F_23 ( L_7 ,
V_3 , V_205 ) ;
goto V_12;
}
if ( ! ( V_42 -> V_43 & V_44 ) )
V_42 -> V_45 = 0 ;
V_42 -> V_45 = ( V_42 -> V_45 & V_46 ) | type ;
V_11 = V_90 ;
if ( ! F_58 ( type ) && ! F_39 ( type ) && ! F_115 ( type ) ) {
F_113 ( V_215 L_8 ,
type ) ;
goto V_12;
}
V_11 = 0 ;
V_27 = 0 ;
switch ( type ) {
case V_73 :
V_27 = F_116 ( V_206 , V_205 , V_42 -> V_45 , true ) ;
if ( ! V_27 )
F_111 ( V_42 ) ;
break;
case V_33 :
V_27 = F_117 ( V_206 , V_205 , V_42 -> V_45 ) ;
break;
case V_216 :
case V_217 :
case V_218 :
case V_219 :
V_27 = F_118 ( V_206 , V_205 , V_42 -> V_45 , V_204 ) ;
break;
}
if ( V_27 < 0 )
goto V_30;
V_11 = F_108 ( V_2 , V_200 , V_42 ) ;
V_103 = F_29 ( F_35 ( V_22 ) ) ;
if ( V_103 )
V_11 = V_103 ;
if ( ! V_11 )
V_11 = F_119 ( V_200 ) ;
V_12:
if ( V_205 && ! F_6 ( V_205 ) )
F_15 ( V_205 ) ;
return V_11 ;
V_30:
V_11 = F_29 ( V_27 ) ;
goto V_12;
}
T_1
F_120 ( struct V_1 * V_2 , struct V_21 * V_22 ,
char * V_202 , int V_203 , struct V_41 * V_42 ,
struct V_21 * V_200 , int V_220 , T_5 * V_221 ,
bool * V_222 , bool * V_223 )
{
struct V_3 * V_3 , * V_205 = NULL ;
struct V_36 * V_206 ;
T_1 V_11 ;
int V_27 ;
T_10 V_224 = 0 , V_225 = 0 ;
V_11 = V_108 ;
if ( ! V_203 )
goto V_12;
V_11 = V_207 ;
if ( F_26 ( V_202 , V_203 ) )
goto V_12;
if ( ! ( V_42 -> V_43 & V_44 ) )
V_42 -> V_45 = 0 ;
V_11 = F_31 ( V_2 , V_22 , V_33 , V_34 ) ;
if ( V_11 )
goto V_12;
V_3 = V_22 -> V_28 ;
V_206 = F_21 ( V_3 ) ;
V_11 = V_209 ;
if ( ! V_206 -> V_210 -> V_211 )
goto V_12;
V_27 = F_46 ( V_22 ) ;
if ( V_27 )
goto V_30;
F_27 ( V_22 , V_31 ) ;
V_205 = F_28 ( V_202 , V_3 , V_203 ) ;
V_27 = F_7 ( V_205 ) ;
if ( F_6 ( V_205 ) )
goto V_30;
if ( F_34 ( V_205 ) ) {
V_11 = F_31 ( V_2 , V_22 , V_33 , V_208 ) ;
if ( V_11 )
goto V_12;
}
V_11 = F_33 ( V_200 , V_22 -> V_29 , V_205 , V_22 ) ;
if ( V_11 )
goto V_12;
if ( F_121 ( V_220 ) ) {
V_224 = V_221 [ 0 ] & 0x7fffffff ;
V_225 = V_221 [ 1 ] & 0x7fffffff ;
}
if ( F_114 ( V_205 ) ) {
V_11 = 0 ;
switch ( V_220 ) {
case V_226 :
if ( ! F_62 ( V_205 ) )
goto V_12;
else if ( V_222 ) {
* V_222 = ( V_42 -> V_43 & V_71 ) && ! V_42 -> V_56 ;
}
else {
V_42 -> V_43 &= V_71 ;
goto V_227;
}
break;
case V_228 :
if ( F_21 ( V_205 ) -> V_229 . V_76 == V_224
&& F_21 ( V_205 ) -> V_230 . V_76 == V_225
&& F_21 ( V_205 ) -> V_57 == 0 ) {
if ( V_223 )
* V_223 = 1 ;
break;
}
case V_231 :
if ( F_21 ( V_205 ) -> V_229 . V_76 == V_224
&& F_21 ( V_205 ) -> V_230 . V_76 == V_225
&& F_21 ( V_205 ) -> V_57 == 0 ) {
if ( V_223 )
* V_223 = 1 ;
goto V_227;
}
case V_232 :
V_11 = V_207 ;
}
F_122 ( V_22 ) ;
goto V_12;
}
V_27 = F_116 ( V_206 , V_205 , V_42 -> V_45 , true ) ;
if ( V_27 < 0 ) {
F_122 ( V_22 ) ;
goto V_30;
}
if ( V_223 )
* V_223 = 1 ;
F_111 ( V_42 ) ;
if ( F_121 ( V_220 ) ) {
V_42 -> V_43 = V_70 | V_69
| V_233 | V_234 ;
V_42 -> V_235 . V_76 = V_224 ;
V_42 -> V_236 . V_76 = V_225 ;
V_42 -> V_235 . V_237 = 0 ;
V_42 -> V_236 . V_237 = 0 ;
}
V_227:
V_11 = F_108 ( V_2 , V_200 , V_42 ) ;
if ( ! V_11 )
V_11 = F_29 ( F_35 ( V_22 ) ) ;
if ( ! V_11 )
V_11 = F_119 ( V_200 ) ;
V_12:
F_51 ( V_22 ) ;
if ( V_205 && ! F_6 ( V_205 ) )
F_15 ( V_205 ) ;
F_122 ( V_22 ) ;
return V_11 ;
V_30:
V_11 = F_29 ( V_27 ) ;
goto V_12;
}
T_1
F_123 ( struct V_1 * V_2 , struct V_21 * V_22 , char * V_155 , int * V_238 )
{
struct V_36 * V_36 ;
T_9 V_174 ;
T_1 V_11 ;
int V_27 ;
struct V_8 V_8 ;
V_11 = F_31 ( V_2 , V_22 , V_239 , V_99 ) ;
if ( V_11 )
goto V_12;
V_8 . V_9 = V_22 -> V_29 -> V_10 . V_9 ;
V_8 . V_3 = V_22 -> V_28 ;
V_36 = F_21 ( V_8 . V_3 ) ;
V_11 = V_90 ;
if ( ! V_36 -> V_210 -> V_240 )
goto V_12;
F_124 ( & V_8 ) ;
V_174 = F_89 () ; F_90 ( V_175 ) ;
V_27 = V_36 -> V_210 -> V_240 ( V_8 . V_3 , ( char V_177 * ) V_155 , * V_238 ) ;
F_90 ( V_174 ) ;
if ( V_27 < 0 )
goto V_30;
* V_238 = V_27 ;
V_11 = 0 ;
V_12:
return V_11 ;
V_30:
V_11 = F_29 ( V_27 ) ;
goto V_12;
}
T_1
F_125 ( struct V_1 * V_2 , struct V_21 * V_22 ,
char * V_202 , int V_203 ,
char * V_8 ,
struct V_21 * V_200 )
{
struct V_3 * V_3 , * V_241 ;
T_1 V_11 , V_242 ;
int V_27 ;
V_11 = V_35 ;
if ( ! V_203 || V_8 [ 0 ] == '\0' )
goto V_12;
V_11 = V_207 ;
if ( F_26 ( V_202 , V_203 ) )
goto V_12;
V_11 = F_31 ( V_2 , V_22 , V_33 , V_208 ) ;
if ( V_11 )
goto V_12;
V_27 = F_46 ( V_22 ) ;
if ( V_27 )
goto V_30;
F_49 ( V_22 ) ;
V_3 = V_22 -> V_28 ;
V_241 = F_28 ( V_202 , V_3 , V_203 ) ;
V_27 = F_7 ( V_241 ) ;
if ( F_6 ( V_241 ) )
goto V_30;
V_27 = F_126 ( F_21 ( V_3 ) , V_241 , V_8 ) ;
V_11 = F_29 ( V_27 ) ;
if ( ! V_11 )
V_11 = F_29 ( F_35 ( V_22 ) ) ;
F_51 ( V_22 ) ;
F_122 ( V_22 ) ;
V_242 = F_33 ( V_200 , V_22 -> V_29 , V_241 , V_22 ) ;
F_15 ( V_241 ) ;
if ( V_11 == 0 ) V_11 = V_242 ;
V_12:
return V_11 ;
V_30:
V_11 = F_29 ( V_27 ) ;
goto V_12;
}
T_1
F_127 ( struct V_1 * V_2 , struct V_21 * V_243 ,
char * V_23 , int V_24 , struct V_21 * V_244 )
{
struct V_3 * V_245 , * V_241 , * V_246 ;
struct V_36 * V_206 ;
T_1 V_11 ;
int V_27 ;
V_11 = F_31 ( V_2 , V_243 , V_33 , V_208 ) ;
if ( V_11 )
goto V_12;
V_11 = F_31 ( V_2 , V_244 , 0 , V_99 ) ;
if ( V_11 )
goto V_12;
V_11 = V_247 ;
if ( F_63 ( V_244 -> V_28 ) )
goto V_12;
V_11 = V_108 ;
if ( ! V_24 )
goto V_12;
V_11 = V_207 ;
if ( F_26 ( V_23 , V_24 ) )
goto V_12;
V_27 = F_46 ( V_244 ) ;
if ( V_27 ) {
V_11 = F_29 ( V_27 ) ;
goto V_12;
}
F_27 ( V_243 , V_31 ) ;
V_245 = V_243 -> V_28 ;
V_206 = F_21 ( V_245 ) ;
V_241 = F_28 ( V_23 , V_245 , V_24 ) ;
V_27 = F_7 ( V_241 ) ;
if ( F_6 ( V_241 ) )
goto V_30;
V_246 = V_244 -> V_28 ;
V_11 = V_35 ;
if ( F_34 ( V_246 ) )
goto V_248;
V_27 = F_128 ( V_246 , V_206 , V_241 , NULL ) ;
if ( ! V_27 ) {
V_11 = F_29 ( F_35 ( V_243 ) ) ;
if ( ! V_11 )
V_11 = F_29 ( F_35 ( V_244 ) ) ;
} else {
if ( V_27 == - V_249 && V_2 -> V_197 == 2 )
V_11 = V_107 ;
else
V_11 = F_29 ( V_27 ) ;
}
V_248:
F_15 ( V_241 ) ;
V_250:
F_51 ( V_243 ) ;
F_122 ( V_244 ) ;
V_12:
return V_11 ;
V_30:
V_11 = F_29 ( V_27 ) ;
goto V_250;
}
T_1
F_129 ( struct V_1 * V_2 , struct V_21 * V_243 , char * V_202 , int V_203 ,
struct V_21 * V_244 , char * V_251 , int V_252 )
{
struct V_3 * V_253 , * V_254 , * V_255 , * V_256 , * V_257 ;
struct V_36 * V_258 , * V_259 ;
T_1 V_11 ;
int V_27 ;
V_11 = F_31 ( V_2 , V_243 , V_33 , V_260 ) ;
if ( V_11 )
goto V_12;
V_11 = F_31 ( V_2 , V_244 , V_33 , V_208 ) ;
if ( V_11 )
goto V_12;
V_253 = V_243 -> V_28 ;
V_258 = F_21 ( V_253 ) ;
V_254 = V_244 -> V_28 ;
V_259 = F_21 ( V_254 ) ;
V_11 = V_108 ;
if ( ! V_203 || F_26 ( V_202 , V_203 ) || ! V_252 || F_26 ( V_251 , V_252 ) )
goto V_12;
V_27 = F_46 ( V_243 ) ;
if ( V_27 ) {
V_11 = F_29 ( V_27 ) ;
goto V_12;
}
V_257 = F_130 ( V_254 , V_253 ) ;
V_243 -> V_212 = V_244 -> V_212 = 1 ;
F_131 ( V_243 ) ;
F_131 ( V_244 ) ;
V_255 = F_28 ( V_202 , V_253 , V_203 ) ;
V_27 = F_7 ( V_255 ) ;
if ( F_6 ( V_255 ) )
goto V_30;
V_27 = - V_13 ;
if ( F_34 ( V_255 ) )
goto V_261;
V_27 = - V_199 ;
if ( V_255 == V_257 )
goto V_261;
V_256 = F_28 ( V_251 , V_254 , V_252 ) ;
V_27 = F_7 ( V_256 ) ;
if ( F_6 ( V_256 ) )
goto V_261;
V_27 = - V_262 ;
if ( V_256 == V_257 )
goto V_263;
V_27 = - V_249 ;
if ( V_243 -> V_29 -> V_10 . V_9 != V_244 -> V_29 -> V_10 . V_9 )
goto V_263;
if ( V_243 -> V_29 -> V_10 . V_3 != V_244 -> V_29 -> V_10 . V_3 )
goto V_263;
V_27 = F_132 ( V_258 , V_255 , V_259 , V_256 , NULL , 0 ) ;
if ( ! V_27 ) {
V_27 = F_35 ( V_244 ) ;
if ( ! V_27 )
V_27 = F_35 ( V_243 ) ;
}
V_263:
F_15 ( V_256 ) ;
V_261:
F_15 ( V_255 ) ;
V_30:
V_11 = F_29 ( V_27 ) ;
F_133 ( V_243 ) ;
F_133 ( V_244 ) ;
F_134 ( V_254 , V_253 ) ;
V_243 -> V_212 = V_244 -> V_212 = 0 ;
F_122 ( V_243 ) ;
V_12:
return V_11 ;
}
T_1
F_135 ( struct V_1 * V_2 , struct V_21 * V_22 , int type ,
char * V_202 , int V_203 )
{
struct V_3 * V_3 , * V_264 ;
struct V_36 * V_206 ;
T_1 V_11 ;
int V_27 ;
V_11 = V_107 ;
if ( ! V_203 || F_26 ( V_202 , V_203 ) )
goto V_12;
V_11 = F_31 ( V_2 , V_22 , V_33 , V_260 ) ;
if ( V_11 )
goto V_12;
V_27 = F_46 ( V_22 ) ;
if ( V_27 )
goto V_30;
F_27 ( V_22 , V_31 ) ;
V_3 = V_22 -> V_28 ;
V_206 = F_21 ( V_3 ) ;
V_264 = F_28 ( V_202 , V_3 , V_203 ) ;
V_27 = F_7 ( V_264 ) ;
if ( F_6 ( V_264 ) )
goto V_30;
if ( F_34 ( V_264 ) ) {
F_15 ( V_264 ) ;
V_11 = V_35 ;
goto V_12;
}
if ( ! type )
type = F_21 ( V_264 ) -> V_47 & V_265 ;
if ( type != V_33 )
V_27 = F_136 ( V_206 , V_264 , NULL ) ;
else
V_27 = F_137 ( V_206 , V_264 ) ;
if ( ! V_27 )
V_27 = F_35 ( V_22 ) ;
F_15 ( V_264 ) ;
V_30:
V_11 = F_29 ( V_27 ) ;
V_12:
return V_11 ;
}
static int F_138 ( struct V_266 * V_267 , const char * V_23 ,
int V_268 , T_4 V_88 , T_11 V_127 ,
unsigned int V_269 )
{
struct V_270 * V_155 =
F_139 ( V_267 , struct V_270 , V_267 ) ;
struct V_271 * V_272 = ( void * ) ( V_155 -> V_273 + V_155 -> V_274 ) ;
unsigned int V_275 ;
V_275 = F_140 ( sizeof( struct V_271 ) + V_268 , sizeof( T_11 ) ) ;
if ( V_155 -> V_274 + V_275 > V_276 ) {
V_155 -> V_277 = 1 ;
return - V_199 ;
}
V_272 -> V_268 = V_268 ;
V_272 -> V_88 = V_88 ;
V_272 -> V_127 = V_127 ;
V_272 -> V_269 = V_269 ;
memcpy ( V_272 -> V_23 , V_23 , V_268 ) ;
V_155 -> V_274 += V_275 ;
return 0 ;
}
static T_1 F_141 ( struct V_87 * V_87 , T_12 V_278 ,
struct V_279 * V_280 , T_4 * V_281 )
{
struct V_271 * V_272 ;
int V_27 ;
int V_162 ;
T_4 V_88 ;
struct V_270 V_155 = {
. V_267 . V_282 = F_138 ,
. V_273 = ( void * ) F_142 (GFP_KERNEL)
} ;
if ( ! V_155 . V_273 )
return F_29 ( - V_283 ) ;
V_88 = * V_281 ;
while ( 1 ) {
struct V_36 * V_284 = F_59 ( V_87 ) ;
unsigned int V_275 ;
V_280 -> V_11 = V_285 ;
V_155 . V_274 = 0 ;
V_155 . V_277 = 0 ;
V_27 = F_143 ( V_87 , & V_155 . V_267 ) ;
if ( V_155 . V_277 )
V_27 = 0 ;
if ( V_27 < 0 )
break;
V_162 = V_155 . V_274 ;
if ( ! V_162 )
break;
V_27 = F_144 ( & V_284 -> V_84 ) ;
if ( V_27 )
break;
V_272 = (struct V_271 * ) V_155 . V_273 ;
while ( V_162 > 0 ) {
V_88 = V_272 -> V_88 ;
if ( V_278 ( V_280 , V_272 -> V_23 , V_272 -> V_268 , V_272 -> V_88 ,
V_272 -> V_127 , V_272 -> V_269 ) )
break;
if ( V_280 -> V_11 != V_105 )
break;
V_275 = F_140 ( sizeof( * V_272 ) + V_272 -> V_268 ,
sizeof( T_11 ) ) ;
V_162 -= V_275 ;
V_272 = (struct V_271 * ) ( ( char * ) V_272 + V_275 ) ;
}
F_56 ( & V_284 -> V_84 ) ;
if ( V_162 > 0 )
break;
V_88 = F_145 ( V_87 , 0 , V_286 ) ;
}
F_146 ( ( unsigned long ) ( V_155 . V_273 ) ) ;
if ( V_27 )
return F_29 ( V_27 ) ;
* V_281 = V_88 ;
return V_280 -> V_11 ;
}
T_1
F_147 ( struct V_1 * V_2 , struct V_21 * V_22 , T_4 * V_281 ,
struct V_279 * V_280 , T_12 V_278 )
{
T_1 V_11 ;
struct V_87 * V_87 ;
T_4 V_88 = * V_281 ;
int V_114 = V_118 ;
if ( V_2 -> V_197 > 2 )
V_114 |= V_120 ;
V_11 = F_66 ( V_2 , V_22 , V_33 , V_114 , & V_87 ) ;
if ( V_11 )
goto V_12;
V_88 = F_145 ( V_87 , V_88 , V_287 ) ;
if ( V_88 < 0 ) {
V_11 = F_29 ( ( int ) V_88 ) ;
goto V_288;
}
V_11 = F_141 ( V_87 , V_278 , V_280 , V_281 ) ;
if ( V_11 == V_285 || V_11 == V_289 )
V_11 = V_105 ;
V_288:
F_73 ( V_87 ) ;
V_12:
return V_11 ;
}
T_1
F_148 ( struct V_1 * V_2 , struct V_21 * V_22 , struct V_290 * V_291 , int V_91 )
{
T_1 V_11 ;
V_11 = F_31 ( V_2 , V_22 , 0 , V_99 | V_91 ) ;
if ( ! V_11 ) {
struct V_8 V_8 = {
. V_9 = V_22 -> V_29 -> V_10 . V_9 ,
. V_3 = V_22 -> V_28 ,
} ;
if ( F_149 ( & V_8 , V_291 ) )
V_11 = V_214 ;
}
return V_11 ;
}
static int F_150 ( struct V_1 * V_2 , struct V_5 * exp )
{
return F_151 ( V_2 , exp ) & V_292 ;
}
T_1
F_41 ( struct V_1 * V_2 , struct V_5 * exp ,
struct V_3 * V_3 , int V_293 )
{
struct V_36 * V_36 = F_21 ( V_3 ) ;
int V_11 ;
if ( ( V_293 & V_294 ) == V_99 )
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
if ( ! ( V_293 & V_295 ) )
if ( V_293 & ( V_72 | V_65 | V_58 ) ) {
if ( F_150 ( V_2 , exp ) ||
F_152 ( exp -> V_10 . V_9 ) )
return V_106 ;
if ( F_153 ( V_36 ) )
return V_108 ;
}
if ( ( V_293 & V_58 ) && F_68 ( V_36 ) )
return V_108 ;
if ( V_293 & V_296 ) {
if ( exp -> V_14 & V_297 )
return 0 ;
else
V_293 = V_118 | V_59 ;
}
if ( ( V_293 & V_59 ) &&
F_109 ( V_36 -> V_298 , F_110 () ) )
return 0 ;
V_11 = F_154 ( V_36 , V_293 & ( V_299 | V_300 | V_301 ) ) ;
if ( V_11 == - V_302 && F_58 ( V_36 -> V_47 ) &&
( V_293 == ( V_118 | V_59 ) ||
V_293 == ( V_118 | V_303 ) ) )
V_11 = F_154 ( V_36 , V_301 ) ;
return V_11 ? F_29 ( V_11 ) : 0 ;
}
void
F_155 ( void )
{
struct V_124 * V_304 , * V_305 ;
unsigned int V_306 ;
F_23 ( L_9 ) ;
for ( V_306 = 0 ; V_306 < V_307 ; V_306 ++ ) {
V_304 = V_137 [ V_306 ] . V_139 ;
while( V_304 ) {
V_305 = V_304 ;
V_304 = V_304 -> V_140 ;
F_156 ( V_305 ) ;
}
V_137 [ V_306 ] . V_139 = NULL ;
}
}
int
F_157 ( int V_308 )
{
int V_306 ;
int V_309 = 0 ;
int V_310 ;
struct V_124 * * V_304 = NULL ;
if ( V_137 [ 0 ] . V_139 )
return 0 ;
V_310 = F_158 ( V_308 , V_307 ) ;
V_310 = F_159 ( 2 , V_310 ) ;
V_308 = V_310 * V_307 ;
F_23 ( L_10 , V_308 ) ;
for ( V_306 = 0 ; V_306 < V_307 ; V_306 ++ ) {
F_160 ( & V_137 [ V_306 ] . V_138 ) ;
V_304 = & V_137 [ V_306 ] . V_139 ;
for ( V_309 = 0 ; V_309 < V_310 ; V_309 ++ ) {
* V_304 = F_161 ( sizeof( struct V_124 ) , V_311 ) ;
if ( ! * V_304 )
goto V_312;
V_304 = & ( * V_304 ) -> V_140 ;
}
* V_304 = NULL ;
}
V_145 . V_146 = V_308 ;
return 0 ;
V_312:
F_23 ( L_11 ) ;
F_155 () ;
return - V_283 ;
}

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
F_29 ( V_22 ) ;
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
return F_30 ( V_27 ) ;
}
T_1
F_31 ( struct V_1 * V_2 , struct V_21 * V_22 , const char * V_23 ,
unsigned int V_24 , struct V_21 * V_32 )
{
struct V_5 * exp ;
struct V_3 * V_3 ;
T_1 V_11 ;
V_11 = F_32 ( V_2 , V_22 , V_33 , V_34 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_22 ( V_2 , V_22 , V_23 , V_24 , & exp , & V_3 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_33 ( exp , V_2 ) ;
if ( V_11 )
goto V_12;
V_11 = F_34 ( V_32 , exp , V_3 , V_22 ) ;
if ( ! V_11 && F_35 ( V_3 ) )
V_11 = V_35 ;
V_12:
F_15 ( V_3 ) ;
F_11 ( exp ) ;
return V_11 ;
}
static int
F_36 ( struct V_21 * V_22 )
{
struct V_36 * V_36 = F_21 ( V_22 -> V_28 ) ;
const struct V_37 * V_38 = V_36 -> V_39 -> V_40 ;
if ( ! F_37 ( V_22 -> V_29 ) )
return 0 ;
if ( V_38 -> F_36 )
return V_38 -> F_36 ( V_36 ) ;
return F_38 ( V_36 , 1 ) ;
}
static void
F_39 ( struct V_36 * V_36 , struct V_41 * V_42 )
{
if ( V_42 -> V_43 & V_44 ) {
V_42 -> V_45 &= V_46 ;
V_42 -> V_45 |= ( V_36 -> V_47 & ~ V_46 ) ;
}
if ( ! F_40 ( V_36 -> V_47 ) &&
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
F_41 ( struct V_1 * V_2 , struct V_21 * V_22 ,
struct V_41 * V_42 )
{
struct V_36 * V_36 = F_21 ( V_22 -> V_28 ) ;
int V_27 ;
if ( V_42 -> V_56 < V_36 -> V_57 ) {
T_1 V_11 ;
V_11 = F_42 ( V_2 , V_22 -> V_29 , V_22 -> V_28 ,
V_58 | V_59 ) ;
if ( V_11 )
return V_11 ;
}
V_27 = F_43 ( V_36 ) ;
if ( V_27 )
goto V_60;
V_27 = F_44 ( V_36 , NULL , V_42 -> V_56 ) ;
if ( V_27 )
goto V_61;
return 0 ;
V_61:
F_45 ( V_36 ) ;
V_60:
return F_30 ( V_27 ) ;
}
T_1
F_46 ( struct V_1 * V_2 , struct V_21 * V_22 , struct V_41 * V_42 ,
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
V_11 = F_32 ( V_2 , V_22 , V_66 , V_64 ) ;
if ( V_11 )
goto V_12;
if ( V_67 ) {
V_27 = F_47 ( V_22 ) ;
if ( V_27 )
return F_30 ( V_27 ) ;
}
V_3 = V_22 -> V_28 ;
V_36 = F_21 ( V_3 ) ;
if ( F_48 ( V_36 -> V_47 ) )
V_42 -> V_43 &= ~ V_44 ;
if ( ! V_42 -> V_43 )
goto V_12;
F_39 ( V_36 , V_42 ) ;
if ( V_42 -> V_43 & V_71 ) {
V_11 = F_41 ( V_2 , V_22 , V_42 ) ;
if ( V_11 )
goto V_12;
V_68 = 1 ;
if ( V_42 -> V_56 != F_49 ( V_36 ) )
V_42 -> V_43 |= V_70 ;
}
V_42 -> V_43 |= V_74 ;
if ( V_62 && V_63 != V_36 -> V_75 . V_76 ) {
V_11 = V_77 ;
goto V_61;
}
F_50 ( V_22 ) ;
V_27 = F_51 ( V_3 , V_42 , NULL ) ;
F_29 ( V_22 ) ;
V_11 = F_30 ( V_27 ) ;
V_61:
if ( V_68 )
F_45 ( V_36 ) ;
if ( ! V_11 )
V_11 = F_30 ( F_36 ( V_22 ) ) ;
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
error = F_32 ( V_2 , V_22 , 0 , V_65 ) ;
if ( error )
return error ;
V_3 = V_22 -> V_28 ;
F_54 ( F_21 ( V_3 ) ) ;
V_83 = F_55 ( V_3 , V_82 -> V_84 , V_82 -> V_24 ) ;
F_56 ( F_21 ( V_3 ) ) ;
return F_30 ( V_83 ) ;
}
T_1 F_53 ( struct V_1 * V_2 , struct V_21 * V_22 ,
struct V_81 * V_82 )
{
return V_85 ;
}
T_1 F_57 ( struct V_86 * V_87 , T_4 V_88 , struct V_86 * V_89 ,
T_4 V_90 , T_4 V_91 )
{
return F_30 ( F_58 ( V_87 , V_88 , V_89 , V_90 , V_91 ) ) ;
}
T_5 F_59 ( struct V_86 * V_87 , T_4 V_88 , struct V_86 * V_89 ,
T_4 V_90 , T_4 V_91 )
{
V_91 = F_60 ( T_4 , V_91 , 1 << 22 ) ;
return F_61 ( V_87 , V_88 , V_89 , V_90 , V_91 , 0 ) ;
}
T_1 F_62 ( struct V_1 * V_2 , struct V_21 * V_22 ,
struct V_86 * V_86 , T_6 V_92 , T_6 V_24 ,
int V_93 )
{
int error ;
if ( ! F_63 ( F_64 ( V_86 ) -> V_47 ) )
return V_94 ;
error = F_65 ( V_86 , V_93 , V_92 , V_24 ) ;
if ( ! error )
error = F_36 ( V_22 ) ;
return F_30 ( error ) ;
}
T_1
F_66 ( struct V_1 * V_2 , struct V_21 * V_22 , T_7 * V_95 , T_7 * V_96 )
{
struct V_97 * V_98 ;
struct V_5 * V_99 ;
struct V_3 * V_3 ;
T_7 V_100 , V_101 = 0 , V_102 = 0 ;
T_1 error ;
error = F_32 ( V_2 , V_22 , 0 , V_103 ) ;
if ( error )
goto V_12;
V_99 = V_22 -> V_29 ;
V_3 = V_22 -> V_28 ;
if ( F_67 ( V_3 ) )
V_98 = V_104 ;
else if ( F_68 ( V_3 ) )
V_98 = V_105 ;
else
V_98 = V_106 ;
V_100 = * V_95 ;
for (; V_98 -> V_95 ; V_98 ++ ) {
if ( V_98 -> V_95 & V_100 ) {
T_1 V_107 ;
V_102 |= V_98 -> V_95 ;
V_107 = F_42 ( V_2 , V_99 , V_3 , V_98 -> V_108 ) ;
switch ( V_107 ) {
case V_109 :
V_101 |= V_98 -> V_95 ;
break;
case V_110 :
case V_111 :
case V_112 :
break;
default:
error = V_107 ;
goto V_12;
}
}
}
* V_95 = V_101 ;
if ( V_96 )
* V_96 = V_102 ;
V_12:
return error ;
}
static int F_69 ( struct V_36 * V_36 , int V_95 )
{
unsigned int V_113 ;
if ( V_95 & V_114 )
return 0 ;
V_113 = ( V_95 & V_72 ) ? V_115 : V_116 ;
return F_70 ( V_36 , V_113 | V_117 ) ;
}
T_1
F_71 ( struct V_1 * V_2 , struct V_21 * V_22 , T_3 type ,
int V_118 , struct V_86 * * V_119 )
{
struct V_8 V_8 ;
struct V_36 * V_36 ;
struct V_86 * V_86 ;
int V_93 = V_116 | V_120 ;
T_1 V_11 ;
int V_27 = 0 ;
F_72 () ;
if ( type == V_73 )
V_118 |= V_59 ;
V_11 = F_32 ( V_2 , V_22 , type , V_118 ) ;
if ( V_11 )
goto V_12;
V_8 . V_9 = V_22 -> V_29 -> V_10 . V_9 ;
V_8 . V_3 = V_22 -> V_28 ;
V_36 = F_21 ( V_8 . V_3 ) ;
V_11 = V_112 ;
if ( F_73 ( V_36 ) && ( V_118 & V_72 ) )
goto V_12;
if ( F_63 ( ( V_36 ) -> V_47 ) && F_74 ( V_36 ) )
goto V_12;
if ( ! V_36 -> V_121 )
goto V_12;
V_27 = F_69 ( V_36 , V_118 ) ;
if ( V_27 )
goto V_30;
if ( V_118 & V_72 ) {
if ( V_118 & V_122 )
V_93 = V_123 | V_120 ;
else
V_93 = V_115 | V_120 ;
}
V_86 = F_75 ( & V_8 , V_93 , F_76 () ) ;
if ( F_6 ( V_86 ) ) {
V_27 = F_7 ( V_86 ) ;
goto V_30;
}
V_27 = F_77 ( V_86 , V_118 , 0 ) ;
if ( V_27 ) {
F_78 ( V_86 ) ;
goto V_30;
}
if ( V_118 & V_124 )
V_86 -> V_125 |= V_126 ;
else
V_86 -> V_125 |= V_127 ;
* V_119 = V_86 ;
V_30:
V_11 = F_30 ( V_27 ) ;
V_12:
F_72 () ;
return V_11 ;
}
struct V_128 *
F_79 ( struct V_86 * V_86 )
{
struct V_36 * V_36 = F_64 ( V_86 ) ;
T_8 V_129 = V_36 -> V_39 -> V_130 ;
T_9 V_131 = V_36 -> V_132 ;
struct V_128 * V_133 , * * V_134 , * * V_135 = NULL ;
int V_136 = 0 ;
unsigned int V_137 ;
struct V_138 * V_139 ;
V_137 = F_80 ( V_129 , V_131 , 0xfeedbeef ) & V_140 ;
V_139 = & V_141 [ V_137 ] ;
F_81 ( & V_139 -> V_142 ) ;
for ( V_134 = & V_139 -> V_143 ; ( V_133 = * V_134 ) ; V_134 = & V_133 -> V_144 ) {
if ( V_133 -> V_145 == V_131 && V_133 -> V_146 == V_129 )
goto V_147;
V_136 ++ ;
if ( V_133 -> V_148 == 0 )
V_135 = V_134 ;
}
V_136 = V_149 . V_150 ;
if ( ! V_135 ) {
F_82 ( & V_139 -> V_142 ) ;
return NULL ;
}
V_134 = V_135 ;
V_133 = * V_135 ;
V_133 -> V_146 = V_129 ;
V_133 -> V_145 = V_131 ;
V_133 -> V_151 = 0 ;
V_133 -> V_152 = V_137 ;
V_147:
if ( V_134 != & V_139 -> V_143 ) {
* V_134 = V_133 -> V_144 ;
V_133 -> V_144 = V_139 -> V_143 ;
V_139 -> V_143 = V_133 ;
}
V_133 -> V_148 ++ ;
V_149 . V_153 [ V_136 * 10 / V_149 . V_150 ] ++ ;
F_82 ( & V_139 -> V_142 ) ;
if ( V_133 -> V_151 )
V_86 -> V_154 = V_133 -> V_155 ;
return V_133 ;
}
void F_83 ( struct V_86 * V_86 , struct V_128 * V_133 )
{
struct V_138 * V_139 = & V_141 [ V_133 -> V_152 ] ;
F_81 ( & V_139 -> V_142 ) ;
V_133 -> V_155 = V_86 -> V_154 ;
V_133 -> V_151 = 1 ;
V_133 -> V_148 -- ;
F_82 ( & V_139 -> V_142 ) ;
}
static int
F_84 ( struct V_156 * V_157 , struct V_158 * V_159 ,
struct V_160 * V_161 )
{
struct V_1 * V_2 = V_161 -> V_162 . V_84 ;
struct V_163 * * V_164 = V_2 -> V_165 ;
struct V_163 * V_163 = V_159 -> V_163 ;
T_10 V_166 ;
V_166 = V_161 -> V_24 ;
if ( V_2 -> V_167 . V_168 == 0 ) {
F_85 ( V_163 ) ;
F_86 ( * V_2 -> V_165 ) ;
* ( V_2 -> V_165 ++ ) = V_163 ;
V_2 -> V_167 . V_169 = V_159 -> V_92 ;
V_2 -> V_167 . V_168 = V_166 ;
} else if ( V_163 != V_164 [ - 1 ] ) {
F_85 ( V_163 ) ;
if ( * V_2 -> V_165 )
F_86 ( * V_2 -> V_165 ) ;
* ( V_2 -> V_165 ++ ) = V_163 ;
V_2 -> V_167 . V_168 += V_166 ;
} else
V_2 -> V_167 . V_168 += V_166 ;
return V_166 ;
}
static int F_87 ( struct V_156 * V_157 ,
struct V_160 * V_161 )
{
return F_88 ( V_157 , V_161 , F_84 ) ;
}
static T_1
F_89 ( struct V_86 * V_86 , unsigned long * V_91 , int V_27 )
{
if ( V_27 >= 0 ) {
V_149 . V_170 += V_27 ;
* V_91 = V_27 ;
F_90 ( V_86 ) ;
return 0 ;
} else
return F_30 ( V_27 ) ;
}
T_1 F_91 ( struct V_1 * V_2 ,
struct V_86 * V_86 , T_6 V_92 , unsigned long * V_91 )
{
struct V_160 V_161 = {
. V_24 = 0 ,
. V_171 = * V_91 ,
. V_172 = V_92 ,
. V_162 . V_84 = V_2 ,
} ;
int V_27 ;
V_2 -> V_165 = V_2 -> V_173 + 1 ;
V_27 = F_92 ( V_86 , & V_161 , F_87 ) ;
return F_89 ( V_86 , V_91 , V_27 ) ;
}
T_1 F_93 ( struct V_86 * V_86 , T_6 V_92 , struct V_174 * V_175 , int V_176 ,
unsigned long * V_91 )
{
T_11 V_177 ;
int V_27 ;
V_177 = F_94 () ;
F_95 ( V_178 ) ;
V_27 = F_96 ( V_86 , (struct V_179 V_180 * ) V_175 , V_176 , & V_92 , 0 ) ;
F_95 ( V_177 ) ;
return F_89 ( V_86 , V_91 , V_27 ) ;
}
static T_1
F_97 ( struct V_1 * V_2 , struct V_86 * V_86 ,
T_6 V_92 , struct V_174 * V_175 , int V_176 , unsigned long * V_91 )
{
if ( V_86 -> V_181 -> V_182 && F_98 ( V_183 , & V_2 -> V_184 ) )
return F_91 ( V_2 , V_86 , V_92 , V_91 ) ;
else
return F_93 ( V_86 , V_92 , V_175 , V_176 , V_91 ) ;
}
static int F_99 ( struct V_86 * V_86 )
{
struct V_36 * V_36 = F_64 ( V_86 ) ;
static T_9 V_185 ;
static T_8 V_186 ;
int V_11 = 0 ;
if ( F_100 ( & V_36 -> V_187 ) > 1
|| ( V_185 == V_36 -> V_132 && V_186 == V_36 -> V_39 -> V_130 ) ) {
F_23 ( L_2 , F_101 ( V_188 ) ) ;
F_102 ( 10 ) ;
F_23 ( L_3 , F_101 ( V_188 ) ) ;
}
if ( V_36 -> V_189 & V_190 ) {
F_23 ( L_4 , F_101 ( V_188 ) ) ;
V_11 = F_103 ( V_86 , 0 ) ;
}
V_185 = V_36 -> V_132 ;
V_186 = V_36 -> V_39 -> V_130 ;
return V_11 ;
}
T_1
F_104 ( struct V_1 * V_2 , struct V_21 * V_22 , struct V_86 * V_86 ,
T_6 V_92 , struct V_174 * V_175 , int V_176 ,
unsigned long * V_191 , int * V_192 )
{
struct V_5 * exp ;
struct V_36 * V_36 ;
T_11 V_177 ;
T_1 V_11 = 0 ;
int V_27 ;
int V_193 = * V_192 ;
int V_194 ;
T_6 V_172 = V_92 ;
unsigned int V_195 = V_188 -> V_93 ;
int V_93 = 0 ;
if ( F_98 ( V_196 , & V_2 -> V_184 ) )
V_188 -> V_93 |= V_197 ;
V_36 = F_64 ( V_86 ) ;
exp = V_22 -> V_29 ;
V_194 = ( V_2 -> V_198 == 2 ) && F_105 ( exp ) ;
if ( ! F_37 ( exp ) )
V_193 = 0 ;
if ( V_193 && ! V_194 )
V_93 |= V_199 ;
V_177 = F_94 () ; F_95 ( V_178 ) ;
V_27 = F_106 ( V_86 , (struct V_179 V_180 * ) V_175 , V_176 , & V_172 , V_93 ) ;
F_95 ( V_177 ) ;
if ( V_27 < 0 )
goto V_30;
* V_191 = V_27 ;
V_149 . V_200 += V_27 ;
F_107 ( V_86 ) ;
if ( V_193 && V_194 )
V_27 = F_99 ( V_86 ) ;
V_30:
F_23 ( L_5 , V_27 ) ;
if ( V_27 >= 0 )
V_11 = 0 ;
else
V_11 = F_30 ( V_27 ) ;
if ( F_98 ( V_196 , & V_2 -> V_184 ) )
F_108 ( V_188 , V_195 , V_197 ) ;
return V_11 ;
}
T_1 F_109 ( struct V_1 * V_2 , struct V_21 * V_22 ,
T_6 V_92 , struct V_174 * V_175 , int V_176 , unsigned long * V_91 )
{
struct V_86 * V_86 ;
struct V_128 * V_133 ;
T_1 V_11 ;
F_110 ( V_2 , V_22 , V_92 , V_176 ) ;
V_11 = F_71 ( V_2 , V_22 , V_73 , V_122 , & V_86 ) ;
if ( V_11 )
return V_11 ;
V_133 = F_79 ( V_86 ) ;
F_111 ( V_2 , V_22 , V_92 , V_176 ) ;
V_11 = F_97 ( V_2 , V_86 , V_92 , V_175 , V_176 , V_91 ) ;
F_112 ( V_2 , V_22 , V_92 , V_176 ) ;
if ( V_133 )
F_83 ( V_86 , V_133 ) ;
F_78 ( V_86 ) ;
F_113 ( V_2 , V_22 , V_92 , V_176 ) ;
return V_11 ;
}
T_1
F_114 ( struct V_1 * V_2 , struct V_21 * V_22 , struct V_86 * V_86 ,
T_6 V_92 , struct V_174 * V_175 , int V_176 , unsigned long * V_191 ,
int * V_192 )
{
T_1 V_11 = 0 ;
F_115 ( V_2 , V_22 , V_92 , V_176 ) ;
if ( V_86 ) {
V_11 = F_42 ( V_2 , V_22 -> V_29 , V_22 -> V_28 ,
V_72 | V_59 ) ;
if ( V_11 )
goto V_12;
F_116 ( V_2 , V_22 , V_92 , V_176 ) ;
V_11 = F_104 ( V_2 , V_22 , V_86 , V_92 , V_175 , V_176 , V_191 ,
V_192 ) ;
F_117 ( V_2 , V_22 , V_92 , V_176 ) ;
} else {
V_11 = F_71 ( V_2 , V_22 , V_73 , V_72 , & V_86 ) ;
if ( V_11 )
goto V_12;
F_116 ( V_2 , V_22 , V_92 , V_176 ) ;
if ( V_191 )
V_11 = F_104 ( V_2 , V_22 , V_86 , V_92 , V_175 , V_176 ,
V_191 , V_192 ) ;
F_117 ( V_2 , V_22 , V_92 , V_176 ) ;
F_78 ( V_86 ) ;
}
V_12:
F_118 ( V_2 , V_22 , V_92 , V_176 ) ;
return V_11 ;
}
T_1
F_119 ( struct V_1 * V_2 , struct V_21 * V_22 ,
T_6 V_92 , unsigned long V_91 )
{
struct V_86 * V_86 ;
T_6 V_201 = V_202 ;
T_1 V_11 = V_94 ;
if ( V_92 < 0 )
goto V_12;
if ( V_91 != 0 ) {
V_201 = V_92 + ( T_6 ) V_91 - 1 ;
if ( V_201 < V_92 )
goto V_12;
}
V_11 = F_71 ( V_2 , V_22 , V_73 ,
V_72 | V_114 , & V_86 ) ;
if ( V_11 )
goto V_12;
if ( F_37 ( V_22 -> V_29 ) ) {
int V_107 = F_120 ( V_86 , V_92 , V_201 , 0 ) ;
if ( V_107 != - V_203 )
V_11 = F_30 ( V_107 ) ;
else
V_11 = V_85 ;
}
F_78 ( V_86 ) ;
V_12:
return V_11 ;
}
static T_1
F_121 ( struct V_1 * V_2 , struct V_21 * V_204 ,
struct V_41 * V_42 )
{
V_42 -> V_43 &= ~ V_44 ;
if ( ! F_122 ( F_123 () , V_205 ) )
V_42 -> V_43 &= ~ ( V_48 | V_49 ) ;
if ( V_42 -> V_43 )
return F_46 ( V_2 , V_204 , V_42 , 0 , ( T_2 ) 0 ) ;
return F_30 ( F_36 ( V_204 ) ) ;
}
static void
F_124 ( struct V_41 * V_42 )
{
if ( ( V_42 -> V_43 & V_71 ) && ( V_42 -> V_56 == 0 ) )
V_42 -> V_43 &= ~ V_71 ;
}
T_1
F_125 ( struct V_1 * V_2 , struct V_21 * V_22 ,
char * V_206 , int V_207 , struct V_41 * V_42 ,
int type , T_8 V_208 , struct V_21 * V_204 )
{
struct V_3 * V_3 , * V_209 ;
struct V_36 * V_210 ;
T_1 V_11 ;
T_1 V_107 ;
int V_27 ;
V_3 = V_22 -> V_28 ;
V_210 = F_21 ( V_3 ) ;
V_209 = F_3 ( V_204 -> V_28 ) ;
if ( ! V_22 -> V_211 ) {
F_126 ( 1 , L_6 ,
V_3 ) ;
V_11 = V_212 ;
goto V_12;
}
V_11 = F_42 ( V_2 , V_22 -> V_29 , V_3 , V_213 ) ;
if ( V_11 )
goto V_12;
if ( ! ( V_42 -> V_43 & V_44 ) )
V_42 -> V_45 = 0 ;
V_42 -> V_45 = ( V_42 -> V_45 & V_46 ) | type ;
V_11 = 0 ;
V_27 = 0 ;
switch ( type ) {
case V_73 :
V_27 = F_127 ( V_210 , V_209 , V_42 -> V_45 , true ) ;
if ( ! V_27 )
F_124 ( V_42 ) ;
break;
case V_33 :
V_27 = F_128 ( V_210 , V_209 , V_42 -> V_45 ) ;
break;
case V_214 :
case V_215 :
case V_216 :
case V_217 :
V_27 = F_129 ( V_210 , V_209 , V_42 -> V_45 , V_208 ) ;
break;
default:
F_130 ( V_218 L_7 ,
type ) ;
V_27 = - V_203 ;
}
if ( V_27 < 0 )
goto V_30;
V_11 = F_121 ( V_2 , V_204 , V_42 ) ;
V_107 = F_30 ( F_36 ( V_22 ) ) ;
if ( V_107 )
V_11 = V_107 ;
if ( ! V_11 )
V_11 = F_131 ( V_204 ) ;
V_12:
F_15 ( V_209 ) ;
return V_11 ;
V_30:
V_11 = F_30 ( V_27 ) ;
goto V_12;
}
T_1
F_132 ( struct V_1 * V_2 , struct V_21 * V_22 ,
char * V_206 , int V_207 , struct V_41 * V_42 ,
int type , T_8 V_208 , struct V_21 * V_204 )
{
struct V_3 * V_3 , * V_209 = NULL ;
struct V_36 * V_210 ;
T_1 V_11 ;
int V_27 ;
if ( F_26 ( V_206 , V_207 ) )
return V_219 ;
V_11 = F_32 ( V_2 , V_22 , V_33 , V_103 ) ;
if ( V_11 )
return V_11 ;
V_3 = V_22 -> V_28 ;
V_210 = F_21 ( V_3 ) ;
V_27 = F_47 ( V_22 ) ;
if ( V_27 )
return F_30 ( V_27 ) ;
F_27 ( V_22 , V_31 ) ;
V_209 = F_28 ( V_206 , V_3 , V_207 ) ;
V_27 = F_7 ( V_209 ) ;
if ( F_6 ( V_209 ) )
return F_30 ( V_27 ) ;
V_11 = F_34 ( V_204 , V_22 -> V_29 , V_209 , V_22 ) ;
F_15 ( V_209 ) ;
if ( V_11 )
return V_11 ;
return F_125 ( V_2 , V_22 , V_206 , V_207 , V_42 , type ,
V_208 , V_204 ) ;
}
T_1
F_133 ( struct V_1 * V_2 , struct V_21 * V_22 ,
char * V_206 , int V_207 , struct V_41 * V_42 ,
struct V_21 * V_204 , int V_220 , T_7 * V_221 ,
bool * V_222 , bool * V_223 )
{
struct V_3 * V_3 , * V_209 = NULL ;
struct V_36 * V_210 ;
T_1 V_11 ;
int V_27 ;
T_12 V_224 = 0 , V_225 = 0 ;
V_11 = V_112 ;
if ( ! V_207 )
goto V_12;
V_11 = V_219 ;
if ( F_26 ( V_206 , V_207 ) )
goto V_12;
if ( ! ( V_42 -> V_43 & V_44 ) )
V_42 -> V_45 = 0 ;
V_11 = F_32 ( V_2 , V_22 , V_33 , V_34 ) ;
if ( V_11 )
goto V_12;
V_3 = V_22 -> V_28 ;
V_210 = F_21 ( V_3 ) ;
V_27 = F_47 ( V_22 ) ;
if ( V_27 )
goto V_30;
F_27 ( V_22 , V_31 ) ;
V_209 = F_28 ( V_206 , V_3 , V_207 ) ;
V_27 = F_7 ( V_209 ) ;
if ( F_6 ( V_209 ) )
goto V_30;
if ( F_35 ( V_209 ) ) {
V_11 = F_32 ( V_2 , V_22 , V_33 , V_213 ) ;
if ( V_11 )
goto V_12;
}
V_11 = F_34 ( V_204 , V_22 -> V_29 , V_209 , V_22 ) ;
if ( V_11 )
goto V_12;
if ( F_134 ( V_220 ) ) {
V_224 = V_221 [ 0 ] & 0x7fffffff ;
V_225 = V_221 [ 1 ] & 0x7fffffff ;
}
if ( F_135 ( V_209 ) ) {
V_11 = 0 ;
switch ( V_220 ) {
case V_226 :
if ( ! F_67 ( V_209 ) )
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
if ( F_21 ( V_209 ) -> V_229 . V_76 == V_224
&& F_21 ( V_209 ) -> V_230 . V_76 == V_225
&& F_21 ( V_209 ) -> V_57 == 0 ) {
if ( V_223 )
* V_223 = 1 ;
break;
}
case V_231 :
if ( F_21 ( V_209 ) -> V_229 . V_76 == V_224
&& F_21 ( V_209 ) -> V_230 . V_76 == V_225
&& F_21 ( V_209 ) -> V_57 == 0 ) {
if ( V_223 )
* V_223 = 1 ;
goto V_227;
}
case V_232 :
V_11 = V_219 ;
}
F_136 ( V_22 ) ;
goto V_12;
}
V_27 = F_127 ( V_210 , V_209 , V_42 -> V_45 , true ) ;
if ( V_27 < 0 ) {
F_136 ( V_22 ) ;
goto V_30;
}
if ( V_223 )
* V_223 = 1 ;
F_124 ( V_42 ) ;
if ( F_134 ( V_220 ) ) {
V_42 -> V_43 = V_70 | V_69
| V_233 | V_234 ;
V_42 -> V_235 . V_76 = V_224 ;
V_42 -> V_236 . V_76 = V_225 ;
V_42 -> V_235 . V_237 = 0 ;
V_42 -> V_236 . V_237 = 0 ;
}
V_227:
V_11 = F_121 ( V_2 , V_204 , V_42 ) ;
if ( ! V_11 )
V_11 = F_30 ( F_36 ( V_22 ) ) ;
if ( ! V_11 )
V_11 = F_131 ( V_204 ) ;
V_12:
F_29 ( V_22 ) ;
if ( V_209 && ! F_6 ( V_209 ) )
F_15 ( V_209 ) ;
F_136 ( V_22 ) ;
return V_11 ;
V_30:
V_11 = F_30 ( V_27 ) ;
goto V_12;
}
T_1
F_137 ( struct V_1 * V_2 , struct V_21 * V_22 , char * V_159 , int * V_238 )
{
T_11 V_177 ;
T_1 V_11 ;
int V_27 ;
struct V_8 V_8 ;
V_11 = F_32 ( V_2 , V_22 , V_239 , V_103 ) ;
if ( V_11 )
goto V_12;
V_8 . V_9 = V_22 -> V_29 -> V_10 . V_9 ;
V_8 . V_3 = V_22 -> V_28 ;
V_11 = V_94 ;
if ( ! F_138 ( V_8 . V_3 ) )
goto V_12;
F_139 ( & V_8 ) ;
V_177 = F_94 () ; F_95 ( V_178 ) ;
V_27 = F_140 ( V_8 . V_3 , ( char V_180 * ) V_159 , * V_238 ) ;
F_95 ( V_177 ) ;
if ( V_27 < 0 )
goto V_30;
* V_238 = V_27 ;
V_11 = 0 ;
V_12:
return V_11 ;
V_30:
V_11 = F_30 ( V_27 ) ;
goto V_12;
}
T_1
F_141 ( struct V_1 * V_2 , struct V_21 * V_22 ,
char * V_206 , int V_207 ,
char * V_8 ,
struct V_21 * V_204 )
{
struct V_3 * V_3 , * V_240 ;
T_1 V_11 , V_241 ;
int V_27 ;
V_11 = V_35 ;
if ( ! V_207 || V_8 [ 0 ] == '\0' )
goto V_12;
V_11 = V_219 ;
if ( F_26 ( V_206 , V_207 ) )
goto V_12;
V_11 = F_32 ( V_2 , V_22 , V_33 , V_213 ) ;
if ( V_11 )
goto V_12;
V_27 = F_47 ( V_22 ) ;
if ( V_27 )
goto V_30;
F_50 ( V_22 ) ;
V_3 = V_22 -> V_28 ;
V_240 = F_28 ( V_206 , V_3 , V_207 ) ;
V_27 = F_7 ( V_240 ) ;
if ( F_6 ( V_240 ) )
goto V_30;
V_27 = F_142 ( F_21 ( V_3 ) , V_240 , V_8 ) ;
V_11 = F_30 ( V_27 ) ;
if ( ! V_11 )
V_11 = F_30 ( F_36 ( V_22 ) ) ;
F_29 ( V_22 ) ;
F_136 ( V_22 ) ;
V_241 = F_34 ( V_204 , V_22 -> V_29 , V_240 , V_22 ) ;
F_15 ( V_240 ) ;
if ( V_11 == 0 ) V_11 = V_241 ;
V_12:
return V_11 ;
V_30:
V_11 = F_30 ( V_27 ) ;
goto V_12;
}
T_1
F_143 ( struct V_1 * V_2 , struct V_21 * V_242 ,
char * V_23 , int V_24 , struct V_21 * V_243 )
{
struct V_3 * V_244 , * V_240 , * V_245 ;
struct V_36 * V_210 ;
T_1 V_11 ;
int V_27 ;
V_11 = F_32 ( V_2 , V_242 , V_33 , V_213 ) ;
if ( V_11 )
goto V_12;
V_11 = F_32 ( V_2 , V_243 , 0 , V_103 ) ;
if ( V_11 )
goto V_12;
V_11 = V_246 ;
if ( F_68 ( V_243 -> V_28 ) )
goto V_12;
V_11 = V_112 ;
if ( ! V_24 )
goto V_12;
V_11 = V_219 ;
if ( F_26 ( V_23 , V_24 ) )
goto V_12;
V_27 = F_47 ( V_243 ) ;
if ( V_27 ) {
V_11 = F_30 ( V_27 ) ;
goto V_12;
}
F_27 ( V_242 , V_31 ) ;
V_244 = V_242 -> V_28 ;
V_210 = F_21 ( V_244 ) ;
V_240 = F_28 ( V_23 , V_244 , V_24 ) ;
V_27 = F_7 ( V_240 ) ;
if ( F_6 ( V_240 ) )
goto V_30;
V_245 = V_243 -> V_28 ;
V_11 = V_35 ;
if ( F_35 ( V_245 ) )
goto V_247;
V_27 = F_144 ( V_245 , V_210 , V_240 , NULL ) ;
if ( ! V_27 ) {
V_11 = F_30 ( F_36 ( V_242 ) ) ;
if ( ! V_11 )
V_11 = F_30 ( F_36 ( V_243 ) ) ;
} else {
if ( V_27 == - V_248 && V_2 -> V_198 == 2 )
V_11 = V_111 ;
else
V_11 = F_30 ( V_27 ) ;
}
V_247:
F_15 ( V_240 ) ;
V_249:
F_29 ( V_242 ) ;
F_136 ( V_243 ) ;
V_12:
return V_11 ;
V_30:
V_11 = F_30 ( V_27 ) ;
goto V_249;
}
T_1
F_145 ( struct V_1 * V_2 , struct V_21 * V_242 , char * V_206 , int V_207 ,
struct V_21 * V_243 , char * V_250 , int V_251 )
{
struct V_3 * V_252 , * V_253 , * V_254 , * V_255 , * V_256 ;
struct V_36 * V_257 , * V_258 ;
T_1 V_11 ;
int V_27 ;
V_11 = F_32 ( V_2 , V_242 , V_33 , V_259 ) ;
if ( V_11 )
goto V_12;
V_11 = F_32 ( V_2 , V_243 , V_33 , V_213 ) ;
if ( V_11 )
goto V_12;
V_252 = V_242 -> V_28 ;
V_257 = F_21 ( V_252 ) ;
V_253 = V_243 -> V_28 ;
V_258 = F_21 ( V_253 ) ;
V_11 = V_112 ;
if ( ! V_207 || F_26 ( V_206 , V_207 ) || ! V_251 || F_26 ( V_250 , V_251 ) )
goto V_12;
V_27 = F_47 ( V_242 ) ;
if ( V_27 ) {
V_11 = F_30 ( V_27 ) ;
goto V_12;
}
V_256 = F_146 ( V_253 , V_252 ) ;
V_242 -> V_211 = V_243 -> V_211 = true ;
F_147 ( V_242 ) ;
F_147 ( V_243 ) ;
V_254 = F_28 ( V_206 , V_252 , V_207 ) ;
V_27 = F_7 ( V_254 ) ;
if ( F_6 ( V_254 ) )
goto V_30;
V_27 = - V_13 ;
if ( F_35 ( V_254 ) )
goto V_260;
V_27 = - V_203 ;
if ( V_254 == V_256 )
goto V_260;
V_255 = F_28 ( V_250 , V_253 , V_251 ) ;
V_27 = F_7 ( V_255 ) ;
if ( F_6 ( V_255 ) )
goto V_260;
V_27 = - V_261 ;
if ( V_255 == V_256 )
goto V_262;
V_27 = - V_248 ;
if ( V_242 -> V_29 -> V_10 . V_9 != V_243 -> V_29 -> V_10 . V_9 )
goto V_262;
if ( V_242 -> V_29 -> V_10 . V_3 != V_243 -> V_29 -> V_10 . V_3 )
goto V_262;
V_27 = F_148 ( V_257 , V_254 , V_258 , V_255 , NULL , 0 ) ;
if ( ! V_27 ) {
V_27 = F_36 ( V_243 ) ;
if ( ! V_27 )
V_27 = F_36 ( V_242 ) ;
}
V_262:
F_15 ( V_255 ) ;
V_260:
F_15 ( V_254 ) ;
V_30:
V_11 = F_30 ( V_27 ) ;
F_149 ( V_242 ) ;
F_149 ( V_243 ) ;
F_150 ( V_253 , V_252 ) ;
V_242 -> V_211 = V_243 -> V_211 = false ;
F_136 ( V_242 ) ;
V_12:
return V_11 ;
}
T_1
F_151 ( struct V_1 * V_2 , struct V_21 * V_22 , int type ,
char * V_206 , int V_207 )
{
struct V_3 * V_3 , * V_263 ;
struct V_36 * V_210 ;
T_1 V_11 ;
int V_27 ;
V_11 = V_111 ;
if ( ! V_207 || F_26 ( V_206 , V_207 ) )
goto V_12;
V_11 = F_32 ( V_2 , V_22 , V_33 , V_259 ) ;
if ( V_11 )
goto V_12;
V_27 = F_47 ( V_22 ) ;
if ( V_27 )
goto V_30;
F_27 ( V_22 , V_31 ) ;
V_3 = V_22 -> V_28 ;
V_210 = F_21 ( V_3 ) ;
V_263 = F_28 ( V_206 , V_3 , V_207 ) ;
V_27 = F_7 ( V_263 ) ;
if ( F_6 ( V_263 ) )
goto V_30;
if ( F_35 ( V_263 ) ) {
F_15 ( V_263 ) ;
V_11 = V_35 ;
goto V_12;
}
if ( ! type )
type = F_21 ( V_263 ) -> V_47 & V_264 ;
if ( type != V_33 )
V_27 = F_152 ( V_210 , V_263 , NULL ) ;
else
V_27 = F_153 ( V_210 , V_263 ) ;
if ( ! V_27 )
V_27 = F_36 ( V_22 ) ;
F_15 ( V_263 ) ;
V_30:
V_11 = F_30 ( V_27 ) ;
V_12:
return V_11 ;
}
static int F_154 ( struct V_265 * V_266 , const char * V_23 ,
int V_267 , T_6 V_92 , T_4 V_131 ,
unsigned int V_268 )
{
struct V_269 * V_159 =
F_155 ( V_266 , struct V_269 , V_266 ) ;
struct V_270 * V_271 = ( void * ) ( V_159 -> V_272 + V_159 -> V_273 ) ;
unsigned int V_274 ;
V_274 = F_156 ( sizeof( struct V_270 ) + V_267 , sizeof( T_4 ) ) ;
if ( V_159 -> V_273 + V_274 > V_275 ) {
V_159 -> V_276 = 1 ;
return - V_203 ;
}
V_271 -> V_267 = V_267 ;
V_271 -> V_92 = V_92 ;
V_271 -> V_131 = V_131 ;
V_271 -> V_268 = V_268 ;
memcpy ( V_271 -> V_23 , V_23 , V_267 ) ;
V_159 -> V_273 += V_274 ;
return 0 ;
}
static T_1 F_157 ( struct V_86 * V_86 , T_13 V_277 ,
struct V_278 * V_279 , T_6 * V_280 )
{
struct V_270 * V_271 ;
int V_27 ;
int V_166 ;
T_6 V_92 ;
struct V_269 V_159 = {
. V_266 . V_281 = F_154 ,
. V_272 = ( void * ) F_158 (GFP_KERNEL)
} ;
if ( ! V_159 . V_272 )
return F_30 ( - V_282 ) ;
V_92 = * V_280 ;
while ( 1 ) {
unsigned int V_274 ;
V_279 -> V_11 = V_283 ;
V_159 . V_273 = 0 ;
V_159 . V_276 = 0 ;
V_27 = F_159 ( V_86 , & V_159 . V_266 ) ;
if ( V_159 . V_276 )
V_27 = 0 ;
if ( V_27 < 0 )
break;
V_166 = V_159 . V_273 ;
if ( ! V_166 )
break;
V_271 = (struct V_270 * ) V_159 . V_272 ;
while ( V_166 > 0 ) {
V_92 = V_271 -> V_92 ;
if ( V_277 ( V_279 , V_271 -> V_23 , V_271 -> V_267 , V_271 -> V_92 ,
V_271 -> V_131 , V_271 -> V_268 ) )
break;
if ( V_279 -> V_11 != V_109 )
break;
V_274 = F_156 ( sizeof( * V_271 ) + V_271 -> V_267 ,
sizeof( T_4 ) ) ;
V_166 -= V_274 ;
V_271 = (struct V_270 * ) ( ( char * ) V_271 + V_274 ) ;
}
if ( V_166 > 0 )
break;
V_92 = F_160 ( V_86 , 0 , V_284 ) ;
}
F_161 ( ( unsigned long ) ( V_159 . V_272 ) ) ;
if ( V_27 )
return F_30 ( V_27 ) ;
* V_280 = V_92 ;
return V_279 -> V_11 ;
}
T_1
F_162 ( struct V_1 * V_2 , struct V_21 * V_22 , T_6 * V_280 ,
struct V_278 * V_279 , T_13 V_277 )
{
T_1 V_11 ;
struct V_86 * V_86 ;
T_6 V_92 = * V_280 ;
int V_118 = V_122 ;
if ( V_2 -> V_198 > 2 )
V_118 |= V_124 ;
V_11 = F_71 ( V_2 , V_22 , V_33 , V_118 , & V_86 ) ;
if ( V_11 )
goto V_12;
V_92 = F_160 ( V_86 , V_92 , V_285 ) ;
if ( V_92 < 0 ) {
V_11 = F_30 ( ( int ) V_92 ) ;
goto V_286;
}
V_11 = F_157 ( V_86 , V_277 , V_279 , V_280 ) ;
if ( V_11 == V_283 || V_11 == V_287 )
V_11 = V_109 ;
V_286:
F_78 ( V_86 ) ;
V_12:
return V_11 ;
}
T_1
F_163 ( struct V_1 * V_2 , struct V_21 * V_22 , struct V_288 * V_289 , int V_95 )
{
T_1 V_11 ;
V_11 = F_32 ( V_2 , V_22 , 0 , V_103 | V_95 ) ;
if ( ! V_11 ) {
struct V_8 V_8 = {
. V_9 = V_22 -> V_29 -> V_10 . V_9 ,
. V_3 = V_22 -> V_28 ,
} ;
if ( F_164 ( & V_8 , V_289 ) )
V_11 = V_212 ;
}
return V_11 ;
}
static int F_165 ( struct V_1 * V_2 , struct V_5 * exp )
{
return F_166 ( V_2 , exp ) & V_290 ;
}
T_1
F_42 ( struct V_1 * V_2 , struct V_5 * exp ,
struct V_3 * V_3 , int V_291 )
{
struct V_36 * V_36 = F_21 ( V_3 ) ;
int V_11 ;
if ( ( V_291 & V_292 ) == V_103 )
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
if ( ! ( V_291 & V_293 ) )
if ( V_291 & ( V_72 | V_65 | V_58 ) ) {
if ( F_165 ( V_2 , exp ) ||
F_167 ( exp -> V_10 . V_9 ) )
return V_110 ;
if ( F_168 ( V_36 ) )
return V_112 ;
}
if ( ( V_291 & V_58 ) && F_73 ( V_36 ) )
return V_112 ;
if ( V_291 & V_294 ) {
if ( exp -> V_14 & V_295 )
return 0 ;
else
V_291 = V_122 | V_59 ;
}
if ( ( V_291 & V_59 ) &&
F_122 ( V_36 -> V_296 , F_123 () ) )
return 0 ;
V_11 = F_169 ( V_36 , V_291 & ( V_297 | V_298 | V_299 ) ) ;
if ( V_11 == - V_300 && F_63 ( V_36 -> V_47 ) &&
( V_291 == ( V_122 | V_59 ) ||
V_291 == ( V_122 | V_301 ) ) )
V_11 = F_169 ( V_36 , V_299 ) ;
return V_11 ? F_30 ( V_11 ) : 0 ;
}
void
F_170 ( void )
{
struct V_128 * V_302 , * V_303 ;
unsigned int V_304 ;
F_23 ( L_8 ) ;
for ( V_304 = 0 ; V_304 < V_305 ; V_304 ++ ) {
V_302 = V_141 [ V_304 ] . V_143 ;
while( V_302 ) {
V_303 = V_302 ;
V_302 = V_302 -> V_144 ;
F_171 ( V_303 ) ;
}
V_141 [ V_304 ] . V_143 = NULL ;
}
}
int
F_172 ( int V_306 )
{
int V_304 ;
int V_307 = 0 ;
int V_308 ;
struct V_128 * * V_302 = NULL ;
if ( V_141 [ 0 ] . V_143 )
return 0 ;
V_308 = F_173 ( V_306 , V_305 ) ;
V_308 = F_174 ( 2 , V_308 ) ;
V_306 = V_308 * V_305 ;
F_23 ( L_9 , V_306 ) ;
for ( V_304 = 0 ; V_304 < V_305 ; V_304 ++ ) {
F_175 ( & V_141 [ V_304 ] . V_142 ) ;
V_302 = & V_141 [ V_304 ] . V_143 ;
for ( V_307 = 0 ; V_307 < V_308 ; V_307 ++ ) {
* V_302 = F_176 ( sizeof( struct V_128 ) , V_309 ) ;
if ( ! * V_302 )
goto V_310;
V_302 = & ( * V_302 ) -> V_144 ;
}
* V_302 = NULL ;
}
V_149 . V_150 = V_306 ;
return 0 ;
V_310:
F_23 ( L_10 ) ;
F_170 () ;
return - V_282 ;
}

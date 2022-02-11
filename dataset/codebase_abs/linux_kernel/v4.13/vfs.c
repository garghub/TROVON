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
if ( V_8 . V_9 == exp -> V_10 . V_9 && V_8 . V_3 == V_3 &&
F_5 ( V_3 , exp ) == 2 ) {
F_6 ( & V_8 ) ;
goto V_12;
}
V_7 = F_7 ( V_2 , & V_8 ) ;
if ( F_8 ( V_7 ) ) {
V_11 = F_9 ( V_7 ) ;
if ( V_11 == - V_13 && ! ( exp -> V_14 & V_15 ) )
V_11 = 0 ;
F_6 ( & V_8 ) ;
goto V_12;
}
if ( F_10 ( V_2 ) ||
( exp -> V_14 & V_16 ) || F_11 ( V_7 ) ) {
* V_4 = V_8 . V_3 ;
V_8 . V_3 = V_3 ;
* V_6 = V_7 ;
V_7 = exp ;
}
F_6 ( & V_8 ) ;
F_12 ( V_7 ) ;
V_12:
return V_11 ;
}
static void F_13 ( struct V_8 * V_8 )
{
struct V_3 * V_17 ;
while ( V_8 -> V_3 == V_8 -> V_9 -> V_18 && F_14 ( V_8 ) )
;
V_17 = F_15 ( V_8 -> V_3 ) ;
F_16 ( V_8 -> V_3 ) ;
V_8 -> V_3 = V_17 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_3 * V_19 , struct V_5 * * exp , struct V_3 * * V_20 )
{
struct V_5 * V_7 ;
struct V_8 V_8 = { . V_9 = F_2 ( ( * exp ) -> V_10 . V_9 ) ,
. V_3 = F_3 (dparent) } ;
F_13 ( & V_8 ) ;
V_7 = F_18 ( V_2 , & V_8 ) ;
if ( F_9 ( V_7 ) == - V_13 ) {
* V_20 = F_3 ( V_19 ) ;
} else if ( F_8 ( V_7 ) ) {
F_6 ( & V_8 ) ;
return F_9 ( V_7 ) ;
} else {
* V_20 = F_3 ( V_8 . V_3 ) ;
F_12 ( * exp ) ;
* exp = V_7 ;
}
F_6 ( & V_8 ) ;
return 0 ;
}
int F_5 ( struct V_3 * V_3 , struct V_5 * exp )
{
if ( ! F_19 ( V_3 ) )
return 0 ;
if ( exp -> V_14 & V_15 )
return 1 ;
if ( F_20 ( V_3 ) )
return 1 ;
if ( F_21 ( V_3 ) )
return 2 ;
return 0 ;
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
V_3 = F_15 ( V_19 ) ;
else if ( ! F_11 ( exp ) && ! F_10 ( V_2 ) )
V_3 = F_3 ( V_19 ) ;
else {
V_27 = F_17 ( V_2 , V_19 , & exp , & V_3 ) ;
if ( V_27 )
goto V_30;
}
} else {
F_27 ( V_22 , V_31 ) ;
V_3 = F_28 ( V_23 , V_19 , V_24 ) ;
V_27 = F_9 ( V_3 ) ;
if ( F_8 ( V_3 ) )
goto V_30;
if ( F_5 ( V_3 , exp ) ) {
F_29 ( V_22 ) ;
if ( ( V_27 = F_1 ( V_2 , & V_3 , & exp ) ) ) {
F_16 ( V_3 ) ;
goto V_30;
}
}
}
* V_26 = V_3 ;
* V_25 = exp ;
return 0 ;
V_30:
F_12 ( exp ) ;
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
F_16 ( V_3 ) ;
F_12 ( exp ) ;
return V_11 ;
}
static int
F_36 ( struct V_21 * V_22 )
{
struct V_36 * V_36 = F_19 ( V_22 -> V_28 ) ;
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
struct V_36 * V_36 = F_19 ( V_22 -> V_28 ) ;
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
bool V_68 = ( V_42 -> V_43 & V_69 ) ;
if ( V_42 -> V_43 & ( V_70 | V_71 | V_69 ) )
V_64 |= V_72 | V_59 ;
if ( V_42 -> V_43 & V_69 )
V_66 = V_73 ;
V_67 = ! V_22 -> V_28 ;
V_11 = F_32 ( V_2 , V_22 , V_66 , V_64 ) ;
if ( V_11 )
return V_11 ;
if ( V_67 ) {
V_27 = F_47 ( V_22 ) ;
if ( V_27 )
goto V_12;
}
V_3 = V_22 -> V_28 ;
V_36 = F_19 ( V_3 ) ;
if ( F_48 ( V_36 -> V_47 ) )
V_42 -> V_43 &= ~ V_44 ;
if ( ! V_42 -> V_43 )
return 0 ;
F_39 ( V_36 , V_42 ) ;
if ( V_62 && V_63 != V_36 -> V_74 . V_75 )
return V_76 ;
if ( V_68 ) {
V_11 = F_41 ( V_2 , V_22 , V_42 ) ;
if ( V_11 )
return V_11 ;
}
F_49 ( V_22 ) ;
if ( V_68 ) {
struct V_41 V_77 = {
. V_43 = V_69 | V_78 | V_71 ,
. V_56 = V_42 -> V_56 ,
} ;
V_27 = F_50 ( V_3 , & V_77 , NULL ) ;
if ( V_27 )
goto V_79;
V_42 -> V_43 &= ~ V_69 ;
if ( ( V_42 -> V_43 & ~ V_71 ) == 0 )
goto V_79;
}
V_42 -> V_43 |= V_78 ;
V_27 = F_50 ( V_3 , V_42 , NULL ) ;
V_79:
F_29 ( V_22 ) ;
if ( V_68 )
F_45 ( V_36 ) ;
V_12:
if ( ! V_27 )
V_27 = F_36 ( V_22 ) ;
return F_30 ( V_27 ) ;
}
int F_20 ( struct V_3 * V_3 )
{
struct V_36 * V_36 = F_19 ( V_3 ) ;
if ( V_36 == NULL )
return 0 ;
if ( V_36 -> V_47 & V_80 )
return 0 ;
if ( ! ( V_36 -> V_47 & V_81 ) )
return 0 ;
if ( F_51 ( V_3 , V_82 , NULL , 0 ) <= 0 )
return 0 ;
return 1 ;
}
T_1 F_52 ( struct V_1 * V_2 , struct V_21 * V_22 ,
struct V_83 * V_84 )
{
T_1 error ;
int V_85 ;
struct V_3 * V_3 ;
error = F_32 ( V_2 , V_22 , 0 , V_65 ) ;
if ( error )
return error ;
V_3 = V_22 -> V_28 ;
F_53 ( F_19 ( V_3 ) ) ;
V_85 = F_54 ( V_3 , V_84 -> V_86 , V_84 -> V_24 ) ;
F_55 ( F_19 ( V_3 ) ) ;
return F_30 ( V_85 ) ;
}
T_1 F_52 ( struct V_1 * V_2 , struct V_21 * V_22 ,
struct V_83 * V_84 )
{
return V_87 ;
}
T_1 F_56 ( struct V_88 * V_89 , T_4 V_90 , struct V_88 * V_91 ,
T_4 V_92 , T_4 V_93 )
{
return F_30 ( F_57 ( V_89 , V_90 , V_91 , V_92 , V_93 ) ) ;
}
T_5 F_58 ( struct V_88 * V_89 , T_4 V_90 , struct V_88 * V_91 ,
T_4 V_92 , T_4 V_93 )
{
V_93 = F_59 ( T_4 , V_93 , 1 << 22 ) ;
return F_60 ( V_89 , V_90 , V_91 , V_92 , V_93 , 0 ) ;
}
T_1 F_61 ( struct V_1 * V_2 , struct V_21 * V_22 ,
struct V_88 * V_88 , T_6 V_94 , T_6 V_24 ,
int V_95 )
{
int error ;
if ( ! F_62 ( F_63 ( V_88 ) -> V_47 ) )
return V_96 ;
error = F_64 ( V_88 , V_95 , V_94 , V_24 ) ;
if ( ! error )
error = F_36 ( V_22 ) ;
return F_30 ( error ) ;
}
T_1
F_65 ( struct V_1 * V_2 , struct V_21 * V_22 , T_7 * V_97 , T_7 * V_98 )
{
struct V_99 * V_100 ;
struct V_5 * V_101 ;
struct V_3 * V_3 ;
T_7 V_102 , V_103 = 0 , V_104 = 0 ;
T_1 error ;
error = F_32 ( V_2 , V_22 , 0 , V_105 ) ;
if ( error )
goto V_12;
V_101 = V_22 -> V_29 ;
V_3 = V_22 -> V_28 ;
if ( F_66 ( V_3 ) )
V_100 = V_106 ;
else if ( F_67 ( V_3 ) )
V_100 = V_107 ;
else
V_100 = V_108 ;
V_102 = * V_97 ;
for (; V_100 -> V_97 ; V_100 ++ ) {
if ( V_100 -> V_97 & V_102 ) {
T_1 V_109 ;
V_104 |= V_100 -> V_97 ;
V_109 = F_42 ( V_2 , V_101 , V_3 , V_100 -> V_110 ) ;
switch ( V_109 ) {
case V_111 :
V_103 |= V_100 -> V_97 ;
break;
case V_112 :
case V_113 :
case V_114 :
break;
default:
error = V_109 ;
goto V_12;
}
}
}
* V_97 = V_103 ;
if ( V_98 )
* V_98 = V_104 ;
V_12:
return error ;
}
static int F_68 ( struct V_36 * V_36 , int V_97 )
{
unsigned int V_115 ;
if ( V_97 & V_116 )
return 0 ;
V_115 = ( V_97 & V_72 ) ? V_117 : V_118 ;
return F_69 ( V_36 , V_115 | V_119 ) ;
}
T_1
F_70 ( struct V_1 * V_2 , struct V_21 * V_22 , T_3 type ,
int V_120 , struct V_88 * * V_121 )
{
struct V_8 V_8 ;
struct V_36 * V_36 ;
struct V_88 * V_88 ;
int V_95 = V_118 | V_122 ;
T_1 V_11 ;
int V_27 = 0 ;
F_71 () ;
if ( type == V_73 )
V_120 |= V_59 ;
V_11 = F_32 ( V_2 , V_22 , type , V_120 ) ;
if ( V_11 )
goto V_12;
V_8 . V_9 = V_22 -> V_29 -> V_10 . V_9 ;
V_8 . V_3 = V_22 -> V_28 ;
V_36 = F_19 ( V_8 . V_3 ) ;
V_11 = V_114 ;
if ( F_72 ( V_36 ) && ( V_120 & V_72 ) )
goto V_12;
if ( F_62 ( ( V_36 ) -> V_47 ) && F_73 ( V_36 ) )
goto V_12;
if ( ! V_36 -> V_123 )
goto V_12;
V_27 = F_68 ( V_36 , V_120 ) ;
if ( V_27 )
goto V_30;
if ( V_120 & V_72 ) {
if ( V_120 & V_124 )
V_95 = V_125 | V_122 ;
else
V_95 = V_117 | V_122 ;
}
V_88 = F_74 ( & V_8 , V_95 , F_75 () ) ;
if ( F_8 ( V_88 ) ) {
V_27 = F_9 ( V_88 ) ;
goto V_30;
}
V_27 = F_76 ( V_88 , V_120 , 0 ) ;
if ( V_27 ) {
F_77 ( V_88 ) ;
goto V_30;
}
if ( V_120 & V_126 )
V_88 -> V_127 |= V_128 ;
else
V_88 -> V_127 |= V_129 ;
* V_121 = V_88 ;
V_30:
V_11 = F_30 ( V_27 ) ;
V_12:
F_71 () ;
return V_11 ;
}
struct V_130 *
F_78 ( struct V_88 * V_88 )
{
struct V_36 * V_36 = F_63 ( V_88 ) ;
T_8 V_131 = V_36 -> V_39 -> V_132 ;
T_9 V_133 = V_36 -> V_134 ;
struct V_130 * V_135 , * * V_136 , * * V_137 = NULL ;
int V_138 = 0 ;
unsigned int V_139 ;
struct V_140 * V_141 ;
V_139 = F_79 ( V_131 , V_133 , 0xfeedbeef ) & V_142 ;
V_141 = & V_143 [ V_139 ] ;
F_80 ( & V_141 -> V_144 ) ;
for ( V_136 = & V_141 -> V_145 ; ( V_135 = * V_136 ) ; V_136 = & V_135 -> V_146 ) {
if ( V_135 -> V_147 == V_133 && V_135 -> V_148 == V_131 )
goto V_149;
V_138 ++ ;
if ( V_135 -> V_150 == 0 )
V_137 = V_136 ;
}
V_138 = V_151 . V_152 ;
if ( ! V_137 ) {
F_81 ( & V_141 -> V_144 ) ;
return NULL ;
}
V_136 = V_137 ;
V_135 = * V_137 ;
V_135 -> V_148 = V_131 ;
V_135 -> V_147 = V_133 ;
V_135 -> V_153 = 0 ;
V_135 -> V_154 = V_139 ;
V_149:
if ( V_136 != & V_141 -> V_145 ) {
* V_136 = V_135 -> V_146 ;
V_135 -> V_146 = V_141 -> V_145 ;
V_141 -> V_145 = V_135 ;
}
V_135 -> V_150 ++ ;
V_151 . V_155 [ V_138 * 10 / V_151 . V_152 ] ++ ;
F_81 ( & V_141 -> V_144 ) ;
if ( V_135 -> V_153 )
V_88 -> V_156 = V_135 -> V_157 ;
return V_135 ;
}
void F_82 ( struct V_88 * V_88 , struct V_130 * V_135 )
{
struct V_140 * V_141 = & V_143 [ V_135 -> V_154 ] ;
F_80 ( & V_141 -> V_144 ) ;
V_135 -> V_157 = V_88 -> V_156 ;
V_135 -> V_153 = 1 ;
V_135 -> V_150 -- ;
F_81 ( & V_141 -> V_144 ) ;
}
static int
F_83 ( struct V_158 * V_159 , struct V_160 * V_161 ,
struct V_162 * V_163 )
{
struct V_1 * V_2 = V_163 -> V_164 . V_86 ;
struct V_165 * * V_166 = V_2 -> V_167 ;
struct V_165 * V_165 = V_161 -> V_165 ;
T_10 V_168 ;
V_168 = V_163 -> V_24 ;
if ( V_2 -> V_169 . V_170 == 0 ) {
F_84 ( V_165 ) ;
F_85 ( * V_2 -> V_167 ) ;
* ( V_2 -> V_167 ++ ) = V_165 ;
V_2 -> V_169 . V_171 = V_161 -> V_94 ;
V_2 -> V_169 . V_170 = V_168 ;
} else if ( V_165 != V_166 [ - 1 ] ) {
F_84 ( V_165 ) ;
if ( * V_2 -> V_167 )
F_85 ( * V_2 -> V_167 ) ;
* ( V_2 -> V_167 ++ ) = V_165 ;
V_2 -> V_169 . V_170 += V_168 ;
} else
V_2 -> V_169 . V_170 += V_168 ;
return V_168 ;
}
static int F_86 ( struct V_158 * V_159 ,
struct V_162 * V_163 )
{
return F_87 ( V_159 , V_163 , F_83 ) ;
}
static T_1
F_88 ( struct V_88 * V_88 , unsigned long * V_93 , int V_27 )
{
if ( V_27 >= 0 ) {
V_151 . V_172 += V_27 ;
* V_93 = V_27 ;
F_89 ( V_88 ) ;
return 0 ;
} else
return F_30 ( V_27 ) ;
}
T_1 F_90 ( struct V_1 * V_2 ,
struct V_88 * V_88 , T_6 V_94 , unsigned long * V_93 )
{
struct V_162 V_163 = {
. V_24 = 0 ,
. V_173 = * V_93 ,
. V_174 = V_94 ,
. V_164 . V_86 = V_2 ,
} ;
int V_27 ;
V_2 -> V_167 = V_2 -> V_175 + 1 ;
V_27 = F_91 ( V_88 , & V_163 , F_86 ) ;
return F_88 ( V_88 , V_93 , V_27 ) ;
}
T_1 F_92 ( struct V_88 * V_88 , T_6 V_94 , struct V_176 * V_177 , int V_178 ,
unsigned long * V_93 )
{
struct V_179 V_180 ;
int V_27 ;
F_93 ( & V_180 , V_181 | V_182 , V_177 , V_178 , * V_93 ) ;
V_27 = F_94 ( V_88 , & V_180 , & V_94 , 0 ) ;
return F_88 ( V_88 , V_93 , V_27 ) ;
}
static int F_95 ( struct V_88 * V_88 )
{
struct V_36 * V_36 = F_63 ( V_88 ) ;
static T_9 V_183 ;
static T_8 V_184 ;
int V_11 = 0 ;
if ( F_96 ( & V_36 -> V_185 ) > 1
|| ( V_183 == V_36 -> V_134 && V_184 == V_36 -> V_39 -> V_132 ) ) {
F_23 ( L_2 , F_97 ( V_186 ) ) ;
F_98 ( 10 ) ;
F_23 ( L_3 , F_97 ( V_186 ) ) ;
}
if ( V_36 -> V_187 & V_188 ) {
F_23 ( L_4 , F_97 ( V_186 ) ) ;
V_11 = F_99 ( V_88 , 0 ) ;
}
V_183 = V_36 -> V_134 ;
V_184 = V_36 -> V_39 -> V_132 ;
return V_11 ;
}
T_1
F_100 ( struct V_1 * V_2 , struct V_21 * V_22 , struct V_88 * V_88 ,
T_6 V_94 , struct V_176 * V_177 , int V_178 ,
unsigned long * V_189 , int V_190 )
{
struct V_5 * exp ;
struct V_179 V_180 ;
T_1 V_11 = 0 ;
int V_27 ;
int V_191 ;
T_6 V_174 = V_94 ;
unsigned int V_192 = V_186 -> V_95 ;
int V_95 = 0 ;
if ( F_101 ( V_193 , & V_2 -> V_194 ) )
V_186 -> V_95 |= V_195 ;
exp = V_22 -> V_29 ;
V_191 = ( V_2 -> V_196 == 2 ) && F_102 ( exp ) ;
if ( ! F_37 ( exp ) )
V_190 = V_197 ;
if ( V_190 && ! V_191 )
V_95 |= V_198 ;
F_93 ( & V_180 , V_199 | V_182 , V_177 , V_178 , * V_189 ) ;
V_27 = F_103 ( V_88 , & V_180 , & V_174 , V_95 ) ;
if ( V_27 < 0 )
goto V_30;
* V_189 = V_27 ;
V_151 . V_200 += V_27 ;
F_104 ( V_88 ) ;
if ( V_190 && V_191 )
V_27 = F_95 ( V_88 ) ;
V_30:
F_23 ( L_5 , V_27 ) ;
if ( V_27 >= 0 )
V_11 = 0 ;
else
V_11 = F_30 ( V_27 ) ;
if ( F_101 ( V_193 , & V_2 -> V_194 ) )
F_105 ( V_192 , V_195 ) ;
return V_11 ;
}
T_1 F_106 ( struct V_1 * V_2 , struct V_21 * V_22 ,
T_6 V_94 , struct V_176 * V_177 , int V_178 , unsigned long * V_93 )
{
struct V_88 * V_88 ;
struct V_130 * V_135 ;
T_1 V_11 ;
F_107 ( V_2 , V_22 , V_94 , V_178 ) ;
V_11 = F_70 ( V_2 , V_22 , V_73 , V_124 , & V_88 ) ;
if ( V_11 )
return V_11 ;
V_135 = F_78 ( V_88 ) ;
F_108 ( V_2 , V_22 , V_94 , V_178 ) ;
if ( V_88 -> V_201 -> V_202 && F_101 ( V_203 , & V_2 -> V_194 ) )
V_11 = F_90 ( V_2 , V_88 , V_94 , V_93 ) ;
else
V_11 = F_92 ( V_88 , V_94 , V_177 , V_178 , V_93 ) ;
F_109 ( V_2 , V_22 , V_94 , V_178 ) ;
if ( V_135 )
F_82 ( V_88 , V_135 ) ;
F_77 ( V_88 ) ;
F_110 ( V_2 , V_22 , V_94 , V_178 ) ;
return V_11 ;
}
T_1
F_111 ( struct V_1 * V_2 , struct V_21 * V_22 , T_6 V_94 ,
struct V_176 * V_177 , int V_178 , unsigned long * V_189 , int V_190 )
{
struct V_88 * V_88 = NULL ;
T_1 V_11 = 0 ;
F_112 ( V_2 , V_22 , V_94 , V_178 ) ;
V_11 = F_70 ( V_2 , V_22 , V_73 , V_72 , & V_88 ) ;
if ( V_11 )
goto V_12;
F_113 ( V_2 , V_22 , V_94 , V_178 ) ;
V_11 = F_100 ( V_2 , V_22 , V_88 , V_94 , V_177 , V_178 , V_189 , V_190 ) ;
F_114 ( V_2 , V_22 , V_94 , V_178 ) ;
F_77 ( V_88 ) ;
V_12:
F_115 ( V_2 , V_22 , V_94 , V_178 ) ;
return V_11 ;
}
T_1
F_116 ( struct V_1 * V_2 , struct V_21 * V_22 ,
T_6 V_94 , unsigned long V_93 )
{
struct V_88 * V_88 ;
T_6 V_204 = V_205 ;
T_1 V_11 = V_96 ;
if ( V_94 < 0 )
goto V_12;
if ( V_93 != 0 ) {
V_204 = V_94 + ( T_6 ) V_93 - 1 ;
if ( V_204 < V_94 )
goto V_12;
}
V_11 = F_70 ( V_2 , V_22 , V_73 ,
V_72 | V_116 , & V_88 ) ;
if ( V_11 )
goto V_12;
if ( F_37 ( V_22 -> V_29 ) ) {
int V_109 = F_117 ( V_88 , V_94 , V_204 , 0 ) ;
if ( V_109 != - V_206 )
V_11 = F_30 ( V_109 ) ;
else
V_11 = V_87 ;
}
F_77 ( V_88 ) ;
V_12:
return V_11 ;
}
static T_1
F_118 ( struct V_1 * V_2 , struct V_21 * V_207 ,
struct V_41 * V_42 )
{
V_42 -> V_43 &= ~ V_44 ;
if ( ! F_119 ( F_120 () , V_208 ) )
V_42 -> V_43 &= ~ ( V_48 | V_49 ) ;
if ( V_42 -> V_43 )
return F_46 ( V_2 , V_207 , V_42 , 0 , ( T_2 ) 0 ) ;
return F_30 ( F_36 ( V_207 ) ) ;
}
static void
F_121 ( struct V_41 * V_42 )
{
if ( ( V_42 -> V_43 & V_69 ) && ( V_42 -> V_56 == 0 ) )
V_42 -> V_43 &= ~ V_69 ;
}
T_1
F_122 ( struct V_1 * V_2 , struct V_21 * V_22 ,
char * V_209 , int V_210 , struct V_41 * V_42 ,
int type , T_8 V_211 , struct V_21 * V_207 )
{
struct V_3 * V_3 , * V_212 ;
struct V_36 * V_213 ;
T_1 V_11 ;
T_1 V_109 ;
int V_27 ;
V_3 = V_22 -> V_28 ;
V_213 = F_19 ( V_3 ) ;
V_212 = F_3 ( V_207 -> V_28 ) ;
if ( ! V_22 -> V_214 ) {
F_123 ( 1 , L_6 ,
V_3 ) ;
V_11 = V_215 ;
goto V_12;
}
V_11 = F_42 ( V_2 , V_22 -> V_29 , V_3 , V_216 ) ;
if ( V_11 )
goto V_12;
if ( ! ( V_42 -> V_43 & V_44 ) )
V_42 -> V_45 = 0 ;
V_42 -> V_45 = ( V_42 -> V_45 & V_46 ) | type ;
V_11 = 0 ;
V_27 = 0 ;
switch ( type ) {
case V_73 :
V_27 = F_124 ( V_213 , V_212 , V_42 -> V_45 , true ) ;
if ( ! V_27 )
F_121 ( V_42 ) ;
break;
case V_33 :
V_27 = F_125 ( V_213 , V_212 , V_42 -> V_45 ) ;
break;
case V_217 :
case V_218 :
case V_219 :
case V_220 :
V_27 = F_126 ( V_213 , V_212 , V_42 -> V_45 , V_211 ) ;
break;
default:
F_127 ( V_221 L_7 ,
type ) ;
V_27 = - V_206 ;
}
if ( V_27 < 0 )
goto V_30;
V_11 = F_118 ( V_2 , V_207 , V_42 ) ;
V_109 = F_30 ( F_36 ( V_22 ) ) ;
if ( V_109 )
V_11 = V_109 ;
if ( ! V_11 )
V_11 = F_128 ( V_207 ) ;
V_12:
F_16 ( V_212 ) ;
return V_11 ;
V_30:
V_11 = F_30 ( V_27 ) ;
goto V_12;
}
T_1
F_129 ( struct V_1 * V_2 , struct V_21 * V_22 ,
char * V_209 , int V_210 , struct V_41 * V_42 ,
int type , T_8 V_211 , struct V_21 * V_207 )
{
struct V_3 * V_3 , * V_212 = NULL ;
struct V_36 * V_213 ;
T_1 V_11 ;
int V_27 ;
if ( F_26 ( V_209 , V_210 ) )
return V_222 ;
V_11 = F_32 ( V_2 , V_22 , V_33 , V_105 ) ;
if ( V_11 )
return V_11 ;
V_3 = V_22 -> V_28 ;
V_213 = F_19 ( V_3 ) ;
V_27 = F_47 ( V_22 ) ;
if ( V_27 )
return F_30 ( V_27 ) ;
F_27 ( V_22 , V_31 ) ;
V_212 = F_28 ( V_209 , V_3 , V_210 ) ;
V_27 = F_9 ( V_212 ) ;
if ( F_8 ( V_212 ) )
return F_30 ( V_27 ) ;
V_11 = F_34 ( V_207 , V_22 -> V_29 , V_212 , V_22 ) ;
F_16 ( V_212 ) ;
if ( V_11 )
return V_11 ;
return F_122 ( V_2 , V_22 , V_209 , V_210 , V_42 , type ,
V_211 , V_207 ) ;
}
T_1
F_130 ( struct V_1 * V_2 , struct V_21 * V_22 ,
char * V_209 , int V_210 , struct V_41 * V_42 ,
struct V_21 * V_207 , int V_223 , T_7 * V_224 ,
bool * V_225 , bool * V_226 )
{
struct V_3 * V_3 , * V_212 = NULL ;
struct V_36 * V_213 ;
T_1 V_11 ;
int V_27 ;
T_11 V_227 = 0 , V_228 = 0 ;
V_11 = V_114 ;
if ( ! V_210 )
goto V_12;
V_11 = V_222 ;
if ( F_26 ( V_209 , V_210 ) )
goto V_12;
if ( ! ( V_42 -> V_43 & V_44 ) )
V_42 -> V_45 = 0 ;
V_11 = F_32 ( V_2 , V_22 , V_33 , V_34 ) ;
if ( V_11 )
goto V_12;
V_3 = V_22 -> V_28 ;
V_213 = F_19 ( V_3 ) ;
V_27 = F_47 ( V_22 ) ;
if ( V_27 )
goto V_30;
F_27 ( V_22 , V_31 ) ;
V_212 = F_28 ( V_209 , V_3 , V_210 ) ;
V_27 = F_9 ( V_212 ) ;
if ( F_8 ( V_212 ) )
goto V_30;
if ( F_35 ( V_212 ) ) {
V_11 = F_32 ( V_2 , V_22 , V_33 , V_216 ) ;
if ( V_11 )
goto V_12;
}
V_11 = F_34 ( V_207 , V_22 -> V_29 , V_212 , V_22 ) ;
if ( V_11 )
goto V_12;
if ( F_131 ( V_223 ) ) {
V_227 = V_224 [ 0 ] & 0x7fffffff ;
V_228 = V_224 [ 1 ] & 0x7fffffff ;
}
if ( F_132 ( V_212 ) ) {
V_11 = 0 ;
switch ( V_223 ) {
case V_229 :
if ( ! F_66 ( V_212 ) )
goto V_12;
else if ( V_225 ) {
* V_225 = ( V_42 -> V_43 & V_69 ) && ! V_42 -> V_56 ;
}
else {
V_42 -> V_43 &= V_69 ;
goto V_230;
}
break;
case V_231 :
if ( F_19 ( V_212 ) -> V_232 . V_75 == V_227
&& F_19 ( V_212 ) -> V_233 . V_75 == V_228
&& F_19 ( V_212 ) -> V_57 == 0 ) {
if ( V_226 )
* V_226 = 1 ;
break;
}
case V_234 :
if ( F_19 ( V_212 ) -> V_232 . V_75 == V_227
&& F_19 ( V_212 ) -> V_233 . V_75 == V_228
&& F_19 ( V_212 ) -> V_57 == 0 ) {
if ( V_226 )
* V_226 = 1 ;
goto V_230;
}
case V_235 :
V_11 = V_222 ;
}
F_133 ( V_22 ) ;
goto V_12;
}
V_27 = F_124 ( V_213 , V_212 , V_42 -> V_45 , true ) ;
if ( V_27 < 0 ) {
F_133 ( V_22 ) ;
goto V_30;
}
if ( V_226 )
* V_226 = 1 ;
F_121 ( V_42 ) ;
if ( F_131 ( V_223 ) ) {
V_42 -> V_43 = V_71 | V_70
| V_236 | V_237 ;
V_42 -> V_238 . V_75 = V_227 ;
V_42 -> V_239 . V_75 = V_228 ;
V_42 -> V_238 . V_240 = 0 ;
V_42 -> V_239 . V_240 = 0 ;
}
V_230:
V_11 = F_118 ( V_2 , V_207 , V_42 ) ;
if ( ! V_11 )
V_11 = F_30 ( F_36 ( V_22 ) ) ;
if ( ! V_11 )
V_11 = F_128 ( V_207 ) ;
V_12:
F_29 ( V_22 ) ;
if ( V_212 && ! F_8 ( V_212 ) )
F_16 ( V_212 ) ;
F_133 ( V_22 ) ;
return V_11 ;
V_30:
V_11 = F_30 ( V_27 ) ;
goto V_12;
}
T_1
F_134 ( struct V_1 * V_2 , struct V_21 * V_22 , char * V_161 , int * V_241 )
{
T_1 V_11 ;
const char * V_242 ;
struct V_8 V_8 ;
F_135 ( V_243 ) ;
int V_24 ;
V_11 = F_32 ( V_2 , V_22 , V_244 , V_105 ) ;
if ( F_136 ( V_11 ) )
return V_11 ;
V_8 . V_9 = V_22 -> V_29 -> V_10 . V_9 ;
V_8 . V_3 = V_22 -> V_28 ;
if ( F_136 ( ! F_137 ( V_8 . V_3 ) ) )
return V_96 ;
F_138 ( & V_8 ) ;
V_242 = F_139 ( V_8 . V_3 , & V_243 ) ;
if ( F_8 ( V_242 ) )
return F_30 ( F_9 ( V_242 ) ) ;
V_24 = strlen ( V_242 ) ;
if ( V_24 < * V_241 )
* V_241 = V_24 ;
memcpy ( V_161 , V_242 , * V_241 ) ;
F_140 ( & V_243 ) ;
return 0 ;
}
T_1
F_141 ( struct V_1 * V_2 , struct V_21 * V_22 ,
char * V_209 , int V_210 ,
char * V_8 ,
struct V_21 * V_207 )
{
struct V_3 * V_3 , * V_245 ;
T_1 V_11 , V_246 ;
int V_27 ;
V_11 = V_35 ;
if ( ! V_210 || V_8 [ 0 ] == '\0' )
goto V_12;
V_11 = V_222 ;
if ( F_26 ( V_209 , V_210 ) )
goto V_12;
V_11 = F_32 ( V_2 , V_22 , V_33 , V_216 ) ;
if ( V_11 )
goto V_12;
V_27 = F_47 ( V_22 ) ;
if ( V_27 )
goto V_30;
F_49 ( V_22 ) ;
V_3 = V_22 -> V_28 ;
V_245 = F_28 ( V_209 , V_3 , V_210 ) ;
V_27 = F_9 ( V_245 ) ;
if ( F_8 ( V_245 ) )
goto V_30;
V_27 = F_142 ( F_19 ( V_3 ) , V_245 , V_8 ) ;
V_11 = F_30 ( V_27 ) ;
if ( ! V_11 )
V_11 = F_30 ( F_36 ( V_22 ) ) ;
F_29 ( V_22 ) ;
F_133 ( V_22 ) ;
V_246 = F_34 ( V_207 , V_22 -> V_29 , V_245 , V_22 ) ;
F_16 ( V_245 ) ;
if ( V_11 == 0 ) V_11 = V_246 ;
V_12:
return V_11 ;
V_30:
V_11 = F_30 ( V_27 ) ;
goto V_12;
}
T_1
F_143 ( struct V_1 * V_2 , struct V_21 * V_247 ,
char * V_23 , int V_24 , struct V_21 * V_248 )
{
struct V_3 * V_249 , * V_245 , * V_250 ;
struct V_36 * V_213 ;
T_1 V_11 ;
int V_27 ;
V_11 = F_32 ( V_2 , V_247 , V_33 , V_216 ) ;
if ( V_11 )
goto V_12;
V_11 = F_32 ( V_2 , V_248 , 0 , V_105 ) ;
if ( V_11 )
goto V_12;
V_11 = V_251 ;
if ( F_67 ( V_248 -> V_28 ) )
goto V_12;
V_11 = V_114 ;
if ( ! V_24 )
goto V_12;
V_11 = V_222 ;
if ( F_26 ( V_23 , V_24 ) )
goto V_12;
V_27 = F_47 ( V_248 ) ;
if ( V_27 ) {
V_11 = F_30 ( V_27 ) ;
goto V_12;
}
F_27 ( V_247 , V_31 ) ;
V_249 = V_247 -> V_28 ;
V_213 = F_19 ( V_249 ) ;
V_245 = F_28 ( V_23 , V_249 , V_24 ) ;
V_27 = F_9 ( V_245 ) ;
if ( F_8 ( V_245 ) )
goto V_30;
V_250 = V_248 -> V_28 ;
V_11 = V_35 ;
if ( F_35 ( V_250 ) )
goto V_252;
V_27 = F_144 ( V_250 , V_213 , V_245 , NULL ) ;
if ( ! V_27 ) {
V_11 = F_30 ( F_36 ( V_247 ) ) ;
if ( ! V_11 )
V_11 = F_30 ( F_36 ( V_248 ) ) ;
} else {
if ( V_27 == - V_253 && V_2 -> V_196 == 2 )
V_11 = V_113 ;
else
V_11 = F_30 ( V_27 ) ;
}
V_252:
F_16 ( V_245 ) ;
V_79:
F_29 ( V_247 ) ;
F_133 ( V_248 ) ;
V_12:
return V_11 ;
V_30:
V_11 = F_30 ( V_27 ) ;
goto V_79;
}
T_1
F_145 ( struct V_1 * V_2 , struct V_21 * V_247 , char * V_209 , int V_210 ,
struct V_21 * V_248 , char * V_254 , int V_255 )
{
struct V_3 * V_256 , * V_257 , * V_258 , * V_259 , * V_260 ;
struct V_36 * V_261 , * V_262 ;
T_1 V_11 ;
int V_27 ;
V_11 = F_32 ( V_2 , V_247 , V_33 , V_263 ) ;
if ( V_11 )
goto V_12;
V_11 = F_32 ( V_2 , V_248 , V_33 , V_216 ) ;
if ( V_11 )
goto V_12;
V_256 = V_247 -> V_28 ;
V_261 = F_19 ( V_256 ) ;
V_257 = V_248 -> V_28 ;
V_262 = F_19 ( V_257 ) ;
V_11 = V_114 ;
if ( ! V_210 || F_26 ( V_209 , V_210 ) || ! V_255 || F_26 ( V_254 , V_255 ) )
goto V_12;
V_27 = F_47 ( V_247 ) ;
if ( V_27 ) {
V_11 = F_30 ( V_27 ) ;
goto V_12;
}
V_260 = F_146 ( V_257 , V_256 ) ;
V_247 -> V_214 = V_248 -> V_214 = true ;
F_147 ( V_247 ) ;
F_147 ( V_248 ) ;
V_258 = F_28 ( V_209 , V_256 , V_210 ) ;
V_27 = F_9 ( V_258 ) ;
if ( F_8 ( V_258 ) )
goto V_30;
V_27 = - V_13 ;
if ( F_35 ( V_258 ) )
goto V_264;
V_27 = - V_206 ;
if ( V_258 == V_260 )
goto V_264;
V_259 = F_28 ( V_254 , V_257 , V_255 ) ;
V_27 = F_9 ( V_259 ) ;
if ( F_8 ( V_259 ) )
goto V_264;
V_27 = - V_265 ;
if ( V_259 == V_260 )
goto V_266;
V_27 = - V_253 ;
if ( V_247 -> V_29 -> V_10 . V_9 != V_248 -> V_29 -> V_10 . V_9 )
goto V_266;
if ( V_247 -> V_29 -> V_10 . V_3 != V_248 -> V_29 -> V_10 . V_3 )
goto V_266;
V_27 = F_148 ( V_261 , V_258 , V_262 , V_259 , NULL , 0 ) ;
if ( ! V_27 ) {
V_27 = F_36 ( V_248 ) ;
if ( ! V_27 )
V_27 = F_36 ( V_247 ) ;
}
V_266:
F_16 ( V_259 ) ;
V_264:
F_16 ( V_258 ) ;
V_30:
V_11 = F_30 ( V_27 ) ;
F_149 ( V_247 ) ;
F_149 ( V_248 ) ;
F_150 ( V_257 , V_256 ) ;
V_247 -> V_214 = V_248 -> V_214 = false ;
F_133 ( V_247 ) ;
V_12:
return V_11 ;
}
T_1
F_151 ( struct V_1 * V_2 , struct V_21 * V_22 , int type ,
char * V_209 , int V_210 )
{
struct V_3 * V_3 , * V_267 ;
struct V_36 * V_213 ;
T_1 V_11 ;
int V_27 ;
V_11 = V_113 ;
if ( ! V_210 || F_26 ( V_209 , V_210 ) )
goto V_12;
V_11 = F_32 ( V_2 , V_22 , V_33 , V_263 ) ;
if ( V_11 )
goto V_12;
V_27 = F_47 ( V_22 ) ;
if ( V_27 )
goto V_30;
F_27 ( V_22 , V_31 ) ;
V_3 = V_22 -> V_28 ;
V_213 = F_19 ( V_3 ) ;
V_267 = F_28 ( V_209 , V_3 , V_210 ) ;
V_27 = F_9 ( V_267 ) ;
if ( F_8 ( V_267 ) )
goto V_30;
if ( F_35 ( V_267 ) ) {
F_16 ( V_267 ) ;
V_11 = V_35 ;
goto V_12;
}
if ( ! type )
type = F_19 ( V_267 ) -> V_47 & V_268 ;
if ( type != V_33 )
V_27 = F_152 ( V_213 , V_267 , NULL ) ;
else
V_27 = F_153 ( V_213 , V_267 ) ;
if ( ! V_27 )
V_27 = F_36 ( V_22 ) ;
F_16 ( V_267 ) ;
V_30:
V_11 = F_30 ( V_27 ) ;
V_12:
return V_11 ;
}
static int F_154 ( struct V_269 * V_270 , const char * V_23 ,
int V_271 , T_6 V_94 , T_4 V_133 ,
unsigned int V_272 )
{
struct V_273 * V_161 =
F_155 ( V_270 , struct V_273 , V_270 ) ;
struct V_274 * V_275 = ( void * ) ( V_161 -> V_276 + V_161 -> V_277 ) ;
unsigned int V_278 ;
V_278 = F_156 ( sizeof( struct V_274 ) + V_271 , sizeof( T_4 ) ) ;
if ( V_161 -> V_277 + V_278 > V_279 ) {
V_161 -> V_280 = 1 ;
return - V_206 ;
}
V_275 -> V_271 = V_271 ;
V_275 -> V_94 = V_94 ;
V_275 -> V_133 = V_133 ;
V_275 -> V_272 = V_272 ;
memcpy ( V_275 -> V_23 , V_23 , V_271 ) ;
V_161 -> V_277 += V_278 ;
return 0 ;
}
static T_1 F_157 ( struct V_88 * V_88 , T_12 V_281 ,
struct V_282 * V_283 , T_6 * V_284 )
{
struct V_274 * V_275 ;
int V_27 ;
int V_168 ;
T_6 V_94 ;
struct V_273 V_161 = {
. V_270 . V_285 = F_154 ,
. V_276 = ( void * ) F_158 (GFP_KERNEL)
} ;
if ( ! V_161 . V_276 )
return F_30 ( - V_286 ) ;
V_94 = * V_284 ;
while ( 1 ) {
unsigned int V_278 ;
V_283 -> V_11 = V_287 ;
V_161 . V_277 = 0 ;
V_161 . V_280 = 0 ;
V_27 = F_159 ( V_88 , & V_161 . V_270 ) ;
if ( V_161 . V_280 )
V_27 = 0 ;
if ( V_27 < 0 )
break;
V_168 = V_161 . V_277 ;
if ( ! V_168 )
break;
V_275 = (struct V_274 * ) V_161 . V_276 ;
while ( V_168 > 0 ) {
V_94 = V_275 -> V_94 ;
if ( V_281 ( V_283 , V_275 -> V_23 , V_275 -> V_271 , V_275 -> V_94 ,
V_275 -> V_133 , V_275 -> V_272 ) )
break;
if ( V_283 -> V_11 != V_111 )
break;
V_278 = F_156 ( sizeof( * V_275 ) + V_275 -> V_271 ,
sizeof( T_4 ) ) ;
V_168 -= V_278 ;
V_275 = (struct V_274 * ) ( ( char * ) V_275 + V_278 ) ;
}
if ( V_168 > 0 )
break;
V_94 = F_160 ( V_88 , 0 , V_288 ) ;
}
F_161 ( ( unsigned long ) ( V_161 . V_276 ) ) ;
if ( V_27 )
return F_30 ( V_27 ) ;
* V_284 = V_94 ;
return V_283 -> V_11 ;
}
T_1
F_162 ( struct V_1 * V_2 , struct V_21 * V_22 , T_6 * V_284 ,
struct V_282 * V_283 , T_12 V_281 )
{
T_1 V_11 ;
struct V_88 * V_88 ;
T_6 V_94 = * V_284 ;
int V_120 = V_124 ;
if ( V_2 -> V_196 > 2 )
V_120 |= V_126 ;
V_11 = F_70 ( V_2 , V_22 , V_33 , V_120 , & V_88 ) ;
if ( V_11 )
goto V_12;
V_94 = F_160 ( V_88 , V_94 , V_289 ) ;
if ( V_94 < 0 ) {
V_11 = F_30 ( ( int ) V_94 ) ;
goto V_290;
}
V_11 = F_157 ( V_88 , V_281 , V_283 , V_284 ) ;
if ( V_11 == V_287 || V_11 == V_291 )
V_11 = V_111 ;
V_290:
F_77 ( V_88 ) ;
V_12:
return V_11 ;
}
T_1
F_163 ( struct V_1 * V_2 , struct V_21 * V_22 , struct V_292 * V_293 , int V_97 )
{
T_1 V_11 ;
V_11 = F_32 ( V_2 , V_22 , 0 , V_105 | V_97 ) ;
if ( ! V_11 ) {
struct V_8 V_8 = {
. V_9 = V_22 -> V_29 -> V_10 . V_9 ,
. V_3 = V_22 -> V_28 ,
} ;
if ( F_164 ( & V_8 , V_293 ) )
V_11 = V_215 ;
}
return V_11 ;
}
static int F_165 ( struct V_1 * V_2 , struct V_5 * exp )
{
return F_166 ( V_2 , exp ) & V_294 ;
}
T_1
F_42 ( struct V_1 * V_2 , struct V_5 * exp ,
struct V_3 * V_3 , int V_295 )
{
struct V_36 * V_36 = F_19 ( V_3 ) ;
int V_11 ;
if ( ( V_295 & V_296 ) == V_105 )
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
if ( ! ( V_295 & V_297 ) )
if ( V_295 & ( V_72 | V_65 | V_58 ) ) {
if ( F_165 ( V_2 , exp ) ||
F_167 ( exp -> V_10 . V_9 ) )
return V_112 ;
if ( F_168 ( V_36 ) )
return V_114 ;
}
if ( ( V_295 & V_58 ) && F_72 ( V_36 ) )
return V_114 ;
if ( V_295 & V_298 ) {
if ( exp -> V_14 & V_299 )
return 0 ;
else
V_295 = V_124 | V_59 ;
}
if ( ( V_295 & V_59 ) &&
F_119 ( V_36 -> V_300 , F_120 () ) )
return 0 ;
V_11 = F_169 ( V_36 , V_295 & ( V_301 | V_302 | V_303 ) ) ;
if ( V_11 == - V_304 && F_62 ( V_36 -> V_47 ) &&
( V_295 == ( V_124 | V_59 ) ||
V_295 == ( V_124 | V_305 ) ) )
V_11 = F_169 ( V_36 , V_303 ) ;
return V_11 ? F_30 ( V_11 ) : 0 ;
}
void
F_170 ( void )
{
struct V_130 * V_306 , * V_307 ;
unsigned int V_308 ;
F_23 ( L_8 ) ;
for ( V_308 = 0 ; V_308 < V_309 ; V_308 ++ ) {
V_306 = V_143 [ V_308 ] . V_145 ;
while( V_306 ) {
V_307 = V_306 ;
V_306 = V_306 -> V_146 ;
F_171 ( V_307 ) ;
}
V_143 [ V_308 ] . V_145 = NULL ;
}
}
int
F_172 ( int V_310 )
{
int V_308 ;
int V_311 = 0 ;
int V_312 ;
struct V_130 * * V_306 = NULL ;
if ( V_143 [ 0 ] . V_145 )
return 0 ;
V_312 = F_173 ( V_310 , V_309 ) ;
V_312 = F_174 ( 2 , V_312 ) ;
V_310 = V_312 * V_309 ;
F_23 ( L_9 , V_310 ) ;
for ( V_308 = 0 ; V_308 < V_309 ; V_308 ++ ) {
F_175 ( & V_143 [ V_308 ] . V_144 ) ;
V_306 = & V_143 [ V_308 ] . V_145 ;
for ( V_311 = 0 ; V_311 < V_312 ; V_311 ++ ) {
* V_306 = F_176 ( sizeof( struct V_130 ) , V_313 ) ;
if ( ! * V_306 )
goto V_314;
V_306 = & ( * V_306 ) -> V_146 ;
}
* V_306 = NULL ;
}
V_151 . V_152 = V_310 ;
return 0 ;
V_314:
F_23 ( L_10 ) ;
F_170 () ;
return - V_286 ;
}

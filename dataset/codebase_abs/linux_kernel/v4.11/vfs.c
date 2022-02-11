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
V_36 = F_21 ( V_3 ) ;
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
struct V_36 * V_36 = F_21 ( V_3 ) ;
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
F_53 ( F_21 ( V_3 ) ) ;
V_85 = F_54 ( V_3 , V_84 -> V_86 , V_84 -> V_24 ) ;
F_55 ( F_21 ( V_3 ) ) ;
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
V_36 = F_21 ( V_8 . V_3 ) ;
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
if ( F_6 ( V_88 ) ) {
V_27 = F_7 ( V_88 ) ;
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
T_11 V_179 ;
int V_27 ;
V_179 = F_93 () ;
F_94 ( V_180 ) ;
V_27 = F_95 ( V_88 , (struct V_181 V_182 * ) V_177 , V_178 , & V_94 , 0 ) ;
F_94 ( V_179 ) ;
return F_88 ( V_88 , V_93 , V_27 ) ;
}
static T_1
F_96 ( struct V_1 * V_2 , struct V_88 * V_88 ,
T_6 V_94 , struct V_176 * V_177 , int V_178 , unsigned long * V_93 )
{
if ( V_88 -> V_183 -> V_184 && F_97 ( V_185 , & V_2 -> V_186 ) )
return F_90 ( V_2 , V_88 , V_94 , V_93 ) ;
else
return F_92 ( V_88 , V_94 , V_177 , V_178 , V_93 ) ;
}
static int F_98 ( struct V_88 * V_88 )
{
struct V_36 * V_36 = F_63 ( V_88 ) ;
static T_9 V_187 ;
static T_8 V_188 ;
int V_11 = 0 ;
if ( F_99 ( & V_36 -> V_189 ) > 1
|| ( V_187 == V_36 -> V_134 && V_188 == V_36 -> V_39 -> V_132 ) ) {
F_23 ( L_2 , F_100 ( V_190 ) ) ;
F_101 ( 10 ) ;
F_23 ( L_3 , F_100 ( V_190 ) ) ;
}
if ( V_36 -> V_191 & V_192 ) {
F_23 ( L_4 , F_100 ( V_190 ) ) ;
V_11 = F_102 ( V_88 , 0 ) ;
}
V_187 = V_36 -> V_134 ;
V_188 = V_36 -> V_39 -> V_132 ;
return V_11 ;
}
T_1
F_103 ( struct V_1 * V_2 , struct V_21 * V_22 , struct V_88 * V_88 ,
T_6 V_94 , struct V_176 * V_177 , int V_178 ,
unsigned long * V_193 , int V_194 )
{
struct V_5 * exp ;
T_11 V_179 ;
T_1 V_11 = 0 ;
int V_27 ;
int V_195 ;
T_6 V_174 = V_94 ;
unsigned int V_196 = V_190 -> V_95 ;
int V_95 = 0 ;
if ( F_97 ( V_197 , & V_2 -> V_186 ) )
V_190 -> V_95 |= V_198 ;
exp = V_22 -> V_29 ;
V_195 = ( V_2 -> V_199 == 2 ) && F_104 ( exp ) ;
if ( ! F_37 ( exp ) )
V_194 = V_200 ;
if ( V_194 && ! V_195 )
V_95 |= V_201 ;
V_179 = F_93 () ; F_94 ( V_180 ) ;
V_27 = F_105 ( V_88 , (struct V_181 V_182 * ) V_177 , V_178 , & V_174 , V_95 ) ;
F_94 ( V_179 ) ;
if ( V_27 < 0 )
goto V_30;
* V_193 = V_27 ;
V_151 . V_202 += V_27 ;
F_106 ( V_88 ) ;
if ( V_194 && V_195 )
V_27 = F_98 ( V_88 ) ;
V_30:
F_23 ( L_5 , V_27 ) ;
if ( V_27 >= 0 )
V_11 = 0 ;
else
V_11 = F_30 ( V_27 ) ;
if ( F_97 ( V_197 , & V_2 -> V_186 ) )
F_107 ( V_190 , V_196 , V_198 ) ;
return V_11 ;
}
T_1 F_108 ( struct V_1 * V_2 , struct V_21 * V_22 ,
T_6 V_94 , struct V_176 * V_177 , int V_178 , unsigned long * V_93 )
{
struct V_88 * V_88 ;
struct V_130 * V_135 ;
T_1 V_11 ;
F_109 ( V_2 , V_22 , V_94 , V_178 ) ;
V_11 = F_70 ( V_2 , V_22 , V_73 , V_124 , & V_88 ) ;
if ( V_11 )
return V_11 ;
V_135 = F_78 ( V_88 ) ;
F_110 ( V_2 , V_22 , V_94 , V_178 ) ;
V_11 = F_96 ( V_2 , V_88 , V_94 , V_177 , V_178 , V_93 ) ;
F_111 ( V_2 , V_22 , V_94 , V_178 ) ;
if ( V_135 )
F_82 ( V_88 , V_135 ) ;
F_77 ( V_88 ) ;
F_112 ( V_2 , V_22 , V_94 , V_178 ) ;
return V_11 ;
}
T_1
F_113 ( struct V_1 * V_2 , struct V_21 * V_22 , T_6 V_94 ,
struct V_176 * V_177 , int V_178 , unsigned long * V_193 , int V_194 )
{
struct V_88 * V_88 = NULL ;
T_1 V_11 = 0 ;
F_114 ( V_2 , V_22 , V_94 , V_178 ) ;
V_11 = F_70 ( V_2 , V_22 , V_73 , V_72 , & V_88 ) ;
if ( V_11 )
goto V_12;
F_115 ( V_2 , V_22 , V_94 , V_178 ) ;
V_11 = F_103 ( V_2 , V_22 , V_88 , V_94 , V_177 , V_178 , V_193 , V_194 ) ;
F_116 ( V_2 , V_22 , V_94 , V_178 ) ;
F_77 ( V_88 ) ;
V_12:
F_117 ( V_2 , V_22 , V_94 , V_178 ) ;
return V_11 ;
}
T_1
F_118 ( struct V_1 * V_2 , struct V_21 * V_22 ,
T_6 V_94 , unsigned long V_93 )
{
struct V_88 * V_88 ;
T_6 V_203 = V_204 ;
T_1 V_11 = V_96 ;
if ( V_94 < 0 )
goto V_12;
if ( V_93 != 0 ) {
V_203 = V_94 + ( T_6 ) V_93 - 1 ;
if ( V_203 < V_94 )
goto V_12;
}
V_11 = F_70 ( V_2 , V_22 , V_73 ,
V_72 | V_116 , & V_88 ) ;
if ( V_11 )
goto V_12;
if ( F_37 ( V_22 -> V_29 ) ) {
int V_109 = F_119 ( V_88 , V_94 , V_203 , 0 ) ;
if ( V_109 != - V_205 )
V_11 = F_30 ( V_109 ) ;
else
V_11 = V_87 ;
}
F_77 ( V_88 ) ;
V_12:
return V_11 ;
}
static T_1
F_120 ( struct V_1 * V_2 , struct V_21 * V_206 ,
struct V_41 * V_42 )
{
V_42 -> V_43 &= ~ V_44 ;
if ( ! F_121 ( F_122 () , V_207 ) )
V_42 -> V_43 &= ~ ( V_48 | V_49 ) ;
if ( V_42 -> V_43 )
return F_46 ( V_2 , V_206 , V_42 , 0 , ( T_2 ) 0 ) ;
return F_30 ( F_36 ( V_206 ) ) ;
}
static void
F_123 ( struct V_41 * V_42 )
{
if ( ( V_42 -> V_43 & V_69 ) && ( V_42 -> V_56 == 0 ) )
V_42 -> V_43 &= ~ V_69 ;
}
T_1
F_124 ( struct V_1 * V_2 , struct V_21 * V_22 ,
char * V_208 , int V_209 , struct V_41 * V_42 ,
int type , T_8 V_210 , struct V_21 * V_206 )
{
struct V_3 * V_3 , * V_211 ;
struct V_36 * V_212 ;
T_1 V_11 ;
T_1 V_109 ;
int V_27 ;
V_3 = V_22 -> V_28 ;
V_212 = F_21 ( V_3 ) ;
V_211 = F_3 ( V_206 -> V_28 ) ;
if ( ! V_22 -> V_213 ) {
F_125 ( 1 , L_6 ,
V_3 ) ;
V_11 = V_214 ;
goto V_12;
}
V_11 = F_42 ( V_2 , V_22 -> V_29 , V_3 , V_215 ) ;
if ( V_11 )
goto V_12;
if ( ! ( V_42 -> V_43 & V_44 ) )
V_42 -> V_45 = 0 ;
V_42 -> V_45 = ( V_42 -> V_45 & V_46 ) | type ;
V_11 = 0 ;
V_27 = 0 ;
switch ( type ) {
case V_73 :
V_27 = F_126 ( V_212 , V_211 , V_42 -> V_45 , true ) ;
if ( ! V_27 )
F_123 ( V_42 ) ;
break;
case V_33 :
V_27 = F_127 ( V_212 , V_211 , V_42 -> V_45 ) ;
break;
case V_216 :
case V_217 :
case V_218 :
case V_219 :
V_27 = F_128 ( V_212 , V_211 , V_42 -> V_45 , V_210 ) ;
break;
default:
F_129 ( V_220 L_7 ,
type ) ;
V_27 = - V_205 ;
}
if ( V_27 < 0 )
goto V_30;
V_11 = F_120 ( V_2 , V_206 , V_42 ) ;
V_109 = F_30 ( F_36 ( V_22 ) ) ;
if ( V_109 )
V_11 = V_109 ;
if ( ! V_11 )
V_11 = F_130 ( V_206 ) ;
V_12:
F_15 ( V_211 ) ;
return V_11 ;
V_30:
V_11 = F_30 ( V_27 ) ;
goto V_12;
}
T_1
F_131 ( struct V_1 * V_2 , struct V_21 * V_22 ,
char * V_208 , int V_209 , struct V_41 * V_42 ,
int type , T_8 V_210 , struct V_21 * V_206 )
{
struct V_3 * V_3 , * V_211 = NULL ;
struct V_36 * V_212 ;
T_1 V_11 ;
int V_27 ;
if ( F_26 ( V_208 , V_209 ) )
return V_221 ;
V_11 = F_32 ( V_2 , V_22 , V_33 , V_105 ) ;
if ( V_11 )
return V_11 ;
V_3 = V_22 -> V_28 ;
V_212 = F_21 ( V_3 ) ;
V_27 = F_47 ( V_22 ) ;
if ( V_27 )
return F_30 ( V_27 ) ;
F_27 ( V_22 , V_31 ) ;
V_211 = F_28 ( V_208 , V_3 , V_209 ) ;
V_27 = F_7 ( V_211 ) ;
if ( F_6 ( V_211 ) )
return F_30 ( V_27 ) ;
V_11 = F_34 ( V_206 , V_22 -> V_29 , V_211 , V_22 ) ;
F_15 ( V_211 ) ;
if ( V_11 )
return V_11 ;
return F_124 ( V_2 , V_22 , V_208 , V_209 , V_42 , type ,
V_210 , V_206 ) ;
}
T_1
F_132 ( struct V_1 * V_2 , struct V_21 * V_22 ,
char * V_208 , int V_209 , struct V_41 * V_42 ,
struct V_21 * V_206 , int V_222 , T_7 * V_223 ,
bool * V_224 , bool * V_225 )
{
struct V_3 * V_3 , * V_211 = NULL ;
struct V_36 * V_212 ;
T_1 V_11 ;
int V_27 ;
T_12 V_226 = 0 , V_227 = 0 ;
V_11 = V_114 ;
if ( ! V_209 )
goto V_12;
V_11 = V_221 ;
if ( F_26 ( V_208 , V_209 ) )
goto V_12;
if ( ! ( V_42 -> V_43 & V_44 ) )
V_42 -> V_45 = 0 ;
V_11 = F_32 ( V_2 , V_22 , V_33 , V_34 ) ;
if ( V_11 )
goto V_12;
V_3 = V_22 -> V_28 ;
V_212 = F_21 ( V_3 ) ;
V_27 = F_47 ( V_22 ) ;
if ( V_27 )
goto V_30;
F_27 ( V_22 , V_31 ) ;
V_211 = F_28 ( V_208 , V_3 , V_209 ) ;
V_27 = F_7 ( V_211 ) ;
if ( F_6 ( V_211 ) )
goto V_30;
if ( F_35 ( V_211 ) ) {
V_11 = F_32 ( V_2 , V_22 , V_33 , V_215 ) ;
if ( V_11 )
goto V_12;
}
V_11 = F_34 ( V_206 , V_22 -> V_29 , V_211 , V_22 ) ;
if ( V_11 )
goto V_12;
if ( F_133 ( V_222 ) ) {
V_226 = V_223 [ 0 ] & 0x7fffffff ;
V_227 = V_223 [ 1 ] & 0x7fffffff ;
}
if ( F_134 ( V_211 ) ) {
V_11 = 0 ;
switch ( V_222 ) {
case V_228 :
if ( ! F_66 ( V_211 ) )
goto V_12;
else if ( V_224 ) {
* V_224 = ( V_42 -> V_43 & V_69 ) && ! V_42 -> V_56 ;
}
else {
V_42 -> V_43 &= V_69 ;
goto V_229;
}
break;
case V_230 :
if ( F_21 ( V_211 ) -> V_231 . V_75 == V_226
&& F_21 ( V_211 ) -> V_232 . V_75 == V_227
&& F_21 ( V_211 ) -> V_57 == 0 ) {
if ( V_225 )
* V_225 = 1 ;
break;
}
case V_233 :
if ( F_21 ( V_211 ) -> V_231 . V_75 == V_226
&& F_21 ( V_211 ) -> V_232 . V_75 == V_227
&& F_21 ( V_211 ) -> V_57 == 0 ) {
if ( V_225 )
* V_225 = 1 ;
goto V_229;
}
case V_234 :
V_11 = V_221 ;
}
F_135 ( V_22 ) ;
goto V_12;
}
V_27 = F_126 ( V_212 , V_211 , V_42 -> V_45 , true ) ;
if ( V_27 < 0 ) {
F_135 ( V_22 ) ;
goto V_30;
}
if ( V_225 )
* V_225 = 1 ;
F_123 ( V_42 ) ;
if ( F_133 ( V_222 ) ) {
V_42 -> V_43 = V_71 | V_70
| V_235 | V_236 ;
V_42 -> V_237 . V_75 = V_226 ;
V_42 -> V_238 . V_75 = V_227 ;
V_42 -> V_237 . V_239 = 0 ;
V_42 -> V_238 . V_239 = 0 ;
}
V_229:
V_11 = F_120 ( V_2 , V_206 , V_42 ) ;
if ( ! V_11 )
V_11 = F_30 ( F_36 ( V_22 ) ) ;
if ( ! V_11 )
V_11 = F_130 ( V_206 ) ;
V_12:
F_29 ( V_22 ) ;
if ( V_211 && ! F_6 ( V_211 ) )
F_15 ( V_211 ) ;
F_135 ( V_22 ) ;
return V_11 ;
V_30:
V_11 = F_30 ( V_27 ) ;
goto V_12;
}
T_1
F_136 ( struct V_1 * V_2 , struct V_21 * V_22 , char * V_161 , int * V_240 )
{
T_11 V_179 ;
T_1 V_11 ;
int V_27 ;
struct V_8 V_8 ;
V_11 = F_32 ( V_2 , V_22 , V_241 , V_105 ) ;
if ( V_11 )
goto V_12;
V_8 . V_9 = V_22 -> V_29 -> V_10 . V_9 ;
V_8 . V_3 = V_22 -> V_28 ;
V_11 = V_96 ;
if ( ! F_137 ( V_8 . V_3 ) )
goto V_12;
F_138 ( & V_8 ) ;
V_179 = F_93 () ; F_94 ( V_180 ) ;
V_27 = F_139 ( V_8 . V_3 , ( char V_182 * ) V_161 , * V_240 ) ;
F_94 ( V_179 ) ;
if ( V_27 < 0 )
goto V_30;
* V_240 = V_27 ;
V_11 = 0 ;
V_12:
return V_11 ;
V_30:
V_11 = F_30 ( V_27 ) ;
goto V_12;
}
T_1
F_140 ( struct V_1 * V_2 , struct V_21 * V_22 ,
char * V_208 , int V_209 ,
char * V_8 ,
struct V_21 * V_206 )
{
struct V_3 * V_3 , * V_242 ;
T_1 V_11 , V_243 ;
int V_27 ;
V_11 = V_35 ;
if ( ! V_209 || V_8 [ 0 ] == '\0' )
goto V_12;
V_11 = V_221 ;
if ( F_26 ( V_208 , V_209 ) )
goto V_12;
V_11 = F_32 ( V_2 , V_22 , V_33 , V_215 ) ;
if ( V_11 )
goto V_12;
V_27 = F_47 ( V_22 ) ;
if ( V_27 )
goto V_30;
F_49 ( V_22 ) ;
V_3 = V_22 -> V_28 ;
V_242 = F_28 ( V_208 , V_3 , V_209 ) ;
V_27 = F_7 ( V_242 ) ;
if ( F_6 ( V_242 ) )
goto V_30;
V_27 = F_141 ( F_21 ( V_3 ) , V_242 , V_8 ) ;
V_11 = F_30 ( V_27 ) ;
if ( ! V_11 )
V_11 = F_30 ( F_36 ( V_22 ) ) ;
F_29 ( V_22 ) ;
F_135 ( V_22 ) ;
V_243 = F_34 ( V_206 , V_22 -> V_29 , V_242 , V_22 ) ;
F_15 ( V_242 ) ;
if ( V_11 == 0 ) V_11 = V_243 ;
V_12:
return V_11 ;
V_30:
V_11 = F_30 ( V_27 ) ;
goto V_12;
}
T_1
F_142 ( struct V_1 * V_2 , struct V_21 * V_244 ,
char * V_23 , int V_24 , struct V_21 * V_245 )
{
struct V_3 * V_246 , * V_242 , * V_247 ;
struct V_36 * V_212 ;
T_1 V_11 ;
int V_27 ;
V_11 = F_32 ( V_2 , V_244 , V_33 , V_215 ) ;
if ( V_11 )
goto V_12;
V_11 = F_32 ( V_2 , V_245 , 0 , V_105 ) ;
if ( V_11 )
goto V_12;
V_11 = V_248 ;
if ( F_67 ( V_245 -> V_28 ) )
goto V_12;
V_11 = V_114 ;
if ( ! V_24 )
goto V_12;
V_11 = V_221 ;
if ( F_26 ( V_23 , V_24 ) )
goto V_12;
V_27 = F_47 ( V_245 ) ;
if ( V_27 ) {
V_11 = F_30 ( V_27 ) ;
goto V_12;
}
F_27 ( V_244 , V_31 ) ;
V_246 = V_244 -> V_28 ;
V_212 = F_21 ( V_246 ) ;
V_242 = F_28 ( V_23 , V_246 , V_24 ) ;
V_27 = F_7 ( V_242 ) ;
if ( F_6 ( V_242 ) )
goto V_30;
V_247 = V_245 -> V_28 ;
V_11 = V_35 ;
if ( F_35 ( V_247 ) )
goto V_249;
V_27 = F_143 ( V_247 , V_212 , V_242 , NULL ) ;
if ( ! V_27 ) {
V_11 = F_30 ( F_36 ( V_244 ) ) ;
if ( ! V_11 )
V_11 = F_30 ( F_36 ( V_245 ) ) ;
} else {
if ( V_27 == - V_250 && V_2 -> V_199 == 2 )
V_11 = V_113 ;
else
V_11 = F_30 ( V_27 ) ;
}
V_249:
F_15 ( V_242 ) ;
V_79:
F_29 ( V_244 ) ;
F_135 ( V_245 ) ;
V_12:
return V_11 ;
V_30:
V_11 = F_30 ( V_27 ) ;
goto V_79;
}
T_1
F_144 ( struct V_1 * V_2 , struct V_21 * V_244 , char * V_208 , int V_209 ,
struct V_21 * V_245 , char * V_251 , int V_252 )
{
struct V_3 * V_253 , * V_254 , * V_255 , * V_256 , * V_257 ;
struct V_36 * V_258 , * V_259 ;
T_1 V_11 ;
int V_27 ;
V_11 = F_32 ( V_2 , V_244 , V_33 , V_260 ) ;
if ( V_11 )
goto V_12;
V_11 = F_32 ( V_2 , V_245 , V_33 , V_215 ) ;
if ( V_11 )
goto V_12;
V_253 = V_244 -> V_28 ;
V_258 = F_21 ( V_253 ) ;
V_254 = V_245 -> V_28 ;
V_259 = F_21 ( V_254 ) ;
V_11 = V_114 ;
if ( ! V_209 || F_26 ( V_208 , V_209 ) || ! V_252 || F_26 ( V_251 , V_252 ) )
goto V_12;
V_27 = F_47 ( V_244 ) ;
if ( V_27 ) {
V_11 = F_30 ( V_27 ) ;
goto V_12;
}
V_257 = F_145 ( V_254 , V_253 ) ;
V_244 -> V_213 = V_245 -> V_213 = true ;
F_146 ( V_244 ) ;
F_146 ( V_245 ) ;
V_255 = F_28 ( V_208 , V_253 , V_209 ) ;
V_27 = F_7 ( V_255 ) ;
if ( F_6 ( V_255 ) )
goto V_30;
V_27 = - V_13 ;
if ( F_35 ( V_255 ) )
goto V_261;
V_27 = - V_205 ;
if ( V_255 == V_257 )
goto V_261;
V_256 = F_28 ( V_251 , V_254 , V_252 ) ;
V_27 = F_7 ( V_256 ) ;
if ( F_6 ( V_256 ) )
goto V_261;
V_27 = - V_262 ;
if ( V_256 == V_257 )
goto V_263;
V_27 = - V_250 ;
if ( V_244 -> V_29 -> V_10 . V_9 != V_245 -> V_29 -> V_10 . V_9 )
goto V_263;
if ( V_244 -> V_29 -> V_10 . V_3 != V_245 -> V_29 -> V_10 . V_3 )
goto V_263;
V_27 = F_147 ( V_258 , V_255 , V_259 , V_256 , NULL , 0 ) ;
if ( ! V_27 ) {
V_27 = F_36 ( V_245 ) ;
if ( ! V_27 )
V_27 = F_36 ( V_244 ) ;
}
V_263:
F_15 ( V_256 ) ;
V_261:
F_15 ( V_255 ) ;
V_30:
V_11 = F_30 ( V_27 ) ;
F_148 ( V_244 ) ;
F_148 ( V_245 ) ;
F_149 ( V_254 , V_253 ) ;
V_244 -> V_213 = V_245 -> V_213 = false ;
F_135 ( V_244 ) ;
V_12:
return V_11 ;
}
T_1
F_150 ( struct V_1 * V_2 , struct V_21 * V_22 , int type ,
char * V_208 , int V_209 )
{
struct V_3 * V_3 , * V_264 ;
struct V_36 * V_212 ;
T_1 V_11 ;
int V_27 ;
V_11 = V_113 ;
if ( ! V_209 || F_26 ( V_208 , V_209 ) )
goto V_12;
V_11 = F_32 ( V_2 , V_22 , V_33 , V_260 ) ;
if ( V_11 )
goto V_12;
V_27 = F_47 ( V_22 ) ;
if ( V_27 )
goto V_30;
F_27 ( V_22 , V_31 ) ;
V_3 = V_22 -> V_28 ;
V_212 = F_21 ( V_3 ) ;
V_264 = F_28 ( V_208 , V_3 , V_209 ) ;
V_27 = F_7 ( V_264 ) ;
if ( F_6 ( V_264 ) )
goto V_30;
if ( F_35 ( V_264 ) ) {
F_15 ( V_264 ) ;
V_11 = V_35 ;
goto V_12;
}
if ( ! type )
type = F_21 ( V_264 ) -> V_47 & V_265 ;
if ( type != V_33 )
V_27 = F_151 ( V_212 , V_264 , NULL ) ;
else
V_27 = F_152 ( V_212 , V_264 ) ;
if ( ! V_27 )
V_27 = F_36 ( V_22 ) ;
F_15 ( V_264 ) ;
V_30:
V_11 = F_30 ( V_27 ) ;
V_12:
return V_11 ;
}
static int F_153 ( struct V_266 * V_267 , const char * V_23 ,
int V_268 , T_6 V_94 , T_4 V_133 ,
unsigned int V_269 )
{
struct V_270 * V_161 =
F_154 ( V_267 , struct V_270 , V_267 ) ;
struct V_271 * V_272 = ( void * ) ( V_161 -> V_273 + V_161 -> V_274 ) ;
unsigned int V_275 ;
V_275 = F_155 ( sizeof( struct V_271 ) + V_268 , sizeof( T_4 ) ) ;
if ( V_161 -> V_274 + V_275 > V_276 ) {
V_161 -> V_277 = 1 ;
return - V_205 ;
}
V_272 -> V_268 = V_268 ;
V_272 -> V_94 = V_94 ;
V_272 -> V_133 = V_133 ;
V_272 -> V_269 = V_269 ;
memcpy ( V_272 -> V_23 , V_23 , V_268 ) ;
V_161 -> V_274 += V_275 ;
return 0 ;
}
static T_1 F_156 ( struct V_88 * V_88 , T_13 V_278 ,
struct V_279 * V_280 , T_6 * V_281 )
{
struct V_271 * V_272 ;
int V_27 ;
int V_168 ;
T_6 V_94 ;
struct V_270 V_161 = {
. V_267 . V_282 = F_153 ,
. V_273 = ( void * ) F_157 (GFP_KERNEL)
} ;
if ( ! V_161 . V_273 )
return F_30 ( - V_283 ) ;
V_94 = * V_281 ;
while ( 1 ) {
unsigned int V_275 ;
V_280 -> V_11 = V_284 ;
V_161 . V_274 = 0 ;
V_161 . V_277 = 0 ;
V_27 = F_158 ( V_88 , & V_161 . V_267 ) ;
if ( V_161 . V_277 )
V_27 = 0 ;
if ( V_27 < 0 )
break;
V_168 = V_161 . V_274 ;
if ( ! V_168 )
break;
V_272 = (struct V_271 * ) V_161 . V_273 ;
while ( V_168 > 0 ) {
V_94 = V_272 -> V_94 ;
if ( V_278 ( V_280 , V_272 -> V_23 , V_272 -> V_268 , V_272 -> V_94 ,
V_272 -> V_133 , V_272 -> V_269 ) )
break;
if ( V_280 -> V_11 != V_111 )
break;
V_275 = F_155 ( sizeof( * V_272 ) + V_272 -> V_268 ,
sizeof( T_4 ) ) ;
V_168 -= V_275 ;
V_272 = (struct V_271 * ) ( ( char * ) V_272 + V_275 ) ;
}
if ( V_168 > 0 )
break;
V_94 = F_159 ( V_88 , 0 , V_285 ) ;
}
F_160 ( ( unsigned long ) ( V_161 . V_273 ) ) ;
if ( V_27 )
return F_30 ( V_27 ) ;
* V_281 = V_94 ;
return V_280 -> V_11 ;
}
T_1
F_161 ( struct V_1 * V_2 , struct V_21 * V_22 , T_6 * V_281 ,
struct V_279 * V_280 , T_13 V_278 )
{
T_1 V_11 ;
struct V_88 * V_88 ;
T_6 V_94 = * V_281 ;
int V_120 = V_124 ;
if ( V_2 -> V_199 > 2 )
V_120 |= V_126 ;
V_11 = F_70 ( V_2 , V_22 , V_33 , V_120 , & V_88 ) ;
if ( V_11 )
goto V_12;
V_94 = F_159 ( V_88 , V_94 , V_286 ) ;
if ( V_94 < 0 ) {
V_11 = F_30 ( ( int ) V_94 ) ;
goto V_287;
}
V_11 = F_156 ( V_88 , V_278 , V_280 , V_281 ) ;
if ( V_11 == V_284 || V_11 == V_288 )
V_11 = V_111 ;
V_287:
F_77 ( V_88 ) ;
V_12:
return V_11 ;
}
T_1
F_162 ( struct V_1 * V_2 , struct V_21 * V_22 , struct V_289 * V_290 , int V_97 )
{
T_1 V_11 ;
V_11 = F_32 ( V_2 , V_22 , 0 , V_105 | V_97 ) ;
if ( ! V_11 ) {
struct V_8 V_8 = {
. V_9 = V_22 -> V_29 -> V_10 . V_9 ,
. V_3 = V_22 -> V_28 ,
} ;
if ( F_163 ( & V_8 , V_290 ) )
V_11 = V_214 ;
}
return V_11 ;
}
static int F_164 ( struct V_1 * V_2 , struct V_5 * exp )
{
return F_165 ( V_2 , exp ) & V_291 ;
}
T_1
F_42 ( struct V_1 * V_2 , struct V_5 * exp ,
struct V_3 * V_3 , int V_292 )
{
struct V_36 * V_36 = F_21 ( V_3 ) ;
int V_11 ;
if ( ( V_292 & V_293 ) == V_105 )
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
if ( ! ( V_292 & V_294 ) )
if ( V_292 & ( V_72 | V_65 | V_58 ) ) {
if ( F_164 ( V_2 , exp ) ||
F_166 ( exp -> V_10 . V_9 ) )
return V_112 ;
if ( F_167 ( V_36 ) )
return V_114 ;
}
if ( ( V_292 & V_58 ) && F_72 ( V_36 ) )
return V_114 ;
if ( V_292 & V_295 ) {
if ( exp -> V_14 & V_296 )
return 0 ;
else
V_292 = V_124 | V_59 ;
}
if ( ( V_292 & V_59 ) &&
F_121 ( V_36 -> V_297 , F_122 () ) )
return 0 ;
V_11 = F_168 ( V_36 , V_292 & ( V_298 | V_299 | V_300 ) ) ;
if ( V_11 == - V_301 && F_62 ( V_36 -> V_47 ) &&
( V_292 == ( V_124 | V_59 ) ||
V_292 == ( V_124 | V_302 ) ) )
V_11 = F_168 ( V_36 , V_300 ) ;
return V_11 ? F_30 ( V_11 ) : 0 ;
}
void
F_169 ( void )
{
struct V_130 * V_303 , * V_304 ;
unsigned int V_305 ;
F_23 ( L_8 ) ;
for ( V_305 = 0 ; V_305 < V_306 ; V_305 ++ ) {
V_303 = V_143 [ V_305 ] . V_145 ;
while( V_303 ) {
V_304 = V_303 ;
V_303 = V_303 -> V_146 ;
F_170 ( V_304 ) ;
}
V_143 [ V_305 ] . V_145 = NULL ;
}
}
int
F_171 ( int V_307 )
{
int V_305 ;
int V_308 = 0 ;
int V_309 ;
struct V_130 * * V_303 = NULL ;
if ( V_143 [ 0 ] . V_145 )
return 0 ;
V_309 = F_172 ( V_307 , V_306 ) ;
V_309 = F_173 ( 2 , V_309 ) ;
V_307 = V_309 * V_306 ;
F_23 ( L_9 , V_307 ) ;
for ( V_305 = 0 ; V_305 < V_306 ; V_305 ++ ) {
F_174 ( & V_143 [ V_305 ] . V_144 ) ;
V_303 = & V_143 [ V_305 ] . V_145 ;
for ( V_308 = 0 ; V_308 < V_309 ; V_308 ++ ) {
* V_303 = F_175 ( sizeof( struct V_130 ) , V_310 ) ;
if ( ! * V_303 )
goto V_311;
V_303 = & ( * V_303 ) -> V_146 ;
}
* V_303 = NULL ;
}
V_151 . V_152 = V_307 ;
return 0 ;
V_311:
F_23 ( L_10 ) ;
F_169 () ;
return - V_283 ;
}

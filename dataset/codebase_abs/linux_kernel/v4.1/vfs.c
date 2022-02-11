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
#define F_39 (ATTR_ATIME_SET | ATTR_MTIME_SET)
#define F_40 (30*60)
if ( ( V_42 -> V_43 & F_39 ) == F_39 &&
V_42 -> V_44 . V_45 == V_42 -> V_46 . V_45 ) {
T_2 V_47 = V_42 -> V_46 . V_45 - F_41 () ;
if ( V_47 < 0 )
V_47 = - V_47 ;
if ( V_47 < F_40 &&
F_42 ( V_36 , V_42 ) != 0 ) {
V_42 -> V_43 &= ~ F_39 ;
}
}
if ( V_42 -> V_43 & V_48 ) {
V_42 -> V_49 &= V_50 ;
V_42 -> V_49 |= ( V_36 -> V_51 & ~ V_50 ) ;
}
if ( ! F_43 ( V_36 -> V_51 ) &&
( ( V_42 -> V_43 & V_52 ) || ( V_42 -> V_43 & V_53 ) ) ) {
V_42 -> V_43 |= V_54 ;
if ( V_42 -> V_43 & V_48 ) {
V_42 -> V_49 &= ~ V_55 ;
if ( V_42 -> V_49 & V_56 )
V_42 -> V_49 &= ~ V_57 ;
} else {
V_42 -> V_43 |= ( V_58 | V_59 ) ;
}
}
}
static T_1
F_44 ( struct V_1 * V_2 , struct V_21 * V_22 ,
struct V_41 * V_42 )
{
struct V_36 * V_36 = F_21 ( V_22 -> V_28 ) ;
int V_27 ;
if ( V_42 -> V_60 < V_36 -> V_61 ) {
T_1 V_11 ;
V_11 = F_45 ( V_2 , V_22 -> V_29 , V_22 -> V_28 ,
V_62 | V_63 ) ;
if ( V_11 )
return V_11 ;
}
V_27 = F_46 ( V_36 ) ;
if ( V_27 )
goto V_64;
V_27 = F_47 ( V_36 , NULL , V_42 -> V_60 ) ;
if ( V_27 )
goto V_65;
return 0 ;
V_65:
F_48 ( V_36 ) ;
V_64:
return F_29 ( V_27 ) ;
}
T_1
F_49 ( struct V_1 * V_2 , struct V_21 * V_22 , struct V_41 * V_42 ,
int V_66 , T_2 V_67 )
{
struct V_3 * V_3 ;
struct V_36 * V_36 ;
int V_68 = V_69 ;
T_3 V_70 = 0 ;
T_1 V_11 ;
int V_27 ;
bool V_71 ;
int V_72 = 0 ;
if ( V_42 -> V_43 & ( V_73 | V_74 | V_75 ) )
V_68 |= V_76 | V_63 ;
if ( V_42 -> V_43 & V_75 )
V_70 = V_77 ;
V_71 = ! V_22 -> V_28 ;
V_11 = F_31 ( V_2 , V_22 , V_70 , V_68 ) ;
if ( V_11 )
goto V_12;
if ( V_71 ) {
V_27 = F_50 ( V_22 ) ;
if ( V_27 )
return F_29 ( V_27 ) ;
}
V_3 = V_22 -> V_28 ;
V_36 = F_21 ( V_3 ) ;
if ( F_51 ( V_36 -> V_51 ) )
V_42 -> V_43 &= ~ V_48 ;
if ( ! V_42 -> V_43 )
goto V_12;
F_38 ( V_36 , V_42 ) ;
if ( V_42 -> V_43 & V_75 ) {
V_11 = F_44 ( V_2 , V_22 , V_42 ) ;
if ( V_11 )
goto V_12;
V_72 = 1 ;
if ( V_42 -> V_60 != F_52 ( V_36 ) )
V_42 -> V_43 |= V_74 ;
}
V_42 -> V_43 |= V_78 ;
if ( V_66 && V_67 != V_36 -> V_79 . V_45 ) {
V_11 = V_80 ;
goto V_65;
}
F_53 ( V_22 ) ;
V_27 = F_54 ( V_3 , V_42 , NULL ) ;
F_55 ( V_22 ) ;
V_11 = F_29 ( V_27 ) ;
V_65:
if ( V_72 )
F_48 ( V_36 ) ;
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
if ( V_36 -> V_51 & V_81 )
return 0 ;
if ( ! ( V_36 -> V_51 & V_82 ) )
return 0 ;
if ( F_56 ( V_3 , V_83 , NULL , 0 ) <= 0 )
return 0 ;
return 1 ;
}
T_1 F_57 ( struct V_1 * V_2 , struct V_21 * V_22 ,
struct V_84 * V_85 )
{
T_1 error ;
int V_86 ;
struct V_3 * V_3 ;
error = F_31 ( V_2 , V_22 , 0 , V_69 ) ;
if ( error )
return error ;
V_3 = V_22 -> V_28 ;
F_58 ( & F_21 ( V_3 ) -> V_87 ) ;
V_86 = F_59 ( V_3 , V_85 -> V_88 , V_85 -> V_24 ) ;
F_60 ( & F_21 ( V_3 ) -> V_87 ) ;
return F_29 ( V_86 ) ;
}
T_1 F_57 ( struct V_1 * V_2 , struct V_21 * V_22 ,
struct V_84 * V_85 )
{
return V_89 ;
}
T_1 F_61 ( struct V_1 * V_2 , struct V_21 * V_22 ,
struct V_90 * V_90 , T_4 V_91 , T_4 V_24 ,
int V_92 )
{
T_1 V_11 ;
int error ;
if ( ! F_62 ( F_63 ( V_90 ) -> V_51 ) )
return V_93 ;
V_11 = F_45 ( V_2 , V_22 -> V_29 , V_22 -> V_28 , V_76 ) ;
if ( V_11 )
return V_11 ;
error = F_64 ( V_90 , V_92 , V_91 , V_24 ) ;
if ( ! error )
error = F_35 ( V_22 ) ;
return F_29 ( error ) ;
}
T_1
F_65 ( struct V_1 * V_2 , struct V_21 * V_22 , T_5 * V_94 , T_5 * V_95 )
{
struct V_96 * V_97 ;
struct V_5 * V_98 ;
struct V_3 * V_3 ;
T_5 V_99 , V_100 = 0 , V_101 = 0 ;
T_1 error ;
error = F_31 ( V_2 , V_22 , 0 , V_102 ) ;
if ( error )
goto V_12;
V_98 = V_22 -> V_29 ;
V_3 = V_22 -> V_28 ;
if ( F_66 ( V_3 ) )
V_97 = V_103 ;
else if ( F_67 ( V_3 ) )
V_97 = V_104 ;
else
V_97 = V_105 ;
V_99 = * V_94 ;
for (; V_97 -> V_94 ; V_97 ++ ) {
if ( V_97 -> V_94 & V_99 ) {
T_1 V_106 ;
V_101 |= V_97 -> V_94 ;
V_106 = F_45 ( V_2 , V_98 , V_3 , V_97 -> V_107 ) ;
switch ( V_106 ) {
case V_108 :
V_100 |= V_97 -> V_94 ;
break;
case V_109 :
case V_110 :
case V_111 :
break;
default:
error = V_106 ;
goto V_12;
}
}
}
* V_94 = V_100 ;
if ( V_95 )
* V_95 = V_101 ;
V_12:
return error ;
}
static int F_68 ( struct V_36 * V_36 , int V_94 )
{
unsigned int V_112 ;
if ( V_94 & V_113 )
return 0 ;
V_112 = ( V_94 & V_76 ) ? V_114 : V_115 ;
return F_69 ( V_36 , V_112 | V_116 ) ;
}
T_1
F_70 ( struct V_1 * V_2 , struct V_21 * V_22 , T_3 type ,
int V_117 , struct V_90 * * V_118 )
{
struct V_8 V_8 ;
struct V_36 * V_36 ;
struct V_90 * V_90 ;
int V_92 = V_115 | V_119 ;
T_1 V_11 ;
int V_27 = 0 ;
F_71 () ;
if ( type == V_77 )
V_117 |= V_63 ;
V_11 = F_31 ( V_2 , V_22 , type , V_117 ) ;
if ( V_11 )
goto V_12;
V_8 . V_9 = V_22 -> V_29 -> V_10 . V_9 ;
V_8 . V_3 = V_22 -> V_28 ;
V_36 = F_21 ( V_8 . V_3 ) ;
V_11 = V_111 ;
if ( F_72 ( V_36 ) && ( V_117 & V_76 ) )
goto V_12;
if ( F_62 ( ( V_36 ) -> V_51 ) && F_73 ( V_36 ) )
goto V_12;
if ( ! V_36 -> V_120 )
goto V_12;
V_27 = F_68 ( V_36 , V_117 ) ;
if ( V_27 )
goto V_30;
if ( V_117 & V_76 ) {
if ( V_117 & V_121 )
V_92 = V_122 | V_119 ;
else
V_92 = V_114 | V_119 ;
}
V_90 = F_74 ( & V_8 , V_92 , F_75 () ) ;
if ( F_6 ( V_90 ) ) {
V_27 = F_7 ( V_90 ) ;
goto V_30;
}
V_27 = F_76 ( V_90 , V_117 , 0 ) ;
if ( V_27 ) {
F_77 ( V_90 ) ;
goto V_30;
}
if ( V_117 & V_123 )
V_90 -> V_124 |= V_125 ;
else
V_90 -> V_124 |= V_126 ;
* V_118 = V_90 ;
V_30:
V_11 = F_29 ( V_27 ) ;
V_12:
F_71 () ;
return V_11 ;
}
void
F_77 ( struct V_90 * V_118 )
{
F_78 ( V_118 ) ;
}
static inline struct V_127 *
F_79 ( T_6 V_128 , T_7 V_129 )
{
struct V_127 * V_130 , * * V_131 , * * V_132 = NULL ;
int V_133 = 0 ;
unsigned int V_134 ;
struct V_135 * V_136 ;
V_134 = F_80 ( V_128 , V_129 , 0xfeedbeef ) & V_137 ;
V_136 = & V_138 [ V_134 ] ;
F_81 ( & V_136 -> V_139 ) ;
for ( V_131 = & V_136 -> V_140 ; ( V_130 = * V_131 ) ; V_131 = & V_130 -> V_141 ) {
if ( V_130 -> V_142 == V_129 && V_130 -> V_143 == V_128 )
goto V_144;
V_133 ++ ;
if ( V_130 -> V_145 == 0 )
V_132 = V_131 ;
}
V_133 = V_146 . V_147 ;
if ( ! V_132 ) {
F_82 ( & V_136 -> V_139 ) ;
return NULL ;
}
V_131 = V_132 ;
V_130 = * V_132 ;
V_130 -> V_143 = V_128 ;
V_130 -> V_142 = V_129 ;
V_130 -> V_148 = 0 ;
V_130 -> V_149 = V_134 ;
V_144:
if ( V_131 != & V_136 -> V_140 ) {
* V_131 = V_130 -> V_141 ;
V_130 -> V_141 = V_136 -> V_140 ;
V_136 -> V_140 = V_130 ;
}
V_130 -> V_145 ++ ;
V_146 . V_150 [ V_133 * 10 / V_146 . V_147 ] ++ ;
F_82 ( & V_136 -> V_139 ) ;
return V_130 ;
}
static int
F_83 ( struct V_151 * V_152 , struct V_153 * V_154 ,
struct V_155 * V_156 )
{
struct V_1 * V_2 = V_156 -> V_157 . V_88 ;
struct V_158 * * V_159 = V_2 -> V_160 ;
struct V_158 * V_158 = V_154 -> V_158 ;
T_8 V_161 ;
V_161 = V_156 -> V_24 ;
if ( V_2 -> V_162 . V_163 == 0 ) {
F_84 ( V_158 ) ;
F_85 ( * V_2 -> V_160 ) ;
* ( V_2 -> V_160 ++ ) = V_158 ;
V_2 -> V_162 . V_164 = V_154 -> V_91 ;
V_2 -> V_162 . V_163 = V_161 ;
} else if ( V_158 != V_159 [ - 1 ] ) {
F_84 ( V_158 ) ;
if ( * V_2 -> V_160 )
F_85 ( * V_2 -> V_160 ) ;
* ( V_2 -> V_160 ++ ) = V_158 ;
V_2 -> V_162 . V_163 += V_161 ;
} else
V_2 -> V_162 . V_163 += V_161 ;
return V_161 ;
}
static int F_86 ( struct V_151 * V_152 ,
struct V_155 * V_156 )
{
return F_87 ( V_152 , V_156 , F_83 ) ;
}
static T_1
F_88 ( struct V_90 * V_90 , unsigned long * V_165 , int V_27 )
{
if ( V_27 >= 0 ) {
V_146 . V_166 += V_27 ;
* V_165 = V_27 ;
F_89 ( V_90 ) ;
return 0 ;
} else
return F_29 ( V_27 ) ;
}
T_1 F_90 ( struct V_1 * V_2 ,
struct V_90 * V_90 , T_4 V_91 , unsigned long * V_165 )
{
struct V_155 V_156 = {
. V_24 = 0 ,
. V_167 = * V_165 ,
. V_168 = V_91 ,
. V_157 . V_88 = V_2 ,
} ;
int V_27 ;
V_2 -> V_160 = V_2 -> V_169 + 1 ;
V_27 = F_91 ( V_90 , & V_156 , F_86 ) ;
return F_88 ( V_90 , V_165 , V_27 ) ;
}
T_1 F_92 ( struct V_90 * V_90 , T_4 V_91 , struct V_170 * V_171 , int V_172 ,
unsigned long * V_165 )
{
T_9 V_173 ;
int V_27 ;
V_173 = F_93 () ;
F_94 ( V_174 ) ;
V_27 = F_95 ( V_90 , (struct V_175 V_176 * ) V_171 , V_172 , & V_91 ) ;
F_94 ( V_173 ) ;
return F_88 ( V_90 , V_165 , V_27 ) ;
}
static T_1
F_96 ( struct V_1 * V_2 , struct V_90 * V_90 ,
T_4 V_91 , struct V_170 * V_171 , int V_172 , unsigned long * V_165 )
{
if ( V_90 -> V_177 -> V_178 && F_97 ( V_179 , & V_2 -> V_180 ) )
return F_90 ( V_2 , V_90 , V_91 , V_165 ) ;
else
return F_92 ( V_90 , V_91 , V_171 , V_172 , V_165 ) ;
}
static int F_98 ( struct V_90 * V_90 )
{
struct V_36 * V_36 = F_63 ( V_90 ) ;
static T_7 V_181 ;
static T_6 V_182 ;
int V_11 = 0 ;
if ( F_99 ( & V_36 -> V_183 ) > 1
|| ( V_181 == V_36 -> V_184 && V_182 == V_36 -> V_39 -> V_185 ) ) {
F_23 ( L_2 , F_100 ( V_186 ) ) ;
F_101 ( 10 ) ;
F_23 ( L_3 , F_100 ( V_186 ) ) ;
}
if ( V_36 -> V_187 & V_188 ) {
F_23 ( L_4 , F_100 ( V_186 ) ) ;
V_11 = F_102 ( V_90 , 0 ) ;
}
V_181 = V_36 -> V_184 ;
V_182 = V_36 -> V_39 -> V_185 ;
return V_11 ;
}
static T_1
F_103 ( struct V_1 * V_2 , struct V_21 * V_22 , struct V_90 * V_90 ,
T_4 V_91 , struct V_170 * V_171 , int V_172 ,
unsigned long * V_189 , int * V_190 )
{
struct V_5 * exp ;
struct V_36 * V_36 ;
T_9 V_173 ;
T_1 V_11 = 0 ;
int V_27 ;
int V_191 = * V_190 ;
int V_192 ;
T_4 V_168 = V_91 ;
T_4 V_193 = V_194 ;
unsigned int V_195 = V_186 -> V_92 ;
if ( F_97 ( V_196 , & V_2 -> V_180 ) )
V_186 -> V_92 |= V_197 ;
V_36 = F_63 ( V_90 ) ;
exp = V_22 -> V_29 ;
V_192 = ( V_2 -> V_198 == 2 ) && F_104 ( exp ) ;
if ( ! F_36 ( exp ) )
V_191 = 0 ;
V_173 = F_93 () ; F_94 ( V_174 ) ;
V_27 = F_105 ( V_90 , (struct V_175 V_176 * ) V_171 , V_172 , & V_168 ) ;
F_94 ( V_173 ) ;
if ( V_27 < 0 )
goto V_30;
* V_189 = V_27 ;
V_146 . V_199 += V_27 ;
F_106 ( V_90 ) ;
if ( V_191 ) {
if ( V_192 ) {
V_27 = F_98 ( V_90 ) ;
} else {
if ( * V_189 )
V_193 = V_91 + * V_189 - 1 ;
V_27 = F_107 ( V_90 , V_91 , V_193 , 0 ) ;
}
}
V_30:
F_23 ( L_5 , V_27 ) ;
if ( V_27 >= 0 )
V_11 = 0 ;
else
V_11 = F_29 ( V_27 ) ;
if ( F_97 ( V_196 , & V_2 -> V_180 ) )
F_108 ( V_186 , V_195 , V_197 ) ;
return V_11 ;
}
T_1 F_109 ( struct V_1 * V_2 , struct V_21 * V_22 ,
struct V_90 * * V_90 , struct V_127 * * V_130 )
{
struct V_36 * V_36 ;
T_1 V_11 ;
V_11 = F_70 ( V_2 , V_22 , V_77 , V_121 , V_90 ) ;
if ( V_11 )
return V_11 ;
V_36 = F_63 ( * V_90 ) ;
* V_130 = F_79 ( V_36 -> V_39 -> V_185 , V_36 -> V_184 ) ;
if ( * V_130 && ( * V_130 ) -> V_148 )
( * V_90 ) -> V_200 = ( * V_130 ) -> V_201 ;
return V_108 ;
}
void F_110 ( struct V_90 * V_90 , struct V_127 * V_130 )
{
if ( V_130 ) {
struct V_135 * V_136 = & V_138 [ V_130 -> V_149 ] ;
F_81 ( & V_136 -> V_139 ) ;
V_130 -> V_201 = V_90 -> V_200 ;
V_130 -> V_148 = 1 ;
V_130 -> V_145 -- ;
F_82 ( & V_136 -> V_139 ) ;
}
F_77 ( V_90 ) ;
}
T_1 F_111 ( struct V_1 * V_2 , struct V_21 * V_22 ,
T_4 V_91 , struct V_170 * V_171 , int V_172 , unsigned long * V_165 )
{
struct V_90 * V_90 ;
struct V_127 * V_130 ;
T_1 V_11 ;
V_11 = F_109 ( V_2 , V_22 , & V_90 , & V_130 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_96 ( V_2 , V_90 , V_91 , V_171 , V_172 , V_165 ) ;
F_110 ( V_90 , V_130 ) ;
return V_11 ;
}
T_1
F_112 ( struct V_1 * V_2 , struct V_21 * V_22 , struct V_90 * V_90 ,
T_4 V_91 , struct V_170 * V_171 , int V_172 , unsigned long * V_189 ,
int * V_190 )
{
T_1 V_11 = 0 ;
if ( V_90 ) {
V_11 = F_45 ( V_2 , V_22 -> V_29 , V_22 -> V_28 ,
V_76 | V_63 ) ;
if ( V_11 )
goto V_12;
V_11 = F_103 ( V_2 , V_22 , V_90 , V_91 , V_171 , V_172 , V_189 ,
V_190 ) ;
} else {
V_11 = F_70 ( V_2 , V_22 , V_77 , V_76 , & V_90 ) ;
if ( V_11 )
goto V_12;
if ( V_189 )
V_11 = F_103 ( V_2 , V_22 , V_90 , V_91 , V_171 , V_172 ,
V_189 , V_190 ) ;
F_77 ( V_90 ) ;
}
V_12:
return V_11 ;
}
T_1
F_113 ( struct V_1 * V_2 , struct V_21 * V_22 ,
T_4 V_91 , unsigned long V_165 )
{
struct V_90 * V_90 ;
T_4 V_193 = V_194 ;
T_1 V_11 = V_93 ;
if ( V_91 < 0 )
goto V_12;
if ( V_165 != 0 ) {
V_193 = V_91 + ( T_4 ) V_165 - 1 ;
if ( V_193 < V_91 )
goto V_12;
}
V_11 = F_70 ( V_2 , V_22 , V_77 ,
V_76 | V_113 , & V_90 ) ;
if ( V_11 )
goto V_12;
if ( F_36 ( V_22 -> V_29 ) ) {
int V_106 = F_107 ( V_90 , V_91 , V_193 , 0 ) ;
if ( V_106 != - V_202 )
V_11 = F_29 ( V_106 ) ;
else
V_11 = V_89 ;
}
F_77 ( V_90 ) ;
V_12:
return V_11 ;
}
static T_1
F_114 ( struct V_1 * V_2 , struct V_21 * V_203 ,
struct V_41 * V_42 )
{
V_42 -> V_43 &= ~ V_48 ;
if ( ! F_115 ( F_116 () , V_204 ) )
V_42 -> V_43 &= ~ ( V_52 | V_53 ) ;
if ( V_42 -> V_43 )
return F_49 ( V_2 , V_203 , V_42 , 0 , ( T_2 ) 0 ) ;
return F_29 ( F_35 ( V_203 ) ) ;
}
static void
F_117 ( struct V_41 * V_42 )
{
if ( ( V_42 -> V_43 & V_75 ) && ( V_42 -> V_60 == 0 ) )
V_42 -> V_43 &= ~ V_75 ;
}
T_1
F_118 ( struct V_1 * V_2 , struct V_21 * V_22 ,
char * V_205 , int V_206 , struct V_41 * V_42 ,
int type , T_6 V_207 , struct V_21 * V_203 )
{
struct V_3 * V_3 , * V_208 = NULL ;
struct V_36 * V_209 ;
T_1 V_11 ;
T_1 V_106 ;
int V_27 ;
V_11 = V_111 ;
if ( ! V_206 )
goto V_12;
V_11 = V_210 ;
if ( F_26 ( V_205 , V_206 ) )
goto V_12;
V_11 = F_31 ( V_2 , V_22 , V_33 , V_211 ) ;
if ( V_11 )
goto V_12;
V_3 = V_22 -> V_28 ;
V_209 = F_21 ( V_3 ) ;
V_11 = V_212 ;
if ( ! V_209 -> V_213 -> V_214 )
goto V_12;
if ( ! V_203 -> V_28 ) {
V_27 = F_50 ( V_22 ) ;
if ( V_27 )
goto V_30;
F_27 ( V_22 , V_31 ) ;
V_208 = F_28 ( V_205 , V_3 , V_206 ) ;
V_27 = F_7 ( V_208 ) ;
if ( F_6 ( V_208 ) )
goto V_30;
V_11 = F_33 ( V_203 , V_22 -> V_29 , V_208 , V_22 ) ;
if ( V_11 )
goto V_12;
} else {
V_208 = F_3 ( V_203 -> V_28 ) ;
if ( ! V_22 -> V_215 ) {
F_119 ( V_216
L_6 ,
V_3 ) ;
V_11 = V_217 ;
goto V_12;
}
}
V_11 = V_210 ;
if ( F_120 ( V_208 ) ) {
F_23 ( L_7 ,
V_3 , V_208 ) ;
goto V_12;
}
if ( ! ( V_42 -> V_43 & V_48 ) )
V_42 -> V_49 = 0 ;
V_42 -> V_49 = ( V_42 -> V_49 & V_50 ) | type ;
V_11 = V_93 ;
if ( ! F_62 ( type ) && ! F_43 ( type ) && ! F_121 ( type ) ) {
F_119 ( V_218 L_8 ,
type ) ;
goto V_12;
}
V_11 = 0 ;
V_27 = 0 ;
switch ( type ) {
case V_77 :
V_27 = F_122 ( V_209 , V_208 , V_42 -> V_49 , true ) ;
if ( ! V_27 )
F_117 ( V_42 ) ;
break;
case V_33 :
V_27 = F_123 ( V_209 , V_208 , V_42 -> V_49 ) ;
break;
case V_219 :
case V_220 :
case V_221 :
case V_222 :
V_27 = F_124 ( V_209 , V_208 , V_42 -> V_49 , V_207 ) ;
break;
}
if ( V_27 < 0 )
goto V_30;
V_11 = F_114 ( V_2 , V_203 , V_42 ) ;
V_106 = F_29 ( F_35 ( V_22 ) ) ;
if ( V_106 )
V_11 = V_106 ;
if ( ! V_11 )
V_11 = F_125 ( V_203 ) ;
V_12:
if ( V_208 && ! F_6 ( V_208 ) )
F_15 ( V_208 ) ;
return V_11 ;
V_30:
V_11 = F_29 ( V_27 ) ;
goto V_12;
}
static inline int F_126 ( int V_223 )
{
return V_223 == V_224
|| V_223 == V_225 ;
}
T_1
F_127 ( struct V_1 * V_2 , struct V_21 * V_22 ,
char * V_205 , int V_206 , struct V_41 * V_42 ,
struct V_21 * V_203 , int V_223 , T_5 * V_226 ,
bool * V_227 , bool * V_228 )
{
struct V_3 * V_3 , * V_208 = NULL ;
struct V_36 * V_209 ;
T_1 V_11 ;
int V_27 ;
T_10 V_229 = 0 , V_230 = 0 ;
V_11 = V_111 ;
if ( ! V_206 )
goto V_12;
V_11 = V_210 ;
if ( F_26 ( V_205 , V_206 ) )
goto V_12;
if ( ! ( V_42 -> V_43 & V_48 ) )
V_42 -> V_49 = 0 ;
V_11 = F_31 ( V_2 , V_22 , V_33 , V_34 ) ;
if ( V_11 )
goto V_12;
V_3 = V_22 -> V_28 ;
V_209 = F_21 ( V_3 ) ;
V_11 = V_212 ;
if ( ! V_209 -> V_213 -> V_214 )
goto V_12;
V_27 = F_50 ( V_22 ) ;
if ( V_27 )
goto V_30;
F_27 ( V_22 , V_31 ) ;
V_208 = F_28 ( V_205 , V_3 , V_206 ) ;
V_27 = F_7 ( V_208 ) ;
if ( F_6 ( V_208 ) )
goto V_30;
if ( F_34 ( V_208 ) ) {
V_11 = F_31 ( V_2 , V_22 , V_33 , V_211 ) ;
if ( V_11 )
goto V_12;
}
V_11 = F_33 ( V_203 , V_22 -> V_29 , V_208 , V_22 ) ;
if ( V_11 )
goto V_12;
if ( F_126 ( V_223 ) ) {
V_229 = V_226 [ 0 ] & 0x7fffffff ;
V_230 = V_226 [ 1 ] & 0x7fffffff ;
}
if ( F_120 ( V_208 ) ) {
V_11 = 0 ;
switch ( V_223 ) {
case V_231 :
if ( ! F_66 ( V_208 ) )
goto V_12;
else if ( V_227 ) {
* V_227 = ( V_42 -> V_43 & V_75 ) && ! V_42 -> V_60 ;
}
else {
V_42 -> V_43 &= V_75 ;
goto V_232;
}
break;
case V_224 :
if ( F_21 ( V_208 ) -> V_233 . V_45 == V_229
&& F_21 ( V_208 ) -> V_234 . V_45 == V_230
&& F_21 ( V_208 ) -> V_61 == 0 ) {
if ( V_228 )
* V_228 = 1 ;
break;
}
case V_225 :
if ( F_21 ( V_208 ) -> V_233 . V_45 == V_229
&& F_21 ( V_208 ) -> V_234 . V_45 == V_230
&& F_21 ( V_208 ) -> V_61 == 0 ) {
if ( V_228 )
* V_228 = 1 ;
goto V_232;
}
case V_235 :
V_11 = V_210 ;
}
F_128 ( V_22 ) ;
goto V_12;
}
V_27 = F_122 ( V_209 , V_208 , V_42 -> V_49 , true ) ;
if ( V_27 < 0 ) {
F_128 ( V_22 ) ;
goto V_30;
}
if ( V_228 )
* V_228 = 1 ;
F_117 ( V_42 ) ;
if ( F_126 ( V_223 ) ) {
V_42 -> V_43 = V_74 | V_73
| V_236 | V_237 ;
V_42 -> V_44 . V_45 = V_229 ;
V_42 -> V_46 . V_45 = V_230 ;
V_42 -> V_44 . V_238 = 0 ;
V_42 -> V_46 . V_238 = 0 ;
}
V_232:
V_11 = F_114 ( V_2 , V_203 , V_42 ) ;
if ( ! V_11 )
V_11 = F_29 ( F_35 ( V_22 ) ) ;
if ( ! V_11 )
V_11 = F_125 ( V_203 ) ;
V_12:
F_55 ( V_22 ) ;
if ( V_208 && ! F_6 ( V_208 ) )
F_15 ( V_208 ) ;
F_128 ( V_22 ) ;
return V_11 ;
V_30:
V_11 = F_29 ( V_27 ) ;
goto V_12;
}
T_1
F_129 ( struct V_1 * V_2 , struct V_21 * V_22 , char * V_154 , int * V_239 )
{
struct V_36 * V_36 ;
T_9 V_173 ;
T_1 V_11 ;
int V_27 ;
struct V_8 V_8 ;
V_11 = F_31 ( V_2 , V_22 , V_240 , V_102 ) ;
if ( V_11 )
goto V_12;
V_8 . V_9 = V_22 -> V_29 -> V_10 . V_9 ;
V_8 . V_3 = V_22 -> V_28 ;
V_36 = F_21 ( V_8 . V_3 ) ;
V_11 = V_93 ;
if ( ! V_36 -> V_213 -> V_241 )
goto V_12;
F_130 ( & V_8 ) ;
V_173 = F_93 () ; F_94 ( V_174 ) ;
V_27 = V_36 -> V_213 -> V_241 ( V_8 . V_3 , ( char V_176 * ) V_154 , * V_239 ) ;
F_94 ( V_173 ) ;
if ( V_27 < 0 )
goto V_30;
* V_239 = V_27 ;
V_11 = 0 ;
V_12:
return V_11 ;
V_30:
V_11 = F_29 ( V_27 ) ;
goto V_12;
}
T_1
F_131 ( struct V_1 * V_2 , struct V_21 * V_22 ,
char * V_205 , int V_206 ,
char * V_8 ,
struct V_21 * V_203 )
{
struct V_3 * V_3 , * V_242 ;
T_1 V_11 , V_243 ;
int V_27 ;
V_11 = V_35 ;
if ( ! V_206 || V_8 [ 0 ] == '\0' )
goto V_12;
V_11 = V_210 ;
if ( F_26 ( V_205 , V_206 ) )
goto V_12;
V_11 = F_31 ( V_2 , V_22 , V_33 , V_211 ) ;
if ( V_11 )
goto V_12;
V_27 = F_50 ( V_22 ) ;
if ( V_27 )
goto V_30;
F_53 ( V_22 ) ;
V_3 = V_22 -> V_28 ;
V_242 = F_28 ( V_205 , V_3 , V_206 ) ;
V_27 = F_7 ( V_242 ) ;
if ( F_6 ( V_242 ) )
goto V_30;
V_27 = F_132 ( F_21 ( V_3 ) , V_242 , V_8 ) ;
V_11 = F_29 ( V_27 ) ;
if ( ! V_11 )
V_11 = F_29 ( F_35 ( V_22 ) ) ;
F_55 ( V_22 ) ;
F_128 ( V_22 ) ;
V_243 = F_33 ( V_203 , V_22 -> V_29 , V_242 , V_22 ) ;
F_15 ( V_242 ) ;
if ( V_11 == 0 ) V_11 = V_243 ;
V_12:
return V_11 ;
V_30:
V_11 = F_29 ( V_27 ) ;
goto V_12;
}
T_1
F_133 ( struct V_1 * V_2 , struct V_21 * V_244 ,
char * V_23 , int V_24 , struct V_21 * V_245 )
{
struct V_3 * V_246 , * V_242 , * V_247 ;
struct V_36 * V_209 ;
T_1 V_11 ;
int V_27 ;
V_11 = F_31 ( V_2 , V_244 , V_33 , V_211 ) ;
if ( V_11 )
goto V_12;
V_11 = F_31 ( V_2 , V_245 , 0 , V_102 ) ;
if ( V_11 )
goto V_12;
V_11 = V_248 ;
if ( F_67 ( V_245 -> V_28 ) )
goto V_12;
V_11 = V_111 ;
if ( ! V_24 )
goto V_12;
V_11 = V_210 ;
if ( F_26 ( V_23 , V_24 ) )
goto V_12;
V_27 = F_50 ( V_245 ) ;
if ( V_27 ) {
V_11 = F_29 ( V_27 ) ;
goto V_12;
}
F_27 ( V_244 , V_31 ) ;
V_246 = V_244 -> V_28 ;
V_209 = F_21 ( V_246 ) ;
V_242 = F_28 ( V_23 , V_246 , V_24 ) ;
V_27 = F_7 ( V_242 ) ;
if ( F_6 ( V_242 ) )
goto V_30;
V_247 = V_245 -> V_28 ;
V_11 = V_35 ;
if ( F_34 ( V_247 ) )
goto V_249;
V_27 = F_134 ( V_247 , V_209 , V_242 , NULL ) ;
if ( ! V_27 ) {
V_11 = F_29 ( F_35 ( V_244 ) ) ;
if ( ! V_11 )
V_11 = F_29 ( F_35 ( V_245 ) ) ;
} else {
if ( V_27 == - V_250 && V_2 -> V_198 == 2 )
V_11 = V_110 ;
else
V_11 = F_29 ( V_27 ) ;
}
V_249:
F_15 ( V_242 ) ;
V_251:
F_55 ( V_244 ) ;
F_128 ( V_245 ) ;
V_12:
return V_11 ;
V_30:
V_11 = F_29 ( V_27 ) ;
goto V_251;
}
T_1
F_135 ( struct V_1 * V_2 , struct V_21 * V_244 , char * V_205 , int V_206 ,
struct V_21 * V_245 , char * V_252 , int V_253 )
{
struct V_3 * V_254 , * V_255 , * V_256 , * V_257 , * V_258 ;
struct V_36 * V_259 , * V_260 ;
T_1 V_11 ;
int V_27 ;
V_11 = F_31 ( V_2 , V_244 , V_33 , V_261 ) ;
if ( V_11 )
goto V_12;
V_11 = F_31 ( V_2 , V_245 , V_33 , V_211 ) ;
if ( V_11 )
goto V_12;
V_254 = V_244 -> V_28 ;
V_259 = F_21 ( V_254 ) ;
V_255 = V_245 -> V_28 ;
V_260 = F_21 ( V_255 ) ;
V_11 = V_111 ;
if ( ! V_206 || F_26 ( V_205 , V_206 ) || ! V_253 || F_26 ( V_252 , V_253 ) )
goto V_12;
V_27 = F_50 ( V_244 ) ;
if ( V_27 ) {
V_11 = F_29 ( V_27 ) ;
goto V_12;
}
V_258 = F_136 ( V_255 , V_254 ) ;
V_244 -> V_215 = V_245 -> V_215 = 1 ;
F_137 ( V_244 ) ;
F_137 ( V_245 ) ;
V_256 = F_28 ( V_205 , V_254 , V_206 ) ;
V_27 = F_7 ( V_256 ) ;
if ( F_6 ( V_256 ) )
goto V_30;
V_27 = - V_13 ;
if ( F_34 ( V_256 ) )
goto V_262;
V_27 = - V_202 ;
if ( V_256 == V_258 )
goto V_262;
V_257 = F_28 ( V_252 , V_255 , V_253 ) ;
V_27 = F_7 ( V_257 ) ;
if ( F_6 ( V_257 ) )
goto V_262;
V_27 = - V_263 ;
if ( V_257 == V_258 )
goto V_264;
V_27 = - V_250 ;
if ( V_244 -> V_29 -> V_10 . V_9 != V_245 -> V_29 -> V_10 . V_9 )
goto V_264;
if ( V_244 -> V_29 -> V_10 . V_3 != V_245 -> V_29 -> V_10 . V_3 )
goto V_264;
V_27 = F_138 ( V_259 , V_256 , V_260 , V_257 , NULL , 0 ) ;
if ( ! V_27 ) {
V_27 = F_35 ( V_245 ) ;
if ( ! V_27 )
V_27 = F_35 ( V_244 ) ;
}
V_264:
F_15 ( V_257 ) ;
V_262:
F_15 ( V_256 ) ;
V_30:
V_11 = F_29 ( V_27 ) ;
F_139 ( V_244 ) ;
F_139 ( V_245 ) ;
F_140 ( V_255 , V_254 ) ;
V_244 -> V_215 = V_245 -> V_215 = 0 ;
F_128 ( V_244 ) ;
V_12:
return V_11 ;
}
T_1
F_141 ( struct V_1 * V_2 , struct V_21 * V_22 , int type ,
char * V_205 , int V_206 )
{
struct V_3 * V_3 , * V_265 ;
struct V_36 * V_209 ;
T_1 V_11 ;
int V_27 ;
V_11 = V_110 ;
if ( ! V_206 || F_26 ( V_205 , V_206 ) )
goto V_12;
V_11 = F_31 ( V_2 , V_22 , V_33 , V_261 ) ;
if ( V_11 )
goto V_12;
V_27 = F_50 ( V_22 ) ;
if ( V_27 )
goto V_30;
F_27 ( V_22 , V_31 ) ;
V_3 = V_22 -> V_28 ;
V_209 = F_21 ( V_3 ) ;
V_265 = F_28 ( V_205 , V_3 , V_206 ) ;
V_27 = F_7 ( V_265 ) ;
if ( F_6 ( V_265 ) )
goto V_30;
if ( F_34 ( V_265 ) ) {
F_15 ( V_265 ) ;
V_11 = V_35 ;
goto V_12;
}
if ( ! type )
type = F_21 ( V_265 ) -> V_51 & V_266 ;
if ( type != V_33 )
V_27 = F_142 ( V_209 , V_265 , NULL ) ;
else
V_27 = F_143 ( V_209 , V_265 ) ;
if ( ! V_27 )
V_27 = F_35 ( V_22 ) ;
F_15 ( V_265 ) ;
V_30:
V_11 = F_29 ( V_27 ) ;
V_12:
return V_11 ;
}
static int F_144 ( struct V_267 * V_268 , const char * V_23 ,
int V_269 , T_4 V_91 , T_11 V_129 ,
unsigned int V_270 )
{
struct V_271 * V_154 =
F_145 ( V_268 , struct V_271 , V_268 ) ;
struct V_272 * V_273 = ( void * ) ( V_154 -> V_274 + V_154 -> V_275 ) ;
unsigned int V_276 ;
V_276 = F_146 ( sizeof( struct V_272 ) + V_269 , sizeof( T_11 ) ) ;
if ( V_154 -> V_275 + V_276 > V_277 ) {
V_154 -> V_278 = 1 ;
return - V_202 ;
}
V_273 -> V_269 = V_269 ;
V_273 -> V_91 = V_91 ;
V_273 -> V_129 = V_129 ;
V_273 -> V_270 = V_270 ;
memcpy ( V_273 -> V_23 , V_23 , V_269 ) ;
V_154 -> V_275 += V_276 ;
return 0 ;
}
static T_1 F_147 ( struct V_90 * V_90 , T_12 V_279 ,
struct V_280 * V_281 , T_4 * V_282 )
{
struct V_272 * V_273 ;
int V_27 ;
int V_161 ;
T_4 V_91 ;
struct V_271 V_154 = {
. V_268 . V_283 = F_144 ,
. V_274 = ( void * ) F_148 (GFP_KERNEL)
} ;
if ( ! V_154 . V_274 )
return F_29 ( - V_284 ) ;
V_91 = * V_282 ;
while ( 1 ) {
struct V_36 * V_285 = F_63 ( V_90 ) ;
unsigned int V_276 ;
V_281 -> V_11 = V_286 ;
V_154 . V_275 = 0 ;
V_154 . V_278 = 0 ;
V_27 = F_149 ( V_90 , & V_154 . V_268 ) ;
if ( V_154 . V_278 )
V_27 = 0 ;
if ( V_27 < 0 )
break;
V_161 = V_154 . V_275 ;
if ( ! V_161 )
break;
V_27 = F_150 ( & V_285 -> V_87 ) ;
if ( V_27 )
break;
V_273 = (struct V_272 * ) V_154 . V_274 ;
while ( V_161 > 0 ) {
V_91 = V_273 -> V_91 ;
if ( V_279 ( V_281 , V_273 -> V_23 , V_273 -> V_269 , V_273 -> V_91 ,
V_273 -> V_129 , V_273 -> V_270 ) )
break;
if ( V_281 -> V_11 != V_108 )
break;
V_276 = F_146 ( sizeof( * V_273 ) + V_273 -> V_269 ,
sizeof( T_11 ) ) ;
V_161 -= V_276 ;
V_273 = (struct V_272 * ) ( ( char * ) V_273 + V_276 ) ;
}
F_60 ( & V_285 -> V_87 ) ;
if ( V_161 > 0 )
break;
V_91 = F_151 ( V_90 , 0 , V_287 ) ;
}
F_152 ( ( unsigned long ) ( V_154 . V_274 ) ) ;
if ( V_27 )
return F_29 ( V_27 ) ;
* V_282 = V_91 ;
return V_281 -> V_11 ;
}
T_1
F_153 ( struct V_1 * V_2 , struct V_21 * V_22 , T_4 * V_282 ,
struct V_280 * V_281 , T_12 V_279 )
{
T_1 V_11 ;
struct V_90 * V_90 ;
T_4 V_91 = * V_282 ;
int V_117 = V_121 ;
if ( V_2 -> V_198 > 2 )
V_117 |= V_123 ;
V_11 = F_70 ( V_2 , V_22 , V_33 , V_117 , & V_90 ) ;
if ( V_11 )
goto V_12;
V_91 = F_151 ( V_90 , V_91 , V_288 ) ;
if ( V_91 < 0 ) {
V_11 = F_29 ( ( int ) V_91 ) ;
goto V_289;
}
V_11 = F_147 ( V_90 , V_279 , V_281 , V_282 ) ;
if ( V_11 == V_286 || V_11 == V_290 )
V_11 = V_108 ;
V_289:
F_77 ( V_90 ) ;
V_12:
return V_11 ;
}
T_1
F_154 ( struct V_1 * V_2 , struct V_21 * V_22 , struct V_291 * V_292 , int V_94 )
{
T_1 V_11 ;
V_11 = F_31 ( V_2 , V_22 , 0 , V_102 | V_94 ) ;
if ( ! V_11 ) {
struct V_8 V_8 = {
. V_9 = V_22 -> V_29 -> V_10 . V_9 ,
. V_3 = V_22 -> V_28 ,
} ;
if ( F_155 ( & V_8 , V_292 ) )
V_11 = V_217 ;
}
return V_11 ;
}
static int F_156 ( struct V_1 * V_2 , struct V_5 * exp )
{
return F_157 ( V_2 , exp ) & V_293 ;
}
T_1
F_45 ( struct V_1 * V_2 , struct V_5 * exp ,
struct V_3 * V_3 , int V_294 )
{
struct V_36 * V_36 = F_21 ( V_3 ) ;
int V_11 ;
if ( ( V_294 & V_295 ) == V_102 )
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
if ( ! ( V_294 & V_296 ) )
if ( V_294 & ( V_76 | V_69 | V_62 ) ) {
if ( F_156 ( V_2 , exp ) ||
F_158 ( exp -> V_10 . V_9 ) )
return V_109 ;
if ( F_159 ( V_36 ) )
return V_111 ;
}
if ( ( V_294 & V_62 ) && F_72 ( V_36 ) )
return V_111 ;
if ( V_294 & V_297 ) {
if ( exp -> V_14 & V_298 )
return 0 ;
else
V_294 = V_121 | V_63 ;
}
if ( ( V_294 & V_63 ) &&
F_115 ( V_36 -> V_299 , F_116 () ) )
return 0 ;
V_11 = F_160 ( V_36 , V_294 & ( V_300 | V_301 | V_302 ) ) ;
if ( V_11 == - V_303 && F_62 ( V_36 -> V_51 ) &&
( V_294 == ( V_121 | V_63 ) ||
V_294 == ( V_121 | V_304 ) ) )
V_11 = F_160 ( V_36 , V_302 ) ;
return V_11 ? F_29 ( V_11 ) : 0 ;
}
void
F_161 ( void )
{
struct V_127 * V_305 , * V_306 ;
unsigned int V_307 ;
F_23 ( L_9 ) ;
for ( V_307 = 0 ; V_307 < V_308 ; V_307 ++ ) {
V_305 = V_138 [ V_307 ] . V_140 ;
while( V_305 ) {
V_306 = V_305 ;
V_305 = V_305 -> V_141 ;
F_162 ( V_306 ) ;
}
V_138 [ V_307 ] . V_140 = NULL ;
}
}
int
F_163 ( int V_309 )
{
int V_307 ;
int V_310 = 0 ;
int V_311 ;
struct V_127 * * V_305 = NULL ;
if ( V_138 [ 0 ] . V_140 )
return 0 ;
V_311 = F_164 ( V_309 , V_308 ) ;
V_311 = F_165 ( 2 , V_311 ) ;
V_309 = V_311 * V_308 ;
F_23 ( L_10 , V_309 ) ;
for ( V_307 = 0 ; V_307 < V_308 ; V_307 ++ ) {
F_166 ( & V_138 [ V_307 ] . V_139 ) ;
V_305 = & V_138 [ V_307 ] . V_140 ;
for ( V_310 = 0 ; V_310 < V_311 ; V_310 ++ ) {
* V_305 = F_167 ( sizeof( struct V_127 ) , V_312 ) ;
if ( ! * V_305 )
goto V_313;
V_305 = & ( * V_305 ) -> V_141 ;
}
* V_305 = NULL ;
}
V_146 . V_147 = V_309 ;
return 0 ;
V_313:
F_23 ( L_11 ) ;
F_161 () ;
return - V_284 ;
}

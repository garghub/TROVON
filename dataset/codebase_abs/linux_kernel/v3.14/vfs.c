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
int V_72 = 0 ;
if ( V_43 -> V_44 & ( V_73 | V_74 | V_75 ) )
V_69 |= V_76 | V_64 ;
if ( V_43 -> V_44 & V_75 )
V_71 = V_77 ;
V_11 = F_30 ( V_2 , V_23 , V_71 , V_69 ) ;
if ( V_11 )
goto V_12;
V_3 = V_23 -> V_29 ;
V_37 = V_3 -> V_21 ;
if ( F_48 ( V_37 -> V_52 ) )
V_43 -> V_44 &= ~ V_49 ;
if ( ! V_43 -> V_44 )
goto V_12;
F_36 ( V_37 , V_43 ) ;
if ( V_43 -> V_44 & V_75 ) {
V_11 = F_42 ( V_2 , V_23 , V_43 ) ;
if ( V_11 )
goto V_12;
V_72 = 1 ;
}
V_43 -> V_44 |= V_78 ;
if ( V_67 && V_68 != V_37 -> V_79 . V_46 ) {
V_11 = V_80 ;
goto V_66;
}
F_49 ( V_23 ) ;
V_28 = F_50 ( V_3 , V_43 , NULL ) ;
F_51 ( V_23 ) ;
V_11 = F_28 ( V_28 ) ;
V_66:
if ( V_72 )
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
if ( V_37 -> V_52 & V_81 )
return 0 ;
if ( ! ( V_37 -> V_52 & V_82 ) )
return 0 ;
if ( F_52 ( V_3 , V_83 , NULL , 0 ) <= 0 )
return 0 ;
return 1 ;
}
T_1 F_53 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_84 * V_85 )
{
T_1 error ;
int V_86 ;
struct V_3 * V_3 ;
error = F_30 ( V_2 , V_23 , 0 , V_70 ) ;
if ( error )
return error ;
V_3 = V_23 -> V_29 ;
F_54 ( & V_3 -> V_21 -> V_87 ) ;
V_86 = F_55 ( V_3 , V_85 -> V_88 , V_85 -> V_25 ) ;
F_56 ( & V_3 -> V_21 -> V_87 ) ;
return F_28 ( V_86 ) ;
}
T_1 F_53 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_84 * V_85 )
{
return V_89 ;
}
T_1
F_57 ( struct V_1 * V_2 , struct V_22 * V_23 , T_4 * V_90 , T_4 * V_91 )
{
struct V_92 * V_93 ;
struct V_5 * V_94 ;
struct V_3 * V_3 ;
T_4 V_95 , V_96 = 0 , V_97 = 0 ;
T_1 error ;
error = F_30 ( V_2 , V_23 , 0 , V_98 ) ;
if ( error )
goto V_12;
V_94 = V_23 -> V_30 ;
V_3 = V_23 -> V_29 ;
if ( F_58 ( V_3 -> V_21 -> V_52 ) )
V_93 = V_99 ;
else if ( F_41 ( V_3 -> V_21 -> V_52 ) )
V_93 = V_100 ;
else
V_93 = V_101 ;
V_95 = * V_90 ;
for (; V_93 -> V_90 ; V_93 ++ ) {
if ( V_93 -> V_90 & V_95 ) {
T_1 V_102 ;
V_97 |= V_93 -> V_90 ;
V_102 = F_43 ( V_2 , V_94 , V_3 , V_93 -> V_103 ) ;
switch ( V_102 ) {
case V_104 :
V_96 |= V_93 -> V_90 ;
break;
case V_105 :
case V_106 :
case V_107 :
break;
default:
error = V_102 ;
goto V_12;
}
}
}
* V_90 = V_96 ;
if ( V_91 )
* V_91 = V_97 ;
V_12:
return error ;
}
static int F_59 ( struct V_37 * V_37 , int V_90 )
{
unsigned int V_108 ;
if ( V_90 & V_109 )
return 0 ;
V_108 = ( V_90 & V_76 ) ? V_110 : V_111 ;
return F_60 ( V_37 , V_108 | V_112 ) ;
}
T_1
F_61 ( struct V_1 * V_2 , struct V_22 * V_23 , T_3 type ,
int V_113 , struct V_114 * * V_115 )
{
struct V_8 V_8 ;
struct V_37 * V_37 ;
int V_116 = V_111 | V_117 ;
T_1 V_11 ;
int V_28 = 0 ;
F_62 () ;
if ( type == V_77 )
V_113 |= V_64 ;
V_11 = F_30 ( V_2 , V_23 , type , V_113 ) ;
if ( V_11 )
goto V_12;
V_8 . V_9 = V_23 -> V_30 -> V_10 . V_9 ;
V_8 . V_3 = V_23 -> V_29 ;
V_37 = V_8 . V_3 -> V_21 ;
V_11 = V_107 ;
if ( F_63 ( V_37 ) && ( V_113 & V_76 ) )
goto V_12;
if ( F_58 ( ( V_37 ) -> V_52 ) && F_64 ( V_37 ) )
goto V_12;
if ( ! V_37 -> V_118 )
goto V_12;
V_28 = F_59 ( V_37 , V_113 ) ;
if ( V_28 )
goto V_31;
if ( V_113 & V_76 ) {
if ( V_113 & V_119 )
V_116 = V_120 | V_117 ;
else
V_116 = V_110 | V_117 ;
}
* V_115 = F_65 ( & V_8 , V_116 , F_66 () ) ;
if ( F_6 ( * V_115 ) ) {
V_28 = F_7 ( * V_115 ) ;
* V_115 = NULL ;
} else {
V_28 = F_67 ( * V_115 , V_113 ) ;
if ( V_113 & V_121 )
( * V_115 ) -> V_122 |= V_123 ;
else
( * V_115 ) -> V_122 |= V_124 ;
}
V_31:
V_11 = F_28 ( V_28 ) ;
V_12:
F_62 () ;
return V_11 ;
}
void
F_68 ( struct V_114 * V_115 )
{
F_69 ( V_115 ) ;
}
static inline struct V_125 *
F_70 ( T_5 V_126 , T_6 V_127 )
{
struct V_125 * V_128 , * * V_129 , * * V_130 = NULL ;
int V_131 = 0 ;
unsigned int V_132 ;
struct V_133 * V_134 ;
V_132 = F_71 ( V_126 , V_127 , 0xfeedbeef ) & V_135 ;
V_134 = & V_136 [ V_132 ] ;
F_72 ( & V_134 -> V_137 ) ;
for ( V_129 = & V_134 -> V_138 ; ( V_128 = * V_129 ) ; V_129 = & V_128 -> V_139 ) {
if ( V_128 -> V_140 == V_127 && V_128 -> V_141 == V_126 )
goto V_142;
V_131 ++ ;
if ( V_128 -> V_143 == 0 )
V_130 = V_129 ;
}
V_131 = V_144 . V_145 ;
if ( ! V_130 ) {
F_73 ( & V_134 -> V_137 ) ;
return NULL ;
}
V_129 = V_130 ;
V_128 = * V_130 ;
V_128 -> V_141 = V_126 ;
V_128 -> V_140 = V_127 ;
V_128 -> V_146 = 0 ;
V_128 -> V_147 = V_132 ;
V_142:
if ( V_129 != & V_134 -> V_138 ) {
* V_129 = V_128 -> V_139 ;
V_128 -> V_139 = V_134 -> V_138 ;
V_134 -> V_138 = V_128 ;
}
V_128 -> V_143 ++ ;
V_144 . V_148 [ V_131 * 10 / V_144 . V_145 ] ++ ;
F_73 ( & V_134 -> V_137 ) ;
return V_128 ;
}
static int
F_74 ( struct V_149 * V_150 , struct V_151 * V_152 ,
struct V_153 * V_154 )
{
struct V_1 * V_2 = V_154 -> V_155 . V_88 ;
struct V_156 * * V_157 = V_2 -> V_158 ;
struct V_156 * V_156 = V_152 -> V_156 ;
T_7 V_159 ;
V_159 = V_154 -> V_25 ;
if ( V_2 -> V_160 . V_161 == 0 ) {
F_75 ( V_156 ) ;
F_76 ( * V_2 -> V_158 ) ;
* ( V_2 -> V_158 ++ ) = V_156 ;
V_2 -> V_160 . V_162 = V_152 -> V_163 ;
V_2 -> V_160 . V_161 = V_159 ;
} else if ( V_156 != V_157 [ - 1 ] ) {
F_75 ( V_156 ) ;
if ( * V_2 -> V_158 )
F_76 ( * V_2 -> V_158 ) ;
* ( V_2 -> V_158 ++ ) = V_156 ;
V_2 -> V_160 . V_161 += V_159 ;
} else
V_2 -> V_160 . V_161 += V_159 ;
return V_159 ;
}
static int F_77 ( struct V_149 * V_150 ,
struct V_153 * V_154 )
{
return F_78 ( V_150 , V_154 , F_74 ) ;
}
static T_1
F_79 ( struct V_1 * V_2 , struct V_22 * V_23 , struct V_114 * V_114 ,
T_8 V_163 , struct V_164 * V_165 , int V_166 , unsigned long * V_167 )
{
T_9 V_168 ;
T_1 V_11 ;
int V_28 ;
V_11 = V_107 ;
if ( V_114 -> V_169 -> V_170 && V_2 -> V_171 ) {
struct V_153 V_154 = {
. V_25 = 0 ,
. V_172 = * V_167 ,
. V_173 = V_163 ,
. V_155 . V_88 = V_2 ,
} ;
V_2 -> V_158 = V_2 -> V_174 + 1 ;
V_28 = F_80 ( V_114 , & V_154 , F_77 ) ;
} else {
V_168 = F_81 () ;
F_82 ( V_175 ) ;
V_28 = F_83 ( V_114 , (struct V_176 V_177 * ) V_165 , V_166 , & V_163 ) ;
F_82 ( V_168 ) ;
}
if ( V_28 >= 0 ) {
V_144 . V_178 += V_28 ;
* V_167 = V_28 ;
V_11 = 0 ;
F_84 ( V_114 ) ;
} else
V_11 = F_28 ( V_28 ) ;
return V_11 ;
}
static void F_85 ( struct V_3 * V_3 )
{
struct V_42 V_179 ;
V_179 . V_44 = V_59 | V_60 | V_55 ;
F_54 ( & V_3 -> V_21 -> V_87 ) ;
F_50 ( V_3 , & V_179 , NULL ) ;
F_56 ( & V_3 -> V_21 -> V_87 ) ;
}
static int F_86 ( struct V_114 * V_114 )
{
struct V_37 * V_37 = F_87 ( V_114 ) ;
static T_6 V_180 ;
static T_5 V_181 ;
int V_11 = 0 ;
if ( F_88 ( & V_37 -> V_182 ) > 1
|| ( V_180 == V_37 -> V_183 && V_181 == V_37 -> V_40 -> V_184 ) ) {
F_22 ( L_2 , F_89 ( V_185 ) ) ;
F_90 ( 10 ) ;
F_22 ( L_3 , F_89 ( V_185 ) ) ;
}
if ( V_37 -> V_186 & V_187 ) {
F_22 ( L_4 , F_89 ( V_185 ) ) ;
V_11 = F_91 ( V_114 , 0 ) ;
}
V_180 = V_37 -> V_183 ;
V_181 = V_37 -> V_40 -> V_184 ;
return V_11 ;
}
static T_1
F_92 ( struct V_1 * V_2 , struct V_22 * V_23 , struct V_114 * V_114 ,
T_8 V_163 , struct V_164 * V_165 , int V_166 ,
unsigned long * V_188 , int * V_189 )
{
struct V_5 * exp ;
struct V_3 * V_3 ;
struct V_37 * V_37 ;
T_9 V_168 ;
T_1 V_11 = 0 ;
int V_28 ;
int V_190 = * V_189 ;
int V_191 ;
T_8 V_173 = V_163 ;
V_3 = V_114 -> V_192 . V_3 ;
V_37 = V_3 -> V_21 ;
exp = V_23 -> V_30 ;
V_191 = ( V_2 -> V_193 == 2 ) && F_93 ( exp ) ;
if ( ! F_34 ( exp ) )
V_190 = 0 ;
V_168 = F_81 () ; F_82 ( V_175 ) ;
V_28 = F_94 ( V_114 , (struct V_176 V_177 * ) V_165 , V_166 , & V_173 ) ;
F_82 ( V_168 ) ;
if ( V_28 < 0 )
goto V_31;
* V_188 = V_28 ;
V_144 . V_194 += V_28 ;
F_95 ( V_114 ) ;
if ( V_37 -> V_52 & ( V_56 | V_58 ) )
F_85 ( V_3 ) ;
if ( V_190 ) {
if ( V_191 )
V_28 = F_86 ( V_114 ) ;
else
V_28 = F_96 ( V_114 , V_163 , V_163 + * V_188 , 0 ) ;
}
V_31:
F_22 ( L_5 , V_28 ) ;
if ( V_28 >= 0 )
V_11 = 0 ;
else
V_11 = F_28 ( V_28 ) ;
return V_11 ;
}
T_1 F_97 ( struct V_1 * V_2 , struct V_22 * V_23 ,
T_8 V_163 , struct V_164 * V_165 , int V_166 , unsigned long * V_167 )
{
struct V_114 * V_114 ;
struct V_37 * V_37 ;
struct V_125 * V_128 ;
T_1 V_11 ;
V_11 = F_61 ( V_2 , V_23 , V_77 , V_119 , & V_114 ) ;
if ( V_11 )
return V_11 ;
V_37 = F_87 ( V_114 ) ;
V_128 = F_70 ( V_37 -> V_40 -> V_184 , V_37 -> V_183 ) ;
if ( V_128 && V_128 -> V_146 )
V_114 -> V_195 = V_128 -> V_196 ;
V_11 = F_79 ( V_2 , V_23 , V_114 , V_163 , V_165 , V_166 , V_167 ) ;
if ( V_128 ) {
struct V_133 * V_134 = & V_136 [ V_128 -> V_147 ] ;
F_72 ( & V_134 -> V_137 ) ;
V_128 -> V_196 = V_114 -> V_195 ;
V_128 -> V_146 = 1 ;
V_128 -> V_143 -- ;
F_73 ( & V_134 -> V_137 ) ;
}
F_68 ( V_114 ) ;
return V_11 ;
}
T_1
F_98 ( struct V_1 * V_2 , struct V_22 * V_23 , struct V_114 * V_114 ,
T_8 V_163 , struct V_164 * V_165 , int V_166 ,
unsigned long * V_167 )
{
T_1 V_11 ;
if ( V_114 ) {
V_11 = F_43 ( V_2 , V_23 -> V_30 , V_23 -> V_29 ,
V_119 | V_64 ) ;
if ( V_11 )
goto V_12;
V_11 = F_79 ( V_2 , V_23 , V_114 , V_163 , V_165 , V_166 , V_167 ) ;
} else
V_11 = F_97 ( V_2 , V_23 , V_163 , V_165 , V_166 , V_167 ) ;
V_12:
return V_11 ;
}
T_1
F_99 ( struct V_1 * V_2 , struct V_22 * V_23 , struct V_114 * V_114 ,
T_8 V_163 , struct V_164 * V_165 , int V_166 , unsigned long * V_188 ,
int * V_189 )
{
T_1 V_11 = 0 ;
if ( V_114 ) {
V_11 = F_43 ( V_2 , V_23 -> V_30 , V_23 -> V_29 ,
V_76 | V_64 ) ;
if ( V_11 )
goto V_12;
V_11 = F_92 ( V_2 , V_23 , V_114 , V_163 , V_165 , V_166 , V_188 ,
V_189 ) ;
} else {
V_11 = F_61 ( V_2 , V_23 , V_77 , V_76 , & V_114 ) ;
if ( V_11 )
goto V_12;
if ( V_188 )
V_11 = F_92 ( V_2 , V_23 , V_114 , V_163 , V_165 , V_166 ,
V_188 , V_189 ) ;
F_68 ( V_114 ) ;
}
V_12:
return V_11 ;
}
T_1
F_100 ( struct V_1 * V_2 , struct V_22 * V_23 ,
T_8 V_163 , unsigned long V_167 )
{
struct V_114 * V_114 ;
T_8 V_197 = V_198 ;
T_1 V_11 = V_199 ;
if ( V_163 < 0 )
goto V_12;
if ( V_167 != 0 ) {
V_197 = V_163 + ( T_8 ) V_167 - 1 ;
if ( V_197 < V_163 )
goto V_12;
}
V_11 = F_61 ( V_2 , V_23 , V_77 ,
V_76 | V_109 , & V_114 ) ;
if ( V_11 )
goto V_12;
if ( F_34 ( V_23 -> V_30 ) ) {
int V_102 = F_96 ( V_114 , V_163 , V_197 , 0 ) ;
if ( V_102 != - V_200 )
V_11 = F_28 ( V_102 ) ;
else
V_11 = V_89 ;
}
F_68 ( V_114 ) ;
V_12:
return V_11 ;
}
static T_1
F_101 ( struct V_1 * V_2 , struct V_22 * V_201 ,
struct V_42 * V_43 )
{
V_43 -> V_44 &= ~ V_49 ;
if ( ! F_102 ( F_103 () , V_202 ) )
V_43 -> V_44 &= ~ ( V_53 | V_54 ) ;
if ( V_43 -> V_44 )
return F_47 ( V_2 , V_201 , V_43 , 0 , ( T_2 ) 0 ) ;
return 0 ;
}
static void
F_104 ( struct V_42 * V_43 )
{
if ( ( V_43 -> V_44 & V_75 ) && ( V_43 -> V_61 == 0 ) )
V_43 -> V_44 &= ~ V_75 ;
}
T_1
F_105 ( struct V_1 * V_2 , struct V_22 * V_23 ,
char * V_203 , int V_204 , struct V_42 * V_43 ,
int type , T_5 V_205 , struct V_22 * V_201 )
{
struct V_3 * V_3 , * V_206 = NULL ;
struct V_37 * V_207 ;
T_1 V_11 ;
T_1 V_102 ;
int V_28 ;
V_11 = V_107 ;
if ( ! V_204 )
goto V_12;
V_11 = V_208 ;
if ( F_25 ( V_203 , V_204 ) )
goto V_12;
V_11 = F_30 ( V_2 , V_23 , V_34 , V_209 ) ;
if ( V_11 )
goto V_12;
V_3 = V_23 -> V_29 ;
V_207 = V_3 -> V_21 ;
V_11 = V_210 ;
if ( ! V_207 -> V_211 -> V_212 )
goto V_12;
if ( ! V_201 -> V_29 ) {
V_28 = F_106 ( V_23 ) ;
if ( V_28 )
goto V_31;
F_26 ( V_23 , V_32 ) ;
V_206 = F_27 ( V_203 , V_3 , V_204 ) ;
V_28 = F_7 ( V_206 ) ;
if ( F_6 ( V_206 ) )
goto V_31;
V_11 = F_32 ( V_201 , V_23 -> V_30 , V_206 , V_23 ) ;
if ( V_11 )
goto V_12;
} else {
V_206 = F_3 ( V_201 -> V_29 ) ;
if ( ! V_23 -> V_213 ) {
F_107 ( V_214
L_6 ,
V_3 ) ;
V_11 = V_215 ;
goto V_12;
}
}
V_11 = V_208 ;
if ( V_206 -> V_21 ) {
F_22 ( L_7 ,
V_3 , V_206 ) ;
goto V_12;
}
if ( ! ( V_43 -> V_44 & V_49 ) )
V_43 -> V_50 = 0 ;
V_43 -> V_50 = ( V_43 -> V_50 & V_51 ) | type ;
V_11 = V_199 ;
if ( ! F_58 ( type ) && ! F_41 ( type ) && ! F_108 ( type ) ) {
F_107 ( V_216 L_8 ,
type ) ;
goto V_12;
}
V_11 = 0 ;
V_28 = 0 ;
switch ( type ) {
case V_77 :
V_28 = F_109 ( V_207 , V_206 , V_43 -> V_50 , true ) ;
if ( ! V_28 )
F_104 ( V_43 ) ;
break;
case V_34 :
V_28 = F_110 ( V_207 , V_206 , V_43 -> V_50 ) ;
break;
case V_217 :
case V_218 :
case V_219 :
case V_220 :
V_28 = F_111 ( V_207 , V_206 , V_43 -> V_50 , V_205 ) ;
break;
}
if ( V_28 < 0 )
goto V_31;
V_11 = F_101 ( V_2 , V_201 , V_43 ) ;
V_102 = F_28 ( F_33 ( V_23 ) ) ;
if ( V_102 )
V_11 = V_102 ;
if ( ! V_11 )
V_11 = F_112 ( V_201 ) ;
V_12:
if ( V_206 && ! F_6 ( V_206 ) )
F_15 ( V_206 ) ;
return V_11 ;
V_31:
V_11 = F_28 ( V_28 ) ;
goto V_12;
}
static inline int F_113 ( int V_221 )
{
return V_221 == V_222
|| V_221 == V_223 ;
}
T_1
F_114 ( struct V_1 * V_2 , struct V_22 * V_23 ,
char * V_203 , int V_204 , struct V_42 * V_43 ,
struct V_22 * V_201 , int V_221 , T_4 * V_224 ,
bool * V_225 , bool * V_226 )
{
struct V_3 * V_3 , * V_206 = NULL ;
struct V_37 * V_207 ;
T_1 V_11 ;
int V_28 ;
T_10 V_227 = 0 , V_228 = 0 ;
V_11 = V_107 ;
if ( ! V_204 )
goto V_12;
V_11 = V_208 ;
if ( F_25 ( V_203 , V_204 ) )
goto V_12;
if ( ! ( V_43 -> V_44 & V_49 ) )
V_43 -> V_50 = 0 ;
V_11 = F_30 ( V_2 , V_23 , V_34 , V_35 ) ;
if ( V_11 )
goto V_12;
V_3 = V_23 -> V_29 ;
V_207 = V_3 -> V_21 ;
V_11 = V_210 ;
if ( ! V_207 -> V_211 -> V_212 )
goto V_12;
V_28 = F_106 ( V_23 ) ;
if ( V_28 )
goto V_31;
F_26 ( V_23 , V_32 ) ;
V_206 = F_27 ( V_203 , V_3 , V_204 ) ;
V_28 = F_7 ( V_206 ) ;
if ( F_6 ( V_206 ) )
goto V_31;
if ( ! V_206 -> V_21 ) {
V_11 = F_30 ( V_2 , V_23 , V_34 , V_209 ) ;
if ( V_11 )
goto V_12;
}
V_11 = F_32 ( V_201 , V_23 -> V_30 , V_206 , V_23 ) ;
if ( V_11 )
goto V_12;
if ( F_113 ( V_221 ) ) {
V_227 = V_224 [ 0 ] & 0x7fffffff ;
V_228 = V_224 [ 1 ] & 0x7fffffff ;
}
if ( V_206 -> V_21 ) {
V_11 = 0 ;
switch ( V_221 ) {
case V_229 :
if ( ! F_58 ( V_206 -> V_21 -> V_52 ) )
goto V_12;
else if ( V_225 ) {
* V_225 = ( V_43 -> V_44 & V_75 ) && ! V_43 -> V_61 ;
}
else {
V_43 -> V_44 &= V_75 ;
goto V_230;
}
break;
case V_222 :
if ( V_206 -> V_21 -> V_231 . V_46 == V_227
&& V_206 -> V_21 -> V_232 . V_46 == V_228
&& V_206 -> V_21 -> V_62 == 0 ) {
if ( V_226 )
* V_226 = 1 ;
break;
}
case V_223 :
if ( V_206 -> V_21 -> V_231 . V_46 == V_227
&& V_206 -> V_21 -> V_232 . V_46 == V_228
&& V_206 -> V_21 -> V_62 == 0 ) {
if ( V_226 )
* V_226 = 1 ;
goto V_230;
}
case V_233 :
V_11 = V_208 ;
}
F_115 ( V_23 ) ;
goto V_12;
}
V_28 = F_109 ( V_207 , V_206 , V_43 -> V_50 , true ) ;
if ( V_28 < 0 ) {
F_115 ( V_23 ) ;
goto V_31;
}
if ( V_226 )
* V_226 = 1 ;
F_104 ( V_43 ) ;
if ( F_113 ( V_221 ) ) {
V_43 -> V_44 = V_74 | V_73
| V_234 | V_235 ;
V_43 -> V_45 . V_46 = V_227 ;
V_43 -> V_47 . V_46 = V_228 ;
V_43 -> V_45 . V_236 = 0 ;
V_43 -> V_47 . V_236 = 0 ;
}
V_230:
V_11 = F_101 ( V_2 , V_201 , V_43 ) ;
if ( ! V_11 )
V_11 = F_28 ( F_33 ( V_23 ) ) ;
if ( ! V_11 )
V_11 = F_112 ( V_201 ) ;
V_12:
F_51 ( V_23 ) ;
if ( V_206 && ! F_6 ( V_206 ) )
F_15 ( V_206 ) ;
F_115 ( V_23 ) ;
return V_11 ;
V_31:
V_11 = F_28 ( V_28 ) ;
goto V_12;
}
T_1
F_116 ( struct V_1 * V_2 , struct V_22 * V_23 , char * V_152 , int * V_237 )
{
struct V_37 * V_37 ;
T_9 V_168 ;
T_1 V_11 ;
int V_28 ;
struct V_8 V_8 ;
V_11 = F_30 ( V_2 , V_23 , V_238 , V_98 ) ;
if ( V_11 )
goto V_12;
V_8 . V_9 = V_23 -> V_30 -> V_10 . V_9 ;
V_8 . V_3 = V_23 -> V_29 ;
V_37 = V_8 . V_3 -> V_21 ;
V_11 = V_199 ;
if ( ! V_37 -> V_211 -> V_239 )
goto V_12;
F_117 ( & V_8 ) ;
V_168 = F_81 () ; F_82 ( V_175 ) ;
V_28 = V_37 -> V_211 -> V_239 ( V_8 . V_3 , ( char V_177 * ) V_152 , * V_237 ) ;
F_82 ( V_168 ) ;
if ( V_28 < 0 )
goto V_31;
* V_237 = V_28 ;
V_11 = 0 ;
V_12:
return V_11 ;
V_31:
V_11 = F_28 ( V_28 ) ;
goto V_12;
}
T_1
F_118 ( struct V_1 * V_2 , struct V_22 * V_23 ,
char * V_203 , int V_204 ,
char * V_8 , int V_240 ,
struct V_22 * V_201 ,
struct V_42 * V_43 )
{
struct V_3 * V_3 , * V_241 ;
T_1 V_11 , V_242 ;
int V_28 ;
V_11 = V_36 ;
if ( ! V_204 || ! V_240 )
goto V_12;
V_11 = V_208 ;
if ( F_25 ( V_203 , V_204 ) )
goto V_12;
V_11 = F_30 ( V_2 , V_23 , V_34 , V_209 ) ;
if ( V_11 )
goto V_12;
V_28 = F_106 ( V_23 ) ;
if ( V_28 )
goto V_31;
F_49 ( V_23 ) ;
V_3 = V_23 -> V_29 ;
V_241 = F_27 ( V_203 , V_3 , V_204 ) ;
V_28 = F_7 ( V_241 ) ;
if ( F_6 ( V_241 ) )
goto V_31;
if ( F_119 ( V_8 [ V_240 ] != 0 ) ) {
char * V_243 = F_120 ( V_240 + 1 , V_244 ) ;
if ( V_243 == NULL )
V_28 = - V_245 ;
else {
strncpy ( V_243 , V_8 , V_240 ) ;
V_243 [ V_240 ] = 0 ;
V_28 = F_121 ( V_3 -> V_21 , V_241 , V_243 ) ;
F_122 ( V_243 ) ;
}
} else
V_28 = F_121 ( V_3 -> V_21 , V_241 , V_8 ) ;
V_11 = F_28 ( V_28 ) ;
if ( ! V_11 )
V_11 = F_28 ( F_33 ( V_23 ) ) ;
F_51 ( V_23 ) ;
F_115 ( V_23 ) ;
V_242 = F_32 ( V_201 , V_23 -> V_30 , V_241 , V_23 ) ;
F_15 ( V_241 ) ;
if ( V_11 == 0 ) V_11 = V_242 ;
V_12:
return V_11 ;
V_31:
V_11 = F_28 ( V_28 ) ;
goto V_12;
}
T_1
F_123 ( struct V_1 * V_2 , struct V_22 * V_246 ,
char * V_24 , int V_25 , struct V_22 * V_247 )
{
struct V_3 * V_248 , * V_241 , * V_249 ;
struct V_37 * V_207 ;
T_1 V_11 ;
int V_28 ;
V_11 = F_30 ( V_2 , V_246 , V_34 , V_209 ) ;
if ( V_11 )
goto V_12;
V_11 = F_30 ( V_2 , V_247 , 0 , V_98 ) ;
if ( V_11 )
goto V_12;
V_11 = V_250 ;
if ( F_41 ( V_247 -> V_29 -> V_21 -> V_52 ) )
goto V_12;
V_11 = V_107 ;
if ( ! V_25 )
goto V_12;
V_11 = V_208 ;
if ( F_25 ( V_24 , V_25 ) )
goto V_12;
V_28 = F_106 ( V_247 ) ;
if ( V_28 ) {
V_11 = F_28 ( V_28 ) ;
goto V_12;
}
F_26 ( V_246 , V_32 ) ;
V_248 = V_246 -> V_29 ;
V_207 = V_248 -> V_21 ;
V_241 = F_27 ( V_24 , V_248 , V_25 ) ;
V_28 = F_7 ( V_241 ) ;
if ( F_6 ( V_241 ) )
goto V_31;
V_249 = V_247 -> V_29 ;
V_11 = V_36 ;
if ( ! V_249 -> V_21 )
goto V_251;
V_28 = F_124 ( V_249 , V_207 , V_241 , NULL ) ;
if ( ! V_28 ) {
V_11 = F_28 ( F_33 ( V_246 ) ) ;
if ( ! V_11 )
V_11 = F_28 ( F_33 ( V_247 ) ) ;
} else {
if ( V_28 == - V_252 && V_2 -> V_193 == 2 )
V_11 = V_106 ;
else
V_11 = F_28 ( V_28 ) ;
}
V_251:
F_15 ( V_241 ) ;
V_253:
F_51 ( V_246 ) ;
F_115 ( V_247 ) ;
V_12:
return V_11 ;
V_31:
V_11 = F_28 ( V_28 ) ;
goto V_253;
}
T_1
F_125 ( struct V_1 * V_2 , struct V_22 * V_246 , char * V_203 , int V_204 ,
struct V_22 * V_247 , char * V_254 , int V_255 )
{
struct V_3 * V_256 , * V_257 , * V_258 , * V_259 , * V_260 ;
struct V_37 * V_261 , * V_262 ;
T_1 V_11 ;
int V_28 ;
V_11 = F_30 ( V_2 , V_246 , V_34 , V_263 ) ;
if ( V_11 )
goto V_12;
V_11 = F_30 ( V_2 , V_247 , V_34 , V_209 ) ;
if ( V_11 )
goto V_12;
V_256 = V_246 -> V_29 ;
V_261 = V_256 -> V_21 ;
V_257 = V_247 -> V_29 ;
V_262 = V_257 -> V_21 ;
V_11 = V_107 ;
if ( ! V_204 || F_25 ( V_203 , V_204 ) || ! V_255 || F_25 ( V_254 , V_255 ) )
goto V_12;
V_28 = F_106 ( V_246 ) ;
if ( V_28 ) {
V_11 = F_28 ( V_28 ) ;
goto V_12;
}
V_260 = F_126 ( V_257 , V_256 ) ;
V_246 -> V_213 = V_247 -> V_213 = 1 ;
F_127 ( V_246 ) ;
F_127 ( V_247 ) ;
V_258 = F_27 ( V_203 , V_256 , V_204 ) ;
V_28 = F_7 ( V_258 ) ;
if ( F_6 ( V_258 ) )
goto V_31;
V_28 = - V_13 ;
if ( ! V_258 -> V_21 )
goto V_264;
V_28 = - V_200 ;
if ( V_258 == V_260 )
goto V_264;
V_259 = F_27 ( V_254 , V_257 , V_255 ) ;
V_28 = F_7 ( V_259 ) ;
if ( F_6 ( V_259 ) )
goto V_264;
V_28 = - V_265 ;
if ( V_259 == V_260 )
goto V_266;
V_28 = - V_252 ;
if ( V_246 -> V_30 -> V_10 . V_9 != V_247 -> V_30 -> V_10 . V_9 )
goto V_266;
if ( V_246 -> V_30 -> V_10 . V_3 != V_247 -> V_30 -> V_10 . V_3 )
goto V_266;
V_28 = F_128 ( V_261 , V_258 , V_262 , V_259 , NULL ) ;
if ( ! V_28 ) {
V_28 = F_33 ( V_247 ) ;
if ( ! V_28 )
V_28 = F_33 ( V_246 ) ;
}
V_266:
F_15 ( V_259 ) ;
V_264:
F_15 ( V_258 ) ;
V_31:
V_11 = F_28 ( V_28 ) ;
F_129 ( V_246 ) ;
F_129 ( V_247 ) ;
F_130 ( V_257 , V_256 ) ;
V_246 -> V_213 = V_247 -> V_213 = 0 ;
F_115 ( V_246 ) ;
V_12:
return V_11 ;
}
T_1
F_131 ( struct V_1 * V_2 , struct V_22 * V_23 , int type ,
char * V_203 , int V_204 )
{
struct V_3 * V_3 , * V_267 ;
struct V_37 * V_207 ;
T_1 V_11 ;
int V_28 ;
V_11 = V_106 ;
if ( ! V_204 || F_25 ( V_203 , V_204 ) )
goto V_12;
V_11 = F_30 ( V_2 , V_23 , V_34 , V_263 ) ;
if ( V_11 )
goto V_12;
V_28 = F_106 ( V_23 ) ;
if ( V_28 )
goto V_31;
F_26 ( V_23 , V_32 ) ;
V_3 = V_23 -> V_29 ;
V_207 = V_3 -> V_21 ;
V_267 = F_27 ( V_203 , V_3 , V_204 ) ;
V_28 = F_7 ( V_267 ) ;
if ( F_6 ( V_267 ) )
goto V_31;
if ( ! V_267 -> V_21 ) {
F_15 ( V_267 ) ;
V_11 = V_36 ;
goto V_12;
}
if ( ! type )
type = V_267 -> V_21 -> V_52 & V_268 ;
if ( type != V_34 )
V_28 = F_132 ( V_207 , V_267 , NULL ) ;
else
V_28 = F_133 ( V_207 , V_267 ) ;
if ( ! V_28 )
V_28 = F_33 ( V_23 ) ;
F_15 ( V_267 ) ;
V_31:
V_11 = F_28 ( V_28 ) ;
V_12:
return V_11 ;
}
static int F_134 ( void * V_269 , const char * V_24 , int V_270 ,
T_8 V_163 , T_11 V_127 , unsigned int V_271 )
{
struct V_272 * V_152 = V_269 ;
struct V_273 * V_274 = ( void * ) ( V_152 -> V_275 + V_152 -> V_276 ) ;
unsigned int V_277 ;
V_277 = F_135 ( sizeof( struct V_273 ) + V_270 , sizeof( T_11 ) ) ;
if ( V_152 -> V_276 + V_277 > V_278 ) {
V_152 -> V_279 = 1 ;
return - V_200 ;
}
V_274 -> V_270 = V_270 ;
V_274 -> V_163 = V_163 ;
V_274 -> V_127 = V_127 ;
V_274 -> V_271 = V_271 ;
memcpy ( V_274 -> V_24 , V_24 , V_270 ) ;
V_152 -> V_276 += V_277 ;
return 0 ;
}
static T_1 F_136 ( struct V_114 * V_114 , T_12 V_280 ,
struct V_281 * V_282 , T_8 * V_283 )
{
struct V_273 * V_274 ;
int V_28 ;
int V_159 ;
T_8 V_163 ;
struct V_272 V_152 = {
. V_284 . V_285 = F_134 ,
. V_275 = ( void * ) F_137 (GFP_KERNEL)
} ;
if ( ! V_152 . V_275 )
return F_28 ( - V_245 ) ;
V_163 = * V_283 ;
while ( 1 ) {
struct V_37 * V_286 = F_87 ( V_114 ) ;
unsigned int V_277 ;
V_282 -> V_11 = V_287 ;
V_152 . V_276 = 0 ;
V_152 . V_279 = 0 ;
V_28 = F_138 ( V_114 , & V_152 . V_284 ) ;
if ( V_152 . V_279 )
V_28 = 0 ;
if ( V_28 < 0 )
break;
V_159 = V_152 . V_276 ;
if ( ! V_159 )
break;
V_28 = F_139 ( & V_286 -> V_87 ) ;
if ( V_28 )
break;
V_274 = (struct V_273 * ) V_152 . V_275 ;
while ( V_159 > 0 ) {
V_163 = V_274 -> V_163 ;
if ( V_280 ( V_282 , V_274 -> V_24 , V_274 -> V_270 , V_274 -> V_163 ,
V_274 -> V_127 , V_274 -> V_271 ) )
break;
if ( V_282 -> V_11 != V_104 )
break;
V_277 = F_135 ( sizeof( * V_274 ) + V_274 -> V_270 ,
sizeof( T_11 ) ) ;
V_159 -= V_277 ;
V_274 = (struct V_273 * ) ( ( char * ) V_274 + V_277 ) ;
}
F_56 ( & V_286 -> V_87 ) ;
if ( V_159 > 0 )
break;
V_163 = F_140 ( V_114 , 0 , V_288 ) ;
}
F_141 ( ( unsigned long ) ( V_152 . V_275 ) ) ;
if ( V_28 )
return F_28 ( V_28 ) ;
* V_283 = V_163 ;
return V_282 -> V_11 ;
}
T_1
F_142 ( struct V_1 * V_2 , struct V_22 * V_23 , T_8 * V_283 ,
struct V_281 * V_282 , T_12 V_280 )
{
T_1 V_11 ;
struct V_114 * V_114 ;
T_8 V_163 = * V_283 ;
int V_113 = V_119 ;
if ( V_2 -> V_193 > 2 )
V_113 |= V_121 ;
V_11 = F_61 ( V_2 , V_23 , V_34 , V_113 , & V_114 ) ;
if ( V_11 )
goto V_12;
V_163 = F_140 ( V_114 , V_163 , V_289 ) ;
if ( V_163 < 0 ) {
V_11 = F_28 ( ( int ) V_163 ) ;
goto V_290;
}
V_11 = F_136 ( V_114 , V_280 , V_282 , V_283 ) ;
if ( V_11 == V_287 || V_11 == V_291 )
V_11 = V_104 ;
V_290:
F_68 ( V_114 ) ;
V_12:
return V_11 ;
}
T_1
F_143 ( struct V_1 * V_2 , struct V_22 * V_23 , struct V_292 * V_293 , int V_90 )
{
T_1 V_11 ;
V_11 = F_30 ( V_2 , V_23 , 0 , V_98 | V_90 ) ;
if ( ! V_11 ) {
struct V_8 V_8 = {
. V_9 = V_23 -> V_30 -> V_10 . V_9 ,
. V_3 = V_23 -> V_29 ,
} ;
if ( F_144 ( & V_8 , V_293 ) )
V_11 = V_215 ;
}
return V_11 ;
}
static int F_145 ( struct V_1 * V_2 , struct V_5 * exp )
{
return F_146 ( V_2 , exp ) & V_294 ;
}
T_1
F_43 ( struct V_1 * V_2 , struct V_5 * exp ,
struct V_3 * V_3 , int V_295 )
{
struct V_37 * V_37 = V_3 -> V_21 ;
int V_11 ;
if ( ( V_295 & V_296 ) == V_98 )
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
if ( V_295 & ( V_76 | V_70 | V_63 ) ) {
if ( F_145 ( V_2 , exp ) ||
F_147 ( exp -> V_10 . V_9 ) )
return V_105 ;
if ( F_148 ( V_37 ) )
return V_107 ;
}
if ( ( V_295 & V_63 ) && F_63 ( V_37 ) )
return V_107 ;
if ( V_295 & V_298 ) {
if ( exp -> V_14 & V_299 )
return 0 ;
else
V_295 = V_119 | V_64 ;
}
if ( ( V_295 & V_64 ) &&
F_102 ( V_37 -> V_300 , F_103 () ) )
return 0 ;
V_11 = F_149 ( V_37 , V_295 & ( V_301 | V_302 | V_303 ) ) ;
if ( V_11 == - V_304 && F_58 ( V_37 -> V_52 ) &&
( V_295 == ( V_119 | V_64 ) ||
V_295 == ( V_119 | V_305 ) ) )
V_11 = F_149 ( V_37 , V_303 ) ;
return V_11 ? F_28 ( V_11 ) : 0 ;
}
void
F_150 ( void )
{
struct V_125 * V_306 , * V_307 ;
unsigned int V_308 ;
F_22 ( L_9 ) ;
for ( V_308 = 0 ; V_308 < V_309 ; V_308 ++ ) {
V_306 = V_136 [ V_308 ] . V_138 ;
while( V_306 ) {
V_307 = V_306 ;
V_306 = V_306 -> V_139 ;
F_122 ( V_307 ) ;
}
V_136 [ V_308 ] . V_138 = NULL ;
}
}
int
F_151 ( int V_310 )
{
int V_308 ;
int V_311 = 0 ;
int V_312 ;
struct V_125 * * V_306 = NULL ;
if ( V_136 [ 0 ] . V_138 )
return 0 ;
V_312 = F_152 ( V_310 , V_309 ) ;
if ( V_312 < 2 )
V_312 = 2 ;
V_310 = V_312 * V_309 ;
F_22 ( L_10 , V_310 ) ;
for ( V_308 = 0 ; V_308 < V_309 ; V_308 ++ ) {
F_153 ( & V_136 [ V_308 ] . V_137 ) ;
V_306 = & V_136 [ V_308 ] . V_138 ;
for ( V_311 = 0 ; V_311 < V_312 ; V_311 ++ ) {
* V_306 = F_154 ( sizeof( struct V_125 ) , V_244 ) ;
if ( ! * V_306 )
goto V_313;
V_306 = & ( * V_306 ) -> V_139 ;
}
* V_306 = NULL ;
}
V_144 . V_145 = V_310 ;
return 0 ;
V_313:
F_22 ( L_11 ) ;
F_150 () ;
return - V_245 ;
}

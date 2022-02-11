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
static void
F_39 ( struct V_36 * V_36 , struct V_44 * V_45 )
{
#define F_40 (ATTR_ATIME_SET | ATTR_MTIME_SET)
#define F_41 (30*60)
if ( ( V_45 -> V_46 & F_40 ) == F_40 &&
V_45 -> V_47 . V_48 == V_45 -> V_49 . V_48 ) {
T_2 V_50 = V_45 -> V_49 . V_48 - F_42 () ;
if ( V_50 < 0 )
V_50 = - V_50 ;
if ( V_50 < F_41 &&
F_43 ( V_36 , V_45 ) != 0 ) {
V_45 -> V_46 &= ~ F_40 ;
}
}
if ( V_45 -> V_46 & V_51 ) {
V_45 -> V_52 &= V_53 ;
V_45 -> V_52 |= ( V_36 -> V_37 & ~ V_53 ) ;
}
if ( ! F_44 ( V_36 -> V_37 ) &&
( ( ( V_45 -> V_46 & V_54 ) && ! F_45 ( V_45 -> V_55 , V_36 -> V_56 ) ) ||
( ( V_45 -> V_46 & V_57 ) && ! F_46 ( V_45 -> V_58 , V_36 -> V_59 ) ) ) ) {
V_45 -> V_46 |= V_60 ;
if ( V_45 -> V_46 & V_51 ) {
V_45 -> V_52 &= ~ V_61 ;
if ( V_45 -> V_52 & V_62 )
V_45 -> V_52 &= ~ V_63 ;
} else {
V_45 -> V_46 |= ( V_64 | V_65 ) ;
}
}
}
static T_1
F_47 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_44 * V_45 )
{
struct V_36 * V_36 = V_23 -> V_29 -> V_21 ;
int V_28 ;
if ( V_45 -> V_66 < V_36 -> V_67 ) {
T_1 V_11 ;
V_11 = F_48 ( V_2 , V_23 -> V_30 , V_23 -> V_29 ,
V_68 | V_69 ) ;
if ( V_11 )
return V_11 ;
}
V_28 = F_49 ( V_36 ) ;
if ( V_28 )
goto V_70;
V_28 = F_50 ( V_36 , NULL , V_45 -> V_66 ) ;
if ( V_28 )
goto V_71;
return 0 ;
V_71:
F_51 ( V_36 ) ;
V_70:
return F_28 ( V_28 ) ;
}
T_1
F_52 ( struct V_1 * V_2 , struct V_22 * V_23 , struct V_44 * V_45 ,
int V_72 , T_2 V_73 )
{
struct V_3 * V_3 ;
struct V_36 * V_36 ;
int V_74 = V_75 ;
T_3 V_76 = 0 ;
T_1 V_11 ;
int V_28 ;
int V_77 = 0 ;
if ( V_45 -> V_46 & ( V_78 | V_79 | V_80 ) )
V_74 |= V_81 | V_69 ;
if ( V_45 -> V_46 & V_80 )
V_76 = V_82 ;
V_11 = F_30 ( V_2 , V_23 , V_76 , V_74 ) ;
if ( V_11 )
goto V_12;
V_3 = V_23 -> V_29 ;
V_36 = V_3 -> V_21 ;
if ( F_53 ( V_36 -> V_37 ) )
V_45 -> V_46 &= ~ V_51 ;
if ( ! V_45 -> V_46 )
goto V_12;
F_39 ( V_36 , V_45 ) ;
if ( V_45 -> V_46 & V_80 ) {
V_11 = F_47 ( V_2 , V_23 , V_45 ) ;
if ( V_11 )
goto V_12;
V_77 = 1 ;
}
V_45 -> V_46 |= V_83 ;
if ( V_72 && V_73 != V_36 -> V_84 . V_48 ) {
V_11 = V_85 ;
goto V_71;
}
V_28 = F_33 ( V_36 ) ;
if ( V_28 )
goto V_86;
F_26 ( V_23 ) ;
V_28 = F_54 ( V_3 , V_45 , NULL ) ;
F_55 ( V_23 ) ;
V_86:
V_11 = F_28 ( V_28 ) ;
V_71:
if ( V_77 )
F_51 ( V_36 ) ;
if ( ! V_11 )
F_36 ( V_23 ) ;
V_12:
return V_11 ;
}
static T_4 F_56 ( struct V_3 * V_3 , char * V_87 , void * * V_88 )
{
T_4 V_89 ;
T_4 V_90 ;
V_89 = F_57 ( V_3 , V_87 , NULL , 0 ) ;
if ( V_89 <= 0 )
return V_89 ;
* V_88 = F_58 ( V_89 , V_91 ) ;
if ( ! * V_88 )
return - V_92 ;
V_90 = F_57 ( V_3 , V_87 , * V_88 , V_89 ) ;
if ( V_90 < 0 )
F_59 ( * V_88 ) ;
return V_90 ;
}
static int
F_60 ( struct V_3 * V_3 , struct V_93 * V_94 , char * V_87 )
{
int V_25 ;
T_5 V_89 ;
char * V_88 = NULL ;
int error = 0 ;
V_89 = F_61 ( V_94 -> V_95 ) ;
V_88 = F_58 ( V_89 , V_91 ) ;
error = - V_92 ;
if ( V_88 == NULL )
goto V_12;
V_25 = F_62 ( & V_96 , V_94 , V_88 , V_89 ) ;
if ( V_25 < 0 ) {
error = V_25 ;
goto V_12;
}
error = F_63 ( V_3 , V_87 , V_88 , V_25 , 0 ) ;
V_12:
F_59 ( V_88 ) ;
return error ;
}
T_1
F_64 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_97 * V_98 )
{
T_1 error ;
int V_99 ;
struct V_3 * V_3 ;
struct V_36 * V_36 ;
struct V_93 * V_94 = NULL , * V_100 = NULL ;
unsigned int V_101 = 0 ;
error = F_30 ( V_2 , V_23 , 0 , V_75 ) ;
if ( error )
return error ;
V_3 = V_23 -> V_29 ;
V_36 = V_3 -> V_21 ;
if ( F_44 ( V_36 -> V_37 ) )
V_101 = V_102 ;
V_99 = F_65 ( V_98 , & V_94 , & V_100 , V_101 ) ;
if ( V_99 == - V_103 ) {
return V_104 ;
} else if ( V_99 < 0 )
goto V_31;
V_99 = F_60 ( V_3 , V_94 , V_105 ) ;
if ( V_99 < 0 )
goto V_106;
if ( F_44 ( V_36 -> V_37 ) )
V_99 = F_60 ( V_3 , V_100 , V_107 ) ;
V_106:
F_66 ( V_94 ) ;
F_66 ( V_100 ) ;
V_31:
if ( V_99 == - V_108 )
return V_104 ;
else
return F_28 ( V_99 ) ;
}
static struct V_93 *
F_67 ( struct V_3 * V_3 , char * V_87 )
{
void * V_88 = NULL ;
struct V_93 * V_94 = NULL ;
int V_89 ;
V_89 = F_56 ( V_3 , V_87 , & V_88 ) ;
if ( ! V_89 )
V_89 = - V_109 ;
if ( V_89 <= 0 )
return F_68 ( V_89 ) ;
V_94 = F_69 ( & V_96 , V_88 , V_89 ) ;
F_59 ( V_88 ) ;
return V_94 ;
}
int
F_70 ( struct V_1 * V_2 , struct V_3 * V_3 , struct V_97 * * V_98 )
{
struct V_36 * V_36 = V_3 -> V_21 ;
int error = 0 ;
struct V_93 * V_94 = NULL , * V_100 = NULL ;
unsigned int V_101 = 0 ;
V_94 = F_67 ( V_3 , V_105 ) ;
if ( F_6 ( V_94 ) && F_7 ( V_94 ) == - V_109 )
V_94 = F_71 ( V_36 -> V_37 , V_91 ) ;
if ( F_6 ( V_94 ) ) {
error = F_7 ( V_94 ) ;
V_94 = NULL ;
goto V_12;
}
if ( F_44 ( V_36 -> V_37 ) ) {
V_100 = F_67 ( V_3 , V_107 ) ;
if ( F_6 ( V_100 ) && F_7 ( V_100 ) == - V_109 )
V_100 = NULL ;
else if ( F_6 ( V_100 ) ) {
error = F_7 ( V_100 ) ;
V_100 = NULL ;
goto V_12;
}
V_101 = V_102 ;
}
* V_98 = F_72 ( V_94 , V_100 , V_101 ) ;
if ( F_6 ( * V_98 ) ) {
error = F_7 ( * V_98 ) ;
* V_98 = NULL ;
}
V_12:
F_66 ( V_94 ) ;
F_66 ( V_100 ) ;
return error ;
}
int F_20 ( struct V_3 * V_3 )
{
struct V_36 * V_36 = V_3 -> V_21 ;
if ( V_36 == NULL )
return 0 ;
if ( V_36 -> V_37 & V_110 )
return 0 ;
if ( ! ( V_36 -> V_37 & V_111 ) )
return 0 ;
if ( F_57 ( V_3 , V_112 , NULL , 0 ) <= 0 )
return 0 ;
return 1 ;
}
T_1 F_73 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_113 * V_114 )
{
T_1 error ;
int V_99 ;
struct V_3 * V_3 ;
error = F_30 ( V_2 , V_23 , 0 , V_75 ) ;
if ( error )
return error ;
V_3 = V_23 -> V_29 ;
F_74 ( & V_3 -> V_21 -> V_115 ) ;
V_99 = F_75 ( V_3 , V_114 -> V_116 , V_114 -> V_25 ) ;
F_76 ( & V_3 -> V_21 -> V_115 ) ;
return F_28 ( V_99 ) ;
}
T_1 F_73 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_113 * V_114 )
{
return V_117 ;
}
T_1
F_77 ( struct V_1 * V_2 , struct V_22 * V_23 , T_6 * V_118 , T_6 * V_119 )
{
struct V_120 * V_121 ;
struct V_5 * V_122 ;
struct V_3 * V_3 ;
T_6 V_123 , V_124 = 0 , V_125 = 0 ;
T_1 error ;
error = F_30 ( V_2 , V_23 , 0 , V_126 ) ;
if ( error )
goto V_12;
V_122 = V_23 -> V_30 ;
V_3 = V_23 -> V_29 ;
if ( F_34 ( V_3 -> V_21 -> V_37 ) )
V_121 = V_127 ;
else if ( F_44 ( V_3 -> V_21 -> V_37 ) )
V_121 = V_128 ;
else
V_121 = V_129 ;
V_123 = * V_118 ;
for (; V_121 -> V_118 ; V_121 ++ ) {
if ( V_121 -> V_118 & V_123 ) {
T_1 V_130 ;
V_125 |= V_121 -> V_118 ;
V_130 = F_48 ( V_2 , V_122 , V_3 , V_121 -> V_131 ) ;
switch ( V_130 ) {
case V_132 :
V_124 |= V_121 -> V_118 ;
break;
case V_133 :
case V_134 :
case V_135 :
break;
default:
error = V_130 ;
goto V_12;
}
}
}
* V_118 = V_124 ;
if ( V_119 )
* V_119 = V_125 ;
V_12:
return error ;
}
static int F_78 ( struct V_36 * V_36 , int V_118 )
{
unsigned int V_136 ;
if ( V_118 & V_137 )
return 0 ;
V_136 = ( V_118 & V_81 ) ? V_38 : V_138 ;
return F_35 ( V_36 , V_136 | V_39 ) ;
}
T_1
F_79 ( struct V_1 * V_2 , struct V_22 * V_23 , T_3 type ,
int V_139 , struct V_140 * * V_141 )
{
struct V_8 V_8 ;
struct V_36 * V_36 ;
int V_101 = V_138 | V_142 ;
T_1 V_11 ;
int V_28 = 0 ;
F_80 () ;
if ( type == V_82 )
V_139 |= V_69 ;
V_11 = F_30 ( V_2 , V_23 , type , V_139 ) ;
if ( V_11 )
goto V_12;
V_8 . V_9 = V_23 -> V_30 -> V_10 . V_9 ;
V_8 . V_3 = V_23 -> V_29 ;
V_36 = V_8 . V_3 -> V_21 ;
V_11 = V_135 ;
if ( F_81 ( V_36 ) && ( V_139 & V_81 ) )
goto V_12;
if ( F_34 ( ( V_36 ) -> V_37 ) && F_82 ( V_36 ) )
goto V_12;
if ( ! V_36 -> V_143 )
goto V_12;
V_28 = F_78 ( V_36 , V_139 ) ;
if ( V_28 )
goto V_31;
if ( V_139 & V_81 ) {
if ( V_139 & V_144 )
V_101 = V_145 | V_142 ;
else
V_101 = V_38 | V_142 ;
}
* V_141 = F_83 ( & V_8 , V_101 , F_84 () ) ;
if ( F_6 ( * V_141 ) ) {
V_28 = F_7 ( * V_141 ) ;
* V_141 = NULL ;
} else {
V_28 = F_85 ( * V_141 , V_139 ) ;
if ( V_139 & V_146 )
( * V_141 ) -> V_147 |= V_148 ;
else
( * V_141 ) -> V_147 |= V_149 ;
}
V_31:
V_11 = F_28 ( V_28 ) ;
V_12:
F_80 () ;
return V_11 ;
}
void
F_86 ( struct V_140 * V_141 )
{
F_87 ( V_141 ) ;
}
static inline struct V_150 *
F_88 ( T_7 V_151 , T_8 V_152 )
{
struct V_150 * V_153 , * * V_154 , * * V_155 = NULL ;
int V_156 = 0 ;
unsigned int V_157 ;
struct V_158 * V_159 ;
V_157 = F_89 ( V_151 , V_152 , 0xfeedbeef ) & V_160 ;
V_159 = & V_161 [ V_157 ] ;
F_90 ( & V_159 -> V_162 ) ;
for ( V_154 = & V_159 -> V_163 ; ( V_153 = * V_154 ) ; V_154 = & V_153 -> V_164 ) {
if ( V_153 -> V_165 == V_152 && V_153 -> V_166 == V_151 )
goto V_167;
V_156 ++ ;
if ( V_153 -> V_168 == 0 )
V_155 = V_154 ;
}
V_156 = V_169 . V_170 ;
if ( ! V_155 ) {
F_91 ( & V_159 -> V_162 ) ;
return NULL ;
}
V_154 = V_155 ;
V_153 = * V_155 ;
V_153 -> V_166 = V_151 ;
V_153 -> V_165 = V_152 ;
V_153 -> V_171 = 0 ;
V_153 -> V_172 = V_157 ;
V_167:
if ( V_154 != & V_159 -> V_163 ) {
* V_154 = V_153 -> V_164 ;
V_153 -> V_164 = V_159 -> V_163 ;
V_159 -> V_163 = V_153 ;
}
V_153 -> V_168 ++ ;
V_169 . V_173 [ V_156 * 10 / V_169 . V_170 ] ++ ;
F_91 ( & V_159 -> V_162 ) ;
return V_153 ;
}
static int
F_92 ( struct V_174 * V_175 , struct V_176 * V_88 ,
struct V_177 * V_178 )
{
struct V_1 * V_2 = V_178 -> V_179 . V_116 ;
struct V_180 * * V_181 = V_2 -> V_182 ;
struct V_180 * V_180 = V_88 -> V_180 ;
T_5 V_183 ;
V_183 = V_178 -> V_25 ;
if ( V_2 -> V_184 . V_185 == 0 ) {
F_93 ( V_180 ) ;
F_94 ( * V_2 -> V_182 ) ;
* ( V_2 -> V_182 ++ ) = V_180 ;
V_2 -> V_184 . V_186 = V_88 -> V_187 ;
V_2 -> V_184 . V_185 = V_183 ;
} else if ( V_180 != V_181 [ - 1 ] ) {
F_93 ( V_180 ) ;
if ( * V_2 -> V_182 )
F_94 ( * V_2 -> V_182 ) ;
* ( V_2 -> V_182 ++ ) = V_180 ;
V_2 -> V_184 . V_185 += V_183 ;
} else
V_2 -> V_184 . V_185 += V_183 ;
return V_183 ;
}
static int F_95 ( struct V_174 * V_175 ,
struct V_177 * V_178 )
{
return F_96 ( V_175 , V_178 , F_92 ) ;
}
static T_1
F_97 ( struct V_1 * V_2 , struct V_22 * V_23 , struct V_140 * V_140 ,
T_9 V_187 , struct V_188 * V_189 , int V_190 , unsigned long * V_191 )
{
T_10 V_192 ;
T_1 V_11 ;
int V_28 ;
V_11 = V_135 ;
if ( V_140 -> V_193 -> V_194 && V_2 -> V_195 ) {
struct V_177 V_178 = {
. V_25 = 0 ,
. V_196 = * V_191 ,
. V_197 = V_187 ,
. V_179 . V_116 = V_2 ,
} ;
V_2 -> V_182 = V_2 -> V_198 + 1 ;
V_28 = F_98 ( V_140 , & V_178 , F_95 ) ;
} else {
V_192 = F_99 () ;
F_100 ( V_199 ) ;
V_28 = F_101 ( V_140 , (struct V_200 V_201 * ) V_189 , V_190 , & V_187 ) ;
F_100 ( V_192 ) ;
}
if ( V_28 >= 0 ) {
V_169 . V_202 += V_28 ;
* V_191 = V_28 ;
V_11 = 0 ;
F_102 ( V_140 ) ;
} else
V_11 = F_28 ( V_28 ) ;
return V_11 ;
}
static void F_103 ( struct V_3 * V_3 )
{
struct V_44 V_203 ;
V_203 . V_46 = V_64 | V_65 | V_60 ;
F_74 ( & V_3 -> V_21 -> V_115 ) ;
F_54 ( V_3 , & V_203 , NULL ) ;
F_76 ( & V_3 -> V_21 -> V_115 ) ;
}
static int F_104 ( struct V_140 * V_140 )
{
struct V_36 * V_36 = F_105 ( V_140 ) ;
static T_8 V_204 ;
static T_7 V_205 ;
int V_11 = 0 ;
if ( F_106 ( & V_36 -> V_206 ) > 1
|| ( V_204 == V_36 -> V_207 && V_205 == V_36 -> V_42 -> V_208 ) ) {
F_22 ( L_2 , F_107 ( V_209 ) ) ;
F_108 ( 10 ) ;
F_22 ( L_3 , F_107 ( V_209 ) ) ;
}
if ( V_36 -> V_210 & V_211 ) {
F_22 ( L_4 , F_107 ( V_209 ) ) ;
V_11 = F_109 ( V_140 , 0 ) ;
}
V_204 = V_36 -> V_207 ;
V_205 = V_36 -> V_42 -> V_208 ;
return V_11 ;
}
static T_1
F_110 ( struct V_1 * V_2 , struct V_22 * V_23 , struct V_140 * V_140 ,
T_9 V_187 , struct V_188 * V_189 , int V_190 ,
unsigned long * V_212 , int * V_213 )
{
struct V_5 * exp ;
struct V_3 * V_3 ;
struct V_36 * V_36 ;
T_10 V_192 ;
T_1 V_11 = 0 ;
int V_28 ;
int V_214 = * V_213 ;
int V_215 ;
T_9 V_197 = V_187 ;
V_3 = V_140 -> V_216 . V_3 ;
V_36 = V_3 -> V_21 ;
exp = V_23 -> V_30 ;
V_215 = ( V_2 -> V_217 == 2 ) && F_111 ( exp ) ;
if ( ! F_37 ( exp ) )
V_214 = 0 ;
V_192 = F_99 () ; F_100 ( V_199 ) ;
V_28 = F_112 ( V_140 , (struct V_200 V_201 * ) V_189 , V_190 , & V_197 ) ;
F_100 ( V_192 ) ;
if ( V_28 < 0 )
goto V_31;
* V_212 = V_28 ;
V_169 . V_218 += V_28 ;
F_113 ( V_140 ) ;
if ( V_36 -> V_37 & ( V_61 | V_63 ) )
F_103 ( V_3 ) ;
if ( V_214 ) {
if ( V_215 )
V_28 = F_104 ( V_140 ) ;
else
V_28 = F_114 ( V_140 , V_187 , V_187 + * V_212 , 0 ) ;
}
V_31:
F_22 ( L_5 , V_28 ) ;
if ( V_28 >= 0 )
V_11 = 0 ;
else
V_11 = F_28 ( V_28 ) ;
return V_11 ;
}
T_1 F_115 ( struct V_1 * V_2 , struct V_22 * V_23 ,
T_9 V_187 , struct V_188 * V_189 , int V_190 , unsigned long * V_191 )
{
struct V_140 * V_140 ;
struct V_36 * V_36 ;
struct V_150 * V_153 ;
T_1 V_11 ;
V_11 = F_79 ( V_2 , V_23 , V_82 , V_144 , & V_140 ) ;
if ( V_11 )
return V_11 ;
V_36 = F_105 ( V_140 ) ;
V_153 = F_88 ( V_36 -> V_42 -> V_208 , V_36 -> V_207 ) ;
if ( V_153 && V_153 -> V_171 )
V_140 -> V_219 = V_153 -> V_220 ;
V_11 = F_97 ( V_2 , V_23 , V_140 , V_187 , V_189 , V_190 , V_191 ) ;
if ( V_153 ) {
struct V_158 * V_159 = & V_161 [ V_153 -> V_172 ] ;
F_90 ( & V_159 -> V_162 ) ;
V_153 -> V_220 = V_140 -> V_219 ;
V_153 -> V_171 = 1 ;
V_153 -> V_168 -- ;
F_91 ( & V_159 -> V_162 ) ;
}
F_86 ( V_140 ) ;
return V_11 ;
}
T_1
F_116 ( struct V_1 * V_2 , struct V_22 * V_23 , struct V_140 * V_140 ,
T_9 V_187 , struct V_188 * V_189 , int V_190 ,
unsigned long * V_191 )
{
T_1 V_11 ;
if ( V_140 ) {
V_11 = F_48 ( V_2 , V_23 -> V_30 , V_23 -> V_29 ,
V_144 | V_69 ) ;
if ( V_11 )
goto V_12;
V_11 = F_97 ( V_2 , V_23 , V_140 , V_187 , V_189 , V_190 , V_191 ) ;
} else
V_11 = F_115 ( V_2 , V_23 , V_187 , V_189 , V_190 , V_191 ) ;
V_12:
return V_11 ;
}
T_1
F_117 ( struct V_1 * V_2 , struct V_22 * V_23 , struct V_140 * V_140 ,
T_9 V_187 , struct V_188 * V_189 , int V_190 , unsigned long * V_212 ,
int * V_213 )
{
T_1 V_11 = 0 ;
if ( V_140 ) {
V_11 = F_48 ( V_2 , V_23 -> V_30 , V_23 -> V_29 ,
V_81 | V_69 ) ;
if ( V_11 )
goto V_12;
V_11 = F_110 ( V_2 , V_23 , V_140 , V_187 , V_189 , V_190 , V_212 ,
V_213 ) ;
} else {
V_11 = F_79 ( V_2 , V_23 , V_82 , V_81 , & V_140 ) ;
if ( V_11 )
goto V_12;
if ( V_212 )
V_11 = F_110 ( V_2 , V_23 , V_140 , V_187 , V_189 , V_190 ,
V_212 , V_213 ) ;
F_86 ( V_140 ) ;
}
V_12:
return V_11 ;
}
T_1
F_118 ( struct V_1 * V_2 , struct V_22 * V_23 ,
T_9 V_187 , unsigned long V_191 )
{
struct V_140 * V_140 ;
T_9 V_221 = V_222 ;
T_1 V_11 = V_223 ;
if ( V_187 < 0 )
goto V_12;
if ( V_191 != 0 ) {
V_221 = V_187 + ( T_9 ) V_191 - 1 ;
if ( V_221 < V_187 )
goto V_12;
}
V_11 = F_79 ( V_2 , V_23 , V_82 ,
V_81 | V_137 , & V_140 ) ;
if ( V_11 )
goto V_12;
if ( F_37 ( V_23 -> V_30 ) ) {
int V_130 = F_114 ( V_140 , V_187 , V_221 , 0 ) ;
if ( V_130 != - V_103 )
V_11 = F_28 ( V_130 ) ;
else
V_11 = V_117 ;
}
F_86 ( V_140 ) ;
V_12:
return V_11 ;
}
static T_1
F_119 ( struct V_1 * V_2 , struct V_22 * V_224 ,
struct V_44 * V_45 )
{
V_45 -> V_46 &= ~ V_51 ;
if ( ! F_45 ( F_120 () , V_225 ) )
V_45 -> V_46 &= ~ ( V_54 | V_57 ) ;
if ( V_45 -> V_46 )
return F_52 ( V_2 , V_224 , V_45 , 0 , ( T_2 ) 0 ) ;
return 0 ;
}
static void
F_121 ( struct V_44 * V_45 )
{
if ( ( V_45 -> V_46 & V_80 ) && ( V_45 -> V_66 == 0 ) )
V_45 -> V_46 &= ~ V_80 ;
}
T_1
F_122 ( struct V_1 * V_2 , struct V_22 * V_23 ,
char * V_226 , int V_227 , struct V_44 * V_45 ,
int type , T_7 V_228 , struct V_22 * V_224 )
{
struct V_3 * V_3 , * V_229 = NULL ;
struct V_36 * V_230 ;
T_1 V_11 ;
T_1 V_130 ;
int V_28 ;
V_11 = V_135 ;
if ( ! V_227 )
goto V_12;
V_11 = V_231 ;
if ( F_25 ( V_226 , V_227 ) )
goto V_12;
V_11 = F_30 ( V_2 , V_23 , V_33 , V_232 ) ;
if ( V_11 )
goto V_12;
V_3 = V_23 -> V_29 ;
V_230 = V_3 -> V_21 ;
V_11 = V_233 ;
if ( ! V_230 -> V_234 -> V_235 )
goto V_12;
if ( ! V_224 -> V_29 ) {
V_28 = F_123 ( V_23 ) ;
if ( V_28 )
goto V_31;
F_124 ( V_23 , V_236 ) ;
V_229 = F_27 ( V_226 , V_3 , V_227 ) ;
V_28 = F_7 ( V_229 ) ;
if ( F_6 ( V_229 ) )
goto V_31;
V_11 = F_32 ( V_224 , V_23 -> V_30 , V_229 , V_23 ) ;
if ( V_11 )
goto V_12;
} else {
V_229 = F_3 ( V_224 -> V_29 ) ;
if ( ! V_23 -> V_237 ) {
F_125 ( V_238
L_6 ,
V_3 ) ;
V_11 = V_239 ;
goto V_12;
}
}
V_11 = V_231 ;
if ( V_229 -> V_21 ) {
F_22 ( L_7 ,
V_3 , V_229 ) ;
goto V_12;
}
if ( ! ( V_45 -> V_46 & V_51 ) )
V_45 -> V_52 = 0 ;
V_45 -> V_52 = ( V_45 -> V_52 & V_53 ) | type ;
V_11 = V_223 ;
if ( ! F_34 ( type ) && ! F_44 ( type ) && ! F_126 ( type ) ) {
F_125 ( V_240 L_8 ,
type ) ;
goto V_12;
}
V_11 = 0 ;
V_28 = 0 ;
switch ( type ) {
case V_82 :
V_28 = F_127 ( V_230 , V_229 , V_45 -> V_52 , true ) ;
if ( ! V_28 )
F_121 ( V_45 ) ;
break;
case V_33 :
V_28 = F_128 ( V_230 , V_229 , V_45 -> V_52 ) ;
break;
case V_241 :
case V_242 :
case V_243 :
case V_244 :
V_28 = F_129 ( V_230 , V_229 , V_45 -> V_52 , V_228 ) ;
break;
}
if ( V_28 < 0 )
goto V_31;
V_11 = F_119 ( V_2 , V_224 , V_45 ) ;
V_130 = F_28 ( F_36 ( V_23 ) ) ;
if ( V_130 )
V_11 = V_130 ;
if ( ! V_11 )
V_11 = F_130 ( V_224 ) ;
V_12:
if ( V_229 && ! F_6 ( V_229 ) )
F_15 ( V_229 ) ;
return V_11 ;
V_31:
V_11 = F_28 ( V_28 ) ;
goto V_12;
}
static inline int F_131 ( int V_245 )
{
return V_245 == V_246
|| V_245 == V_247 ;
}
T_1
F_132 ( struct V_1 * V_2 , struct V_22 * V_23 ,
char * V_226 , int V_227 , struct V_44 * V_45 ,
struct V_22 * V_224 , int V_245 , T_6 * V_248 ,
bool * V_249 , bool * V_250 )
{
struct V_3 * V_3 , * V_229 = NULL ;
struct V_36 * V_230 ;
T_1 V_11 ;
int V_28 ;
T_11 V_251 = 0 , V_252 = 0 ;
V_11 = V_135 ;
if ( ! V_227 )
goto V_12;
V_11 = V_231 ;
if ( F_25 ( V_226 , V_227 ) )
goto V_12;
if ( ! ( V_45 -> V_46 & V_51 ) )
V_45 -> V_52 = 0 ;
V_11 = F_30 ( V_2 , V_23 , V_33 , V_34 ) ;
if ( V_11 )
goto V_12;
V_3 = V_23 -> V_29 ;
V_230 = V_3 -> V_21 ;
V_11 = V_233 ;
if ( ! V_230 -> V_234 -> V_235 )
goto V_12;
V_28 = F_123 ( V_23 ) ;
if ( V_28 )
goto V_31;
F_124 ( V_23 , V_236 ) ;
V_229 = F_27 ( V_226 , V_3 , V_227 ) ;
V_28 = F_7 ( V_229 ) ;
if ( F_6 ( V_229 ) )
goto V_31;
if ( ! V_229 -> V_21 ) {
V_11 = F_30 ( V_2 , V_23 , V_33 , V_232 ) ;
if ( V_11 )
goto V_12;
}
V_11 = F_32 ( V_224 , V_23 -> V_30 , V_229 , V_23 ) ;
if ( V_11 )
goto V_12;
if ( F_131 ( V_245 ) ) {
V_251 = V_248 [ 0 ] & 0x7fffffff ;
V_252 = V_248 [ 1 ] & 0x7fffffff ;
}
if ( V_229 -> V_21 ) {
V_11 = 0 ;
switch ( V_245 ) {
case V_253 :
if ( ! F_34 ( V_229 -> V_21 -> V_37 ) )
goto V_12;
else if ( V_249 ) {
* V_249 = ( V_45 -> V_46 & V_80 ) && ! V_45 -> V_66 ;
}
else {
V_45 -> V_46 &= V_80 ;
goto V_254;
}
break;
case V_246 :
if ( V_229 -> V_21 -> V_255 . V_48 == V_251
&& V_229 -> V_21 -> V_256 . V_48 == V_252
&& V_229 -> V_21 -> V_67 == 0 ) {
if ( V_250 )
* V_250 = 1 ;
break;
}
case V_247 :
if ( V_229 -> V_21 -> V_255 . V_48 == V_251
&& V_229 -> V_21 -> V_256 . V_48 == V_252
&& V_229 -> V_21 -> V_67 == 0 ) {
if ( V_250 )
* V_250 = 1 ;
goto V_254;
}
case V_257 :
V_11 = V_231 ;
}
F_133 ( V_23 ) ;
goto V_12;
}
V_28 = F_127 ( V_230 , V_229 , V_45 -> V_52 , true ) ;
if ( V_28 < 0 ) {
F_133 ( V_23 ) ;
goto V_31;
}
if ( V_250 )
* V_250 = 1 ;
F_121 ( V_45 ) ;
if ( F_131 ( V_245 ) ) {
V_45 -> V_46 = V_79 | V_78
| V_258 | V_259 ;
V_45 -> V_47 . V_48 = V_251 ;
V_45 -> V_49 . V_48 = V_252 ;
V_45 -> V_47 . V_260 = 0 ;
V_45 -> V_49 . V_260 = 0 ;
}
V_254:
V_11 = F_119 ( V_2 , V_224 , V_45 ) ;
if ( ! V_11 )
V_11 = F_28 ( F_36 ( V_23 ) ) ;
if ( ! V_11 )
V_11 = F_130 ( V_224 ) ;
V_12:
F_55 ( V_23 ) ;
if ( V_229 && ! F_6 ( V_229 ) )
F_15 ( V_229 ) ;
F_133 ( V_23 ) ;
return V_11 ;
V_31:
V_11 = F_28 ( V_28 ) ;
goto V_12;
}
T_1
F_134 ( struct V_1 * V_2 , struct V_22 * V_23 , char * V_88 , int * V_261 )
{
struct V_36 * V_36 ;
T_10 V_192 ;
T_1 V_11 ;
int V_28 ;
struct V_8 V_8 ;
V_11 = F_30 ( V_2 , V_23 , V_262 , V_126 ) ;
if ( V_11 )
goto V_12;
V_8 . V_9 = V_23 -> V_30 -> V_10 . V_9 ;
V_8 . V_3 = V_23 -> V_29 ;
V_36 = V_8 . V_3 -> V_21 ;
V_11 = V_223 ;
if ( ! V_36 -> V_234 -> V_263 )
goto V_12;
F_135 ( & V_8 ) ;
V_192 = F_99 () ; F_100 ( V_199 ) ;
V_28 = V_36 -> V_234 -> V_263 ( V_8 . V_3 , ( char V_201 * ) V_88 , * V_261 ) ;
F_100 ( V_192 ) ;
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
F_136 ( struct V_1 * V_2 , struct V_22 * V_23 ,
char * V_226 , int V_227 ,
char * V_8 , int V_264 ,
struct V_22 * V_224 ,
struct V_44 * V_45 )
{
struct V_3 * V_3 , * V_265 ;
T_1 V_11 , V_266 ;
int V_28 ;
V_11 = V_35 ;
if ( ! V_227 || ! V_264 )
goto V_12;
V_11 = V_231 ;
if ( F_25 ( V_226 , V_227 ) )
goto V_12;
V_11 = F_30 ( V_2 , V_23 , V_33 , V_232 ) ;
if ( V_11 )
goto V_12;
V_28 = F_123 ( V_23 ) ;
if ( V_28 )
goto V_31;
F_26 ( V_23 ) ;
V_3 = V_23 -> V_29 ;
V_265 = F_27 ( V_226 , V_3 , V_227 ) ;
V_28 = F_7 ( V_265 ) ;
if ( F_6 ( V_265 ) )
goto V_31;
if ( F_137 ( V_8 [ V_264 ] != 0 ) ) {
char * V_267 = F_58 ( V_264 + 1 , V_91 ) ;
if ( V_267 == NULL )
V_28 = - V_92 ;
else {
strncpy ( V_267 , V_8 , V_264 ) ;
V_267 [ V_264 ] = 0 ;
V_28 = F_138 ( V_3 -> V_21 , V_265 , V_267 ) ;
F_59 ( V_267 ) ;
}
} else
V_28 = F_138 ( V_3 -> V_21 , V_265 , V_8 ) ;
V_11 = F_28 ( V_28 ) ;
if ( ! V_11 )
V_11 = F_28 ( F_36 ( V_23 ) ) ;
F_55 ( V_23 ) ;
F_133 ( V_23 ) ;
V_266 = F_32 ( V_224 , V_23 -> V_30 , V_265 , V_23 ) ;
F_15 ( V_265 ) ;
if ( V_11 == 0 ) V_11 = V_266 ;
V_12:
return V_11 ;
V_31:
V_11 = F_28 ( V_28 ) ;
goto V_12;
}
T_1
F_139 ( struct V_1 * V_2 , struct V_22 * V_268 ,
char * V_24 , int V_25 , struct V_22 * V_269 )
{
struct V_3 * V_270 , * V_265 , * V_271 ;
struct V_36 * V_230 ;
T_1 V_11 ;
int V_28 ;
V_11 = F_30 ( V_2 , V_268 , V_33 , V_232 ) ;
if ( V_11 )
goto V_12;
V_11 = F_30 ( V_2 , V_269 , 0 , V_126 ) ;
if ( V_11 )
goto V_12;
V_11 = V_272 ;
if ( F_44 ( V_269 -> V_29 -> V_21 -> V_37 ) )
goto V_12;
V_11 = V_135 ;
if ( ! V_25 )
goto V_12;
V_11 = V_231 ;
if ( F_25 ( V_24 , V_25 ) )
goto V_12;
V_28 = F_123 ( V_269 ) ;
if ( V_28 ) {
V_11 = F_28 ( V_28 ) ;
goto V_12;
}
F_124 ( V_268 , V_236 ) ;
V_270 = V_268 -> V_29 ;
V_230 = V_270 -> V_21 ;
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
V_28 = F_140 ( V_271 , V_230 , V_265 , NULL ) ;
if ( ! V_28 ) {
V_11 = F_28 ( F_36 ( V_268 ) ) ;
if ( ! V_11 )
V_11 = F_28 ( F_36 ( V_269 ) ) ;
} else {
if ( V_28 == - V_274 && V_2 -> V_217 == 2 )
V_11 = V_134 ;
else
V_11 = F_28 ( V_28 ) ;
}
V_273:
F_15 ( V_265 ) ;
V_275:
F_55 ( V_268 ) ;
F_133 ( V_269 ) ;
V_12:
return V_11 ;
V_31:
V_11 = F_28 ( V_28 ) ;
goto V_275;
}
T_1
F_141 ( struct V_1 * V_2 , struct V_22 * V_268 , char * V_226 , int V_227 ,
struct V_22 * V_269 , char * V_276 , int V_277 )
{
struct V_3 * V_278 , * V_279 , * V_280 , * V_281 , * V_282 ;
struct V_36 * V_283 , * V_284 ;
T_1 V_11 ;
int V_28 ;
V_11 = F_30 ( V_2 , V_268 , V_33 , V_285 ) ;
if ( V_11 )
goto V_12;
V_11 = F_30 ( V_2 , V_269 , V_33 , V_232 ) ;
if ( V_11 )
goto V_12;
V_278 = V_268 -> V_29 ;
V_283 = V_278 -> V_21 ;
V_279 = V_269 -> V_29 ;
V_284 = V_279 -> V_21 ;
V_11 = V_135 ;
if ( ! V_227 || F_25 ( V_226 , V_227 ) || ! V_277 || F_25 ( V_276 , V_277 ) )
goto V_12;
V_28 = F_123 ( V_268 ) ;
if ( V_28 ) {
V_11 = F_28 ( V_28 ) ;
goto V_12;
}
V_282 = F_142 ( V_279 , V_278 ) ;
V_268 -> V_237 = V_269 -> V_237 = 1 ;
F_143 ( V_268 ) ;
F_143 ( V_269 ) ;
V_280 = F_27 ( V_226 , V_278 , V_227 ) ;
V_28 = F_7 ( V_280 ) ;
if ( F_6 ( V_280 ) )
goto V_31;
V_28 = - V_13 ;
if ( ! V_280 -> V_21 )
goto V_286;
V_28 = - V_103 ;
if ( V_280 == V_282 )
goto V_286;
V_281 = F_27 ( V_276 , V_279 , V_277 ) ;
V_28 = F_7 ( V_281 ) ;
if ( F_6 ( V_281 ) )
goto V_286;
V_28 = - V_287 ;
if ( V_281 == V_282 )
goto V_288;
V_28 = - V_274 ;
if ( V_268 -> V_30 -> V_10 . V_9 != V_269 -> V_30 -> V_10 . V_9 )
goto V_288;
if ( V_268 -> V_30 -> V_10 . V_3 != V_269 -> V_30 -> V_10 . V_3 )
goto V_288;
V_28 = F_33 ( V_280 -> V_21 ) ;
if ( V_28 )
goto V_288;
if ( V_281 -> V_21 ) {
V_28 = F_33 ( V_281 -> V_21 ) ;
if ( V_28 )
goto V_288;
}
V_28 = F_144 ( V_283 , V_280 , V_284 , V_281 , NULL ) ;
if ( ! V_28 ) {
V_28 = F_36 ( V_269 ) ;
if ( ! V_28 )
V_28 = F_36 ( V_268 ) ;
}
V_288:
F_15 ( V_281 ) ;
V_286:
F_15 ( V_280 ) ;
V_31:
V_11 = F_28 ( V_28 ) ;
F_145 ( V_268 ) ;
F_145 ( V_269 ) ;
F_146 ( V_279 , V_278 ) ;
V_268 -> V_237 = V_269 -> V_237 = 0 ;
F_133 ( V_268 ) ;
V_12:
return V_11 ;
}
T_1
F_147 ( struct V_1 * V_2 , struct V_22 * V_23 , int type ,
char * V_226 , int V_227 )
{
struct V_3 * V_3 , * V_289 ;
struct V_36 * V_230 ;
T_1 V_11 ;
int V_28 ;
V_11 = V_134 ;
if ( ! V_227 || F_25 ( V_226 , V_227 ) )
goto V_12;
V_11 = F_30 ( V_2 , V_23 , V_33 , V_285 ) ;
if ( V_11 )
goto V_12;
V_28 = F_123 ( V_23 ) ;
if ( V_28 )
goto V_31;
F_124 ( V_23 , V_236 ) ;
V_3 = V_23 -> V_29 ;
V_230 = V_3 -> V_21 ;
V_289 = F_27 ( V_226 , V_3 , V_227 ) ;
V_28 = F_7 ( V_289 ) ;
if ( F_6 ( V_289 ) )
goto V_31;
if ( ! V_289 -> V_21 ) {
F_15 ( V_289 ) ;
V_11 = V_35 ;
goto V_12;
}
if ( ! type )
type = V_289 -> V_21 -> V_37 & V_290 ;
V_28 = F_33 ( V_289 -> V_21 ) ;
if ( V_28 )
goto V_291;
if ( type != V_33 )
V_28 = F_148 ( V_230 , V_289 , NULL ) ;
else
V_28 = F_149 ( V_230 , V_289 ) ;
if ( ! V_28 )
V_28 = F_36 ( V_23 ) ;
V_291:
F_15 ( V_289 ) ;
V_31:
V_11 = F_28 ( V_28 ) ;
V_12:
return V_11 ;
}
static int F_150 ( void * V_292 , const char * V_24 , int V_293 ,
T_9 V_187 , T_12 V_152 , unsigned int V_294 )
{
struct V_295 * V_88 = V_292 ;
struct V_296 * V_297 = ( void * ) ( V_88 -> V_298 + V_88 -> V_299 ) ;
unsigned int V_300 ;
V_300 = F_151 ( sizeof( struct V_296 ) + V_293 , sizeof( T_12 ) ) ;
if ( V_88 -> V_299 + V_300 > V_301 ) {
V_88 -> V_302 = 1 ;
return - V_103 ;
}
V_297 -> V_293 = V_293 ;
V_297 -> V_187 = V_187 ;
V_297 -> V_152 = V_152 ;
V_297 -> V_294 = V_294 ;
memcpy ( V_297 -> V_24 , V_24 , V_293 ) ;
V_88 -> V_299 += V_300 ;
return 0 ;
}
static T_1 F_152 ( struct V_140 * V_140 , T_13 V_303 ,
struct V_304 * V_305 , T_9 * V_306 )
{
struct V_296 * V_297 ;
int V_28 ;
int V_183 ;
T_9 V_187 ;
struct V_295 V_88 = {
. V_307 . V_308 = F_150 ,
. V_298 = ( void * ) F_153 (GFP_KERNEL)
} ;
if ( ! V_88 . V_298 )
return F_28 ( - V_92 ) ;
V_187 = * V_306 ;
while ( 1 ) {
struct V_36 * V_309 = F_105 ( V_140 ) ;
unsigned int V_300 ;
V_305 -> V_11 = V_310 ;
V_88 . V_299 = 0 ;
V_88 . V_302 = 0 ;
V_28 = F_154 ( V_140 , & V_88 . V_307 ) ;
if ( V_88 . V_302 )
V_28 = 0 ;
if ( V_28 < 0 )
break;
V_183 = V_88 . V_299 ;
if ( ! V_183 )
break;
V_28 = F_155 ( & V_309 -> V_115 ) ;
if ( V_28 )
break;
V_297 = (struct V_296 * ) V_88 . V_298 ;
while ( V_183 > 0 ) {
V_187 = V_297 -> V_187 ;
if ( V_303 ( V_305 , V_297 -> V_24 , V_297 -> V_293 , V_297 -> V_187 ,
V_297 -> V_152 , V_297 -> V_294 ) )
break;
if ( V_305 -> V_11 != V_132 )
break;
V_300 = F_151 ( sizeof( * V_297 ) + V_297 -> V_293 ,
sizeof( T_12 ) ) ;
V_183 -= V_300 ;
V_297 = (struct V_296 * ) ( ( char * ) V_297 + V_300 ) ;
}
F_76 ( & V_309 -> V_115 ) ;
if ( V_183 > 0 )
break;
V_187 = F_156 ( V_140 , 0 , V_311 ) ;
}
F_157 ( ( unsigned long ) ( V_88 . V_298 ) ) ;
if ( V_28 )
return F_28 ( V_28 ) ;
* V_306 = V_187 ;
return V_305 -> V_11 ;
}
T_1
F_158 ( struct V_1 * V_2 , struct V_22 * V_23 , T_9 * V_306 ,
struct V_304 * V_305 , T_13 V_303 )
{
T_1 V_11 ;
struct V_140 * V_140 ;
T_9 V_187 = * V_306 ;
int V_139 = V_144 ;
if ( V_2 -> V_217 > 2 )
V_139 |= V_146 ;
V_11 = F_79 ( V_2 , V_23 , V_33 , V_139 , & V_140 ) ;
if ( V_11 )
goto V_12;
V_187 = F_156 ( V_140 , V_187 , V_312 ) ;
if ( V_187 < 0 ) {
V_11 = F_28 ( ( int ) V_187 ) ;
goto V_313;
}
V_11 = F_152 ( V_140 , V_303 , V_305 , V_306 ) ;
if ( V_11 == V_310 || V_11 == V_314 )
V_11 = V_132 ;
V_313:
F_86 ( V_140 ) ;
V_12:
return V_11 ;
}
T_1
F_159 ( struct V_1 * V_2 , struct V_22 * V_23 , struct V_315 * V_316 , int V_118 )
{
T_1 V_11 ;
V_11 = F_30 ( V_2 , V_23 , 0 , V_126 | V_118 ) ;
if ( ! V_11 ) {
struct V_8 V_8 = {
. V_9 = V_23 -> V_30 -> V_10 . V_9 ,
. V_3 = V_23 -> V_29 ,
} ;
if ( F_160 ( & V_8 , V_316 ) )
V_11 = V_239 ;
}
return V_11 ;
}
static int F_161 ( struct V_1 * V_2 , struct V_5 * exp )
{
return F_162 ( V_2 , exp ) & V_317 ;
}
T_1
F_48 ( struct V_1 * V_2 , struct V_5 * exp ,
struct V_3 * V_3 , int V_318 )
{
struct V_36 * V_36 = V_3 -> V_21 ;
int V_11 ;
if ( ( V_318 & V_319 ) == V_126 )
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
if ( ! ( V_318 & V_320 ) )
if ( V_318 & ( V_81 | V_75 | V_68 ) ) {
if ( F_161 ( V_2 , exp ) ||
F_163 ( exp -> V_10 . V_9 ) )
return V_133 ;
if ( F_164 ( V_36 ) )
return V_135 ;
}
if ( ( V_318 & V_68 ) && F_81 ( V_36 ) )
return V_135 ;
if ( V_318 & V_321 ) {
if ( exp -> V_14 & V_322 )
return 0 ;
else
V_318 = V_144 | V_69 ;
}
if ( ( V_318 & V_69 ) &&
F_45 ( V_36 -> V_56 , F_120 () ) )
return 0 ;
V_11 = F_165 ( V_36 , V_318 & ( V_323 | V_324 | V_325 ) ) ;
if ( V_11 == - V_326 && F_34 ( V_36 -> V_37 ) &&
( V_318 == ( V_144 | V_69 ) ||
V_318 == ( V_144 | V_327 ) ) )
V_11 = F_165 ( V_36 , V_325 ) ;
return V_11 ? F_28 ( V_11 ) : 0 ;
}
void
F_166 ( void )
{
struct V_150 * V_328 , * V_329 ;
unsigned int V_330 ;
F_22 ( L_9 ) ;
for ( V_330 = 0 ; V_330 < V_331 ; V_330 ++ ) {
V_328 = V_161 [ V_330 ] . V_163 ;
while( V_328 ) {
V_329 = V_328 ;
V_328 = V_328 -> V_164 ;
F_59 ( V_329 ) ;
}
V_161 [ V_330 ] . V_163 = NULL ;
}
}
int
F_167 ( int V_332 )
{
int V_330 ;
int V_333 = 0 ;
int V_334 ;
struct V_150 * * V_328 = NULL ;
if ( V_161 [ 0 ] . V_163 )
return 0 ;
V_334 = F_168 ( V_332 , V_331 ) ;
if ( V_334 < 2 )
V_334 = 2 ;
V_332 = V_334 * V_331 ;
F_22 ( L_10 , V_332 ) ;
for ( V_330 = 0 ; V_330 < V_331 ; V_330 ++ ) {
F_169 ( & V_161 [ V_330 ] . V_162 ) ;
V_328 = & V_161 [ V_330 ] . V_163 ;
for ( V_333 = 0 ; V_333 < V_334 ; V_333 ++ ) {
* V_328 = F_170 ( sizeof( struct V_150 ) , V_91 ) ;
if ( ! * V_328 )
goto V_335;
V_328 = & ( * V_328 ) -> V_164 ;
}
* V_328 = NULL ;
}
V_169 . V_170 = V_332 ;
return 0 ;
V_335:
F_22 ( L_11 ) ;
F_166 () ;
return - V_92 ;
}
struct V_93 *
F_171 ( struct V_22 * V_23 , int type )
{
struct V_36 * V_36 = V_23 -> V_29 -> V_21 ;
char * V_24 ;
void * V_336 = NULL ;
T_4 V_183 ;
struct V_93 * V_98 ;
if ( ! F_172 ( V_36 ) )
return F_68 ( - V_108 ) ;
switch ( type ) {
case V_337 :
V_24 = V_105 ;
break;
case V_338 :
V_24 = V_107 ;
break;
default:
return F_68 ( - V_108 ) ;
}
V_183 = F_56 ( V_23 -> V_29 , V_24 , & V_336 ) ;
if ( V_183 < 0 )
return F_68 ( V_183 ) ;
V_98 = F_69 ( & V_96 , V_336 , V_183 ) ;
F_59 ( V_336 ) ;
return V_98 ;
}
int
F_173 ( struct V_22 * V_23 , int type , struct V_93 * V_98 )
{
struct V_36 * V_36 = V_23 -> V_29 -> V_21 ;
char * V_24 ;
void * V_336 = NULL ;
T_5 V_183 ;
int error ;
if ( ! F_172 ( V_36 ) ||
! V_36 -> V_234 -> V_339 || ! V_36 -> V_234 -> V_340 )
return - V_108 ;
switch( type ) {
case V_337 :
V_24 = V_105 ;
break;
case V_338 :
V_24 = V_107 ;
break;
default:
return - V_108 ;
}
if ( V_98 && V_98 -> V_95 ) {
V_183 = F_61 ( V_98 -> V_95 ) ;
V_336 = F_58 ( V_183 , V_91 ) ;
if ( ! V_336 )
return - V_92 ;
error = F_62 ( & V_96 , V_98 , V_336 , V_183 ) ;
if ( error < 0 )
goto V_341;
V_183 = error ;
} else
V_183 = 0 ;
error = F_123 ( V_23 ) ;
if ( error )
goto V_341;
if ( V_183 )
error = F_63 ( V_23 -> V_29 , V_24 , V_336 , V_183 , 0 ) ;
else {
if ( ! F_44 ( V_36 -> V_37 ) && type == V_338 )
error = 0 ;
else {
error = F_174 ( V_23 -> V_29 , V_24 ) ;
if ( error == - V_109 )
error = 0 ;
}
}
F_133 ( V_23 ) ;
V_341:
F_59 ( V_336 ) ;
return error ;
}

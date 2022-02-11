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
if ( ! ( exp -> V_14 & V_15 ) )
return 0 ;
return V_3 -> V_21 != NULL ;
}
T_1
F_20 ( struct V_1 * V_2 , struct V_22 * V_23 ,
const char * V_24 , unsigned int V_25 ,
struct V_5 * * V_26 , struct V_3 * * V_27 )
{
struct V_5 * exp ;
struct V_3 * V_19 ;
struct V_3 * V_3 ;
int V_28 ;
F_21 ( L_1 , F_22 ( V_23 ) , V_25 , V_24 ) ;
V_19 = V_23 -> V_29 ;
exp = V_23 -> V_30 ;
F_23 ( exp ) ;
if ( F_24 ( V_24 , V_25 ) ) {
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
F_25 ( V_23 ) ;
V_3 = F_26 ( V_24 , V_19 , V_25 ) ;
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
return F_27 ( V_28 ) ;
}
T_1
F_28 ( struct V_1 * V_2 , struct V_22 * V_23 , const char * V_24 ,
unsigned int V_25 , struct V_22 * V_32 )
{
struct V_5 * exp ;
struct V_3 * V_3 ;
T_1 V_11 ;
V_11 = F_29 ( V_2 , V_23 , V_33 , V_34 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_20 ( V_2 , V_23 , V_24 , V_25 , & exp , & V_3 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_30 ( exp , V_2 ) ;
if ( V_11 )
goto V_12;
V_11 = F_31 ( V_32 , exp , V_3 , V_23 ) ;
if ( ! V_11 && ! V_3 -> V_21 )
V_11 = V_35 ;
V_12:
F_15 ( V_3 ) ;
F_11 ( exp ) ;
return V_11 ;
}
static int F_32 ( struct V_36 * V_36 )
{
if ( ! F_33 ( V_36 -> V_37 ) )
return 0 ;
return F_34 ( V_36 , V_38 | V_39 ) ;
}
static int
F_35 ( struct V_22 * V_23 )
{
struct V_36 * V_36 = V_23 -> V_29 -> V_21 ;
const struct V_40 * V_41 = V_36 -> V_42 -> V_43 ;
if ( ! F_36 ( V_23 -> V_30 ) )
return 0 ;
if ( V_41 -> F_35 )
return V_41 -> F_35 ( V_36 ) ;
return F_37 ( V_36 , 1 ) ;
}
T_1
F_38 ( struct V_1 * V_2 , struct V_22 * V_23 , struct V_44 * V_45 ,
int V_46 , T_2 V_47 )
{
struct V_3 * V_3 ;
struct V_36 * V_36 ;
int V_48 = V_49 ;
int V_50 = 0 ;
T_1 V_11 ;
int V_28 ;
int V_51 = 0 ;
if ( V_45 -> V_52 & ( V_53 | V_54 | V_55 ) )
V_48 |= V_56 | V_57 ;
if ( V_45 -> V_52 & V_55 )
V_50 = V_58 ;
V_11 = F_29 ( V_2 , V_23 , V_50 , V_48 ) ;
if ( V_11 )
goto V_12;
V_3 = V_23 -> V_29 ;
V_36 = V_3 -> V_21 ;
if ( F_39 ( V_36 -> V_37 ) )
V_45 -> V_52 &= ~ V_59 ;
if ( ! V_45 -> V_52 )
goto V_12;
#define F_40 (ATTR_ATIME_SET | ATTR_MTIME_SET)
#define F_41 (30*60)
if ( ( V_45 -> V_52 & F_40 ) == F_40 &&
V_45 -> V_60 . V_61 == V_45 -> V_62 . V_61 ) {
T_2 V_63 = V_45 -> V_62 . V_61 - F_42 () ;
if ( V_63 < 0 )
V_63 = - V_63 ;
if ( V_63 < F_41 &&
F_43 ( V_36 , V_45 ) != 0 ) {
V_45 -> V_52 &= ~ F_40 ;
}
}
if ( V_45 -> V_52 & V_55 ) {
if ( V_45 -> V_64 < V_36 -> V_65 ) {
V_11 = F_44 ( V_2 , V_23 -> V_30 , V_3 ,
V_66 | V_57 ) ;
if ( V_11 )
goto V_12;
}
V_28 = F_45 ( V_36 ) ;
if ( V_28 )
goto V_31;
V_51 = 1 ;
V_28 = F_46 ( V_36 , NULL , V_45 -> V_64 ) ;
if ( V_28 ) {
F_47 ( V_36 ) ;
goto V_31;
}
}
if ( V_45 -> V_52 & V_59 ) {
V_45 -> V_67 &= V_68 ;
V_45 -> V_67 |= ( V_36 -> V_37 & ~ V_68 ) ;
}
if ( ! F_48 ( V_36 -> V_37 ) &&
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
V_28 = F_32 ( V_36 ) ;
if ( V_28 )
goto V_31;
F_25 ( V_23 ) ;
V_28 = F_49 ( V_3 , V_45 ) ;
V_11 = F_27 ( V_28 ) ;
F_50 ( V_23 ) ;
}
if ( V_51 )
F_47 ( V_36 ) ;
if ( ! V_11 )
F_35 ( V_23 ) ;
V_12:
return V_11 ;
V_31:
V_11 = F_27 ( V_28 ) ;
goto V_12;
}
static T_3 F_51 ( struct V_3 * V_3 , char * V_84 , void * * V_85 )
{
T_3 V_86 ;
T_3 V_87 ;
V_86 = F_52 ( V_3 , V_84 , NULL , 0 ) ;
if ( V_86 <= 0 )
return V_86 ;
* V_85 = F_53 ( V_86 , V_88 ) ;
if ( ! * V_85 )
return - V_89 ;
V_87 = F_52 ( V_3 , V_84 , * V_85 , V_86 ) ;
if ( V_87 < 0 )
F_54 ( * V_85 ) ;
return V_87 ;
}
static int
F_55 ( struct V_3 * V_3 , struct V_90 * V_91 , char * V_84 )
{
int V_25 ;
T_4 V_86 ;
char * V_85 = NULL ;
int error = 0 ;
V_86 = F_56 ( V_91 -> V_92 ) ;
V_85 = F_53 ( V_86 , V_88 ) ;
error = - V_89 ;
if ( V_85 == NULL )
goto V_12;
V_25 = F_57 ( V_91 , V_85 , V_86 ) ;
if ( V_25 < 0 ) {
error = V_25 ;
goto V_12;
}
error = F_58 ( V_3 , V_84 , V_85 , V_25 , 0 ) ;
V_12:
F_54 ( V_85 ) ;
return error ;
}
T_1
F_59 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_93 * V_94 )
{
T_1 error ;
int V_95 ;
struct V_3 * V_3 ;
struct V_36 * V_36 ;
struct V_90 * V_91 = NULL , * V_96 = NULL ;
unsigned int V_97 = 0 ;
error = F_29 ( V_2 , V_23 , 0 , V_49 ) ;
if ( error )
return error ;
V_3 = V_23 -> V_29 ;
V_36 = V_3 -> V_21 ;
if ( F_48 ( V_36 -> V_37 ) )
V_97 = V_98 ;
V_95 = F_60 ( V_94 , & V_91 , & V_96 , V_97 ) ;
if ( V_95 == - V_99 ) {
return V_100 ;
} else if ( V_95 < 0 )
goto V_31;
V_95 = F_55 ( V_3 , V_91 , V_101 ) ;
if ( V_95 < 0 )
goto V_102;
if ( F_48 ( V_36 -> V_37 ) )
V_95 = F_55 ( V_3 , V_96 , V_103 ) ;
V_102:
F_61 ( V_91 ) ;
F_61 ( V_96 ) ;
V_31:
if ( V_95 == - V_104 )
return V_100 ;
else
return F_27 ( V_95 ) ;
}
static struct V_90 *
F_62 ( struct V_3 * V_3 , char * V_84 )
{
void * V_85 = NULL ;
struct V_90 * V_91 = NULL ;
int V_86 ;
V_86 = F_51 ( V_3 , V_84 , & V_85 ) ;
if ( ! V_86 )
V_86 = - V_105 ;
if ( V_86 <= 0 )
return F_63 ( V_86 ) ;
V_91 = F_64 ( V_85 , V_86 ) ;
F_54 ( V_85 ) ;
return V_91 ;
}
int
F_65 ( struct V_1 * V_2 , struct V_3 * V_3 , struct V_93 * * V_94 )
{
struct V_36 * V_36 = V_3 -> V_21 ;
int error = 0 ;
struct V_90 * V_91 = NULL , * V_96 = NULL ;
unsigned int V_97 = 0 ;
V_91 = F_62 ( V_3 , V_101 ) ;
if ( F_6 ( V_91 ) && F_7 ( V_91 ) == - V_105 )
V_91 = F_66 ( V_36 -> V_37 , V_88 ) ;
if ( F_6 ( V_91 ) ) {
error = F_7 ( V_91 ) ;
V_91 = NULL ;
goto V_12;
}
if ( F_48 ( V_36 -> V_37 ) ) {
V_96 = F_62 ( V_3 , V_103 ) ;
if ( F_6 ( V_96 ) && F_7 ( V_96 ) == - V_105 )
V_96 = NULL ;
else if ( F_6 ( V_96 ) ) {
error = F_7 ( V_96 ) ;
V_96 = NULL ;
goto V_12;
}
V_97 = V_98 ;
}
* V_94 = F_67 ( V_91 , V_96 , V_97 ) ;
if ( F_6 ( * V_94 ) ) {
error = F_7 ( * V_94 ) ;
* V_94 = NULL ;
}
V_12:
F_61 ( V_91 ) ;
F_61 ( V_96 ) ;
return error ;
}
T_1
F_68 ( struct V_1 * V_2 , struct V_22 * V_23 , T_5 * V_106 , T_5 * V_107 )
{
struct V_108 * V_109 ;
struct V_5 * V_110 ;
struct V_3 * V_3 ;
T_5 V_111 , V_112 = 0 , V_113 = 0 ;
T_1 error ;
error = F_29 ( V_2 , V_23 , 0 , V_114 ) ;
if ( error )
goto V_12;
V_110 = V_23 -> V_30 ;
V_3 = V_23 -> V_29 ;
if ( F_33 ( V_3 -> V_21 -> V_37 ) )
V_109 = V_115 ;
else if ( F_48 ( V_3 -> V_21 -> V_37 ) )
V_109 = V_116 ;
else
V_109 = V_117 ;
V_111 = * V_106 ;
for (; V_109 -> V_106 ; V_109 ++ ) {
if ( V_109 -> V_106 & V_111 ) {
T_1 V_118 ;
V_113 |= V_109 -> V_106 ;
V_118 = F_44 ( V_2 , V_110 , V_3 , V_109 -> V_119 ) ;
switch ( V_118 ) {
case V_120 :
V_112 |= V_109 -> V_106 ;
break;
case V_121 :
case V_122 :
case V_123 :
break;
default:
error = V_118 ;
goto V_12;
}
}
}
* V_106 = V_112 ;
if ( V_107 )
* V_107 = V_113 ;
V_12:
return error ;
}
static int F_69 ( struct V_36 * V_36 , int V_106 )
{
unsigned int V_124 ;
if ( V_106 & V_125 )
return 0 ;
V_124 = ( V_106 & V_56 ) ? V_38 : V_126 ;
return F_34 ( V_36 , V_124 | V_39 ) ;
}
T_1
F_70 ( struct V_1 * V_2 , struct V_22 * V_23 , int type ,
int V_106 , struct V_127 * * V_128 )
{
struct V_3 * V_3 ;
struct V_36 * V_36 ;
int V_97 = V_126 | V_129 ;
T_1 V_11 ;
int V_28 = 0 ;
F_71 () ;
V_11 = F_29 ( V_2 , V_23 , type , V_106 | V_57 ) ;
if ( V_11 )
goto V_12;
V_3 = V_23 -> V_29 ;
V_36 = V_3 -> V_21 ;
V_11 = V_123 ;
if ( F_72 ( V_36 ) && ( V_106 & V_56 ) )
goto V_12;
if ( F_33 ( ( V_36 ) -> V_37 ) && F_73 ( V_36 ) )
goto V_12;
if ( ! V_36 -> V_130 )
goto V_12;
V_28 = F_69 ( V_36 , V_106 ) ;
if ( V_28 )
goto V_31;
if ( V_106 & V_56 ) {
if ( V_106 & V_131 )
V_97 = V_132 | V_129 ;
else
V_97 = V_38 | V_129 ;
}
* V_128 = F_74 ( F_3 ( V_3 ) , F_2 ( V_23 -> V_30 -> V_10 . V_9 ) ,
V_97 , F_75 () ) ;
if ( F_6 ( * V_128 ) )
V_28 = F_7 ( * V_128 ) ;
else
V_28 = F_76 ( * V_128 , V_106 ) ;
V_31:
V_11 = F_27 ( V_28 ) ;
V_12:
F_71 () ;
return V_11 ;
}
void
F_77 ( struct V_127 * V_128 )
{
F_78 ( V_128 ) ;
}
static inline struct V_133 *
F_79 ( T_6 V_134 , T_7 V_135 )
{
struct V_133 * V_136 , * * V_137 , * * V_138 = NULL ;
int V_139 = 0 ;
unsigned int V_140 ;
struct V_141 * V_142 ;
V_140 = F_80 ( V_134 , V_135 , 0xfeedbeef ) & V_143 ;
V_142 = & V_144 [ V_140 ] ;
F_81 ( & V_142 -> V_145 ) ;
for ( V_137 = & V_142 -> V_146 ; ( V_136 = * V_137 ) ; V_137 = & V_136 -> V_147 ) {
if ( V_136 -> V_148 == V_135 && V_136 -> V_149 == V_134 )
goto V_150;
V_139 ++ ;
if ( V_136 -> V_151 == 0 )
V_138 = V_137 ;
}
V_139 = V_152 . V_153 ;
if ( ! V_138 ) {
F_82 ( & V_142 -> V_145 ) ;
return NULL ;
}
V_137 = V_138 ;
V_136 = * V_138 ;
V_136 -> V_149 = V_134 ;
V_136 -> V_148 = V_135 ;
V_136 -> V_154 = 0 ;
V_136 -> V_155 = V_140 ;
V_150:
if ( V_137 != & V_142 -> V_146 ) {
* V_137 = V_136 -> V_147 ;
V_136 -> V_147 = V_142 -> V_146 ;
V_142 -> V_146 = V_136 ;
}
V_136 -> V_151 ++ ;
V_152 . V_156 [ V_139 * 10 / V_152 . V_153 ] ++ ;
F_82 ( & V_142 -> V_145 ) ;
return V_136 ;
}
static int
F_83 ( struct V_157 * V_158 , struct V_159 * V_85 ,
struct V_160 * V_161 )
{
struct V_1 * V_2 = V_161 -> V_162 . V_163 ;
struct V_164 * * V_165 = V_2 -> V_166 + V_2 -> V_167 ;
struct V_164 * V_164 = V_85 -> V_164 ;
T_4 V_168 ;
V_168 = V_161 -> V_25 ;
if ( V_2 -> V_169 . V_170 == 0 ) {
F_84 ( V_164 ) ;
F_85 ( * V_165 ) ;
* V_165 = V_164 ;
V_2 -> V_167 ++ ;
V_2 -> V_169 . V_171 = V_85 -> V_172 ;
V_2 -> V_169 . V_170 = V_168 ;
} else if ( V_164 != V_165 [ - 1 ] ) {
F_84 ( V_164 ) ;
if ( * V_165 )
F_85 ( * V_165 ) ;
* V_165 = V_164 ;
V_2 -> V_167 ++ ;
V_2 -> V_169 . V_170 += V_168 ;
} else
V_2 -> V_169 . V_170 += V_168 ;
return V_168 ;
}
static int F_86 ( struct V_157 * V_158 ,
struct V_160 * V_161 )
{
return F_87 ( V_158 , V_161 , F_83 ) ;
}
static T_1
F_88 ( struct V_1 * V_2 , struct V_22 * V_23 , struct V_127 * V_127 ,
T_8 V_172 , struct V_173 * V_174 , int V_175 , unsigned long * V_176 )
{
T_9 V_177 ;
T_1 V_11 ;
int V_28 ;
V_11 = V_123 ;
if ( V_127 -> V_178 -> V_179 && V_2 -> V_180 ) {
struct V_160 V_161 = {
. V_25 = 0 ,
. V_181 = * V_176 ,
. V_182 = V_172 ,
. V_162 . V_163 = V_2 ,
} ;
V_2 -> V_167 = 1 ;
V_28 = F_89 ( V_127 , & V_161 , F_86 ) ;
} else {
V_177 = F_90 () ;
F_91 ( V_183 ) ;
V_28 = F_92 ( V_127 , (struct V_184 V_185 * ) V_174 , V_175 , & V_172 ) ;
F_91 ( V_177 ) ;
}
if ( V_28 >= 0 ) {
V_152 . V_186 += V_28 ;
* V_176 = V_28 ;
V_11 = 0 ;
F_93 ( V_127 ) ;
} else
V_11 = F_27 ( V_28 ) ;
return V_11 ;
}
static void F_94 ( struct V_3 * V_3 )
{
struct V_44 V_187 ;
V_187 . V_52 = V_79 | V_80 | V_75 ;
F_95 ( & V_3 -> V_21 -> V_188 ) ;
F_49 ( V_3 , & V_187 ) ;
F_96 ( & V_3 -> V_21 -> V_188 ) ;
}
static int F_97 ( struct V_127 * V_127 )
{
struct V_36 * V_36 = V_127 -> V_189 . V_3 -> V_21 ;
static T_7 V_190 ;
static T_6 V_191 ;
int V_11 = 0 ;
if ( F_98 ( & V_36 -> V_192 ) > 1
|| ( V_190 == V_36 -> V_193 && V_191 == V_36 -> V_42 -> V_194 ) ) {
F_21 ( L_2 , F_99 ( V_195 ) ) ;
F_100 ( 10 ) ;
F_21 ( L_3 , F_99 ( V_195 ) ) ;
}
if ( V_36 -> V_196 & V_197 ) {
F_21 ( L_4 , F_99 ( V_195 ) ) ;
V_11 = F_101 ( V_127 , 0 ) ;
}
V_190 = V_36 -> V_193 ;
V_191 = V_36 -> V_42 -> V_194 ;
return V_11 ;
}
static T_1
F_102 ( struct V_1 * V_2 , struct V_22 * V_23 , struct V_127 * V_127 ,
T_8 V_172 , struct V_173 * V_174 , int V_175 ,
unsigned long * V_198 , int * V_199 )
{
struct V_5 * exp ;
struct V_3 * V_3 ;
struct V_36 * V_36 ;
T_9 V_177 ;
T_1 V_11 = 0 ;
int V_28 ;
int V_200 = * V_199 ;
int V_201 ;
V_3 = V_127 -> V_189 . V_3 ;
V_36 = V_3 -> V_21 ;
exp = V_23 -> V_30 ;
V_201 = ( V_2 -> V_202 == 2 ) && F_103 ( exp ) ;
if ( ! V_127 -> V_178 -> V_203 ) {
V_200 = 2 ;
* V_199 = 2 ;
}
if ( ! F_36 ( exp ) )
V_200 = 0 ;
if ( V_200 && ! V_201 ) {
F_81 ( & V_127 -> V_204 ) ;
V_127 -> V_205 |= V_206 ;
F_82 ( & V_127 -> V_204 ) ;
}
V_177 = F_90 () ; F_91 ( V_183 ) ;
V_28 = F_104 ( V_127 , (struct V_184 V_185 * ) V_174 , V_175 , & V_172 ) ;
F_91 ( V_177 ) ;
if ( V_28 < 0 )
goto V_31;
* V_198 = V_28 ;
V_152 . V_207 += V_28 ;
F_105 ( V_127 ) ;
if ( V_36 -> V_37 & ( V_76 | V_78 ) )
F_94 ( V_3 ) ;
if ( V_200 && V_201 )
V_28 = F_97 ( V_127 ) ;
V_31:
F_21 ( L_5 , V_28 ) ;
if ( V_28 >= 0 )
V_11 = 0 ;
else
V_11 = F_27 ( V_28 ) ;
return V_11 ;
}
T_1 F_106 ( struct V_1 * V_2 , struct V_22 * V_23 ,
T_8 V_172 , struct V_173 * V_174 , int V_175 , unsigned long * V_176 )
{
struct V_127 * V_127 ;
struct V_36 * V_36 ;
struct V_133 * V_136 ;
T_1 V_11 ;
V_11 = F_70 ( V_2 , V_23 , V_58 , V_131 , & V_127 ) ;
if ( V_11 )
return V_11 ;
V_36 = V_127 -> V_189 . V_3 -> V_21 ;
V_136 = F_79 ( V_36 -> V_42 -> V_194 , V_36 -> V_193 ) ;
if ( V_136 && V_136 -> V_154 )
V_127 -> V_208 = V_136 -> V_209 ;
V_11 = F_88 ( V_2 , V_23 , V_127 , V_172 , V_174 , V_175 , V_176 ) ;
if ( V_136 ) {
struct V_141 * V_142 = & V_144 [ V_136 -> V_155 ] ;
F_81 ( & V_142 -> V_145 ) ;
V_136 -> V_209 = V_127 -> V_208 ;
V_136 -> V_154 = 1 ;
V_136 -> V_151 -- ;
F_82 ( & V_142 -> V_145 ) ;
}
F_77 ( V_127 ) ;
return V_11 ;
}
T_1
F_107 ( struct V_1 * V_2 , struct V_22 * V_23 , struct V_127 * V_127 ,
T_8 V_172 , struct V_173 * V_174 , int V_175 ,
unsigned long * V_176 )
{
T_1 V_11 ;
if ( V_127 ) {
V_11 = F_44 ( V_2 , V_23 -> V_30 , V_23 -> V_29 ,
V_131 | V_57 ) ;
if ( V_11 )
goto V_12;
V_11 = F_88 ( V_2 , V_23 , V_127 , V_172 , V_174 , V_175 , V_176 ) ;
} else
V_11 = F_106 ( V_2 , V_23 , V_172 , V_174 , V_175 , V_176 ) ;
V_12:
return V_11 ;
}
T_1
F_108 ( struct V_1 * V_2 , struct V_22 * V_23 , struct V_127 * V_127 ,
T_8 V_172 , struct V_173 * V_174 , int V_175 , unsigned long * V_198 ,
int * V_199 )
{
T_1 V_11 = 0 ;
if ( V_127 ) {
V_11 = F_44 ( V_2 , V_23 -> V_30 , V_23 -> V_29 ,
V_56 | V_57 ) ;
if ( V_11 )
goto V_12;
V_11 = F_102 ( V_2 , V_23 , V_127 , V_172 , V_174 , V_175 , V_198 ,
V_199 ) ;
} else {
V_11 = F_70 ( V_2 , V_23 , V_58 , V_56 , & V_127 ) ;
if ( V_11 )
goto V_12;
if ( V_198 )
V_11 = F_102 ( V_2 , V_23 , V_127 , V_172 , V_174 , V_175 ,
V_198 , V_199 ) ;
F_77 ( V_127 ) ;
}
V_12:
return V_11 ;
}
T_1
F_109 ( struct V_1 * V_2 , struct V_22 * V_23 ,
T_8 V_172 , unsigned long V_176 )
{
struct V_127 * V_127 ;
T_8 V_210 = V_211 ;
T_1 V_11 = V_212 ;
if ( V_172 < 0 )
goto V_12;
if ( V_176 != 0 ) {
V_210 = V_172 + ( T_8 ) V_176 - 1 ;
if ( V_210 < V_172 )
goto V_12;
}
V_11 = F_70 ( V_2 , V_23 , V_58 ,
V_56 | V_125 , & V_127 ) ;
if ( V_11 )
goto V_12;
if ( F_36 ( V_23 -> V_30 ) ) {
int V_118 = F_110 ( V_127 , V_172 , V_210 , 0 ) ;
if ( V_118 != - V_99 )
V_11 = F_27 ( V_118 ) ;
else
V_11 = V_213 ;
}
F_77 ( V_127 ) ;
V_12:
return V_11 ;
}
static T_1
F_111 ( struct V_1 * V_2 , struct V_22 * V_214 ,
struct V_44 * V_45 )
{
V_45 -> V_52 &= ~ V_59 ;
if ( F_112 () != 0 )
V_45 -> V_52 &= ~ ( V_69 | V_72 ) ;
if ( V_45 -> V_52 )
return F_38 ( V_2 , V_214 , V_45 , 0 , ( T_2 ) 0 ) ;
return 0 ;
}
static void
F_113 ( struct V_44 * V_45 )
{
if ( ( V_45 -> V_52 & V_55 ) && ( V_45 -> V_64 == 0 ) )
V_45 -> V_52 &= ~ V_55 ;
}
T_1
F_114 ( struct V_1 * V_2 , struct V_22 * V_23 ,
char * V_215 , int V_216 , struct V_44 * V_45 ,
int type , T_6 V_217 , struct V_22 * V_214 )
{
struct V_3 * V_3 , * V_218 = NULL ;
struct V_36 * V_219 ;
T_1 V_11 ;
T_1 V_118 ;
int V_28 ;
V_11 = V_123 ;
if ( ! V_216 )
goto V_12;
V_11 = V_220 ;
if ( F_24 ( V_215 , V_216 ) )
goto V_12;
V_11 = F_29 ( V_2 , V_23 , V_33 , V_221 ) ;
if ( V_11 )
goto V_12;
V_3 = V_23 -> V_29 ;
V_219 = V_3 -> V_21 ;
V_11 = V_222 ;
if ( ! V_219 -> V_223 -> V_224 )
goto V_12;
if ( ! V_214 -> V_29 ) {
F_115 ( V_23 , V_225 ) ;
V_218 = F_26 ( V_215 , V_3 , V_216 ) ;
V_28 = F_7 ( V_218 ) ;
if ( F_6 ( V_218 ) )
goto V_31;
V_11 = F_31 ( V_214 , V_23 -> V_30 , V_218 , V_23 ) ;
if ( V_11 )
goto V_12;
} else {
V_218 = F_3 ( V_214 -> V_29 ) ;
if ( ! V_23 -> V_226 ) {
F_116 ( V_227
L_6 ,
V_3 -> V_228 -> V_229 . V_24 ,
V_3 -> V_229 . V_24 ) ;
V_11 = V_230 ;
goto V_12;
}
}
V_11 = V_220 ;
if ( V_218 -> V_21 ) {
F_21 ( L_7 ,
V_3 -> V_229 . V_24 , V_218 -> V_229 . V_24 ) ;
goto V_12;
}
if ( ! ( V_45 -> V_52 & V_59 ) )
V_45 -> V_67 = 0 ;
V_45 -> V_67 = ( V_45 -> V_67 & V_68 ) | type ;
V_11 = V_212 ;
if ( ! F_33 ( type ) && ! F_48 ( type ) && ! F_117 ( type ) ) {
F_116 ( V_231 L_8 ,
type ) ;
goto V_12;
}
V_28 = F_118 ( V_23 -> V_30 -> V_10 . V_9 ) ;
if ( V_28 )
goto V_31;
V_11 = 0 ;
switch ( type ) {
case V_58 :
V_28 = F_119 ( V_219 , V_218 , V_45 -> V_67 , NULL ) ;
if ( ! V_28 )
F_113 ( V_45 ) ;
break;
case V_33 :
V_28 = F_120 ( V_219 , V_218 , V_45 -> V_67 ) ;
break;
case V_232 :
case V_233 :
case V_234 :
case V_235 :
V_28 = F_121 ( V_219 , V_218 , V_45 -> V_67 , V_217 ) ;
break;
}
if ( V_28 < 0 ) {
F_122 ( V_23 -> V_30 -> V_10 . V_9 ) ;
goto V_31;
}
V_11 = F_111 ( V_2 , V_214 , V_45 ) ;
V_118 = F_27 ( F_35 ( V_23 ) ) ;
if ( V_118 )
V_11 = V_118 ;
F_122 ( V_23 -> V_30 -> V_10 . V_9 ) ;
if ( ! V_11 )
V_11 = F_123 ( V_214 ) ;
V_12:
if ( V_218 && ! F_6 ( V_218 ) )
F_15 ( V_218 ) ;
return V_11 ;
V_31:
V_11 = F_27 ( V_28 ) ;
goto V_12;
}
static inline int F_124 ( int V_236 )
{
return V_236 == V_237
|| V_236 == V_238 ;
}
T_1
F_125 ( struct V_1 * V_2 , struct V_22 * V_23 ,
char * V_215 , int V_216 , struct V_44 * V_45 ,
struct V_22 * V_214 , int V_236 , T_5 * V_239 ,
int * V_240 , int * V_241 )
{
struct V_3 * V_3 , * V_218 = NULL ;
struct V_36 * V_219 ;
T_1 V_11 ;
int V_28 ;
T_10 V_242 = 0 , V_243 = 0 ;
V_11 = V_123 ;
if ( ! V_216 )
goto V_12;
V_11 = V_220 ;
if ( F_24 ( V_215 , V_216 ) )
goto V_12;
if ( ! ( V_45 -> V_52 & V_59 ) )
V_45 -> V_67 = 0 ;
V_11 = F_29 ( V_2 , V_23 , V_33 , V_34 ) ;
if ( V_11 )
goto V_12;
V_3 = V_23 -> V_29 ;
V_219 = V_3 -> V_21 ;
V_11 = V_222 ;
if ( ! V_219 -> V_223 -> V_224 )
goto V_12;
F_115 ( V_23 , V_225 ) ;
V_218 = F_26 ( V_215 , V_3 , V_216 ) ;
V_28 = F_7 ( V_218 ) ;
if ( F_6 ( V_218 ) )
goto V_31;
if ( ! V_218 -> V_21 ) {
V_11 = F_29 ( V_2 , V_23 , V_33 , V_221 ) ;
if ( V_11 )
goto V_12;
}
V_11 = F_31 ( V_214 , V_23 -> V_30 , V_218 , V_23 ) ;
if ( V_11 )
goto V_12;
if ( F_124 ( V_236 ) ) {
V_242 = V_239 [ 0 ] & 0x7fffffff ;
V_243 = V_239 [ 1 ] & 0x7fffffff ;
}
V_28 = F_118 ( V_23 -> V_30 -> V_10 . V_9 ) ;
if ( V_28 )
goto V_31;
if ( V_218 -> V_21 ) {
V_11 = 0 ;
switch ( V_236 ) {
case V_244 :
if ( ! F_33 ( V_218 -> V_21 -> V_37 ) )
V_11 = V_220 ;
else if ( V_240 ) {
* V_240 = ( V_45 -> V_52 & V_55 ) && ! V_45 -> V_64 ;
}
else {
V_45 -> V_52 &= V_55 ;
goto V_245;
}
break;
case V_237 :
if ( V_218 -> V_21 -> V_246 . V_61 == V_242
&& V_218 -> V_21 -> V_247 . V_61 == V_243
&& V_218 -> V_21 -> V_65 == 0 )
break;
case V_238 :
if ( V_218 -> V_21 -> V_246 . V_61 == V_242
&& V_218 -> V_21 -> V_247 . V_61 == V_243
&& V_218 -> V_21 -> V_65 == 0 )
goto V_245;
case V_248 :
V_11 = V_220 ;
}
F_122 ( V_23 -> V_30 -> V_10 . V_9 ) ;
goto V_12;
}
V_28 = F_119 ( V_219 , V_218 , V_45 -> V_67 , NULL ) ;
if ( V_28 < 0 ) {
F_122 ( V_23 -> V_30 -> V_10 . V_9 ) ;
goto V_31;
}
if ( V_241 )
* V_241 = 1 ;
F_113 ( V_45 ) ;
if ( F_124 ( V_236 ) ) {
V_45 -> V_52 = V_54 | V_53
| V_249 | V_250 ;
V_45 -> V_60 . V_61 = V_242 ;
V_45 -> V_62 . V_61 = V_243 ;
V_45 -> V_60 . V_251 = 0 ;
V_45 -> V_62 . V_251 = 0 ;
}
V_245:
V_11 = F_111 ( V_2 , V_214 , V_45 ) ;
if ( ! V_11 )
V_11 = F_27 ( F_35 ( V_23 ) ) ;
F_122 ( V_23 -> V_30 -> V_10 . V_9 ) ;
if ( ! V_11 )
V_11 = F_123 ( V_214 ) ;
V_12:
F_50 ( V_23 ) ;
if ( V_218 && ! F_6 ( V_218 ) )
F_15 ( V_218 ) ;
return V_11 ;
V_31:
V_11 = F_27 ( V_28 ) ;
goto V_12;
}
T_1
F_126 ( struct V_1 * V_2 , struct V_22 * V_23 , char * V_85 , int * V_252 )
{
struct V_3 * V_3 ;
struct V_36 * V_36 ;
T_9 V_177 ;
T_1 V_11 ;
int V_28 ;
V_11 = F_29 ( V_2 , V_23 , V_253 , V_114 ) ;
if ( V_11 )
goto V_12;
V_3 = V_23 -> V_29 ;
V_36 = V_3 -> V_21 ;
V_11 = V_212 ;
if ( ! V_36 -> V_223 -> V_254 )
goto V_12;
F_127 ( V_23 -> V_30 -> V_10 . V_9 , V_3 ) ;
V_177 = F_90 () ; F_91 ( V_183 ) ;
V_28 = V_36 -> V_223 -> V_254 ( V_3 , V_85 , * V_252 ) ;
F_91 ( V_177 ) ;
if ( V_28 < 0 )
goto V_31;
* V_252 = V_28 ;
V_11 = 0 ;
V_12:
return V_11 ;
V_31:
V_11 = F_27 ( V_28 ) ;
goto V_12;
}
T_1
F_128 ( struct V_1 * V_2 , struct V_22 * V_23 ,
char * V_215 , int V_216 ,
char * V_8 , int V_255 ,
struct V_22 * V_214 ,
struct V_44 * V_45 )
{
struct V_3 * V_3 , * V_256 ;
T_1 V_11 , V_257 ;
int V_28 ;
V_11 = V_35 ;
if ( ! V_216 || ! V_255 )
goto V_12;
V_11 = V_220 ;
if ( F_24 ( V_215 , V_216 ) )
goto V_12;
V_11 = F_29 ( V_2 , V_23 , V_33 , V_221 ) ;
if ( V_11 )
goto V_12;
F_25 ( V_23 ) ;
V_3 = V_23 -> V_29 ;
V_256 = F_26 ( V_215 , V_3 , V_216 ) ;
V_28 = F_7 ( V_256 ) ;
if ( F_6 ( V_256 ) )
goto V_31;
V_28 = F_118 ( V_23 -> V_30 -> V_10 . V_9 ) ;
if ( V_28 )
goto V_31;
if ( F_129 ( V_8 [ V_255 ] != 0 ) ) {
char * V_258 = F_53 ( V_255 + 1 , V_88 ) ;
if ( V_258 == NULL )
V_28 = - V_89 ;
else {
strncpy ( V_258 , V_8 , V_255 ) ;
V_258 [ V_255 ] = 0 ;
V_28 = F_130 ( V_3 -> V_21 , V_256 , V_258 ) ;
F_54 ( V_258 ) ;
}
} else
V_28 = F_130 ( V_3 -> V_21 , V_256 , V_8 ) ;
V_11 = F_27 ( V_28 ) ;
if ( ! V_11 )
V_11 = F_27 ( F_35 ( V_23 ) ) ;
F_50 ( V_23 ) ;
F_122 ( V_23 -> V_30 -> V_10 . V_9 ) ;
V_257 = F_31 ( V_214 , V_23 -> V_30 , V_256 , V_23 ) ;
F_15 ( V_256 ) ;
if ( V_11 == 0 ) V_11 = V_257 ;
V_12:
return V_11 ;
V_31:
V_11 = F_27 ( V_28 ) ;
goto V_12;
}
T_1
F_131 ( struct V_1 * V_2 , struct V_22 * V_259 ,
char * V_24 , int V_25 , struct V_22 * V_260 )
{
struct V_3 * V_261 , * V_256 , * V_262 ;
struct V_36 * V_219 ;
T_1 V_11 ;
int V_28 ;
V_11 = F_29 ( V_2 , V_259 , V_33 , V_221 ) ;
if ( V_11 )
goto V_12;
V_11 = F_29 ( V_2 , V_260 , - V_33 , V_114 ) ;
if ( V_11 )
goto V_12;
V_11 = V_123 ;
if ( ! V_25 )
goto V_12;
V_11 = V_220 ;
if ( F_24 ( V_24 , V_25 ) )
goto V_12;
F_115 ( V_259 , V_225 ) ;
V_261 = V_259 -> V_29 ;
V_219 = V_261 -> V_21 ;
V_256 = F_26 ( V_24 , V_261 , V_25 ) ;
V_28 = F_7 ( V_256 ) ;
if ( F_6 ( V_256 ) )
goto V_31;
V_262 = V_260 -> V_29 ;
V_28 = F_118 ( V_260 -> V_30 -> V_10 . V_9 ) ;
if ( V_28 ) {
V_11 = F_27 ( V_28 ) ;
goto V_263;
}
V_11 = V_35 ;
if ( ! V_262 -> V_21 )
goto V_264;
V_28 = F_32 ( V_262 -> V_21 ) ;
if ( V_28 ) {
V_11 = F_27 ( V_28 ) ;
goto V_264;
}
V_28 = F_132 ( V_262 , V_219 , V_256 ) ;
if ( ! V_28 ) {
V_11 = F_27 ( F_35 ( V_259 ) ) ;
if ( ! V_11 )
V_11 = F_27 ( F_35 ( V_260 ) ) ;
} else {
if ( V_28 == - V_265 && V_2 -> V_202 == 2 )
V_11 = V_122 ;
else
V_11 = F_27 ( V_28 ) ;
}
V_264:
F_122 ( V_260 -> V_30 -> V_10 . V_9 ) ;
V_263:
F_15 ( V_256 ) ;
V_266:
F_50 ( V_259 ) ;
V_12:
return V_11 ;
V_31:
V_11 = F_27 ( V_28 ) ;
goto V_266;
}
T_1
F_133 ( struct V_1 * V_2 , struct V_22 * V_259 , char * V_215 , int V_216 ,
struct V_22 * V_260 , char * V_267 , int V_268 )
{
struct V_3 * V_269 , * V_270 , * V_271 , * V_272 , * V_273 ;
struct V_36 * V_274 , * V_275 ;
T_1 V_11 ;
int V_28 ;
V_11 = F_29 ( V_2 , V_259 , V_33 , V_276 ) ;
if ( V_11 )
goto V_12;
V_11 = F_29 ( V_2 , V_260 , V_33 , V_221 ) ;
if ( V_11 )
goto V_12;
V_269 = V_259 -> V_29 ;
V_274 = V_269 -> V_21 ;
V_270 = V_260 -> V_29 ;
V_275 = V_270 -> V_21 ;
V_11 = ( V_2 -> V_202 == 2 ) ? V_122 : V_277 ;
if ( V_259 -> V_30 != V_260 -> V_30 )
goto V_12;
V_11 = V_123 ;
if ( ! V_216 || F_24 ( V_215 , V_216 ) || ! V_268 || F_24 ( V_267 , V_268 ) )
goto V_12;
V_273 = F_134 ( V_270 , V_269 ) ;
V_259 -> V_226 = V_260 -> V_226 = 1 ;
F_135 ( V_259 ) ;
F_135 ( V_260 ) ;
V_271 = F_26 ( V_215 , V_269 , V_216 ) ;
V_28 = F_7 ( V_271 ) ;
if ( F_6 ( V_271 ) )
goto V_31;
V_28 = - V_13 ;
if ( ! V_271 -> V_21 )
goto V_278;
V_28 = - V_99 ;
if ( V_271 == V_273 )
goto V_278;
V_272 = F_26 ( V_267 , V_270 , V_268 ) ;
V_28 = F_7 ( V_272 ) ;
if ( F_6 ( V_272 ) )
goto V_278;
V_28 = - V_279 ;
if ( V_272 == V_273 )
goto V_280;
V_28 = - V_265 ;
if ( V_259 -> V_30 -> V_10 . V_9 != V_260 -> V_30 -> V_10 . V_9 )
goto V_280;
V_28 = F_118 ( V_259 -> V_30 -> V_10 . V_9 ) ;
if ( V_28 )
goto V_280;
V_28 = F_32 ( V_271 -> V_21 ) ;
if ( V_28 )
goto V_264;
if ( V_272 -> V_21 ) {
V_28 = F_32 ( V_272 -> V_21 ) ;
if ( V_28 )
goto V_264;
}
V_28 = F_136 ( V_274 , V_271 , V_275 , V_272 ) ;
if ( ! V_28 ) {
V_28 = F_35 ( V_260 ) ;
if ( ! V_28 )
V_28 = F_35 ( V_259 ) ;
}
V_264:
F_122 ( V_259 -> V_30 -> V_10 . V_9 ) ;
V_280:
F_15 ( V_272 ) ;
V_278:
F_15 ( V_271 ) ;
V_31:
V_11 = F_27 ( V_28 ) ;
F_137 ( V_259 ) ;
F_137 ( V_260 ) ;
F_138 ( V_270 , V_269 ) ;
V_259 -> V_226 = V_260 -> V_226 = 0 ;
V_12:
return V_11 ;
}
T_1
F_139 ( struct V_1 * V_2 , struct V_22 * V_23 , int type ,
char * V_215 , int V_216 )
{
struct V_3 * V_3 , * V_281 ;
struct V_36 * V_219 ;
T_1 V_11 ;
int V_28 ;
V_11 = V_122 ;
if ( ! V_216 || F_24 ( V_215 , V_216 ) )
goto V_12;
V_11 = F_29 ( V_2 , V_23 , V_33 , V_276 ) ;
if ( V_11 )
goto V_12;
F_115 ( V_23 , V_225 ) ;
V_3 = V_23 -> V_29 ;
V_219 = V_3 -> V_21 ;
V_281 = F_26 ( V_215 , V_3 , V_216 ) ;
V_28 = F_7 ( V_281 ) ;
if ( F_6 ( V_281 ) )
goto V_31;
if ( ! V_281 -> V_21 ) {
F_15 ( V_281 ) ;
V_11 = V_35 ;
goto V_12;
}
if ( ! type )
type = V_281 -> V_21 -> V_37 & V_282 ;
V_28 = F_118 ( V_23 -> V_30 -> V_10 . V_9 ) ;
if ( V_28 )
goto V_283;
V_28 = F_32 ( V_281 -> V_21 ) ;
if ( V_28 )
goto V_264;
if ( type != V_33 )
V_28 = F_140 ( V_219 , V_281 ) ;
else
V_28 = F_141 ( V_219 , V_281 ) ;
if ( ! V_28 )
V_28 = F_35 ( V_23 ) ;
V_264:
F_122 ( V_23 -> V_30 -> V_10 . V_9 ) ;
V_283:
F_15 ( V_281 ) ;
V_31:
V_11 = F_27 ( V_28 ) ;
V_12:
return V_11 ;
}
static int F_142 ( void * V_284 , const char * V_24 , int V_285 ,
T_8 V_172 , T_11 V_135 , unsigned int V_286 )
{
struct V_287 * V_85 = V_284 ;
struct V_288 * V_289 = ( void * ) ( V_85 -> V_290 + V_85 -> V_291 ) ;
unsigned int V_292 ;
V_292 = F_143 ( sizeof( struct V_288 ) + V_285 , sizeof( T_11 ) ) ;
if ( V_85 -> V_291 + V_292 > V_293 ) {
V_85 -> V_294 = 1 ;
return - V_99 ;
}
V_289 -> V_285 = V_285 ;
V_289 -> V_172 = V_172 ;
V_289 -> V_135 = V_135 ;
V_289 -> V_286 = V_286 ;
memcpy ( V_289 -> V_24 , V_24 , V_285 ) ;
V_85 -> V_291 += V_292 ;
return 0 ;
}
static T_1 F_144 ( struct V_127 * V_127 , T_12 V_295 ,
struct V_296 * V_297 , T_8 * V_298 )
{
struct V_287 V_85 ;
struct V_288 * V_289 ;
int V_28 ;
int V_168 ;
T_8 V_172 ;
V_85 . V_290 = ( void * ) F_145 ( V_88 ) ;
if ( ! V_85 . V_290 )
return F_27 ( - V_89 ) ;
V_172 = * V_298 ;
while ( 1 ) {
struct V_36 * V_299 = V_127 -> V_189 . V_3 -> V_21 ;
unsigned int V_292 ;
V_297 -> V_11 = V_300 ;
V_85 . V_291 = 0 ;
V_85 . V_294 = 0 ;
V_28 = F_146 ( V_127 , F_142 , & V_85 ) ;
if ( V_85 . V_294 )
V_28 = 0 ;
if ( V_28 < 0 )
break;
V_168 = V_85 . V_291 ;
if ( ! V_168 )
break;
V_28 = F_147 ( & V_299 -> V_188 ) ;
if ( V_28 )
break;
V_289 = (struct V_288 * ) V_85 . V_290 ;
while ( V_168 > 0 ) {
V_172 = V_289 -> V_172 ;
if ( V_295 ( V_297 , V_289 -> V_24 , V_289 -> V_285 , V_289 -> V_172 ,
V_289 -> V_135 , V_289 -> V_286 ) )
break;
if ( V_297 -> V_11 != V_120 )
break;
V_292 = F_143 ( sizeof( * V_289 ) + V_289 -> V_285 ,
sizeof( T_11 ) ) ;
V_168 -= V_292 ;
V_289 = (struct V_288 * ) ( ( char * ) V_289 + V_292 ) ;
}
F_96 ( & V_299 -> V_188 ) ;
if ( V_168 > 0 )
break;
V_172 = F_148 ( V_127 , 0 , V_301 ) ;
}
F_149 ( ( unsigned long ) ( V_85 . V_290 ) ) ;
if ( V_28 )
return F_27 ( V_28 ) ;
* V_298 = V_172 ;
return V_297 -> V_11 ;
}
T_1
F_150 ( struct V_1 * V_2 , struct V_22 * V_23 , T_8 * V_298 ,
struct V_296 * V_297 , T_12 V_295 )
{
T_1 V_11 ;
struct V_127 * V_127 ;
T_8 V_172 = * V_298 ;
V_11 = F_70 ( V_2 , V_23 , V_33 , V_131 , & V_127 ) ;
if ( V_11 )
goto V_12;
V_172 = F_148 ( V_127 , V_172 , 0 ) ;
if ( V_172 < 0 ) {
V_11 = F_27 ( ( int ) V_172 ) ;
goto V_302;
}
V_11 = F_144 ( V_127 , V_295 , V_297 , V_298 ) ;
if ( V_11 == V_300 || V_11 == V_303 )
V_11 = V_120 ;
V_302:
F_77 ( V_127 ) ;
V_12:
return V_11 ;
}
T_1
F_151 ( struct V_1 * V_2 , struct V_22 * V_23 , struct V_304 * V_305 , int V_106 )
{
T_1 V_11 ;
V_11 = F_29 ( V_2 , V_23 , 0 , V_114 | V_106 ) ;
if ( ! V_11 ) {
struct V_8 V_8 = {
. V_9 = V_23 -> V_30 -> V_10 . V_9 ,
. V_3 = V_23 -> V_29 ,
} ;
if ( F_152 ( & V_8 , V_305 ) )
V_11 = V_230 ;
}
return V_11 ;
}
static int F_153 ( struct V_1 * V_2 , struct V_5 * exp )
{
return F_154 ( V_2 , exp ) & V_306 ;
}
T_1
F_44 ( struct V_1 * V_2 , struct V_5 * exp ,
struct V_3 * V_3 , int V_307 )
{
struct V_36 * V_36 = V_3 -> V_21 ;
int V_11 ;
if ( ( V_307 & V_308 ) == V_114 )
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
if ( ! ( V_307 & V_309 ) )
if ( V_307 & ( V_56 | V_49 | V_66 ) ) {
if ( F_153 ( V_2 , exp ) ||
F_155 ( exp -> V_10 . V_9 ) )
return V_121 ;
if ( F_156 ( V_36 ) )
return V_123 ;
}
if ( ( V_307 & V_66 ) && F_72 ( V_36 ) )
return V_123 ;
if ( V_307 & V_310 ) {
if ( exp -> V_14 & V_311 )
return 0 ;
else
V_307 = V_131 | V_57 ;
}
if ( ( V_307 & V_57 ) &&
V_36 -> V_71 == F_112 () )
return 0 ;
V_11 = F_157 ( V_36 , V_307 & ( V_312 | V_313 | V_314 ) ) ;
if ( V_11 == - V_315 && F_33 ( V_36 -> V_37 ) &&
V_307 == ( V_131 | V_57 ) )
V_11 = F_157 ( V_36 , V_314 ) ;
return V_11 ? F_27 ( V_11 ) : 0 ;
}
void
F_158 ( void )
{
struct V_133 * V_316 , * V_317 ;
unsigned int V_318 ;
F_21 ( L_9 ) ;
for ( V_318 = 0 ; V_318 < V_319 ; V_318 ++ ) {
V_316 = V_144 [ V_318 ] . V_146 ;
while( V_316 ) {
V_317 = V_316 ;
V_316 = V_316 -> V_147 ;
F_54 ( V_317 ) ;
}
V_144 [ V_318 ] . V_146 = NULL ;
}
}
int
F_159 ( int V_320 )
{
int V_318 ;
int V_321 = 0 ;
int V_322 ;
struct V_133 * * V_316 = NULL ;
if ( V_144 [ 0 ] . V_146 )
return 0 ;
V_322 = F_160 ( V_320 , V_319 ) ;
if ( V_322 < 2 )
V_322 = 2 ;
V_320 = V_322 * V_319 ;
F_21 ( L_10 , V_320 ) ;
for ( V_318 = 0 ; V_318 < V_319 ; V_318 ++ ) {
F_161 ( & V_144 [ V_318 ] . V_145 ) ;
V_316 = & V_144 [ V_318 ] . V_146 ;
for ( V_321 = 0 ; V_321 < V_322 ; V_321 ++ ) {
* V_316 = F_162 ( sizeof( struct V_133 ) , V_88 ) ;
if ( ! * V_316 )
goto V_323;
V_316 = & ( * V_316 ) -> V_147 ;
}
* V_316 = NULL ;
}
V_152 . V_153 = V_320 ;
return 0 ;
V_323:
F_21 ( L_11 ) ;
F_158 () ;
return - V_89 ;
}
struct V_90 *
F_163 ( struct V_22 * V_23 , int type )
{
struct V_36 * V_36 = V_23 -> V_29 -> V_21 ;
char * V_24 ;
void * V_324 = NULL ;
T_3 V_168 ;
struct V_90 * V_94 ;
if ( ! F_164 ( V_36 ) )
return F_63 ( - V_104 ) ;
switch ( type ) {
case V_325 :
V_24 = V_101 ;
break;
case V_326 :
V_24 = V_103 ;
break;
default:
return F_63 ( - V_104 ) ;
}
V_168 = F_51 ( V_23 -> V_29 , V_24 , & V_324 ) ;
if ( V_168 < 0 )
return F_63 ( V_168 ) ;
V_94 = F_64 ( V_324 , V_168 ) ;
F_54 ( V_324 ) ;
return V_94 ;
}
int
F_165 ( struct V_22 * V_23 , int type , struct V_90 * V_94 )
{
struct V_36 * V_36 = V_23 -> V_29 -> V_21 ;
char * V_24 ;
void * V_324 = NULL ;
T_4 V_168 ;
int error ;
if ( ! F_164 ( V_36 ) ||
! V_36 -> V_223 -> V_327 || ! V_36 -> V_223 -> V_328 )
return - V_104 ;
switch( type ) {
case V_325 :
V_24 = V_101 ;
break;
case V_326 :
V_24 = V_103 ;
break;
default:
return - V_104 ;
}
if ( V_94 && V_94 -> V_92 ) {
V_168 = F_56 ( V_94 -> V_92 ) ;
V_324 = F_53 ( V_168 , V_88 ) ;
if ( ! V_324 )
return - V_89 ;
error = F_57 ( V_94 , V_324 , V_168 ) ;
if ( error < 0 )
goto V_329;
V_168 = error ;
} else
V_168 = 0 ;
error = F_118 ( V_23 -> V_30 -> V_10 . V_9 ) ;
if ( error )
goto V_329;
if ( V_168 )
error = F_58 ( V_23 -> V_29 , V_24 , V_324 , V_168 , 0 ) ;
else {
if ( ! F_48 ( V_36 -> V_37 ) && type == V_326 )
error = 0 ;
else {
error = F_166 ( V_23 -> V_29 , V_24 ) ;
if ( error == - V_105 )
error = 0 ;
}
}
F_122 ( V_23 -> V_30 -> V_10 . V_9 ) ;
V_329:
F_54 ( V_324 ) ;
return error ;
}

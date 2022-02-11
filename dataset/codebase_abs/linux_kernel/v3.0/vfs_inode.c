static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
V_4 = V_3 & 0777 ;
if ( F_2 ( V_3 ) )
V_4 |= V_5 ;
if ( F_3 ( V_2 ) ) {
if ( F_4 ( V_3 ) )
V_4 |= V_6 ;
if ( V_2 -> V_7 == 0 ) {
if ( F_5 ( V_3 ) )
V_4 |= V_8 ;
if ( F_6 ( V_3 ) )
V_4 |= V_9 ;
if ( F_7 ( V_3 ) )
V_4 |= V_10 ;
if ( F_8 ( V_3 ) )
V_4 |= V_10 ;
}
if ( ( V_3 & V_11 ) == V_11 )
V_4 |= V_12 ;
if ( ( V_3 & V_13 ) == V_13 )
V_4 |= V_14 ;
if ( ( V_3 & V_15 ) == V_15 )
V_4 |= V_16 ;
if ( ( V_3 & V_17 ) )
V_4 |= V_17 ;
}
return V_4 ;
}
static int F_9 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
V_4 = V_3 & 0777 ;
if ( ( V_3 & V_5 ) == V_5 )
V_4 |= V_18 ;
else if ( ( V_3 & V_6 ) && ( F_3 ( V_2 ) ) )
V_4 |= V_19 ;
else if ( ( V_3 & V_8 ) && ( F_3 ( V_2 ) )
&& ( V_2 -> V_7 == 0 ) )
V_4 |= V_20 ;
else if ( ( V_3 & V_9 ) && ( F_3 ( V_2 ) )
&& ( V_2 -> V_7 == 0 ) )
V_4 |= V_21 ;
else if ( ( V_3 & V_10 ) && ( F_3 ( V_2 ) )
&& ( V_2 -> V_7 == 0 ) )
V_4 |= V_22 ;
else
V_4 |= V_23 ;
if ( F_3 ( V_2 ) ) {
if ( ( V_3 & V_12 ) == V_12 )
V_4 |= V_11 ;
if ( ( V_3 & V_14 ) == V_14 )
V_4 |= V_13 ;
if ( ( V_3 & V_16 ) == V_16 )
V_4 |= V_15 ;
}
return V_4 ;
}
int F_10 ( int V_24 , int V_25 )
{
int V_26 ;
V_26 = 0 ;
switch ( V_24 & 3 ) {
default:
case V_27 :
V_26 = V_28 ;
break;
case V_29 :
V_26 = V_30 ;
break;
case V_31 :
V_26 = V_32 ;
break;
}
if ( V_24 & V_33 )
V_26 |= V_34 ;
if ( V_25 ) {
if ( V_24 & V_35 )
V_26 |= V_36 ;
if ( V_24 & V_37 )
V_26 |= V_38 ;
}
return V_26 ;
}
void
F_11 ( struct V_39 * V_40 )
{
V_40 -> type = ~ 0 ;
V_40 -> V_41 = ~ 0 ;
V_40 -> V_42 . type = ~ 0 ;
V_40 -> V_42 . V_43 = ~ 0 ;
* ( ( long long * ) & V_40 -> V_42 . V_44 ) = ~ 0 ;
V_40 -> V_3 = ~ 0 ;
V_40 -> V_45 = ~ 0 ;
V_40 -> V_46 = ~ 0 ;
V_40 -> V_47 = ~ 0 ;
V_40 -> V_48 = NULL ;
V_40 -> V_49 = NULL ;
V_40 -> V_50 = NULL ;
V_40 -> V_51 = NULL ;
V_40 -> V_52 = ~ 0 ;
V_40 -> V_53 = ~ 0 ;
V_40 -> V_54 = ~ 0 ;
V_40 -> V_55 = NULL ;
}
struct V_56 * F_12 ( struct V_57 * V_58 )
{
struct V_59 * V_60 ;
V_60 = (struct V_59 * ) F_13 ( V_61 ,
V_62 ) ;
if ( ! V_60 )
return NULL ;
#ifdef F_14
V_60 -> V_63 = NULL ;
V_60 -> V_64 = NULL ;
F_15 ( & V_60 -> V_65 ) ;
#endif
V_60 -> V_66 = NULL ;
V_60 -> V_67 = 0 ;
F_16 ( & V_60 -> V_68 ) ;
return & V_60 -> V_69 ;
}
static void F_17 ( struct V_70 * V_71 )
{
struct V_56 * V_56 = F_18 ( V_71 , struct V_56 , V_72 ) ;
F_19 ( & V_56 -> V_73 ) ;
F_20 ( V_61 , F_21 ( V_56 ) ) ;
}
void F_22 ( struct V_56 * V_56 )
{
F_23 ( & V_56 -> V_72 , F_17 ) ;
}
int F_24 ( struct V_1 * V_2 ,
struct V_56 * V_56 , int V_3 )
{
int V_74 = 0 ;
F_25 ( V_56 , NULL , V_3 ) ;
V_56 -> V_75 = 0 ;
V_56 -> V_76 = 0 ;
V_56 -> V_77 = V_56 -> V_78 = V_56 -> V_79 = V_80 ;
V_56 -> V_81 -> V_82 = & V_83 ;
switch ( V_3 & V_84 ) {
case V_21 :
case V_22 :
case V_85 :
case V_20 :
if ( F_26 ( V_2 ) ) {
V_56 -> V_86 = & V_87 ;
V_56 -> V_88 = & V_89 ;
} else if ( F_3 ( V_2 ) ) {
V_56 -> V_86 = & V_90 ;
V_56 -> V_88 = & V_91 ;
} else {
F_27 ( V_92 ,
L_1 ) ;
V_74 = - V_93 ;
goto error;
}
F_28 ( V_56 , V_56 -> V_94 , V_56 -> V_76 ) ;
break;
case V_23 :
if ( F_26 ( V_2 ) ) {
V_56 -> V_86 = & V_87 ;
if ( V_2 -> V_95 )
V_56 -> V_88 =
& V_96 ;
else
V_56 -> V_88 = & V_89 ;
} else {
V_56 -> V_86 = & V_90 ;
if ( V_2 -> V_95 )
V_56 -> V_88 = & V_97 ;
else
V_56 -> V_88 = & V_91 ;
}
break;
case V_19 :
if ( ! F_3 ( V_2 ) && ! F_26 ( V_2 ) ) {
F_27 ( V_92 , L_2
L_3 ) ;
V_74 = - V_93 ;
goto error;
}
if ( F_26 ( V_2 ) )
V_56 -> V_86 = & V_98 ;
else
V_56 -> V_86 = & V_99 ;
break;
case V_18 :
F_29 ( V_56 ) ;
if ( F_26 ( V_2 ) )
V_56 -> V_86 = & V_100 ;
else if ( F_3 ( V_2 ) )
V_56 -> V_86 = & V_101 ;
else
V_56 -> V_86 = & V_102 ;
if ( F_26 ( V_2 ) )
V_56 -> V_88 = & V_103 ;
else
V_56 -> V_88 = & V_104 ;
break;
default:
F_27 ( V_92 , L_4 ,
V_3 , V_3 & V_84 ) ;
V_74 = - V_93 ;
goto error;
}
error:
return V_74 ;
}
struct V_56 * F_30 ( struct V_57 * V_58 , int V_3 )
{
int V_74 ;
struct V_56 * V_56 ;
struct V_1 * V_2 = V_58 -> V_105 ;
F_27 ( V_106 , L_5 , V_58 , V_3 ) ;
V_56 = F_31 ( V_58 ) ;
if ( ! V_56 ) {
F_32 ( V_107 , L_6 ) ;
return F_33 ( - V_108 ) ;
}
V_74 = F_24 ( V_2 , V_56 , V_3 ) ;
if ( V_74 ) {
F_34 ( V_56 ) ;
return F_33 ( V_74 ) ;
}
return V_56 ;
}
void F_35 ( struct V_56 * V_56 )
{
struct V_59 * V_60 = F_21 ( V_56 ) ;
F_36 ( V_56 -> V_81 , 0 ) ;
F_37 ( V_56 ) ;
F_38 ( V_56 -> V_81 ) ;
#ifdef F_14
F_39 ( V_56 ) ;
#endif
if ( V_60 -> V_66 ) {
F_40 ( V_60 -> V_66 ) ;
V_60 -> V_66 = NULL ;
}
}
static struct V_56 * F_41 ( struct V_57 * V_58 ,
struct V_109 * V_42 ,
struct V_39 * V_110 )
{
int V_111 , V_112 ;
unsigned long V_113 ;
struct V_56 * V_56 ;
struct V_1 * V_2 = V_58 -> V_105 ;
V_113 = F_42 ( V_42 ) ;
V_56 = F_43 ( V_58 , V_113 ) ;
if ( ! V_56 )
return F_33 ( - V_108 ) ;
if ( ! ( V_56 -> V_114 & V_115 ) )
return V_56 ;
V_112 = F_9 ( V_2 , V_110 -> V_3 ) ;
V_111 = F_24 ( V_2 , V_56 , V_112 ) ;
if ( V_111 )
goto error;
F_44 ( V_110 , V_56 , V_58 ) ;
#ifdef F_14
F_45 ( V_56 , & V_110 -> V_42 ) ;
F_46 ( V_56 ) ;
#endif
F_47 ( V_56 ) ;
return V_56 ;
error:
F_47 ( V_56 ) ;
F_34 ( V_56 ) ;
return F_33 ( V_111 ) ;
}
struct V_56 *
F_48 ( struct V_1 * V_2 , struct V_116 * V_117 ,
struct V_57 * V_58 )
{
struct V_39 * V_110 ;
struct V_56 * V_56 = NULL ;
V_110 = F_49 ( V_117 ) ;
if ( F_50 ( V_110 ) )
return F_51 ( V_110 ) ;
V_56 = F_41 ( V_58 , & V_110 -> V_42 , V_110 ) ;
F_52 ( V_110 ) ;
F_53 ( V_110 ) ;
return V_56 ;
}
static int F_54 ( struct V_56 * V_118 , struct V_119 * V_120 , int V_121 )
{
int V_111 ;
struct V_116 * V_122 ;
struct V_56 * V_123 ;
F_27 ( V_106 , L_7 , V_118 , V_120 ,
V_121 ) ;
V_123 = V_120 -> V_124 ;
V_122 = F_55 ( V_120 ) ;
if ( F_50 ( V_122 ) )
return F_56 ( V_122 ) ;
V_111 = F_57 ( V_122 ) ;
if ( ! V_111 ) {
if ( V_121 ) {
F_58 ( V_123 ) ;
F_59 ( V_118 ) ;
} else
F_59 ( V_123 ) ;
F_60 ( V_123 ) ;
F_60 ( V_118 ) ;
}
return V_111 ;
}
static struct V_116 *
F_61 ( struct V_1 * V_2 , struct V_56 * V_118 ,
struct V_119 * V_119 , char * V_55 , T_1 V_125 , T_2 V_3 )
{
int V_74 ;
char * V_48 ;
struct V_116 * V_126 , * V_127 , * V_117 ;
struct V_56 * V_56 ;
F_27 ( V_106 , L_8 , V_119 -> V_128 . V_48 ) ;
V_74 = 0 ;
V_127 = NULL ;
V_117 = NULL ;
V_48 = ( char * ) V_119 -> V_128 . V_48 ;
V_126 = F_62 ( V_119 -> V_129 ) ;
if ( F_50 ( V_126 ) ) {
V_74 = F_56 ( V_126 ) ;
F_27 ( V_106 , L_9 , V_74 ) ;
return F_33 ( V_74 ) ;
}
V_127 = F_63 ( V_126 , 0 , NULL , 1 ) ;
if ( F_50 ( V_127 ) ) {
V_74 = F_56 ( V_127 ) ;
F_27 ( V_106 , L_10 , V_74 ) ;
return F_33 ( V_74 ) ;
}
V_74 = F_64 ( V_127 , V_48 , V_125 , V_3 , V_55 ) ;
if ( V_74 < 0 ) {
F_27 ( V_106 , L_11 , V_74 ) ;
goto error;
}
V_117 = F_63 ( V_126 , 1 , & V_48 , 1 ) ;
if ( F_50 ( V_117 ) ) {
V_74 = F_56 ( V_117 ) ;
F_27 ( V_106 , L_10 , V_74 ) ;
V_117 = NULL ;
goto error;
}
V_56 = F_65 ( V_2 , V_117 , V_118 -> V_130 ) ;
if ( F_50 ( V_56 ) ) {
V_74 = F_56 ( V_56 ) ;
F_27 ( V_106 , L_12 , V_74 ) ;
goto error;
}
F_66 ( V_119 , V_56 ) ;
V_74 = F_67 ( V_119 , V_117 ) ;
if ( V_74 < 0 )
goto error;
return V_127 ;
error:
if ( V_127 )
F_40 ( V_127 ) ;
if ( V_117 )
F_40 ( V_117 ) ;
return F_33 ( V_74 ) ;
}
static int
F_68 ( struct V_56 * V_118 , struct V_119 * V_119 , int V_3 ,
struct V_131 * V_132 )
{
int V_74 ;
T_1 V_125 ;
int V_133 ;
struct V_120 * V_134 ;
struct V_59 * V_60 ;
struct V_1 * V_2 ;
struct V_116 * V_117 , * V_135 ;
V_74 = 0 ;
V_117 = NULL ;
V_2 = F_69 ( V_118 ) ;
V_125 = F_1 ( V_2 , V_3 ) ;
if ( V_132 && V_132 -> V_133 & V_136 )
V_133 = V_132 -> V_137 . V_138 . V_133 - 1 ;
else
V_133 = V_31 ;
V_117 = F_61 ( V_2 , V_118 , V_119 , NULL , V_125 ,
F_10 ( V_133 ,
F_3 ( V_2 ) ) ) ;
if ( F_50 ( V_117 ) ) {
V_74 = F_56 ( V_117 ) ;
V_117 = NULL ;
goto error;
}
F_60 ( V_118 ) ;
if ( V_132 && V_132 -> V_133 & V_136 ) {
V_60 = F_21 ( V_119 -> V_124 ) ;
F_70 ( & V_60 -> V_68 ) ;
if ( V_2 -> V_95 && ! V_60 -> V_66 &&
( ( V_133 & V_139 ) != V_27 ) ) {
V_135 = F_71 ( V_119 ) ;
if ( F_50 ( V_135 ) ) {
V_74 = F_56 ( V_135 ) ;
F_72 ( & V_60 -> V_68 ) ;
goto error;
}
V_60 -> V_66 = ( void * ) V_135 ;
}
F_72 ( & V_60 -> V_68 ) ;
V_134 = F_73 ( V_132 , V_119 , V_140 ) ;
if ( F_50 ( V_134 ) ) {
V_74 = F_56 ( V_134 ) ;
goto error;
}
V_134 -> V_141 = V_117 ;
#ifdef F_14
if ( V_2 -> V_95 )
F_74 ( V_119 -> V_124 , V_134 ) ;
#endif
} else
F_40 ( V_117 ) ;
return 0 ;
error:
if ( V_117 )
F_40 ( V_117 ) ;
return V_74 ;
}
static int F_75 ( struct V_56 * V_118 , struct V_119 * V_119 , int V_3 )
{
int V_74 ;
T_1 V_125 ;
struct V_116 * V_117 ;
struct V_1 * V_2 ;
F_27 ( V_106 , L_8 , V_119 -> V_128 . V_48 ) ;
V_74 = 0 ;
V_2 = F_69 ( V_118 ) ;
V_125 = F_1 ( V_2 , V_3 | V_18 ) ;
V_117 = F_61 ( V_2 , V_118 , V_119 , NULL , V_125 , V_28 ) ;
if ( F_50 ( V_117 ) ) {
V_74 = F_56 ( V_117 ) ;
V_117 = NULL ;
} else {
F_29 ( V_118 ) ;
F_60 ( V_118 ) ;
}
if ( V_117 )
F_40 ( V_117 ) ;
return V_74 ;
}
struct V_119 * F_76 ( struct V_56 * V_118 , struct V_119 * V_119 ,
struct V_131 * V_131 )
{
struct V_57 * V_58 ;
struct V_1 * V_2 ;
struct V_116 * V_126 , * V_117 ;
struct V_56 * V_56 ;
char * V_48 ;
int V_142 = 0 ;
F_27 ( V_106 , L_13 ,
V_118 , V_119 -> V_128 . V_48 , V_119 , V_131 ) ;
if ( V_119 -> V_128 . V_143 > V_144 )
return F_33 ( - V_145 ) ;
V_58 = V_118 -> V_130 ;
V_2 = F_69 ( V_118 ) ;
V_126 = F_62 ( V_119 -> V_129 ) ;
if ( F_50 ( V_126 ) )
return F_51 ( V_126 ) ;
V_48 = ( char * ) V_119 -> V_128 . V_48 ;
V_117 = F_63 ( V_126 , 1 , & V_48 , 1 ) ;
if ( F_50 ( V_117 ) ) {
V_142 = F_56 ( V_117 ) ;
if ( V_142 == - V_146 ) {
V_56 = NULL ;
goto V_147;
}
return F_33 ( V_142 ) ;
}
V_56 = F_65 ( V_2 , V_117 , V_118 -> V_130 ) ;
if ( F_50 ( V_56 ) ) {
V_142 = F_56 ( V_56 ) ;
V_56 = NULL ;
goto error;
}
V_142 = F_67 ( V_119 , V_117 ) ;
if ( V_142 < 0 )
goto V_148;
V_147:
F_77 ( V_119 , V_56 ) ;
return NULL ;
V_148:
F_34 ( V_56 ) ;
error:
F_40 ( V_117 ) ;
return F_33 ( V_142 ) ;
}
int F_78 ( struct V_56 * V_149 , struct V_119 * V_150 )
{
return F_54 ( V_149 , V_150 , 0 ) ;
}
int F_79 ( struct V_56 * V_149 , struct V_119 * V_150 )
{
return F_54 ( V_149 , V_150 , 1 ) ;
}
int
F_80 ( struct V_56 * V_151 , struct V_119 * V_152 ,
struct V_56 * V_153 , struct V_119 * V_154 )
{
int V_111 ;
struct V_56 * V_155 ;
struct V_56 * F_31 ;
struct V_1 * V_2 ;
struct V_116 * V_156 ;
struct V_116 * V_157 ;
struct V_116 * V_158 ;
struct V_39 V_40 ;
F_27 ( V_106 , L_14 ) ;
V_111 = 0 ;
V_155 = V_152 -> V_124 ;
F_31 = V_154 -> V_124 ;
V_2 = F_69 ( V_155 ) ;
V_156 = F_62 ( V_152 ) ;
if ( F_50 ( V_156 ) )
return F_56 ( V_156 ) ;
V_157 = F_55 ( V_152 -> V_129 ) ;
if ( F_50 ( V_157 ) ) {
V_111 = F_56 ( V_157 ) ;
goto V_159;
}
V_158 = F_55 ( V_154 -> V_129 ) ;
if ( F_50 ( V_158 ) ) {
V_111 = F_56 ( V_158 ) ;
goto V_160;
}
F_81 ( & V_2 -> V_161 ) ;
if ( F_26 ( V_2 ) ) {
V_111 = F_82 ( V_156 , V_158 ,
( char * ) V_154 -> V_128 . V_48 ) ;
if ( V_111 != - V_162 )
goto V_163;
}
if ( V_152 -> V_129 != V_154 -> V_129 ) {
F_27 ( V_92 ,
L_15 ) ;
V_111 = - V_164 ;
goto V_163;
}
F_11 ( & V_40 ) ;
V_40 . V_51 = V_2 -> V_165 ;
V_40 . V_48 = ( char * ) V_154 -> V_128 . V_48 ;
V_111 = F_83 ( V_156 , & V_40 ) ;
V_163:
if ( ! V_111 ) {
if ( F_31 ) {
if ( F_2 ( F_31 -> V_94 ) )
F_58 ( F_31 ) ;
else
F_59 ( F_31 ) ;
F_60 ( F_31 ) ;
}
if ( F_2 ( V_155 -> V_94 ) ) {
if ( ! F_31 )
F_29 ( V_153 ) ;
F_59 ( V_151 ) ;
}
F_60 ( V_155 ) ;
F_60 ( V_151 ) ;
F_60 ( V_153 ) ;
F_84 ( V_152 , V_154 ) ;
}
F_85 ( & V_2 -> V_161 ) ;
F_40 ( V_158 ) ;
V_160:
F_40 ( V_157 ) ;
V_159:
return V_111 ;
}
static int
F_86 ( struct V_166 * V_167 , struct V_119 * V_119 ,
struct V_168 * V_169 )
{
int V_74 ;
struct V_1 * V_2 ;
struct V_116 * V_117 ;
struct V_39 * V_110 ;
F_27 ( V_106 , L_16 , V_119 ) ;
V_74 = - V_170 ;
V_2 = F_87 ( V_119 ) ;
if ( V_2 -> V_95 == V_171 || V_2 -> V_95 == V_172 ) {
F_88 ( V_119 -> V_124 , V_169 ) ;
return 0 ;
}
V_117 = F_62 ( V_119 ) ;
if ( F_50 ( V_117 ) )
return F_56 ( V_117 ) ;
V_110 = F_49 ( V_117 ) ;
if ( F_50 ( V_110 ) )
return F_56 ( V_110 ) ;
F_44 ( V_110 , V_119 -> V_124 , V_119 -> V_124 -> V_130 ) ;
F_88 ( V_119 -> V_124 , V_169 ) ;
F_52 ( V_110 ) ;
F_53 ( V_110 ) ;
return 0 ;
}
static int F_89 ( struct V_119 * V_119 , struct V_173 * V_173 )
{
int V_111 ;
struct V_1 * V_2 ;
struct V_116 * V_117 ;
struct V_39 V_40 ;
F_27 ( V_106 , L_14 ) ;
V_111 = F_90 ( V_119 -> V_124 , V_173 ) ;
if ( V_111 )
return V_111 ;
V_111 = - V_170 ;
V_2 = F_87 ( V_119 ) ;
V_117 = F_62 ( V_119 ) ;
if( F_50 ( V_117 ) )
return F_56 ( V_117 ) ;
F_11 ( & V_40 ) ;
if ( V_173 -> V_174 & V_175 )
V_40 . V_3 = F_1 ( V_2 , V_173 -> V_176 ) ;
if ( V_173 -> V_174 & V_177 )
V_40 . V_46 = V_173 -> V_178 . V_179 ;
if ( V_173 -> V_174 & V_180 )
V_40 . V_45 = V_173 -> V_181 . V_179 ;
if ( V_173 -> V_174 & V_182 )
V_40 . V_47 = V_173 -> V_183 ;
if ( F_3 ( V_2 ) ) {
if ( V_173 -> V_174 & V_184 )
V_40 . V_52 = V_173 -> V_185 ;
if ( V_173 -> V_174 & V_186 )
V_40 . V_53 = V_173 -> V_187 ;
}
if ( F_91 ( V_119 -> V_124 -> V_94 ) )
F_92 ( V_119 -> V_124 -> V_81 ) ;
V_111 = F_83 ( V_117 , & V_40 ) ;
if ( V_111 < 0 )
return V_111 ;
if ( ( V_173 -> V_174 & V_182 ) &&
V_173 -> V_183 != F_93 ( V_119 -> V_124 ) )
F_94 ( V_119 -> V_124 , V_173 -> V_183 ) ;
F_60 ( V_119 -> V_124 ) ;
F_95 ( V_119 -> V_124 , V_173 ) ;
F_96 ( V_119 -> V_124 ) ;
return 0 ;
}
void
F_44 ( struct V_39 * V_169 , struct V_56 * V_56 ,
struct V_57 * V_58 )
{
char V_188 [ 32 ] ;
char V_189 [ 14 ] ;
unsigned int V_190 ;
struct V_1 * V_2 = V_58 -> V_105 ;
struct V_59 * V_60 = F_21 ( V_56 ) ;
V_56 -> V_190 = 1 ;
V_56 -> V_77 . V_179 = V_169 -> V_45 ;
V_56 -> V_78 . V_179 = V_169 -> V_46 ;
V_56 -> V_79 . V_179 = V_169 -> V_46 ;
V_56 -> V_191 = V_2 -> V_192 ;
V_56 -> V_193 = V_2 -> V_194 ;
if ( F_3 ( V_2 ) ) {
V_56 -> V_191 = V_169 -> V_52 ;
V_56 -> V_193 = V_169 -> V_53 ;
}
if ( ( F_91 ( V_56 -> V_94 ) ) || ( F_2 ( V_56 -> V_94 ) ) ) {
if ( F_3 ( V_2 ) && ( V_169 -> V_55 [ 0 ] != '\0' ) ) {
strncpy ( V_188 , V_169 -> V_55 , sizeof( V_188 ) ) ;
sscanf ( V_188 , L_17 , V_189 , & V_190 ) ;
if ( ! strncmp ( V_189 , L_18 , 13 ) )
V_56 -> V_190 = V_190 ;
}
}
V_56 -> V_94 = F_9 ( V_2 , V_169 -> V_3 ) ;
if ( ( F_7 ( V_56 -> V_94 ) ) || ( F_8 ( V_56 -> V_94 ) ) ) {
char type = 0 ;
int V_195 = - 1 ;
int V_196 = - 1 ;
strncpy ( V_188 , V_169 -> V_55 , sizeof( V_188 ) ) ;
sscanf ( V_188 , L_19 , & type , & V_195 , & V_196 ) ;
switch ( type ) {
case 'c' :
V_56 -> V_94 &= ~ V_22 ;
V_56 -> V_94 |= V_85 ;
break;
case 'b' :
break;
default:
F_27 ( V_92 ,
L_20 , type ,
V_169 -> V_55 ) ;
} ;
V_56 -> V_76 = F_97 ( V_195 , V_196 ) ;
F_28 ( V_56 , V_56 -> V_94 , V_56 -> V_76 ) ;
} else
V_56 -> V_76 = 0 ;
F_98 ( V_56 , V_169 -> V_47 ) ;
V_56 -> V_75 = ( F_93 ( V_56 ) + 512 - 1 ) >> 9 ;
V_60 -> V_67 &= ~ V_197 ;
}
T_3 F_42 ( struct V_109 * V_42 )
{
T_4 V_44 = V_42 -> V_44 + 2 ;
T_3 V_149 = 0 ;
if ( sizeof( T_3 ) == sizeof( V_44 ) )
memcpy ( & V_149 , & V_44 , sizeof( T_3 ) ) ;
else
V_149 = ( T_3 ) ( V_44 ^ ( V_44 >> 32 ) ) ;
return V_149 ;
}
static int F_99 ( struct V_119 * V_119 , char * V_198 , int V_199 )
{
int V_111 ;
struct V_1 * V_2 ;
struct V_116 * V_117 ;
struct V_39 * V_110 ;
F_27 ( V_106 , L_21 , V_119 -> V_128 . V_48 ) ;
V_111 = - V_170 ;
V_2 = F_87 ( V_119 ) ;
V_117 = F_62 ( V_119 ) ;
if ( F_50 ( V_117 ) )
return F_56 ( V_117 ) ;
if ( ! F_3 ( V_2 ) )
return - V_200 ;
V_110 = F_49 ( V_117 ) ;
if ( F_50 ( V_110 ) )
return F_56 ( V_110 ) ;
if ( ! ( V_110 -> V_3 & V_6 ) ) {
V_111 = - V_93 ;
goto V_159;
}
strncpy ( V_198 , V_110 -> V_55 , V_199 ) ;
F_27 ( V_106 ,
L_22 , V_119 -> V_128 . V_48 , V_110 -> V_55 , V_198 ) ;
V_111 = F_100 ( V_198 , V_199 ) ;
V_159:
F_52 ( V_110 ) ;
F_53 ( V_110 ) ;
return V_111 ;
}
static void * F_101 ( struct V_119 * V_119 , struct V_131 * V_132 )
{
int V_143 = 0 ;
char * V_201 = F_102 () ;
F_27 ( V_106 , L_23 , V_119 -> V_128 . V_48 ) ;
if ( ! V_201 )
V_201 = F_33 ( - V_108 ) ;
else {
V_143 = F_99 ( V_119 , V_201 , V_202 ) ;
if ( V_143 < 0 ) {
F_103 ( V_201 ) ;
V_201 = F_33 ( V_143 ) ;
} else
V_201 [ F_104 ( V_143 , V_202 - 1 ) ] = 0 ;
}
F_105 ( V_132 , V_201 ) ;
return NULL ;
}
void
F_106 ( struct V_119 * V_119 , struct V_131 * V_132 , void * V_203 )
{
char * V_204 = F_107 ( V_132 ) ;
F_27 ( V_106 , L_24 , V_119 -> V_128 . V_48 ,
F_50 ( V_204 ) ? L_25 : V_204 ) ;
if ( ! F_50 ( V_204 ) )
F_103 ( V_204 ) ;
}
static int F_108 ( struct V_56 * V_118 , struct V_119 * V_119 ,
int V_3 , const char * V_55 )
{
T_1 V_125 ;
struct V_116 * V_117 ;
struct V_1 * V_2 ;
V_2 = F_69 ( V_118 ) ;
if ( ! F_3 ( V_2 ) ) {
F_27 ( V_92 , L_26 ) ;
return - V_170 ;
}
V_125 = F_1 ( V_2 , V_3 ) ;
V_117 = F_61 ( V_2 , V_118 , V_119 , ( char * ) V_55 , V_125 ,
V_28 ) ;
if ( F_50 ( V_117 ) )
return F_56 ( V_117 ) ;
F_60 ( V_118 ) ;
F_40 ( V_117 ) ;
return 0 ;
}
static int
F_109 ( struct V_56 * V_118 , struct V_119 * V_119 , const char * V_205 )
{
F_27 ( V_106 , L_27 , V_118 -> V_113 ,
V_119 -> V_128 . V_48 , V_205 ) ;
return F_108 ( V_118 , V_119 , V_19 , V_205 ) ;
}
static int
F_110 ( struct V_119 * V_152 , struct V_56 * V_118 ,
struct V_119 * V_119 )
{
int V_111 ;
char * V_48 ;
struct V_116 * V_156 ;
F_27 ( V_106 ,
L_27 , V_118 -> V_113 , V_119 -> V_128 . V_48 ,
V_152 -> V_128 . V_48 ) ;
V_156 = F_55 ( V_152 ) ;
if ( F_50 ( V_156 ) )
return F_56 ( V_156 ) ;
V_48 = F_102 () ;
if ( F_111 ( ! V_48 ) ) {
V_111 = - V_108 ;
goto V_206;
}
sprintf ( V_48 , L_28 , V_156 -> V_117 ) ;
V_111 = F_108 ( V_118 , V_119 , V_17 , V_48 ) ;
F_103 ( V_48 ) ;
if ( ! V_111 ) {
F_112 ( V_156 , V_152 -> V_124 ) ;
F_60 ( V_118 ) ;
}
V_206:
F_40 ( V_156 ) ;
return V_111 ;
}
static int
F_113 ( struct V_56 * V_118 , struct V_119 * V_119 , int V_3 , T_5 V_207 )
{
int V_111 ;
char * V_48 ;
F_27 ( V_106 ,
L_29 , V_118 -> V_113 ,
V_119 -> V_128 . V_48 , V_3 , F_114 ( V_207 ) , F_115 ( V_207 ) ) ;
if ( ! F_116 ( V_207 ) )
return - V_93 ;
V_48 = F_102 () ;
if ( ! V_48 )
return - V_108 ;
if ( F_7 ( V_3 ) )
sprintf ( V_48 , L_30 , F_114 ( V_207 ) , F_115 ( V_207 ) ) ;
else if ( F_8 ( V_3 ) )
sprintf ( V_48 , L_31 , F_114 ( V_207 ) , F_115 ( V_207 ) ) ;
else if ( F_6 ( V_3 ) )
* V_48 = 0 ;
else if ( F_5 ( V_3 ) )
* V_48 = 0 ;
else {
F_103 ( V_48 ) ;
return - V_93 ;
}
V_111 = F_108 ( V_118 , V_119 , V_3 , V_48 ) ;
F_103 ( V_48 ) ;
return V_111 ;
}
int F_112 ( struct V_116 * V_117 , struct V_56 * V_56 )
{
T_6 V_208 ;
struct V_39 * V_110 ;
struct V_1 * V_2 ;
V_2 = F_69 ( V_56 ) ;
V_110 = F_49 ( V_117 ) ;
if ( F_50 ( V_110 ) )
return F_56 ( V_110 ) ;
F_117 ( & V_56 -> V_209 ) ;
V_208 = V_56 -> V_208 ;
F_44 ( V_110 , V_56 , V_56 -> V_130 ) ;
if ( V_2 -> V_95 )
V_56 -> V_208 = V_208 ;
F_118 ( & V_56 -> V_209 ) ;
F_52 ( V_110 ) ;
F_53 ( V_110 ) ;
return 0 ;
}

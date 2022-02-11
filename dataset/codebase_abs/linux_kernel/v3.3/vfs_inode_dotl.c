static T_1 F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 == NULL ) ;
if ( V_2 -> V_3 & V_4 ) {
return V_2 -> V_5 ;
}
return F_3 () ;
}
static struct V_6 * F_4 ( struct V_1 * V_1 )
{
struct V_6 * V_6 ;
F_5 ( & V_1 -> V_7 ) ;
F_2 ( F_6 ( V_1 -> V_3 ) && ! F_7 ( & V_1 -> V_8 ) ) ;
V_6 = F_8 ( V_1 -> V_8 . V_9 , struct V_6 , V_10 ) ;
F_9 ( & V_1 -> V_7 ) ;
return V_6 ;
}
static int F_10 ( struct V_1 * V_1 , void * V_11 )
{
struct V_12 * V_13 = F_11 ( V_1 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_11 ;
if ( ( V_1 -> V_3 & V_16 ) != ( V_15 -> V_17 & V_16 ) )
return 0 ;
if ( V_1 -> V_18 != V_15 -> V_19 )
return 0 ;
if ( memcmp ( & V_13 -> V_20 . V_21 ,
& V_15 -> V_20 . V_21 , sizeof( V_13 -> V_20 . V_21 ) ) )
return 0 ;
if ( V_13 -> V_20 . type != V_15 -> V_20 . type )
return 0 ;
return 1 ;
}
static int F_12 ( struct V_1 * V_1 , void * V_11 )
{
return 0 ;
}
static int F_13 ( struct V_1 * V_1 , void * V_11 )
{
struct V_12 * V_13 = F_11 ( V_1 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_11 ;
memcpy ( & V_13 -> V_20 , & V_15 -> V_20 , sizeof( V_15 -> V_20 ) ) ;
V_1 -> V_18 = V_15 -> V_19 ;
return 0 ;
}
static struct V_1 * F_14 ( struct V_22 * V_23 ,
struct V_24 * V_20 ,
struct V_25 * V_26 ,
struct V_14 * V_15 ,
int V_27 )
{
int V_28 ;
unsigned long V_29 ;
struct V_1 * V_1 ;
struct V_30 * V_31 = V_23 -> V_32 ;
int (* F_15)( struct V_1 * , void * );
if ( V_27 )
F_15 = F_12 ;
else
F_15 = F_10 ;
V_29 = F_16 ( V_20 ) ;
V_1 = F_17 ( V_23 , V_29 , F_15 , F_13 , V_15 ) ;
if ( ! V_1 )
return F_18 ( - V_33 ) ;
if ( ! ( V_1 -> V_34 & V_35 ) )
return V_1 ;
V_1 -> V_29 = V_29 ;
V_28 = F_19 ( V_31 , V_1 ,
V_15 -> V_17 , F_20 ( V_15 -> V_36 ) ) ;
if ( V_28 )
goto error;
F_21 ( V_15 , V_1 ) ;
#ifdef F_22
F_23 ( V_1 ) ;
#endif
V_28 = F_24 ( V_1 , V_26 ) ;
if ( V_28 )
goto error;
F_25 ( V_1 ) ;
return V_1 ;
error:
F_25 ( V_1 ) ;
F_26 ( V_1 ) ;
return F_18 ( V_28 ) ;
}
struct V_1 *
F_27 ( struct V_30 * V_31 , struct V_25 * V_26 ,
struct V_22 * V_23 , int V_27 )
{
struct V_14 * V_15 ;
struct V_1 * V_1 = NULL ;
V_15 = F_28 ( V_26 , V_37 | V_38 ) ;
if ( F_29 ( V_15 ) )
return F_30 ( V_15 ) ;
V_1 = F_14 ( V_23 , & V_15 -> V_20 , V_26 , V_15 , V_27 ) ;
F_31 ( V_15 ) ;
return V_1 ;
}
static int F_32 ( int V_39 )
{
int V_40 ;
int V_41 = 0 ;
struct V_42 V_43 [] = {
{ V_44 , V_45 } ,
{ V_46 , V_47 } ,
{ V_48 , V_49 } ,
{ V_50 , V_51 } ,
{ V_52 , V_53 } ,
{ V_54 , V_55 } ,
{ V_56 , V_57 } ,
{ V_58 , V_59 } ,
{ V_60 , V_61 } ,
{ V_62 , V_63 } ,
{ V_64 , V_65 } ,
{ V_66 , V_67 } ,
{ V_68 , V_69 } ,
{ V_70 , V_71 } ,
{ V_72 , V_73 } ,
} ;
for ( V_40 = 0 ; V_40 < F_33 ( V_43 ) ; V_40 ++ ) {
if ( V_39 & V_43 [ V_40 ] . V_74 )
V_41 |= V_43 [ V_40 ] . V_75 ;
}
return V_41 ;
}
int F_34 ( int V_39 )
{
int V_41 = 0 ;
V_41 |= V_39 & V_76 ;
V_41 |= F_32 ( V_39 ) ;
return V_41 ;
}
static int
F_35 ( struct V_1 * V_77 , struct V_6 * V_6 , T_2 V_78 ,
struct V_79 * V_80 )
{
int V_81 = 0 ;
T_1 V_82 ;
int V_39 ;
T_2 V_83 ;
char * V_84 = NULL ;
struct V_85 * V_86 ;
struct V_24 V_20 ;
struct V_1 * V_1 ;
struct V_25 * V_26 = NULL ;
struct V_12 * V_13 ;
struct V_25 * V_87 , * V_88 , * V_89 ;
struct V_30 * V_31 ;
struct V_90 * V_91 = NULL , * V_92 = NULL ;
V_31 = F_36 ( V_77 ) ;
if ( V_80 )
V_39 = V_80 -> V_93 . V_94 . V_39 ;
else {
return F_37 ( V_77 , V_6 , V_78 , 0 ) ;
}
V_84 = ( char * ) V_6 -> V_95 . V_84 ;
F_38 ( V_96 , L_1 ,
V_84 , V_39 , V_78 ) ;
V_87 = F_39 ( V_6 -> V_97 ) ;
if ( F_29 ( V_87 ) ) {
V_81 = F_40 ( V_87 ) ;
F_38 ( V_96 , L_2 , V_81 ) ;
return V_81 ;
}
V_88 = F_41 ( V_87 , 0 , NULL , 1 ) ;
if ( F_29 ( V_88 ) ) {
V_81 = F_40 ( V_88 ) ;
F_38 ( V_96 , L_3 , V_81 ) ;
return V_81 ;
}
V_82 = F_1 ( V_77 ) ;
V_83 = V_78 ;
V_81 = F_42 ( V_77 , & V_83 , & V_92 , & V_91 ) ;
if ( V_81 ) {
F_38 ( V_96 , L_4 ,
V_81 ) ;
goto error;
}
V_81 = F_43 ( V_88 , V_84 , F_34 ( V_39 ) ,
V_83 , V_82 , & V_20 ) ;
if ( V_81 < 0 ) {
F_38 ( V_96 , L_5 ,
V_81 ) ;
goto error;
}
F_44 ( V_77 ) ;
V_26 = F_41 ( V_87 , 1 , & V_84 , 1 ) ;
if ( F_29 ( V_26 ) ) {
V_81 = F_40 ( V_26 ) ;
F_38 ( V_96 , L_3 , V_81 ) ;
V_26 = NULL ;
goto error;
}
V_1 = F_45 ( V_31 , V_26 , V_77 -> V_98 ) ;
if ( F_29 ( V_1 ) ) {
V_81 = F_40 ( V_1 ) ;
F_38 ( V_96 , L_6 , V_81 ) ;
goto error;
}
V_81 = F_46 ( V_6 , V_26 ) ;
if ( V_81 < 0 )
goto error;
F_47 ( V_6 , V_1 ) ;
F_48 ( V_6 , & V_92 , & V_91 ) ;
V_13 = F_11 ( V_1 ) ;
F_49 ( & V_13 -> V_99 ) ;
if ( V_31 -> V_100 && ! V_13 -> V_101 &&
( ( V_39 & V_76 ) != V_102 ) ) {
V_89 = F_50 ( V_6 ) ;
if ( F_29 ( V_89 ) ) {
V_81 = F_40 ( V_89 ) ;
F_51 ( & V_13 -> V_99 ) ;
goto V_103;
}
V_13 -> V_101 = ( void * ) V_89 ;
}
F_51 ( & V_13 -> V_99 ) ;
V_86 = F_52 ( V_80 , V_6 , V_104 ) ;
if ( F_29 ( V_86 ) ) {
V_81 = F_40 ( V_86 ) ;
goto V_103;
}
V_86 -> V_105 = V_88 ;
#ifdef F_22
if ( V_31 -> V_100 )
F_53 ( V_1 , V_86 ) ;
#endif
return 0 ;
error:
if ( V_26 )
F_54 ( V_26 ) ;
V_103:
if ( V_88 )
F_54 ( V_88 ) ;
F_48 ( NULL , & V_92 , & V_91 ) ;
return V_81 ;
}
static int F_55 ( struct V_1 * V_77 ,
struct V_6 * V_6 , T_2 V_78 )
{
int V_81 ;
struct V_30 * V_31 ;
struct V_25 * V_26 = NULL , * V_87 = NULL ;
T_1 V_82 ;
char * V_84 ;
T_2 V_83 ;
struct V_1 * V_1 ;
struct V_24 V_20 ;
struct V_6 * V_106 ;
struct V_90 * V_92 = NULL , * V_91 = NULL ;
F_38 ( V_96 , L_7 , V_6 -> V_95 . V_84 ) ;
V_81 = 0 ;
V_31 = F_36 ( V_77 ) ;
V_78 |= V_107 ;
if ( V_77 -> V_3 & V_4 )
V_78 |= V_4 ;
V_106 = F_4 ( V_77 ) ;
V_87 = F_39 ( V_106 ) ;
if ( F_29 ( V_87 ) ) {
V_81 = F_40 ( V_87 ) ;
F_38 ( V_96 , L_2 , V_81 ) ;
V_87 = NULL ;
goto error;
}
V_82 = F_1 ( V_77 ) ;
V_83 = V_78 ;
V_81 = F_42 ( V_77 , & V_83 , & V_92 , & V_91 ) ;
if ( V_81 ) {
F_38 ( V_96 , L_8 ,
V_81 ) ;
goto error;
}
V_84 = ( char * ) V_6 -> V_95 . V_84 ;
V_81 = F_56 ( V_87 , V_84 , V_83 , V_82 , & V_20 ) ;
if ( V_81 < 0 )
goto error;
if ( V_31 -> V_100 == V_108 || V_31 -> V_100 == V_109 ) {
V_26 = F_41 ( V_87 , 1 , & V_84 , 1 ) ;
if ( F_29 ( V_26 ) ) {
V_81 = F_40 ( V_26 ) ;
F_38 ( V_96 , L_3 ,
V_81 ) ;
V_26 = NULL ;
goto error;
}
V_1 = F_45 ( V_31 , V_26 , V_77 -> V_98 ) ;
if ( F_29 ( V_1 ) ) {
V_81 = F_40 ( V_1 ) ;
F_38 ( V_96 , L_6 ,
V_81 ) ;
goto error;
}
V_81 = F_46 ( V_6 , V_26 ) ;
if ( V_81 < 0 )
goto error;
F_47 ( V_6 , V_1 ) ;
V_26 = NULL ;
} else {
V_1 = F_57 ( V_77 -> V_98 , V_83 , 0 ) ;
if ( F_29 ( V_1 ) ) {
V_81 = F_40 ( V_1 ) ;
goto error;
}
F_47 ( V_6 , V_1 ) ;
}
F_48 ( V_6 , & V_92 , & V_91 ) ;
F_58 ( V_77 ) ;
F_44 ( V_77 ) ;
error:
if ( V_26 )
F_54 ( V_26 ) ;
F_48 ( NULL , & V_92 , & V_91 ) ;
return V_81 ;
}
static int
F_59 ( struct V_110 * V_111 , struct V_6 * V_6 ,
struct V_112 * V_113 )
{
int V_81 ;
struct V_30 * V_31 ;
struct V_25 * V_26 ;
struct V_14 * V_15 ;
F_38 ( V_96 , L_9 , V_6 ) ;
V_81 = - V_114 ;
V_31 = F_60 ( V_6 ) ;
if ( V_31 -> V_100 == V_108 || V_31 -> V_100 == V_109 ) {
F_61 ( V_6 -> V_115 , V_113 ) ;
return 0 ;
}
V_26 = F_39 ( V_6 ) ;
if ( F_29 ( V_26 ) )
return F_40 ( V_26 ) ;
V_15 = F_28 ( V_26 , V_116 ) ;
if ( F_29 ( V_15 ) )
return F_40 ( V_15 ) ;
F_21 ( V_15 , V_6 -> V_115 ) ;
F_61 ( V_6 -> V_115 , V_113 ) ;
V_113 -> V_117 = V_15 -> V_118 ;
F_31 ( V_15 ) ;
return 0 ;
}
static int F_62 ( int V_119 )
{
int V_40 ;
int V_120 = 0 ;
struct V_121 V_121 [] = {
{ V_122 , V_123 } ,
{ V_124 , V_125 } ,
{ V_126 , V_127 } ,
{ V_128 , V_129 } ,
{ V_130 , V_131 } ,
{ V_132 , V_133 } ,
{ V_134 , V_135 } ,
{ V_136 , V_137 } ,
{ V_138 , V_139 } ,
} ;
for ( V_40 = 0 ; V_40 < F_33 ( V_121 ) ; V_40 ++ ) {
if ( V_119 & V_121 [ V_40 ] . V_119 )
V_120 |= V_121 [ V_40 ] . V_120 ;
}
return V_120 ;
}
int F_63 ( struct V_6 * V_6 , struct V_140 * V_140 )
{
int V_28 ;
struct V_30 * V_31 ;
struct V_25 * V_26 ;
struct V_141 V_142 ;
F_38 ( V_96 , L_10 ) ;
V_28 = F_64 ( V_6 -> V_115 , V_140 ) ;
if ( V_28 )
return V_28 ;
V_142 . V_143 = F_62 ( V_140 -> V_144 ) ;
V_142 . V_83 = V_140 -> V_145 ;
V_142 . V_146 = V_140 -> V_147 ;
V_142 . V_82 = V_140 -> V_148 ;
V_142 . V_149 = V_140 -> V_150 ;
V_142 . V_151 = V_140 -> V_152 . V_153 ;
V_142 . V_154 = V_140 -> V_152 . V_155 ;
V_142 . V_156 = V_140 -> V_157 . V_153 ;
V_142 . V_158 = V_140 -> V_157 . V_155 ;
V_28 = - V_114 ;
V_31 = F_60 ( V_6 ) ;
V_26 = F_39 ( V_6 ) ;
if ( F_29 ( V_26 ) )
return F_40 ( V_26 ) ;
if ( F_65 ( V_6 -> V_115 -> V_3 ) )
F_66 ( V_6 -> V_115 -> V_159 ) ;
V_28 = F_67 ( V_26 , & V_142 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( ( V_140 -> V_144 & V_128 ) &&
V_140 -> V_150 != F_68 ( V_6 -> V_115 ) )
F_69 ( V_6 -> V_115 , V_140 -> V_150 ) ;
F_44 ( V_6 -> V_115 ) ;
F_70 ( V_6 -> V_115 , V_140 ) ;
F_71 ( V_6 -> V_115 ) ;
if ( V_140 -> V_144 & V_122 ) {
V_28 = F_72 ( V_6 ) ;
if ( V_28 < 0 )
return V_28 ;
}
return 0 ;
}
void
F_21 ( struct V_14 * V_113 , struct V_1 * V_1 )
{
T_2 V_83 ;
struct V_12 * V_13 = F_11 ( V_1 ) ;
if ( ( V_113 -> V_160 & V_37 ) == V_37 ) {
V_1 -> V_161 . V_153 = V_113 -> V_162 ;
V_1 -> V_161 . V_155 = V_113 -> V_163 ;
V_1 -> V_164 . V_153 = V_113 -> V_165 ;
V_1 -> V_164 . V_155 = V_113 -> V_166 ;
V_1 -> V_167 . V_153 = V_113 -> V_168 ;
V_1 -> V_167 . V_155 = V_113 -> V_169 ;
V_1 -> V_170 = V_113 -> V_171 ;
V_1 -> V_5 = V_113 -> V_172 ;
F_73 ( V_1 , V_113 -> V_173 ) ;
V_83 = V_113 -> V_17 & V_174 ;
V_83 |= V_1 -> V_3 & ~ V_174 ;
V_1 -> V_3 = V_83 ;
F_74 ( V_1 , V_113 -> V_175 ) ;
V_1 -> V_176 = V_113 -> V_177 ;
} else {
if ( V_113 -> V_160 & V_178 ) {
V_1 -> V_161 . V_153 = V_113 -> V_162 ;
V_1 -> V_161 . V_155 = V_113 -> V_163 ;
}
if ( V_113 -> V_160 & V_179 ) {
V_1 -> V_164 . V_153 = V_113 -> V_165 ;
V_1 -> V_164 . V_155 = V_113 -> V_166 ;
}
if ( V_113 -> V_160 & V_180 ) {
V_1 -> V_167 . V_153 = V_113 -> V_168 ;
V_1 -> V_167 . V_155 = V_113 -> V_169 ;
}
if ( V_113 -> V_160 & V_181 )
V_1 -> V_170 = V_113 -> V_171 ;
if ( V_113 -> V_160 & V_182 )
V_1 -> V_5 = V_113 -> V_172 ;
if ( V_113 -> V_160 & V_183 )
F_73 ( V_1 , V_113 -> V_173 ) ;
if ( V_113 -> V_160 & V_184 ) {
V_1 -> V_3 = V_113 -> V_17 ;
if ( ( F_75 ( V_1 -> V_3 ) ) ||
( F_76 ( V_1 -> V_3 ) ) )
F_77 ( V_1 , V_1 -> V_3 ,
V_1 -> V_185 ) ;
}
if ( V_113 -> V_160 & V_186 )
V_1 -> V_185 = F_20 ( V_113 -> V_36 ) ;
if ( V_113 -> V_160 & V_187 )
F_74 ( V_1 , V_113 -> V_175 ) ;
if ( V_113 -> V_160 & V_188 )
V_1 -> V_176 = V_113 -> V_177 ;
}
if ( V_113 -> V_160 & V_38 )
V_1 -> V_18 = V_113 -> V_19 ;
V_13 -> V_189 &= ~ V_190 ;
}
static int
F_78 ( struct V_1 * V_77 , struct V_6 * V_6 ,
const char * V_191 )
{
int V_81 ;
T_1 V_82 ;
char * V_84 ;
struct V_24 V_20 ;
struct V_1 * V_1 ;
struct V_25 * V_87 ;
struct V_25 * V_26 = NULL ;
struct V_30 * V_31 ;
V_84 = ( char * ) V_6 -> V_95 . V_84 ;
F_38 ( V_96 , L_11 , V_77 -> V_29 , V_84 , V_191 ) ;
V_31 = F_36 ( V_77 ) ;
V_87 = F_39 ( V_6 -> V_97 ) ;
if ( F_29 ( V_87 ) ) {
V_81 = F_40 ( V_87 ) ;
F_38 ( V_96 , L_2 , V_81 ) ;
return V_81 ;
}
V_82 = F_1 ( V_77 ) ;
V_81 = F_79 ( V_87 , V_84 , ( char * ) V_191 , V_82 , & V_20 ) ;
if ( V_81 < 0 ) {
F_38 ( V_96 , L_12 , V_81 ) ;
goto error;
}
F_44 ( V_77 ) ;
if ( V_31 -> V_100 ) {
V_26 = F_41 ( V_87 , 1 , & V_84 , 1 ) ;
if ( F_29 ( V_26 ) ) {
V_81 = F_40 ( V_26 ) ;
F_38 ( V_96 , L_3 ,
V_81 ) ;
V_26 = NULL ;
goto error;
}
V_1 = F_45 ( V_31 , V_26 , V_77 -> V_98 ) ;
if ( F_29 ( V_1 ) ) {
V_81 = F_40 ( V_1 ) ;
F_38 ( V_96 , L_6 ,
V_81 ) ;
goto error;
}
V_81 = F_46 ( V_6 , V_26 ) ;
if ( V_81 < 0 )
goto error;
F_47 ( V_6 , V_1 ) ;
V_26 = NULL ;
} else {
V_1 = F_57 ( V_77 -> V_98 , V_192 , 0 ) ;
if ( F_29 ( V_1 ) ) {
V_81 = F_40 ( V_1 ) ;
goto error;
}
F_47 ( V_6 , V_1 ) ;
}
error:
if ( V_26 )
F_54 ( V_26 ) ;
return V_81 ;
}
static int
F_80 ( struct V_6 * V_193 , struct V_1 * V_77 ,
struct V_6 * V_6 )
{
int V_81 ;
char * V_84 ;
struct V_6 * V_106 ;
struct V_25 * V_87 , * V_194 ;
struct V_30 * V_31 ;
F_38 ( V_96 , L_13 ,
V_77 -> V_29 , V_193 -> V_95 . V_84 , V_6 -> V_95 . V_84 ) ;
V_31 = F_36 ( V_77 ) ;
V_106 = F_4 ( V_77 ) ;
V_87 = F_39 ( V_106 ) ;
if ( F_29 ( V_87 ) )
return F_40 ( V_87 ) ;
V_194 = F_39 ( V_193 ) ;
if ( F_29 ( V_194 ) )
return F_40 ( V_194 ) ;
V_84 = ( char * ) V_6 -> V_95 . V_84 ;
V_81 = F_81 ( V_87 , V_194 , ( char * ) V_6 -> V_95 . V_84 ) ;
if ( V_81 < 0 ) {
F_38 ( V_96 , L_14 , V_81 ) ;
return V_81 ;
}
F_44 ( V_77 ) ;
if ( V_31 -> V_100 == V_108 || V_31 -> V_100 == V_109 ) {
struct V_25 * V_26 ;
V_26 = F_39 ( V_193 ) ;
if ( F_29 ( V_26 ) )
return F_40 ( V_26 ) ;
F_82 ( V_26 , V_193 -> V_115 ) ;
}
F_83 ( V_193 -> V_115 ) ;
F_47 ( V_6 , V_193 -> V_115 ) ;
return V_81 ;
}
static int
F_37 ( struct V_1 * V_77 , struct V_6 * V_6 , T_2 V_78 ,
T_3 V_195 )
{
int V_81 ;
T_1 V_82 ;
char * V_84 ;
T_2 V_83 ;
struct V_30 * V_31 ;
struct V_25 * V_26 = NULL , * V_87 = NULL ;
struct V_1 * V_1 ;
struct V_24 V_20 ;
struct V_6 * V_106 ;
struct V_90 * V_92 = NULL , * V_91 = NULL ;
F_38 ( V_96 , L_15 ,
V_77 -> V_29 , V_6 -> V_95 . V_84 , V_78 ,
F_84 ( V_195 ) , F_85 ( V_195 ) ) ;
if ( ! F_86 ( V_195 ) )
return - V_196 ;
V_31 = F_36 ( V_77 ) ;
V_106 = F_4 ( V_77 ) ;
V_87 = F_39 ( V_106 ) ;
if ( F_29 ( V_87 ) ) {
V_81 = F_40 ( V_87 ) ;
F_38 ( V_96 , L_2 , V_81 ) ;
V_87 = NULL ;
goto error;
}
V_82 = F_1 ( V_77 ) ;
V_83 = V_78 ;
V_81 = F_42 ( V_77 , & V_83 , & V_92 , & V_91 ) ;
if ( V_81 ) {
F_38 ( V_96 , L_16 ,
V_81 ) ;
goto error;
}
V_84 = ( char * ) V_6 -> V_95 . V_84 ;
V_81 = F_87 ( V_87 , V_84 , V_83 , V_195 , V_82 , & V_20 ) ;
if ( V_81 < 0 )
goto error;
F_44 ( V_77 ) ;
if ( V_31 -> V_100 == V_108 || V_31 -> V_100 == V_109 ) {
V_26 = F_41 ( V_87 , 1 , & V_84 , 1 ) ;
if ( F_29 ( V_26 ) ) {
V_81 = F_40 ( V_26 ) ;
F_38 ( V_96 , L_3 ,
V_81 ) ;
V_26 = NULL ;
goto error;
}
V_1 = F_45 ( V_31 , V_26 , V_77 -> V_98 ) ;
if ( F_29 ( V_1 ) ) {
V_81 = F_40 ( V_1 ) ;
F_38 ( V_96 , L_6 ,
V_81 ) ;
goto error;
}
V_81 = F_46 ( V_6 , V_26 ) ;
if ( V_81 < 0 )
goto error;
F_47 ( V_6 , V_1 ) ;
V_26 = NULL ;
} else {
V_1 = F_57 ( V_77 -> V_98 , V_83 , V_195 ) ;
if ( F_29 ( V_1 ) ) {
V_81 = F_40 ( V_1 ) ;
goto error;
}
F_47 ( V_6 , V_1 ) ;
}
F_48 ( V_6 , & V_92 , & V_91 ) ;
error:
if ( V_26 )
F_54 ( V_26 ) ;
F_48 ( NULL , & V_92 , & V_91 ) ;
return V_81 ;
}
static void *
F_88 ( struct V_6 * V_6 , struct V_79 * V_80 )
{
int V_28 ;
struct V_25 * V_26 ;
char * V_197 = F_89 () ;
char * V_198 ;
F_38 ( V_96 , L_17 , V_6 -> V_95 . V_84 ) ;
if ( ! V_197 ) {
V_197 = F_18 ( - V_33 ) ;
goto V_199;
}
V_26 = F_39 ( V_6 ) ;
if ( F_29 ( V_26 ) ) {
F_90 ( V_197 ) ;
V_197 = F_30 ( V_26 ) ;
goto V_199;
}
V_28 = F_91 ( V_26 , & V_198 ) ;
if ( ! V_28 ) {
strcpy ( V_197 , V_198 ) ;
F_31 ( V_198 ) ;
goto V_199;
}
F_90 ( V_197 ) ;
V_197 = F_18 ( V_28 ) ;
V_199:
F_92 ( V_80 , V_197 ) ;
return NULL ;
}
int F_82 ( struct V_25 * V_26 , struct V_1 * V_1 )
{
T_4 V_200 ;
struct V_14 * V_15 ;
struct V_30 * V_31 ;
V_31 = F_36 ( V_1 ) ;
V_15 = F_28 ( V_26 , V_116 ) ;
if ( F_29 ( V_15 ) )
return F_40 ( V_15 ) ;
if ( ( V_1 -> V_3 & V_16 ) != ( V_15 -> V_17 & V_16 ) )
goto V_201;
F_5 ( & V_1 -> V_7 ) ;
V_200 = V_1 -> V_200 ;
F_21 ( V_15 , V_1 ) ;
if ( V_31 -> V_100 )
V_1 -> V_200 = V_200 ;
F_9 ( & V_1 -> V_7 ) ;
V_201:
F_31 ( V_15 ) ;
return 0 ;
}

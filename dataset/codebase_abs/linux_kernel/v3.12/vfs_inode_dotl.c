static T_1 F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 == NULL ) ;
if ( V_2 -> V_3 & V_4 ) {
return V_2 -> V_5 ;
}
return F_3 () ;
}
static int F_4 ( struct V_1 * V_1 , void * V_6 )
{
struct V_7 * V_8 = F_5 ( V_1 ) ;
struct V_9 * V_10 = (struct V_9 * ) V_6 ;
if ( ( V_1 -> V_3 & V_11 ) != ( V_10 -> V_12 & V_11 ) )
return 0 ;
if ( V_1 -> V_13 != V_10 -> V_14 )
return 0 ;
if ( memcmp ( & V_8 -> V_15 . V_16 ,
& V_10 -> V_15 . V_16 , sizeof( V_8 -> V_15 . V_16 ) ) )
return 0 ;
if ( V_8 -> V_15 . type != V_10 -> V_15 . type )
return 0 ;
return 1 ;
}
static int F_6 ( struct V_1 * V_1 , void * V_6 )
{
return 0 ;
}
static int F_7 ( struct V_1 * V_1 , void * V_6 )
{
struct V_7 * V_8 = F_5 ( V_1 ) ;
struct V_9 * V_10 = (struct V_9 * ) V_6 ;
memcpy ( & V_8 -> V_15 , & V_10 -> V_15 , sizeof( V_10 -> V_15 ) ) ;
V_1 -> V_13 = V_10 -> V_14 ;
return 0 ;
}
static struct V_1 * F_8 ( struct V_17 * V_18 ,
struct V_19 * V_15 ,
struct V_20 * V_21 ,
struct V_9 * V_10 ,
int V_22 )
{
int V_23 ;
unsigned long V_24 ;
struct V_1 * V_1 ;
struct V_25 * V_26 = V_18 -> V_27 ;
int (* F_9)( struct V_1 * , void * );
if ( V_22 )
F_9 = F_6 ;
else
F_9 = F_4 ;
V_24 = F_10 ( V_15 ) ;
V_1 = F_11 ( V_18 , V_24 , F_9 , F_7 , V_10 ) ;
if ( ! V_1 )
return F_12 ( - V_28 ) ;
if ( ! ( V_1 -> V_29 & V_30 ) )
return V_1 ;
V_1 -> V_24 = V_24 ;
V_23 = F_13 ( V_26 , V_1 ,
V_10 -> V_12 , F_14 ( V_10 -> V_31 ) ) ;
if ( V_23 )
goto error;
F_15 ( V_10 , V_1 ) ;
#ifdef F_16
F_17 ( V_1 ) ;
#endif
V_23 = F_18 ( V_1 , V_21 ) ;
if ( V_23 )
goto error;
F_19 ( V_1 ) ;
return V_1 ;
error:
F_19 ( V_1 ) ;
F_20 ( V_1 ) ;
return F_12 ( V_23 ) ;
}
struct V_1 *
F_21 ( struct V_25 * V_26 , struct V_20 * V_21 ,
struct V_17 * V_18 , int V_22 )
{
struct V_9 * V_10 ;
struct V_1 * V_1 = NULL ;
V_10 = F_22 ( V_21 , V_32 | V_33 ) ;
if ( F_23 ( V_10 ) )
return F_24 ( V_10 ) ;
V_1 = F_8 ( V_18 , & V_10 -> V_15 , V_21 , V_10 , V_22 ) ;
F_25 ( V_10 ) ;
return V_1 ;
}
static int F_26 ( int V_34 )
{
int V_35 ;
int V_36 = 0 ;
struct V_37 V_38 [] = {
{ V_39 , V_40 } ,
{ V_41 , V_42 } ,
{ V_43 , V_44 } ,
{ V_45 , V_46 } ,
{ V_47 , V_48 } ,
{ V_49 , V_50 } ,
{ V_51 , V_52 } ,
{ V_53 , V_54 } ,
{ V_55 , V_56 } ,
{ V_57 , V_58 } ,
{ V_59 , V_60 } ,
{ V_61 , V_62 } ,
{ V_63 , V_64 } ,
{ V_65 , V_66 } ,
} ;
for ( V_35 = 0 ; V_35 < F_27 ( V_38 ) ; V_35 ++ ) {
if ( V_34 & V_38 [ V_35 ] . V_67 )
V_36 |= V_38 [ V_35 ] . V_68 ;
}
return V_36 ;
}
int F_28 ( int V_34 )
{
int V_36 = 0 ;
V_36 |= V_34 & V_69 ;
V_36 |= F_26 ( V_34 ) ;
return V_36 ;
}
static int
F_29 ( struct V_1 * V_70 , struct V_71 * V_71 , T_2 V_72 ,
bool V_73 )
{
return F_30 ( V_70 , V_71 , V_72 , 0 ) ;
}
static int
F_31 ( struct V_1 * V_70 , struct V_71 * V_71 ,
struct V_74 * V_74 , unsigned V_34 , T_2 V_72 ,
int * V_75 )
{
int V_76 = 0 ;
T_1 V_77 ;
T_2 V_78 ;
char * V_79 = NULL ;
struct V_19 V_15 ;
struct V_1 * V_1 ;
struct V_20 * V_21 = NULL ;
struct V_7 * V_8 ;
struct V_20 * V_80 , * V_81 , * V_82 ;
struct V_25 * V_26 ;
struct V_83 * V_84 = NULL , * V_85 = NULL ;
struct V_71 * V_86 = NULL ;
if ( F_32 ( V_71 ) ) {
V_86 = F_33 ( V_70 , V_71 , 0 ) ;
if ( F_23 ( V_86 ) )
return F_34 ( V_86 ) ;
if ( V_86 )
V_71 = V_86 ;
}
if ( ! ( V_34 & V_39 ) || V_71 -> V_87 )
return F_35 ( V_74 , V_86 ) ;
V_26 = F_36 ( V_70 ) ;
V_79 = ( char * ) V_71 -> V_88 . V_79 ;
F_37 ( V_89 , L_1 ,
V_79 , V_34 , V_72 ) ;
V_80 = F_38 ( V_71 -> V_90 ) ;
if ( F_23 ( V_80 ) ) {
V_76 = F_34 ( V_80 ) ;
F_37 ( V_89 , L_2 , V_76 ) ;
goto V_91;
}
V_81 = F_39 ( V_80 , 0 , NULL , 1 ) ;
if ( F_23 ( V_81 ) ) {
V_76 = F_34 ( V_81 ) ;
F_37 ( V_89 , L_3 , V_76 ) ;
goto V_91;
}
V_77 = F_1 ( V_70 ) ;
V_78 = V_72 ;
V_76 = F_40 ( V_70 , & V_78 , & V_85 , & V_84 ) ;
if ( V_76 ) {
F_37 ( V_89 , L_4 ,
V_76 ) ;
goto error;
}
V_76 = F_41 ( V_81 , V_79 , F_28 ( V_34 ) ,
V_78 , V_77 , & V_15 ) ;
if ( V_76 < 0 ) {
F_37 ( V_89 , L_5 ,
V_76 ) ;
goto error;
}
F_42 ( V_70 ) ;
V_21 = F_39 ( V_80 , 1 , & V_79 , 1 ) ;
if ( F_23 ( V_21 ) ) {
V_76 = F_34 ( V_21 ) ;
F_37 ( V_89 , L_3 , V_76 ) ;
V_21 = NULL ;
goto error;
}
V_1 = F_43 ( V_26 , V_21 , V_70 -> V_92 ) ;
if ( F_23 ( V_1 ) ) {
V_76 = F_34 ( V_1 ) ;
F_37 ( V_89 , L_6 , V_76 ) ;
goto error;
}
F_44 ( V_1 , V_21 , V_85 , V_84 ) ;
F_45 ( V_71 , V_21 ) ;
F_46 ( V_71 , V_1 ) ;
V_8 = F_5 ( V_1 ) ;
F_47 ( & V_8 -> V_93 ) ;
if ( V_26 -> V_94 && ! V_8 -> V_95 &&
( ( V_34 & V_69 ) != V_96 ) ) {
V_82 = F_48 ( V_71 ) ;
if ( F_23 ( V_82 ) ) {
V_76 = F_34 ( V_82 ) ;
F_49 ( & V_8 -> V_93 ) ;
goto V_97;
}
V_8 -> V_95 = ( void * ) V_82 ;
}
F_49 ( & V_8 -> V_93 ) ;
V_76 = F_50 ( V_74 , V_71 , V_98 , V_75 ) ;
if ( V_76 )
goto V_97;
V_74 -> V_99 = V_81 ;
#ifdef F_16
if ( V_26 -> V_94 )
F_51 ( V_1 , V_74 ) ;
#endif
* V_75 |= V_100 ;
V_91:
F_52 ( V_85 , V_84 ) ;
F_53 ( V_86 ) ;
return V_76 ;
error:
if ( V_21 )
F_54 ( V_21 ) ;
V_97:
if ( V_81 )
F_54 ( V_81 ) ;
goto V_91;
}
static int F_55 ( struct V_1 * V_70 ,
struct V_71 * V_71 , T_2 V_72 )
{
int V_76 ;
struct V_25 * V_26 ;
struct V_20 * V_21 = NULL , * V_80 = NULL ;
T_1 V_77 ;
char * V_79 ;
T_2 V_78 ;
struct V_1 * V_1 ;
struct V_19 V_15 ;
struct V_71 * V_101 ;
struct V_83 * V_85 = NULL , * V_84 = NULL ;
F_37 ( V_89 , L_7 , V_71 -> V_88 . V_79 ) ;
V_76 = 0 ;
V_26 = F_36 ( V_70 ) ;
V_72 |= V_102 ;
if ( V_70 -> V_3 & V_4 )
V_72 |= V_4 ;
V_101 = V_71 -> V_90 ;
V_80 = F_38 ( V_101 ) ;
if ( F_23 ( V_80 ) ) {
V_76 = F_34 ( V_80 ) ;
F_37 ( V_89 , L_2 , V_76 ) ;
V_80 = NULL ;
goto error;
}
V_77 = F_1 ( V_70 ) ;
V_78 = V_72 ;
V_76 = F_40 ( V_70 , & V_78 , & V_85 , & V_84 ) ;
if ( V_76 ) {
F_37 ( V_89 , L_8 ,
V_76 ) ;
goto error;
}
V_79 = ( char * ) V_71 -> V_88 . V_79 ;
V_76 = F_56 ( V_80 , V_79 , V_78 , V_77 , & V_15 ) ;
if ( V_76 < 0 )
goto error;
V_21 = F_39 ( V_80 , 1 , & V_79 , 1 ) ;
if ( F_23 ( V_21 ) ) {
V_76 = F_34 ( V_21 ) ;
F_37 ( V_89 , L_3 ,
V_76 ) ;
V_21 = NULL ;
goto error;
}
if ( V_26 -> V_94 == V_103 || V_26 -> V_94 == V_104 ) {
V_1 = F_43 ( V_26 , V_21 , V_70 -> V_92 ) ;
if ( F_23 ( V_1 ) ) {
V_76 = F_34 ( V_1 ) ;
F_37 ( V_89 , L_6 ,
V_76 ) ;
goto error;
}
F_45 ( V_71 , V_21 ) ;
F_44 ( V_1 , V_21 , V_85 , V_84 ) ;
F_46 ( V_71 , V_1 ) ;
V_21 = NULL ;
V_76 = 0 ;
} else {
V_1 = F_57 ( V_70 -> V_92 , V_78 , 0 ) ;
if ( F_23 ( V_1 ) ) {
V_76 = F_34 ( V_1 ) ;
goto error;
}
F_44 ( V_1 , V_21 , V_85 , V_84 ) ;
F_46 ( V_71 , V_1 ) ;
}
F_58 ( V_70 ) ;
F_42 ( V_70 ) ;
error:
if ( V_21 )
F_54 ( V_21 ) ;
F_52 ( V_85 , V_84 ) ;
return V_76 ;
}
static int
F_59 ( struct V_105 * V_106 , struct V_71 * V_71 ,
struct V_107 * V_108 )
{
int V_76 ;
struct V_25 * V_26 ;
struct V_20 * V_21 ;
struct V_9 * V_10 ;
F_37 ( V_89 , L_9 , V_71 ) ;
V_76 = - V_109 ;
V_26 = F_60 ( V_71 ) ;
if ( V_26 -> V_94 == V_103 || V_26 -> V_94 == V_104 ) {
F_61 ( V_71 -> V_87 , V_108 ) ;
return 0 ;
}
V_21 = F_38 ( V_71 ) ;
if ( F_23 ( V_21 ) )
return F_34 ( V_21 ) ;
V_10 = F_22 ( V_21 , V_110 ) ;
if ( F_23 ( V_10 ) )
return F_34 ( V_10 ) ;
F_15 ( V_10 , V_71 -> V_87 ) ;
F_61 ( V_71 -> V_87 , V_108 ) ;
V_108 -> V_111 = V_10 -> V_112 ;
F_25 ( V_10 ) ;
return 0 ;
}
static int F_62 ( int V_113 )
{
int V_35 ;
int V_114 = 0 ;
struct V_115 V_115 [] = {
{ V_116 , V_117 } ,
{ V_118 , V_119 } ,
{ V_120 , V_121 } ,
{ V_122 , V_123 } ,
{ V_124 , V_125 } ,
{ V_126 , V_127 } ,
{ V_128 , V_129 } ,
{ V_130 , V_131 } ,
{ V_132 , V_133 } ,
} ;
for ( V_35 = 0 ; V_35 < F_27 ( V_115 ) ; V_35 ++ ) {
if ( V_113 & V_115 [ V_35 ] . V_113 )
V_114 |= V_115 [ V_35 ] . V_114 ;
}
return V_114 ;
}
int F_63 ( struct V_71 * V_71 , struct V_134 * V_134 )
{
int V_23 ;
struct V_25 * V_26 ;
struct V_20 * V_21 ;
struct V_135 V_136 ;
struct V_1 * V_1 = V_71 -> V_87 ;
F_37 ( V_89 , L_10 ) ;
V_23 = F_64 ( V_1 , V_134 ) ;
if ( V_23 )
return V_23 ;
V_136 . V_137 = F_62 ( V_134 -> V_138 ) ;
V_136 . V_78 = V_134 -> V_139 ;
V_136 . V_140 = V_134 -> V_141 ;
V_136 . V_77 = V_134 -> V_142 ;
V_136 . V_143 = V_134 -> V_144 ;
V_136 . V_145 = V_134 -> V_146 . V_147 ;
V_136 . V_148 = V_134 -> V_146 . V_149 ;
V_136 . V_150 = V_134 -> V_151 . V_147 ;
V_136 . V_152 = V_134 -> V_151 . V_149 ;
V_23 = - V_109 ;
V_26 = F_60 ( V_71 ) ;
V_21 = F_38 ( V_71 ) ;
if ( F_23 ( V_21 ) )
return F_34 ( V_21 ) ;
if ( F_65 ( V_1 -> V_3 ) )
F_66 ( V_1 -> V_153 ) ;
V_23 = F_67 ( V_21 , & V_136 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( ( V_134 -> V_138 & V_122 ) &&
V_134 -> V_144 != F_68 ( V_1 ) )
F_69 ( V_1 , V_134 -> V_144 ) ;
F_42 ( V_1 ) ;
F_70 ( V_1 , V_134 ) ;
F_71 ( V_1 ) ;
if ( V_134 -> V_138 & V_116 ) {
V_23 = F_72 ( V_1 , V_21 ) ;
if ( V_23 < 0 )
return V_23 ;
}
return 0 ;
}
void
F_15 ( struct V_9 * V_108 , struct V_1 * V_1 )
{
T_2 V_78 ;
struct V_7 * V_8 = F_5 ( V_1 ) ;
if ( ( V_108 -> V_154 & V_32 ) == V_32 ) {
V_1 -> V_155 . V_147 = V_108 -> V_156 ;
V_1 -> V_155 . V_149 = V_108 -> V_157 ;
V_1 -> V_158 . V_147 = V_108 -> V_159 ;
V_1 -> V_158 . V_149 = V_108 -> V_160 ;
V_1 -> V_161 . V_147 = V_108 -> V_162 ;
V_1 -> V_161 . V_149 = V_108 -> V_163 ;
V_1 -> V_164 = V_108 -> V_165 ;
V_1 -> V_5 = V_108 -> V_166 ;
F_73 ( V_1 , V_108 -> V_167 ) ;
V_78 = V_108 -> V_12 & V_168 ;
V_78 |= V_1 -> V_3 & ~ V_168 ;
V_1 -> V_3 = V_78 ;
F_74 ( V_1 , V_108 -> V_169 ) ;
V_1 -> V_170 = V_108 -> V_171 ;
} else {
if ( V_108 -> V_154 & V_172 ) {
V_1 -> V_155 . V_147 = V_108 -> V_156 ;
V_1 -> V_155 . V_149 = V_108 -> V_157 ;
}
if ( V_108 -> V_154 & V_173 ) {
V_1 -> V_158 . V_147 = V_108 -> V_159 ;
V_1 -> V_158 . V_149 = V_108 -> V_160 ;
}
if ( V_108 -> V_154 & V_174 ) {
V_1 -> V_161 . V_147 = V_108 -> V_162 ;
V_1 -> V_161 . V_149 = V_108 -> V_163 ;
}
if ( V_108 -> V_154 & V_175 )
V_1 -> V_164 = V_108 -> V_165 ;
if ( V_108 -> V_154 & V_176 )
V_1 -> V_5 = V_108 -> V_166 ;
if ( V_108 -> V_154 & V_177 )
F_73 ( V_1 , V_108 -> V_167 ) ;
if ( V_108 -> V_154 & V_178 ) {
V_1 -> V_3 = V_108 -> V_12 ;
if ( ( F_75 ( V_1 -> V_3 ) ) ||
( F_76 ( V_1 -> V_3 ) ) )
F_77 ( V_1 , V_1 -> V_3 ,
V_1 -> V_179 ) ;
}
if ( V_108 -> V_154 & V_180 )
V_1 -> V_179 = F_14 ( V_108 -> V_31 ) ;
if ( V_108 -> V_154 & V_181 )
F_74 ( V_1 , V_108 -> V_169 ) ;
if ( V_108 -> V_154 & V_182 )
V_1 -> V_170 = V_108 -> V_171 ;
}
if ( V_108 -> V_154 & V_33 )
V_1 -> V_13 = V_108 -> V_14 ;
V_8 -> V_183 &= ~ V_184 ;
}
static int
F_78 ( struct V_1 * V_70 , struct V_71 * V_71 ,
const char * V_185 )
{
int V_76 ;
T_1 V_77 ;
char * V_79 ;
struct V_19 V_15 ;
struct V_1 * V_1 ;
struct V_20 * V_80 ;
struct V_20 * V_21 = NULL ;
struct V_25 * V_26 ;
V_79 = ( char * ) V_71 -> V_88 . V_79 ;
F_37 ( V_89 , L_11 , V_70 -> V_24 , V_79 , V_185 ) ;
V_26 = F_36 ( V_70 ) ;
V_80 = F_38 ( V_71 -> V_90 ) ;
if ( F_23 ( V_80 ) ) {
V_76 = F_34 ( V_80 ) ;
F_37 ( V_89 , L_2 , V_76 ) ;
return V_76 ;
}
V_77 = F_1 ( V_70 ) ;
V_76 = F_79 ( V_80 , V_79 , ( char * ) V_185 , V_77 , & V_15 ) ;
if ( V_76 < 0 ) {
F_37 ( V_89 , L_12 , V_76 ) ;
goto error;
}
F_42 ( V_70 ) ;
if ( V_26 -> V_94 ) {
V_21 = F_39 ( V_80 , 1 , & V_79 , 1 ) ;
if ( F_23 ( V_21 ) ) {
V_76 = F_34 ( V_21 ) ;
F_37 ( V_89 , L_3 ,
V_76 ) ;
V_21 = NULL ;
goto error;
}
V_1 = F_43 ( V_26 , V_21 , V_70 -> V_92 ) ;
if ( F_23 ( V_1 ) ) {
V_76 = F_34 ( V_1 ) ;
F_37 ( V_89 , L_6 ,
V_76 ) ;
goto error;
}
F_45 ( V_71 , V_21 ) ;
F_46 ( V_71 , V_1 ) ;
V_21 = NULL ;
V_76 = 0 ;
} else {
V_1 = F_57 ( V_70 -> V_92 , V_186 , 0 ) ;
if ( F_23 ( V_1 ) ) {
V_76 = F_34 ( V_1 ) ;
goto error;
}
F_46 ( V_71 , V_1 ) ;
}
error:
if ( V_21 )
F_54 ( V_21 ) ;
return V_76 ;
}
static int
F_80 ( struct V_71 * V_187 , struct V_1 * V_70 ,
struct V_71 * V_71 )
{
int V_76 ;
char * V_79 ;
struct V_71 * V_101 ;
struct V_20 * V_80 , * V_188 ;
struct V_25 * V_26 ;
F_37 ( V_89 , L_13 ,
V_70 -> V_24 , V_187 -> V_88 . V_79 , V_71 -> V_88 . V_79 ) ;
V_26 = F_36 ( V_70 ) ;
V_101 = V_71 -> V_90 ;
V_80 = F_38 ( V_101 ) ;
if ( F_23 ( V_80 ) )
return F_34 ( V_80 ) ;
V_188 = F_38 ( V_187 ) ;
if ( F_23 ( V_188 ) )
return F_34 ( V_188 ) ;
V_79 = ( char * ) V_71 -> V_88 . V_79 ;
V_76 = F_81 ( V_80 , V_188 , ( char * ) V_71 -> V_88 . V_79 ) ;
if ( V_76 < 0 ) {
F_37 ( V_89 , L_14 , V_76 ) ;
return V_76 ;
}
F_42 ( V_70 ) ;
if ( V_26 -> V_94 == V_103 || V_26 -> V_94 == V_104 ) {
struct V_20 * V_21 ;
V_21 = F_38 ( V_187 ) ;
if ( F_23 ( V_21 ) )
return F_34 ( V_21 ) ;
F_82 ( V_21 , V_187 -> V_87 ) ;
}
F_83 ( V_187 -> V_87 ) ;
F_46 ( V_71 , V_187 -> V_87 ) ;
return V_76 ;
}
static int
F_30 ( struct V_1 * V_70 , struct V_71 * V_71 , T_2 V_72 ,
T_3 V_189 )
{
int V_76 ;
T_1 V_77 ;
char * V_79 ;
T_2 V_78 ;
struct V_25 * V_26 ;
struct V_20 * V_21 = NULL , * V_80 = NULL ;
struct V_1 * V_1 ;
struct V_19 V_15 ;
struct V_71 * V_101 ;
struct V_83 * V_85 = NULL , * V_84 = NULL ;
F_37 ( V_89 , L_15 ,
V_70 -> V_24 , V_71 -> V_88 . V_79 , V_72 ,
F_84 ( V_189 ) , F_85 ( V_189 ) ) ;
if ( ! F_86 ( V_189 ) )
return - V_190 ;
V_26 = F_36 ( V_70 ) ;
V_101 = V_71 -> V_90 ;
V_80 = F_38 ( V_101 ) ;
if ( F_23 ( V_80 ) ) {
V_76 = F_34 ( V_80 ) ;
F_37 ( V_89 , L_2 , V_76 ) ;
V_80 = NULL ;
goto error;
}
V_77 = F_1 ( V_70 ) ;
V_78 = V_72 ;
V_76 = F_40 ( V_70 , & V_78 , & V_85 , & V_84 ) ;
if ( V_76 ) {
F_37 ( V_89 , L_16 ,
V_76 ) ;
goto error;
}
V_79 = ( char * ) V_71 -> V_88 . V_79 ;
V_76 = F_87 ( V_80 , V_79 , V_78 , V_189 , V_77 , & V_15 ) ;
if ( V_76 < 0 )
goto error;
F_42 ( V_70 ) ;
V_21 = F_39 ( V_80 , 1 , & V_79 , 1 ) ;
if ( F_23 ( V_21 ) ) {
V_76 = F_34 ( V_21 ) ;
F_37 ( V_89 , L_3 ,
V_76 ) ;
V_21 = NULL ;
goto error;
}
if ( V_26 -> V_94 == V_103 || V_26 -> V_94 == V_104 ) {
V_1 = F_43 ( V_26 , V_21 , V_70 -> V_92 ) ;
if ( F_23 ( V_1 ) ) {
V_76 = F_34 ( V_1 ) ;
F_37 ( V_89 , L_6 ,
V_76 ) ;
goto error;
}
F_44 ( V_1 , V_21 , V_85 , V_84 ) ;
F_45 ( V_71 , V_21 ) ;
F_46 ( V_71 , V_1 ) ;
V_21 = NULL ;
V_76 = 0 ;
} else {
V_1 = F_57 ( V_70 -> V_92 , V_78 , V_189 ) ;
if ( F_23 ( V_1 ) ) {
V_76 = F_34 ( V_1 ) ;
goto error;
}
F_44 ( V_1 , V_21 , V_85 , V_84 ) ;
F_46 ( V_71 , V_1 ) ;
}
error:
if ( V_21 )
F_54 ( V_21 ) ;
F_52 ( V_85 , V_84 ) ;
return V_76 ;
}
static void *
F_88 ( struct V_71 * V_71 , struct V_191 * V_192 )
{
int V_23 ;
struct V_20 * V_21 ;
char * V_193 = F_89 () ;
char * V_194 ;
F_37 ( V_89 , L_17 , V_71 -> V_88 . V_79 ) ;
if ( ! V_193 ) {
V_193 = F_12 ( - V_28 ) ;
goto V_195;
}
V_21 = F_38 ( V_71 ) ;
if ( F_23 ( V_21 ) ) {
F_90 ( V_193 ) ;
V_193 = F_24 ( V_21 ) ;
goto V_195;
}
V_23 = F_91 ( V_21 , & V_194 ) ;
if ( ! V_23 ) {
strcpy ( V_193 , V_194 ) ;
F_25 ( V_194 ) ;
goto V_195;
}
F_90 ( V_193 ) ;
V_193 = F_12 ( V_23 ) ;
V_195:
F_92 ( V_192 , V_193 ) ;
return NULL ;
}
int F_82 ( struct V_20 * V_21 , struct V_1 * V_1 )
{
T_4 V_196 ;
struct V_9 * V_10 ;
struct V_25 * V_26 ;
V_26 = F_36 ( V_1 ) ;
V_10 = F_22 ( V_21 , V_110 ) ;
if ( F_23 ( V_10 ) )
return F_34 ( V_10 ) ;
if ( ( V_1 -> V_3 & V_11 ) != ( V_10 -> V_12 & V_11 ) )
goto V_91;
F_93 ( & V_1 -> V_197 ) ;
V_196 = V_1 -> V_196 ;
F_15 ( V_10 , V_1 ) ;
if ( V_26 -> V_94 )
V_1 -> V_196 = V_196 ;
F_94 ( & V_1 -> V_197 ) ;
V_91:
F_25 ( V_10 ) ;
return 0 ;
}

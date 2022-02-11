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
{ V_67 , V_68 } ,
} ;
for ( V_35 = 0 ; V_35 < F_27 ( V_38 ) ; V_35 ++ ) {
if ( V_34 & V_38 [ V_35 ] . V_69 )
V_36 |= V_38 [ V_35 ] . V_70 ;
}
return V_36 ;
}
int F_28 ( int V_34 )
{
int V_36 = 0 ;
V_36 |= V_34 & V_71 ;
V_36 |= F_26 ( V_34 ) ;
return V_36 ;
}
static int
F_29 ( struct V_1 * V_72 , struct V_73 * V_73 , T_2 V_74 ,
bool V_75 )
{
return F_30 ( V_72 , V_73 , V_74 , 0 ) ;
}
static int
F_31 ( struct V_1 * V_72 , struct V_73 * V_73 ,
struct V_76 * V_76 , unsigned V_34 , T_2 V_74 ,
int * V_77 )
{
int V_78 = 0 ;
T_1 V_79 ;
T_2 V_80 ;
char * V_81 = NULL ;
struct V_19 V_15 ;
struct V_1 * V_1 ;
struct V_20 * V_21 = NULL ;
struct V_7 * V_8 ;
struct V_20 * V_82 , * V_83 , * V_84 ;
struct V_25 * V_26 ;
struct V_85 * V_86 = NULL , * V_87 = NULL ;
struct V_73 * V_88 = NULL ;
if ( F_32 ( V_73 ) ) {
V_88 = F_33 ( V_72 , V_73 , 0 ) ;
if ( F_23 ( V_88 ) )
return F_34 ( V_88 ) ;
if ( V_88 )
V_73 = V_88 ;
}
if ( ! ( V_34 & V_39 ) || V_73 -> V_89 )
return F_35 ( V_76 , V_88 ) ;
V_26 = F_36 ( V_72 ) ;
V_81 = ( char * ) V_73 -> V_90 . V_81 ;
F_37 ( V_91 , L_1 ,
V_81 , V_34 , V_74 ) ;
V_82 = F_38 ( V_73 -> V_92 ) ;
if ( F_23 ( V_82 ) ) {
V_78 = F_34 ( V_82 ) ;
F_37 ( V_91 , L_2 , V_78 ) ;
goto V_93;
}
V_83 = F_39 ( V_82 , 0 , NULL , 1 ) ;
if ( F_23 ( V_83 ) ) {
V_78 = F_34 ( V_83 ) ;
F_37 ( V_91 , L_3 , V_78 ) ;
goto V_93;
}
V_79 = F_1 ( V_72 ) ;
V_80 = V_74 ;
V_78 = F_40 ( V_72 , & V_80 , & V_87 , & V_86 ) ;
if ( V_78 ) {
F_37 ( V_91 , L_4 ,
V_78 ) ;
goto error;
}
V_78 = F_41 ( V_83 , V_81 , F_28 ( V_34 ) ,
V_80 , V_79 , & V_15 ) ;
if ( V_78 < 0 ) {
F_37 ( V_91 , L_5 ,
V_78 ) ;
goto error;
}
F_42 ( V_72 ) ;
V_21 = F_39 ( V_82 , 1 , & V_81 , 1 ) ;
if ( F_23 ( V_21 ) ) {
V_78 = F_34 ( V_21 ) ;
F_37 ( V_91 , L_3 , V_78 ) ;
V_21 = NULL ;
goto error;
}
V_1 = F_43 ( V_26 , V_21 , V_72 -> V_94 ) ;
if ( F_23 ( V_1 ) ) {
V_78 = F_34 ( V_1 ) ;
F_37 ( V_91 , L_6 , V_78 ) ;
goto error;
}
V_78 = F_44 ( V_73 , V_21 ) ;
if ( V_78 < 0 )
goto error;
F_45 ( V_73 , V_1 ) ;
F_46 ( V_73 , & V_87 , & V_86 ) ;
V_8 = F_5 ( V_1 ) ;
F_47 ( & V_8 -> V_95 ) ;
if ( V_26 -> V_96 && ! V_8 -> V_97 &&
( ( V_34 & V_71 ) != V_98 ) ) {
V_84 = F_48 ( V_73 ) ;
if ( F_23 ( V_84 ) ) {
V_78 = F_34 ( V_84 ) ;
F_49 ( & V_8 -> V_95 ) ;
goto V_99;
}
V_8 -> V_97 = ( void * ) V_84 ;
}
F_49 ( & V_8 -> V_95 ) ;
V_78 = F_50 ( V_76 , V_73 , V_100 , V_77 ) ;
if ( V_78 )
goto V_99;
V_76 -> V_101 = V_83 ;
#ifdef F_16
if ( V_26 -> V_96 )
F_51 ( V_1 , V_76 ) ;
#endif
* V_77 |= V_102 ;
V_93:
F_52 ( V_88 ) ;
return V_78 ;
error:
if ( V_21 )
F_53 ( V_21 ) ;
V_99:
if ( V_83 )
F_53 ( V_83 ) ;
F_46 ( NULL , & V_87 , & V_86 ) ;
goto V_93;
}
static int F_54 ( struct V_1 * V_72 ,
struct V_73 * V_73 , T_2 V_74 )
{
int V_78 ;
struct V_25 * V_26 ;
struct V_20 * V_21 = NULL , * V_82 = NULL ;
T_1 V_79 ;
char * V_81 ;
T_2 V_80 ;
struct V_1 * V_1 ;
struct V_19 V_15 ;
struct V_73 * V_103 ;
struct V_85 * V_87 = NULL , * V_86 = NULL ;
F_37 ( V_91 , L_7 , V_73 -> V_90 . V_81 ) ;
V_78 = 0 ;
V_26 = F_36 ( V_72 ) ;
V_74 |= V_104 ;
if ( V_72 -> V_3 & V_4 )
V_74 |= V_4 ;
V_103 = V_73 -> V_92 ;
V_82 = F_38 ( V_103 ) ;
if ( F_23 ( V_82 ) ) {
V_78 = F_34 ( V_82 ) ;
F_37 ( V_91 , L_2 , V_78 ) ;
V_82 = NULL ;
goto error;
}
V_79 = F_1 ( V_72 ) ;
V_80 = V_74 ;
V_78 = F_40 ( V_72 , & V_80 , & V_87 , & V_86 ) ;
if ( V_78 ) {
F_37 ( V_91 , L_8 ,
V_78 ) ;
goto error;
}
V_81 = ( char * ) V_73 -> V_90 . V_81 ;
V_78 = F_55 ( V_82 , V_81 , V_80 , V_79 , & V_15 ) ;
if ( V_78 < 0 )
goto error;
if ( V_26 -> V_96 == V_105 || V_26 -> V_96 == V_106 ) {
V_21 = F_39 ( V_82 , 1 , & V_81 , 1 ) ;
if ( F_23 ( V_21 ) ) {
V_78 = F_34 ( V_21 ) ;
F_37 ( V_91 , L_3 ,
V_78 ) ;
V_21 = NULL ;
goto error;
}
V_1 = F_43 ( V_26 , V_21 , V_72 -> V_94 ) ;
if ( F_23 ( V_1 ) ) {
V_78 = F_34 ( V_1 ) ;
F_37 ( V_91 , L_6 ,
V_78 ) ;
goto error;
}
V_78 = F_44 ( V_73 , V_21 ) ;
if ( V_78 < 0 )
goto error;
F_45 ( V_73 , V_1 ) ;
V_21 = NULL ;
} else {
V_1 = F_56 ( V_72 -> V_94 , V_80 , 0 ) ;
if ( F_23 ( V_1 ) ) {
V_78 = F_34 ( V_1 ) ;
goto error;
}
F_45 ( V_73 , V_1 ) ;
}
F_46 ( V_73 , & V_87 , & V_86 ) ;
F_57 ( V_72 ) ;
F_42 ( V_72 ) ;
error:
if ( V_21 )
F_53 ( V_21 ) ;
F_46 ( NULL , & V_87 , & V_86 ) ;
return V_78 ;
}
static int
F_58 ( struct V_107 * V_108 , struct V_73 * V_73 ,
struct V_109 * V_110 )
{
int V_78 ;
struct V_25 * V_26 ;
struct V_20 * V_21 ;
struct V_9 * V_10 ;
F_37 ( V_91 , L_9 , V_73 ) ;
V_78 = - V_111 ;
V_26 = F_59 ( V_73 ) ;
if ( V_26 -> V_96 == V_105 || V_26 -> V_96 == V_106 ) {
F_60 ( V_73 -> V_89 , V_110 ) ;
return 0 ;
}
V_21 = F_38 ( V_73 ) ;
if ( F_23 ( V_21 ) )
return F_34 ( V_21 ) ;
V_10 = F_22 ( V_21 , V_112 ) ;
if ( F_23 ( V_10 ) )
return F_34 ( V_10 ) ;
F_15 ( V_10 , V_73 -> V_89 ) ;
F_60 ( V_73 -> V_89 , V_110 ) ;
V_110 -> V_113 = V_10 -> V_114 ;
F_25 ( V_10 ) ;
return 0 ;
}
static int F_61 ( int V_115 )
{
int V_35 ;
int V_116 = 0 ;
struct V_117 V_117 [] = {
{ V_118 , V_119 } ,
{ V_120 , V_121 } ,
{ V_122 , V_123 } ,
{ V_124 , V_125 } ,
{ V_126 , V_127 } ,
{ V_128 , V_129 } ,
{ V_130 , V_131 } ,
{ V_132 , V_133 } ,
{ V_134 , V_135 } ,
} ;
for ( V_35 = 0 ; V_35 < F_27 ( V_117 ) ; V_35 ++ ) {
if ( V_115 & V_117 [ V_35 ] . V_115 )
V_116 |= V_117 [ V_35 ] . V_116 ;
}
return V_116 ;
}
int F_62 ( struct V_73 * V_73 , struct V_136 * V_136 )
{
int V_23 ;
struct V_25 * V_26 ;
struct V_20 * V_21 ;
struct V_137 V_138 ;
F_37 ( V_91 , L_10 ) ;
V_23 = F_63 ( V_73 -> V_89 , V_136 ) ;
if ( V_23 )
return V_23 ;
V_138 . V_139 = F_61 ( V_136 -> V_140 ) ;
V_138 . V_80 = V_136 -> V_141 ;
V_138 . V_142 = V_136 -> V_143 ;
V_138 . V_79 = V_136 -> V_144 ;
V_138 . V_145 = V_136 -> V_146 ;
V_138 . V_147 = V_136 -> V_148 . V_149 ;
V_138 . V_150 = V_136 -> V_148 . V_151 ;
V_138 . V_152 = V_136 -> V_153 . V_149 ;
V_138 . V_154 = V_136 -> V_153 . V_151 ;
V_23 = - V_111 ;
V_26 = F_59 ( V_73 ) ;
V_21 = F_38 ( V_73 ) ;
if ( F_23 ( V_21 ) )
return F_34 ( V_21 ) ;
if ( F_64 ( V_73 -> V_89 -> V_3 ) )
F_65 ( V_73 -> V_89 -> V_155 ) ;
V_23 = F_66 ( V_21 , & V_138 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( ( V_136 -> V_140 & V_124 ) &&
V_136 -> V_146 != F_67 ( V_73 -> V_89 ) )
F_68 ( V_73 -> V_89 , V_136 -> V_146 ) ;
F_42 ( V_73 -> V_89 ) ;
F_69 ( V_73 -> V_89 , V_136 ) ;
F_70 ( V_73 -> V_89 ) ;
if ( V_136 -> V_140 & V_118 ) {
V_23 = F_71 ( V_73 ) ;
if ( V_23 < 0 )
return V_23 ;
}
return 0 ;
}
void
F_15 ( struct V_9 * V_110 , struct V_1 * V_1 )
{
T_2 V_80 ;
struct V_7 * V_8 = F_5 ( V_1 ) ;
if ( ( V_110 -> V_156 & V_32 ) == V_32 ) {
V_1 -> V_157 . V_149 = V_110 -> V_158 ;
V_1 -> V_157 . V_151 = V_110 -> V_159 ;
V_1 -> V_160 . V_149 = V_110 -> V_161 ;
V_1 -> V_160 . V_151 = V_110 -> V_162 ;
V_1 -> V_163 . V_149 = V_110 -> V_164 ;
V_1 -> V_163 . V_151 = V_110 -> V_165 ;
V_1 -> V_166 = V_110 -> V_167 ;
V_1 -> V_5 = V_110 -> V_168 ;
F_72 ( V_1 , V_110 -> V_169 ) ;
V_80 = V_110 -> V_12 & V_170 ;
V_80 |= V_1 -> V_3 & ~ V_170 ;
V_1 -> V_3 = V_80 ;
F_73 ( V_1 , V_110 -> V_171 ) ;
V_1 -> V_172 = V_110 -> V_173 ;
} else {
if ( V_110 -> V_156 & V_174 ) {
V_1 -> V_157 . V_149 = V_110 -> V_158 ;
V_1 -> V_157 . V_151 = V_110 -> V_159 ;
}
if ( V_110 -> V_156 & V_175 ) {
V_1 -> V_160 . V_149 = V_110 -> V_161 ;
V_1 -> V_160 . V_151 = V_110 -> V_162 ;
}
if ( V_110 -> V_156 & V_176 ) {
V_1 -> V_163 . V_149 = V_110 -> V_164 ;
V_1 -> V_163 . V_151 = V_110 -> V_165 ;
}
if ( V_110 -> V_156 & V_177 )
V_1 -> V_166 = V_110 -> V_167 ;
if ( V_110 -> V_156 & V_178 )
V_1 -> V_5 = V_110 -> V_168 ;
if ( V_110 -> V_156 & V_179 )
F_72 ( V_1 , V_110 -> V_169 ) ;
if ( V_110 -> V_156 & V_180 ) {
V_1 -> V_3 = V_110 -> V_12 ;
if ( ( F_74 ( V_1 -> V_3 ) ) ||
( F_75 ( V_1 -> V_3 ) ) )
F_76 ( V_1 , V_1 -> V_3 ,
V_1 -> V_181 ) ;
}
if ( V_110 -> V_156 & V_182 )
V_1 -> V_181 = F_14 ( V_110 -> V_31 ) ;
if ( V_110 -> V_156 & V_183 )
F_73 ( V_1 , V_110 -> V_171 ) ;
if ( V_110 -> V_156 & V_184 )
V_1 -> V_172 = V_110 -> V_173 ;
}
if ( V_110 -> V_156 & V_33 )
V_1 -> V_13 = V_110 -> V_14 ;
V_8 -> V_185 &= ~ V_186 ;
}
static int
F_77 ( struct V_1 * V_72 , struct V_73 * V_73 ,
const char * V_187 )
{
int V_78 ;
T_1 V_79 ;
char * V_81 ;
struct V_19 V_15 ;
struct V_1 * V_1 ;
struct V_20 * V_82 ;
struct V_20 * V_21 = NULL ;
struct V_25 * V_26 ;
V_81 = ( char * ) V_73 -> V_90 . V_81 ;
F_37 ( V_91 , L_11 , V_72 -> V_24 , V_81 , V_187 ) ;
V_26 = F_36 ( V_72 ) ;
V_82 = F_38 ( V_73 -> V_92 ) ;
if ( F_23 ( V_82 ) ) {
V_78 = F_34 ( V_82 ) ;
F_37 ( V_91 , L_2 , V_78 ) ;
return V_78 ;
}
V_79 = F_1 ( V_72 ) ;
V_78 = F_78 ( V_82 , V_81 , ( char * ) V_187 , V_79 , & V_15 ) ;
if ( V_78 < 0 ) {
F_37 ( V_91 , L_12 , V_78 ) ;
goto error;
}
F_42 ( V_72 ) ;
if ( V_26 -> V_96 ) {
V_21 = F_39 ( V_82 , 1 , & V_81 , 1 ) ;
if ( F_23 ( V_21 ) ) {
V_78 = F_34 ( V_21 ) ;
F_37 ( V_91 , L_3 ,
V_78 ) ;
V_21 = NULL ;
goto error;
}
V_1 = F_43 ( V_26 , V_21 , V_72 -> V_94 ) ;
if ( F_23 ( V_1 ) ) {
V_78 = F_34 ( V_1 ) ;
F_37 ( V_91 , L_6 ,
V_78 ) ;
goto error;
}
V_78 = F_44 ( V_73 , V_21 ) ;
if ( V_78 < 0 )
goto error;
F_45 ( V_73 , V_1 ) ;
V_21 = NULL ;
} else {
V_1 = F_56 ( V_72 -> V_94 , V_188 , 0 ) ;
if ( F_23 ( V_1 ) ) {
V_78 = F_34 ( V_1 ) ;
goto error;
}
F_45 ( V_73 , V_1 ) ;
}
error:
if ( V_21 )
F_53 ( V_21 ) ;
return V_78 ;
}
static int
F_79 ( struct V_73 * V_189 , struct V_1 * V_72 ,
struct V_73 * V_73 )
{
int V_78 ;
char * V_81 ;
struct V_73 * V_103 ;
struct V_20 * V_82 , * V_190 ;
struct V_25 * V_26 ;
F_37 ( V_91 , L_13 ,
V_72 -> V_24 , V_189 -> V_90 . V_81 , V_73 -> V_90 . V_81 ) ;
V_26 = F_36 ( V_72 ) ;
V_103 = V_73 -> V_92 ;
V_82 = F_38 ( V_103 ) ;
if ( F_23 ( V_82 ) )
return F_34 ( V_82 ) ;
V_190 = F_38 ( V_189 ) ;
if ( F_23 ( V_190 ) )
return F_34 ( V_190 ) ;
V_81 = ( char * ) V_73 -> V_90 . V_81 ;
V_78 = F_80 ( V_82 , V_190 , ( char * ) V_73 -> V_90 . V_81 ) ;
if ( V_78 < 0 ) {
F_37 ( V_91 , L_14 , V_78 ) ;
return V_78 ;
}
F_42 ( V_72 ) ;
if ( V_26 -> V_96 == V_105 || V_26 -> V_96 == V_106 ) {
struct V_20 * V_21 ;
V_21 = F_38 ( V_189 ) ;
if ( F_23 ( V_21 ) )
return F_34 ( V_21 ) ;
F_81 ( V_21 , V_189 -> V_89 ) ;
}
F_82 ( V_189 -> V_89 ) ;
F_45 ( V_73 , V_189 -> V_89 ) ;
return V_78 ;
}
static int
F_30 ( struct V_1 * V_72 , struct V_73 * V_73 , T_2 V_74 ,
T_3 V_191 )
{
int V_78 ;
T_1 V_79 ;
char * V_81 ;
T_2 V_80 ;
struct V_25 * V_26 ;
struct V_20 * V_21 = NULL , * V_82 = NULL ;
struct V_1 * V_1 ;
struct V_19 V_15 ;
struct V_73 * V_103 ;
struct V_85 * V_87 = NULL , * V_86 = NULL ;
F_37 ( V_91 , L_15 ,
V_72 -> V_24 , V_73 -> V_90 . V_81 , V_74 ,
F_83 ( V_191 ) , F_84 ( V_191 ) ) ;
if ( ! F_85 ( V_191 ) )
return - V_192 ;
V_26 = F_36 ( V_72 ) ;
V_103 = V_73 -> V_92 ;
V_82 = F_38 ( V_103 ) ;
if ( F_23 ( V_82 ) ) {
V_78 = F_34 ( V_82 ) ;
F_37 ( V_91 , L_2 , V_78 ) ;
V_82 = NULL ;
goto error;
}
V_79 = F_1 ( V_72 ) ;
V_80 = V_74 ;
V_78 = F_40 ( V_72 , & V_80 , & V_87 , & V_86 ) ;
if ( V_78 ) {
F_37 ( V_91 , L_16 ,
V_78 ) ;
goto error;
}
V_81 = ( char * ) V_73 -> V_90 . V_81 ;
V_78 = F_86 ( V_82 , V_81 , V_80 , V_191 , V_79 , & V_15 ) ;
if ( V_78 < 0 )
goto error;
F_42 ( V_72 ) ;
if ( V_26 -> V_96 == V_105 || V_26 -> V_96 == V_106 ) {
V_21 = F_39 ( V_82 , 1 , & V_81 , 1 ) ;
if ( F_23 ( V_21 ) ) {
V_78 = F_34 ( V_21 ) ;
F_37 ( V_91 , L_3 ,
V_78 ) ;
V_21 = NULL ;
goto error;
}
V_1 = F_43 ( V_26 , V_21 , V_72 -> V_94 ) ;
if ( F_23 ( V_1 ) ) {
V_78 = F_34 ( V_1 ) ;
F_37 ( V_91 , L_6 ,
V_78 ) ;
goto error;
}
V_78 = F_44 ( V_73 , V_21 ) ;
if ( V_78 < 0 )
goto error;
F_45 ( V_73 , V_1 ) ;
V_21 = NULL ;
} else {
V_1 = F_56 ( V_72 -> V_94 , V_80 , V_191 ) ;
if ( F_23 ( V_1 ) ) {
V_78 = F_34 ( V_1 ) ;
goto error;
}
F_45 ( V_73 , V_1 ) ;
}
F_46 ( V_73 , & V_87 , & V_86 ) ;
error:
if ( V_21 )
F_53 ( V_21 ) ;
F_46 ( NULL , & V_87 , & V_86 ) ;
return V_78 ;
}
static void *
F_87 ( struct V_73 * V_73 , struct V_193 * V_194 )
{
int V_23 ;
struct V_20 * V_21 ;
char * V_195 = F_88 () ;
char * V_196 ;
F_37 ( V_91 , L_17 , V_73 -> V_90 . V_81 ) ;
if ( ! V_195 ) {
V_195 = F_12 ( - V_28 ) ;
goto V_197;
}
V_21 = F_38 ( V_73 ) ;
if ( F_23 ( V_21 ) ) {
F_89 ( V_195 ) ;
V_195 = F_24 ( V_21 ) ;
goto V_197;
}
V_23 = F_90 ( V_21 , & V_196 ) ;
if ( ! V_23 ) {
strcpy ( V_195 , V_196 ) ;
F_25 ( V_196 ) ;
goto V_197;
}
F_89 ( V_195 ) ;
V_195 = F_12 ( V_23 ) ;
V_197:
F_91 ( V_194 , V_195 ) ;
return NULL ;
}
int F_81 ( struct V_20 * V_21 , struct V_1 * V_1 )
{
T_4 V_198 ;
struct V_9 * V_10 ;
struct V_25 * V_26 ;
V_26 = F_36 ( V_1 ) ;
V_10 = F_22 ( V_21 , V_112 ) ;
if ( F_23 ( V_10 ) )
return F_34 ( V_10 ) ;
if ( ( V_1 -> V_3 & V_11 ) != ( V_10 -> V_12 & V_11 ) )
goto V_93;
F_92 ( & V_1 -> V_199 ) ;
V_198 = V_1 -> V_198 ;
F_15 ( V_10 , V_1 ) ;
if ( V_26 -> V_96 )
V_1 -> V_198 = V_198 ;
F_93 ( & V_1 -> V_199 ) ;
V_93:
F_25 ( V_10 ) ;
return 0 ;
}

static int
F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static T_1
F_3 ( struct V_4 * V_5 , T_1 V_6 )
{
return F_4 ( V_5 , V_6 , V_3 ) ;
}
static int
V_3 ( struct V_7 * V_7 , T_1 V_6 ,
struct V_8 * V_9 , int V_10 )
{
struct V_11 * V_12 = V_7 -> V_13 ;
T_2 * V_14 = & F_5 ( V_7 ) -> V_15 . V_14 ;
T_3 V_16 = V_17 ;
int V_18 = 0 ;
T_4 V_19 ;
F_6 ( V_12 , L_1 ,
( unsigned long ) V_7 -> V_20 , ( long ) V_6 ) ;
if ( V_10 ) {
F_7 ( V_12 , L_2
L_3 , ( long ) V_6 ,
( unsigned long ) V_7 -> V_20 ) ;
return - V_21 ;
}
V_18 = F_8 ( V_12 , V_14 , V_6 , & V_16 ) ;
if ( V_18 != V_22 ) {
F_7 ( V_12 ,
L_4 ,
V_23 , ( unsigned long ) V_7 -> V_20 ,
( long ) V_6 ) ;
return - V_24 ;
}
V_19 = ( T_4 ) F_9 ( V_12 , & V_16 ) ;
F_10 ( V_9 , V_7 -> V_13 , V_19 ) ;
F_6 ( V_12 , L_5 ,
V_23 , ( unsigned long ) V_7 -> V_20 , ( long ) V_6 ,
( unsigned long ) V_19 ) ;
return 0 ;
}
static struct V_25 *
F_11 ( struct V_7 * V_26 , struct V_25 * V_25 , unsigned int V_27 )
{
struct V_7 * V_7 ;
struct V_11 * V_12 = V_26 -> V_13 ;
const T_2 * V_14 = & F_5 ( V_26 ) -> V_15 . V_14 ;
T_5 V_28 ;
int V_29 ;
int V_30 ;
char * V_31 ;
const char * V_32 = V_25 -> V_33 . V_32 ;
F_6 ( V_12 , L_6 , V_23 ,
V_25 , V_26 -> V_20 ) ;
if ( F_12 ( V_12 ) -> V_34 ) {
V_29 =
F_13 ( V_12 , V_32 , strlen ( V_32 ) , & V_31 , & V_30 ) ;
if ( V_29 < 0 ) {
F_6 ( V_12 , L_7 , V_23 ) ;
return F_14 ( V_29 ) ;
}
V_29 = F_15 ( V_12 , V_14 , V_31 , & V_28 ) ;
F_16 ( V_31 ) ;
} else {
V_29 = F_15 ( V_12 , V_14 , V_25 -> V_33 . V_32 , & V_28 ) ;
}
if ( V_29 == V_35 ) {
F_6 ( V_12 , L_8 , V_23 , V_25 ) ;
return F_14 ( - V_36 ) ;
} else if ( V_29 != V_22 || V_28 == 0 ) {
F_17 ( V_12 , L_9 , V_23 ) ;
return F_14 ( - V_37 ) ;
}
V_7 = F_18 ( V_26 -> V_13 , ( V_38 ) V_28 ) ;
if ( F_19 ( V_7 ) )
return F_20 ( V_7 ) ;
F_21 ( V_25 , V_7 ) ;
F_6 ( V_12 , L_10 , V_23 ) ;
return NULL ;
}
static int
F_22 ( struct V_1 * V_1 , struct V_39 * V_40 )
{
struct V_7 * V_7 = F_23 ( V_1 ) ;
struct V_11 * V_12 = V_7 -> V_13 ;
const T_2 * V_14 = & F_5 ( V_7 ) -> V_15 . V_14 ;
T_5 V_41 ;
int V_42 ;
T_6 V_43 ;
unsigned char V_44 ;
char V_45 [ V_46 + 1 ] ;
F_6 ( V_12 , L_11 ,
V_23 , V_1 , V_7 -> V_20 , V_40 -> V_47 ) ;
V_48:
V_42 = F_24 ( V_12 , V_14 , V_40 -> V_47 , V_46 + 1 ,
V_45 , & V_43 , & V_41 ) ;
if ( V_42 == V_49 ) {
F_6 ( V_12 , L_7 , V_23 ) ;
F_7 ( V_12 , L_12 ,
V_1 , V_7 -> V_20 ) ;
return - V_50 ;
} else if ( V_42 == V_51 ) {
F_6 ( V_12 , L_13 , V_23 ) ;
return 0 ;
} else if ( V_42 == V_52 ) {
F_6 ( V_12 , L_14 , V_23 ) ;
return 0 ;
}
V_44 = V_53 ;
if ( F_12 ( V_12 ) -> V_34 ) {
char * V_54 ;
int V_55 ;
V_42 =
F_25 ( V_12 , V_45 , V_43 , & V_54 , & V_55 ) ;
if ( V_42 < 0 ) {
F_6 ( V_12 , L_7 , V_23 ) ;
return V_42 ;
}
if ( ! F_26 ( V_40 , V_54 , V_55 ,
( V_38 ) V_41 , V_44 ) ) {
F_16 ( V_54 ) ;
return 0 ;
}
F_16 ( V_54 ) ;
} else {
if ( ! F_26 ( V_40 , V_45 , V_43 ,
( V_38 ) V_41 , V_44 ) )
return 0 ;
}
V_40 -> V_47 ++ ;
goto V_48;
}
static struct V_7 *
F_27 ( struct V_11 * V_12 )
{
struct V_56 * V_57 ;
V_57 = F_28 ( V_58 , V_59 ) ;
if ( ! V_57 )
return NULL ;
return & V_57 -> V_60 ;
}
static void F_29 ( struct V_61 * V_62 )
{
struct V_7 * V_7 = F_30 ( V_62 , struct V_7 , V_63 ) ;
F_31 ( V_58 , F_5 ( V_7 ) ) ;
}
static void F_32 ( struct V_7 * V_7 )
{
F_33 ( & V_7 -> V_63 , F_29 ) ;
}
static void F_34 ( void * V_64 )
{
struct V_56 * V_57 = (struct V_56 * ) V_64 ;
F_35 ( & V_57 -> V_60 ) ;
}
static struct V_7 * F_18 ( struct V_11 * V_12 , unsigned long V_65 )
{
struct V_8 * V_66 ;
T_7 * V_67 ;
struct V_68 * V_69 = F_12 ( V_12 ) ;
struct V_56 * V_70 ;
struct V_7 * V_7 ;
long V_29 = - V_50 ;
F_6 ( V_12 , L_15 , V_23 , V_65 ) ;
V_7 = F_36 ( V_12 , V_65 ) ;
if ( ! V_7 )
return F_14 ( - V_71 ) ;
if ( ! ( V_7 -> V_72 & V_73 ) )
return V_7 ;
V_70 = F_5 ( V_7 ) ;
V_70 -> V_74 = F_37 ( V_12 , V_7 -> V_20 ) ;
F_6 ( V_12 , L_16 ,
V_70 -> V_74 . V_75 ,
V_70 -> V_74 . V_76 , V_70 -> V_74 . V_77 ) ;
V_66 = F_38 ( V_12 , V_7 -> V_20 ) ;
if ( ! V_66 ) {
F_7 ( V_12 , L_17
L_18 , V_7 -> V_20 ) ;
goto V_78;
}
V_67 = ( T_7 * ) V_66 -> V_79 ;
F_39 ( V_12 , V_67 ) ;
if ( F_40 ( V_12 , V_67 , V_7 -> V_20 ) != V_22 ) {
F_7 ( V_12 , L_19 , V_7 -> V_20 ) ;
goto V_80;
}
V_7 -> V_81 = ( V_82 ) F_41 ( V_12 , V_67 -> V_83 ) ;
V_7 -> V_84 = V_69 -> V_85 . V_86 ?
V_69 -> V_85 . V_87 :
F_42 ( & V_88 , F_41 ( V_12 , V_67 -> V_87 ) ) ;
V_7 -> V_89 = V_69 -> V_85 . V_90 ?
V_69 -> V_85 . V_91 :
F_43 ( & V_88 , F_41 ( V_12 , V_67 -> V_91 ) ) ;
F_44 ( V_7 , 1 ) ;
V_7 -> V_92 . V_93 =
F_45 ( V_12 , V_67 -> V_94 ) >> 16 ;
V_7 -> V_92 . V_95 = 0 ;
V_7 -> V_96 = V_7 -> V_92 ;
V_7 -> V_97 = V_7 -> V_92 ;
V_70 -> V_74 = F_46 ( V_12 , V_67 -> V_98 ) ;
V_70 -> V_99 = F_46 ( V_12 , V_67 -> V_100 ) ;
V_70 -> V_101 = F_46 ( V_12 , V_67 -> V_102 ) ;
V_70 -> V_103 = F_41 ( V_12 , V_67 -> V_27 ) ;
if ( F_47 ( V_7 -> V_81 ) && ! ( V_70 -> V_103 & V_104 ) ) {
V_7 -> V_105 = 0 ;
V_7 -> V_106 = V_69 -> V_107 / V_108 ;
F_48 ( V_70 -> V_15 . V_109 , V_67 -> V_110 . V_109 ,
V_111 ) ;
} else {
int V_112 ;
V_70 -> V_15 . V_14 =
F_49 ( V_12 , & V_67 -> V_110 . V_113 ) ;
V_112 = F_50 ( V_12 , & V_70 -> V_15 . V_14 ) ;
V_7 -> V_106 =
V_112 * ( V_69 -> V_107 / V_108 ) ;
V_7 -> V_105 = V_70 -> V_15 . V_14 . V_114 ;
}
V_7 -> V_115 -> V_116 = & V_117 ;
if ( F_51 ( V_7 -> V_81 ) ) {
V_7 -> V_118 = & V_119 ;
} else if ( F_52 ( V_7 -> V_81 ) ) {
V_7 -> V_120 = & V_121 ;
V_7 -> V_118 = & V_122 ;
} else if ( F_47 ( V_7 -> V_81 ) ) {
if ( V_70 -> V_103 & V_104 ) {
V_7 -> V_120 = & V_123 ;
F_53 ( V_7 ) ;
V_7 -> V_115 -> V_116 = & V_124 ;
} else {
V_7 -> V_125 = V_70 -> V_15 . V_109 ;
V_7 -> V_120 = & V_126 ;
}
} else {
F_7 ( V_12 , L_20
L_21
L_22 , V_7 -> V_20 ) ;
goto V_80;
}
F_54 ( V_66 ) ;
F_6 ( V_12 , L_10 , V_23 ) ;
F_55 ( V_7 ) ;
return V_7 ;
V_80:
F_54 ( V_66 ) ;
V_78:
F_56 ( V_7 ) ;
F_6 ( V_12 , L_23 , V_23 ) ;
return F_14 ( V_29 ) ;
}
static int T_8
F_57 ( void )
{
V_58 = F_58 ( L_24 ,
sizeof ( struct V_56 ) ,
0 , ( V_127 |
V_128 | V_129 ) ,
F_34 ) ;
if ( V_58 == NULL ) {
F_59 ( L_25 , V_23 ) ;
return - V_71 ;
}
return 0 ;
}
static void
F_60 ( void )
{
F_61 () ;
F_62 ( V_58 ) ;
}
static int F_63 ( struct V_1 * V_130 , struct V_2 * V_2 )
{
struct V_7 * V_7 = V_2 -> V_5 -> V_131 ;
struct V_11 * V_12 = V_7 -> V_13 ;
struct V_56 * V_70 = F_5 ( V_7 ) ;
T_2 * V_110 = & V_70 -> V_15 . V_14 ;
T_5 V_77 = V_110 -> V_114 ;
char * V_132 = F_64 ( V_2 ) ;
if ( V_77 == 0 || V_77 > V_133 ) {
F_7 ( V_12 , L_26 ) ;
goto V_134;
}
F_6 ( V_12 , L_27 ) ;
if ( F_65 ( V_12 , V_110 , V_132 , V_77 ) != V_77 ) {
F_7 ( V_12 , L_28 ) ;
goto V_134;
}
V_132 [ V_77 - 1 ] = '\0' ;
F_66 ( V_2 ) ;
F_67 ( V_2 ) ;
return 0 ;
V_134:
F_68 ( V_2 ) ;
F_67 ( V_2 ) ;
return - V_50 ;
}
static int
F_25 ( struct V_11 * V_12 , const char * V_135 ,
int V_136 , char * * V_137 , int * V_138 )
{
struct V_139 * V_34 = F_12 ( V_12 ) -> V_34 ;
int V_140 , V_141 ;
T_9 V_142 ;
int V_143 , V_144 ;
char * V_42 ;
int V_145 = V_136 + 1 ;
F_6 ( V_12 , L_29 , V_23 ) ;
if ( ! V_34 ) {
F_7 ( V_12 , L_30 , V_23 ) ;
return - V_146 ;
}
* V_137 = V_42 = F_69 ( V_145 , V_147 ) ;
if ( ! * V_137 ) {
F_7 ( V_12 , L_31 , V_23 ) ;
* V_138 = 0 ;
return - V_71 ;
}
for ( V_140 = V_141 = 0 ; V_140 < V_136 ; V_140 += V_144 , V_141 += V_143 ) {
V_144 = F_70 ( & V_135 [ V_140 ] , V_136 - V_140 , & V_142 ) ;
if ( V_144 < 0 )
goto V_148;
if ( V_142 > V_149 )
goto V_148;
V_143 = V_34 -> V_150 ( V_142 , & V_42 [ V_141 ] , V_136 - V_141 ) ;
if ( V_143 < 0 )
goto V_148;
}
V_42 [ V_141 ] = '\0' ;
* V_138 = V_141 ;
F_6 ( V_12 , L_10 , V_23 ) ;
return V_141 ;
V_148:
F_7 ( V_12 , L_32
L_33 , V_34 -> V_151 ) ;
F_6 ( V_12 , L_10 , V_23 ) ;
F_16 ( V_42 ) ;
return - V_152 ;
}
static int
F_13 ( struct V_11 * V_12 , const char * V_135 ,
int V_136 , char * * V_137 , int * V_138 )
{
struct V_139 * V_34 = F_12 ( V_12 ) -> V_34 ;
int V_140 , V_141 ;
T_10 V_142 ;
int V_143 , V_144 ;
char * V_42 ;
int V_145 = ( 3 * V_136 ) + 1 ;
F_6 ( V_12 , L_34 , V_23 ) ;
if ( ! V_34 ) {
F_7 ( V_12 , L_35 ,
V_23 ) ;
return - V_146 ;
}
* V_137 = V_42 = F_69 ( V_145 , V_147 ) ;
if ( ! * V_137 ) {
F_7 ( V_12 , L_31 , V_23 ) ;
* V_138 = 0 ;
return - V_71 ;
}
for ( V_140 = V_141 = 0 ; V_140 < V_136 ; V_140 += V_143 , V_141 += V_144 ) {
V_143 = V_34 -> V_153 ( & V_135 [ V_140 ] , V_136 - V_140 , & V_142 ) ;
if ( V_143 < 0 )
goto V_148;
V_144 = F_71 ( V_142 , & V_42 [ V_141 ] , 3 ) ;
if ( V_144 <= 0 )
goto V_148;
}
V_42 [ V_141 ] = '\0' ;
* V_138 = V_141 ;
F_6 ( V_12 , L_10 , V_23 ) ;
return V_140 ;
V_148:
F_7 ( V_12 , L_36
L_33 , V_34 -> V_151 ) ;
F_6 ( V_12 , L_10 , V_23 ) ;
F_16 ( V_42 ) ;
return - V_152 ;
}
static int
F_72 ( char * V_154 , struct V_155 * V_156 )
{
char * V_157 ;
T_11 args [ V_158 ] ;
int V_159 ;
T_12 V_87 ;
T_13 V_91 ;
V_156 -> V_87 = V_160 ;
V_156 -> V_91 = V_161 ;
V_156 -> V_86 = 0 ;
V_156 -> V_90 = 0 ;
V_156 -> V_162 = NULL ;
V_156 -> V_163 = 0 ;
if ( ! V_154 )
return 1 ;
while ( ( V_157 = F_73 ( & V_154 , L_37 ) ) != NULL ) {
int V_164 ;
if ( ! * V_157 )
continue;
V_164 = F_74 ( V_157 , V_165 , args ) ;
switch ( V_164 ) {
case V_166 :
if ( F_75 ( & args [ 0 ] , & V_159 ) )
return 0 ;
V_87 = V_167 ;
if ( V_159 >= 0 )
V_87 = F_42 ( F_76 () , V_159 ) ;
if ( ! F_77 ( V_87 ) ) {
F_59 ( L_38
L_39 , V_159 ) ;
break;
}
V_156 -> V_87 = V_87 ;
V_156 -> V_86 = 1 ;
break;
case V_168 :
if ( F_75 ( & args [ 0 ] , & V_159 ) )
return 0 ;
V_91 = V_169 ;
if ( V_159 >= 0 )
V_91 = F_43 ( F_76 () , V_159 ) ;
if ( ! F_78 ( V_91 ) ) {
F_59 ( L_40
L_39 , V_159 ) ;
break;
}
V_156 -> V_91 = V_91 ;
V_156 -> V_90 = 1 ;
break;
case V_170 :
F_16 ( V_156 -> V_162 ) ;
V_156 -> V_162 = F_79 ( & args [ 0 ] ) ;
if ( ! V_156 -> V_162 ) {
F_59 ( L_41
L_42 ) ;
return 0 ;
}
break;
case V_171 :
V_156 -> V_163 = 1 ;
break;
default:
F_59 ( L_43
L_44 , V_157 ) ;
return 0 ;
}
}
return 1 ;
}
static void
F_80 ( struct V_11 * V_12 )
{
F_16 ( F_12 ( V_12 ) -> V_85 . V_162 ) ;
F_12 ( V_12 ) -> V_85 . V_162 = NULL ;
F_81 ( F_12 ( V_12 ) -> V_34 ) ;
F_16 ( V_12 -> V_172 ) ;
V_12 -> V_172 = NULL ;
}
static int
F_82 ( struct V_11 * V_12 , void * V_110 , int V_173 )
{
struct V_8 * V_66 ;
struct V_68 * V_69 ;
T_14 * V_174 ;
struct V_7 * V_175 ;
long V_29 = - V_146 ;
const unsigned long V_176 = 0 ;
const T_15 V_177 = 512 ;
F_83 ( V_12 , V_110 ) ;
V_12 -> V_172 = F_84 ( sizeof( * V_69 ) , V_59 ) ;
if ( V_12 -> V_172 == NULL ) {
F_59 ( L_45
L_46 , V_12 -> V_178 ) ;
goto V_78;
}
V_69 = F_12 ( V_12 ) ;
if ( ! F_72 ( ( char * ) V_110 , & V_69 -> V_85 ) ) {
F_7 ( V_12 , L_47 ) ;
goto V_179;
}
F_6 ( V_12 , L_29 , V_23 ) ;
if ( ! ( V_12 -> V_180 & V_181 ) ) {
F_17 ( V_12 ,
L_48 ) ;
V_12 -> V_180 |= V_181 ;
}
F_85 ( V_12 , 1024 ) ;
if ( ! ( V_66 = F_86 ( V_12 , V_176 ) ) ) {
F_7 ( V_12 , L_49 ) ;
goto V_179;
}
V_174 = ( T_14 * ) V_66 -> V_79 ;
if ( ( V_174 -> V_182 == V_183 ) ||
( V_174 -> V_182 == V_184 ) ) {
F_6 ( V_12 , L_50 ) ;
} else {
F_6 ( V_12 , L_51 ) ;
V_174 =
( T_14 * ) ( ( void * ) V_66 -> V_79 + V_177 ) ;
}
if ( ( F_87 ( V_12 , V_174 ) != V_22 ) ||
( F_88 ( V_12 ) != V_22 ) )
goto V_80;
F_89 ( V_12 , V_174 ) ;
F_54 ( V_66 ) ;
if( V_69 -> V_185 > ~ ( ( T_1 ) 0 ) ) {
F_7 ( V_12 , L_52
L_53 ,
V_69 -> V_185 ) ;
goto V_179;
}
V_12 -> V_186 = V_187 ;
F_90 ( V_12 , ( T_4 ) V_69 -> V_107 ) ;
V_12 -> V_188 = & V_189 ;
V_175 = F_18 ( V_12 , F_9 ( V_12 , & ( V_69 -> V_190 ) ) ) ;
if ( F_19 ( V_175 ) ) {
V_29 = F_91 ( V_175 ) ;
goto V_179;
}
V_12 -> V_191 = F_92 ( V_175 ) ;
if ( ! V_12 -> V_191 ) {
F_7 ( V_12 , L_54 ) ;
goto V_179;
}
if ( V_69 -> V_85 . V_162 ) {
F_6 ( V_12 , L_55 ,
V_69 -> V_85 . V_162 ) ;
V_69 -> V_34 = F_93 ( V_69 -> V_85 . V_162 ) ;
if ( ! V_69 -> V_34 ) {
F_17 ( V_12 , L_56
L_57 ,
V_69 -> V_85 . V_162 ) ;
V_69 -> V_34 = F_94 () ;
}
} else {
F_6 ( V_12 , L_58 ) ;
V_69 -> V_34 = F_94 () ;
}
return 0 ;
V_80:
F_54 ( V_66 ) ;
V_179:
F_16 ( V_69 -> V_85 . V_162 ) ;
F_16 ( V_12 -> V_172 ) ;
V_78:
V_12 -> V_172 = NULL ;
return V_29 ;
}
static int
F_95 ( struct V_11 * V_12 , int * V_27 , char * V_110 )
{
F_96 ( V_12 ) ;
if ( ! ( * V_27 & V_181 ) )
return - V_146 ;
return 0 ;
}
static int
F_97 ( struct V_25 * V_25 , struct V_192 * V_193 )
{
struct V_11 * V_12 = V_25 -> V_194 ;
T_16 V_195 = F_98 ( V_12 -> V_196 -> V_197 ) ;
F_6 ( V_12 , L_29 , V_23 ) ;
V_193 -> V_198 = V_187 ;
V_193 -> V_199 = V_12 -> V_200 ;
V_193 -> V_201 = F_12 ( V_12 ) -> V_185 ;
V_193 -> V_202 = F_12 ( V_12 ) -> V_185 - F_12 ( V_12 ) -> V_203 ;
V_193 -> V_204 = V_193 -> V_202 ;
V_193 -> V_205 = 0 ;
V_193 -> V_206 = 0 ;
V_193 -> V_207 . V_208 [ 0 ] = ( V_209 ) V_195 ;
V_193 -> V_207 . V_208 [ 1 ] = ( V_209 ) ( V_195 >> 32 ) ;
V_193 -> V_210 = V_46 ;
F_6 ( V_12 , L_10 , V_23 ) ;
return 0 ;
}
static struct V_25 *
F_99 ( struct V_211 * V_212 , int V_27 , const char * V_213 ,
void * V_110 )
{
return F_100 ( V_212 , V_27 , V_213 , V_110 , F_82 ) ;
}
static int T_8
F_101 ( void )
{
int V_214 ;
F_102 ( L_59 , V_215 ) ;
V_214 = F_57 () ;
if ( V_214 )
goto V_78;
V_214 = F_103 ( & V_216 ) ;
if ( V_214 )
goto V_217;
return 0 ;
V_217:
F_60 () ;
V_78:
return V_214 ;
}
static void T_17
F_104 ( void )
{
F_60 () ;
F_105 ( & V_216 ) ;
}

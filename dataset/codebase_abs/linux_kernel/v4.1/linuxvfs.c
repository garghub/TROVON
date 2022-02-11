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
struct V_7 * V_7 = NULL ;
struct V_11 * V_12 = V_26 -> V_13 ;
T_2 * V_14 = & F_5 ( V_26 ) -> V_15 . V_14 ;
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
T_2 * V_14 = & F_5 ( V_7 ) -> V_15 . V_14 ;
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
struct V_8 * V_66 = NULL ;
T_7 * V_67 = NULL ;
struct V_68 * V_69 = F_12 ( V_12 ) ;
struct V_56 * V_70 = NULL ;
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
if ( V_70 -> V_103 & V_104 )
V_7 -> V_120 = & V_123 ;
else
V_7 -> V_120 = & V_124 ;
} else {
F_7 ( V_12 , L_20
L_21
L_22 , V_7 -> V_20 ) ;
goto V_80;
}
F_53 ( V_66 ) ;
F_6 ( V_12 , L_10 , V_23 ) ;
F_54 ( V_7 ) ;
return V_7 ;
V_80:
F_53 ( V_66 ) ;
V_78:
F_55 ( V_7 ) ;
F_6 ( V_12 , L_23 , V_23 ) ;
return F_14 ( V_29 ) ;
}
static int T_8
F_56 ( void )
{
V_58 = F_57 ( L_24 ,
sizeof ( struct V_56 ) ,
0 , ( V_125 |
V_126 ) ,
F_34 ) ;
if ( V_58 == NULL ) {
F_58 ( L_25 , V_23 ) ;
return - V_71 ;
}
return 0 ;
}
static void
F_59 ( void )
{
F_60 () ;
F_61 ( V_58 ) ;
}
static void *
F_62 ( struct V_25 * V_25 , struct V_127 * V_128 )
{
struct V_11 * V_12 = V_25 -> V_129 ;
struct V_56 * V_70 = F_5 ( F_63 ( V_25 ) ) ;
T_2 * V_110 = & V_70 -> V_15 . V_14 ;
T_5 V_77 = V_110 -> V_114 ;
char * V_130 ;
if ( V_77 == 0 ) {
F_7 ( V_12 , L_26 ) ;
V_130 = F_14 ( - V_50 ) ;
} else {
F_6 ( V_12 , L_27 ) ;
V_130 = F_64 ( V_77 , V_131 ) ;
if ( ! V_130 ) {
V_130 = F_14 ( - V_71 ) ;
} else if ( F_65 ( V_12 , V_110 , V_130 , V_77 ) != V_77 ) {
F_16 ( V_130 ) ;
F_7 ( V_12 , L_28 ) ;
V_130 = F_14 ( - V_50 ) ;
} else {
V_130 [ V_77 - 1 ] = '\0' ;
}
}
F_66 ( V_128 , V_130 ) ;
return NULL ;
}
static void *
F_67 ( struct V_25 * V_25 , struct V_127 * V_128 )
{
struct V_56 * V_70 = F_5 ( F_63 ( V_25 ) ) ;
F_66 ( V_128 , V_70 -> V_15 . V_109 ) ;
return NULL ;
}
static int
F_25 ( struct V_11 * V_12 , const char * V_132 ,
int V_133 , char * * V_134 , int * V_135 )
{
struct V_136 * V_34 = F_12 ( V_12 ) -> V_34 ;
int V_137 , V_138 ;
T_9 V_139 ;
int V_140 , V_141 ;
char * V_42 ;
int V_142 = V_133 + 1 ;
F_6 ( V_12 , L_29 , V_23 ) ;
if ( ! V_34 ) {
F_7 ( V_12 , L_30 , V_23 ) ;
return - V_143 ;
}
* V_134 = V_42 = F_64 ( V_142 , V_131 ) ;
if ( ! * V_134 ) {
F_7 ( V_12 , L_31 , V_23 ) ;
* V_135 = 0 ;
return - V_71 ;
}
for ( V_137 = V_138 = 0 ; V_137 < V_133 ; V_137 += V_141 , V_138 += V_140 ) {
V_141 = F_68 ( & V_132 [ V_137 ] , V_133 - V_137 , & V_139 ) ;
if ( V_141 < 0 )
goto V_144;
if ( V_139 > V_145 )
goto V_144;
V_140 = V_34 -> V_146 ( V_139 , & V_42 [ V_138 ] , V_133 - V_138 ) ;
if ( V_140 < 0 )
goto V_144;
}
V_42 [ V_138 ] = '\0' ;
* V_135 = V_138 ;
F_6 ( V_12 , L_10 , V_23 ) ;
return V_138 ;
V_144:
F_7 ( V_12 , L_32
L_33 , V_34 -> V_147 ) ;
F_6 ( V_12 , L_10 , V_23 ) ;
F_16 ( V_42 ) ;
return - V_148 ;
}
static int
F_13 ( struct V_11 * V_12 , const char * V_132 ,
int V_133 , char * * V_134 , int * V_135 )
{
struct V_136 * V_34 = F_12 ( V_12 ) -> V_34 ;
int V_137 , V_138 ;
T_10 V_139 ;
int V_140 , V_141 ;
char * V_42 ;
int V_142 = ( 3 * V_133 ) + 1 ;
F_6 ( V_12 , L_34 , V_23 ) ;
if ( ! V_34 ) {
F_7 ( V_12 , L_35 ,
V_23 ) ;
return - V_143 ;
}
* V_134 = V_42 = F_64 ( V_142 , V_131 ) ;
if ( ! * V_134 ) {
F_7 ( V_12 , L_31 , V_23 ) ;
* V_135 = 0 ;
return - V_71 ;
}
for ( V_137 = V_138 = 0 ; V_137 < V_133 ; V_137 += V_140 , V_138 += V_141 ) {
V_140 = V_34 -> V_149 ( & V_132 [ V_137 ] , V_133 - V_137 , & V_139 ) ;
if ( V_140 < 0 )
goto V_144;
V_141 = F_69 ( V_139 , & V_42 [ V_138 ] , 3 ) ;
if ( V_141 <= 0 )
goto V_144;
}
V_42 [ V_138 ] = '\0' ;
* V_135 = V_138 ;
F_6 ( V_12 , L_10 , V_23 ) ;
return V_137 ;
V_144:
F_7 ( V_12 , L_36
L_33 , V_34 -> V_147 ) ;
F_6 ( V_12 , L_10 , V_23 ) ;
F_16 ( V_42 ) ;
return - V_148 ;
}
static int
F_70 ( char * V_150 , struct V_151 * V_152 )
{
char * V_153 ;
T_11 args [ V_154 ] ;
int V_155 ;
T_12 V_87 ;
T_13 V_91 ;
V_152 -> V_87 = V_156 ;
V_152 -> V_91 = V_157 ;
V_152 -> V_86 = 0 ;
V_152 -> V_90 = 0 ;
V_152 -> V_158 = NULL ;
V_152 -> V_159 = 0 ;
if ( ! V_150 )
return 1 ;
while ( ( V_153 = F_71 ( & V_150 , L_37 ) ) != NULL ) {
int V_160 ;
if ( ! * V_153 )
continue;
V_160 = F_72 ( V_153 , V_161 , args ) ;
switch ( V_160 ) {
case V_162 :
if ( F_73 ( & args [ 0 ] , & V_155 ) )
return 0 ;
V_87 = V_163 ;
if ( V_155 >= 0 )
V_87 = F_42 ( F_74 () , V_155 ) ;
if ( ! F_75 ( V_87 ) ) {
F_58 ( L_38
L_39 , V_155 ) ;
break;
}
V_152 -> V_87 = V_87 ;
V_152 -> V_86 = 1 ;
break;
case V_164 :
if ( F_73 ( & args [ 0 ] , & V_155 ) )
return 0 ;
V_91 = V_165 ;
if ( V_155 >= 0 )
V_91 = F_43 ( F_74 () , V_155 ) ;
if ( ! F_76 ( V_91 ) ) {
F_58 ( L_40
L_39 , V_155 ) ;
break;
}
V_152 -> V_91 = V_91 ;
V_152 -> V_90 = 1 ;
break;
case V_166 :
F_16 ( V_152 -> V_158 ) ;
V_152 -> V_158 = F_77 ( & args [ 0 ] ) ;
if ( ! V_152 -> V_158 ) {
F_58 ( L_41
L_42 ) ;
return 0 ;
}
break;
case V_167 :
V_152 -> V_159 = 1 ;
break;
default:
F_58 ( L_43
L_44 , V_153 ) ;
return 0 ;
}
}
return 1 ;
}
static void
F_78 ( struct V_11 * V_12 )
{
F_16 ( F_12 ( V_12 ) -> V_85 . V_158 ) ;
F_12 ( V_12 ) -> V_85 . V_158 = NULL ;
F_79 ( F_12 ( V_12 ) -> V_34 ) ;
F_16 ( V_12 -> V_168 ) ;
V_12 -> V_168 = NULL ;
}
static int
F_80 ( struct V_11 * V_12 , void * V_110 , int V_169 )
{
struct V_8 * V_66 ;
struct V_68 * V_69 ;
T_14 * V_170 ;
struct V_7 * V_171 ;
long V_29 = - V_143 ;
const unsigned long V_172 = 0 ;
const T_15 V_173 = 512 ;
F_81 ( V_12 , V_110 ) ;
V_12 -> V_168 = F_82 ( sizeof( * V_69 ) , V_59 ) ;
if ( V_12 -> V_168 == NULL ) {
F_58 ( L_45
L_46 , V_12 -> V_174 ) ;
goto V_78;
}
V_69 = F_12 ( V_12 ) ;
if ( ! F_70 ( ( char * ) V_110 , & V_69 -> V_85 ) ) {
F_7 ( V_12 , L_47 ) ;
goto V_175;
}
F_6 ( V_12 , L_29 , V_23 ) ;
if ( ! ( V_12 -> V_176 & V_177 ) ) {
F_17 ( V_12 ,
L_48 ) ;
V_12 -> V_176 |= V_177 ;
}
F_83 ( V_12 , 1024 ) ;
if ( ! ( V_66 = F_84 ( V_12 , V_172 ) ) ) {
F_7 ( V_12 , L_49 ) ;
goto V_175;
}
V_170 = ( T_14 * ) V_66 -> V_79 ;
if ( ( V_170 -> V_178 == V_179 ) ||
( V_170 -> V_178 == V_180 ) ) {
F_6 ( V_12 , L_50 ) ;
} else {
F_6 ( V_12 , L_51 ) ;
V_170 =
( T_14 * ) ( ( void * ) V_66 -> V_79 + V_173 ) ;
}
if ( ( F_85 ( V_12 , V_170 ) != V_22 ) ||
( F_86 ( V_12 ) != V_22 ) )
goto V_80;
F_87 ( V_12 , V_170 ) ;
F_53 ( V_66 ) ;
if( V_69 -> V_181 > ~ ( ( T_1 ) 0 ) ) {
F_7 ( V_12 , L_52
L_53 ,
V_69 -> V_181 ) ;
goto V_175;
}
V_12 -> V_182 = V_183 ;
F_88 ( V_12 , ( T_4 ) V_69 -> V_107 ) ;
V_12 -> V_184 = & V_185 ;
V_171 = F_18 ( V_12 , F_9 ( V_12 , & ( V_69 -> V_186 ) ) ) ;
if ( F_19 ( V_171 ) ) {
V_29 = F_89 ( V_171 ) ;
goto V_175;
}
V_12 -> V_187 = F_90 ( V_171 ) ;
if ( ! V_12 -> V_187 ) {
F_7 ( V_12 , L_54 ) ;
goto V_175;
}
if ( V_69 -> V_85 . V_158 ) {
F_6 ( V_12 , L_55 ,
V_69 -> V_85 . V_158 ) ;
V_69 -> V_34 = F_91 ( V_69 -> V_85 . V_158 ) ;
if ( ! V_69 -> V_34 ) {
F_17 ( V_12 , L_56
L_57 ,
V_69 -> V_85 . V_158 ) ;
V_69 -> V_34 = F_92 () ;
}
} else {
F_6 ( V_12 , L_58 ) ;
V_69 -> V_34 = F_92 () ;
}
return 0 ;
V_80:
F_53 ( V_66 ) ;
V_175:
F_16 ( V_69 -> V_85 . V_158 ) ;
F_16 ( V_12 -> V_168 ) ;
V_78:
V_12 -> V_168 = NULL ;
return V_29 ;
}
static int
F_93 ( struct V_11 * V_12 , int * V_27 , char * V_110 )
{
F_94 ( V_12 ) ;
if ( ! ( * V_27 & V_177 ) )
return - V_143 ;
return 0 ;
}
static int
F_95 ( struct V_25 * V_25 , struct V_188 * V_189 )
{
struct V_11 * V_12 = V_25 -> V_129 ;
T_16 V_190 = F_96 ( V_12 -> V_191 -> V_192 ) ;
F_6 ( V_12 , L_29 , V_23 ) ;
V_189 -> V_193 = V_183 ;
V_189 -> V_194 = V_12 -> V_195 ;
V_189 -> V_196 = F_12 ( V_12 ) -> V_181 ;
V_189 -> V_197 = F_12 ( V_12 ) -> V_181 - F_12 ( V_12 ) -> V_198 ;
V_189 -> V_199 = V_189 -> V_197 ;
V_189 -> V_200 = 0 ;
V_189 -> V_201 = 0 ;
V_189 -> V_202 . V_203 [ 0 ] = ( V_204 ) V_190 ;
V_189 -> V_202 . V_203 [ 1 ] = ( V_204 ) ( V_190 >> 32 ) ;
V_189 -> V_205 = V_46 ;
F_6 ( V_12 , L_10 , V_23 ) ;
return 0 ;
}
static struct V_25 *
F_97 ( struct V_206 * V_207 , int V_27 , const char * V_208 ,
void * V_110 )
{
return F_98 ( V_207 , V_27 , V_208 , V_110 , F_80 ) ;
}
static int T_8
F_99 ( void )
{
int V_209 ;
F_100 ( L_59 , V_210 ) ;
V_209 = F_56 () ;
if ( V_209 )
goto V_78;
V_209 = F_101 ( & V_211 ) ;
if ( V_209 )
goto V_212;
return 0 ;
V_212:
F_59 () ;
V_78:
return V_209 ;
}
static void T_17
F_102 ( void )
{
F_59 () ;
F_103 ( & V_211 ) ;
}

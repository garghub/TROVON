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
V_7 -> V_20 , V_6 ) ;
if ( V_6 < 0 ) {
F_7 ( V_12 , L_2
L_3 ,
V_6 , V_7 -> V_20 ) ;
return - V_21 ;
}
if ( V_10 ) {
F_7 ( V_12 , L_4
L_5 , V_6 , V_7 -> V_20 ) ;
return - V_22 ;
}
V_18 = F_8 ( V_12 , V_14 , V_6 , & V_16 ) ;
if ( V_18 != V_23 ) {
F_7 ( V_12 ,
L_6
L_7 , V_7 -> V_20 , V_6 ) ;
return - V_24 ;
}
V_19 = ( T_4 ) F_9 ( V_12 , & V_16 ) ;
F_10 ( V_9 , V_7 -> V_13 , V_19 ) ;
F_6 ( V_12 , L_8
L_9 , V_7 -> V_20 , V_6 , V_19 ) ;
return 0 ;
}
static struct V_25 *
F_11 ( struct V_7 * V_26 , struct V_25 * V_25 , struct V_27 * V_28 )
{
struct V_7 * V_7 = NULL ;
struct V_11 * V_12 = V_26 -> V_13 ;
T_2 * V_14 = & F_5 ( V_26 ) -> V_15 . V_14 ;
T_5 V_29 ;
int V_30 ;
int V_31 ;
char * V_32 ;
const char * V_33 = V_25 -> V_34 . V_33 ;
F_6 ( V_12 , L_10
L_11 , V_25 -> V_34 . V_33 , V_26 -> V_20 ) ;
if ( F_12 ( V_12 ) -> V_35 ) {
V_30 =
F_13 ( V_12 , V_33 , strlen ( V_33 ) , & V_32 , & V_31 ) ;
if ( V_30 < 0 ) {
F_6 ( V_12 , L_12 ) ;
return F_14 ( V_30 ) ;
}
V_30 = F_15 ( V_12 , V_14 , V_32 , & V_29 ) ;
F_16 ( V_32 ) ;
} else {
V_30 = F_15 ( V_12 , V_14 , V_25 -> V_34 . V_33 , & V_29 ) ;
}
if ( V_30 == V_36 ) {
F_6 ( V_12 , L_13 ,
V_25 -> V_34 . V_33 ) ;
return F_14 ( - V_37 ) ;
} else if ( V_30 != V_23 || V_29 == 0 ) {
F_17 ( V_12 , L_14 ) ;
return F_14 ( - V_38 ) ;
}
V_7 = F_18 ( V_26 -> V_13 , ( V_39 ) V_29 ) ;
if ( F_19 ( V_7 ) )
return F_20 ( V_7 ) ;
F_21 ( V_25 , V_7 ) ;
F_6 ( V_12 , L_15 ) ;
return NULL ;
}
static int
F_22 ( struct V_1 * V_40 , void * V_41 , T_6 V_42 )
{
struct V_7 * V_7 = V_40 -> V_43 . V_25 -> V_44 ;
struct V_11 * V_12 = V_7 -> V_13 ;
T_2 * V_14 = & F_5 ( V_7 ) -> V_15 . V_14 ;
T_5 V_45 ;
int V_46 ;
T_7 V_47 ;
unsigned char V_48 ;
char V_49 [ V_50 + 1 ] ;
char * V_51 ;
int V_52 ;
const char * V_53 = V_40 -> V_43 . V_25 -> V_34 . V_33 ;
F_6 ( V_12 , L_16
L_17 ,
V_53 , V_7 -> V_20 , V_40 -> V_54 ) ;
V_46 = F_23 ( V_12 , V_14 , V_40 -> V_54 , V_50 + 1 ,
V_49 , & V_47 , & V_45 ) ;
if ( V_46 == V_55 ) {
F_6 ( V_12 , L_18 ) ;
F_7 ( V_12 , L_19 ,
V_53 , V_7 -> V_20 ) ;
return - V_21 ;
} else if ( V_46 == V_56 ) {
F_6 ( V_12 , L_20 ) ;
return 0 ;
} else if ( V_46 == V_57 ) {
F_6 ( V_12 , L_21 ) ;
return 0 ;
}
V_48 = V_58 ;
if ( F_12 ( V_12 ) -> V_35 ) {
V_46 =
F_24 ( V_12 , V_49 , V_47 , & V_51 , & V_52 ) ;
if ( V_46 < 0 ) {
F_6 ( V_12 , L_18 ) ;
return V_46 ;
}
V_46 = V_42 ( V_41 , V_51 , V_52 , V_40 -> V_54 ,
( V_39 ) V_45 , V_48 ) ;
F_16 ( V_51 ) ;
} else {
V_46 = V_42 ( V_41 , V_49 , V_47 , V_40 -> V_54 ,
( V_39 ) V_45 , V_48 ) ;
}
V_40 -> V_54 ++ ;
F_6 ( V_12 , L_22 , V_40 -> V_54 ) ;
return 0 ;
}
static struct V_7 *
F_25 ( struct V_11 * V_12 )
{
struct V_59 * V_60 ;
V_60 = (struct V_59 * ) F_26 ( V_61 ,
V_62 ) ;
if ( ! V_60 )
return NULL ;
return & V_60 -> V_63 ;
}
static void F_27 ( struct V_64 * V_65 )
{
struct V_7 * V_7 = F_28 ( V_65 , struct V_7 , V_66 ) ;
F_29 ( & V_7 -> V_67 ) ;
F_30 ( V_61 , F_5 ( V_7 ) ) ;
}
static void F_31 ( struct V_7 * V_7 )
{
F_32 ( & V_7 -> V_66 , F_27 ) ;
}
static void F_33 ( void * V_68 )
{
struct V_59 * V_60 = (struct V_59 * ) V_68 ;
F_34 ( & V_60 -> V_63 ) ;
}
static struct V_7 * F_18 ( struct V_11 * V_12 , unsigned long V_69 )
{
struct V_8 * V_70 = NULL ;
T_8 * V_71 = NULL ;
T_9 * V_72 = F_12 ( V_12 ) ;
V_59 * V_73 = NULL ;
struct V_7 * V_7 ;
long V_30 = - V_21 ;
F_6 ( V_12 , L_23 L_24 , V_69 ) ;
V_7 = F_35 ( V_12 , V_69 ) ;
if ( F_19 ( V_7 ) )
return V_7 ;
if ( ! ( V_7 -> V_74 & V_75 ) )
return V_7 ;
V_73 = F_5 ( V_7 ) ;
V_73 -> V_76 = F_36 ( V_12 , V_7 -> V_20 ) ;
F_6 ( V_12 , L_25 ,
V_73 -> V_76 . V_77 ,
V_73 -> V_76 . V_78 , V_73 -> V_76 . V_79 ) ;
V_70 = F_37 ( V_12 , V_7 -> V_20 ) ;
if ( ! V_70 ) {
F_7 ( V_12 , L_26
L_24 , V_7 -> V_20 ) ;
goto V_80;
}
V_71 = ( T_8 * ) V_70 -> V_81 ;
F_38 ( V_12 , V_71 ) ;
if ( F_39 ( V_12 , V_71 , V_7 -> V_20 ) != V_23 ) {
F_7 ( V_12 , L_27 , V_7 -> V_20 ) ;
goto V_82;
}
V_7 -> V_83 = ( V_84 ) F_40 ( V_12 , V_71 -> V_85 ) ;
V_7 -> V_86 = V_72 -> V_87 . V_88 ?
V_72 -> V_87 . V_89 : ( V_90 ) F_40 ( V_12 , V_71 -> V_89 ) ;
V_7 -> V_91 = V_72 -> V_87 . V_92 ?
V_72 -> V_87 . V_93 : ( V_94 ) F_40 ( V_12 , V_71 -> V_93 ) ;
V_7 -> V_95 = 1 ;
V_7 -> V_96 . V_97 =
F_41 ( V_12 , V_71 -> V_98 ) >> 16 ;
V_7 -> V_96 . V_99 = 0 ;
V_7 -> V_100 = V_7 -> V_96 ;
V_7 -> V_101 = V_7 -> V_96 ;
V_73 -> V_76 = F_42 ( V_12 , V_71 -> V_102 ) ;
V_73 -> V_103 = F_42 ( V_12 , V_71 -> V_104 ) ;
V_73 -> V_105 = F_42 ( V_12 , V_71 -> V_106 ) ;
V_73 -> V_107 = F_40 ( V_12 , V_71 -> V_108 ) ;
if ( F_43 ( V_7 -> V_83 ) && ! ( V_73 -> V_107 & V_109 ) ) {
V_7 -> V_110 = 0 ;
V_7 -> V_111 = V_72 -> V_112 / V_113 ;
strncpy ( V_73 -> V_15 . V_114 , V_71 -> V_115 . V_114 ,
V_116 - 1 ) ;
V_73 -> V_15 . V_114 [ V_116 - 1 ] = '\0' ;
} else {
int V_117 ;
V_73 -> V_15 . V_14 =
F_44 ( V_12 , & V_71 -> V_115 . V_118 ) ;
V_117 = F_45 ( V_12 , & V_73 -> V_15 . V_14 ) ;
V_7 -> V_111 =
V_117 * ( V_72 -> V_112 / V_113 ) ;
V_7 -> V_110 = V_73 -> V_15 . V_14 . V_119 ;
}
V_7 -> V_120 -> V_121 = & V_122 ;
if ( F_46 ( V_7 -> V_83 ) ) {
V_7 -> V_123 = & V_124 ;
} else if ( F_47 ( V_7 -> V_83 ) ) {
V_7 -> V_125 = & V_126 ;
V_7 -> V_123 = & V_127 ;
} else if ( F_43 ( V_7 -> V_83 ) ) {
V_7 -> V_125 = & V_128 ;
} else {
F_7 ( V_12 , L_28
L_29
L_30 , V_7 -> V_20 ) ;
goto V_82;
}
F_48 ( V_70 ) ;
F_6 ( V_12 , L_31 ) ;
F_49 ( V_7 ) ;
return V_7 ;
V_82:
F_48 ( V_70 ) ;
V_80:
F_50 ( V_7 ) ;
F_6 ( V_12 , L_32 ) ;
return F_14 ( V_30 ) ;
}
static int
F_51 ( void )
{
V_61 = F_52 ( L_33 ,
sizeof ( struct V_59 ) ,
0 , ( V_129 |
V_130 ) ,
F_33 ) ;
if ( V_61 == NULL ) {
F_53 ( V_131 L_34
L_35 ) ;
return - V_132 ;
}
return 0 ;
}
static void
F_54 ( void )
{
F_55 ( V_61 ) ;
}
static void *
F_56 ( struct V_25 * V_25 , struct V_27 * V_28 )
{
V_59 * V_73 = F_5 ( V_25 -> V_44 ) ;
char * V_133 ;
if ( V_73 -> V_107 & V_109 ) {
struct V_11 * V_12 = V_25 -> V_134 ;
T_2 * V_115 = & V_73 -> V_15 . V_14 ;
T_5 V_79 = V_115 -> V_119 ;
F_6 ( V_12 , L_36 ) ;
V_133 = F_57 ( V_79 , V_135 ) ;
if ( ! V_133 ) {
V_133 = F_14 ( - V_132 ) ;
} else if ( F_58 ( V_12 , V_115 , V_133 , V_79 ) != V_79 ) {
F_16 ( V_133 ) ;
F_7 ( V_12 , L_37 ) ;
V_133 = F_14 ( - V_21 ) ;
} else {
V_133 [ V_79 - 1 ] = '\0' ;
}
} else {
V_133 = V_73 -> V_15 . V_114 ;
}
F_59 ( V_28 , V_133 ) ;
return NULL ;
}
static void F_60 ( struct V_25 * V_25 , struct V_27 * V_28 , void * V_136 )
{
V_59 * V_73 = F_5 ( V_25 -> V_44 ) ;
if ( V_73 -> V_107 & V_109 ) {
char * V_133 = F_61 ( V_28 ) ;
if ( ! F_19 ( V_133 ) )
F_16 ( V_133 ) ;
}
}
static int
F_24 ( struct V_11 * V_12 , const char * V_137 ,
int V_138 , char * * V_139 , int * V_140 )
{
struct V_141 * V_35 = F_12 ( V_12 ) -> V_35 ;
int V_142 , V_143 ;
T_10 V_144 ;
int V_145 , V_146 ;
char * V_46 ;
int V_147 = V_138 + 1 ;
F_6 ( V_12 , L_38 ) ;
if ( ! V_35 ) {
F_7 ( V_12 , L_39 ) ;
return - V_148 ;
}
* V_139 = V_46 = F_57 ( V_147 , V_135 ) ;
if ( ! * V_139 ) {
F_7 ( V_12 , L_40 ) ;
* V_140 = 0 ;
return - V_132 ;
}
for ( V_142 = V_143 = 0 ; V_142 < V_138 ; V_142 += V_146 , V_143 += V_145 ) {
V_146 = F_62 ( & V_137 [ V_142 ] , V_138 - V_142 , & V_144 ) ;
if ( V_146 < 0 )
goto V_149;
if ( V_144 > V_150 )
goto V_149;
V_145 = V_35 -> V_151 ( V_144 , & V_46 [ V_143 ] , V_138 - V_143 ) ;
if ( V_145 < 0 )
goto V_149;
}
V_46 [ V_143 ] = '\0' ;
* V_140 = V_143 ;
F_6 ( V_12 , L_41 ) ;
return V_143 ;
V_149:
F_7 ( V_12 , L_42
L_43 , V_35 -> V_152 ) ;
F_6 ( V_12 , L_41 ) ;
F_16 ( V_46 ) ;
return - V_153 ;
}
static int
F_13 ( struct V_11 * V_12 , const char * V_137 ,
int V_138 , char * * V_139 , int * V_140 )
{
struct V_141 * V_35 = F_12 ( V_12 ) -> V_35 ;
int V_142 , V_143 ;
T_11 V_144 ;
int V_145 , V_146 ;
char * V_46 ;
int V_147 = ( 3 * V_138 ) + 1 ;
F_6 ( V_12 , L_44 ) ;
if ( ! V_35 ) {
F_7 ( V_12 , L_45 ) ;
return - V_148 ;
}
* V_139 = V_46 = F_57 ( V_147 , V_135 ) ;
if ( ! * V_139 ) {
F_7 ( V_12 , L_46 ) ;
* V_140 = 0 ;
return - V_132 ;
}
for ( V_142 = V_143 = 0 ; V_142 < V_138 ; V_142 += V_145 , V_143 += V_146 ) {
V_145 = V_35 -> V_154 ( & V_137 [ V_142 ] , V_138 - V_142 , & V_144 ) ;
if ( V_145 < 0 )
goto V_149;
V_146 = F_63 ( V_144 , & V_46 [ V_143 ] , 3 ) ;
if ( V_146 <= 0 )
goto V_149;
}
V_46 [ V_143 ] = '\0' ;
* V_140 = V_143 ;
F_6 ( V_12 , L_47 ) ;
return V_142 ;
V_149:
F_7 ( V_12 , L_48
L_43 , V_35 -> V_152 ) ;
F_6 ( V_12 , L_47 ) ;
F_16 ( V_46 ) ;
return - V_153 ;
}
static int
F_64 ( char * V_155 , T_12 * V_156 )
{
char * V_136 ;
T_13 args [ V_157 ] ;
int V_158 ;
V_156 -> V_89 = 0 ;
V_156 -> V_93 = 0 ;
V_156 -> V_88 = 0 ;
V_156 -> V_92 = 0 ;
V_156 -> V_159 = NULL ;
V_156 -> V_160 = 0 ;
if ( ! V_155 )
return 1 ;
while ( ( V_136 = F_65 ( & V_155 , L_49 ) ) != NULL ) {
int V_161 ;
if ( ! * V_136 )
continue;
V_161 = F_66 ( V_136 , V_162 , args ) ;
switch ( V_161 ) {
case V_163 :
if ( F_67 ( & args [ 0 ] , & V_158 ) )
return 0 ;
if ( V_158 < 0 ) {
F_53 ( V_131 L_50
L_51 , V_158 ) ;
break;
}
V_156 -> V_89 = V_158 ;
V_156 -> V_88 = 1 ;
break;
case V_164 :
if ( F_67 ( & args [ 0 ] , & V_158 ) )
return 0 ;
if ( V_158 < 0 ) {
F_53 ( V_131 L_52
L_51 , V_158 ) ;
break;
}
V_156 -> V_93 = V_158 ;
V_156 -> V_92 = 1 ;
break;
case V_165 :
F_16 ( V_156 -> V_159 ) ;
V_156 -> V_159 = F_68 ( & args [ 0 ] ) ;
if ( ! V_156 -> V_159 ) {
F_53 ( V_131 L_53
L_54 ) ;
return 0 ;
}
break;
case V_166 :
V_156 -> V_160 = 1 ;
break;
default:
F_53 ( V_131 L_55
L_56 , V_136 ) ;
return 0 ;
}
}
return 1 ;
}
static void
F_69 ( struct V_11 * V_12 )
{
F_16 ( F_12 ( V_12 ) -> V_87 . V_159 ) ;
F_12 ( V_12 ) -> V_87 . V_159 = NULL ;
F_70 ( F_12 ( V_12 ) -> V_35 ) ;
F_16 ( V_12 -> V_167 ) ;
V_12 -> V_167 = NULL ;
}
static int
F_71 ( struct V_11 * V_12 , void * V_115 , int V_168 )
{
struct V_8 * V_70 ;
T_9 * V_72 ;
T_14 * V_169 ;
struct V_7 * V_170 ;
long V_30 = - V_148 ;
const unsigned long V_171 = 0 ;
const T_15 V_172 = 512 ;
F_72 ( V_12 , V_115 ) ;
V_12 -> V_167 = F_57 ( sizeof ( * V_72 ) , V_62 ) ;
if ( V_12 -> V_167 == NULL ) {
F_53 ( V_131
L_57
L_58 , V_12 -> V_173 ) ;
goto V_80;
}
V_72 = F_12 ( V_12 ) ;
memset ( V_72 , 0 , sizeof( T_9 ) ) ;
if ( ! F_64 ( ( char * ) V_115 , & V_72 -> V_87 ) ) {
F_7 ( V_12 , L_59 ) ;
goto V_174;
}
F_6 ( V_12 , L_60 ) ;
#ifndef F_73
if ( ! ( V_12 -> V_175 & V_176 ) ) {
F_17 ( V_12 ,
L_61 ) ;
V_12 -> V_175 |= V_176 ;
}
#endif
F_74 ( V_12 , 1024 ) ;
if ( ! ( V_70 = F_75 ( V_12 , V_171 ) ) ) {
F_7 ( V_12 , L_62 ) ;
goto V_174;
}
V_169 = ( T_14 * ) V_70 -> V_81 ;
if ( ( V_169 -> V_177 == V_178 ) ||
( V_169 -> V_177 == V_179 ) ) {
F_6 ( V_12 , L_63 ) ;
} else {
F_6 ( V_12 , L_64 ) ;
V_169 =
( T_14 * ) ( ( void * ) V_70 -> V_81 + V_172 ) ;
}
if ( F_76 ( V_12 , V_169 ) != V_23 )
goto V_82;
F_77 ( V_12 , V_169 ) ;
F_48 ( V_70 ) ;
if ( F_78 ( V_12 ) != V_23 )
goto V_174;
if( V_72 -> V_180 > ~ ( ( T_1 ) 0 ) ) {
F_7 ( V_12 , L_65
L_66 ,
V_72 -> V_180 ) ;
goto V_174;
}
V_12 -> V_181 = V_182 ;
F_79 ( V_12 , ( T_4 ) V_72 -> V_112 ) ;
V_12 -> V_183 = & V_184 ;
V_170 = F_18 ( V_12 , F_9 ( V_12 , & ( V_72 -> V_185 ) ) ) ;
if ( F_19 ( V_170 ) ) {
V_30 = F_80 ( V_170 ) ;
goto V_174;
}
V_12 -> V_186 = F_81 ( V_170 ) ;
if ( ! V_12 -> V_186 ) {
F_82 ( V_170 ) ;
F_7 ( V_12 , L_67 ) ;
goto V_174;
}
if ( V_72 -> V_87 . V_159 ) {
F_6 ( V_12 , L_68 ,
V_72 -> V_87 . V_159 ) ;
V_72 -> V_35 = F_83 ( V_72 -> V_87 . V_159 ) ;
if ( ! V_72 -> V_35 ) {
F_17 ( V_12 , L_69
L_70 ,
V_72 -> V_87 . V_159 ) ;
V_72 -> V_35 = F_84 () ;
}
} else {
F_6 ( V_12 , L_71 ) ;
V_72 -> V_35 = F_84 () ;
}
return 0 ;
V_82:
F_48 ( V_70 ) ;
V_174:
F_16 ( V_72 -> V_87 . V_159 ) ;
F_16 ( V_12 -> V_167 ) ;
V_80:
V_12 -> V_167 = NULL ;
return V_30 ;
}
static int
F_85 ( struct V_11 * V_12 , int * V_108 , char * V_115 )
{
if ( ! ( * V_108 & V_176 ) )
return - V_148 ;
return 0 ;
}
static int
F_86 ( struct V_25 * V_25 , struct V_187 * V_188 )
{
struct V_11 * V_12 = V_25 -> V_134 ;
T_16 V_189 = F_87 ( V_12 -> V_190 -> V_191 ) ;
F_6 ( V_12 , L_72 ) ;
V_188 -> V_192 = V_182 ;
V_188 -> V_193 = V_12 -> V_194 ;
V_188 -> V_195 = F_12 ( V_12 ) -> V_180 ;
V_188 -> V_196 = F_12 ( V_12 ) -> V_180 - F_12 ( V_12 ) -> V_197 ;
V_188 -> V_198 = V_188 -> V_196 ;
V_188 -> V_199 = 0 ;
V_188 -> V_200 = 0 ;
V_188 -> V_201 . V_202 [ 0 ] = ( V_203 ) V_189 ;
V_188 -> V_201 . V_202 [ 1 ] = ( V_203 ) ( V_189 >> 32 ) ;
V_188 -> V_204 = V_50 ;
F_6 ( V_12 , L_73 ) ;
return 0 ;
}
static struct V_25 *
F_88 ( struct V_205 * V_206 , int V_108 , const char * V_207 ,
void * V_115 )
{
return F_89 ( V_206 , V_108 , V_207 , V_115 , F_71 ) ;
}
static int T_17
F_90 ( void )
{
int V_208 ;
F_53 ( V_209 L_74 , V_210 ) ;
V_208 = F_51 () ;
if ( V_208 )
goto V_80;
V_208 = F_91 ( & V_211 ) ;
if ( V_208 )
goto V_212;
return 0 ;
V_212:
F_54 () ;
V_80:
return V_208 ;
}
static void T_18
F_92 ( void )
{
F_54 () ;
F_93 ( & V_211 ) ;
}

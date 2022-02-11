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
V_25 -> V_33 . V_32 , V_26 -> V_20 ) ;
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
F_6 ( V_12 , L_8 , V_23 ,
V_25 -> V_33 . V_32 ) ;
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
const char * V_47 = V_1 -> V_48 . V_25 -> V_33 . V_32 ;
F_6 ( V_12 , L_11 ,
V_23 , V_47 , V_7 -> V_20 , V_40 -> V_49 ) ;
V_50:
V_42 = F_24 ( V_12 , V_14 , V_40 -> V_49 , V_46 + 1 ,
V_45 , & V_43 , & V_41 ) ;
if ( V_42 == V_51 ) {
F_6 ( V_12 , L_7 , V_23 ) ;
F_7 ( V_12 , L_12 ,
V_47 , V_7 -> V_20 ) ;
return - V_52 ;
} else if ( V_42 == V_53 ) {
F_6 ( V_12 , L_13 , V_23 ) ;
return 0 ;
} else if ( V_42 == V_54 ) {
F_6 ( V_12 , L_14 , V_23 ) ;
return 0 ;
}
V_44 = V_55 ;
if ( F_12 ( V_12 ) -> V_34 ) {
char * V_56 ;
int V_57 ;
V_42 =
F_25 ( V_12 , V_45 , V_43 , & V_56 , & V_57 ) ;
if ( V_42 < 0 ) {
F_6 ( V_12 , L_7 , V_23 ) ;
return V_42 ;
}
if ( ! F_26 ( V_40 , V_56 , V_57 ,
( V_38 ) V_41 , V_44 ) ) {
F_16 ( V_56 ) ;
return 0 ;
}
F_16 ( V_56 ) ;
} else {
if ( ! F_26 ( V_40 , V_45 , V_43 ,
( V_38 ) V_41 , V_44 ) )
return 0 ;
}
V_40 -> V_49 ++ ;
goto V_50;
F_6 ( V_12 , L_15 , V_23 , V_40 -> V_49 ) ;
return 0 ;
}
static struct V_7 *
F_27 ( struct V_11 * V_12 )
{
struct V_58 * V_59 ;
V_59 = (struct V_58 * ) F_28 ( V_60 ,
V_61 ) ;
if ( ! V_59 )
return NULL ;
return & V_59 -> V_62 ;
}
static void F_29 ( struct V_63 * V_64 )
{
struct V_7 * V_7 = F_30 ( V_64 , struct V_7 , V_65 ) ;
F_31 ( V_60 , F_5 ( V_7 ) ) ;
}
static void F_32 ( struct V_7 * V_7 )
{
F_33 ( & V_7 -> V_65 , F_29 ) ;
}
static void F_34 ( void * V_66 )
{
struct V_58 * V_59 = (struct V_58 * ) V_66 ;
F_35 ( & V_59 -> V_62 ) ;
}
static struct V_7 * F_18 ( struct V_11 * V_12 , unsigned long V_67 )
{
struct V_8 * V_68 = NULL ;
T_7 * V_69 = NULL ;
T_8 * V_70 = F_12 ( V_12 ) ;
V_58 * V_71 = NULL ;
struct V_7 * V_7 ;
long V_29 = - V_52 ;
F_6 ( V_12 , L_16 , V_23 , V_67 ) ;
V_7 = F_36 ( V_12 , V_67 ) ;
if ( ! V_7 )
return F_14 ( - V_72 ) ;
if ( ! ( V_7 -> V_73 & V_74 ) )
return V_7 ;
V_71 = F_5 ( V_7 ) ;
V_71 -> V_75 = F_37 ( V_12 , V_7 -> V_20 ) ;
F_6 ( V_12 , L_17 ,
V_71 -> V_75 . V_76 ,
V_71 -> V_75 . V_77 , V_71 -> V_75 . V_78 ) ;
V_68 = F_38 ( V_12 , V_7 -> V_20 ) ;
if ( ! V_68 ) {
F_7 ( V_12 , L_18
L_19 , V_7 -> V_20 ) ;
goto V_79;
}
V_69 = ( T_7 * ) V_68 -> V_80 ;
F_39 ( V_12 , V_69 ) ;
if ( F_40 ( V_12 , V_69 , V_7 -> V_20 ) != V_22 ) {
F_7 ( V_12 , L_20 , V_7 -> V_20 ) ;
goto V_81;
}
V_7 -> V_82 = ( V_83 ) F_41 ( V_12 , V_69 -> V_84 ) ;
V_7 -> V_85 = V_70 -> V_86 . V_87 ?
V_70 -> V_86 . V_88 :
F_42 ( & V_89 , F_41 ( V_12 , V_69 -> V_88 ) ) ;
V_7 -> V_90 = V_70 -> V_86 . V_91 ?
V_70 -> V_86 . V_92 :
F_43 ( & V_89 , F_41 ( V_12 , V_69 -> V_92 ) ) ;
F_44 ( V_7 , 1 ) ;
V_7 -> V_93 . V_94 =
F_45 ( V_12 , V_69 -> V_95 ) >> 16 ;
V_7 -> V_93 . V_96 = 0 ;
V_7 -> V_97 = V_7 -> V_93 ;
V_7 -> V_98 = V_7 -> V_93 ;
V_71 -> V_75 = F_46 ( V_12 , V_69 -> V_99 ) ;
V_71 -> V_100 = F_46 ( V_12 , V_69 -> V_101 ) ;
V_71 -> V_102 = F_46 ( V_12 , V_69 -> V_103 ) ;
V_71 -> V_104 = F_41 ( V_12 , V_69 -> V_27 ) ;
if ( F_47 ( V_7 -> V_82 ) && ! ( V_71 -> V_104 & V_105 ) ) {
V_7 -> V_106 = 0 ;
V_7 -> V_107 = V_70 -> V_108 / V_109 ;
F_48 ( V_71 -> V_15 . V_110 , V_69 -> V_111 . V_110 ,
V_112 ) ;
} else {
int V_113 ;
V_71 -> V_15 . V_14 =
F_49 ( V_12 , & V_69 -> V_111 . V_114 ) ;
V_113 = F_50 ( V_12 , & V_71 -> V_15 . V_14 ) ;
V_7 -> V_107 =
V_113 * ( V_70 -> V_108 / V_109 ) ;
V_7 -> V_106 = V_71 -> V_15 . V_14 . V_115 ;
}
V_7 -> V_116 -> V_117 = & V_118 ;
if ( F_51 ( V_7 -> V_82 ) ) {
V_7 -> V_119 = & V_120 ;
} else if ( F_52 ( V_7 -> V_82 ) ) {
V_7 -> V_121 = & V_122 ;
V_7 -> V_119 = & V_123 ;
} else if ( F_47 ( V_7 -> V_82 ) ) {
if ( V_71 -> V_104 & V_105 )
V_7 -> V_121 = & V_124 ;
else
V_7 -> V_121 = & V_125 ;
} else {
F_7 ( V_12 , L_21
L_22
L_23 , V_7 -> V_20 ) ;
goto V_81;
}
F_53 ( V_68 ) ;
F_6 ( V_12 , L_10 , V_23 ) ;
F_54 ( V_7 ) ;
return V_7 ;
V_81:
F_53 ( V_68 ) ;
V_79:
F_55 ( V_7 ) ;
F_6 ( V_12 , L_24 , V_23 ) ;
return F_14 ( V_29 ) ;
}
static int T_9
F_56 ( void )
{
V_60 = F_57 ( L_25 ,
sizeof ( struct V_58 ) ,
0 , ( V_126 |
V_127 ) ,
F_34 ) ;
if ( V_60 == NULL ) {
F_58 ( L_26 , V_23 ) ;
return - V_72 ;
}
return 0 ;
}
static void
F_59 ( void )
{
F_60 () ;
F_61 ( V_60 ) ;
}
static void *
F_62 ( struct V_25 * V_25 , struct V_128 * V_129 )
{
struct V_11 * V_12 = V_25 -> V_130 ;
V_58 * V_71 = F_5 ( V_25 -> V_131 ) ;
T_2 * V_111 = & V_71 -> V_15 . V_14 ;
T_5 V_78 = V_111 -> V_115 ;
char * V_132 ;
if ( V_78 == 0 ) {
F_7 ( V_12 , L_27 ) ;
V_132 = F_14 ( - V_52 ) ;
} else {
F_6 ( V_12 , L_28 ) ;
V_132 = F_63 ( V_78 , V_133 ) ;
if ( ! V_132 ) {
V_132 = F_14 ( - V_72 ) ;
} else if ( F_64 ( V_12 , V_111 , V_132 , V_78 ) != V_78 ) {
F_16 ( V_132 ) ;
F_7 ( V_12 , L_29 ) ;
V_132 = F_14 ( - V_52 ) ;
} else {
V_132 [ V_78 - 1 ] = '\0' ;
}
}
F_65 ( V_129 , V_132 ) ;
return NULL ;
}
static void *
F_66 ( struct V_25 * V_25 , struct V_128 * V_129 )
{
V_58 * V_71 = F_5 ( V_25 -> V_131 ) ;
F_65 ( V_129 , V_71 -> V_15 . V_110 ) ;
return NULL ;
}
static int
F_25 ( struct V_11 * V_12 , const char * V_134 ,
int V_135 , char * * V_136 , int * V_137 )
{
struct V_138 * V_34 = F_12 ( V_12 ) -> V_34 ;
int V_139 , V_140 ;
T_10 V_141 ;
int V_142 , V_143 ;
char * V_42 ;
int V_144 = V_135 + 1 ;
F_6 ( V_12 , L_30 , V_23 ) ;
if ( ! V_34 ) {
F_7 ( V_12 , L_31 , V_23 ) ;
return - V_145 ;
}
* V_136 = V_42 = F_63 ( V_144 , V_133 ) ;
if ( ! * V_136 ) {
F_7 ( V_12 , L_32 , V_23 ) ;
* V_137 = 0 ;
return - V_72 ;
}
for ( V_139 = V_140 = 0 ; V_139 < V_135 ; V_139 += V_143 , V_140 += V_142 ) {
V_143 = F_67 ( & V_134 [ V_139 ] , V_135 - V_139 , & V_141 ) ;
if ( V_143 < 0 )
goto V_146;
if ( V_141 > V_147 )
goto V_146;
V_142 = V_34 -> V_148 ( V_141 , & V_42 [ V_140 ] , V_135 - V_140 ) ;
if ( V_142 < 0 )
goto V_146;
}
V_42 [ V_140 ] = '\0' ;
* V_137 = V_140 ;
F_6 ( V_12 , L_10 , V_23 ) ;
return V_140 ;
V_146:
F_7 ( V_12 , L_33
L_34 , V_34 -> V_149 ) ;
F_6 ( V_12 , L_10 , V_23 ) ;
F_16 ( V_42 ) ;
return - V_150 ;
}
static int
F_13 ( struct V_11 * V_12 , const char * V_134 ,
int V_135 , char * * V_136 , int * V_137 )
{
struct V_138 * V_34 = F_12 ( V_12 ) -> V_34 ;
int V_139 , V_140 ;
T_11 V_141 ;
int V_142 , V_143 ;
char * V_42 ;
int V_144 = ( 3 * V_135 ) + 1 ;
F_6 ( V_12 , L_35 , V_23 ) ;
if ( ! V_34 ) {
F_7 ( V_12 , L_36 ,
V_23 ) ;
return - V_145 ;
}
* V_136 = V_42 = F_63 ( V_144 , V_133 ) ;
if ( ! * V_136 ) {
F_7 ( V_12 , L_32 , V_23 ) ;
* V_137 = 0 ;
return - V_72 ;
}
for ( V_139 = V_140 = 0 ; V_139 < V_135 ; V_139 += V_142 , V_140 += V_143 ) {
V_142 = V_34 -> V_151 ( & V_134 [ V_139 ] , V_135 - V_139 , & V_141 ) ;
if ( V_142 < 0 )
goto V_146;
V_143 = F_68 ( V_141 , & V_42 [ V_140 ] , 3 ) ;
if ( V_143 <= 0 )
goto V_146;
}
V_42 [ V_140 ] = '\0' ;
* V_137 = V_140 ;
F_6 ( V_12 , L_10 , V_23 ) ;
return V_139 ;
V_146:
F_7 ( V_12 , L_37
L_34 , V_34 -> V_149 ) ;
F_6 ( V_12 , L_10 , V_23 ) ;
F_16 ( V_42 ) ;
return - V_150 ;
}
static int
F_69 ( char * V_152 , T_12 * V_153 )
{
char * V_154 ;
T_13 args [ V_155 ] ;
int V_156 ;
T_14 V_88 ;
T_15 V_92 ;
V_153 -> V_88 = V_157 ;
V_153 -> V_92 = V_158 ;
V_153 -> V_87 = 0 ;
V_153 -> V_91 = 0 ;
V_153 -> V_159 = NULL ;
V_153 -> V_160 = 0 ;
if ( ! V_152 )
return 1 ;
while ( ( V_154 = F_70 ( & V_152 , L_38 ) ) != NULL ) {
int V_161 ;
if ( ! * V_154 )
continue;
V_161 = F_71 ( V_154 , V_162 , args ) ;
switch ( V_161 ) {
case V_163 :
if ( F_72 ( & args [ 0 ] , & V_156 ) )
return 0 ;
V_88 = V_164 ;
if ( V_156 >= 0 )
V_88 = F_42 ( F_73 () , V_156 ) ;
if ( ! F_74 ( V_88 ) ) {
F_58 ( L_39
L_40 , V_156 ) ;
break;
}
V_153 -> V_88 = V_88 ;
V_153 -> V_87 = 1 ;
break;
case V_165 :
if ( F_72 ( & args [ 0 ] , & V_156 ) )
return 0 ;
V_92 = V_166 ;
if ( V_156 >= 0 )
V_92 = F_43 ( F_73 () , V_156 ) ;
if ( ! F_75 ( V_92 ) ) {
F_58 ( L_41
L_40 , V_156 ) ;
break;
}
V_153 -> V_92 = V_92 ;
V_153 -> V_91 = 1 ;
break;
case V_167 :
F_16 ( V_153 -> V_159 ) ;
V_153 -> V_159 = F_76 ( & args [ 0 ] ) ;
if ( ! V_153 -> V_159 ) {
F_58 ( L_42
L_43 ) ;
return 0 ;
}
break;
case V_168 :
V_153 -> V_160 = 1 ;
break;
default:
F_58 ( L_44
L_45 , V_154 ) ;
return 0 ;
}
}
return 1 ;
}
static void
F_77 ( struct V_11 * V_12 )
{
F_16 ( F_12 ( V_12 ) -> V_86 . V_159 ) ;
F_12 ( V_12 ) -> V_86 . V_159 = NULL ;
F_78 ( F_12 ( V_12 ) -> V_34 ) ;
F_16 ( V_12 -> V_169 ) ;
V_12 -> V_169 = NULL ;
}
static int
F_79 ( struct V_11 * V_12 , void * V_111 , int V_170 )
{
struct V_8 * V_68 ;
T_8 * V_70 ;
T_16 * V_171 ;
struct V_7 * V_172 ;
long V_29 = - V_145 ;
const unsigned long V_173 = 0 ;
const T_17 V_174 = 512 ;
F_80 ( V_12 , V_111 ) ;
V_12 -> V_169 = F_81 ( sizeof( * V_70 ) , V_61 ) ;
if ( V_12 -> V_169 == NULL ) {
F_58 ( L_46
L_47 , V_12 -> V_175 ) ;
goto V_79;
}
V_70 = F_12 ( V_12 ) ;
if ( ! F_69 ( ( char * ) V_111 , & V_70 -> V_86 ) ) {
F_7 ( V_12 , L_48 ) ;
goto V_176;
}
F_6 ( V_12 , L_30 , V_23 ) ;
#ifndef F_82
if ( ! ( V_12 -> V_177 & V_178 ) ) {
F_17 ( V_12 ,
L_49 ) ;
V_12 -> V_177 |= V_178 ;
}
#endif
F_83 ( V_12 , 1024 ) ;
if ( ! ( V_68 = F_84 ( V_12 , V_173 ) ) ) {
F_7 ( V_12 , L_50 ) ;
goto V_176;
}
V_171 = ( T_16 * ) V_68 -> V_80 ;
if ( ( V_171 -> V_179 == V_180 ) ||
( V_171 -> V_179 == V_181 ) ) {
F_6 ( V_12 , L_51 ) ;
} else {
F_6 ( V_12 , L_52 ) ;
V_171 =
( T_16 * ) ( ( void * ) V_68 -> V_80 + V_174 ) ;
}
if ( F_85 ( V_12 , V_171 ) != V_22 )
goto V_81;
F_86 ( V_12 , V_171 ) ;
F_53 ( V_68 ) ;
if ( F_87 ( V_12 ) != V_22 )
goto V_176;
if( V_70 -> V_182 > ~ ( ( T_1 ) 0 ) ) {
F_7 ( V_12 , L_53
L_54 ,
V_70 -> V_182 ) ;
goto V_176;
}
V_12 -> V_183 = V_184 ;
F_88 ( V_12 , ( T_4 ) V_70 -> V_108 ) ;
V_12 -> V_185 = & V_186 ;
V_172 = F_18 ( V_12 , F_9 ( V_12 , & ( V_70 -> V_187 ) ) ) ;
if ( F_19 ( V_172 ) ) {
V_29 = F_89 ( V_172 ) ;
goto V_176;
}
V_12 -> V_188 = F_90 ( V_172 ) ;
if ( ! V_12 -> V_188 ) {
F_7 ( V_12 , L_55 ) ;
goto V_176;
}
if ( V_70 -> V_86 . V_159 ) {
F_6 ( V_12 , L_56 ,
V_70 -> V_86 . V_159 ) ;
V_70 -> V_34 = F_91 ( V_70 -> V_86 . V_159 ) ;
if ( ! V_70 -> V_34 ) {
F_17 ( V_12 , L_57
L_58 ,
V_70 -> V_86 . V_159 ) ;
V_70 -> V_34 = F_92 () ;
}
} else {
F_6 ( V_12 , L_59 ) ;
V_70 -> V_34 = F_92 () ;
}
return 0 ;
V_81:
F_53 ( V_68 ) ;
V_176:
F_16 ( V_70 -> V_86 . V_159 ) ;
F_16 ( V_12 -> V_169 ) ;
V_79:
V_12 -> V_169 = NULL ;
return V_29 ;
}
static int
F_93 ( struct V_11 * V_12 , int * V_27 , char * V_111 )
{
F_94 ( V_12 ) ;
if ( ! ( * V_27 & V_178 ) )
return - V_145 ;
return 0 ;
}
static int
F_95 ( struct V_25 * V_25 , struct V_189 * V_190 )
{
struct V_11 * V_12 = V_25 -> V_130 ;
T_18 V_191 = F_96 ( V_12 -> V_192 -> V_193 ) ;
F_6 ( V_12 , L_30 , V_23 ) ;
V_190 -> V_194 = V_184 ;
V_190 -> V_195 = V_12 -> V_196 ;
V_190 -> V_197 = F_12 ( V_12 ) -> V_182 ;
V_190 -> V_198 = F_12 ( V_12 ) -> V_182 - F_12 ( V_12 ) -> V_199 ;
V_190 -> V_200 = V_190 -> V_198 ;
V_190 -> V_201 = 0 ;
V_190 -> V_202 = 0 ;
V_190 -> V_203 . V_204 [ 0 ] = ( V_205 ) V_191 ;
V_190 -> V_203 . V_204 [ 1 ] = ( V_205 ) ( V_191 >> 32 ) ;
V_190 -> V_206 = V_46 ;
F_6 ( V_12 , L_10 , V_23 ) ;
return 0 ;
}
static struct V_25 *
F_97 ( struct V_207 * V_208 , int V_27 , const char * V_209 ,
void * V_111 )
{
return F_98 ( V_208 , V_27 , V_209 , V_111 , F_79 ) ;
}
static int T_9
F_99 ( void )
{
int V_210 ;
F_100 ( L_60 , V_211 ) ;
V_210 = F_56 () ;
if ( V_210 )
goto V_79;
V_210 = F_101 ( & V_212 ) ;
if ( V_210 )
goto V_213;
return 0 ;
V_213:
F_59 () ;
V_79:
return V_210 ;
}
static void T_19
F_102 ( void )
{
F_59 () ;
F_103 ( & V_212 ) ;
}

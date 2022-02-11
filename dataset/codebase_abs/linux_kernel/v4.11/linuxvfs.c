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
int V_18 ;
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
V_29 = F_15 ( V_12 , V_14 , V_32 , & V_28 ) ;
}
if ( V_29 == V_35 ) {
F_6 ( V_12 , L_8 , V_23 , V_25 ) ;
F_17 ( V_25 , NULL ) ;
return F_14 ( - V_36 ) ;
} else if ( V_29 != V_22 || V_28 == 0 ) {
F_7 ( V_12 , L_9 , V_23 ) ;
return F_14 ( - V_37 ) ;
}
V_7 = F_18 ( V_26 -> V_13 , ( V_38 ) V_28 ) ;
if ( F_19 ( V_7 ) )
return F_20 ( V_7 ) ;
F_17 ( V_25 , V_7 ) ;
F_6 ( V_12 , L_10 , V_23 ) ;
return NULL ;
}
static int
F_21 ( struct V_1 * V_1 , struct V_39 * V_40 )
{
struct V_7 * V_7 = F_22 ( V_1 ) ;
struct V_11 * V_12 = V_7 -> V_13 ;
const T_2 * V_14 = & F_5 ( V_7 ) -> V_15 . V_14 ;
T_5 V_41 ;
int V_42 ;
T_6 V_43 ;
char V_44 [ V_45 + 1 ] ;
F_6 ( V_12 , L_11 ,
V_23 , V_1 , V_7 -> V_20 , V_40 -> V_46 ) ;
while ( 1 ) {
V_42 = F_23 ( V_12 , V_14 , V_40 -> V_46 , V_45 + 1 ,
V_44 , & V_43 , & V_41 ) ;
if ( V_42 == V_47 ) {
F_6 ( V_12 , L_7 , V_23 ) ;
F_7 ( V_12 , L_12 ,
V_1 , V_7 -> V_20 ) ;
return - V_48 ;
} else if ( V_42 == V_49 ) {
F_6 ( V_12 , L_13 , V_23 ) ;
return 0 ;
} else if ( V_42 == V_50 ) {
F_6 ( V_12 , L_14 , V_23 ) ;
return 0 ;
}
if ( F_12 ( V_12 ) -> V_34 ) {
char * V_51 ;
int V_52 ;
V_42 =
F_24 ( V_12 , V_44 , V_43 , & V_51 ,
& V_52 ) ;
if ( V_42 < 0 ) {
F_6 ( V_12 , L_7 , V_23 ) ;
return V_42 ;
}
if ( ! F_25 ( V_40 , V_51 , V_52 ,
( V_38 ) V_41 , V_53 ) ) {
F_16 ( V_51 ) ;
return 0 ;
}
F_16 ( V_51 ) ;
} else {
if ( ! F_25 ( V_40 , V_44 , V_43 ,
( V_38 ) V_41 , V_53 ) )
return 0 ;
}
V_40 -> V_46 ++ ;
}
}
static struct V_7 *
F_26 ( struct V_11 * V_12 )
{
struct V_54 * V_55 ;
V_55 = F_27 ( V_56 , V_57 ) ;
if ( ! V_55 )
return NULL ;
return & V_55 -> V_58 ;
}
static void F_28 ( struct V_59 * V_60 )
{
struct V_7 * V_7 = F_29 ( V_60 , struct V_7 , V_61 ) ;
F_30 ( V_56 , F_5 ( V_7 ) ) ;
}
static void F_31 ( struct V_7 * V_7 )
{
F_32 ( & V_7 -> V_61 , F_28 ) ;
}
static void F_33 ( void * V_62 )
{
struct V_54 * V_55 = (struct V_54 * ) V_62 ;
F_34 ( & V_55 -> V_58 ) ;
}
static struct V_7 * F_18 ( struct V_11 * V_12 , unsigned long V_63 )
{
struct V_8 * V_64 ;
T_7 * V_65 ;
struct V_66 * V_67 = F_12 ( V_12 ) ;
struct V_54 * V_68 ;
struct V_7 * V_7 ;
F_6 ( V_12 , L_15 , V_23 , V_63 ) ;
V_7 = F_35 ( V_12 , V_63 ) ;
if ( ! V_7 )
return F_14 ( - V_69 ) ;
if ( ! ( V_7 -> V_70 & V_71 ) )
return V_7 ;
V_68 = F_5 ( V_7 ) ;
V_68 -> V_72 = F_36 ( V_12 , V_7 -> V_20 ) ;
F_6 ( V_12 , L_16 ,
V_68 -> V_72 . V_73 ,
V_68 -> V_72 . V_74 , V_68 -> V_72 . V_75 ) ;
V_64 = F_37 ( V_12 , V_7 -> V_20 ) ;
if ( ! V_64 ) {
F_7 ( V_12 , L_17
L_18 , V_7 -> V_20 ) ;
goto V_76;
}
V_65 = ( T_7 * ) V_64 -> V_77 ;
F_38 ( V_12 , V_65 ) ;
if ( F_39 ( V_12 , V_65 , V_7 -> V_20 ) != V_22 ) {
F_7 ( V_12 , L_19 , V_7 -> V_20 ) ;
goto V_78;
}
V_7 -> V_79 = ( V_80 ) F_40 ( V_12 , V_65 -> V_81 ) ;
V_7 -> V_82 = V_67 -> V_83 . V_84 ?
V_67 -> V_83 . V_85 :
F_41 ( & V_86 , F_40 ( V_12 , V_65 -> V_85 ) ) ;
V_7 -> V_87 = V_67 -> V_83 . V_88 ?
V_67 -> V_83 . V_89 :
F_42 ( & V_86 , F_40 ( V_12 , V_65 -> V_89 ) ) ;
F_43 ( V_7 , 1 ) ;
V_7 -> V_90 . V_91 =
F_44 ( V_12 , V_65 -> V_92 ) >> 16 ;
V_7 -> V_90 . V_93 = 0 ;
V_7 -> V_94 = V_7 -> V_90 ;
V_7 -> V_95 = V_7 -> V_90 ;
V_68 -> V_72 = F_45 ( V_12 , V_65 -> V_96 ) ;
V_68 -> V_97 = F_45 ( V_12 , V_65 -> V_98 ) ;
V_68 -> V_99 = F_45 ( V_12 , V_65 -> V_100 ) ;
V_68 -> V_101 = F_40 ( V_12 , V_65 -> V_27 ) ;
if ( F_46 ( V_7 -> V_79 ) && ! ( V_68 -> V_101 & V_102 ) ) {
V_7 -> V_103 = 0 ;
V_7 -> V_104 = V_67 -> V_105 / V_106 ;
F_47 ( V_68 -> V_15 . V_107 , V_65 -> V_108 . V_107 ,
V_109 ) ;
} else {
int V_110 ;
V_68 -> V_15 . V_14 =
F_48 ( V_12 , & V_65 -> V_108 . V_111 ) ;
V_110 = F_49 ( V_12 , & V_68 -> V_15 . V_14 ) ;
V_7 -> V_104 =
V_110 * ( V_67 -> V_105 / V_106 ) ;
V_7 -> V_103 = V_68 -> V_15 . V_14 . V_112 ;
}
V_7 -> V_113 -> V_114 = & V_115 ;
if ( F_50 ( V_7 -> V_79 ) ) {
V_7 -> V_116 = & V_117 ;
} else if ( F_51 ( V_7 -> V_79 ) ) {
V_7 -> V_118 = & V_119 ;
V_7 -> V_116 = & V_120 ;
} else if ( F_46 ( V_7 -> V_79 ) ) {
if ( V_68 -> V_101 & V_102 ) {
V_7 -> V_118 = & V_121 ;
F_52 ( V_7 ) ;
V_7 -> V_113 -> V_114 = & V_122 ;
} else {
V_7 -> V_123 = V_68 -> V_15 . V_107 ;
V_7 -> V_118 = & V_124 ;
}
} else {
F_7 ( V_12 , L_20
L_21
L_22 , V_7 -> V_20 ) ;
goto V_78;
}
F_53 ( V_64 ) ;
F_6 ( V_12 , L_10 , V_23 ) ;
F_54 ( V_7 ) ;
return V_7 ;
V_78:
F_53 ( V_64 ) ;
V_76:
F_55 ( V_7 ) ;
F_6 ( V_12 , L_23 , V_23 ) ;
return F_14 ( - V_48 ) ;
}
static int T_8
F_56 ( void )
{
V_56 = F_57 ( L_24 ,
sizeof ( struct V_54 ) ,
0 , ( V_125 |
V_126 | V_127 ) ,
F_33 ) ;
if ( V_56 == NULL )
return - V_69 ;
return 0 ;
}
static void
F_58 ( void )
{
F_59 () ;
F_60 ( V_56 ) ;
}
static int F_61 ( struct V_1 * V_128 , struct V_2 * V_2 )
{
struct V_7 * V_7 = V_2 -> V_5 -> V_129 ;
struct V_11 * V_12 = V_7 -> V_13 ;
struct V_54 * V_68 = F_5 ( V_7 ) ;
T_2 * V_108 = & V_68 -> V_15 . V_14 ;
T_5 V_75 = V_108 -> V_112 ;
char * V_130 = F_62 ( V_2 ) ;
if ( V_75 == 0 || V_75 > V_131 ) {
F_7 ( V_12 , L_25 ) ;
goto V_132;
}
F_6 ( V_12 , L_26 ) ;
if ( F_63 ( V_12 , V_108 , V_130 , V_75 ) != V_75 ) {
F_7 ( V_12 , L_27 ) ;
goto V_132;
}
V_130 [ V_75 - 1 ] = '\0' ;
F_64 ( V_2 ) ;
F_65 ( V_2 ) ;
return 0 ;
V_132:
F_66 ( V_2 ) ;
F_65 ( V_2 ) ;
return - V_48 ;
}
static int
F_24 ( struct V_11 * V_12 , const char * V_133 ,
int V_134 , char * * V_135 , int * V_136 )
{
struct V_137 * V_34 = F_12 ( V_12 ) -> V_34 ;
int V_138 , V_139 ;
T_9 V_140 ;
int V_141 , V_142 ;
char * V_42 ;
int V_143 = V_134 + 1 ;
F_6 ( V_12 , L_28 , V_23 ) ;
if ( ! V_34 ) {
F_7 ( V_12 , L_29 , V_23 ) ;
return - V_144 ;
}
* V_135 = V_42 = F_67 ( V_143 , V_145 ) ;
if ( ! * V_135 )
return - V_69 ;
for ( V_138 = V_139 = 0 ; V_138 < V_134 ; V_138 += V_142 , V_139 += V_141 ) {
V_142 = F_68 ( & V_133 [ V_138 ] , V_134 - V_138 , & V_140 ) ;
if ( V_142 < 0 )
goto V_146;
if ( V_140 > V_147 )
goto V_146;
V_141 = V_34 -> V_148 ( V_140 , & V_42 [ V_139 ] , V_134 - V_139 ) ;
if ( V_141 < 0 )
goto V_146;
}
V_42 [ V_139 ] = '\0' ;
* V_136 = V_139 ;
F_6 ( V_12 , L_10 , V_23 ) ;
return V_139 ;
V_146:
F_7 ( V_12 , L_30
L_31 , V_34 -> V_149 ) ;
F_6 ( V_12 , L_10 , V_23 ) ;
F_16 ( V_42 ) ;
return - V_150 ;
}
static int
F_13 ( struct V_11 * V_12 , const char * V_133 ,
int V_134 , char * * V_135 , int * V_136 )
{
struct V_137 * V_34 = F_12 ( V_12 ) -> V_34 ;
int V_138 , V_139 ;
T_10 V_140 ;
int V_141 , V_142 ;
char * V_42 ;
int V_143 = ( 3 * V_134 ) + 1 ;
F_6 ( V_12 , L_32 , V_23 ) ;
if ( ! V_34 ) {
F_7 ( V_12 , L_33 ,
V_23 ) ;
return - V_144 ;
}
* V_135 = V_42 = F_67 ( V_143 , V_145 ) ;
if ( ! * V_135 ) {
* V_136 = 0 ;
return - V_69 ;
}
for ( V_138 = V_139 = 0 ; V_138 < V_134 ; V_138 += V_141 , V_139 += V_142 ) {
V_141 = V_34 -> V_151 ( & V_133 [ V_138 ] , V_134 - V_138 , & V_140 ) ;
if ( V_141 < 0 )
goto V_146;
V_142 = F_69 ( V_140 , & V_42 [ V_139 ] , 3 ) ;
if ( V_142 <= 0 )
goto V_146;
}
V_42 [ V_139 ] = '\0' ;
* V_136 = V_139 ;
F_6 ( V_12 , L_10 , V_23 ) ;
return V_138 ;
V_146:
F_7 ( V_12 , L_30
L_31 , V_34 -> V_149 ) ;
F_6 ( V_12 , L_10 , V_23 ) ;
F_16 ( V_42 ) ;
return - V_150 ;
}
static struct V_7 * F_70 ( struct V_11 * V_12 , T_11 V_63 ,
T_12 V_152 )
{
return F_18 ( V_12 , V_63 ) ;
}
static struct V_25 * F_71 ( struct V_11 * V_12 ,
struct V_153 * V_153 , int V_154 , int V_155 )
{
return F_72 ( V_12 , V_153 , V_154 , V_155 ,
F_70 ) ;
}
static struct V_25 * F_73 ( struct V_11 * V_12 ,
struct V_153 * V_153 , int V_154 , int V_155 )
{
return F_74 ( V_12 , V_153 , V_154 , V_155 ,
F_70 ) ;
}
static int
F_75 ( char * V_156 , struct V_157 * V_158 )
{
char * V_159 ;
T_13 args [ V_160 ] ;
int V_161 ;
T_14 V_85 ;
T_15 V_89 ;
V_158 -> V_85 = V_162 ;
V_158 -> V_89 = V_163 ;
V_158 -> V_84 = 0 ;
V_158 -> V_88 = 0 ;
V_158 -> V_164 = NULL ;
V_158 -> V_165 = 0 ;
if ( ! V_156 )
return 1 ;
while ( ( V_159 = F_76 ( & V_156 , L_34 ) ) != NULL ) {
int V_166 ;
if ( ! * V_159 )
continue;
V_166 = F_77 ( V_159 , V_167 , args ) ;
switch ( V_166 ) {
case V_168 :
if ( F_78 ( & args [ 0 ] , & V_161 ) )
return 0 ;
V_85 = V_169 ;
if ( V_161 >= 0 )
V_85 = F_41 ( F_79 () , V_161 ) ;
if ( ! F_80 ( V_85 ) ) {
F_81 ( L_35
L_36 , V_161 ) ;
break;
}
V_158 -> V_85 = V_85 ;
V_158 -> V_84 = 1 ;
break;
case V_170 :
if ( F_78 ( & args [ 0 ] , & V_161 ) )
return 0 ;
V_89 = V_171 ;
if ( V_161 >= 0 )
V_89 = F_42 ( F_79 () , V_161 ) ;
if ( ! F_82 ( V_89 ) ) {
F_81 ( L_37
L_36 , V_161 ) ;
break;
}
V_158 -> V_89 = V_89 ;
V_158 -> V_88 = 1 ;
break;
case V_172 :
F_16 ( V_158 -> V_164 ) ;
V_158 -> V_164 = F_83 ( & args [ 0 ] ) ;
if ( ! V_158 -> V_164 ) {
F_81 ( L_38
L_39 ) ;
return 0 ;
}
break;
case V_173 :
V_158 -> V_165 = 1 ;
break;
default:
F_81 ( L_40
L_41 , V_159 ) ;
return 0 ;
}
}
return 1 ;
}
static void
F_84 ( struct V_11 * V_12 )
{
F_16 ( F_12 ( V_12 ) -> V_83 . V_164 ) ;
F_12 ( V_12 ) -> V_83 . V_164 = NULL ;
F_85 ( F_12 ( V_12 ) -> V_34 ) ;
F_16 ( V_12 -> V_174 ) ;
V_12 -> V_174 = NULL ;
}
static int
F_86 ( struct V_11 * V_12 , void * V_108 , int V_175 )
{
struct V_8 * V_64 ;
struct V_66 * V_67 ;
T_16 * V_176 ;
struct V_7 * V_177 ;
long V_29 = - V_144 ;
const unsigned long V_178 = 0 ;
const T_17 V_179 = 512 ;
int V_180 ;
F_87 ( V_12 , V_108 ) ;
V_12 -> V_174 = F_88 ( sizeof( * V_67 ) , V_57 ) ;
if ( V_12 -> V_174 == NULL )
goto V_76;
V_67 = F_12 ( V_12 ) ;
if ( ! F_75 ( ( char * ) V_108 , & V_67 -> V_83 ) ) {
if ( ! V_175 )
F_7 ( V_12 , L_42 ) ;
goto V_181;
}
F_6 ( V_12 , L_28 , V_23 ) ;
if ( ! ( V_12 -> V_182 & V_183 ) ) {
F_89 ( V_12 ,
L_43 ) ;
V_12 -> V_182 |= V_183 ;
}
V_180 = F_90 ( V_12 , 1024 ) ;
if ( ! V_180 ) {
if ( ! V_175 )
F_7 ( V_12 , L_44 ) ;
goto V_181;
}
V_64 = F_37 ( V_12 , V_178 ) ;
if ( ! V_64 ) {
if ( ! V_175 )
F_7 ( V_12 , L_45 ) ;
goto V_181;
}
V_176 = ( T_16 * ) V_64 -> V_77 ;
if ( ( V_176 -> V_184 == V_185 ) ||
( V_176 -> V_184 == V_186 ) ) {
F_6 ( V_12 , L_46 ) ;
} else {
F_6 ( V_12 , L_47 ) ;
V_176 =
( T_16 * ) ( ( void * ) V_64 -> V_77 + V_179 ) ;
}
if ( ( F_91 ( V_12 , V_176 ) != V_22 ) ||
( F_92 ( V_12 ) != V_22 ) )
goto V_78;
F_93 ( V_12 , V_176 ) ;
F_53 ( V_64 ) ;
if ( V_67 -> V_187 > ~ ( ( T_1 ) 0 ) ) {
if ( ! V_175 )
F_7 ( V_12 , L_48 ,
V_67 -> V_187 ) ;
goto V_181;
}
V_12 -> V_188 = V_189 ;
F_94 ( V_12 , ( T_4 ) V_67 -> V_105 ) ;
V_12 -> V_190 = & V_191 ;
V_12 -> V_192 = & V_193 ;
V_177 = F_18 ( V_12 , F_9 ( V_12 , & ( V_67 -> V_194 ) ) ) ;
if ( F_19 ( V_177 ) ) {
V_29 = F_95 ( V_177 ) ;
goto V_181;
}
V_12 -> V_195 = F_96 ( V_177 ) ;
if ( ! V_12 -> V_195 ) {
if ( ! V_175 )
F_7 ( V_12 , L_49 ) ;
goto V_181;
}
if ( V_67 -> V_83 . V_164 ) {
F_6 ( V_12 , L_50 ,
V_67 -> V_83 . V_164 ) ;
V_67 -> V_34 = F_97 ( V_67 -> V_83 . V_164 ) ;
if ( ! V_67 -> V_34 ) {
F_89 ( V_12 , L_51
L_52 ,
V_67 -> V_83 . V_164 ) ;
V_67 -> V_34 = F_98 () ;
}
} else {
F_6 ( V_12 , L_53 ) ;
V_67 -> V_34 = F_98 () ;
}
return 0 ;
V_78:
F_53 ( V_64 ) ;
V_181:
F_16 ( V_67 -> V_83 . V_164 ) ;
F_16 ( V_12 -> V_174 ) ;
V_12 -> V_174 = NULL ;
V_76:
return V_29 ;
}
static int
F_99 ( struct V_11 * V_12 , int * V_27 , char * V_108 )
{
F_100 ( V_12 ) ;
if ( ! ( * V_27 & V_183 ) )
return - V_144 ;
return 0 ;
}
static int
F_101 ( struct V_25 * V_25 , struct V_196 * V_197 )
{
struct V_11 * V_12 = V_25 -> V_198 ;
T_18 V_199 = F_102 ( V_12 -> V_200 -> V_201 ) ;
F_6 ( V_12 , L_28 , V_23 ) ;
V_197 -> V_202 = V_189 ;
V_197 -> V_203 = V_12 -> V_204 ;
V_197 -> V_205 = F_12 ( V_12 ) -> V_187 ;
V_197 -> V_206 = F_12 ( V_12 ) -> V_187 - F_12 ( V_12 ) -> V_207 ;
V_197 -> V_208 = V_197 -> V_206 ;
V_197 -> V_209 = 0 ;
V_197 -> V_210 = 0 ;
V_197 -> V_211 . V_212 [ 0 ] = ( V_213 ) V_199 ;
V_197 -> V_211 . V_212 [ 1 ] = ( V_213 ) ( V_199 >> 32 ) ;
V_197 -> V_214 = V_45 ;
F_6 ( V_12 , L_10 , V_23 ) ;
return 0 ;
}
static struct V_25 *
F_103 ( struct V_215 * V_216 , int V_27 , const char * V_217 ,
void * V_108 )
{
return F_104 ( V_216 , V_27 , V_217 , V_108 , F_86 ) ;
}
static int T_8
F_105 ( void )
{
int V_218 ;
F_106 ( L_54 , V_219 ) ;
V_218 = F_56 () ;
if ( V_218 )
goto V_76;
V_218 = F_107 ( & V_220 ) ;
if ( V_218 )
goto V_221;
return 0 ;
V_221:
F_58 () ;
V_76:
return V_218 ;
}
static void T_19
F_108 ( void )
{
F_58 () ;
F_109 ( & V_220 ) ;
}

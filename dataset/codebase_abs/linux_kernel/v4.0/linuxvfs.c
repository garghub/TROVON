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
T_8 * V_68 = F_12 ( V_12 ) ;
V_56 * V_69 = NULL ;
struct V_7 * V_7 ;
long V_29 = - V_50 ;
F_6 ( V_12 , L_15 , V_23 , V_65 ) ;
V_7 = F_36 ( V_12 , V_65 ) ;
if ( ! V_7 )
return F_14 ( - V_70 ) ;
if ( ! ( V_7 -> V_71 & V_72 ) )
return V_7 ;
V_69 = F_5 ( V_7 ) ;
V_69 -> V_73 = F_37 ( V_12 , V_7 -> V_20 ) ;
F_6 ( V_12 , L_16 ,
V_69 -> V_73 . V_74 ,
V_69 -> V_73 . V_75 , V_69 -> V_73 . V_76 ) ;
V_66 = F_38 ( V_12 , V_7 -> V_20 ) ;
if ( ! V_66 ) {
F_7 ( V_12 , L_17
L_18 , V_7 -> V_20 ) ;
goto V_77;
}
V_67 = ( T_7 * ) V_66 -> V_78 ;
F_39 ( V_12 , V_67 ) ;
if ( F_40 ( V_12 , V_67 , V_7 -> V_20 ) != V_22 ) {
F_7 ( V_12 , L_19 , V_7 -> V_20 ) ;
goto V_79;
}
V_7 -> V_80 = ( V_81 ) F_41 ( V_12 , V_67 -> V_82 ) ;
V_7 -> V_83 = V_68 -> V_84 . V_85 ?
V_68 -> V_84 . V_86 :
F_42 ( & V_87 , F_41 ( V_12 , V_67 -> V_86 ) ) ;
V_7 -> V_88 = V_68 -> V_84 . V_89 ?
V_68 -> V_84 . V_90 :
F_43 ( & V_87 , F_41 ( V_12 , V_67 -> V_90 ) ) ;
F_44 ( V_7 , 1 ) ;
V_7 -> V_91 . V_92 =
F_45 ( V_12 , V_67 -> V_93 ) >> 16 ;
V_7 -> V_91 . V_94 = 0 ;
V_7 -> V_95 = V_7 -> V_91 ;
V_7 -> V_96 = V_7 -> V_91 ;
V_69 -> V_73 = F_46 ( V_12 , V_67 -> V_97 ) ;
V_69 -> V_98 = F_46 ( V_12 , V_67 -> V_99 ) ;
V_69 -> V_100 = F_46 ( V_12 , V_67 -> V_101 ) ;
V_69 -> V_102 = F_41 ( V_12 , V_67 -> V_27 ) ;
if ( F_47 ( V_7 -> V_80 ) && ! ( V_69 -> V_102 & V_103 ) ) {
V_7 -> V_104 = 0 ;
V_7 -> V_105 = V_68 -> V_106 / V_107 ;
F_48 ( V_69 -> V_15 . V_108 , V_67 -> V_109 . V_108 ,
V_110 ) ;
} else {
int V_111 ;
V_69 -> V_15 . V_14 =
F_49 ( V_12 , & V_67 -> V_109 . V_112 ) ;
V_111 = F_50 ( V_12 , & V_69 -> V_15 . V_14 ) ;
V_7 -> V_105 =
V_111 * ( V_68 -> V_106 / V_107 ) ;
V_7 -> V_104 = V_69 -> V_15 . V_14 . V_113 ;
}
V_7 -> V_114 -> V_115 = & V_116 ;
if ( F_51 ( V_7 -> V_80 ) ) {
V_7 -> V_117 = & V_118 ;
} else if ( F_52 ( V_7 -> V_80 ) ) {
V_7 -> V_119 = & V_120 ;
V_7 -> V_117 = & V_121 ;
} else if ( F_47 ( V_7 -> V_80 ) ) {
if ( V_69 -> V_102 & V_103 )
V_7 -> V_119 = & V_122 ;
else
V_7 -> V_119 = & V_123 ;
} else {
F_7 ( V_12 , L_20
L_21
L_22 , V_7 -> V_20 ) ;
goto V_79;
}
F_53 ( V_66 ) ;
F_6 ( V_12 , L_10 , V_23 ) ;
F_54 ( V_7 ) ;
return V_7 ;
V_79:
F_53 ( V_66 ) ;
V_77:
F_55 ( V_7 ) ;
F_6 ( V_12 , L_23 , V_23 ) ;
return F_14 ( V_29 ) ;
}
static int T_9
F_56 ( void )
{
V_58 = F_57 ( L_24 ,
sizeof ( struct V_56 ) ,
0 , ( V_124 |
V_125 ) ,
F_34 ) ;
if ( V_58 == NULL ) {
F_58 ( L_25 , V_23 ) ;
return - V_70 ;
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
F_62 ( struct V_25 * V_25 , struct V_126 * V_127 )
{
struct V_11 * V_12 = V_25 -> V_128 ;
V_56 * V_69 = F_5 ( V_25 -> V_129 ) ;
T_2 * V_109 = & V_69 -> V_15 . V_14 ;
T_5 V_76 = V_109 -> V_113 ;
char * V_130 ;
if ( V_76 == 0 ) {
F_7 ( V_12 , L_26 ) ;
V_130 = F_14 ( - V_50 ) ;
} else {
F_6 ( V_12 , L_27 ) ;
V_130 = F_63 ( V_76 , V_131 ) ;
if ( ! V_130 ) {
V_130 = F_14 ( - V_70 ) ;
} else if ( F_64 ( V_12 , V_109 , V_130 , V_76 ) != V_76 ) {
F_16 ( V_130 ) ;
F_7 ( V_12 , L_28 ) ;
V_130 = F_14 ( - V_50 ) ;
} else {
V_130 [ V_76 - 1 ] = '\0' ;
}
}
F_65 ( V_127 , V_130 ) ;
return NULL ;
}
static void *
F_66 ( struct V_25 * V_25 , struct V_126 * V_127 )
{
V_56 * V_69 = F_5 ( V_25 -> V_129 ) ;
F_65 ( V_127 , V_69 -> V_15 . V_108 ) ;
return NULL ;
}
static int
F_25 ( struct V_11 * V_12 , const char * V_132 ,
int V_133 , char * * V_134 , int * V_135 )
{
struct V_136 * V_34 = F_12 ( V_12 ) -> V_34 ;
int V_137 , V_138 ;
T_10 V_139 ;
int V_140 , V_141 ;
char * V_42 ;
int V_142 = V_133 + 1 ;
F_6 ( V_12 , L_29 , V_23 ) ;
if ( ! V_34 ) {
F_7 ( V_12 , L_30 , V_23 ) ;
return - V_143 ;
}
* V_134 = V_42 = F_63 ( V_142 , V_131 ) ;
if ( ! * V_134 ) {
F_7 ( V_12 , L_31 , V_23 ) ;
* V_135 = 0 ;
return - V_70 ;
}
for ( V_137 = V_138 = 0 ; V_137 < V_133 ; V_137 += V_141 , V_138 += V_140 ) {
V_141 = F_67 ( & V_132 [ V_137 ] , V_133 - V_137 , & V_139 ) ;
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
T_11 V_139 ;
int V_140 , V_141 ;
char * V_42 ;
int V_142 = ( 3 * V_133 ) + 1 ;
F_6 ( V_12 , L_34 , V_23 ) ;
if ( ! V_34 ) {
F_7 ( V_12 , L_35 ,
V_23 ) ;
return - V_143 ;
}
* V_134 = V_42 = F_63 ( V_142 , V_131 ) ;
if ( ! * V_134 ) {
F_7 ( V_12 , L_31 , V_23 ) ;
* V_135 = 0 ;
return - V_70 ;
}
for ( V_137 = V_138 = 0 ; V_137 < V_133 ; V_137 += V_140 , V_138 += V_141 ) {
V_140 = V_34 -> V_149 ( & V_132 [ V_137 ] , V_133 - V_137 , & V_139 ) ;
if ( V_140 < 0 )
goto V_144;
V_141 = F_68 ( V_139 , & V_42 [ V_138 ] , 3 ) ;
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
F_69 ( char * V_150 , T_12 * V_151 )
{
char * V_152 ;
T_13 args [ V_153 ] ;
int V_154 ;
T_14 V_86 ;
T_15 V_90 ;
V_151 -> V_86 = V_155 ;
V_151 -> V_90 = V_156 ;
V_151 -> V_85 = 0 ;
V_151 -> V_89 = 0 ;
V_151 -> V_157 = NULL ;
V_151 -> V_158 = 0 ;
if ( ! V_150 )
return 1 ;
while ( ( V_152 = F_70 ( & V_150 , L_37 ) ) != NULL ) {
int V_159 ;
if ( ! * V_152 )
continue;
V_159 = F_71 ( V_152 , V_160 , args ) ;
switch ( V_159 ) {
case V_161 :
if ( F_72 ( & args [ 0 ] , & V_154 ) )
return 0 ;
V_86 = V_162 ;
if ( V_154 >= 0 )
V_86 = F_42 ( F_73 () , V_154 ) ;
if ( ! F_74 ( V_86 ) ) {
F_58 ( L_38
L_39 , V_154 ) ;
break;
}
V_151 -> V_86 = V_86 ;
V_151 -> V_85 = 1 ;
break;
case V_163 :
if ( F_72 ( & args [ 0 ] , & V_154 ) )
return 0 ;
V_90 = V_164 ;
if ( V_154 >= 0 )
V_90 = F_43 ( F_73 () , V_154 ) ;
if ( ! F_75 ( V_90 ) ) {
F_58 ( L_40
L_39 , V_154 ) ;
break;
}
V_151 -> V_90 = V_90 ;
V_151 -> V_89 = 1 ;
break;
case V_165 :
F_16 ( V_151 -> V_157 ) ;
V_151 -> V_157 = F_76 ( & args [ 0 ] ) ;
if ( ! V_151 -> V_157 ) {
F_58 ( L_41
L_42 ) ;
return 0 ;
}
break;
case V_166 :
V_151 -> V_158 = 1 ;
break;
default:
F_58 ( L_43
L_44 , V_152 ) ;
return 0 ;
}
}
return 1 ;
}
static void
F_77 ( struct V_11 * V_12 )
{
F_16 ( F_12 ( V_12 ) -> V_84 . V_157 ) ;
F_12 ( V_12 ) -> V_84 . V_157 = NULL ;
F_78 ( F_12 ( V_12 ) -> V_34 ) ;
F_16 ( V_12 -> V_167 ) ;
V_12 -> V_167 = NULL ;
}
static int
F_79 ( struct V_11 * V_12 , void * V_109 , int V_168 )
{
struct V_8 * V_66 ;
T_8 * V_68 ;
T_16 * V_169 ;
struct V_7 * V_170 ;
long V_29 = - V_143 ;
const unsigned long V_171 = 0 ;
const T_17 V_172 = 512 ;
F_80 ( V_12 , V_109 ) ;
V_12 -> V_167 = F_81 ( sizeof( * V_68 ) , V_59 ) ;
if ( V_12 -> V_167 == NULL ) {
F_58 ( L_45
L_46 , V_12 -> V_173 ) ;
goto V_77;
}
V_68 = F_12 ( V_12 ) ;
if ( ! F_69 ( ( char * ) V_109 , & V_68 -> V_84 ) ) {
F_7 ( V_12 , L_47 ) ;
goto V_174;
}
F_6 ( V_12 , L_29 , V_23 ) ;
if ( ! ( V_12 -> V_175 & V_176 ) ) {
F_17 ( V_12 ,
L_48 ) ;
V_12 -> V_175 |= V_176 ;
}
F_82 ( V_12 , 1024 ) ;
if ( ! ( V_66 = F_83 ( V_12 , V_171 ) ) ) {
F_7 ( V_12 , L_49 ) ;
goto V_174;
}
V_169 = ( T_16 * ) V_66 -> V_78 ;
if ( ( V_169 -> V_177 == V_178 ) ||
( V_169 -> V_177 == V_179 ) ) {
F_6 ( V_12 , L_50 ) ;
} else {
F_6 ( V_12 , L_51 ) ;
V_169 =
( T_16 * ) ( ( void * ) V_66 -> V_78 + V_172 ) ;
}
if ( ( F_84 ( V_12 , V_169 ) != V_22 ) ||
( F_85 ( V_12 ) != V_22 ) )
goto V_79;
F_86 ( V_12 , V_169 ) ;
F_53 ( V_66 ) ;
if( V_68 -> V_180 > ~ ( ( T_1 ) 0 ) ) {
F_7 ( V_12 , L_52
L_53 ,
V_68 -> V_180 ) ;
goto V_174;
}
V_12 -> V_181 = V_182 ;
F_87 ( V_12 , ( T_4 ) V_68 -> V_106 ) ;
V_12 -> V_183 = & V_184 ;
V_170 = F_18 ( V_12 , F_9 ( V_12 , & ( V_68 -> V_185 ) ) ) ;
if ( F_19 ( V_170 ) ) {
V_29 = F_88 ( V_170 ) ;
goto V_174;
}
V_12 -> V_186 = F_89 ( V_170 ) ;
if ( ! V_12 -> V_186 ) {
F_7 ( V_12 , L_54 ) ;
goto V_174;
}
if ( V_68 -> V_84 . V_157 ) {
F_6 ( V_12 , L_55 ,
V_68 -> V_84 . V_157 ) ;
V_68 -> V_34 = F_90 ( V_68 -> V_84 . V_157 ) ;
if ( ! V_68 -> V_34 ) {
F_17 ( V_12 , L_56
L_57 ,
V_68 -> V_84 . V_157 ) ;
V_68 -> V_34 = F_91 () ;
}
} else {
F_6 ( V_12 , L_58 ) ;
V_68 -> V_34 = F_91 () ;
}
return 0 ;
V_79:
F_53 ( V_66 ) ;
V_174:
F_16 ( V_68 -> V_84 . V_157 ) ;
F_16 ( V_12 -> V_167 ) ;
V_77:
V_12 -> V_167 = NULL ;
return V_29 ;
}
static int
F_92 ( struct V_11 * V_12 , int * V_27 , char * V_109 )
{
F_93 ( V_12 ) ;
if ( ! ( * V_27 & V_176 ) )
return - V_143 ;
return 0 ;
}
static int
F_94 ( struct V_25 * V_25 , struct V_187 * V_188 )
{
struct V_11 * V_12 = V_25 -> V_128 ;
T_18 V_189 = F_95 ( V_12 -> V_190 -> V_191 ) ;
F_6 ( V_12 , L_29 , V_23 ) ;
V_188 -> V_192 = V_182 ;
V_188 -> V_193 = V_12 -> V_194 ;
V_188 -> V_195 = F_12 ( V_12 ) -> V_180 ;
V_188 -> V_196 = F_12 ( V_12 ) -> V_180 - F_12 ( V_12 ) -> V_197 ;
V_188 -> V_198 = V_188 -> V_196 ;
V_188 -> V_199 = 0 ;
V_188 -> V_200 = 0 ;
V_188 -> V_201 . V_202 [ 0 ] = ( V_203 ) V_189 ;
V_188 -> V_201 . V_202 [ 1 ] = ( V_203 ) ( V_189 >> 32 ) ;
V_188 -> V_204 = V_46 ;
F_6 ( V_12 , L_10 , V_23 ) ;
return 0 ;
}
static struct V_25 *
F_96 ( struct V_205 * V_206 , int V_27 , const char * V_207 ,
void * V_109 )
{
return F_97 ( V_206 , V_27 , V_207 , V_109 , F_79 ) ;
}
static int T_9
F_98 ( void )
{
int V_208 ;
F_99 ( L_59 , V_209 ) ;
V_208 = F_56 () ;
if ( V_208 )
goto V_77;
V_208 = F_100 ( & V_210 ) ;
if ( V_208 )
goto V_211;
return 0 ;
V_211:
F_59 () ;
V_77:
return V_208 ;
}
static void T_19
F_101 ( void )
{
F_59 () ;
F_102 ( & V_210 ) ;
}

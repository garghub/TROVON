static void F_1 ( int V_1 , char * V_2 )
{
int V_3 = 0 ;
if ( V_1 & V_4 )
V_2 [ V_3 ++ ] = 'r' ;
if ( V_1 & V_5 )
V_2 [ V_3 ++ ] = 'w' ;
if ( V_1 & V_6 )
V_2 [ V_3 ++ ] = 'x' ;
if ( V_1 & V_7 )
V_2 [ V_3 ++ ] = 'a' ;
if ( V_1 & V_8 )
V_2 [ V_3 ++ ] = 't' ;
if ( V_1 & V_9 )
V_2 [ V_3 ++ ] = 'l' ;
if ( V_3 == 0 )
V_2 [ V_3 ++ ] = '-' ;
V_2 [ V_3 ] = '\0' ;
}
static int F_2 ( char * V_10 , struct V_11 * V_12 ,
struct V_11 * V_13 , int V_1 , int V_14 )
{
char V_15 [ V_16 + 1 ] ;
if ( V_14 <= 0 )
return V_14 ;
if ( V_14 > V_17 )
V_14 = 0 ;
F_1 ( V_1 , V_15 ) ;
F_3 ( L_1 , V_18 [ V_14 ] ,
V_12 -> V_19 , V_13 -> V_19 , V_15 , V_10 ) ;
return 0 ;
}
static int F_4 ( char * V_10 , struct V_11 * V_13 ,
int V_1 , int V_14 )
{
struct V_20 * V_21 = F_5 () ;
char V_15 [ V_16 + 1 ] ;
if ( V_14 <= 0 )
return V_14 ;
if ( V_14 > V_17 )
V_14 = 0 ;
F_1 ( V_1 , V_15 ) ;
F_3 ( L_2 , V_18 [ V_14 ] ,
V_21 -> V_22 -> V_19 , V_13 -> V_19 ,
V_15 , V_23 -> V_24 , V_10 ) ;
return 0 ;
}
static int F_6 ( struct V_25 * V_26 , int V_1 , int V_14 )
{
struct V_20 * V_21 = F_5 () ;
struct V_11 * V_22 = F_7 ( V_26 ) ;
char V_15 [ V_16 + 1 ] ;
if ( V_14 <= 0 )
return V_14 ;
if ( V_14 > V_17 )
V_14 = 0 ;
F_1 ( V_1 , V_15 ) ;
F_3 ( L_3 , V_18 [ V_14 ] ,
V_21 -> V_22 -> V_19 , V_22 -> V_19 , V_15 ,
V_23 -> V_24 , V_26 -> V_24 ) ;
return 0 ;
}
static int F_8 ( struct V_27 * V_27 , int V_1 , int V_14 )
{
struct V_20 * V_21 = F_5 () ;
struct V_28 * V_29 = V_27 -> V_30 ;
char V_15 [ V_16 + 1 ] ;
if ( V_29 -> V_31 & V_32 )
F_3 ( L_4 ,
V_27 -> V_33 -> V_34 , V_27 -> V_35 , V_23 -> V_24 ) ;
if ( V_14 <= 0 )
return V_14 ;
if ( V_14 > V_17 )
V_14 = 0 ;
if ( V_14 == V_36 &&
( V_1 & ( V_5 | V_7 ) ) )
V_29 -> V_31 |= V_32 ;
F_1 ( V_1 , V_15 ) ;
F_3 ( L_5 , V_18 [ V_14 ] ,
V_21 -> V_22 -> V_19 , V_29 -> V_37 -> V_19 , V_15 ,
V_27 -> V_33 -> V_34 , V_27 -> V_35 , V_23 -> V_24 ) ;
return 0 ;
}
static int F_9 ( struct V_38 * V_38 , int V_1 , int V_14 )
{
struct V_20 * V_21 = F_5 () ;
struct V_11 * V_12 = V_21 -> V_22 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
struct V_28 * V_29 = V_27 -> V_30 ;
char V_15 [ V_16 + 1 ] ;
if ( V_29 -> V_31 & V_32 )
F_3 ( L_4 ,
V_27 -> V_33 -> V_34 , V_27 -> V_35 , V_23 -> V_24 ) ;
if ( V_14 <= 0 )
return V_14 ;
if ( V_14 > V_17 )
V_14 = 0 ;
F_1 ( V_1 , V_15 ) ;
F_3 ( L_6 , V_18 [ V_14 ] ,
V_12 -> V_19 , F_11 ( V_27 ) -> V_19 , V_15 ,
V_27 -> V_33 -> V_34 , V_27 -> V_35 , V_38 ,
V_23 -> V_24 ) ;
return 0 ;
}
static int F_12 ( const struct V_39 * V_39 , struct V_38 * V_38 ,
int V_1 , int V_14 )
{
struct V_20 * V_21 = V_39 -> V_40 ;
struct V_11 * V_12 = V_21 -> V_22 ;
struct V_27 * V_27 = V_38 -> V_41 ;
struct V_28 * V_29 = V_27 -> V_30 ;
char V_15 [ V_16 + 1 ] ;
if ( V_29 -> V_31 & V_32 )
F_3 ( L_4 ,
V_27 -> V_33 -> V_34 , V_27 -> V_35 , V_23 -> V_24 ) ;
if ( V_14 <= 0 )
return V_14 ;
if ( V_14 > V_17 )
V_14 = 0 ;
F_1 ( V_1 , V_15 ) ;
F_3 ( L_6 , V_18 [ V_14 ] ,
V_12 -> V_19 , F_11 ( V_27 ) -> V_19 , V_15 ,
V_27 -> V_33 -> V_34 , V_27 -> V_35 , V_38 ,
V_23 -> V_24 ) ;
return 0 ;
}
static struct V_11 * F_13 ( const char * V_42 , struct V_27 * V_43 ,
struct V_44 * V_45 )
{
int V_14 ;
char * V_46 ;
struct V_11 * V_47 = NULL ;
if ( V_43 -> V_48 -> V_49 == NULL )
return F_14 ( - V_50 ) ;
V_46 = F_15 ( V_51 , V_52 ) ;
if ( V_46 == NULL )
return F_14 ( - V_53 ) ;
V_14 = V_43 -> V_48 -> V_49 ( V_45 , V_43 , V_42 , V_46 , V_51 ) ;
if ( V_14 < 0 )
V_47 = F_14 ( V_14 ) ;
else if ( V_14 == 0 )
V_47 = NULL ;
else
V_47 = F_16 ( V_46 , V_14 ) ;
F_17 ( V_46 ) ;
return V_47 ;
}
static struct V_28 * F_18 ( struct V_11 * V_47 )
{
struct V_28 * V_29 ;
V_29 = F_19 ( V_54 , V_55 ) ;
if ( V_29 == NULL )
return NULL ;
V_29 -> V_37 = V_47 ;
V_29 -> V_31 = 0 ;
F_20 ( & V_29 -> V_56 ) ;
return V_29 ;
}
static struct V_20 * F_21 ( struct V_11 * V_57 ,
struct V_11 * V_58 , T_1 V_59 )
{
struct V_20 * V_21 ;
V_21 = F_15 ( sizeof( struct V_20 ) , V_59 ) ;
if ( V_21 == NULL )
return NULL ;
V_21 -> V_22 = V_57 ;
V_21 -> V_60 = V_58 ;
F_22 ( & V_21 -> V_61 ) ;
F_22 ( & V_21 -> V_62 ) ;
F_20 ( & V_21 -> V_63 ) ;
return V_21 ;
}
static int F_23 ( struct V_64 * V_65 , struct V_64 * V_66 ,
T_1 V_59 )
{
struct V_67 * V_68 ;
struct V_67 * V_69 ;
int V_14 = 0 ;
F_22 ( V_65 ) ;
F_24 (orp, ohead, list) {
V_68 = F_15 ( sizeof( struct V_67 ) , V_59 ) ;
if ( V_68 == NULL ) {
V_14 = - V_53 ;
break;
}
* V_68 = * V_69 ;
F_25 ( & V_68 -> V_70 , V_65 ) ;
}
return V_14 ;
}
static int F_26 ( struct V_64 * V_65 , struct V_64 * V_66 ,
T_1 V_59 )
{
struct V_71 * V_72 ;
struct V_71 * V_73 ;
F_22 ( V_65 ) ;
F_27 (oklep, ohead, list) {
V_72 = F_15 ( sizeof( struct V_71 ) , V_59 ) ;
if ( V_72 == NULL ) {
F_28 ( V_65 ) ;
return - V_53 ;
}
V_72 -> V_74 = V_73 -> V_74 ;
F_29 ( & V_72 -> V_70 , V_65 ) ;
}
return 0 ;
}
static inline unsigned int F_30 ( unsigned int V_1 )
{
if ( V_1 & V_75 )
return V_76 ;
if ( V_1 & V_77 )
return V_4 ;
return 0 ;
}
static int F_31 ( struct V_25 * V_78 ,
struct V_11 * V_79 ,
unsigned int V_1 , const char * V_80 )
{
int V_14 ;
struct V_81 V_82 , * V_83 = NULL ;
struct V_20 * V_21 ;
struct V_11 * V_84 ;
if ( ( V_1 & V_85 ) == 0 ) {
F_32 ( & V_82 , V_80 , V_86 ) ;
F_33 ( & V_82 , V_78 ) ;
V_83 = & V_82 ;
}
F_34 () ;
V_21 = F_35 ( V_78 ) -> V_40 ;
V_84 = F_36 ( V_21 ) ;
if ( ( V_1 & V_75 ) &&
( V_87 == V_88 ||
V_87 == V_89 ) ) {
if ( V_84 -> V_19 == V_79 -> V_19 )
V_14 = 0 ;
else if ( V_87 == V_89 )
V_14 = - V_90 ;
else if ( F_37 ( V_91 ) )
V_14 = 0 ;
else
V_14 = - V_90 ;
if ( V_83 )
F_38 ( V_84 -> V_19 ,
V_79 -> V_19 ,
0 , V_14 , V_83 ) ;
F_39 () ;
return V_14 ;
}
V_14 = F_40 ( V_21 , V_79 , F_30 ( V_1 ) , V_83 ) ;
F_39 () ;
return V_14 ;
}
static int F_41 ( struct V_25 * V_92 , unsigned int V_1 )
{
struct V_11 * V_47 ;
V_47 = F_7 ( V_92 ) ;
return F_31 ( V_23 , V_47 , V_1 , V_93 ) ;
}
static int F_42 ( struct V_25 * V_94 )
{
int V_14 ;
struct V_11 * V_47 ;
V_47 = F_36 ( F_5 () ) ;
V_14 = F_31 ( V_94 , V_47 , V_75 , V_93 ) ;
return V_14 ;
}
static int F_43 ( int V_95 )
{
int V_14 = 0 ;
struct V_11 * V_47 = F_44 () ;
if ( F_45 ( V_96 ) )
return 0 ;
if ( V_97 != NULL && V_97 != V_47 )
V_14 = - V_90 ;
return V_14 ;
}
static int F_46 ( struct V_98 * V_99 )
{
struct V_100 * V_101 ;
V_101 = F_15 ( sizeof( struct V_100 ) , V_52 ) ;
if ( V_101 == NULL )
return - V_53 ;
V_101 -> V_102 = & V_103 ;
V_101 -> V_104 = & V_103 ;
V_101 -> V_105 = & V_103 ;
V_101 -> V_106 = & V_107 ;
V_99 -> V_108 = V_101 ;
return 0 ;
}
static void F_47 ( struct V_98 * V_99 )
{
F_17 ( V_99 -> V_108 ) ;
V_99 -> V_108 = NULL ;
}
static int F_48 ( char * V_109 , char * V_110 )
{
char * V_111 , * V_112 , * V_113 , * V_45 ;
V_113 = ( char * ) F_49 ( V_52 ) ;
if ( V_113 == NULL )
return - V_53 ;
for ( V_111 = V_109 , V_112 = V_109 ; V_112 != NULL ; V_111 = V_112 + 1 ) {
if ( strstr ( V_111 , V_114 ) == V_111 )
V_45 = V_110 ;
else if ( strstr ( V_111 , V_115 ) == V_111 )
V_45 = V_110 ;
else if ( strstr ( V_111 , V_116 ) == V_111 )
V_45 = V_110 ;
else if ( strstr ( V_111 , V_117 ) == V_111 )
V_45 = V_110 ;
else if ( strstr ( V_111 , V_118 ) == V_111 )
V_45 = V_110 ;
else
V_45 = V_113 ;
V_112 = strchr ( V_111 , ',' ) ;
if ( V_112 != NULL )
* V_112 = '\0' ;
if ( * V_45 != '\0' )
strcat ( V_45 , L_7 ) ;
strcat ( V_45 , V_111 ) ;
}
strcpy ( V_109 , V_113 ) ;
F_50 ( ( unsigned long ) V_113 ) ;
return 0 ;
}
static int F_51 ( char * V_119 ,
struct V_120 * V_121 )
{
char * V_122 ;
char * V_123 = NULL ;
char * V_124 = NULL ;
char * V_125 = NULL ;
char * V_126 = NULL ;
char * V_127 = NULL ;
int V_14 = - V_53 ;
int V_128 = 0 ;
int V_129 ;
V_121 -> V_128 = 0 ;
if ( ! V_119 )
return 0 ;
while ( ( V_122 = F_52 ( & V_119 , L_7 ) ) != NULL ) {
T_2 args [ V_130 ] ;
if ( ! * V_122 )
continue;
V_129 = F_53 ( V_122 , V_131 , args ) ;
switch ( V_129 ) {
case V_132 :
if ( V_123 )
goto V_133;
V_123 = F_54 ( & args [ 0 ] ) ;
if ( ! V_123 )
goto V_134;
break;
case V_135 :
if ( V_124 )
goto V_133;
V_124 = F_54 ( & args [ 0 ] ) ;
if ( ! V_124 )
goto V_134;
break;
case V_136 :
if ( V_125 )
goto V_133;
V_125 = F_54 ( & args [ 0 ] ) ;
if ( ! V_125 )
goto V_134;
break;
case V_137 :
if ( V_126 )
goto V_133;
V_126 = F_54 ( & args [ 0 ] ) ;
if ( ! V_126 )
goto V_134;
break;
case V_138 :
if ( V_127 )
goto V_133;
V_127 = F_54 ( & args [ 0 ] ) ;
if ( ! V_127 )
goto V_134;
break;
default:
V_14 = - V_139 ;
F_55 ( L_8 ) ;
goto V_134;
}
}
V_121 -> V_140 = F_56 ( V_141 , sizeof( char * ) , V_142 ) ;
if ( ! V_121 -> V_140 )
goto V_134;
V_121 -> V_143 = F_56 ( V_141 , sizeof( int ) ,
V_142 ) ;
if ( ! V_121 -> V_143 ) {
F_17 ( V_121 -> V_140 ) ;
goto V_134;
}
if ( V_123 ) {
V_121 -> V_140 [ V_128 ] = V_123 ;
V_121 -> V_143 [ V_128 ++ ] = V_144 ;
}
if ( V_124 ) {
V_121 -> V_140 [ V_128 ] = V_124 ;
V_121 -> V_143 [ V_128 ++ ] = V_145 ;
}
if ( V_125 ) {
V_121 -> V_140 [ V_128 ] = V_125 ;
V_121 -> V_143 [ V_128 ++ ] = V_146 ;
}
if ( V_126 ) {
V_121 -> V_140 [ V_128 ] = V_126 ;
V_121 -> V_143 [ V_128 ++ ] = V_147 ;
}
if ( V_127 ) {
V_121 -> V_140 [ V_128 ] = V_127 ;
V_121 -> V_143 [ V_128 ++ ] = V_148 ;
}
V_121 -> V_128 = V_128 ;
return 0 ;
V_133:
V_14 = - V_139 ;
F_55 ( L_9 ) ;
V_134:
F_17 ( V_123 ) ;
F_17 ( V_124 ) ;
F_17 ( V_125 ) ;
F_17 ( V_126 ) ;
F_17 ( V_127 ) ;
return V_14 ;
}
static int F_57 ( struct V_98 * V_99 ,
struct V_120 * V_121 ,
unsigned long V_149 ,
unsigned long * V_150 )
{
struct V_44 * V_151 = V_99 -> V_152 ;
struct V_27 * V_27 = F_58 ( V_151 ) ;
struct V_100 * V_153 = V_99 -> V_108 ;
struct V_28 * V_29 ;
struct V_11 * V_47 ;
int V_3 ;
int V_154 = V_121 -> V_128 ;
int V_155 = 0 ;
if ( V_153 -> V_31 & V_156 )
return 0 ;
V_153 -> V_31 |= V_156 ;
for ( V_3 = 0 ; V_3 < V_154 ; V_3 ++ ) {
switch ( V_121 -> V_143 [ V_3 ] ) {
case V_144 :
V_47 = F_16 ( V_121 -> V_140 [ V_3 ] , 0 ) ;
if ( F_59 ( V_47 ) )
return F_60 ( V_47 ) ;
V_153 -> V_104 = V_47 ;
break;
case V_145 :
V_47 = F_16 ( V_121 -> V_140 [ V_3 ] , 0 ) ;
if ( F_59 ( V_47 ) )
return F_60 ( V_47 ) ;
V_153 -> V_105 = V_47 ;
break;
case V_146 :
V_47 = F_16 ( V_121 -> V_140 [ V_3 ] , 0 ) ;
if ( F_59 ( V_47 ) )
return F_60 ( V_47 ) ;
V_153 -> V_106 = V_47 ;
break;
case V_147 :
V_47 = F_16 ( V_121 -> V_140 [ V_3 ] , 0 ) ;
if ( F_59 ( V_47 ) )
return F_60 ( V_47 ) ;
V_153 -> V_102 = V_47 ;
break;
case V_148 :
V_47 = F_16 ( V_121 -> V_140 [ V_3 ] , 0 ) ;
if ( F_59 ( V_47 ) )
return F_60 ( V_47 ) ;
V_153 -> V_102 = V_47 ;
V_155 = 1 ;
break;
default:
break;
}
}
if ( ! F_45 ( V_157 ) ) {
if ( V_154 )
return - V_158 ;
V_47 = F_44 () ;
V_153 -> V_102 = V_47 ;
V_153 -> V_104 = V_47 ;
if ( V_99 -> V_159 != & V_160 &&
V_99 -> V_161 != V_162 && V_99 -> V_161 != V_163 &&
V_99 -> V_161 != V_164 ) {
V_155 = 1 ;
V_153 -> V_31 |= V_165 ;
}
}
V_29 = V_27 -> V_30 ;
if ( V_29 == NULL ) {
V_29 = F_18 ( V_153 -> V_102 ) ;
if ( V_29 == NULL )
return - V_53 ;
V_27 -> V_30 = V_29 ;
} else
V_29 -> V_37 = V_153 -> V_102 ;
if ( V_155 )
V_29 -> V_31 |= V_166 ;
return 0 ;
}
static int F_61 ( struct V_98 * V_99 , int V_167 , void * V_168 )
{
int V_14 = 0 ;
char * V_119 = V_168 ;
struct V_120 V_121 ;
F_62 ( & V_121 ) ;
if ( ! V_119 )
goto V_169;
V_14 = F_51 ( V_119 , & V_121 ) ;
if ( V_14 )
goto V_134;
V_169:
V_14 = F_57 ( V_99 , & V_121 , 0 , NULL ) ;
V_134:
F_63 ( & V_121 ) ;
return V_14 ;
}
static int F_64 ( struct V_44 * V_44 )
{
struct V_100 * V_170 = V_44 -> V_171 -> V_108 ;
int V_14 ;
struct V_81 V_82 ;
F_32 ( & V_82 , V_93 , V_172 ) ;
F_65 ( & V_82 , V_44 ) ;
V_14 = F_66 ( V_170 -> V_105 , V_4 , & V_82 ) ;
V_14 = F_4 ( L_10 , V_170 -> V_105 , V_4 , V_14 ) ;
return V_14 ;
}
static int F_67 ( struct V_173 * V_174 )
{
struct V_27 * V_27 = F_10 ( V_174 -> V_38 ) ;
struct V_20 * V_175 = V_174 -> V_39 -> V_40 ;
struct V_28 * V_29 ;
struct V_100 * V_101 ;
int V_14 ;
if ( V_174 -> V_176 )
return 0 ;
V_29 = V_27 -> V_30 ;
if ( V_29 -> V_22 == NULL || V_29 -> V_22 == V_175 -> V_22 )
return 0 ;
V_101 = V_27 -> V_33 -> V_108 ;
if ( ( V_101 -> V_31 & V_165 ) &&
V_29 -> V_22 != V_101 -> V_102 )
return 0 ;
if ( V_174 -> V_177 & ( V_178 | V_179 ) ) {
struct V_25 * V_78 ;
V_14 = 0 ;
F_34 () ;
V_78 = F_68 ( V_23 ) ;
if ( F_69 ( V_78 != NULL ) )
V_14 = F_31 ( V_78 ,
V_29 -> V_22 ,
V_75 ,
V_93 ) ;
F_39 () ;
if ( V_14 != 0 )
return V_14 ;
} else if ( V_174 -> V_177 )
return - V_158 ;
V_175 -> V_22 = V_29 -> V_22 ;
V_174 -> V_180 |= V_181 ;
return 0 ;
}
static void F_70 ( struct V_173 * V_174 )
{
struct V_20 * V_175 = V_174 -> V_39 -> V_40 ;
if ( V_175 -> V_22 != V_175 -> V_60 )
V_23 -> V_182 = 0 ;
}
static int F_71 ( struct V_173 * V_174 )
{
struct V_20 * V_21 = F_5 () ;
if ( V_21 -> V_22 != V_21 -> V_60 )
return 1 ;
return 0 ;
}
static int F_72 ( struct V_27 * V_27 )
{
struct V_11 * V_47 = F_44 () ;
V_27 -> V_30 = F_18 ( V_47 ) ;
if ( V_27 -> V_30 == NULL )
return - V_53 ;
return 0 ;
}
static void F_73 ( struct V_27 * V_27 )
{
F_74 ( V_54 , V_27 -> V_30 ) ;
V_27 -> V_30 = NULL ;
}
static int F_75 ( struct V_27 * V_27 , struct V_27 * V_183 ,
const struct V_184 * V_184 , const char * * V_42 ,
void * * V_185 , T_3 * V_186 )
{
struct V_28 * V_187 = V_27 -> V_30 ;
struct V_11 * V_47 = F_44 () ;
struct V_11 * V_29 = F_11 ( V_27 ) ;
struct V_11 * V_188 = F_11 ( V_183 ) ;
int V_189 ;
if ( V_42 )
* V_42 = V_190 ;
if ( V_185 && V_186 ) {
F_34 () ;
V_189 = F_76 ( V_47 -> V_19 , V_188 -> V_19 ,
& V_47 -> V_61 ) ;
F_39 () ;
if ( V_189 > 0 && ( ( V_189 & V_8 ) != 0 ) &&
F_77 ( V_183 ) ) {
V_29 = V_188 ;
V_187 -> V_31 |= V_191 ;
}
* V_185 = F_78 ( V_29 -> V_19 , V_55 ) ;
if ( * V_185 == NULL )
return - V_53 ;
* V_186 = strlen ( V_29 -> V_19 ) ;
}
return 0 ;
}
static int F_79 ( struct V_44 * V_192 , struct V_27 * V_183 ,
struct V_44 * V_193 )
{
struct V_11 * V_29 ;
struct V_81 V_82 ;
int V_14 ;
F_32 ( & V_82 , V_93 , V_172 ) ;
F_65 ( & V_82 , V_192 ) ;
V_29 = F_11 ( F_58 ( V_192 ) ) ;
V_14 = F_66 ( V_29 , V_5 , & V_82 ) ;
V_14 = F_8 ( F_58 ( V_192 ) , V_5 , V_14 ) ;
if ( V_14 == 0 && F_80 ( V_193 ) ) {
V_29 = F_11 ( F_58 ( V_193 ) ) ;
F_65 ( & V_82 , V_193 ) ;
V_14 = F_66 ( V_29 , V_5 , & V_82 ) ;
V_14 = F_8 ( F_58 ( V_193 ) , V_5 , V_14 ) ;
}
return V_14 ;
}
static int F_81 ( struct V_27 * V_183 , struct V_44 * V_44 )
{
struct V_27 * V_43 = F_58 ( V_44 ) ;
struct V_81 V_82 ;
int V_14 ;
F_32 ( & V_82 , V_93 , V_172 ) ;
F_65 ( & V_82 , V_44 ) ;
V_14 = F_66 ( F_11 ( V_43 ) , V_5 , & V_82 ) ;
V_14 = F_8 ( V_43 , V_5 , V_14 ) ;
if ( V_14 == 0 ) {
F_32 ( & V_82 , V_93 , V_194 ) ;
F_82 ( & V_82 , V_183 ) ;
V_14 = F_66 ( F_11 ( V_183 ) , V_5 , & V_82 ) ;
V_14 = F_8 ( V_183 , V_5 , V_14 ) ;
}
return V_14 ;
}
static int F_83 ( struct V_27 * V_183 , struct V_44 * V_44 )
{
struct V_81 V_82 ;
int V_14 ;
F_32 ( & V_82 , V_93 , V_172 ) ;
F_65 ( & V_82 , V_44 ) ;
V_14 = F_66 ( F_11 ( F_58 ( V_44 ) ) , V_5 , & V_82 ) ;
V_14 = F_8 ( F_58 ( V_44 ) , V_5 , V_14 ) ;
if ( V_14 == 0 ) {
F_32 ( & V_82 , V_93 , V_194 ) ;
F_82 ( & V_82 , V_183 ) ;
V_14 = F_66 ( F_11 ( V_183 ) , V_5 , & V_82 ) ;
V_14 = F_8 ( V_183 , V_5 , V_14 ) ;
}
return V_14 ;
}
static int F_84 ( struct V_27 * V_195 ,
struct V_44 * V_192 ,
struct V_27 * V_196 ,
struct V_44 * V_193 )
{
int V_14 ;
struct V_11 * V_29 ;
struct V_81 V_82 ;
F_32 ( & V_82 , V_93 , V_172 ) ;
F_65 ( & V_82 , V_192 ) ;
V_29 = F_11 ( F_58 ( V_192 ) ) ;
V_14 = F_66 ( V_29 , V_76 , & V_82 ) ;
V_14 = F_8 ( F_58 ( V_192 ) , V_76 , V_14 ) ;
if ( V_14 == 0 && F_80 ( V_193 ) ) {
V_29 = F_11 ( F_58 ( V_193 ) ) ;
F_65 ( & V_82 , V_193 ) ;
V_14 = F_66 ( V_29 , V_76 , & V_82 ) ;
V_14 = F_8 ( F_58 ( V_193 ) , V_76 , V_14 ) ;
}
return V_14 ;
}
static int F_85 ( struct V_27 * V_27 , int V_197 )
{
struct V_100 * V_101 = V_27 -> V_33 -> V_108 ;
struct V_81 V_82 ;
int V_198 = V_197 & V_199 ;
int V_14 ;
V_197 &= ( V_4 | V_5 | V_6 | V_7 ) ;
if ( V_197 == 0 )
return 0 ;
if ( V_101 -> V_31 & V_165 ) {
if ( F_11 ( V_27 ) != V_101 -> V_102 )
return - V_90 ;
}
if ( V_198 )
return - V_200 ;
F_32 ( & V_82 , V_93 , V_194 ) ;
F_82 ( & V_82 , V_27 ) ;
V_14 = F_66 ( F_11 ( V_27 ) , V_197 , & V_82 ) ;
V_14 = F_8 ( V_27 , V_197 , V_14 ) ;
return V_14 ;
}
static int F_86 ( struct V_44 * V_44 , struct V_201 * V_201 )
{
struct V_81 V_82 ;
int V_14 ;
if ( V_201 -> V_202 & V_203 )
return 0 ;
F_32 ( & V_82 , V_93 , V_172 ) ;
F_65 ( & V_82 , V_44 ) ;
V_14 = F_66 ( F_11 ( F_58 ( V_44 ) ) , V_5 , & V_82 ) ;
V_14 = F_8 ( F_58 ( V_44 ) , V_5 , V_14 ) ;
return V_14 ;
}
static int F_87 ( const struct V_204 * V_204 )
{
struct V_81 V_82 ;
struct V_27 * V_27 = F_58 ( V_204 -> V_44 ) ;
int V_14 ;
F_32 ( & V_82 , V_93 , V_205 ) ;
F_88 ( & V_82 , * V_204 ) ;
V_14 = F_66 ( F_11 ( V_27 ) , V_4 , & V_82 ) ;
V_14 = F_8 ( V_27 , V_4 , V_14 ) ;
return V_14 ;
}
static int F_89 ( struct V_44 * V_44 , const char * V_42 ,
const void * V_185 , T_3 V_206 , int V_167 )
{
struct V_81 V_82 ;
struct V_11 * V_47 ;
int V_207 = 0 ;
int V_208 = 0 ;
int V_209 = 0 ;
int V_14 = 0 ;
if ( strcmp ( V_42 , V_210 ) == 0 ||
strcmp ( V_42 , V_211 ) == 0 ||
strcmp ( V_42 , V_212 ) == 0 ) {
V_207 = 1 ;
V_208 = 1 ;
} else if ( strcmp ( V_42 , V_213 ) == 0 ||
strcmp ( V_42 , V_214 ) == 0 ) {
V_207 = 1 ;
V_208 = 1 ;
V_209 = 1 ;
} else if ( strcmp ( V_42 , V_215 ) == 0 ) {
V_207 = 1 ;
if ( V_206 != V_216 ||
strncmp ( V_185 , V_217 , V_216 ) != 0 )
V_14 = - V_139 ;
} else
V_14 = F_90 ( V_44 , V_42 , V_185 , V_206 , V_167 ) ;
if ( V_207 && ! F_45 ( V_157 ) )
V_14 = - V_158 ;
if ( V_14 == 0 && V_208 ) {
V_47 = V_206 ? F_16 ( V_185 , V_206 ) : NULL ;
if ( F_59 ( V_47 ) )
V_14 = F_60 ( V_47 ) ;
else if ( V_47 == NULL || ( V_209 &&
( V_47 == & V_218 || V_47 == & V_219 ) ) )
V_14 = - V_139 ;
}
F_32 ( & V_82 , V_93 , V_172 ) ;
F_65 ( & V_82 , V_44 ) ;
if ( V_14 == 0 ) {
V_14 = F_66 ( F_11 ( F_58 ( V_44 ) ) , V_5 , & V_82 ) ;
V_14 = F_8 ( F_58 ( V_44 ) , V_5 , V_14 ) ;
}
return V_14 ;
}
static void F_91 ( struct V_44 * V_44 , const char * V_42 ,
const void * V_185 , T_3 V_206 , int V_167 )
{
struct V_11 * V_47 ;
struct V_28 * V_29 = F_58 ( V_44 ) -> V_30 ;
if ( strcmp ( V_42 , V_215 ) == 0 ) {
V_29 -> V_31 |= V_166 ;
return;
}
if ( strcmp ( V_42 , V_210 ) == 0 ) {
V_47 = F_16 ( V_185 , V_206 ) ;
if ( ! F_59 ( V_47 ) )
V_29 -> V_37 = V_47 ;
else
V_29 -> V_37 = & V_220 ;
} else if ( strcmp ( V_42 , V_213 ) == 0 ) {
V_47 = F_16 ( V_185 , V_206 ) ;
if ( ! F_59 ( V_47 ) )
V_29 -> V_22 = V_47 ;
else
V_29 -> V_22 = & V_220 ;
} else if ( strcmp ( V_42 , V_214 ) == 0 ) {
V_47 = F_16 ( V_185 , V_206 ) ;
if ( ! F_59 ( V_47 ) )
V_29 -> V_221 = V_47 ;
else
V_29 -> V_221 = & V_220 ;
}
return;
}
static int F_92 ( struct V_44 * V_44 , const char * V_42 )
{
struct V_81 V_82 ;
int V_14 ;
F_32 ( & V_82 , V_93 , V_172 ) ;
F_65 ( & V_82 , V_44 ) ;
V_14 = F_66 ( F_11 ( F_58 ( V_44 ) ) , V_4 , & V_82 ) ;
V_14 = F_8 ( F_58 ( V_44 ) , V_4 , V_14 ) ;
return V_14 ;
}
static int F_93 ( struct V_44 * V_44 , const char * V_42 )
{
struct V_28 * V_29 ;
struct V_81 V_82 ;
int V_14 = 0 ;
if ( strcmp ( V_42 , V_210 ) == 0 ||
strcmp ( V_42 , V_211 ) == 0 ||
strcmp ( V_42 , V_212 ) == 0 ||
strcmp ( V_42 , V_213 ) == 0 ||
strcmp ( V_42 , V_215 ) == 0 ||
strcmp ( V_42 , V_214 ) == 0 ) {
if ( ! F_45 ( V_157 ) )
V_14 = - V_158 ;
} else
V_14 = F_94 ( V_44 , V_42 ) ;
if ( V_14 != 0 )
return V_14 ;
F_32 ( & V_82 , V_93 , V_172 ) ;
F_65 ( & V_82 , V_44 ) ;
V_14 = F_66 ( F_11 ( F_58 ( V_44 ) ) , V_5 , & V_82 ) ;
V_14 = F_8 ( F_58 ( V_44 ) , V_5 , V_14 ) ;
if ( V_14 != 0 )
return V_14 ;
V_29 = F_58 ( V_44 ) -> V_30 ;
if ( strcmp ( V_42 , V_210 ) == 0 ) {
struct V_98 * V_170 = V_44 -> V_171 ;
struct V_100 * V_101 = V_170 -> V_108 ;
V_29 -> V_37 = V_101 -> V_104 ;
} else if ( strcmp ( V_42 , V_213 ) == 0 )
V_29 -> V_22 = NULL ;
else if ( strcmp ( V_42 , V_214 ) == 0 )
V_29 -> V_221 = NULL ;
else if ( strcmp ( V_42 , V_215 ) == 0 )
V_29 -> V_31 &= ~ V_166 ;
return 0 ;
}
static int F_95 ( struct V_27 * V_27 ,
const char * V_42 , void * * V_46 ,
bool V_222 )
{
struct V_223 * V_224 ;
struct V_225 * V_226 ;
struct V_98 * V_170 ;
struct V_27 * V_43 = (struct V_27 * ) V_27 ;
struct V_11 * V_29 ;
int V_227 ;
int V_14 = 0 ;
if ( strcmp ( V_42 , V_190 ) == 0 ) {
V_29 = F_11 ( V_27 ) ;
V_227 = strlen ( V_29 -> V_19 ) ;
* V_46 = V_29 -> V_19 ;
return V_227 ;
}
V_170 = V_43 -> V_33 ;
if ( V_170 -> V_161 != V_228 )
return - V_50 ;
V_226 = F_96 ( V_43 ) ;
if ( V_226 == NULL || V_226 -> V_229 == NULL )
return - V_50 ;
V_224 = V_226 -> V_229 -> V_230 ;
if ( strcmp ( V_42 , V_231 ) == 0 )
V_29 = V_224 -> V_232 ;
else if ( strcmp ( V_42 , V_233 ) == 0 )
V_29 = V_224 -> V_234 ;
else
return - V_50 ;
V_227 = strlen ( V_29 -> V_19 ) ;
if ( V_14 == 0 ) {
* V_46 = V_29 -> V_19 ;
V_14 = V_227 ;
}
return V_14 ;
}
static int F_97 ( struct V_27 * V_27 , char * V_46 ,
T_3 V_235 )
{
int V_186 = sizeof( V_210 ) ;
if ( V_46 != NULL && V_186 <= V_235 )
memcpy ( V_46 , V_210 , V_186 ) ;
return V_186 ;
}
static void F_98 ( struct V_27 * V_27 , T_4 * V_236 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
* V_236 = V_29 -> V_37 -> V_237 ;
}
static int F_99 ( struct V_38 * V_38 )
{
struct V_11 * V_47 = F_44 () ;
V_38 -> V_238 = V_47 ;
return 0 ;
}
static void F_100 ( struct V_38 * V_38 )
{
V_38 -> V_238 = NULL ;
}
static int F_101 ( struct V_38 * V_38 , unsigned int V_239 ,
unsigned long V_240 )
{
int V_14 = 0 ;
struct V_81 V_82 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
F_32 ( & V_82 , V_93 , V_205 ) ;
F_88 ( & V_82 , V_38 -> V_241 ) ;
if ( F_102 ( V_239 ) & V_242 ) {
V_14 = F_66 ( F_11 ( V_27 ) , V_5 , & V_82 ) ;
V_14 = F_9 ( V_38 , V_5 , V_14 ) ;
}
if ( V_14 == 0 && ( F_102 ( V_239 ) & V_243 ) ) {
V_14 = F_66 ( F_11 ( V_27 ) , V_4 , & V_82 ) ;
V_14 = F_9 ( V_38 , V_4 , V_14 ) ;
}
return V_14 ;
}
static int F_103 ( struct V_38 * V_38 , unsigned int V_239 )
{
struct V_81 V_82 ;
int V_14 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
F_32 ( & V_82 , V_93 , V_205 ) ;
F_88 ( & V_82 , V_38 -> V_241 ) ;
V_14 = F_66 ( F_11 ( V_27 ) , V_9 , & V_82 ) ;
V_14 = F_9 ( V_38 , V_9 , V_14 ) ;
return V_14 ;
}
static int F_104 ( struct V_38 * V_38 , unsigned int V_239 ,
unsigned long V_240 )
{
struct V_81 V_82 ;
int V_14 = 0 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
switch ( V_239 ) {
case V_244 :
break;
case V_245 :
case V_246 :
F_32 ( & V_82 , V_93 , V_205 ) ;
F_88 ( & V_82 , V_38 -> V_241 ) ;
V_14 = F_66 ( F_11 ( V_27 ) , V_9 , & V_82 ) ;
V_14 = F_9 ( V_38 , V_9 , V_14 ) ;
break;
case V_247 :
case V_248 :
F_32 ( & V_82 , V_93 , V_205 ) ;
F_88 ( & V_82 , V_38 -> V_241 ) ;
V_14 = F_66 ( F_11 ( V_27 ) , V_5 , & V_82 ) ;
V_14 = F_9 ( V_38 , V_5 , V_14 ) ;
break;
default:
break;
}
return V_14 ;
}
static int F_105 ( struct V_38 * V_38 ,
unsigned long V_249 , unsigned long V_250 ,
unsigned long V_167 )
{
struct V_11 * V_47 ;
struct V_11 * V_251 ;
struct V_67 * V_252 ;
struct V_20 * V_21 ;
struct V_11 * V_253 ;
struct V_28 * V_29 ;
struct V_100 * V_101 ;
int V_189 ;
int V_254 ;
int V_255 ;
int V_14 ;
if ( V_38 == NULL )
return 0 ;
V_29 = F_10 ( V_38 ) -> V_30 ;
if ( V_29 -> V_221 == NULL )
return 0 ;
V_101 = F_10 ( V_38 ) -> V_33 -> V_108 ;
if ( V_101 -> V_31 & V_165 &&
V_29 -> V_221 != V_101 -> V_102 )
return - V_90 ;
V_251 = V_29 -> V_221 ;
V_21 = F_5 () ;
V_47 = F_44 () ;
V_14 = 0 ;
F_34 () ;
F_24 (srp, &skp->smk_rules, list) {
V_253 = V_252 -> V_256 ;
if ( V_251 -> V_19 == V_253 -> V_19 )
continue;
V_189 = F_76 ( V_252 -> V_257 -> V_19 ,
V_253 -> V_19 ,
& V_21 -> V_61 ) ;
if ( V_189 == - V_258 )
V_189 = V_252 -> V_259 ;
else
V_189 &= V_252 -> V_259 ;
if ( V_189 == 0 )
continue;
V_254 = F_76 ( V_251 -> V_19 , V_253 -> V_19 ,
& V_251 -> V_61 ) ;
if ( V_254 == - V_258 ) {
V_14 = - V_90 ;
break;
}
V_255 = F_76 ( V_251 -> V_19 , V_253 -> V_19 ,
& V_21 -> V_61 ) ;
if ( V_255 != - V_258 )
V_254 &= V_255 ;
if ( ( V_189 | V_254 ) != V_254 ) {
V_14 = - V_90 ;
break;
}
}
F_39 () ;
return V_14 ;
}
static void F_106 ( struct V_38 * V_38 )
{
V_38 -> V_238 = F_44 () ;
}
static int F_107 ( struct V_25 * V_260 ,
struct V_261 * V_262 , int V_263 )
{
struct V_11 * V_47 ;
struct V_11 * V_264 = F_36 ( V_260 -> V_39 -> V_40 ) ;
struct V_38 * V_38 ;
int V_14 ;
struct V_81 V_82 ;
V_38 = F_108 ( V_262 , struct V_38 , V_265 ) ;
V_47 = V_38 -> V_238 ;
V_14 = V_259 ( V_47 , V_264 , V_5 , NULL ) ;
V_14 = F_2 ( L_11 , V_47 , V_264 , V_5 , V_14 ) ;
if ( V_14 != 0 && F_109 ( V_260 , V_96 ) )
V_14 = 0 ;
F_32 ( & V_82 , V_93 , V_86 ) ;
F_33 ( & V_82 , V_260 ) ;
F_38 ( V_47 -> V_19 , V_264 -> V_19 , V_5 , V_14 , & V_82 ) ;
return V_14 ;
}
static int F_110 ( struct V_38 * V_38 )
{
int V_14 ;
int V_189 = 0 ;
struct V_81 V_82 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
struct V_225 * V_226 ;
struct V_20 * V_21 ;
struct V_223 * V_224 ;
if ( F_111 ( F_112 ( V_27 ) ) )
return 0 ;
F_32 ( & V_82 , V_93 , V_205 ) ;
F_88 ( & V_82 , V_38 -> V_241 ) ;
if ( F_113 ( V_27 -> V_266 ) ) {
V_226 = F_96 ( V_27 ) ;
V_224 = V_226 -> V_229 -> V_230 ;
V_21 = F_5 () ;
V_14 = V_259 ( V_21 -> V_22 , V_224 -> V_234 , V_5 , & V_82 ) ;
V_14 = F_9 ( V_38 , V_189 , V_14 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = V_259 ( V_224 -> V_232 , V_21 -> V_22 , V_5 , & V_82 ) ;
V_14 = F_9 ( V_38 , V_189 , V_14 ) ;
return V_14 ;
}
if ( V_38 -> V_267 & V_268 )
V_189 = V_4 ;
if ( V_38 -> V_267 & V_269 )
V_189 |= V_5 ;
V_14 = F_66 ( F_11 ( V_27 ) , V_189 , & V_82 ) ;
V_14 = F_9 ( V_38 , V_189 , V_14 ) ;
return V_14 ;
}
static int F_114 ( struct V_38 * V_38 , const struct V_39 * V_39 )
{
struct V_20 * V_21 = V_39 -> V_40 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
struct V_81 V_82 ;
int V_14 ;
if ( F_45 ( V_96 ) )
return 0 ;
F_32 ( & V_82 , V_93 , V_205 ) ;
F_88 ( & V_82 , V_38 -> V_241 ) ;
V_14 = V_259 ( V_21 -> V_22 , F_11 ( V_27 ) , V_4 , & V_82 ) ;
V_14 = F_12 ( V_39 , V_38 , V_4 , V_14 ) ;
return V_14 ;
}
static int F_115 ( struct V_39 * V_39 , T_1 V_59 )
{
struct V_20 * V_21 ;
V_21 = F_21 ( NULL , NULL , V_59 ) ;
if ( V_21 == NULL )
return - V_53 ;
V_39 -> V_40 = V_21 ;
return 0 ;
}
static void F_116 ( struct V_39 * V_39 )
{
struct V_20 * V_21 = V_39 -> V_40 ;
struct V_67 * V_270 ;
struct V_64 * V_271 ;
struct V_64 * V_272 ;
if ( V_21 == NULL )
return;
V_39 -> V_40 = NULL ;
F_28 ( & V_21 -> V_62 ) ;
F_117 (l, n, &tsp->smk_rules) {
V_270 = F_118 ( V_271 , struct V_67 , V_70 ) ;
F_119 ( & V_270 -> V_70 ) ;
F_17 ( V_270 ) ;
}
F_17 ( V_21 ) ;
}
static int F_120 ( struct V_39 * V_273 , const struct V_39 * V_274 ,
T_1 V_59 )
{
struct V_20 * V_275 = V_274 -> V_40 ;
struct V_20 * V_276 ;
int V_14 ;
V_276 = F_21 ( V_275 -> V_22 , V_275 -> V_22 , V_59 ) ;
if ( V_276 == NULL )
return - V_53 ;
V_14 = F_23 ( & V_276 -> V_61 , & V_275 -> V_61 , V_59 ) ;
if ( V_14 != 0 )
return V_14 ;
V_14 = F_26 ( & V_276 -> V_62 , & V_275 -> V_62 ,
V_59 ) ;
if ( V_14 != 0 )
return V_14 ;
V_273 -> V_40 = V_276 ;
return 0 ;
}
static void F_121 ( struct V_39 * V_273 , const struct V_39 * V_274 )
{
struct V_20 * V_275 = V_274 -> V_40 ;
struct V_20 * V_276 = V_273 -> V_40 ;
V_276 -> V_22 = V_275 -> V_22 ;
V_276 -> V_60 = V_275 -> V_22 ;
F_20 ( & V_276 -> V_63 ) ;
F_22 ( & V_276 -> V_61 ) ;
}
static int F_122 ( struct V_39 * V_273 , T_4 V_236 )
{
struct V_20 * V_276 = V_273 -> V_40 ;
struct V_11 * V_47 = F_123 ( V_236 ) ;
if ( V_47 == NULL )
return - V_139 ;
V_276 -> V_22 = V_47 ;
return 0 ;
}
static int F_124 ( struct V_39 * V_273 ,
struct V_27 * V_27 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
struct V_20 * V_21 = V_273 -> V_40 ;
V_21 -> V_60 = V_29 -> V_37 ;
V_21 -> V_22 = V_21 -> V_60 ;
return 0 ;
}
static int F_125 ( struct V_25 * V_122 , int V_277 ,
const char * V_278 )
{
struct V_81 V_82 ;
struct V_11 * V_47 = F_7 ( V_122 ) ;
int V_14 ;
F_32 ( & V_82 , V_278 , V_86 ) ;
F_33 ( & V_82 , V_122 ) ;
V_14 = F_66 ( V_47 , V_277 , & V_82 ) ;
V_14 = F_6 ( V_122 , V_277 , V_14 ) ;
return V_14 ;
}
static int F_126 ( struct V_25 * V_122 , T_5 V_279 )
{
return F_125 ( V_122 , V_5 , V_93 ) ;
}
static int F_127 ( struct V_25 * V_122 )
{
return F_125 ( V_122 , V_4 , V_93 ) ;
}
static int F_128 ( struct V_25 * V_122 )
{
return F_125 ( V_122 , V_4 , V_93 ) ;
}
static void F_129 ( struct V_25 * V_122 , T_4 * V_236 )
{
struct V_11 * V_47 = F_7 ( V_122 ) ;
* V_236 = V_47 -> V_237 ;
}
static int F_130 ( struct V_25 * V_122 , int V_280 )
{
return F_125 ( V_122 , V_5 , V_93 ) ;
}
static int F_131 ( struct V_25 * V_122 , int V_281 )
{
return F_125 ( V_122 , V_5 , V_93 ) ;
}
static int F_132 ( struct V_25 * V_122 )
{
return F_125 ( V_122 , V_4 , V_93 ) ;
}
static int F_133 ( struct V_25 * V_122 )
{
return F_125 ( V_122 , V_5 , V_93 ) ;
}
static int F_134 ( struct V_25 * V_122 )
{
return F_125 ( V_122 , V_4 , V_93 ) ;
}
static int F_135 ( struct V_25 * V_122 )
{
return F_125 ( V_122 , V_5 , V_93 ) ;
}
static int F_136 ( struct V_25 * V_122 , struct V_282 * V_283 ,
int V_284 , T_4 V_236 )
{
struct V_81 V_82 ;
struct V_11 * V_47 ;
struct V_11 * V_264 = F_7 ( V_122 ) ;
int V_14 ;
if ( ! V_284 )
return 0 ;
F_32 ( & V_82 , V_93 , V_86 ) ;
F_33 ( & V_82 , V_122 ) ;
if ( V_236 == 0 ) {
V_14 = F_66 ( V_264 , V_5 , & V_82 ) ;
V_14 = F_6 ( V_122 , V_5 , V_14 ) ;
return V_14 ;
}
V_47 = F_123 ( V_236 ) ;
V_14 = V_259 ( V_47 , V_264 , V_5 , & V_82 ) ;
V_14 = F_2 ( L_12 , V_47 , V_264 , V_5 , V_14 ) ;
return V_14 ;
}
static int F_137 ( struct V_25 * V_122 )
{
return 0 ;
}
static void F_138 ( struct V_25 * V_122 , struct V_27 * V_27 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
struct V_11 * V_47 = F_7 ( V_122 ) ;
V_29 -> V_37 = V_47 ;
}
static int F_139 ( struct V_226 * V_229 , int V_285 , T_1 V_286 )
{
struct V_11 * V_47 = F_44 () ;
struct V_223 * V_224 ;
V_224 = F_15 ( sizeof( struct V_223 ) , V_286 ) ;
if ( V_224 == NULL )
return - V_53 ;
V_224 -> V_232 = V_47 ;
V_224 -> V_234 = V_47 ;
V_224 -> V_287 = NULL ;
V_229 -> V_230 = V_224 ;
return 0 ;
}
static void F_140 ( struct V_226 * V_229 )
{
F_17 ( V_229 -> V_230 ) ;
}
static struct V_11 * F_141 ( struct V_288 * V_289 )
{
struct V_290 * V_291 ;
struct V_292 * V_293 = & V_289 -> V_294 ;
if ( V_293 -> V_295 == 0 )
return NULL ;
F_24 (snp, &smk_net4addr_list, list)
if ( V_291 -> V_296 . V_295 ==
( V_293 -> V_295 & V_291 -> V_297 . V_295 ) )
return V_291 -> V_74 ;
return NULL ;
}
static bool F_142 ( struct V_298 * V_289 )
{
T_6 * V_299 = ( T_6 * ) & V_289 -> V_300 ;
T_7 * V_301 = ( T_7 * ) & V_289 -> V_300 ;
if ( V_301 [ 0 ] == 0 && V_301 [ 1 ] == 0 && V_301 [ 2 ] == 0 && V_299 [ 6 ] == 0 &&
F_143 ( V_299 [ 7 ] ) == 1 )
return true ;
return false ;
}
static struct V_11 * F_144 ( struct V_298 * V_289 )
{
struct V_302 * V_291 ;
struct V_303 * V_304 = & V_289 -> V_300 ;
int V_3 ;
int V_305 = 0 ;
if ( F_142 ( V_289 ) )
return NULL ;
F_24 (snp, &smk_net6addr_list, list) {
for ( V_305 = 1 , V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
if ( V_291 -> V_74 == NULL )
continue;
if ( ( V_304 -> V_306 [ V_3 ] & V_291 -> V_297 . V_306 [ V_3 ] ) !=
V_291 -> V_296 . V_306 [ V_3 ] ) {
V_305 = 0 ;
break;
}
}
if ( V_305 )
return V_291 -> V_74 ;
}
return NULL ;
}
static int F_145 ( struct V_226 * V_229 , int V_307 )
{
struct V_11 * V_47 ;
struct V_223 * V_224 = V_229 -> V_230 ;
int V_14 = 0 ;
F_146 () ;
F_147 ( V_229 ) ;
if ( V_224 -> V_234 == V_308 ||
V_307 == V_309 )
F_148 ( V_229 ) ;
else {
V_47 = V_224 -> V_234 ;
V_14 = F_149 ( V_229 , V_229 -> V_310 , & V_47 -> V_311 ) ;
}
F_150 ( V_229 ) ;
F_151 () ;
return V_14 ;
}
static int F_152 ( struct V_226 * V_229 , struct V_288 * V_304 )
{
struct V_11 * V_47 ;
int V_14 ;
int V_312 ;
struct V_11 * V_313 ;
struct V_223 * V_224 = V_229 -> V_230 ;
struct V_81 V_82 ;
F_34 () ;
V_313 = F_141 ( V_304 ) ;
if ( V_313 != NULL ) {
#ifdef F_153
struct V_314 V_315 ;
F_154 ( & V_82 , V_93 , V_316 , & V_315 ) ;
V_82 . V_317 . V_318 . V_315 -> V_285 = V_304 -> V_319 ;
V_82 . V_317 . V_318 . V_315 -> V_320 = V_304 -> V_321 ;
V_82 . V_317 . V_318 . V_315 -> V_322 . V_323 = V_304 -> V_294 . V_295 ;
#endif
V_312 = V_309 ;
V_47 = V_224 -> V_234 ;
V_14 = V_259 ( V_47 , V_313 , V_5 , & V_82 ) ;
V_14 = F_2 ( L_13 , V_47 , V_313 , V_5 , V_14 ) ;
} else {
V_312 = V_324 ;
V_14 = 0 ;
}
F_39 () ;
if ( V_14 != 0 )
return V_14 ;
return F_145 ( V_229 , V_312 ) ;
}
static int F_155 ( struct V_11 * V_325 ,
struct V_11 * V_326 ,
struct V_298 * V_327 , int V_328 )
{
#ifdef F_153
struct V_314 V_315 ;
#endif
struct V_81 V_82 ;
int V_14 ;
#ifdef F_153
F_154 ( & V_82 , V_93 , V_316 , & V_315 ) ;
V_82 . V_317 . V_318 . V_315 -> V_285 = V_329 ;
V_82 . V_317 . V_318 . V_315 -> V_320 = F_143 ( V_327 -> V_330 ) ;
if ( V_328 == V_331 )
V_82 . V_317 . V_318 . V_315 -> V_332 . V_333 = V_327 -> V_300 ;
else
V_82 . V_317 . V_318 . V_315 -> V_332 . V_323 = V_327 -> V_300 ;
#endif
V_14 = V_259 ( V_325 , V_326 , V_5 , & V_82 ) ;
V_14 = F_2 ( L_14 , V_325 , V_326 , V_5 , V_14 ) ;
return V_14 ;
}
static void F_156 ( struct V_225 * V_226 , struct V_334 * V_327 )
{
struct V_226 * V_229 = V_226 -> V_229 ;
struct V_298 * V_335 ;
struct V_223 * V_224 = V_226 -> V_229 -> V_230 ;
struct V_336 * V_337 ;
unsigned short V_338 = 0 ;
if ( V_327 == NULL ) {
F_27 (spp, &smk_ipv6_port_list, list) {
if ( V_229 != V_337 -> V_339 )
continue;
V_337 -> V_232 = V_224 -> V_232 ;
V_337 -> V_234 = V_224 -> V_234 ;
return;
}
return;
}
V_335 = (struct V_298 * ) V_327 ;
V_338 = F_143 ( V_335 -> V_330 ) ;
if ( V_338 == 0 )
return;
F_27 (spp, &smk_ipv6_port_list, list) {
if ( V_337 -> V_340 != V_338 )
continue;
V_337 -> V_340 = V_338 ;
V_337 -> V_339 = V_229 ;
V_337 -> V_232 = V_224 -> V_232 ;
V_337 -> V_234 = V_224 -> V_234 ;
return;
}
V_337 = F_15 ( sizeof( * V_337 ) , V_52 ) ;
if ( V_337 == NULL )
return;
V_337 -> V_340 = V_338 ;
V_337 -> V_339 = V_229 ;
V_337 -> V_232 = V_224 -> V_232 ;
V_337 -> V_234 = V_224 -> V_234 ;
F_29 ( & V_337 -> V_70 , & V_341 ) ;
return;
}
static int F_157 ( struct V_226 * V_229 , struct V_298 * V_327 ,
int V_328 )
{
struct V_336 * V_337 ;
struct V_223 * V_224 = V_229 -> V_230 ;
struct V_11 * V_47 = NULL ;
unsigned short V_338 ;
struct V_11 * V_326 ;
if ( V_328 == V_331 ) {
V_47 = F_144 ( V_327 ) ;
V_326 = V_224 -> V_232 ;
} else {
V_47 = V_224 -> V_234 ;
V_326 = F_144 ( V_327 ) ;
}
if ( V_47 != NULL && V_326 != NULL )
return F_155 ( V_47 , V_326 , V_327 , V_328 ) ;
if ( V_47 == NULL )
V_47 = V_308 ;
if ( V_326 == NULL )
V_326 = V_308 ;
if ( ! F_142 ( V_327 ) )
return F_155 ( V_47 , V_326 , V_327 , V_328 ) ;
if ( V_328 == V_331 )
return 0 ;
V_338 = F_143 ( V_327 -> V_330 ) ;
F_27 (spp, &smk_ipv6_port_list, list) {
if ( V_337 -> V_340 != V_338 )
continue;
V_326 = V_337 -> V_232 ;
if ( V_328 == V_342 )
V_224 -> V_287 = V_337 -> V_234 ;
break;
}
return F_155 ( V_47 , V_326 , V_327 , V_328 ) ;
}
static int F_158 ( struct V_27 * V_27 , const char * V_42 ,
const void * V_185 , T_3 V_206 , int V_167 )
{
struct V_11 * V_47 ;
struct V_28 * V_343 = V_27 -> V_30 ;
struct V_223 * V_224 ;
struct V_225 * V_226 ;
int V_14 = 0 ;
if ( V_185 == NULL || V_206 > V_51 || V_206 == 0 )
return - V_139 ;
V_47 = F_16 ( V_185 , V_206 ) ;
if ( F_59 ( V_47 ) )
return F_60 ( V_47 ) ;
if ( strcmp ( V_42 , V_190 ) == 0 ) {
V_343 -> V_37 = V_47 ;
V_343 -> V_31 |= V_344 ;
return 0 ;
}
if ( V_27 -> V_33 -> V_161 != V_228 )
return - V_50 ;
V_226 = F_96 ( V_27 ) ;
if ( V_226 == NULL || V_226 -> V_229 == NULL )
return - V_50 ;
V_224 = V_226 -> V_229 -> V_230 ;
if ( strcmp ( V_42 , V_231 ) == 0 )
V_224 -> V_232 = V_47 ;
else if ( strcmp ( V_42 , V_233 ) == 0 ) {
V_224 -> V_234 = V_47 ;
if ( V_226 -> V_229 -> V_310 == V_345 ) {
V_14 = F_145 ( V_226 -> V_229 , V_324 ) ;
if ( V_14 != 0 )
F_159 ( V_346
L_15 ,
V_93 , - V_14 ) ;
}
} else
return - V_50 ;
#ifdef F_160
if ( V_226 -> V_229 -> V_310 == V_329 )
F_156 ( V_226 , NULL ) ;
#endif
return 0 ;
}
static int F_161 ( struct V_225 * V_226 , int V_285 ,
int type , int V_347 , int V_348 )
{
struct V_223 * V_224 ;
if ( V_226 -> V_229 == NULL )
return 0 ;
if ( F_111 ( V_23 -> V_167 & V_349 ) ) {
V_224 = V_226 -> V_229 -> V_230 ;
V_224 -> V_232 = & V_219 ;
V_224 -> V_234 = & V_219 ;
}
if ( V_285 != V_345 )
return 0 ;
return F_145 ( V_226 -> V_229 , V_324 ) ;
}
static int F_162 ( struct V_225 * V_226 , struct V_334 * V_327 ,
int V_350 )
{
if ( V_226 -> V_229 != NULL && V_226 -> V_229 -> V_310 == V_329 )
F_156 ( V_226 , V_327 ) ;
return 0 ;
}
static int F_163 ( struct V_225 * V_226 , struct V_334 * V_304 ,
int V_350 )
{
int V_14 = 0 ;
#if F_164 ( V_351 )
struct V_298 * V_289 = (struct V_298 * ) V_304 ;
#endif
#ifdef F_165
struct V_11 * V_352 ;
struct V_223 * V_224 = V_226 -> V_229 -> V_230 ;
#endif
if ( V_226 -> V_229 == NULL )
return 0 ;
switch ( V_226 -> V_229 -> V_310 ) {
case V_345 :
if ( V_350 < sizeof( struct V_288 ) )
return - V_139 ;
V_14 = F_152 ( V_226 -> V_229 , (struct V_288 * ) V_304 ) ;
break;
case V_329 :
if ( V_350 < sizeof( struct V_298 ) )
return - V_139 ;
#ifdef F_165
V_352 = F_144 ( V_289 ) ;
if ( V_352 != NULL )
V_14 = F_155 ( V_224 -> V_234 , V_352 , V_289 ,
V_342 ) ;
#endif
#ifdef F_160
V_14 = F_157 ( V_226 -> V_229 , V_289 , V_342 ) ;
#endif
break;
}
return V_14 ;
}
static int F_166 ( int V_167 )
{
int V_189 = 0 ;
if ( V_167 & V_353 )
V_189 |= V_4 ;
if ( V_167 & V_354 )
V_189 |= V_5 ;
if ( V_167 & V_355 )
V_189 |= V_6 ;
return V_189 ;
}
static int F_167 ( struct V_356 * V_357 )
{
struct V_11 * V_47 = F_44 () ;
V_357 -> V_40 = V_47 ;
return 0 ;
}
static void F_168 ( struct V_356 * V_357 )
{
V_357 -> V_40 = NULL ;
}
static struct V_11 * F_169 ( struct V_358 * V_359 )
{
return (struct V_11 * ) V_359 -> V_360 . V_40 ;
}
static int F_170 ( struct V_358 * V_359 )
{
struct V_361 * V_29 = & V_359 -> V_360 ;
struct V_11 * V_47 = F_44 () ;
V_29 -> V_40 = V_47 ;
return 0 ;
}
static void F_171 ( struct V_358 * V_359 )
{
struct V_361 * V_29 = & V_359 -> V_360 ;
V_29 -> V_40 = NULL ;
}
static int F_172 ( struct V_358 * V_359 , int V_277 )
{
struct V_11 * V_224 = F_169 ( V_359 ) ;
struct V_81 V_82 ;
int V_14 ;
#ifdef F_153
F_32 ( & V_82 , V_93 , V_362 ) ;
V_82 . V_317 . V_318 . V_363 = V_359 -> V_360 . V_364 ;
#endif
V_14 = F_66 ( V_224 , V_277 , & V_82 ) ;
V_14 = F_4 ( L_16 , V_224 , V_277 , V_14 ) ;
return V_14 ;
}
static int F_173 ( struct V_358 * V_359 , int V_365 )
{
int V_189 ;
V_189 = F_166 ( V_365 ) ;
return F_172 ( V_359 , V_189 ) ;
}
static int F_174 ( struct V_358 * V_359 , int V_239 )
{
int V_189 ;
switch ( V_239 ) {
case V_366 :
case V_367 :
V_189 = V_4 ;
break;
case V_368 :
case V_369 :
case V_370 :
case V_371 :
V_189 = V_76 ;
break;
case V_372 :
case V_373 :
return 0 ;
default:
return - V_139 ;
}
return F_172 ( V_359 , V_189 ) ;
}
static int F_175 ( struct V_358 * V_359 , char T_8 * V_374 ,
int V_365 )
{
int V_189 ;
V_189 = F_166 ( V_365 ) ;
return F_172 ( V_359 , V_189 ) ;
}
static struct V_11 * F_176 ( struct V_375 * V_376 )
{
return (struct V_11 * ) V_376 -> V_377 . V_40 ;
}
static int F_177 ( struct V_375 * V_376 )
{
struct V_361 * V_29 = & V_376 -> V_377 ;
struct V_11 * V_47 = F_44 () ;
V_29 -> V_40 = V_47 ;
return 0 ;
}
static void F_178 ( struct V_375 * V_376 )
{
struct V_361 * V_29 = & V_376 -> V_377 ;
V_29 -> V_40 = NULL ;
}
static int F_179 ( struct V_375 * V_376 , int V_277 )
{
struct V_11 * V_224 = F_176 ( V_376 ) ;
struct V_81 V_82 ;
int V_14 ;
#ifdef F_153
F_32 ( & V_82 , V_93 , V_362 ) ;
V_82 . V_317 . V_318 . V_363 = V_376 -> V_377 . V_364 ;
#endif
V_14 = F_66 ( V_224 , V_277 , & V_82 ) ;
V_14 = F_4 ( L_17 , V_224 , V_277 , V_14 ) ;
return V_14 ;
}
static int F_180 ( struct V_375 * V_376 , int V_378 )
{
int V_189 ;
V_189 = F_166 ( V_378 ) ;
return F_179 ( V_376 , V_189 ) ;
}
static int F_181 ( struct V_375 * V_376 , int V_239 )
{
int V_189 ;
switch ( V_239 ) {
case V_379 :
case V_380 :
case V_381 :
case V_382 :
case V_383 :
case V_366 :
case V_384 :
V_189 = V_4 ;
break;
case V_385 :
case V_386 :
case V_371 :
case V_368 :
V_189 = V_76 ;
break;
case V_372 :
case V_387 :
return 0 ;
default:
return - V_139 ;
}
return F_179 ( V_376 , V_189 ) ;
}
static int F_182 ( struct V_375 * V_376 , struct V_388 * V_389 ,
unsigned V_390 , int V_391 )
{
return F_179 ( V_376 , V_76 ) ;
}
static int F_183 ( struct V_392 * V_393 )
{
struct V_361 * V_394 = & V_393 -> V_395 ;
struct V_11 * V_47 = F_44 () ;
V_394 -> V_40 = V_47 ;
return 0 ;
}
static void F_184 ( struct V_392 * V_393 )
{
struct V_361 * V_394 = & V_393 -> V_395 ;
V_394 -> V_40 = NULL ;
}
static struct V_11 * F_185 ( struct V_392 * V_393 )
{
return (struct V_11 * ) V_393 -> V_395 . V_40 ;
}
static int F_186 ( struct V_392 * V_393 , int V_277 )
{
struct V_11 * V_396 = F_185 ( V_393 ) ;
struct V_81 V_82 ;
int V_14 ;
#ifdef F_153
F_32 ( & V_82 , V_93 , V_362 ) ;
V_82 . V_317 . V_318 . V_363 = V_393 -> V_395 . V_364 ;
#endif
V_14 = F_66 ( V_396 , V_277 , & V_82 ) ;
V_14 = F_4 ( L_18 , V_396 , V_277 , V_14 ) ;
return V_14 ;
}
static int F_187 ( struct V_392 * V_393 , int V_397 )
{
int V_189 ;
V_189 = F_166 ( V_397 ) ;
return F_186 ( V_393 , V_189 ) ;
}
static int F_188 ( struct V_392 * V_393 , int V_239 )
{
int V_189 ;
switch ( V_239 ) {
case V_366 :
case V_398 :
V_189 = V_4 ;
break;
case V_368 :
case V_371 :
V_189 = V_76 ;
break;
case V_372 :
case V_399 :
return 0 ;
default:
return - V_139 ;
}
return F_186 ( V_393 , V_189 ) ;
}
static int F_189 ( struct V_392 * V_393 , struct V_356 * V_357 ,
int V_397 )
{
int V_189 ;
V_189 = F_166 ( V_397 ) ;
return F_186 ( V_393 , V_189 ) ;
}
static int F_190 ( struct V_392 * V_393 , struct V_356 * V_357 ,
struct V_25 * V_400 , long type , int V_1 )
{
return F_186 ( V_393 , V_76 ) ;
}
static int F_191 ( struct V_361 * V_401 , short V_402 )
{
struct V_11 * V_403 = V_401 -> V_40 ;
int V_189 = F_166 ( V_402 ) ;
struct V_81 V_82 ;
int V_14 ;
#ifdef F_153
F_32 ( & V_82 , V_93 , V_362 ) ;
V_82 . V_317 . V_318 . V_363 = V_401 -> V_364 ;
#endif
V_14 = F_66 ( V_403 , V_189 , & V_82 ) ;
V_14 = F_4 ( L_19 , V_403 , V_189 , V_14 ) ;
return V_14 ;
}
static void F_192 ( struct V_361 * V_401 , T_4 * V_236 )
{
struct V_11 * V_403 = V_401 -> V_40 ;
* V_236 = V_403 -> V_237 ;
}
static void F_193 ( struct V_44 * V_404 , struct V_27 * V_27 )
{
struct V_98 * V_170 ;
struct V_100 * V_101 ;
struct V_28 * V_29 ;
struct V_11 * V_47 ;
struct V_11 * V_405 = F_44 () ;
struct V_11 * V_406 ;
char V_407 [ V_216 ] ;
int V_408 = 0 ;
int V_14 ;
struct V_44 * V_45 ;
if ( V_27 == NULL )
return;
V_29 = V_27 -> V_30 ;
F_194 ( & V_29 -> V_56 ) ;
if ( V_29 -> V_31 & V_344 )
goto V_409;
V_170 = V_27 -> V_33 ;
V_101 = V_170 -> V_108 ;
V_406 = V_101 -> V_104 ;
if ( V_404 -> V_410 == V_404 ) {
switch ( V_170 -> V_161 ) {
case V_411 :
V_101 -> V_102 = & V_218 ;
V_101 -> V_104 = & V_218 ;
V_29 -> V_37 = V_101 -> V_102 ;
break;
case V_163 :
V_29 -> V_37 = F_44 () ;
break;
case V_412 :
V_29 -> V_37 = F_44 () ;
break;
default:
V_29 -> V_37 = V_101 -> V_102 ;
break;
}
V_29 -> V_31 |= V_344 ;
goto V_409;
}
switch ( V_170 -> V_161 ) {
case V_413 :
case V_412 :
case V_228 :
case V_411 :
V_406 = & V_218 ;
break;
case V_414 :
V_406 = V_405 ;
break;
case V_415 :
break;
case V_163 :
V_406 = & V_218 ;
default:
if ( F_113 ( V_27 -> V_266 ) ) {
V_406 = & V_218 ;
break;
}
if ( V_27 -> V_48 -> V_49 == NULL )
break;
V_45 = F_195 ( V_404 ) ;
V_47 = F_13 ( V_210 , V_27 , V_45 ) ;
if ( ! F_196 ( V_47 ) )
V_406 = V_47 ;
if ( F_197 ( V_27 -> V_266 ) ) {
if ( V_29 -> V_31 & V_191 ) {
V_29 -> V_31 &= ~ V_191 ;
V_14 = V_27 -> V_48 -> V_416 ( V_45 , V_27 ,
V_215 ,
V_217 , V_216 ,
0 ) ;
} else {
V_14 = V_27 -> V_48 -> V_49 ( V_45 , V_27 ,
V_215 , V_407 ,
V_216 ) ;
if ( V_14 >= 0 && strncmp ( V_407 , V_217 ,
V_216 ) != 0 )
V_14 = - V_139 ;
}
if ( V_14 >= 0 )
V_408 = V_166 ;
}
V_47 = F_13 ( V_213 , V_27 , V_45 ) ;
if ( F_59 ( V_47 ) || V_47 == & V_218 ||
V_47 == & V_219 )
V_47 = NULL ;
V_29 -> V_22 = V_47 ;
V_47 = F_13 ( V_214 , V_27 , V_45 ) ;
if ( F_59 ( V_47 ) || V_47 == & V_218 ||
V_47 == & V_219 )
V_47 = NULL ;
V_29 -> V_221 = V_47 ;
F_198 ( V_45 ) ;
break;
}
if ( V_406 == NULL )
V_29 -> V_37 = V_405 ;
else
V_29 -> V_37 = V_406 ;
V_29 -> V_31 |= ( V_344 | V_408 ) ;
V_409:
F_199 ( & V_29 -> V_56 ) ;
return;
}
static int F_200 ( struct V_25 * V_122 , char * V_42 , char * * V_185 )
{
struct V_11 * V_47 = F_7 ( V_122 ) ;
char * V_111 ;
int V_417 ;
if ( strcmp ( V_42 , L_20 ) != 0 )
return - V_139 ;
V_111 = F_78 ( V_47 -> V_19 , V_52 ) ;
if ( V_111 == NULL )
return - V_53 ;
V_417 = strlen ( V_111 ) ;
* V_185 = V_111 ;
return V_417 ;
}
static int F_201 ( struct V_25 * V_122 , char * V_42 ,
void * V_185 , T_3 V_206 )
{
struct V_20 * V_21 = F_5 () ;
struct V_39 * V_273 ;
struct V_11 * V_47 ;
struct V_71 * V_418 ;
int V_14 ;
if ( V_122 != V_23 )
return - V_158 ;
if ( ! F_45 ( V_157 ) && F_202 ( & V_21 -> V_62 ) )
return - V_158 ;
if ( V_185 == NULL || V_206 == 0 || V_206 >= V_51 )
return - V_139 ;
if ( strcmp ( V_42 , L_20 ) != 0 )
return - V_139 ;
V_47 = F_16 ( V_185 , V_206 ) ;
if ( F_59 ( V_47 ) )
return F_60 ( V_47 ) ;
if ( V_47 == & V_219 )
return - V_158 ;
if ( ! F_45 ( V_157 ) ) {
V_14 = - V_158 ;
F_27 (sklep, &tsp->smk_relabel, list)
if ( V_418 -> V_74 == V_47 ) {
V_14 = 0 ;
break;
}
if ( V_14 )
return V_14 ;
}
V_273 = F_203 () ;
if ( V_273 == NULL )
return - V_53 ;
V_21 = V_273 -> V_40 ;
V_21 -> V_22 = V_47 ;
F_28 ( & V_21 -> V_62 ) ;
F_204 ( V_273 ) ;
return V_206 ;
}
static int F_205 ( struct V_226 * V_226 ,
struct V_226 * V_419 , struct V_226 * V_420 )
{
struct V_11 * V_47 ;
struct V_11 * V_253 ;
struct V_223 * V_224 = V_226 -> V_230 ;
struct V_223 * V_421 = V_419 -> V_230 ;
struct V_223 * V_343 = V_420 -> V_230 ;
struct V_81 V_82 ;
int V_14 = 0 ;
#ifdef F_153
struct V_314 V_315 ;
#endif
if ( ! F_45 ( V_96 ) ) {
V_47 = V_224 -> V_234 ;
V_253 = V_421 -> V_232 ;
#ifdef F_153
F_154 ( & V_82 , V_93 , V_316 , & V_315 ) ;
F_206 ( & V_82 , V_419 ) ;
#endif
V_14 = V_259 ( V_47 , V_253 , V_5 , & V_82 ) ;
V_14 = F_2 ( L_21 , V_47 , V_253 , V_5 , V_14 ) ;
if ( V_14 == 0 ) {
V_253 = V_421 -> V_234 ;
V_47 = V_224 -> V_232 ;
V_14 = V_259 ( V_253 , V_47 , V_5 , & V_82 ) ;
V_14 = F_2 ( L_21 , V_253 , V_47 ,
V_5 , V_14 ) ;
}
}
if ( V_14 == 0 ) {
V_343 -> V_287 = V_224 -> V_234 ;
V_224 -> V_287 = V_421 -> V_234 ;
}
return V_14 ;
}
static int F_207 ( struct V_225 * V_226 , struct V_225 * V_419 )
{
struct V_223 * V_224 = V_226 -> V_229 -> V_230 ;
struct V_223 * V_421 = V_419 -> V_229 -> V_230 ;
struct V_81 V_82 ;
int V_14 ;
#ifdef F_153
struct V_314 V_315 ;
F_154 ( & V_82 , V_93 , V_316 , & V_315 ) ;
F_206 ( & V_82 , V_419 -> V_229 ) ;
#endif
if ( F_45 ( V_96 ) )
return 0 ;
V_14 = V_259 ( V_224 -> V_234 , V_421 -> V_232 , V_5 , & V_82 ) ;
V_14 = F_2 ( L_22 , V_224 -> V_234 , V_421 -> V_232 , V_5 , V_14 ) ;
return V_14 ;
}
static int F_208 ( struct V_225 * V_226 , struct V_422 * V_357 ,
int V_206 )
{
struct V_288 * V_289 = (struct V_288 * ) V_357 -> V_423 ;
#if F_164 ( V_351 )
struct V_298 * V_304 = (struct V_298 * ) V_357 -> V_423 ;
#endif
#ifdef F_165
struct V_223 * V_224 = V_226 -> V_229 -> V_230 ;
struct V_11 * V_352 ;
#endif
int V_14 = 0 ;
if ( V_289 == NULL )
return 0 ;
switch ( V_226 -> V_229 -> V_310 ) {
case V_424 :
V_14 = F_152 ( V_226 -> V_229 , V_289 ) ;
break;
case V_425 :
#ifdef F_165
V_352 = F_144 ( V_304 ) ;
if ( V_352 != NULL )
V_14 = F_155 ( V_224 -> V_234 , V_352 , V_304 ,
V_342 ) ;
#endif
#ifdef F_160
V_14 = F_157 ( V_226 -> V_229 , V_304 , V_426 ) ;
#endif
break;
}
return V_14 ;
}
static struct V_11 * F_209 ( struct V_427 * V_304 ,
struct V_223 * V_224 )
{
struct V_11 * V_47 ;
int V_305 = 0 ;
int V_428 ;
int V_429 ;
if ( ( V_304 -> V_167 & V_430 ) != 0 ) {
F_34 () ;
F_27 (skp, &smack_known_list, list) {
if ( V_304 -> V_431 . V_432 . V_433 != V_47 -> V_311 . V_431 . V_432 . V_433 )
continue;
if ( ( V_304 -> V_167 & V_434 ) == 0 ) {
if ( ( V_47 -> V_311 . V_167 &
V_434 ) == 0 )
V_305 = 1 ;
break;
}
for ( V_428 = - 1 , V_429 = - 1 ; V_428 == V_429 ; ) {
V_428 = F_210 ( V_304 -> V_431 . V_432 . V_435 ,
V_428 + 1 ) ;
V_429 = F_210 (
V_47 -> V_311 . V_431 . V_432 . V_435 ,
V_429 + 1 ) ;
if ( V_428 < 0 || V_429 < 0 )
break;
}
if ( V_428 == V_429 ) {
V_305 = 1 ;
break;
}
}
F_39 () ;
if ( V_305 )
return V_47 ;
if ( V_224 != NULL && V_224 -> V_232 == & V_218 )
return & V_219 ;
return & V_218 ;
}
if ( ( V_304 -> V_167 & V_436 ) != 0 ) {
V_47 = F_123 ( V_304 -> V_431 . V_236 ) ;
F_211 ( V_47 == NULL ) ;
return V_47 ;
}
return V_308 ;
}
static int F_212 ( struct V_437 * V_438 , struct V_298 * V_289 )
{
T_9 V_439 ;
int V_440 ;
int V_441 = - V_139 ;
struct V_442 V_443 ;
struct V_442 * V_444 ;
T_6 V_445 ;
struct V_446 V_447 , * V_448 ;
struct V_449 V_450 , * V_451 ;
struct V_452 V_453 , * V_454 ;
V_289 -> V_330 = 0 ;
V_440 = F_213 ( V_438 ) ;
V_444 = F_214 ( V_438 , V_440 , sizeof( V_443 ) , & V_443 ) ;
if ( V_444 == NULL )
return - V_139 ;
V_289 -> V_300 = V_444 -> V_333 ;
V_439 = V_444 -> V_439 ;
V_440 += sizeof( V_443 ) ;
V_440 = F_215 ( V_438 , V_440 , & V_439 , & V_445 ) ;
if ( V_440 < 0 )
return - V_139 ;
V_441 = V_439 ;
switch ( V_441 ) {
case V_455 :
V_448 = F_214 ( V_438 , V_440 , sizeof( V_447 ) , & V_447 ) ;
if ( V_448 != NULL )
V_289 -> V_330 = V_448 -> V_456 ;
break;
case V_457 :
V_451 = F_214 ( V_438 , V_440 , sizeof( V_450 ) , & V_450 ) ;
if ( V_451 != NULL )
V_289 -> V_330 = V_451 -> V_456 ;
break;
case V_458 :
V_454 = F_214 ( V_438 , V_440 , sizeof( V_453 ) , & V_453 ) ;
if ( V_454 != NULL )
V_289 -> V_330 = V_454 -> V_459 ;
break;
}
return V_441 ;
}
static int F_216 ( struct V_226 * V_229 , struct V_437 * V_438 )
{
struct V_427 V_460 ;
struct V_223 * V_224 = V_229 -> V_230 ;
struct V_11 * V_47 = NULL ;
int V_14 = 0 ;
struct V_81 V_82 ;
#ifdef F_153
struct V_314 V_315 ;
#endif
#if F_164 ( V_351 )
struct V_298 V_461 ;
int V_441 ;
#endif
switch ( V_229 -> V_310 ) {
case V_345 :
#ifdef F_217
if ( V_438 && V_438 -> V_462 != 0 ) {
V_47 = F_123 ( V_438 -> V_462 ) ;
goto V_463;
}
#endif
F_218 ( & V_460 ) ;
V_14 = F_219 ( V_438 , V_229 -> V_310 , & V_460 ) ;
if ( V_14 == 0 )
V_47 = F_209 ( & V_460 , V_224 ) ;
else
V_47 = V_308 ;
F_220 ( & V_460 ) ;
#ifdef F_217
V_463:
#endif
#ifdef F_153
F_154 ( & V_82 , V_93 , V_316 , & V_315 ) ;
V_82 . V_317 . V_318 . V_315 -> V_285 = V_229 -> V_310 ;
V_82 . V_317 . V_318 . V_315 -> V_464 = V_438 -> V_465 ;
F_221 ( V_438 , & V_82 . V_317 , NULL ) ;
#endif
V_14 = V_259 ( V_47 , V_224 -> V_232 , V_5 , & V_82 ) ;
V_14 = F_2 ( L_23 , V_47 , V_224 -> V_232 ,
V_5 , V_14 ) ;
if ( V_14 != 0 )
F_222 ( V_438 , V_229 -> V_310 , V_14 , 0 ) ;
break;
#if F_164 ( V_351 )
case V_329 :
V_441 = F_212 ( V_438 , & V_461 ) ;
if ( V_441 != V_457 && V_441 != V_455 )
break;
#ifdef F_165
if ( V_438 && V_438 -> V_462 != 0 )
V_47 = F_123 ( V_438 -> V_462 ) ;
else
V_47 = F_144 ( & V_461 ) ;
if ( V_47 == NULL )
V_47 = V_308 ;
#ifdef F_153
F_154 ( & V_82 , V_93 , V_316 , & V_315 ) ;
V_82 . V_317 . V_318 . V_315 -> V_285 = V_229 -> V_310 ;
V_82 . V_317 . V_318 . V_315 -> V_464 = V_438 -> V_465 ;
F_223 ( V_438 , & V_82 . V_317 , NULL ) ;
#endif
V_14 = V_259 ( V_47 , V_224 -> V_232 , V_5 , & V_82 ) ;
V_14 = F_2 ( L_24 , V_47 , V_224 -> V_232 ,
V_5 , V_14 ) ;
#endif
#ifdef F_160
V_14 = F_157 ( V_229 , & V_461 , V_331 ) ;
#endif
break;
#endif
}
return V_14 ;
}
static int F_224 ( struct V_225 * V_226 ,
char T_8 * V_466 ,
int T_8 * V_467 , unsigned V_186 )
{
struct V_223 * V_224 ;
char * V_468 = L_25 ;
int V_417 = 1 ;
int V_14 = 0 ;
V_224 = V_226 -> V_229 -> V_230 ;
if ( V_224 -> V_287 != NULL ) {
V_468 = V_224 -> V_287 -> V_19 ;
V_417 = strlen ( V_468 ) + 1 ;
}
if ( V_417 > V_186 )
V_14 = - V_469 ;
else if ( F_225 ( V_466 , V_468 , V_417 ) != 0 )
V_14 = - V_470 ;
if ( F_226 ( V_417 , V_467 ) != 0 )
V_14 = - V_470 ;
return V_14 ;
}
static int F_227 ( struct V_225 * V_226 ,
struct V_437 * V_438 , T_4 * V_236 )
{
struct V_427 V_460 ;
struct V_223 * V_224 = NULL ;
struct V_11 * V_47 ;
int V_285 = V_471 ;
T_4 V_2 = 0 ;
int V_14 ;
if ( V_438 != NULL ) {
if ( V_438 -> V_347 == F_228 ( V_472 ) )
V_285 = V_345 ;
#if F_164 ( V_351 )
else if ( V_438 -> V_347 == F_228 ( V_473 ) )
V_285 = V_329 ;
#endif
}
if ( V_285 == V_471 && V_226 != NULL )
V_285 = V_226 -> V_229 -> V_310 ;
switch ( V_285 ) {
case V_474 :
V_224 = V_226 -> V_229 -> V_230 ;
V_2 = V_224 -> V_234 -> V_237 ;
break;
case V_345 :
#ifdef F_217
V_2 = V_438 -> V_462 ;
if ( V_2 != 0 )
break;
#endif
if ( V_226 != NULL && V_226 -> V_229 != NULL )
V_224 = V_226 -> V_229 -> V_230 ;
F_218 ( & V_460 ) ;
V_14 = F_219 ( V_438 , V_285 , & V_460 ) ;
if ( V_14 == 0 ) {
V_47 = F_209 ( & V_460 , V_224 ) ;
V_2 = V_47 -> V_237 ;
}
F_220 ( & V_460 ) ;
break;
case V_329 :
#ifdef F_165
V_2 = V_438 -> V_462 ;
#endif
break;
}
* V_236 = V_2 ;
if ( V_2 == 0 )
return - V_139 ;
return 0 ;
}
static void F_229 ( struct V_226 * V_229 , struct V_225 * V_475 )
{
struct V_223 * V_224 ;
struct V_11 * V_47 = F_44 () ;
if ( V_229 == NULL ||
( V_229 -> V_310 != V_345 && V_229 -> V_310 != V_329 ) )
return;
V_224 = V_229 -> V_230 ;
V_224 -> V_232 = V_47 ;
V_224 -> V_234 = V_47 ;
}
static int F_230 ( struct V_226 * V_229 , struct V_437 * V_438 ,
struct V_476 * V_477 )
{
T_10 V_285 = V_229 -> V_310 ;
struct V_11 * V_47 ;
struct V_223 * V_224 = V_229 -> V_230 ;
struct V_427 V_460 ;
struct V_288 V_478 ;
struct V_479 * V_480 ;
struct V_11 * V_481 ;
int V_14 ;
struct V_81 V_82 ;
#ifdef F_153
struct V_314 V_315 ;
#endif
#if F_164 ( V_351 )
if ( V_285 == V_329 ) {
if ( V_438 -> V_347 == F_228 ( V_472 ) )
V_285 = V_345 ;
else
return 0 ;
}
#endif
#ifdef F_217
if ( V_438 && V_438 -> V_462 != 0 ) {
V_47 = F_123 ( V_438 -> V_462 ) ;
goto V_463;
}
#endif
F_218 ( & V_460 ) ;
V_14 = F_219 ( V_438 , V_285 , & V_460 ) ;
if ( V_14 == 0 )
V_47 = F_209 ( & V_460 , V_224 ) ;
else
V_47 = & V_482 ;
F_220 ( & V_460 ) ;
#ifdef F_217
V_463:
#endif
#ifdef F_153
F_154 ( & V_82 , V_93 , V_316 , & V_315 ) ;
V_82 . V_317 . V_318 . V_315 -> V_285 = V_285 ;
V_82 . V_317 . V_318 . V_315 -> V_464 = V_438 -> V_465 ;
F_221 ( V_438 , & V_82 . V_317 , NULL ) ;
#endif
V_14 = V_259 ( V_47 , V_224 -> V_232 , V_5 , & V_82 ) ;
V_14 = F_2 ( L_26 , V_47 , V_224 -> V_232 , V_5 , V_14 ) ;
if ( V_14 != 0 )
return V_14 ;
V_477 -> V_483 = V_47 -> V_237 ;
V_480 = F_231 ( V_438 ) ;
V_478 . V_294 . V_295 = V_480 -> V_333 ;
F_34 () ;
V_481 = F_141 ( & V_478 ) ;
F_39 () ;
if ( V_481 == NULL )
V_14 = F_232 ( V_477 , & V_47 -> V_311 ) ;
else
F_233 ( V_477 ) ;
return V_14 ;
}
static void F_234 ( struct V_226 * V_229 ,
const struct V_476 * V_477 )
{
struct V_223 * V_224 = V_229 -> V_230 ;
struct V_11 * V_47 ;
if ( V_477 -> V_483 != 0 ) {
V_47 = F_123 ( V_477 -> V_483 ) ;
V_224 -> V_287 = V_47 ;
} else
V_224 -> V_287 = NULL ;
}
static int F_235 ( struct V_484 * V_484 , const struct V_39 * V_39 ,
unsigned long V_167 )
{
struct V_11 * V_47 = F_36 ( V_39 -> V_40 ) ;
V_484 -> V_40 = V_47 ;
return 0 ;
}
static void F_236 ( struct V_484 * V_484 )
{
V_484 -> V_40 = NULL ;
}
static int F_237 ( T_11 V_485 ,
const struct V_39 * V_39 , unsigned V_486 )
{
struct V_484 * V_487 ;
struct V_81 V_82 ;
struct V_11 * V_264 = F_36 ( V_39 -> V_40 ) ;
int V_488 = 0 ;
int V_14 ;
V_487 = F_238 ( V_485 ) ;
if ( V_487 == NULL )
return - V_139 ;
if ( V_487 -> V_40 == NULL )
return 0 ;
if ( V_264 == NULL )
return - V_90 ;
#ifdef F_153
F_32 ( & V_82 , V_93 , V_489 ) ;
V_82 . V_317 . V_318 . V_490 . V_484 = V_487 -> V_491 ;
V_82 . V_317 . V_318 . V_490 . V_492 = V_487 -> V_493 ;
#endif
if ( V_486 & V_494 )
V_488 = V_4 ;
if ( V_486 & ( V_495 | V_496 | V_497 ) )
V_488 = V_5 ;
V_14 = V_259 ( V_264 , V_487 -> V_40 , V_488 , & V_82 ) ;
V_14 = F_2 ( L_27 , V_264 , V_487 -> V_40 , V_488 , V_14 ) ;
return V_14 ;
}
static int F_239 ( struct V_484 * V_484 , char * * V_498 )
{
struct V_11 * V_47 = V_484 -> V_40 ;
T_3 V_499 ;
char * V_500 ;
if ( V_484 -> V_40 == NULL ) {
* V_498 = NULL ;
return 0 ;
}
V_500 = F_78 ( V_47 -> V_19 , V_52 ) ;
if ( V_500 == NULL )
return - V_53 ;
V_499 = strlen ( V_500 ) + 1 ;
* V_498 = V_500 ;
return V_499 ;
}
static int F_240 ( T_4 V_501 , T_4 V_502 , char * V_503 , void * * V_504 )
{
struct V_11 * V_47 ;
char * * V_505 = ( char * * ) V_504 ;
* V_505 = NULL ;
if ( V_501 != V_506 && V_501 != V_507 )
return - V_139 ;
if ( V_502 != V_508 && V_502 != V_509 )
return - V_139 ;
V_47 = F_16 ( V_503 , 0 ) ;
if ( F_59 ( V_47 ) )
return F_60 ( V_47 ) ;
* V_505 = V_47 -> V_19 ;
return 0 ;
}
static int F_241 ( struct V_510 * V_511 )
{
struct V_512 * V_513 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_511 -> V_514 ; V_3 ++ ) {
V_513 = & V_511 -> V_515 [ V_3 ] ;
if ( V_513 -> type == V_506 || V_513 -> type == V_507 )
return 1 ;
}
return 0 ;
}
static int F_242 ( T_4 V_236 , T_4 V_501 , T_4 V_502 , void * V_504 ,
struct V_516 * V_517 )
{
struct V_11 * V_47 ;
char * V_505 = V_504 ;
if ( F_111 ( ! V_505 ) ) {
F_243 ( 1 , L_28 ) ;
return - V_258 ;
}
if ( V_501 != V_506 && V_501 != V_507 )
return 0 ;
V_47 = F_123 ( V_236 ) ;
if ( V_502 == V_508 )
return ( V_505 == V_47 -> V_19 ) ;
if ( V_502 == V_509 )
return ( V_505 != V_47 -> V_19 ) ;
return 0 ;
}
static int F_244 ( const char * V_42 )
{
return ( strcmp ( V_42 , V_190 ) == 0 ) ;
}
static int F_245 ( T_4 V_236 , char * * V_518 , T_4 * V_519 )
{
struct V_11 * V_47 = F_123 ( V_236 ) ;
if ( V_518 )
* V_518 = V_47 -> V_19 ;
* V_519 = strlen ( V_47 -> V_19 ) ;
return 0 ;
}
static int F_246 ( const char * V_518 , T_4 V_519 , T_4 * V_236 )
{
struct V_11 * V_47 = F_247 ( V_518 ) ;
if ( V_47 )
* V_236 = V_47 -> V_237 ;
else
* V_236 = 0 ;
return 0 ;
}
static int F_248 ( struct V_27 * V_27 , void * V_520 , T_4 V_521 )
{
return F_158 ( V_27 , V_190 , V_520 , V_521 , 0 ) ;
}
static int F_249 ( struct V_44 * V_44 , void * V_520 , T_4 V_521 )
{
return F_250 ( V_44 , V_210 , V_520 , V_521 , 0 ) ;
}
static int F_251 ( struct V_27 * V_27 , void * * V_520 , T_4 * V_521 )
{
int V_186 = 0 ;
V_186 = F_95 ( V_27 , V_190 , V_520 , true ) ;
if ( V_186 < 0 )
return V_186 ;
* V_521 = V_186 ;
return 0 ;
}
static T_12 void F_252 ( void )
{
F_20 ( & V_482 . V_63 ) ;
F_20 ( & V_107 . V_63 ) ;
F_20 ( & V_103 . V_63 ) ;
F_20 ( & V_218 . V_63 ) ;
F_20 ( & V_220 . V_63 ) ;
F_20 ( & V_219 . V_63 ) ;
F_22 ( & V_482 . V_61 ) ;
F_22 ( & V_107 . V_61 ) ;
F_22 ( & V_218 . V_61 ) ;
F_22 ( & V_103 . V_61 ) ;
F_22 ( & V_220 . V_61 ) ;
F_22 ( & V_219 . V_61 ) ;
F_253 ( & V_482 ) ;
F_253 ( & V_107 ) ;
F_253 ( & V_218 ) ;
F_253 ( & V_103 ) ;
F_253 ( & V_220 ) ;
F_253 ( & V_219 ) ;
}
static T_12 int F_254 ( void )
{
struct V_39 * V_39 ;
struct V_20 * V_21 ;
if ( ! F_255 ( L_29 ) )
return 0 ;
V_54 = F_256 ( V_28 , 0 ) ;
if ( ! V_54 )
return - V_53 ;
V_21 = F_21 ( & V_103 , & V_103 ,
V_52 ) ;
if ( V_21 == NULL ) {
F_257 ( V_54 ) ;
return - V_53 ;
}
V_522 = 1 ;
F_3 ( L_30 ) ;
#ifdef F_217
F_3 ( L_31 ) ;
#endif
#ifdef F_160
F_3 ( L_32 ) ;
#endif
#ifdef F_165
F_3 ( L_33 ) ;
#endif
V_39 = (struct V_39 * ) V_23 -> V_39 ;
V_39 -> V_40 = V_21 ;
F_252 () ;
F_258 ( V_523 , F_259 ( V_523 ) ) ;
return 0 ;
}

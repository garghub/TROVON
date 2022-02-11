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
if ( ! ( V_43 -> V_48 & V_49 ) )
return F_14 ( - V_50 ) ;
V_46 = F_15 ( V_51 , V_52 ) ;
if ( V_46 == NULL )
return F_14 ( - V_53 ) ;
V_14 = F_16 ( V_45 , V_43 , V_42 , V_46 , V_51 ) ;
if ( V_14 < 0 )
V_47 = F_14 ( V_14 ) ;
else if ( V_14 == 0 )
V_47 = NULL ;
else
V_47 = F_17 ( V_46 , V_14 ) ;
F_18 ( V_46 ) ;
return V_47 ;
}
static struct V_28 * F_19 ( struct V_11 * V_47 )
{
struct V_28 * V_29 ;
V_29 = F_20 ( V_54 , V_55 ) ;
if ( V_29 == NULL )
return NULL ;
V_29 -> V_37 = V_47 ;
V_29 -> V_31 = 0 ;
F_21 ( & V_29 -> V_56 ) ;
return V_29 ;
}
static struct V_20 * F_22 ( struct V_11 * V_57 ,
struct V_11 * V_58 , T_1 V_59 )
{
struct V_20 * V_21 ;
V_21 = F_15 ( sizeof( struct V_20 ) , V_59 ) ;
if ( V_21 == NULL )
return NULL ;
V_21 -> V_22 = V_57 ;
V_21 -> V_60 = V_58 ;
F_23 ( & V_21 -> V_61 ) ;
F_23 ( & V_21 -> V_62 ) ;
F_21 ( & V_21 -> V_63 ) ;
return V_21 ;
}
static int F_24 ( struct V_64 * V_65 , struct V_64 * V_66 ,
T_1 V_59 )
{
struct V_67 * V_68 ;
struct V_67 * V_69 ;
int V_14 = 0 ;
F_23 ( V_65 ) ;
F_25 (orp, ohead, list) {
V_68 = F_15 ( sizeof( struct V_67 ) , V_59 ) ;
if ( V_68 == NULL ) {
V_14 = - V_53 ;
break;
}
* V_68 = * V_69 ;
F_26 ( & V_68 -> V_70 , V_65 ) ;
}
return V_14 ;
}
static int F_27 ( struct V_64 * V_65 , struct V_64 * V_66 ,
T_1 V_59 )
{
struct V_71 * V_72 ;
struct V_71 * V_73 ;
F_23 ( V_65 ) ;
F_28 (oklep, ohead, list) {
V_72 = F_15 ( sizeof( struct V_71 ) , V_59 ) ;
if ( V_72 == NULL ) {
F_29 ( V_65 ) ;
return - V_53 ;
}
V_72 -> V_74 = V_73 -> V_74 ;
F_30 ( & V_72 -> V_70 , V_65 ) ;
}
return 0 ;
}
static inline unsigned int F_31 ( unsigned int V_1 )
{
if ( V_1 & V_75 )
return V_76 ;
if ( V_1 & V_77 )
return V_4 ;
return 0 ;
}
static int F_32 ( struct V_25 * V_78 ,
struct V_11 * V_79 ,
unsigned int V_1 , const char * V_80 )
{
int V_14 ;
struct V_81 V_82 , * V_83 = NULL ;
struct V_20 * V_21 ;
struct V_11 * V_84 ;
if ( ( V_1 & V_85 ) == 0 ) {
F_33 ( & V_82 , V_80 , V_86 ) ;
F_34 ( & V_82 , V_78 ) ;
V_83 = & V_82 ;
}
F_35 () ;
V_21 = F_36 ( V_78 ) -> V_40 ;
V_84 = F_37 ( V_21 ) ;
if ( ( V_1 & V_75 ) &&
( V_87 == V_88 ||
V_87 == V_89 ) ) {
if ( V_84 -> V_19 == V_79 -> V_19 )
V_14 = 0 ;
else if ( V_87 == V_89 )
V_14 = - V_90 ;
else if ( F_38 ( V_91 ) )
V_14 = 0 ;
else
V_14 = - V_90 ;
if ( V_83 )
F_39 ( V_84 -> V_19 ,
V_79 -> V_19 ,
0 , V_14 , V_83 ) ;
F_40 () ;
return V_14 ;
}
V_14 = F_41 ( V_21 , V_79 , F_31 ( V_1 ) , V_83 ) ;
F_40 () ;
return V_14 ;
}
static int F_42 ( struct V_25 * V_92 , unsigned int V_1 )
{
struct V_11 * V_47 ;
V_47 = F_7 ( V_92 ) ;
return F_32 ( V_23 , V_47 , V_1 , V_93 ) ;
}
static int F_43 ( struct V_25 * V_94 )
{
int V_14 ;
struct V_11 * V_47 ;
V_47 = F_37 ( F_5 () ) ;
V_14 = F_32 ( V_94 , V_47 , V_75 , V_93 ) ;
return V_14 ;
}
static int F_44 ( int V_95 )
{
int V_14 = 0 ;
struct V_11 * V_47 = F_45 () ;
if ( F_46 ( V_96 ) )
return 0 ;
if ( V_97 != NULL && V_97 != V_47 )
V_14 = - V_90 ;
return V_14 ;
}
static int F_47 ( struct V_98 * V_99 )
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
static void F_48 ( struct V_98 * V_99 )
{
F_18 ( V_99 -> V_108 ) ;
V_99 -> V_108 = NULL ;
}
static int F_49 ( char * V_109 , char * V_110 )
{
char * V_111 , * V_112 , * V_113 , * V_45 ;
V_113 = ( char * ) F_50 ( V_52 ) ;
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
F_51 ( ( unsigned long ) V_113 ) ;
return 0 ;
}
static int F_52 ( char * V_119 ,
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
while ( ( V_122 = F_53 ( & V_119 , L_7 ) ) != NULL ) {
T_2 args [ V_130 ] ;
if ( ! * V_122 )
continue;
V_129 = F_54 ( V_122 , V_131 , args ) ;
switch ( V_129 ) {
case V_132 :
if ( V_123 )
goto V_133;
V_123 = F_55 ( & args [ 0 ] ) ;
if ( ! V_123 )
goto V_134;
break;
case V_135 :
if ( V_124 )
goto V_133;
V_124 = F_55 ( & args [ 0 ] ) ;
if ( ! V_124 )
goto V_134;
break;
case V_136 :
if ( V_125 )
goto V_133;
V_125 = F_55 ( & args [ 0 ] ) ;
if ( ! V_125 )
goto V_134;
break;
case V_137 :
if ( V_126 )
goto V_133;
V_126 = F_55 ( & args [ 0 ] ) ;
if ( ! V_126 )
goto V_134;
break;
case V_138 :
if ( V_127 )
goto V_133;
V_127 = F_55 ( & args [ 0 ] ) ;
if ( ! V_127 )
goto V_134;
break;
default:
V_14 = - V_139 ;
F_56 ( L_8 ) ;
goto V_134;
}
}
V_121 -> V_140 = F_57 ( V_141 , sizeof( char * ) , V_142 ) ;
if ( ! V_121 -> V_140 )
goto V_134;
V_121 -> V_143 = F_57 ( V_141 , sizeof( int ) ,
V_142 ) ;
if ( ! V_121 -> V_143 ) {
F_18 ( V_121 -> V_140 ) ;
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
F_56 ( L_9 ) ;
V_134:
F_18 ( V_123 ) ;
F_18 ( V_124 ) ;
F_18 ( V_125 ) ;
F_18 ( V_126 ) ;
F_18 ( V_127 ) ;
return V_14 ;
}
static int F_58 ( struct V_98 * V_99 ,
struct V_120 * V_121 ,
unsigned long V_149 ,
unsigned long * V_150 )
{
struct V_44 * V_151 = V_99 -> V_152 ;
struct V_27 * V_27 = F_59 ( V_151 ) ;
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
V_47 = F_17 ( V_121 -> V_140 [ V_3 ] , 0 ) ;
if ( F_60 ( V_47 ) )
return F_61 ( V_47 ) ;
V_153 -> V_104 = V_47 ;
break;
case V_145 :
V_47 = F_17 ( V_121 -> V_140 [ V_3 ] , 0 ) ;
if ( F_60 ( V_47 ) )
return F_61 ( V_47 ) ;
V_153 -> V_105 = V_47 ;
break;
case V_146 :
V_47 = F_17 ( V_121 -> V_140 [ V_3 ] , 0 ) ;
if ( F_60 ( V_47 ) )
return F_61 ( V_47 ) ;
V_153 -> V_106 = V_47 ;
break;
case V_147 :
V_47 = F_17 ( V_121 -> V_140 [ V_3 ] , 0 ) ;
if ( F_60 ( V_47 ) )
return F_61 ( V_47 ) ;
V_153 -> V_102 = V_47 ;
break;
case V_148 :
V_47 = F_17 ( V_121 -> V_140 [ V_3 ] , 0 ) ;
if ( F_60 ( V_47 ) )
return F_61 ( V_47 ) ;
V_153 -> V_102 = V_47 ;
V_155 = 1 ;
break;
default:
break;
}
}
if ( ! F_46 ( V_157 ) ) {
if ( V_154 )
return - V_158 ;
V_47 = F_45 () ;
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
V_29 = F_19 ( V_153 -> V_102 ) ;
if ( V_29 == NULL )
return - V_53 ;
V_27 -> V_30 = V_29 ;
} else
V_29 -> V_37 = V_153 -> V_102 ;
if ( V_155 )
V_29 -> V_31 |= V_166 ;
return 0 ;
}
static int F_62 ( struct V_98 * V_99 , int V_167 , void * V_168 )
{
int V_14 = 0 ;
char * V_119 = V_168 ;
struct V_120 V_121 ;
F_63 ( & V_121 ) ;
if ( ! V_119 )
goto V_169;
V_14 = F_52 ( V_119 , & V_121 ) ;
if ( V_14 )
goto V_134;
V_169:
V_14 = F_58 ( V_99 , & V_121 , 0 , NULL ) ;
V_134:
F_64 ( & V_121 ) ;
return V_14 ;
}
static int F_65 ( struct V_44 * V_44 )
{
struct V_100 * V_170 = V_44 -> V_171 -> V_108 ;
int V_14 ;
struct V_81 V_82 ;
F_33 ( & V_82 , V_93 , V_172 ) ;
F_66 ( & V_82 , V_44 ) ;
V_14 = F_67 ( V_170 -> V_105 , V_4 , & V_82 ) ;
V_14 = F_4 ( L_10 , V_170 -> V_105 , V_4 , V_14 ) ;
return V_14 ;
}
static int F_68 ( struct V_173 * V_174 )
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
F_35 () ;
V_78 = F_69 ( V_23 ) ;
if ( F_70 ( V_78 != NULL ) )
V_14 = F_32 ( V_78 ,
V_29 -> V_22 ,
V_75 ,
V_93 ) ;
F_40 () ;
if ( V_14 != 0 )
return V_14 ;
} else if ( V_174 -> V_177 )
return - V_158 ;
V_175 -> V_22 = V_29 -> V_22 ;
V_174 -> V_180 |= V_181 ;
return 0 ;
}
static void F_71 ( struct V_173 * V_174 )
{
struct V_20 * V_175 = V_174 -> V_39 -> V_40 ;
if ( V_175 -> V_22 != V_175 -> V_60 )
V_23 -> V_182 = 0 ;
}
static int F_72 ( struct V_173 * V_174 )
{
struct V_20 * V_21 = F_5 () ;
if ( V_21 -> V_22 != V_21 -> V_60 )
return 1 ;
return 0 ;
}
static int F_73 ( struct V_27 * V_27 )
{
struct V_11 * V_47 = F_45 () ;
V_27 -> V_30 = F_19 ( V_47 ) ;
if ( V_27 -> V_30 == NULL )
return - V_53 ;
return 0 ;
}
static void F_74 ( struct V_27 * V_27 )
{
F_75 ( V_54 , V_27 -> V_30 ) ;
V_27 -> V_30 = NULL ;
}
static int F_76 ( struct V_27 * V_27 , struct V_27 * V_183 ,
const struct V_184 * V_184 , const char * * V_42 ,
void * * V_185 , T_3 * V_186 )
{
struct V_28 * V_187 = V_27 -> V_30 ;
struct V_11 * V_47 = F_45 () ;
struct V_11 * V_29 = F_11 ( V_27 ) ;
struct V_11 * V_188 = F_11 ( V_183 ) ;
int V_189 ;
if ( V_42 )
* V_42 = V_190 ;
if ( V_185 && V_186 ) {
F_35 () ;
V_189 = F_77 ( V_47 -> V_19 , V_188 -> V_19 ,
& V_47 -> V_61 ) ;
F_40 () ;
if ( V_189 > 0 && ( ( V_189 & V_8 ) != 0 ) &&
F_78 ( V_183 ) ) {
V_29 = V_188 ;
V_187 -> V_31 |= V_191 ;
}
* V_185 = F_79 ( V_29 -> V_19 , V_55 ) ;
if ( * V_185 == NULL )
return - V_53 ;
* V_186 = strlen ( V_29 -> V_19 ) ;
}
return 0 ;
}
static int F_80 ( struct V_44 * V_192 , struct V_27 * V_183 ,
struct V_44 * V_193 )
{
struct V_11 * V_29 ;
struct V_81 V_82 ;
int V_14 ;
F_33 ( & V_82 , V_93 , V_172 ) ;
F_66 ( & V_82 , V_192 ) ;
V_29 = F_11 ( F_59 ( V_192 ) ) ;
V_14 = F_67 ( V_29 , V_5 , & V_82 ) ;
V_14 = F_8 ( F_59 ( V_192 ) , V_5 , V_14 ) ;
if ( V_14 == 0 && F_81 ( V_193 ) ) {
V_29 = F_11 ( F_59 ( V_193 ) ) ;
F_66 ( & V_82 , V_193 ) ;
V_14 = F_67 ( V_29 , V_5 , & V_82 ) ;
V_14 = F_8 ( F_59 ( V_193 ) , V_5 , V_14 ) ;
}
return V_14 ;
}
static int F_82 ( struct V_27 * V_183 , struct V_44 * V_44 )
{
struct V_27 * V_43 = F_59 ( V_44 ) ;
struct V_81 V_82 ;
int V_14 ;
F_33 ( & V_82 , V_93 , V_172 ) ;
F_66 ( & V_82 , V_44 ) ;
V_14 = F_67 ( F_11 ( V_43 ) , V_5 , & V_82 ) ;
V_14 = F_8 ( V_43 , V_5 , V_14 ) ;
if ( V_14 == 0 ) {
F_33 ( & V_82 , V_93 , V_194 ) ;
F_83 ( & V_82 , V_183 ) ;
V_14 = F_67 ( F_11 ( V_183 ) , V_5 , & V_82 ) ;
V_14 = F_8 ( V_183 , V_5 , V_14 ) ;
}
return V_14 ;
}
static int F_84 ( struct V_27 * V_183 , struct V_44 * V_44 )
{
struct V_81 V_82 ;
int V_14 ;
F_33 ( & V_82 , V_93 , V_172 ) ;
F_66 ( & V_82 , V_44 ) ;
V_14 = F_67 ( F_11 ( F_59 ( V_44 ) ) , V_5 , & V_82 ) ;
V_14 = F_8 ( F_59 ( V_44 ) , V_5 , V_14 ) ;
if ( V_14 == 0 ) {
F_33 ( & V_82 , V_93 , V_194 ) ;
F_83 ( & V_82 , V_183 ) ;
V_14 = F_67 ( F_11 ( V_183 ) , V_5 , & V_82 ) ;
V_14 = F_8 ( V_183 , V_5 , V_14 ) ;
}
return V_14 ;
}
static int F_85 ( struct V_27 * V_195 ,
struct V_44 * V_192 ,
struct V_27 * V_196 ,
struct V_44 * V_193 )
{
int V_14 ;
struct V_11 * V_29 ;
struct V_81 V_82 ;
F_33 ( & V_82 , V_93 , V_172 ) ;
F_66 ( & V_82 , V_192 ) ;
V_29 = F_11 ( F_59 ( V_192 ) ) ;
V_14 = F_67 ( V_29 , V_76 , & V_82 ) ;
V_14 = F_8 ( F_59 ( V_192 ) , V_76 , V_14 ) ;
if ( V_14 == 0 && F_81 ( V_193 ) ) {
V_29 = F_11 ( F_59 ( V_193 ) ) ;
F_66 ( & V_82 , V_193 ) ;
V_14 = F_67 ( V_29 , V_76 , & V_82 ) ;
V_14 = F_8 ( F_59 ( V_193 ) , V_76 , V_14 ) ;
}
return V_14 ;
}
static int F_86 ( struct V_27 * V_27 , int V_197 )
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
F_33 ( & V_82 , V_93 , V_194 ) ;
F_83 ( & V_82 , V_27 ) ;
V_14 = F_67 ( F_11 ( V_27 ) , V_197 , & V_82 ) ;
V_14 = F_8 ( V_27 , V_197 , V_14 ) ;
return V_14 ;
}
static int F_87 ( struct V_44 * V_44 , struct V_201 * V_201 )
{
struct V_81 V_82 ;
int V_14 ;
if ( V_201 -> V_202 & V_203 )
return 0 ;
F_33 ( & V_82 , V_93 , V_172 ) ;
F_66 ( & V_82 , V_44 ) ;
V_14 = F_67 ( F_11 ( F_59 ( V_44 ) ) , V_5 , & V_82 ) ;
V_14 = F_8 ( F_59 ( V_44 ) , V_5 , V_14 ) ;
return V_14 ;
}
static int F_88 ( const struct V_204 * V_204 )
{
struct V_81 V_82 ;
struct V_27 * V_27 = F_59 ( V_204 -> V_44 ) ;
int V_14 ;
F_33 ( & V_82 , V_93 , V_205 ) ;
F_89 ( & V_82 , * V_204 ) ;
V_14 = F_67 ( F_11 ( V_27 ) , V_4 , & V_82 ) ;
V_14 = F_8 ( V_27 , V_4 , V_14 ) ;
return V_14 ;
}
static int F_90 ( struct V_44 * V_44 , const char * V_42 ,
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
V_14 = F_91 ( V_44 , V_42 , V_185 , V_206 , V_167 ) ;
if ( V_207 && ! F_46 ( V_157 ) )
V_14 = - V_158 ;
if ( V_14 == 0 && V_208 ) {
V_47 = V_206 ? F_17 ( V_185 , V_206 ) : NULL ;
if ( F_60 ( V_47 ) )
V_14 = F_61 ( V_47 ) ;
else if ( V_47 == NULL || ( V_209 &&
( V_47 == & V_218 || V_47 == & V_219 ) ) )
V_14 = - V_139 ;
}
F_33 ( & V_82 , V_93 , V_172 ) ;
F_66 ( & V_82 , V_44 ) ;
if ( V_14 == 0 ) {
V_14 = F_67 ( F_11 ( F_59 ( V_44 ) ) , V_5 , & V_82 ) ;
V_14 = F_8 ( F_59 ( V_44 ) , V_5 , V_14 ) ;
}
return V_14 ;
}
static void F_92 ( struct V_44 * V_44 , const char * V_42 ,
const void * V_185 , T_3 V_206 , int V_167 )
{
struct V_11 * V_47 ;
struct V_28 * V_29 = F_59 ( V_44 ) -> V_30 ;
if ( strcmp ( V_42 , V_215 ) == 0 ) {
V_29 -> V_31 |= V_166 ;
return;
}
if ( strcmp ( V_42 , V_210 ) == 0 ) {
V_47 = F_17 ( V_185 , V_206 ) ;
if ( ! F_60 ( V_47 ) )
V_29 -> V_37 = V_47 ;
else
V_29 -> V_37 = & V_220 ;
} else if ( strcmp ( V_42 , V_213 ) == 0 ) {
V_47 = F_17 ( V_185 , V_206 ) ;
if ( ! F_60 ( V_47 ) )
V_29 -> V_22 = V_47 ;
else
V_29 -> V_22 = & V_220 ;
} else if ( strcmp ( V_42 , V_214 ) == 0 ) {
V_47 = F_17 ( V_185 , V_206 ) ;
if ( ! F_60 ( V_47 ) )
V_29 -> V_221 = V_47 ;
else
V_29 -> V_221 = & V_220 ;
}
return;
}
static int F_93 ( struct V_44 * V_44 , const char * V_42 )
{
struct V_81 V_82 ;
int V_14 ;
F_33 ( & V_82 , V_93 , V_172 ) ;
F_66 ( & V_82 , V_44 ) ;
V_14 = F_67 ( F_11 ( F_59 ( V_44 ) ) , V_4 , & V_82 ) ;
V_14 = F_8 ( F_59 ( V_44 ) , V_4 , V_14 ) ;
return V_14 ;
}
static int F_94 ( struct V_44 * V_44 , const char * V_42 )
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
if ( ! F_46 ( V_157 ) )
V_14 = - V_158 ;
} else
V_14 = F_95 ( V_44 , V_42 ) ;
if ( V_14 != 0 )
return V_14 ;
F_33 ( & V_82 , V_93 , V_172 ) ;
F_66 ( & V_82 , V_44 ) ;
V_14 = F_67 ( F_11 ( F_59 ( V_44 ) ) , V_5 , & V_82 ) ;
V_14 = F_8 ( F_59 ( V_44 ) , V_5 , V_14 ) ;
if ( V_14 != 0 )
return V_14 ;
V_29 = F_59 ( V_44 ) -> V_30 ;
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
static int F_96 ( struct V_27 * V_27 ,
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
V_226 = F_97 ( V_43 ) ;
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
static int F_98 ( struct V_27 * V_27 , char * V_46 ,
T_3 V_235 )
{
int V_186 = sizeof( V_210 ) ;
if ( V_46 != NULL && V_186 <= V_235 )
memcpy ( V_46 , V_210 , V_186 ) ;
return V_186 ;
}
static void F_99 ( struct V_27 * V_27 , T_4 * V_236 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
* V_236 = V_29 -> V_37 -> V_237 ;
}
static int F_100 ( struct V_38 * V_38 )
{
struct V_11 * V_47 = F_45 () ;
V_38 -> V_238 = V_47 ;
return 0 ;
}
static void F_101 ( struct V_38 * V_38 )
{
V_38 -> V_238 = NULL ;
}
static int F_102 ( struct V_38 * V_38 , unsigned int V_239 ,
unsigned long V_240 )
{
int V_14 = 0 ;
struct V_81 V_82 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
F_33 ( & V_82 , V_93 , V_205 ) ;
F_89 ( & V_82 , V_38 -> V_241 ) ;
if ( F_103 ( V_239 ) & V_242 ) {
V_14 = F_67 ( F_11 ( V_27 ) , V_5 , & V_82 ) ;
V_14 = F_9 ( V_38 , V_5 , V_14 ) ;
}
if ( V_14 == 0 && ( F_103 ( V_239 ) & V_243 ) ) {
V_14 = F_67 ( F_11 ( V_27 ) , V_4 , & V_82 ) ;
V_14 = F_9 ( V_38 , V_4 , V_14 ) ;
}
return V_14 ;
}
static int F_104 ( struct V_38 * V_38 , unsigned int V_239 )
{
struct V_81 V_82 ;
int V_14 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
F_33 ( & V_82 , V_93 , V_205 ) ;
F_89 ( & V_82 , V_38 -> V_241 ) ;
V_14 = F_67 ( F_11 ( V_27 ) , V_9 , & V_82 ) ;
V_14 = F_9 ( V_38 , V_9 , V_14 ) ;
return V_14 ;
}
static int F_105 ( struct V_38 * V_38 , unsigned int V_239 ,
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
F_33 ( & V_82 , V_93 , V_205 ) ;
F_89 ( & V_82 , V_38 -> V_241 ) ;
V_14 = F_67 ( F_11 ( V_27 ) , V_9 , & V_82 ) ;
V_14 = F_9 ( V_38 , V_9 , V_14 ) ;
break;
case V_247 :
case V_248 :
F_33 ( & V_82 , V_93 , V_205 ) ;
F_89 ( & V_82 , V_38 -> V_241 ) ;
V_14 = F_67 ( F_11 ( V_27 ) , V_5 , & V_82 ) ;
V_14 = F_9 ( V_38 , V_5 , V_14 ) ;
break;
default:
break;
}
return V_14 ;
}
static int F_106 ( struct V_38 * V_38 ,
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
V_47 = F_45 () ;
V_14 = 0 ;
F_35 () ;
F_25 (srp, &skp->smk_rules, list) {
V_253 = V_252 -> V_256 ;
if ( V_251 -> V_19 == V_253 -> V_19 )
continue;
V_189 = F_77 ( V_252 -> V_257 -> V_19 ,
V_253 -> V_19 ,
& V_21 -> V_61 ) ;
if ( V_189 == - V_258 )
V_189 = V_252 -> V_259 ;
else
V_189 &= V_252 -> V_259 ;
if ( V_189 == 0 )
continue;
V_254 = F_77 ( V_251 -> V_19 , V_253 -> V_19 ,
& V_251 -> V_61 ) ;
if ( V_254 == - V_258 ) {
V_14 = - V_90 ;
break;
}
V_255 = F_77 ( V_251 -> V_19 , V_253 -> V_19 ,
& V_21 -> V_61 ) ;
if ( V_255 != - V_258 )
V_254 &= V_255 ;
if ( ( V_189 | V_254 ) != V_254 ) {
V_14 = - V_90 ;
break;
}
}
F_40 () ;
return V_14 ;
}
static void F_107 ( struct V_38 * V_38 )
{
V_38 -> V_238 = F_45 () ;
}
static int F_108 ( struct V_25 * V_260 ,
struct V_261 * V_262 , int V_263 )
{
struct V_11 * V_47 ;
struct V_11 * V_264 = F_37 ( V_260 -> V_39 -> V_40 ) ;
struct V_38 * V_38 ;
int V_14 ;
struct V_81 V_82 ;
V_38 = F_109 ( V_262 , struct V_38 , V_265 ) ;
V_47 = V_38 -> V_238 ;
V_14 = V_259 ( V_47 , V_264 , V_266 , NULL ) ;
V_14 = F_2 ( L_11 , V_47 , V_264 , V_266 , V_14 ) ;
if ( V_14 != 0 && F_110 ( V_260 , V_96 ) )
V_14 = 0 ;
F_33 ( & V_82 , V_93 , V_86 ) ;
F_34 ( & V_82 , V_260 ) ;
F_39 ( V_47 -> V_19 , V_264 -> V_19 , V_266 , V_14 , & V_82 ) ;
return V_14 ;
}
static int F_111 ( struct V_38 * V_38 )
{
int V_14 ;
int V_189 = 0 ;
struct V_81 V_82 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
struct V_225 * V_226 ;
struct V_20 * V_21 ;
struct V_223 * V_224 ;
if ( F_112 ( F_113 ( V_27 ) ) )
return 0 ;
F_33 ( & V_82 , V_93 , V_205 ) ;
F_89 ( & V_82 , V_38 -> V_241 ) ;
if ( F_114 ( V_27 -> V_267 ) ) {
V_226 = F_97 ( V_27 ) ;
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
if ( V_38 -> V_268 & V_269 )
V_189 = V_4 ;
if ( V_38 -> V_268 & V_270 )
V_189 |= V_5 ;
V_14 = F_67 ( F_11 ( V_27 ) , V_189 , & V_82 ) ;
V_14 = F_9 ( V_38 , V_189 , V_14 ) ;
return V_14 ;
}
static int F_115 ( struct V_38 * V_38 , const struct V_39 * V_39 )
{
struct V_20 * V_21 = V_39 -> V_40 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
struct V_81 V_82 ;
int V_14 ;
if ( F_46 ( V_96 ) )
return 0 ;
F_33 ( & V_82 , V_93 , V_205 ) ;
F_89 ( & V_82 , V_38 -> V_241 ) ;
V_14 = V_259 ( V_21 -> V_22 , F_11 ( V_27 ) , V_4 , & V_82 ) ;
V_14 = F_12 ( V_39 , V_38 , V_4 , V_14 ) ;
return V_14 ;
}
static int F_116 ( struct V_39 * V_39 , T_1 V_59 )
{
struct V_20 * V_21 ;
V_21 = F_22 ( NULL , NULL , V_59 ) ;
if ( V_21 == NULL )
return - V_53 ;
V_39 -> V_40 = V_21 ;
return 0 ;
}
static void F_117 ( struct V_39 * V_39 )
{
struct V_20 * V_21 = V_39 -> V_40 ;
struct V_67 * V_271 ;
struct V_64 * V_272 ;
struct V_64 * V_273 ;
if ( V_21 == NULL )
return;
V_39 -> V_40 = NULL ;
F_29 ( & V_21 -> V_62 ) ;
F_118 (l, n, &tsp->smk_rules) {
V_271 = F_119 ( V_272 , struct V_67 , V_70 ) ;
F_120 ( & V_271 -> V_70 ) ;
F_18 ( V_271 ) ;
}
F_18 ( V_21 ) ;
}
static int F_121 ( struct V_39 * V_274 , const struct V_39 * V_275 ,
T_1 V_59 )
{
struct V_20 * V_276 = V_275 -> V_40 ;
struct V_20 * V_277 ;
int V_14 ;
V_277 = F_22 ( V_276 -> V_22 , V_276 -> V_22 , V_59 ) ;
if ( V_277 == NULL )
return - V_53 ;
V_14 = F_24 ( & V_277 -> V_61 , & V_276 -> V_61 , V_59 ) ;
if ( V_14 != 0 )
return V_14 ;
V_14 = F_27 ( & V_277 -> V_62 , & V_276 -> V_62 ,
V_59 ) ;
if ( V_14 != 0 )
return V_14 ;
V_274 -> V_40 = V_277 ;
return 0 ;
}
static void F_122 ( struct V_39 * V_274 , const struct V_39 * V_275 )
{
struct V_20 * V_276 = V_275 -> V_40 ;
struct V_20 * V_277 = V_274 -> V_40 ;
V_277 -> V_22 = V_276 -> V_22 ;
V_277 -> V_60 = V_276 -> V_22 ;
F_21 ( & V_277 -> V_63 ) ;
F_23 ( & V_277 -> V_61 ) ;
}
static int F_123 ( struct V_39 * V_274 , T_4 V_236 )
{
struct V_20 * V_277 = V_274 -> V_40 ;
struct V_11 * V_47 = F_124 ( V_236 ) ;
if ( V_47 == NULL )
return - V_139 ;
V_277 -> V_22 = V_47 ;
return 0 ;
}
static int F_125 ( struct V_39 * V_274 ,
struct V_27 * V_27 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
struct V_20 * V_21 = V_274 -> V_40 ;
V_21 -> V_60 = V_29 -> V_37 ;
V_21 -> V_22 = V_21 -> V_60 ;
return 0 ;
}
static int F_126 ( struct V_25 * V_122 , int V_278 ,
const char * V_279 )
{
struct V_81 V_82 ;
struct V_11 * V_47 = F_7 ( V_122 ) ;
int V_14 ;
F_33 ( & V_82 , V_279 , V_86 ) ;
F_34 ( & V_82 , V_122 ) ;
V_14 = F_67 ( V_47 , V_278 , & V_82 ) ;
V_14 = F_6 ( V_122 , V_278 , V_14 ) ;
return V_14 ;
}
static int F_127 ( struct V_25 * V_122 , T_5 V_280 )
{
return F_126 ( V_122 , V_5 , V_93 ) ;
}
static int F_128 ( struct V_25 * V_122 )
{
return F_126 ( V_122 , V_4 , V_93 ) ;
}
static int F_129 ( struct V_25 * V_122 )
{
return F_126 ( V_122 , V_4 , V_93 ) ;
}
static void F_130 ( struct V_25 * V_122 , T_4 * V_236 )
{
struct V_11 * V_47 = F_7 ( V_122 ) ;
* V_236 = V_47 -> V_237 ;
}
static int F_131 ( struct V_25 * V_122 , int V_281 )
{
return F_126 ( V_122 , V_5 , V_93 ) ;
}
static int F_132 ( struct V_25 * V_122 , int V_282 )
{
return F_126 ( V_122 , V_5 , V_93 ) ;
}
static int F_133 ( struct V_25 * V_122 )
{
return F_126 ( V_122 , V_4 , V_93 ) ;
}
static int F_134 ( struct V_25 * V_122 )
{
return F_126 ( V_122 , V_5 , V_93 ) ;
}
static int F_135 ( struct V_25 * V_122 )
{
return F_126 ( V_122 , V_4 , V_93 ) ;
}
static int F_136 ( struct V_25 * V_122 )
{
return F_126 ( V_122 , V_5 , V_93 ) ;
}
static int F_137 ( struct V_25 * V_122 , struct V_283 * V_284 ,
int V_285 , T_4 V_236 )
{
struct V_81 V_82 ;
struct V_11 * V_47 ;
struct V_11 * V_264 = F_7 ( V_122 ) ;
int V_14 ;
if ( ! V_285 )
return 0 ;
F_33 ( & V_82 , V_93 , V_86 ) ;
F_34 ( & V_82 , V_122 ) ;
if ( V_236 == 0 ) {
V_14 = F_67 ( V_264 , V_266 , & V_82 ) ;
V_14 = F_6 ( V_122 , V_266 , V_14 ) ;
return V_14 ;
}
V_47 = F_124 ( V_236 ) ;
V_14 = V_259 ( V_47 , V_264 , V_266 , & V_82 ) ;
V_14 = F_2 ( L_12 , V_47 , V_264 , V_266 , V_14 ) ;
return V_14 ;
}
static int F_138 ( struct V_25 * V_122 )
{
return 0 ;
}
static void F_139 ( struct V_25 * V_122 , struct V_27 * V_27 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
struct V_11 * V_47 = F_7 ( V_122 ) ;
V_29 -> V_37 = V_47 ;
}
static int F_140 ( struct V_226 * V_229 , int V_286 , T_1 V_287 )
{
struct V_11 * V_47 = F_45 () ;
struct V_223 * V_224 ;
V_224 = F_15 ( sizeof( struct V_223 ) , V_287 ) ;
if ( V_224 == NULL )
return - V_53 ;
V_224 -> V_232 = V_47 ;
V_224 -> V_234 = V_47 ;
V_224 -> V_288 = NULL ;
V_229 -> V_230 = V_224 ;
return 0 ;
}
static void F_141 ( struct V_226 * V_229 )
{
F_18 ( V_229 -> V_230 ) ;
}
static struct V_11 * F_142 ( struct V_289 * V_290 )
{
struct V_291 * V_292 ;
struct V_293 * V_294 = & V_290 -> V_295 ;
if ( V_294 -> V_296 == 0 )
return NULL ;
F_25 (snp, &smk_net4addr_list, list)
if ( V_292 -> V_297 . V_296 ==
( V_294 -> V_296 & V_292 -> V_298 . V_296 ) )
return V_292 -> V_74 ;
return NULL ;
}
static bool F_143 ( struct V_299 * V_290 )
{
T_6 * V_300 = ( T_6 * ) & V_290 -> V_301 ;
T_7 * V_302 = ( T_7 * ) & V_290 -> V_301 ;
if ( V_302 [ 0 ] == 0 && V_302 [ 1 ] == 0 && V_302 [ 2 ] == 0 && V_300 [ 6 ] == 0 &&
F_144 ( V_300 [ 7 ] ) == 1 )
return true ;
return false ;
}
static struct V_11 * F_145 ( struct V_299 * V_290 )
{
struct V_303 * V_292 ;
struct V_304 * V_305 = & V_290 -> V_301 ;
int V_3 ;
int V_306 = 0 ;
if ( F_143 ( V_290 ) )
return NULL ;
F_25 (snp, &smk_net6addr_list, list) {
for ( V_306 = 1 , V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
if ( V_292 -> V_74 == NULL )
continue;
if ( ( V_305 -> V_307 [ V_3 ] & V_292 -> V_298 . V_307 [ V_3 ] ) !=
V_292 -> V_297 . V_307 [ V_3 ] ) {
V_306 = 0 ;
break;
}
}
if ( V_306 )
return V_292 -> V_74 ;
}
return NULL ;
}
static int F_146 ( struct V_226 * V_229 , int V_308 )
{
struct V_11 * V_47 ;
struct V_223 * V_224 = V_229 -> V_230 ;
int V_14 = 0 ;
F_147 () ;
F_148 ( V_229 ) ;
if ( V_224 -> V_234 == V_309 ||
V_308 == V_310 )
F_149 ( V_229 ) ;
else {
V_47 = V_224 -> V_234 ;
V_14 = F_150 ( V_229 , V_229 -> V_311 , & V_47 -> V_312 ) ;
}
F_151 ( V_229 ) ;
F_152 () ;
return V_14 ;
}
static int F_153 ( struct V_226 * V_229 , struct V_289 * V_305 )
{
struct V_11 * V_47 ;
int V_14 ;
int V_313 ;
struct V_11 * V_314 ;
struct V_223 * V_224 = V_229 -> V_230 ;
struct V_81 V_82 ;
F_35 () ;
V_314 = F_142 ( V_305 ) ;
if ( V_314 != NULL ) {
#ifdef F_154
struct V_315 V_316 ;
F_155 ( & V_82 , V_93 , V_317 , & V_316 ) ;
V_82 . V_318 . V_319 . V_316 -> V_286 = V_305 -> V_320 ;
V_82 . V_318 . V_319 . V_316 -> V_321 = V_305 -> V_322 ;
V_82 . V_318 . V_319 . V_316 -> V_323 . V_324 = V_305 -> V_295 . V_296 ;
#endif
V_313 = V_310 ;
V_47 = V_224 -> V_234 ;
V_14 = V_259 ( V_47 , V_314 , V_5 , & V_82 ) ;
V_14 = F_2 ( L_13 , V_47 , V_314 , V_5 , V_14 ) ;
} else {
V_313 = V_325 ;
V_14 = 0 ;
}
F_40 () ;
if ( V_14 != 0 )
return V_14 ;
return F_146 ( V_229 , V_313 ) ;
}
static int F_156 ( struct V_11 * V_326 ,
struct V_11 * V_327 ,
struct V_299 * V_328 , int V_329 )
{
#ifdef F_154
struct V_315 V_316 ;
#endif
struct V_81 V_82 ;
int V_14 ;
#ifdef F_154
F_155 ( & V_82 , V_93 , V_317 , & V_316 ) ;
V_82 . V_318 . V_319 . V_316 -> V_286 = V_330 ;
V_82 . V_318 . V_319 . V_316 -> V_321 = F_144 ( V_328 -> V_331 ) ;
if ( V_329 == V_332 )
V_82 . V_318 . V_319 . V_316 -> V_333 . V_334 = V_328 -> V_301 ;
else
V_82 . V_318 . V_319 . V_316 -> V_333 . V_324 = V_328 -> V_301 ;
#endif
V_14 = V_259 ( V_326 , V_327 , V_5 , & V_82 ) ;
V_14 = F_2 ( L_14 , V_326 , V_327 , V_5 , V_14 ) ;
return V_14 ;
}
static void F_157 ( struct V_225 * V_226 , struct V_335 * V_328 )
{
struct V_226 * V_229 = V_226 -> V_229 ;
struct V_299 * V_336 ;
struct V_223 * V_224 = V_226 -> V_229 -> V_230 ;
struct V_337 * V_338 ;
unsigned short V_339 = 0 ;
if ( V_328 == NULL ) {
F_28 (spp, &smk_ipv6_port_list, list) {
if ( V_229 != V_338 -> V_340 )
continue;
V_338 -> V_232 = V_224 -> V_232 ;
V_338 -> V_234 = V_224 -> V_234 ;
return;
}
return;
}
V_336 = (struct V_299 * ) V_328 ;
V_339 = F_144 ( V_336 -> V_331 ) ;
if ( V_339 == 0 )
return;
F_28 (spp, &smk_ipv6_port_list, list) {
if ( V_338 -> V_341 != V_339 )
continue;
V_338 -> V_341 = V_339 ;
V_338 -> V_340 = V_229 ;
V_338 -> V_232 = V_224 -> V_232 ;
V_338 -> V_234 = V_224 -> V_234 ;
return;
}
V_338 = F_15 ( sizeof( * V_338 ) , V_52 ) ;
if ( V_338 == NULL )
return;
V_338 -> V_341 = V_339 ;
V_338 -> V_340 = V_229 ;
V_338 -> V_232 = V_224 -> V_232 ;
V_338 -> V_234 = V_224 -> V_234 ;
F_30 ( & V_338 -> V_70 , & V_342 ) ;
return;
}
static int F_158 ( struct V_226 * V_229 , struct V_299 * V_328 ,
int V_329 )
{
struct V_337 * V_338 ;
struct V_223 * V_224 = V_229 -> V_230 ;
struct V_11 * V_47 = NULL ;
unsigned short V_339 ;
struct V_11 * V_327 ;
if ( V_329 == V_332 ) {
V_47 = F_145 ( V_328 ) ;
V_327 = V_224 -> V_232 ;
} else {
V_47 = V_224 -> V_234 ;
V_327 = F_145 ( V_328 ) ;
}
if ( V_47 != NULL && V_327 != NULL )
return F_156 ( V_47 , V_327 , V_328 , V_329 ) ;
if ( V_47 == NULL )
V_47 = V_309 ;
if ( V_327 == NULL )
V_327 = V_309 ;
if ( ! F_143 ( V_328 ) )
return F_156 ( V_47 , V_327 , V_328 , V_329 ) ;
if ( V_329 == V_332 )
return 0 ;
V_339 = F_144 ( V_328 -> V_331 ) ;
F_28 (spp, &smk_ipv6_port_list, list) {
if ( V_338 -> V_341 != V_339 )
continue;
V_327 = V_338 -> V_232 ;
if ( V_329 == V_343 )
V_224 -> V_288 = V_338 -> V_234 ;
break;
}
return F_156 ( V_47 , V_327 , V_328 , V_329 ) ;
}
static int F_159 ( struct V_27 * V_27 , const char * V_42 ,
const void * V_185 , T_3 V_206 , int V_167 )
{
struct V_11 * V_47 ;
struct V_28 * V_344 = V_27 -> V_30 ;
struct V_223 * V_224 ;
struct V_225 * V_226 ;
int V_14 = 0 ;
if ( V_185 == NULL || V_206 > V_51 || V_206 == 0 )
return - V_139 ;
V_47 = F_17 ( V_185 , V_206 ) ;
if ( F_60 ( V_47 ) )
return F_61 ( V_47 ) ;
if ( strcmp ( V_42 , V_190 ) == 0 ) {
V_344 -> V_37 = V_47 ;
V_344 -> V_31 |= V_345 ;
return 0 ;
}
if ( V_27 -> V_33 -> V_161 != V_228 )
return - V_50 ;
V_226 = F_97 ( V_27 ) ;
if ( V_226 == NULL || V_226 -> V_229 == NULL )
return - V_50 ;
V_224 = V_226 -> V_229 -> V_230 ;
if ( strcmp ( V_42 , V_231 ) == 0 )
V_224 -> V_232 = V_47 ;
else if ( strcmp ( V_42 , V_233 ) == 0 ) {
V_224 -> V_234 = V_47 ;
if ( V_226 -> V_229 -> V_311 == V_346 ) {
V_14 = F_146 ( V_226 -> V_229 , V_325 ) ;
if ( V_14 != 0 )
F_160 ( V_347
L_15 ,
V_93 , - V_14 ) ;
}
} else
return - V_50 ;
#ifdef F_161
if ( V_226 -> V_229 -> V_311 == V_330 )
F_157 ( V_226 , NULL ) ;
#endif
return 0 ;
}
static int F_162 ( struct V_225 * V_226 , int V_286 ,
int type , int V_348 , int V_349 )
{
struct V_223 * V_224 ;
if ( V_226 -> V_229 == NULL )
return 0 ;
if ( F_112 ( V_23 -> V_167 & V_350 ) ) {
V_224 = V_226 -> V_229 -> V_230 ;
V_224 -> V_232 = & V_219 ;
V_224 -> V_234 = & V_219 ;
}
if ( V_286 != V_346 )
return 0 ;
return F_146 ( V_226 -> V_229 , V_325 ) ;
}
static int F_163 ( struct V_225 * V_226 , struct V_335 * V_328 ,
int V_351 )
{
if ( V_226 -> V_229 != NULL && V_226 -> V_229 -> V_311 == V_330 )
F_157 ( V_226 , V_328 ) ;
return 0 ;
}
static int F_164 ( struct V_225 * V_226 , struct V_335 * V_305 ,
int V_351 )
{
int V_14 = 0 ;
#if F_165 ( V_352 )
struct V_299 * V_290 = (struct V_299 * ) V_305 ;
#endif
#ifdef F_166
struct V_11 * V_353 ;
struct V_223 * V_224 = V_226 -> V_229 -> V_230 ;
#endif
if ( V_226 -> V_229 == NULL )
return 0 ;
switch ( V_226 -> V_229 -> V_311 ) {
case V_346 :
if ( V_351 < sizeof( struct V_289 ) )
return - V_139 ;
V_14 = F_153 ( V_226 -> V_229 , (struct V_289 * ) V_305 ) ;
break;
case V_330 :
if ( V_351 < sizeof( struct V_299 ) )
return - V_139 ;
#ifdef F_166
V_353 = F_145 ( V_290 ) ;
if ( V_353 != NULL )
V_14 = F_156 ( V_224 -> V_234 , V_353 , V_290 ,
V_343 ) ;
#endif
#ifdef F_161
V_14 = F_158 ( V_226 -> V_229 , V_290 , V_343 ) ;
#endif
break;
}
return V_14 ;
}
static int F_167 ( int V_167 )
{
int V_189 = 0 ;
if ( V_167 & V_354 )
V_189 |= V_4 ;
if ( V_167 & V_355 )
V_189 |= V_5 ;
if ( V_167 & V_356 )
V_189 |= V_6 ;
return V_189 ;
}
static int F_168 ( struct V_357 * V_358 )
{
struct V_11 * V_47 = F_45 () ;
V_358 -> V_40 = V_47 ;
return 0 ;
}
static void F_169 ( struct V_357 * V_358 )
{
V_358 -> V_40 = NULL ;
}
static struct V_11 * F_170 ( struct V_359 * V_360 )
{
return (struct V_11 * ) V_360 -> V_361 . V_40 ;
}
static int F_171 ( struct V_359 * V_360 )
{
struct V_362 * V_29 = & V_360 -> V_361 ;
struct V_11 * V_47 = F_45 () ;
V_29 -> V_40 = V_47 ;
return 0 ;
}
static void F_172 ( struct V_359 * V_360 )
{
struct V_362 * V_29 = & V_360 -> V_361 ;
V_29 -> V_40 = NULL ;
}
static int F_173 ( struct V_359 * V_360 , int V_278 )
{
struct V_11 * V_224 = F_170 ( V_360 ) ;
struct V_81 V_82 ;
int V_14 ;
#ifdef F_154
F_33 ( & V_82 , V_93 , V_363 ) ;
V_82 . V_318 . V_319 . V_364 = V_360 -> V_361 . V_365 ;
#endif
V_14 = F_67 ( V_224 , V_278 , & V_82 ) ;
V_14 = F_4 ( L_16 , V_224 , V_278 , V_14 ) ;
return V_14 ;
}
static int F_174 ( struct V_359 * V_360 , int V_366 )
{
int V_189 ;
V_189 = F_167 ( V_366 ) ;
return F_173 ( V_360 , V_189 ) ;
}
static int F_175 ( struct V_359 * V_360 , int V_239 )
{
int V_189 ;
switch ( V_239 ) {
case V_367 :
case V_368 :
V_189 = V_4 ;
break;
case V_369 :
case V_370 :
case V_371 :
case V_372 :
V_189 = V_76 ;
break;
case V_373 :
case V_374 :
return 0 ;
default:
return - V_139 ;
}
return F_173 ( V_360 , V_189 ) ;
}
static int F_176 ( struct V_359 * V_360 , char T_8 * V_375 ,
int V_366 )
{
int V_189 ;
V_189 = F_167 ( V_366 ) ;
return F_173 ( V_360 , V_189 ) ;
}
static struct V_11 * F_177 ( struct V_376 * V_377 )
{
return (struct V_11 * ) V_377 -> V_378 . V_40 ;
}
static int F_178 ( struct V_376 * V_377 )
{
struct V_362 * V_29 = & V_377 -> V_378 ;
struct V_11 * V_47 = F_45 () ;
V_29 -> V_40 = V_47 ;
return 0 ;
}
static void F_179 ( struct V_376 * V_377 )
{
struct V_362 * V_29 = & V_377 -> V_378 ;
V_29 -> V_40 = NULL ;
}
static int F_180 ( struct V_376 * V_377 , int V_278 )
{
struct V_11 * V_224 = F_177 ( V_377 ) ;
struct V_81 V_82 ;
int V_14 ;
#ifdef F_154
F_33 ( & V_82 , V_93 , V_363 ) ;
V_82 . V_318 . V_319 . V_364 = V_377 -> V_378 . V_365 ;
#endif
V_14 = F_67 ( V_224 , V_278 , & V_82 ) ;
V_14 = F_4 ( L_17 , V_224 , V_278 , V_14 ) ;
return V_14 ;
}
static int F_181 ( struct V_376 * V_377 , int V_379 )
{
int V_189 ;
V_189 = F_167 ( V_379 ) ;
return F_180 ( V_377 , V_189 ) ;
}
static int F_182 ( struct V_376 * V_377 , int V_239 )
{
int V_189 ;
switch ( V_239 ) {
case V_380 :
case V_381 :
case V_382 :
case V_383 :
case V_384 :
case V_367 :
case V_385 :
V_189 = V_4 ;
break;
case V_386 :
case V_387 :
case V_372 :
case V_369 :
V_189 = V_76 ;
break;
case V_373 :
case V_388 :
return 0 ;
default:
return - V_139 ;
}
return F_180 ( V_377 , V_189 ) ;
}
static int F_183 ( struct V_376 * V_377 , struct V_389 * V_390 ,
unsigned V_391 , int V_392 )
{
return F_180 ( V_377 , V_76 ) ;
}
static int F_184 ( struct V_393 * V_394 )
{
struct V_362 * V_395 = & V_394 -> V_396 ;
struct V_11 * V_47 = F_45 () ;
V_395 -> V_40 = V_47 ;
return 0 ;
}
static void F_185 ( struct V_393 * V_394 )
{
struct V_362 * V_395 = & V_394 -> V_396 ;
V_395 -> V_40 = NULL ;
}
static struct V_11 * F_186 ( struct V_393 * V_394 )
{
return (struct V_11 * ) V_394 -> V_396 . V_40 ;
}
static int F_187 ( struct V_393 * V_394 , int V_278 )
{
struct V_11 * V_397 = F_186 ( V_394 ) ;
struct V_81 V_82 ;
int V_14 ;
#ifdef F_154
F_33 ( & V_82 , V_93 , V_363 ) ;
V_82 . V_318 . V_319 . V_364 = V_394 -> V_396 . V_365 ;
#endif
V_14 = F_67 ( V_397 , V_278 , & V_82 ) ;
V_14 = F_4 ( L_18 , V_397 , V_278 , V_14 ) ;
return V_14 ;
}
static int F_188 ( struct V_393 * V_394 , int V_398 )
{
int V_189 ;
V_189 = F_167 ( V_398 ) ;
return F_187 ( V_394 , V_189 ) ;
}
static int F_189 ( struct V_393 * V_394 , int V_239 )
{
int V_189 ;
switch ( V_239 ) {
case V_367 :
case V_399 :
V_189 = V_4 ;
break;
case V_369 :
case V_372 :
V_189 = V_76 ;
break;
case V_373 :
case V_400 :
return 0 ;
default:
return - V_139 ;
}
return F_187 ( V_394 , V_189 ) ;
}
static int F_190 ( struct V_393 * V_394 , struct V_357 * V_358 ,
int V_398 )
{
int V_189 ;
V_189 = F_167 ( V_398 ) ;
return F_187 ( V_394 , V_189 ) ;
}
static int F_191 ( struct V_393 * V_394 , struct V_357 * V_358 ,
struct V_25 * V_401 , long type , int V_1 )
{
return F_187 ( V_394 , V_76 ) ;
}
static int F_192 ( struct V_362 * V_402 , short V_403 )
{
struct V_11 * V_404 = V_402 -> V_40 ;
int V_189 = F_167 ( V_403 ) ;
struct V_81 V_82 ;
int V_14 ;
#ifdef F_154
F_33 ( & V_82 , V_93 , V_363 ) ;
V_82 . V_318 . V_319 . V_364 = V_402 -> V_365 ;
#endif
V_14 = F_67 ( V_404 , V_189 , & V_82 ) ;
V_14 = F_4 ( L_19 , V_404 , V_189 , V_14 ) ;
return V_14 ;
}
static void F_193 ( struct V_362 * V_402 , T_4 * V_236 )
{
struct V_11 * V_404 = V_402 -> V_40 ;
* V_236 = V_404 -> V_237 ;
}
static void F_194 ( struct V_44 * V_405 , struct V_27 * V_27 )
{
struct V_98 * V_170 ;
struct V_100 * V_101 ;
struct V_28 * V_29 ;
struct V_11 * V_47 ;
struct V_11 * V_406 = F_45 () ;
struct V_11 * V_407 ;
char V_408 [ V_216 ] ;
int V_409 = 0 ;
int V_14 ;
struct V_44 * V_45 ;
if ( V_27 == NULL )
return;
V_29 = V_27 -> V_30 ;
F_195 ( & V_29 -> V_56 ) ;
if ( V_29 -> V_31 & V_345 )
goto V_410;
V_170 = V_27 -> V_33 ;
V_101 = V_170 -> V_108 ;
V_407 = V_101 -> V_104 ;
if ( V_405 -> V_411 == V_405 ) {
switch ( V_170 -> V_161 ) {
case V_412 :
V_101 -> V_102 = & V_218 ;
V_101 -> V_104 = & V_218 ;
V_29 -> V_37 = V_101 -> V_102 ;
break;
case V_163 :
V_29 -> V_37 = F_45 () ;
break;
case V_413 :
V_29 -> V_37 = F_45 () ;
break;
default:
V_29 -> V_37 = V_101 -> V_102 ;
break;
}
V_29 -> V_31 |= V_345 ;
goto V_410;
}
switch ( V_170 -> V_161 ) {
case V_414 :
case V_413 :
case V_228 :
case V_412 :
V_407 = & V_218 ;
break;
case V_415 :
V_407 = V_406 ;
break;
case V_416 :
break;
case V_163 :
V_407 = & V_218 ;
default:
if ( F_114 ( V_27 -> V_267 ) ) {
V_407 = & V_218 ;
break;
}
if ( ! ( V_27 -> V_48 & V_49 ) )
break;
V_45 = F_196 ( V_405 ) ;
V_47 = F_13 ( V_210 , V_27 , V_45 ) ;
if ( ! F_197 ( V_47 ) )
V_407 = V_47 ;
if ( F_198 ( V_27 -> V_267 ) ) {
if ( V_29 -> V_31 & V_191 ) {
V_29 -> V_31 &= ~ V_191 ;
V_14 = F_199 ( V_45 , V_27 ,
V_215 ,
V_217 , V_216 ,
0 ) ;
} else {
V_14 = F_16 ( V_45 , V_27 ,
V_215 , V_408 ,
V_216 ) ;
if ( V_14 >= 0 && strncmp ( V_408 , V_217 ,
V_216 ) != 0 )
V_14 = - V_139 ;
}
if ( V_14 >= 0 )
V_409 = V_166 ;
}
V_47 = F_13 ( V_213 , V_27 , V_45 ) ;
if ( F_60 ( V_47 ) || V_47 == & V_218 ||
V_47 == & V_219 )
V_47 = NULL ;
V_29 -> V_22 = V_47 ;
V_47 = F_13 ( V_214 , V_27 , V_45 ) ;
if ( F_60 ( V_47 ) || V_47 == & V_218 ||
V_47 == & V_219 )
V_47 = NULL ;
V_29 -> V_221 = V_47 ;
F_200 ( V_45 ) ;
break;
}
if ( V_407 == NULL )
V_29 -> V_37 = V_406 ;
else
V_29 -> V_37 = V_407 ;
V_29 -> V_31 |= ( V_345 | V_409 ) ;
V_410:
F_201 ( & V_29 -> V_56 ) ;
return;
}
static int F_202 ( struct V_25 * V_122 , char * V_42 , char * * V_185 )
{
struct V_11 * V_47 = F_7 ( V_122 ) ;
char * V_111 ;
int V_417 ;
if ( strcmp ( V_42 , L_20 ) != 0 )
return - V_139 ;
V_111 = F_79 ( V_47 -> V_19 , V_52 ) ;
if ( V_111 == NULL )
return - V_53 ;
V_417 = strlen ( V_111 ) ;
* V_185 = V_111 ;
return V_417 ;
}
static int F_203 ( struct V_25 * V_122 , char * V_42 ,
void * V_185 , T_3 V_206 )
{
struct V_20 * V_21 = F_5 () ;
struct V_39 * V_274 ;
struct V_11 * V_47 ;
struct V_71 * V_418 ;
int V_14 ;
if ( V_122 != V_23 )
return - V_158 ;
if ( ! F_46 ( V_157 ) && F_204 ( & V_21 -> V_62 ) )
return - V_158 ;
if ( V_185 == NULL || V_206 == 0 || V_206 >= V_51 )
return - V_139 ;
if ( strcmp ( V_42 , L_20 ) != 0 )
return - V_139 ;
V_47 = F_17 ( V_185 , V_206 ) ;
if ( F_60 ( V_47 ) )
return F_61 ( V_47 ) ;
if ( V_47 == & V_219 )
return - V_158 ;
if ( ! F_46 ( V_157 ) ) {
V_14 = - V_158 ;
F_28 (sklep, &tsp->smk_relabel, list)
if ( V_418 -> V_74 == V_47 ) {
V_14 = 0 ;
break;
}
if ( V_14 )
return V_14 ;
}
V_274 = F_205 () ;
if ( V_274 == NULL )
return - V_53 ;
V_21 = V_274 -> V_40 ;
V_21 -> V_22 = V_47 ;
F_29 ( & V_21 -> V_62 ) ;
F_206 ( V_274 ) ;
return V_206 ;
}
static int F_207 ( struct V_226 * V_226 ,
struct V_226 * V_419 , struct V_226 * V_420 )
{
struct V_11 * V_47 ;
struct V_11 * V_253 ;
struct V_223 * V_224 = V_226 -> V_230 ;
struct V_223 * V_421 = V_419 -> V_230 ;
struct V_223 * V_344 = V_420 -> V_230 ;
struct V_81 V_82 ;
int V_14 = 0 ;
#ifdef F_154
struct V_315 V_316 ;
#endif
if ( ! F_46 ( V_96 ) ) {
V_47 = V_224 -> V_234 ;
V_253 = V_421 -> V_232 ;
#ifdef F_154
F_155 ( & V_82 , V_93 , V_317 , & V_316 ) ;
F_208 ( & V_82 , V_419 ) ;
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
V_344 -> V_288 = V_224 -> V_234 ;
V_224 -> V_288 = V_421 -> V_234 ;
}
return V_14 ;
}
static int F_209 ( struct V_225 * V_226 , struct V_225 * V_419 )
{
struct V_223 * V_224 = V_226 -> V_229 -> V_230 ;
struct V_223 * V_421 = V_419 -> V_229 -> V_230 ;
struct V_81 V_82 ;
int V_14 ;
#ifdef F_154
struct V_315 V_316 ;
F_155 ( & V_82 , V_93 , V_317 , & V_316 ) ;
F_208 ( & V_82 , V_419 -> V_229 ) ;
#endif
if ( F_46 ( V_96 ) )
return 0 ;
V_14 = V_259 ( V_224 -> V_234 , V_421 -> V_232 , V_5 , & V_82 ) ;
V_14 = F_2 ( L_22 , V_224 -> V_234 , V_421 -> V_232 , V_5 , V_14 ) ;
return V_14 ;
}
static int F_210 ( struct V_225 * V_226 , struct V_422 * V_358 ,
int V_206 )
{
struct V_289 * V_290 = (struct V_289 * ) V_358 -> V_423 ;
#if F_165 ( V_352 )
struct V_299 * V_305 = (struct V_299 * ) V_358 -> V_423 ;
#endif
#ifdef F_166
struct V_223 * V_224 = V_226 -> V_229 -> V_230 ;
struct V_11 * V_353 ;
#endif
int V_14 = 0 ;
if ( V_290 == NULL )
return 0 ;
switch ( V_226 -> V_229 -> V_311 ) {
case V_424 :
V_14 = F_153 ( V_226 -> V_229 , V_290 ) ;
break;
case V_425 :
#ifdef F_166
V_353 = F_145 ( V_305 ) ;
if ( V_353 != NULL )
V_14 = F_156 ( V_224 -> V_234 , V_353 , V_305 ,
V_343 ) ;
#endif
#ifdef F_161
V_14 = F_158 ( V_226 -> V_229 , V_305 , V_426 ) ;
#endif
break;
}
return V_14 ;
}
static struct V_11 * F_211 ( struct V_427 * V_305 ,
struct V_223 * V_224 )
{
struct V_11 * V_47 ;
int V_306 = 0 ;
int V_428 ;
int V_429 ;
if ( ( V_305 -> V_167 & V_430 ) != 0 ) {
F_35 () ;
F_28 (skp, &smack_known_list, list) {
if ( V_305 -> V_431 . V_432 . V_433 != V_47 -> V_312 . V_431 . V_432 . V_433 )
continue;
if ( ( V_305 -> V_167 & V_434 ) == 0 ) {
if ( ( V_47 -> V_312 . V_167 &
V_434 ) == 0 )
V_306 = 1 ;
break;
}
for ( V_428 = - 1 , V_429 = - 1 ; V_428 == V_429 ; ) {
V_428 = F_212 ( V_305 -> V_431 . V_432 . V_435 ,
V_428 + 1 ) ;
V_429 = F_212 (
V_47 -> V_312 . V_431 . V_432 . V_435 ,
V_429 + 1 ) ;
if ( V_428 < 0 || V_429 < 0 )
break;
}
if ( V_428 == V_429 ) {
V_306 = 1 ;
break;
}
}
F_40 () ;
if ( V_306 )
return V_47 ;
if ( V_224 != NULL && V_224 -> V_232 == & V_218 )
return & V_219 ;
return & V_218 ;
}
if ( ( V_305 -> V_167 & V_436 ) != 0 ) {
V_47 = F_124 ( V_305 -> V_431 . V_236 ) ;
F_213 ( V_47 == NULL ) ;
return V_47 ;
}
return V_309 ;
}
static int F_214 ( struct V_437 * V_438 , struct V_299 * V_290 )
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
V_290 -> V_331 = 0 ;
V_440 = F_215 ( V_438 ) ;
V_444 = F_216 ( V_438 , V_440 , sizeof( V_443 ) , & V_443 ) ;
if ( V_444 == NULL )
return - V_139 ;
V_290 -> V_301 = V_444 -> V_334 ;
V_439 = V_444 -> V_439 ;
V_440 += sizeof( V_443 ) ;
V_440 = F_217 ( V_438 , V_440 , & V_439 , & V_445 ) ;
if ( V_440 < 0 )
return - V_139 ;
V_441 = V_439 ;
switch ( V_441 ) {
case V_455 :
V_448 = F_216 ( V_438 , V_440 , sizeof( V_447 ) , & V_447 ) ;
if ( V_448 != NULL )
V_290 -> V_331 = V_448 -> V_456 ;
break;
case V_457 :
V_451 = F_216 ( V_438 , V_440 , sizeof( V_450 ) , & V_450 ) ;
if ( V_451 != NULL )
V_290 -> V_331 = V_451 -> V_456 ;
break;
case V_458 :
V_454 = F_216 ( V_438 , V_440 , sizeof( V_453 ) , & V_453 ) ;
if ( V_454 != NULL )
V_290 -> V_331 = V_454 -> V_459 ;
break;
}
return V_441 ;
}
static int F_218 ( struct V_226 * V_229 , struct V_437 * V_438 )
{
struct V_427 V_460 ;
struct V_223 * V_224 = V_229 -> V_230 ;
struct V_11 * V_47 = NULL ;
int V_14 = 0 ;
struct V_81 V_82 ;
#ifdef F_154
struct V_315 V_316 ;
#endif
#if F_165 ( V_352 )
struct V_299 V_461 ;
int V_441 ;
#endif
switch ( V_229 -> V_311 ) {
case V_346 :
#ifdef F_219
if ( V_438 && V_438 -> V_462 != 0 ) {
V_47 = F_124 ( V_438 -> V_462 ) ;
goto V_463;
}
#endif
F_220 ( & V_460 ) ;
V_14 = F_221 ( V_438 , V_229 -> V_311 , & V_460 ) ;
if ( V_14 == 0 )
V_47 = F_211 ( & V_460 , V_224 ) ;
else
V_47 = V_309 ;
F_222 ( & V_460 ) ;
#ifdef F_219
V_463:
#endif
#ifdef F_154
F_155 ( & V_82 , V_93 , V_317 , & V_316 ) ;
V_82 . V_318 . V_319 . V_316 -> V_286 = V_229 -> V_311 ;
V_82 . V_318 . V_319 . V_316 -> V_464 = V_438 -> V_465 ;
F_223 ( V_438 , & V_82 . V_318 , NULL ) ;
#endif
V_14 = V_259 ( V_47 , V_224 -> V_232 , V_5 , & V_82 ) ;
V_14 = F_2 ( L_23 , V_47 , V_224 -> V_232 ,
V_5 , V_14 ) ;
if ( V_14 != 0 )
F_224 ( V_438 , V_229 -> V_311 , V_14 , 0 ) ;
break;
#if F_165 ( V_352 )
case V_330 :
V_441 = F_214 ( V_438 , & V_461 ) ;
if ( V_441 != V_457 && V_441 != V_455 )
break;
#ifdef F_166
if ( V_438 && V_438 -> V_462 != 0 )
V_47 = F_124 ( V_438 -> V_462 ) ;
else
V_47 = F_145 ( & V_461 ) ;
if ( V_47 == NULL )
V_47 = V_309 ;
#ifdef F_154
F_155 ( & V_82 , V_93 , V_317 , & V_316 ) ;
V_82 . V_318 . V_319 . V_316 -> V_286 = V_229 -> V_311 ;
V_82 . V_318 . V_319 . V_316 -> V_464 = V_438 -> V_465 ;
F_225 ( V_438 , & V_82 . V_318 , NULL ) ;
#endif
V_14 = V_259 ( V_47 , V_224 -> V_232 , V_5 , & V_82 ) ;
V_14 = F_2 ( L_24 , V_47 , V_224 -> V_232 ,
V_5 , V_14 ) ;
#endif
#ifdef F_161
V_14 = F_158 ( V_229 , & V_461 , V_332 ) ;
#endif
break;
#endif
}
return V_14 ;
}
static int F_226 ( struct V_225 * V_226 ,
char T_8 * V_466 ,
int T_8 * V_467 , unsigned V_186 )
{
struct V_223 * V_224 ;
char * V_468 = L_25 ;
int V_417 = 1 ;
int V_14 = 0 ;
V_224 = V_226 -> V_229 -> V_230 ;
if ( V_224 -> V_288 != NULL ) {
V_468 = V_224 -> V_288 -> V_19 ;
V_417 = strlen ( V_468 ) + 1 ;
}
if ( V_417 > V_186 )
V_14 = - V_469 ;
else if ( F_227 ( V_466 , V_468 , V_417 ) != 0 )
V_14 = - V_470 ;
if ( F_228 ( V_417 , V_467 ) != 0 )
V_14 = - V_470 ;
return V_14 ;
}
static int F_229 ( struct V_225 * V_226 ,
struct V_437 * V_438 , T_4 * V_236 )
{
struct V_427 V_460 ;
struct V_223 * V_224 = NULL ;
struct V_11 * V_47 ;
int V_286 = V_471 ;
T_4 V_2 = 0 ;
int V_14 ;
if ( V_438 != NULL ) {
if ( V_438 -> V_348 == F_230 ( V_472 ) )
V_286 = V_346 ;
#if F_165 ( V_352 )
else if ( V_438 -> V_348 == F_230 ( V_473 ) )
V_286 = V_330 ;
#endif
}
if ( V_286 == V_471 && V_226 != NULL )
V_286 = V_226 -> V_229 -> V_311 ;
switch ( V_286 ) {
case V_474 :
V_224 = V_226 -> V_229 -> V_230 ;
V_2 = V_224 -> V_234 -> V_237 ;
break;
case V_346 :
#ifdef F_219
V_2 = V_438 -> V_462 ;
if ( V_2 != 0 )
break;
#endif
if ( V_226 != NULL && V_226 -> V_229 != NULL )
V_224 = V_226 -> V_229 -> V_230 ;
F_220 ( & V_460 ) ;
V_14 = F_221 ( V_438 , V_286 , & V_460 ) ;
if ( V_14 == 0 ) {
V_47 = F_211 ( & V_460 , V_224 ) ;
V_2 = V_47 -> V_237 ;
}
F_222 ( & V_460 ) ;
break;
case V_330 :
#ifdef F_166
V_2 = V_438 -> V_462 ;
#endif
break;
}
* V_236 = V_2 ;
if ( V_2 == 0 )
return - V_139 ;
return 0 ;
}
static void F_231 ( struct V_226 * V_229 , struct V_225 * V_475 )
{
struct V_223 * V_224 ;
struct V_11 * V_47 = F_45 () ;
if ( V_229 == NULL ||
( V_229 -> V_311 != V_346 && V_229 -> V_311 != V_330 ) )
return;
V_224 = V_229 -> V_230 ;
V_224 -> V_232 = V_47 ;
V_224 -> V_234 = V_47 ;
}
static int F_232 ( struct V_226 * V_229 , struct V_437 * V_438 ,
struct V_476 * V_477 )
{
T_10 V_286 = V_229 -> V_311 ;
struct V_11 * V_47 ;
struct V_223 * V_224 = V_229 -> V_230 ;
struct V_427 V_460 ;
struct V_289 V_478 ;
struct V_479 * V_480 ;
struct V_11 * V_481 ;
int V_14 ;
struct V_81 V_82 ;
#ifdef F_154
struct V_315 V_316 ;
#endif
#if F_165 ( V_352 )
if ( V_286 == V_330 ) {
if ( V_438 -> V_348 == F_230 ( V_472 ) )
V_286 = V_346 ;
else
return 0 ;
}
#endif
#ifdef F_219
if ( V_438 && V_438 -> V_462 != 0 ) {
V_47 = F_124 ( V_438 -> V_462 ) ;
goto V_463;
}
#endif
F_220 ( & V_460 ) ;
V_14 = F_221 ( V_438 , V_286 , & V_460 ) ;
if ( V_14 == 0 )
V_47 = F_211 ( & V_460 , V_224 ) ;
else
V_47 = & V_482 ;
F_222 ( & V_460 ) ;
#ifdef F_219
V_463:
#endif
#ifdef F_154
F_155 ( & V_82 , V_93 , V_317 , & V_316 ) ;
V_82 . V_318 . V_319 . V_316 -> V_286 = V_286 ;
V_82 . V_318 . V_319 . V_316 -> V_464 = V_438 -> V_465 ;
F_223 ( V_438 , & V_82 . V_318 , NULL ) ;
#endif
V_14 = V_259 ( V_47 , V_224 -> V_232 , V_5 , & V_82 ) ;
V_14 = F_2 ( L_26 , V_47 , V_224 -> V_232 , V_5 , V_14 ) ;
if ( V_14 != 0 )
return V_14 ;
V_477 -> V_483 = V_47 -> V_237 ;
V_480 = F_233 ( V_438 ) ;
V_478 . V_295 . V_296 = V_480 -> V_334 ;
F_35 () ;
V_481 = F_142 ( & V_478 ) ;
F_40 () ;
if ( V_481 == NULL )
V_14 = F_234 ( V_477 , & V_47 -> V_312 ) ;
else
F_235 ( V_477 ) ;
return V_14 ;
}
static void F_236 ( struct V_226 * V_229 ,
const struct V_476 * V_477 )
{
struct V_223 * V_224 = V_229 -> V_230 ;
struct V_11 * V_47 ;
if ( V_477 -> V_483 != 0 ) {
V_47 = F_124 ( V_477 -> V_483 ) ;
V_224 -> V_288 = V_47 ;
} else
V_224 -> V_288 = NULL ;
}
static int F_237 ( struct V_484 * V_484 , const struct V_39 * V_39 ,
unsigned long V_167 )
{
struct V_11 * V_47 = F_37 ( V_39 -> V_40 ) ;
V_484 -> V_40 = V_47 ;
return 0 ;
}
static void F_238 ( struct V_484 * V_484 )
{
V_484 -> V_40 = NULL ;
}
static int F_239 ( T_11 V_485 ,
const struct V_39 * V_39 , unsigned V_486 )
{
struct V_484 * V_487 ;
struct V_81 V_82 ;
struct V_11 * V_264 = F_37 ( V_39 -> V_40 ) ;
int V_488 = 0 ;
int V_14 ;
V_487 = F_240 ( V_485 ) ;
if ( V_487 == NULL )
return - V_139 ;
if ( V_487 -> V_40 == NULL )
return 0 ;
if ( V_264 == NULL )
return - V_90 ;
#ifdef F_154
F_33 ( & V_82 , V_93 , V_489 ) ;
V_82 . V_318 . V_319 . V_490 . V_484 = V_487 -> V_491 ;
V_82 . V_318 . V_319 . V_490 . V_492 = V_487 -> V_493 ;
#endif
if ( V_486 & V_494 )
V_488 = V_4 ;
if ( V_486 & ( V_495 | V_496 | V_497 ) )
V_488 = V_5 ;
V_14 = V_259 ( V_264 , V_487 -> V_40 , V_488 , & V_82 ) ;
V_14 = F_2 ( L_27 , V_264 , V_487 -> V_40 , V_488 , V_14 ) ;
return V_14 ;
}
static int F_241 ( struct V_484 * V_484 , char * * V_498 )
{
struct V_11 * V_47 = V_484 -> V_40 ;
T_3 V_499 ;
char * V_500 ;
if ( V_484 -> V_40 == NULL ) {
* V_498 = NULL ;
return 0 ;
}
V_500 = F_79 ( V_47 -> V_19 , V_52 ) ;
if ( V_500 == NULL )
return - V_53 ;
V_499 = strlen ( V_500 ) + 1 ;
* V_498 = V_500 ;
return V_499 ;
}
static int F_242 ( T_4 V_501 , T_4 V_502 , char * V_503 , void * * V_504 )
{
struct V_11 * V_47 ;
char * * V_505 = ( char * * ) V_504 ;
* V_505 = NULL ;
if ( V_501 != V_506 && V_501 != V_507 )
return - V_139 ;
if ( V_502 != V_508 && V_502 != V_509 )
return - V_139 ;
V_47 = F_17 ( V_503 , 0 ) ;
if ( F_60 ( V_47 ) )
return F_61 ( V_47 ) ;
* V_505 = V_47 -> V_19 ;
return 0 ;
}
static int F_243 ( struct V_510 * V_511 )
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
static int F_244 ( T_4 V_236 , T_4 V_501 , T_4 V_502 , void * V_504 ,
struct V_516 * V_517 )
{
struct V_11 * V_47 ;
char * V_505 = V_504 ;
if ( F_112 ( ! V_505 ) ) {
F_245 ( 1 , L_28 ) ;
return - V_258 ;
}
if ( V_501 != V_506 && V_501 != V_507 )
return 0 ;
V_47 = F_124 ( V_236 ) ;
if ( V_502 == V_508 )
return ( V_505 == V_47 -> V_19 ) ;
if ( V_502 == V_509 )
return ( V_505 != V_47 -> V_19 ) ;
return 0 ;
}
static int F_246 ( const char * V_42 )
{
return ( strcmp ( V_42 , V_190 ) == 0 ) ;
}
static int F_247 ( T_4 V_236 , char * * V_518 , T_4 * V_519 )
{
struct V_11 * V_47 = F_124 ( V_236 ) ;
if ( V_518 )
* V_518 = V_47 -> V_19 ;
* V_519 = strlen ( V_47 -> V_19 ) ;
return 0 ;
}
static int F_248 ( const char * V_518 , T_4 V_519 , T_4 * V_236 )
{
struct V_11 * V_47 = F_249 ( V_518 ) ;
if ( V_47 )
* V_236 = V_47 -> V_237 ;
else
* V_236 = 0 ;
return 0 ;
}
static int F_250 ( struct V_27 * V_27 , void * V_520 , T_4 V_521 )
{
return F_159 ( V_27 , V_190 , V_520 , V_521 , 0 ) ;
}
static int F_251 ( struct V_44 * V_44 , void * V_520 , T_4 V_521 )
{
return F_252 ( V_44 , V_210 , V_520 , V_521 , 0 ) ;
}
static int F_253 ( struct V_27 * V_27 , void * * V_520 , T_4 * V_521 )
{
int V_186 = 0 ;
V_186 = F_96 ( V_27 , V_190 , V_520 , true ) ;
if ( V_186 < 0 )
return V_186 ;
* V_521 = V_186 ;
return 0 ;
}
static T_12 void F_254 ( void )
{
F_21 ( & V_482 . V_63 ) ;
F_21 ( & V_107 . V_63 ) ;
F_21 ( & V_103 . V_63 ) ;
F_21 ( & V_218 . V_63 ) ;
F_21 ( & V_220 . V_63 ) ;
F_21 ( & V_219 . V_63 ) ;
F_23 ( & V_482 . V_61 ) ;
F_23 ( & V_107 . V_61 ) ;
F_23 ( & V_218 . V_61 ) ;
F_23 ( & V_103 . V_61 ) ;
F_23 ( & V_220 . V_61 ) ;
F_23 ( & V_219 . V_61 ) ;
F_255 ( & V_482 ) ;
F_255 ( & V_107 ) ;
F_255 ( & V_218 ) ;
F_255 ( & V_103 ) ;
F_255 ( & V_220 ) ;
F_255 ( & V_219 ) ;
}
static T_12 int F_256 ( void )
{
struct V_39 * V_39 ;
struct V_20 * V_21 ;
if ( ! F_257 ( L_29 ) )
return 0 ;
V_54 = F_258 ( V_28 , 0 ) ;
if ( ! V_54 )
return - V_53 ;
V_21 = F_22 ( & V_103 , & V_103 ,
V_52 ) ;
if ( V_21 == NULL ) {
F_259 ( V_54 ) ;
return - V_53 ;
}
V_522 = 1 ;
F_3 ( L_30 ) ;
#ifdef F_219
F_3 ( L_31 ) ;
#endif
#ifdef F_161
F_3 ( L_32 ) ;
#endif
#ifdef F_166
F_3 ( L_33 ) ;
#endif
V_39 = (struct V_39 * ) V_23 -> V_39 ;
V_39 -> V_40 = V_21 ;
F_254 () ;
F_260 ( V_523 , F_261 ( V_523 ) ) ;
return 0 ;
}
